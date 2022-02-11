static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_5 )
{
struct V_6 V_7 [ 2 ] ;
T_1 V_8 [ V_9 ] = { 0 } ;
int V_10 ;
if ( V_3 > V_11 ) {
F_2 ( & V_2 -> V_12 , L_1 ,
V_13 ) ;
return - V_14 ;
}
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_7 [ 0 ] . V_15 = V_2 -> V_15 ;
V_7 [ 0 ] . V_16 = 0 ;
V_7 [ 0 ] . V_3 = V_17 ;
V_7 [ 0 ] . V_18 = ( V_19 * ) V_8 ;
V_8 [ 0 ] = F_3 ( V_4 ) ;
V_7 [ 1 ] . V_15 = V_2 -> V_15 ;
V_7 [ 1 ] . V_3 = V_3 ;
V_7 [ 1 ] . V_16 = V_20 ;
V_7 [ 1 ] . V_18 = ( V_19 * ) V_8 ;
V_10 = F_4 ( V_2 -> V_21 , V_7 , 2 ) ;
if ( V_10 != 2 ) {
if ( V_10 >= 0 )
V_10 = - V_22 ;
goto error;
}
memcpy ( V_5 , V_8 , V_3 ) ;
return 0 ;
error:
F_2 ( & V_2 -> V_12 , L_2 , V_4 , V_10 ) ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_23 , T_1 V_15 ,
V_19 * V_18 )
{
T_1 V_24 ;
int V_25 ;
for ( V_24 = 0 ; V_24 + V_26 <= V_23 ;
V_24 += V_26 ) {
V_25 = F_1 ( V_2 , V_26 ,
V_15 + V_24 , & V_18 [ V_24 ] ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
void * F_6 ( struct V_27 * V_28 , V_19 V_29 ,
T_2 V_30 , T_2 V_23 )
{
struct V_1 * V_2 = F_7 ( V_28 ) ;
V_19 * V_18 ;
int V_25 ;
int V_31 ;
V_18 = F_8 ( & V_2 -> V_12 , V_23 , V_32 ) ;
if ( ! V_18 )
return F_9 ( - V_33 ) ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
V_25 = F_10 ( V_2 , V_35 ,
V_36 , V_31 & 0xff ) ;
if ( V_25 )
goto V_37;
V_25 = F_10 ( V_2 , V_35 ,
V_38 , V_39 ) ;
if ( V_25 )
goto V_37;
V_25 = F_5 ( V_2 , V_40 ,
V_41 , V_18 + V_31 * V_40 ) ;
if ( V_25 )
goto V_37;
}
return V_18 ;
V_37:
F_2 ( & V_2 -> V_12 , L_3 ) ;
return F_9 ( V_25 ) ;
}
void * F_11 ( struct V_27 * V_28 , V_19 V_29 ,
T_2 V_30 , T_2 V_23 )
{
struct V_1 * V_2 = F_7 ( V_28 ) ;
V_19 * V_18 ;
int V_25 ;
int V_31 ;
V_18 = F_8 ( & V_2 -> V_12 , V_23 , V_32 ) ;
if ( ! V_18 )
return F_9 ( - V_33 ) ;
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
V_25 = F_10 ( V_2 , V_35 ,
V_42 , V_31 & 0xff ) ;
if ( V_25 )
goto V_37;
V_25 = F_10 ( V_2 , V_35 ,
V_43 , V_44 ) ;
if ( V_25 )
goto V_37;
V_25 = F_5 ( V_2 , V_40 ,
V_45 , V_18 + V_31 * V_40 ) ;
if ( V_25 )
goto V_37;
}
return V_18 ;
V_37:
F_2 ( & V_2 -> V_12 , L_3 ) ;
return F_9 ( V_25 ) ;
}
