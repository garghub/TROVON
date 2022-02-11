static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_2 ( V_3 & 0x00ff , V_2 -> V_4 + V_5 ) ;
F_2 ( ( V_3 >> 8 ) & 0x00ff ,
V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 ,
int V_7 )
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
V_25 ,
V_2 -> V_4 + V_26 ) ;
F_7 ( 1000000 , V_2 -> V_4 + V_27 ) ;
F_2 ( 0 , V_2 -> V_4 + V_28 ) ;
V_7 = F_8 ( V_15 -> V_29 ) ;
V_6 = F_9 ( V_15 -> V_29 ) ;
for ( V_22 = 0 ; V_22 < V_15 -> V_30 ; V_22 ++ ) {
F_3 ( V_2 , V_6 , V_7 ) ;
F_2 ( V_31 ,
V_2 -> V_4 + V_26 ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_32 ) ;
if ( V_21 )
return V_21 ;
F_2 ( V_33 ,
V_2 -> V_4 + V_26 ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_34 ) ;
if ( V_21 )
return V_21 ;
V_21 =
F_10 ( V_2 , V_13 , V_15 , F_4 ,
V_35 ) ;
if ( V_21 )
return V_21 ;
V_20 [ V_22 ] = F_5 ( V_2 -> V_4 + V_36 ) ;
F_2 ( V_37 ,
V_2 -> V_4 + V_26 ) ;
F_2 ( V_38 ,
V_2 -> V_4 + V_26 ) ;
}
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_16 )
{
unsigned int V_6 = F_9 ( V_15 -> V_29 ) ;
unsigned int V_17 ;
V_17 = F_5 ( V_2 -> V_4 + V_39 ) ;
if ( ( V_17 & F_12 ( V_6 ) ) == 0 )
return 0 ;
return - V_19 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned int * V_20 )
{
unsigned int V_6 = F_9 ( V_15 -> V_29 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_15 -> V_30 ; V_22 ++ ) {
unsigned int V_40 = V_20 [ V_22 ] ;
int V_21 ;
F_2 ( V_40 , V_2 -> V_4 + F_14 ( V_6 ) ) ;
V_21 = F_10 ( V_2 , V_13 , V_15 , F_11 , 0 ) ;
if ( V_21 )
return V_21 ;
V_13 -> V_41 [ V_6 ] = V_40 ;
}
return V_15 -> V_30 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
F_7 ( V_45 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_47 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
F_7 ( V_48 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_49 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_48 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
F_7 ( V_50 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
F_7 ( V_51 , V_43 -> V_46 + 0x6c ) ;
F_16 ( 10 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_52 )
{
int V_53 = 0 ;
int V_22 ;
int V_54 ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
V_54 = F_5 ( V_2 -> V_4 + 0x1000 ) ;
if ( ( V_54 & V_52 ) == V_52 ) {
V_53 = 1 ;
break;
}
F_20 ( 100 , 1000 ) ;
}
F_21 ( 5 ) ;
return V_53 ;
}
static int F_22 ( struct V_1 * V_2 , int V_20 )
{
int V_53 = 0 ;
F_20 ( 10 , 20 ) ;
F_2 ( V_20 , V_2 -> V_4 + 0x1000 ) ;
if ( ( F_5 ( V_2 -> V_4 + 0x1000 ) & V_55 ) ==
V_55 ) {
V_53 = 1 ;
}
return V_53 ;
}
static int F_23 ( struct V_1 * V_2 ,
const T_2 * V_56 , T_3 V_57 ,
unsigned long V_16 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
int V_53 = - V_58 ;
int V_59 ;
int V_60 ;
T_3 V_22 ;
V_59 = F_24 ( V_43 -> V_46 + 0x6c ) ;
if ( ! ( V_59 & V_61 ) )
return - V_58 ;
for ( V_60 = 0 ; V_60 < 3 ; V_60 ++ ) {
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( F_19 ( V_2 , V_55 ) ) {
for ( V_22 = 0 ; V_22 < V_57 ; V_22 ++ ) {
if ( V_56 [ V_22 ] == 0xff &&
V_56 [ V_22 + 1 ] == 0x20 )
break;
}
for (; V_22 < V_57 ; V_22 += 2 ) {
int V_20 =
( V_56 [ V_22 ] << 8 ) + V_56 [ V_22 + 1 ] ;
if ( ! F_22 ( V_2 , V_20 ) )
break;
}
if ( V_22 >= V_57 ) {
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
V_53 = 0 ;
break;
}
}
}
return V_53 ;
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_1 * V_2 )
{
F_21 ( 2 ) ;
F_2 ( V_62 | V_63 ,
V_2 -> V_4 + V_64 ) ;
F_21 ( 2 ) ;
F_2 ( V_65 | V_63 ,
V_2 -> V_4 + V_64 ) ;
F_21 ( 2 ) ;
F_2 ( V_38 ,
V_2 -> V_4 + V_26 ) ;
F_21 ( 2 ) ;
F_2 ( V_37 ,
V_2 -> V_4 + V_26 ) ;
F_25 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned int V_40 ;
int V_66 ;
F_2 ( V_67 | V_68 ,
V_2 -> V_4 + V_69 ) ;
for ( V_66 = 0 ; V_66 < 20 ; V_66 ++ ) {
V_40 = F_5 ( V_2 -> V_4 + V_39 ) ;
if ( ( V_40 & V_70 ) == 0 )
break;
F_21 ( 2 ) ;
}
F_2 ( V_67 | V_71 ,
V_2 -> V_4 + V_69 ) ;
for ( V_66 = 0 ; V_66 < 20 ; V_66 ++ ) {
V_40 = F_5 ( V_2 -> V_4 + V_39 ) ;
if ( ( V_40 & V_70 ) == 0 )
break;
F_21 ( 2 ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
int V_72 , int V_73 , int V_20 ,
unsigned long V_74 )
{
if ( V_72 ) {
F_2 ( V_20 , V_2 -> V_4 + V_74 + V_73 * 2 ) ;
return 0 ;
}
return F_5 ( V_2 -> V_4 + V_74 + V_73 * 2 ) ;
}
static const void * F_34 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
const struct V_77 * V_78 ;
int V_22 ;
if ( V_76 -> V_79 != V_80 )
return NULL ;
for ( V_22 = 0 ; V_22 < F_35 ( V_81 ) ; V_22 ++ ) {
V_78 = & V_81 [ V_22 ] ;
if ( V_76 -> V_82 == V_78 -> V_83 )
return V_78 ;
}
return NULL ;
}
static int F_36 ( struct V_1 * V_2 ,
unsigned long V_84 )
{
struct V_75 * V_76 = F_37 ( V_2 ) ;
const struct V_77 * V_78 ;
struct V_42 * V_43 ;
struct V_12 * V_13 ;
int V_53 ;
V_78 = F_34 ( V_2 , V_76 ) ;
if ( ! V_78 )
return - V_85 ;
V_2 -> V_86 = V_78 ;
V_2 -> V_87 = V_78 -> V_88 ;
V_43 = F_38 ( V_2 , sizeof( * V_43 ) ) ;
if ( ! V_43 )
return - V_89 ;
V_53 = F_39 ( V_2 ) ;
if ( V_53 )
return V_53 ;
V_43 -> V_46 = F_40 ( V_76 , 0 ) ;
V_2 -> V_4 = F_40 ( V_76 , 2 ) ;
if ( ! V_43 -> V_46 || ! V_2 -> V_4 )
return - V_89 ;
V_53 = F_41 ( V_2 , 3 ) ;
if ( V_53 )
return V_53 ;
F_24 ( V_43 -> V_46 + 0x6c ) ;
V_53 = F_42 ( V_2 , & F_37 ( V_2 ) -> V_2 ,
V_90 ,
F_23 , 0 ) ;
if ( V_53 < 0 )
return V_53 ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
V_13 = & V_2 -> V_91 [ 0 ] ;
V_13 -> type = V_92 ;
V_13 -> V_93 = V_94 | V_95 ;
V_13 -> V_96 = 24 ;
V_13 -> V_97 = 0xffff ;
V_13 -> V_98 = F_6 ;
V_13 -> V_99 = & V_100 ;
V_13 = & V_2 -> V_91 [ 1 ] ;
V_13 -> type = V_101 ;
V_13 -> V_93 = V_102 ;
V_13 -> V_96 = 2 ;
V_13 -> V_97 = 0xffff ;
V_13 -> V_103 = F_13 ;
V_13 -> V_99 = & V_104 ;
V_53 = F_43 ( V_13 ) ;
if ( V_53 )
return V_53 ;
V_13 = & V_2 -> V_91 [ 2 ] ;
return F_44 ( V_2 , V_13 , F_33 ,
V_105 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
if ( V_43 && V_43 -> V_46 )
F_46 ( V_43 -> V_46 ) ;
F_47 ( V_2 ) ;
}
static int F_48 ( struct V_75 * V_2 ,
const struct V_106 * V_83 )
{
return F_49 ( V_2 , & V_107 ,
V_83 -> V_108 ) ;
}
