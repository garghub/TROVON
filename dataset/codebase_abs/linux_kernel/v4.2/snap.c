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
if ( V_40 == 0 && V_4 -> V_44 == V_45 -> V_44 ) {
F_42 ( V_45 ) ;
V_38 = V_45 ;
goto V_46;
}
V_39 = - V_20 ;
if ( V_40 > ( V_47 - sizeof( * V_38 ) ) / sizeof( T_1 ) )
goto V_43;
V_38 = F_43 ( V_40 , V_19 ) ;
if ( ! V_38 )
goto V_43;
V_40 = 0 ;
V_38 -> V_44 = V_4 -> V_44 ;
if ( V_13 ) {
T_2 V_48 ;
for ( V_48 = 0 ; V_48 < V_13 -> V_30 -> V_42 ; V_48 ++ )
if ( V_13 -> V_30 -> V_29 [ V_48 ] >=
V_4 -> V_49 )
V_38 -> V_29 [ V_40 ++ ] =
V_13 -> V_30 -> V_29 [ V_48 ] ;
if ( V_13 -> V_30 -> V_44 > V_38 -> V_44 )
V_38 -> V_44 = V_13 -> V_30 -> V_44 ;
}
memcpy ( V_38 -> V_29 + V_40 , V_4 -> V_29 ,
sizeof( T_1 ) * V_4 -> V_42 ) ;
V_40 += V_4 -> V_42 ;
memcpy ( V_38 -> V_29 + V_40 , V_4 -> V_28 ,
sizeof( T_1 ) * V_4 -> V_41 ) ;
V_40 += V_4 -> V_41 ;
F_44 ( V_38 -> V_29 , V_40 , sizeof( T_1 ) , F_40 , NULL ) ;
V_38 -> V_42 = V_40 ;
F_2 ( L_10 ,
V_4 -> V_16 , V_4 , V_38 , V_38 -> V_44 ,
( unsigned int ) V_38 -> V_42 ) ;
V_46:
F_25 ( V_4 -> V_30 ) ;
V_4 -> V_30 = V_38 ;
return 0 ;
V_43:
if ( V_4 -> V_30 ) {
F_25 ( V_4 -> V_30 ) ;
V_4 -> V_30 = NULL ;
}
F_45 ( L_11 , V_4 -> V_16 ,
V_4 , V_39 ) ;
return V_39 ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_3 * V_50 ;
F_2 ( L_12 , V_4 -> V_16 , V_4 ) ;
F_41 ( V_4 ) ;
F_47 (child, &realm->children, child_item)
F_46 ( V_50 ) ;
}
static int F_48 ( T_1 * * V_51 , T_3 * V_52 , T_2 V_40 )
{
T_2 V_48 ;
F_24 ( * V_51 ) ;
if ( V_40 ) {
* V_51 = F_49 ( V_40 , sizeof( T_1 ) , V_19 ) ;
if ( ! * V_51 )
return - V_20 ;
for ( V_48 = 0 ; V_48 < V_40 ; V_48 ++ )
( * V_51 ) [ V_48 ] = F_50 ( V_52 + V_48 ) ;
} else {
* V_51 = NULL ;
}
return 0 ;
}
static bool F_51 ( struct V_37 * V_53 ,
struct V_37 * V_27 )
{
if ( V_27 -> V_42 == 0 )
return false ;
return V_27 -> V_29 [ 0 ] > V_53 -> V_44 ;
}
void F_52 ( struct V_54 * V_55 )
{
struct V_56 * V_56 = & V_55 -> V_57 ;
struct V_58 * V_59 ;
struct V_37 * V_60 , * V_61 ;
int V_62 , V_63 ;
V_59 = F_14 ( sizeof( * V_59 ) , V_19 ) ;
if ( ! V_59 ) {
F_45 ( L_13 , V_56 ) ;
return;
}
F_5 ( & V_55 -> V_64 ) ;
V_62 = F_53 ( V_55 ) ;
V_63 = F_54 ( V_55 ) ;
V_60 = V_55 -> V_65 ;
V_61 = V_55 -> V_66 -> V_30 ;
if ( V_62 & V_67 )
V_63 |= V_67 ;
if ( F_55 ( V_55 ) ) {
F_2 ( L_14 , V_56 ) ;
goto V_68;
}
if ( V_55 -> V_69 == 0 &&
! ( V_63 & ( V_70 | V_67 ) ) ) {
F_2 ( L_15 , V_56 ) ;
goto V_68;
}
F_56 ( ! V_60 ) ;
if ( F_51 ( V_60 , V_61 ) ) {
if ( V_63 & ( V_70 | V_67 ) )
V_59 -> V_71 = true ;
} else {
if ( ! ( V_62 & V_67 ) &&
V_55 -> V_69 == 0 ) {
F_2 ( L_16
L_17 , V_56 ) ;
goto V_68;
}
}
F_2 ( L_18 ,
V_56 , V_59 , V_60 , F_57 ( V_63 ) ,
V_59 -> V_71 ? L_19 : L_20 ) ;
F_58 ( V_56 ) ;
F_16 ( & V_59 -> V_5 , 1 ) ;
V_59 -> V_55 = V_55 ;
F_17 ( & V_59 -> V_72 ) ;
F_17 ( & V_59 -> V_73 ) ;
V_59 -> V_74 = V_60 -> V_44 ;
V_59 -> V_75 = F_59 ( V_55 , NULL ) ;
V_59 -> V_63 = V_63 ;
V_59 -> V_76 = V_56 -> V_77 ;
V_59 -> V_78 = V_56 -> V_79 ;
V_59 -> V_80 = V_56 -> V_81 ;
if ( V_63 & V_82 ) {
F_60 ( V_55 ) ;
V_59 -> V_83 =
F_61 ( V_55 -> V_84 . V_85 ) ;
V_59 -> V_86 = V_55 -> V_84 . V_87 ;
} else {
V_59 -> V_83 = NULL ;
V_59 -> V_86 = 0 ;
}
V_59 -> V_88 = V_55 -> V_89 != V_90 ;
V_59 -> V_91 = V_55 -> V_69 ;
V_55 -> V_69 = 0 ;
V_59 -> V_92 = V_60 ;
F_62 ( & V_59 -> V_72 , & V_55 -> V_93 ) ;
V_60 = NULL ;
if ( V_62 & V_67 ) {
F_2 ( L_21
L_22 , V_56 ,
V_59 , V_60 , V_60 -> V_44 ) ;
V_59 -> V_94 = 1 ;
} else {
F_63 ( V_55 , V_59 ) ;
}
V_59 = NULL ;
V_68:
if ( V_55 -> V_65 ) {
V_55 -> V_65 = F_42 ( V_61 ) ;
F_2 ( L_23 , V_61 ) ;
}
F_7 ( & V_55 -> V_64 ) ;
F_24 ( V_59 ) ;
F_25 ( V_60 ) ;
}
int F_63 ( struct V_54 * V_55 ,
struct V_58 * V_59 )
{
struct V_56 * V_56 = & V_55 -> V_57 ;
struct V_1 * V_2 = F_64 ( V_56 -> V_95 ) -> V_2 ;
F_56 ( V_59 -> V_94 ) ;
V_59 -> V_96 = V_56 -> V_97 ;
V_59 -> V_98 = V_56 -> V_99 ;
V_59 -> V_100 = V_56 -> V_101 ;
V_59 -> ctime = V_56 -> V_102 ;
V_59 -> V_103 = V_55 -> V_104 ;
if ( V_59 -> V_91 ) {
F_2 ( L_24
L_25 , V_56 , V_59 ,
V_59 -> V_92 , V_59 -> V_92 -> V_44 ,
F_57 ( V_59 -> V_63 ) , V_59 -> V_96 ,
V_59 -> V_91 ) ;
return 0 ;
}
F_2 ( L_26 ,
V_56 , V_59 , V_59 -> V_92 ,
V_59 -> V_92 -> V_44 , F_57 ( V_59 -> V_63 ) ,
V_59 -> V_96 ) ;
F_5 ( & V_2 -> V_105 ) ;
F_62 ( & V_55 -> V_106 , & V_2 -> V_107 ) ;
F_7 ( & V_2 -> V_105 ) ;
return 1 ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_54 * V_55 ;
struct V_56 * V_108 = NULL ;
struct V_3 * V_50 ;
F_2 ( L_27 , V_4 , V_4 -> V_16 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_47 (ci, &realm->inodes_with_caps,
i_snap_realm_item) {
struct V_56 * V_56 = F_66 ( & V_55 -> V_57 ) ;
if ( ! V_56 )
continue;
F_7 ( & V_4 -> V_25 ) ;
F_67 ( V_108 ) ;
V_108 = V_56 ;
F_52 ( V_55 ) ;
F_5 ( & V_4 -> V_25 ) ;
}
F_7 ( & V_4 -> V_25 ) ;
F_67 ( V_108 ) ;
F_47 (child, &realm->children, child_item) {
F_2 ( L_28 ,
V_4 , V_4 -> V_16 , V_50 , V_50 -> V_16 ) ;
F_6 ( & V_50 -> V_23 ) ;
F_30 ( & V_50 -> V_23 , & V_4 -> V_23 ) ;
}
F_6 ( & V_4 -> V_23 ) ;
F_2 ( L_29 , V_4 , V_4 -> V_16 ) ;
}
int F_68 ( struct V_1 * V_2 ,
void * V_12 , void * V_109 , bool V_110 ,
struct V_3 * * V_111 )
{
struct V_112 * V_113 ;
T_3 * V_29 ;
T_3 * V_28 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_114 = NULL ;
int V_115 = 0 ;
int V_39 = - V_20 ;
F_69 ( V_116 ) ;
F_2 ( L_30 , V_110 ) ;
V_117:
F_70 ( & V_12 , V_109 , sizeof( * V_113 ) , V_118 ) ;
V_113 = V_12 ;
V_12 += sizeof( * V_113 ) ;
F_70 ( & V_12 , V_109 , sizeof( T_1 ) * ( F_71 ( V_113 -> V_42 ) +
F_71 ( V_113 -> V_41 ) ) , V_118 ) ;
V_29 = V_12 ;
V_12 += sizeof( T_1 ) * F_71 ( V_113 -> V_42 ) ;
V_28 = V_12 ;
V_12 += sizeof( T_1 ) * F_71 ( V_113 -> V_41 ) ;
V_4 = F_20 ( V_2 , F_72 ( V_113 -> V_16 ) ) ;
if ( ! V_4 ) {
V_4 = F_13 ( V_2 , F_72 ( V_113 -> V_16 ) ) ;
if ( F_38 ( V_4 ) ) {
V_39 = F_39 ( V_4 ) ;
goto V_43;
}
}
V_39 = F_37 ( V_2 , V_4 , F_72 ( V_113 -> V_13 ) ) ;
if ( V_39 < 0 )
goto V_43;
V_115 += V_39 ;
if ( F_72 ( V_113 -> V_44 ) > V_4 -> V_44 ) {
F_2 ( L_31 ,
V_4 -> V_16 , V_4 , V_4 -> V_44 , F_72 ( V_113 -> V_44 ) ) ;
V_4 -> V_44 = F_72 ( V_113 -> V_44 ) ;
V_4 -> V_119 = F_72 ( V_113 -> V_119 ) ;
V_4 -> V_49 = F_72 ( V_113 -> V_49 ) ;
V_4 -> V_42 = F_71 ( V_113 -> V_42 ) ;
V_39 = F_48 ( & V_4 -> V_29 , V_29 , V_4 -> V_42 ) ;
if ( V_39 < 0 )
goto V_43;
V_4 -> V_41 =
F_71 ( V_113 -> V_41 ) ;
V_39 = F_48 ( & V_4 -> V_28 , V_28 ,
V_4 -> V_41 ) ;
if ( V_39 < 0 )
goto V_43;
F_30 ( & V_4 -> V_23 , & V_116 ) ;
if ( V_4 -> V_44 > V_2 -> V_120 )
V_2 -> V_120 = V_4 -> V_44 ;
V_115 = 1 ;
} else if ( ! V_4 -> V_30 ) {
F_2 ( L_32 ,
V_4 -> V_16 , V_4 , V_4 -> V_44 ) ;
V_115 = 1 ;
} else {
F_2 ( L_33 ,
V_4 -> V_16 , V_4 , V_4 -> V_44 ) ;
}
F_2 ( L_34 , V_4 -> V_16 ,
V_4 , V_115 , V_12 , V_109 ) ;
if ( V_115 && V_12 >= V_109 )
F_46 ( V_4 ) ;
if ( ! V_114 )
V_114 = V_4 ;
else
F_27 ( V_2 , V_4 ) ;
if ( V_12 < V_109 )
goto V_117;
while ( ! F_32 ( & V_116 ) ) {
V_4 = F_33 ( & V_116 , struct V_3 ,
V_23 ) ;
F_65 ( V_4 ) ;
}
if ( V_111 )
* V_111 = V_114 ;
else
F_27 ( V_2 , V_114 ) ;
F_31 ( V_2 ) ;
return 0 ;
V_118:
V_39 = - V_121 ;
V_43:
if ( V_4 && ! F_38 ( V_4 ) )
F_27 ( V_2 , V_4 ) ;
if ( V_114 )
F_27 ( V_2 , V_114 ) ;
F_45 ( L_35 , V_39 ) ;
return V_39 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
struct V_56 * V_56 ;
struct V_122 * V_123 = NULL ;
F_2 ( L_36 ) ;
F_5 ( & V_2 -> V_105 ) ;
while ( ! F_32 ( & V_2 -> V_107 ) ) {
V_55 = F_33 ( & V_2 -> V_107 ,
struct V_54 , V_106 ) ;
V_56 = & V_55 -> V_57 ;
F_58 ( V_56 ) ;
F_7 ( & V_2 -> V_105 ) ;
F_5 ( & V_55 -> V_64 ) ;
F_74 ( V_55 , & V_123 , 0 ) ;
F_7 ( & V_55 -> V_64 ) ;
F_67 ( V_56 ) ;
F_5 ( & V_2 -> V_105 ) ;
}
F_7 ( & V_2 -> V_105 ) ;
if ( V_123 ) {
F_75 ( & V_123 -> V_124 ) ;
F_76 ( V_123 ) ;
}
F_2 ( L_37 ) ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_122 * V_123 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 = V_2 -> V_129 -> V_128 ;
int V_130 = V_123 -> V_131 ;
T_1 V_132 ;
int V_133 ;
int V_134 ;
struct V_3 * V_4 = NULL ;
void * V_12 = V_126 -> V_135 . V_136 ;
void * V_109 = V_12 + V_126 -> V_135 . V_137 ;
struct V_138 * V_139 ;
int V_140 , V_141 ;
T_3 * V_142 = NULL , * V_143 = NULL ;
int V_48 ;
int V_144 = 0 ;
if ( V_126 -> V_135 . V_137 < sizeof( * V_139 ) )
goto V_118;
V_139 = V_12 ;
V_133 = F_71 ( V_139 -> V_133 ) ;
V_132 = F_72 ( V_139 -> V_132 ) ;
V_140 = F_71 ( V_139 -> V_140 ) ;
V_141 = F_71 ( V_139 -> V_141 ) ;
V_134 = F_71 ( V_139 -> V_134 ) ;
V_12 += sizeof( * V_139 ) ;
F_2 ( L_38 , V_130 ,
F_78 ( V_133 ) , V_132 , V_134 ) ;
F_79 ( & V_123 -> V_124 ) ;
V_123 -> V_145 ++ ;
F_75 ( & V_123 -> V_124 ) ;
F_36 ( & V_2 -> V_31 ) ;
V_144 = 1 ;
if ( V_133 == V_146 ) {
struct V_112 * V_113 ;
V_142 = V_12 ;
V_12 += sizeof( T_1 ) * V_140 ;
V_143 = V_12 ;
V_12 += sizeof( T_1 ) * V_141 ;
F_70 ( & V_12 , V_109 , sizeof( * V_113 ) , V_118 ) ;
V_113 = V_12 ;
V_4 = F_20 ( V_2 , V_132 ) ;
if ( ! V_4 ) {
V_4 = F_13 ( V_2 , V_132 ) ;
if ( F_38 ( V_4 ) )
goto V_147;
}
F_2 ( L_39 , V_4 -> V_16 , V_4 ) ;
for ( V_48 = 0 ; V_48 < V_140 ; V_48 ++ ) {
struct V_148 V_149 = {
. V_16 = F_72 ( V_142 [ V_48 ] ) ,
. V_150 = V_151 ,
} ;
struct V_56 * V_56 = F_80 ( V_128 , V_149 ) ;
struct V_54 * V_55 ;
struct V_3 * V_152 ;
if ( ! V_56 )
continue;
V_55 = F_81 ( V_56 ) ;
F_5 ( & V_55 -> V_64 ) ;
if ( ! V_55 -> V_66 )
goto V_153;
if ( V_55 -> V_66 -> V_119 >
F_72 ( V_113 -> V_119 ) ) {
F_2 ( L_40 ,
V_56 , V_55 -> V_66 -> V_16 ,
V_55 -> V_66 ) ;
goto V_153;
}
F_2 ( L_41 ,
V_56 , V_4 -> V_16 , V_4 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_6 ( & V_55 -> V_154 ) ;
F_30 ( & V_55 -> V_154 ,
& V_4 -> V_24 ) ;
V_152 = V_55 -> V_66 ;
V_55 -> V_66 = V_4 ;
F_7 ( & V_4 -> V_25 ) ;
F_7 ( & V_55 -> V_64 ) ;
F_1 ( V_2 , V_4 ) ;
F_27 ( V_2 , V_152 ) ;
F_67 ( V_56 ) ;
continue;
V_153:
F_7 ( & V_55 -> V_64 ) ;
F_67 ( V_56 ) ;
}
for ( V_48 = 0 ; V_48 < V_141 ; V_48 ++ ) {
struct V_3 * V_50 =
F_19 ( V_2 ,
F_72 ( V_143 [ V_48 ] ) ) ;
if ( ! V_50 )
continue;
F_37 ( V_2 , V_50 , V_4 -> V_16 ) ;
}
}
F_68 ( V_2 , V_12 , V_109 ,
V_133 == V_155 , NULL ) ;
if ( V_133 == V_146 )
F_27 ( V_2 , V_4 ) ;
F_31 ( V_2 ) ;
F_29 ( & V_2 -> V_31 ) ;
F_73 ( V_2 ) ;
return;
V_118:
F_45 ( L_42 , V_130 ) ;
F_82 ( V_126 ) ;
V_147:
if ( V_144 )
F_29 ( & V_2 -> V_31 ) ;
return;
}
int T_4 F_83 ( void )
{
V_45 = F_43 ( 0 , V_19 ) ;
if ( ! V_45 )
return - V_20 ;
V_45 -> V_44 = 1 ;
return 0 ;
}
void F_84 ( void )
{
F_25 ( V_45 ) ;
}
