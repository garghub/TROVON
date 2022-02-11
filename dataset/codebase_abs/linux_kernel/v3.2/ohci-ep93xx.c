static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
if ( V_7 -> V_11 [ 1 ] . V_12 != V_13 ) {
F_6 ( L_1 ) ;
return - V_14 ;
}
V_10 = F_7 ( V_5 , & V_7 -> V_2 , L_2 ) ;
if ( V_10 == NULL )
return - V_14 ;
V_10 -> V_15 = V_7 -> V_11 [ 0 ] . V_16 ;
V_10 -> V_17 = V_7 -> V_11 [ 0 ] . V_18 - V_7 -> V_11 [ 0 ] . V_16 + 1 ;
if ( ! F_8 ( V_10 -> V_15 , V_10 -> V_17 , V_19 ) ) {
F_9 ( V_10 ) ;
V_8 = - V_20 ;
goto V_21;
}
V_10 -> V_22 = F_10 ( V_10 -> V_15 , V_10 -> V_17 ) ;
if ( V_10 -> V_22 == NULL ) {
F_6 ( L_3 ) ;
V_8 = - V_14 ;
goto V_23;
}
V_3 = F_11 ( & V_7 -> V_2 , NULL ) ;
if ( F_12 ( V_3 ) ) {
F_6 ( L_4 ) ;
V_8 = F_13 ( V_3 ) ;
goto V_24;
}
F_1 ( & V_7 -> V_2 ) ;
F_14 ( F_15 ( V_10 ) ) ;
V_8 = F_16 ( V_10 , V_7 -> V_11 [ 1 ] . V_16 , 0 ) ;
if ( V_8 == 0 )
return V_8 ;
F_3 ( & V_7 -> V_2 ) ;
V_24:
F_17 ( V_10 -> V_22 ) ;
V_23:
F_18 ( V_10 -> V_15 , V_10 -> V_17 ) ;
V_21:
F_9 ( V_10 ) ;
return V_8 ;
}
static void F_19 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
F_20 ( V_10 ) ;
F_3 ( & V_7 -> V_2 ) ;
F_21 ( V_3 ) ;
F_17 ( V_10 -> V_22 ) ;
F_18 ( V_10 -> V_15 , V_10 -> V_17 ) ;
F_9 ( V_10 ) ;
}
static int T_1 F_22 ( struct V_9 * V_10 )
{
struct V_25 * V_26 = F_15 ( V_10 ) ;
int V_27 ;
if ( ( V_27 = F_23 ( V_26 ) ) < 0 )
return V_27 ;
if ( ( V_27 = F_24 ( V_26 ) ) < 0 ) {
F_25 ( L_5 , V_10 -> V_28 . V_29 ) ;
F_26 ( V_10 ) ;
return V_27 ;
}
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
int V_27 ;
V_27 = - V_30 ;
if ( ! F_28 () )
V_27 = F_5 ( & V_31 , V_7 ) ;
return V_27 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_30 ( V_7 ) ;
F_19 ( V_10 , V_7 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , T_2 V_32 )
{
struct V_9 * V_10 = F_30 ( V_7 ) ;
struct V_25 * V_26 = F_15 ( V_10 ) ;
if ( F_32 ( V_33 , V_26 -> V_34 ) )
F_33 ( 5 ) ;
V_26 -> V_34 = V_33 ;
F_3 ( & V_7 -> V_2 ) ;
V_10 -> V_32 = V_35 ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_30 ( V_7 ) ;
struct V_25 * V_26 = F_15 ( V_10 ) ;
if ( F_32 ( V_33 , V_26 -> V_34 ) )
F_33 ( 5 ) ;
V_26 -> V_34 = V_33 ;
F_1 ( & V_7 -> V_2 ) ;
F_35 ( V_10 ) ;
return 0 ;
}
