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
T_4 V_25 = F_8 ( V_9 -> V_18 + V_26 ) ;
if ( V_25 & V_27 ) {
F_9 ( V_9 -> V_21 , L_1 , V_25 ) ;
F_4 ( V_25 & V_27 ,
V_9 -> V_18 + V_26 ) ;
return V_28 ;
}
return V_29 ;
}
static void F_10 ( struct V_8 * V_9 )
{
int V_30 ;
T_4 V_12 ;
V_30 = F_11 ( V_9 -> V_21 , V_9 -> V_23 , F_7 ,
V_31 , L_2 , V_9 ) ;
if ( V_30 ) {
F_9 ( V_9 -> V_21 , L_3 ) ;
return;
}
V_12 = F_8 ( V_9 -> V_18 + V_32 ) ;
V_12 |= V_27 ;
F_4 ( V_12 , V_9 -> V_18 + V_32 ) ;
}
static inline void F_10 ( struct V_8 * V_9 ) { }
static int F_12 ( int V_33 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void T_1 * V_18 = V_9 -> V_18 ;
T_4 V_12 ;
F_13 ( V_9 -> V_21 ) ;
F_14 ( V_9 -> V_21 ) ;
V_12 = F_8 ( V_18 + V_34 ) ;
F_15 ( V_9 -> V_21 , L_4 , V_6 -> V_13 , V_12 ) ;
V_12 = F_8 ( V_18 + V_35 ) & ~ V_36 ;
V_12 |= V_37 | V_38 ;
F_4 ( V_12 , V_18 + V_35 ) ;
F_16 ( 4 ) ;
V_12 &= ~ ( V_39 | V_40 |
V_37 | V_38 ) ;
switch ( V_9 -> V_41 ) {
case V_42 :
V_12 |= V_43 ;
break;
case V_44 :
V_12 |= V_45 ;
break;
case V_46 :
V_12 |= V_47 ;
break;
default:
F_17 ( L_5 ,
V_9 -> V_41 ) ;
V_9 -> V_41 = V_48 ;
case V_48 :
V_12 |= V_49 ;
break;
}
F_4 ( V_12 , V_18 + V_35 ) ;
F_4 ( V_50 , V_18 + V_51 ) ;
V_12 = F_8 ( V_18 + V_52 ) ;
V_12 |= V_53 | V_54 |
V_55 ;
F_4 ( V_12 , V_18 + V_52 ) ;
F_4 ( V_9 -> V_56 | V_57 ,
V_18 + V_58 ) ;
V_12 = V_9 -> V_59 . V_60 | V_61 ;
F_4 ( V_12 , V_18 + V_62 ) ;
F_4 ( V_17 | V_16 ,
V_18 + V_19 ) ;
F_4 ( V_9 -> V_63 | V_64 ,
V_18 + V_65 ) ;
V_12 = V_9 -> V_66 -> V_60 + V_67 ;
F_4 ( V_12 , V_18 + V_68 ) ;
V_12 = F_8 ( V_18 + V_69 ) ;
V_12 |= V_70 | V_71 |
V_72 | V_73 ;
F_4 ( V_12 , V_18 + V_69 ) ;
F_4 ( V_74 | V_75 | V_76 ,
V_18 + V_32 ) ;
if ( V_9 -> V_23 > 0 )
F_10 ( V_9 ) ;
F_18 ( & V_6 -> V_77 , & V_9 -> V_78 ) ;
F_18 ( & V_6 -> V_77 , & V_9 -> V_59 ) ;
V_6 -> V_13 = V_9 -> V_13 ;
return 1 ;
}
static int F_19 ( struct V_79 * V_80 ,
struct V_81 * V_82 )
{
const int V_83 = 3 , V_84 = 2 ;
int V_85 ;
V_80 -> V_82 = V_82 ;
V_80 -> V_86 = F_20 ( V_82 ) ;
V_80 -> V_87 = V_80 -> V_86 + V_83 + V_84 ;
V_80 -> V_88 = F_21 ( V_82 , L_6 , & V_85 ) ;
if ( ! V_80 -> V_88 )
return - V_89 ;
V_80 -> V_90 = V_80 -> V_88 + V_85 / sizeof( V_91 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_92 ,
struct V_81 * V_87 )
{
struct V_93 V_88 ;
struct V_79 V_80 ;
int V_94 = 0 ;
if ( F_19 ( & V_80 , V_87 ) )
return 0 ;
F_23 (&parser, &range) {
if ( V_94 )
return - V_95 ;
V_92 -> V_56 = ( unsigned long ) V_88 . V_96 ;
V_92 -> V_63 = ( unsigned long ) V_88 . V_97 ;
V_92 -> V_41 = ( unsigned long ) V_88 . V_98 ;
if ( ! ( V_88 . V_99 & V_100 ) ) {
F_9 ( V_92 -> V_21 , L_7 ) ;
return - V_95 ;
}
if ( V_92 -> V_56 ) {
T_4 V_101 = 1 << ( F_24 ( V_92 -> V_56 ) - 1 ) ;
if ( V_101 < V_92 -> V_41 ) {
F_9 ( V_92 -> V_21 , L_8 ) ;
return - V_95 ;
}
}
V_94 ++ ;
}
return 0 ;
}
static int F_25 ( struct V_102 * V_103 )
{
struct V_104 * V_66 , * V_59 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_105 V_106 ;
void * V_107 [ 1 ] ;
V_66 = F_26 ( V_103 , V_108 , 0 ) ;
V_18 = F_27 ( & V_103 -> V_21 , V_66 ) ;
if ( F_28 ( V_18 ) )
return F_29 ( V_18 ) ;
V_59 = F_26 ( V_103 , V_108 , 1 ) ;
if ( ! V_59 || ! V_59 -> V_60 )
return - V_109 ;
if ( V_59 -> V_60 & 0xFFFF )
return - V_95 ;
V_9 = F_30 ( & V_103 -> V_21 ,
sizeof( struct V_8 ) , V_110 ) ;
if ( ! V_9 )
return - V_111 ;
V_9 -> V_59 = * V_59 ;
V_9 -> V_78 . V_60 = V_9 -> V_59 . V_60 ;
V_9 -> V_78 . V_90 = V_9 -> V_59 . V_90 ;
V_9 -> V_78 . V_99 = V_112 ;
V_9 -> V_66 = V_66 ;
V_9 -> V_23 = F_31 ( V_103 , 0 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_21 = & V_103 -> V_21 ;
if ( V_9 -> V_23 < 0 ) {
F_9 ( & V_103 -> V_21 , L_9 ) ;
return V_9 -> V_23 ;
}
V_9 -> V_56 = 0x40000000 ;
V_9 -> V_63 = 0x40000000 ;
V_9 -> V_41 = V_44 ;
if ( V_103 -> V_21 . V_113 ) {
struct V_104 V_13 ;
int V_30 ;
V_30 = F_32 ( V_103 -> V_21 . V_113 , & V_13 ) ;
if ( V_30 < 0 ) {
F_9 ( & V_103 -> V_21 , L_10 ) ;
return V_30 ;
}
V_9 -> V_13 = V_13 . V_60 ;
if ( V_13 . V_90 != V_13 . V_60 )
F_33 ( & V_103 -> V_21 , L_11 ) ;
V_30 = F_22 ( V_9 , V_103 -> V_21 . V_113 ) ;
if ( V_30 < 0 ) {
F_9 ( & V_103 -> V_21 , L_12 ) ;
return V_30 ;
}
} else {
V_9 -> V_13 = V_103 -> V_114 ;
}
V_107 [ 0 ] = V_9 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_115 = F_34 ( V_107 ) ;
V_106 . V_10 = V_107 ;
V_106 . V_116 = F_5 ;
V_106 . V_117 = & V_118 ;
V_106 . V_119 = F_12 ;
F_35 ( & V_103 -> V_21 , & V_106 ) ;
return 0 ;
}
