static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 , V_3 ) )
return - V_4 ;
if ( ! F_3 ( V_2 ) || F_4 ( V_2 , V_3 ) )
return 0 ;
return F_5 ( V_2 , 0 , 0 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_1 ( V_2 , V_10 ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
if ( V_2 -> V_11 == V_12 )
V_2 -> V_13 = F_8 ( V_2 -> V_13 , F_9 ( V_2 -> V_14
+ ( 2 * V_15 ) , V_16 , 0 ) ) ;
V_8 = (struct V_7 * ) ( V_2 -> V_14 + V_17 ) ;
* V_6 = V_8 -> V_18 ;
memmove ( V_2 -> V_14 + V_16 , V_2 -> V_14 , 2 * V_15 ) ;
F_10 ( V_2 , V_16 ) ;
F_11 ( V_2 , V_8 ) ;
V_2 -> V_19 += V_16 ;
if ( F_12 ( V_2 ) < V_17 )
F_13 ( V_2 , V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_20 ;
int V_9 ;
if ( F_16 ( F_17 ( V_2 ) ) ) {
V_2 -> V_21 = 0 ;
} else {
if ( F_7 ( V_2 -> V_22 != F_18 ( V_23 ) ||
V_2 -> V_24 < V_10 ) )
return 0 ;
V_9 = F_6 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
}
if ( F_16 ( V_2 -> V_22 != F_18 ( V_23 ) ||
V_2 -> V_24 < V_10 ) )
return 0 ;
V_9 = F_6 ( V_2 , & V_20 ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
F_19 ( V_2 , F_18 ( V_23 ) , F_20 ( V_20 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const struct V_25 * V_26 )
{
if ( F_7 ( F_17 ( V_2 ) ) ) {
T_2 V_27 ;
V_27 = F_22 ( V_2 ) ;
if ( ! F_23 ( V_2 , V_2 -> V_28 , V_27 ) )
return - V_4 ;
if ( V_2 -> V_11 == V_12 )
V_2 -> V_13 = F_24 ( V_2 -> V_13 , F_9 ( V_2 -> V_14
+ ( 2 * V_15 ) , V_16 , 0 ) ) ;
}
F_19 ( V_2 , V_26 -> V_29 , F_20 ( V_26 -> V_21 ) & ~ V_30 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
int V_9 ;
V_9 = F_1 ( V_2 , V_17 ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
F_26 ( V_2 , F_27 ( V_2 ) , V_15 * 2 ) ;
F_28 ( F_27 ( V_2 ) -> V_33 , V_32 -> V_34 ) ;
F_28 ( F_27 ( V_2 ) -> V_35 , V_32 -> V_36 ) ;
F_29 ( V_2 , F_27 ( V_2 ) , V_15 * 2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_37 * V_38 ,
T_3 * V_39 , T_3 V_40 )
{
int V_41 = V_2 -> V_24 - F_31 ( V_2 ) ;
if ( V_38 -> V_22 == V_42 ) {
if ( F_16 ( V_41 >= sizeof( struct V_43 ) ) )
F_32 ( & F_33 ( V_2 ) -> V_44 , V_2 ,
* V_39 , V_40 , 1 ) ;
} else if ( V_38 -> V_22 == V_45 ) {
if ( F_16 ( V_41 >= sizeof( struct V_46 ) ) ) {
struct V_46 * V_47 = F_34 ( V_2 ) ;
if ( V_47 -> V_44 || V_2 -> V_11 == V_48 ) {
F_32 ( & V_47 -> V_44 , V_2 ,
* V_39 , V_40 , 1 ) ;
if ( ! V_47 -> V_44 )
V_47 -> V_44 = V_49 ;
}
}
}
F_35 ( & V_38 -> V_44 , * V_39 , V_40 ) ;
F_36 ( V_2 ) ;
* V_39 = V_40 ;
}
static void F_37 ( struct V_1 * V_2 , T_4 V_50 ,
T_3 V_39 [ 4 ] , const T_3 V_40 [ 4 ] )
{
int V_41 = V_2 -> V_24 - F_31 ( V_2 ) ;
if ( V_50 == V_42 ) {
if ( F_16 ( V_41 >= sizeof( struct V_43 ) ) )
F_38 ( & F_33 ( V_2 ) -> V_44 , V_2 ,
V_39 , V_40 , 1 ) ;
} else if ( V_50 == V_45 ) {
if ( F_16 ( V_41 >= sizeof( struct V_46 ) ) ) {
struct V_46 * V_47 = F_34 ( V_2 ) ;
if ( V_47 -> V_44 || V_2 -> V_11 == V_48 ) {
F_38 ( & V_47 -> V_44 , V_2 ,
V_39 , V_40 , 1 ) ;
if ( ! V_47 -> V_44 )
V_47 -> V_44 = V_49 ;
}
}
}
}
static void F_39 ( struct V_1 * V_2 , T_4 V_50 ,
T_3 V_39 [ 4 ] , const T_3 V_40 [ 4 ] ,
bool V_51 )
{
if ( V_51 )
F_37 ( V_2 , V_50 , V_39 , V_40 ) ;
F_36 ( V_2 ) ;
memcpy ( V_39 , V_40 , sizeof( T_3 [ 4 ] ) ) ;
}
static void F_40 ( struct V_52 * V_38 , T_4 V_53 )
{
V_38 -> V_54 = V_53 >> 4 ;
V_38 -> V_55 [ 0 ] = ( V_38 -> V_55 [ 0 ] & 0x0F ) | ( ( V_53 & 0x0F ) << 4 ) ;
}
static void F_41 ( struct V_52 * V_38 , T_5 V_56 )
{
V_38 -> V_55 [ 0 ] = ( V_38 -> V_55 [ 0 ] & 0xF0 ) | ( V_56 & 0x000F0000 ) >> 16 ;
V_38 -> V_55 [ 1 ] = ( V_56 & 0x0000FF00 ) >> 8 ;
V_38 -> V_55 [ 2 ] = V_56 & 0x000000FF ;
}
static void F_42 ( struct V_1 * V_2 , struct V_37 * V_38 , T_4 V_57 )
{
F_43 ( & V_38 -> V_44 , F_18 ( V_38 -> V_58 << 8 ) , F_18 ( V_57 << 8 ) ) ;
V_38 -> V_58 = V_57 ;
}
static int F_44 ( struct V_1 * V_2 , const struct V_59 * V_60 )
{
struct V_37 * V_38 ;
int V_9 ;
V_9 = F_1 ( V_2 , F_12 ( V_2 ) +
sizeof( struct V_37 ) ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
V_38 = F_45 ( V_2 ) ;
if ( V_60 -> V_61 != V_38 -> V_62 )
F_30 ( V_2 , V_38 , & V_38 -> V_62 , V_60 -> V_61 ) ;
if ( V_60 -> V_63 != V_38 -> V_64 )
F_30 ( V_2 , V_38 , & V_38 -> V_64 , V_60 -> V_63 ) ;
if ( V_60 -> V_65 != V_38 -> V_66 )
F_46 ( V_38 , 0 , V_60 -> V_65 ) ;
if ( V_60 -> V_67 != V_38 -> V_58 )
F_42 ( V_2 , V_38 , V_60 -> V_67 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , const struct V_68 * V_69 )
{
struct V_52 * V_38 ;
int V_9 ;
T_3 * V_62 ;
T_3 * V_64 ;
V_9 = F_1 ( V_2 , F_12 ( V_2 ) +
sizeof( struct V_52 ) ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
V_38 = F_48 ( V_2 ) ;
V_62 = ( T_3 * ) & V_38 -> V_62 ;
V_64 = ( T_3 * ) & V_38 -> V_64 ;
if ( memcmp ( V_69 -> V_70 , V_62 , sizeof( V_69 -> V_70 ) ) )
F_39 ( V_2 , V_69 -> V_71 , V_62 ,
V_69 -> V_70 , true ) ;
if ( memcmp ( V_69 -> V_72 , V_64 , sizeof( V_69 -> V_72 ) ) ) {
unsigned int V_73 = 0 ;
int V_74 = V_75 ;
bool V_76 = true ;
if ( F_49 ( V_38 -> V_77 ) )
V_76 = F_50 ( V_2 , & V_73 ,
V_78 , NULL ,
& V_74 ) != V_78 ;
F_39 ( V_2 , V_69 -> V_71 , V_64 ,
V_69 -> V_72 , V_76 ) ;
}
F_40 ( V_38 , V_69 -> V_79 ) ;
F_41 ( V_38 , F_51 ( V_69 -> V_80 ) ) ;
V_38 -> V_81 = V_69 -> V_82 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , T_1 * V_83 ,
T_1 V_84 , T_6 * V_44 )
{
F_53 ( V_44 , V_2 , * V_83 , V_84 , 0 ) ;
* V_83 = V_84 ;
F_36 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 , T_1 * V_83 , T_1 V_84 )
{
struct V_46 * V_47 = F_34 ( V_2 ) ;
if ( V_47 -> V_44 && V_2 -> V_11 != V_48 ) {
F_52 ( V_2 , V_83 , V_84 , & V_47 -> V_44 ) ;
if ( ! V_47 -> V_44 )
V_47 -> V_44 = V_49 ;
} else {
* V_83 = V_84 ;
F_36 ( V_2 ) ;
}
}
static int F_55 ( struct V_1 * V_2 , const struct V_85 * V_86 )
{
struct V_46 * V_47 ;
int V_9 ;
V_9 = F_1 ( V_2 , F_31 ( V_2 ) +
sizeof( struct V_46 ) ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
V_47 = F_34 ( V_2 ) ;
if ( V_86 -> V_87 != V_47 -> V_88 )
F_54 ( V_2 , & V_47 -> V_88 , V_86 -> V_87 ) ;
if ( V_86 -> V_89 != V_47 -> V_90 )
F_54 ( V_2 , & V_47 -> V_90 , V_86 -> V_89 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , const struct V_91 * V_92 )
{
struct V_43 * V_93 ;
int V_9 ;
V_9 = F_1 ( V_2 , F_31 ( V_2 ) +
sizeof( struct V_43 ) ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
V_93 = F_33 ( V_2 ) ;
if ( V_92 -> V_94 != V_93 -> V_88 )
F_52 ( V_2 , & V_93 -> V_88 , V_92 -> V_94 , & V_93 -> V_44 ) ;
if ( V_92 -> V_95 != V_93 -> V_90 )
F_52 ( V_2 , & V_93 -> V_90 , V_92 -> V_95 , & V_93 -> V_44 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
const struct V_96 * V_97 )
{
struct V_98 * V_99 ;
int V_9 ;
unsigned int V_100 = F_31 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_100 + sizeof( struct V_98 ) ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
V_99 = F_58 ( V_2 ) ;
if ( V_97 -> V_101 != V_99 -> V_88 ||
V_97 -> V_102 != V_99 -> V_90 ) {
T_7 V_103 , V_104 , V_105 ;
V_105 = V_99 -> V_106 ;
V_103 = F_59 ( V_2 , V_100 ) ;
V_99 -> V_88 = V_97 -> V_101 ;
V_99 -> V_90 = V_97 -> V_102 ;
V_104 = F_59 ( V_2 , V_100 ) ;
V_99 -> V_106 = V_105 ^ V_103 ^ V_104 ;
F_36 ( V_2 ) ;
}
return 0 ;
}
static int F_60 ( struct V_107 * V_108 , struct V_1 * V_2 , int V_109 )
{
struct V_110 * V_110 ;
if ( F_7 ( ! V_2 ) )
return - V_4 ;
V_110 = F_61 ( V_108 , V_109 ) ;
if ( F_7 ( ! V_110 ) ) {
F_62 ( V_2 ) ;
return - V_111 ;
}
F_63 ( V_110 , V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_107 * V_108 , struct V_1 * V_2 ,
const struct V_112 * V_113 )
{
struct V_114 V_115 ;
const struct V_112 * V_116 ;
int V_117 ;
F_65 ( ! F_66 ( V_2 ) -> V_118 ) ;
V_115 . V_119 = V_120 ;
V_115 . V_121 = F_66 ( V_2 ) -> V_118 ;
V_115 . V_122 = NULL ;
V_115 . V_123 = 0 ;
for ( V_116 = F_67 ( V_113 ) , V_117 = F_68 ( V_113 ) ; V_117 > 0 ;
V_116 = F_69 ( V_116 , & V_117 ) ) {
switch ( F_70 ( V_116 ) ) {
case V_124 :
V_115 . V_122 = V_116 ;
break;
case V_125 :
V_115 . V_123 = F_71 ( V_116 ) ;
break;
}
}
return F_72 ( V_108 , V_2 , & V_115 ) ;
}
static bool F_73 ( const struct V_112 * V_116 , int V_117 )
{
return V_116 -> F_68 == V_117 ;
}
static int F_74 ( struct V_107 * V_108 , struct V_1 * V_2 ,
const struct V_112 * V_113 )
{
const struct V_112 * V_126 = NULL ;
const struct V_112 * V_116 ;
struct V_1 * V_127 ;
int V_117 ;
for ( V_116 = F_67 ( V_113 ) , V_117 = F_68 ( V_113 ) ; V_117 > 0 ;
V_116 = F_69 ( V_116 , & V_117 ) ) {
switch ( F_70 ( V_116 ) ) {
case V_128 :
if ( F_75 () >= F_71 ( V_116 ) )
return 0 ;
break;
case V_129 :
V_126 = V_116 ;
break;
}
}
V_117 = F_68 ( V_126 ) ;
V_116 = F_67 ( V_126 ) ;
if ( F_16 ( V_117 == 0 || ( F_70 ( V_116 ) == V_130 &&
F_73 ( V_116 , V_117 ) ) ) ) {
V_127 = V_2 ;
F_76 ( V_2 ) ;
} else {
V_127 = F_77 ( V_2 , V_5 ) ;
if ( ! V_127 )
return 0 ;
}
return F_78 ( V_108 , V_127 , V_116 , V_117 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
const struct V_112 * V_131 )
{
int V_9 = 0 ;
switch ( F_70 ( V_131 ) ) {
case V_132 :
V_2 -> V_54 = F_71 ( V_131 ) ;
break;
case V_133 :
V_2 -> V_134 = F_71 ( V_131 ) ;
break;
case V_135 :
F_66 ( V_2 ) -> V_136 = F_67 ( V_131 ) ;
break;
case V_137 :
V_9 = F_25 ( V_2 , F_67 ( V_131 ) ) ;
break;
case V_138 :
V_9 = F_44 ( V_2 , F_67 ( V_131 ) ) ;
break;
case V_139 :
V_9 = F_47 ( V_2 , F_67 ( V_131 ) ) ;
break;
case V_140 :
V_9 = F_56 ( V_2 , F_67 ( V_131 ) ) ;
break;
case V_141 :
V_9 = F_55 ( V_2 , F_67 ( V_131 ) ) ;
break;
case V_142 :
V_9 = F_57 ( V_2 , F_67 ( V_131 ) ) ;
break;
}
return V_9 ;
}
static int F_78 ( struct V_107 * V_108 , struct V_1 * V_2 ,
const struct V_112 * V_113 , int V_24 )
{
int V_143 = - 1 ;
const struct V_112 * V_116 ;
int V_117 ;
for ( V_116 = V_113 , V_117 = V_24 ; V_117 > 0 ;
V_116 = F_69 ( V_116 , & V_117 ) ) {
int V_9 = 0 ;
if ( V_143 != - 1 ) {
F_60 ( V_108 , F_77 ( V_2 , V_5 ) , V_143 ) ;
V_143 = - 1 ;
}
switch ( F_70 ( V_116 ) ) {
case V_144 :
V_143 = F_71 ( V_116 ) ;
break;
case V_130 :
F_64 ( V_108 , V_2 , V_116 ) ;
break;
case V_145 :
V_9 = F_21 ( V_2 , F_67 ( V_116 ) ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
break;
case V_146 :
V_9 = F_15 ( V_2 ) ;
break;
case V_147 :
V_9 = F_79 ( V_2 , F_67 ( V_116 ) ) ;
break;
case V_148 :
V_9 = F_74 ( V_108 , V_2 , V_116 ) ;
if ( F_7 ( V_9 ) )
return V_9 ;
break;
}
if ( F_7 ( V_9 ) ) {
F_62 ( V_2 ) ;
return V_9 ;
}
}
if ( V_143 != - 1 )
F_60 ( V_108 , V_2 , V_143 ) ;
else
F_80 ( V_2 ) ;
return 0 ;
}
int F_81 ( struct V_107 * V_108 , struct V_1 * V_2 )
{
struct V_149 * V_150 = F_82 ( F_66 ( V_2 ) -> V_151 -> V_152 ) ;
F_66 ( V_2 ) -> V_136 = NULL ;
return F_78 ( V_108 , V_2 , V_150 -> V_153 , V_150 -> V_154 ) ;
}
