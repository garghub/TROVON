int
F_1 (
T_1 * V_1 )
{
T_2 * V_2 , * V_3 ;
struct V_4 * V_4 , * V_5 ;
int error = 0 ;
V_4 = F_2 ( ( int ) V_1 -> V_6 ) ;
if ( ! V_4 ) {
error = F_3 ( V_7 ) ;
goto V_8;
}
if ( ! ( V_4 -> V_9 & V_10 ) ||
! ( V_4 -> V_9 & V_11 ) ||
( V_4 -> V_12 & V_13 ) ) {
error = F_3 ( V_14 ) ;
goto V_15;
}
V_5 = F_2 ( ( int ) V_1 -> V_16 ) ;
if ( ! V_5 ) {
error = F_3 ( V_7 ) ;
goto V_15;
}
if ( ! ( V_5 -> V_9 & V_10 ) ||
! ( V_5 -> V_9 & V_11 ) ||
( V_5 -> V_12 & V_13 ) ) {
error = F_3 ( V_14 ) ;
goto V_17;
}
if ( F_4 ( V_4 -> V_18 . V_19 -> V_20 ) ||
F_4 ( V_5 -> V_18 . V_19 -> V_20 ) ) {
error = F_3 ( V_7 ) ;
goto V_17;
}
V_2 = F_5 ( V_4 -> V_18 . V_19 -> V_20 ) ;
V_3 = F_5 ( V_5 -> V_18 . V_19 -> V_20 ) ;
if ( V_2 -> V_21 != V_3 -> V_21 ) {
error = F_3 ( V_7 ) ;
goto V_17;
}
if ( V_2 -> V_22 == V_3 -> V_22 ) {
error = F_3 ( V_7 ) ;
goto V_17;
}
if ( F_6 ( V_2 -> V_21 ) ) {
error = F_3 ( V_23 ) ;
goto V_17;
}
error = F_7 ( V_2 , V_3 , V_1 ) ;
V_17:
F_8 ( V_5 ) ;
V_15:
F_8 ( V_4 ) ;
V_8:
return error ;
}
static int
F_9 (
T_2 * V_2 ,
T_2 * V_3 )
{
if ( V_2 -> V_24 . V_25 == V_26 ||
V_3 -> V_24 . V_25 == V_26 )
return V_7 ;
if ( V_2 -> V_24 . V_27 < V_3 -> V_24 . V_27 )
return V_7 ;
if ( V_2 -> V_24 . V_25 == V_28 &&
V_3 -> V_24 . V_25 == V_29 )
return V_7 ;
if ( V_3 -> V_24 . V_25 == V_28 &&
F_10 ( V_3 , V_30 ) > V_2 -> V_31 . V_32 )
return V_7 ;
if ( V_2 -> V_24 . V_25 == V_28 &&
F_10 ( V_2 , V_30 ) > V_3 -> V_31 . V_32 )
return V_7 ;
if ( V_3 -> V_24 . V_25 == V_29 &&
( ( F_11 ( V_2 ) &&
V_3 -> V_31 . V_33 > F_11 ( V_2 ) ) ||
F_10 ( V_3 , V_30 ) <= V_2 -> V_31 . V_32 ) )
return V_7 ;
if ( V_2 -> V_24 . V_25 == V_29 &&
( ( F_11 ( V_3 ) &&
V_2 -> V_31 . V_33 > F_11 ( V_3 ) ) ||
F_10 ( V_2 , V_30 ) <= V_3 -> V_31 . V_32 ) )
return V_7 ;
return 0 ;
}
static int
F_7 (
T_2 * V_2 ,
T_2 * V_3 ,
T_1 * V_1 )
{
T_3 * V_34 = V_2 -> V_21 ;
T_4 * V_35 ;
T_5 * V_36 = & V_1 -> V_37 ;
T_6 * V_38 , * V_39 , * V_40 ;
int V_41 , V_42 ;
int error = 0 ;
int V_43 = 0 ;
int V_44 = 0 ;
T_7 V_45 ;
V_38 = F_12 ( sizeof( T_6 ) , V_46 ) ;
if ( ! V_38 ) {
error = F_3 ( V_47 ) ;
goto V_8;
}
F_13 ( V_2 , V_3 , V_48 ) ;
F_13 ( V_2 , V_3 , V_49 ) ;
if ( ( V_2 -> V_24 . V_50 & V_51 ) != ( V_3 -> V_24 . V_50 & V_51 ) ) {
error = F_3 ( V_7 ) ;
goto V_52;
}
if ( F_14 ( V_2 ) != F_14 ( V_3 ) ) {
error = F_3 ( V_7 ) ;
goto V_52;
}
if ( F_15 ( F_16 ( V_3 ) ) != 0 ) {
error = F_17 ( V_3 , 0 , - 1 ,
V_53 ) ;
if ( error )
goto V_52;
}
if ( F_15 ( F_16 ( V_3 ) ) != 0 ) {
error = F_3 ( V_7 ) ;
goto V_52;
}
if ( V_1 -> V_54 != 0 ||
V_1 -> V_55 != V_2 -> V_24 . V_56 ||
V_1 -> V_55 != V_3 -> V_24 . V_56 ) {
error = F_3 ( V_57 ) ;
goto V_52;
}
F_18 ( V_2 , 0 ) ;
F_18 ( V_3 , 1 ) ;
error = F_9 ( V_2 , V_3 ) ;
if ( error ) {
F_19 ( V_34 ,
L_1 ,
V_58 , V_2 -> V_22 ) ;
goto V_52;
}
if ( ( V_36 -> V_59 . V_60 != F_16 ( V_2 ) -> V_61 . V_60 ) ||
( V_36 -> V_59 . V_62 != F_16 ( V_2 ) -> V_61 . V_62 ) ||
( V_36 -> V_63 . V_60 != F_16 ( V_2 ) -> V_64 . V_60 ) ||
( V_36 -> V_63 . V_62 != F_16 ( V_2 ) -> V_64 . V_62 ) ) {
error = F_3 ( V_65 ) ;
goto V_52;
}
if ( F_20 ( F_16 ( V_2 ) ) ) {
error = F_3 ( V_65 ) ;
goto V_52;
}
F_21 ( V_2 , V_49 ) ;
F_21 ( V_3 , V_49 ) ;
F_22 ( V_2 , 0 , - 1 , V_66 ) ;
V_35 = F_23 ( V_34 , V_67 ) ;
if ( ( error = F_24 ( V_35 , 0 ,
F_25 ( V_34 ) , 0 ,
0 , 0 ) ) ) {
F_21 ( V_2 , V_48 ) ;
F_21 ( V_3 , V_48 ) ;
F_26 ( V_35 , 0 ) ;
goto V_8;
}
F_13 ( V_2 , V_3 , V_49 ) ;
if ( ( ( F_27 ( V_2 ) != 0 ) && ( V_2 -> V_24 . V_68 > 0 ) ) &&
( V_2 -> V_24 . V_69 != V_26 ) ) {
error = F_28 ( V_35 , V_2 , V_70 , & V_43 ) ;
if ( error )
goto V_71;
}
if ( ( ( F_27 ( V_3 ) != 0 ) && ( V_3 -> V_24 . V_68 > 0 ) ) &&
( V_3 -> V_24 . V_69 != V_26 ) ) {
error = F_28 ( V_35 , V_3 , V_70 ,
& V_44 ) ;
if ( error )
goto V_71;
}
V_39 = & V_2 -> V_31 ;
V_40 = & V_3 -> V_31 ;
* V_38 = * V_39 ;
* V_39 = * V_40 ;
* V_40 = * V_38 ;
V_39 -> V_32 = F_29 ( V_2 , V_30 ) /
( V_72 ) sizeof( V_73 ) ;
V_40 -> V_32 = F_29 ( V_3 , V_30 ) /
( V_72 ) sizeof( V_73 ) ;
V_45 = ( T_7 ) V_2 -> V_24 . V_74 ;
V_2 -> V_24 . V_74 = V_3 -> V_24 . V_74 - V_44 + V_43 ;
V_3 -> V_24 . V_74 = V_45 + V_44 - V_43 ;
V_45 = ( T_7 ) V_2 -> V_24 . V_27 ;
V_2 -> V_24 . V_27 = V_3 -> V_24 . V_27 ;
V_3 -> V_24 . V_27 = V_45 ;
V_45 = ( T_7 ) V_2 -> V_24 . V_25 ;
V_2 -> V_24 . V_25 = V_3 -> V_24 . V_25 ;
V_3 -> V_24 . V_25 = V_45 ;
ASSERT ( V_3 -> V_75 == 0 ) ;
V_3 -> V_75 = V_2 -> V_75 ;
V_2 -> V_75 = 0 ;
V_41 = V_76 ;
switch( V_2 -> V_24 . V_25 ) {
case V_28 :
if ( V_2 -> V_24 . V_27 <= V_77 ) {
V_39 -> V_78 . V_79 =
V_39 -> V_80 . V_81 ;
}
V_41 |= V_82 ;
break;
case V_29 :
V_41 |= V_83 ;
break;
}
V_42 = V_76 ;
switch( V_3 -> V_24 . V_25 ) {
case V_28 :
if ( V_3 -> V_24 . V_27 <= V_77 ) {
V_40 -> V_78 . V_79 =
V_40 -> V_80 . V_81 ;
}
V_42 |= V_82 ;
break;
case V_29 :
V_42 |= V_83 ;
break;
}
F_30 ( V_35 , V_2 , V_49 | V_48 ) ;
F_30 ( V_35 , V_3 , V_49 | V_48 ) ;
F_31 ( V_35 , V_2 , V_41 ) ;
F_31 ( V_35 , V_3 , V_42 ) ;
if ( V_34 -> V_84 & V_85 )
F_32 ( V_35 ) ;
error = F_33 ( V_35 , 0 ) ;
F_34 ( V_2 , 0 ) ;
F_34 ( V_3 , 1 ) ;
V_8:
F_35 ( V_38 ) ;
return error ;
V_52:
F_21 ( V_2 , V_49 | V_48 ) ;
F_21 ( V_3 , V_49 | V_48 ) ;
goto V_8;
V_71:
F_26 ( V_35 , 0 ) ;
goto V_52;
}
