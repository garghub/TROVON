struct V_1 * * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_8 , * * V_9 ;
int V_10 , V_11 ;
V_5 = V_3 -> V_12 -> V_13 . V_14 -> V_15 ;
V_7 = V_5 -> V_16 ;
V_11 = V_3 -> V_17 >> V_18 ;
V_9 = F_2 ( V_11 , sizeof( struct V_1 * ) ) ;
if ( V_9 == NULL )
return F_3 ( - V_19 ) ;
V_4 |= F_4 ( V_7 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_8 = F_5 ( V_7 , V_10 , V_4 ) ;
if ( F_6 ( V_8 ) )
goto V_20;
V_9 [ V_10 ] = V_8 ;
F_7 ( ( V_4 & V_21 ) &&
( F_8 ( V_8 ) >= 0x00100000UL ) ) ;
}
return V_9 ;
V_20:
while ( V_10 -- ) {
F_9 ( V_9 [ V_10 ] ) ;
}
F_10 ( V_9 ) ;
return F_11 ( V_8 ) ;
}
void F_12 ( struct V_2 * V_3 , struct V_1 * * V_9 ,
bool V_22 , bool V_23 )
{
int V_10 , V_11 ;
V_11 = V_3 -> V_17 >> V_18 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_22 )
F_13 ( V_9 [ V_10 ] ) ;
if ( V_23 )
F_14 ( V_9 [ V_10 ] ) ;
F_9 ( V_9 [ V_10 ] ) ;
}
F_10 ( V_9 ) ;
}
int
F_15 ( struct V_2 * V_3 , T_2 V_17 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_33 = 0 ;
V_30 = & V_3 -> V_34 ;
V_30 -> V_32 = F_16 ( sizeof( struct V_29 ) , V_35 ) ;
if ( ! V_30 -> V_32 )
return - V_19 ;
V_32 = V_30 -> V_32 ;
V_32 -> type = V_36 ;
V_32 -> V_17 = V_17 ;
V_32 -> V_37 = V_3 ;
V_30 -> V_38 = F_17 ( & V_27 -> V_39 ,
V_17 / V_40 , 0 , 0 ) ;
if ( ! V_30 -> V_38 ) {
F_18 ( L_1 , V_3 -> V_41 ) ;
V_33 = - V_42 ;
goto V_43;
}
V_30 -> V_38 = F_19 ( V_30 -> V_38 ,
V_17 / V_40 , 0 ) ;
if ( ! V_30 -> V_38 ) {
V_33 = - V_19 ;
goto V_43;
}
V_30 -> V_44 . V_45 = V_30 -> V_38 -> V_46 ;
V_33 = F_20 ( & V_27 -> V_47 , & V_30 -> V_44 ) ;
if ( V_33 ) {
F_18 ( L_2 ) ;
goto V_48;
}
return 0 ;
V_48:
F_21 ( V_30 -> V_38 ) ;
V_43:
F_22 ( V_30 -> V_32 ) ;
V_30 -> V_32 = NULL ;
return V_33 ;
}
