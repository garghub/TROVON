T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 != - 1 )
return V_3 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
int V_4 ;
T_2 V_5 ;
const T_3 * V_6 = F_3 ( V_2 , L_2 , & V_4 ) ;
if ( V_6 && V_4 == 4 )
V_5 = F_4 ( V_6 ) ;
else
V_5 = 2 ;
V_6 = F_3 ( V_2 , L_3 , & V_4 ) ;
if ( V_6 )
V_3 = F_5 ( V_2 , V_6 + V_5 ) ;
F_6 ( V_2 ) ;
}
return V_3 ;
}
T_2 F_7 ( void )
{
static T_2 V_7 = - 1 ;
struct V_1 * V_2 ;
if ( V_7 != - 1 )
return V_7 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( ! V_2 )
return - 1 ;
F_8 ( V_2 , L_4 , & V_7 ) ;
if ( V_7 == - 1 || ! V_7 )
F_8 ( V_2 , L_5 , & V_7 ) ;
F_6 ( V_2 ) ;
return V_7 ;
}
T_2 F_9 ( void )
{
static T_2 V_8 = - 1 ;
struct V_1 * V_9 ;
if ( V_8 != - 1 )
return V_8 ;
V_9 = F_10 ( NULL , NULL , L_6 ) ;
if ( V_9 ) {
F_8 ( V_9 , L_4 , & V_8 ) ;
F_6 ( V_9 ) ;
return V_8 ;
}
V_9 = F_2 ( NULL , L_7 ) ;
if ( ! V_9 )
V_9 = F_10 ( NULL , NULL , L_8 ) ;
if ( ! V_9 )
V_9 = F_2 ( NULL , L_9 ) ;
if ( V_9 ) {
F_8 ( V_9 , L_10 , & V_8 ) ;
if ( V_8 == - 1 || ! V_8 )
if ( ! F_8 ( V_9 , L_5 ,
& V_8 ) )
V_8 /= 2 ;
F_6 ( V_9 ) ;
}
return V_8 ;
}
T_2 F_11 ( void )
{
static T_2 V_10 = - 1 ;
struct V_1 * V_9 ;
if ( V_10 != - 1 )
return V_10 ;
V_9 = F_2 ( NULL , L_11 ) ;
if ( V_9 ) {
F_8 ( V_9 , L_12 , & V_10 ) ;
F_6 ( V_9 ) ;
}
return V_10 ;
}
static int F_12 ( struct V_11 * V_12 ,
unsigned long V_13 , void * V_14 )
{
F_13 () ;
F_14 ( V_15 , 0x2 ) ;
return V_16 ;
}
static int T_4 F_15 ( void )
{
struct V_1 * V_17 ;
static struct V_11 V_18 = {
. V_19 = F_12 ,
. V_20 = 128 ,
} ;
F_16 (np, L_13 ) {
if ( ( F_3 ( V_17 , L_14 , NULL ) ) ) {
V_15 = F_17 ( V_17 , 0 ) + 0xb0 ;
if ( ! V_15 ) {
F_18 ( V_21 L_15
L_16 ) ;
} else {
F_19 ( & V_18 ) ;
}
break;
}
}
F_6 ( V_17 ) ;
return 0 ;
}
void T_5 F_20 ( char * V_14 )
{
F_21 ( L_17 ) ;
F_22 ( - 1 ) ;
while ( 1 ) ;
}
void T_5 F_23 ( void )
{
F_21 ( L_18 ) ;
F_24 ( - 1 ) ;
while ( 1 ) ;
}
