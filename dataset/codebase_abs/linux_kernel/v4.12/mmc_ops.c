int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
struct V_5 V_6 = {} ;
V_6 . V_7 = V_8 ;
if ( ! F_2 ( V_2 -> V_9 ) )
V_6 . V_10 = V_2 -> V_11 << 16 ;
V_6 . V_12 = V_13 | V_14 | V_15 ;
V_4 = F_3 ( V_2 -> V_9 , & V_6 , V_16 ) ;
if ( V_4 )
return V_4 ;
if ( V_3 )
* V_3 = V_6 . V_17 [ 0 ] ;
return 0 ;
}
static int F_4 ( struct V_18 * V_9 , struct V_1 * V_2 )
{
struct V_5 V_6 = {} ;
V_6 . V_7 = V_19 ;
if ( V_2 ) {
V_6 . V_10 = V_2 -> V_11 << 16 ;
V_6 . V_12 = V_14 | V_15 ;
} else {
V_6 . V_10 = 0 ;
V_6 . V_12 = V_20 | V_15 ;
}
return F_3 ( V_9 , & V_6 , V_16 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_9 , V_2 ) ;
}
int F_6 ( struct V_18 * V_9 )
{
return F_4 ( V_9 , NULL ) ;
}
int F_7 ( struct V_18 * V_9 )
{
struct V_5 V_6 = {} ;
V_6 . V_7 = V_21 ;
V_6 . V_10 = ( V_9 -> V_22 << 16 ) | 0xffff ;
V_6 . V_12 = V_20 | V_15 ;
return F_3 ( V_9 , & V_6 , V_16 ) ;
}
int F_8 ( struct V_18 * V_9 )
{
int V_4 ;
struct V_5 V_6 = {} ;
if ( ! F_2 ( V_9 ) ) {
F_9 ( V_9 , V_23 ) ;
F_10 ( 1 ) ;
}
V_6 . V_7 = V_24 ;
V_6 . V_10 = 0 ;
V_6 . V_12 = V_25 | V_20 | V_26 ;
V_4 = F_3 ( V_9 , & V_6 , 0 ) ;
F_10 ( 1 ) ;
if ( ! F_2 ( V_9 ) ) {
F_9 ( V_9 , V_27 ) ;
F_10 ( 1 ) ;
}
V_9 -> V_28 = 0 ;
return V_4 ;
}
int F_11 ( struct V_18 * V_9 , T_1 V_29 , T_1 * V_30 )
{
struct V_5 V_6 = {} ;
int V_31 , V_4 = 0 ;
V_6 . V_7 = V_32 ;
V_6 . V_10 = F_2 ( V_9 ) ? 0 : V_29 ;
V_6 . V_12 = V_25 | V_33 | V_34 ;
for ( V_31 = 100 ; V_31 ; V_31 -- ) {
V_4 = F_3 ( V_9 , & V_6 , 0 ) ;
if ( V_4 )
break;
if ( V_29 == 0 )
break;
if ( F_2 ( V_9 ) ) {
if ( ! ( V_6 . V_17 [ 0 ] & V_35 ) )
break;
} else {
if ( V_6 . V_17 [ 0 ] & V_36 )
break;
}
V_4 = - V_37 ;
F_10 ( 10 ) ;
}
if ( V_30 && ! F_2 ( V_9 ) )
* V_30 = V_6 . V_17 [ 0 ] ;
return V_4 ;
}
int F_12 ( struct V_18 * V_9 , T_1 * V_38 )
{
int V_4 ;
struct V_5 V_6 = {} ;
V_6 . V_7 = V_39 ;
V_6 . V_10 = 0 ;
V_6 . V_12 = V_40 | V_34 ;
V_4 = F_3 ( V_9 , & V_6 , V_16 ) ;
if ( V_4 )
return V_4 ;
memcpy ( V_38 , V_6 . V_17 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_5 V_6 = {} ;
V_6 . V_7 = V_41 ;
V_6 . V_10 = V_2 -> V_11 << 16 ;
V_6 . V_12 = V_14 | V_15 ;
return F_3 ( V_2 -> V_9 , & V_6 , V_16 ) ;
}
static int
F_14 ( struct V_18 * V_9 , T_1 V_10 , T_1 * V_42 , int V_7 )
{
int V_4 ;
struct V_5 V_6 = {} ;
V_6 . V_7 = V_7 ;
V_6 . V_10 = V_10 ;
V_6 . V_12 = V_40 | V_15 ;
V_4 = F_3 ( V_9 , & V_6 , V_16 ) ;
if ( V_4 )
return V_4 ;
memcpy ( V_42 , V_6 . V_17 , sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_18 * V_9 ,
T_1 V_7 , void * V_43 , unsigned V_44 )
{
struct V_45 V_46 = {} ;
struct V_5 V_6 = {} ;
struct V_47 V_48 = {} ;
struct V_49 V_50 ;
V_46 . V_6 = & V_6 ;
V_46 . V_48 = & V_48 ;
V_6 . V_7 = V_7 ;
V_6 . V_10 = 0 ;
V_6 . V_12 = V_25 | V_14 | V_51 ;
V_48 . V_52 = V_44 ;
V_48 . V_53 = 1 ;
V_48 . V_12 = V_54 ;
V_48 . V_50 = & V_50 ;
V_48 . V_55 = 1 ;
F_16 ( & V_50 , V_43 , V_44 ) ;
if ( V_7 == V_56 || V_7 == V_57 ) {
V_48 . V_58 = 0 ;
V_48 . V_59 = 64 ;
} else
F_17 ( & V_48 , V_2 ) ;
F_18 ( V_9 , & V_46 ) ;
if ( V_6 . error )
return V_6 . error ;
if ( V_48 . error )
return V_48 . error ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_1 * V_60 )
{
int V_61 , V_31 ;
T_2 * V_62 ;
if ( ! F_2 ( V_2 -> V_9 ) )
return F_14 ( V_2 -> V_9 , V_2 -> V_11 << 16 ,
V_60 , V_56 ) ;
V_62 = F_20 ( 16 , V_63 ) ;
if ( ! V_62 )
return - V_64 ;
V_61 = F_15 ( V_2 , V_2 -> V_9 , V_56 , V_62 , 16 ) ;
if ( V_61 )
goto V_4;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
V_60 [ V_31 ] = F_21 ( V_62 [ V_31 ] ) ;
V_4:
F_22 ( V_62 ) ;
return V_61 ;
}
int F_23 ( struct V_18 * V_9 , T_1 * V_38 )
{
int V_61 , V_31 ;
T_2 * V_65 ;
if ( ! F_2 ( V_9 ) ) {
if ( ! V_9 -> V_2 )
return - V_66 ;
return F_14 ( V_9 , V_9 -> V_2 -> V_11 << 16 ,
V_38 , V_57 ) ;
}
V_65 = F_20 ( 16 , V_63 ) ;
if ( ! V_65 )
return - V_64 ;
V_61 = F_15 ( NULL , V_9 , V_57 , V_65 , 16 ) ;
if ( V_61 )
goto V_4;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ )
V_38 [ V_31 ] = F_21 ( V_65 [ V_31 ] ) ;
V_4:
F_22 ( V_65 ) ;
return V_61 ;
}
int F_24 ( struct V_1 * V_2 , T_3 * * V_67 )
{
int V_4 ;
T_3 * V_68 ;
if ( ! V_2 || ! V_67 )
return - V_66 ;
if ( ! F_25 ( V_2 ) )
return - V_69 ;
V_68 = F_20 ( 512 , V_63 ) ;
if ( ! V_68 )
return - V_64 ;
V_4 = F_15 ( V_2 , V_2 -> V_9 , V_70 , V_68 ,
512 ) ;
if ( V_4 )
F_22 ( V_68 ) ;
else
* V_67 = V_68 ;
return V_4 ;
}
int F_26 ( struct V_18 * V_9 , int V_71 , T_1 * V_72 )
{
struct V_5 V_6 = {} ;
int V_4 ;
V_6 . V_7 = V_73 ;
V_6 . V_10 = V_71 ? ( 1 << 30 ) : 0 ;
V_6 . V_12 = V_74 ;
V_4 = F_3 ( V_9 , & V_6 , 0 ) ;
* V_72 = V_6 . V_17 [ 1 ] ;
return V_4 ;
}
int F_27 ( struct V_18 * V_9 , int V_75 )
{
struct V_5 V_6 = {} ;
int V_4 ;
V_6 . V_7 = V_76 ;
V_6 . V_12 = V_25 ;
V_6 . V_10 = V_75 ;
V_4 = F_3 ( V_9 , & V_6 , 0 ) ;
if ( ! V_4 )
V_9 -> V_28 = V_75 ;
return V_4 ;
}
static int F_28 ( struct V_18 * V_9 , T_1 V_3 )
{
if ( F_2 ( V_9 ) ) {
if ( V_3 & V_77 )
return - V_78 ;
} else {
if ( V_3 & 0xFDFFA000 )
F_29 ( L_1 ,
F_30 ( V_9 ) , V_3 ) ;
if ( V_3 & V_79 )
return - V_78 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , bool V_80 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( ! V_80 && V_4 == - V_81 )
return 0 ;
if ( V_4 )
return V_4 ;
return F_28 ( V_2 -> V_9 , V_3 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
return F_31 ( V_2 , true ) ;
}
static int F_33 ( struct V_1 * V_2 , unsigned int V_82 ,
bool V_83 , bool V_84 )
{
struct V_18 * V_9 = V_2 -> V_9 ;
int V_4 ;
unsigned long V_85 ;
T_1 V_3 = 0 ;
bool V_86 = false ;
bool V_87 = false ;
if ( ! V_82 )
V_82 = V_88 ;
if ( ! V_83 && ! V_9 -> V_89 -> V_90 ) {
F_10 ( V_82 ) ;
return 0 ;
}
V_85 = V_91 + F_34 ( V_82 ) + 1 ;
do {
V_86 = F_35 ( V_91 , V_85 ) ;
if ( V_9 -> V_89 -> V_90 ) {
V_87 = V_9 -> V_89 -> V_90 ( V_9 ) ;
} else {
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( V_84 && V_4 == - V_81 ) {
V_87 = true ;
} else if ( V_4 ) {
return V_4 ;
} else {
V_4 = F_28 ( V_9 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_87 = F_36 ( V_3 ) == V_92 ;
}
}
if ( V_86 && V_87 ) {
F_37 ( L_2 ,
F_30 ( V_9 ) , V_93 ) ;
return - V_37 ;
}
} while ( V_87 );
return 0 ;
}
int F_38 ( struct V_1 * V_2 , T_3 V_94 , T_3 V_95 , T_3 V_96 ,
unsigned int V_82 , unsigned char V_97 ,
bool V_98 , bool V_83 , bool V_84 )
{
struct V_18 * V_9 = V_2 -> V_9 ;
int V_4 ;
struct V_5 V_6 = {} ;
bool V_99 = V_98 ;
unsigned char V_100 = V_9 -> V_101 . V_97 ;
F_39 ( V_9 ) ;
if ( V_82 && V_9 -> V_102 &&
( V_82 > V_9 -> V_102 ) )
V_99 = false ;
V_6 . V_7 = V_103 ;
V_6 . V_10 = ( V_104 << 24 ) |
( V_95 << 16 ) |
( V_96 << 8 ) |
V_94 ;
V_6 . V_12 = V_15 ;
if ( V_99 ) {
V_6 . V_12 |= V_105 | V_106 ;
V_6 . V_107 = V_82 ;
} else {
V_6 . V_12 |= V_25 | V_14 ;
}
if ( V_95 == V_108 )
V_6 . V_109 = true ;
V_4 = F_3 ( V_9 , & V_6 , V_16 ) ;
if ( V_4 )
goto V_110;
if ( ! V_98 )
goto V_110;
if ( ( ( V_9 -> V_111 & V_112 ) && V_99 ) ||
F_2 ( V_9 ) )
goto V_113;
V_4 = F_33 ( V_2 , V_82 , V_83 , V_84 ) ;
if ( V_4 )
goto V_110;
V_113:
if ( V_97 )
F_40 ( V_9 , V_97 ) ;
if ( V_83 ) {
V_4 = F_32 ( V_2 ) ;
if ( V_4 && V_97 )
F_40 ( V_9 , V_100 ) ;
}
V_110:
F_41 ( V_9 ) ;
return V_4 ;
}
int F_42 ( struct V_1 * V_2 , T_3 V_94 , T_3 V_95 , T_3 V_96 ,
unsigned int V_82 )
{
return F_38 ( V_2 , V_94 , V_95 , V_96 , V_82 , 0 ,
true , true , false ) ;
}
int F_43 ( struct V_18 * V_9 , T_1 V_7 , int * V_114 )
{
struct V_45 V_46 = {} ;
struct V_5 V_6 = {} ;
struct V_47 V_48 = {} ;
struct V_49 V_50 ;
struct V_115 * V_101 = & V_9 -> V_101 ;
const T_3 * V_116 ;
int V_117 , V_4 = 0 ;
T_3 * V_118 ;
if ( V_101 -> V_119 == V_120 ) {
V_116 = V_121 ;
V_117 = sizeof( V_121 ) ;
} else if ( V_101 -> V_119 == V_122 ) {
V_116 = V_123 ;
V_117 = sizeof( V_123 ) ;
} else
return - V_66 ;
V_118 = F_20 ( V_117 , V_63 ) ;
if ( ! V_118 )
return - V_64 ;
V_46 . V_6 = & V_6 ;
V_46 . V_48 = & V_48 ;
V_6 . V_7 = V_7 ;
V_6 . V_12 = V_14 | V_51 ;
V_48 . V_52 = V_117 ;
V_48 . V_53 = 1 ;
V_48 . V_12 = V_54 ;
V_48 . V_58 = 150 * V_124 ;
V_48 . V_50 = & V_50 ;
V_48 . V_55 = 1 ;
F_16 ( & V_50 , V_118 , V_117 ) ;
F_18 ( V_9 , & V_46 ) ;
if ( V_114 )
* V_114 = V_6 . error ;
if ( V_6 . error ) {
V_4 = V_6 . error ;
goto V_110;
}
if ( V_48 . error ) {
V_4 = V_48 . error ;
goto V_110;
}
if ( memcmp ( V_118 , V_116 , V_117 ) )
V_4 = - V_125 ;
V_110:
F_22 ( V_118 ) ;
return V_4 ;
}
int F_44 ( struct V_18 * V_9 , T_1 V_7 )
{
struct V_5 V_6 = {} ;
if ( V_7 != V_126 )
return 0 ;
V_6 . V_7 = V_127 ;
V_6 . V_12 = V_25 | V_14 | V_15 ;
V_6 . V_107 = 150 ;
return F_3 ( V_9 , & V_6 , 0 ) ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_18 * V_9 , T_3 V_7 ,
T_3 V_44 )
{
struct V_45 V_46 = {} ;
struct V_5 V_6 = {} ;
struct V_47 V_48 = {} ;
struct V_49 V_50 ;
T_3 * V_118 ;
T_3 * V_128 ;
int V_31 , V_4 ;
static T_3 V_129 [ 8 ] = { 0x55 , 0xaa , 0 , 0 , 0 , 0 , 0 , 0 } ;
static T_3 V_130 [ 4 ] = { 0x5a , 0 , 0 , 0 } ;
V_118 = F_46 ( V_44 , V_63 ) ;
if ( ! V_118 )
return - V_64 ;
if ( V_44 == 8 )
V_128 = V_129 ;
else if ( V_44 == 4 )
V_128 = V_130 ;
else {
F_37 ( L_3 ,
F_30 ( V_9 ) , V_44 ) ;
F_22 ( V_118 ) ;
return - V_66 ;
}
if ( V_7 == V_131 )
memcpy ( V_118 , V_128 , V_44 ) ;
V_46 . V_6 = & V_6 ;
V_46 . V_48 = & V_48 ;
V_6 . V_7 = V_7 ;
V_6 . V_10 = 0 ;
V_6 . V_12 = V_25 | V_14 | V_51 ;
V_48 . V_52 = V_44 ;
V_48 . V_53 = 1 ;
if ( V_7 == V_132 )
V_48 . V_12 = V_54 ;
else
V_48 . V_12 = V_133 ;
V_48 . V_50 = & V_50 ;
V_48 . V_55 = 1 ;
F_17 ( & V_48 , V_2 ) ;
F_16 ( & V_50 , V_118 , V_44 ) ;
F_18 ( V_9 , & V_46 ) ;
V_4 = 0 ;
if ( V_7 == V_132 ) {
for ( V_31 = 0 ; V_31 < V_44 / 4 ; V_31 ++ )
if ( ( V_128 [ V_31 ] ^ V_118 [ V_31 ] ) != 0xff ) {
V_4 = - V_125 ;
break;
}
}
F_22 ( V_118 ) ;
if ( V_6 . error )
return V_6 . error ;
if ( V_48 . error )
return V_48 . error ;
return V_4 ;
}
int F_47 ( struct V_1 * V_2 , T_3 V_119 )
{
int V_134 ;
if ( V_119 == V_120 )
V_134 = 8 ;
else if ( V_119 == V_122 )
V_134 = 4 ;
else if ( V_119 == V_135 )
return 0 ;
else
return - V_66 ;
F_45 ( V_2 , V_2 -> V_9 , V_131 , V_134 ) ;
return F_45 ( V_2 , V_2 -> V_9 , V_132 , V_134 ) ;
}
int F_48 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_5 V_6 = {} ;
unsigned int V_7 ;
int V_4 ;
if ( ! V_2 -> V_68 . V_136 ) {
F_29 ( L_4 ,
F_30 ( V_2 -> V_9 ) ) ;
return - V_66 ;
}
V_7 = V_2 -> V_68 . V_137 ;
if ( V_7 == V_127 )
V_6 . V_12 = V_106 | V_15 ;
else if ( V_7 == V_8 )
V_6 . V_12 = V_14 | V_15 ;
V_6 . V_7 = V_7 ;
V_6 . V_10 = V_2 -> V_11 << 16 | 1 ;
V_4 = F_3 ( V_2 -> V_9 , & V_6 , 0 ) ;
if ( V_4 ) {
F_29 ( L_5
L_6 , F_30 ( V_2 -> V_9 ) ,
V_4 , V_6 . V_17 [ 0 ] ) ;
return V_4 ;
}
if ( V_3 )
* V_3 = V_6 . V_17 [ 0 ] ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
return ( V_2 && V_2 -> V_60 . V_138 > V_139 ) ;
}
static int F_49 ( struct V_1 * V_2 , bool V_140 )
{
T_3 V_141 = V_140 ? V_142 : 0 ;
int V_4 ;
if ( ! V_2 -> V_68 . V_143 )
return - V_69 ;
V_4 = F_42 ( V_2 , V_144 , V_145 ,
V_141 , V_2 -> V_68 . V_146 ) ;
if ( ! V_4 )
V_2 -> V_68 . V_147 = V_140 ;
return V_4 ;
}
int F_50 ( struct V_1 * V_2 )
{
return F_49 ( V_2 , true ) ;
}
int F_51 ( struct V_1 * V_2 )
{
return F_49 ( V_2 , false ) ;
}
