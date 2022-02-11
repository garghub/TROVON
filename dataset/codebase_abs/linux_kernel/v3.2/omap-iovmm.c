static unsigned int F_1 ( const struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return 0 ;
return V_2 -> V_4 -> V_5 ;
}
static T_1 F_2 ( const struct V_1 * V_2 )
{
unsigned int V_6 , V_7 = 0 ;
struct V_8 * V_9 ;
if ( ! V_2 )
return 0 ;
F_3 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_10 ;
V_10 = V_9 -> V_11 + V_9 -> V_5 ;
if ( ! F_4 ( V_10 ) ) {
F_5 ( L_1 ,
V_12 , V_6 , V_10 , V_9 -> V_5 ) ;
return 0 ;
}
if ( V_6 && V_9 -> V_5 ) {
F_5 ( L_2
L_3 , V_12 , V_6 ) ;
return 0 ;
}
V_7 += V_10 ;
}
return V_7 ;
}
static unsigned F_6 ( T_2 V_13 )
{
int V_6 ;
unsigned V_14 [] = { V_15 , V_16 , V_17 , V_18 , } ;
for ( V_6 = 0 ; V_6 < F_7 ( V_14 ) && V_13 & ( V_14 [ V_6 ] - 1 ) ; V_6 ++ )
;
return ( V_6 < F_7 ( V_14 ) ) ? V_14 [ V_6 ] : 0 ;
}
static unsigned F_8 ( T_1 V_10 , T_2 V_19 , T_2 V_20 )
{
unsigned V_21 = 0 , V_22 ;
if ( ! F_9 ( V_10 , V_23 ) ) {
F_5 ( L_4 , V_12 , V_10 ) ;
return 0 ;
}
while ( V_10 ) {
V_22 = F_6 ( V_19 | V_20 ) ;
V_22 = F_10 ( unsigned , V_22 , F_11 ( V_10 ) ) ;
V_21 ++ ;
V_19 += V_22 ;
V_20 += V_22 ;
V_10 -= V_22 ;
}
return V_21 ;
}
static struct V_1 * F_12 ( const T_1 V_10 , T_2 V_24 ,
T_2 V_19 , T_2 V_20 )
{
unsigned int V_21 ;
int V_25 ;
struct V_1 * V_2 ;
if ( ! V_10 )
return F_13 ( - V_26 ) ;
if ( ! F_9 ( V_10 , V_23 ) )
return F_13 ( - V_26 ) ;
if ( V_24 & V_27 ) {
V_21 = F_8 ( V_10 , V_19 , V_20 ) ;
if ( ! V_21 )
return F_13 ( - V_26 ) ;
} else
V_21 = V_10 / V_23 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_13 ( - V_29 ) ;
V_25 = F_15 ( V_2 , V_21 , V_28 ) ;
if ( V_25 ) {
F_16 ( V_2 ) ;
return F_13 ( V_25 ) ;
}
F_17 ( L_5 , V_12 , V_2 , V_21 ) ;
return V_2 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_19 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( L_6 , V_12 , V_2 ) ;
}
static void * F_20 ( const struct V_1 * V_2 )
{
T_2 V_30 ;
T_1 V_7 ;
unsigned int V_6 ;
struct V_8 * V_9 ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
V_34 = F_21 ( V_35 ) ;
if ( ! V_34 )
return F_13 ( - V_26 ) ;
V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return F_13 ( - V_26 ) ;
V_32 = F_22 ( V_7 , V_36 , V_37 , V_38 ) ;
if ( ! V_32 )
return F_13 ( - V_29 ) ;
V_30 = ( T_2 ) V_32 -> V_13 ;
F_3 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_10 ;
T_2 V_20 ;
int V_25 ;
V_20 = F_23 ( V_9 ) - V_9 -> V_5 ;
V_10 = V_9 -> V_11 + V_9 -> V_5 ;
F_24 ( V_10 != V_23 ) ;
V_25 = F_25 ( V_30 , V_20 , V_34 ) ;
if ( V_25 )
goto V_39;
V_30 += V_10 ;
}
F_26 ( ( unsigned long ) V_32 -> V_13 ,
( unsigned long ) ( V_32 -> V_13 + V_7 ) ) ;
return V_32 -> V_13 ;
V_39:
F_27 ( 1 ) ;
F_28 ( V_32 -> V_13 ) ;
return F_13 ( - V_40 ) ;
}
static inline void F_29 ( const void * V_30 )
{
F_28 ( V_30 ) ;
}
static struct V_41 * F_30 ( struct V_42 * V_43 ,
const T_2 V_19 )
{
struct V_41 * V_44 ;
F_31 (tmp, &obj->mmap, list) {
if ( ( V_19 >= V_44 -> V_45 ) && ( V_19 < V_44 -> V_46 ) ) {
T_1 V_47 ;
V_47 = V_44 -> V_46 - V_44 -> V_45 ;
F_32 ( V_43 -> V_48 , L_7 ,
V_12 , V_44 -> V_45 , V_19 , V_44 -> V_46 , V_47 ,
V_44 -> V_24 ) ;
return V_44 ;
}
}
return NULL ;
}
struct V_41 * F_33 ( struct V_42 * V_43 , T_2 V_19 )
{
struct V_41 * V_49 ;
F_34 ( & V_43 -> V_50 ) ;
V_49 = F_30 ( V_43 , V_19 ) ;
F_35 ( & V_43 -> V_50 ) ;
return V_49 ;
}
static struct V_41 * F_36 ( struct V_42 * V_43 , T_2 V_19 ,
T_1 V_10 , T_2 V_24 )
{
struct V_41 * V_32 , * V_44 ;
T_2 V_51 , V_52 , V_53 ;
if ( ! V_43 || ! V_10 )
return F_13 ( - V_26 ) ;
V_51 = V_19 ;
V_53 = V_23 ;
if ( ~ V_24 & V_54 ) {
V_51 = V_43 -> V_45 ? V_43 -> V_45 : V_53 ;
if ( V_24 & V_27 )
V_53 = F_11 ( V_10 ) ;
V_51 = F_37 ( V_51 , V_53 ) ;
} else if ( V_51 < V_43 -> V_45 || V_51 > V_43 -> V_46 ||
V_43 -> V_46 - V_51 < V_10 ) {
return F_13 ( - V_26 ) ;
}
V_44 = NULL ;
if ( F_38 ( & V_43 -> V_55 ) )
goto V_56;
V_52 = 0 ;
F_31 (tmp, &obj->mmap, list) {
if ( V_52 > V_51 )
break;
if ( V_44 -> V_45 > V_51 && ( V_44 -> V_45 - V_51 ) >= V_10 )
goto V_56;
if ( V_44 -> V_46 >= V_51 && ~ V_24 & V_54 )
V_51 = F_37 ( V_44 -> V_46 + 1 , V_53 ) ;
V_52 = V_44 -> V_46 ;
}
if ( ( V_51 >= V_52 ) && ( V_43 -> V_46 - V_51 >= V_10 ) )
goto V_56;
F_32 ( V_43 -> V_48 , L_8 ,
V_12 , V_19 , V_10 , V_24 ) ;
return F_13 ( - V_26 ) ;
V_56:
V_32 = F_39 ( V_57 , V_28 ) ;
if ( ! V_32 )
return F_13 ( - V_29 ) ;
V_32 -> V_58 = V_43 ;
V_32 -> V_45 = V_51 ;
V_32 -> V_46 = V_51 + V_10 ;
V_32 -> V_24 = V_24 ;
if ( V_44 )
F_40 ( & V_32 -> V_59 , & V_44 -> V_59 ) ;
else
F_41 ( & V_32 -> V_59 , & V_43 -> V_55 ) ;
F_32 ( V_43 -> V_48 , L_9 ,
V_12 , V_32 -> V_45 , V_51 , V_32 -> V_46 , V_10 , V_24 ) ;
return V_32 ;
}
static void F_42 ( struct V_42 * V_43 , struct V_41 * V_49 )
{
T_1 V_10 ;
F_24 ( ! V_43 || ! V_49 ) ;
V_10 = V_49 -> V_46 - V_49 -> V_45 ;
F_32 ( V_43 -> V_48 , L_10 ,
V_12 , V_49 -> V_45 , V_49 -> V_46 , V_10 , V_49 -> V_24 ) ;
F_43 ( & V_49 -> V_59 ) ;
F_44 ( V_57 , V_49 ) ;
}
void * F_45 ( struct V_42 * V_43 , T_2 V_19 )
{
void * V_30 = NULL ;
struct V_41 * V_49 ;
F_34 ( & V_43 -> V_50 ) ;
V_49 = F_30 ( V_43 , V_19 ) ;
if ( ! V_49 ) {
F_32 ( V_43 -> V_48 , L_11 , V_12 , V_19 ) ;
goto V_60;
}
V_30 = V_49 -> V_30 ;
V_60:
F_35 ( & V_43 -> V_50 ) ;
return V_30 ;
}
static void F_46 ( struct V_1 * V_2 , void * V_61 )
{
unsigned int V_6 ;
struct V_8 * V_9 ;
void * V_30 = V_61 ;
void * va_end ;
F_3 (sgt->sgl, sg, sgt->nents, i) {
struct V_62 * V_63 ;
const T_1 V_10 = V_23 ;
V_63 = F_47 ( V_30 ) ;
F_24 ( ! V_63 ) ;
F_48 ( V_9 , V_63 , V_10 , 0 ) ;
V_30 += V_10 ;
}
va_end = V_61 + V_23 * V_6 ;
}
static inline void F_49 ( struct V_1 * V_2 )
{
F_24 ( ! V_2 ) ;
}
static int F_50 ( struct V_64 * V_65 , struct V_41 * V_32 ,
const struct V_1 * V_2 , T_2 V_24 )
{
int V_25 ;
unsigned int V_6 , V_66 ;
struct V_8 * V_9 ;
T_2 V_19 = V_32 -> V_45 ;
int V_67 ;
if ( ! V_65 || ! V_2 )
return - V_26 ;
F_24 ( ! F_51 ( V_2 ) ) ;
F_3 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_20 ;
T_1 V_10 ;
V_20 = F_23 ( V_9 ) - V_9 -> V_5 ;
V_10 = V_9 -> V_11 + V_9 -> V_5 ;
V_24 &= ~ V_68 ;
if ( F_52 ( V_10 ) < 0 )
goto V_39;
V_67 = F_53 ( V_10 ) ;
F_17 ( L_12 , V_12 ,
V_6 , V_19 , V_20 , V_10 ) ;
V_25 = F_54 ( V_65 , V_19 , V_20 , V_67 , V_24 ) ;
if ( V_25 )
goto V_39;
V_19 += V_10 ;
}
return 0 ;
V_39:
V_19 = V_32 -> V_45 ;
F_3 (sgt->sgl, sg, i, j) {
T_1 V_10 ;
V_10 = V_9 -> V_11 + V_9 -> V_5 ;
V_67 = F_53 ( V_10 ) ;
F_55 ( V_65 , V_19 , V_67 ) ;
V_19 += V_10 ;
}
return V_25 ;
}
static void F_56 ( struct V_64 * V_65 , struct V_42 * V_43 ,
struct V_41 * V_49 )
{
T_2 V_51 ;
T_1 V_7 = V_49 -> V_46 - V_49 -> V_45 ;
const struct V_1 * V_2 = V_49 -> V_2 ;
struct V_8 * V_9 ;
int V_6 , V_25 ;
F_24 ( ! F_51 ( V_2 ) ) ;
F_24 ( ( ! V_7 ) || ! F_9 ( V_7 , V_23 ) ) ;
V_51 = V_49 -> V_45 ;
F_3 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_10 ;
int V_67 ;
V_10 = V_9 -> V_11 + V_9 -> V_5 ;
V_67 = F_53 ( V_10 ) ;
V_25 = F_55 ( V_65 , V_51 , V_67 ) ;
if ( V_25 < 0 )
break;
F_32 ( V_43 -> V_48 , L_13 ,
V_12 , V_51 , V_10 , V_49 -> V_24 ) ;
F_24 ( ! F_9 ( V_10 , V_23 ) ) ;
V_7 -= V_10 ;
V_51 += V_10 ;
}
F_24 ( V_7 ) ;
}
static struct V_1 * F_57 ( struct V_64 * V_65 ,
struct V_42 * V_43 , const T_2 V_19 ,
void (* F_58)( const void * ) , T_2 V_24 )
{
struct V_1 * V_2 = NULL ;
struct V_41 * V_49 ;
if ( ! F_9 ( V_19 , V_23 ) ) {
F_59 ( V_43 -> V_48 , L_14 , V_12 , V_19 ) ;
return NULL ;
}
F_34 ( & V_43 -> V_50 ) ;
V_49 = F_30 ( V_43 , V_19 ) ;
if ( ! V_49 ) {
F_32 ( V_43 -> V_48 , L_11 , V_12 , V_19 ) ;
goto V_60;
}
if ( ( V_49 -> V_24 & V_24 ) != V_24 ) {
F_59 ( V_43 -> V_48 , L_15 , V_12 ,
V_49 -> V_24 ) ;
goto V_60;
}
V_2 = (struct V_1 * ) V_49 -> V_2 ;
F_56 ( V_65 , V_43 , V_49 ) ;
F_58 ( V_49 -> V_30 ) ;
F_32 ( V_43 -> V_48 , L_7 , V_12 ,
V_49 -> V_45 , V_19 , V_49 -> V_46 ,
V_49 -> V_46 - V_49 -> V_45 , V_49 -> V_24 ) ;
F_42 ( V_43 , V_49 ) ;
V_60:
F_35 ( & V_43 -> V_50 ) ;
return V_2 ;
}
static T_2 F_60 ( struct V_64 * V_65 , struct V_42 * V_43 ,
T_2 V_19 , const struct V_1 * V_2 , void * V_30 ,
T_1 V_10 , T_2 V_24 )
{
int V_25 = - V_29 ;
struct V_41 * V_32 ;
F_34 ( & V_43 -> V_50 ) ;
V_32 = F_36 ( V_43 , V_19 , V_10 , V_24 ) ;
if ( F_61 ( V_32 ) ) {
V_25 = F_62 ( V_32 ) ;
goto V_69;
}
V_32 -> V_30 = V_30 ;
V_32 -> V_2 = V_2 ;
if ( F_50 ( V_65 , V_32 , V_2 , V_32 -> V_24 ) )
goto V_70;
F_35 ( & V_43 -> V_50 ) ;
F_32 ( V_43 -> V_48 , L_16 ,
V_12 , V_32 -> V_45 , V_10 , V_32 -> V_24 , V_30 ) ;
return V_32 -> V_45 ;
V_70:
F_42 ( V_43 , V_32 ) ;
V_69:
F_35 ( & V_43 -> V_50 ) ;
return V_25 ;
}
static inline T_2
F_63 ( struct V_64 * V_65 , struct V_42 * V_43 ,
T_2 V_19 , const struct V_1 * V_2 ,
void * V_30 , T_1 V_10 , T_2 V_24 )
{
return F_60 ( V_65 , V_43 , V_19 , V_2 , V_30 , V_10 , V_24 ) ;
}
T_2 F_64 ( struct V_64 * V_65 , struct V_42 * V_43 , T_2 V_19 ,
const struct V_1 * V_2 , T_2 V_24 )
{
T_1 V_10 ;
void * V_30 = NULL ;
if ( ! V_43 || ! V_43 -> V_48 || ! V_2 )
return - V_26 ;
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 )
return - V_26 ;
V_10 = F_65 ( V_10 ) ;
if ( V_24 & V_71 ) {
V_30 = F_20 ( V_2 ) ;
if ( F_61 ( V_30 ) )
return F_62 ( V_30 ) ;
}
V_24 |= V_72 ;
V_24 |= V_71 ;
V_19 = F_63 ( V_65 , V_43 , V_19 , V_2 , V_30 , V_10 , V_24 ) ;
if ( F_66 ( V_19 ) )
F_29 ( V_30 ) ;
return V_19 + F_1 ( V_2 ) ;
}
struct V_1 *
F_67 ( struct V_64 * V_65 , struct V_42 * V_43 , T_2 V_19 )
{
struct V_1 * V_2 ;
V_19 &= V_73 ;
V_2 = F_57 ( V_65 , V_43 , V_19 , F_29 ,
V_72 | V_71 ) ;
if ( ! V_2 )
F_32 ( V_43 -> V_48 , L_17 , V_12 ) ;
return V_2 ;
}
T_2
F_68 ( struct V_64 * V_65 , struct V_42 * V_43 , T_2 V_19 ,
T_1 V_10 , T_2 V_24 )
{
void * V_30 ;
struct V_1 * V_2 ;
if ( ! V_43 || ! V_43 -> V_48 || ! V_10 )
return - V_26 ;
V_10 = F_65 ( V_10 ) ;
V_30 = F_69 ( V_10 ) ;
if ( ! V_30 )
return - V_29 ;
V_24 |= V_72 ;
V_24 |= V_74 ;
V_2 = F_12 ( V_10 , V_24 , V_19 , 0 ) ;
if ( F_61 ( V_2 ) ) {
V_19 = F_62 ( V_2 ) ;
goto V_75;
}
F_46 ( V_2 , V_30 ) ;
V_19 = F_63 ( V_65 , V_43 , V_19 , V_2 , V_30 , V_10 , V_24 ) ;
if ( F_66 ( V_19 ) )
goto V_76;
return V_19 ;
V_76:
F_49 ( V_2 ) ;
F_18 ( V_2 ) ;
V_75:
F_70 ( V_30 ) ;
return V_19 ;
}
void F_71 ( struct V_64 * V_65 , struct V_42 * V_43 ,
const T_2 V_19 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( V_65 , V_43 , V_19 , F_70 ,
V_72 | V_74 ) ;
if ( ! V_2 )
F_32 ( V_43 -> V_48 , L_17 , V_12 ) ;
F_18 ( V_2 ) ;
}
static int T_3 F_72 ( void )
{
const unsigned long V_24 = V_77 ;
struct V_78 * V_79 ;
V_79 = F_73 ( L_18 , sizeof( struct V_41 ) , 0 ,
V_24 , NULL ) ;
if ( ! V_79 )
return - V_29 ;
V_57 = V_79 ;
return 0 ;
}
static void T_4 F_74 ( void )
{
F_75 ( V_57 ) ;
}
