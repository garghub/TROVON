static T_1 F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 , V_4 = 0 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return 0 ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_7 ;
V_7 = V_6 -> V_8 ;
if ( ! F_3 ( V_7 ) ) {
F_4 ( L_1 ,
V_9 , V_3 , V_7 ) ;
return 0 ;
}
V_4 += V_7 ;
}
return V_4 ;
}
static unsigned F_5 ( T_2 V_10 )
{
int V_3 ;
unsigned V_11 [] = { V_12 , V_13 , V_14 , V_15 , } ;
for ( V_3 = 0 ; V_3 < F_6 ( V_11 ) && V_10 & ( V_11 [ V_3 ] - 1 ) ; V_3 ++ )
;
return ( V_3 < F_6 ( V_11 ) ) ? V_11 [ V_3 ] : 0 ;
}
static unsigned F_7 ( T_1 V_7 , T_2 V_16 , T_2 V_17 )
{
unsigned V_18 = 0 , V_19 ;
if ( ! F_8 ( V_7 , V_20 ) ) {
F_4 ( L_2 , V_9 , V_7 ) ;
return 0 ;
}
while ( V_7 ) {
V_19 = F_5 ( V_16 | V_17 ) ;
V_19 = F_9 ( unsigned , V_19 , F_10 ( V_7 ) ) ;
V_18 ++ ;
V_16 += V_19 ;
V_17 += V_19 ;
V_7 -= V_19 ;
}
return V_18 ;
}
static struct V_1 * F_11 ( const T_1 V_7 , T_2 V_21 ,
T_2 V_16 , T_2 V_17 )
{
unsigned int V_18 ;
int V_22 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return F_12 ( - V_23 ) ;
if ( ! F_8 ( V_7 , V_20 ) )
return F_12 ( - V_23 ) ;
if ( V_21 & V_24 ) {
V_18 = F_7 ( V_7 , V_16 , V_17 ) ;
if ( ! V_18 )
return F_12 ( - V_23 ) ;
} else
V_18 = V_7 / V_20 ;
V_2 = F_13 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return F_12 ( - V_26 ) ;
V_22 = F_14 ( V_2 , V_18 , V_25 ) ;
if ( V_22 ) {
F_15 ( V_2 ) ;
return F_12 ( V_22 ) ;
}
F_16 ( L_3 , V_9 , V_2 , V_18 ) ;
return V_2 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_18 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( L_4 , V_9 , V_2 ) ;
}
static void * F_19 ( const struct V_1 * V_2 )
{
T_2 V_27 ;
T_1 V_4 ;
unsigned int V_3 ;
struct V_5 * V_6 ;
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
V_31 = F_20 ( V_32 ) ;
if ( ! V_31 )
return F_12 ( - V_23 ) ;
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 )
return F_12 ( - V_23 ) ;
V_29 = F_21 ( V_4 , V_33 , V_34 , V_35 ) ;
if ( ! V_29 )
return F_12 ( - V_26 ) ;
V_27 = ( T_2 ) V_29 -> V_10 ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_7 ;
T_2 V_17 ;
int V_22 ;
V_17 = F_22 ( V_6 ) ;
V_7 = V_6 -> V_8 ;
F_23 ( V_7 != V_20 ) ;
V_22 = F_24 ( V_27 , V_17 , V_31 ) ;
if ( V_22 )
goto V_36;
V_27 += V_7 ;
}
F_25 ( ( unsigned long ) V_29 -> V_10 ,
( unsigned long ) ( V_29 -> V_10 + V_4 ) ) ;
return V_29 -> V_10 ;
V_36:
F_26 ( 1 ) ;
F_27 ( V_29 -> V_10 ) ;
return F_12 ( - V_37 ) ;
}
static inline void F_28 ( const void * V_27 )
{
F_27 ( V_27 ) ;
}
static struct V_38 * F_29 ( struct V_39 * V_40 , const T_2 V_16 )
{
struct V_38 * V_41 ;
F_30 (tmp, &obj->mmap, list) {
if ( ( V_16 >= V_41 -> V_42 ) && ( V_16 < V_41 -> V_43 ) ) {
T_1 V_44 ;
V_44 = V_41 -> V_43 - V_41 -> V_42 ;
F_31 ( V_40 -> V_45 , L_5 ,
V_9 , V_41 -> V_42 , V_16 , V_41 -> V_43 , V_44 ,
V_41 -> V_21 ) ;
return V_41 ;
}
}
return NULL ;
}
struct V_38 * F_32 ( struct V_39 * V_40 , T_2 V_16 )
{
struct V_38 * V_46 ;
F_33 ( & V_40 -> V_47 ) ;
V_46 = F_29 ( V_40 , V_16 ) ;
F_34 ( & V_40 -> V_47 ) ;
return V_46 ;
}
static struct V_38 * F_35 ( struct V_39 * V_40 , T_2 V_16 ,
T_1 V_7 , T_2 V_21 )
{
struct V_38 * V_29 , * V_41 ;
T_2 V_48 , V_49 , V_50 ;
if ( ! V_40 || ! V_7 )
return F_12 ( - V_23 ) ;
V_48 = V_16 ;
V_50 = V_20 ;
if ( ~ V_21 & V_51 ) {
V_48 = V_40 -> V_42 ? V_40 -> V_42 : V_50 ;
if ( V_21 & V_24 )
V_50 = F_10 ( V_7 ) ;
V_48 = F_36 ( V_48 , V_50 ) ;
} else if ( V_48 < V_40 -> V_42 || V_48 > V_40 -> V_43 ||
V_40 -> V_43 - V_48 < V_7 ) {
return F_12 ( - V_23 ) ;
}
V_41 = NULL ;
if ( F_37 ( & V_40 -> V_52 ) )
goto V_53;
V_49 = 0 ;
F_30 (tmp, &obj->mmap, list) {
if ( V_49 > V_48 )
break;
if ( V_41 -> V_42 > V_48 && ( V_41 -> V_42 - V_48 ) >= V_7 )
goto V_53;
if ( V_41 -> V_43 >= V_48 && ~ V_21 & V_51 )
V_48 = F_36 ( V_41 -> V_43 + 1 , V_50 ) ;
V_49 = V_41 -> V_43 ;
}
if ( ( V_48 >= V_49 ) && ( V_40 -> V_43 - V_48 >= V_7 ) )
goto V_53;
F_31 ( V_40 -> V_45 , L_6 ,
V_9 , V_16 , V_7 , V_21 ) ;
return F_12 ( - V_23 ) ;
V_53:
V_29 = F_38 ( V_54 , V_25 ) ;
if ( ! V_29 )
return F_12 ( - V_26 ) ;
V_29 -> V_39 = V_40 ;
V_29 -> V_42 = V_48 ;
V_29 -> V_43 = V_48 + V_7 ;
V_29 -> V_21 = V_21 ;
if ( V_41 )
F_39 ( & V_29 -> V_55 , & V_41 -> V_55 ) ;
else
F_40 ( & V_29 -> V_55 , & V_40 -> V_52 ) ;
F_31 ( V_40 -> V_45 , L_7 ,
V_9 , V_29 -> V_42 , V_48 , V_29 -> V_43 , V_7 , V_21 ) ;
return V_29 ;
}
static void F_41 ( struct V_39 * V_40 , struct V_38 * V_46 )
{
T_1 V_7 ;
F_23 ( ! V_40 || ! V_46 ) ;
V_7 = V_46 -> V_43 - V_46 -> V_42 ;
F_31 ( V_40 -> V_45 , L_8 ,
V_9 , V_46 -> V_42 , V_46 -> V_43 , V_7 , V_46 -> V_21 ) ;
F_42 ( & V_46 -> V_55 ) ;
F_43 ( V_54 , V_46 ) ;
}
void * F_44 ( struct V_39 * V_40 , T_2 V_16 )
{
void * V_27 = NULL ;
struct V_38 * V_46 ;
F_33 ( & V_40 -> V_47 ) ;
V_46 = F_29 ( V_40 , V_16 ) ;
if ( ! V_46 ) {
F_31 ( V_40 -> V_45 , L_9 , V_9 , V_16 ) ;
goto V_56;
}
V_27 = V_46 -> V_27 ;
V_56:
F_34 ( & V_40 -> V_47 ) ;
return V_27 ;
}
static void F_45 ( struct V_1 * V_2 , void * V_57 )
{
unsigned int V_3 ;
struct V_5 * V_6 ;
void * V_27 = V_57 ;
void * va_end ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
struct V_58 * V_59 ;
const T_1 V_7 = V_20 ;
V_59 = F_46 ( V_27 ) ;
F_23 ( ! V_59 ) ;
F_47 ( V_6 , V_59 , V_7 , 0 ) ;
V_27 += V_7 ;
}
va_end = V_57 + V_20 * V_3 ;
}
static inline void F_48 ( struct V_1 * V_2 )
{
F_23 ( ! V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_2 V_17 , T_2 V_16 ,
T_1 V_44 )
{
unsigned int V_3 ;
struct V_5 * V_6 ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
unsigned V_7 ;
V_7 = F_5 ( V_16 | V_17 ) ;
V_7 = F_9 ( unsigned , V_7 , F_10 ( V_44 ) ) ;
F_23 ( ! F_3 ( V_7 ) ) ;
F_50 ( V_6 , F_51 ( V_17 ) , V_7 ) ;
V_17 += V_7 ;
V_16 += V_7 ;
V_44 -= V_7 ;
}
F_23 ( V_44 ) ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
F_23 ( ! V_2 ) ;
}
static int F_53 ( struct V_39 * V_40 , struct V_38 * V_29 ,
const struct V_1 * V_2 , T_2 V_21 )
{
int V_22 ;
unsigned int V_3 , V_60 ;
struct V_5 * V_6 ;
T_2 V_16 = V_29 -> V_42 ;
if ( ! V_40 || ! V_2 )
return - V_23 ;
F_23 ( ! F_54 ( V_2 ) ) ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_17 ;
int V_61 ;
T_1 V_7 ;
struct V_62 V_63 ;
V_17 = F_22 ( V_6 ) ;
V_7 = V_6 -> V_8 ;
V_21 &= ~ V_64 ;
V_61 = F_55 ( V_7 ) ;
if ( V_61 < 0 )
goto V_36;
V_21 |= V_61 ;
F_16 ( L_10 , V_9 ,
V_3 , V_16 , V_17 , V_7 ) ;
F_56 ( & V_63 , V_16 , V_17 , V_21 ) ;
V_22 = F_57 ( V_40 , & V_63 ) ;
if ( V_22 )
goto V_36;
V_16 += V_7 ;
}
return 0 ;
V_36:
V_16 = V_29 -> V_42 ;
F_2 (sgt->sgl, sg, i, j) {
T_1 V_7 ;
V_7 = F_58 ( V_40 , V_16 ) ;
F_23 ( ! F_3 ( V_7 ) ) ;
V_16 += V_7 ;
}
return V_22 ;
}
static void F_59 ( struct V_39 * V_40 , struct V_38 * V_46 )
{
T_2 V_48 ;
T_1 V_4 = V_46 -> V_43 - V_46 -> V_42 ;
F_23 ( ( ! V_4 ) || ! F_8 ( V_4 , V_20 ) ) ;
V_48 = V_46 -> V_42 ;
while ( V_4 > 0 ) {
T_1 V_7 ;
V_7 = F_58 ( V_40 , V_48 ) ;
if ( V_7 == 0 )
V_7 = V_20 ;
else
F_31 ( V_40 -> V_45 , L_11 ,
V_9 , V_48 , V_7 , V_46 -> V_21 ) ;
F_23 ( ! F_8 ( V_7 , V_20 ) ) ;
V_4 -= V_7 ;
V_48 += V_7 ;
}
F_23 ( V_4 ) ;
}
static struct V_1 * F_60 ( struct V_39 * V_40 , const T_2 V_16 ,
void (* F_61)( const void * ) , T_2 V_21 )
{
struct V_1 * V_2 = NULL ;
struct V_38 * V_46 ;
if ( ! F_8 ( V_16 , V_20 ) ) {
F_62 ( V_40 -> V_45 , L_12 , V_9 , V_16 ) ;
return NULL ;
}
F_33 ( & V_40 -> V_47 ) ;
V_46 = F_29 ( V_40 , V_16 ) ;
if ( ! V_46 ) {
F_31 ( V_40 -> V_45 , L_9 , V_9 , V_16 ) ;
goto V_56;
}
if ( ( V_46 -> V_21 & V_21 ) != V_21 ) {
F_62 ( V_40 -> V_45 , L_13 , V_9 ,
V_46 -> V_21 ) ;
goto V_56;
}
V_2 = (struct V_1 * ) V_46 -> V_2 ;
F_59 ( V_40 , V_46 ) ;
F_61 ( V_46 -> V_27 ) ;
F_31 ( V_40 -> V_45 , L_5 , V_9 ,
V_46 -> V_42 , V_16 , V_46 -> V_43 ,
V_46 -> V_43 - V_46 -> V_42 , V_46 -> V_21 ) ;
F_41 ( V_40 , V_46 ) ;
V_56:
F_34 ( & V_40 -> V_47 ) ;
return V_2 ;
}
static T_2 F_63 ( struct V_39 * V_40 , T_2 V_16 ,
const struct V_1 * V_2 , void * V_27 , T_1 V_7 , T_2 V_21 )
{
int V_22 = - V_26 ;
struct V_38 * V_29 ;
F_33 ( & V_40 -> V_47 ) ;
V_29 = F_35 ( V_40 , V_16 , V_7 , V_21 ) ;
if ( F_64 ( V_29 ) ) {
V_22 = F_65 ( V_29 ) ;
goto V_65;
}
V_29 -> V_27 = V_27 ;
V_29 -> V_2 = V_2 ;
if ( F_53 ( V_40 , V_29 , V_2 , V_29 -> V_21 ) )
goto V_66;
F_34 ( & V_40 -> V_47 ) ;
F_31 ( V_40 -> V_45 , L_14 ,
V_9 , V_29 -> V_42 , V_7 , V_29 -> V_21 , V_27 ) ;
return V_29 -> V_42 ;
V_66:
F_41 ( V_40 , V_29 ) ;
V_65:
F_34 ( & V_40 -> V_47 ) ;
return V_22 ;
}
static inline T_2 F_66 ( struct V_39 * V_40 , T_2 V_16 ,
const struct V_1 * V_2 , void * V_27 , T_1 V_7 , T_2 V_21 )
{
return F_63 ( V_40 , V_16 , V_2 , V_27 , V_7 , V_21 ) ;
}
T_2 F_67 ( struct V_39 * V_40 , T_2 V_16 , const struct V_1 * V_2 ,
T_2 V_21 )
{
T_1 V_7 ;
void * V_27 = NULL ;
if ( ! V_40 || ! V_40 -> V_45 || ! V_2 )
return - V_23 ;
V_7 = F_1 ( V_2 ) ;
if ( ! V_7 )
return - V_23 ;
V_7 = F_68 ( V_7 ) ;
if ( V_21 & V_67 ) {
V_27 = F_19 ( V_2 ) ;
if ( F_64 ( V_27 ) )
return F_65 ( V_27 ) ;
}
V_21 |= V_68 ;
V_21 |= V_67 ;
V_16 = F_66 ( V_40 , V_16 , V_2 , V_27 , V_7 , V_21 ) ;
if ( F_69 ( V_16 ) )
F_28 ( V_27 ) ;
return V_16 ;
}
struct V_1 * F_70 ( struct V_39 * V_40 , T_2 V_16 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( V_40 , V_16 , F_28 , V_68 | V_67 ) ;
if ( ! V_2 )
F_31 ( V_40 -> V_45 , L_15 , V_9 ) ;
return V_2 ;
}
T_2 F_71 ( struct V_39 * V_40 , T_2 V_16 , T_1 V_7 , T_2 V_21 )
{
void * V_27 ;
struct V_1 * V_2 ;
if ( ! V_40 || ! V_40 -> V_45 || ! V_7 )
return - V_23 ;
V_7 = F_68 ( V_7 ) ;
V_27 = F_72 ( V_7 ) ;
if ( ! V_27 )
return - V_26 ;
V_21 |= V_68 ;
V_21 |= V_69 ;
V_2 = F_11 ( V_7 , V_21 , V_16 , 0 ) ;
if ( F_64 ( V_2 ) ) {
V_16 = F_65 ( V_2 ) ;
goto V_70;
}
F_45 ( V_2 , V_27 ) ;
V_16 = F_66 ( V_40 , V_16 , V_2 , V_27 , V_7 , V_21 ) ;
if ( F_69 ( V_16 ) )
goto V_71;
return V_16 ;
V_71:
F_48 ( V_2 ) ;
F_17 ( V_2 ) ;
V_70:
F_73 ( V_27 ) ;
return V_16 ;
}
void F_74 ( struct V_39 * V_40 , const T_2 V_16 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( V_40 , V_16 , F_73 , V_68 | V_69 ) ;
if ( ! V_2 )
F_31 ( V_40 -> V_45 , L_15 , V_9 ) ;
F_17 ( V_2 ) ;
}
static T_2 F_75 ( struct V_39 * V_40 , T_2 V_16 , T_2 V_17 , void * V_27 ,
T_1 V_7 , T_2 V_21 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_7 , V_21 , V_16 , V_17 ) ;
if ( F_64 ( V_2 ) )
return F_65 ( V_2 ) ;
F_49 ( V_2 , V_17 , V_16 , V_7 ) ;
V_16 = F_63 ( V_40 , V_16 , V_2 , V_27 , V_7 , V_21 ) ;
if ( F_69 ( V_16 ) ) {
F_52 ( V_2 ) ;
F_17 ( V_2 ) ;
}
return V_16 ;
}
T_2 F_76 ( struct V_39 * V_40 , T_2 V_16 , T_2 V_17 , T_1 V_7 ,
T_2 V_21 )
{
void * V_27 ;
if ( ! V_40 || ! V_40 -> V_45 || ! V_7 )
return - V_23 ;
V_7 = F_68 ( V_7 ) ;
V_27 = F_77 ( V_17 , V_7 ) ;
if ( ! V_27 )
return - V_26 ;
V_21 |= V_24 ;
V_21 |= V_67 ;
V_16 = F_75 ( V_40 , V_16 , V_17 , V_27 , V_7 , V_21 ) ;
if ( F_69 ( V_16 ) )
F_78 ( V_27 ) ;
return V_16 ;
}
void F_79 ( struct V_39 * V_40 , T_2 V_16 )
{
struct V_1 * V_2 ;
typedef void (* F_80)( const void * );
V_2 = F_60 ( V_40 , V_16 , ( F_80 ) F_78 ,
V_24 | V_67 ) ;
if ( ! V_2 )
F_31 ( V_40 -> V_45 , L_15 , V_9 ) ;
F_17 ( V_2 ) ;
}
T_2 F_81 ( struct V_39 * V_40 , T_2 V_16 , T_1 V_7 , T_2 V_21 )
{
void * V_27 ;
T_2 V_17 ;
if ( ! V_40 || ! V_40 -> V_45 || ! V_7 )
return - V_23 ;
V_7 = F_68 ( V_7 ) ;
V_27 = F_82 ( V_7 , V_25 | V_72 ) ;
if ( ! V_27 )
return - V_26 ;
V_17 = F_83 ( V_27 ) ;
V_21 |= V_24 ;
V_21 |= V_69 ;
V_16 = F_75 ( V_40 , V_16 , V_17 , V_27 , V_7 , V_21 ) ;
if ( F_69 ( V_16 ) )
F_15 ( V_27 ) ;
return V_16 ;
}
void F_84 ( struct V_39 * V_40 , T_2 V_16 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( V_40 , V_16 , F_15 , V_24 | V_69 ) ;
if ( ! V_2 )
F_31 ( V_40 -> V_45 , L_15 , V_9 ) ;
F_17 ( V_2 ) ;
}
static int T_3 F_85 ( void )
{
const unsigned long V_21 = V_73 ;
struct V_74 * V_75 ;
V_75 = F_86 ( L_16 , sizeof( struct V_38 ) , 0 ,
V_21 , NULL ) ;
if ( ! V_75 )
return - V_26 ;
V_54 = V_75 ;
return 0 ;
}
static void T_4 F_87 ( void )
{
F_88 ( V_54 ) ;
}
