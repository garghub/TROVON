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
if ( ! F_5 ( V_2 , V_9 ) ) {
* V_3 =
F_6 ( T_2 , V_10 ) ;
return ( V_11 ) ;
}
} else if ( ! V_7 ) {
return ( V_8 ) ;
}
V_4 =
F_7 ( V_7 , V_2 , V_12 , & V_6 ) ;
if ( F_8 ( V_4 ) ) {
* V_3 = F_6 ( T_2 , V_6 ) ;
}
return ( V_4 ) ;
}
T_1
F_9 ( T_2 V_13 , T_4 V_14 , struct V_15 * V_16 )
{
T_1 V_4 ;
struct V_5 * V_6 ;
char * V_17 ;
if ( V_14 > V_18 ) {
return ( V_8 ) ;
}
V_4 = F_10 ( V_16 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( V_14 == V_19 ) {
V_4 = F_12 ( V_13 , V_16 ) ;
return ( V_4 ) ;
}
V_4 = F_13 ( V_20 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
V_4 = V_8 ;
goto V_21;
}
V_4 = F_14 ( V_16 , V_22 ) ;
if ( F_11 ( V_4 ) ) {
goto V_21;
}
V_17 = F_15 ( V_6 ) ;
F_16 ( V_16 -> V_23 , V_17 ) ;
( ( char * ) V_16 -> V_23 ) [ V_24 ] = 0 ;
V_4 = V_11 ;
V_21:
( void ) F_17 ( V_20 ) ;
return ( V_4 ) ;
}
static char * F_18 ( struct V_25 * V_26 ,
struct V_25 * V_27 ,
char * V_28 )
{
V_26 -> string = V_28 ;
V_26 -> V_29 = V_27 -> V_29 ;
F_19 ( V_28 , V_27 -> string , V_27 -> V_29 ) ;
return ( V_28 + V_27 -> V_29 ) ;
}
T_1
F_20 ( T_2 V_13 ,
struct V_30 * * V_31 )
{
struct V_5 * V_6 ;
struct V_30 * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_25 * V_35 = NULL ;
struct V_25 * V_36 = NULL ;
struct V_25 * V_37 = NULL ;
char * V_38 ;
T_5 type ;
T_6 V_39 ;
T_7 V_40 = 0 ;
T_7 V_41 = 0 ;
T_4 V_42 ;
T_4 V_43 ;
T_1 V_4 ;
if ( ! V_13 || ! V_31 ) {
return ( V_8 ) ;
}
V_4 = F_13 ( V_20 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
( void ) F_17 ( V_20 ) ;
return ( V_8 ) ;
}
V_42 = sizeof( struct V_30 ) ;
type = V_6 -> type ;
V_39 = V_6 -> V_39 . integer ;
if ( V_6 -> type == V_44 ) {
V_40 = V_6 -> V_45 -> V_46 . V_40 ;
}
V_4 = F_17 ( V_20 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( ( type == V_47 ) || ( type == V_48 ) ) {
V_4 = F_21 ( V_6 , & V_35 ) ;
if ( F_8 ( V_4 ) ) {
V_42 += V_35 -> V_29 ;
V_41 |= V_49 ;
}
V_4 = F_22 ( V_6 , & V_36 ) ;
if ( F_8 ( V_4 ) ) {
V_42 += V_36 -> V_29 ;
V_41 |= V_50 ;
}
V_4 = F_23 ( V_6 , & V_37 ) ;
if ( F_8 ( V_4 ) ) {
V_42 += V_37 -> V_29 ;
V_41 |= V_51 ;
}
V_4 = F_24 ( V_6 , & V_34 ) ;
if ( F_8 ( V_4 ) ) {
V_42 +=
( V_34 -> V_52 -
sizeof( struct V_33 ) ) ;
V_41 |= V_53 ;
}
}
V_32 = F_25 ( V_42 ) ;
if ( ! V_32 ) {
V_4 = V_54 ;
goto V_55;
}
if ( ( type == V_47 ) || ( type == V_48 ) ) {
V_4 = F_26 ( V_6 , & V_32 -> V_56 ) ;
if ( F_8 ( V_4 ) ) {
V_41 |= V_57 ;
}
V_4 = F_27 ( V_58 , V_6 ,
& V_32 -> V_59 ) ;
if ( F_8 ( V_4 ) ) {
V_41 |= V_60 ;
}
V_4 = F_28 ( V_6 ,
V_61 ,
V_62 ,
V_32 -> V_63 ) ;
if ( F_8 ( V_4 ) ) {
V_41 |= V_64 ;
}
V_4 = F_28 ( V_6 ,
V_65 ,
V_66 ,
V_32 -> V_67 ) ;
if ( F_8 ( V_4 ) ) {
V_41 |= V_68 ;
}
}
V_38 = F_6 ( char , V_32 -> V_69 . V_70 ) ;
if ( V_34 ) {
V_38 +=
( ( V_71 ) V_34 -> V_72 *
sizeof( struct V_25 ) ) ;
}
if ( V_35 ) {
V_38 = F_18 ( & V_32 -> V_73 ,
V_35 , V_38 ) ;
if ( F_29 ( V_35 -> string ) ) {
V_32 -> V_74 |= V_75 ;
}
}
if ( V_36 ) {
V_38 = F_18 ( & V_32 -> V_76 ,
V_36 , V_38 ) ;
}
if ( V_37 ) {
V_38 = F_18 ( & V_32 -> V_77 ,
V_37 , V_38 ) ;
}
if ( V_34 ) {
V_32 -> V_69 . V_72 = V_34 -> V_72 ;
V_32 -> V_69 . V_52 = V_34 -> V_52 ;
for ( V_43 = 0 ; V_43 < V_34 -> V_72 ; V_43 ++ ) {
V_38 =
F_18 ( & V_32 -> V_69 .
V_70 [ V_43 ] , & V_34 -> V_70 [ V_43 ] ,
V_38 ) ;
if ( F_29 ( V_34 -> V_70 [ V_43 ] . string ) ) {
V_32 -> V_74 |= V_75 ;
}
}
}
V_32 -> V_42 = V_42 ;
V_32 -> type = type ;
V_32 -> V_39 = V_39 ;
V_32 -> V_40 = V_40 ;
V_32 -> V_41 = V_41 ;
* V_31 = V_32 ;
V_4 = V_11 ;
V_55:
if ( V_35 ) {
F_30 ( V_35 ) ;
}
if ( V_36 ) {
F_30 ( V_36 ) ;
}
if ( V_37 ) {
F_30 ( V_37 ) ;
}
if ( V_34 ) {
F_30 ( V_34 ) ;
}
return ( V_4 ) ;
}
T_1 F_31 ( T_7 * V_16 )
{
struct V_78 * V_79 =
F_6 ( struct V_78 , V_16 ) ;
T_7 * V_80 ;
T_7 * V_81 ;
char * V_82 ;
struct V_5 * V_6 ;
union V_83 * V_84 ;
struct V_85 V_86 ;
T_4 V_87 ;
T_8 V_88 ;
T_7 V_89 ;
T_1 V_4 ;
if ( ! V_16 ) {
return ( V_8 ) ;
}
if ( ! F_32 ( V_79 -> V_90 , V_91 ) &&
! F_32 ( V_79 -> V_90 , V_92 ) ) {
return ( V_93 ) ;
}
V_86 . V_94 = V_16 + sizeof( struct V_78 ) ;
V_88 = F_33 ( & V_86 ) ;
if ( V_88 != V_95 ) {
return ( V_8 ) ;
}
V_86 . V_94 += F_34 ( V_88 ) ;
V_86 . V_96 = F_35 ( & V_86 ) ;
V_82 = F_36 ( & V_86 ) ;
V_89 = * V_86 . V_94 ++ ;
V_81 = V_86 . V_94 ;
V_87 = F_37 ( V_86 . V_96 , V_81 ) ;
V_80 = F_38 ( V_87 ) ;
if ( ! V_80 ) {
return ( V_54 ) ;
}
V_84 = F_39 ( V_44 ) ;
if ( ! V_84 ) {
F_30 ( V_80 ) ;
return ( V_54 ) ;
}
V_4 = F_13 ( V_20 ) ;
if ( F_11 ( V_4 ) ) {
goto V_97;
}
V_4 =
F_40 ( NULL , V_82 , V_44 , V_98 ,
V_99 | V_100 ,
NULL , & V_6 ) ;
( void ) F_17 ( V_20 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_4 != V_101 ) {
goto V_97;
}
if ( V_6 -> type != V_44 ) {
V_4 = V_102 ;
goto V_97;
}
}
F_19 ( V_80 , V_81 , V_87 ) ;
V_84 -> V_46 . V_81 = V_80 ;
V_84 -> V_46 . V_87 = V_87 ;
V_84 -> V_46 . V_40 = ( T_7 )
( V_89 & V_103 ) ;
if ( V_89 & V_104 ) {
V_84 -> V_46 . V_105 = V_106 ;
V_84 -> V_46 . V_107 = ( T_7 )
( ( V_89 & V_108 ) >> 4 ) ;
}
V_4 = F_41 ( V_6 , V_84 , V_44 ) ;
V_6 -> V_74 |= V_109 ;
F_42 ( V_84 ) ;
return ( V_4 ) ;
V_97:
F_30 ( V_80 ) ;
F_30 ( V_84 ) ;
return ( V_4 ) ;
}
