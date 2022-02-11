static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) -> V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , int V_11 , T_1 * V_12 , bool V_13 )
{
int V_14 ;
struct V_15 V_16 [] = {
{
. V_17 = V_8 -> V_17 ,
. V_18 = 8 ,
. V_11 = 1 ,
} ,
{
. V_19 = V_8 -> V_19 ,
. V_18 = 8 ,
. V_11 = V_11 ,
}
} ;
F_5 ( & V_8 -> V_20 ) ;
if ( ( V_13 ) && ( V_11 > 1 ) )
V_8 -> V_17 [ 0 ] = V_10 | V_21 ;
else
V_8 -> V_17 [ 0 ] = V_10 | V_22 ;
V_14 = F_6 ( F_3 ( V_5 ) , V_16 , F_7 ( V_16 ) ) ;
if ( V_14 )
goto V_23;
memcpy ( V_12 , V_8 -> V_19 , V_11 * sizeof( T_1 ) ) ;
F_8 ( & V_8 -> V_20 ) ;
return V_11 ;
V_23:
F_8 ( & V_8 -> V_20 ) ;
return V_14 ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , T_1 * V_24 )
{
return F_4 ( V_8 , V_5 , V_10 , 1 , V_24 , false ) ;
}
static int F_10 (
struct V_7 * V_8 , struct V_9 * V_5 ,
T_1 V_10 , int V_11 , T_1 * V_12 , bool V_13 )
{
return F_4 ( V_8 , V_5 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_9 * V_5 , T_1 V_10 , T_1 V_12 )
{
int V_14 ;
struct V_15 V_16 = {
. V_17 = V_8 -> V_17 ,
. V_18 = 8 ,
. V_11 = 2 ,
} ;
F_5 ( & V_8 -> V_20 ) ;
V_8 -> V_17 [ 0 ] = V_10 ;
V_8 -> V_17 [ 1 ] = V_12 ;
V_14 = F_6 ( F_3 ( V_5 ) , & V_16 , 1 ) ;
F_8 ( & V_8 -> V_20 ) ;
return V_14 ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 , struct V_3 * V_4 )
{
F_13 ( V_26 , V_2 ) ;
V_2 -> V_5 . V_27 = & V_26 -> V_5 ;
V_2 -> V_28 = V_26 -> V_29 ;
V_4 -> V_5 = & V_26 -> V_5 ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_32 = F_1 ;
}
