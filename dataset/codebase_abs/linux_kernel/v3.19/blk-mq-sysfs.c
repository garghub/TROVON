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
char * V_29 = V_5 ;
struct V_30 * V_31 ;
V_5 += sprintf ( V_5 , L_3 , V_28 ) ;
F_14 (rq, list, queuelist)
V_5 += sprintf ( V_5 , L_4 , V_31 ) ;
return V_5 - V_29 ;
}
static T_1 F_15 ( struct V_8 * V_9 , char * V_5 )
{
T_1 V_32 ;
F_16 ( & V_9 -> V_33 ) ;
V_32 = F_13 ( V_5 , & V_9 -> V_34 , L_5 ) ;
F_17 ( & V_9 -> V_33 ) ;
return V_32 ;
}
static T_1 F_18 ( struct V_21 * V_22 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 , V_22 -> V_35 ) ;
}
static T_1 F_19 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_22 -> V_36 ) ;
}
static T_1 F_20 ( struct V_21 * V_22 ,
char * V_5 )
{
char * V_29 = V_5 ;
int V_37 ;
V_5 += sprintf ( V_5 , L_6 , 0U , V_22 -> V_38 [ 0 ] ) ;
for ( V_37 = 1 ; V_37 < V_39 ; V_37 ++ ) {
unsigned long V_40 = 1U << ( V_37 - 1 ) ;
V_5 += sprintf ( V_5 , L_7 , V_40 , V_22 -> V_38 [ V_37 ] ) ;
}
return V_5 - V_29 ;
}
static T_1 F_21 ( struct V_21 * V_22 ,
char * V_5 )
{
T_1 V_32 ;
F_16 ( & V_22 -> V_33 ) ;
V_32 = F_13 ( V_5 , & V_22 -> V_41 , L_8 ) ;
F_17 ( & V_22 -> V_33 ) ;
return V_32 ;
}
static T_1 F_22 ( struct V_21 * V_22 , char * V_5 )
{
return F_23 ( V_22 -> V_42 , V_5 ) ;
}
static T_1 F_24 ( struct V_21 * V_22 , char * V_5 )
{
return sprintf ( V_5 , L_9 , F_25 ( & V_22 -> V_43 ) ) ;
}
static T_1 F_26 ( struct V_21 * V_22 , char * V_5 )
{
unsigned int V_37 , V_44 = 1 ;
T_1 V_32 = 0 ;
F_27 () ;
F_28 (i, hctx->cpumask) {
if ( V_44 )
V_32 += sprintf ( V_32 + V_5 , L_10 , V_37 ) ;
else
V_32 += sprintf ( V_32 + V_5 , L_11 , V_37 ) ;
V_44 = 0 ;
}
F_29 () ;
V_32 += sprintf ( V_32 + V_5 , L_12 ) ;
return V_32 ;
}
static void F_30 ( struct V_21 * V_22 )
{
struct V_8 * V_9 ;
int V_37 ;
if ( ! V_22 -> V_45 || ! ( V_22 -> V_46 & V_47 ) )
return;
F_31 (hctx, ctx, i)
F_32 ( & V_9 -> V_2 ) ;
F_32 ( & V_22 -> V_2 ) ;
}
static int F_33 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_13 ;
struct V_8 * V_9 ;
int V_37 , V_32 ;
if ( ! V_22 -> V_45 || ! ( V_22 -> V_46 & V_47 ) )
return 0 ;
V_32 = F_34 ( & V_22 -> V_2 , & V_11 -> V_48 , L_10 , V_22 -> V_49 ) ;
if ( V_32 )
return V_32 ;
F_31 (hctx, ctx, i) {
V_32 = F_34 ( & V_9 -> V_2 , & V_22 -> V_2 , L_13 , V_9 -> V_50 ) ;
if ( V_32 )
break;
}
return V_32 ;
}
void F_35 ( struct V_51 * V_52 )
{
struct V_10 * V_11 = V_52 -> V_13 ;
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_37 , V_53 ;
F_36 (q, hctx, i) {
F_30 ( V_22 ) ;
F_31 (hctx, ctx, j)
F_37 ( & V_9 -> V_2 ) ;
F_37 ( & V_22 -> V_2 ) ;
}
F_38 ( & V_11 -> V_48 , V_54 ) ;
F_32 ( & V_11 -> V_48 ) ;
F_37 ( & V_11 -> V_48 ) ;
F_37 ( & F_39 ( V_52 ) -> V_2 ) ;
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_37 ;
F_41 ( & V_11 -> V_48 , & V_55 ) ;
F_36 (q, hctx, i)
F_41 ( & V_22 -> V_2 , & V_56 ) ;
F_42 (q, ctx, i)
F_41 ( & V_9 -> V_2 , & V_57 ) ;
}
void F_43 ( struct V_10 * V_11 )
{
F_44 ( & V_11 -> V_58 ) ;
}
int F_45 ( struct V_51 * V_52 )
{
struct V_59 * V_60 = F_39 ( V_52 ) ;
struct V_10 * V_11 = V_52 -> V_13 ;
struct V_21 * V_22 ;
int V_32 , V_37 ;
F_40 ( V_11 ) ;
V_32 = F_34 ( & V_11 -> V_48 , F_46 ( & V_60 -> V_2 ) , L_14 , L_15 ) ;
if ( V_32 < 0 )
return V_32 ;
F_38 ( & V_11 -> V_48 , V_61 ) ;
F_36 (q, hctx, i) {
V_22 -> V_46 |= V_47 ;
V_32 = F_33 ( V_22 ) ;
if ( V_32 )
break;
}
if ( V_32 ) {
F_35 ( V_52 ) ;
return V_32 ;
}
return 0 ;
}
void F_47 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_37 ;
F_36 (q, hctx, i)
F_30 ( V_22 ) ;
}
int F_48 ( struct V_10 * V_11 )
{
struct V_21 * V_22 ;
int V_37 , V_32 = 0 ;
F_36 (q, hctx, i) {
V_32 = F_33 ( V_22 ) ;
if ( V_32 )
break;
}
return V_32 ;
}
