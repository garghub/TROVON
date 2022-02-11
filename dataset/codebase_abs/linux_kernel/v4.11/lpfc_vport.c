inline void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_5 ) {
if ( V_4 != V_6 )
V_5 -> V_7 = V_5 -> V_8 ;
V_5 -> V_8 = V_4 ;
}
switch ( V_4 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
V_2 -> V_14 = V_15 ;
break;
case V_16 :
V_2 -> V_14 = V_17 ;
break;
default:
break;
}
}
int
F_2 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
F_3 ( & V_19 -> V_21 ) ;
V_20 = F_4 ( V_19 -> V_22 , ( V_19 -> V_23 + 1 ) , 1 ) ;
if ( V_20 > V_19 -> V_23 )
V_20 = 0 ;
else
F_5 ( V_20 , V_19 -> V_22 ) ;
if ( V_19 -> V_24 == V_25 )
V_19 -> V_26 . V_27 . V_28 ++ ;
F_6 ( & V_19 -> V_21 ) ;
return V_20 ;
}
static void
F_7 ( struct V_18 * V_19 , int V_20 )
{
if ( V_20 == 0 )
return;
F_3 ( & V_19 -> V_21 ) ;
F_8 ( V_20 , V_19 -> V_22 ) ;
if ( V_19 -> V_24 == V_25 )
V_19 -> V_26 . V_27 . V_28 -- ;
F_6 ( & V_19 -> V_21 ) ;
}
static int
F_9 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
T_1 * V_29 ;
T_2 * V_30 ;
struct V_31 * V_32 ;
int V_33 ;
V_29 = F_10 ( V_19 -> V_34 , V_35 ) ;
if ( ! V_29 ) {
return - V_36 ;
}
V_30 = & V_29 -> V_37 . V_30 ;
V_33 = F_11 ( V_19 , V_29 , V_2 -> V_20 ) ;
if ( V_33 ) {
F_12 ( V_29 , V_19 -> V_34 ) ;
return - V_36 ;
}
V_32 = (struct V_31 * ) V_29 -> V_38 ;
V_29 -> V_38 = NULL ;
V_29 -> V_2 = V_2 ;
V_33 = F_13 ( V_19 , V_29 , V_19 -> V_39 * 2 ) ;
if ( V_33 != V_40 ) {
if ( F_14 ( V_41 ) ) {
F_15 ( V_2 , V_42 , V_43 | V_44 ,
L_1 ,
V_30 -> V_45 ) ;
F_16 ( V_19 , V_32 -> V_46 , V_32 -> V_47 ) ;
F_17 ( V_32 ) ;
if ( V_33 != V_48 )
F_12 ( V_29 , V_19 -> V_34 ) ;
return - V_49 ;
} else {
F_15 ( V_2 , V_42 , V_43 | V_44 ,
L_2
L_3 ,
V_30 -> V_45 , V_30 -> V_50 , V_33 ) ;
F_16 ( V_19 , V_32 -> V_46 , V_32 -> V_47 ) ;
F_17 ( V_32 ) ;
if ( V_33 != V_48 )
F_12 ( V_29 , V_19 -> V_34 ) ;
return - V_51 ;
}
}
memcpy ( & V_2 -> V_52 , V_32 -> V_46 , sizeof ( struct V_53 ) ) ;
memcpy ( & V_2 -> V_54 , & V_2 -> V_52 . V_55 ,
sizeof ( struct V_56 ) ) ;
memcpy ( & V_2 -> V_57 , & V_2 -> V_52 . V_58 ,
sizeof ( struct V_56 ) ) ;
F_16 ( V_19 , V_32 -> V_46 , V_32 -> V_47 ) ;
F_17 ( V_32 ) ;
F_12 ( V_29 , V_19 -> V_34 ) ;
return 0 ;
}
static int
F_18 ( struct V_18 * V_19 , struct V_56 * V_59 ,
const char * V_60 )
{
if ( ! ( ( V_59 -> V_37 . V_59 [ 0 ] >> 4 ) == 1 &&
( ( V_59 -> V_37 . V_59 [ 0 ] & 0xf ) != 0 || ( V_59 -> V_37 . V_59 [ 1 ] & 0xf ) != 0 ) ) )
return 1 ;
F_19 ( V_19 , V_42 , V_44 ,
L_4
L_5 ,
V_60 ,
V_59 -> V_37 . V_59 [ 0 ] , V_59 -> V_37 . V_59 [ 1 ] ,
V_59 -> V_37 . V_59 [ 2 ] , V_59 -> V_37 . V_59 [ 3 ] ,
V_59 -> V_37 . V_59 [ 4 ] , V_59 -> V_37 . V_59 [ 5 ] ,
V_59 -> V_37 . V_59 [ 6 ] , V_59 -> V_37 . V_59 [ 7 ] ) ;
return 0 ;
}
static int
F_20 ( struct V_18 * V_19 , struct V_1 * V_61 )
{
struct V_1 * V_2 ;
unsigned long V_62 ;
F_21 ( & V_19 -> V_21 , V_62 ) ;
F_22 (vport, &phba->port_list, listentry) {
if ( V_2 == V_61 )
continue;
if ( memcmp ( & V_2 -> V_52 . V_58 ,
& V_61 -> V_52 . V_58 ,
sizeof( struct V_56 ) ) == 0 ) {
F_23 ( & V_19 -> V_21 , V_62 ) ;
return 0 ;
}
}
F_23 ( & V_19 -> V_21 , V_62 ) ;
return 1 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_3 V_63 = 0 ;
unsigned long V_64 ;
unsigned long V_65 ;
V_63 = V_66 | V_67 | V_68 |
V_69 | V_70 | V_71 ;
V_64 = F_25 ( ( ( V_19 -> V_39 * 3 ) + 3 ) * 1000 ) ;
V_64 += V_72 ;
V_65 = V_72 ;
while ( F_26 ( V_72 , V_64 ) ) {
if ( ( V_2 -> V_73 > 0 ) ||
( V_2 -> V_74 & V_63 ) ||
( ( V_2 -> V_14 > V_15 ) &&
( V_2 -> V_14 < V_75 ) ) ) {
F_15 ( V_2 , V_76 , V_44 ,
L_6
L_7
L_8
L_9 ,
V_2 -> V_14 , V_2 -> V_74 ,
V_2 -> V_73 ,
F_27 ( V_72 - V_65 ) ) ;
F_28 ( 1000 ) ;
} else {
F_15 ( V_2 , V_76 , V_44 ,
L_10
L_7
L_11 ,
V_2 -> V_14 , V_2 -> V_74 ,
F_27 ( V_72
- V_65 ) ) ;
break;
}
}
if ( F_29 ( V_72 , V_64 ) )
F_15 ( V_2 , V_42 , V_44 ,
L_12
L_13 ,
V_2 -> V_14 , V_2 -> V_74 ,
F_27 ( V_72 - V_65 ) ) ;
}
int
F_30 ( struct V_5 * V_5 , bool V_77 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 = V_5 -> V_81 ;
struct V_1 * V_82 = (struct V_1 * ) V_81 -> V_83 ;
struct V_18 * V_19 = V_82 -> V_19 ;
struct V_1 * V_2 = NULL ;
int V_84 ;
int V_20 ;
int V_33 = V_85 ;
int V_86 ;
if ( ( V_19 -> V_24 < 3 ) || ! ( V_19 -> V_87 ) ) {
F_19 ( V_19 , V_42 , V_44 ,
L_14
L_15 ,
V_19 -> V_24 ) ;
V_33 = V_88 ;
goto V_89;
}
V_20 = F_2 ( V_19 ) ;
if ( V_20 == 0 ) {
F_19 ( V_19 , V_42 , V_44 ,
L_16
L_17 ,
V_19 -> V_23 ) ;
V_33 = V_90 ;
goto V_89;
}
if ( ( V_84 = F_31 () ) < 0 ) {
F_19 ( V_19 , V_42 , V_44 ,
L_18
L_19 ) ;
F_7 ( V_19 , V_20 ) ;
V_33 = V_90 ;
goto V_89;
}
V_2 = F_32 ( V_19 , V_84 , & V_5 -> V_91 ) ;
if ( ! V_2 ) {
F_19 ( V_19 , V_42 , V_44 ,
L_20 , V_20 ) ;
F_7 ( V_19 , V_20 ) ;
V_33 = V_90 ;
goto V_89;
}
V_2 -> V_20 = V_20 ;
F_33 ( V_2 ) ;
if ( ( V_86 = F_9 ( V_19 , V_2 ) ) ) {
if ( V_86 == - V_49 ) {
F_15 ( V_2 , V_42 , V_44 ,
L_21 ) ;
V_33 = V_85 ;
} else {
F_15 ( V_2 , V_42 , V_44 ,
L_22
L_23 ) ;
V_33 = V_90 ;
}
F_7 ( V_19 , V_20 ) ;
F_34 ( V_2 ) ;
goto V_89;
}
F_35 ( V_5 -> V_92 , V_2 -> V_54 . V_37 . V_59 ) ;
F_35 ( V_5 -> V_93 , V_2 -> V_57 . V_37 . V_59 ) ;
memcpy ( & V_2 -> V_52 . V_58 , V_2 -> V_57 . V_37 . V_59 , 8 ) ;
memcpy ( & V_2 -> V_52 . V_55 , V_2 -> V_54 . V_37 . V_59 , 8 ) ;
if ( ! F_18 ( V_19 , & V_2 -> V_52 . V_55 , L_24 ) ||
! F_18 ( V_19 , & V_2 -> V_52 . V_58 , L_25 ) ) {
F_15 ( V_2 , V_42 , V_44 ,
L_26
L_27 ) ;
F_7 ( V_19 , V_20 ) ;
F_34 ( V_2 ) ;
V_33 = V_88 ;
goto V_89;
}
if ( ! F_20 ( V_19 , V_2 ) ) {
F_15 ( V_2 , V_42 , V_44 ,
L_28
L_29 ) ;
F_7 ( V_19 , V_20 ) ;
F_34 ( V_2 ) ;
V_33 = V_88 ;
goto V_89;
}
F_36 ( V_2 ) ;
V_2 -> V_94 = V_19 -> V_82 -> V_94 ;
* (struct V_1 * * ) V_5 -> V_95 = V_2 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_96 |= V_97 ;
if ( V_19 -> V_98 ||
( V_19 -> V_99 == V_100 ) ) {
V_2 -> V_101 = V_19 -> V_82 -> V_101 ;
V_2 -> V_102 = V_19 -> V_82 -> V_102 ;
}
if ( ( V_19 -> V_103 == 0 ) &&
( ( V_19 -> V_104 == V_105 ) ||
( V_19 -> V_104 == V_106 ) ) ) {
V_33 = F_37 ( V_2 ) ;
if ( V_33 ) {
F_19 ( V_19 , V_42 , V_43 ,
L_30 ,
L_31 ,
V_33 ) ;
goto V_89;
}
}
if ( ( V_19 -> V_24 == V_25 ) &&
( V_82 -> V_74 & V_107 ) ) {
V_33 = F_38 ( V_2 ) ;
if ( V_33 ) {
F_19 ( V_19 , V_42 , V_44 ,
L_32
L_33 , V_20 , V_33 ) ;
V_33 = V_90 ;
F_7 ( V_19 , V_20 ) ;
goto V_89;
}
} else if ( V_19 -> V_24 == V_25 ) {
V_2 -> V_74 |= V_108 ;
F_1 ( V_2 , V_16 ) ;
V_33 = V_109 ;
goto V_110;
}
if ( ( V_19 -> V_111 < V_112 ) ||
( V_82 -> V_14 < V_113 ) ||
( V_19 -> V_114 == V_115 ) ) {
F_1 ( V_2 , V_16 ) ;
V_33 = V_109 ;
goto V_110;
}
if ( V_77 ) {
F_1 ( V_2 , V_116 ) ;
V_33 = V_109 ;
goto V_110;
}
V_79 = F_39 ( V_19 -> V_82 , V_117 ) ;
if ( V_79 && F_40 ( V_79 ) &&
V_79 -> V_118 == V_119 ) {
if ( V_19 -> V_120 & V_121 ) {
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
} else {
F_1 ( V_2 , V_9 ) ;
F_15 ( V_2 , V_42 , V_122 ,
L_34 ) ;
}
} else {
F_1 ( V_2 , V_13 ) ;
}
V_33 = V_109 ;
V_110:
F_15 ( V_2 , V_42 , V_44 ,
L_35 ) ;
F_43 ( F_44 ( V_2 ) ) ;
V_89:
return V_33 ;
}
static int
F_45 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = * (struct V_1 * * ) V_5 -> V_95 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_78 * V_79 = NULL , * V_123 = NULL ;
long V_124 ;
struct V_80 * V_81 = F_44 ( V_2 ) ;
V_79 = F_39 ( V_2 , V_117 ) ;
if ( V_79 && F_40 ( V_79 )
&& V_19 -> V_111 >= V_112 ) {
V_2 -> V_125 = V_88 ;
V_124 = F_25 ( V_19 -> V_39 * 2000 ) ;
if ( ! F_46 ( V_2 , V_79 ) )
while ( V_2 -> V_125 == V_88 && V_124 )
V_124 = F_47 ( V_124 ) ;
}
F_48 ( V_2 ) ;
F_49 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_40 ( V_79 ) )
continue;
if ( V_79 -> V_118 == V_126 )
continue;
F_50 ( V_2 , V_79 , NULL ,
V_127 ) ;
}
F_51 ( V_2 , 1 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_3 ( V_81 -> V_128 ) ;
V_2 -> V_74 |= V_108 ;
F_6 ( V_81 -> V_128 ) ;
F_1 ( V_2 , V_116 ) ;
F_15 ( V_2 , V_42 , V_44 ,
L_36 ) ;
return V_109 ;
}
static int
F_56 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = * (struct V_1 * * ) V_5 -> V_95 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_78 * V_79 = NULL ;
struct V_80 * V_81 = F_44 ( V_2 ) ;
if ( ( V_19 -> V_111 < V_112 ) ||
( V_19 -> V_114 == V_115 ) ) {
F_1 ( V_2 , V_16 ) ;
return V_109 ;
}
F_3 ( V_81 -> V_128 ) ;
V_2 -> V_96 |= V_129 ;
if ( V_2 -> V_74 & V_108 ) {
F_6 ( V_81 -> V_128 ) ;
F_57 ( V_2 ) ;
goto V_110;
}
V_2 -> V_74 |= V_130 ;
F_6 ( V_81 -> V_128 ) ;
V_79 = F_39 ( V_19 -> V_82 , V_117 ) ;
if ( V_79 && F_40 ( V_79 )
&& V_79 -> V_118 == V_119 ) {
if ( V_19 -> V_120 & V_121 ) {
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
} else {
F_1 ( V_2 , V_9 ) ;
F_15 ( V_2 , V_42 , V_122 ,
L_37 ) ;
}
} else {
F_1 ( V_2 , V_13 ) ;
}
V_110:
F_15 ( V_2 , V_42 , V_44 ,
L_38 ) ;
return V_109 ;
}
int
F_58 ( struct V_5 * V_5 , bool V_77 )
{
if ( V_77 )
return F_45 ( V_5 ) ;
else
return F_56 ( V_5 ) ;
}
int
F_59 ( struct V_5 * V_5 )
{
struct V_78 * V_79 = NULL ;
struct V_1 * V_2 = * (struct V_1 * * ) V_5 -> V_95 ;
struct V_80 * V_81 = F_44 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
long V_124 ;
bool V_131 = false ;
if ( V_2 -> V_132 == V_133 ) {
F_15 ( V_2 , V_42 , V_44 ,
L_39
L_40 ) ;
return V_85 ;
}
if ( ( V_2 -> V_134 & V_135 ) &&
! ( V_19 -> V_82 -> V_96 & V_136 ) ) {
F_15 ( V_2 , V_42 , V_44 ,
L_41
L_42 ) ;
return V_85 ;
}
F_3 ( & V_19 -> V_21 ) ;
V_2 -> V_96 |= V_136 ;
F_6 ( & V_19 -> V_21 ) ;
if ( ! ( V_19 -> V_82 -> V_96 & V_136 ) ) {
int V_137 = 0 ;
while ( V_137 < ( ( V_19 -> V_39 * 3 ) + 3 ) &&
V_2 -> V_14 > V_15 &&
V_2 -> V_14 < V_75 ) {
V_137 ++ ;
F_28 ( 1000 ) ;
}
if ( V_2 -> V_14 > V_15 &&
V_2 -> V_14 < V_75 )
return - V_138 ;
}
if ( ! F_60 ( V_81 ) )
return V_88 ;
if ( ! F_60 ( V_81 ) ) {
F_61 ( V_81 ) ;
return V_88 ;
}
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
V_79 = F_39 ( V_2 , V_139 ) ;
if ( V_79 && F_40 ( V_79 ) ) {
F_64 ( V_79 ) ;
V_131 = true ;
}
F_65 ( V_81 ) ;
F_66 ( V_81 ) ;
V_79 = F_39 ( V_19 -> V_82 , V_117 ) ;
if ( V_19 -> V_82 -> V_96 & V_136 ) {
if ( V_79 && F_40 ( V_79 ) &&
V_79 -> V_118 == V_119 &&
V_19 -> V_111 >= V_112 ) {
V_79 = F_39 ( V_2 , V_117 ) ;
if ( ! V_79 )
goto V_140;
else if ( ! F_40 ( V_79 ) ) {
V_79 = F_67 ( V_2 , V_79 ,
V_126 ) ;
if ( ! V_79 )
goto V_140;
}
F_68 ( V_2 , V_79 ) ;
F_3 ( & V_19 -> V_141 ) ;
F_69 ( V_79 ) ;
F_6 ( & V_19 -> V_141 ) ;
F_70 ( V_79 ) ;
}
goto V_140;
}
if ( V_79 && F_40 ( V_79 ) &&
V_79 -> V_118 == V_119 &&
V_19 -> V_111 >= V_112 &&
V_19 -> V_114 != V_115 ) {
if ( V_2 -> V_142 ) {
V_124 = F_25 ( V_19 -> V_39 * 2000 ) ;
if ( ! F_71 ( V_2 , V_143 , 0 , 0 ) )
while ( V_2 -> V_144 && V_124 )
V_124 = F_47 ( V_124 ) ;
else
F_19 ( V_2 -> V_19 , V_145 ,
V_44 ,
L_43
L_44 ) ;
}
V_79 = F_39 ( V_2 , V_117 ) ;
if ( ! V_79 ) {
V_79 = F_10 ( V_19 -> V_146 , V_35 ) ;
if ( ! V_79 )
goto V_140;
F_72 ( V_2 , V_79 , V_117 ) ;
F_69 ( V_79 ) ;
} else {
if ( ! F_40 ( V_79 ) ) {
V_79 = F_67 ( V_2 , V_79 ,
V_126 ) ;
if ( ! V_79 )
goto V_140;
}
F_68 ( V_2 , V_79 ) ;
F_3 ( & V_19 -> V_141 ) ;
if ( ! F_73 ( V_79 ) )
F_69 ( V_79 ) ;
else {
F_6 ( & V_19 -> V_141 ) ;
goto V_140;
}
F_6 ( & V_19 -> V_141 ) ;
}
if ( ! ( V_2 -> V_147 & V_148 ) ) {
F_70 ( V_79 ) ;
goto V_140;
}
V_2 -> V_125 = V_88 ;
V_124 = F_25 ( V_19 -> V_39 * 2000 ) ;
if ( ! F_46 ( V_2 , V_79 ) )
while ( V_2 -> V_125 == V_88 && V_124 )
V_124 = F_47 ( V_124 ) ;
}
if ( ! ( V_19 -> V_82 -> V_96 & V_136 ) )
F_24 ( V_2 ) ;
V_140:
if ( V_131 ) {
V_79 = F_39 ( V_2 , V_139 ) ;
F_70 ( V_79 ) ;
}
F_74 ( V_2 ) ;
F_48 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( ! ( V_19 -> V_82 -> V_96 & V_136 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( ! ( V_2 -> V_147 & V_148 ) ||
F_55 ( V_2 ) )
F_61 ( V_81 ) ;
} else
F_61 ( V_81 ) ;
F_7 ( V_19 , V_2 -> V_20 ) ;
V_2 -> V_149 = 0 ;
F_3 ( & V_19 -> V_21 ) ;
F_75 ( & V_2 -> V_150 ) ;
F_6 ( & V_19 -> V_21 ) ;
F_15 ( V_2 , V_42 , V_44 ,
L_45 ) ;
F_61 ( V_81 ) ;
return V_109 ;
}
struct V_1 * *
F_76 ( struct V_18 * V_19 )
{
struct V_1 * V_151 ;
struct V_1 * * V_152 ;
int V_153 = 0 ;
V_152 = F_77 ( ( V_19 -> V_154 + 1 ) * sizeof( struct V_1 * ) ,
V_35 ) ;
if ( V_152 == NULL )
return NULL ;
F_3 ( & V_19 -> V_21 ) ;
F_22 (port_iterator, &phba->port_list, listentry) {
if ( V_151 -> V_96 & V_136 )
continue;
if ( ! F_60 ( F_44 ( V_151 ) ) ) {
F_15 ( V_151 , V_42 , V_44 ,
L_46
L_47 ) ;
continue;
}
V_152 [ V_153 ++ ] = V_151 ;
}
F_6 ( & V_19 -> V_21 ) ;
return V_152 ;
}
void
F_78 ( struct V_18 * V_19 , struct V_1 * * V_152 )
{
int V_155 ;
if ( V_152 == NULL )
return;
for ( V_155 = 0 ; V_155 <= V_19 -> V_154 && V_152 [ V_155 ] != NULL ; V_155 ++ )
F_61 ( F_44 ( V_152 [ V_155 ] ) ) ;
F_17 ( V_152 ) ;
}
void
F_79 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_123 = NULL ;
F_49 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_40 ( V_79 ) )
continue;
if ( V_79 -> V_156 )
memset ( V_79 -> V_156 , 0 , V_157 *
sizeof( struct V_158 ) ) ;
}
}
void
F_80 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_123 = NULL ;
F_49 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_40 ( V_79 ) )
continue;
F_17 ( V_79 -> V_156 ) ;
V_79 -> V_156 = NULL ;
if ( V_79 -> V_118 == V_159 ) {
V_79 -> V_156 = F_81 ( V_157 ,
sizeof( struct V_158 ) ,
V_160 ) ;
if ( ! V_79 -> V_156 )
F_15 ( V_2 , V_42 , V_161 ,
L_48
L_49
L_50 , V_79 -> V_162 ) ;
}
}
}
void
F_82 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_123 = NULL ;
F_49 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_40 ( V_79 ) )
continue;
F_17 ( V_79 -> V_156 ) ;
V_79 -> V_156 = NULL ;
}
}
