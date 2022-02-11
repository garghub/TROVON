static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_1 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static inline int F_5 ( const struct V_6 * V_7 ,
const struct V_10 * V_8 )
{
if ( V_8 -> V_1 != V_7 -> V_8 . V_1 && V_8 -> V_1 != V_11 )
return 0 ;
return V_8 -> V_9 == V_11 || V_8 -> V_9 == V_7 -> V_8 . V_9 ;
}
static int F_6 ( struct V_1 * V_12 , struct V_13 * V_14 )
{
unsigned int V_15 ;
struct V_6 * V_7 = F_2 ( V_12 ) ;
const struct V_10 * V_16 ;
V_16 = F_7 ( V_14 ) -> V_17 ;
for ( V_15 = 0 ; V_16 [ V_15 ] . V_1 ; V_15 ++ )
if ( F_5 ( V_7 , & V_16 [ V_15 ] ) )
return 1 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_12 , struct V_18 * V_19 )
{
struct V_6 * V_7 = F_2 ( V_12 ) ;
return F_9 ( V_19 , L_3 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_7 ( V_7 -> V_7 . V_23 ) ;
V_20 = V_22 -> V_24 ( V_7 ) ;
if ( ! V_20 )
if ( V_22 -> V_25 )
V_22 -> V_25 ( V_7 ) ;
return V_20 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_7 ( V_7 -> V_7 . V_23 ) ;
V_22 -> remove ( V_7 ) ;
return 0 ;
}
int F_12 ( struct V_21 * V_23 )
{
V_23 -> V_23 . V_26 = & V_27 ;
return F_13 ( & V_23 -> V_23 ) ;
}
void F_14 ( struct V_21 * V_23 )
{
F_15 ( & V_23 -> V_23 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_28 = F_2 ( V_2 ) ;
F_17 ( V_28 ) ;
}
struct V_6 *
F_18 ( struct V_1 * V_29 , int V_8 , struct V_30 * V_31 ,
struct V_32 * V_33 , void T_2 * V_34 )
{
int V_35 ;
struct V_6 * V_28 ;
V_28 = F_19 ( sizeof( * V_28 ) , V_36 ) ;
if ( ! V_28 )
return F_20 ( - V_37 ) ;
V_28 -> V_34 = V_34 ;
V_28 -> V_7 . V_38 = V_29 ;
V_28 -> V_8 . V_1 = V_8 ;
V_28 -> V_8 . V_9 = V_11 ;
V_28 -> V_7 . V_39 . V_31 = V_31 ;
V_28 -> V_7 . V_40 = & V_28 -> V_7 . V_41 ;
F_21 ( & V_28 -> V_7 , F_22 ( 64 ) ) ;
V_28 -> V_7 . V_42 = F_16 ;
V_28 -> V_33 = V_33 ;
V_28 -> V_7 . V_26 = & V_27 ;
V_35 = F_23 ( & V_43 , 0 , 0 , V_36 ) ;
if ( V_35 < 0 )
goto V_44;
V_28 -> V_45 = V_35 ;
F_24 ( & V_28 -> V_7 , L_4 , V_28 -> V_45 ) ;
V_35 = F_25 ( & V_28 -> V_7 ) ;
if ( V_35 )
goto V_46;
return V_28 ;
V_46:
F_26 ( & V_43 , V_28 -> V_45 ) ;
V_44:
F_17 ( V_28 ) ;
return F_20 ( V_35 ) ;
}
void F_27 ( struct V_6 * V_28 )
{
int V_45 = V_28 -> V_45 ;
F_28 ( & V_28 -> V_7 ) ;
F_26 ( & V_43 , V_45 ) ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_27 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_27 ) ;
F_33 ( & V_43 ) ;
}
