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
F_5 ( V_8 , L_3 , V_10 ) ;
F_5 ( V_8 , L_4 ) ;
F_5 ( V_8 , L_5 ) ;
F_5 ( V_8 , L_6 ) ;
F_5 ( V_8 , L_7 , V_11 ) ;
F_5 ( V_8 , L_8 ,
V_12 / ( 500000 / V_13 ) ,
( V_12 / ( 5000 / V_13 ) ) % 100 ) ;
return 0 ;
}
static void * F_6 ( struct V_7 * V_8 , T_2 * V_14 )
{
return * V_14 < V_15 ? V_16 + * V_14 : NULL ;
}
static void * F_7 ( struct V_7 * V_8 , void * V_9 , T_2 * V_14 )
{
++ * V_14 ;
return F_6 ( V_8 , V_14 ) ;
}
static void F_8 ( struct V_7 * V_8 , void * V_9 )
{
}
static int T_1 F_9 ( char * line , int * V_17 )
{
printf ( L_9 , F_10 () -> V_18 ) ;
exit ( 0 ) ;
return 0 ;
}
static int T_1 F_11 ( char * line , int * V_17 )
{
V_19 = 1 ;
return 0 ;
}
static int T_1 F_12 ( char * line , int * V_17 )
{
printf ( L_10 ) ;
printf ( L_11 ) ;
return 0 ;
}
static int T_1 F_13 ( char * line , int * V_17 )
{
const char * * V_20 ;
printf ( V_21 , F_10 () -> V_18 ) ;
V_20 = & V_22 ;
while ( V_20 < & V_23 ) {
printf ( L_12 , * V_20 ) ;
V_20 ++ ;
}
exit ( 0 ) ;
return 0 ;
}
static void T_1 F_14 ( char * line , int * V_17 )
{
struct V_24 * V_20 ;
V_20 = & V_25 ;
while ( V_20 < & V_26 ) {
T_3 V_27 ;
V_27 = strlen ( V_20 -> V_28 ) ;
if ( ! strncmp ( line , V_20 -> V_28 , V_27 ) && V_20 -> V_29 ( line + V_27 , V_17 ) )
return;
V_20 ++ ;
}
}
static void T_1 F_15 ( void )
{
T_4 * V_20 ;
V_20 = & V_30 ;
while ( V_20 < & V_31 ) {
(* V_20)() ;
V_20 ++ ;
}
return;
}
static int F_16 ( struct V_32 * V_33 , unsigned long V_34 ,
void * V_35 )
{
F_17 ( V_36 ) ;
F_18 ( 1 ) ;
F_18 ( 0 ) ;
V_37 = 1 ;
F_19 () ;
return 0 ;
}
void F_20 ( void )
{
F_21 ( & V_38 ,
& V_39 ) ;
F_15 () ;
F_22 () ;
}
int T_1 F_23 ( int V_40 , char * * V_41 )
{
unsigned long V_42 , V_43 ;
unsigned long V_44 , V_45 ;
unsigned long V_46 ;
unsigned int V_47 ;
int V_17 ;
for ( V_47 = 1 ; V_47 < V_40 ; V_47 ++ ) {
if ( ( V_47 == 1 ) && ( V_41 [ V_47 ] [ 0 ] == ' ' ) )
continue;
V_17 = 1 ;
F_14 ( V_41 [ V_47 ] , & V_17 ) ;
if ( V_17 )
F_1 ( V_41 [ V_47 ] ) ;
}
if ( V_19 == 0 )
F_1 ( V_48 ) ;
V_49 = F_24 () ;
V_50 = V_49 & V_51 ;
F_25 () ;
V_52 = ( unsigned long ) F_26 ( 0 ) ;
V_43 = F_27 ( V_52 ) - F_27 ( & V_53 ) ;
if ( V_43 > 1024 * 1024 ) {
printf ( L_13
L_14 , V_43 ) ;
V_54 += F_27 ( V_52 ) - F_27 ( & V_53 ) ;
}
V_55 = ( unsigned long ) & V_56 & V_57 ;
V_58 = F_28 ( V_52 ) + ( 1 << 22 ) ;
F_29 ( F_10 () -> V_59 ) ;
V_60 = 0 ;
V_61 = ( V_61 + V_62 - 1 ) & V_57 ;
V_45 = V_63 - V_55 - V_61 - V_64 ;
V_45 &= ~ ( ( 1 << ( V_65 + V_66 ) ) - 1 ) ;
if ( V_54 + V_61 > V_45 ) {
V_60 = V_54 + V_61 - V_45 ;
V_54 -= V_60 ;
}
V_67 = V_55 + V_54 ;
V_68 = V_67 + V_61 ;
V_69 = ( void * ) V_68 ;
V_70 = V_71 ;
F_30 ( V_55 , V_58 , V_54 , V_60 ) ;
F_31 ( V_54 , V_61 , V_60 ) ;
V_44 = V_54 ;
V_46 = ( unsigned long ) V_41 ;
V_46 &= ~ ( 1024 * 1024 - 1 ) ;
V_42 = V_46 - V_70 ;
if ( V_54 > V_42 )
V_44 = V_42 ;
V_72 = V_70 + V_44 ;
if ( V_44 < V_54 )
printf ( L_15 ,
V_44 ) ;
F_32 ( ( unsigned long ) & V_73 ) ;
F_33 () ;
return F_34 () ;
}
void T_1 F_35 ( char * * V_74 )
{
F_36 () ;
F_37 ( V_75 , V_2 , V_3 ) ;
* V_74 = V_2 ;
F_38 ( V_11 , sizeof V_11 ) ;
}
void T_1 F_39 ( void )
{
F_40 () ;
F_41 () ;
}
void F_42 ( struct V_76 * V_77 , struct V_76 * V_78 )
{
}
