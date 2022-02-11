static int F_1 ( enum V_1 V_2 , unsigned int V_3 ,
char * V_4 , T_1 V_5 )
{
register unsigned long T_2 V_6 ( L_1 ) = V_2 ;
register unsigned long T_3 V_6 ( L_2 ) = V_3 ;
register unsigned long T_4 V_6 ( L_3 ) = F_2 ( V_4 ) ;
register unsigned long T_5 V_6 ( L_4 ) = V_5 ;
int V_7 ;
V_7 = - V_8 ;
asm volatile(
" diag %1,%3,0x288\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (err) : "d"(__func), "d"(__timeout),
"d"(__cmdp), "d"(__cmdl) : "1", "cc");
return V_7 ;
}
static int F_3 ( void )
{
static char * V_9 ;
T_1 V_5 ;
int V_10 ;
unsigned int V_2 ;
V_9 = F_4 ( V_11 , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_5 = F_5 ( V_9 , V_14 , V_11 ) ;
F_6 ( V_9 , V_11 ) ;
F_7 ( V_9 , V_11 ) ;
V_2 = V_15 ? ( V_16 | V_17 ) : V_16 ;
F_8 ( V_18 , & V_19 ) ;
V_10 = F_1 ( V_2 , V_20 , V_9 , V_5 ) ;
F_9 ( V_10 != 0 ) ;
F_10 ( V_9 ) ;
return V_10 ;
}
static int F_11 ( void )
{
char V_4 [] = { '\0' } ;
int V_10 = F_1 ( V_21 , 0 , V_4 , 0 ) ;
F_9 ( V_10 != 0 ) ;
F_12 ( V_18 , & V_19 ) ;
return V_10 ;
}
static int T_6 F_13 ( void )
{
char V_22 [] = {
194 , 197 , 199 , 201 , 213
} ;
if ( F_1 ( V_16 , 15 , V_22 , sizeof( V_22 ) ) != 0 )
return - V_8 ;
return F_11 () ;
}
static int F_14 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
int V_10 ;
if ( F_15 ( V_27 , & V_19 ) )
return - V_28 ;
V_10 = F_3 () ;
if ( V_10 )
F_12 ( V_27 , & V_19 ) ;
return V_10 ? V_10 : F_16 ( V_24 , V_26 ) ;
}
static int F_17 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
if ( V_29 == 42 )
F_11 () ;
V_29 = 0 ;
F_12 ( V_27 , & V_19 ) ;
return 0 ;
}
static int F_18 ( unsigned int V_4 , unsigned long V_30 )
{
switch ( V_4 ) {
case V_31 :
if ( F_19 ( ( void V_32 * ) V_30 , & V_33 ,
sizeof( V_33 ) ) )
return - V_34 ;
return 0 ;
case V_35 :
case V_36 :
return F_20 ( 0 , ( int V_32 * ) V_30 ) ;
case V_37 :
return - V_8 ;
case V_38 :
{
int V_39 , V_10 ;
if ( F_21 ( V_39 , ( int V_32 * ) V_30 ) )
return - V_34 ;
V_10 = - V_8 ;
if ( V_39 & V_40 ) {
V_10 = F_11 () ;
if ( V_10 )
return V_10 ;
}
if ( V_39 & V_41 ) {
V_10 = F_3 () ;
}
return V_10 ;
}
case V_42 :
return F_20 ( V_20 , ( int V_32 * ) V_30 ) ;
case V_43 :
{
int V_44 ;
if ( F_21 ( V_44 , ( int V_32 * ) V_30 ) )
return - V_34 ;
if ( V_44 < V_45 )
return - V_8 ;
V_20 = V_44 ;
}
return F_3 () ;
case V_46 :
return F_3 () ;
}
return - V_8 ;
}
static long F_22 ( struct V_25 * V_26 , unsigned int V_4 , unsigned long V_30 )
{
int V_47 ;
F_23 ( & V_48 ) ;
V_47 = F_18 ( V_4 , V_30 ) ;
F_24 ( & V_48 ) ;
return ( long ) V_47 ;
}
static T_7 F_25 ( struct V_25 * V_26 , const char V_32 * V_49 ,
T_1 V_50 , T_8 * V_51 )
{
if( V_50 ) {
if ( ! V_52 ) {
T_1 V_24 ;
V_29 = 0 ;
for ( V_24 = 0 ; V_24 != V_50 ; V_24 ++ ) {
char V_53 ;
if ( F_21 ( V_53 , V_49 + V_24 ) )
return - V_34 ;
if ( V_53 == 'V' )
V_29 = 42 ;
}
}
F_3 () ;
}
return V_50 ;
}
static int F_26 ( void )
{
F_12 ( V_27 , & V_19 ) ;
return V_54 ;
}
static int F_27 ( void )
{
if ( F_15 ( V_27 , & V_19 ) ) {
F_28 ( L_5
L_6 ) ;
return F_29 ( - V_28 ) ;
}
if ( F_30 ( V_18 , & V_19 ) ) {
F_12 ( V_27 , & V_19 ) ;
F_28 ( L_5
L_7 ) ;
return F_29 ( - V_28 ) ;
}
return V_54 ;
}
static int F_31 ( struct V_55 * V_56 , unsigned long V_57 ,
void * V_58 )
{
switch ( V_57 ) {
case V_59 :
case V_60 :
return F_26 () ;
case V_61 :
case V_62 :
return F_27 () ;
default:
return V_54 ;
}
}
static int T_6 F_32 ( void )
{
int V_10 ;
V_10 = F_13 () ;
if ( V_10 )
return V_10 ;
V_10 = F_33 ( & V_63 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_34 ( & V_64 ) ;
if ( V_10 ) {
F_35 ( & V_63 ) ;
return V_10 ;
}
return 0 ;
}
static void T_9 F_36 ( void )
{
F_35 ( & V_63 ) ;
F_37 ( & V_64 ) ;
}
