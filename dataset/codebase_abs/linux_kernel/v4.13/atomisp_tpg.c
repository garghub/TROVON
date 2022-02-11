static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_9 ;
if ( V_9 -> V_12 )
return - V_13 ;
V_11 -> V_14 = V_15 ;
if ( V_9 -> V_16 == V_17 ) {
V_7 -> V_18 = * V_11 ;
return 0 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_19 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_20 * V_14 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_21 * V_22 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_23 * V_24 )
{
return 0 ;
}
void F_11 ( struct V_25 * V_26 )
{
F_12 ( & V_26 -> V_2 . V_27 ) ;
F_13 ( & V_26 -> V_2 ) ;
}
int F_14 ( struct V_25 * V_26 ,
struct V_28 * V_29 )
{
int V_30 ;
V_30 = F_15 ( V_29 , & V_26 -> V_2 ) ;
if ( V_30 < 0 )
goto error;
return 0 ;
error:
F_11 ( V_26 ) ;
return V_30 ;
}
void F_16 ( struct V_31 * V_32 )
{
}
int F_17 ( struct V_31 * V_32 )
{
struct V_25 * V_26 = & V_32 -> V_26 ;
struct V_1 * V_2 = & V_26 -> V_2 ;
struct V_33 * V_34 = V_26 -> V_34 ;
struct V_35 * V_36 = & V_2 -> V_27 ;
int V_30 ;
V_26 -> V_32 = V_32 ;
F_18 ( V_2 , & V_37 ) ;
V_2 -> V_38 |= V_39 ;
strcpy ( V_2 -> V_40 , L_1 ) ;
F_19 ( V_2 , V_26 ) ;
V_34 [ 0 ] . V_38 = V_41 ;
V_36 -> V_42 = V_43 ;
V_30 = F_20 ( V_36 , 1 , V_34 ) ;
if ( V_30 < 0 )
goto V_44;
return 0 ;
V_44:
F_16 ( V_32 ) ;
return V_30 ;
}
