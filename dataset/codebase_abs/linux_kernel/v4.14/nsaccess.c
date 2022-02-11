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
F_7 ( NULL , F_8 ( char , V_3 -> V_17 ) ,
V_3 -> type , V_19 ,
V_20 , NULL , & V_5 ) ;
if ( F_4 ( V_1 ) ) {
F_9 ( ( V_21 , V_1 ,
L_3 ,
V_3 -> V_17 ) ) ;
continue;
}
if ( V_3 -> V_8 ) {
V_1 = F_10 ( V_3 , & V_8 ) ;
if ( F_4 ( V_1 ) ) {
F_11 ( ( V_21 ,
L_4 ,
V_3 -> V_17 ) ) ;
}
if ( ! V_8 ) {
V_8 = V_3 -> V_8 ;
}
V_7 =
F_12 ( V_3 -> type ) ;
if ( ! V_7 ) {
V_1 = V_22 ;
goto V_13;
}
switch ( V_3 -> type ) {
case V_23 :
V_7 -> V_24 . V_25 =
( V_26 ) F_13 ( V_8 ) ;
V_7 -> V_27 . V_28 |= V_29 ;
#if F_14 ( V_30 )
V_5 -> V_31 = V_7 -> V_24 . V_25 ;
#else
V_7 -> V_24 . V_32 =
V_33 ;
V_7 -> V_24 . V_34 . V_35 =
V_36 ;
#endif
break;
case V_37 :
V_7 -> integer . V_31 = F_13 ( V_8 ) ;
break;
case V_38 :
V_7 -> string . V_39 = ( V_40 ) strlen ( V_8 ) ;
V_7 -> string . V_41 = V_8 ;
V_7 -> V_27 . V_28 |= V_42 ;
break;
case V_43 :
V_7 -> V_44 . V_45 = V_5 ;
V_7 -> V_44 . V_46 =
( V_26 ) ( F_13 ( V_8 ) - 1 ) ;
V_1 =
F_15 ( & V_7 -> V_44 .
V_47 ) ;
if ( F_4 ( V_1 ) ) {
F_16 ( V_7 ) ;
goto V_13;
}
if ( strcmp ( V_3 -> V_17 , L_5 ) == 0 ) {
V_48 = V_7 ;
V_1 =
F_17 ( 1 , 0 ,
& V_49 ) ;
if ( F_4 ( V_1 ) ) {
F_16
( V_7 ) ;
goto V_13;
}
}
break;
default:
F_11 ( ( V_21 ,
L_6 ,
V_3 -> type ) ) ;
F_16 ( V_7 ) ;
V_7 = NULL ;
continue;
}
V_1 = F_18 ( V_5 , V_7 ,
V_7 -> V_27 . type ) ;
F_16 ( V_7 ) ;
}
}
V_13:
( void ) F_19 ( V_10 ) ;
if ( F_20 ( V_1 ) ) {
V_1 = F_21 ( NULL , L_7 , V_20 ,
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
char * V_59 ;
struct V_4 * V_60 ;
struct V_4 * V_61 = NULL ;
struct V_4 * V_62 = NULL ;
V_40 V_63 ;
V_40 V_64 ;
T_5 V_65 ;
T_3 V_66 ;
T_3 V_67 ;
V_40 V_68 = V_69 ;
V_40 V_70 ;
F_2 ( V_71 ) ;
if ( ! V_57 ) {
F_5 ( V_72 ) ;
}
V_70 = V_28 &
~ ( V_73 | V_74 |
V_69 ) ;
* V_57 = V_75 ;
V_76 ++ ;
if ( ! V_11 ) {
F_5 ( V_77 ) ;
}
if ( ( ! V_52 ) || ( ! V_52 -> V_78 . V_45 ) ) {
F_6 ( ( V_79 ,
L_8 ,
V_11 ) ) ;
V_60 = V_11 ;
} else {
V_60 = V_52 -> V_78 . V_45 ;
if ( F_22 ( V_60 ) !=
V_80 ) {
F_11 ( ( V_21 , L_9 ,
V_60 ,
F_23 ( V_60 ) ) ) ;
F_5 ( V_81 ) ;
}
if ( ! ( V_28 & V_82 ) ) {
while ( ! F_24 ( V_60 -> type ) &&
V_60 -> type != V_83 ) {
V_60 = V_60 -> V_84 ;
}
}
}
V_66 = type ;
if ( ! V_53 ) {
V_63 = 0 ;
V_62 = V_11 ;
V_58 = L_10 ;
F_6 ( ( V_79 ,
L_11 ,
V_28 ) ) ;
} else {
if ( * V_58 == ( V_26 ) V_85 ) {
V_62 = V_11 ;
V_68 = V_20 ;
V_58 ++ ;
F_6 ( ( V_79 ,
L_12 ,
V_62 ) ) ;
} else {
F_6 ( ( V_79 ,
L_13 ,
F_25 ( V_60 ) ,
V_60 ) ) ;
V_62 = V_60 ;
V_64 = 0 ;
while ( * V_58 == ( V_26 ) V_86 ) {
V_68 = V_20 ;
V_58 ++ ;
V_64 ++ ;
V_62 = V_62 -> V_84 ;
if ( ! V_62 ) {
V_1 =
F_26
( V_87 , V_53 , NULL ,
& V_59 ) ;
if ( F_20 ( V_1 ) ) {
F_11 ( ( V_21 ,
L_14 ,
V_59 ) ) ;
F_27 ( V_59 ) ;
}
F_5 ( V_88 ) ;
}
}
if ( V_68 == V_20 ) {
F_6 ( ( V_79 ,
L_15 ,
F_25
( V_62 ) , V_64 ) ) ;
}
}
switch ( * V_58 ) {
case 0 :
V_63 = 0 ;
type = V_62 -> type ;
F_6 ( ( V_79 ,
L_16 ,
V_28 ) ) ;
break;
case V_89 :
V_68 = V_20 ;
V_63 = 2 ;
V_58 ++ ;
F_6 ( ( V_79 ,
L_17 ,
V_28 ) ) ;
break;
case V_90 :
V_68 = V_20 ;
V_58 ++ ;
V_63 = ( V_40 ) ( V_26 ) * V_58 ;
V_58 ++ ;
F_6 ( ( V_79 ,
L_18 ,
V_63 , V_28 ) ) ;
break;
default:
V_63 = 1 ;
F_6 ( ( V_79 ,
L_19 ,
V_28 ) ) ;
break;
}
F_28 ( F_29 ( V_63 , V_58 ) ) ;
}
V_67 = V_83 ;
V_61 = V_62 ;
while ( V_63 && V_61 ) {
V_63 -- ;
if ( ! V_63 ) {
V_67 = type ;
if ( ( V_68 != V_20 ) &&
( V_28 & V_69 ) ) {
V_70 |= V_69 ;
}
if ( V_28 & V_73 ) {
V_70 |= V_73 ;
}
if ( V_28 & V_74 ) {
V_70 |= V_74 ;
}
}
F_30 ( & V_65 , V_58 ) ;
V_1 =
F_31 ( V_65 , V_56 ,
V_61 , V_54 ,
V_67 , V_70 ,
& V_62 ) ;
if ( F_4 ( V_1 ) ) {
if ( V_1 == V_88 ) {
F_6 ( ( V_79 ,
L_20 ,
( char * ) & V_65 ,
( char * ) & V_61 -> V_17 ,
V_61 ) ) ;
}
#ifdef V_30
if ( V_91 &&
( V_1 == V_92 ) &&
( ( V_62 -> V_28 & V_93 ) ||
( V_56
&& V_56 -> V_94 == V_95 ) ) ) {
V_62 -> V_28 &= ~ V_93 ;
V_62 -> type = ( V_26 ) V_67 ;
if ( V_56 -> V_94 != V_95 ) {
F_32
( V_62 ) ;
}
break;
}
#endif
* V_57 = V_62 ;
F_5 ( V_1 ) ;
}
if ( V_63 > 0 ) {
if ( V_62 -> type == V_96 ) {
if ( ! V_62 -> V_97 ) {
F_5 ( V_98 ) ;
}
if ( F_24
( ( (struct V_4 * )
V_62 -> V_97 ) -> type ) ) {
V_62 =
(struct V_4 * )
V_62 -> V_97 ;
}
}
#ifdef V_30
if ( ! V_91 &&
( V_62 -> V_28 & V_93 ) ) {
V_62 -> V_28 |= V_99 ;
}
#endif
}
else {
if ( ( V_66 != V_83 ) &&
( V_66 != V_96 ) &&
( V_66 != V_100 )
&& ( V_66 != V_101 )
&& ( V_62 -> type != V_83 )
&& ( V_62 -> type != V_66 ) ) {
F_33 ( ( V_21 ,
L_21 ,
F_8 ( char , & V_65 ) ,
F_34 ( V_62 ->
type ) ,
F_34
( V_66 ) ) ) ;
}
if ( type == V_83 ) {
type = V_62 -> type ;
}
}
V_58 += V_102 ;
V_61 = V_62 ;
}
if ( ! ( V_28 & V_103 ) && ( V_56 ) ) {
if ( F_24 ( type ) ) {
V_1 =
F_35 ( V_62 , type ,
V_56 ) ;
if ( F_4 ( V_1 ) ) {
F_5 ( V_1 ) ;
}
}
}
* V_57 = V_62 ;
F_5 ( V_12 ) ;
}
