struct V_1 * * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_8 , * * V_9 ;
int V_10 , V_11 ;
V_5 = F_2 ( V_3 -> V_12 ) ;
V_7 = V_5 -> V_13 ;
V_11 = V_3 -> V_14 >> V_15 ;
V_9 = F_3 ( V_11 , sizeof( struct V_1 * ) ) ;
if ( V_9 == NULL )
return F_4 ( - V_16 ) ;
V_4 |= F_5 ( V_7 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_8 = F_6 ( V_7 , V_10 , V_4 ) ;
if ( F_7 ( V_8 ) )
goto V_17;
V_9 [ V_10 ] = V_8 ;
F_8 ( ( V_4 & V_18 ) &&
( F_9 ( V_8 ) >= 0x00100000UL ) ) ;
}
return V_9 ;
V_17:
while ( V_10 -- )
F_10 ( V_9 [ V_10 ] ) ;
F_11 ( V_9 ) ;
return F_12 ( V_8 ) ;
}
void F_13 ( struct V_2 * V_3 , struct V_1 * * V_9 ,
bool V_19 , bool V_20 )
{
int V_10 , V_11 ;
V_11 = V_3 -> V_14 >> V_15 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_19 )
F_14 ( V_9 [ V_10 ] ) ;
if ( V_20 )
F_15 ( V_9 [ V_10 ] ) ;
F_10 ( V_9 [ V_10 ] ) ;
}
F_11 ( V_9 ) ;
}
int
F_16 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 = 0 ;
V_27 = & V_3 -> V_31 ;
V_27 -> V_29 = F_17 ( sizeof( struct V_26 ) , V_32 ) ;
if ( ! V_27 -> V_29 )
return - V_16 ;
V_29 = V_27 -> V_29 ;
V_29 -> type = V_33 ;
V_29 -> V_14 = V_14 ;
V_29 -> V_34 = V_3 ;
V_27 -> V_35 = F_18 ( & V_24 -> V_36 ,
V_14 / V_37 , 0 , 0 ) ;
if ( ! V_27 -> V_35 ) {
F_19 ( L_1 , V_3 -> V_38 ) ;
V_30 = - V_39 ;
goto V_40;
}
V_27 -> V_35 = F_20 ( V_27 -> V_35 ,
V_14 / V_37 , 0 ) ;
if ( ! V_27 -> V_35 ) {
V_30 = - V_16 ;
goto V_40;
}
V_27 -> V_41 . V_42 = V_27 -> V_35 -> V_43 ;
V_30 = F_21 ( & V_24 -> V_44 , & V_27 -> V_41 ) ;
if ( V_30 ) {
F_19 ( L_2 ) ;
goto V_45;
}
return 0 ;
V_45:
F_22 ( V_27 -> V_35 ) ;
V_40:
F_23 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
return V_30 ;
}
