static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
F_2 () ;
for ( V_2 = 0 ; V_1 ; V_2 ++ ) {
V_1 &= ( T_2 ) ( V_1 - 1 ) ;
}
return V_2 ;
}
static T_3
F_3 ( struct V_3 * V_4 )
{
F_2 () ;
if ( V_4 -> V_5 ) {
return ( ( T_3 ) ( V_4 -> V_6 + 1 ) ) ;
}
return ( 0 ) ;
}
static T_4
F_4 ( T_4 V_7 ,
T_4 V_8 )
{
T_4 V_6 = 0 ;
F_2 () ;
if ( V_7 > V_8 ) {
V_6 =
V_7 - V_8 - 1 ;
}
return ( ( T_4 ) F_5 ( V_6 ) ) ;
}
T_5
F_6 ( struct V_9 * V_10 , T_6 * V_11 )
{
T_6 V_12 = 0 ;
T_3 V_13 ;
F_7 ( V_14 ) ;
while ( V_10 ) {
if ( V_10 -> type > V_15 ) {
F_8 ( V_16 ) ;
}
V_13 = V_17 [ V_10 -> type ] ;
switch ( V_10 -> type ) {
case V_18 :
if ( V_10 -> V_19 . V_20 . V_21 == 2 ) {
V_13 -- ;
}
break;
case V_22 :
if ( V_10 -> V_19 . V_20 . V_21 == 0 ) {
V_13 -- ;
}
break;
case V_23 :
if ( V_10 -> V_19 . V_24 . V_25 > 7 ) {
V_13 =
sizeof( struct V_26 ) ;
}
V_13 = ( T_3 )
( V_13 + V_10 -> V_19 . V_24 . V_25 ) ;
break;
case V_27 :
* V_11 = V_12 + V_13 ;
F_8 ( V_28 ) ;
case V_29 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_19 .
V_30 .
V_4 ) ) ;
break;
case V_31 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_19 .
V_32 .
V_4 ) ) ;
break;
case V_33 :
V_13 = ( T_3 )
( V_13 +
F_3 ( & V_10 -> V_19 .
V_34 .
V_4 ) ) ;
break;
case V_35 :
V_13 = ( T_3 )
( V_13 +
( ( V_10 -> V_19 . V_36 . V_37 -
1 ) * 4 ) +
F_3 ( & V_10 -> V_19 .
V_36 .
V_4 ) ) ;
break;
default:
break;
}
V_12 += V_13 ;
V_10 =
F_9 ( struct V_9 , V_10 ,
V_10 -> V_38 ) ;
}
F_8 ( V_39 ) ;
}
T_5
F_10 ( T_1 * V_40 ,
T_4 V_41 , T_6 * V_11 )
{
T_5 V_42 ;
T_1 * V_43 ;
T_1 * V_44 ;
T_4 V_45 ;
T_2 V_46 ;
T_2 V_7 ;
T_4 V_47 ;
T_1 V_48 ;
T_1 V_8 ;
F_7 ( V_49 ) ;
* V_11 = 0 ;
V_43 = V_40 + V_41 ;
while ( V_40 < V_43 ) {
V_42 = F_11 ( V_40 , & V_48 ) ;
if ( F_12 ( V_42 ) ) {
F_8 ( V_42 ) ;
}
V_7 = F_13 ( V_40 ) ;
V_8 =
V_50 [ V_48 ] ;
V_47 = 0 ;
V_44 =
V_40 + F_14 ( V_40 ) ;
switch ( F_15 ( V_40 ) ) {
case V_51 :
F_16 ( & V_46 , V_44 ) ;
V_47 = F_1 ( V_46 ) ;
break;
case V_52 :
V_47 = F_1 ( * V_44 ) ;
break;
case V_53 :
case V_54 :
V_47 = V_7 ;
break;
case V_55 :
* V_11 += V_56 ;
F_8 ( V_28 ) ;
case V_57 :
case V_58 :
case V_59 :
V_47 =
F_4 ( V_7 ,
V_8 ) ;
break;
case V_60 :
V_47 = ( V_44 [ 1 ] - 1 ) * sizeof( T_4 ) ;
V_47 +=
F_4 ( V_7 -
V_47 ,
V_8 ) ;
break;
default:
break;
}
V_45 = V_61 [ V_48 ] +
V_47 ;
V_45 = ( T_4 ) F_5 ( V_45 ) ;
* V_11 += V_45 ;
F_17 ( ( V_62 ,
L_1 ,
F_15 ( V_40 ) ,
F_18 ( V_40 ) ,
V_45 ) ) ;
V_40 += F_18 ( V_40 ) ;
}
F_8 ( V_39 ) ;
}
T_5
F_19 ( union V_63 * V_64 ,
T_6 * V_65 )
{
T_4 V_66 ;
T_6 V_67 = 0 ;
union V_63 * * V_68 ;
T_4 V_69 ;
union V_63 * V_70 ;
union V_63 * * V_71 ;
T_1 V_72 ;
T_4 V_73 ;
F_7 ( V_74 ) ;
V_66 = V_64 -> V_75 . V_76 ;
V_68 = V_64 -> V_75 . V_77 ;
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
V_70 = * V_68 ;
if ( ! V_70 ||
( V_70 -> V_78 . type != V_79 ) ) {
F_8 ( V_80 ) ;
}
V_71 = V_70 -> V_75 . V_77 ;
V_72 = FALSE ;
for ( V_73 = 0 ; V_73 < 4 && ! V_72 ;
V_73 ++ ) {
if ( * V_71 &&
( ( V_81 ==
( * V_71 ) -> V_78 . type ) ||
( ( V_82 ==
( * V_71 ) -> V_78 . type ) &&
( ( * V_71 ) -> V_83 . V_84 ==
V_85 ) ) ) ) {
V_72 = TRUE ;
} else {
V_71 ++ ;
}
}
V_67 += ( sizeof( struct V_86 ) - 4 ) ;
if ( V_72 ) {
if ( ( * V_71 ) -> V_78 . type == V_81 ) {
V_67 += ( ( T_6 )
( * V_71 ) -> string .
V_38 + 1 ) ;
} else {
V_67 +=
F_20 ( ( * V_71 ) -> V_83 . V_87 ) ;
}
} else {
V_67 += sizeof( T_4 ) ;
}
V_67 = F_21 ( V_67 ) ;
V_68 ++ ;
}
* V_65 =
V_67 + sizeof( struct V_86 ) ;
F_8 ( V_28 ) ;
}
