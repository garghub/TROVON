static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static inline int F_4 ( int V_1 )
{
if ( ! F_5 ( V_1 , 2 , L_1 ) ) {
F_6 ( L_2 , V_1 ) ;
return - V_3 ;
}
F_2 ( V_4 , V_1 ) ;
return 0 ;
}
static inline void F_7 ( int V_1 , int V_5 )
{
F_2 ( V_6 , V_1 ) ;
F_2 ( V_5 , V_1 + 1 ) ;
}
static inline void F_8 ( int V_1 )
{
F_2 ( V_7 , V_1 ) ;
F_9 ( V_1 , 2 ) ;
}
static int F_10 ( T_1 V_8 , T_2 V_9 , T_1 V_2 , T_2 V_10 )
{
T_2 V_11 ;
int V_12 ;
const int V_13 = 64 ;
const int V_14 = 32 ;
V_11 = F_3 ( V_8 + 1 ) ;
F_2 ( V_11 , V_8 + 1 ) ;
F_2 ( 0x00 , V_8 + 2 ) ;
F_2 ( 0x80 , V_8 + 3 ) ;
F_2 ( V_9 , V_8 + 4 ) ;
F_2 ( 0x01 , V_8 + 5 ) ;
F_2 ( 0x04 , V_8 + 2 ) ;
if ( V_9 == V_15 )
F_2 ( V_10 , V_8 + 4 ) ;
F_2 ( V_2 & 0xff , V_8 + 6 ) ;
F_2 ( V_2 >> 8 , V_8 + 7 ) ;
F_2 ( 0x01 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_13 + V_14 ; V_12 ++ ) {
if ( V_12 >= V_13 )
F_11 ( 1 ) ;
V_11 = F_3 ( V_8 + 8 ) ;
if ( V_11 )
F_2 ( V_11 , V_8 + 8 ) ;
if ( V_11 & 0x01 )
break;
}
if ( V_12 == V_13 + V_14 ) {
F_6 ( L_3
L_4 , V_2 , 1 ) ;
return - V_16 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = F_3 ( V_8 + 1 ) ;
if ( V_11 == 0x01 )
break;
if ( V_12 == 0 )
F_12 ( L_5
L_6 , ( unsigned int ) V_11 , V_2 ) ;
}
if ( V_12 == V_13 ) {
F_6 ( L_3
L_4 , V_2 , 2 ) ;
return - V_16 ;
}
if ( V_9 == V_17 )
return F_3 ( V_8 + 4 ) ;
return 0 ;
}
int F_13 ( T_1 V_8 , T_1 V_2 )
{
return F_10 ( V_8 , V_17 , V_2 , 0 ) ;
}
int F_14 ( T_1 V_8 , T_1 V_2 , T_2 V_11 )
{
return F_10 ( V_8 , V_15 , V_2 , V_11 ) ;
}
int F_15 ( T_1 V_8 , T_1 V_2 )
{
int V_18 , V_19 ;
V_18 = F_13 ( V_8 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = F_13 ( V_8 , V_2 + 1 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_18 | ( V_19 << 8 ) ;
}
int F_16 ( T_1 V_8 , T_1 V_20 , T_1 V_21 ,
int V_22 )
{
int V_19 , V_23 ;
V_19 = F_13 ( V_8 , V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_23 = F_13 ( V_8 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_22 )
return ( V_19 << 4 ) | ( V_23 >> 4 ) ;
else
return ( V_19 << 4 ) | ( V_23 & 0x0f ) ;
}
static int T_3 F_17 ( int V_24 , unsigned short * V_25 ,
const char * * V_26 )
{
T_2 V_27 ;
int V_28 ;
V_28 = F_4 ( V_24 ) ;
if ( V_28 )
return V_28 ;
V_27 = F_1 ( V_24 , V_29 ) ;
switch ( V_27 ) {
case V_30 :
* V_26 = L_7 ;
break;
case V_31 :
* V_26 = L_8 ;
break;
default:
F_18 ( L_9 ,
( unsigned int ) V_27 ) ;
V_28 = - V_32 ;
goto exit;
}
F_7 ( V_24 , V_33 ) ;
if ( ! ( F_1 ( V_24 , V_34 ) & 0x01 ) ) {
F_12 ( L_10 ) ;
V_28 = - V_32 ;
goto exit;
}
* V_25 = F_1 ( V_24 , V_35 ) |
F_1 ( V_24 , V_35 + 1 ) << 8 ;
if ( * V_25 == 0 ) {
F_12 ( L_11 ) ;
V_28 = - V_32 ;
goto exit;
}
exit:
F_8 ( V_24 ) ;
return V_28 ;
}
static int T_3 F_19 ( unsigned short V_25 , const char * V_26 )
{
struct V_36 V_37 = {
. V_38 = V_25 ,
. V_39 = V_25 + V_40 - 1 ,
. V_41 = V_42 ,
} ;
int V_28 ;
V_43 = F_20 ( V_26 , V_25 ) ;
if ( ! V_43 )
return - V_44 ;
V_37 . V_26 = V_43 -> V_26 ;
V_28 = F_21 ( & V_37 ) ;
if ( V_28 )
goto V_45;
V_28 = F_22 ( V_43 , & V_37 , 1 ) ;
if ( V_28 ) {
F_6 ( L_12 ) ;
goto V_45;
}
V_28 = F_23 ( V_43 ) ;
if ( V_28 ) {
F_6 ( L_13 ) ;
goto V_45;
}
return 0 ;
V_45:
F_24 ( V_43 ) ;
return V_28 ;
}
static int T_3 F_25 ( void )
{
int V_28 ;
unsigned short V_25 ;
const char * V_26 ;
V_28 = F_17 ( 0x4e , & V_25 , & V_26 ) ;
if ( V_28 )
V_28 = F_17 ( 0x2e , & V_25 , & V_26 ) ;
if ( V_28 )
return V_28 ;
return F_19 ( V_25 , V_26 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( V_43 ) ;
}
