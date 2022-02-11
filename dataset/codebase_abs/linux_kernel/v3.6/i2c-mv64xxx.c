static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_3 + V_4 ) ;
F_2 ( ( ( ( V_2 -> V_5 & 0xf ) << 3 ) | ( V_2 -> V_6 & 0x7 ) ) ,
V_2 -> V_3 + V_7 ) ;
F_2 ( 0 , V_2 -> V_3 + V_8 ) ;
F_2 ( 0 , V_2 -> V_3 + V_9 ) ;
F_2 ( V_10 | V_11 ,
V_2 -> V_3 + V_12 ) ;
V_2 -> V_13 = V_14 ;
}
static void
F_3 ( struct V_1 * V_2 , T_1 V_15 )
{
if ( V_2 -> V_13 == V_14 ) {
V_2 -> V_16 = V_17 ;
return;
}
switch ( V_15 ) {
case V_18 :
case V_19 :
V_2 -> V_16 = V_20 ;
V_2 -> V_13 = V_21 ;
break;
case V_22 :
if ( V_2 -> V_23 -> V_24 & V_25 ) {
V_2 -> V_16 = V_26 ;
V_2 -> V_13 =
V_27 ;
break;
}
case V_28 :
case V_29 :
if ( ( V_2 -> V_30 == 0 )
|| ( V_2 -> V_31
&& ( V_2 -> V_32 != 0 ) ) ) {
if ( V_2 -> V_33 ) {
V_2 -> V_16 = V_17 ;
V_2 -> V_13 = V_14 ;
} else {
V_2 -> V_16 =
V_34 ;
V_2 -> V_13 =
V_35 ;
}
} else {
V_2 -> V_16 = V_36 ;
V_2 -> V_13 =
V_37 ;
V_2 -> V_30 -- ;
}
break;
case V_38 :
if ( V_2 -> V_23 -> V_24 & V_25 ) {
V_2 -> V_16 = V_26 ;
V_2 -> V_13 =
V_27 ;
break;
}
case V_39 :
if ( V_2 -> V_30 == 0 ) {
V_2 -> V_16 = V_17 ;
V_2 -> V_13 = V_14 ;
break;
}
case V_40 :
if ( V_15 != V_40 )
V_2 -> V_16 = V_41 ;
else {
V_2 -> V_16 = V_42 ;
V_2 -> V_30 -- ;
}
V_2 -> V_13 = V_43 ;
if ( ( V_2 -> V_30 == 1 ) || V_2 -> V_31 )
V_2 -> V_44 &= ~ V_45 ;
break;
case V_46 :
V_2 -> V_16 = V_47 ;
V_2 -> V_13 = V_14 ;
break;
case V_48 :
case V_49 :
case V_50 :
V_2 -> V_16 = V_17 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_51 = - V_52 ;
break;
default:
F_4 ( & V_2 -> V_53 . V_54 ,
L_1
L_2 ,
V_2 -> V_13 , V_15 , V_2 -> V_23 -> V_55 ,
V_2 -> V_23 -> V_24 ) ;
V_2 -> V_16 = V_17 ;
F_1 ( V_2 ) ;
V_2 -> V_51 = - V_56 ;
}
}
static void
F_5 ( struct V_1 * V_2 )
{
switch( V_2 -> V_16 ) {
case V_34 :
V_2 -> V_44 |= V_57 ;
V_2 -> V_44 &= ~ V_58 ;
F_2 ( V_2 -> V_44 ,
V_2 -> V_3 + V_12 ) ;
V_2 -> V_59 = 0 ;
F_6 ( & V_2 -> V_60 ) ;
break;
case V_41 :
F_2 ( V_2 -> V_44 ,
V_2 -> V_3 + V_12 ) ;
break;
case V_61 :
F_2 ( V_2 -> V_44 | V_57 ,
V_2 -> V_3 + V_12 ) ;
break;
case V_20 :
F_2 ( V_2 -> V_62 ,
V_2 -> V_3 + V_63 ) ;
F_2 ( V_2 -> V_44 ,
V_2 -> V_3 + V_12 ) ;
break;
case V_26 :
F_2 ( V_2 -> V_64 ,
V_2 -> V_3 + V_63 ) ;
F_2 ( V_2 -> V_44 ,
V_2 -> V_3 + V_12 ) ;
break;
case V_36 :
F_2 ( V_2 -> V_23 -> V_65 [ V_2 -> V_32 ++ ] ,
V_2 -> V_3 + V_63 ) ;
F_2 ( V_2 -> V_44 ,
V_2 -> V_3 + V_12 ) ;
break;
case V_42 :
V_2 -> V_23 -> V_65 [ V_2 -> V_32 ++ ] =
F_7 ( V_2 -> V_3 + V_63 ) ;
F_2 ( V_2 -> V_44 ,
V_2 -> V_3 + V_12 ) ;
break;
case V_47 :
V_2 -> V_23 -> V_65 [ V_2 -> V_32 ++ ] =
F_7 ( V_2 -> V_3 + V_63 ) ;
V_2 -> V_44 &= ~ V_58 ;
F_2 ( V_2 -> V_44 | V_11 ,
V_2 -> V_3 + V_12 ) ;
V_2 -> V_59 = 0 ;
F_6 ( & V_2 -> V_60 ) ;
break;
case V_66 :
default:
F_4 ( & V_2 -> V_53 . V_54 ,
L_3 ,
V_2 -> V_16 ) ;
V_2 -> V_51 = - V_56 ;
case V_17 :
V_2 -> V_44 &= ~ V_58 ;
F_2 ( V_2 -> V_44 | V_11 ,
V_2 -> V_3 + V_12 ) ;
V_2 -> V_59 = 0 ;
F_6 ( & V_2 -> V_60 ) ;
break;
}
}
static T_2
F_8 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
unsigned long V_24 ;
T_1 V_15 ;
T_2 V_51 = V_69 ;
F_9 ( & V_2 -> V_70 , V_24 ) ;
while ( F_7 ( V_2 -> V_3 + V_12 ) &
V_71 ) {
V_15 = F_7 ( V_2 -> V_3 + V_72 ) ;
F_3 ( V_2 , V_15 ) ;
F_5 ( V_2 ) ;
V_51 = V_73 ;
}
F_10 ( & V_2 -> V_70 , V_24 ) ;
return V_51 ;
}
static void
F_11 ( struct V_1 * V_2 ,
struct V_74 * V_23 )
{
T_1 V_75 = 0 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_32 = 0 ;
V_2 -> V_30 = V_23 -> V_76 ;
V_2 -> V_31 = 0 ;
V_2 -> V_51 = 0 ;
V_2 -> V_44 = V_45 |
V_58 | V_10 ;
if ( V_23 -> V_24 & V_77 )
V_75 = 1 ;
if ( V_23 -> V_24 & V_25 ) {
V_2 -> V_62 = 0xf0 | ( ( ( T_1 ) V_23 -> V_55 & 0x300 ) >> 7 ) | V_75 ;
V_2 -> V_64 = ( T_1 ) V_23 -> V_55 & 0xff ;
} else {
V_2 -> V_62 = ( ( T_1 ) V_23 -> V_55 & 0x7f ) << 1 | V_75 ;
V_2 -> V_64 = 0 ;
}
}
static void
F_12 ( struct V_1 * V_2 )
{
long V_78 ;
unsigned long V_24 ;
char abort = 0 ;
V_78 = F_13 ( V_2 -> V_60 ,
! V_2 -> V_59 , V_2 -> V_53 . V_79 ) ;
F_9 ( & V_2 -> V_70 , V_24 ) ;
if ( ! V_78 ) {
V_2 -> V_51 = - V_80 ;
abort = 1 ;
} else if ( V_78 < 0 ) {
V_2 -> V_51 = V_78 ;
abort = 1 ;
}
if ( abort && V_2 -> V_59 ) {
V_2 -> V_31 = 1 ;
F_10 ( & V_2 -> V_70 , V_24 ) ;
V_78 = F_14 ( V_2 -> V_60 ,
! V_2 -> V_59 , V_2 -> V_53 . V_79 ) ;
if ( ( V_78 <= 0 ) && V_2 -> V_59 ) {
V_2 -> V_13 = V_14 ;
F_4 ( & V_2 -> V_53 . V_54 ,
L_4
L_5 , V_2 -> V_59 ,
( int ) V_78 ) ;
F_1 ( V_2 ) ;
}
} else
F_10 ( & V_2 -> V_70 , V_24 ) ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_74 * V_23 ,
int V_81 , int V_82 )
{
unsigned long V_24 ;
F_9 ( & V_2 -> V_70 , V_24 ) ;
F_11 ( V_2 , V_23 ) ;
if ( F_16 ( V_23 -> V_24 & V_83 ) ) {
if ( V_2 -> V_23 -> V_24 & V_77 ) {
V_2 -> V_16 = V_41 ;
V_2 -> V_13 =
V_43 ;
} else {
V_2 -> V_16 = V_36 ;
V_2 -> V_13 =
V_37 ;
V_2 -> V_30 -- ;
}
} else {
if ( V_81 ) {
V_2 -> V_16 = V_61 ;
V_2 -> V_13 =
V_84 ;
} else {
V_2 -> V_16 = V_20 ;
V_2 -> V_13 =
V_21 ;
}
}
V_2 -> V_33 = V_82 ;
V_2 -> V_59 = 1 ;
F_5 ( V_2 ) ;
F_10 ( & V_2 -> V_70 , V_24 ) ;
F_12 ( V_2 ) ;
return V_2 -> V_51 ;
}
static T_1
F_17 ( struct V_85 * V_86 )
{
return V_87 | V_88 | V_89 ;
}
static int
F_18 ( struct V_85 * V_86 , struct V_74 V_90 [] , int V_91 )
{
struct V_1 * V_2 = F_19 ( V_86 ) ;
int V_92 , V_51 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
V_51 = F_15 ( V_2 , & V_90 [ V_92 ] ,
V_92 == 0 , V_92 + 1 == V_91 ) ;
if ( V_51 < 0 )
return V_51 ;
}
return V_91 ;
}
static int T_3
F_20 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
int V_95 ;
struct V_96 * V_97 = F_21 ( V_94 , V_98 , 0 ) ;
if ( ! V_97 )
return - V_52 ;
V_95 = F_22 ( V_97 ) ;
if ( ! F_23 ( V_97 -> V_99 , V_95 , V_2 -> V_53 . V_100 ) )
return - V_101 ;
V_2 -> V_3 = F_24 ( V_97 -> V_99 , V_95 ) ;
V_2 -> V_102 = V_97 -> V_99 ;
V_2 -> V_103 = V_95 ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_26 ( V_2 -> V_3 ) ;
F_27 ( V_2 -> V_102 , V_2 -> V_103 ) ;
}
V_2 -> V_3 = NULL ;
V_2 -> V_102 = 0 ;
}
static int T_3
F_28 ( const int V_104 , const int V_105 , const int V_106 )
{
return V_104 / ( 10 * ( V_106 + 1 ) * ( 2 << V_105 ) ) ;
}
static bool T_3
F_29 ( const T_1 V_107 , const T_1 V_104 , T_1 * V_108 ,
T_1 * V_109 )
{
int V_110 , V_111 , V_112 = V_113 ;
int V_106 , V_105 ;
for ( V_105 = 0 ; V_105 <= 7 ; V_105 ++ )
for ( V_106 = 0 ; V_106 <= 15 ; V_106 ++ ) {
V_110 = F_28 ( V_104 , V_105 , V_106 ) ;
V_111 = V_107 - V_110 ;
if ( V_111 >= 0 && V_111 < V_112 ) {
* V_109 = V_106 ;
* V_108 = V_105 ;
V_112 = V_111 ;
}
if ( V_112 == 0 )
return true ;
}
if ( V_112 == V_113 )
return false ;
return true ;
}
static int T_3
F_30 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
T_1 V_116 , V_104 ;
int V_51 = 0 ;
#if ! F_31 ( V_117 )
return - V_52 ;
#else
if ( F_32 ( V_2 -> V_118 ) ) {
V_51 = - V_52 ;
goto V_119;
}
V_104 = F_33 ( V_2 -> V_118 ) ;
F_34 ( V_115 , L_6 , & V_116 ) ;
if ( ! F_29 ( V_116 , V_104 ,
& V_2 -> V_6 , & V_2 -> V_5 ) ) {
V_51 = - V_120 ;
goto V_119;
}
V_2 -> V_67 = F_35 ( V_115 , 0 ) ;
V_2 -> V_53 . V_79 = V_121 ;
V_119:
return V_51 ;
#endif
}
static int T_3
F_30 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
return - V_52 ;
}
static int T_3
F_36 ( struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_122 * V_123 = V_94 -> V_54 . V_124 ;
int V_51 ;
if ( ( ! V_123 && ! V_94 -> V_54 . V_125 ) )
return - V_52 ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_126 ) ;
if ( ! V_2 )
return - V_127 ;
if ( F_20 ( V_94 , V_2 ) ) {
V_51 = - V_52 ;
goto V_128;
}
F_38 ( V_2 -> V_53 . V_100 , V_129 L_7 ,
sizeof( V_2 -> V_53 . V_100 ) ) ;
F_39 ( & V_2 -> V_60 ) ;
F_40 ( & V_2 -> V_70 ) ;
#if F_31 ( V_117 )
V_2 -> V_118 = F_41 ( & V_94 -> V_54 , NULL ) ;
if ( ! F_32 ( V_2 -> V_118 ) ) {
F_42 ( V_2 -> V_118 ) ;
F_43 ( V_2 -> V_118 ) ;
}
#endif
if ( V_123 ) {
V_2 -> V_5 = V_123 -> V_5 ;
V_2 -> V_6 = V_123 -> V_6 ;
V_2 -> V_67 = F_44 ( V_94 , 0 ) ;
V_2 -> V_53 . V_79 = F_45 ( V_123 -> V_79 ) ;
} else if ( V_94 -> V_54 . V_125 ) {
V_51 = F_30 ( V_2 , V_94 -> V_54 . V_125 ) ;
if ( V_51 )
goto V_130;
}
if ( V_2 -> V_67 < 0 ) {
V_51 = - V_131 ;
goto V_130;
}
V_2 -> V_53 . V_54 . V_132 = & V_94 -> V_54 ;
V_2 -> V_53 . V_133 = & V_134 ;
V_2 -> V_53 . V_135 = V_136 ;
V_2 -> V_53 . V_137 = V_138 | V_139 ;
V_2 -> V_53 . V_140 = V_94 -> V_141 ;
V_2 -> V_53 . V_54 . V_125 = V_94 -> V_54 . V_125 ;
F_46 ( V_94 , V_2 ) ;
F_47 ( & V_2 -> V_53 , V_2 ) ;
F_1 ( V_2 ) ;
if ( F_48 ( V_2 -> V_67 , F_8 , 0 ,
V_129 , V_2 ) ) {
F_4 ( & V_2 -> V_53 . V_54 ,
L_8 ,
V_2 -> V_67 ) ;
V_51 = - V_120 ;
goto V_130;
} else if ( ( V_51 = F_49 ( & V_2 -> V_53 ) ) != 0 ) {
F_4 ( & V_2 -> V_53 . V_54 ,
L_9 , - V_51 ) ;
goto V_142;
}
F_50 ( & V_2 -> V_53 ) ;
return 0 ;
V_142:
F_51 ( V_2 -> V_67 , V_2 ) ;
V_130:
#if F_31 ( V_117 )
if ( ! F_32 ( V_2 -> V_118 ) ) {
F_52 ( V_2 -> V_118 ) ;
F_53 ( V_2 -> V_118 ) ;
}
#endif
F_25 ( V_2 ) ;
V_128:
F_54 ( V_2 ) ;
return V_51 ;
}
static int T_4
F_55 ( struct V_93 * V_54 )
{
struct V_1 * V_2 = F_56 ( V_54 ) ;
int V_51 ;
V_51 = F_57 ( & V_2 -> V_53 ) ;
F_51 ( V_2 -> V_67 , V_2 ) ;
F_25 ( V_2 ) ;
#if F_31 ( V_117 )
if ( ! F_32 ( V_2 -> V_118 ) ) {
F_52 ( V_2 -> V_118 ) ;
F_53 ( V_2 -> V_118 ) ;
}
#endif
F_54 ( V_2 ) ;
return V_51 ;
}
