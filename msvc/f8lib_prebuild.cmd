set Platform=%3
set Configuration=%2
set Cmd=%1
set OutDir=%4
if %Platform% EQU x64 (
    if %Configuration% EQU Debug (
        if %Cmd% EQU clean (
            echo "%OutDir%\getopt.dll"
            echo "%OutDir%\Poco*64d.dll"
            echo "%OutDir%\tbb*.dll"
        ) else (
            copy "%GetOpt%\bin\%Platform%\%Configuration% Dll\getopt.dll" "%OutDir%\getopt.dll"
            copy "%Poco%\bin64\Poco*64d.dll" "%OutDir%"
            copy "%TBB%\build\vs2013\intel64\Debug\tbb*.dll" "%OutDir%"
        )
    ) else (
        if %Cmd% EQU clean (
            del "%OutDir%\getopt.dll"
            del "%OutDir%\Poco*64.dll"
            del "%OutDir%\tbb*.dll"
        ) else (
            copy "%GetOpt%\bin\%Platform%\%Configuration% Dll\getopt.dll" "%OutDir%\getopt.dll"
            copy "%Poco%\bin64\Poco*64.dll" "%OutDir%"
            copy "%TBB%\build\vs2013\intel64\Release\tbb*.dll" "%OutDir%"
        )
    )
) else (
    if %Configuration% EQU Debug (
        if %Cmd% EQU clean (
            echo "%OutDir%\getopt.dll"
            echo "%OutDir%\Poco*d.dll"
            echo "%OutDir%\tbb*.dll"
        ) else (
            copy "%GetOpt%\bin\%Platform%\%Configuration% Dll\getopt.dll" "%OutDir%\getopt.dll"
            copy "%Poco%\bin\Poco*d.dll" "%OutDir%"
            copy "%TBB%\build\vs2013\ia32\Debug\tbb*.dll" "%OutDir%"
        )
    ) else (
        if %Cmd% EQU clean (
            del "%OutDir%\getopt.dll"
            del "%OutDir%\Poco*.dll"
            del "%OutDir%\tbb*.dll"
        ) else (
            copy "%GetOpt%\bin\%Platform%\%Configuration% Dll\getopt.dll" "%OutDir%\getopt.dll"
            copy "%Poco%\bin\Poco*.dll" "%OutDir%"
            copy "%TBB%\build\vs2013\ia32\Release\tbb*.dll" "%OutDir%"
        )
    )
)