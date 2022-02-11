static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_3 ( & V_6 -> V_8 , V_4 ) ;
V_4 -> V_9 &= ~ ( V_10 | V_11 ) ;
V_4 -> V_12 &= ~ ( V_13 | V_14 ) ;
if ( ! F_4 ( V_6 -> V_2 ) )
F_5 ( V_4 , - 1 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_6 -> V_16 ;
T_1 V_17 = F_7 ( V_4 ) ;
int V_7 ;
F_8 ( V_16 , V_18 , V_19 ) ;
if ( V_17 == V_20 ) {
V_17 = V_21 ;
V_4 -> V_22 = V_23 ;
}
V_7 = F_9 ( & V_6 -> V_8 , V_4 ) ;
if ( V_7 ) {
F_10 ( L_1 ) ;
return V_7 ;
}
V_16 -> V_24 . V_25 = V_17 ;
V_16 -> V_24 . V_26 = V_4 -> V_22 ;
V_16 -> V_27 . V_28 = V_4 -> V_12 ;
V_16 -> V_24 . V_29 = V_4 -> V_29 ;
F_11 ( V_16 ) ;
if ( F_12 ( V_6 -> V_2 ) ) {
F_13 ( V_6 ) ;
V_7 = F_14 ( V_6 ) ;
} else {
F_15 ( V_6 ) ;
}
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_30 * ( int ) sizeof( T_1 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strcpy ( V_32 -> V_33 , V_34 ) ;
strcpy ( V_32 -> V_35 , V_36 ) ;
strcpy ( V_32 -> V_37 , L_2 ) ;
strcpy ( V_32 -> V_38 , F_18 ( V_6 -> V_39 ) ) ;
V_32 -> V_40 = F_16 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_41 * V_42 , void * V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_6 -> V_16 ;
struct V_44 * V_39 = V_6 -> V_39 ;
T_1 * V_45 = V_43 ;
T_2 V_46 , V_47 ;
V_42 -> V_35 = 0x1000000 | ( V_48 ) V_39 -> V_49 << 16 | V_39 -> V_50 ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ )
* V_45 ++ = F_20 ( & V_16 -> V_52 -> V_53 + V_46 ) ;
for ( V_46 = 0 ; V_46 < V_54 ; V_46 ++ ) {
F_21 ( & V_6 -> V_16 , V_46 , & V_47 ) ;
* V_45 ++ = V_47 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_56 -> V_9 = V_57 | V_58 | V_59 | V_60 ;
V_56 -> V_61 = 0 ;
if ( ( V_6 -> V_62 & V_63 ) )
V_56 -> V_61 |= V_57 ;
if ( ( V_6 -> V_62 & V_64 ) )
V_56 -> V_61 |= V_58 ;
if ( ( V_6 -> V_62 & V_65 ) )
V_56 -> V_61 |= V_59 ;
if ( ( V_6 -> V_62 & V_66 ) )
V_56 -> V_61 |= V_60 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_56 -> V_61 & ( V_67 | V_68 | V_69 ) ) )
return - V_70 ;
V_6 -> V_62 = 0 ;
if ( ( V_56 -> V_61 & V_57 ) )
V_6 -> V_62 |= V_63 ;
if ( ( V_56 -> V_61 & V_58 ) )
V_6 -> V_62 |= V_64 ;
if ( ( V_56 -> V_61 & V_59 ) )
V_6 -> V_62 |= V_65 ;
if ( ( V_56 -> V_61 & V_60 ) )
V_6 -> V_62 |= V_66 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_25 ( & V_6 -> V_8 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_73 * V_74 = V_6 -> V_75 ;
struct V_76 * V_77 = V_6 -> V_78 ;
V_72 -> V_79 = V_80 ;
V_72 -> V_81 = V_82 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 0 ;
V_72 -> V_85 = V_77 -> V_86 ;
V_72 -> V_87 = V_74 -> V_86 ;
V_72 -> V_88 = 0 ;
V_72 -> V_89 = 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_73 * V_74 , * V_90 ;
struct V_76 * V_77 , * V_91 ;
int V_92 , V_93 ;
int V_94 = 0 ;
if ( ( V_72 -> V_88 ) || ( V_72 -> V_89 ) )
return - V_95 ;
V_92 = ( int ) sizeof( struct V_73 ) ;
V_93 = ( int ) sizeof( struct V_76 ) ;
if ( ( F_12 ( V_6 -> V_2 ) ) )
F_13 ( V_6 ) ;
V_90 = V_6 -> V_75 ;
V_91 = V_6 -> V_78 ;
V_74 = F_28 ( V_92 , V_96 ) ;
if ( ! V_74 ) {
V_94 = - V_97 ;
goto V_98;
}
V_77 = F_28 ( V_93 , V_96 ) ;
if ( ! V_77 ) {
V_94 = - V_97 ;
goto V_99;
}
V_6 -> V_75 = V_74 ;
V_6 -> V_78 = V_77 ;
V_77 -> V_86 =
F_29 ( V_72 -> V_85 , V_100 , V_80 ) ;
V_77 -> V_86 = F_30 ( V_77 -> V_86 , V_101 ) ;
V_74 -> V_86 =
F_29 ( V_72 -> V_87 , V_100 , V_80 ) ;
V_74 -> V_86 = F_30 ( V_74 -> V_86 , V_102 ) ;
if ( ( F_12 ( V_6 -> V_2 ) ) ) {
V_94 = F_31 ( V_6 , V_6 -> V_78 ) ;
if ( V_94 )
goto V_103;
V_94 = F_32 ( V_6 , V_6 -> V_75 ) ;
if ( V_94 )
goto V_104;
#ifdef F_33
V_6 -> V_78 = V_91 ;
V_6 -> V_75 = V_90 ;
F_34 ( V_6 , V_6 -> V_78 ) ;
F_35 ( V_6 , V_6 -> V_75 ) ;
F_36 ( V_90 ) ;
F_36 ( V_91 ) ;
V_6 -> V_78 = V_77 ;
V_6 -> V_75 = V_74 ;
#else
F_34 ( V_6 , V_91 ) ;
F_35 ( V_6 , V_90 ) ;
F_36 ( V_90 ) ;
F_36 ( V_91 ) ;
V_6 -> V_78 = V_77 ;
V_6 -> V_75 = V_74 ;
#endif
V_94 = F_14 ( V_6 ) ;
}
return V_94 ;
V_104:
F_34 ( V_6 , V_6 -> V_78 ) ;
V_103:
V_6 -> V_78 = V_91 ;
V_6 -> V_75 = V_90 ;
F_36 ( V_77 ) ;
V_99:
F_36 ( V_74 ) ;
V_98:
if ( F_12 ( V_6 -> V_2 ) )
F_14 ( V_6 ) ;
return V_94 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_6 -> V_16 ;
V_106 -> V_29 =
( ( V_16 -> V_24 . V_107 ) ? V_108 : V_109 ) ;
if ( V_16 -> V_24 . V_110 == V_111 ) {
V_106 -> V_112 = 1 ;
} else if ( V_16 -> V_24 . V_110 == V_113 ) {
V_106 -> V_114 = 1 ;
} else if ( V_16 -> V_24 . V_110 == V_115 ) {
V_106 -> V_112 = 1 ;
V_106 -> V_114 = 1 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_6 -> V_16 ;
int V_7 = 0 ;
V_16 -> V_24 . V_107 = V_106 -> V_29 ;
if ( ( V_106 -> V_112 ) && ( V_106 -> V_114 ) )
V_16 -> V_24 . V_110 = V_115 ;
else if ( ( V_106 -> V_112 ) && ( ! V_106 -> V_114 ) )
V_16 -> V_24 . V_110 = V_111 ;
else if ( ( ! V_106 -> V_112 ) && ( V_106 -> V_114 ) )
V_16 -> V_24 . V_110 = V_113 ;
else if ( ( ! V_106 -> V_112 ) && ( ! V_106 -> V_114 ) )
V_16 -> V_24 . V_110 = V_116 ;
if ( V_16 -> V_24 . V_107 == V_108 ) {
if ( ( F_12 ( V_6 -> V_2 ) ) ) {
F_13 ( V_6 ) ;
V_7 = F_14 ( V_6 ) ;
} else {
F_15 ( V_6 ) ;
}
} else {
V_7 = F_39 ( V_16 ) ;
}
return V_7 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_117 ,
T_3 * V_118 )
{
T_3 * V_43 = V_118 ;
int V_46 ;
switch ( V_117 ) {
case ( T_1 ) V_119 :
for ( V_46 = 0 ; V_46 < V_120 ; V_46 ++ ) {
memcpy ( V_43 , V_121 [ V_46 ] . string ,
V_122 ) ;
V_43 += V_122 ;
}
break;
}
}
static void F_41 ( struct V_1 * V_2 ,
struct V_123 * V_124 , T_4 * V_118 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_46 ;
const struct V_125 * V_126 = V_121 ;
char * V_127 = ( char * ) & V_6 -> V_124 ;
F_42 ( V_6 ) ;
for ( V_46 = 0 ; V_46 < V_120 ; V_46 ++ ) {
char * V_43 = V_127 + V_126 -> V_128 ;
V_118 [ V_46 ] = V_126 -> V_129 == sizeof( T_4 ) ? * ( T_4 * ) V_43 : ( * ( T_1 * ) V_43 ) ;
V_126 ++ ;
}
}
static int F_43 ( struct V_1 * V_2 , int V_130 )
{
switch ( V_130 ) {
case V_119 :
return V_131 ;
default:
return - V_70 ;
}
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 , & V_132 ) ;
}
