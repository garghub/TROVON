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
F_20 ( 0 ) ;
V_38 = 1 ;
F_21 () ;
return 0 ;
}
int T_1 F_22 ( int V_39 , char * * V_40 )
{
unsigned long V_41 , V_42 ;
unsigned long V_43 , V_44 ;
unsigned long V_45 ;
unsigned int V_46 ;
int V_18 ;
char * V_47 ;
for ( V_46 = 1 ; V_46 < V_39 ; V_46 ++ ) {
if ( ( V_46 == 1 ) && ( V_40 [ V_46 ] [ 0 ] == ' ' ) )
continue;
V_18 = 1 ;
F_17 ( V_40 [ V_46 ] , & V_18 ) ;
if ( V_18 )
F_1 ( V_40 [ V_46 ] ) ;
}
if ( V_20 == 0 )
F_1 ( V_48 ) ;
V_49 = F_23 () ;
V_50 = V_49 & V_51 ;
F_24 () ;
F_25 () ;
if ( V_52 && V_53 )
V_47 = L_15 ;
else
V_47 = L_16 ;
printf ( L_17 , V_47 ) ;
V_54 = ( unsigned long ) F_26 ( 0 ) ;
V_42 = F_27 ( V_54 ) - F_27 ( & V_55 ) ;
if ( V_42 > 1024 * 1024 ) {
printf ( L_18
L_19 , V_42 ) ;
V_56 += F_27 ( V_54 ) - F_27 ( & V_55 ) ;
}
V_57 = ( unsigned long ) & V_58 & V_59 ;
V_60 = F_28 ( V_54 ) + ( 1 << 22 ) ;
F_29 ( F_12 () -> V_61 ) ;
V_62 = 0 ;
V_63 = ( V_63 + V_64 - 1 ) & V_59 ;
V_44 = V_65 - V_57 - V_63 - V_66 ;
V_44 &= ~ ( ( 1 << ( V_67 + V_68 ) ) - 1 ) ;
if ( V_56 + V_63 > V_44 ) {
V_62 = V_56 + V_63 - V_44 ;
V_56 -= V_62 ;
#ifndef F_30
V_62 = 0 ;
printf ( L_20
L_21 , V_56 ) ;
#endif
}
V_69 = V_57 + V_56 ;
V_70 = V_69 + V_63 ;
V_71 = ( void * ) V_70 ;
V_72 = V_73 ;
F_31 ( V_57 , V_60 , V_56 , V_62 ) ;
if ( F_32 ( V_56 , V_63 , V_62 ) ) {
printf ( L_22
L_23 , V_56 ,
V_62 ) ;
exit ( 1 ) ;
}
V_43 = V_56 ;
V_45 = ( unsigned long ) V_40 ;
V_45 &= ~ ( 1024 * 1024 - 1 ) ;
V_41 = V_45 - V_72 ;
if ( V_56 > V_41 )
V_43 = V_41 ;
V_74 = V_72 + V_43 ;
if ( V_43 < V_56 )
printf ( L_24 ,
V_43 ) ;
F_33 ( & V_75 ,
& V_76 ) ;
F_18 () ;
F_34 ( ( unsigned long ) & V_77 ) ;
F_35 () ;
return F_36 () ;
}
void T_1 F_37 ( char * * V_78 )
{
F_38 () ;
F_39 ( V_79 , V_2 , V_3 ) ;
* V_78 = V_2 ;
F_40 ( V_13 , sizeof V_13 ) ;
}
void T_1 F_41 ( void )
{
F_42 () ;
F_43 () ;
}
void F_44 ( struct V_80 * V_81 , struct V_80 * V_82 )
{
}
void F_45 ( struct V_83 * V_84 , char * V_85 ,
void * V_86 , void * V_87 ,
void * V_88 , void * V_89 )
{
}
void F_46 ( struct V_83 * V_84 )
{
}
