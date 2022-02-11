static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 & 0x00ff , V_2 -> V_4 + V_5 ) ;
F_2 ( ( V_3 >> 8 ) & 0x00ff ,
V_2 -> V_4 + V_5 ) ;
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
static int F_4 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned long V_16 )
{
unsigned int V_17 ;
V_17 = F_5 ( V_2 -> V_4 + V_18 ) ;
if ( V_17 & V_16 )
return 0 ;
return - V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned int * V_20 )
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
static int F_11 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned long V_16 )
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
struct V_14 * V_15 , unsigned int * V_20 )
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
T_2 V_45 ;
V_45 = F_16 ( V_43 -> V_46 + V_47 ) ;
V_45 |= V_48 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
V_45 &= ~ V_48 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
T_2 V_45 ;
V_45 = F_16 ( V_43 -> V_46 + V_47 ) ;
V_45 &= ~ V_49 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
V_45 |= V_49 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
V_45 &= ~ V_49 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
T_2 V_45 ;
V_45 = F_16 ( V_43 -> V_46 + V_47 ) ;
V_45 |= V_50 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
V_45 &= ~ V_50 ;
F_7 ( V_45 , V_43 -> V_46 + V_47 ) ;
F_17 ( 10 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_51 = - V_52 ;
int V_22 ;
T_1 V_53 ;
for ( V_22 = 0 ; V_22 < 50 ; V_22 ++ ) {
V_53 = F_5 ( V_2 -> V_4 + V_54 ) ;
if ( V_53 & V_55 ) {
V_51 = 0 ;
break;
}
F_21 ( 100 , 1000 ) ;
}
F_22 ( 5 ) ;
return V_51 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 100 ; V_22 ++ ) {
if ( F_5 ( V_2 -> V_4 + V_54 ) &
V_56 ) {
return 0 ;
}
F_22 ( 1 ) ;
}
return - V_52 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_20 , bool V_57 )
{
int V_51 = 0 ;
if ( V_57 ) {
V_51 = F_23 ( V_2 ) ;
if ( V_51 )
return V_51 ;
} else {
F_21 ( 10 , 20 ) ;
}
F_2 ( V_20 , V_2 -> V_4 + V_58 ) ;
if ( ! ( F_5 ( V_2 -> V_4 + V_54 ) & V_55 ) )
V_51 = - V_59 ;
return V_51 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 200 ; V_22 ++ ) {
T_2 V_45 = F_16 ( V_43 -> V_46 + V_47 ) ;
if ( V_45 & V_60 )
return 0 ;
F_21 ( 100 , 1000 ) ;
}
return - V_52 ;
}
static int F_26 ( struct V_1 * V_2 , const T_3 * V_61 ,
T_4 V_62 , unsigned long V_16 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
int V_51 = - V_59 ;
T_2 V_45 ;
int V_63 ;
T_4 V_22 ;
bool V_57 ;
for ( V_22 = 0 ; V_22 + 1 < V_62 ; V_22 ++ ) {
if ( V_61 [ V_22 ] == 0xff && V_61 [ V_22 + 1 ] == 0x20 )
break;
}
if ( V_22 + 1 >= V_62 ) {
F_27 ( V_2 -> V_64 , L_1 ) ;
return - V_65 ;
}
if ( ( V_62 - V_22 ) & 1 ) {
F_27 ( V_2 -> V_64 ,
L_2 ,
V_62 - V_22 , V_62 , V_22 ) ;
return - V_65 ;
}
V_61 += V_22 ;
V_62 -= V_22 ;
V_45 = F_16 ( V_43 -> V_46 + V_47 ) ;
if ( ! ( V_45 & V_66 ) )
return - V_59 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
F_15 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
V_51 = F_20 ( V_2 ) ;
if ( V_51 )
continue;
V_57 = ( F_5 ( V_2 -> V_4 + V_54 ) &
V_67 ) == V_68 ;
for (; V_22 < V_62 ; V_22 += 2 ) {
T_1 V_20 = ( V_61 [ V_22 ] << 8 ) + V_61 [ V_22 + 1 ] ;
V_51 = F_24 ( V_2 , V_20 , V_57 ) ;
if ( V_51 )
break;
}
if ( V_51 == 0 )
V_51 = F_25 ( V_2 ) ;
if ( V_51 == 0 ) {
F_15 ( V_2 ) ;
F_18 ( V_2 ) ;
break;
}
}
return V_51 ;
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
F_22 ( 2 ) ;
F_2 ( V_69 | V_70 ,
V_2 -> V_4 + V_71 ) ;
F_22 ( 2 ) ;
F_2 ( V_72 | V_70 ,
V_2 -> V_4 + V_71 ) ;
F_22 ( 2 ) ;
F_2 ( V_38 ,
V_2 -> V_4 + V_26 ) ;
F_22 ( 2 ) ;
F_2 ( V_37 ,
V_2 -> V_4 + V_26 ) ;
F_28 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_40 ;
int V_73 ;
F_2 ( V_74 | V_75 ,
V_2 -> V_4 + V_76 ) ;
for ( V_73 = 0 ; V_73 < 20 ; V_73 ++ ) {
V_40 = F_5 ( V_2 -> V_4 + V_39 ) ;
if ( ( V_40 & V_77 ) == 0 )
break;
F_22 ( 2 ) ;
}
F_2 ( V_74 | V_78 ,
V_2 -> V_4 + V_76 ) ;
for ( V_73 = 0 ; V_73 < 20 ; V_73 ++ ) {
V_40 = F_5 ( V_2 -> V_4 + V_39 ) ;
if ( ( V_40 & V_77 ) == 0 )
break;
F_22 ( 2 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
}
static void F_32 ( struct V_1 * V_2 )
{
}
static void F_33 ( struct V_1 * V_2 )
{
}
static void F_34 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_79 , int V_80 , int V_20 ,
unsigned long V_81 )
{
if ( V_79 ) {
F_2 ( V_20 , V_2 -> V_4 + V_81 + V_80 * 2 ) ;
return 0 ;
}
return F_5 ( V_2 -> V_4 + V_81 + V_80 * 2 ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned long V_16 )
{
struct V_82 * V_83 = F_38 ( V_2 ) ;
const struct V_84 * V_85 ;
struct V_42 * V_43 ;
struct V_12 * V_13 ;
int V_51 ;
if ( V_16 >= F_39 ( V_86 ) )
return - V_87 ;
V_85 = & V_86 [ V_16 ] ;
if ( ! V_85 -> V_88 )
return - V_87 ;
V_2 -> V_89 = V_85 ;
V_2 -> V_90 = V_85 -> V_88 ;
V_43 = F_40 ( V_2 , sizeof( * V_43 ) ) ;
if ( ! V_43 )
return - V_91 ;
V_51 = F_41 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_43 -> V_46 = F_42 ( V_83 , 0 ) ;
V_2 -> V_4 = F_42 ( V_83 , 2 ) ;
if ( ! V_43 -> V_46 || ! V_2 -> V_4 )
return - V_91 ;
V_51 = F_43 ( V_2 , 3 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_44 ( V_2 , & F_38 ( V_2 ) -> V_2 ,
V_92 , F_26 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
V_13 = & V_2 -> V_93 [ 0 ] ;
V_13 -> type = V_94 ;
V_13 -> V_95 = V_96 | V_97 ;
V_13 -> V_98 = 24 ;
V_13 -> V_99 = 0xffff ;
V_13 -> V_100 = F_6 ;
V_13 -> V_101 = & V_102 ;
V_13 = & V_2 -> V_93 [ 1 ] ;
V_13 -> type = V_103 ;
V_13 -> V_95 = V_104 ;
V_13 -> V_98 = V_85 -> V_105 ? 2 : 4 ;
V_13 -> V_99 = 0xffff ;
V_13 -> V_106 = F_13 ;
V_13 -> V_101 = & V_107 ;
V_51 = F_45 ( V_13 ) ;
if ( V_51 )
return V_51 ;
V_13 = & V_2 -> V_93 [ 2 ] ;
return F_46 ( V_2 , V_13 , F_36 ,
V_108 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_44 ;
if ( V_43 && V_43 -> V_46 )
F_48 ( V_43 -> V_46 ) ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_82 * V_2 , const struct V_109 * V_110 )
{
return F_51 ( V_2 , & V_111 , V_110 -> V_112 ) ;
}
