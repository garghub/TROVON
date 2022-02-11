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
struct V_21 * V_22 = & V_23 ;
struct V_5 * V_24 ;
int V_25 = 0 ;
F_21 (pos, &gpio_chips) {
V_24 = F_22 ( V_22 , struct V_5 , V_26 ) ;
if ( V_24 -> V_9 >= V_6 -> V_9 + V_6 -> V_10 )
break;
}
if ( V_22 != & V_23 && V_22 -> V_27 != & V_23 ) {
V_24 = F_22 ( V_22 -> V_27 , struct V_5 , V_26 ) ;
if ( V_24 -> V_9 + V_24 -> V_10 > V_6 -> V_9 ) {
F_23 ( V_6 -> V_28 ,
L_4 ) ;
V_25 = - V_29 ;
}
}
if ( ! V_25 )
F_24 ( & V_6 -> V_26 , V_22 ) ;
return V_25 ;
}
int F_25 ( struct V_5 * V_6 )
{
unsigned long V_7 ;
int V_18 = 0 ;
unsigned V_30 ;
int V_9 = V_6 -> V_9 ;
struct V_1 * V_31 ;
V_31 = F_26 ( V_6 -> V_10 , sizeof( V_31 [ 0 ] ) , V_32 ) ;
if ( ! V_31 )
return - V_33 ;
F_3 ( & V_8 , V_7 ) ;
if ( V_9 < 0 ) {
V_9 = F_12 ( V_6 -> V_10 ) ;
if ( V_9 < 0 ) {
V_18 = V_9 ;
F_5 ( & V_8 , V_7 ) ;
goto V_34;
}
V_6 -> V_9 = V_9 ;
}
V_18 = F_20 ( V_6 ) ;
if ( V_18 ) {
F_5 ( & V_8 , V_7 ) ;
goto V_34;
}
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ ) {
struct V_1 * V_11 = & V_31 [ V_30 ] ;
V_11 -> V_6 = V_6 ;
V_11 -> V_7 = ! V_6 -> V_35 ? ( 1 << V_20 ) : 0 ;
}
V_6 -> V_11 = V_31 ;
F_5 ( & V_8 , V_7 ) ;
#ifdef F_27
F_28 ( & V_6 -> V_36 ) ;
#endif
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
V_18 = F_31 ( V_6 ) ;
if ( V_18 )
goto V_37;
F_14 ( L_5 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_6 ) ;
return 0 ;
V_37:
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
F_3 ( & V_8 , V_7 ) ;
F_35 ( & V_6 -> V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
V_6 -> V_11 = NULL ;
V_34:
F_36 ( V_31 ) ;
F_15 ( L_7 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_6 ) ;
return V_18 ;
}
void F_37 ( struct V_5 * V_6 )
{
unsigned long V_7 ;
unsigned V_30 ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_32 ( V_6 ) ;
F_40 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
F_3 ( & V_8 , V_7 ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ ) {
if ( F_41 ( V_38 , & V_6 -> V_11 [ V_30 ] . V_7 ) )
F_42 ( V_6 -> V_28 , L_8 ) ;
}
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ )
V_6 -> V_11 [ V_30 ] . V_6 = NULL ;
F_35 ( & V_6 -> V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
F_36 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
struct V_5 * F_43 ( void * V_39 ,
int (* F_44)( struct V_5 * V_6 ,
void * V_39 ) )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( F_44 ( V_6 , V_39 ) )
break;
if ( & V_6 -> V_26 == & V_23 )
V_6 = NULL ;
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
static int F_45 ( struct V_5 * V_6 , void * V_39 )
{
const char * V_40 = V_39 ;
return ! strcmp ( V_6 -> V_3 , V_40 ) ;
}
static struct V_5 * F_46 ( const char * V_40 )
{
return F_43 ( ( void * ) V_40 , F_45 ) ;
}
void F_47 ( struct V_5 * V_41 ,
struct V_42 * V_43 ,
int V_44 ,
T_2 V_45 )
{
unsigned int V_17 ;
if ( ! V_41 -> V_46 ) {
F_48 ( V_41 , L_9 ,
V_15 ) ;
return;
}
if ( V_45 ) {
if ( V_41 -> V_47 ) {
F_48 ( V_41 ,
L_10
L_11 ) ;
return;
}
F_49 ( V_44 , V_41 ) ;
F_50 ( V_44 , V_45 ) ;
}
for ( V_17 = 0 ; V_17 < V_41 -> V_10 ; V_17 ++ )
F_51 ( F_52 ( V_41 -> V_46 , V_17 ) ,
V_44 ) ;
}
static int F_53 ( struct V_48 * V_2 , unsigned int V_49 ,
T_3 V_50 )
{
struct V_5 * V_6 = V_2 -> V_51 ;
F_54 ( V_49 , V_6 ) ;
F_55 ( V_49 , & V_52 ) ;
F_56 ( V_49 , V_6 -> V_43 , V_6 -> V_53 ) ;
if ( V_6 -> V_47 && ! V_6 -> V_54 )
F_57 ( V_49 , 1 ) ;
#ifdef F_58
F_59 ( V_49 , V_55 ) ;
#else
F_60 ( V_49 ) ;
#endif
if ( V_6 -> V_56 != V_57 )
F_61 ( V_49 , V_6 -> V_56 ) ;
return 0 ;
}
static void F_62 ( struct V_48 * V_2 , unsigned int V_49 )
{
struct V_5 * V_6 = V_2 -> V_51 ;
#ifdef F_58
F_59 ( V_49 , 0 ) ;
#endif
if ( V_6 -> V_47 )
F_57 ( V_49 , 0 ) ;
F_56 ( V_49 , NULL , NULL ) ;
F_54 ( V_49 , NULL ) ;
}
static int F_63 ( struct V_58 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
if ( F_65 ( V_6 , V_2 -> V_50 ) ) {
F_48 ( V_6 ,
L_12 ,
V_2 -> V_50 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_66 ( struct V_58 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
F_67 ( V_6 , V_2 -> V_50 ) ;
}
static int F_68 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_52 ( V_6 -> V_46 , V_17 ) ;
}
static void F_39 ( struct V_5 * V_41 )
{
unsigned int V_17 ;
F_69 ( V_41 ) ;
if ( V_41 -> V_46 ) {
for ( V_17 = 0 ; V_17 < V_41 -> V_10 ; V_17 ++ )
F_70 (
F_52 ( V_41 -> V_46 , V_17 ) ) ;
F_71 ( V_41 -> V_46 ) ;
}
if ( V_41 -> V_43 ) {
V_41 -> V_43 -> V_59 = NULL ;
V_41 -> V_43 -> V_60 = NULL ;
V_41 -> V_43 = NULL ;
}
}
int F_72 ( struct V_5 * V_41 ,
struct V_42 * V_43 ,
unsigned int V_61 ,
T_2 V_62 ,
unsigned int type )
{
struct V_63 * V_64 ;
unsigned int V_17 ;
unsigned V_65 = 0 ;
if ( ! V_41 || ! V_43 )
return - V_13 ;
if ( ! V_41 -> V_28 ) {
F_15 ( L_13 ) ;
return - V_13 ;
}
V_64 = V_41 -> V_28 -> V_64 ;
#ifdef F_73
if ( V_41 -> V_64 )
V_64 = V_41 -> V_64 ;
#endif
V_41 -> V_43 = V_43 ;
V_41 -> V_53 = V_62 ;
V_41 -> V_56 = type ;
V_41 -> V_66 = F_68 ;
V_41 -> V_46 = F_74 ( V_64 ,
V_41 -> V_10 , V_61 ,
& V_67 , V_41 ) ;
if ( ! V_41 -> V_46 ) {
V_41 -> V_43 = NULL ;
return - V_13 ;
}
V_43 -> V_59 = F_63 ;
V_43 -> V_60 = F_66 ;
for ( V_17 = 0 ; V_17 < V_41 -> V_10 ; V_17 ++ ) {
V_65 = F_75 ( V_41 -> V_46 , V_17 ) ;
if ( V_17 == 0 )
V_41 -> V_65 = V_65 ;
}
F_76 ( V_41 ) ;
return 0 ;
}
static void F_39 ( struct V_5 * V_41 ) {}
int F_77 ( struct V_5 * V_6 ,
struct V_68 * V_69 ,
unsigned int V_70 , const char * V_71 )
{
struct V_72 * V_73 ;
int V_74 ;
V_73 = F_78 ( sizeof( * V_73 ) , V_32 ) ;
if ( ! V_73 ) {
F_48 ( V_6 , L_14 ) ;
return - V_33 ;
}
V_73 -> V_75 . V_30 = V_70 ;
V_73 -> V_75 . V_76 = V_6 ;
V_73 -> V_75 . V_40 = V_6 -> V_3 ;
V_73 -> V_75 . V_9 = V_6 -> V_9 + V_70 ;
V_73 -> V_69 = V_69 ;
V_74 = F_79 ( V_69 , V_71 ,
& V_73 -> V_75 . V_77 ,
& V_73 -> V_75 . V_78 ) ;
if ( V_74 < 0 ) {
F_36 ( V_73 ) ;
return V_74 ;
}
F_80 ( V_69 , & V_73 -> V_75 ) ;
F_81 ( V_6 , L_15 ,
V_70 , V_70 + V_73 -> V_75 . V_78 - 1 ,
F_82 ( V_69 ) , V_71 ) ;
F_24 ( & V_73 -> V_79 , & V_6 -> V_36 ) ;
return 0 ;
}
int F_83 ( struct V_5 * V_6 , const char * V_80 ,
unsigned int V_70 , unsigned int V_81 ,
unsigned int V_78 )
{
struct V_72 * V_73 ;
int V_74 ;
V_73 = F_78 ( sizeof( * V_73 ) , V_32 ) ;
if ( ! V_73 ) {
F_48 ( V_6 , L_14 ) ;
return - V_33 ;
}
V_73 -> V_75 . V_30 = V_70 ;
V_73 -> V_75 . V_76 = V_6 ;
V_73 -> V_75 . V_40 = V_6 -> V_3 ;
V_73 -> V_75 . V_9 = V_6 -> V_9 + V_70 ;
V_73 -> V_75 . V_82 = V_81 ;
V_73 -> V_75 . V_78 = V_78 ;
V_73 -> V_69 = F_84 ( V_80 ,
& V_73 -> V_75 ) ;
if ( F_85 ( V_73 -> V_69 ) ) {
V_74 = F_86 ( V_73 -> V_69 ) ;
F_48 ( V_6 , L_16 ) ;
F_36 ( V_73 ) ;
return V_74 ;
}
F_81 ( V_6 , L_17 ,
V_70 , V_70 + V_78 - 1 ,
V_80 ,
V_81 , V_81 + V_78 - 1 ) ;
F_24 ( & V_73 -> V_79 , & V_6 -> V_36 ) ;
return 0 ;
}
void F_40 ( struct V_5 * V_6 )
{
struct V_72 * V_73 , * V_83 ;
F_87 (pin_range, tmp, &chip->pin_ranges, node) {
F_35 ( & V_73 -> V_79 ) ;
F_88 ( V_73 -> V_69 ,
& V_73 -> V_75 ) ;
F_36 ( V_73 ) ;
}
}
static int F_89 ( struct V_1 * V_11 , const char * V_3 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
int V_18 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_90 ( V_38 , & V_11 -> V_7 ) == 0 ) {
F_1 ( V_11 , V_3 ? : L_18 ) ;
V_18 = 0 ;
} else {
V_18 = - V_29 ;
goto V_84;
}
if ( V_6 -> V_85 ) {
F_5 ( & V_8 , V_7 ) ;
V_18 = V_6 -> V_85 ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_18 < 0 ) {
F_1 ( V_11 , NULL ) ;
F_18 ( V_38 , & V_11 -> V_7 ) ;
goto V_84;
}
}
if ( V_6 -> V_19 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_84:
F_5 ( & V_8 , V_7 ) ;
return V_18 ;
}
int F_91 ( struct V_1 * V_11 , const char * V_3 )
{
int V_18 = - V_86 ;
struct V_5 * V_6 ;
if ( ! V_11 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 )
goto V_84;
if ( F_93 ( V_6 -> V_87 ) ) {
V_18 = F_89 ( V_11 , V_3 ) ;
if ( V_18 < 0 )
F_94 ( V_6 -> V_87 ) ;
}
V_84:
if ( V_18 )
F_95 ( V_11 , L_20 , V_15 , V_18 ) ;
return V_18 ;
}
static bool F_96 ( struct V_1 * V_11 )
{
bool V_74 = false ;
unsigned long V_7 ;
struct V_5 * V_6 ;
F_97 () ;
F_98 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
V_6 = V_11 -> V_6 ;
if ( V_6 && F_41 ( V_38 , & V_11 -> V_7 ) ) {
if ( V_6 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_99 ( V_6 -> V_47 ) ;
V_6 -> free ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_11 , NULL ) ;
F_18 ( V_88 , & V_11 -> V_7 ) ;
F_18 ( V_38 , & V_11 -> V_7 ) ;
F_18 ( V_89 , & V_11 -> V_7 ) ;
F_18 ( V_90 , & V_11 -> V_7 ) ;
F_18 ( V_91 , & V_11 -> V_7 ) ;
V_74 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_74 ;
}
void F_100 ( struct V_1 * V_11 )
{
if ( V_11 && F_96 ( V_11 ) )
F_94 ( V_11 -> V_6 -> V_87 ) ;
else
F_101 ( V_92 ) ;
}
const char * F_102 ( struct V_5 * V_6 , unsigned V_17 )
{
struct V_1 * V_11 ;
if ( ! F_103 ( V_6 , V_17 ) )
return NULL ;
V_11 = & V_6 -> V_11 [ V_17 ] ;
if ( F_41 ( V_38 , & V_11 -> V_7 ) == 0 )
return NULL ;
return V_11 -> V_3 ;
}
struct V_1 * F_104 ( struct V_5 * V_6 , T_1 V_12 ,
const char * V_3 )
{
struct V_1 * V_11 = F_8 ( V_6 , V_12 ) ;
int V_25 ;
if ( F_85 ( V_11 ) ) {
F_48 ( V_6 , L_21 ) ;
return V_11 ;
}
V_25 = F_89 ( V_11 , V_3 ) ;
if ( V_25 < 0 )
return F_9 ( V_25 ) ;
return V_11 ;
}
void F_105 ( struct V_1 * V_11 )
{
if ( V_11 )
F_96 ( V_11 ) ;
}
int F_106 ( struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_93 || ! V_6 -> V_35 ) {
F_107 ( V_11 ,
L_22 ,
V_15 ) ;
return - V_94 ;
}
V_18 = V_6 -> V_35 ( V_6 , F_17 ( V_11 ) ) ;
if ( V_18 == 0 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
F_108 ( F_10 ( V_11 ) , 1 , V_18 ) ;
return V_18 ;
}
static int F_109 ( struct V_1 * V_11 , int V_95 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( F_41 ( V_96 , & V_11 -> V_7 ) ) {
F_110 ( V_11 ,
L_23 ,
V_15 ) ;
return - V_94 ;
}
if ( V_95 && F_41 ( V_89 , & V_11 -> V_7 ) )
return F_106 ( V_11 ) ;
if ( ! V_95 && F_41 ( V_90 , & V_11 -> V_7 ) )
return F_106 ( V_11 ) ;
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_97 || ! V_6 -> V_98 ) {
F_107 ( V_11 ,
L_24 ,
V_15 ) ;
return - V_94 ;
}
V_18 = V_6 -> V_98 ( V_6 , F_17 ( V_11 ) , V_95 ) ;
if ( V_18 == 0 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
F_111 ( F_10 ( V_11 ) , 0 , V_95 ) ;
F_108 ( F_10 ( V_11 ) , 0 , V_18 ) ;
return V_18 ;
}
int F_112 ( struct V_1 * V_11 , int V_95 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
return F_109 ( V_11 , V_95 ) ;
}
int F_113 ( struct V_1 * V_11 , int V_95 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
if ( F_41 ( V_88 , & V_11 -> V_7 ) )
V_95 = ! V_95 ;
return F_109 ( V_11 , V_95 ) ;
}
int F_114 ( struct V_1 * V_11 , unsigned V_99 )
{
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_97 || ! V_6 -> V_100 ) {
F_95 ( V_11 ,
L_25 ,
V_15 ) ;
return - V_101 ;
}
return V_6 -> V_100 ( V_6 , F_17 ( V_11 ) , V_99 ) ;
}
int F_115 ( const struct V_1 * V_11 )
{
return F_41 ( V_88 , & V_11 -> V_7 ) ;
}
static bool F_116 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
bool V_95 ;
int V_17 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
V_95 = V_6 -> V_93 ? V_6 -> V_93 ( V_6 , V_17 ) : false ;
F_111 ( F_10 ( V_11 ) , 1 , V_95 ) ;
return V_95 ;
}
int F_117 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
F_101 ( V_11 -> V_6 -> V_47 ) ;
return F_116 ( V_11 ) ;
}
int F_118 ( const struct V_1 * V_11 )
{
int V_95 ;
if ( ! V_11 )
return 0 ;
F_101 ( V_11 -> V_6 -> V_47 ) ;
V_95 = F_116 ( V_11 ) ;
if ( F_41 ( V_88 , & V_11 -> V_7 ) )
V_95 = ! V_95 ;
return V_95 ;
}
static void F_119 ( struct V_1 * V_11 , bool V_95 )
{
int V_25 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_95 ) {
V_25 = V_6 -> V_35 ( V_6 , V_17 ) ;
if ( ! V_25 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_25 = V_6 -> V_98 ( V_6 , V_17 , 0 ) ;
if ( ! V_25 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
}
F_108 ( F_10 ( V_11 ) , V_95 , V_25 ) ;
if ( V_25 < 0 )
F_110 ( V_11 ,
L_26 ,
V_15 , V_25 ) ;
}
static void F_120 ( struct V_1 * V_11 , bool V_95 )
{
int V_25 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_95 ) {
V_25 = V_6 -> V_98 ( V_6 , V_17 , 1 ) ;
if ( ! V_25 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_25 = V_6 -> V_35 ( V_6 , V_17 ) ;
if ( ! V_25 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
}
F_108 ( F_10 ( V_11 ) , ! V_95 , V_25 ) ;
if ( V_25 < 0 )
F_110 ( V_11 ,
L_27 ,
V_15 , V_25 ) ;
}
static void F_121 ( struct V_1 * V_11 , bool V_95 )
{
struct V_5 * V_6 ;
V_6 = V_11 -> V_6 ;
F_111 ( F_10 ( V_11 ) , 0 , V_95 ) ;
if ( F_41 ( V_89 , & V_11 -> V_7 ) )
F_119 ( V_11 , V_95 ) ;
else if ( F_41 ( V_90 , & V_11 -> V_7 ) )
F_120 ( V_11 , V_95 ) ;
else
V_6 -> V_97 ( V_6 , F_17 ( V_11 ) , V_95 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
unsigned long * V_102 , unsigned long * V_103 )
{
if ( V_6 -> V_104 ) {
V_6 -> V_104 ( V_6 , V_102 , V_103 ) ;
} else {
int V_105 ;
for ( V_105 = 0 ; V_105 < V_6 -> V_10 ; V_105 ++ ) {
if ( V_102 [ F_123 ( V_105 ) ] == 0 ) {
V_105 = ( F_123 ( V_105 ) + 1 ) * V_106 - 1 ;
continue;
}
if ( F_124 ( V_105 , V_102 ) ) {
V_6 -> V_97 ( V_6 , V_105 , F_41 ( V_105 , V_103 ) ) ;
}
}
}
}
static void F_125 ( bool V_107 , bool V_47 ,
unsigned int V_108 ,
struct V_1 * * V_109 ,
int * V_110 )
{
int V_105 = 0 ;
while ( V_105 < V_108 ) {
struct V_5 * V_6 = V_109 [ V_105 ] -> V_6 ;
unsigned long V_102 [ F_126 ( V_6 -> V_10 ) ] ;
unsigned long V_103 [ F_126 ( V_6 -> V_10 ) ] ;
int V_111 = 0 ;
if ( ! V_47 ) {
F_101 ( V_6 -> V_47 ) ;
}
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
do {
struct V_1 * V_11 = V_109 [ V_105 ] ;
int V_112 = F_17 ( V_11 ) ;
int V_95 = V_110 [ V_105 ] ;
if ( ! V_107 && F_41 ( V_88 , & V_11 -> V_7 ) )
V_95 = ! V_95 ;
F_111 ( F_10 ( V_11 ) , 0 , V_95 ) ;
if ( F_41 ( V_89 , & V_11 -> V_7 ) ) {
F_119 ( V_11 , V_95 ) ;
} else if ( F_41 ( V_90 , & V_11 -> V_7 ) ) {
F_120 ( V_11 , V_95 ) ;
} else {
F_127 ( V_112 , V_102 ) ;
if ( V_95 ) {
F_127 ( V_112 , V_103 ) ;
} else {
F_128 ( V_112 , V_103 ) ;
}
V_111 ++ ;
}
V_105 ++ ;
} while ( ( V_105 < V_108 ) && ( V_109 [ V_105 ] -> V_6 == V_6 ) );
if ( V_111 != 0 ) {
F_122 ( V_6 , V_102 , V_103 ) ;
}
}
}
void F_129 ( struct V_1 * V_11 , int V_95 )
{
if ( ! V_11 )
return;
F_101 ( V_11 -> V_6 -> V_47 ) ;
F_121 ( V_11 , V_95 ) ;
}
void F_130 ( struct V_1 * V_11 , int V_95 )
{
if ( ! V_11 )
return;
F_101 ( V_11 -> V_6 -> V_47 ) ;
if ( F_41 ( V_88 , & V_11 -> V_7 ) )
V_95 = ! V_95 ;
F_121 ( V_11 , V_95 ) ;
}
void F_131 ( unsigned int V_108 ,
struct V_1 * * V_109 , int * V_110 )
{
if ( ! V_109 )
return;
F_125 ( true , false , V_108 , V_109 , V_110 ) ;
}
void F_132 ( unsigned int V_108 ,
struct V_1 * * V_109 , int * V_110 )
{
if ( ! V_109 )
return;
F_125 ( false , false , V_108 , V_109 , V_110 ) ;
}
int F_133 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
return V_11 -> V_6 -> V_47 ;
}
int F_134 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( ! V_11 )
return - V_13 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
return V_6 -> V_66 ? V_6 -> V_66 ( V_6 , V_17 ) : - V_113 ;
}
int F_65 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return - V_13 ;
if ( F_41 ( V_20 , & V_6 -> V_11 [ V_17 ] . V_7 ) ) {
F_48 ( V_6 ,
L_28 ,
V_15 ) ;
return - V_94 ;
}
F_19 ( V_96 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
return 0 ;
}
void F_67 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return;
F_18 ( V_96 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
}
int F_135 ( const struct V_1 * V_11 )
{
F_99 ( V_92 ) ;
if ( ! V_11 )
return 0 ;
return F_116 ( V_11 ) ;
}
int F_136 ( const struct V_1 * V_11 )
{
int V_95 ;
F_99 ( V_92 ) ;
if ( ! V_11 )
return 0 ;
V_95 = F_116 ( V_11 ) ;
if ( F_41 ( V_88 , & V_11 -> V_7 ) )
V_95 = ! V_95 ;
return V_95 ;
}
void F_137 ( struct V_1 * V_11 , int V_95 )
{
F_99 ( V_92 ) ;
if ( ! V_11 )
return;
F_121 ( V_11 , V_95 ) ;
}
void F_138 ( struct V_1 * V_11 , int V_95 )
{
F_99 ( V_92 ) ;
if ( ! V_11 )
return;
if ( F_41 ( V_88 , & V_11 -> V_7 ) )
V_95 = ! V_95 ;
F_121 ( V_11 , V_95 ) ;
}
void F_139 ( unsigned int V_108 ,
struct V_1 * * V_109 ,
int * V_110 )
{
F_99 ( V_92 ) ;
if ( ! V_109 )
return;
F_125 ( true , true , V_108 , V_109 , V_110 ) ;
}
void F_140 ( unsigned int V_108 ,
struct V_1 * * V_109 ,
int * V_110 )
{
F_99 ( V_92 ) ;
if ( ! V_109 )
return;
F_125 ( false , true , V_108 , V_109 , V_110 ) ;
}
void F_141 ( struct V_114 * V_115 )
{
F_142 ( & V_116 ) ;
F_24 ( & V_115 -> V_26 , & V_117 ) ;
F_143 ( & V_116 ) ;
}
static struct V_1 * F_144 ( struct V_118 * V_28 , const char * V_119 ,
unsigned int V_120 ,
enum V_121 * V_7 )
{
char V_122 [ 32 ] ;
enum V_123 V_124 ;
struct V_1 * V_11 ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < F_145 ( V_125 ) ; V_105 ++ ) {
if ( V_119 )
snprintf ( V_122 , sizeof( V_122 ) , L_29 , V_119 ,
V_125 [ V_105 ] ) ;
else
snprintf ( V_122 , sizeof( V_122 ) , L_30 ,
V_125 [ V_105 ] ) ;
V_11 = F_146 ( V_28 -> V_64 , V_122 , V_120 ,
& V_124 ) ;
if ( ! F_85 ( V_11 ) || ( F_86 ( V_11 ) == - V_86 ) )
break;
}
if ( F_85 ( V_11 ) )
return V_11 ;
if ( V_124 & V_126 )
* V_7 |= V_127 ;
return V_11 ;
}
static struct V_1 * F_147 ( struct V_118 * V_28 , const char * V_119 ,
unsigned int V_120 ,
enum V_121 * V_7 )
{
struct V_128 * V_129 = F_148 ( V_28 ) ;
struct V_130 V_131 ;
struct V_1 * V_11 ;
char V_132 [ 32 ] ;
int V_105 ;
for ( V_105 = 0 ; V_105 < F_145 ( V_125 ) ; V_105 ++ ) {
if ( V_119 && strcmp ( V_119 , L_31 ) ) {
snprintf ( V_132 , sizeof( V_132 ) , L_29 ,
V_119 , V_125 [ V_105 ] ) ;
} else {
snprintf ( V_132 , sizeof( V_132 ) , L_30 ,
V_125 [ V_105 ] ) ;
}
V_11 = F_149 ( V_129 , V_132 , V_120 , & V_131 ) ;
if ( ! F_85 ( V_11 ) || ( F_86 ( V_11 ) == - V_86 ) )
break;
}
if ( F_85 ( V_11 ) ) {
V_11 = F_149 ( V_129 , NULL , V_120 , & V_131 ) ;
if ( F_85 ( V_11 ) )
return V_11 ;
}
if ( V_131 . V_133 )
* V_7 |= V_127 ;
return V_11 ;
}
static struct V_114 * F_150 ( struct V_118 * V_28 )
{
const char * V_134 = V_28 ? F_151 ( V_28 ) : NULL ;
struct V_114 * V_115 ;
F_142 ( & V_116 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_115 -> V_134 && V_134 ) {
if ( ! strcmp ( V_115 -> V_134 , V_134 ) )
goto V_135;
} else {
if ( V_134 == V_115 -> V_134 )
goto V_135;
}
}
V_115 = NULL ;
V_135:
F_143 ( & V_116 ) ;
return V_115 ;
}
static struct V_1 * F_152 ( struct V_118 * V_28 , const char * V_119 ,
unsigned int V_120 ,
enum V_121 * V_7 )
{
struct V_1 * V_11 = F_9 ( - V_136 ) ;
struct V_114 * V_115 ;
struct V_137 * V_138 ;
V_115 = F_150 ( V_28 ) ;
if ( ! V_115 )
return V_11 ;
for ( V_138 = & V_115 -> V_115 [ 0 ] ; V_138 -> V_139 ; V_138 ++ ) {
struct V_5 * V_6 ;
if ( V_138 -> V_120 != V_120 )
continue;
if ( V_138 -> V_119 && ( ! V_119 || strcmp ( V_138 -> V_119 , V_119 ) ) )
continue;
V_6 = F_46 ( V_138 -> V_139 ) ;
if ( ! V_6 ) {
F_23 ( V_28 , L_32 ,
V_138 -> V_139 ) ;
return F_9 ( - V_140 ) ;
}
if ( V_6 -> V_10 <= V_138 -> V_141 ) {
F_23 ( V_28 ,
L_33 ,
V_120 , V_6 -> V_10 , V_6 -> V_3 ) ;
return F_9 ( - V_13 ) ;
}
V_11 = F_8 ( V_6 , V_138 -> V_141 ) ;
* V_7 = V_138 -> V_7 ;
return V_11 ;
}
return V_11 ;
}
static int F_153 ( struct V_118 * V_28 , const char * V_119 )
{
int V_74 ;
char V_132 [ 32 ] ;
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < F_145 ( V_125 ) ; V_105 ++ ) {
if ( V_119 )
snprintf ( V_132 , sizeof( V_132 ) , L_29 ,
V_119 , V_125 [ V_105 ] ) ;
else
snprintf ( V_132 , sizeof( V_132 ) , L_30 ,
V_125 [ V_105 ] ) ;
V_74 = F_154 ( V_28 -> V_64 , V_132 ) ;
if ( V_74 >= 0 )
break;
}
return V_74 ;
}
static int F_155 ( struct V_118 * V_28 , const char * V_119 )
{
struct V_114 * V_115 ;
struct V_137 * V_138 ;
unsigned int V_111 = 0 ;
V_115 = F_150 ( V_28 ) ;
if ( ! V_115 )
return - V_136 ;
for ( V_138 = & V_115 -> V_115 [ 0 ] ; V_138 -> V_139 ; V_138 ++ ) {
if ( ( V_119 && V_138 -> V_119 && ! strcmp ( V_119 , V_138 -> V_119 ) ) ||
( ! V_119 && ! V_138 -> V_119 ) )
V_111 ++ ;
}
if ( ! V_111 )
return - V_136 ;
return V_111 ;
}
int F_156 ( struct V_118 * V_28 , const char * V_119 )
{
int V_111 = - V_136 ;
if ( F_157 ( V_142 ) && V_28 && V_28 -> V_64 )
V_111 = F_153 ( V_28 , V_119 ) ;
else if ( F_157 ( V_143 ) && V_28 && F_158 ( V_28 ) )
V_111 = F_159 ( V_28 , V_119 ) ;
if ( V_111 < 0 )
V_111 = F_155 ( V_28 , V_119 ) ;
return V_111 ;
}
struct V_1 * T_4 F_160 ( struct V_118 * V_28 , const char * V_119 ,
enum V_144 V_7 )
{
return F_161 ( V_28 , V_119 , 0 , V_7 ) ;
}
struct V_1 * T_4 F_162 ( struct V_118 * V_28 ,
const char * V_119 ,
enum V_144 V_7 )
{
return F_163 ( V_28 , V_119 , 0 , V_7 ) ;
}
static int F_164 ( struct V_1 * V_11 , const char * V_119 ,
unsigned long V_145 , enum V_144 V_146 )
{
int V_18 ;
if ( V_145 & V_127 )
F_19 ( V_88 , & V_11 -> V_7 ) ;
if ( V_145 & V_147 )
F_19 ( V_89 , & V_11 -> V_7 ) ;
if ( V_145 & V_148 )
F_19 ( V_90 , & V_11 -> V_7 ) ;
if ( ! ( V_146 & V_149 ) ) {
F_14 ( L_34 , V_119 ) ;
return 0 ;
}
if ( V_146 & V_150 )
V_18 = F_113 ( V_11 ,
V_146 & V_151 ) ;
else
V_18 = F_106 ( V_11 ) ;
return V_18 ;
}
struct V_1 * T_4 F_165 ( struct V_118 * V_28 ,
const char * V_119 ,
unsigned int V_120 ,
enum V_144 V_7 )
{
struct V_1 * V_11 = NULL ;
int V_18 ;
enum V_121 V_152 = 0 ;
F_166 ( V_28 , L_35 , V_119 ) ;
if ( V_28 ) {
if ( F_157 ( V_142 ) && V_28 -> V_64 ) {
F_166 ( V_28 , L_36 ) ;
V_11 = F_144 ( V_28 , V_119 , V_120 , & V_152 ) ;
} else if ( F_148 ( V_28 ) ) {
F_166 ( V_28 , L_37 ) ;
V_11 = F_147 ( V_28 , V_119 , V_120 , & V_152 ) ;
}
}
if ( ! V_11 || V_11 == F_9 ( - V_136 ) ) {
F_166 ( V_28 , L_38 ) ;
V_11 = F_152 ( V_28 , V_119 , V_120 , & V_152 ) ;
}
if ( F_85 ( V_11 ) ) {
F_166 ( V_28 , L_39 , V_119 ) ;
return V_11 ;
}
V_18 = F_91 ( V_11 , V_119 ) ;
if ( V_18 < 0 )
return F_9 ( V_18 ) ;
V_18 = F_164 ( V_11 , V_119 , V_152 , V_7 ) ;
if ( V_18 < 0 ) {
F_166 ( V_28 , L_40 , V_119 ) ;
F_167 ( V_11 ) ;
return F_9 ( V_18 ) ;
}
return V_11 ;
}
struct V_1 * F_168 ( struct V_153 * V_154 ,
const char * V_132 )
{
struct V_1 * V_11 = F_9 ( - V_140 ) ;
bool V_133 = false ;
int V_74 ;
if ( ! V_154 )
return F_9 ( - V_13 ) ;
if ( F_169 ( V_154 ) ) {
enum V_123 V_7 ;
V_11 = F_146 ( V_64 ( V_154 ) , V_132 , 0 ,
& V_7 ) ;
if ( ! F_85 ( V_11 ) )
V_133 = V_7 & V_126 ;
} else if ( F_170 ( V_154 ) ) {
struct V_130 V_131 ;
V_11 = F_149 ( F_171 ( V_154 ) , V_132 , 0 ,
& V_131 ) ;
if ( ! F_85 ( V_11 ) )
V_133 = V_131 . V_133 ;
}
if ( F_85 ( V_11 ) )
return V_11 ;
V_74 = F_91 ( V_11 , NULL ) ;
if ( V_74 )
return F_9 ( V_74 ) ;
if ( V_133 )
F_19 ( V_88 , & V_11 -> V_7 ) ;
return V_11 ;
}
struct V_1 * T_4 F_172 ( struct V_118 * V_28 ,
const char * V_119 ,
unsigned int V_155 ,
enum V_144 V_7 )
{
struct V_1 * V_11 ;
V_11 = F_161 ( V_28 , V_119 , V_155 , V_7 ) ;
if ( F_85 ( V_11 ) ) {
if ( F_86 ( V_11 ) == - V_136 )
return NULL ;
}
return V_11 ;
}
int F_173 ( struct V_1 * V_11 , const char * V_40 ,
unsigned long V_145 , enum V_144 V_146 )
{
struct V_5 * V_6 ;
struct V_1 * V_156 ;
int V_12 ;
int V_18 ;
V_6 = F_11 ( V_11 ) ;
V_12 = F_17 ( V_11 ) ;
V_156 = F_104 ( V_6 , V_12 , V_40 ) ;
if ( F_85 ( V_156 ) ) {
F_14 ( L_41 , V_40 ) ;
return F_86 ( V_156 ) ;
}
V_18 = F_164 ( V_11 , V_40 , V_145 , V_146 ) ;
if ( V_18 < 0 ) {
F_14 ( L_40 , V_40 ) ;
F_105 ( V_11 ) ;
return V_18 ;
}
F_19 ( V_91 , & V_11 -> V_7 ) ;
F_174 ( L_42 ,
F_10 ( V_11 ) , V_40 ,
( V_146 & V_150 ) ? L_43 : L_44 ,
( V_146 & V_150 ) ?
( V_146 & V_151 ) ? L_45 : L_46 : L_47 ) ;
return 0 ;
}
static void F_33 ( struct V_5 * V_6 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ ) {
if ( F_41 ( V_91 , & V_6 -> V_11 [ V_30 ] . V_7 ) )
F_105 ( & V_6 -> V_11 [ V_30 ] ) ;
}
}
struct V_157 * T_4 F_175 ( struct V_118 * V_28 ,
const char * V_119 ,
enum V_144 V_7 )
{
struct V_1 * V_11 ;
struct V_157 * V_31 ;
int V_111 ;
V_111 = F_156 ( V_28 , V_119 ) ;
if ( V_111 < 0 )
return F_9 ( V_111 ) ;
V_31 = F_78 ( sizeof( * V_31 ) + sizeof( V_31 -> V_11 [ 0 ] ) * V_111 ,
V_32 ) ;
if ( ! V_31 )
return F_9 ( - V_33 ) ;
for ( V_31 -> V_158 = 0 ; V_31 -> V_158 < V_111 ; ) {
V_11 = F_161 ( V_28 , V_119 , V_31 -> V_158 , V_7 ) ;
if ( F_85 ( V_11 ) ) {
F_176 ( V_31 ) ;
return F_177 ( V_11 ) ;
}
V_31 -> V_11 [ V_31 -> V_158 ] = V_11 ;
V_31 -> V_158 ++ ;
}
return V_31 ;
}
struct V_157 * T_4 F_178 ( struct V_118 * V_28 ,
const char * V_119 ,
enum V_144 V_7 )
{
struct V_157 * V_31 ;
V_31 = F_175 ( V_28 , V_119 , V_7 ) ;
if ( F_85 ( V_31 ) && ( F_86 ( V_31 ) == - V_136 ) )
return NULL ;
return V_31 ;
}
void F_167 ( struct V_1 * V_11 )
{
F_100 ( V_11 ) ;
}
void F_176 ( struct V_157 * V_31 )
{
unsigned int V_105 ;
for ( V_105 = 0 ; V_105 < V_31 -> V_158 ; V_105 ++ )
F_167 ( V_31 -> V_11 [ V_105 ] ) ;
F_36 ( V_31 ) ;
}
static void F_179 ( struct V_159 * V_160 , struct V_5 * V_6 )
{
unsigned V_105 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_161 = & V_6 -> V_11 [ 0 ] ;
int V_162 ;
int V_163 ;
for ( V_105 = 0 ; V_105 < V_6 -> V_10 ; V_105 ++ , V_4 ++ , V_161 ++ ) {
if ( ! F_41 ( V_38 , & V_161 -> V_7 ) )
continue;
F_16 ( V_161 ) ;
V_162 = F_41 ( V_20 , & V_161 -> V_7 ) ;
V_163 = F_41 ( V_96 , & V_161 -> V_7 ) ;
F_180 ( V_160 , L_48 ,
V_4 , V_161 -> V_3 ,
V_162 ? L_49 : L_50 ,
V_6 -> V_93
? ( V_6 -> V_93 ( V_6 , V_105 ) ? L_51 : L_52 )
: L_53 ,
V_163 ? L_54 : L_55 ) ;
F_180 ( V_160 , L_56 ) ;
}
}
static void * F_181 ( struct V_159 * V_160 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_5 V_155 = * V_22 ;
V_160 -> V_164 = L_47 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( V_155 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_182 ( struct V_159 * V_160 , void * V_165 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_165 ;
void * V_74 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_183 ( & V_6 -> V_26 , & V_23 ) )
V_74 = NULL ;
else
V_74 = F_22 ( V_6 -> V_26 . V_166 , struct V_5 , V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
V_160 -> V_164 = L_56 ;
++ * V_22 ;
return V_74 ;
}
static void F_184 ( struct V_159 * V_160 , void * V_165 )
{
}
static int F_185 ( struct V_159 * V_160 , void * V_165 )
{
struct V_5 * V_6 = V_165 ;
struct V_118 * V_28 ;
F_180 ( V_160 , L_57 , ( char * ) V_160 -> V_164 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_28 = V_6 -> V_28 ;
if ( V_28 )
F_180 ( V_160 , L_58 , V_28 -> V_167 ? V_28 -> V_167 -> V_40 : L_59 ,
F_151 ( V_28 ) ) ;
if ( V_6 -> V_3 )
F_180 ( V_160 , L_60 , V_6 -> V_3 ) ;
if ( V_6 -> V_47 )
F_180 ( V_160 , L_61 ) ;
F_180 ( V_160 , L_62 ) ;
if ( V_6 -> V_168 )
V_6 -> V_168 ( V_160 , V_6 ) ;
else
F_179 ( V_160 , V_6 ) ;
return 0 ;
}
static int F_186 ( struct V_169 * V_169 , struct V_170 * V_170 )
{
return F_187 ( V_170 , & V_171 ) ;
}
static int T_6 F_188 ( void )
{
( void ) F_189 ( L_63 , V_172 | V_173 ,
NULL , NULL , & V_174 ) ;
return 0 ;
}
