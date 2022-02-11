T_1
F_1 ( T_2 V_1 , void * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_7 = V_8 ;
T_3 V_9 ;
F_2 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_6 = V_12 ;
while ( V_6 ) {
V_4 = V_6 -> V_13 ;
while ( V_4 ) {
V_7 =
V_1 ( V_6 , V_4 ,
V_2 ) ;
if ( F_4 ( V_7 ) ) {
if ( V_7 == V_14 ) {
V_7 = V_8 ;
}
goto V_15;
}
V_4 = V_4 -> V_16 ;
}
V_6 = V_6 -> V_16 ;
}
V_15:
F_5 ( V_11 , V_9 ) ;
F_6 ( V_7 ) ;
}
T_4 F_7 ( struct V_17 * V_18 )
{
struct V_5 * V_19 ;
struct V_3 * V_4 ;
F_8 () ;
V_19 = V_12 ;
while ( V_19 ) {
V_4 = V_19 -> V_13 ;
while ( V_4 ) {
if ( ( & V_4 -> V_20 [ 0 ] <= V_18 ) &&
( & V_4 -> V_20 [ V_4 -> V_21 ] >
V_18 ) ) {
return ( TRUE ) ;
}
V_4 = V_4 -> V_16 ;
}
V_19 = V_19 -> V_16 ;
}
return ( FALSE ) ;
}
T_1
F_9 ( struct V_5 * V_6 ,
struct V_3 * V_4 , void * V_2 )
{
struct V_22 * V_23 = V_2 ;
V_23 -> V_24 += V_4 -> V_21 ;
if ( V_23 -> V_25 < V_23 -> V_24 ) {
if ( ( V_4 -> V_26 ) -> type == V_27 ) {
V_23 -> V_28 = V_4 -> V_26 ;
}
V_23 -> V_7 = V_8 ;
return ( V_14 ) ;
}
return ( V_8 ) ;
}
struct V_5 * F_10 ( T_5 V_29 )
{
struct V_5 * V_30 ;
struct V_5 * V_31 ;
T_1 V_7 ;
T_3 V_9 ;
F_2 ( V_32 ) ;
V_30 = V_12 ;
while ( V_30 ) {
if ( V_30 -> V_29 == V_29 ) {
F_11 ( V_30 ) ;
}
V_30 = V_30 -> V_16 ;
}
V_31 = F_12 ( sizeof( struct V_5 ) ) ;
if ( ! V_31 ) {
F_11 ( NULL ) ;
}
V_31 -> V_29 = V_29 ;
V_9 = F_3 ( V_11 ) ;
if ( V_12 ) {
V_30 = V_12 ;
while ( V_30 -> V_16 ) {
V_30 = V_30 -> V_16 ;
}
V_30 -> V_16 = V_31 ;
V_31 -> V_33 = V_30 ;
} else {
V_12 = V_31 ;
}
F_5 ( V_11 , V_9 ) ;
if ( V_29 != V_34 . V_35 ) {
V_7 = F_13 ( V_29 ,
V_36 ,
V_31 ) ;
if ( F_4 ( V_7 ) ) {
F_14 ( ( V_37 ,
L_1 ,
V_29 ) ) ;
F_11 ( NULL ) ;
}
}
F_11 ( V_31 ) ;
}
T_1 F_15 ( struct V_5 * V_31 )
{
T_1 V_7 ;
T_3 V_9 ;
F_2 ( V_38 ) ;
if ( V_31 -> V_29 == V_34 . V_35 ) {
V_31 -> V_13 = NULL ;
F_6 ( V_8 ) ;
}
V_7 =
F_16 ( V_31 -> V_29 ,
V_36 ) ;
if ( F_4 ( V_7 ) ) {
F_6 ( V_7 ) ;
}
V_9 = F_3 ( V_11 ) ;
if ( V_31 -> V_33 ) {
V_31 -> V_33 -> V_16 = V_31 -> V_16 ;
} else {
V_12 = V_31 -> V_16 ;
}
if ( V_31 -> V_16 ) {
V_31 -> V_16 -> V_33 = V_31 -> V_33 ;
}
F_5 ( V_11 , V_9 ) ;
F_17 ( V_31 ) ;
F_6 ( V_8 ) ;
}
T_1
F_18 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
void * V_2 )
{
struct V_17 * V_18 ;
struct V_39 * V_40 ;
struct V_39 * V_16 ;
T_5 V_41 ;
T_5 V_42 ;
F_2 ( V_43 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_44 ; V_41 ++ ) {
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ ) {
V_18 = & V_4 -> V_20 [ ( ( V_46 ) V_41 *
V_45 )
+ V_42 ] ;
if ( ( V_18 -> V_9 & V_47 ) ==
V_48 ) {
F_17 ( V_18 -> V_49 . V_50 ) ;
V_18 -> V_49 . V_50 = NULL ;
V_18 -> V_9 &=
~ V_47 ;
} else
if ( ( V_18 ->
V_9 & V_47 ) ==
V_51 ) {
V_40 = V_18 -> V_49 . V_52 ;
while ( V_40 ) {
V_16 = V_40 -> V_16 ;
F_17 ( V_40 ) ;
V_40 = V_16 ;
}
V_18 -> V_49 . V_52 = NULL ;
V_18 -> V_9 &=
~ V_47 ;
}
}
}
F_6 ( V_8 ) ;
}
