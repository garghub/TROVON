static inline bool F_1 ( void )
{
return V_1 || ! V_2 ;
}
static inline void F_2 ( struct V_3 * V_4 )
{
#ifdef F_3
if ( V_4 ) {
F_4 ( L_1 ) ;
F_5 ( & V_4 -> V_5 , 0 ) ;
}
#endif
}
static bool F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
unsigned long V_10 ;
bool V_11 ;
if ( F_7 ( ! V_12 [ 0 ] ) )
return true ;
if ( V_13 && V_7 && V_7 -> V_14 == V_13 )
return true ;
if ( ! V_7 )
return false ;
if ( V_13 || ! V_12 [ 0 ] )
return false ;
V_9 = V_7 -> V_14 ;
if ( ! V_9 )
return false ;
F_8 ( & V_15 , V_10 ) ;
V_11 = false ;
if ( V_9 -> V_16 &&
strncmp ( V_12 , V_9 -> V_16 , V_17 - 1 ) == 0 ) {
V_13 = V_9 ;
V_11 = true ;
}
F_9 ( & V_15 , V_10 ) ;
return V_11 ;
}
static int F_10 ( struct V_3 * V_4 )
{
return ( V_4 -> V_18 >> V_19 ) & V_20 ;
}
static struct V_21 * F_11 ( struct V_3 * V_4 ,
unsigned long * V_10 )
__acquires( &dma_entry_hash[idx].lock
static void F_12 ( struct V_21 * V_22 ,
unsigned long * V_10 )
__releases( &bucket->lock
static bool F_13 ( struct V_3 * V_23 , struct V_3 * V_24 )
{
return ( ( V_23 -> V_18 == V_24 -> V_18 ) &&
( V_23 -> V_7 == V_24 -> V_7 ) ) ? true : false ;
}
static bool F_14 ( struct V_3 * V_23 ,
struct V_3 * V_24 )
{
if ( V_23 -> V_7 != V_24 -> V_7 )
return false ;
if ( ( V_24 -> V_18 <= V_23 -> V_18 ) &&
( ( V_24 -> V_18 + V_24 -> V_25 ) >= ( V_23 -> V_18 + V_23 -> V_25 ) ) )
return true ;
return false ;
}
static struct V_3 * F_15 ( struct V_21 * V_22 ,
struct V_3 * V_26 ,
T_1 V_27 )
{
struct V_3 * V_4 , * V_11 = NULL ;
int V_28 = 0 , V_29 , V_30 = - 1 ;
F_16 (entry, &bucket->list, list) {
if ( ! V_27 ( V_26 , V_4 ) )
continue;
V_28 += 1 ;
V_29 = 0 ;
V_4 -> V_25 == V_26 -> V_25 ? ++ V_29 : 0 ;
V_4 -> type == V_26 -> type ? ++ V_29 : 0 ;
V_4 -> V_31 == V_26 -> V_31 ? ++ V_29 : 0 ;
V_4 -> V_32 == V_26 -> V_32 ? ++ V_29 : 0 ;
if ( V_29 == 4 ) {
return V_4 ;
} else if ( V_29 > V_30 ) {
V_30 = V_29 ;
V_11 = V_4 ;
}
}
V_11 = ( V_28 == 1 ) ? V_11 : NULL ;
return V_11 ;
}
static struct V_3 * F_17 ( struct V_21 * V_22 ,
struct V_3 * V_26 )
{
return F_15 ( V_22 , V_26 , F_13 ) ;
}
static struct V_3 * F_18 ( struct V_21 * * V_22 ,
struct V_3 * V_26 ,
unsigned long * V_10 )
{
unsigned int V_33 = F_19 ( V_26 -> V_7 ) ;
struct V_3 * V_4 , V_34 = * V_26 ;
unsigned int V_35 = 0 ;
while ( V_35 <= V_33 ) {
V_4 = F_15 ( * V_22 , V_26 , F_14 ) ;
if ( V_4 )
return V_4 ;
F_12 ( * V_22 , V_10 ) ;
V_35 += ( 1 << V_19 ) ;
V_34 . V_18 -= ( 1 << V_19 ) ;
* V_22 = F_11 ( & V_34 , V_10 ) ;
}
return NULL ;
}
static void F_20 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
F_21 ( & V_4 -> V_36 , & V_22 -> V_36 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
F_23 ( & V_4 -> V_36 ) ;
}
static unsigned long long F_24 ( struct V_3 * V_4 )
{
if ( V_4 -> type == V_37 )
return F_25 ( V_4 -> V_38 ) + V_4 -> V_39 ;
return F_26 ( F_27 ( V_4 -> V_38 ) ) + V_4 -> V_39 ;
}
void F_28 ( struct V_6 * V_7 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
struct V_21 * V_22 = & V_42 [ V_40 ] ;
struct V_3 * V_4 ;
unsigned long V_10 ;
F_29 ( & V_22 -> V_43 , V_10 ) ;
F_16 (entry, &bucket->list, list) {
if ( ! V_7 || V_7 == V_4 -> V_7 ) {
F_30 ( V_4 -> V_7 ,
L_2 ,
V_44 [ V_4 -> type ] , V_40 ,
F_24 ( V_4 ) , V_4 -> V_38 ,
V_4 -> V_18 , V_4 -> V_25 ,
V_45 [ V_4 -> V_31 ] ,
V_46 [ V_4 -> V_47 ] ) ;
}
}
F_31 ( & V_22 -> V_43 , V_10 ) ;
}
}
static T_2 F_32 ( struct V_3 * V_4 )
{
return ( V_4 -> V_38 << V_48 ) +
( V_4 -> V_39 >> V_49 ) ;
}
static int F_33 ( T_2 V_50 )
{
int V_51 = 0 , V_52 ;
for ( V_52 = V_53 - 1 ; V_52 >= 0 ; V_52 -- )
if ( F_34 ( & V_54 , V_50 , V_52 ) )
V_51 |= 1 << V_52 ;
return V_51 ;
}
static int F_35 ( T_2 V_50 , int V_51 )
{
int V_52 ;
if ( V_51 > V_55 || V_51 < 0 )
return V_51 ;
for ( V_52 = V_53 - 1 ; V_52 >= 0 ; V_52 -- )
if ( V_51 & 1 << V_52 )
F_36 ( & V_54 , V_50 , V_52 ) ;
else
F_37 ( & V_54 , V_50 , V_52 ) ;
return V_51 ;
}
static void F_38 ( T_2 V_50 )
{
int V_51 = F_33 ( V_50 ) ;
V_51 = F_35 ( V_50 , ++ V_51 ) ;
F_39 ( V_51 > V_55 ,
L_3 ,
V_55 , & V_50 ) ;
}
static int F_40 ( T_2 V_50 )
{
int V_51 = F_33 ( V_50 ) ;
return F_35 ( V_50 , -- V_51 ) ;
}
static int F_41 ( struct V_3 * V_4 )
{
T_2 V_50 = F_32 ( V_4 ) ;
unsigned long V_10 ;
int V_56 ;
if ( V_4 -> V_31 == V_57 )
return 0 ;
F_29 ( & V_58 , V_10 ) ;
V_56 = F_42 ( & V_54 , V_50 , V_4 ) ;
if ( V_56 == - V_59 )
F_38 ( V_50 ) ;
F_31 ( & V_58 , V_10 ) ;
return V_56 ;
}
static void F_43 ( struct V_3 * V_4 )
{
T_2 V_50 = F_32 ( V_4 ) ;
unsigned long V_10 ;
if ( V_4 -> V_31 == V_57 )
return;
F_29 ( & V_58 , V_10 ) ;
if ( F_40 ( V_50 ) < 0 )
F_44 ( & V_54 , V_50 ) ;
F_31 ( & V_58 , V_10 ) ;
}
void F_45 ( struct V_60 * V_60 )
{
static struct V_3 * V_61 [ V_62 ] ;
struct V_3 * V_4 = NULL ;
void * * V_63 = ( void * * ) & V_61 ;
unsigned int V_64 , V_52 ;
unsigned long V_10 ;
T_2 V_50 ;
if ( F_1 () )
return;
if ( ! V_60 )
return;
V_50 = ( T_2 ) F_46 ( V_60 ) << V_48 ;
F_29 ( & V_58 , V_10 ) ;
V_64 = F_47 ( & V_54 , V_63 , V_50 ,
V_62 ) ;
for ( V_52 = 0 ; V_52 < V_64 ; V_52 ++ ) {
T_2 V_65 = F_32 ( V_61 [ V_52 ] ) ;
if ( V_65 == V_50 ) {
V_4 = V_61 [ V_52 ] ;
break;
} else if ( V_65 >= V_50 + V_62 )
break;
}
F_31 ( & V_58 , V_10 ) ;
if ( ! V_4 )
return;
V_50 = F_32 ( V_4 ) ;
F_48 ( V_4 -> V_7 , V_4 ,
L_4 ,
& V_50 ) ;
}
static void F_49 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
unsigned long V_10 ;
int V_56 ;
V_22 = F_11 ( V_4 , & V_10 ) ;
F_20 ( V_22 , V_4 ) ;
F_12 ( V_22 , & V_10 ) ;
V_56 = F_41 ( V_4 ) ;
if ( V_56 == - V_66 ) {
F_50 ( L_5 ) ;
V_1 = true ;
}
}
static struct V_3 * F_51 ( void )
{
struct V_3 * V_4 ;
V_4 = F_52 ( V_67 . V_68 , struct V_3 , V_36 ) ;
F_23 ( & V_4 -> V_36 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_69 -= 1 ;
if ( V_69 < V_70 )
V_70 = V_69 ;
return V_4 ;
}
static struct V_3 * F_53 ( void )
{
struct V_3 * V_4 ;
unsigned long V_10 ;
F_29 ( & V_71 , V_10 ) ;
if ( F_54 ( & V_67 ) ) {
V_1 = true ;
F_31 ( & V_71 , V_10 ) ;
F_50 ( L_6 ) ;
return NULL ;
}
V_4 = F_51 () ;
F_31 ( & V_71 , V_10 ) ;
#ifdef F_3
V_4 -> V_5 . V_72 = V_73 ;
V_4 -> V_5 . V_74 = V_4 -> V_75 ;
V_4 -> V_5 . V_76 = 2 ;
F_55 ( & V_4 -> V_5 ) ;
#endif
return V_4 ;
}
static void F_56 ( struct V_3 * V_4 )
{
unsigned long V_10 ;
F_43 ( V_4 ) ;
F_29 ( & V_71 , V_10 ) ;
F_57 ( & V_4 -> V_36 , & V_67 ) ;
V_69 += 1 ;
F_31 ( & V_71 , V_10 ) ;
}
int F_58 ( T_3 V_77 )
{
int V_52 , V_78 , V_11 = 0 ;
unsigned long V_10 ;
struct V_3 * V_4 ;
F_59 ( V_79 ) ;
F_29 ( & V_71 , V_10 ) ;
if ( V_80 < V_77 ) {
V_78 = V_77 - V_80 ;
F_31 ( & V_71 , V_10 ) ;
for ( V_52 = 0 ; V_52 < V_78 ; V_52 ++ ) {
V_4 = F_60 ( sizeof( * V_4 ) , V_81 ) ;
if ( ! V_4 )
break;
F_21 ( & V_4 -> V_36 , & V_79 ) ;
}
F_29 ( & V_71 , V_10 ) ;
F_61 ( & V_79 , & V_67 ) ;
V_80 += V_52 ;
V_69 += V_52 ;
} else {
V_78 = V_80 - V_77 ;
for ( V_52 = 0 ; V_52 < V_78 && ! F_54 ( & V_67 ) ; V_52 ++ ) {
V_4 = F_51 () ;
F_62 ( V_4 ) ;
}
V_80 -= V_52 ;
}
if ( V_80 != V_77 )
V_11 = 1 ;
F_31 ( & V_71 , V_10 ) ;
return V_11 ;
}
static int F_63 ( T_3 V_77 )
{
struct V_3 * V_4 , * V_82 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_77 ; ++ V_52 ) {
V_4 = F_60 ( sizeof( * V_4 ) , V_81 ) ;
if ( ! V_4 )
goto V_83;
F_21 ( & V_4 -> V_36 , & V_67 ) ;
}
V_69 = V_77 ;
V_70 = V_77 ;
F_64 ( L_7 , V_77 ) ;
return 0 ;
V_83:
F_65 (entry, next_entry, &free_entries, list) {
F_23 ( & V_4 -> V_36 ) ;
F_62 ( V_4 ) ;
}
return - V_66 ;
}
static T_4 F_66 ( struct V_84 * V_84 , char T_5 * V_85 ,
T_6 V_86 , T_7 * V_87 )
{
char V_88 [ V_17 + 1 ] ;
unsigned long V_10 ;
int V_89 ;
if ( ! V_12 [ 0 ] )
return 0 ;
F_8 ( & V_15 , V_10 ) ;
V_89 = F_67 ( V_88 , V_17 + 1 , L_8 , V_12 ) ;
F_9 ( & V_15 , V_10 ) ;
return F_68 ( V_85 , V_86 , V_87 , V_88 , V_89 ) ;
}
static T_4 F_69 ( struct V_84 * V_84 , const char T_5 * V_90 ,
T_6 V_86 , T_7 * V_87 )
{
char V_88 [ V_17 ] ;
unsigned long V_10 ;
T_6 V_89 ;
int V_52 ;
V_89 = F_70 ( V_86 , ( T_6 ) ( V_17 - 1 ) ) ;
if ( F_71 ( V_88 , V_90 , V_89 ) )
return - V_91 ;
V_88 [ V_89 ] = 0 ;
F_72 ( & V_15 , V_10 ) ;
if ( ! isalnum ( V_88 [ 0 ] ) ) {
if ( V_12 [ 0 ] )
F_64 ( L_9 ) ;
V_12 [ 0 ] = 0 ;
V_13 = NULL ;
goto V_92;
}
for ( V_52 = 0 ; V_52 < V_17 - 1 ; ++ V_52 ) {
V_12 [ V_52 ] = V_88 [ V_52 ] ;
if ( isspace ( V_88 [ V_52 ] ) || V_88 [ V_52 ] == ' ' || V_88 [ V_52 ] == 0 )
break;
}
V_12 [ V_52 ] = 0 ;
V_13 = NULL ;
F_64 ( L_10 ,
V_12 ) ;
V_92:
F_73 ( & V_15 , V_10 ) ;
return V_86 ;
}
static int F_74 ( void )
{
V_93 = F_75 ( L_11 , NULL ) ;
if ( ! V_93 ) {
F_50 ( L_12 ) ;
return - V_66 ;
}
V_94 = F_76 ( L_13 , 0444 ,
V_93 ,
& V_1 ) ;
if ( ! V_94 )
goto V_83;
V_95 = F_77 ( L_14 , 0444 ,
V_93 , & V_96 ) ;
if ( ! V_95 )
goto V_83;
V_97 = F_77 ( L_15 , 0644 ,
V_93 ,
& V_98 ) ;
if ( ! V_97 )
goto V_83;
V_99 = F_77 ( L_16 , 0644 ,
V_93 ,
& V_100 ) ;
if ( ! V_99 )
goto V_83;
V_101 = F_77 ( L_17 , 0444 ,
V_93 ,
& V_69 ) ;
if ( ! V_101 )
goto V_83;
V_102 = F_77 ( L_18 , 0444 ,
V_93 ,
& V_70 ) ;
if ( ! V_102 )
goto V_83;
V_103 = F_78 ( L_19 , 0644 ,
V_93 , NULL , & V_104 ) ;
if ( ! V_103 )
goto V_83;
return 0 ;
V_83:
F_79 ( V_93 ) ;
return - V_66 ;
}
static int F_80 ( struct V_6 * V_7 , struct V_3 * * V_105 )
{
struct V_3 * V_4 ;
unsigned long V_10 ;
int V_86 = 0 , V_52 ;
F_81 ( V_10 ) ;
for ( V_52 = 0 ; V_52 < V_41 ; ++ V_52 ) {
F_82 ( & V_42 [ V_52 ] . V_43 ) ;
F_16 (entry, &dma_entry_hash[i].list, list) {
if ( V_4 -> V_7 == V_7 ) {
V_86 += 1 ;
* V_105 = V_4 ;
}
}
F_83 ( & V_42 [ V_52 ] . V_43 ) ;
}
F_84 ( V_10 ) ;
return V_86 ;
}
static int F_85 ( struct V_106 * V_107 , unsigned long V_108 , void * V_109 )
{
struct V_6 * V_7 = V_109 ;
struct V_3 * V_110 ( V_4 ) ;
int V_86 ;
if ( F_1 () )
return 0 ;
switch ( V_108 ) {
case V_111 :
V_86 = F_80 ( V_7 , & V_4 ) ;
if ( V_86 == 0 )
break;
F_48 ( V_7 , V_4 , L_20
L_21
L_22
L_23
L_24
L_25 ,
V_86 , V_4 -> V_18 , V_4 -> V_25 ,
V_45 [ V_4 -> V_31 ] , V_44 [ V_4 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_86 ( struct V_112 * V_113 )
{
struct V_106 * V_107 ;
if ( F_1 () )
return;
V_107 = F_60 ( sizeof( struct V_106 ) , V_81 ) ;
if ( V_107 == NULL ) {
F_50 ( L_26 ) ;
return;
}
V_107 -> V_114 = F_85 ;
F_87 ( V_113 , V_107 ) ;
}
void F_88 ( T_3 V_77 )
{
int V_52 ;
if ( V_1 )
return;
for ( V_52 = 0 ; V_52 < V_41 ; ++ V_52 ) {
F_89 ( & V_42 [ V_52 ] . V_36 ) ;
F_90 ( & V_42 [ V_52 ] . V_43 ) ;
}
if ( F_74 () != 0 ) {
F_50 ( L_27 ) ;
V_1 = true ;
return;
}
if ( V_115 )
V_77 = V_115 ;
if ( F_63 ( V_77 ) != 0 ) {
F_50 ( L_28 ) ;
V_1 = true ;
return;
}
V_80 = V_69 ;
V_2 = true ;
F_64 ( L_29 ) ;
}
static T_8 int F_91 ( char * V_116 )
{
if ( ! V_116 )
return - V_117 ;
if ( strncmp ( V_116 , L_30 , 3 ) == 0 ) {
F_64 ( L_31 ) ;
V_1 = true ;
}
return 0 ;
}
static T_8 int F_92 ( char * V_116 )
{
int V_118 ;
if ( ! V_116 )
return - V_117 ;
V_118 = F_93 ( & V_116 , & V_115 ) ;
if ( ! V_118 )
V_115 = 0 ;
return 0 ;
}
static void F_94 ( struct V_3 * V_26 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
V_22 = F_11 ( V_26 , & V_10 ) ;
V_4 = F_17 ( V_22 , V_26 ) ;
if ( ! V_4 ) {
F_12 ( V_22 , & V_10 ) ;
if ( F_95 ( V_26 -> V_7 , V_26 -> V_18 ) ) {
F_48 ( V_26 -> V_7 , NULL ,
L_32
L_33 ) ;
} else {
F_48 ( V_26 -> V_7 , NULL ,
L_34
L_35
L_36 ,
V_26 -> V_18 , V_26 -> V_25 ) ;
}
return;
}
if ( V_26 -> V_25 != V_4 -> V_25 ) {
F_48 ( V_26 -> V_7 , V_4 , L_37
L_38
L_39
L_40 ,
V_26 -> V_18 , V_4 -> V_25 , V_26 -> V_25 ) ;
}
if ( V_26 -> type != V_4 -> type ) {
F_48 ( V_26 -> V_7 , V_4 , L_37
L_41
L_24
L_42 ,
V_26 -> V_18 , V_26 -> V_25 ,
V_44 [ V_4 -> type ] , V_44 [ V_26 -> type ] ) ;
} else if ( ( V_4 -> type == V_119 ) &&
( F_24 ( V_26 ) != F_24 ( V_4 ) ) ) {
F_48 ( V_26 -> V_7 , V_4 , L_37
L_43
L_24
L_44
L_45 ,
V_26 -> V_18 , V_26 -> V_25 ,
F_24 ( V_4 ) ,
F_24 ( V_26 ) ) ;
}
if ( V_26 -> V_32 && V_26 -> type == V_120 &&
V_26 -> V_32 != V_4 -> V_32 ) {
F_48 ( V_26 -> V_7 , V_4 , L_37
L_46
L_47 ,
V_4 -> V_32 , V_26 -> V_32 ) ;
}
if ( V_26 -> V_31 != V_4 -> V_31 ) {
F_48 ( V_26 -> V_7 , V_4 , L_37
L_48
L_24
L_49 ,
V_26 -> V_18 , V_26 -> V_25 ,
V_45 [ V_4 -> V_31 ] ,
V_45 [ V_26 -> V_31 ] ) ;
}
if ( V_4 -> V_47 == V_121 ) {
F_48 ( V_26 -> V_7 , V_4 ,
L_50
L_24
L_51 ,
V_26 -> V_18 , V_26 -> V_25 ,
V_44 [ V_4 -> type ] ) ;
}
F_22 ( V_4 ) ;
F_56 ( V_4 ) ;
F_12 ( V_22 , & V_10 ) ;
}
static void F_96 ( struct V_6 * V_7 ,
struct V_60 * V_60 , T_6 V_39 )
{
void * V_122 ;
struct V_123 * V_124 = F_97 ( V_125 ) ;
if ( ! V_124 ) {
if ( F_98 ( V_60 ) )
return;
V_122 = F_99 ( V_60 ) + V_39 ;
if ( F_100 ( V_122 ) )
F_48 ( V_7 , NULL , L_52 , V_122 ) ;
} else {
int V_52 ;
for ( V_52 = 0 ; V_52 < V_124 -> V_126 ; V_52 ++ ) {
if ( V_60 != V_124 -> V_127 [ V_52 ] )
continue;
V_122 = ( V_128 * ) V_125 -> V_129 + V_52 * V_130 + V_39 ;
F_48 ( V_7 , NULL , L_53 , V_122 ) ;
break;
}
}
}
static inline bool V_51 ( void * V_122 , unsigned long V_89 , void * V_131 , void * V_132 )
{
unsigned long V_133 = ( unsigned long ) V_122 ;
unsigned long V_134 = V_133 + V_89 ;
unsigned long V_135 = ( unsigned long ) V_131 ;
unsigned long V_136 = ( unsigned long ) V_132 ;
return ! ( V_134 <= V_135 || V_133 >= V_136 ) ;
}
static void F_101 ( struct V_6 * V_7 , void * V_122 , unsigned long V_89 )
{
if ( V_51 ( V_122 , V_89 , V_137 , V_138 ) ||
V_51 ( V_122 , V_89 , V_139 , V_140 ) )
F_48 ( V_7 , NULL , L_54 , V_122 , V_89 ) ;
}
static void F_102 ( struct V_6 * V_7 ,
struct V_3 * V_26 ,
bool V_141 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
V_22 = F_11 ( V_26 , & V_10 ) ;
V_4 = F_18 ( & V_22 , V_26 , & V_10 ) ;
if ( ! V_4 ) {
F_48 ( V_7 , NULL , L_55
L_56
L_57 ,
( unsigned long long ) V_26 -> V_18 , V_26 -> V_25 ) ;
goto V_142;
}
if ( V_26 -> V_25 > V_4 -> V_25 ) {
F_48 ( V_7 , V_4 , L_58
L_59
L_60
L_61
L_62 ,
V_4 -> V_18 , V_4 -> V_25 ,
V_26 -> V_25 ) ;
}
if ( V_4 -> V_31 == V_143 )
goto V_142;
if ( V_26 -> V_31 != V_4 -> V_31 ) {
F_48 ( V_7 , V_4 , L_63
L_48
L_24
L_64 ,
( unsigned long long ) V_26 -> V_18 , V_4 -> V_25 ,
V_45 [ V_4 -> V_31 ] ,
V_45 [ V_26 -> V_31 ] ) ;
}
if ( V_141 && ! ( V_4 -> V_31 == V_144 ) &&
! ( V_26 -> V_31 == V_57 ) )
F_48 ( V_7 , V_4 , L_63
L_65
L_24
L_64 ,
( unsigned long long ) V_26 -> V_18 , V_4 -> V_25 ,
V_45 [ V_4 -> V_31 ] ,
V_45 [ V_26 -> V_31 ] ) ;
if ( ! V_141 && ! ( V_4 -> V_31 == V_57 ) &&
! ( V_26 -> V_31 == V_144 ) )
F_48 ( V_7 , V_4 , L_63
L_66
L_24
L_64 ,
( unsigned long long ) V_26 -> V_18 , V_4 -> V_25 ,
V_45 [ V_4 -> V_31 ] ,
V_45 [ V_26 -> V_31 ] ) ;
if ( V_26 -> V_32 && V_26 -> type == V_120 &&
V_26 -> V_32 != V_4 -> V_32 ) {
F_48 ( V_26 -> V_7 , V_4 , L_63
L_46
L_67 ,
V_4 -> V_32 , V_26 -> V_32 ) ;
}
V_142:
F_12 ( V_22 , & V_10 ) ;
}
void F_103 ( struct V_6 * V_7 , struct V_60 * V_60 , T_6 V_39 ,
T_6 V_25 , int V_31 , T_9 V_145 ,
bool V_146 )
{
struct V_3 * V_4 ;
if ( F_104 ( F_1 () ) )
return;
if ( F_95 ( V_7 , V_145 ) )
return;
V_4 = F_53 () ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_7 ;
V_4 -> type = V_147 ;
V_4 -> V_38 = F_46 ( V_60 ) ;
V_4 -> V_39 = V_39 ,
V_4 -> V_18 = V_145 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_47 = V_121 ;
if ( V_146 )
V_4 -> type = V_148 ;
F_96 ( V_7 , V_60 , V_39 ) ;
if ( ! F_98 ( V_60 ) ) {
void * V_122 = F_99 ( V_60 ) + V_39 ;
F_101 ( V_7 , V_122 , V_25 ) ;
}
F_49 ( V_4 ) ;
}
void F_105 ( struct V_6 * V_7 , T_9 V_145 )
{
struct V_3 V_26 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
if ( F_104 ( F_1 () ) )
return;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_145 ;
V_22 = F_11 ( & V_26 , & V_10 ) ;
F_16 (entry, &bucket->list, list) {
if ( ! F_13 ( & V_26 , V_4 ) )
continue;
if ( V_4 -> V_47 == V_121 ) {
V_4 -> V_47 = V_149 ;
break;
}
}
F_12 ( V_22 , & V_10 ) ;
}
void F_106 ( struct V_6 * V_7 , T_9 V_122 ,
T_6 V_25 , int V_31 , bool V_146 )
{
struct V_3 V_26 = {
. type = V_147 ,
. V_7 = V_7 ,
. V_18 = V_122 ,
. V_25 = V_25 ,
. V_31 = V_31 ,
} ;
if ( F_104 ( F_1 () ) )
return;
if ( V_146 )
V_26 . type = V_148 ;
F_94 ( & V_26 ) ;
}
void F_107 ( struct V_6 * V_7 , struct V_150 * V_151 ,
int V_64 , int V_152 , int V_31 )
{
struct V_3 * V_4 ;
struct V_150 * V_153 ;
int V_52 ;
if ( F_104 ( F_1 () ) )
return;
F_108 (sg, s, mapped_ents, i) {
V_4 = F_53 () ;
if ( ! V_4 )
return;
V_4 -> type = V_120 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_38 = F_46 ( F_109 ( V_153 ) ) ;
V_4 -> V_39 = V_153 -> V_39 ,
V_4 -> V_25 = F_110 ( V_153 ) ;
V_4 -> V_18 = F_111 ( V_153 ) ;
V_4 -> V_31 = V_31 ;
V_4 -> V_32 = V_64 ;
V_4 -> V_154 = V_152 ;
F_96 ( V_7 , F_109 ( V_153 ) , V_153 -> V_39 ) ;
if ( ! F_98 ( F_109 ( V_153 ) ) ) {
F_101 ( V_7 , F_112 ( V_153 ) , F_110 ( V_153 ) ) ;
}
F_49 ( V_4 ) ;
}
}
static int F_113 ( struct V_6 * V_7 ,
struct V_3 * V_26 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
int V_152 ;
V_22 = F_11 ( V_26 , & V_10 ) ;
V_4 = F_17 ( V_22 , V_26 ) ;
V_152 = 0 ;
if ( V_4 )
V_152 = V_4 -> V_154 ;
F_12 ( V_22 , & V_10 ) ;
return V_152 ;
}
void F_114 ( struct V_6 * V_7 , struct V_150 * V_155 ,
int V_156 , int V_157 )
{
struct V_150 * V_153 ;
int V_152 = 0 , V_52 ;
if ( F_104 ( F_1 () ) )
return;
F_108 (sglist, s, nelems, i) {
struct V_3 V_26 = {
. type = V_120 ,
. V_7 = V_7 ,
. V_38 = F_46 ( F_109 ( V_153 ) ) ,
. V_39 = V_153 -> V_39 ,
. V_18 = F_111 ( V_153 ) ,
. V_25 = F_110 ( V_153 ) ,
. V_31 = V_157 ,
. V_32 = V_156 ,
} ;
if ( V_152 && V_52 >= V_152 )
break;
if ( ! V_52 )
V_152 = F_113 ( V_7 , & V_26 ) ;
F_94 ( & V_26 ) ;
}
}
void F_115 ( struct V_6 * V_7 , T_6 V_25 ,
T_9 V_145 , void * V_158 )
{
struct V_3 * V_4 ;
if ( F_104 ( F_1 () ) )
return;
if ( F_104 ( V_158 == NULL ) )
return;
V_4 = F_53 () ;
if ( ! V_4 )
return;
V_4 -> type = V_119 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_38 = F_46 ( F_116 ( V_158 ) ) ;
V_4 -> V_39 = ( T_6 ) V_158 & ~ V_159 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_18 = V_145 ;
V_4 -> V_31 = V_143 ;
F_49 ( V_4 ) ;
}
void F_117 ( struct V_6 * V_7 , T_6 V_25 ,
void * V_158 , T_9 V_122 )
{
struct V_3 V_26 = {
. type = V_119 ,
. V_7 = V_7 ,
. V_38 = F_46 ( F_116 ( V_158 ) ) ,
. V_39 = ( T_6 ) V_158 & ~ V_159 ,
. V_18 = V_122 ,
. V_25 = V_25 ,
. V_31 = V_143 ,
} ;
if ( F_104 ( F_1 () ) )
return;
F_94 ( & V_26 ) ;
}
void F_118 ( struct V_6 * V_7 , T_2 V_122 , T_6 V_25 ,
int V_31 , T_9 V_145 )
{
struct V_3 * V_4 ;
if ( F_104 ( F_1 () ) )
return;
V_4 = F_53 () ;
if ( ! V_4 )
return;
V_4 -> type = V_37 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_38 = F_119 ( V_122 ) ;
V_4 -> V_39 = F_120 ( V_122 ) ;
V_4 -> V_25 = V_25 ;
V_4 -> V_18 = V_145 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_47 = V_121 ;
F_49 ( V_4 ) ;
}
void F_121 ( struct V_6 * V_7 , T_9 V_145 ,
T_6 V_25 , int V_31 )
{
struct V_3 V_26 = {
. type = V_37 ,
. V_7 = V_7 ,
. V_18 = V_145 ,
. V_25 = V_25 ,
. V_31 = V_31 ,
} ;
if ( F_104 ( F_1 () ) )
return;
F_94 ( & V_26 ) ;
}
void F_122 ( struct V_6 * V_7 , T_9 V_160 ,
T_6 V_25 , int V_31 )
{
struct V_3 V_26 ;
if ( F_104 ( F_1 () ) )
return;
V_26 . type = V_148 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_160 ;
V_26 . V_25 = V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_102 ( V_7 , & V_26 , true ) ;
}
void F_123 ( struct V_6 * V_7 ,
T_9 V_160 , T_6 V_25 ,
int V_31 )
{
struct V_3 V_26 ;
if ( F_104 ( F_1 () ) )
return;
V_26 . type = V_148 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_160 ;
V_26 . V_25 = V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_102 ( V_7 , & V_26 , false ) ;
}
void F_124 ( struct V_6 * V_7 ,
T_9 V_160 ,
unsigned long V_39 , T_6 V_25 ,
int V_31 )
{
struct V_3 V_26 ;
if ( F_104 ( F_1 () ) )
return;
V_26 . type = V_148 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_160 ;
V_26 . V_25 = V_39 + V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_102 ( V_7 , & V_26 , true ) ;
}
void F_125 ( struct V_6 * V_7 ,
T_9 V_160 ,
unsigned long V_39 ,
T_6 V_25 , int V_31 )
{
struct V_3 V_26 ;
if ( F_104 ( F_1 () ) )
return;
V_26 . type = V_148 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_160 ;
V_26 . V_25 = V_39 + V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_102 ( V_7 , & V_26 , false ) ;
}
void F_126 ( struct V_6 * V_7 , struct V_150 * V_151 ,
int V_156 , int V_31 )
{
struct V_150 * V_153 ;
int V_152 = 0 , V_52 ;
if ( F_104 ( F_1 () ) )
return;
F_108 (sg, s, nelems, i) {
struct V_3 V_26 = {
. type = V_120 ,
. V_7 = V_7 ,
. V_38 = F_46 ( F_109 ( V_153 ) ) ,
. V_39 = V_153 -> V_39 ,
. V_18 = F_111 ( V_153 ) ,
. V_25 = F_110 ( V_153 ) ,
. V_31 = V_31 ,
. V_32 = V_156 ,
} ;
if ( ! V_52 )
V_152 = F_113 ( V_7 , & V_26 ) ;
if ( V_52 >= V_152 )
break;
F_102 ( V_7 , & V_26 , true ) ;
}
}
void F_127 ( struct V_6 * V_7 , struct V_150 * V_151 ,
int V_156 , int V_31 )
{
struct V_150 * V_153 ;
int V_152 = 0 , V_52 ;
if ( F_104 ( F_1 () ) )
return;
F_108 (sg, s, nelems, i) {
struct V_3 V_26 = {
. type = V_120 ,
. V_7 = V_7 ,
. V_38 = F_46 ( F_109 ( V_153 ) ) ,
. V_39 = V_153 -> V_39 ,
. V_18 = F_111 ( V_153 ) ,
. V_25 = F_110 ( V_153 ) ,
. V_31 = V_31 ,
. V_32 = V_156 ,
} ;
if ( ! V_52 )
V_152 = F_113 ( V_7 , & V_26 ) ;
if ( V_52 >= V_152 )
break;
F_102 ( V_7 , & V_26 , false ) ;
}
}
static int T_8 F_128 ( char * V_116 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_17 - 1 ; ++ V_52 , ++ V_116 ) {
V_12 [ V_52 ] = * V_116 ;
if ( * V_116 == 0 )
break;
}
if ( V_12 [ 0 ] )
F_64 ( L_10 ,
V_12 ) ;
return 1 ;
}
