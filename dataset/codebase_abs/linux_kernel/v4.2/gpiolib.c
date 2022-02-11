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
struct V_1 * V_11 ;
unsigned long V_7 ;
unsigned V_30 ;
bool V_38 = false ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_32 ( V_6 ) ;
F_40 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
F_3 ( & V_8 , V_7 ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ ) {
V_11 = & V_6 -> V_11 [ V_30 ] ;
V_11 -> V_6 = NULL ;
if ( F_41 ( V_39 , & V_11 -> V_7 ) )
V_38 = true ;
}
F_35 ( & V_6 -> V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
if ( V_38 )
F_42 ( V_6 -> V_28 , L_8 ) ;
F_36 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
struct V_5 * F_43 ( void * V_40 ,
int (* F_44)( struct V_5 * V_6 ,
void * V_40 ) )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( F_44 ( V_6 , V_40 ) )
break;
if ( & V_6 -> V_26 == & V_23 )
V_6 = NULL ;
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
static int F_45 ( struct V_5 * V_6 , void * V_40 )
{
const char * V_41 = V_40 ;
return ! strcmp ( V_6 -> V_3 , V_41 ) ;
}
static struct V_5 * F_46 ( const char * V_41 )
{
return F_43 ( ( void * ) V_41 , F_45 ) ;
}
void F_47 ( struct V_5 * V_42 ,
struct V_43 * V_44 ,
int V_45 ,
T_2 V_46 )
{
unsigned int V_17 ;
if ( ! V_42 -> V_47 ) {
F_48 ( V_42 , L_9 ,
V_15 ) ;
return;
}
if ( V_46 ) {
if ( V_42 -> V_48 ) {
F_48 ( V_42 ,
L_10
L_11 ) ;
return;
}
F_49 ( V_45 , V_42 ) ;
F_50 ( V_45 , V_46 ) ;
V_42 -> V_49 = V_45 ;
}
for ( V_17 = 0 ; V_17 < V_42 -> V_10 ; V_17 ++ )
F_51 ( F_52 ( V_42 -> V_47 , V_17 ) ,
V_45 ) ;
}
static int F_53 ( struct V_50 * V_2 , unsigned int V_51 ,
T_3 V_52 )
{
struct V_5 * V_6 = V_2 -> V_53 ;
F_54 ( V_51 , V_6 ) ;
F_55 ( V_51 , & V_54 ) ;
F_56 ( V_51 , V_6 -> V_44 , V_6 -> V_55 ) ;
if ( V_6 -> V_48 && ! V_6 -> V_56 )
F_57 ( V_51 , 1 ) ;
#ifdef F_58
F_59 ( V_51 , V_57 ) ;
#else
F_60 ( V_51 ) ;
#endif
if ( V_6 -> V_58 != V_59 )
F_61 ( V_51 , V_6 -> V_58 ) ;
return 0 ;
}
static void F_62 ( struct V_50 * V_2 , unsigned int V_51 )
{
struct V_5 * V_6 = V_2 -> V_53 ;
#ifdef F_58
F_59 ( V_51 , 0 ) ;
#endif
if ( V_6 -> V_48 )
F_57 ( V_51 , 0 ) ;
F_56 ( V_51 , NULL , NULL ) ;
F_54 ( V_51 , NULL ) ;
}
static int F_63 ( struct V_60 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
if ( F_65 ( V_6 , V_2 -> V_52 ) ) {
F_48 ( V_6 ,
L_12 ,
V_2 -> V_52 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_66 ( struct V_60 * V_2 )
{
struct V_5 * V_6 = F_64 ( V_2 ) ;
F_67 ( V_6 , V_2 -> V_52 ) ;
}
static int F_68 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_52 ( V_6 -> V_47 , V_17 ) ;
}
static void F_39 ( struct V_5 * V_42 )
{
unsigned int V_17 ;
F_69 ( V_42 ) ;
if ( V_42 -> V_49 ) {
F_50 ( V_42 -> V_49 , NULL ) ;
F_49 ( V_42 -> V_49 , NULL ) ;
}
if ( V_42 -> V_47 ) {
for ( V_17 = 0 ; V_17 < V_42 -> V_10 ; V_17 ++ )
F_70 (
F_52 ( V_42 -> V_47 , V_17 ) ) ;
F_71 ( V_42 -> V_47 ) ;
}
if ( V_42 -> V_44 ) {
V_42 -> V_44 -> V_61 = NULL ;
V_42 -> V_44 -> V_62 = NULL ;
V_42 -> V_44 = NULL ;
}
}
int F_72 ( struct V_5 * V_42 ,
struct V_43 * V_44 ,
unsigned int V_63 ,
T_2 V_64 ,
unsigned int type )
{
struct V_65 * V_66 ;
unsigned int V_17 ;
unsigned V_67 = 0 ;
if ( ! V_42 || ! V_44 )
return - V_13 ;
if ( ! V_42 -> V_28 ) {
F_15 ( L_13 ) ;
return - V_13 ;
}
V_66 = V_42 -> V_28 -> V_66 ;
#ifdef F_73
if ( V_42 -> V_66 )
V_66 = V_42 -> V_66 ;
#endif
V_42 -> V_44 = V_44 ;
V_42 -> V_55 = V_64 ;
V_42 -> V_58 = type ;
V_42 -> V_68 = F_68 ;
V_42 -> V_47 = F_74 ( V_66 ,
V_42 -> V_10 , V_63 ,
& V_69 , V_42 ) ;
if ( ! V_42 -> V_47 ) {
V_42 -> V_44 = NULL ;
return - V_13 ;
}
V_44 -> V_61 = F_63 ;
V_44 -> V_62 = F_66 ;
for ( V_17 = 0 ; V_17 < V_42 -> V_10 ; V_17 ++ ) {
V_67 = F_75 ( V_42 -> V_47 , V_17 ) ;
if ( V_17 == 0 )
V_42 -> V_67 = V_67 ;
}
F_76 ( V_42 ) ;
return 0 ;
}
static void F_39 ( struct V_5 * V_42 ) {}
int F_77 ( struct V_5 * V_6 ,
struct V_70 * V_71 ,
unsigned int V_72 , const char * V_73 )
{
struct V_74 * V_75 ;
int V_76 ;
V_75 = F_78 ( sizeof( * V_75 ) , V_32 ) ;
if ( ! V_75 ) {
F_48 ( V_6 , L_14 ) ;
return - V_33 ;
}
V_75 -> V_77 . V_30 = V_72 ;
V_75 -> V_77 . V_78 = V_6 ;
V_75 -> V_77 . V_41 = V_6 -> V_3 ;
V_75 -> V_77 . V_9 = V_6 -> V_9 + V_72 ;
V_75 -> V_71 = V_71 ;
V_76 = F_79 ( V_71 , V_73 ,
& V_75 -> V_77 . V_79 ,
& V_75 -> V_77 . V_80 ) ;
if ( V_76 < 0 ) {
F_36 ( V_75 ) ;
return V_76 ;
}
F_80 ( V_71 , & V_75 -> V_77 ) ;
F_81 ( V_6 , L_15 ,
V_72 , V_72 + V_75 -> V_77 . V_80 - 1 ,
F_82 ( V_71 ) , V_73 ) ;
F_24 ( & V_75 -> V_81 , & V_6 -> V_36 ) ;
return 0 ;
}
int F_83 ( struct V_5 * V_6 , const char * V_82 ,
unsigned int V_72 , unsigned int V_83 ,
unsigned int V_80 )
{
struct V_74 * V_75 ;
int V_76 ;
V_75 = F_78 ( sizeof( * V_75 ) , V_32 ) ;
if ( ! V_75 ) {
F_48 ( V_6 , L_14 ) ;
return - V_33 ;
}
V_75 -> V_77 . V_30 = V_72 ;
V_75 -> V_77 . V_78 = V_6 ;
V_75 -> V_77 . V_41 = V_6 -> V_3 ;
V_75 -> V_77 . V_9 = V_6 -> V_9 + V_72 ;
V_75 -> V_77 . V_84 = V_83 ;
V_75 -> V_77 . V_80 = V_80 ;
V_75 -> V_71 = F_84 ( V_82 ,
& V_75 -> V_77 ) ;
if ( F_85 ( V_75 -> V_71 ) ) {
V_76 = F_86 ( V_75 -> V_71 ) ;
F_48 ( V_6 , L_16 ) ;
F_36 ( V_75 ) ;
return V_76 ;
}
F_81 ( V_6 , L_17 ,
V_72 , V_72 + V_80 - 1 ,
V_82 ,
V_83 , V_83 + V_80 - 1 ) ;
F_24 ( & V_75 -> V_81 , & V_6 -> V_36 ) ;
return 0 ;
}
void F_40 ( struct V_5 * V_6 )
{
struct V_74 * V_75 , * V_85 ;
F_87 (pin_range, tmp, &chip->pin_ranges, node) {
F_35 ( & V_75 -> V_81 ) ;
F_88 ( V_75 -> V_71 ,
& V_75 -> V_77 ) ;
F_36 ( V_75 ) ;
}
}
static int F_89 ( struct V_1 * V_11 , const char * V_3 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
int V_18 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_90 ( V_39 , & V_11 -> V_7 ) == 0 ) {
F_1 ( V_11 , V_3 ? : L_18 ) ;
V_18 = 0 ;
} else {
V_18 = - V_29 ;
goto V_86;
}
if ( V_6 -> V_87 ) {
F_5 ( & V_8 , V_7 ) ;
V_18 = V_6 -> V_87 ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
if ( V_18 < 0 ) {
F_1 ( V_11 , NULL ) ;
F_18 ( V_39 , & V_11 -> V_7 ) ;
goto V_86;
}
}
if ( V_6 -> V_19 ) {
F_5 ( & V_8 , V_7 ) ;
F_16 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
}
V_86:
F_5 ( & V_8 , V_7 ) ;
return V_18 ;
}
int F_91 ( struct V_1 * V_11 , const char * V_3 )
{
int V_18 = - V_88 ;
struct V_5 * V_6 ;
if ( ! V_11 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 )
goto V_86;
if ( F_93 ( V_6 -> V_89 ) ) {
V_18 = F_89 ( V_11 , V_3 ) ;
if ( V_18 < 0 )
F_94 ( V_6 -> V_89 ) ;
}
V_86:
if ( V_18 )
F_95 ( V_11 , L_20 , V_15 , V_18 ) ;
return V_18 ;
}
static bool F_96 ( struct V_1 * V_11 )
{
bool V_76 = false ;
unsigned long V_7 ;
struct V_5 * V_6 ;
F_97 () ;
F_98 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
V_6 = V_11 -> V_6 ;
if ( V_6 && F_41 ( V_39 , & V_11 -> V_7 ) ) {
if ( V_6 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_99 ( V_6 -> V_48 ) ;
V_6 -> free ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_11 , NULL ) ;
F_18 ( V_90 , & V_11 -> V_7 ) ;
F_18 ( V_39 , & V_11 -> V_7 ) ;
F_18 ( V_91 , & V_11 -> V_7 ) ;
F_18 ( V_92 , & V_11 -> V_7 ) ;
F_18 ( V_93 , & V_11 -> V_7 ) ;
V_76 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_76 ;
}
void F_100 ( struct V_1 * V_11 )
{
if ( V_11 && F_96 ( V_11 ) )
F_94 ( V_11 -> V_6 -> V_89 ) ;
else
F_101 ( V_94 ) ;
}
const char * F_102 ( struct V_5 * V_6 , unsigned V_17 )
{
struct V_1 * V_11 ;
if ( ! F_103 ( V_6 , V_17 ) )
return NULL ;
V_11 = & V_6 -> V_11 [ V_17 ] ;
if ( F_41 ( V_39 , & V_11 -> V_7 ) == 0 )
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
if ( ! V_6 -> V_95 || ! V_6 -> V_35 ) {
F_107 ( V_11 ,
L_22 ,
V_15 ) ;
return - V_96 ;
}
V_18 = V_6 -> V_35 ( V_6 , F_17 ( V_11 ) ) ;
if ( V_18 == 0 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
F_108 ( F_10 ( V_11 ) , 1 , V_18 ) ;
return V_18 ;
}
static int F_109 ( struct V_1 * V_11 , int V_97 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( F_41 ( V_98 , & V_11 -> V_7 ) ) {
F_110 ( V_11 ,
L_23 ,
V_15 ) ;
return - V_96 ;
}
if ( V_97 && F_41 ( V_91 , & V_11 -> V_7 ) )
return F_106 ( V_11 ) ;
if ( ! V_97 && F_41 ( V_92 , & V_11 -> V_7 ) )
return F_106 ( V_11 ) ;
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_99 || ! V_6 -> V_100 ) {
F_107 ( V_11 ,
L_24 ,
V_15 ) ;
return - V_96 ;
}
V_18 = V_6 -> V_100 ( V_6 , F_17 ( V_11 ) , V_97 ) ;
if ( V_18 == 0 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
F_111 ( F_10 ( V_11 ) , 0 , V_97 ) ;
F_108 ( F_10 ( V_11 ) , 0 , V_18 ) ;
return V_18 ;
}
int F_112 ( struct V_1 * V_11 , int V_97 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
return F_109 ( V_11 , V_97 ) ;
}
int F_113 ( struct V_1 * V_11 , int V_97 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
if ( F_41 ( V_90 , & V_11 -> V_7 ) )
V_97 = ! V_97 ;
return F_109 ( V_11 , V_97 ) ;
}
int F_114 ( struct V_1 * V_11 , unsigned V_101 )
{
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_92 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_99 || ! V_6 -> V_102 ) {
F_95 ( V_11 ,
L_25 ,
V_15 ) ;
return - V_103 ;
}
return V_6 -> V_102 ( V_6 , F_17 ( V_11 ) , V_101 ) ;
}
int F_115 ( const struct V_1 * V_11 )
{
return F_41 ( V_90 , & V_11 -> V_7 ) ;
}
static bool F_116 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
bool V_97 ;
int V_17 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
V_97 = V_6 -> V_95 ? V_6 -> V_95 ( V_6 , V_17 ) : false ;
F_111 ( F_10 ( V_11 ) , 1 , V_97 ) ;
return V_97 ;
}
int F_117 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
F_101 ( V_11 -> V_6 -> V_48 ) ;
return F_116 ( V_11 ) ;
}
int F_118 ( const struct V_1 * V_11 )
{
int V_97 ;
if ( ! V_11 )
return 0 ;
F_101 ( V_11 -> V_6 -> V_48 ) ;
V_97 = F_116 ( V_11 ) ;
if ( F_41 ( V_90 , & V_11 -> V_7 ) )
V_97 = ! V_97 ;
return V_97 ;
}
static void F_119 ( struct V_1 * V_11 , bool V_97 )
{
int V_25 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_97 ) {
V_25 = V_6 -> V_35 ( V_6 , V_17 ) ;
if ( ! V_25 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_25 = V_6 -> V_100 ( V_6 , V_17 , 0 ) ;
if ( ! V_25 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
}
F_108 ( F_10 ( V_11 ) , V_97 , V_25 ) ;
if ( V_25 < 0 )
F_110 ( V_11 ,
L_26 ,
V_15 , V_25 ) ;
}
static void F_120 ( struct V_1 * V_11 , bool V_97 )
{
int V_25 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_97 ) {
V_25 = V_6 -> V_100 ( V_6 , V_17 , 1 ) ;
if ( ! V_25 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_25 = V_6 -> V_35 ( V_6 , V_17 ) ;
if ( ! V_25 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
}
F_108 ( F_10 ( V_11 ) , ! V_97 , V_25 ) ;
if ( V_25 < 0 )
F_110 ( V_11 ,
L_27 ,
V_15 , V_25 ) ;
}
static void F_121 ( struct V_1 * V_11 , bool V_97 )
{
struct V_5 * V_6 ;
V_6 = V_11 -> V_6 ;
F_111 ( F_10 ( V_11 ) , 0 , V_97 ) ;
if ( F_41 ( V_91 , & V_11 -> V_7 ) )
F_119 ( V_11 , V_97 ) ;
else if ( F_41 ( V_92 , & V_11 -> V_7 ) )
F_120 ( V_11 , V_97 ) ;
else
V_6 -> V_99 ( V_6 , F_17 ( V_11 ) , V_97 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
unsigned long * V_104 , unsigned long * V_105 )
{
if ( V_6 -> V_106 ) {
V_6 -> V_106 ( V_6 , V_104 , V_105 ) ;
} else {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_6 -> V_10 ; V_107 ++ ) {
if ( V_104 [ F_123 ( V_107 ) ] == 0 ) {
V_107 = ( F_123 ( V_107 ) + 1 ) * V_108 - 1 ;
continue;
}
if ( F_124 ( V_107 , V_104 ) )
V_6 -> V_99 ( V_6 , V_107 , F_41 ( V_107 , V_105 ) ) ;
}
}
}
static void F_125 ( bool V_109 , bool V_48 ,
unsigned int V_110 ,
struct V_1 * * V_111 ,
int * V_112 )
{
int V_107 = 0 ;
while ( V_107 < V_110 ) {
struct V_5 * V_6 = V_111 [ V_107 ] -> V_6 ;
unsigned long V_104 [ F_126 ( V_6 -> V_10 ) ] ;
unsigned long V_105 [ F_126 ( V_6 -> V_10 ) ] ;
int V_113 = 0 ;
if ( ! V_48 )
F_101 ( V_6 -> V_48 ) ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
do {
struct V_1 * V_11 = V_111 [ V_107 ] ;
int V_114 = F_17 ( V_11 ) ;
int V_97 = V_112 [ V_107 ] ;
if ( ! V_109 && F_41 ( V_90 , & V_11 -> V_7 ) )
V_97 = ! V_97 ;
F_111 ( F_10 ( V_11 ) , 0 , V_97 ) ;
if ( F_41 ( V_91 , & V_11 -> V_7 ) ) {
F_119 ( V_11 , V_97 ) ;
} else if ( F_41 ( V_92 , & V_11 -> V_7 ) ) {
F_120 ( V_11 , V_97 ) ;
} else {
F_127 ( V_114 , V_104 ) ;
if ( V_97 )
F_127 ( V_114 , V_105 ) ;
else
F_128 ( V_114 , V_105 ) ;
V_113 ++ ;
}
V_107 ++ ;
} while ( ( V_107 < V_110 ) && ( V_111 [ V_107 ] -> V_6 == V_6 ) );
if ( V_113 != 0 )
F_122 ( V_6 , V_104 , V_105 ) ;
}
}
void F_129 ( struct V_1 * V_11 , int V_97 )
{
if ( ! V_11 )
return;
F_101 ( V_11 -> V_6 -> V_48 ) ;
F_121 ( V_11 , V_97 ) ;
}
void F_130 ( struct V_1 * V_11 , int V_97 )
{
if ( ! V_11 )
return;
F_101 ( V_11 -> V_6 -> V_48 ) ;
if ( F_41 ( V_90 , & V_11 -> V_7 ) )
V_97 = ! V_97 ;
F_121 ( V_11 , V_97 ) ;
}
void F_131 ( unsigned int V_110 ,
struct V_1 * * V_111 , int * V_112 )
{
if ( ! V_111 )
return;
F_125 ( true , false , V_110 , V_111 ,
V_112 ) ;
}
void F_132 ( unsigned int V_110 ,
struct V_1 * * V_111 , int * V_112 )
{
if ( ! V_111 )
return;
F_125 ( false , false , V_110 , V_111 ,
V_112 ) ;
}
int F_133 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
return V_11 -> V_6 -> V_48 ;
}
int F_134 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( ! V_11 )
return - V_13 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
return V_6 -> V_68 ? V_6 -> V_68 ( V_6 , V_17 ) : - V_115 ;
}
int F_65 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return - V_13 ;
if ( F_41 ( V_20 , & V_6 -> V_11 [ V_17 ] . V_7 ) ) {
F_48 ( V_6 ,
L_28 ,
V_15 ) ;
return - V_96 ;
}
F_19 ( V_98 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
return 0 ;
}
void F_67 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return;
F_18 ( V_98 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
}
int F_135 ( const struct V_1 * V_11 )
{
F_99 ( V_94 ) ;
if ( ! V_11 )
return 0 ;
return F_116 ( V_11 ) ;
}
int F_136 ( const struct V_1 * V_11 )
{
int V_97 ;
F_99 ( V_94 ) ;
if ( ! V_11 )
return 0 ;
V_97 = F_116 ( V_11 ) ;
if ( F_41 ( V_90 , & V_11 -> V_7 ) )
V_97 = ! V_97 ;
return V_97 ;
}
void F_137 ( struct V_1 * V_11 , int V_97 )
{
F_99 ( V_94 ) ;
if ( ! V_11 )
return;
F_121 ( V_11 , V_97 ) ;
}
void F_138 ( struct V_1 * V_11 , int V_97 )
{
F_99 ( V_94 ) ;
if ( ! V_11 )
return;
if ( F_41 ( V_90 , & V_11 -> V_7 ) )
V_97 = ! V_97 ;
F_121 ( V_11 , V_97 ) ;
}
void F_139 ( unsigned int V_110 ,
struct V_1 * * V_111 ,
int * V_112 )
{
F_99 ( V_94 ) ;
if ( ! V_111 )
return;
F_125 ( true , true , V_110 , V_111 ,
V_112 ) ;
}
void F_140 ( unsigned int V_110 ,
struct V_1 * * V_111 ,
int * V_112 )
{
F_99 ( V_94 ) ;
if ( ! V_111 )
return;
F_125 ( false , true , V_110 , V_111 ,
V_112 ) ;
}
void F_141 ( struct V_116 * V_117 )
{
F_142 ( & V_118 ) ;
F_24 ( & V_117 -> V_26 , & V_119 ) ;
F_143 ( & V_118 ) ;
}
static struct V_1 * F_144 ( struct V_120 * V_28 , const char * V_121 ,
unsigned int V_122 ,
enum V_123 * V_7 )
{
char V_124 [ 32 ] ;
enum V_125 V_126 ;
struct V_1 * V_11 ;
unsigned int V_107 ;
for ( V_107 = 0 ; V_107 < F_145 ( V_127 ) ; V_107 ++ ) {
if ( V_121 )
snprintf ( V_124 , sizeof( V_124 ) , L_29 , V_121 ,
V_127 [ V_107 ] ) ;
else
snprintf ( V_124 , sizeof( V_124 ) , L_30 ,
V_127 [ V_107 ] ) ;
V_11 = F_146 ( V_28 -> V_66 , V_124 , V_122 ,
& V_126 ) ;
if ( ! F_85 ( V_11 ) || ( F_86 ( V_11 ) == - V_88 ) )
break;
}
if ( F_85 ( V_11 ) )
return V_11 ;
if ( V_126 & V_128 )
* V_7 |= V_129 ;
return V_11 ;
}
static struct V_1 * F_147 ( struct V_120 * V_28 , const char * V_121 ,
unsigned int V_122 ,
enum V_123 * V_7 )
{
struct V_130 * V_131 = F_148 ( V_28 ) ;
struct V_132 V_133 ;
struct V_1 * V_11 ;
char V_134 [ 32 ] ;
int V_107 ;
for ( V_107 = 0 ; V_107 < F_145 ( V_127 ) ; V_107 ++ ) {
if ( V_121 && strcmp ( V_121 , L_31 ) ) {
snprintf ( V_134 , sizeof( V_134 ) , L_29 ,
V_121 , V_127 [ V_107 ] ) ;
} else {
snprintf ( V_134 , sizeof( V_134 ) , L_30 ,
V_127 [ V_107 ] ) ;
}
V_11 = F_149 ( V_131 , V_134 , V_122 , & V_133 ) ;
if ( ! F_85 ( V_11 ) || ( F_86 ( V_11 ) == - V_88 ) )
break;
}
if ( F_85 ( V_11 ) ) {
V_11 = F_149 ( V_131 , NULL , V_122 , & V_133 ) ;
if ( F_85 ( V_11 ) )
return V_11 ;
}
if ( V_133 . V_135 )
* V_7 |= V_129 ;
return V_11 ;
}
static struct V_116 * F_150 ( struct V_120 * V_28 )
{
const char * V_136 = V_28 ? F_151 ( V_28 ) : NULL ;
struct V_116 * V_117 ;
F_142 ( & V_118 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_117 -> V_136 && V_136 ) {
if ( ! strcmp ( V_117 -> V_136 , V_136 ) )
goto V_137;
} else {
if ( V_136 == V_117 -> V_136 )
goto V_137;
}
}
V_117 = NULL ;
V_137:
F_143 ( & V_118 ) ;
return V_117 ;
}
static struct V_1 * F_152 ( struct V_120 * V_28 , const char * V_121 ,
unsigned int V_122 ,
enum V_123 * V_7 )
{
struct V_1 * V_11 = F_9 ( - V_138 ) ;
struct V_116 * V_117 ;
struct V_139 * V_140 ;
V_117 = F_150 ( V_28 ) ;
if ( ! V_117 )
return V_11 ;
for ( V_140 = & V_117 -> V_117 [ 0 ] ; V_140 -> V_141 ; V_140 ++ ) {
struct V_5 * V_6 ;
if ( V_140 -> V_122 != V_122 )
continue;
if ( V_140 -> V_121 && ( ! V_121 || strcmp ( V_140 -> V_121 , V_121 ) ) )
continue;
V_6 = F_46 ( V_140 -> V_141 ) ;
if ( ! V_6 ) {
F_23 ( V_28 , L_32 ,
V_140 -> V_141 ) ;
return F_9 ( - V_142 ) ;
}
if ( V_6 -> V_10 <= V_140 -> V_143 ) {
F_23 ( V_28 ,
L_33 ,
V_122 , V_6 -> V_10 , V_6 -> V_3 ) ;
return F_9 ( - V_13 ) ;
}
V_11 = F_8 ( V_6 , V_140 -> V_143 ) ;
* V_7 = V_140 -> V_7 ;
return V_11 ;
}
return V_11 ;
}
static int F_153 ( struct V_120 * V_28 , const char * V_121 )
{
int V_76 ;
char V_134 [ 32 ] ;
unsigned int V_107 ;
for ( V_107 = 0 ; V_107 < F_145 ( V_127 ) ; V_107 ++ ) {
if ( V_121 )
snprintf ( V_134 , sizeof( V_134 ) , L_29 ,
V_121 , V_127 [ V_107 ] ) ;
else
snprintf ( V_134 , sizeof( V_134 ) , L_30 ,
V_127 [ V_107 ] ) ;
V_76 = F_154 ( V_28 -> V_66 , V_134 ) ;
if ( V_76 >= 0 )
break;
}
return V_76 ;
}
static int F_155 ( struct V_120 * V_28 , const char * V_121 )
{
struct V_116 * V_117 ;
struct V_139 * V_140 ;
unsigned int V_113 = 0 ;
V_117 = F_150 ( V_28 ) ;
if ( ! V_117 )
return - V_138 ;
for ( V_140 = & V_117 -> V_117 [ 0 ] ; V_140 -> V_141 ; V_140 ++ ) {
if ( ( V_121 && V_140 -> V_121 && ! strcmp ( V_121 , V_140 -> V_121 ) ) ||
( ! V_121 && ! V_140 -> V_121 ) )
V_113 ++ ;
}
if ( ! V_113 )
return - V_138 ;
return V_113 ;
}
int F_156 ( struct V_120 * V_28 , const char * V_121 )
{
int V_113 = - V_138 ;
if ( F_157 ( V_144 ) && V_28 && V_28 -> V_66 )
V_113 = F_153 ( V_28 , V_121 ) ;
else if ( F_157 ( V_145 ) && V_28 && F_158 ( V_28 ) )
V_113 = F_159 ( V_28 , V_121 ) ;
if ( V_113 < 0 )
V_113 = F_155 ( V_28 , V_121 ) ;
return V_113 ;
}
struct V_1 * T_4 F_160 ( struct V_120 * V_28 , const char * V_121 ,
enum V_146 V_7 )
{
return F_161 ( V_28 , V_121 , 0 , V_7 ) ;
}
struct V_1 * T_4 F_162 ( struct V_120 * V_28 ,
const char * V_121 ,
enum V_146 V_7 )
{
return F_163 ( V_28 , V_121 , 0 , V_7 ) ;
}
static int F_164 ( struct V_1 * V_11 , const char * V_121 ,
unsigned long V_147 , enum V_146 V_148 )
{
int V_18 ;
if ( V_147 & V_129 )
F_19 ( V_90 , & V_11 -> V_7 ) ;
if ( V_147 & V_149 )
F_19 ( V_91 , & V_11 -> V_7 ) ;
if ( V_147 & V_150 )
F_19 ( V_92 , & V_11 -> V_7 ) ;
if ( ! ( V_148 & V_151 ) ) {
F_14 ( L_34 , V_121 ) ;
return 0 ;
}
if ( V_148 & V_152 )
V_18 = F_113 ( V_11 ,
V_148 & V_153 ) ;
else
V_18 = F_106 ( V_11 ) ;
return V_18 ;
}
struct V_1 * T_4 F_165 ( struct V_120 * V_28 ,
const char * V_121 ,
unsigned int V_122 ,
enum V_146 V_7 )
{
struct V_1 * V_11 = NULL ;
int V_18 ;
enum V_123 V_154 = 0 ;
F_166 ( V_28 , L_35 , V_121 ) ;
if ( V_28 ) {
if ( F_157 ( V_144 ) && V_28 -> V_66 ) {
F_166 ( V_28 , L_36 ) ;
V_11 = F_144 ( V_28 , V_121 , V_122 , & V_154 ) ;
} else if ( F_148 ( V_28 ) ) {
F_166 ( V_28 , L_37 ) ;
V_11 = F_147 ( V_28 , V_121 , V_122 , & V_154 ) ;
}
}
if ( ! V_11 || V_11 == F_9 ( - V_138 ) ) {
F_166 ( V_28 , L_38 ) ;
V_11 = F_152 ( V_28 , V_121 , V_122 , & V_154 ) ;
}
if ( F_85 ( V_11 ) ) {
F_166 ( V_28 , L_39 , V_121 ) ;
return V_11 ;
}
V_18 = F_91 ( V_11 , V_121 ) ;
if ( V_18 < 0 )
return F_9 ( V_18 ) ;
V_18 = F_164 ( V_11 , V_121 , V_154 , V_7 ) ;
if ( V_18 < 0 ) {
F_166 ( V_28 , L_40 , V_121 ) ;
F_167 ( V_11 ) ;
return F_9 ( V_18 ) ;
}
return V_11 ;
}
struct V_1 * F_168 ( struct V_155 * V_156 ,
const char * V_134 )
{
struct V_1 * V_11 = F_9 ( - V_142 ) ;
bool V_135 = false ;
int V_76 ;
if ( ! V_156 )
return F_9 ( - V_13 ) ;
if ( F_169 ( V_156 ) ) {
enum V_125 V_7 ;
V_11 = F_146 ( F_170 ( V_156 ) , V_134 , 0 ,
& V_7 ) ;
if ( ! F_85 ( V_11 ) )
V_135 = V_7 & V_128 ;
} else if ( F_171 ( V_156 ) ) {
struct V_132 V_133 ;
V_11 = F_149 ( F_172 ( V_156 ) , V_134 , 0 ,
& V_133 ) ;
if ( ! F_85 ( V_11 ) )
V_135 = V_133 . V_135 ;
}
if ( F_85 ( V_11 ) )
return V_11 ;
V_76 = F_91 ( V_11 , NULL ) ;
if ( V_76 )
return F_9 ( V_76 ) ;
if ( V_135 )
F_19 ( V_90 , & V_11 -> V_7 ) ;
return V_11 ;
}
struct V_1 * T_4 F_173 ( struct V_120 * V_28 ,
const char * V_121 ,
unsigned int V_157 ,
enum V_146 V_7 )
{
struct V_1 * V_11 ;
V_11 = F_161 ( V_28 , V_121 , V_157 , V_7 ) ;
if ( F_85 ( V_11 ) ) {
if ( F_86 ( V_11 ) == - V_138 )
return NULL ;
}
return V_11 ;
}
int F_174 ( struct V_1 * V_11 , const char * V_41 ,
unsigned long V_147 , enum V_146 V_148 )
{
struct V_5 * V_6 ;
struct V_1 * V_158 ;
int V_12 ;
int V_18 ;
V_6 = F_11 ( V_11 ) ;
V_12 = F_17 ( V_11 ) ;
V_158 = F_104 ( V_6 , V_12 , V_41 ) ;
if ( F_85 ( V_158 ) ) {
F_15 ( L_41 ,
V_41 , V_6 -> V_3 , V_12 ) ;
return F_86 ( V_158 ) ;
}
V_18 = F_164 ( V_11 , V_41 , V_147 , V_148 ) ;
if ( V_18 < 0 ) {
F_15 ( L_42 ,
V_41 , V_6 -> V_3 , V_12 ) ;
F_105 ( V_11 ) ;
return V_18 ;
}
F_19 ( V_93 , & V_11 -> V_7 ) ;
F_175 ( L_43 ,
F_10 ( V_11 ) , V_41 ,
( V_148 & V_152 ) ? L_44 : L_45 ,
( V_148 & V_152 ) ?
( V_148 & V_153 ) ? L_46 : L_47 : L_48 ) ;
return 0 ;
}
static void F_33 ( struct V_5 * V_6 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ ) {
if ( F_41 ( V_93 , & V_6 -> V_11 [ V_30 ] . V_7 ) )
F_105 ( & V_6 -> V_11 [ V_30 ] ) ;
}
}
struct V_159 * T_4 F_176 ( struct V_120 * V_28 ,
const char * V_121 ,
enum V_146 V_7 )
{
struct V_1 * V_11 ;
struct V_159 * V_31 ;
int V_113 ;
V_113 = F_156 ( V_28 , V_121 ) ;
if ( V_113 < 0 )
return F_9 ( V_113 ) ;
V_31 = F_78 ( sizeof( * V_31 ) + sizeof( V_31 -> V_11 [ 0 ] ) * V_113 ,
V_32 ) ;
if ( ! V_31 )
return F_9 ( - V_33 ) ;
for ( V_31 -> V_160 = 0 ; V_31 -> V_160 < V_113 ; ) {
V_11 = F_161 ( V_28 , V_121 , V_31 -> V_160 , V_7 ) ;
if ( F_85 ( V_11 ) ) {
F_177 ( V_31 ) ;
return F_178 ( V_11 ) ;
}
V_31 -> V_11 [ V_31 -> V_160 ] = V_11 ;
V_31 -> V_160 ++ ;
}
return V_31 ;
}
struct V_159 * T_4 F_179 ( struct V_120 * V_28 ,
const char * V_121 ,
enum V_146 V_7 )
{
struct V_159 * V_31 ;
V_31 = F_176 ( V_28 , V_121 , V_7 ) ;
if ( F_85 ( V_31 ) && ( F_86 ( V_31 ) == - V_138 ) )
return NULL ;
return V_31 ;
}
void F_167 ( struct V_1 * V_11 )
{
F_100 ( V_11 ) ;
}
void F_177 ( struct V_159 * V_31 )
{
unsigned int V_107 ;
for ( V_107 = 0 ; V_107 < V_31 -> V_160 ; V_107 ++ )
F_167 ( V_31 -> V_11 [ V_107 ] ) ;
F_36 ( V_31 ) ;
}
static void F_180 ( struct V_161 * V_162 , struct V_5 * V_6 )
{
unsigned V_107 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_163 = & V_6 -> V_11 [ 0 ] ;
int V_164 ;
int V_165 ;
for ( V_107 = 0 ; V_107 < V_6 -> V_10 ; V_107 ++ , V_4 ++ , V_163 ++ ) {
if ( ! F_41 ( V_39 , & V_163 -> V_7 ) )
continue;
F_16 ( V_163 ) ;
V_164 = F_41 ( V_20 , & V_163 -> V_7 ) ;
V_165 = F_41 ( V_98 , & V_163 -> V_7 ) ;
F_181 ( V_162 , L_49 ,
V_4 , V_163 -> V_3 ,
V_164 ? L_50 : L_51 ,
V_6 -> V_95
? ( V_6 -> V_95 ( V_6 , V_107 ) ? L_52 : L_53 )
: L_54 ,
V_165 ? L_55 : L_56 ) ;
F_181 ( V_162 , L_57 ) ;
}
}
static void * F_182 ( struct V_161 * V_162 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_5 V_157 = * V_22 ;
V_162 -> V_166 = L_48 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( V_157 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_183 ( struct V_161 * V_162 , void * V_167 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_167 ;
void * V_76 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_184 ( & V_6 -> V_26 , & V_23 ) )
V_76 = NULL ;
else
V_76 = F_22 ( V_6 -> V_26 . V_168 , struct V_5 , V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
V_162 -> V_166 = L_57 ;
++ * V_22 ;
return V_76 ;
}
static void F_185 ( struct V_161 * V_162 , void * V_167 )
{
}
static int F_186 ( struct V_161 * V_162 , void * V_167 )
{
struct V_5 * V_6 = V_167 ;
struct V_120 * V_28 ;
F_181 ( V_162 , L_58 , ( char * ) V_162 -> V_166 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_28 = V_6 -> V_28 ;
if ( V_28 )
F_181 ( V_162 , L_59 , V_28 -> V_169 ? V_28 -> V_169 -> V_41 : L_60 ,
F_151 ( V_28 ) ) ;
if ( V_6 -> V_3 )
F_181 ( V_162 , L_61 , V_6 -> V_3 ) ;
if ( V_6 -> V_48 )
F_181 ( V_162 , L_62 ) ;
F_181 ( V_162 , L_63 ) ;
if ( V_6 -> V_170 )
V_6 -> V_170 ( V_162 , V_6 ) ;
else
F_180 ( V_162 , V_6 ) ;
return 0 ;
}
static int F_187 ( struct V_171 * V_171 , struct V_172 * V_172 )
{
return F_188 ( V_172 , & V_173 ) ;
}
static int T_6 F_189 ( void )
{
( void ) F_190 ( L_64 , V_174 | V_175 ,
NULL , NULL , & V_176 ) ;
return 0 ;
}
