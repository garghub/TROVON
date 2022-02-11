static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 = V_2 -> V_7 + 0x100 ;
#ifdef F_3
V_5 -> V_8 = 1 ;
V_5 -> V_9 = 1 ;
#endif
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_5 -> V_10 = 0 ;
F_5 ( V_5 , 0x1010 , & V_5 -> V_7 -> V_11 [ 1 ] ) ;
return V_3 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_3 ;
if ( F_7 () )
return - V_16 ;
if ( V_13 -> V_14 [ 1 ] . V_17 != V_18 ) {
F_8 ( L_1 ) ;
return - V_19 ;
}
V_2 = F_9 ( & V_20 , & V_13 -> V_21 , L_2 ) ;
if ( ! V_2 )
return - V_19 ;
V_15 = F_10 ( V_13 , V_22 , 0 ) ;
V_2 -> V_23 = V_15 -> V_24 ;
V_2 -> V_25 = F_11 ( V_15 ) ;
V_2 -> V_7 = F_12 ( & V_13 -> V_21 , V_15 ) ;
if ( F_13 ( V_2 -> V_7 ) ) {
V_3 = F_14 ( V_2 -> V_7 ) ;
goto V_26;
}
V_2 -> V_27 = 1 ;
V_3 = F_15 ( V_2 , V_13 -> V_14 [ 1 ] . V_24 ,
V_28 ) ;
if ( V_3 == 0 ) {
F_16 ( V_13 , V_2 ) ;
return V_3 ;
}
V_26:
F_17 ( V_2 ) ;
return V_3 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_19 ( V_13 ) ;
F_20 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_21 )
{
struct V_1 * V_2 = F_22 ( V_21 ) ;
bool V_30 = F_23 ( V_21 ) ;
return F_24 ( V_2 , V_30 ) ;
}
static int F_25 ( struct V_29 * V_21 )
{
struct V_1 * V_2 = F_22 ( V_21 ) ;
F_26 ( V_2 , false ) ;
return 0 ;
}
