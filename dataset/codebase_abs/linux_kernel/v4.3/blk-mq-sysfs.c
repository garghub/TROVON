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
static T_1 F_18 ( struct V_21 * V_22 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 , V_22 -> V_37 ) ;
}
static T_1 F_19 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_22 -> V_38 ) ;
}
static T_1 F_20 ( struct V_21 * V_22 ,
char * V_5 )
{
char * V_39 = V_5 ;
int V_40 ;
V_5 += sprintf ( V_5 , L_7 , 0U , V_22 -> V_41 [ 0 ] ) ;
for ( V_40 = 1 ; V_40 < V_42 ; V_40 ++ ) {
unsigned long V_43 = 1U << ( V_40 - 1 ) ;
V_5 += sprintf ( V_5 , L_8 , V_43 , V_22 -> V_41 [ V_40 ] ) ;
}
return V_5 - V_39 ;
}
static T_1 F_21 ( struct V_21 * V_22 ,
char * V_5 )
{
T_1 V_34 ;
F_16 ( & V_22 -> V_35 ) ;
V_34 = F_13 ( V_5 , & V_22 -> V_44 , L_9 ) ;
F_17 ( & V_22 -> V_35 ) ;
return V_34 ;
}
static T_1 F_22 ( struct V_21 * V_22 , char * V_5 )
{
return F_23 ( V_22 -> V_45 , V_5 ) ;
}
static T_1 F_24 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_10 , F_25 ( & V_22 -> V_46 ) ) ;
}
static T_1 F_26 ( struct V_21 * V_22 , char * V_5 )
{
unsigned int V_40 , V_47 = 1 ;
T_1 V_34 = 0 ;
F_27 (i, hctx->cpumask) {
if ( V_47 )
V_34 += sprintf ( V_34 + V_5 , L_11 , V_40 ) ;
else
V_34 += sprintf ( V_34 + V_5 , L_12 , V_40 ) ;
V_47 = 0 ;
}
V_34 += sprintf ( V_34 + V_5 , L_13 ) ;
return V_34 ;
}
static void F_28 ( struct V_21 * V_22 )
{
struct V_8 * V_9 ;
int V_40 ;
if ( ! V_22 -> V_48 )
return;
F_29 (hctx, ctx, i)
F_30 ( & V_9 -> V_2 ) ;
F_30 ( & V_22 -> V_2 ) ;
}
static int F_31 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_13 ;
struct V_8 * V_9 ;
int V_40 , V_34 ;
if ( ! V_22 -> V_48 )
return 0 ;
V_34 = F_32 ( & V_22 -> V_2 , & V_11 -> V_49 , L_11 , V_22 -> V_50 ) ;
if ( V_34 )
return V_34 ;
F_29 (hctx, ctx, i) {
V_34 = F_32 ( & V_9 -> V_2 , & V_22 -> V_2 , L_14 , V_9 -> V_51 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
void F_33 ( struct V_52 * V_53 )
{
struct V_10 * V_11 = V_53 -> V_13 ;
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_40 , V_54 ;
F_34 () ;
F_35 (q, hctx, i) {
F_28 ( V_22 ) ;
F_29 (hctx, ctx, j)
F_36 ( & V_9 -> V_2 ) ;
F_36 ( & V_22 -> V_2 ) ;
}
F_37 ( & V_11 -> V_49 , V_55 ) ;
F_30 ( & V_11 -> V_49 ) ;
F_36 ( & V_11 -> V_49 ) ;
F_36 ( & F_38 ( V_53 ) -> V_2 ) ;
V_11 -> V_56 = false ;
F_39 () ;
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_40 ;
F_41 ( & V_11 -> V_49 , & V_57 ) ;
F_35 (q, hctx, i)
F_41 ( & V_22 -> V_2 , & V_58 ) ;
F_42 (q, ctx, i)
F_41 ( & V_9 -> V_2 , & V_59 ) ;
}
void F_43 ( struct V_10 * V_11 )
{
F_44 ( & V_11 -> V_60 ) ;
}
int F_45 ( struct V_52 * V_53 )
{
struct V_61 * V_62 = F_38 ( V_53 ) ;
struct V_10 * V_11 = V_53 -> V_13 ;
struct V_21 * V_22 ;
int V_34 , V_40 ;
F_34 () ;
F_40 ( V_11 ) ;
V_34 = F_32 ( & V_11 -> V_49 , F_46 ( & V_62 -> V_2 ) , L_15 , L_16 ) ;
if ( V_34 < 0 )
goto V_63;
F_37 ( & V_11 -> V_49 , V_64 ) ;
F_35 (q, hctx, i) {
V_34 = F_31 ( V_22 ) ;
if ( V_34 )
break;
}
if ( V_34 )
F_33 ( V_53 ) ;
else
V_11 -> V_56 = true ;
V_63:
F_39 () ;
return V_34 ;
}
void F_47 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_40 ;
if ( ! V_11 -> V_56 )
return;
F_35 (q, hctx, i)
F_28 ( V_22 ) ;
}
int F_48 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_40 , V_34 = 0 ;
if ( ! V_11 -> V_56 )
return V_34 ;
F_35 (q, hctx, i) {
V_34 = F_31 ( V_22 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
