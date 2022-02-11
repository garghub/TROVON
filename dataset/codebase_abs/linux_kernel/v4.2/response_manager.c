int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_6 ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
F_2 ( & V_2 -> V_8 [ V_3 ] . V_9 ) ;
F_3 ( & V_2 -> V_8 [ V_3 ] . V_10 ) ;
F_4 ( & V_2 -> V_8 [ V_3 ] . V_11 , 0 ) ;
}
V_2 -> V_12 . V_13 = F_5 ( L_1 ) ;
if ( ! V_2 -> V_12 . V_13 ) {
F_6 ( & V_2 -> V_14 -> V_15 , L_2 ) ;
return - V_16 ;
}
V_6 = & V_2 -> V_12 ;
F_7 ( & V_6 -> V_17 . V_18 , V_19 ) ;
V_6 -> V_17 . V_20 = V_2 ;
F_8 ( V_6 -> V_13 , & V_6 -> V_17 . V_18 , F_9 ( 100 ) ) ;
return V_4 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_12 . V_17 . V_18 ) ;
F_12 ( V_2 -> V_12 . V_13 ) ;
F_13 ( V_2 -> V_12 . V_13 ) ;
}
int F_14 ( struct V_1 * V_21 ,
T_1 V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
int V_28 = V_29 ;
T_1 V_30 ;
T_2 V_31 ;
struct V_32 * V_33 ;
V_24 = & V_21 -> V_8 [ V_34 ] ;
do {
F_15 ( & V_24 -> V_10 ) ;
if ( V_24 -> V_9 . V_35 == & V_24 -> V_9 ) {
F_16
( & V_24 -> V_10 ) ;
return 1 ;
}
V_26 = (struct V_25 * ) V_24 ->
V_9 . V_35 ;
V_33 = (struct V_32 * ) & V_26 -> V_36 . V_33 ;
V_30 = V_37 ;
F_17 ( & V_21 -> V_14 -> V_15 ,
V_26 -> V_36 . V_38 , V_33 -> V_39 ,
V_40 ) ;
V_31 = * V_26 -> V_41 ;
if ( V_31 != V_42 ) {
if ( ( V_31 & 0xff ) != 0xff ) {
F_18 ( & V_31 , 1 ) ;
if ( ( ( V_31 & 0xff ) != 0xff ) ) {
V_30 = ( T_1 ) ( V_31 &
0xffffffffULL ) ;
}
}
} else if ( V_22 || ( V_26 -> V_43 &&
F_19 ( V_44 , ( unsigned long ) V_26 -> V_43 ) ) ) {
V_30 = V_45 ;
}
if ( V_30 != V_37 ) {
F_20 ( & V_26 -> V_46 ) ;
F_21 ( & V_21 -> V_8
[ V_34 ] .
V_11 ) ;
F_16
( & V_24 -> V_10 ) ;
if ( V_26 -> V_47 )
V_26 -> V_47 ( V_21 , V_30 ,
V_26 -> V_48 ) ;
V_27 ++ ;
} else {
V_27 = 0 ;
F_16
( & V_24 -> V_10 ) ;
}
if ( V_27 >= V_28 )
break;
} while ( V_27 );
return 0 ;
}
static void V_19 ( struct V_49 * V_18 )
{
struct V_50 * V_17 = (struct V_50 * ) V_18 ;
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_20 ;
struct V_5 * V_6 = & V_2 -> V_12 ;
F_14 ( V_2 , 0 ) ;
F_8 ( V_6 -> V_13 , & V_6 -> V_17 . V_18 , F_9 ( 100 ) ) ;
}
