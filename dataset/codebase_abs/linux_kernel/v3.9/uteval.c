T_1
F_1 ( struct V_1 * V_2 ,
char * V_3 ,
T_2 V_4 ,
union V_5 * * V_6 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
T_2 V_10 ;
F_2 ( V_11 ) ;
V_8 = F_3 ( sizeof( struct V_7 ) ) ;
if ( ! V_8 ) {
F_4 ( V_12 ) ;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_13 = V_3 ;
V_9 = F_5 ( V_8 ) ;
if ( F_6 ( V_9 ) ) {
if ( V_9 == V_14 ) {
F_7 ( ( V_15 ,
L_1 ,
F_8 ( V_2 ) ,
V_3 ) ) ;
} else {
F_9 ( L_2 ,
V_2 , V_3 , V_9 ) ;
}
goto V_16;
}
if ( ! V_8 -> V_17 ) {
if ( V_4 ) {
F_9 ( L_3 ,
V_2 , V_3 , V_18 ) ;
V_9 = V_18 ;
}
goto V_16;
}
switch ( ( V_8 -> V_17 ) -> V_19 . type ) {
case V_20 :
V_10 = V_21 ;
break;
case V_22 :
V_10 = V_23 ;
break;
case V_24 :
V_10 = V_25 ;
break;
case V_26 :
V_10 = V_27 ;
break;
default:
V_10 = 0 ;
break;
}
if ( ( V_28 ) && ( ! V_4 ) ) {
F_10 ( V_8 -> V_17 ) ;
goto V_16;
}
if ( ! ( V_4 & V_10 ) ) {
F_9 ( L_4 ,
V_2 , V_3 , V_29 ) ;
F_11 ( ( V_30 ,
L_5 ,
V_3 ,
F_12 ( V_8 -> V_17 ) ,
V_4 ) ) ;
F_10 ( V_8 -> V_17 ) ;
V_9 = V_29 ;
goto V_16;
}
* V_6 = V_8 -> V_17 ;
V_16:
F_13 ( V_8 ) ;
F_4 ( V_9 ) ;
}
T_1
F_14 ( char * V_31 ,
struct V_1 * V_32 ,
T_3 * V_33 )
{
union V_5 * V_34 ;
T_1 V_9 ;
F_2 ( V_35 ) ;
V_9 = F_1 ( V_32 , V_31 ,
V_21 , & V_34 ) ;
if ( F_6 ( V_9 ) ) {
F_4 ( V_9 ) ;
}
* V_33 = V_34 -> integer . V_33 ;
F_10 ( V_34 ) ;
F_4 ( V_9 ) ;
}
T_1
F_15 ( struct V_1 * V_32 , T_2 * V_36 )
{
union V_5 * V_34 ;
T_1 V_9 ;
F_2 ( V_37 ) ;
V_9 = F_1 ( V_32 , V_38 ,
V_21 , & V_34 ) ;
if ( F_6 ( V_9 ) ) {
if ( V_14 == V_9 ) {
F_7 ( ( V_15 ,
L_6 ,
F_8 ( V_32 ) ) ) ;
* V_36 = V_39 ;
V_9 = V_40 ;
}
F_4 ( V_9 ) ;
}
* V_36 = ( T_2 ) V_34 -> integer . V_33 ;
F_10 ( V_34 ) ;
F_4 ( V_9 ) ;
}
T_1
F_16 ( struct V_1 * V_32 ,
const char * * V_41 ,
T_4 V_42 , T_4 * V_43 )
{
union V_5 * V_34 ;
T_1 V_9 ;
T_1 V_44 = V_14 ;
T_2 V_45 ;
F_2 ( V_46 ) ;
for ( V_45 = 0 ; V_45 < V_42 ; V_45 ++ ) {
V_9 = F_1 ( V_32 ,
F_17 ( char ,
V_41 [ V_45 ] ) ,
V_21 , & V_34 ) ;
if ( F_18 ( V_9 ) ) {
V_43 [ V_45 ] = ( T_4 ) V_34 -> integer . V_33 ;
F_10 ( V_34 ) ;
V_44 = V_40 ;
continue;
}
V_43 [ V_45 ] = V_47 ;
if ( V_9 == V_14 ) {
continue;
}
F_7 ( ( V_15 ,
L_7 ,
F_17 ( char , V_41 [ V_45 ] ) ,
F_8 ( V_32 ) ,
F_19 ( V_9 ) ) ) ;
}
F_4 ( V_44 ) ;
}
