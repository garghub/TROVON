static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 = V_5 ;
T_1 V_6 ;
struct V_7 * V_8 ;
T_2 V_9 ;
T_1 V_10 ;
V_4 =
F_2 ( & V_11 . V_12 [ V_3 ] ,
& V_8 , & V_9 , & V_10 ) ;
if ( F_3 ( V_4 ) ) {
return ( FALSE ) ;
}
V_6 = ( T_1 ) ( ( V_2 -> V_13 != V_9 ||
memcmp ( V_2 -> V_14 , V_8 , V_9 ) ) ?
FALSE : TRUE ) ;
F_4 ( V_8 , V_9 , V_10 ) ;
return ( V_6 ) ;
}
void
F_5 ( T_2 V_3 ,
struct V_1 * V_15 ,
T_1 V_16 )
{
if ( V_3 >= V_11 . V_17 ) {
return;
}
if ( V_16 ) {
F_6 ( V_15 ) ;
}
F_7 ( & V_11 .
V_12 [ V_3 ] ,
V_15 -> V_18 ,
V_15 -> V_19 ,
V_15 -> V_14 ) ;
F_8 ( V_15 -> V_18 ,
V_15 -> V_14 ) ;
if ( V_3 == V_20 ) {
F_9 ( V_15 -> V_14 -> V_21 ) ;
}
}
T_3
F_10 ( T_4 V_18 ,
char * V_22 , T_2 V_3 )
{
struct V_1 V_15 ;
T_3 V_4 ;
F_11 ( V_23 ) ;
if ( ! V_18 ) {
F_12 ( ( V_24 ,
L_1 ,
V_22 ) ) ;
return ( V_25 ) ;
}
V_4 = F_13 ( & V_15 , V_18 ,
V_26 ) ;
if ( F_3 ( V_4 ) ) {
F_12 ( ( V_24 ,
L_2 ,
F_14 ( V_18 ) ) ) ;
F_15 ( V_4 ) ;
}
V_4 = F_16 ( & V_15 , V_22 ) ;
if ( F_3 ( V_4 ) ) {
goto V_27;
}
F_5 ( V_3 , & V_15 , TRUE ) ;
V_27:
F_17 ( & V_15 ) ;
F_15 ( V_4 ) ;
}
T_3
F_18 ( T_4 V_18 ,
T_1 V_19 ,
T_1 V_28 , T_1 V_16 , T_2 * V_3 )
{
T_2 V_29 ;
T_3 V_4 = V_5 ;
struct V_1 V_15 ;
F_11 ( V_30 ) ;
V_4 = F_13 ( & V_15 , V_18 , V_19 ) ;
if ( F_3 ( V_4 ) ) {
F_12 ( ( V_24 ,
L_2 ,
F_14 ( V_18 ) ) ) ;
F_15 ( V_4 ) ;
}
if ( ! V_28 &&
V_31 &&
F_19 ( & V_15 . V_22 , V_32 ) ) {
F_20 ( ( V_24 ,
L_3 ,
V_15 . V_22 . V_33 ,
F_14 ( V_18 ) ) ) ;
goto V_27;
}
V_4 = F_16 ( & V_15 , NULL ) ;
if ( F_3 ( V_4 ) ) {
goto V_27;
}
if ( V_28 ) {
if ( ( V_15 . V_22 . V_33 [ 0 ] != 0x00 ) &&
( ! F_19
( & V_15 . V_22 , V_32 ) )
&& ( strncmp ( V_15 . V_22 . V_33 , L_4 , 3 ) ) ) {
F_21 ( ( V_24 ,
L_5
L_6 ,
F_22 ( V_15 .
V_22 .
V_33 ) ?
V_15 . V_22 .
V_33 : L_7 ,
V_15 . V_22 . integer ) ) ;
V_4 = V_34 ;
goto V_27;
}
for ( V_29 = 0 ; V_29 < V_11 . V_17 ;
++ V_29 ) {
if ( ! F_1 ( & V_15 , V_29 ) ) {
continue;
}
if ( V_11 . V_12 [ V_29 ] .
V_19 & V_35 ) {
V_4 = V_36 ;
goto V_27;
} else {
F_23 ( & V_15 ) ;
* V_3 = V_29 ;
F_15 ( V_5 ) ;
}
}
}
V_4 = F_24 ( & V_29 , NULL ) ;
if ( F_3 ( V_4 ) ) {
goto V_27;
}
* V_3 = V_29 ;
F_5 ( V_29 , & V_15 , V_16 ) ;
V_27:
F_17 ( & V_15 ) ;
F_15 ( V_4 ) ;
}
void F_6 ( struct V_1 * V_37 )
{
T_3 V_4 ;
char * V_38 ;
struct V_1 V_15 ;
struct V_7 * V_8 ;
T_4 V_18 ;
T_2 V_13 ;
V_4 = F_25 ( V_37 -> V_14 , & V_8 ) ;
if ( F_26 ( V_4 ) && V_8 ) {
F_13 ( & V_15 ,
F_27 ( V_8 ) ,
V_39 ) ;
V_38 = L_8 ;
goto V_40;
}
V_4 = F_28 ( V_37 -> V_14 ,
& V_18 , & V_13 ) ;
if ( F_26 ( V_4 ) && V_18 && V_13 ) {
F_13 ( & V_15 , V_18 ,
V_26 ) ;
V_38 = L_9 ;
goto V_40;
}
return;
V_40:
V_4 = F_16 ( & V_15 , NULL ) ;
if ( F_3 ( V_4 ) ) {
return;
}
F_20 ( ( V_24 , L_10
L_11 ,
V_37 -> V_22 . V_33 ,
F_14 ( V_37 -> V_18 ) ,
V_38 , F_14 ( V_15 . V_18 ) ) ) ;
F_23 ( V_37 ) ;
F_7 ( V_37 , V_15 . V_18 ,
V_15 . V_19 ,
V_15 . V_14 ) ;
F_29 ( V_37 ) ;
F_17 ( & V_15 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_11 ( V_41 ) ;
if ( ! V_2 -> V_18 ) {
V_42 ;
}
F_30 ( V_2 ) ;
if ( ( V_2 -> V_19 & V_43 ) ==
V_44 ) {
F_31 ( F_32 ( V_2 -> V_18 ) ) ;
}
V_2 -> V_18 = F_27 ( NULL ) ;
V_42 ;
}
