static inline unsigned F_1 ( void )
{
return V_1 << V_2 ;
}
static inline unsigned F_2 ( unsigned V_3 )
{
F_3 ( V_3 == 0 || V_3 > F_1 () ) ;
return ( V_3 + V_4 - 1 ) >> V_2 ;
}
static inline int F_4 ( struct V_5 * V_6 )
{
unsigned V_7 = ( unsigned long ) V_6 & ( V_8 - 1 ) ;
struct V_9 * V_10 = NULL ;
unsigned V_11 = - 1U ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( V_7 == F_5 ( F_6 ( * V_10 ) , V_14 [ V_12 ] ) ) {
V_11 = V_12 ;
break;
}
F_3 ( V_11 == - 1U ) ;
return V_11 ;
}
static char * F_7 ( struct V_5 * V_6 , unsigned V_3 )
{
struct V_9 * V_10 ;
char * V_15 ;
unsigned V_11 ;
F_8 ( V_6 , V_16 ) ;
V_11 = F_4 ( V_6 ) ;
F_3 ( V_3 == 0 || V_3 > F_1 () ) ;
V_10 = F_9 ( V_6 , struct V_9 , V_14 [ V_11 ] ) ;
F_10 ( & V_10 -> V_17 ) ;
V_15 = ( char * ) V_10 ;
if ( V_11 == 0 )
V_15 += ( ( sizeof( struct V_9 ) + V_4 - 1 ) &
V_18 ) ;
else if ( V_11 == 1 )
V_15 += V_8 - ( ( V_3 + V_4 - 1 ) & V_18 ) ;
return V_15 ;
}
static struct V_9 * F_11 ( void )
{
struct V_9 * V_10 = NULL ;
struct V_5 * V_19 , * V_20 ;
bool V_21 = 0 ;
F_12 ( & V_22 ) ;
if ( ! F_13 ( & V_23 ) ) {
V_10 = F_14 ( & V_23 ,
struct V_9 , V_24 ) ;
F_15 ( & V_10 -> V_24 ) ;
V_25 -- ;
V_21 = 1 ;
}
F_16 ( & V_22 ) ;
if ( V_10 == NULL )
V_10 = F_17 () ;
if ( F_18 ( V_10 != NULL ) ) {
F_19 ( & V_10 -> V_24 ) ;
V_19 = & V_10 -> V_14 [ 0 ] ; V_20 = & V_10 -> V_14 [ 1 ] ;
F_20 ( & V_10 -> V_17 ) ;
if ( V_21 ) {
F_21 ( V_10 , V_26 ) ;
F_22 ( V_10 , V_26 ) ;
F_3 ( V_19 -> V_3 != 0 || F_23 ( & V_19 -> V_27 ) ) ;
F_3 ( V_20 -> V_3 != 0 || F_23 ( & V_20 -> V_27 ) ) ;
} else {
F_24 ( & V_28 ) ;
F_19 ( & V_10 -> V_24 ) ;
F_22 ( V_10 , V_26 ) ;
V_19 -> V_3 = 0 ; V_20 -> V_3 = 0 ;
F_25 ( & V_19 -> V_27 ) ;
F_25 ( & V_20 -> V_27 ) ;
}
}
return V_10 ;
}
static void F_26 ( struct V_9 * V_10 )
{
struct V_5 * V_19 = & V_10 -> V_14 [ 0 ] , * V_20 = & V_10 -> V_14 [ 1 ] ;
F_8 ( V_10 , V_26 ) ;
F_3 ( ! F_13 ( & V_10 -> V_24 ) ) ;
F_10 ( & V_10 -> V_17 ) ;
F_3 ( V_19 -> V_3 != 0 || F_23 ( & V_19 -> V_27 ) ) ;
F_3 ( V_20 -> V_3 != 0 || F_23 ( & V_20 -> V_27 ) ) ;
F_27 ( V_10 , V_26 ) ;
F_16 ( & V_10 -> V_17 ) ;
F_12 ( & V_22 ) ;
F_28 ( & V_10 -> V_24 , & V_23 ) ;
V_25 ++ ;
F_16 ( & V_22 ) ;
}
static unsigned F_29 ( struct V_5 * V_6 )
{
unsigned V_3 ;
F_8 ( V_6 , V_16 ) ;
F_3 ( ! F_23 ( & V_6 -> V_27 ) ) ;
V_3 = V_6 -> V_3 ;
F_3 ( V_6 -> V_3 == 0 || V_6 -> V_3 > F_1 () ) ;
V_6 -> V_3 = 0 ;
F_25 ( & V_6 -> V_27 ) ;
F_27 ( V_6 , V_16 ) ;
V_29 -= V_3 ;
F_30 ( & V_30 ) ;
return V_3 ;
}
static void F_31 ( struct V_5 * V_6 )
{
unsigned V_31 ;
struct V_5 * V_32 ;
unsigned V_11 = F_4 ( V_6 ) , V_3 ;
struct V_9 * V_10 =
F_9 ( V_6 , struct V_9 , V_14 [ V_11 ] ) ;
F_12 ( & V_10 -> V_17 ) ;
if ( F_13 ( & V_10 -> V_24 ) ) {
F_16 ( & V_10 -> V_17 ) ;
return;
}
V_3 = F_29 ( V_6 ) ;
F_10 ( & V_10 -> V_17 ) ;
V_32 = & V_10 -> V_14 [ ( V_11 == 0 ) ? 1 : 0 ] ;
if ( V_32 -> V_3 == 0 ) {
V_31 = F_2 ( V_3 ) ;
F_12 ( & V_33 ) ;
F_3 ( F_13 ( & V_34 [ V_31 ] . V_35 ) ) ;
F_15 ( & V_10 -> V_24 ) ;
V_34 [ V_31 ] . V_36 -- ;
F_16 ( & V_33 ) ;
F_26 ( V_10 ) ;
} else {
V_31 = F_2 ( V_32 -> V_3 ) ;
F_12 ( & V_33 ) ;
F_15 ( & V_10 -> V_24 ) ;
V_37 -- ;
F_32 ( & V_10 -> V_24 , & V_34 [ V_31 ] . V_35 ) ;
V_34 [ V_31 ] . V_36 ++ ;
F_16 ( & V_33 ) ;
F_16 ( & V_10 -> V_17 ) ;
}
}
static struct V_5 * F_33 ( T_1 V_38 , struct V_39 * V_27 ,
T_1 V_40 , struct V_41 * V_41 ,
void * V_42 , unsigned V_3 )
{
struct V_5 * V_19 , * V_20 , * V_6 = NULL ;
struct V_9 * V_10 = NULL , * V_43 ;
unsigned V_44 ;
char * V_45 ;
int V_12 , V_46 = 0 ;
V_44 = F_2 ( V_3 ) ;
for ( V_12 = V_1 - V_44 + 1 ; V_12 > 0 ; V_12 -- ) {
F_12 ( & V_33 ) ;
if ( ! F_13 ( & V_34 [ V_12 ] . V_35 ) ) {
F_34 (zbpg, ztmp,
&zbud_unbuddied[i].list, bud_list) {
if ( F_35 ( & V_10 -> V_17 ) ) {
V_46 = V_12 ;
goto V_47;
}
}
}
F_16 ( & V_33 ) ;
}
V_10 = F_11 () ;
if ( F_36 ( V_10 == NULL ) )
goto V_48;
F_12 ( & V_10 -> V_17 ) ;
F_12 ( & V_33 ) ;
F_32 ( & V_10 -> V_24 , & V_34 [ V_44 ] . V_35 ) ;
V_34 [ V_44 ] . V_36 ++ ;
V_6 = & V_10 -> V_14 [ 0 ] ;
goto V_49;
V_47:
F_10 ( & V_10 -> V_17 ) ;
V_19 = & V_10 -> V_14 [ 0 ] ; V_20 = & V_10 -> V_14 [ 1 ] ;
F_3 ( ! ( ( V_19 -> V_3 == 0 ) ^ ( V_20 -> V_3 == 0 ) ) ) ;
if ( V_19 -> V_3 != 0 ) {
F_8 ( V_19 , V_16 ) ;
V_6 = V_20 ;
} else if ( V_20 -> V_3 != 0 ) {
F_8 ( V_20 , V_16 ) ;
V_6 = V_19 ;
} else
F_37 () ;
F_15 ( & V_10 -> V_24 ) ;
V_34 [ V_46 ] . V_36 -- ;
F_32 ( & V_10 -> V_24 , & V_50 ) ;
V_37 ++ ;
V_49:
F_22 ( V_6 , V_16 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_40 = V_40 ;
V_6 -> V_27 = * V_27 ;
V_6 -> V_38 = V_38 ;
F_16 ( & V_33 ) ;
V_45 = F_7 ( V_6 , V_3 ) ;
memcpy ( V_45 , V_42 , V_3 ) ;
F_16 ( & V_10 -> V_17 ) ;
V_51 [ V_44 ] ++ ;
F_24 ( & V_30 ) ;
V_52 ++ ;
V_29 += V_3 ;
V_53 += V_3 ;
V_48:
return V_6 ;
}
static int F_38 ( struct V_41 * V_41 , struct V_5 * V_6 )
{
struct V_9 * V_10 ;
unsigned V_11 = F_4 ( V_6 ) ;
T_2 V_54 = V_8 ;
char * V_55 , * V_56 ;
unsigned V_3 ;
int V_57 = 0 ;
V_10 = F_9 ( V_6 , struct V_9 , V_14 [ V_11 ] ) ;
F_12 ( & V_10 -> V_17 ) ;
if ( F_13 ( & V_10 -> V_24 ) ) {
V_57 = - V_58 ;
goto V_48;
}
F_8 ( V_6 , V_16 ) ;
F_3 ( V_6 -> V_3 == 0 || V_6 -> V_3 > F_1 () ) ;
V_55 = F_39 ( V_41 , V_59 ) ;
V_3 = V_6 -> V_3 ;
V_56 = F_7 ( V_6 , V_3 ) ;
V_57 = F_40 ( V_56 , V_3 , V_55 , & V_54 ) ;
F_3 ( V_57 != V_60 ) ;
F_3 ( V_54 != V_8 ) ;
F_41 ( V_55 , V_59 ) ;
V_48:
F_16 ( & V_10 -> V_17 ) ;
return V_57 ;
}
static void F_42 ( struct V_9 * V_10 )
{
struct V_5 * V_6 ;
int V_12 , V_61 ;
T_1 V_38 [ V_13 ] , V_40 [ V_13 ] ;
struct V_39 V_27 [ V_13 ] ;
struct V_62 * V_63 ;
F_10 ( & V_10 -> V_17 ) ;
F_3 ( ! F_13 ( & V_10 -> V_24 ) ) ;
for ( V_12 = 0 , V_61 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_6 = & V_10 -> V_14 [ V_12 ] ;
if ( V_6 -> V_3 ) {
V_38 [ V_61 ] = V_6 -> V_38 ;
V_27 [ V_61 ] = V_6 -> V_27 ;
V_40 [ V_61 ] = V_6 -> V_40 ;
V_61 ++ ;
F_29 ( V_6 ) ;
}
}
F_16 ( & V_10 -> V_17 ) ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 ++ ) {
V_63 = F_43 ( V_38 [ V_12 ] ) ;
if ( V_63 != NULL ) {
F_44 ( V_63 , & V_27 [ V_12 ] , V_40 [ V_12 ] ) ;
F_45 ( V_63 ) ;
}
}
F_8 ( V_10 , V_26 ) ;
F_12 ( & V_10 -> V_17 ) ;
F_26 ( V_10 ) ;
}
static void F_46 ( int V_64 )
{
struct V_9 * V_10 ;
int V_12 ;
V_65:
F_47 ( & V_22 ) ;
if ( ! F_13 ( & V_23 ) ) {
V_10 = F_14 ( & V_23 ,
struct V_9 , V_24 ) ;
F_15 ( & V_10 -> V_24 ) ;
V_25 -- ;
F_30 ( & V_28 ) ;
F_48 ( & V_22 ) ;
F_49 ( V_10 ) ;
V_66 ++ ;
if ( -- V_64 <= 0 )
goto V_48;
goto V_65;
}
F_48 ( & V_22 ) ;
for ( V_12 = 0 ; V_12 < V_1 ; V_12 ++ ) {
V_67:
F_47 ( & V_33 ) ;
if ( F_13 ( & V_34 [ V_12 ] . V_35 ) ) {
F_48 ( & V_33 ) ;
continue;
}
F_50 (zbpg, &zbud_unbuddied[i].list, bud_list) {
if ( F_36 ( ! F_35 ( & V_10 -> V_17 ) ) )
continue;
F_15 ( & V_10 -> V_24 ) ;
V_34 [ V_12 ] . V_36 -- ;
F_16 ( & V_33 ) ;
V_68 ++ ;
F_42 ( V_10 ) ;
F_51 () ;
if ( -- V_64 <= 0 )
goto V_48;
goto V_67;
}
F_48 ( & V_33 ) ;
}
V_69:
F_47 ( & V_33 ) ;
if ( F_13 ( & V_50 ) ) {
F_48 ( & V_33 ) ;
goto V_48;
}
F_50 (zbpg, &zbud_buddied_list, bud_list) {
if ( F_36 ( ! F_35 ( & V_10 -> V_17 ) ) )
continue;
F_15 ( & V_10 -> V_24 ) ;
V_37 -- ;
F_16 ( & V_33 ) ;
V_70 ++ ;
F_42 ( V_10 ) ;
F_51 () ;
if ( -- V_64 <= 0 )
goto V_48;
goto V_69;
}
F_48 ( & V_33 ) ;
V_48:
return;
}
static void F_52 ( void )
{
int V_12 ;
F_19 ( & V_50 ) ;
V_37 = 0 ;
for ( V_12 = 0 ; V_12 < V_71 ; V_12 ++ ) {
F_19 ( & V_34 [ V_12 ] . V_35 ) ;
V_34 [ V_12 ] . V_36 = 0 ;
}
}
static int F_53 ( char * V_72 )
{
int V_12 ;
char * V_15 = V_72 ;
for ( V_12 = 0 ; V_12 < V_71 - 1 ; V_12 ++ )
V_15 += sprintf ( V_15 , L_1 , V_34 [ V_12 ] . V_36 ) ;
V_15 += sprintf ( V_15 , L_2 , V_34 [ V_12 ] . V_36 ) ;
return V_15 - V_72 ;
}
static int F_54 ( char * V_72 )
{
unsigned long V_12 , V_31 = 0 , V_73 = 0 , V_74 = 0 ;
unsigned long V_75 = 0 , V_76 = 0 ;
unsigned long V_77 = 0 ;
char * V_15 = V_72 ;
for ( V_12 = 0 ; V_12 < V_71 ; V_12 ++ ) {
V_15 += sprintf ( V_15 , L_3 , V_51 [ V_12 ] ) ;
V_31 += V_51 [ V_12 ] ;
V_73 += V_51 [ V_12 ] ;
V_74 += V_12 * V_51 [ V_12 ] ;
if ( V_12 == 21 )
V_75 = V_73 ;
if ( V_12 == 32 )
V_76 = V_73 ;
if ( V_12 == 42 )
V_77 = V_73 ;
}
V_15 += sprintf ( V_15 , L_4 ,
V_75 , V_76 , V_77 ,
V_31 == 0 ? 0 : V_74 / V_31 ) ;
return V_15 - V_72 ;
}
static struct V_78 * F_55 ( struct V_79 * V_80 , T_1 V_38 ,
struct V_39 * V_27 , T_1 V_40 ,
void * V_42 , unsigned V_81 )
{
struct V_41 * V_41 ;
struct V_78 * V_82 = NULL ;
T_1 V_7 ;
int V_57 ;
F_3 ( ! F_56 () ) ;
V_57 = F_57 ( V_80 , V_81 + sizeof( struct V_78 ) ,
& V_41 , & V_7 , V_83 ) ;
if ( F_36 ( V_57 ) )
goto V_48;
V_82 = F_39 ( V_41 , V_59 ) + V_7 ;
V_82 -> V_40 = V_40 ;
V_82 -> V_27 = * V_27 ;
V_82 -> V_38 = V_38 ;
F_22 ( V_82 , V_84 ) ;
memcpy ( ( char * ) V_82 + sizeof( struct V_78 ) , V_42 , V_81 ) ;
F_41 ( V_82 , V_59 ) ;
V_48:
return V_82 ;
}
static void F_58 ( struct V_79 * V_80 , struct V_78 * V_82 )
{
unsigned long V_85 ;
struct V_41 * V_41 ;
T_1 V_7 ;
T_3 V_3 ;
F_8 ( V_82 , V_84 ) ;
V_3 = F_59 ( V_82 ) - sizeof( * V_82 ) ;
F_3 ( V_3 == 0 || V_3 > V_86 ) ;
F_27 ( V_82 , V_84 ) ;
V_41 = F_60 ( V_82 ) ;
V_7 = ( unsigned long ) V_82 & ~ V_87 ;
F_61 ( V_85 ) ;
F_62 ( V_80 , V_41 , V_7 ) ;
F_63 ( V_85 ) ;
}
static void F_64 ( struct V_41 * V_41 , struct V_78 * V_82 )
{
T_2 V_81 = V_8 ;
char * V_55 ;
unsigned V_3 ;
int V_57 ;
F_8 ( V_82 , V_84 ) ;
V_3 = F_59 ( V_82 ) - sizeof( * V_82 ) ;
F_3 ( V_3 == 0 || V_3 > V_86 ) ;
V_55 = F_39 ( V_41 , V_59 ) ;
V_57 = F_40 ( ( char * ) V_82 + sizeof( * V_82 ) ,
V_3 , V_55 , & V_81 ) ;
F_41 ( V_55 , V_59 ) ;
F_3 ( V_57 != V_60 ) ;
F_3 ( V_81 != V_8 ) ;
}
static struct V_62 * F_43 ( T_1 V_88 )
{
struct V_62 * V_63 = NULL ;
if ( V_88 >= 0 ) {
V_63 = V_89 . V_90 [ V_88 ] ;
if ( V_63 != NULL )
F_24 ( & V_63 -> V_91 ) ;
}
return V_63 ;
}
static void F_45 ( struct V_62 * V_63 )
{
if ( V_63 != NULL )
F_30 ( & V_63 -> V_91 ) ;
}
static int F_65 ( struct V_62 * V_63 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
void * V_41 ;
int V_57 = - V_98 ;
if ( F_36 ( V_99 == NULL ) )
goto V_48;
if ( F_36 ( V_100 == NULL ) )
goto V_48;
if ( ! F_35 ( & V_101 ) ) {
V_102 ++ ;
goto V_48;
}
F_66 () ;
V_93 = & F_67 ( V_103 ) ;
while ( V_93 -> V_64 < F_68 ( V_93 -> V_104 ) ) {
F_69 () ;
V_95 = F_70 ( V_99 ,
V_83 ) ;
if ( F_36 ( V_95 == NULL ) ) {
V_105 ++ ;
goto V_106;
}
F_66 () ;
V_93 = & F_67 ( V_103 ) ;
if ( V_93 -> V_64 < F_68 ( V_93 -> V_104 ) )
V_93 -> V_104 [ V_93 -> V_64 ++ ] = V_95 ;
else
F_71 ( V_99 , V_95 ) ;
}
F_69 () ;
V_97 = F_70 ( V_100 , V_83 ) ;
if ( F_36 ( V_97 == NULL ) ) {
V_105 ++ ;
goto V_106;
}
V_41 = ( void * ) F_72 ( V_83 ) ;
if ( F_36 ( V_41 == NULL ) ) {
V_107 ++ ;
F_71 ( V_100 , V_97 ) ;
goto V_106;
}
F_66 () ;
V_93 = & F_67 ( V_103 ) ;
if ( V_93 -> V_97 == NULL )
V_93 -> V_97 = V_97 ;
else
F_71 ( V_100 , V_97 ) ;
if ( V_93 -> V_41 == NULL )
V_93 -> V_41 = V_41 ;
else
F_73 ( ( unsigned long ) V_41 ) ;
V_57 = 0 ;
V_106:
F_16 ( & V_101 ) ;
V_48:
return V_57 ;
}
static void * F_17 ( void )
{
struct V_92 * V_93 ;
void * V_41 ;
V_93 = & F_67 ( V_103 ) ;
V_41 = V_93 -> V_41 ;
F_3 ( V_41 == NULL ) ;
V_93 -> V_41 = NULL ;
return V_41 ;
}
static void F_49 ( void * V_15 )
{
F_73 ( ( unsigned long ) V_15 ) ;
}
static struct V_94 * F_74 ( struct V_62 * V_63 )
{
struct V_94 * V_95 = NULL ;
unsigned long V_36 ;
struct V_92 * V_93 ;
V_93 = & F_67 ( V_103 ) ;
if ( V_93 -> V_64 <= 0 )
goto V_48;
V_95 = V_93 -> V_104 [ V_93 -> V_64 - 1 ] ;
F_3 ( V_95 == NULL ) ;
V_93 -> V_104 [ V_93 -> V_64 - 1 ] = NULL ;
V_93 -> V_64 -- ;
V_36 = F_75 ( & V_108 ) ;
if ( V_36 > V_109 )
V_109 = V_36 ;
V_48:
return V_95 ;
}
static void F_76 ( struct V_94 * V_95 ,
struct V_62 * V_63 )
{
F_30 ( & V_108 ) ;
F_3 ( F_77 ( & V_108 ) < 0 ) ;
F_71 ( V_99 , V_95 ) ;
}
static struct V_96 * F_78 ( struct V_62 * V_63 )
{
struct V_96 * V_97 = NULL ;
unsigned long V_36 ;
struct V_92 * V_93 ;
V_93 = & F_67 ( V_103 ) ;
V_97 = V_93 -> V_97 ;
F_3 ( V_97 == NULL ) ;
V_93 -> V_97 = NULL ;
V_36 = F_75 ( & V_110 ) ;
if ( V_36 > V_111 )
V_111 = V_36 ;
return V_97 ;
}
static void F_79 ( struct V_96 * V_97 , struct V_62 * V_63 )
{
F_30 ( & V_110 ) ;
F_3 ( F_77 ( & V_110 ) < 0 ) ;
F_71 ( V_100 , V_97 ) ;
}
static void * F_80 ( struct V_62 * V_63 , struct V_39 * V_27 ,
T_1 V_40 , struct V_41 * V_41 )
{
void * V_112 = NULL , * V_42 ;
T_2 V_81 ;
int V_57 ;
bool V_113 = F_81 ( V_63 ) ;
unsigned long V_36 ;
if ( V_113 ) {
V_57 = F_82 ( V_41 , & V_42 , & V_81 ) ;
if ( V_57 == 0 )
goto V_48;
if ( V_81 == 0 || V_81 > F_1 () ) {
V_114 ++ ;
goto V_48;
}
V_112 = ( void * ) F_33 ( V_63 -> V_38 , V_27 , V_40 ,
V_41 , V_42 , V_81 ) ;
if ( V_112 != NULL ) {
V_36 = F_75 ( & V_115 ) ;
if ( V_36 > V_116 )
V_116 = V_36 ;
}
} else {
if ( F_77 ( & V_117 ) >
3 * V_118 / 4 )
goto V_48;
V_57 = F_82 ( V_41 , & V_42 , & V_81 ) ;
if ( V_57 == 0 )
goto V_48;
if ( V_81 > V_86 ) {
V_114 ++ ;
goto V_48;
}
V_112 = ( void * ) F_55 ( V_89 . V_80 , V_63 -> V_38 ,
V_27 , V_40 , V_42 , V_81 ) ;
if ( V_112 == NULL )
goto V_48;
V_36 = F_75 ( & V_117 ) ;
if ( V_36 > V_119 )
V_119 = V_36 ;
}
V_48:
return V_112 ;
}
static int F_83 ( struct V_41 * V_41 , void * V_112 ,
struct V_62 * V_63 )
{
int V_57 = 0 ;
if ( F_81 ( V_63 ) )
V_57 = F_38 ( V_41 , V_112 ) ;
else
F_64 ( V_41 , V_112 ) ;
return V_57 ;
}
static void F_84 ( void * V_112 , struct V_62 * V_63 )
{
if ( F_81 ( V_63 ) ) {
F_31 ( (struct V_5 * ) V_112 ) ;
F_30 ( & V_115 ) ;
F_3 ( F_77 ( & V_115 ) < 0 ) ;
} else {
F_58 ( V_89 . V_80 , (struct V_78 * ) V_112 ) ;
F_30 ( & V_117 ) ;
F_3 ( F_77 ( & V_117 ) < 0 ) ;
}
}
static int F_82 ( struct V_41 * V_120 , void * * V_121 , T_2 * V_54 )
{
int V_57 = 0 ;
unsigned char * V_122 = F_67 ( V_123 ) ;
unsigned char * V_124 = F_67 ( V_125 ) ;
char * V_56 ;
F_3 ( ! F_56 () ) ;
if ( F_36 ( V_122 == NULL || V_124 == NULL ) )
goto V_48;
V_56 = F_39 ( V_120 , V_59 ) ;
F_85 () ;
V_57 = F_86 ( V_56 , V_8 , V_122 , V_54 , V_124 ) ;
F_3 ( V_57 != V_60 ) ;
* V_121 = V_122 ;
F_41 ( V_56 , V_59 ) ;
V_57 = 1 ;
V_48:
return V_57 ;
}
static int F_87 ( struct V_126 * V_127 ,
unsigned long V_128 , void * V_129 )
{
int V_130 = ( long ) V_129 ;
struct V_92 * V_93 ;
switch ( V_128 ) {
case V_131 :
F_88 ( V_123 , V_130 ) = ( void * ) F_89 (
V_132 | V_133 ,
V_134 ) ,
F_88 ( V_125 , V_130 ) =
F_90 ( V_135 ,
V_132 | V_133 ) ;
break;
case V_136 :
case V_137 :
F_91 ( ( unsigned long ) F_88 ( V_123 , V_130 ) ,
V_134 ) ;
F_88 ( V_123 , V_130 ) = NULL ;
F_92 ( F_88 ( V_125 , V_130 ) ) ;
F_88 ( V_125 , V_130 ) = NULL ;
V_93 = & F_88 ( V_103 , V_130 ) ;
while ( V_93 -> V_64 ) {
F_71 ( V_99 ,
V_93 -> V_104 [ V_93 -> V_64 - 1 ] ) ;
V_93 -> V_104 [ V_93 -> V_64 - 1 ] = NULL ;
V_93 -> V_64 -- ;
}
F_71 ( V_100 , V_93 -> V_97 ) ;
F_73 ( ( unsigned long ) V_93 -> V_41 ) ;
break;
default:
break;
}
return V_138 ;
}
static int F_93 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
int V_57 = - 1 ;
int V_64 = V_142 -> V_143 ;
T_4 V_144 = V_142 -> V_144 ;
if ( V_64 >= 0 ) {
if ( ! ( V_144 & V_145 ) )
goto V_48;
if ( F_35 ( & V_101 ) ) {
F_46 ( V_64 ) ;
F_16 ( & V_101 ) ;
} else
V_146 ++ ;
}
V_57 = ( int ) F_77 ( & V_28 ) ;
V_48:
return V_57 ;
}
static int F_94 ( int V_38 , struct V_39 * V_147 ,
T_1 V_40 , struct V_41 * V_41 )
{
struct V_62 * V_63 ;
int V_57 = - 1 ;
F_3 ( ! F_56 () ) ;
V_63 = F_43 ( V_38 ) ;
if ( F_36 ( V_63 == NULL ) )
goto V_48;
if ( ! V_148 && F_65 ( V_63 ) == 0 ) {
V_57 = F_95 ( V_63 , V_147 , V_40 , V_41 ) ;
if ( V_57 < 0 ) {
if ( F_81 ( V_63 ) )
V_149 ++ ;
else
V_150 ++ ;
}
F_45 ( V_63 ) ;
F_69 () ;
} else {
V_151 ++ ;
if ( F_77 ( & V_63 -> V_152 ) > 0 )
( void ) F_44 ( V_63 , V_147 , V_40 ) ;
F_45 ( V_63 ) ;
}
V_48:
return V_57 ;
}
static int F_96 ( int V_38 , struct V_39 * V_147 ,
T_1 V_40 , struct V_41 * V_41 )
{
struct V_62 * V_63 ;
int V_57 = - 1 ;
unsigned long V_85 ;
F_61 ( V_85 ) ;
V_63 = F_43 ( V_38 ) ;
if ( F_18 ( V_63 != NULL ) ) {
if ( F_77 ( & V_63 -> V_152 ) > 0 )
V_57 = F_97 ( V_63 , V_147 , V_40 , V_41 ) ;
F_45 ( V_63 ) ;
}
F_63 ( V_85 ) ;
return V_57 ;
}
static int F_98 ( int V_38 , struct V_39 * V_147 , T_1 V_40 )
{
struct V_62 * V_63 ;
int V_57 = - 1 ;
unsigned long V_85 ;
F_61 ( V_85 ) ;
V_153 ++ ;
V_63 = F_43 ( V_38 ) ;
if ( F_18 ( V_63 != NULL ) ) {
if ( F_77 ( & V_63 -> V_152 ) > 0 )
V_57 = F_44 ( V_63 , V_147 , V_40 ) ;
F_45 ( V_63 ) ;
}
if ( V_57 >= 0 )
V_154 ++ ;
F_63 ( V_85 ) ;
return V_57 ;
}
static int F_99 ( int V_38 , struct V_39 * V_147 )
{
struct V_62 * V_63 ;
int V_57 = - 1 ;
unsigned long V_85 ;
F_61 ( V_85 ) ;
V_155 ++ ;
V_63 = F_43 ( V_38 ) ;
if ( F_18 ( V_63 != NULL ) ) {
if ( F_77 ( & V_63 -> V_152 ) > 0 )
V_57 = F_100 ( V_63 , V_147 ) ;
F_45 ( V_63 ) ;
}
if ( V_57 >= 0 )
V_156 ++ ;
F_63 ( V_85 ) ;
return V_57 ;
}
static int F_101 ( int V_38 )
{
struct V_62 * V_63 = NULL ;
int V_57 = - 1 ;
if ( V_38 < 0 )
goto V_48;
V_63 = V_89 . V_90 [ V_38 ] ;
if ( V_63 == NULL )
goto V_48;
V_89 . V_90 [ V_38 ] = NULL ;
while ( F_77 ( & V_63 -> V_91 ) != 0 )
;
F_102 () ;
V_57 = F_103 ( V_63 ) ;
F_51 () ;
F_92 ( V_63 ) ;
F_104 ( L_5 , V_38 ) ;
V_48:
return V_57 ;
}
static int F_105 ( T_1 V_85 )
{
int V_88 = - 1 ;
struct V_62 * V_63 ;
V_63 = F_106 ( sizeof( struct V_62 ) , V_132 ) ;
if ( V_63 == NULL ) {
F_104 ( L_6 ) ;
goto V_48;
}
for ( V_88 = 0 ; V_88 < V_157 ; V_88 ++ )
if ( V_89 . V_90 [ V_88 ] == NULL )
break;
if ( V_88 >= V_157 ) {
F_104 ( L_7 ) ;
F_92 ( V_63 ) ;
V_88 = - 1 ;
goto V_48;
}
F_107 ( & V_63 -> V_91 , 0 ) ;
V_63 -> V_158 = & V_89 ;
V_63 -> V_38 = V_88 ;
F_108 ( V_63 , V_85 ) ;
V_89 . V_90 [ V_88 ] = V_63 ;
F_104 ( L_8 ,
V_85 & V_159 ? L_9 : L_10 ,
V_88 ) ;
V_48:
return V_88 ;
}
static void F_109 ( int V_38 ,
struct V_160 V_161 ,
T_5 V_40 , struct V_41 * V_41 )
{
T_6 V_162 = ( T_6 ) V_40 ;
struct V_39 V_27 = * (struct V_39 * ) & V_161 ;
if ( F_18 ( V_162 == V_40 ) )
( void ) F_94 ( V_38 , & V_27 , V_40 , V_41 ) ;
}
static int F_110 ( int V_38 ,
struct V_160 V_161 ,
T_5 V_40 , struct V_41 * V_41 )
{
T_6 V_162 = ( T_6 ) V_40 ;
struct V_39 V_27 = * (struct V_39 * ) & V_161 ;
int V_57 = - 1 ;
if ( F_18 ( V_162 == V_40 ) )
V_57 = F_96 ( V_38 , & V_27 , V_40 , V_41 ) ;
return V_57 ;
}
static void F_111 ( int V_38 ,
struct V_160 V_161 ,
T_5 V_40 )
{
T_6 V_162 = ( T_6 ) V_40 ;
struct V_39 V_27 = * (struct V_39 * ) & V_161 ;
if ( F_18 ( V_162 == V_40 ) )
( void ) F_98 ( V_38 , & V_27 , V_162 ) ;
}
static void F_112 ( int V_38 ,
struct V_160 V_161 )
{
struct V_39 V_27 = * (struct V_39 * ) & V_161 ;
( void ) F_99 ( V_38 , & V_27 ) ;
}
static void F_113 ( int V_38 )
{
if ( V_38 >= 0 )
( void ) F_101 ( V_38 ) ;
}
static int F_114 ( T_2 V_163 )
{
F_3 ( sizeof( struct V_160 ) !=
sizeof( struct V_39 ) ) ;
F_3 ( V_163 != V_8 ) ;
return F_105 ( 0 ) ;
}
static int F_115 ( char * V_164 , T_2 V_163 )
{
F_3 ( sizeof( struct V_160 ) !=
sizeof( struct V_39 ) ) ;
F_3 ( V_163 != V_8 ) ;
return F_105 ( 0 ) ;
}
struct V_165 F_116 ( void )
{
struct V_165 V_166 =
F_117 ( & V_167 ) ;
return V_166 ;
}
static inline struct V_39 F_118 ( unsigned type , T_6 V_162 )
{
struct V_39 V_27 = { . V_27 = { 0 } } ;
V_27 . V_27 [ 0 ] = F_119 ( type , V_162 ) ;
return V_27 ;
}
static int F_120 ( unsigned type , T_5 V_7 ,
struct V_41 * V_41 )
{
T_7 V_168 = ( T_7 ) V_7 ;
T_6 V_162 = ( T_6 ) V_7 ;
struct V_39 V_27 = F_118 ( type , V_162 ) ;
int V_57 = - 1 ;
unsigned long V_85 ;
F_3 ( ! F_121 ( V_41 ) ) ;
if ( F_18 ( V_168 == V_162 ) ) {
F_61 ( V_85 ) ;
V_57 = F_94 ( V_169 , & V_27 ,
F_122 ( V_162 ) , V_41 ) ;
F_63 ( V_85 ) ;
}
return V_57 ;
}
static int F_123 ( unsigned type , T_5 V_7 ,
struct V_41 * V_41 )
{
T_7 V_168 = ( T_7 ) V_7 ;
T_6 V_162 = ( T_6 ) V_7 ;
struct V_39 V_27 = F_118 ( type , V_162 ) ;
int V_57 = - 1 ;
F_3 ( ! F_121 ( V_41 ) ) ;
if ( F_18 ( V_168 == V_162 ) )
V_57 = F_96 ( V_169 , & V_27 ,
F_122 ( V_162 ) , V_41 ) ;
return V_57 ;
}
static void F_124 ( unsigned type , T_5 V_7 )
{
T_7 V_168 = ( T_7 ) V_7 ;
T_6 V_162 = ( T_6 ) V_7 ;
struct V_39 V_27 = F_118 ( type , V_162 ) ;
if ( F_18 ( V_168 == V_162 ) )
( void ) F_98 ( V_169 , & V_27 ,
F_122 ( V_162 ) ) ;
}
static void F_125 ( unsigned type )
{
struct V_39 V_27 ;
int V_162 ;
for ( V_162 = V_170 ; V_162 >= 0 ; V_162 -- ) {
V_27 = F_118 ( type , V_162 ) ;
( void ) F_99 ( V_169 , & V_27 ) ;
}
}
static void F_126 ( unsigned V_171 )
{
if ( V_169 < 0 )
V_169 = F_105 ( V_159 ) ;
}
struct V_172 F_127 ( void )
{
struct V_172 V_166 =
F_128 ( & V_173 ) ;
return V_166 ;
}
static int T_8 F_129 ( char * V_174 )
{
V_175 = 1 ;
return 1 ;
}
static int T_8 F_130 ( char * V_174 )
{
V_176 = 0 ;
return 1 ;
}
static int T_8 F_131 ( char * V_174 )
{
V_177 = 0 ;
return 1 ;
}
static int T_8 F_132 ( void )
{
#ifdef F_133
int V_57 = 0 ;
V_57 = F_134 ( V_178 , & V_179 ) ;
if ( V_57 ) {
F_135 ( L_11 ) ;
goto V_48;
}
#endif
#if F_136 ( V_180 ) || F_136 ( V_181 )
if ( V_175 ) {
unsigned int V_130 ;
F_137 ( & V_182 ) ;
F_138 ( & V_183 ) ;
V_57 = F_139 ( & V_184 ) ;
if ( V_57 ) {
F_135 ( L_12 ) ;
goto V_48;
}
F_140 (cpu) {
void * V_129 = ( void * ) ( long ) V_130 ;
F_87 ( & V_184 ,
V_131 , V_129 ) ;
}
}
V_99 = F_141 ( L_13 ,
sizeof( struct V_94 ) , 0 , 0 , NULL ) ;
V_100 = F_141 ( L_14 ,
sizeof( struct V_96 ) , 0 , 0 , NULL ) ;
#endif
#ifdef V_180
if ( V_175 && V_176 ) {
struct V_165 V_166 ;
F_52 () ;
F_142 ( & V_185 ) ;
V_166 = F_116 () ;
F_104 ( L_15
L_16 ) ;
if ( V_166 . V_186 != NULL )
F_143 ( L_17 ) ;
}
#endif
#ifdef V_181
if ( V_175 && V_177 ) {
struct V_172 V_166 ;
V_89 . V_80 = F_144 () ;
if ( V_89 . V_80 == NULL ) {
F_135 ( L_18 ) ;
goto V_48;
}
V_166 = F_127 () ;
F_104 ( L_19
L_20 ) ;
if ( V_166 . V_187 != NULL )
F_143 ( L_21 ) ;
}
#endif
V_48:
return V_57 ;
}
