static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 3 , L_1 ,
V_2 , V_2 -> V_3 ) ;
F_2 ( 4 , L_2 , V_2 -> V_4 ) ;
F_2 ( 3 , L_3 , V_2 -> V_5 ) ;
F_2 ( 3 , L_4 ,
V_2 -> V_6 , V_2 -> V_7 ) ;
F_2 ( 3 , L_5 , V_2 -> V_8 ) ;
}
struct V_1 * F_3 (
unsigned V_9 ,
char * V_10 , unsigned V_11 ,
char * V_12 , unsigned V_13 ,
unsigned V_14 ,
struct V_15 * V_16 , unsigned V_17 ,
int V_18 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 , * V_22 ;
struct V_23 * V_24 , * V_25 , * V_26 ;
struct V_15 * V_27 , * V_28 , * V_29 ;
unsigned V_30 ;
unsigned V_31 ;
unsigned V_32 , V_33 , V_34 ;
void * V_35 , * V_36 ;
int V_37 ;
F_2 ( 4 , L_6 , V_11 , V_13 ) ;
V_36 = NULL ;
V_19 = F_4 ( & V_36 , sizeof( * V_19 ) , 1 ) ;
V_21 = F_4 ( & V_36 , sizeof( * V_21 ) , V_11 ) ;
V_31 = V_11 * V_13 ;
V_24 = F_4 ( & V_36 , sizeof( * V_24 ) , V_31 ) ;
if ( V_17 > 0 )
V_31 *= V_17 ;
V_27 = F_4 ( & V_36 , sizeof( * V_27 ) , V_31 ) ;
V_35 = F_4 ( & V_36 , V_9 , 1 ) ;
V_30 = ( ( unsigned long ) V_35 ) + V_9 ;
V_19 = F_5 ( V_30 , V_38 ) ;
if ( V_19 == NULL )
return NULL ;
V_21 = (struct V_20 * )
( ( ( char * ) V_19 ) + ( ( unsigned long ) V_21 ) ) ;
V_24 = (struct V_23 * )
( ( ( char * ) V_19 ) + ( ( unsigned long ) V_24 ) ) ;
V_27 = (struct V_15 * )
( ( ( char * ) V_19 ) + ( ( unsigned long ) V_27 ) ) ;
V_35 = V_9 ? ( ( ( char * ) V_19 ) + ( ( unsigned long ) V_35 ) ) : NULL ;
V_19 -> V_3 = V_18 ;
V_19 -> V_11 = V_11 ;
V_19 -> V_39 = V_21 ;
V_19 -> V_8 = V_35 ;
V_19 -> V_40 = 1 ;
V_19 -> V_41 = 1 ;
snprintf ( V_19 -> V_42 , sizeof( V_19 -> V_42 ) , L_7 , V_10 ) ;
F_2 ( 4 , L_8 ,
V_19 , V_35 + V_9 ) ;
for ( V_32 = 0 ; V_32 < V_11 ; V_32 ++ ) {
V_22 = & V_21 [ V_32 ] ;
V_22 -> V_43 = V_19 ;
V_22 -> V_13 = V_13 ;
V_25 = & V_24 [ V_32 * V_13 ] ;
V_22 -> V_44 = V_25 ;
snprintf ( V_22 -> V_42 , sizeof( V_22 -> V_42 ) ,
L_9 , V_10 , V_32 ) ;
for ( V_33 = 0 ; V_33 < V_13 ; V_33 ++ ) {
V_26 = & V_25 [ V_33 ] ;
V_26 -> V_32 = V_22 ;
snprintf ( V_26 -> V_42 , sizeof( V_26 -> V_42 ) ,
L_10 , V_12 , V_33 + V_14 ) ;
F_2 ( 4 , L_11 ,
V_32 , V_22 , V_33 , V_26 , V_26 -> V_42 ) ;
if ( ( V_17 == 0 ) || ( V_16 == NULL ) )
continue;
V_26 -> V_45 = V_17 ;
V_28 = & V_27 [ V_33 * V_11 * V_17 ] ;
V_26 -> V_46 = V_28 ;
F_2 ( 4 , L_12 ,
V_26 -> V_46 ) ;
for ( V_34 = 0 ; V_34 < V_17 ; V_34 ++ ) {
V_29 = & V_28 [ V_34 ] ;
V_29 -> V_34 = V_16 [ V_34 ] . V_34 ;
V_29 -> V_47 = V_16 [ V_34 ] . V_47 ;
V_29 -> V_48 = V_16 [ V_34 ] . V_48 ;
V_29 -> V_33 = V_26 ;
F_2 ( 4 , L_13 ,
V_29 , V_29 -> V_34 . V_42 ,
& V_16 [ V_34 ] ,
V_16 [ V_34 ] . V_34 . V_42
) ;
}
}
}
V_19 -> V_49 = V_50 ;
V_37 = F_6 ( V_19 ) ;
if ( V_37 ) {
F_7 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
void F_8 ( struct V_1 * V_51 )
{
F_9 ( V_51 ) ;
}
static struct V_1 * F_10 ( struct V_52 * V_5 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
F_2 ( 0 , L_14 ) ;
F_11 (item, &edac_device_list) {
V_2 = F_12 ( V_54 , struct V_1 , V_55 ) ;
if ( V_2 -> V_5 == V_5 )
return V_2 ;
}
return NULL ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_53 * V_54 , * V_56 ;
struct V_1 * V_57 ;
V_56 = & V_58 ;
V_57 = F_10 ( V_2 -> V_5 ) ;
if ( F_14 ( V_57 != NULL ) )
goto V_59;
F_11 (item, &edac_device_list) {
V_57 = F_12 ( V_54 , struct V_1 , V_55 ) ;
if ( V_57 -> V_3 >= V_2 -> V_3 ) {
if ( F_14 ( V_57 -> V_3 == V_2 -> V_3 ) )
goto V_60;
V_56 = V_54 ;
break;
}
}
F_15 ( & V_2 -> V_55 , V_56 ) ;
return 0 ;
V_59:
F_16 ( V_61 , V_62 ,
L_15 ,
F_17 ( V_57 -> V_5 ) , F_18 ( V_57 ) ,
V_57 -> V_6 , V_57 -> V_7 , V_57 -> V_3 ) ;
return 1 ;
V_60:
F_16 ( V_61 , V_62 ,
L_16
L_17 , V_57 -> V_3 ,
V_63 ) ;
return 1 ;
}
static void F_19 ( struct V_1
* V_64 )
{
F_20 ( & V_64 -> V_55 ) ;
F_21 () ;
F_22 ( & V_64 -> V_55 ) ;
}
static void F_23 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = F_24 ( V_66 ) ;
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_26 ( & V_69 ) ;
if ( V_2 -> V_49 == V_70 ) {
F_27 ( & V_69 ) ;
return;
}
if ( ( V_2 -> V_49 == V_71 ) &&
( V_2 -> V_4 != NULL ) ) {
V_2 -> V_4 ( V_2 ) ;
}
F_27 ( & V_69 ) ;
if ( V_2 -> V_72 == 1000 )
F_28 ( V_73 , & V_2 -> V_74 ,
F_29 ( V_2 -> V_75 ) ) ;
else
F_28 ( V_73 , & V_2 -> V_74 ,
V_2 -> V_75 ) ;
}
void F_30 ( struct V_1 * V_2 ,
unsigned V_76 )
{
F_2 ( 0 , L_14 ) ;
V_2 -> V_72 = V_76 ;
V_2 -> V_75 = F_31 ( V_76 ) ;
F_32 ( & V_2 -> V_74 , F_23 ) ;
if ( V_2 -> V_72 == 1000 )
F_28 ( V_73 , & V_2 -> V_74 ,
F_29 ( V_2 -> V_75 ) ) ;
else
F_28 ( V_73 , & V_2 -> V_74 ,
V_2 -> V_75 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
int V_77 ;
V_77 = F_34 ( & V_2 -> V_74 ) ;
if ( V_77 == 0 ) {
F_35 ( V_73 ) ;
}
}
void F_36 ( struct V_1 * V_2 ,
unsigned long V_78 )
{
F_33 ( V_2 ) ;
F_26 ( & V_69 ) ;
F_30 ( V_2 , V_78 ) ;
F_27 ( & V_69 ) ;
}
int F_37 ( void )
{
static T_1 V_79 = F_38 ( 0 ) ;
return F_39 ( & V_79 ) - 1 ;
}
int F_40 ( struct V_1 * V_2 )
{
F_2 ( 0 , L_14 ) ;
#ifdef F_41
if ( V_80 >= 3 )
F_1 ( V_2 ) ;
#endif
F_26 ( & V_69 ) ;
if ( F_13 ( V_2 ) )
goto V_59;
V_2 -> V_81 = V_82 ;
if ( F_42 ( V_2 ) ) {
F_43 ( V_2 , V_61 ,
L_18 ) ;
goto V_60;
}
if ( V_2 -> V_4 != NULL ) {
V_2 -> V_49 = V_71 ;
F_30 ( V_2 , 1000 ) ;
} else {
V_2 -> V_49 = V_83 ;
}
F_43 ( V_2 , V_84 ,
L_19 ,
V_2 -> V_6 , V_2 -> V_7 , V_2 -> F_17 ,
F_44 ( V_2 -> V_49 ) ) ;
F_27 ( & V_69 ) ;
return 0 ;
V_60:
F_19 ( V_2 ) ;
V_59:
F_27 ( & V_69 ) ;
return 1 ;
}
struct V_1 * F_45 ( struct V_52 * V_5 )
{
struct V_1 * V_2 ;
F_2 ( 0 , L_14 ) ;
F_26 ( & V_69 ) ;
V_2 = F_10 ( V_5 ) ;
if ( V_2 == NULL ) {
F_27 ( & V_69 ) ;
return NULL ;
}
V_2 -> V_49 = V_70 ;
F_19 ( V_2 ) ;
F_27 ( & V_69 ) ;
F_33 ( V_2 ) ;
F_46 ( V_2 ) ;
F_16 ( V_84 , V_62 ,
L_20 ,
V_2 -> V_3 ,
V_2 -> V_6 , V_2 -> V_7 , F_18 ( V_2 ) ) ;
return V_2 ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
return V_2 -> V_40 ;
}
static inline int F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_41 ;
}
static inline int F_49 ( struct V_1
* V_2 )
{
return V_2 -> V_85 ;
}
void F_50 ( struct V_1 * V_2 ,
int V_86 , int V_87 , const char * V_88 )
{
struct V_20 * V_32 ;
struct V_23 * V_33 = NULL ;
if ( ( V_86 >= V_2 -> V_11 ) || ( V_86 < 0 ) ) {
F_43 ( V_2 , V_89 ,
L_21
L_22 , V_86 ,
V_2 -> V_11 ) ;
return;
}
V_32 = V_2 -> V_39 + V_86 ;
if ( ( V_87 >= V_32 -> V_13 ) || ( V_87 < 0 ) ) {
F_43 ( V_2 , V_89 ,
L_23
L_24 ,
V_86 , V_87 ,
V_32 -> V_13 ) ;
return;
}
if ( V_32 -> V_13 > 0 ) {
V_33 = V_32 -> V_44 + V_87 ;
V_33 -> V_90 . V_91 ++ ;
}
V_32 -> V_90 . V_91 ++ ;
V_2 -> V_90 . V_91 ++ ;
if ( F_47 ( V_2 ) )
F_43 ( V_2 , V_61 ,
L_25 ,
V_2 -> V_7 , V_32 -> V_42 ,
V_33 ? V_33 -> V_42 : L_26 , V_88 ) ;
}
void F_51 ( struct V_1 * V_2 ,
int V_86 , int V_87 , const char * V_88 )
{
struct V_20 * V_32 ;
struct V_23 * V_33 = NULL ;
if ( ( V_86 >= V_2 -> V_11 ) || ( V_86 < 0 ) ) {
F_43 ( V_2 , V_89 ,
L_21
L_22 , V_86 ,
V_2 -> V_11 ) ;
return;
}
V_32 = V_2 -> V_39 + V_86 ;
if ( ( V_87 >= V_32 -> V_13 ) || ( V_87 < 0 ) ) {
F_43 ( V_2 , V_89 ,
L_23
L_24 ,
V_86 , V_87 ,
V_32 -> V_13 ) ;
return;
}
if ( V_32 -> V_13 > 0 ) {
V_33 = V_32 -> V_44 + V_87 ;
V_33 -> V_90 . V_92 ++ ;
}
V_32 -> V_90 . V_92 ++ ;
V_2 -> V_90 . V_92 ++ ;
if ( F_48 ( V_2 ) )
F_43 ( V_2 , V_93 ,
L_27 ,
V_2 -> V_7 , V_32 -> V_42 ,
V_33 ? V_33 -> V_42 : L_26 , V_88 ) ;
if ( F_49 ( V_2 ) )
F_52 ( L_28 ,
V_2 -> V_7 , V_32 -> V_42 ,
V_33 ? V_33 -> V_42 : L_26 , V_88 ) ;
}
