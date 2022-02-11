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
unsigned V_121 , V_122 = 1 ;
T_6 V_123 = V_124 ;
if ( V_117 != 4 ) {
V_45 -> error = L_18 ;
V_54 = - V_47 ;
goto V_125;
}
if ( F_40 ( V_45 ) ) {
V_122 = 2 ;
V_123 = V_126 ;
}
V_3 = F_24 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 ) {
V_45 -> error = L_19 ;
V_54 = - V_26 ;
goto V_125;
}
V_119 = V_118 [ 0 ] ;
V_118 ++ ;
V_117 -- ;
V_54 = F_114 ( V_45 , V_119 , V_123 , & V_3 -> V_4 ) ;
if ( V_54 ) {
V_45 -> error = L_20 ;
goto V_127;
}
V_120 = V_118 [ 0 ] ;
V_118 ++ ;
V_117 -- ;
V_54 = F_114 ( V_45 , V_120 , F_115 ( V_45 -> V_61 ) , & V_3 -> V_5 ) ;
if ( V_54 ) {
V_45 -> error = L_21 ;
goto V_128;
}
V_54 = F_116 ( V_45 , V_117 , V_118 , V_3 , & V_121 , & V_3 -> V_7 ) ;
if ( V_54 ) {
V_45 -> error = L_22 ;
V_54 = - V_47 ;
goto V_129;
}
V_118 += V_121 ;
V_117 -= V_121 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_108 = 1 ;
V_3 -> V_43 = 0 ;
F_117 ( & V_3 -> V_77 , 0 ) ;
V_3 -> V_130 = 0 ;
V_3 -> V_131 = 0 ;
F_26 ( & V_3 -> V_132 ) ;
F_28 ( & V_3 -> V_46 ) ;
F_26 ( & V_3 -> V_52 ) ;
F_118 ( & V_3 -> V_133 ) ;
V_3 -> V_91 = 0 ;
V_3 -> V_109 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = 0 ;
F_119 ( & V_3 -> V_94 ) ;
if ( F_80 ( V_3 ) ) {
V_45 -> error = L_23 ;
V_54 = - V_26 ;
goto V_134;
}
V_3 -> V_111 = F_120 ( & V_135 ) ;
if ( F_121 ( V_3 -> V_111 ) ) {
V_54 = F_122 ( V_3 -> V_111 ) ;
V_45 -> error = L_24 ;
goto V_136;
}
V_3 -> V_76 = F_123 ( V_137 , V_138 ) ;
if ( ! V_3 -> V_76 ) {
V_45 -> error = L_25 ;
V_54 = - V_26 ;
goto V_139;
}
for ( V_21 = 0 ; V_21 < V_140 ; V_21 ++ )
F_124 ( & V_3 -> V_18 [ V_21 ] ) ;
F_118 ( & V_3 -> V_17 ) ;
V_45 -> V_141 = V_3 ;
V_45 -> V_122 = V_122 ;
V_45 -> V_142 = sizeof( struct V_14 ) ;
V_54 = F_45 ( V_3 ) ;
if ( V_54 == - V_26 ) {
V_45 -> error = L_26 ;
goto V_143;
} else if ( V_54 < 0 ) {
goto V_143;
}
if ( V_54 > 0 ) {
V_3 -> V_7 -> V_51 = 0 ;
return 0 ;
}
V_54 = V_3 -> V_7 -> type -> V_144 ( V_3 -> V_7 , F_76 ,
( void * ) V_3 ) ;
if ( V_54 < 0 ) {
V_45 -> error = L_27 ;
goto V_145;
} else if ( V_54 > 0 ) {
V_3 -> V_108 = 0 ;
F_125 ( L_28 ) ;
}
if ( ! V_3 -> V_7 -> V_51 ) {
V_45 -> error = L_29 ;
goto V_145;
}
V_54 = F_126 ( V_45 , V_3 -> V_7 -> V_51 ) ;
if ( V_54 )
goto V_145;
return 0 ;
V_145:
F_49 ( V_3 ) ;
V_143:
F_127 ( V_3 -> V_76 ) ;
V_139:
F_128 ( V_3 -> V_111 ) ;
V_136:
F_53 ( & V_3 -> V_89 , V_138 ) ;
F_53 ( & V_3 -> V_84 , V_71 ) ;
V_134:
F_129 ( V_3 -> V_7 ) ;
V_129:
F_130 ( V_45 , V_3 -> V_5 ) ;
V_128:
F_130 ( V_45 , V_3 -> V_4 ) ;
V_127:
F_27 ( V_3 ) ;
V_125:
return V_54 ;
}
static void F_131 ( struct V_2 * V_3 )
{
F_128 ( V_3 -> V_111 ) ;
V_3 -> V_111 = NULL ;
F_53 ( & V_3 -> V_89 , V_138 ) ;
F_53 ( & V_3 -> V_84 , V_71 ) ;
}
static void F_132 ( struct V_2 * V_39 ,
struct V_2 * V_40 )
{
union {
struct V_56 V_146 ;
struct V_6 * V_147 ;
} V_148 ;
V_148 . V_146 = V_40 -> V_84 ;
V_40 -> V_84 = V_39 -> V_84 ;
V_39 -> V_84 = V_148 . V_146 ;
V_148 . V_147 = V_40 -> V_7 ;
V_40 -> V_7 = V_39 -> V_7 ;
V_39 -> V_7 = V_148 . V_147 ;
V_40 -> V_7 -> V_38 = V_40 ;
V_39 -> V_7 -> V_38 = V_39 ;
V_40 -> V_45 -> V_149 = V_40 -> V_7 -> V_51 ;
V_40 -> V_108 = V_39 -> V_108 ;
V_39 -> V_108 = 0 ;
}
static void F_133 ( struct V_116 * V_45 )
{
#ifdef F_134
int V_21 ;
#endif
struct V_2 * V_3 = V_45 -> V_141 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_41 ( & V_28 ) ;
( void ) F_39 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 && ( V_3 == V_39 ) ) {
F_46 ( & V_40 -> V_46 ) ;
V_40 -> V_108 = 0 ;
F_47 ( & V_40 -> V_46 ) ;
F_25 ( L_30 ) ;
}
F_42 ( & V_28 ) ;
if ( F_40 ( V_45 ) )
F_109 ( V_3 ) ;
F_49 ( V_3 ) ;
while ( F_135 ( & V_3 -> V_77 ) )
F_22 ( 1 ) ;
F_136 () ;
#ifdef F_134
for ( V_21 = 0 ; V_21 < V_140 ; V_21 ++ )
F_100 ( ! F_137 ( & V_3 -> V_18 [ V_21 ] ) ) ;
#endif
F_131 ( V_3 ) ;
F_127 ( V_3 -> V_76 ) ;
F_129 ( V_3 -> V_7 ) ;
F_130 ( V_45 , V_3 -> V_5 ) ;
F_130 ( V_45 , V_3 -> V_4 ) ;
F_27 ( V_3 ) ;
}
static void F_93 ( struct V_13 * V_13 )
{
struct V_13 * V_150 ;
while ( V_13 ) {
V_150 = V_13 -> V_151 ;
V_13 -> V_151 = NULL ;
F_138 ( V_13 ) ;
V_13 = V_150 ;
}
}
static void F_139 ( struct V_2 * V_3 , struct V_13 * V_13 )
{
struct V_13 * V_150 ;
int V_54 ;
while ( V_13 ) {
V_150 = V_13 -> V_151 ;
V_13 -> V_151 = NULL ;
V_54 = F_140 ( V_3 -> V_4 , V_13 ) ;
if ( V_54 == V_152 )
F_138 ( V_13 ) ;
V_13 = V_150 ;
}
}
static void F_106 ( struct V_13 * V_13 )
{
struct V_13 * V_150 ;
while ( V_13 ) {
V_150 = V_13 -> V_151 ;
V_13 -> V_151 = NULL ;
F_141 ( V_13 ) ;
V_13 = V_150 ;
}
}
static void F_142 ( struct V_2 * V_3 , int V_153 )
{
if ( ! V_3 -> V_108 )
return;
if ( V_153 == - V_154 )
F_25 ( L_31 ) ;
else if ( V_153 == - V_26 )
F_25 ( L_32 ) ;
if ( V_3 -> V_7 -> type -> V_155 )
V_3 -> V_7 -> type -> V_155 ( V_3 -> V_7 ) ;
V_3 -> V_108 = 0 ;
F_143 ( V_3 -> V_45 -> V_61 ) ;
}
static void F_144 ( struct V_74 * V_75 , int V_156 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_75 -> V_38 ;
struct V_13 * V_157 = NULL ;
struct V_13 * V_158 = NULL ;
struct V_13 * V_159 = NULL ;
int error = 0 ;
if ( ! V_156 ) {
F_46 ( & V_3 -> V_46 ) ;
F_142 ( V_3 , - V_154 ) ;
error = 1 ;
goto V_44;
}
V_68 = F_61 ( V_72 ) ;
if ( ! V_68 ) {
F_46 ( & V_3 -> V_46 ) ;
F_142 ( V_3 , - V_26 ) ;
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
V_158 = F_89 ( & V_75 -> V_158 ) ;
V_157 = F_89 ( & V_75 -> V_157 ) ;
V_159 = V_75 -> V_159 ;
if ( V_159 ) {
V_159 -> V_160 = V_75 -> V_161 ;
V_159 -> V_162 = V_75 -> V_163 ;
}
F_97 () ;
F_47 ( & V_3 -> V_46 ) ;
if ( error ) {
if ( V_159 )
F_141 ( V_159 ) ;
F_106 ( V_158 ) ;
} else {
if ( V_159 )
F_145 ( V_159 , 0 ) ;
F_93 ( V_158 ) ;
}
F_139 ( V_3 , V_157 ) ;
F_67 ( V_75 ) ;
}
static void F_146 ( void * V_81 , int V_156 )
{
struct V_74 * V_75 = V_81 ;
F_144 ( V_75 , V_156 ) ;
}
static void F_147 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
if ( F_102 ( V_75 -> V_164 ) )
F_144 ( V_75 , 0 ) ;
else
V_3 -> V_7 -> type -> V_165 ( V_3 -> V_7 , & V_75 -> V_68 ,
F_146 , V_75 ) ;
}
static void F_148 ( int V_113 , unsigned long V_114 , void * V_81 )
{
struct V_74 * V_75 = V_81 ;
struct V_2 * V_3 = V_75 -> V_38 ;
V_75 -> V_164 = V_113 || V_114 ;
if ( V_75 -> V_166 == V_3 -> V_131 ) {
V_3 -> V_131 ++ ;
F_147 ( V_75 ) ;
while ( ! F_50 ( & V_3 -> V_132 ) ) {
V_75 = F_149 ( V_3 -> V_132 . V_67 ,
struct V_74 , V_167 ) ;
if ( V_75 -> V_166 != V_3 -> V_131 )
break;
V_3 -> V_131 ++ ;
F_38 ( & V_75 -> V_167 ) ;
F_147 ( V_75 ) ;
}
} else {
struct V_24 * V_168 ;
struct V_74 * V_169 ;
F_150 (lh, &s->out_of_order_list) {
V_169 = F_149 ( V_168 , struct V_74 , V_167 ) ;
if ( V_169 -> V_166 < V_75 -> V_166 )
break;
}
F_75 ( & V_75 -> V_167 , V_168 ) ;
}
}
static void F_151 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
struct V_101 V_102 , V_103 ;
struct V_10 * V_29 = V_3 -> V_4 -> V_29 ;
T_1 V_170 ;
V_170 = F_81 ( V_29 ) ;
V_102 . V_29 = V_29 ;
V_102 . V_110 = F_3 ( V_3 -> V_7 , V_75 -> V_68 . V_69 ) ;
V_102 . V_42 = F_82 ( ( T_1 ) V_3 -> V_7 -> V_51 , V_170 - V_102 . V_110 ) ;
V_103 . V_29 = V_3 -> V_5 -> V_29 ;
V_103 . V_110 = F_3 ( V_3 -> V_7 , V_75 -> V_68 . V_80 ) ;
V_103 . V_42 = V_102 . V_42 ;
F_105 ( V_3 -> V_111 , & V_102 , 1 , & V_103 , 0 , F_148 , V_75 ) ;
}
static void V_161 ( struct V_13 * V_13 , int error )
{
void * V_171 = V_13 -> V_162 ;
F_152 ( V_171 , 0 , error ? 1 : 0 ) ;
}
static void F_153 ( struct V_74 * V_75 ,
struct V_13 * V_13 )
{
struct V_2 * V_3 = V_75 -> V_38 ;
void * V_171 ;
V_75 -> V_159 = V_13 ;
V_75 -> V_161 = V_13 -> V_160 ;
V_75 -> V_163 = V_13 -> V_162 ;
V_171 = F_154 ( V_3 -> V_111 ,
F_148 , V_75 ) ;
V_13 -> V_160 = V_161 ;
V_13 -> V_162 = V_171 ;
F_138 ( V_13 ) ;
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
struct V_74 * V_169 ;
V_169 = F_155 ( V_3 , V_8 ) ;
if ( V_169 ) {
F_67 ( V_75 ) ;
return V_169 ;
}
V_75 -> V_68 . V_69 = V_8 ;
F_119 ( & V_75 -> V_157 ) ;
F_119 ( & V_75 -> V_158 ) ;
V_75 -> V_172 = 0 ;
V_75 -> V_159 = NULL ;
if ( V_3 -> V_7 -> type -> V_173 ( V_3 -> V_7 , & V_75 -> V_68 ) ) {
F_67 ( V_75 ) ;
return NULL ;
}
V_75 -> V_166 = V_3 -> V_130 ++ ;
F_71 ( & V_3 -> V_89 , & V_75 -> V_68 ) ;
return V_75 ;
}
static void F_158 ( struct V_2 * V_3 , struct V_65 * V_68 ,
struct V_13 * V_13 , T_2 V_8 )
{
V_13 -> V_174 = V_3 -> V_5 -> V_29 ;
V_13 -> V_175 . V_176 =
F_3 ( V_3 -> V_7 , F_73 ( V_68 -> V_80 ) +
( V_8 - V_68 -> V_69 ) ) +
( V_13 -> V_175 . V_176 & V_3 -> V_7 -> V_177 ) ;
}
static int F_159 ( struct V_116 * V_45 , struct V_13 * V_13 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_45 -> V_141 ;
int V_54 = V_152 ;
T_2 V_8 ;
struct V_74 * V_75 = NULL ;
F_5 ( V_13 ) ;
if ( V_13 -> V_178 & V_179 ) {
V_13 -> V_174 = V_3 -> V_5 -> V_29 ;
return V_152 ;
}
V_8 = F_160 ( V_3 -> V_7 , V_13 -> V_175 . V_176 ) ;
if ( ! V_3 -> V_108 )
return - V_154 ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 ) {
V_54 = - V_154 ;
goto V_180;
}
V_68 = F_59 ( & V_3 -> V_84 , V_8 ) ;
if ( V_68 ) {
F_158 ( V_3 , V_68 , V_13 , V_8 ) ;
goto V_180;
}
if ( F_161 ( V_13 ) == V_181 ) {
V_75 = F_155 ( V_3 , V_8 ) ;
if ( ! V_75 ) {
F_47 ( & V_3 -> V_46 ) ;
V_75 = F_64 ( V_3 ) ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 ) {
F_67 ( V_75 ) ;
V_54 = - V_154 ;
goto V_180;
}
V_68 = F_59 ( & V_3 -> V_84 , V_8 ) ;
if ( V_68 ) {
F_67 ( V_75 ) ;
F_158 ( V_3 , V_68 , V_13 , V_8 ) ;
goto V_180;
}
V_75 = F_157 ( V_3 , V_75 , V_8 ) ;
if ( ! V_75 ) {
F_142 ( V_3 , - V_26 ) ;
V_54 = - V_154 ;
goto V_180;
}
}
F_158 ( V_3 , & V_75 -> V_68 , V_13 , V_8 ) ;
V_54 = V_182 ;
if ( ! V_75 -> V_172 &&
V_13 -> V_175 . V_183 ==
( V_3 -> V_7 -> V_51 << V_184 ) ) {
V_75 -> V_172 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
F_153 ( V_75 , V_13 ) ;
goto V_44;
}
F_162 ( & V_75 -> V_158 , V_13 ) ;
if ( ! V_75 -> V_172 ) {
V_75 -> V_172 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
F_151 ( V_75 ) ;
goto V_44;
}
} else {
V_13 -> V_174 = V_3 -> V_4 -> V_29 ;
F_10 ( V_3 , V_13 , V_8 ) ;
}
V_180:
F_47 ( & V_3 -> V_46 ) ;
V_44:
return V_54 ;
}
static int F_163 ( struct V_116 * V_45 , struct V_13 * V_13 )
{
struct V_65 * V_68 ;
struct V_2 * V_3 = V_45 -> V_141 ;
int V_54 = V_152 ;
T_2 V_8 ;
F_5 ( V_13 ) ;
if ( V_13 -> V_178 & V_179 ) {
if ( ! F_164 ( V_13 ) )
V_13 -> V_174 = V_3 -> V_4 -> V_29 ;
else
V_13 -> V_174 = V_3 -> V_5 -> V_29 ;
return V_152 ;
}
V_8 = F_160 ( V_3 -> V_7 , V_13 -> V_175 . V_176 ) ;
F_46 ( & V_3 -> V_46 ) ;
if ( ! V_3 -> V_108 )
goto V_185;
V_68 = F_59 ( & V_3 -> V_84 , V_8 ) ;
if ( V_68 ) {
if ( F_161 ( V_13 ) == V_181 &&
V_8 >= V_3 -> V_92 &&
V_8 < ( V_3 -> V_92 +
V_3 -> V_93 ) ) {
V_13 -> V_174 = V_3 -> V_4 -> V_29 ;
F_162 ( & V_3 -> V_94 , V_13 ) ;
V_54 = V_182 ;
goto V_180;
}
F_158 ( V_3 , V_68 , V_13 , V_8 ) ;
if ( F_161 ( V_13 ) == V_181 )
F_10 ( V_3 , V_13 , V_8 ) ;
goto V_180;
}
V_185:
V_13 -> V_174 = V_3 -> V_4 -> V_29 ;
if ( F_161 ( V_13 ) == V_181 ) {
F_47 ( & V_3 -> V_46 ) ;
return F_140 ( V_3 -> V_4 , V_13 ) ;
}
V_180:
F_47 ( & V_3 -> V_46 ) ;
return V_54 ;
}
static int F_165 ( struct V_116 * V_45 , struct V_13 * V_13 , int error )
{
struct V_2 * V_3 = V_45 -> V_141 ;
if ( F_8 ( V_13 ) )
F_15 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_166 ( struct V_116 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_141 ;
F_109 ( V_3 ) ;
}
static int F_167 ( struct V_116 * V_45 )
{
int V_54 = 0 ;
struct V_2 * V_3 = V_45 -> V_141 ;
struct V_2 * V_39 = NULL , * V_40 = NULL ;
F_41 ( & V_28 ) ;
( void ) F_39 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 ) {
F_41 ( & V_39 -> V_46 ) ;
if ( V_3 == V_39 ) {
F_25 ( L_33
L_34 ) ;
V_54 = - V_47 ;
} else if ( ! F_168 ( V_39 -> V_45 ) ) {
F_25 ( L_35
L_36 ) ;
V_54 = - V_47 ;
}
F_42 ( & V_39 -> V_46 ) ;
}
F_42 ( & V_28 ) ;
return V_54 ;
}
static void F_169 ( struct V_116 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_141 ;
struct V_2 * V_39 = NULL , * V_40 = NULL , * V_186 = NULL ;
struct V_36 * V_33 ;
struct V_187 * V_188 = NULL ;
bool V_189 = false ;
F_41 ( & V_28 ) ;
V_33 = F_35 ( V_3 -> V_4 -> V_29 ) ;
if ( V_33 )
V_188 = F_170 ( V_33 -> V_45 -> V_61 ) ;
if ( ! V_188 ) {
( void ) F_39 ( V_3 , NULL , NULL , & V_186 ) ;
if ( V_186 )
V_188 = F_170 ( V_186 -> V_45 -> V_61 ) ;
}
if ( V_188 == F_170 ( V_45 -> V_61 ) )
V_188 = NULL ;
if ( V_188 ) {
if ( F_171 ( V_188 ) )
V_188 = NULL ;
}
F_42 ( & V_28 ) ;
if ( V_188 ) {
F_172 ( V_188 ) ;
if ( V_186 && F_101 ( V_90 , & V_186 -> V_91 ) ) {
V_189 = true ;
F_109 ( V_186 ) ;
}
}
F_41 ( & V_28 ) ;
( void ) F_39 ( V_3 , & V_39 , & V_40 , NULL ) ;
if ( V_39 && V_40 ) {
F_46 ( & V_39 -> V_46 ) ;
F_173 ( & V_40 -> V_46 , V_190 ) ;
F_132 ( V_39 , V_40 ) ;
F_47 ( & V_40 -> V_46 ) ;
F_47 ( & V_39 -> V_46 ) ;
}
F_42 ( & V_28 ) ;
if ( V_188 ) {
if ( V_189 )
F_107 ( V_186 ) ;
F_174 ( V_188 ) ;
F_175 ( V_188 ) ;
}
F_48 ( V_3 ) ;
F_46 ( & V_3 -> V_46 ) ;
V_3 -> V_43 = 1 ;
F_47 ( & V_3 -> V_46 ) ;
}
static T_3 F_176 ( struct V_10 * V_29 )
{
T_3 V_191 ;
F_41 ( & V_28 ) ;
V_191 = F_77 ( F_31 ( V_29 ) ) ;
F_42 ( & V_28 ) ;
return V_191 ;
}
static void F_177 ( struct V_116 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_141 ;
F_169 ( V_45 ) ;
V_45 -> V_149 = F_176 ( V_3 -> V_4 -> V_29 ) ;
F_107 ( V_3 ) ;
}
static void F_178 ( struct V_116 * V_45 , T_7 type ,
unsigned V_192 , char * V_193 , unsigned V_194 )
{
unsigned V_195 = 0 ;
struct V_2 * V_38 = V_45 -> V_141 ;
switch ( type ) {
case V_196 :
F_46 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 )
F_179 ( L_37 ) ;
else if ( V_38 -> V_109 )
F_179 ( L_38 ) ;
else {
if ( V_38 -> V_7 -> type -> V_197 ) {
T_1 V_198 , V_199 ,
V_200 ;
V_38 -> V_7 -> type -> V_197 ( V_38 -> V_7 ,
& V_198 ,
& V_199 ,
& V_200 ) ;
F_179 ( L_39 ,
( unsigned long long ) V_199 ,
( unsigned long long ) V_198 ,
( unsigned long long ) V_200 ) ;
}
else
F_179 ( L_40 ) ;
}
F_47 ( & V_38 -> V_46 ) ;
break;
case V_201 :
F_179 ( L_41 , V_38 -> V_4 -> V_202 , V_38 -> V_5 -> V_202 ) ;
V_38 -> V_7 -> type -> V_203 ( V_38 -> V_7 , type , V_193 + V_195 ,
V_194 - V_195 ) ;
break;
}
}
static int F_180 ( struct V_116 * V_45 ,
T_8 V_204 , void * V_205 )
{
struct V_2 * V_38 = V_45 -> V_141 ;
int V_54 ;
V_54 = V_204 ( V_45 , V_38 -> V_4 , 0 , V_45 -> V_206 , V_205 ) ;
if ( ! V_54 )
V_54 = V_204 ( V_45 , V_38 -> V_5 , 0 , F_81 ( V_38 -> V_5 -> V_29 ) , V_205 ) ;
return V_54 ;
}
static int F_181 ( struct V_24 * V_55 , T_1 V_110 ,
struct V_13 * V_13 )
{
int V_54 = V_152 ;
struct V_2 * V_38 ;
struct V_65 * V_68 ;
struct V_74 * V_75 ;
struct V_74 * V_207 = NULL ;
struct V_74 * V_208 = NULL ;
T_2 V_8 ;
F_32 (snap, snapshots, list) {
if ( F_40 ( V_38 -> V_45 ) )
continue;
F_46 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 || ! V_38 -> V_43 )
goto V_209;
if ( V_110 >= F_182 ( V_38 -> V_45 -> V_61 ) )
goto V_209;
V_8 = F_160 ( V_38 -> V_7 , V_110 ) ;
V_68 = F_59 ( & V_38 -> V_84 , V_8 ) ;
if ( V_68 )
goto V_209;
V_75 = F_155 ( V_38 , V_8 ) ;
if ( ! V_75 ) {
F_47 ( & V_38 -> V_46 ) ;
V_75 = F_64 ( V_38 ) ;
F_46 ( & V_38 -> V_46 ) ;
if ( ! V_38 -> V_108 ) {
F_67 ( V_75 ) ;
goto V_209;
}
V_68 = F_59 ( & V_38 -> V_84 , V_8 ) ;
if ( V_68 ) {
F_67 ( V_75 ) ;
goto V_209;
}
V_75 = F_157 ( V_38 , V_75 , V_8 ) ;
if ( ! V_75 ) {
F_142 ( V_38 , - V_26 ) ;
goto V_209;
}
}
V_54 = V_182 ;
if ( V_13 ) {
F_162 ( & V_75 -> V_157 , V_13 ) ;
V_13 = NULL ;
if ( ! V_75 -> V_172 ) {
V_75 -> V_172 = 1 ;
V_208 = V_75 ;
}
}
if ( ! V_75 -> V_172 ) {
V_75 -> V_172 = 1 ;
V_207 = V_75 ;
}
V_209:
F_47 ( & V_38 -> V_46 ) ;
if ( V_207 ) {
F_151 ( V_207 ) ;
V_207 = NULL ;
}
}
if ( V_208 )
F_151 ( V_208 ) ;
return V_54 ;
}
static int F_140 ( struct V_1 * V_4 , struct V_13 * V_13 )
{
struct V_4 * V_33 ;
int V_54 = V_152 ;
F_41 ( & V_28 ) ;
V_33 = F_31 ( V_4 -> V_29 ) ;
if ( V_33 )
V_54 = F_181 ( & V_33 -> V_55 , V_13 -> V_175 . V_176 , V_13 ) ;
F_42 ( & V_28 ) ;
return V_54 ;
}
static int F_103 ( struct V_2 * V_210 ,
T_1 V_110 , unsigned V_58 )
{
int V_211 = 0 ;
T_1 V_150 ;
struct V_4 * V_33 ;
F_41 ( & V_28 ) ;
V_33 = F_31 ( V_210 -> V_4 -> V_29 ) ;
for ( V_150 = 0 ; V_150 < V_58 ; V_150 += V_210 -> V_45 -> V_149 )
if ( F_181 ( & V_33 -> V_55 , V_110 + V_150 , NULL ) ==
V_182 )
V_211 = 1 ;
F_42 ( & V_28 ) ;
return V_211 ;
}
static int F_183 ( struct V_116 * V_45 , unsigned int V_117 , char * * V_118 )
{
int V_54 ;
struct V_36 * V_33 ;
if ( V_117 != 1 ) {
V_45 -> error = L_42 ;
return - V_47 ;
}
V_33 = F_24 ( sizeof( struct V_36 ) , V_25 ) ;
if ( ! V_33 ) {
V_45 -> error = L_43 ;
V_54 = - V_26 ;
goto V_212;
}
V_54 = F_114 ( V_45 , V_118 [ 0 ] , F_115 ( V_45 -> V_61 ) , & V_33 -> V_37 ) ;
if ( V_54 ) {
V_45 -> error = L_44 ;
goto V_213;
}
V_33 -> V_45 = V_45 ;
V_45 -> V_141 = V_33 ;
V_45 -> V_122 = 1 ;
return 0 ;
V_213:
F_27 ( V_33 ) ;
V_212:
return V_54 ;
}
static void F_184 ( struct V_116 * V_45 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
F_130 ( V_45 , V_33 -> V_37 ) ;
F_27 ( V_33 ) ;
}
static int F_185 ( struct V_116 * V_45 , struct V_13 * V_13 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
unsigned V_214 ;
V_13 -> V_174 = V_33 -> V_37 -> V_29 ;
if ( F_102 ( V_13 -> V_178 & V_179 ) )
return V_152 ;
if ( F_161 ( V_13 ) != V_181 )
return V_152 ;
V_214 = V_33 -> V_215 -
( ( unsigned ) V_13 -> V_175 . V_176 & ( V_33 -> V_215 - 1 ) ) ;
if ( F_186 ( V_13 ) > V_214 )
F_187 ( V_13 , V_214 ) ;
return F_140 ( V_33 -> V_37 , V_13 ) ;
}
static void F_188 ( struct V_116 * V_45 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
V_33 -> V_215 = F_176 ( V_33 -> V_37 -> V_29 ) ;
F_46 ( & V_28 ) ;
F_36 ( V_33 ) ;
F_47 ( & V_28 ) ;
}
static void F_189 ( struct V_116 * V_45 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
F_46 ( & V_28 ) ;
F_37 ( V_33 ) ;
F_47 ( & V_28 ) ;
}
static void F_190 ( struct V_116 * V_45 , T_7 type ,
unsigned V_192 , char * V_193 , unsigned V_194 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
switch ( type ) {
case V_196 :
V_193 [ 0 ] = '\0' ;
break;
case V_201 :
snprintf ( V_193 , V_194 , L_45 , V_33 -> V_37 -> V_202 ) ;
break;
}
}
static int F_191 ( struct V_116 * V_45 , struct V_216 * V_217 ,
struct V_218 * V_219 , int V_220 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
struct V_221 * V_222 = F_192 ( V_33 -> V_37 -> V_29 ) ;
if ( ! V_222 -> V_223 )
return V_220 ;
V_217 -> V_174 = V_33 -> V_37 -> V_29 ;
return F_82 ( V_220 , V_222 -> V_223 ( V_222 , V_217 , V_219 ) ) ;
}
static int F_193 ( struct V_116 * V_45 ,
T_8 V_204 , void * V_205 )
{
struct V_36 * V_33 = V_45 -> V_141 ;
return V_204 ( V_45 , V_33 -> V_37 , 0 , V_45 -> V_206 , V_205 ) ;
}
static int T_9 F_194 ( void )
{
int V_54 ;
V_54 = F_195 () ;
if ( V_54 ) {
F_25 ( L_46 ) ;
return V_54 ;
}
V_54 = F_196 ( & V_224 ) ;
if ( V_54 < 0 ) {
F_25 ( L_47 , V_54 ) ;
goto V_225;
}
V_54 = F_196 ( & V_226 ) ;
if ( V_54 < 0 ) {
F_25 ( L_48 , V_54 ) ;
goto V_227;
}
V_54 = F_196 ( & V_228 ) ;
if ( V_54 < 0 ) {
F_25 ( L_49 , V_54 ) ;
goto V_229;
}
V_54 = F_23 () ;
if ( V_54 ) {
F_25 ( L_50 ) ;
goto V_230;
}
V_71 = F_197 ( V_65 , 0 ) ;
if ( ! V_71 ) {
F_25 ( L_51 ) ;
V_54 = - V_26 ;
goto V_231;
}
V_138 = F_197 ( V_74 , 0 ) ;
if ( ! V_138 ) {
F_25 ( L_52 ) ;
V_54 = - V_26 ;
goto V_232;
}
return 0 ;
V_232:
F_198 ( V_71 ) ;
V_231:
F_29 () ;
V_230:
F_199 ( & V_228 ) ;
V_229:
F_199 ( & V_226 ) ;
V_227:
F_199 ( & V_224 ) ;
V_225:
F_200 () ;
return V_54 ;
}
static void T_10 F_201 ( void )
{
F_199 ( & V_224 ) ;
F_199 ( & V_226 ) ;
F_199 ( & V_228 ) ;
F_29 () ;
F_198 ( V_138 ) ;
F_198 ( V_71 ) ;
F_200 () ;
}
