static T_1 F_1 ( T_2 * V_1 , T_3 * V_2 ,
T_3 * V_3 , int V_4 )
{
int V_5 = 100 ;
int V_6 , V_7 ;
int V_8 ;
V_6 = ( ( V_4 / 2 ) + V_9 - 1 ) /
V_9 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( V_1 [ V_8 ] < V_5 && V_1 [ V_8 ] )
V_5 = V_1 [ V_8 ] ;
}
V_7 = ( V_6 / V_5 ) + 1 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
int V_11 = F_2 ( V_1 [ V_8 ] * V_7 , V_12 ) ;
if ( V_11 < V_6 )
V_11 = V_6 ;
V_2 [ V_8 ] = V_11 ;
V_3 [ V_8 ] = V_1 [ V_8 ] ? ( V_1 [ V_8 ] * V_13 ) / 100 : V_6 ;
}
return 0 ;
}
T_1 F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
int V_4 , T_4 V_18 )
{
struct V_19 * V_20 ;
int V_6 ;
int V_21 ;
int V_5 = 100 ;
T_5 V_22 = 0 ;
T_5 V_23 = 0 ;
T_6 V_24 = 0 ;
T_4 V_25 = 0 ;
T_4 V_8 ;
if ( ! V_17 )
return V_26 ;
V_6 = ( ( V_4 / 2 ) + V_9 - 1 ) /
V_9 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_17 -> V_27 [ V_8 ] . V_28 [ V_18 ] ;
V_25 = V_17 -> V_29 [ V_18 ] [ V_20 -> V_30 ] ;
V_24 = V_20 -> V_31 ;
V_24 = ( V_24 * V_25 ) / 100 ;
if ( V_24 && V_24 < V_5 )
V_5 = V_24 ;
}
V_21 = ( V_6 / V_5 ) + 1 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_17 -> V_27 [ V_8 ] . V_28 [ V_18 ] ;
V_25 = V_17 -> V_29 [ V_18 ] [ V_20 -> V_30 ] ;
V_24 = V_20 -> V_31 ;
V_24 = ( V_24 * V_25 ) / 100 ;
if ( V_20 -> V_31 > 0 && V_24 == 0 )
V_24 = 1 ;
V_20 -> V_32 = ( T_4 ) V_24 ;
V_22 = F_2 ( V_24 * V_21 ,
V_12 ) ;
V_20 -> V_33 = ( T_6 ) V_22 ;
V_23 = ( V_24 * V_13 ) / 100 ;
if ( V_23 && ( V_23 < V_6 ) )
V_23 = V_6 ;
if ( V_18 == V_34 ) {
if ( ( V_15 -> V_35 . type == V_36 ) &&
V_23 &&
( V_23 < V_37 ) )
V_23 = V_37 ;
V_17 -> V_27 [ V_8 ] . V_38 =
( T_6 ) V_23 ;
}
V_20 -> V_39 = ( T_6 ) V_23 ;
}
return 0 ;
}
void F_4 ( struct V_16 * V_40 , T_4 * V_41 )
{
struct V_42 * V_27 = & V_40 -> V_27 [ 0 ] ;
int V_43 ;
for ( * V_41 = 0 , V_43 = 0 ; V_43 < V_10 ; V_43 ++ ) {
if ( V_27 [ V_43 ] . V_44 != V_45 )
* V_41 |= 1 << V_43 ;
}
}
void F_5 ( struct V_16 * V_40 , int V_18 ,
T_6 * V_2 )
{
struct V_42 * V_27 = & V_40 -> V_27 [ 0 ] ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_10 ; V_43 ++ )
V_2 [ V_43 ] = V_27 [ V_43 ] . V_28 [ V_18 ] . V_33 ;
}
void F_6 ( struct V_16 * V_40 , T_6 * V_3 )
{
struct V_42 * V_27 = & V_40 -> V_27 [ 0 ] ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_10 ; V_43 ++ )
V_3 [ V_43 ] = V_27 [ V_43 ] . V_38 ;
}
void F_7 ( struct V_16 * V_40 , int V_18 ,
T_4 * V_46 )
{
struct V_42 * V_27 = & V_40 -> V_27 [ 0 ] ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_10 ; V_43 ++ )
V_46 [ V_43 ] = V_27 [ V_43 ] . V_28 [ V_18 ] . V_30 ;
}
void F_8 ( struct V_16 * V_40 , int V_18 ,
T_4 * V_47 )
{
struct V_42 * V_27 = & V_40 -> V_27 [ 0 ] ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_10 ; V_43 ++ )
V_47 [ V_43 ] = V_27 [ V_43 ] . V_28 [ V_18 ] . V_48 ;
}
T_4 F_9 ( struct V_16 * V_40 , int V_18 , T_4 V_49 )
{
struct V_42 * V_27 = & V_40 -> V_27 [ 0 ] ;
T_4 V_50 = 1 << V_49 ;
T_4 V_43 = V_40 -> V_51 . V_52 ;
if ( ! V_43 )
return 0 ;
for ( V_43 -- ; V_43 ; V_43 -- ) {
if ( V_50 & V_27 [ V_43 ] . V_28 [ V_18 ] . V_53 )
break;
}
return V_43 ;
}
void F_10 ( struct V_16 * V_40 , int V_18 , T_4 * V_54 )
{
T_4 V_49 ;
for ( V_49 = 0 ; V_49 < V_55 ; V_49 ++ )
V_54 [ V_49 ] = F_9 ( V_40 , V_18 , V_49 ) ;
}
T_1 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
T_4 V_41 ;
T_4 V_47 [ V_10 ] ;
T_4 V_46 [ V_10 ] ;
T_4 V_56 [ V_10 ] ;
T_6 V_2 [ V_10 ] ;
T_6 V_3 [ V_10 ] ;
F_4 ( V_17 , & V_41 ) ;
F_5 ( V_17 , V_34 , V_2 ) ;
F_6 ( V_17 , V_3 ) ;
F_7 ( V_17 , V_34 , V_46 ) ;
F_8 ( V_17 , V_34 , V_47 ) ;
F_10 ( V_17 , V_34 , V_56 ) ;
switch ( V_15 -> V_35 . type ) {
case V_36 :
return F_12 ( V_15 , V_41 , V_2 , V_3 ,
V_46 , V_47 ) ;
case V_57 :
case V_58 :
return F_13 ( V_15 , V_41 , V_2 , V_3 ,
V_46 , V_47 , V_56 ) ;
default:
break;
}
return 0 ;
}
T_1 F_14 ( struct V_14 * V_15 , T_4 V_41 , T_4 * V_56 )
{
switch ( V_15 -> V_35 . type ) {
case V_36 :
return F_15 ( V_15 , V_41 ) ;
case V_57 :
case V_58 :
return F_16 ( V_15 , V_41 , V_56 ) ;
default:
break;
}
return - V_59 ;
}
T_1 F_17 ( struct V_14 * V_15 , struct V_60 * V_61 , int V_4 )
{
T_3 V_2 [ V_62 ] , V_3 [ V_62 ] ;
T_2 V_48 [ V_62 ] ;
int V_8 ;
T_2 V_30 [ V_62 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
for ( V_8 = 0 ; V_8 < V_62 ; V_8 ++ ) {
switch ( V_61 -> V_63 [ V_8 ] ) {
case V_64 :
V_48 [ V_8 ] = 2 ;
break;
case V_65 :
V_48 [ V_8 ] = 0 ;
break;
default:
return - V_59 ;
}
}
F_1 ( V_61 -> V_66 , V_2 , V_3 , V_4 ) ;
return F_18 ( V_15 , V_2 , V_3 ,
V_30 , V_48 , V_61 -> V_56 ) ;
}
T_1 F_18 ( struct V_14 * V_15 ,
T_6 * V_2 , T_6 * V_3 , T_4 * V_30 ,
T_4 * V_48 , T_4 * V_56 )
{
switch ( V_15 -> V_35 . type ) {
case V_36 :
F_19 ( V_15 , V_2 , V_3 ,
V_48 ) ;
F_20 ( V_15 , V_2 , V_3 ,
V_30 , V_48 ) ;
F_21 ( V_15 , V_2 , V_3 ,
V_30 , V_48 ) ;
break;
case V_57 :
case V_58 :
F_22 ( V_15 , V_2 , V_3 ,
V_30 , V_48 , V_56 ) ;
F_23 ( V_15 , V_2 , V_3 ,
V_30 , V_48 ) ;
F_24 ( V_15 , V_2 , V_3 , V_30 ,
V_48 , V_56 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_25 ( struct V_14 * V_15 , T_4 * V_54 )
{
T_5 V_67 , V_8 ;
V_67 = F_26 ( V_15 , V_68 ) ;
for ( V_8 = 0 ; V_8 < V_55 ; V_8 ++ )
V_54 [ V_8 ] = V_69 &
( V_67 >> ( V_8 * V_70 ) ) ;
}
void F_27 ( struct V_14 * V_15 , T_4 * V_54 )
{
switch ( V_15 -> V_35 . type ) {
case V_57 :
case V_58 :
F_25 ( V_15 , V_54 ) ;
break;
default:
break;
}
}
