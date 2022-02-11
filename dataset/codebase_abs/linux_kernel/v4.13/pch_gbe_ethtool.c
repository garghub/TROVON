static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
F_3 ( & V_6 -> V_9 , V_4 ) ;
F_4 ( & V_7 ,
V_4 -> V_10 . V_7 ) ;
F_4 ( & V_8 ,
V_4 -> V_10 . V_8 ) ;
V_7 &= ~ ( V_11 | V_12 ) ;
V_8 &= ~ ( V_13 | V_14 ) ;
F_5 ( V_4 -> V_10 . V_7 ,
V_7 ) ;
F_5 ( V_4 -> V_10 . V_8 ,
V_8 ) ;
if ( ! F_6 ( V_6 -> V_2 ) )
V_4 -> V_15 . V_16 = V_17 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = & V_6 -> V_19 ;
struct V_3 V_20 ;
T_1 V_16 = V_4 -> V_15 . V_16 ;
T_1 V_8 ;
int V_21 ;
F_8 ( V_19 , V_22 , V_23 ) ;
memcpy ( & V_20 , V_4 , sizeof( * V_4 ) ) ;
if ( V_16 == V_24 ) {
V_16 = V_25 ;
V_20 . V_15 . V_16 = V_16 ;
V_20 . V_15 . V_26 = V_27 ;
}
V_21 = F_9 ( & V_6 -> V_9 , & V_20 ) ;
if ( V_21 ) {
F_10 ( V_2 , L_1 ) ;
return V_21 ;
}
V_19 -> V_28 . V_29 = V_16 ;
V_19 -> V_28 . V_30 = V_20 . V_15 . V_26 ;
F_4 (
& V_8 , V_20 . V_10 . V_8 ) ;
V_19 -> V_31 . V_32 = V_8 ;
V_19 -> V_28 . V_33 = V_20 . V_15 . V_33 ;
if ( F_11 ( V_6 -> V_2 ) ) {
F_12 ( V_6 ) ;
V_21 = F_13 ( V_6 ) ;
} else {
F_14 ( V_6 ) ;
}
return V_21 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_34 * ( int ) sizeof( T_1 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_17 ( V_36 -> V_37 , V_38 , sizeof( V_36 -> V_37 ) ) ;
F_17 ( V_36 -> V_39 , V_40 , sizeof( V_36 -> V_39 ) ) ;
F_17 ( V_36 -> V_41 , F_18 ( V_6 -> V_42 ) ,
sizeof( V_36 -> V_41 ) ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_43 * V_44 , void * V_45 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = & V_6 -> V_19 ;
struct V_46 * V_42 = V_6 -> V_42 ;
T_1 * V_47 = V_45 ;
T_2 V_48 , V_49 ;
V_44 -> V_39 = 0x1000000 | ( V_50 ) V_42 -> V_51 << 16 | V_42 -> V_52 ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ )
* V_47 ++ = F_20 ( & V_19 -> V_54 -> V_55 + V_48 ) ;
for ( V_48 = 0 ; V_48 < V_56 ; V_48 ++ ) {
F_21 ( & V_6 -> V_19 , V_48 , & V_49 ) ;
* V_47 ++ = V_49 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_58 -> V_7 = V_59 | V_60 | V_61 | V_62 ;
V_58 -> V_63 = 0 ;
if ( ( V_6 -> V_64 & V_65 ) )
V_58 -> V_63 |= V_59 ;
if ( ( V_6 -> V_64 & V_66 ) )
V_58 -> V_63 |= V_60 ;
if ( ( V_6 -> V_64 & V_67 ) )
V_58 -> V_63 |= V_61 ;
if ( ( V_6 -> V_64 & V_68 ) )
V_58 -> V_63 |= V_62 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_58 -> V_63 & ( V_69 | V_70 | V_71 ) ) )
return - V_72 ;
V_6 -> V_64 = 0 ;
if ( ( V_58 -> V_63 & V_59 ) )
V_6 -> V_64 |= V_65 ;
if ( ( V_58 -> V_63 & V_60 ) )
V_6 -> V_64 |= V_66 ;
if ( ( V_58 -> V_63 & V_61 ) )
V_6 -> V_64 |= V_67 ;
if ( ( V_58 -> V_63 & V_62 ) )
V_6 -> V_64 |= V_68 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_25 ( & V_6 -> V_9 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_78 * V_79 = V_6 -> V_80 ;
V_74 -> V_81 = V_82 ;
V_74 -> V_83 = V_84 ;
V_74 -> V_85 = V_79 -> V_86 ;
V_74 -> V_87 = V_76 -> V_86 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_75 * V_76 , * V_88 ;
struct V_78 * V_79 , * V_89 ;
int V_90 , V_91 ;
int V_92 = 0 ;
if ( ( V_74 -> V_93 ) || ( V_74 -> V_94 ) )
return - V_95 ;
V_90 = ( int ) sizeof( struct V_75 ) ;
V_91 = ( int ) sizeof( struct V_78 ) ;
if ( ( F_11 ( V_6 -> V_2 ) ) )
F_12 ( V_6 ) ;
V_88 = V_6 -> V_77 ;
V_89 = V_6 -> V_80 ;
V_76 = F_28 ( V_90 , V_96 ) ;
if ( ! V_76 ) {
V_92 = - V_97 ;
goto V_98;
}
V_79 = F_28 ( V_91 , V_96 ) ;
if ( ! V_79 ) {
V_92 = - V_97 ;
goto V_99;
}
V_6 -> V_77 = V_76 ;
V_6 -> V_80 = V_79 ;
V_79 -> V_86 =
F_29 ( V_74 -> V_85 , V_100 , V_82 ) ;
V_79 -> V_86 = F_30 ( V_79 -> V_86 , V_101 ) ;
V_76 -> V_86 =
F_29 ( V_74 -> V_87 , V_100 , V_82 ) ;
V_76 -> V_86 = F_30 ( V_76 -> V_86 , V_102 ) ;
if ( ( F_11 ( V_6 -> V_2 ) ) ) {
V_92 = F_31 ( V_6 , V_6 -> V_80 ) ;
if ( V_92 )
goto V_103;
V_92 = F_32 ( V_6 , V_6 -> V_77 ) ;
if ( V_92 )
goto V_104;
#ifdef F_33
V_6 -> V_80 = V_89 ;
V_6 -> V_77 = V_88 ;
F_34 ( V_6 , V_6 -> V_80 ) ;
F_35 ( V_6 , V_6 -> V_77 ) ;
F_36 ( V_88 ) ;
F_36 ( V_89 ) ;
V_6 -> V_80 = V_79 ;
V_6 -> V_77 = V_76 ;
#else
F_34 ( V_6 , V_89 ) ;
F_35 ( V_6 , V_88 ) ;
F_36 ( V_88 ) ;
F_36 ( V_89 ) ;
V_6 -> V_80 = V_79 ;
V_6 -> V_77 = V_76 ;
#endif
V_92 = F_13 ( V_6 ) ;
}
return V_92 ;
V_104:
F_34 ( V_6 , V_6 -> V_80 ) ;
V_103:
V_6 -> V_80 = V_89 ;
V_6 -> V_77 = V_88 ;
F_36 ( V_79 ) ;
V_99:
F_36 ( V_76 ) ;
V_98:
if ( F_11 ( V_6 -> V_2 ) )
F_13 ( V_6 ) ;
return V_92 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = & V_6 -> V_19 ;
V_106 -> V_33 =
( ( V_19 -> V_28 . V_107 ) ? V_108 : V_109 ) ;
if ( V_19 -> V_28 . V_110 == V_111 ) {
V_106 -> V_112 = 1 ;
} else if ( V_19 -> V_28 . V_110 == V_113 ) {
V_106 -> V_114 = 1 ;
} else if ( V_19 -> V_28 . V_110 == V_115 ) {
V_106 -> V_112 = 1 ;
V_106 -> V_114 = 1 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = & V_6 -> V_19 ;
int V_21 = 0 ;
V_19 -> V_28 . V_107 = V_106 -> V_33 ;
if ( ( V_106 -> V_112 ) && ( V_106 -> V_114 ) )
V_19 -> V_28 . V_110 = V_115 ;
else if ( ( V_106 -> V_112 ) && ( ! V_106 -> V_114 ) )
V_19 -> V_28 . V_110 = V_111 ;
else if ( ( ! V_106 -> V_112 ) && ( V_106 -> V_114 ) )
V_19 -> V_28 . V_110 = V_113 ;
else if ( ( ! V_106 -> V_112 ) && ( ! V_106 -> V_114 ) )
V_19 -> V_28 . V_110 = V_116 ;
if ( V_19 -> V_28 . V_107 == V_108 ) {
if ( ( F_11 ( V_6 -> V_2 ) ) ) {
F_12 ( V_6 ) ;
V_21 = F_13 ( V_6 ) ;
} else {
F_14 ( V_6 ) ;
}
} else {
V_21 = F_39 ( V_19 ) ;
}
return V_21 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_117 ,
T_3 * V_118 )
{
T_3 * V_45 = V_118 ;
int V_48 ;
switch ( V_117 ) {
case ( T_1 ) V_119 :
for ( V_48 = 0 ; V_48 < V_120 ; V_48 ++ ) {
memcpy ( V_45 , V_121 [ V_48 ] . string ,
V_122 ) ;
V_45 += V_122 ;
}
break;
}
}
static void F_41 ( struct V_1 * V_2 ,
struct V_123 * V_124 , T_4 * V_118 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_48 ;
const struct V_125 * V_126 = V_121 ;
char * V_127 = ( char * ) & V_6 -> V_124 ;
F_42 ( V_6 ) ;
for ( V_48 = 0 ; V_48 < V_120 ; V_48 ++ ) {
char * V_45 = V_127 + V_126 -> V_128 ;
V_118 [ V_48 ] = V_126 -> V_129 == sizeof( T_4 ) ? * ( T_4 * ) V_45 : ( * ( T_1 * ) V_45 ) ;
V_126 ++ ;
}
}
static int F_43 ( struct V_1 * V_2 , int V_130 )
{
switch ( V_130 ) {
case V_119 :
return V_131 ;
default:
return - V_72 ;
}
}
void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_132 = & V_133 ;
}
