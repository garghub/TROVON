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
if ( ( ! V_11 -> V_17 . V_18 ) ||
( V_11 -> V_17 . V_18 == V_23 ) ) {
goto V_15;
}
V_14 = F_6 ( sizeof( struct V_13 ) ) ;
if ( ! V_14 ) {
goto V_15;
}
V_14 -> V_11 = V_11 ;
V_14 -> V_24 = V_2 -> V_25 ;
V_14 -> V_12 = V_12 ;
V_8 = F_7 ( V_14 , V_6 ,
V_11 -> V_17 . V_18 ,
V_26 ) ;
if ( F_8 ( V_8 ) ) {
goto exit;
}
if ( ( * V_6 ) -> V_27 . type == V_28 ) {
V_14 -> V_29 = * V_6 ;
V_8 = F_9 ( V_14 , V_6 ) ;
if ( F_8 ( V_8 ) ) {
goto exit;
}
}
V_8 = F_10 ( V_14 , V_2 , V_8 , V_6 ) ;
exit:
if ( F_8 ( V_8 ) || ( V_14 -> V_25 & V_30 ) ) {
V_2 -> V_25 |= V_31 ;
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
T_2 V_32 ;
T_2 V_33 ;
T_2 V_34 ;
V_32 = 0 ;
if ( V_2 -> type == V_35 ) {
V_32 = V_2 -> V_36 -> V_37 . V_32 ;
}
if ( ! V_11 ) {
if ( V_3 < V_32 ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_2 ,
V_32 , V_3 ) ) ;
} else if ( V_3 > V_32 ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_3 ,
V_32 , V_3 ) ) ;
}
return;
}
V_33 = V_11 -> V_17 . V_32 & 0x0F ;
V_34 = V_11 -> V_17 . V_32 >> 4 ;
if ( V_3 != V_38 ) {
if ( ( V_3 != V_33 ) &&
( V_3 != V_34 ) ) {
F_5 ( ( V_20 , V_12 ,
V_21 ,
L_4
L_5 ,
V_3 ,
V_33 ) ) ;
}
}
if ( ( V_32 != V_33 ) &&
( V_32 != V_34 ) ) {
F_5 ( ( V_20 , V_12 , V_2 -> V_25 ,
L_6 ,
V_32 , V_33 ) ) ;
}
}
const union V_10 * F_2 ( struct
V_1
* V_2 )
{
const union V_10 * V_39 ;
if ( V_2 -> V_40 . V_41 [ 0 ] != '_' ) {
return ( NULL ) ;
}
V_39 = V_42 ;
while ( V_39 -> V_17 . V_40 [ 0 ] ) {
if ( F_12 ( V_2 -> V_40 . V_41 , V_39 -> V_17 . V_40 ) ) {
return ( V_39 ) ;
}
if ( V_39 -> V_17 . V_18 & V_43 ) {
V_39 ++ ;
}
V_39 ++ ;
}
return ( NULL ) ;
}
static T_1
F_9 ( struct V_13 * V_14 ,
union V_5 * * V_6 )
{
union V_5 * V_7 = * V_6 ;
const union V_10 * V_44 ;
union V_5 * * V_45 ;
T_1 V_8 = V_9 ;
T_2 V_46 ;
T_2 V_47 ;
T_2 V_48 ;
F_13 ( V_49 ) ;
V_44 = V_14 -> V_11 + 1 ;
F_14 ( ( V_50 ,
L_7 ,
V_14 -> V_12 , V_44 -> V_51 . type ,
V_7 -> V_44 . V_47 ) ) ;
F_15 ( V_14 , V_44 -> V_51 . type ,
V_7 ) ;
V_45 = V_7 -> V_44 . V_45 ;
V_47 = V_7 -> V_44 . V_47 ;
if ( ! V_47 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_8 ) ) ;
return ( V_52 ) ;
}
switch ( V_44 -> V_51 . type ) {
case V_53 :
V_46 =
V_44 -> V_51 . V_54 + V_44 -> V_51 . V_55 ;
if ( V_47 < V_46 ) {
goto V_56;
} else if ( V_47 > V_46 ) {
F_14 ( ( V_57 ,
L_9
L_10 ,
V_14 -> V_12 , V_47 ,
V_46 ) ) ;
}
V_8 = F_16 ( V_14 , V_45 ,
V_44 -> V_51 .
V_58 ,
V_44 -> V_51 .
V_54 ,
V_44 -> V_51 .
V_59 ,
V_44 -> V_51 .
V_55 , 0 ) ;
break;
case V_60 :
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
V_8 = F_7 ( V_14 , V_45 ,
V_44 -> V_51 .
V_58 , V_48 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_45 ++ ;
}
break;
case V_61 :
V_46 = V_44 -> V_62 . V_47 ;
if ( V_47 < V_46 ) {
goto V_56;
}
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
if ( V_48 < V_44 -> V_62 . V_47 ) {
V_8 =
F_7 ( V_14 , V_45 ,
V_44 ->
V_62 .
V_63 [ V_48 ] ,
V_48 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
} else {
V_8 =
F_7 ( V_14 , V_45 ,
V_44 ->
V_62 .
V_64 ,
V_48 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
}
V_45 ++ ;
}
break;
case V_65 :
V_8 = F_7 ( V_14 , V_45 ,
V_66 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_45 ++ ;
V_47 -- ;
V_8 =
F_17 ( V_14 , V_44 , V_45 , V_47 ) ;
break;
case V_67 :
V_8 = F_7 ( V_14 , V_45 ,
V_66 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_46 = ( T_2 ) ( * V_45 ) -> integer . V_68 ;
if ( V_46 >= V_47 ) {
goto V_56;
}
V_47 = V_46 ;
V_45 ++ ;
V_8 =
F_17 ( V_14 , V_44 , V_45 , V_47 ) ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
if ( * V_45
&& ( ( * V_45 ) -> V_27 . type != V_28 ) ) {
V_8 =
F_18 ( V_14 ,
V_6 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_7 = * V_6 ;
V_45 = V_7 -> V_44 . V_45 ;
V_47 = 1 ;
}
V_8 =
F_17 ( V_14 , V_44 , V_45 , V_47 ) ;
break;
default:
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_11 ,
V_44 -> V_51 . type ) ) ;
return ( V_73 ) ;
}
return ( V_8 ) ;
V_56:
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_12 ,
V_47 , V_46 ) ) ;
return ( V_52 ) ;
}
static T_1
F_17 ( struct V_13 * V_14 ,
const union V_10 * V_44 ,
union V_5 * * V_45 , T_2 V_47 )
{
union V_5 * V_74 ;
union V_5 * * V_75 ;
T_1 V_8 ;
T_2 V_46 ;
T_2 V_48 ;
T_2 V_76 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
V_74 = * V_45 ;
V_75 = V_74 -> V_44 . V_45 ;
V_14 -> V_29 = V_74 ;
V_8 = F_7 ( V_14 , & V_74 ,
V_43 , V_48 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_14 -> V_29 = V_74 ;
switch ( V_44 -> V_51 . type ) {
case V_69 :
case V_67 :
case V_65 :
V_46 =
V_44 -> V_51 . V_54 + V_44 -> V_51 . V_55 ;
if ( V_74 -> V_44 . V_47 < V_46 ) {
goto V_56;
}
V_8 =
F_16 ( V_14 , V_75 ,
V_44 -> V_51 .
V_58 ,
V_44 -> V_51 .
V_54 ,
V_44 -> V_51 .
V_59 ,
V_44 -> V_51 .
V_55 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
case V_70 :
V_46 = V_44 -> V_77 . V_47 ;
if ( V_74 -> V_44 . V_47 < V_46 ) {
goto V_56;
}
for ( V_76 = 0 ; V_76 < V_46 ; V_76 ++ ) {
V_8 =
F_7 ( V_14 ,
& V_75 [ V_76 ] ,
V_44 ->
V_77 .
V_63 [ V_76 ] ,
V_76 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
}
break;
case V_71 :
V_46 = V_44 -> V_51 . V_54 ;
if ( V_74 -> V_44 . V_47 < V_46 ) {
goto V_56;
}
V_8 =
F_16 ( V_14 , V_75 ,
V_44 -> V_51 .
V_58 ,
V_74 -> V_44 .
V_47 , 0 , 0 , 0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
case V_72 :
V_8 = F_7 ( V_14 , V_75 ,
V_66 ,
0 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_46 = ( T_2 ) ( * V_75 ) -> integer . V_68 ;
if ( V_74 -> V_44 . V_47 < V_46 ) {
goto V_56;
}
if ( V_74 -> V_44 . V_47 <
V_44 -> V_51 . V_54 ) {
V_46 = V_44 -> V_51 . V_54 ;
goto V_56;
}
if ( V_46 == 0 ) {
V_46 = V_74 -> V_44 . V_47 ;
( * V_75 ) -> integer . V_68 = V_46 ;
}
V_8 =
F_16 ( V_14 ,
( V_75 + 1 ) ,
V_44 -> V_51 .
V_58 ,
( V_46 - 1 ) ,
0 , 0 , 1 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
break;
default:
return ( V_73 ) ;
}
V_45 ++ ;
}
return ( V_9 ) ;
V_56:
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_13 ,
V_48 , V_74 -> V_44 . V_47 , V_46 ) ) ;
return ( V_52 ) ;
}
static T_1
F_16 ( struct V_13 * V_14 ,
union V_5 * * V_45 ,
T_3 V_78 ,
T_2 V_54 ,
T_3 V_79 , T_2 V_55 , T_2 V_80 )
{
union V_5 * * V_81 = V_45 ;
T_1 V_8 ;
T_2 V_48 ;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ ) {
V_8 = F_7 ( V_14 , V_81 ,
V_78 , V_48 + V_80 ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_81 ++ ;
}
for ( V_48 = 0 ; V_48 < V_55 ; V_48 ++ ) {
V_8 = F_7 ( V_14 , V_81 ,
V_79 ,
( V_48 + V_54 + V_80 ) ) ;
if ( F_8 ( V_8 ) ) {
return ( V_8 ) ;
}
V_81 ++ ;
}
return ( V_9 ) ;
}
static T_1
F_7 ( struct V_13 * V_14 ,
union V_5 * * V_6 ,
T_2 V_18 , T_2 V_82 )
{
union V_5 * V_7 = * V_6 ;
T_1 V_8 = V_9 ;
T_2 V_83 ;
char V_84 [ 48 ] ;
if ( ! V_7 ) {
V_8 = F_19 ( V_14 , V_18 ,
V_82 ,
V_6 ) ;
if ( F_20 ( V_8 ) ) {
return ( V_9 ) ;
}
goto V_85;
}
if ( F_21 ( V_7 ) == V_86 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_14 ,
V_7 -> V_2 . V_40 . V_41 ,
F_22 ( V_7 -> V_2 .
type ) ) ) ;
return ( V_87 ) ;
}
switch ( V_7 -> V_27 . type ) {
case V_88 :
V_83 = V_66 ;
break;
case V_89 :
V_83 = V_90 ;
break;
case V_91 :
V_83 = V_92 ;
break;
case V_28 :
V_83 = V_43 ;
break;
case V_93 :
V_83 = V_94 ;
break;
default:
goto V_85;
}
if ( V_83 & V_18 ) {
if ( V_7 -> V_27 . type == V_93 ) {
V_8 = F_23 ( V_14 , V_7 ) ;
}
return ( V_8 ) ;
}
V_8 = F_24 ( V_14 , V_18 ,
V_82 , V_6 ) ;
if ( F_20 ( V_8 ) ) {
return ( V_9 ) ;
}
V_85:
F_25 ( V_84 , V_18 ) ;
if ( V_82 == V_26 ) {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_15 ,
F_26
( V_7 ) , V_84 ) ) ;
} else {
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_16
L_17 , V_82 ,
F_26
( V_7 ) , V_84 ) ) ;
}
return ( V_87 ) ;
}
static T_1
F_23 ( struct V_13 * V_14 ,
union V_5 * V_7 )
{
if ( V_7 -> V_95 . V_96 == V_97 ) {
return ( V_9 ) ;
}
F_5 ( ( V_20 , V_14 -> V_12 , V_14 -> V_24 ,
L_18 ,
F_27 ( V_7 ) ,
V_7 -> V_95 . V_96 ) ) ;
return ( V_87 ) ;
}
static void F_25 ( char * V_98 , T_2 V_18 )
{
T_2 V_99 ;
T_2 V_48 ;
T_2 V_76 ;
V_76 = 1 ;
V_98 [ 0 ] = 0 ;
V_99 = V_66 ;
for ( V_48 = 0 ; V_48 < V_100 ; V_48 ++ ) {
if ( V_18 & V_99 ) {
F_28 ( V_98 , & V_101 [ V_48 ] [ V_76 ] ) ;
V_76 = 0 ;
}
V_99 <<= 1 ;
}
}
