static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 , V_2 -> V_3 ) ;
F_3 ( L_2 , V_2 -> V_4 ) ;
F_2 ( L_3 , V_2 -> V_5 ) ;
F_2 ( L_4 ,
V_2 -> V_6 , V_2 -> V_7 ) ;
F_2 ( L_5 , V_2 -> V_8 ) ;
}
struct V_1 * F_4 (
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
void * V_35 ;
int V_36 ;
F_3 ( L_6 ,
V_37 , V_11 , V_13 ) ;
V_19 = (struct V_1 * ) NULL ;
V_21 = F_5 ( & V_19 [ 1 ] , sizeof( * V_21 ) ) ;
V_24 = F_5 ( & V_21 [ V_11 ] , sizeof( * V_24 ) ) ;
V_31 = V_11 * V_13 ;
V_27 = F_5 ( & V_24 [ V_31 ] , sizeof( * V_27 ) ) ;
if ( V_17 > 0 ) {
V_31 *= V_17 ;
V_35 = F_5 ( & V_27 [ V_31 ] , V_9 ) ;
} else {
V_35 = F_5 ( V_27 , V_9 ) ;
}
V_30 = ( ( unsigned long ) V_35 ) + V_9 ;
V_19 = F_6 ( V_30 , V_38 ) ;
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
F_3 ( L_8 ,
V_37 , V_19 , V_35 + V_9 ) ;
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
F_3 ( L_11
L_12 ,
V_37 , V_32 , V_22 , V_33 ,
V_26 , V_26 -> V_42 ) ;
if ( ( V_17 == 0 ) || ( V_16 == NULL ) )
continue;
V_26 -> V_45 = V_17 ;
V_28 = & V_27 [ V_33 * V_11 * V_17 ] ;
V_26 -> V_46 = V_28 ;
F_3 ( L_13 ,
V_37 , V_26 -> V_46 ) ;
for ( V_34 = 0 ; V_34 < V_17 ; V_34 ++ ) {
V_29 = & V_28 [ V_34 ] ;
V_29 -> V_34 = V_16 [ V_34 ] . V_34 ;
V_29 -> V_47 = V_16 [ V_34 ] . V_47 ;
V_29 -> V_48 = V_16 [ V_34 ] . V_48 ;
V_29 -> V_33 = V_26 ;
F_3 ( L_14
L_15 ,
V_37 , V_29 , V_29 -> V_34 . V_42 ,
& V_16 [ V_34 ] ,
V_16 [ V_34 ] . V_34 . V_42
) ;
}
}
}
V_19 -> V_49 = V_50 ;
V_36 = F_7 ( V_19 ) ;
if ( V_36 ) {
F_8 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
void F_9 ( struct V_1 * V_51 )
{
F_10 ( V_51 ) ;
}
static struct V_1 * F_11 ( struct V_52 * V_5 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
F_12 ( L_16 , V_37 ) ;
F_13 (item, &edac_device_list) {
V_2 = F_14 ( V_54 , struct V_1 , V_55 ) ;
if ( V_2 -> V_5 == V_5 )
return V_2 ;
}
return NULL ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_53 * V_54 , * V_56 ;
struct V_1 * V_57 ;
V_56 = & V_58 ;
V_57 = F_11 ( V_2 -> V_5 ) ;
if ( F_16 ( V_57 != NULL ) )
goto V_59;
F_13 (item, &edac_device_list) {
V_57 = F_14 ( V_54 , struct V_1 , V_55 ) ;
if ( V_57 -> V_3 >= V_2 -> V_3 ) {
if ( F_16 ( V_57 -> V_3 == V_2 -> V_3 ) )
goto V_60;
V_56 = V_54 ;
break;
}
}
F_17 ( & V_2 -> V_55 , V_56 ) ;
return 0 ;
V_59:
F_18 ( V_61 , V_62 ,
L_17 ,
F_19 ( V_57 -> V_5 ) , F_20 ( V_57 ) ,
V_57 -> V_6 , V_57 -> V_7 , V_57 -> V_3 ) ;
return 1 ;
V_60:
F_18 ( V_61 , V_62 ,
L_18
L_19 , V_57 -> V_3 ,
V_37 ) ;
return 1 ;
}
static void F_21 ( struct V_1
* V_63 )
{
F_22 ( & V_63 -> V_55 ) ;
F_23 () ;
F_24 ( & V_63 -> V_55 ) ;
}
static void F_25 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_26 ( V_65 ) ;
struct V_1 * V_2 = F_27 ( V_67 ) ;
F_28 ( & V_68 ) ;
if ( V_2 -> V_49 == V_69 ) {
F_29 ( & V_68 ) ;
return;
}
if ( ( V_2 -> V_49 == V_70 ) &&
( V_2 -> V_4 != NULL ) ) {
V_2 -> V_4 ( V_2 ) ;
}
F_29 ( & V_68 ) ;
if ( V_2 -> V_71 == 1000 )
F_30 ( V_72 , & V_2 -> V_73 ,
F_31 ( V_2 -> V_74 ) ) ;
else
F_30 ( V_72 , & V_2 -> V_73 ,
V_2 -> V_74 ) ;
}
void F_32 ( struct V_1 * V_2 ,
unsigned V_75 )
{
F_12 ( L_16 , V_37 ) ;
V_2 -> V_71 = V_75 ;
V_2 -> V_74 = F_33 ( V_75 ) ;
F_34 ( & V_2 -> V_73 , F_25 ) ;
if ( V_2 -> V_71 == 1000 )
F_30 ( V_72 , & V_2 -> V_73 ,
F_31 ( V_2 -> V_74 ) ) ;
else
F_30 ( V_72 , & V_2 -> V_73 ,
V_2 -> V_74 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
int V_76 ;
V_76 = F_36 ( & V_2 -> V_73 ) ;
if ( V_76 == 0 ) {
F_37 ( V_72 ) ;
}
}
void F_38 ( struct V_1 * V_2 ,
unsigned long V_77 )
{
F_35 ( V_2 ) ;
F_28 ( & V_68 ) ;
F_32 ( V_2 , V_77 ) ;
F_29 ( & V_68 ) ;
}
int F_39 ( void )
{
static T_1 V_78 = F_40 ( 0 ) ;
return F_41 ( & V_78 ) - 1 ;
}
int F_42 ( struct V_1 * V_2 )
{
F_12 ( L_16 , V_37 ) ;
#ifdef F_43
if ( V_79 >= 3 )
F_1 ( V_2 ) ;
#endif
F_28 ( & V_68 ) ;
if ( F_15 ( V_2 ) )
goto V_59;
V_2 -> V_80 = V_81 ;
if ( F_44 ( V_2 ) ) {
F_45 ( V_2 , V_61 ,
L_20 ) ;
goto V_60;
}
if ( V_2 -> V_4 != NULL ) {
V_2 -> V_49 = V_70 ;
F_32 ( V_2 , 1000 ) ;
} else {
V_2 -> V_49 = V_82 ;
}
F_45 ( V_2 , V_83 ,
L_21
L_22 ,
V_2 -> V_6 ,
V_2 -> V_7 ,
F_20 ( V_2 ) ,
F_46 ( V_2 -> V_49 ) ) ;
F_29 ( & V_68 ) ;
return 0 ;
V_60:
F_21 ( V_2 ) ;
V_59:
F_29 ( & V_68 ) ;
return 1 ;
}
struct V_1 * F_47 ( struct V_52 * V_5 )
{
struct V_1 * V_2 ;
F_12 ( L_16 , V_37 ) ;
F_28 ( & V_68 ) ;
V_2 = F_11 ( V_5 ) ;
if ( V_2 == NULL ) {
F_29 ( & V_68 ) ;
return NULL ;
}
V_2 -> V_49 = V_69 ;
F_21 ( V_2 ) ;
F_29 ( & V_68 ) ;
F_35 ( V_2 ) ;
F_48 ( V_2 ) ;
F_18 ( V_83 , V_62 ,
L_23 ,
V_2 -> V_3 ,
V_2 -> V_6 , V_2 -> V_7 , F_20 ( V_2 ) ) ;
return V_2 ;
}
static inline int F_49 ( struct V_1 * V_2 )
{
return V_2 -> V_40 ;
}
static inline int F_50 ( struct V_1 * V_2 )
{
return V_2 -> V_41 ;
}
static inline int F_51 ( struct V_1
* V_2 )
{
return V_2 -> V_84 ;
}
void F_52 ( struct V_1 * V_2 ,
int V_85 , int V_86 , const char * V_87 )
{
struct V_20 * V_32 ;
struct V_23 * V_33 = NULL ;
if ( ( V_85 >= V_2 -> V_11 ) || ( V_85 < 0 ) ) {
F_45 ( V_2 , V_88 ,
L_24
L_25 , V_85 ,
V_2 -> V_11 ) ;
return;
}
V_32 = V_2 -> V_39 + V_85 ;
if ( ( V_86 >= V_32 -> V_13 ) || ( V_86 < 0 ) ) {
F_45 ( V_2 , V_88 ,
L_26
L_27 ,
V_85 , V_86 ,
V_32 -> V_13 ) ;
return;
}
if ( V_32 -> V_13 > 0 ) {
V_33 = V_32 -> V_44 + V_86 ;
V_33 -> V_89 . V_90 ++ ;
}
V_32 -> V_89 . V_90 ++ ;
V_2 -> V_89 . V_90 ++ ;
if ( F_49 ( V_2 ) )
F_45 ( V_2 , V_61 ,
L_28 ,
V_2 -> V_7 , V_32 -> V_42 ,
V_33 ? V_33 -> V_42 : L_29 , V_87 ) ;
}
void F_53 ( struct V_1 * V_2 ,
int V_85 , int V_86 , const char * V_87 )
{
struct V_20 * V_32 ;
struct V_23 * V_33 = NULL ;
if ( ( V_85 >= V_2 -> V_11 ) || ( V_85 < 0 ) ) {
F_45 ( V_2 , V_88 ,
L_24
L_25 , V_85 ,
V_2 -> V_11 ) ;
return;
}
V_32 = V_2 -> V_39 + V_85 ;
if ( ( V_86 >= V_32 -> V_13 ) || ( V_86 < 0 ) ) {
F_45 ( V_2 , V_88 ,
L_26
L_27 ,
V_85 , V_86 ,
V_32 -> V_13 ) ;
return;
}
if ( V_32 -> V_13 > 0 ) {
V_33 = V_32 -> V_44 + V_86 ;
V_33 -> V_89 . V_91 ++ ;
}
V_32 -> V_89 . V_91 ++ ;
V_2 -> V_89 . V_91 ++ ;
if ( F_50 ( V_2 ) )
F_45 ( V_2 , V_92 ,
L_30 ,
V_2 -> V_7 , V_32 -> V_42 ,
V_33 ? V_33 -> V_42 : L_29 , V_87 ) ;
if ( F_51 ( V_2 ) )
F_54 ( L_31 ,
V_2 -> V_7 , V_32 -> V_42 ,
V_33 ? V_33 -> V_42 : L_29 , V_87 ) ;
}
