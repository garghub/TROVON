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
T_1 *
F_3 ( void (* F_4)( T_1 * ) ,
void (* F_5)( T_1 * ) )
{
T_1 * V_1 ;
V_1 = F_6 ( L_2 ) ;
if ( sizeof( V_1 ) == 4 )
F_2 ( V_1 , L_3 ) ;
else
F_2 ( V_1 , L_4 ) ;
if ( F_4 ) {
(* F_4)( V_1 ) ;
F_2 ( V_1 , L_5 ) ;
}
F_2 ( V_1 , L_6 ) ;
F_7 ( V_1 ,
#ifdef F_8
L_7 , F_8 , V_6 ,
V_7 ) ;
#else
L_8 ) ;
void
F_9 ( T_1 * V_1 V_8 )
{
T_3 V_9 [ 4 ] ;
char V_10 [ 0x40 ] ;
unsigned V_11 ;
if ( ! F_10 ( V_9 , 0x80000000 ) )
return;
V_11 = V_9 [ 0 ] ;
if( V_11 < 0x80000005 )
return;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
F_10 ( V_9 , 0x80000002 ) ;
memcpy ( V_10 , V_9 , sizeof( V_9 ) ) ;
F_10 ( V_9 , 0x80000003 ) ;
memcpy ( V_10 + 16 , V_9 , sizeof( V_9 ) ) ;
F_10 ( V_9 , 0x80000004 ) ;
memcpy ( V_10 + 32 , V_9 , sizeof( V_9 ) ) ;
F_7 ( V_1 , L_9 , V_10 ) ;
if ( F_11 () )
F_2 ( V_1 , L_10 ) ;
}
static void
F_12 ( T_1 * V_1 V_8 )
{
#ifdef F_13
T_4 V_12 ;
V_12 . V_13 = sizeof ( V_12 ) ;
if ( F_14 ( & V_12 ) )
F_7 (str, L_11%L_12dL_13MB of physical memory.\nL_14\n\nBuilt using clang %s.\nL_15\n\nBuilt using llvm-gcc %s.\nL_16\n\nBuilt using gcc %s.\nL_17\n\nBuilt using HP aCC %d.\nL_18\n\nBuilt using IBM XL C %d.%d\nL_19 patch %dL_20\nL_21\n\nBuilt using Intel C %d.%dL_22 patch %dL_23 , compiler built %04d-%02d-%02d L_24\nL_25VisualL_26\n\nBuilt using Microsoft Visual C++ %d.%dL_27 build %dL_28\n\nBuilt using Microsoft Visual C++ %d.%dL_29 build %dL_30\nL_31\n\nBuilt using Microsoft Visual C++ %d.%d\nL_32\n\nBuilt using Sun C %d.%dL_33 patch %dL_34\nL_35additional_infoL_36Running on L_37 , with locale %sL_38 , with default localeL_39.L_40%s %s\nL_41\nL_41%sL_41\nL_41%sL_41\nL_41%sL_42 (L_43 from L_44)"
