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
}
static void F_15 ( struct V_20 * V_20 , struct V_13 * V_14 )
{
struct V_34 * V_21 = V_20 -> V_22 ;
struct V_23 * V_24 = V_14 -> V_16 ;
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
}
static void F_16 ( struct V_13 * V_14 , const char * V_35 )
{
struct V_3 * V_36 = ( void * ) & V_14 -> V_15 ;
F_17 ( V_28 , V_14 , L_4
L_5 ,
V_35 , V_14 , V_14 -> V_37 -> V_38 ,
( V_36 -> V_39 & V_40 ) ? L_6 : L_7 ,
( V_36 -> V_39 & V_41 ) ? L_8 : L_7 ,
( V_36 -> V_39 & V_42 ) ? L_9 : L_7 ,
( V_36 -> V_39 & V_43 ) ? L_10 : L_7 ,
( V_36 -> V_39 & V_44 ) ? L_11 : L_7 ,
( V_36 -> V_39 & V_45 ) ? L_12 : L_7 ,
( V_36 -> V_39 & V_46 ) ? L_13 : L_7 ,
( V_36 -> V_39 & V_47 ) ? L_14 : L_7 ,
( V_36 -> V_39 & V_48 ) ? L_15 : L_7 ,
( V_36 -> V_39 & V_49 ) ? L_16 : L_7 ,
( V_36 -> V_39 & V_50 ) ? L_17 : L_7 ) ;
}
static int F_18 ( struct V_13 * V_14 , const char * V_35 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
if ( V_4 -> V_39 & ( V_47 |
V_48 |
V_49 ) )
return - V_51 ;
F_19 ( V_4 -> V_39 & V_50 ) ;
V_4 -> V_39 |= V_50 ;
F_20 ( V_4 -> V_52 ) ;
F_20 ( V_4 -> V_53 ) ;
V_14 -> V_54 ( V_14 ) ;
return 0 ;
}
static void F_21 ( struct V_20 * V_20 , struct V_13 * V_14 ,
unsigned V_55 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
int V_8 ;
V_4 -> V_39 |= V_55 | V_40 ;
V_8 = F_7 ( V_14 , V_14 -> V_16 -> V_17 , V_56 ) ;
if ( V_8 ) {
F_22 ( & V_9 ) ;
F_9 ( & V_4 -> V_7 , & V_10 ) ;
F_23 ( & V_9 ) ;
F_10 ( & V_19 ) ;
}
}
static void F_24 ( struct V_20 * V_20 )
{
struct V_57 * V_57 = V_20 -> V_22 ;
struct V_58 * V_59 = V_20 -> V_60 ;
struct V_61 * V_62 = ( void * ) V_59 -> V_17 [ 0 ] ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_38 ;
if ( V_20 -> V_33 ) {
F_25 ( & V_20 -> V_63 -> V_63 , L_18 , V_20 -> V_33 ) ;
F_20 ( V_20 ) ;
return;
}
if ( V_62 -> V_64 ) {
F_20 ( V_20 ) ;
return;
}
V_38 = F_12 ( & V_57 -> V_38 ) - 1 ;
if ( V_38 == 0 )
V_14 = V_62 -> V_14 ;
else
V_14 = F_26 ( V_59 , V_38 - 1 ) ;
if ( ! V_14 ) {
if ( V_57 -> V_65 != V_66 ) {
F_20 ( V_20 ) ;
return;
}
} else {
V_4 = ( void * ) & V_14 -> V_15 ;
}
switch ( V_57 -> V_65 ) {
case V_67 :
if ( V_62 -> V_14 == V_14 )
V_62 -> V_14 = NULL ;
if ( V_20 -> V_25 < 16 )
V_62 -> F_15 = 1 ;
if ( V_62 -> F_15 )
F_15 ( V_20 , V_14 ) ;
else
F_11 ( V_20 , V_14 ) ;
if ( V_14 -> V_32 != 0 ) {
if ( V_4 -> V_39 & V_48 )
F_27 ( V_4 -> V_52 ) ;
if ( V_4 -> V_39 & V_49 )
F_27 ( V_4 -> V_53 ) ;
}
V_4 -> V_39 &= ~ V_47 ;
F_18 ( V_14 , V_29 ) ;
break;
case V_68 :
F_21 ( V_20 , V_14 , V_42 ) ;
break;
case V_69 :
F_21 ( V_20 , V_14 , V_44 ) ;
break;
case V_66 :
memcpy ( & V_62 -> V_70 , V_57 , sizeof( V_62 -> V_70 ) ) ;
break;
default:
F_17 ( V_71 , V_14 ,
L_19 , V_57 -> V_65 ) ;
}
F_20 ( V_20 ) ;
}
static void F_28 ( struct V_20 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_60 ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
struct V_72 * V_73 = NULL ;
if ( V_4 -> V_52 == V_20 ) {
V_73 = F_29 ( V_14 ) ;
V_4 -> V_39 &= ~ V_48 ;
} else if ( V_4 -> V_53 == V_20 ) {
V_73 = F_30 ( V_14 ) ;
V_4 -> V_39 &= ~ V_49 ;
}
F_19 ( V_73 == NULL ) ;
if ( V_20 -> V_33 ) {
V_73 -> V_74 = V_73 -> V_75 ;
} else {
V_73 -> V_74 = V_73 -> V_75 - V_20 -> V_25 ;
}
if ( V_4 -> V_76 ) {
return;
}
F_18 ( V_14 , V_29 ) ;
}
static struct V_20 * F_31 ( struct V_61 * V_62 , T_2 V_77 ,
unsigned int V_78 , T_1 V_79 ,
struct V_13 * V_14 ,
enum V_80 V_81 )
{
struct V_82 * V_83 = V_62 -> V_83 ;
struct V_20 * V_20 = F_32 ( 0 , V_77 ) ;
struct V_72 * V_73 = ( V_81 == V_84 )
? F_29 ( V_14 ) : F_30 ( V_14 ) ;
if ( ! V_20 )
goto V_85;
F_33 ( V_20 , V_83 , V_78 , NULL , V_73 -> V_75 ,
F_28 , V_14 ) ;
if ( V_62 -> V_86 )
V_20 -> V_79 = V_79 ;
V_20 -> V_87 = V_83 -> V_88 -> V_89 ? V_73 -> V_90 . V_91 : 0 ;
V_20 -> V_92 = V_73 -> V_90 . V_93 ;
V_85:
return V_20 ;
}
static struct V_20 * F_34 ( struct V_61 * V_62 , T_2 V_77 ,
struct V_58 * V_59 , T_1 V_79 )
{
struct V_82 * V_83 = V_62 -> V_83 ;
struct V_20 * V_20 = F_32 ( 0 , V_77 ) ;
struct V_21 * V_57 ;
if ( ! V_20 )
goto V_85;
V_57 = F_35 ( sizeof( * V_57 ) , V_77 ) ;
if ( ! V_57 )
goto free;
F_33 ( V_20 , V_83 , V_62 -> V_94 , V_57 , sizeof( * V_57 ) ,
F_24 , V_59 ) ;
V_20 -> V_79 = V_79 ;
V_20 -> V_95 |= V_96 ;
V_85:
return V_20 ;
free:
F_20 ( V_20 ) ;
return NULL ;
}
static struct V_20 * F_36 ( struct V_61 * V_62 , T_2 V_77 ,
struct V_13 * V_14 , T_1 V_79 )
{
struct V_82 * V_83 = V_62 -> V_83 ;
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_20 * V_20 = F_32 ( 0 , V_77 ) ;
struct V_97 * V_57 ;
int V_26 ;
if ( ! V_20 )
goto V_85;
V_26 = V_14 -> V_98 - 16 ;
if ( V_26 < 0 )
V_26 = 0 ;
V_26 = F_37 ( V_26 , 4 ) ;
V_57 = F_35 ( sizeof( * V_57 ) + V_26 , V_77 ) ;
if ( ! V_57 )
goto free;
V_57 -> V_65 = V_99 ;
if ( F_38 ( V_14 -> V_37 ) )
V_57 -> V_38 = F_39 ( V_14 -> V_37 -> V_38 + 2 ) ;
else
V_57 -> V_38 = F_39 ( 1 ) ;
V_57 -> V_100 = V_101 ;
V_57 -> V_26 = V_26 ;
F_40 ( V_24 -> V_102 , & V_57 -> V_102 ) ;
memcpy ( V_57 -> V_103 , V_14 -> V_14 , V_14 -> V_98 ) ;
F_33 ( V_20 , V_83 , V_62 -> V_104 , V_57 , sizeof( * V_57 ) + V_26 ,
F_20 , NULL ) ;
V_20 -> V_95 |= V_96 ;
V_85:
return V_20 ;
free:
F_20 ( V_20 ) ;
return NULL ;
}
static int F_41 ( struct V_13 * V_14 , T_2 V_77 ,
T_3 V_105 , T_1 V_79 )
{
struct V_61 * V_62 = ( void * ) V_14 -> V_16 -> V_17 ;
struct V_82 * V_83 = V_62 -> V_83 ;
struct V_20 * V_20 = F_32 ( 0 , V_77 ) ;
struct V_106 * V_57 ;
int V_8 = - V_107 ;
if ( ! V_20 )
goto V_8;
V_57 = F_35 ( sizeof( * V_57 ) , V_77 ) ;
if ( ! V_57 )
goto V_8;
V_57 -> V_65 = V_108 ;
V_57 -> V_38 = F_39 ( V_79 ) ;
F_40 ( V_14 -> V_16 -> V_102 , & V_57 -> V_102 ) ;
V_57 -> V_105 = V_105 ;
switch ( V_105 ) {
case V_109 :
if ( F_38 ( V_14 -> V_37 ) )
V_57 -> V_110 = F_39 ( V_14 -> V_37 -> V_38 + 2 ) ;
else
V_57 -> V_110 = F_39 ( 1 ) ;
break;
}
F_33 ( V_20 , V_83 , V_62 -> V_104 , V_57 , sizeof( * V_57 ) ,
F_20 , NULL ) ;
V_20 -> V_95 |= V_96 ;
V_8 = F_42 ( V_20 , V_77 ) ;
if ( V_8 )
goto V_8;
return 0 ;
V_8:
F_20 ( V_20 ) ;
return V_8 ;
}
static int F_43 ( struct V_58 * V_59 ,
T_2 V_77 , unsigned int V_111 )
{
struct V_61 * V_62 = ( void * ) V_59 -> V_17 [ 0 ] ;
struct V_20 * V_20 ;
V_20 = F_34 ( V_62 , V_77 , V_59 , V_111 ) ;
if ( ! V_20 )
return V_112 ;
if ( F_42 ( V_20 , V_77 ) ) {
F_44 ( V_28 , V_59 ,
L_20 ) ;
F_20 ( V_20 ) ;
return V_112 ;
}
F_45 ( V_20 , & V_62 -> V_113 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_61 * V_62 , T_2 V_77 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
int V_8 ;
if ( V_4 -> V_39 & V_40 ) {
V_8 = F_43 ( V_14 -> V_16 -> V_114 , V_77 ,
V_4 -> V_111 ) ;
if ( V_8 ) {
return V_8 ;
}
V_4 -> V_39 &= ~ V_40 ;
}
if ( V_4 -> V_39 & V_41 ) {
V_4 -> V_52 = F_31 ( V_62 , V_77 ,
V_62 -> V_115 , V_4 -> V_111 ,
V_14 , V_84 ) ;
if ( ! V_4 -> V_52 )
return V_112 ;
V_4 -> V_39 &= ~ V_41 ;
}
if ( V_4 -> V_39 & V_42 ) {
if ( F_42 ( V_4 -> V_52 , V_77 ) ) {
F_17 ( V_28 , V_14 ,
L_21 ) ;
return V_112 ;
}
V_4 -> V_39 &= ~ V_42 ;
V_4 -> V_39 |= V_48 ;
F_45 ( V_4 -> V_52 , & V_62 -> V_116 ) ;
}
if ( V_4 -> V_39 & V_43 ) {
V_4 -> V_53 = F_31 ( V_62 , V_77 ,
V_62 -> V_117 , V_4 -> V_111 ,
V_14 , V_118 ) ;
if ( ! V_4 -> V_53 )
return V_112 ;
V_4 -> V_39 &= ~ V_43 ;
}
if ( V_4 -> V_39 & V_44 ) {
if ( F_42 ( V_4 -> V_53 , V_77 ) ) {
F_17 ( V_28 , V_14 ,
L_22 ) ;
return V_112 ;
}
V_4 -> V_39 &= ~ V_44 ;
V_4 -> V_39 |= V_49 ;
F_45 ( V_4 -> V_53 , & V_62 -> V_116 ) ;
}
if ( V_4 -> V_39 & V_45 ) {
V_4 -> V_119 = F_36 ( V_62 , V_77 , V_14 ,
V_4 -> V_111 ) ;
if ( ! V_4 -> V_119 )
return V_112 ;
V_4 -> V_39 &= ~ V_45 ;
}
if ( V_4 -> V_39 & V_46 ) {
if ( F_42 ( V_4 -> V_119 , V_77 ) ) {
F_17 ( V_28 , V_14 ,
L_23 ) ;
return V_112 ;
}
V_4 -> V_39 &= ~ V_46 ;
V_4 -> V_39 |= V_47 ;
}
return 0 ;
}
static int F_46 ( struct V_13 * V_14 ,
void (* F_47)( struct V_13 * ) )
{
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_61 * V_62 = V_24 -> V_17 ;
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
int V_8 ;
F_48 ( sizeof( struct V_3 ) > sizeof( struct V_11 ) ) ;
if ( V_62 -> V_14 )
return V_112 ;
if ( F_38 ( V_14 -> V_37 ) ) {
V_4 -> V_111 = V_14 -> V_37 -> V_38 + 2 ;
} else {
V_62 -> V_14 = V_14 ;
V_4 -> V_111 = 1 ;
}
V_14 -> V_54 = F_47 ;
V_4 -> V_39 = V_40 |
V_45 | V_46 ;
V_4 -> V_76 = 0 ;
switch ( V_14 -> V_120 ) {
case V_84 :
V_4 -> V_39 |= V_41 | V_42 ;
break;
case V_121 :
V_4 -> V_39 |= V_41 | V_42 ;
case V_118 :
V_4 -> V_39 |= V_43 | V_44 ;
case V_122 :
break;
}
if ( ! V_62 -> V_86 ) {
V_4 -> V_39 &= ~ ( V_42 | V_44 ) ;
V_4 -> V_111 = 0 ;
}
V_8 = F_7 ( V_14 , V_62 , V_56 ) ;
if ( V_8 ) {
if ( V_4 -> V_39 & V_40 ) {
return V_112 ;
}
F_22 ( & V_9 ) ;
F_9 ( & V_4 -> V_7 , & V_10 ) ;
F_23 ( & V_9 ) ;
F_10 ( & V_19 ) ;
}
return 0 ;
}
int F_49 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = ( void * ) & V_14 -> V_15 ;
int V_123 ;
F_16 ( V_14 , V_29 ) ;
V_4 -> V_76 = 1 ;
V_123 = F_50 ( V_14 , L_24 , V_109 ) ;
if ( V_4 -> V_39 & V_48 )
F_51 ( V_4 -> V_52 ) ;
if ( V_4 -> V_39 & V_49 )
F_51 ( V_4 -> V_53 ) ;
return V_123 ;
}
static int F_52 ( struct V_13 * V_14 )
{
F_14 ( V_28 , V_14 -> V_16 , L_25 , V_29 ) ;
return F_50 ( V_14 , L_26 ,
V_124 ) ;
}
static int F_53 ( struct V_13 * V_14 )
{
struct V_23 * V_24 = V_14 -> V_16 ;
struct V_61 * V_62 = V_24 -> V_17 ;
struct V_82 * V_83 = V_62 -> V_83 ;
int V_8 ;
V_62 -> V_64 = 1 ;
F_54 ( & V_62 -> V_113 ) ;
F_54 ( & V_62 -> V_116 ) ;
V_8 = F_55 ( V_83 ) ;
V_62 -> V_64 = 0 ;
if ( V_8 ) {
F_44 ( V_28 , V_24 -> V_114 , L_27 , V_29 ) ;
return V_125 ;
}
F_44 ( V_28 , V_24 -> V_114 , L_28 , V_29 ) ;
return V_126 ;
}
static int F_56 ( struct V_23 * V_24 )
{
V_24 -> V_17 = ( void * ) V_24 -> V_114 -> V_17 [ 0 ] ;
return 0 ;
}
static int F_57 ( struct V_23 * V_24 )
{
struct V_61 * V_62 = V_24 -> V_17 ;
F_58 ( V_24 , V_127 ) ;
F_59 ( V_24 , V_62 -> V_128 - 2 ) ;
return 0 ;
}
static int F_60 ( struct V_129 * V_130 )
{
return ( V_130 -> V_131 . V_132 == V_133 &&
V_130 -> V_131 . V_134 == V_135 &&
V_130 -> V_131 . V_136 == V_137 ) ;
}
static int F_61 ( struct V_82 * V_83 )
{
struct V_138 * V_139 = F_62 ( V_83 -> V_88 ) ;
F_63 ( & V_83 -> V_63 , L_29
L_30 ,
V_139 -> V_140 -> V_141 ) ;
F_63 ( & V_83 -> V_63 , L_31
L_32 ) ;
return - V_142 ;
}
static int F_64 ( struct V_82 * V_83 ,
struct V_143 * V_130 )
{
int V_144 ;
int V_145 = V_83 -> V_88 -> V_89 != 0 ;
for ( V_144 = 0 ; V_144 < V_130 -> V_146 ; V_144 ++ ) {
struct V_129 * V_147 = & V_130 -> V_148 [ V_144 ] ;
if ( F_60 ( V_147 ) ) {
if ( ! V_145 )
return F_61 ( V_83 ) ;
return F_65 ( V_83 ,
V_147 -> V_131 . V_149 ,
V_147 -> V_131 . V_150 ) ;
}
}
return - V_142 ;
}
static void F_66 ( struct V_61 * V_62 )
{
struct V_151 * V_152 [ 4 ] = { } ;
struct V_143 * V_130 = V_62 -> V_130 ;
struct V_82 * V_83 = V_62 -> V_83 ;
struct V_151 * V_153 = V_130 -> V_154 -> V_153 ;
unsigned V_144 , V_155 = V_130 -> V_154 -> V_131 . V_156 ;
V_62 -> F_15 = 0 ;
V_62 -> V_14 = NULL ;
for ( V_144 = 0 ; V_144 < V_155 ; V_144 ++ ) {
unsigned char * V_157 = V_153 [ V_144 ] . V_157 ;
int V_26 = V_153 [ V_144 ] . V_158 ;
while ( V_26 > 1 ) {
if ( V_157 [ 1 ] == V_159 ) {
unsigned V_160 = V_157 [ 2 ] ;
if ( V_160 > 0 && V_160 < 5 )
V_152 [ V_160 - 1 ] = & V_153 [ V_144 ] ;
break;
}
V_26 -= V_157 [ 0 ] ;
V_157 += V_157 [ 0 ] ;
}
}
if ( ! V_152 [ 0 ] ) {
V_62 -> V_104 = F_67 ( V_83 , 1 ) ;
V_62 -> V_94 = F_68 ( V_83 , 1 ) ;
V_62 -> V_115 = F_68 ( V_83 , 2 ) ;
V_62 -> V_117 = F_67 ( V_83 , 2 ) ;
V_152 [ 1 ] = F_69 ( V_83 , V_62 -> V_94 ) ;
V_152 [ 2 ] = F_69 ( V_83 , V_62 -> V_115 ) ;
V_152 [ 3 ] = F_69 ( V_83 , V_62 -> V_117 ) ;
} else {
V_62 -> V_104 = F_67 ( V_83 ,
V_152 [ 0 ] -> V_131 . V_161 ) ;
V_62 -> V_94 = F_68 ( V_83 ,
V_152 [ 1 ] -> V_131 . V_161 ) ;
V_62 -> V_115 = F_68 ( V_83 ,
V_152 [ 2 ] -> V_131 . V_161 ) ;
V_62 -> V_117 = F_67 ( V_83 ,
V_152 [ 3 ] -> V_131 . V_161 ) ;
}
V_62 -> V_128 = F_70 ( V_62 -> V_130 , V_152 + 1 , 3 , 256 ,
V_162 ) ;
if ( V_62 -> V_128 < 0 ) {
V_62 -> V_128 = 256 ;
V_62 -> V_86 = 0 ;
} else {
V_62 -> V_86 = 1 ;
}
}
static void F_71 ( struct V_61 * V_62 )
{
struct V_82 * V_83 = V_62 -> V_83 ;
struct V_151 * V_152 [ 3 ] ;
V_152 [ 0 ] = F_69 ( V_83 , V_62 -> V_94 ) ;
V_152 [ 1 ] = F_69 ( V_83 , V_62 -> V_115 ) ;
V_152 [ 2 ] = F_69 ( V_83 , V_62 -> V_117 ) ;
F_72 ( V_62 -> V_130 , V_152 , 3 , V_162 ) ;
}
static int F_73 ( struct V_143 * V_130 , const struct V_163 * V_164 )
{
int V_32 ;
struct V_58 * V_59 ;
struct V_61 * V_62 ;
struct V_82 * V_83 = F_74 ( V_130 ) ;
if ( F_64 ( V_83 , V_130 ) )
return - V_142 ;
V_62 = F_75 ( sizeof( struct V_61 ) , V_162 ) ;
if ( ! V_62 )
return - V_107 ;
V_32 = - V_107 ;
V_59 = F_76 ( & V_165 , sizeof( void * ) ) ;
if ( ! V_59 )
goto free;
V_59 -> V_166 = 16 + 252 ;
V_59 -> V_167 = 1 ;
V_59 -> V_89 = V_83 -> V_88 -> V_89 ;
V_62 -> V_130 = V_130 ;
V_62 -> V_83 = V_83 ;
V_62 -> V_64 = 0 ;
F_77 ( & V_62 -> V_113 ) ;
F_77 ( & V_62 -> V_116 ) ;
F_66 ( V_62 ) ;
V_32 = F_78 ( V_59 , V_62 -> V_128 - 2 ) ;
if ( V_32 )
goto free;
V_32 = F_79 ( V_59 , & V_130 -> V_63 ) ;
if ( V_32 )
goto V_168;
V_59 -> V_17 [ 0 ] = ( unsigned long ) V_62 ;
F_80 ( V_59 ) ;
F_81 ( V_130 , V_59 ) ;
return V_32 ;
V_168:
F_71 ( V_62 ) ;
free:
F_82 ( V_62 ) ;
if ( V_59 )
F_83 ( V_59 ) ;
return V_32 ;
}
static int F_84 ( struct V_143 * V_130 )
{
return 0 ;
}
static int F_85 ( struct V_143 * V_130 )
{
return 0 ;
}
static void F_86 ( struct V_143 * V_130 )
{
struct V_58 * V_59 = F_87 ( V_130 ) ;
struct V_61 * V_62 = ( void * ) V_59 -> V_17 [ 0 ] ;
F_88 ( V_59 ) ;
F_54 ( & V_62 -> V_113 ) ;
F_54 ( & V_62 -> V_116 ) ;
F_71 ( V_62 ) ;
F_82 ( V_62 ) ;
}
