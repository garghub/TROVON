static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_8 ( V_7 ) ;
return F_5 ( V_2 , V_8 ) &
V_9 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_8 ( V_7 ) ;
T_2 V_10 = V_7 -> V_11 . V_10 ;
if ( V_7 -> V_11 . V_12 & V_13 )
return 0 ;
F_3 ( V_2 , V_8 , V_10 ) ;
F_3 ( V_2 , V_8 + 1 , V_10 >> 8 ) ;
F_3 ( V_2 , V_8 + 2 , V_10 >> 16 ) ;
F_3 ( V_2 , V_8 + 3 , 0 ) ;
return 0 ;
}
static int T_3 F_10 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_20 V_11 ;
struct V_6 * V_21 ;
T_1 V_22 , V_23 , V_24 ;
int V_25 = - V_26 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
F_12 ( V_15 , V_2 ) ;
V_19 = F_13 ( V_15 , V_29 , 0 ) ;
if ( ! V_19 ) {
F_14 ( L_1 ) ;
goto V_30;
}
V_2 -> V_4 = V_19 -> V_31 ;
V_2 -> V_32 = V_19 -> V_33 - V_19 -> V_31 ;
if ( V_2 -> V_32 < V_34 ) {
F_14 ( L_2 ,
V_2 -> V_32 , V_34 ) ;
goto V_30;
}
if ( ! F_15 ( V_2 -> V_4 , V_2 -> V_32 ,
L_3 ) ) {
F_14 ( L_4 ) ;
goto V_30;
}
V_22 = F_1 ( V_2 , V_35 ) ;
V_23 = F_1 ( V_2 , V_36 ) ;
V_24 = F_1 ( V_2 , V_37 ) ;
if ( V_22 == 0xff && V_23 == 0xff && V_24 == 0xff ) {
F_16 ( L_5 ) ;
V_25 = - V_38 ;
goto V_39;
}
F_16 ( L_6 , V_22 , V_23 ,
V_24 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . type = V_40 ;
V_11 . V_41 = F_5 ( V_2 , V_42 ) ;
if ( F_17 ( V_11 . V_41 > V_43 ) )
V_11 . V_41 = V_43 ;
V_21 = F_18 ( L_7 , & V_15 -> V_44 ,
V_2 , & V_45 , & V_11 ) ;
if ( F_19 ( V_21 ) ) {
V_25 = F_20 ( V_21 ) ;
goto V_39;
}
V_2 -> V_21 = V_21 ;
V_21 -> V_11 . V_10 = F_7 ( V_21 ) ;
F_21 ( V_21 ) ;
F_22 () ;
F_23 () ;
return 0 ;
V_39:
F_24 ( V_2 -> V_4 , V_2 -> V_32 ) ;
V_30:
F_25 ( V_2 ) ;
return V_25 ;
}
static void T_4 F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_27 ( V_15 ) ;
F_28 ( V_2 -> V_21 ) ;
F_24 ( V_2 -> V_4 , V_2 -> V_32 ) ;
F_25 ( V_2 ) ;
F_29 () ;
F_30 () ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_46 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_46 ) ;
}
