static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_6 ,
unsigned long V_7 )
{
return F_5 ( V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static inline void F_6 ( struct V_1 * V_6 ,
T_1 V_9 , unsigned long V_7 )
{
F_7 ( V_9 , V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static void F_8 ( struct V_1 * V_6 , const T_2 * V_10 ,
T_3 V_11 )
{
T_3 V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_11 , 4 ) ; V_12 ++ ) {
T_3 V_14 = F_10 ( T_3 , V_11 - V_12 * 4 , 4 ) ;
T_1 V_9 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
V_9 |= V_10 [ V_12 * 4 + V_13 ] << ( V_13 * 8 ) ;
F_6 ( V_6 , V_9 , F_11 ( V_12 ) ) ;
}
}
static void F_12 ( struct V_1 * V_6 , T_2 * V_10 ,
T_3 V_11 )
{
T_3 V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_11 , 4 ) ; V_12 ++ ) {
T_3 V_14 = F_10 ( T_3 , V_11 - V_12 * 4 , 4 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , F_13 ( V_12 ) ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
V_10 [ V_12 * 4 + V_13 ] = V_9 >> ( V_13 * 8 ) ;
}
}
static T_4 F_14 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
unsigned long V_17 = F_15 ( 250 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_18 ;
T_4 V_19 = 0 ;
T_1 V_9 ;
if ( V_16 -> V_11 > 16 )
return - V_20 ;
if ( V_16 -> V_11 < 1 ) {
switch ( V_16 -> V_21 & ~ V_22 ) {
case V_23 :
case V_24 :
case V_25 :
V_9 = V_26 ;
break;
default:
return - V_20 ;
}
} else {
V_9 = F_16 ( V_16 -> V_11 - 1 ) ;
}
switch ( V_16 -> V_21 & ~ V_22 ) {
case V_24 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_27 ;
else
V_9 |= V_28 ;
break;
case V_25 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_29 ;
else
V_9 |= V_30 ;
break;
case V_23 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_31 ;
else
V_9 |= V_32 ;
break;
case V_33 :
V_9 |= V_34 ;
break;
case V_35 :
V_9 |= V_36 ;
break;
default:
return - V_20 ;
}
F_6 ( V_6 , V_16 -> V_37 , V_38 ) ;
F_6 ( V_6 , V_9 , V_39 ) ;
if ( ( V_16 -> V_21 & V_25 ) == 0 ) {
F_8 ( V_6 , V_16 -> V_10 , V_16 -> V_11 ) ;
V_19 = V_16 -> V_11 ;
}
V_9 = F_4 ( V_6 , V_39 ) ;
V_9 |= V_40 ;
F_6 ( V_6 , V_9 , V_39 ) ;
V_18 = F_17 ( & V_6 -> V_41 , V_17 ) ;
if ( ! V_18 )
return - V_42 ;
V_9 = F_4 ( V_6 , V_43 ) ;
F_6 ( V_6 , 0xf00 , V_43 ) ;
if ( V_9 & V_44 )
return - V_42 ;
if ( ( V_9 & V_45 ) ||
( V_9 & V_46 ) ||
( V_9 & V_47 ) )
return - V_48 ;
switch ( ( V_9 & V_49 ) >> 16 ) {
case 0x00 :
V_16 -> V_50 = V_51 ;
break;
case 0x01 :
V_16 -> V_50 = V_52 ;
break;
case 0x02 :
V_16 -> V_50 = V_53 ;
break;
case 0x04 :
V_16 -> V_50 = V_54 ;
break;
case 0x08 :
V_16 -> V_50 = V_55 ;
break;
}
if ( ( V_16 -> V_11 > 0 ) && ( V_16 -> V_50 == V_51 ) ) {
if ( V_16 -> V_21 & V_25 ) {
T_3 V_56 = V_9 & V_57 ;
if ( F_18 ( V_56 != V_16 -> V_11 ) )
V_56 = F_10 ( T_3 , V_56 , V_16 -> V_11 ) ;
F_12 ( V_6 , V_16 -> V_10 , V_56 ) ;
V_19 = V_56 ;
}
}
return V_19 ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_58 )
F_20 ( V_6 -> V_58 -> V_59 . V_60 ) ;
}
static T_5 F_21 ( int V_61 , void * V_62 )
{
struct V_1 * V_6 = V_62 ;
T_5 V_19 = V_63 ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_64 ) ;
F_6 ( V_6 , V_9 , V_64 ) ;
if ( V_9 & ( V_65 | V_66 ) )
F_22 ( & V_6 -> V_5 ) ;
if ( V_9 & V_67 ) {
}
if ( V_9 & V_68 )
V_41 ( & V_6 -> V_41 ) ;
return V_19 ;
}
static int F_23 ( struct V_69 * V_70 )
{
struct V_1 * V_6 ;
struct V_71 * V_8 ;
T_1 V_9 ;
int V_72 ;
V_6 = F_24 ( & V_70 -> V_60 , sizeof( * V_6 ) , V_73 ) ;
if ( ! V_6 )
return - V_74 ;
F_25 ( & V_6 -> V_5 , F_19 ) ;
F_26 ( & V_6 -> V_41 ) ;
F_27 ( & V_6 -> V_75 ) ;
V_6 -> V_60 = & V_70 -> V_60 ;
V_8 = F_28 ( V_70 , V_76 , 0 ) ;
V_6 -> V_8 = F_29 ( & V_70 -> V_60 , V_8 ) ;
if ( F_30 ( V_6 -> V_8 ) )
return F_31 ( V_6 -> V_8 ) ;
V_6 -> V_61 = F_32 ( V_70 , 0 ) ;
if ( V_6 -> V_61 < 0 ) {
F_33 ( & V_70 -> V_60 , L_1 ) ;
return - V_77 ;
}
V_6 -> V_78 = F_34 ( & V_70 -> V_60 , L_2 ) ;
if ( F_30 ( V_6 -> V_78 ) ) {
F_33 ( & V_70 -> V_60 , L_3 ,
F_31 ( V_6 -> V_78 ) ) ;
return F_31 ( V_6 -> V_78 ) ;
}
V_6 -> V_79 = F_35 ( & V_70 -> V_60 , NULL ) ;
if ( F_30 ( V_6 -> V_79 ) ) {
F_33 ( & V_70 -> V_60 , L_4 ,
F_31 ( V_6 -> V_79 ) ) ;
return F_31 ( V_6 -> V_79 ) ;
}
V_72 = F_36 ( V_6 -> V_79 ) ;
if ( V_72 < 0 ) {
F_33 ( & V_70 -> V_60 , L_5 ,
V_72 ) ;
return V_72 ;
}
F_37 ( V_6 -> V_78 ) ;
V_6 -> V_80 = F_35 ( & V_70 -> V_60 , L_6 ) ;
if ( F_30 ( V_6 -> V_80 ) ) {
F_33 ( & V_70 -> V_60 , L_7 ,
F_31 ( V_6 -> V_80 ) ) ;
return F_31 ( V_6 -> V_80 ) ;
}
V_72 = F_36 ( V_6 -> V_80 ) ;
if ( V_72 < 0 ) {
F_33 ( & V_70 -> V_60 , L_8 ,
V_72 ) ;
return V_72 ;
}
V_72 = F_38 ( V_6 -> V_80 , 270000000 ) ;
if ( V_72 < 0 ) {
F_33 ( & V_70 -> V_60 , L_9 ,
V_72 ) ;
return V_72 ;
}
V_6 -> V_81 = F_39 ( & V_70 -> V_60 , L_10 ) ;
if ( F_30 ( V_6 -> V_81 ) ) {
F_33 ( & V_70 -> V_60 , L_11 ,
F_31 ( V_6 -> V_81 ) ) ;
return F_31 ( V_6 -> V_81 ) ;
}
V_72 = F_40 ( V_6 -> V_60 , V_6 -> V_61 , F_21 , 0 ,
F_41 ( V_6 -> V_60 ) , V_6 ) ;
if ( V_72 < 0 ) {
F_33 ( V_6 -> V_60 , L_12 ,
V_6 -> V_61 , V_72 ) ;
return V_72 ;
}
F_42 ( V_6 -> V_61 ) ;
V_6 -> V_3 . V_82 = F_14 ;
V_6 -> V_3 . V_60 = & V_70 -> V_60 ;
V_72 = F_43 ( & V_6 -> V_3 ) ;
if ( V_72 < 0 )
return V_72 ;
V_9 = F_4 ( V_6 , V_83 ) ;
V_9 &= ~ V_84 ;
F_6 ( V_6 , V_9 , V_83 ) ;
V_9 = F_4 ( V_6 , V_85 ) ;
V_9 = V_86 |
V_87 |
V_88 ;
F_6 ( V_6 , V_9 , V_85 ) ;
V_9 = V_68 | V_67 |
V_66 | V_65 ;
F_6 ( V_6 , V_9 , V_89 ) ;
F_6 ( V_6 , V_9 , V_64 ) ;
F_44 ( & V_90 ) ;
F_45 ( & V_6 -> V_75 , & V_91 ) ;
F_46 ( & V_90 ) ;
F_47 ( V_70 , V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_69 * V_70 )
{
struct V_1 * V_6 = F_49 ( V_70 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_83 ) ;
V_9 |= V_84 ;
F_6 ( V_6 , V_9 , V_83 ) ;
F_50 ( & V_6 -> V_3 ) ;
F_44 ( & V_90 ) ;
F_51 ( & V_6 -> V_75 ) ;
F_46 ( & V_90 ) ;
F_52 ( & V_6 -> V_5 ) ;
F_53 ( V_6 -> V_80 ) ;
F_54 ( V_6 -> V_78 ) ;
F_53 ( V_6 -> V_79 ) ;
return 0 ;
}
struct V_2 * F_55 ( struct V_92 * V_93 )
{
struct V_1 * V_6 ;
F_44 ( & V_90 ) ;
F_56 (dpaux, &dpaux_list, list)
if ( V_93 == V_6 -> V_60 -> V_94 ) {
F_46 ( & V_90 ) ;
return & V_6 -> V_3 ;
}
F_46 ( & V_90 ) ;
return NULL ;
}
int F_57 ( struct V_2 * V_3 , struct V_95 * V_58 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_17 ;
int V_72 ;
V_58 -> V_59 . V_96 = V_97 ;
V_6 -> V_58 = V_58 ;
V_72 = F_58 ( V_6 -> V_81 ) ;
if ( V_72 < 0 )
return V_72 ;
V_17 = V_98 + F_15 ( 250 ) ;
while ( F_59 ( V_98 , V_17 ) ) {
enum V_99 V_18 ;
V_18 = F_60 ( V_3 ) ;
if ( V_18 == V_100 ) {
F_61 ( V_6 -> V_61 ) ;
return 0 ;
}
F_62 ( 1000 , 2000 ) ;
}
return - V_42 ;
}
int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_17 ;
int V_72 ;
F_42 ( V_6 -> V_61 ) ;
V_72 = F_64 ( V_6 -> V_81 ) ;
if ( V_72 < 0 )
return V_72 ;
V_17 = V_98 + F_15 ( 250 ) ;
while ( F_59 ( V_98 , V_17 ) ) {
enum V_99 V_18 ;
V_18 = F_60 ( V_3 ) ;
if ( V_18 == V_101 ) {
V_6 -> V_58 = NULL ;
return 0 ;
}
F_62 ( 1000 , 2000 ) ;
}
return - V_42 ;
}
enum V_99 F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_43 ) ;
if ( V_9 & V_102 )
return V_100 ;
return V_101 ;
}
int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_66 ( 2 ) |
F_67 ( 4 ) |
F_68 ( 0x18 ) |
V_103 |
V_104 ;
F_6 ( V_6 , V_9 , V_85 ) ;
V_9 = F_4 ( V_6 , V_83 ) ;
V_9 &= ~ V_84 ;
F_6 ( V_6 , V_9 , V_83 ) ;
return 0 ;
}
int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_83 ) ;
V_9 |= V_84 ;
F_6 ( V_6 , V_9 , V_83 ) ;
return 0 ;
}
int F_70 ( struct V_2 * V_3 , T_2 V_105 )
{
int V_72 ;
V_72 = F_71 ( V_3 , V_106 ,
V_105 ) ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
int F_72 ( struct V_2 * V_3 , struct V_107 * V_108 ,
T_2 V_109 )
{
T_2 V_110 = V_109 & V_111 ;
T_2 V_18 [ V_112 ] , V_113 [ 4 ] ;
unsigned int V_12 ;
int V_72 ;
V_72 = F_71 ( V_3 , V_114 , V_109 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_110 == V_115 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_108 -> V_116 ; V_12 ++ )
V_113 [ V_12 ] = V_117 |
V_118 |
V_119 |
V_120 ;
V_72 = F_73 ( V_3 , V_121 , V_113 ,
V_108 -> V_116 ) ;
if ( V_72 < 0 )
return V_72 ;
F_62 ( 500 , 1000 ) ;
V_72 = F_74 ( V_3 , V_18 ) ;
if ( V_72 < 0 )
return V_72 ;
switch ( V_110 ) {
case V_122 :
if ( ! F_75 ( V_18 , V_108 -> V_116 ) )
return - V_123 ;
break;
case V_124 :
if ( ! F_76 ( V_18 , V_108 -> V_116 ) )
return - V_123 ;
break;
default:
F_33 ( V_3 -> V_60 , L_13 , V_110 ) ;
return - V_20 ;
}
V_72 = F_71 ( V_3 , V_125 , 0 ) ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
