static inline void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
V_2 -> V_3 = V_3 ;
}
struct V_1 * F_2 ( unsigned V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list) {
if ( V_6 -> V_9 <= V_4 && V_6 -> V_9 + V_6 -> V_10 > V_4 ) {
F_5 ( & V_8 , V_7 ) ;
return & V_6 -> V_11 [ V_4 - V_6 -> V_9 ] ;
}
}
F_5 ( & V_8 , V_7 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( 1 , L_1 , V_4 ) ;
return NULL ;
}
struct V_1 * F_8 ( struct V_5 * V_6 ,
T_1 V_12 )
{
if ( V_12 >= V_6 -> V_10 )
return F_9 ( - V_13 ) ;
return & V_6 -> V_11 [ V_12 ] ;
}
int F_10 ( const struct V_1 * V_11 )
{
return V_11 -> V_6 -> V_9 + ( V_11 - & V_11 -> V_6 -> V_11 [ 0 ] ) ;
}
struct V_5 * F_11 ( const struct V_1 * V_11 )
{
return V_11 ? V_11 -> V_6 : NULL ;
}
static int F_12 ( int V_10 )
{
struct V_5 * V_6 ;
int V_9 = V_14 - V_10 ;
F_13 (chip, &gpio_chips, list) {
if ( V_6 -> V_9 + V_6 -> V_10 <= V_9 )
break;
else
V_9 = V_6 -> V_9 - V_10 ;
}
if ( F_6 ( V_9 ) ) {
F_14 ( L_2 , V_15 , V_9 ) ;
return V_9 ;
} else {
F_15 ( L_3 , V_15 ) ;
return - V_16 ;
}
}
int F_16 ( struct V_1 * V_11 )
{
struct V_5 * V_6 ;
unsigned V_17 ;
int V_18 = - V_13 ;
V_6 = F_11 ( V_11 ) ;
V_17 = F_17 ( V_11 ) ;
if ( ! V_6 -> V_19 )
return V_18 ;
V_18 = V_6 -> V_19 ( V_6 , V_17 ) ;
if ( V_18 > 0 ) {
V_18 = 1 ;
F_18 ( V_20 , & V_11 -> V_7 ) ;
}
if ( V_18 == 0 ) {
F_19 ( V_20 , & V_11 -> V_7 ) ;
}
return V_18 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_5 * V_21 ;
struct V_5 * V_22 = NULL ;
if ( F_21 ( & V_23 ) ) {
F_22 ( & V_6 -> V_24 , & V_23 ) ;
return 0 ;
}
F_4 (iterator, &gpio_chips, list) {
if ( V_21 -> V_9 >= V_6 -> V_9 + V_6 -> V_10 ) {
if ( ! V_22 ) {
goto V_25;
} else {
if ( V_22 -> V_9 + V_22 -> V_10
<= V_6 -> V_9 )
goto V_25;
}
}
V_22 = V_21 ;
}
V_21 = F_23 ( & V_23 , struct V_5 , V_24 ) ;
if ( V_21 -> V_9 + V_21 -> V_10 <= V_6 -> V_9 ) {
F_24 ( & V_6 -> V_24 , & V_21 -> V_24 ) ;
return 0 ;
}
F_25 ( V_6 -> V_26 ,
L_4 ) ;
return - V_27 ;
V_25:
F_22 ( & V_6 -> V_24 , & V_21 -> V_24 ) ;
return 0 ;
}
static struct V_1 * F_26 ( const char * const V_28 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list) {
int V_29 ;
for ( V_29 = 0 ; V_29 != V_6 -> V_10 ; ++ V_29 ) {
struct V_1 * V_4 = & V_6 -> V_11 [ V_29 ] ;
if ( ! V_4 -> V_28 || ! V_28 )
continue;
if ( ! strcmp ( V_4 -> V_28 , V_28 ) ) {
F_5 ( & V_8 , V_7 ) ;
return V_4 ;
}
}
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static int F_27 ( struct V_5 * V_30 )
{
int V_29 ;
if ( ! V_30 -> V_31 )
return 0 ;
for ( V_29 = 0 ; V_29 != V_30 -> V_10 ; ++ V_29 ) {
struct V_1 * V_4 ;
V_4 = F_26 ( V_30 -> V_31 [ V_29 ] ) ;
if ( V_4 )
F_28 ( V_30 -> V_26 , L_5
L_6 ,
V_30 -> V_31 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 != V_30 -> V_10 ; ++ V_29 )
V_30 -> V_11 [ V_29 ] . V_28 = V_30 -> V_31 [ V_29 ] ;
return 0 ;
}
int F_29 ( struct V_5 * V_6 , void * V_32 )
{
unsigned long V_7 ;
int V_18 = 0 ;
unsigned V_33 ;
int V_9 = V_6 -> V_9 ;
struct V_1 * V_34 ;
V_34 = F_30 ( V_6 -> V_10 , sizeof( V_34 [ 0 ] ) , V_35 ) ;
if ( ! V_34 )
return - V_36 ;
V_6 -> V_32 = V_32 ;
if ( V_6 -> V_10 == 0 ) {
F_31 ( V_6 , L_7 ) ;
return - V_13 ;
}
F_3 ( & V_8 , V_7 ) ;
if ( V_9 < 0 ) {
V_9 = F_12 ( V_6 -> V_10 ) ;
if ( V_9 < 0 ) {
V_18 = V_9 ;
F_5 ( & V_8 , V_7 ) ;
goto V_37;
}
V_6 -> V_9 = V_9 ;
}
V_18 = F_20 ( V_6 ) ;
if ( V_18 ) {
F_5 ( & V_8 , V_7 ) ;
goto V_37;
}
for ( V_33 = 0 ; V_33 < V_6 -> V_10 ; V_33 ++ ) {
struct V_1 * V_11 = & V_34 [ V_33 ] ;
V_11 -> V_6 = V_6 ;
V_11 -> V_7 = ! V_6 -> V_38 ? ( 1 << V_20 ) : 0 ;
}
V_6 -> V_11 = V_34 ;
F_5 ( & V_8 , V_7 ) ;
#ifdef F_32
F_33 ( & V_6 -> V_39 ) ;
#endif
if ( ! V_6 -> V_40 && V_6 -> V_26 && V_6 -> V_26 -> V_41 )
V_6 -> V_40 = V_6 -> V_26 -> V_41 -> V_40 ;
V_18 = F_27 ( V_6 ) ;
if ( V_18 )
goto V_42;
V_18 = F_34 ( V_6 ) ;
if ( V_18 )
goto V_43;
F_35 ( V_6 ) ;
V_18 = F_36 ( V_6 ) ;
if ( V_18 )
goto V_43;
F_14 ( L_8 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_9 ) ;
return 0 ;
V_43:
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
V_42:
F_3 ( & V_8 , V_7 ) ;
F_40 ( & V_6 -> V_24 ) ;
F_5 ( & V_8 , V_7 ) ;
V_6 -> V_11 = NULL ;
V_37:
F_41 ( V_34 ) ;
F_15 ( L_10 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_9 ) ;
return V_18 ;
}
void F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_11 ;
unsigned long V_7 ;
unsigned V_33 ;
bool V_44 = false ;
F_43 ( V_6 ) ;
F_44 ( V_6 ) ;
F_37 ( V_6 ) ;
F_45 ( V_6 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_3 ( & V_8 , V_7 ) ;
for ( V_33 = 0 ; V_33 < V_6 -> V_10 ; V_33 ++ ) {
V_11 = & V_6 -> V_11 [ V_33 ] ;
V_11 -> V_6 = NULL ;
if ( F_46 ( V_45 , & V_11 -> V_7 ) )
V_44 = true ;
}
F_40 ( & V_6 -> V_24 ) ;
F_5 ( & V_8 , V_7 ) ;
if ( V_44 )
F_47 ( V_6 -> V_26 ,
L_11 ) ;
F_41 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
struct V_5 * F_48 ( void * V_32 ,
int (* F_49)( struct V_5 * V_6 ,
void * V_32 ) )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( F_49 ( V_6 , V_32 ) )
break;
if ( & V_6 -> V_24 == & V_23 )
V_6 = NULL ;
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
static int F_50 ( struct V_5 * V_6 , void * V_32 )
{
const char * V_28 = V_32 ;
return ! strcmp ( V_6 -> V_3 , V_28 ) ;
}
static struct V_5 * F_51 ( const char * V_28 )
{
return F_48 ( ( void * ) V_28 , F_50 ) ;
}
void F_52 ( struct V_5 * V_46 ,
struct V_47 * V_48 ,
int V_49 ,
T_2 V_50 )
{
unsigned int V_17 ;
if ( ! V_46 -> V_51 ) {
F_31 ( V_46 , L_12 ,
V_15 ) ;
return;
}
if ( V_50 ) {
if ( V_46 -> V_52 ) {
F_31 ( V_46 ,
L_13
L_14 ) ;
return;
}
F_53 ( V_49 , V_50 ,
V_46 ) ;
V_46 -> V_53 = V_49 ;
}
for ( V_17 = 0 ; V_17 < V_46 -> V_10 ; V_17 ++ )
F_54 ( F_55 ( V_46 -> V_51 , V_17 ) ,
V_49 ) ;
}
static int F_56 ( struct V_54 * V_2 , unsigned int V_55 ,
T_3 V_56 )
{
struct V_5 * V_6 = V_2 -> V_57 ;
F_57 ( V_55 , V_6 ) ;
F_58 ( V_55 , V_6 -> V_58 ) ;
F_59 ( V_55 , V_6 -> V_48 , V_6 -> V_59 ) ;
if ( V_6 -> V_52 && ! V_6 -> V_60 )
F_60 ( V_55 , 1 ) ;
F_61 ( V_55 ) ;
if ( V_6 -> V_61 != V_62 )
F_62 ( V_55 , V_6 -> V_61 ) ;
return 0 ;
}
static void F_63 ( struct V_54 * V_2 , unsigned int V_55 )
{
struct V_5 * V_6 = V_2 -> V_57 ;
if ( V_6 -> V_52 )
F_60 ( V_55 , 0 ) ;
F_59 ( V_55 , NULL , NULL ) ;
F_57 ( V_55 , NULL ) ;
}
static int F_64 ( struct V_63 * V_2 )
{
struct V_5 * V_6 = F_65 ( V_2 ) ;
if ( ! F_66 ( V_6 -> V_40 ) )
return - V_64 ;
if ( F_67 ( V_6 , V_2 -> V_56 ) ) {
F_31 ( V_6 ,
L_15 ,
V_2 -> V_56 ) ;
F_68 ( V_6 -> V_40 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_69 ( struct V_63 * V_2 )
{
struct V_5 * V_6 = F_65 ( V_2 ) ;
F_70 ( V_6 , V_2 -> V_56 ) ;
F_68 ( V_6 -> V_40 ) ;
}
static int F_71 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_55 ( V_6 -> V_51 , V_17 ) ;
}
static void F_44 ( struct V_5 * V_46 )
{
unsigned int V_17 ;
F_72 ( V_46 ) ;
if ( V_46 -> V_53 ) {
F_73 ( V_46 -> V_53 , NULL ) ;
F_74 ( V_46 -> V_53 , NULL ) ;
}
if ( V_46 -> V_51 ) {
for ( V_17 = 0 ; V_17 < V_46 -> V_10 ; V_17 ++ )
F_75 (
F_55 ( V_46 -> V_51 , V_17 ) ) ;
F_76 ( V_46 -> V_51 ) ;
}
if ( V_46 -> V_48 ) {
V_46 -> V_48 -> V_65 = NULL ;
V_46 -> V_48 -> V_66 = NULL ;
V_46 -> V_48 = NULL ;
}
}
int F_77 ( struct V_5 * V_46 ,
struct V_47 * V_48 ,
unsigned int V_67 ,
T_2 V_68 ,
unsigned int type ,
struct V_69 * V_58 )
{
struct V_70 * V_71 ;
unsigned int V_17 ;
unsigned V_72 = 0 ;
if ( ! V_46 || ! V_48 )
return - V_13 ;
if ( ! V_46 -> V_26 ) {
F_15 ( L_16 ) ;
return - V_13 ;
}
V_71 = V_46 -> V_26 -> V_71 ;
#ifdef F_78
if ( V_46 -> V_71 )
V_71 = V_46 -> V_71 ;
#endif
V_46 -> V_48 = V_48 ;
V_46 -> V_59 = V_68 ;
V_46 -> V_61 = type ;
V_46 -> V_73 = F_71 ;
V_46 -> V_58 = V_58 ;
V_46 -> V_51 = F_79 ( V_71 ,
V_46 -> V_10 , V_67 ,
& V_74 , V_46 ) ;
if ( ! V_46 -> V_51 ) {
V_46 -> V_48 = NULL ;
return - V_13 ;
}
if ( ! V_48 -> V_65 &&
! V_48 -> V_66 ) {
V_48 -> V_65 = F_64 ;
V_48 -> V_66 = F_69 ;
}
for ( V_17 = 0 ; V_17 < V_46 -> V_10 ; V_17 ++ ) {
V_72 = F_80 ( V_46 -> V_51 , V_17 ) ;
if ( V_17 == 0 )
V_46 -> V_72 = V_72 ;
}
F_81 ( V_46 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_46 ) {}
int F_82 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_83 ( V_6 -> V_9 + V_17 ) ;
}
void F_84 ( struct V_5 * V_6 , unsigned V_17 )
{
F_85 ( V_6 -> V_9 + V_17 ) ;
}
int F_86 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
unsigned int V_77 , const char * V_78 )
{
struct V_79 * V_80 ;
int V_81 ;
V_80 = F_87 ( sizeof( * V_80 ) , V_35 ) ;
if ( ! V_80 ) {
F_31 ( V_6 , L_17 ) ;
return - V_36 ;
}
V_80 -> V_82 . V_33 = V_77 ;
V_80 -> V_82 . V_30 = V_6 ;
V_80 -> V_82 . V_28 = V_6 -> V_3 ;
V_80 -> V_82 . V_9 = V_6 -> V_9 + V_77 ;
V_80 -> V_76 = V_76 ;
V_81 = F_88 ( V_76 , V_78 ,
& V_80 -> V_82 . V_83 ,
& V_80 -> V_82 . V_84 ) ;
if ( V_81 < 0 ) {
F_41 ( V_80 ) ;
return V_81 ;
}
F_89 ( V_76 , & V_80 -> V_82 ) ;
F_90 ( V_6 , L_18 ,
V_77 , V_77 + V_80 -> V_82 . V_84 - 1 ,
F_91 ( V_76 ) , V_78 ) ;
F_22 ( & V_80 -> V_85 , & V_6 -> V_39 ) ;
return 0 ;
}
int F_92 ( struct V_5 * V_6 , const char * V_86 ,
unsigned int V_77 , unsigned int V_87 ,
unsigned int V_84 )
{
struct V_79 * V_80 ;
int V_81 ;
V_80 = F_87 ( sizeof( * V_80 ) , V_35 ) ;
if ( ! V_80 ) {
F_31 ( V_6 , L_17 ) ;
return - V_36 ;
}
V_80 -> V_82 . V_33 = V_77 ;
V_80 -> V_82 . V_30 = V_6 ;
V_80 -> V_82 . V_28 = V_6 -> V_3 ;
V_80 -> V_82 . V_9 = V_6 -> V_9 + V_77 ;
V_80 -> V_82 . V_88 = V_87 ;
V_80 -> V_82 . V_84 = V_84 ;
V_80 -> V_76 = F_93 ( V_86 ,
& V_80 -> V_82 ) ;
if ( F_94 ( V_80 -> V_76 ) ) {
V_81 = F_95 ( V_80 -> V_76 ) ;
F_31 ( V_6 , L_19 ) ;
F_41 ( V_80 ) ;
return V_81 ;
}
F_90 ( V_6 , L_20 ,
V_77 , V_77 + V_84 - 1 ,
V_86 ,
V_87 , V_87 + V_84 - 1 ) ;
F_22 ( & V_80 -> V_85 , & V_6 -> V_39 ) ;
return 0 ;
}
void F_45 ( struct V_5 * V_6 )
{
struct V_79 * V_80 , * V_89 ;
F_96 (pin_range, tmp, &chip->pin_ranges, node) {
F_40 ( & V_80 -> V_85 ) ;
F_97 ( V_80 -> V_76 ,
& V_80 -> V_82 ) ;
F_41 ( V_80 ) ;
}
}
static int F_98 ( struct V_1 * V_11 , const char * V_3 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
int V_18 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_99 ( V_45 , & V_11 -> V_7 ) == 0 ) {
F_1 ( V_11 , V_3 ? : L_21 ) ;
V_18 = 0 ;
} else {
V_18 = - V_27 ;
goto V_90;
}
if ( V_6 -> V_91 ) {
F_5 ( & V_8 , V_7 ) ;
V_18 = V_6 -> V_91 ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_18 < 0 ) {
F_1 ( V_11 , NULL ) ;
F_18 ( V_45 , & V_11 -> V_7 ) ;
goto V_90;
}
}
if ( V_6 -> V_19 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_90:
if ( V_18 < 0 ) {
F_18 ( V_92 , & V_11 -> V_7 ) ;
F_18 ( V_93 , & V_11 -> V_7 ) ;
F_18 ( V_94 , & V_11 -> V_7 ) ;
}
F_5 ( & V_8 , V_7 ) ;
return V_18 ;
}
int F_100 ( struct V_1 * V_11 , const char * V_3 )
{
int V_18 = - V_95 ;
struct V_5 * V_6 ;
if ( ! V_11 ) {
F_101 ( L_22 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 )
goto V_90;
if ( F_66 ( V_6 -> V_40 ) ) {
V_18 = F_98 ( V_11 , V_3 ) ;
if ( V_18 < 0 )
F_68 ( V_6 -> V_40 ) ;
}
V_90:
if ( V_18 )
F_102 ( V_11 , L_23 , V_15 , V_18 ) ;
return V_18 ;
}
static bool F_103 ( struct V_1 * V_11 )
{
bool V_81 = false ;
unsigned long V_7 ;
struct V_5 * V_6 ;
F_104 () ;
F_105 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
V_6 = V_11 -> V_6 ;
if ( V_6 && F_46 ( V_45 , & V_11 -> V_7 ) ) {
if ( V_6 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_106 ( V_6 -> V_52 ) ;
V_6 -> free ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_11 , NULL ) ;
F_18 ( V_92 , & V_11 -> V_7 ) ;
F_18 ( V_45 , & V_11 -> V_7 ) ;
F_18 ( V_93 , & V_11 -> V_7 ) ;
F_18 ( V_94 , & V_11 -> V_7 ) ;
F_18 ( V_96 , & V_11 -> V_7 ) ;
V_81 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_81 ;
}
void F_107 ( struct V_1 * V_11 )
{
if ( V_11 && F_103 ( V_11 ) )
F_68 ( V_11 -> V_6 -> V_40 ) ;
else
F_108 ( V_97 ) ;
}
const char * F_109 ( struct V_5 * V_6 , unsigned V_17 )
{
struct V_1 * V_11 ;
if ( V_17 >= V_6 -> V_10 )
return NULL ;
V_11 = & V_6 -> V_11 [ V_17 ] ;
if ( F_46 ( V_45 , & V_11 -> V_7 ) == 0 )
return NULL ;
return V_11 -> V_3 ;
}
struct V_1 * F_110 ( struct V_5 * V_6 , T_1 V_12 ,
const char * V_3 )
{
struct V_1 * V_11 = F_8 ( V_6 , V_12 ) ;
int V_98 ;
if ( F_94 ( V_11 ) ) {
F_31 ( V_6 , L_24 ) ;
return V_11 ;
}
V_98 = F_98 ( V_11 , V_3 ) ;
if ( V_98 < 0 )
return F_9 ( V_98 ) ;
return V_11 ;
}
void F_111 ( struct V_1 * V_11 )
{
if ( V_11 )
F_103 ( V_11 ) ;
}
int F_112 ( struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_101 ( L_22 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_99 || ! V_6 -> V_38 ) {
F_113 ( V_11 ,
L_25 ,
V_15 ) ;
return - V_100 ;
}
V_18 = V_6 -> V_38 ( V_6 , F_17 ( V_11 ) ) ;
if ( V_18 == 0 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
F_114 ( F_10 ( V_11 ) , 1 , V_18 ) ;
return V_18 ;
}
static int F_115 ( struct V_1 * V_11 , int V_101 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( F_46 ( V_102 , & V_11 -> V_7 ) ) {
F_116 ( V_11 ,
L_26 ,
V_15 ) ;
return - V_100 ;
}
if ( V_101 && F_46 ( V_93 , & V_11 -> V_7 ) )
return F_112 ( V_11 ) ;
if ( ! V_101 && F_46 ( V_94 , & V_11 -> V_7 ) )
return F_112 ( V_11 ) ;
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_103 || ! V_6 -> V_104 ) {
F_113 ( V_11 ,
L_27 ,
V_15 ) ;
return - V_100 ;
}
V_18 = V_6 -> V_104 ( V_6 , F_17 ( V_11 ) , V_101 ) ;
if ( V_18 == 0 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
F_117 ( F_10 ( V_11 ) , 0 , V_101 ) ;
F_114 ( F_10 ( V_11 ) , 0 , V_18 ) ;
return V_18 ;
}
int F_118 ( struct V_1 * V_11 , int V_101 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_101 ( L_22 , V_15 ) ;
return - V_13 ;
}
return F_115 ( V_11 , V_101 ) ;
}
int F_119 ( struct V_1 * V_11 , int V_101 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_101 ( L_22 , V_15 ) ;
return - V_13 ;
}
if ( F_46 ( V_92 , & V_11 -> V_7 ) )
V_101 = ! V_101 ;
return F_115 ( V_11 , V_101 ) ;
}
int F_120 ( struct V_1 * V_11 , unsigned V_105 )
{
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_101 ( L_22 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_103 || ! V_6 -> V_106 ) {
F_102 ( V_11 ,
L_28 ,
V_15 ) ;
return - V_107 ;
}
return V_6 -> V_106 ( V_6 , F_17 ( V_11 ) , V_105 ) ;
}
int F_121 ( const struct V_1 * V_11 )
{
return F_46 ( V_92 , & V_11 -> V_7 ) ;
}
static int F_122 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
int V_101 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
V_101 = V_6 -> V_99 ? V_6 -> V_99 ( V_6 , V_17 ) : - V_100 ;
V_101 = V_101 < 0 ? V_101 : ! ! V_101 ;
F_117 ( F_10 ( V_11 ) , 1 , V_101 ) ;
return V_101 ;
}
int F_123 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
F_108 ( V_11 -> V_6 -> V_52 ) ;
return F_122 ( V_11 ) ;
}
int F_124 ( const struct V_1 * V_11 )
{
int V_101 ;
if ( ! V_11 )
return 0 ;
F_108 ( V_11 -> V_6 -> V_52 ) ;
V_101 = F_122 ( V_11 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( F_46 ( V_92 , & V_11 -> V_7 ) )
V_101 = ! V_101 ;
return V_101 ;
}
static void F_125 ( struct V_1 * V_11 , bool V_101 )
{
int V_98 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_101 ) {
V_98 = V_6 -> V_38 ( V_6 , V_17 ) ;
if ( ! V_98 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_98 = V_6 -> V_104 ( V_6 , V_17 , 0 ) ;
if ( ! V_98 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
}
F_114 ( F_10 ( V_11 ) , V_101 , V_98 ) ;
if ( V_98 < 0 )
F_116 ( V_11 ,
L_29 ,
V_15 , V_98 ) ;
}
static void F_126 ( struct V_1 * V_11 , bool V_101 )
{
int V_98 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_101 ) {
V_98 = V_6 -> V_104 ( V_6 , V_17 , 1 ) ;
if ( ! V_98 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_98 = V_6 -> V_38 ( V_6 , V_17 ) ;
if ( ! V_98 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
}
F_114 ( F_10 ( V_11 ) , ! V_101 , V_98 ) ;
if ( V_98 < 0 )
F_116 ( V_11 ,
L_30 ,
V_15 , V_98 ) ;
}
static void F_127 ( struct V_1 * V_11 , bool V_101 )
{
struct V_5 * V_6 ;
V_6 = V_11 -> V_6 ;
F_117 ( F_10 ( V_11 ) , 0 , V_101 ) ;
if ( F_46 ( V_93 , & V_11 -> V_7 ) )
F_125 ( V_11 , V_101 ) ;
else if ( F_46 ( V_94 , & V_11 -> V_7 ) )
F_126 ( V_11 , V_101 ) ;
else
V_6 -> V_103 ( V_6 , F_17 ( V_11 ) , V_101 ) ;
}
static void F_128 ( struct V_5 * V_6 ,
unsigned long * V_108 , unsigned long * V_109 )
{
if ( V_6 -> V_110 ) {
V_6 -> V_110 ( V_6 , V_108 , V_109 ) ;
} else {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_10 ; V_29 ++ ) {
if ( V_108 [ F_129 ( V_29 ) ] == 0 ) {
V_29 = ( F_129 ( V_29 ) + 1 ) * V_111 - 1 ;
continue;
}
if ( F_130 ( V_29 , V_108 ) )
V_6 -> V_103 ( V_6 , V_29 , F_46 ( V_29 , V_109 ) ) ;
}
}
}
static void F_131 ( bool V_112 , bool V_52 ,
unsigned int V_113 ,
struct V_1 * * V_114 ,
int * V_115 )
{
int V_29 = 0 ;
while ( V_29 < V_113 ) {
struct V_5 * V_6 = V_114 [ V_29 ] -> V_6 ;
unsigned long V_108 [ F_132 ( V_6 -> V_10 ) ] ;
unsigned long V_109 [ F_132 ( V_6 -> V_10 ) ] ;
int V_116 = 0 ;
if ( ! V_52 )
F_108 ( V_6 -> V_52 ) ;
memset ( V_108 , 0 , sizeof( V_108 ) ) ;
do {
struct V_1 * V_11 = V_114 [ V_29 ] ;
int V_117 = F_17 ( V_11 ) ;
int V_101 = V_115 [ V_29 ] ;
if ( ! V_112 && F_46 ( V_92 , & V_11 -> V_7 ) )
V_101 = ! V_101 ;
F_117 ( F_10 ( V_11 ) , 0 , V_101 ) ;
if ( F_46 ( V_93 , & V_11 -> V_7 ) ) {
F_125 ( V_11 , V_101 ) ;
} else if ( F_46 ( V_94 , & V_11 -> V_7 ) ) {
F_126 ( V_11 , V_101 ) ;
} else {
F_133 ( V_117 , V_108 ) ;
if ( V_101 )
F_133 ( V_117 , V_109 ) ;
else
F_134 ( V_117 , V_109 ) ;
V_116 ++ ;
}
V_29 ++ ;
} while ( ( V_29 < V_113 ) && ( V_114 [ V_29 ] -> V_6 == V_6 ) );
if ( V_116 != 0 )
F_128 ( V_6 , V_108 , V_109 ) ;
}
}
void F_135 ( struct V_1 * V_11 , int V_101 )
{
if ( ! V_11 )
return;
F_108 ( V_11 -> V_6 -> V_52 ) ;
F_127 ( V_11 , V_101 ) ;
}
void F_136 ( struct V_1 * V_11 , int V_101 )
{
if ( ! V_11 )
return;
F_108 ( V_11 -> V_6 -> V_52 ) ;
if ( F_46 ( V_92 , & V_11 -> V_7 ) )
V_101 = ! V_101 ;
F_127 ( V_11 , V_101 ) ;
}
void F_137 ( unsigned int V_113 ,
struct V_1 * * V_114 , int * V_115 )
{
if ( ! V_114 )
return;
F_131 ( true , false , V_113 , V_114 ,
V_115 ) ;
}
void F_138 ( unsigned int V_113 ,
struct V_1 * * V_114 , int * V_115 )
{
if ( ! V_114 )
return;
F_131 ( false , false , V_113 , V_114 ,
V_115 ) ;
}
int F_139 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
return V_11 -> V_6 -> V_52 ;
}
int F_140 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( ! V_11 )
return - V_13 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
return V_6 -> V_73 ? V_6 -> V_73 ( V_6 , V_17 ) : - V_118 ;
}
int F_67 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return - V_13 ;
if ( F_46 ( V_20 , & V_6 -> V_11 [ V_17 ] . V_7 ) ) {
F_31 ( V_6 ,
L_31 ,
V_15 ) ;
return - V_100 ;
}
F_19 ( V_102 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
return 0 ;
}
void F_70 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return;
F_18 ( V_102 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
}
int F_141 ( const struct V_1 * V_11 )
{
F_106 ( V_97 ) ;
if ( ! V_11 )
return 0 ;
return F_122 ( V_11 ) ;
}
int F_142 ( const struct V_1 * V_11 )
{
int V_101 ;
F_106 ( V_97 ) ;
if ( ! V_11 )
return 0 ;
V_101 = F_122 ( V_11 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( F_46 ( V_92 , & V_11 -> V_7 ) )
V_101 = ! V_101 ;
return V_101 ;
}
void F_143 ( struct V_1 * V_11 , int V_101 )
{
F_106 ( V_97 ) ;
if ( ! V_11 )
return;
F_127 ( V_11 , V_101 ) ;
}
void F_144 ( struct V_1 * V_11 , int V_101 )
{
F_106 ( V_97 ) ;
if ( ! V_11 )
return;
if ( F_46 ( V_92 , & V_11 -> V_7 ) )
V_101 = ! V_101 ;
F_127 ( V_11 , V_101 ) ;
}
void F_145 ( unsigned int V_113 ,
struct V_1 * * V_114 ,
int * V_115 )
{
F_106 ( V_97 ) ;
if ( ! V_114 )
return;
F_131 ( true , true , V_113 , V_114 ,
V_115 ) ;
}
void F_146 ( unsigned int V_113 ,
struct V_1 * * V_114 ,
int * V_115 )
{
F_106 ( V_97 ) ;
if ( ! V_114 )
return;
F_131 ( false , true , V_113 , V_114 ,
V_115 ) ;
}
void F_147 ( struct V_119 * V_120 )
{
F_148 ( & V_121 ) ;
F_22 ( & V_120 -> V_24 , & V_122 ) ;
F_149 ( & V_121 ) ;
}
void F_150 ( struct V_119 * V_120 )
{
F_148 ( & V_121 ) ;
F_40 ( & V_120 -> V_24 ) ;
F_149 ( & V_121 ) ;
}
static struct V_1 * F_151 ( struct V_123 * V_124 , const char * V_125 ,
unsigned int V_126 ,
enum V_127 * V_7 )
{
char V_128 [ 32 ] ;
enum V_129 V_130 ;
struct V_1 * V_11 ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_152 ( V_131 ) ; V_29 ++ ) {
if ( V_125 )
snprintf ( V_128 , sizeof( V_128 ) , L_32 , V_125 ,
V_131 [ V_29 ] ) ;
else
snprintf ( V_128 , sizeof( V_128 ) , L_33 ,
V_131 [ V_29 ] ) ;
V_11 = F_153 ( V_124 -> V_71 , V_128 , V_126 ,
& V_130 ) ;
if ( ! F_94 ( V_11 ) || ( F_95 ( V_11 ) == - V_95 ) )
break;
}
if ( F_94 ( V_11 ) )
return V_11 ;
if ( V_130 & V_132 )
* V_7 |= V_133 ;
if ( V_130 & V_134 ) {
if ( V_130 & V_132 )
* V_7 |= V_135 ;
else
* V_7 |= V_136 ;
}
return V_11 ;
}
static struct V_1 * F_154 ( struct V_123 * V_124 , const char * V_125 ,
unsigned int V_126 ,
enum V_127 * V_7 )
{
struct V_137 * V_138 = F_155 ( V_124 ) ;
struct V_139 V_140 ;
struct V_1 * V_11 ;
char V_141 [ 32 ] ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_152 ( V_131 ) ; V_29 ++ ) {
if ( V_125 && strcmp ( V_125 , L_34 ) ) {
snprintf ( V_141 , sizeof( V_141 ) , L_32 ,
V_125 , V_131 [ V_29 ] ) ;
} else {
snprintf ( V_141 , sizeof( V_141 ) , L_33 ,
V_131 [ V_29 ] ) ;
}
V_11 = F_156 ( V_138 , V_141 , V_126 , & V_140 ) ;
if ( ! F_94 ( V_11 ) || ( F_95 ( V_11 ) == - V_95 ) )
break;
}
if ( F_94 ( V_11 ) ) {
if ( ! F_157 ( V_138 , V_125 ) )
return F_9 ( - V_142 ) ;
V_11 = F_156 ( V_138 , NULL , V_126 , & V_140 ) ;
if ( F_94 ( V_11 ) )
return V_11 ;
}
if ( V_140 . V_143 == V_133 )
* V_7 |= V_133 ;
return V_11 ;
}
static struct V_119 * F_158 ( struct V_123 * V_124 )
{
const char * V_144 = V_124 ? F_159 ( V_124 ) : NULL ;
struct V_119 * V_120 ;
F_148 ( & V_121 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_120 -> V_144 && V_144 ) {
if ( ! strcmp ( V_120 -> V_144 , V_144 ) )
goto V_25;
} else {
if ( V_144 == V_120 -> V_144 )
goto V_25;
}
}
V_120 = NULL ;
V_25:
F_149 ( & V_121 ) ;
return V_120 ;
}
static struct V_1 * F_160 ( struct V_123 * V_124 , const char * V_125 ,
unsigned int V_126 ,
enum V_127 * V_7 )
{
struct V_1 * V_11 = F_9 ( - V_142 ) ;
struct V_119 * V_120 ;
struct V_145 * V_146 ;
V_120 = F_158 ( V_124 ) ;
if ( ! V_120 )
return V_11 ;
for ( V_146 = & V_120 -> V_120 [ 0 ] ; V_146 -> V_147 ; V_146 ++ ) {
struct V_5 * V_6 ;
if ( V_146 -> V_126 != V_126 )
continue;
if ( V_146 -> V_125 && ( ! V_125 || strcmp ( V_146 -> V_125 , V_125 ) ) )
continue;
V_6 = F_51 ( V_146 -> V_147 ) ;
if ( ! V_6 ) {
F_25 ( V_124 , L_35 ,
V_146 -> V_147 ) ;
return F_9 ( - V_64 ) ;
}
if ( V_6 -> V_10 <= V_146 -> V_148 ) {
F_25 ( V_124 ,
L_36 ,
V_126 , V_6 -> V_10 , V_6 -> V_3 ) ;
return F_9 ( - V_13 ) ;
}
V_11 = F_8 ( V_6 , V_146 -> V_148 ) ;
* V_7 = V_146 -> V_7 ;
return V_11 ;
}
return V_11 ;
}
static int F_161 ( struct V_123 * V_124 , const char * V_125 )
{
int V_81 ;
char V_141 [ 32 ] ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_152 ( V_131 ) ; V_29 ++ ) {
if ( V_125 )
snprintf ( V_141 , sizeof( V_141 ) , L_32 ,
V_125 , V_131 [ V_29 ] ) ;
else
snprintf ( V_141 , sizeof( V_141 ) , L_33 ,
V_131 [ V_29 ] ) ;
V_81 = F_162 ( V_124 -> V_71 , V_141 ) ;
if ( V_81 >= 0 )
break;
}
return V_81 ;
}
static int F_163 ( struct V_123 * V_124 , const char * V_125 )
{
struct V_119 * V_120 ;
struct V_145 * V_146 ;
unsigned int V_116 = 0 ;
V_120 = F_158 ( V_124 ) ;
if ( ! V_120 )
return - V_142 ;
for ( V_146 = & V_120 -> V_120 [ 0 ] ; V_146 -> V_147 ; V_146 ++ ) {
if ( ( V_125 && V_146 -> V_125 && ! strcmp ( V_125 , V_146 -> V_125 ) ) ||
( ! V_125 && ! V_146 -> V_125 ) )
V_116 ++ ;
}
if ( ! V_116 )
return - V_142 ;
return V_116 ;
}
int F_164 ( struct V_123 * V_124 , const char * V_125 )
{
int V_116 = - V_142 ;
if ( F_165 ( V_149 ) && V_124 && V_124 -> V_71 )
V_116 = F_161 ( V_124 , V_125 ) ;
else if ( F_165 ( V_150 ) && V_124 && F_166 ( V_124 ) )
V_116 = F_167 ( V_124 , V_125 ) ;
if ( V_116 < 0 )
V_116 = F_163 ( V_124 , V_125 ) ;
return V_116 ;
}
struct V_1 * T_4 F_168 ( struct V_123 * V_124 , const char * V_125 ,
enum V_151 V_7 )
{
return F_169 ( V_124 , V_125 , 0 , V_7 ) ;
}
struct V_1 * T_4 F_170 ( struct V_123 * V_124 ,
const char * V_125 ,
enum V_151 V_7 )
{
return F_171 ( V_124 , V_125 , 0 , V_7 ) ;
}
static void F_172 ( struct V_1 * V_11 , unsigned long V_152 )
{
if ( V_152 & V_133 )
F_19 ( V_92 , & V_11 -> V_7 ) ;
if ( V_152 & V_135 )
F_19 ( V_93 , & V_11 -> V_7 ) ;
if ( V_152 & V_136 )
F_19 ( V_94 , & V_11 -> V_7 ) ;
}
static int F_173 ( struct V_1 * V_11 , const char * V_125 ,
enum V_151 V_153 )
{
int V_18 ;
if ( ! ( V_153 & V_154 ) ) {
F_14 ( L_37 , V_125 ) ;
return 0 ;
}
if ( V_153 & V_155 )
V_18 = F_119 ( V_11 ,
V_153 & V_156 ) ;
else
V_18 = F_112 ( V_11 ) ;
return V_18 ;
}
struct V_1 * T_4 F_169 ( struct V_123 * V_124 ,
const char * V_125 ,
unsigned int V_126 ,
enum V_151 V_7 )
{
struct V_1 * V_11 = NULL ;
int V_18 ;
enum V_127 V_157 = 0 ;
F_174 ( V_124 , L_38 , V_125 ) ;
if ( V_124 ) {
if ( F_165 ( V_149 ) && V_124 -> V_71 ) {
F_174 ( V_124 , L_39 ) ;
V_11 = F_151 ( V_124 , V_125 , V_126 , & V_157 ) ;
} else if ( F_155 ( V_124 ) ) {
F_174 ( V_124 , L_40 ) ;
V_11 = F_154 ( V_124 , V_125 , V_126 , & V_157 ) ;
}
}
if ( ! V_11 || V_11 == F_9 ( - V_142 ) ) {
F_174 ( V_124 , L_41 ) ;
V_11 = F_160 ( V_124 , V_125 , V_126 , & V_157 ) ;
}
if ( F_94 ( V_11 ) ) {
F_174 ( V_124 , L_42 , V_125 ) ;
return V_11 ;
}
F_172 ( V_11 , V_157 ) ;
V_18 = F_100 ( V_11 , V_125 ) ;
if ( V_18 < 0 )
return F_9 ( V_18 ) ;
V_18 = F_173 ( V_11 , V_125 , V_7 ) ;
if ( V_18 < 0 ) {
F_174 ( V_124 , L_43 , V_125 ) ;
F_175 ( V_11 ) ;
return F_9 ( V_18 ) ;
}
return V_11 ;
}
struct V_1 * F_176 ( struct V_158 * V_159 ,
const char * V_141 )
{
struct V_1 * V_11 = F_9 ( - V_64 ) ;
bool V_160 = false ;
bool V_161 = false ;
int V_81 ;
if ( ! V_159 )
return F_9 ( - V_13 ) ;
if ( F_177 ( V_159 ) ) {
enum V_129 V_7 ;
V_11 = F_153 ( F_178 ( V_159 ) , V_141 , 0 ,
& V_7 ) ;
if ( ! F_94 ( V_11 ) ) {
V_160 = V_7 & V_132 ;
V_161 = V_7 & V_134 ;
}
} else if ( F_179 ( V_159 ) ) {
struct V_139 V_140 ;
V_11 = F_180 ( V_159 , V_141 , 0 , & V_140 ) ;
if ( ! F_94 ( V_11 ) )
V_160 = V_140 . V_143 == V_133 ;
}
if ( F_94 ( V_11 ) )
return V_11 ;
if ( V_160 )
F_19 ( V_92 , & V_11 -> V_7 ) ;
if ( V_161 ) {
if ( V_160 )
F_19 ( V_93 , & V_11 -> V_7 ) ;
else
F_19 ( V_94 , & V_11 -> V_7 ) ;
}
V_81 = F_100 ( V_11 , NULL ) ;
if ( V_81 )
return F_9 ( V_81 ) ;
return V_11 ;
}
struct V_1 * T_4 F_171 ( struct V_123 * V_124 ,
const char * V_125 ,
unsigned int V_162 ,
enum V_151 V_7 )
{
struct V_1 * V_11 ;
V_11 = F_169 ( V_124 , V_125 , V_162 , V_7 ) ;
if ( F_94 ( V_11 ) ) {
if ( F_95 ( V_11 ) == - V_142 )
return NULL ;
}
return V_11 ;
}
int F_181 ( struct V_1 * V_11 , const char * V_28 ,
unsigned long V_152 , enum V_151 V_153 )
{
struct V_5 * V_6 ;
struct V_1 * V_163 ;
int V_12 ;
int V_18 ;
V_6 = F_11 ( V_11 ) ;
V_12 = F_17 ( V_11 ) ;
F_172 ( V_11 , V_152 ) ;
V_163 = F_110 ( V_6 , V_12 , V_28 ) ;
if ( F_94 ( V_163 ) ) {
F_15 ( L_44 ,
V_28 , V_6 -> V_3 , V_12 ) ;
return F_95 ( V_163 ) ;
}
V_18 = F_173 ( V_11 , V_28 , V_153 ) ;
if ( V_18 < 0 ) {
F_15 ( L_45 ,
V_28 , V_6 -> V_3 , V_12 ) ;
F_111 ( V_11 ) ;
return V_18 ;
}
F_19 ( V_96 , & V_11 -> V_7 ) ;
F_182 ( L_46 ,
F_10 ( V_11 ) , V_28 ,
( V_153 & V_155 ) ? L_47 : L_48 ,
( V_153 & V_155 ) ?
( V_153 & V_156 ) ? L_49 : L_50 : L_51 ) ;
return 0 ;
}
static void F_38 ( struct V_5 * V_6 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_6 -> V_10 ; V_33 ++ ) {
if ( F_46 ( V_96 , & V_6 -> V_11 [ V_33 ] . V_7 ) )
F_111 ( & V_6 -> V_11 [ V_33 ] ) ;
}
}
struct V_164 * T_4 F_183 ( struct V_123 * V_124 ,
const char * V_125 ,
enum V_151 V_7 )
{
struct V_1 * V_11 ;
struct V_164 * V_34 ;
int V_116 ;
V_116 = F_164 ( V_124 , V_125 ) ;
if ( V_116 < 0 )
return F_9 ( V_116 ) ;
V_34 = F_87 ( sizeof( * V_34 ) + sizeof( V_34 -> V_11 [ 0 ] ) * V_116 ,
V_35 ) ;
if ( ! V_34 )
return F_9 ( - V_36 ) ;
for ( V_34 -> V_165 = 0 ; V_34 -> V_165 < V_116 ; ) {
V_11 = F_169 ( V_124 , V_125 , V_34 -> V_165 , V_7 ) ;
if ( F_94 ( V_11 ) ) {
F_184 ( V_34 ) ;
return F_185 ( V_11 ) ;
}
V_34 -> V_11 [ V_34 -> V_165 ] = V_11 ;
V_34 -> V_165 ++ ;
}
return V_34 ;
}
struct V_164 * T_4 F_186 ( struct V_123 * V_124 ,
const char * V_125 ,
enum V_151 V_7 )
{
struct V_164 * V_34 ;
V_34 = F_183 ( V_124 , V_125 , V_7 ) ;
if ( F_94 ( V_34 ) && ( F_95 ( V_34 ) == - V_142 ) )
return NULL ;
return V_34 ;
}
void F_175 ( struct V_1 * V_11 )
{
F_107 ( V_11 ) ;
}
void F_184 ( struct V_164 * V_34 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_34 -> V_165 ; V_29 ++ )
F_175 ( V_34 -> V_11 [ V_29 ] ) ;
F_41 ( V_34 ) ;
}
static void F_187 ( struct V_166 * V_167 , struct V_5 * V_6 )
{
unsigned V_29 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_168 = & V_6 -> V_11 [ 0 ] ;
int V_169 ;
int V_170 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_10 ; V_29 ++ , V_4 ++ , V_168 ++ ) {
if ( ! F_46 ( V_45 , & V_168 -> V_7 ) ) {
if ( V_168 -> V_28 ) {
F_188 ( V_167 , L_52 ,
V_4 , V_168 -> V_28 ) ;
}
continue;
}
F_16 ( V_168 ) ;
V_169 = F_46 ( V_20 , & V_168 -> V_7 ) ;
V_170 = F_46 ( V_102 , & V_168 -> V_7 ) ;
F_188 ( V_167 , L_53 ,
V_4 , V_168 -> V_28 ? V_168 -> V_28 : L_51 , V_168 -> V_3 ,
V_169 ? L_54 : L_55 ,
V_6 -> V_99
? ( V_6 -> V_99 ( V_6 , V_29 ) ? L_56 : L_57 )
: L_58 ,
V_170 ? L_59 : L_60 ) ;
F_188 ( V_167 , L_61 ) ;
}
}
static void * F_189 ( struct V_166 * V_167 , T_5 * V_171 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_5 V_162 = * V_171 ;
V_167 -> V_172 = L_51 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( V_162 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_190 ( struct V_166 * V_167 , void * V_173 , T_5 * V_171 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_173 ;
void * V_81 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_191 ( & V_6 -> V_24 , & V_23 ) )
V_81 = NULL ;
else
V_81 = F_192 ( V_6 -> V_24 . V_174 , struct V_5 , V_24 ) ;
F_5 ( & V_8 , V_7 ) ;
V_167 -> V_172 = L_61 ;
++ * V_171 ;
return V_81 ;
}
static void F_193 ( struct V_166 * V_167 , void * V_173 )
{
}
static int F_194 ( struct V_166 * V_167 , void * V_173 )
{
struct V_5 * V_6 = V_173 ;
struct V_123 * V_124 ;
F_188 ( V_167 , L_62 , ( char * ) V_167 -> V_172 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_124 = V_6 -> V_26 ;
if ( V_124 )
F_188 ( V_167 , L_63 , V_124 -> V_175 ? V_124 -> V_175 -> V_28 : L_64 ,
F_159 ( V_124 ) ) ;
if ( V_6 -> V_3 )
F_188 ( V_167 , L_65 , V_6 -> V_3 ) ;
if ( V_6 -> V_52 )
F_188 ( V_167 , L_66 ) ;
F_188 ( V_167 , L_67 ) ;
if ( V_6 -> V_176 )
V_6 -> V_176 ( V_167 , V_6 ) ;
else
F_187 ( V_167 , V_6 ) ;
return 0 ;
}
static int F_195 ( struct V_177 * V_177 , struct V_178 * V_178 )
{
return F_196 ( V_178 , & V_179 ) ;
}
static int T_6 F_197 ( void )
{
( void ) F_198 ( L_68 , V_180 | V_181 ,
NULL , NULL , & V_182 ) ;
return 0 ;
}
