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
struct V_20 * V_21 ;
int V_22 = 0 ;
F_11 ( & V_3 -> V_17 ) ;
F_20 (c, hn,
&s->tracked_chunk_hash[DM_TRACKED_CHUNK_HASH(chunk)], node) {
if ( V_15 -> V_8 == V_8 ) {
V_22 = 1 ;
break;
}
}
F_14 ( & V_3 -> V_17 ) ;
return V_22 ;
}
static void F_21 ( struct V_2 * V_3 , T_2 V_8 )
{
while ( F_19 ( V_3 , V_8 ) )
F_22 ( 1 ) ;
}
static int F_23 ( void )
{
int V_23 ;
V_24 = F_24 ( V_25 * sizeof( struct V_26 ) ,
V_27 ) ;
if ( ! V_24 ) {
F_25 ( L_1 ) ;
return - V_28 ;
}
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ )
F_26 ( V_24 + V_23 ) ;
F_27 ( & V_29 ) ;
return 0 ;
}
static void F_28 ( void )
{
F_29 ( V_24 ) ;
}
static unsigned F_30 ( struct V_10 * V_30 )
{
return V_30 -> V_31 & V_32 ;
}
static struct V_4 * F_31 ( struct V_10 * V_4 )
{
struct V_26 * V_33 ;
struct V_4 * V_34 ;
V_33 = & V_24 [ F_30 ( V_4 ) ] ;
F_32 (o, ol, hash_list)
if ( F_4 ( V_34 -> V_30 , V_4 ) )
return V_34 ;
return NULL ;
}
static void F_33 ( struct V_4 * V_34 )
{
struct V_26 * V_35 = & V_24 [ F_30 ( V_34 -> V_30 ) ] ;
F_34 ( & V_34 -> V_36 , V_35 ) ;
}
static int F_35 ( struct V_2 * V_37 ,
struct V_2 * * V_38 ,
struct V_2 * * V_39 ,
struct V_2 * * V_40 )
{
struct V_2 * V_3 ;
struct V_4 * V_34 ;
int V_41 = 0 ;
int V_42 ;
V_34 = F_31 ( V_37 -> V_4 -> V_30 ) ;
if ( ! V_34 )
goto V_43;
F_32 (s, &o->snapshots, list) {
if ( F_36 ( V_3 -> V_44 ) && V_40 )
* V_40 = V_3 ;
if ( ! F_4 ( V_3 -> V_5 -> V_30 , V_37 -> V_5 -> V_30 ) )
continue;
F_37 ( & V_3 -> V_45 ) ;
V_42 = V_3 -> V_42 ;
F_38 ( & V_3 -> V_45 ) ;
if ( V_42 ) {
if ( V_38 )
* V_38 = V_3 ;
} else if ( V_39 )
* V_39 = V_3 ;
V_41 ++ ;
}
V_43:
return V_41 ;
}
static int F_39 ( struct V_2 * V_37 )
{
struct V_2 * V_38 = NULL , * V_39 = NULL ;
struct V_2 * V_40 = NULL ;
if ( ( F_35 ( V_37 , & V_38 , & V_39 ,
& V_40 ) == 2 ) ||
V_39 ) {
V_37 -> V_44 -> error = L_2
L_3 ;
return - V_46 ;
}
if ( ! V_38 )
return 0 ;
if ( ! F_36 ( V_37 -> V_44 ) )
return 1 ;
if ( V_40 ) {
V_37 -> V_44 -> error = L_4 ;
return - V_46 ;
}
if ( ! V_38 -> V_7 -> type -> V_47 ||
! V_38 -> V_7 -> type -> V_48 ) {
V_37 -> V_44 -> error = L_5
L_6 ;
return - V_46 ;
}
return 1 ;
}
static void F_40 ( struct V_4 * V_34 , struct V_2 * V_3 )
{
struct V_2 * V_49 ;
F_32 (l, &o->snapshots, list)
if ( V_49 -> V_7 -> V_50 < V_3 -> V_7 -> V_50 )
break;
F_34 ( & V_3 -> V_51 , & V_49 -> V_51 ) ;
}
static int F_41 ( struct V_2 * V_37 )
{
struct V_4 * V_34 , * V_52 = NULL ;
struct V_10 * V_30 = V_37 -> V_4 -> V_30 ;
int V_53 = 0 ;
V_52 = F_24 ( sizeof( * V_52 ) , V_27 ) ;
if ( ! V_52 )
return - V_28 ;
F_42 ( & V_29 ) ;
V_53 = F_39 ( V_37 ) ;
if ( V_53 < 0 ) {
F_29 ( V_52 ) ;
goto V_43;
}
V_34 = F_31 ( V_30 ) ;
if ( V_34 )
F_29 ( V_52 ) ;
else {
V_34 = V_52 ;
F_26 ( & V_34 -> V_54 ) ;
V_34 -> V_30 = V_30 ;
F_33 ( V_34 ) ;
}
F_40 ( V_34 , V_37 ) ;
V_43:
F_43 ( & V_29 ) ;
return V_53 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_10 * V_30 = V_3 -> V_4 -> V_30 ;
F_42 ( & V_29 ) ;
F_45 ( & V_3 -> V_51 ) ;
F_40 ( F_31 ( V_30 ) , V_3 ) ;
F_43 ( & V_29 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_4 * V_34 ;
F_42 ( & V_29 ) ;
V_34 = F_31 ( V_3 -> V_4 -> V_30 ) ;
F_45 ( & V_3 -> V_51 ) ;
if ( V_34 && F_47 ( & V_34 -> V_54 ) ) {
F_45 ( & V_34 -> V_36 ) ;
F_29 ( V_34 ) ;
}
F_43 ( & V_29 ) ;
}
static int F_48 ( struct V_55 * V_56 ,
T_3 V_57 , unsigned V_58 )
{
unsigned int V_23 ;
V_56 -> V_58 = V_58 ;
V_56 -> V_59 = V_57 - 1 ;
V_56 -> V_60 = F_49 ( V_57 , sizeof( struct V_26 ) ) ;
if ( ! V_56 -> V_60 )
return - V_28 ;
for ( V_23 = 0 ; V_23 < V_57 ; V_23 ++ )
F_26 ( V_56 -> V_60 + V_23 ) ;
return 0 ;
}
static void F_50 ( struct V_55 * V_56 ,
struct V_61 * V_62 )
{
struct V_26 * V_63 ;
struct V_64 * V_65 , * V_66 ;
int V_23 , V_57 ;
V_57 = V_56 -> V_59 + 1 ;
for ( V_23 = 0 ; V_23 < V_57 ; V_23 ++ ) {
V_63 = V_56 -> V_60 + V_23 ;
F_51 (ex, next, slot, hash_list)
F_52 ( V_62 , V_65 ) ;
}
F_53 ( V_56 -> V_60 ) ;
}
static T_3 F_54 ( struct V_55 * V_56 , T_2 V_8 )
{
return ( V_8 >> V_56 -> V_58 ) & V_56 -> V_59 ;
}
static void F_55 ( struct V_64 * V_67 )
{
F_45 ( & V_67 -> V_36 ) ;
}
static struct V_64 * F_56 ( struct V_55 * V_56 ,
T_2 V_8 )
{
struct V_26 * V_63 ;
struct V_64 * V_67 ;
V_63 = & V_56 -> V_60 [ F_54 ( V_56 , V_8 ) ] ;
F_32 (e, slot, hash_list)
if ( V_8 >= V_67 -> V_68 &&
V_8 <= V_67 -> V_68 + F_57 ( V_67 ) )
return V_67 ;
return NULL ;
}
static struct V_64 * F_58 ( void )
{
struct V_64 * V_67 ;
V_67 = F_59 ( V_69 , V_70 ) ;
if ( ! V_67 )
V_67 = F_59 ( V_69 , V_71 ) ;
return V_67 ;
}
static void F_60 ( struct V_64 * V_67 )
{
F_52 ( V_69 , V_67 ) ;
}
static struct V_72 * F_61 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = F_62 ( V_3 -> V_74 ,
V_70 ) ;
F_63 ( & V_3 -> V_75 ) ;
V_73 -> V_37 = V_3 ;
return V_73 ;
}
static void F_64 ( struct V_72 * V_73 )
{
struct V_2 * V_3 = V_73 -> V_37 ;
F_65 ( V_73 , V_3 -> V_74 ) ;
F_66 () ;
F_67 ( & V_3 -> V_75 ) ;
}
static void F_68 ( struct V_55 * V_76 ,
struct V_64 * V_77 )
{
struct V_26 * V_49 ;
struct V_64 * V_67 = NULL ;
V_49 = & V_76 -> V_60 [ F_54 ( V_76 , V_77 -> V_68 ) ] ;
if ( ! V_76 -> V_58 )
goto V_43;
F_69 (e, l, hash_list) {
if ( V_77 -> V_68 == ( V_67 -> V_68 +
F_57 ( V_67 ) + 1 ) &&
V_77 -> V_78 == ( F_70 ( V_67 -> V_78 ) +
F_57 ( V_67 ) + 1 ) ) {
F_71 ( V_67 ) ;
F_60 ( V_77 ) ;
return;
}
if ( V_77 -> V_68 == ( V_67 -> V_68 - 1 ) &&
V_77 -> V_78 == ( F_70 ( V_67 -> V_78 ) - 1 ) ) {
F_71 ( V_67 ) ;
V_67 -> V_68 -- ;
V_67 -> V_78 -- ;
F_60 ( V_77 ) ;
return;
}
if ( V_77 -> V_68 > V_67 -> V_68 )
break;
}
V_43:
F_72 ( & V_77 -> V_36 , V_67 ? & V_67 -> V_36 : V_49 ) ;
}
static int F_73 ( void * V_79 , T_2 V_80 , T_2 V_81 )
{
struct V_2 * V_3 = V_79 ;
struct V_64 * V_67 ;
V_67 = F_58 () ;
if ( ! V_67 )
return - V_28 ;
V_67 -> V_68 = V_80 ;
V_67 -> V_78 = V_81 ;
F_68 ( & V_3 -> V_82 , V_67 ) ;
return 0 ;
}
static T_3 F_74 ( struct V_4 * V_34 )
{
struct V_2 * V_37 ;
unsigned V_50 = 0 ;
if ( V_34 )
F_32 (snap, &o->snapshots, list)
V_50 = F_75 ( V_50 ,
V_37 -> V_7 -> V_50 ) ;
return ( T_3 ) V_50 ;
}
static int F_76 ( void )
{
unsigned long V_62 = 2 * 1024 * 1024 ;
V_62 /= sizeof( struct V_26 ) ;
return V_62 ;
}
static int F_77 ( struct V_2 * V_3 )
{
T_1 V_83 , V_84 , V_85 , V_86 ;
V_84 = F_78 ( V_3 -> V_5 -> V_30 ) ;
V_85 = F_78 ( V_3 -> V_4 -> V_30 ) ;
V_86 = F_76 () ;
V_83 = F_79 ( V_85 , V_84 ) >> V_3 -> V_7 -> V_9 ;
V_83 = F_79 ( V_83 , V_86 ) ;
if ( V_83 < 64 )
V_83 = 64 ;
V_83 = F_80 ( V_83 ) ;
if ( F_48 ( & V_3 -> V_82 , V_83 ,
V_87 ) )
return - V_28 ;
V_83 >>= 3 ;
if ( V_83 < 64 )
V_83 = 64 ;
if ( F_48 ( & V_3 -> V_88 , V_83 , 0 ) ) {
F_50 ( & V_3 -> V_82 , V_69 ) ;
return - V_28 ;
}
return 0 ;
}
static void F_81 ( struct V_2 * V_3 )
{
F_82 ( V_89 , & V_3 -> V_90 ) ;
F_83 () ;
F_84 ( & V_3 -> V_90 , V_89 ) ;
}
static struct V_13 * F_85 ( struct V_2 * V_3 )
{
V_3 -> V_91 = 0 ;
V_3 -> V_92 = 0 ;
return F_86 ( & V_3 -> V_93 ) ;
}
static int F_87 ( struct V_2 * V_3 ,
T_2 V_68 )
{
struct V_64 * V_67 ;
V_67 = F_56 ( & V_3 -> V_82 , V_68 ) ;
if ( ! V_67 ) {
F_25 ( L_7
L_8 ,
( unsigned long long ) V_68 ) ;
return - V_46 ;
}
if ( ! F_57 ( V_67 ) ) {
F_55 ( V_67 ) ;
F_60 ( V_67 ) ;
return 0 ;
}
if ( V_68 == V_67 -> V_68 ) {
V_67 -> V_68 ++ ;
V_67 -> V_78 ++ ;
} else if ( V_68 != V_67 -> V_68 +
F_57 ( V_67 ) ) {
F_25 ( L_9
L_10 ,
( unsigned long long ) V_68 ,
( unsigned long long ) V_67 -> V_68 ,
( unsigned long long )
V_67 -> V_68 + F_57 ( V_67 ) ) ;
return - V_46 ;
}
F_88 ( V_67 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_13 * V_94 = NULL ;
int V_53 ;
T_2 V_68 = V_3 -> V_91 + V_3 -> V_92 - 1 ;
F_42 ( & V_3 -> V_45 ) ;
do {
V_53 = F_87 ( V_3 , V_68 ) ;
if ( V_53 )
goto V_43;
} while ( V_68 -- > V_3 -> V_91 );
V_94 = F_85 ( V_3 ) ;
V_43:
F_43 ( & V_3 -> V_45 ) ;
if ( V_94 )
F_90 ( V_94 ) ;
return V_53 ;
}
static T_4 F_91 ( void )
{
T_4 V_95 ;
F_92 ( & V_96 ) ;
V_95 = V_97 ;
F_93 ( & V_96 ) ;
return V_95 ;
}
static void F_94 ( void )
{
F_92 ( & V_96 ) ;
V_97 ++ ;
F_93 ( & V_96 ) ;
F_95 ( & V_98 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
int V_23 , V_99 ;
T_2 V_68 , V_78 ;
struct V_100 V_101 , V_102 ;
T_1 V_103 ;
T_4 V_104 ;
F_97 ( ! F_98 ( V_89 , & V_3 -> V_90 ) ) ;
if ( F_99 ( F_98 ( V_105 , & V_3 -> V_90 ) ) )
goto V_106;
if ( ! V_3 -> V_107 ) {
F_25 ( L_11 ) ;
goto V_106;
}
V_99 = V_3 -> V_7 -> type -> V_47 ( V_3 -> V_7 , & V_68 ,
& V_78 ) ;
if ( V_99 <= 0 ) {
if ( V_99 < 0 ) {
F_25 ( L_12
L_13 ) ;
F_42 ( & V_3 -> V_45 ) ;
V_3 -> V_108 = 1 ;
F_43 ( & V_3 -> V_45 ) ;
}
goto V_106;
}
V_68 = V_68 + 1 - V_99 ;
V_78 = V_78 + 1 - V_99 ;
V_103 = V_99 * V_3 -> V_7 -> V_50 ;
V_102 . V_30 = V_3 -> V_4 -> V_30 ;
V_102 . V_109 = F_3 ( V_3 -> V_7 , V_68 ) ;
V_102 . V_41 = F_79 ( V_103 , F_78 ( V_102 . V_30 ) - V_102 . V_109 ) ;
V_101 . V_30 = V_3 -> V_5 -> V_30 ;
V_101 . V_109 = F_3 ( V_3 -> V_7 , V_78 ) ;
V_101 . V_41 = V_102 . V_41 ;
V_104 = F_91 () ;
while ( F_100 ( V_3 , V_102 . V_109 , V_103 ) ) {
F_101 ( V_98 ,
( F_91 () !=
V_104 ) ) ;
V_104 = F_91 () ;
}
F_42 ( & V_3 -> V_45 ) ;
V_3 -> V_91 = V_68 ;
V_3 -> V_92 = V_99 ;
F_43 ( & V_3 -> V_45 ) ;
for ( V_23 = 0 ; V_23 < V_99 ; V_23 ++ )
F_21 ( V_3 , V_68 + V_23 ) ;
F_102 ( V_3 -> V_110 , & V_101 , 1 , & V_102 , 0 , V_111 , V_3 ) ;
return;
V_106:
F_81 ( V_3 ) ;
}
static void V_111 ( int V_112 , unsigned long V_113 , void * V_79 )
{
struct V_2 * V_3 = V_79 ;
struct V_13 * V_94 = NULL ;
if ( V_112 || V_113 ) {
if ( V_112 )
F_25 ( L_14 ) ;
else
F_25 ( L_15 ) ;
goto V_106;
}
if ( V_3 -> V_7 -> type -> V_48 ( V_3 -> V_7 ,
V_3 -> V_92 ) < 0 ) {
F_25 ( L_16 ) ;
goto V_106;
}
if ( F_89 ( V_3 ) < 0 )
goto V_106;
F_96 ( V_3 ) ;
return;
V_106:
F_42 ( & V_3 -> V_45 ) ;
V_3 -> V_108 = 1 ;
V_94 = F_85 ( V_3 ) ;
F_43 ( & V_3 -> V_45 ) ;
F_103 ( V_94 ) ;
F_81 ( V_3 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
if ( ! F_105 ( V_89 , & V_3 -> V_90 ) )
F_96 ( V_3 ) ;
}
static int F_106 ( void * V_114 )
{
F_107 () ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_109 ( V_105 , & V_3 -> V_90 ) ;
F_110 ( & V_3 -> V_90 , V_89 , F_106 ,
V_115 ) ;
F_111 ( V_105 , & V_3 -> V_90 ) ;
}
static int F_112 ( struct V_116 * V_44 , unsigned int V_117 , char * * V_118 )
{
struct V_2 * V_3 ;
int V_23 ;
int V_53 = - V_46 ;
char * V_119 , * V_120 ;
unsigned V_121 , V_122 = 1 ;
T_5 V_123 = V_124 ;
if ( V_117 != 4 ) {
V_44 -> error = L_17 ;
V_53 = - V_46 ;
goto V_125;
}
if ( F_36 ( V_44 ) ) {
V_122 = 2 ;
V_123 = V_126 ;
}
V_3 = F_24 ( sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 ) {
V_44 -> error = L_18 ;
V_53 = - V_28 ;
goto V_125;
}
V_119 = V_118 [ 0 ] ;
V_118 ++ ;
V_117 -- ;
V_53 = F_113 ( V_44 , V_119 , V_123 , & V_3 -> V_4 ) ;
if ( V_53 ) {
V_44 -> error = L_19 ;
goto V_127;
}
V_120 = V_118 [ 0 ] ;
V_118 ++ ;
V_117 -- ;
V_53 = F_113 ( V_44 , V_120 , F_114 ( V_44 -> V_60 ) , & V_3 -> V_5 ) ;
if ( V_53 ) {
V_44 -> error = L_20 ;
goto V_128;
}
V_53 = F_115 ( V_44 , V_117 , V_118 , V_3 , & V_121 , & V_3 -> V_7 ) ;
if ( V_53 ) {
V_44 -> error = L_21 ;
V_53 = - V_46 ;
goto V_129;
}
V_118 += V_121 ;
V_117 -= V_121 ;
V_3 -> V_44 = V_44 ;
V_3 -> V_107 = 1 ;
V_3 -> V_42 = 0 ;
F_116 ( & V_3 -> V_75 , 0 ) ;
F_27 ( & V_3 -> V_45 ) ;
F_26 ( & V_3 -> V_51 ) ;
F_117 ( & V_3 -> V_130 ) ;
V_3 -> V_90 = 0 ;
V_3 -> V_108 = 0 ;
V_3 -> V_91 = 0 ;
V_3 -> V_92 = 0 ;
F_118 ( & V_3 -> V_93 ) ;
if ( F_77 ( V_3 ) ) {
V_44 -> error = L_22 ;
V_53 = - V_28 ;
goto V_131;
}
V_3 -> V_110 = F_119 () ;
if ( F_120 ( V_3 -> V_110 ) ) {
V_53 = F_121 ( V_3 -> V_110 ) ;
V_44 -> error = L_23 ;
goto V_132;
}
V_3 -> V_74 = F_122 ( V_133 , V_134 ) ;
if ( ! V_3 -> V_74 ) {
V_44 -> error = L_24 ;
goto V_135;
}
for ( V_23 = 0 ; V_23 < V_136 ; V_23 ++ )
F_123 ( & V_3 -> V_18 [ V_23 ] ) ;
F_117 ( & V_3 -> V_17 ) ;
V_44 -> V_137 = V_3 ;
V_44 -> V_122 = V_122 ;
V_44 -> V_138 = sizeof( struct V_14 ) ;
V_53 = F_41 ( V_3 ) ;
if ( V_53 == - V_28 ) {
V_44 -> error = L_25 ;
goto V_139;
} else if ( V_53 < 0 ) {
goto V_139;
}
if ( V_53 > 0 ) {
V_3 -> V_7 -> V_50 = 0 ;
return 0 ;
}
V_53 = V_3 -> V_7 -> type -> V_140 ( V_3 -> V_7 , F_73 ,
( void * ) V_3 ) ;
if ( V_53 < 0 ) {
V_44 -> error = L_26 ;
goto V_141;
} else if ( V_53 > 0 ) {
V_3 -> V_107 = 0 ;
F_124 ( L_27 ) ;
}
if ( ! V_3 -> V_7 -> V_50 ) {
V_44 -> error = L_28 ;
goto V_141;
}
V_53 = F_125 ( V_44 , V_3 -> V_7 -> V_50 ) ;
if ( V_53 )
goto V_141;
return 0 ;
V_141:
F_46 ( V_3 ) ;
V_139:
F_126 ( V_3 -> V_74 ) ;
V_135:
F_127 ( V_3 -> V_110 ) ;
V_132:
F_50 ( & V_3 -> V_88 , V_134 ) ;
F_50 ( & V_3 -> V_82 , V_69 ) ;
V_131:
F_128 ( V_3 -> V_7 ) ;
V_129:
F_129 ( V_44 , V_3 -> V_5 ) ;
V_128:
F_129 ( V_44 , V_3 -> V_4 ) ;
V_127:
F_29 ( V_3 ) ;
V_125:
return V_53 ;
}
static void F_130 ( struct V_2 * V_3 )
{
F_127 ( V_3 -> V_110 ) ;
V_3 -> V_110 = NULL ;
F_50 ( & V_3 -> V_88 , V_134 ) ;
F_50 ( & V_3 -> V_82 , V_69 ) ;
}
static void F_131 ( struct V_2 * V_38 ,
struct V_2 * V_39 )
{
union {
struct V_55 V_142 ;
struct V_6 * V_143 ;
} V_144 ;
V_144 . V_142 = V_39 -> V_82 ;
V_39 -> V_82 = V_38 -> V_82 ;
V_38 -> V_82 = V_144 . V_142 ;
V_144 . V_143 = V_39 -> V_7 ;
V_39 -> V_7 = V_38 -> V_7 ;
V_38 -> V_7 = V_144 . V_143 ;
V_39 -> V_7 -> V_37 = V_39 ;
V_38 -> V_7 -> V_37 = V_38 ;
V_39 -> V_44 -> V_145 = V_39 -> V_7 -> V_50 ;
V_39 -> V_107 = V_38 -> V_107 ;
V_38 -> V_107 = 0 ;
}
static void F_132 ( struct V_116 * V_44 )
{
#ifdef F_133
int V_23 ;
#endif
struct V_2 * V_3 = V_44 -> V_137 ;
struct V_2 * V_38 = NULL , * V_39 = NULL ;
F_37 ( & V_29 ) ;
( void ) F_35 ( V_3 , & V_38 , & V_39 , NULL ) ;
if ( V_38 && V_39 && ( V_3 == V_38 ) ) {
F_42 ( & V_39 -> V_45 ) ;
V_39 -> V_107 = 0 ;
F_43 ( & V_39 -> V_45 ) ;
F_25 ( L_29 ) ;
}
F_38 ( & V_29 ) ;
if ( F_36 ( V_44 ) )
F_108 ( V_3 ) ;
F_46 ( V_3 ) ;
while ( F_134 ( & V_3 -> V_75 ) )
F_22 ( 1 ) ;
F_135 () ;
#ifdef F_133
for ( V_23 = 0 ; V_23 < V_136 ; V_23 ++ )
F_97 ( ! F_136 ( & V_3 -> V_18 [ V_23 ] ) ) ;
#endif
F_130 ( V_3 ) ;
F_126 ( V_3 -> V_74 ) ;
F_128 ( V_3 -> V_7 ) ;
F_129 ( V_44 , V_3 -> V_5 ) ;
F_129 ( V_44 , V_3 -> V_4 ) ;
F_29 ( V_3 ) ;
}
static void F_90 ( struct V_13 * V_13 )
{
struct V_13 * V_146 ;
while ( V_13 ) {
V_146 = V_13 -> V_147 ;
V_13 -> V_147 = NULL ;
F_137 ( V_13 ) ;
V_13 = V_146 ;
}
}
static void F_138 ( struct V_2 * V_3 , struct V_13 * V_13 )
{
struct V_13 * V_146 ;
int V_53 ;
while ( V_13 ) {
V_146 = V_13 -> V_147 ;
V_13 -> V_147 = NULL ;
V_53 = F_139 ( V_3 -> V_4 , V_13 ) ;
if ( V_53 == V_148 )
F_137 ( V_13 ) ;
V_13 = V_146 ;
}
}
static void F_103 ( struct V_13 * V_13 )
{
struct V_13 * V_146 ;
while ( V_13 ) {
V_146 = V_13 -> V_147 ;
V_13 -> V_147 = NULL ;
F_140 ( V_13 ) ;
V_13 = V_146 ;
}
}
static void F_141 ( struct V_2 * V_3 , int V_149 )
{
if ( ! V_3 -> V_107 )
return;
if ( V_149 == - V_150 )
F_25 ( L_30 ) ;
else if ( V_149 == - V_28 )
F_25 ( L_31 ) ;
if ( V_3 -> V_7 -> type -> V_151 )
V_3 -> V_7 -> type -> V_151 ( V_3 -> V_7 ) ;
V_3 -> V_107 = 0 ;
F_142 ( V_3 -> V_44 -> V_60 ) ;
}
static void F_143 ( struct V_72 * V_73 , int V_152 )
{
struct V_64 * V_67 ;
struct V_2 * V_3 = V_73 -> V_37 ;
struct V_13 * V_153 = NULL ;
struct V_13 * V_154 = NULL ;
struct V_13 * V_155 = NULL ;
int error = 0 ;
if ( ! V_152 ) {
F_42 ( & V_3 -> V_45 ) ;
F_141 ( V_3 , - V_150 ) ;
error = 1 ;
goto V_43;
}
V_67 = F_58 () ;
if ( ! V_67 ) {
F_42 ( & V_3 -> V_45 ) ;
F_141 ( V_3 , - V_28 ) ;
error = 1 ;
goto V_43;
}
* V_67 = V_73 -> V_67 ;
F_42 ( & V_3 -> V_45 ) ;
if ( ! V_3 -> V_107 ) {
F_60 ( V_67 ) ;
error = 1 ;
goto V_43;
}
F_21 ( V_3 , V_73 -> V_67 . V_68 ) ;
F_68 ( & V_3 -> V_82 , V_67 ) ;
V_43:
F_55 ( & V_73 -> V_67 ) ;
V_154 = F_86 ( & V_73 -> V_154 ) ;
V_153 = F_86 ( & V_73 -> V_153 ) ;
V_155 = V_73 -> V_155 ;
if ( V_155 ) {
V_155 -> V_156 = V_73 -> V_157 ;
V_155 -> V_158 = V_73 -> V_159 ;
}
F_64 ( V_73 ) ;
F_94 () ;
F_43 ( & V_3 -> V_45 ) ;
if ( error ) {
if ( V_155 )
F_140 ( V_155 ) ;
F_103 ( V_154 ) ;
} else {
if ( V_155 )
F_144 ( V_155 , 0 ) ;
F_90 ( V_154 ) ;
}
F_138 ( V_3 , V_153 ) ;
}
static void F_145 ( void * V_79 , int V_152 )
{
struct V_72 * V_73 = V_79 ;
F_143 ( V_73 , V_152 ) ;
}
static void F_146 ( int V_112 , unsigned long V_113 , void * V_79 )
{
struct V_72 * V_73 = V_79 ;
struct V_2 * V_3 = V_73 -> V_37 ;
if ( V_112 || V_113 )
F_143 ( V_73 , 0 ) ;
else
V_3 -> V_7 -> type -> V_160 ( V_3 -> V_7 , & V_73 -> V_67 ,
F_145 , V_73 ) ;
}
static void F_147 ( struct V_72 * V_73 )
{
struct V_2 * V_3 = V_73 -> V_37 ;
struct V_100 V_101 , V_102 ;
struct V_10 * V_30 = V_3 -> V_4 -> V_30 ;
T_1 V_161 ;
V_161 = F_78 ( V_30 ) ;
V_101 . V_30 = V_30 ;
V_101 . V_109 = F_3 ( V_3 -> V_7 , V_73 -> V_67 . V_68 ) ;
V_101 . V_41 = F_79 ( ( T_1 ) V_3 -> V_7 -> V_50 , V_161 - V_101 . V_109 ) ;
V_102 . V_30 = V_3 -> V_5 -> V_30 ;
V_102 . V_109 = F_3 ( V_3 -> V_7 , V_73 -> V_67 . V_78 ) ;
V_102 . V_41 = V_101 . V_41 ;
F_102 ( V_3 -> V_110 , & V_101 , 1 , & V_102 , 0 , F_146 , V_73 ) ;
}
static void V_157 ( struct V_13 * V_13 , int error )
{
void * V_162 = V_13 -> V_158 ;
F_148 ( V_162 , 0 , error ? 1 : 0 ) ;
}
static void F_149 ( struct V_72 * V_73 ,
struct V_13 * V_13 )
{
struct V_2 * V_3 = V_73 -> V_37 ;
void * V_162 ;
V_73 -> V_155 = V_13 ;
V_73 -> V_157 = V_13 -> V_156 ;
V_73 -> V_159 = V_13 -> V_158 ;
V_162 = F_150 ( V_3 -> V_110 ,
F_146 , V_73 ) ;
V_13 -> V_156 = V_157 ;
V_13 -> V_158 = V_162 ;
F_137 ( V_13 ) ;
}
static struct V_72 *
F_151 ( struct V_2 * V_3 , T_2 V_8 )
{
struct V_64 * V_67 = F_56 ( & V_3 -> V_88 , V_8 ) ;
if ( ! V_67 )
return NULL ;
return F_152 ( V_67 , struct V_72 , V_67 ) ;
}
static struct V_72 *
F_153 ( struct V_2 * V_3 ,
struct V_72 * V_73 , T_2 V_8 )
{
struct V_72 * V_163 ;
V_163 = F_151 ( V_3 , V_8 ) ;
if ( V_163 ) {
F_64 ( V_73 ) ;
return V_163 ;
}
V_73 -> V_67 . V_68 = V_8 ;
F_118 ( & V_73 -> V_153 ) ;
F_118 ( & V_73 -> V_154 ) ;
V_73 -> V_164 = 0 ;
V_73 -> V_155 = NULL ;
if ( V_3 -> V_7 -> type -> V_165 ( V_3 -> V_7 , & V_73 -> V_67 ) ) {
F_64 ( V_73 ) ;
return NULL ;
}
F_68 ( & V_3 -> V_88 , & V_73 -> V_67 ) ;
return V_73 ;
}
static void F_154 ( struct V_2 * V_3 , struct V_64 * V_67 ,
struct V_13 * V_13 , T_2 V_8 )
{
V_13 -> V_166 = V_3 -> V_5 -> V_30 ;
V_13 -> V_167 = F_3 ( V_3 -> V_7 ,
F_70 ( V_67 -> V_78 ) +
( V_8 - V_67 -> V_68 ) ) +
( V_13 -> V_167 &
V_3 -> V_7 -> V_168 ) ;
}
static int F_155 ( struct V_116 * V_44 , struct V_13 * V_13 )
{
struct V_64 * V_67 ;
struct V_2 * V_3 = V_44 -> V_137 ;
int V_53 = V_148 ;
T_2 V_8 ;
struct V_72 * V_73 = NULL ;
F_5 ( V_13 ) ;
if ( V_13 -> V_169 & V_170 ) {
V_13 -> V_166 = V_3 -> V_5 -> V_30 ;
return V_148 ;
}
V_8 = F_156 ( V_3 -> V_7 , V_13 -> V_167 ) ;
if ( ! V_3 -> V_107 )
return - V_150 ;
F_42 ( & V_3 -> V_45 ) ;
if ( ! V_3 -> V_107 ) {
V_53 = - V_150 ;
goto V_171;
}
V_67 = F_56 ( & V_3 -> V_82 , V_8 ) ;
if ( V_67 ) {
F_154 ( V_3 , V_67 , V_13 , V_8 ) ;
goto V_171;
}
if ( F_157 ( V_13 ) == V_172 ) {
V_73 = F_151 ( V_3 , V_8 ) ;
if ( ! V_73 ) {
F_43 ( & V_3 -> V_45 ) ;
V_73 = F_61 ( V_3 ) ;
F_42 ( & V_3 -> V_45 ) ;
if ( ! V_3 -> V_107 ) {
F_64 ( V_73 ) ;
V_53 = - V_150 ;
goto V_171;
}
V_67 = F_56 ( & V_3 -> V_82 , V_8 ) ;
if ( V_67 ) {
F_64 ( V_73 ) ;
F_154 ( V_3 , V_67 , V_13 , V_8 ) ;
goto V_171;
}
V_73 = F_153 ( V_3 , V_73 , V_8 ) ;
if ( ! V_73 ) {
F_141 ( V_3 , - V_28 ) ;
V_53 = - V_150 ;
goto V_171;
}
}
F_154 ( V_3 , & V_73 -> V_67 , V_13 , V_8 ) ;
V_53 = V_173 ;
if ( ! V_73 -> V_164 &&
V_13 -> V_174 == ( V_3 -> V_7 -> V_50 << V_175 ) ) {
V_73 -> V_164 = 1 ;
F_43 ( & V_3 -> V_45 ) ;
F_149 ( V_73 , V_13 ) ;
goto V_43;
}
F_158 ( & V_73 -> V_154 , V_13 ) ;
if ( ! V_73 -> V_164 ) {
V_73 -> V_164 = 1 ;
F_43 ( & V_3 -> V_45 ) ;
F_147 ( V_73 ) ;
goto V_43;
}
} else {
V_13 -> V_166 = V_3 -> V_4 -> V_30 ;
F_10 ( V_3 , V_13 , V_8 ) ;
}
V_171:
F_43 ( & V_3 -> V_45 ) ;
V_43:
return V_53 ;
}
static int F_159 ( struct V_116 * V_44 , struct V_13 * V_13 )
{
struct V_64 * V_67 ;
struct V_2 * V_3 = V_44 -> V_137 ;
int V_53 = V_148 ;
T_2 V_8 ;
F_5 ( V_13 ) ;
if ( V_13 -> V_169 & V_170 ) {
if ( ! F_160 ( V_13 ) )
V_13 -> V_166 = V_3 -> V_4 -> V_30 ;
else
V_13 -> V_166 = V_3 -> V_5 -> V_30 ;
return V_148 ;
}
V_8 = F_156 ( V_3 -> V_7 , V_13 -> V_167 ) ;
F_42 ( & V_3 -> V_45 ) ;
if ( ! V_3 -> V_107 )
goto V_176;
V_67 = F_56 ( & V_3 -> V_82 , V_8 ) ;
if ( V_67 ) {
if ( F_157 ( V_13 ) == V_172 &&
V_8 >= V_3 -> V_91 &&
V_8 < ( V_3 -> V_91 +
V_3 -> V_92 ) ) {
V_13 -> V_166 = V_3 -> V_4 -> V_30 ;
F_158 ( & V_3 -> V_93 , V_13 ) ;
V_53 = V_173 ;
goto V_171;
}
F_154 ( V_3 , V_67 , V_13 , V_8 ) ;
if ( F_157 ( V_13 ) == V_172 )
F_10 ( V_3 , V_13 , V_8 ) ;
goto V_171;
}
V_176:
V_13 -> V_166 = V_3 -> V_4 -> V_30 ;
if ( F_157 ( V_13 ) == V_172 ) {
F_43 ( & V_3 -> V_45 ) ;
return F_139 ( V_3 -> V_4 , V_13 ) ;
}
V_171:
F_43 ( & V_3 -> V_45 ) ;
return V_53 ;
}
static int F_161 ( struct V_116 * V_44 , struct V_13 * V_13 , int error )
{
struct V_2 * V_3 = V_44 -> V_137 ;
if ( F_8 ( V_13 ) )
F_15 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_162 ( struct V_116 * V_44 )
{
struct V_2 * V_3 = V_44 -> V_137 ;
F_108 ( V_3 ) ;
}
static int F_163 ( struct V_116 * V_44 )
{
int V_53 = 0 ;
struct V_2 * V_3 = V_44 -> V_137 ;
struct V_2 * V_38 = NULL , * V_39 = NULL ;
F_37 ( & V_29 ) ;
( void ) F_35 ( V_3 , & V_38 , & V_39 , NULL ) ;
if ( V_38 && V_39 ) {
F_37 ( & V_38 -> V_45 ) ;
if ( V_3 == V_38 ) {
F_25 ( L_32
L_33 ) ;
V_53 = - V_46 ;
} else if ( ! F_164 ( V_38 -> V_44 ) ) {
F_25 ( L_34
L_35 ) ;
V_53 = - V_46 ;
}
F_38 ( & V_38 -> V_45 ) ;
}
F_38 ( & V_29 ) ;
return V_53 ;
}
static void F_165 ( struct V_116 * V_44 )
{
struct V_2 * V_3 = V_44 -> V_137 ;
struct V_2 * V_38 = NULL , * V_39 = NULL ;
F_37 ( & V_29 ) ;
( void ) F_35 ( V_3 , & V_38 , & V_39 , NULL ) ;
if ( V_38 && V_39 ) {
F_42 ( & V_38 -> V_45 ) ;
F_166 ( & V_39 -> V_45 , V_177 ) ;
F_131 ( V_38 , V_39 ) ;
F_43 ( & V_39 -> V_45 ) ;
F_43 ( & V_38 -> V_45 ) ;
}
F_38 ( & V_29 ) ;
F_44 ( V_3 ) ;
F_42 ( & V_3 -> V_45 ) ;
V_3 -> V_42 = 1 ;
F_43 ( & V_3 -> V_45 ) ;
}
static T_3 F_167 ( struct V_10 * V_30 )
{
T_3 V_178 ;
F_37 ( & V_29 ) ;
V_178 = F_74 ( F_31 ( V_30 ) ) ;
F_38 ( & V_29 ) ;
return V_178 ;
}
static void F_168 ( struct V_116 * V_44 )
{
struct V_2 * V_3 = V_44 -> V_137 ;
F_165 ( V_44 ) ;
V_44 -> V_145 = F_167 ( V_3 -> V_4 -> V_30 ) ;
F_104 ( V_3 ) ;
}
static int F_169 ( struct V_116 * V_44 , T_6 type ,
unsigned V_179 , char * V_180 , unsigned V_181 )
{
unsigned V_182 = 0 ;
struct V_2 * V_37 = V_44 -> V_137 ;
switch ( type ) {
case V_183 :
F_42 ( & V_37 -> V_45 ) ;
if ( ! V_37 -> V_107 )
F_170 ( L_36 ) ;
else if ( V_37 -> V_108 )
F_170 ( L_37 ) ;
else {
if ( V_37 -> V_7 -> type -> V_184 ) {
T_1 V_185 , V_186 ,
V_187 ;
V_37 -> V_7 -> type -> V_184 ( V_37 -> V_7 ,
& V_185 ,
& V_186 ,
& V_187 ) ;
F_170 ( L_38 ,
( unsigned long long ) V_186 ,
( unsigned long long ) V_185 ,
( unsigned long long ) V_187 ) ;
}
else
F_170 ( L_39 ) ;
}
F_43 ( & V_37 -> V_45 ) ;
break;
case V_188 :
F_170 ( L_40 , V_37 -> V_4 -> V_189 , V_37 -> V_5 -> V_189 ) ;
V_37 -> V_7 -> type -> V_190 ( V_37 -> V_7 , type , V_180 + V_182 ,
V_181 - V_182 ) ;
break;
}
return 0 ;
}
static int F_171 ( struct V_116 * V_44 ,
T_7 V_191 , void * V_192 )
{
struct V_2 * V_37 = V_44 -> V_137 ;
int V_53 ;
V_53 = V_191 ( V_44 , V_37 -> V_4 , 0 , V_44 -> V_193 , V_192 ) ;
if ( ! V_53 )
V_53 = V_191 ( V_44 , V_37 -> V_5 , 0 , F_78 ( V_37 -> V_5 -> V_30 ) , V_192 ) ;
return V_53 ;
}
static int F_172 ( struct V_26 * V_54 , T_1 V_109 ,
struct V_13 * V_13 )
{
int V_53 = V_148 ;
struct V_2 * V_37 ;
struct V_64 * V_67 ;
struct V_72 * V_73 ;
struct V_72 * V_194 = NULL ;
struct V_72 * V_195 = NULL ;
T_2 V_8 ;
F_32 (snap, snapshots, list) {
if ( F_36 ( V_37 -> V_44 ) )
continue;
F_42 ( & V_37 -> V_45 ) ;
if ( ! V_37 -> V_107 || ! V_37 -> V_42 )
goto V_196;
if ( V_109 >= F_173 ( V_37 -> V_44 -> V_60 ) )
goto V_196;
V_8 = F_156 ( V_37 -> V_7 , V_109 ) ;
V_67 = F_56 ( & V_37 -> V_82 , V_8 ) ;
if ( V_67 )
goto V_196;
V_73 = F_151 ( V_37 , V_8 ) ;
if ( ! V_73 ) {
F_43 ( & V_37 -> V_45 ) ;
V_73 = F_61 ( V_37 ) ;
F_42 ( & V_37 -> V_45 ) ;
if ( ! V_37 -> V_107 ) {
F_64 ( V_73 ) ;
goto V_196;
}
V_67 = F_56 ( & V_37 -> V_82 , V_8 ) ;
if ( V_67 ) {
F_64 ( V_73 ) ;
goto V_196;
}
V_73 = F_153 ( V_37 , V_73 , V_8 ) ;
if ( ! V_73 ) {
F_141 ( V_37 , - V_28 ) ;
goto V_196;
}
}
V_53 = V_173 ;
if ( V_13 ) {
F_158 ( & V_73 -> V_153 , V_13 ) ;
V_13 = NULL ;
if ( ! V_73 -> V_164 ) {
V_73 -> V_164 = 1 ;
V_195 = V_73 ;
}
}
if ( ! V_73 -> V_164 ) {
V_73 -> V_164 = 1 ;
V_194 = V_73 ;
}
V_196:
F_43 ( & V_37 -> V_45 ) ;
if ( V_194 ) {
F_147 ( V_194 ) ;
V_194 = NULL ;
}
}
if ( V_195 )
F_147 ( V_195 ) ;
return V_53 ;
}
static int F_139 ( struct V_1 * V_4 , struct V_13 * V_13 )
{
struct V_4 * V_34 ;
int V_53 = V_148 ;
F_37 ( & V_29 ) ;
V_34 = F_31 ( V_4 -> V_30 ) ;
if ( V_34 )
V_53 = F_172 ( & V_34 -> V_54 , V_13 -> V_167 , V_13 ) ;
F_38 ( & V_29 ) ;
return V_53 ;
}
static int F_100 ( struct V_2 * V_197 ,
T_1 V_109 , unsigned V_57 )
{
int V_198 = 0 ;
T_1 V_146 ;
struct V_4 * V_34 ;
F_37 ( & V_29 ) ;
V_34 = F_31 ( V_197 -> V_4 -> V_30 ) ;
for ( V_146 = 0 ; V_146 < V_57 ; V_146 += V_197 -> V_44 -> V_145 )
if ( F_172 ( & V_34 -> V_54 , V_109 + V_146 , NULL ) ==
V_173 )
V_198 = 1 ;
F_38 ( & V_29 ) ;
return V_198 ;
}
static int F_174 ( struct V_116 * V_44 , unsigned int V_117 , char * * V_118 )
{
int V_53 ;
struct V_1 * V_199 ;
if ( V_117 != 1 ) {
V_44 -> error = L_41 ;
return - V_46 ;
}
V_53 = F_113 ( V_44 , V_118 [ 0 ] , F_114 ( V_44 -> V_60 ) , & V_199 ) ;
if ( V_53 ) {
V_44 -> error = L_42 ;
return V_53 ;
}
V_44 -> V_137 = V_199 ;
V_44 -> V_122 = 1 ;
return 0 ;
}
static void F_175 ( struct V_116 * V_44 )
{
struct V_1 * V_199 = V_44 -> V_137 ;
F_129 ( V_44 , V_199 ) ;
}
static int F_176 ( struct V_116 * V_44 , struct V_13 * V_13 )
{
struct V_1 * V_199 = V_44 -> V_137 ;
V_13 -> V_166 = V_199 -> V_30 ;
if ( V_13 -> V_169 & V_170 )
return V_148 ;
return ( F_157 ( V_13 ) == V_172 ) ? F_139 ( V_199 , V_13 ) : V_148 ;
}
static void F_177 ( struct V_116 * V_44 )
{
struct V_1 * V_199 = V_44 -> V_137 ;
V_44 -> V_145 = F_167 ( V_199 -> V_30 ) ;
}
static int F_178 ( struct V_116 * V_44 , T_6 type ,
unsigned V_179 , char * V_180 , unsigned V_181 )
{
struct V_1 * V_199 = V_44 -> V_137 ;
switch ( type ) {
case V_183 :
V_180 [ 0 ] = '\0' ;
break;
case V_188 :
snprintf ( V_180 , V_181 , L_43 , V_199 -> V_189 ) ;
break;
}
return 0 ;
}
static int F_179 ( struct V_116 * V_44 , struct V_200 * V_201 ,
struct V_202 * V_203 , int V_204 )
{
struct V_1 * V_199 = V_44 -> V_137 ;
struct V_205 * V_206 = F_180 ( V_199 -> V_30 ) ;
if ( ! V_206 -> V_207 )
return V_204 ;
V_201 -> V_166 = V_199 -> V_30 ;
return F_79 ( V_204 , V_206 -> V_207 ( V_206 , V_201 , V_203 ) ) ;
}
static int F_181 ( struct V_116 * V_44 ,
T_7 V_191 , void * V_192 )
{
struct V_1 * V_199 = V_44 -> V_137 ;
return V_191 ( V_44 , V_199 , 0 , V_44 -> V_193 , V_192 ) ;
}
static int T_8 F_182 ( void )
{
int V_53 ;
V_53 = F_183 () ;
if ( V_53 ) {
F_25 ( L_44 ) ;
return V_53 ;
}
V_53 = F_184 ( & V_208 ) ;
if ( V_53 < 0 ) {
F_25 ( L_45 , V_53 ) ;
goto V_209;
}
V_53 = F_184 ( & V_210 ) ;
if ( V_53 < 0 ) {
F_25 ( L_46 , V_53 ) ;
goto V_211;
}
V_53 = F_184 ( & V_212 ) ;
if ( V_53 < 0 ) {
F_25 ( L_47 , V_53 ) ;
goto V_213;
}
V_53 = F_23 () ;
if ( V_53 ) {
F_25 ( L_48 ) ;
goto V_214;
}
V_69 = F_185 ( V_64 , 0 ) ;
if ( ! V_69 ) {
F_25 ( L_49 ) ;
V_53 = - V_28 ;
goto V_215;
}
V_134 = F_185 ( V_72 , 0 ) ;
if ( ! V_134 ) {
F_25 ( L_50 ) ;
V_53 = - V_28 ;
goto V_216;
}
return 0 ;
V_216:
F_186 ( V_69 ) ;
V_215:
F_28 () ;
V_214:
F_187 ( & V_212 ) ;
V_213:
F_187 ( & V_210 ) ;
V_211:
F_187 ( & V_208 ) ;
V_209:
F_188 () ;
return V_53 ;
}
static void T_9 F_189 ( void )
{
F_187 ( & V_208 ) ;
F_187 ( & V_210 ) ;
F_187 ( & V_212 ) ;
F_28 () ;
F_186 ( V_134 ) ;
F_186 ( V_69 ) ;
F_188 () ;
}
