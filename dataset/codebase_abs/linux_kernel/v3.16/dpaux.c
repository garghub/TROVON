static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline unsigned long F_4 ( struct V_1 * V_6 ,
unsigned long V_7 )
{
return F_5 ( V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static inline void F_6 ( struct V_1 * V_6 ,
unsigned long V_9 ,
unsigned long V_7 )
{
F_7 ( V_9 , V_6 -> V_8 + ( V_7 << 2 ) ) ;
}
static void F_8 ( struct V_1 * V_6 , const T_1 * V_10 ,
T_2 V_11 )
{
unsigned long V_7 = F_9 ( 0 ) ;
T_2 V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 += 4 ) {
T_2 V_14 = F_10 ( T_2 , V_11 - V_12 , 4 ) ;
unsigned long V_9 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
V_9 |= V_10 [ V_12 + V_13 ] << ( V_13 * 8 ) ;
F_6 ( V_6 , V_9 , V_7 ++ ) ;
}
}
static void F_11 ( struct V_1 * V_6 , T_1 * V_10 ,
T_2 V_11 )
{
unsigned long V_7 = F_12 ( 0 ) ;
T_2 V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 += 4 ) {
T_2 V_14 = F_10 ( T_2 , V_11 - V_12 , 4 ) ;
unsigned long V_9 ;
V_9 = F_4 ( V_6 , V_7 ++ ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
V_10 [ V_12 + V_13 ] = V_9 >> ( V_13 * 8 ) ;
}
}
static T_3 F_13 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
unsigned long V_17 = F_14 ( 250 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_18 ;
T_3 V_19 = 0 ;
T_4 V_9 ;
if ( V_16 -> V_11 > 16 )
return - V_20 ;
if ( V_16 -> V_11 < 1 ) {
switch ( V_16 -> V_21 & ~ V_22 ) {
case V_23 :
case V_24 :
V_9 = V_25 ;
break;
default:
return - V_20 ;
}
} else {
V_9 = F_15 ( V_16 -> V_11 - 1 ) ;
}
switch ( V_16 -> V_21 & ~ V_22 ) {
case V_23 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_26 ;
else
V_9 |= V_27 ;
break;
case V_24 :
if ( V_16 -> V_21 & V_22 )
V_9 |= V_28 ;
else
V_9 |= V_29 ;
break;
case V_30 :
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
if ( ( V_16 -> V_21 & V_24 ) == 0 ) {
F_8 ( V_6 , V_16 -> V_10 , V_16 -> V_11 ) ;
V_19 = V_16 -> V_11 ;
}
V_9 = F_4 ( V_6 , V_39 ) ;
V_9 |= V_40 ;
F_6 ( V_6 , V_9 , V_39 ) ;
V_18 = F_16 ( & V_6 -> V_41 , V_17 ) ;
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
if ( V_16 -> V_21 & V_24 ) {
T_2 V_56 = V_9 & V_57 ;
if ( F_17 ( V_56 != V_16 -> V_11 ) )
V_56 = F_10 ( T_2 , V_56 , V_16 -> V_11 ) ;
F_11 ( V_6 , V_16 -> V_10 , V_56 ) ;
V_19 = V_56 ;
}
}
return V_19 ;
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_58 )
F_19 ( V_6 -> V_58 -> V_59 . V_60 ) ;
}
static T_5 F_20 ( int V_61 , void * V_62 )
{
struct V_1 * V_6 = V_62 ;
T_5 V_19 = V_63 ;
unsigned long V_9 ;
V_9 = F_4 ( V_6 , V_64 ) ;
F_6 ( V_6 , V_9 , V_64 ) ;
if ( V_9 & ( V_65 | V_66 ) )
F_21 ( & V_6 -> V_5 ) ;
if ( V_9 & V_67 ) {
}
if ( V_9 & V_68 )
V_41 ( & V_6 -> V_41 ) ;
return V_19 ;
}
static int F_22 ( struct V_69 * V_70 )
{
struct V_1 * V_6 ;
struct V_71 * V_8 ;
unsigned long V_9 ;
int V_72 ;
V_6 = F_23 ( & V_70 -> V_60 , sizeof( * V_6 ) , V_73 ) ;
if ( ! V_6 )
return - V_74 ;
F_24 ( & V_6 -> V_5 , F_18 ) ;
F_25 ( & V_6 -> V_41 ) ;
F_26 ( & V_6 -> V_75 ) ;
V_6 -> V_60 = & V_70 -> V_60 ;
V_8 = F_27 ( V_70 , V_76 , 0 ) ;
V_6 -> V_8 = F_28 ( & V_70 -> V_60 , V_8 ) ;
if ( F_29 ( V_6 -> V_8 ) )
return F_30 ( V_6 -> V_8 ) ;
V_6 -> V_61 = F_31 ( V_70 , 0 ) ;
if ( V_6 -> V_61 < 0 ) {
F_32 ( & V_70 -> V_60 , L_1 ) ;
return - V_77 ;
}
V_6 -> V_78 = F_33 ( & V_70 -> V_60 , L_2 ) ;
if ( F_29 ( V_6 -> V_78 ) )
return F_30 ( V_6 -> V_78 ) ;
V_6 -> V_79 = F_34 ( & V_70 -> V_60 , NULL ) ;
if ( F_29 ( V_6 -> V_79 ) )
return F_30 ( V_6 -> V_79 ) ;
V_72 = F_35 ( V_6 -> V_79 ) ;
if ( V_72 < 0 )
return V_72 ;
F_36 ( V_6 -> V_78 ) ;
V_6 -> V_80 = F_34 ( & V_70 -> V_60 , L_3 ) ;
if ( F_29 ( V_6 -> V_80 ) )
return F_30 ( V_6 -> V_80 ) ;
V_72 = F_35 ( V_6 -> V_80 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_37 ( V_6 -> V_80 , 270000000 ) ;
if ( V_72 < 0 ) {
F_32 ( & V_70 -> V_60 , L_4 ,
V_72 ) ;
return V_72 ;
}
V_6 -> V_81 = F_38 ( & V_70 -> V_60 , L_5 ) ;
if ( F_29 ( V_6 -> V_81 ) )
return F_30 ( V_6 -> V_81 ) ;
V_72 = F_39 ( V_6 -> V_60 , V_6 -> V_61 , F_20 , 0 ,
F_40 ( V_6 -> V_60 ) , V_6 ) ;
if ( V_72 < 0 ) {
F_32 ( V_6 -> V_60 , L_6 ,
V_6 -> V_61 , V_72 ) ;
return V_72 ;
}
V_6 -> V_3 . V_82 = F_13 ;
V_6 -> V_3 . V_60 = & V_70 -> V_60 ;
V_72 = F_41 ( & V_6 -> V_3 ) ;
if ( V_72 < 0 )
return V_72 ;
V_9 = V_68 | V_67 |
V_66 | V_65 ;
F_6 ( V_6 , V_9 , V_83 ) ;
F_6 ( V_6 , V_9 , V_64 ) ;
F_42 ( & V_84 ) ;
F_43 ( & V_6 -> V_75 , & V_85 ) ;
F_44 ( & V_84 ) ;
F_45 ( V_70 , V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_69 * V_70 )
{
struct V_1 * V_6 = F_47 ( V_70 ) ;
F_48 ( & V_6 -> V_3 ) ;
F_42 ( & V_84 ) ;
F_49 ( & V_6 -> V_75 ) ;
F_44 ( & V_84 ) ;
F_50 ( & V_6 -> V_5 ) ;
F_51 ( V_6 -> V_80 ) ;
F_52 ( V_6 -> V_78 ) ;
F_51 ( V_6 -> V_79 ) ;
return 0 ;
}
struct V_1 * F_53 ( struct V_86 * V_87 )
{
struct V_1 * V_6 ;
F_42 ( & V_84 ) ;
F_54 (dpaux, &dpaux_list, list)
if ( V_87 == V_6 -> V_60 -> V_88 ) {
F_44 ( & V_84 ) ;
return V_6 ;
}
F_44 ( & V_84 ) ;
return NULL ;
}
int F_55 ( struct V_1 * V_6 , struct V_89 * V_58 )
{
unsigned long V_17 ;
int V_72 ;
V_58 -> V_59 . V_90 = V_91 ;
V_6 -> V_58 = V_58 ;
V_72 = F_56 ( V_6 -> V_81 ) ;
if ( V_72 < 0 )
return V_72 ;
V_17 = V_92 + F_14 ( 250 ) ;
while ( F_57 ( V_92 , V_17 ) ) {
enum V_93 V_18 ;
V_18 = F_58 ( V_6 ) ;
if ( V_18 == V_94 )
return 0 ;
F_59 ( 1000 , 2000 ) ;
}
return - V_42 ;
}
int F_60 ( struct V_1 * V_6 )
{
unsigned long V_17 ;
int V_72 ;
V_72 = F_61 ( V_6 -> V_81 ) ;
if ( V_72 < 0 )
return V_72 ;
V_17 = V_92 + F_14 ( 250 ) ;
while ( F_57 ( V_92 , V_17 ) ) {
enum V_93 V_18 ;
V_18 = F_58 ( V_6 ) ;
if ( V_18 == V_95 ) {
V_6 -> V_58 = NULL ;
return 0 ;
}
F_59 ( 1000 , 2000 ) ;
}
return - V_42 ;
}
enum V_93 F_58 ( struct V_1 * V_6 )
{
unsigned long V_9 ;
V_9 = F_4 ( V_6 , V_43 ) ;
if ( V_9 & V_96 )
return V_94 ;
return V_95 ;
}
int F_62 ( struct V_1 * V_6 )
{
unsigned long V_9 ;
V_9 = F_63 ( 2 ) |
F_64 ( 4 ) |
F_65 ( 0x18 ) |
V_97 |
V_98 ;
F_6 ( V_6 , V_9 , V_99 ) ;
V_9 = F_4 ( V_6 , V_100 ) ;
V_9 &= ~ V_101 ;
F_6 ( V_6 , V_9 , V_100 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_6 )
{
unsigned long V_9 ;
V_9 = F_4 ( V_6 , V_100 ) ;
V_9 |= V_101 ;
F_6 ( V_6 , V_9 , V_100 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_6 , T_1 V_102 )
{
int V_72 ;
V_72 = F_68 ( & V_6 -> V_3 , V_103 ,
V_102 ) ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
int F_69 ( struct V_1 * V_6 , struct V_104 * V_105 ,
T_1 V_106 )
{
T_1 V_107 = V_106 & V_108 ;
T_1 V_18 [ V_109 ] , V_110 [ 4 ] ;
unsigned int V_12 ;
int V_72 ;
V_72 = F_68 ( & V_6 -> V_3 , V_111 , V_106 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_107 == V_112 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_105 -> V_113 ; V_12 ++ )
V_110 [ V_12 ] = V_114 |
V_115 |
V_116 |
V_117 ;
V_72 = F_70 ( & V_6 -> V_3 , V_118 , V_110 ,
V_105 -> V_113 ) ;
if ( V_72 < 0 )
return V_72 ;
F_59 ( 500 , 1000 ) ;
V_72 = F_71 ( & V_6 -> V_3 , V_18 ) ;
if ( V_72 < 0 )
return V_72 ;
switch ( V_107 ) {
case V_119 :
if ( ! F_72 ( V_18 , V_105 -> V_113 ) )
return - V_120 ;
break;
case V_121 :
if ( ! F_73 ( V_18 , V_105 -> V_113 ) )
return - V_120 ;
break;
default:
F_32 ( V_6 -> V_60 , L_7 , V_107 ) ;
return - V_20 ;
}
V_72 = F_68 ( & V_6 -> V_3 , V_122 , 0 ) ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
