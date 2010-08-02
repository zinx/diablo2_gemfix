.globl _GemFixSplitLines1_1_112a
_GemFixSplitLines1_1_112a:
	pushl %eax

	movl 0xF9E, %ecx
	call *(_D2Lang_10005_112a)

	movl %eax, %edx
	movl %edi, %ecx

	call *%esi /* Unicode::strcat(Unicode *,Unicode const *) */

	movl %eax, %ecx

	call @GemFixSplitLines1_112a@4

	popl %eax
	ret

.globl _GemFixSplitLines1_2_112a
_GemFixSplitLines1_2_112a:
	movl 0xC(%ebp), %ecx
	call @GemFixSplitLines1_112a@4
	movl $1, %ebx
	ret

.globl _GemFixSplitLines1_3_112a
_GemFixSplitLines1_3_112a:
	pushl %ecx
	movl %esi, %ecx
	call @GemFixSplitLines1_112a@4
	popl %ecx
	movl $1, %ebx
	call *(_D2Lang_10005_112a)
	ret

.globl _GemFixSplitLines2_1_112a
_GemFixSplitLines2_1_112a:
	pushl %ecx
	pushl %eax
	call _GemFixSplitLines2_112a
	popl %eax
	popl %ecx
	call *(_D2Lang_10005_112a)
	ret
