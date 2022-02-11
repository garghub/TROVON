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
V_27 = F_24 ( V_23 * sizeof( struct V_24 ) ,
V_25 ) ;
if ( ! V_27 ) {
F_25 ( L_2 ) ;
F_27 ( V_22 ) ;
return - V_26 ;
}
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ )
F_26 ( V_27 + V_21 ) ;
F_28 ( & V_28 ) ;
return 0 ;
}
static void F_29 ( void )
{
F_27 ( V_22 ) ;
F_27 ( V_27 ) ;
}
static unsigned F_30 ( struct V_10 * V_29 )
{
return V_29 -> V_30 & V_31 ;
}
static struct V_4 * F_31 ( struct V_10 * V_4 )
{
struct V_24 * V_32 ;
struct V_4 * V_33 ;
V_32 = & V_22 [ F_30 ( V_4 ) ] ;
F_32 (o, ol, hash_list)
if ( F_4 ( V_33 -> V_29 , V_4 ) )
return V_33 ;
return NULL ;
}
static void F_33 ( struct V_4 * V_33 )
{
struct V_24 * V_34 = & V_22 [ F_30 ( V_33 -> V_29 ) ] ;
F_34 ( & V_33 -> V_35 , V_34 ) ;
}
static struct V_36 * F_35 ( struct V_10 * V_4 )
{
struct V_24 * V_32 ;
struct V_36 * V_33 ;
V_32 = & V_27 [ F_30 ( V_4 ) ] ;
F_32 (o, ol, hash_list)
if ( F_4 ( V_33 -> V_37 -> V_29 , V_4 ) )
return V_33 ;
return NULL ;
}
static void F_36 ( struct V_36 * V_33 )
{
struct V_24 * V_34 = & V_27 [ F_30 ( V_33 -> V_37 -> V_29 ) ] ;
F_34 ( & V_33 -> V_35 , V_34 ) ;
}
static void F_37 ( struct V_36 * V_33 )
{
F_38 ( & V_33 -> V_35 ) ;
}
static int F_39 ( struct V_2 * V_38 ,
struct V_2 * * V_39 ,
struct V_2 * * V_40 ,
struct V_2 * * V_41 )
{
struct V_2 * V_3 ;
struct V_4 * V_33 ;
int V_42 = 0 ;
int V_43 ;
V_33 = F_31 ( V_38 -> V_4 -> V_29 ) ;
if ( ! V_33 )
goto V_44;
F_32 (s, &o->snapshots, list) {
if ( F_40 ( V_3 -> V_45 ) && V_41 )
* V_41 = V_3 ;
if ( ! F_4 ( V_3 -> V_5 -> V_29 , V_38 -> V_5 -> V_29 ) )
continue;
F_41 ( & V_3 -> V_46 ) ;
V_43 = V_3 -> V_43 ;
F_42 ( & V_3 -> V_46 ) ;
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
static int F_43 ( struct V_2 * V_38 )
{
struct V_2 * V_39 = NULL , * V_40 = NULL ;
struct V_2 * V_41 = NULL ;
if ( ( F_39 ( V_38 , & V_39 , & V_40 ,
& V_41 ) == 2 ) ||
V_40 ) {
V_38 -> V_45 -> error = L_3
L_4 ;
return - V_47 ;
}
if ( ! V_39 )
return 0 ;
if ( ! F_40 ( V_38 -> V_45 ) )
return 1 ;
if ( V_41 ) {
V_38 -> V_45 -> error = L_5 ;
return - V_47 ;
}
if ( ! V_39 -> V_7 -> type -> V_48 ||
! V_39 -> V_7 -> type -> V_49 ) {
V_38 -> V_45 -> error = L_6
L_7 ;
return - V_47 ;
}
return 1 ;
}
static void F_44 ( struct V_4 * V_33 , struct V_2 * V_3 )
{
struct V_2 * V_50 ;
F_32 (l, &o->snapshots, list)
if ( V_50 -> V_7 -> V_51 < V_3 -> V_7 -> V_51 )
break;
F_34 ( & V_3 -> V_52 , & V_50 -> V_52 ) ;
}
static int F_45 ( struct V_2 * V_38 )
{
struct V_4 * V_33 , * V_53 = NULL ;
struct V_10 * V_29 = V_38 -> V_4 -> V_29 ;
int V_54 = 0 ;
V_53 = F_24 ( sizeof( * V_53 ) , V_25 ) ;
if ( ! V_53 )
return - V_26 ;
F_46 ( & V_28 ) ;
V_54 = F_43 ( V_38 ) ;
if ( V_54 < 0 ) {
F_27 ( V_53 ) ;
goto V_44;
}
V_33 = F_31 ( V_29 ) ;
if ( V_33 )
F_27 ( V_53 ) ;
else {
V_33 = V_53 ;
F_26 ( & V_33 -> V_55 ) ;
V_33 -> V_29 = V_29 ;
F_33 ( V_33 ) ;
}
F_44 ( V_33 , V_38 ) ;
V_44:
F_47 ( & V_28 ) ;
return V_54 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_10 * V_29 = V_3 -> V_4 -> V_29 ;
F_46 ( & V_28 ) ;
F_38 ( & V_3 -> V_52 ) ;
F_44 ( F_31 ( V_29 ) , V_3 ) ;
F_47 ( & V_28 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_33 ;
F_46 ( & V_28 ) ;
V_33 = F_31 ( V_3 -> V_4 -> V_29 ) ;
F_38 ( & V_3 -> V_52 ) ;
if ( V_33 && F_50 ( & V_33 -> V_55 ) ) {
F_38 ( & V_33 -> V_35 ) ;
F_27 ( V_33 ) ;
}
F_47 ( & V_28 ) ;
}
static int F_51 ( struct V_56 * V_57 ,
T_3 V_58 , unsigned V_59 )
{
unsigned int V_21 ;
V_57 -> V_59 = V_59 ;
V_57 -> V_60 = V_58 - 1 ;
V_57 -> V_61 = F_52 ( V_58 , sizeof( struct V_24 ) ) ;
if ( ! V_57 -> V_61 )
return - V_26 ;
for ( V_21 = 0 ; V_21 < V_58 ; V_21 ++ )
F_26 ( V_57 -> V_61 + V_21 ) ;
return 0 ;
}
static void F_53 ( struct V_56 * V_57 ,
struct V_62 * V_63 )
{
struct V_24 * V_64 ;
struct V_65 * V_66 , * V_67 ;
int V_21 , V_58 ;
V_58 = V_57 -> V_60 + 1 ;
for ( V_21 = 0 ; V_21 < V_58 ; V_21 ++ ) {
V_64 = V_57 -> V_61 + V_21 ;
F_54 (ex, next, slot, hash_list)
F_55 ( V_63 , V_66 ) ;
}
F_56 ( V_57 -> V_61 ) ;
}
static T_3 F_57 ( struct V_56 * V_57 , T_2 V_8 )
{
return ( V_8 >> V_57 -> V_59 ) & V_57 -> V_60 ;
}
static void F_58 ( struct V_65 * V_68 )
{
F_38 ( & V_68 -> V_35 ) ;
}
static struct V_65 * F_59 ( struct V_56 * V_57 ,
T_2 V_8 )
{
struct V_24 * V_64 ;
struct V_65 * V_68 ;
V_64 = & V_57 -> V_61 [ F_57 ( V_57 , V_8 ) ] ;
F_32 (e, slot, hash_list)
if ( V_8 >= V_68 -> V_69 &&
V_8 <= V_68 -> V_69 + F_60 ( V_68 ) )
return V_68 ;
return NULL ;
}
static struct V_65 * F_61 ( T_4 V_70 )
{
struct V_65 * V_68 ;
V_68 = F_62 ( V_71 , V_70 ) ;
if ( ! V_68 && V_70 == V_72 )
V_68 = F_62 ( V_71 , V_73 ) ;
return V_68 ;
}
static void F_63 ( struct V_65 * V_68 )
{
F_55 ( V_71 , V_68 ) ;
}
static struct V_74 * F_64 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = F_65 ( V_3 -> V_76 ,
V_72 ) ;
F_66 ( & V_3 -> V_77 ) ;
V_75 -> V_38 = V_3 ;
return V_75 ;
}
static void F_67 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
F_68 ( V_75 , V_3 -> V_76 ) ;
F_69 () ;
F_70 ( & V_3 -> V_77 ) ;
}
static void F_71 ( struct V_56 * V_78 ,
struct V_65 * V_79 )
{
struct V_24 * V_50 ;
struct V_65 * V_68 = NULL ;
V_50 = & V_78 -> V_61 [ F_57 ( V_78 , V_79 -> V_69 ) ] ;
if ( ! V_78 -> V_59 )
goto V_44;
F_72 (e, l, hash_list) {
if ( V_79 -> V_69 == ( V_68 -> V_69 +
F_60 ( V_68 ) + 1 ) &&
V_79 -> V_80 == ( F_73 ( V_68 -> V_80 ) +
F_60 ( V_68 ) + 1 ) ) {
F_74 ( V_68 ) ;
F_63 ( V_79 ) ;
return;
}
if ( V_79 -> V_69 == ( V_68 -> V_69 - 1 ) &&
V_79 -> V_80 == ( F_73 ( V_68 -> V_80 ) - 1 ) ) {
F_74 ( V_68 ) ;
V_68 -> V_69 -- ;
V_68 -> V_80 -- ;
F_63 ( V_79 ) ;
return;
}
if ( V_79 -> V_69 > V_68 -> V_69 )
break;
}
V_44:
F_75 ( & V_79 -> V_35 , V_68 ? & V_68 -> V_35 : V_50 ) ;
}
static int F_76 ( void * V_81 , T_2 V_82 , T_2 V_83 )
{
struct V_2 * V_3 = V_81 ;
struct V_65 * V_68 ;
V_68 = F_61 ( V_25 ) ;
if ( ! V_68 )
return - V_26 ;
V_68 -> V_69 = V_82 ;
V_68 -> V_80 = V_83 ;
F_71 ( & V_3 -> V_84 , V_68 ) ;
return 0 ;
}
static T_3 F_77 ( struct V_4 * V_33 )
{
struct V_2 * V_38 ;
unsigned V_51 = 0 ;
if ( V_33 )
F_32 (snap, &o->snapshots, list)
V_51 = F_78 ( V_51 ,
V_38 -> V_7 -> V_51 ) ;
return ( T_3 ) V_51 ;
}
static int F_79 ( void )
{
unsigned long V_63 = 2 * 1024 * 1024 ;
V_63 /= sizeof( struct V_24 ) ;
return V_63 ;
}
static int F_80 ( struct V_2 * V_3 )
{
T_1 V_85 , V_86 , V_87 ;
V_86 = F_81 ( V_3 -> V_5 -> V_29 ) ;
V_87 = F_79 () ;
V_85 = V_86 >> V_3 -> V_7 -> V_9 ;
V_85 = F_82 ( V_85 , V_87 ) ;
if ( V_85 < 64 )
V_85 = 64 ;
V_85 = F_83 ( V_85 ) ;
if ( F_51 ( & V_3 -> V_84 , V_85 ,
V_88 ) )
return - V_26 ;
V_85 >>= 3 ;
if ( V_85 < 64 )
V_85 = 64 ;
if ( F_51 ( & V_3 -> V_89 , V_85 , 0 ) ) {
F_53 ( & V_3 -> V_84 , V_71 ) ;
return - V_26 ;
}
return 0 ;
}
static void F_84 ( struct V_2 * V_3 )
{
F_85 ( V_90 , & V_3 -> V_91 ) ;
F_86 () ;
F_87 ( & V_3 -> V_91 , V_90 ) ;
}
static struct V_13 * F_88 ( struct V_2 * V_3 )
{
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
return F_89 ( & V_3 -> V_94 ) ;
}
static int F_90 ( struct V_2 * V_3 ,
T_2 V_69 )
{
struct V_65 * V_68 ;
V_68 = F_59 ( & V_3 -> V_84 , V_69 ) ;
if ( ! V_68 ) {
F_25 ( L_8
L_9 ,
( unsigned long long ) V_69 ) ;
return - V_47 ;
}
if ( ! F_60 ( V_68 ) ) {
F_58 ( V_68 ) ;
F_63 ( V_68 ) ;
return 0 ;
}
if ( V_69 == V_68 -> V_69 ) {
V_68 -> V_69 ++ ;
V_68 -> V_80 ++ ;
} else if ( V_69 != V_68 -> V_69 +
F_60 ( V_68 ) ) {
F_25 ( L_10
L_11 ,
( unsigned long long ) V_69 ,
( unsigned long long ) V_68 -> V_69 ,
( unsigned long long )
V_68 -> V_69 + F_60 ( V_68 ) ) ;
return - V_47 ;
}
F_91 ( V_68 ) ;
return 0 ;
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_13 * V_95 = NULL ;
int V_54 ;
T_2 V_69 = V_3 -> V_92 + V_3 -> V_93 - 1 ;
F_46 ( & V_3 -> V_46 ) ;
do {
V_54 = F_90 ( V_3 , V_69 ) ;
if ( V_54 )
goto V_44;
} while ( V_69 -- > V_3 -> V_92 );
V_95 = F_88 ( V_3 ) ;
V_44:
F_47 ( & V_3 -> V_46 ) ;
if ( V_95 )
F_93 ( V_95 ) ;
return V_54 ;
}
static T_5 F_94 ( void )
{
T_5 V_96 ;
F_95 ( & V_97 ) ;
V_96 = V_98 ;
F_96 ( & V_97 ) ;
return V_96 ;
}
static void F_97 ( void )
{
F_95 ( & V_97 ) ;
V_98 ++ ;
F_96 ( & V_97 ) ;
F_98 ( & V_99 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
int V_21 , V_100 ;
T_2 V_69 , V_80 ;
struct V_101 V_102 , V_103 ;
T_1 V_104 ;
T_5 V_105 ;
F_100 ( ! F_101 ( V_90 , & V_3 -> V_91 ) ) ;
if ( F_102 ( F_101 ( V_106 , & V_3 -> V_91 ) ) )
goto V_107;
if ( ! V_3 -> V_108 ) {
F_25 ( L_12 ) ;
goto V_107;
}
V_100 = V_3 -> V_7 -> type -> V_48 ( V_3 -> V_7 , & V_69 ,
& V_80 ) ;
if ( V_100 <= 0 ) {
if ( V_100 < 0 ) {
F_25 ( L_13
L_14 ) ;
F_46 ( & V_3 -> V_46 ) ;
V_3 -> V_109 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
}
goto V_107;
}
V_69 = V_69 + 1 - V_100 ;
V_80 = V_80 + 1 - V_100 ;
V_104 = V_100 * V_3 -> V_7 -> V_51 ;
V_103 . V_29 = V_3 -> V_4 -> V_29 ;
V_103 . V_110 = F_3 ( V_3 -> V_7 , V_69 ) ;
V_103 . V_42 = F_82 ( V_104 , F_81 ( V_103 . V_29 ) - V_103 . V_110 ) ;
V_102 . V_29 = V_3 -> V_5 -> V_29 ;
V_102 . V_110 = F_3 ( V_3 -> V_7 , V_80 ) ;
V_102 . V_42 = V_103 . V_42 ;
V_105 = F_94 () ;
while ( F_103 ( V_3 , V_103 . V_110 , V_104 ) ) {
F_104 ( V_99 ,
( F_94 () !=
V_105 ) ) ;
V_105 = F_94 () ;
}
F_46 ( & V_3 -> V_46 ) ;
V_3 -> V_92 = V_69 ;
V_3 -> V_93 = V_100 ;
F_47 ( & V_3 -> V_46 ) ;
for ( V_21 = 0 ; V_21 < V_100 ; V_21 ++ )
F_21 ( V_3 , V_69 + V_21 ) ;
F_105 ( V_3 -> V_111 , & V_102 , 1 , & V_103 , 0 , V_112 , V_3 ) ;
return;
V_107:
F_84 ( V_3 ) ;
}
static void V_112 ( int V_113 , unsigned long V_114 , void * V_81 )
{
struct V_2 * V_3 = V_81 ;
struct V_13 * V_95 = NULL ;
if ( V_113 || V_114 ) {
if ( V_113 )
F_25 ( L_15 ) ;
else
F_25 ( L_16 ) ;
goto V_107;
}
if ( V_3 -> V_7 -> type -> V_49 ( V_3 -> V_7 ,
V_3 -> V_93 ) < 0 ) {
F_25 ( L_17 ) ;
goto V_107;
}
if ( F_92 ( V_3 ) < 0 )
goto V_107;
F_99 ( V_3 ) ;
return;
V_107:
F_46 ( & V_3 -> V_46 ) ;
V_3 -> V_109 = 1 ;
V_95 = F_88 ( V_3 ) ;
F_47 ( & V_3 -> V_46 ) ;
F_106 ( V_95 ) ;
F_84 ( V_3 ) ;
}
static void F_107 ( struct V_2 * V_3 )
{
if ( ! F_108 ( V_90 , & V_3 -> V_91 ) )
F_99 ( V_3 ) ;
}
static void F_109 ( struct V_2 * V_3 )
{
F_110 ( V_106 , & V_3 -> V_91 ) ;
F_111 ( & V_3 -> V_91 , V_90 , V_115 ) ;
F_112 ( V_106 , & V_3 -> V_91 ) ;
}
static int F_113 ( struct V_116 * V_45 , unsigned int V_117 , char * * V_118 )
{
struct V_2 * V_3 ;
int V_21 ;
int V_54 = - V_47 ;
char * V_119 , * V_120 ;
T_6 V_121 , V_122 ;
unsigned V_123 , V_124 = 1 ;
T_7 V_125 = V_126 ;
if ( V_117 != 4 ) {
V_45 -> error = L_18 ;
V_54 = - V_47 ;
goto V_127;
}
if ( F_40 ( V_45 ) ) {
V_124 = 2 ;
V_125 = V_128 ;
}
V_3 = F_24 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 ) {
V_45 -> error = L_19 ;
V_54 = - V_26 ;
goto V_127;
}
V_119 = V_118 [ 0 ] ;
V_118 ++ ;
V_117 -- ;
V_54 = F_114 ( V_45 , V_119 , V_125 , & V_3 -> V_4 ) ;
if ( V_54 ) {
V_45 -> error = L_20 ;
goto V_129;
}
V_121 = V_3 -> V_4 -> V_29 -> V_30 ;
V_120 = V_118 [ 0 ] ;
V_118 ++ ;
V_117 -- ;
V_122 = F_115 ( V_120 ) ;
if ( V_122 && V_122 == V_121 ) {
V_45 -> error = L_21 ;
V_54 = - V_47 ;
goto V_130;
}
V_54 = F_114 ( V_45 , V_120 , F_116 ( V_45 -> V_61 ) , & V_3 -> V_5 ) ;
if ( V_54 ) {
V_45 -> error = L_22 ;
goto V_130;
}
V_54 = F_117 ( V_45 , V_117 , V_118 , V_3 , & V_123 , & V_3 -> V_7 ) ;
if ( V_54 ) {
V_45 -> error = L_23 ;
V_54 = - V_47 ;
goto V_131;
}
V_118 += V_123 ;
V_117 -= V_123 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_108 = 1 ;
V_3 -> V_132 = 0 ;
V_3 -> V_43 = 0 ;
F_118 ( & V_3 -> V_77 , 0 ) ;
V_3 -> V_133 = 0 ;
V_3 -> V_134 = 0 ;
F_26 ( & V_3 -> V_135 ) ;
F_28 ( & V_3 -> V_46 ) ;
F_26 ( & V_3 -> V_52 ) ;
F_119 ( & V_3 -> V_136 ) ;
V_3 -> V_91 = 0 ;
V_3 -> V_109 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
F_120 ( & V_3 -> V_94 ) ;
if ( F_80 ( V_3 ) ) {
V_45 -> error = L_24 ;
V_54 = - V_26 ;
goto V_137;
}
V_3 -> V_111 = F_121 ( & V_138 ) ;
if ( F_122 ( V_3 -> V_111 ) ) {
V_54 = F_123 ( V_3 -> V_111 ) ;
V_45 -> error = L_25 ;
goto V_139;
}
V_3 -> V_76 = F_124 ( V_140 , V_141 ) ;
if ( ! V_3 -> V_76 ) {
V_45 -> error = L_26 ;
V_54 = - V_26 ;
goto V_142;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ )
F_125 ( & V_3 -> V_18 [ V_21 ] ) ;
F_119 ( & V_3 -> V_17 ) ;
V_45 -> V_144 = V_3 ;
V_45 -> V_124 = V_124 ;
V_45 -> V_145 = sizeof( struct V_14 ) ;
V_54 = F_45 ( V_3 ) ;
if ( V_54 == - V_26 ) {
V_45 -> error = L_27 ;
goto V_146;
} else if ( V_54 < 0 ) {
goto V_146;
}
if ( V_54 > 0 ) {
V_3 -> V_7 -> V_51 = 0 ;
return 0 ;
}
V_54 = V_3 -> V_7 -> type -> V_147 ( V_3 -> V_7 , F_76 ,
( void * ) V_3 ) ;
if ( V_54 < 0 ) {
V_45 -> error = L_28 ;
goto V_148;
} else if ( V_54 > 0 ) {
V_3 -> V_108 = 0 ;
F_126 ( L_29 ) ;
}
if ( ! V_3 -> V_7 -> V_51 ) {
V_45 -> error = L_30 ;
goto V_148;
}
V_54 = F_127 ( V_45 , V_3 -> V_7 -> V_51 ) ;
if ( V_54 )
goto V_148;
return 0 ;
V_148:
F_49 ( V_3 ) ;
V_146:
F_128 ( V_3 -> V_76 ) ;
V_142:
F_129 ( V_3 -> V_111 ) ;
V_139:
F_53 ( & V_3 -> V_89 , V_141 ) ;
F_53 ( & V_3 -> V_84 , V_71 ) ;
V_137:
F_130 ( V_3 -> V_7 ) ;
V_131:
F_131 ( V_45 , V_3 -> V_5 ) ;
V_130:
F_131 ( V_45 , V_3 -> V_4 ) ;
V_129:
F_27 ( V_3 ) ;
V_127:
return V_54 ;
}
static void F_132 ( struct V_2 * V_3 )
{
F_129 ( V_3 -> V_111 ) ;
V_3 -> V_111 = NULL ;
F_53 ( & V_3 -> V_89 , V_141 ) ;
F_53 ( & V_3 -> V_84 , V_71 ) ;
}
static void F_133 ( struct V_2 * V_39 ,
struct V_2 * V_40 )
{
union {
struct V_56 V_149 ;
struct V_6 * V_150 ;
} V_151 ;
V_151 . V_149 = V_40 -> V_84 ;
V_40 -> V_84 = V_39 -> V_84 ;
V_39 -> V_84 = V_151 . V_149 ;
V_151 . V_150 = V_40 -> V_7 ;
V_40 -> V_7 = V_39 -> V_7 ;
V_40 -> V_7 -> V_152 = V_151 . V_150 -> V_152 ;
V_39 -> V_7 = V_151 . V_150 ;
V_40 -> V_7 -> V_38 = V_40 ;
V_39 -> V_7 -> V_38 = V_39 ;
V_40 -> V_45 -> V_153 = V_40 -> V_7 -> V_51 ;
V_40 -> V_108 = V_39 -> V_108 ;
V_40 -> V_132 = V_39 -> V_132 ;
V_39 -> V_108 = 0 ;
}
static void F_134 ( struct V_116 * V_45 )
{
#ifdef F_135
int V_21 ;
#endif
struct V_2 * V_3 = V_45 -> V_144 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_41 ( & V_28 ) ;
( void ) F_39 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 && ( V_3 == V_39 ) ) {
F_46 ( & V_40 -> V_46 ) ;
V_40 -> V_108 = 0 ;
F_47 ( & V_40 -> V_46 ) ;
F_25 ( L_31 ) ;
}
F_42 ( & V_28 ) ;
if ( F_40 ( V_45 ) )
F_109 ( V_3 ) ;
F_49 ( V_3 ) ;
while ( F_136 ( & V_3 -> V_77 ) )
F_22 ( 1 ) ;
F_137 () ;
#ifdef F_135
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ )
F_100 ( ! F_138 ( & V_3 -> V_18 [ V_21 ] ) ) ;
#endif
F_132 ( V_3 ) ;
F_128 ( V_3 -> V_76 ) ;
F_130 ( V_3 -> V_7 ) ;
F_131 ( V_45 , V_3 -> V_5 ) ;
F_131 ( V_45 , V_3 -> V_4 ) ;
F_27 ( V_3 ) ;
}
static void F_93 ( struct V_13 * V_13 )
{
struct V_13 * V_154 ;
while ( V_13 ) {
V_154 = V_13 -> V_155 ;
V_13 -> V_155 = NULL ;
F_139 ( V_13 ) ;
V_13 = V_154 ;
}
}
static void F_140 ( struct V_2 * V_3 , struct V_13 * V_13 )
{
struct V_13 * V_154 ;
int V_54 ;
while ( V_13 ) {
V_154 = V_13 -> V_155 ;
V_13 -> V_155 = NULL ;
V_54 = F_141 ( V_3 -> V_4 , V_13 ) ;
if ( V_54 == V_156 )
F_139 ( V_13 ) ;
V_13 = V_154 ;
}
}
static void F_106 ( struct V_13 * V_13 )
{
struct V_13 * V_154 ;
while ( V_13 ) {
V_154 = V_13 -> V_155 ;
V_13 -> V_155 = NULL ;
F_142 ( V_13 ) ;
V_13 = V_154 ;
}
}
static void F_143 ( struct V_2 * V_3 , int V_157 )
{
if ( ! V_3 -> V_108 )
return;
if ( V_157 == - V_158 )
F_25 ( L_32 ) ;
else if ( V_157 == - V_26 )
F_25 ( L_33 ) ;
if ( V_3 -> V_7 -> type -> V_159 )
V_3 -> V_7 -> type -> V_159 ( V_3 -> V_7 ) ;
V_3 -> V_108 = 0 ;
F_144 ( V_3 -> V_45 -> V_61 ) ;
}
static void F_145 ( void * V_81 , int V_160 )
{
struct V_74 * V_75 = V_81 ;
struct V_65 * V_68 ;
struct V_2 * V_3 = V_75 -> V_38 ;
struct V_13 * V_161 = NULL ;
struct V_13 * V_162 = NULL ;
struct V_13 * V_163 = NULL ;
int error = 0 ;
if ( ! V_160 ) {
F_46 ( & V_3 -> V_46 ) ;
F_143 ( V_3 , - V_158 ) ;
error = 1 ;
goto V_44;
}
V_68 = F_61 ( V_72 ) ;
if ( ! V_68 ) {
F_46 ( & V_3 -> V_46 ) ;
F_143 ( V_3 , - V_26 ) ;
error = 1 ;
goto V_44;
}
* V_68 = V_75 -> V_68 ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 ) {
F_63 ( V_68 ) ;
error = 1 ;
goto V_44;
}
F_21 ( V_3 , V_75 -> V_68 . V_69 ) ;
F_71 ( & V_3 -> V_84 , V_68 ) ;
V_44:
F_58 ( & V_75 -> V_68 ) ;
V_162 = F_89 ( & V_75 -> V_162 ) ;
V_161 = F_89 ( & V_75 -> V_161 ) ;
V_163 = V_75 -> V_163 ;
if ( V_163 )
V_163 -> V_164 = V_75 -> V_165 ;
F_97 () ;
F_47 ( & V_3 -> V_46 ) ;
if ( error ) {
if ( V_163 )
F_142 ( V_163 ) ;
F_106 ( V_162 ) ;
} else {
if ( V_163 )
F_146 ( V_163 ) ;
F_93 ( V_162 ) ;
}
F_140 ( V_3 , V_161 ) ;
F_67 ( V_75 ) ;
}
static void F_147 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
V_3 -> V_7 -> type -> V_166 ( V_3 -> V_7 , & V_75 -> V_68 , ! V_75 -> V_167 ,
F_145 , V_75 ) ;
}
static void F_148 ( int V_113 , unsigned long V_114 , void * V_81 )
{
struct V_74 * V_75 = V_81 ;
struct V_2 * V_3 = V_75 -> V_38 ;
V_75 -> V_167 = V_113 || V_114 ;
if ( V_75 -> V_168 == V_3 -> V_134 ) {
V_3 -> V_134 ++ ;
F_147 ( V_75 ) ;
while ( ! F_50 ( & V_3 -> V_135 ) ) {
V_75 = F_149 ( V_3 -> V_135 . V_67 ,
struct V_74 , V_169 ) ;
if ( V_75 -> V_168 != V_3 -> V_134 )
break;
V_3 -> V_134 ++ ;
F_38 ( & V_75 -> V_169 ) ;
F_147 ( V_75 ) ;
}
} else {
struct V_24 * V_170 ;
struct V_74 * V_171 ;
F_150 (lh, &s->out_of_order_list) {
V_171 = F_149 ( V_170 , struct V_74 , V_169 ) ;
if ( V_171 -> V_168 < V_75 -> V_168 )
break;
}
F_75 ( & V_75 -> V_169 , V_170 ) ;
}
}
static void F_151 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
struct V_101 V_102 , V_103 ;
struct V_10 * V_29 = V_3 -> V_4 -> V_29 ;
T_1 V_172 ;
V_172 = F_81 ( V_29 ) ;
V_102 . V_29 = V_29 ;
V_102 . V_110 = F_3 ( V_3 -> V_7 , V_75 -> V_68 . V_69 ) ;
V_102 . V_42 = F_82 ( ( T_1 ) V_3 -> V_7 -> V_51 , V_172 - V_102 . V_110 ) ;
V_103 . V_29 = V_3 -> V_5 -> V_29 ;
V_103 . V_110 = F_3 ( V_3 -> V_7 , V_75 -> V_68 . V_80 ) ;
V_103 . V_42 = V_102 . V_42 ;
F_105 ( V_3 -> V_111 , & V_102 , 1 , & V_103 , 0 , F_148 , V_75 ) ;
}
static void V_165 ( struct V_13 * V_13 )
{
void * V_173 = V_13 -> V_174 ;
F_152 ( V_173 , 0 , V_13 -> V_175 ? 1 : 0 ) ;
}
static void F_153 ( struct V_74 * V_75 ,
struct V_13 * V_13 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
void * V_173 ;
V_75 -> V_163 = V_13 ;
V_75 -> V_165 = V_13 -> V_164 ;
V_173 = F_154 ( V_3 -> V_111 ,
F_148 , V_75 ) ;
V_13 -> V_164 = V_165 ;
V_13 -> V_174 = V_173 ;
F_139 ( V_13 ) ;
}
static struct V_74 *
F_155 ( struct V_2 * V_3 , T_2 V_8 )
{
struct V_65 * V_68 = F_59 ( & V_3 -> V_89 , V_8 ) ;
if ( ! V_68 )
return NULL ;
return F_156 ( V_68 , struct V_74 , V_68 ) ;
}
static struct V_74 *
F_157 ( struct V_2 * V_3 ,
struct V_74 * V_75 , T_2 V_8 )
{
struct V_74 * V_171 ;
V_171 = F_155 ( V_3 , V_8 ) ;
if ( V_171 ) {
F_67 ( V_75 ) ;
return V_171 ;
}
V_75 -> V_68 . V_69 = V_8 ;
F_120 ( & V_75 -> V_161 ) ;
F_120 ( & V_75 -> V_162 ) ;
V_75 -> V_176 = 0 ;
V_75 -> V_163 = NULL ;
if ( V_3 -> V_7 -> type -> V_177 ( V_3 -> V_7 , & V_75 -> V_68 ) ) {
F_67 ( V_75 ) ;
return NULL ;
}
V_75 -> V_168 = V_3 -> V_133 ++ ;
F_71 ( & V_3 -> V_89 , & V_75 -> V_68 ) ;
return V_75 ;
}
static void F_158 ( struct V_2 * V_3 , struct V_65 * V_68 ,
struct V_13 * V_13 , T_2 V_8 )
{
F_159 ( V_13 , V_3 -> V_5 -> V_29 ) ;
V_13 -> V_178 . V_179 =
F_3 ( V_3 -> V_7 , F_73 ( V_68 -> V_80 ) +
( V_8 - V_68 -> V_69 ) ) +
( V_13 -> V_178 . V_179 & V_3 -> V_7 -> V_180 ) ;
}
static int F_160 ( struct V_116 * V_45 , struct V_13 * V_13 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_45 -> V_144 ;
int V_54 = V_156 ;
T_2 V_8 ;
struct V_74 * V_75 = NULL ;
F_5 ( V_13 ) ;
if ( V_13 -> V_181 & V_182 ) {
F_159 ( V_13 , V_3 -> V_5 -> V_29 ) ;
return V_156 ;
}
V_8 = F_161 ( V_3 -> V_7 , V_13 -> V_178 . V_179 ) ;
if ( ! V_3 -> V_108 )
return V_183 ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 || ( F_102 ( V_3 -> V_132 ) &&
F_162 ( V_13 ) == V_184 ) ) {
V_54 = V_183 ;
goto V_185;
}
V_68 = F_59 ( & V_3 -> V_84 , V_8 ) ;
if ( V_68 ) {
F_158 ( V_3 , V_68 , V_13 , V_8 ) ;
goto V_185;
}
if ( F_162 ( V_13 ) == V_184 ) {
V_75 = F_155 ( V_3 , V_8 ) ;
if ( ! V_75 ) {
F_47 ( & V_3 -> V_46 ) ;
V_75 = F_64 ( V_3 ) ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 || V_3 -> V_132 ) {
F_67 ( V_75 ) ;
V_54 = V_183 ;
goto V_185;
}
V_68 = F_59 ( & V_3 -> V_84 , V_8 ) ;
if ( V_68 ) {
F_67 ( V_75 ) ;
F_158 ( V_3 , V_68 , V_13 , V_8 ) ;
goto V_185;
}
V_75 = F_157 ( V_3 , V_75 , V_8 ) ;
if ( ! V_75 ) {
if ( V_3 -> V_7 -> V_152 ) {
V_3 -> V_132 = 1 ;
F_25 ( L_34 ) ;
} else
F_143 ( V_3 , - V_26 ) ;
V_54 = V_183 ;
goto V_185;
}
}
F_158 ( V_3 , & V_75 -> V_68 , V_13 , V_8 ) ;
V_54 = V_186 ;
if ( ! V_75 -> V_176 &&
V_13 -> V_178 . V_187 ==
( V_3 -> V_7 -> V_51 << V_188 ) ) {
V_75 -> V_176 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
F_153 ( V_75 , V_13 ) ;
goto V_44;
}
F_163 ( & V_75 -> V_162 , V_13 ) ;
if ( ! V_75 -> V_176 ) {
V_75 -> V_176 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
F_151 ( V_75 ) ;
goto V_44;
}
} else {
F_159 ( V_13 , V_3 -> V_4 -> V_29 ) ;
F_10 ( V_3 , V_13 , V_8 ) ;
}
V_185:
F_47 ( & V_3 -> V_46 ) ;
V_44:
return V_54 ;
}
static int F_164 ( struct V_116 * V_45 , struct V_13 * V_13 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_45 -> V_144 ;
int V_54 = V_156 ;
T_2 V_8 ;
F_5 ( V_13 ) ;
if ( V_13 -> V_181 & V_182 ) {
if ( ! F_165 ( V_13 ) )
F_159 ( V_13 , V_3 -> V_4 -> V_29 ) ;
else
F_159 ( V_13 , V_3 -> V_5 -> V_29 ) ;
return V_156 ;
}
V_8 = F_161 ( V_3 -> V_7 , V_13 -> V_178 . V_179 ) ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 )
goto V_189;
V_68 = F_59 ( & V_3 -> V_84 , V_8 ) ;
if ( V_68 ) {
if ( F_162 ( V_13 ) == V_184 &&
V_8 >= V_3 -> V_92 &&
V_8 < ( V_3 -> V_92 +
V_3 -> V_93 ) ) {
F_159 ( V_13 , V_3 -> V_4 -> V_29 ) ;
F_163 ( & V_3 -> V_94 , V_13 ) ;
V_54 = V_186 ;
goto V_185;
}
F_158 ( V_3 , V_68 , V_13 , V_8 ) ;
if ( F_162 ( V_13 ) == V_184 )
F_10 ( V_3 , V_13 , V_8 ) ;
goto V_185;
}
V_189:
F_159 ( V_13 , V_3 -> V_4 -> V_29 ) ;
if ( F_162 ( V_13 ) == V_184 ) {
F_47 ( & V_3 -> V_46 ) ;
return F_141 ( V_3 -> V_4 , V_13 ) ;
}
V_185:
F_47 ( & V_3 -> V_46 ) ;
return V_54 ;
}
static int F_166 ( struct V_116 * V_45 , struct V_13 * V_13 ,
T_8 * error )
{
struct V_2 * V_3 = V_45 -> V_144 ;
if ( F_8 ( V_13 ) )
F_15 ( V_3 , V_13 ) ;
return V_190 ;
}
static void F_167 ( struct V_116 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_144 ;
F_109 ( V_3 ) ;
}
static int F_168 ( struct V_116 * V_45 )
{
int V_54 = 0 ;
struct V_2 * V_3 = V_45 -> V_144 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_41 ( & V_28 ) ;
( void ) F_39 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 ) {
F_41 ( & V_39 -> V_46 ) ;
if ( V_3 == V_39 ) {
F_25 ( L_35
L_36 ) ;
V_54 = - V_47 ;
} else if ( ! F_169 ( V_39 -> V_45 ) ) {
F_25 ( L_37
L_38 ) ;
V_54 = - V_47 ;
}
F_42 ( & V_39 -> V_46 ) ;
}
F_42 ( & V_28 ) ;
return V_54 ;
}
static void F_170 ( struct V_116 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_144 ;
struct V_2 * V_39 = NULL , * V_40 = NULL , * V_191 = NULL ;
struct V_36 * V_33 ;
struct V_192 * V_193 = NULL ;
bool V_194 = false ;
F_41 ( & V_28 ) ;
V_33 = F_35 ( V_3 -> V_4 -> V_29 ) ;
if ( V_33 )
V_193 = F_171 ( V_33 -> V_45 -> V_61 ) ;
if ( ! V_193 ) {
( void ) F_39 ( V_3 , NULL , NULL , & V_191 ) ;
if ( V_191 )
V_193 = F_171 ( V_191 -> V_45 -> V_61 ) ;
}
if ( V_193 == F_171 ( V_45 -> V_61 ) )
V_193 = NULL ;
if ( V_193 ) {
if ( F_172 ( V_193 ) )
V_193 = NULL ;
}
F_42 ( & V_28 ) ;
if ( V_193 ) {
F_173 ( V_193 ) ;
if ( V_191 && F_101 ( V_90 , & V_191 -> V_91 ) ) {
V_194 = true ;
F_109 ( V_191 ) ;
}
}
F_41 ( & V_28 ) ;
( void ) F_39 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 ) {
F_46 ( & V_39 -> V_46 ) ;
F_174 ( & V_40 -> V_46 , V_195 ) ;
F_133 ( V_39 , V_40 ) ;
F_47 ( & V_40 -> V_46 ) ;
F_47 ( & V_39 -> V_46 ) ;
}
F_42 ( & V_28 ) ;
if ( V_193 ) {
if ( V_194 )
F_107 ( V_191 ) ;
F_175 ( V_193 ) ;
F_176 ( V_193 ) ;
}
F_48 ( V_3 ) ;
F_46 ( & V_3 -> V_46 ) ;
V_3 -> V_43 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
}
static T_3 F_177 ( struct V_10 * V_29 )
{
T_3 V_196 ;
F_41 ( & V_28 ) ;
V_196 = F_77 ( F_31 ( V_29 ) ) ;
F_42 ( & V_28 ) ;
return V_196 ;
}
static void F_178 ( struct V_116 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_144 ;
F_170 ( V_45 ) ;
V_45 -> V_153 = F_177 ( V_3 -> V_4 -> V_29 ) ;
F_107 ( V_3 ) ;
}
static void F_179 ( struct V_116 * V_45 , T_9 type ,
unsigned V_197 , char * V_198 , unsigned V_199 )
{
unsigned V_200 = 0 ;
struct V_2 * V_38 = V_45 -> V_144 ;
switch ( type ) {
case V_201 :
F_46 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 )
F_180 ( L_39 ) ;
else if ( V_38 -> V_109 )
F_180 ( L_40 ) ;
else if ( V_38 -> V_132 )
F_180 ( L_41 ) ;
else {
if ( V_38 -> V_7 -> type -> V_202 ) {
T_1 V_203 , V_204 ,
V_205 ;
V_38 -> V_7 -> type -> V_202 ( V_38 -> V_7 ,
& V_203 ,
& V_204 ,
& V_205 ) ;
F_180 ( L_42 ,
( unsigned long long ) V_204 ,
( unsigned long long ) V_203 ,
( unsigned long long ) V_205 ) ;
}
else
F_180 ( L_43 ) ;
}
F_47 ( & V_38 -> V_46 ) ;
break;
case V_206 :
F_180 ( L_44 , V_38 -> V_4 -> V_207 , V_38 -> V_5 -> V_207 ) ;
V_38 -> V_7 -> type -> V_208 ( V_38 -> V_7 , type , V_198 + V_200 ,
V_199 - V_200 ) ;
break;
}
}
static int F_181 ( struct V_116 * V_45 ,
T_10 V_209 , void * V_210 )
{
struct V_2 * V_38 = V_45 -> V_144 ;
int V_54 ;
V_54 = V_209 ( V_45 , V_38 -> V_4 , 0 , V_45 -> V_211 , V_210 ) ;
if ( ! V_54 )
V_54 = V_209 ( V_45 , V_38 -> V_5 , 0 , F_81 ( V_38 -> V_5 -> V_29 ) , V_210 ) ;
return V_54 ;
}
static int F_182 ( struct V_24 * V_55 , T_1 V_110 ,
struct V_13 * V_13 )
{
int V_54 = V_156 ;
struct V_2 * V_38 ;
struct V_65 * V_68 ;
struct V_74 * V_75 ;
struct V_74 * V_212 = NULL ;
struct V_74 * V_213 = NULL ;
T_2 V_8 ;
F_32 (snap, snapshots, list) {
if ( F_40 ( V_38 -> V_45 ) )
continue;
F_46 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 || ! V_38 -> V_43 )
goto V_214;
if ( V_110 >= F_183 ( V_38 -> V_45 -> V_61 ) )
goto V_214;
V_8 = F_161 ( V_38 -> V_7 , V_110 ) ;
V_68 = F_59 ( & V_38 -> V_84 , V_8 ) ;
if ( V_68 )
goto V_214;
V_75 = F_155 ( V_38 , V_8 ) ;
if ( ! V_75 ) {
F_47 ( & V_38 -> V_46 ) ;
V_75 = F_64 ( V_38 ) ;
F_46 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 ) {
F_67 ( V_75 ) ;
goto V_214;
}
V_68 = F_59 ( & V_38 -> V_84 , V_8 ) ;
if ( V_68 ) {
F_67 ( V_75 ) ;
goto V_214;
}
V_75 = F_157 ( V_38 , V_75 , V_8 ) ;
if ( ! V_75 ) {
F_143 ( V_38 , - V_26 ) ;
goto V_214;
}
}
V_54 = V_186 ;
if ( V_13 ) {
F_163 ( & V_75 -> V_161 , V_13 ) ;
V_13 = NULL ;
if ( ! V_75 -> V_176 ) {
V_75 -> V_176 = 1 ;
V_213 = V_75 ;
}
}
if ( ! V_75 -> V_176 ) {
V_75 -> V_176 = 1 ;
V_212 = V_75 ;
}
V_214:
F_47 ( & V_38 -> V_46 ) ;
if ( V_212 ) {
F_151 ( V_212 ) ;
V_212 = NULL ;
}
}
if ( V_213 )
F_151 ( V_213 ) ;
return V_54 ;
}
static int F_141 ( struct V_1 * V_4 , struct V_13 * V_13 )
{
struct V_4 * V_33 ;
int V_54 = V_156 ;
F_41 ( & V_28 ) ;
V_33 = F_31 ( V_4 -> V_29 ) ;
if ( V_33 )
V_54 = F_182 ( & V_33 -> V_55 , V_13 -> V_178 . V_179 , V_13 ) ;
F_42 ( & V_28 ) ;
return V_54 ;
}
static int F_103 ( struct V_2 * V_215 ,
T_1 V_110 , unsigned V_58 )
{
int V_216 = 0 ;
T_1 V_154 ;
struct V_4 * V_33 ;
F_41 ( & V_28 ) ;
V_33 = F_31 ( V_215 -> V_4 -> V_29 ) ;
for ( V_154 = 0 ; V_154 < V_58 ; V_154 += V_215 -> V_45 -> V_153 )
if ( F_182 ( & V_33 -> V_55 , V_110 + V_154 , NULL ) ==
V_186 )
V_216 = 1 ;
F_42 ( & V_28 ) ;
return V_216 ;
}
static int F_184 ( struct V_116 * V_45 , unsigned int V_117 , char * * V_118 )
{
int V_54 ;
struct V_36 * V_33 ;
if ( V_117 != 1 ) {
V_45 -> error = L_45 ;
return - V_47 ;
}
V_33 = F_24 ( sizeof( struct V_36 ) , V_25 ) ;
if ( ! V_33 ) {
V_45 -> error = L_46 ;
V_54 = - V_26 ;
goto V_217;
}
V_54 = F_114 ( V_45 , V_118 [ 0 ] , F_116 ( V_45 -> V_61 ) , & V_33 -> V_37 ) ;
if ( V_54 ) {
V_45 -> error = L_47 ;
goto V_218;
}
V_33 -> V_45 = V_45 ;
V_45 -> V_144 = V_33 ;
V_45 -> V_124 = 1 ;
return 0 ;
V_218:
F_27 ( V_33 ) ;
V_217:
return V_54 ;
}
static void F_185 ( struct V_116 * V_45 )
{
struct V_36 * V_33 = V_45 -> V_144 ;
F_131 ( V_45 , V_33 -> V_37 ) ;
F_27 ( V_33 ) ;
}
static int F_186 ( struct V_116 * V_45 , struct V_13 * V_13 )
{
struct V_36 * V_33 = V_45 -> V_144 ;
unsigned V_219 ;
F_159 ( V_13 , V_33 -> V_37 -> V_29 ) ;
if ( F_102 ( V_13 -> V_181 & V_182 ) )
return V_156 ;
if ( F_162 ( V_13 ) != V_184 )
return V_156 ;
V_219 = V_33 -> V_220 -
( ( unsigned ) V_13 -> V_178 . V_179 & ( V_33 -> V_220 - 1 ) ) ;
if ( F_187 ( V_13 ) > V_219 )
F_188 ( V_13 , V_219 ) ;
return F_141 ( V_33 -> V_37 , V_13 ) ;
}
static long F_189 ( struct V_116 * V_45 , T_11 V_221 ,
long V_222 , void * * V_223 , T_12 * V_224 )
{
F_126 ( L_48 ) ;
return - V_158 ;
}
static void F_190 ( struct V_116 * V_45 )
{
struct V_36 * V_33 = V_45 -> V_144 ;
V_33 -> V_220 = F_177 ( V_33 -> V_37 -> V_29 ) ;
F_46 ( & V_28 ) ;
F_36 ( V_33 ) ;
F_47 ( & V_28 ) ;
}
static void F_191 ( struct V_116 * V_45 )
{
struct V_36 * V_33 = V_45 -> V_144 ;
F_46 ( & V_28 ) ;
F_37 ( V_33 ) ;
F_47 ( & V_28 ) ;
}
static void F_192 ( struct V_116 * V_45 , T_9 type ,
unsigned V_197 , char * V_198 , unsigned V_199 )
{
struct V_36 * V_33 = V_45 -> V_144 ;
switch ( type ) {
case V_201 :
V_198 [ 0 ] = '\0' ;
break;
case V_206 :
snprintf ( V_198 , V_199 , L_49 , V_33 -> V_37 -> V_207 ) ;
break;
}
}
static int F_193 ( struct V_116 * V_45 ,
T_10 V_209 , void * V_210 )
{
struct V_36 * V_33 = V_45 -> V_144 ;
return V_209 ( V_45 , V_33 -> V_37 , 0 , V_45 -> V_211 , V_210 ) ;
}
static int T_13 F_194 ( void )
{
int V_54 ;
V_54 = F_195 () ;
if ( V_54 ) {
F_25 ( L_50 ) ;
return V_54 ;
}
V_54 = F_196 ( & V_225 ) ;
if ( V_54 < 0 ) {
F_25 ( L_51 , V_54 ) ;
goto V_226;
}
V_54 = F_196 ( & V_227 ) ;
if ( V_54 < 0 ) {
F_25 ( L_52 , V_54 ) ;
goto V_228;
}
V_54 = F_196 ( & V_229 ) ;
if ( V_54 < 0 ) {
F_25 ( L_53 , V_54 ) ;
goto V_230;
}
V_54 = F_23 () ;
if ( V_54 ) {
F_25 ( L_54 ) ;
goto V_231;
}
V_71 = F_197 ( V_65 , 0 ) ;
if ( ! V_71 ) {
F_25 ( L_55 ) ;
V_54 = - V_26 ;
goto V_232;
}
V_141 = F_197 ( V_74 , 0 ) ;
if ( ! V_141 ) {
F_25 ( L_56 ) ;
V_54 = - V_26 ;
goto V_233;
}
return 0 ;
V_233:
F_198 ( V_71 ) ;
V_232:
F_29 () ;
V_231:
F_199 ( & V_229 ) ;
V_230:
F_199 ( & V_227 ) ;
V_228:
F_199 ( & V_225 ) ;
V_226:
F_200 () ;
return V_54 ;
}
static void T_14 F_201 ( void )
{
F_199 ( & V_225 ) ;
F_199 ( & V_227 ) ;
F_199 ( & V_229 ) ;
F_29 () ;
F_198 ( V_141 ) ;
F_198 ( V_71 ) ;
F_200 () ;
}
