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
if ( ( V_19 -> V_24 == V_25 ) &&
( V_82 -> V_74 & V_103 ) ) {
V_33 = F_37 ( V_2 ) ;
if ( V_33 ) {
F_19 ( V_19 , V_42 , V_44 ,
L_30
L_31 , V_20 , V_33 ) ;
V_33 = V_90 ;
F_7 ( V_19 , V_20 ) ;
goto V_89;
}
} else if ( V_19 -> V_24 == V_25 ) {
V_2 -> V_74 |= V_104 ;
F_1 ( V_2 , V_16 ) ;
V_33 = V_105 ;
goto V_106;
}
if ( ( V_19 -> V_107 < V_108 ) ||
( V_82 -> V_14 < V_109 ) ||
( V_19 -> V_110 == V_111 ) ) {
F_1 ( V_2 , V_16 ) ;
V_33 = V_105 ;
goto V_106;
}
if ( V_77 ) {
F_1 ( V_2 , V_112 ) ;
V_33 = V_105 ;
goto V_106;
}
V_79 = F_38 ( V_19 -> V_82 , V_113 ) ;
if ( V_79 && F_39 ( V_79 ) &&
V_79 -> V_114 == V_115 ) {
if ( V_19 -> V_116 & V_117 ) {
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
} else {
F_1 ( V_2 , V_9 ) ;
F_15 ( V_2 , V_42 , V_118 ,
L_32 ) ;
}
} else {
F_1 ( V_2 , V_13 ) ;
}
V_33 = V_105 ;
V_106:
F_15 ( V_2 , V_42 , V_44 ,
L_33 ) ;
F_42 ( F_43 ( V_2 ) ) ;
V_89:
return V_33 ;
}
static int
F_44 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = * (struct V_1 * * ) V_5 -> V_95 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_78 * V_79 = NULL , * V_119 = NULL ;
long V_120 ;
struct V_80 * V_81 = F_43 ( V_2 ) ;
V_79 = F_38 ( V_2 , V_113 ) ;
if ( V_79 && F_39 ( V_79 )
&& V_19 -> V_107 >= V_108 ) {
V_2 -> V_121 = V_88 ;
V_120 = F_25 ( V_19 -> V_39 * 2000 ) ;
if ( ! F_45 ( V_2 , V_79 ) )
while ( V_2 -> V_121 == V_88 && V_120 )
V_120 = F_46 ( V_120 ) ;
}
F_47 ( V_2 ) ;
F_48 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_39 ( V_79 ) )
continue;
if ( V_79 -> V_114 == V_122 )
continue;
F_49 ( V_2 , V_79 , NULL ,
V_123 ) ;
}
F_50 ( V_2 , 1 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_3 ( V_81 -> V_124 ) ;
V_2 -> V_74 |= V_104 ;
F_6 ( V_81 -> V_124 ) ;
F_1 ( V_2 , V_112 ) ;
F_15 ( V_2 , V_42 , V_44 ,
L_34 ) ;
return V_105 ;
}
static int
F_55 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = * (struct V_1 * * ) V_5 -> V_95 ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_78 * V_79 = NULL ;
struct V_80 * V_81 = F_43 ( V_2 ) ;
if ( ( V_19 -> V_107 < V_108 ) ||
( V_19 -> V_110 == V_111 ) ) {
F_1 ( V_2 , V_16 ) ;
return V_105 ;
}
F_3 ( V_81 -> V_124 ) ;
V_2 -> V_96 |= V_125 ;
V_2 -> V_74 |= V_126 ;
F_6 ( V_81 -> V_124 ) ;
V_79 = F_38 ( V_19 -> V_82 , V_113 ) ;
if ( V_79 && F_39 ( V_79 )
&& V_79 -> V_114 == V_115 ) {
if ( V_19 -> V_116 & V_117 ) {
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
} else {
F_1 ( V_2 , V_9 ) ;
F_15 ( V_2 , V_42 , V_118 ,
L_35 ) ;
}
} else {
F_1 ( V_2 , V_13 ) ;
}
F_15 ( V_2 , V_42 , V_44 ,
L_36 ) ;
return V_105 ;
}
int
F_56 ( struct V_5 * V_5 , bool V_77 )
{
if ( V_77 )
return F_44 ( V_5 ) ;
else
return F_55 ( V_5 ) ;
}
int
F_57 ( struct V_5 * V_5 )
{
struct V_78 * V_79 = NULL ;
struct V_1 * V_2 = * (struct V_1 * * ) V_5 -> V_95 ;
struct V_80 * V_81 = F_43 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
long V_120 ;
bool V_127 = false ;
if ( V_2 -> V_128 == V_129 ) {
F_15 ( V_2 , V_42 , V_44 ,
L_37
L_38 ) ;
return V_85 ;
}
if ( ( V_2 -> V_130 & V_131 ) &&
! ( V_19 -> V_82 -> V_96 & V_132 ) ) {
F_15 ( V_2 , V_42 , V_44 ,
L_39
L_40 ) ;
return V_85 ;
}
F_3 ( & V_19 -> V_21 ) ;
V_2 -> V_96 |= V_132 ;
F_6 ( & V_19 -> V_21 ) ;
if ( ! ( V_19 -> V_82 -> V_96 & V_132 ) ) {
int V_133 = 0 ;
while ( V_133 < ( ( V_19 -> V_39 * 3 ) + 3 ) &&
V_2 -> V_14 > V_15 &&
V_2 -> V_14 < V_75 ) {
V_133 ++ ;
F_28 ( 1000 ) ;
}
if ( V_2 -> V_14 > V_15 &&
V_2 -> V_14 < V_75 )
return - V_134 ;
}
if ( ! F_58 ( V_81 ) )
return V_88 ;
if ( ! F_58 ( V_81 ) ) {
F_59 ( V_81 ) ;
return V_88 ;
}
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
V_79 = F_38 ( V_2 , V_135 ) ;
if ( V_79 && F_39 ( V_79 ) ) {
F_62 ( V_79 ) ;
V_127 = true ;
}
F_63 ( V_81 ) ;
F_64 ( V_81 ) ;
V_79 = F_38 ( V_19 -> V_82 , V_113 ) ;
if ( V_19 -> V_82 -> V_96 & V_132 ) {
if ( V_79 && F_39 ( V_79 ) &&
V_79 -> V_114 == V_115 &&
V_19 -> V_107 >= V_108 ) {
V_79 = F_38 ( V_2 , V_113 ) ;
if ( ! V_79 )
goto V_136;
else if ( ! F_39 ( V_79 ) ) {
V_79 = F_65 ( V_2 , V_79 ,
V_122 ) ;
if ( ! V_79 )
goto V_136;
}
F_66 ( V_2 , V_79 ) ;
F_3 ( & V_19 -> V_137 ) ;
F_67 ( V_79 ) ;
F_6 ( & V_19 -> V_137 ) ;
F_68 ( V_79 ) ;
}
goto V_136;
}
if ( V_79 && F_39 ( V_79 ) &&
V_79 -> V_114 == V_115 &&
V_19 -> V_107 >= V_108 &&
V_19 -> V_110 != V_111 ) {
if ( V_2 -> V_138 ) {
V_120 = F_25 ( V_19 -> V_39 * 2000 ) ;
if ( ! F_69 ( V_2 , V_139 , 0 , 0 ) )
while ( V_2 -> V_140 && V_120 )
V_120 = F_46 ( V_120 ) ;
else
F_19 ( V_2 -> V_19 , V_141 ,
V_44 ,
L_41
L_42 ) ;
}
V_79 = F_38 ( V_2 , V_113 ) ;
if ( ! V_79 ) {
V_79 = F_10 ( V_19 -> V_142 , V_35 ) ;
if ( ! V_79 )
goto V_136;
F_70 ( V_2 , V_79 , V_113 ) ;
F_67 ( V_79 ) ;
} else {
if ( ! F_39 ( V_79 ) ) {
V_79 = F_65 ( V_2 , V_79 ,
V_122 ) ;
if ( ! V_79 )
goto V_136;
}
F_66 ( V_2 , V_79 ) ;
F_3 ( & V_19 -> V_137 ) ;
if ( ! F_71 ( V_79 ) )
F_67 ( V_79 ) ;
else {
F_6 ( & V_19 -> V_137 ) ;
goto V_136;
}
F_6 ( & V_19 -> V_137 ) ;
}
if ( ! ( V_2 -> V_143 & V_144 ) ) {
F_68 ( V_79 ) ;
goto V_136;
}
V_2 -> V_121 = V_88 ;
V_120 = F_25 ( V_19 -> V_39 * 2000 ) ;
if ( ! F_45 ( V_2 , V_79 ) )
while ( V_2 -> V_121 == V_88 && V_120 )
V_120 = F_46 ( V_120 ) ;
}
if ( ! ( V_19 -> V_82 -> V_96 & V_132 ) )
F_24 ( V_2 ) ;
V_136:
if ( V_127 ) {
V_79 = F_38 ( V_2 , V_135 ) ;
F_68 ( V_79 ) ;
}
F_72 ( V_2 ) ;
F_47 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( ! ( V_19 -> V_82 -> V_96 & V_132 ) ) {
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( ! ( V_2 -> V_143 & V_144 ) ||
F_54 ( V_2 ) )
F_59 ( V_81 ) ;
} else
F_59 ( V_81 ) ;
F_7 ( V_19 , V_2 -> V_20 ) ;
V_2 -> V_145 = 0 ;
F_3 ( & V_19 -> V_21 ) ;
F_73 ( & V_2 -> V_146 ) ;
F_6 ( & V_19 -> V_21 ) ;
F_15 ( V_2 , V_42 , V_44 ,
L_43 ) ;
F_59 ( V_81 ) ;
return V_105 ;
}
struct V_1 * *
F_74 ( struct V_18 * V_19 )
{
struct V_1 * V_147 ;
struct V_1 * * V_148 ;
int V_149 = 0 ;
V_148 = F_75 ( ( V_19 -> V_150 + 1 ) * sizeof( struct V_1 * ) ,
V_35 ) ;
if ( V_148 == NULL )
return NULL ;
F_3 ( & V_19 -> V_21 ) ;
F_22 (port_iterator, &phba->port_list, listentry) {
if ( V_147 -> V_96 & V_132 )
continue;
if ( ! F_58 ( F_43 ( V_147 ) ) ) {
F_15 ( V_147 , V_42 , V_44 ,
L_44
L_45 ) ;
continue;
}
V_148 [ V_149 ++ ] = V_147 ;
}
F_6 ( & V_19 -> V_21 ) ;
return V_148 ;
}
void
F_76 ( struct V_18 * V_19 , struct V_1 * * V_148 )
{
int V_151 ;
if ( V_148 == NULL )
return;
for ( V_151 = 0 ; V_151 <= V_19 -> V_150 && V_148 [ V_151 ] != NULL ; V_151 ++ )
F_59 ( F_43 ( V_148 [ V_151 ] ) ) ;
F_17 ( V_148 ) ;
}
void
F_77 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_119 = NULL ;
F_48 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_39 ( V_79 ) )
continue;
if ( V_79 -> V_152 )
memset ( V_79 -> V_152 , 0 , V_153 *
sizeof( struct V_154 ) ) ;
}
}
void
F_78 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_119 = NULL ;
F_48 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_39 ( V_79 ) )
continue;
F_17 ( V_79 -> V_152 ) ;
V_79 -> V_152 = NULL ;
if ( V_79 -> V_114 == V_155 ) {
V_79 -> V_152 = F_79 ( V_153 ,
sizeof( struct V_154 ) ,
V_156 ) ;
if ( ! V_79 -> V_152 )
F_15 ( V_2 , V_42 , V_157 ,
L_46
L_47
L_48 , V_79 -> V_158 ) ;
}
}
}
void
F_80 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = NULL , * V_119 = NULL ;
F_48 (ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! F_39 ( V_79 ) )
continue;
F_17 ( V_79 -> V_152 ) ;
V_79 -> V_152 = NULL ;
}
}
