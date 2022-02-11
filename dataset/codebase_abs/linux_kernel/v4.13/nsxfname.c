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
if ( V_14 > V_17 ) {
return ( V_8 ) ;
}
V_4 = F_9 ( V_16 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
V_4 = F_11 ( V_18 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( V_14 == V_19 ||
V_14 == V_20 ) {
V_4 = F_12 ( V_13 , V_16 ,
V_14 ==
V_19 ? FALSE :
TRUE ) ;
} else {
V_4 = F_13 ( V_13 , V_16 ) ;
}
( void ) F_14 ( V_18 ) ;
return ( V_4 ) ;
}
static char * F_15 ( struct V_21 * V_22 ,
struct V_21 * V_23 ,
char * V_24 )
{
V_22 -> string = V_24 ;
V_22 -> V_25 = V_23 -> V_25 ;
memcpy ( V_24 , V_23 -> string , V_23 -> V_25 ) ;
return ( V_24 + V_23 -> V_25 ) ;
}
T_1
F_16 ( T_2 V_13 ,
struct V_26 * * V_27 )
{
struct V_5 * V_6 ;
struct V_26 * V_28 ;
struct V_29 * V_30 = NULL ;
struct V_21 * V_31 = NULL ;
struct V_21 * V_32 = NULL ;
struct V_21 * V_33 = NULL ;
char * V_34 ;
T_5 type ;
T_6 V_35 ;
T_7 V_36 = 0 ;
T_8 V_37 = 0 ;
T_4 V_38 ;
T_4 V_39 ;
T_1 V_4 ;
if ( ! V_13 || ! V_27 ) {
return ( V_8 ) ;
}
V_4 = F_11 ( V_18 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
( void ) F_14 ( V_18 ) ;
return ( V_8 ) ;
}
V_38 = sizeof( struct V_26 ) ;
type = V_6 -> type ;
V_35 = V_6 -> V_35 . integer ;
if ( V_6 -> type == V_40 ) {
V_36 = V_6 -> V_41 -> V_42 . V_36 ;
}
V_4 = F_14 ( V_18 ) ;
if ( F_10 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( ( type == V_43 ) || ( type == V_44 ) ) {
V_4 = F_17 ( V_6 , & V_31 ) ;
if ( F_7 ( V_4 ) ) {
V_38 += V_31 -> V_25 ;
V_37 |= V_45 ;
}
V_4 = F_18 ( V_6 , & V_32 ) ;
if ( F_7 ( V_4 ) ) {
V_38 += V_32 -> V_25 ;
V_37 |= V_46 ;
}
V_4 = F_19 ( V_6 , & V_30 ) ;
if ( F_7 ( V_4 ) ) {
V_38 +=
( V_30 -> V_47 -
sizeof( struct V_29 ) ) ;
V_37 |= V_48 ;
}
V_4 = F_20 ( V_6 , & V_33 ) ;
if ( F_7 ( V_4 ) ) {
V_38 += V_33 -> V_25 ;
V_37 |= V_49 ;
}
}
V_28 = F_21 ( V_38 ) ;
if ( ! V_28 ) {
V_4 = V_50 ;
goto V_51;
}
if ( ( type == V_43 ) || ( type == V_44 ) ) {
V_4 = F_22 ( V_6 , & V_28 -> V_52 ) ;
if ( F_7 ( V_4 ) ) {
V_37 |= V_53 ;
}
V_4 = F_23 ( V_54 , V_6 ,
& V_28 -> V_55 ) ;
if ( F_7 ( V_4 ) ) {
V_37 |= V_56 ;
}
V_4 = F_24 ( V_6 ,
V_57 ,
V_58 ,
V_28 -> V_59 ) ;
if ( F_7 ( V_4 ) ) {
V_37 |= V_60 ;
}
V_4 = F_24 ( V_6 ,
V_61 ,
V_62 ,
V_28 -> V_63 ) ;
if ( F_7 ( V_4 ) ) {
V_37 |= V_64 ;
}
}
V_34 = F_5 ( char , V_28 -> V_65 . V_66 ) ;
if ( V_30 ) {
V_34 +=
( ( V_67 ) V_30 -> V_68 *
sizeof( struct V_21 ) ) ;
}
if ( V_31 ) {
V_34 = F_15 ( & V_28 -> V_69 ,
V_31 , V_34 ) ;
if ( F_25 ( V_31 -> string ) ) {
V_28 -> V_70 |= V_71 ;
}
}
if ( V_32 ) {
V_34 = F_15 ( & V_28 -> V_72 ,
V_32 , V_34 ) ;
}
if ( V_30 ) {
V_28 -> V_65 . V_68 = V_30 -> V_68 ;
V_28 -> V_65 . V_47 = V_30 -> V_47 ;
for ( V_39 = 0 ; V_39 < V_30 -> V_68 ; V_39 ++ ) {
V_34 =
F_15 ( & V_28 -> V_65 .
V_66 [ V_39 ] , & V_30 -> V_66 [ V_39 ] ,
V_34 ) ;
if ( F_25 ( V_30 -> V_66 [ V_39 ] . string ) ) {
V_28 -> V_70 |= V_71 ;
}
}
}
if ( V_33 ) {
V_34 = F_15 ( & V_28 -> V_73 ,
V_33 , V_34 ) ;
}
V_28 -> V_38 = V_38 ;
V_28 -> type = type ;
V_28 -> V_35 = V_35 ;
V_28 -> V_36 = V_36 ;
V_28 -> V_37 = V_37 ;
* V_27 = V_28 ;
V_4 = V_11 ;
V_51:
if ( V_31 ) {
F_26 ( V_31 ) ;
}
if ( V_32 ) {
F_26 ( V_32 ) ;
}
if ( V_30 ) {
F_26 ( V_30 ) ;
}
if ( V_33 ) {
F_26 ( V_33 ) ;
}
return ( V_4 ) ;
}
T_1 F_27 ( T_7 * V_16 )
{
struct V_74 * V_75 =
F_5 ( struct V_74 , V_16 ) ;
T_7 * V_76 ;
T_7 * V_77 ;
char * V_78 ;
struct V_5 * V_6 ;
union V_79 * V_80 ;
struct V_81 V_82 ;
T_4 V_83 ;
T_8 V_84 ;
T_7 V_85 ;
T_1 V_4 ;
if ( ! V_16 ) {
return ( V_8 ) ;
}
if ( ! F_28 ( V_75 -> V_86 , V_87 ) &&
! F_28 ( V_75 -> V_86 , V_88 ) ) {
return ( V_89 ) ;
}
V_82 . V_90 = V_16 + sizeof( struct V_74 ) ;
V_84 = F_29 ( & V_82 ) ;
if ( V_84 != V_91 ) {
return ( V_8 ) ;
}
V_82 . V_90 += F_30 ( V_84 ) ;
V_82 . V_92 = F_31 ( & V_82 ) ;
V_78 = F_32 ( & V_82 ) ;
V_85 = * V_82 . V_90 ++ ;
V_77 = V_82 . V_90 ;
V_83 = F_33 ( V_82 . V_92 , V_77 ) ;
V_76 = F_34 ( V_83 ) ;
if ( ! V_76 ) {
return ( V_50 ) ;
}
V_80 = F_35 ( V_40 ) ;
if ( ! V_80 ) {
F_26 ( V_76 ) ;
return ( V_50 ) ;
}
V_4 = F_11 ( V_18 ) ;
if ( F_10 ( V_4 ) ) {
goto V_93;
}
V_4 =
F_36 ( NULL , V_78 , V_40 , V_94 ,
V_95 | V_96 ,
NULL , & V_6 ) ;
( void ) F_14 ( V_18 ) ;
if ( F_10 ( V_4 ) ) {
if ( V_4 != V_97 ) {
goto V_93;
}
if ( V_6 -> type != V_40 ) {
V_4 = V_98 ;
goto V_93;
}
}
memcpy ( V_76 , V_77 , V_83 ) ;
V_80 -> V_42 . V_77 = V_76 ;
V_80 -> V_42 . V_83 = V_83 ;
V_80 -> V_42 . V_36 = ( T_7 )
( V_85 & V_99 ) ;
if ( V_85 & V_100 ) {
V_80 -> V_42 . V_101 = V_102 ;
V_80 -> V_42 . V_103 = ( T_7 )
( ( V_85 & V_104 ) >> 4 ) ;
}
V_4 = F_37 ( V_6 , V_80 , V_40 ) ;
V_6 -> V_70 |= V_105 ;
F_38 ( V_80 ) ;
return ( V_4 ) ;
V_93:
F_26 ( V_76 ) ;
F_26 ( V_80 ) ;
return ( V_4 ) ;
}
