static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static const char * F_3 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
return L_1 ;
case V_8 :
return L_2 ;
case V_9 :
return L_3 ;
case V_10 :
return L_4 ;
default:
return L_5 ;
}
}
static inline struct V_11 * F_4 ( struct V_12 * V_13 , int V_14 )
{
return F_5 ( V_13 , V_14 , V_15 ) ;
}
void F_6 ( struct V_12 * V_13 , struct V_11 * V_16 )
{
F_7 ( V_16 -> V_17 ) ;
F_8 ( V_13 , V_16 ) ;
}
static void F_9 ( struct V_18 * V_19 , struct V_12 * V_13 )
{
int V_20 ;
if ( V_13 -> V_21 ) {
V_20 = F_10 ( V_13 ) ;
if ( V_20 < 0 )
F_11 ( V_19 , L_6 ,
V_13 -> V_22 , V_20 ) ;
V_13 -> V_21 = NULL ;
}
}
void F_12 ( struct V_18 * V_19 ,
struct V_12 * V_23 , struct V_12 * V_24 ,
struct V_12 * V_25 , struct V_12 * V_26 ,
struct V_12 * V_27 , struct V_12 * V_28 )
{
F_9 ( V_19 , V_23 ) ;
F_9 ( V_19 , V_24 ) ;
if ( V_25 )
F_9 ( V_19 , V_25 ) ;
if ( V_26 )
F_9 ( V_19 , V_26 ) ;
if ( V_27 )
F_9 ( V_19 , V_27 ) ;
if ( V_28 )
F_9 ( V_19 , V_28 ) ;
}
static int
F_13 ( struct V_29 * V_30 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_30 -> V_19 ;
struct V_1 * V_31 = F_1 ( V_3 ) ;
int V_32 ;
int V_33 ;
V_32 = F_14 ( V_30 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
V_34 . V_35 = V_32 ;
V_36 . V_35 = V_32 ;
V_37 . V_35 = V_32 ;
V_31 -> V_38 = F_15 ( V_19 -> V_39 , & V_40 ) ;
if ( ! V_31 -> V_38 ) {
V_41:
ERROR ( V_19 , L_7 ,
V_3 -> V_22 , V_19 -> V_39 -> V_22 ) ;
return - V_42 ;
}
V_31 -> V_38 -> V_21 = V_19 ;
V_31 -> V_43 = F_15 ( V_19 -> V_39 , & V_44 ) ;
if ( ! V_31 -> V_43 )
goto V_41;
V_31 -> V_43 -> V_21 = V_19 ;
if ( V_45 < 1 )
V_45 = 1 ;
if ( V_45 > 16 )
V_45 = 16 ;
if ( V_46 > 2 )
V_46 = 2 ;
if ( V_47 > 15 )
V_47 = 15 ;
V_48 . V_49 = V_50 > 1023 ?
1023 : V_50 ;
V_48 . V_51 = V_45 ;
V_52 . V_49 = V_50 > 1023 ?
1023 : V_50 ;
V_52 . V_51 = V_45 ;
V_31 -> V_53 = F_15 ( V_19 -> V_39 , & V_48 ) ;
if ( ! V_31 -> V_53 )
goto V_54;
V_31 -> V_53 -> V_21 = V_19 ;
V_31 -> V_55 = F_15 ( V_19 -> V_39 , & V_52 ) ;
if ( V_31 -> V_55 ) {
V_31 -> V_55 -> V_21 = V_19 ;
} else {
V_31 -> V_53 -> V_21 = NULL ;
V_31 -> V_53 = NULL ;
V_54:
V_56 [ V_57 ] = NULL ;
V_58 [ V_59 ] = NULL ;
V_60 [ V_61 ] = NULL ;
}
if ( V_50 > 1024 )
V_50 = 1024 ;
if ( V_62 < 1 )
V_62 = 1 ;
if ( V_62 > 4096 )
V_62 = 4096 ;
if ( V_63 > 2 )
V_63 = 2 ;
if ( V_64 > 15 )
V_64 = 15 ;
V_65 . V_49 = V_66 > 64 ?
64 : V_66 ;
V_65 . V_51 = V_62 > 255 ?
255 : V_62 ;
V_67 . V_49 = V_66 > 64 ?
64 : V_66 ;
V_67 . V_51 = V_62 > 255 ?
255 : V_62 ;
V_31 -> V_68 = F_15 ( V_19 -> V_39 , & V_65 ) ;
if ( ! V_31 -> V_68 )
goto V_69;
V_31 -> V_68 -> V_21 = V_19 ;
V_31 -> V_70 = F_15 ( V_19 -> V_39 , & V_67 ) ;
if ( V_31 -> V_70 ) {
V_31 -> V_70 -> V_21 = V_19 ;
} else {
V_31 -> V_68 -> V_21 = NULL ;
V_31 -> V_68 = NULL ;
V_69:
V_56 [ V_71 ] = NULL ;
V_58 [ V_72 ] = NULL ;
V_60 [ V_73 ] = NULL ;
}
if ( V_66 > 1024 )
V_66 = 1024 ;
V_74 . V_75 = V_40 . V_75 ;
V_76 . V_75 = V_44 . V_75 ;
V_77 . V_49 = V_50 ;
V_77 . V_49 |= V_46 << 11 ;
V_77 . V_51 = V_45 ;
V_77 . V_75 =
V_48 . V_75 ;
V_78 . V_49 = V_50 ;
V_78 . V_49 |= V_46 << 11 ;
V_78 . V_51 = V_45 ;
V_78 . V_75 = V_52 . V_75 ;
V_79 . V_49 = V_66 ;
V_79 . V_49 |= V_63 << 11 ;
V_79 . V_51 = F_16 ( V_62 ) ;
V_79 . V_75 =
V_65 . V_75 ;
V_80 . V_49 = V_66 ;
V_80 . V_49 |= V_63 << 11 ;
V_80 . V_51 = F_16 ( V_62 ) ;
V_80 . V_75 = V_67 . V_75 ;
V_81 . V_75 =
V_40 . V_75 ;
V_82 . V_75 =
V_44 . V_75 ;
V_83 . V_49 = V_50 ;
V_83 . V_51 = V_45 ;
V_84 . V_85 = V_46 ;
V_84 . V_86 = V_47 ;
V_84 . V_87 =
V_50 * ( V_46 + 1 ) * ( V_47 + 1 ) ;
V_83 . V_75 =
V_48 . V_75 ;
V_88 . V_49 = V_50 ;
V_88 . V_51 = V_45 ;
V_89 . V_85 = V_46 ;
V_89 . V_86 = V_47 ;
V_89 . V_87 =
V_50 * ( V_46 + 1 ) * ( V_47 + 1 ) ;
V_88 . V_75 = V_52 . V_75 ;
V_90 . V_49 = V_66 ;
V_90 . V_51 = F_17 ( V_62 ) ;
V_91 . V_85 = V_63 ;
V_91 . V_86 = V_64 ;
V_91 . V_87 =
V_66 * ( V_63 + 1 ) * ( V_64 + 1 ) ;
V_90 . V_75 =
V_65 . V_75 ;
V_92 . V_49 = V_66 ;
V_92 . V_51 = F_17 ( V_62 ) ;
V_93 . V_85 = V_63 ;
V_93 . V_86 = V_64 ;
V_93 . V_87 =
V_66 * ( V_63 + 1 ) * ( V_64 + 1 ) ;
V_92 . V_75 = V_67 . V_75 ;
V_33 = F_18 ( V_3 , V_56 ,
V_58 , V_60 ) ;
if ( V_33 )
return V_33 ;
F_11 ( V_19 , L_8
L_9 ,
( F_19 ( V_30 -> V_19 -> V_39 ) ? L_10 :
( F_20 ( V_30 -> V_19 -> V_39 ) ? L_11 : L_12 ) ) ,
V_3 -> V_22 , V_31 -> V_38 -> V_22 , V_31 -> V_43 -> V_22 ,
V_31 -> V_53 ? V_31 -> V_53 -> V_22 : L_13 ,
V_31 -> V_55 ? V_31 -> V_55 -> V_22 : L_13 ,
V_31 -> V_68 ? V_31 -> V_68 -> V_22 : L_13 ,
V_31 -> V_70 ? V_31 -> V_70 -> V_22 : L_13 ) ;
return 0 ;
}
static void
F_21 ( struct V_2 * V_3 )
{
struct V_94 * V_95 ;
V_95 = F_2 ( V_3 -> V_96 , struct V_94 , V_97 ) ;
F_22 ( & V_95 -> V_98 ) ;
V_95 -> V_99 -- ;
F_23 ( & V_95 -> V_98 ) ;
F_24 ( V_3 ) ;
F_7 ( F_1 ( V_3 ) ) ;
}
static int F_25 ( struct V_1 * V_31 , struct V_11 * V_16 )
{
unsigned V_100 ;
T_1 * V_17 = V_16 -> V_17 ;
struct V_18 * V_19 = V_31 -> V_4 . V_101 -> V_19 ;
if ( V_102 == 2 )
return 0 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_103 ; V_100 ++ , V_17 ++ ) {
switch ( V_102 ) {
case 0 :
if ( * V_17 == 0 )
continue;
break;
case 1 :
if ( * V_17 == ( T_1 ) ( V_100 % 63 ) )
continue;
break;
}
ERROR ( V_19 , L_14 , V_100 , * V_17 ) ;
F_26 ( V_31 -> V_43 ) ;
return - V_104 ;
}
return 0 ;
}
static void F_27 ( struct V_12 * V_13 , struct V_11 * V_16 )
{
unsigned V_100 ;
T_1 * V_17 = V_16 -> V_17 ;
switch ( V_102 ) {
case 0 :
memset ( V_16 -> V_17 , 0 , V_16 -> V_105 ) ;
break;
case 1 :
for ( V_100 = 0 ; V_100 < V_16 -> V_105 ; V_100 ++ )
* V_17 ++ = ( T_1 ) ( V_100 % 63 ) ;
break;
case 2 :
break;
}
}
static void F_28 ( struct V_12 * V_13 , struct V_11 * V_16 )
{
struct V_18 * V_19 ;
struct V_1 * V_31 = V_13 -> V_21 ;
int V_106 = V_16 -> V_106 ;
if ( ! V_31 )
return;
V_19 = V_31 -> V_4 . V_101 -> V_19 ;
switch ( V_106 ) {
case 0 :
if ( V_13 == V_31 -> V_43 ) {
F_25 ( V_31 , V_16 ) ;
if ( V_102 != 2 )
memset ( V_16 -> V_17 , 0x55 , V_16 -> V_105 ) ;
}
break;
case - V_107 :
case - V_108 :
case - V_109 :
F_29 ( V_19 , L_15 , V_13 -> V_22 , V_106 ,
V_16 -> V_103 , V_16 -> V_105 ) ;
if ( V_13 == V_31 -> V_43 )
F_25 ( V_31 , V_16 ) ;
F_6 ( V_13 , V_16 ) ;
return;
case - V_110 :
default:
#if 1
F_11 ( V_19 , L_16 , V_13 -> V_22 ,
V_106 , V_16 -> V_103 , V_16 -> V_105 ) ;
#endif
case - V_111 :
break;
}
V_106 = F_30 ( V_13 , V_16 , V_112 ) ;
if ( V_106 ) {
ERROR ( V_19 , L_17 ,
V_13 -> V_22 , V_16 -> V_105 , V_106 ) ;
F_26 ( V_13 ) ;
}
}
static int F_31 ( struct V_1 * V_31 , bool V_113 ,
enum V_5 V_6 , int V_114 )
{
struct V_12 * V_13 ;
struct V_11 * V_16 ;
int V_100 , V_115 , V_106 ;
for ( V_100 = 0 ; V_100 < 8 ; V_100 ++ ) {
switch ( V_6 ) {
case V_7 :
switch ( V_114 ) {
case V_116 :
V_115 = V_50 * ( V_46 + 1 ) *
( V_47 + 1 ) ;
break;
case V_117 :
V_115 = V_50 * ( V_46 + 1 ) ;
break;
default:
V_115 = V_50 > 1023 ?
1023 : V_50 ;
break;
}
V_13 = V_113 ? V_31 -> V_53 : V_31 -> V_55 ;
V_16 = F_4 ( V_13 , V_115 ) ;
break;
case V_8 :
switch ( V_114 ) {
case V_116 :
V_115 = V_66 * ( V_63 + 1 ) *
( V_64 + 1 ) ;
break;
case V_117 :
V_115 = V_66 * ( V_63 + 1 ) ;
break;
default:
V_115 = V_66 > 1023 ?
1023 : V_66 ;
break;
}
V_13 = V_113 ? V_31 -> V_68 : V_31 -> V_70 ;
V_16 = F_4 ( V_13 , V_115 ) ;
break;
default:
V_13 = V_113 ? V_31 -> V_38 : V_31 -> V_43 ;
V_16 = F_4 ( V_13 , 0 ) ;
break;
}
if ( ! V_16 )
return - V_118 ;
V_16 -> V_119 = F_28 ;
if ( V_113 )
F_27 ( V_13 , V_16 ) ;
else if ( V_102 != 2 )
memset ( V_16 -> V_17 , 0x55 , V_16 -> V_105 ) ;
V_106 = F_30 ( V_13 , V_16 , V_112 ) ;
if ( V_106 ) {
struct V_18 * V_19 ;
V_19 = V_31 -> V_4 . V_101 -> V_19 ;
ERROR ( V_19 , L_18 ,
F_3 ( V_6 ) , V_113 ? L_19 : L_20 ,
V_13 -> V_22 , V_106 ) ;
F_6 ( V_13 , V_16 ) ;
}
if ( ! ( V_6 == V_7 ) )
break;
}
return V_106 ;
}
static void F_32 ( struct V_1 * V_31 )
{
struct V_18 * V_19 ;
V_19 = V_31 -> V_4 . V_101 -> V_19 ;
F_12 ( V_19 , V_31 -> V_38 , V_31 -> V_43 , V_31 -> V_53 ,
V_31 -> V_55 , V_31 -> V_68 , V_31 -> V_70 ) ;
F_29 ( V_19 , L_21 , V_31 -> V_4 . V_22 ) ;
}
static int
F_33 ( struct V_18 * V_19 , struct V_1 * V_31 ,
int V_120 )
{
int V_121 = 0 ;
int V_114 = V_19 -> V_39 -> V_114 ;
struct V_12 * V_13 ;
if ( V_120 == 2 ) {
V_13 = V_31 -> V_68 ;
if ( V_13 ) {
V_121 = F_34 ( V_19 -> V_39 ,
& ( V_31 -> V_4 ) , V_13 ) ;
if ( V_121 )
return V_121 ;
V_121 = F_35 ( V_13 ) ;
if ( V_121 < 0 )
return V_121 ;
V_13 -> V_21 = V_31 ;
V_121 = F_31 ( V_31 , true , V_8 ,
V_114 ) ;
if ( V_121 < 0 ) {
V_122:
V_13 = V_31 -> V_68 ;
if ( V_13 ) {
F_10 ( V_13 ) ;
V_13 -> V_21 = NULL ;
}
return V_121 ;
}
}
V_13 = V_31 -> V_70 ;
if ( V_13 ) {
V_121 = F_34 ( V_19 -> V_39 ,
& ( V_31 -> V_4 ) , V_13 ) ;
if ( V_121 )
goto V_122;
V_121 = F_35 ( V_13 ) ;
if ( V_121 < 0 )
goto V_122;
V_13 -> V_21 = V_31 ;
V_121 = F_31 ( V_31 , false , V_8 ,
V_114 ) ;
if ( V_121 < 0 ) {
V_13 = V_31 -> V_70 ;
F_10 ( V_13 ) ;
V_13 -> V_21 = NULL ;
goto V_122;
}
}
goto V_24;
}
V_13 = V_31 -> V_38 ;
V_121 = F_34 ( V_19 -> V_39 , & ( V_31 -> V_4 ) , V_13 ) ;
if ( V_121 )
return V_121 ;
V_121 = F_35 ( V_13 ) ;
if ( V_121 < 0 )
return V_121 ;
V_13 -> V_21 = V_31 ;
V_121 = F_31 ( V_31 , true , V_10 , V_114 ) ;
if ( V_121 < 0 ) {
V_123:
V_13 = V_31 -> V_38 ;
F_10 ( V_13 ) ;
V_13 -> V_21 = NULL ;
return V_121 ;
}
V_13 = V_31 -> V_43 ;
V_121 = F_34 ( V_19 -> V_39 , & ( V_31 -> V_4 ) , V_13 ) ;
if ( V_121 )
goto V_123;
V_121 = F_35 ( V_13 ) ;
if ( V_121 < 0 )
goto V_123;
V_13 -> V_21 = V_31 ;
V_121 = F_31 ( V_31 , false , V_10 , V_114 ) ;
if ( V_121 < 0 ) {
V_124:
V_13 = V_31 -> V_43 ;
F_10 ( V_13 ) ;
V_13 -> V_21 = NULL ;
goto V_123;
}
if ( V_120 == 0 )
goto V_24;
V_13 = V_31 -> V_53 ;
if ( V_13 ) {
V_121 = F_34 ( V_19 -> V_39 , & ( V_31 -> V_4 ) , V_13 ) ;
if ( V_121 )
goto V_124;
V_121 = F_35 ( V_13 ) ;
if ( V_121 < 0 )
goto V_124;
V_13 -> V_21 = V_31 ;
V_121 = F_31 ( V_31 , true , V_7 , V_114 ) ;
if ( V_121 < 0 ) {
V_125:
V_13 = V_31 -> V_53 ;
if ( V_13 ) {
F_10 ( V_13 ) ;
V_13 -> V_21 = NULL ;
}
goto V_124;
}
}
V_13 = V_31 -> V_55 ;
if ( V_13 ) {
V_121 = F_34 ( V_19 -> V_39 , & ( V_31 -> V_4 ) , V_13 ) ;
if ( V_121 )
goto V_125;
V_121 = F_35 ( V_13 ) ;
if ( V_121 < 0 )
goto V_125;
V_13 -> V_21 = V_31 ;
V_121 = F_31 ( V_31 , false , V_7 , V_114 ) ;
if ( V_121 < 0 ) {
F_10 ( V_13 ) ;
V_13 -> V_21 = NULL ;
goto V_125;
}
}
V_24:
V_31 -> V_126 = V_120 ;
F_11 ( V_19 , L_22 , V_31 -> V_4 . V_22 , V_120 ) ;
return V_121 ;
}
static int F_36 ( struct V_2 * V_3 ,
unsigned V_127 , unsigned V_120 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_3 -> V_101 -> V_19 ;
if ( V_31 -> V_38 -> V_21 )
F_32 ( V_31 ) ;
else if ( V_120 == 2 && V_31 -> V_68 -> V_21 )
F_32 ( V_31 ) ;
return F_33 ( V_19 , V_31 , V_120 ) ;
}
static int F_37 ( struct V_2 * V_3 , unsigned V_127 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
return V_31 -> V_126 ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_31 = F_1 ( V_3 ) ;
F_32 ( V_31 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
const struct V_128 * V_129 )
{
struct V_29 * V_30 = V_3 -> V_101 ;
struct V_11 * V_16 = V_30 -> V_19 -> V_16 ;
int V_20 = - V_130 ;
T_2 V_131 = F_40 ( V_129 -> V_132 ) ;
T_2 V_133 = F_40 ( V_129 -> V_134 ) ;
T_2 V_135 = F_40 ( V_129 -> V_136 ) ;
V_16 -> V_105 = V_137 ;
switch ( V_129 -> V_138 ) {
case 0x5b :
if ( V_129 -> V_139 != ( V_140 | V_141 ) )
goto V_142;
if ( V_133 || V_131 )
break;
if ( V_135 > V_16 -> V_105 )
break;
V_20 = V_135 ;
break;
case 0x5c :
if ( V_129 -> V_139 != ( V_143 | V_141 ) )
goto V_142;
if ( V_133 || V_131 )
break;
if ( V_135 > V_16 -> V_105 )
break;
V_20 = V_135 ;
break;
default:
V_142:
F_29 ( V_30 -> V_19 ,
L_23 ,
V_129 -> V_139 , V_129 -> V_138 ,
V_133 , V_131 , V_135 ) ;
}
if ( V_20 >= 0 ) {
F_29 ( V_30 -> V_19 , L_24 ,
V_129 -> V_139 , V_129 -> V_138 ,
V_133 , V_131 , V_135 ) ;
V_16 -> V_144 = 0 ;
V_16 -> V_105 = V_20 ;
V_20 = F_30 ( V_30 -> V_19 -> V_39 -> V_145 , V_16 , V_112 ) ;
if ( V_20 < 0 )
ERROR ( V_30 -> V_19 , L_25 ,
V_20 ) ;
}
return V_20 ;
}
static struct V_2 * F_41 (
struct V_146 * V_96 )
{
struct V_1 * V_31 ;
struct V_94 * V_147 ;
V_31 = F_42 ( sizeof( * V_31 ) , V_148 ) ;
if ( ! V_31 )
return NULL ;
V_147 = F_2 ( V_96 , struct V_94 , V_97 ) ;
F_22 ( & V_147 -> V_98 ) ;
V_147 -> V_99 ++ ;
F_23 ( & V_147 -> V_98 ) ;
V_102 = V_147 -> V_102 ;
V_45 = V_147 -> V_45 ;
V_50 = V_147 -> V_50 ;
V_46 = V_147 -> V_46 ;
V_47 = V_147 -> V_47 ;
V_62 = V_147 -> V_62 ;
V_66 = V_147 -> V_66 ;
V_63 = V_147 -> V_63 ;
V_64 = V_147 -> V_64 ;
V_15 = V_147 -> V_149 ;
V_31 -> V_4 . V_22 = L_26 ;
V_31 -> V_4 . V_150 = F_13 ;
V_31 -> V_4 . V_151 = F_36 ;
V_31 -> V_4 . V_152 = F_37 ;
V_31 -> V_4 . V_153 = F_38 ;
V_31 -> V_4 . V_154 = F_39 ;
V_31 -> V_4 . V_155 = V_156 ;
V_31 -> V_4 . V_157 = F_21 ;
return & V_31 -> V_4 ;
}
static inline struct V_94 * F_43 ( struct V_158 * V_159 )
{
return F_2 ( F_44 ( V_159 ) , struct V_94 ,
V_97 . V_160 ) ;
}
static void F_45 ( struct V_158 * V_159 )
{
struct V_94 * V_147 = F_43 ( V_159 ) ;
F_46 ( & V_147 -> V_97 ) ;
}
static T_3 F_47 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_102 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_48 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_1 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_49 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 != 0 && V_162 != 1 && V_162 != 2 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_102 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_50 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_45 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_51 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_1 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_49 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 16 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_45 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_52 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_50 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_53 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_2 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_54 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 1024 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_50 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_55 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_46 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_56 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_1 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_49 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 2 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_46 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_57 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_47 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_58 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_1 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_49 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 15 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_47 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_59 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_149 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_60 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_5 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_61 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
V_95 -> V_149 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_62 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_62 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_63 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_5 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_61 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 4096 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_62 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_64 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_66 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_65 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_2 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_54 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 1024 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_66 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_66 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_63 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_67 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_1 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_49 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 2 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_63 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static T_3 F_68 ( struct V_94 * V_95 , char * V_161 )
{
int V_121 ;
F_22 ( & V_95 -> V_98 ) ;
V_121 = sprintf ( V_161 , L_27 , V_95 -> V_64 ) ;
F_23 ( & V_95 -> V_98 ) ;
return V_121 ;
}
static T_3 F_69 ( struct V_94 * V_95 ,
const char * V_161 , T_4 V_14 )
{
int V_33 ;
T_1 V_162 ;
F_22 ( & V_95 -> V_98 ) ;
if ( V_95 -> V_99 ) {
V_33 = - V_163 ;
goto V_164;
}
V_33 = F_49 ( V_161 , 0 , & V_162 ) ;
if ( V_33 )
goto V_164;
if ( V_162 > 15 ) {
V_33 = - V_104 ;
goto V_164;
}
V_95 -> V_64 = V_162 ;
V_33 = V_14 ;
V_164:
F_23 ( & V_95 -> V_98 ) ;
return V_33 ;
}
static void F_70 ( struct V_146 * V_96 )
{
struct V_94 * V_147 ;
V_147 = F_2 ( V_96 , struct V_94 , V_97 ) ;
F_7 ( V_147 ) ;
}
static struct V_146 * F_71 ( void )
{
struct V_94 * V_147 ;
V_147 = F_42 ( sizeof( * V_147 ) , V_148 ) ;
if ( ! V_147 )
return F_72 ( - V_118 ) ;
F_73 ( & V_147 -> V_98 ) ;
V_147 -> V_97 . V_165 = F_70 ;
V_147 -> V_45 = V_166 ;
V_147 -> V_50 = V_167 ;
V_147 -> V_149 = V_168 ;
V_147 -> V_62 = V_169 ;
V_147 -> V_66 = V_170 ;
F_74 ( & V_147 -> V_97 . V_160 , L_28 ,
& V_171 ) ;
return & V_147 -> V_97 ;
}
static int T_6 F_75 ( void )
{
int V_33 ;
V_33 = F_76 ( & V_172 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_77 () ;
if ( V_33 )
F_78 ( & V_172 ) ;
return V_33 ;
}
static void T_7 F_79 ( void )
{
F_78 ( & V_172 ) ;
F_80 () ;
}
