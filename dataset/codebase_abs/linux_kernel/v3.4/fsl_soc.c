T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 != - 1 )
return V_3 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
int V_4 ;
T_2 V_5 ;
const T_2 * V_6 = F_3 ( V_2 , L_2 , & V_4 ) ;
if ( V_6 && V_4 == 4 )
V_5 = * V_6 ;
else
V_5 = 2 ;
V_6 = F_3 ( V_2 , L_3 , & V_4 ) ;
if ( V_6 )
V_3 = F_4 ( V_2 , V_6 + V_5 ) ;
F_5 ( V_2 ) ;
}
return V_3 ;
}
T_2 F_6 ( void )
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
F_5 ( V_2 ) ;
return V_7 ;
}
T_2 F_7 ( void )
{
struct V_1 * V_8 ;
const unsigned int * V_6 ;
int V_4 ;
if ( V_9 != - 1 )
return V_9 ;
V_8 = F_8 ( NULL , NULL , L_6 ) ;
if ( V_8 ) {
V_6 = F_3 ( V_8 , L_4 , & V_4 ) ;
if ( V_6 && V_4 == 4 )
V_9 = * V_6 ;
F_5 ( V_8 ) ;
return V_9 ;
}
V_8 = F_2 ( NULL , L_7 ) ;
if ( ! V_8 )
V_8 = F_8 ( NULL , NULL , L_8 ) ;
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
F_5 ( V_8 ) ;
}
return V_9 ;
}
T_2 F_9 ( void )
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
F_5 ( V_8 ) ;
}
return V_10 ;
}
static int T_3 F_10 ( void )
{
int V_11 ;
struct V_1 * V_12 ;
T_2 * V_13 ;
struct V_14 V_15 = {} ;
F_11 (np, L_13 ) {
V_13 = ( T_2 * ) F_3 ( V_12 , L_14 , NULL ) ;
if ( ! V_13 )
continue;
V_15 . V_16 = 1 ;
V_15 . V_17 = V_13 [ 1 ] ;
V_15 . V_18 = V_13 [ 2 ] ;
V_15 . V_19 = V_13 [ 3 ] ;
V_15 . V_20 = V_13 [ 4 ] ;
V_11 = F_12 ( V_21 , V_13 [ 0 ] , & V_15 ) ;
if ( V_11 ) {
F_5 ( V_12 ) ;
return V_11 ;
}
}
return 0 ;
}
static int T_3 F_13 ( void )
{
struct V_1 * V_12 ;
F_11 (np, L_15 ) {
if ( ( F_3 ( V_12 , L_16 , NULL ) ) ) {
V_22 = F_14 ( V_12 , 0 ) + 0xb0 ;
if ( ! V_22 )
F_15 ( V_23 L_17
L_18 ) ;
break;
}
}
if ( ! V_22 && V_24 . V_25 == V_26 )
F_15 ( V_23 L_19 ) ;
if ( V_12 )
F_5 ( V_12 ) ;
return 0 ;
}
void V_26 ( char * V_27 )
{
F_16 () ;
if ( V_22 )
F_17 ( V_22 , 0x2 ) ;
while ( 1 ) ;
}
void F_18 ( char * V_27 )
{
F_19 ( L_20 ) ;
F_20 ( - 1 ) ;
}
void F_21 ( void )
{
F_19 ( L_21 ) ;
F_22 ( - 1 ) ;
}
