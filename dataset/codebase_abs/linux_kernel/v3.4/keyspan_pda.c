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
F_7 ( L_1 ) ;
V_13 = F_8 ( V_12 -> V_14 ,
F_9 ( V_12 -> V_14 , 0 ) ,
7 ,
V_15 | V_16
| V_17 ,
16 ,
0 ,
NULL ,
0 ,
2000 ) ;
if ( V_13 < 0 )
F_7 ( L_2 ,
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
F_7 ( L_3 ,
V_18 , V_24 ) ;
return;
default:
F_7 ( L_4 ,
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
F_7 ( L_5 , V_21 [ 1 ] , V_21 [ 2 ] ) ;
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
L_6 ,
V_18 , V_23 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
F_7 ( L_7 , V_7 -> V_32 ) ;
F_18 ( V_7 -> V_33 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
F_7 ( L_8 , V_7 -> V_32 ) ;
if ( F_15 ( V_7 -> V_33 , V_34 ) )
F_7 ( L_9 ) ;
}
static T_1 F_20 ( struct V_11 * V_12 , T_1 V_35 )
{
int V_36 ;
int V_37 ;
switch ( V_35 ) {
case 110 :
V_37 = 0 ;
break;
case 300 :
V_37 = 1 ;
break;
case 1200 :
V_37 = 2 ;
break;
case 2400 :
V_37 = 3 ;
break;
case 4800 :
V_37 = 4 ;
break;
case 9600 :
V_37 = 5 ;
break;
case 19200 :
V_37 = 6 ;
break;
case 38400 :
V_37 = 7 ;
break;
case 57600 :
V_37 = 8 ;
break;
case 115200 :
V_37 = 9 ;
break;
default:
V_37 = 5 ;
V_35 = 9600 ;
}
V_36 = F_8 ( V_12 -> V_14 , F_9 ( V_12 -> V_14 , 0 ) ,
0 ,
V_15
| V_16
| V_17 ,
V_37 ,
0 ,
NULL ,
0 ,
2000 ) ;
if ( V_36 < 0 )
return 0 ;
return V_35 ;
}
static void F_21 ( struct V_8 * V_9 , int V_38 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_11 * V_12 = V_7 -> V_12 ;
int V_39 ;
int V_13 ;
if ( V_38 == - 1 )
V_39 = 1 ;
else
V_39 = 0 ;
V_13 = F_8 ( V_12 -> V_14 , F_9 ( V_12 -> V_14 , 0 ) ,
4 ,
V_15 | V_16 | V_17 ,
V_39 , 0 , NULL , 0 , 2000 ) ;
if ( V_13 < 0 )
F_7 ( L_2 ,
V_18 , V_13 ) ;
}
static void F_22 ( struct V_8 * V_9 ,
struct V_6 * V_7 , struct V_40 * V_41 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_1 V_42 ;
V_42 = F_23 ( V_9 ) ;
V_42 = F_20 ( V_12 , V_42 ) ;
if ( V_42 == 0 ) {
F_7 ( L_10 ) ;
V_42 = F_24 ( V_41 ) ;
}
F_25 ( V_9 -> V_43 , V_41 ) ;
F_26 ( V_9 , V_42 , V_42 ) ;
}
static int F_27 ( struct V_11 * V_12 ,
unsigned char * V_39 )
{
int V_36 ;
T_2 * V_21 ;
V_21 = F_28 ( 1 , V_34 ) ;
if ( ! V_21 )
return - V_44 ;
V_36 = F_8 ( V_12 -> V_14 , F_29 ( V_12 -> V_14 , 0 ) ,
3 ,
V_15 | V_16 | V_45 ,
0 , 0 , V_21 , 1 , 2000 ) ;
if ( V_36 >= 0 )
* V_39 = * V_21 ;
F_30 ( V_21 ) ;
return V_36 ;
}
static int F_31 ( struct V_11 * V_12 ,
unsigned char V_39 )
{
int V_36 ;
V_36 = F_8 ( V_12 -> V_14 , F_9 ( V_12 -> V_14 , 0 ) ,
3 ,
V_15 | V_16 | V_17 ,
V_39 , 0 , NULL , 0 , 2000 ) ;
return V_36 ;
}
static int F_32 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_11 * V_12 = V_7 -> V_12 ;
int V_36 ;
unsigned char V_24 ;
int V_39 ;
V_36 = F_27 ( V_12 , & V_24 ) ;
if ( V_36 < 0 )
return V_36 ;
V_39 =
( ( V_24 & ( 1 << 7 ) ) ? V_46 : 0 ) |
( ( V_24 & ( 1 << 6 ) ) ? V_47 : 0 ) |
( ( V_24 & ( 1 << 5 ) ) ? V_48 : 0 ) |
( ( V_24 & ( 1 << 4 ) ) ? V_49 : 0 ) |
( ( V_24 & ( 1 << 3 ) ) ? V_50 : 0 ) |
( ( V_24 & ( 1 << 2 ) ) ? V_51 : 0 ) ;
return V_39 ;
}
static int F_33 ( struct V_8 * V_9 ,
unsigned int V_52 , unsigned int V_53 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_11 * V_12 = V_7 -> V_12 ;
int V_36 ;
unsigned char V_24 ;
V_36 = F_27 ( V_12 , & V_24 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_52 & V_51 )
V_24 |= ( 1 << 2 ) ;
if ( V_52 & V_46 )
V_24 |= ( 1 << 7 ) ;
if ( V_53 & V_51 )
V_24 &= ~ ( 1 << 2 ) ;
if ( V_53 & V_46 )
V_24 &= ~ ( 1 << 7 ) ;
V_36 = F_31 ( V_12 , V_24 ) ;
return V_36 ;
}
static int F_34 ( struct V_8 * V_9 ,
struct V_6 * V_7 , const unsigned char * V_54 , int V_55 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
int V_56 = 0 ;
int V_36 = 0 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_7 ) ;
F_7 ( L_11 , V_55 ) ;
if ( V_55 == 0 ) {
F_7 ( L_12 ) ;
return 0 ;
}
F_35 ( & V_7 -> V_57 ) ;
if ( ! F_36 ( 0 , & V_7 -> V_58 ) || V_4 -> V_29 ) {
F_37 ( & V_7 -> V_57 ) ;
return 0 ;
}
F_38 ( 0 , & V_7 -> V_58 ) ;
F_37 ( & V_7 -> V_57 ) ;
V_55 = ( V_55 > V_7 -> V_59 ) ? V_7 -> V_59 : V_55 ;
if ( V_55 > V_4 -> V_60 && ! F_39 () ) {
T_2 * V_61 ;
V_61 = F_28 ( 1 , V_34 ) ;
if ( ! V_61 ) {
V_36 = - V_44 ;
goto exit;
}
V_36 = F_8 ( V_12 -> V_14 ,
F_29 ( V_12 -> V_14 , 0 ) ,
6 ,
V_15 | V_16
| V_45 ,
0 ,
0 ,
V_61 ,
1 ,
2000 ) ;
if ( V_36 > 0 ) {
F_7 ( L_13 , * V_61 ) ;
V_4 -> V_60 = * V_61 ;
}
F_30 ( V_61 ) ;
if ( V_36 < 0 ) {
F_7 ( L_14 ) ;
goto exit;
}
if ( V_36 == 0 ) {
F_7 ( L_15 ) ;
V_36 = - V_62 ;
goto exit;
}
}
if ( V_55 > V_4 -> V_60 ) {
V_55 = V_4 -> V_60 ;
V_56 = 1 ;
}
if ( V_55 ) {
memcpy ( V_7 -> V_63 -> V_22 , V_54 , V_55 ) ;
V_7 -> V_63 -> V_64 = V_55 ;
V_4 -> V_60 -= V_55 ;
V_36 = F_15 ( V_7 -> V_63 , V_30 ) ;
if ( V_36 ) {
F_7 ( L_16 ) ;
goto exit;
}
} else {
V_56 = 1 ;
}
if ( V_56 ) {
V_4 -> V_29 = 1 ;
F_14 ( & V_4 -> V_10 ) ;
}
V_36 = V_55 ;
exit:
if ( V_36 < 0 )
F_40 ( 0 , & V_7 -> V_58 ) ;
return V_36 ;
}
static void F_41 ( struct V_19 * V_19 )
{
struct V_6 * V_7 = V_19 -> V_20 ;
struct V_3 * V_4 ;
F_40 ( 0 , & V_7 -> V_58 ) ;
V_4 = F_11 ( V_7 ) ;
F_14 ( & V_4 -> V_5 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_7 ) ;
return V_4 -> V_60 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_31 ;
struct V_3 * V_4 ;
unsigned long V_65 ;
int V_66 = 0 ;
V_4 = F_11 ( V_7 ) ;
F_44 ( & V_7 -> V_57 , V_65 ) ;
if ( ! F_36 ( 0 , & V_7 -> V_58 ) || V_4 -> V_29 )
V_66 = 256 ;
F_45 ( & V_7 -> V_57 , V_65 ) ;
return V_66 ;
}
static void F_46 ( struct V_6 * V_7 , int V_67 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
if ( V_12 -> V_14 ) {
if ( V_67 )
F_31 ( V_12 , ( 1 << 7 ) | ( 1 << 2 ) ) ;
else
F_31 ( V_12 , 0 ) ;
}
}
static int F_47 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
T_2 * V_61 ;
int V_36 = 0 ;
struct V_3 * V_4 ;
V_61 = F_28 ( 1 , V_34 ) ;
if ( ! V_61 )
return - V_44 ;
V_36 = F_8 ( V_12 -> V_14 , F_29 ( V_12 -> V_14 , 0 ) ,
6 ,
V_15 | V_16
| V_45 ,
0 ,
0 ,
V_61 ,
1 ,
2000 ) ;
if ( V_36 < 0 ) {
F_7 ( L_17 , V_18 ) ;
goto error;
}
if ( V_36 == 0 ) {
F_7 ( L_18 , V_18 ) ;
V_36 = - V_62 ;
goto error;
}
V_4 = F_11 ( V_7 ) ;
V_4 -> V_60 = * V_61 ;
V_4 -> V_29 = * V_61 ? 0 : 1 ;
V_36 = F_15 ( V_7 -> V_33 , V_34 ) ;
if ( V_36 ) {
F_7 ( L_19 , V_18 ) ;
goto error;
}
error:
F_30 ( V_61 ) ;
return V_36 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
if ( V_12 -> V_14 ) {
F_18 ( V_7 -> V_63 ) ;
F_18 ( V_7 -> V_33 ) ;
}
}
static int F_49 ( struct V_11 * V_12 )
{
int V_68 ;
const char * V_69 ;
const struct V_70 * V_71 ;
const struct V_72 * V_73 ;
V_68 = F_50 ( V_12 , 1 ) ;
if ( 0 ) { ; }
#ifdef F_51
else if ( F_52 ( V_12 -> V_14 -> V_74 . V_75 ) == V_76 )
V_69 = L_20 ;
#endif
#ifdef F_53
else if ( ( F_52 ( V_12 -> V_14 -> V_74 . V_75 ) == V_77 ) ||
( F_52 ( V_12 -> V_14 -> V_74 . V_75 ) == V_78 ) )
V_69 = L_21 ;
#endif
else {
F_16 ( & V_12 -> V_14 -> V_14 , L_22 ,
V_18 ) ;
return - V_79 ;
}
if ( F_54 ( & V_73 , V_69 , & V_12 -> V_14 -> V_14 ) ) {
F_16 ( & V_12 -> V_14 -> V_14 , L_23 ,
V_69 ) ;
return - V_26 ;
}
V_71 = ( const struct V_70 * ) V_73 -> V_21 ;
while ( V_71 ) {
V_68 = F_55 ( V_12 , F_56 ( V_71 -> V_80 ) ,
( unsigned char * ) V_71 -> V_21 ,
F_57 ( V_71 -> V_81 ) , 0xa0 ) ;
if ( V_68 < 0 ) {
F_16 ( & V_12 -> V_14 -> V_14 , L_24
L_25 ,
V_68 , F_56 ( V_71 -> V_80 ) ,
V_71 -> V_21 , F_57 ( V_71 -> V_81 ) ) ;
break;
}
V_71 = F_58 ( V_71 ) ;
}
F_59 ( V_73 ) ;
V_68 = F_50 ( V_12 , 0 ) ;
return 1 ;
}
static int F_60 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
V_4 = F_28 ( sizeof( struct V_3 ) , V_34 ) ;
if ( ! V_4 )
return 1 ;
F_61 ( V_12 -> V_7 [ 0 ] , V_4 ) ;
F_62 ( & V_12 -> V_7 [ 0 ] -> V_82 ) ;
F_63 ( & V_4 -> V_5 , F_1 ) ;
F_63 ( & V_4 -> V_10 , F_6 ) ;
V_4 -> V_12 = V_12 ;
V_4 -> V_7 = V_12 -> V_7 [ 0 ] ;
return 0 ;
}
static void F_64 ( struct V_11 * V_12 )
{
F_7 ( L_26 , V_18 ) ;
F_30 ( F_11 ( V_12 -> V_7 [ 0 ] ) ) ;
}
