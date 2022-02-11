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
static struct V_13 * F_5 ( struct V_2 * V_3 ,
T_2 V_8 )
{
struct V_13 * V_14 = F_6 ( V_3 -> V_15 ,
V_16 ) ;
unsigned long V_17 ;
V_14 -> V_8 = V_8 ;
F_7 ( & V_3 -> V_18 , V_17 ) ;
F_8 ( & V_14 -> V_19 ,
& V_3 -> V_20 [ F_9 ( V_8 ) ] ) ;
F_10 ( & V_3 -> V_18 , V_17 ) ;
return V_14 ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
unsigned long V_17 ;
F_7 ( & V_3 -> V_18 , V_17 ) ;
F_12 ( & V_14 -> V_19 ) ;
F_10 ( & V_3 -> V_18 , V_17 ) ;
F_13 ( V_14 , V_3 -> V_15 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_2 V_8 )
{
struct V_13 * V_14 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
F_15 ( & V_3 -> V_18 ) ;
F_16 (c, hn,
&s->tracked_chunk_hash[DM_TRACKED_CHUNK_HASH(chunk)], node) {
if ( V_14 -> V_8 == V_8 ) {
V_23 = 1 ;
break;
}
}
F_17 ( & V_3 -> V_18 ) ;
return V_23 ;
}
static void F_18 ( struct V_2 * V_3 , T_2 V_8 )
{
while ( F_14 ( V_3 , V_8 ) )
F_19 ( 1 ) ;
}
static int F_20 ( void )
{
int V_24 ;
V_25 = F_21 ( V_26 * sizeof( struct V_27 ) ,
V_28 ) ;
if ( ! V_25 ) {
F_22 ( L_1 ) ;
return - V_29 ;
}
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
F_23 ( V_25 + V_24 ) ;
F_24 ( & V_30 ) ;
return 0 ;
}
static void F_25 ( void )
{
F_26 ( V_25 ) ;
}
static unsigned F_27 ( struct V_10 * V_31 )
{
return V_31 -> V_32 & V_33 ;
}
static struct V_4 * F_28 ( struct V_10 * V_4 )
{
struct V_27 * V_34 ;
struct V_4 * V_35 ;
V_34 = & V_25 [ F_27 ( V_4 ) ] ;
F_29 (o, ol, hash_list)
if ( F_4 ( V_35 -> V_31 , V_4 ) )
return V_35 ;
return NULL ;
}
static void F_30 ( struct V_4 * V_35 )
{
struct V_27 * V_36 = & V_25 [ F_27 ( V_35 -> V_31 ) ] ;
F_31 ( & V_35 -> V_37 , V_36 ) ;
}
static int F_32 ( struct V_2 * V_38 ,
struct V_2 * * V_39 ,
struct V_2 * * V_40 ,
struct V_2 * * V_41 )
{
struct V_2 * V_3 ;
struct V_4 * V_35 ;
int V_42 = 0 ;
int V_43 ;
V_35 = F_28 ( V_38 -> V_4 -> V_31 ) ;
if ( ! V_35 )
goto V_44;
F_29 (s, &o->snapshots, list) {
if ( F_33 ( V_3 -> V_45 ) && V_41 )
* V_41 = V_3 ;
if ( ! F_4 ( V_3 -> V_5 -> V_31 , V_38 -> V_5 -> V_31 ) )
continue;
F_34 ( & V_3 -> V_46 ) ;
V_43 = V_3 -> V_43 ;
F_35 ( & V_3 -> V_46 ) ;
if ( V_43 ) {
if ( V_39 )
* V_39 = V_3 ;
} else if ( V_40 )
* V_40 = V_3 ;
V_42 ++ ;
}
V_44:
return V_42 ;
}
static int F_36 ( struct V_2 * V_38 )
{
struct V_2 * V_39 = NULL , * V_40 = NULL ;
struct V_2 * V_41 = NULL ;
if ( ( F_32 ( V_38 , & V_39 , & V_40 ,
& V_41 ) == 2 ) ||
V_40 ) {
V_38 -> V_45 -> error = L_2
L_3 ;
return - V_47 ;
}
if ( ! V_39 )
return 0 ;
if ( ! F_33 ( V_38 -> V_45 ) )
return 1 ;
if ( V_41 ) {
V_38 -> V_45 -> error = L_4 ;
return - V_47 ;
}
if ( ! V_39 -> V_7 -> type -> V_48 ||
! V_39 -> V_7 -> type -> V_49 ) {
V_38 -> V_45 -> error = L_5
L_6 ;
return - V_47 ;
}
return 1 ;
}
static void F_37 ( struct V_4 * V_35 , struct V_2 * V_3 )
{
struct V_2 * V_50 ;
F_29 (l, &o->snapshots, list)
if ( V_50 -> V_7 -> V_51 < V_3 -> V_7 -> V_51 )
break;
F_31 ( & V_3 -> V_52 , & V_50 -> V_52 ) ;
}
static int F_38 ( struct V_2 * V_38 )
{
struct V_4 * V_35 , * V_53 = NULL ;
struct V_10 * V_31 = V_38 -> V_4 -> V_31 ;
int V_54 = 0 ;
V_53 = F_21 ( sizeof( * V_53 ) , V_28 ) ;
if ( ! V_53 )
return - V_29 ;
F_39 ( & V_30 ) ;
V_54 = F_36 ( V_38 ) ;
if ( V_54 < 0 ) {
F_26 ( V_53 ) ;
goto V_44;
}
V_35 = F_28 ( V_31 ) ;
if ( V_35 )
F_26 ( V_53 ) ;
else {
V_35 = V_53 ;
F_23 ( & V_35 -> V_55 ) ;
V_35 -> V_31 = V_31 ;
F_30 ( V_35 ) ;
}
F_37 ( V_35 , V_38 ) ;
V_44:
F_40 ( & V_30 ) ;
return V_54 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_10 * V_31 = V_3 -> V_4 -> V_31 ;
F_39 ( & V_30 ) ;
F_42 ( & V_3 -> V_52 ) ;
F_37 ( F_28 ( V_31 ) , V_3 ) ;
F_40 ( & V_30 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_4 * V_35 ;
F_39 ( & V_30 ) ;
V_35 = F_28 ( V_3 -> V_4 -> V_31 ) ;
F_42 ( & V_3 -> V_52 ) ;
if ( V_35 && F_44 ( & V_35 -> V_55 ) ) {
F_42 ( & V_35 -> V_37 ) ;
F_26 ( V_35 ) ;
}
F_40 ( & V_30 ) ;
}
static int F_45 ( struct V_56 * V_57 ,
T_3 V_58 , unsigned V_59 )
{
unsigned int V_24 ;
V_57 -> V_59 = V_59 ;
V_57 -> V_60 = V_58 - 1 ;
V_57 -> V_61 = F_46 ( V_58 , sizeof( struct V_27 ) ) ;
if ( ! V_57 -> V_61 )
return - V_29 ;
for ( V_24 = 0 ; V_24 < V_58 ; V_24 ++ )
F_23 ( V_57 -> V_61 + V_24 ) ;
return 0 ;
}
static void F_47 ( struct V_56 * V_57 ,
struct V_62 * V_63 )
{
struct V_27 * V_64 ;
struct V_65 * V_66 , * V_67 ;
int V_24 , V_58 ;
V_58 = V_57 -> V_60 + 1 ;
for ( V_24 = 0 ; V_24 < V_58 ; V_24 ++ ) {
V_64 = V_57 -> V_61 + V_24 ;
F_48 (ex, next, slot, hash_list)
F_49 ( V_63 , V_66 ) ;
}
F_50 ( V_57 -> V_61 ) ;
}
static T_3 F_51 ( struct V_56 * V_57 , T_2 V_8 )
{
return ( V_8 >> V_57 -> V_59 ) & V_57 -> V_60 ;
}
static void F_52 ( struct V_65 * V_68 )
{
F_42 ( & V_68 -> V_37 ) ;
}
static struct V_65 * F_53 ( struct V_56 * V_57 ,
T_2 V_8 )
{
struct V_27 * V_64 ;
struct V_65 * V_68 ;
V_64 = & V_57 -> V_61 [ F_51 ( V_57 , V_8 ) ] ;
F_29 (e, slot, hash_list)
if ( V_8 >= V_68 -> V_69 &&
V_8 <= V_68 -> V_69 + F_54 ( V_68 ) )
return V_68 ;
return NULL ;
}
static struct V_65 * F_55 ( void )
{
struct V_65 * V_68 ;
V_68 = F_56 ( V_70 , V_16 ) ;
if ( ! V_68 )
V_68 = F_56 ( V_70 , V_71 ) ;
return V_68 ;
}
static void F_57 ( struct V_65 * V_68 )
{
F_49 ( V_70 , V_68 ) ;
}
static struct V_72 * F_58 ( struct V_2 * V_3 )
{
struct V_72 * V_73 = F_6 ( V_3 -> V_74 ,
V_16 ) ;
F_59 ( & V_3 -> V_75 ) ;
V_73 -> V_38 = V_3 ;
return V_73 ;
}
static void F_60 ( struct V_72 * V_73 )
{
struct V_2 * V_3 = V_73 -> V_38 ;
F_13 ( V_73 , V_3 -> V_74 ) ;
F_61 () ;
F_62 ( & V_3 -> V_75 ) ;
}
static void F_63 ( struct V_56 * V_76 ,
struct V_65 * V_77 )
{
struct V_27 * V_50 ;
struct V_65 * V_68 = NULL ;
V_50 = & V_76 -> V_61 [ F_51 ( V_76 , V_77 -> V_69 ) ] ;
if ( ! V_76 -> V_59 )
goto V_44;
F_64 (e, l, hash_list) {
if ( V_77 -> V_69 == ( V_68 -> V_69 +
F_54 ( V_68 ) + 1 ) &&
V_77 -> V_78 == ( F_65 ( V_68 -> V_78 ) +
F_54 ( V_68 ) + 1 ) ) {
F_66 ( V_68 ) ;
F_57 ( V_77 ) ;
return;
}
if ( V_77 -> V_69 == ( V_68 -> V_69 - 1 ) &&
V_77 -> V_78 == ( F_65 ( V_68 -> V_78 ) - 1 ) ) {
F_66 ( V_68 ) ;
V_68 -> V_69 -- ;
V_68 -> V_78 -- ;
F_57 ( V_77 ) ;
return;
}
if ( V_77 -> V_69 > V_68 -> V_69 )
break;
}
V_44:
F_67 ( & V_77 -> V_37 , V_68 ? & V_68 -> V_37 : V_50 ) ;
}
static int F_68 ( void * V_79 , T_2 V_80 , T_2 V_81 )
{
struct V_2 * V_3 = V_79 ;
struct V_65 * V_68 ;
V_68 = F_55 () ;
if ( ! V_68 )
return - V_29 ;
V_68 -> V_69 = V_80 ;
V_68 -> V_78 = V_81 ;
F_63 ( & V_3 -> V_82 , V_68 ) ;
return 0 ;
}
static T_3 F_69 ( struct V_4 * V_35 )
{
struct V_2 * V_38 ;
unsigned V_51 = 0 ;
if ( V_35 )
F_29 (snap, &o->snapshots, list)
V_51 = F_70 ( V_51 ,
V_38 -> V_7 -> V_51 ) ;
return ( T_3 ) V_51 ;
}
static int F_71 ( void )
{
unsigned long V_63 = 2 * 1024 * 1024 ;
V_63 /= sizeof( struct V_27 ) ;
return V_63 ;
}
static int F_72 ( struct V_2 * V_3 )
{
T_1 V_83 , V_84 , V_85 , V_86 ;
V_84 = F_73 ( V_3 -> V_5 -> V_31 ) ;
V_85 = F_73 ( V_3 -> V_4 -> V_31 ) ;
V_86 = F_71 () ;
V_83 = F_74 ( V_85 , V_84 ) >> V_3 -> V_7 -> V_9 ;
V_83 = F_74 ( V_83 , V_86 ) ;
if ( V_83 < 64 )
V_83 = 64 ;
V_83 = F_75 ( V_83 ) ;
if ( F_45 ( & V_3 -> V_82 , V_83 ,
V_87 ) )
return - V_29 ;
V_83 >>= 3 ;
if ( V_83 < 64 )
V_83 = 64 ;
if ( F_45 ( & V_3 -> V_88 , V_83 , 0 ) ) {
F_47 ( & V_3 -> V_82 , V_70 ) ;
return - V_29 ;
}
return 0 ;
}
static void F_76 ( struct V_2 * V_3 )
{
F_77 ( V_89 , & V_3 -> V_90 ) ;
F_78 () ;
F_79 ( & V_3 -> V_90 , V_89 ) ;
}
static struct V_91 * F_80 ( struct V_2 * V_3 )
{
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
return F_81 ( & V_3 -> V_94 ) ;
}
static int F_82 ( struct V_2 * V_3 ,
T_2 V_69 )
{
struct V_65 * V_68 ;
V_68 = F_53 ( & V_3 -> V_82 , V_69 ) ;
if ( ! V_68 ) {
F_22 ( L_7
L_8 ,
( unsigned long long ) V_69 ) ;
return - V_47 ;
}
if ( ! F_54 ( V_68 ) ) {
F_52 ( V_68 ) ;
F_57 ( V_68 ) ;
return 0 ;
}
if ( V_69 == V_68 -> V_69 ) {
V_68 -> V_69 ++ ;
V_68 -> V_78 ++ ;
} else if ( V_69 != V_68 -> V_69 +
F_54 ( V_68 ) ) {
F_22 ( L_9
L_10 ,
( unsigned long long ) V_69 ,
( unsigned long long ) V_68 -> V_69 ,
( unsigned long long )
V_68 -> V_69 + F_54 ( V_68 ) ) ;
return - V_47 ;
}
F_83 ( V_68 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_91 * V_95 = NULL ;
int V_54 ;
T_2 V_69 = V_3 -> V_92 + V_3 -> V_93 - 1 ;
F_39 ( & V_3 -> V_46 ) ;
do {
V_54 = F_82 ( V_3 , V_69 ) ;
if ( V_54 )
goto V_44;
} while ( V_69 -- > V_3 -> V_92 );
V_95 = F_80 ( V_3 ) ;
V_44:
F_40 ( & V_3 -> V_46 ) ;
if ( V_95 )
F_85 ( V_95 ) ;
return V_54 ;
}
static T_4 F_86 ( void )
{
T_4 V_96 ;
F_87 ( & V_97 ) ;
V_96 = V_98 ;
F_88 ( & V_97 ) ;
return V_96 ;
}
static void F_89 ( void )
{
F_87 ( & V_97 ) ;
V_98 ++ ;
F_88 ( & V_97 ) ;
F_90 ( & V_99 ) ;
}
static void F_91 ( struct V_2 * V_3 )
{
int V_24 , V_100 ;
T_2 V_69 , V_78 ;
struct V_101 V_102 , V_103 ;
T_1 V_104 ;
T_4 V_105 ;
F_92 ( ! F_93 ( V_89 , & V_3 -> V_90 ) ) ;
if ( F_94 ( F_93 ( V_106 , & V_3 -> V_90 ) ) )
goto V_107;
if ( ! V_3 -> V_108 ) {
F_22 ( L_11 ) ;
goto V_107;
}
V_100 = V_3 -> V_7 -> type -> V_48 ( V_3 -> V_7 , & V_69 ,
& V_78 ) ;
if ( V_100 <= 0 ) {
if ( V_100 < 0 ) {
F_22 ( L_12
L_13 ) ;
F_39 ( & V_3 -> V_46 ) ;
V_3 -> V_109 = 1 ;
F_40 ( & V_3 -> V_46 ) ;
}
goto V_107;
}
V_69 = V_69 + 1 - V_100 ;
V_78 = V_78 + 1 - V_100 ;
V_104 = V_100 * V_3 -> V_7 -> V_51 ;
V_103 . V_31 = V_3 -> V_4 -> V_31 ;
V_103 . V_110 = F_3 ( V_3 -> V_7 , V_69 ) ;
V_103 . V_42 = F_74 ( V_104 , F_73 ( V_103 . V_31 ) - V_103 . V_110 ) ;
V_102 . V_31 = V_3 -> V_5 -> V_31 ;
V_102 . V_110 = F_3 ( V_3 -> V_7 , V_78 ) ;
V_102 . V_42 = V_103 . V_42 ;
V_105 = F_86 () ;
while ( F_95 ( V_3 , V_103 . V_110 , V_104 ) ) {
F_96 ( V_99 ,
( F_86 () !=
V_105 ) ) ;
V_105 = F_86 () ;
}
F_39 ( & V_3 -> V_46 ) ;
V_3 -> V_92 = V_69 ;
V_3 -> V_93 = V_100 ;
F_40 ( & V_3 -> V_46 ) ;
for ( V_24 = 0 ; V_24 < V_100 ; V_24 ++ )
F_18 ( V_3 , V_69 + V_24 ) ;
F_97 ( V_3 -> V_111 , & V_102 , 1 , & V_103 , 0 , V_112 , V_3 ) ;
return;
V_107:
F_76 ( V_3 ) ;
}
static void V_112 ( int V_113 , unsigned long V_114 , void * V_79 )
{
struct V_2 * V_3 = V_79 ;
struct V_91 * V_95 = NULL ;
if ( V_113 || V_114 ) {
if ( V_113 )
F_22 ( L_14 ) ;
else
F_22 ( L_15 ) ;
goto V_107;
}
if ( V_3 -> V_7 -> type -> V_49 ( V_3 -> V_7 ,
V_3 -> V_93 ) < 0 ) {
F_22 ( L_16 ) ;
goto V_107;
}
if ( F_84 ( V_3 ) < 0 )
goto V_107;
F_91 ( V_3 ) ;
return;
V_107:
F_39 ( & V_3 -> V_46 ) ;
V_3 -> V_109 = 1 ;
V_95 = F_80 ( V_3 ) ;
F_40 ( & V_3 -> V_46 ) ;
F_98 ( V_95 ) ;
F_76 ( V_3 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
if ( ! F_100 ( V_89 , & V_3 -> V_90 ) )
F_91 ( V_3 ) ;
}
static int F_101 ( void * V_115 )
{
F_102 () ;
return 0 ;
}
static void F_103 ( struct V_2 * V_3 )
{
F_104 ( V_106 , & V_3 -> V_90 ) ;
F_105 ( & V_3 -> V_90 , V_89 , F_101 ,
V_116 ) ;
F_106 ( V_106 , & V_3 -> V_90 ) ;
}
static int F_107 ( struct V_117 * V_45 , unsigned int V_118 , char * * V_119 )
{
struct V_2 * V_3 ;
int V_24 ;
int V_54 = - V_47 ;
char * V_120 , * V_121 ;
unsigned V_122 , V_123 = 1 ;
T_5 V_124 = V_125 ;
if ( V_118 != 4 ) {
V_45 -> error = L_17 ;
V_54 = - V_47 ;
goto V_126;
}
if ( F_33 ( V_45 ) ) {
V_123 = 2 ;
V_124 = V_127 ;
}
V_3 = F_21 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 ) {
V_45 -> error = L_18 ;
V_54 = - V_29 ;
goto V_126;
}
V_120 = V_119 [ 0 ] ;
V_119 ++ ;
V_118 -- ;
V_54 = F_108 ( V_45 , V_120 , V_124 , & V_3 -> V_4 ) ;
if ( V_54 ) {
V_45 -> error = L_19 ;
goto V_128;
}
V_121 = V_119 [ 0 ] ;
V_119 ++ ;
V_118 -- ;
V_54 = F_108 ( V_45 , V_121 , F_109 ( V_45 -> V_61 ) , & V_3 -> V_5 ) ;
if ( V_54 ) {
V_45 -> error = L_20 ;
goto V_129;
}
V_54 = F_110 ( V_45 , V_118 , V_119 , V_3 , & V_122 , & V_3 -> V_7 ) ;
if ( V_54 ) {
V_45 -> error = L_21 ;
V_54 = - V_47 ;
goto V_130;
}
V_119 += V_122 ;
V_118 -= V_122 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_108 = 1 ;
V_3 -> V_43 = 0 ;
F_111 ( & V_3 -> V_75 , 0 ) ;
F_24 ( & V_3 -> V_46 ) ;
F_23 ( & V_3 -> V_52 ) ;
F_112 ( & V_3 -> V_131 ) ;
V_3 -> V_90 = 0 ;
V_3 -> V_109 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
F_113 ( & V_3 -> V_94 ) ;
if ( F_72 ( V_3 ) ) {
V_45 -> error = L_22 ;
V_54 = - V_29 ;
goto V_132;
}
V_3 -> V_111 = F_114 () ;
if ( F_115 ( V_3 -> V_111 ) ) {
V_54 = F_116 ( V_3 -> V_111 ) ;
V_45 -> error = L_23 ;
goto V_133;
}
V_3 -> V_74 = F_117 ( V_134 , V_135 ) ;
if ( ! V_3 -> V_74 ) {
V_45 -> error = L_24 ;
goto V_136;
}
V_3 -> V_15 = F_117 ( V_134 ,
V_137 ) ;
if ( ! V_3 -> V_15 ) {
V_45 -> error = L_25
L_26 ;
goto V_138;
}
for ( V_24 = 0 ; V_24 < V_139 ; V_24 ++ )
F_118 ( & V_3 -> V_20 [ V_24 ] ) ;
F_112 ( & V_3 -> V_18 ) ;
V_45 -> V_140 = V_3 ;
V_45 -> V_123 = V_123 ;
V_54 = F_38 ( V_3 ) ;
if ( V_54 == - V_29 ) {
V_45 -> error = L_27 ;
goto V_141;
} else if ( V_54 < 0 ) {
goto V_141;
}
if ( V_54 > 0 ) {
V_3 -> V_7 -> V_51 = 0 ;
return 0 ;
}
V_54 = V_3 -> V_7 -> type -> V_142 ( V_3 -> V_7 , F_68 ,
( void * ) V_3 ) ;
if ( V_54 < 0 ) {
V_45 -> error = L_28 ;
goto V_143;
} else if ( V_54 > 0 ) {
V_3 -> V_108 = 0 ;
F_119 ( L_29 ) ;
}
if ( ! V_3 -> V_7 -> V_51 ) {
V_45 -> error = L_30 ;
goto V_143;
}
V_54 = F_120 ( V_45 , V_3 -> V_7 -> V_51 ) ;
if ( V_54 )
goto V_143;
return 0 ;
V_143:
F_43 ( V_3 ) ;
V_141:
F_121 ( V_3 -> V_15 ) ;
V_138:
F_121 ( V_3 -> V_74 ) ;
V_136:
F_122 ( V_3 -> V_111 ) ;
V_133:
F_47 ( & V_3 -> V_88 , V_135 ) ;
F_47 ( & V_3 -> V_82 , V_70 ) ;
V_132:
F_123 ( V_3 -> V_7 ) ;
V_130:
F_124 ( V_45 , V_3 -> V_5 ) ;
V_129:
F_124 ( V_45 , V_3 -> V_4 ) ;
V_128:
F_26 ( V_3 ) ;
V_126:
return V_54 ;
}
static void F_125 ( struct V_2 * V_3 )
{
F_122 ( V_3 -> V_111 ) ;
V_3 -> V_111 = NULL ;
F_47 ( & V_3 -> V_88 , V_135 ) ;
F_47 ( & V_3 -> V_82 , V_70 ) ;
}
static void F_126 ( struct V_2 * V_39 ,
struct V_2 * V_40 )
{
union {
struct V_56 V_144 ;
struct V_6 * V_145 ;
} V_146 ;
V_146 . V_144 = V_40 -> V_82 ;
V_40 -> V_82 = V_39 -> V_82 ;
V_39 -> V_82 = V_146 . V_144 ;
V_146 . V_145 = V_40 -> V_7 ;
V_40 -> V_7 = V_39 -> V_7 ;
V_39 -> V_7 = V_146 . V_145 ;
V_40 -> V_7 -> V_38 = V_40 ;
V_39 -> V_7 -> V_38 = V_39 ;
V_40 -> V_45 -> V_147 = V_40 -> V_7 -> V_51 ;
V_40 -> V_108 = V_39 -> V_108 ;
V_39 -> V_108 = 0 ;
}
static void F_127 ( struct V_117 * V_45 )
{
#ifdef F_128
int V_24 ;
#endif
struct V_2 * V_3 = V_45 -> V_140 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_34 ( & V_30 ) ;
( void ) F_32 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 && ( V_3 == V_39 ) ) {
F_39 ( & V_40 -> V_46 ) ;
V_40 -> V_108 = 0 ;
F_40 ( & V_40 -> V_46 ) ;
F_22 ( L_31 ) ;
}
F_35 ( & V_30 ) ;
if ( F_33 ( V_45 ) )
F_103 ( V_3 ) ;
F_43 ( V_3 ) ;
while ( F_129 ( & V_3 -> V_75 ) )
F_19 ( 1 ) ;
F_130 () ;
#ifdef F_128
for ( V_24 = 0 ; V_24 < V_139 ; V_24 ++ )
F_92 ( ! F_131 ( & V_3 -> V_20 [ V_24 ] ) ) ;
#endif
F_121 ( V_3 -> V_15 ) ;
F_125 ( V_3 ) ;
F_121 ( V_3 -> V_74 ) ;
F_123 ( V_3 -> V_7 ) ;
F_124 ( V_45 , V_3 -> V_5 ) ;
F_124 ( V_45 , V_3 -> V_4 ) ;
F_26 ( V_3 ) ;
}
static void F_85 ( struct V_91 * V_91 )
{
struct V_91 * V_148 ;
while ( V_91 ) {
V_148 = V_91 -> V_149 ;
V_91 -> V_149 = NULL ;
F_132 ( V_91 ) ;
V_91 = V_148 ;
}
}
static void F_133 ( struct V_2 * V_3 , struct V_91 * V_91 )
{
struct V_91 * V_148 ;
int V_54 ;
while ( V_91 ) {
V_148 = V_91 -> V_149 ;
V_91 -> V_149 = NULL ;
V_54 = F_134 ( V_3 -> V_4 , V_91 ) ;
if ( V_54 == V_150 )
F_132 ( V_91 ) ;
V_91 = V_148 ;
}
}
static void F_98 ( struct V_91 * V_91 )
{
struct V_91 * V_148 ;
while ( V_91 ) {
V_148 = V_91 -> V_149 ;
V_91 -> V_149 = NULL ;
F_135 ( V_91 ) ;
V_91 = V_148 ;
}
}
static void F_136 ( struct V_2 * V_3 , int V_151 )
{
if ( ! V_3 -> V_108 )
return;
if ( V_151 == - V_152 )
F_22 ( L_32 ) ;
else if ( V_151 == - V_29 )
F_22 ( L_33 ) ;
if ( V_3 -> V_7 -> type -> V_153 )
V_3 -> V_7 -> type -> V_153 ( V_3 -> V_7 ) ;
V_3 -> V_108 = 0 ;
F_137 ( V_3 -> V_45 -> V_61 ) ;
}
static void F_138 ( struct V_72 * V_73 , int V_154 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_73 -> V_38 ;
struct V_91 * V_155 = NULL ;
struct V_91 * V_156 = NULL ;
struct V_91 * V_157 = NULL ;
int error = 0 ;
if ( ! V_154 ) {
F_39 ( & V_3 -> V_46 ) ;
F_136 ( V_3 , - V_152 ) ;
error = 1 ;
goto V_44;
}
V_68 = F_55 () ;
if ( ! V_68 ) {
F_39 ( & V_3 -> V_46 ) ;
F_136 ( V_3 , - V_29 ) ;
error = 1 ;
goto V_44;
}
* V_68 = V_73 -> V_68 ;
F_39 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 ) {
F_57 ( V_68 ) ;
error = 1 ;
goto V_44;
}
F_18 ( V_3 , V_73 -> V_68 . V_69 ) ;
F_63 ( & V_3 -> V_82 , V_68 ) ;
V_44:
F_52 ( & V_73 -> V_68 ) ;
V_156 = F_81 ( & V_73 -> V_156 ) ;
V_155 = F_81 ( & V_73 -> V_155 ) ;
V_157 = V_73 -> V_157 ;
if ( V_157 ) {
V_157 -> V_158 = V_73 -> V_159 ;
V_157 -> V_160 = V_73 -> V_161 ;
}
F_60 ( V_73 ) ;
F_89 () ;
F_40 ( & V_3 -> V_46 ) ;
if ( error ) {
if ( V_157 )
F_135 ( V_157 ) ;
F_98 ( V_156 ) ;
} else {
if ( V_157 )
F_139 ( V_157 , 0 ) ;
F_85 ( V_156 ) ;
}
F_133 ( V_3 , V_155 ) ;
}
static void F_140 ( void * V_79 , int V_154 )
{
struct V_72 * V_73 = V_79 ;
F_138 ( V_73 , V_154 ) ;
}
static void F_141 ( int V_113 , unsigned long V_114 , void * V_79 )
{
struct V_72 * V_73 = V_79 ;
struct V_2 * V_3 = V_73 -> V_38 ;
if ( V_113 || V_114 )
F_138 ( V_73 , 0 ) ;
else
V_3 -> V_7 -> type -> V_162 ( V_3 -> V_7 , & V_73 -> V_68 ,
F_140 , V_73 ) ;
}
static void F_142 ( struct V_72 * V_73 )
{
struct V_2 * V_3 = V_73 -> V_38 ;
struct V_101 V_102 , V_103 ;
struct V_10 * V_31 = V_3 -> V_4 -> V_31 ;
T_1 V_163 ;
V_163 = F_73 ( V_31 ) ;
V_102 . V_31 = V_31 ;
V_102 . V_110 = F_3 ( V_3 -> V_7 , V_73 -> V_68 . V_69 ) ;
V_102 . V_42 = F_74 ( ( T_1 ) V_3 -> V_7 -> V_51 , V_163 - V_102 . V_110 ) ;
V_103 . V_31 = V_3 -> V_5 -> V_31 ;
V_103 . V_110 = F_3 ( V_3 -> V_7 , V_73 -> V_68 . V_78 ) ;
V_103 . V_42 = V_102 . V_42 ;
F_97 ( V_3 -> V_111 , & V_102 , 1 , & V_103 , 0 , F_141 , V_73 ) ;
}
static void V_159 ( struct V_91 * V_91 , int error )
{
void * V_164 = V_91 -> V_160 ;
F_143 ( V_164 , 0 , error ? 1 : 0 ) ;
}
static void F_144 ( struct V_72 * V_73 ,
struct V_91 * V_91 )
{
struct V_2 * V_3 = V_73 -> V_38 ;
void * V_164 ;
V_73 -> V_157 = V_91 ;
V_73 -> V_159 = V_91 -> V_158 ;
V_73 -> V_161 = V_91 -> V_160 ;
V_164 = F_145 ( V_3 -> V_111 ,
F_141 , V_73 ) ;
V_91 -> V_158 = V_159 ;
V_91 -> V_160 = V_164 ;
F_132 ( V_91 ) ;
}
static struct V_72 *
F_146 ( struct V_2 * V_3 , T_2 V_8 )
{
struct V_65 * V_68 = F_53 ( & V_3 -> V_88 , V_8 ) ;
if ( ! V_68 )
return NULL ;
return F_147 ( V_68 , struct V_72 , V_68 ) ;
}
static struct V_72 *
F_148 ( struct V_2 * V_3 ,
struct V_72 * V_73 , T_2 V_8 )
{
struct V_72 * V_165 ;
V_165 = F_146 ( V_3 , V_8 ) ;
if ( V_165 ) {
F_60 ( V_73 ) ;
return V_165 ;
}
V_73 -> V_68 . V_69 = V_8 ;
F_113 ( & V_73 -> V_155 ) ;
F_113 ( & V_73 -> V_156 ) ;
V_73 -> V_166 = 0 ;
V_73 -> V_157 = NULL ;
if ( V_3 -> V_7 -> type -> V_167 ( V_3 -> V_7 , & V_73 -> V_68 ) ) {
F_60 ( V_73 ) ;
return NULL ;
}
F_63 ( & V_3 -> V_88 , & V_73 -> V_68 ) ;
return V_73 ;
}
static void F_149 ( struct V_2 * V_3 , struct V_65 * V_68 ,
struct V_91 * V_91 , T_2 V_8 )
{
V_91 -> V_168 = V_3 -> V_5 -> V_31 ;
V_91 -> V_169 = F_3 ( V_3 -> V_7 ,
F_65 ( V_68 -> V_78 ) +
( V_8 - V_68 -> V_69 ) ) +
( V_91 -> V_169 &
V_3 -> V_7 -> V_170 ) ;
}
static int F_150 ( struct V_117 * V_45 , struct V_91 * V_91 ,
union V_171 * V_172 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_45 -> V_140 ;
int V_54 = V_150 ;
T_2 V_8 ;
struct V_72 * V_73 = NULL ;
if ( V_91 -> V_173 & V_174 ) {
V_91 -> V_168 = V_3 -> V_5 -> V_31 ;
return V_150 ;
}
V_8 = F_151 ( V_3 -> V_7 , V_91 -> V_169 ) ;
if ( ! V_3 -> V_108 )
return - V_152 ;
F_39 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 ) {
V_54 = - V_152 ;
goto V_175;
}
V_68 = F_53 ( & V_3 -> V_82 , V_8 ) ;
if ( V_68 ) {
F_149 ( V_3 , V_68 , V_91 , V_8 ) ;
goto V_175;
}
if ( F_152 ( V_91 ) == V_176 ) {
V_73 = F_146 ( V_3 , V_8 ) ;
if ( ! V_73 ) {
F_40 ( & V_3 -> V_46 ) ;
V_73 = F_58 ( V_3 ) ;
F_39 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 ) {
F_60 ( V_73 ) ;
V_54 = - V_152 ;
goto V_175;
}
V_68 = F_53 ( & V_3 -> V_82 , V_8 ) ;
if ( V_68 ) {
F_60 ( V_73 ) ;
F_149 ( V_3 , V_68 , V_91 , V_8 ) ;
goto V_175;
}
V_73 = F_148 ( V_3 , V_73 , V_8 ) ;
if ( ! V_73 ) {
F_136 ( V_3 , - V_29 ) ;
V_54 = - V_152 ;
goto V_175;
}
}
F_149 ( V_3 , & V_73 -> V_68 , V_91 , V_8 ) ;
V_54 = V_177 ;
if ( ! V_73 -> V_166 &&
V_91 -> V_178 == ( V_3 -> V_7 -> V_51 << V_179 ) ) {
V_73 -> V_166 = 1 ;
F_40 ( & V_3 -> V_46 ) ;
F_144 ( V_73 , V_91 ) ;
goto V_44;
}
F_153 ( & V_73 -> V_156 , V_91 ) ;
if ( ! V_73 -> V_166 ) {
V_73 -> V_166 = 1 ;
F_40 ( & V_3 -> V_46 ) ;
F_142 ( V_73 ) ;
goto V_44;
}
} else {
V_91 -> V_168 = V_3 -> V_4 -> V_31 ;
V_172 -> V_115 = F_5 ( V_3 , V_8 ) ;
}
V_175:
F_40 ( & V_3 -> V_46 ) ;
V_44:
return V_54 ;
}
static int F_154 ( struct V_117 * V_45 , struct V_91 * V_91 ,
union V_171 * V_172 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_45 -> V_140 ;
int V_54 = V_150 ;
T_2 V_8 ;
if ( V_91 -> V_173 & V_174 ) {
if ( ! V_172 -> V_180 )
V_91 -> V_168 = V_3 -> V_4 -> V_31 ;
else
V_91 -> V_168 = V_3 -> V_5 -> V_31 ;
V_172 -> V_115 = NULL ;
return V_150 ;
}
V_8 = F_151 ( V_3 -> V_7 , V_91 -> V_169 ) ;
F_39 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 )
goto V_181;
V_68 = F_53 ( & V_3 -> V_82 , V_8 ) ;
if ( V_68 ) {
if ( F_152 ( V_91 ) == V_176 &&
V_8 >= V_3 -> V_92 &&
V_8 < ( V_3 -> V_92 +
V_3 -> V_93 ) ) {
V_91 -> V_168 = V_3 -> V_4 -> V_31 ;
F_153 ( & V_3 -> V_94 , V_91 ) ;
V_54 = V_177 ;
goto V_175;
}
F_149 ( V_3 , V_68 , V_91 , V_8 ) ;
if ( F_152 ( V_91 ) == V_176 )
V_172 -> V_115 = F_5 ( V_3 , V_8 ) ;
goto V_175;
}
V_181:
V_91 -> V_168 = V_3 -> V_4 -> V_31 ;
if ( F_152 ( V_91 ) == V_176 ) {
F_40 ( & V_3 -> V_46 ) ;
return F_134 ( V_3 -> V_4 , V_91 ) ;
}
V_175:
F_40 ( & V_3 -> V_46 ) ;
return V_54 ;
}
static int F_155 ( struct V_117 * V_45 , struct V_91 * V_91 ,
int error , union V_171 * V_172 )
{
struct V_2 * V_3 = V_45 -> V_140 ;
struct V_13 * V_14 = V_172 -> V_115 ;
if ( V_14 )
F_11 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_156 ( struct V_117 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_140 ;
F_103 ( V_3 ) ;
}
static int F_157 ( struct V_117 * V_45 )
{
int V_54 = 0 ;
struct V_2 * V_3 = V_45 -> V_140 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_34 ( & V_30 ) ;
( void ) F_32 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 ) {
F_34 ( & V_39 -> V_46 ) ;
if ( V_3 == V_39 ) {
F_22 ( L_34
L_35 ) ;
V_54 = - V_47 ;
} else if ( ! F_158 ( V_39 -> V_45 ) ) {
F_22 ( L_36
L_37 ) ;
V_54 = - V_47 ;
}
F_35 ( & V_39 -> V_46 ) ;
}
F_35 ( & V_30 ) ;
return V_54 ;
}
static void F_159 ( struct V_117 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_140 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_34 ( & V_30 ) ;
( void ) F_32 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 ) {
F_39 ( & V_39 -> V_46 ) ;
F_160 ( & V_40 -> V_46 , V_182 ) ;
F_126 ( V_39 , V_40 ) ;
F_40 ( & V_40 -> V_46 ) ;
F_40 ( & V_39 -> V_46 ) ;
}
F_35 ( & V_30 ) ;
F_41 ( V_3 ) ;
F_39 ( & V_3 -> V_46 ) ;
V_3 -> V_43 = 1 ;
F_40 ( & V_3 -> V_46 ) ;
}
static T_3 F_161 ( struct V_10 * V_31 )
{
T_3 V_183 ;
F_34 ( & V_30 ) ;
V_183 = F_69 ( F_28 ( V_31 ) ) ;
F_35 ( & V_30 ) ;
return V_183 ;
}
static void F_162 ( struct V_117 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_140 ;
F_159 ( V_45 ) ;
V_45 -> V_147 = F_161 ( V_3 -> V_4 -> V_31 ) ;
F_99 ( V_3 ) ;
}
static int F_163 ( struct V_117 * V_45 , T_6 type ,
unsigned V_184 , char * V_185 , unsigned V_186 )
{
unsigned V_187 = 0 ;
struct V_2 * V_38 = V_45 -> V_140 ;
switch ( type ) {
case V_188 :
F_39 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 )
F_164 ( L_38 ) ;
else if ( V_38 -> V_109 )
F_164 ( L_39 ) ;
else {
if ( V_38 -> V_7 -> type -> V_189 ) {
T_1 V_190 , V_191 ,
V_192 ;
V_38 -> V_7 -> type -> V_189 ( V_38 -> V_7 ,
& V_190 ,
& V_191 ,
& V_192 ) ;
F_164 ( L_40 ,
( unsigned long long ) V_191 ,
( unsigned long long ) V_190 ,
( unsigned long long ) V_192 ) ;
}
else
F_164 ( L_41 ) ;
}
F_40 ( & V_38 -> V_46 ) ;
break;
case V_193 :
F_164 ( L_42 , V_38 -> V_4 -> V_194 , V_38 -> V_5 -> V_194 ) ;
V_38 -> V_7 -> type -> V_195 ( V_38 -> V_7 , type , V_185 + V_187 ,
V_186 - V_187 ) ;
break;
}
return 0 ;
}
static int F_165 ( struct V_117 * V_45 ,
T_7 V_196 , void * V_197 )
{
struct V_2 * V_38 = V_45 -> V_140 ;
int V_54 ;
V_54 = V_196 ( V_45 , V_38 -> V_4 , 0 , V_45 -> V_198 , V_197 ) ;
if ( ! V_54 )
V_54 = V_196 ( V_45 , V_38 -> V_5 , 0 , F_73 ( V_38 -> V_5 -> V_31 ) , V_197 ) ;
return V_54 ;
}
static int F_166 ( struct V_27 * V_55 , T_1 V_110 ,
struct V_91 * V_91 )
{
int V_54 = V_150 ;
struct V_2 * V_38 ;
struct V_65 * V_68 ;
struct V_72 * V_73 ;
struct V_72 * V_199 = NULL ;
struct V_72 * V_200 = NULL ;
T_2 V_8 ;
F_29 (snap, snapshots, list) {
if ( F_33 ( V_38 -> V_45 ) )
continue;
F_39 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 || ! V_38 -> V_43 )
goto V_201;
if ( V_110 >= F_167 ( V_38 -> V_45 -> V_61 ) )
goto V_201;
V_8 = F_151 ( V_38 -> V_7 , V_110 ) ;
V_68 = F_53 ( & V_38 -> V_82 , V_8 ) ;
if ( V_68 )
goto V_201;
V_73 = F_146 ( V_38 , V_8 ) ;
if ( ! V_73 ) {
F_40 ( & V_38 -> V_46 ) ;
V_73 = F_58 ( V_38 ) ;
F_39 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 ) {
F_60 ( V_73 ) ;
goto V_201;
}
V_68 = F_53 ( & V_38 -> V_82 , V_8 ) ;
if ( V_68 ) {
F_60 ( V_73 ) ;
goto V_201;
}
V_73 = F_148 ( V_38 , V_73 , V_8 ) ;
if ( ! V_73 ) {
F_136 ( V_38 , - V_29 ) ;
goto V_201;
}
}
V_54 = V_177 ;
if ( V_91 ) {
F_153 ( & V_73 -> V_155 , V_91 ) ;
V_91 = NULL ;
if ( ! V_73 -> V_166 ) {
V_73 -> V_166 = 1 ;
V_200 = V_73 ;
}
}
if ( ! V_73 -> V_166 ) {
V_73 -> V_166 = 1 ;
V_199 = V_73 ;
}
V_201:
F_40 ( & V_38 -> V_46 ) ;
if ( V_199 ) {
F_142 ( V_199 ) ;
V_199 = NULL ;
}
}
if ( V_200 )
F_142 ( V_200 ) ;
return V_54 ;
}
static int F_134 ( struct V_1 * V_4 , struct V_91 * V_91 )
{
struct V_4 * V_35 ;
int V_54 = V_150 ;
F_34 ( & V_30 ) ;
V_35 = F_28 ( V_4 -> V_31 ) ;
if ( V_35 )
V_54 = F_166 ( & V_35 -> V_55 , V_91 -> V_169 , V_91 ) ;
F_35 ( & V_30 ) ;
return V_54 ;
}
static int F_95 ( struct V_2 * V_202 ,
T_1 V_110 , unsigned V_58 )
{
int V_203 = 0 ;
T_1 V_148 ;
struct V_4 * V_35 ;
F_34 ( & V_30 ) ;
V_35 = F_28 ( V_202 -> V_4 -> V_31 ) ;
for ( V_148 = 0 ; V_148 < V_58 ; V_148 += V_202 -> V_45 -> V_147 )
if ( F_166 ( & V_35 -> V_55 , V_110 + V_148 , NULL ) ==
V_177 )
V_203 = 1 ;
F_35 ( & V_30 ) ;
return V_203 ;
}
static int F_168 ( struct V_117 * V_45 , unsigned int V_118 , char * * V_119 )
{
int V_54 ;
struct V_1 * V_204 ;
if ( V_118 != 1 ) {
V_45 -> error = L_43 ;
return - V_47 ;
}
V_54 = F_108 ( V_45 , V_119 [ 0 ] , F_109 ( V_45 -> V_61 ) , & V_204 ) ;
if ( V_54 ) {
V_45 -> error = L_44 ;
return V_54 ;
}
V_45 -> V_140 = V_204 ;
V_45 -> V_123 = 1 ;
return 0 ;
}
static void F_169 ( struct V_117 * V_45 )
{
struct V_1 * V_204 = V_45 -> V_140 ;
F_124 ( V_45 , V_204 ) ;
}
static int F_170 ( struct V_117 * V_45 , struct V_91 * V_91 ,
union V_171 * V_172 )
{
struct V_1 * V_204 = V_45 -> V_140 ;
V_91 -> V_168 = V_204 -> V_31 ;
if ( V_91 -> V_173 & V_174 )
return V_150 ;
return ( F_152 ( V_91 ) == V_176 ) ? F_134 ( V_204 , V_91 ) : V_150 ;
}
static void F_171 ( struct V_117 * V_45 )
{
struct V_1 * V_204 = V_45 -> V_140 ;
V_45 -> V_147 = F_161 ( V_204 -> V_31 ) ;
}
static int F_172 ( struct V_117 * V_45 , T_6 type ,
unsigned V_184 , char * V_185 , unsigned V_186 )
{
struct V_1 * V_204 = V_45 -> V_140 ;
switch ( type ) {
case V_188 :
V_185 [ 0 ] = '\0' ;
break;
case V_193 :
snprintf ( V_185 , V_186 , L_45 , V_204 -> V_194 ) ;
break;
}
return 0 ;
}
static int F_173 ( struct V_117 * V_45 , struct V_205 * V_206 ,
struct V_207 * V_208 , int V_209 )
{
struct V_1 * V_204 = V_45 -> V_140 ;
struct V_210 * V_211 = F_174 ( V_204 -> V_31 ) ;
if ( ! V_211 -> V_212 )
return V_209 ;
V_206 -> V_168 = V_204 -> V_31 ;
return F_74 ( V_209 , V_211 -> V_212 ( V_211 , V_206 , V_208 ) ) ;
}
static int F_175 ( struct V_117 * V_45 ,
T_7 V_196 , void * V_197 )
{
struct V_1 * V_204 = V_45 -> V_140 ;
return V_196 ( V_45 , V_204 , 0 , V_45 -> V_198 , V_197 ) ;
}
static int T_8 F_176 ( void )
{
int V_54 ;
V_54 = F_177 () ;
if ( V_54 ) {
F_22 ( L_46 ) ;
return V_54 ;
}
V_54 = F_178 ( & V_213 ) ;
if ( V_54 < 0 ) {
F_22 ( L_47 , V_54 ) ;
goto V_214;
}
V_54 = F_178 ( & V_215 ) ;
if ( V_54 < 0 ) {
F_22 ( L_48 , V_54 ) ;
goto V_216;
}
V_54 = F_178 ( & V_217 ) ;
if ( V_54 < 0 ) {
F_22 ( L_49 , V_54 ) ;
goto V_218;
}
V_54 = F_20 () ;
if ( V_54 ) {
F_22 ( L_50 ) ;
goto V_219;
}
V_70 = F_179 ( V_65 , 0 ) ;
if ( ! V_70 ) {
F_22 ( L_51 ) ;
V_54 = - V_29 ;
goto V_220;
}
V_135 = F_179 ( V_72 , 0 ) ;
if ( ! V_135 ) {
F_22 ( L_52 ) ;
V_54 = - V_29 ;
goto V_221;
}
V_137 = F_179 ( V_13 , 0 ) ;
if ( ! V_137 ) {
F_22 ( L_53 ) ;
V_54 = - V_29 ;
goto V_222;
}
return 0 ;
V_222:
F_180 ( V_135 ) ;
V_221:
F_180 ( V_70 ) ;
V_220:
F_25 () ;
V_219:
F_181 ( & V_217 ) ;
V_218:
F_181 ( & V_215 ) ;
V_216:
F_181 ( & V_213 ) ;
V_214:
F_182 () ;
return V_54 ;
}
static void T_9 F_183 ( void )
{
F_181 ( & V_213 ) ;
F_181 ( & V_215 ) ;
F_181 ( & V_217 ) ;
F_25 () ;
F_180 ( V_135 ) ;
F_180 ( V_70 ) ;
F_180 ( V_137 ) ;
F_182 () ;
}
