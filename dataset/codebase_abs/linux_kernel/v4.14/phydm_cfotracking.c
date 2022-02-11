static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_6 =
(struct V_5 * ) F_2 ( V_4 , V_7 ) ;
if ( V_6 -> V_2 == V_2 )
return;
V_6 -> V_2 = V_2 ;
if ( V_4 -> V_8 & ( V_9 | V_10 ) ) {
V_2 = V_2 & 0x3F ;
F_3 ( V_4 , V_11 , 0x007ff800 ,
( V_2 | ( V_2 << 6 ) ) ) ;
} else if ( V_4 -> V_8 & V_12 ) {
V_2 = V_2 & 0x3F ;
F_3 ( V_4 , V_13 , 0x7FF80000 ,
( V_2 | ( V_2 << 6 ) ) ) ;
} else if ( ( V_4 -> V_8 & ( V_14 | V_15 |
V_16 | V_17 ) ) ) {
V_2 = V_2 & 0x3F ;
F_3 ( V_4 , V_13 , 0x00FFF000 ,
( V_2 | ( V_2 << 6 ) ) ) ;
} else if ( V_4 -> V_8 & V_18 ) {
V_2 = V_2 & 0x3F ;
F_3 ( V_4 , V_13 , 0x07FF8000 ,
( V_2 | ( V_2 << 6 ) ) ) ;
} else if ( V_4 -> V_8 & ( V_19 | V_20 ) ) {
V_2 = V_2 & 0x3F ;
F_3 ( V_4 , V_11 , 0x7e000000 , V_2 ) ;
F_3 ( V_4 , V_21 , 0x7e , V_2 ) ;
} else {
F_4 ( V_4 , V_22 ,
L_1 , V_23 ) ;
F_3 ( V_4 , V_13 , 0xFFF000 ,
( V_2 | ( V_2 << 6 ) ) ) ;
}
F_4 ( V_4 , V_22 , L_2 ,
V_23 , V_2 ) ;
}
static T_1 F_5 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_2 = 0x20 ;
struct V_24 * V_25 = (struct V_24 * ) V_4 -> V_26 ;
struct V_27 * V_28 = V_27 ( V_25 ) ;
V_2 = V_28 -> V_29 ;
V_2 = V_2 & 0x3f ;
return V_2 ;
}
static void F_6 ( void * V_1 , bool V_30 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_6 =
(struct V_5 * ) F_2 ( V_4 , V_7 ) ;
if ( V_6 -> V_31 == V_30 )
return;
F_3 ( V_4 , F_7 ( V_32 , V_4 ) , F_8 ( V_32 , V_4 ) ,
V_30 ) ;
V_6 -> V_31 = V_30 ;
}
static bool F_9 ( void * V_1 )
{
bool V_30 ;
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
V_30 = ( bool ) F_10 ( V_4 , F_7 ( V_32 , V_4 ) ,
F_8 ( V_32 , V_4 ) ) ;
return V_30 ;
}
void F_11 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_6 =
(struct V_5 * ) F_2 ( V_4 , V_7 ) ;
V_6 -> V_33 = F_5 ( V_4 ) ;
V_6 -> V_34 = true ;
if ( V_6 -> V_2 > V_6 -> V_33 ) {
F_1 ( V_4 , V_6 -> V_2 - 1 ) ;
F_4 ( V_4 , V_22 ,
L_3 , V_23 ,
V_6 -> V_2 ) ;
} else if ( V_6 -> V_2 < V_6 -> V_33 ) {
F_1 ( V_4 , V_6 -> V_2 + 1 ) ;
F_4 ( V_4 , V_22 ,
L_3 , V_23 ,
V_6 -> V_2 ) ;
}
F_6 ( V_4 , true ) ;
}
void F_12 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_6 =
(struct V_5 * ) F_2 ( V_4 , V_7 ) ;
V_6 -> V_2 = F_5 ( V_4 ) ;
V_6 -> V_33 = V_6 -> V_2 ;
V_6 -> V_31 = F_9 ( V_4 ) ;
V_6 -> V_34 = true ;
F_4 ( V_4 , V_22 , L_4 , V_23 ) ;
F_4 ( V_4 , V_22 ,
L_5 , V_23 ,
V_6 -> V_31 , V_6 -> V_33 ) ;
if ( V_4 -> V_8 & V_19 )
F_3 ( V_4 , 0x10 , 0x40 , 0x1 ) ;
}
void F_13 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_6 =
(struct V_5 * ) F_2 ( V_4 , V_7 ) ;
T_2 V_35 = 0 ;
T_3 V_36 , V_37 [ 4 ] = { 0 } ;
T_2 V_38 ;
T_4 V_2 = V_6 -> V_2 ;
T_1 V_39 = 1 , V_40 , V_41 = 0 ;
if ( ! ( V_4 -> V_42 & V_43 ) ) {
F_4 (
V_4 , V_22 ,
L_6 ,
V_23 ) ;
return;
}
F_4 ( V_4 , V_22 , L_4 , V_23 ) ;
if ( ! V_4 -> V_44 || ! V_4 -> V_45 ) {
F_11 ( V_4 ) ;
F_4 (
V_4 , V_22 ,
L_7 ,
V_23 , V_4 -> V_44 , V_4 -> V_45 ) ;
} else {
if ( V_6 -> V_46 == V_6 -> V_47 ) {
F_4 ( V_4 , V_22 ,
L_8 ,
V_23 ) ;
return;
}
V_6 -> V_47 = V_6 -> V_46 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_48 ; V_40 ++ ) {
if ( V_6 -> V_49 [ V_40 ] == 0 )
continue;
V_41 ++ ;
V_36 =
( T_3 ) ( ( V_6 -> V_50 [ V_40 ] < 0 ) ?
( 0 - V_6 -> V_50 [ V_40 ] ) :
V_6 -> V_50 [ V_40 ] ) ;
V_37 [ V_40 ] = F_14 ( V_36 ) /
V_6 -> V_49 [ V_40 ] ;
F_4 (
V_4 , V_22 ,
L_9 ,
V_40 , V_36 , V_6 -> V_49 [ V_40 ] ,
( ( V_6 -> V_50 [ V_40 ] < 0 ) ? L_10 : L_11 ) ,
V_37 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
if ( V_6 -> V_50 [ V_40 ] < 0 ) {
V_35 += ( 0 - ( T_2 ) V_37 [ V_40 ] ) ;
} else {
V_35 += ( T_2 ) V_37 [ V_40 ] ;
}
}
if ( V_41 >= 2 )
V_35 = V_35 / V_41 ;
F_4 ( V_4 , V_22 ,
L_12 ,
V_41 , V_35 ) ;
for ( V_40 = 0 ; V_40 < V_4 -> V_48 ; V_40 ++ ) {
V_6 -> V_50 [ V_40 ] = 0 ;
V_6 -> V_49 [ V_40 ] = 0 ;
}
V_38 = ( V_6 -> V_51 >= V_35 ) ?
( V_6 -> V_51 - V_35 ) :
( V_35 - V_6 -> V_51 ) ;
if ( V_38 > 20 && V_6 -> V_52 == 0 &&
! V_6 -> V_34 ) {
F_4 ( V_4 , V_22 ,
L_13 , V_23 ) ;
V_6 -> V_52 = 1 ;
return;
}
V_6 -> V_52 = 0 ;
V_6 -> V_51 = V_35 ;
if ( ! V_6 -> V_34 ) {
if ( V_35 > V_53 ||
V_35 < ( - V_53 ) )
V_6 -> V_34 = true ;
} else {
if ( V_35 < V_54 &&
V_35 > ( - V_54 ) )
V_6 -> V_34 = false ;
}
if ( V_4 -> V_55 ) {
V_6 -> V_34 = false ;
F_1 ( V_4 , V_6 -> V_33 ) ;
F_4 ( V_4 , V_22 ,
L_14 ,
V_23 ) ;
}
if ( V_6 -> V_34 ) {
if ( V_35 > V_54 )
V_2 = V_2 + V_39 ;
else if ( V_35 < ( - V_54 ) )
V_2 = V_2 - V_39 ;
if ( V_2 > 0x3f )
V_2 = 0x3f ;
else if ( V_2 < 0 )
V_2 = 0 ;
F_1 ( V_4 , ( T_1 ) V_2 ) ;
}
F_4 (
V_4 , V_22 ,
L_15 ,
V_23 , V_6 -> V_2 , V_6 -> V_33 ) ;
if ( V_4 -> V_8 & V_56 )
return;
if ( V_35 < V_57 && V_35 > - V_57 ) {
F_6 ( V_4 , false ) ;
F_4 ( V_4 , V_22 ,
L_16 , V_23 ) ;
} else {
F_6 ( V_4 , true ) ;
F_4 ( V_4 , V_22 ,
L_17 , V_23 ) ;
}
}
}
void F_15 ( void * V_1 , void * V_58 , T_4 * V_59 , T_1 V_60 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_61 * V_62 =
(struct V_61 * ) V_58 ;
struct V_5 * V_6 =
(struct V_5 * ) F_2 ( V_4 , V_7 ) ;
T_1 V_40 ;
if ( ! ( V_4 -> V_42 & V_43 ) )
return;
if ( V_62 -> V_63 ) {
if ( V_60 > V_4 -> V_48 )
V_60 = V_4 -> V_48 ;
for ( V_40 = 0 ; V_40 < V_60 ; V_40 ++ ) {
V_6 -> V_50 [ V_40 ] += V_59 [ V_40 ] ;
V_6 -> V_49 [ V_40 ] ++ ;
}
if ( V_6 -> V_46 == 0xffffffff )
V_6 -> V_46 = 0 ;
else
V_6 -> V_46 ++ ;
}
}
