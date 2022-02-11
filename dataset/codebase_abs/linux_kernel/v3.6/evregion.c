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
union V_16 * V_47 ,
T_2 V_28 ,
T_2 V_48 , T_2 V_49 , V_42 * V_50 )
{
T_1 V_1 ;
T_5 V_20 ;
T_6 V_51 ;
union V_16 * V_52 ;
union V_16 * V_31 ;
void * V_53 = NULL ;
struct V_54 * V_55 ;
F_2 ( V_56 ) ;
V_31 = F_13 ( V_27 ) ;
if ( ! V_31 ) {
F_5 ( V_33 ) ;
}
V_52 = V_27 -> V_43 . V_20 ;
if ( ! V_52 ) {
F_22 ( ( V_57 ,
L_1 ,
F_23 ( V_27 -> V_43 . V_14 ) ,
V_27 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
F_5 ( V_33 ) ;
}
V_55 = V_52 -> V_21 . V_55 ;
if ( ! ( V_27 -> V_43 . V_40 & V_58 ) ) {
V_51 = V_52 -> V_21 . V_59 ;
if ( ! V_51 ) {
F_22 ( ( V_57 ,
L_2 ,
V_27 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
F_5 ( V_33 ) ;
}
F_25 () ;
V_1 = V_51 ( V_27 , V_60 ,
V_55 , & V_53 ) ;
F_26 () ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_57 , V_1 ,
L_3 ,
F_24 ( V_27 ->
V_43 .
V_15 ) ) ) ;
F_5 ( V_1 ) ;
}
if ( ! ( V_27 -> V_43 . V_40 & V_58 ) ) {
V_27 -> V_43 . V_40 |= V_58 ;
if ( V_31 -> V_34 . V_53 ) {
F_20 ( V_53 ) ;
} else {
V_31 -> V_34 . V_53 =
V_53 ;
}
}
}
V_20 = V_52 -> V_21 . V_20 ;
F_28 ( ( V_61 ,
L_4 ,
& V_27 -> V_43 . V_20 -> V_21 , V_20 ,
F_29 ( V_27 -> V_43 . V_62 +
V_48 ) ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
if ( ( ( V_27 -> V_43 . V_15 == V_63 ) ||
( V_27 -> V_43 . V_15 == V_64 ) ) &&
V_55 && V_47 ) {
V_55 -> V_65 = V_47 -> V_66 . V_67 ;
V_55 -> V_68 = V_47 -> V_66 . V_69 ;
V_55 -> V_70 = V_47 -> V_66 . V_70 ;
}
if ( ! ( V_52 -> V_21 . V_22 &
V_23 ) ) {
F_25 () ;
}
V_1 = V_20 ( V_28 ,
( V_27 -> V_43 . V_62 + V_48 ) ,
V_49 , V_50 , V_55 ,
V_31 -> V_34 . V_53 ) ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_57 , V_1 , L_5 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
}
if ( ! ( V_52 -> V_21 . V_22 &
V_23 ) ) {
F_26 () ;
}
F_5 ( V_1 ) ;
}
void
F_30 ( union V_16 * V_27 ,
T_3 V_71 )
{
union V_16 * V_18 ;
union V_16 * V_17 ;
union V_16 * * V_72 ;
T_6 V_51 ;
void * * V_53 ;
union V_16 * V_31 ;
T_1 V_1 ;
F_2 ( V_73 ) ;
V_31 = F_13 ( V_27 ) ;
if ( ! V_31 ) {
V_74 ;
}
V_53 = & V_31 -> V_34 . V_53 ;
V_18 = V_27 -> V_43 . V_20 ;
if ( ! V_18 ) {
V_74 ;
}
V_17 = V_18 -> V_21 . V_75 ;
V_72 = & V_18 -> V_21 . V_75 ;
while ( V_17 ) {
if ( V_17 == V_27 ) {
F_28 ( ( V_61 ,
L_6 ,
V_27 , V_18 ) ) ;
* V_72 = V_17 -> V_43 . V_24 ;
V_17 -> V_43 . V_24 = NULL ;
if ( V_71 ) {
V_1 =
F_7 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
V_74 ;
}
}
V_1 =
F_12 ( V_27 ,
V_76 ) ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_57 , V_1 ,
L_7 ,
F_24
( V_27 -> V_43 . V_15 ) ) ) ;
}
if ( V_71 ) {
V_1 =
F_3 ( V_4 ) ;
if ( F_4 ( V_1 ) ) {
V_74 ;
}
}
if ( V_27 -> V_43 . V_40 & V_58 ) {
V_51 = V_18 -> V_21 . V_59 ;
V_1 =
V_51 ( V_27 ,
V_77 ,
V_18 -> V_21 .
V_55 , V_53 ) ;
if ( F_4 ( V_1 ) ) {
F_27 ( ( V_57 , V_1 ,
L_8 ,
F_24
( V_27 -> V_43 .
V_15 ) ) ) ;
}
V_27 -> V_43 . V_40 &=
~ ( V_58 ) ;
}
V_27 -> V_43 . V_20 = NULL ;
F_19 ( V_18 ) ;
V_74 ;
}
V_72 = & V_17 -> V_43 . V_24 ;
V_17 = V_17 -> V_43 . V_24 ;
}
F_28 ( ( V_61 ,
L_9 ,
V_27 , V_18 ) ) ;
V_74 ;
}
T_1
F_31 ( union V_16 * V_18 ,
union V_16 * V_27 ,
T_3 V_71 )
{
F_2 ( V_78 ) ;
F_28 ( ( V_61 ,
L_10 ,
F_23 ( V_27 -> V_43 . V_14 ) ,
V_27 , V_18 ,
F_24 ( V_27 -> V_43 .
V_15 ) ) ) ;
V_27 -> V_43 . V_24 = V_18 -> V_21 . V_75 ;
V_18 -> V_21 . V_75 = V_27 ;
if ( V_27 -> V_43 . V_20 ) {
F_5 ( V_11 ) ;
}
V_27 -> V_43 . V_20 = V_18 ;
F_32 ( V_18 ) ;
F_5 ( V_9 ) ;
}
static T_1
F_33 ( T_7 V_79 ,
T_2 V_80 , void * V_55 , void * * V_81 )
{
union V_16 * V_18 ;
union V_16 * V_82 ;
union V_16 * V_17 ;
struct V_13 * V_14 ;
T_1 V_1 ;
F_34 ( V_83 ) ;
V_18 = (union V_16 * ) V_55 ;
if ( ! V_18 ) {
return ( V_9 ) ;
}
V_14 = F_35 ( V_79 ) ;
if ( ! V_14 ) {
return ( V_84 ) ;
}
if ( ( V_14 -> type != V_85 ) &&
( V_14 -> type != V_86 ) && ( V_14 != V_6 ) ) {
return ( V_9 ) ;
}
V_17 = F_9 ( V_14 ) ;
if ( ! V_17 ) {
return ( V_9 ) ;
}
if ( V_17 -> V_87 . type == V_85 ) {
V_82 = V_17 -> V_19 . V_20 ;
while ( V_82 ) {
if ( V_82 -> V_21 . V_15 ==
V_18 -> V_21 . V_15 ) {
F_28 ( ( V_61 ,
L_11
L_12 ,
F_24
( V_18 -> V_21 .
V_15 ) , V_17 ,
V_82 ,
V_18 ) ) ;
return ( V_88 ) ;
}
V_82 = V_82 -> V_21 . V_24 ;
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
T_6 V_59 , void * V_55 )
{
union V_16 * V_17 ;
union V_16 * V_18 ;
T_1 V_1 ;
T_8 type ;
T_3 V_40 = 0 ;
F_2 ( V_89 ) ;
if ( ( V_14 -> type != V_85 ) &&
( V_14 -> type != V_90 ) &&
( V_14 -> type != V_91 ) && ( V_14 != V_6 ) ) {
V_1 = V_84 ;
goto V_12;
}
if ( V_20 == V_8 ) {
V_40 = V_23 ;
switch ( V_15 ) {
case V_92 :
V_20 = V_93 ;
V_59 = V_94 ;
break;
case V_95 :
V_20 = V_96 ;
V_59 = V_97 ;
break;
case V_98 :
V_20 = V_99 ;
V_59 = V_100 ;
break;
case V_101 :
V_20 = V_102 ;
V_59 = V_103 ;
break;
case V_104 :
V_20 = V_105 ;
V_59 = V_106 ;
break;
case V_107 :
V_20 = V_108 ;
V_59 = NULL ;
break;
default:
V_1 = V_84 ;
goto V_12;
}
}
if ( ! V_59 ) {
V_59 = V_109 ;
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
F_28 ( ( V_61 ,
L_13 ,
V_14 ) ) ;
if ( V_14 -> type == V_110 ) {
type = V_85 ;
} else {
type = V_14 -> type ;
}
V_17 = F_36 ( type ) ;
if ( ! V_17 ) {
V_1 = V_36 ;
goto V_12;
}
V_17 -> V_87 . type = ( T_3 ) type ;
V_1 = F_37 ( V_14 , V_17 , type ) ;
F_19 ( V_17 ) ;
if ( F_4 ( V_1 ) ) {
goto V_12;
}
}
F_28 ( ( V_61 ,
L_14 ,
F_24 ( V_15 ) , V_15 ,
F_23 ( V_14 ) , V_14 , V_17 ) ) ;
V_18 =
F_36 ( V_111 ) ;
if ( ! V_18 ) {
V_1 = V_36 ;
goto V_12;
}
V_18 -> V_21 . V_15 = ( T_3 ) V_15 ;
V_18 -> V_21 . V_22 = V_40 ;
V_18 -> V_21 . V_75 = NULL ;
V_18 -> V_21 . V_14 = V_14 ;
V_18 -> V_21 . V_20 = V_20 ;
V_18 -> V_21 . V_55 = V_55 ;
V_18 -> V_21 . V_59 = V_59 ;
V_18 -> V_21 . V_24 = V_17 -> V_19 . V_20 ;
V_17 -> V_19 . V_20 = V_18 ;
V_1 = F_38 ( V_110 , V_14 , V_112 ,
V_113 ,
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
F_2 ( V_114 ) ;
V_1 = F_38 ( V_110 , V_14 , V_112 ,
V_113 , V_115 ,
NULL , & V_15 , NULL ) ;
if ( V_15 == V_116 ) {
F_39 () ;
}
F_5 ( V_1 ) ;
}
static T_1
V_115 ( T_7 V_79 ,
T_2 V_80 , void * V_55 , void * * V_81 )
{
union V_16 * V_17 ;
struct V_13 * V_14 ;
T_4 V_15 ;
T_1 V_1 ;
V_15 = * F_40 ( T_4 , V_55 ) ;
V_14 = F_35 ( V_79 ) ;
if ( ! V_14 ) {
return ( V_84 ) ;
}
if ( ( V_14 -> type != V_86 ) && ( V_14 != V_6 ) ) {
return ( V_9 ) ;
}
V_17 = F_9 ( V_14 ) ;
if ( ! V_17 ) {
return ( V_9 ) ;
}
if ( V_17 -> V_43 . V_15 != V_15 ) {
return ( V_9 ) ;
}
V_1 = F_12 ( V_17 , V_117 ) ;
return ( V_1 ) ;
}
static void F_39 ( void )
{
struct V_118 * V_119 ;
T_1 V_1 ;
struct V_120 args ;
union V_121 V_122 [ 2 ] ;
struct V_13 * V_123 ;
struct V_13 * V_124 ;
struct V_13 * V_125 ;
F_2 ( V_126 ) ;
V_1 = F_41 ( V_127 , 0 ,
F_42 ( struct V_128 ,
& V_119 ) ) ;
if ( F_4 ( V_1 ) ) {
V_74 ;
}
if ( ! ( * V_119 -> V_129 ) ) {
V_74 ;
}
( void ) F_7 ( V_4 ) ;
V_1 = F_43 ( NULL ,
F_40 ( char , V_119 -> V_129 ) ,
F_40 ( T_7 , & V_123 ) ) ;
if ( F_4 ( V_1 ) ) {
goto exit;
}
V_1 = F_43 ( V_123 ,
V_130 , F_40 ( T_7 ,
& V_124 ) ) ;
if ( F_4 ( V_1 ) ) {
goto exit;
}
V_125 = F_44 ( V_123 , NULL ) ;
while ( V_125 ) {
if ( ( V_125 -> type == V_86 ) &&
( V_125 -> V_131 ) &&
( V_125 -> V_131 -> V_43 . V_15 == V_116 ) ) {
goto exit;
}
V_125 = F_44 ( V_123 , V_125 ) ;
}
args . V_132 = 2 ;
args . V_133 = V_122 ;
V_122 [ 0 ] . type = V_134 ;
V_122 [ 0 ] . integer . V_50 = V_116 ;
V_122 [ 1 ] . type = V_134 ;
V_122 [ 1 ] . integer . V_50 = V_117 ;
V_1 = F_45 ( V_124 , NULL , & args , NULL ) ;
exit:
V_1 = F_3 ( V_4 ) ;
V_74 ;
}
