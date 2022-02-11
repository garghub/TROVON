static T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 ;
T_1 V_8 ;
T_2 type ;
F_2 ( V_9 ) ;
* V_6 = NULL ;
if ( V_4 -> V_10 . V_11 == V_12 ) {
if ( ! V_4 -> V_10 . V_13 ) {
V_8 = F_3 ( V_2 -> V_14 ,
V_4 -> V_10 . V_15 . string ,
V_16 ,
V_17 ,
V_18 |
V_19 , NULL ,
F_4 ( struct
V_20 ,
& ( V_4 ->
V_10 .
V_13 ) ) ) ;
if ( F_5 ( V_8 ) ) {
if ( ( V_8 == V_21 )
&& ( V_22 )
&&
( ( V_4 -> V_10 . V_23 -> V_10 . V_11 ==
V_24 )
|| ( V_4 -> V_10 . V_23 -> V_10 . V_11 ==
V_25 ) ) ) {
F_6 ( ( V_26 ,
L_1 ,
V_2 ->
V_14 -> V_27 .
V_13 -> V_28 . V_29 ) ) ;
F_7 ( V_30 ) ;
} else {
F_8 ( V_4 -> V_10 . V_15 .
string , V_8 ) ;
}
F_7 ( V_8 ) ;
}
}
if ( ( V_4 -> V_10 . V_23 -> V_10 . V_11 == V_24 ) ||
( V_4 -> V_10 . V_23 -> V_10 . V_11 ==
V_25 ) ) {
V_7 =
F_9 ( union V_5 ,
V_4 -> V_10 . V_13 ) ;
V_8 =
F_10 ( F_4
( struct
V_20 ,
& V_7 ) ,
V_2 ) ;
if ( F_5 ( V_8 ) ) {
F_7 ( V_8 ) ;
}
type = V_4 -> V_10 . V_13 -> type ;
if ( type == V_31 ) {
type = V_7 -> V_10 . type ;
V_4 -> V_10 . V_13 =
F_9 ( struct V_20 ,
V_4 -> V_10 . V_13 -> V_32 ) ;
}
switch ( type ) {
case V_33 :
case V_34 :
F_11 ( V_4 -> V_10 . V_13 -> V_32 ) ;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
break;
default:
goto exit;
}
}
}
V_7 = F_12 ( ( F_13
( V_4 -> V_10 . V_11 ) ) ->
V_41 ) ;
if ( ! V_7 ) {
F_7 ( V_42 ) ;
}
V_8 =
F_14 ( V_2 , V_4 , V_4 -> V_10 . V_11 ,
& V_7 ) ;
if ( F_5 ( V_8 ) ) {
F_15 ( V_7 ) ;
F_7 ( V_8 ) ;
}
exit:
* V_6 = V_7 ;
F_7 ( V_8 ) ;
}
T_1
F_16 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_3 V_43 ,
union V_5 * * V_6 )
{
union V_3 * V_44 ;
union V_5 * V_7 ;
union V_3 * V_45 ;
T_3 V_46 = 0 ;
F_2 ( V_47 ) ;
V_7 = * V_6 ;
if ( ! V_7 ) {
V_7 = F_12 ( V_48 ) ;
* V_6 = V_7 ;
if ( ! V_7 ) {
F_7 ( V_42 ) ;
}
}
V_44 = V_4 -> V_10 . V_15 . V_44 ;
V_45 = V_44 -> V_49 . V_50 ;
if ( V_45 ) {
if ( V_45 -> V_10 . V_11 != V_51 ) {
F_17 ( ( V_52 ,
L_2 ,
V_45 -> V_10 . V_11 , V_45 ) ) ;
F_15 ( V_7 ) ;
return ( V_53 ) ;
}
V_46 = ( T_3 ) V_45 -> V_10 . V_15 . integer ;
}
V_7 -> V_54 . V_55 = V_43 ;
if ( V_46 > V_43 ) {
V_7 -> V_54 . V_55 = V_46 ;
}
if ( V_7 -> V_54 . V_55 == 0 ) {
V_7 -> V_54 . V_56 = NULL ;
F_6 ( ( V_57 ,
L_3 ) ) ;
} else {
V_7 -> V_54 . V_56 =
F_18 ( V_7 -> V_54 . V_55 ) ;
if ( ! V_7 -> V_54 . V_56 ) {
F_19 ( V_7 ) ;
F_7 ( V_42 ) ;
}
if ( V_45 ) {
memcpy ( V_7 -> V_54 . V_56 , V_45 -> V_49 . V_58 ,
V_46 ) ;
}
}
V_7 -> V_54 . V_59 |= V_60 ;
V_4 -> V_10 . V_13 = F_9 ( struct V_20 , V_7 ) ;
F_7 ( V_30 ) ;
}
T_1
F_20 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_3 V_61 ,
union V_5 * * V_6 )
{
union V_3 * V_44 ;
union V_3 * V_23 ;
union V_5 * V_7 = NULL ;
T_1 V_8 = V_30 ;
T_3 V_62 ;
T_4 V_63 ;
T_4 V_64 ;
F_2 ( V_65 ) ;
V_23 = V_4 -> V_10 . V_23 ;
while ( ( V_23 -> V_10 . V_11 == V_24 ) ||
( V_23 -> V_10 . V_11 == V_25 ) ) {
V_23 = V_23 -> V_10 . V_23 ;
}
V_7 = * V_6 ;
if ( ! V_7 ) {
V_7 = F_12 ( V_66 ) ;
* V_6 = V_7 ;
if ( ! V_7 ) {
F_7 ( V_42 ) ;
}
V_7 -> V_67 . V_13 = V_23 -> V_10 . V_13 ;
}
V_7 -> V_67 . V_68 = F_18 ( ( ( V_69 )
V_61 +
1 ) * sizeof( void * ) ) ;
if ( ! V_7 -> V_67 . V_68 ) {
F_19 ( V_7 ) ;
F_7 ( V_42 ) ;
}
V_7 -> V_67 . V_70 = V_61 ;
V_44 = V_4 -> V_10 . V_15 . V_44 ;
V_44 = V_44 -> V_10 . V_50 ;
for ( V_62 = 0 ; V_44 && ( V_62 < V_61 ) ; V_62 ++ ) {
if ( V_44 -> V_10 . V_11 == V_71 ) {
if ( V_44 -> V_10 . V_13 -> type == V_36 ) {
V_44 -> V_10 . V_11 = V_12 ;
V_8 =
F_1 ( V_2 ,
V_44 ,
& V_7 ->
V_67 .
V_68 [ V_62 ] ) ;
} else {
V_7 -> V_67 . V_68 [ V_62 ] =
F_9 ( union V_5 ,
V_44 -> V_10 . V_13 ) ;
}
} else {
V_8 = F_1 ( V_2 , V_44 ,
& V_7 ->
V_67 .
V_68 [ V_62 ] ) ;
}
if ( * V_6 ) {
V_64 =
( * V_6 ) -> V_10 . V_64 ;
if ( V_64 > 1 ) {
for ( V_63 = 0 ; V_63 < ( V_64 - 1 ) ;
V_63 ++ ) {
F_11 ( ( V_7 ->
V_67 .
V_68 [ V_62 ] ) ) ;
}
}
}
V_44 = V_44 -> V_10 . V_50 ;
}
if ( V_44 ) {
while ( V_44 ) {
if ( V_44 -> V_10 . V_13 ) {
F_15 ( F_9
( union
V_5 ,
V_44 -> V_10 . V_13 ) ) ;
V_44 -> V_10 . V_13 = NULL ;
}
V_62 ++ ;
V_44 = V_44 -> V_10 . V_50 ;
}
F_21 ( ( V_52 ,
L_4 ,
V_62 , V_61 ) ) ;
} else if ( V_62 < V_61 ) {
F_6 ( ( V_26 ,
L_5 ,
V_62 , V_61 ) ) ;
}
V_7 -> V_67 . V_59 |= V_60 ;
V_4 -> V_10 . V_13 = F_9 ( struct V_20 , V_7 ) ;
F_7 ( V_8 ) ;
}
T_1
F_22 ( struct V_1 * V_2 ,
struct V_20 * V_13 ,
union V_3 * V_4 )
{
T_1 V_8 ;
union V_5 * V_7 ;
F_23 ( V_72 , V_4 ) ;
if ( F_24 ( V_13 ) ) {
F_7 ( V_30 ) ;
}
if ( ! V_4 -> V_10 . V_15 . V_44 ) {
F_7 ( V_30 ) ;
}
V_8 = F_1 ( V_2 , V_4 -> V_10 . V_15 . V_44 ,
& V_7 ) ;
if ( F_5 ( V_8 ) ) {
F_7 ( V_8 ) ;
}
V_13 -> type = V_7 -> V_10 . type ;
V_8 = F_25 ( V_13 , V_7 , V_13 -> type ) ;
F_15 ( V_7 ) ;
F_7 ( V_8 ) ;
}
T_1
F_14 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_4 V_73 ,
union V_5 * * V_74 )
{
const struct V_75 * V_76 ;
union V_5 * V_7 ;
T_1 V_8 = V_30 ;
F_2 ( V_77 ) ;
V_7 = * V_74 ;
V_76 = F_13 ( V_73 ) ;
if ( V_76 -> V_78 == V_79 ) {
F_7 ( V_53 ) ;
}
switch ( V_7 -> V_10 . type ) {
case V_48 :
V_7 -> V_54 . V_13 =
F_9 ( struct V_20 ,
V_2 -> V_80 [ 0 ] ) ;
V_7 -> V_54 . V_81 = V_4 -> V_49 . V_58 ;
V_7 -> V_54 . V_82 = V_4 -> V_49 . V_55 ;
break;
case V_66 :
V_7 -> V_67 . V_13 =
F_9 ( struct V_20 ,
V_2 -> V_80 [ 0 ] ) ;
V_7 -> V_67 . V_81 = V_4 -> V_49 . V_58 ;
V_7 -> V_67 . V_82 = V_4 -> V_49 . V_55 ;
break;
case V_83 :
switch ( V_76 -> type ) {
case V_84 :
V_7 -> V_10 . V_59 = V_85 ;
switch ( V_73 ) {
case V_86 :
V_7 -> integer . V_15 = 0 ;
break;
case V_87 :
V_7 -> integer . V_15 = 1 ;
break;
case V_88 :
V_7 -> integer . V_15 = V_89 ;
#ifndef F_26
( void ) F_27 ( V_7 ) ;
#endif
break;
case V_90 :
V_7 -> integer . V_15 = V_91 ;
break;
default:
F_17 ( ( V_52 ,
L_6 ,
V_73 ) ) ;
V_8 = V_92 ;
break;
}
break;
case V_93 :
V_7 -> integer . V_15 = V_4 -> V_10 . V_15 . integer ;
#ifndef F_26
if ( F_27 ( V_7 ) ) {
F_28 ( ( V_52 ,
L_7 ,
F_29 ( V_4 -> V_10 .
V_15 . integer ) ,
( T_3 ) V_7 -> integer . V_15 ) ) ;
}
#endif
break;
default:
F_17 ( ( V_52 , L_8 ,
V_76 -> type ) ) ;
V_8 = V_92 ;
break;
}
break;
case V_94 :
V_7 -> string . V_56 = V_4 -> V_10 . V_15 . string ;
V_7 -> string . V_55 = ( T_3 ) strlen ( V_4 -> V_10 . V_15 . string ) ;
V_7 -> V_10 . V_59 |= V_95 ;
break;
case V_36 :
break;
case V_96 :
switch ( V_76 -> type ) {
case V_97 :
V_7 -> V_98 . V_15 =
( ( T_3 ) V_73 ) - V_99 ;
V_7 -> V_98 . V_78 = V_100 ;
#ifndef F_26
V_8 =
F_30 ( V_100 ,
V_7 -> V_98 .
V_15 , V_2 ,
F_4
( struct
V_20 ,
& V_7 -> V_98 .
V_32 ) ) ;
#endif
break;
case V_101 :
V_7 -> V_98 . V_15 = ( ( T_3 ) V_73 ) - V_102 ;
V_7 -> V_98 . V_78 = V_103 ;
#ifndef F_26
V_8 = F_30 ( V_103 ,
V_7 ->
V_98 . V_15 ,
V_2 ,
F_4
( struct
V_20 ,
& V_7 ->
V_98 .
V_32 ) ) ;
#endif
break;
default:
switch ( V_4 -> V_10 . V_11 ) {
case V_12 :
V_7 -> V_98 . V_13 = V_4 -> V_10 . V_13 ;
V_7 -> V_98 . V_32 =
V_4 -> V_10 . V_13 -> V_32 ;
V_7 -> V_98 . V_78 = V_104 ;
break;
case V_105 :
V_7 -> V_98 . V_78 = V_106 ;
break;
default:
F_17 ( ( V_52 ,
L_9 ,
V_73 ) ) ;
F_7 ( V_92 ) ;
}
break;
}
break;
default:
F_17 ( ( V_52 , L_10 ,
V_7 -> V_10 . type ) ) ;
V_8 = V_92 ;
break;
}
F_7 ( V_8 ) ;
}
