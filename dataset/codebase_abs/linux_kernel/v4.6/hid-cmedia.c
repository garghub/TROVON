static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
F_2 ( V_4 -> V_6 , V_7 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_1 * V_10 , int V_11 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( V_11 != V_12 )
goto V_13;
if ( memcmp ( V_10 + V_14 , V_15 , sizeof( V_15 ) ) )
goto V_13;
if ( ! memcmp ( V_10 , V_16 , sizeof( V_16 ) ) ) {
F_1 ( V_2 , V_4 , 0 ) ;
goto V_13;
}
if ( ! memcmp ( V_10 , V_17 , sizeof( V_17 ) ) ) {
F_1 ( V_2 , V_4 , 1 ) ;
goto V_13;
}
V_13:
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_6 * V_6 = V_19 -> V_20 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
int V_21 ;
V_4 -> V_6 = V_6 ;
memcpy ( V_4 -> V_22 , V_23 , sizeof( V_4 -> V_22 ) ) ;
V_6 -> V_24 [ 0 ] = F_7 ( V_25 ) ;
for ( V_21 = 0 ; V_21 < V_26 ; V_21 ++ )
F_8 ( V_4 -> V_6 ,
V_25 , V_23 [ V_21 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_18 * V_27 , struct V_28 * V_29 ,
struct V_30 * V_31 , unsigned long * * V_32 , int * V_33 )
{
return - 1 ;
}
static int F_10 ( struct V_1 * V_2 , const struct V_34 * V_35 )
{
int V_36 ;
struct V_3 * V_4 ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_37 ) ;
if ( ! V_4 ) {
V_36 = - V_38 ;
goto V_39;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_40 |= V_41 ;
F_12 ( V_2 , V_4 ) ;
V_36 = F_13 ( V_2 ) ;
if ( V_36 ) {
F_14 ( V_2 , L_1 ) ;
goto V_42;
}
V_36 = F_15 ( V_2 , V_43 | V_44 ) ;
if ( V_36 ) {
F_14 ( V_2 , L_2 ) ;
goto V_42;
}
return 0 ;
V_42:
F_16 ( V_4 ) ;
V_39:
return V_36 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_18 ( V_2 ) ;
F_16 ( V_4 ) ;
}
