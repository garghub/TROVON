void F_1 ( T_1 V_1 , char * V_2 )
{
T_1 V_3 ;
F_2 ( V_4 ) ;
if ( ! ( V_5 & V_6 )
|| ! ( V_7 & V_8 ) ) {
return;
}
F_3 ( ( V_9 , L_1 ) ) ;
while ( V_1 ) {
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
F_4 ( V_2 [ V_3 ] ) ?
F_5 ( L_2 , V_2 [ V_3 ] ) :
F_5 ( L_3 ) ;
}
V_2 += V_10 ;
V_1 -- ;
if ( V_1 ) {
F_5 ( L_4 ) ;
}
}
F_5 ( L_5 ) ;
}
void
F_6 ( T_2 V_11 , char * V_12 , T_1 V_13 , T_1 V_14 )
{
F_7 ( V_15 ) ;
if ( ! ( V_5 & V_13 ) || ! ( V_7 & V_14 ) ) {
V_16 ;
}
F_8 ( V_11 , V_12 ) ;
F_5 ( L_6 ) ;
V_16 ;
}
T_3
F_9 ( T_2 V_17 ,
T_1 V_13 , void * V_18 , void * * V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_18 ;
struct V_22 * V_23 ;
union V_24 * V_25 = NULL ;
T_4 V_26 ;
T_4 type ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_3 ;
F_2 ( V_29 ) ;
if ( ! ( V_5 & V_21 -> V_30 ) ) {
return ( V_31 ) ;
}
if ( ! V_17 ) {
F_3 ( ( V_32 , L_7 ) ) ;
return ( V_31 ) ;
}
V_23 = F_10 ( V_17 ) ;
if ( ! V_23 ) {
F_3 ( ( V_32 , L_8 ,
V_17 ) ) ;
return ( V_31 ) ;
}
type = V_23 -> type ;
if ( ( V_21 -> V_33 != V_34 ) &&
( V_21 -> V_33 != V_23 -> V_33 ) ) {
return ( V_31 ) ;
}
if ( ! ( V_21 -> V_35 & V_36 ) ) {
F_5 ( L_9 , ( T_1 ) V_13 - 1 , ( int ) V_13 * 2 , L_10 ) ;
if ( type > V_37 ) {
F_11 ( ( V_38 ,
L_11 , type ) ) ;
}
if ( ! F_12 ( V_23 -> V_39 . integer ) ) {
V_23 -> V_39 . integer =
F_13 ( V_23 -> V_39 . V_40 ) ;
F_11 ( ( V_38 , L_12 ,
V_23 -> V_39 . integer ) ) ;
}
F_5 ( L_13 , F_14 ( V_23 ) ) ;
}
F_5 ( L_14 ,
F_15 ( type ) , V_23 ,
V_23 -> V_33 ) ;
V_28 = V_5 ;
V_5 = 0 ;
V_25 = F_16 ( V_23 ) ;
V_5 = V_28 ;
if ( V_23 -> V_41 & V_42 ) {
F_5 ( L_15 ) ;
}
switch ( V_21 -> V_35 & V_43 ) {
case V_44 :
if ( ! V_25 ) {
switch ( type ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
F_5 ( L_16 ) ;
break;
default:
break;
}
F_5 ( L_6 ) ;
return ( V_31 ) ;
}
switch ( type ) {
case V_50 :
F_5 ( L_17 ,
V_25 -> V_51 . V_52 ,
V_25 -> V_51 . V_53 ,
F_17 ( void ,
V_25 -> V_51 .
V_54 ) ) ;
break;
case V_55 :
F_5 ( L_18 , V_25 ) ;
break;
case V_49 :
F_5 ( L_19 ,
( T_1 ) V_25 -> V_56 . V_57 ,
V_25 -> V_56 . V_58 ,
V_25 -> V_56 . V_59 ) ;
break;
case V_45 :
F_5 ( L_20 ,
F_18 ( V_25 -> integer .
V_60 ) ) ;
break;
case V_46 :
if ( V_25 -> V_61 . V_41 & V_62 ) {
F_5 ( L_21 ,
V_25 -> V_63 . V_64 ) ;
} else {
F_5 ( L_22 ) ;
}
break;
case V_47 :
if ( V_25 -> V_61 . V_41 & V_62 ) {
F_5 ( L_23 ,
V_25 -> V_65 . V_53 ) ;
if ( V_25 -> V_65 . V_53 > 0 ) {
F_5 ( L_24 ) ;
for ( V_3 = 0 ;
( V_3 < V_25 -> V_65 . V_53
&& V_3 < 12 ) ; V_3 ++ ) {
F_5 ( L_25 ,
V_25 -> V_65 .
V_66 [ V_3 ] ) ;
}
}
F_5 ( L_6 ) ;
} else {
F_5 ( L_22 ) ;
}
break;
case V_48 :
F_5 ( L_26 , V_25 -> string . V_53 ) ;
F_19 ( V_25 -> string . V_66 , 32 ) ;
F_5 ( L_6 ) ;
break;
case V_67 :
F_5 ( L_27 ,
F_20 ( V_25 -> V_68 .
V_69 ) ) ;
if ( V_25 -> V_68 . V_41 & V_62 ) {
F_5 ( L_28 ,
F_21
( V_25 -> V_68 . V_54 ) ,
V_25 -> V_68 . V_53 ) ;
} else {
F_5
( L_29 ) ;
}
break;
case V_70 :
F_5 ( L_30 ,
F_22 ( V_25 ) ) ;
break;
case V_71 :
if ( V_25 -> V_72 . V_73 &&
V_25 -> V_72 . V_73 -> V_65 . V_74 ) {
F_5 ( L_31 ,
F_14 ( V_25 ->
V_72 .
V_73 ->
V_65 .
V_74 ) ) ;
}
break;
case V_75 :
F_5 ( L_32 ,
F_14 ( V_25 ->
V_76 .
V_77 -> V_68 .
V_74 ) ) ;
break;
case V_78 :
F_5 ( L_33 ,
F_14 ( V_25 ->
V_76 .
V_77 -> V_68 .
V_74 ) ,
F_14 ( V_25 ->
V_79 .
V_80 ->
V_76 .
V_74 ) ) ;
break;
case V_81 :
F_5 ( L_34 ,
F_14 ( V_25 ->
V_82 .
V_83 ->
V_76 . V_74 ) ,
F_14 ( V_25 ->
V_82 .
V_84 ->
V_76 .
V_74 ) ) ;
break;
case V_85 :
case V_86 :
F_5 ( L_35 ,
F_14 ( V_25 ) ,
V_25 ) ;
break;
default:
F_5 ( L_36 , V_25 ) ;
break;
}
switch ( type ) {
case V_71 :
case V_75 :
case V_78 :
case V_81 :
F_5 ( L_37 ,
( V_25 -> V_76 .
V_87 * 8 )
+
V_25 -> V_76 .
V_88 ,
V_25 -> V_76 . V_89 ,
V_25 -> V_76 .
V_90 ) ;
break;
default:
break;
}
break;
case V_91 :
F_5 ( L_38 , V_25 ) ;
if ( ! V_25 ) {
F_5 ( L_6 ) ;
return ( V_31 ) ;
}
F_5 ( L_39 , V_25 -> V_61 . V_92 ) ;
switch ( type ) {
case V_49 :
F_5 ( L_40 , V_25 -> V_56 . V_59 ,
V_25 -> V_56 . V_58 ) ;
break;
case V_45 :
F_5 ( L_41 ,
F_18 ( V_25 -> integer .
V_60 ) ) ;
break;
case V_48 :
F_5 ( L_42 , V_25 -> string . V_66 ,
V_25 -> string . V_53 ) ;
break;
case V_47 :
F_5 ( L_43 , V_25 -> V_65 . V_66 ,
V_25 -> V_65 . V_53 ) ;
break;
default:
F_5 ( L_6 ) ;
break;
}
break;
default:
F_5 ( L_6 ) ;
break;
}
if ( ! ( V_5 & V_93 ) ) {
return ( V_31 ) ;
}
V_28 = V_5 ;
V_5 = 0 ;
V_25 = F_16 ( V_23 ) ;
V_5 = V_28 ;
while ( V_25 ) {
V_26 = V_94 ;
F_5 ( L_44 , V_25 ) ;
switch ( F_23 ( V_25 ) ) {
case V_95 :
F_5 ( L_45 ) ;
V_27 = sizeof( struct V_22 ) ;
F_24 ( V_25 , V_27 ) ;
break;
case V_96 :
V_26 = V_25 -> V_61 . type ;
if ( V_26 > V_37 ) {
F_5
( L_46 ,
V_26 ) ;
V_27 = 32 ;
} else {
F_5
( L_47 ,
V_26 , F_15 ( V_26 ) ) ;
V_27 =
sizeof( union V_24 ) ;
}
F_24 ( V_25 , V_27 ) ;
break;
default:
break;
}
if ( F_23 ( V_25 ) !=
V_96 ) {
goto V_97;
}
switch ( V_26 ) {
case V_47 :
case V_48 :
V_27 = V_25 -> string . V_53 ;
V_25 = ( void * ) V_25 -> string . V_66 ;
F_5 ( L_48 ,
V_25 , V_27 ) ;
F_24 ( V_25 , V_27 ) ;
goto V_97;
case V_71 :
V_25 =
(union V_24 * ) V_25 -> V_72 .
V_73 ;
break;
case V_46 :
V_25 = ( void * ) V_25 -> V_63 . V_98 ;
break;
case V_49 :
V_25 = ( void * ) V_25 -> V_56 . V_59 ;
break;
case V_75 :
V_25 = ( void * ) V_25 -> V_99 . V_77 ;
break;
case V_78 :
V_25 = ( void * ) V_25 -> V_79 . V_77 ;
break;
case V_81 :
V_25 = ( void * ) V_25 -> V_82 . V_83 ;
break;
default:
goto V_97;
}
V_26 = V_94 ;
}
V_97:
F_5 ( L_6 ) ;
return ( V_31 ) ;
}
void
F_25 ( T_4 type ,
T_5 V_35 ,
T_1 V_100 ,
T_6 V_33 , T_2 V_101 )
{
struct V_20 V_21 ;
T_3 V_102 ;
F_26 () ;
V_102 = F_27 ( V_103 ) ;
if ( F_28 ( V_102 ) ) {
F_5 ( L_49 ) ;
return;
}
V_21 . V_30 = V_104 ;
V_21 . V_33 = V_33 ;
V_21 . V_35 = V_35 ;
( void ) F_29 ( type , V_101 , V_100 ,
V_105 |
V_106 ,
F_9 , NULL ,
( void * ) & V_21 , NULL ) ;
( void ) F_30 ( V_103 ) ;
}
void F_31 ( T_2 V_11 , T_1 V_30 )
{
struct V_20 V_21 ;
F_26 () ;
V_21 . V_30 = V_30 ;
V_21 . V_33 = V_34 ;
V_21 . V_35 = V_44 ;
( void ) F_9 ( V_11 , 1 , & V_21 , NULL ) ;
}
void F_32 ( T_2 V_107 , T_1 V_100 )
{
T_2 V_108 = V_107 ;
F_7 ( V_109 ) ;
if ( ! V_110 ) {
F_3 ( ( V_111 ,
L_50 ) ) ;
V_16 ;
}
if ( V_112 == V_107 ) {
V_108 = V_110 ;
F_3 ( ( V_111 , L_51 ) ) ;
}
F_25 ( V_113 , V_91 , V_100 ,
V_34 , V_108 ) ;
V_16 ;
}
