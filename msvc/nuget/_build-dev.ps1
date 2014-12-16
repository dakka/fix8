. "$PSScriptRoot\scripts\replace-version.ps1"

# c++ packages
ReplaceVersion "fix8pro.dev.autopkg" "_1.autopkg"
ReplaceVersion "fix8pro.dev.tests.autopkg" "_2.autopkg"
ReplaceVersion "fix8pro.dev.stocklib.autopkg" "_3.autopkg"
Write-NuGetPackage "_1.autopkg"
Write-NuGetPackage "_2.autopkg"
Write-NuGetPackage "_3.autopkg"

# remove temporary files
rm _1.autopkg
rm _2.autopkg
rm _3.autopkg
