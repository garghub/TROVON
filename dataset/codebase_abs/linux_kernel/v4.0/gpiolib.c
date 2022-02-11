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
F_3 ( & V_8 , V_7 ) ;
F_34 ( & V_6 -> V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
V_6 -> V_11 = NULL ;
V_34:
F_35 ( V_31 ) ;
F_15 ( L_7 , V_15 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ,
V_6 -> V_3 ? : L_6 ) ;
return V_18 ;
}
void F_36 ( struct V_5 * V_6 )
{
unsigned long V_7 ;
unsigned V_30 ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_32 ( V_6 ) ;
F_39 ( V_6 ) ;
F_33 ( V_6 ) ;
F_3 ( & V_8 , V_7 ) ;
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ ) {
if ( F_40 ( V_38 , & V_6 -> V_11 [ V_30 ] . V_7 ) )
F_41 ( V_6 -> V_28 , L_8 ) ;
}
for ( V_30 = 0 ; V_30 < V_6 -> V_10 ; V_30 ++ )
V_6 -> V_11 [ V_30 ] . V_6 = NULL ;
F_34 ( & V_6 -> V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
F_35 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
struct V_5 * F_42 ( void * V_39 ,
int (* F_43)( struct V_5 * V_6 ,
void * V_39 ) )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( F_43 ( V_6 , V_39 ) )
break;
if ( & V_6 -> V_26 == & V_23 )
V_6 = NULL ;
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
static int F_44 ( struct V_5 * V_6 , void * V_39 )
{
const char * V_40 = V_39 ;
return ! strcmp ( V_6 -> V_3 , V_40 ) ;
}
static struct V_5 * F_45 ( const char * V_40 )
{
return F_42 ( ( void * ) V_40 , F_44 ) ;
}
void F_46 ( struct V_5 * V_41 ,
struct V_42 * V_43 ,
int V_44 ,
T_2 V_45 )
{
unsigned int V_17 ;
if ( ! V_41 -> V_46 ) {
F_47 ( V_41 , L_9 ,
V_15 ) ;
return;
}
if ( V_45 ) {
if ( V_41 -> V_47 ) {
F_47 ( V_41 ,
L_10
L_11 ) ;
return;
}
F_48 ( V_44 , V_41 ) ;
F_49 ( V_44 , V_45 ) ;
}
for ( V_17 = 0 ; V_17 < V_41 -> V_10 ; V_17 ++ )
F_50 ( F_51 ( V_41 -> V_46 , V_17 ) ,
V_44 ) ;
}
static int F_52 ( struct V_48 * V_2 , unsigned int V_49 ,
T_3 V_50 )
{
struct V_5 * V_6 = V_2 -> V_51 ;
F_53 ( V_49 , V_6 ) ;
F_54 ( V_49 , & V_52 ) ;
F_55 ( V_49 , V_6 -> V_43 , V_6 -> V_53 ) ;
if ( V_6 -> V_47 && ! V_6 -> V_54 )
F_56 ( V_49 , 1 ) ;
#ifdef F_57
F_58 ( V_49 , V_55 ) ;
#else
F_59 ( V_49 ) ;
#endif
if ( V_6 -> V_56 != V_57 )
F_60 ( V_49 , V_6 -> V_56 ) ;
return 0 ;
}
static void F_61 ( struct V_48 * V_2 , unsigned int V_49 )
{
struct V_5 * V_6 = V_2 -> V_51 ;
#ifdef F_57
F_58 ( V_49 , 0 ) ;
#endif
if ( V_6 -> V_47 )
F_56 ( V_49 , 0 ) ;
F_55 ( V_49 , NULL , NULL ) ;
F_53 ( V_49 , NULL ) ;
}
static int F_62 ( struct V_58 * V_2 )
{
struct V_5 * V_6 = F_63 ( V_2 ) ;
if ( F_64 ( V_6 , V_2 -> V_50 ) ) {
F_47 ( V_6 ,
L_12 ,
V_2 -> V_50 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_65 ( struct V_58 * V_2 )
{
struct V_5 * V_6 = F_63 ( V_2 ) ;
F_66 ( V_6 , V_2 -> V_50 ) ;
}
static int F_67 ( struct V_5 * V_6 , unsigned V_17 )
{
return F_51 ( V_6 -> V_46 , V_17 ) ;
}
static void F_38 ( struct V_5 * V_41 )
{
unsigned int V_17 ;
F_68 ( V_41 ) ;
if ( V_41 -> V_46 ) {
for ( V_17 = 0 ; V_17 < V_41 -> V_10 ; V_17 ++ )
F_69 (
F_51 ( V_41 -> V_46 , V_17 ) ) ;
F_70 ( V_41 -> V_46 ) ;
}
if ( V_41 -> V_43 ) {
V_41 -> V_43 -> V_59 = NULL ;
V_41 -> V_43 -> V_60 = NULL ;
V_41 -> V_43 = NULL ;
}
}
int F_71 ( struct V_5 * V_41 ,
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
#ifdef F_72
if ( V_41 -> V_64 )
V_64 = V_41 -> V_64 ;
#endif
V_41 -> V_43 = V_43 ;
V_41 -> V_53 = V_62 ;
V_41 -> V_56 = type ;
V_41 -> V_66 = F_67 ;
V_41 -> V_46 = F_73 ( V_64 ,
V_41 -> V_10 , V_61 ,
& V_67 , V_41 ) ;
if ( ! V_41 -> V_46 ) {
V_41 -> V_43 = NULL ;
return - V_13 ;
}
V_43 -> V_59 = F_62 ;
V_43 -> V_60 = F_65 ;
for ( V_17 = 0 ; V_17 < V_41 -> V_10 ; V_17 ++ ) {
V_65 = F_74 ( V_41 -> V_46 , V_17 ) ;
if ( V_17 == 0 )
V_41 -> V_65 = V_65 ;
}
F_75 ( V_41 ) ;
return 0 ;
}
static void F_38 ( struct V_5 * V_41 ) {}
int F_76 ( struct V_5 * V_6 ,
struct V_68 * V_69 ,
unsigned int V_70 , const char * V_71 )
{
struct V_72 * V_73 ;
int V_74 ;
V_73 = F_77 ( sizeof( * V_73 ) , V_32 ) ;
if ( ! V_73 ) {
F_47 ( V_6 , L_14 ) ;
return - V_33 ;
}
V_73 -> V_75 . V_30 = V_70 ;
V_73 -> V_75 . V_76 = V_6 ;
V_73 -> V_75 . V_40 = V_6 -> V_3 ;
V_73 -> V_75 . V_9 = V_6 -> V_9 + V_70 ;
V_73 -> V_69 = V_69 ;
V_74 = F_78 ( V_69 , V_71 ,
& V_73 -> V_75 . V_77 ,
& V_73 -> V_75 . V_78 ) ;
if ( V_74 < 0 ) {
F_35 ( V_73 ) ;
return V_74 ;
}
F_79 ( V_69 , & V_73 -> V_75 ) ;
F_80 ( V_6 , L_15 ,
V_70 , V_70 + V_73 -> V_75 . V_78 - 1 ,
F_81 ( V_69 ) , V_71 ) ;
F_24 ( & V_73 -> V_79 , & V_6 -> V_36 ) ;
return 0 ;
}
int F_82 ( struct V_5 * V_6 , const char * V_80 ,
unsigned int V_70 , unsigned int V_81 ,
unsigned int V_78 )
{
struct V_72 * V_73 ;
int V_74 ;
V_73 = F_77 ( sizeof( * V_73 ) , V_32 ) ;
if ( ! V_73 ) {
F_47 ( V_6 , L_14 ) ;
return - V_33 ;
}
V_73 -> V_75 . V_30 = V_70 ;
V_73 -> V_75 . V_76 = V_6 ;
V_73 -> V_75 . V_40 = V_6 -> V_3 ;
V_73 -> V_75 . V_9 = V_6 -> V_9 + V_70 ;
V_73 -> V_75 . V_82 = V_81 ;
V_73 -> V_75 . V_78 = V_78 ;
V_73 -> V_69 = F_83 ( V_80 ,
& V_73 -> V_75 ) ;
if ( F_84 ( V_73 -> V_69 ) ) {
V_74 = F_85 ( V_73 -> V_69 ) ;
F_47 ( V_6 , L_16 ) ;
F_35 ( V_73 ) ;
return V_74 ;
}
F_80 ( V_6 , L_17 ,
V_70 , V_70 + V_78 - 1 ,
V_80 ,
V_81 , V_81 + V_78 - 1 ) ;
F_24 ( & V_73 -> V_79 , & V_6 -> V_36 ) ;
return 0 ;
}
void F_39 ( struct V_5 * V_6 )
{
struct V_72 * V_73 , * V_83 ;
F_86 (pin_range, tmp, &chip->pin_ranges, node) {
F_34 ( & V_73 -> V_79 ) ;
F_87 ( V_73 -> V_69 ,
& V_73 -> V_75 ) ;
F_35 ( V_73 ) ;
}
}
static int F_88 ( struct V_1 * V_11 , const char * V_3 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
int V_18 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
if ( F_89 ( V_38 , & V_11 -> V_7 ) == 0 ) {
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
int F_90 ( struct V_1 * V_11 , const char * V_3 )
{
int V_18 = - V_86 ;
struct V_5 * V_6 ;
if ( ! V_11 ) {
F_91 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 )
goto V_84;
if ( F_92 ( V_6 -> V_87 ) ) {
V_18 = F_88 ( V_11 , V_3 ) ;
if ( V_18 < 0 )
F_93 ( V_6 -> V_87 ) ;
}
V_84:
if ( V_18 )
F_94 ( V_11 , L_20 , V_15 , V_18 ) ;
return V_18 ;
}
static bool F_95 ( struct V_1 * V_11 )
{
bool V_74 = false ;
unsigned long V_7 ;
struct V_5 * V_6 ;
F_96 () ;
F_97 ( V_11 ) ;
F_3 ( & V_8 , V_7 ) ;
V_6 = V_11 -> V_6 ;
if ( V_6 && F_40 ( V_38 , & V_11 -> V_7 ) ) {
if ( V_6 -> free ) {
F_5 ( & V_8 , V_7 ) ;
F_98 ( V_6 -> V_47 ) ;
V_6 -> free ( V_6 , F_17 ( V_11 ) ) ;
F_3 ( & V_8 , V_7 ) ;
}
F_1 ( V_11 , NULL ) ;
F_18 ( V_88 , & V_11 -> V_7 ) ;
F_18 ( V_38 , & V_11 -> V_7 ) ;
F_18 ( V_89 , & V_11 -> V_7 ) ;
F_18 ( V_90 , & V_11 -> V_7 ) ;
V_74 = true ;
}
F_5 ( & V_8 , V_7 ) ;
return V_74 ;
}
void F_99 ( struct V_1 * V_11 )
{
if ( V_11 && F_95 ( V_11 ) )
F_93 ( V_11 -> V_6 -> V_87 ) ;
else
F_100 ( V_91 ) ;
}
const char * F_101 ( struct V_5 * V_6 , unsigned V_17 )
{
struct V_1 * V_11 ;
if ( ! F_102 ( V_6 , V_17 ) )
return NULL ;
V_11 = & V_6 -> V_11 [ V_17 ] ;
if ( F_40 ( V_38 , & V_11 -> V_7 ) == 0 )
return NULL ;
return V_11 -> V_3 ;
}
struct V_1 * F_103 ( struct V_5 * V_6 , T_1 V_12 ,
const char * V_3 )
{
struct V_1 * V_11 = F_8 ( V_6 , V_12 ) ;
int V_25 ;
if ( F_84 ( V_11 ) ) {
F_47 ( V_6 , L_21 ) ;
return V_11 ;
}
V_25 = F_88 ( V_11 , V_3 ) ;
if ( V_25 < 0 )
return F_9 ( V_25 ) ;
return V_11 ;
}
void F_104 ( struct V_1 * V_11 )
{
if ( V_11 )
F_95 ( V_11 ) ;
}
int F_105 ( struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_91 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_92 || ! V_6 -> V_35 ) {
F_106 ( V_11 ,
L_22 ,
V_15 ) ;
return - V_93 ;
}
V_18 = V_6 -> V_35 ( V_6 , F_17 ( V_11 ) ) ;
if ( V_18 == 0 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
F_107 ( F_10 ( V_11 ) , 1 , V_18 ) ;
return V_18 ;
}
static int F_108 ( struct V_1 * V_11 , int V_94 )
{
struct V_5 * V_6 ;
int V_18 = - V_13 ;
if ( F_40 ( V_95 , & V_11 -> V_7 ) ) {
F_109 ( V_11 ,
L_23 ,
V_15 ) ;
return - V_93 ;
}
if ( V_94 && F_40 ( V_89 , & V_11 -> V_7 ) )
return F_105 ( V_11 ) ;
if ( ! V_94 && F_40 ( V_90 , & V_11 -> V_7 ) )
return F_105 ( V_11 ) ;
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_96 || ! V_6 -> V_97 ) {
F_106 ( V_11 ,
L_24 ,
V_15 ) ;
return - V_93 ;
}
V_18 = V_6 -> V_97 ( V_6 , F_17 ( V_11 ) , V_94 ) ;
if ( V_18 == 0 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
F_110 ( F_10 ( V_11 ) , 0 , V_94 ) ;
F_107 ( F_10 ( V_11 ) , 0 , V_18 ) ;
return V_18 ;
}
int F_111 ( struct V_1 * V_11 , int V_94 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_91 ( L_19 , V_15 ) ;
return - V_13 ;
}
return F_108 ( V_11 , V_94 ) ;
}
int F_112 ( struct V_1 * V_11 , int V_94 )
{
if ( ! V_11 || ! V_11 -> V_6 ) {
F_91 ( L_19 , V_15 ) ;
return - V_13 ;
}
if ( F_40 ( V_88 , & V_11 -> V_7 ) )
V_94 = ! V_94 ;
return F_108 ( V_11 , V_94 ) ;
}
int F_113 ( struct V_1 * V_11 , unsigned V_98 )
{
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_6 ) {
F_91 ( L_19 , V_15 ) ;
return - V_13 ;
}
V_6 = V_11 -> V_6 ;
if ( ! V_6 -> V_96 || ! V_6 -> V_99 ) {
F_94 ( V_11 ,
L_25 ,
V_15 ) ;
return - V_100 ;
}
return V_6 -> V_99 ( V_6 , F_17 ( V_11 ) , V_98 ) ;
}
int F_114 ( const struct V_1 * V_11 )
{
return F_40 ( V_88 , & V_11 -> V_7 ) ;
}
static bool F_115 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
bool V_94 ;
int V_17 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
V_94 = V_6 -> V_92 ? V_6 -> V_92 ( V_6 , V_17 ) : false ;
F_110 ( F_10 ( V_11 ) , 1 , V_94 ) ;
return V_94 ;
}
int F_116 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
F_100 ( V_11 -> V_6 -> V_47 ) ;
return F_115 ( V_11 ) ;
}
int F_117 ( const struct V_1 * V_11 )
{
int V_94 ;
if ( ! V_11 )
return 0 ;
F_100 ( V_11 -> V_6 -> V_47 ) ;
V_94 = F_115 ( V_11 ) ;
if ( F_40 ( V_88 , & V_11 -> V_7 ) )
V_94 = ! V_94 ;
return V_94 ;
}
static void F_118 ( struct V_1 * V_11 , bool V_94 )
{
int V_25 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_94 ) {
V_25 = V_6 -> V_35 ( V_6 , V_17 ) ;
if ( ! V_25 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_25 = V_6 -> V_97 ( V_6 , V_17 , 0 ) ;
if ( ! V_25 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
}
F_107 ( F_10 ( V_11 ) , V_94 , V_25 ) ;
if ( V_25 < 0 )
F_109 ( V_11 ,
L_26 ,
V_15 , V_25 ) ;
}
static void F_119 ( struct V_1 * V_11 , bool V_94 )
{
int V_25 = 0 ;
struct V_5 * V_6 = V_11 -> V_6 ;
int V_17 = F_17 ( V_11 ) ;
if ( V_94 ) {
V_25 = V_6 -> V_97 ( V_6 , V_17 , 1 ) ;
if ( ! V_25 )
F_19 ( V_20 , & V_11 -> V_7 ) ;
} else {
V_25 = V_6 -> V_35 ( V_6 , V_17 ) ;
if ( ! V_25 )
F_18 ( V_20 , & V_11 -> V_7 ) ;
}
F_107 ( F_10 ( V_11 ) , ! V_94 , V_25 ) ;
if ( V_25 < 0 )
F_109 ( V_11 ,
L_27 ,
V_15 , V_25 ) ;
}
static void F_120 ( struct V_1 * V_11 , bool V_94 )
{
struct V_5 * V_6 ;
V_6 = V_11 -> V_6 ;
F_110 ( F_10 ( V_11 ) , 0 , V_94 ) ;
if ( F_40 ( V_89 , & V_11 -> V_7 ) )
F_118 ( V_11 , V_94 ) ;
else if ( F_40 ( V_90 , & V_11 -> V_7 ) )
F_119 ( V_11 , V_94 ) ;
else
V_6 -> V_96 ( V_6 , F_17 ( V_11 ) , V_94 ) ;
}
static void F_121 ( struct V_5 * V_6 ,
unsigned long * V_101 , unsigned long * V_102 )
{
if ( V_6 -> V_103 ) {
V_6 -> V_103 ( V_6 , V_101 , V_102 ) ;
} else {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_6 -> V_10 ; V_104 ++ ) {
if ( V_101 [ F_122 ( V_104 ) ] == 0 ) {
V_104 = ( F_122 ( V_104 ) + 1 ) * V_105 - 1 ;
continue;
}
if ( F_123 ( V_104 , V_101 ) ) {
V_6 -> V_96 ( V_6 , V_104 , F_40 ( V_104 , V_102 ) ) ;
}
}
}
}
static void F_124 ( bool V_106 , bool V_47 ,
unsigned int V_107 ,
struct V_1 * * V_108 ,
int * V_109 )
{
int V_104 = 0 ;
while ( V_104 < V_107 ) {
struct V_5 * V_6 = V_108 [ V_104 ] -> V_6 ;
unsigned long V_101 [ F_125 ( V_6 -> V_10 ) ] ;
unsigned long V_102 [ F_125 ( V_6 -> V_10 ) ] ;
int V_110 = 0 ;
if ( ! V_47 ) {
F_100 ( V_6 -> V_47 ) ;
}
memset ( V_101 , 0 , sizeof( V_101 ) ) ;
do {
struct V_1 * V_11 = V_108 [ V_104 ] ;
int V_111 = F_17 ( V_11 ) ;
int V_94 = V_109 [ V_104 ] ;
if ( ! V_106 && F_40 ( V_88 , & V_11 -> V_7 ) )
V_94 = ! V_94 ;
F_110 ( F_10 ( V_11 ) , 0 , V_94 ) ;
if ( F_40 ( V_89 , & V_11 -> V_7 ) ) {
F_118 ( V_11 , V_94 ) ;
} else if ( F_40 ( V_90 , & V_11 -> V_7 ) ) {
F_119 ( V_11 , V_94 ) ;
} else {
F_126 ( V_111 , V_101 ) ;
if ( V_94 ) {
F_126 ( V_111 , V_102 ) ;
} else {
F_127 ( V_111 , V_102 ) ;
}
V_110 ++ ;
}
V_104 ++ ;
} while ( ( V_104 < V_107 ) && ( V_108 [ V_104 ] -> V_6 == V_6 ) );
if ( V_110 != 0 ) {
F_121 ( V_6 , V_101 , V_102 ) ;
}
}
}
void F_128 ( struct V_1 * V_11 , int V_94 )
{
if ( ! V_11 )
return;
F_100 ( V_11 -> V_6 -> V_47 ) ;
F_120 ( V_11 , V_94 ) ;
}
void F_129 ( struct V_1 * V_11 , int V_94 )
{
if ( ! V_11 )
return;
F_100 ( V_11 -> V_6 -> V_47 ) ;
if ( F_40 ( V_88 , & V_11 -> V_7 ) )
V_94 = ! V_94 ;
F_120 ( V_11 , V_94 ) ;
}
void F_130 ( unsigned int V_107 ,
struct V_1 * * V_108 , int * V_109 )
{
if ( ! V_108 )
return;
F_124 ( true , false , V_107 , V_108 , V_109 ) ;
}
void F_131 ( unsigned int V_107 ,
struct V_1 * * V_108 , int * V_109 )
{
if ( ! V_108 )
return;
F_124 ( false , false , V_107 , V_108 , V_109 ) ;
}
int F_132 ( const struct V_1 * V_11 )
{
if ( ! V_11 )
return 0 ;
return V_11 -> V_6 -> V_47 ;
}
int F_133 ( const struct V_1 * V_11 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( ! V_11 )
return - V_13 ;
V_6 = V_11 -> V_6 ;
V_17 = F_17 ( V_11 ) ;
return V_6 -> V_66 ? V_6 -> V_66 ( V_6 , V_17 ) : - V_112 ;
}
int F_64 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return - V_13 ;
if ( F_40 ( V_20 , & V_6 -> V_11 [ V_17 ] . V_7 ) ) {
F_47 ( V_6 ,
L_28 ,
V_15 ) ;
return - V_93 ;
}
F_19 ( V_95 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
return 0 ;
}
void F_66 ( struct V_5 * V_6 , unsigned int V_17 )
{
if ( V_17 >= V_6 -> V_10 )
return;
F_18 ( V_95 , & V_6 -> V_11 [ V_17 ] . V_7 ) ;
}
int F_134 ( const struct V_1 * V_11 )
{
F_98 ( V_91 ) ;
if ( ! V_11 )
return 0 ;
return F_115 ( V_11 ) ;
}
int F_135 ( const struct V_1 * V_11 )
{
int V_94 ;
F_98 ( V_91 ) ;
if ( ! V_11 )
return 0 ;
V_94 = F_115 ( V_11 ) ;
if ( F_40 ( V_88 , & V_11 -> V_7 ) )
V_94 = ! V_94 ;
return V_94 ;
}
void F_136 ( struct V_1 * V_11 , int V_94 )
{
F_98 ( V_91 ) ;
if ( ! V_11 )
return;
F_120 ( V_11 , V_94 ) ;
}
void F_137 ( struct V_1 * V_11 , int V_94 )
{
F_98 ( V_91 ) ;
if ( ! V_11 )
return;
if ( F_40 ( V_88 , & V_11 -> V_7 ) )
V_94 = ! V_94 ;
F_120 ( V_11 , V_94 ) ;
}
void F_138 ( unsigned int V_107 ,
struct V_1 * * V_108 ,
int * V_109 )
{
F_98 ( V_91 ) ;
if ( ! V_108 )
return;
F_124 ( true , true , V_107 , V_108 , V_109 ) ;
}
void F_139 ( unsigned int V_107 ,
struct V_1 * * V_108 ,
int * V_109 )
{
F_98 ( V_91 ) ;
if ( ! V_108 )
return;
F_124 ( false , true , V_107 , V_108 , V_109 ) ;
}
void F_140 ( struct V_113 * V_114 )
{
F_141 ( & V_115 ) ;
F_24 ( & V_114 -> V_26 , & V_116 ) ;
F_142 ( & V_115 ) ;
}
static struct V_1 * F_143 ( struct V_117 * V_28 , const char * V_118 ,
unsigned int V_119 ,
enum V_120 * V_7 )
{
static const char * const V_121 [] = { L_29 , L_30 } ;
char V_122 [ 32 ] ;
enum V_123 V_124 ;
struct V_1 * V_11 ;
unsigned int V_104 ;
for ( V_104 = 0 ; V_104 < F_144 ( V_121 ) ; V_104 ++ ) {
if ( V_118 )
snprintf ( V_122 , sizeof( V_122 ) , L_31 , V_118 ,
V_121 [ V_104 ] ) ;
else
snprintf ( V_122 , sizeof( V_122 ) , L_32 ,
V_121 [ V_104 ] ) ;
V_11 = F_145 ( V_28 -> V_64 , V_122 , V_119 ,
& V_124 ) ;
if ( ! F_84 ( V_11 ) || ( F_85 ( V_11 ) == - V_86 ) )
break;
}
if ( F_84 ( V_11 ) )
return V_11 ;
if ( V_124 & V_125 )
* V_7 |= V_126 ;
return V_11 ;
}
static struct V_1 * F_146 ( struct V_117 * V_28 , const char * V_118 ,
unsigned int V_119 ,
enum V_120 * V_7 )
{
static const char * const V_121 [] = { L_29 , L_30 } ;
struct V_127 * V_128 = F_147 ( V_28 ) ;
struct V_129 V_130 ;
struct V_1 * V_11 ;
char V_131 [ 32 ] ;
int V_104 ;
for ( V_104 = 0 ; V_104 < F_144 ( V_121 ) ; V_104 ++ ) {
if ( V_118 && strcmp ( V_118 , L_29 ) ) {
snprintf ( V_131 , sizeof( V_131 ) , L_31 ,
V_118 , V_121 [ V_104 ] ) ;
} else {
snprintf ( V_131 , sizeof( V_131 ) , L_32 ,
V_121 [ V_104 ] ) ;
}
V_11 = F_148 ( V_128 , V_131 , V_119 , & V_130 ) ;
if ( ! F_84 ( V_11 ) || ( F_85 ( V_11 ) == - V_86 ) )
break;
}
if ( F_84 ( V_11 ) ) {
V_11 = F_148 ( V_128 , NULL , V_119 , & V_130 ) ;
if ( F_84 ( V_11 ) )
return V_11 ;
}
if ( V_130 . V_132 )
* V_7 |= V_126 ;
return V_11 ;
}
static struct V_113 * F_149 ( struct V_117 * V_28 )
{
const char * V_133 = V_28 ? F_150 ( V_28 ) : NULL ;
struct V_113 * V_114 ;
F_141 ( & V_115 ) ;
F_4 (table, &gpio_lookup_list, list) {
if ( V_114 -> V_133 && V_133 ) {
if ( ! strcmp ( V_114 -> V_133 , V_133 ) )
goto V_134;
} else {
if ( V_133 == V_114 -> V_133 )
goto V_134;
}
}
V_114 = NULL ;
V_134:
F_142 ( & V_115 ) ;
return V_114 ;
}
static struct V_1 * F_151 ( struct V_117 * V_28 , const char * V_118 ,
unsigned int V_119 ,
enum V_120 * V_7 )
{
struct V_1 * V_11 = F_9 ( - V_135 ) ;
struct V_113 * V_114 ;
struct V_136 * V_137 ;
V_114 = F_149 ( V_28 ) ;
if ( ! V_114 )
return V_11 ;
for ( V_137 = & V_114 -> V_114 [ 0 ] ; V_137 -> V_138 ; V_137 ++ ) {
struct V_5 * V_6 ;
if ( V_137 -> V_119 != V_119 )
continue;
if ( V_137 -> V_118 && ( ! V_118 || strcmp ( V_137 -> V_118 , V_118 ) ) )
continue;
V_6 = F_45 ( V_137 -> V_138 ) ;
if ( ! V_6 ) {
F_23 ( V_28 , L_33 ,
V_137 -> V_138 ) ;
return F_9 ( - V_139 ) ;
}
if ( V_6 -> V_10 <= V_137 -> V_140 ) {
F_23 ( V_28 ,
L_34 ,
V_119 , V_6 -> V_10 , V_6 -> V_3 ) ;
return F_9 ( - V_13 ) ;
}
V_11 = F_8 ( V_6 , V_137 -> V_140 ) ;
* V_7 = V_137 -> V_7 ;
return V_11 ;
}
return V_11 ;
}
struct V_1 * T_4 F_152 ( struct V_117 * V_28 , const char * V_118 ,
enum V_141 V_7 )
{
return F_153 ( V_28 , V_118 , 0 , V_7 ) ;
}
struct V_1 * T_4 F_154 ( struct V_117 * V_28 ,
const char * V_118 ,
enum V_141 V_7 )
{
return F_155 ( V_28 , V_118 , 0 , V_7 ) ;
}
struct V_1 * T_4 F_156 ( struct V_117 * V_28 ,
const char * V_118 ,
unsigned int V_119 ,
enum V_141 V_7 )
{
struct V_1 * V_11 = NULL ;
int V_18 ;
enum V_120 V_142 = 0 ;
F_157 ( V_28 , L_35 , V_118 ) ;
if ( F_158 ( V_143 ) && V_28 && V_28 -> V_64 ) {
F_157 ( V_28 , L_36 ) ;
V_11 = F_143 ( V_28 , V_118 , V_119 , & V_142 ) ;
} else if ( F_158 ( V_144 ) && V_28 && F_159 ( V_28 ) ) {
F_157 ( V_28 , L_37 ) ;
V_11 = F_146 ( V_28 , V_118 , V_119 , & V_142 ) ;
}
if ( ! V_11 || V_11 == F_9 ( - V_135 ) ) {
F_157 ( V_28 , L_38 ) ;
V_11 = F_151 ( V_28 , V_118 , V_119 , & V_142 ) ;
}
if ( F_84 ( V_11 ) ) {
F_157 ( V_28 , L_39 , V_118 ) ;
return V_11 ;
}
V_18 = F_90 ( V_11 , V_118 ) ;
if ( V_18 < 0 )
return F_9 ( V_18 ) ;
if ( V_142 & V_126 )
F_19 ( V_88 , & V_11 -> V_7 ) ;
if ( V_142 & V_145 )
F_19 ( V_89 , & V_11 -> V_7 ) ;
if ( V_142 & V_146 )
F_19 ( V_90 , & V_11 -> V_7 ) ;
if ( ! ( V_7 & V_147 ) )
return V_11 ;
if ( V_7 & V_148 )
V_18 = F_112 ( V_11 ,
V_7 & V_149 ) ;
else
V_18 = F_105 ( V_11 ) ;
if ( V_18 < 0 ) {
F_157 ( V_28 , L_40 , V_118 ) ;
F_160 ( V_11 ) ;
return F_9 ( V_18 ) ;
}
return V_11 ;
}
struct V_1 * F_161 ( struct V_150 * V_151 ,
const char * V_131 )
{
struct V_1 * V_11 = F_9 ( - V_139 ) ;
bool V_132 = false ;
int V_74 ;
if ( ! V_151 )
return F_9 ( - V_13 ) ;
if ( F_162 ( V_151 ) ) {
enum V_123 V_7 ;
V_11 = F_145 ( V_64 ( V_151 ) , V_131 , 0 ,
& V_7 ) ;
if ( ! F_84 ( V_11 ) )
V_132 = V_7 & V_125 ;
} else if ( F_163 ( V_151 ) ) {
struct V_129 V_130 ;
V_11 = F_148 ( F_164 ( V_151 ) , V_131 , 0 ,
& V_130 ) ;
if ( ! F_84 ( V_11 ) )
V_132 = V_130 . V_132 ;
}
if ( F_84 ( V_11 ) )
return V_11 ;
V_74 = F_90 ( V_11 , NULL ) ;
if ( V_74 )
return F_9 ( V_74 ) ;
if ( V_132 )
F_19 ( V_88 , & V_11 -> V_7 ) ;
return V_11 ;
}
struct V_1 * T_4 F_165 ( struct V_117 * V_28 ,
const char * V_118 ,
unsigned int V_152 ,
enum V_141 V_7 )
{
struct V_1 * V_11 ;
V_11 = F_153 ( V_28 , V_118 , V_152 , V_7 ) ;
if ( F_84 ( V_11 ) ) {
if ( F_85 ( V_11 ) == - V_135 )
return NULL ;
}
return V_11 ;
}
void F_160 ( struct V_1 * V_11 )
{
F_99 ( V_11 ) ;
}
static void F_166 ( struct V_153 * V_154 , struct V_5 * V_6 )
{
unsigned V_104 ;
unsigned V_4 = V_6 -> V_9 ;
struct V_1 * V_155 = & V_6 -> V_11 [ 0 ] ;
int V_156 ;
int V_157 ;
for ( V_104 = 0 ; V_104 < V_6 -> V_10 ; V_104 ++ , V_4 ++ , V_155 ++ ) {
if ( ! F_40 ( V_38 , & V_155 -> V_7 ) )
continue;
F_16 ( V_155 ) ;
V_156 = F_40 ( V_20 , & V_155 -> V_7 ) ;
V_157 = F_40 ( V_95 , & V_155 -> V_7 ) ;
F_167 ( V_154 , L_41 ,
V_4 , V_155 -> V_3 ,
V_156 ? L_42 : L_43 ,
V_6 -> V_92
? ( V_6 -> V_92 ( V_6 , V_104 ) ? L_44 : L_45 )
: L_46 ,
V_157 ? L_47 : L_48 ) ;
F_167 ( V_154 , L_49 ) ;
}
}
static void * F_168 ( struct V_153 * V_154 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = NULL ;
T_5 V_152 = * V_22 ;
V_154 -> V_158 = L_50 ;
F_3 ( & V_8 , V_7 ) ;
F_4 (chip, &gpio_chips, list)
if ( V_152 -- == 0 ) {
F_5 ( & V_8 , V_7 ) ;
return V_6 ;
}
F_5 ( & V_8 , V_7 ) ;
return NULL ;
}
static void * F_169 ( struct V_153 * V_154 , void * V_159 , T_5 * V_22 )
{
unsigned long V_7 ;
struct V_5 * V_6 = V_159 ;
void * V_74 = NULL ;
F_3 ( & V_8 , V_7 ) ;
if ( F_170 ( & V_6 -> V_26 , & V_23 ) )
V_74 = NULL ;
else
V_74 = F_22 ( V_6 -> V_26 . V_160 , struct V_5 , V_26 ) ;
F_5 ( & V_8 , V_7 ) ;
V_154 -> V_158 = L_49 ;
++ * V_22 ;
return V_74 ;
}
static void F_171 ( struct V_153 * V_154 , void * V_159 )
{
}
static int F_172 ( struct V_153 * V_154 , void * V_159 )
{
struct V_5 * V_6 = V_159 ;
struct V_117 * V_28 ;
F_167 ( V_154 , L_51 , ( char * ) V_154 -> V_158 ,
V_6 -> V_9 , V_6 -> V_9 + V_6 -> V_10 - 1 ) ;
V_28 = V_6 -> V_28 ;
if ( V_28 )
F_167 ( V_154 , L_52 , V_28 -> V_161 ? V_28 -> V_161 -> V_40 : L_53 ,
F_150 ( V_28 ) ) ;
if ( V_6 -> V_3 )
F_167 ( V_154 , L_54 , V_6 -> V_3 ) ;
if ( V_6 -> V_47 )
F_167 ( V_154 , L_55 ) ;
F_167 ( V_154 , L_56 ) ;
if ( V_6 -> V_162 )
V_6 -> V_162 ( V_154 , V_6 ) ;
else
F_166 ( V_154 , V_6 ) ;
return 0 ;
}
static int F_173 ( struct V_163 * V_163 , struct V_164 * V_164 )
{
return F_174 ( V_164 , & V_165 ) ;
}
static int T_6 F_175 ( void )
{
( void ) F_176 ( L_30 , V_166 | V_167 ,
NULL , NULL , & V_168 ) ;
return 0 ;
}
