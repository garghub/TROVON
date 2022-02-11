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
{
int V_22 = F_10 ( V_4 ) ;
unsigned long V_23 ;
F_12 ( & V_24 [ V_22 ] . V_25 , V_23 ) ;
* V_10 = V_23 ;
return & V_24 [ V_22 ] ;
}
static void F_13 ( struct V_21 * V_26 ,
unsigned long * V_10 )
{
unsigned long V_23 = * V_10 ;
F_14 ( & V_26 -> V_25 , V_23 ) ;
}
static bool F_15 ( struct V_3 * V_27 , struct V_3 * V_28 )
{
return ( ( V_27 -> V_18 == V_28 -> V_18 ) &&
( V_27 -> V_7 == V_28 -> V_7 ) ) ? true : false ;
}
static bool F_16 ( struct V_3 * V_27 ,
struct V_3 * V_28 )
{
if ( V_27 -> V_7 != V_28 -> V_7 )
return false ;
if ( ( V_28 -> V_18 <= V_27 -> V_18 ) &&
( ( V_28 -> V_18 + V_28 -> V_29 ) >= ( V_27 -> V_18 + V_27 -> V_29 ) ) )
return true ;
return false ;
}
static struct V_3 * F_17 ( struct V_21 * V_26 ,
struct V_3 * V_30 ,
T_1 V_31 )
{
struct V_3 * V_4 , * V_11 = NULL ;
int V_32 = 0 , V_33 , V_34 = - 1 ;
F_18 (entry, &bucket->list, list) {
if ( ! V_31 ( V_30 , V_4 ) )
continue;
V_32 += 1 ;
V_33 = 0 ;
V_4 -> V_29 == V_30 -> V_29 ? ++ V_33 : 0 ;
V_4 -> type == V_30 -> type ? ++ V_33 : 0 ;
V_4 -> V_35 == V_30 -> V_35 ? ++ V_33 : 0 ;
V_4 -> V_36 == V_30 -> V_36 ? ++ V_33 : 0 ;
if ( V_33 == 4 ) {
return V_4 ;
} else if ( V_33 > V_34 ) {
V_34 = V_33 ;
V_11 = V_4 ;
}
}
V_11 = ( V_32 == 1 ) ? V_11 : NULL ;
return V_11 ;
}
static struct V_3 * F_19 ( struct V_21 * V_26 ,
struct V_3 * V_30 )
{
return F_17 ( V_26 , V_30 , F_15 ) ;
}
static struct V_3 * F_20 ( struct V_21 * * V_26 ,
struct V_3 * V_30 ,
unsigned long * V_10 )
{
unsigned int V_37 = F_21 ( V_30 -> V_7 ) ;
struct V_3 * V_4 , V_38 = * V_30 ;
unsigned int V_39 = 0 ;
while ( V_39 <= V_37 ) {
V_4 = F_17 ( * V_26 , V_30 , F_16 ) ;
if ( V_4 )
return V_4 ;
F_13 ( * V_26 , V_10 ) ;
V_39 += ( 1 << V_19 ) ;
V_38 . V_18 -= ( 1 << V_19 ) ;
* V_26 = F_11 ( & V_38 , V_10 ) ;
}
return NULL ;
}
static void F_22 ( struct V_21 * V_26 ,
struct V_3 * V_4 )
{
F_23 ( & V_4 -> V_40 , & V_26 -> V_40 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
F_25 ( & V_4 -> V_40 ) ;
}
static unsigned long long F_26 ( struct V_3 * V_4 )
{
return F_27 ( F_28 ( V_4 -> V_41 ) ) + V_4 -> V_42 ;
}
void F_29 ( struct V_6 * V_7 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_43 ; V_22 ++ ) {
struct V_21 * V_26 = & V_24 [ V_22 ] ;
struct V_3 * V_4 ;
unsigned long V_10 ;
F_12 ( & V_26 -> V_25 , V_10 ) ;
F_18 (entry, &bucket->list, list) {
if ( ! V_7 || V_7 == V_4 -> V_7 ) {
F_30 ( V_4 -> V_7 ,
L_2 ,
V_44 [ V_4 -> type ] , V_22 ,
F_26 ( V_4 ) , V_4 -> V_41 ,
V_4 -> V_18 , V_4 -> V_29 ,
V_45 [ V_4 -> V_35 ] ,
V_46 [ V_4 -> V_47 ] ) ;
}
}
F_14 ( & V_26 -> V_25 , V_10 ) ;
}
}
static T_2 F_31 ( struct V_3 * V_4 )
{
return ( V_4 -> V_41 << V_48 ) +
( V_4 -> V_42 >> V_49 ) ;
}
static int F_32 ( T_2 V_50 )
{
int V_51 = 0 , V_52 ;
for ( V_52 = V_53 - 1 ; V_52 >= 0 ; V_52 -- )
if ( F_33 ( & V_54 , V_50 , V_52 ) )
V_51 |= 1 << V_52 ;
return V_51 ;
}
static int F_34 ( T_2 V_50 , int V_51 )
{
int V_52 ;
if ( V_51 > V_55 || V_51 < 0 )
return V_51 ;
for ( V_52 = V_53 - 1 ; V_52 >= 0 ; V_52 -- )
if ( V_51 & 1 << V_52 )
F_35 ( & V_54 , V_50 , V_52 ) ;
else
F_36 ( & V_54 , V_50 , V_52 ) ;
return V_51 ;
}
static void F_37 ( T_2 V_50 )
{
int V_51 = F_32 ( V_50 ) ;
V_51 = F_34 ( V_50 , ++ V_51 ) ;
F_38 ( V_51 > V_55 ,
L_3 ,
V_55 , & V_50 ) ;
}
static int F_39 ( T_2 V_50 )
{
int V_51 = F_32 ( V_50 ) ;
return F_34 ( V_50 , -- V_51 ) ;
}
static int F_40 ( struct V_3 * V_4 )
{
T_2 V_50 = F_31 ( V_4 ) ;
unsigned long V_10 ;
int V_56 ;
if ( V_4 -> V_35 == V_57 )
return 0 ;
F_12 ( & V_58 , V_10 ) ;
V_56 = F_41 ( & V_54 , V_50 , V_4 ) ;
if ( V_56 == - V_59 )
F_37 ( V_50 ) ;
F_14 ( & V_58 , V_10 ) ;
return V_56 ;
}
static void F_42 ( struct V_3 * V_4 )
{
T_2 V_50 = F_31 ( V_4 ) ;
unsigned long V_10 ;
if ( V_4 -> V_35 == V_57 )
return;
F_12 ( & V_58 , V_10 ) ;
if ( F_39 ( V_50 ) < 0 )
F_43 ( & V_54 , V_50 ) ;
F_14 ( & V_58 , V_10 ) ;
}
void F_44 ( struct V_60 * V_60 )
{
static struct V_3 * V_61 [ V_62 ] ;
struct V_3 * V_4 = NULL ;
void * * V_63 = ( void * * ) & V_61 ;
unsigned int V_64 , V_52 ;
unsigned long V_10 ;
T_2 V_50 ;
if ( ! V_60 )
return;
V_50 = ( T_2 ) F_45 ( V_60 ) << V_48 ;
F_12 ( & V_58 , V_10 ) ;
V_64 = F_46 ( & V_54 , V_63 , V_50 ,
V_62 ) ;
for ( V_52 = 0 ; V_52 < V_64 ; V_52 ++ ) {
T_2 V_65 = F_31 ( V_61 [ V_52 ] ) ;
if ( V_65 == V_50 ) {
V_4 = V_61 [ V_52 ] ;
break;
} else if ( V_65 >= V_50 + V_62 )
break;
}
F_14 ( & V_58 , V_10 ) ;
if ( ! V_4 )
return;
V_50 = F_31 ( V_4 ) ;
F_47 ( V_4 -> V_7 , V_4 ,
L_4 ,
& V_50 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_21 * V_26 ;
unsigned long V_10 ;
int V_56 ;
V_26 = F_11 ( V_4 , & V_10 ) ;
F_22 ( V_26 , V_4 ) ;
F_13 ( V_26 , & V_10 ) ;
V_56 = F_40 ( V_4 ) ;
if ( V_56 == - V_66 ) {
F_49 ( L_5 ) ;
V_1 = true ;
}
}
static struct V_3 * F_50 ( void )
{
struct V_3 * V_4 ;
V_4 = F_51 ( V_67 . V_68 , struct V_3 , V_40 ) ;
F_25 ( & V_4 -> V_40 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_69 -= 1 ;
if ( V_69 < V_70 )
V_70 = V_69 ;
return V_4 ;
}
static struct V_3 * F_52 ( void )
{
struct V_3 * V_4 ;
unsigned long V_10 ;
F_12 ( & V_71 , V_10 ) ;
if ( F_53 ( & V_67 ) ) {
F_49 ( L_6 ) ;
V_1 = true ;
F_14 ( & V_71 , V_10 ) ;
return NULL ;
}
V_4 = F_50 () ;
F_14 ( & V_71 , V_10 ) ;
#ifdef F_3
V_4 -> V_5 . V_72 = V_73 ;
V_4 -> V_5 . V_74 = V_4 -> V_75 ;
V_4 -> V_5 . V_76 = 2 ;
F_54 ( & V_4 -> V_5 ) ;
#endif
return V_4 ;
}
static void F_55 ( struct V_3 * V_4 )
{
unsigned long V_10 ;
F_42 ( V_4 ) ;
F_12 ( & V_71 , V_10 ) ;
F_56 ( & V_4 -> V_40 , & V_67 ) ;
V_69 += 1 ;
F_14 ( & V_71 , V_10 ) ;
}
int F_57 ( T_3 V_77 )
{
int V_52 , V_78 , V_11 = 0 ;
unsigned long V_10 ;
struct V_3 * V_4 ;
F_58 ( V_79 ) ;
F_12 ( & V_71 , V_10 ) ;
if ( V_80 < V_77 ) {
V_78 = V_77 - V_80 ;
F_14 ( & V_71 , V_10 ) ;
for ( V_52 = 0 ; V_52 < V_78 ; V_52 ++ ) {
V_4 = F_59 ( sizeof( * V_4 ) , V_81 ) ;
if ( ! V_4 )
break;
F_23 ( & V_4 -> V_40 , & V_79 ) ;
}
F_12 ( & V_71 , V_10 ) ;
F_60 ( & V_79 , & V_67 ) ;
V_80 += V_52 ;
V_69 += V_52 ;
} else {
V_78 = V_80 - V_77 ;
for ( V_52 = 0 ; V_52 < V_78 && ! F_53 ( & V_67 ) ; V_52 ++ ) {
V_4 = F_50 () ;
F_61 ( V_4 ) ;
}
V_80 -= V_52 ;
}
if ( V_80 != V_77 )
V_11 = 1 ;
F_14 ( & V_71 , V_10 ) ;
return V_11 ;
}
static int F_62 ( T_3 V_77 )
{
struct V_3 * V_4 , * V_82 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_77 ; ++ V_52 ) {
V_4 = F_59 ( sizeof( * V_4 ) , V_81 ) ;
if ( ! V_4 )
goto V_83;
F_23 ( & V_4 -> V_40 , & V_67 ) ;
}
V_69 = V_77 ;
V_70 = V_77 ;
F_63 ( L_7 , V_77 ) ;
return 0 ;
V_83:
F_64 (entry, next_entry, &free_entries, list) {
F_25 ( & V_4 -> V_40 ) ;
F_61 ( V_4 ) ;
}
return - V_66 ;
}
static T_4 F_65 ( struct V_84 * V_84 , char T_5 * V_85 ,
T_6 V_86 , T_7 * V_87 )
{
char V_88 [ V_17 + 1 ] ;
unsigned long V_10 ;
int V_89 ;
if ( ! V_12 [ 0 ] )
return 0 ;
F_8 ( & V_15 , V_10 ) ;
V_89 = F_66 ( V_88 , V_17 + 1 , L_8 , V_12 ) ;
F_9 ( & V_15 , V_10 ) ;
return F_67 ( V_85 , V_86 , V_87 , V_88 , V_89 ) ;
}
static T_4 F_68 ( struct V_84 * V_84 , const char T_5 * V_90 ,
T_6 V_86 , T_7 * V_87 )
{
char V_88 [ V_17 ] ;
unsigned long V_10 ;
T_6 V_89 ;
int V_52 ;
V_89 = F_69 ( V_86 , ( T_6 ) ( V_17 - 1 ) ) ;
if ( F_70 ( V_88 , V_90 , V_89 ) )
return - V_91 ;
V_88 [ V_89 ] = 0 ;
F_71 ( & V_15 , V_10 ) ;
if ( ! isalnum ( V_88 [ 0 ] ) ) {
if ( V_12 [ 0 ] )
F_63 ( L_9 ) ;
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
F_63 ( L_10 ,
V_12 ) ;
V_92:
F_72 ( & V_15 , V_10 ) ;
return V_86 ;
}
static int F_73 ( void )
{
V_93 = F_74 ( L_11 , NULL ) ;
if ( ! V_93 ) {
F_49 ( L_12 ) ;
return - V_66 ;
}
V_94 = F_75 ( L_13 , 0444 ,
V_93 ,
& V_1 ) ;
if ( ! V_94 )
goto V_83;
V_95 = F_76 ( L_14 , 0444 ,
V_93 , & V_96 ) ;
if ( ! V_95 )
goto V_83;
V_97 = F_76 ( L_15 , 0644 ,
V_93 ,
& V_98 ) ;
if ( ! V_97 )
goto V_83;
V_99 = F_76 ( L_16 , 0644 ,
V_93 ,
& V_100 ) ;
if ( ! V_99 )
goto V_83;
V_101 = F_76 ( L_17 , 0444 ,
V_93 ,
& V_69 ) ;
if ( ! V_101 )
goto V_83;
V_102 = F_76 ( L_18 , 0444 ,
V_93 ,
& V_70 ) ;
if ( ! V_102 )
goto V_83;
V_103 = F_77 ( L_19 , 0644 ,
V_93 , NULL , & V_104 ) ;
if ( ! V_103 )
goto V_83;
return 0 ;
V_83:
F_78 ( V_93 ) ;
return - V_66 ;
}
static int F_79 ( struct V_6 * V_7 , struct V_3 * * V_105 )
{
struct V_3 * V_4 ;
unsigned long V_10 ;
int V_86 = 0 , V_52 ;
F_80 ( V_10 ) ;
for ( V_52 = 0 ; V_52 < V_43 ; ++ V_52 ) {
F_81 ( & V_24 [ V_52 ] . V_25 ) ;
F_18 (entry, &dma_entry_hash[i].list, list) {
if ( V_4 -> V_7 == V_7 ) {
V_86 += 1 ;
* V_105 = V_4 ;
}
}
F_82 ( & V_24 [ V_52 ] . V_25 ) ;
}
F_83 ( V_10 ) ;
return V_86 ;
}
static int F_84 ( struct V_106 * V_107 , unsigned long V_108 , void * V_109 )
{
struct V_6 * V_7 = V_109 ;
struct V_3 * V_110 ( V_4 ) ;
int V_86 ;
if ( F_1 () )
return 0 ;
switch ( V_108 ) {
case V_111 :
V_86 = F_79 ( V_7 , & V_4 ) ;
if ( V_86 == 0 )
break;
F_47 ( V_7 , V_4 , L_20
L_21
L_22
L_23
L_24
L_25 ,
V_86 , V_4 -> V_18 , V_4 -> V_29 ,
V_45 [ V_4 -> V_35 ] , V_44 [ V_4 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_85 ( struct V_112 * V_113 )
{
struct V_106 * V_107 ;
if ( F_1 () )
return;
V_107 = F_59 ( sizeof( struct V_106 ) , V_81 ) ;
if ( V_107 == NULL ) {
F_49 ( L_26 ) ;
return;
}
V_107 -> V_114 = F_84 ;
F_86 ( V_113 , V_107 ) ;
}
void F_87 ( T_3 V_77 )
{
int V_52 ;
if ( V_1 )
return;
for ( V_52 = 0 ; V_52 < V_43 ; ++ V_52 ) {
F_88 ( & V_24 [ V_52 ] . V_40 ) ;
F_89 ( & V_24 [ V_52 ] . V_25 ) ;
}
if ( F_73 () != 0 ) {
F_49 ( L_27 ) ;
V_1 = true ;
return;
}
if ( V_115 )
V_77 = V_115 ;
if ( F_62 ( V_77 ) != 0 ) {
F_49 ( L_28 ) ;
V_1 = true ;
return;
}
V_80 = V_69 ;
V_2 = true ;
F_63 ( L_29 ) ;
}
static T_8 int F_90 ( char * V_116 )
{
if ( ! V_116 )
return - V_117 ;
if ( strncmp ( V_116 , L_30 , 3 ) == 0 ) {
F_63 ( L_31 ) ;
V_1 = true ;
}
return 0 ;
}
static T_8 int F_91 ( char * V_116 )
{
int V_118 ;
if ( ! V_116 )
return - V_117 ;
V_118 = F_92 ( & V_116 , & V_115 ) ;
if ( ! V_118 )
V_115 = 0 ;
return 0 ;
}
static void F_93 ( struct V_3 * V_30 )
{
struct V_3 * V_4 ;
struct V_21 * V_26 ;
unsigned long V_10 ;
V_26 = F_11 ( V_30 , & V_10 ) ;
V_4 = F_19 ( V_26 , V_30 ) ;
if ( ! V_4 ) {
F_13 ( V_26 , & V_10 ) ;
if ( F_94 ( V_30 -> V_7 , V_30 -> V_18 ) ) {
F_47 ( V_30 -> V_7 , NULL ,
L_32
L_33 ) ;
} else {
F_47 ( V_30 -> V_7 , NULL ,
L_34
L_35
L_36 ,
V_30 -> V_18 , V_30 -> V_29 ) ;
}
return;
}
if ( V_30 -> V_29 != V_4 -> V_29 ) {
F_47 ( V_30 -> V_7 , V_4 , L_37
L_38
L_39
L_40 ,
V_30 -> V_18 , V_4 -> V_29 , V_30 -> V_29 ) ;
}
if ( V_30 -> type != V_4 -> type ) {
F_47 ( V_30 -> V_7 , V_4 , L_37
L_41
L_24
L_42 ,
V_30 -> V_18 , V_30 -> V_29 ,
V_44 [ V_4 -> type ] , V_44 [ V_30 -> type ] ) ;
} else if ( ( V_4 -> type == V_119 ) &&
( F_26 ( V_30 ) != F_26 ( V_4 ) ) ) {
F_47 ( V_30 -> V_7 , V_4 , L_37
L_43
L_24
L_44
L_45 ,
V_30 -> V_18 , V_30 -> V_29 ,
F_26 ( V_4 ) ,
F_26 ( V_30 ) ) ;
}
if ( V_30 -> V_36 && V_30 -> type == V_120 &&
V_30 -> V_36 != V_4 -> V_36 ) {
F_47 ( V_30 -> V_7 , V_4 , L_37
L_46
L_47 ,
V_4 -> V_36 , V_30 -> V_36 ) ;
}
if ( V_30 -> V_35 != V_4 -> V_35 ) {
F_47 ( V_30 -> V_7 , V_4 , L_37
L_48
L_24
L_49 ,
V_30 -> V_18 , V_30 -> V_29 ,
V_45 [ V_4 -> V_35 ] ,
V_45 [ V_30 -> V_35 ] ) ;
}
if ( V_4 -> V_47 == V_121 ) {
F_47 ( V_30 -> V_7 , V_4 ,
L_50
L_24
L_51 ,
V_30 -> V_18 , V_30 -> V_29 ,
V_44 [ V_4 -> type ] ) ;
}
F_24 ( V_4 ) ;
F_55 ( V_4 ) ;
F_13 ( V_26 , & V_10 ) ;
}
static void F_95 ( struct V_6 * V_7 , void * V_122 )
{
if ( F_96 ( V_122 ) )
F_47 ( V_7 , NULL , L_52
L_53 , V_122 ) ;
}
static inline bool V_51 ( void * V_122 , unsigned long V_89 , void * V_123 , void * V_124 )
{
unsigned long V_125 = ( unsigned long ) V_122 ;
unsigned long V_126 = V_125 + V_89 ;
unsigned long V_127 = ( unsigned long ) V_123 ;
unsigned long V_128 = ( unsigned long ) V_124 ;
return ! ( V_126 <= V_127 || V_125 >= V_128 ) ;
}
static void F_97 ( struct V_6 * V_7 , void * V_122 , unsigned long V_89 )
{
if ( V_51 ( V_122 , V_89 , V_129 , V_130 ) ||
V_51 ( V_122 , V_89 , V_131 , V_132 ) )
F_47 ( V_7 , NULL , L_54 , V_122 , V_89 ) ;
}
static void F_98 ( struct V_6 * V_7 ,
struct V_3 * V_30 ,
bool V_133 )
{
struct V_3 * V_4 ;
struct V_21 * V_26 ;
unsigned long V_10 ;
V_26 = F_11 ( V_30 , & V_10 ) ;
V_4 = F_20 ( & V_26 , V_30 , & V_10 ) ;
if ( ! V_4 ) {
F_47 ( V_7 , NULL , L_55
L_56
L_57 ,
( unsigned long long ) V_30 -> V_18 , V_30 -> V_29 ) ;
goto V_134;
}
if ( V_30 -> V_29 > V_4 -> V_29 ) {
F_47 ( V_7 , V_4 , L_58
L_59
L_60
L_61
L_62 ,
V_4 -> V_18 , V_4 -> V_29 ,
V_30 -> V_29 ) ;
}
if ( V_4 -> V_35 == V_135 )
goto V_134;
if ( V_30 -> V_35 != V_4 -> V_35 ) {
F_47 ( V_7 , V_4 , L_63
L_48
L_24
L_64 ,
( unsigned long long ) V_30 -> V_18 , V_4 -> V_29 ,
V_45 [ V_4 -> V_35 ] ,
V_45 [ V_30 -> V_35 ] ) ;
}
if ( V_133 && ! ( V_4 -> V_35 == V_136 ) &&
! ( V_30 -> V_35 == V_57 ) )
F_47 ( V_7 , V_4 , L_63
L_65
L_24
L_64 ,
( unsigned long long ) V_30 -> V_18 , V_4 -> V_29 ,
V_45 [ V_4 -> V_35 ] ,
V_45 [ V_30 -> V_35 ] ) ;
if ( ! V_133 && ! ( V_4 -> V_35 == V_57 ) &&
! ( V_30 -> V_35 == V_136 ) )
F_47 ( V_7 , V_4 , L_63
L_66
L_24
L_64 ,
( unsigned long long ) V_30 -> V_18 , V_4 -> V_29 ,
V_45 [ V_4 -> V_35 ] ,
V_45 [ V_30 -> V_35 ] ) ;
V_134:
F_13 ( V_26 , & V_10 ) ;
}
void F_99 ( struct V_6 * V_7 , struct V_60 * V_60 , T_6 V_42 ,
T_6 V_29 , int V_35 , T_9 V_137 ,
bool V_138 )
{
struct V_3 * V_4 ;
if ( F_100 ( F_1 () ) )
return;
if ( F_94 ( V_7 , V_137 ) )
return;
V_4 = F_52 () ;
if ( ! V_4 )
return;
V_4 -> V_7 = V_7 ;
V_4 -> type = V_139 ;
V_4 -> V_41 = F_45 ( V_60 ) ;
V_4 -> V_42 = V_42 ,
V_4 -> V_18 = V_137 ;
V_4 -> V_29 = V_29 ;
V_4 -> V_35 = V_35 ;
V_4 -> V_47 = V_121 ;
if ( V_138 )
V_4 -> type = V_140 ;
if ( ! F_101 ( V_60 ) ) {
void * V_122 = F_102 ( V_60 ) + V_42 ;
F_95 ( V_7 , V_122 ) ;
F_97 ( V_7 , V_122 , V_29 ) ;
}
F_48 ( V_4 ) ;
}
void F_103 ( struct V_6 * V_7 , T_9 V_137 )
{
struct V_3 V_30 ;
struct V_3 * V_4 ;
struct V_21 * V_26 ;
unsigned long V_10 ;
if ( F_100 ( F_1 () ) )
return;
V_30 . V_7 = V_7 ;
V_30 . V_18 = V_137 ;
V_26 = F_11 ( & V_30 , & V_10 ) ;
F_18 (entry, &bucket->list, list) {
if ( ! F_15 ( & V_30 , V_4 ) )
continue;
if ( V_4 -> V_47 == V_121 ) {
V_4 -> V_47 = V_141 ;
break;
}
}
F_13 ( V_26 , & V_10 ) ;
}
void F_104 ( struct V_6 * V_7 , T_9 V_122 ,
T_6 V_29 , int V_35 , bool V_138 )
{
struct V_3 V_30 = {
. type = V_139 ,
. V_7 = V_7 ,
. V_18 = V_122 ,
. V_29 = V_29 ,
. V_35 = V_35 ,
} ;
if ( F_100 ( F_1 () ) )
return;
if ( V_138 )
V_30 . type = V_140 ;
F_93 ( & V_30 ) ;
}
void F_105 ( struct V_6 * V_7 , struct V_142 * V_143 ,
int V_64 , int V_144 , int V_35 )
{
struct V_3 * V_4 ;
struct V_142 * V_145 ;
int V_52 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sg, s, mapped_ents, i) {
V_4 = F_52 () ;
if ( ! V_4 )
return;
V_4 -> type = V_120 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_41 = F_45 ( F_107 ( V_145 ) ) ;
V_4 -> V_42 = V_145 -> V_42 ,
V_4 -> V_29 = F_108 ( V_145 ) ;
V_4 -> V_18 = F_109 ( V_145 ) ;
V_4 -> V_35 = V_35 ;
V_4 -> V_36 = V_64 ;
V_4 -> V_146 = V_144 ;
if ( ! F_101 ( F_107 ( V_145 ) ) ) {
F_95 ( V_7 , F_110 ( V_145 ) ) ;
F_97 ( V_7 , F_110 ( V_145 ) , F_108 ( V_145 ) ) ;
}
F_48 ( V_4 ) ;
}
}
static int F_111 ( struct V_6 * V_7 ,
struct V_3 * V_30 )
{
struct V_3 * V_4 ;
struct V_21 * V_26 ;
unsigned long V_10 ;
int V_144 ;
V_26 = F_11 ( V_30 , & V_10 ) ;
V_4 = F_19 ( V_26 , V_30 ) ;
V_144 = 0 ;
if ( V_4 )
V_144 = V_4 -> V_146 ;
F_13 ( V_26 , & V_10 ) ;
return V_144 ;
}
void F_112 ( struct V_6 * V_7 , struct V_142 * V_147 ,
int V_148 , int V_149 )
{
struct V_142 * V_145 ;
int V_144 = 0 , V_52 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sglist, s, nelems, i) {
struct V_3 V_30 = {
. type = V_120 ,
. V_7 = V_7 ,
. V_41 = F_45 ( F_107 ( V_145 ) ) ,
. V_42 = V_145 -> V_42 ,
. V_18 = F_109 ( V_145 ) ,
. V_29 = F_108 ( V_145 ) ,
. V_35 = V_149 ,
. V_36 = V_148 ,
} ;
if ( V_144 && V_52 >= V_144 )
break;
if ( ! V_52 )
V_144 = F_111 ( V_7 , & V_30 ) ;
F_93 ( & V_30 ) ;
}
}
void F_113 ( struct V_6 * V_7 , T_6 V_29 ,
T_9 V_137 , void * V_150 )
{
struct V_3 * V_4 ;
if ( F_100 ( F_1 () ) )
return;
if ( F_100 ( V_150 == NULL ) )
return;
V_4 = F_52 () ;
if ( ! V_4 )
return;
V_4 -> type = V_119 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_41 = F_45 ( F_114 ( V_150 ) ) ;
V_4 -> V_42 = ( T_6 ) V_150 & V_151 ;
V_4 -> V_29 = V_29 ;
V_4 -> V_18 = V_137 ;
V_4 -> V_35 = V_135 ;
F_48 ( V_4 ) ;
}
void F_115 ( struct V_6 * V_7 , T_6 V_29 ,
void * V_150 , T_9 V_122 )
{
struct V_3 V_30 = {
. type = V_119 ,
. V_7 = V_7 ,
. V_41 = F_45 ( F_114 ( V_150 ) ) ,
. V_42 = ( T_6 ) V_150 & V_151 ,
. V_18 = V_122 ,
. V_29 = V_29 ,
. V_35 = V_135 ,
} ;
if ( F_100 ( F_1 () ) )
return;
F_93 ( & V_30 ) ;
}
void F_116 ( struct V_6 * V_7 , T_9 V_152 ,
T_6 V_29 , int V_35 )
{
struct V_3 V_30 ;
if ( F_100 ( F_1 () ) )
return;
V_30 . type = V_140 ;
V_30 . V_7 = V_7 ;
V_30 . V_18 = V_152 ;
V_30 . V_29 = V_29 ;
V_30 . V_35 = V_35 ;
V_30 . V_36 = 0 ;
F_98 ( V_7 , & V_30 , true ) ;
}
void F_117 ( struct V_6 * V_7 ,
T_9 V_152 , T_6 V_29 ,
int V_35 )
{
struct V_3 V_30 ;
if ( F_100 ( F_1 () ) )
return;
V_30 . type = V_140 ;
V_30 . V_7 = V_7 ;
V_30 . V_18 = V_152 ;
V_30 . V_29 = V_29 ;
V_30 . V_35 = V_35 ;
V_30 . V_36 = 0 ;
F_98 ( V_7 , & V_30 , false ) ;
}
void F_118 ( struct V_6 * V_7 ,
T_9 V_152 ,
unsigned long V_42 , T_6 V_29 ,
int V_35 )
{
struct V_3 V_30 ;
if ( F_100 ( F_1 () ) )
return;
V_30 . type = V_140 ;
V_30 . V_7 = V_7 ;
V_30 . V_18 = V_152 ;
V_30 . V_29 = V_42 + V_29 ;
V_30 . V_35 = V_35 ;
V_30 . V_36 = 0 ;
F_98 ( V_7 , & V_30 , true ) ;
}
void F_119 ( struct V_6 * V_7 ,
T_9 V_152 ,
unsigned long V_42 ,
T_6 V_29 , int V_35 )
{
struct V_3 V_30 ;
if ( F_100 ( F_1 () ) )
return;
V_30 . type = V_140 ;
V_30 . V_7 = V_7 ;
V_30 . V_18 = V_152 ;
V_30 . V_29 = V_42 + V_29 ;
V_30 . V_35 = V_35 ;
V_30 . V_36 = 0 ;
F_98 ( V_7 , & V_30 , false ) ;
}
void F_120 ( struct V_6 * V_7 , struct V_142 * V_143 ,
int V_148 , int V_35 )
{
struct V_142 * V_145 ;
int V_144 = 0 , V_52 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sg, s, nelems, i) {
struct V_3 V_30 = {
. type = V_120 ,
. V_7 = V_7 ,
. V_41 = F_45 ( F_107 ( V_145 ) ) ,
. V_42 = V_145 -> V_42 ,
. V_18 = F_109 ( V_145 ) ,
. V_29 = F_108 ( V_145 ) ,
. V_35 = V_35 ,
. V_36 = V_148 ,
} ;
if ( ! V_52 )
V_144 = F_111 ( V_7 , & V_30 ) ;
if ( V_52 >= V_144 )
break;
F_98 ( V_7 , & V_30 , true ) ;
}
}
void F_121 ( struct V_6 * V_7 , struct V_142 * V_143 ,
int V_148 , int V_35 )
{
struct V_142 * V_145 ;
int V_144 = 0 , V_52 ;
if ( F_100 ( F_1 () ) )
return;
F_106 (sg, s, nelems, i) {
struct V_3 V_30 = {
. type = V_120 ,
. V_7 = V_7 ,
. V_41 = F_45 ( F_107 ( V_145 ) ) ,
. V_42 = V_145 -> V_42 ,
. V_18 = F_109 ( V_145 ) ,
. V_29 = F_108 ( V_145 ) ,
. V_35 = V_35 ,
. V_36 = V_148 ,
} ;
if ( ! V_52 )
V_144 = F_111 ( V_7 , & V_30 ) ;
if ( V_52 >= V_144 )
break;
F_98 ( V_7 , & V_30 , false ) ;
}
}
static int T_8 F_122 ( char * V_116 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_17 - 1 ; ++ V_52 , ++ V_116 ) {
V_12 [ V_52 ] = * V_116 ;
if ( * V_116 == 0 )
break;
}
if ( V_12 [ 0 ] )
F_63 ( L_10 ,
V_12 ) ;
return 1 ;
}
