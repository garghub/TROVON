static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_5 ) ;
F_4 ( & V_4 -> V_6 ) ;
F_5 ( V_4 -> V_7 , V_8 ) ;
F_6 ( & V_5 ) ;
if ( V_4 -> V_9 )
V_4 -> V_9 ( V_4 ) ;
}
static T_1 F_7 ( struct V_10 * V_11 , char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
if ( ! V_4 -> V_15 -> V_16 )
return - V_17 ;
if ( ! F_9 ( V_4 ) )
return - V_18 ;
return V_4 -> V_15 -> V_16 ( V_11 , V_12 , V_13 , V_14 ) ;
}
static T_1 F_10 ( struct V_10 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
if ( ! V_4 -> V_15 -> V_19 )
return - V_17 ;
if ( ! F_9 ( V_4 ) )
return - V_18 ;
return V_4 -> V_15 -> V_19 ( V_11 , V_12 , V_13 , V_14 ) ;
}
static unsigned int F_11 ( struct V_10 * V_11 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
if ( ! F_9 ( V_4 ) )
return V_22 | V_23 ;
if ( ! V_4 -> V_15 -> V_21 )
return V_24 ;
return V_4 -> V_15 -> V_21 ( V_11 , V_21 ) ;
}
static long
F_12 ( struct V_10 * V_11 , unsigned int V_25 , unsigned long V_26 ,
long (* F_13)( struct V_10 * V_11 , unsigned int V_25 ,
unsigned long V_26 ) )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
if ( ! F_13 )
return - V_27 ;
if ( ! F_9 ( V_4 ) )
return - V_18 ;
return F_13 ( V_11 , V_25 , V_26 ) ;
}
static long F_14 ( struct V_10 * V_11 , unsigned int V_25 , unsigned long V_26 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
return F_12 ( V_11 , V_25 , V_26 , V_4 -> V_15 -> V_28 ) ;
}
static long F_15 ( struct V_10 * V_11 , unsigned int V_25 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
return F_12 ( V_11 , V_25 , V_26 , V_4 -> V_15 -> V_29 ) ;
}
static int F_16 ( struct V_30 * V_30 , struct V_10 * V_11 )
{
struct V_3 * V_4 ;
int V_31 ;
F_3 ( & V_5 ) ;
V_4 = F_17 ( V_30 -> V_32 , struct V_3 , V_6 ) ;
if ( ! F_9 ( V_4 ) ) {
F_6 ( & V_5 ) ;
return - V_33 ;
}
F_18 ( & V_4 -> V_34 ) ;
F_6 ( & V_5 ) ;
V_11 -> V_35 = V_4 ;
if ( V_4 -> V_15 -> V_36 ) {
V_31 = V_4 -> V_15 -> V_36 ( V_11 ) ;
if ( V_31 ) {
F_19 ( & V_4 -> V_34 ) ;
return V_31 ;
}
}
return 0 ;
}
static int F_20 ( struct V_30 * V_30 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
int V_31 = 0 ;
if ( V_4 -> V_15 -> V_9 )
V_4 -> V_15 -> V_9 ( V_11 ) ;
F_19 ( & V_4 -> V_34 ) ;
V_11 -> V_35 = NULL ;
return V_31 ;
}
int T_5 F_21 ( struct V_3 * V_4 )
{
int V_7 ;
int V_31 ;
F_3 ( & V_5 ) ;
V_7 = F_22 ( V_8 , V_37 , 0 ) ;
if ( V_7 == V_37 ) {
F_6 ( & V_5 ) ;
F_23 ( L_1 ) ;
return - V_38 ;
}
F_24 ( V_7 , V_8 ) ;
F_6 ( & V_5 ) ;
V_4 -> V_7 = V_7 ;
F_25 ( & V_4 -> V_6 , & V_39 ) ;
V_4 -> V_6 . V_40 = V_4 -> V_15 -> V_40 ;
V_31 = F_26 ( & V_4 -> V_6 , F_27 ( F_28 ( V_41 ) , V_4 -> V_7 ) , 1 ) ;
if ( V_31 < 0 ) {
F_23 ( L_2 , V_42 ) ;
goto error;
}
V_4 -> V_34 . V_43 = & V_44 ;
V_4 -> V_34 . V_45 = F_27 ( F_28 ( V_41 ) , V_4 -> V_7 ) ;
V_4 -> V_34 . V_9 = F_1 ;
if ( V_4 -> V_46 )
V_4 -> V_34 . V_46 = V_4 -> V_46 ;
F_29 ( & V_4 -> V_34 , L_3 , V_4 -> V_7 ) ;
V_31 = F_30 ( & V_4 -> V_34 ) ;
if ( V_31 < 0 ) {
F_23 ( L_4 , V_42 ) ;
goto error;
}
F_24 ( V_47 , & V_4 -> V_48 ) ;
return 0 ;
error:
F_4 ( & V_4 -> V_6 ) ;
F_5 ( V_4 -> V_7 , V_8 ) ;
return V_31 ;
}
void F_31 ( struct V_3 * V_4 )
{
if ( ! F_9 ( V_4 ) )
return;
F_3 ( & V_5 ) ;
F_5 ( V_47 , & V_4 -> V_48 ) ;
F_6 ( & V_5 ) ;
F_32 ( & V_4 -> V_34 ) ;
}
static int T_6 F_33 ( void )
{
int V_31 ;
F_34 ( L_5 ) ;
V_31 = F_35 ( & V_41 , 0 , V_37 ,
V_49 ) ;
if ( V_31 < 0 ) {
F_36 ( L_6 ) ;
return V_31 ;
}
V_31 = F_37 ( & V_44 ) ;
if ( V_31 < 0 ) {
F_38 ( V_41 , V_37 ) ;
F_36 ( L_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_44 ) ;
F_38 ( V_41 , V_37 ) ;
}
