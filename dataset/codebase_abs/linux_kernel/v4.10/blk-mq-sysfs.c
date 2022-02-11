static void F_1 ( struct V_1 * V_2 )
{
}
static T_1 F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
V_7 = F_3 ( V_4 , struct V_6 , V_4 ) ;
V_9 = F_3 ( V_2 , struct V_8 , V_2 ) ;
V_11 = V_9 -> V_13 ;
if ( ! V_7 -> V_14 )
return - V_15 ;
V_12 = - V_16 ;
F_4 ( & V_11 -> V_17 ) ;
if ( ! F_5 ( V_11 ) )
V_12 = V_7 -> V_14 ( V_9 , V_5 ) ;
F_6 ( & V_11 -> V_17 ) ;
return V_12 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_1 V_12 ;
V_7 = F_3 ( V_4 , struct V_6 , V_4 ) ;
V_9 = F_3 ( V_2 , struct V_8 , V_2 ) ;
V_11 = V_9 -> V_13 ;
if ( ! V_7 -> V_19 )
return - V_15 ;
V_12 = - V_16 ;
F_4 ( & V_11 -> V_17 ) ;
if ( ! F_5 ( V_11 ) )
V_12 = V_7 -> V_19 ( V_9 , V_5 , V_18 ) ;
F_6 ( & V_11 -> V_17 ) ;
return V_12 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_20 * V_7 ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
T_1 V_12 ;
V_7 = F_3 ( V_4 , struct V_20 , V_4 ) ;
V_22 = F_3 ( V_2 , struct V_21 , V_2 ) ;
V_11 = V_22 -> V_13 ;
if ( ! V_7 -> V_14 )
return - V_15 ;
V_12 = - V_16 ;
F_4 ( & V_11 -> V_17 ) ;
if ( ! F_5 ( V_11 ) )
V_12 = V_7 -> V_14 ( V_22 , V_5 ) ;
F_6 ( & V_11 -> V_17 ) ;
return V_12 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_18 )
{
struct V_20 * V_7 ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
T_1 V_12 ;
V_7 = F_3 ( V_4 , struct V_20 , V_4 ) ;
V_22 = F_3 ( V_2 , struct V_21 , V_2 ) ;
V_11 = V_22 -> V_13 ;
if ( ! V_7 -> V_19 )
return - V_15 ;
V_12 = - V_16 ;
F_4 ( & V_11 -> V_17 ) ;
if ( ! F_5 ( V_11 ) )
V_12 = V_7 -> V_19 ( V_22 , V_5 , V_18 ) ;
F_6 ( & V_11 -> V_17 ) ;
return V_12 ;
}
static T_1 F_10 ( struct V_8 * V_9 , char * V_5 )
{
return sprintf ( V_5 , L_1 , V_9 -> V_23 [ 1 ] ,
V_9 -> V_23 [ 0 ] ) ;
}
static T_1 F_11 ( struct V_8 * V_9 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_9 -> V_24 ) ;
}
static T_1 F_12 ( struct V_8 * V_9 , char * V_5 )
{
return sprintf ( V_5 , L_1 , V_9 -> V_25 [ 1 ] ,
V_9 -> V_25 [ 0 ] ) ;
}
static T_1 F_13 ( char * V_5 , struct V_26 * V_27 , char * V_28 )
{
struct V_29 * V_30 ;
int V_31 = snprintf ( V_5 , V_32 - 1 , L_3 , V_28 ) ;
F_14 (rq, list, queuelist) {
const int V_33 = 2 * sizeof( V_30 ) + 2 ;
if ( V_32 - 1 < V_31 + V_33 ) {
if ( V_32 - 1 < V_31 + 5 )
V_31 -= V_33 ;
V_31 += snprintf ( V_5 + V_31 , V_32 - 1 - V_31 ,
L_4 ) ;
break;
}
V_31 += snprintf ( V_5 + V_31 , V_32 - 1 - V_31 ,
L_5 , V_30 ) ;
}
return V_31 ;
}
static T_1 F_15 ( struct V_8 * V_9 , char * V_5 )
{
T_1 V_34 ;
F_16 ( & V_9 -> V_35 ) ;
V_34 = F_13 ( V_5 , & V_9 -> V_36 , L_6 ) ;
F_17 ( & V_9 -> V_35 ) ;
return V_34 ;
}
static T_1 F_18 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_7 ,
V_22 -> V_37 , V_22 -> V_38 ,
V_22 -> V_39 ) ;
}
static T_1 F_19 ( struct V_21 * V_22 ,
const char * V_5 , T_2 V_40 )
{
V_22 -> V_37 = V_22 -> V_38 = V_22 -> V_39 = 0 ;
return V_40 ;
}
static T_1 F_20 ( struct V_21 * V_22 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 , V_22 -> V_41 ) ;
}
static T_1 F_21 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_22 -> V_42 ) ;
}
static T_1 F_22 ( struct V_21 * V_22 ,
char * V_5 )
{
char * V_43 = V_5 ;
int V_44 ;
V_5 += sprintf ( V_5 , L_8 , 0U , V_22 -> V_45 [ 0 ] ) ;
for ( V_44 = 1 ; V_44 < V_46 - 1 ; V_44 ++ ) {
unsigned int V_47 = 1U << ( V_44 - 1 ) ;
V_5 += sprintf ( V_5 , L_8 , V_47 , V_22 -> V_45 [ V_44 ] ) ;
}
V_5 += sprintf ( V_5 , L_9 , 1U << ( V_44 - 1 ) ,
V_22 -> V_45 [ V_44 ] ) ;
return V_5 - V_43 ;
}
static T_1 F_23 ( struct V_21 * V_22 ,
char * V_5 )
{
T_1 V_34 ;
F_16 ( & V_22 -> V_35 ) ;
V_34 = F_13 ( V_5 , & V_22 -> V_48 , L_10 ) ;
F_17 ( & V_22 -> V_35 ) ;
return V_34 ;
}
static T_1 F_24 ( struct V_21 * V_22 , char * V_5 )
{
return F_25 ( V_22 -> V_49 , V_5 ) ;
}
static T_1 F_26 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_11 , F_27 ( & V_22 -> V_50 ) ) ;
}
static T_1 F_28 ( struct V_21 * V_22 , char * V_5 )
{
unsigned int V_44 , V_51 = 1 ;
T_1 V_34 = 0 ;
F_29 (i, hctx->cpumask) {
if ( V_51 )
V_34 += sprintf ( V_34 + V_5 , L_12 , V_44 ) ;
else
V_34 += sprintf ( V_34 + V_5 , L_13 , V_44 ) ;
V_51 = 0 ;
}
V_34 += sprintf ( V_34 + V_5 , L_14 ) ;
return V_34 ;
}
static void F_30 ( struct V_21 * V_22 )
{
struct V_8 * V_9 ;
unsigned int V_44 ;
F_31 (hctx, ctx, i) {
F_32 ( & V_9 -> V_52 [ V_53 ] ) ;
F_32 ( & V_9 -> V_52 [ V_54 ] ) ;
}
}
static T_1 F_33 ( struct V_21 * V_22 ,
const char * V_5 , T_2 V_55 )
{
F_30 ( V_22 ) ;
return V_55 ;
}
static T_1 F_34 ( char * V_5 , struct V_56 * V_52 , const char * V_57 )
{
return sprintf ( V_5 , L_15 ,
V_57 , ( long long ) V_52 -> V_58 ,
( long long ) V_52 -> V_59 , ( long long ) V_52 -> V_60 ,
( long long ) V_52 -> V_61 ) ;
}
static T_1 F_35 ( struct V_21 * V_22 , char * V_5 )
{
struct V_56 V_52 [ 2 ] ;
T_1 V_34 ;
F_32 ( & V_52 [ V_53 ] ) ;
F_32 ( & V_52 [ V_54 ] ) ;
F_36 ( V_22 , V_52 ) ;
V_34 = F_34 ( V_5 , & V_52 [ V_53 ] , L_16 ) ;
V_34 += F_34 ( V_5 + V_34 , & V_52 [ V_54 ] , L_17 ) ;
return V_34 ;
}
static void F_37 ( struct V_21 * V_22 )
{
struct V_8 * V_9 ;
int V_44 ;
if ( ! V_22 -> V_62 )
return;
F_31 (hctx, ctx, i)
F_38 ( & V_9 -> V_2 ) ;
F_38 ( & V_22 -> V_2 ) ;
}
static int F_39 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_13 ;
struct V_8 * V_9 ;
int V_44 , V_34 ;
if ( ! V_22 -> V_62 )
return 0 ;
V_34 = F_40 ( & V_22 -> V_2 , & V_11 -> V_63 , L_12 , V_22 -> V_64 ) ;
if ( V_34 )
return V_34 ;
F_31 (hctx, ctx, i) {
V_34 = F_40 ( & V_9 -> V_2 , & V_22 -> V_2 , L_18 , V_9 -> V_65 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
static void F_41 ( struct V_66 * V_67 , struct V_10 * V_11 )
{
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_44 , V_68 ;
F_42 (q, hctx, i) {
F_37 ( V_22 ) ;
F_31 (hctx, ctx, j)
F_43 ( & V_9 -> V_2 ) ;
F_43 ( & V_22 -> V_2 ) ;
}
F_44 ( & V_11 -> V_63 , V_69 ) ;
F_38 ( & V_11 -> V_63 ) ;
F_43 ( & V_11 -> V_63 ) ;
F_43 ( & V_67 -> V_2 ) ;
V_11 -> V_70 = false ;
}
void F_45 ( struct V_66 * V_67 , struct V_10 * V_11 )
{
F_46 () ;
F_41 ( V_67 , V_11 ) ;
F_47 () ;
}
void F_48 ( struct V_21 * V_22 )
{
F_49 ( & V_22 -> V_2 , & V_71 ) ;
}
static void F_50 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
int V_65 ;
F_49 ( & V_11 -> V_63 , & V_72 ) ;
F_51 (cpu) {
V_9 = F_52 ( V_11 -> V_73 , V_65 ) ;
F_49 ( & V_9 -> V_2 , & V_74 ) ;
}
}
int F_53 ( struct V_66 * V_67 , struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_34 , V_44 ;
F_46 () ;
F_50 ( V_11 ) ;
V_34 = F_40 ( & V_11 -> V_63 , F_54 ( & V_67 -> V_2 ) , L_19 , L_20 ) ;
if ( V_34 < 0 )
goto V_75;
F_44 ( & V_11 -> V_63 , V_76 ) ;
F_42 (q, hctx, i) {
V_34 = F_39 ( V_22 ) ;
if ( V_34 )
break;
}
if ( V_34 )
F_41 ( V_67 , V_11 ) ;
else
V_11 -> V_70 = true ;
V_75:
F_47 () ;
return V_34 ;
}
void F_55 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_44 ;
if ( ! V_11 -> V_70 )
return;
F_42 (q, hctx, i)
F_37 ( V_22 ) ;
}
int F_56 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_44 , V_34 = 0 ;
if ( ! V_11 -> V_70 )
return V_34 ;
F_42 (q, hctx, i) {
V_34 = F_39 ( V_22 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
