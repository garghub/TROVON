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
int F_12 ( struct V_1 * V_2 ,
struct V_51 * V_22 )
{
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
struct V_51 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
return F_12 ( V_2 , V_22 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_58 * V_37 )
{
struct V_51 V_59 = { 0 , } ;
if ( V_37 -> V_52 > 0 )
return - V_54 ;
F_3 ( V_2 ) ;
F_12 ( V_2 , & V_59 ) ;
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
static int F_15 ( struct V_34 * V_34 , void * V_35 ,
struct V_58 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
return F_14 ( V_2 , V_37 ) ;
}
static int F_16 ( struct V_34 * V_34 , void * V_35 ,
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
static int F_17 ( struct V_34 * V_34 , void * V_35 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
if ( V_70 -> V_53 != 0 )
return - V_54 ;
V_70 -> type = V_60 ;
V_70 -> V_71 = V_2 -> V_20 ;
return 0 ;
}
static int F_18 ( struct V_34 * V_34 , void * V_35 ,
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
V_2 -> V_20 = F_19 ( T_3 , V_70 -> V_71 , V_28 [ V_2 -> V_22 ] . V_29 ,
V_28 [ V_2 -> V_22 ] . V_30 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_34 * V_34 , struct V_1 * V_2 ,
const struct V_72 * V_73 )
{
unsigned long V_74 ;
int V_75 , V_76 ;
if ( V_2 -> V_47 )
return - V_77 ;
if ( V_73 -> V_53 || V_73 -> V_78 )
return - V_54 ;
if ( V_34 -> V_79 & V_80 )
return - V_81 ;
if ( V_73 -> V_29 || V_73 -> V_30 ) {
for ( V_75 = 0 ; V_75 < F_21 ( V_28 ) ; V_75 ++ ) {
if ( ( V_75 == V_23 && V_2 -> V_42 ) ||
( V_75 == V_25 && ! V_2 -> V_42 ) ||
( V_75 == V_26 && ! V_2 -> V_55 ) )
continue;
if ( V_28 [ V_75 ] . V_29 == V_73 -> V_29 &&
V_28 [ V_75 ] . V_30 == V_73 -> V_30 )
break;
}
if ( V_75 == F_21 ( V_28 ) )
return - V_54 ;
if ( V_75 != V_2 -> V_22 ) {
V_2 -> V_22 = V_75 ;
V_2 -> V_20 = F_5 ( V_2 -> V_20 , V_28 [ V_75 ] . V_29 ,
V_28 [ V_75 ] . V_30 ) ;
F_7 ( V_2 ) ;
}
}
V_76 = ( V_2 -> V_22 == V_26 ) ? 5 : 50 ;
V_2 -> V_3 &= ~ V_21 ;
V_2 -> V_3 |= V_82 ;
if ( V_73 -> V_83 )
V_2 -> V_3 |= V_84 ;
else
V_2 -> V_3 &= ~ V_84 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_74 = V_85 + F_22 ( 10000 ) ;
for (; ; ) {
if ( F_23 ( V_85 , V_74 ) )
break;
if ( F_24 ( F_22 ( 10 ) ) ) {
V_2 -> V_3 &= ~ V_82 ;
F_7 ( V_2 ) ;
return - V_86 ;
}
if ( ! ( F_3 ( V_2 ) & V_82 ) ) {
T_3 V_20 ;
for ( V_75 = 0 ; V_75 < 100 ; V_75 ++ ) {
F_25 ( 10 ) ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 )
break;
}
if ( V_20 == 0 )
break;
if ( abs ( V_2 -> V_20 - V_20 ) < 16 * V_76 ||
( V_73 -> V_83 && V_20 < V_2 -> V_20 ) ||
( ! V_73 -> V_83 && V_20 > V_2 -> V_20 ) ) {
F_1 ( V_2 , V_2 -> V_3 ) ;
continue;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_3 &= ~ V_82 ;
return 0 ;
}
}
V_2 -> V_3 &= ~ V_82 ;
F_7 ( V_2 ) ;
return - V_87 ;
}
static int F_26 ( struct V_34 * V_34 , void * V_88 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 = F_9 ( V_34 ) ;
return F_20 ( V_34 , V_2 , V_73 ) ;
}
static int F_27 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_28 ( V_90 -> V_91 , struct V_1 , V_92 ) ;
switch ( V_90 -> V_93 ) {
case V_94 :
V_2 -> V_13 = V_90 -> V_3 ;
F_7 ( V_2 ) ;
return 0 ;
}
return - V_54 ;
}
int F_29 ( struct V_1 * V_2 )
{
V_2 -> V_13 = true ;
if ( ! V_2 -> V_47 ) {
F_1 ( V_2 , 0x55AA ) ;
if ( F_3 ( V_2 ) != 0x55AA )
return - V_95 ;
}
V_2 -> V_3 = V_31 | V_96 ;
V_2 -> V_20 = 90500 * 16 ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
int V_99 = F_29 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_100 = V_101 ;
F_31 ( & V_2 -> V_100 , V_2 ) ;
F_32 ( & V_2 -> V_102 ) ;
F_10 ( V_2 -> V_100 . V_40 , V_2 -> V_39 -> V_40 , sizeof( V_2 -> V_100 . V_40 ) ) ;
V_2 -> V_100 . V_103 = & V_2 -> V_102 ;
V_2 -> V_100 . V_39 = V_2 -> V_39 ;
V_2 -> V_104 = V_105 ;
V_2 -> V_104 . V_98 = V_98 ;
V_2 -> V_100 . V_104 = & V_2 -> V_104 ;
if ( V_2 -> V_47 )
F_33 ( & V_2 -> V_100 , V_106 ) ;
if ( ! V_2 -> V_107 ) {
V_2 -> V_100 . V_92 = & V_2 -> V_92 ;
F_34 ( & V_2 -> V_92 , 1 ) ;
F_35 ( & V_2 -> V_92 , & V_108 ,
V_94 , 0 , 1 , 1 , 1 ) ;
V_99 = V_2 -> V_92 . error ;
if ( V_99 ) {
F_36 ( V_2 -> V_39 , L_5 ) ;
F_37 ( & V_2 -> V_92 ) ;
return V_99 ;
}
if ( V_2 -> V_109 ) {
V_99 = V_2 -> V_109 ( V_2 ) ;
if ( V_99 ) {
F_37 ( & V_2 -> V_92 ) ;
return V_99 ;
}
}
F_38 ( & V_2 -> V_92 ) ;
}
V_99 = F_39 ( & V_2 -> V_100 , V_110 , V_2 -> V_111 ) ;
if ( V_99 ) {
F_36 ( V_2 -> V_39 , L_6 ) ;
F_37 ( V_2 -> V_100 . V_92 ) ;
return V_99 ;
}
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_100 ) ;
F_37 ( V_2 -> V_100 . V_92 ) ;
}
static int T_4 F_42 ( void )
{
return 0 ;
}
static void T_5 F_43 ( void )
{
}
