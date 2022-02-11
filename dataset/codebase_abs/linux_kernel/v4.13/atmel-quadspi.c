static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
void T_2 * V_8 ;
V_8 = V_2 -> V_9 ;
if ( V_7 -> V_10 . V_11 . V_12 )
V_8 += V_7 -> V_12 ;
if ( V_7 -> V_13 )
F_6 ( V_8 , V_7 -> V_13 , V_7 -> V_14 ) ;
else
F_7 ( V_7 -> V_15 , V_8 , V_7 -> V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_6 * V_7 ,
T_1 V_16 )
{
T_3 V_17 [ V_18 ] ;
T_4 V_19 = 0 ;
int V_20 ;
if ( V_7 -> V_10 . V_11 . V_21 )
V_17 [ V_19 ++ ] = V_7 -> V_21 ;
for ( V_20 = V_7 -> V_10 . V_11 . V_12 - 1 ; V_20 >= 0 ; -- V_20 )
V_17 [ V_19 ++ ] = ( V_7 -> V_12 >> ( V_20 << 3 ) ) & 0xff ;
if ( V_7 -> V_10 . V_11 . V_22 )
V_17 [ V_19 ++ ] = V_7 -> V_22 ;
if ( V_7 -> V_10 . V_11 . V_23 ) {
int V_24 = V_7 -> V_25 ;
switch ( V_16 & V_26 ) {
case V_27 :
case V_28 :
case V_29 :
V_24 >>= 3 ;
break;
case V_30 :
case V_31 :
V_24 >>= 2 ;
break;
case V_32 :
case V_33 :
V_24 >>= 1 ;
break;
default:
return;
}
for ( V_20 = 0 ; V_20 < V_24 ; ++ V_20 )
V_17 [ V_19 ++ ] = 0 ;
}
F_9 ( V_34 , L_1 , V_35 ,
32 , 1 , V_17 , V_19 , false ) ;
#ifdef F_10
if ( V_7 -> V_10 . V_11 . V_36 && V_7 -> V_13 )
F_9 ( V_34 , L_2 , V_35 ,
32 , 1 , V_7 -> V_13 , V_7 -> V_14 , false ) ;
#endif
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_6 * V_7 ,
T_1 V_37 , enum V_38 V_39 )
{
T_1 V_40 , V_41 , V_16 , V_42 ;
int V_43 = 0 ;
V_40 = 0 ;
V_41 = 0 ;
V_16 = V_37 ;
switch ( V_39 ) {
case V_44 :
V_16 |= V_27 ;
break;
case V_45 :
V_16 |= V_28 ;
break;
case V_46 :
V_16 |= V_29 ;
break;
case V_47 :
V_16 |= V_30 ;
break;
case V_48 :
V_16 |= V_32 ;
break;
case V_49 :
V_16 |= V_31 ;
break;
case V_50 :
V_16 |= V_33 ;
break;
default:
return - V_51 ;
}
if ( V_7 -> V_10 . V_11 . V_21 ) {
V_41 |= F_12 ( V_7 -> V_21 ) ;
V_16 |= V_52 ;
}
switch ( V_7 -> V_10 . V_11 . V_12 ) {
case 4 :
V_16 |= V_53 ;
case 3 :
V_40 = ( V_7 -> V_10 . V_11 . V_36 ) ? 0 : V_7 -> V_12 ;
V_16 |= V_54 ;
break;
case 0 :
break;
default:
return - V_51 ;
}
if ( V_7 -> V_10 . V_11 . V_22 && V_7 -> V_55 ) {
T_1 V_56 , V_57 ;
V_41 |= F_13 ( V_7 -> V_22 ) ;
V_16 |= V_58 ;
switch ( V_16 & V_26 ) {
case V_27 :
case V_28 :
case V_29 :
V_56 = 1 ;
break;
case V_30 :
case V_31 :
V_56 = 2 ;
break;
case V_32 :
case V_33 :
V_56 = 4 ;
break;
default:
return - V_51 ;
}
V_57 = V_7 -> V_55 * V_56 ;
switch ( V_57 ) {
case 1 :
V_16 |= V_59 ;
break;
case 2 :
V_16 |= V_60 ;
break;
case 4 :
V_16 |= V_61 ;
break;
case 8 :
V_16 |= V_62 ;
break;
default:
return - V_51 ;
}
}
if ( V_7 -> V_10 . V_11 . V_23 )
V_16 |= F_14 ( V_7 -> V_25 ) ;
if ( V_7 -> V_10 . V_11 . V_36 ) {
V_16 |= V_63 ;
if ( ! V_7 -> V_13 && ! V_7 -> V_15 )
V_16 |= V_64 ;
}
( void ) F_1 ( V_2 , V_65 ) ;
F_8 ( V_2 , V_7 , V_16 ) ;
F_3 ( V_2 , V_66 , V_40 ) ;
F_3 ( V_2 , V_67 , V_41 ) ;
F_3 ( V_2 , V_68 , V_16 ) ;
if ( ! V_7 -> V_10 . V_11 . V_36 )
goto V_69;
( void ) F_1 ( V_2 , V_68 ) ;
if ( ! V_7 -> V_13 && ! V_7 -> V_15 )
return 0 ;
V_43 = F_5 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_70 , V_71 ) ;
if ( V_43 )
return V_43 ;
#if F_15 ( V_72 ) && F_15 ( F_10 )
if ( V_7 -> V_15 )
F_9 ( V_34 , L_3 , V_35 ,
32 , 1 , V_7 -> V_15 , V_7 -> V_14 , false ) ;
#endif
V_69:
V_42 = F_1 ( V_2 , V_65 ) ;
if ( ( V_42 & V_73 ) == V_73 )
return V_43 ;
F_16 ( & V_2 -> V_74 ) ;
V_2 -> V_75 = V_42 & V_73 ;
F_3 ( V_2 , V_76 , V_73 ) ;
if ( ! F_17 ( & V_2 -> V_74 ,
F_18 ( 1000 ) ) )
V_43 = - V_77 ;
F_3 ( V_2 , V_78 , V_73 ) ;
return V_43 ;
}
static int F_19 ( struct V_79 * V_80 , T_3 V_81 ,
T_3 * V_82 , int V_19 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_36 = 1 ;
V_7 . V_21 = V_81 ;
V_7 . V_15 = V_82 ;
V_7 . V_14 = V_19 ;
return F_11 ( V_2 , & V_7 , V_84 ,
V_80 -> V_85 ) ;
}
static int F_20 ( struct V_79 * V_80 , T_3 V_81 ,
T_3 * V_82 , int V_19 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_36 = ( V_82 != NULL && V_19 > 0 ) ;
V_7 . V_21 = V_81 ;
V_7 . V_13 = V_82 ;
V_7 . V_14 = V_19 ;
return F_11 ( V_2 , & V_7 , V_86 ,
V_80 -> V_85 ) ;
}
static T_5 F_21 ( struct V_79 * V_80 , T_6 V_87 , T_4 V_19 ,
const T_7 * V_88 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
struct V_6 V_7 ;
T_5 V_89 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_12 = V_80 -> V_90 ;
V_7 . V_10 . V_11 . V_36 = 1 ;
V_7 . V_21 = V_80 -> V_91 ;
V_7 . V_12 = ( T_1 ) V_87 ;
V_7 . V_13 = V_88 ;
V_7 . V_14 = V_19 ;
V_89 = F_11 ( V_2 , & V_7 , V_92 ,
V_80 -> V_93 ) ;
return ( V_89 < 0 ) ? V_89 : V_19 ;
}
static int F_22 ( struct V_79 * V_80 , T_6 V_94 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_12 = V_80 -> V_90 ;
V_7 . V_21 = V_80 -> V_95 ;
V_7 . V_12 = ( T_1 ) V_94 ;
return F_11 ( V_2 , & V_7 , V_86 ,
V_80 -> V_85 ) ;
}
static T_5 F_23 ( struct V_79 * V_80 , T_6 V_96 , T_4 V_19 ,
T_7 * V_97 )
{
struct V_1 * V_2 = V_80 -> V_83 ;
struct V_6 V_7 ;
T_3 V_55 , V_25 ;
T_5 V_89 ;
if ( V_80 -> V_98 >= 2 ) {
V_55 = 2 ;
V_25 = V_80 -> V_98 - 2 ;
} else {
V_55 = V_80 -> V_98 ;
V_25 = 0 ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_12 = V_80 -> V_90 ;
V_7 . V_10 . V_11 . V_22 = ( V_55 > 0 ) ;
V_7 . V_10 . V_11 . V_23 = ( V_25 > 0 ) ;
V_7 . V_10 . V_11 . V_36 = 1 ;
V_7 . V_21 = V_80 -> V_99 ;
V_7 . V_12 = ( T_1 ) V_96 ;
V_7 . V_22 = 0xff ;
V_7 . V_55 = V_55 ;
V_7 . V_25 = V_25 ;
V_7 . V_15 = V_97 ;
V_7 . V_14 = V_19 ;
V_89 = F_11 ( V_2 , & V_7 , V_100 ,
V_80 -> V_101 ) ;
return ( V_89 < 0 ) ? V_89 : V_19 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_102 ;
T_1 V_103 , V_104 , V_105 ;
F_3 ( V_2 , V_70 , V_106 ) ;
V_103 = F_25 ( 8 ) | V_107 ;
F_3 ( V_2 , V_108 , V_103 ) ;
V_102 = F_26 ( V_2 -> V_109 ) ;
if ( ! V_102 )
return - V_51 ;
V_105 = F_27 ( V_102 , V_2 -> V_110 ) ;
if ( V_105 > 0 )
V_105 -- ;
V_104 = F_28 ( V_105 ) ;
F_3 ( V_2 , V_111 , V_104 ) ;
F_3 ( V_2 , V_70 , V_112 ) ;
return 0 ;
}
static T_8 F_29 ( int V_113 , void * V_114 )
{
struct V_1 * V_2 = (struct V_1 * ) V_114 ;
T_1 V_115 , V_116 , V_75 ;
V_115 = F_1 ( V_2 , V_65 ) ;
V_116 = F_1 ( V_2 , V_117 ) ;
V_75 = V_115 & V_116 ;
if ( ! V_75 )
return V_118 ;
V_2 -> V_75 |= V_75 ;
if ( ( V_2 -> V_75 & V_73 ) == V_73 )
F_30 ( & V_2 -> V_74 ) ;
return V_119 ;
}
static int F_31 ( struct V_120 * V_121 )
{
const struct V_122 V_123 = {
. V_116 = V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 ,
} ;
struct V_136 * V_137 , * V_138 = V_121 -> V_139 . V_140 ;
struct V_1 * V_2 ;
struct V_141 * V_142 ;
struct V_79 * V_80 ;
struct V_143 * V_144 ;
int V_113 , V_43 = 0 ;
if ( F_32 ( V_138 ) != 1 )
return - V_145 ;
V_137 = F_33 ( V_138 , NULL ) ;
V_2 = F_34 ( & V_121 -> V_139 , sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 ) {
V_43 = - V_147 ;
goto exit;
}
F_35 ( V_121 , V_2 ) ;
F_36 ( & V_2 -> V_74 ) ;
V_2 -> V_121 = V_121 ;
V_142 = F_37 ( V_121 , V_148 , L_4 ) ;
V_2 -> V_4 = F_38 ( & V_121 -> V_139 , V_142 ) ;
if ( F_39 ( V_2 -> V_4 ) ) {
F_40 ( & V_121 -> V_139 , L_5 ) ;
V_43 = F_41 ( V_2 -> V_4 ) ;
goto exit;
}
V_142 = F_37 ( V_121 , V_148 , L_6 ) ;
V_2 -> V_9 = F_38 ( & V_121 -> V_139 , V_142 ) ;
if ( F_39 ( V_2 -> V_9 ) ) {
F_40 ( & V_121 -> V_139 , L_7 ) ;
V_43 = F_41 ( V_2 -> V_9 ) ;
goto exit;
}
V_2 -> V_109 = F_42 ( & V_121 -> V_139 , NULL ) ;
if ( F_39 ( V_2 -> V_109 ) ) {
F_40 ( & V_121 -> V_139 , L_8 ) ;
V_43 = F_41 ( V_2 -> V_109 ) ;
goto exit;
}
V_43 = F_43 ( V_2 -> V_109 ) ;
if ( V_43 ) {
F_40 ( & V_121 -> V_139 , L_9 ) ;
goto exit;
}
V_113 = F_44 ( V_121 , 0 ) ;
if ( V_113 < 0 ) {
F_40 ( & V_121 -> V_139 , L_10 ) ;
V_43 = V_113 ;
goto V_149;
}
V_43 = F_45 ( & V_121 -> V_139 , V_113 , F_29 ,
0 , F_46 ( & V_121 -> V_139 ) , V_2 ) ;
if ( V_43 )
goto V_149;
V_80 = & V_2 -> V_80 ;
V_144 = & V_80 -> V_144 ;
V_80 -> V_139 = & V_121 -> V_139 ;
F_47 ( V_80 , V_137 ) ;
V_80 -> V_83 = V_2 ;
V_144 -> V_83 = V_80 ;
V_80 -> V_150 = F_19 ;
V_80 -> V_151 = F_20 ;
V_80 -> V_152 = F_23 ;
V_80 -> V_153 = F_21 ;
V_80 -> V_154 = F_22 ;
V_43 = F_48 ( V_137 , L_11 , & V_2 -> V_110 ) ;
if ( V_43 < 0 )
goto V_149;
V_43 = F_24 ( V_2 ) ;
if ( V_43 )
goto V_149;
V_43 = F_49 ( V_80 , NULL , & V_123 ) ;
if ( V_43 )
goto V_149;
V_43 = F_50 ( V_144 , NULL , 0 ) ;
if ( V_43 )
goto V_149;
F_51 ( V_137 ) ;
return 0 ;
V_149:
F_52 ( V_2 -> V_109 ) ;
exit:
F_51 ( V_137 ) ;
return V_43 ;
}
static int F_53 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_54 ( V_121 ) ;
F_55 ( & V_2 -> V_80 . V_144 ) ;
F_3 ( V_2 , V_70 , V_155 ) ;
F_52 ( V_2 -> V_109 ) ;
return 0 ;
}
