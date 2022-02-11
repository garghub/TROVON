T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_3 ) ;
}
T_1 F_2 ( struct V_1 * V_2 , T_2 V_4 )
{
T_3 V_5 ;
T_3 V_6 = V_4 ;
T_3 V_7 = V_4 << 16 ;
T_1 V_8 = V_9 ;
T_1 V_10 = 0 , V_11 = 200 ;
while ( V_10 < V_11 ) {
if ( F_5 ( V_2 ) ) {
V_8 = - V_12 ;
goto V_13;
}
V_5 = F_6 ( V_14 ) ;
if ( ! ( V_5 & V_7 ) )
break;
F_7 ( V_2 ) ;
F_8 ( 5 ) ;
V_10 ++ ;
}
if ( V_10 == V_11 ) {
F_9 ( L_1 ) ;
V_8 = - V_12 ;
goto V_13;
}
V_5 |= V_6 ;
F_10 ( V_14 , V_5 ) ;
F_7 ( V_2 ) ;
V_13:
return V_8 ;
}
void F_4 ( struct V_1 * V_2 , T_2 V_4 )
{
T_3 V_5 ;
while ( F_5 ( V_2 ) != V_9 )
;
V_5 = F_6 ( V_14 ) ;
V_5 &= ~ V_4 ;
F_10 ( V_14 , V_5 ) ;
F_7 ( V_2 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
T_3 V_15 ;
T_1 V_8 = V_9 ;
T_1 V_11 = V_2 -> V_16 . V_17 + 1 ;
T_1 V_10 = 0 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_15 = F_6 ( V_18 ) ;
F_10 ( V_18 , V_15 | V_19 ) ;
if ( F_6 ( V_18 ) & V_19 )
break;
F_11 ( 50 ) ;
}
if ( V_10 == V_11 ) {
F_12 ( V_2 ) ;
F_9 ( L_2 ) ;
V_8 = - V_20 ;
goto V_13;
}
V_13:
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_3 V_15 ;
V_15 = F_6 ( V_18 ) ;
V_15 &= ~ V_19 ;
F_10 ( V_18 , V_15 ) ;
}
T_1 F_13 ( struct V_1 * V_2 , T_2 V_21 , T_2 V_22 ,
T_2 * V_23 )
{
T_1 V_24 = V_9 ;
T_2 V_10 , V_25 ;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 += V_26 ) {
V_25 = ( V_22 - V_10 ) / V_26 > 0 ?
V_26 : ( V_22 - V_10 ) ;
if ( V_2 -> V_16 . V_27 . V_28 ( V_2 ) == V_9 ) {
V_24 = F_14 ( V_2 , V_21 , V_25 ,
V_23 + V_10 ) ;
V_2 -> V_16 . V_27 . V_29 ( V_2 ) ;
} else {
V_24 = V_12 ;
}
if ( V_24 != V_9 )
break;
}
return V_24 ;
}
T_1 F_15 ( struct V_1 * V_2 , T_2 V_21 , T_2 V_22 ,
T_2 * V_23 )
{
T_1 V_24 = V_9 ;
T_2 V_10 , V_25 ;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 += V_26 ) {
V_25 = ( V_22 - V_10 ) / V_26 > 0 ?
V_26 : ( V_22 - V_10 ) ;
if ( V_2 -> V_16 . V_27 . V_28 ( V_2 ) == V_9 ) {
V_24 = F_16 ( V_2 , V_21 , V_25 ,
V_23 + V_10 ) ;
V_2 -> V_16 . V_27 . V_29 ( V_2 ) ;
} else {
V_24 = V_12 ;
}
if ( V_24 != V_9 )
break;
}
return V_24 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_2 V_21 , T_2 V_22 ,
T_2 * V_23 )
{
struct V_30 * V_16 = & V_2 -> V_16 ;
T_3 V_10 , V_31 , V_32 = 0 ;
T_3 V_33 = 100000 ;
T_1 V_8 = V_9 ;
if ( ( V_21 >= V_16 -> V_17 ) || ( V_22 > ( V_16 -> V_17 - V_21 ) ) ||
( V_22 == 0 ) ) {
F_9 ( L_3 ) ;
V_8 = - V_20 ;
goto V_13;
}
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
V_32 = ( ( V_21 + V_10 ) << V_34 ) |
( V_23 [ V_10 ] << V_35 ) |
V_36 ;
F_10 ( V_37 , V_32 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if ( V_38 &
F_6 ( V_37 ) ) {
V_8 = V_9 ;
break;
}
F_11 ( 5 ) ;
}
if ( V_8 != V_9 ) {
F_9 ( L_4 ) ;
break;
}
}
V_13:
return V_8 ;
}
T_1 F_17 ( struct V_1 * V_2 , T_2 V_21 , T_2 V_22 ,
T_2 * V_23 )
{
T_1 V_8 = V_9 ;
switch ( V_21 ) {
case V_39 :
V_8 = F_18 ( V_2 , V_21 , & V_23 [ 0 ] ) ;
V_8 |= F_18 ( V_2 , V_21 + 1 , & V_23 [ 1 ] ) ;
V_8 |= F_18 ( V_2 , V_21 + 2 , & V_23 [ 2 ] ) ;
if ( V_8 != V_9 )
F_9 ( L_5 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
F_18 ( V_2 , V_21 , V_23 ) ;
break;
case V_45 :
* V_23 = V_46 ;
break;
case V_47 :
* V_23 = V_2 -> V_48 ;
break;
case V_49 :
* V_23 = V_2 -> V_50 ;
break;
case V_51 :
* V_23 = V_2 -> V_52 ;
break;
case V_53 :
* V_23 = V_2 -> V_54 ;
break;
default:
F_9 ( L_6 , V_21 ) ;
* V_23 = V_55 ;
break;
}
return V_8 ;
}
T_1 F_18 ( struct V_1 * V_2 , T_2 V_56 , T_2 * V_23 )
{
T_1 V_24 = - V_57 ;
T_3 V_58 ;
T_2 V_10 ;
T_4 V_59 , V_60 ;
for ( V_10 = 0 ; V_10 < V_61 ; V_10 ++ ) {
V_58 = F_6 ( F_19 ( V_10 ) ) ;
V_59 = F_20 ( V_58 ) ;
if ( V_59 == V_62 )
break;
if ( V_59 == V_63 )
V_10 += V_64 ;
if ( V_59 == V_65 )
V_10 += V_66 ;
if ( V_59 == V_67 ) {
V_60 = F_21 ( V_58 ) ;
if ( V_60 == ( T_4 ) V_56 ) {
* V_23 = F_22 ( V_58 ) ;
F_9 ( L_7 ,
V_56 , * V_23 ) ;
V_24 = V_9 ;
break;
}
}
}
if ( V_24 != V_9 )
F_9 ( L_8 , V_56 ) ;
return V_24 ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
T_1 V_24 = V_9 ;
T_1 (* F_24)( struct V_1 * , T_2 , T_2 , T_2 * );
if ( V_2 -> V_16 . V_27 . V_28 ( V_2 ) == V_9 ) {
F_24 = V_2 -> V_16 . V_27 . V_68 ;
V_2 -> V_16 . V_27 . V_68 = F_14 ;
V_24 = F_25 ( V_2 ) ;
V_2 -> V_16 . V_27 . V_68 = F_24 ;
V_2 -> V_16 . V_27 . V_29 ( V_2 ) ;
} else {
V_24 = V_12 ;
}
return V_24 ;
}
T_1 F_26 ( struct V_1 * V_2 )
{
T_1 V_8 = V_9 ;
T_2 V_69 = 0 ;
T_2 V_10 , V_70 ;
V_8 = F_14 ( V_2 , 0 , 1 , & V_70 ) ;
if ( V_8 != V_9 ) {
F_9 ( L_9 ) ;
goto V_13;
}
if ( V_2 -> V_16 . V_27 . V_28 ( V_2 ) == V_9 ) {
for ( V_10 = 0 ; V_10 < V_71 ; V_10 ++ ) {
V_8 = F_14 ( V_2 , V_10 , 1 , & V_70 ) ;
if ( V_8 ) {
V_2 -> V_16 . V_27 . V_29 ( V_2 ) ;
F_9 ( L_10 ) ;
goto V_13;
}
V_69 += V_70 ;
}
V_69 = ( T_2 ) V_72 - V_69 ;
V_8 = F_16 ( V_2 , V_71 , 1 ,
& V_69 ) ;
if ( V_8 != V_9 ) {
V_2 -> V_16 . V_27 . V_29 ( V_2 ) ;
F_9 ( L_11 ) ;
goto V_13;
}
V_2 -> V_16 . V_27 . V_29 ( V_2 ) ;
V_8 = F_27 ( V_2 ) ;
} else {
V_8 = - V_12 ;
}
V_13:
return V_8 ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
T_1 V_8 = V_9 ;
T_3 V_73 ;
V_8 = F_28 ( V_2 ) ;
if ( V_8 == - V_20 ) {
F_9 ( L_12 ) ;
goto V_13;
}
V_73 = F_6 ( V_74 ) | V_75 ;
F_10 ( V_74 , V_73 ) ;
V_8 = F_28 ( V_2 ) ;
if ( V_8 == V_9 )
F_9 ( L_13 ) ;
else
F_9 ( L_12 ) ;
V_13:
return V_8 ;
}
T_1 F_28 ( struct V_1 * V_2 )
{
T_1 V_8 = - V_20 ;
T_3 V_10 , V_76 ;
for ( V_10 = 0 ; V_10 < V_77 ; V_10 ++ ) {
V_76 = F_6 ( V_74 ) ;
if ( V_76 & V_78 ) {
V_8 = V_9 ;
break;
}
F_11 ( 5 ) ;
}
return V_8 ;
}
T_1 F_29 ( struct V_1 * V_2 , T_2 * V_23 )
{
T_1 V_8 ;
V_8 = V_2 -> V_16 . V_27 . V_68 ( V_2 , V_40 , 1 , V_23 ) ;
if ( V_8 ) {
F_9 ( L_14 ) ;
goto V_13;
}
if ( * V_23 == V_79 || * V_23 == V_80 ) {
switch ( V_2 -> V_81 . V_82 ) {
case V_83 :
* V_23 = V_84 ;
break;
case V_85 :
default:
* V_23 = V_46 ;
break;
}
}
V_13:
return V_8 ;
}
