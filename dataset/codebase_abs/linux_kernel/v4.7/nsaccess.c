T_1 F_1 ( void )
{
T_1 V_1 ;
const struct V_2 * V_3 = NULL ;
struct V_4 * V_5 ;
union V_6 * V_7 ;
T_2 V_8 = NULL ;
F_2 ( V_9 ) ;
V_1 = F_3 ( V_10 ) ;
if ( F_4 ( V_1 ) ) {
F_5 ( V_1 ) ;
}
if ( V_11 ) {
V_1 = V_12 ;
goto V_13;
}
V_11 = & V_14 ;
F_6 ( ( V_15 ,
L_1 ) ) ;
for ( V_3 = V_16 ; V_3 -> V_17 ; V_3 ++ ) {
if ( ! strcmp ( V_3 -> V_17 , L_2 )
&& ! V_18 ) {
continue;
}
V_1 =
F_7 ( NULL , ( char * ) V_3 -> V_17 , V_3 -> type ,
V_19 , V_20 ,
NULL , & V_5 ) ;
if ( F_4 ( V_1 ) ) {
F_8 ( ( V_21 , V_1 ,
L_3 ,
V_3 -> V_17 ) ) ;
continue;
}
if ( V_3 -> V_8 ) {
V_1 = F_9 ( V_3 , & V_8 ) ;
if ( F_4 ( V_1 ) ) {
F_10 ( ( V_21 ,
L_4 ,
V_3 -> V_17 ) ) ;
}
if ( ! V_8 ) {
V_8 = V_3 -> V_8 ;
}
V_7 =
F_11 ( V_3 -> type ) ;
if ( ! V_7 ) {
V_1 = V_22 ;
goto V_13;
}
switch ( V_3 -> type ) {
case V_23 :
V_7 -> V_24 . V_25 =
( V_26 ) F_12 ( V_8 ) ;
V_7 -> V_27 . V_28 |= V_29 ;
#if F_13 ( V_30 )
V_5 -> V_31 = V_7 -> V_24 . V_25 ;
#else
V_7 -> V_24 . V_32 =
V_33 ;
V_7 -> V_24 . V_34 . V_35 =
V_36 ;
#endif
break;
case V_37 :
V_7 -> integer . V_31 = F_12 ( V_8 ) ;
break;
case V_38 :
V_7 -> string . V_39 = ( V_40 ) strlen ( V_8 ) ;
V_7 -> string . V_41 = V_8 ;
V_7 -> V_27 . V_28 |= V_42 ;
break;
case V_43 :
V_7 -> V_44 . V_45 = V_5 ;
V_7 -> V_44 . V_46 =
( V_26 ) ( F_12 ( V_8 ) - 1 ) ;
V_1 =
F_14 ( & V_7 -> V_44 .
V_47 ) ;
if ( F_4 ( V_1 ) ) {
F_15 ( V_7 ) ;
goto V_13;
}
if ( strcmp ( V_3 -> V_17 , L_5 ) == 0 ) {
V_48 = V_7 ;
V_1 =
F_16 ( 1 , 0 ,
& V_49 ) ;
if ( F_4 ( V_1 ) ) {
F_15
( V_7 ) ;
goto V_13;
}
}
break;
default:
F_10 ( ( V_21 ,
L_6 ,
V_3 -> type ) ) ;
F_15 ( V_7 ) ;
V_7 = NULL ;
continue;
}
V_1 = F_17 ( V_5 , V_7 ,
V_7 -> V_27 . type ) ;
F_15 ( V_7 ) ;
}
}
V_13:
( void ) F_18 ( V_10 ) ;
if ( F_19 ( V_1 ) ) {
V_1 = F_20 ( NULL , L_7 , V_20 ,
& V_50 ) ;
}
F_5 ( V_1 ) ;
}
T_1
F_7 ( union V_51 * V_52 ,
char * V_53 ,
T_3 type ,
T_4 V_54 ,
V_40 V_28 ,
struct V_55 * V_56 ,
struct V_4 * * V_57 )
{
T_1 V_1 ;
char * V_58 = V_53 ;
struct V_4 * V_59 ;
struct V_4 * V_60 = NULL ;
struct V_4 * V_61 = NULL ;
V_40 V_62 ;
V_40 V_63 ;
T_5 V_64 ;
T_3 V_65 ;
T_3 V_66 ;
V_40 V_67 = V_68 ;
V_40 V_69 ;
F_2 ( V_70 ) ;
if ( ! V_57 ) {
F_5 ( V_71 ) ;
}
V_69 = V_28 &
~ ( V_72 | V_73 |
V_68 ) ;
* V_57 = V_74 ;
V_75 ++ ;
if ( ! V_11 ) {
F_5 ( V_76 ) ;
}
if ( ( ! V_52 ) || ( ! V_52 -> V_77 . V_45 ) ) {
F_6 ( ( V_78 ,
L_8 ,
V_11 ) ) ;
V_59 = V_11 ;
} else {
V_59 = V_52 -> V_77 . V_45 ;
if ( F_21 ( V_59 ) !=
V_79 ) {
F_10 ( ( V_21 , L_9 ,
V_59 ,
F_22 ( V_59 ) ) ) ;
F_5 ( V_80 ) ;
}
if ( ! ( V_28 & V_81 ) ) {
while ( ! F_23 ( V_59 -> type ) &&
V_59 -> type != V_82 ) {
V_59 = V_59 -> V_83 ;
}
}
}
V_65 = type ;
if ( ! V_53 ) {
V_62 = 0 ;
V_61 = V_11 ;
V_58 = L_10 ;
F_6 ( ( V_78 ,
L_11 ,
V_28 ) ) ;
} else {
if ( * V_58 == ( V_26 ) V_84 ) {
V_61 = V_11 ;
V_67 = V_20 ;
V_58 ++ ;
F_6 ( ( V_78 ,
L_12 ,
V_61 ) ) ;
} else {
F_6 ( ( V_78 ,
L_13 ,
F_24 ( V_59 ) ,
V_59 ) ) ;
V_61 = V_59 ;
V_63 = 0 ;
while ( * V_58 == ( V_26 ) V_85 ) {
V_67 = V_20 ;
V_58 ++ ;
V_63 ++ ;
V_61 = V_61 -> V_83 ;
if ( ! V_61 ) {
F_10 ( ( V_21 ,
L_14
L_15 ,
V_53 ) ) ;
F_5 ( V_86 ) ;
}
}
if ( V_67 == V_20 ) {
F_6 ( ( V_78 ,
L_16 ,
F_24
( V_61 ) , V_63 ) ) ;
}
}
switch ( * V_58 ) {
case 0 :
V_62 = 0 ;
type = V_61 -> type ;
F_6 ( ( V_78 ,
L_17 ,
V_28 ) ) ;
break;
case V_87 :
V_67 = V_20 ;
V_62 = 2 ;
V_58 ++ ;
F_6 ( ( V_78 ,
L_18 ,
V_28 ) ) ;
break;
case V_88 :
V_67 = V_20 ;
V_58 ++ ;
V_62 = ( V_40 ) ( V_26 ) * V_58 ;
V_58 ++ ;
F_6 ( ( V_78 ,
L_19 ,
V_62 , V_28 ) ) ;
break;
default:
V_62 = 1 ;
F_6 ( ( V_78 ,
L_20 ,
V_28 ) ) ;
break;
}
F_25 ( F_26 ( V_62 , V_58 ) ) ;
}
V_66 = V_82 ;
V_60 = V_61 ;
while ( V_62 && V_60 ) {
V_62 -- ;
if ( ! V_62 ) {
V_66 = type ;
if ( ( V_67 != V_20 ) &&
( V_28 & V_68 ) ) {
V_69 |= V_68 ;
}
if ( V_28 & V_72 ) {
V_69 |= V_72 ;
}
if ( V_28 & V_73 ) {
V_69 |= V_73 ;
}
}
F_27 ( & V_64 , V_58 ) ;
V_1 =
F_28 ( V_64 , V_56 ,
V_60 , V_54 ,
V_66 , V_69 ,
& V_61 ) ;
if ( F_4 ( V_1 ) ) {
if ( V_1 == V_86 ) {
F_6 ( ( V_78 ,
L_21 ,
( char * ) & V_64 ,
( char * ) & V_60 -> V_17 ,
V_60 ) ) ;
}
* V_57 = V_61 ;
F_5 ( V_1 ) ;
}
if ( V_62 > 0 ) {
if ( V_61 -> type == V_89 ) {
if ( ! V_61 -> V_90 ) {
F_5 ( V_91 ) ;
}
if ( F_23
( ( (struct V_4 * )
V_61 -> V_90 ) -> type ) ) {
V_61 =
(struct V_4 * )
V_61 -> V_90 ;
}
}
}
else {
if ( ( V_65 != V_82 ) &&
( V_65 != V_89 ) &&
( V_65 != V_92 )
&& ( V_65 != V_93 )
&& ( V_61 -> type != V_82 )
&& ( V_61 -> type != V_65 ) ) {
F_29 ( ( V_21 ,
L_22 ,
F_30 ( char , & V_64 ) ,
F_31 ( V_61 ->
type ) ,
F_31
( V_65 ) ) ) ;
}
if ( type == V_82 ) {
type = V_61 -> type ;
}
}
V_58 += V_94 ;
V_60 = V_61 ;
}
if ( ! ( V_28 & V_95 ) && ( V_56 ) ) {
if ( F_23 ( type ) ) {
V_1 =
F_32 ( V_61 , type ,
V_56 ) ;
if ( F_4 ( V_1 ) ) {
F_5 ( V_1 ) ;
}
}
}
* V_57 = V_61 ;
F_5 ( V_12 ) ;
}
