static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = { 0 } ;
int V_7 = 0 , V_8 ;
T_1 * V_9 ;
F_2 ( V_2 , & V_6 , V_10 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_12 |
V_13 ) ;
V_9 = & V_6 . V_14 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
V_6 . V_16 |= F_3 (
V_17 << V_8 ) ;
V_9 [ V_8 ] = V_2 -> V_18 [ V_4 -> V_19 [ V_8 ] ] . V_20 ;
}
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 V_6 = { 0 } ;
int V_7 = 0 ;
F_2 ( V_2 , & V_6 , V_26 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_27 ) ;
F_6 ( & V_2 -> V_28 ) ;
V_7 = F_7 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( ! V_7 ) {
T_1 * V_9 = & V_23 -> V_14 ;
int V_8 , V_29 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
T_1 V_20 = V_9 [ V_8 ] ;
for ( V_29 = 0 ; V_29 < V_2 -> V_30 ; V_29 ++ ) {
if ( V_2 -> V_18 [ V_29 ] . V_20 == V_20 ) {
V_4 -> V_19 [ V_8 ] = V_29 ;
break;
}
}
}
}
F_8 ( & V_2 -> V_28 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_30 )
{
struct V_31 V_6 = { 0 } ;
struct V_32 V_33 ;
int V_7 = 0 , V_8 ;
void * V_34 ;
F_2 ( V_2 , & V_6 , V_35 , - 1 , - 1 ) ;
V_34 = & V_6 . V_36 ;
for ( V_8 = 0 ; V_8 < V_30 ; V_8 ++ , V_34 += sizeof( V_33 ) - 4 ) {
V_6 . V_16 |= F_3 (
V_37 << V_8 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_20 = V_2 -> V_18 [ V_8 ] . V_20 ;
if ( V_4 -> V_38 [ V_8 ] == V_39 ) {
V_33 . V_40 =
V_41 ;
V_33 . V_42 = V_8 ;
} else {
V_33 . V_40 =
V_43 ;
V_33 . V_44 = V_4 -> V_45 [ V_8 ] ;
V_33 . V_46 =
F_3 ( ( V_4 -> V_45 [ V_8 ] * 100 ) |
V_47 ) ;
}
memcpy ( V_34 , & V_33 . V_20 , sizeof( V_33 ) - 4 ) ;
if ( V_8 == 0 ) {
V_6 . V_48 = V_33 . V_20 ;
V_6 . V_36 = 0 ;
}
}
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_49 * V_23 = V_2 -> V_24 ;
struct V_50 V_6 = { 0 } ;
struct V_32 V_33 ;
void * V_34 ;
int V_7 , V_8 ;
F_2 ( V_2 , & V_6 , V_51 , - 1 , - 1 ) ;
F_6 ( & V_2 -> V_28 ) ;
V_7 = F_7 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 ) {
F_8 ( & V_2 -> V_28 ) ;
return V_7 ;
}
V_34 = & V_23 -> V_48 + F_11 ( struct V_32 , V_20 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_30 ; V_8 ++ , V_34 += sizeof( V_33 ) - 4 ) {
int V_29 ;
memcpy ( & V_33 . V_20 , V_34 , sizeof( V_33 ) - 4 ) ;
if ( V_8 == 0 )
V_33 . V_20 = V_23 -> V_48 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_30 ; V_29 ++ ) {
if ( V_2 -> V_18 [ V_29 ] . V_20 != V_33 . V_20 )
continue;
if ( V_33 . V_40 ==
V_41 ) {
V_4 -> V_38 [ V_29 ] = V_39 ;
} else {
V_4 -> V_38 [ V_29 ] = V_52 ;
V_4 -> V_45 [ V_29 ] = V_33 . V_44 ;
}
}
}
F_8 ( & V_2 -> V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_53 )
{
struct V_54 V_6 = { 0 } ;
int V_8 ;
if ( F_13 ( V_2 -> V_55 ) )
F_14 ( V_2 ) ;
F_2 ( V_2 , & V_6 , V_56 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_57 ) ;
V_6 . V_16 = F_3 ( V_58 ) ;
V_6 . V_59 = V_60 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_30 ; V_8 ++ ) {
if ( F_15 ( V_2 -> V_18 [ V_8 ] . V_61 ) ) {
V_6 . V_20 = F_3 ( V_2 -> V_18 [ V_8 ] . V_20 ) ;
F_4 ( V_2 , & V_6 , sizeof( V_6 ) ,
V_21 ) ;
V_2 -> V_18 [ V_8 ] . V_61 =
V_60 ;
}
}
V_6 . V_59 = V_62 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_30 ; V_8 ++ ) {
if ( V_53 & ( 1 << V_8 ) ) {
V_6 . V_20 = F_3 ( V_2 -> V_18 [ V_8 ] . V_20 ) ;
F_4 ( V_2 , & V_6 , sizeof( V_6 ) ,
V_21 ) ;
V_2 -> V_18 [ V_8 ] . V_61 =
V_62 ;
}
}
if ( F_13 ( V_2 -> V_55 ) )
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
struct V_65 V_6 = { 0 } ;
struct V_3 * V_66 = V_2 -> V_3 ;
unsigned int V_67 = 0 , V_68 = 0 ;
T_1 V_8 , V_69 , V_70 = 0 ;
bool V_71 = false ;
int V_7 ;
if ( ! V_66 )
return - V_72 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_30 ; V_8 ++ ) {
for ( V_69 = 0 ; V_69 < V_15 ; V_69 ++ ) {
if ( ( V_64 -> V_73 & ( 1 << V_69 ) ) &&
( V_66 -> V_19 [ V_69 ] == V_8 ) ) {
V_68 |= 1 << V_69 ;
V_67 |= 1 << V_8 ;
}
}
if ( V_67 & ( 1 << V_8 ) )
V_70 ++ ;
}
if ( V_70 > V_2 -> V_74 )
return - V_72 ;
F_2 ( V_2 , & V_6 , V_75 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_68 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_30 ; V_8 ++ ) {
if ( V_67 & ( 1 << V_8 ) ) {
if ( ! F_15 ( V_2 -> V_18 [ V_8 ] . V_61 ) )
V_71 = true ;
}
}
if ( V_71 )
V_7 = F_12 ( V_2 , V_67 ) ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
struct V_76 * V_23 = V_2 -> V_24 ;
struct V_77 V_6 = { 0 } ;
T_1 V_68 ;
int V_7 ;
F_2 ( V_2 , & V_6 , V_78 , - 1 , - 1 ) ;
F_6 ( & V_2 -> V_28 ) ;
V_7 = F_7 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 ) {
F_8 ( & V_2 -> V_28 ) ;
return V_7 ;
}
V_68 = F_19 ( V_23 -> V_11 ) ;
V_64 -> V_73 = V_68 ;
F_8 ( & V_2 -> V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_79 * V_80 ,
bool V_81 )
{
struct V_82 V_83 = { 0 } ;
struct V_84 V_85 = { 0 } ;
struct V_86 * V_87 ;
struct V_88 * V_34 ;
T_2 V_89 ;
T_3 V_90 ;
int V_7 , V_91 , V_8 ;
if ( V_2 -> V_92 < 0x10601 )
return 0 ;
V_91 = V_15 ;
V_90 = sizeof( * V_34 ) + sizeof( * V_87 ) * V_91 ;
V_34 = F_21 ( & V_2 -> V_93 -> V_55 , V_90 , & V_89 ,
V_94 ) ;
if ( ! V_34 )
return - V_95 ;
memset ( V_34 , 0 , V_90 ) ;
F_2 ( V_2 , & V_85 , V_96 , - 1 , - 1 ) ;
V_85 . V_97 = F_22 ( V_89 ) ;
V_85 . V_98 = F_23 ( V_99 ) ;
V_85 . V_100 = F_23 ( V_101 ) ;
V_85 . V_102 = 0 ;
V_7 = F_4 ( V_2 , & V_85 , sizeof( V_85 ) , V_21 ) ;
if ( V_7 )
goto V_103;
V_87 = (struct V_86 * ) ( V_34 + 1 ) ;
if ( V_34 -> V_104 != F_23 ( V_99 ) ) {
V_7 = - V_105 ;
goto V_103;
}
V_91 = V_34 -> V_102 ;
for ( V_8 = 0 ; V_8 < V_91 ; V_8 ++ , V_87 ++ ) {
if ( V_87 -> V_106 == F_24 ( V_80 -> V_107 ) &&
V_87 -> V_108 == V_80 -> V_109 &&
V_87 -> V_110 == V_80 -> V_110 ) {
if ( V_81 )
goto V_103;
else
break;
}
}
if ( V_81 ) {
V_91 ++ ;
V_87 -> V_106 = F_24 ( V_80 -> V_107 ) ;
V_87 -> V_108 = V_80 -> V_109 ;
V_87 -> V_110 = V_80 -> V_110 ;
V_87 -> V_111 = 1 ;
} else {
T_3 V_112 = 0 ;
if ( V_91 == V_8 )
goto V_103;
V_112 = ( V_91 - 1 - V_8 ) * sizeof( * V_87 ) ;
if ( V_112 )
memmove ( V_87 , V_87 + 1 , V_112 ) ;
V_91 -- ;
memset ( V_87 + V_91 , 0 , sizeof( * V_87 ) ) ;
}
V_34 -> V_102 = V_91 ;
V_34 -> V_112 = F_23 ( sizeof( * V_87 ) * V_91 ) ;
V_34 -> V_100 = F_23 ( V_101 ) ;
F_2 ( V_2 , & V_83 , V_113 , - 1 , - 1 ) ;
V_83 . V_114 = F_22 ( V_89 ) ;
V_83 . V_90 = F_23 ( sizeof( * V_34 ) + sizeof( * V_87 ) * V_91 ) ;
V_83 . V_115 = 1 ;
V_7 = F_4 ( V_2 , & V_83 , sizeof( V_83 ) , V_21 ) ;
if ( V_7 )
V_7 = - V_116 ;
V_103:
F_25 ( & V_2 -> V_93 -> V_55 , V_90 , V_34 , V_89 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_117 )
{
int V_118 = 0 ;
T_1 V_30 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
if ( V_4 -> V_19 [ V_8 ] > V_2 -> V_30 ) {
F_27 ( V_2 -> V_55 , L_1 ,
V_4 -> V_19 [ V_8 ] ) ;
return - V_72 ;
}
if ( V_4 -> V_19 [ V_8 ] > V_30 )
V_30 = V_4 -> V_19 [ V_8 ] ;
if ( ( V_4 -> V_45 [ V_8 ] || V_4 -> V_38 [ V_8 ] ) && V_8 > V_2 -> V_30 )
return - V_72 ;
switch ( V_4 -> V_38 [ V_8 ] ) {
case V_39 :
break;
case V_52 :
V_118 += V_4 -> V_45 [ V_8 ] ;
break;
default:
return - V_119 ;
}
}
if ( V_118 > 100 )
return - V_72 ;
* V_117 = V_30 + 1 ;
return 0 ;
}
static int F_28 ( struct V_120 * V_55 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
struct V_3 * V_66 = V_2 -> V_3 ;
V_4 -> V_121 = V_2 -> V_30 ;
if ( ! V_66 ) {
int V_7 ;
if ( V_2 -> V_122 & V_123 )
return 0 ;
V_66 = F_30 ( sizeof( * V_66 ) , V_94 ) ;
if ( ! V_66 )
return 0 ;
V_7 = F_10 ( V_2 , V_66 ) ;
if ( V_7 )
return 0 ;
V_7 = F_5 ( V_2 , V_66 ) ;
if ( V_7 )
return 0 ;
}
V_4 -> V_124 = V_66 -> V_124 ;
memcpy ( V_4 -> V_45 , V_66 -> V_45 , sizeof( V_4 -> V_45 ) ) ;
memcpy ( V_4 -> V_125 , V_66 -> V_125 , sizeof( V_4 -> V_125 ) ) ;
memcpy ( V_4 -> V_38 , V_66 -> V_38 , sizeof( V_4 -> V_38 ) ) ;
memcpy ( V_4 -> V_19 , V_66 -> V_19 , sizeof( V_4 -> V_19 ) ) ;
return 0 ;
}
static int F_31 ( struct V_120 * V_55 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
struct V_3 * V_66 = V_2 -> V_3 ;
T_1 V_30 = 0 ;
int V_7 , V_8 ;
if ( ! ( V_2 -> V_122 & V_126 ) ||
! ( V_2 -> V_122 & V_123 ) )
return - V_72 ;
V_7 = F_26 ( V_2 , V_4 , & V_30 ) ;
if ( ! V_7 ) {
if ( ! V_66 ) {
V_66 = F_30 ( sizeof( * V_66 ) , V_94 ) ;
if ( ! V_66 )
return - V_95 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ )
V_66 -> V_19 [ V_8 ] = V_15 ;
V_2 -> V_3 = V_66 ;
}
V_7 = F_32 ( V_55 , V_30 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_9 ( V_2 , V_4 , V_30 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
memcpy ( V_66 , V_4 , sizeof( * V_66 ) ) ;
}
return V_7 ;
}
static int F_33 ( struct V_120 * V_55 , struct V_63 * V_64 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
T_4 * V_127 = ( T_4 * ) V_2 -> V_128 ;
struct V_63 * V_129 = V_2 -> V_63 ;
long V_130 , V_131 ;
int V_8 , V_7 ;
V_64 -> V_132 = V_2 -> V_74 ;
if ( ! V_129 ) {
if ( V_2 -> V_122 & V_123 )
return 0 ;
V_129 = F_30 ( sizeof( * V_129 ) , V_94 ) ;
if ( ! V_129 )
return 0 ;
V_2 -> V_63 = V_129 ;
V_7 = F_18 ( V_2 , V_129 ) ;
if ( V_7 )
return 0 ;
}
V_64 -> V_73 = V_129 -> V_73 ;
V_64 -> V_133 = V_129 -> V_133 ;
V_64 -> V_134 = V_129 -> V_134 ;
if ( ! V_127 )
return 0 ;
V_130 = F_34 ( V_135 ) ;
V_131 = F_35 ( V_136 ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ , V_130 ++ , V_131 ++ ) {
V_64 -> V_137 [ V_8 ] = F_36 ( * ( V_127 + V_131 ) ) ;
V_64 -> V_138 [ V_8 ] = F_36 ( * ( V_127 + V_130 ) ) ;
}
return 0 ;
}
static int F_37 ( struct V_120 * V_55 , struct V_63 * V_64 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
struct V_63 * V_129 = V_2 -> V_63 ;
int V_7 ;
if ( ! ( V_2 -> V_122 & V_126 ) ||
! ( V_2 -> V_122 & V_123 ) )
return - V_72 ;
if ( ! V_129 ) {
V_129 = F_30 ( sizeof( * V_129 ) , V_94 ) ;
if ( ! V_129 )
return - V_95 ;
V_2 -> V_63 = V_129 ;
}
V_7 = F_17 ( V_2 , V_64 ) ;
if ( ! V_7 )
memcpy ( V_129 , V_64 , sizeof( * V_129 ) ) ;
return V_7 ;
}
static int F_38 ( struct V_120 * V_55 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
int V_7 = - V_72 ;
if ( ! ( V_2 -> V_122 & V_126 ) ||
! ( V_2 -> V_122 & V_123 ) )
return - V_72 ;
V_7 = F_39 ( V_55 , V_80 ) ;
if ( V_7 )
return V_7 ;
if ( ( V_80 -> V_109 == V_139 &&
V_80 -> V_107 == V_140 ) ||
( V_80 -> V_109 == V_141 &&
V_80 -> V_107 == V_142 ) )
V_7 = F_20 ( V_2 , V_80 , true ) ;
return V_7 ;
}
static int F_40 ( struct V_120 * V_55 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
int V_7 ;
if ( ! ( V_2 -> V_122 & V_126 ) ||
! ( V_2 -> V_122 & V_123 ) )
return - V_72 ;
V_7 = F_41 ( V_55 , V_80 ) ;
if ( V_7 )
return V_7 ;
if ( ( V_80 -> V_109 == V_139 &&
V_80 -> V_107 == V_140 ) ||
( V_80 -> V_109 == V_141 &&
V_80 -> V_107 == V_142 ) )
V_7 = F_20 ( V_2 , V_80 , false ) ;
return V_7 ;
}
static T_1 F_42 ( struct V_120 * V_55 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
return V_2 -> V_122 ;
}
static T_1 F_43 ( struct V_120 * V_55 , T_1 V_143 )
{
struct V_1 * V_2 = F_29 ( V_55 ) ;
if ( V_2 -> V_122 & V_144 )
return 1 ;
if ( V_143 & V_123 ) {
if ( F_44 ( V_2 ) || ( V_2 -> V_11 & V_145 ) )
return 1 ;
if ( ( V_143 & V_146 ) ||
! ( V_143 & V_126 ) )
return 1 ;
}
if ( V_143 == V_2 -> V_122 )
return 0 ;
V_2 -> V_122 = V_143 ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_92 < 0x10501 )
return;
V_2 -> V_122 = V_126 ;
if ( F_46 ( V_2 ) && ! ( V_2 -> V_11 & V_145 ) )
V_2 -> V_122 |= V_123 ;
else if ( V_2 -> V_11 & V_147 )
V_2 -> V_122 |= V_144 ;
V_2 -> V_55 -> V_148 = & V_148 ;
}
void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_63 ) ;
F_48 ( V_2 -> V_3 ) ;
V_2 -> V_63 = NULL ;
V_2 -> V_3 = NULL ;
}
void F_45 ( struct V_1 * V_2 )
{
}
void F_47 ( struct V_1 * V_2 )
{
}
