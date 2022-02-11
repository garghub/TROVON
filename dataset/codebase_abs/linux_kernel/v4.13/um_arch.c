static void T_1 F_1 ( char * V_1 )
{
if ( strlen ( V_2 ) + strlen ( V_1 ) + 1 > V_3 ) {
F_2 ( L_1 ) ;
exit ( 1 ) ;
}
if ( strlen ( V_2 ) > 0 )
strcat ( V_2 , L_2 ) ;
strcat ( V_2 , V_1 ) ;
}
static int F_3 ( struct V_4 * V_5 , void * V_6 )
{
int V_7 = 0 ;
F_4 ( V_5 , L_3 , V_7 ) ;
F_4 ( V_5 , L_4 ) ;
F_4 ( V_5 , L_5 ) ;
F_4 ( V_5 , L_6 ) ;
F_4 ( V_5 , L_7 , V_8 ) ;
F_4 ( V_5 , L_8 ,
V_9 / ( 500000 / V_10 ) ,
( V_9 / ( 5000 / V_10 ) ) % 100 ) ;
return 0 ;
}
static void * F_5 ( struct V_4 * V_5 , T_2 * V_11 )
{
return * V_11 < V_12 ? V_13 + * V_11 : NULL ;
}
static void * F_6 ( struct V_4 * V_5 , void * V_6 , T_2 * V_11 )
{
++ * V_11 ;
return F_5 ( V_5 , V_11 ) ;
}
static void F_7 ( struct V_4 * V_5 , void * V_6 )
{
}
static int T_1 F_8 ( char * line , int * V_14 )
{
printf ( L_9 , F_9 () -> V_15 ) ;
exit ( 0 ) ;
return 0 ;
}
static int T_1 F_10 ( char * line , int * V_14 )
{
V_16 = 1 ;
return 0 ;
}
static int T_1 F_11 ( char * line , int * V_14 )
{
F_2 ( L_10 ) ;
F_2 ( L_11 ) ;
return 0 ;
}
static int T_1 F_12 ( char * line , int * V_14 )
{
const char * * V_17 ;
printf ( V_18 , F_9 () -> V_15 ) ;
V_17 = & V_19 ;
while ( V_17 < & V_20 ) {
printf ( L_12 , * V_17 ) ;
V_17 ++ ;
}
exit ( 0 ) ;
return 0 ;
}
static void T_1 F_13 ( char * line , int * V_14 )
{
struct V_21 * V_17 ;
V_17 = & V_22 ;
while ( V_17 < & V_23 ) {
T_3 V_24 ;
V_24 = strlen ( V_17 -> V_25 ) ;
if ( ! strncmp ( line , V_17 -> V_25 , V_24 ) && V_17 -> V_26 ( line + V_24 , V_14 ) )
return;
V_17 ++ ;
}
}
static void T_1 F_14 ( void )
{
T_4 * V_17 ;
V_17 = & V_27 ;
while ( V_17 < & V_28 ) {
(* V_17)() ;
V_17 ++ ;
}
return;
}
static int F_15 ( struct V_29 * V_30 , unsigned long V_31 ,
void * V_32 )
{
F_16 ( V_33 ) ;
F_17 ( 1 ) ;
F_17 ( 0 ) ;
V_34 = 1 ;
F_18 () ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( & V_35 ,
& V_36 ) ;
F_14 () ;
F_21 () ;
}
int T_1 F_22 ( int V_37 , char * * V_38 )
{
unsigned long V_39 , V_40 ;
unsigned long V_41 , V_42 ;
unsigned long V_43 ;
unsigned int V_44 ;
int V_14 ;
for ( V_44 = 1 ; V_44 < V_37 ; V_44 ++ ) {
if ( ( V_44 == 1 ) && ( V_38 [ V_44 ] [ 0 ] == ' ' ) )
continue;
V_14 = 1 ;
F_13 ( V_38 [ V_44 ] , & V_14 ) ;
if ( V_14 )
F_1 ( V_38 [ V_44 ] ) ;
}
if ( V_16 == 0 )
F_1 ( V_45 ) ;
V_46 = F_23 () ;
V_47 = V_46 & V_48 ;
F_24 () ;
V_49 = ( unsigned long ) F_25 ( 0 ) ;
V_40 = F_26 ( V_49 ) - F_26 ( & V_50 ) ;
if ( V_40 > 1024 * 1024 ) {
F_27 ( L_13
L_14 , V_40 ) ;
V_51 += F_26 ( V_49 ) - F_26 ( & V_50 ) ;
}
V_52 = ( unsigned long ) V_53 & V_54 ;
V_55 = F_28 ( V_49 ) + ( 1 << 22 ) ;
F_29 ( F_9 () -> V_56 ) ;
V_57 = 0 ;
V_58 = ( V_58 + V_59 - 1 ) & V_54 ;
V_42 = V_60 - V_52 - V_58 - V_61 ;
V_42 &= ~ ( ( 1 << ( V_62 + V_63 ) ) - 1 ) ;
if ( V_51 + V_58 > V_42 ) {
V_57 = V_51 + V_58 - V_42 ;
V_51 -= V_57 ;
}
V_64 = V_52 + V_51 ;
V_65 = V_64 + V_58 ;
V_66 = ( void * ) V_65 ;
V_67 = V_68 ;
V_41 = V_51 ;
V_43 = ( unsigned long ) V_38 ;
V_43 &= ~ ( 1024 * 1024 - 1 ) ;
V_39 = V_43 - V_67 ;
if ( V_51 > V_39 )
V_41 = V_39 ;
V_69 = V_67 + V_41 ;
if ( V_41 < V_51 )
F_27 ( L_15 ,
V_41 ) ;
F_30 () ;
return F_31 () ;
}
int T_1 __weak F_32 ( void )
{
return 0 ;
}
void T_1 F_33 ( char * * V_70 )
{
F_34 ( ( unsigned long ) & V_71 ) ;
F_35 ( V_52 , V_55 , V_51 , V_57 ) ;
F_36 ( V_51 , V_58 , V_57 ) ;
F_32 () ;
F_37 () ;
F_38 ( V_72 , V_2 , V_3 ) ;
* V_70 = V_2 ;
F_39 ( V_8 , sizeof V_8 ) ;
}
void T_1 F_40 ( void )
{
F_41 () ;
F_42 () ;
}
void F_43 ( struct V_73 * V_74 , struct V_73 * V_75 )
{
}
