static inline void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
V_2 -> V_3 = V_3 ;
}
struct V_1 * F_2 ( unsigned V_4 )
{
if ( F_3 ( ! F_4 ( V_4 ) , L_1 , V_4 ) )
return NULL ;
else
return & V_1 [ V_4 ] ;
}
struct V_1 * F_5 ( struct V_5 * V_6 ,
T_1 V_7 )
{
if ( V_7 >= V_6 -> V_8 )
return F_6 ( - V_9 ) ;
return & V_6 -> V_10 [ V_7 ] ;
}
int F_7 ( const struct V_1 * V_10 )
{
return V_10 - & V_1 [ 0 ] ;
}
struct V_5 * F_8 ( const struct V_1 * V_10 )
{
return V_10 ? V_10 -> V_6 : NULL ;
}
static int F_9 ( int V_8 )
{
struct V_5 * V_6 ;
int V_11 = V_12 - V_8 ;
F_10 (chip, &gpio_chips, list) {
if ( V_6 -> V_11 + V_6 -> V_8 <= V_11 )
break;
else
V_11 = V_6 -> V_11 - V_8 ;
}
if ( F_4 ( V_11 ) ) {
F_11 ( L_2 , V_13 , V_11 ) ;
return V_11 ;
} else {
F_12 ( L_3 , V_13 ) ;
return - V_14 ;
}
}
int F_13 ( const struct V_1 * V_10 )
{
struct V_5 * V_6 ;
unsigned V_15 ;
int V_16 = - V_9 ;
V_6 = F_8 ( V_10 ) ;
V_15 = F_14 ( V_10 ) ;
if ( ! V_6 -> V_17 )
return V_16 ;
V_16 = V_6 -> V_17 ( V_6 , V_15 ) ;
if ( V_16 > 0 ) {
V_16 = 1 ;
F_15 ( V_18 , & ( (struct V_1 * ) V_10 ) -> V_19 ) ;
}
if ( V_16 == 0 ) {
F_16 ( V_18 , & ( (struct V_1 * ) V_10 ) -> V_19 ) ;
}
return V_16 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = & V_22 ;
struct V_5 * V_23 ;
int V_24 = 0 ;
F_18 (pos, &gpio_chips) {
V_23 = F_19 ( V_21 , struct V_5 , V_25 ) ;
if ( V_23 -> V_11 >= V_6 -> V_11 + V_6 -> V_8 )
break;
}
if ( V_21 != & V_22 && V_21 -> V_26 != & V_22 ) {
V_23 = F_19 ( V_21 -> V_26 , struct V_5 , V_25 ) ;
if ( V_23 -> V_11 + V_23 -> V_8 > V_6 -> V_11 ) {
F_20 ( V_6 -> V_27 ,
L_4 ) ;
V_24 = - V_28 ;
}
}
if ( ! V_24 )
F_21 ( & V_6 -> V_25 , V_21 ) ;
return V_24 ;
}
int F_22 ( struct V_5 * V_6 )
{
unsigned long V_19 ;
int V_16 = 0 ;
unsigned V_29 ;
int V_11 = V_6 -> V_11 ;
if ( ( ! F_4 ( V_11 ) || ! F_4 ( V_11 + V_6 -> V_8 - 1 ) )
&& V_11 >= 0 ) {
V_16 = - V_9 ;
goto V_30;
}
F_23 ( & V_31 , V_19 ) ;
if ( V_11 < 0 ) {
V_11 = F_9 ( V_6 -> V_8 ) ;
if ( V_11 < 0 ) {
V_16 = V_11 ;
goto V_32;
}
V_6 -> V_11 = V_11 ;
}
V_16 = F_17 ( V_6 ) ;
if ( V_16 == 0 ) {
V_6 -> V_10 = & V_1 [ V_6 -> V_11 ] ;
for ( V_29 = 0 ; V_29 < V_6 -> V_8 ; V_29 ++ ) {
struct V_1 * V_10 = & V_6 -> V_10 [ V_29 ] ;
V_10 -> V_6 = V_6 ;
V_10 -> V_19 = ! V_6 -> V_33
? ( 1 << V_18 )
: 0 ;
}
}
F_24 ( & V_31 , V_19 ) ;
#ifdef F_25
F_26 ( & V_6 -> V_34 ) ;
#endif
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
if ( V_16 )
goto V_30;
V_16 = F_29 ( V_6 ) ;
if ( V_16 )
goto V_30;
F_11 ( L_5 , V_13 ,
V_6 -> V_11 , V_6 -> V_11 + V_6 -> V_8 - 1 ,
V_6 -> V_3 ? : L_6 ) ;
return 0 ;
V_32:
F_24 ( & V_31 , V_19 ) ;
V_30:
F_12 ( L_7 , V_13 ,
V_6 -> V_11 , V_6 -> V_11 + V_6 -> V_8 - 1 ,
V_6 -> V_3 ? : L_6 ) ;
return V_16 ;
}
int F_30 ( struct V_5 * V_6 )
{
unsigned long V_19 ;
int V_16 = 0 ;
unsigned V_29 ;
F_31 ( V_6 ) ;
F_23 ( & V_31 , V_19 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_8 ; V_29 ++ ) {
if ( F_35 ( V_35 , & V_6 -> V_10 [ V_29 ] . V_19 ) ) {
V_16 = - V_28 ;
break;
}
}
if ( V_16 == 0 ) {
for ( V_29 = 0 ; V_29 < V_6 -> V_8 ; V_29 ++ )
V_6 -> V_10 [ V_29 ] . V_6 = NULL ;
F_36 ( & V_6 -> V_25 ) ;
}
F_24 ( & V_31 , V_19 ) ;
if ( V_16 == 0 )
F_37 ( V_6 ) ;
return V_16 ;
}
struct V_5 * F_38 ( void * V_36 ,
int (* F_39)( struct V_5 * V_6 ,
void * V_36 ) )
{
struct V_5 * V_6 ;
unsigned long V_19 ;
F_23 ( & V_31 , V_19 ) ;
F_40 (chip, &gpio_chips, list)
if ( F_39 ( V_6 , V_36 ) )
break;
if ( & V_6 -> V_25 == & V_22 )
V_6 = NULL ;
F_24 ( & V_31 , V_19 ) ;
return V_6 ;
}
static int F_41 ( struct V_5 * V_6 , void * V_36 )
{
const char * V_37 = V_36 ;
return ! strcmp ( V_6 -> V_3 , V_37 ) ;
}
static struct V_5 * F_42 ( const char * V_37 )
{
return F_38 ( ( void * ) V_37 , F_41 ) ;
}
void F_43 ( struct V_5 * V_38 ,
struct V_39 * V_40 ,
int V_41 ,
T_2 V_42 )
{
if ( V_38 -> V_43 ) {
F_44 ( V_38 , L_8 ) ;
return;
}
F_45 ( V_41 , V_38 ) ;
F_46 ( V_41 , V_42 ) ;
}
static int F_47 ( struct V_44 * V_2 , unsigned int V_45 ,
T_3 V_46 )
{
struct V_5 * V_6 = V_2 -> V_47 ;
F_48 ( V_45 , V_6 ) ;
F_49 ( V_45 , & V_48 ) ;
F_50 ( V_45 , V_6 -> V_40 , V_6 -> V_49 ) ;
if ( V_6 -> V_43 )
F_51 ( V_45 , 1 ) ;
#ifdef F_52
F_53 ( V_45 , V_50 ) ;
#else
F_54 ( V_45 ) ;
#endif
if ( V_6 -> V_51 != V_52 )
F_55 ( V_45 , V_6 -> V_51 ) ;
return 0 ;
}
static void F_56 ( struct V_44 * V_2 , unsigned int V_45 )
{
struct V_5 * V_6 = V_2 -> V_47 ;
#ifdef F_52
F_53 ( V_45 , 0 ) ;
#endif
if ( V_6 -> V_43 )
F_51 ( V_45 , 0 ) ;
F_50 ( V_45 , NULL , NULL ) ;
F_48 ( V_45 , NULL ) ;
}
static int F_57 ( struct V_53 * V_2 )
{
struct V_5 * V_6 = F_58 ( V_2 ) ;
if ( F_59 ( V_6 , V_2 -> V_46 ) ) {
F_44 ( V_6 ,
L_9 ,
V_2 -> V_46 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_60 ( struct V_53 * V_2 )
{
struct V_5 * V_6 = F_58 ( V_2 ) ;
F_61 ( V_6 , V_2 -> V_46 ) ;
}
static int F_62 ( struct V_5 * V_6 , unsigned V_15 )
{
return F_63 ( V_6 -> V_54 , V_15 ) ;
}
static void F_32 ( struct V_5 * V_38 )
{
unsigned int V_15 ;
F_64 ( V_38 ) ;
if ( V_38 -> V_54 ) {
for ( V_15 = 0 ; V_15 < V_38 -> V_8 ; V_15 ++ )
F_65 ( V_38 -> V_55 + V_15 ) ;
F_66 ( V_38 -> V_54 ) ;
}
if ( V_38 -> V_40 ) {
V_38 -> V_40 -> V_56 = NULL ;
V_38 -> V_40 -> V_57 = NULL ;
V_38 -> V_40 = NULL ;
}
}
int F_67 ( struct V_5 * V_38 ,
struct V_39 * V_40 ,
unsigned int V_58 ,
T_2 V_59 ,
unsigned int type )
{
struct V_60 * V_61 ;
unsigned int V_15 ;
unsigned V_55 = 0 ;
if ( ! V_38 || ! V_40 )
return - V_9 ;
if ( ! V_38 -> V_27 ) {
F_12 ( L_10 ) ;
return - V_9 ;
}
V_61 = V_38 -> V_27 -> V_61 ;
#ifdef F_68
if ( V_38 -> V_61 )
V_61 = V_38 -> V_61 ;
#endif
V_38 -> V_40 = V_40 ;
V_38 -> V_49 = V_59 ;
V_38 -> V_51 = type ;
V_38 -> V_62 = F_62 ;
V_38 -> V_54 = F_69 ( V_61 ,
V_38 -> V_8 , V_58 ,
& V_63 , V_38 ) ;
if ( ! V_38 -> V_54 ) {
V_38 -> V_40 = NULL ;
return - V_9 ;
}
V_40 -> V_56 = F_57 ;
V_40 -> V_57 = F_60 ;
for ( V_15 = 0 ; V_15 < V_38 -> V_8 ; V_15 ++ ) {
V_55 = F_70 ( V_38 -> V_54 , V_15 ) ;
if ( V_15 == 0 )
V_38 -> V_55 = V_55 ;
}
F_71 ( V_38 ) ;
return 0 ;
}
static void F_32 ( struct V_5 * V_38 ) {}
int F_72 ( struct V_5 * V_6 ,
struct V_64 * V_65 ,
unsigned int V_66 , const char * V_67 )
{
struct V_68 * V_69 ;
int V_70 ;
V_69 = F_73 ( sizeof( * V_69 ) , V_71 ) ;
if ( ! V_69 ) {
F_44 ( V_6 , L_11 ) ;
return - V_72 ;
}
V_69 -> V_73 . V_29 = V_66 ;
V_69 -> V_73 . V_74 = V_6 ;
V_69 -> V_73 . V_37 = V_6 -> V_3 ;
V_69 -> V_73 . V_11 = V_6 -> V_11 + V_66 ;
V_69 -> V_65 = V_65 ;
V_70 = F_74 ( V_65 , V_67 ,
& V_69 -> V_73 . V_75 ,
& V_69 -> V_73 . V_76 ) ;
if ( V_70 < 0 ) {
F_75 ( V_69 ) ;
return V_70 ;
}
F_76 ( V_65 , & V_69 -> V_73 ) ;
F_77 ( V_6 , L_12 ,
V_66 , V_66 + V_69 -> V_73 . V_76 - 1 ,
F_78 ( V_65 ) , V_67 ) ;
F_21 ( & V_69 -> V_77 , & V_6 -> V_34 ) ;
return 0 ;
}
int F_79 ( struct V_5 * V_6 , const char * V_78 ,
unsigned int V_66 , unsigned int V_79 ,
unsigned int V_76 )
{
struct V_68 * V_69 ;
int V_70 ;
V_69 = F_73 ( sizeof( * V_69 ) , V_71 ) ;
if ( ! V_69 ) {
F_44 ( V_6 , L_11 ) ;
return - V_72 ;
}
V_69 -> V_73 . V_29 = V_66 ;
V_69 -> V_73 . V_74 = V_6 ;
V_69 -> V_73 . V_37 = V_6 -> V_3 ;
V_69 -> V_73 . V_11 = V_6 -> V_11 + V_66 ;
V_69 -> V_73 . V_80 = V_79 ;
V_69 -> V_73 . V_76 = V_76 ;
V_69 -> V_65 = F_80 ( V_78 ,
& V_69 -> V_73 ) ;
if ( F_81 ( V_69 -> V_65 ) ) {
V_70 = F_82 ( V_69 -> V_65 ) ;
F_44 ( V_6 , L_13 ) ;
F_75 ( V_69 ) ;
return V_70 ;
}
F_77 ( V_6 , L_14 ,
V_66 , V_66 + V_76 - 1 ,
V_78 ,
V_79 , V_79 + V_76 - 1 ) ;
F_21 ( & V_69 -> V_77 , & V_6 -> V_34 ) ;
return 0 ;
}
void F_33 ( struct V_5 * V_6 )
{
struct V_68 * V_69 , * V_81 ;
F_83 (pin_range, tmp, &chip->pin_ranges, node) {
F_36 ( & V_69 -> V_77 ) ;
F_84 ( V_69 -> V_65 ,
& V_69 -> V_73 ) ;
F_75 ( V_69 ) ;
}
}
static int F_85 ( struct V_1 * V_10 , const char * V_3 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
int V_16 ;
unsigned long V_19 ;
F_23 ( & V_31 , V_19 ) ;
if ( F_86 ( V_35 , & V_10 -> V_19 ) == 0 ) {
F_1 ( V_10 , V_3 ? : L_15 ) ;
V_16 = 0 ;
} else {
V_16 = - V_28 ;
goto V_82;
}
if ( V_6 -> V_83 ) {
F_24 ( & V_31 , V_19 ) ;
V_16 = V_6 -> V_83 ( V_6 , F_14 ( V_10 ) ) ;
F_23 ( & V_31 , V_19 ) ;
if ( V_16 < 0 ) {
F_1 ( V_10 , NULL ) ;
F_15 ( V_35 , & V_10 -> V_19 ) ;
goto V_82;
}
}
if ( V_6 -> V_17 ) {
F_24 ( & V_31 , V_19 ) ;
F_13 ( V_10 ) ;
F_23 ( & V_31 , V_19 ) ;
}
V_82:
F_24 ( & V_31 , V_19 ) ;
return V_16 ;
}
int F_87 ( struct V_1 * V_10 , const char * V_3 )
{
int V_16 = - V_84 ;
struct V_5 * V_6 ;
if ( ! V_10 ) {
F_88 ( L_16 , V_13 ) ;
return - V_9 ;
}
V_6 = V_10 -> V_6 ;
if ( ! V_6 )
goto V_82;
if ( F_89 ( V_6 -> V_85 ) ) {
V_16 = F_85 ( V_10 , V_3 ) ;
if ( V_16 < 0 )
F_90 ( V_6 -> V_85 ) ;
}
V_82:
if ( V_16 )
F_91 ( V_10 , L_17 , V_13 , V_16 ) ;
return V_16 ;
}
static bool F_92 ( struct V_1 * V_10 )
{
bool V_70 = false ;
unsigned long V_19 ;
struct V_5 * V_6 ;
F_93 () ;
F_94 ( V_10 ) ;
F_23 ( & V_31 , V_19 ) ;
V_6 = V_10 -> V_6 ;
if ( V_6 && F_35 ( V_35 , & V_10 -> V_19 ) ) {
if ( V_6 -> free ) {
F_24 ( & V_31 , V_19 ) ;
F_95 ( V_6 -> V_43 ) ;
V_6 -> free ( V_6 , F_14 ( V_10 ) ) ;
F_23 ( & V_31 , V_19 ) ;
}
F_1 ( V_10 , NULL ) ;
F_15 ( V_86 , & V_10 -> V_19 ) ;
F_15 ( V_35 , & V_10 -> V_19 ) ;
F_15 ( V_87 , & V_10 -> V_19 ) ;
F_15 ( V_88 , & V_10 -> V_19 ) ;
V_70 = true ;
}
F_24 ( & V_31 , V_19 ) ;
return V_70 ;
}
void F_96 ( struct V_1 * V_10 )
{
if ( V_10 && F_92 ( V_10 ) )
F_90 ( V_10 -> V_6 -> V_85 ) ;
else
F_97 ( V_89 ) ;
}
const char * F_98 ( struct V_5 * V_6 , unsigned V_15 )
{
struct V_1 * V_10 ;
if ( ! F_99 ( V_6 , V_15 ) )
return NULL ;
V_10 = & V_6 -> V_10 [ V_15 ] ;
if ( F_35 ( V_35 , & V_10 -> V_19 ) == 0 )
return NULL ;
return V_10 -> V_3 ;
}
int F_100 ( struct V_1 * V_10 , const char * V_3 )
{
if ( ! V_10 || ! V_10 -> V_6 )
return - V_9 ;
return F_85 ( V_10 , V_3 ) ;
}
void F_101 ( struct V_1 * V_10 )
{
if ( V_10 )
F_92 ( V_10 ) ;
}
int F_102 ( struct V_1 * V_10 )
{
struct V_5 * V_6 ;
int V_16 = - V_9 ;
if ( ! V_10 || ! V_10 -> V_6 ) {
F_88 ( L_16 , V_13 ) ;
return - V_9 ;
}
V_6 = V_10 -> V_6 ;
if ( ! V_6 -> V_90 || ! V_6 -> V_33 ) {
F_103 ( V_10 ,
L_18 ,
V_13 ) ;
return - V_91 ;
}
V_16 = V_6 -> V_33 ( V_6 , F_14 ( V_10 ) ) ;
if ( V_16 == 0 )
F_15 ( V_18 , & V_10 -> V_19 ) ;
F_104 ( F_7 ( V_10 ) , 1 , V_16 ) ;
return V_16 ;
}
static int F_105 ( struct V_1 * V_10 , int V_92 )
{
struct V_5 * V_6 ;
int V_16 = - V_9 ;
if ( F_35 ( V_93 , & V_10 -> V_19 ) ) {
F_106 ( V_10 ,
L_19 ,
V_13 ) ;
return - V_91 ;
}
if ( V_92 && F_35 ( V_87 , & V_10 -> V_19 ) )
return F_102 ( V_10 ) ;
if ( ! V_92 && F_35 ( V_88 , & V_10 -> V_19 ) )
return F_102 ( V_10 ) ;
V_6 = V_10 -> V_6 ;
if ( ! V_6 -> V_94 || ! V_6 -> V_95 ) {
F_103 ( V_10 ,
L_20 ,
V_13 ) ;
return - V_91 ;
}
V_16 = V_6 -> V_95 ( V_6 , F_14 ( V_10 ) , V_92 ) ;
if ( V_16 == 0 )
F_16 ( V_18 , & V_10 -> V_19 ) ;
F_107 ( F_7 ( V_10 ) , 0 , V_92 ) ;
F_104 ( F_7 ( V_10 ) , 0 , V_16 ) ;
return V_16 ;
}
int F_108 ( struct V_1 * V_10 , int V_92 )
{
if ( ! V_10 || ! V_10 -> V_6 ) {
F_88 ( L_16 , V_13 ) ;
return - V_9 ;
}
return F_105 ( V_10 , V_92 ) ;
}
int F_109 ( struct V_1 * V_10 , int V_92 )
{
if ( ! V_10 || ! V_10 -> V_6 ) {
F_88 ( L_16 , V_13 ) ;
return - V_9 ;
}
if ( F_35 ( V_86 , & V_10 -> V_19 ) )
V_92 = ! V_92 ;
return F_105 ( V_10 , V_92 ) ;
}
int F_110 ( struct V_1 * V_10 , unsigned V_96 )
{
struct V_5 * V_6 ;
if ( ! V_10 || ! V_10 -> V_6 ) {
F_88 ( L_16 , V_13 ) ;
return - V_9 ;
}
V_6 = V_10 -> V_6 ;
if ( ! V_6 -> V_94 || ! V_6 -> V_97 ) {
F_91 ( V_10 ,
L_21 ,
V_13 ) ;
return - V_98 ;
}
return V_6 -> V_97 ( V_6 , F_14 ( V_10 ) , V_96 ) ;
}
int F_111 ( const struct V_1 * V_10 )
{
return F_35 ( V_86 , & V_10 -> V_19 ) ;
}
static bool F_112 ( const struct V_1 * V_10 )
{
struct V_5 * V_6 ;
bool V_92 ;
int V_15 ;
V_6 = V_10 -> V_6 ;
V_15 = F_14 ( V_10 ) ;
V_92 = V_6 -> V_90 ? V_6 -> V_90 ( V_6 , V_15 ) : false ;
F_107 ( F_7 ( V_10 ) , 1 , V_92 ) ;
return V_92 ;
}
int F_113 ( const struct V_1 * V_10 )
{
if ( ! V_10 )
return 0 ;
F_97 ( V_10 -> V_6 -> V_43 ) ;
return F_112 ( V_10 ) ;
}
int F_114 ( const struct V_1 * V_10 )
{
int V_92 ;
if ( ! V_10 )
return 0 ;
F_97 ( V_10 -> V_6 -> V_43 ) ;
V_92 = F_112 ( V_10 ) ;
if ( F_35 ( V_86 , & V_10 -> V_19 ) )
V_92 = ! V_92 ;
return V_92 ;
}
static void F_115 ( struct V_1 * V_10 , bool V_92 )
{
int V_24 = 0 ;
struct V_5 * V_6 = V_10 -> V_6 ;
int V_15 = F_14 ( V_10 ) ;
if ( V_92 ) {
V_24 = V_6 -> V_33 ( V_6 , V_15 ) ;
if ( ! V_24 )
F_15 ( V_18 , & V_10 -> V_19 ) ;
} else {
V_24 = V_6 -> V_95 ( V_6 , V_15 , 0 ) ;
if ( ! V_24 )
F_16 ( V_18 , & V_10 -> V_19 ) ;
}
F_104 ( F_7 ( V_10 ) , V_92 , V_24 ) ;
if ( V_24 < 0 )
F_106 ( V_10 ,
L_22 ,
V_13 , V_24 ) ;
}
static void F_116 ( struct V_1 * V_10 , bool V_92 )
{
int V_24 = 0 ;
struct V_5 * V_6 = V_10 -> V_6 ;
int V_15 = F_14 ( V_10 ) ;
if ( V_92 ) {
V_24 = V_6 -> V_95 ( V_6 , V_15 , 1 ) ;
if ( ! V_24 )
F_16 ( V_18 , & V_10 -> V_19 ) ;
} else {
V_24 = V_6 -> V_33 ( V_6 , V_15 ) ;
if ( ! V_24 )
F_15 ( V_18 , & V_10 -> V_19 ) ;
}
F_104 ( F_7 ( V_10 ) , ! V_92 , V_24 ) ;
if ( V_24 < 0 )
F_106 ( V_10 ,
L_23 ,
V_13 , V_24 ) ;
}
static void F_117 ( struct V_1 * V_10 , bool V_92 )
{
struct V_5 * V_6 ;
V_6 = V_10 -> V_6 ;
F_107 ( F_7 ( V_10 ) , 0 , V_92 ) ;
if ( F_35 ( V_87 , & V_10 -> V_19 ) )
F_115 ( V_10 , V_92 ) ;
else if ( F_35 ( V_88 , & V_10 -> V_19 ) )
F_116 ( V_10 , V_92 ) ;
else
V_6 -> V_94 ( V_6 , F_14 ( V_10 ) , V_92 ) ;
}
void F_118 ( struct V_1 * V_10 , int V_92 )
{
if ( ! V_10 )
return;
F_97 ( V_10 -> V_6 -> V_43 ) ;
F_117 ( V_10 , V_92 ) ;
}
void F_119 ( struct V_1 * V_10 , int V_92 )
{
if ( ! V_10 )
return;
F_97 ( V_10 -> V_6 -> V_43 ) ;
if ( F_35 ( V_86 , & V_10 -> V_19 ) )
V_92 = ! V_92 ;
F_117 ( V_10 , V_92 ) ;
}
int F_120 ( const struct V_1 * V_10 )
{
if ( ! V_10 )
return 0 ;
return V_10 -> V_6 -> V_43 ;
}
int F_121 ( const struct V_1 * V_10 )
{
struct V_5 * V_6 ;
int V_15 ;
if ( ! V_10 )
return - V_9 ;
V_6 = V_10 -> V_6 ;
V_15 = F_14 ( V_10 ) ;
return V_6 -> V_62 ? V_6 -> V_62 ( V_6 , V_15 ) : - V_99 ;
}
int F_59 ( struct V_5 * V_6 , unsigned int V_15 )
{
if ( V_15 >= V_6 -> V_8 )
return - V_9 ;
if ( F_35 ( V_18 , & V_6 -> V_10 [ V_15 ] . V_19 ) ) {
F_44 ( V_6 ,
L_24 ,
V_13 ) ;
return - V_91 ;
}
F_16 ( V_93 , & V_6 -> V_10 [ V_15 ] . V_19 ) ;
return 0 ;
}
void F_61 ( struct V_5 * V_6 , unsigned int V_15 )
{
if ( V_15 >= V_6 -> V_8 )
return;
F_15 ( V_93 , & V_6 -> V_10 [ V_15 ] . V_19 ) ;
}
int F_122 ( const struct V_1 * V_10 )
{
F_95 ( V_89 ) ;
if ( ! V_10 )
return 0 ;
return F_112 ( V_10 ) ;
}
int F_123 ( const struct V_1 * V_10 )
{
int V_92 ;
F_95 ( V_89 ) ;
if ( ! V_10 )
return 0 ;
V_92 = F_112 ( V_10 ) ;
if ( F_35 ( V_86 , & V_10 -> V_19 ) )
V_92 = ! V_92 ;
return V_92 ;
}
void F_124 ( struct V_1 * V_10 , int V_92 )
{
F_95 ( V_89 ) ;
if ( ! V_10 )
return;
F_117 ( V_10 , V_92 ) ;
}
void F_125 ( struct V_1 * V_10 , int V_92 )
{
F_95 ( V_89 ) ;
if ( ! V_10 )
return;
if ( F_35 ( V_86 , & V_10 -> V_19 ) )
V_92 = ! V_92 ;
F_117 ( V_10 , V_92 ) ;
}
void F_126 ( struct V_100 * V_101 )
{
F_127 ( & V_102 ) ;
F_21 ( & V_101 -> V_25 , & V_103 ) ;
F_128 ( & V_102 ) ;
}
static struct V_1 * F_129 ( struct V_104 * V_27 , const char * V_105 ,
unsigned int V_106 ,
enum V_107 * V_19 )
{
static const char * V_108 [] = { L_25 , L_26 } ;
char V_109 [ 32 ] ;
enum V_110 V_111 ;
struct V_1 * V_10 ;
unsigned int V_112 ;
for ( V_112 = 0 ; V_112 < F_130 ( V_108 ) ; V_112 ++ ) {
if ( V_105 )
snprintf ( V_109 , 32 , L_27 , V_105 , V_108 [ V_112 ] ) ;
else
snprintf ( V_109 , 32 , L_28 , V_108 [ V_112 ] ) ;
V_10 = F_131 ( V_27 -> V_61 , V_109 , V_106 ,
& V_111 ) ;
if ( ! F_81 ( V_10 ) || ( F_82 ( V_10 ) == - V_84 ) )
break;
}
if ( F_81 ( V_10 ) )
return V_10 ;
if ( V_111 & V_113 )
* V_19 |= V_114 ;
return V_10 ;
}
static struct V_1 * F_132 ( struct V_104 * V_27 , const char * V_105 ,
unsigned int V_106 ,
enum V_107 * V_19 )
{
struct V_115 V_116 ;
struct V_1 * V_10 ;
V_10 = F_133 ( V_27 , V_106 , & V_116 ) ;
if ( F_81 ( V_10 ) )
return V_10 ;
if ( V_116 . V_117 && V_116 . V_118 )
* V_19 |= V_114 ;
return V_10 ;
}
static struct V_100 * F_134 ( struct V_104 * V_27 )
{
const char * V_119 = V_27 ? F_135 ( V_27 ) : NULL ;
struct V_100 * V_101 ;
F_127 ( & V_102 ) ;
F_40 (table, &gpio_lookup_list, list) {
if ( V_101 -> V_119 && V_119 ) {
if ( ! strcmp ( V_101 -> V_119 , V_119 ) )
goto V_120;
} else {
if ( V_119 == V_101 -> V_119 )
goto V_120;
}
}
V_101 = NULL ;
V_120:
F_128 ( & V_102 ) ;
return V_101 ;
}
static struct V_1 * F_136 ( struct V_104 * V_27 , const char * V_105 ,
unsigned int V_106 ,
enum V_107 * V_19 )
{
struct V_1 * V_10 = F_6 ( - V_121 ) ;
struct V_100 * V_101 ;
struct V_122 * V_123 ;
V_101 = F_134 ( V_27 ) ;
if ( ! V_101 )
return V_10 ;
for ( V_123 = & V_101 -> V_101 [ 0 ] ; V_123 -> V_124 ; V_123 ++ ) {
struct V_5 * V_6 ;
if ( V_123 -> V_106 != V_106 )
continue;
if ( V_123 -> V_105 && ( ! V_105 || strcmp ( V_123 -> V_105 , V_105 ) ) )
continue;
V_6 = F_42 ( V_123 -> V_124 ) ;
if ( ! V_6 ) {
F_20 ( V_27 , L_29 ,
V_123 -> V_124 ) ;
return F_6 ( - V_125 ) ;
}
if ( V_6 -> V_8 <= V_123 -> V_126 ) {
F_20 ( V_27 ,
L_30 ,
V_106 , V_6 -> V_8 , V_6 -> V_3 ) ;
return F_6 ( - V_9 ) ;
}
V_10 = F_5 ( V_6 , V_123 -> V_126 ) ;
* V_19 = V_123 -> V_19 ;
return V_10 ;
}
return V_10 ;
}
struct V_1 * T_4 F_137 ( struct V_104 * V_27 , const char * V_105 ,
enum V_127 V_19 )
{
return F_138 ( V_27 , V_105 , 0 , V_19 ) ;
}
struct V_1 * T_4 F_139 ( struct V_104 * V_27 ,
const char * V_105 ,
enum V_127 V_19 )
{
return F_140 ( V_27 , V_105 , 0 , V_19 ) ;
}
struct V_1 * T_4 F_141 ( struct V_104 * V_27 ,
const char * V_105 ,
unsigned int V_106 ,
enum V_127 V_19 )
{
struct V_1 * V_10 = NULL ;
int V_16 ;
enum V_107 V_128 = 0 ;
F_142 ( V_27 , L_31 , V_105 ) ;
if ( F_143 ( V_129 ) && V_27 && V_27 -> V_61 ) {
F_142 ( V_27 , L_32 ) ;
V_10 = F_129 ( V_27 , V_105 , V_106 , & V_128 ) ;
} else if ( F_143 ( V_130 ) && V_27 && F_144 ( V_27 ) ) {
F_142 ( V_27 , L_33 ) ;
V_10 = F_132 ( V_27 , V_105 , V_106 , & V_128 ) ;
}
if ( ! V_10 || V_10 == F_6 ( - V_121 ) ) {
F_142 ( V_27 , L_34 ) ;
V_10 = F_136 ( V_27 , V_105 , V_106 , & V_128 ) ;
}
if ( F_81 ( V_10 ) ) {
F_142 ( V_27 , L_35 , V_105 ) ;
return V_10 ;
}
V_16 = F_87 ( V_10 , V_105 ) ;
if ( V_16 < 0 )
return F_6 ( V_16 ) ;
if ( V_128 & V_114 )
F_16 ( V_86 , & V_10 -> V_19 ) ;
if ( V_128 & V_131 )
F_16 ( V_87 , & V_10 -> V_19 ) ;
if ( V_128 & V_132 )
F_16 ( V_88 , & V_10 -> V_19 ) ;
if ( ! ( V_19 & V_133 ) )
return V_10 ;
if ( V_19 & V_134 )
V_16 = F_109 ( V_10 ,
V_19 & V_135 ) ;
else
V_16 = F_102 ( V_10 ) ;
if ( V_16 < 0 ) {
F_142 ( V_27 , L_36 , V_105 ) ;
F_145 ( V_10 ) ;
return F_6 ( V_16 ) ;
}
return V_10 ;
}
struct V_1 * T_4 F_146 ( struct V_104 * V_27 ,
const char * V_105 ,
unsigned int V_136 ,
enum V_127 V_19 )
{
struct V_1 * V_10 ;
V_10 = F_138 ( V_27 , V_105 , V_136 , V_19 ) ;
if ( F_81 ( V_10 ) ) {
if ( F_82 ( V_10 ) == - V_121 )
return NULL ;
}
return V_10 ;
}
void F_145 ( struct V_1 * V_10 )
{
F_96 ( V_10 ) ;
}
static void F_147 ( struct V_137 * V_138 , struct V_5 * V_6 )
{
unsigned V_112 ;
unsigned V_4 = V_6 -> V_11 ;
struct V_1 * V_139 = & V_6 -> V_10 [ 0 ] ;
int V_140 ;
int V_141 ;
for ( V_112 = 0 ; V_112 < V_6 -> V_8 ; V_112 ++ , V_4 ++ , V_139 ++ ) {
if ( ! F_35 ( V_35 , & V_139 -> V_19 ) )
continue;
F_13 ( V_139 ) ;
V_140 = F_35 ( V_18 , & V_139 -> V_19 ) ;
V_141 = F_35 ( V_93 , & V_139 -> V_19 ) ;
F_148 ( V_138 , L_37 ,
V_4 , V_139 -> V_3 ,
V_140 ? L_38 : L_39 ,
V_6 -> V_90
? ( V_6 -> V_90 ( V_6 , V_112 ) ? L_40 : L_41 )
: L_42 ,
V_141 ? L_43 : L_44 ) ;
F_148 ( V_138 , L_45 ) ;
}
}
static void * F_149 ( struct V_137 * V_138 , T_5 * V_21 )
{
unsigned long V_19 ;
struct V_5 * V_6 = NULL ;
T_5 V_136 = * V_21 ;
V_138 -> V_142 = L_46 ;
F_23 ( & V_31 , V_19 ) ;
F_40 (chip, &gpio_chips, list)
if ( V_136 -- == 0 ) {
F_24 ( & V_31 , V_19 ) ;
return V_6 ;
}
F_24 ( & V_31 , V_19 ) ;
return NULL ;
}
static void * F_150 ( struct V_137 * V_138 , void * V_143 , T_5 * V_21 )
{
unsigned long V_19 ;
struct V_5 * V_6 = V_143 ;
void * V_70 = NULL ;
F_23 ( & V_31 , V_19 ) ;
if ( F_151 ( & V_6 -> V_25 , & V_22 ) )
V_70 = NULL ;
else
V_70 = F_19 ( V_6 -> V_25 . V_144 , struct V_5 , V_25 ) ;
F_24 ( & V_31 , V_19 ) ;
V_138 -> V_142 = L_45 ;
++ * V_21 ;
return V_70 ;
}
static void F_152 ( struct V_137 * V_138 , void * V_143 )
{
}
static int F_153 ( struct V_137 * V_138 , void * V_143 )
{
struct V_5 * V_6 = V_143 ;
struct V_104 * V_27 ;
F_148 ( V_138 , L_47 , ( char * ) V_138 -> V_142 ,
V_6 -> V_11 , V_6 -> V_11 + V_6 -> V_8 - 1 ) ;
V_27 = V_6 -> V_27 ;
if ( V_27 )
F_148 ( V_138 , L_48 , V_27 -> V_145 ? V_27 -> V_145 -> V_37 : L_49 ,
F_135 ( V_27 ) ) ;
if ( V_6 -> V_3 )
F_148 ( V_138 , L_50 , V_6 -> V_3 ) ;
if ( V_6 -> V_43 )
F_148 ( V_138 , L_51 ) ;
F_148 ( V_138 , L_52 ) ;
if ( V_6 -> V_146 )
V_6 -> V_146 ( V_138 , V_6 ) ;
else
F_147 ( V_138 , V_6 ) ;
return 0 ;
}
static int F_154 ( struct V_147 * V_147 , struct V_148 * V_148 )
{
return F_155 ( V_148 , & V_149 ) ;
}
static int T_6 F_156 ( void )
{
( void ) F_157 ( L_26 , V_150 | V_151 ,
NULL , NULL , & V_152 ) ;
return 0 ;
}
