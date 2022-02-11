static void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_11 , V_12 ;
if ( V_6 -> V_13 != V_2 -> V_14 || F_2 ( V_3 ) )
return NULL ;
V_11 = F_3 ( V_3 ) ;
if ( V_11 > 2 )
return NULL ;
if ( V_11 == 0x0 && V_4 >= 0x40 )
return NULL ;
V_12 = V_11 ? V_15 | V_16 :
V_17 | V_16 ;
F_4 ( V_12 , V_9 -> V_18 + V_19 ) ;
return V_9 -> V_18 + ( V_11 >> 1 ) * 0x100 + V_4 ;
}
static int F_5 ( const struct V_20 * V_21 , T_2 V_11 , T_2 V_22 )
{
struct V_5 * V_6 = V_21 -> V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_23 ;
V_23 = F_6 ( V_21 , V_11 , V_22 ) ;
if ( ! V_23 )
V_23 = V_9 -> V_23 ;
return V_23 ;
}
static T_3 F_7 ( int V_23 , void * V_24 )
{
struct V_8 * V_9 = V_24 ;
struct V_25 * V_21 = V_9 -> V_21 ;
T_4 V_26 = F_8 ( V_9 -> V_18 + V_27 ) ;
if ( V_26 & V_28 ) {
F_9 ( V_21 , L_1 , V_26 ) ;
F_4 ( V_26 & V_28 ,
V_9 -> V_18 + V_27 ) ;
return V_29 ;
}
return V_30 ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_25 * V_21 = V_9 -> V_21 ;
int V_31 ;
T_4 V_12 ;
V_31 = F_11 ( V_21 , V_9 -> V_23 , F_7 ,
V_32 , L_2 , V_9 ) ;
if ( V_31 ) {
F_9 ( V_21 , L_3 ) ;
return;
}
V_12 = F_8 ( V_9 -> V_18 + V_33 ) ;
V_12 |= V_28 ;
F_4 ( V_12 , V_9 -> V_18 + V_33 ) ;
}
static inline void F_10 ( struct V_8 * V_9 ) { }
static int F_12 ( int V_34 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_25 * V_21 = V_9 -> V_21 ;
void T_1 * V_18 = V_9 -> V_18 ;
T_4 V_12 ;
int V_31 ;
F_13 ( V_21 ) ;
F_14 ( V_21 ) ;
V_12 = F_8 ( V_18 + V_35 ) ;
F_15 ( V_21 , L_4 , V_6 -> V_13 , V_12 ) ;
V_12 = F_8 ( V_18 + V_36 ) & ~ V_37 ;
V_12 |= V_38 | V_39 ;
F_4 ( V_12 , V_18 + V_36 ) ;
F_16 ( 4 ) ;
V_12 &= ~ ( V_40 | V_41 |
V_38 | V_39 ) ;
switch ( V_9 -> V_42 ) {
case V_43 :
V_12 |= V_44 ;
break;
case V_45 :
V_12 |= V_46 ;
break;
case V_47 :
V_12 |= V_48 ;
break;
default:
F_17 ( L_5 ,
V_9 -> V_42 ) ;
V_9 -> V_42 = V_49 ;
case V_49 :
V_12 |= V_50 ;
break;
}
F_4 ( V_12 , V_18 + V_36 ) ;
F_4 ( V_51 , V_18 + V_52 ) ;
V_12 = F_8 ( V_18 + V_53 ) ;
V_12 |= V_54 | V_55 |
V_56 ;
F_4 ( V_12 , V_18 + V_53 ) ;
F_4 ( V_9 -> V_57 | V_58 ,
V_18 + V_59 ) ;
V_12 = V_9 -> V_60 . V_61 | V_62 ;
F_4 ( V_12 , V_18 + V_63 ) ;
F_4 ( V_17 | V_16 ,
V_18 + V_19 ) ;
F_4 ( V_9 -> V_64 | V_65 ,
V_18 + V_66 ) ;
V_12 = V_9 -> V_67 -> V_61 + V_68 ;
F_4 ( V_12 , V_18 + V_69 ) ;
V_12 = F_8 ( V_18 + V_70 ) ;
V_12 |= V_71 | V_72 |
V_73 | V_74 ;
F_4 ( V_12 , V_18 + V_70 ) ;
F_4 ( V_75 | V_76 | V_77 ,
V_18 + V_33 ) ;
if ( V_9 -> V_23 > 0 )
F_10 ( V_9 ) ;
F_18 ( & V_6 -> V_78 , & V_9 -> V_60 ) ;
V_31 = F_19 ( V_21 , & V_6 -> V_78 ) ;
if ( V_31 < 0 )
return V_31 ;
V_6 -> V_13 = V_9 -> V_13 ;
return 1 ;
}
static int F_20 ( struct V_79 * V_80 ,
struct V_81 * V_82 )
{
const int V_83 = 3 , V_84 = 2 ;
int V_85 ;
V_80 -> V_82 = V_82 ;
V_80 -> V_86 = F_21 ( V_82 ) ;
V_80 -> V_87 = V_80 -> V_86 + V_83 + V_84 ;
V_80 -> V_88 = F_22 ( V_82 , L_6 , & V_85 ) ;
if ( ! V_80 -> V_88 )
return - V_89 ;
V_80 -> V_90 = V_80 -> V_88 + V_85 / sizeof( V_91 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_92 ,
struct V_81 * V_87 )
{
struct V_25 * V_21 = V_92 -> V_21 ;
struct V_93 V_88 ;
struct V_79 V_80 ;
int V_94 = 0 ;
if ( F_20 ( & V_80 , V_87 ) )
return 0 ;
F_24 (&parser, &range) {
if ( V_94 )
return - V_95 ;
V_92 -> V_57 = ( unsigned long ) V_88 . V_96 ;
V_92 -> V_64 = ( unsigned long ) V_88 . V_97 ;
V_92 -> V_42 = ( unsigned long ) V_88 . V_98 ;
if ( ! ( V_88 . V_99 & V_100 ) ) {
F_9 ( V_21 , L_7 ) ;
return - V_95 ;
}
if ( V_92 -> V_57 ) {
T_4 V_101 = 1 << ( F_25 ( V_92 -> V_57 ) - 1 ) ;
if ( V_101 < V_92 -> V_42 ) {
F_9 ( V_21 , L_8 ) ;
return - V_95 ;
}
}
V_94 ++ ;
}
return 0 ;
}
static int F_26 ( struct V_102 * V_103 )
{
struct V_25 * V_21 = & V_103 -> V_21 ;
struct V_104 * V_67 , * V_60 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_105 V_106 ;
void * V_107 [ 1 ] ;
V_67 = F_27 ( V_103 , V_108 , 0 ) ;
V_18 = F_28 ( V_21 , V_67 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
V_60 = F_27 ( V_103 , V_108 , 1 ) ;
if ( ! V_60 || ! V_60 -> V_61 )
return - V_109 ;
if ( V_60 -> V_61 & 0xFFFF )
return - V_95 ;
V_9 = F_31 ( V_21 , sizeof( struct V_8 ) , V_110 ) ;
if ( ! V_9 )
return - V_111 ;
V_9 -> V_60 = * V_60 ;
V_9 -> V_67 = V_67 ;
V_9 -> V_23 = F_32 ( V_103 , 0 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_21 = V_21 ;
if ( V_9 -> V_23 < 0 ) {
F_9 ( V_21 , L_9 ) ;
return V_9 -> V_23 ;
}
V_9 -> V_57 = 0x40000000 ;
V_9 -> V_64 = 0x40000000 ;
V_9 -> V_42 = V_45 ;
if ( V_21 -> V_112 ) {
struct V_104 V_13 ;
int V_31 ;
V_31 = F_33 ( V_21 -> V_112 , & V_13 ) ;
if ( V_31 < 0 ) {
F_9 ( V_21 , L_10 ) ;
return V_31 ;
}
V_9 -> V_13 = V_13 . V_61 ;
if ( V_13 . V_90 != V_13 . V_61 )
F_34 ( V_21 , L_11 ) ;
V_31 = F_23 ( V_9 , V_21 -> V_112 ) ;
if ( V_31 < 0 ) {
F_9 ( V_21 , L_12 ) ;
return V_31 ;
}
} else {
V_9 -> V_13 = V_103 -> V_113 ;
}
V_107 [ 0 ] = V_9 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_114 = F_35 ( V_107 ) ;
V_106 . V_115 = 1 ;
V_106 . V_10 = V_107 ;
V_106 . V_116 = F_5 ;
V_106 . V_117 = & V_118 ;
V_106 . V_119 = F_12 ;
F_36 ( V_21 , & V_106 ) ;
return 0 ;
}
