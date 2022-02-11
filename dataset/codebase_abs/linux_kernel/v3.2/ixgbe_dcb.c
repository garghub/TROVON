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
T_1 V_22 = 0 ;
T_5 V_23 = 0 ;
T_5 V_24 = 0 ;
T_6 V_25 = 0 ;
T_4 V_26 = 0 ;
T_4 V_8 ;
if ( V_17 == NULL ) {
V_22 = V_27 ;
goto V_28;
}
V_6 = ( ( V_4 / 2 ) + V_9 - 1 ) /
V_9 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_17 -> V_29 [ V_8 ] . V_30 [ V_18 ] ;
V_26 = V_17 -> V_31 [ V_18 ] [ V_20 -> V_32 ] ;
V_25 = V_20 -> V_33 ;
V_25 = ( V_25 * V_26 ) / 100 ;
if ( V_25 && V_25 < V_5 )
V_5 = V_25 ;
}
V_21 = ( V_6 / V_5 ) + 1 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_17 -> V_29 [ V_8 ] . V_30 [ V_18 ] ;
V_26 = V_17 -> V_31 [ V_18 ] [ V_20 -> V_32 ] ;
V_25 = V_20 -> V_33 ;
V_25 = ( V_25 * V_26 ) / 100 ;
if ( V_20 -> V_33 > 0 && V_25 == 0 )
V_25 = 1 ;
V_20 -> V_34 = ( T_4 ) V_25 ;
V_23 = F_2 ( V_25 * V_21 ,
V_12 ) ;
V_20 -> V_35 = ( T_6 ) V_23 ;
V_24 = ( V_25 * V_13 ) / 100 ;
if ( V_24 && ( V_24 < V_6 ) )
V_24 = V_6 ;
if ( V_18 == V_36 ) {
if ( ( V_15 -> V_37 . type == V_38 ) &&
V_24 &&
( V_24 < V_39 ) )
V_24 = V_39 ;
V_17 -> V_29 [ V_8 ] . V_40 =
( T_6 ) V_24 ;
}
V_20 -> V_41 = ( T_6 ) V_24 ;
}
V_28:
return V_22 ;
}
void F_4 ( struct V_16 * V_42 , T_4 * V_43 )
{
int V_8 ;
* V_43 = 0 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
* V_43 |= ! ! ( V_42 -> V_29 [ V_8 ] . V_44 & 0xF ) << V_8 ;
}
void F_5 ( struct V_16 * V_42 , int V_18 ,
T_6 * V_2 )
{
struct V_19 * V_20 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_42 -> V_29 [ V_8 ] . V_30 [ V_18 ] ;
V_2 [ V_8 ] = V_20 -> V_35 ;
}
}
void F_6 ( struct V_16 * V_42 , T_6 * V_3 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
V_3 [ V_8 ] = V_42 -> V_29 [ V_8 ] . V_40 ;
}
void F_7 ( struct V_16 * V_42 , int V_18 ,
T_4 * V_45 )
{
struct V_19 * V_20 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_42 -> V_29 [ V_8 ] . V_30 [ V_18 ] ;
V_45 [ V_8 ] = V_20 -> V_32 ;
}
}
void F_8 ( struct V_16 * V_42 , int V_18 ,
T_4 * V_46 )
{
struct V_19 * V_20 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_20 = & V_42 -> V_29 [ V_8 ] . V_30 [ V_18 ] ;
V_46 [ V_8 ] = V_20 -> V_47 ;
}
}
void F_9 ( struct V_16 * V_42 , int V_18 , T_4 * V_48 )
{
int V_8 , V_49 ;
unsigned long V_50 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_50 = V_42 -> V_29 [ V_8 ] . V_30 [ V_18 ] . V_51 ;
F_10 (up, &bitmap, MAX_USER_PRIORITY)
V_48 [ V_49 ] = V_8 ;
}
}
T_1 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
T_1 V_52 = 0 ;
T_4 V_43 ;
T_4 V_46 [ V_10 ] ;
T_4 V_45 [ V_10 ] ;
T_4 V_53 [ V_10 ] ;
T_6 V_2 [ V_10 ] ;
T_6 V_3 [ V_10 ] ;
F_4 ( V_17 , & V_43 ) ;
F_5 ( V_17 , V_36 , V_2 ) ;
F_6 ( V_17 , V_3 ) ;
F_7 ( V_17 , V_36 , V_45 ) ;
F_8 ( V_17 , V_36 , V_46 ) ;
F_9 ( V_17 , V_36 , V_53 ) ;
switch ( V_15 -> V_37 . type ) {
case V_38 :
V_52 = F_12 ( V_15 , V_43 , V_2 , V_3 ,
V_45 , V_46 ) ;
break;
case V_54 :
case V_55 :
V_52 = F_13 ( V_15 , V_43 , V_2 , V_3 ,
V_45 , V_46 , V_53 ) ;
break;
default:
break;
}
return V_52 ;
}
T_1 F_14 ( struct V_14 * V_15 , T_4 V_43 , T_4 * V_53 )
{
int V_52 = - V_56 ;
switch ( V_15 -> V_37 . type ) {
case V_38 :
V_52 = F_15 ( V_15 , V_43 ) ;
break;
case V_54 :
case V_55 :
V_52 = F_16 ( V_15 , V_43 , V_53 ) ;
break;
default:
break;
}
return V_52 ;
}
T_1 F_17 ( struct V_14 * V_15 , struct V_57 * V_58 , int V_4 )
{
T_3 V_2 [ V_59 ] , V_3 [ V_59 ] ;
T_2 V_47 [ V_59 ] ;
int V_8 ;
T_2 V_32 [ V_59 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
for ( V_8 = 0 ; V_8 < V_59 ; V_8 ++ ) {
switch ( V_58 -> V_60 [ V_8 ] ) {
case V_61 :
V_47 [ V_8 ] = 2 ;
break;
case V_62 :
V_47 [ V_8 ] = 0 ;
break;
default:
return - V_56 ;
}
}
F_1 ( V_58 -> V_63 , V_2 , V_3 , V_4 ) ;
return F_18 ( V_15 , V_2 , V_3 ,
V_32 , V_47 , V_58 -> V_53 ) ;
}
T_1 F_18 ( struct V_14 * V_15 ,
T_6 * V_2 , T_6 * V_3 , T_4 * V_32 ,
T_4 * V_47 , T_4 * V_53 )
{
switch ( V_15 -> V_37 . type ) {
case V_38 :
F_19 ( V_15 , V_2 , V_3 ,
V_47 ) ;
F_20 ( V_15 , V_2 , V_3 ,
V_32 , V_47 ) ;
F_21 ( V_15 , V_2 , V_3 ,
V_32 , V_47 ) ;
break;
case V_54 :
case V_55 :
F_22 ( V_15 , V_2 , V_3 ,
V_32 , V_47 , V_53 ) ;
F_23 ( V_15 , V_2 , V_3 ,
V_32 , V_47 ) ;
F_24 ( V_15 , V_2 , V_3 , V_32 ,
V_47 , V_53 ) ;
break;
default:
break;
}
return 0 ;
}
