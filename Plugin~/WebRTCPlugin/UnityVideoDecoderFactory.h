#pragma once

#include <api/video_codecs/sdp_video_format.h>
#include <api/video_codecs/video_decoder_factory.h>

namespace unity
{
namespace webrtc
{
    using namespace ::webrtc;

    class IGraphicsDevice;
    class ProfilerMarkerFactory;
    class UnityVideoDecoderFactory : public VideoDecoderFactory
    {
    public:
        virtual std::vector<webrtc::SdpVideoFormat> GetSupportedFormats() const override;
        virtual std::unique_ptr<webrtc::VideoDecoder> CreateVideoDecoder(const webrtc::SdpVideoFormat& format) override;

        UnityVideoDecoderFactory(IGraphicsDevice* gfxDevice, ProfilerMarkerFactory* profiler);
        ~UnityVideoDecoderFactory() override;

    private:
        ProfilerMarkerFactory* profiler_;
        const std::unique_ptr<VideoDecoderFactory> internal_decoder_factory_;
        const std::unique_ptr<VideoDecoderFactory> native_decoder_factory_;
    };
}
}
