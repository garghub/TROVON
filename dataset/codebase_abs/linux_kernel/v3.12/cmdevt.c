static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_6 )
{
V_4 -> V_2 = V_2 ;
V_4 -> V_5 = V_5 ;
if ( V_2 -> V_7 -> V_8 ) {
V_4 -> V_9 = V_2 -> V_7 -> V_8 ;
V_2 -> V_7 -> V_8 = false ;
V_4 -> V_10 = false ;
V_4 -> V_11 = & V_4 -> V_10 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_12 = V_4 -> V_13 ;
}
static struct V_3 *
F_2 ( struct V_14 * V_7 )
{
struct V_3 * V_4 ;
unsigned long V_15 ;
F_3 ( & V_7 -> V_16 , V_15 ) ;
if ( F_4 ( & V_7 -> V_17 ) ) {
F_5 ( V_7 -> V_18 , L_1 ) ;
F_6 ( & V_7 -> V_16 , V_15 ) ;
return NULL ;
}
V_4 = F_7 ( & V_7 -> V_17 ,
struct V_3 , V_19 ) ;
F_8 ( & V_4 -> V_19 ) ;
F_6 ( & V_7 -> V_16 , V_15 ) ;
return V_4 ;
}
static void
F_9 ( struct V_14 * V_7 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_20 = 0 ;
V_4 -> V_6 = NULL ;
V_4 -> V_9 = false ;
if ( V_4 -> V_12 )
F_10 ( V_4 -> V_12 , 0 ) ;
if ( V_4 -> V_21 ) {
V_7 -> V_22 . V_23 ( V_7 , V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
}
}
static int F_11 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
memcpy ( V_25 , V_27 -> V_25 , V_27 -> V_28 ) ;
F_12 ( V_2 -> V_7 -> V_18 , L_2 , V_27 -> V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_14 * V_7 = V_2 -> V_7 ;
int V_29 ;
struct V_24 * V_30 ;
T_2 V_31 ;
T_2 V_32 ;
struct V_33 V_34 ;
unsigned long V_15 ;
T_3 V_35 ;
if ( ! V_7 || ! V_4 )
return - 1 ;
V_30 = (struct V_24 * ) ( V_4 -> V_12 -> V_36 ) ;
if ( V_30 == NULL || V_30 -> V_37 == 0 ) {
F_5 ( V_7 -> V_18 , L_3
L_4 ) ;
if ( V_4 -> V_9 )
V_7 -> V_38 . V_39 = - 1 ;
F_14 ( V_7 , V_4 ) ;
return - 1 ;
}
V_31 = F_15 ( V_30 -> V_40 ) ;
V_32 = F_15 ( V_30 -> V_37 ) ;
if ( V_7 -> V_41 == V_42 &&
V_31 != V_43 &&
V_31 != V_44 ) {
F_5 ( V_7 -> V_18 ,
L_5 ,
V_31 ) ;
F_16 ( V_7 , V_4 ) ;
F_14 ( V_7 , V_4 ) ;
return - 1 ;
}
V_7 -> V_45 ++ ;
V_30 -> V_45 = F_17 ( F_18
( V_7 -> V_45 ,
V_4 -> V_2 -> V_46 ,
V_4 -> V_2 -> V_47 ) ) ;
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_49 = V_4 ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
if ( V_4 -> V_12 -> V_28 > V_32 )
F_10 ( V_4 -> V_12 , V_32 ) ;
else if ( V_4 -> V_12 -> V_28 < V_32 )
F_19 ( V_4 -> V_12 , V_32 - V_4 -> V_12 -> V_28 ) ;
F_20 ( & V_34 ) ;
F_12 ( V_7 -> V_18 , L_6
L_7 ,
V_34 . V_50 , V_34 . V_51 , V_31 ,
F_15 ( * ( V_52 * ) ( ( V_53 * ) V_30 + V_54 ) ) , V_32 ,
F_15 ( V_30 -> V_45 ) ) ;
if ( V_7 -> V_55 == V_56 ) {
V_35 = F_21 ( V_57 ) ;
F_22 ( V_4 -> V_12 , V_58 ) ;
memcpy ( V_4 -> V_12 -> V_36 , & V_35 , V_58 ) ;
V_7 -> V_59 = true ;
V_29 = V_7 -> V_22 . V_60 ( V_7 ,
V_61 ,
V_4 -> V_12 , NULL ) ;
F_23 ( V_4 -> V_12 , V_58 ) ;
if ( V_29 == - V_62 )
V_4 -> V_12 = NULL ;
} else {
F_22 ( V_4 -> V_12 , V_63 ) ;
V_29 = V_7 -> V_22 . V_60 ( V_7 , V_64 ,
V_4 -> V_12 , NULL ) ;
F_23 ( V_4 -> V_12 , V_63 ) ;
}
if ( V_29 == - 1 ) {
F_5 ( V_7 -> V_18 , L_8 ) ;
if ( V_7 -> V_55 == V_56 )
V_7 -> V_59 = false ;
if ( V_4 -> V_9 )
V_7 -> V_38 . V_39 = - 1 ;
F_14 ( V_7 , V_7 -> V_49 ) ;
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_49 = NULL ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_65 . V_66 ++ ;
return - 1 ;
}
V_7 -> V_65 . V_67 =
( V_7 -> V_65 . V_67 + 1 ) % V_68 ;
V_7 -> V_65 . V_69 [ V_7 -> V_65 . V_67 ] = V_31 ;
V_7 -> V_65 . V_70 [ V_7 -> V_65 . V_67 ] =
F_15 ( * ( V_52 * ) ( ( V_53 * ) V_30 + V_54 ) ) ;
V_31 &= V_71 ;
F_24 ( & V_7 -> V_72 ,
V_73 + F_25 ( V_74 ) ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_7 )
{
int V_29 ;
struct V_1 * V_2 ;
struct V_75 * V_76 =
(struct V_75 * )
V_7 -> V_77 -> V_36 ;
struct V_78 * V_79 ;
T_3 V_35 ;
V_2 = F_27 ( V_7 , V_80 ) ;
V_76 -> V_45 =
F_17 ( ( F_18
( V_7 -> V_45 , V_2 -> V_46 ,
V_2 -> V_47 ) ) ) ;
V_7 -> V_45 ++ ;
if ( V_7 -> V_55 == V_56 ) {
V_79 =
F_28 ( sizeof( struct V_75 )
+ V_58 ) ;
F_19 ( V_79 , sizeof( struct V_75 )
+ V_58 ) ;
V_35 = F_21 ( V_57 ) ;
memcpy ( V_79 -> V_36 , & V_35 , V_58 ) ;
memcpy ( V_79 -> V_36 + V_58 ,
V_7 -> V_77 -> V_36 ,
sizeof( struct V_75 ) ) ;
V_29 = V_7 -> V_22 . V_60 ( V_7 ,
V_61 ,
V_79 , NULL ) ;
if ( V_29 != - V_62 )
F_29 ( V_79 ) ;
} else {
F_22 ( V_7 -> V_77 , V_63 ) ;
V_29 = V_7 -> V_22 . V_60 ( V_7 , V_64 ,
V_7 -> V_77 , NULL ) ;
F_23 ( V_7 -> V_77 , V_63 ) ;
}
if ( V_29 == - 1 ) {
F_5 ( V_7 -> V_18 , L_9 ) ;
V_7 -> V_65 . V_81 ++ ;
return - 1 ;
}
if ( F_30 ( F_27 ( V_7 , V_80 ) )
== V_82 ) {
if ( ! V_76 -> V_83 )
V_7 -> V_84 = V_85 ;
else
V_7 -> V_84 = V_86 ;
if ( ! V_76 -> V_83 &&
( V_7 -> V_87 &&
! V_7 -> V_88 . V_89 ) ) {
V_7 -> V_90 = true ;
F_31 ( F_27
( V_7 , V_82 ) , true ) ;
}
}
return V_29 ;
}
int F_32 ( struct V_14 * V_7 )
{
struct V_3 * V_91 ;
T_1 V_92 ;
V_91 = F_33 ( V_93 ,
sizeof( struct V_3 ) , V_94 ) ;
if ( ! V_91 )
return - V_95 ;
V_7 -> V_96 = V_91 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_91 [ V_92 ] . V_13 = F_28 ( V_97 ) ;
if ( ! V_91 [ V_92 ] . V_13 ) {
F_5 ( V_7 -> V_18 , L_10 ) ;
return - 1 ;
}
}
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ )
F_34 ( V_7 , & V_91 [ V_92 ] ) ;
return 0 ;
}
int F_35 ( struct V_14 * V_7 )
{
struct V_3 * V_91 ;
T_1 V_92 ;
if ( ! V_7 -> V_96 ) {
F_12 ( V_7 -> V_18 , L_11 ) ;
return 0 ;
}
V_91 = V_7 -> V_96 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
if ( V_91 [ V_92 ] . V_13 ) {
F_12 ( V_7 -> V_18 , L_12 , V_92 ) ;
F_29 ( V_91 [ V_92 ] . V_13 ) ;
}
if ( ! V_91 [ V_92 ] . V_21 )
continue;
if ( V_7 -> V_55 == V_56 )
V_7 -> V_22 . V_23 ( V_7 ,
V_91 [ V_92 ] . V_21 ) ;
else
F_29 ( V_91 [ V_92 ] . V_21 ) ;
}
if ( V_7 -> V_96 ) {
F_12 ( V_7 -> V_18 , L_13 ) ;
F_36 ( V_7 -> V_96 ) ;
V_7 -> V_96 = NULL ;
}
return 0 ;
}
int F_37 ( struct V_14 * V_7 )
{
int V_29 ;
struct V_1 * V_2 =
F_27 ( V_7 , V_80 ) ;
struct V_78 * V_13 = V_7 -> V_98 ;
T_1 V_99 = V_7 -> V_100 ;
struct V_33 V_34 ;
struct V_101 * V_102 ;
V_7 -> V_65 . V_103 =
( V_7 -> V_65 . V_103 + 1 ) % V_68 ;
V_7 -> V_65 . V_104 [ V_7 -> V_65 . V_103 ] =
( V_105 ) V_99 ;
V_2 = F_38 ( V_7 , F_39 ( V_99 ) ,
F_40 ( V_99 ) ) ;
if ( ! V_2 )
V_2 = F_27 ( V_7 , V_80 ) ;
V_99 &= V_106 ;
V_7 -> V_100 = V_99 ;
if ( V_13 ) {
V_102 = F_41 ( V_13 ) ;
V_102 -> V_46 = V_2 -> V_46 ;
V_102 -> V_47 = V_2 -> V_47 ;
}
if ( V_99 != V_107 && V_99 != V_108 ) {
F_20 ( & V_34 ) ;
F_12 ( V_7 -> V_18 , L_14 ,
V_34 . V_50 , V_34 . V_51 , V_99 ) ;
} else {
V_2 = F_27 ( V_7 , V_82 ) ;
if ( ! V_2 )
V_2 = F_27 ( V_7 , V_80 ) ;
}
if ( V_2 -> V_109 == V_110 )
V_29 = F_42 ( V_2 ) ;
else
V_29 = F_43 ( V_2 ) ;
V_7 -> V_100 = 0 ;
V_7 -> V_98 = NULL ;
V_7 -> V_22 . V_111 ( V_7 , V_13 ) ;
return V_29 ;
}
int F_44 ( struct V_1 * V_2 , T_2 V_112 ,
V_105 V_113 , T_1 V_5 , void * V_6 )
{
int V_29 = 0 ;
struct V_14 * V_7 = V_2 -> V_7 ;
V_7 -> V_8 = true ;
V_29 = F_45 ( V_2 , V_112 , V_113 , V_5 ,
V_6 ) ;
return V_29 ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_112 ,
V_105 V_113 , T_1 V_5 , void * V_6 )
{
int V_29 ;
struct V_14 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 ;
struct V_24 * V_114 ;
if ( ! V_7 ) {
F_46 ( L_15 ) ;
return - 1 ;
}
if ( V_7 -> V_115 ) {
F_5 ( V_7 -> V_18 , L_16 ) ;
return - 1 ;
}
if ( V_7 -> V_116 ) {
F_5 ( V_7 -> V_18 , L_17 ) ;
return - 1 ;
}
if ( V_7 -> V_41 == V_42 ) {
if ( V_112 != V_44 ) {
F_5 ( V_7 -> V_18 , L_18 ) ;
return - 1 ;
}
}
V_4 = F_2 ( V_7 ) ;
if ( ! V_4 ) {
F_5 ( V_7 -> V_18 , L_19 ) ;
return - 1 ;
}
F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( ! V_4 -> V_12 ) {
F_5 ( V_7 -> V_18 , L_20 ) ;
return - 1 ;
}
memset ( F_19 ( V_4 -> V_12 , sizeof( struct V_24 ) ) ,
0 , sizeof( struct V_24 ) ) ;
V_114 = (struct V_24 * ) ( V_4 -> V_12 -> V_36 ) ;
V_114 -> V_40 = F_17 ( V_112 ) ;
V_114 -> V_117 = 0 ;
if ( V_112 ) {
switch ( V_112 ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_29 = F_47 ( V_2 , V_112 , V_113 ,
V_5 , V_6 ,
V_114 ) ;
break;
default:
V_29 = F_48 ( V_2 , V_112 , V_113 ,
V_5 , V_6 ,
V_114 ) ;
break;
}
} else {
V_29 = F_11 ( V_2 , V_114 , V_6 ) ;
V_4 -> V_20 |= V_122 ;
}
if ( V_29 ) {
F_5 ( V_7 -> V_18 , L_21 ,
V_112 ) ;
F_34 ( V_7 , V_4 ) ;
return - 1 ;
}
if ( V_112 == V_123 ) {
F_49 ( V_2 , V_4 ) ;
} else {
F_50 ( V_7 , V_4 , true ) ;
F_51 ( V_7 -> V_124 , & V_7 -> V_125 ) ;
if ( V_4 -> V_9 )
V_29 = F_52 ( V_7 , V_4 ) ;
}
return V_29 ;
}
void
F_34 ( struct V_14 * V_7 ,
struct V_3 * V_4 )
{
unsigned long V_15 ;
if ( ! V_4 )
return;
if ( V_4 -> V_9 )
F_16 ( V_7 , V_4 ) ;
F_9 ( V_7 , V_4 ) ;
F_3 ( & V_7 -> V_16 , V_15 ) ;
F_53 ( & V_4 -> V_19 , & V_7 -> V_17 ) ;
F_6 ( & V_7 -> V_16 , V_15 ) ;
}
void F_14 ( struct V_14 * V_7 ,
struct V_3 * V_4 )
{
struct V_24 * V_30 = ( void * ) V_4 -> V_12 -> V_36 ;
F_34 ( V_7 , V_4 ) ;
F_54 ( & V_7 -> V_126 ) ;
F_12 ( V_7 -> V_18 , L_22 ,
F_15 ( V_30 -> V_40 ) ,
F_55 ( & V_7 -> V_126 ) ) ;
}
void
F_50 ( struct V_14 * V_7 ,
struct V_3 * V_4 , T_1 V_127 )
{
struct V_24 * V_30 = NULL ;
V_105 V_40 ;
unsigned long V_15 ;
V_30 = (struct V_24 * ) ( V_4 -> V_12 -> V_36 ) ;
if ( ! V_30 ) {
F_5 ( V_7 -> V_18 , L_23 ) ;
return;
}
V_40 = F_15 ( V_30 -> V_40 ) ;
if ( V_40 == V_128 ) {
struct V_129 * V_130 =
& V_30 -> V_131 . V_132 ;
if ( ( F_15 ( V_130 -> V_133 ) == V_134 ) ||
( F_15 ( V_130 -> V_133 ) == V_135 ) ) {
if ( V_7 -> V_84 != V_136 )
V_127 = false ;
}
}
F_3 ( & V_7 -> V_137 , V_15 ) ;
if ( V_127 )
F_53 ( & V_4 -> V_19 , & V_7 -> V_138 ) ;
else
F_56 ( & V_4 -> V_19 , & V_7 -> V_138 ) ;
F_6 ( & V_7 -> V_137 , V_15 ) ;
F_57 ( & V_7 -> V_126 ) ;
F_12 ( V_7 -> V_18 , L_24 ,
V_40 , F_55 ( & V_7 -> V_126 ) ) ;
}
int F_58 ( struct V_14 * V_7 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_29 = 0 ;
struct V_24 * V_30 ;
unsigned long V_139 ;
unsigned long V_140 ;
if ( V_7 -> V_49 ) {
F_5 ( V_7 -> V_18 , L_25 ) ;
return - 1 ;
}
F_3 ( & V_7 -> V_48 , V_139 ) ;
F_3 ( & V_7 -> V_137 , V_140 ) ;
if ( F_4 ( & V_7 -> V_138 ) ) {
F_6 ( & V_7 -> V_137 ,
V_140 ) ;
F_6 ( & V_7 -> V_48 , V_139 ) ;
return 0 ;
}
V_4 = F_7 ( & V_7 -> V_138 ,
struct V_3 , V_19 ) ;
F_6 ( & V_7 -> V_137 ,
V_140 ) ;
V_30 = (struct V_24 * ) ( V_4 -> V_12 -> V_36 ) ;
V_2 = V_4 -> V_2 ;
if ( V_7 -> V_84 != V_136 ) {
F_5 ( V_7 -> V_18 , L_26
L_27 , V_141 ) ;
F_6 ( & V_7 -> V_48 , V_139 ) ;
return V_29 ;
}
F_3 ( & V_7 -> V_137 , V_140 ) ;
F_8 ( & V_4 -> V_19 ) ;
F_6 ( & V_7 -> V_137 ,
V_140 ) ;
F_6 ( & V_7 -> V_48 , V_139 ) ;
V_29 = F_13 ( V_2 , V_4 ) ;
V_2 = F_27 ( V_7 , V_80 ) ;
if ( V_2 && ( V_30 -> V_40 !=
F_17 ( V_142 ) ) ) {
if ( V_7 -> V_143 ) {
V_7 -> V_87 = false ;
F_31 ( V_2 , false ) ;
}
}
return V_29 ;
}
int F_59 ( struct V_14 * V_7 )
{
struct V_24 * V_144 ;
struct V_1 * V_2 =
F_27 ( V_7 , V_80 ) ;
int V_29 = 0 ;
T_2 V_145 ;
T_2 V_146 ;
T_2 V_147 ;
struct V_33 V_34 ;
unsigned long V_15 ;
F_60 ( & V_7 -> V_72 ) ;
if ( ! V_7 -> V_49 || ! V_7 -> V_49 -> V_21 ) {
V_144 = (struct V_24 * ) V_7 -> V_148 ;
F_5 ( V_7 -> V_18 , L_28 ,
F_15 ( V_144 -> V_40 ) ) ;
return - 1 ;
}
V_7 -> V_149 = 0 ;
V_144 = (struct V_24 * ) V_7 -> V_49 -> V_21 -> V_36 ;
if ( V_7 -> V_49 -> V_20 & V_150 ) {
F_5 ( V_7 -> V_18 , L_29 ,
F_15 ( V_144 -> V_40 ) ) ;
F_14 ( V_7 , V_7 -> V_49 ) ;
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_49 = NULL ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
return - 1 ;
}
if ( V_7 -> V_49 -> V_20 & V_122 ) {
struct V_26 * V_151 ;
T_2 V_37 = F_15 ( V_144 -> V_37 ) ;
F_12 ( V_7 -> V_18 , L_30 , V_37 ) ;
V_37 = F_61 ( V_105 , V_37 , V_97 ) ;
if ( V_7 -> V_49 -> V_6 ) {
V_151 = V_7 -> V_49 -> V_6 ;
V_151 -> V_28 = V_37 ;
memcpy ( V_151 -> V_25 , V_144 , V_37 ) ;
}
}
V_145 = F_15 ( V_144 -> V_40 ) ;
V_2 = F_38 ( V_7 ,
F_62 ( F_15 ( V_144 -> V_45 ) ) ,
F_63 ( F_15 ( V_144 -> V_45 ) ) ) ;
if ( ! V_2 )
V_2 = F_27 ( V_7 , V_80 ) ;
V_144 -> V_40 = F_17 ( V_145 & V_71 ) ;
V_146 = F_15 ( V_144 -> V_40 ) ;
V_147 = F_15 ( V_144 -> V_117 ) ;
V_7 -> V_65 . V_152 =
( V_7 -> V_65 . V_152 + 1 ) % V_68 ;
V_7 -> V_65 . V_153 [ V_7 -> V_65 . V_152 ] =
V_145 ;
F_20 ( & V_34 ) ;
F_12 ( V_7 -> V_18 , L_31
L_32 ,
V_34 . V_50 , V_34 . V_51 , V_145 , V_147 ,
F_15 ( V_144 -> V_37 ) , F_15 ( V_144 -> V_45 ) ) ;
if ( ! ( V_145 & V_154 ) ) {
F_5 ( V_7 -> V_18 , L_33 ) ;
if ( V_7 -> V_49 -> V_9 )
V_7 -> V_38 . V_39 = - 1 ;
F_14 ( V_7 , V_7 -> V_49 ) ;
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_49 = NULL ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
return - 1 ;
}
if ( V_7 -> V_49 -> V_20 & V_122 ) {
V_7 -> V_49 -> V_20 &= ~ V_122 ;
if ( ( V_147 == V_155 ) &&
( V_146 == V_142 ) )
V_29 = F_64 ( V_2 , V_144 ) ;
} else {
V_29 = F_65 ( V_2 , V_146 , V_144 ) ;
}
if ( V_7 -> V_41 == V_156 ) {
if ( V_29 ) {
F_5 ( V_7 -> V_18 , L_34
L_35 , V_141 , V_146 ) ;
F_66 ( V_7 ) ;
return - 1 ;
} else if ( V_7 -> V_157 == V_146 )
V_7 -> V_41 = V_158 ;
}
if ( V_7 -> V_49 ) {
if ( V_7 -> V_49 -> V_9 )
V_7 -> V_38 . V_39 = V_29 ;
F_14 ( V_7 , V_7 -> V_49 ) ;
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_49 = NULL ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
}
return V_29 ;
}
void
F_67 ( unsigned long V_159 )
{
struct V_14 * V_7 =
(struct V_14 * ) V_159 ;
struct V_3 * V_4 ;
struct V_33 V_34 ;
V_7 -> V_149 ++ ;
V_7 -> V_65 . V_149 ++ ;
if ( ! V_7 -> V_49 ) {
F_12 ( V_7 -> V_18 , L_36 ) ;
return;
}
V_4 = V_7 -> V_49 ;
if ( V_4 ) {
V_7 -> V_65 . V_160 =
V_7 -> V_65 . V_69 [ V_7 -> V_65 . V_67 ] ;
V_7 -> V_65 . V_161 =
V_7 -> V_65 . V_70 [ V_7 -> V_65 . V_67 ] ;
F_20 ( & V_34 ) ;
F_5 ( V_7 -> V_18 ,
L_37 ,
V_141 , V_34 . V_50 , V_34 . V_51 ,
V_7 -> V_65 . V_160 ,
V_7 -> V_65 . V_161 ) ;
F_5 ( V_7 -> V_18 , L_38 ,
V_7 -> V_65 . V_162 ) ;
F_5 ( V_7 -> V_18 , L_39 ,
V_7 -> V_65 . V_66 ) ;
F_5 ( V_7 -> V_18 , L_40 ,
V_7 -> V_65 . V_149 ) ;
F_5 ( V_7 -> V_18 , L_41 ,
V_7 -> V_65 . V_163 ) ;
F_5 ( V_7 -> V_18 , L_42 ,
V_7 -> V_65 . V_67 ) ;
F_5 ( V_7 -> V_18 , L_43 ,
( int ) sizeof( V_7 -> V_65 . V_69 ) ,
V_7 -> V_65 . V_69 ) ;
F_5 ( V_7 -> V_18 , L_44 ,
( int ) sizeof( V_7 -> V_65 . V_70 ) ,
V_7 -> V_65 . V_70 ) ;
F_5 ( V_7 -> V_18 , L_45 ,
V_7 -> V_65 . V_152 ) ;
F_5 ( V_7 -> V_18 , L_46 ,
( int ) sizeof( V_7 -> V_65 . V_153 ) ,
V_7 -> V_65 . V_153 ) ;
F_5 ( V_7 -> V_18 , L_47 ,
V_7 -> V_65 . V_103 ) ;
F_5 ( V_7 -> V_18 , L_48 ,
( int ) sizeof( V_7 -> V_65 . V_104 ) ,
V_7 -> V_65 . V_104 ) ;
F_5 ( V_7 -> V_18 , L_49 ,
V_7 -> V_164 , V_7 -> V_59 ) ;
F_5 ( V_7 -> V_18 , L_50 ,
V_7 -> V_165 , V_7 -> V_84 ) ;
if ( V_4 -> V_9 ) {
V_7 -> V_38 . V_39 = - V_166 ;
F_68 ( & V_7 -> V_38 . V_167 ) ;
F_69 ( V_7 ) ;
V_7 -> V_59 = false ;
}
}
if ( V_7 -> V_41 == V_156 )
F_66 ( V_7 ) ;
if ( V_7 -> V_22 . V_168 )
V_7 -> V_22 . V_168 ( V_7 ) ;
}
void
F_70 ( struct V_14 * V_7 )
{
struct V_3 * V_4 = NULL , * V_169 ;
unsigned long V_15 ;
if ( ( V_7 -> V_49 ) && ( V_7 -> V_49 -> V_9 ) ) {
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_49 -> V_9 = false ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_38 . V_39 = - 1 ;
F_16 ( V_7 , V_7 -> V_49 ) ;
}
F_3 ( & V_7 -> V_137 , V_15 ) ;
F_71 (cmd_node, tmp_node,
&adapter->cmd_pending_q, list) {
F_8 ( & V_4 -> V_19 ) ;
F_6 ( & V_7 -> V_137 , V_15 ) ;
if ( V_4 -> V_9 ) {
V_7 -> V_38 . V_39 = - 1 ;
F_16 ( V_7 , V_4 ) ;
V_4 -> V_9 = false ;
}
F_14 ( V_7 , V_4 ) ;
F_3 ( & V_7 -> V_137 , V_15 ) ;
}
F_6 ( & V_7 -> V_137 , V_15 ) ;
F_3 ( & V_7 -> V_170 , V_15 ) ;
F_71 (cmd_node, tmp_node,
&adapter->scan_pending_q, list) {
F_8 ( & V_4 -> V_19 ) ;
F_6 ( & V_7 -> V_170 , V_15 ) ;
V_4 -> V_9 = false ;
F_34 ( V_7 , V_4 ) ;
F_3 ( & V_7 -> V_170 , V_15 ) ;
}
F_6 ( & V_7 -> V_170 , V_15 ) ;
F_3 ( & V_7 -> V_48 , V_15 ) ;
V_7 -> V_171 = false ;
F_6 ( & V_7 -> V_48 , V_15 ) ;
}
void
F_69 ( struct V_14 * V_7 )
{
struct V_3 * V_4 = NULL , * V_169 = NULL ;
unsigned long V_139 ;
unsigned long V_172 ;
T_2 V_173 = false ;
if ( ( V_7 -> V_49 ) &&
( V_7 -> V_49 -> V_9 ) ) {
F_3 ( & V_7 -> V_48 , V_139 ) ;
V_4 = V_7 -> V_49 ;
V_4 -> V_9 = false ;
V_4 -> V_20 |= V_150 ;
F_14 ( V_7 , V_4 ) ;
F_16 ( V_7 , V_7 -> V_49 ) ;
V_7 -> V_49 = NULL ;
F_6 ( & V_7 -> V_48 , V_139 ) ;
}
F_3 ( & V_7 -> V_170 ,
V_172 ) ;
F_71 (cmd_node, tmp_node,
&adapter->scan_pending_q, list) {
F_8 ( & V_4 -> V_19 ) ;
F_6 ( & V_7 -> V_170 ,
V_172 ) ;
V_4 -> V_9 = false ;
F_34 ( V_7 , V_4 ) ;
F_3 ( & V_7 -> V_170 ,
V_172 ) ;
V_173 = true ;
}
F_6 ( & V_7 -> V_170 ,
V_172 ) ;
if ( V_173 ) {
F_3 ( & V_7 -> V_48 , V_139 ) ;
V_7 -> V_171 = false ;
F_6 ( & V_7 -> V_48 , V_139 ) ;
}
V_7 -> V_38 . V_39 = - 1 ;
}
void
F_72 ( struct V_14 * V_7 )
{
if ( ! V_7 -> V_59 &&
! V_7 -> V_49 && ! F_73 ( V_7 ) )
F_26 ( V_7 ) ;
else
F_12 ( V_7 -> V_18 ,
L_51 ,
( V_7 -> V_59 ) ? L_52 : L_53 ,
( V_7 -> V_49 ) ? L_54 : L_53 ,
( F_73 ( V_7 ) ) ? L_55 : L_53 ) ;
}
void
F_31 ( struct V_1 * V_2 , V_53 V_174 )
{
if ( V_174 ) {
if ( V_2 -> V_7 -> V_87 ) {
V_2 -> V_7 -> V_143 = true ;
F_74 ( V_2 -> V_7 ,
V_175 ) ;
F_12 ( V_2 -> V_7 -> V_18 , L_56 ) ;
V_2 -> V_7 -> V_176 = true ;
F_68 (
& V_2 -> V_7 -> V_177 ) ;
} else {
F_12 ( V_2 -> V_7 -> V_18 , L_57 ) ;
}
} else {
F_12 ( V_2 -> V_7 -> V_18 , L_58 ) ;
V_2 -> V_7 -> V_143 = false ;
}
}
int F_64 ( struct V_1 * V_2 ,
struct V_24 * V_144 )
{
struct V_14 * V_7 = V_2 -> V_7 ;
struct V_178 * V_179 =
& V_144 -> V_131 . V_180 ;
T_4 V_181 = F_75 ( V_179 -> V_131 . V_182 . V_181 ) ;
if ( V_179 -> V_133 == F_17 ( V_183 ) &&
V_7 -> V_55 != V_56 ) {
F_31 ( V_2 , true ) ;
return 0 ;
} else {
F_12 ( V_7 -> V_18 , L_59
L_60 ,
V_144 -> V_117 , V_181 ,
V_179 -> V_131 . V_182 . V_184 ,
V_179 -> V_131 . V_182 . V_185 ) ;
}
if ( V_181 != V_186 ) {
V_7 -> V_87 = true ;
if ( V_7 -> V_55 == V_56 )
F_31 ( V_2 , true ) ;
} else {
V_7 -> V_87 = false ;
if ( V_7 -> V_143 )
F_31 ( V_2 , false ) ;
}
return 0 ;
}
void
F_76 ( struct V_14 * V_7 )
{
F_12 ( V_7 -> V_18 , L_61
L_62 , V_141 ) ;
V_7 -> V_22 . V_187 ( V_7 ) ;
V_7 -> V_143 = false ;
V_7 -> V_87 = false ;
V_7 -> V_115 = false ;
F_31 ( F_27 ( V_7 ,
V_80 ) ,
false ) ;
}
void
F_77 ( struct V_14 * V_7 ,
V_53 * V_188 , T_1 V_189 )
{
struct V_24 * V_25 = (struct V_24 * ) V_188 ;
struct V_1 * V_2 =
F_27 ( V_7 , V_80 ) ;
T_2 V_117 = F_15 ( V_25 -> V_117 ) ;
T_2 V_40 = F_15 ( V_25 -> V_40 ) ;
T_2 V_45 = F_15 ( V_25 -> V_45 ) ;
if ( ! V_189 ) {
F_5 ( V_7 -> V_18 , L_63 , V_141 ) ;
return;
}
V_2 = F_38 ( V_7 , F_62 ( V_45 ) ,
F_63 ( V_45 ) ) ;
if ( ! V_2 )
V_2 = F_27 ( V_7 , V_80 ) ;
V_45 = F_78 ( V_45 ) ;
V_40 &= V_71 ;
if ( V_40 != V_128 ) {
F_5 ( V_7 -> V_18 ,
L_64 ,
V_141 , V_40 , V_117 ) ;
return;
}
if ( V_117 ) {
F_5 ( V_7 -> V_18 , L_65 ,
V_141 ) ;
V_7 -> V_90 = false ;
V_7 -> V_84 = V_136 ;
return;
}
V_7 -> V_90 = true ;
if ( V_7 -> V_87 )
F_31 ( F_27
( V_7 , V_80 ) ,
true ) ;
V_7 -> V_84 = V_85 ;
V_25 -> V_40 = F_17 ( V_40 ) ;
V_25 -> V_45 = F_17 ( V_45 ) ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
V_105 V_113 , T_2 V_190 ,
struct V_191 * V_192 )
{
struct V_129 * V_132 =
& V_25 -> V_131 . V_132 ;
V_53 * V_193 ;
V_105 V_32 = 0 ;
V_25 -> V_40 = F_17 ( V_128 ) ;
if ( V_113 == V_135 ) {
V_132 -> V_133 = F_17 ( V_135 ) ;
V_132 -> V_131 . V_190 = F_17 ( V_190 ) ;
V_25 -> V_37 = F_17 ( V_54 + sizeof( V_132 -> V_133 ) +
sizeof( V_132 -> V_131 . V_190 ) ) ;
} else if ( V_113 == V_194 ) {
V_132 -> V_133 = F_17 ( V_194 ) ;
V_132 -> V_131 . V_190 = F_17 ( V_190 ) ;
V_25 -> V_37 = F_17 ( V_54 + sizeof( V_132 -> V_133 ) +
sizeof( V_132 -> V_131 . V_190 ) ) ;
} else if ( V_113 == V_195 ) {
V_132 -> V_133 = F_17 ( V_195 ) ;
V_132 -> V_131 . V_190 = F_17 ( V_190 ) ;
V_32 = V_54 + sizeof( V_132 -> V_133 ) +
sizeof( V_132 -> V_131 . V_190 ) ;
V_193 = ( V_53 * ) V_25 + V_32 ;
if ( V_190 & V_196 ) {
struct V_14 * V_7 = V_2 -> V_7 ;
struct V_197 * V_198 =
(struct V_197 * ) V_193 ;
struct V_199 * V_165 = & V_198 -> V_200 ;
V_198 -> V_201 . type = F_17 ( V_202 ) ;
V_198 -> V_201 . V_28 = F_17 ( sizeof( * V_198 ) -
sizeof( struct V_203 ) ) ;
V_32 += sizeof( * V_198 ) ;
V_193 += sizeof( * V_198 ) ;
F_12 ( V_7 -> V_18 , L_66 ) ;
V_165 -> V_204 =
F_17 ( V_7 -> V_204 ) ;
V_165 -> V_205 =
F_17 ( V_7 -> V_206 ) ;
V_165 -> V_207 =
F_17 ( V_7 -> V_208 ) ;
V_165 -> V_209 =
F_17 ( V_7 -> V_209 ) ;
V_165 -> V_210 =
F_17 ( V_7 -> V_211 ) ;
V_165 -> V_212 =
F_17 ( V_7 -> V_212 ) ;
V_165 -> V_213 = F_17 ( V_7 -> V_214 ) ;
}
if ( V_190 & V_215 ) {
struct V_216 * V_217 =
(struct V_216 * ) V_193 ;
V_105 V_218 = 0 ;
V_217 -> V_201 . type =
F_17 ( V_219 ) ;
V_217 -> V_201 . V_28 =
F_17 ( sizeof( * V_217 ) -
sizeof( struct V_203 ) ) ;
V_32 += sizeof( * V_217 ) ;
V_193 += sizeof( * V_217 ) ;
if ( V_192 )
V_218 = V_192 -> V_220 ;
F_12 ( V_2 -> V_7 -> V_18 ,
L_67 ) ;
V_217 -> V_221 = F_17 ( V_218 ) ;
}
V_25 -> V_37 = F_17 ( V_32 ) ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_24 * V_144 ,
struct V_222 * V_223 )
{
struct V_14 * V_7 = V_2 -> V_7 ;
struct V_129 * V_165 =
& V_144 -> V_131 . V_132 ;
T_2 V_133 = F_15 ( V_165 -> V_133 ) ;
T_2 V_190 = F_15 ( V_165 -> V_131 . V_190 ) ;
T_2 V_224 =
F_15 ( V_165 -> V_131 . V_190 ) ;
F_12 ( V_7 -> V_18 ,
L_68 ,
V_141 , V_144 -> V_117 , V_133 ) ;
if ( V_133 == V_195 ) {
if ( V_224 & V_215 ) {
F_12 ( V_7 -> V_18 , L_69 ) ;
V_2 -> V_7 -> V_225 = true ;
}
if ( V_224 & V_196 ) {
F_12 ( V_7 -> V_18 , L_70 ) ;
if ( V_7 -> V_88 . V_89 )
F_12 ( V_7 -> V_18 ,
L_71 ) ;
}
} else if ( V_133 == V_135 ) {
if ( V_190 & V_215 ) {
V_2 -> V_7 -> V_225 = false ;
F_12 ( V_7 -> V_18 , L_72 ) ;
}
if ( V_190 & V_196 ) {
F_12 ( V_7 -> V_18 , L_73 ) ;
if ( V_7 -> V_88 . V_89 ) {
V_7 -> V_226 = false ;
V_7 -> V_227 = false ;
V_7 -> V_228 = false ;
}
}
} else if ( V_133 == V_194 ) {
if ( V_190 & V_196 )
V_7 -> V_165 = V_229 ;
else
V_7 -> V_165 = V_230 ;
F_12 ( V_7 -> V_18 , L_74 , V_190 ) ;
if ( V_223 ) {
if ( V_190 & V_196 )
V_223 -> V_200 . V_165 = 1 ;
else
V_223 -> V_200 . V_165 = 0 ;
}
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_231 * V_232 = & V_25 -> V_131 . V_232 ;
V_25 -> V_40 = F_17 ( V_233 ) ;
V_25 -> V_37 =
F_17 ( sizeof( struct V_231 ) + V_54 ) ;
memcpy ( V_232 -> V_234 , V_2 -> V_235 , V_236 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_24 * V_144 )
{
struct V_231 * V_232 = & V_144 -> V_131 . V_232 ;
struct V_14 * V_7 = V_2 -> V_7 ;
int V_92 ;
V_7 -> V_237 = F_75 ( V_232 -> V_237 ) ;
if ( F_83 ( V_7 ) )
V_7 -> V_238 = ( V_53 ) F_84 ( V_7 ) ;
else
V_7 -> V_238 = V_239 ;
V_7 -> V_240 = V_7 -> V_238 ;
if ( V_7 -> V_238 & V_241 ) {
if ( V_7 -> V_238 & V_242 ) {
V_7 -> V_240 |= V_243 ;
V_7 -> V_238 |= V_243 ;
}
if ( V_7 -> V_238 & V_243 ) {
V_7 -> V_244 = V_241 | V_243 ;
V_7 -> V_245 = true ;
} else {
V_7 -> V_244 = V_241 ;
}
V_2 -> V_246 = V_247 ;
} else if ( V_7 -> V_238 & V_242 ) {
V_7 -> V_244 = V_248 | V_239 | V_242 ;
V_2 -> V_246 = V_249 ;
V_7 -> V_245 = true ;
} else if ( V_7 -> V_238 & V_248 ) {
V_7 -> V_244 = V_248 | V_239 ;
V_2 -> V_246 = V_249 ;
} else if ( V_7 -> V_238 & V_239 ) {
V_7 -> V_244 = V_239 ;
V_2 -> V_246 = V_249 ;
}
V_7 -> V_250 = F_75 ( V_232 -> V_250 ) ;
V_7 -> V_251 = F_15 ( V_232 -> V_251 ) ;
if ( F_75 ( V_232 -> V_252 ) ) {
V_7 -> V_253 = true ;
V_7 -> V_254 =
F_75 ( V_232 -> V_252 ) ;
V_7 -> V_255 = V_7 -> V_254 ;
V_7 -> V_256 = V_7 -> V_254 ;
V_7 -> V_257 =
F_75 ( V_232 -> V_258 ) ;
V_7 -> V_259 =
V_7 -> V_257 ;
} else {
V_7 -> V_253 = false ;
}
F_12 ( V_7 -> V_18 , L_75 ,
V_7 -> V_250 ) ;
F_12 ( V_7 -> V_18 , L_76 ,
V_232 -> V_234 ) ;
F_12 ( V_7 -> V_18 ,
L_77 ,
F_15 ( V_232 -> V_260 ) ,
F_15 ( V_232 -> V_261 ) ) ;
if ( V_2 -> V_235 [ 0 ] == 0xff )
memmove ( V_2 -> V_235 , V_232 -> V_234 , V_236 ) ;
V_7 -> V_262 = F_15 ( V_232 -> V_262 ) ;
for ( V_92 = 0 ; V_92 < V_263 ; V_92 ++ )
if ( V_7 -> V_262 == V_264 [ V_92 ] )
break;
if ( V_92 >= V_263 ) {
V_7 -> V_262 = 0x10 ;
F_12 ( V_7 -> V_18 ,
L_78 ) ;
}
V_7 -> V_265 = F_75 ( V_232 -> V_266 ) ;
V_7 -> V_267 = V_232 -> V_268 ;
if ( V_7 -> V_22 . V_269 )
V_7 -> V_22 . V_269 ( V_7 ,
F_15 ( V_232 -> V_270 ) ) ;
return 0 ;
}
