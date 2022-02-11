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
static int F_12 ( struct V_19 * V_20 ,
unsigned long V_21 , void * V_22 )
{
struct V_1 * V_2 = F_13 ( V_20 , struct V_1 ,
V_23 ) ;
if ( V_21 == V_24 || V_21 == V_25 ) {
if ( F_14 ( V_2 ) ) {
int V_15 ;
V_15 = V_2 -> V_26 -> V_27 ( V_2 ) ;
if ( V_15 )
return V_28 ;
}
}
return V_29 ;
}
static int F_15 ( struct V_19 * V_20 ,
unsigned long V_30 , void * V_22 )
{
struct V_1 * V_2 = F_13 ( V_20 , struct V_1 ,
V_31 ) ;
int V_15 ;
V_15 = V_2 -> V_26 -> V_32 ( V_2 ) ;
if ( V_15 )
return V_28 ;
return V_29 ;
}
void F_16 ( struct V_1 * V_2 , int V_33 )
{
V_2 -> V_31 . V_33 = V_33 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 , V_34 = - 1 ;
if ( V_2 == NULL || V_2 -> V_35 == NULL || V_2 -> V_26 == NULL )
return - V_17 ;
if ( V_2 -> V_26 -> V_36 == NULL || V_2 -> V_26 -> V_27 == NULL )
return - V_17 ;
F_7 ( V_2 ) ;
if ( V_2 -> V_37 ) {
V_15 = F_18 ( V_2 -> V_37 -> V_18 , L_3 ) ;
if ( V_15 >= 0 )
V_34 = F_19 ( & V_38 , V_15 ,
V_15 + 1 , V_39 ) ;
}
if ( V_34 < 0 )
V_34 = F_19 ( & V_38 , 0 , V_40 , V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_34 = V_34 ;
V_15 = F_20 ( V_2 ) ;
if ( V_15 ) {
F_21 ( & V_38 , V_34 ) ;
if ( ! ( V_34 == 0 && V_15 == - V_41 ) )
return V_15 ;
V_34 = F_19 ( & V_38 , 1 , V_40 , V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 -> V_34 = V_34 ;
V_15 = F_20 ( V_2 ) ;
if ( V_15 ) {
F_21 ( & V_38 , V_34 ) ;
return V_15 ;
}
}
if ( F_22 ( V_42 , & V_2 -> V_43 ) ) {
V_2 -> V_23 . V_44 = F_12 ;
V_15 = F_23 ( & V_2 -> V_23 ) ;
if ( V_15 ) {
F_24 ( L_4 ,
V_2 -> V_34 , V_15 ) ;
F_25 ( V_2 ) ;
F_21 ( & V_38 , V_2 -> V_34 ) ;
return V_15 ;
}
}
if ( V_2 -> V_26 -> V_32 ) {
V_2 -> V_31 . V_44 = F_15 ;
V_15 = F_26 ( & V_2 -> V_31 ) ;
if ( V_15 )
F_27 ( L_5 ,
V_2 -> V_34 , V_15 ) ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_15 ;
F_29 ( & V_45 ) ;
if ( V_46 )
V_15 = F_17 ( V_2 ) ;
else
V_15 = F_1 ( V_2 ) ;
F_30 ( & V_45 ) ;
return V_15 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_26 -> V_32 )
F_32 ( & V_2 -> V_31 ) ;
if ( F_22 ( V_42 , & V_2 -> V_43 ) )
F_33 ( & V_2 -> V_23 ) ;
F_25 ( V_2 ) ;
F_21 ( & V_38 , V_2 -> V_34 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_29 ( & V_45 ) ;
if ( V_46 )
F_31 ( V_2 ) ;
else
F_3 ( V_2 ) ;
F_30 ( & V_45 ) ;
}
static int T_1 F_35 ( void )
{
F_29 ( & V_45 ) ;
V_46 = true ;
while ( ! F_36 ( & V_4 ) ) {
struct V_1 * V_2 ;
V_2 = F_37 ( & V_4 ,
struct V_1 , V_3 ) ;
F_6 ( & V_2 -> V_3 ) ;
F_17 ( V_2 ) ;
}
F_30 ( & V_45 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
int V_47 ;
V_47 = F_39 () ;
if ( V_47 < 0 )
return V_47 ;
F_35 () ;
return 0 ;
}
static void T_2 F_40 ( void )
{
F_41 () ;
F_42 ( & V_38 ) ;
}
