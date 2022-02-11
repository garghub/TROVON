int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_6 ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
F_2 ( & V_2 -> V_8 [ V_3 ] . V_9 ) ;
F_3 ( & V_2 -> V_8 [ V_3 ] . V_10 ) ;
F_4 ( & V_2 -> V_8 [ V_3 ] . V_11 , 0 ) ;
}
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_13 . V_14 = F_5 ( L_1 , V_15 , 0 ) ;
if ( ! V_2 -> V_13 . V_14 ) {
F_6 ( & V_2 -> V_16 -> V_17 , L_2 ) ;
return - V_18 ;
}
V_6 = & V_2 -> V_13 ;
F_7 ( & V_6 -> V_19 . V_20 , V_21 ) ;
V_6 -> V_19 . V_22 = V_2 ;
V_2 -> V_23 = V_24 ;
F_8 ( V_6 -> V_14 , & V_6 -> V_19 . V_20 , F_9 ( 50 ) ) ;
return V_4 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_13 . V_19 . V_20 ) ;
F_12 ( V_2 -> V_13 . V_14 ) ;
}
int F_13 ( struct V_1 * V_25 ,
T_1 V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 = 0 ;
int V_32 = V_33 ;
T_1 V_34 ;
T_2 V_35 ;
struct V_36 * V_37 ;
T_2 V_38 ;
V_28 = & V_25 -> V_8 [ V_39 ] ;
do {
F_14 ( & V_28 -> V_10 ) ;
if ( V_28 -> V_9 . V_40 == & V_28 -> V_9 ) {
F_15
( & V_28 -> V_10 ) ;
return 1 ;
}
V_30 = (struct V_29 * ) V_28 ->
V_9 . V_40 ;
V_37 = (struct V_36 * ) & V_30 -> V_41 . V_42 . V_37 ;
V_38 = V_30 -> V_41 . V_42 . V_38 ;
V_34 = V_43 ;
F_16 ( & V_25 -> V_16 -> V_17 ,
V_38 , V_37 -> V_44 ,
V_45 ) ;
V_35 = * V_30 -> V_46 ;
if ( V_35 != V_47 ) {
if ( ( V_35 & 0xff ) != 0xff ) {
F_17 ( & V_35 , 1 ) ;
if ( ( ( V_35 & 0xff ) != 0xff ) ) {
V_34 = ( T_1 ) ( V_35 &
0xffffffffULL ) ;
}
}
} else if ( V_26 || ( V_30 -> V_48 &&
F_18 ( V_49 , ( unsigned long ) V_30 -> V_48 ) ) ) {
V_34 = V_50 ;
}
if ( V_34 != V_43 ) {
F_19 ( & V_30 -> V_51 ) ;
F_20 ( & V_25 -> V_8
[ V_39 ] .
V_11 ) ;
F_15
( & V_28 -> V_10 ) ;
if ( V_30 -> V_52 )
V_30 -> V_52 ( V_25 , V_34 ,
V_30 -> V_53 ) ;
V_31 ++ ;
} else {
V_31 = 0 ;
F_15
( & V_28 -> V_10 ) ;
}
if ( V_31 >= V_32 )
break;
} while ( V_31 );
return 0 ;
}
static void V_21 ( struct V_54 * V_20 )
{
struct V_55 * V_19 = (struct V_55 * ) V_20 ;
struct V_1 * V_2 = (struct V_1 * ) V_19 -> V_22 ;
struct V_5 * V_6 = & V_2 -> V_13 ;
F_13 ( V_2 , 0 ) ;
F_8 ( V_6 -> V_14 , & V_6 -> V_19 . V_20 , F_9 ( 50 ) ) ;
}
