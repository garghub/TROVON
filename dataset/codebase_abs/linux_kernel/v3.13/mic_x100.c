T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( & V_2 -> V_4 ,
V_5 +
V_6 + V_3 * 4 ) ;
}
void F_3 ( struct V_1 * V_2 , int V_7 )
{
struct V_8 * V_9 = & V_2 -> V_4 ;
if ( V_7 > V_10 )
return;
F_4 () ;
F_5 ( V_9 , V_11 ,
V_5 +
( V_12 + ( 4 * V_7 ) ) ) ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_7 ( int V_13 )
{
return V_14 + V_13 ;
}
static inline int F_8 ( int V_15 )
{
return V_16 + V_15 ;
}
void F_9 ( struct V_17 * V_18 )
{
V_18 -> V_19 . V_20 = V_21 +
V_22 ;
}
int F_10 ( struct V_17 * V_18 , int V_13 )
{
int V_23 ;
if ( V_13 < V_21 ) {
return F_7 ( V_13 ) ;
} else {
V_23 = V_13 - V_21 +
V_16 ;
return F_8 ( V_23 ) ;
}
}
void T_2 *
F_11 ( struct V_1 * V_2 , T_3 V_24 , T_4 V_25 )
{
return F_12 ( V_24 , V_25 ) ;
}
void F_13 ( struct V_1 * V_2 , void T_2 * V_24 )
{
F_14 ( V_24 ) ;
}
static int T_5 F_15 ( struct V_26 * V_27 )
{
struct V_17 * V_18 = & V_28 ;
struct V_1 * V_2 = & V_18 -> V_2 ;
int V_29 = 0 ;
V_18 -> V_30 = & V_27 -> V_30 ;
snprintf ( V_18 -> V_31 , sizeof( V_32 ) , V_32 ) ;
V_2 -> V_4 . V_33 = V_34 ;
V_2 -> V_4 . V_35 = V_36 ;
V_2 -> V_4 . V_37 = F_12 ( V_34 , V_36 ) ;
if ( ! V_2 -> V_4 . V_37 ) {
F_16 ( & V_27 -> V_30 , L_1 ) ;
V_29 = - V_38 ;
goto V_39;
}
F_9 ( V_18 ) ;
V_29 = F_17 ( V_18 ) ;
if ( V_29 ) {
F_16 ( & V_27 -> V_30 , L_2 , V_29 ) ;
goto F_14;
}
V_39:
return V_29 ;
F_14:
F_14 ( V_2 -> V_4 . V_37 ) ;
return V_29 ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_17 * V_18 = & V_28 ;
struct V_1 * V_2 = & V_18 -> V_2 ;
F_19 ( V_18 ) ;
F_14 ( V_2 -> V_4 . V_37 ) ;
return 0 ;
}
static void F_20 ( struct V_26 * V_27 )
{
F_18 ( V_27 ) ;
}
static int T_5 F_21 ( void )
{
int V_40 ;
struct V_41 * V_42 = & F_22 ( 0 ) ;
if ( ! ( V_42 -> V_43 == 11 && V_42 -> V_44 == 1 ) ) {
V_40 = - V_45 ;
F_23 ( L_3 , V_46 , V_40 ) ;
goto V_39;
}
F_24 () ;
V_40 = F_25 ( & V_47 ) ;
if ( V_40 ) {
F_23 ( L_4 , V_40 ) ;
goto V_48;
}
V_40 = F_26 ( & V_49 ) ;
if ( V_40 ) {
F_23 ( L_5 , V_40 ) ;
goto V_50;
}
return V_40 ;
V_50:
F_27 ( & V_47 ) ;
V_48:
F_28 () ;
V_39:
return V_40 ;
}
static void T_6 F_29 ( void )
{
F_30 ( & V_49 ) ;
F_27 ( & V_47 ) ;
F_28 () ;
}
