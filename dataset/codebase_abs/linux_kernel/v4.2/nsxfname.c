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
if ( V_14 == V_19 ) {
V_4 = F_11 ( V_13 , V_16 ) ;
return ( V_4 ) ;
}
V_4 = F_12 ( V_20 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
V_4 = V_8 ;
goto V_21;
}
V_4 = F_13 ( V_16 , V_22 ) ;
if ( F_10 ( V_4 ) ) {
goto V_21;
}
V_17 = F_14 ( V_6 ) ;
F_15 ( V_16 -> V_23 , V_17 ) ;
( ( char * ) V_16 -> V_23 ) [ V_24 ] = 0 ;
V_4 = V_11 ;
V_21:
( void ) F_16 ( V_20 ) ;
return ( V_4 ) ;
}
static char * F_17 ( struct V_25 * V_26 ,
struct V_25 * V_27 ,
char * V_28 )
{
V_26 -> string = V_28 ;
V_26 -> V_29 = V_27 -> V_29 ;
memcpy ( V_28 , V_27 -> string , V_27 -> V_29 ) ;
return ( V_28 + V_27 -> V_29 ) ;
}
T_1
F_18 ( T_2 V_13 ,
struct V_30 * * V_31 )
{
struct V_5 * V_6 ;
struct V_30 * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_25 * V_35 = NULL ;
struct V_25 * V_36 = NULL ;
struct V_25 * V_37 = NULL ;
struct V_25 * V_38 = NULL ;
char * V_39 ;
T_5 type ;
T_6 V_40 ;
T_7 V_41 = 0 ;
T_8 V_42 = 0 ;
T_4 V_43 ;
T_4 V_44 ;
T_1 V_4 ;
if ( ! V_13 || ! V_31 ) {
return ( V_8 ) ;
}
V_4 = F_12 ( V_20 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
( void ) F_16 ( V_20 ) ;
return ( V_8 ) ;
}
V_43 = sizeof( struct V_30 ) ;
type = V_6 -> type ;
V_40 = V_6 -> V_40 . integer ;
if ( V_6 -> type == V_45 ) {
V_41 = V_6 -> V_46 -> V_47 . V_41 ;
}
V_4 = F_16 ( V_20 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( ( type == V_48 ) || ( type == V_49 ) ) {
V_4 = F_19 ( V_6 , & V_35 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_35 -> V_29 ;
V_42 |= V_50 ;
}
V_4 = F_20 ( V_6 , & V_36 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_36 -> V_29 ;
V_42 |= V_51 ;
}
V_4 = F_21 ( V_6 , & V_37 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_37 -> V_29 ;
V_42 |= V_52 ;
}
V_4 = F_22 ( V_6 , & V_34 ) ;
if ( F_7 ( V_4 ) ) {
V_43 +=
( V_34 -> V_53 -
sizeof( struct V_33 ) ) ;
V_42 |= V_54 ;
}
V_4 = F_23 ( V_6 , & V_38 ) ;
if ( F_7 ( V_4 ) ) {
V_43 += V_38 -> V_29 ;
V_42 |= V_55 ;
}
}
V_32 = F_24 ( V_43 ) ;
if ( ! V_32 ) {
V_4 = V_56 ;
goto V_57;
}
if ( ( type == V_48 ) || ( type == V_49 ) ) {
V_4 = F_25 ( V_6 , & V_32 -> V_58 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_59 ;
}
V_4 = F_26 ( V_60 , V_6 ,
& V_32 -> V_61 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_62 ;
}
V_4 = F_27 ( V_6 ,
V_63 ,
V_64 ,
V_32 -> V_65 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_66 ;
}
V_4 = F_27 ( V_6 ,
V_67 ,
V_68 ,
V_32 -> V_69 ) ;
if ( F_7 ( V_4 ) ) {
V_42 |= V_70 ;
}
}
V_39 = F_5 ( char , V_32 -> V_71 . V_72 ) ;
if ( V_34 ) {
V_39 +=
( ( V_73 ) V_34 -> V_74 *
sizeof( struct V_25 ) ) ;
}
if ( V_35 ) {
V_39 = F_17 ( & V_32 -> V_75 ,
V_35 , V_39 ) ;
if ( F_28 ( V_35 -> string ) ) {
V_32 -> V_76 |= V_77 ;
}
}
if ( V_36 ) {
V_39 = F_17 ( & V_32 -> V_78 ,
V_36 , V_39 ) ;
}
if ( V_37 ) {
V_39 = F_17 ( & V_32 -> V_79 ,
V_37 , V_39 ) ;
}
if ( V_34 ) {
V_32 -> V_71 . V_74 = V_34 -> V_74 ;
V_32 -> V_71 . V_53 = V_34 -> V_53 ;
for ( V_44 = 0 ; V_44 < V_34 -> V_74 ; V_44 ++ ) {
V_39 =
F_17 ( & V_32 -> V_71 .
V_72 [ V_44 ] , & V_34 -> V_72 [ V_44 ] ,
V_39 ) ;
if ( F_28 ( V_34 -> V_72 [ V_44 ] . string ) ) {
V_32 -> V_76 |= V_77 ;
}
}
}
if ( V_38 ) {
V_39 = F_17 ( & V_32 -> V_80 ,
V_38 , V_39 ) ;
}
V_32 -> V_43 = V_43 ;
V_32 -> type = type ;
V_32 -> V_40 = V_40 ;
V_32 -> V_41 = V_41 ;
V_32 -> V_42 = V_42 ;
* V_31 = V_32 ;
V_4 = V_11 ;
V_57:
if ( V_35 ) {
F_29 ( V_35 ) ;
}
if ( V_36 ) {
F_29 ( V_36 ) ;
}
if ( V_37 ) {
F_29 ( V_37 ) ;
}
if ( V_34 ) {
F_29 ( V_34 ) ;
}
if ( V_38 ) {
F_29 ( V_38 ) ;
}
return ( V_4 ) ;
}
T_1 F_30 ( T_7 * V_16 )
{
struct V_81 * V_82 =
F_5 ( struct V_81 , V_16 ) ;
T_7 * V_83 ;
T_7 * V_84 ;
char * V_85 ;
struct V_5 * V_6 ;
union V_86 * V_87 ;
struct V_88 V_89 ;
T_4 V_90 ;
T_8 V_91 ;
T_7 V_92 ;
T_1 V_4 ;
if ( ! V_16 ) {
return ( V_8 ) ;
}
if ( ! F_31 ( V_82 -> V_93 , V_94 ) &&
! F_31 ( V_82 -> V_93 , V_95 ) ) {
return ( V_96 ) ;
}
V_89 . V_97 = V_16 + sizeof( struct V_81 ) ;
V_91 = F_32 ( & V_89 ) ;
if ( V_91 != V_98 ) {
return ( V_8 ) ;
}
V_89 . V_97 += F_33 ( V_91 ) ;
V_89 . V_99 = F_34 ( & V_89 ) ;
V_85 = F_35 ( & V_89 ) ;
V_92 = * V_89 . V_97 ++ ;
V_84 = V_89 . V_97 ;
V_90 = F_36 ( V_89 . V_99 , V_84 ) ;
V_83 = F_37 ( V_90 ) ;
if ( ! V_83 ) {
return ( V_56 ) ;
}
V_87 = F_38 ( V_45 ) ;
if ( ! V_87 ) {
F_29 ( V_83 ) ;
return ( V_56 ) ;
}
V_4 = F_12 ( V_20 ) ;
if ( F_10 ( V_4 ) ) {
goto V_100;
}
V_4 =
F_39 ( NULL , V_85 , V_45 , V_101 ,
V_102 | V_103 ,
NULL , & V_6 ) ;
( void ) F_16 ( V_20 ) ;
if ( F_10 ( V_4 ) ) {
if ( V_4 != V_104 ) {
goto V_100;
}
if ( V_6 -> type != V_45 ) {
V_4 = V_105 ;
goto V_100;
}
}
memcpy ( V_83 , V_84 , V_90 ) ;
V_87 -> V_47 . V_84 = V_83 ;
V_87 -> V_47 . V_90 = V_90 ;
V_87 -> V_47 . V_41 = ( T_7 )
( V_92 & V_106 ) ;
if ( V_92 & V_107 ) {
V_87 -> V_47 . V_108 = V_109 ;
V_87 -> V_47 . V_110 = ( T_7 )
( ( V_92 & V_111 ) >> 4 ) ;
}
V_4 = F_40 ( V_6 , V_87 , V_45 ) ;
V_6 -> V_76 |= V_112 ;
F_41 ( V_87 ) ;
return ( V_4 ) ;
V_100:
F_29 ( V_83 ) ;
F_29 ( V_87 ) ;
return ( V_4 ) ;
}
