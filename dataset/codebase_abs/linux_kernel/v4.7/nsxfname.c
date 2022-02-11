T_1
F_1 ( T_2 V_1 ,
T_3 V_2 , T_2 * V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_7 = NULL ;
F_2 () ;
if ( ! V_3 || ! V_2 ) {
return ( V_8 ) ;
}
if ( V_1 ) {
V_7 = F_3 ( V_1 ) ;
if ( ! V_7 ) {
return ( V_8 ) ;
}
}
if ( F_4 ( V_2 [ 0 ] ) ) {
if ( ! strcmp ( V_2 , V_9 ) ) {
* V_3 =
F_5 ( T_2 , V_10 ) ;
return ( V_11 ) ;
}
} else if ( ! V_7 ) {
return ( V_8 ) ;
}
V_4 =
F_6 ( V_7 , V_2 , V_12 , & V_6 ) ;
if ( F_7 ( V_4 ) ) {
* V_3 = F_5 ( T_2 , V_6 ) ;
}
return ( V_4 ) ;
}
T_1
F_8 ( T_2 V_13 , T_4 V_14 , struct V_15 * V_16 )
{
T_1 V_4 ;
struct V_5 * V_6 ;
const char * V_17 ;
if ( V_14 > V_18 ) {
return ( V_8 ) ;
}
V_4 = F_9 ( V_16 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( V_14 == V_19 ||
V_14 == V_20 ) {
V_4 = F_11 ( V_13 , V_16 ,
V_14 ==
V_19 ? FALSE :
TRUE ) ;
return ( V_4 ) ;
}
V_4 = F_12 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
V_4 = V_8 ;
goto V_22;
}
V_4 = F_13 ( V_16 , V_23 ) ;
if ( F_10 ( V_4 ) ) {
goto V_22;
}
V_17 = F_14 ( V_6 ) ;
F_15 ( V_16 -> V_24 , V_17 ) ;
( ( char * ) V_16 -> V_24 ) [ V_25 ] = 0 ;
V_4 = V_11 ;
V_22:
( void ) F_16 ( V_21 ) ;
return ( V_4 ) ;
}
static char * F_17 ( struct V_26 * V_27 ,
struct V_26 * V_28 ,
char * V_29 )
{
V_27 -> string = V_29 ;
V_27 -> V_30 = V_28 -> V_30 ;
memcpy ( V_29 , V_28 -> string , V_28 -> V_30 ) ;
return ( V_29 + V_28 -> V_30 ) ;
}
T_1
F_18 ( T_2 V_13 ,
struct V_31 * * V_32 )
{
struct V_5 * V_6 ;
struct V_31 * V_33 ;
struct V_34 * V_35 = NULL ;
struct V_26 * V_36 = NULL ;
struct V_26 * V_37 = NULL ;
struct V_26 * V_38 = NULL ;
char * V_39 ;
T_5 type ;
T_6 V_40 ;
T_7 V_41 = 0 ;
T_8 V_42 = 0 ;
T_4 V_43 ;
T_4 V_44 ;
T_1 V_4 ;
if ( ! V_13 || ! V_32 ) {
return ( V_8 ) ;
}
V_4 = F_12 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
( void ) F_16 ( V_21 ) ;
return ( V_8 ) ;
}
V_43 = sizeof( struct V_31 ) ;
type = V_6 -> type ;
V_40 = V_6 -> V_40 . integer ;
if ( V_6 -> type == V_45 ) {
V_41 = V_6 -> V_46 -> V_47 . V_41 ;
}
V_4 = F_16 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( ( type == V_48 ) || ( type == V_49 ) ) {
V_4 = F_19 ( V_6 , & V_36 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_36 -> V_30 ;
V_42 |= V_50 ;
}
V_4 = F_20 ( V_6 , & V_37 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_37 -> V_30 ;
V_42 |= V_51 ;
}
V_4 = F_21 ( V_6 , & V_35 ) ;
if ( F_7 ( V_4 ) ) {
V_43 +=
( V_35 -> V_52 -
sizeof( struct V_34 ) ) ;
V_42 |= V_53 ;
}
V_4 = F_22 ( V_6 , & V_38 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_38 -> V_30 ;
V_42 |= V_54 ;
}
}
V_33 = F_23 ( V_43 ) ;
if ( ! V_33 ) {
V_4 = V_55 ;
goto V_56;
}
if ( ( type == V_48 ) || ( type == V_49 ) ) {
V_4 = F_24 ( V_6 , & V_33 -> V_57 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_58 ;
}
V_4 = F_25 ( V_59 , V_6 ,
& V_33 -> V_60 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_61 ;
}
V_4 = F_26 ( V_6 ,
V_62 ,
V_63 ,
V_33 -> V_64 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_65 ;
}
V_4 = F_26 ( V_6 ,
V_66 ,
V_67 ,
V_33 -> V_68 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_69 ;
}
}
V_39 = F_5 ( char , V_33 -> V_70 . V_71 ) ;
if ( V_35 ) {
V_39 +=
( ( V_72 ) V_35 -> V_73 *
sizeof( struct V_26 ) ) ;
}
if ( V_36 ) {
V_39 = F_17 ( & V_33 -> V_74 ,
V_36 , V_39 ) ;
if ( F_27 ( V_36 -> string ) ) {
V_33 -> V_75 |= V_76 ;
}
}
if ( V_37 ) {
V_39 = F_17 ( & V_33 -> V_77 ,
V_37 , V_39 ) ;
}
if ( V_35 ) {
V_33 -> V_70 . V_73 = V_35 -> V_73 ;
V_33 -> V_70 . V_52 = V_35 -> V_52 ;
for ( V_44 = 0 ; V_44 < V_35 -> V_73 ; V_44 ++ ) {
V_39 =
F_17 ( & V_33 -> V_70 .
V_71 [ V_44 ] , & V_35 -> V_71 [ V_44 ] ,
V_39 ) ;
if ( F_27 ( V_35 -> V_71 [ V_44 ] . string ) ) {
V_33 -> V_75 |= V_76 ;
}
}
}
if ( V_38 ) {
V_39 = F_17 ( & V_33 -> V_78 ,
V_38 , V_39 ) ;
}
V_33 -> V_43 = V_43 ;
V_33 -> type = type ;
V_33 -> V_40 = V_40 ;
V_33 -> V_41 = V_41 ;
V_33 -> V_42 = V_42 ;
* V_32 = V_33 ;
V_4 = V_11 ;
V_56:
if ( V_36 ) {
F_28 ( V_36 ) ;
}
if ( V_37 ) {
F_28 ( V_37 ) ;
}
if ( V_35 ) {
F_28 ( V_35 ) ;
}
if ( V_38 ) {
F_28 ( V_38 ) ;
}
return ( V_4 ) ;
}
T_1 F_29 ( T_7 * V_16 )
{
struct V_79 * V_80 =
F_5 ( struct V_79 , V_16 ) ;
T_7 * V_81 ;
T_7 * V_82 ;
char * V_83 ;
struct V_5 * V_6 ;
union V_84 * V_85 ;
struct V_86 V_87 ;
T_4 V_88 ;
T_8 V_89 ;
T_7 V_90 ;
T_1 V_4 ;
if ( ! V_16 ) {
return ( V_8 ) ;
}
if ( ! F_30 ( V_80 -> V_91 , V_92 ) &&
! F_30 ( V_80 -> V_91 , V_93 ) ) {
return ( V_94 ) ;
}
V_87 . V_95 = V_16 + sizeof( struct V_79 ) ;
V_89 = F_31 ( & V_87 ) ;
if ( V_89 != V_96 ) {
return ( V_8 ) ;
}
V_87 . V_95 += F_32 ( V_89 ) ;
V_87 . V_97 = F_33 ( & V_87 ) ;
V_83 = F_34 ( & V_87 ) ;
V_90 = * V_87 . V_95 ++ ;
V_82 = V_87 . V_95 ;
V_88 = F_35 ( V_87 . V_97 , V_82 ) ;
V_81 = F_36 ( V_88 ) ;
if ( ! V_81 ) {
return ( V_55 ) ;
}
V_85 = F_37 ( V_45 ) ;
if ( ! V_85 ) {
F_28 ( V_81 ) ;
return ( V_55 ) ;
}
V_4 = F_12 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
goto V_98;
}
V_4 =
F_38 ( NULL , V_83 , V_45 , V_99 ,
V_100 | V_101 ,
NULL , & V_6 ) ;
( void ) F_16 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
if ( V_4 != V_102 ) {
goto V_98;
}
if ( V_6 -> type != V_45 ) {
V_4 = V_103 ;
goto V_98;
}
}
memcpy ( V_81 , V_82 , V_88 ) ;
V_85 -> V_47 . V_82 = V_81 ;
V_85 -> V_47 . V_88 = V_88 ;
V_85 -> V_47 . V_41 = ( T_7 )
( V_90 & V_104 ) ;
if ( V_90 & V_105 ) {
V_85 -> V_47 . V_106 = V_107 ;
V_85 -> V_47 . V_108 = ( T_7 )
( ( V_90 & V_109 ) >> 4 ) ;
}
V_4 = F_39 ( V_6 , V_85 , V_45 ) ;
V_6 -> V_75 |= V_110 ;
F_40 ( V_85 ) ;
return ( V_4 ) ;
V_98:
F_28 ( V_81 ) ;
F_28 ( V_85 ) ;
return ( V_4 ) ;
}
