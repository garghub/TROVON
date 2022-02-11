static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x00000003 , V_3 | 0x0004770c ) ;
F_2 ( 0x00000003 , V_3 | 0x00047710 ) ;
F_3 ( 100 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_3 ( 10 ) ;
}
int F_5 ( const struct V_4 * V_5 ,
struct V_1 * V_2 )
{
int V_6 ;
struct V_7 * V_8 ;
if ( V_2 -> V_9 [ 0 ] . V_10 != V_11 ||
V_2 -> V_9 [ 1 ] . V_10 != V_12 ) {
F_6 ( & V_2 -> V_2 , L_1 ) ;
return - V_13 ;
}
V_8 = F_7 ( V_5 , & V_2 -> V_2 , L_2 ) ;
if ( ! V_8 )
return - V_13 ;
V_8 -> V_14 = V_2 -> V_9 [ 0 ] . V_15 ;
V_8 -> V_16 = V_2 -> V_9 [ 0 ] . V_17 - V_2 -> V_9 [ 0 ] . V_15 + 1 ;
if ( ! F_8 ( V_8 -> V_14 , V_8 -> V_16 , V_18 ) ) {
F_6 ( & V_2 -> V_2 , L_3
L_4 , V_8 -> V_14 , V_8 -> V_16 ) ;
V_6 = - V_19 ;
goto V_20;
}
V_8 -> V_21 = F_9 ( V_8 -> V_14 , V_8 -> V_16 ) ;
if ( ! V_8 -> V_21 ) {
F_6 ( & V_2 -> V_2 , L_5 ,
V_8 -> V_14 , V_8 -> V_16 ) ;
V_6 = - V_13 ;
goto V_22;
}
F_1 ( V_2 ) ;
F_10 ( F_11 ( V_8 ) ) ;
V_6 = F_12 ( V_8 , V_2 -> V_9 [ 1 ] . V_15 , 0 ) ;
if ( V_6 == 0 )
return V_6 ;
F_4 ( V_2 ) ;
F_13 ( V_8 -> V_21 ) ;
V_22:
F_14 ( V_8 -> V_14 , V_8 -> V_16 ) ;
V_20:
F_15 ( V_8 ) ;
return V_6 ;
}
void F_16 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_17 ( V_8 ) ;
F_4 ( V_2 ) ;
F_13 ( V_8 -> V_21 ) ;
F_14 ( V_8 -> V_14 , V_8 -> V_16 ) ;
F_15 ( V_8 ) ;
}
static int T_1
F_18 ( struct V_7 * V_8 )
{
struct V_23 * V_24 = F_11 ( V_8 ) ;
int V_25 ;
F_19 ( V_24 , L_6 , V_24 ) ;
if ( ( V_25 = F_20 ( V_24 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_21 ( V_24 ) ) < 0 ) {
F_22 ( L_7 , V_8 -> V_26 . V_27 ) ;
F_23 ( V_8 ) ;
return V_25 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_28 )
{
int V_25 ;
if ( F_25 () )
return - V_29 ;
V_25 = F_5 ( & V_30 , V_28 ) ;
return V_25 ;
}
static int F_26 ( struct V_1 * V_28 )
{
struct V_7 * V_8 = F_27 ( V_28 ) ;
F_16 ( V_8 , V_28 ) ;
return 0 ;
}
