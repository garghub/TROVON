void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , V_4 ,
F_3 ( & V_4 -> V_5 ) , F_3 ( & V_4 -> V_5 ) + 1 ) ;
if ( F_4 ( & V_4 -> V_5 ) == 1 ) {
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_7 ( & V_2 -> V_6 ) ;
}
}
static void F_8 ( struct V_8 * V_9 ,
struct V_3 * V_10 )
{
struct V_11 * * V_12 = & V_9 -> V_11 ;
struct V_11 * V_13 = NULL ;
struct V_3 * V_14 = NULL ;
while ( * V_12 ) {
V_13 = * V_12 ;
V_14 = F_9 ( V_13 , struct V_3 , V_15 ) ;
if ( V_10 -> V_16 < V_14 -> V_16 )
V_12 = & ( * V_12 ) -> V_17 ;
else if ( V_10 -> V_16 > V_14 -> V_16 )
V_12 = & ( * V_12 ) -> V_18 ;
else
F_10 () ;
}
F_11 ( & V_10 -> V_15 , V_13 , V_12 ) ;
F_12 ( & V_10 -> V_15 , V_9 ) ;
}
static struct V_3 * F_13 (
struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return F_15 ( - V_20 ) ;
F_16 ( & V_4 -> V_5 , 1 ) ;
V_4 -> V_16 = V_16 ;
F_17 ( & V_4 -> V_21 ) ;
F_17 ( & V_4 -> V_22 ) ;
F_17 ( & V_4 -> V_7 ) ;
F_17 ( & V_4 -> V_23 ) ;
F_17 ( & V_4 -> V_24 ) ;
F_18 ( & V_4 -> V_25 ) ;
F_8 ( & V_2 -> V_26 , V_4 ) ;
F_2 ( L_2 , V_4 -> V_16 , V_4 ) ;
return V_4 ;
}
static struct V_3 * F_19 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_11 * V_27 = V_2 -> V_26 . V_11 ;
struct V_3 * V_14 ;
while ( V_27 ) {
V_14 = F_9 ( V_27 , struct V_3 , V_15 ) ;
if ( V_16 < V_14 -> V_16 )
V_27 = V_27 -> V_17 ;
else if ( V_16 > V_14 -> V_16 )
V_27 = V_27 -> V_18 ;
else {
F_2 ( L_3 , V_14 -> V_16 , V_14 ) ;
return V_14 ;
}
}
return NULL ;
}
struct V_3 * F_20 ( struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_3 * V_14 ;
V_14 = F_19 ( V_2 , V_16 ) ;
if ( V_14 )
F_1 ( V_2 , V_14 ) ;
return V_14 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_4 , V_4 , V_4 -> V_16 ) ;
F_22 ( & V_4 -> V_15 , & V_2 -> V_26 ) ;
if ( V_4 -> V_13 ) {
F_6 ( & V_4 -> V_22 ) ;
F_23 ( V_2 , V_4 -> V_13 ) ;
}
F_24 ( V_4 -> V_28 ) ;
F_24 ( V_4 -> V_29 ) ;
F_25 ( V_4 -> V_30 ) ;
F_24 ( V_4 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_5 , V_4 -> V_16 , V_4 ,
F_3 ( & V_4 -> V_5 ) , F_3 ( & V_4 -> V_5 ) - 1 ) ;
if ( F_26 ( & V_4 -> V_5 ) )
F_21 ( V_2 , V_4 ) ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_6 , V_4 -> V_16 , V_4 ,
F_3 ( & V_4 -> V_5 ) , F_3 ( & V_4 -> V_5 ) - 1 ) ;
if ( ! F_26 ( & V_4 -> V_5 ) )
return;
if ( F_28 ( & V_2 -> V_31 ) ) {
F_21 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_31 ) ;
} else {
F_5 ( & V_2 -> V_6 ) ;
F_30 ( & V_4 -> V_7 , & V_2 -> V_32 ) ;
F_7 ( & V_2 -> V_6 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_5 ( & V_2 -> V_6 ) ;
while ( ! F_32 ( & V_2 -> V_32 ) ) {
V_4 = F_33 ( & V_2 -> V_32 ,
struct V_3 , V_7 ) ;
F_34 ( & V_4 -> V_7 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_21 ( V_2 , V_4 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
F_7 ( & V_2 -> V_6 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_31 ) ;
F_31 ( V_2 ) ;
F_29 ( & V_2 -> V_31 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_33 )
{
struct V_3 * V_13 ;
if ( V_4 -> V_34 == V_33 )
return 0 ;
V_13 = F_20 ( V_2 , V_33 ) ;
if ( ! V_13 ) {
V_13 = F_13 ( V_2 , V_33 ) ;
if ( F_38 ( V_13 ) )
return F_39 ( V_13 ) ;
}
F_2 ( L_7 ,
V_4 -> V_16 , V_4 , V_4 -> V_34 , V_4 -> V_13 ,
V_33 , V_13 ) ;
if ( V_4 -> V_13 ) {
F_6 ( & V_4 -> V_22 ) ;
F_27 ( V_2 , V_4 -> V_13 ) ;
}
V_4 -> V_34 = V_33 ;
V_4 -> V_13 = V_13 ;
F_30 ( & V_4 -> V_22 , & V_13 -> V_21 ) ;
return 1 ;
}
static int F_40 ( const void * V_35 , const void * V_36 )
{
if ( * ( T_1 * ) V_35 < * ( T_1 * ) V_36 )
return 1 ;
if ( * ( T_1 * ) V_35 > * ( T_1 * ) V_36 )
return - 1 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_3 * V_13 = V_4 -> V_13 ;
struct V_37 * V_38 ;
int V_39 = 0 ;
T_2 V_40 = V_4 -> V_41 + V_4 -> V_42 ;
if ( V_13 ) {
if ( ! V_13 -> V_30 ) {
V_39 = F_41 ( V_13 ) ;
if ( V_39 )
goto V_43;
}
V_40 += V_13 -> V_30 -> V_42 ;
}
if ( V_4 -> V_30 &&
V_4 -> V_30 -> V_44 == V_4 -> V_44 &&
( ! V_13 ||
V_4 -> V_30 -> V_44 >= V_13 -> V_30 -> V_44 ) ) {
F_2 ( L_8
L_9 ,
V_4 -> V_16 , V_4 , V_4 -> V_30 ,
V_4 -> V_30 -> V_44 ,
( unsigned int ) V_4 -> V_30 -> V_42 ) ;
return 0 ;
}
V_39 = - V_20 ;
if ( V_40 > ( V_45 - sizeof( * V_38 ) ) / sizeof( T_1 ) )
goto V_43;
V_38 = F_42 ( V_40 , V_19 ) ;
if ( ! V_38 )
goto V_43;
V_40 = 0 ;
V_38 -> V_44 = V_4 -> V_44 ;
if ( V_13 ) {
T_2 V_46 ;
for ( V_46 = 0 ; V_46 < V_13 -> V_30 -> V_42 ; V_46 ++ )
if ( V_13 -> V_30 -> V_29 [ V_46 ] >=
V_4 -> V_47 )
V_38 -> V_29 [ V_40 ++ ] =
V_13 -> V_30 -> V_29 [ V_46 ] ;
if ( V_13 -> V_30 -> V_44 > V_38 -> V_44 )
V_38 -> V_44 = V_13 -> V_30 -> V_44 ;
}
memcpy ( V_38 -> V_29 + V_40 , V_4 -> V_29 ,
sizeof( T_1 ) * V_4 -> V_42 ) ;
V_40 += V_4 -> V_42 ;
memcpy ( V_38 -> V_29 + V_40 , V_4 -> V_28 ,
sizeof( T_1 ) * V_4 -> V_41 ) ;
V_40 += V_4 -> V_41 ;
F_43 ( V_38 -> V_29 , V_40 , sizeof( T_1 ) , F_40 , NULL ) ;
V_38 -> V_42 = V_40 ;
F_2 ( L_10 ,
V_4 -> V_16 , V_4 , V_38 , V_38 -> V_44 ,
( unsigned int ) V_38 -> V_42 ) ;
F_25 ( V_4 -> V_30 ) ;
V_4 -> V_30 = V_38 ;
return 0 ;
V_43:
if ( V_4 -> V_30 ) {
F_25 ( V_4 -> V_30 ) ;
V_4 -> V_30 = NULL ;
}
F_44 ( L_11 , V_4 -> V_16 ,
V_4 , V_39 ) ;
return V_39 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_3 * V_48 ;
F_2 ( L_12 , V_4 -> V_16 , V_4 ) ;
F_41 ( V_4 ) ;
F_46 (child, &realm->children, child_item)
F_45 ( V_48 ) ;
}
static int F_47 ( T_1 * * V_49 , T_3 * V_50 , T_2 V_40 )
{
T_2 V_46 ;
F_24 ( * V_49 ) ;
if ( V_40 ) {
* V_49 = F_48 ( V_40 , sizeof( T_1 ) , V_19 ) ;
if ( ! * V_49 )
return - V_20 ;
for ( V_46 = 0 ; V_46 < V_40 ; V_46 ++ )
( * V_49 ) [ V_46 ] = F_49 ( V_50 + V_46 ) ;
} else {
* V_49 = NULL ;
}
return 0 ;
}
static bool F_50 ( struct V_37 * V_51 ,
struct V_37 * V_27 )
{
if ( V_27 -> V_42 == 0 )
return false ;
return V_27 -> V_29 [ 0 ] > V_51 -> V_44 ;
}
void F_51 ( struct V_52 * V_53 )
{
struct V_54 * V_54 = & V_53 -> V_55 ;
struct V_56 * V_57 ;
struct V_37 * V_58 , * V_59 ;
int V_60 , V_61 ;
V_57 = F_14 ( sizeof( * V_57 ) , V_19 ) ;
if ( ! V_57 ) {
F_44 ( L_13 , V_54 ) ;
return;
}
F_5 ( & V_53 -> V_62 ) ;
V_60 = F_52 ( V_53 ) ;
V_61 = F_53 ( V_53 ) ;
V_58 = V_53 -> V_63 ;
V_59 = V_53 -> V_64 -> V_30 ;
if ( V_60 & V_65 )
V_61 |= V_65 ;
if ( F_54 ( V_53 ) ) {
F_2 ( L_14 , V_54 ) ;
goto V_66;
}
if ( V_53 -> V_67 == 0 &&
! ( V_61 & ( V_68 | V_65 ) ) ) {
F_2 ( L_15 , V_54 ) ;
goto V_66;
}
F_55 ( ! V_58 ) ;
if ( F_50 ( V_58 , V_59 ) ) {
if ( V_61 & ( V_68 | V_65 ) )
V_57 -> V_69 = true ;
} else {
if ( ! ( V_60 & V_65 ) &&
V_53 -> V_67 == 0 ) {
F_2 ( L_16
L_17 , V_54 ) ;
goto V_66;
}
}
F_2 ( L_18 ,
V_54 , V_57 , V_58 , F_56 ( V_61 ) ,
V_57 -> V_69 ? L_19 : L_20 ) ;
F_57 ( V_54 ) ;
F_16 ( & V_57 -> V_5 , 1 ) ;
V_57 -> V_53 = V_53 ;
F_17 ( & V_57 -> V_70 ) ;
F_17 ( & V_57 -> V_71 ) ;
V_57 -> V_72 = V_58 -> V_44 ;
V_57 -> V_73 = F_58 ( V_53 , NULL ) ;
V_57 -> V_61 = V_61 ;
V_57 -> V_74 = V_54 -> V_75 ;
V_57 -> V_76 = V_54 -> V_77 ;
V_57 -> V_78 = V_54 -> V_79 ;
if ( V_61 & V_80 ) {
F_59 ( V_53 ) ;
V_57 -> V_81 =
F_60 ( V_53 -> V_82 . V_83 ) ;
V_57 -> V_84 = V_53 -> V_82 . V_85 ;
} else {
V_57 -> V_81 = NULL ;
V_57 -> V_84 = 0 ;
}
V_57 -> V_86 = V_53 -> V_87 != V_88 ;
V_57 -> V_89 = V_53 -> V_67 ;
V_53 -> V_67 = 0 ;
V_57 -> V_90 = V_58 ;
F_61 ( & V_57 -> V_70 , & V_53 -> V_91 ) ;
V_58 = NULL ;
if ( V_60 & V_65 ) {
F_2 ( L_21
L_22 , V_54 ,
V_57 , V_58 , V_58 -> V_44 ) ;
V_57 -> V_92 = 1 ;
} else {
F_62 ( V_53 , V_57 ) ;
}
V_57 = NULL ;
V_66:
if ( V_53 -> V_63 ) {
V_53 -> V_63 = F_63 ( V_59 ) ;
F_2 ( L_23 , V_59 ) ;
}
F_7 ( & V_53 -> V_62 ) ;
F_24 ( V_57 ) ;
F_25 ( V_58 ) ;
}
int F_62 ( struct V_52 * V_53 ,
struct V_56 * V_57 )
{
struct V_54 * V_54 = & V_53 -> V_55 ;
struct V_1 * V_2 = F_64 ( V_54 -> V_93 ) -> V_2 ;
F_55 ( V_57 -> V_92 ) ;
V_57 -> V_94 = V_54 -> V_95 ;
V_57 -> V_96 = V_54 -> V_97 ;
V_57 -> V_98 = V_54 -> V_99 ;
V_57 -> ctime = V_54 -> V_100 ;
V_57 -> V_101 = V_53 -> V_102 ;
if ( V_57 -> V_89 ) {
F_2 ( L_24
L_25 , V_54 , V_57 ,
V_57 -> V_90 , V_57 -> V_90 -> V_44 ,
F_56 ( V_57 -> V_61 ) , V_57 -> V_94 ,
V_57 -> V_89 ) ;
return 0 ;
}
F_2 ( L_26 ,
V_54 , V_57 , V_57 -> V_90 ,
V_57 -> V_90 -> V_44 , F_56 ( V_57 -> V_61 ) ,
V_57 -> V_94 ) ;
F_5 ( & V_2 -> V_103 ) ;
F_61 ( & V_53 -> V_104 , & V_2 -> V_105 ) ;
F_7 ( & V_2 -> V_103 ) ;
return 1 ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_52 * V_53 ;
struct V_54 * V_106 = NULL ;
struct V_3 * V_48 ;
F_2 ( L_27 , V_4 , V_4 -> V_16 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_46 (ci, &realm->inodes_with_caps,
i_snap_realm_item) {
struct V_54 * V_54 = F_66 ( & V_53 -> V_55 ) ;
if ( ! V_54 )
continue;
F_7 ( & V_4 -> V_25 ) ;
F_67 ( V_106 ) ;
V_106 = V_54 ;
F_51 ( V_53 ) ;
F_5 ( & V_4 -> V_25 ) ;
}
F_7 ( & V_4 -> V_25 ) ;
F_67 ( V_106 ) ;
F_46 (child, &realm->children, child_item) {
F_2 ( L_28 ,
V_4 , V_4 -> V_16 , V_48 , V_48 -> V_16 ) ;
F_6 ( & V_48 -> V_23 ) ;
F_30 ( & V_48 -> V_23 , & V_4 -> V_23 ) ;
}
F_6 ( & V_4 -> V_23 ) ;
F_2 ( L_29 , V_4 , V_4 -> V_16 ) ;
}
int F_68 ( struct V_1 * V_2 ,
void * V_12 , void * V_107 , bool V_108 ,
struct V_3 * * V_109 )
{
struct V_110 * V_111 ;
T_3 * V_29 ;
T_3 * V_28 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_112 = NULL ;
int V_113 = 0 ;
int V_39 = - V_20 ;
F_69 ( V_114 ) ;
F_2 ( L_30 , V_108 ) ;
V_115:
F_70 ( & V_12 , V_107 , sizeof( * V_111 ) , V_116 ) ;
V_111 = V_12 ;
V_12 += sizeof( * V_111 ) ;
F_70 ( & V_12 , V_107 , sizeof( T_1 ) * ( F_71 ( V_111 -> V_42 ) +
F_71 ( V_111 -> V_41 ) ) , V_116 ) ;
V_29 = V_12 ;
V_12 += sizeof( T_1 ) * F_71 ( V_111 -> V_42 ) ;
V_28 = V_12 ;
V_12 += sizeof( T_1 ) * F_71 ( V_111 -> V_41 ) ;
V_4 = F_20 ( V_2 , F_72 ( V_111 -> V_16 ) ) ;
if ( ! V_4 ) {
V_4 = F_13 ( V_2 , F_72 ( V_111 -> V_16 ) ) ;
if ( F_38 ( V_4 ) ) {
V_39 = F_39 ( V_4 ) ;
goto V_43;
}
}
V_39 = F_37 ( V_2 , V_4 , F_72 ( V_111 -> V_13 ) ) ;
if ( V_39 < 0 )
goto V_43;
V_113 += V_39 ;
if ( F_72 ( V_111 -> V_44 ) > V_4 -> V_44 ) {
F_2 ( L_31 ,
V_4 -> V_16 , V_4 , V_4 -> V_44 , F_72 ( V_111 -> V_44 ) ) ;
V_4 -> V_44 = F_72 ( V_111 -> V_44 ) ;
V_4 -> V_117 = F_72 ( V_111 -> V_117 ) ;
V_4 -> V_47 = F_72 ( V_111 -> V_47 ) ;
V_4 -> V_42 = F_71 ( V_111 -> V_42 ) ;
V_39 = F_47 ( & V_4 -> V_29 , V_29 , V_4 -> V_42 ) ;
if ( V_39 < 0 )
goto V_43;
V_4 -> V_41 =
F_71 ( V_111 -> V_41 ) ;
V_39 = F_47 ( & V_4 -> V_28 , V_28 ,
V_4 -> V_41 ) ;
if ( V_39 < 0 )
goto V_43;
F_30 ( & V_4 -> V_23 , & V_114 ) ;
if ( V_4 -> V_44 > V_2 -> V_118 )
V_2 -> V_118 = V_4 -> V_44 ;
V_113 = 1 ;
} else if ( ! V_4 -> V_30 ) {
F_2 ( L_32 ,
V_4 -> V_16 , V_4 , V_4 -> V_44 ) ;
V_113 = 1 ;
} else {
F_2 ( L_33 ,
V_4 -> V_16 , V_4 , V_4 -> V_44 ) ;
}
F_2 ( L_34 , V_4 -> V_16 ,
V_4 , V_113 , V_12 , V_107 ) ;
if ( V_113 && V_12 >= V_107 )
F_45 ( V_4 ) ;
if ( ! V_112 )
V_112 = V_4 ;
else
F_27 ( V_2 , V_4 ) ;
if ( V_12 < V_107 )
goto V_115;
while ( ! F_32 ( & V_114 ) ) {
V_4 = F_33 ( & V_114 , struct V_3 ,
V_23 ) ;
F_65 ( V_4 ) ;
}
if ( V_109 )
* V_109 = V_112 ;
else
F_27 ( V_2 , V_112 ) ;
F_31 ( V_2 ) ;
return 0 ;
V_116:
V_39 = - V_119 ;
V_43:
if ( V_4 && ! F_38 ( V_4 ) )
F_27 ( V_2 , V_4 ) ;
if ( V_112 )
F_27 ( V_2 , V_112 ) ;
F_44 ( L_35 , V_39 ) ;
return V_39 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
struct V_54 * V_54 ;
struct V_120 * V_121 = NULL ;
F_2 ( L_36 ) ;
F_5 ( & V_2 -> V_103 ) ;
while ( ! F_32 ( & V_2 -> V_105 ) ) {
V_53 = F_33 ( & V_2 -> V_105 ,
struct V_52 , V_104 ) ;
V_54 = & V_53 -> V_55 ;
F_57 ( V_54 ) ;
F_7 ( & V_2 -> V_103 ) ;
F_5 ( & V_53 -> V_62 ) ;
F_74 ( V_53 , & V_121 , 0 ) ;
F_7 ( & V_53 -> V_62 ) ;
F_67 ( V_54 ) ;
F_5 ( & V_2 -> V_103 ) ;
}
F_7 ( & V_2 -> V_103 ) ;
if ( V_121 ) {
F_75 ( & V_121 -> V_122 ) ;
F_76 ( V_121 ) ;
}
F_2 ( L_37 ) ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_120 * V_121 ,
struct V_123 * V_124 )
{
struct V_125 * V_126 = V_2 -> V_127 -> V_126 ;
int V_128 = V_121 -> V_129 ;
T_1 V_130 ;
int V_131 ;
int V_132 ;
struct V_3 * V_4 = NULL ;
void * V_12 = V_124 -> V_133 . V_134 ;
void * V_107 = V_12 + V_124 -> V_133 . V_135 ;
struct V_136 * V_137 ;
int V_138 , V_139 ;
T_3 * V_140 = NULL , * V_141 = NULL ;
int V_46 ;
int V_142 = 0 ;
if ( V_124 -> V_133 . V_135 < sizeof( * V_137 ) )
goto V_116;
V_137 = V_12 ;
V_131 = F_71 ( V_137 -> V_131 ) ;
V_130 = F_72 ( V_137 -> V_130 ) ;
V_138 = F_71 ( V_137 -> V_138 ) ;
V_139 = F_71 ( V_137 -> V_139 ) ;
V_132 = F_71 ( V_137 -> V_132 ) ;
V_12 += sizeof( * V_137 ) ;
F_2 ( L_38 , V_128 ,
F_78 ( V_131 ) , V_130 , V_132 ) ;
F_79 ( & V_121 -> V_122 ) ;
V_121 -> V_143 ++ ;
F_75 ( & V_121 -> V_122 ) ;
F_36 ( & V_2 -> V_31 ) ;
V_142 = 1 ;
if ( V_131 == V_144 ) {
struct V_110 * V_111 ;
V_140 = V_12 ;
V_12 += sizeof( T_1 ) * V_138 ;
V_141 = V_12 ;
V_12 += sizeof( T_1 ) * V_139 ;
F_70 ( & V_12 , V_107 , sizeof( * V_111 ) , V_116 ) ;
V_111 = V_12 ;
V_4 = F_20 ( V_2 , V_130 ) ;
if ( ! V_4 ) {
V_4 = F_13 ( V_2 , V_130 ) ;
if ( F_38 ( V_4 ) )
goto V_145;
}
F_2 ( L_39 , V_4 -> V_16 , V_4 ) ;
for ( V_46 = 0 ; V_46 < V_138 ; V_46 ++ ) {
struct V_146 V_147 = {
. V_16 = F_72 ( V_140 [ V_46 ] ) ,
. V_148 = V_149 ,
} ;
struct V_54 * V_54 = F_80 ( V_126 , V_147 ) ;
struct V_52 * V_53 ;
struct V_3 * V_150 ;
if ( ! V_54 )
continue;
V_53 = F_81 ( V_54 ) ;
F_5 ( & V_53 -> V_62 ) ;
if ( ! V_53 -> V_64 )
goto V_151;
if ( V_53 -> V_64 -> V_117 >
F_72 ( V_111 -> V_117 ) ) {
F_2 ( L_40 ,
V_54 , V_53 -> V_64 -> V_16 ,
V_53 -> V_64 ) ;
goto V_151;
}
F_2 ( L_41 ,
V_54 , V_4 -> V_16 , V_4 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_6 ( & V_53 -> V_152 ) ;
F_30 ( & V_53 -> V_152 ,
& V_4 -> V_24 ) ;
V_150 = V_53 -> V_64 ;
V_53 -> V_64 = V_4 ;
F_7 ( & V_4 -> V_25 ) ;
F_7 ( & V_53 -> V_62 ) ;
F_1 ( V_2 , V_4 ) ;
F_27 ( V_2 , V_150 ) ;
F_67 ( V_54 ) ;
continue;
V_151:
F_7 ( & V_53 -> V_62 ) ;
F_67 ( V_54 ) ;
}
for ( V_46 = 0 ; V_46 < V_139 ; V_46 ++ ) {
struct V_3 * V_48 =
F_19 ( V_2 ,
F_72 ( V_141 [ V_46 ] ) ) ;
if ( ! V_48 )
continue;
F_37 ( V_2 , V_48 , V_4 -> V_16 ) ;
}
}
F_68 ( V_2 , V_12 , V_107 ,
V_131 == V_153 , NULL ) ;
if ( V_131 == V_144 )
F_27 ( V_2 , V_4 ) ;
F_31 ( V_2 ) ;
F_29 ( & V_2 -> V_31 ) ;
F_73 ( V_2 ) ;
return;
V_116:
F_44 ( L_42 , V_128 ) ;
F_82 ( V_124 ) ;
V_145:
if ( V_142 )
F_29 ( & V_2 -> V_31 ) ;
return;
}
int T_4 F_83 ( void )
{
V_154 = F_42 ( 0 , V_19 ) ;
if ( ! V_154 )
return - V_20 ;
V_154 -> V_44 = 1 ;
return 0 ;
}
void F_84 ( void )
{
F_25 ( V_154 ) ;
}
