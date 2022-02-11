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
struct V_21 * V_22 ;
struct V_5 * V_23 ;
int V_24 = 0 ;
F_21 (pos, &gpio_chips) {
V_23 = F_22 ( V_22 , struct V_5 , V_25 ) ;
if ( V_23 -> V_9 >= V_6 -> V_9 + V_6 -> V_10 )
break;
}
if ( V_22 != & V_26 && V_22 -> V_27 != & V_26 ) {
V_23 = F_22 ( V_22 -> V_27 , struct V_5 , V_25 ) ;
if ( V_23 -> V_9 + V_23 -> V_10 > V_6 -> V_9 ) {
F_23 ( V_6 -> V_28 ,
L_4 ) ;
V_24 = - V_29 ;
}
}
if ( ! V_24 )
F_24 ( & V_6 -> V_25 , V_22 ) ;
return V_24 ;
}
static struct V_1 * F_25 ( const char * const V_30 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list) {
int V_31 ;
for ( V_31 = 0 ; V_31 != V_6 -> V_10 ; ++ V_31 ) {
struct V_1 * V_4 = & V_6 -> V_11 [ V_31 ] ;
if ( ! V_4 -> V_30 || ! V_30 )
continue;
if ( ! strcmp ( V_4 -> V_30 , V_30 ) ) {
F_5 ( & V_8 , V_7 ) ;
return V_4 ;
}
}
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static int F_26 ( struct V_5 * V_32 )
{
int V_31 ;
if ( ! V_32 -> V_33 )
return 0 ;
for ( V_31 = 0 ; V_31 != V_32 -> V_10 ; ++ V_31 ) {
struct V_1 * V_4 ;
V_4 = F_25 ( V_32 -> V_33 [ V_31 ] ) ;
if ( V_4 )
F_27 ( V_32 -> V_28 , L_5
L_6 ,
V_32 -> V_33 [ V_31 ] ) ;
}
for ( V_31 = 0 ; V_31 != V_32 -> V_10 ; ++ V_31 )
V_32 -> V_11 [ V_31 ] . V_30 = V_32 -> V_33 [ V_31 ] ;
return 0 ;
}
int F_28 ( struct V_5 * V_6 )
{
unsigned long V_7 ;
int V_18 = 0 ;
unsigned V_34 ;
int V_9 = V_6 -> V_9 ;
struct V_1 * V_35 ;
V_35 = F_29 ( V_6 -> V_10 , sizeof( V_35 [ 0 ] ) , V_36 ) ;
if ( ! V_35 )
return - V_37 ;
F_3 ( & V_8 , V_7 ) ;
if ( V_9 < 0 ) {
V_9 = F_12 ( V_6 -> V_10 ) ;
if ( V_9 < 0 ) {
V_18 = V_9 ;
F_5 ( & V_8 , V_7 ) ;
goto V_38;
}
V_6 -> V_9 = V_9 ;
}
V_18 = F_20 ( V_6 ) ;
if ( V_18 ) {
F_5 ( & V_8 , V_7 ) ;
goto V_38;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_10 ; V_34 ++ ) {
struct V_1 * V_11 = & V_35 [ V_34 ] ;
V_11 -> V_6 = V_6 ;
V_11 -> V_7 = ! V_6 -> V_39 ? ( 1 << V_20 ) : 0 ;
}
V_6 -> V_11 = V_35 ;
F_5 ( & V_8 , V_7 ) ;
#ifdef F_30
F_31 ( & V_6 -> V_40 ) ;
#endif
if ( ! V_6 -> V_41 && V_6 -> V_28 && V_6 -> V_28 -> V_42 )
V_6 -> V_41 = V_6 -> V_28 -> V_42 -> V_41 ;
V_18 = F_26 ( V_6 ) ;
if ( V_18 )
goto V_43;
V_18 = F_32 ( V_6 ) ;
if ( V_18 )
goto V_44;
F_33 ( V_6 ) ;
V_18 = F_34 ( V_6 ) ;
if ( V_18 )
goto V_44;
F_14 ( L_7 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_8 ) ;
return 0 ;
V_44:
F_35 ( V_6 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
V_43:
F_3 ( & V_8 , V_7 ) ;
F_38 ( & V_6 -> V_25 ) ;
F_5 ( & V_8 , V_7 ) ;
V_6 -> V_11 = NULL ;
V_38:
F_39 ( V_35 ) ;
F_15 ( L_9 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_8 ) ;
return V_18 ;
}
void F_40 ( struct V_5 * V_6 )
{
struct V_1 * V_11 ;
unsigned long V_7 ;
unsigned V_34 ;
bool V_45 = false ;
F_41 ( V_6 ) ;
F_42 ( V_6 ) ;
F_35 ( V_6 ) ;
F_43 ( V_6 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
F_3 ( & V_8 , V_7 ) ;
for ( V_34 = 0 ; V_34 < V_6 -> V_10 ; V_34 ++ ) {
V_11 = & V_6 -> V_11 [ V_34 ] ;
V_11 -> V_6 = NULL ;
if ( F_44 ( V_46 , & V_11 -> V_7 ) )
V_45 = true ;
}
F_38 ( & V_6 -> V_25 ) ;
F_5 ( & V_8 , V_7 ) ;
if ( V_45 )
F_45 ( V_6 -> V_28 , L_10 ) ;
F_39 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
struct V_5 * F_46 ( void * V_47 ,
int (* F_47)( struct V_5 * V_6 ,
void * V_47 ) )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( F_47 ( V_6 , V_47 ) )
break;
if ( & V_6 -> V_25 == & V_26 )
V_6 = NULL ;
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
static int F_48 ( struct V_5 * V_6 , void * V_47 )
{
const char * V_30 = V_47 ;
return ! strcmp ( V_6 -> V_3 , V_30 ) ;
}
static struct V_5 * F_49 ( const char * V_30 )
{
return F_46 ( ( void * ) V_30 , F_48 ) ;
}
void F_50 ( struct V_5 * V_48 ,
struct V_49 * V_50 ,
int V_51 ,
T_2 V_52 )
{
unsigned int V_17 ;
if ( ! V_48 -> V_53 ) {
F_51 ( V_48 , L_11 ,
V_15 ) ;
return;
}
if ( V_52 ) {
if ( V_48 -> V_54 ) {
F_51 ( V_48 ,
L_12
L_13 ) ;
return;
}
F_52 ( V_51 , V_52 ,
V_48 ) ;
V_48 -> V_55 = V_51 ;
}
for ( V_17 = 0 ; V_17 < V_48 -> V_10 ; V_17 ++ )
F_53 ( F_54 ( V_48 -> V_53 , V_17 ) ,
V_51 ) ;
}
static int F_55 ( struct V_56 * V_2 , unsigned int V_57 ,
T_3 V_58 )
{
struct V_5 * V_6 = V_2 -> V_59 ;
F_56 ( V_57 , V_6 ) ;
F_57 ( V_57 , V_6 -> V_60 ) ;
F_58 ( V_57 , V_6 -> V_50 , V_6 -> V_61 ) ;
if ( V_6 -> V_54 && ! V_6 -> V_62 )
F_59 ( V_57 , 1 ) ;
F_60 ( V_57 ) ;
if ( V_6 -> V_63 != V_64 )
F_61 ( V_57 , V_6 -> V_63 ) ;
return 0 ;
}
static void F_62 ( struct V_56 * V_2 , unsigned int V_57 )
{
struct V_5 * V_6 = V_2 -> V_59 ;
if ( V_6 -> V_54 )
F_59 ( V_57 , 0 ) ;
F_58 ( V_57 , NULL , NULL ) ;
F_56 ( V_57 , NULL ) ;
}
static int F_63 ( struct V_65 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
if ( ! F_65 ( V_6 -> V_41 ) )
return - V_66 ;
if ( F_66 ( V_6 , V_2 -> V_58 ) ) {
F_51 ( V_6 ,
L_14 ,
V_2 -> V_58 ) ;
F_67 ( V_6 -> V_41 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_68 ( struct V_65 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
F_69 ( V_6 , V_2 -> V_58 ) ;
F_67 ( V_6 -> V_41 ) ;
}
static int F_70 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_54 ( V_6 -> V_53 , V_17 ) ;
}
static void F_42 ( struct V_5 * V_48 )
{
unsigned int V_17 ;
F_71 ( V_48 ) ;
if ( V_48 -> V_55 ) {
F_72 ( V_48 -> V_55 , NULL ) ;
F_73 ( V_48 -> V_55 , NULL ) ;
}
if ( V_48 -> V_53 ) {
for ( V_17 = 0 ; V_17 < V_48 -> V_10 ; V_17 ++ )
F_74 (
F_54 ( V_48 -> V_53 , V_17 ) ) ;
F_75 ( V_48 -> V_53 ) ;
}
if ( V_48 -> V_50 ) {
V_48 -> V_50 -> V_67 = NULL ;
V_48 -> V_50 -> V_68 = NULL ;
V_48 -> V_50 = NULL ;
}
}
int F_76 ( struct V_5 * V_48 ,
struct V_49 * V_50 ,
unsigned int V_69 ,
T_2 V_70 ,
unsigned int type ,
struct V_71 * V_60 )
{
struct V_72 * V_73 ;
unsigned int V_17 ;
unsigned V_74 = 0 ;
if ( ! V_48 || ! V_50 )
return - V_13 ;
if ( ! V_48 -> V_28 ) {
F_15 ( L_15 ) ;
return - V_13 ;
}
V_73 = V_48 -> V_28 -> V_73 ;
#ifdef F_77
if ( V_48 -> V_73 )
V_73 = V_48 -> V_73 ;
#endif
V_48 -> V_50 = V_50 ;
V_48 -> V_61 = V_70 ;
V_48 -> V_63 = type ;
V_48 -> V_75 = F_70 ;
V_48 -> V_60 = V_60 ;
V_48 -> V_53 = F_78 ( V_73 ,
V_48 -> V_10 , V_69 ,
& V_76 , V_48 ) ;
if ( ! V_48 -> V_53 ) {
V_48 -> V_50 = NULL ;
return - V_13 ;
}
if ( ! V_50 -> V_67 &&
! V_50 -> V_68 ) {
V_50 -> V_67 = F_63 ;
V_50 -> V_68 = F_68 ;
}
for ( V_17 = 0 ; V_17 < V_48 -> V_10 ; V_17 ++ ) {
V_74 = F_79 ( V_48 -> V_53 , V_17 ) ;
if ( V_17 == 0 )
V_48 -> V_74 = V_74 ;
}
F_80 ( V_48 ) ;
return 0 ;
}
static void F_42 ( struct V_5 * V_48 ) {}
int F_81 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_82 ( V_6 -> V_9 + V_17 ) ;
}
void F_83 ( struct V_5 * V_6 , unsigned V_17 )
{
F_84 ( V_6 -> V_9 + V_17 ) ;
}
int F_85 ( struct V_5 * V_6 ,
struct V_77 * V_78 ,
unsigned int V_79 , const char * V_80 )
{
struct V_81 * V_82 ;
int V_83 ;
V_82 = F_86 ( sizeof( * V_82 ) , V_36 ) ;
if ( ! V_82 ) {
F_51 ( V_6 , L_16 ) ;
return - V_37 ;
}
V_82 -> V_84 . V_34 = V_79 ;
V_82 -> V_84 . V_32 = V_6 ;
V_82 -> V_84 . V_30 = V_6 -> V_3 ;
V_82 -> V_84 . V_9 = V_6 -> V_9 + V_79 ;
V_82 -> V_78 = V_78 ;
V_83 = F_87 ( V_78 , V_80 ,
& V_82 -> V_84 . V_85 ,
& V_82 -> V_84 . V_86 ) ;
if ( V_83 < 0 ) {
F_39 ( V_82 ) ;
return V_83 ;
}
F_88 ( V_78 , & V_82 -> V_84 ) ;
F_89 ( V_6 , L_17 ,
V_79 , V_79 + V_82 -> V_84 . V_86 - 1 ,
F_90 ( V_78 ) , V_80 ) ;
F_24 ( & V_82 -> V_87 , & V_6 -> V_40 ) ;
return 0 ;
}
int F_91 ( struct V_5 * V_6 , const char * V_88 ,
unsigned int V_79 , unsigned int V_89 ,
unsigned int V_86 )
{
struct V_81 * V_82 ;
int V_83 ;
V_82 = F_86 ( sizeof( * V_82 ) , V_36 ) ;
if ( ! V_82 ) {
F_51 ( V_6 , L_16 ) ;
return - V_37 ;
}
V_82 -> V_84 . V_34 = V_79 ;
V_82 -> V_84 . V_32 = V_6 ;
V_82 -> V_84 . V_30 = V_6 -> V_3 ;
V_82 -> V_84 . V_9 = V_6 -> V_9 + V_79 ;
V_82 -> V_84 . V_90 = V_89 ;
V_82 -> V_84 . V_86 = V_86 ;
V_82 -> V_78 = F_92 ( V_88 ,
& V_82 -> V_84 ) ;
if ( F_93 ( V_82 -> V_78 ) ) {
V_83 = F_94 ( V_82 -> V_78 ) ;
F_51 ( V_6 , L_18 ) ;
F_39 ( V_82 ) ;
return V_83 ;
}
F_89 ( V_6 , L_19 ,
V_79 , V_79 + V_86 - 1 ,
V_88 ,
V_89 , V_89 + V_86 - 1 ) ;
F_24 ( & V_82 -> V_87 , & V_6 -> V_40 ) ;
return 0 ;
}
void F_43 ( struct V_5 * V_6 )
{
struct V_81 * V_82 , * V_91 ;
F_95 (pin_range, tmp, &chip->pin_ranges, node) {
F_38 ( & V_82 -> V_87 ) ;
F_96 ( V_82 -> V_78 ,
& V_82 -> V_84 ) ;
F_39 ( V_82 ) ;
}
}
static int F_97 ( struct V_1 * V_11 , const char * V_3 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
int V_18 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_98 ( V_46 , & V_11 -> V_7 ) == 0 ) {
F_1 ( V_11 , V_3 ? : L_20 ) ;
V_18 = 0 ;
} else {
V_18 = - V_29 ;
goto V_92;
}
if ( V_6 -> V_93 ) {
F_5 ( & V_8 , V_7 ) ;
V_18 = V_6 -> V_93 ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_18 < 0 ) {
F_1 ( V_11 , NULL ) ;
F_18 ( V_46 , & V_11 -> V_7 ) ;
goto V_92;
}
}
if ( V_6 -> V_19 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_92:
if ( V_18 < 0 ) {
F_18 ( V_94 , & V_11 -> V_7 ) ;
F_18 ( V_95 , & V_11 -> V_7 ) ;
F_18 ( V_96 , & V_11 -> V_7 ) ;
}
F_5 ( & V_8 , V_7 ) ;
return V_18 ;
}
int F_99 ( struct V_1 * V_11 , const char * V_3 )
{
int V_18 = - V_97 ;
struct V_5 * V_6 ;
if ( ! V_11 ) {
F_100 ( L_21 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 )
goto V_92;
if ( F_65 ( V_6 -> V_41 ) ) {
V_18 = F_97 ( V_11 , V_3 ) ;
if ( V_18 < 0 )
F_67 ( V_6 -> V_41 ) ;
}
V_92:
if ( V_18 )
F_101 ( V_11 , L_22 , V_15 , V_18 ) ;
return V_18 ;
}
static bool F_102 ( struct V_1 * V_11 )
{
bool V_83 = false ;
unsigned long V_7 ;
struct V_5 * V_6 ;
F_103 () ;
F_104 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
V_6 = V_11 -> V_6 ;
if ( V_6 && F_44 ( V_46 , & V_11 -> V_7 ) ) {
if ( V_6 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_105 ( V_6 -> V_54 ) ;
V_6 -> free ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_11 , NULL ) ;
F_18 ( V_94 , & V_11 -> V_7 ) ;
F_18 ( V_46 , & V_11 -> V_7 ) ;
F_18 ( V_95 , & V_11 -> V_7 ) ;
F_18 ( V_96 , & V_11 -> V_7 ) ;
F_18 ( V_98 , & V_11 -> V_7 ) ;
V_83 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_83 ;
}
void F_106 ( struct V_1 * V_11 )
{
if ( V_11 && F_102 ( V_11 ) )
F_67 ( V_11 -> V_6 -> V_41 ) ;
else
F_107 ( V_99 ) ;
}
const char * F_108 ( struct V_5 * V_6 , unsigned V_17 )
{
struct V_1 * V_11 ;
if ( V_17 >= V_6 -> V_10 )
return NULL ;
V_11 = & V_6 -> V_11 [ V_17 ] ;
if ( F_44 ( V_46 , & V_11 -> V_7 ) == 0 )
return NULL ;
return V_11 -> V_3 ;
}
struct V_1 * F_109 ( struct V_5 * V_6 , T_1 V_12 ,
const char * V_3 )
{
struct V_1 * V_11 = F_8 ( V_6 , V_12 ) ;
int V_24 ;
if ( F_93 ( V_11 ) ) {
F_51 ( V_6 , L_23 ) ;
return V_11 ;
}
V_24 = F_97 ( V_11 , V_3 ) ;
if ( V_24 < 0 )
return F_9 ( V_24 ) ;
return V_11 ;
}
void F_110 ( struct V_1 * V_11 )
{
if ( V_11 )
F_102 ( V_11 ) ;
}
int F_111 ( struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_100 ( L_21 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_100 || ! V_6 -> V_39 ) {
F_112 ( V_11 ,
L_24 ,
V_15 ) ;
return - V_101 ;
}
V_18 = V_6 -> V_39 ( V_6 , F_17 ( V_11 ) ) ;
if ( V_18 == 0 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
F_113 ( F_10 ( V_11 ) , 1 , V_18 ) ;
return V_18 ;
}
static int F_114 ( struct V_1 * V_11 , int V_102 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( F_44 ( V_103 , & V_11 -> V_7 ) ) {
F_115 ( V_11 ,
L_25 ,
V_15 ) ;
return - V_101 ;
}
if ( V_102 && F_44 ( V_95 , & V_11 -> V_7 ) )
return F_111 ( V_11 ) ;
if ( ! V_102 && F_44 ( V_96 , & V_11 -> V_7 ) )
return F_111 ( V_11 ) ;
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_104 || ! V_6 -> V_105 ) {
F_112 ( V_11 ,
L_26 ,
V_15 ) ;
return - V_101 ;
}
V_18 = V_6 -> V_105 ( V_6 , F_17 ( V_11 ) , V_102 ) ;
if ( V_18 == 0 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
F_116 ( F_10 ( V_11 ) , 0 , V_102 ) ;
F_113 ( F_10 ( V_11 ) , 0 , V_18 ) ;
return V_18 ;
}
int F_117 ( struct V_1 * V_11 , int V_102 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_100 ( L_21 , V_15 ) ;
return - V_13 ;
}
return F_114 ( V_11 , V_102 ) ;
}
int F_118 ( struct V_1 * V_11 , int V_102 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_100 ( L_21 , V_15 ) ;
return - V_13 ;
}
if ( F_44 ( V_94 , & V_11 -> V_7 ) )
V_102 = ! V_102 ;
return F_114 ( V_11 , V_102 ) ;
}
int F_119 ( struct V_1 * V_11 , unsigned V_106 )
{
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_100 ( L_21 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_104 || ! V_6 -> V_107 ) {
F_101 ( V_11 ,
L_27 ,
V_15 ) ;
return - V_108 ;
}
return V_6 -> V_107 ( V_6 , F_17 ( V_11 ) , V_106 ) ;
}
int F_120 ( const struct V_1 * V_11 )
{
return F_44 ( V_94 , & V_11 -> V_7 ) ;
}
static int F_121 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
int V_102 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
V_102 = V_6 -> V_100 ? V_6 -> V_100 ( V_6 , V_17 ) : - V_101 ;
V_102 = ! ! V_102 ;
F_116 ( F_10 ( V_11 ) , 1 , V_102 ) ;
return V_102 ;
}
int F_122 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
F_107 ( V_11 -> V_6 -> V_54 ) ;
return F_121 ( V_11 ) ;
}
int F_123 ( const struct V_1 * V_11 )
{
int V_102 ;
if ( ! V_11 )
return 0 ;
F_107 ( V_11 -> V_6 -> V_54 ) ;
V_102 = F_121 ( V_11 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( F_44 ( V_94 , & V_11 -> V_7 ) )
V_102 = ! V_102 ;
return V_102 ;
}
static void F_124 ( struct V_1 * V_11 , bool V_102 )
{
int V_24 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_102 ) {
V_24 = V_6 -> V_39 ( V_6 , V_17 ) ;
if ( ! V_24 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_24 = V_6 -> V_105 ( V_6 , V_17 , 0 ) ;
if ( ! V_24 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
}
F_113 ( F_10 ( V_11 ) , V_102 , V_24 ) ;
if ( V_24 < 0 )
F_115 ( V_11 ,
L_28 ,
V_15 , V_24 ) ;
}
static void F_125 ( struct V_1 * V_11 , bool V_102 )
{
int V_24 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_102 ) {
V_24 = V_6 -> V_105 ( V_6 , V_17 , 1 ) ;
if ( ! V_24 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_24 = V_6 -> V_39 ( V_6 , V_17 ) ;
if ( ! V_24 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
}
F_113 ( F_10 ( V_11 ) , ! V_102 , V_24 ) ;
if ( V_24 < 0 )
F_115 ( V_11 ,
L_29 ,
V_15 , V_24 ) ;
}
static void F_126 ( struct V_1 * V_11 , bool V_102 )
{
struct V_5 * V_6 ;
V_6 = V_11 -> V_6 ;
F_116 ( F_10 ( V_11 ) , 0 , V_102 ) ;
if ( F_44 ( V_95 , & V_11 -> V_7 ) )
F_124 ( V_11 , V_102 ) ;
else if ( F_44 ( V_96 , & V_11 -> V_7 ) )
F_125 ( V_11 , V_102 ) ;
else
V_6 -> V_104 ( V_6 , F_17 ( V_11 ) , V_102 ) ;
}
static void F_127 ( struct V_5 * V_6 ,
unsigned long * V_109 , unsigned long * V_110 )
{
if ( V_6 -> V_111 ) {
V_6 -> V_111 ( V_6 , V_109 , V_110 ) ;
} else {
int V_31 ;
for ( V_31 = 0 ; V_31 < V_6 -> V_10 ; V_31 ++ ) {
if ( V_109 [ F_128 ( V_31 ) ] == 0 ) {
V_31 = ( F_128 ( V_31 ) + 1 ) * V_112 - 1 ;
continue;
}
if ( F_129 ( V_31 , V_109 ) )
V_6 -> V_104 ( V_6 , V_31 , F_44 ( V_31 , V_110 ) ) ;
}
}
}
static void F_130 ( bool V_113 , bool V_54 ,
unsigned int V_114 ,
struct V_1 * * V_115 ,
int * V_116 )
{
int V_31 = 0 ;
while ( V_31 < V_114 ) {
struct V_5 * V_6 = V_115 [ V_31 ] -> V_6 ;
unsigned long V_109 [ F_131 ( V_6 -> V_10 ) ] ;
unsigned long V_110 [ F_131 ( V_6 -> V_10 ) ] ;
int V_117 = 0 ;
if ( ! V_54 )
F_107 ( V_6 -> V_54 ) ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
do {
struct V_1 * V_11 = V_115 [ V_31 ] ;
int V_118 = F_17 ( V_11 ) ;
int V_102 = V_116 [ V_31 ] ;
if ( ! V_113 && F_44 ( V_94 , & V_11 -> V_7 ) )
V_102 = ! V_102 ;
F_116 ( F_10 ( V_11 ) , 0 , V_102 ) ;
if ( F_44 ( V_95 , & V_11 -> V_7 ) ) {
F_124 ( V_11 , V_102 ) ;
} else if ( F_44 ( V_96 , & V_11 -> V_7 ) ) {
F_125 ( V_11 , V_102 ) ;
} else {
F_132 ( V_118 , V_109 ) ;
if ( V_102 )
F_132 ( V_118 , V_110 ) ;
else
F_133 ( V_118 , V_110 ) ;
V_117 ++ ;
}
V_31 ++ ;
} while ( ( V_31 < V_114 ) && ( V_115 [ V_31 ] -> V_6 == V_6 ) );
if ( V_117 != 0 )
F_127 ( V_6 , V_109 , V_110 ) ;
}
}
void F_134 ( struct V_1 * V_11 , int V_102 )
{
if ( ! V_11 )
return;
F_107 ( V_11 -> V_6 -> V_54 ) ;
F_126 ( V_11 , V_102 ) ;
}
void F_135 ( struct V_1 * V_11 , int V_102 )
{
if ( ! V_11 )
return;
F_107 ( V_11 -> V_6 -> V_54 ) ;
if ( F_44 ( V_94 , & V_11 -> V_7 ) )
V_102 = ! V_102 ;
F_126 ( V_11 , V_102 ) ;
}
void F_136 ( unsigned int V_114 ,
struct V_1 * * V_115 , int * V_116 )
{
if ( ! V_115 )
return;
F_130 ( true , false , V_114 , V_115 ,
V_116 ) ;
}
void F_137 ( unsigned int V_114 ,
struct V_1 * * V_115 , int * V_116 )
{
if ( ! V_115 )
return;
F_130 ( false , false , V_114 , V_115 ,
V_116 ) ;
}
int F_138 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
return V_11 -> V_6 -> V_54 ;
}
int F_139 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( ! V_11 )
return - V_13 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
return V_6 -> V_75 ? V_6 -> V_75 ( V_6 , V_17 ) : - V_119 ;
}
int F_66 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return - V_13 ;
if ( F_44 ( V_20 , & V_6 -> V_11 [ V_17 ] . V_7 ) ) {
F_51 ( V_6 ,
L_30 ,
V_15 ) ;
return - V_101 ;
}
F_19 ( V_103 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
return 0 ;
}
void F_69 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return;
F_18 ( V_103 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
}
int F_140 ( const struct V_1 * V_11 )
{
F_105 ( V_99 ) ;
if ( ! V_11 )
return 0 ;
return F_121 ( V_11 ) ;
}
int F_141 ( const struct V_1 * V_11 )
{
int V_102 ;
F_105 ( V_99 ) ;
if ( ! V_11 )
return 0 ;
V_102 = F_121 ( V_11 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( F_44 ( V_94 , & V_11 -> V_7 ) )
V_102 = ! V_102 ;
return V_102 ;
}
void F_142 ( struct V_1 * V_11 , int V_102 )
{
F_105 ( V_99 ) ;
if ( ! V_11 )
return;
F_126 ( V_11 , V_102 ) ;
}
void F_143 ( struct V_1 * V_11 , int V_102 )
{
F_105 ( V_99 ) ;
if ( ! V_11 )
return;
if ( F_44 ( V_94 , & V_11 -> V_7 ) )
V_102 = ! V_102 ;
F_126 ( V_11 , V_102 ) ;
}
void F_144 ( unsigned int V_114 ,
struct V_1 * * V_115 ,
int * V_116 )
{
F_105 ( V_99 ) ;
if ( ! V_115 )
return;
F_130 ( true , true , V_114 , V_115 ,
V_116 ) ;
}
void F_145 ( unsigned int V_114 ,
struct V_1 * * V_115 ,
int * V_116 )
{
F_105 ( V_99 ) ;
if ( ! V_115 )
return;
F_130 ( false , true , V_114 , V_115 ,
V_116 ) ;
}
void F_146 ( struct V_120 * V_121 )
{
F_147 ( & V_122 ) ;
F_24 ( & V_121 -> V_25 , & V_123 ) ;
F_148 ( & V_122 ) ;
}
void F_149 ( struct V_120 * V_121 )
{
F_147 ( & V_122 ) ;
F_38 ( & V_121 -> V_25 ) ;
F_148 ( & V_122 ) ;
}
static struct V_1 * F_150 ( struct V_124 * V_28 , const char * V_125 ,
unsigned int V_126 ,
enum V_127 * V_7 )
{
char V_128 [ 32 ] ;
enum V_129 V_130 ;
struct V_1 * V_11 ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < F_151 ( V_131 ) ; V_31 ++ ) {
if ( V_125 )
snprintf ( V_128 , sizeof( V_128 ) , L_31 , V_125 ,
V_131 [ V_31 ] ) ;
else
snprintf ( V_128 , sizeof( V_128 ) , L_32 ,
V_131 [ V_31 ] ) ;
V_11 = F_152 ( V_28 -> V_73 , V_128 , V_126 ,
& V_130 ) ;
if ( ! F_93 ( V_11 ) || ( F_94 ( V_11 ) == - V_97 ) )
break;
}
if ( F_93 ( V_11 ) )
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
static struct V_1 * F_153 ( struct V_124 * V_28 , const char * V_125 ,
unsigned int V_126 ,
enum V_127 * V_7 )
{
struct V_137 * V_138 = F_154 ( V_28 ) ;
struct V_139 V_140 ;
struct V_1 * V_11 ;
char V_141 [ 32 ] ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_151 ( V_131 ) ; V_31 ++ ) {
if ( V_125 && strcmp ( V_125 , L_33 ) ) {
snprintf ( V_141 , sizeof( V_141 ) , L_31 ,
V_125 , V_131 [ V_31 ] ) ;
} else {
snprintf ( V_141 , sizeof( V_141 ) , L_32 ,
V_131 [ V_31 ] ) ;
}
V_11 = F_155 ( V_138 , V_141 , V_126 , & V_140 ) ;
if ( ! F_93 ( V_11 ) || ( F_94 ( V_11 ) == - V_97 ) )
break;
}
if ( F_93 ( V_11 ) ) {
V_11 = F_155 ( V_138 , NULL , V_126 , & V_140 ) ;
if ( F_93 ( V_11 ) )
return V_11 ;
}
if ( V_140 . V_142 )
* V_7 |= V_133 ;
return V_11 ;
}
static struct V_120 * F_156 ( struct V_124 * V_28 )
{
const char * V_143 = V_28 ? F_157 ( V_28 ) : NULL ;
struct V_120 * V_121 ;
F_147 ( & V_122 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_121 -> V_143 && V_143 ) {
if ( ! strcmp ( V_121 -> V_143 , V_143 ) )
goto V_144;
} else {
if ( V_143 == V_121 -> V_143 )
goto V_144;
}
}
V_121 = NULL ;
V_144:
F_148 ( & V_122 ) ;
return V_121 ;
}
static struct V_1 * F_158 ( struct V_124 * V_28 , const char * V_125 ,
unsigned int V_126 ,
enum V_127 * V_7 )
{
struct V_1 * V_11 = F_9 ( - V_145 ) ;
struct V_120 * V_121 ;
struct V_146 * V_147 ;
V_121 = F_156 ( V_28 ) ;
if ( ! V_121 )
return V_11 ;
for ( V_147 = & V_121 -> V_121 [ 0 ] ; V_147 -> V_148 ; V_147 ++ ) {
struct V_5 * V_6 ;
if ( V_147 -> V_126 != V_126 )
continue;
if ( V_147 -> V_125 && ( ! V_125 || strcmp ( V_147 -> V_125 , V_125 ) ) )
continue;
V_6 = F_49 ( V_147 -> V_148 ) ;
if ( ! V_6 ) {
F_23 ( V_28 , L_34 ,
V_147 -> V_148 ) ;
return F_9 ( - V_66 ) ;
}
if ( V_6 -> V_10 <= V_147 -> V_149 ) {
F_23 ( V_28 ,
L_35 ,
V_126 , V_6 -> V_10 , V_6 -> V_3 ) ;
return F_9 ( - V_13 ) ;
}
V_11 = F_8 ( V_6 , V_147 -> V_149 ) ;
* V_7 = V_147 -> V_7 ;
return V_11 ;
}
return V_11 ;
}
static int F_159 ( struct V_124 * V_28 , const char * V_125 )
{
int V_83 ;
char V_141 [ 32 ] ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < F_151 ( V_131 ) ; V_31 ++ ) {
if ( V_125 )
snprintf ( V_141 , sizeof( V_141 ) , L_31 ,
V_125 , V_131 [ V_31 ] ) ;
else
snprintf ( V_141 , sizeof( V_141 ) , L_32 ,
V_131 [ V_31 ] ) ;
V_83 = F_160 ( V_28 -> V_73 , V_141 ) ;
if ( V_83 >= 0 )
break;
}
return V_83 ;
}
static int F_161 ( struct V_124 * V_28 , const char * V_125 )
{
struct V_120 * V_121 ;
struct V_146 * V_147 ;
unsigned int V_117 = 0 ;
V_121 = F_156 ( V_28 ) ;
if ( ! V_121 )
return - V_145 ;
for ( V_147 = & V_121 -> V_121 [ 0 ] ; V_147 -> V_148 ; V_147 ++ ) {
if ( ( V_125 && V_147 -> V_125 && ! strcmp ( V_125 , V_147 -> V_125 ) ) ||
( ! V_125 && ! V_147 -> V_125 ) )
V_117 ++ ;
}
if ( ! V_117 )
return - V_145 ;
return V_117 ;
}
int F_162 ( struct V_124 * V_28 , const char * V_125 )
{
int V_117 = - V_145 ;
if ( F_163 ( V_150 ) && V_28 && V_28 -> V_73 )
V_117 = F_159 ( V_28 , V_125 ) ;
else if ( F_163 ( V_151 ) && V_28 && F_164 ( V_28 ) )
V_117 = F_165 ( V_28 , V_125 ) ;
if ( V_117 < 0 )
V_117 = F_161 ( V_28 , V_125 ) ;
return V_117 ;
}
struct V_1 * T_4 F_166 ( struct V_124 * V_28 , const char * V_125 ,
enum V_152 V_7 )
{
return F_167 ( V_28 , V_125 , 0 , V_7 ) ;
}
struct V_1 * T_4 F_168 ( struct V_124 * V_28 ,
const char * V_125 ,
enum V_152 V_7 )
{
return F_169 ( V_28 , V_125 , 0 , V_7 ) ;
}
static void F_170 ( struct V_1 * V_11 , unsigned long V_153 )
{
if ( V_153 & V_133 )
F_19 ( V_94 , & V_11 -> V_7 ) ;
if ( V_153 & V_135 )
F_19 ( V_95 , & V_11 -> V_7 ) ;
if ( V_153 & V_136 )
F_19 ( V_96 , & V_11 -> V_7 ) ;
}
static int F_171 ( struct V_1 * V_11 , const char * V_125 ,
enum V_152 V_154 )
{
int V_18 ;
if ( ! ( V_154 & V_155 ) ) {
F_14 ( L_36 , V_125 ) ;
return 0 ;
}
if ( V_154 & V_156 )
V_18 = F_118 ( V_11 ,
V_154 & V_157 ) ;
else
V_18 = F_111 ( V_11 ) ;
return V_18 ;
}
struct V_1 * T_4 F_167 ( struct V_124 * V_28 ,
const char * V_125 ,
unsigned int V_126 ,
enum V_152 V_7 )
{
struct V_1 * V_11 = NULL ;
int V_18 ;
enum V_127 V_158 = 0 ;
F_172 ( V_28 , L_37 , V_125 ) ;
if ( V_28 ) {
if ( F_163 ( V_150 ) && V_28 -> V_73 ) {
F_172 ( V_28 , L_38 ) ;
V_11 = F_150 ( V_28 , V_125 , V_126 , & V_158 ) ;
} else if ( F_154 ( V_28 ) ) {
F_172 ( V_28 , L_39 ) ;
V_11 = F_153 ( V_28 , V_125 , V_126 , & V_158 ) ;
}
}
if ( ! V_11 || V_11 == F_9 ( - V_145 ) ) {
F_172 ( V_28 , L_40 ) ;
V_11 = F_158 ( V_28 , V_125 , V_126 , & V_158 ) ;
}
if ( F_93 ( V_11 ) ) {
F_172 ( V_28 , L_41 , V_125 ) ;
return V_11 ;
}
F_170 ( V_11 , V_158 ) ;
V_18 = F_99 ( V_11 , V_125 ) ;
if ( V_18 < 0 )
return F_9 ( V_18 ) ;
V_18 = F_171 ( V_11 , V_125 , V_7 ) ;
if ( V_18 < 0 ) {
F_172 ( V_28 , L_42 , V_125 ) ;
F_173 ( V_11 ) ;
return F_9 ( V_18 ) ;
}
return V_11 ;
}
struct V_1 * F_174 ( struct V_159 * V_160 ,
const char * V_141 )
{
struct V_1 * V_11 = F_9 ( - V_66 ) ;
bool V_142 = false ;
bool V_161 = false ;
int V_83 ;
if ( ! V_160 )
return F_9 ( - V_13 ) ;
if ( F_175 ( V_160 ) ) {
enum V_129 V_7 ;
V_11 = F_152 ( F_176 ( V_160 ) , V_141 , 0 ,
& V_7 ) ;
if ( ! F_93 ( V_11 ) ) {
V_142 = V_7 & V_132 ;
V_161 = V_7 & V_134 ;
}
} else if ( F_177 ( V_160 ) ) {
struct V_139 V_140 ;
V_11 = F_178 ( V_160 , V_141 , 0 , & V_140 ) ;
if ( ! F_93 ( V_11 ) )
V_142 = V_140 . V_142 ;
}
if ( F_93 ( V_11 ) )
return V_11 ;
if ( V_142 )
F_19 ( V_94 , & V_11 -> V_7 ) ;
if ( V_161 ) {
if ( V_142 )
F_19 ( V_95 , & V_11 -> V_7 ) ;
else
F_19 ( V_96 , & V_11 -> V_7 ) ;
}
V_83 = F_99 ( V_11 , NULL ) ;
if ( V_83 )
return F_9 ( V_83 ) ;
return V_11 ;
}
struct V_1 * T_4 F_169 ( struct V_124 * V_28 ,
const char * V_125 ,
unsigned int V_162 ,
enum V_152 V_7 )
{
struct V_1 * V_11 ;
V_11 = F_167 ( V_28 , V_125 , V_162 , V_7 ) ;
if ( F_93 ( V_11 ) ) {
if ( F_94 ( V_11 ) == - V_145 )
return NULL ;
}
return V_11 ;
}
int F_179 ( struct V_1 * V_11 , const char * V_30 ,
unsigned long V_153 , enum V_152 V_154 )
{
struct V_5 * V_6 ;
struct V_1 * V_163 ;
int V_12 ;
int V_18 ;
V_6 = F_11 ( V_11 ) ;
V_12 = F_17 ( V_11 ) ;
F_170 ( V_11 , V_153 ) ;
V_163 = F_109 ( V_6 , V_12 , V_30 ) ;
if ( F_93 ( V_163 ) ) {
F_15 ( L_43 ,
V_30 , V_6 -> V_3 , V_12 ) ;
return F_94 ( V_163 ) ;
}
V_18 = F_171 ( V_11 , V_30 , V_154 ) ;
if ( V_18 < 0 ) {
F_15 ( L_44 ,
V_30 , V_6 -> V_3 , V_12 ) ;
F_110 ( V_11 ) ;
return V_18 ;
}
F_19 ( V_98 , & V_11 -> V_7 ) ;
F_180 ( L_45 ,
F_10 ( V_11 ) , V_30 ,
( V_154 & V_156 ) ? L_46 : L_47 ,
( V_154 & V_156 ) ?
( V_154 & V_157 ) ? L_48 : L_49 : L_50 ) ;
return 0 ;
}
static void F_36 ( struct V_5 * V_6 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 -> V_10 ; V_34 ++ ) {
if ( F_44 ( V_98 , & V_6 -> V_11 [ V_34 ] . V_7 ) )
F_110 ( & V_6 -> V_11 [ V_34 ] ) ;
}
}
struct V_164 * T_4 F_181 ( struct V_124 * V_28 ,
const char * V_125 ,
enum V_152 V_7 )
{
struct V_1 * V_11 ;
struct V_164 * V_35 ;
int V_117 ;
V_117 = F_162 ( V_28 , V_125 ) ;
if ( V_117 < 0 )
return F_9 ( V_117 ) ;
V_35 = F_86 ( sizeof( * V_35 ) + sizeof( V_35 -> V_11 [ 0 ] ) * V_117 ,
V_36 ) ;
if ( ! V_35 )
return F_9 ( - V_37 ) ;
for ( V_35 -> V_165 = 0 ; V_35 -> V_165 < V_117 ; ) {
V_11 = F_167 ( V_28 , V_125 , V_35 -> V_165 , V_7 ) ;
if ( F_93 ( V_11 ) ) {
F_182 ( V_35 ) ;
return F_183 ( V_11 ) ;
}
V_35 -> V_11 [ V_35 -> V_165 ] = V_11 ;
V_35 -> V_165 ++ ;
}
return V_35 ;
}
struct V_164 * T_4 F_184 ( struct V_124 * V_28 ,
const char * V_125 ,
enum V_152 V_7 )
{
struct V_164 * V_35 ;
V_35 = F_181 ( V_28 , V_125 , V_7 ) ;
if ( F_93 ( V_35 ) && ( F_94 ( V_35 ) == - V_145 ) )
return NULL ;
return V_35 ;
}
void F_173 ( struct V_1 * V_11 )
{
F_106 ( V_11 ) ;
}
void F_182 ( struct V_164 * V_35 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_35 -> V_165 ; V_31 ++ )
F_173 ( V_35 -> V_11 [ V_31 ] ) ;
F_39 ( V_35 ) ;
}
static void F_185 ( struct V_166 * V_167 , struct V_5 * V_6 )
{
unsigned V_31 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_168 = & V_6 -> V_11 [ 0 ] ;
int V_169 ;
int V_170 ;
for ( V_31 = 0 ; V_31 < V_6 -> V_10 ; V_31 ++ , V_4 ++ , V_168 ++ ) {
if ( ! F_44 ( V_46 , & V_168 -> V_7 ) ) {
if ( V_168 -> V_30 ) {
F_186 ( V_167 , L_51 ,
V_4 , V_168 -> V_30 ) ;
}
continue;
}
F_16 ( V_168 ) ;
V_169 = F_44 ( V_20 , & V_168 -> V_7 ) ;
V_170 = F_44 ( V_103 , & V_168 -> V_7 ) ;
F_186 ( V_167 , L_52 ,
V_4 , V_168 -> V_30 ? V_168 -> V_30 : L_50 , V_168 -> V_3 ,
V_169 ? L_53 : L_54 ,
V_6 -> V_100
? ( V_6 -> V_100 ( V_6 , V_31 ) ? L_55 : L_56 )
: L_57 ,
V_170 ? L_58 : L_59 ) ;
F_186 ( V_167 , L_60 ) ;
}
}
static void * F_187 ( struct V_166 * V_167 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_5 V_162 = * V_22 ;
V_167 -> V_171 = L_50 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( V_162 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_188 ( struct V_166 * V_167 , void * V_172 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_172 ;
void * V_83 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_189 ( & V_6 -> V_25 , & V_26 ) )
V_83 = NULL ;
else
V_83 = F_22 ( V_6 -> V_25 . V_173 , struct V_5 , V_25 ) ;
F_5 ( & V_8 , V_7 ) ;
V_167 -> V_171 = L_60 ;
++ * V_22 ;
return V_83 ;
}
static void F_190 ( struct V_166 * V_167 , void * V_172 )
{
}
static int F_191 ( struct V_166 * V_167 , void * V_172 )
{
struct V_5 * V_6 = V_172 ;
struct V_124 * V_28 ;
F_186 ( V_167 , L_61 , ( char * ) V_167 -> V_171 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_28 = V_6 -> V_28 ;
if ( V_28 )
F_186 ( V_167 , L_62 , V_28 -> V_174 ? V_28 -> V_174 -> V_30 : L_63 ,
F_157 ( V_28 ) ) ;
if ( V_6 -> V_3 )
F_186 ( V_167 , L_64 , V_6 -> V_3 ) ;
if ( V_6 -> V_54 )
F_186 ( V_167 , L_65 ) ;
F_186 ( V_167 , L_66 ) ;
if ( V_6 -> V_175 )
V_6 -> V_175 ( V_167 , V_6 ) ;
else
F_185 ( V_167 , V_6 ) ;
return 0 ;
}
static int F_192 ( struct V_176 * V_176 , struct V_177 * V_177 )
{
return F_193 ( V_177 , & V_178 ) ;
}
static int T_6 F_194 ( void )
{
( void ) F_195 ( L_67 , V_179 | V_180 ,
NULL , NULL , & V_181 ) ;
return 0 ;
}
