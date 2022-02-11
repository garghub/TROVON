static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
if ( V_2 -> V_6 -> V_7 )
return V_2 -> V_6 -> V_7 ( V_2 , V_3 ) ;
V_2 -> V_6 -> V_8 ( V_2 , 1 ) ;
F_2 ( 16 ) ;
for ( V_4 = 25 ; V_4 > 0 ; V_4 -- ) {
V_5 = ( V_3 >> 24 ) & V_9 ;
V_3 <<= 1 ;
V_2 -> V_6 -> V_10 ( V_2 , V_5 | V_11 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_10 ( V_2 , V_5 | V_11 | V_12 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_10 ( V_2 , V_5 | V_11 ) ;
F_2 ( 2 ) ;
}
if ( ! V_2 -> V_13 )
V_2 -> V_6 -> V_10 ( V_2 , 0 ) ;
}
static T_3 F_3 ( struct V_1 * V_2 )
{
T_1 V_4 , V_14 ;
T_3 V_5 = 0 ;
if ( V_2 -> V_6 -> V_15 )
return V_2 -> V_6 -> V_15 ( V_2 ) ;
V_2 -> V_6 -> V_8 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_10 ( V_2 , 0 ) ;
F_2 ( 16 ) ;
for ( V_4 = 24 ; V_4 -- ; ) {
V_2 -> V_6 -> V_10 ( V_2 , V_12 ) ;
F_2 ( 2 ) ;
if ( ! V_4 )
V_2 -> V_16 = V_2 -> V_6 -> V_17 ( V_2 ) & V_18 ? 0 : 1 ;
V_2 -> V_6 -> V_10 ( V_2 , 0 ) ;
F_2 ( 2 ) ;
V_5 <<= 1 ;
V_14 = V_2 -> V_6 -> V_17 ( V_2 ) ;
if ( ! V_4 )
V_2 -> V_19 = ( V_14 & V_18 ) ? 0 : 1 ;
if ( V_14 & V_9 )
V_5 ++ ;
F_2 ( 2 ) ;
}
if ( V_2 -> V_13 )
V_2 -> V_6 -> V_10 ( V_2 , V_11 ) ;
return V_5 ;
}
static T_3 F_4 ( struct V_1 * V_2 , T_3 V_3 )
{
T_3 V_20 = V_3 & V_21 ;
if ( V_20 == 0 )
return V_20 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_20 *= 125 ;
V_20 /= 10 ;
V_20 -= V_24 ;
break;
case V_25 :
V_20 *= 125 ;
V_20 /= 10 ;
V_20 += V_24 ;
break;
case V_26 :
V_20 -= V_27 ;
break;
}
return F_5 ( V_20 * 16 , V_28 [ V_2 -> V_22 ] . V_29 ,
V_28 [ V_2 -> V_22 ] . V_30 ) ;
}
static T_3 F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , F_3 ( V_2 ) ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_3 V_20 = V_2 -> V_20 / 16 ;
T_3 V_22 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_22 = V_31 ;
V_20 += V_24 ;
V_20 *= 10 ;
V_20 /= 125 ;
break;
case V_25 :
V_22 = V_31 ;
V_20 -= V_24 ;
V_20 *= 10 ;
V_20 /= 125 ;
break;
case V_26 :
V_22 = V_32 ;
V_20 += V_27 ;
break;
}
V_2 -> V_3 &= ~ ( V_21 | V_33 ) ;
V_2 -> V_3 |= V_22 ;
V_2 -> V_3 |= V_20 & V_21 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_2 -> V_20 = F_4 ( V_2 , V_2 -> V_3 ) ;
}
static int F_8 ( struct V_34 * V_34 , void * V_35 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
F_10 ( V_37 -> V_38 , V_2 -> V_39 -> V_40 , sizeof( V_37 -> V_38 ) ) ;
F_10 ( V_37 -> V_41 , V_2 -> V_41 , sizeof( V_37 -> V_41 ) ) ;
F_11 ( V_37 -> V_41 , V_2 -> V_42 ? L_1 : L_2 , sizeof( V_37 -> V_41 ) ) ;
F_10 ( V_37 -> V_43 , V_2 -> V_43 , sizeof( V_37 -> V_43 ) ) ;
V_37 -> V_44 = V_45 | V_46 ;
if ( ! V_2 -> V_47 )
V_37 -> V_44 |= V_48 ;
V_37 -> V_49 = V_37 -> V_44 | V_50 ;
return 0 ;
}
static int F_12 ( struct V_34 * V_34 , void * V_35 ,
struct V_51 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
int V_52 ;
if ( V_22 -> V_53 != 0 )
return - V_54 ;
switch ( V_22 -> V_52 ) {
case 0 :
if ( V_2 -> V_42 )
V_52 = V_25 ;
else
V_52 = V_23 ;
break;
case 1 :
if ( V_2 -> V_55 ) {
V_52 = V_26 ;
break;
}
default:
return - V_54 ;
}
* V_22 = V_28 [ V_52 ] ;
if ( ! V_2 -> V_47 )
V_22 -> V_56 |= V_57 ;
return 0 ;
}
static int F_13 ( struct V_34 * V_34 , void * V_35 ,
struct V_58 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
struct V_51 V_59 = { 0 , } ;
if ( V_37 -> V_52 > 0 )
return - V_54 ;
F_3 ( V_2 ) ;
F_12 ( V_34 , V_35 , & V_59 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
F_10 ( V_37 -> V_40 , V_2 -> V_55 ? L_3 : L_4 , sizeof( V_37 -> V_40 ) ) ;
V_37 -> type = V_60 ;
V_37 -> V_56 = V_59 . V_56 ;
V_37 -> V_29 = V_2 -> V_55 ? V_28 [ V_26 ] . V_29 : V_59 . V_29 ;
V_37 -> V_30 = V_59 . V_30 ;
V_37 -> V_61 = V_2 -> V_19 ? V_62 : V_63 ;
V_37 -> V_64 = ( V_2 -> V_3 & V_65 ) ?
V_66 : V_67 ;
V_37 -> signal = V_2 -> V_16 ? 0xffff : 0 ;
return 0 ;
}
static int F_14 ( struct V_34 * V_34 , void * V_35 ,
const struct V_58 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
T_3 V_68 = V_2 -> V_3 ;
if ( V_37 -> V_52 )
return - V_54 ;
V_2 -> V_3 &= ~ V_65 ;
if ( V_37 -> V_64 == V_66 )
V_2 -> V_3 |= V_65 ;
if ( V_2 -> V_22 != V_26 && V_2 -> V_3 != V_68 )
F_7 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_34 , void * V_35 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
if ( V_70 -> V_53 != 0 )
return - V_54 ;
V_70 -> type = V_60 ;
V_70 -> V_71 = V_2 -> V_20 ;
return 0 ;
}
static int F_16 ( struct V_34 * V_34 , void * V_35 ,
const struct V_69 * V_70 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
if ( V_70 -> V_53 != 0 || V_70 -> type != V_60 )
return - V_54 ;
if ( V_2 -> V_55 && V_70 -> V_71 < ( 20000 * 16 ) )
V_2 -> V_22 = V_26 ;
else if ( V_2 -> V_42 )
V_2 -> V_22 = V_25 ;
else
V_2 -> V_22 = V_23 ;
V_2 -> V_20 = F_17 ( T_3 , V_70 -> V_71 , V_28 [ V_2 -> V_22 ] . V_29 ,
V_28 [ V_2 -> V_22 ] . V_30 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_34 * V_34 , void * V_72 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
unsigned long V_75 ;
int V_76 , V_77 ;
if ( V_2 -> V_47 )
return - V_78 ;
if ( V_74 -> V_53 || V_74 -> V_79 )
return - V_54 ;
if ( V_34 -> V_80 & V_81 )
return - V_82 ;
if ( V_74 -> V_29 || V_74 -> V_30 ) {
for ( V_76 = 0 ; V_76 < F_19 ( V_28 ) ; V_76 ++ ) {
if ( ( V_76 == V_23 && V_2 -> V_42 ) ||
( V_76 == V_25 && ! V_2 -> V_42 ) ||
( V_76 == V_26 && ! V_2 -> V_55 ) )
continue;
if ( V_28 [ V_76 ] . V_29 == V_74 -> V_29 &&
V_28 [ V_76 ] . V_30 == V_74 -> V_30 )
break;
}
if ( V_76 == F_19 ( V_28 ) )
return - V_54 ;
if ( V_76 != V_2 -> V_22 ) {
V_2 -> V_22 = V_76 ;
V_2 -> V_20 = F_5 ( V_2 -> V_20 , V_28 [ V_76 ] . V_29 ,
V_28 [ V_76 ] . V_30 ) ;
F_7 ( V_2 ) ;
}
}
V_77 = ( V_2 -> V_22 == V_26 ) ? 5 : 50 ;
V_2 -> V_3 &= ~ V_21 ;
V_2 -> V_3 |= V_83 ;
if ( V_74 -> V_84 )
V_2 -> V_3 |= V_85 ;
else
V_2 -> V_3 &= ~ V_85 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_75 = V_86 + F_20 ( 10000 ) ;
for (; ; ) {
if ( F_21 ( V_86 , V_75 ) )
break;
if ( F_22 ( F_20 ( 10 ) ) ) {
V_2 -> V_3 &= ~ V_83 ;
F_7 ( V_2 ) ;
return - V_87 ;
}
if ( ! ( F_3 ( V_2 ) & V_83 ) ) {
T_3 V_20 ;
for ( V_76 = 0 ; V_76 < 100 ; V_76 ++ ) {
F_23 ( 10 ) ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 )
break;
}
if ( V_20 == 0 )
break;
if ( abs ( V_2 -> V_20 - V_20 ) < 16 * V_77 ||
( V_74 -> V_84 && V_20 < V_2 -> V_20 ) ||
( ! V_74 -> V_84 && V_20 > V_2 -> V_20 ) ) {
F_1 ( V_2 , V_2 -> V_3 ) ;
continue;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_3 &= ~ V_83 ;
return 0 ;
}
}
V_2 -> V_3 &= ~ V_83 ;
F_7 ( V_2 ) ;
return - V_88 ;
}
static int F_24 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_25 ( V_90 -> V_91 , struct V_1 , V_92 ) ;
switch ( V_90 -> V_93 ) {
case V_94 :
V_2 -> V_13 = V_90 -> V_3 ;
F_7 ( V_2 ) ;
return 0 ;
}
return - V_54 ;
}
int F_26 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
int V_97 ;
V_2 -> V_13 = true ;
if ( ! V_2 -> V_47 ) {
F_1 ( V_2 , 0x55AA ) ;
if ( F_3 ( V_2 ) != 0x55AA )
return - V_98 ;
}
V_2 -> V_3 = V_31 | V_99 ;
V_2 -> V_20 = 90500 * 16 ;
F_7 ( V_2 ) ;
V_2 -> V_100 = V_101 ;
F_27 ( & V_2 -> V_100 , V_2 ) ;
F_28 ( & V_2 -> V_102 ) ;
F_10 ( V_2 -> V_100 . V_40 , V_2 -> V_39 -> V_40 , sizeof( V_2 -> V_100 . V_40 ) ) ;
V_2 -> V_100 . V_103 = & V_2 -> V_102 ;
V_2 -> V_100 . V_39 = V_2 -> V_39 ;
V_2 -> V_104 = V_105 ;
V_2 -> V_104 . V_96 = V_96 ;
V_2 -> V_100 . V_104 = & V_2 -> V_104 ;
F_29 ( V_106 , & V_2 -> V_100 . V_107 ) ;
if ( V_2 -> V_47 )
F_30 ( & V_2 -> V_100 , V_108 ) ;
if ( ! V_2 -> V_109 ) {
V_2 -> V_100 . V_92 = & V_2 -> V_92 ;
F_31 ( & V_2 -> V_92 , 1 ) ;
F_32 ( & V_2 -> V_92 , & V_110 ,
V_94 , 0 , 1 , 1 , 1 ) ;
V_97 = V_2 -> V_92 . error ;
if ( V_97 ) {
F_33 ( V_2 -> V_39 , L_5 ) ;
F_34 ( & V_2 -> V_92 ) ;
return V_97 ;
}
if ( V_2 -> V_111 ) {
V_97 = V_2 -> V_111 ( V_2 ) ;
if ( V_97 ) {
F_34 ( & V_2 -> V_92 ) ;
return V_97 ;
}
}
F_35 ( & V_2 -> V_92 ) ;
}
V_97 = F_36 ( & V_2 -> V_100 , V_112 , V_2 -> V_113 ) ;
if ( V_97 ) {
F_33 ( V_2 -> V_39 , L_6 ) ;
F_34 ( V_2 -> V_100 . V_92 ) ;
return V_97 ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_100 ) ;
F_34 ( V_2 -> V_100 . V_92 ) ;
}
static int T_4 F_39 ( void )
{
return 0 ;
}
static void T_5 F_40 ( void )
{
}
