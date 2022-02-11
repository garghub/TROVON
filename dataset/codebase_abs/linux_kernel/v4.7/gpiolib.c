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
void T_2 * V_40 = ( void T_2 * ) V_38 ;
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
static long F_35 ( struct V_35 * V_36 , unsigned int V_37 ,
unsigned long V_38 )
{
return F_30 ( V_36 , V_37 , ( unsigned long ) F_36 ( V_38 ) ) ;
}
static int F_37 ( struct V_65 * V_65 , struct V_35 * V_36 )
{
struct V_5 * V_6 = F_38 ( V_65 -> V_66 ,
struct V_5 , V_67 ) ;
if ( ! V_6 || ! V_6 -> V_13 )
return - V_41 ;
F_39 ( & V_6 -> V_29 ) ;
V_36 -> V_39 = V_6 ;
return 0 ;
}
static int F_40 ( struct V_65 * V_65 , struct V_35 * V_36 )
{
struct V_5 * V_6 = F_38 ( V_65 -> V_66 ,
struct V_5 , V_67 ) ;
if ( ! V_6 )
return - V_41 ;
F_41 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_42 ( struct V_68 * V_29 )
{
struct V_5 * V_6 = F_43 ( V_29 ) ;
F_44 ( & V_6 -> V_28 ) ;
F_45 ( & V_69 , V_6 -> V_70 ) ;
F_46 ( V_6 -> V_3 ) ;
F_46 ( V_6 -> V_11 ) ;
F_46 ( V_6 ) ;
}
static int F_47 ( struct V_5 * V_6 )
{
int V_22 ;
F_48 ( & V_6 -> V_67 , & V_71 ) ;
V_6 -> V_67 . V_72 = V_73 ;
V_6 -> V_67 . V_74 . V_75 = & V_6 -> V_29 . V_74 ;
V_6 -> V_29 . V_76 = F_49 ( F_50 ( V_77 ) , V_6 -> V_70 ) ;
V_22 = F_51 ( & V_6 -> V_67 , V_6 -> V_29 . V_76 , 1 ) ;
if ( V_22 < 0 )
F_52 ( V_6 -> V_13 , L_6 ,
F_50 ( V_77 ) , V_6 -> V_70 ) ;
else
F_53 ( V_6 -> V_13 , L_7 ,
F_50 ( V_77 ) , V_6 -> V_70 ) ;
V_22 = F_54 ( & V_6 -> V_29 ) ;
if ( V_22 )
goto V_78;
V_22 = F_55 ( V_6 ) ;
if ( V_22 )
goto V_79;
V_6 -> V_29 . V_80 = F_42 ;
F_14 ( L_8 ,
V_19 , V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
F_31 ( & V_6 -> V_29 ) , V_6 -> V_13 -> V_3 ? : L_9 ) ;
return 0 ;
V_79:
F_56 ( & V_6 -> V_29 ) ;
V_78:
F_57 ( & V_6 -> V_67 ) ;
return V_22 ;
}
static void F_58 ( void )
{
struct V_5 * V_6 ;
int V_81 ;
F_4 (gdev, &gpio_devices, list) {
V_81 = F_47 ( V_6 ) ;
if ( V_81 )
F_15 ( L_10 ,
F_31 ( & V_6 -> V_29 ) , V_81 ) ;
}
}
int F_59 ( struct V_12 * V_13 , void * V_82 )
{
unsigned long V_7 ;
int V_22 = 0 ;
unsigned V_32 ;
int V_9 = V_13 -> V_9 ;
struct V_5 * V_6 ;
V_6 = F_60 ( sizeof( * V_6 ) , V_83 ) ;
if ( ! V_6 )
return - V_84 ;
V_6 -> V_29 . V_85 = & V_86 ;
V_6 -> V_13 = V_13 ;
V_13 -> V_15 = V_6 ;
if ( V_13 -> V_75 ) {
V_6 -> V_29 . V_75 = V_13 -> V_75 ;
V_6 -> V_29 . V_87 = V_13 -> V_75 -> V_87 ;
} else {
#ifdef F_61
if ( V_13 -> V_87 )
V_6 -> V_29 . V_87 = V_13 -> V_87 ;
#endif
}
V_6 -> V_70 = F_62 ( & V_69 , 0 , 0 , V_83 ) ;
if ( V_6 -> V_70 < 0 ) {
V_22 = V_6 -> V_70 ;
goto V_88;
}
F_63 ( & V_6 -> V_29 , L_11 , V_6 -> V_70 ) ;
F_64 ( & V_6 -> V_29 ) ;
F_65 ( & V_6 -> V_29 , V_6 ) ;
if ( V_13 -> V_75 && V_13 -> V_75 -> V_89 )
V_6 -> V_72 = V_13 -> V_75 -> V_89 -> V_72 ;
else if ( V_13 -> V_72 )
V_6 -> V_72 = V_13 -> V_72 ;
else
V_6 -> V_72 = V_73 ;
V_6 -> V_11 = F_66 ( V_13 -> V_10 , sizeof( V_6 -> V_11 [ 0 ] ) , V_83 ) ;
if ( ! V_6 -> V_11 ) {
V_22 = - V_84 ;
goto V_88;
}
if ( V_13 -> V_10 == 0 ) {
F_67 ( V_13 , L_12 ) ;
V_22 = - V_16 ;
goto V_90;
}
if ( V_13 -> V_3 )
V_6 -> V_3 = F_68 ( V_13 -> V_3 , V_83 ) ;
else
V_6 -> V_3 = F_68 ( L_13 , V_83 ) ;
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
F_5 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
struct V_1 * V_17 = & V_6 -> V_11 [ V_32 ] ;
V_17 -> V_6 = V_6 ;
if ( V_13 -> V_23 ) {
int V_92 = V_13 -> V_23 ( V_13 , V_32 ) ;
if ( ! V_92 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else if ( ! V_13 -> V_93 ) {
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
}
#ifdef F_69
F_70 ( & V_6 -> V_94 ) ;
#endif
V_22 = F_28 ( V_13 ) ;
if ( V_22 )
goto V_95;
V_22 = F_71 ( V_13 ) ;
if ( V_22 )
goto V_96;
F_72 ( V_13 ) ;
if ( V_97 ) {
V_22 = F_47 ( V_6 ) ;
if ( V_22 )
goto V_96;
}
return 0 ;
V_96:
F_73 ( V_13 ) ;
F_74 ( V_13 ) ;
F_75 ( V_13 ) ;
V_95:
F_3 ( & V_8 , V_7 ) ;
F_44 ( & V_6 -> V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_91:
F_46 ( V_6 -> V_3 ) ;
V_90:
F_46 ( V_6 -> V_11 ) ;
V_88:
F_45 ( & V_69 , V_6 -> V_70 ) ;
F_15 ( L_14 , V_19 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_13 -> V_3 ? : L_9 ) ;
F_46 ( V_6 ) ;
return V_22 ;
}
void * F_76 ( struct V_12 * V_13 )
{
return V_13 -> V_15 -> V_82 ;
}
void F_77 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_15 ;
struct V_1 * V_17 ;
unsigned long V_7 ;
unsigned V_32 ;
bool V_98 = false ;
F_78 ( V_6 ) ;
V_6 -> V_13 = NULL ;
F_79 ( V_13 ) ;
F_73 ( V_13 ) ;
F_80 ( V_13 ) ;
F_74 ( V_13 ) ;
F_75 ( V_13 ) ;
V_6 -> V_82 = NULL ;
F_3 ( & V_8 , V_7 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ ) {
V_17 = & V_6 -> V_11 [ V_32 ] ;
if ( F_34 ( V_52 , & V_17 -> V_7 ) )
V_98 = true ;
}
F_5 ( & V_8 , V_7 ) ;
if ( V_98 )
F_81 ( & V_6 -> V_29 ,
L_15 ) ;
F_57 ( & V_6 -> V_67 ) ;
F_56 ( & V_6 -> V_29 ) ;
F_41 ( & V_6 -> V_29 ) ;
}
static void F_82 ( struct V_68 * V_29 , void * V_99 )
{
struct V_12 * V_13 = * (struct V_12 * * ) V_99 ;
F_77 ( V_13 ) ;
}
static int F_83 ( struct V_68 * V_29 , void * V_99 , void * V_82 )
{
struct V_12 * * V_100 = V_99 ;
if ( ! V_100 || ! * V_100 ) {
F_84 ( ! V_100 || ! * V_100 ) ;
return 0 ;
}
return * V_100 == V_82 ;
}
int F_85 ( struct V_68 * V_29 , struct V_12 * V_13 ,
void * V_82 )
{
struct V_12 * * V_101 ;
int V_102 ;
V_101 = F_86 ( F_82 , sizeof( * V_101 ) ,
V_83 ) ;
if ( ! V_101 )
return - V_84 ;
V_102 = F_59 ( V_13 , V_82 ) ;
if ( V_102 < 0 ) {
F_87 ( V_101 ) ;
return V_102 ;
}
* V_101 = V_13 ;
F_88 ( V_29 , V_101 ) ;
return 0 ;
}
void F_89 ( struct V_68 * V_29 , struct V_12 * V_13 )
{
int V_102 ;
V_102 = F_90 ( V_29 , F_82 ,
F_83 , V_13 ) ;
if ( ! V_102 )
F_84 ( V_102 ) ;
}
struct V_12 * F_91 ( void * V_82 ,
int (* F_92)( struct V_12 * V_13 ,
void * V_82 ) )
{
struct V_5 * V_6 ;
struct V_12 * V_13 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_6 -> V_13 && F_92 ( V_6 -> V_13 , V_82 ) )
break;
if ( & V_6 -> V_28 == & V_27 )
V_13 = NULL ;
else
V_13 = V_6 -> V_13 ;
F_5 ( & V_8 , V_7 ) ;
return V_13 ;
}
static int F_93 ( struct V_12 * V_13 , void * V_82 )
{
const char * V_31 = V_82 ;
return ! strcmp ( V_13 -> V_3 , V_31 ) ;
}
static struct V_12 * F_94 ( const char * V_31 )
{
return F_91 ( ( void * ) V_31 , F_93 ) ;
}
void F_95 ( struct V_12 * V_103 ,
struct V_104 * V_105 ,
int V_106 ,
T_3 V_107 )
{
unsigned int V_21 ;
if ( ! V_103 -> V_108 ) {
F_67 ( V_103 , L_16 ,
V_19 ) ;
return;
}
if ( V_107 ) {
if ( V_103 -> V_109 ) {
F_67 ( V_103 ,
L_17
L_18 ) ;
return;
}
F_96 ( V_106 , V_107 ,
V_103 ) ;
V_103 -> V_110 = V_106 ;
}
for ( V_21 = 0 ; V_21 < V_103 -> V_10 ; V_21 ++ )
F_97 ( F_98 ( V_103 -> V_108 , V_21 ) ,
V_106 ) ;
}
static int F_99 ( struct V_111 * V_2 , unsigned int V_112 ,
T_4 V_113 )
{
struct V_12 * V_13 = V_2 -> V_114 ;
F_100 ( V_112 , V_13 ) ;
F_101 ( V_112 , V_13 -> V_115 ) ;
F_102 ( V_112 , V_13 -> V_105 , V_13 -> V_116 ) ;
if ( V_13 -> V_109 && ! V_13 -> V_117 )
F_103 ( V_112 , 1 ) ;
F_104 ( V_112 ) ;
if ( V_13 -> V_118 != V_119 )
F_105 ( V_112 , V_13 -> V_118 ) ;
return 0 ;
}
static void F_106 ( struct V_111 * V_2 , unsigned int V_112 )
{
struct V_12 * V_13 = V_2 -> V_114 ;
if ( V_13 -> V_109 )
F_103 ( V_112 , 0 ) ;
F_102 ( V_112 , NULL , NULL ) ;
F_100 ( V_112 , NULL ) ;
}
static int F_107 ( struct V_120 * V_2 )
{
struct V_12 * V_13 = F_108 ( V_2 ) ;
if ( ! F_109 ( V_13 -> V_15 -> V_72 ) )
return - V_41 ;
if ( F_110 ( V_13 , V_2 -> V_113 ) ) {
F_67 ( V_13 ,
L_19 ,
V_2 -> V_113 ) ;
F_111 ( V_13 -> V_15 -> V_72 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_112 ( struct V_120 * V_2 )
{
struct V_12 * V_13 = F_108 ( V_2 ) ;
F_113 ( V_13 , V_2 -> V_113 ) ;
F_111 ( V_13 -> V_15 -> V_72 ) ;
}
static int F_114 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_98 ( V_13 -> V_108 , V_21 ) ;
}
static void F_79 ( struct V_12 * V_103 )
{
unsigned int V_21 ;
F_115 ( V_103 ) ;
if ( V_103 -> V_110 ) {
F_116 ( V_103 -> V_110 , NULL ) ;
F_117 ( V_103 -> V_110 , NULL ) ;
}
if ( V_103 -> V_108 ) {
for ( V_21 = 0 ; V_21 < V_103 -> V_10 ; V_21 ++ )
F_118 (
F_98 ( V_103 -> V_108 , V_21 ) ) ;
F_119 ( V_103 -> V_108 ) ;
}
if ( V_103 -> V_105 ) {
V_103 -> V_105 -> V_121 = NULL ;
V_103 -> V_105 -> V_122 = NULL ;
V_103 -> V_105 = NULL ;
}
}
int F_120 ( struct V_12 * V_103 ,
struct V_104 * V_105 ,
unsigned int V_123 ,
T_3 V_124 ,
unsigned int type ,
struct V_125 * V_115 )
{
struct V_126 * V_87 ;
unsigned int V_21 ;
unsigned V_127 = 0 ;
if ( ! V_103 || ! V_105 )
return - V_16 ;
if ( ! V_103 -> V_75 ) {
F_15 ( L_20 ) ;
return - V_16 ;
}
V_87 = V_103 -> V_75 -> V_87 ;
#ifdef F_61
if ( V_103 -> V_87 )
V_87 = V_103 -> V_87 ;
#endif
V_103 -> V_105 = V_105 ;
V_103 -> V_116 = V_124 ;
V_103 -> V_118 = type ;
V_103 -> V_128 = F_114 ;
V_103 -> V_115 = V_115 ;
V_103 -> V_108 = F_121 ( V_87 ,
V_103 -> V_10 , V_123 ,
& V_129 , V_103 ) ;
if ( ! V_103 -> V_108 ) {
V_103 -> V_105 = NULL ;
return - V_16 ;
}
if ( ! V_105 -> V_121 &&
! V_105 -> V_122 ) {
V_105 -> V_121 = F_107 ;
V_105 -> V_122 = F_112 ;
}
for ( V_21 = 0 ; V_21 < V_103 -> V_10 ; V_21 ++ ) {
V_127 = F_122 ( V_103 -> V_108 , V_21 ) ;
if ( V_21 == 0 )
V_103 -> V_127 = V_127 ;
}
F_123 ( V_103 ) ;
return 0 ;
}
static void F_79 ( struct V_12 * V_103 ) {}
int F_124 ( struct V_12 * V_13 , unsigned V_21 )
{
return F_125 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
void F_126 ( struct V_12 * V_13 , unsigned V_21 )
{
F_127 ( V_13 -> V_15 -> V_9 + V_21 ) ;
}
int F_128 ( struct V_12 * V_13 ,
struct V_130 * V_131 ,
unsigned int V_132 , const char * V_133 )
{
struct V_134 * V_135 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_102 ;
V_135 = F_60 ( sizeof( * V_135 ) , V_83 ) ;
if ( ! V_135 ) {
F_67 ( V_13 , L_21 ) ;
return - V_84 ;
}
V_135 -> V_136 . V_70 = V_132 ;
V_135 -> V_136 . V_33 = V_13 ;
V_135 -> V_136 . V_31 = V_13 -> V_3 ;
V_135 -> V_136 . V_9 = V_6 -> V_9 + V_132 ;
V_135 -> V_131 = V_131 ;
V_102 = F_129 ( V_131 , V_133 ,
& V_135 -> V_136 . V_137 ,
& V_135 -> V_136 . V_138 ) ;
if ( V_102 < 0 ) {
F_46 ( V_135 ) ;
return V_102 ;
}
F_130 ( V_131 , & V_135 -> V_136 ) ;
F_53 ( V_13 , L_22 ,
V_132 , V_132 + V_135 -> V_136 . V_138 - 1 ,
F_131 ( V_131 ) , V_133 ) ;
F_22 ( & V_135 -> V_139 , & V_6 -> V_94 ) ;
return 0 ;
}
int F_132 ( struct V_12 * V_13 , const char * V_140 ,
unsigned int V_132 , unsigned int V_141 ,
unsigned int V_138 )
{
struct V_134 * V_135 ;
struct V_5 * V_6 = V_13 -> V_15 ;
int V_102 ;
V_135 = F_60 ( sizeof( * V_135 ) , V_83 ) ;
if ( ! V_135 ) {
F_67 ( V_13 , L_21 ) ;
return - V_84 ;
}
V_135 -> V_136 . V_70 = V_132 ;
V_135 -> V_136 . V_33 = V_13 ;
V_135 -> V_136 . V_31 = V_13 -> V_3 ;
V_135 -> V_136 . V_9 = V_6 -> V_9 + V_132 ;
V_135 -> V_136 . V_142 = V_141 ;
V_135 -> V_136 . V_138 = V_138 ;
V_135 -> V_131 = F_133 ( V_140 ,
& V_135 -> V_136 ) ;
if ( F_134 ( V_135 -> V_131 ) ) {
V_102 = F_135 ( V_135 -> V_131 ) ;
F_67 ( V_13 , L_23 ) ;
F_46 ( V_135 ) ;
return V_102 ;
}
F_53 ( V_13 , L_24 ,
V_132 , V_132 + V_138 - 1 ,
V_140 ,
V_141 , V_141 + V_138 - 1 ) ;
F_22 ( & V_135 -> V_139 , & V_6 -> V_94 ) ;
return 0 ;
}
void F_80 ( struct V_12 * V_13 )
{
struct V_134 * V_135 , * V_143 ;
struct V_5 * V_6 = V_13 -> V_15 ;
F_25 (pin_range, tmp, &gdev->pin_ranges, node) {
F_44 ( & V_135 -> V_139 ) ;
F_136 ( V_135 -> V_131 ,
& V_135 -> V_136 ) ;
F_46 ( V_135 ) ;
}
}
static int F_137 ( struct V_1 * V_17 , const char * V_3 )
{
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_22 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_138 ( V_52 , & V_17 -> V_7 ) == 0 ) {
F_1 ( V_17 , V_3 ? : L_25 ) ;
V_22 = 0 ;
} else {
V_22 = - V_30 ;
goto V_144;
}
if ( V_13 -> V_145 ) {
F_5 ( & V_8 , V_7 ) ;
V_22 = V_13 -> V_145 ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_22 < 0 ) {
F_1 ( V_17 , NULL ) ;
F_18 ( V_52 , & V_17 -> V_7 ) ;
goto V_144;
}
}
if ( V_13 -> V_23 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_144:
F_5 ( & V_8 , V_7 ) ;
return V_22 ;
}
int F_139 ( struct V_1 * V_17 , const char * V_3 )
{
int V_22 = - V_146 ;
struct V_5 * V_6 ;
F_140 ( V_17 ) ;
V_6 = V_17 -> V_6 ;
if ( F_109 ( V_6 -> V_72 ) ) {
V_22 = F_137 ( V_17 , V_3 ) ;
if ( V_22 < 0 )
F_111 ( V_6 -> V_72 ) ;
else
F_39 ( & V_6 -> V_29 ) ;
}
if ( V_22 )
F_141 ( V_17 , L_26 , V_19 , V_22 ) ;
return V_22 ;
}
static bool F_142 ( struct V_1 * V_17 )
{
bool V_102 = false ;
unsigned long V_7 ;
struct V_12 * V_13 ;
F_143 () ;
F_144 ( V_17 ) ;
F_3 ( & V_8 , V_7 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( V_13 && F_34 ( V_52 , & V_17 -> V_7 ) ) {
if ( V_13 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_145 ( V_13 -> V_109 ) ;
V_13 -> free ( V_13 , F_17 ( V_17 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_17 , NULL ) ;
F_18 ( V_59 , & V_17 -> V_7 ) ;
F_18 ( V_52 , & V_17 -> V_7 ) ;
F_18 ( V_61 , & V_17 -> V_7 ) ;
F_18 ( V_63 , & V_17 -> V_7 ) ;
F_18 ( V_53 , & V_17 -> V_7 ) ;
V_102 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_102 ;
}
void F_146 ( struct V_1 * V_17 )
{
if ( V_17 && V_17 -> V_6 && F_142 ( V_17 ) ) {
F_111 ( V_17 -> V_6 -> V_72 ) ;
F_41 ( & V_17 -> V_6 -> V_29 ) ;
} else {
F_84 ( V_147 ) ;
}
}
const char * F_147 ( struct V_12 * V_13 , unsigned V_21 )
{
struct V_1 * V_17 ;
if ( V_21 >= V_13 -> V_10 )
return NULL ;
V_17 = & V_13 -> V_15 -> V_11 [ V_21 ] ;
if ( F_34 ( V_52 , & V_17 -> V_7 ) == 0 )
return NULL ;
return V_17 -> V_3 ;
}
struct V_1 * F_148 ( struct V_12 * V_13 , T_1 V_14 ,
const char * V_3 )
{
struct V_1 * V_17 = F_8 ( V_13 , V_14 ) ;
int V_81 ;
if ( F_134 ( V_17 ) ) {
F_67 ( V_13 , L_27 ) ;
return V_17 ;
}
V_81 = F_137 ( V_17 , V_3 ) ;
if ( V_81 < 0 )
return F_9 ( V_81 ) ;
return V_17 ;
}
void F_149 ( struct V_1 * V_17 )
{
if ( V_17 )
F_142 ( V_17 ) ;
}
int F_150 ( struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_22 = - V_16 ;
F_140 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_148 || ! V_13 -> V_93 ) {
F_151 ( V_17 ,
L_28 ,
V_19 ) ;
return - V_149 ;
}
V_22 = V_13 -> V_93 ( V_13 , F_17 ( V_17 ) ) ;
if ( V_22 == 0 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
F_152 ( F_10 ( V_17 ) , 1 , V_22 ) ;
return V_22 ;
}
static int F_153 ( struct V_1 * V_17 , int V_150 )
{
struct V_12 * V_33 = V_17 -> V_6 -> V_13 ;
int V_102 ;
if ( F_34 ( V_54 , & V_17 -> V_7 ) ) {
F_154 ( V_17 ,
L_29 ,
V_19 ) ;
return - V_149 ;
}
if ( F_34 ( V_61 , & V_17 -> V_7 ) ) {
if ( V_33 -> V_151 ) {
V_102 = V_33 -> V_151 ( V_33 , F_17 ( V_17 ) ,
V_152 ) ;
if ( ! V_102 )
goto V_153;
}
if ( V_150 )
return F_150 ( V_17 ) ;
}
else if ( F_34 ( V_63 , & V_17 -> V_7 ) ) {
if ( V_33 -> V_151 ) {
V_102 = V_33 -> V_151 ( V_33 , F_17 ( V_17 ) ,
V_154 ) ;
if ( ! V_102 )
goto V_153;
}
if ( ! V_150 )
return F_150 ( V_17 ) ;
} else {
if ( V_33 -> V_151 )
V_33 -> V_151 ( V_33 ,
F_17 ( V_17 ) ,
V_155 ) ;
}
V_153:
if ( ! V_33 -> V_156 || ! V_33 -> V_157 ) {
F_151 ( V_17 ,
L_30 ,
V_19 ) ;
return - V_149 ;
}
V_102 = V_33 -> V_157 ( V_33 , F_17 ( V_17 ) , V_150 ) ;
if ( ! V_102 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
F_155 ( F_10 ( V_17 ) , 0 , V_150 ) ;
F_152 ( F_10 ( V_17 ) , 0 , V_102 ) ;
return V_102 ;
}
int F_156 ( struct V_1 * V_17 , int V_150 )
{
F_140 ( V_17 ) ;
return F_153 ( V_17 , V_150 ) ;
}
int F_157 ( struct V_1 * V_17 , int V_150 )
{
F_140 ( V_17 ) ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_150 = ! V_150 ;
return F_153 ( V_17 , V_150 ) ;
}
int F_158 ( struct V_1 * V_17 , unsigned V_158 )
{
struct V_12 * V_13 ;
F_140 ( V_17 ) ;
V_13 = V_17 -> V_6 -> V_13 ;
if ( ! V_13 -> V_156 || ! V_13 -> V_159 ) {
F_141 ( V_17 ,
L_31 ,
V_19 ) ;
return - V_160 ;
}
return V_13 -> V_159 ( V_13 , F_17 ( V_17 ) , V_158 ) ;
}
int F_159 ( const struct V_1 * V_17 )
{
F_140 ( V_17 ) ;
return F_34 ( V_59 , & V_17 -> V_7 ) ;
}
static int F_160 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
int V_150 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
V_150 = V_13 -> V_148 ? V_13 -> V_148 ( V_13 , V_21 ) : - V_149 ;
V_150 = V_150 < 0 ? V_150 : ! ! V_150 ;
F_155 ( F_10 ( V_17 ) , 1 , V_150 ) ;
return V_150 ;
}
int F_161 ( const struct V_1 * V_17 )
{
F_140 ( V_17 ) ;
F_84 ( V_17 -> V_6 -> V_13 -> V_109 ) ;
return F_160 ( V_17 ) ;
}
int F_162 ( const struct V_1 * V_17 )
{
int V_150 ;
F_140 ( V_17 ) ;
F_84 ( V_17 -> V_6 -> V_13 -> V_109 ) ;
V_150 = F_160 ( V_17 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_150 = ! V_150 ;
return V_150 ;
}
static void F_163 ( struct V_1 * V_17 , bool V_150 )
{
int V_81 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_150 ) {
V_81 = V_13 -> V_93 ( V_13 , V_21 ) ;
if ( ! V_81 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_81 = V_13 -> V_157 ( V_13 , V_21 , 0 ) ;
if ( ! V_81 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
F_152 ( F_10 ( V_17 ) , V_150 , V_81 ) ;
if ( V_81 < 0 )
F_154 ( V_17 ,
L_32 ,
V_19 , V_81 ) ;
}
static void F_164 ( struct V_1 * V_17 , bool V_150 )
{
int V_81 = 0 ;
struct V_12 * V_13 = V_17 -> V_6 -> V_13 ;
int V_21 = F_17 ( V_17 ) ;
if ( V_150 ) {
V_81 = V_13 -> V_157 ( V_13 , V_21 , 1 ) ;
if ( ! V_81 )
F_19 ( V_24 , & V_17 -> V_7 ) ;
} else {
V_81 = V_13 -> V_93 ( V_13 , V_21 ) ;
if ( ! V_81 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
}
F_152 ( F_10 ( V_17 ) , ! V_150 , V_81 ) ;
if ( V_81 < 0 )
F_154 ( V_17 ,
L_33 ,
V_19 , V_81 ) ;
}
static void F_165 ( struct V_1 * V_17 , bool V_150 )
{
struct V_12 * V_13 ;
V_13 = V_17 -> V_6 -> V_13 ;
F_155 ( F_10 ( V_17 ) , 0 , V_150 ) ;
if ( F_34 ( V_61 , & V_17 -> V_7 ) )
F_163 ( V_17 , V_150 ) ;
else if ( F_34 ( V_63 , & V_17 -> V_7 ) )
F_164 ( V_17 , V_150 ) ;
else
V_13 -> V_156 ( V_13 , F_17 ( V_17 ) , V_150 ) ;
}
static void F_166 ( struct V_12 * V_13 ,
unsigned long * V_161 , unsigned long * V_162 )
{
if ( V_13 -> V_163 ) {
V_13 -> V_163 ( V_13 , V_161 , V_162 ) ;
} else {
int V_32 ;
for ( V_32 = 0 ; V_32 < V_13 -> V_10 ; V_32 ++ ) {
if ( V_161 [ F_167 ( V_32 ) ] == 0 ) {
V_32 = ( F_167 ( V_32 ) + 1 ) * V_164 - 1 ;
continue;
}
if ( F_168 ( V_32 , V_161 ) )
V_13 -> V_156 ( V_13 , V_32 , F_34 ( V_32 , V_162 ) ) ;
}
}
}
void F_169 ( bool V_165 , bool V_109 ,
unsigned int V_166 ,
struct V_1 * * V_167 ,
int * V_168 )
{
int V_32 = 0 ;
while ( V_32 < V_166 ) {
struct V_12 * V_13 = V_167 [ V_32 ] -> V_6 -> V_13 ;
unsigned long V_161 [ F_170 ( V_13 -> V_10 ) ] ;
unsigned long V_162 [ F_170 ( V_13 -> V_10 ) ] ;
int V_169 = 0 ;
if ( ! V_109 )
F_84 ( V_13 -> V_109 ) ;
memset ( V_161 , 0 , sizeof( V_161 ) ) ;
do {
struct V_1 * V_17 = V_167 [ V_32 ] ;
int V_170 = F_17 ( V_17 ) ;
int V_150 = V_168 [ V_32 ] ;
if ( ! V_165 && F_34 ( V_59 , & V_17 -> V_7 ) )
V_150 = ! V_150 ;
F_155 ( F_10 ( V_17 ) , 0 , V_150 ) ;
if ( F_34 ( V_61 , & V_17 -> V_7 ) ) {
F_163 ( V_17 , V_150 ) ;
} else if ( F_34 ( V_63 , & V_17 -> V_7 ) ) {
F_164 ( V_17 , V_150 ) ;
} else {
F_171 ( V_170 , V_161 ) ;
if ( V_150 )
F_171 ( V_170 , V_162 ) ;
else
F_172 ( V_170 , V_162 ) ;
V_169 ++ ;
}
V_32 ++ ;
} while ( ( V_32 < V_166 ) &&
( V_167 [ V_32 ] -> V_6 -> V_13 == V_13 ) );
if ( V_169 != 0 )
F_166 ( V_13 , V_161 , V_162 ) ;
}
}
void F_173 ( struct V_1 * V_17 , int V_150 )
{
F_174 ( V_17 ) ;
F_84 ( V_17 -> V_6 -> V_13 -> V_109 ) ;
F_165 ( V_17 , V_150 ) ;
}
void F_175 ( struct V_1 * V_17 , int V_150 )
{
F_174 ( V_17 ) ;
F_84 ( V_17 -> V_6 -> V_13 -> V_109 ) ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_150 = ! V_150 ;
F_165 ( V_17 , V_150 ) ;
}
void F_176 ( unsigned int V_166 ,
struct V_1 * * V_167 , int * V_168 )
{
if ( ! V_167 )
return;
F_169 ( true , false , V_166 , V_167 ,
V_168 ) ;
}
void F_177 ( unsigned int V_166 ,
struct V_1 * * V_167 , int * V_168 )
{
if ( ! V_167 )
return;
F_169 ( false , false , V_166 , V_167 ,
V_168 ) ;
}
int F_178 ( const struct V_1 * V_17 )
{
F_140 ( V_17 ) ;
return V_17 -> V_6 -> V_13 -> V_109 ;
}
int F_179 ( const struct V_1 * V_17 )
{
struct V_12 * V_13 ;
int V_21 ;
if ( ! V_17 || F_134 ( V_17 ) || ! V_17 -> V_6 || ! V_17 -> V_6 -> V_13 )
return - V_16 ;
V_13 = V_17 -> V_6 -> V_13 ;
V_21 = F_17 ( V_17 ) ;
if ( V_13 -> V_128 ) {
int V_171 = V_13 -> V_128 ( V_13 , V_21 ) ;
if ( ! V_171 )
return - V_172 ;
return V_171 ;
}
return - V_172 ;
}
int F_110 ( struct V_12 * V_13 , unsigned int V_21 )
{
struct V_1 * V_17 ;
V_17 = F_8 ( V_13 , V_21 ) ;
if ( F_134 ( V_17 ) )
return F_135 ( V_17 ) ;
if ( V_13 -> V_23 ) {
int V_92 = V_13 -> V_23 ( V_13 , V_21 ) ;
if ( V_92 )
F_18 ( V_24 , & V_17 -> V_7 ) ;
else
F_19 ( V_24 , & V_17 -> V_7 ) ;
}
if ( F_34 ( V_24 , & V_17 -> V_7 ) ) {
F_67 ( V_13 ,
L_34 ,
V_19 ) ;
return - V_149 ;
}
F_19 ( V_54 , & V_17 -> V_7 ) ;
return 0 ;
}
void F_113 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return;
F_18 ( V_54 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_180 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_34 ( V_54 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_181 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_34 ( V_61 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
bool F_182 ( struct V_12 * V_13 , unsigned int V_21 )
{
if ( V_21 >= V_13 -> V_10 )
return false ;
return F_34 ( V_63 , & V_13 -> V_15 -> V_11 [ V_21 ] . V_7 ) ;
}
int F_183 ( const struct V_1 * V_17 )
{
F_145 ( V_147 ) ;
F_140 ( V_17 ) ;
return F_160 ( V_17 ) ;
}
int F_184 ( const struct V_1 * V_17 )
{
int V_150 ;
F_145 ( V_147 ) ;
F_140 ( V_17 ) ;
V_150 = F_160 ( V_17 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_150 = ! V_150 ;
return V_150 ;
}
void F_185 ( struct V_1 * V_17 , int V_150 )
{
F_145 ( V_147 ) ;
F_174 ( V_17 ) ;
F_165 ( V_17 , V_150 ) ;
}
void F_186 ( struct V_1 * V_17 , int V_150 )
{
F_145 ( V_147 ) ;
F_174 ( V_17 ) ;
if ( F_34 ( V_59 , & V_17 -> V_7 ) )
V_150 = ! V_150 ;
F_165 ( V_17 , V_150 ) ;
}
void F_187 ( unsigned int V_166 ,
struct V_1 * * V_167 ,
int * V_168 )
{
F_145 ( V_147 ) ;
if ( ! V_167 )
return;
F_169 ( true , true , V_166 , V_167 ,
V_168 ) ;
}
void F_188 ( unsigned int V_166 ,
struct V_1 * * V_167 ,
int * V_168 )
{
F_145 ( V_147 ) ;
if ( ! V_167 )
return;
F_169 ( false , true , V_166 , V_167 ,
V_168 ) ;
}
void F_189 ( struct V_173 * V_174 )
{
F_190 ( & V_175 ) ;
F_22 ( & V_174 -> V_28 , & V_176 ) ;
F_191 ( & V_175 ) ;
}
void F_192 ( struct V_173 * V_174 )
{
F_190 ( & V_175 ) ;
F_44 ( & V_174 -> V_28 ) ;
F_191 ( & V_175 ) ;
}
static struct V_1 * F_193 ( struct V_68 * V_29 , const char * V_177 ,
unsigned int V_178 ,
enum V_179 * V_7 )
{
char V_180 [ 32 ] ;
enum V_181 V_182 ;
struct V_1 * V_17 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_194 ( V_183 ) ; V_32 ++ ) {
if ( V_177 )
snprintf ( V_180 , sizeof( V_180 ) , L_35 , V_177 ,
V_183 [ V_32 ] ) ;
else
snprintf ( V_180 , sizeof( V_180 ) , L_36 ,
V_183 [ V_32 ] ) ;
V_17 = F_195 ( V_29 -> V_87 , V_180 , V_178 ,
& V_182 ) ;
if ( ! F_134 ( V_17 ) || ( F_135 ( V_17 ) == - V_146 ) )
break;
}
if ( F_134 ( V_17 ) )
return V_17 ;
if ( V_182 & V_184 )
* V_7 |= V_185 ;
if ( V_182 & V_186 ) {
if ( V_182 & V_184 )
* V_7 |= V_187 ;
else
* V_7 |= V_188 ;
}
return V_17 ;
}
static struct V_1 * F_196 ( struct V_68 * V_29 ,
const char * V_177 ,
unsigned int V_178 ,
enum V_189 V_7 ,
enum V_179 * V_190 )
{
struct V_191 * V_192 = F_197 ( V_29 ) ;
struct V_193 V_194 ;
struct V_1 * V_17 ;
char V_195 [ 32 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_194 ( V_183 ) ; V_32 ++ ) {
if ( V_177 && strcmp ( V_177 , L_37 ) ) {
snprintf ( V_195 , sizeof( V_195 ) , L_35 ,
V_177 , V_183 [ V_32 ] ) ;
} else {
snprintf ( V_195 , sizeof( V_195 ) , L_36 ,
V_183 [ V_32 ] ) ;
}
V_17 = F_198 ( V_192 , V_195 , V_178 , & V_194 ) ;
if ( ! F_134 ( V_17 ) || ( F_135 ( V_17 ) == - V_146 ) )
break;
}
if ( F_134 ( V_17 ) ) {
if ( ! F_199 ( V_192 , V_177 ) )
return F_9 ( - V_196 ) ;
V_17 = F_198 ( V_192 , NULL , V_178 , & V_194 ) ;
if ( F_134 ( V_17 ) )
return V_17 ;
if ( ( V_7 == V_197 || V_7 == V_198 ) &&
V_194 . V_199 ) {
F_200 ( V_29 , L_38 ) ;
return F_9 ( - V_196 ) ;
}
}
if ( V_194 . V_200 == V_185 )
* V_190 |= V_185 ;
return V_17 ;
}
static struct V_173 * F_201 ( struct V_68 * V_29 )
{
const char * V_201 = V_29 ? F_31 ( V_29 ) : NULL ;
struct V_173 * V_174 ;
F_190 ( & V_175 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_174 -> V_201 && V_201 ) {
if ( ! strcmp ( V_174 -> V_201 , V_201 ) )
goto V_202;
} else {
if ( V_201 == V_174 -> V_201 )
goto V_202;
}
}
V_174 = NULL ;
V_202:
F_191 ( & V_175 ) ;
return V_174 ;
}
static struct V_1 * F_202 ( struct V_68 * V_29 , const char * V_177 ,
unsigned int V_178 ,
enum V_179 * V_7 )
{
struct V_1 * V_17 = F_9 ( - V_196 ) ;
struct V_173 * V_174 ;
struct V_203 * V_204 ;
V_174 = F_201 ( V_29 ) ;
if ( ! V_174 )
return V_17 ;
for ( V_204 = & V_174 -> V_174 [ 0 ] ; V_204 -> V_205 ; V_204 ++ ) {
struct V_12 * V_13 ;
if ( V_204 -> V_178 != V_178 )
continue;
if ( V_204 -> V_177 && ( ! V_177 || strcmp ( V_204 -> V_177 , V_177 ) ) )
continue;
V_13 = F_94 ( V_204 -> V_205 ) ;
if ( ! V_13 ) {
F_26 ( V_29 , L_39 ,
V_204 -> V_205 ) ;
return F_9 ( - V_41 ) ;
}
if ( V_13 -> V_10 <= V_204 -> V_206 ) {
F_26 ( V_29 ,
L_40 ,
V_178 , V_13 -> V_10 , V_13 -> V_3 ) ;
return F_9 ( - V_16 ) ;
}
V_17 = F_8 ( V_13 , V_204 -> V_206 ) ;
* V_7 = V_204 -> V_7 ;
return V_17 ;
}
return V_17 ;
}
static int F_203 ( struct V_68 * V_29 , const char * V_177 )
{
int V_102 ;
char V_195 [ 32 ] ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_194 ( V_183 ) ; V_32 ++ ) {
if ( V_177 )
snprintf ( V_195 , sizeof( V_195 ) , L_35 ,
V_177 , V_183 [ V_32 ] ) ;
else
snprintf ( V_195 , sizeof( V_195 ) , L_36 ,
V_183 [ V_32 ] ) ;
V_102 = F_204 ( V_29 -> V_87 , V_195 ) ;
if ( V_102 >= 0 )
break;
}
return V_102 ;
}
static int F_205 ( struct V_68 * V_29 , const char * V_177 )
{
struct V_173 * V_174 ;
struct V_203 * V_204 ;
unsigned int V_169 = 0 ;
V_174 = F_201 ( V_29 ) ;
if ( ! V_174 )
return - V_196 ;
for ( V_204 = & V_174 -> V_174 [ 0 ] ; V_204 -> V_205 ; V_204 ++ ) {
if ( ( V_177 && V_204 -> V_177 && ! strcmp ( V_177 , V_204 -> V_177 ) ) ||
( ! V_177 && ! V_204 -> V_177 ) )
V_169 ++ ;
}
if ( ! V_169 )
return - V_196 ;
return V_169 ;
}
int F_206 ( struct V_68 * V_29 , const char * V_177 )
{
int V_169 = - V_196 ;
if ( F_207 ( V_207 ) && V_29 && V_29 -> V_87 )
V_169 = F_203 ( V_29 , V_177 ) ;
else if ( F_207 ( V_208 ) && V_29 && F_208 ( V_29 ) )
V_169 = F_209 ( V_29 , V_177 ) ;
if ( V_169 < 0 )
V_169 = F_205 ( V_29 , V_177 ) ;
return V_169 ;
}
struct V_1 * T_5 F_210 ( struct V_68 * V_29 , const char * V_177 ,
enum V_189 V_7 )
{
return F_211 ( V_29 , V_177 , 0 , V_7 ) ;
}
struct V_1 * T_5 F_212 ( struct V_68 * V_29 ,
const char * V_177 ,
enum V_189 V_7 )
{
return F_213 ( V_29 , V_177 , 0 , V_7 ) ;
}
static int F_214 ( struct V_1 * V_17 , const char * V_177 ,
unsigned long V_209 , enum V_189 V_210 )
{
int V_22 ;
if ( V_209 & V_185 )
F_19 ( V_59 , & V_17 -> V_7 ) ;
if ( V_209 & V_187 )
F_19 ( V_61 , & V_17 -> V_7 ) ;
if ( V_209 & V_188 )
F_19 ( V_63 , & V_17 -> V_7 ) ;
if ( ! ( V_210 & V_211 ) ) {
F_14 ( L_41 , V_177 ) ;
return 0 ;
}
if ( V_210 & V_212 )
V_22 = F_157 ( V_17 ,
V_210 & V_213 ) ;
else
V_22 = F_150 ( V_17 ) ;
return V_22 ;
}
struct V_1 * T_5 F_211 ( struct V_68 * V_29 ,
const char * V_177 ,
unsigned int V_178 ,
enum V_189 V_7 )
{
struct V_1 * V_17 = NULL ;
int V_22 ;
enum V_179 V_190 = 0 ;
F_200 ( V_29 , L_42 , V_177 ) ;
if ( V_29 ) {
if ( F_207 ( V_207 ) && V_29 -> V_87 ) {
F_200 ( V_29 , L_43 ) ;
V_17 = F_193 ( V_29 , V_177 , V_178 , & V_190 ) ;
} else if ( F_197 ( V_29 ) ) {
F_200 ( V_29 , L_44 ) ;
V_17 = F_196 ( V_29 , V_177 , V_178 , V_7 , & V_190 ) ;
}
}
if ( ! V_17 || V_17 == F_9 ( - V_196 ) ) {
F_200 ( V_29 , L_45 ) ;
V_17 = F_202 ( V_29 , V_177 , V_178 , & V_190 ) ;
}
if ( F_134 ( V_17 ) ) {
F_200 ( V_29 , L_46 , V_177 ) ;
return V_17 ;
}
V_22 = F_139 ( V_17 , V_177 ) ;
if ( V_22 < 0 )
return F_9 ( V_22 ) ;
V_22 = F_214 ( V_17 , V_177 , V_190 , V_7 ) ;
if ( V_22 < 0 ) {
F_200 ( V_29 , L_47 , V_177 ) ;
F_215 ( V_17 ) ;
return F_9 ( V_22 ) ;
}
return V_17 ;
}
struct V_1 * F_216 ( struct V_214 * V_215 ,
const char * V_195 )
{
struct V_1 * V_17 = F_9 ( - V_41 ) ;
bool V_216 = false ;
bool V_217 = false ;
int V_102 ;
if ( ! V_215 )
return F_9 ( - V_16 ) ;
if ( F_217 ( V_215 ) ) {
enum V_181 V_7 ;
V_17 = F_195 ( F_218 ( V_215 ) , V_195 , 0 ,
& V_7 ) ;
if ( ! F_134 ( V_17 ) ) {
V_216 = V_7 & V_184 ;
V_217 = V_7 & V_186 ;
}
} else if ( F_219 ( V_215 ) ) {
struct V_193 V_194 ;
V_17 = F_220 ( V_215 , V_195 , 0 , & V_194 ) ;
if ( ! F_134 ( V_17 ) )
V_216 = V_194 . V_200 == V_185 ;
}
if ( F_134 ( V_17 ) )
return V_17 ;
V_102 = F_139 ( V_17 , NULL ) ;
if ( V_102 )
return F_9 ( V_102 ) ;
if ( V_216 )
F_19 ( V_59 , & V_17 -> V_7 ) ;
if ( V_217 ) {
if ( V_216 )
F_19 ( V_61 , & V_17 -> V_7 ) ;
else
F_19 ( V_63 , & V_17 -> V_7 ) ;
}
return V_17 ;
}
struct V_1 * T_5 F_213 ( struct V_68 * V_29 ,
const char * V_177 ,
unsigned int V_218 ,
enum V_189 V_7 )
{
struct V_1 * V_17 ;
V_17 = F_211 ( V_29 , V_177 , V_218 , V_7 ) ;
if ( F_134 ( V_17 ) ) {
if ( F_135 ( V_17 ) == - V_196 )
return NULL ;
}
return V_17 ;
}
int F_221 ( struct V_1 * V_17 , const char * V_31 ,
unsigned long V_209 , enum V_189 V_210 )
{
struct V_12 * V_13 ;
struct V_1 * V_219 ;
int V_14 ;
int V_22 ;
V_13 = F_11 ( V_17 ) ;
V_14 = F_17 ( V_17 ) ;
V_219 = F_148 ( V_13 , V_14 , V_31 ) ;
if ( F_134 ( V_219 ) ) {
V_22 = F_135 ( V_219 ) ;
F_15 ( L_48 ,
V_31 , V_13 -> V_3 , V_14 , V_22 ) ;
return V_22 ;
}
V_22 = F_214 ( V_17 , V_31 , V_209 , V_210 ) ;
if ( V_22 < 0 ) {
F_15 ( L_49 ,
V_31 , V_13 -> V_3 , V_14 , V_22 ) ;
F_149 ( V_17 ) ;
return V_22 ;
}
F_19 ( V_53 , & V_17 -> V_7 ) ;
F_222 ( L_50 ,
F_10 ( V_17 ) , V_31 ,
( V_210 & V_212 ) ? L_51 : L_52 ,
( V_210 & V_212 ) ?
( V_210 & V_213 ) ? L_53 : L_54 : L_55 ) ;
return 0 ;
}
static void F_74 ( struct V_12 * V_13 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_13 -> V_10 ; V_70 ++ ) {
if ( F_34 ( V_53 , & V_13 -> V_15 -> V_11 [ V_70 ] . V_7 ) )
F_149 ( & V_13 -> V_15 -> V_11 [ V_70 ] ) ;
}
}
struct V_220 * T_5 F_223 ( struct V_68 * V_29 ,
const char * V_177 ,
enum V_189 V_7 )
{
struct V_1 * V_17 ;
struct V_220 * V_11 ;
int V_169 ;
V_169 = F_206 ( V_29 , V_177 ) ;
if ( V_169 < 0 )
return F_9 ( V_169 ) ;
V_11 = F_60 ( sizeof( * V_11 ) + sizeof( V_11 -> V_17 [ 0 ] ) * V_169 ,
V_83 ) ;
if ( ! V_11 )
return F_9 ( - V_84 ) ;
for ( V_11 -> V_221 = 0 ; V_11 -> V_221 < V_169 ; ) {
V_17 = F_211 ( V_29 , V_177 , V_11 -> V_221 , V_7 ) ;
if ( F_134 ( V_17 ) ) {
F_224 ( V_11 ) ;
return F_225 ( V_17 ) ;
}
V_11 -> V_17 [ V_11 -> V_221 ] = V_17 ;
V_11 -> V_221 ++ ;
}
return V_11 ;
}
struct V_220 * T_5 F_226 ( struct V_68 * V_29 ,
const char * V_177 ,
enum V_189 V_7 )
{
struct V_220 * V_11 ;
V_11 = F_223 ( V_29 , V_177 , V_7 ) ;
if ( F_134 ( V_11 ) && ( F_135 ( V_11 ) == - V_196 ) )
return NULL ;
return V_11 ;
}
void F_215 ( struct V_1 * V_17 )
{
F_146 ( V_17 ) ;
}
void F_224 ( struct V_220 * V_11 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_11 -> V_221 ; V_32 ++ )
F_215 ( V_11 -> V_17 [ V_32 ] ) ;
F_46 ( V_11 ) ;
}
static int T_6 F_227 ( void )
{
int V_102 ;
V_102 = F_228 ( & V_86 ) ;
if ( V_102 < 0 ) {
F_15 ( L_56 ) ;
return V_102 ;
}
V_102 = F_229 ( & V_77 , 0 , V_222 , L_57 ) ;
if ( V_102 < 0 ) {
F_15 ( L_58 ) ;
F_230 ( & V_86 ) ;
} else {
V_97 = true ;
F_58 () ;
}
return V_102 ;
}
static void F_231 ( struct V_223 * V_224 , struct V_5 * V_6 )
{
unsigned V_32 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_225 = & V_6 -> V_11 [ 0 ] ;
int V_226 ;
int V_227 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_10 ; V_32 ++ , V_4 ++ , V_225 ++ ) {
if ( ! F_34 ( V_52 , & V_225 -> V_7 ) ) {
if ( V_225 -> V_31 ) {
F_232 ( V_224 , L_59 ,
V_4 , V_225 -> V_31 ) ;
}
continue;
}
F_16 ( V_225 ) ;
V_226 = F_34 ( V_24 , & V_225 -> V_7 ) ;
V_227 = F_34 ( V_54 , & V_225 -> V_7 ) ;
F_232 ( V_224 , L_60 ,
V_4 , V_225 -> V_31 ? V_225 -> V_31 : L_55 , V_225 -> V_3 ,
V_226 ? L_61 : L_62 ,
V_13 -> V_148
? ( V_13 -> V_148 ( V_13 , V_32 ) ? L_63 : L_64 )
: L_65 ,
V_227 ? L_66 : L_67 ) ;
F_232 ( V_224 , L_68 ) ;
}
}
static void * F_233 ( struct V_223 * V_224 , T_7 * V_228 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_7 V_218 = * V_228 ;
V_224 -> V_229 = L_55 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (gdev, &gpio_devices, list)
if ( V_218 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_234 ( struct V_223 * V_224 , void * V_230 , T_7 * V_228 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_230 ;
void * V_102 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_235 ( & V_6 -> V_28 , & V_27 ) )
V_102 = NULL ;
else
V_102 = F_23 ( V_6 -> V_28 . V_26 , struct V_5 , V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_224 -> V_229 = L_68 ;
++ * V_228 ;
return V_102 ;
}
static void F_236 ( struct V_223 * V_224 , void * V_230 )
{
}
static int F_237 ( struct V_223 * V_224 , void * V_230 )
{
struct V_5 * V_6 = V_230 ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_68 * V_75 ;
if ( ! V_13 ) {
F_232 ( V_224 , L_69 , ( char * ) V_224 -> V_229 ,
F_31 ( & V_6 -> V_29 ) ) ;
return 0 ;
}
F_232 ( V_224 , L_70 , ( char * ) V_224 -> V_229 ,
F_31 ( & V_6 -> V_29 ) ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_75 = V_13 -> V_75 ;
if ( V_75 )
F_232 ( V_224 , L_71 ,
V_75 -> V_85 ? V_75 -> V_85 -> V_31 : L_72 ,
F_31 ( V_75 ) ) ;
if ( V_13 -> V_3 )
F_232 ( V_224 , L_73 , V_13 -> V_3 ) ;
if ( V_13 -> V_109 )
F_232 ( V_224 , L_74 ) ;
F_232 ( V_224 , L_75 ) ;
if ( V_13 -> V_231 )
V_13 -> V_231 ( V_224 , V_13 ) ;
else
F_231 ( V_224 , V_6 ) ;
return 0 ;
}
static int F_238 ( struct V_65 * V_65 , struct V_35 * V_35 )
{
return F_239 ( V_35 , & V_232 ) ;
}
static int T_6 F_240 ( void )
{
( void ) F_241 ( L_76 , V_233 | V_234 ,
NULL , NULL , & V_235 ) ;
return 0 ;
}
