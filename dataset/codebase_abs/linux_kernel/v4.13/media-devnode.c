static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_5 ) ;
F_4 ( V_4 -> V_6 , V_7 ) ;
F_5 ( & V_5 ) ;
if ( V_4 -> V_8 )
V_4 -> V_8 ( V_4 ) ;
F_6 ( V_4 ) ;
F_7 ( L_1 , V_9 ) ;
}
static T_1 F_8 ( struct V_10 * V_11 , char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( ! V_4 -> V_15 -> V_16 )
return - V_17 ;
if ( ! F_10 ( V_4 ) )
return - V_18 ;
return V_4 -> V_15 -> V_16 ( V_11 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_11 ( struct V_10 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( ! V_4 -> V_15 -> V_19 )
return - V_17 ;
if ( ! F_10 ( V_4 ) )
return - V_18 ;
return V_4 -> V_15 -> V_19 ( V_11 , V_12 , V_13 , V_14 ) ;
}
static unsigned int F_12 ( struct V_10 * V_11 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( ! F_10 ( V_4 ) )
return V_22 | V_23 ;
if ( ! V_4 -> V_15 -> V_21 )
return V_24 ;
return V_4 -> V_15 -> V_21 ( V_11 , V_21 ) ;
}
static long
F_13 ( struct V_10 * V_11 , unsigned int V_25 , unsigned long V_26 ,
long (* F_14)( struct V_10 * V_11 , unsigned int V_25 ,
unsigned long V_26 ) )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( ! F_14 )
return - V_27 ;
if ( ! F_10 ( V_4 ) )
return - V_18 ;
return F_14 ( V_11 , V_25 , V_26 ) ;
}
static long F_15 ( struct V_10 * V_11 , unsigned int V_25 , unsigned long V_26 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
return F_13 ( V_11 , V_25 , V_26 , V_4 -> V_15 -> V_28 ) ;
}
static long F_16 ( struct V_10 * V_11 , unsigned int V_25 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
return F_13 ( V_11 , V_25 , V_26 , V_4 -> V_15 -> V_29 ) ;
}
static int F_17 ( struct V_30 * V_30 , struct V_10 * V_11 )
{
struct V_3 * V_4 ;
int V_31 ;
F_3 ( & V_5 ) ;
V_4 = F_18 ( V_30 -> V_32 , struct V_3 , V_33 ) ;
if ( ! F_10 ( V_4 ) ) {
F_5 ( & V_5 ) ;
return - V_34 ;
}
F_19 ( & V_4 -> V_35 ) ;
F_5 ( & V_5 ) ;
V_11 -> V_36 = V_4 ;
if ( V_4 -> V_15 -> V_37 ) {
V_31 = V_4 -> V_15 -> V_37 ( V_11 ) ;
if ( V_31 ) {
F_20 ( & V_4 -> V_35 ) ;
V_11 -> V_36 = NULL ;
return V_31 ;
}
}
return 0 ;
}
static int F_21 ( struct V_30 * V_30 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_9 ( V_11 ) ;
if ( V_4 -> V_15 -> V_8 )
V_4 -> V_15 -> V_8 ( V_11 ) ;
V_11 -> V_36 = NULL ;
F_20 ( & V_4 -> V_35 ) ;
F_7 ( L_2 , V_9 ) ;
return 0 ;
}
int T_5 F_22 ( struct V_38 * V_39 ,
struct V_3 * V_4 ,
struct V_40 * V_41 )
{
int V_6 ;
int V_31 ;
F_3 ( & V_5 ) ;
V_6 = F_23 ( V_7 , V_42 , 0 ) ;
if ( V_6 == V_42 ) {
F_5 ( & V_5 ) ;
F_24 ( L_3 ) ;
F_6 ( V_4 ) ;
return - V_43 ;
}
F_25 ( V_6 , V_7 ) ;
F_5 ( & V_5 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_44 = V_39 ;
V_4 -> V_35 . V_45 = & V_46 ;
V_4 -> V_35 . V_47 = F_26 ( F_27 ( V_48 ) , V_4 -> V_6 ) ;
V_4 -> V_35 . V_8 = F_1 ;
if ( V_4 -> V_49 )
V_4 -> V_35 . V_49 = V_4 -> V_49 ;
F_28 ( & V_4 -> V_35 , L_4 , V_4 -> V_6 ) ;
F_29 ( & V_4 -> V_35 ) ;
F_30 ( & V_4 -> V_33 , & V_50 ) ;
V_4 -> V_33 . V_41 = V_41 ;
V_31 = F_31 ( & V_4 -> V_33 , & V_4 -> V_35 ) ;
if ( V_31 < 0 ) {
F_24 ( L_5 , V_9 ) ;
goto V_51;
}
F_25 ( V_52 , & V_4 -> V_53 ) ;
return 0 ;
V_51:
F_3 ( & V_5 ) ;
F_4 ( V_4 -> V_6 , V_7 ) ;
V_4 -> V_44 = NULL ;
F_5 ( & V_5 ) ;
F_20 ( & V_4 -> V_35 ) ;
return V_31 ;
}
void F_32 ( struct V_3 * V_4 )
{
if ( ! F_10 ( V_4 ) )
return;
F_3 ( & V_5 ) ;
F_4 ( V_52 , & V_4 -> V_53 ) ;
F_5 ( & V_5 ) ;
}
void F_33 ( struct V_3 * V_4 )
{
F_3 ( & V_5 ) ;
F_34 ( & V_4 -> V_33 , & V_4 -> V_35 ) ;
F_5 ( & V_5 ) ;
V_4 -> V_44 = NULL ;
F_20 ( & V_4 -> V_35 ) ;
}
static int T_6 F_35 ( void )
{
int V_31 ;
F_36 ( L_6 ) ;
V_31 = F_37 ( & V_48 , 0 , V_42 ,
V_54 ) ;
if ( V_31 < 0 ) {
F_38 ( L_7 ) ;
return V_31 ;
}
V_31 = F_39 ( & V_46 ) ;
if ( V_31 < 0 ) {
F_40 ( V_48 , V_42 ) ;
F_38 ( L_8 ) ;
return - V_18 ;
}
return 0 ;
}
static void T_7 F_41 ( void )
{
F_42 ( & V_46 ) ;
F_40 ( V_48 , V_42 ) ;
}
