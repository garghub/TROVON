static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = V_5 . V_11 ;
if ( V_9 )
return F_2 ( V_2 , V_9 ) ;
if ( V_2 -> V_12 )
return - V_13 ;
F_3 ( V_2 , V_2 -> V_14 . V_15 ,
V_2 -> V_14 . V_16 ) ;
V_2 -> V_17 = F_4 ( V_11 , V_2 -> V_17 * 1000 ) / 1000 ;
V_2 -> V_18 = F_4 ( V_11 , V_2 -> V_18 * 1000 ) / 1000 ;
F_3 ( V_2 , V_2 -> V_14 . V_15 ,
V_2 -> V_14 . V_16 ) ;
return 0 ;
}
static unsigned int F_5 ( unsigned int V_12 )
{
if ( V_12 )
return 0 ;
return F_6 ( V_5 . V_11 ) / 1000 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_19 , unsigned int V_20 )
{
int V_21 = 0 ;
unsigned int V_22 ;
struct V_23 V_24 ;
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_10 * V_11 = V_5 . V_11 ;
V_24 . V_25 = F_5 ( 0 ) ;
V_24 . V_26 = F_4 ( V_11 , V_19 * 1000 ) / 1000 ;
if ( V_24 . V_25 == V_24 . V_26 )
return V_21 ;
F_8 ( V_5 . V_6 , L_1 , V_24 . V_25 , V_24 . V_26 ) ;
V_21 = F_9 ( V_2 , V_4 -> V_9 ,
V_24 . V_26 , V_20 , & V_22 ) ;
if ( V_21 )
return - V_13 ;
F_10 ( V_2 , & V_24 , V_27 ) ;
if ( V_4 -> V_28 && V_24 . V_26 > V_24 . V_25 ) {
V_21 = V_4 -> V_28 ( V_22 ) ;
if ( V_21 )
goto V_29;
}
V_21 = F_11 ( V_11 , V_22 ) ;
if ( V_21 )
goto V_29;
if ( V_5 . V_30 ) {
V_21 = F_11 ( V_5 . V_30 , V_5 . V_31 ) ;
if ( V_21 )
goto V_29;
}
if ( V_4 -> V_28 && V_24 . V_26 < V_24 . V_25 )
V_4 -> V_28 ( V_22 ) ;
V_29:
if ( V_21 )
V_24 . V_26 = V_24 . V_25 ;
F_10 ( V_2 , & V_24 , V_32 ) ;
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
struct V_3 * V_4 = V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_2 -> V_12 != 0 )
return - V_13 ;
if ( V_4 -> V_34 ) {
V_33 = V_4 -> V_34 () ;
if ( V_33 )
return V_33 ;
}
V_2 -> V_35 = F_5 ( 0 ) ;
V_33 = F_13 ( V_2 , V_9 ) ;
if ( V_33 ) {
F_14 ( L_2 ,
V_36 ) ;
return V_33 ;
}
F_15 ( V_9 , V_2 -> V_12 ) ;
V_2 -> V_14 . V_37 = 2000 * 1000 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_12 ) ;
return 0 ;
}
static int T_1 F_18 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = V_39 -> V_6 . V_7 ;
struct V_10 * V_30 ;
if ( ! V_4 )
return - V_13 ;
if ( ! V_4 -> V_9 )
return - V_13 ;
V_5 . V_6 = & V_39 -> V_6 ;
V_5 . V_11 = F_19 ( NULL , L_3 ) ;
if ( F_20 ( V_5 . V_11 ) ) {
F_21 ( V_5 . V_6 , L_4 ) ;
return F_22 ( V_5 . V_11 ) ;
}
V_30 = F_19 ( V_5 . V_6 , L_5 ) ;
if ( ! F_20 ( V_30 ) ) {
V_5 . V_30 = V_30 ;
V_5 . V_31 = F_6 ( V_30 ) ;
}
return F_23 ( & V_40 ) ;
}
static int T_2 F_24 ( struct V_38 * V_39 )
{
F_25 ( V_5 . V_11 ) ;
if ( V_5 . V_30 )
F_25 ( V_5 . V_30 ) ;
return F_26 ( & V_40 ) ;
}
int T_1 F_27 ( void )
{
return F_28 ( & V_41 ,
F_18 ) ;
}
