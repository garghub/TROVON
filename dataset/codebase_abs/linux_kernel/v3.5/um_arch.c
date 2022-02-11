static void T_1 F_1 ( char * V_1 )
{
if ( strlen ( V_2 ) + strlen ( V_1 ) + 1 > V_3 ) {
printf ( L_1 ) ;
exit ( 1 ) ;
}
if ( strlen ( V_2 ) > 0 )
strcat ( V_2 , L_2 ) ;
strcat ( V_2 , V_1 ) ;
}
unsigned long F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_6 [ 0 ] ) ;
}
static int F_4 ( struct V_7 * V_8 , void * V_9 )
{
int V_10 = 0 ;
#ifdef F_5
V_10 = (struct V_11 * ) V_9 - V_12 ;
if ( ! F_6 ( V_10 ) )
return 0 ;
#endif
F_7 ( V_8 , L_3 , V_10 ) ;
F_7 ( V_8 , L_4 ) ;
F_7 ( V_8 , L_5 ) ;
F_7 ( V_8 , L_6 ) ;
F_7 ( V_8 , L_7 , V_13 ) ;
F_7 ( V_8 , L_8 ,
V_14 / ( 500000 / V_15 ) ,
( V_14 / ( 5000 / V_15 ) ) % 100 ) ;
return 0 ;
}
static void * F_8 ( struct V_7 * V_8 , T_2 * V_16 )
{
return * V_16 < V_17 ? V_12 + * V_16 : NULL ;
}
static void * F_9 ( struct V_7 * V_8 , void * V_9 , T_2 * V_16 )
{
++ * V_16 ;
return F_8 ( V_8 , V_16 ) ;
}
static void F_10 ( struct V_7 * V_8 , void * V_9 )
{
}
static int T_1 F_11 ( char * line , int * V_18 )
{
printf ( L_9 , F_12 () -> V_19 ) ;
exit ( 0 ) ;
return 0 ;
}
static int T_1 F_13 ( char * line , int * V_18 )
{
V_20 = 1 ;
return 0 ;
}
static int T_1 F_14 ( char * line , int * V_18 )
{
printf ( L_10 ) ;
printf ( L_11 ) ;
return 0 ;
}
static int T_1 F_15 ( char * line , int * V_18 )
{
if ( ! sscanf ( line , L_12 , & V_21 ) ) {
printf ( L_13 , line ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_16 ( char * line , int * V_18 )
{
const char * * V_22 ;
printf ( V_23 , F_12 () -> V_19 ) ;
V_22 = & V_24 ;
while ( V_22 < & V_25 ) {
printf ( L_14 , * V_22 ) ;
V_22 ++ ;
}
exit ( 0 ) ;
return 0 ;
}
static void T_1 F_17 ( char * line , int * V_18 )
{
struct V_26 * V_22 ;
V_22 = & V_27 ;
while ( V_22 < & V_28 ) {
T_3 V_29 ;
V_29 = strlen ( V_22 -> V_30 ) ;
if ( ! strncmp ( line , V_22 -> V_30 , V_29 ) && V_22 -> V_31 ( line + V_29 , V_18 ) )
return;
V_22 ++ ;
}
}
static void T_1 F_18 ( void )
{
T_4 * V_22 ;
V_22 = & V_32 ;
while ( V_22 < & V_33 ) {
(* V_22)() ;
V_22 ++ ;
}
return;
}
static int F_19 ( struct V_34 * V_35 , unsigned long V_36 ,
void * V_37 )
{
F_20 ( 1 ) ;
F_21 ( & ( V_38 -> V_39 . V_40 ) ) ;
F_20 ( 0 ) ;
V_41 = 1 ;
F_22 () ;
return 0 ;
}
int T_1 F_23 ( int V_42 , char * * V_43 )
{
unsigned long V_44 , V_45 ;
unsigned long V_46 , V_47 ;
unsigned long V_48 ;
unsigned int V_49 ;
int V_18 ;
char * V_50 ;
for ( V_49 = 1 ; V_49 < V_42 ; V_49 ++ ) {
if ( ( V_49 == 1 ) && ( V_43 [ V_49 ] [ 0 ] == ' ' ) )
continue;
V_18 = 1 ;
F_17 ( V_43 [ V_49 ] , & V_18 ) ;
if ( V_18 )
F_1 ( V_43 [ V_49 ] ) ;
}
if ( V_20 == 0 )
F_1 ( V_51 ) ;
V_52 = F_24 () ;
V_53 = V_52 & V_54 ;
F_25 () ;
F_26 () ;
if ( V_55 && V_56 )
V_50 = L_15 ;
else
V_50 = L_16 ;
printf ( L_17 , V_50 ) ;
V_57 = ( unsigned long ) F_27 ( 0 ) ;
V_45 = F_28 ( V_57 ) - F_28 ( & V_58 ) ;
if ( V_45 > 1024 * 1024 ) {
printf ( L_18
L_19 , V_45 ) ;
V_59 += F_28 ( V_57 ) - F_28 ( & V_58 ) ;
}
V_60 = ( unsigned long ) & V_61 & V_62 ;
V_63 = F_29 ( V_57 ) + ( 1 << 22 ) ;
F_30 ( F_12 () -> V_64 ) ;
V_65 = 0 ;
V_66 = ( V_66 + V_67 - 1 ) & V_62 ;
V_47 = V_68 - V_60 - V_66 - V_69 ;
V_47 &= ~ ( ( 1 << ( V_70 + V_71 ) ) - 1 ) ;
if ( V_59 + V_66 > V_47 ) {
V_65 = V_59 + V_66 - V_47 ;
V_59 -= V_65 ;
#ifndef F_31
V_65 = 0 ;
printf ( L_20
L_21 , V_59 ) ;
#endif
}
V_72 = V_60 + V_59 ;
V_73 = V_72 + V_66 ;
V_74 = ( void * ) V_73 ;
V_75 = V_76 ;
F_32 ( V_60 , V_63 , V_59 , V_65 ) ;
if ( F_33 ( V_59 , V_66 , V_65 ) ) {
printf ( L_22
L_23 , V_59 ,
V_65 ) ;
exit ( 1 ) ;
}
V_46 = V_59 ;
V_48 = ( unsigned long ) V_43 ;
V_48 &= ~ ( 1024 * 1024 - 1 ) ;
V_44 = V_48 - V_75 ;
if ( V_59 > V_44 )
V_46 = V_44 ;
V_77 = V_75 + V_46 ;
if ( V_46 < V_59 )
printf ( L_24 ,
V_46 ) ;
F_34 ( & V_78 ,
& V_79 ) ;
F_18 () ;
F_35 ( ( unsigned long ) & V_80 ) ;
F_36 () ;
return F_37 () ;
}
void T_1 F_38 ( char * * V_81 )
{
F_39 () ;
F_40 ( V_82 , V_2 , V_3 ) ;
* V_81 = V_2 ;
F_41 ( V_13 , sizeof V_13 ) ;
}
void T_1 F_42 ( void )
{
F_43 () ;
F_44 () ;
}
void F_45 ( struct V_83 * V_84 , struct V_83 * V_85 )
{
}
void F_46 ( struct V_86 * V_87 , char * V_88 ,
void * V_89 , void * V_90 ,
void * V_91 , void * V_92 )
{
}
void F_47 ( struct V_86 * V_87 )
{
}
