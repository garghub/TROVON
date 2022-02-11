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
if ( ! V_2 -> V_9 && V_2 -> V_10 > V_2 -> V_11 ) {
F_8 ( L_1 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
}
}
int F_9 ( struct V_1 * V_2 ,
unsigned int V_12 , struct V_13 * V_14 )
{
unsigned int V_15 = 0 ;
int V_16 = 0 ;
F_7 ( V_2 ) ;
if ( ! F_10 ( V_2 , V_12 ) && V_12 ) {
V_2 -> V_17 = V_12 ;
return V_16 ;
}
if ( V_12 )
V_16 = - V_18 ;
if ( V_14 == NULL || V_14 -> V_19 == NULL )
return V_16 ;
F_11 ( V_14 -> V_19 , L_2 , & V_15 ) ;
if ( ! F_10 ( V_2 , V_15 ) && V_15 )
V_2 -> V_17 = V_15 ;
else
V_16 = - V_18 ;
return V_16 ;
}
static int F_12 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
struct V_1 * V_2 = F_13 ( V_21 , struct V_1 ,
V_24 ) ;
if ( V_22 == V_25 || V_22 == V_26 ) {
if ( F_14 ( V_2 ) ) {
int V_16 ;
V_16 = V_2 -> V_27 -> V_28 ( V_2 ) ;
if ( V_16 )
return V_29 ;
}
}
return V_30 ;
}
static int F_15 ( struct V_20 * V_21 ,
unsigned long V_31 , void * V_23 )
{
struct V_1 * V_2 = F_13 ( V_21 , struct V_1 ,
V_32 ) ;
int V_16 ;
V_16 = V_2 -> V_27 -> V_33 ( V_2 , V_31 , V_23 ) ;
if ( V_16 )
return V_29 ;
return V_30 ;
}
void F_16 ( struct V_1 * V_2 , int V_34 )
{
V_2 -> V_32 . V_34 = V_34 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_16 , V_35 = - 1 ;
if ( V_2 == NULL || V_2 -> V_36 == NULL || V_2 -> V_27 == NULL )
return - V_18 ;
if ( ! V_2 -> V_27 -> V_37 || ( ! V_2 -> V_27 -> V_28 && ! V_2 -> V_9 ) )
return - V_18 ;
F_7 ( V_2 ) ;
if ( V_2 -> V_38 ) {
V_16 = F_18 ( V_2 -> V_38 -> V_19 , L_3 ) ;
if ( V_16 >= 0 )
V_35 = F_19 ( & V_39 , V_16 ,
V_16 + 1 , V_40 ) ;
}
if ( V_35 < 0 )
V_35 = F_19 ( & V_39 , 0 , V_41 , V_40 ) ;
if ( V_35 < 0 )
return V_35 ;
V_2 -> V_35 = V_35 ;
V_16 = F_20 ( V_2 ) ;
if ( V_16 ) {
F_21 ( & V_39 , V_35 ) ;
if ( ! ( V_35 == 0 && V_16 == - V_42 ) )
return V_16 ;
V_35 = F_19 ( & V_39 , 1 , V_41 , V_40 ) ;
if ( V_35 < 0 )
return V_35 ;
V_2 -> V_35 = V_35 ;
V_16 = F_20 ( V_2 ) ;
if ( V_16 ) {
F_21 ( & V_39 , V_35 ) ;
return V_16 ;
}
}
if ( F_22 ( V_43 , & V_2 -> V_44 ) ) {
V_2 -> V_24 . V_45 = F_12 ;
V_16 = F_23 ( & V_2 -> V_24 ) ;
if ( V_16 ) {
F_24 ( L_4 ,
V_2 -> V_35 , V_16 ) ;
F_25 ( V_2 ) ;
F_21 ( & V_39 , V_2 -> V_35 ) ;
return V_16 ;
}
}
if ( V_2 -> V_27 -> V_33 ) {
V_2 -> V_32 . V_45 = F_15 ;
V_16 = F_26 ( & V_2 -> V_32 ) ;
if ( V_16 )
F_27 ( L_5 ,
V_2 -> V_35 , V_16 ) ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_16 ;
F_29 ( & V_46 ) ;
if ( V_47 )
V_16 = F_17 ( V_2 ) ;
else
V_16 = F_1 ( V_2 ) ;
F_30 ( & V_46 ) ;
return V_16 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_27 -> V_33 )
F_32 ( & V_2 -> V_32 ) ;
if ( F_22 ( V_43 , & V_2 -> V_44 ) )
F_33 ( & V_2 -> V_24 ) ;
F_25 ( V_2 ) ;
F_21 ( & V_39 , V_2 -> V_35 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_29 ( & V_46 ) ;
if ( V_47 )
F_31 ( V_2 ) ;
else
F_3 ( V_2 ) ;
F_30 ( & V_46 ) ;
}
static void F_35 ( struct V_13 * V_14 , void * V_48 )
{
F_34 ( * (struct V_1 * * ) V_48 ) ;
}
int F_36 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_1 * * V_49 ;
int V_16 ;
V_49 = F_37 ( F_35 , sizeof( * V_49 ) ,
V_40 ) ;
if ( ! V_49 )
return - V_50 ;
V_16 = F_28 ( V_2 ) ;
if ( ! V_16 ) {
* V_49 = V_2 ;
F_38 ( V_14 , V_49 ) ;
} else {
F_39 ( V_49 ) ;
}
return V_16 ;
}
static int T_1 F_40 ( void )
{
F_29 ( & V_46 ) ;
V_47 = true ;
while ( ! F_41 ( & V_4 ) ) {
struct V_1 * V_2 ;
V_2 = F_42 ( & V_4 ,
struct V_1 , V_3 ) ;
F_6 ( & V_2 -> V_3 ) ;
F_17 ( V_2 ) ;
}
F_30 ( & V_46 ) ;
return 0 ;
}
static int T_1 F_43 ( void )
{
int V_51 ;
V_51 = F_44 () ;
if ( V_51 < 0 )
return V_51 ;
F_40 () ;
return 0 ;
}
static void T_2 F_45 ( void )
{
F_46 () ;
F_47 ( & V_39 ) ;
}
