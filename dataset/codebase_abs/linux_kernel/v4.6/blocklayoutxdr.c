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
case V_24 :
V_8 = 4 + 4 + 4 + 4 + V_6 -> V_25 . V_26 + 8 ;
V_10 = F_2 ( V_2 , V_8 ) ;
if ( ! V_10 )
return - V_21 ;
* V_10 ++ = F_3 ( V_6 -> type ) ;
* V_10 ++ = F_3 ( V_6 -> V_25 . V_27 ) ;
* V_10 ++ = F_3 ( V_6 -> V_25 . V_28 ) ;
V_10 = F_7 ( V_10 , V_6 -> V_25 . V_29 , V_6 -> V_25 . V_26 ) ;
V_10 = F_5 ( V_10 , V_6 -> V_25 . V_30 ) ;
break;
default:
return - V_31 ;
}
return V_8 ;
}
T_1
F_8 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_36 ;
int V_8 = sizeof( T_1 ) , V_37 , V_38 ;
T_1 * V_10 ;
V_10 = F_2 ( V_2 , V_8 + sizeof( T_1 ) ) ;
if ( ! V_10 )
return V_39 ;
for ( V_38 = 0 ; V_38 < V_35 -> V_40 ; V_38 ++ ) {
V_37 = F_6 ( V_2 , & V_35 -> V_41 [ V_38 ] ) ;
if ( V_37 < 0 )
return F_9 ( V_37 ) ;
V_8 += V_37 ;
}
* V_10 ++ = F_3 ( V_8 ) ;
* V_10 ++ = F_3 ( V_35 -> V_40 ) ;
return 0 ;
}
int
F_10 ( T_1 * V_10 , T_2 V_8 , struct V_42 * * V_43 ,
T_2 V_44 )
{
struct V_42 * V_45 ;
T_2 V_46 , V_38 ;
if ( V_8 < sizeof( T_2 ) ) {
F_11 ( L_1 , V_47 , V_8 ) ;
return - V_48 ;
}
V_8 -= sizeof( T_2 ) ;
if ( V_8 % V_49 ) {
F_11 ( L_2 , V_47 , V_8 ) ;
return - V_48 ;
}
V_46 = F_12 ( V_10 ++ ) ;
if ( V_46 != V_8 / V_49 ) {
F_11 ( L_3 ,
V_47 , V_8 , V_46 ) ;
return - V_48 ;
}
V_45 = F_13 ( V_46 , sizeof( * V_45 ) , V_50 ) ;
if ( ! V_45 ) {
F_11 ( L_4 , V_47 ) ;
return - V_51 ;
}
for ( V_38 = 0 ; V_38 < V_46 ; V_38 ++ ) {
struct V_5 V_52 ;
memcpy ( & V_52 . V_12 , V_10 , sizeof( struct V_13 ) ) ;
V_10 += F_14 ( sizeof( struct V_13 ) ) ;
V_10 = F_15 ( V_10 , & V_52 . V_14 ) ;
if ( V_52 . V_14 & ( V_44 - 1 ) ) {
F_11 ( L_5 ,
V_47 , V_52 . V_14 ) ;
goto V_53;
}
V_10 = F_15 ( V_10 , & V_52 . V_8 ) ;
if ( V_52 . V_8 & ( V_44 - 1 ) ) {
F_11 ( L_6 ,
V_47 , V_52 . V_14 ) ;
goto V_53;
}
V_10 = F_15 ( V_10 , & V_52 . V_15 ) ;
if ( V_52 . V_15 & ( V_44 - 1 ) ) {
F_11 ( L_7 ,
V_47 , V_52 . V_15 ) ;
goto V_53;
}
V_52 . V_16 = F_12 ( V_10 ++ ) ;
if ( V_52 . V_16 != V_54 ) {
F_11 ( L_8 ,
V_47 , V_52 . V_16 ) ;
goto V_53;
}
V_45 [ V_38 ] . V_22 = V_52 . V_14 ;
V_45 [ V_38 ] . V_55 = V_52 . V_8 ;
}
* V_43 = V_45 ;
return V_46 ;
V_53:
F_16 ( V_45 ) ;
return - V_48 ;
}
int
F_17 ( T_1 * V_10 , T_2 V_8 , struct V_42 * * V_43 ,
T_2 V_44 )
{
struct V_42 * V_45 ;
T_2 V_46 , V_56 , V_38 ;
if ( V_8 < sizeof( T_2 ) ) {
F_11 ( L_1 , V_47 , V_8 ) ;
return - V_48 ;
}
V_46 = F_12 ( V_10 ++ ) ;
V_56 = sizeof( T_1 ) + V_46 * V_57 ;
if ( V_8 != V_56 ) {
F_11 ( L_3 ,
V_47 , V_8 , V_56 ) ;
return - V_48 ;
}
V_45 = F_13 ( V_46 , sizeof( * V_45 ) , V_50 ) ;
if ( ! V_45 ) {
F_11 ( L_4 , V_47 ) ;
return - V_51 ;
}
for ( V_38 = 0 ; V_38 < V_46 ; V_38 ++ ) {
T_3 V_58 ;
V_10 = F_15 ( V_10 , & V_58 ) ;
if ( V_58 & ( V_44 - 1 ) ) {
F_11 ( L_5 , V_47 , V_58 ) ;
goto V_53;
}
V_45 [ V_38 ] . V_22 = V_58 ;
V_10 = F_15 ( V_10 , & V_58 ) ;
if ( V_58 & ( V_44 - 1 ) ) {
F_11 ( L_6 , V_47 , V_58 ) ;
goto V_53;
}
V_45 [ V_38 ] . V_55 = V_58 ;
}
* V_43 = V_45 ;
return V_46 ;
V_53:
F_16 ( V_45 ) ;
return - V_48 ;
}
