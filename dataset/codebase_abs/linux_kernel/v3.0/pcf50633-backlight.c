int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_8 = V_3 & 0x3f ;
F_3 ( V_5 -> V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_9 )
{
struct V_4 * V_5 = F_5 ( V_9 ) ;
unsigned int V_11 ;
if ( V_9 -> V_12 . V_13 & ( V_14 | V_15 ) ||
V_9 -> V_12 . V_16 != V_17 )
V_11 = 0 ;
else if ( V_9 -> V_12 . V_18 < V_5 -> V_8 )
V_11 = V_9 -> V_12 . V_18 ;
else
V_11 = V_5 -> V_8 ;
if ( V_5 -> V_18 == V_11 )
return 0 ;
if ( V_11 ) {
F_6 ( V_5 -> V_2 , V_19 ,
V_11 ) ;
if ( ! V_5 -> V_18 )
F_6 ( V_5 -> V_2 , V_20 , 1 ) ;
} else {
F_6 ( V_5 -> V_2 , V_20 , 0 ) ;
}
V_5 -> V_18 = V_11 ;
return 0 ;
}
static int F_7 ( struct V_10 * V_9 )
{
struct V_4 * V_5 = F_5 ( V_9 ) ;
return V_5 -> V_18 ;
}
static int T_1 F_8 ( struct V_21 * V_22 )
{
int V_23 ;
struct V_4 * V_5 ;
struct V_24 * V_25 = V_22 -> V_26 . V_25 ;
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_33 V_34 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_34 . type = V_37 ;
V_34 . V_38 = 0x3f ;
V_34 . V_16 = V_17 ;
if ( V_31 ) {
V_34 . V_18 = V_31 -> V_39 ;
V_5 -> V_8 = V_31 -> V_40 ;
} else {
V_34 . V_18 = 0x3f ;
V_5 -> V_8 = 0x3f ;
}
V_5 -> V_2 = F_10 ( V_22 -> V_26 . V_25 ) ;
V_5 -> V_9 = F_11 ( V_22 -> V_41 , & V_22 -> V_26 , V_5 ,
& V_42 , & V_34 ) ;
if ( F_12 ( V_5 -> V_9 ) ) {
V_23 = F_13 ( V_5 -> V_9 ) ;
goto V_43;
}
F_14 ( V_22 , V_5 ) ;
F_6 ( V_5 -> V_2 , V_44 , V_31 -> V_45 ) ;
V_5 -> V_18 = V_5 -> V_9 -> V_12 . V_18 + 1 ;
F_3 ( V_5 -> V_9 ) ;
return 0 ;
V_43:
F_15 ( V_5 ) ;
return V_23 ;
}
static int T_2 F_16 ( struct V_21 * V_22 )
{
struct V_4 * V_5 = F_2 ( V_22 ) ;
F_17 ( V_5 -> V_9 ) ;
F_14 ( V_22 , NULL ) ;
F_15 ( V_5 ) ;
return 0 ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_46 ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_46 ) ;
}
