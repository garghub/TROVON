static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) & V_5 ;
int V_6 = 0 ;
F_3 ( V_2 , L_1 , V_3 ) ;
switch ( V_3 ) {
case V_7 :
case V_8 :
break;
default:
F_4 ( V_2 , L_2
L_3 , V_3 ) ;
V_6 = - V_9 ;
break;
}
return V_6 ;
}
const T_2
* F_5 ( const struct V_1 * V_2 , T_3 V_10 )
{
F_6 ( V_10 >= V_2 -> V_11 -> V_12 -> V_13 ) ;
return & V_2 -> V_14 [ V_10 ] ;
}
T_4 F_7 ( const struct V_1 * V_2 , T_3 V_10 )
{
if ( ! V_2 -> V_14 )
return 0 ;
return ( T_4 ) V_2 -> V_14 [ V_10 ] | ( ( T_4 ) V_2 -> V_14 [ V_10 + 1 ] << 8 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
T_5 * V_15 ;
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
int V_16 ;
int V_6 ;
T_4 V_17 ;
V_16 = V_2 -> V_11 -> V_12 -> V_13 ;
F_3 ( V_2 , L_4 , V_16 ) ;
V_2 -> V_14 = F_9 ( V_16 , V_18 ) ;
if ( ! V_2 -> V_14 ) {
V_6 = - V_19 ;
goto V_20;
}
V_15 = ( T_5 * ) V_2 -> V_14 ;
V_2 -> V_11 -> V_21 -> V_22 -> V_23 . V_24 ( V_2 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 , L_5 , V_3 ) ;
V_6 = - V_9 ;
goto V_25;
}
V_6 = V_2 -> V_11 -> V_21 -> V_22 -> V_26 . V_27 ( V_2 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 , L_6 ) ;
V_6 = - V_9 ;
goto V_25;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 += sizeof( T_4 ) ) {
T_1 V_28 ;
F_10 ( V_2 , V_29 ,
V_30 & ( V_17 << 1 ) ) ;
V_6 = F_11 ( V_2 , V_29 ,
V_31 ,
V_31 ,
V_32 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 , L_7 ,
V_17 ) ;
goto V_33;
}
V_28 = F_12 ( V_2 , V_29 ) ;
V_15 [ V_17 / 2 ] = F_13 ( V_28 >> 16 ) ;
}
F_3 ( V_2 , L_8 ,
L_9 ,
F_7 ( V_2 , V_34 ) ) ;
V_6 = 0 ;
V_33:
V_2 -> V_11 -> V_21 -> V_22 -> V_26 . V_35 ( V_2 ) ;
V_25:
if ( V_6 )
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
V_20:
return V_6 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static void F_17 ( const struct V_1 * V_2 ,
int V_36 , int * V_37 ,
const struct V_38 * * V_39 ,
const T_2 * * V_40 )
{
T_1 V_10 = V_2 -> V_11 -> V_21 -> V_22 ->
V_26 . V_41 [ V_36 - 1 ] ;
switch ( V_36 ) {
case 1 :
* V_37 = F_18 ( V_42 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_42 ;
break;
case 2 :
* V_37 = F_18 ( V_43 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_43 ;
break;
case 3 :
* V_37 = F_18 ( V_44 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_44 ;
break;
case 4 :
* V_37 = F_18 ( V_45 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_45 ;
break;
case 5 :
* V_37 = F_18 ( V_46 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_46 ;
break;
case 6 :
* V_37 = F_18 ( V_47 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_47 ;
break;
case 7 :
* V_37 = F_18 ( V_48 ) ;
* V_39 = (struct V_38 * )
F_5 ( V_2 , V_10 ) ;
* V_40 = V_48 ;
break;
default:
F_19 () ;
}
}
static int F_20 ( struct V_1 * V_2 ,
enum V_49 V_50 , T_4 V_51 ,
const struct V_38 * V_52 ,
T_2 V_53 )
{
struct V_54 * V_55 ;
V_55 = (struct V_54 * )
F_21 ( V_2 , V_50 , V_51 ) ;
if ( ! F_22 ( V_55 ) )
return - 1 ;
F_3 ( V_2 , L_10
L_11 ,
V_55 -> V_51 ,
F_23 ( V_55 ) ?
L_12 : L_13 ,
F_24 ( V_56 ) ,
F_24 ( V_57 ) ,
F_24 ( V_58 ) ,
F_24 ( V_59 ) ,
F_24 ( V_60 ) ,
V_52 -> V_61 ,
V_52 -> V_62 ,
( ( V_52 -> V_61 & V_63 )
&& ! ( V_52 -> V_61 & V_64 ) ) ?
L_14 : L_15 ) ;
V_55 -> V_65 = * V_52 ;
V_55 -> V_66 = V_52 -> V_62 ;
V_55 -> V_67 = V_52 -> V_61 ;
if ( V_52 -> V_61 & V_68 )
V_55 -> V_69 &=
~ V_53 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
const T_2 * V_40 = NULL ;
const struct V_38 * V_39 = NULL ;
int V_50 , V_70 ;
struct V_54 * V_55 ;
if ( V_2 -> V_71 ) {
F_3 ( V_2 , L_16 ) ;
return 0 ;
}
F_3 ( V_2 , L_17 ) ;
V_2 -> V_71 =
F_18 ( V_42 ) +
F_18 ( V_43 ) +
F_18 ( V_44 ) +
F_18 ( V_45 ) +
F_18 ( V_46 ) ;
F_3 ( V_2 , L_18 ,
V_2 -> V_71 ) ;
V_2 -> V_72 = F_9 ( sizeof( struct V_54 ) *
V_2 -> V_71 , V_18 ) ;
if ( ! V_2 -> V_72 ) {
F_4 ( V_2 , L_19 ) ;
V_2 -> V_71 = 0 ;
return - V_19 ;
}
V_55 = V_2 -> V_72 ;
for ( V_50 = 1 ; V_50 <= 5 ; V_50 ++ ) {
F_17 ( V_2 , V_50 , & V_37 ,
& V_39 , & V_40 ) ;
for ( V_70 = 0 ; V_70 < V_37 ; V_70 ++ ) {
V_55 -> V_51 = V_40 [ V_70 ] ;
V_55 -> V_50 = ( V_50 == 1 ) ? V_73 :
V_74 ;
V_55 -> V_14 = V_39 [ V_70 ] ;
V_55 -> V_61 = V_39 [ V_70 ] . V_61 ;
V_55 -> V_69 =
V_75 ;
if ( ! ( F_22 ( V_55 ) ) ) {
F_3 ( V_2 ,
L_20
L_21 ,
V_55 -> V_51 ,
V_55 -> V_61 ,
F_23 ( V_55 ) ?
L_12 : L_13 ) ;
V_55 ++ ;
continue;
}
V_55 -> V_62 = V_55 -> V_76 =
V_39 [ V_70 ] . V_62 ;
V_55 -> V_77 = V_39 [ V_70 ] . V_62 ;
V_55 -> V_78 = 0 ;
F_3 ( V_2 , L_22
L_23
L_11 ,
V_55 -> V_51 ,
F_23 ( V_55 ) ?
L_12 : L_13 ,
F_26 ( V_79 ) ,
F_26 ( V_56 ) ,
F_26 ( V_57 ) ,
F_26 ( V_58 ) ,
F_26 ( V_59 ) ,
F_26 ( V_60 ) ,
V_39 [ V_70 ] . V_61 ,
V_39 [ V_70 ] . V_62 ,
( ( V_39 [ V_70 ] .
V_61 & V_63 )
&& ! ( V_39 [ V_70 ] .
V_61 & V_64 ) )
? L_14 : L_15 ) ;
V_55 ++ ;
}
}
if ( V_2 -> V_11 -> V_21 -> V_22 -> V_26 . V_41 [ 5 ] ==
V_80 &&
V_2 -> V_11 -> V_21 -> V_22 -> V_26 . V_41 [ 6 ] ==
V_80 )
return 0 ;
for ( V_50 = 6 ; V_50 <= 7 ; V_50 ++ ) {
enum V_49 V_81 ;
F_17 ( V_2 , V_50 , & V_37 ,
& V_39 , & V_40 ) ;
V_81 =
( V_50 == 6 ) ? V_73 : V_74 ;
for ( V_70 = 0 ; V_70 < V_37 ; V_70 ++ ) {
F_20 ( V_2 , V_81 ,
V_40 [ V_70 ] ,
& V_39 [ V_70 ] ,
V_82 ) ;
F_20 ( V_2 , V_81 ,
V_40 [ V_70 ] + 4 ,
& V_39 [ V_70 ] ,
V_83 ) ;
}
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_72 ) ;
V_2 -> V_71 = 0 ;
}
const struct
V_54 * F_21 ( const struct V_1 * V_2 ,
enum V_49 V_50 , T_4 V_51 )
{
int V_84 ;
switch ( V_50 ) {
case V_74 :
for ( V_84 = 14 ; V_84 < V_2 -> V_71 ; V_84 ++ ) {
if ( V_2 -> V_72 [ V_84 ] . V_51 == V_51 )
return & V_2 -> V_72 [ V_84 ] ;
}
break;
case V_73 :
if ( V_51 >= 1 && V_51 <= 14 )
return & V_2 -> V_72 [ V_51 - 1 ] ;
break;
default:
F_19 () ;
}
return NULL ;
}
