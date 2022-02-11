static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) -> V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , int V_11 , T_1 * V_12 , bool V_13 )
{
struct V_14 V_15 ;
int V_16 ;
struct V_17 V_18 [] = {
{
. V_19 = V_8 -> V_19 ,
. V_20 = 8 ,
. V_11 = 1 ,
} ,
{
. V_21 = V_8 -> V_21 ,
. V_20 = 8 ,
. V_11 = V_11 ,
}
} ;
F_5 ( & V_8 -> V_22 ) ;
if ( ( V_13 ) && ( V_11 > 1 ) )
V_8 -> V_19 [ 0 ] = V_10 | V_23 ;
else
V_8 -> V_19 [ 0 ] = V_10 | V_24 ;
F_6 ( & V_15 ) ;
F_7 ( & V_18 [ 0 ] , & V_15 ) ;
F_7 ( & V_18 [ 1 ] , & V_15 ) ;
V_16 = F_8 ( F_3 ( V_5 ) , & V_15 ) ;
if ( V_16 )
goto V_25;
memcpy ( V_12 , V_8 -> V_21 , V_11 * sizeof( T_1 ) ) ;
F_9 ( & V_8 -> V_22 ) ;
return V_11 ;
V_25:
F_9 ( & V_8 -> V_22 ) ;
return V_16 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , T_1 * V_26 )
{
return F_4 ( V_8 , V_5 , V_10 , 1 , V_26 , false ) ;
}
static int F_11 (
struct V_7 * V_8 , struct V_9 * V_5 ,
T_1 V_10 , int V_11 , T_1 * V_12 , bool V_13 )
{
return F_4 ( V_8 , V_5 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , T_1 V_12 )
{
struct V_14 V_15 ;
int V_16 ;
struct V_17 V_18 = {
. V_19 = V_8 -> V_19 ,
. V_20 = 8 ,
. V_11 = 2 ,
} ;
F_5 ( & V_8 -> V_22 ) ;
V_8 -> V_19 [ 0 ] = V_10 ;
V_8 -> V_19 [ 1 ] = V_12 ;
F_6 ( & V_15 ) ;
F_7 ( & V_18 , & V_15 ) ;
V_16 = F_8 ( F_3 ( V_5 ) , & V_15 ) ;
F_9 ( & V_8 -> V_22 ) ;
return V_16 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_27 * V_28 , struct V_3 * V_4 )
{
F_14 ( V_28 , V_2 ) ;
V_2 -> V_5 . V_29 = & V_28 -> V_5 ;
V_2 -> V_30 = V_28 -> V_31 ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_1 ;
}
