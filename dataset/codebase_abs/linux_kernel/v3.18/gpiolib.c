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
void F_30 ( struct V_5 * V_6 )
{
unsigned long V_19 ;
unsigned V_29 ;
F_31 ( V_6 ) ;
F_23 ( & V_31 , V_19 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_8 ; V_29 ++ ) {
if ( F_35 ( V_35 , & V_6 -> V_10 [ V_29 ] . V_19 ) )
F_36 ( V_6 -> V_27 , L_8 ) ;
}
for ( V_29 = 0 ; V_29 < V_6 -> V_8 ; V_29 ++ )
V_6 -> V_10 [ V_29 ] . V_6 = NULL ;
F_37 ( & V_6 -> V_25 ) ;
F_24 ( & V_31 , V_19 ) ;
F_38 ( V_6 ) ;
}
struct V_5 * F_39 ( void * V_36 ,
int (* F_40)( struct V_5 * V_6 ,
void * V_36 ) )
{
struct V_5 * V_6 ;
unsigned long V_19 ;
F_23 ( & V_31 , V_19 ) ;
F_41 (chip, &gpio_chips, list)
if ( F_40 ( V_6 , V_36 ) )
break;
if ( & V_6 -> V_25 == & V_22 )
V_6 = NULL ;
F_24 ( & V_31 , V_19 ) ;
return V_6 ;
}
static int F_42 ( struct V_5 * V_6 , void * V_36 )
{
const char * V_37 = V_36 ;
return ! strcmp ( V_6 -> V_3 , V_37 ) ;
}
static struct V_5 * F_43 ( const char * V_37 )
{
return F_39 ( ( void * ) V_37 , F_42 ) ;
}
void F_44 ( struct V_5 * V_38 ,
struct V_39 * V_40 ,
int V_41 ,
T_2 V_42 )
{
unsigned int V_15 ;
if ( ! V_38 -> V_43 ) {
F_45 ( V_38 , L_9 ,
V_13 ) ;
return;
}
if ( V_42 ) {
if ( V_38 -> V_44 ) {
F_45 ( V_38 ,
L_10
L_11 ) ;
return;
}
F_46 ( V_41 , V_38 ) ;
F_47 ( V_41 , V_42 ) ;
}
for ( V_15 = 0 ; V_15 < V_38 -> V_8 ; V_15 ++ )
F_48 ( F_49 ( V_38 -> V_43 , V_15 ) ,
V_41 ) ;
}
static int F_50 ( struct V_45 * V_2 , unsigned int V_46 ,
T_3 V_47 )
{
struct V_5 * V_6 = V_2 -> V_48 ;
F_51 ( V_46 , V_6 ) ;
F_52 ( V_46 , & V_49 ) ;
F_53 ( V_46 , V_6 -> V_40 , V_6 -> V_50 ) ;
if ( V_6 -> V_44 && ! V_6 -> V_51 )
F_54 ( V_46 , 1 ) ;
#ifdef F_55
F_56 ( V_46 , V_52 ) ;
#else
F_57 ( V_46 ) ;
#endif
if ( V_6 -> V_53 != V_54 )
F_58 ( V_46 , V_6 -> V_53 ) ;
return 0 ;
}
static void F_59 ( struct V_45 * V_2 , unsigned int V_46 )
{
struct V_5 * V_6 = V_2 -> V_48 ;
#ifdef F_55
F_56 ( V_46 , 0 ) ;
#endif
if ( V_6 -> V_44 )
F_54 ( V_46 , 0 ) ;
F_53 ( V_46 , NULL , NULL ) ;
F_51 ( V_46 , NULL ) ;
}
static int F_60 ( struct V_55 * V_2 )
{
struct V_5 * V_6 = F_61 ( V_2 ) ;
if ( F_62 ( V_6 , V_2 -> V_47 ) ) {
F_45 ( V_6 ,
L_12 ,
V_2 -> V_47 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_63 ( struct V_55 * V_2 )
{
struct V_5 * V_6 = F_61 ( V_2 ) ;
F_64 ( V_6 , V_2 -> V_47 ) ;
}
static int F_65 ( struct V_5 * V_6 , unsigned V_15 )
{
return F_49 ( V_6 -> V_43 , V_15 ) ;
}
static void F_32 ( struct V_5 * V_38 )
{
unsigned int V_15 ;
F_66 ( V_38 ) ;
if ( V_38 -> V_43 ) {
for ( V_15 = 0 ; V_15 < V_38 -> V_8 ; V_15 ++ )
F_67 (
F_49 ( V_38 -> V_43 , V_15 ) ) ;
F_68 ( V_38 -> V_43 ) ;
}
if ( V_38 -> V_40 ) {
V_38 -> V_40 -> V_56 = NULL ;
V_38 -> V_40 -> V_57 = NULL ;
V_38 -> V_40 = NULL ;
}
}
int F_69 ( struct V_5 * V_38 ,
struct V_39 * V_40 ,
unsigned int V_58 ,
T_2 V_59 ,
unsigned int type )
{
struct V_60 * V_61 ;
unsigned int V_15 ;
unsigned V_62 = 0 ;
if ( ! V_38 || ! V_40 )
return - V_9 ;
if ( ! V_38 -> V_27 ) {
F_12 ( L_13 ) ;
return - V_9 ;
}
V_61 = V_38 -> V_27 -> V_61 ;
#ifdef F_70
if ( V_38 -> V_61 )
V_61 = V_38 -> V_61 ;
#endif
V_38 -> V_40 = V_40 ;
V_38 -> V_50 = V_59 ;
V_38 -> V_53 = type ;
V_38 -> V_63 = F_65 ;
V_38 -> V_43 = F_71 ( V_61 ,
V_38 -> V_8 , V_58 ,
& V_64 , V_38 ) ;
if ( ! V_38 -> V_43 ) {
V_38 -> V_40 = NULL ;
return - V_9 ;
}
V_40 -> V_56 = F_60 ;
V_40 -> V_57 = F_63 ;
for ( V_15 = 0 ; V_15 < V_38 -> V_8 ; V_15 ++ ) {
V_62 = F_72 ( V_38 -> V_43 , V_15 ) ;
if ( V_15 == 0 )
V_38 -> V_62 = V_62 ;
}
F_73 ( V_38 ) ;
return 0 ;
}
static void F_32 ( struct V_5 * V_38 ) {}
int F_74 ( struct V_5 * V_6 ,
struct V_65 * V_66 ,
unsigned int V_67 , const char * V_68 )
{
struct V_69 * V_70 ;
int V_71 ;
V_70 = F_75 ( sizeof( * V_70 ) , V_72 ) ;
if ( ! V_70 ) {
F_45 ( V_6 , L_14 ) ;
return - V_73 ;
}
V_70 -> V_74 . V_29 = V_67 ;
V_70 -> V_74 . V_75 = V_6 ;
V_70 -> V_74 . V_37 = V_6 -> V_3 ;
V_70 -> V_74 . V_11 = V_6 -> V_11 + V_67 ;
V_70 -> V_66 = V_66 ;
V_71 = F_76 ( V_66 , V_68 ,
& V_70 -> V_74 . V_76 ,
& V_70 -> V_74 . V_77 ) ;
if ( V_71 < 0 ) {
F_77 ( V_70 ) ;
return V_71 ;
}
F_78 ( V_66 , & V_70 -> V_74 ) ;
F_79 ( V_6 , L_15 ,
V_67 , V_67 + V_70 -> V_74 . V_77 - 1 ,
F_80 ( V_66 ) , V_68 ) ;
F_21 ( & V_70 -> V_78 , & V_6 -> V_34 ) ;
return 0 ;
}
int F_81 ( struct V_5 * V_6 , const char * V_79 ,
unsigned int V_67 , unsigned int V_80 ,
unsigned int V_77 )
{
struct V_69 * V_70 ;
int V_71 ;
V_70 = F_75 ( sizeof( * V_70 ) , V_72 ) ;
if ( ! V_70 ) {
F_45 ( V_6 , L_14 ) ;
return - V_73 ;
}
V_70 -> V_74 . V_29 = V_67 ;
V_70 -> V_74 . V_75 = V_6 ;
V_70 -> V_74 . V_37 = V_6 -> V_3 ;
V_70 -> V_74 . V_11 = V_6 -> V_11 + V_67 ;
V_70 -> V_74 . V_81 = V_80 ;
V_70 -> V_74 . V_77 = V_77 ;
V_70 -> V_66 = F_82 ( V_79 ,
& V_70 -> V_74 ) ;
if ( F_83 ( V_70 -> V_66 ) ) {
V_71 = F_84 ( V_70 -> V_66 ) ;
F_45 ( V_6 , L_16 ) ;
F_77 ( V_70 ) ;
return V_71 ;
}
F_79 ( V_6 , L_17 ,
V_67 , V_67 + V_77 - 1 ,
V_79 ,
V_80 , V_80 + V_77 - 1 ) ;
F_21 ( & V_70 -> V_78 , & V_6 -> V_34 ) ;
return 0 ;
}
void F_33 ( struct V_5 * V_6 )
{
struct V_69 * V_70 , * V_82 ;
F_85 (pin_range, tmp, &chip->pin_ranges, node) {
F_37 ( & V_70 -> V_78 ) ;
F_86 ( V_70 -> V_66 ,
& V_70 -> V_74 ) ;
F_77 ( V_70 ) ;
}
}
static int F_87 ( struct V_1 * V_10 , const char * V_3 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
int V_16 ;
unsigned long V_19 ;
F_23 ( & V_31 , V_19 ) ;
if ( F_88 ( V_35 , & V_10 -> V_19 ) == 0 ) {
F_1 ( V_10 , V_3 ? : L_18 ) ;
V_16 = 0 ;
} else {
V_16 = - V_28 ;
goto V_83;
}
if ( V_6 -> V_84 ) {
F_24 ( & V_31 , V_19 ) ;
V_16 = V_6 -> V_84 ( V_6 , F_14 ( V_10 ) ) ;
F_23 ( & V_31 , V_19 ) ;
if ( V_16 < 0 ) {
F_1 ( V_10 , NULL ) ;
F_15 ( V_35 , & V_10 -> V_19 ) ;
goto V_83;
}
}
if ( V_6 -> V_17 ) {
F_24 ( & V_31 , V_19 ) ;
F_13 ( V_10 ) ;
F_23 ( & V_31 , V_19 ) ;
}
V_83:
F_24 ( & V_31 , V_19 ) ;
return V_16 ;
}
int F_89 ( struct V_1 * V_10 , const char * V_3 )
{
int V_16 = - V_85 ;
struct V_5 * V_6 ;
if ( ! V_10 ) {
F_90 ( L_19 , V_13 ) ;
return - V_9 ;
}
V_6 = V_10 -> V_6 ;
if ( ! V_6 )
goto V_83;
if ( F_91 ( V_6 -> V_86 ) ) {
V_16 = F_87 ( V_10 , V_3 ) ;
if ( V_16 < 0 )
F_92 ( V_6 -> V_86 ) ;
}
V_83:
if ( V_16 )
F_93 ( V_10 , L_20 , V_13 , V_16 ) ;
return V_16 ;
}
static bool F_94 ( struct V_1 * V_10 )
{
bool V_71 = false ;
unsigned long V_19 ;
struct V_5 * V_6 ;
F_95 () ;
F_96 ( V_10 ) ;
F_23 ( & V_31 , V_19 ) ;
V_6 = V_10 -> V_6 ;
if ( V_6 && F_35 ( V_35 , & V_10 -> V_19 ) ) {
if ( V_6 -> free ) {
F_24 ( & V_31 , V_19 ) ;
F_97 ( V_6 -> V_44 ) ;
V_6 -> free ( V_6 , F_14 ( V_10 ) ) ;
F_23 ( & V_31 , V_19 ) ;
}
F_1 ( V_10 , NULL ) ;
F_15 ( V_87 , & V_10 -> V_19 ) ;
F_15 ( V_35 , & V_10 -> V_19 ) ;
F_15 ( V_88 , & V_10 -> V_19 ) ;
F_15 ( V_89 , & V_10 -> V_19 ) ;
V_71 = true ;
}
F_24 ( & V_31 , V_19 ) ;
return V_71 ;
}
void F_98 ( struct V_1 * V_10 )
{
if ( V_10 && F_94 ( V_10 ) )
F_92 ( V_10 -> V_6 -> V_86 ) ;
else
F_99 ( V_90 ) ;
}
const char * F_100 ( struct V_5 * V_6 , unsigned V_15 )
{
struct V_1 * V_10 ;
if ( ! F_101 ( V_6 , V_15 ) )
return NULL ;
V_10 = & V_6 -> V_10 [ V_15 ] ;
if ( F_35 ( V_35 , & V_10 -> V_19 ) == 0 )
return NULL ;
return V_10 -> V_3 ;
}
struct V_1 * F_102 ( struct V_5 * V_6 , T_1 V_7 ,
const char * V_3 )
{
struct V_1 * V_10 = F_5 ( V_6 , V_7 ) ;
int V_24 ;
if ( F_83 ( V_10 ) ) {
F_45 ( V_6 , L_21 ) ;
return V_10 ;
}
V_24 = F_87 ( V_10 , V_3 ) ;
if ( V_24 < 0 )
return F_6 ( V_24 ) ;
return V_10 ;
}
void F_103 ( struct V_1 * V_10 )
{
if ( V_10 )
F_94 ( V_10 ) ;
}
int F_104 ( struct V_1 * V_10 )
{
struct V_5 * V_6 ;
int V_16 = - V_9 ;
if ( ! V_10 || ! V_10 -> V_6 ) {
F_90 ( L_19 , V_13 ) ;
return - V_9 ;
}
V_6 = V_10 -> V_6 ;
if ( ! V_6 -> V_91 || ! V_6 -> V_33 ) {
F_105 ( V_10 ,
L_22 ,
V_13 ) ;
return - V_92 ;
}
V_16 = V_6 -> V_33 ( V_6 , F_14 ( V_10 ) ) ;
if ( V_16 == 0 )
F_15 ( V_18 , & V_10 -> V_19 ) ;
F_106 ( F_7 ( V_10 ) , 1 , V_16 ) ;
return V_16 ;
}
static int F_107 ( struct V_1 * V_10 , int V_93 )
{
struct V_5 * V_6 ;
int V_16 = - V_9 ;
if ( F_35 ( V_94 , & V_10 -> V_19 ) ) {
F_108 ( V_10 ,
L_23 ,
V_13 ) ;
return - V_92 ;
}
if ( V_93 && F_35 ( V_88 , & V_10 -> V_19 ) )
return F_104 ( V_10 ) ;
if ( ! V_93 && F_35 ( V_89 , & V_10 -> V_19 ) )
return F_104 ( V_10 ) ;
V_6 = V_10 -> V_6 ;
if ( ! V_6 -> V_95 || ! V_6 -> V_96 ) {
F_105 ( V_10 ,
L_24 ,
V_13 ) ;
return - V_92 ;
}
V_16 = V_6 -> V_96 ( V_6 , F_14 ( V_10 ) , V_93 ) ;
if ( V_16 == 0 )
F_16 ( V_18 , & V_10 -> V_19 ) ;
F_109 ( F_7 ( V_10 ) , 0 , V_93 ) ;
F_106 ( F_7 ( V_10 ) , 0 , V_16 ) ;
return V_16 ;
}
int F_110 ( struct V_1 * V_10 , int V_93 )
{
if ( ! V_10 || ! V_10 -> V_6 ) {
F_90 ( L_19 , V_13 ) ;
return - V_9 ;
}
return F_107 ( V_10 , V_93 ) ;
}
int F_111 ( struct V_1 * V_10 , int V_93 )
{
if ( ! V_10 || ! V_10 -> V_6 ) {
F_90 ( L_19 , V_13 ) ;
return - V_9 ;
}
if ( F_35 ( V_87 , & V_10 -> V_19 ) )
V_93 = ! V_93 ;
return F_107 ( V_10 , V_93 ) ;
}
int F_112 ( struct V_1 * V_10 , unsigned V_97 )
{
struct V_5 * V_6 ;
if ( ! V_10 || ! V_10 -> V_6 ) {
F_90 ( L_19 , V_13 ) ;
return - V_9 ;
}
V_6 = V_10 -> V_6 ;
if ( ! V_6 -> V_95 || ! V_6 -> V_98 ) {
F_93 ( V_10 ,
L_25 ,
V_13 ) ;
return - V_99 ;
}
return V_6 -> V_98 ( V_6 , F_14 ( V_10 ) , V_97 ) ;
}
int F_113 ( const struct V_1 * V_10 )
{
return F_35 ( V_87 , & V_10 -> V_19 ) ;
}
static bool F_114 ( const struct V_1 * V_10 )
{
struct V_5 * V_6 ;
bool V_93 ;
int V_15 ;
V_6 = V_10 -> V_6 ;
V_15 = F_14 ( V_10 ) ;
V_93 = V_6 -> V_91 ? V_6 -> V_91 ( V_6 , V_15 ) : false ;
F_109 ( F_7 ( V_10 ) , 1 , V_93 ) ;
return V_93 ;
}
int F_115 ( const struct V_1 * V_10 )
{
if ( ! V_10 )
return 0 ;
F_99 ( V_10 -> V_6 -> V_44 ) ;
return F_114 ( V_10 ) ;
}
int F_116 ( const struct V_1 * V_10 )
{
int V_93 ;
if ( ! V_10 )
return 0 ;
F_99 ( V_10 -> V_6 -> V_44 ) ;
V_93 = F_114 ( V_10 ) ;
if ( F_35 ( V_87 , & V_10 -> V_19 ) )
V_93 = ! V_93 ;
return V_93 ;
}
static void F_117 ( struct V_1 * V_10 , bool V_93 )
{
int V_24 = 0 ;
struct V_5 * V_6 = V_10 -> V_6 ;
int V_15 = F_14 ( V_10 ) ;
if ( V_93 ) {
V_24 = V_6 -> V_33 ( V_6 , V_15 ) ;
if ( ! V_24 )
F_15 ( V_18 , & V_10 -> V_19 ) ;
} else {
V_24 = V_6 -> V_96 ( V_6 , V_15 , 0 ) ;
if ( ! V_24 )
F_16 ( V_18 , & V_10 -> V_19 ) ;
}
F_106 ( F_7 ( V_10 ) , V_93 , V_24 ) ;
if ( V_24 < 0 )
F_108 ( V_10 ,
L_26 ,
V_13 , V_24 ) ;
}
static void F_118 ( struct V_1 * V_10 , bool V_93 )
{
int V_24 = 0 ;
struct V_5 * V_6 = V_10 -> V_6 ;
int V_15 = F_14 ( V_10 ) ;
if ( V_93 ) {
V_24 = V_6 -> V_96 ( V_6 , V_15 , 1 ) ;
if ( ! V_24 )
F_16 ( V_18 , & V_10 -> V_19 ) ;
} else {
V_24 = V_6 -> V_33 ( V_6 , V_15 ) ;
if ( ! V_24 )
F_15 ( V_18 , & V_10 -> V_19 ) ;
}
F_106 ( F_7 ( V_10 ) , ! V_93 , V_24 ) ;
if ( V_24 < 0 )
F_108 ( V_10 ,
L_27 ,
V_13 , V_24 ) ;
}
static void F_119 ( struct V_1 * V_10 , bool V_93 )
{
struct V_5 * V_6 ;
V_6 = V_10 -> V_6 ;
F_109 ( F_7 ( V_10 ) , 0 , V_93 ) ;
if ( F_35 ( V_88 , & V_10 -> V_19 ) )
F_117 ( V_10 , V_93 ) ;
else if ( F_35 ( V_89 , & V_10 -> V_19 ) )
F_118 ( V_10 , V_93 ) ;
else
V_6 -> V_95 ( V_6 , F_14 ( V_10 ) , V_93 ) ;
}
void F_120 ( struct V_1 * V_10 , int V_93 )
{
if ( ! V_10 )
return;
F_99 ( V_10 -> V_6 -> V_44 ) ;
F_119 ( V_10 , V_93 ) ;
}
void F_121 ( struct V_1 * V_10 , int V_93 )
{
if ( ! V_10 )
return;
F_99 ( V_10 -> V_6 -> V_44 ) ;
if ( F_35 ( V_87 , & V_10 -> V_19 ) )
V_93 = ! V_93 ;
F_119 ( V_10 , V_93 ) ;
}
int F_122 ( const struct V_1 * V_10 )
{
if ( ! V_10 )
return 0 ;
return V_10 -> V_6 -> V_44 ;
}
int F_123 ( const struct V_1 * V_10 )
{
struct V_5 * V_6 ;
int V_15 ;
if ( ! V_10 )
return - V_9 ;
V_6 = V_10 -> V_6 ;
V_15 = F_14 ( V_10 ) ;
return V_6 -> V_63 ? V_6 -> V_63 ( V_6 , V_15 ) : - V_100 ;
}
int F_62 ( struct V_5 * V_6 , unsigned int V_15 )
{
if ( V_15 >= V_6 -> V_8 )
return - V_9 ;
if ( F_35 ( V_18 , & V_6 -> V_10 [ V_15 ] . V_19 ) ) {
F_45 ( V_6 ,
L_28 ,
V_13 ) ;
return - V_92 ;
}
F_16 ( V_94 , & V_6 -> V_10 [ V_15 ] . V_19 ) ;
return 0 ;
}
void F_64 ( struct V_5 * V_6 , unsigned int V_15 )
{
if ( V_15 >= V_6 -> V_8 )
return;
F_15 ( V_94 , & V_6 -> V_10 [ V_15 ] . V_19 ) ;
}
int F_124 ( const struct V_1 * V_10 )
{
F_97 ( V_90 ) ;
if ( ! V_10 )
return 0 ;
return F_114 ( V_10 ) ;
}
int F_125 ( const struct V_1 * V_10 )
{
int V_93 ;
F_97 ( V_90 ) ;
if ( ! V_10 )
return 0 ;
V_93 = F_114 ( V_10 ) ;
if ( F_35 ( V_87 , & V_10 -> V_19 ) )
V_93 = ! V_93 ;
return V_93 ;
}
void F_126 ( struct V_1 * V_10 , int V_93 )
{
F_97 ( V_90 ) ;
if ( ! V_10 )
return;
F_119 ( V_10 , V_93 ) ;
}
void F_127 ( struct V_1 * V_10 , int V_93 )
{
F_97 ( V_90 ) ;
if ( ! V_10 )
return;
if ( F_35 ( V_87 , & V_10 -> V_19 ) )
V_93 = ! V_93 ;
F_119 ( V_10 , V_93 ) ;
}
void F_128 ( struct V_101 * V_102 )
{
F_129 ( & V_103 ) ;
F_21 ( & V_102 -> V_25 , & V_104 ) ;
F_130 ( & V_103 ) ;
}
static struct V_1 * F_131 ( struct V_105 * V_27 , const char * V_106 ,
unsigned int V_107 ,
enum V_108 * V_19 )
{
static const char * V_109 [] = { L_29 , L_30 } ;
char V_110 [ 32 ] ;
enum V_111 V_112 ;
struct V_1 * V_10 ;
unsigned int V_113 ;
for ( V_113 = 0 ; V_113 < F_132 ( V_109 ) ; V_113 ++ ) {
if ( V_106 )
snprintf ( V_110 , 32 , L_31 , V_106 , V_109 [ V_113 ] ) ;
else
snprintf ( V_110 , 32 , L_32 , V_109 [ V_113 ] ) ;
V_10 = F_133 ( V_27 -> V_61 , V_110 , V_107 ,
& V_112 ) ;
if ( ! F_83 ( V_10 ) || ( F_84 ( V_10 ) == - V_85 ) )
break;
}
if ( F_83 ( V_10 ) )
return V_10 ;
if ( V_112 & V_114 )
* V_19 |= V_115 ;
return V_10 ;
}
static struct V_1 * F_134 ( struct V_105 * V_27 , const char * V_106 ,
unsigned int V_107 ,
enum V_108 * V_19 )
{
struct V_116 V_117 ;
struct V_1 * V_10 ;
V_10 = F_135 ( V_27 , V_107 , & V_117 ) ;
if ( F_83 ( V_10 ) )
return V_10 ;
if ( V_117 . V_118 && V_117 . V_119 )
* V_19 |= V_115 ;
return V_10 ;
}
static struct V_101 * F_136 ( struct V_105 * V_27 )
{
const char * V_120 = V_27 ? F_137 ( V_27 ) : NULL ;
struct V_101 * V_102 ;
F_129 ( & V_103 ) ;
F_41 (table, &gpio_lookup_list, list) {
if ( V_102 -> V_120 && V_120 ) {
if ( ! strcmp ( V_102 -> V_120 , V_120 ) )
goto V_121;
} else {
if ( V_120 == V_102 -> V_120 )
goto V_121;
}
}
V_102 = NULL ;
V_121:
F_130 ( & V_103 ) ;
return V_102 ;
}
static struct V_1 * F_138 ( struct V_105 * V_27 , const char * V_106 ,
unsigned int V_107 ,
enum V_108 * V_19 )
{
struct V_1 * V_10 = F_6 ( - V_122 ) ;
struct V_101 * V_102 ;
struct V_123 * V_124 ;
V_102 = F_136 ( V_27 ) ;
if ( ! V_102 )
return V_10 ;
for ( V_124 = & V_102 -> V_102 [ 0 ] ; V_124 -> V_125 ; V_124 ++ ) {
struct V_5 * V_6 ;
if ( V_124 -> V_107 != V_107 )
continue;
if ( V_124 -> V_106 && ( ! V_106 || strcmp ( V_124 -> V_106 , V_106 ) ) )
continue;
V_6 = F_43 ( V_124 -> V_125 ) ;
if ( ! V_6 ) {
F_20 ( V_27 , L_33 ,
V_124 -> V_125 ) ;
return F_6 ( - V_126 ) ;
}
if ( V_6 -> V_8 <= V_124 -> V_127 ) {
F_20 ( V_27 ,
L_34 ,
V_107 , V_6 -> V_8 , V_6 -> V_3 ) ;
return F_6 ( - V_9 ) ;
}
V_10 = F_5 ( V_6 , V_124 -> V_127 ) ;
* V_19 = V_124 -> V_19 ;
return V_10 ;
}
return V_10 ;
}
struct V_1 * T_4 F_139 ( struct V_105 * V_27 , const char * V_106 ,
enum V_128 V_19 )
{
return F_140 ( V_27 , V_106 , 0 , V_19 ) ;
}
struct V_1 * T_4 F_141 ( struct V_105 * V_27 ,
const char * V_106 ,
enum V_128 V_19 )
{
return F_142 ( V_27 , V_106 , 0 , V_19 ) ;
}
struct V_1 * T_4 F_143 ( struct V_105 * V_27 ,
const char * V_106 ,
unsigned int V_107 ,
enum V_128 V_19 )
{
struct V_1 * V_10 = NULL ;
int V_16 ;
enum V_108 V_129 = 0 ;
F_144 ( V_27 , L_35 , V_106 ) ;
if ( F_145 ( V_130 ) && V_27 && V_27 -> V_61 ) {
F_144 ( V_27 , L_36 ) ;
V_10 = F_131 ( V_27 , V_106 , V_107 , & V_129 ) ;
} else if ( F_145 ( V_131 ) && V_27 && F_146 ( V_27 ) ) {
F_144 ( V_27 , L_37 ) ;
V_10 = F_134 ( V_27 , V_106 , V_107 , & V_129 ) ;
}
if ( ! V_10 || V_10 == F_6 ( - V_122 ) ) {
F_144 ( V_27 , L_38 ) ;
V_10 = F_138 ( V_27 , V_106 , V_107 , & V_129 ) ;
}
if ( F_83 ( V_10 ) ) {
F_144 ( V_27 , L_39 , V_106 ) ;
return V_10 ;
}
V_16 = F_89 ( V_10 , V_106 ) ;
if ( V_16 < 0 )
return F_6 ( V_16 ) ;
if ( V_129 & V_115 )
F_16 ( V_87 , & V_10 -> V_19 ) ;
if ( V_129 & V_132 )
F_16 ( V_88 , & V_10 -> V_19 ) ;
if ( V_129 & V_133 )
F_16 ( V_89 , & V_10 -> V_19 ) ;
if ( ! ( V_19 & V_134 ) )
return V_10 ;
if ( V_19 & V_135 )
V_16 = F_111 ( V_10 ,
V_19 & V_136 ) ;
else
V_16 = F_104 ( V_10 ) ;
if ( V_16 < 0 ) {
F_144 ( V_27 , L_40 , V_106 ) ;
F_147 ( V_10 ) ;
return F_6 ( V_16 ) ;
}
return V_10 ;
}
struct V_1 * T_4 F_148 ( struct V_105 * V_27 ,
const char * V_106 ,
unsigned int V_137 ,
enum V_128 V_19 )
{
struct V_1 * V_10 ;
V_10 = F_140 ( V_27 , V_106 , V_137 , V_19 ) ;
if ( F_83 ( V_10 ) ) {
if ( F_84 ( V_10 ) == - V_122 )
return NULL ;
}
return V_10 ;
}
void F_147 ( struct V_1 * V_10 )
{
F_98 ( V_10 ) ;
}
static void F_149 ( struct V_138 * V_139 , struct V_5 * V_6 )
{
unsigned V_113 ;
unsigned V_4 = V_6 -> V_11 ;
struct V_1 * V_140 = & V_6 -> V_10 [ 0 ] ;
int V_141 ;
int V_142 ;
for ( V_113 = 0 ; V_113 < V_6 -> V_8 ; V_113 ++ , V_4 ++ , V_140 ++ ) {
if ( ! F_35 ( V_35 , & V_140 -> V_19 ) )
continue;
F_13 ( V_140 ) ;
V_141 = F_35 ( V_18 , & V_140 -> V_19 ) ;
V_142 = F_35 ( V_94 , & V_140 -> V_19 ) ;
F_150 ( V_139 , L_41 ,
V_4 , V_140 -> V_3 ,
V_141 ? L_42 : L_43 ,
V_6 -> V_91
? ( V_6 -> V_91 ( V_6 , V_113 ) ? L_44 : L_45 )
: L_46 ,
V_142 ? L_47 : L_48 ) ;
F_150 ( V_139 , L_49 ) ;
}
}
static void * F_151 ( struct V_138 * V_139 , T_5 * V_21 )
{
unsigned long V_19 ;
struct V_5 * V_6 = NULL ;
T_5 V_137 = * V_21 ;
V_139 -> V_143 = L_50 ;
F_23 ( & V_31 , V_19 ) ;
F_41 (chip, &gpio_chips, list)
if ( V_137 -- == 0 ) {
F_24 ( & V_31 , V_19 ) ;
return V_6 ;
}
F_24 ( & V_31 , V_19 ) ;
return NULL ;
}
static void * F_152 ( struct V_138 * V_139 , void * V_144 , T_5 * V_21 )
{
unsigned long V_19 ;
struct V_5 * V_6 = V_144 ;
void * V_71 = NULL ;
F_23 ( & V_31 , V_19 ) ;
if ( F_153 ( & V_6 -> V_25 , & V_22 ) )
V_71 = NULL ;
else
V_71 = F_19 ( V_6 -> V_25 . V_145 , struct V_5 , V_25 ) ;
F_24 ( & V_31 , V_19 ) ;
V_139 -> V_143 = L_49 ;
++ * V_21 ;
return V_71 ;
}
static void F_154 ( struct V_138 * V_139 , void * V_144 )
{
}
static int F_155 ( struct V_138 * V_139 , void * V_144 )
{
struct V_5 * V_6 = V_144 ;
struct V_105 * V_27 ;
F_150 ( V_139 , L_51 , ( char * ) V_139 -> V_143 ,
V_6 -> V_11 , V_6 -> V_11 + V_6 -> V_8 - 1 ) ;
V_27 = V_6 -> V_27 ;
if ( V_27 )
F_150 ( V_139 , L_52 , V_27 -> V_146 ? V_27 -> V_146 -> V_37 : L_53 ,
F_137 ( V_27 ) ) ;
if ( V_6 -> V_3 )
F_150 ( V_139 , L_54 , V_6 -> V_3 ) ;
if ( V_6 -> V_44 )
F_150 ( V_139 , L_55 ) ;
F_150 ( V_139 , L_56 ) ;
if ( V_6 -> V_147 )
V_6 -> V_147 ( V_139 , V_6 ) ;
else
F_149 ( V_139 , V_6 ) ;
return 0 ;
}
static int F_156 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
return F_157 ( V_149 , & V_150 ) ;
}
static int T_6 F_158 ( void )
{
( void ) F_159 ( L_30 , V_151 | V_152 ,
NULL , NULL , & V_153 ) ;
return 0 ;
}
