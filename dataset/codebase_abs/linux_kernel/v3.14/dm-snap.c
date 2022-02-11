struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
struct V_1 * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_5 ;
}
static T_1 F_3 ( struct V_6 * V_7 ,
T_2 V_8 )
{
return V_8 << V_7 -> V_9 ;
}
static int F_4 ( struct V_10 * V_11 , struct V_10 * V_12 )
{
return V_11 == V_12 ;
}
static void F_5 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 , sizeof( struct V_14 ) ) ;
F_7 ( & V_15 -> V_16 ) ;
}
static bool F_8 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 , sizeof( struct V_14 ) ) ;
return ! F_9 ( & V_15 -> V_16 ) ;
}
static void F_10 ( struct V_2 * V_3 , struct V_13 * V_13 , T_2 V_8 )
{
struct V_14 * V_15 = F_6 ( V_13 , sizeof( struct V_14 ) ) ;
V_15 -> V_8 = V_8 ;
F_11 ( & V_3 -> V_17 ) ;
F_12 ( & V_15 -> V_16 ,
& V_3 -> V_18 [ F_13 ( V_8 ) ] ) ;
F_14 ( & V_3 -> V_17 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_13 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 , sizeof( struct V_14 ) ) ;
unsigned long V_19 ;
F_16 ( & V_3 -> V_17 , V_19 ) ;
F_17 ( & V_15 -> V_16 ) ;
F_18 ( & V_3 -> V_17 , V_19 ) ;
}
static int F_19 ( struct V_2 * V_3 , T_2 V_8 )
{
struct V_14 * V_15 ;
int V_20 = 0 ;
F_11 ( & V_3 -> V_17 ) ;
F_20 (c,
&s->tracked_chunk_hash[DM_TRACKED_CHUNK_HASH(chunk)], node) {
if ( V_15 -> V_8 == V_8 ) {
V_20 = 1 ;
break;
}
}
F_14 ( & V_3 -> V_17 ) ;
return V_20 ;
}
static void F_21 ( struct V_2 * V_3 , T_2 V_8 )
{
while ( F_19 ( V_3 , V_8 ) )
F_22 ( 1 ) ;
}
static int F_23 ( void )
{
int V_21 ;
V_22 = F_24 ( V_23 * sizeof( struct V_24 ) ,
V_25 ) ;
if ( ! V_22 ) {
F_25 ( L_1 ) ;
return - V_26 ;
}
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ )
F_26 ( V_22 + V_21 ) ;
F_27 ( & V_27 ) ;
return 0 ;
}
static void F_28 ( void )
{
F_29 ( V_22 ) ;
}
static unsigned F_30 ( struct V_10 * V_28 )
{
return V_28 -> V_29 & V_30 ;
}
static struct V_4 * F_31 ( struct V_10 * V_4 )
{
struct V_24 * V_31 ;
struct V_4 * V_32 ;
V_31 = & V_22 [ F_30 ( V_4 ) ] ;
F_32 (o, ol, hash_list)
if ( F_4 ( V_32 -> V_28 , V_4 ) )
return V_32 ;
return NULL ;
}
static void F_33 ( struct V_4 * V_32 )
{
struct V_24 * V_33 = & V_22 [ F_30 ( V_32 -> V_28 ) ] ;
F_34 ( & V_32 -> V_34 , V_33 ) ;
}
static int F_35 ( struct V_2 * V_35 ,
struct V_2 * * V_36 ,
struct V_2 * * V_37 ,
struct V_2 * * V_38 )
{
struct V_2 * V_3 ;
struct V_4 * V_32 ;
int V_39 = 0 ;
int V_40 ;
V_32 = F_31 ( V_35 -> V_4 -> V_28 ) ;
if ( ! V_32 )
goto V_41;
F_32 (s, &o->snapshots, list) {
if ( F_36 ( V_3 -> V_42 ) && V_38 )
* V_38 = V_3 ;
if ( ! F_4 ( V_3 -> V_5 -> V_28 , V_35 -> V_5 -> V_28 ) )
continue;
F_37 ( & V_3 -> V_43 ) ;
V_40 = V_3 -> V_40 ;
F_38 ( & V_3 -> V_43 ) ;
if ( V_40 ) {
if ( V_36 )
* V_36 = V_3 ;
} else if ( V_37 )
* V_37 = V_3 ;
V_39 ++ ;
}
V_41:
return V_39 ;
}
static int F_39 ( struct V_2 * V_35 )
{
struct V_2 * V_36 = NULL , * V_37 = NULL ;
struct V_2 * V_38 = NULL ;
if ( ( F_35 ( V_35 , & V_36 , & V_37 ,
& V_38 ) == 2 ) ||
V_37 ) {
V_35 -> V_42 -> error = L_2
L_3 ;
return - V_44 ;
}
if ( ! V_36 )
return 0 ;
if ( ! F_36 ( V_35 -> V_42 ) )
return 1 ;
if ( V_38 ) {
V_35 -> V_42 -> error = L_4 ;
return - V_44 ;
}
if ( ! V_36 -> V_7 -> type -> V_45 ||
! V_36 -> V_7 -> type -> V_46 ) {
V_35 -> V_42 -> error = L_5
L_6 ;
return - V_44 ;
}
return 1 ;
}
static void F_40 ( struct V_4 * V_32 , struct V_2 * V_3 )
{
struct V_2 * V_47 ;
F_32 (l, &o->snapshots, list)
if ( V_47 -> V_7 -> V_48 < V_3 -> V_7 -> V_48 )
break;
F_34 ( & V_3 -> V_49 , & V_47 -> V_49 ) ;
}
static int F_41 ( struct V_2 * V_35 )
{
struct V_4 * V_32 , * V_50 = NULL ;
struct V_10 * V_28 = V_35 -> V_4 -> V_28 ;
int V_51 = 0 ;
V_50 = F_24 ( sizeof( * V_50 ) , V_25 ) ;
if ( ! V_50 )
return - V_26 ;
F_42 ( & V_27 ) ;
V_51 = F_39 ( V_35 ) ;
if ( V_51 < 0 ) {
F_29 ( V_50 ) ;
goto V_41;
}
V_32 = F_31 ( V_28 ) ;
if ( V_32 )
F_29 ( V_50 ) ;
else {
V_32 = V_50 ;
F_26 ( & V_32 -> V_52 ) ;
V_32 -> V_28 = V_28 ;
F_33 ( V_32 ) ;
}
F_40 ( V_32 , V_35 ) ;
V_41:
F_43 ( & V_27 ) ;
return V_51 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_10 * V_28 = V_3 -> V_4 -> V_28 ;
F_42 ( & V_27 ) ;
F_45 ( & V_3 -> V_49 ) ;
F_40 ( F_31 ( V_28 ) , V_3 ) ;
F_43 ( & V_27 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_4 * V_32 ;
F_42 ( & V_27 ) ;
V_32 = F_31 ( V_3 -> V_4 -> V_28 ) ;
F_45 ( & V_3 -> V_49 ) ;
if ( V_32 && F_47 ( & V_32 -> V_52 ) ) {
F_45 ( & V_32 -> V_34 ) ;
F_29 ( V_32 ) ;
}
F_43 ( & V_27 ) ;
}
static int F_48 ( struct V_53 * V_54 ,
T_3 V_55 , unsigned V_56 )
{
unsigned int V_21 ;
V_54 -> V_56 = V_56 ;
V_54 -> V_57 = V_55 - 1 ;
V_54 -> V_58 = F_49 ( V_55 , sizeof( struct V_24 ) ) ;
if ( ! V_54 -> V_58 )
return - V_26 ;
for ( V_21 = 0 ; V_21 < V_55 ; V_21 ++ )
F_26 ( V_54 -> V_58 + V_21 ) ;
return 0 ;
}
static void F_50 ( struct V_53 * V_54 ,
struct V_59 * V_60 )
{
struct V_24 * V_61 ;
struct V_62 * V_63 , * V_64 ;
int V_21 , V_55 ;
V_55 = V_54 -> V_57 + 1 ;
for ( V_21 = 0 ; V_21 < V_55 ; V_21 ++ ) {
V_61 = V_54 -> V_58 + V_21 ;
F_51 (ex, next, slot, hash_list)
F_52 ( V_60 , V_63 ) ;
}
F_53 ( V_54 -> V_58 ) ;
}
static T_3 F_54 ( struct V_53 * V_54 , T_2 V_8 )
{
return ( V_8 >> V_54 -> V_56 ) & V_54 -> V_57 ;
}
static void F_55 ( struct V_62 * V_65 )
{
F_45 ( & V_65 -> V_34 ) ;
}
static struct V_62 * F_56 ( struct V_53 * V_54 ,
T_2 V_8 )
{
struct V_24 * V_61 ;
struct V_62 * V_65 ;
V_61 = & V_54 -> V_58 [ F_54 ( V_54 , V_8 ) ] ;
F_32 (e, slot, hash_list)
if ( V_8 >= V_65 -> V_66 &&
V_8 <= V_65 -> V_66 + F_57 ( V_65 ) )
return V_65 ;
return NULL ;
}
static struct V_62 * F_58 ( T_4 V_67 )
{
struct V_62 * V_65 ;
V_65 = F_59 ( V_68 , V_67 ) ;
if ( ! V_65 && V_67 == V_69 )
V_65 = F_59 ( V_68 , V_70 ) ;
return V_65 ;
}
static void F_60 ( struct V_62 * V_65 )
{
F_52 ( V_68 , V_65 ) ;
}
static struct V_71 * F_61 ( struct V_2 * V_3 )
{
struct V_71 * V_72 = F_62 ( V_3 -> V_73 ,
V_69 ) ;
F_63 ( & V_3 -> V_74 ) ;
V_72 -> V_35 = V_3 ;
return V_72 ;
}
static void F_64 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = V_72 -> V_35 ;
F_65 ( V_72 , V_3 -> V_73 ) ;
F_66 () ;
F_67 ( & V_3 -> V_74 ) ;
}
static void F_68 ( struct V_53 * V_75 ,
struct V_62 * V_76 )
{
struct V_24 * V_47 ;
struct V_62 * V_65 = NULL ;
V_47 = & V_75 -> V_58 [ F_54 ( V_75 , V_76 -> V_66 ) ] ;
if ( ! V_75 -> V_56 )
goto V_41;
F_69 (e, l, hash_list) {
if ( V_76 -> V_66 == ( V_65 -> V_66 +
F_57 ( V_65 ) + 1 ) &&
V_76 -> V_77 == ( F_70 ( V_65 -> V_77 ) +
F_57 ( V_65 ) + 1 ) ) {
F_71 ( V_65 ) ;
F_60 ( V_76 ) ;
return;
}
if ( V_76 -> V_66 == ( V_65 -> V_66 - 1 ) &&
V_76 -> V_77 == ( F_70 ( V_65 -> V_77 ) - 1 ) ) {
F_71 ( V_65 ) ;
V_65 -> V_66 -- ;
V_65 -> V_77 -- ;
F_60 ( V_76 ) ;
return;
}
if ( V_76 -> V_66 > V_65 -> V_66 )
break;
}
V_41:
F_72 ( & V_76 -> V_34 , V_65 ? & V_65 -> V_34 : V_47 ) ;
}
static int F_73 ( void * V_78 , T_2 V_79 , T_2 V_80 )
{
struct V_2 * V_3 = V_78 ;
struct V_62 * V_65 ;
V_65 = F_58 ( V_25 ) ;
if ( ! V_65 )
return - V_26 ;
V_65 -> V_66 = V_79 ;
V_65 -> V_77 = V_80 ;
F_68 ( & V_3 -> V_81 , V_65 ) ;
return 0 ;
}
static T_3 F_74 ( struct V_4 * V_32 )
{
struct V_2 * V_35 ;
unsigned V_48 = 0 ;
if ( V_32 )
F_32 (snap, &o->snapshots, list)
V_48 = F_75 ( V_48 ,
V_35 -> V_7 -> V_48 ) ;
return ( T_3 ) V_48 ;
}
static int F_76 ( void )
{
unsigned long V_60 = 2 * 1024 * 1024 ;
V_60 /= sizeof( struct V_24 ) ;
return V_60 ;
}
static int F_77 ( struct V_2 * V_3 )
{
T_1 V_82 , V_83 , V_84 ;
V_83 = F_78 ( V_3 -> V_5 -> V_28 ) ;
V_84 = F_76 () ;
V_82 = V_83 >> V_3 -> V_7 -> V_9 ;
V_82 = F_79 ( V_82 , V_84 ) ;
if ( V_82 < 64 )
V_82 = 64 ;
V_82 = F_80 ( V_82 ) ;
if ( F_48 ( & V_3 -> V_81 , V_82 ,
V_85 ) )
return - V_26 ;
V_82 >>= 3 ;
if ( V_82 < 64 )
V_82 = 64 ;
if ( F_48 ( & V_3 -> V_86 , V_82 , 0 ) ) {
F_50 ( & V_3 -> V_81 , V_68 ) ;
return - V_26 ;
}
return 0 ;
}
static void F_81 ( struct V_2 * V_3 )
{
F_82 ( V_87 , & V_3 -> V_88 ) ;
F_83 () ;
F_84 ( & V_3 -> V_88 , V_87 ) ;
}
static struct V_13 * F_85 ( struct V_2 * V_3 )
{
V_3 -> V_89 = 0 ;
V_3 -> V_90 = 0 ;
return F_86 ( & V_3 -> V_91 ) ;
}
static int F_87 ( struct V_2 * V_3 ,
T_2 V_66 )
{
struct V_62 * V_65 ;
V_65 = F_56 ( & V_3 -> V_81 , V_66 ) ;
if ( ! V_65 ) {
F_25 ( L_7
L_8 ,
( unsigned long long ) V_66 ) ;
return - V_44 ;
}
if ( ! F_57 ( V_65 ) ) {
F_55 ( V_65 ) ;
F_60 ( V_65 ) ;
return 0 ;
}
if ( V_66 == V_65 -> V_66 ) {
V_65 -> V_66 ++ ;
V_65 -> V_77 ++ ;
} else if ( V_66 != V_65 -> V_66 +
F_57 ( V_65 ) ) {
F_25 ( L_9
L_10 ,
( unsigned long long ) V_66 ,
( unsigned long long ) V_65 -> V_66 ,
( unsigned long long )
V_65 -> V_66 + F_57 ( V_65 ) ) ;
return - V_44 ;
}
F_88 ( V_65 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_13 * V_92 = NULL ;
int V_51 ;
T_2 V_66 = V_3 -> V_89 + V_3 -> V_90 - 1 ;
F_42 ( & V_3 -> V_43 ) ;
do {
V_51 = F_87 ( V_3 , V_66 ) ;
if ( V_51 )
goto V_41;
} while ( V_66 -- > V_3 -> V_89 );
V_92 = F_85 ( V_3 ) ;
V_41:
F_43 ( & V_3 -> V_43 ) ;
if ( V_92 )
F_90 ( V_92 ) ;
return V_51 ;
}
static T_5 F_91 ( void )
{
T_5 V_93 ;
F_92 ( & V_94 ) ;
V_93 = V_95 ;
F_93 ( & V_94 ) ;
return V_93 ;
}
static void F_94 ( void )
{
F_92 ( & V_94 ) ;
V_95 ++ ;
F_93 ( & V_94 ) ;
F_95 ( & V_96 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
int V_21 , V_97 ;
T_2 V_66 , V_77 ;
struct V_98 V_99 , V_100 ;
T_1 V_101 ;
T_5 V_102 ;
F_97 ( ! F_98 ( V_87 , & V_3 -> V_88 ) ) ;
if ( F_99 ( F_98 ( V_103 , & V_3 -> V_88 ) ) )
goto V_104;
if ( ! V_3 -> V_105 ) {
F_25 ( L_11 ) ;
goto V_104;
}
V_97 = V_3 -> V_7 -> type -> V_45 ( V_3 -> V_7 , & V_66 ,
& V_77 ) ;
if ( V_97 <= 0 ) {
if ( V_97 < 0 ) {
F_25 ( L_12
L_13 ) ;
F_42 ( & V_3 -> V_43 ) ;
V_3 -> V_106 = 1 ;
F_43 ( & V_3 -> V_43 ) ;
}
goto V_104;
}
V_66 = V_66 + 1 - V_97 ;
V_77 = V_77 + 1 - V_97 ;
V_101 = V_97 * V_3 -> V_7 -> V_48 ;
V_100 . V_28 = V_3 -> V_4 -> V_28 ;
V_100 . V_107 = F_3 ( V_3 -> V_7 , V_66 ) ;
V_100 . V_39 = F_79 ( V_101 , F_78 ( V_100 . V_28 ) - V_100 . V_107 ) ;
V_99 . V_28 = V_3 -> V_5 -> V_28 ;
V_99 . V_107 = F_3 ( V_3 -> V_7 , V_77 ) ;
V_99 . V_39 = V_100 . V_39 ;
V_102 = F_91 () ;
while ( F_100 ( V_3 , V_100 . V_107 , V_101 ) ) {
F_101 ( V_96 ,
( F_91 () !=
V_102 ) ) ;
V_102 = F_91 () ;
}
F_42 ( & V_3 -> V_43 ) ;
V_3 -> V_89 = V_66 ;
V_3 -> V_90 = V_97 ;
F_43 ( & V_3 -> V_43 ) ;
for ( V_21 = 0 ; V_21 < V_97 ; V_21 ++ )
F_21 ( V_3 , V_66 + V_21 ) ;
F_102 ( V_3 -> V_108 , & V_99 , 1 , & V_100 , 0 , V_109 , V_3 ) ;
return;
V_104:
F_81 ( V_3 ) ;
}
static void V_109 ( int V_110 , unsigned long V_111 , void * V_78 )
{
struct V_2 * V_3 = V_78 ;
struct V_13 * V_92 = NULL ;
if ( V_110 || V_111 ) {
if ( V_110 )
F_25 ( L_14 ) ;
else
F_25 ( L_15 ) ;
goto V_104;
}
if ( V_3 -> V_7 -> type -> V_46 ( V_3 -> V_7 ,
V_3 -> V_90 ) < 0 ) {
F_25 ( L_16 ) ;
goto V_104;
}
if ( F_89 ( V_3 ) < 0 )
goto V_104;
F_96 ( V_3 ) ;
return;
V_104:
F_42 ( & V_3 -> V_43 ) ;
V_3 -> V_106 = 1 ;
V_92 = F_85 ( V_3 ) ;
F_43 ( & V_3 -> V_43 ) ;
F_103 ( V_92 ) ;
F_81 ( V_3 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
if ( ! F_105 ( V_87 , & V_3 -> V_88 ) )
F_96 ( V_3 ) ;
}
static int F_106 ( void * V_112 )
{
F_107 () ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_109 ( V_103 , & V_3 -> V_88 ) ;
F_110 ( & V_3 -> V_88 , V_87 , F_106 ,
V_113 ) ;
F_111 ( V_103 , & V_3 -> V_88 ) ;
}
static int F_112 ( struct V_114 * V_42 , unsigned int V_115 , char * * V_116 )
{
struct V_2 * V_3 ;
int V_21 ;
int V_51 = - V_44 ;
char * V_117 , * V_118 ;
unsigned V_119 , V_120 = 1 ;
T_6 V_121 = V_122 ;
if ( V_115 != 4 ) {
V_42 -> error = L_17 ;
V_51 = - V_44 ;
goto V_123;
}
if ( F_36 ( V_42 ) ) {
V_120 = 2 ;
V_121 = V_124 ;
}
V_3 = F_24 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 ) {
V_42 -> error = L_18 ;
V_51 = - V_26 ;
goto V_123;
}
V_117 = V_116 [ 0 ] ;
V_116 ++ ;
V_115 -- ;
V_51 = F_113 ( V_42 , V_117 , V_121 , & V_3 -> V_4 ) ;
if ( V_51 ) {
V_42 -> error = L_19 ;
goto V_125;
}
V_118 = V_116 [ 0 ] ;
V_116 ++ ;
V_115 -- ;
V_51 = F_113 ( V_42 , V_118 , F_114 ( V_42 -> V_58 ) , & V_3 -> V_5 ) ;
if ( V_51 ) {
V_42 -> error = L_20 ;
goto V_126;
}
V_51 = F_115 ( V_42 , V_115 , V_116 , V_3 , & V_119 , & V_3 -> V_7 ) ;
if ( V_51 ) {
V_42 -> error = L_21 ;
V_51 = - V_44 ;
goto V_127;
}
V_116 += V_119 ;
V_115 -= V_119 ;
V_3 -> V_42 = V_42 ;
V_3 -> V_105 = 1 ;
V_3 -> V_40 = 0 ;
F_116 ( & V_3 -> V_74 , 0 ) ;
V_3 -> V_128 = 0 ;
V_3 -> V_129 = 0 ;
F_26 ( & V_3 -> V_130 ) ;
F_27 ( & V_3 -> V_43 ) ;
F_26 ( & V_3 -> V_49 ) ;
F_117 ( & V_3 -> V_131 ) ;
V_3 -> V_88 = 0 ;
V_3 -> V_106 = 0 ;
V_3 -> V_89 = 0 ;
V_3 -> V_90 = 0 ;
F_118 ( & V_3 -> V_91 ) ;
if ( F_77 ( V_3 ) ) {
V_42 -> error = L_22 ;
V_51 = - V_26 ;
goto V_132;
}
V_3 -> V_108 = F_119 ( & V_133 ) ;
if ( F_120 ( V_3 -> V_108 ) ) {
V_51 = F_121 ( V_3 -> V_108 ) ;
V_42 -> error = L_23 ;
goto V_134;
}
V_3 -> V_73 = F_122 ( V_135 , V_136 ) ;
if ( ! V_3 -> V_73 ) {
V_42 -> error = L_24 ;
V_51 = - V_26 ;
goto V_137;
}
for ( V_21 = 0 ; V_21 < V_138 ; V_21 ++ )
F_123 ( & V_3 -> V_18 [ V_21 ] ) ;
F_117 ( & V_3 -> V_17 ) ;
V_42 -> V_139 = V_3 ;
V_42 -> V_120 = V_120 ;
V_42 -> V_140 = sizeof( struct V_14 ) ;
V_51 = F_41 ( V_3 ) ;
if ( V_51 == - V_26 ) {
V_42 -> error = L_25 ;
goto V_141;
} else if ( V_51 < 0 ) {
goto V_141;
}
if ( V_51 > 0 ) {
V_3 -> V_7 -> V_48 = 0 ;
return 0 ;
}
V_51 = V_3 -> V_7 -> type -> V_142 ( V_3 -> V_7 , F_73 ,
( void * ) V_3 ) ;
if ( V_51 < 0 ) {
V_42 -> error = L_26 ;
goto V_143;
} else if ( V_51 > 0 ) {
V_3 -> V_105 = 0 ;
F_124 ( L_27 ) ;
}
if ( ! V_3 -> V_7 -> V_48 ) {
V_42 -> error = L_28 ;
goto V_143;
}
V_51 = F_125 ( V_42 , V_3 -> V_7 -> V_48 ) ;
if ( V_51 )
goto V_143;
return 0 ;
V_143:
F_46 ( V_3 ) ;
V_141:
F_126 ( V_3 -> V_73 ) ;
V_137:
F_127 ( V_3 -> V_108 ) ;
V_134:
F_50 ( & V_3 -> V_86 , V_136 ) ;
F_50 ( & V_3 -> V_81 , V_68 ) ;
V_132:
F_128 ( V_3 -> V_7 ) ;
V_127:
F_129 ( V_42 , V_3 -> V_5 ) ;
V_126:
F_129 ( V_42 , V_3 -> V_4 ) ;
V_125:
F_29 ( V_3 ) ;
V_123:
return V_51 ;
}
static void F_130 ( struct V_2 * V_3 )
{
F_127 ( V_3 -> V_108 ) ;
V_3 -> V_108 = NULL ;
F_50 ( & V_3 -> V_86 , V_136 ) ;
F_50 ( & V_3 -> V_81 , V_68 ) ;
}
static void F_131 ( struct V_2 * V_36 ,
struct V_2 * V_37 )
{
union {
struct V_53 V_144 ;
struct V_6 * V_145 ;
} V_146 ;
V_146 . V_144 = V_37 -> V_81 ;
V_37 -> V_81 = V_36 -> V_81 ;
V_36 -> V_81 = V_146 . V_144 ;
V_146 . V_145 = V_37 -> V_7 ;
V_37 -> V_7 = V_36 -> V_7 ;
V_36 -> V_7 = V_146 . V_145 ;
V_37 -> V_7 -> V_35 = V_37 ;
V_36 -> V_7 -> V_35 = V_36 ;
V_37 -> V_42 -> V_147 = V_37 -> V_7 -> V_48 ;
V_37 -> V_105 = V_36 -> V_105 ;
V_36 -> V_105 = 0 ;
}
static void F_132 ( struct V_114 * V_42 )
{
#ifdef F_133
int V_21 ;
#endif
struct V_2 * V_3 = V_42 -> V_139 ;
struct V_2 * V_36 = NULL , * V_37 = NULL ;
F_37 ( & V_27 ) ;
( void ) F_35 ( V_3 , & V_36 , & V_37 , NULL ) ;
if ( V_36 && V_37 && ( V_3 == V_36 ) ) {
F_42 ( & V_37 -> V_43 ) ;
V_37 -> V_105 = 0 ;
F_43 ( & V_37 -> V_43 ) ;
F_25 ( L_29 ) ;
}
F_38 ( & V_27 ) ;
if ( F_36 ( V_42 ) )
F_108 ( V_3 ) ;
F_46 ( V_3 ) ;
while ( F_134 ( & V_3 -> V_74 ) )
F_22 ( 1 ) ;
F_135 () ;
#ifdef F_133
for ( V_21 = 0 ; V_21 < V_138 ; V_21 ++ )
F_97 ( ! F_136 ( & V_3 -> V_18 [ V_21 ] ) ) ;
#endif
F_130 ( V_3 ) ;
F_126 ( V_3 -> V_73 ) ;
F_128 ( V_3 -> V_7 ) ;
F_129 ( V_42 , V_3 -> V_5 ) ;
F_129 ( V_42 , V_3 -> V_4 ) ;
F_29 ( V_3 ) ;
}
static void F_90 ( struct V_13 * V_13 )
{
struct V_13 * V_148 ;
while ( V_13 ) {
V_148 = V_13 -> V_149 ;
V_13 -> V_149 = NULL ;
F_137 ( V_13 ) ;
V_13 = V_148 ;
}
}
static void F_138 ( struct V_2 * V_3 , struct V_13 * V_13 )
{
struct V_13 * V_148 ;
int V_51 ;
while ( V_13 ) {
V_148 = V_13 -> V_149 ;
V_13 -> V_149 = NULL ;
V_51 = F_139 ( V_3 -> V_4 , V_13 ) ;
if ( V_51 == V_150 )
F_137 ( V_13 ) ;
V_13 = V_148 ;
}
}
static void F_103 ( struct V_13 * V_13 )
{
struct V_13 * V_148 ;
while ( V_13 ) {
V_148 = V_13 -> V_149 ;
V_13 -> V_149 = NULL ;
F_140 ( V_13 ) ;
V_13 = V_148 ;
}
}
static void F_141 ( struct V_2 * V_3 , int V_151 )
{
if ( ! V_3 -> V_105 )
return;
if ( V_151 == - V_152 )
F_25 ( L_30 ) ;
else if ( V_151 == - V_26 )
F_25 ( L_31 ) ;
if ( V_3 -> V_7 -> type -> V_153 )
V_3 -> V_7 -> type -> V_153 ( V_3 -> V_7 ) ;
V_3 -> V_105 = 0 ;
F_142 ( V_3 -> V_42 -> V_58 ) ;
}
static void F_143 ( struct V_71 * V_72 , int V_154 )
{
struct V_62 * V_65 ;
struct V_2 * V_3 = V_72 -> V_35 ;
struct V_13 * V_155 = NULL ;
struct V_13 * V_156 = NULL ;
struct V_13 * V_157 = NULL ;
int error = 0 ;
if ( ! V_154 ) {
F_42 ( & V_3 -> V_43 ) ;
F_141 ( V_3 , - V_152 ) ;
error = 1 ;
goto V_41;
}
V_65 = F_58 ( V_69 ) ;
if ( ! V_65 ) {
F_42 ( & V_3 -> V_43 ) ;
F_141 ( V_3 , - V_26 ) ;
error = 1 ;
goto V_41;
}
* V_65 = V_72 -> V_65 ;
F_42 ( & V_3 -> V_43 ) ;
if ( ! V_3 -> V_105 ) {
F_60 ( V_65 ) ;
error = 1 ;
goto V_41;
}
F_21 ( V_3 , V_72 -> V_65 . V_66 ) ;
F_68 ( & V_3 -> V_81 , V_65 ) ;
V_41:
F_55 ( & V_72 -> V_65 ) ;
V_156 = F_86 ( & V_72 -> V_156 ) ;
V_155 = F_86 ( & V_72 -> V_155 ) ;
V_157 = V_72 -> V_157 ;
if ( V_157 ) {
V_157 -> V_158 = V_72 -> V_159 ;
V_157 -> V_160 = V_72 -> V_161 ;
F_63 ( & V_157 -> V_162 ) ;
}
F_64 ( V_72 ) ;
F_94 () ;
F_43 ( & V_3 -> V_43 ) ;
if ( error ) {
if ( V_157 )
F_140 ( V_157 ) ;
F_103 ( V_156 ) ;
} else {
if ( V_157 )
F_144 ( V_157 , 0 ) ;
F_90 ( V_156 ) ;
}
F_138 ( V_3 , V_155 ) ;
}
static void F_145 ( void * V_78 , int V_154 )
{
struct V_71 * V_72 = V_78 ;
F_143 ( V_72 , V_154 ) ;
}
static void F_146 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = V_72 -> V_35 ;
if ( F_99 ( V_72 -> V_163 ) )
F_143 ( V_72 , 0 ) ;
else
V_3 -> V_7 -> type -> V_164 ( V_3 -> V_7 , & V_72 -> V_65 ,
F_145 , V_72 ) ;
}
static void F_147 ( int V_110 , unsigned long V_111 , void * V_78 )
{
struct V_71 * V_72 = V_78 ;
struct V_2 * V_3 = V_72 -> V_35 ;
V_72 -> V_163 = V_110 || V_111 ;
if ( V_72 -> V_165 == V_3 -> V_129 ) {
V_3 -> V_129 ++ ;
F_146 ( V_72 ) ;
while ( ! F_47 ( & V_3 -> V_130 ) ) {
V_72 = F_148 ( V_3 -> V_130 . V_64 ,
struct V_71 , V_166 ) ;
if ( V_72 -> V_165 != V_3 -> V_129 )
break;
V_3 -> V_129 ++ ;
F_45 ( & V_72 -> V_166 ) ;
F_146 ( V_72 ) ;
}
} else {
struct V_24 * V_167 ;
struct V_71 * V_168 ;
F_149 (lh, &s->out_of_order_list) {
V_168 = F_148 ( V_167 , struct V_71 , V_166 ) ;
if ( V_168 -> V_165 < V_72 -> V_165 )
break;
}
F_72 ( & V_72 -> V_166 , V_167 ) ;
}
}
static void F_150 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = V_72 -> V_35 ;
struct V_98 V_99 , V_100 ;
struct V_10 * V_28 = V_3 -> V_4 -> V_28 ;
T_1 V_169 ;
V_169 = F_78 ( V_28 ) ;
V_99 . V_28 = V_28 ;
V_99 . V_107 = F_3 ( V_3 -> V_7 , V_72 -> V_65 . V_66 ) ;
V_99 . V_39 = F_79 ( ( T_1 ) V_3 -> V_7 -> V_48 , V_169 - V_99 . V_107 ) ;
V_100 . V_28 = V_3 -> V_5 -> V_28 ;
V_100 . V_107 = F_3 ( V_3 -> V_7 , V_72 -> V_65 . V_77 ) ;
V_100 . V_39 = V_99 . V_39 ;
F_102 ( V_3 -> V_108 , & V_99 , 1 , & V_100 , 0 , F_147 , V_72 ) ;
}
static void V_159 ( struct V_13 * V_13 , int error )
{
void * V_170 = V_13 -> V_160 ;
F_151 ( V_170 , 0 , error ? 1 : 0 ) ;
}
static void F_152 ( struct V_71 * V_72 ,
struct V_13 * V_13 )
{
struct V_2 * V_3 = V_72 -> V_35 ;
void * V_170 ;
V_72 -> V_157 = V_13 ;
V_72 -> V_159 = V_13 -> V_158 ;
V_72 -> V_161 = V_13 -> V_160 ;
V_170 = F_153 ( V_3 -> V_108 ,
F_147 , V_72 ) ;
V_13 -> V_158 = V_159 ;
V_13 -> V_160 = V_170 ;
F_137 ( V_13 ) ;
}
static struct V_71 *
F_154 ( struct V_2 * V_3 , T_2 V_8 )
{
struct V_62 * V_65 = F_56 ( & V_3 -> V_86 , V_8 ) ;
if ( ! V_65 )
return NULL ;
return F_155 ( V_65 , struct V_71 , V_65 ) ;
}
static struct V_71 *
F_156 ( struct V_2 * V_3 ,
struct V_71 * V_72 , T_2 V_8 )
{
struct V_71 * V_168 ;
V_168 = F_154 ( V_3 , V_8 ) ;
if ( V_168 ) {
F_64 ( V_72 ) ;
return V_168 ;
}
V_72 -> V_65 . V_66 = V_8 ;
F_118 ( & V_72 -> V_155 ) ;
F_118 ( & V_72 -> V_156 ) ;
V_72 -> V_171 = 0 ;
V_72 -> V_157 = NULL ;
if ( V_3 -> V_7 -> type -> V_172 ( V_3 -> V_7 , & V_72 -> V_65 ) ) {
F_64 ( V_72 ) ;
return NULL ;
}
V_72 -> V_165 = V_3 -> V_128 ++ ;
F_68 ( & V_3 -> V_86 , & V_72 -> V_65 ) ;
return V_72 ;
}
static void F_157 ( struct V_2 * V_3 , struct V_62 * V_65 ,
struct V_13 * V_13 , T_2 V_8 )
{
V_13 -> V_173 = V_3 -> V_5 -> V_28 ;
V_13 -> V_174 . V_175 =
F_3 ( V_3 -> V_7 , F_70 ( V_65 -> V_77 ) +
( V_8 - V_65 -> V_66 ) ) +
( V_13 -> V_174 . V_175 & V_3 -> V_7 -> V_176 ) ;
}
static int F_158 ( struct V_114 * V_42 , struct V_13 * V_13 )
{
struct V_62 * V_65 ;
struct V_2 * V_3 = V_42 -> V_139 ;
int V_51 = V_150 ;
T_2 V_8 ;
struct V_71 * V_72 = NULL ;
F_5 ( V_13 ) ;
if ( V_13 -> V_177 & V_178 ) {
V_13 -> V_173 = V_3 -> V_5 -> V_28 ;
return V_150 ;
}
V_8 = F_159 ( V_3 -> V_7 , V_13 -> V_174 . V_175 ) ;
if ( ! V_3 -> V_105 )
return - V_152 ;
F_42 ( & V_3 -> V_43 ) ;
if ( ! V_3 -> V_105 ) {
V_51 = - V_152 ;
goto V_179;
}
V_65 = F_56 ( & V_3 -> V_81 , V_8 ) ;
if ( V_65 ) {
F_157 ( V_3 , V_65 , V_13 , V_8 ) ;
goto V_179;
}
if ( F_160 ( V_13 ) == V_180 ) {
V_72 = F_154 ( V_3 , V_8 ) ;
if ( ! V_72 ) {
F_43 ( & V_3 -> V_43 ) ;
V_72 = F_61 ( V_3 ) ;
F_42 ( & V_3 -> V_43 ) ;
if ( ! V_3 -> V_105 ) {
F_64 ( V_72 ) ;
V_51 = - V_152 ;
goto V_179;
}
V_65 = F_56 ( & V_3 -> V_81 , V_8 ) ;
if ( V_65 ) {
F_64 ( V_72 ) ;
F_157 ( V_3 , V_65 , V_13 , V_8 ) ;
goto V_179;
}
V_72 = F_156 ( V_3 , V_72 , V_8 ) ;
if ( ! V_72 ) {
F_141 ( V_3 , - V_26 ) ;
V_51 = - V_152 ;
goto V_179;
}
}
F_157 ( V_3 , & V_72 -> V_65 , V_13 , V_8 ) ;
V_51 = V_181 ;
if ( ! V_72 -> V_171 &&
V_13 -> V_174 . V_182 ==
( V_3 -> V_7 -> V_48 << V_183 ) ) {
V_72 -> V_171 = 1 ;
F_43 ( & V_3 -> V_43 ) ;
F_152 ( V_72 , V_13 ) ;
goto V_41;
}
F_161 ( & V_72 -> V_156 , V_13 ) ;
if ( ! V_72 -> V_171 ) {
V_72 -> V_171 = 1 ;
F_43 ( & V_3 -> V_43 ) ;
F_150 ( V_72 ) ;
goto V_41;
}
} else {
V_13 -> V_173 = V_3 -> V_4 -> V_28 ;
F_10 ( V_3 , V_13 , V_8 ) ;
}
V_179:
F_43 ( & V_3 -> V_43 ) ;
V_41:
return V_51 ;
}
static int F_162 ( struct V_114 * V_42 , struct V_13 * V_13 )
{
struct V_62 * V_65 ;
struct V_2 * V_3 = V_42 -> V_139 ;
int V_51 = V_150 ;
T_2 V_8 ;
F_5 ( V_13 ) ;
if ( V_13 -> V_177 & V_178 ) {
if ( ! F_163 ( V_13 ) )
V_13 -> V_173 = V_3 -> V_4 -> V_28 ;
else
V_13 -> V_173 = V_3 -> V_5 -> V_28 ;
return V_150 ;
}
V_8 = F_159 ( V_3 -> V_7 , V_13 -> V_174 . V_175 ) ;
F_42 ( & V_3 -> V_43 ) ;
if ( ! V_3 -> V_105 )
goto V_184;
V_65 = F_56 ( & V_3 -> V_81 , V_8 ) ;
if ( V_65 ) {
if ( F_160 ( V_13 ) == V_180 &&
V_8 >= V_3 -> V_89 &&
V_8 < ( V_3 -> V_89 +
V_3 -> V_90 ) ) {
V_13 -> V_173 = V_3 -> V_4 -> V_28 ;
F_161 ( & V_3 -> V_91 , V_13 ) ;
V_51 = V_181 ;
goto V_179;
}
F_157 ( V_3 , V_65 , V_13 , V_8 ) ;
if ( F_160 ( V_13 ) == V_180 )
F_10 ( V_3 , V_13 , V_8 ) ;
goto V_179;
}
V_184:
V_13 -> V_173 = V_3 -> V_4 -> V_28 ;
if ( F_160 ( V_13 ) == V_180 ) {
F_43 ( & V_3 -> V_43 ) ;
return F_139 ( V_3 -> V_4 , V_13 ) ;
}
V_179:
F_43 ( & V_3 -> V_43 ) ;
return V_51 ;
}
static int F_164 ( struct V_114 * V_42 , struct V_13 * V_13 , int error )
{
struct V_2 * V_3 = V_42 -> V_139 ;
if ( F_8 ( V_13 ) )
F_15 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_165 ( struct V_114 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_139 ;
F_108 ( V_3 ) ;
}
static int F_166 ( struct V_114 * V_42 )
{
int V_51 = 0 ;
struct V_2 * V_3 = V_42 -> V_139 ;
struct V_2 * V_36 = NULL , * V_37 = NULL ;
F_37 ( & V_27 ) ;
( void ) F_35 ( V_3 , & V_36 , & V_37 , NULL ) ;
if ( V_36 && V_37 ) {
F_37 ( & V_36 -> V_43 ) ;
if ( V_3 == V_36 ) {
F_25 ( L_32
L_33 ) ;
V_51 = - V_44 ;
} else if ( ! F_167 ( V_36 -> V_42 ) ) {
F_25 ( L_34
L_35 ) ;
V_51 = - V_44 ;
}
F_38 ( & V_36 -> V_43 ) ;
}
F_38 ( & V_27 ) ;
return V_51 ;
}
static void F_168 ( struct V_114 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_139 ;
struct V_2 * V_36 = NULL , * V_37 = NULL ;
F_37 ( & V_27 ) ;
( void ) F_35 ( V_3 , & V_36 , & V_37 , NULL ) ;
if ( V_36 && V_37 ) {
F_42 ( & V_36 -> V_43 ) ;
F_169 ( & V_37 -> V_43 , V_185 ) ;
F_131 ( V_36 , V_37 ) ;
F_43 ( & V_37 -> V_43 ) ;
F_43 ( & V_36 -> V_43 ) ;
}
F_38 ( & V_27 ) ;
F_44 ( V_3 ) ;
F_42 ( & V_3 -> V_43 ) ;
V_3 -> V_40 = 1 ;
F_43 ( & V_3 -> V_43 ) ;
}
static T_3 F_170 ( struct V_10 * V_28 )
{
T_3 V_186 ;
F_37 ( & V_27 ) ;
V_186 = F_74 ( F_31 ( V_28 ) ) ;
F_38 ( & V_27 ) ;
return V_186 ;
}
static void F_171 ( struct V_114 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_139 ;
F_168 ( V_42 ) ;
V_42 -> V_147 = F_170 ( V_3 -> V_4 -> V_28 ) ;
F_104 ( V_3 ) ;
}
static void F_172 ( struct V_114 * V_42 , T_7 type ,
unsigned V_187 , char * V_188 , unsigned V_189 )
{
unsigned V_190 = 0 ;
struct V_2 * V_35 = V_42 -> V_139 ;
switch ( type ) {
case V_191 :
F_42 ( & V_35 -> V_43 ) ;
if ( ! V_35 -> V_105 )
F_173 ( L_36 ) ;
else if ( V_35 -> V_106 )
F_173 ( L_37 ) ;
else {
if ( V_35 -> V_7 -> type -> V_192 ) {
T_1 V_193 , V_194 ,
V_195 ;
V_35 -> V_7 -> type -> V_192 ( V_35 -> V_7 ,
& V_193 ,
& V_194 ,
& V_195 ) ;
F_173 ( L_38 ,
( unsigned long long ) V_194 ,
( unsigned long long ) V_193 ,
( unsigned long long ) V_195 ) ;
}
else
F_173 ( L_39 ) ;
}
F_43 ( & V_35 -> V_43 ) ;
break;
case V_196 :
F_173 ( L_40 , V_35 -> V_4 -> V_197 , V_35 -> V_5 -> V_197 ) ;
V_35 -> V_7 -> type -> V_198 ( V_35 -> V_7 , type , V_188 + V_190 ,
V_189 - V_190 ) ;
break;
}
}
static int F_174 ( struct V_114 * V_42 ,
T_8 V_199 , void * V_200 )
{
struct V_2 * V_35 = V_42 -> V_139 ;
int V_51 ;
V_51 = V_199 ( V_42 , V_35 -> V_4 , 0 , V_42 -> V_201 , V_200 ) ;
if ( ! V_51 )
V_51 = V_199 ( V_42 , V_35 -> V_5 , 0 , F_78 ( V_35 -> V_5 -> V_28 ) , V_200 ) ;
return V_51 ;
}
static int F_175 ( struct V_24 * V_52 , T_1 V_107 ,
struct V_13 * V_13 )
{
int V_51 = V_150 ;
struct V_2 * V_35 ;
struct V_62 * V_65 ;
struct V_71 * V_72 ;
struct V_71 * V_202 = NULL ;
struct V_71 * V_203 = NULL ;
T_2 V_8 ;
F_32 (snap, snapshots, list) {
if ( F_36 ( V_35 -> V_42 ) )
continue;
F_42 ( & V_35 -> V_43 ) ;
if ( ! V_35 -> V_105 || ! V_35 -> V_40 )
goto V_204;
if ( V_107 >= F_176 ( V_35 -> V_42 -> V_58 ) )
goto V_204;
V_8 = F_159 ( V_35 -> V_7 , V_107 ) ;
V_65 = F_56 ( & V_35 -> V_81 , V_8 ) ;
if ( V_65 )
goto V_204;
V_72 = F_154 ( V_35 , V_8 ) ;
if ( ! V_72 ) {
F_43 ( & V_35 -> V_43 ) ;
V_72 = F_61 ( V_35 ) ;
F_42 ( & V_35 -> V_43 ) ;
if ( ! V_35 -> V_105 ) {
F_64 ( V_72 ) ;
goto V_204;
}
V_65 = F_56 ( & V_35 -> V_81 , V_8 ) ;
if ( V_65 ) {
F_64 ( V_72 ) ;
goto V_204;
}
V_72 = F_156 ( V_35 , V_72 , V_8 ) ;
if ( ! V_72 ) {
F_141 ( V_35 , - V_26 ) ;
goto V_204;
}
}
V_51 = V_181 ;
if ( V_13 ) {
F_161 ( & V_72 -> V_155 , V_13 ) ;
V_13 = NULL ;
if ( ! V_72 -> V_171 ) {
V_72 -> V_171 = 1 ;
V_203 = V_72 ;
}
}
if ( ! V_72 -> V_171 ) {
V_72 -> V_171 = 1 ;
V_202 = V_72 ;
}
V_204:
F_43 ( & V_35 -> V_43 ) ;
if ( V_202 ) {
F_150 ( V_202 ) ;
V_202 = NULL ;
}
}
if ( V_203 )
F_150 ( V_203 ) ;
return V_51 ;
}
static int F_139 ( struct V_1 * V_4 , struct V_13 * V_13 )
{
struct V_4 * V_32 ;
int V_51 = V_150 ;
F_37 ( & V_27 ) ;
V_32 = F_31 ( V_4 -> V_28 ) ;
if ( V_32 )
V_51 = F_175 ( & V_32 -> V_52 , V_13 -> V_174 . V_175 , V_13 ) ;
F_38 ( & V_27 ) ;
return V_51 ;
}
static int F_100 ( struct V_2 * V_205 ,
T_1 V_107 , unsigned V_55 )
{
int V_206 = 0 ;
T_1 V_148 ;
struct V_4 * V_32 ;
F_37 ( & V_27 ) ;
V_32 = F_31 ( V_205 -> V_4 -> V_28 ) ;
for ( V_148 = 0 ; V_148 < V_55 ; V_148 += V_205 -> V_42 -> V_147 )
if ( F_175 ( & V_32 -> V_52 , V_107 + V_148 , NULL ) ==
V_181 )
V_206 = 1 ;
F_38 ( & V_27 ) ;
return V_206 ;
}
static int F_177 ( struct V_114 * V_42 , unsigned int V_115 , char * * V_116 )
{
int V_51 ;
struct V_1 * V_207 ;
if ( V_115 != 1 ) {
V_42 -> error = L_41 ;
return - V_44 ;
}
V_51 = F_113 ( V_42 , V_116 [ 0 ] , F_114 ( V_42 -> V_58 ) , & V_207 ) ;
if ( V_51 ) {
V_42 -> error = L_42 ;
return V_51 ;
}
V_42 -> V_139 = V_207 ;
V_42 -> V_120 = 1 ;
return 0 ;
}
static void F_178 ( struct V_114 * V_42 )
{
struct V_1 * V_207 = V_42 -> V_139 ;
F_129 ( V_42 , V_207 ) ;
}
static int F_179 ( struct V_114 * V_42 , struct V_13 * V_13 )
{
struct V_1 * V_207 = V_42 -> V_139 ;
V_13 -> V_173 = V_207 -> V_28 ;
if ( V_13 -> V_177 & V_178 )
return V_150 ;
return ( F_160 ( V_13 ) == V_180 ) ? F_139 ( V_207 , V_13 ) : V_150 ;
}
static void F_180 ( struct V_114 * V_42 )
{
struct V_1 * V_207 = V_42 -> V_139 ;
V_42 -> V_147 = F_170 ( V_207 -> V_28 ) ;
}
static void F_181 ( struct V_114 * V_42 , T_7 type ,
unsigned V_187 , char * V_188 , unsigned V_189 )
{
struct V_1 * V_207 = V_42 -> V_139 ;
switch ( type ) {
case V_191 :
V_188 [ 0 ] = '\0' ;
break;
case V_196 :
snprintf ( V_188 , V_189 , L_43 , V_207 -> V_197 ) ;
break;
}
}
static int F_182 ( struct V_114 * V_42 , struct V_208 * V_209 ,
struct V_210 * V_211 , int V_212 )
{
struct V_1 * V_207 = V_42 -> V_139 ;
struct V_213 * V_214 = F_183 ( V_207 -> V_28 ) ;
if ( ! V_214 -> V_215 )
return V_212 ;
V_209 -> V_173 = V_207 -> V_28 ;
return F_79 ( V_212 , V_214 -> V_215 ( V_214 , V_209 , V_211 ) ) ;
}
static int F_184 ( struct V_114 * V_42 ,
T_8 V_199 , void * V_200 )
{
struct V_1 * V_207 = V_42 -> V_139 ;
return V_199 ( V_42 , V_207 , 0 , V_42 -> V_201 , V_200 ) ;
}
static int T_9 F_185 ( void )
{
int V_51 ;
V_51 = F_186 () ;
if ( V_51 ) {
F_25 ( L_44 ) ;
return V_51 ;
}
V_51 = F_187 ( & V_216 ) ;
if ( V_51 < 0 ) {
F_25 ( L_45 , V_51 ) ;
goto V_217;
}
V_51 = F_187 ( & V_218 ) ;
if ( V_51 < 0 ) {
F_25 ( L_46 , V_51 ) ;
goto V_219;
}
V_51 = F_187 ( & V_220 ) ;
if ( V_51 < 0 ) {
F_25 ( L_47 , V_51 ) ;
goto V_221;
}
V_51 = F_23 () ;
if ( V_51 ) {
F_25 ( L_48 ) ;
goto V_222;
}
V_68 = F_188 ( V_62 , 0 ) ;
if ( ! V_68 ) {
F_25 ( L_49 ) ;
V_51 = - V_26 ;
goto V_223;
}
V_136 = F_188 ( V_71 , 0 ) ;
if ( ! V_136 ) {
F_25 ( L_50 ) ;
V_51 = - V_26 ;
goto V_224;
}
return 0 ;
V_224:
F_189 ( V_68 ) ;
V_223:
F_28 () ;
V_222:
F_190 ( & V_220 ) ;
V_221:
F_190 ( & V_218 ) ;
V_219:
F_190 ( & V_216 ) ;
V_217:
F_191 () ;
return V_51 ;
}
static void T_10 F_192 ( void )
{
F_190 ( & V_216 ) ;
F_190 ( & V_218 ) ;
F_190 ( & V_220 ) ;
F_28 () ;
F_189 ( V_136 ) ;
F_189 ( V_68 ) ;
F_191 () ;
}
