static bool F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 )
return false ;
if ( ( V_2 -> V_5 & V_6 ) == V_7 )
return false ;
if ( ! V_2 -> V_8 )
return false ;
return true ;
}
T_1 F_2 ( const struct V_9 * V_10 )
{
const struct V_1 * V_11 ;
const struct V_1 * V_2 ;
const struct V_12 * V_13 ;
T_2 V_14 = ( T_2 ) V_15 ;
T_2 V_16 = 0 ;
int V_17 ;
V_13 = (struct V_12 * ) V_10 -> V_18 ;
V_11 = (struct V_1 * ) ( V_13 + 1 ) ;
for ( V_17 = 0 ; V_17 < V_13 -> V_19 ; V_17 ++ ) {
V_2 = & V_11 [ V_17 ] ;
if ( ! F_1 ( V_2 ) )
continue;
if ( V_2 -> V_20 < V_14 )
V_14 = V_2 -> V_20 ;
if ( V_2 -> V_20 + V_2 -> V_8 > V_16 )
V_16 = F_3 ( V_2 -> V_20 + V_2 -> V_8 , V_21 ) ;
}
return V_14 < V_16 ? V_16 - V_14 : - V_22 ;
}
int F_4 ( struct V_23 * V_24 , const struct V_9 * V_10 ,
const char * V_9 , int V_25 , void * V_26 ,
T_2 V_27 , T_3 V_28 )
{
const struct V_1 * V_11 ;
const struct V_1 * V_2 ;
const struct V_12 * V_13 ;
const struct V_9 * V_29 ;
T_2 V_30 ;
T_2 V_14 = ( T_2 ) V_15 ;
T_2 V_16 = 0 ;
T_3 V_31 ;
T_1 V_32 ;
char * V_33 ;
bool V_34 = false ;
void * V_35 ;
int V_36 ;
int V_17 ;
if ( ! V_10 || ! V_26 || ! V_27 || ! V_28 )
return - V_22 ;
V_13 = (struct V_12 * ) V_10 -> V_18 ;
V_11 = (struct V_1 * ) ( V_13 + 1 ) ;
V_31 = strlen ( V_9 ) ;
if ( V_31 <= 4 )
return - V_22 ;
V_33 = F_5 ( V_9 , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
V_36 = F_6 ( V_25 , V_10 -> V_18 , V_10 -> V_39 ) ;
if ( V_36 ) {
F_7 ( V_24 , L_1 ) ;
goto V_40;
}
for ( V_17 = 0 ; V_17 < V_13 -> V_19 ; V_17 ++ ) {
V_2 = & V_11 [ V_17 ] ;
if ( ! F_1 ( V_2 ) )
continue;
if ( V_2 -> V_5 & V_41 )
V_34 = true ;
if ( V_2 -> V_20 < V_14 )
V_14 = V_2 -> V_20 ;
if ( V_2 -> V_20 + V_2 -> V_8 > V_16 )
V_16 = F_3 ( V_2 -> V_20 + V_2 -> V_8 , V_21 ) ;
}
if ( V_34 ) {
V_36 = F_8 ( V_25 , V_27 , V_16 - V_14 ) ;
if ( V_36 ) {
F_7 ( V_24 , L_2 ) ;
goto V_40;
}
V_30 = V_14 ;
} else {
V_30 = V_27 ;
}
for ( V_17 = 0 ; V_17 < V_13 -> V_19 ; V_17 ++ ) {
V_2 = & V_11 [ V_17 ] ;
if ( ! F_1 ( V_2 ) )
continue;
V_32 = V_2 -> V_20 - V_30 ;
if ( V_32 < 0 || V_32 + V_2 -> V_8 > V_28 ) {
F_7 ( V_24 , L_3 ) ;
V_36 = - V_22 ;
break;
}
V_35 = V_26 + V_32 ;
if ( V_2 -> V_42 ) {
sprintf ( V_33 + V_31 - 3 , L_4 , V_17 ) ;
V_36 = F_9 ( & V_29 , V_33 , V_24 ,
V_35 , V_2 -> V_42 ) ;
if ( V_36 ) {
F_7 ( V_24 , L_5 , V_33 ) ;
break;
}
F_10 ( V_29 ) ;
}
if ( V_2 -> V_8 > V_2 -> V_42 )
memset ( V_35 + V_2 -> V_42 , 0 , V_2 -> V_8 - V_2 -> V_42 ) ;
}
V_40:
F_11 ( V_33 ) ;
return V_36 ;
}
