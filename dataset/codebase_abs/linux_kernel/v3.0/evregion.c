T_1 F_1 ( void )
{
T_1 V_1 ;
T_2 V_2 ;
F_2 ( V_3 ) ;
V_1 = F_3 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
F_5 ( V_1 ) ;
}
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
V_1 = F_6 ( V_6 ,
V_7
[ V_2 ] ,
V_8 ,
NULL , NULL ) ;
switch ( V_1 ) {
case V_9 :
case V_10 :
case V_11 :
V_1 = V_9 ;
break;
default:
goto V_12;
}
}
V_12:
( void ) F_7 ( V_4 ) ;
F_5 ( V_1 ) ;
}
static T_3
F_8 ( struct V_13 * V_14 ,
T_4 V_15 )
{
union V_16 * V_17 ;
union V_16 * V_18 ;
V_17 = F_9 ( V_14 ) ;
if ( V_17 ) {
V_18 = V_17 -> V_19 . V_20 ;
while ( V_18 ) {
if ( V_18 -> V_21 . V_15 == V_15 ) {
if ( V_18 -> V_21 . V_22 &
V_23 ) {
return ( TRUE ) ;
}
}
V_18 = V_18 -> V_21 . V_24 ;
}
}
return ( FALSE ) ;
}
T_1 F_10 ( void )
{
T_1 V_1 ;
T_2 V_2 ;
F_2 ( V_25 ) ;
V_1 = F_3 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
F_5 ( V_1 ) ;
}
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
if ( F_8 ( V_6 ,
V_7
[ V_2 ] ) ) {
V_1 =
F_11 ( V_6 ,
V_7
[ V_2 ] ) ;
}
}
V_26 = TRUE ;
( void ) F_7 ( V_4 ) ;
F_5 ( V_1 ) ;
}
T_1
F_12 ( union V_16 * V_27 , T_2 V_28 )
{
struct V_29 * V_30 ;
union V_16 * args [ 3 ] ;
union V_16 * V_31 ;
T_1 V_1 ;
F_2 ( V_32 ) ;
V_31 = F_13 ( V_27 ) ;
if ( ! V_31 ) {
F_5 ( V_33 ) ;
}
if ( V_31 -> V_34 . V_35 == NULL ) {
F_5 ( V_9 ) ;
}
V_30 = F_14 ( sizeof( struct V_29 ) ) ;
if ( ! V_30 ) {
F_5 ( V_36 ) ;
}
V_30 -> V_37 = V_31 -> V_34 . V_35 ;
V_30 -> V_38 = NULL ;
V_30 -> V_39 = args ;
V_30 -> V_40 = V_41 ;
args [ 0 ] =
F_15 ( ( V_42 ) V_27 -> V_43 . V_15 ) ;
if ( ! args [ 0 ] ) {
V_1 = V_36 ;
goto V_44;
}
args [ 1 ] = F_15 ( ( V_42 ) V_28 ) ;
if ( ! args [ 1 ] ) {
V_1 = V_36 ;
goto V_45;
}
args [ 2 ] = NULL ;
F_16 ( F_17
( V_46 , V_30 -> V_37 , NULL ) ) ;
V_1 = F_18 ( V_30 ) ;
F_19 ( args [ 1 ] ) ;
V_45:
F_19 ( args [ 0 ] ) ;
V_44:
F_20 ( V_30 ) ;
F_5 ( V_1 ) ;
}
T_1
F_21 ( union V_16 * V_27 ,
T_2 V_28 ,
T_2 V_47 , T_2 V_48 , V_42 * V_49 )
{
T_1 V_1 ;
T_5 V_20 ;
T_6 V_50 ;
union V_16 * V_51 ;
union V_16 * V_31 ;
void * V_52 = NULL ;
F_2 ( V_53 ) ;
V_31 = F_13 ( V_27 ) ;
if ( ! V_31 ) {
F_5 ( V_33 ) ;
}
V_51 = V_27 -> V_43 . V_20 ;
if ( ! V_51 ) {
F_22 ( ( V_54 ,
L_1 ,
F_23 ( V_27 -> V_43 . V_14 ) ,
V_27 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
F_5 ( V_33 ) ;
}
if ( ! ( V_27 -> V_43 . V_40 & V_55 ) ) {
V_50 = V_51 -> V_21 . V_56 ;
if ( ! V_50 ) {
F_22 ( ( V_54 ,
L_2 ,
V_27 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
F_5 ( V_33 ) ;
}
F_25 () ;
V_1 = V_50 ( V_27 , V_57 ,
V_51 -> V_21 . V_58 ,
& V_52 ) ;
F_26 () ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_54 , V_1 ,
L_3 ,
F_24 ( V_27 ->
V_43 .
V_15 ) ) ) ;
F_5 ( V_1 ) ;
}
if ( ! ( V_27 -> V_43 . V_40 & V_55 ) ) {
V_27 -> V_43 . V_40 |= V_55 ;
if ( V_31 -> V_34 . V_52 ) {
F_20 ( V_52 ) ;
} else {
V_31 -> V_34 . V_52 =
V_52 ;
}
}
}
V_20 = V_51 -> V_21 . V_20 ;
F_28 ( ( V_59 ,
L_4 ,
& V_27 -> V_43 . V_20 -> V_21 , V_20 ,
F_29 ( V_27 -> V_43 . V_60 +
V_47 ) ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
if ( ! ( V_51 -> V_21 . V_22 &
V_23 ) ) {
F_25 () ;
}
V_1 = V_20 ( V_28 ,
( V_27 -> V_43 . V_60 + V_47 ) ,
V_48 , V_49 , V_51 -> V_21 . V_58 ,
V_31 -> V_34 . V_52 ) ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_54 , V_1 , L_5 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
}
if ( ! ( V_51 -> V_21 . V_22 &
V_23 ) ) {
F_26 () ;
}
F_5 ( V_1 ) ;
}
void
F_30 ( union V_16 * V_27 ,
T_3 V_61 )
{
union V_16 * V_18 ;
union V_16 * V_17 ;
union V_16 * * V_62 ;
T_6 V_50 ;
void * * V_52 ;
union V_16 * V_31 ;
T_1 V_1 ;
F_2 ( V_63 ) ;
V_31 = F_13 ( V_27 ) ;
if ( ! V_31 ) {
V_64 ;
}
V_52 = & V_31 -> V_34 . V_52 ;
V_18 = V_27 -> V_43 . V_20 ;
if ( ! V_18 ) {
V_64 ;
}
V_17 = V_18 -> V_21 . V_65 ;
V_62 = & V_18 -> V_21 . V_65 ;
while ( V_17 ) {
if ( V_17 == V_27 ) {
F_28 ( ( V_59 ,
L_6 ,
V_27 , V_18 ) ) ;
* V_62 = V_17 -> V_43 . V_24 ;
V_17 -> V_43 . V_24 = NULL ;
if ( V_61 ) {
V_1 =
F_7 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
V_64 ;
}
}
V_1 =
F_12 ( V_27 ,
V_66 ) ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_54 , V_1 ,
L_7 ,
F_24
( V_27 -> V_43 . V_15 ) ) ) ;
}
if ( V_61 ) {
V_1 =
F_3 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
V_64 ;
}
}
if ( V_27 -> V_43 . V_40 & V_55 ) {
V_50 = V_18 -> V_21 . V_56 ;
V_1 =
V_50 ( V_27 ,
V_67 ,
V_18 -> V_21 .
V_58 , V_52 ) ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_54 , V_1 ,
L_8 ,
F_24
( V_27 -> V_43 .
V_15 ) ) ) ;
}
V_27 -> V_43 . V_40 &=
~ ( V_55 ) ;
}
V_27 -> V_43 . V_20 = NULL ;
F_19 ( V_18 ) ;
V_64 ;
}
V_62 = & V_17 -> V_43 . V_24 ;
V_17 = V_17 -> V_43 . V_24 ;
}
F_28 ( ( V_59 ,
L_9 ,
V_27 , V_18 ) ) ;
V_64 ;
}
T_1
F_31 ( union V_16 * V_18 ,
union V_16 * V_27 ,
T_3 V_61 )
{
F_2 ( V_68 ) ;
F_28 ( ( V_59 ,
L_10 ,
F_23 ( V_27 -> V_43 . V_14 ) ,
V_27 , V_18 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
V_27 -> V_43 . V_24 = V_18 -> V_21 . V_65 ;
V_18 -> V_21 . V_65 = V_27 ;
if ( V_27 -> V_43 . V_20 ) {
F_5 ( V_11 ) ;
}
V_27 -> V_43 . V_20 = V_18 ;
F_32 ( V_18 ) ;
F_5 ( V_9 ) ;
}
static T_1
F_33 ( T_7 V_69 ,
T_2 V_70 , void * V_58 , void * * V_71 )
{
union V_16 * V_18 ;
union V_16 * V_72 ;
union V_16 * V_17 ;
struct V_13 * V_14 ;
T_1 V_1 ;
F_34 ( V_73 ) ;
V_18 = (union V_16 * ) V_58 ;
if ( ! V_18 ) {
return ( V_9 ) ;
}
V_14 = F_35 ( V_69 ) ;
if ( ! V_14 ) {
return ( V_74 ) ;
}
if ( ( V_14 -> type != V_75 ) &&
( V_14 -> type != V_76 ) && ( V_14 != V_6 ) ) {
return ( V_9 ) ;
}
V_17 = F_9 ( V_14 ) ;
if ( ! V_17 ) {
return ( V_9 ) ;
}
if ( V_17 -> V_77 . type == V_75 ) {
V_72 = V_17 -> V_19 . V_20 ;
while ( V_72 ) {
if ( V_72 -> V_21 . V_15 ==
V_18 -> V_21 . V_15 ) {
F_28 ( ( V_59 ,
L_11
L_12 ,
F_24
( V_18 -> V_21 .
V_15 ) , V_17 ,
V_72 ,
V_18 ) ) ;
return ( V_78 ) ;
}
V_72 = V_72 -> V_21 . V_24 ;
}
return ( V_9 ) ;
}
if ( V_17 -> V_43 . V_15 != V_18 -> V_21 . V_15 ) {
return ( V_9 ) ;
}
F_30 ( V_17 , FALSE ) ;
V_1 = F_31 ( V_18 , V_17 , FALSE ) ;
return ( V_1 ) ;
}
T_1
F_6 ( struct V_13 * V_14 ,
T_4 V_15 ,
T_5 V_20 ,
T_6 V_56 , void * V_58 )
{
union V_16 * V_17 ;
union V_16 * V_18 ;
T_1 V_1 ;
T_8 type ;
T_3 V_40 = 0 ;
F_2 ( V_79 ) ;
if ( ( V_14 -> type != V_75 ) &&
( V_14 -> type != V_80 ) &&
( V_14 -> type != V_81 ) && ( V_14 != V_6 ) ) {
V_1 = V_74 ;
goto V_12;
}
if ( V_20 == V_8 ) {
V_40 = V_23 ;
switch ( V_15 ) {
case V_82 :
V_20 = V_83 ;
V_56 = V_84 ;
break;
case V_85 :
V_20 = V_86 ;
V_56 = V_87 ;
break;
case V_88 :
V_20 = V_89 ;
V_56 = V_90 ;
break;
case V_91 :
V_20 = V_92 ;
V_56 = V_93 ;
break;
case V_94 :
V_20 = V_95 ;
V_56 = V_96 ;
break;
case V_97 :
V_20 = V_98 ;
V_56 = NULL ;
break;
default:
V_1 = V_74 ;
goto V_12;
}
}
if ( ! V_56 ) {
V_56 = V_99 ;
}
V_17 = F_9 ( V_14 ) ;
if ( V_17 ) {
V_18 = V_17 -> V_19 . V_20 ;
while ( V_18 ) {
if ( V_18 -> V_21 . V_15 == V_15 ) {
if ( V_18 -> V_21 . V_20 ==
V_20 ) {
V_1 = V_10 ;
goto V_12;
} else {
V_1 = V_11 ;
}
goto V_12;
}
V_18 = V_18 -> V_21 . V_24 ;
}
} else {
F_28 ( ( V_59 ,
L_13 ,
V_14 ) ) ;
if ( V_14 -> type == V_100 ) {
type = V_75 ;
} else {
type = V_14 -> type ;
}
V_17 = F_36 ( type ) ;
if ( ! V_17 ) {
V_1 = V_36 ;
goto V_12;
}
V_17 -> V_77 . type = ( T_3 ) type ;
V_1 = F_37 ( V_14 , V_17 , type ) ;
F_19 ( V_17 ) ;
if ( F_4 ( V_1 ) ) {
goto V_12;
}
}
F_28 ( ( V_59 ,
L_14 ,
F_24 ( V_15 ) , V_15 ,
F_23 ( V_14 ) , V_14 , V_17 ) ) ;
V_18 =
F_36 ( V_101 ) ;
if ( ! V_18 ) {
V_1 = V_36 ;
goto V_12;
}
V_18 -> V_21 . V_15 = ( T_3 ) V_15 ;
V_18 -> V_21 . V_22 = V_40 ;
V_18 -> V_21 . V_65 = NULL ;
V_18 -> V_21 . V_14 = V_14 ;
V_18 -> V_21 . V_20 = V_20 ;
V_18 -> V_21 . V_58 = V_58 ;
V_18 -> V_21 . V_56 = V_56 ;
V_18 -> V_21 . V_24 = V_17 -> V_19 . V_20 ;
V_17 -> V_19 . V_20 = V_18 ;
V_1 = F_38 ( V_100 , V_14 , V_102 ,
V_103 ,
F_33 , NULL ,
V_18 , NULL ) ;
V_12:
F_5 ( V_1 ) ;
}
T_1
F_11 ( struct V_13 * V_14 ,
T_4 V_15 )
{
T_1 V_1 ;
F_2 ( V_104 ) ;
V_1 = F_38 ( V_100 , V_14 , V_102 ,
V_103 , V_105 ,
NULL , & V_15 , NULL ) ;
if ( V_15 == V_106 ) {
F_39 () ;
}
F_5 ( V_1 ) ;
}
static T_1
V_105 ( T_7 V_69 ,
T_2 V_70 , void * V_58 , void * * V_71 )
{
union V_16 * V_17 ;
struct V_13 * V_14 ;
T_4 V_15 ;
T_1 V_1 ;
V_15 = * F_40 ( T_4 , V_58 ) ;
V_14 = F_35 ( V_69 ) ;
if ( ! V_14 ) {
return ( V_74 ) ;
}
if ( ( V_14 -> type != V_76 ) && ( V_14 != V_6 ) ) {
return ( V_9 ) ;
}
V_17 = F_9 ( V_14 ) ;
if ( ! V_17 ) {
return ( V_9 ) ;
}
if ( V_17 -> V_43 . V_15 != V_15 ) {
return ( V_9 ) ;
}
V_1 = F_12 ( V_17 , V_107 ) ;
return ( V_1 ) ;
}
static void F_39 ( void )
{
struct V_108 * V_109 ;
T_1 V_1 ;
struct V_110 args ;
union V_111 V_112 [ 2 ] ;
struct V_13 * V_113 ;
struct V_13 * V_114 ;
struct V_13 * V_115 ;
F_2 ( V_116 ) ;
V_1 = F_41 ( V_117 , 0 ,
F_42 ( struct V_118 ,
& V_109 ) ) ;
if ( F_4 ( V_1 ) ) {
V_64 ;
}
if ( ! ( * V_109 -> V_119 ) ) {
V_64 ;
}
( void ) F_7 ( V_4 ) ;
V_1 = F_43 ( NULL ,
F_40 ( char , V_109 -> V_119 ) ,
F_40 ( T_7 , & V_113 ) ) ;
if ( F_4 ( V_1 ) ) {
goto exit;
}
V_1 = F_43 ( V_113 ,
V_120 , F_40 ( T_7 ,
& V_114 ) ) ;
if ( F_4 ( V_1 ) ) {
goto exit;
}
V_115 = F_44 ( V_113 , NULL ) ;
while ( V_115 ) {
if ( ( V_115 -> type == V_76 ) &&
( V_115 -> V_121 ) &&
( V_115 -> V_121 -> V_43 . V_15 == V_106 ) ) {
goto exit;
}
V_115 = F_44 ( V_113 , V_115 ) ;
}
args . V_122 = 2 ;
args . V_123 = V_112 ;
V_112 [ 0 ] . type = V_124 ;
V_112 [ 0 ] . integer . V_49 = V_106 ;
V_112 [ 1 ] . type = V_124 ;
V_112 [ 1 ] . integer . V_49 = V_107 ;
V_1 = F_45 ( V_114 , NULL , & args , NULL ) ;
exit:
V_1 = F_3 ( V_4 ) ;
V_64 ;
}
