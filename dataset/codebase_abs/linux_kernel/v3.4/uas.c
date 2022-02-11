static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
struct V_6 V_7 ;
int V_8 ;
F_2 ( & V_9 ) ;
F_3 ( & V_10 , & V_7 ) ;
F_4 ( & V_9 ) ;
F_5 (cmdinfo, temp, &list, list) {
struct V_11 * V_12 = ( void * ) V_4 ;
struct V_13 * V_14 = F_6 ( V_12 ,
struct V_13 , V_15 ) ;
V_8 = F_7 ( V_14 , V_14 -> V_16 -> V_17 , V_18 ) ;
if ( V_8 ) {
F_8 ( & V_4 -> V_7 ) ;
F_2 ( & V_9 ) ;
F_9 ( & V_4 -> V_7 , & V_10 ) ;
F_4 ( & V_9 ) ;
F_10 ( & V_19 ) ;
}
}
}
static void F_11 ( struct V_20 * V_20 , struct V_13 * V_14 )
{
struct V_21 * V_21 = V_20 -> V_22 ;
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
if ( V_20 -> V_25 > 16 ) {
unsigned V_26 = F_12 ( & V_21 -> V_26 ) ;
if ( V_26 + 16 != V_20 -> V_25 ) {
int V_27 = F_13 ( V_26 + 16 , V_20 -> V_25 ) - 16 ;
if ( V_27 < 0 )
V_27 = 0 ;
F_14 ( V_28 , V_24 , L_1
L_2
L_3 , V_29 ,
V_20 -> V_25 , V_26 , V_27 ) ;
V_26 = V_27 ;
}
memcpy ( V_14 -> V_30 , V_21 -> V_31 , V_26 ) ;
}
V_14 -> V_32 = V_21 -> V_33 ;
if ( ! ( V_4 -> V_34 & V_35 ) )
V_14 -> V_36 ( V_14 ) ;
}
static void F_15 ( struct V_20 * V_20 , struct V_13 * V_14 )
{
struct V_37 * V_21 = V_20 -> V_22 ;
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
if ( V_20 -> V_25 > 8 ) {
unsigned V_26 = F_12 ( & V_21 -> V_26 ) - 2 ;
if ( V_26 + 8 != V_20 -> V_25 ) {
int V_27 = F_13 ( V_26 + 8 , V_20 -> V_25 ) - 8 ;
if ( V_27 < 0 )
V_27 = 0 ;
F_14 ( V_28 , V_24 , L_1
L_2
L_3 , V_29 ,
V_20 -> V_25 , V_26 , V_27 ) ;
V_26 = V_27 ;
}
memcpy ( V_14 -> V_30 , V_21 -> V_31 , V_26 ) ;
}
V_14 -> V_32 = V_21 -> V_33 ;
if ( ! ( V_4 -> V_34 & V_35 ) )
V_14 -> V_36 ( V_14 ) ;
}
static void F_16 ( struct V_20 * V_20 , struct V_13 * V_14 ,
unsigned V_38 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
int V_8 ;
V_4 -> V_34 = V_38 ;
V_8 = F_7 ( V_14 , V_14 -> V_16 -> V_17 , V_39 ) ;
if ( V_8 ) {
F_17 ( & V_9 ) ;
F_9 ( & V_4 -> V_7 , & V_10 ) ;
F_18 ( & V_9 ) ;
F_10 ( & V_19 ) ;
}
}
static void F_19 ( struct V_20 * V_20 )
{
struct V_40 * V_40 = V_20 -> V_22 ;
struct V_41 * V_42 = V_20 -> V_43 ;
struct V_44 * V_45 = ( void * ) V_42 -> V_17 [ 0 ] ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_46 ;
int V_47 ;
if ( V_20 -> V_33 ) {
F_20 ( & V_20 -> V_48 -> V_48 , L_4 , V_20 -> V_33 ) ;
if ( V_45 -> V_49 )
F_21 ( V_20 ) ;
return;
}
V_46 = F_12 ( & V_40 -> V_46 ) - 1 ;
if ( V_46 == 0 )
V_14 = V_45 -> V_14 ;
else
V_14 = F_22 ( V_42 , V_46 - 1 ) ;
if ( ! V_14 ) {
if ( V_45 -> V_49 ) {
F_21 ( V_20 ) ;
return;
}
V_47 = F_23 ( V_20 , V_39 ) ;
if ( V_47 )
F_20 ( & V_20 -> V_48 -> V_48 , L_5 ) ;
return;
}
V_4 = ( void * ) & V_14 -> V_15 ;
switch ( V_40 -> V_50 ) {
case V_51 :
if ( V_45 -> V_14 == V_14 )
V_45 -> V_14 = NULL ;
if ( ! ( V_4 -> V_34 & V_52 ) &&
V_4 -> V_53 ) {
if ( V_45 -> V_49 ) {
V_4 -> V_34 |= V_35 ;
F_24 ( V_4 -> V_53 ) ;
} else {
F_21 ( V_4 -> V_53 ) ;
}
}
if ( ! ( V_4 -> V_34 & V_54 ) &&
V_4 -> V_55 ) {
if ( V_45 -> V_49 ) {
V_4 -> V_34 |= V_35 ;
F_24 ( V_4 -> V_53 ) ;
} else {
F_21 ( V_4 -> V_55 ) ;
}
}
if ( V_20 -> V_25 < 16 )
V_45 -> F_15 = 1 ;
if ( V_45 -> F_15 )
F_15 ( V_20 , V_14 ) ;
else
F_11 ( V_20 , V_14 ) ;
break;
case V_56 :
F_16 ( V_20 , V_14 , V_57 ) ;
break;
case V_58 :
F_16 ( V_20 , V_14 , V_59 ) ;
break;
default:
F_25 ( V_60 , V_14 ,
L_6 , V_40 -> V_50 ) ;
}
if ( V_45 -> V_49 ) {
F_21 ( V_20 ) ;
return;
}
V_47 = F_23 ( V_20 , V_39 ) ;
if ( V_47 )
F_20 ( & V_20 -> V_48 -> V_48 , L_5 ) ;
}
static void F_26 ( struct V_20 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_43 ;
struct V_61 * V_62 = F_27 ( V_14 ) ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
V_4 -> V_34 |= V_54 ;
V_62 -> V_63 = V_62 -> V_64 - V_20 -> V_25 ;
F_21 ( V_20 ) ;
if ( V_4 -> V_34 & V_35 )
V_14 -> V_36 ( V_14 ) ;
}
static void F_28 ( struct V_20 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_43 ;
struct V_61 * V_62 = F_29 ( V_14 ) ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
V_4 -> V_34 |= V_52 ;
V_62 -> V_63 = V_62 -> V_64 - V_20 -> V_25 ;
F_21 ( V_20 ) ;
if ( V_4 -> V_34 & V_35 )
V_14 -> V_36 ( V_14 ) ;
}
static struct V_20 * F_30 ( struct V_44 * V_45 , T_2 V_65 ,
unsigned int V_66 , struct V_13 * V_14 ,
enum V_67 V_68 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
struct V_69 * V_70 = V_45 -> V_70 ;
struct V_20 * V_20 = F_31 ( 0 , V_65 ) ;
struct V_61 * V_62 ;
T_3 V_71 ;
T_1 V_72 = V_4 -> V_73 ;
if ( ! V_20 )
goto V_74;
if ( V_68 == V_75 ) {
V_62 = F_29 ( V_14 ) ;
V_71 = F_28 ;
} else {
V_62 = F_27 ( V_14 ) ;
V_71 = F_26 ;
}
F_32 ( V_20 , V_70 , V_66 , NULL , V_62 -> V_64 ,
V_71 , V_14 ) ;
V_20 -> V_72 = V_72 ;
V_20 -> V_76 = V_70 -> V_77 -> V_78 ? V_62 -> V_79 . V_80 : 0 ;
V_20 -> V_81 = V_62 -> V_79 . V_82 ;
V_74:
return V_20 ;
}
static struct V_20 * F_33 ( struct V_44 * V_45 , T_2 V_65 ,
struct V_41 * V_42 , T_1 V_72 )
{
struct V_69 * V_70 = V_45 -> V_70 ;
struct V_20 * V_20 = F_31 ( 0 , V_65 ) ;
struct V_21 * V_40 ;
if ( ! V_20 )
goto V_74;
V_40 = F_34 ( sizeof( * V_40 ) , V_65 ) ;
if ( ! V_40 )
goto free;
F_32 ( V_20 , V_70 , V_45 -> V_83 , V_40 , sizeof( * V_40 ) ,
F_19 , V_42 ) ;
V_20 -> V_72 = V_72 ;
V_20 -> V_84 |= V_85 ;
V_74:
return V_20 ;
free:
F_21 ( V_20 ) ;
return NULL ;
}
static struct V_20 * F_35 ( struct V_44 * V_45 , T_2 V_65 ,
struct V_13 * V_14 , T_1 V_72 )
{
struct V_69 * V_70 = V_45 -> V_70 ;
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_20 * V_20 = F_31 ( 0 , V_65 ) ;
struct V_86 * V_40 ;
int V_26 ;
if ( ! V_20 )
goto V_74;
V_26 = V_14 -> V_87 - 16 ;
if ( V_26 < 0 )
V_26 = 0 ;
V_26 = F_36 ( V_26 , 4 ) ;
V_40 = F_34 ( sizeof( * V_40 ) + V_26 , V_65 ) ;
if ( ! V_40 )
goto free;
V_40 -> V_50 = V_88 ;
if ( F_37 ( V_14 -> V_89 ) )
V_40 -> V_46 = F_38 ( V_14 -> V_89 -> V_46 + 2 ) ;
else
V_40 -> V_46 = F_38 ( 1 ) ;
V_40 -> V_90 = V_91 ;
V_40 -> V_26 = V_26 ;
F_39 ( V_24 -> V_92 , & V_40 -> V_92 ) ;
memcpy ( V_40 -> V_93 , V_14 -> V_14 , V_14 -> V_87 ) ;
F_32 ( V_20 , V_70 , V_45 -> V_94 , V_40 , sizeof( * V_40 ) + V_26 ,
F_21 , NULL ) ;
V_20 -> V_84 |= V_85 ;
V_74:
return V_20 ;
free:
F_21 ( V_20 ) ;
return NULL ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_44 * V_45 , T_2 V_65 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
if ( V_4 -> V_34 & V_95 ) {
V_4 -> V_96 = F_33 ( V_45 , V_65 ,
V_14 -> V_16 -> V_97 , V_4 -> V_73 ) ;
if ( ! V_4 -> V_96 )
return V_98 ;
V_4 -> V_34 &= ~ V_95 ;
}
if ( V_4 -> V_34 & V_99 ) {
if ( F_23 ( V_4 -> V_96 , V_65 ) ) {
F_25 ( V_28 , V_14 ,
L_7 ) ;
return V_98 ;
}
V_4 -> V_34 &= ~ V_99 ;
}
if ( V_4 -> V_34 & V_100 ) {
V_4 -> V_53 = F_30 ( V_45 , V_65 ,
V_45 -> V_101 , V_14 ,
V_75 ) ;
if ( ! V_4 -> V_53 )
return V_98 ;
V_4 -> V_34 &= ~ V_100 ;
}
if ( V_4 -> V_34 & V_57 ) {
if ( F_23 ( V_4 -> V_53 , V_65 ) ) {
F_25 ( V_28 , V_14 ,
L_8 ) ;
return V_98 ;
}
V_4 -> V_34 &= ~ V_57 ;
}
if ( V_4 -> V_34 & V_102 ) {
V_4 -> V_55 = F_30 ( V_45 , V_65 ,
V_45 -> V_103 , V_14 ,
V_104 ) ;
if ( ! V_4 -> V_55 )
return V_98 ;
V_4 -> V_34 &= ~ V_102 ;
}
if ( V_4 -> V_34 & V_59 ) {
if ( F_23 ( V_4 -> V_55 , V_65 ) ) {
F_25 ( V_28 , V_14 ,
L_9 ) ;
return V_98 ;
}
V_4 -> V_34 &= ~ V_59 ;
}
if ( V_4 -> V_34 & V_105 ) {
V_4 -> V_106 = F_35 ( V_45 , V_65 , V_14 ,
V_4 -> V_73 ) ;
if ( ! V_4 -> V_106 )
return V_98 ;
V_4 -> V_34 &= ~ V_105 ;
}
if ( V_4 -> V_34 & V_107 ) {
if ( F_23 ( V_4 -> V_106 , V_65 ) ) {
F_25 ( V_28 , V_14 ,
L_10 ) ;
return V_98 ;
}
V_4 -> V_34 &= ~ V_107 ;
}
return 0 ;
}
static int F_40 ( struct V_13 * V_14 ,
void (* F_41)( struct V_13 * ) )
{
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_44 * V_45 = V_24 -> V_17 ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
int V_8 ;
F_42 ( sizeof( struct V_3 ) > sizeof( struct V_11 ) ) ;
if ( V_45 -> V_14 )
return V_98 ;
if ( F_37 ( V_14 -> V_89 ) ) {
V_4 -> V_73 = V_14 -> V_89 -> V_46 + 2 ;
} else {
V_45 -> V_14 = V_14 ;
V_4 -> V_73 = 1 ;
}
V_14 -> V_36 = F_41 ;
V_4 -> V_34 = V_95 | V_99 |
V_105 | V_107 ;
switch ( V_14 -> V_108 ) {
case V_75 :
V_4 -> V_34 |= V_100 | V_57 ;
break;
case V_109 :
V_4 -> V_34 |= V_100 | V_57 ;
case V_104 :
V_4 -> V_34 |= V_102 | V_59 ;
case V_110 :
break;
}
if ( ! V_45 -> V_49 ) {
V_4 -> V_34 &= ~ ( V_57 | V_59 |
V_95 | V_99 ) ;
V_4 -> V_73 = 0 ;
}
V_8 = F_7 ( V_14 , V_45 , V_39 ) ;
if ( V_8 ) {
if ( V_4 -> V_34 & V_99 ) {
F_21 ( V_4 -> V_96 ) ;
return V_98 ;
}
F_17 ( & V_9 ) ;
F_9 ( & V_4 -> V_7 , & V_10 ) ;
F_18 ( & V_9 ) ;
F_10 ( & V_19 ) ;
}
return 0 ;
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_23 * V_24 = V_14 -> V_16 ;
F_14 ( V_28 , V_24 , L_11 , V_29 ,
V_14 -> V_89 -> V_46 ) ;
return V_111 ;
}
static int F_44 ( struct V_13 * V_14 )
{
struct V_23 * V_24 = V_14 -> V_16 ;
F_14 ( V_28 , V_24 , L_11 , V_29 ,
V_14 -> V_89 -> V_46 ) ;
return V_111 ;
}
static int F_45 ( struct V_13 * V_14 )
{
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_44 * V_45 = V_24 -> V_17 ;
struct V_69 * V_70 = V_45 -> V_70 ;
F_14 ( V_28 , V_24 , L_11 , V_29 ,
V_14 -> V_89 -> V_46 ) ;
if ( F_46 ( V_70 ) )
return V_112 ;
return V_111 ;
}
static int F_47 ( struct V_23 * V_24 )
{
V_24 -> V_17 = ( void * ) V_24 -> V_97 -> V_17 [ 0 ] ;
return 0 ;
}
static int F_48 ( struct V_23 * V_24 )
{
struct V_44 * V_45 = V_24 -> V_17 ;
F_49 ( V_24 , V_113 ) ;
F_50 ( V_24 , V_45 -> V_114 - 2 ) ;
return 0 ;
}
static int F_51 ( struct V_115 * V_116 )
{
return ( V_116 -> V_117 . V_118 == V_119 &&
V_116 -> V_117 . V_120 == V_121 &&
V_116 -> V_117 . V_122 == V_123 ) ;
}
static int F_52 ( struct V_69 * V_70 )
{
struct V_124 * V_125 = F_53 ( V_70 -> V_77 ) ;
F_54 ( & V_70 -> V_48 , L_12
L_13 ,
V_125 -> V_126 -> V_127 ) ;
F_54 ( & V_70 -> V_48 , L_14
L_15 ) ;
return - V_128 ;
}
static int F_55 ( struct V_69 * V_70 ,
struct V_129 * V_116 )
{
int V_130 ;
int V_131 = V_70 -> V_77 -> V_78 != 0 ;
for ( V_130 = 0 ; V_130 < V_116 -> V_132 ; V_130 ++ ) {
struct V_115 * V_133 = & V_116 -> V_134 [ V_130 ] ;
if ( F_51 ( V_133 ) ) {
if ( ! V_131 )
return F_52 ( V_70 ) ;
return F_56 ( V_70 ,
V_133 -> V_117 . V_135 ,
V_133 -> V_117 . V_136 ) ;
}
}
return - V_128 ;
}
static void F_57 ( struct V_44 * V_45 )
{
struct V_137 * V_138 [ 4 ] = { } ;
struct V_129 * V_116 = V_45 -> V_116 ;
struct V_69 * V_70 = V_45 -> V_70 ;
struct V_137 * V_139 = V_116 -> V_140 -> V_139 ;
unsigned V_130 , V_141 = V_116 -> V_140 -> V_117 . V_142 ;
V_45 -> F_15 = 0 ;
V_45 -> V_14 = NULL ;
for ( V_130 = 0 ; V_130 < V_141 ; V_130 ++ ) {
unsigned char * V_143 = V_139 [ V_130 ] . V_143 ;
int V_26 = V_139 [ V_130 ] . V_144 ;
while ( V_26 > 1 ) {
if ( V_143 [ 1 ] == V_145 ) {
unsigned V_146 = V_143 [ 2 ] ;
if ( V_146 > 0 && V_146 < 5 )
V_138 [ V_146 - 1 ] = & V_139 [ V_130 ] ;
break;
}
V_26 -= V_143 [ 0 ] ;
V_143 += V_143 [ 0 ] ;
}
}
if ( ! V_138 [ 0 ] ) {
V_45 -> V_94 = F_58 ( V_70 , 1 ) ;
V_45 -> V_83 = F_59 ( V_70 , 1 ) ;
V_45 -> V_101 = F_59 ( V_70 , 2 ) ;
V_45 -> V_103 = F_58 ( V_70 , 2 ) ;
V_138 [ 1 ] = F_60 ( V_70 , V_45 -> V_83 ) ;
V_138 [ 2 ] = F_60 ( V_70 , V_45 -> V_101 ) ;
V_138 [ 3 ] = F_60 ( V_70 , V_45 -> V_103 ) ;
} else {
V_45 -> V_94 = F_58 ( V_70 ,
V_138 [ 0 ] -> V_117 . V_147 ) ;
V_45 -> V_83 = F_59 ( V_70 ,
V_138 [ 1 ] -> V_117 . V_147 ) ;
V_45 -> V_101 = F_59 ( V_70 ,
V_138 [ 2 ] -> V_117 . V_147 ) ;
V_45 -> V_103 = F_58 ( V_70 ,
V_138 [ 3 ] -> V_117 . V_147 ) ;
}
V_45 -> V_114 = F_61 ( V_45 -> V_116 , V_138 + 1 , 3 , 256 ,
V_148 ) ;
if ( V_45 -> V_114 < 0 ) {
V_45 -> V_114 = 256 ;
V_45 -> V_49 = 0 ;
} else {
V_45 -> V_49 = 1 ;
}
}
static int F_62 ( struct V_44 * V_45 ,
struct V_41 * V_42 )
{
if ( V_45 -> V_49 ) {
V_45 -> V_96 = NULL ;
return 0 ;
}
V_45 -> V_96 = F_33 ( V_45 , V_148 ,
V_42 , 0 ) ;
if ( ! V_45 -> V_96 )
goto V_149;
if ( F_23 ( V_45 -> V_96 , V_148 ) )
goto V_150;
return 0 ;
V_150:
F_21 ( V_45 -> V_96 ) ;
V_149:
return - V_151 ;
}
static void F_63 ( struct V_44 * V_45 )
{
struct V_69 * V_70 = V_45 -> V_70 ;
struct V_137 * V_138 [ 3 ] ;
V_138 [ 0 ] = F_60 ( V_70 , V_45 -> V_83 ) ;
V_138 [ 1 ] = F_60 ( V_70 , V_45 -> V_101 ) ;
V_138 [ 2 ] = F_60 ( V_70 , V_45 -> V_103 ) ;
F_64 ( V_45 -> V_116 , V_138 , 3 , V_148 ) ;
}
static int F_65 ( struct V_129 * V_116 , const struct V_152 * V_153 )
{
int V_32 ;
struct V_41 * V_42 ;
struct V_44 * V_45 ;
struct V_69 * V_70 = F_66 ( V_116 ) ;
if ( F_55 ( V_70 , V_116 ) )
return - V_128 ;
V_45 = F_67 ( sizeof( struct V_44 ) , V_148 ) ;
if ( ! V_45 )
return - V_151 ;
V_32 = - V_151 ;
V_42 = F_68 ( & V_154 , sizeof( void * ) ) ;
if ( ! V_42 )
goto free;
V_42 -> V_155 = 16 + 252 ;
V_42 -> V_156 = 1 ;
V_42 -> V_78 = V_70 -> V_77 -> V_78 ;
V_45 -> V_116 = V_116 ;
V_45 -> V_70 = V_70 ;
F_57 ( V_45 ) ;
V_32 = F_69 ( V_42 , V_45 -> V_114 - 2 ) ;
if ( V_32 )
goto free;
V_32 = F_70 ( V_42 , & V_116 -> V_48 ) ;
if ( V_32 )
goto V_157;
V_42 -> V_17 [ 0 ] = ( unsigned long ) V_45 ;
V_32 = F_62 ( V_45 , V_42 ) ;
if ( V_32 )
goto V_158;
F_71 ( V_42 ) ;
F_72 ( V_116 , V_42 ) ;
return V_32 ;
V_158:
F_73 ( V_42 ) ;
V_42 = NULL ;
V_157:
F_63 ( V_45 ) ;
free:
F_74 ( V_45 ) ;
if ( V_42 )
F_75 ( V_42 ) ;
return V_32 ;
}
static int F_76 ( struct V_129 * V_116 )
{
return 0 ;
}
static int F_77 ( struct V_129 * V_116 )
{
return 0 ;
}
static void F_78 ( struct V_129 * V_116 )
{
struct V_41 * V_42 = F_79 ( V_116 ) ;
struct V_44 * V_45 = ( void * ) V_42 -> V_17 [ 0 ] ;
F_73 ( V_42 ) ;
F_80 ( V_45 -> V_96 ) ;
F_21 ( V_45 -> V_96 ) ;
F_63 ( V_45 ) ;
F_74 ( V_45 ) ;
}
