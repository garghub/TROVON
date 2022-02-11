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
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( ! V_7 ) {
T_1 * V_9 = & V_23 -> V_14 ;
int V_8 , V_28 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
T_1 V_20 = V_9 [ V_8 ] ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ ) {
if ( V_2 -> V_18 [ V_28 ] . V_20 == V_20 ) {
V_4 -> V_19 [ V_8 ] = V_28 ;
break;
}
}
}
}
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_29 )
{
struct V_30 V_6 = { 0 } ;
struct V_31 V_32 ;
int V_7 = 0 , V_8 ;
void * V_33 ;
F_2 ( V_2 , & V_6 , V_34 , - 1 , - 1 ) ;
V_33 = & V_6 . V_35 ;
for ( V_8 = 0 ; V_8 < V_29 ; V_8 ++ , V_33 += sizeof( V_32 ) - 4 ) {
V_6 . V_16 |= F_3 (
V_36 << V_8 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_20 = V_2 -> V_18 [ V_8 ] . V_20 ;
if ( V_4 -> V_37 [ V_8 ] == V_38 ) {
V_32 . V_39 =
V_40 ;
V_32 . V_41 = V_8 ;
} else {
V_32 . V_39 =
V_42 ;
V_32 . V_43 = V_4 -> V_44 [ V_8 ] ;
}
memcpy ( V_33 , & V_32 . V_20 , sizeof( V_32 ) - 4 ) ;
if ( V_8 == 0 ) {
V_6 . V_45 = V_32 . V_20 ;
V_6 . V_35 = 0 ;
}
}
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_46 * V_23 = V_2 -> V_24 ;
struct V_47 V_6 = { 0 } ;
struct V_31 V_32 ;
void * V_33 ;
int V_7 , V_8 ;
F_2 ( V_2 , & V_6 , V_48 , - 1 , - 1 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
V_33 = & V_23 -> V_45 + F_8 ( struct V_31 , V_20 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ , V_33 += sizeof( V_32 ) - 4 ) {
int V_28 ;
memcpy ( & V_32 . V_20 , V_33 , sizeof( V_32 ) - 4 ) ;
if ( V_8 == 0 )
V_32 . V_20 = V_23 -> V_45 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ ) {
if ( V_2 -> V_18 [ V_28 ] . V_20 != V_32 . V_20 )
continue;
if ( V_32 . V_39 ==
V_40 ) {
V_4 -> V_37 [ V_28 ] = V_38 ;
} else {
V_4 -> V_37 [ V_28 ] = V_49 ;
V_4 -> V_44 [ V_28 ] = V_32 . V_43 ;
}
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_50 )
{
struct V_51 V_6 = { 0 } ;
int V_8 ;
if ( F_10 ( V_2 -> V_52 ) )
F_11 ( V_2 ) ;
F_2 ( V_2 , & V_6 , V_53 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_54 ) ;
V_6 . V_16 = F_3 ( V_55 ) ;
V_6 . V_56 = V_57 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
if ( F_12 ( V_2 -> V_18 [ V_8 ] . V_58 ) ) {
V_6 . V_20 = F_3 ( V_2 -> V_18 [ V_8 ] . V_20 ) ;
F_4 ( V_2 , & V_6 , sizeof( V_6 ) ,
V_21 ) ;
V_2 -> V_18 [ V_8 ] . V_58 =
V_57 ;
}
}
V_6 . V_56 = V_59 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
if ( V_50 & ( 1 << V_8 ) ) {
V_6 . V_20 = F_3 ( V_2 -> V_18 [ V_8 ] . V_20 ) ;
F_4 ( V_2 , & V_6 , sizeof( V_6 ) ,
V_21 ) ;
V_2 -> V_18 [ V_8 ] . V_58 =
V_59 ;
}
}
if ( F_10 ( V_2 -> V_52 ) )
F_13 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_62 V_6 = { 0 } ;
struct V_3 * V_63 = V_2 -> V_3 ;
unsigned int V_64 = 0 , V_65 = 0 ;
T_1 V_8 , V_66 , V_67 = 0 ;
bool V_68 = false ;
int V_7 ;
if ( ! V_63 )
return - V_69 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
for ( V_66 = 0 ; V_66 < V_15 ; V_66 ++ ) {
if ( ( V_61 -> V_70 & ( 1 << V_66 ) ) &&
( V_63 -> V_19 [ V_66 ] == V_8 ) ) {
V_65 |= 1 << V_66 ;
V_64 |= 1 << V_8 ;
}
}
if ( V_64 & ( 1 << V_8 ) )
V_67 ++ ;
}
if ( V_67 > V_2 -> V_71 )
return - V_69 ;
F_2 ( V_2 , & V_6 , V_72 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_65 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
if ( V_64 & ( 1 << V_8 ) ) {
if ( ! F_12 ( V_2 -> V_18 [ V_8 ] . V_58 ) )
V_68 = true ;
}
}
if ( V_68 )
V_7 = F_9 ( V_2 , V_64 ) ;
return V_7 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_73 * V_23 = V_2 -> V_24 ;
struct V_74 V_6 = { 0 } ;
T_1 V_65 ;
int V_7 ;
F_2 ( V_2 , & V_6 , V_75 , - 1 , - 1 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
V_65 = F_16 ( V_23 -> V_11 ) ;
V_61 -> V_70 = V_65 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_76 * V_77 ,
bool V_78 )
{
struct V_79 V_80 = { 0 } ;
struct V_81 V_82 = { 0 } ;
struct V_83 * V_84 ;
struct V_85 * V_33 ;
T_2 V_86 ;
T_3 V_87 ;
int V_7 , V_88 , V_8 ;
if ( V_2 -> V_89 < 0x10601 )
return 0 ;
V_88 = V_15 ;
V_87 = sizeof( * V_33 ) + sizeof( * V_84 ) * V_88 ;
V_33 = F_18 ( & V_2 -> V_90 -> V_52 , V_87 , & V_86 ,
V_91 ) ;
if ( ! V_33 )
return - V_92 ;
memset ( V_33 , 0 , V_87 ) ;
F_2 ( V_2 , & V_82 , V_93 , - 1 , - 1 ) ;
V_82 . V_94 = F_19 ( V_86 ) ;
V_82 . V_95 = F_20 ( V_96 ) ;
V_82 . V_97 = F_20 ( V_98 ) ;
V_82 . V_99 = 0 ;
V_7 = F_4 ( V_2 , & V_82 , sizeof( V_82 ) , V_21 ) ;
if ( V_7 )
goto V_100;
V_84 = (struct V_83 * ) ( V_33 + 1 ) ;
if ( V_33 -> V_101 != F_20 ( V_96 ) ) {
V_7 = - V_102 ;
goto V_100;
}
V_88 = V_33 -> V_99 ;
for ( V_8 = 0 ; V_8 < V_88 ; V_8 ++ , V_84 ++ ) {
if ( V_84 -> V_103 == F_21 ( V_77 -> V_104 ) &&
V_84 -> V_105 == V_77 -> V_106 &&
V_84 -> V_107 == V_77 -> V_107 ) {
if ( V_78 )
goto V_100;
else
break;
}
}
if ( V_78 ) {
V_88 ++ ;
V_84 -> V_103 = F_21 ( V_77 -> V_104 ) ;
V_84 -> V_105 = V_77 -> V_106 ;
V_84 -> V_107 = V_77 -> V_107 ;
V_84 -> V_108 = 1 ;
} else {
T_3 V_109 = 0 ;
if ( V_88 == V_8 )
goto V_100;
V_109 = ( V_88 - 1 - V_8 ) * sizeof( * V_84 ) ;
if ( V_109 )
memmove ( V_84 , V_84 + 1 , V_109 ) ;
V_88 -- ;
memset ( V_84 + V_88 , 0 , sizeof( * V_84 ) ) ;
}
V_33 -> V_99 = V_88 ;
V_33 -> V_109 = F_20 ( sizeof( * V_84 ) * V_88 ) ;
V_33 -> V_97 = F_20 ( V_98 ) ;
F_2 ( V_2 , & V_80 , V_110 , - 1 , - 1 ) ;
V_80 . V_111 = F_19 ( V_86 ) ;
V_80 . V_87 = F_20 ( sizeof( * V_33 ) + sizeof( * V_84 ) * V_88 ) ;
V_80 . V_112 = 1 ;
V_7 = F_4 ( V_2 , & V_80 , sizeof( V_80 ) , V_21 ) ;
if ( V_7 )
V_7 = - V_113 ;
V_100:
F_22 ( & V_2 -> V_90 -> V_52 , V_87 , V_33 , V_86 ) ;
return V_7 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_114 )
{
int V_115 = 0 ;
T_1 V_29 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
if ( V_4 -> V_19 [ V_8 ] > V_2 -> V_29 ) {
F_24 ( V_2 -> V_52 , L_1 ,
V_4 -> V_19 [ V_8 ] ) ;
return - V_69 ;
}
if ( V_4 -> V_19 [ V_8 ] > V_29 )
V_29 = V_4 -> V_19 [ V_8 ] ;
if ( ( V_4 -> V_44 [ V_8 ] || V_4 -> V_37 [ V_8 ] ) && V_8 > V_2 -> V_29 )
return - V_69 ;
switch ( V_4 -> V_37 [ V_8 ] ) {
case V_38 :
break;
case V_49 :
V_115 += V_4 -> V_44 [ V_8 ] ;
break;
default:
return - V_116 ;
}
}
if ( V_115 > 100 )
return - V_69 ;
* V_114 = V_29 + 1 ;
return 0 ;
}
static int F_25 ( struct V_117 * V_52 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_3 * V_63 = V_2 -> V_3 ;
V_4 -> V_118 = V_2 -> V_29 ;
if ( ! V_63 ) {
int V_7 ;
if ( V_2 -> V_119 & V_120 )
return 0 ;
V_63 = F_27 ( sizeof( * V_63 ) , V_91 ) ;
if ( ! V_63 )
return 0 ;
V_7 = F_7 ( V_2 , V_63 ) ;
if ( V_7 )
return 0 ;
V_7 = F_5 ( V_2 , V_63 ) ;
if ( V_7 )
return 0 ;
}
V_4 -> V_121 = V_63 -> V_121 ;
memcpy ( V_4 -> V_44 , V_63 -> V_44 , sizeof( V_4 -> V_44 ) ) ;
memcpy ( V_4 -> V_122 , V_63 -> V_122 , sizeof( V_4 -> V_122 ) ) ;
memcpy ( V_4 -> V_37 , V_63 -> V_37 , sizeof( V_4 -> V_37 ) ) ;
memcpy ( V_4 -> V_19 , V_63 -> V_19 , sizeof( V_4 -> V_19 ) ) ;
return 0 ;
}
static int F_28 ( struct V_117 * V_52 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_3 * V_63 = V_2 -> V_3 ;
T_1 V_29 = 0 ;
int V_7 , V_8 ;
if ( ! ( V_2 -> V_119 & V_123 ) ||
! ( V_2 -> V_119 & V_120 ) )
return - V_69 ;
V_7 = F_23 ( V_2 , V_4 , & V_29 ) ;
if ( ! V_7 ) {
if ( ! V_63 ) {
V_63 = F_27 ( sizeof( * V_63 ) , V_91 ) ;
if ( ! V_63 )
return - V_92 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ )
V_63 -> V_19 [ V_8 ] = V_15 ;
V_2 -> V_3 = V_63 ;
}
V_7 = F_29 ( V_52 , V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_2 , V_4 , V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
memcpy ( V_63 , V_4 , sizeof( * V_63 ) ) ;
}
return V_7 ;
}
static int F_30 ( struct V_117 * V_52 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
T_4 * V_124 = ( T_4 * ) V_2 -> V_125 ;
struct V_60 * V_126 = V_2 -> V_60 ;
long V_127 , V_128 ;
int V_8 , V_7 ;
V_61 -> V_129 = V_2 -> V_71 ;
if ( ! V_126 ) {
if ( V_2 -> V_119 & V_120 )
return 0 ;
V_126 = F_27 ( sizeof( * V_126 ) , V_91 ) ;
if ( ! V_126 )
return 0 ;
V_2 -> V_60 = V_126 ;
V_7 = F_15 ( V_2 , V_126 ) ;
if ( V_7 )
return 0 ;
}
V_61 -> V_70 = V_126 -> V_70 ;
V_61 -> V_130 = V_126 -> V_130 ;
V_61 -> V_131 = V_126 -> V_131 ;
if ( ! V_124 )
return 0 ;
V_127 = F_31 ( V_132 ) ;
V_128 = F_32 ( V_133 ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ , V_127 ++ , V_128 ++ ) {
V_61 -> V_134 [ V_8 ] = F_33 ( * ( V_124 + V_128 ) ) ;
V_61 -> V_135 [ V_8 ] = F_33 ( * ( V_124 + V_127 ) ) ;
}
return 0 ;
}
static int F_34 ( struct V_117 * V_52 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
struct V_60 * V_126 = V_2 -> V_60 ;
int V_7 ;
if ( ! ( V_2 -> V_119 & V_123 ) ||
! ( V_2 -> V_119 & V_120 ) )
return - V_69 ;
if ( ! V_126 ) {
V_126 = F_27 ( sizeof( * V_126 ) , V_91 ) ;
if ( ! V_126 )
return - V_92 ;
V_2 -> V_60 = V_126 ;
}
V_7 = F_14 ( V_2 , V_61 ) ;
if ( ! V_7 )
memcpy ( V_126 , V_61 , sizeof( * V_126 ) ) ;
return V_7 ;
}
static int F_35 ( struct V_117 * V_52 , struct V_76 * V_77 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
int V_7 = - V_69 ;
if ( ! ( V_2 -> V_119 & V_123 ) ||
! ( V_2 -> V_119 & V_120 ) )
return - V_69 ;
V_7 = F_36 ( V_52 , V_77 ) ;
if ( V_7 )
return V_7 ;
if ( ( V_77 -> V_106 == V_136 &&
V_77 -> V_104 == V_137 ) ||
( V_77 -> V_106 == V_138 &&
V_77 -> V_104 == V_139 ) )
V_7 = F_17 ( V_2 , V_77 , true ) ;
return V_7 ;
}
static int F_37 ( struct V_117 * V_52 , struct V_76 * V_77 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
int V_7 ;
if ( ! ( V_2 -> V_119 & V_123 ) ||
! ( V_2 -> V_119 & V_120 ) )
return - V_69 ;
V_7 = F_38 ( V_52 , V_77 ) ;
if ( V_7 )
return V_7 ;
if ( ( V_77 -> V_106 == V_136 &&
V_77 -> V_104 == V_137 ) ||
( V_77 -> V_106 == V_138 &&
V_77 -> V_104 == V_139 ) )
V_7 = F_17 ( V_2 , V_77 , false ) ;
return V_7 ;
}
static T_1 F_39 ( struct V_117 * V_52 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
return V_2 -> V_119 ;
}
static T_1 F_40 ( struct V_117 * V_52 , T_1 V_140 )
{
struct V_1 * V_2 = F_26 ( V_52 ) ;
if ( ( V_140 & V_141 ) || ! ( V_140 & V_123 ) )
return 1 ;
if ( V_140 & V_120 ) {
if ( F_41 ( V_2 ) || ( V_2 -> V_11 & V_142 ) )
return 1 ;
}
if ( V_140 == V_2 -> V_119 )
return 0 ;
V_2 -> V_119 = V_140 ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 < 0x10501 )
return;
V_2 -> V_119 = V_123 ;
if ( F_43 ( V_2 ) && ! ( V_2 -> V_11 & V_142 ) )
V_2 -> V_119 |= V_120 ;
else
V_2 -> V_119 |= V_143 ;
V_2 -> V_52 -> V_144 = & V_144 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 -> V_60 ) ;
F_45 ( V_2 -> V_3 ) ;
V_2 -> V_60 = NULL ;
V_2 -> V_3 = NULL ;
}
void F_42 ( struct V_1 * V_2 )
{
}
void F_44 ( struct V_1 * V_2 )
{
}
