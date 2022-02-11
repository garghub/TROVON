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
T_1 V_32 ;
F_16 ( & V_22 -> V_33 ) ;
V_32 = sprintf ( V_5 , L_9 , ! ! ( V_22 -> V_42 & V_43 ) ) ;
F_17 ( & V_22 -> V_33 ) ;
return V_32 ;
}
static T_1 F_23 ( struct V_21 * V_22 ,
const char * V_5 , T_2 V_44 )
{
struct V_8 * V_9 ;
unsigned long V_32 ;
unsigned int V_37 ;
if ( F_24 ( V_5 , 10 , & V_32 ) ) {
F_25 ( L_10 , V_5 ) ;
return - V_45 ;
}
F_16 ( & V_22 -> V_33 ) ;
if ( V_32 )
V_22 -> V_42 |= V_43 ;
else
V_22 -> V_42 &= ~ V_43 ;
F_17 ( & V_22 -> V_33 ) ;
F_26 (hctx, ctx, i)
V_9 -> V_46 = ! ! V_32 ;
return V_44 ;
}
static T_1 F_27 ( struct V_21 * V_22 , char * V_5 )
{
return F_28 ( V_22 -> V_47 , V_5 ) ;
}
static T_1 F_29 ( struct V_21 * V_22 , char * V_5 )
{
unsigned int V_37 , V_48 , V_49 = 1 ;
T_1 V_32 = 0 ;
F_30 () ;
F_31 (i) {
V_48 = V_22 -> V_13 -> V_50 [ V_37 ] ;
if ( V_48 != V_22 -> V_48 )
continue;
if ( V_49 )
V_32 += sprintf ( V_32 + V_5 , L_11 , V_37 ) ;
else
V_32 += sprintf ( V_32 + V_5 , L_12 , V_37 ) ;
V_49 = 0 ;
}
F_32 () ;
V_32 += sprintf ( V_32 + V_5 , L_13 ) ;
return V_32 ;
}
void F_33 ( struct V_51 * V_52 )
{
struct V_10 * V_11 = V_52 -> V_13 ;
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_37 , V_53 ;
F_34 (q, hctx, i) {
F_26 (hctx, ctx, j) {
F_35 ( & V_9 -> V_2 ) ;
F_36 ( & V_9 -> V_2 ) ;
}
F_35 ( & V_22 -> V_2 ) ;
F_36 ( & V_22 -> V_2 ) ;
}
F_37 ( & V_11 -> V_54 , V_55 ) ;
F_35 ( & V_11 -> V_54 ) ;
F_36 ( & V_11 -> V_54 ) ;
F_36 ( & F_38 ( V_52 ) -> V_2 ) ;
}
int F_39 ( struct V_51 * V_52 )
{
struct V_56 * V_57 = F_38 ( V_52 ) ;
struct V_10 * V_11 = V_52 -> V_13 ;
struct V_21 * V_22 ;
struct V_8 * V_9 ;
int V_32 , V_37 , V_53 ;
F_40 ( & V_11 -> V_54 , & V_58 ) ;
V_32 = F_41 ( & V_11 -> V_54 , F_42 ( & V_57 -> V_2 ) , L_14 , L_15 ) ;
if ( V_32 < 0 )
return V_32 ;
F_37 ( & V_11 -> V_54 , V_59 ) ;
F_34 (q, hctx, i) {
F_40 ( & V_22 -> V_2 , & V_60 ) ;
V_32 = F_41 ( & V_22 -> V_2 , & V_11 -> V_54 , L_11 , V_37 ) ;
if ( V_32 )
break;
if ( ! V_22 -> V_61 )
continue;
F_26 (hctx, ctx, j) {
F_40 ( & V_9 -> V_2 , & V_62 ) ;
V_32 = F_41 ( & V_9 -> V_2 , & V_22 -> V_2 , L_16 , V_9 -> V_63 ) ;
if ( V_32 )
break;
}
}
if ( V_32 ) {
F_33 ( V_52 ) ;
return V_32 ;
}
return 0 ;
}
