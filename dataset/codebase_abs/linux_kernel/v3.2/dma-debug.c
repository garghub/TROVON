static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 ) {
F_3 ( L_1 ) ;
F_4 ( & V_2 -> V_3 , 0 ) ;
}
#endif
}
static bool F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
bool V_9 ;
if ( F_6 ( ! V_10 [ 0 ] ) )
return true ;
if ( V_11 && V_5 && V_5 -> V_12 == V_11 )
return true ;
if ( ! V_5 )
return false ;
if ( V_11 || ! V_10 [ 0 ] )
return false ;
V_7 = F_7 ( V_5 -> V_12 ) ;
if ( ! V_7 )
return false ;
F_8 ( & V_13 , V_8 ) ;
V_9 = false ;
if ( V_7 -> V_14 &&
strncmp ( V_10 , V_7 -> V_14 , V_15 - 1 ) == 0 ) {
V_11 = V_7 ;
V_9 = true ;
}
F_9 ( & V_13 , V_8 ) ;
F_10 ( V_7 ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return ( V_2 -> V_16 >> V_17 ) & V_18 ;
}
static struct V_19 * F_12 ( struct V_1 * V_2 ,
unsigned long * V_8 )
{
int V_20 = F_11 ( V_2 ) ;
unsigned long V_21 ;
F_13 ( & V_22 [ V_20 ] . V_23 , V_21 ) ;
* V_8 = V_21 ;
return & V_22 [ V_20 ] ;
}
static void F_14 ( struct V_19 * V_24 ,
unsigned long * V_8 )
{
unsigned long V_21 = * V_8 ;
F_15 ( & V_24 -> V_23 , V_21 ) ;
}
static bool F_16 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
return ( ( V_25 -> V_16 == V_26 -> V_16 ) &&
( V_25 -> V_5 == V_26 -> V_5 ) ) ? true : false ;
}
static bool F_17 ( struct V_1 * V_25 ,
struct V_1 * V_26 )
{
if ( V_25 -> V_5 != V_26 -> V_5 )
return false ;
if ( ( V_26 -> V_16 <= V_25 -> V_16 ) &&
( ( V_26 -> V_16 + V_26 -> V_27 ) >= ( V_25 -> V_16 + V_25 -> V_27 ) ) )
return true ;
return false ;
}
static struct V_1 * F_18 ( struct V_19 * V_24 ,
struct V_1 * V_28 ,
T_1 V_29 )
{
struct V_1 * V_2 , * V_9 = NULL ;
int V_30 = 0 , V_31 , V_32 = 0 ;
F_19 (entry, &bucket->list, list) {
if ( ! V_29 ( V_28 , V_2 ) )
continue;
V_30 += 1 ;
V_31 = 0 ;
V_2 -> V_27 == V_28 -> V_27 ? ++ V_31 : 0 ;
V_2 -> type == V_28 -> type ? ++ V_31 : 0 ;
V_2 -> V_33 == V_28 -> V_33 ? ++ V_31 : 0 ;
V_2 -> V_34 == V_28 -> V_34 ? ++ V_31 : 0 ;
if ( V_31 == 4 ) {
return V_2 ;
} else if ( V_31 > V_32 ) {
V_32 = V_31 ;
V_9 = V_2 ;
}
}
V_9 = ( V_30 == 1 ) ? V_9 : NULL ;
return V_9 ;
}
static struct V_1 * F_20 ( struct V_19 * V_24 ,
struct V_1 * V_28 )
{
return F_18 ( V_24 , V_28 , F_16 ) ;
}
static struct V_1 * F_21 ( struct V_19 * * V_24 ,
struct V_1 * V_28 ,
unsigned long * V_8 )
{
unsigned int V_35 = F_22 ( V_28 -> V_5 ) ;
struct V_1 * V_2 , V_36 = * V_28 ;
unsigned int V_37 = 0 ;
while ( V_37 <= V_35 ) {
V_2 = F_18 ( * V_24 , & V_36 , F_17 ) ;
if ( V_2 )
return V_2 ;
F_14 ( * V_24 , V_8 ) ;
V_37 += ( 1 << V_17 ) ;
V_36 . V_16 -= ( 1 << V_17 ) ;
* V_24 = F_12 ( & V_36 , V_8 ) ;
}
return NULL ;
}
static void F_23 ( struct V_19 * V_24 ,
struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_38 , & V_24 -> V_38 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_38 ) ;
}
void F_27 ( struct V_4 * V_5 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_39 ; V_20 ++ ) {
struct V_19 * V_24 = & V_22 [ V_20 ] ;
struct V_1 * V_2 ;
unsigned long V_8 ;
F_13 ( & V_24 -> V_23 , V_8 ) ;
F_19 (entry, &bucket->list, list) {
if ( ! V_5 || V_5 == V_2 -> V_5 ) {
F_28 ( V_2 -> V_5 ,
L_2 ,
V_40 [ V_2 -> type ] , V_20 ,
( unsigned long long ) V_2 -> V_41 ,
V_2 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ) ;
}
}
F_15 ( & V_24 -> V_23 , V_8 ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_12 ( V_2 , & V_8 ) ;
F_23 ( V_24 , V_2 ) ;
F_14 ( V_24 , & V_8 ) ;
}
static struct V_1 * F_30 ( void )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_43 . V_44 , struct V_1 , V_38 ) ;
F_26 ( & V_2 -> V_38 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_45 -= 1 ;
if ( V_45 < V_46 )
V_46 = V_45 ;
return V_2 ;
}
static struct V_1 * F_32 ( void )
{
struct V_1 * V_2 = NULL ;
unsigned long V_8 ;
F_13 ( & V_47 , V_8 ) ;
if ( F_33 ( & V_43 ) ) {
F_34 ( L_3 ) ;
V_48 = true ;
goto V_49;
}
V_2 = F_30 () ;
#ifdef F_2
V_2 -> V_3 . V_50 = V_51 ;
V_2 -> V_3 . V_52 = V_2 -> V_53 ;
V_2 -> V_3 . V_54 = 2 ;
F_35 ( & V_2 -> V_3 ) ;
#endif
V_49:
F_15 ( & V_47 , V_8 ) ;
return V_2 ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
F_13 ( & V_47 , V_8 ) ;
F_37 ( & V_2 -> V_38 , & V_43 ) ;
V_45 += 1 ;
F_15 ( & V_47 , V_8 ) ;
}
int F_38 ( T_2 V_55 )
{
int V_56 , V_57 , V_9 = 0 ;
unsigned long V_8 ;
struct V_1 * V_2 ;
F_39 ( V_58 ) ;
F_13 ( & V_47 , V_8 ) ;
if ( V_59 < V_55 ) {
V_57 = V_55 - V_59 ;
F_15 ( & V_47 , V_8 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_2 = F_40 ( sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
break;
F_24 ( & V_2 -> V_38 , & V_58 ) ;
}
F_13 ( & V_47 , V_8 ) ;
F_41 ( & V_58 , & V_43 ) ;
V_59 += V_56 ;
V_45 += V_56 ;
} else {
V_57 = V_59 - V_55 ;
for ( V_56 = 0 ; V_56 < V_57 && ! F_33 ( & V_43 ) ; V_56 ++ ) {
V_2 = F_30 () ;
F_42 ( V_2 ) ;
}
V_59 -= V_56 ;
}
if ( V_59 != V_55 )
V_9 = 1 ;
F_15 ( & V_47 , V_8 ) ;
return V_9 ;
}
static int F_43 ( T_2 V_55 )
{
struct V_1 * V_2 , * V_61 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_55 ; ++ V_56 ) {
V_2 = F_40 ( sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
goto V_62;
F_24 ( & V_2 -> V_38 , & V_43 ) ;
}
V_45 = V_55 ;
V_46 = V_55 ;
F_44 ( L_4 , V_55 ) ;
return 0 ;
V_62:
F_45 (entry, next_entry, &free_entries, list) {
F_26 ( & V_2 -> V_38 ) ;
F_42 ( V_2 ) ;
}
return - V_63 ;
}
static T_3 F_46 ( struct V_64 * V_64 , char T_4 * V_65 ,
T_5 V_66 , T_6 * V_67 )
{
char V_68 [ V_15 + 1 ] ;
unsigned long V_8 ;
int V_69 ;
if ( ! V_10 [ 0 ] )
return 0 ;
F_8 ( & V_13 , V_8 ) ;
V_69 = F_47 ( V_68 , V_15 + 1 , L_5 , V_10 ) ;
F_9 ( & V_13 , V_8 ) ;
return F_48 ( V_65 , V_66 , V_67 , V_68 , V_69 ) ;
}
static T_3 F_49 ( struct V_64 * V_64 , const char T_4 * V_70 ,
T_5 V_66 , T_6 * V_67 )
{
char V_68 [ V_15 ] ;
unsigned long V_8 ;
T_5 V_69 ;
int V_56 ;
V_69 = F_50 ( V_66 , ( T_5 ) ( V_15 - 1 ) ) ;
if ( F_51 ( V_68 , V_70 , V_69 ) )
return - V_71 ;
V_68 [ V_69 ] = 0 ;
F_52 ( & V_13 , V_8 ) ;
if ( ! isalnum ( V_68 [ 0 ] ) ) {
if ( V_10 [ 0 ] )
F_44 ( L_6 ) ;
V_10 [ 0 ] = 0 ;
V_11 = NULL ;
goto V_72;
}
for ( V_56 = 0 ; V_56 < V_15 - 1 ; ++ V_56 ) {
V_10 [ V_56 ] = V_68 [ V_56 ] ;
if ( isspace ( V_68 [ V_56 ] ) || V_68 [ V_56 ] == ' ' || V_68 [ V_56 ] == 0 )
break;
}
V_10 [ V_56 ] = 0 ;
V_11 = NULL ;
F_44 ( L_7 ,
V_10 ) ;
V_72:
F_53 ( & V_13 , V_8 ) ;
return V_66 ;
}
static int F_54 ( void )
{
V_73 = F_55 ( L_8 , NULL ) ;
if ( ! V_73 ) {
F_34 ( L_9 ) ;
return - V_63 ;
}
V_74 = F_56 ( L_10 , 0444 ,
V_73 ,
( T_2 * ) & V_48 ) ;
if ( ! V_74 )
goto V_62;
V_75 = F_57 ( L_11 , 0444 ,
V_73 , & V_76 ) ;
if ( ! V_75 )
goto V_62;
V_77 = F_57 ( L_12 , 0644 ,
V_73 ,
& V_78 ) ;
if ( ! V_77 )
goto V_62;
V_79 = F_57 ( L_13 , 0644 ,
V_73 ,
& V_80 ) ;
if ( ! V_79 )
goto V_62;
V_81 = F_57 ( L_14 , 0444 ,
V_73 ,
& V_45 ) ;
if ( ! V_81 )
goto V_62;
V_82 = F_57 ( L_15 , 0444 ,
V_73 ,
& V_46 ) ;
if ( ! V_82 )
goto V_62;
V_83 = F_58 ( L_16 , 0644 ,
V_73 , NULL , & V_84 ) ;
if ( ! V_83 )
goto V_62;
return 0 ;
V_62:
F_59 ( V_73 ) ;
return - V_63 ;
}
static int F_60 ( struct V_4 * V_5 , struct V_1 * * V_85 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
int V_66 = 0 , V_56 ;
F_61 ( V_8 ) ;
for ( V_56 = 0 ; V_56 < V_39 ; ++ V_56 ) {
F_62 ( & V_22 [ V_56 ] . V_23 ) ;
F_19 (entry, &dma_entry_hash[i].list, list) {
if ( V_2 -> V_5 == V_5 ) {
V_66 += 1 ;
* V_85 = V_2 ;
}
}
F_63 ( & V_22 [ V_56 ] . V_23 ) ;
}
F_64 ( V_8 ) ;
return V_66 ;
}
static int F_65 ( struct V_86 * V_87 , unsigned long V_88 , void * V_89 )
{
struct V_4 * V_5 = V_89 ;
struct V_1 * V_90 ( V_2 ) ;
int V_66 ;
if ( V_48 )
return 0 ;
switch ( V_88 ) {
case V_91 :
V_66 = F_60 ( V_5 , & V_2 ) ;
if ( V_66 == 0 )
break;
F_66 ( V_5 , V_2 , L_17
L_18
L_19
L_20
L_21
L_22 ,
V_66 , V_2 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] , V_40 [ V_2 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_67 ( struct V_92 * V_93 )
{
struct V_86 * V_87 ;
if ( V_48 )
return;
V_87 = F_40 ( sizeof( struct V_86 ) , V_60 ) ;
if ( V_87 == NULL ) {
F_34 ( L_23 ) ;
return;
}
V_87 -> V_94 = F_65 ;
F_68 ( V_93 , V_87 ) ;
}
void F_69 ( T_2 V_55 )
{
int V_56 ;
if ( V_48 )
return;
for ( V_56 = 0 ; V_56 < V_39 ; ++ V_56 ) {
F_70 ( & V_22 [ V_56 ] . V_38 ) ;
F_71 ( & V_22 [ V_56 ] . V_23 ) ;
}
if ( F_54 () != 0 ) {
F_34 ( L_24 ) ;
V_48 = true ;
return;
}
if ( V_95 )
V_55 = V_95 ;
if ( F_43 ( V_55 ) != 0 ) {
F_34 ( L_25 ) ;
V_48 = true ;
return;
}
V_59 = V_45 ;
F_44 ( L_26 ) ;
}
static T_7 int F_72 ( char * V_96 )
{
if ( ! V_96 )
return - V_97 ;
if ( strncmp ( V_96 , L_27 , 3 ) == 0 ) {
F_44 ( L_28 ) ;
V_48 = true ;
}
return 0 ;
}
static T_7 int F_73 ( char * V_96 )
{
int V_98 ;
if ( ! V_96 )
return - V_97 ;
V_98 = F_74 ( & V_96 , & V_95 ) ;
if ( ! V_98 )
V_95 = 0 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
if ( F_76 ( V_28 -> V_5 , V_28 -> V_16 ) ) {
F_66 ( V_28 -> V_5 , NULL , L_29
L_30 ) ;
return;
}
V_24 = F_12 ( V_28 , & V_8 ) ;
V_2 = F_20 ( V_24 , V_28 ) ;
if ( ! V_2 ) {
F_66 ( V_28 -> V_5 , NULL , L_29
L_31
L_32 ,
V_28 -> V_16 , V_28 -> V_27 ) ;
goto V_49;
}
if ( V_28 -> V_27 != V_2 -> V_27 ) {
F_66 ( V_28 -> V_5 , V_2 , L_33
L_34
L_35
L_36 ,
V_28 -> V_16 , V_2 -> V_27 , V_28 -> V_27 ) ;
}
if ( V_28 -> type != V_2 -> type ) {
F_66 ( V_28 -> V_5 , V_2 , L_33
L_37
L_21
L_38 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_40 [ V_2 -> type ] , V_40 [ V_28 -> type ] ) ;
} else if ( ( V_2 -> type == V_99 ) &&
( V_28 -> V_41 != V_2 -> V_41 ) ) {
F_66 ( V_28 -> V_5 , V_2 , L_33
L_39
L_21
L_40
L_41 ,
V_28 -> V_16 , V_28 -> V_27 ,
( unsigned long long ) V_2 -> V_41 ,
( unsigned long long ) V_28 -> V_41 ) ;
}
if ( V_28 -> V_34 && V_28 -> type == V_100 &&
V_28 -> V_34 != V_2 -> V_34 ) {
F_66 ( V_28 -> V_5 , V_2 , L_33
L_42
L_43 ,
V_2 -> V_34 , V_28 -> V_34 ) ;
}
if ( V_28 -> V_33 != V_2 -> V_33 ) {
F_66 ( V_28 -> V_5 , V_2 , L_33
L_44
L_21
L_45 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
}
F_25 ( V_2 ) ;
F_36 ( V_2 ) ;
V_49:
F_14 ( V_24 , & V_8 ) ;
}
static void F_77 ( struct V_4 * V_5 , void * V_101 )
{
if ( F_78 ( V_101 ) )
F_66 ( V_5 , NULL , L_46
L_47 , V_101 ) ;
}
static inline bool F_79 ( void * V_101 , unsigned long V_69 , void * V_102 , void * V_103 )
{
unsigned long V_104 = ( unsigned long ) V_101 ;
unsigned long V_105 = V_104 + V_69 ;
unsigned long V_106 = ( unsigned long ) V_102 ;
unsigned long V_107 = ( unsigned long ) V_103 ;
return ! ( V_105 <= V_106 || V_104 >= V_107 ) ;
}
static void F_80 ( struct V_4 * V_5 , void * V_101 , unsigned long V_69 )
{
if ( F_79 ( V_101 , V_69 , V_108 , V_109 ) ||
F_79 ( V_101 , V_69 , V_110 , V_111 ) )
F_66 ( V_5 , NULL , L_48 , V_101 , V_69 ) ;
}
static void F_81 ( struct V_4 * V_5 ,
struct V_1 * V_28 ,
bool V_112 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_12 ( V_28 , & V_8 ) ;
V_2 = F_21 ( & V_24 , V_28 , & V_8 ) ;
if ( ! V_2 ) {
F_66 ( V_5 , NULL , L_29
L_49
L_32 ,
( unsigned long long ) V_28 -> V_16 , V_28 -> V_27 ) ;
goto V_49;
}
if ( V_28 -> V_27 > V_2 -> V_27 ) {
F_66 ( V_5 , V_2 , L_50
L_51
L_52
L_53
L_54 ,
V_2 -> V_16 , V_2 -> V_27 ,
V_28 -> V_27 ) ;
}
if ( V_2 -> V_33 == V_113 )
goto V_49;
if ( V_28 -> V_33 != V_2 -> V_33 ) {
F_66 ( V_5 , V_2 , L_55
L_44
L_21
L_56 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
}
if ( V_112 && ! ( V_2 -> V_33 == V_114 ) &&
! ( V_28 -> V_33 == V_115 ) )
F_66 ( V_5 , V_2 , L_55
L_57
L_21
L_56 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
if ( ! V_112 && ! ( V_2 -> V_33 == V_115 ) &&
! ( V_28 -> V_33 == V_114 ) )
F_66 ( V_5 , V_2 , L_55
L_58
L_21
L_56 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
V_49:
F_14 ( V_24 , & V_8 ) ;
}
void F_82 ( struct V_4 * V_5 , struct V_116 * V_116 , T_5 V_117 ,
T_5 V_27 , int V_33 , T_8 V_118 ,
bool V_119 )
{
struct V_1 * V_2 ;
if ( F_83 ( V_48 ) )
return;
if ( F_83 ( F_76 ( V_5 , V_118 ) ) )
return;
V_2 = F_32 () ;
if ( ! V_2 )
return;
V_2 -> V_5 = V_5 ;
V_2 -> type = V_120 ;
V_2 -> V_41 = F_84 ( V_116 ) + V_117 ;
V_2 -> V_16 = V_118 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_33 = V_33 ;
if ( V_119 )
V_2 -> type = V_121 ;
if ( ! F_85 ( V_116 ) ) {
void * V_101 = F_86 ( V_116 ) + V_117 ;
F_77 ( V_5 , V_101 ) ;
F_80 ( V_5 , V_101 , V_27 ) ;
}
F_29 ( V_2 ) ;
}
void F_87 ( struct V_4 * V_5 , T_8 V_101 ,
T_5 V_27 , int V_33 , bool V_119 )
{
struct V_1 V_28 = {
. type = V_120 ,
. V_5 = V_5 ,
. V_16 = V_101 ,
. V_27 = V_27 ,
. V_33 = V_33 ,
} ;
if ( F_83 ( V_48 ) )
return;
if ( V_119 )
V_28 . type = V_121 ;
F_75 ( & V_28 ) ;
}
void F_88 ( struct V_4 * V_5 , struct V_122 * V_123 ,
int V_124 , int V_125 , int V_33 )
{
struct V_1 * V_2 ;
struct V_122 * V_126 ;
int V_56 ;
if ( F_83 ( V_48 ) )
return;
F_89 (sg, s, mapped_ents, i) {
V_2 = F_32 () ;
if ( ! V_2 )
return;
V_2 -> type = V_100 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_41 = F_90 ( V_126 ) ;
V_2 -> V_27 = F_91 ( V_126 ) ;
V_2 -> V_16 = F_92 ( V_126 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_34 = V_124 ;
V_2 -> V_127 = V_125 ;
if ( ! F_85 ( F_93 ( V_126 ) ) ) {
F_77 ( V_5 , F_94 ( V_126 ) ) ;
F_80 ( V_5 , F_94 ( V_126 ) , F_91 ( V_126 ) ) ;
}
F_29 ( V_2 ) ;
}
}
static int F_95 ( struct V_4 * V_5 ,
struct V_1 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
int V_125 ;
V_24 = F_12 ( V_28 , & V_8 ) ;
V_2 = F_20 ( V_24 , V_28 ) ;
V_125 = 0 ;
if ( V_2 )
V_125 = V_2 -> V_127 ;
F_14 ( V_24 , & V_8 ) ;
return V_125 ;
}
void F_96 ( struct V_4 * V_5 , struct V_122 * V_128 ,
int V_129 , int V_130 )
{
struct V_122 * V_126 ;
int V_125 = 0 , V_56 ;
if ( F_83 ( V_48 ) )
return;
F_89 (sglist, s, nelems, i) {
struct V_1 V_28 = {
. type = V_100 ,
. V_5 = V_5 ,
. V_41 = F_90 ( V_126 ) ,
. V_16 = F_92 ( V_126 ) ,
. V_27 = F_91 ( V_126 ) ,
. V_33 = V_130 ,
. V_34 = V_129 ,
} ;
if ( V_125 && V_56 >= V_125 )
break;
if ( ! V_56 )
V_125 = F_95 ( V_5 , & V_28 ) ;
F_75 ( & V_28 ) ;
}
}
void F_97 ( struct V_4 * V_5 , T_5 V_27 ,
T_8 V_118 , void * V_131 )
{
struct V_1 * V_2 ;
if ( F_83 ( V_48 ) )
return;
if ( F_83 ( V_131 == NULL ) )
return;
V_2 = F_32 () ;
if ( ! V_2 )
return;
V_2 -> type = V_99 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_41 = F_98 ( V_131 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_16 = V_118 ;
V_2 -> V_33 = V_113 ;
F_29 ( V_2 ) ;
}
void F_99 ( struct V_4 * V_5 , T_5 V_27 ,
void * V_131 , T_8 V_101 )
{
struct V_1 V_28 = {
. type = V_99 ,
. V_5 = V_5 ,
. V_41 = F_98 ( V_131 ) ,
. V_16 = V_101 ,
. V_27 = V_27 ,
. V_33 = V_113 ,
} ;
if ( F_83 ( V_48 ) )
return;
F_75 ( & V_28 ) ;
}
void F_100 ( struct V_4 * V_5 , T_8 V_132 ,
T_5 V_27 , int V_33 )
{
struct V_1 V_28 ;
if ( F_83 ( V_48 ) )
return;
V_28 . type = V_121 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_132 ;
V_28 . V_27 = V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_81 ( V_5 , & V_28 , true ) ;
}
void F_101 ( struct V_4 * V_5 ,
T_8 V_132 , T_5 V_27 ,
int V_33 )
{
struct V_1 V_28 ;
if ( F_83 ( V_48 ) )
return;
V_28 . type = V_121 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_132 ;
V_28 . V_27 = V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_81 ( V_5 , & V_28 , false ) ;
}
void F_102 ( struct V_4 * V_5 ,
T_8 V_132 ,
unsigned long V_117 , T_5 V_27 ,
int V_33 )
{
struct V_1 V_28 ;
if ( F_83 ( V_48 ) )
return;
V_28 . type = V_121 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_132 ;
V_28 . V_27 = V_117 + V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_81 ( V_5 , & V_28 , true ) ;
}
void F_103 ( struct V_4 * V_5 ,
T_8 V_132 ,
unsigned long V_117 ,
T_5 V_27 , int V_33 )
{
struct V_1 V_28 ;
if ( F_83 ( V_48 ) )
return;
V_28 . type = V_121 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_132 ;
V_28 . V_27 = V_117 + V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_81 ( V_5 , & V_28 , false ) ;
}
void F_104 ( struct V_4 * V_5 , struct V_122 * V_123 ,
int V_129 , int V_33 )
{
struct V_122 * V_126 ;
int V_125 = 0 , V_56 ;
if ( F_83 ( V_48 ) )
return;
F_89 (sg, s, nelems, i) {
struct V_1 V_28 = {
. type = V_100 ,
. V_5 = V_5 ,
. V_41 = F_90 ( V_126 ) ,
. V_16 = F_92 ( V_126 ) ,
. V_27 = F_91 ( V_126 ) ,
. V_33 = V_33 ,
. V_34 = V_129 ,
} ;
if ( ! V_56 )
V_125 = F_95 ( V_5 , & V_28 ) ;
if ( V_56 >= V_125 )
break;
F_81 ( V_5 , & V_28 , true ) ;
}
}
void F_105 ( struct V_4 * V_5 , struct V_122 * V_123 ,
int V_129 , int V_33 )
{
struct V_122 * V_126 ;
int V_125 = 0 , V_56 ;
if ( F_83 ( V_48 ) )
return;
F_89 (sg, s, nelems, i) {
struct V_1 V_28 = {
. type = V_100 ,
. V_5 = V_5 ,
. V_41 = F_90 ( V_126 ) ,
. V_16 = F_92 ( V_126 ) ,
. V_27 = F_91 ( V_126 ) ,
. V_33 = V_33 ,
. V_34 = V_129 ,
} ;
if ( ! V_56 )
V_125 = F_95 ( V_5 , & V_28 ) ;
if ( V_56 >= V_125 )
break;
F_81 ( V_5 , & V_28 , false ) ;
}
}
static int T_7 F_106 ( char * V_96 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_15 - 1 ; ++ V_56 , ++ V_96 ) {
V_10 [ V_56 ] = * V_96 ;
if ( * V_96 == 0 )
break;
}
if ( V_10 [ 0 ] )
F_44 ( L_7 ,
V_10 ) ;
return 1 ;
}
