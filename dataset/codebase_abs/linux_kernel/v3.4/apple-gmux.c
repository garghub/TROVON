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
F_3 ( V_2 , V_8 , V_10 ) ;
F_3 ( V_2 , V_8 + 1 , V_10 >> 8 ) ;
F_3 ( V_2 , V_8 + 2 , V_10 >> 16 ) ;
F_3 ( V_2 , V_8 + 3 , 0 ) ;
return 0 ;
}
static int T_3 F_10 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_18 V_11 ;
struct V_6 * V_19 ;
T_1 V_20 , V_21 , V_22 ;
int V_23 = - V_24 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
F_12 ( V_13 , V_2 ) ;
V_17 = F_13 ( V_13 , V_27 , 0 ) ;
if ( ! V_17 ) {
F_14 ( L_1 ) ;
goto V_28;
}
V_2 -> V_4 = V_17 -> V_29 ;
V_2 -> V_30 = V_17 -> V_31 - V_17 -> V_29 ;
if ( V_2 -> V_30 < V_32 ) {
F_14 ( L_2 ,
V_2 -> V_30 , V_32 ) ;
goto V_28;
}
if ( ! F_15 ( V_2 -> V_4 , V_2 -> V_30 ,
L_3 ) ) {
F_14 ( L_4 ) ;
goto V_28;
}
V_20 = F_1 ( V_2 , V_33 ) ;
V_21 = F_1 ( V_2 , V_34 ) ;
V_22 = F_1 ( V_2 , V_35 ) ;
if ( V_20 == 0xff && V_21 == 0xff && V_22 == 0xff ) {
F_16 ( L_5 ) ;
V_23 = - V_36 ;
goto V_37;
}
F_16 ( L_6 , V_20 , V_21 ,
V_22 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . type = V_38 ;
V_11 . V_39 = F_5 ( V_2 , V_40 ) ;
if ( F_17 ( V_11 . V_39 > V_41 ) )
V_11 . V_39 = V_41 ;
V_19 = F_18 ( L_7 , & V_13 -> V_42 ,
V_2 , & V_43 , & V_11 ) ;
if ( F_19 ( V_19 ) ) {
V_23 = F_20 ( V_19 ) ;
goto V_37;
}
V_2 -> V_19 = V_19 ;
V_19 -> V_11 . V_10 = F_7 ( V_19 ) ;
F_21 ( V_19 ) ;
F_22 () ;
F_23 () ;
return 0 ;
V_37:
F_24 ( V_2 -> V_4 , V_2 -> V_30 ) ;
V_28:
F_25 ( V_2 ) ;
return V_23 ;
}
static void T_4 F_26 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_27 ( V_13 ) ;
F_28 ( V_2 -> V_19 ) ;
F_24 ( V_2 -> V_4 , V_2 -> V_30 ) ;
F_25 ( V_2 ) ;
F_29 () ;
F_30 () ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_44 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_44 ) ;
}
