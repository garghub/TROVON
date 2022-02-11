static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned long F_3 ( struct V_1 * V_4 ,
unsigned long V_5 )
{
return F_4 ( V_4 -> V_6 + ( V_5 << 2 ) ) ;
}
static inline void F_5 ( struct V_1 * V_4 ,
unsigned long V_7 ,
unsigned long V_5 )
{
F_6 ( V_7 , V_4 -> V_6 + ( V_5 << 2 ) ) ;
}
static void F_7 ( struct V_1 * V_4 , const T_1 * V_8 ,
T_2 V_9 )
{
unsigned long V_5 = F_8 ( 0 ) ;
T_2 V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 += 4 ) {
T_2 V_12 = F_9 ( T_2 , V_9 - V_10 , 4 ) ;
unsigned long V_7 = 0 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_7 |= V_8 [ V_10 + V_11 ] << ( V_11 * 8 ) ;
F_5 ( V_4 , V_7 , V_5 ++ ) ;
}
}
static void F_10 ( struct V_1 * V_4 , T_1 * V_8 ,
T_2 V_9 )
{
unsigned long V_5 = F_11 ( 0 ) ;
T_2 V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 += 4 ) {
T_2 V_12 = F_9 ( T_2 , V_9 - V_10 , 4 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_4 , V_5 ++ ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_8 [ V_10 + V_11 ] = V_7 >> ( V_11 * 8 ) ;
}
}
static T_3 F_12 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
unsigned long V_15 = F_13 ( 250 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_16 ;
T_3 V_17 = 0 ;
T_4 V_7 ;
if ( V_14 -> V_9 > 16 )
return - V_18 ;
if ( V_14 -> V_9 < 1 ) {
switch ( V_14 -> V_19 & ~ V_20 ) {
case V_21 :
case V_22 :
V_7 = V_23 ;
break;
default:
return - V_18 ;
}
} else {
V_7 = F_14 ( V_14 -> V_9 - 1 ) ;
}
switch ( V_14 -> V_19 & ~ V_20 ) {
case V_21 :
if ( V_14 -> V_19 & V_20 )
V_7 |= V_24 ;
else
V_7 |= V_25 ;
break;
case V_22 :
if ( V_14 -> V_19 & V_20 )
V_7 |= V_26 ;
else
V_7 |= V_27 ;
break;
case V_28 :
if ( V_14 -> V_19 & V_20 )
V_7 |= V_29 ;
else
V_7 |= V_30 ;
break;
case V_31 :
V_7 |= V_32 ;
break;
case V_33 :
V_7 |= V_34 ;
break;
default:
return - V_18 ;
}
F_5 ( V_4 , V_14 -> V_35 , V_36 ) ;
F_5 ( V_4 , V_7 , V_37 ) ;
if ( ( V_14 -> V_19 & V_22 ) == 0 ) {
F_7 ( V_4 , V_14 -> V_8 , V_14 -> V_9 ) ;
V_17 = V_14 -> V_9 ;
}
V_7 = F_3 ( V_4 , V_37 ) ;
V_7 |= V_38 ;
F_5 ( V_4 , V_7 , V_37 ) ;
V_16 = F_15 ( & V_4 -> V_39 , V_15 ) ;
if ( ! V_16 )
return - V_40 ;
V_7 = F_3 ( V_4 , V_41 ) ;
F_5 ( V_4 , 0xf00 , V_41 ) ;
if ( V_7 & V_42 )
return - V_40 ;
if ( ( V_7 & V_43 ) ||
( V_7 & V_44 ) ||
( V_7 & V_45 ) )
return - V_46 ;
switch ( ( V_7 & V_47 ) >> 16 ) {
case 0x00 :
V_14 -> V_48 = V_49 ;
break;
case 0x01 :
V_14 -> V_48 = V_50 ;
break;
case 0x02 :
V_14 -> V_48 = V_51 ;
break;
case 0x04 :
V_14 -> V_48 = V_52 ;
break;
case 0x08 :
V_14 -> V_48 = V_53 ;
break;
}
if ( ( V_14 -> V_9 > 0 ) && ( V_14 -> V_48 == V_49 ) ) {
if ( V_14 -> V_19 & V_22 ) {
T_2 V_54 = V_7 & V_55 ;
if ( F_16 ( V_54 != V_14 -> V_9 ) )
V_54 = F_9 ( T_2 , V_54 , V_14 -> V_9 ) ;
F_10 ( V_4 , V_14 -> V_8 , V_54 ) ;
V_17 = V_54 ;
}
}
return V_17 ;
}
static T_5 F_17 ( int V_56 , void * V_57 )
{
struct V_1 * V_4 = V_57 ;
T_5 V_17 = V_58 ;
unsigned long V_7 ;
V_7 = F_3 ( V_4 , V_59 ) ;
F_5 ( V_4 , V_7 , V_59 ) ;
if ( V_7 & V_60 ) {
if ( V_4 -> V_61 ) {
F_18 ( V_4 -> V_61 -> V_62 . V_63 ) ;
}
}
if ( V_7 & V_64 ) {
if ( V_4 -> V_61 )
F_18 ( V_4 -> V_61 -> V_62 . V_63 ) ;
}
if ( V_7 & V_65 ) {
}
if ( V_7 & V_66 )
V_39 ( & V_4 -> V_39 ) ;
return V_17 ;
}
static int F_19 ( struct V_67 * V_68 )
{
struct V_1 * V_4 ;
struct V_69 * V_6 ;
unsigned long V_7 ;
int V_70 ;
V_4 = F_20 ( & V_68 -> V_63 , sizeof( * V_4 ) , V_71 ) ;
if ( ! V_4 )
return - V_72 ;
F_21 ( & V_4 -> V_39 ) ;
F_22 ( & V_4 -> V_73 ) ;
V_4 -> V_63 = & V_68 -> V_63 ;
V_6 = F_23 ( V_68 , V_74 , 0 ) ;
V_4 -> V_6 = F_24 ( & V_68 -> V_63 , V_6 ) ;
if ( F_25 ( V_4 -> V_6 ) )
return F_26 ( V_4 -> V_6 ) ;
V_4 -> V_56 = F_27 ( V_68 , 0 ) ;
if ( V_4 -> V_56 < 0 ) {
F_28 ( & V_68 -> V_63 , L_1 ) ;
return - V_75 ;
}
V_4 -> V_76 = F_29 ( & V_68 -> V_63 , L_2 ) ;
if ( F_25 ( V_4 -> V_76 ) )
return F_26 ( V_4 -> V_76 ) ;
V_4 -> V_77 = F_30 ( & V_68 -> V_63 , NULL ) ;
if ( F_25 ( V_4 -> V_77 ) )
return F_26 ( V_4 -> V_77 ) ;
V_70 = F_31 ( V_4 -> V_77 ) ;
if ( V_70 < 0 )
return V_70 ;
F_32 ( V_4 -> V_76 ) ;
V_4 -> V_78 = F_30 ( & V_68 -> V_63 , L_3 ) ;
if ( F_25 ( V_4 -> V_78 ) )
return F_26 ( V_4 -> V_78 ) ;
V_70 = F_31 ( V_4 -> V_78 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_33 ( V_4 -> V_78 , 270000000 ) ;
if ( V_70 < 0 ) {
F_28 ( & V_68 -> V_63 , L_4 ,
V_70 ) ;
return V_70 ;
}
V_4 -> V_79 = F_34 ( & V_68 -> V_63 , L_5 ) ;
if ( F_25 ( V_4 -> V_79 ) )
return F_26 ( V_4 -> V_79 ) ;
V_70 = F_35 ( V_4 -> V_63 , V_4 -> V_56 , F_17 , 0 ,
F_36 ( V_4 -> V_63 ) , V_4 ) ;
if ( V_70 < 0 ) {
F_28 ( V_4 -> V_63 , L_6 ,
V_4 -> V_56 , V_70 ) ;
return V_70 ;
}
V_4 -> V_3 . V_80 = F_12 ;
V_4 -> V_3 . V_63 = & V_68 -> V_63 ;
V_70 = F_37 ( & V_4 -> V_3 ) ;
if ( V_70 < 0 )
return V_70 ;
V_7 = V_66 | V_65 |
V_64 | V_60 ;
F_5 ( V_4 , V_7 , V_81 ) ;
F_5 ( V_4 , V_7 , V_59 ) ;
F_38 ( & V_82 ) ;
F_39 ( & V_4 -> V_73 , & V_83 ) ;
F_40 ( & V_82 ) ;
F_41 ( V_68 , V_4 ) ;
return 0 ;
}
static int F_42 ( struct V_67 * V_68 )
{
struct V_1 * V_4 = F_43 ( V_68 ) ;
F_44 ( & V_4 -> V_3 ) ;
F_38 ( & V_82 ) ;
F_45 ( & V_4 -> V_73 ) ;
F_40 ( & V_82 ) ;
F_46 ( V_4 -> V_78 ) ;
F_47 ( V_4 -> V_76 ) ;
F_46 ( V_4 -> V_77 ) ;
return 0 ;
}
struct V_1 * F_48 ( struct V_84 * V_85 )
{
struct V_1 * V_4 ;
F_38 ( & V_82 ) ;
F_49 (dpaux, &dpaux_list, list)
if ( V_85 == V_4 -> V_63 -> V_86 ) {
F_40 ( & V_82 ) ;
return V_4 ;
}
F_40 ( & V_82 ) ;
return NULL ;
}
int F_50 ( struct V_1 * V_4 , struct V_87 * V_61 )
{
unsigned long V_15 ;
int V_70 ;
V_4 -> V_61 = V_61 ;
V_70 = F_51 ( V_4 -> V_79 ) ;
if ( V_70 < 0 )
return V_70 ;
V_15 = V_88 + F_13 ( 250 ) ;
while ( F_52 ( V_88 , V_15 ) ) {
enum V_89 V_16 ;
V_16 = F_53 ( V_4 ) ;
if ( V_16 == V_90 )
return 0 ;
F_54 ( 1000 , 2000 ) ;
}
return - V_40 ;
}
int F_55 ( struct V_1 * V_4 )
{
unsigned long V_15 ;
int V_70 ;
V_70 = F_56 ( V_4 -> V_79 ) ;
if ( V_70 < 0 )
return V_70 ;
V_15 = V_88 + F_13 ( 250 ) ;
while ( F_52 ( V_88 , V_15 ) ) {
enum V_89 V_16 ;
V_16 = F_53 ( V_4 ) ;
if ( V_16 == V_91 ) {
V_4 -> V_61 = NULL ;
return 0 ;
}
F_54 ( 1000 , 2000 ) ;
}
return - V_40 ;
}
enum V_89 F_53 ( struct V_1 * V_4 )
{
unsigned long V_7 ;
V_7 = F_3 ( V_4 , V_41 ) ;
if ( V_7 & V_92 )
return V_90 ;
return V_91 ;
}
int F_57 ( struct V_1 * V_4 )
{
unsigned long V_7 ;
V_7 = F_58 ( 2 ) |
F_59 ( 4 ) |
F_60 ( 0x18 ) |
V_93 |
V_94 ;
F_5 ( V_4 , V_7 , V_95 ) ;
V_7 = F_3 ( V_4 , V_96 ) ;
V_7 &= ~ V_97 ;
F_5 ( V_4 , V_7 , V_96 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_4 )
{
unsigned long V_7 ;
V_7 = F_3 ( V_4 , V_96 ) ;
V_7 |= V_97 ;
F_5 ( V_4 , V_7 , V_96 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_4 , T_1 V_98 )
{
int V_70 ;
V_70 = F_63 ( & V_4 -> V_3 , V_99 ,
V_98 ) ;
if ( V_70 < 0 )
return V_70 ;
return 0 ;
}
int F_64 ( struct V_1 * V_4 , struct V_100 * V_101 ,
T_1 V_102 )
{
T_1 V_103 = V_102 & V_104 ;
T_1 V_16 [ V_105 ] , V_106 [ 4 ] ;
unsigned int V_10 ;
int V_70 ;
V_70 = F_63 ( & V_4 -> V_3 , V_107 , V_102 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_103 == V_108 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_101 -> V_109 ; V_10 ++ )
V_106 [ V_10 ] = V_110 |
V_111 |
V_112 |
V_113 ;
V_70 = F_65 ( & V_4 -> V_3 , V_114 , V_106 ,
V_101 -> V_109 ) ;
if ( V_70 < 0 )
return V_70 ;
F_54 ( 500 , 1000 ) ;
V_70 = F_66 ( & V_4 -> V_3 , V_16 ) ;
if ( V_70 < 0 )
return V_70 ;
switch ( V_103 ) {
case V_115 :
if ( ! F_67 ( V_16 , V_101 -> V_109 ) )
return - V_116 ;
break;
case V_117 :
if ( ! F_68 ( V_16 , V_101 -> V_109 ) )
return - V_116 ;
break;
default:
F_28 ( V_4 -> V_63 , L_7 , V_103 ) ;
return - V_18 ;
}
V_70 = F_63 ( & V_4 -> V_3 , V_118 , 0 ) ;
if ( V_70 < 0 )
return V_70 ;
return 0 ;
}
