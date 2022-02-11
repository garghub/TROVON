static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 & 0x00ff , V_2 -> V_4 + V_5 ) ;
F_2 ( ( V_3 >> 8 ) & 0x00ff , V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 , int V_7 )
{
T_1 V_8 , V_9 , V_10 , V_11 ;
V_8 = 0 ;
V_9 = 0x0004 ;
V_10 = ( V_6 << 6 ) & 0x00c0 ;
switch ( V_6 / 4 ) {
case 0 :
V_11 = 0x0001 ;
break;
case 1 :
V_11 = 0x0002 ;
break;
case 2 :
V_11 = 0x0005 ;
break;
case 3 :
V_11 = 0x0006 ;
break;
case 4 :
V_11 = 0x0041 ;
break;
case 5 :
V_11 = 0x0042 ;
break;
default:
V_11 = 0 ;
break;
}
V_10 |= 0x0800 ;
V_11 |= 0xc000 ;
F_1 ( V_2 , V_8 ) ;
F_1 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_10 ) ;
F_1 ( V_2 , V_11 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_16 )
{
unsigned int V_17 ;
V_17 = F_5 ( V_2 -> V_4 + V_18 ) ;
if ( V_17 & V_16 )
return 0 ;
return - V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_20 )
{
int V_7 , V_6 ;
int V_21 ;
int V_22 ;
F_2 ( V_23 |
V_24 |
V_25 , V_2 -> V_4 + V_18 ) ;
F_7 ( 1000000 , V_2 -> V_4 + V_26 ) ;
F_2 ( 0 , V_2 -> V_4 + V_27 ) ;
V_7 = F_8 ( V_15 -> V_28 ) ;
V_6 = F_9 ( V_15 -> V_28 ) ;
for ( V_22 = 0 ; V_22 < V_15 -> V_29 ; V_22 ++ ) {
F_3 ( V_2 , V_6 , V_7 ) ;
F_2 ( V_30 , V_2 -> V_4 + V_18 ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_31 ) ;
if ( V_21 )
return V_21 ;
F_2 ( V_32 , V_2 -> V_4 + V_18 ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_33 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_34 ) ;
if ( V_21 )
return V_21 ;
V_20 [ V_22 ] = F_5 ( V_2 -> V_4 + V_35 ) ;
F_2 ( V_36 , V_2 -> V_4 + V_18 ) ;
F_2 ( V_37 , V_2 -> V_4 + V_18 ) ;
}
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_16 )
{
unsigned int V_6 = F_9 ( V_15 -> V_28 ) ;
unsigned int V_17 ;
V_17 = F_5 ( V_2 -> V_4 + V_38 ) ;
if ( ( V_17 & ( ( V_6 + 1 ) * 0x0010 ) ) == 0 )
return 0 ;
return - V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_20 )
{
unsigned int V_6 = F_9 ( V_15 -> V_28 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_15 -> V_29 ; V_22 ++ ) {
unsigned int V_39 = V_20 [ V_22 ] ;
int V_21 ;
F_2 ( V_39 , V_2 -> V_4 + F_13 ( V_6 ) ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_11 , 0 ) ;
if ( V_21 )
return V_21 ;
V_13 -> V_40 [ V_6 ] = V_39 ;
}
return V_15 -> V_29 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_43 ;
F_7 ( V_44 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
F_7 ( V_46 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_43 ;
F_7 ( V_47 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
F_7 ( V_48 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
F_7 ( V_47 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_43 ;
F_7 ( V_49 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
F_7 ( V_50 , V_42 -> V_45 + 0x6c ) ;
F_15 ( 10 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_51 )
{
int V_52 = 0 ;
int V_22 ;
int V_53 ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
V_53 = F_5 ( V_2 -> V_4 + 0x1000 ) ;
if ( ( V_53 & V_51 ) == V_51 ) {
V_52 = 1 ;
break;
}
F_19 ( 100 ) ;
}
F_19 ( 5 ) ;
return V_52 ;
}
static int F_20 ( struct V_1 * V_2 , int V_20 )
{
int V_52 = 0 ;
F_19 ( 10 ) ;
F_2 ( V_20 , V_2 -> V_4 + 0x1000 ) ;
if ( ( F_5 ( V_2 -> V_4 + 0x1000 ) & V_54 ) ==
V_54 ) {
V_52 = 1 ;
}
return V_52 ;
}
static int F_21 ( struct V_1 * V_2 ,
const T_2 * V_55 , T_3 V_56 ,
unsigned long V_16 )
{
struct V_41 * V_42 = V_2 -> V_43 ;
int V_52 = - V_57 ;
int V_58 ;
int V_59 ;
T_3 V_22 ;
V_58 = F_22 ( V_42 -> V_45 + 0x6c ) ;
if ( ! ( V_58 & V_60 ) )
return - V_57 ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
if ( F_18 ( V_2 , V_54 ) ) {
for ( V_22 = 0 ; V_22 < V_56 ; V_22 ++ ) {
if ( V_55 [ V_22 ] == 0xff &&
V_55 [ V_22 + 1 ] == 0x20 )
break;
}
for (; V_22 < V_56 ; V_22 += 2 ) {
int V_20 =
( V_55 [ V_22 ] << 8 ) + V_55 [ V_22 + 1 ] ;
if ( ! F_20 ( V_2 , V_20 ) )
break;
}
if ( V_22 >= V_56 ) {
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
V_52 = 0 ;
break;
}
}
}
return V_52 ;
}
static void F_23 ( struct V_1 * V_2 )
{
}
static void F_24 ( struct V_1 * V_2 )
{
F_19 ( 2 ) ;
F_2 ( V_61 | V_62 ,
V_2 -> V_4 + V_63 ) ;
F_19 ( 2 ) ;
F_2 ( V_64 | V_62 ,
V_2 -> V_4 + V_63 ) ;
F_19 ( 2 ) ;
F_2 ( V_37 , V_2 -> V_4 + V_18 ) ;
F_19 ( 2 ) ;
F_2 ( V_36 , V_2 -> V_4 + V_18 ) ;
F_23 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_39 ;
int V_65 ;
F_2 ( 0x80 | V_66 , V_2 -> V_4 + V_67 ) ;
for ( V_65 = 0 ; V_65 < 20 ; V_65 ++ ) {
V_39 = F_5 ( V_2 -> V_4 + V_38 ) ;
if ( ( V_39 & V_68 ) == 0 )
break;
F_19 ( 2 ) ;
}
F_2 ( 0x80 | V_69 , V_2 -> V_4 + V_67 ) ;
for ( V_65 = 0 ; V_65 < 20 ; V_65 ++ ) {
V_39 = F_5 ( V_2 -> V_4 + V_38 ) ;
if ( ( V_39 & V_68 ) == 0 )
break;
F_19 ( 2 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
}
static void F_27 ( struct V_1 * V_2 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_70 , int V_71 , int V_20 ,
unsigned long V_72 )
{
if ( V_70 ) {
F_2 ( V_20 , V_2 -> V_4 + V_72 + V_71 * 2 ) ;
return 0 ;
}
return F_5 ( V_2 -> V_4 + V_72 + V_71 * 2 ) ;
}
static const void * F_32 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
int V_22 ;
if ( V_74 -> V_77 != V_78 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_33 ( V_79 ) ; V_22 ++ ) {
V_76 = & V_79 [ V_22 ] ;
if ( V_74 -> V_77 == V_76 -> V_80 )
return V_76 ;
}
return NULL ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long V_81 )
{
struct V_73 * V_74 = F_35 ( V_2 ) ;
const struct V_75 * V_76 ;
struct V_41 * V_42 ;
struct V_12 * V_13 ;
int V_52 ;
V_76 = F_32 ( V_2 , V_74 ) ;
if ( ! V_76 )
return - V_82 ;
V_2 -> V_83 = V_76 ;
V_2 -> V_84 = V_76 -> V_85 ;
V_42 = F_36 ( V_2 , sizeof( * V_42 ) ) ;
if ( ! V_42 )
return - V_86 ;
V_52 = F_37 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_42 -> V_45 = F_38 ( V_74 , 0 ) ;
V_2 -> V_4 = F_38 ( V_74 , 2 ) ;
if ( ! V_42 -> V_45 || ! V_2 -> V_4 )
return - V_86 ;
V_52 = F_39 ( V_2 , 3 ) ;
if ( V_52 )
return V_52 ;
F_22 ( V_42 -> V_45 + 0x6c ) ;
V_52 = F_40 ( V_2 , & F_35 ( V_2 ) -> V_2 ,
V_87 ,
F_21 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
V_13 = & V_2 -> V_88 [ 0 ] ;
V_13 -> type = V_89 ;
V_13 -> V_90 = V_91 | V_92 ;
V_13 -> V_93 = 24 ;
V_13 -> V_94 = 0xffff ;
V_13 -> V_95 = F_6 ;
V_13 -> V_96 = & V_97 ;
V_13 = & V_2 -> V_88 [ 1 ] ;
V_13 -> type = V_98 ;
V_13 -> V_90 = V_99 ;
V_13 -> V_93 = 2 ;
V_13 -> V_94 = 0xffff ;
V_13 -> V_100 = F_12 ;
V_13 -> V_95 = V_101 ;
V_13 -> V_96 = & V_102 ;
V_52 = F_41 ( V_13 ) ;
if ( V_52 )
return V_52 ;
V_13 = & V_2 -> V_88 [ 2 ] ;
V_52 = F_42 ( V_2 , V_13 , F_31 ,
V_103 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_43 ;
if ( V_42 && V_42 -> V_45 )
F_44 ( V_42 -> V_45 ) ;
F_45 ( V_2 ) ;
}
static int F_46 ( struct V_73 * V_2 ,
const struct V_104 * V_80 )
{
return F_47 ( V_2 , & V_105 ,
V_80 -> V_106 ) ;
}
