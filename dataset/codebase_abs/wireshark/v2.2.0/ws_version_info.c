static void
F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
char * V_3 , * V_4 ;
V_2 = V_1 -> V_5 ;
if ( V_2 == 0 || V_1 -> V_1 [ V_2 - 1 ] != '\n' )
F_2 ( V_1 , L_1 ) ;
V_3 = V_1 -> V_1 ;
while ( * V_3 != '\0' ) {
V_4 = strchr ( V_3 , '\n' ) ;
if ( V_4 - V_3 > 80 ) {
V_4 = V_3 + 80 ;
while ( V_4 > V_3 && * V_4 != ' ' )
V_4 -- ;
if ( V_4 != V_3 )
* V_4 = '\n' ;
}
V_3 = V_4 + 1 ;
}
}
static const T_3 *
F_3 ( void )
{
#ifdef F_4
#ifdef F_5
return L_2 F_5 ;
#else
return L_3 ;
#endif
#else
return L_4 ;
#endif
}
T_1 *
F_6 ( void (* F_7)( T_1 * ) ,
void (* F_8)( T_1 * ) )
{
T_1 * V_1 ;
V_1 = F_9 ( L_5 ) ;
if ( sizeof( V_1 ) == 4 )
F_2 ( V_1 , L_6 ) ;
else
F_2 ( V_1 , L_7 ) ;
if ( F_7 ) {
(* F_7)( V_1 ) ;
F_2 ( V_1 , L_8 ) ;
}
F_2 ( V_1 , L_9 ) ;
F_10 ( V_1 ,
#ifdef F_11
L_10 , F_11 , V_6 ,
V_7 ) ;
#else
L_11 ) ;
void
F_12 ( T_1 * V_1 )
{
T_4 V_8 [ 4 ] ;
char V_9 [ 0x40 ] ;
unsigned V_10 ;
if ( ! F_13 ( V_8 , 0x80000000 ) )
return;
V_10 = V_8 [ 0 ] ;
if( V_10 < 0x80000005 )
return;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
F_13 ( V_8 , 0x80000002 ) ;
memcpy ( V_9 , V_8 , sizeof( V_8 ) ) ;
F_13 ( V_8 , 0x80000003 ) ;
memcpy ( V_9 + 16 , V_8 , sizeof( V_8 ) ) ;
F_13 ( V_8 , 0x80000004 ) ;
memcpy ( V_9 + 32 , V_8 , sizeof( V_8 ) ) ;
F_10 ( V_1 , L_12 , V_9 ) ;
if ( F_14 () )
F_2 ( V_1 , L_13 ) ;
}
static void
F_15 ( T_1 * V_1 V_11 )
{
#ifdef F_16
T_5 V_12 ;
V_12 . V_13 = sizeof ( V_12 ) ;
if ( F_17 ( & V_12 ) )
F_10 (str, L_14%L_15dL_16MB of physical memory.\nL_17\n\nBuilt using clang %s.\nL_18\n\nBuilt using llvm-gcc %s.\nL_19\n\nBuilt using gcc %s.\nL_20\n\nBuilt using HP aCC %d.\nL_21\n\nBuilt using IBM XL C %d.%d\nL_22 patch %dL_23\nL_24\n\nBuilt using Intel C %d.%dL_25 patch %dL_26 , compiler built %04d-%02d-%02d L_27\nL_28VisualL_29\n\nBuilt using Microsoft Visual C++ %d.%dL_30 build %dL_31\n\nBuilt using Microsoft Visual C++ %d.%dL_32 build %dL_33\nL_34\n\nBuilt using Microsoft Visual C++ %d.%d\nL_35\n\nBuilt using Sun C %d.%dL_36 patch %dL_37\nL_38;L_39 , L_40additional_infoL_41Running on L_42 , with locale %sL_43 , with default localeL_44 , with zlib %sL_45.L_46%s %s\nL_47\nL_47%sL_47\nL_47%sL_47\nL_47%sL_48 (L_49 from L_50)"
