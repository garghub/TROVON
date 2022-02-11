static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
int V_3 ;
V_2 -> V_4 = F_3 ( V_2 -> V_5 , L_1 , & V_3 ) ;
if ( ! V_3 )
return;
V_2 -> V_4 = ~ 0 ;
if ( V_3 != - V_6 )
F_4 ( V_2 -> V_5 , L_2 , V_3 ) ;
#endif
}
static int F_5 ( struct V_7 * V_8 , int V_9 )
{
#ifdef F_2
struct V_1 * V_2 = F_6 ( V_8 ) ;
int V_3 ;
if ( V_9 > V_2 -> V_4 ) {
F_7 ( V_2 -> V_5 , L_3 ,
V_2 -> V_4 ) ;
return - V_10 ;
}
V_3 = F_8 ( V_8 , V_9 ) ;
if ( V_3 ) {
F_9 ( & V_8 -> V_11 , L_4 , V_3 ) ;
return V_3 ;
}
V_2 -> V_9 = V_9 ;
F_10 ( & V_8 -> V_11 , L_5 , V_2 -> V_9 ) ;
return V_9 ;
#endif
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
#ifdef F_2
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( F_12 ( V_8 ) ) {
F_9 ( & V_8 -> V_11 , L_6 ) ;
return - V_12 ;
}
V_2 -> V_9 = 0 ;
F_13 ( V_8 ) ;
F_10 ( & V_8 -> V_11 , L_7 ) ;
#endif
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , int V_9 )
{
if ( V_9 == 0 )
return F_11 ( V_8 ) ;
else
return F_5 ( V_8 , V_9 ) ;
}
static const struct V_13 *
F_15 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_13 * V_14 = NULL ;
struct V_15 * V_16 ;
const char * V_17 ;
char V_18 [ 256 ] ;
int V_19 , V_3 = 0 ;
int V_20 , V_21 ;
if ( ! V_2 -> V_22 ) {
F_16 ( & V_8 -> V_11 , L_8 ) ;
return NULL ;
}
V_17 = F_17 ( V_2 -> V_5 , L_9 ) ;
if ( ! V_17 ) {
F_16 ( & V_8 -> V_11 , L_10 ) ;
return NULL ;
}
V_19 = F_18 ( V_18 ) ;
V_19 -= snprintf ( V_18 , V_19 , L_11 , V_17 ) ;
for ( V_20 = 0 ; V_19 > 0 && V_20 < V_2 -> V_22 -> V_23 ; V_20 += V_21 ) {
V_16 = & V_2 -> V_22 -> V_24 [ V_20 ] ;
V_21 = 1 ;
while ( V_20 + V_21 < V_2 -> V_22 -> V_23 &&
V_16 -> V_25 == V_16 [ V_21 ] . V_25 )
V_21 ++ ;
V_19 -= snprintf ( & V_18 [ F_18 ( V_18 ) - V_19 ] , V_19 ,
L_12 , V_21 , V_16 -> V_25 / 1000 ) ;
}
if ( V_19 <= 0 )
return NULL ;
V_19 -= snprintf ( & V_18 [ F_18 ( V_18 ) - V_19 ] , V_19 , L_13 ) ;
if ( V_19 <= 0 )
return NULL ;
V_3 = F_19 ( & V_14 , V_18 , & V_8 -> V_11 ) ;
if ( V_3 )
return NULL ;
F_20 ( & V_8 -> V_11 , L_14 , V_18 ) ;
return V_14 ;
}
static int
F_21 ( struct V_7 * V_8 , struct V_1 * V_2 , struct V_26 * V_27 )
{
const struct V_13 * V_14 ;
T_1 V_28 ;
int V_3 ;
V_28 = F_22 ( V_2 -> V_5 ) ;
if ( F_23 ( V_28 ) != 0 ) {
F_20 ( & V_8 -> V_11 , L_15 ) ;
return 0 ;
}
V_14 = F_15 ( V_8 , V_2 ) ;
if ( ! V_14 )
return 0 ;
F_20 ( & V_8 -> V_11 , L_16 ) ;
V_3 = F_24 ( V_27 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_8 -> V_11 , L_17 ,
V_3 ) ;
goto V_29;
}
V_3 = F_25 ( V_27 , V_14 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_8 -> V_11 , L_18 , V_3 ) ;
goto V_29;
}
F_20 ( & V_8 -> V_11 , L_19 ) ;
V_29:
F_26 ( V_14 ) ;
return V_3 < 0 ? V_3 : 1 ;
}
static int F_27 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_3 ;
V_27 = F_28 ( V_2 -> V_5 ) ;
if ( F_29 ( V_27 ) ) {
V_3 = F_30 ( V_27 ) ;
F_16 ( & V_8 -> V_11 , L_20 , V_3 ) ;
return V_3 ;
}
V_3 = F_31 ( V_27 ) ;
if ( V_3 < 0 )
goto V_30;
V_2 -> V_22 = F_32 ( V_2 -> V_5 , V_27 ) ;
V_3 = F_21 ( V_8 , V_2 , V_27 ) ;
if ( V_3 < 0 ) {
F_33 ( V_2 -> V_22 ) ;
F_16 ( & V_8 -> V_11 , L_21 ) ;
goto V_30;
}
V_2 -> V_31 = ! ! V_3 ;
V_3 = 0 ;
V_30:
F_34 ( V_27 ) ;
return V_3 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_3 ;
V_27 = F_28 ( V_2 -> V_5 ) ;
if ( F_29 ( V_27 ) ) {
F_36 ( V_2 -> V_5 , L_22 ) ;
return;
}
V_3 = F_24 ( V_27 ) ;
if ( V_3 < 0 )
F_9 ( & V_2 -> V_8 -> V_11 , L_23 , V_3 ) ;
else
F_20 ( & V_2 -> V_8 -> V_11 , L_24 ) ;
F_34 ( V_27 ) ;
}
static int F_37 ( struct V_7 * V_8 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_3 ;
V_3 = F_38 ( V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
F_39 ( V_8 ) ;
V_3 = F_40 ( & V_8 -> V_11 ,
F_41 ( V_34 ) ) ;
if ( V_3 )
goto V_35;
V_3 = F_42 ( V_8 , V_36 ) ;
if ( V_3 < 0 ) {
F_16 ( & V_8 -> V_11 , L_25 ) ;
goto V_35;
}
V_2 = F_43 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 ) {
V_3 = - V_38 ;
goto V_39;
}
F_44 ( & V_2 -> V_24 ) ;
F_45 ( V_8 , V_2 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_5 = F_46 ( V_8 ) ;
if ( F_47 ( V_2 -> V_5 ) ) {
V_3 = F_30 ( V_2 -> V_5 ) ;
if ( V_3 >= 0 )
V_3 = - V_38 ;
goto V_40;
}
F_20 ( & V_8 -> V_11 , L_26 ,
F_17 ( V_2 -> V_5 , L_27 ) ,
F_17 ( V_2 -> V_5 , L_9 ) ,
F_17 ( V_2 -> V_5 , L_28 ) ,
F_17 ( V_2 -> V_5 , L_29 ) ,
F_17 ( V_2 -> V_5 , L_30 ) ) ;
V_3 = F_27 ( V_8 , V_2 ) ;
if ( V_3 )
goto V_41;
F_1 ( V_2 ) ;
V_3 = F_48 ( V_2 ) ;
if ( V_3 )
goto V_42;
return 0 ;
V_42:
if ( V_2 -> V_31 )
F_35 ( V_2 ) ;
F_33 ( V_2 -> V_22 ) ;
V_41:
F_49 ( V_2 -> V_5 ) ;
V_40:
F_45 ( V_8 , NULL ) ;
F_33 ( V_2 ) ;
V_39:
F_50 ( V_8 ) ;
V_35:
F_51 ( V_8 ) ;
return V_3 ;
}
static void F_52 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
if ( ! F_53 ( & V_2 -> V_24 ) )
F_54 ( V_2 ) ;
F_11 ( V_8 ) ;
if ( V_2 -> V_31 )
F_35 ( V_2 ) ;
F_45 ( V_8 , NULL ) ;
F_49 ( V_2 -> V_5 ) ;
F_33 ( V_2 -> V_22 ) ;
F_33 ( V_2 ) ;
F_50 ( V_8 ) ;
F_51 ( V_8 ) ;
}
static int T_2 F_55 ( void )
{
int V_3 ;
F_56 ( L_31 ,
V_36 ) ;
F_57 () ;
V_3 = F_58 ( & V_43 ) ;
if ( V_3 < 0 )
goto V_44;
V_3 = F_58 ( & V_45 ) ;
if ( V_3 )
goto V_46;
return V_3 ;
V_46:
F_59 ( & V_43 ) ;
V_44:
F_60 () ;
return V_3 ;
}
static void T_3 F_61 ( void )
{
F_59 ( & V_45 ) ;
F_59 ( & V_43 ) ;
F_60 () ;
}
