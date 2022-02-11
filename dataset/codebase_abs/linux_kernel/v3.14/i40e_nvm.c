T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 = 0 ;
T_2 V_6 , V_7 ;
T_3 V_8 ;
V_7 = F_2 ( V_2 , V_9 ) ;
V_8 = ( ( V_7 & V_10 ) >>
V_11 ) ;
V_4 -> V_8 = ( 1 << V_8 ) * V_12 ;
V_6 = F_2 ( V_2 , V_13 ) ;
if ( V_6 & V_14 ) {
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = false ;
} else {
V_4 -> V_17 = true ;
V_5 = V_18 ;
F_3 ( V_2 , L_1 ) ;
}
return V_5 ;
}
T_1 F_4 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
T_1 V_5 = 0 ;
T_4 V_21 , V_15 ;
T_4 time = 0 ;
if ( V_2 -> V_4 . V_17 )
goto V_22;
V_5 = F_5 ( V_2 , V_23 , V_20 ,
0 , & time , NULL ) ;
V_21 = F_2 ( V_2 , V_24 ) ;
V_2 -> V_4 . V_25 = F_6 ( time ) + V_21 ;
if ( V_5 ) {
if ( time > V_16 )
V_15 = F_6 ( V_16 )
+ V_21 ;
else
V_15 = V_2 -> V_4 . V_25 ;
while ( V_21 < V_15 ) {
F_7 ( 10000 , 20000 ) ;
V_5 = F_5 ( V_2 ,
V_23 ,
V_20 , 0 , & time ,
NULL ) ;
if ( ! V_5 ) {
V_2 -> V_4 . V_25 =
F_6 ( time ) + V_21 ;
break;
}
V_21 = F_2 ( V_2 , V_24 ) ;
}
if ( V_5 ) {
V_2 -> V_4 . V_25 = 0 ;
V_2 -> V_4 . V_26 =
F_6 ( time ) + V_21 ;
F_3 ( V_2 , L_2 ,
time ) ;
}
}
V_22:
return V_5 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_17 )
F_9 ( V_2 , V_23 , 0 , NULL ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_5 = V_27 ;
T_2 V_28 , V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_28 = F_2 ( V_2 , V_31 ) ;
if ( V_28 & V_32 ) {
V_5 = 0 ;
break;
}
F_11 ( 5 ) ;
}
if ( V_5 == V_27 )
F_3 ( V_2 , L_3 ) ;
return V_5 ;
}
T_1 F_12 ( struct V_1 * V_2 , T_5 V_33 ,
T_5 * V_34 )
{
T_1 V_5 = V_27 ;
T_2 V_35 ;
if ( V_33 >= V_2 -> V_4 . V_8 ) {
F_3 ( V_2 , L_4 ) ;
V_5 = V_36 ;
goto V_37;
}
V_5 = F_10 ( V_2 ) ;
if ( ! V_5 ) {
V_35 = ( T_2 ) ( V_33 << V_38 ) |
( 1 << V_39 ) ;
F_13 ( V_2 , V_31 , V_35 ) ;
V_5 = F_10 ( V_2 ) ;
if ( ! V_5 ) {
V_35 = F_2 ( V_2 , V_40 ) ;
* V_34 = ( T_5 ) ( ( V_35 &
V_41 )
>> V_42 ) ;
}
}
if ( V_5 )
F_3 ( V_2 , L_5 ,
V_33 ) ;
V_37:
return V_5 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_5 V_33 ,
T_5 * V_43 , T_5 * V_34 )
{
T_1 V_5 = 0 ;
T_5 V_44 , V_45 ;
for ( V_45 = 0 ; V_45 < * V_43 ; V_45 ++ ) {
V_44 = V_33 + V_45 ;
V_5 = F_12 ( V_2 , V_44 , & V_34 [ V_45 ] ) ;
if ( V_5 )
break;
}
* V_43 = V_45 ;
return V_5 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
T_5 * V_46 )
{
T_1 V_5 = 0 ;
T_5 V_47 = 0 ;
T_5 V_48 = 0 ;
T_5 V_49 = 0 ;
T_5 V_45 = 0 ;
T_2 V_50 = 0 ;
V_5 = F_12 ( V_2 , V_51 , & V_49 ) ;
if ( V_5 ) {
V_5 = V_52 ;
goto V_53;
}
V_5 = F_12 ( V_2 , V_54 ,
& V_47 ) ;
if ( V_5 ) {
V_5 = V_52 ;
goto V_53;
}
for ( V_50 = 0 ; V_50 < V_2 -> V_4 . V_8 ; V_50 ++ ) {
if ( V_50 == V_55 )
V_50 ++ ;
if ( V_50 == ( T_2 ) V_49 ) {
V_50 += ( V_56 / 2 ) ;
if ( V_50 >= V_2 -> V_4 . V_8 )
break;
}
if ( V_50 == ( T_2 ) V_47 ) {
V_50 += ( V_57 / 2 ) ;
if ( V_50 >= V_2 -> V_4 . V_8 )
break;
}
V_5 = F_12 ( V_2 , ( T_5 ) V_50 , & V_45 ) ;
if ( V_5 ) {
V_5 = V_52 ;
goto V_53;
}
V_48 += V_45 ;
}
* V_46 = ( T_5 ) V_58 - V_48 ;
V_53:
return V_5 ;
}
T_1 F_16 ( struct V_1 * V_2 ,
T_5 * V_46 )
{
T_1 V_5 = 0 ;
T_5 V_59 = 0 ;
T_5 V_48 = 0 ;
V_5 = F_4 ( V_2 , V_60 ) ;
if ( V_5 )
goto V_61;
V_5 = F_15 ( V_2 , & V_48 ) ;
if ( V_5 )
goto V_62;
F_12 ( V_2 , V_55 , & V_59 ) ;
if ( V_48 != V_59 )
V_5 = V_52 ;
if ( V_46 )
* V_46 = V_48 ;
V_62:
F_8 ( V_2 ) ;
V_61:
return V_5 ;
}
