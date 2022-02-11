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
static struct V_1 * F_16 ( struct V_19 * V_24 ,
struct V_1 * V_25 )
{
struct V_1 * V_2 , * V_9 = NULL ;
int V_26 = 0 , V_27 , V_28 = 0 ;
F_17 (entry, &bucket->list, list) {
if ( ( V_2 -> V_16 != V_25 -> V_16 ) ||
( V_2 -> V_5 != V_25 -> V_5 ) )
continue;
V_26 += 1 ;
V_27 = 0 ;
V_2 -> V_29 == V_25 -> V_29 ? ++ V_27 : 0 ;
V_2 -> type == V_25 -> type ? ++ V_27 : 0 ;
V_2 -> V_30 == V_25 -> V_30 ? ++ V_27 : 0 ;
V_2 -> V_31 == V_25 -> V_31 ? ++ V_27 : 0 ;
if ( V_27 == 4 ) {
return V_2 ;
} else if ( V_27 > V_28 ) {
V_28 = V_27 ;
V_9 = V_2 ;
}
}
V_9 = ( V_26 == 1 ) ? V_9 : NULL ;
return V_9 ;
}
static void F_18 ( struct V_19 * V_24 ,
struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_32 , & V_24 -> V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_32 ) ;
}
void F_22 ( struct V_4 * V_5 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_33 ; V_20 ++ ) {
struct V_19 * V_24 = & V_22 [ V_20 ] ;
struct V_1 * V_2 ;
unsigned long V_8 ;
F_13 ( & V_24 -> V_23 , V_8 ) ;
F_17 (entry, &bucket->list, list) {
if ( ! V_5 || V_5 == V_2 -> V_5 ) {
F_23 ( V_2 -> V_5 ,
L_2 ,
V_34 [ V_2 -> type ] , V_20 ,
( unsigned long long ) V_2 -> V_35 ,
V_2 -> V_16 , V_2 -> V_29 ,
V_36 [ V_2 -> V_30 ] ) ;
}
}
F_15 ( & V_24 -> V_23 , V_8 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_12 ( V_2 , & V_8 ) ;
F_18 ( V_24 , V_2 ) ;
F_14 ( V_24 , & V_8 ) ;
}
static struct V_1 * F_25 ( void )
{
struct V_1 * V_2 ;
V_2 = F_26 ( V_37 . V_38 , struct V_1 , V_32 ) ;
F_21 ( & V_2 -> V_32 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_39 -= 1 ;
if ( V_39 < V_40 )
V_40 = V_39 ;
return V_2 ;
}
static struct V_1 * F_27 ( void )
{
struct V_1 * V_2 = NULL ;
unsigned long V_8 ;
F_13 ( & V_41 , V_8 ) ;
if ( F_28 ( & V_37 ) ) {
F_29 ( L_3 ) ;
V_42 = true ;
goto V_43;
}
V_2 = F_25 () ;
#ifdef F_2
V_2 -> V_3 . V_44 = V_45 ;
V_2 -> V_3 . V_46 = V_2 -> V_47 ;
V_2 -> V_3 . V_48 = 2 ;
F_30 ( & V_2 -> V_3 ) ;
#endif
V_43:
F_15 ( & V_41 , V_8 ) ;
return V_2 ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
F_13 ( & V_41 , V_8 ) ;
F_32 ( & V_2 -> V_32 , & V_37 ) ;
V_39 += 1 ;
F_15 ( & V_41 , V_8 ) ;
}
int F_33 ( T_1 V_49 )
{
int V_50 , V_51 , V_9 = 0 ;
unsigned long V_8 ;
struct V_1 * V_2 ;
F_34 ( V_52 ) ;
F_13 ( & V_41 , V_8 ) ;
if ( V_53 < V_49 ) {
V_51 = V_49 - V_53 ;
F_15 ( & V_41 , V_8 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_2 = F_35 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
break;
F_19 ( & V_2 -> V_32 , & V_52 ) ;
}
F_13 ( & V_41 , V_8 ) ;
F_36 ( & V_52 , & V_37 ) ;
V_53 += V_50 ;
V_39 += V_50 ;
} else {
V_51 = V_53 - V_49 ;
for ( V_50 = 0 ; V_50 < V_51 && ! F_28 ( & V_37 ) ; V_50 ++ ) {
V_2 = F_25 () ;
F_37 ( V_2 ) ;
}
V_53 -= V_50 ;
}
if ( V_53 != V_49 )
V_9 = 1 ;
F_15 ( & V_41 , V_8 ) ;
return V_9 ;
}
static int F_38 ( T_1 V_49 )
{
struct V_1 * V_2 , * V_55 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_49 ; ++ V_50 ) {
V_2 = F_35 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
goto V_56;
F_19 ( & V_2 -> V_32 , & V_37 ) ;
}
V_39 = V_49 ;
V_40 = V_49 ;
F_39 ( L_4 , V_49 ) ;
return 0 ;
V_56:
F_40 (entry, next_entry, &free_entries, list) {
F_21 ( & V_2 -> V_32 ) ;
F_37 ( V_2 ) ;
}
return - V_57 ;
}
static T_2 F_41 ( struct V_58 * V_58 , char T_3 * V_59 ,
T_4 V_60 , T_5 * V_61 )
{
char V_62 [ V_15 + 1 ] ;
unsigned long V_8 ;
int V_63 ;
if ( ! V_10 [ 0 ] )
return 0 ;
F_8 ( & V_13 , V_8 ) ;
V_63 = F_42 ( V_62 , V_15 + 1 , L_5 , V_10 ) ;
F_9 ( & V_13 , V_8 ) ;
return F_43 ( V_59 , V_60 , V_61 , V_62 , V_63 ) ;
}
static T_2 F_44 ( struct V_58 * V_58 , const char T_3 * V_64 ,
T_4 V_60 , T_5 * V_61 )
{
char V_62 [ V_15 ] ;
unsigned long V_8 ;
T_4 V_63 ;
int V_50 ;
V_63 = F_45 ( V_60 , ( T_4 ) ( V_15 - 1 ) ) ;
if ( F_46 ( V_62 , V_64 , V_63 ) )
return - V_65 ;
V_62 [ V_63 ] = 0 ;
F_47 ( & V_13 , V_8 ) ;
if ( ! isalnum ( V_62 [ 0 ] ) ) {
if ( V_10 [ 0 ] )
F_39 ( L_6 ) ;
V_10 [ 0 ] = 0 ;
V_11 = NULL ;
goto V_66;
}
for ( V_50 = 0 ; V_50 < V_15 - 1 ; ++ V_50 ) {
V_10 [ V_50 ] = V_62 [ V_50 ] ;
if ( isspace ( V_62 [ V_50 ] ) || V_62 [ V_50 ] == ' ' || V_62 [ V_50 ] == 0 )
break;
}
V_10 [ V_50 ] = 0 ;
V_11 = NULL ;
F_39 ( L_7 ,
V_10 ) ;
V_66:
F_48 ( & V_13 , V_8 ) ;
return V_60 ;
}
static int F_49 ( void )
{
V_67 = F_50 ( L_8 , NULL ) ;
if ( ! V_67 ) {
F_29 ( L_9 ) ;
return - V_57 ;
}
V_68 = F_51 ( L_10 , 0444 ,
V_67 ,
( T_1 * ) & V_42 ) ;
if ( ! V_68 )
goto V_56;
V_69 = F_52 ( L_11 , 0444 ,
V_67 , & V_70 ) ;
if ( ! V_69 )
goto V_56;
V_71 = F_52 ( L_12 , 0644 ,
V_67 ,
& V_72 ) ;
if ( ! V_71 )
goto V_56;
V_73 = F_52 ( L_13 , 0644 ,
V_67 ,
& V_74 ) ;
if ( ! V_73 )
goto V_56;
V_75 = F_52 ( L_14 , 0444 ,
V_67 ,
& V_39 ) ;
if ( ! V_75 )
goto V_56;
V_76 = F_52 ( L_15 , 0444 ,
V_67 ,
& V_40 ) ;
if ( ! V_76 )
goto V_56;
V_77 = F_53 ( L_16 , 0644 ,
V_67 , NULL , & V_78 ) ;
if ( ! V_77 )
goto V_56;
return 0 ;
V_56:
F_54 ( V_67 ) ;
return - V_57 ;
}
static int F_55 ( struct V_4 * V_5 , struct V_1 * * V_79 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
int V_60 = 0 , V_50 ;
F_56 ( V_8 ) ;
for ( V_50 = 0 ; V_50 < V_33 ; ++ V_50 ) {
F_57 ( & V_22 [ V_50 ] . V_23 ) ;
F_17 (entry, &dma_entry_hash[i].list, list) {
if ( V_2 -> V_5 == V_5 ) {
V_60 += 1 ;
* V_79 = V_2 ;
}
}
F_58 ( & V_22 [ V_50 ] . V_23 ) ;
}
F_59 ( V_8 ) ;
return V_60 ;
}
static int F_60 ( struct V_80 * V_81 , unsigned long V_82 , void * V_83 )
{
struct V_4 * V_5 = V_83 ;
struct V_1 * V_84 ( V_2 ) ;
int V_60 ;
if ( V_42 )
return 0 ;
switch ( V_82 ) {
case V_85 :
V_60 = F_55 ( V_5 , & V_2 ) ;
if ( V_60 == 0 )
break;
F_61 ( V_5 , V_2 , L_17
L_18
L_19
L_20
L_21
L_22 ,
V_60 , V_2 -> V_16 , V_2 -> V_29 ,
V_36 [ V_2 -> V_30 ] , V_34 [ V_2 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_62 ( struct V_86 * V_87 )
{
struct V_80 * V_81 ;
if ( V_42 )
return;
V_81 = F_35 ( sizeof( struct V_80 ) , V_54 ) ;
if ( V_81 == NULL ) {
F_29 ( L_23 ) ;
return;
}
V_81 -> V_88 = F_60 ;
F_63 ( V_87 , V_81 ) ;
}
void F_64 ( T_1 V_49 )
{
int V_50 ;
if ( V_42 )
return;
for ( V_50 = 0 ; V_50 < V_33 ; ++ V_50 ) {
F_65 ( & V_22 [ V_50 ] . V_32 ) ;
F_66 ( & V_22 [ V_50 ] . V_23 ) ;
}
if ( F_49 () != 0 ) {
F_29 ( L_24 ) ;
V_42 = true ;
return;
}
if ( V_89 )
V_49 = V_89 ;
if ( F_38 ( V_49 ) != 0 ) {
F_29 ( L_25 ) ;
V_42 = true ;
return;
}
V_53 = V_39 ;
F_39 ( L_26 ) ;
}
static T_6 int F_67 ( char * V_90 )
{
if ( ! V_90 )
return - V_91 ;
if ( strncmp ( V_90 , L_27 , 3 ) == 0 ) {
F_39 ( L_28 ) ;
V_42 = true ;
}
return 0 ;
}
static T_6 int F_68 ( char * V_90 )
{
int V_92 ;
if ( ! V_90 )
return - V_91 ;
V_92 = F_69 ( & V_90 , & V_89 ) ;
if ( ! V_92 )
V_89 = 0 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_25 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
if ( F_71 ( V_25 -> V_5 , V_25 -> V_16 ) ) {
F_61 ( V_25 -> V_5 , NULL , L_29
L_30 ) ;
return;
}
V_24 = F_12 ( V_25 , & V_8 ) ;
V_2 = F_16 ( V_24 , V_25 ) ;
if ( ! V_2 ) {
F_61 ( V_25 -> V_5 , NULL , L_29
L_31
L_32 ,
V_25 -> V_16 , V_25 -> V_29 ) ;
goto V_43;
}
if ( V_25 -> V_29 != V_2 -> V_29 ) {
F_61 ( V_25 -> V_5 , V_2 , L_33
L_34
L_35
L_36 ,
V_25 -> V_16 , V_2 -> V_29 , V_25 -> V_29 ) ;
}
if ( V_25 -> type != V_2 -> type ) {
F_61 ( V_25 -> V_5 , V_2 , L_33
L_37
L_21
L_38 ,
V_25 -> V_16 , V_25 -> V_29 ,
V_34 [ V_2 -> type ] , V_34 [ V_25 -> type ] ) ;
} else if ( ( V_2 -> type == V_93 ) &&
( V_25 -> V_35 != V_2 -> V_35 ) ) {
F_61 ( V_25 -> V_5 , V_2 , L_33
L_39
L_21
L_40
L_41 ,
V_25 -> V_16 , V_25 -> V_29 ,
( unsigned long long ) V_2 -> V_35 ,
( unsigned long long ) V_25 -> V_35 ) ;
}
if ( V_25 -> V_31 && V_25 -> type == V_94 &&
V_25 -> V_31 != V_2 -> V_31 ) {
F_61 ( V_25 -> V_5 , V_2 , L_33
L_42
L_43 ,
V_2 -> V_31 , V_25 -> V_31 ) ;
}
if ( V_25 -> V_30 != V_2 -> V_30 ) {
F_61 ( V_25 -> V_5 , V_2 , L_33
L_44
L_21
L_45 ,
V_25 -> V_16 , V_25 -> V_29 ,
V_36 [ V_2 -> V_30 ] ,
V_36 [ V_25 -> V_30 ] ) ;
}
F_20 ( V_2 ) ;
F_31 ( V_2 ) ;
V_43:
F_14 ( V_24 , & V_8 ) ;
}
static void F_72 ( struct V_4 * V_5 , void * V_95 )
{
if ( F_73 ( V_95 ) )
F_61 ( V_5 , NULL , L_46
L_47 , V_95 ) ;
}
static inline bool F_74 ( void * V_95 , unsigned long V_63 , void * V_96 , void * V_97 )
{
unsigned long V_98 = ( unsigned long ) V_95 ;
unsigned long V_99 = V_98 + V_63 ;
unsigned long V_100 = ( unsigned long ) V_96 ;
unsigned long V_101 = ( unsigned long ) V_97 ;
return ! ( V_99 <= V_100 || V_98 >= V_101 ) ;
}
static void F_75 ( struct V_4 * V_5 , void * V_95 , unsigned long V_63 )
{
if ( F_74 ( V_95 , V_63 , V_102 , V_103 ) ||
F_74 ( V_95 , V_63 , V_104 , V_105 ) )
F_61 ( V_5 , NULL , L_48 , V_95 , V_63 ) ;
}
static void F_76 ( struct V_4 * V_5 ,
struct V_1 * V_25 ,
bool V_106 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_12 ( V_25 , & V_8 ) ;
V_2 = F_16 ( V_24 , V_25 ) ;
if ( ! V_2 ) {
F_61 ( V_5 , NULL , L_29
L_49
L_32 ,
( unsigned long long ) V_25 -> V_16 , V_25 -> V_29 ) ;
goto V_43;
}
if ( V_25 -> V_29 > V_2 -> V_29 ) {
F_61 ( V_5 , V_2 , L_50
L_51
L_52
L_53
L_54 ,
V_2 -> V_16 , V_2 -> V_29 ,
V_25 -> V_29 ) ;
}
if ( V_2 -> V_30 == V_107 )
goto V_43;
if ( V_25 -> V_30 != V_2 -> V_30 ) {
F_61 ( V_5 , V_2 , L_55
L_44
L_21
L_56 ,
( unsigned long long ) V_25 -> V_16 , V_2 -> V_29 ,
V_36 [ V_2 -> V_30 ] ,
V_36 [ V_25 -> V_30 ] ) ;
}
if ( V_106 && ! ( V_2 -> V_30 == V_108 ) &&
! ( V_25 -> V_30 == V_109 ) )
F_61 ( V_5 , V_2 , L_55
L_57
L_21
L_56 ,
( unsigned long long ) V_25 -> V_16 , V_2 -> V_29 ,
V_36 [ V_2 -> V_30 ] ,
V_36 [ V_25 -> V_30 ] ) ;
if ( ! V_106 && ! ( V_2 -> V_30 == V_109 ) &&
! ( V_25 -> V_30 == V_108 ) )
F_61 ( V_5 , V_2 , L_55
L_58
L_21
L_56 ,
( unsigned long long ) V_25 -> V_16 , V_2 -> V_29 ,
V_36 [ V_2 -> V_30 ] ,
V_36 [ V_25 -> V_30 ] ) ;
V_43:
F_14 ( V_24 , & V_8 ) ;
}
void F_77 ( struct V_4 * V_5 , struct V_110 * V_110 , T_4 V_111 ,
T_4 V_29 , int V_30 , T_7 V_112 ,
bool V_113 )
{
struct V_1 * V_2 ;
if ( F_78 ( V_42 ) )
return;
if ( F_78 ( F_71 ( V_5 , V_112 ) ) )
return;
V_2 = F_27 () ;
if ( ! V_2 )
return;
V_2 -> V_5 = V_5 ;
V_2 -> type = V_114 ;
V_2 -> V_35 = F_79 ( V_110 ) + V_111 ;
V_2 -> V_16 = V_112 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_30 = V_30 ;
if ( V_113 )
V_2 -> type = V_115 ;
if ( ! F_80 ( V_110 ) ) {
void * V_95 = F_81 ( V_110 ) + V_111 ;
F_72 ( V_5 , V_95 ) ;
F_75 ( V_5 , V_95 , V_29 ) ;
}
F_24 ( V_2 ) ;
}
void F_82 ( struct V_4 * V_5 , T_7 V_95 ,
T_4 V_29 , int V_30 , bool V_113 )
{
struct V_1 V_25 = {
. type = V_114 ,
. V_5 = V_5 ,
. V_16 = V_95 ,
. V_29 = V_29 ,
. V_30 = V_30 ,
} ;
if ( F_78 ( V_42 ) )
return;
if ( V_113 )
V_25 . type = V_115 ;
F_70 ( & V_25 ) ;
}
void F_83 ( struct V_4 * V_5 , struct V_116 * V_117 ,
int V_118 , int V_119 , int V_30 )
{
struct V_1 * V_2 ;
struct V_116 * V_120 ;
int V_50 ;
if ( F_78 ( V_42 ) )
return;
F_84 (sg, s, mapped_ents, i) {
V_2 = F_27 () ;
if ( ! V_2 )
return;
V_2 -> type = V_94 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_35 = F_85 ( V_120 ) ;
V_2 -> V_29 = F_86 ( V_120 ) ;
V_2 -> V_16 = F_87 ( V_120 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_31 = V_118 ;
V_2 -> V_121 = V_119 ;
if ( ! F_80 ( F_88 ( V_120 ) ) ) {
F_72 ( V_5 , F_89 ( V_120 ) ) ;
F_75 ( V_5 , F_89 ( V_120 ) , F_86 ( V_120 ) ) ;
}
F_24 ( V_2 ) ;
}
}
static int F_90 ( struct V_4 * V_5 ,
struct V_1 * V_25 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
int V_119 ;
V_24 = F_12 ( V_25 , & V_8 ) ;
V_2 = F_16 ( V_24 , V_25 ) ;
V_119 = 0 ;
if ( V_2 )
V_119 = V_2 -> V_121 ;
F_14 ( V_24 , & V_8 ) ;
return V_119 ;
}
void F_91 ( struct V_4 * V_5 , struct V_116 * V_122 ,
int V_123 , int V_124 )
{
struct V_116 * V_120 ;
int V_119 = 0 , V_50 ;
if ( F_78 ( V_42 ) )
return;
F_84 (sglist, s, nelems, i) {
struct V_1 V_25 = {
. type = V_94 ,
. V_5 = V_5 ,
. V_35 = F_85 ( V_120 ) ,
. V_16 = F_87 ( V_120 ) ,
. V_29 = F_86 ( V_120 ) ,
. V_30 = V_124 ,
. V_31 = V_123 ,
} ;
if ( V_119 && V_50 >= V_119 )
break;
if ( ! V_50 )
V_119 = F_90 ( V_5 , & V_25 ) ;
F_70 ( & V_25 ) ;
}
}
void F_92 ( struct V_4 * V_5 , T_4 V_29 ,
T_7 V_112 , void * V_125 )
{
struct V_1 * V_2 ;
if ( F_78 ( V_42 ) )
return;
if ( F_78 ( V_125 == NULL ) )
return;
V_2 = F_27 () ;
if ( ! V_2 )
return;
V_2 -> type = V_93 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_35 = F_93 ( V_125 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_16 = V_112 ;
V_2 -> V_30 = V_107 ;
F_24 ( V_2 ) ;
}
void F_94 ( struct V_4 * V_5 , T_4 V_29 ,
void * V_125 , T_7 V_95 )
{
struct V_1 V_25 = {
. type = V_93 ,
. V_5 = V_5 ,
. V_35 = F_93 ( V_125 ) ,
. V_16 = V_95 ,
. V_29 = V_29 ,
. V_30 = V_107 ,
} ;
if ( F_78 ( V_42 ) )
return;
F_70 ( & V_25 ) ;
}
void F_95 ( struct V_4 * V_5 , T_7 V_126 ,
T_4 V_29 , int V_30 )
{
struct V_1 V_25 ;
if ( F_78 ( V_42 ) )
return;
V_25 . type = V_115 ;
V_25 . V_5 = V_5 ;
V_25 . V_16 = V_126 ;
V_25 . V_29 = V_29 ;
V_25 . V_30 = V_30 ;
V_25 . V_31 = 0 ;
F_76 ( V_5 , & V_25 , true ) ;
}
void F_96 ( struct V_4 * V_5 ,
T_7 V_126 , T_4 V_29 ,
int V_30 )
{
struct V_1 V_25 ;
if ( F_78 ( V_42 ) )
return;
V_25 . type = V_115 ;
V_25 . V_5 = V_5 ;
V_25 . V_16 = V_126 ;
V_25 . V_29 = V_29 ;
V_25 . V_30 = V_30 ;
V_25 . V_31 = 0 ;
F_76 ( V_5 , & V_25 , false ) ;
}
void F_97 ( struct V_4 * V_5 ,
T_7 V_126 ,
unsigned long V_111 , T_4 V_29 ,
int V_30 )
{
struct V_1 V_25 ;
if ( F_78 ( V_42 ) )
return;
V_25 . type = V_115 ;
V_25 . V_5 = V_5 ;
V_25 . V_16 = V_126 ;
V_25 . V_29 = V_111 + V_29 ;
V_25 . V_30 = V_30 ;
V_25 . V_31 = 0 ;
F_76 ( V_5 , & V_25 , true ) ;
}
void F_98 ( struct V_4 * V_5 ,
T_7 V_126 ,
unsigned long V_111 ,
T_4 V_29 , int V_30 )
{
struct V_1 V_25 ;
if ( F_78 ( V_42 ) )
return;
V_25 . type = V_115 ;
V_25 . V_5 = V_5 ;
V_25 . V_16 = V_126 ;
V_25 . V_29 = V_111 + V_29 ;
V_25 . V_30 = V_30 ;
V_25 . V_31 = 0 ;
F_76 ( V_5 , & V_25 , false ) ;
}
void F_99 ( struct V_4 * V_5 , struct V_116 * V_117 ,
int V_123 , int V_30 )
{
struct V_116 * V_120 ;
int V_119 = 0 , V_50 ;
if ( F_78 ( V_42 ) )
return;
F_84 (sg, s, nelems, i) {
struct V_1 V_25 = {
. type = V_94 ,
. V_5 = V_5 ,
. V_35 = F_85 ( V_120 ) ,
. V_16 = F_87 ( V_120 ) ,
. V_29 = F_86 ( V_120 ) ,
. V_30 = V_30 ,
. V_31 = V_123 ,
} ;
if ( ! V_50 )
V_119 = F_90 ( V_5 , & V_25 ) ;
if ( V_50 >= V_119 )
break;
F_76 ( V_5 , & V_25 , true ) ;
}
}
void F_100 ( struct V_4 * V_5 , struct V_116 * V_117 ,
int V_123 , int V_30 )
{
struct V_116 * V_120 ;
int V_119 = 0 , V_50 ;
if ( F_78 ( V_42 ) )
return;
F_84 (sg, s, nelems, i) {
struct V_1 V_25 = {
. type = V_94 ,
. V_5 = V_5 ,
. V_35 = F_85 ( V_120 ) ,
. V_16 = F_87 ( V_120 ) ,
. V_29 = F_86 ( V_120 ) ,
. V_30 = V_30 ,
. V_31 = V_123 ,
} ;
if ( ! V_50 )
V_119 = F_90 ( V_5 , & V_25 ) ;
if ( V_50 >= V_119 )
break;
F_76 ( V_5 , & V_25 , false ) ;
}
}
static int T_6 F_101 ( char * V_90 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_15 - 1 ; ++ V_50 , ++ V_90 ) {
V_10 [ V_50 ] = * V_90 ;
if ( * V_90 == 0 )
break;
}
if ( V_10 [ 0 ] )
F_39 ( L_7 ,
V_10 ) ;
return 1 ;
}
