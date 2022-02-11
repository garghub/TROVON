T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = sizeof( T_1 ) + 5 * sizeof( V_9 ) + sizeof( T_1 ) ;
T_1 * V_10 ;
V_10 = F_2 ( V_2 , sizeof( T_1 ) + V_8 ) ;
if ( ! V_10 )
return V_11 ;
* V_10 ++ = F_3 ( V_8 ) ;
* V_10 ++ = F_3 ( 1 ) ;
V_10 = F_4 ( V_10 , & V_6 -> V_12 ,
sizeof( struct V_13 ) ) ;
V_10 = F_5 ( V_10 , V_6 -> V_14 ) ;
V_10 = F_5 ( V_10 , V_6 -> V_8 ) ;
V_10 = F_5 ( V_10 , V_6 -> V_15 ) ;
* V_10 ++ = F_3 ( V_6 -> V_16 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_17 * V_6 )
{
T_1 * V_10 ;
int V_8 ;
switch ( V_6 -> type ) {
case V_18 :
V_8 = 4 + 4 + 8 + 4 + V_6 -> V_19 . V_20 ;
V_10 = F_2 ( V_2 , V_8 ) ;
if ( ! V_10 )
return - V_21 ;
* V_10 ++ = F_3 ( V_6 -> type ) ;
* V_10 ++ = F_3 ( 1 ) ;
V_10 = F_5 ( V_10 , V_6 -> V_19 . V_22 ) ;
V_10 = F_7 ( V_10 , V_6 -> V_19 . V_23 , V_6 -> V_19 . V_20 ) ;
break;
default:
return - V_24 ;
}
return V_8 ;
}
T_1
F_8 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
int V_8 = sizeof( T_1 ) , V_30 , V_31 ;
T_1 * V_10 ;
V_10 = F_2 ( V_2 , V_8 + sizeof( T_1 ) ) ;
if ( ! V_10 )
return V_32 ;
for ( V_31 = 0 ; V_31 < V_28 -> V_33 ; V_31 ++ ) {
V_30 = F_6 ( V_2 , & V_28 -> V_34 [ V_31 ] ) ;
if ( V_30 < 0 )
return F_9 ( V_30 ) ;
V_8 += V_30 ;
}
* V_10 ++ = F_3 ( V_8 ) ;
* V_10 ++ = F_3 ( V_28 -> V_33 ) ;
return 0 ;
}
int
F_10 ( T_1 * V_10 , T_2 V_8 , struct V_35 * * V_36 ,
T_2 V_37 )
{
struct V_35 * V_38 ;
T_2 V_39 , V_40 , V_31 ;
if ( V_8 < sizeof( T_2 ) ) {
F_11 ( L_1 , V_41 , V_8 ) ;
return - V_42 ;
}
V_39 = F_12 ( V_10 ++ ) ;
V_40 = sizeof( T_1 ) + V_39 * V_43 ;
if ( V_8 != V_40 ) {
F_11 ( L_2 ,
V_41 , V_8 , V_40 ) ;
return - V_42 ;
}
V_38 = F_13 ( V_39 , sizeof( * V_38 ) , V_44 ) ;
if ( ! V_38 ) {
F_11 ( L_3 , V_41 ) ;
return - V_45 ;
}
for ( V_31 = 0 ; V_31 < V_39 ; V_31 ++ ) {
struct V_5 V_46 ;
memcpy ( & V_46 . V_12 , V_10 , sizeof( struct V_13 ) ) ;
V_10 += F_14 ( sizeof( struct V_13 ) ) ;
V_10 = F_15 ( V_10 , & V_46 . V_14 ) ;
if ( V_46 . V_14 & ( V_37 - 1 ) ) {
F_11 ( L_4 ,
V_41 , V_46 . V_14 ) ;
goto V_47;
}
V_10 = F_15 ( V_10 , & V_46 . V_8 ) ;
if ( V_46 . V_8 & ( V_37 - 1 ) ) {
F_11 ( L_5 ,
V_41 , V_46 . V_14 ) ;
goto V_47;
}
V_10 = F_15 ( V_10 , & V_46 . V_15 ) ;
if ( V_46 . V_15 & ( V_37 - 1 ) ) {
F_11 ( L_6 ,
V_41 , V_46 . V_15 ) ;
goto V_47;
}
V_46 . V_16 = F_12 ( V_10 ++ ) ;
if ( V_46 . V_16 != V_48 ) {
F_11 ( L_7 ,
V_41 , V_46 . V_16 ) ;
goto V_47;
}
V_38 [ V_31 ] . V_22 = V_46 . V_14 ;
V_38 [ V_31 ] . V_49 = V_46 . V_8 ;
}
* V_36 = V_38 ;
return V_39 ;
V_47:
F_16 ( V_38 ) ;
return - V_42 ;
}
