static T_1
F_1 ( union V_1 * V_2 ,
T_2 V_3 )
{
T_1 V_4 = V_5 ;
union V_1 * V_6 ;
T_3 V_7 ;
F_2 ( V_8 , V_3 ) ;
V_6 = V_2 -> V_9 . V_10 ;
if ( V_6 -> V_11 . type != V_12 ) {
F_3 ( ( V_13 , L_1 ,
V_6 -> V_11 . type ,
F_4 ( V_6 ) ) ) ;
F_5 ( V_14 ) ;
}
V_7 = V_6 -> V_15 . V_7 ;
if ( ! F_6 ( V_7 ) ) {
F_3 ( ( V_13 ,
L_2 ,
V_7 ) ) ;
F_5 ( V_16 ) ;
}
if ( ! ( V_6 -> V_11 . V_17 & V_18 ) ) {
V_4 = F_7 ( V_6 ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
}
if ( V_6 -> V_11 . V_17 & V_19 ) {
F_5 ( V_20 ) ;
}
if ( V_7 == V_21 ||
V_7 == V_22 ||
V_7 == V_23 ) {
F_5 ( V_5 ) ;
}
#ifdef F_9
if ( ! ( V_2 -> V_11 . V_17 & V_18 ) ) {
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
}
#endif
if ( V_6 -> V_15 . V_24 <
( V_2 -> V_9 . V_25 + V_3 +
V_2 -> V_9 . V_26 ) ) {
if ( V_27 ) {
if ( F_10 ( V_6 -> V_15 . V_24 ,
V_2 -> V_9 .
V_26 ) >=
( ( V_28 ) V_2 -> V_9 .
V_25 +
V_2 -> V_9 . V_26 +
V_3 ) ) {
F_5 ( V_5 ) ;
}
}
if ( V_6 -> V_15 . V_24 <
V_2 -> V_9 . V_26 ) {
F_3 ( ( V_13 ,
L_3 ,
F_11 ( V_2 ->
V_9 . V_29 ) ,
V_2 -> V_9 . V_26 ,
F_11 ( V_6 -> V_15 .
V_29 ) ,
V_6 -> V_15 . V_24 ) ) ;
}
F_3 ( ( V_13 ,
L_4 ,
F_11 ( V_2 -> V_9 . V_29 ) ,
V_2 -> V_9 . V_25 ,
V_3 ,
V_2 -> V_9 . V_26 ,
F_11 ( V_6 -> V_15 . V_29 ) ,
V_6 -> V_15 . V_24 ) ) ;
F_5 ( V_30 ) ;
}
F_5 ( V_5 ) ;
}
T_1
F_12 ( union V_1 * V_2 ,
T_2 V_3 , T_4 * V_31 , T_2 V_32 )
{
T_1 V_4 ;
union V_1 * V_6 ;
T_2 V_33 ;
F_13 ( V_34 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
V_6 = V_2 -> V_9 . V_10 ;
V_33 =
V_2 -> V_9 . V_25 + V_3 ;
if ( ( V_32 & V_35 ) == V_36 ) {
F_14 ( ( V_37 , L_5 ) ) ;
} else {
F_14 ( ( V_37 , L_6 ) ) ;
}
F_15 ( ( V_37 ,
L_7 ,
F_16 ( V_6 -> V_15 .
V_7 ) ,
V_6 -> V_15 . V_7 ,
V_2 -> V_9 . V_26 ,
V_2 -> V_9 . V_25 ,
V_3 , F_17 ( void ,
( V_6 ->
V_15 .
V_38 +
V_33 ) ) ) ) ;
V_4 = F_18 ( V_6 , V_2 ,
V_32 , V_33 ,
F_19 ( V_2 ->
V_9 .
V_26 ) ,
V_31 ) ;
if ( F_8 ( V_4 ) ) {
if ( V_4 == V_39 ) {
F_3 ( ( V_13 ,
L_8 ,
F_16 ( V_6 -> V_15 .
V_7 ) ,
V_6 -> V_15 . V_7 ) ) ;
} else if ( V_4 == V_40 ) {
F_3 ( ( V_13 ,
L_9 ,
F_16 ( V_6 -> V_15 .
V_7 ) ,
V_6 -> V_15 . V_7 ) ) ;
}
}
F_5 ( V_4 ) ;
}
static T_3
F_20 ( union V_1 * V_2 , T_4 V_31 )
{
F_21 ( V_41 ) ;
if ( V_2 -> V_9 . V_42 >= V_43 ) {
return ( FALSE ) ;
}
if ( V_31 >= ( ( T_4 ) 1 << V_2 -> V_9 . V_42 ) ) {
F_3 ( ( V_13 ,
L_10 ,
F_22 ( V_31 ) ,
V_2 -> V_9 . V_42 ) ) ;
return ( TRUE ) ;
}
return ( FALSE ) ;
}
static T_1
F_23 ( union V_1 * V_2 ,
T_2 V_3 , T_4 * V_31 , T_2 V_44 )
{
T_1 V_4 ;
T_4 V_45 ;
F_2 ( V_46 , V_3 ) ;
if ( V_44 == V_36 ) {
if ( ! V_31 ) {
V_45 = 0 ;
V_31 = & V_45 ;
}
* V_31 = 0 ;
}
switch ( V_2 -> V_11 . type ) {
case V_47 :
if ( ! ( V_2 -> V_11 . V_17 & V_18 ) ) {
V_4 = F_24 ( V_2 ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
}
if ( V_44 == V_36 ) {
F_25 ( V_31 ,
( V_2 -> V_48 . V_49 ) -> V_50 .
V_51 +
V_2 -> V_48 . V_25 +
V_3 ,
V_2 -> V_9 . V_26 ) ;
} else {
F_25 ( ( V_2 -> V_48 . V_49 ) -> V_50 .
V_51 +
V_2 -> V_48 . V_25 +
V_3 , V_31 ,
V_2 -> V_9 . V_26 ) ;
}
V_4 = V_5 ;
break;
case V_52 :
if ( F_20 ( V_2 -> V_53 . V_54 ,
( T_4 ) V_2 -> V_53 .
V_31 ) ) {
F_5 ( V_55 ) ;
}
V_4 =
F_26 ( V_2 -> V_53 . V_54 ,
& V_2 -> V_53 . V_31 ,
sizeof( V_2 -> V_53 .
V_31 ) ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
case V_56 :
V_4 =
F_12 ( V_2 , V_3 ,
V_31 , V_44 ) ;
break;
case V_57 :
if ( F_20 ( V_2 -> V_58 . V_59 ,
( T_4 ) V_2 -> V_58 .
V_31 ) ) {
F_5 ( V_55 ) ;
}
V_3 += V_2 -> V_58 . V_31 ;
F_14 ( ( V_37 ,
L_11 ,
V_3 ) ) ;
V_4 =
F_26 ( V_2 -> V_58 . V_59 ,
& V_3 ,
sizeof( V_3 ) ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
if ( V_44 == V_36 ) {
F_14 ( ( V_37 ,
L_12 ) ) ;
V_4 =
F_27 ( V_2 -> V_58 .
V_60 , V_31 ,
sizeof( T_4 ) ) ;
} else {
F_14 ( ( V_37 ,
L_13 ,
F_22 ( * V_31 ) ) ) ;
V_4 =
F_26 ( V_2 -> V_58 .
V_60 , V_31 ,
sizeof( T_4 ) ) ;
}
break;
default:
F_3 ( ( V_13 , L_14 ,
V_2 -> V_11 . type ) ) ;
V_4 = V_61 ;
break;
}
if ( F_28 ( V_4 ) ) {
if ( V_44 == V_36 ) {
F_14 ( ( V_37 ,
L_15 ,
F_22 ( * V_31 ) ,
V_2 -> V_9 .
V_26 ) ) ;
} else {
F_14 ( ( V_37 ,
L_16 ,
F_22 ( * V_31 ) ,
V_2 -> V_9 .
V_26 ) ) ;
}
}
F_5 ( V_4 ) ;
}
T_1
F_29 ( union V_1 * V_2 ,
T_4 V_62 ,
T_4 V_63 , T_2 V_3 )
{
T_1 V_4 = V_5 ;
T_4 V_64 ;
T_4 V_65 ;
F_2 ( V_66 , V_62 ) ;
V_64 = V_63 ;
if ( V_62 != V_67 ) {
switch ( V_2 -> V_9 .
V_68 & V_69 ) {
case V_70 :
if ( ( ~ V_62 << ( F_19 ( sizeof( V_62 ) ) -
F_19 ( V_2 -> V_9 .
V_26 ) ) ) != 0 ) {
V_4 =
F_23 ( V_2 ,
V_3 ,
& V_65 ,
V_36 ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
V_64 |= ( V_65 & ~ V_62 ) ;
}
break;
case V_71 :
V_64 |= ~ V_62 ;
break;
case V_72 :
V_64 &= V_62 ;
break;
default:
F_3 ( ( V_13 ,
L_17 ,
( V_2 -> V_9 .
V_68 &
V_69 ) ) ) ;
F_5 ( V_73 ) ;
}
}
F_14 ( ( V_37 ,
L_18 ,
F_22 ( V_62 ) ,
V_3 ,
V_2 -> V_9 . V_26 ,
F_22 ( V_63 ) ,
F_22 ( V_64 ) ) ) ;
V_4 = F_23 ( V_2 , V_3 ,
& V_64 , V_74 ) ;
F_5 ( V_4 ) ;
}
T_1
F_27 ( union V_1 * V_2 ,
void * V_50 , T_2 V_75 )
{
T_1 V_4 ;
T_4 V_76 ;
T_4 V_77 ;
T_2 V_78 = 0 ;
T_2 V_79 = 0 ;
T_2 V_80 ;
T_2 V_81 ;
T_2 V_82 ;
T_2 V_83 ;
T_2 V_84 ;
F_13 ( V_85 ) ;
if ( V_75 <
F_30 ( V_2 -> V_9 . V_42 ) ) {
F_3 ( ( V_13 ,
L_19 ,
V_2 -> V_9 . V_42 , V_75 ) ) ;
F_5 ( V_86 ) ;
}
F_31 ( V_50 , 0 , V_75 ) ;
V_83 = F_19 ( V_2 -> V_9 . V_26 ) ;
if ( ( V_2 -> V_9 . V_87 == 0 ) &&
( V_2 -> V_9 . V_42 == V_83 ) ) {
V_4 = F_23 ( V_2 , 0 , V_50 , V_36 ) ;
F_5 ( V_4 ) ;
}
if ( V_2 -> V_9 . V_26 > sizeof( T_4 ) ) {
V_2 -> V_9 . V_26 = sizeof( T_4 ) ;
V_83 = sizeof( T_4 ) * 8 ;
}
V_81 =
F_32 ( V_2 -> V_9 . V_42 ,
V_83 ) ;
V_82 = F_32 ( V_2 -> V_9 . V_42 +
V_2 -> V_9 .
V_87 ,
V_83 ) ;
V_4 =
F_23 ( V_2 , V_78 , & V_76 ,
V_36 ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
V_77 =
V_76 >> V_2 -> V_9 . V_87 ;
for ( V_84 = 1 ; V_84 < V_82 ; V_84 ++ ) {
V_78 += V_2 -> V_9 . V_26 ;
V_4 = F_23 ( V_2 , V_78 ,
& V_76 , V_36 ) ;
if ( F_8 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
if ( V_83 -
V_2 -> V_9 . V_87 <
V_43 ) {
V_77 |=
V_76 << ( V_83 -
V_2 -> V_9 .
V_87 ) ;
}
if ( V_84 == V_81 ) {
break;
}
F_25 ( ( ( char * ) V_50 ) + V_79 , & V_77 ,
F_33 ( V_2 -> V_9 . V_26 ,
V_75 - V_79 ) ) ;
V_79 += V_2 -> V_9 . V_26 ;
V_77 =
V_76 >> V_2 -> V_9 . V_87 ;
}
V_80 = V_2 -> V_9 . V_42 % V_83 ;
if ( V_80 ) {
V_77 &= F_34 ( V_80 ) ;
}
F_25 ( ( ( char * ) V_50 ) + V_79 , & V_77 ,
F_33 ( V_2 -> V_9 . V_26 ,
V_75 - V_79 ) ) ;
F_5 ( V_5 ) ;
}
T_1
F_26 ( union V_1 * V_2 ,
void * V_50 , T_2 V_75 )
{
void * V_88 ;
T_1 V_4 ;
T_4 V_62 ;
T_4 V_89 ;
T_4 V_77 ;
T_4 V_76 = 0 ;
T_2 V_78 = 0 ;
T_2 V_79 = 0 ;
T_2 V_80 ;
T_2 V_81 ;
T_2 V_82 ;
T_2 V_83 ;
T_2 V_90 ;
T_2 V_84 ;
F_13 ( V_91 ) ;
V_88 = NULL ;
V_90 =
F_30 ( V_2 -> V_9 . V_42 ) ;
if ( V_75 < V_90 ) {
V_88 = F_35 ( V_90 ) ;
if ( ! V_88 ) {
F_5 ( V_92 ) ;
}
F_25 ( ( char * ) V_88 , ( char * ) V_50 , V_75 ) ;
V_50 = V_88 ;
V_75 = V_90 ;
}
if ( V_2 -> V_9 . V_26 > sizeof( T_4 ) ) {
V_2 -> V_9 . V_26 = sizeof( T_4 ) ;
}
V_83 = F_19 ( V_2 -> V_9 . V_26 ) ;
if ( V_83 == V_43 ) {
V_89 = V_67 ;
} else {
V_89 = F_34 ( V_83 ) ;
}
V_62 = V_89 &
F_36 ( V_2 -> V_9 . V_87 ) ;
V_81 = F_32 ( V_2 -> V_9 . V_42 ,
V_83 ) ;
V_82 = F_32 ( V_2 -> V_9 . V_42 +
V_2 -> V_9 .
V_87 ,
V_83 ) ;
F_25 ( & V_76 , V_50 ,
F_33 ( V_2 -> V_9 . V_26 ,
V_75 - V_79 ) ) ;
V_77 =
V_76 << V_2 -> V_9 . V_87 ;
for ( V_84 = 1 ; V_84 < V_82 ; V_84 ++ ) {
V_77 &= V_62 ;
V_4 = F_29 ( V_2 , V_62 ,
V_77 ,
V_78 ) ;
if ( F_8 ( V_4 ) ) {
goto exit;
}
V_78 += V_2 -> V_9 . V_26 ;
if ( ( V_83 -
V_2 -> V_9 . V_87 ) <
V_43 ) {
V_77 =
V_76 >> ( V_83 -
V_2 -> V_9 .
V_87 ) ;
} else {
V_77 = 0 ;
}
V_62 = V_89 ;
if ( V_84 == V_81 ) {
break;
}
V_79 += V_2 -> V_9 . V_26 ;
F_25 ( & V_76 , ( ( char * ) V_50 ) + V_79 ,
F_33 ( V_2 -> V_9 . V_26 ,
V_75 - V_79 ) ) ;
V_77 |=
V_76 << V_2 -> V_9 . V_87 ;
}
V_80 = ( V_2 -> V_9 . V_42 +
V_2 -> V_9 . V_87 ) %
V_83 ;
if ( V_80 ) {
V_62 &= F_34 ( V_80 ) ;
}
V_77 &= V_62 ;
V_4 = F_29 ( V_2 ,
V_62 , V_77 ,
V_78 ) ;
exit:
if ( V_88 ) {
F_37 ( V_88 ) ;
}
F_5 ( V_4 ) ;
}
