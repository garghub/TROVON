static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 , V_8 ;
T_1 * V_9 ;
if ( V_3 >= V_10 )
return;
F_3 ( & V_5 -> V_11 ) ;
V_9 = & V_5 -> V_5 [ V_3 << V_12 ] ;
if ( ! ( V_5 -> V_13 & ( 1 << V_3 ) ) ||
F_4 ( V_14 , V_5 -> V_15 [ V_3 ] ) ) {
F_5 ( & V_2 -> V_16 , L_1 , V_3 ) ;
V_5 -> V_13 &= ~ ( 1 << V_3 ) ;
V_8 = V_17 + ( V_3 << V_12 ) ;
if ( F_6 ( V_2 , V_8 >> 8 , V_8 & 0xFF ) ) {
F_7 ( & V_2 -> V_16 , L_2 ) ;
goto V_18;
}
if ( F_8 ( V_2 -> V_19 ,
V_20 ) ) {
if ( F_9 ( V_2 ,
V_21 ,
V_22 ,
V_9 ) != V_22 ) {
goto V_18;
}
} else {
for ( V_6 = 0 ; V_6 < V_22 ; V_6 ++ ) {
V_7 = F_10 ( V_2 ) ;
if ( V_7 < 0 ) {
goto V_18;
}
V_9 [ V_6 ] = V_7 ;
}
}
V_5 -> V_15 [ V_3 ] = V_14 ;
V_5 -> V_13 |= ( 1 << V_3 ) ;
}
V_18:
F_11 ( & V_5 -> V_11 ) ;
}
static T_2 F_12 ( struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_9 , T_3 V_29 , T_4 V_30 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 , V_31 ;
V_31 = ( V_29 + V_30 - 1 ) >> V_12 ;
for ( V_3 = ( V_29 >> V_12 ) ; V_3 <= V_31 ; V_3 ++ )
F_1 ( V_2 , V_3 ) ;
memcpy ( V_9 , & V_5 -> V_5 [ V_29 ] , V_30 ) ;
return V_30 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_32 * V_33 )
{
struct V_34 * V_19 = V_2 -> V_19 ;
struct V_4 * V_5 ;
int V_35 ;
if ( ! F_8 ( V_19 , V_36
| V_37 ) )
return - V_38 ;
if ( V_2 -> V_8 & 1 )
return - V_38 ;
if ( ! ( V_5 = F_15 ( sizeof( struct V_4 ) , V_39 ) ) )
return - V_40 ;
V_5 -> V_41 = F_16 ( V_2 -> V_19 , V_2 -> V_8 + 1 ) ;
if ( ! V_5 -> V_41 ) {
V_35 = - V_40 ;
goto V_42;
}
F_17 ( V_2 , V_5 ) ;
F_18 ( & V_5 -> V_11 ) ;
V_35 = F_19 ( & V_2 -> V_16 . V_26 , & V_43 ) ;
if ( V_35 )
goto V_44;
return 0 ;
V_44:
F_20 ( V_5 -> V_41 ) ;
V_42:
F_21 ( V_5 ) ;
return V_35 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_20 ( V_5 -> V_41 ) ;
F_23 ( & V_2 -> V_16 . V_26 , & V_43 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
