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
T_4 V_8 = 0 ;
#ifdef F_13
T_5 V_9 ;
V_9 . V_10 = sizeof ( V_9 ) ;
if ( F_14 ( & V_9 ) )
V_8 = V_9 . V_11 ;
#elif V_12
T_2 V_5 = sizeof( V_8 ) ;
F_15 ( L_12 , & V_8 , & V_5 , NULL , 0 ) ;
#elif V_13
struct V_14 V_15 ;
if ( V_14 ( & V_15 ) == 0 )
V_8 = V_15 . V_16 * V_15 . V_17 ;
#endif
if ( V_8 > 0 )
F_10 (str, L_13%L_14dL_15 MB of physical memoryL_16\n\nBuilt using clang %s.\nL_17\n\nBuilt using llvm-gcc %s.\nL_18\n\nBuilt using gcc %s.\nL_19\n\nBuilt using HP aCC %d.\nL_20\n\nBuilt using IBM XL C %d.%d\nL_21 patch %dL_22\nL_23\n\nBuilt using Intel C %d.%dL_24 patch %dL_25 , compiler built %04d-%02d-%02d L_26\nL_27VisualL_28\n\nBuilt using Microsoft Visual C++ %d.%dL_29 build %dL_30\n\nBuilt using Microsoft Visual C++ %d.%dL_31 build %dL_32\nL_33\n\nBuilt using Microsoft Visual C++ %d.%d\nL_34\n\nBuilt using Sun C %d.%dL_35 patch %dL_36\nL_37;L_38 , L_39additional_infoL_40Running on L_41English_United States.1252 L_42 , with locale %sL_43 , with default localeL_44 , with zlib %sL_45.L_46%s %s\nL_47\nL_47%sL_47\nL_47%sL_47\nL_47%sL_48 (L_49)"
