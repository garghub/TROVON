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
static long F_12 ( struct V_10 * V_11 , unsigned int V_25 , unsigned long V_26 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
if ( ! V_4 -> V_15 -> V_27 )
return - V_28 ;
if ( ! F_9 ( V_4 ) )
return - V_18 ;
return V_4 -> V_15 -> V_27 ( V_11 , V_25 , V_26 ) ;
}
static int F_13 ( struct V_29 * V_29 , struct V_10 * V_11 )
{
struct V_3 * V_4 ;
int V_30 ;
F_3 ( & V_5 ) ;
V_4 = F_14 ( V_29 -> V_31 , struct V_3 , V_6 ) ;
if ( ! F_9 ( V_4 ) ) {
F_6 ( & V_5 ) ;
return - V_32 ;
}
F_15 ( & V_4 -> V_33 ) ;
F_6 ( & V_5 ) ;
V_11 -> V_34 = V_4 ;
if ( V_4 -> V_15 -> V_35 ) {
V_30 = V_4 -> V_15 -> V_35 ( V_11 ) ;
if ( V_30 ) {
F_16 ( & V_4 -> V_33 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_17 ( struct V_29 * V_29 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_8 ( V_11 ) ;
int V_30 = 0 ;
if ( V_4 -> V_15 -> V_9 )
V_4 -> V_15 -> V_9 ( V_11 ) ;
F_16 ( & V_4 -> V_33 ) ;
V_11 -> V_34 = NULL ;
return V_30 ;
}
int T_5 F_18 ( struct V_3 * V_4 )
{
int V_7 ;
int V_30 ;
F_3 ( & V_5 ) ;
V_7 = F_19 ( V_8 , V_36 , 0 ) ;
if ( V_7 == V_36 ) {
F_6 ( & V_5 ) ;
F_20 ( L_1 ) ;
return - V_37 ;
}
F_21 ( V_7 , V_8 ) ;
F_6 ( & V_5 ) ;
V_4 -> V_7 = V_7 ;
F_22 ( & V_4 -> V_6 , & V_38 ) ;
V_4 -> V_6 . V_39 = V_4 -> V_15 -> V_39 ;
V_30 = F_23 ( & V_4 -> V_6 , F_24 ( F_25 ( V_40 ) , V_4 -> V_7 ) , 1 ) ;
if ( V_30 < 0 ) {
F_20 ( L_2 , V_41 ) ;
goto error;
}
V_4 -> V_33 . V_42 = & V_43 ;
V_4 -> V_33 . V_44 = F_24 ( F_25 ( V_40 ) , V_4 -> V_7 ) ;
V_4 -> V_33 . V_9 = F_1 ;
if ( V_4 -> V_45 )
V_4 -> V_33 . V_45 = V_4 -> V_45 ;
F_26 ( & V_4 -> V_33 , L_3 , V_4 -> V_7 ) ;
V_30 = F_27 ( & V_4 -> V_33 ) ;
if ( V_30 < 0 ) {
F_20 ( L_4 , V_41 ) ;
goto error;
}
F_21 ( V_46 , & V_4 -> V_47 ) ;
return 0 ;
error:
F_4 ( & V_4 -> V_6 ) ;
F_5 ( V_4 -> V_7 , V_8 ) ;
return V_30 ;
}
void F_28 ( struct V_3 * V_4 )
{
if ( ! F_9 ( V_4 ) )
return;
F_3 ( & V_5 ) ;
F_5 ( V_46 , & V_4 -> V_47 ) ;
F_6 ( & V_5 ) ;
F_29 ( & V_4 -> V_33 ) ;
}
static int T_6 F_30 ( void )
{
int V_30 ;
F_31 ( L_5 ) ;
V_30 = F_32 ( & V_40 , 0 , V_36 ,
V_48 ) ;
if ( V_30 < 0 ) {
F_33 ( L_6 ) ;
return V_30 ;
}
V_30 = F_34 ( & V_43 ) ;
if ( V_30 < 0 ) {
F_35 ( V_40 , V_36 ) ;
F_33 ( L_7 ) ;
return - V_18 ;
}
return 0 ;
}
static void T_7 F_36 ( void )
{
F_37 ( & V_43 ) ;
F_35 ( V_40 , V_36 ) ;
}
