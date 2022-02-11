static void F_1 ( char * V_1 , T_1 V_2 , T_2 V_3 )
{
snprintf ( V_1 , V_2 , L_1 ,
V_3 ,
( V_3 & V_4 ) ? L_2 : L_3 ,
( V_3 & V_5 ) ? L_4 : L_3 ,
( V_3 & V_6 ) ? L_5 : L_3 ,
( V_3 & V_7 ) ? L_6 :
( ( V_3 & ( V_4 | V_5 ) )
? L_7 : L_3 ) ,
( V_3 & V_8 ) ? L_8 : L_3 ,
( V_3 & V_9 ) ? L_9 : L_3 ,
( V_3 & V_10 ) ? L_10 : L_3 ,
( V_3 & V_11 ) ? L_11 : L_3 ) ;
}
static void F_2 ( char * V_1 , T_1 V_2 , T_2 V_12 )
{
snprintf ( V_1 , V_2 , L_12 ,
V_12 ,
( V_12 & V_13 ) ? L_13 : L_14 ,
( V_12 & V_14 ) ? L_15 : L_3 ,
( V_12 & V_15 ) ? L_16 : L_3 ,
( V_12 & V_16 ) ? L_17 : L_3 ,
( V_12 & V_17 ) ? L_18 : L_3 ,
( V_12 & V_18 ) ? L_19 : L_3 ,
( V_12 & V_19 ) ? L_20 : L_3 ,
( V_12 & V_20 ) ? L_21 : L_3 ) ;
}
static void F_3 ( int V_21 , char * V_1 , T_1 V_2 , T_2 V_22 )
{
const char * V_23 ;
if ( V_21 )
V_23 = ( V_22 & V_24 )
? L_22 : L_23 ;
else
V_23 = ( V_22 & V_25 ) ? L_24 : L_3 ;
snprintf (buf, len, L_25 ,
chgconfig, hibit,
(chgconfig & TPS_CHARGE_RESET) ? L_26 : L_3 ,
(chgconfig & TPS_CHARGE_FAST) ? L_27 : L_3 ,
({int p; switch ((chgconfig >> 3) & 3) {
case 3: p = 100; break;
case 2: p = 75; break;
case 1: p = 50; break;
default: p = 25; break;
}; p; }),
(chgconfig & TPS_VBUS_CHARGING)
? ((chgconfig & TPS_VBUS_500MA) ? 500 : 100)
: 0 ,
(chgconfig & TPS_CHARGE_ENABLE) ? L_3 : L_28 ) ;
}
static void F_4 ( const char * V_26 , T_2 V_3 )
{
char V_1 [ 100 ] ;
F_1 ( V_1 , sizeof V_1 , V_3 ) ;
F_5 ( L_29 , V_27 , V_26 , V_1 ) ;
}
static void F_6 ( const char * V_26 , T_2 V_12 )
{
char V_1 [ 100 ] ;
F_2 ( V_1 , sizeof V_1 , V_12 ) ;
F_5 ( L_29 , V_27 , V_26 , V_1 ) ;
}
static void F_7 ( int V_21 , const char * V_26 , T_2 V_22 )
{
char V_1 [ 100 ] ;
F_3 ( V_21 , V_1 , sizeof V_1 , V_22 ) ;
F_5 ( L_29 , V_27 , V_26 , V_1 ) ;
}
static inline void F_4 ( const char * V_26 , T_2 V_3 ) { }
static inline void F_6 ( const char * V_26 , T_2 V_3 ) { }
static inline void F_7 ( int V_21 , const char * V_26 , T_2 V_22 ) { }
static int F_8 ( struct V_28 * V_29 , void * _ )
{
struct V_30 * V_31 = V_29 -> V_32 ;
T_2 V_33 , V_34 ;
unsigned V_35 ;
char V_1 [ 100 ] ;
const char * V_36 ;
switch ( V_31 -> V_37 ) {
case V_38 : V_36 = L_30 ; break;
case V_39 : V_36 = L_31 ; break;
case V_40 : V_36 = L_32 ; break;
case V_41 : V_36 = L_33 ; break;
default: V_36 = NULL ; break;
}
F_9 ( V_29 , L_34 ,
V_27 , V_42 , V_36 ) ;
F_10 ( & V_31 -> V_43 ) ;
F_9 ( V_29 , L_35 , V_31 -> V_44 ? L_3 : L_36 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_46 ) ;
F_3 ( V_31 -> V_21 , V_1 , sizeof V_1 , V_33 ) ;
F_9 ( V_29 , L_37 , V_1 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_47 ) ;
F_1 ( V_1 , sizeof V_1 , V_33 ) ;
F_9 ( V_29 , L_38 , V_1 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_48 ) ;
F_1 ( V_1 , sizeof V_1 , V_33 ) ;
F_9 ( V_29 , L_39 , V_1 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_49 ) ;
F_2 ( V_1 , sizeof V_1 , V_33 ) ;
F_9 ( V_29 , L_40 , V_1 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_50 ) ;
F_2 ( V_1 , sizeof V_1 , V_33 ) ;
F_9 ( V_29 , L_41 , V_1 ) ;
F_12 ( V_51 , & V_31 -> V_52 ,
V_53 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_54 ) ;
F_9 ( V_29 , L_42 , V_33 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_55 ) ;
F_9 ( V_29 , L_43 , V_33 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_56 ) ;
F_9 ( V_29 , L_44 , V_33 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_57 ) ;
V_34 = F_11 ( V_31 -> V_45 , V_58 ) ;
F_9 ( V_29 , L_45 ,
( V_33 & 0x80 )
? ( ( V_34 & 0x80 ) ? L_46 : L_13 )
: ( ( V_34 & 0x80 ) ? L_47 : L_48 ) ,
V_33 , V_34 ,
( V_33 & 0x7f ) * 10 , ( V_34 & 0x7f ) * 100 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_59 ) ;
V_34 = F_11 ( V_31 -> V_45 , V_60 ) ;
F_9 ( V_29 , L_49 ,
( V_33 & 0x80 )
? ( ( V_34 & 0x80 ) ? L_46 : L_13 )
: ( ( V_34 & 0x80 ) ? L_47 : L_13 ) ,
V_33 , V_34 ,
( V_33 & 0x7f ) * 10 , ( V_34 & 0x7f ) * 100 ) ;
V_33 = F_11 ( V_31 -> V_45 , V_61 ) ;
V_34 = F_11 ( V_31 -> V_45 , V_62 ) ;
F_9 ( V_29 , L_50 , V_33 , V_34 ) ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
if ( V_33 & ( 1 << ( 4 + V_35 ) ) )
F_9 ( V_29 , L_51 , V_35 + 1 ,
( V_33 & ( 1 << V_35 ) ) ? L_52 : L_53 ) ;
else
F_9 ( V_29 , L_54 , V_35 + 1 ,
( V_33 & ( 1 << V_35 ) ) ? L_53 : L_52 ,
( V_34 & ( 1 << V_35 ) ) ? L_55 : L_56 ,
( V_34 & ( 1 << ( 4 + V_35 ) ) ) ? L_57 : L_58 ) ;
}
F_13 ( & V_31 -> V_43 ) ;
return 0 ;
}
static int F_14 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
return F_15 ( V_64 , F_8 , V_63 -> V_65 ) ;
}
static void F_16 ( struct V_30 * V_31 )
{
T_2 V_66 = 0 , V_67 , V_68 ;
V_68 = 0 ;
if ( V_31 -> V_69 ) {
V_66 = F_11 ( V_31 -> V_45 , V_49 ) ;
V_67 = V_66 ^ V_31 -> V_12 ;
V_31 -> V_12 = V_66 ;
V_67 &= V_31 -> V_69 ;
} else
V_67 = 0 ;
if ( V_67 ) {
V_31 -> V_12 = V_66 ;
if ( V_66 & V_13 ) {
F_17 ( L_59 , V_27 ) ;
#if 0
hibernate();
#endif
V_68 = 1 ;
}
}
if ( V_31 -> V_70 ) {
V_66 = F_11 ( V_31 -> V_45 , V_47 ) ;
V_67 = V_66 ^ V_31 -> V_3 ;
V_31 -> V_3 = V_66 ;
V_67 &= V_31 -> V_70 ;
} else
V_67 = 0 ;
if ( V_67 ) {
unsigned V_44 = 0 ;
F_4 ( L_60 , V_66 ) ;
if ( V_66 & ( V_4 | V_5 ) )
F_7 ( V_31 -> V_21 , L_61 , V_31 -> V_71 ) ;
if ( ! ( V_31 -> V_3 & ~ ( V_4 | V_5 ) )
&& ( V_31 -> V_3 & ( V_4 | V_5 ) )
&& ( V_31 -> V_71 & V_72 )
) {
if ( V_31 -> V_3 & V_4 ) {
if ( V_67 & V_4 )
F_18 ( V_73 , & V_31 -> V_74 ) ;
V_44 = 1 ;
} else if ( V_31 -> V_3 & V_5 )
V_44 = 1 ;
}
if ( V_44 != V_31 -> V_44 ) {
V_31 -> V_44 = V_44 ;
F_17 ( L_62 ,
V_27 , V_44 ? L_3 :
( ( V_31 -> V_3 & ( V_4 | V_5 ) )
? L_63 : L_64 ) ) ;
}
}
if ( ( V_31 -> V_37 != V_41 || ! V_31 -> V_44 )
&& ( V_31 -> V_3 & ( V_4 | V_5 ) ) )
V_68 = 1 ;
if ( V_68 )
F_12 ( V_51 , & V_31 -> V_52 ,
V_53 ) ;
}
static void F_19 ( struct V_75 * V_52 )
{
struct V_30 * V_31 ;
V_31 = F_20 ( F_21 ( V_52 ) , struct V_30 , V_52 ) ;
F_10 ( & V_31 -> V_43 ) ;
F_16 ( V_31 ) ;
if ( F_22 ( V_73 , & V_31 -> V_74 ) ) {
int V_76 ;
T_2 V_22 , V_66 ;
V_22 = F_11 ( V_31 -> V_45 ,
V_46 ) ;
V_22 &= ~ ( V_77 | V_78 ) ;
if ( V_31 -> V_79 == 500 )
V_22 |= V_77 | V_78 ;
else if ( V_31 -> V_79 >= 100 )
V_22 |= V_78 ;
V_76 = F_23 ( V_31 -> V_45 ,
V_46 , V_22 ) ;
V_66 = F_11 ( V_31 -> V_45 , V_46 ) ;
V_31 -> V_71 = V_66 ;
F_7 ( V_31 -> V_21 , L_65 , V_66 ) ;
}
if ( F_22 ( V_80 , & V_31 -> V_74 ) )
F_24 ( V_31 -> V_45 -> V_81 ) ;
F_13 ( & V_31 -> V_43 ) ;
}
static T_3 F_25 ( int V_81 , void * V_82 )
{
struct V_30 * V_31 = V_82 ;
F_26 ( V_81 ) ;
F_18 ( V_80 , & V_31 -> V_74 ) ;
F_12 ( V_51 , & V_31 -> V_52 , 0 ) ;
return V_83 ;
}
static void
F_27 ( struct V_84 * V_36 , unsigned V_85 , int V_33 )
{
if ( V_85 < 4 )
F_28 ( V_85 + 1 , V_33 ) ;
else if ( V_85 < 6 )
F_29 ( V_85 - 3 , V_33 ? V_86 : V_87 ) ;
else
F_30 ( V_33 ) ;
}
static int
F_31 ( struct V_84 * V_36 , unsigned V_85 , int V_33 )
{
if ( V_85 < 4 ) {
struct V_30 * V_31 ;
V_31 = F_20 ( V_36 , struct V_30 , V_36 ) ;
if ( ! ( V_31 -> V_88 & ( 1 << V_85 ) ) )
return - V_89 ;
F_28 ( V_85 + 1 , V_33 ) ;
} else if ( V_85 < 6 )
F_29 ( V_85 - 3 , V_33 ? V_86 : V_87 ) ;
else
F_30 ( V_33 ) ;
return 0 ;
}
static int F_32 ( struct V_84 * V_36 , unsigned V_85 )
{
int V_33 ;
struct V_30 * V_31 ;
V_31 = F_20 ( V_36 , struct V_30 , V_36 ) ;
if ( V_85 < 4 ) {
V_33 = F_11 ( V_31 -> V_45 , V_61 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_33 & ( 1 << ( V_85 + 4 ) ) )
return ! ( V_33 & ( 1 << V_85 ) ) ;
else
return ! ! ( V_33 & ( 1 << V_85 ) ) ;
}
return 0 ;
}
static int F_33 ( struct V_90 * V_45 )
{
struct V_30 * V_31 = F_34 ( V_45 ) ;
struct V_91 * V_92 = F_35 ( & V_45 -> V_93 ) ;
if ( V_92 && V_92 -> V_94 ) {
int V_76 = V_92 -> V_94 ( V_45 , V_92 -> V_95 ) ;
if ( V_76 < 0 )
F_36 ( & V_45 -> V_93 , L_66 ,
L_67 , V_45 -> V_96 , V_76 ) ;
}
if ( V_45 -> V_81 > 0 )
F_37 ( V_45 -> V_81 , V_31 ) ;
F_38 ( & V_31 -> V_52 ) ;
F_39 ( V_31 -> V_64 ) ;
V_97 = NULL ;
return 0 ;
}
static int F_40 ( struct V_90 * V_45 ,
const struct V_98 * V_99 )
{
struct V_30 * V_31 ;
int V_76 ;
struct V_91 * V_92 = F_35 ( & V_45 -> V_93 ) ;
if ( V_97 ) {
F_36 ( & V_45 -> V_93 , L_68 ) ;
return - V_100 ;
}
if ( ! F_41 ( V_45 -> V_101 , V_102 ) )
return - V_89 ;
V_31 = F_42 ( & V_45 -> V_93 , sizeof( * V_31 ) , V_103 ) ;
if ( ! V_31 )
return - V_104 ;
F_43 ( & V_31 -> V_43 ) ;
F_44 ( & V_31 -> V_52 , F_19 ) ;
V_31 -> V_45 = V_45 ;
V_31 -> V_37 = V_99 -> V_105 ;
if ( V_45 -> V_81 > 0 ) {
V_76 = F_45 ( V_45 -> V_81 , F_25 ,
V_106 , V_27 , V_31 ) ;
if ( V_76 < 0 ) {
F_36 ( & V_45 -> V_93 , L_69 ,
V_45 -> V_81 , V_76 ) ;
return V_76 ;
}
F_46 ( V_45 -> V_81 ) ;
F_18 ( V_80 , & V_31 -> V_74 ) ;
} else
F_47 ( & V_45 -> V_93 , L_70 ) ;
switch ( V_31 -> V_37 ) {
case V_38 :
case V_40 :
V_31 -> V_21 = 1 ;
break;
}
V_31 -> V_71 = F_11 ( V_45 , V_46 ) ;
F_7 ( V_31 -> V_21 , L_71 , V_31 -> V_71 ) ;
F_4 ( L_72 ,
F_11 ( V_45 , V_47 ) ) ;
F_6 ( L_73 ,
F_11 ( V_45 , V_49 ) ) ;
F_5 ( L_74 , V_27 ,
F_11 ( V_45 , V_54 ) ,
F_11 ( V_45 , V_55 ) ,
F_11 ( V_45 , V_56 ) ) ;
F_5 ( L_75 , V_27 ,
F_11 ( V_45 , V_61 ) ,
F_11 ( V_45 , V_62 ) ) ;
F_48 ( V_45 , V_31 ) ;
V_97 = V_31 ;
#if F_49 ( V_107 ) && ! F_49 ( V_108 )
V_31 -> V_79 = 100 ;
#endif
V_31 -> V_70 = ~ 0 ;
( void ) F_23 ( V_45 , V_48 , ~ V_31 -> V_70 ) ;
V_31 -> V_69 = V_13 ;
if ( V_31 -> V_37 == V_41 )
V_31 -> V_69 |= V_16 ;
( void ) F_23 ( V_45 , V_50 , ~ V_31 -> V_69 ) ;
( void ) F_23 ( V_45 , V_62 , 0x0f
| F_11 ( V_45 , V_62 ) ) ;
F_19 ( & V_31 -> V_52 . V_52 ) ;
V_31 -> V_64 = F_50 ( V_27 , V_109 , NULL ,
V_31 , V_110 ) ;
if ( V_92 && V_92 -> V_111 != 0 ) {
V_31 -> V_88 = V_92 -> V_88 ;
V_31 -> V_36 . V_26 = V_45 -> V_96 ;
V_31 -> V_36 . V_112 = & V_45 -> V_93 ;
V_31 -> V_36 . V_113 = V_114 ;
V_31 -> V_36 . V_115 = F_27 ;
V_31 -> V_36 . V_116 = F_31 ;
V_31 -> V_36 . V_117 = F_32 ;
V_31 -> V_36 . V_111 = V_92 -> V_111 ;
V_31 -> V_36 . V_118 = 7 ;
V_31 -> V_36 . V_119 = 1 ;
V_76 = F_51 ( & V_31 -> V_36 ) ;
if ( V_76 < 0 )
F_52 ( & V_45 -> V_93 , L_76 ,
V_76 ) ;
else if ( V_92 -> V_120 ) {
V_76 = V_92 -> V_120 ( V_45 , V_92 -> V_95 ) ;
if ( V_76 < 0 ) {
F_36 ( & V_45 -> V_93 ,
L_66 ,
L_77 , V_45 -> V_96 , V_76 ) ;
V_76 = 0 ;
}
}
}
return 0 ;
}
int F_53 ( unsigned V_121 )
{
unsigned long V_74 ;
if ( ! V_97 )
return - V_100 ;
F_54 ( V_74 ) ;
if ( V_121 >= 500 )
V_121 = 500 ;
else if ( V_121 >= 100 )
V_121 = 100 ;
else
V_121 = 0 ;
V_97 -> V_79 = V_121 ;
if ( ( V_97 -> V_3 & V_4 )
&& F_55 (
V_73 , & V_97 -> V_74 ) ) {
F_12 ( V_51 , & V_97 -> V_52 ,
0 ) ;
}
F_56 ( V_74 ) ;
return 0 ;
}
int F_28 ( unsigned V_122 , unsigned V_33 )
{
int V_76 ;
unsigned V_123 ;
if ( ! V_97 )
return - V_100 ;
if ( ( V_122 < V_124 ) || ( V_122 > V_125 ) )
return - V_89 ;
F_10 ( & V_97 -> V_43 ) ;
V_123 = F_11 ( V_97 -> V_45 , V_61 ) ;
V_123 |= 1 << ( V_122 + 3 ) ;
switch ( V_33 ) {
case V_126 :
V_123 |= 1 << ( V_122 - 1 ) ;
break;
default:
V_123 &= ~ ( 1 << ( V_122 - 1 ) ) ;
break;
}
V_76 = F_23 ( V_97 -> V_45 ,
V_61 , V_123 ) ;
F_5 ( L_78 , V_27 ,
V_122 , V_33 ? L_79 : L_52 ,
F_11 ( V_97 -> V_45 , V_61 ) ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
int F_29 ( unsigned V_127 , unsigned V_128 )
{
int V_76 ;
unsigned V_129 , V_130 , V_131 ;
if ( ! V_97 )
return - V_100 ;
if ( V_127 == V_132 )
V_131 = 0 ;
else {
V_131 = 2 ;
V_127 = V_133 ;
}
F_10 ( & V_97 -> V_43 ) ;
F_5 ( L_80 , V_27 , V_127 ,
F_11 ( V_97 -> V_45 ,
V_57 + V_131 ) ) ;
F_5 ( L_81 , V_27 , V_127 ,
F_11 ( V_97 -> V_45 ,
V_58 + V_131 ) ) ;
switch ( V_128 ) {
case V_87 :
V_129 = 1 << 7 ;
V_130 = 0 << 7 ;
break;
case V_86 :
V_129 = 1 << 7 ;
V_130 = 1 << 7 ;
break;
case V_134 :
V_129 = 0x30 | ( 0 << 7 ) ;
V_130 = 0x08 | ( 1 << 7 ) ;
break;
default:
F_57 ( V_135 L_82 ,
V_27 ) ;
F_13 ( & V_97 -> V_43 ) ;
return - V_89 ;
}
V_76 = F_23 ( V_97 -> V_45 ,
V_57 + V_131 , V_129 ) ;
if ( V_76 != 0 ) {
F_57 ( V_135 L_83 ,
V_27 , V_127 ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
F_5 ( L_80 , V_27 , V_127 ,
F_11 ( V_97 -> V_45 , V_57 + V_131 ) ) ;
V_76 = F_23 ( V_97 -> V_45 ,
V_58 + V_131 , V_130 ) ;
if ( V_76 != 0 ) {
F_57 ( V_135 L_84 ,
V_27 , V_127 ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
F_5 ( L_81 , V_27 , V_127 ,
F_11 ( V_97 -> V_45 ,
V_58 + V_131 ) ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
int F_30 ( unsigned V_33 )
{
int V_76 ;
unsigned V_136 ;
if ( ! V_97 )
return - V_100 ;
F_10 ( & V_97 -> V_43 ) ;
V_136 = F_11 ( V_97 -> V_45 , V_55 ) ;
V_136 &= ~ ( 1 << 1 ) ;
if ( V_33 )
V_136 |= ( 1 << 1 ) ;
V_76 = F_23 ( V_97 -> V_45 ,
V_55 , V_136 ) ;
F_5 ( L_85 , V_27 , V_33 ? L_46 : L_13 ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
int F_58 ( unsigned V_128 )
{
int V_76 ;
unsigned V_137 ;
if ( ! V_97 )
return - V_100 ;
F_10 ( & V_97 -> V_43 ) ;
F_5 ( L_86 , V_27 ,
V_128 ? L_87 : L_88 ,
F_11 ( V_97 -> V_45 , V_54 ) ) ;
V_137 = F_11 ( V_97 -> V_45 , V_54 ) ;
switch ( V_128 ) {
case V_87 :
V_137 &= ~ V_138 ;
break;
default:
V_137 |= V_138 ;
break;
}
V_76 = F_23 ( V_97 -> V_45 ,
V_54 , V_137 ) ;
if ( V_76 != 0 )
F_57 ( V_135 L_89 ,
V_27 ) ;
else
F_5 ( L_90 , V_27 ,
F_11 ( V_97 -> V_45 , V_54 ) ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
int F_59 ( unsigned V_33 )
{
int V_76 ;
if ( ! V_97 )
return - V_100 ;
F_10 ( & V_97 -> V_43 ) ;
F_5 ( L_91 , V_27 ,
F_11 ( V_97 -> V_45 , V_56 ) ) ;
V_76 = F_23 ( V_97 -> V_45 ,
V_56 , V_33 ) ;
if ( V_76 != 0 )
F_57 ( V_135 L_92 ,
V_27 ) ;
else
F_5 ( L_91 , V_27 ,
F_11 ( V_97 -> V_45 , V_56 ) ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
int F_60 ( unsigned V_33 )
{
struct V_90 * V_139 ;
int V_76 ;
if ( ! V_97 )
return - V_100 ;
V_139 = V_97 -> V_45 ;
F_10 ( & V_97 -> V_43 ) ;
F_5 ( L_93 , V_27 ,
F_11 ( V_139 , V_55 ) ) ;
V_76 = F_23 ( V_139 , V_55 , V_33 ) ;
if ( V_76 != 0 )
F_57 ( V_135 L_94 ,
V_27 ) ;
else
F_5 ( L_91 , V_27 ,
F_11 ( V_139 , V_55 ) ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
int F_61 ( unsigned V_128 )
{
int V_76 ;
unsigned V_137 , V_22 ;
if ( ! V_97 || V_97 -> V_21 )
return - V_100 ;
F_10 ( & V_97 -> V_43 ) ;
F_5 ( L_95 ,
V_27 ,
V_128 ? L_87 : L_88 ,
F_11 ( V_97 -> V_45 , V_46 ) ,
F_11 ( V_97 -> V_45 , V_54 ) ) ;
V_22 = F_11 ( V_97 -> V_45 , V_46 ) ;
V_137 = F_11 ( V_97 -> V_45 , V_54 ) ;
switch ( V_128 ) {
case V_87 :
V_22 &= ~ V_25 ;
V_137 &= ~ V_138 ;
break;
default:
V_22 |= V_25 ;
V_137 |= V_138 ;
break;
}
V_76 = F_23 ( V_97 -> V_45 ,
V_46 , V_22 ) ;
if ( V_76 != 0 ) {
F_57 ( V_135 L_96 ,
V_27 ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
V_22 = F_11 ( V_97 -> V_45 , V_46 ) ;
V_97 -> V_71 = V_22 ;
F_7 ( 0 , L_97 , V_22 ) ;
V_76 = F_23 ( V_97 -> V_45 ,
V_54 , V_137 ) ;
if ( V_76 != 0 )
F_57 ( V_135 L_89 ,
V_27 ) ;
else
F_5 ( L_90 , V_27 ,
F_11 ( V_97 -> V_45 , V_54 ) ) ;
F_13 ( & V_97 -> V_43 ) ;
return V_76 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_140 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_140 ) ;
}
