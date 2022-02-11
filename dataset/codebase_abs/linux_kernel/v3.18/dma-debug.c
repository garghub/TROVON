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
static unsigned long long F_25 ( struct V_1 * V_2 )
{
return F_26 ( F_27 ( V_2 -> V_39 ) ) + V_2 -> V_40 ;
}
void F_28 ( struct V_4 * V_5 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_41 ; V_20 ++ ) {
struct V_19 * V_24 = & V_22 [ V_20 ] ;
struct V_1 * V_2 ;
unsigned long V_8 ;
F_11 ( & V_24 -> V_23 , V_8 ) ;
F_17 (entry, &bucket->list, list) {
if ( ! V_5 || V_5 == V_2 -> V_5 ) {
F_29 ( V_2 -> V_5 ,
L_2 ,
V_42 [ V_2 -> type ] , V_20 ,
F_25 ( V_2 ) , V_2 -> V_39 ,
V_2 -> V_16 , V_2 -> V_27 ,
V_43 [ V_2 -> V_33 ] ,
V_44 [ V_2 -> V_45 ] ) ;
}
}
F_13 ( & V_24 -> V_23 , V_8 ) ;
}
}
static T_2 F_30 ( struct V_1 * V_2 )
{
return ( V_2 -> V_39 << V_46 ) +
( V_2 -> V_40 >> V_47 ) ;
}
static int F_31 ( T_2 V_48 )
{
int V_49 = 0 , V_50 ;
for ( V_50 = V_51 - 1 ; V_50 >= 0 ; V_50 -- )
if ( F_32 ( & V_52 , V_48 , V_50 ) )
V_49 |= 1 << V_50 ;
return V_49 ;
}
static int F_33 ( T_2 V_48 , int V_49 )
{
int V_50 ;
if ( V_49 > V_53 || V_49 < 0 )
return V_49 ;
for ( V_50 = V_51 - 1 ; V_50 >= 0 ; V_50 -- )
if ( V_49 & 1 << V_50 )
F_34 ( & V_52 , V_48 , V_50 ) ;
else
F_35 ( & V_52 , V_48 , V_50 ) ;
return V_49 ;
}
static void F_36 ( T_2 V_48 )
{
int V_49 = F_31 ( V_48 ) ;
V_49 = F_33 ( V_48 , ++ V_49 ) ;
F_37 ( V_49 > V_53 ,
L_3 ,
V_53 , & V_48 ) ;
}
static int F_38 ( T_2 V_48 )
{
int V_49 = F_31 ( V_48 ) ;
return F_33 ( V_48 , -- V_49 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_2 V_48 = F_30 ( V_2 ) ;
unsigned long V_8 ;
int V_54 ;
if ( V_2 -> V_33 == V_55 )
return 0 ;
F_11 ( & V_56 , V_8 ) ;
V_54 = F_40 ( & V_52 , V_48 , V_2 ) ;
if ( V_54 == - V_57 )
F_36 ( V_48 ) ;
F_13 ( & V_56 , V_8 ) ;
return V_54 ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_2 V_48 = F_30 ( V_2 ) ;
unsigned long V_8 ;
if ( V_2 -> V_33 == V_55 )
return;
F_11 ( & V_56 , V_8 ) ;
if ( F_38 ( V_48 ) < 0 )
F_42 ( & V_52 , V_48 ) ;
F_13 ( & V_56 , V_8 ) ;
}
void F_43 ( struct V_58 * V_58 )
{
static struct V_1 * V_59 [ V_60 ] ;
struct V_1 * V_2 = NULL ;
void * * V_61 = ( void * * ) & V_59 ;
unsigned int V_62 , V_50 ;
unsigned long V_8 ;
T_2 V_48 ;
if ( ! V_58 )
return;
V_48 = ( T_2 ) F_44 ( V_58 ) << V_46 ;
F_11 ( & V_56 , V_8 ) ;
V_62 = F_45 ( & V_52 , V_61 , V_48 ,
V_60 ) ;
for ( V_50 = 0 ; V_50 < V_62 ; V_50 ++ ) {
T_2 V_63 = F_30 ( V_59 [ V_50 ] ) ;
if ( V_63 == V_48 ) {
V_2 = V_59 [ V_50 ] ;
break;
} else if ( V_63 >= V_48 + V_60 )
break;
}
F_13 ( & V_56 , V_8 ) ;
if ( ! V_2 )
return;
V_48 = F_30 ( V_2 ) ;
F_46 ( V_2 -> V_5 , V_2 ,
L_4 ,
& V_48 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_19 * V_24 ;
unsigned long V_8 ;
int V_54 ;
V_24 = F_10 ( V_2 , & V_8 ) ;
F_21 ( V_24 , V_2 ) ;
F_12 ( V_24 , & V_8 ) ;
V_54 = F_39 ( V_2 ) ;
if ( V_54 == - V_64 ) {
F_48 ( L_5 ) ;
V_65 = true ;
}
}
static struct V_1 * F_49 ( void )
{
struct V_1 * V_2 ;
V_2 = F_50 ( V_66 . V_67 , struct V_1 , V_38 ) ;
F_24 ( & V_2 -> V_38 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_68 -= 1 ;
if ( V_68 < V_69 )
V_69 = V_68 ;
return V_2 ;
}
static struct V_1 * F_51 ( void )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
F_11 ( & V_70 , V_8 ) ;
if ( F_52 ( & V_66 ) ) {
F_48 ( L_6 ) ;
V_65 = true ;
F_13 ( & V_70 , V_8 ) ;
return NULL ;
}
V_2 = F_49 () ;
F_13 ( & V_70 , V_8 ) ;
#ifdef F_2
V_2 -> V_3 . V_71 = V_72 ;
V_2 -> V_3 . V_73 = V_2 -> V_74 ;
V_2 -> V_3 . V_75 = 2 ;
F_53 ( & V_2 -> V_3 ) ;
#endif
return V_2 ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
F_41 ( V_2 ) ;
F_11 ( & V_70 , V_8 ) ;
F_55 ( & V_2 -> V_38 , & V_66 ) ;
V_68 += 1 ;
F_13 ( & V_70 , V_8 ) ;
}
int F_56 ( T_3 V_76 )
{
int V_50 , V_77 , V_9 = 0 ;
unsigned long V_8 ;
struct V_1 * V_2 ;
F_57 ( V_78 ) ;
F_11 ( & V_70 , V_8 ) ;
if ( V_79 < V_76 ) {
V_77 = V_76 - V_79 ;
F_13 ( & V_70 , V_8 ) ;
for ( V_50 = 0 ; V_50 < V_77 ; V_50 ++ ) {
V_2 = F_58 ( sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
break;
F_22 ( & V_2 -> V_38 , & V_78 ) ;
}
F_11 ( & V_70 , V_8 ) ;
F_59 ( & V_78 , & V_66 ) ;
V_79 += V_50 ;
V_68 += V_50 ;
} else {
V_77 = V_79 - V_76 ;
for ( V_50 = 0 ; V_50 < V_77 && ! F_52 ( & V_66 ) ; V_50 ++ ) {
V_2 = F_49 () ;
F_60 ( V_2 ) ;
}
V_79 -= V_50 ;
}
if ( V_79 != V_76 )
V_9 = 1 ;
F_13 ( & V_70 , V_8 ) ;
return V_9 ;
}
static int F_61 ( T_3 V_76 )
{
struct V_1 * V_2 , * V_81 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_76 ; ++ V_50 ) {
V_2 = F_58 ( sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
goto V_82;
F_22 ( & V_2 -> V_38 , & V_66 ) ;
}
V_68 = V_76 ;
V_69 = V_76 ;
F_62 ( L_7 , V_76 ) ;
return 0 ;
V_82:
F_63 (entry, next_entry, &free_entries, list) {
F_24 ( & V_2 -> V_38 ) ;
F_60 ( V_2 ) ;
}
return - V_64 ;
}
static T_4 F_64 ( struct V_83 * V_83 , char T_5 * V_84 ,
T_6 V_85 , T_7 * V_86 )
{
char V_87 [ V_15 + 1 ] ;
unsigned long V_8 ;
int V_88 ;
if ( ! V_10 [ 0 ] )
return 0 ;
F_7 ( & V_13 , V_8 ) ;
V_88 = F_65 ( V_87 , V_15 + 1 , L_8 , V_10 ) ;
F_8 ( & V_13 , V_8 ) ;
return F_66 ( V_84 , V_85 , V_86 , V_87 , V_88 ) ;
}
static T_4 F_67 ( struct V_83 * V_83 , const char T_5 * V_89 ,
T_6 V_85 , T_7 * V_86 )
{
char V_87 [ V_15 ] ;
unsigned long V_8 ;
T_6 V_88 ;
int V_50 ;
V_88 = F_68 ( V_85 , ( T_6 ) ( V_15 - 1 ) ) ;
if ( F_69 ( V_87 , V_89 , V_88 ) )
return - V_90 ;
V_87 [ V_88 ] = 0 ;
F_70 ( & V_13 , V_8 ) ;
if ( ! isalnum ( V_87 [ 0 ] ) ) {
if ( V_10 [ 0 ] )
F_62 ( L_9 ) ;
V_10 [ 0 ] = 0 ;
V_11 = NULL ;
goto V_91;
}
for ( V_50 = 0 ; V_50 < V_15 - 1 ; ++ V_50 ) {
V_10 [ V_50 ] = V_87 [ V_50 ] ;
if ( isspace ( V_87 [ V_50 ] ) || V_87 [ V_50 ] == ' ' || V_87 [ V_50 ] == 0 )
break;
}
V_10 [ V_50 ] = 0 ;
V_11 = NULL ;
F_62 ( L_10 ,
V_10 ) ;
V_91:
F_71 ( & V_13 , V_8 ) ;
return V_85 ;
}
static int F_72 ( void )
{
V_92 = F_73 ( L_11 , NULL ) ;
if ( ! V_92 ) {
F_48 ( L_12 ) ;
return - V_64 ;
}
V_93 = F_74 ( L_13 , 0444 ,
V_92 ,
& V_65 ) ;
if ( ! V_93 )
goto V_82;
V_94 = F_75 ( L_14 , 0444 ,
V_92 , & V_95 ) ;
if ( ! V_94 )
goto V_82;
V_96 = F_75 ( L_15 , 0644 ,
V_92 ,
& V_97 ) ;
if ( ! V_96 )
goto V_82;
V_98 = F_75 ( L_16 , 0644 ,
V_92 ,
& V_99 ) ;
if ( ! V_98 )
goto V_82;
V_100 = F_75 ( L_17 , 0444 ,
V_92 ,
& V_68 ) ;
if ( ! V_100 )
goto V_82;
V_101 = F_75 ( L_18 , 0444 ,
V_92 ,
& V_69 ) ;
if ( ! V_101 )
goto V_82;
V_102 = F_76 ( L_19 , 0644 ,
V_92 , NULL , & V_103 ) ;
if ( ! V_102 )
goto V_82;
return 0 ;
V_82:
F_77 ( V_92 ) ;
return - V_64 ;
}
static int F_78 ( struct V_4 * V_5 , struct V_1 * * V_104 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
int V_85 = 0 , V_50 ;
F_79 ( V_8 ) ;
for ( V_50 = 0 ; V_50 < V_41 ; ++ V_50 ) {
F_80 ( & V_22 [ V_50 ] . V_23 ) ;
F_17 (entry, &dma_entry_hash[i].list, list) {
if ( V_2 -> V_5 == V_5 ) {
V_85 += 1 ;
* V_104 = V_2 ;
}
}
F_81 ( & V_22 [ V_50 ] . V_23 ) ;
}
F_82 ( V_8 ) ;
return V_85 ;
}
static int F_83 ( struct V_105 * V_106 , unsigned long V_107 , void * V_108 )
{
struct V_4 * V_5 = V_108 ;
struct V_1 * V_109 ( V_2 ) ;
int V_85 ;
if ( V_65 )
return 0 ;
switch ( V_107 ) {
case V_110 :
V_85 = F_78 ( V_5 , & V_2 ) ;
if ( V_85 == 0 )
break;
F_46 ( V_5 , V_2 , L_20
L_21
L_22
L_23
L_24
L_25 ,
V_85 , V_2 -> V_16 , V_2 -> V_27 ,
V_43 [ V_2 -> V_33 ] , V_42 [ V_2 -> type ] ) ;
break;
default:
break;
}
return 0 ;
}
void F_84 ( struct V_111 * V_112 )
{
struct V_105 * V_106 ;
if ( V_65 )
return;
V_106 = F_58 ( sizeof( struct V_105 ) , V_80 ) ;
if ( V_106 == NULL ) {
F_48 ( L_26 ) ;
return;
}
V_106 -> V_113 = F_83 ;
F_85 ( V_112 , V_106 ) ;
}
void F_86 ( T_3 V_76 )
{
int V_50 ;
if ( V_65 )
return;
for ( V_50 = 0 ; V_50 < V_41 ; ++ V_50 ) {
F_87 ( & V_22 [ V_50 ] . V_38 ) ;
F_88 ( & V_22 [ V_50 ] . V_23 ) ;
}
if ( F_72 () != 0 ) {
F_48 ( L_27 ) ;
V_65 = true ;
return;
}
if ( V_114 )
V_76 = V_114 ;
if ( F_61 ( V_76 ) != 0 ) {
F_48 ( L_28 ) ;
V_65 = true ;
return;
}
V_79 = V_68 ;
F_62 ( L_29 ) ;
}
static T_8 int F_89 ( char * V_115 )
{
if ( ! V_115 )
return - V_116 ;
if ( strncmp ( V_115 , L_30 , 3 ) == 0 ) {
F_62 ( L_31 ) ;
V_65 = true ;
}
return 0 ;
}
static T_8 int F_90 ( char * V_115 )
{
int V_117 ;
if ( ! V_115 )
return - V_116 ;
V_117 = F_91 ( & V_115 , & V_114 ) ;
if ( ! V_117 )
V_114 = 0 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_10 ( V_28 , & V_8 ) ;
V_2 = F_18 ( V_24 , V_28 ) ;
if ( ! V_2 ) {
F_12 ( V_24 , & V_8 ) ;
if ( F_93 ( V_28 -> V_5 , V_28 -> V_16 ) ) {
F_46 ( V_28 -> V_5 , NULL ,
L_32
L_33 ) ;
} else {
F_46 ( V_28 -> V_5 , NULL ,
L_34
L_35
L_36 ,
V_28 -> V_16 , V_28 -> V_27 ) ;
}
return;
}
if ( V_28 -> V_27 != V_2 -> V_27 ) {
F_46 ( V_28 -> V_5 , V_2 , L_37
L_38
L_39
L_40 ,
V_28 -> V_16 , V_2 -> V_27 , V_28 -> V_27 ) ;
}
if ( V_28 -> type != V_2 -> type ) {
F_46 ( V_28 -> V_5 , V_2 , L_37
L_41
L_24
L_42 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_42 [ V_2 -> type ] , V_42 [ V_28 -> type ] ) ;
} else if ( ( V_2 -> type == V_118 ) &&
( F_25 ( V_28 ) != F_25 ( V_2 ) ) ) {
F_46 ( V_28 -> V_5 , V_2 , L_37
L_43
L_24
L_44
L_45 ,
V_28 -> V_16 , V_28 -> V_27 ,
F_25 ( V_2 ) ,
F_25 ( V_28 ) ) ;
}
if ( V_28 -> V_34 && V_28 -> type == V_119 &&
V_28 -> V_34 != V_2 -> V_34 ) {
F_46 ( V_28 -> V_5 , V_2 , L_37
L_46
L_47 ,
V_2 -> V_34 , V_28 -> V_34 ) ;
}
if ( V_28 -> V_33 != V_2 -> V_33 ) {
F_46 ( V_28 -> V_5 , V_2 , L_37
L_48
L_24
L_49 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_43 [ V_2 -> V_33 ] ,
V_43 [ V_28 -> V_33 ] ) ;
}
if ( V_2 -> V_45 == V_120 ) {
F_46 ( V_28 -> V_5 , V_2 ,
L_50
L_24
L_51 ,
V_28 -> V_16 , V_28 -> V_27 ,
V_42 [ V_2 -> type ] ) ;
}
F_23 ( V_2 ) ;
F_54 ( V_2 ) ;
F_12 ( V_24 , & V_8 ) ;
}
static void F_94 ( struct V_4 * V_5 , void * V_121 )
{
if ( F_95 ( V_121 ) )
F_46 ( V_5 , NULL , L_52
L_53 , V_121 ) ;
}
static inline bool V_49 ( void * V_121 , unsigned long V_88 , void * V_122 , void * V_123 )
{
unsigned long V_124 = ( unsigned long ) V_121 ;
unsigned long V_125 = V_124 + V_88 ;
unsigned long V_126 = ( unsigned long ) V_122 ;
unsigned long V_127 = ( unsigned long ) V_123 ;
return ! ( V_125 <= V_126 || V_124 >= V_127 ) ;
}
static void F_96 ( struct V_4 * V_5 , void * V_121 , unsigned long V_88 )
{
if ( V_49 ( V_121 , V_88 , V_128 , V_129 ) ||
V_49 ( V_121 , V_88 , V_130 , V_131 ) )
F_46 ( V_5 , NULL , L_54 , V_121 , V_88 ) ;
}
static void F_97 ( struct V_4 * V_5 ,
struct V_1 * V_28 ,
bool V_132 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
V_24 = F_10 ( V_28 , & V_8 ) ;
V_2 = F_19 ( & V_24 , V_28 , & V_8 ) ;
if ( ! V_2 ) {
F_46 ( V_5 , NULL , L_55
L_56
L_57 ,
( unsigned long long ) V_28 -> V_16 , V_28 -> V_27 ) ;
goto V_133;
}
if ( V_28 -> V_27 > V_2 -> V_27 ) {
F_46 ( V_5 , V_2 , L_58
L_59
L_60
L_61
L_62 ,
V_2 -> V_16 , V_2 -> V_27 ,
V_28 -> V_27 ) ;
}
if ( V_2 -> V_33 == V_134 )
goto V_133;
if ( V_28 -> V_33 != V_2 -> V_33 ) {
F_46 ( V_5 , V_2 , L_63
L_48
L_24
L_64 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_43 [ V_2 -> V_33 ] ,
V_43 [ V_28 -> V_33 ] ) ;
}
if ( V_132 && ! ( V_2 -> V_33 == V_135 ) &&
! ( V_28 -> V_33 == V_55 ) )
F_46 ( V_5 , V_2 , L_63
L_65
L_24
L_64 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_43 [ V_2 -> V_33 ] ,
V_43 [ V_28 -> V_33 ] ) ;
if ( ! V_132 && ! ( V_2 -> V_33 == V_55 ) &&
! ( V_28 -> V_33 == V_135 ) )
F_46 ( V_5 , V_2 , L_63
L_66
L_24
L_64 ,
( unsigned long long ) V_28 -> V_16 , V_2 -> V_27 ,
V_43 [ V_2 -> V_33 ] ,
V_43 [ V_28 -> V_33 ] ) ;
V_133:
F_12 ( V_24 , & V_8 ) ;
}
void F_98 ( struct V_4 * V_5 , struct V_58 * V_58 , T_6 V_40 ,
T_6 V_27 , int V_33 , T_9 V_136 ,
bool V_137 )
{
struct V_1 * V_2 ;
if ( F_99 ( V_65 ) )
return;
if ( F_93 ( V_5 , V_136 ) )
return;
V_2 = F_51 () ;
if ( ! V_2 )
return;
V_2 -> V_5 = V_5 ;
V_2 -> type = V_138 ;
V_2 -> V_39 = F_44 ( V_58 ) ;
V_2 -> V_40 = V_40 ,
V_2 -> V_16 = V_136 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_45 = V_120 ;
if ( V_137 )
V_2 -> type = V_139 ;
if ( ! F_100 ( V_58 ) ) {
void * V_121 = F_101 ( V_58 ) + V_40 ;
F_94 ( V_5 , V_121 ) ;
F_96 ( V_5 , V_121 , V_27 ) ;
}
F_47 ( V_2 ) ;
}
void F_102 ( struct V_4 * V_5 , T_9 V_136 )
{
struct V_1 V_28 ;
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
if ( F_99 ( V_65 ) )
return;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_136 ;
V_24 = F_10 ( & V_28 , & V_8 ) ;
F_17 (entry, &bucket->list, list) {
if ( ! F_14 ( & V_28 , V_2 ) )
continue;
if ( V_2 -> V_45 == V_120 ) {
V_2 -> V_45 = V_140 ;
break;
}
}
F_12 ( V_24 , & V_8 ) ;
}
void F_103 ( struct V_4 * V_5 , T_9 V_121 ,
T_6 V_27 , int V_33 , bool V_137 )
{
struct V_1 V_28 = {
. type = V_138 ,
. V_5 = V_5 ,
. V_16 = V_121 ,
. V_27 = V_27 ,
. V_33 = V_33 ,
} ;
if ( F_99 ( V_65 ) )
return;
if ( V_137 )
V_28 . type = V_139 ;
F_92 ( & V_28 ) ;
}
void F_104 ( struct V_4 * V_5 , struct V_141 * V_142 ,
int V_62 , int V_143 , int V_33 )
{
struct V_1 * V_2 ;
struct V_141 * V_144 ;
int V_50 ;
if ( F_99 ( V_65 ) )
return;
F_105 (sg, s, mapped_ents, i) {
V_2 = F_51 () ;
if ( ! V_2 )
return;
V_2 -> type = V_119 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_39 = F_44 ( F_106 ( V_144 ) ) ;
V_2 -> V_40 = V_144 -> V_40 ,
V_2 -> V_27 = F_107 ( V_144 ) ;
V_2 -> V_16 = F_108 ( V_144 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_34 = V_62 ;
V_2 -> V_145 = V_143 ;
if ( ! F_100 ( F_106 ( V_144 ) ) ) {
F_94 ( V_5 , F_109 ( V_144 ) ) ;
F_96 ( V_5 , F_109 ( V_144 ) , F_107 ( V_144 ) ) ;
}
F_47 ( V_2 ) ;
}
}
static int F_110 ( struct V_4 * V_5 ,
struct V_1 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_24 ;
unsigned long V_8 ;
int V_143 ;
V_24 = F_10 ( V_28 , & V_8 ) ;
V_2 = F_18 ( V_24 , V_28 ) ;
V_143 = 0 ;
if ( V_2 )
V_143 = V_2 -> V_145 ;
F_12 ( V_24 , & V_8 ) ;
return V_143 ;
}
void F_111 ( struct V_4 * V_5 , struct V_141 * V_146 ,
int V_147 , int V_148 )
{
struct V_141 * V_144 ;
int V_143 = 0 , V_50 ;
if ( F_99 ( V_65 ) )
return;
F_105 (sglist, s, nelems, i) {
struct V_1 V_28 = {
. type = V_119 ,
. V_5 = V_5 ,
. V_39 = F_44 ( F_106 ( V_144 ) ) ,
. V_40 = V_144 -> V_40 ,
. V_16 = F_108 ( V_144 ) ,
. V_27 = F_107 ( V_144 ) ,
. V_33 = V_148 ,
. V_34 = V_147 ,
} ;
if ( V_143 && V_50 >= V_143 )
break;
if ( ! V_50 )
V_143 = F_110 ( V_5 , & V_28 ) ;
F_92 ( & V_28 ) ;
}
}
void F_112 ( struct V_4 * V_5 , T_6 V_27 ,
T_9 V_136 , void * V_149 )
{
struct V_1 * V_2 ;
if ( F_99 ( V_65 ) )
return;
if ( F_99 ( V_149 == NULL ) )
return;
V_2 = F_51 () ;
if ( ! V_2 )
return;
V_2 -> type = V_118 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_39 = F_44 ( F_113 ( V_149 ) ) ;
V_2 -> V_40 = ( T_6 ) V_149 & V_150 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_16 = V_136 ;
V_2 -> V_33 = V_134 ;
F_47 ( V_2 ) ;
}
void F_114 ( struct V_4 * V_5 , T_6 V_27 ,
void * V_149 , T_9 V_121 )
{
struct V_1 V_28 = {
. type = V_118 ,
. V_5 = V_5 ,
. V_39 = F_44 ( F_113 ( V_149 ) ) ,
. V_40 = ( T_6 ) V_149 & V_150 ,
. V_16 = V_121 ,
. V_27 = V_27 ,
. V_33 = V_134 ,
} ;
if ( F_99 ( V_65 ) )
return;
F_92 ( & V_28 ) ;
}
void F_115 ( struct V_4 * V_5 , T_9 V_151 ,
T_6 V_27 , int V_33 )
{
struct V_1 V_28 ;
if ( F_99 ( V_65 ) )
return;
V_28 . type = V_139 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_151 ;
V_28 . V_27 = V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_97 ( V_5 , & V_28 , true ) ;
}
void F_116 ( struct V_4 * V_5 ,
T_9 V_151 , T_6 V_27 ,
int V_33 )
{
struct V_1 V_28 ;
if ( F_99 ( V_65 ) )
return;
V_28 . type = V_139 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_151 ;
V_28 . V_27 = V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_97 ( V_5 , & V_28 , false ) ;
}
void F_117 ( struct V_4 * V_5 ,
T_9 V_151 ,
unsigned long V_40 , T_6 V_27 ,
int V_33 )
{
struct V_1 V_28 ;
if ( F_99 ( V_65 ) )
return;
V_28 . type = V_139 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_151 ;
V_28 . V_27 = V_40 + V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_97 ( V_5 , & V_28 , true ) ;
}
void F_118 ( struct V_4 * V_5 ,
T_9 V_151 ,
unsigned long V_40 ,
T_6 V_27 , int V_33 )
{
struct V_1 V_28 ;
if ( F_99 ( V_65 ) )
return;
V_28 . type = V_139 ;
V_28 . V_5 = V_5 ;
V_28 . V_16 = V_151 ;
V_28 . V_27 = V_40 + V_27 ;
V_28 . V_33 = V_33 ;
V_28 . V_34 = 0 ;
F_97 ( V_5 , & V_28 , false ) ;
}
void F_119 ( struct V_4 * V_5 , struct V_141 * V_142 ,
int V_147 , int V_33 )
{
struct V_141 * V_144 ;
int V_143 = 0 , V_50 ;
if ( F_99 ( V_65 ) )
return;
F_105 (sg, s, nelems, i) {
struct V_1 V_28 = {
. type = V_119 ,
. V_5 = V_5 ,
. V_39 = F_44 ( F_106 ( V_144 ) ) ,
. V_40 = V_144 -> V_40 ,
. V_16 = F_108 ( V_144 ) ,
. V_27 = F_107 ( V_144 ) ,
. V_33 = V_33 ,
. V_34 = V_147 ,
} ;
if ( ! V_50 )
V_143 = F_110 ( V_5 , & V_28 ) ;
if ( V_50 >= V_143 )
break;
F_97 ( V_5 , & V_28 , true ) ;
}
}
void F_120 ( struct V_4 * V_5 , struct V_141 * V_142 ,
int V_147 , int V_33 )
{
struct V_141 * V_144 ;
int V_143 = 0 , V_50 ;
if ( F_99 ( V_65 ) )
return;
F_105 (sg, s, nelems, i) {
struct V_1 V_28 = {
. type = V_119 ,
. V_5 = V_5 ,
. V_39 = F_44 ( F_106 ( V_144 ) ) ,
. V_40 = V_144 -> V_40 ,
. V_16 = F_108 ( V_144 ) ,
. V_27 = F_107 ( V_144 ) ,
. V_33 = V_33 ,
. V_34 = V_147 ,
} ;
if ( ! V_50 )
V_143 = F_110 ( V_5 , & V_28 ) ;
if ( V_50 >= V_143 )
break;
F_97 ( V_5 , & V_28 , false ) ;
}
}
static int T_8 F_121 ( char * V_115 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_15 - 1 ; ++ V_50 , ++ V_115 ) {
V_10 [ V_50 ] = * V_115 ;
if ( * V_115 == 0 )
break;
}
if ( V_10 [ 0 ] )
F_62 ( L_10 ,
V_10 ) ;
return 1 ;
}
