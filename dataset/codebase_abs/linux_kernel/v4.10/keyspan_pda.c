static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_3 ( & V_7 -> V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
int V_11 ;
V_11 = F_5 ( V_10 -> V_12 ,
F_6 ( V_10 -> V_12 , 0 ) ,
7 ,
V_13 | V_14
| V_15 ,
16 ,
0 ,
NULL ,
0 ,
2000 ) ;
if ( V_11 < 0 )
F_7 ( & V_10 -> V_12 -> V_12 , L_1 ,
V_16 , V_11 ) ;
}
static void F_8 ( struct V_17 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_18 ;
unsigned char * V_19 = V_17 -> V_20 ;
int V_21 ;
int V_22 = V_17 -> V_22 ;
struct V_3 * V_4 ;
V_4 = F_9 ( V_7 ) ;
switch ( V_22 ) {
case 0 :
break;
case - V_23 :
case - V_24 :
case - V_25 :
F_7 ( & V_17 -> V_12 -> V_12 , L_2 , V_16 , V_22 ) ;
return;
default:
F_7 ( & V_17 -> V_12 -> V_12 , L_3 , V_16 , V_22 ) ;
goto exit;
}
switch ( V_19 [ 0 ] ) {
case 0 :
if ( V_17 -> V_26 ) {
F_10 ( & V_7 -> V_7 , V_19 + 1 ,
V_17 -> V_26 - 1 ) ;
F_11 ( & V_7 -> V_7 ) ;
}
break;
case 1 :
F_7 ( & V_7 -> V_12 , L_4 , V_19 [ 1 ] , V_19 [ 2 ] ) ;
switch ( V_19 [ 1 ] ) {
case 1 :
break;
case 2 :
V_4 -> V_27 = 0 ;
F_12 ( & V_4 -> V_5 ) ;
break;
default:
break;
}
break;
default:
break;
}
exit:
V_21 = F_13 ( V_17 , V_28 ) ;
if ( V_21 )
F_14 ( & V_7 -> V_12 ,
L_5 ,
V_16 , V_21 ) ;
}
static void F_15 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
F_16 ( V_7 -> V_32 ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
if ( F_13 ( V_7 -> V_32 , V_33 ) )
F_7 ( & V_7 -> V_12 , L_6 ) ;
}
static T_1 F_18 ( struct V_9 * V_10 , T_1 V_34 )
{
int V_35 ;
int V_36 ;
switch ( V_34 ) {
case 110 :
V_36 = 0 ;
break;
case 300 :
V_36 = 1 ;
break;
case 1200 :
V_36 = 2 ;
break;
case 2400 :
V_36 = 3 ;
break;
case 4800 :
V_36 = 4 ;
break;
case 9600 :
V_36 = 5 ;
break;
case 19200 :
V_36 = 6 ;
break;
case 38400 :
V_36 = 7 ;
break;
case 57600 :
V_36 = 8 ;
break;
case 115200 :
V_36 = 9 ;
break;
default:
V_36 = 5 ;
V_34 = 9600 ;
}
V_35 = F_5 ( V_10 -> V_12 , F_6 ( V_10 -> V_12 , 0 ) ,
0 ,
V_13
| V_14
| V_15 ,
V_36 ,
0 ,
NULL ,
0 ,
2000 ) ;
if ( V_35 < 0 )
return 0 ;
return V_34 ;
}
static void F_19 ( struct V_29 * V_30 , int V_37 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_38 ;
int V_11 ;
if ( V_37 == - 1 )
V_38 = 1 ;
else
V_38 = 0 ;
V_11 = F_5 ( V_10 -> V_12 , F_6 ( V_10 -> V_12 , 0 ) ,
4 ,
V_13 | V_14 | V_15 ,
V_38 , 0 , NULL , 0 , 2000 ) ;
if ( V_11 < 0 )
F_7 ( & V_7 -> V_12 , L_1 ,
V_16 , V_11 ) ;
}
static void F_20 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_39 * V_40 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
T_1 V_41 ;
V_41 = F_21 ( V_30 ) ;
V_41 = F_18 ( V_10 , V_41 ) ;
if ( V_41 == 0 ) {
F_7 ( & V_7 -> V_12 , L_7 ) ;
V_41 = F_22 ( V_40 ) ;
}
F_23 ( & V_30 -> V_42 , V_40 ) ;
F_24 ( V_30 , V_41 , V_41 ) ;
}
static int F_25 ( struct V_9 * V_10 ,
unsigned char * V_38 )
{
int V_35 ;
T_2 * V_19 ;
V_19 = F_26 ( 1 , V_33 ) ;
if ( ! V_19 )
return - V_43 ;
V_35 = F_5 ( V_10 -> V_12 , F_27 ( V_10 -> V_12 , 0 ) ,
3 ,
V_13 | V_14 | V_44 ,
0 , 0 , V_19 , 1 , 2000 ) ;
if ( V_35 >= 0 )
* V_38 = * V_19 ;
F_28 ( V_19 ) ;
return V_35 ;
}
static int F_29 ( struct V_9 * V_10 ,
unsigned char V_38 )
{
int V_35 ;
V_35 = F_5 ( V_10 -> V_12 , F_6 ( V_10 -> V_12 , 0 ) ,
3 ,
V_13 | V_14 | V_15 ,
V_38 , 0 , NULL , 0 , 2000 ) ;
return V_35 ;
}
static int F_30 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_35 ;
unsigned char V_22 ;
int V_38 ;
V_35 = F_25 ( V_10 , & V_22 ) ;
if ( V_35 < 0 )
return V_35 ;
V_38 =
( ( V_22 & ( 1 << 7 ) ) ? V_45 : 0 ) |
( ( V_22 & ( 1 << 6 ) ) ? V_46 : 0 ) |
( ( V_22 & ( 1 << 5 ) ) ? V_47 : 0 ) |
( ( V_22 & ( 1 << 4 ) ) ? V_48 : 0 ) |
( ( V_22 & ( 1 << 3 ) ) ? V_49 : 0 ) |
( ( V_22 & ( 1 << 2 ) ) ? V_50 : 0 ) ;
return V_38 ;
}
static int F_31 ( struct V_29 * V_30 ,
unsigned int V_51 , unsigned int V_52 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_35 ;
unsigned char V_22 ;
V_35 = F_25 ( V_10 , & V_22 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_51 & V_50 )
V_22 |= ( 1 << 2 ) ;
if ( V_51 & V_45 )
V_22 |= ( 1 << 7 ) ;
if ( V_52 & V_50 )
V_22 &= ~ ( 1 << 2 ) ;
if ( V_52 & V_45 )
V_22 &= ~ ( 1 << 7 ) ;
V_35 = F_29 ( V_10 , V_22 ) ;
return V_35 ;
}
static int F_32 ( struct V_29 * V_30 ,
struct V_6 * V_7 , const unsigned char * V_53 , int V_54 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
int V_55 = 0 ;
int V_35 = 0 ;
struct V_3 * V_4 ;
V_4 = F_9 ( V_7 ) ;
if ( V_54 == 0 ) {
F_7 ( & V_7 -> V_12 , L_8 ) ;
return 0 ;
}
F_33 ( & V_7 -> V_56 ) ;
if ( ! F_34 ( 0 , & V_7 -> V_57 ) || V_4 -> V_27 ) {
F_35 ( & V_7 -> V_56 ) ;
return 0 ;
}
F_36 ( 0 , & V_7 -> V_57 ) ;
F_35 ( & V_7 -> V_56 ) ;
V_54 = ( V_54 > V_7 -> V_58 ) ? V_7 -> V_58 : V_54 ;
if ( V_54 > V_4 -> V_59 && ! F_37 () ) {
T_2 * V_60 ;
V_60 = F_26 ( 1 , V_33 ) ;
if ( ! V_60 ) {
V_35 = - V_43 ;
goto exit;
}
V_35 = F_5 ( V_10 -> V_12 ,
F_27 ( V_10 -> V_12 , 0 ) ,
6 ,
V_13 | V_14
| V_44 ,
0 ,
0 ,
V_60 ,
1 ,
2000 ) ;
if ( V_35 > 0 ) {
F_7 ( & V_7 -> V_12 , L_9 , * V_60 ) ;
V_4 -> V_59 = * V_60 ;
}
F_28 ( V_60 ) ;
if ( V_35 < 0 ) {
F_7 ( & V_7 -> V_12 , L_10 ) ;
goto exit;
}
if ( V_35 == 0 ) {
F_7 ( & V_7 -> V_12 , L_11 ) ;
V_35 = - V_61 ;
goto exit;
}
}
if ( V_54 > V_4 -> V_59 ) {
V_54 = V_4 -> V_59 ;
V_55 = 1 ;
}
if ( V_54 ) {
memcpy ( V_7 -> V_62 -> V_20 , V_53 , V_54 ) ;
V_7 -> V_62 -> V_63 = V_54 ;
V_4 -> V_59 -= V_54 ;
V_35 = F_13 ( V_7 -> V_62 , V_28 ) ;
if ( V_35 ) {
F_7 ( & V_7 -> V_12 , L_12 ) ;
goto exit;
}
} else {
V_55 = 1 ;
}
if ( V_55 ) {
V_4 -> V_27 = 1 ;
F_12 ( & V_4 -> V_8 ) ;
}
V_35 = V_54 ;
exit:
if ( V_35 < 0 )
F_38 ( 0 , & V_7 -> V_57 ) ;
return V_35 ;
}
static void F_39 ( struct V_17 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_18 ;
struct V_3 * V_4 ;
F_38 ( 0 , & V_7 -> V_57 ) ;
V_4 = F_9 ( V_7 ) ;
F_12 ( & V_4 -> V_5 ) ;
}
static int F_40 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
struct V_3 * V_4 ;
V_4 = F_9 ( V_7 ) ;
return V_4 -> V_59 ;
}
static int F_41 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_31 ;
struct V_3 * V_4 ;
unsigned long V_64 ;
int V_65 = 0 ;
V_4 = F_9 ( V_7 ) ;
F_42 ( & V_7 -> V_56 , V_64 ) ;
if ( ! F_34 ( 0 , & V_7 -> V_57 ) || V_4 -> V_27 )
V_65 = 256 ;
F_43 ( & V_7 -> V_56 , V_64 ) ;
return V_65 ;
}
static void F_44 ( struct V_6 * V_7 , int V_66 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_66 )
F_29 ( V_10 , ( 1 << 7 ) | ( 1 << 2 ) ) ;
else
F_29 ( V_10 , 0 ) ;
}
static int F_45 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
T_2 * V_60 ;
int V_35 = 0 ;
struct V_3 * V_4 ;
V_60 = F_26 ( 1 , V_33 ) ;
if ( ! V_60 )
return - V_43 ;
V_35 = F_5 ( V_10 -> V_12 , F_27 ( V_10 -> V_12 , 0 ) ,
6 ,
V_13 | V_14
| V_44 ,
0 ,
0 ,
V_60 ,
1 ,
2000 ) ;
if ( V_35 < 0 ) {
F_7 ( & V_7 -> V_12 , L_13 , V_16 ) ;
goto error;
}
if ( V_35 == 0 ) {
F_7 ( & V_7 -> V_12 , L_14 , V_16 ) ;
V_35 = - V_61 ;
goto error;
}
V_4 = F_9 ( V_7 ) ;
V_4 -> V_59 = * V_60 ;
V_4 -> V_27 = * V_60 ? 0 : 1 ;
V_35 = F_13 ( V_7 -> V_32 , V_33 ) ;
if ( V_35 ) {
F_7 ( & V_7 -> V_12 , L_15 , V_16 ) ;
goto error;
}
error:
F_28 ( V_60 ) ;
return V_35 ;
}
static void F_46 ( struct V_6 * V_7 )
{
F_16 ( V_7 -> V_62 ) ;
F_16 ( V_7 -> V_32 ) ;
}
static int F_47 ( struct V_9 * V_10 )
{
int V_67 ;
const char * V_68 ;
V_67 = F_48 ( V_10 -> V_12 , 1 ) ;
if ( 0 ) { ; }
#ifdef F_49
else if ( F_50 ( V_10 -> V_12 -> V_69 . V_70 ) == V_71 )
V_68 = L_16 ;
#endif
#ifdef F_51
else if ( ( F_50 ( V_10 -> V_12 -> V_69 . V_70 ) == V_72 ) ||
( F_50 ( V_10 -> V_12 -> V_69 . V_70 ) == V_73 ) )
V_68 = L_17 ;
#endif
else {
F_14 ( & V_10 -> V_12 -> V_12 , L_18 ,
V_16 ) ;
return - V_74 ;
}
if ( F_52 ( V_10 -> V_12 , V_68 ) < 0 ) {
F_14 ( & V_10 -> V_12 -> V_12 , L_19 ,
V_68 ) ;
return - V_24 ;
}
return 1 ;
}
static int F_53 ( struct V_9 * V_10 )
{
unsigned char V_75 = V_10 -> V_75 ;
if ( V_10 -> V_76 < V_75 ||
V_10 -> V_77 < V_75 ) {
F_14 ( & V_10 -> V_78 -> V_12 , L_20 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_54 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_33 ) ;
if ( ! V_4 )
return - V_43 ;
F_55 ( & V_4 -> V_5 , F_1 ) ;
F_55 ( & V_4 -> V_8 , F_4 ) ;
V_4 -> V_10 = V_7 -> V_10 ;
V_4 -> V_7 = V_7 ;
F_56 ( V_7 , V_4 ) ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_9 ( V_7 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
