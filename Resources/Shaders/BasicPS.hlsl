#include "Basic.hlsli"

//0�ԃX���b�g�ɐݒ肳�ꂽ�e�N�X�`��
Texture2D<float4> tex : register(t0);

//0�ԃX���b�g�ɐݒ肳�ꂽ�T���v���[
SamplerState smp : register(s0);

float4 main(VSOutput input) :SV_TARGET
{
	// --- �g�U���ˌ�(diffuse) --- //
	//�E�����@�����̃��C�g
	//float3 light = normalize(float3(1, -1, 1));

	//�����ւ̃x�N�g���Ɩ@���x�N�g���̓���
	//float brightness = dot(-light, input.normal);

	//�P�x��RGB�ɑ�����ďo��
	//return float4(brightness,brightness,brightness,1);


	// --- ����(Ambient) --- //
	//�E�����@�����̃��C�g
	float3 light = normalize(float3(1,-1,1));

	//diffuse��[0,1]�͈̔͂�Clamp����
	float diffuse = saturate(dot(-light, input.normal));

	//�A���r�G���g����0.3�Ƃ��Čv�Z
	float brightness = diffuse + 0.3f;

	//�P�x��RGB�ɑ�����ďo��
	//return float4(brightness, brightness, brightness, 1);

	float4 texcolor = float4(tex.Sample(smp,input.uv));

	return float4(texcolor.rgb * brightness,texcolor.a) * color;

}
