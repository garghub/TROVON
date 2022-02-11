T_1
F_1 ( T_2 V_1 ,
struct V_2 * V_3 ,
T_3 type ,
struct V_2 * * V_4 )
{
struct V_2 * V_5 ;
F_2 ( V_6 ) ;
#ifdef F_3
if ( V_7 & V_8 ) {
char * V_9 ;
V_9 = F_4 ( V_3 ) ;
if ( V_9 ) {
F_5 ( ( V_10 ,
L_1 ,
V_9 , V_3 ,
F_6 ( char , & V_1 ) ,
F_7 ( type ) ) ) ;
F_8 ( V_9 ) ;
}
}
#endif
V_5 = V_3 -> V_11 ;
while ( V_5 ) {
if ( V_5 -> V_12 . integer == V_1 ) {
if ( F_9 ( V_5 ) ==
V_13 ) {
V_5 =
F_6 ( struct V_2 ,
V_5 -> V_14 ) ;
}
F_5 ( ( V_10 ,
L_2 ,
F_6 ( char , & V_1 ) ,
F_7 ( V_5 -> type ) ,
V_5 ,
F_10 ( V_3 ) ,
V_3 ) ) ;
* V_4 = V_5 ;
F_11 ( V_15 ) ;
}
V_5 = V_5 -> V_16 ;
}
F_5 ( ( V_10 ,
L_3
L_4 ,
F_6 ( char , & V_1 ) ,
F_7 ( type ) ,
F_10 ( V_3 ) , V_3 ,
V_3 -> V_11 ) ) ;
F_11 ( V_17 ) ;
}
static T_1
F_12 ( T_2 V_1 ,
struct V_2 * V_5 ,
T_3 type ,
struct V_2 * * V_4 )
{
T_1 V_18 ;
struct V_2 * V_3 ;
F_2 ( V_19 ) ;
V_3 = V_5 -> V_20 ;
if ( ! V_3 ) {
F_5 ( ( V_10 , L_5 ,
F_6 ( char , & V_1 ) ) ) ;
F_11 ( V_17 ) ;
}
if ( F_13 ( type ) ) {
F_5 ( ( V_10 ,
L_6 ,
F_6 ( char , & V_1 ) ,
F_7 ( type ) ) ) ;
F_11 ( V_17 ) ;
}
F_5 ( ( V_10 ,
L_7 ,
F_10 ( V_3 ) ,
F_6 ( char , & V_1 ) ) ) ;
while ( V_3 ) {
V_18 =
F_1 ( V_1 , V_3 ,
V_21 , V_4 ) ;
if ( F_14 ( V_18 ) ) {
F_11 ( V_18 ) ;
}
V_3 = V_3 -> V_20 ;
}
F_11 ( V_17 ) ;
}
T_1
F_15 ( T_2 V_1 ,
struct V_22 * V_23 ,
struct V_2 * V_5 ,
T_4 V_24 ,
T_3 type ,
T_2 V_25 , struct V_2 * * V_4 )
{
T_1 V_18 ;
struct V_2 * V_26 ;
F_2 ( V_27 ) ;
if ( ! V_5 || ! V_1 || ! V_4 ) {
F_16 ( ( V_28 ,
L_8 ,
V_5 , V_1 , V_4 ) ) ;
F_11 ( V_29 ) ;
}
F_17 ( F_6 ( char , & V_1 ) ) ;
* V_4 = V_30 ;
V_18 = F_1 ( V_1 , V_5 , type , V_4 ) ;
if ( V_18 != V_17 ) {
if ( V_18 == V_15 ) {
if ( V_25 & V_31 ) {
F_5 ( ( V_10 ,
L_9 ,
F_6 ( char ,
& V_1 ) ,
V_24 ,
( * V_4 ) -> type ,
V_23 -> V_32 ) ) ;
F_18 ( * V_4 ) ;
if ( V_33 ) {
F_19 ( ( * V_4 ) -> V_14 ) ;
( * V_4 ) -> V_14 = NULL ;
( * V_4 ) -> V_32 =
V_23 -> V_32 ;
} else {
F_20 ( * V_4 ) ;
* V_4 = V_30 ;
}
}
else if ( V_25 & V_34 ) {
V_18 = V_35 ;
}
}
#ifdef F_21
if ( * V_4 && ( * V_4 ) -> type == V_21 ) {
( * V_4 ) -> V_25 |= V_36 ;
}
#endif
F_11 ( V_18 ) ;
}
if ( ( V_24 != V_37 ) &&
( V_25 & V_38 ) ) {
V_18 =
F_12 ( V_1 , V_5 , type ,
V_4 ) ;
if ( F_14 ( V_18 ) ) {
F_11 ( V_18 ) ;
}
}
if ( V_24 == V_39 ) {
F_5 ( ( V_10 ,
L_10 ,
F_6 ( char , & V_1 ) , V_5 ) ) ;
F_11 ( V_17 ) ;
}
V_26 = F_22 ( V_1 ) ;
if ( ! V_26 ) {
F_11 ( V_40 ) ;
}
#ifdef F_21
if ( V_25 & V_41 ||
( V_23 && V_23 -> V_42 == V_43 ) ) {
V_26 -> V_25 |= V_36 ;
}
#endif
if ( V_25 & V_44 ) {
V_26 -> V_25 |= V_45 ;
}
F_23 ( V_23 , V_5 , V_26 , type ) ;
* V_4 = V_26 ;
F_11 ( V_15 ) ;
}
