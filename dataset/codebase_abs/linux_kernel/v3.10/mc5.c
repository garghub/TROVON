static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_3 , V_2 ) ;
return F_3 ( V_1 , V_4 ,
V_5 , 1 , V_6 , 1 ) ;
}
static inline void F_4 ( struct V_1 * V_1 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 )
{
F_2 ( V_1 , V_10 , V_7 ) ;
F_2 ( V_1 , V_11 , V_8 ) ;
F_2 ( V_1 , V_12 , V_9 ) ;
}
static inline void F_5 ( struct V_1 * V_1 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 )
{
F_2 ( V_1 , V_13 , V_7 ) ;
F_2 ( V_1 , V_14 , V_8 ) ;
F_2 ( V_1 , V_15 , V_9 ) ;
}
static inline void F_6 ( struct V_1 * V_1 , T_1 * V_7 , T_1 * V_8 ,
T_1 * V_9 )
{
* V_7 = F_7 ( V_1 , V_16 ) ;
* V_8 = F_7 ( V_1 , V_17 ) ;
* V_9 = F_7 ( V_1 , V_18 ) ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_19 , T_1 V_2 )
{
F_2 ( V_1 , V_10 , V_19 ) ;
if ( F_1 ( V_1 , V_2 ) == 0 )
return 0 ;
F_9 ( V_1 , L_1 ,
V_19 ) ;
return - 1 ;
}
static int F_10 ( struct V_20 * V_20 , T_1 V_21 ,
T_1 V_22 , T_1 V_23 ,
int V_24 )
{
unsigned int V_25 ;
struct V_1 * V_26 = V_20 -> V_1 ;
unsigned int V_27 = V_20 -> V_28 ;
unsigned int V_29 = F_7 ( V_26 , V_30 ) ;
if ( V_20 -> V_31 == V_32 ) {
V_27 *= 2 ;
V_29 *= 2 ;
}
F_5 ( V_26 , 0 , 0 , 0 ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
if ( F_8 ( V_26 , V_22 + ( V_25 << V_24 ) ,
V_23 ) )
return - 1 ;
F_5 ( V_26 , 0xffffffff , 0xffffffff , 0xff ) ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_25 == V_29 )
F_2 ( V_26 , V_13 ,
V_20 -> V_31 == V_32 ?
0xfffffff9 : 0xfffffffd ) ;
if ( F_8 ( V_26 , V_21 + ( V_25 << V_24 ) ,
V_23 ) )
return - 1 ;
}
return 0 ;
}
static int F_11 ( struct V_20 * V_20 )
{
int V_25 ;
struct V_1 * V_26 = V_20 -> V_1 ;
F_2 ( V_26 , V_33 ,
F_12 ( 0x15 ) | F_13 ( 0x15 ) | F_14 ( 0x15 ) ) ;
F_2 ( V_26 , V_34 , 2 ) ;
F_2 ( V_26 , V_35 , V_36 ) ;
F_2 ( V_26 , V_37 , V_36 ) ;
F_2 ( V_26 , V_38 , V_39 ) ;
F_2 ( V_26 , V_40 , V_41 ) ;
F_2 ( V_26 , V_42 , V_39 | 0x6000 ) ;
F_2 ( V_26 , V_43 , V_41 ) ;
F_2 ( V_26 , V_44 , V_39 ) ;
F_2 ( V_26 , V_45 , V_41 ) ;
F_2 ( V_26 , V_46 , V_39 ) ;
F_2 ( V_26 , V_47 , V_39 | 0x7000 ) ;
F_2 ( V_26 , V_48 , V_36 ) ;
F_2 ( V_26 , V_49 , V_50 ) ;
F_2 ( V_26 , V_51 , V_52 ) ;
F_5 ( V_26 , V_53 , 0 , 0 ) ;
if ( F_8 ( V_26 , V_54 , V_36 ) )
goto V_55;
F_5 ( V_26 , 0xffffffff , 0xffffffff , 0 ) ;
if ( F_8 ( V_26 , V_56 , V_36 ) ||
F_8 ( V_26 , V_57 , V_36 ) )
goto V_55;
for ( V_25 = 0 ; V_25 < 32 ; ++ V_25 ) {
if ( V_25 >= 12 && V_25 < 15 )
F_5 ( V_26 , 0xfffffff9 , 0xffffffff , 0xff ) ;
else if ( V_25 == 15 )
F_5 ( V_26 , 0xfffffff9 , 0xffff8007 , 0xff ) ;
else
F_5 ( V_26 , 0xffffffff , 0xffffffff , 0xff ) ;
if ( F_8 ( V_26 , V_58 + V_25 , V_36 ) )
goto V_55;
}
F_5 ( V_26 , 1 , 0 , 0 ) ;
if ( F_8 ( V_26 , V_59 , V_36 ) )
goto V_55;
return F_10 ( V_20 , V_60 ,
V_61 , V_36 , 0 ) ;
V_55:
return - V_62 ;
}
static int F_15 ( struct V_20 * V_20 )
{
int V_25 ;
struct V_1 * V_26 = V_20 -> V_1 ;
F_2 ( V_26 , V_33 ,
V_26 -> V_63 . V_64 == 0 ? F_12 ( 0xd ) | F_14 ( 0x11 ) :
F_12 ( 0xd ) | F_14 ( 0x12 ) ) ;
F_2 ( V_26 , V_35 , V_65 ) ;
F_2 ( V_26 , V_37 , V_65 ) ;
F_2 ( V_26 , V_38 ,
V_66 | 0x3800 ) ;
F_2 ( V_26 , V_42 , V_66 ) ;
F_2 ( V_26 , V_44 , V_66 | 0x3800 ) ;
F_2 ( V_26 , V_46 , V_66 | 0x3800 ) ;
F_2 ( V_26 , V_47 , V_66 | 0x800 ) ;
F_2 ( V_26 , V_48 , V_65 ) ;
F_2 ( V_26 , V_49 , V_67 ) ;
F_2 ( V_26 , V_34 , 3 ) ;
F_2 ( V_26 , V_51 , V_52 ) ;
F_5 ( V_26 , 0xffffffff , 0xffffffff , 0xff ) ;
for ( V_25 = 0 ; V_25 < 7 ; ++ V_25 )
if ( F_8 ( V_26 , V_68 + V_25 , V_65 ) )
goto V_55;
for ( V_25 = 0 ; V_25 < 4 ; ++ V_25 )
if ( F_8 ( V_26 , V_69 + V_25 , V_65 ) )
goto V_55;
F_5 ( V_26 , 0xfffffff9 , 0xffffffff , 0xff ) ;
if ( F_8 ( V_26 , V_70 , V_65 ) ||
F_8 ( V_26 , V_70 + 1 , V_65 ) ||
F_8 ( V_26 , V_70 + 4 , V_65 ) )
goto V_55;
F_5 ( V_26 , 0xfffffff9 , 0xffff8007 , 0xff ) ;
if ( F_8 ( V_26 , V_70 + 5 , V_65 ) )
goto V_55;
F_5 ( V_26 , 0xf0000000 , 0 , 0 ) ;
if ( F_8 ( V_26 , V_71 , V_65 ) )
goto V_55;
return F_10 ( V_20 , V_72 ,
V_73 , V_65 , 1 ) ;
V_55:
return - V_62 ;
}
static inline void F_16 ( const struct V_20 * V_20 )
{
F_2 ( V_20 -> V_1 , V_74 ,
F_17 ( V_20 -> V_31 == V_75 ) | V_76 ) ;
}
static void F_18 ( const struct V_20 * V_20 )
{
F_2 ( V_20 -> V_1 , V_74 ,
F_17 ( V_20 -> V_31 == V_75 ) |
F_19 ( V_20 -> V_31 == V_75 ) |
F_20 ( V_20 -> V_77 ) | V_78 ) ;
}
int F_21 ( struct V_20 * V_20 , unsigned int V_79 , unsigned int V_80 ,
unsigned int V_81 )
{
T_1 V_82 ;
int V_55 ;
unsigned int V_28 = V_20 -> V_28 ;
struct V_1 * V_26 = V_20 -> V_1 ;
if ( ! V_28 )
return 0 ;
if ( V_81 > V_83 || V_81 + V_79 + V_80 > V_28 )
return - V_84 ;
V_82 = F_7 ( V_26 , V_74 ) & ~ V_85 ;
V_82 |= F_17 ( V_20 -> V_31 == V_75 ) | V_86 ;
F_2 ( V_26 , V_74 , V_82 ) ;
if ( F_3 ( V_26 , V_74 , V_87 , 1 , 500 , 0 ) ) {
F_9 ( V_26 , L_2 ) ;
return - 1 ;
}
F_2 ( V_26 , V_88 , V_28 - V_81 ) ;
F_2 ( V_26 , V_89 ,
V_28 - V_81 - V_80 ) ;
F_2 ( V_26 , V_30 ,
V_28 - V_81 - V_80 - V_79 ) ;
V_20 -> V_77 = 1 ;
F_2 ( V_26 , V_11 , 0 ) ;
F_2 ( V_26 , V_12 , 0 ) ;
F_16 ( V_20 ) ;
switch ( V_20 -> V_90 ) {
case V_91 :
V_55 = F_11 ( V_20 ) ;
break;
case V_92 :
V_55 = F_15 ( V_20 ) ;
break;
default:
F_9 ( V_26 , L_3 , V_20 -> V_90 ) ;
V_55 = - V_84 ;
break;
}
F_18 ( V_20 ) ;
return V_55 ;
}
void F_22 ( struct V_20 * V_20 )
{
struct V_1 * V_26 = V_20 -> V_1 ;
T_1 V_93 = F_7 ( V_26 , V_94 ) ;
if ( ( V_93 & V_95 ) && V_20 -> V_77 ) {
F_23 ( V_26 , L_4 ) ;
V_20 -> V_96 . V_97 ++ ;
}
if ( V_93 & V_98 ) {
F_23 ( V_26 , L_5 ) ;
V_20 -> V_96 . V_99 ++ ;
}
if ( V_93 & V_100 ) {
F_23 ( V_26 , L_6 ) ;
V_20 -> V_96 . V_101 ++ ;
}
if ( V_93 & V_102 )
V_20 -> V_96 . V_103 ++ ;
if ( V_93 & V_104 )
V_20 -> V_96 . V_105 ++ ;
if ( V_93 & V_106 )
V_20 -> V_96 . V_107 ++ ;
if ( V_93 & V_108 )
V_20 -> V_96 . V_109 ++ ;
if ( V_93 & V_110 )
F_24 ( V_26 ) ;
F_2 ( V_26 , V_94 , V_93 ) ;
}
void F_25 ( struct V_1 * V_1 , struct V_20 * V_20 , int V_31 )
{
#define F_26 * 1024
static unsigned int V_111 [] = {
64 F_26 , 128 F_26 , 256 F_26 , 32 F_26
} ;
#undef F_26
T_1 V_82 = F_7 ( V_1 , V_74 ) ;
V_20 -> V_1 = V_1 ;
V_20 -> V_31 = ( unsigned char ) V_31 ;
V_20 -> V_90 = ( unsigned char ) F_27 ( V_82 ) ;
if ( V_82 & V_112 )
V_20 -> V_90 |= 4 ;
V_20 -> V_28 = V_111 [ F_28 ( V_82 ) ] ;
if ( V_31 == V_32 )
V_20 -> V_28 /= 2 ;
}
