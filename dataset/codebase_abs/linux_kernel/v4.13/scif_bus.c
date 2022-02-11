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
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_7 ( V_7 -> V_7 . V_22 ) ;
return V_21 -> V_23 ( V_7 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_7 ( V_7 -> V_7 . V_22 ) ;
V_21 -> remove ( V_7 ) ;
return 0 ;
}
int F_12 ( struct V_20 * V_22 )
{
V_22 -> V_22 . V_24 = & V_25 ;
return F_13 ( & V_22 -> V_22 ) ;
}
void F_14 ( struct V_20 * V_22 )
{
F_15 ( & V_22 -> V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_26 = F_2 ( V_2 ) ;
F_17 ( V_26 ) ;
}
struct V_6 *
F_18 ( struct V_1 * V_27 , int V_8 , const struct V_28 * V_29 ,
struct V_30 * V_31 , T_2 V_32 , T_2 V_33 ,
struct V_34 * V_35 , struct V_34 * V_36 , void * V_37 ,
void T_3 * V_38 , struct V_39 * * V_40 , int V_41 ,
bool V_42 )
{
int V_43 ;
struct V_6 * V_26 ;
V_26 = F_19 ( sizeof( * V_26 ) , V_44 ) ;
if ( ! V_26 )
return F_20 ( - V_45 ) ;
V_26 -> V_7 . V_46 = V_27 ;
V_26 -> V_8 . V_1 = V_8 ;
V_26 -> V_8 . V_9 = V_11 ;
V_26 -> V_7 . V_29 = V_29 ;
V_26 -> V_7 . V_47 = F_16 ;
V_26 -> V_31 = V_31 ;
V_26 -> V_32 = V_32 ;
V_26 -> V_33 = V_33 ;
F_21 ( & V_26 -> V_7 , V_26 ) ;
V_26 -> V_7 . V_24 = & V_25 ;
V_26 -> V_35 = V_35 ;
V_26 -> V_36 = V_36 ;
V_26 -> V_37 = V_37 ;
V_26 -> V_38 = V_38 ;
V_26 -> V_7 . V_48 = & V_26 -> V_7 . V_49 ;
F_22 ( & V_26 -> V_7 , F_23 ( 64 ) ) ;
V_26 -> V_50 = V_40 ;
V_26 -> V_51 = V_41 ;
V_26 -> V_42 = V_42 ;
F_24 ( & V_26 -> V_7 , L_4 , V_26 -> V_32 ) ;
V_43 = F_25 ( & V_26 -> V_7 ) ;
if ( V_43 )
goto V_52;
return V_26 ;
V_52:
F_26 ( & V_26 -> V_7 ) ;
return F_20 ( V_43 ) ;
}
void F_27 ( struct V_6 * V_26 )
{
F_28 ( & V_26 -> V_7 ) ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_25 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_25 ) ;
}
