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
return F_25 ( F_26 ( V_4 -> V_37 ) ) + V_4 -> V_38 ;
}
void F_27 ( struct V_6 * V_7 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
struct V_21 * V_22 = & V_41 [ V_39 ] ;
struct V_3 * V_4 ;
unsigned long V_10 ;
F_28 ( & V_22 -> V_42 , V_10 ) ;
F_16 (entry, &bucket->list, list) {
if ( ! V_7 || V_7 == V_4 -> V_7 ) {
F_29 ( V_4 -> V_7 ,
L_2 ,
V_43 [ V_4 -> type ] , V_39 ,
F_24 ( V_4 ) , V_4 -> V_37 ,
V_4 -> V_18 , V_4 -> V_25 ,
V_44 [ V_4 -> V_31 ] ,
V_45 [ V_4 -> V_46 ] ) ;
}
}
F_30 ( & V_22 -> V_42 , V_10 ) ;
}
}
static T_2 F_31 ( struct V_3 * V_4 )
{
return ( V_4 -> V_37 << V_47 ) +
( V_4 -> V_38 >> V_48 ) ;
}
static int F_32 ( T_2 V_49 )
{
int V_50 = 0 , V_51 ;
for ( V_51 = V_52 - 1 ; V_51 >= 0 ; V_51 -- )
if ( F_33 ( & V_53 , V_49 , V_51 ) )
V_50 |= 1 << V_51 ;
return V_50 ;
}
static int F_34 ( T_2 V_49 , int V_50 )
{
int V_51 ;
if ( V_50 > V_54 || V_50 < 0 )
return V_50 ;
for ( V_51 = V_52 - 1 ; V_51 >= 0 ; V_51 -- )
if ( V_50 & 1 << V_51 )
F_35 ( & V_53 , V_49 , V_51 ) ;
else
F_36 ( & V_53 , V_49 , V_51 ) ;
return V_50 ;
}
static void F_37 ( T_2 V_49 )
{
int V_50 = F_32 ( V_49 ) ;
V_50 = F_34 ( V_49 , ++ V_50 ) ;
F_38 ( V_50 > V_54 ,
L_3 ,
V_54 , & V_49 ) ;
}
static int F_39 ( T_2 V_49 )
{
int V_50 = F_32 ( V_49 ) ;
return F_34 ( V_49 , -- V_50 ) ;
}
static int F_40 ( struct V_3 * V_4 )
{
T_2 V_49 = F_31 ( V_4 ) ;
unsigned long V_10 ;
int V_55 ;
if ( V_4 -> V_31 == V_56 )
return 0 ;
F_28 ( & V_57 , V_10 ) ;
V_55 = F_41 ( & V_53 , V_49 , V_4 ) ;
if ( V_55 == - V_58 )
F_37 ( V_49 ) ;
F_30 ( & V_57 , V_10 ) ;
return V_55 ;
}
static void F_42 ( struct V_3 * V_4 )
{
T_2 V_49 = F_31 ( V_4 ) ;
unsigned long V_10 ;
if ( V_4 -> V_31 == V_56 )
return;
F_28 ( & V_57 , V_10 ) ;
if ( F_39 ( V_49 ) < 0 )
F_43 ( & V_53 , V_49 ) ;
F_30 ( & V_57 , V_10 ) ;
}
void F_44 ( struct V_59 * V_59 )
{
static struct V_3 * V_60 [ V_61 ] ;
struct V_3 * V_4 = NULL ;
void * * V_62 = ( void * * ) & V_60 ;
unsigned int V_63 , V_51 ;
unsigned long V_10 ;
T_2 V_49 ;
if ( F_1 () )
return;
if ( ! V_59 )
return;
V_49 = ( T_2 ) F_45 ( V_59 ) << V_47 ;
F_28 ( & V_57 , V_10 ) ;
V_63 = F_46 ( & V_53 , V_62 , V_49 ,
V_61 ) ;
for ( V_51 = 0 ; V_51 < V_63 ; V_51 ++ ) {
T_2 V_64 = F_31 ( V_60 [ V_51 ] ) ;
if ( V_64 == V_49 ) {
V_4 = V_60 [ V_51 ] ;
break;
} else if ( V_64 >= V_49 + V_61 )
break;
}
F_30 ( & V_57 , V_10 ) ;
if ( ! V_4 )
return;
V_49 = F_31 ( V_4 ) ;
F_47 ( V_4 -> V_7 , V_4 ,
L_4 ,
& V_49 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
unsigned long V_10 ;
int V_55 ;
V_22 = F_11 ( V_4 , & V_10 ) ;
F_20 ( V_22 , V_4 ) ;
F_12 ( V_22 , & V_10 ) ;
V_55 = F_40 ( V_4 ) ;
if ( V_55 == - V_65 ) {
F_49 ( L_5 ) ;
V_1 = true ;
}
}
static struct V_3 * F_50 ( void )
{
struct V_3 * V_4 ;
V_4 = F_51 ( V_66 . V_67 , struct V_3 , V_36 ) ;
F_23 ( & V_4 -> V_36 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_68 -= 1 ;
if ( V_68 < V_69 )
V_69 = V_68 ;
return V_4 ;
}
static struct V_3 * F_52 ( void )
{
struct V_3 * V_4 ;
unsigned long V_10 ;
F_28 ( & V_70 , V_10 ) ;
if ( F_53 ( & V_66 ) ) {
V_1 = true ;
F_30 ( & V_70 , V_10 ) ;
F_49 ( L_6 ) ;
return NULL ;
}
V_4 = F_50 () ;
F_30 ( & V_70 , V_10 ) ;
#ifdef F_3
V_4 -> V_5 . V_71 = V_72 ;
V_4 -> V_5 . V_73 = V_4 -> V_74 ;
V_4 -> V_5 . V_75 = 2 ;
F_54 ( & V_4 -> V_5 ) ;
#endif
return V_4 ;
}
static void F_55 ( struct V_3 * V_4 )
{
unsigned long V_10 ;
F_42 ( V_4 ) ;
F_28 ( & V_70 , V_10 ) ;
F_56 ( & V_4 -> V_36 , & V_66 ) ;
V_68 += 1 ;
F_30 ( & V_70 , V_10 ) ;
}
int F_57 ( T_3 V_76 )
{
int V_51 , V_77 , V_11 = 0 ;
unsigned long V_10 ;
struct V_3 * V_4 ;
F_58 ( V_78 ) ;
F_28 ( & V_70 , V_10 ) ;
if ( V_79 < V_76 ) {
V_77 = V_76 - V_79 ;
F_30 ( & V_70 , V_10 ) ;
for ( V_51 = 0 ; V_51 < V_77 ; V_51 ++ ) {
V_4 = F_59 ( sizeof( * V_4 ) , V_80 ) ;
if ( ! V_4 )
break;
F_21 ( & V_4 -> V_36 , & V_78 ) ;
}
F_28 ( & V_70 , V_10 ) ;
F_60 ( & V_78 , & V_66 ) ;
V_79 += V_51 ;
V_68 += V_51 ;
} else {
V_77 = V_79 - V_76 ;
for ( V_51 = 0 ; V_51 < V_77 && ! F_53 ( & V_66 ) ; V_51 ++ ) {
V_4 = F_50 () ;
F_61 ( V_4 ) ;
}
V_79 -= V_51 ;
}
if ( V_79 != V_76 )
V_11 = 1 ;
F_30 ( & V_70 , V_10 ) ;
return V_11 ;
}
static int F_62 ( T_3 V_76 )
{
struct V_3 * V_4 , * V_81 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_76 ; ++ V_51 ) {
V_4 = F_59 ( sizeof( * V_4 ) , V_80 ) ;
if ( ! V_4 )
goto V_82;
F_21 ( & V_4 -> V_36 , & V_66 ) ;
}
V_68 = V_76 ;
V_69 = V_76 ;
F_63 ( L_7 , V_76 ) ;
return 0 ;
V_82:
F_64 (entry, next_entry, &free_entries, list) {
F_23 ( & V_4 -> V_36 ) ;
F_61 ( V_4 ) ;
}
return - V_65 ;
}
static T_4 F_65 ( struct V_83 * V_83 , char T_5 * V_84 ,
T_6 V_85 , T_7 * V_86 )
{
char V_87 [ V_17 + 1 ] ;
unsigned long V_10 ;
int V_88 ;
if ( ! V_12 [ 0 ] )
return 0 ;
F_8 ( & V_15 , V_10 ) ;
V_88 = F_66 ( V_87 , V_17 + 1 , L_8 , V_12 ) ;
F_9 ( & V_15 , V_10 ) ;
return F_67 ( V_84 , V_85 , V_86 , V_87 , V_88 ) ;
}
static T_4 F_68 ( struct V_83 * V_83 , const char T_5 * V_89 ,
T_6 V_85 , T_7 * V_86 )
{
char V_87 [ V_17 ] ;
unsigned long V_10 ;
T_6 V_88 ;
int V_51 ;
V_88 = F_69 ( V_85 , ( T_6 ) ( V_17 - 1 ) ) ;
if ( F_70 ( V_87 , V_89 , V_88 ) )
return - V_90 ;
V_87 [ V_88 ] = 0 ;
F_71 ( & V_15 , V_10 ) ;
if ( ! isalnum ( V_87 [ 0 ] ) ) {
if ( V_12 [ 0 ] )
F_63 ( L_9 ) ;
V_12 [ 0 ] = 0 ;
V_13 = NULL ;
goto V_91;
}
for ( V_51 = 0 ; V_51 < V_17 - 1 ; ++ V_51 ) {
V_12 [ V_51 ] = V_87 [ V_51 ] ;
if ( isspace ( V_87 [ V_51 ] ) || V_87 [ V_51 ] == ' ' || V_87 [ V_51 ] == 0 )
break;
}
V_12 [ V_51 ] = 0 ;
V_13 = NULL ;
F_63 ( L_10 ,
V_12 ) ;
V_91:
F_72 ( & V_15 , V_10 ) ;
return V_85 ;
}
static int F_73 ( void )
{
V_92 = F_74 ( L_11 , NULL ) ;
if ( ! V_92 ) {
F_49 ( L_12 ) ;
return - V_65 ;
}
V_93 = F_75 ( L_13 , 0444 ,
V_92 ,
& V_1 ) ;
if ( ! V_93 )
goto V_82;
V_94 = F_76 ( L_14 , 0444 ,
V_92 , & V_95 ) ;
if ( ! V_94 )
goto V_82;
V_96 = F_76 ( L_15 , 0644 ,
V_92 ,
& V_97 ) ;
if ( ! V_96 )
goto V_82;
V_98 = F_76 ( L_16 , 0644 ,
V_92 ,
& V_99 ) ;
if ( ! V_98 )
goto V_82;
V_100 = F_76 ( L_17 , 0444 ,
V_92 ,
& V_68 ) ;
if ( ! V_100 )
goto V_82;
V_101 = F_76 ( L_18 , 0444 ,
V_92 ,
& V_69 ) ;
if ( ! V_101 )
goto V_82;
V_102 = F_77 ( L_19 , 0644 ,
V_92 , NULL , & V_103 ) ;
if ( ! V_102 )
goto V_82;
return 0 ;
V_82:
F_78 ( V_92 ) ;
return - V_65 ;
}
static int F_79 ( struct V_6 * V_7 , struct V_3 * * V_104 )
{
struct V_3 * V_4 ;
unsigned long V_10 ;
int V_85 = 0 , V_51 ;
F_80 ( V_10 ) ;
for ( V_51 = 0 ; V_51 < V_40 ; ++ V_51 ) {
F_81 ( & V_41 [ V_51 ] . V_42 ) ;
F_16 (entry, &dma_entry_hash[i].list, list) {
if ( V_4 -> V_7 == V_7 ) {
V_85 += 1 ;
* V_104 = V_4 ;
}
}
F_82 ( & V_41 [ V_51 ] . V_42 ) ;
}
F_83 ( V_10 ) ;
return V_85 ;
}
static int F_84 ( struct V_105 * V_106 , unsigned long V_107 , void * V_108 )
{
struct V_6 * V_7 = V_108 ;
struct V_3 * V_109 ( V_4 ) ;
int V_85 ;
if ( F_1 () )
return 0 ;
switch ( V_107 ) {
case V_110 :
V_85 = F_79 ( V_7 , & V_4 ) ;
if ( V_85 == 0 )
break;
F_47 ( V_7 , V_4 , L_20
L_21
L_22
L_23
L_24
L_25 ,
V_85 , V_4 -> V_18 , V_4 -> V_25 ,
V_44 [ V_4 -> V_31 ] , V_43 [ V_4 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_85 ( struct V_111 * V_112 )
{
struct V_105 * V_106 ;
if ( F_1 () )
return;
V_106 = F_59 ( sizeof( struct V_105 ) , V_80 ) ;
if ( V_106 == NULL ) {
F_49 ( L_26 ) ;
return;
}
V_106 -> V_113 = F_84 ;
F_86 ( V_112 , V_106 ) ;
}
void F_87 ( T_3 V_76 )
{
int V_51 ;
if ( V_1 )
return;
for ( V_51 = 0 ; V_51 < V_40 ; ++ V_51 ) {
F_88 ( & V_41 [ V_51 ] . V_36 ) ;
F_89 ( & V_41 [ V_51 ] . V_42 ) ;
}
if ( F_73 () != 0 ) {
F_49 ( L_27 ) ;
V_1 = true ;
return;
}
if ( V_114 )
V_76 = V_114 ;
if ( F_62 ( V_76 ) != 0 ) {
F_49 ( L_28 ) ;
V_1 = true ;
return;
}
V_79 = V_68 ;
V_2 = true ;
F_63 ( L_29 ) ;
}
static T_8 int F_90 ( char * V_115 )
{
if ( ! V_115 )
return - V_116 ;
if ( strncmp ( V_115 , L_30 , 3 ) == 0 ) {
F_63 ( L_31 ) ;
V_1 = true ;
}
return 0 ;
}
static T_8 int F_91 ( char * V_115 )
{
int V_117 ;
if ( ! V_115 )
return - V_116 ;
V_117 = F_92 ( & V_115 , & V_114 ) ;
if ( ! V_117 )
V_114 = 0 ;
return 0 ;
}
static void F_93 ( struct V_3 * V_26 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
V_22 = F_11 ( V_26 , & V_10 ) ;
V_4 = F_17 ( V_22 , V_26 ) ;
if ( ! V_4 ) {
F_12 ( V_22 , & V_10 ) ;
if ( F_94 ( V_26 -> V_7 , V_26 -> V_18 ) ) {
F_47 ( V_26 -> V_7 , NULL ,
L_32
L_33 ) ;
} else {
F_47 ( V_26 -> V_7 , NULL ,
L_34
L_35
L_36 ,
V_26 -> V_18 , V_26 -> V_25 ) ;
}
return;
}
if ( V_26 -> V_25 != V_4 -> V_25 ) {
F_47 ( V_26 -> V_7 , V_4 , L_37
L_38
L_39
L_40 ,
V_26 -> V_18 , V_4 -> V_25 , V_26 -> V_25 ) ;
}
if ( V_26 -> type != V_4 -> type ) {
F_47 ( V_26 -> V_7 , V_4 , L_37
L_41
L_24
L_42 ,
V_26 -> V_18 , V_26 -> V_25 ,
V_43 [ V_4 -> type ] , V_43 [ V_26 -> type ] ) ;
} else if ( ( V_4 -> type == V_118 ) &&
( F_24 ( V_26 ) != F_24 ( V_4 ) ) ) {
F_47 ( V_26 -> V_7 , V_4 , L_37
L_43
L_24
L_44
L_45 ,
V_26 -> V_18 , V_26 -> V_25 ,
F_24 ( V_4 ) ,
F_24 ( V_26 ) ) ;
}
if ( V_26 -> V_32 && V_26 -> type == V_119 &&
V_26 -> V_32 != V_4 -> V_32 ) {
F_47 ( V_26 -> V_7 , V_4 , L_37
L_46
L_47 ,
V_4 -> V_32 , V_26 -> V_32 ) ;
}
if ( V_26 -> V_31 != V_4 -> V_31 ) {
F_47 ( V_26 -> V_7 , V_4 , L_37
L_48
L_24
L_49 ,
V_26 -> V_18 , V_26 -> V_25 ,
V_44 [ V_4 -> V_31 ] ,
V_44 [ V_26 -> V_31 ] ) ;
}
if ( V_4 -> V_46 == V_120 ) {
F_47 ( V_26 -> V_7 , V_4 ,
L_50
L_24
L_51 ,
V_26 -> V_18 , V_26 -> V_25 ,
V_43 [ V_4 -> type ] ) ;
}
F_22 ( V_4 ) ;
F_55 ( V_4 ) ;
F_12 ( V_22 , & V_10 ) ;
}
static void F_95 ( struct V_6 * V_7 , void * V_121 )
{
if ( F_96 ( V_121 ) )
F_47 ( V_7 , NULL , L_52
L_53 , V_121 ) ;
}
static inline bool V_50 ( void * V_121 , unsigned long V_88 , void * V_122 , void * V_123 )
{
unsigned long V_124 = ( unsigned long ) V_121 ;
unsigned long V_125 = V_124 + V_88 ;
unsigned long V_126 = ( unsigned long ) V_122 ;
unsigned long V_127 = ( unsigned long ) V_123 ;
return ! ( V_125 <= V_126 || V_124 >= V_127 ) ;
}
static void F_97 ( struct V_6 * V_7 , void * V_121 , unsigned long V_88 )
{
if ( V_50 ( V_121 , V_88 , V_128 , V_129 ) ||
V_50 ( V_121 , V_88 , V_130 , V_131 ) )
F_47 ( V_7 , NULL , L_54 , V_121 , V_88 ) ;
}
static void F_98 ( struct V_6 * V_7 ,
struct V_3 * V_26 ,
bool V_132 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
V_22 = F_11 ( V_26 , & V_10 ) ;
V_4 = F_18 ( & V_22 , V_26 , & V_10 ) ;
if ( ! V_4 ) {
F_47 ( V_7 , NULL , L_55
L_56
L_57 ,
( unsigned long long ) V_26 -> V_18 , V_26 -> V_25 ) ;
goto V_133;
}
if ( V_26 -> V_25 > V_4 -> V_25 ) {
F_47 ( V_7 , V_4 , L_58
L_59
L_60
L_61
L_62 ,
V_4 -> V_18 , V_4 -> V_25 ,
V_26 -> V_25 ) ;
}
if ( V_4 -> V_31 == V_134 )
goto V_133;
if ( V_26 -> V_31 != V_4 -> V_31 ) {
F_47 ( V_7 , V_4 , L_63
L_48
L_24
L_64 ,
( unsigned long long ) V_26 -> V_18 , V_4 -> V_25 ,
V_44 [ V_4 -> V_31 ] ,
V_44 [ V_26 -> V_31 ] ) ;
}
if ( V_132 && ! ( V_4 -> V_31 == V_135 ) &&
! ( V_26 -> V_31 == V_56 ) )
F_47 ( V_7 , V_4 , L_63
L_65
L_24
L_64 ,
( unsigned long long ) V_26 -> V_18 , V_4 -> V_25 ,
V_44 [ V_4 -> V_31 ] ,
V_44 [ V_26 -> V_31 ] ) ;
if ( ! V_132 && ! ( V_4 -> V_31 == V_56 ) &&
! ( V_26 -> V_31 == V_135 ) )
F_47 ( V_7 , V_4 , L_63
L_66
L_24
L_64 ,
( unsigned long long ) V_26 -> V_18 , V_4 -> V_25 ,
V_44 [ V_4 -> V_31 ] ,
V_44 [ V_26 -> V_31 ] ) ;
if ( V_26 -> V_32 && V_26 -> type == V_119 &&
V_26 -> V_32 != V_4 -> V_32 ) {
F_47 ( V_26 -> V_7 , V_4 , L_63
L_46
L_67 ,
V_4 -> V_32 , V_26 -> V_32 ) ;
}
V_133:
F_12 ( V_22 , & V_10 ) ;
}
void F_99 ( struct V_6 * V_7 , struct V_59 * V_59 , T_6 V_38 ,
T_6 V_25 , int V_31 , T_9 V_136 ,
bool V_137 )
{
struct V_3 * V_4 ;
if ( F_100 ( F_1 () ) )
return;
if ( F_94 ( V_7 , V_136 ) )
return;
V_4 = F_52 () ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_7 ;
V_4 -> type = V_138 ;
V_4 -> V_37 = F_45 ( V_59 ) ;
V_4 -> V_38 = V_38 ,
V_4 -> V_18 = V_136 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_46 = V_120 ;
if ( V_137 )
V_4 -> type = V_139 ;
if ( ! F_101 ( V_59 ) ) {
void * V_121 = F_102 ( V_59 ) + V_38 ;
F_95 ( V_7 , V_121 ) ;
F_97 ( V_7 , V_121 , V_25 ) ;
}
F_48 ( V_4 ) ;
}
void F_103 ( struct V_6 * V_7 , T_9 V_136 )
{
struct V_3 V_26 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
if ( F_100 ( F_1 () ) )
return;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_136 ;
V_22 = F_11 ( & V_26 , & V_10 ) ;
F_16 (entry, &bucket->list, list) {
if ( ! F_13 ( & V_26 , V_4 ) )
continue;
if ( V_4 -> V_46 == V_120 ) {
V_4 -> V_46 = V_140 ;
break;
}
}
F_12 ( V_22 , & V_10 ) ;
}
void F_104 ( struct V_6 * V_7 , T_9 V_121 ,
T_6 V_25 , int V_31 , bool V_137 )
{
struct V_3 V_26 = {
. type = V_138 ,
. V_7 = V_7 ,
. V_18 = V_121 ,
. V_25 = V_25 ,
. V_31 = V_31 ,
} ;
if ( F_100 ( F_1 () ) )
return;
if ( V_137 )
V_26 . type = V_139 ;
F_93 ( & V_26 ) ;
}
void F_105 ( struct V_6 * V_7 , struct V_141 * V_142 ,
int V_63 , int V_143 , int V_31 )
{
struct V_3 * V_4 ;
struct V_141 * V_144 ;
int V_51 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sg, s, mapped_ents, i) {
V_4 = F_52 () ;
if ( ! V_4 )
return;
V_4 -> type = V_119 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_37 = F_45 ( F_107 ( V_144 ) ) ;
V_4 -> V_38 = V_144 -> V_38 ,
V_4 -> V_25 = F_108 ( V_144 ) ;
V_4 -> V_18 = F_109 ( V_144 ) ;
V_4 -> V_31 = V_31 ;
V_4 -> V_32 = V_63 ;
V_4 -> V_145 = V_143 ;
if ( ! F_101 ( F_107 ( V_144 ) ) ) {
F_95 ( V_7 , F_110 ( V_144 ) ) ;
F_97 ( V_7 , F_110 ( V_144 ) , F_108 ( V_144 ) ) ;
}
F_48 ( V_4 ) ;
}
}
static int F_111 ( struct V_6 * V_7 ,
struct V_3 * V_26 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
int V_143 ;
V_22 = F_11 ( V_26 , & V_10 ) ;
V_4 = F_17 ( V_22 , V_26 ) ;
V_143 = 0 ;
if ( V_4 )
V_143 = V_4 -> V_145 ;
F_12 ( V_22 , & V_10 ) ;
return V_143 ;
}
void F_112 ( struct V_6 * V_7 , struct V_141 * V_146 ,
int V_147 , int V_148 )
{
struct V_141 * V_144 ;
int V_143 = 0 , V_51 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sglist, s, nelems, i) {
struct V_3 V_26 = {
. type = V_119 ,
. V_7 = V_7 ,
. V_37 = F_45 ( F_107 ( V_144 ) ) ,
. V_38 = V_144 -> V_38 ,
. V_18 = F_109 ( V_144 ) ,
. V_25 = F_108 ( V_144 ) ,
. V_31 = V_148 ,
. V_32 = V_147 ,
} ;
if ( V_143 && V_51 >= V_143 )
break;
if ( ! V_51 )
V_143 = F_111 ( V_7 , & V_26 ) ;
F_93 ( & V_26 ) ;
}
}
void F_113 ( struct V_6 * V_7 , T_6 V_25 ,
T_9 V_136 , void * V_149 )
{
struct V_3 * V_4 ;
if ( F_100 ( F_1 () ) )
return;
if ( F_100 ( V_149 == NULL ) )
return;
V_4 = F_52 () ;
if ( ! V_4 )
return;
V_4 -> type = V_118 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_37 = F_45 ( F_114 ( V_149 ) ) ;
V_4 -> V_38 = ( T_6 ) V_149 & ~ V_150 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_18 = V_136 ;
V_4 -> V_31 = V_134 ;
F_48 ( V_4 ) ;
}
void F_115 ( struct V_6 * V_7 , T_6 V_25 ,
void * V_149 , T_9 V_121 )
{
struct V_3 V_26 = {
. type = V_118 ,
. V_7 = V_7 ,
. V_37 = F_45 ( F_114 ( V_149 ) ) ,
. V_38 = ( T_6 ) V_149 & ~ V_150 ,
. V_18 = V_121 ,
. V_25 = V_25 ,
. V_31 = V_134 ,
} ;
if ( F_100 ( F_1 () ) )
return;
F_93 ( & V_26 ) ;
}
void F_116 ( struct V_6 * V_7 , T_9 V_151 ,
T_6 V_25 , int V_31 )
{
struct V_3 V_26 ;
if ( F_100 ( F_1 () ) )
return;
V_26 . type = V_139 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_151 ;
V_26 . V_25 = V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_98 ( V_7 , & V_26 , true ) ;
}
void F_117 ( struct V_6 * V_7 ,
T_9 V_151 , T_6 V_25 ,
int V_31 )
{
struct V_3 V_26 ;
if ( F_100 ( F_1 () ) )
return;
V_26 . type = V_139 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_151 ;
V_26 . V_25 = V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_98 ( V_7 , & V_26 , false ) ;
}
void F_118 ( struct V_6 * V_7 ,
T_9 V_151 ,
unsigned long V_38 , T_6 V_25 ,
int V_31 )
{
struct V_3 V_26 ;
if ( F_100 ( F_1 () ) )
return;
V_26 . type = V_139 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_151 ;
V_26 . V_25 = V_38 + V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_98 ( V_7 , & V_26 , true ) ;
}
void F_119 ( struct V_6 * V_7 ,
T_9 V_151 ,
unsigned long V_38 ,
T_6 V_25 , int V_31 )
{
struct V_3 V_26 ;
if ( F_100 ( F_1 () ) )
return;
V_26 . type = V_139 ;
V_26 . V_7 = V_7 ;
V_26 . V_18 = V_151 ;
V_26 . V_25 = V_38 + V_25 ;
V_26 . V_31 = V_31 ;
V_26 . V_32 = 0 ;
F_98 ( V_7 , & V_26 , false ) ;
}
void F_120 ( struct V_6 * V_7 , struct V_141 * V_142 ,
int V_147 , int V_31 )
{
struct V_141 * V_144 ;
int V_143 = 0 , V_51 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sg, s, nelems, i) {
struct V_3 V_26 = {
. type = V_119 ,
. V_7 = V_7 ,
. V_37 = F_45 ( F_107 ( V_144 ) ) ,
. V_38 = V_144 -> V_38 ,
. V_18 = F_109 ( V_144 ) ,
. V_25 = F_108 ( V_144 ) ,
. V_31 = V_31 ,
. V_32 = V_147 ,
} ;
if ( ! V_51 )
V_143 = F_111 ( V_7 , & V_26 ) ;
if ( V_51 >= V_143 )
break;
F_98 ( V_7 , & V_26 , true ) ;
}
}
void F_121 ( struct V_6 * V_7 , struct V_141 * V_142 ,
int V_147 , int V_31 )
{
struct V_141 * V_144 ;
int V_143 = 0 , V_51 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sg, s, nelems, i) {
struct V_3 V_26 = {
. type = V_119 ,
. V_7 = V_7 ,
. V_37 = F_45 ( F_107 ( V_144 ) ) ,
. V_38 = V_144 -> V_38 ,
. V_18 = F_109 ( V_144 ) ,
. V_25 = F_108 ( V_144 ) ,
. V_31 = V_31 ,
. V_32 = V_147 ,
} ;
if ( ! V_51 )
V_143 = F_111 ( V_7 , & V_26 ) ;
if ( V_51 >= V_143 )
break;
F_98 ( V_7 , & V_26 , false ) ;
}
}
static int T_8 F_122 ( char * V_115 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_17 - 1 ; ++ V_51 , ++ V_115 ) {
V_12 [ V_51 ] = * V_115 ;
if ( * V_115 == 0 )
break;
}
if ( V_12 [ 0 ] )
F_63 ( L_10 ,
V_12 ) ;
return 1 ;
}
