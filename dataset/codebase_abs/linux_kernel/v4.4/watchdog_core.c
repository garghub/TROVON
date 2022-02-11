static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ,
& V_4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_7 ;
struct V_1 * V_8 ;
F_4 (p, n, &wtd_deferred_reg_list) {
V_8 = F_5 ( V_6 , struct V_1 ,
V_3 ) ;
if ( V_8 == V_2 ) {
F_6 ( & V_8 -> V_3 ) ;
break;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 > V_2 -> V_10 ) {
F_8 ( L_1 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
}
}
int F_9 ( struct V_1 * V_2 ,
unsigned int V_11 , struct V_12 * V_13 )
{
unsigned int V_14 = 0 ;
int V_15 = 0 ;
F_7 ( V_2 ) ;
if ( ! F_10 ( V_2 , V_11 ) && V_11 ) {
V_2 -> V_16 = V_11 ;
return V_15 ;
}
if ( V_11 )
V_15 = - V_17 ;
if ( V_13 == NULL || V_13 -> V_18 == NULL )
return V_15 ;
F_11 ( V_13 -> V_18 , L_2 , & V_14 ) ;
if ( ! F_10 ( V_2 , V_14 ) && V_14 )
V_2 -> V_16 = V_14 ;
else
V_15 = - V_17 ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_15 , V_19 = - 1 , V_20 ;
if ( V_2 == NULL || V_2 -> V_21 == NULL || V_2 -> V_22 == NULL )
return - V_17 ;
if ( V_2 -> V_22 -> V_23 == NULL || V_2 -> V_22 -> V_24 == NULL )
return - V_17 ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_26 ) {
V_15 = F_14 ( V_2 -> V_26 -> V_18 , L_3 ) ;
if ( V_15 >= 0 )
V_19 = F_15 ( & V_27 , V_15 ,
V_15 + 1 , V_28 ) ;
}
if ( V_19 < 0 )
V_19 = F_15 ( & V_27 , 0 , V_29 , V_28 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_19 = V_19 ;
V_15 = F_16 ( V_2 ) ;
if ( V_15 ) {
F_17 ( & V_27 , V_19 ) ;
if ( ! ( V_19 == 0 && V_15 == - V_30 ) )
return V_15 ;
V_19 = F_15 ( & V_27 , 1 , V_29 , V_28 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_19 = V_19 ;
V_15 = F_16 ( V_2 ) ;
if ( V_15 ) {
F_17 ( & V_27 , V_19 ) ;
return V_15 ;
}
}
V_20 = V_2 -> V_31 . V_13 ;
V_2 -> V_13 = F_18 ( V_32 , V_2 -> V_26 , V_20 ,
NULL , L_4 , V_2 -> V_19 ) ;
if ( F_19 ( V_2 -> V_13 ) ) {
F_20 ( V_2 ) ;
F_17 ( & V_27 , V_19 ) ;
V_15 = F_21 ( V_2 -> V_13 ) ;
return V_15 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_15 ;
F_23 ( & V_33 ) ;
if ( V_34 )
V_15 = F_12 ( V_2 ) ;
else
V_15 = F_1 ( V_2 ) ;
F_24 ( & V_33 ) ;
return V_15 ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_15 ;
int V_20 ;
if ( V_2 == NULL )
return;
V_20 = V_2 -> V_31 . V_13 ;
V_15 = F_20 ( V_2 ) ;
if ( V_15 )
F_26 ( L_5 , V_15 ) ;
F_27 ( V_32 , V_20 ) ;
F_17 ( & V_27 , V_2 -> V_19 ) ;
V_2 -> V_13 = NULL ;
}
void F_28 ( struct V_1 * V_2 )
{
F_23 ( & V_33 ) ;
if ( V_34 )
F_25 ( V_2 ) ;
else
F_3 ( V_2 ) ;
F_24 ( & V_33 ) ;
}
static int T_1 F_29 ( void )
{
F_23 ( & V_33 ) ;
V_34 = true ;
while ( ! F_30 ( & V_4 ) ) {
struct V_1 * V_2 ;
V_2 = F_31 ( & V_4 ,
struct V_1 , V_3 ) ;
F_6 ( & V_2 -> V_3 ) ;
F_12 ( V_2 ) ;
}
F_24 ( & V_33 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
int V_35 ;
V_32 = F_33 ( V_36 , L_3 ) ;
if ( F_19 ( V_32 ) ) {
F_26 ( L_6 ) ;
return F_21 ( V_32 ) ;
}
V_35 = F_34 () ;
if ( V_35 < 0 ) {
F_35 ( V_32 ) ;
return V_35 ;
}
F_29 () ;
return 0 ;
}
static void T_2 F_36 ( void )
{
F_37 () ;
F_35 ( V_32 ) ;
F_38 ( & V_27 ) ;
}
