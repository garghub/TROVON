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
V_7 = V_5 -> V_12 ;
if ( ! V_7 )
return false ;
F_7 ( & V_13 , V_8 ) ;
V_9 = false ;
if ( V_7 -> V_14 &&
strncmp ( V_10 , V_7 -> V_14 , V_15 - 1 ) == 0 ) {
V_11 = V_7 ;
V_9 = true ;
}
F_8 ( & V_13 , V_8 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return ( V_2 -> V_16 >> V_17 ) & V_18 ;
}
static struct V_19 * F_10 ( struct V_1 * V_2 ,
unsigned long * V_8 )
{
int V_20 = F_9 ( V_2 ) ;
unsigned long V_21 ;
F_11 ( & V_22 [ V_20 ] . V_23 , V_21 ) ;
* V_8 = V_21 ;
return & V_22 [ V_20 ] ;
}
static void F_12 ( struct V_19 * V_24 ,
unsigned long * V_8 )
{
unsigned long V_21 = * V_8 ;
F_13 ( & V_24 -> V_23 , V_21 ) ;
}
static bool F_14 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
return ( ( V_25 -> V_16 == V_26 -> V_16 ) &&
( V_25 -> V_5 == V_26 -> V_5 ) ) ? true : false ;
}
static bool F_15 ( struct V_1 * V_25 ,
struct V_1 * V_26 )
{
if ( V_25 -> V_5 != V_26 -> V_5 )
return false ;
if ( ( V_26 -> V_16 <= V_25 -> V_16 ) &&
( ( V_26 -> V_16 + V_26 -> V_27 ) >= ( V_25 -> V_16 + V_25 -> V_27 ) ) )
return true ;
return false ;
}
static struct V_1 * F_16 ( struct V_19 * V_24 ,
struct V_1 * V_28 ,
T_1 V_29 )
{
struct V_1 * V_2 , * V_9 = NULL ;
int V_30 = 0 , V_31 , V_32 = - 1 ;
F_17 (entry, &bucket->list, list) {
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
static struct V_1 * F_18 ( struct V_19 * V_24 ,
struct V_1 * V_28 )
{
return F_16 ( V_24 , V_28 , F_14 ) ;
}
static struct V_1 * F_19 ( struct V_19 * * V_24 ,
struct V_1 * V_28 ,
unsigned long * V_8 )
{
unsigned int V_35 = F_20 ( V_28 -> V_5 ) ;
struct V_1 * V_2 , V_36 = * V_28 ;
unsigned int V_37 = 0 ;
while ( V_37 <= V_35 ) {
V_2 = F_16 ( * V_24 , & V_36 , F_15 ) ;
if ( V_2 )
return V_2 ;
F_12 ( * V_24 , V_8 ) ;
V_37 += ( 1 << V_17 ) ;
V_36 . V_16 -= ( 1 << V_17 ) ;
* V_24 = F_10 ( & V_36 , V_8 ) ;
}
return NULL ;
}
static void F_21 ( struct V_19 * V_24 ,
struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_38 , & V_24 -> V_38 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_38 ) ;
}
void F_25 ( struct V_4 * V_5 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_39 ; V_20 ++ ) {
struct V_19 * V_24 = & V_22 [ V_20 ] ;
struct V_1 * V_2 ;
unsigned long V_8 ;
F_11 ( & V_24 -> V_23 , V_8 ) ;
F_17 (entry, &bucket->list, list) {
if ( ! V_5 || V_5 == V_2 -> V_5 ) {
F_26 ( V_2 -> V_5 ,
L_2 ,
V_40 [ V_2 -> type ] , V_20 ,
( unsigned long long ) V_2 -> V_41 ,
V_2 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_43 [ V_2 -> V_44 ] ) ;
}
}
F_13 ( & V_24 -> V_23 , V_8 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_10 ( V_2 , & V_8 ) ;
F_21 ( V_24 , V_2 ) ;
F_12 ( V_24 , & V_8 ) ;
}
static struct V_1 * F_28 ( void )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_45 . V_46 , struct V_1 , V_38 ) ;
F_24 ( & V_2 -> V_38 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_47 -= 1 ;
if ( V_47 < V_48 )
V_48 = V_47 ;
return V_2 ;
}
static struct V_1 * F_30 ( void )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
F_11 ( & V_49 , V_8 ) ;
if ( F_31 ( & V_45 ) ) {
F_32 ( L_3 ) ;
V_50 = true ;
F_13 ( & V_49 , V_8 ) ;
return NULL ;
}
V_2 = F_28 () ;
F_13 ( & V_49 , V_8 ) ;
#ifdef F_2
V_2 -> V_3 . V_51 = V_52 ;
V_2 -> V_3 . V_53 = V_2 -> V_54 ;
V_2 -> V_3 . V_55 = 2 ;
F_33 ( & V_2 -> V_3 ) ;
#endif
return V_2 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
F_11 ( & V_49 , V_8 ) ;
F_35 ( & V_2 -> V_38 , & V_45 ) ;
V_47 += 1 ;
F_13 ( & V_49 , V_8 ) ;
}
int F_36 ( T_2 V_56 )
{
int V_57 , V_58 , V_9 = 0 ;
unsigned long V_8 ;
struct V_1 * V_2 ;
F_37 ( V_59 ) ;
F_11 ( & V_49 , V_8 ) ;
if ( V_60 < V_56 ) {
V_58 = V_56 - V_60 ;
F_13 ( & V_49 , V_8 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_2 = F_38 ( sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
break;
F_22 ( & V_2 -> V_38 , & V_59 ) ;
}
F_11 ( & V_49 , V_8 ) ;
F_39 ( & V_59 , & V_45 ) ;
V_60 += V_57 ;
V_47 += V_57 ;
} else {
V_58 = V_60 - V_56 ;
for ( V_57 = 0 ; V_57 < V_58 && ! F_31 ( & V_45 ) ; V_57 ++ ) {
V_2 = F_28 () ;
F_40 ( V_2 ) ;
}
V_60 -= V_57 ;
}
if ( V_60 != V_56 )
V_9 = 1 ;
F_13 ( & V_49 , V_8 ) ;
return V_9 ;
}
static int F_41 ( T_2 V_56 )
{
struct V_1 * V_2 , * V_62 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_56 ; ++ V_57 ) {
V_2 = F_38 ( sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
goto V_63;
F_22 ( & V_2 -> V_38 , & V_45 ) ;
}
V_47 = V_56 ;
V_48 = V_56 ;
F_42 ( L_4 , V_56 ) ;
return 0 ;
V_63:
F_43 (entry, next_entry, &free_entries, list) {
F_24 ( & V_2 -> V_38 ) ;
F_40 ( V_2 ) ;
}
return - V_64 ;
}
static T_3 F_44 ( struct V_65 * V_65 , char T_4 * V_66 ,
T_5 V_67 , T_6 * V_68 )
{
char V_69 [ V_15 + 1 ] ;
unsigned long V_8 ;
int V_70 ;
if ( ! V_10 [ 0 ] )
return 0 ;
F_7 ( & V_13 , V_8 ) ;
V_70 = F_45 ( V_69 , V_15 + 1 , L_5 , V_10 ) ;
F_8 ( & V_13 , V_8 ) ;
return F_46 ( V_66 , V_67 , V_68 , V_69 , V_70 ) ;
}
static T_3 F_47 ( struct V_65 * V_65 , const char T_4 * V_71 ,
T_5 V_67 , T_6 * V_68 )
{
char V_69 [ V_15 ] ;
unsigned long V_8 ;
T_5 V_70 ;
int V_57 ;
V_70 = F_48 ( V_67 , ( T_5 ) ( V_15 - 1 ) ) ;
if ( F_49 ( V_69 , V_71 , V_70 ) )
return - V_72 ;
V_69 [ V_70 ] = 0 ;
F_50 ( & V_13 , V_8 ) ;
if ( ! isalnum ( V_69 [ 0 ] ) ) {
if ( V_10 [ 0 ] )
F_42 ( L_6 ) ;
V_10 [ 0 ] = 0 ;
V_11 = NULL ;
goto V_73;
}
for ( V_57 = 0 ; V_57 < V_15 - 1 ; ++ V_57 ) {
V_10 [ V_57 ] = V_69 [ V_57 ] ;
if ( isspace ( V_69 [ V_57 ] ) || V_69 [ V_57 ] == ' ' || V_69 [ V_57 ] == 0 )
break;
}
V_10 [ V_57 ] = 0 ;
V_11 = NULL ;
F_42 ( L_7 ,
V_10 ) ;
V_73:
F_51 ( & V_13 , V_8 ) ;
return V_67 ;
}
static int F_52 ( void )
{
V_74 = F_53 ( L_8 , NULL ) ;
if ( ! V_74 ) {
F_32 ( L_9 ) ;
return - V_64 ;
}
V_75 = F_54 ( L_10 , 0444 ,
V_74 ,
& V_50 ) ;
if ( ! V_75 )
goto V_63;
V_76 = F_55 ( L_11 , 0444 ,
V_74 , & V_77 ) ;
if ( ! V_76 )
goto V_63;
V_78 = F_55 ( L_12 , 0644 ,
V_74 ,
& V_79 ) ;
if ( ! V_78 )
goto V_63;
V_80 = F_55 ( L_13 , 0644 ,
V_74 ,
& V_81 ) ;
if ( ! V_80 )
goto V_63;
V_82 = F_55 ( L_14 , 0444 ,
V_74 ,
& V_47 ) ;
if ( ! V_82 )
goto V_63;
V_83 = F_55 ( L_15 , 0444 ,
V_74 ,
& V_48 ) ;
if ( ! V_83 )
goto V_63;
V_84 = F_56 ( L_16 , 0644 ,
V_74 , NULL , & V_85 ) ;
if ( ! V_84 )
goto V_63;
return 0 ;
V_63:
F_57 ( V_74 ) ;
return - V_64 ;
}
static int F_58 ( struct V_4 * V_5 , struct V_1 * * V_86 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
int V_67 = 0 , V_57 ;
F_59 ( V_8 ) ;
for ( V_57 = 0 ; V_57 < V_39 ; ++ V_57 ) {
F_60 ( & V_22 [ V_57 ] . V_23 ) ;
F_17 (entry, &dma_entry_hash[i].list, list) {
if ( V_2 -> V_5 == V_5 ) {
V_67 += 1 ;
* V_86 = V_2 ;
}
}
F_61 ( & V_22 [ V_57 ] . V_23 ) ;
}
F_62 ( V_8 ) ;
return V_67 ;
}
static int F_63 ( struct V_87 * V_88 , unsigned long V_89 , void * V_90 )
{
struct V_4 * V_5 = V_90 ;
struct V_1 * V_91 ( V_2 ) ;
int V_67 ;
if ( V_50 )
return 0 ;
switch ( V_89 ) {
case V_92 :
V_67 = F_58 ( V_5 , & V_2 ) ;
if ( V_67 == 0 )
break;
F_64 ( V_5 , V_2 , L_17
L_18
L_19
L_20
L_21
L_22 ,
V_67 , V_2 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] , V_40 [ V_2 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_65 ( struct V_93 * V_94 )
{
struct V_87 * V_88 ;
if ( V_50 )
return;
V_88 = F_38 ( sizeof( struct V_87 ) , V_61 ) ;
if ( V_88 == NULL ) {
F_32 ( L_23 ) ;
return;
}
V_88 -> V_95 = F_63 ;
F_66 ( V_94 , V_88 ) ;
}
void F_67 ( T_2 V_56 )
{
int V_57 ;
if ( V_50 )
return;
for ( V_57 = 0 ; V_57 < V_39 ; ++ V_57 ) {
F_68 ( & V_22 [ V_57 ] . V_38 ) ;
F_69 ( & V_22 [ V_57 ] . V_23 ) ;
}
if ( F_52 () != 0 ) {
F_32 ( L_24 ) ;
V_50 = true ;
return;
}
if ( V_96 )
V_56 = V_96 ;
if ( F_41 ( V_56 ) != 0 ) {
F_32 ( L_25 ) ;
V_50 = true ;
return;
}
V_60 = V_47 ;
F_42 ( L_26 ) ;
}
static T_7 int F_70 ( char * V_97 )
{
if ( ! V_97 )
return - V_98 ;
if ( strncmp ( V_97 , L_27 , 3 ) == 0 ) {
F_42 ( L_28 ) ;
V_50 = true ;
}
return 0 ;
}
static T_7 int F_71 ( char * V_97 )
{
int V_99 ;
if ( ! V_97 )
return - V_98 ;
V_99 = F_72 ( & V_97 , & V_96 ) ;
if ( ! V_99 )
V_96 = 0 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_10 ( V_28 , & V_8 ) ;
V_2 = F_18 ( V_24 , V_28 ) ;
if ( ! V_2 ) {
if ( F_74 ( V_28 -> V_5 , V_28 -> V_16 ) ) {
F_64 ( V_28 -> V_5 , NULL ,
L_29
L_30 ) ;
return;
}
F_64 ( V_28 -> V_5 , NULL , L_29
L_31
L_32 ,
V_28 -> V_16 , V_28 -> V_27 ) ;
goto V_100;
}
if ( V_28 -> V_27 != V_2 -> V_27 ) {
F_64 ( V_28 -> V_5 , V_2 , L_33
L_34
L_35
L_36 ,
V_28 -> V_16 , V_2 -> V_27 , V_28 -> V_27 ) ;
}
if ( V_28 -> type != V_2 -> type ) {
F_64 ( V_28 -> V_5 , V_2 , L_33
L_37
L_21
L_38 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_40 [ V_2 -> type ] , V_40 [ V_28 -> type ] ) ;
} else if ( ( V_2 -> type == V_101 ) &&
( V_28 -> V_41 != V_2 -> V_41 ) ) {
F_64 ( V_28 -> V_5 , V_2 , L_33
L_39
L_21
L_40
L_41 ,
V_28 -> V_16 , V_28 -> V_27 ,
( unsigned long long ) V_2 -> V_41 ,
( unsigned long long ) V_28 -> V_41 ) ;
}
if ( V_28 -> V_34 && V_28 -> type == V_102 &&
V_28 -> V_34 != V_2 -> V_34 ) {
F_64 ( V_28 -> V_5 , V_2 , L_33
L_42
L_43 ,
V_2 -> V_34 , V_28 -> V_34 ) ;
}
if ( V_28 -> V_33 != V_2 -> V_33 ) {
F_64 ( V_28 -> V_5 , V_2 , L_33
L_44
L_21
L_45 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
}
if ( V_2 -> V_44 == V_103 ) {
F_64 ( V_28 -> V_5 , V_2 ,
L_46
L_21
L_47 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_40 [ V_2 -> type ] ) ;
}
F_23 ( V_2 ) ;
F_34 ( V_2 ) ;
V_100:
F_12 ( V_24 , & V_8 ) ;
}
static void F_75 ( struct V_4 * V_5 , void * V_104 )
{
if ( F_76 ( V_104 ) )
F_64 ( V_5 , NULL , L_48
L_49 , V_104 ) ;
}
static inline bool F_77 ( void * V_104 , unsigned long V_70 , void * V_105 , void * V_106 )
{
unsigned long V_107 = ( unsigned long ) V_104 ;
unsigned long V_108 = V_107 + V_70 ;
unsigned long V_109 = ( unsigned long ) V_105 ;
unsigned long V_110 = ( unsigned long ) V_106 ;
return ! ( V_108 <= V_109 || V_107 >= V_110 ) ;
}
static void F_78 ( struct V_4 * V_5 , void * V_104 , unsigned long V_70 )
{
if ( F_77 ( V_104 , V_70 , V_111 , V_112 ) ||
F_77 ( V_104 , V_70 , V_113 , V_114 ) )
F_64 ( V_5 , NULL , L_50 , V_104 , V_70 ) ;
}
static void F_79 ( struct V_4 * V_5 ,
struct V_1 * V_28 ,
bool V_115 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_10 ( V_28 , & V_8 ) ;
V_2 = F_19 ( & V_24 , V_28 , & V_8 ) ;
if ( ! V_2 ) {
F_64 ( V_5 , NULL , L_29
L_51
L_32 ,
( unsigned long long ) V_28 -> V_16 , V_28 -> V_27 ) ;
goto V_100;
}
if ( V_28 -> V_27 > V_2 -> V_27 ) {
F_64 ( V_5 , V_2 , L_52
L_53
L_54
L_55
L_56 ,
V_2 -> V_16 , V_2 -> V_27 ,
V_28 -> V_27 ) ;
}
if ( V_2 -> V_33 == V_116 )
goto V_100;
if ( V_28 -> V_33 != V_2 -> V_33 ) {
F_64 ( V_5 , V_2 , L_57
L_44
L_21
L_58 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
}
if ( V_115 && ! ( V_2 -> V_33 == V_117 ) &&
! ( V_28 -> V_33 == V_118 ) )
F_64 ( V_5 , V_2 , L_57
L_59
L_21
L_58 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
if ( ! V_115 && ! ( V_2 -> V_33 == V_118 ) &&
! ( V_28 -> V_33 == V_117 ) )
F_64 ( V_5 , V_2 , L_57
L_60
L_21
L_58 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_42 [ V_2 -> V_33 ] ,
V_42 [ V_28 -> V_33 ] ) ;
V_100:
F_12 ( V_24 , & V_8 ) ;
}
void F_80 ( struct V_4 * V_5 , struct V_119 * V_119 , T_5 V_120 ,
T_5 V_27 , int V_33 , T_8 V_121 ,
bool V_122 )
{
struct V_1 * V_2 ;
if ( F_81 ( V_50 ) )
return;
if ( F_74 ( V_5 , V_121 ) )
return;
V_2 = F_30 () ;
if ( ! V_2 )
return;
V_2 -> V_5 = V_5 ;
V_2 -> type = V_123 ;
V_2 -> V_41 = F_82 ( V_119 ) + V_120 ;
V_2 -> V_16 = V_121 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_44 = V_103 ;
if ( V_122 )
V_2 -> type = V_124 ;
if ( ! F_83 ( V_119 ) ) {
void * V_104 = F_84 ( V_119 ) + V_120 ;
F_75 ( V_5 , V_104 ) ;
F_78 ( V_5 , V_104 , V_27 ) ;
}
F_27 ( V_2 ) ;
}
void F_85 ( struct V_4 * V_5 , T_8 V_121 )
{
struct V_1 V_28 ;
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
if ( F_81 ( V_50 ) )
return;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_121 ;
V_24 = F_10 ( & V_28 , & V_8 ) ;
V_2 = F_18 ( V_24 , & V_28 ) ;
if ( ! V_2 )
goto V_100;
V_2 -> V_44 = V_125 ;
V_100:
F_12 ( V_24 , & V_8 ) ;
}
void F_86 ( struct V_4 * V_5 , T_8 V_104 ,
T_5 V_27 , int V_33 , bool V_122 )
{
struct V_1 V_28 = {
. type = V_123 ,
. V_5 = V_5 ,
. V_16 = V_104 ,
. V_27 = V_27 ,
. V_33 = V_33 ,
} ;
if ( F_81 ( V_50 ) )
return;
if ( V_122 )
V_28 . type = V_124 ;
F_73 ( & V_28 ) ;
}
void F_87 ( struct V_4 * V_5 , struct V_126 * V_127 ,
int V_128 , int V_129 , int V_33 )
{
struct V_1 * V_2 ;
struct V_126 * V_130 ;
int V_57 ;
if ( F_81 ( V_50 ) )
return;
F_88 (sg, s, mapped_ents, i) {
V_2 = F_30 () ;
if ( ! V_2 )
return;
V_2 -> type = V_102 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_41 = F_89 ( V_130 ) ;
V_2 -> V_27 = F_90 ( V_130 ) ;
V_2 -> V_16 = F_91 ( V_130 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_34 = V_128 ;
V_2 -> V_131 = V_129 ;
if ( ! F_83 ( F_92 ( V_130 ) ) ) {
F_75 ( V_5 , F_93 ( V_130 ) ) ;
F_78 ( V_5 , F_93 ( V_130 ) , F_90 ( V_130 ) ) ;
}
F_27 ( V_2 ) ;
}
}
static int F_94 ( struct V_4 * V_5 ,
struct V_1 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
int V_129 ;
V_24 = F_10 ( V_28 , & V_8 ) ;
V_2 = F_18 ( V_24 , V_28 ) ;
V_129 = 0 ;
if ( V_2 )
V_129 = V_2 -> V_131 ;
F_12 ( V_24 , & V_8 ) ;
return V_129 ;
}
void F_95 ( struct V_4 * V_5 , struct V_126 * V_132 ,
int V_133 , int V_134 )
{
struct V_126 * V_130 ;
int V_129 = 0 , V_57 ;
if ( F_81 ( V_50 ) )
return;
F_88 (sglist, s, nelems, i) {
struct V_1 V_28 = {
. type = V_102 ,
. V_5 = V_5 ,
. V_41 = F_89 ( V_130 ) ,
. V_16 = F_91 ( V_130 ) ,
. V_27 = F_90 ( V_130 ) ,
. V_33 = V_134 ,
. V_34 = V_133 ,
} ;
if ( V_129 && V_57 >= V_129 )
break;
if ( ! V_57 )
V_129 = F_94 ( V_5 , & V_28 ) ;
F_73 ( & V_28 ) ;
}
}
void F_96 ( struct V_4 * V_5 , T_5 V_27 ,
T_8 V_121 , void * V_135 )
{
struct V_1 * V_2 ;
if ( F_81 ( V_50 ) )
return;
if ( F_81 ( V_135 == NULL ) )
return;
V_2 = F_30 () ;
if ( ! V_2 )
return;
V_2 -> type = V_101 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_41 = F_97 ( V_135 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_16 = V_121 ;
V_2 -> V_33 = V_116 ;
F_27 ( V_2 ) ;
}
void F_98 ( struct V_4 * V_5 , T_5 V_27 ,
void * V_135 , T_8 V_104 )
{
struct V_1 V_28 = {
. type = V_101 ,
. V_5 = V_5 ,
. V_41 = F_97 ( V_135 ) ,
. V_16 = V_104 ,
. V_27 = V_27 ,
. V_33 = V_116 ,
} ;
if ( F_81 ( V_50 ) )
return;
F_73 ( & V_28 ) ;
}
void F_99 ( struct V_4 * V_5 , T_8 V_136 ,
T_5 V_27 , int V_33 )
{
struct V_1 V_28 ;
if ( F_81 ( V_50 ) )
return;
V_28 . type = V_124 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_136 ;
V_28 . V_27 = V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_79 ( V_5 , & V_28 , true ) ;
}
void F_100 ( struct V_4 * V_5 ,
T_8 V_136 , T_5 V_27 ,
int V_33 )
{
struct V_1 V_28 ;
if ( F_81 ( V_50 ) )
return;
V_28 . type = V_124 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_136 ;
V_28 . V_27 = V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_79 ( V_5 , & V_28 , false ) ;
}
void F_101 ( struct V_4 * V_5 ,
T_8 V_136 ,
unsigned long V_120 , T_5 V_27 ,
int V_33 )
{
struct V_1 V_28 ;
if ( F_81 ( V_50 ) )
return;
V_28 . type = V_124 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_136 ;
V_28 . V_27 = V_120 + V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_79 ( V_5 , & V_28 , true ) ;
}
void F_102 ( struct V_4 * V_5 ,
T_8 V_136 ,
unsigned long V_120 ,
T_5 V_27 , int V_33 )
{
struct V_1 V_28 ;
if ( F_81 ( V_50 ) )
return;
V_28 . type = V_124 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_136 ;
V_28 . V_27 = V_120 + V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_79 ( V_5 , & V_28 , false ) ;
}
void F_103 ( struct V_4 * V_5 , struct V_126 * V_127 ,
int V_133 , int V_33 )
{
struct V_126 * V_130 ;
int V_129 = 0 , V_57 ;
if ( F_81 ( V_50 ) )
return;
F_88 (sg, s, nelems, i) {
struct V_1 V_28 = {
. type = V_102 ,
. V_5 = V_5 ,
. V_41 = F_89 ( V_130 ) ,
. V_16 = F_91 ( V_130 ) ,
. V_27 = F_90 ( V_130 ) ,
. V_33 = V_33 ,
. V_34 = V_133 ,
} ;
if ( ! V_57 )
V_129 = F_94 ( V_5 , & V_28 ) ;
if ( V_57 >= V_129 )
break;
F_79 ( V_5 , & V_28 , true ) ;
}
}
void F_104 ( struct V_4 * V_5 , struct V_126 * V_127 ,
int V_133 , int V_33 )
{
struct V_126 * V_130 ;
int V_129 = 0 , V_57 ;
if ( F_81 ( V_50 ) )
return;
F_88 (sg, s, nelems, i) {
struct V_1 V_28 = {
. type = V_102 ,
. V_5 = V_5 ,
. V_41 = F_89 ( V_130 ) ,
. V_16 = F_91 ( V_130 ) ,
. V_27 = F_90 ( V_130 ) ,
. V_33 = V_33 ,
. V_34 = V_133 ,
} ;
if ( ! V_57 )
V_129 = F_94 ( V_5 , & V_28 ) ;
if ( V_57 >= V_129 )
break;
F_79 ( V_5 , & V_28 , false ) ;
}
}
static int T_7 F_105 ( char * V_97 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_15 - 1 ; ++ V_57 , ++ V_97 ) {
V_10 [ V_57 ] = * V_97 ;
if ( * V_97 == 0 )
break;
}
if ( V_10 [ 0 ] )
F_42 ( L_7 ,
V_10 ) ;
return 1 ;
}
