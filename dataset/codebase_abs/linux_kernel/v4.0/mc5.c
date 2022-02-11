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
static int F_5 ( struct V_1 * V_1 , T_1 V_13 , T_1 V_2 )
{
F_2 ( V_1 , V_14 , V_13 ) ;
if ( F_1 ( V_1 , V_2 ) == 0 )
return 0 ;
F_6 ( V_1 , L_1 ,
V_13 ) ;
return - 1 ;
}
static int F_7 ( struct V_15 * V_15 , T_1 V_16 ,
T_1 V_17 , T_1 V_18 ,
int V_19 )
{
unsigned int V_20 ;
struct V_1 * V_21 = V_15 -> V_1 ;
unsigned int V_22 = V_15 -> V_23 ;
unsigned int V_24 = F_8 ( V_21 , V_25 ) ;
if ( V_15 -> V_26 == V_27 ) {
V_22 *= 2 ;
V_24 *= 2 ;
}
F_4 ( V_21 , 0 , 0 , 0 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ )
if ( F_5 ( V_21 , V_17 + ( V_20 << V_19 ) ,
V_18 ) )
return - 1 ;
F_4 ( V_21 , 0xffffffff , 0xffffffff , 0xff ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( V_20 == V_24 )
F_2 ( V_21 , V_10 ,
V_15 -> V_26 == V_27 ?
0xfffffff9 : 0xfffffffd ) ;
if ( F_5 ( V_21 , V_16 + ( V_20 << V_19 ) ,
V_18 ) )
return - 1 ;
}
return 0 ;
}
static int F_9 ( struct V_15 * V_15 )
{
int V_20 ;
struct V_1 * V_21 = V_15 -> V_1 ;
F_2 ( V_21 , V_28 ,
F_10 ( 0x15 ) | F_11 ( 0x15 ) | F_12 ( 0x15 ) ) ;
F_2 ( V_21 , V_29 , 2 ) ;
F_2 ( V_21 , V_30 , V_31 ) ;
F_2 ( V_21 , V_32 , V_31 ) ;
F_2 ( V_21 , V_33 , V_34 ) ;
F_2 ( V_21 , V_35 , V_36 ) ;
F_2 ( V_21 , V_37 , V_34 | 0x6000 ) ;
F_2 ( V_21 , V_38 , V_36 ) ;
F_2 ( V_21 , V_39 , V_34 ) ;
F_2 ( V_21 , V_40 , V_36 ) ;
F_2 ( V_21 , V_41 , V_34 ) ;
F_2 ( V_21 , V_42 , V_34 | 0x7000 ) ;
F_2 ( V_21 , V_43 , V_31 ) ;
F_2 ( V_21 , V_44 , V_45 ) ;
F_2 ( V_21 , V_46 , V_47 ) ;
F_4 ( V_21 , V_48 , 0 , 0 ) ;
if ( F_5 ( V_21 , V_49 , V_31 ) )
goto V_50;
F_4 ( V_21 , 0xffffffff , 0xffffffff , 0 ) ;
if ( F_5 ( V_21 , V_51 , V_31 ) ||
F_5 ( V_21 , V_52 , V_31 ) )
goto V_50;
for ( V_20 = 0 ; V_20 < 32 ; ++ V_20 ) {
if ( V_20 >= 12 && V_20 < 15 )
F_4 ( V_21 , 0xfffffff9 , 0xffffffff , 0xff ) ;
else if ( V_20 == 15 )
F_4 ( V_21 , 0xfffffff9 , 0xffff8007 , 0xff ) ;
else
F_4 ( V_21 , 0xffffffff , 0xffffffff , 0xff ) ;
if ( F_5 ( V_21 , V_53 + V_20 , V_31 ) )
goto V_50;
}
F_4 ( V_21 , 1 , 0 , 0 ) ;
if ( F_5 ( V_21 , V_54 , V_31 ) )
goto V_50;
return F_7 ( V_15 , V_55 ,
V_56 , V_31 , 0 ) ;
V_50:
return - V_57 ;
}
static int F_13 ( struct V_15 * V_15 )
{
int V_20 ;
struct V_1 * V_21 = V_15 -> V_1 ;
F_2 ( V_21 , V_28 ,
V_21 -> V_58 . V_59 == 0 ? F_10 ( 0xd ) | F_12 ( 0x11 ) :
F_10 ( 0xd ) | F_12 ( 0x12 ) ) ;
F_2 ( V_21 , V_30 , V_60 ) ;
F_2 ( V_21 , V_32 , V_60 ) ;
F_2 ( V_21 , V_33 ,
V_61 | 0x3800 ) ;
F_2 ( V_21 , V_37 , V_61 ) ;
F_2 ( V_21 , V_39 , V_61 | 0x3800 ) ;
F_2 ( V_21 , V_41 , V_61 | 0x3800 ) ;
F_2 ( V_21 , V_42 , V_61 | 0x800 ) ;
F_2 ( V_21 , V_43 , V_60 ) ;
F_2 ( V_21 , V_44 , V_62 ) ;
F_2 ( V_21 , V_29 , 3 ) ;
F_2 ( V_21 , V_46 , V_47 ) ;
F_4 ( V_21 , 0xffffffff , 0xffffffff , 0xff ) ;
for ( V_20 = 0 ; V_20 < 7 ; ++ V_20 )
if ( F_5 ( V_21 , V_63 + V_20 , V_60 ) )
goto V_50;
for ( V_20 = 0 ; V_20 < 4 ; ++ V_20 )
if ( F_5 ( V_21 , V_64 + V_20 , V_60 ) )
goto V_50;
F_4 ( V_21 , 0xfffffff9 , 0xffffffff , 0xff ) ;
if ( F_5 ( V_21 , V_65 , V_60 ) ||
F_5 ( V_21 , V_65 + 1 , V_60 ) ||
F_5 ( V_21 , V_65 + 4 , V_60 ) )
goto V_50;
F_4 ( V_21 , 0xfffffff9 , 0xffff8007 , 0xff ) ;
if ( F_5 ( V_21 , V_65 + 5 , V_60 ) )
goto V_50;
F_4 ( V_21 , 0xf0000000 , 0 , 0 ) ;
if ( F_5 ( V_21 , V_66 , V_60 ) )
goto V_50;
return F_7 ( V_15 , V_67 ,
V_68 , V_60 , 1 ) ;
V_50:
return - V_57 ;
}
static inline void F_14 ( const struct V_15 * V_15 )
{
F_2 ( V_15 -> V_1 , V_69 ,
F_15 ( V_15 -> V_26 == V_70 ) | V_71 ) ;
}
static void F_16 ( const struct V_15 * V_15 )
{
F_2 ( V_15 -> V_1 , V_69 ,
F_15 ( V_15 -> V_26 == V_70 ) |
F_17 ( V_15 -> V_26 == V_70 ) |
F_18 ( V_15 -> V_72 ) | V_73 ) ;
}
int F_19 ( struct V_15 * V_15 , unsigned int V_74 , unsigned int V_75 ,
unsigned int V_76 )
{
T_1 V_77 ;
int V_50 ;
unsigned int V_23 = V_15 -> V_23 ;
struct V_1 * V_21 = V_15 -> V_1 ;
if ( ! V_23 )
return 0 ;
if ( V_76 > V_78 || V_76 + V_74 + V_75 > V_23 )
return - V_79 ;
V_77 = F_8 ( V_21 , V_69 ) & ~ V_80 ;
V_77 |= F_15 ( V_15 -> V_26 == V_70 ) | V_81 ;
F_2 ( V_21 , V_69 , V_77 ) ;
if ( F_3 ( V_21 , V_69 , V_82 , 1 , 500 , 0 ) ) {
F_6 ( V_21 , L_2 ) ;
return - 1 ;
}
F_2 ( V_21 , V_83 , V_23 - V_76 ) ;
F_2 ( V_21 , V_84 ,
V_23 - V_76 - V_75 ) ;
F_2 ( V_21 , V_25 ,
V_23 - V_76 - V_75 - V_74 ) ;
V_15 -> V_72 = 1 ;
F_2 ( V_21 , V_85 , 0 ) ;
F_2 ( V_21 , V_86 , 0 ) ;
F_14 ( V_15 ) ;
switch ( V_15 -> V_87 ) {
case V_88 :
V_50 = F_9 ( V_15 ) ;
break;
case V_89 :
V_50 = F_13 ( V_15 ) ;
break;
default:
F_6 ( V_21 , L_3 , V_15 -> V_87 ) ;
V_50 = - V_79 ;
break;
}
F_16 ( V_15 ) ;
return V_50 ;
}
void F_20 ( struct V_15 * V_15 )
{
struct V_1 * V_21 = V_15 -> V_1 ;
T_1 V_90 = F_8 ( V_21 , V_91 ) ;
if ( ( V_90 & V_92 ) && V_15 -> V_72 ) {
F_21 ( V_21 , L_4 ) ;
V_15 -> V_93 . V_94 ++ ;
}
if ( V_90 & V_95 ) {
F_21 ( V_21 , L_5 ) ;
V_15 -> V_93 . V_96 ++ ;
}
if ( V_90 & V_97 ) {
F_21 ( V_21 , L_6 ) ;
V_15 -> V_93 . V_98 ++ ;
}
if ( V_90 & V_99 )
V_15 -> V_93 . V_100 ++ ;
if ( V_90 & V_101 )
V_15 -> V_93 . V_102 ++ ;
if ( V_90 & V_103 )
V_15 -> V_93 . V_104 ++ ;
if ( V_90 & V_105 )
V_15 -> V_93 . V_106 ++ ;
if ( V_90 & V_107 )
F_22 ( V_21 ) ;
F_2 ( V_21 , V_91 , V_90 ) ;
}
void F_23 ( struct V_1 * V_1 , struct V_15 * V_15 , int V_26 )
{
#define F_24 * 1024
static unsigned int V_108 [] = {
64 F_24 , 128 F_24 , 256 F_24 , 32 F_24
} ;
#undef F_24
T_1 V_77 = F_8 ( V_1 , V_69 ) ;
V_15 -> V_1 = V_1 ;
V_15 -> V_26 = ( unsigned char ) V_26 ;
V_15 -> V_87 = ( unsigned char ) F_25 ( V_77 ) ;
if ( V_77 & V_109 )
V_15 -> V_87 |= 4 ;
V_15 -> V_23 = V_108 [ F_26 ( V_77 ) ] ;
if ( V_26 == V_27 )
V_15 -> V_23 /= 2 ;
}
