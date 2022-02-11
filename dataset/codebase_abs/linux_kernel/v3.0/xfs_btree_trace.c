STATIC void
F_1 (
struct V_1 * V_2 ,
union V_3 V_4 ,
T_1 * V_5 ,
T_1 * V_6 )
{
if ( V_2 -> V_7 & V_8 ) {
T_2 V_9 = F_2 ( V_4 . V_10 ) ;
* V_5 = V_9 >> 32 ;
* V_6 = ( int ) V_9 ;
} else {
* V_5 = 0 ;
* V_6 = F_3 ( V_4 . V_11 ) ;
}
}
void
F_4 (
const char * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_15 ,
int line )
{
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_19 ,
line , ( T_1 ) V_14 , V_15 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 ) ;
}
void
F_5 (
const char * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_20 ,
int V_21 ,
int line )
{
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_22 ,
line , ( T_1 ) V_14 , V_20 , V_21 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 ) ;
}
void
F_6 (
const char * V_12 ,
struct V_1 * V_2 ,
T_3 V_23 ,
T_4 V_14 ,
T_5 V_15 ,
int V_24 ,
int line )
{
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_25 ,
line ,
V_23 >> 32 , ( int ) V_23 ,
V_14 >> 32 , ( int ) V_14 ,
V_15 >> 32 , ( int ) V_15 ,
( int ) V_24 , 0 , 0 , 0 , 0 ) ;
}
void
F_7 (
const char * V_12 ,
struct V_1 * V_2 ,
int V_15 ,
int line )
{
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_26 ,
line , V_15 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
}
void
F_8 (
const char * V_12 ,
struct V_1 * V_2 ,
int V_15 ,
union V_3 V_4 ,
union V_27 * V_28 ,
int line )
{
T_1 V_5 , V_6 ;
T_6 V_29 , V_30 ;
F_1 ( V_2 , V_4 , & V_5 , & V_6 ) ;
V_2 -> V_16 -> V_31 ( V_2 , V_28 , & V_29 , & V_30 ) ;
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_32 ,
line , V_15 , V_5 , V_6 ,
V_29 >> 32 , ( int ) V_29 ,
V_30 >> 32 , ( int ) V_30 ,
0 , 0 , 0 , 0 ) ;
}
void
F_9 (
const char * V_12 ,
struct V_1 * V_2 ,
int V_15 ,
union V_3 V_4 ,
union V_33 * V_34 ,
int line )
{
T_1 V_5 , V_6 ;
T_6 V_29 , V_30 , V_35 ;
F_1 ( V_2 , V_4 , & V_5 , & V_6 ) ;
V_2 -> V_16 -> V_36 ( V_2 , V_34 , & V_29 , & V_30 , & V_35 ) ;
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_37 ,
line , V_15 ,
V_5 , V_6 ,
V_29 >> 32 , ( int ) V_29 ,
V_30 >> 32 , ( int ) V_30 ,
V_35 >> 32 , ( int ) V_35 ,
0 , 0 ) ;
}
void
F_10 (
const char * V_12 ,
struct V_1 * V_2 ,
int V_15 ,
union V_27 * V_28 ,
int line )
{
T_6 V_29 , V_30 ;
V_2 -> V_16 -> V_31 ( V_2 , V_28 , & V_29 , & V_30 ) ;
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_38 ,
line , V_15 ,
V_29 >> 32 , ( int ) V_29 ,
V_30 >> 32 , ( int ) V_30 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
}
void
F_11 (
const char * V_12 ,
struct V_1 * V_2 ,
union V_33 * V_34 ,
int line )
{
T_6 V_29 , V_30 , V_35 ;
V_2 -> V_16 -> V_36 ( V_2 , V_34 , & V_29 , & V_30 , & V_35 ) ;
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_18 , V_39 ,
line ,
V_29 >> 32 , ( int ) V_29 ,
V_30 >> 32 , ( int ) V_30 ,
V_35 >> 32 , ( int ) V_35 ,
0 , 0 , 0 , 0 , 0 ) ;
}
void
F_12 (
const char * V_12 ,
struct V_1 * V_2 ,
int type ,
int line )
{
T_7 V_40 ;
T_6 V_29 , V_30 ;
char * V_11 ;
switch ( type ) {
case V_18 :
V_11 = L_1 ;
break;
case V_41 :
V_11 = L_2 ;
break;
case V_42 :
V_11 = L_3 ;
break;
case V_43 :
V_11 = L_4 ;
break;
default:
V_11 = L_5 ;
break;
}
V_2 -> V_16 -> V_44 ( V_2 , & V_40 , & V_29 , & V_30 ) ;
V_2 -> V_16 -> V_17 ( V_2 , V_12 , V_11 , V_45 , line ,
V_40 ,
V_29 >> 32 , ( int ) V_29 ,
V_30 >> 32 , ( int ) V_30 ,
( T_1 ) V_2 -> V_46 [ 0 ] ,
( T_1 ) V_2 -> V_46 [ 1 ] ,
( T_1 ) V_2 -> V_46 [ 2 ] ,
( T_1 ) V_2 -> V_46 [ 3 ] ,
( V_2 -> V_47 [ 0 ] << 16 ) | V_2 -> V_47 [ 1 ] ,
( V_2 -> V_47 [ 2 ] << 16 ) | V_2 -> V_47 [ 3 ] ) ;
}
