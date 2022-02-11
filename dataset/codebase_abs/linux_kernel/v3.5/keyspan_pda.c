static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_3 ( & V_7 -> V_7 ) ;
if ( V_9 )
F_4 ( V_9 ) ;
F_5 ( V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_10 ) ;
struct V_11 * V_12 = V_4 -> V_12 ;
int V_13 ;
V_13 = F_7 ( V_12 -> V_14 ,
F_8 ( V_12 -> V_14 , 0 ) ,
7 ,
V_15 | V_16
| V_17 ,
16 ,
0 ,
NULL ,
0 ,
2000 ) ;
if ( V_13 < 0 )
F_9 ( L_1 ,
V_18 , V_13 ) ;
}
static void F_10 ( struct V_19 * V_19 )
{
struct V_6 * V_7 = V_19 -> V_20 ;
struct V_8 * V_9 ;
unsigned char * V_21 = V_19 -> V_22 ;
int V_23 ;
int V_24 = V_19 -> V_24 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_7 ) ;
switch ( V_24 ) {
case 0 :
break;
case - V_25 :
case - V_26 :
case - V_27 :
F_9 ( L_2 ,
V_18 , V_24 ) ;
return;
default:
F_9 ( L_3 ,
V_18 , V_24 ) ;
goto exit;
}
switch ( V_21 [ 0 ] ) {
case 0 :
V_9 = F_3 ( & V_7 -> V_7 ) ;
if ( V_9 && V_19 -> V_28 ) {
F_12 ( V_9 , V_21 + 1 ,
V_19 -> V_28 - 1 ) ;
F_13 ( V_9 ) ;
}
F_5 ( V_9 ) ;
break;
case 1 :
F_9 ( L_4 , V_21 [ 1 ] , V_21 [ 2 ] ) ;
switch ( V_21 [ 1 ] ) {
case 1 :
break;
case 2 :
V_4 -> V_29 = 0 ;
F_14 ( & V_4 -> V_5 ) ;
break;
default:
break;
}
break;
default:
break;
}
exit:
V_23 = F_15 ( V_19 , V_30 ) ;
if ( V_23 )
F_16 ( & V_7 -> V_14 ,
L_5 ,
V_18 , V_23 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
F_18 ( V_7 -> V_32 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
if ( F_15 ( V_7 -> V_32 , V_33 ) )
F_9 ( L_6 ) ;
}
static T_1 F_20 ( struct V_11 * V_12 , T_1 V_34 )
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
V_35 = F_7 ( V_12 -> V_14 , F_8 ( V_12 -> V_14 , 0 ) ,
0 ,
V_15
| V_16
| V_17 ,
V_36 ,
0 ,
NULL ,
0 ,
2000 ) ;
if ( V_35 < 0 )
return 0 ;
return V_34 ;
}
static void F_21 ( struct V_8 * V_9 , int V_37 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_11 * V_12 = V_7 -> V_12 ;
int V_38 ;
int V_13 ;
if ( V_37 == - 1 )
V_38 = 1 ;
else
V_38 = 0 ;
V_13 = F_7 ( V_12 -> V_14 , F_8 ( V_12 -> V_14 , 0 ) ,
4 ,
V_15 | V_16 | V_17 ,
V_38 , 0 , NULL , 0 , 2000 ) ;
if ( V_13 < 0 )
F_9 ( L_1 ,
V_18 , V_13 ) ;
}
static void F_22 ( struct V_8 * V_9 ,
struct V_6 * V_7 , struct V_39 * V_40 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_1 V_41 ;
V_41 = F_23 ( V_9 ) ;
V_41 = F_20 ( V_12 , V_41 ) ;
if ( V_41 == 0 ) {
F_9 ( L_7 ) ;
V_41 = F_24 ( V_40 ) ;
}
F_25 ( V_9 -> V_42 , V_40 ) ;
F_26 ( V_9 , V_41 , V_41 ) ;
}
static int F_27 ( struct V_11 * V_12 ,
unsigned char * V_38 )
{
int V_35 ;
T_2 * V_21 ;
V_21 = F_28 ( 1 , V_33 ) ;
if ( ! V_21 )
return - V_43 ;
V_35 = F_7 ( V_12 -> V_14 , F_29 ( V_12 -> V_14 , 0 ) ,
3 ,
V_15 | V_16 | V_44 ,
0 , 0 , V_21 , 1 , 2000 ) ;
if ( V_35 >= 0 )
* V_38 = * V_21 ;
F_30 ( V_21 ) ;
return V_35 ;
}
static int F_31 ( struct V_11 * V_12 ,
unsigned char V_38 )
{
int V_35 ;
V_35 = F_7 ( V_12 -> V_14 , F_8 ( V_12 -> V_14 , 0 ) ,
3 ,
V_15 | V_16 | V_17 ,
V_38 , 0 , NULL , 0 , 2000 ) ;
return V_35 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_11 * V_12 = V_7 -> V_12 ;
int V_35 ;
unsigned char V_24 ;
int V_38 ;
V_35 = F_27 ( V_12 , & V_24 ) ;
if ( V_35 < 0 )
return V_35 ;
V_38 =
( ( V_24 & ( 1 << 7 ) ) ? V_45 : 0 ) |
( ( V_24 & ( 1 << 6 ) ) ? V_46 : 0 ) |
( ( V_24 & ( 1 << 5 ) ) ? V_47 : 0 ) |
( ( V_24 & ( 1 << 4 ) ) ? V_48 : 0 ) |
( ( V_24 & ( 1 << 3 ) ) ? V_49 : 0 ) |
( ( V_24 & ( 1 << 2 ) ) ? V_50 : 0 ) ;
return V_38 ;
}
static int F_33 ( struct V_8 * V_9 ,
unsigned int V_51 , unsigned int V_52 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_11 * V_12 = V_7 -> V_12 ;
int V_35 ;
unsigned char V_24 ;
V_35 = F_27 ( V_12 , & V_24 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_51 & V_50 )
V_24 |= ( 1 << 2 ) ;
if ( V_51 & V_45 )
V_24 |= ( 1 << 7 ) ;
if ( V_52 & V_50 )
V_24 &= ~ ( 1 << 2 ) ;
if ( V_52 & V_45 )
V_24 &= ~ ( 1 << 7 ) ;
V_35 = F_31 ( V_12 , V_24 ) ;
return V_35 ;
}
static int F_34 ( struct V_8 * V_9 ,
struct V_6 * V_7 , const unsigned char * V_53 , int V_54 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
int V_55 = 0 ;
int V_35 = 0 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_7 ) ;
if ( V_54 == 0 ) {
F_9 ( L_8 ) ;
return 0 ;
}
F_35 ( & V_7 -> V_56 ) ;
if ( ! F_36 ( 0 , & V_7 -> V_57 ) || V_4 -> V_29 ) {
F_37 ( & V_7 -> V_56 ) ;
return 0 ;
}
F_38 ( 0 , & V_7 -> V_57 ) ;
F_37 ( & V_7 -> V_56 ) ;
V_54 = ( V_54 > V_7 -> V_58 ) ? V_7 -> V_58 : V_54 ;
if ( V_54 > V_4 -> V_59 && ! F_39 () ) {
T_2 * V_60 ;
V_60 = F_28 ( 1 , V_33 ) ;
if ( ! V_60 ) {
V_35 = - V_43 ;
goto exit;
}
V_35 = F_7 ( V_12 -> V_14 ,
F_29 ( V_12 -> V_14 , 0 ) ,
6 ,
V_15 | V_16
| V_44 ,
0 ,
0 ,
V_60 ,
1 ,
2000 ) ;
if ( V_35 > 0 ) {
F_9 ( L_9 , * V_60 ) ;
V_4 -> V_59 = * V_60 ;
}
F_30 ( V_60 ) ;
if ( V_35 < 0 ) {
F_9 ( L_10 ) ;
goto exit;
}
if ( V_35 == 0 ) {
F_9 ( L_11 ) ;
V_35 = - V_61 ;
goto exit;
}
}
if ( V_54 > V_4 -> V_59 ) {
V_54 = V_4 -> V_59 ;
V_55 = 1 ;
}
if ( V_54 ) {
memcpy ( V_7 -> V_62 -> V_22 , V_53 , V_54 ) ;
V_7 -> V_62 -> V_63 = V_54 ;
V_4 -> V_59 -= V_54 ;
V_35 = F_15 ( V_7 -> V_62 , V_30 ) ;
if ( V_35 ) {
F_9 ( L_12 ) ;
goto exit;
}
} else {
V_55 = 1 ;
}
if ( V_55 ) {
V_4 -> V_29 = 1 ;
F_14 ( & V_4 -> V_10 ) ;
}
V_35 = V_54 ;
exit:
if ( V_35 < 0 )
F_40 ( 0 , & V_7 -> V_57 ) ;
return V_35 ;
}
static void F_41 ( struct V_19 * V_19 )
{
struct V_6 * V_7 = V_19 -> V_20 ;
struct V_3 * V_4 ;
F_40 ( 0 , & V_7 -> V_57 ) ;
V_4 = F_11 ( V_7 ) ;
F_14 ( & V_4 -> V_5 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_7 ) ;
return V_4 -> V_59 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_3 * V_4 ;
unsigned long V_64 ;
int V_65 = 0 ;
V_4 = F_11 ( V_7 ) ;
F_44 ( & V_7 -> V_56 , V_64 ) ;
if ( ! F_36 ( 0 , & V_7 -> V_57 ) || V_4 -> V_29 )
V_65 = 256 ;
F_45 ( & V_7 -> V_56 , V_64 ) ;
return V_65 ;
}
static void F_46 ( struct V_6 * V_7 , int V_66 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
if ( V_12 -> V_14 ) {
if ( V_66 )
F_31 ( V_12 , ( 1 << 7 ) | ( 1 << 2 ) ) ;
else
F_31 ( V_12 , 0 ) ;
}
}
static int F_47 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_2 * V_60 ;
int V_35 = 0 ;
struct V_3 * V_4 ;
V_60 = F_28 ( 1 , V_33 ) ;
if ( ! V_60 )
return - V_43 ;
V_35 = F_7 ( V_12 -> V_14 , F_29 ( V_12 -> V_14 , 0 ) ,
6 ,
V_15 | V_16
| V_44 ,
0 ,
0 ,
V_60 ,
1 ,
2000 ) ;
if ( V_35 < 0 ) {
F_9 ( L_13 , V_18 ) ;
goto error;
}
if ( V_35 == 0 ) {
F_9 ( L_14 , V_18 ) ;
V_35 = - V_61 ;
goto error;
}
V_4 = F_11 ( V_7 ) ;
V_4 -> V_59 = * V_60 ;
V_4 -> V_29 = * V_60 ? 0 : 1 ;
V_35 = F_15 ( V_7 -> V_32 , V_33 ) ;
if ( V_35 ) {
F_9 ( L_15 , V_18 ) ;
goto error;
}
error:
F_30 ( V_60 ) ;
return V_35 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
if ( V_12 -> V_14 ) {
F_18 ( V_7 -> V_62 ) ;
F_18 ( V_7 -> V_32 ) ;
}
}
static int F_49 ( struct V_11 * V_12 )
{
int V_67 ;
const char * V_68 ;
const struct V_69 * V_70 ;
const struct V_71 * V_72 ;
V_67 = F_50 ( V_12 , 1 ) ;
if ( 0 ) { ; }
#ifdef F_51
else if ( F_52 ( V_12 -> V_14 -> V_73 . V_74 ) == V_75 )
V_68 = L_16 ;
#endif
#ifdef F_53
else if ( ( F_52 ( V_12 -> V_14 -> V_73 . V_74 ) == V_76 ) ||
( F_52 ( V_12 -> V_14 -> V_73 . V_74 ) == V_77 ) )
V_68 = L_17 ;
#endif
else {
F_16 ( & V_12 -> V_14 -> V_14 , L_18 ,
V_18 ) ;
return - V_78 ;
}
if ( F_54 ( & V_72 , V_68 , & V_12 -> V_14 -> V_14 ) ) {
F_16 ( & V_12 -> V_14 -> V_14 , L_19 ,
V_68 ) ;
return - V_26 ;
}
V_70 = ( const struct V_69 * ) V_72 -> V_21 ;
while ( V_70 ) {
V_67 = F_55 ( V_12 , F_56 ( V_70 -> V_79 ) ,
( unsigned char * ) V_70 -> V_21 ,
F_57 ( V_70 -> V_80 ) , 0xa0 ) ;
if ( V_67 < 0 ) {
F_16 ( & V_12 -> V_14 -> V_14 , L_20
L_21 ,
V_67 , F_56 ( V_70 -> V_79 ) ,
V_70 -> V_21 , F_57 ( V_70 -> V_80 ) ) ;
break;
}
V_70 = F_58 ( V_70 ) ;
}
F_59 ( V_72 ) ;
V_67 = F_50 ( V_12 , 0 ) ;
return 1 ;
}
static int F_60 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( sizeof( struct V_3 ) , V_33 ) ;
if ( ! V_4 )
return 1 ;
F_61 ( V_12 -> V_7 [ 0 ] , V_4 ) ;
F_62 ( & V_12 -> V_7 [ 0 ] -> V_81 ) ;
F_63 ( & V_4 -> V_5 , F_1 ) ;
F_63 ( & V_4 -> V_10 , F_6 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_7 = V_12 -> V_7 [ 0 ] ;
return 0 ;
}
static void F_64 ( struct V_11 * V_12 )
{
F_30 ( F_11 ( V_12 -> V_7 [ 0 ] ) ) ;
}
