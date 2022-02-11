static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> line ) ;
return 0 ;
}
static int T_1 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> line ) ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 , int V_7 )
{
unsigned int V_8 ;
F_7 ( V_6 , V_9 , V_7 & 0xff ) ;
V_8 = F_8 ( V_6 , V_9 ) ;
F_9 ( V_8 != ( V_7 & 0xff ) ) ;
F_7 ( V_6 , V_10 , V_7 >> 8 & 0xff ) ;
}
static void F_10 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_14 )
{
struct V_3 * V_4 = V_12 -> V_15 ;
if ( ! V_13 )
F_11 ( V_4 -> V_16 ) ;
else
F_12 ( V_4 -> V_16 ) ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_5 V_19 = {} ;
struct V_3 * V_4 ;
struct V_20 * V_21 , * V_22 ;
int V_23 ;
V_21 = F_14 ( V_18 , V_24 , 0 ) ;
V_22 = F_14 ( V_18 , V_25 , 0 ) ;
if ( ! V_21 || ! V_22 )
return - V_26 ;
V_4 = F_15 ( & V_18 -> V_2 , sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_4 -> V_16 = F_16 ( & V_18 -> V_2 , NULL ) ;
if ( F_17 ( V_4 -> V_16 ) )
return F_18 ( V_4 -> V_16 ) ;
V_23 = F_19 ( V_4 -> V_16 ) ;
if ( V_23 )
return V_23 ;
V_19 . V_12 . type = V_29 ;
V_19 . V_12 . V_30 = V_31 ;
V_19 . V_12 . V_32 = V_21 -> V_33 ;
V_19 . V_12 . V_34 = 2 ;
V_19 . V_12 . V_35 = V_22 -> V_33 ;
V_19 . V_12 . V_36 = 64 ;
V_19 . V_12 . V_37 = V_38 | V_39 ;
V_19 . V_12 . V_2 = & V_18 -> V_2 ;
V_19 . V_12 . V_40 = F_20 ( V_4 -> V_16 ) ;
V_19 . V_12 . V_41 = F_10 ;
V_19 . V_12 . V_15 = V_4 ;
V_19 . V_42 = F_6 ;
V_23 = F_21 ( & V_19 ) ;
if ( V_23 < 0 )
goto V_43;
V_4 -> line = V_23 ;
F_22 ( V_18 , V_4 ) ;
return 0 ;
V_43:
F_23 ( V_4 -> V_16 ) ;
return V_23 ;
}
static int F_24 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_25 ( V_18 ) ;
F_26 ( V_4 -> line ) ;
F_23 ( V_4 -> V_16 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_44 * V_1 ,
const char * V_45 )
{
struct V_11 * V_12 = & V_1 -> V_12 ;
if ( ! ( V_1 -> V_12 . V_46 || V_1 -> V_12 . V_47 ) )
return - V_26 ;
V_12 -> V_34 = 2 ;
return F_28 ( V_1 , NULL ) ;
}
