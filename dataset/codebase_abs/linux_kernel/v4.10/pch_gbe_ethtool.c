static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_3 ( & V_6 -> V_8 , V_4 ) ;
V_4 -> V_9 &= ~ ( V_10 | V_11 ) ;
V_4 -> V_12 &= ~ ( V_13 | V_14 ) ;
if ( ! F_4 ( V_6 -> V_2 ) )
F_5 ( V_4 , V_15 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_6 -> V_17 ;
T_1 V_18 = F_7 ( V_4 ) ;
int V_7 ;
F_8 ( V_17 , V_19 , V_20 ) ;
if ( V_18 == V_21 ) {
V_18 = V_22 ;
F_5 ( V_4 , V_18 ) ;
V_4 -> V_23 = V_24 ;
}
V_7 = F_9 ( & V_6 -> V_8 , V_4 ) ;
if ( V_7 ) {
F_10 ( V_2 , L_1 ) ;
return V_7 ;
}
V_17 -> V_25 . V_26 = V_18 ;
V_17 -> V_25 . V_27 = V_4 -> V_23 ;
V_17 -> V_28 . V_29 = V_4 -> V_12 ;
V_17 -> V_25 . V_30 = V_4 -> V_30 ;
if ( F_11 ( V_6 -> V_2 ) ) {
F_12 ( V_6 ) ;
V_7 = F_13 ( V_6 ) ;
} else {
F_14 ( V_6 ) ;
}
return V_7 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_31 * ( int ) sizeof( T_1 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_17 ( V_33 -> V_34 , V_35 , sizeof( V_33 -> V_34 ) ) ;
F_17 ( V_33 -> V_36 , V_37 , sizeof( V_33 -> V_36 ) ) ;
F_17 ( V_33 -> V_38 , F_18 ( V_6 -> V_39 ) ,
sizeof( V_33 -> V_38 ) ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_40 * V_41 , void * V_42 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_6 -> V_17 ;
struct V_43 * V_39 = V_6 -> V_39 ;
T_1 * V_44 = V_42 ;
T_2 V_45 , V_46 ;
V_41 -> V_36 = 0x1000000 | ( V_47 ) V_39 -> V_48 << 16 | V_39 -> V_49 ;
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ )
* V_44 ++ = F_20 ( & V_17 -> V_51 -> V_52 + V_45 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
F_21 ( & V_6 -> V_17 , V_45 , & V_46 ) ;
* V_44 ++ = V_46 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_55 -> V_9 = V_56 | V_57 | V_58 | V_59 ;
V_55 -> V_60 = 0 ;
if ( ( V_6 -> V_61 & V_62 ) )
V_55 -> V_60 |= V_56 ;
if ( ( V_6 -> V_61 & V_63 ) )
V_55 -> V_60 |= V_57 ;
if ( ( V_6 -> V_61 & V_64 ) )
V_55 -> V_60 |= V_58 ;
if ( ( V_6 -> V_61 & V_65 ) )
V_55 -> V_60 |= V_59 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_55 -> V_60 & ( V_66 | V_67 | V_68 ) ) )
return - V_69 ;
V_6 -> V_61 = 0 ;
if ( ( V_55 -> V_60 & V_56 ) )
V_6 -> V_61 |= V_62 ;
if ( ( V_55 -> V_60 & V_57 ) )
V_6 -> V_61 |= V_63 ;
if ( ( V_55 -> V_60 & V_58 ) )
V_6 -> V_61 |= V_64 ;
if ( ( V_55 -> V_60 & V_59 ) )
V_6 -> V_61 |= V_65 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_25 ( & V_6 -> V_8 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_72 * V_73 = V_6 -> V_74 ;
struct V_75 * V_76 = V_6 -> V_77 ;
V_71 -> V_78 = V_79 ;
V_71 -> V_80 = V_81 ;
V_71 -> V_82 = V_76 -> V_83 ;
V_71 -> V_84 = V_73 -> V_83 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_72 * V_73 , * V_85 ;
struct V_75 * V_76 , * V_86 ;
int V_87 , V_88 ;
int V_89 = 0 ;
if ( ( V_71 -> V_90 ) || ( V_71 -> V_91 ) )
return - V_92 ;
V_87 = ( int ) sizeof( struct V_72 ) ;
V_88 = ( int ) sizeof( struct V_75 ) ;
if ( ( F_11 ( V_6 -> V_2 ) ) )
F_12 ( V_6 ) ;
V_85 = V_6 -> V_74 ;
V_86 = V_6 -> V_77 ;
V_73 = F_28 ( V_87 , V_93 ) ;
if ( ! V_73 ) {
V_89 = - V_94 ;
goto V_95;
}
V_76 = F_28 ( V_88 , V_93 ) ;
if ( ! V_76 ) {
V_89 = - V_94 ;
goto V_96;
}
V_6 -> V_74 = V_73 ;
V_6 -> V_77 = V_76 ;
V_76 -> V_83 =
F_29 ( V_71 -> V_82 , V_97 , V_79 ) ;
V_76 -> V_83 = F_30 ( V_76 -> V_83 , V_98 ) ;
V_73 -> V_83 =
F_29 ( V_71 -> V_84 , V_97 , V_79 ) ;
V_73 -> V_83 = F_30 ( V_73 -> V_83 , V_99 ) ;
if ( ( F_11 ( V_6 -> V_2 ) ) ) {
V_89 = F_31 ( V_6 , V_6 -> V_77 ) ;
if ( V_89 )
goto V_100;
V_89 = F_32 ( V_6 , V_6 -> V_74 ) ;
if ( V_89 )
goto V_101;
#ifdef F_33
V_6 -> V_77 = V_86 ;
V_6 -> V_74 = V_85 ;
F_34 ( V_6 , V_6 -> V_77 ) ;
F_35 ( V_6 , V_6 -> V_74 ) ;
F_36 ( V_85 ) ;
F_36 ( V_86 ) ;
V_6 -> V_77 = V_76 ;
V_6 -> V_74 = V_73 ;
#else
F_34 ( V_6 , V_86 ) ;
F_35 ( V_6 , V_85 ) ;
F_36 ( V_85 ) ;
F_36 ( V_86 ) ;
V_6 -> V_77 = V_76 ;
V_6 -> V_74 = V_73 ;
#endif
V_89 = F_13 ( V_6 ) ;
}
return V_89 ;
V_101:
F_34 ( V_6 , V_6 -> V_77 ) ;
V_100:
V_6 -> V_77 = V_86 ;
V_6 -> V_74 = V_85 ;
F_36 ( V_76 ) ;
V_96:
F_36 ( V_73 ) ;
V_95:
if ( F_11 ( V_6 -> V_2 ) )
F_13 ( V_6 ) ;
return V_89 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_6 -> V_17 ;
V_103 -> V_30 =
( ( V_17 -> V_25 . V_104 ) ? V_105 : V_106 ) ;
if ( V_17 -> V_25 . V_107 == V_108 ) {
V_103 -> V_109 = 1 ;
} else if ( V_17 -> V_25 . V_107 == V_110 ) {
V_103 -> V_111 = 1 ;
} else if ( V_17 -> V_25 . V_107 == V_112 ) {
V_103 -> V_109 = 1 ;
V_103 -> V_111 = 1 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_6 -> V_17 ;
int V_7 = 0 ;
V_17 -> V_25 . V_104 = V_103 -> V_30 ;
if ( ( V_103 -> V_109 ) && ( V_103 -> V_111 ) )
V_17 -> V_25 . V_107 = V_112 ;
else if ( ( V_103 -> V_109 ) && ( ! V_103 -> V_111 ) )
V_17 -> V_25 . V_107 = V_108 ;
else if ( ( ! V_103 -> V_109 ) && ( V_103 -> V_111 ) )
V_17 -> V_25 . V_107 = V_110 ;
else if ( ( ! V_103 -> V_109 ) && ( ! V_103 -> V_111 ) )
V_17 -> V_25 . V_107 = V_113 ;
if ( V_17 -> V_25 . V_104 == V_105 ) {
if ( ( F_11 ( V_6 -> V_2 ) ) ) {
F_12 ( V_6 ) ;
V_7 = F_13 ( V_6 ) ;
} else {
F_14 ( V_6 ) ;
}
} else {
V_7 = F_39 ( V_17 ) ;
}
return V_7 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_114 ,
T_3 * V_115 )
{
T_3 * V_42 = V_115 ;
int V_45 ;
switch ( V_114 ) {
case ( T_1 ) V_116 :
for ( V_45 = 0 ; V_45 < V_117 ; V_45 ++ ) {
memcpy ( V_42 , V_118 [ V_45 ] . string ,
V_119 ) ;
V_42 += V_119 ;
}
break;
}
}
static void F_41 ( struct V_1 * V_2 ,
struct V_120 * V_121 , T_4 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_45 ;
const struct V_122 * V_123 = V_118 ;
char * V_124 = ( char * ) & V_6 -> V_121 ;
F_42 ( V_6 ) ;
for ( V_45 = 0 ; V_45 < V_117 ; V_45 ++ ) {
char * V_42 = V_124 + V_123 -> V_125 ;
V_115 [ V_45 ] = V_123 -> V_126 == sizeof( T_4 ) ? * ( T_4 * ) V_42 : ( * ( T_1 * ) V_42 ) ;
V_123 ++ ;
}
}
static int F_43 ( struct V_1 * V_2 , int V_127 )
{
switch ( V_127 ) {
case V_116 :
return V_128 ;
default:
return - V_69 ;
}
}
void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_129 = & V_130 ;
}
