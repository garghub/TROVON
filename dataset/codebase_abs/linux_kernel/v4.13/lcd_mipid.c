static void F_1 ( struct V_1 * V_2 , int V_3 , const T_1 * V_4 ,
int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 V_9 ;
struct V_10 * V_11 , V_12 [ 4 ] ;
T_2 V_13 ;
int V_14 ;
F_2 ( V_2 -> V_15 == NULL ) ;
F_3 ( & V_9 ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_11 = & V_12 [ 0 ] ;
V_3 &= 0xff ;
V_11 -> V_16 = & V_3 ;
V_11 -> V_17 = 9 ;
V_11 -> V_18 = 2 ;
F_4 ( V_11 , & V_9 ) ;
if ( V_5 ) {
V_11 ++ ;
V_11 -> V_16 = V_4 ;
V_11 -> V_18 = V_5 ;
V_11 -> V_17 = 9 ;
F_4 ( V_11 , & V_9 ) ;
}
if ( V_7 ) {
V_11 ++ ;
V_11 -> V_19 = & V_13 ;
V_11 -> V_18 = 1 ;
F_4 ( V_11 , & V_9 ) ;
if ( V_7 > 1 ) {
V_11 -> V_17 = 9 ;
V_11 -> V_18 = 2 ;
V_11 ++ ;
V_11 -> V_19 = & V_6 [ 1 ] ;
V_11 -> V_18 = V_7 - 1 ;
F_4 ( V_11 , & V_9 ) ;
}
}
V_14 = F_5 ( V_2 -> V_15 , & V_9 ) ;
if ( V_14 < 0 )
F_6 ( & V_2 -> V_15 -> V_20 , L_1 , V_14 ) ;
if ( V_7 )
V_6 [ 0 ] = V_13 & 0xff ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , NULL , 0 , NULL , 0 ) ;
}
static inline void F_8 ( struct V_1 * V_2 ,
int V_21 , const T_1 * V_22 , int V_18 )
{
F_1 ( V_2 , V_21 , V_22 , V_18 , NULL , 0 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
int V_21 , T_1 * V_22 , int V_18 )
{
F_1 ( V_2 , V_21 , NULL , 0 , V_22 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_23 )
{
T_2 V_24 ;
switch ( V_23 ) {
case 16 :
V_24 = 0x150 ;
break;
case 18 :
V_24 = 0x160 ;
break;
case 24 :
V_24 = 0x170 ;
break;
}
F_8 ( V_2 , 0x3a , ( T_1 * ) & V_24 , 2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_2 V_25 [] = { 0x0102 , 0x0100 , 0x0100 } ;
F_8 ( V_2 , 0xc2 , ( T_1 * ) V_25 , sizeof( V_25 ) ) ;
F_10 ( V_2 , V_2 -> V_26 . V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_27 )
{
V_2 -> V_28 = F_13 ( V_27 ) ;
V_2 -> V_29 = V_30 + V_2 -> V_28 ;
}
static void V_28 ( struct V_1 * V_2 )
{
unsigned long V_31 = V_2 -> V_29 - V_30 ;
if ( ( long ) V_31 > 0 && F_14 ( V_31 , V_2 -> V_28 ) ) {
F_15 ( V_32 ) ;
F_16 ( V_31 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , int V_33 )
{
int V_3 , V_34 = 50 ;
if ( V_33 )
V_3 = V_35 ;
else
V_3 = V_36 ;
V_28 ( V_2 ) ;
F_7 ( V_2 , V_3 ) ;
F_12 ( V_2 , 120 ) ;
if ( ! V_33 )
V_34 = 120 ;
F_18 ( V_34 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_37 )
{
int V_3 = V_37 ? V_38 : V_39 ;
F_7 ( V_2 , V_3 ) ;
}
static int F_20 ( struct V_40 * V_26 , unsigned int V_41 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
struct V_42 * V_43 = V_2 -> V_15 -> V_20 . V_44 ;
if ( V_43 -> V_45 == NULL || V_43 -> V_46 == NULL )
return - V_47 ;
if ( V_41 > V_43 -> V_45 ( V_43 ) )
return - V_48 ;
if ( ! V_2 -> V_37 ) {
V_2 -> V_49 = V_41 ;
return 0 ;
}
V_43 -> V_46 ( V_43 , V_41 ) ;
return 0 ;
}
static unsigned int F_22 ( struct V_40 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
struct V_42 * V_43 = V_2 -> V_15 -> V_20 . V_44 ;
if ( V_43 -> V_50 == NULL )
return - V_47 ;
return V_43 -> V_50 ( V_43 ) ;
}
static unsigned int F_23 ( struct V_40 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
struct V_42 * V_43 = V_2 -> V_15 -> V_20 . V_44 ;
if ( V_43 -> V_45 == NULL )
return - V_47 ;
return V_43 -> V_45 ( V_43 ) ;
}
static unsigned long F_24 ( struct V_40 * V_26 )
{
return V_51 ;
}
static T_2 F_25 ( struct V_1 * V_2 )
{
T_2 V_52 ;
T_1 V_53 , V_54 , V_55 ;
F_26 ( & V_2 -> V_56 ) ;
F_9 ( V_2 , V_57 , & V_53 , 1 ) ;
F_9 ( V_2 , V_58 , & V_54 , 1 ) ;
F_9 ( V_2 , V_59 , & V_55 , 1 ) ;
F_27 ( & V_2 -> V_56 ) ;
switch ( V_2 -> V_26 . V_23 ) {
case 16 :
V_52 = ( ( V_53 >> 1 ) << 11 ) | ( V_54 << 5 ) | ( V_55 >> 1 ) ;
break;
case 24 :
V_52 = ( ( V_53 >> 3 ) << 11 ) | ( ( V_54 >> 2 ) << 5 ) |
( V_55 >> 3 ) ;
break;
default:
V_52 = 0 ;
F_28 () ;
}
return V_52 ;
}
static int F_29 ( struct V_40 * V_26 , int V_60 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
static const T_2 V_61 [ 4 ] = {
0x0000 , 0xffff , 0xaaaa , 0x5555 ,
} ;
int V_62 ;
if ( V_60 != V_63 )
return V_64 ;
for ( V_62 = 0 ; V_62 < F_30 ( V_61 ) ; V_62 ++ ) {
int V_65 ;
unsigned long V_66 ;
F_31 ( V_2 -> V_67 , V_61 [ V_62 ] ) ;
V_66 = V_30 + F_13 ( 100 ) ;
V_65 = 25 ;
while ( 1 ) {
T_2 V_52 ;
F_18 ( V_65 ) ;
V_52 = F_25 ( V_2 ) ;
if ( V_52 == V_61 [ V_62 ] )
break;
if ( F_32 ( V_30 , V_66 ) ) {
F_33 ( & V_2 -> V_15 -> V_20 ,
L_2
L_3 ,
V_61 [ V_62 ] , V_52 ) ;
return V_68 ;
}
V_65 = 10 ;
}
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_15 -> V_20 , L_4 ) ;
F_17 ( V_2 , 1 ) ;
F_17 ( V_2 , 0 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_69 , V_70 ;
F_9 ( V_2 , V_71 , & V_69 , 1 ) ;
F_17 ( V_2 , 0 ) ;
F_9 ( V_2 , V_71 , & V_70 , 1 ) ;
F_6 ( & V_2 -> V_15 -> V_20 , L_5 ,
V_69 , V_70 ) ;
if ( ! ( ( V_69 ^ V_70 ) & ( 1 << 6 ) ) )
F_34 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_62 ;
T_1 V_6 [ 2 ] ;
static const struct {
int V_3 ;
int V_5 ;
T_2 V_4 [ 3 ] ;
} * V_72 , V_73 [ 7 ] = {
{ 0xb0 , 4 , { 0x0101 , 0x01fe , } } ,
{ 0xb1 , 4 , { 0x01de , 0x0121 , } } ,
{ 0xc2 , 4 , { 0x0100 , 0x0100 , } } ,
{ 0xbd , 2 , { 0x0100 , } } ,
{ 0xc2 , 4 , { 0x01fc , 0x0103 , } } ,
{ 0xb4 , 0 , } ,
{ 0x00 , 0 , } ,
} ;
V_72 = V_73 ;
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ , V_72 ++ )
F_8 ( V_2 , V_72 -> V_3 , ( T_1 * ) V_72 -> V_4 , V_72 -> V_5 ) ;
F_37 ( 10 ) ;
F_9 ( V_2 , V_72 -> V_3 , V_6 , 2 ) ;
V_72 ++ ;
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ , V_72 ++ ) {
F_37 ( 10 ) ;
F_8 ( V_2 , V_72 -> V_3 , ( T_1 * ) V_72 -> V_4 , V_72 -> V_5 ) ;
}
F_6 ( & V_2 -> V_15 -> V_20 , L_6 , V_6 [ 1 ] ) ;
if ( V_6 [ 1 ] == 0x00 )
F_34 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
if ( V_2 -> V_74 >= 0x88 )
F_36 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 != NULL )
F_40 ( & V_2 -> V_76 ,
V_77 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 != NULL )
F_42 ( & V_2 -> V_76 ) ;
}
static void F_43 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_44 ( V_79 , struct V_1 ,
V_76 . V_79 ) ;
F_26 ( & V_2 -> V_56 ) ;
V_2 -> V_75 ( V_2 ) ;
F_27 ( & V_2 -> V_56 ) ;
F_39 ( V_2 ) ;
}
static int F_45 ( struct V_40 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
F_26 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_37 ) {
F_27 ( & V_2 -> V_56 ) ;
return 0 ;
}
F_17 ( V_2 , 0 ) ;
V_2 -> V_37 = 1 ;
F_11 ( V_2 ) ;
F_19 ( V_2 , 1 ) ;
F_20 ( V_26 , V_2 -> V_49 ) ;
F_39 ( V_2 ) ;
F_27 ( & V_2 -> V_56 ) ;
return 0 ;
}
static void F_46 ( struct V_40 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
F_41 ( V_2 ) ;
F_26 ( & V_2 -> V_56 ) ;
if ( ! V_2 -> V_37 ) {
F_27 ( & V_2 -> V_56 ) ;
return;
}
V_2 -> V_49 = F_22 ( V_26 ) ;
F_20 ( V_26 , 0 ) ;
F_19 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
V_2 -> V_37 = 0 ;
F_27 ( & V_2 -> V_56 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
T_3 V_80 ;
int V_37 ;
F_9 ( V_2 , V_81 , ( T_1 * ) & V_80 , 4 ) ;
V_80 = F_48 ( V_80 ) ;
V_37 = ( V_80 & ( 1 << 17 ) ) && ( V_80 & ( 1 << 10 ) ) ;
F_6 ( & V_2 -> V_15 -> V_20 ,
L_7 ,
V_37 ? L_8 : L_9 , V_80 ) ;
return V_37 ;
}
static int F_49 ( struct V_40 * V_26 ,
struct V_82 * V_67 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
V_2 -> V_67 = V_67 ;
F_50 ( & V_2 -> V_76 , F_43 ) ;
F_51 ( & V_2 -> V_56 ) ;
V_2 -> V_37 = F_47 ( V_2 ) ;
if ( V_2 -> V_37 )
F_39 ( V_2 ) ;
else
V_2 -> V_49 = F_22 ( V_26 ) ;
return 0 ;
}
static void F_52 ( struct V_40 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
if ( V_2 -> V_37 )
F_41 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_42 * V_83 ;
T_1 V_84 [ 3 ] ;
V_83 = V_2 -> V_15 -> V_20 . V_44 ;
if ( V_83 == NULL ) {
F_33 ( & V_2 -> V_15 -> V_20 , L_10 ) ;
return - V_85 ;
}
F_9 ( V_2 , V_86 , V_84 , 3 ) ;
F_6 ( & V_2 -> V_15 -> V_20 , L_11 ,
V_84 [ 0 ] , V_84 [ 1 ] , V_84 [ 2 ] ) ;
switch ( V_84 [ 0 ] ) {
case 0x45 :
V_2 -> V_26 . V_87 = L_12 ;
break;
case 0x83 :
V_2 -> V_26 . V_87 = L_13 ;
V_2 -> V_75 = F_38 ;
break;
default:
V_2 -> V_26 . V_87 = L_14 ;
F_33 ( & V_2 -> V_15 -> V_20 , L_15 ) ;
return - V_47 ;
}
V_2 -> V_74 = V_84 [ 1 ] ;
V_2 -> V_26 . V_23 = V_83 -> V_23 ;
F_54 ( L_16 ,
V_2 -> V_26 . V_87 , V_2 -> V_74 , V_2 -> V_26 . V_23 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_15 )
{
struct V_1 * V_2 ;
int V_14 ;
V_2 = F_56 ( sizeof( * V_2 ) , V_89 ) ;
if ( V_2 == NULL ) {
F_33 ( & V_15 -> V_20 , L_17 ) ;
return - V_90 ;
}
V_15 -> V_91 = V_92 ;
V_2 -> V_15 = V_15 ;
F_57 ( & V_15 -> V_20 , V_2 ) ;
V_2 -> V_26 = V_93 ;
V_14 = F_53 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
F_58 ( & V_2 -> V_26 ) ;
return 0 ;
}
static int F_59 ( struct V_88 * V_15 )
{
struct V_1 * V_2 = F_60 ( & V_15 -> V_20 ) ;
F_46 ( & V_2 -> V_26 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
