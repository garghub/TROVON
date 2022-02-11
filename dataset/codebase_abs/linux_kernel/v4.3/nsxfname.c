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
char * V_17 ;
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
struct V_26 * V_39 = NULL ;
char * V_40 ;
T_5 type ;
T_6 V_41 ;
T_7 V_42 = 0 ;
T_8 V_43 = 0 ;
T_4 V_44 ;
T_4 V_45 ;
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
V_44 = sizeof( struct V_31 ) ;
type = V_6 -> type ;
V_41 = V_6 -> V_41 . integer ;
if ( V_6 -> type == V_46 ) {
V_42 = V_6 -> V_47 -> V_48 . V_42 ;
}
V_4 = F_16 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( ( type == V_49 ) || ( type == V_50 ) ) {
V_4 = F_19 ( V_6 , & V_36 ) ;
if ( F_7 ( V_4 ) ) {
V_44 += V_36 -> V_30 ;
V_43 |= V_51 ;
}
V_4 = F_20 ( V_6 , & V_37 ) ;
if ( F_7 ( V_4 ) ) {
V_44 += V_37 -> V_30 ;
V_43 |= V_52 ;
}
V_4 = F_21 ( V_6 , & V_38 ) ;
if ( F_7 ( V_4 ) ) {
V_44 += V_38 -> V_30 ;
V_43 |= V_53 ;
}
V_4 = F_22 ( V_6 , & V_35 ) ;
if ( F_7 ( V_4 ) ) {
V_44 +=
( V_35 -> V_54 -
sizeof( struct V_34 ) ) ;
V_43 |= V_55 ;
}
V_4 = F_23 ( V_6 , & V_39 ) ;
if ( F_7 ( V_4 ) ) {
V_44 += V_39 -> V_30 ;
V_43 |= V_56 ;
}
}
V_33 = F_24 ( V_44 ) ;
if ( ! V_33 ) {
V_4 = V_57 ;
goto V_58;
}
if ( ( type == V_49 ) || ( type == V_50 ) ) {
V_4 = F_25 ( V_6 , & V_33 -> V_59 ) ;
if ( F_7 ( V_4 ) ) {
V_43 |= V_60 ;
}
V_4 = F_26 ( V_61 , V_6 ,
& V_33 -> V_62 ) ;
if ( F_7 ( V_4 ) ) {
V_43 |= V_63 ;
}
V_4 = F_27 ( V_6 ,
V_64 ,
V_65 ,
V_33 -> V_66 ) ;
if ( F_7 ( V_4 ) ) {
V_43 |= V_67 ;
}
V_4 = F_27 ( V_6 ,
V_68 ,
V_69 ,
V_33 -> V_70 ) ;
if ( F_7 ( V_4 ) ) {
V_43 |= V_71 ;
}
}
V_40 = F_5 ( char , V_33 -> V_72 . V_73 ) ;
if ( V_35 ) {
V_40 +=
( ( V_74 ) V_35 -> V_75 *
sizeof( struct V_26 ) ) ;
}
if ( V_36 ) {
V_40 = F_17 ( & V_33 -> V_76 ,
V_36 , V_40 ) ;
if ( F_28 ( V_36 -> string ) ) {
V_33 -> V_77 |= V_78 ;
}
}
if ( V_37 ) {
V_40 = F_17 ( & V_33 -> V_79 ,
V_37 , V_40 ) ;
}
if ( V_38 ) {
V_40 = F_17 ( & V_33 -> V_80 ,
V_38 , V_40 ) ;
}
if ( V_35 ) {
V_33 -> V_72 . V_75 = V_35 -> V_75 ;
V_33 -> V_72 . V_54 = V_35 -> V_54 ;
for ( V_45 = 0 ; V_45 < V_35 -> V_75 ; V_45 ++ ) {
V_40 =
F_17 ( & V_33 -> V_72 .
V_73 [ V_45 ] , & V_35 -> V_73 [ V_45 ] ,
V_40 ) ;
if ( F_28 ( V_35 -> V_73 [ V_45 ] . string ) ) {
V_33 -> V_77 |= V_78 ;
}
}
}
if ( V_39 ) {
V_40 = F_17 ( & V_33 -> V_81 ,
V_39 , V_40 ) ;
}
V_33 -> V_44 = V_44 ;
V_33 -> type = type ;
V_33 -> V_41 = V_41 ;
V_33 -> V_42 = V_42 ;
V_33 -> V_43 = V_43 ;
* V_32 = V_33 ;
V_4 = V_11 ;
V_58:
if ( V_36 ) {
F_29 ( V_36 ) ;
}
if ( V_37 ) {
F_29 ( V_37 ) ;
}
if ( V_38 ) {
F_29 ( V_38 ) ;
}
if ( V_35 ) {
F_29 ( V_35 ) ;
}
if ( V_39 ) {
F_29 ( V_39 ) ;
}
return ( V_4 ) ;
}
T_1 F_30 ( T_7 * V_16 )
{
struct V_82 * V_83 =
F_5 ( struct V_82 , V_16 ) ;
T_7 * V_84 ;
T_7 * V_85 ;
char * V_86 ;
struct V_5 * V_6 ;
union V_87 * V_88 ;
struct V_89 V_90 ;
T_4 V_91 ;
T_8 V_92 ;
T_7 V_93 ;
T_1 V_4 ;
if ( ! V_16 ) {
return ( V_8 ) ;
}
if ( ! F_31 ( V_83 -> V_94 , V_95 ) &&
! F_31 ( V_83 -> V_94 , V_96 ) ) {
return ( V_97 ) ;
}
V_90 . V_98 = V_16 + sizeof( struct V_82 ) ;
V_92 = F_32 ( & V_90 ) ;
if ( V_92 != V_99 ) {
return ( V_8 ) ;
}
V_90 . V_98 += F_33 ( V_92 ) ;
V_90 . V_100 = F_34 ( & V_90 ) ;
V_86 = F_35 ( & V_90 ) ;
V_93 = * V_90 . V_98 ++ ;
V_85 = V_90 . V_98 ;
V_91 = F_36 ( V_90 . V_100 , V_85 ) ;
V_84 = F_37 ( V_91 ) ;
if ( ! V_84 ) {
return ( V_57 ) ;
}
V_88 = F_38 ( V_46 ) ;
if ( ! V_88 ) {
F_29 ( V_84 ) ;
return ( V_57 ) ;
}
V_4 = F_12 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
goto V_101;
}
V_4 =
F_39 ( NULL , V_86 , V_46 , V_102 ,
V_103 | V_104 ,
NULL , & V_6 ) ;
( void ) F_16 ( V_21 ) ;
if ( F_10 ( V_4 ) ) {
if ( V_4 != V_105 ) {
goto V_101;
}
if ( V_6 -> type != V_46 ) {
V_4 = V_106 ;
goto V_101;
}
}
memcpy ( V_84 , V_85 , V_91 ) ;
V_88 -> V_48 . V_85 = V_84 ;
V_88 -> V_48 . V_91 = V_91 ;
V_88 -> V_48 . V_42 = ( T_7 )
( V_93 & V_107 ) ;
if ( V_93 & V_108 ) {
V_88 -> V_48 . V_109 = V_110 ;
V_88 -> V_48 . V_111 = ( T_7 )
( ( V_93 & V_112 ) >> 4 ) ;
}
V_4 = F_40 ( V_6 , V_88 , V_46 ) ;
V_6 -> V_77 |= V_113 ;
F_41 ( V_88 ) ;
return ( V_4 ) ;
V_101:
F_29 ( V_84 ) ;
F_29 ( V_88 ) ;
return ( V_4 ) ;
}
