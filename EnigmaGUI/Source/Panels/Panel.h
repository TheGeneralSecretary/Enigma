#pragma once

namespace Enigma
{
	class Panel
	{
	public:
		virtual ~Panel() = default;
		virtual void OnImGuiRender() = 0;
	};
}
