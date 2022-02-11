static inline void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
V_2 -> V_3 = V_3 ;
}
struct V_1 * F_2 ( unsigned V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list) {
if ( V_6 -> V_9 <= V_4 &&
V_6 -> V_9 + V_6 -> V_10 > V_4 ) {
F_5 ( & V_8 , V_7 ) ;
return & V_6 -> V_11 [ V_4 - V_6 -> V_9 ] ;
}
}
F_5 ( & V_8 , V_7 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( 1 , L_1 , V_4 ) ;
return NULL ;
}
struct V_1 * F_8 ( struct V_12 * V_13 ,
T_1 V_14 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
if ( V_14 >= V_6 -> V_10 )
return F_9 ( - V_16 ) ;
return & V_6 -> V_11 [ V_14 ] ;
}
int F_10 ( const struct V_1 * V_17 )
{
return V_17 -> V_6 -> V_9 + ( V_17 - & V_17 -> V_6 -> V_11 [ 0 ] ) ;
}
struct V_12 * F_11 ( const struct V_1 * V_17 )
{
if ( ! V_17 || ! V_17 -> V_6 || ! V_17 -> V_6 -> V_13 )
return NULL ;
return V_17 -> V_6 -> V_13 ;
}
static int F_12 ( int V_10 )
{
struct V_5 * V_6 ;
int V_9 = V_18 - V_10 ;
F_13 (gdev, &gpio_devices, list) {
if ( V_6 -> V_9 + V_6 -> V_10 <= V_9 )
break;
else
V_9 = V_6 -> V_9 - V_10 ;
}
if ( F_6 ( V_9 ) ) {
F_14 ( L_2 , V_19 , V_9 ) ;
return V_9 ;
} else {
F_15 ( L_3 , V_19 ) ;
return - V_20 ;
}
}
int F_16 ( struct V_1 * V_17 )
{
struct V_12 * V_13 ;
unsigned V_21 ;
int V_22 = - V_16 ;
V_13 = F_11 ( V_17 ) ;
V_21 = F_17 ( V_17 ) ;
if ( ! V_13 -> V_23 )
return V_22 ;
V_22 = V_13 -> V_23 ( V_13 , V_21 ) ;
if ( V_22 > 0 ) {
V_22 = 1 ;
F_18 ( V_24 , & V_17 -> V_7 ) ;
}
if ( V_22 == 0 ) {
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
return V_22 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_5 * V_25 , * V_26 ;
if ( F_21 ( & V_27 ) ) {
F_22 ( & V_6 -> V_28 , & V_27 ) ;
return 0 ;
}
V_26 = F_23 ( V_27 . V_26 , struct V_5 , V_28 ) ;
if ( V_6 -> V_9 + V_6 -> V_10 <= V_26 -> V_9 ) {
F_24 ( & V_6 -> V_28 , & V_27 ) ;
return 0 ;
}
V_25 = F_23 ( V_27 . V_25 , struct V_5 , V_28 ) ;
if ( V_25 -> V_9 + V_25 -> V_10 <= V_6 -> V_9 ) {
F_22 ( & V_6 -> V_28 , & V_27 ) ;
return 0 ;
}
F_25 (prev, next, &gpio_devices, list) {
if ( & V_26 -> V_28 == & V_27 )
break;
if ( V_25 -> V_9 + V_25 -> V_10 <= V_6 -> V_9
&& V_6 -> V_9 + V_6 -> V_10 <= V_26 -> V_9 ) {
F_24 ( & V_6 -> V_28 , & V_25 -> V_28 ) ;
return 0 ;
}
}
F_26 ( & V_6 -> V_29 , L_4 ) ;
return - V_30 ;
}
static struct V_1 * F_27 ( const char * const V_31 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list) {
int V_32 ;
for ( V_32 = 0 ; V_32 != V_6 -> V_10 ; ++ V_32 ) {
struct V_1 * V_17 = & V_6 -> V_11 [ V_32 ] ;
if ( ! V_17 -> V_31 || ! V_31 )
continue;
if ( ! strcmp ( V_17 -> V_31 , V_31 ) ) {
F_5 ( & V_8 , V_7 ) ;
return V_17 ;
}
}
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static int F_28 ( struct V_12 * V_33 )
{
struct V_5 * V_6 = V_33 -> V_15 ;
int V_32 ;
if ( ! V_33 -> V_34 )
return 0 ;
for ( V_32 = 0 ; V_32 != V_33 -> V_10 ; ++ V_32 ) {
struct V_1 * V_4 ;
V_4 = F_27 ( V_33 -> V_34 [ V_32 ] ) ;
if ( V_4 )
F_29 ( & V_6 -> V_29 ,
L_5 ,
V_33 -> V_34 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 != V_33 -> V_10 ; ++ V_32 )
V_6 -> V_11 [ V_32 ] . V_31 = V_33 -> V_34 [ V_32 ] ;
return 0 ;
}
static long F_30 ( struct V_35 * V_36 , unsigned int V_37 , unsigned long V_38 )
{
struct V_5 * V_6 = V_36 -> V_39 ;
struct V_12 * V_13 = V_6 -> V_13 ;
int T_2 * V_40 = ( int T_2 * ) V_38 ;
if ( ! V_13 )
return - V_41 ;
if ( V_37 == V_42 ) {
struct V_43 V_44 ;
strncpy ( V_44 . V_31 , F_31 ( & V_6 -> V_29 ) ,
sizeof( V_44 . V_31 ) ) ;
V_44 . V_31 [ sizeof( V_44 . V_31 ) - 1 ] = '\0' ;
strncpy ( V_44 . V_3 , V_6 -> V_3 ,
sizeof( V_44 . V_3 ) ) ;
V_44 . V_3 [ sizeof( V_44 . V_3 ) - 1 ] = '\0' ;
V_44 . V_45 = V_6 -> V_10 ;
if ( F_32 ( V_40 , & V_44 , sizeof( V_44 ) ) )
return - V_46 ;
return 0 ;
} else if ( V_37 == V_47 ) {
struct V_48 V_49 ;
struct V_1 * V_17 ;
if ( F_33 ( & V_49 , V_40 , sizeof( V_49 ) ) )
return - V_46 ;
if ( V_49 . V_50 > V_6 -> V_10 )
return - V_16 ;
V_17 = & V_6 -> V_11 [ V_49 . V_50 ] ;
if ( V_17 -> V_31 ) {
strncpy ( V_49 . V_31 , V_17 -> V_31 ,
sizeof( V_49 . V_31 ) ) ;
V_49 . V_31 [ sizeof( V_49 . V_31 ) - 1 ] = '\0' ;
} else {
V_49 . V_31 [ 0 ] = '\0' ;
}
if ( V_17 -> V_3 ) {
strncpy ( V_49 . V_51 , V_17 -> V_3 ,
sizeof( V_49 . V_51 ) ) ;
V_49 . V_51 [ sizeof( V_49 . V_51 ) - 1 ] = '\0' ;
} else {
V_49 . V_51 [ 0 ] = '\0' ;
}
V_49 . V_7 = 0 ;
if ( F_34 ( V_52 , & V_17 -> V_7 ) ||
F_34 ( V_53 , & V_17 -> V_7 ) ||
F_34 ( V_54 , & V_17 -> V_7 ) ||
F_34 ( V_55 , & V_17 -> V_7 ) ||
F_34 ( V_56 , & V_17 -> V_7 ) )
V_49 . V_7 |= V_57 ;
if ( F_34 ( V_24 , & V_17 -> V_7 ) )
V_49 . V_7 |= V_58 ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_49 . V_7 |= V_60 ;
if ( F_34 ( V_61 , & V_17 -> V_7 ) )
V_49 . V_7 |= V_62 ;
if ( F_34 ( V_63 , & V_17 -> V_7 ) )
V_49 . V_7 |= V_64 ;
if ( F_32 ( V_40 , & V_49 , sizeof( V_49 ) ) )
return - V_46 ;
return 0 ;
}
return - V_16 ;
}
static int F_35 ( struct V_65 * V_65 , struct V_35 * V_36 )
{
struct V_5 * V_6 = F_36 ( V_65 -> V_66 ,
struct V_5 , V_67 ) ;
if ( ! V_6 || ! V_6 -> V_13 )
return - V_41 ;
F_37 ( & V_6 -> V_29 ) ;
V_36 -> V_39 = V_6 ;
return 0 ;
}
static int F_38 ( struct V_65 * V_65 , struct V_35 * V_36 )
{
struct V_5 * V_6 = F_36 ( V_65 -> V_66 ,
struct V_5 , V_67 ) ;
if ( ! V_6 )
return - V_41 ;
F_39 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_40 ( struct V_68 * V_29 )
{
struct V_5 * V_6 = F_41 ( V_29 ) ;
F_42 ( & V_6 -> V_67 ) ;
F_43 ( & V_6 -> V_28 ) ;
F_44 ( & V_69 , V_6 -> V_70 ) ;
F_45 ( V_6 -> V_3 ) ;
F_45 ( V_6 -> V_11 ) ;
F_45 ( V_6 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
int V_22 ;
F_47 ( & V_6 -> V_67 , & V_71 ) ;
V_6 -> V_67 . V_72 = V_73 ;
V_6 -> V_67 . V_74 . V_75 = & V_6 -> V_29 . V_74 ;
V_6 -> V_29 . V_76 = F_48 ( F_49 ( V_77 ) , V_6 -> V_70 ) ;
V_22 = F_50 ( & V_6 -> V_67 , V_6 -> V_29 . V_76 , 1 ) ;
if ( V_22 < 0 )
F_51 ( V_6 -> V_13 , L_6 ,
F_49 ( V_77 ) , V_6 -> V_70 ) ;
else
F_52 ( V_6 -> V_13 , L_7 ,
F_49 ( V_77 ) , V_6 -> V_70 ) ;
V_22 = F_53 ( & V_6 -> V_29 ) ;
if ( V_22 )
goto V_78;
V_22 = F_54 ( V_6 ) ;
if ( V_22 )
goto V_79;
V_6 -> V_29 . V_80 = F_40 ;
F_37 ( & V_6 -> V_29 ) ;
F_14 ( L_8 ,
V_19 , V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
F_31 ( & V_6 -> V_29 ) , V_6 -> V_13 -> V_3 ? : L_9 ) ;
return 0 ;
V_79:
F_55 ( & V_6 -> V_29 ) ;
V_78:
F_42 ( & V_6 -> V_67 ) ;
return V_22 ;
}
static void F_56 ( void )
{
struct V_5 * V_6 ;
int V_81 ;
F_4 (gdev, &gpio_devices, list) {
V_81 = F_46 ( V_6 ) ;
if ( V_81 )
F_15 ( L_10 ,
F_31 ( & V_6 -> V_29 ) , V_81 ) ;
}
}
int F_57 ( struct V_12 * V_13 , void * V_82 )
{
unsigned long V_7 ;
int V_22 = 0 ;
unsigned V_32 ;
int V_9 = V_13 -> V_9 ;
struct V_5 * V_6 ;
V_6 = F_58 ( sizeof( * V_6 ) , V_83 ) ;
if ( ! V_6 )
return - V_84 ;
V_6 -> V_29 . V_85 = & V_86 ;
V_6 -> V_13 = V_13 ;
V_13 -> V_15 = V_6 ;
if ( V_13 -> V_75 ) {
V_6 -> V_29 . V_75 = V_13 -> V_75 ;
V_6 -> V_29 . V_87 = V_13 -> V_75 -> V_87 ;
} else {
#ifdef F_59
if ( V_13 -> V_87 )
V_6 -> V_29 . V_87 = V_13 -> V_87 ;
#endif
}
V_6 -> V_70 = F_60 ( & V_69 , 0 , 0 , V_83 ) ;
if ( V_6 -> V_70 < 0 ) {
V_22 = V_6 -> V_70 ;
goto V_88;
}
F_61 ( & V_6 -> V_29 , L_11 , V_6 -> V_70 ) ;
F_62 ( & V_6 -> V_29 ) ;
F_63 ( & V_6 -> V_29 , V_6 ) ;
if ( V_13 -> V_75 && V_13 -> V_75 -> V_89 )
V_6 -> V_72 = V_13 -> V_75 -> V_89 -> V_72 ;
else if ( V_13 -> V_72 )
V_6 -> V_72 = V_13 -> V_72 ;
else
V_6 -> V_72 = V_73 ;
V_6 -> V_11 = F_64 ( V_13 -> V_10 , sizeof( V_6 -> V_11 [ 0 ] ) , V_83 ) ;
if ( ! V_6 -> V_11 ) {
V_22 = - V_84 ;
goto V_88;
}
if ( V_13 -> V_10 == 0 ) {
F_65 ( V_13 , L_12 ) ;
V_22 = - V_16 ;
goto V_90;
}
if ( V_13 -> V_3 )
V_6 -> V_3 = F_66 ( V_13 -> V_3 , V_83 ) ;
else
V_6 -> V_3 = F_66 ( L_13 , V_83 ) ;
if ( ! V_6 -> V_3 ) {
V_22 = - V_84 ;
goto V_90;
}
V_6 -> V_10 = V_13 -> V_10 ;
V_6 -> V_82 = V_82 ;
F_3 ( & V_8 , V_7 ) ;
if ( V_9 < 0 ) {
V_9 = F_12 ( V_13 -> V_10 ) ;
if ( V_9 < 0 ) {
V_22 = V_9 ;
F_5 ( & V_8 , V_7 ) ;
goto V_91;
}
V_13 -> V_9 = V_9 ;
}
V_6 -> V_9 = V_9 ;
V_22 = F_20 ( V_6 ) ;
if ( V_22 ) {
F_5 ( & V_8 , V_7 ) ;
goto V_91;
}
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
struct V_1 * V_17 = & V_6 -> V_11 [ V_32 ] ;
V_17 -> V_6 = V_6 ;
V_17 -> V_7 = ! V_13 -> V_92 ? ( 1 << V_24 ) : 0 ;
}
F_5 ( & V_8 , V_7 ) ;
#ifdef F_67
F_68 ( & V_6 -> V_93 ) ;
#endif
V_22 = F_28 ( V_13 ) ;
if ( V_22 )
goto V_94;
V_22 = F_69 ( V_13 ) ;
if ( V_22 )
goto V_95;
F_70 ( V_13 ) ;
if ( V_96 ) {
V_22 = F_46 ( V_6 ) ;
if ( V_22 )
goto V_95;
}
return 0 ;
V_95:
F_71 ( V_13 ) ;
F_72 ( V_13 ) ;
F_73 ( V_13 ) ;
V_94:
F_3 ( & V_8 , V_7 ) ;
F_43 ( & V_6 -> V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_91:
F_45 ( V_6 -> V_3 ) ;
V_90:
F_45 ( V_6 -> V_11 ) ;
V_88:
F_44 ( & V_69 , V_6 -> V_70 ) ;
F_15 ( L_14 , V_19 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_13 -> V_3 ? : L_9 ) ;
F_45 ( V_6 ) ;
return V_22 ;
}
void * F_74 ( struct V_12 * V_13 )
{
return V_13 -> V_15 -> V_82 ;
}
void F_75 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
struct V_1 * V_17 ;
unsigned long V_7 ;
unsigned V_32 ;
bool V_97 = false ;
F_76 ( V_6 ) ;
V_6 -> V_13 = NULL ;
F_77 ( V_13 ) ;
F_71 ( V_13 ) ;
F_78 ( V_13 ) ;
F_72 ( V_13 ) ;
F_73 ( V_13 ) ;
V_6 -> V_82 = NULL ;
F_3 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ ) {
V_17 = & V_6 -> V_11 [ V_32 ] ;
if ( F_34 ( V_52 , & V_17 -> V_7 ) )
V_97 = true ;
}
F_5 ( & V_8 , V_7 ) ;
if ( V_97 )
F_79 ( & V_6 -> V_29 ,
L_15 ) ;
F_39 ( & V_6 -> V_29 ) ;
}
static void F_80 ( struct V_68 * V_29 , void * V_98 )
{
struct V_12 * V_13 = * (struct V_12 * * ) V_98 ;
F_75 ( V_13 ) ;
}
static int F_81 ( struct V_68 * V_29 , void * V_98 , void * V_82 )
{
struct V_12 * * V_99 = V_98 ;
if ( ! V_99 || ! * V_99 ) {
F_82 ( ! V_99 || ! * V_99 ) ;
return 0 ;
}
return * V_99 == V_82 ;
}
int F_83 ( struct V_68 * V_29 , struct V_12 * V_13 ,
void * V_82 )
{
struct V_12 * * V_100 ;
int V_101 ;
V_100 = F_84 ( F_80 , sizeof( * V_100 ) ,
V_83 ) ;
if ( ! V_100 )
return - V_84 ;
V_101 = F_57 ( V_13 , V_82 ) ;
if ( V_101 < 0 ) {
F_85 ( V_100 ) ;
return V_101 ;
}
* V_100 = V_13 ;
F_86 ( V_29 , V_100 ) ;
return 0 ;
}
void F_87 ( struct V_68 * V_29 , struct V_12 * V_13 )
{
int V_101 ;
V_101 = F_88 ( V_29 , F_80 ,
F_81 , V_13 ) ;
if ( ! V_101 )
F_82 ( V_101 ) ;
}
struct V_12 * F_89 ( void * V_82 ,
int (* F_90)( struct V_12 * V_13 ,
void * V_82 ) )
{
struct V_5 * V_6 ;
struct V_12 * V_13 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( F_90 ( V_6 -> V_13 , V_82 ) )
break;
if ( & V_6 -> V_28 == & V_27 )
V_13 = NULL ;
else
V_13 = V_6 -> V_13 ;
F_5 ( & V_8 , V_7 ) ;
return V_13 ;
}
static int F_91 ( struct V_12 * V_13 , void * V_82 )
{
const char * V_31 = V_82 ;
return ! strcmp ( V_13 -> V_3 , V_31 ) ;
}
static struct V_12 * F_92 ( const char * V_31 )
{
return F_89 ( ( void * ) V_31 , F_91 ) ;
}
void F_93 ( struct V_12 * V_102 ,
struct V_103 * V_104 ,
int V_105 ,
T_3 V_106 )
{
unsigned int V_21 ;
if ( ! V_102 -> V_107 ) {
F_65 ( V_102 , L_16 ,
V_19 ) ;
return;
}
if ( V_106 ) {
if ( V_102 -> V_108 ) {
F_65 ( V_102 ,
L_17
L_18 ) ;
return;
}
F_94 ( V_105 , V_106 ,
V_102 ) ;
V_102 -> V_109 = V_105 ;
}
for ( V_21 = 0 ; V_21 < V_102 -> V_10 ; V_21 ++ )
F_95 ( F_96 ( V_102 -> V_107 , V_21 ) ,
V_105 ) ;
}
static int F_97 ( struct V_110 * V_2 , unsigned int V_111 ,
T_4 V_112 )
{
struct V_12 * V_13 = V_2 -> V_113 ;
F_98 ( V_111 , V_13 ) ;
F_99 ( V_111 , V_13 -> V_114 ) ;
F_100 ( V_111 , V_13 -> V_104 , V_13 -> V_115 ) ;
if ( V_13 -> V_108 && ! V_13 -> V_116 )
F_101 ( V_111 , 1 ) ;
F_102 ( V_111 ) ;
if ( V_13 -> V_117 != V_118 )
F_103 ( V_111 , V_13 -> V_117 ) ;
return 0 ;
}
static void F_104 ( struct V_110 * V_2 , unsigned int V_111 )
{
struct V_12 * V_13 = V_2 -> V_113 ;
if ( V_13 -> V_108 )
F_101 ( V_111 , 0 ) ;
F_100 ( V_111 , NULL , NULL ) ;
F_98 ( V_111 , NULL ) ;
}
static int F_105 ( struct V_119 * V_2 )
{
struct V_12 * V_13 = F_106 ( V_2 ) ;
if ( ! F_107 ( V_13 -> V_15 -> V_72 ) )
return - V_41 ;
if ( F_108 ( V_13 , V_2 -> V_112 ) ) {
F_65 ( V_13 ,
L_19 ,
V_2 -> V_112 ) ;
F_109 ( V_13 -> V_15 -> V_72 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_110 ( struct V_119 * V_2 )
{
struct V_12 * V_13 = F_106 ( V_2 ) ;
F_111 ( V_13 , V_2 -> V_112 ) ;
F_109 ( V_13 -> V_15 -> V_72 ) ;
}
static int F_112 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_96 ( V_13 -> V_107 , V_21 ) ;
}
static void F_77 ( struct V_12 * V_102 )
{
unsigned int V_21 ;
F_113 ( V_102 ) ;
if ( V_102 -> V_109 ) {
F_114 ( V_102 -> V_109 , NULL ) ;
F_115 ( V_102 -> V_109 , NULL ) ;
}
if ( V_102 -> V_107 ) {
for ( V_21 = 0 ; V_21 < V_102 -> V_10 ; V_21 ++ )
F_116 (
F_96 ( V_102 -> V_107 , V_21 ) ) ;
F_117 ( V_102 -> V_107 ) ;
}
if ( V_102 -> V_104 ) {
V_102 -> V_104 -> V_120 = NULL ;
V_102 -> V_104 -> V_121 = NULL ;
V_102 -> V_104 = NULL ;
}
}
int F_118 ( struct V_12 * V_102 ,
struct V_103 * V_104 ,
unsigned int V_122 ,
T_3 V_123 ,
unsigned int type ,
struct V_124 * V_114 )
{
struct V_125 * V_87 ;
unsigned int V_21 ;
unsigned V_126 = 0 ;
if ( ! V_102 || ! V_104 )
return - V_16 ;
if ( ! V_102 -> V_75 ) {
F_15 ( L_20 ) ;
return - V_16 ;
}
V_87 = V_102 -> V_75 -> V_87 ;
#ifdef F_59
if ( V_102 -> V_87 )
V_87 = V_102 -> V_87 ;
#endif
V_102 -> V_104 = V_104 ;
V_102 -> V_115 = V_123 ;
V_102 -> V_117 = type ;
V_102 -> V_127 = F_112 ;
V_102 -> V_114 = V_114 ;
V_102 -> V_107 = F_119 ( V_87 ,
V_102 -> V_10 , V_122 ,
& V_128 , V_102 ) ;
if ( ! V_102 -> V_107 ) {
V_102 -> V_104 = NULL ;
return - V_16 ;
}
if ( ! V_104 -> V_120 &&
! V_104 -> V_121 ) {
V_104 -> V_120 = F_105 ;
V_104 -> V_121 = F_110 ;
}
for ( V_21 = 0 ; V_21 < V_102 -> V_10 ; V_21 ++ ) {
V_126 = F_120 ( V_102 -> V_107 , V_21 ) ;
if ( V_21 == 0 )
V_102 -> V_126 = V_126 ;
}
F_121 ( V_102 ) ;
return 0 ;
}
static void F_77 ( struct V_12 * V_102 ) {}
int F_122 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_123 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
void F_124 ( struct V_12 * V_13 , unsigned V_21 )
{
F_125 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
int F_126 ( struct V_12 * V_13 ,
struct V_129 * V_130 ,
unsigned int V_131 , const char * V_132 )
{
struct V_133 * V_134 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_101 ;
V_134 = F_58 ( sizeof( * V_134 ) , V_83 ) ;
if ( ! V_134 ) {
F_65 ( V_13 , L_21 ) ;
return - V_84 ;
}
V_134 -> V_135 . V_70 = V_131 ;
V_134 -> V_135 . V_33 = V_13 ;
V_134 -> V_135 . V_31 = V_13 -> V_3 ;
V_134 -> V_135 . V_9 = V_6 -> V_9 + V_131 ;
V_134 -> V_130 = V_130 ;
V_101 = F_127 ( V_130 , V_132 ,
& V_134 -> V_135 . V_136 ,
& V_134 -> V_135 . V_137 ) ;
if ( V_101 < 0 ) {
F_45 ( V_134 ) ;
return V_101 ;
}
F_128 ( V_130 , & V_134 -> V_135 ) ;
F_52 ( V_13 , L_22 ,
V_131 , V_131 + V_134 -> V_135 . V_137 - 1 ,
F_129 ( V_130 ) , V_132 ) ;
F_22 ( & V_134 -> V_138 , & V_6 -> V_93 ) ;
return 0 ;
}
int F_130 ( struct V_12 * V_13 , const char * V_139 ,
unsigned int V_131 , unsigned int V_140 ,
unsigned int V_137 )
{
struct V_133 * V_134 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_101 ;
V_134 = F_58 ( sizeof( * V_134 ) , V_83 ) ;
if ( ! V_134 ) {
F_65 ( V_13 , L_21 ) ;
return - V_84 ;
}
V_134 -> V_135 . V_70 = V_131 ;
V_134 -> V_135 . V_33 = V_13 ;
V_134 -> V_135 . V_31 = V_13 -> V_3 ;
V_134 -> V_135 . V_9 = V_6 -> V_9 + V_131 ;
V_134 -> V_135 . V_141 = V_140 ;
V_134 -> V_135 . V_137 = V_137 ;
V_134 -> V_130 = F_131 ( V_139 ,
& V_134 -> V_135 ) ;
if ( F_132 ( V_134 -> V_130 ) ) {
V_101 = F_133 ( V_134 -> V_130 ) ;
F_65 ( V_13 , L_23 ) ;
F_45 ( V_134 ) ;
return V_101 ;
}
F_52 ( V_13 , L_24 ,
V_131 , V_131 + V_137 - 1 ,
V_139 ,
V_140 , V_140 + V_137 - 1 ) ;
F_22 ( & V_134 -> V_138 , & V_6 -> V_93 ) ;
return 0 ;
}
void F_78 ( struct V_12 * V_13 )
{
struct V_133 * V_134 , * V_142 ;
struct V_5 * V_6 = V_13 -> V_15 ;
F_25 (pin_range, tmp, &gdev->pin_ranges, node) {
F_43 ( & V_134 -> V_138 ) ;
F_134 ( V_134 -> V_130 ,
& V_134 -> V_135 ) ;
F_45 ( V_134 ) ;
}
}
static int F_135 ( struct V_1 * V_17 , const char * V_3 )
{
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_22 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_136 ( V_52 , & V_17 -> V_7 ) == 0 ) {
F_1 ( V_17 , V_3 ? : L_25 ) ;
V_22 = 0 ;
} else {
V_22 = - V_30 ;
goto V_143;
}
if ( V_13 -> V_144 ) {
F_5 ( & V_8 , V_7 ) ;
V_22 = V_13 -> V_144 ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_22 < 0 ) {
F_1 ( V_17 , NULL ) ;
F_18 ( V_52 , & V_17 -> V_7 ) ;
goto V_143;
}
}
if ( V_13 -> V_23 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_143:
if ( V_22 < 0 ) {
F_18 ( V_59 , & V_17 -> V_7 ) ;
F_18 ( V_61 , & V_17 -> V_7 ) ;
F_18 ( V_63 , & V_17 -> V_7 ) ;
}
F_5 ( & V_8 , V_7 ) ;
return V_22 ;
}
int F_137 ( struct V_1 * V_17 , const char * V_3 )
{
int V_22 = - V_145 ;
struct V_5 * V_6 ;
F_138 ( V_17 ) ;
V_6 = V_17 -> V_6 ;
if ( F_107 ( V_6 -> V_72 ) ) {
V_22 = F_135 ( V_17 , V_3 ) ;
if ( V_22 < 0 )
F_109 ( V_6 -> V_72 ) ;
else
F_37 ( & V_6 -> V_29 ) ;
}
if ( V_22 )
F_139 ( V_17 , L_26 , V_19 , V_22 ) ;
return V_22 ;
}
static bool F_140 ( struct V_1 * V_17 )
{
bool V_101 = false ;
unsigned long V_7 ;
struct V_12 * V_13 ;
F_141 () ;
F_142 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( V_13 && F_34 ( V_52 , & V_17 -> V_7 ) ) {
if ( V_13 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_143 ( V_13 -> V_108 ) ;
V_13 -> free ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_17 , NULL ) ;
F_18 ( V_59 , & V_17 -> V_7 ) ;
F_18 ( V_52 , & V_17 -> V_7 ) ;
F_18 ( V_61 , & V_17 -> V_7 ) ;
F_18 ( V_63 , & V_17 -> V_7 ) ;
F_18 ( V_53 , & V_17 -> V_7 ) ;
V_101 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_101 ;
}
void F_144 ( struct V_1 * V_17 )
{
if ( V_17 && V_17 -> V_6 && F_140 ( V_17 ) ) {
F_109 ( V_17 -> V_6 -> V_72 ) ;
F_39 ( & V_17 -> V_6 -> V_29 ) ;
} else {
F_82 ( V_146 ) ;
}
}
const char * F_145 ( struct V_12 * V_13 , unsigned V_21 )
{
struct V_1 * V_17 ;
if ( V_21 >= V_13 -> V_10 )
return NULL ;
V_17 = & V_13 -> V_15 -> V_11 [ V_21 ] ;
if ( F_34 ( V_52 , & V_17 -> V_7 ) == 0 )
return NULL ;
return V_17 -> V_3 ;
}
struct V_1 * F_146 ( struct V_12 * V_13 , T_1 V_14 ,
const char * V_3 )
{
struct V_1 * V_17 = F_8 ( V_13 , V_14 ) ;
int V_81 ;
if ( F_132 ( V_17 ) ) {
F_65 ( V_13 , L_27 ) ;
return V_17 ;
}
V_81 = F_135 ( V_17 , V_3 ) ;
if ( V_81 < 0 )
return F_9 ( V_81 ) ;
return V_17 ;
}
void F_147 ( struct V_1 * V_17 )
{
if ( V_17 )
F_140 ( V_17 ) ;
}
int F_148 ( struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_22 = - V_16 ;
F_138 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_147 || ! V_13 -> V_92 ) {
F_149 ( V_17 ,
L_28 ,
V_19 ) ;
return - V_148 ;
}
V_22 = V_13 -> V_92 ( V_13 , F_17 ( V_17 ) ) ;
if ( V_22 == 0 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
F_150 ( F_10 ( V_17 ) , 1 , V_22 ) ;
return V_22 ;
}
static int F_151 ( struct V_1 * V_17 , int V_149 )
{
struct V_12 * V_13 ;
int V_22 = - V_16 ;
if ( F_34 ( V_54 , & V_17 -> V_7 ) ) {
F_152 ( V_17 ,
L_29 ,
V_19 ) ;
return - V_148 ;
}
if ( V_149 && F_34 ( V_61 , & V_17 -> V_7 ) )
return F_148 ( V_17 ) ;
if ( ! V_149 && F_34 ( V_63 , & V_17 -> V_7 ) )
return F_148 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_150 || ! V_13 -> V_151 ) {
F_149 ( V_17 ,
L_30 ,
V_19 ) ;
return - V_148 ;
}
V_22 = V_13 -> V_151 ( V_13 , F_17 ( V_17 ) , V_149 ) ;
if ( V_22 == 0 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
F_153 ( F_10 ( V_17 ) , 0 , V_149 ) ;
F_150 ( F_10 ( V_17 ) , 0 , V_22 ) ;
return V_22 ;
}
int F_154 ( struct V_1 * V_17 , int V_149 )
{
F_138 ( V_17 ) ;
return F_151 ( V_17 , V_149 ) ;
}
int F_155 ( struct V_1 * V_17 , int V_149 )
{
F_138 ( V_17 ) ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_149 = ! V_149 ;
return F_151 ( V_17 , V_149 ) ;
}
int F_156 ( struct V_1 * V_17 , unsigned V_152 )
{
struct V_12 * V_13 ;
F_138 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_150 || ! V_13 -> V_153 ) {
F_139 ( V_17 ,
L_31 ,
V_19 ) ;
return - V_154 ;
}
return V_13 -> V_153 ( V_13 , F_17 ( V_17 ) , V_152 ) ;
}
int F_157 ( const struct V_1 * V_17 )
{
F_138 ( V_17 ) ;
return F_34 ( V_59 , & V_17 -> V_7 ) ;
}
static int F_158 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
int V_149 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
V_149 = V_13 -> V_147 ? V_13 -> V_147 ( V_13 , V_21 ) : - V_148 ;
V_149 = V_149 < 0 ? V_149 : ! ! V_149 ;
F_153 ( F_10 ( V_17 ) , 1 , V_149 ) ;
return V_149 ;
}
int F_159 ( const struct V_1 * V_17 )
{
F_138 ( V_17 ) ;
F_82 ( V_17 -> V_6 -> V_13 -> V_108 ) ;
return F_158 ( V_17 ) ;
}
int F_160 ( const struct V_1 * V_17 )
{
int V_149 ;
F_138 ( V_17 ) ;
F_82 ( V_17 -> V_6 -> V_13 -> V_108 ) ;
V_149 = F_158 ( V_17 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_149 = ! V_149 ;
return V_149 ;
}
static void F_161 ( struct V_1 * V_17 , bool V_149 )
{
int V_81 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_149 ) {
V_81 = V_13 -> V_92 ( V_13 , V_21 ) ;
if ( ! V_81 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_81 = V_13 -> V_151 ( V_13 , V_21 , 0 ) ;
if ( ! V_81 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
F_150 ( F_10 ( V_17 ) , V_149 , V_81 ) ;
if ( V_81 < 0 )
F_152 ( V_17 ,
L_32 ,
V_19 , V_81 ) ;
}
static void F_162 ( struct V_1 * V_17 , bool V_149 )
{
int V_81 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_149 ) {
V_81 = V_13 -> V_151 ( V_13 , V_21 , 1 ) ;
if ( ! V_81 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_81 = V_13 -> V_92 ( V_13 , V_21 ) ;
if ( ! V_81 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
}
F_150 ( F_10 ( V_17 ) , ! V_149 , V_81 ) ;
if ( V_81 < 0 )
F_152 ( V_17 ,
L_33 ,
V_19 , V_81 ) ;
}
static void F_163 ( struct V_1 * V_17 , bool V_149 )
{
struct V_12 * V_13 ;
V_13 = V_17 -> V_6 -> V_13 ;
F_153 ( F_10 ( V_17 ) , 0 , V_149 ) ;
if ( F_34 ( V_61 , & V_17 -> V_7 ) )
F_161 ( V_17 , V_149 ) ;
else if ( F_34 ( V_63 , & V_17 -> V_7 ) )
F_162 ( V_17 , V_149 ) ;
else
V_13 -> V_150 ( V_13 , F_17 ( V_17 ) , V_149 ) ;
}
static void F_164 ( struct V_12 * V_13 ,
unsigned long * V_155 , unsigned long * V_156 )
{
if ( V_13 -> V_157 ) {
V_13 -> V_157 ( V_13 , V_155 , V_156 ) ;
} else {
int V_32 ;
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
if ( V_155 [ F_165 ( V_32 ) ] == 0 ) {
V_32 = ( F_165 ( V_32 ) + 1 ) * V_158 - 1 ;
continue;
}
if ( F_166 ( V_32 , V_155 ) )
V_13 -> V_150 ( V_13 , V_32 , F_34 ( V_32 , V_156 ) ) ;
}
}
}
static void F_167 ( bool V_159 , bool V_108 ,
unsigned int V_160 ,
struct V_1 * * V_161 ,
int * V_162 )
{
int V_32 = 0 ;
while ( V_32 < V_160 ) {
struct V_12 * V_13 = V_161 [ V_32 ] -> V_6 -> V_13 ;
unsigned long V_155 [ F_168 ( V_13 -> V_10 ) ] ;
unsigned long V_156 [ F_168 ( V_13 -> V_10 ) ] ;
int V_163 = 0 ;
if ( ! V_108 )
F_82 ( V_13 -> V_108 ) ;
memset ( V_155 , 0 , sizeof( V_155 ) ) ;
do {
struct V_1 * V_17 = V_161 [ V_32 ] ;
int V_164 = F_17 ( V_17 ) ;
int V_149 = V_162 [ V_32 ] ;
if ( ! V_159 && F_34 ( V_59 , & V_17 -> V_7 ) )
V_149 = ! V_149 ;
F_153 ( F_10 ( V_17 ) , 0 , V_149 ) ;
if ( F_34 ( V_61 , & V_17 -> V_7 ) ) {
F_161 ( V_17 , V_149 ) ;
} else if ( F_34 ( V_63 , & V_17 -> V_7 ) ) {
F_162 ( V_17 , V_149 ) ;
} else {
F_169 ( V_164 , V_155 ) ;
if ( V_149 )
F_169 ( V_164 , V_156 ) ;
else
F_170 ( V_164 , V_156 ) ;
V_163 ++ ;
}
V_32 ++ ;
} while ( ( V_32 < V_160 ) &&
( V_161 [ V_32 ] -> V_6 -> V_13 == V_13 ) );
if ( V_163 != 0 )
F_164 ( V_13 , V_155 , V_156 ) ;
}
}
void F_171 ( struct V_1 * V_17 , int V_149 )
{
F_172 ( V_17 ) ;
F_82 ( V_17 -> V_6 -> V_13 -> V_108 ) ;
F_163 ( V_17 , V_149 ) ;
}
void F_173 ( struct V_1 * V_17 , int V_149 )
{
F_172 ( V_17 ) ;
F_82 ( V_17 -> V_6 -> V_13 -> V_108 ) ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_149 = ! V_149 ;
F_163 ( V_17 , V_149 ) ;
}
void F_174 ( unsigned int V_160 ,
struct V_1 * * V_161 , int * V_162 )
{
if ( ! V_161 )
return;
F_167 ( true , false , V_160 , V_161 ,
V_162 ) ;
}
void F_175 ( unsigned int V_160 ,
struct V_1 * * V_161 , int * V_162 )
{
if ( ! V_161 )
return;
F_167 ( false , false , V_160 , V_161 ,
V_162 ) ;
}
int F_176 ( const struct V_1 * V_17 )
{
F_138 ( V_17 ) ;
return V_17 -> V_6 -> V_13 -> V_108 ;
}
int F_177 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
F_138 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
return V_13 -> V_127 ? V_13 -> V_127 ( V_13 , V_21 ) : - V_165 ;
}
int F_108 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return - V_16 ;
if ( F_34 ( V_24 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ) {
F_65 ( V_13 ,
L_34 ,
V_19 ) ;
return - V_148 ;
}
F_19 ( V_54 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
return 0 ;
}
void F_111 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return;
F_18 ( V_54 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_178 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_34 ( V_54 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_179 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_34 ( V_61 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_180 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_34 ( V_63 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
int F_181 ( const struct V_1 * V_17 )
{
F_143 ( V_146 ) ;
F_138 ( V_17 ) ;
return F_158 ( V_17 ) ;
}
int F_182 ( const struct V_1 * V_17 )
{
int V_149 ;
F_143 ( V_146 ) ;
F_138 ( V_17 ) ;
V_149 = F_158 ( V_17 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_149 = ! V_149 ;
return V_149 ;
}
void F_183 ( struct V_1 * V_17 , int V_149 )
{
F_143 ( V_146 ) ;
F_172 ( V_17 ) ;
F_163 ( V_17 , V_149 ) ;
}
void F_184 ( struct V_1 * V_17 , int V_149 )
{
F_143 ( V_146 ) ;
F_172 ( V_17 ) ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_149 = ! V_149 ;
F_163 ( V_17 , V_149 ) ;
}
void F_185 ( unsigned int V_160 ,
struct V_1 * * V_161 ,
int * V_162 )
{
F_143 ( V_146 ) ;
if ( ! V_161 )
return;
F_167 ( true , true , V_160 , V_161 ,
V_162 ) ;
}
void F_186 ( unsigned int V_160 ,
struct V_1 * * V_161 ,
int * V_162 )
{
F_143 ( V_146 ) ;
if ( ! V_161 )
return;
F_167 ( false , true , V_160 , V_161 ,
V_162 ) ;
}
void F_187 ( struct V_166 * V_167 )
{
F_188 ( & V_168 ) ;
F_22 ( & V_167 -> V_28 , & V_169 ) ;
F_189 ( & V_168 ) ;
}
void F_190 ( struct V_166 * V_167 )
{
F_188 ( & V_168 ) ;
F_43 ( & V_167 -> V_28 ) ;
F_189 ( & V_168 ) ;
}
static struct V_1 * F_191 ( struct V_68 * V_29 , const char * V_170 ,
unsigned int V_171 ,
enum V_172 * V_7 )
{
char V_173 [ 32 ] ;
enum V_174 V_175 ;
struct V_1 * V_17 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_192 ( V_176 ) ; V_32 ++ ) {
if ( V_170 )
snprintf ( V_173 , sizeof( V_173 ) , L_35 , V_170 ,
V_176 [ V_32 ] ) ;
else
snprintf ( V_173 , sizeof( V_173 ) , L_36 ,
V_176 [ V_32 ] ) ;
V_17 = F_193 ( V_29 -> V_87 , V_173 , V_171 ,
& V_175 ) ;
if ( ! F_132 ( V_17 ) || ( F_133 ( V_17 ) == - V_145 ) )
break;
}
if ( F_132 ( V_17 ) )
return V_17 ;
if ( V_175 & V_177 )
* V_7 |= V_178 ;
if ( V_175 & V_179 ) {
if ( V_175 & V_177 )
* V_7 |= V_180 ;
else
* V_7 |= V_181 ;
}
return V_17 ;
}
static struct V_1 * F_194 ( struct V_68 * V_29 ,
const char * V_170 ,
unsigned int V_171 ,
enum V_182 V_7 ,
enum V_172 * V_183 )
{
struct V_184 * V_185 = F_195 ( V_29 ) ;
struct V_186 V_187 ;
struct V_1 * V_17 ;
char V_188 [ 32 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_192 ( V_176 ) ; V_32 ++ ) {
if ( V_170 && strcmp ( V_170 , L_37 ) ) {
snprintf ( V_188 , sizeof( V_188 ) , L_35 ,
V_170 , V_176 [ V_32 ] ) ;
} else {
snprintf ( V_188 , sizeof( V_188 ) , L_36 ,
V_176 [ V_32 ] ) ;
}
V_17 = F_196 ( V_185 , V_188 , V_171 , & V_187 ) ;
if ( ! F_132 ( V_17 ) || ( F_133 ( V_17 ) == - V_145 ) )
break;
}
if ( F_132 ( V_17 ) ) {
if ( ! F_197 ( V_185 , V_170 ) )
return F_9 ( - V_189 ) ;
V_17 = F_196 ( V_185 , NULL , V_171 , & V_187 ) ;
if ( F_132 ( V_17 ) )
return V_17 ;
if ( ( V_7 == V_190 || V_7 == V_191 ) &&
V_187 . V_192 ) {
F_198 ( V_29 , L_38 ) ;
return F_9 ( - V_189 ) ;
}
}
if ( V_187 . V_193 == V_178 )
* V_183 |= V_178 ;
return V_17 ;
}
static struct V_166 * F_199 ( struct V_68 * V_29 )
{
const char * V_194 = V_29 ? F_31 ( V_29 ) : NULL ;
struct V_166 * V_167 ;
F_188 ( & V_168 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_167 -> V_194 && V_194 ) {
if ( ! strcmp ( V_167 -> V_194 , V_194 ) )
goto V_195;
} else {
if ( V_194 == V_167 -> V_194 )
goto V_195;
}
}
V_167 = NULL ;
V_195:
F_189 ( & V_168 ) ;
return V_167 ;
}
static struct V_1 * F_200 ( struct V_68 * V_29 , const char * V_170 ,
unsigned int V_171 ,
enum V_172 * V_7 )
{
struct V_1 * V_17 = F_9 ( - V_189 ) ;
struct V_166 * V_167 ;
struct V_196 * V_197 ;
V_167 = F_199 ( V_29 ) ;
if ( ! V_167 )
return V_17 ;
for ( V_197 = & V_167 -> V_167 [ 0 ] ; V_197 -> V_198 ; V_197 ++ ) {
struct V_12 * V_13 ;
if ( V_197 -> V_171 != V_171 )
continue;
if ( V_197 -> V_170 && ( ! V_170 || strcmp ( V_197 -> V_170 , V_170 ) ) )
continue;
V_13 = F_92 ( V_197 -> V_198 ) ;
if ( ! V_13 ) {
F_26 ( V_29 , L_39 ,
V_197 -> V_198 ) ;
return F_9 ( - V_41 ) ;
}
if ( V_13 -> V_10 <= V_197 -> V_199 ) {
F_26 ( V_29 ,
L_40 ,
V_171 , V_13 -> V_10 , V_13 -> V_3 ) ;
return F_9 ( - V_16 ) ;
}
V_17 = F_8 ( V_13 , V_197 -> V_199 ) ;
* V_7 = V_197 -> V_7 ;
return V_17 ;
}
return V_17 ;
}
static int F_201 ( struct V_68 * V_29 , const char * V_170 )
{
int V_101 ;
char V_188 [ 32 ] ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_192 ( V_176 ) ; V_32 ++ ) {
if ( V_170 )
snprintf ( V_188 , sizeof( V_188 ) , L_35 ,
V_170 , V_176 [ V_32 ] ) ;
else
snprintf ( V_188 , sizeof( V_188 ) , L_36 ,
V_176 [ V_32 ] ) ;
V_101 = F_202 ( V_29 -> V_87 , V_188 ) ;
if ( V_101 >= 0 )
break;
}
return V_101 ;
}
static int F_203 ( struct V_68 * V_29 , const char * V_170 )
{
struct V_166 * V_167 ;
struct V_196 * V_197 ;
unsigned int V_163 = 0 ;
V_167 = F_199 ( V_29 ) ;
if ( ! V_167 )
return - V_189 ;
for ( V_197 = & V_167 -> V_167 [ 0 ] ; V_197 -> V_198 ; V_197 ++ ) {
if ( ( V_170 && V_197 -> V_170 && ! strcmp ( V_170 , V_197 -> V_170 ) ) ||
( ! V_170 && ! V_197 -> V_170 ) )
V_163 ++ ;
}
if ( ! V_163 )
return - V_189 ;
return V_163 ;
}
int F_204 ( struct V_68 * V_29 , const char * V_170 )
{
int V_163 = - V_189 ;
if ( F_205 ( V_200 ) && V_29 && V_29 -> V_87 )
V_163 = F_201 ( V_29 , V_170 ) ;
else if ( F_205 ( V_201 ) && V_29 && F_206 ( V_29 ) )
V_163 = F_207 ( V_29 , V_170 ) ;
if ( V_163 < 0 )
V_163 = F_203 ( V_29 , V_170 ) ;
return V_163 ;
}
struct V_1 * T_5 F_208 ( struct V_68 * V_29 , const char * V_170 ,
enum V_182 V_7 )
{
return F_209 ( V_29 , V_170 , 0 , V_7 ) ;
}
struct V_1 * T_5 F_210 ( struct V_68 * V_29 ,
const char * V_170 ,
enum V_182 V_7 )
{
return F_211 ( V_29 , V_170 , 0 , V_7 ) ;
}
static void F_212 ( struct V_1 * V_17 , unsigned long V_202 )
{
if ( V_202 & V_178 )
F_19 ( V_59 , & V_17 -> V_7 ) ;
if ( V_202 & V_180 )
F_19 ( V_61 , & V_17 -> V_7 ) ;
if ( V_202 & V_181 )
F_19 ( V_63 , & V_17 -> V_7 ) ;
}
static int F_213 ( struct V_1 * V_17 , const char * V_170 ,
enum V_182 V_203 )
{
int V_22 ;
if ( ! ( V_203 & V_204 ) ) {
F_14 ( L_41 , V_170 ) ;
return 0 ;
}
if ( V_203 & V_205 )
V_22 = F_155 ( V_17 ,
V_203 & V_206 ) ;
else
V_22 = F_148 ( V_17 ) ;
return V_22 ;
}
struct V_1 * T_5 F_209 ( struct V_68 * V_29 ,
const char * V_170 ,
unsigned int V_171 ,
enum V_182 V_7 )
{
struct V_1 * V_17 = NULL ;
int V_22 ;
enum V_172 V_183 = 0 ;
F_198 ( V_29 , L_42 , V_170 ) ;
if ( V_29 ) {
if ( F_205 ( V_200 ) && V_29 -> V_87 ) {
F_198 ( V_29 , L_43 ) ;
V_17 = F_191 ( V_29 , V_170 , V_171 , & V_183 ) ;
} else if ( F_195 ( V_29 ) ) {
F_198 ( V_29 , L_44 ) ;
V_17 = F_194 ( V_29 , V_170 , V_171 , V_7 , & V_183 ) ;
}
}
if ( ! V_17 || V_17 == F_9 ( - V_189 ) ) {
F_198 ( V_29 , L_45 ) ;
V_17 = F_200 ( V_29 , V_170 , V_171 , & V_183 ) ;
}
if ( F_132 ( V_17 ) ) {
F_198 ( V_29 , L_46 , V_170 ) ;
return V_17 ;
}
F_212 ( V_17 , V_183 ) ;
V_22 = F_137 ( V_17 , V_170 ) ;
if ( V_22 < 0 )
return F_9 ( V_22 ) ;
V_22 = F_213 ( V_17 , V_170 , V_7 ) ;
if ( V_22 < 0 ) {
F_198 ( V_29 , L_47 , V_170 ) ;
F_214 ( V_17 ) ;
return F_9 ( V_22 ) ;
}
return V_17 ;
}
struct V_1 * F_215 ( struct V_207 * V_208 ,
const char * V_188 )
{
struct V_1 * V_17 = F_9 ( - V_41 ) ;
bool V_209 = false ;
bool V_210 = false ;
int V_101 ;
if ( ! V_208 )
return F_9 ( - V_16 ) ;
if ( F_216 ( V_208 ) ) {
enum V_174 V_7 ;
V_17 = F_193 ( F_217 ( V_208 ) , V_188 , 0 ,
& V_7 ) ;
if ( ! F_132 ( V_17 ) ) {
V_209 = V_7 & V_177 ;
V_210 = V_7 & V_179 ;
}
} else if ( F_218 ( V_208 ) ) {
struct V_186 V_187 ;
V_17 = F_219 ( V_208 , V_188 , 0 , & V_187 ) ;
if ( ! F_132 ( V_17 ) )
V_209 = V_187 . V_193 == V_178 ;
}
if ( F_132 ( V_17 ) )
return V_17 ;
if ( V_209 )
F_19 ( V_59 , & V_17 -> V_7 ) ;
if ( V_210 ) {
if ( V_209 )
F_19 ( V_61 , & V_17 -> V_7 ) ;
else
F_19 ( V_63 , & V_17 -> V_7 ) ;
}
V_101 = F_137 ( V_17 , NULL ) ;
if ( V_101 )
return F_9 ( V_101 ) ;
return V_17 ;
}
struct V_1 * T_5 F_211 ( struct V_68 * V_29 ,
const char * V_170 ,
unsigned int V_211 ,
enum V_182 V_7 )
{
struct V_1 * V_17 ;
V_17 = F_209 ( V_29 , V_170 , V_211 , V_7 ) ;
if ( F_132 ( V_17 ) ) {
if ( F_133 ( V_17 ) == - V_189 )
return NULL ;
}
return V_17 ;
}
int F_220 ( struct V_1 * V_17 , const char * V_31 ,
unsigned long V_202 , enum V_182 V_203 )
{
struct V_12 * V_13 ;
struct V_1 * V_212 ;
int V_14 ;
int V_22 ;
V_13 = F_11 ( V_17 ) ;
V_14 = F_17 ( V_17 ) ;
F_212 ( V_17 , V_202 ) ;
V_212 = F_146 ( V_13 , V_14 , V_31 ) ;
if ( F_132 ( V_212 ) ) {
F_15 ( L_48 ,
V_31 , V_13 -> V_3 , V_14 ) ;
return F_133 ( V_212 ) ;
}
V_22 = F_213 ( V_17 , V_31 , V_203 ) ;
if ( V_22 < 0 ) {
F_15 ( L_49 ,
V_31 , V_13 -> V_3 , V_14 ) ;
F_147 ( V_17 ) ;
return V_22 ;
}
F_19 ( V_53 , & V_17 -> V_7 ) ;
F_221 ( L_50 ,
F_10 ( V_17 ) , V_31 ,
( V_203 & V_205 ) ? L_51 : L_52 ,
( V_203 & V_205 ) ?
( V_203 & V_206 ) ? L_53 : L_54 : L_55 ) ;
return 0 ;
}
static void F_72 ( struct V_12 * V_13 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_13 -> V_10 ; V_70 ++ ) {
if ( F_34 ( V_53 , & V_13 -> V_15 -> V_11 [ V_70 ] . V_7 ) )
F_147 ( & V_13 -> V_15 -> V_11 [ V_70 ] ) ;
}
}
struct V_213 * T_5 F_222 ( struct V_68 * V_29 ,
const char * V_170 ,
enum V_182 V_7 )
{
struct V_1 * V_17 ;
struct V_213 * V_11 ;
int V_163 ;
V_163 = F_204 ( V_29 , V_170 ) ;
if ( V_163 < 0 )
return F_9 ( V_163 ) ;
V_11 = F_58 ( sizeof( * V_11 ) + sizeof( V_11 -> V_17 [ 0 ] ) * V_163 ,
V_83 ) ;
if ( ! V_11 )
return F_9 ( - V_84 ) ;
for ( V_11 -> V_214 = 0 ; V_11 -> V_214 < V_163 ; ) {
V_17 = F_209 ( V_29 , V_170 , V_11 -> V_214 , V_7 ) ;
if ( F_132 ( V_17 ) ) {
F_223 ( V_11 ) ;
return F_224 ( V_17 ) ;
}
V_11 -> V_17 [ V_11 -> V_214 ] = V_17 ;
V_11 -> V_214 ++ ;
}
return V_11 ;
}
struct V_213 * T_5 F_225 ( struct V_68 * V_29 ,
const char * V_170 ,
enum V_182 V_7 )
{
struct V_213 * V_11 ;
V_11 = F_222 ( V_29 , V_170 , V_7 ) ;
if ( F_132 ( V_11 ) && ( F_133 ( V_11 ) == - V_189 ) )
return NULL ;
return V_11 ;
}
void F_214 ( struct V_1 * V_17 )
{
F_144 ( V_17 ) ;
}
void F_223 ( struct V_213 * V_11 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_11 -> V_214 ; V_32 ++ )
F_214 ( V_11 -> V_17 [ V_32 ] ) ;
F_45 ( V_11 ) ;
}
static int T_6 F_226 ( void )
{
int V_101 ;
V_101 = F_227 ( & V_86 ) ;
if ( V_101 < 0 ) {
F_15 ( L_56 ) ;
return V_101 ;
}
V_101 = F_228 ( & V_77 , 0 , V_215 , L_57 ) ;
if ( V_101 < 0 ) {
F_15 ( L_58 ) ;
F_229 ( & V_86 ) ;
} else {
V_96 = true ;
F_56 () ;
}
return V_101 ;
}
static void F_230 ( struct V_216 * V_217 , struct V_5 * V_6 )
{
unsigned V_32 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_218 = & V_6 -> V_11 [ 0 ] ;
int V_219 ;
int V_220 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ , V_4 ++ , V_218 ++ ) {
if ( ! F_34 ( V_52 , & V_218 -> V_7 ) ) {
if ( V_218 -> V_31 ) {
F_231 ( V_217 , L_59 ,
V_4 , V_218 -> V_31 ) ;
}
continue;
}
F_16 ( V_218 ) ;
V_219 = F_34 ( V_24 , & V_218 -> V_7 ) ;
V_220 = F_34 ( V_54 , & V_218 -> V_7 ) ;
F_231 ( V_217 , L_60 ,
V_4 , V_218 -> V_31 ? V_218 -> V_31 : L_55 , V_218 -> V_3 ,
V_219 ? L_61 : L_62 ,
V_13 -> V_147
? ( V_13 -> V_147 ( V_13 , V_32 ) ? L_63 : L_64 )
: L_65 ,
V_220 ? L_66 : L_67 ) ;
F_231 ( V_217 , L_68 ) ;
}
}
static void * F_232 ( struct V_216 * V_217 , T_7 * V_221 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_7 V_211 = * V_221 ;
V_217 -> V_222 = L_55 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_211 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_233 ( struct V_216 * V_217 , void * V_223 , T_7 * V_221 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_223 ;
void * V_101 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_234 ( & V_6 -> V_28 , & V_27 ) )
V_101 = NULL ;
else
V_101 = F_23 ( V_6 -> V_28 . V_26 , struct V_5 , V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_217 -> V_222 = L_68 ;
++ * V_221 ;
return V_101 ;
}
static void F_235 ( struct V_216 * V_217 , void * V_223 )
{
}
static int F_236 ( struct V_216 * V_217 , void * V_223 )
{
struct V_5 * V_6 = V_223 ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_68 * V_75 ;
if ( ! V_13 ) {
F_231 ( V_217 , L_69 , ( char * ) V_217 -> V_222 ,
F_31 ( & V_6 -> V_29 ) ) ;
return 0 ;
}
F_231 ( V_217 , L_70 , ( char * ) V_217 -> V_222 ,
F_31 ( & V_6 -> V_29 ) ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_75 = V_13 -> V_75 ;
if ( V_75 )
F_231 ( V_217 , L_71 ,
V_75 -> V_85 ? V_75 -> V_85 -> V_31 : L_72 ,
F_31 ( V_75 ) ) ;
if ( V_13 -> V_3 )
F_231 ( V_217 , L_73 , V_13 -> V_3 ) ;
if ( V_13 -> V_108 )
F_231 ( V_217 , L_74 ) ;
F_231 ( V_217 , L_75 ) ;
if ( V_13 -> V_224 )
V_13 -> V_224 ( V_217 , V_13 ) ;
else
F_230 ( V_217 , V_6 ) ;
return 0 ;
}
static int F_237 ( struct V_65 * V_65 , struct V_35 * V_35 )
{
return F_238 ( V_35 , & V_225 ) ;
}
static int T_6 F_239 ( void )
{
( void ) F_240 ( L_76 , V_226 | V_227 ,
NULL , NULL , & V_228 ) ;
return 0 ;
}
