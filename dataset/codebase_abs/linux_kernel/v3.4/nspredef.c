T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
T_1 V_8 = V_9 ;
const union V_10 * V_11 ;
char * V_12 ;
struct V_13 * V_14 ;
V_11 = F_2 ( V_2 ) ;
V_12 = F_3 ( V_2 ) ;
if ( ! V_12 ) {
return V_9 ;
}
F_4 ( V_12 , V_2 , V_3 ,
V_11 ) ;
if ( ! V_11 ) {
goto V_15;
}
if ( ( V_4 != V_9 ) && ( V_4 != V_16 ) ) {
goto V_15;
}
if ( ! V_7 ) {
if ( ( V_11 -> V_17 . V_18 ) &&
( ! ( V_11 -> V_17 . V_18 & V_19 ) ) ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_1 ) ) ;
V_8 = V_22 ;
}
goto V_15;
}
if ( V_23 ||
( ! V_11 -> V_17 . V_18 ) ||
( V_11 -> V_17 . V_18 == V_24 ) ) {
goto V_15;
}
V_14 = F_6 ( sizeof( struct V_13 ) ) ;
if ( ! V_14 ) {
goto V_15;
}
V_14 -> V_11 = V_11 ;
V_14 -> V_2 = V_2 ;
V_14 -> V_25 = V_2 -> V_26 ;
V_14 -> V_12 = V_12 ;
V_8 = F_7 ( V_14 , V_6 ,
V_11 -> V_17 . V_18 ,
V_27 ) ;
if ( F_8 ( V_8 ) ) {
goto exit;
}
if ( ( * V_6 ) -> V_28 . type == V_29 ) {
V_14 -> V_30 = * V_6 ;
V_8 = F_9 ( V_14 , V_6 ) ;
if ( F_8 ( V_8 ) ) {
goto exit;
}
}
V_8 = F_10 ( V_14 , V_2 , V_8 , V_6 ) ;
exit:
if ( F_8 ( V_8 ) || ( V_14 -> V_26 & V_31 ) ) {
V_2 -> V_26 |= V_32 ;
}
F_11 ( V_14 ) ;
V_15:
F_11 ( V_12 ) ;
return ( V_8 ) ;
}
void
F_4 ( char * V_12 ,
struct V_1 * V_2 ,
T_2 V_3 ,
const union V_10 * V_11 )
{
T_2 V_33 ;
T_2 V_34 ;
T_2 V_35 ;
V_33 = 0 ;
if ( V_2 -> type == V_36 ) {
V_33 = V_2 -> V_37 -> V_38 . V_33 ;
}
if ( ! V_11 ) {
if ( V_3 < V_33 ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_2 ,
V_33 , V_3 ) ) ;
} else if ( V_3 > V_33 ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_3 ,
V_33 , V_3 ) ) ;
}
return;
}
V_34 = V_11 -> V_17 . V_33 & 0x0F ;
V_35 = V_11 -> V_17 . V_33 >> 4 ;
if ( V_3 != V_39 ) {
if ( ( V_3 != V_34 ) &&
( V_3 != V_35 ) ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_4
L_5 ,
V_3 ,
V_34 ) ) ;
}
}
if ( ( V_33 != V_34 ) &&
( V_33 != V_35 ) ) {
F_5 ( ( V_20 , V_12 , V_2 -> V_26 ,
L_6 ,
V_33 , V_34 ) ) ;
}
}
const union V_10 * F_2 ( struct
V_1
* V_2 )
{
const union V_10 * V_40 ;
if ( V_2 -> V_41 . V_42 [ 0 ] != '_' ) {
return ( NULL ) ;
}
V_40 = V_43 ;
while ( V_40 -> V_17 . V_41 [ 0 ] ) {
if ( F_12 ( V_2 -> V_41 . V_42 , V_40 -> V_17 . V_41 ) ) {
return ( V_40 ) ;
}
if ( V_40 -> V_17 . V_18 & V_44 ) {
V_40 ++ ;
}
V_40 ++ ;
}
return ( NULL ) ;
}
static T_1
F_9 ( struct V_13 * V_14 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
const union V_10 * V_45 ;
union V_5 * * V_46 ;
T_1 V_8 = V_9 ;
T_2 V_47 ;
T_2 V_48 ;
T_2 V_49 ;
F_13 ( V_50 ) ;
V_45 = V_14 -> V_11 + 1 ;
F_14 ( ( V_51 ,
L_7 ,
V_14 -> V_12 , V_45 -> V_52 . type ,
V_7 -> V_45 . V_48 ) ) ;
F_15 ( V_14 , V_45 -> V_52 . type ,
V_7 ) ;
V_46 = V_7 -> V_45 . V_46 ;
V_48 = V_7 -> V_45 . V_48 ;
if ( ! V_48 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_8 ) ) ;
return ( V_53 ) ;
}
switch ( V_45 -> V_52 . type ) {
case V_54 :
V_47 =
V_45 -> V_52 . V_55 + V_45 -> V_52 . V_56 ;
if ( V_48 < V_47 ) {
goto V_57;
} else if ( V_48 > V_47 ) {
F_14 ( ( V_58 ,
L_9
L_10 ,
V_14 -> V_12 , V_48 ,
V_47 ) ) ;
}
V_8 = F_16 ( V_14 , V_46 ,
V_45 -> V_52 .
V_59 ,
V_45 -> V_52 .
V_55 ,
V_45 -> V_52 .
V_60 ,
V_45 -> V_52 .
V_56 , 0 ) ;
break;
case V_61 :
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
V_8 = F_7 ( V_14 , V_46 ,
V_45 -> V_52 .
V_59 , V_49 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_46 ++ ;
}
break;
case V_62 :
V_47 = V_45 -> V_63 . V_48 ;
if ( V_48 < V_47 ) {
goto V_57;
}
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
if ( V_49 < V_45 -> V_63 . V_48 ) {
V_8 =
F_7 ( V_14 , V_46 ,
V_45 ->
V_63 .
V_64 [ V_49 ] ,
V_49 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
} else {
V_8 =
F_7 ( V_14 , V_46 ,
V_45 ->
V_63 .
V_65 ,
V_49 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
}
V_46 ++ ;
}
break;
case V_66 :
V_8 = F_7 ( V_14 , V_46 ,
V_67 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_46 ++ ;
V_48 -- ;
V_8 =
F_17 ( V_14 , V_45 , V_46 , V_48 ) ;
break;
case V_68 :
V_8 = F_7 ( V_14 , V_46 ,
V_67 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_47 = ( T_2 ) ( * V_46 ) -> integer . V_69 ;
if ( V_47 >= V_48 ) {
goto V_57;
}
V_48 = V_47 ;
V_46 ++ ;
V_8 =
F_17 ( V_14 , V_45 , V_46 , V_48 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
if ( * V_46
&& ( ( * V_46 ) -> V_28 . type != V_29 ) ) {
V_8 =
F_18 ( V_14 , * V_46 ,
V_6 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_7 = * V_6 ;
V_46 = V_7 -> V_45 . V_46 ;
V_48 = 1 ;
}
V_8 =
F_17 ( V_14 , V_45 , V_46 , V_48 ) ;
break;
default:
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_11 ,
V_45 -> V_52 . type ) ) ;
return ( V_75 ) ;
}
return ( V_8 ) ;
V_57:
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_12 ,
V_48 , V_47 ) ) ;
return ( V_53 ) ;
}
static T_1
F_17 ( struct V_13 * V_14 ,
const union V_10 * V_45 ,
union V_5 * * V_46 , T_2 V_48 )
{
union V_5 * V_76 ;
union V_5 * * V_77 ;
T_1 V_8 ;
T_2 V_47 ;
T_2 V_49 ;
T_2 V_78 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
V_76 = * V_46 ;
V_77 = V_76 -> V_45 . V_46 ;
V_14 -> V_30 = V_76 ;
V_8 = F_7 ( V_14 , & V_76 ,
V_44 , V_49 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_14 -> V_30 = V_76 ;
switch ( V_45 -> V_52 . type ) {
case V_70 :
case V_68 :
case V_66 :
V_47 =
V_45 -> V_52 . V_55 + V_45 -> V_52 . V_56 ;
if ( V_76 -> V_45 . V_48 < V_47 ) {
goto V_57;
}
V_8 =
F_16 ( V_14 , V_77 ,
V_45 -> V_52 .
V_59 ,
V_45 -> V_52 .
V_55 ,
V_45 -> V_52 .
V_60 ,
V_45 -> V_52 .
V_56 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
case V_74 :
V_47 =
V_45 -> V_52 . V_55 + V_45 -> V_52 . V_56 ;
if ( V_76 -> V_45 . V_48 < V_47 ) {
goto V_57;
}
V_8 =
F_16 ( V_14 , V_77 ,
V_45 -> V_52 .
V_59 ,
V_45 -> V_52 .
V_55 ,
V_45 -> V_52 .
V_60 ,
V_76 -> V_45 .
V_48 -
V_45 -> V_52 .
V_55 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
case V_71 :
V_47 = V_45 -> V_79 . V_48 ;
if ( V_76 -> V_45 . V_48 < V_47 ) {
goto V_57;
}
for ( V_78 = 0 ; V_78 < V_47 ; V_78 ++ ) {
V_8 =
F_7 ( V_14 ,
& V_77 [ V_78 ] ,
V_45 ->
V_79 .
V_64 [ V_78 ] ,
V_78 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
}
break;
case V_72 :
V_47 = V_45 -> V_52 . V_55 ;
if ( V_76 -> V_45 . V_48 < V_47 ) {
goto V_57;
}
V_8 =
F_16 ( V_14 , V_77 ,
V_45 -> V_52 .
V_59 ,
V_76 -> V_45 .
V_48 , 0 , 0 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
case V_73 :
V_8 = F_7 ( V_14 , V_77 ,
V_67 ,
0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_47 = ( T_2 ) ( * V_77 ) -> integer . V_69 ;
if ( V_76 -> V_45 . V_48 < V_47 ) {
goto V_57;
}
if ( V_76 -> V_45 . V_48 <
V_45 -> V_52 . V_55 ) {
V_47 = V_45 -> V_52 . V_55 ;
goto V_57;
}
if ( V_47 == 0 ) {
V_47 = V_76 -> V_45 . V_48 ;
( * V_77 ) -> integer . V_69 = V_47 ;
}
V_8 =
F_16 ( V_14 ,
( V_77 + 1 ) ,
V_45 -> V_52 .
V_59 ,
( V_47 - 1 ) ,
0 , 0 , 1 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
default:
return ( V_75 ) ;
}
V_46 ++ ;
}
return ( V_9 ) ;
V_57:
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_13 ,
V_49 , V_76 -> V_45 . V_48 , V_47 ) ) ;
return ( V_53 ) ;
}
static T_1
F_16 ( struct V_13 * V_14 ,
union V_5 * * V_46 ,
T_3 V_80 ,
T_2 V_55 ,
T_3 V_81 , T_2 V_56 , T_2 V_82 )
{
union V_5 * * V_83 = V_46 ;
T_1 V_8 ;
T_2 V_49 ;
for ( V_49 = 0 ; V_49 < V_55 ; V_49 ++ ) {
V_8 = F_7 ( V_14 , V_83 ,
V_80 , V_49 + V_82 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_83 ++ ;
}
for ( V_49 = 0 ; V_49 < V_56 ; V_49 ++ ) {
V_8 = F_7 ( V_14 , V_83 ,
V_81 ,
( V_49 + V_55 + V_82 ) ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_83 ++ ;
}
return ( V_9 ) ;
}
static T_1
F_7 ( struct V_13 * V_14 ,
union V_5 * * V_6 ,
T_2 V_18 , T_2 V_84 )
{
union V_5 * V_7 = * V_6 ;
T_1 V_8 = V_9 ;
T_2 V_85 ;
char V_86 [ 48 ] ;
if ( ! V_7 ) {
V_8 = F_19 ( V_14 , V_18 ,
V_84 ,
V_6 ) ;
if ( F_20 ( V_8 ) ) {
return ( V_9 ) ;
}
goto V_87;
}
if ( F_21 ( V_7 ) == V_88 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_14 ,
V_7 -> V_2 . V_41 . V_42 ,
F_22 ( V_7 -> V_2 .
type ) ) ) ;
return ( V_89 ) ;
}
switch ( V_7 -> V_28 . type ) {
case V_90 :
V_85 = V_67 ;
break;
case V_91 :
V_85 = V_92 ;
break;
case V_93 :
V_85 = V_94 ;
break;
case V_29 :
V_85 = V_44 ;
break;
case V_95 :
V_85 = V_96 ;
break;
default:
goto V_87;
}
if ( V_85 & V_18 ) {
if ( V_7 -> V_28 . type == V_95 ) {
V_8 = F_23 ( V_14 , V_7 ) ;
}
return ( V_8 ) ;
}
V_8 = F_24 ( V_14 , V_18 ,
V_84 , V_6 ) ;
if ( F_20 ( V_8 ) ) {
return ( V_9 ) ;
}
V_87:
F_25 ( V_86 , V_18 ) ;
if ( V_84 == V_27 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_15 ,
F_26
( V_7 ) , V_86 ) ) ;
} else {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_16
L_17 , V_84 ,
F_26
( V_7 ) , V_86 ) ) ;
}
return ( V_89 ) ;
}
static T_1
F_23 ( struct V_13 * V_14 ,
union V_5 * V_7 )
{
if ( V_7 -> V_97 . V_98 == V_99 ) {
return ( V_9 ) ;
}
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_25 ,
L_18 ,
F_27 ( V_7 ) ,
V_7 -> V_97 . V_98 ) ) ;
return ( V_89 ) ;
}
static void F_25 ( char * V_100 , T_2 V_18 )
{
T_2 V_101 ;
T_2 V_49 ;
T_2 V_78 ;
V_78 = 1 ;
V_100 [ 0 ] = 0 ;
V_101 = V_67 ;
for ( V_49 = 0 ; V_49 < V_102 ; V_49 ++ ) {
if ( V_18 & V_101 ) {
F_28 ( V_100 , & V_103 [ V_49 ] [ V_78 ] ) ;
V_78 = 0 ;
}
V_101 <<= 1 ;
}
}
