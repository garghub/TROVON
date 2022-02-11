int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
T_1 V_5 ,
T_2 V_6 ,
bool V_7 ,
T_3 * V_8 ,
T_4 V_9 )
{
T_3 V_10 = 0 ;
T_3 V_11 = 0 ;
T_3 V_12 = 0 ;
T_5 V_13 =
V_2 -> V_14 . V_15 ;
T_5 V_16 =
V_2 -> V_14 . V_17 ;
T_3 V_18 ;
T_3 V_19 = 0 ;
bool V_20 = 0 ;
LONG V_21 = 0 ;
T_3 V_22 = 0 ;
struct V_3 * V_23 = NULL ;
struct V_3 * V_24 = * V_4 ;
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_1 ) ;
if ( ! V_9 )
V_19 = V_28 ;
V_18 = ( (struct V_29 * ) ( V_24 -> V_30 ) ) -> V_31 ;
V_13 = V_24 -> V_30 + V_19 ;
if ( ( * V_8 - V_19 ) < V_32 )
V_10 = ( * V_8 - V_19 ) ;
else
V_10 = V_32 ;
if ( ( V_10 > 0 ) &&
( V_10 <= V_32 ) ) {
if ( ( ( V_18 == V_33 ) ||
( V_18 == V_34 ) ) &&
( V_7 ) ) {
F_2 ( V_2 , V_25 , V_26 ,
V_27 ,
L_2 ,
V_6 ) ;
V_12 = V_10 ;
V_21 = F_3 ( & V_2 -> V_35 ,
V_5 ,
V_6 ,
V_13 ,
V_16 ,
& V_11 ,
& V_12 ) ;
F_2 ( V_2 , V_25 , V_26 ,
V_27 ,
L_3 ,
V_11 , V_12 ) ;
if ( V_12 == V_11 ) {
if ( V_21 == V_36 )
V_20 = * V_16 ;
V_21 = V_37 ;
}
if ( V_21 == V_36 ) {
F_2 ( V_2 , V_25 ,
V_26 , V_27 ,
L_4 ) ;
if ( F_4 ( V_24 ) ) {
V_23 =
F_5 ( V_24 , V_38 ) ;
if ( V_23 == NULL )
return V_39 ;
F_6 ( V_24 ) ;
* V_4 = V_24 = V_23 ;
V_13 =
V_24 -> V_30 + V_19 ;
}
V_22 = V_11 -
( V_12 + V_40 ) ;
memcpy ( V_13 + V_22 ,
V_16 ,
V_12 + V_40 ) ;
memcpy ( V_24 -> V_30 + V_22 ,
V_24 -> V_30 , V_19 ) ;
F_7 ( V_24 , V_22 ) ;
return V_41 ;
} else {
if ( ! ( F_8 ( V_24 ) > 0 ) ) {
if ( F_9 ( V_24 , 1 ) ) {
F_2 ( V_2 ,
V_42 ,
0 , 0 ,
L_5 ) ;
return V_39 ;
}
}
F_10 ( V_24 , 1 ) ;
* ( V_24 -> V_30 + V_19 ) = V_20 ;
return V_41 ;
}
} else {
if ( ! V_7 )
F_2 ( V_2 , V_25 ,
V_26 , V_27 ,
L_6 ) ;
return V_41 ;
}
}
return V_41 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_43 ,
struct V_3 * V_44 ,
T_3 * V_45 ,
T_4 * V_46 ,
T_3 V_7 )
{
T_6 V_47 = 0 ;
T_6 V_48 = 0 ;
int V_21 = 0 ;
T_5 V_49 = NULL ;
T_3 V_50 = 0 ;
if ( ! V_7 ) {
F_2 ( V_2 , V_25 , V_51 ,
V_27 ,
L_7 ) ;
return V_21 ;
}
V_49 = V_44 -> V_30 ;
V_47 = V_44 -> V_52 ;
V_21 = F_12 ( & V_2 -> V_35 ,
V_43 ,
V_49 ,
V_2 -> V_53 ,
& V_48 ,
& V_47 ) ;
F_2 ( V_2 , V_25 , V_51 , V_27 ,
L_8 ,
V_48 , V_47 ) ;
if ( V_21 != V_36 ) {
F_7 ( V_44 , 1 ) ;
return V_41 ;
} else {
V_50 = V_47 -
V_48 - V_40 ;
if ( V_50 ) {
if ( F_8 ( V_44 ) >= ( V_54 + V_50 ) )
F_10 ( V_44 , V_50 ) ;
else {
if ( F_9 ( V_44 , F_8 ( V_44 ) + V_50 ) ) {
F_2 ( V_2 ,
V_42 , 0 , 0 ,
L_9 ) ;
return V_39 ;
}
F_10 ( V_44 , V_50 ) ;
}
}
memcpy ( V_44 -> V_30 , V_2 -> V_53 ,
V_47 ) ;
}
return V_41 ;
}
void F_13 ( T_4 * V_55 , T_3 V_56 )
{
struct V_1 * V_2 = F_14 ( V_57 ) ;
F_2 ( V_2 , V_58 , V_59 , V_27 ,
L_10 ) ;
F_15 ( V_2 , V_58 , V_59 , V_27 ,
V_55 , V_56 ) ;
}
int F_16 ( struct V_60 * V_61 ,
struct V_1 * V_2 )
{
int V_62 ;
struct V_63 * V_64 ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_11 ) ;
if ( V_61 -> V_66 )
return - V_67 ;
V_61 -> V_66 =
F_17 ( sizeof( struct V_63 ) , V_68 ) ;
if ( ! V_61 -> V_66 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 ,
L_12 ) ;
return - V_69 ;
}
V_64 = V_61 -> V_66 ;
for ( V_62 = 0 ; V_62 < V_70 ; V_62 ++ ) {
struct V_71 V_72 =
V_64 -> V_73 [ V_62 ] ;
V_72 . V_74 =
F_17 ( sizeof( struct V_75 ) ,
V_68 ) ;
if ( ! V_72 . V_74 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_13 ) ;
F_18 ( V_61 -> V_66 ) ;
V_61 -> V_66 = NULL ;
return - V_69 ;
}
}
V_61 -> V_76 = F_19 ( V_77 , V_68 ) ;
if ( V_61 -> V_76 == NULL ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_13 ) ;
F_18 ( V_61 -> V_66 ) ;
V_61 -> V_66 = NULL ;
return - V_69 ;
}
V_61 -> V_78 =
F_19 ( V_77 , V_68 ) ;
if ( V_61 -> V_78 == NULL ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_13 ) ;
F_20 ( V_61 -> V_76 ) ;
F_18 ( V_61 -> V_66 ) ;
V_61 -> V_66 = NULL ;
return - V_69 ;
}
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_14 ) ;
return V_41 ;
}
int F_21 ( T_7 struct V_60 * V_79 )
{
if ( V_79 -> V_66 ) {
F_18 ( V_79 -> V_66 ) ;
V_79 -> V_66 = NULL ;
}
F_20 ( V_79 -> V_76 ) ;
V_79 -> V_76 = NULL ;
F_20 ( V_79 -> V_78 ) ;
V_79 -> V_78 = NULL ;
return 0 ;
}
T_8 F_22 ( T_7 void * V_80 ,
T_7 T_2 V_81 ,
T_7 T_2 V_82 ,
T_7 struct V_83 * V_84 ,
T_7 T_9 V_85 )
{
T_8 V_86 = 0 ;
T_3 V_87 = 0 ;
struct V_71 * V_88 = NULL ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_60 * V_89 =
(struct V_60 * ) V_80 ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_15 ) ;
if ( V_89 == NULL ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_16 ) ;
return V_90 ;
}
if ( V_85 == 0 )
return V_91 ;
V_87 = F_23 ( V_89 -> V_66 ,
V_81 , & V_88 ) ;
if ( V_87 == V_92 ) {
V_86 = F_24 ( V_81 , V_82 ,
V_89 -> V_66 ,
V_84 ,
V_85 ) ;
return V_86 ;
}
V_86 = F_25 ( V_81 , V_82 ,
V_88 ,
V_84 ,
V_85 ) ;
return V_86 ;
}
T_8 F_26 ( T_7 void * V_80 ,
T_7 T_2 V_81 ,
T_7 T_9 V_93 )
{
T_3 V_87 = 0 , V_94 = 0 ;
struct V_71 * V_88 = NULL ;
struct V_75 * V_95 = NULL ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_60 * V_89 = (struct V_60 * ) V_80 ;
struct V_96 * V_97 ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_17 ) ;
if ( V_89 ) {
V_87 = F_23 ( V_89 -> V_66 ,
V_81 , & V_88 ) ;
if ( V_87 == V_92 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_18 ) ;
return V_98 ;
}
V_95 = V_88 -> V_74 ;
if ( V_95 ) {
for ( V_94 = 0 ; V_94 < V_99 ; V_94 ++ ) {
V_97 = & V_95 -> V_100 [ V_94 ] ;
if ( V_97 -> V_101 &&
V_97 -> V_102 &&
( V_97 -> V_102 -> V_93 == V_93 ) ) {
if ( V_97 -> V_102 -> V_103 )
V_97 -> V_102 -> V_103 -- ;
if ( 0 == V_97 -> V_102 -> V_103 )
F_20 ( V_97 -> V_102 ) ;
memset ( V_97 ,
0 ,
sizeof( struct V_96 ) ) ;
}
}
}
}
return 0 ;
}
T_8 F_27 ( T_7 void * V_80 ,
T_7 T_2 V_81 ,
T_7 T_2 V_82 )
{
T_3 V_87 = 0 , V_94 = 0 ;
struct V_71 * V_88 = NULL ;
struct V_96 * V_104 = NULL ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_60 * V_89 =
(struct V_60 * ) V_80 ;
if ( ! V_89 )
goto V_105;
V_87 = F_23 ( V_89 -> V_66 ,
V_81 , & V_88 ) ;
if ( V_87 == V_92 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_18 ) ;
return V_98 ;
}
V_94 =
F_28 ( V_88 -> V_74 ,
V_82 ,
V_106 ,
& V_104 ) ;
if ( ( V_94 != V_92 ) &&
( ! V_104 -> V_107 ) ) {
if ( V_104 -> V_102 ) {
if ( V_104 -> V_102 -> V_103 )
V_104 -> V_102 -> V_103 -- ;
if ( 0 == V_104 -> V_102 -> V_103 )
F_20 ( V_104 -> V_102 ) ;
}
memset ( V_104 , 0 ,
sizeof( struct V_96 ) ) ;
}
V_94 =
F_28 ( V_88 -> V_74 ,
V_82 ,
V_108 ,
& V_104 ) ;
if ( ( V_94 != V_92 ) &&
( ! V_104 -> V_107 ) ) {
F_20 ( V_104 -> V_102 ) ;
memset ( V_104 , 0 ,
sizeof( struct V_96 ) ) ;
}
V_105:
return 0 ;
}
T_8 F_29 ( T_7 void * V_80 , T_7 T_2 V_81 )
{
T_3 V_87 = 0 , V_94 = 0 ;
struct V_71 * V_88 = NULL ;
struct V_75 * V_95 = NULL ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_60 * V_89 =
(struct V_60 * ) V_80 ;
struct V_96 * V_109 ;
struct V_96 * V_110 ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_19 ) ;
if ( ! V_89 )
goto V_105;
V_87 = F_23 ( V_89 -> V_66 ,
V_81 , & V_88 ) ;
if ( V_87 == V_92 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_18 ) ;
return V_98 ;
}
V_95 = V_88 -> V_74 ;
if ( V_95 ) {
for ( V_94 = 0 ; V_94 < V_99 ; V_94 ++ ) {
V_109 =
& V_95 -> V_100 [ V_94 ] ;
V_110 =
& V_95 -> V_111 [ V_94 ] ;
if ( V_109 -> V_102 ) {
if ( V_109 -> V_102 -> V_103 )
V_109 -> V_102 -> V_103 -- ;
if ( 0 == V_109 -> V_102 -> V_103 )
F_20 ( V_109 -> V_102 ) ;
V_109 -> V_102 = NULL ;
}
memset ( V_109 , 0 ,
sizeof( struct V_96 ) ) ;
if ( V_110 -> V_102 ) {
if ( V_110 -> V_102 -> V_103 )
V_110 -> V_102 -> V_103 -- ;
if ( 0 == V_110 -> V_102 -> V_103 )
F_20 ( V_110 -> V_102 ) ;
V_110 -> V_102 = NULL ;
}
memset ( V_110 , 0 ,
sizeof( struct V_96 ) ) ;
}
}
V_88 -> V_101 = false ;
V_88 -> V_81 = 0 ;
V_105:
return 0 ;
}
static T_8 F_3 ( T_7 void * V_80 ,
T_7 T_2 V_81 ,
T_7 T_2 V_82 ,
T_7 void * V_112 ,
T_10 void * V_113 ,
T_10 T_3 * V_114 ,
T_10 T_3 * V_115 )
{
T_3 V_87 = 0 , V_94 = 0 ;
struct V_71 * V_88 = NULL ;
struct V_96 * V_104 = NULL ;
struct V_83 * V_102 = NULL ;
T_8 V_86 = 0 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_60 * V_89 =
(struct V_60 * ) V_80 ;
if ( V_89 == NULL ) {
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_16 ) ;
V_86 = V_37 ;
return V_86 ;
}
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_20 ) ;
V_87 = F_23 ( V_89 -> V_66 ,
V_81 , & V_88 ) ;
if ( V_87 == V_92 ) {
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_18 ) ;
V_86 = V_37 ;
return V_86 ;
}
V_94 = F_28 ( V_88 -> V_74 ,
V_82 , V_106 ,
& V_104 ) ;
if ( V_94 == V_92 ) {
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_21 ) ;
V_86 = V_37 ;
return V_86 ;
}
V_102 = V_104 -> V_102 ;
if ( ! F_30 ( V_102 ) ) {
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_22 ) ;
V_86 = V_37 ;
return V_86 ;
}
V_86 = F_31 ( V_102 ,
( T_5 ) V_112 ,
( T_5 ) V_113 ,
V_114 ,
V_115 ) ;
if ( V_86 == V_36 ) {
V_102 -> V_116 +=
* V_114 - * V_115 - 1 ;
V_102 -> V_117 ++ ;
} else {
V_102 -> V_118 ++ ;
}
return V_86 ;
}
static T_8 F_12 ( T_7 void * V_80 ,
T_7 T_2 V_81 ,
T_7 void * V_112 ,
T_10 void * V_113 ,
T_10 T_3 * V_119 ,
T_10 T_3 * V_120 )
{
T_3 V_87 = 0 , V_121 = 0 ;
struct V_71 * V_88 = NULL ;
struct V_83 * V_102 = NULL ;
T_3 V_122 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_60 * V_89 =
(struct V_60 * ) V_80 ;
* V_119 = 0 ;
if ( V_89 == NULL ) {
F_2 ( V_2 , V_25 , V_51 ,
V_27 , L_16 ) ;
return V_90 ;
}
F_2 ( V_2 , V_25 , V_51 , V_27 ,
L_23 ) ;
V_122 = * ( ( unsigned char * ) ( V_112 ) ) ;
F_2 ( V_2 , V_25 , V_51 , V_27 ,
L_24 , V_122 ) ;
if ( V_122 == V_123 )
return V_37 ;
V_87 = F_23 ( V_89 -> V_66 ,
V_81 , & V_88 ) ;
if ( V_87 == V_92 ) {
F_2 ( V_2 , V_25 , V_51 ,
V_27 ,
L_25 ) ;
return V_98 ;
}
V_121 = F_32 ( V_88 -> V_74 ,
V_122 ,
V_106 ,
& V_102 ) ;
if ( V_121 == V_92 ) {
V_121 = F_32 ( V_88 -> V_74 ,
V_122 ,
V_108 ,
& V_102 ) ;
if ( V_121 == V_92 )
return V_124 ;
}
* V_119 = F_33 ( ( T_5 ) V_112 ,
( T_5 ) V_113 ,
V_102 ,
V_120 ) ;
V_102 -> V_116 += * V_120 - * V_119 - 1 ;
V_102 -> V_117 ++ ;
return V_36 ;
}
static void F_18 ( struct V_63 * V_125 )
{
int V_62 , V_126 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_96 * V_127 ;
struct V_96 * V_128 ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_26 ) ;
if ( ! V_125 )
goto V_105;
for ( V_62 = 0 ; V_62 < V_70 ; V_62 ++ ) {
struct V_71 V_129 =
V_125 -> V_73 [ V_62 ] ;
struct V_75 * V_95 =
V_129 . V_74 ;
if ( V_95 ) {
for ( V_126 = 0 ; V_126 < V_99 ; V_126 ++ ) {
V_127 =
& V_95 -> V_100 [ V_126 ] ;
V_128 =
& V_95 -> V_111 [ V_126 ] ;
if ( V_127 -> V_102 ) {
if ( V_127 -> V_102 -> V_103 )
V_127 -> V_102 -> V_103 -- ;
if ( 0 == V_127 -> V_102 -> V_103 )
F_20 ( V_127 -> V_102 ) ;
V_127 -> V_102 = NULL ;
}
if ( V_128 -> V_102 ) {
if ( V_128 -> V_102 -> V_103 )
V_128 -> V_102 -> V_103 -- ;
if ( 0 == V_128 -> V_102 -> V_103 )
F_20 ( V_128 -> V_102 ) ;
V_128 -> V_102 = NULL ;
}
}
F_20 ( V_95 ) ;
V_129 . V_74 =
V_95 = NULL ;
}
}
V_105:
F_20 ( V_125 ) ;
V_125 = NULL ;
}
T_3 F_23 ( T_7 struct V_63 * V_130 ,
T_7 T_2 V_81 ,
struct V_71 * * V_131 )
{
int V_62 ;
struct V_71 * V_132 ;
for ( V_62 = 0 ; V_62 < V_70 ; V_62 ++ ) {
V_132 = & V_130 -> V_73 [ V_62 ] ;
if ( V_132 -> V_101 && ( V_132 -> V_81 == V_81 ) ) {
* V_131 = V_132 ;
return V_62 ;
}
}
* V_131 = NULL ;
return V_92 ;
}
static T_3 F_28 ( T_7 struct V_75 * V_74 ,
T_7 T_11 V_133 ,
enum V_134 V_135 ,
T_10 struct V_96 * * V_136 )
{
int V_62 ;
struct V_96 * V_137 = NULL ;
for ( V_62 = 0 ; V_62 < V_99 ; V_62 ++ ) {
if ( V_135 == V_106 )
V_137 =
& V_74 -> V_100 [ V_62 ] ;
else
V_137 =
& V_74 -> V_111 [ V_62 ] ;
if ( V_137 -> V_101 &&
( V_137 -> V_138 == V_133 ) ) {
* V_136 = V_137 ;
return V_62 ;
}
}
* V_136 = NULL ;
return V_92 ;
}
static T_3 F_32 ( T_7 struct V_75 * V_74 ,
T_7 T_11 V_139 ,
enum V_134 V_135 ,
T_10 struct V_83 * * V_140 )
{
int V_62 ;
struct V_96 * V_141 = NULL ;
for ( V_62 = 0 ; V_62 < V_99 ; V_62 ++ ) {
if ( V_135 == V_106 )
V_141 =
& V_74 -> V_100 [ V_62 ] ;
else
V_141 =
& V_74 -> V_111 [ V_62 ] ;
if ( V_141 -> V_101 &&
( V_141 -> V_93 == V_139 ) ) {
* V_140 = V_141 -> V_102 ;
return V_62 ;
}
}
* V_140 = NULL ;
return V_92 ;
}
static T_3 F_24 ( T_7 T_2 V_81 ,
T_7 T_2 V_82 ,
T_7 struct V_63 * V_130 ,
struct V_83 * V_84 ,
T_9 V_85 )
{
struct V_75 * V_142 = NULL ;
T_3 V_143 = 0 ;
int V_144 ;
bool V_145 = false ;
struct V_71 * V_146 ;
for ( V_144 = 0 ; V_144 < V_70 ; V_144 ++ ) {
V_146 = & V_130 -> V_73 [ V_144 ] ;
if ( ! V_146 -> V_101 ) {
V_145 = TRUE ;
break;
}
}
if ( ! V_145 )
return V_147 ;
V_142 = V_146 -> V_74 ;
V_143 = F_34 ( V_82 ,
V_142 ,
V_84 ,
V_106 ,
V_85 ) ;
if ( V_143 == V_148 ) {
V_146 -> V_101 = TRUE ;
V_146 -> V_81 = V_81 ;
}
return V_143 ;
}
static T_3 F_25 ( T_7 T_2 V_81 ,
T_7 T_2 V_82 ,
T_7 struct V_71 * V_88 ,
struct V_83 * V_84 ,
T_9 V_85 )
{
struct V_96 * V_104 = NULL ;
T_3 V_143 = V_148 ;
T_3 V_149 = 0 ;
struct V_75 * V_142 = NULL ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
V_142 = V_88 -> V_74 ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_27 ) ;
V_149 = F_28 (
V_88 -> V_74 ,
V_82 ,
V_106 ,
& V_104 ) ;
if ( V_149 == V_92 ) {
V_143 = F_34 ( V_82 , V_142 ,
V_84 ,
V_106 ,
V_85 ) ;
return V_143 ;
}
if ( V_104 -> V_93 == V_84 -> V_93 ) {
if ( V_104 -> V_102 == NULL )
return V_91 ;
if ( V_84 -> V_150 ) {
memcpy ( V_104 -> V_102 -> V_151 ,
V_84 -> V_151 ,
V_32 ) ;
}
if ( V_84 -> V_150 ) {
V_104 -> V_102 -> V_150 =
V_84 -> V_150 ;
}
if ( V_84 -> V_152 ) {
memcpy ( V_104 -> V_102 -> V_153 ,
V_84 -> V_153 ,
V_32 ) ;
}
if ( V_84 -> V_152 ) {
V_104 -> V_102 -> V_152 =
V_84 -> V_152 ;
}
if ( V_84 -> V_154 ) {
V_104 -> V_102 -> V_154 =
V_84 -> V_154 ;
}
V_104 -> V_102 -> V_155 = V_84 -> V_155 ;
} else {
V_143 = F_35 ( V_82 ,
V_104 ,
V_142 ,
V_84 ,
V_85 ) ;
}
return V_143 ;
}
static T_3 F_34 ( T_7 T_2 V_82 ,
struct V_75 * V_142 ,
struct V_83 * V_84 ,
enum V_134 V_135 ,
T_9 V_85 )
{
T_3 V_156 = 0 ;
bool V_145 = false ;
struct V_96 * V_137 = NULL ;
T_3 V_157 = V_148 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
F_2 ( V_2 , V_25 , V_65 , V_27 ,
L_28 ) ;
if ( V_142 == NULL )
return V_158 ;
if ( V_135 == V_108 ) {
V_156 = F_28 ( V_142 ,
V_82 ,
V_135 ,
& V_137 ) ;
if ( V_156 != V_92 ) {
V_145 = TRUE ;
}
}
if ( ! V_145 ) {
for ( V_156 = 0 ; V_156 <
V_99 ; V_156 ++ ) {
if ( V_135 == V_106 )
V_137 = & V_142 -> V_100 [ V_156 ] ;
else
V_137 = & V_142 -> V_111 [ V_156 ] ;
if ( ! V_137 -> V_101 ) {
V_145 = TRUE ;
break;
}
}
}
if ( ! V_145 ) {
if ( V_135 == V_106 )
return V_159 ;
else {
if ( V_142 -> V_160 >= V_99 )
V_142 -> V_160 = 0 ;
V_156 =
V_142 -> V_160 ;
V_137 =
& V_142 -> V_111 [ V_156 ] ;
( V_142 -> V_160 ) ++ ;
}
}
if ( V_135 == V_108 ) {
if ( V_137 -> V_102 == NULL ) {
V_137 -> V_102 =
F_19 ( sizeof( struct V_83 ) ,
V_68 ) ;
if ( NULL == V_137 -> V_102 )
return V_161 ;
}
V_137 -> V_101 = TRUE ;
V_137 -> V_138 = V_82 ;
V_137 -> V_93 = V_84 -> V_93 ;
V_137 -> V_107 =
V_84 -> V_107 ;
memcpy ( V_137 -> V_102 , V_84 ,
sizeof( struct V_83 ) ) ;
} else
V_157 = F_35 ( V_82 ,
V_137 ,
V_142 ,
V_84 ,
V_85 ) ;
return V_157 ;
}
static T_3 F_35 ( T_7 T_2 V_82 ,
T_7 struct V_96 * V_104 ,
struct V_75 * V_142 ,
struct V_83 * V_84 ,
T_9 V_85 )
{
struct V_83 * V_162 = NULL ;
T_3 V_121 = 0 ;
bool V_163 = false ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
V_84 -> V_103 = 0 ;
V_163 = F_36 ( V_82 , V_142 ,
V_104 -> V_102 ) ;
V_121 = F_32 ( V_142 , V_85 ,
V_106 ,
& V_162 ) ;
if ( V_92 == V_121 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 ,
L_29 ) ;
if ( V_84 -> V_93 == 0 ) {
F_2 ( V_2 , V_25 , V_65 ,
V_27 , L_30 ) ;
return V_91 ;
}
if ( false == V_163 ) {
V_104 -> V_102 =
F_19 ( sizeof( struct V_83 ) ,
V_68 ) ;
if ( NULL == V_104 -> V_102 )
return V_161 ;
}
memcpy ( V_104 -> V_102 , V_84 ,
sizeof( struct V_83 ) ) ;
} else {
F_2 ( V_2 , V_25 , V_65 ,
V_27 ,
L_31 ) ;
if ( V_163 ) {
F_20 ( V_104 -> V_102 ) ;
V_104 -> V_102 = NULL ;
}
V_104 -> V_102 = V_162 ;
}
V_104 -> V_101 = TRUE ;
V_104 -> V_93 = V_104 -> V_102 -> V_93 ;
V_104 -> V_138 = V_82 ;
V_104 -> V_102 -> V_103 ++ ;
V_104 -> V_107 =
V_104 -> V_102 -> V_107 ;
return V_148 ;
}
static bool F_36 ( T_7 T_2 V_82 ,
struct V_75 * V_142 ,
struct V_83 * V_102 )
{
if ( V_102 == NULL )
return false ;
if ( V_102 -> V_103 )
V_102 -> V_103 -- ;
return ( 0 == V_102 -> V_103 ) ;
}
static void F_37 ( struct V_1 * V_164 ,
struct V_71 * V_165 ,
struct V_96 * V_166 )
{
int V_167 ;
F_2 ( V_164 , V_25 , V_168 , V_27 , L_32 , V_165 -> V_81 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_33 , V_166 -> V_138 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_34 , V_166 -> V_93 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_35 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_36 , V_166 -> V_102 -> V_93 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_37 , V_166 -> V_102 -> V_150 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_38 ) ;
for ( V_167 = 0 ; V_167 < V_166 -> V_102 -> V_150 ; V_167 ++ )
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_39 , V_166 -> V_102 -> V_151 [ V_167 ] ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_40 , V_166 -> V_102 -> V_152 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_41 ) ;
for ( V_167 = 0 ; V_167 < V_166 -> V_102 -> V_152 ; V_167 ++ )
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_39 , V_166 -> V_102 -> V_153 [ V_167 ] ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_42 , V_166 -> V_102 -> V_154 ) ;
F_2 ( V_164 , V_25 , V_168 , ( V_27 | V_169 ) , L_43 , V_166 -> V_102 -> V_155 ) ;
F_2 ( V_164 , V_25 , V_168 , V_27 , L_44 ) ;
}
static void F_38 ( struct V_1 * V_164 ,
struct V_71 * V_165 )
{
int V_126 , V_170 ;
struct V_96 V_166 ;
for ( V_126 = 0 ; V_126 < V_99 ; V_126 ++ ) {
for ( V_170 = 0 ; V_170 < 2 ; V_170 ++ ) {
if ( V_170 == 0 ) {
V_166 = V_165 -> V_74 -> V_100 [ V_126 ] ;
if ( V_166 . V_101 )
F_2 ( V_164 ,
V_25 ,
V_168 ,
( V_27 | V_169 ) ,
L_45 ) ;
} else {
V_166 = V_165 -> V_74 -> V_111 [ V_126 ] ;
if ( V_166 . V_101 )
F_2 ( V_164 ,
V_25 ,
V_168 ,
( V_27 | V_169 ) ,
L_46 ) ;
}
if ( V_166 . V_101 ) {
F_37 ( V_164 ,
V_165 ,
& V_166 ) ;
}
}
}
}
void F_39 ( struct V_60 * V_89 )
{
int V_62 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
F_2 ( V_2 , V_25 , V_168 , V_27 ,
L_47 ) ;
for ( V_62 = 0 ; V_62 < V_70 ; V_62 ++ ) {
struct V_71 V_171 =
V_89 -> V_66 -> V_73 [ V_62 ] ;
if ( ! V_171 . V_101 )
continue;
F_38 ( V_2 , & V_171 ) ;
}
}
static int F_33 ( unsigned char * V_172 ,
unsigned char * V_173 ,
struct V_83 * V_174 ,
T_3 * V_175 )
{
int V_176 , V_177 = 0 ;
struct V_83 * V_178 ;
int V_179 , V_62 = 0 ;
unsigned char * V_180 , * V_181 ;
int V_182 = * V_175 - 1 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
V_172 ++ ;
F_2 ( V_2 , V_25 , V_51 , V_27 ,
L_19 ) ;
* V_175 = 0 ;
if ( V_174 == NULL )
return 0 ;
V_178 = V_174 ;
V_176 = V_178 -> V_154 ;
V_180 = V_178 -> V_151 ;
V_181 = V_178 -> V_153 ;
if ( V_176 > V_32 )
V_176 = V_32 ;
while ( ( V_176 > 0 ) && ( V_177 < V_182 ) ) {
V_179 = ( ( * V_181 << V_62 ) & V_183 ) ;
if ( V_179 == V_183 ) {
* V_173 = * V_180 ;
F_2 ( V_2 , V_25 , V_51 ,
V_27 ,
L_48 ,
V_176 , * V_180 , * V_173 ) ;
} else {
* V_173 = * V_172 ;
F_2 ( V_2 , V_25 , V_51 ,
V_27 ,
L_49 ,
V_176 , * V_172 , * V_173 ) ;
V_172 ++ ;
V_177 ++ ;
}
V_173 ++ ;
V_180 ++ ;
V_176 -- ;
V_62 ++ ;
* V_175 = * V_175 + 1 ;
if ( V_62 > V_184 ) {
V_62 = 0 ;
V_181 ++ ;
}
}
return V_177 ;
}
static int F_31 ( struct V_83 * V_185 ,
unsigned char * V_172 ,
unsigned char * V_173 ,
T_3 * V_175 ,
T_3 * V_186 )
{
unsigned char * V_187 = V_173 ;
int V_188 = 0 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
if ( V_185 == NULL ) {
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_50 ) ;
* V_173 = V_189 ;
return V_37 ;
}
if ( V_185 -> V_154 <= * V_186 )
* V_175 = V_185 -> V_154 ;
else
* V_175 = * V_186 ;
V_173 ++ ;
V_188 = F_40 ( V_172 , V_173 , V_185 -> V_151 ,
V_185 -> V_153 , V_185 -> V_154 ,
V_185 -> V_155 , V_186 ) ;
if ( V_188 == V_36 ) {
* V_187 = ( unsigned char ) V_185 -> V_93 ;
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_51 ,
V_185 -> V_93 ) ;
} else {
* V_187 = V_189 ;
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_52 ) ;
}
return V_188 ;
}
static int F_40 ( unsigned char * V_190 ,
unsigned char * V_191 ,
unsigned char * V_180 ,
unsigned char * V_181 ,
unsigned int V_176 ,
unsigned int V_192 ,
T_3 * V_186 )
{
unsigned int V_177 = 0 ;
int V_179 , V_62 = 0 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_53 , * V_181 ) ;
if ( V_176 > ( * V_186 ) )
V_176 = * V_186 ;
while ( V_176 > 0 ) {
V_179 = ( ( * V_181 << V_62 ) & V_183 ) ;
if ( V_179 == V_183 ) {
if ( * V_190 != * V_180 ) {
if ( V_192 == V_193 ) {
F_2 ( V_2 ,
V_25 ,
V_26 ,
V_27 ,
L_54 ,
V_176 ,
* V_190 ,
* V_180 ) ;
return V_37 ;
}
} else
F_2 ( V_2 ,
V_25 ,
V_26 ,
V_27 ,
L_55 ,
V_176 ,
* V_190 ,
* V_180 ) ;
} else {
* V_191 = * V_190 ;
F_2 ( V_2 ,
V_25 ,
V_26 ,
V_27 ,
L_56 ,
* V_190 ,
* V_191 ) ;
V_191 ++ ;
V_177 ++ ;
}
V_190 ++ ;
V_180 ++ ;
V_176 -- ;
V_62 ++ ;
if ( V_62 > V_184 ) {
V_62 = 0 ;
V_181 ++ ;
}
}
F_2 ( V_2 , V_25 , V_26 , V_27 ,
L_57 ) ;
* V_186 = V_177 ;
return V_36 ;
}
