static inline void F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 = V_2 -> V_4 | V_3 ;
V_2 -> V_4 = V_4 ;
F_2 ( V_4 , V_2 -> V_5 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 = V_2 -> V_4 & ~ V_3 ;
V_2 -> V_4 = V_4 ;
F_2 ( V_4 , V_2 -> V_5 ) ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_5 ) ;
}
static void F_6 ( T_1 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
F_1 ( V_2 , V_9 ) ;
}
static void F_7 ( T_1 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
F_3 ( V_2 , V_9 ) ;
}
static void
F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
unsigned long V_14 ;
void T_2 * V_15 ;
F_10 ( V_14 ) ;
switch ( V_1 ( V_11 ) -> V_16 ) {
case V_17 :
case V_18 :
V_15 = ( void T_2 * ) V_11 -> V_19 + V_20 ;
switch ( V_11 -> V_21 ) {
case V_22 :
F_2 ( ( F_5 ( V_15 ) & 0xf8 ) | 1 , V_15 ) ;
break;
case V_23 :
F_2 ( ( F_5 ( V_15 ) & 0xf8 ) , V_15 ) ;
break;
}
break;
case V_24 :
switch ( V_11 -> V_21 ) {
case V_22 :
F_3 ( V_1 ( V_11 ) , V_25 ) ;
break;
case V_23 :
F_1 ( V_1 ( V_11 ) , V_25 ) ;
break;
}
break;
default:
break;
}
F_11 ( V_14 ) ;
}
static int
F_12 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
void T_2 * V_15 ;
int V_26 = 0 ;
switch ( V_1 ( V_11 ) -> V_16 ) {
case V_17 :
case V_18 :
V_15 = ( void T_2 * ) V_11 -> V_19 + V_20 ;
switch ( V_11 -> V_21 ) {
case V_22 :
V_26 = 1 ;
break;
case V_23 :
V_26 = F_5 ( V_15 ) & 4 ;
break;
}
break;
case V_24 :
switch ( V_11 -> V_21 ) {
case V_22 :
V_26 = 1 ;
break;
case V_23 :
V_26 = F_4 ( V_1 ( V_11 ) ) & V_27 ;
break;
}
break;
default:
V_26 = 0 ;
break;
}
return V_26 != 0 ;
}
static int F_13 ( struct V_10 * V_11 , struct V_28 * V_29 )
{
switch ( V_29 -> V_30 ) {
case V_22 :
case V_23 :
V_11 -> V_14 &= ~ V_31 ;
V_11 -> V_21 = V_29 -> V_30 ;
break;
default:
return - V_32 ;
}
F_8 ( V_11 ) ;
return 0 ;
}
static void
F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
void T_2 * V_15 = ( void T_2 * ) V_11 -> V_19 ;
F_2 ( V_33 + V_34 + V_35 , V_15 ) ;
if ( V_11 -> V_14 & V_31 && V_13 -> V_36 ) {
V_13 -> V_36 = 0 ;
if ( V_11 -> V_21 == V_23 )
V_11 -> V_21 = V_22 ;
else
V_11 -> V_21 = V_23 ;
F_8 ( V_11 ) ;
}
}
static void
F_15 ( struct V_10 * V_11 , int V_37 , const unsigned char * V_38 , int V_39 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
unsigned long V_40 ;
void T_2 * V_41 , * V_15 ;
if ( V_13 -> V_42 ) {
F_16 ( V_43 L_1
L_2 , V_11 -> V_44 ,
V_13 -> V_42 , V_13 -> V_45 ) ;
return;
}
if ( V_37 & 1 && V_13 -> V_46 )
V_37 ++ ;
V_13 -> V_42 = 1 ;
V_15 = ( void T_2 * ) V_11 -> V_19 ;
V_41 = V_1 ( V_11 ) -> V_41 ;
V_37 = ( V_37 + 1 ) & ~ 1 ;
F_2 ( V_33 | V_34 | V_47 , V_15 + V_48 ) ;
F_2 ( 0x42 , V_15 + V_49 ) ;
F_2 ( 0x00 , V_15 + V_20 ) ;
F_2 ( 0x42 , V_15 + V_50 ) ;
F_2 ( 0x00 , V_15 + V_51 ) ;
F_2 ( V_52 | V_47 , V_15 + V_48 ) ;
F_17 ( 1 ) ;
F_2 ( V_53 , V_15 + V_54 ) ;
F_2 ( V_37 , V_15 + V_49 ) ;
F_2 ( V_37 >> 8 , V_15 + V_20 ) ;
F_2 ( 0 , V_15 + V_50 ) ;
F_2 ( V_39 , V_15 + V_51 ) ;
F_2 ( V_55 | V_47 , V_15 + V_48 ) ;
if ( V_13 -> V_46 )
F_18 ( V_41 , V_38 , V_37 >> 1 ) ;
else
F_19 ( V_41 , V_38 , V_37 ) ;
V_40 = V_56 ;
while ( ( F_5 ( V_15 + V_54 ) & V_53 ) == 0 )
if ( F_20 ( V_56 , V_40 + 2 * V_57 / 100 ) ) {
F_16 ( V_43 L_3 ,
V_11 -> V_44 ) ;
F_14 ( V_11 ) ;
F_21 ( V_11 , 1 ) ;
break;
}
F_2 ( V_53 , V_15 + V_54 ) ;
V_13 -> V_42 = 0 ;
}
static void
F_22 ( struct V_10 * V_11 , int V_37 , struct V_58 * V_59 , int V_60 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
unsigned char * V_38 ;
void T_2 * V_41 , * V_15 ;
if ( V_13 -> V_42 ) {
F_16 ( V_43 L_1
L_2 , V_11 -> V_44 ,
V_13 -> V_42 , V_13 -> V_45 ) ;
return;
}
V_13 -> V_42 = 1 ;
V_15 = ( void T_2 * ) V_11 -> V_19 ;
V_41 = V_1 ( V_11 ) -> V_41 ;
V_38 = V_59 -> V_61 ;
F_2 ( V_33 | V_34 | V_47 , V_15 + V_48 ) ;
F_2 ( V_37 , V_15 + V_49 ) ;
F_2 ( V_37 >> 8 , V_15 + V_20 ) ;
F_2 ( V_60 , V_15 + V_50 ) ;
F_2 ( V_60 >> 8 , V_15 + V_51 ) ;
F_2 ( V_52 | V_47 , V_15 + V_48 ) ;
if ( V_13 -> V_46 ) {
F_23 ( V_41 , V_38 , V_37 >> 1 ) ;
if ( V_37 & 1 )
V_38 [ V_37 - 1 ] = F_5 ( V_41 ) ;
} else
F_24 ( V_41 , V_38 , V_37 ) ;
F_2 ( V_53 , V_15 + V_54 ) ;
V_13 -> V_42 = 0 ;
}
static void
F_25 ( struct V_10 * V_11 , struct V_62 * V_63 , int V_64 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
void T_2 * V_41 , * V_15 ;
if ( V_13 -> V_42 ) {
F_16 ( V_43 L_4
L_2 , V_11 -> V_44 ,
V_13 -> V_42 , V_13 -> V_45 ) ;
return;
}
V_13 -> V_42 = 1 ;
V_15 = ( void T_2 * ) V_11 -> V_19 ;
V_41 = V_1 ( V_11 ) -> V_41 ;
F_2 ( V_33 | V_34 | V_47 , V_15 + V_48 ) ;
F_2 ( sizeof ( * V_63 ) , V_15 + V_49 ) ;
F_2 ( 0 , V_15 + V_20 ) ;
F_2 ( 0 , V_15 + V_50 ) ;
F_2 ( V_64 , V_15 + V_51 ) ;
F_2 ( V_52 | V_47 , V_15 + V_48 ) ;
if ( V_13 -> V_46 )
F_23 ( V_41 , V_63 , sizeof ( * V_63 ) >> 1 ) ;
else
F_24 ( V_41 , V_63 , sizeof ( * V_63 ) ) ;
F_2 ( V_53 , V_15 + V_54 ) ;
V_13 -> V_42 = 0 ;
}
static int
F_26 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
if ( ! F_27 ( V_11 -> V_65 ) ) {
F_16 ( V_66 L_5 ,
V_11 -> V_44 ) ;
return - V_32 ;
}
if ( F_28 ( V_11 -> V_67 , V_68 , 0 , V_11 -> V_44 , V_11 ) )
return - V_69 ;
V_13 -> V_36 = 0 ;
if ( V_11 -> V_14 & V_31 ) {
V_11 -> V_21 = V_23 ;
F_8 ( V_11 ) ;
F_29 ( 1 ) ;
if ( ! F_12 ( V_11 ) ) {
V_11 -> V_21 = V_22 ;
F_8 ( V_11 ) ;
}
} else
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
F_30 ( V_11 ) ;
return 0 ;
}
static int
F_31 ( struct V_10 * V_11 )
{
F_32 ( V_11 ) ;
F_33 ( V_11 -> V_67 , V_11 ) ;
return 0 ;
}
static void T_3 F_34 ( void )
{
static int V_70 ;
if ( V_71 && V_70 ++ == 0 )
F_16 ( V_72 L_6 , V_73 ) ;
}
static int T_4 F_35 ( char * V_15 , struct V_74 * V_6 )
{
struct V_75 V_76 ;
char * V_77 ;
if ( ! F_36 ( & V_76 , V_6 , 0xf5 , 0 ) ) {
F_16 ( V_43 L_7 ,
F_37 ( & V_6 -> V_11 ) ) ;
goto V_78;
}
V_77 = strchr ( V_76 . V_79 . string , '(' ) ;
if ( V_77 ) {
int V_80 ;
for ( V_80 = 0 ; V_80 < 6 ; V_80 ++ ) {
V_15 [ V_80 ] = F_38 ( V_77 + 1 , & V_77 , 0x10 ) ;
if ( * V_77 != ( V_80 == 5 ? ')' : ':' ) )
break;
}
if ( V_80 == 6 )
return 0 ;
}
F_16 ( V_43 L_8 ,
F_37 ( & V_6 -> V_11 ) , V_76 . V_79 . string ) ;
V_78:
return - V_81 ;
}
static int T_3 F_39 ( char * V_15 )
{
unsigned int V_82 ;
if ( V_83 == 0 && V_84 == 0 )
return - V_81 ;
V_82 = V_83 | V_84 ;
V_15 [ 0 ] = 0 ;
V_15 [ 1 ] = 0 ;
V_15 [ 2 ] = 0xa4 ;
V_15 [ 3 ] = 0x10 + ( V_82 >> 24 ) ;
V_15 [ 4 ] = V_82 >> 16 ;
V_15 [ 5 ] = V_82 >> 8 ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 , struct V_85 * V_86 )
{
F_41 ( V_86 -> V_87 , V_88 , sizeof( V_86 -> V_87 ) ) ;
F_41 ( V_86 -> V_73 , V_89 , sizeof( V_86 -> V_73 ) ) ;
F_41 ( V_86 -> V_90 , F_37 ( V_11 -> V_11 . V_91 ) ,
sizeof( V_86 -> V_90 ) ) ;
}
static int F_42 ( struct V_10 * V_11 , struct V_92 * V_93 )
{
V_93 -> V_94 = V_1 ( V_11 ) -> V_94 ;
F_43 ( V_93 , V_95 ) ;
V_93 -> V_96 = V_97 ;
V_93 -> V_30 = V_11 -> V_21 == V_23 ? V_98 : V_99 ;
V_93 -> V_100 = ( V_11 -> V_14 & V_31 ?
V_101 : V_102 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 , struct V_92 * V_93 )
{
switch ( V_93 -> V_100 ) {
case V_101 :
V_11 -> V_14 |= V_31 ;
break;
case V_102 :
switch ( V_93 -> V_30 ) {
case V_98 :
V_11 -> V_21 = V_23 ;
break;
case V_99 :
V_11 -> V_21 = V_22 ;
break;
default:
return - V_32 ;
}
V_11 -> V_14 &= ~ V_31 ;
break;
default:
return - V_32 ;
}
F_8 ( V_11 ) ;
return 0 ;
}
static int T_4
F_45 ( struct V_74 * V_6 , const struct V_103 * V_16 )
{
const struct V_104 * V_61 = V_16 -> V_61 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_105 ;
F_34 () ;
V_105 = F_46 ( V_6 ) ;
if ( V_105 )
goto V_106;
V_11 = F_47 ( sizeof( struct V_1 ) ) ;
if ( ! V_11 ) {
V_105 = - V_107 ;
goto V_108;
}
F_48 ( V_11 , & V_6 -> V_11 ) ;
V_11 -> V_109 = & V_110 ;
V_11 -> V_67 = V_6 -> V_67 ;
V_11 -> V_111 = & V_112 ;
if ( V_61 -> V_94 & V_113 )
V_11 -> V_14 |= V_31 ;
if ( V_61 -> V_94 & V_114 ) {
V_11 -> V_14 |= V_115 ;
V_11 -> V_21 = V_23 ;
} else if ( V_61 -> V_94 & V_116 ) {
V_11 -> V_14 |= V_115 ;
V_11 -> V_21 = V_22 ;
} else
V_11 -> V_21 = V_117 ;
V_2 = V_1 ( V_11 ) ;
V_2 -> V_94 = V_61 -> V_94 ;
V_2 -> V_4 = 0 ;
V_2 -> V_16 = V_6 -> V_118 . V_119 ;
V_2 -> V_120 = F_49 ( V_6 , V_121 , 0 , V_122 ) ;
if ( ! V_2 -> V_120 ) {
V_105 = - V_107 ;
goto free;
}
V_2 -> V_5 = V_2 -> V_120 ;
if ( V_61 -> V_123 ) {
V_2 -> V_124 = F_49 ( V_6 , V_125 , 0 , V_122 ) ;
if ( ! V_2 -> V_124 ) {
V_105 = - V_107 ;
goto free;
}
V_2 -> V_5 = V_2 -> V_124 ;
}
V_11 -> V_19 = ( unsigned long ) V_2 -> V_120 + V_61 -> V_126 ;
V_2 -> V_41 = V_2 -> V_120 + V_61 -> V_127 ;
V_2 -> V_5 += V_61 -> V_128 ;
if ( V_6 -> V_129 != 8 ) {
F_50 ( V_6 , & V_130 , V_2 ) ;
} else {
F_1 ( V_2 , V_9 ) ;
}
V_13 = F_9 ( V_11 ) ;
F_51 ( & V_13 -> V_131 ) ;
if ( V_6 -> V_118 . V_119 == V_132 ) {
F_39 ( V_11 -> V_65 ) ;
V_13 -> V_133 = V_134 ;
} else {
F_35 ( V_11 -> V_65 , V_6 ) ;
V_13 -> V_133 = V_135 ;
}
V_13 -> V_44 = V_11 -> V_44 ;
V_13 -> V_46 = 1 ;
V_13 -> V_136 = V_61 -> V_136 ;
V_13 -> V_137 = V_13 -> V_136 + V_138 ;
V_13 -> V_139 = V_61 -> V_139 ;
V_13 -> V_140 = F_14 ;
V_13 -> V_141 = F_22 ;
V_13 -> V_142 = F_15 ;
V_13 -> V_143 = F_25 ;
V_13 -> V_36 = 0 ;
F_14 ( V_11 ) ;
F_21 ( V_11 , 0 ) ;
V_105 = F_52 ( V_11 ) ;
if ( V_105 )
goto free;
F_16 ( V_72 L_9 ,
V_11 -> V_44 , V_61 -> V_44 , V_6 -> V_129 , V_11 -> V_65 ) ;
F_53 ( V_6 , V_11 ) ;
return 0 ;
free:
F_54 ( V_11 ) ;
V_108:
F_55 ( V_6 ) ;
V_106:
return V_105 ;
}
static void T_5 F_56 ( struct V_74 * V_6 )
{
struct V_10 * V_11 = F_57 ( V_6 ) ;
F_53 ( V_6 , NULL ) ;
F_58 ( V_11 ) ;
F_54 ( V_11 ) ;
F_55 ( V_6 ) ;
}
static int T_3 F_59 ( void )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ ) {
V_135 [ V_80 ] = V_80 << 2 ;
V_134 [ V_80 ] = V_80 << 5 ;
}
return F_60 ( & V_144 ) ;
}
static void T_6 F_61 ( void )
{
F_62 ( & V_144 ) ;
}
