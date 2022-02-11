static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 = V_5 -> V_9 ;
int V_10 , V_11 ;
T_1 V_12 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_13 = F_2 ( F_3 ( V_9 -> V_14 ,
V_9 -> V_15 ) ) ;
V_7 . V_3 = F_2 ( V_3 ) ;
V_7 . V_16 = F_2 ( F_3 ( V_9 -> V_14 ,
V_9 -> V_15 ) ) ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ )
V_7 . V_18 [ V_10 ] = F_2 ( V_19 ) ;
for ( V_10 = 0 ; V_10 < V_5 -> V_20 ; V_10 ++ )
V_7 . V_18 [ V_10 ] = F_2 ( F_3 ( V_5 -> V_21 [ V_10 ] ,
V_5 -> V_22 [ V_10 ] ) ) ;
V_12 = 0 ;
V_11 = F_4 ( V_2 , V_23 ,
sizeof( V_7 ) , & V_7 , & V_12 ) ;
if ( V_11 ) {
F_5 ( V_2 , L_1 ,
V_3 , V_11 ) ;
return V_11 ;
}
if ( V_12 ) {
F_5 ( V_2 , L_2 , V_12 ) ;
V_11 = - V_24 ;
}
return V_11 ;
}
static void F_6 ( void * V_25 , T_2 * V_26 ,
struct V_27 * V_28 )
{
struct V_4 * V_5 = V_25 ;
struct V_29 * V_30 = F_7 ( V_28 ) ;
if ( V_28 == V_5 -> V_31 )
return;
if ( V_30 -> V_32 != V_5 -> V_9 )
return;
if ( F_8 ( V_5 -> V_20 >= V_17 ) )
return;
V_5 -> V_21 [ V_5 -> V_20 ] = V_30 -> V_14 ;
V_5 -> V_22 [ V_5 -> V_20 ] = V_30 -> V_15 ;
V_5 -> V_20 ++ ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_8 * V_9 ,
bool V_33 )
{
struct V_29 * V_30 = F_7 ( V_28 ) ;
struct V_4 V_5 = {
. V_31 = V_28 ,
. V_9 = V_9 ,
} ;
T_1 V_3 = V_34 ;
F_10 ( & V_2 -> V_35 ) ;
F_11 ( V_2 -> V_36 ,
V_37 ,
F_6 ,
& V_5 ) ;
if ( V_5 . V_20 == 0 ) {
if ( V_33 )
V_3 = V_38 ;
else
V_3 = V_39 ;
}
if ( V_33 ) {
if ( F_8 ( V_5 . V_20 >= V_17 ) )
return - V_40 ;
V_5 . V_21 [ V_5 . V_20 ] = V_30 -> V_14 ;
V_5 . V_22 [ V_5 . V_20 ] = V_30 -> V_15 ;
V_5 . V_20 ++ ;
}
return F_1 ( V_2 , V_3 , & V_5 ) ;
}
int F_12 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_29 * V_30 = F_7 ( V_28 ) ;
if ( F_8 ( ! V_30 -> V_32 ) )
return - V_40 ;
if ( F_13 ( V_2 , V_28 , false ) )
return - V_40 ;
return F_9 ( V_2 , V_28 , V_30 -> V_32 , true ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_29 * V_30 = F_7 ( V_28 ) ;
int V_11 ;
if ( F_8 ( ! V_30 -> V_32 ) )
return - V_40 ;
V_11 = F_9 ( V_2 , V_28 , V_30 -> V_32 , false ) ;
if ( ! V_11 )
if ( F_13 ( V_2 , V_28 , true ) )
F_5 ( V_2 , L_3 ) ;
return V_11 ;
}
