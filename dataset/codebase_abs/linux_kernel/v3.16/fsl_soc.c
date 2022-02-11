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
struct V_1 * V_2 ;
const T_2 * V_6 ;
int V_4 ;
if ( V_7 != - 1 )
return V_7 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( ! V_2 )
return - 1 ;
V_6 = F_3 ( V_2 , L_4 , & V_4 ) ;
if ( ! V_6 || V_4 != sizeof( * V_6 ) || * V_6 == 0 )
V_6 = F_3 ( V_2 , L_5 , & V_4 ) ;
if ( V_6 && V_4 == sizeof( * V_6 ) )
V_7 = * V_6 ;
F_6 ( V_2 ) ;
return V_7 ;
}
T_2 F_8 ( void )
{
struct V_1 * V_8 ;
const unsigned int * V_6 ;
int V_4 ;
if ( V_9 != - 1 )
return V_9 ;
V_8 = F_9 ( NULL , NULL , L_6 ) ;
if ( V_8 ) {
V_6 = F_3 ( V_8 , L_4 , & V_4 ) ;
if ( V_6 && V_4 == 4 )
V_9 = * V_6 ;
F_6 ( V_8 ) ;
return V_9 ;
}
V_8 = F_2 ( NULL , L_7 ) ;
if ( ! V_8 )
V_8 = F_9 ( NULL , NULL , L_8 ) ;
if ( ! V_8 )
V_8 = F_2 ( NULL , L_9 ) ;
if ( V_8 ) {
V_6 = F_3 ( V_8 , L_10 , & V_4 ) ;
if ( V_6 && V_4 == 4 )
V_9 = * V_6 ;
if ( V_9 == - 1 || V_9 == 0 ) {
V_6 = F_3 ( V_8 , L_5 , & V_4 ) ;
if ( V_6 && V_4 == 4 )
V_9 = * V_6 / 2 ;
}
F_6 ( V_8 ) ;
}
return V_9 ;
}
T_2 F_10 ( void )
{
struct V_1 * V_8 ;
if ( V_10 != - 1 )
return V_10 ;
V_8 = F_2 ( NULL , L_11 ) ;
if ( V_8 ) {
int V_4 ;
const unsigned int * V_6 = F_3 ( V_8 ,
L_12 , & V_4 ) ;
if ( V_6 )
V_10 = * V_6 ;
F_6 ( V_8 ) ;
}
return V_10 ;
}
static int T_4 F_11 ( void )
{
struct V_1 * V_11 ;
F_12 (np, L_13 ) {
if ( ( F_3 ( V_11 , L_14 , NULL ) ) ) {
V_12 = F_13 ( V_11 , 0 ) + 0xb0 ;
if ( ! V_12 )
F_14 ( V_13 L_15
L_16 ) ;
break;
}
}
if ( ! V_12 && V_14 . V_15 == V_16 )
F_14 ( V_13 L_17 ) ;
if ( V_11 )
F_6 ( V_11 ) ;
return 0 ;
}
void V_16 ( char * V_17 )
{
F_15 () ;
if ( V_12 )
F_16 ( V_12 , 0x2 ) ;
while ( 1 ) ;
}
void F_17 ( char * V_17 )
{
F_18 ( L_18 ) ;
F_19 ( - 1 ) ;
}
void F_20 ( void )
{
F_18 ( L_19 ) ;
F_21 ( - 1 ) ;
}
