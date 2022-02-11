static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 ;
struct V_10 V_11 = {
. V_12 = V_7 -> V_13 ,
. V_14 = V_7 -> V_13 ,
. V_15 = 4 ,
} ;
F_3 ( & V_7 -> V_16 ) ;
V_7 -> V_13 [ 0 ] = V_17 | V_3 ;
V_7 -> V_13 [ 1 ] = V_7 -> V_13 [ 2 ] = V_7 -> V_13 [ 3 ] = 0 ;
F_4 ( & V_9 ) ;
F_5 ( & V_11 , & V_9 ) ;
V_5 = F_6 ( V_7 -> V_18 , & V_9 ) ;
V_5 = F_7 ( V_7 -> V_18 , V_7 -> V_13 , 4 ) ;
if ( V_5 == 0 )
* V_4 = ( V_7 -> V_13 [ 1 ] << 16 ) | ( V_7 -> V_13 [ 2 ] << 8 ) | V_7 -> V_13 [ 3 ] ;
F_8 ( & V_7 -> V_16 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_19 const * V_20 ,
int * V_4 , int * V_21 ,
long V_22 )
{
int V_5 ;
T_2 V_23 ;
F_3 ( & V_2 -> V_24 ) ;
V_5 = F_1 ( V_2 , V_20 -> V_25 , & V_23 ) ;
F_8 ( & V_2 -> V_24 ) ;
if ( V_5 )
return V_5 ;
* V_4 = V_23 ;
return V_26 ;
}
static int T_3 F_10 ( struct V_27 * V_28 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_11 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_29 ;
goto V_30;
}
V_7 = F_2 ( V_2 ) ;
F_12 ( V_28 , V_2 ) ;
V_7 -> V_18 = V_28 ;
F_13 ( & V_7 -> V_16 ) ;
V_2 -> V_31 = V_28 -> V_32 . V_33 -> V_31 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = F_14 ( V_35 ) ;
V_2 -> V_32 . V_37 = & V_28 -> V_32 ;
V_2 -> V_38 = & V_39 ;
V_2 -> V_40 = V_41 ;
V_5 = F_15 ( V_2 ) ;
if ( V_5 )
goto V_42;
return 0 ;
V_42:
F_16 ( V_2 ) ;
V_30:
return V_5 ;
}
static int T_4 F_17 ( struct V_27 * V_28 )
{
F_18 ( F_19 ( V_28 ) ) ;
F_16 ( F_19 ( V_28 ) ) ;
return 0 ;
}
