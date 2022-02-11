static T_1 F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 , V_4 = 0 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return 0 ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_7 ;
V_7 = F_3 ( V_6 ) ;
if ( ! F_4 ( V_7 ) ) {
F_5 ( L_1 ,
V_8 , V_3 , V_7 ) ;
return 0 ;
}
V_4 += V_7 ;
}
return V_4 ;
}
static unsigned F_6 ( T_2 V_9 )
{
int V_3 ;
unsigned V_10 [] = { V_11 , V_12 , V_13 , V_14 , } ;
for ( V_3 = 0 ; V_3 < F_7 ( V_10 ) && V_9 & ( V_10 [ V_3 ] - 1 ) ; V_3 ++ )
;
return ( V_3 < F_7 ( V_10 ) ) ? V_10 [ V_3 ] : 0 ;
}
static unsigned F_8 ( T_1 V_7 , T_2 V_15 , T_2 V_16 )
{
unsigned V_17 = 0 , V_18 ;
if ( ! F_9 ( V_7 , V_19 ) ) {
F_5 ( L_2 , V_8 , V_7 ) ;
return 0 ;
}
while ( V_7 ) {
V_18 = F_6 ( V_15 | V_16 ) ;
V_18 = F_10 ( unsigned , V_18 , F_11 ( V_7 ) ) ;
V_17 ++ ;
V_15 += V_18 ;
V_16 += V_18 ;
V_7 -= V_18 ;
}
return V_17 ;
}
static struct V_1 * F_12 ( const T_1 V_7 , T_2 V_20 ,
T_2 V_15 , T_2 V_16 )
{
unsigned int V_17 ;
int V_21 ;
struct V_1 * V_2 ;
if ( ! V_7 )
return F_13 ( - V_22 ) ;
if ( ! F_9 ( V_7 , V_19 ) )
return F_13 ( - V_22 ) ;
if ( V_20 & V_23 ) {
V_17 = F_8 ( V_7 , V_15 , V_16 ) ;
if ( ! V_17 )
return F_13 ( - V_22 ) ;
} else
V_17 = V_7 / V_19 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return F_13 ( - V_25 ) ;
V_21 = F_15 ( V_2 , V_17 , V_24 ) ;
if ( V_21 ) {
F_16 ( V_2 ) ;
return F_13 ( V_21 ) ;
}
F_17 ( L_3 , V_8 , V_2 , V_17 ) ;
return V_2 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_19 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( L_4 , V_8 , V_2 ) ;
}
static void * F_20 ( const struct V_1 * V_2 )
{
T_2 V_26 ;
T_1 V_4 ;
unsigned int V_3 ;
struct V_5 * V_6 ;
struct V_27 * V_28 ;
const struct V_29 * V_30 ;
V_30 = F_21 ( V_31 ) ;
if ( ! V_30 )
return F_13 ( - V_22 ) ;
V_4 = F_1 ( V_2 ) ;
if ( ! V_4 )
return F_13 ( - V_22 ) ;
V_28 = F_22 ( V_4 , V_32 , V_33 , V_34 ) ;
if ( ! V_28 )
return F_13 ( - V_25 ) ;
V_26 = ( T_2 ) V_28 -> V_9 ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_7 ;
T_2 V_16 ;
int V_21 ;
V_16 = F_23 ( V_6 ) ;
V_7 = F_3 ( V_6 ) ;
F_24 ( V_7 != V_19 ) ;
V_21 = F_25 ( V_26 , V_16 , V_30 ) ;
if ( V_21 )
goto V_35;
V_26 += V_7 ;
}
F_26 ( ( unsigned long ) V_28 -> V_9 ,
( unsigned long ) ( V_28 -> V_9 + V_4 ) ) ;
return V_28 -> V_9 ;
V_35:
F_27 ( 1 ) ;
F_28 ( V_28 -> V_9 ) ;
return F_13 ( - V_36 ) ;
}
static inline void F_29 ( const void * V_26 )
{
F_28 ( V_26 ) ;
}
static struct V_37 * F_30 ( struct V_38 * V_39 , const T_2 V_15 )
{
struct V_37 * V_40 ;
F_31 (tmp, &obj->mmap, list) {
if ( ( V_15 >= V_40 -> V_41 ) && ( V_15 < V_40 -> V_42 ) ) {
T_1 V_43 ;
V_43 = V_40 -> V_42 - V_40 -> V_41 ;
F_32 ( V_39 -> V_44 , L_5 ,
V_8 , V_40 -> V_41 , V_15 , V_40 -> V_42 , V_43 ,
V_40 -> V_20 ) ;
return V_40 ;
}
}
return NULL ;
}
struct V_37 * F_33 ( struct V_38 * V_39 , T_2 V_15 )
{
struct V_37 * V_45 ;
F_34 ( & V_39 -> V_46 ) ;
V_45 = F_30 ( V_39 , V_15 ) ;
F_35 ( & V_39 -> V_46 ) ;
return V_45 ;
}
static struct V_37 * F_36 ( struct V_38 * V_39 , T_2 V_15 ,
T_1 V_7 , T_2 V_20 )
{
struct V_37 * V_28 , * V_40 ;
T_2 V_47 , V_48 , V_49 ;
if ( ! V_39 || ! V_7 )
return F_13 ( - V_22 ) ;
V_47 = V_15 ;
V_49 = V_19 ;
if ( ~ V_20 & V_50 ) {
V_47 = V_39 -> V_41 ? V_39 -> V_41 : V_49 ;
if ( V_20 & V_23 )
V_49 = F_11 ( V_7 ) ;
V_47 = F_37 ( V_47 , V_49 ) ;
} else if ( V_47 < V_39 -> V_41 || V_47 > V_39 -> V_42 ||
V_39 -> V_42 - V_47 < V_7 ) {
return F_13 ( - V_22 ) ;
}
V_40 = NULL ;
if ( F_38 ( & V_39 -> V_51 ) )
goto V_52;
V_48 = 0 ;
F_31 (tmp, &obj->mmap, list) {
if ( V_48 > V_47 )
break;
if ( V_40 -> V_41 > V_47 && ( V_40 -> V_41 - V_47 ) >= V_7 )
goto V_52;
if ( V_40 -> V_42 >= V_47 && ~ V_20 & V_50 )
V_47 = F_37 ( V_40 -> V_42 + 1 , V_49 ) ;
V_48 = V_40 -> V_42 ;
}
if ( ( V_47 >= V_48 ) && ( V_39 -> V_42 - V_47 >= V_7 ) )
goto V_52;
F_32 ( V_39 -> V_44 , L_6 ,
V_8 , V_15 , V_7 , V_20 ) ;
return F_13 ( - V_22 ) ;
V_52:
V_28 = F_39 ( V_53 , V_24 ) ;
if ( ! V_28 )
return F_13 ( - V_25 ) ;
V_28 -> V_38 = V_39 ;
V_28 -> V_41 = V_47 ;
V_28 -> V_42 = V_47 + V_7 ;
V_28 -> V_20 = V_20 ;
if ( V_40 )
F_40 ( & V_28 -> V_54 , & V_40 -> V_54 ) ;
else
F_41 ( & V_28 -> V_54 , & V_39 -> V_51 ) ;
F_32 ( V_39 -> V_44 , L_7 ,
V_8 , V_28 -> V_41 , V_47 , V_28 -> V_42 , V_7 , V_20 ) ;
return V_28 ;
}
static void F_42 ( struct V_38 * V_39 , struct V_37 * V_45 )
{
T_1 V_7 ;
F_24 ( ! V_39 || ! V_45 ) ;
V_7 = V_45 -> V_42 - V_45 -> V_41 ;
F_32 ( V_39 -> V_44 , L_8 ,
V_8 , V_45 -> V_41 , V_45 -> V_42 , V_7 , V_45 -> V_20 ) ;
F_43 ( & V_45 -> V_54 ) ;
F_44 ( V_53 , V_45 ) ;
}
void * F_45 ( struct V_38 * V_39 , T_2 V_15 )
{
void * V_26 = NULL ;
struct V_37 * V_45 ;
F_34 ( & V_39 -> V_46 ) ;
V_45 = F_30 ( V_39 , V_15 ) ;
if ( ! V_45 ) {
F_32 ( V_39 -> V_44 , L_9 , V_8 , V_15 ) ;
goto V_55;
}
V_26 = V_45 -> V_26 ;
V_55:
F_35 ( & V_39 -> V_46 ) ;
return V_26 ;
}
static void F_46 ( struct V_1 * V_2 , void * V_56 )
{
unsigned int V_3 ;
struct V_5 * V_6 ;
void * V_26 = V_56 ;
void * va_end ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
struct V_57 * V_58 ;
const T_1 V_7 = V_19 ;
V_58 = F_47 ( V_26 ) ;
F_24 ( ! V_58 ) ;
F_48 ( V_6 , V_58 , V_7 , 0 ) ;
V_26 += V_7 ;
}
va_end = V_56 + V_19 * V_3 ;
}
static inline void F_49 ( struct V_1 * V_2 )
{
F_24 ( ! V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 , T_2 V_16 , T_2 V_15 ,
T_1 V_43 )
{
unsigned int V_3 ;
struct V_5 * V_6 ;
void * V_26 ;
V_26 = F_51 ( V_16 ) ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
unsigned V_7 ;
V_7 = F_6 ( V_15 | V_16 ) ;
V_7 = F_10 ( unsigned , V_7 , F_11 ( V_43 ) ) ;
F_24 ( ! F_4 ( V_7 ) ) ;
F_52 ( V_6 , F_51 ( V_16 ) , V_7 ) ;
V_16 += V_7 ;
V_15 += V_7 ;
V_43 -= V_7 ;
}
F_24 ( V_43 ) ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
F_24 ( ! V_2 ) ;
}
static int F_54 ( struct V_38 * V_39 , struct V_37 * V_28 ,
const struct V_1 * V_2 , T_2 V_20 )
{
int V_21 ;
unsigned int V_3 , V_59 ;
struct V_5 * V_6 ;
T_2 V_15 = V_28 -> V_41 ;
if ( ! V_39 || ! V_2 )
return - V_22 ;
F_24 ( ! F_55 ( V_2 ) ) ;
F_2 (sgt->sgl, sg, sgt->nents, i) {
T_2 V_16 ;
int V_60 ;
T_1 V_7 ;
struct V_61 V_62 ;
V_16 = F_23 ( V_6 ) ;
V_7 = F_3 ( V_6 ) ;
V_20 &= ~ V_63 ;
V_60 = F_56 ( V_7 ) ;
if ( V_60 < 0 )
goto V_35;
V_20 |= V_60 ;
F_17 ( L_10 , V_8 ,
V_3 , V_15 , V_16 , V_7 ) ;
F_57 ( & V_62 , V_15 , V_16 , V_20 ) ;
V_21 = F_58 ( V_39 , & V_62 ) ;
if ( V_21 )
goto V_35;
V_15 += V_7 ;
}
return 0 ;
V_35:
V_15 = V_28 -> V_41 ;
F_2 (sgt->sgl, sg, i, j) {
T_1 V_7 ;
V_7 = F_59 ( V_39 , V_15 ) ;
F_24 ( ! F_4 ( V_7 ) ) ;
V_15 += V_7 ;
}
return V_21 ;
}
static void F_60 ( struct V_38 * V_39 , struct V_37 * V_45 )
{
T_2 V_47 ;
T_1 V_4 = V_45 -> V_42 - V_45 -> V_41 ;
F_24 ( ( ! V_4 ) || ! F_9 ( V_4 , V_19 ) ) ;
V_47 = V_45 -> V_41 ;
while ( V_4 > 0 ) {
T_1 V_7 ;
V_7 = F_59 ( V_39 , V_47 ) ;
if ( V_7 == 0 )
V_7 = V_19 ;
else
F_32 ( V_39 -> V_44 , L_11 ,
V_8 , V_47 , V_7 , V_45 -> V_20 ) ;
F_24 ( ! F_9 ( V_7 , V_19 ) ) ;
V_4 -= V_7 ;
V_47 += V_7 ;
}
F_24 ( V_4 ) ;
}
static struct V_1 * F_61 ( struct V_38 * V_39 , const T_2 V_15 ,
void (* F_62)( const void * ) , T_2 V_20 )
{
struct V_1 * V_2 = NULL ;
struct V_37 * V_45 ;
if ( ! F_9 ( V_15 , V_19 ) ) {
F_63 ( V_39 -> V_44 , L_12 , V_8 , V_15 ) ;
return NULL ;
}
F_34 ( & V_39 -> V_46 ) ;
V_45 = F_30 ( V_39 , V_15 ) ;
if ( ! V_45 ) {
F_32 ( V_39 -> V_44 , L_9 , V_8 , V_15 ) ;
goto V_55;
}
if ( ( V_45 -> V_20 & V_20 ) != V_20 ) {
F_63 ( V_39 -> V_44 , L_13 , V_8 ,
V_45 -> V_20 ) ;
goto V_55;
}
V_2 = (struct V_1 * ) V_45 -> V_2 ;
F_60 ( V_39 , V_45 ) ;
F_62 ( V_45 -> V_26 ) ;
F_32 ( V_39 -> V_44 , L_5 , V_8 ,
V_45 -> V_41 , V_15 , V_45 -> V_42 ,
V_45 -> V_42 - V_45 -> V_41 , V_45 -> V_20 ) ;
F_42 ( V_39 , V_45 ) ;
V_55:
F_35 ( & V_39 -> V_46 ) ;
return V_2 ;
}
static T_2 F_64 ( struct V_38 * V_39 , T_2 V_15 ,
const struct V_1 * V_2 , void * V_26 , T_1 V_7 , T_2 V_20 )
{
int V_21 = - V_25 ;
struct V_37 * V_28 ;
F_34 ( & V_39 -> V_46 ) ;
V_28 = F_36 ( V_39 , V_15 , V_7 , V_20 ) ;
if ( F_65 ( V_28 ) ) {
V_21 = F_66 ( V_28 ) ;
goto V_64;
}
V_28 -> V_26 = V_26 ;
V_28 -> V_2 = V_2 ;
if ( F_54 ( V_39 , V_28 , V_2 , V_28 -> V_20 ) )
goto V_65;
F_35 ( & V_39 -> V_46 ) ;
F_32 ( V_39 -> V_44 , L_14 ,
V_8 , V_28 -> V_41 , V_7 , V_28 -> V_20 , V_26 ) ;
return V_28 -> V_41 ;
V_65:
F_42 ( V_39 , V_28 ) ;
V_64:
F_35 ( & V_39 -> V_46 ) ;
return V_21 ;
}
static inline T_2 F_67 ( struct V_38 * V_39 , T_2 V_15 ,
const struct V_1 * V_2 , void * V_26 , T_1 V_7 , T_2 V_20 )
{
return F_64 ( V_39 , V_15 , V_2 , V_26 , V_7 , V_20 ) ;
}
T_2 F_68 ( struct V_38 * V_39 , T_2 V_15 , const struct V_1 * V_2 ,
T_2 V_20 )
{
T_1 V_7 ;
void * V_26 = NULL ;
if ( ! V_39 || ! V_39 -> V_44 || ! V_2 )
return - V_22 ;
V_7 = F_1 ( V_2 ) ;
if ( ! V_7 )
return - V_22 ;
V_7 = F_69 ( V_7 ) ;
if ( V_20 & V_66 ) {
V_26 = F_20 ( V_2 ) ;
if ( F_65 ( V_26 ) )
return F_66 ( V_26 ) ;
}
V_20 |= V_67 ;
V_20 |= V_66 ;
V_15 = F_67 ( V_39 , V_15 , V_2 , V_26 , V_7 , V_20 ) ;
if ( F_70 ( V_15 ) )
F_29 ( V_26 ) ;
return V_15 ;
}
struct V_1 * F_71 ( struct V_38 * V_39 , T_2 V_15 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( V_39 , V_15 , F_29 , V_67 | V_66 ) ;
if ( ! V_2 )
F_32 ( V_39 -> V_44 , L_15 , V_8 ) ;
return V_2 ;
}
T_2 F_72 ( struct V_38 * V_39 , T_2 V_15 , T_1 V_7 , T_2 V_20 )
{
void * V_26 ;
struct V_1 * V_2 ;
if ( ! V_39 || ! V_39 -> V_44 || ! V_7 )
return - V_22 ;
V_7 = F_69 ( V_7 ) ;
V_26 = F_73 ( V_7 ) ;
if ( ! V_26 )
return - V_25 ;
V_20 |= V_67 ;
V_20 |= V_68 ;
V_2 = F_12 ( V_7 , V_20 , V_15 , 0 ) ;
if ( F_65 ( V_2 ) ) {
V_15 = F_66 ( V_2 ) ;
goto V_69;
}
F_46 ( V_2 , V_26 ) ;
V_15 = F_67 ( V_39 , V_15 , V_2 , V_26 , V_7 , V_20 ) ;
if ( F_70 ( V_15 ) )
goto V_70;
return V_15 ;
V_70:
F_49 ( V_2 ) ;
F_18 ( V_2 ) ;
V_69:
F_74 ( V_26 ) ;
return V_15 ;
}
void F_75 ( struct V_38 * V_39 , const T_2 V_15 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( V_39 , V_15 , F_74 , V_67 | V_68 ) ;
if ( ! V_2 )
F_32 ( V_39 -> V_44 , L_15 , V_8 ) ;
F_18 ( V_2 ) ;
}
static T_2 F_76 ( struct V_38 * V_39 , T_2 V_15 , T_2 V_16 , void * V_26 ,
T_1 V_7 , T_2 V_20 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_7 , V_20 , V_15 , V_16 ) ;
if ( F_65 ( V_2 ) )
return F_66 ( V_2 ) ;
F_50 ( V_2 , V_16 , V_15 , V_7 ) ;
V_15 = F_64 ( V_39 , V_15 , V_2 , V_26 , V_7 , V_20 ) ;
if ( F_70 ( V_15 ) ) {
F_53 ( V_2 ) ;
F_18 ( V_2 ) ;
}
return V_15 ;
}
T_2 F_77 ( struct V_38 * V_39 , T_2 V_15 , T_2 V_16 , T_1 V_7 ,
T_2 V_20 )
{
void * V_26 ;
if ( ! V_39 || ! V_39 -> V_44 || ! V_7 )
return - V_22 ;
V_7 = F_69 ( V_7 ) ;
V_26 = F_78 ( V_16 , V_7 ) ;
if ( ! V_26 )
return - V_25 ;
V_20 |= V_23 ;
V_20 |= V_66 ;
V_15 = F_76 ( V_39 , V_15 , V_16 , V_26 , V_7 , V_20 ) ;
if ( F_70 ( V_15 ) )
F_79 ( V_26 ) ;
return V_15 ;
}
void F_80 ( struct V_38 * V_39 , T_2 V_15 )
{
struct V_1 * V_2 ;
typedef void (* F_81)( const void * );
V_2 = F_61 ( V_39 , V_15 , ( F_81 ) F_79 ,
V_23 | V_66 ) ;
if ( ! V_2 )
F_32 ( V_39 -> V_44 , L_15 , V_8 ) ;
F_18 ( V_2 ) ;
}
T_2 F_82 ( struct V_38 * V_39 , T_2 V_15 , T_1 V_7 , T_2 V_20 )
{
void * V_26 ;
T_2 V_16 ;
if ( ! V_39 || ! V_39 -> V_44 || ! V_7 )
return - V_22 ;
V_7 = F_69 ( V_7 ) ;
V_26 = F_83 ( V_7 , V_24 | V_71 ) ;
if ( ! V_26 )
return - V_25 ;
V_16 = F_84 ( V_26 ) ;
V_20 |= V_23 ;
V_20 |= V_68 ;
V_15 = F_76 ( V_39 , V_15 , V_16 , V_26 , V_7 , V_20 ) ;
if ( F_70 ( V_15 ) )
F_16 ( V_26 ) ;
return V_15 ;
}
void F_85 ( struct V_38 * V_39 , T_2 V_15 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( V_39 , V_15 , F_16 , V_23 | V_68 ) ;
if ( ! V_2 )
F_32 ( V_39 -> V_44 , L_15 , V_8 ) ;
F_18 ( V_2 ) ;
}
static int T_3 F_86 ( void )
{
const unsigned long V_20 = V_72 ;
struct V_73 * V_74 ;
V_74 = F_87 ( L_16 , sizeof( struct V_37 ) , 0 ,
V_20 , NULL ) ;
if ( ! V_74 )
return - V_25 ;
V_53 = V_74 ;
return 0 ;
}
static void T_4 F_88 ( void )
{
F_89 ( V_53 ) ;
}
