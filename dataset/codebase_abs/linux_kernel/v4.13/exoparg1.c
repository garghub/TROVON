T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
union V_5 * V_6 = NULL ;
F_2 ( V_7 ,
F_3 ( V_2 -> V_8 ) ) ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_6 =
F_4 ( F_5 () ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
break;
default:
F_6 ( ( V_12 , L_1 ,
V_2 -> V_8 ) ) ;
V_3 = V_13 ;
break;
}
V_11:
if ( ( F_7 ( V_3 ) ) || V_2 -> V_14 ) {
F_8 ( V_6 ) ;
V_2 -> V_14 = NULL ;
} else {
V_2 -> V_14 = V_6 ;
}
F_9 ( V_3 ) ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
union V_5 * * V_15 = & V_2 -> V_16 [ 0 ] ;
T_1 V_3 = V_4 ;
F_2 ( V_17 ,
F_3 ( V_2 -> V_8 ) ) ;
switch ( V_2 -> V_8 ) {
case V_18 :
V_3 = F_11 ( V_15 [ 0 ] , V_2 ) ;
break;
case V_19 :
V_3 = F_12 ( V_15 [ 0 ] ) ;
break;
case V_20 :
V_3 = F_13 ( V_15 [ 0 ] ) ;
break;
case V_21 :
V_3 = F_14 ( V_15 [ 0 ] -> integer . V_22 ) ;
break;
case V_23 :
V_3 =
F_15 ( ( V_24 ) V_15 [ 0 ] -> integer . V_22 ) ;
break;
case V_25 :
V_3 = F_16 ( V_15 [ 0 ] ) ;
break;
default:
F_6 ( ( V_12 , L_1 ,
V_2 -> V_8 ) ) ;
V_3 = V_13 ;
break;
}
F_9 ( V_3 ) ;
}
T_1 F_17 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
union V_5 * * V_15 = & V_2 -> V_16 [ 0 ] ;
F_2 ( V_26 ,
F_3 ( V_2 -> V_8 ) ) ;
switch ( V_2 -> V_8 ) {
case V_27 :
V_3 = F_18 ( V_15 [ 0 ] , V_15 [ 1 ] , V_2 ) ;
break;
default:
F_6 ( ( V_12 , L_1 ,
V_2 -> V_8 ) ) ;
V_3 = V_13 ;
goto V_11;
}
V_11:
F_9 ( V_3 ) ;
}
T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
union V_5 * * V_15 = & V_2 -> V_16 [ 0 ] ;
union V_5 * V_6 = NULL ;
union V_5 * V_28 = NULL ;
V_24 V_29 ;
V_24 V_30 ;
T_2 V_31 ;
T_2 V_32 ;
F_2 ( V_33 ,
F_3 ( V_2 -> V_8 ) ) ;
switch ( V_2 -> V_8 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_6 = F_20 ( V_40 ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
switch ( V_2 -> V_8 ) {
case V_34 :
V_6 -> integer . V_22 = ~ V_15 [ 0 ] -> integer . V_22 ;
break;
case V_35 :
V_6 -> integer . V_22 = V_15 [ 0 ] -> integer . V_22 ;
for ( V_29 = 0 ; V_6 -> integer . V_22 &&
V_29 < V_41 ; ++ V_29 ) {
V_6 -> integer . V_22 >>= 1 ;
}
V_6 -> integer . V_22 = V_29 ;
break;
case V_36 :
V_6 -> integer . V_22 = V_15 [ 0 ] -> integer . V_22 ;
for ( V_29 = 0 ; V_6 -> integer . V_22 &&
V_29 < V_41 ; ++ V_29 ) {
V_6 -> integer . V_22 <<= 1 ;
}
V_6 -> integer . V_22 =
V_29 ==
0 ? 0 : ( V_41 + 1 ) - V_29 ;
break;
case V_37 :
V_31 = 1 ;
V_6 -> integer . V_22 = 0 ;
V_32 = V_15 [ 0 ] -> integer . V_22 ;
for ( V_30 = 0 ;
( V_30 < V_42 ) && ( V_32 > 0 ) ;
V_30 ++ ) {
V_29 = ( ( V_24 ) V_32 ) & 0xF ;
if ( V_29 > 9 ) {
F_6 ( ( V_12 ,
L_2 ,
V_29 ) ) ;
V_3 = V_43 ;
goto V_11;
}
V_6 -> integer . V_22 +=
( ( ( T_2 ) V_29 ) * V_31 ) ;
V_32 >>= 4 ;
V_31 *= 10 ;
}
break;
case V_38 :
V_6 -> integer . V_22 = 0 ;
V_32 = V_15 [ 0 ] -> integer . V_22 ;
for ( V_30 = 0 ;
( V_30 < V_42 ) && ( V_32 > 0 ) ;
V_30 ++ ) {
( void ) F_21 ( V_32 , 10 , & V_32 ,
& V_29 ) ;
V_6 -> integer . V_22 |=
( ( ( T_2 ) V_29 ) << F_22 ( V_30 ) ) ;
}
if ( V_32 > 0 ) {
F_6 ( ( V_12 ,
L_3 ,
F_23 ( V_15 [ 0 ] ->
integer . V_22 ) ) ) ;
V_3 = V_43 ;
goto V_11;
}
break;
case V_39 :
if ( (struct V_44 * ) V_15 [ 0 ] ==
V_45 ) {
V_6 -> integer . V_22 = 0 ;
goto V_11;
}
V_3 = F_24 ( V_15 [ 0 ] ,
& V_28 ,
V_2 ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
V_3 =
F_25 ( V_28 , V_15 [ 1 ] , V_2 ) ;
F_8 ( V_28 ) ;
V_6 -> integer . V_22 = V_46 ;
goto V_11;
default:
break;
}
break;
case V_47 :
V_3 = F_25 ( V_15 [ 0 ] , V_15 [ 1 ] , V_2 ) ;
if ( F_7 ( V_3 ) ) {
F_9 ( V_3 ) ;
}
if ( ! V_2 -> V_14 ) {
V_2 -> V_14 = V_15 [ 0 ] ;
V_2 -> V_16 [ 0 ] = NULL ;
}
F_9 ( V_3 ) ;
case V_48 :
V_3 =
F_26 ( V_15 [ 0 ] , & V_6 ,
V_2 ) ;
break;
case V_49 :
V_3 =
F_27 ( V_15 [ 0 ] , & V_6 ,
V_50 ) ;
if ( V_6 == V_15 [ 0 ] ) {
F_28 ( V_6 ) ;
}
break;
case V_51 :
V_3 =
F_27 ( V_15 [ 0 ] , & V_6 ,
V_52 ) ;
if ( V_6 == V_15 [ 0 ] ) {
F_28 ( V_6 ) ;
}
break;
case V_53 :
V_3 = F_29 ( V_15 [ 0 ] , & V_6 ) ;
if ( V_6 == V_15 [ 0 ] ) {
F_28 ( V_6 ) ;
}
break;
case V_54 :
V_3 =
F_30 ( V_15 [ 0 ] , & V_6 , 0 ) ;
if ( V_6 == V_15 [ 0 ] ) {
F_28 ( V_6 ) ;
}
break;
case V_55 :
case V_56 :
F_6 ( ( V_12 ,
L_4 ,
F_3 ( V_2 -> V_8 ) ) ) ;
V_3 = V_57 ;
goto V_11;
default:
F_6 ( ( V_12 , L_1 ,
V_2 -> V_8 ) ) ;
V_3 = V_13 ;
goto V_11;
}
if ( F_31 ( V_3 ) ) {
V_3 = F_25 ( V_6 , V_15 [ 1 ] , V_2 ) ;
}
V_11:
if ( F_7 ( V_3 ) ) {
F_8 ( V_6 ) ;
}
else if ( ! V_2 -> V_14 ) {
V_2 -> V_14 = V_6 ;
}
F_9 ( V_3 ) ;
}
T_1 F_32 ( struct V_1 * V_2 )
{
union V_5 * * V_15 = & V_2 -> V_16 [ 0 ] ;
union V_5 * V_58 ;
union V_5 * V_6 = NULL ;
T_1 V_3 = V_4 ;
V_24 type ;
T_2 V_22 ;
F_2 ( V_59 ,
F_3 ( V_2 -> V_8 ) ) ;
switch ( V_2 -> V_8 ) {
case V_60 :
V_6 = F_4 ( ( T_2 ) 0 ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
if ( ! V_15 [ 0 ] -> integer . V_22 ) {
V_6 -> integer . V_22 = V_46 ;
}
break;
case V_61 :
case V_62 :
V_6 = F_20 ( V_40 ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
V_58 = V_15 [ 0 ] ;
if ( F_33 ( V_58 ) ==
V_63 ) {
F_28 ( V_58 ) ;
}
V_3 = F_34 ( V_60 ,
& V_58 , V_2 ) ;
if ( F_7 ( V_3 ) ) {
F_35 ( ( V_12 , V_3 ,
L_5 ,
F_3 ( V_2 ->
V_8 ) ) ) ;
goto V_11;
}
if ( V_2 -> V_8 == V_62 ) {
V_6 -> integer . V_22 =
V_58 -> integer . V_22 + 1 ;
} else {
V_6 -> integer . V_22 =
V_58 -> integer . V_22 - 1 ;
}
F_8 ( V_58 ) ;
V_3 = F_25 ( V_6 , V_15 [ 0 ] , V_2 ) ;
break;
case V_64 :
V_3 =
F_36 ( V_2 , V_15 [ 0 ] , & type ,
NULL ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
V_6 = F_4 ( ( T_2 ) type ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
break;
case V_65 :
V_3 =
F_36 ( V_2 , V_15 [ 0 ] , & type ,
& V_58 ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
switch ( type ) {
case V_40 :
V_22 = V_66 ;
break;
case V_67 :
V_22 = V_58 -> string . V_68 ;
break;
case V_69 :
V_3 = F_37 ( V_58 ) ;
V_22 = V_58 -> V_70 . V_68 ;
break;
case V_71 :
V_3 = F_38 ( V_58 ) ;
V_22 = V_58 -> V_72 . V_73 ;
break;
default:
F_6 ( ( V_12 ,
L_6
L_7 ,
F_39 ( type ) ) ) ;
V_3 = V_74 ;
goto V_11;
}
if ( F_7 ( V_3 ) ) {
goto V_11;
}
V_6 = F_4 ( V_22 ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
break;
case V_75 :
V_3 =
F_24 ( V_15 [ 0 ] , & V_6 ,
V_2 ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
break;
case V_76 :
if ( F_33 ( V_15 [ 0 ] ) ==
V_77 ) {
V_58 =
F_40 ( (struct
V_44 * )
V_15 [ 0 ] ) ;
if ( V_58
&& ( ( V_58 -> V_78 . type == V_67 )
|| ( V_58 -> V_78 . type ==
V_79 ) ) ) {
V_15 [ 0 ] = V_58 ;
F_28 ( V_58 ) ;
} else {
V_3 = V_74 ;
goto V_11;
}
} else {
switch ( ( V_15 [ 0 ] ) -> V_78 . type ) {
case V_79 :
switch ( V_15 [ 0 ] -> V_80 . V_81 ) {
case V_82 :
case V_83 :
V_3 =
F_41
( V_15 [ 0 ] -> V_80 . V_81 ,
V_15 [ 0 ] -> V_80 . V_22 ,
V_2 , & V_58 ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
F_8 ( V_15 [ 0 ] ) ;
V_15 [ 0 ] = V_58 ;
break;
case V_84 :
V_58 =
V_15 [ 0 ] -> V_80 . V_85 ;
F_8 ( V_15 [ 0 ] ) ;
V_15 [ 0 ] = V_58 ;
break;
default:
break;
}
break;
case V_67 :
break;
default:
V_3 = V_74 ;
goto V_11;
}
}
if ( F_33 ( V_15 [ 0 ] ) !=
V_77 ) {
if ( ( V_15 [ 0 ] ) -> V_78 . type == V_67 ) {
V_3 =
F_42 ( V_2 ->
V_86 -> V_87 .
V_88 ,
V_15 [ 0 ] ->
string . V_89 ,
V_90 ,
F_43
( struct
V_44 ,
& V_6 ) ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
V_3 =
F_44
( F_43
( struct V_44 , & V_6 ) ,
V_2 ) ;
goto V_11;
}
}
if ( F_33 ( V_15 [ 0 ] ) ==
V_77 ) {
switch ( ( (struct V_44 * ) V_15 [ 0 ] ) ->
type ) {
case V_91 :
case V_92 :
V_6 = V_15 [ 0 ] ;
break;
default:
V_6 = F_40 ( (struct V_44 * ) V_15 [ 0 ] ) ;
F_28 ( V_6 ) ;
break;
}
} else {
switch ( V_15 [ 0 ] -> V_80 . V_81 ) {
case V_93 :
switch ( V_15 [ 0 ] -> V_80 . V_94 ) {
case V_95 :
V_58 =
V_15 [ 0 ] -> V_80 . V_85 ;
V_6 =
F_4 ( ( T_2 )
V_58 -> V_70 . V_89 [ V_15 [ 0 ] -> V_80 . V_22 ] ) ;
if ( ! V_6 ) {
V_3 = V_10 ;
goto V_11;
}
break;
case V_71 :
V_6 =
* ( V_15 [ 0 ] -> V_80 . V_96 ) ;
if ( ! V_6 ) {
F_9
( V_97 ) ;
}
F_28 ( V_6 ) ;
break;
default:
F_6 ( ( V_12 ,
L_8 ,
V_15 [ 0 ] -> V_80 .
V_94 , V_15 [ 0 ] ) ) ;
V_3 = V_74 ;
goto V_11;
}
break;
case V_84 :
V_6 = V_15 [ 0 ] -> V_80 . V_85 ;
if ( F_33 ( V_6 ) ==
V_77 ) {
V_6 =
F_40 ( (struct
V_44
* )
V_6 ) ;
if ( ! V_6 ) {
break;
}
switch ( V_6 -> V_78 . type ) {
case V_95 :
case V_98 :
case V_99 :
case V_100 :
V_3 =
F_45
( V_2 , V_6 ,
& V_58 ) ;
if ( F_7 ( V_3 ) ) {
goto V_11;
}
V_6 = V_58 ;
break;
default:
F_28
( V_6 ) ;
break;
}
}
break;
default:
F_6 ( ( V_12 ,
L_9 ,
V_15 [ 0 ] ,
V_15 [ 0 ] -> V_80 . V_81 ) ) ;
V_3 = V_101 ;
goto V_11;
}
}
break;
default:
F_6 ( ( V_12 , L_1 ,
V_2 -> V_8 ) ) ;
V_3 = V_13 ;
goto V_11;
}
V_11:
if ( F_7 ( V_3 ) ) {
F_8 ( V_6 ) ;
}
else {
V_2 -> V_14 = V_6 ;
}
F_9 ( V_3 ) ;
}
