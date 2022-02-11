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
if ( V_14 > V_17 ) {
return ( V_8 ) ;
}
V_4 = F_10 ( V_16 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( V_14 == V_18 ) {
V_4 = F_12 ( V_13 , V_16 ) ;
return ( V_4 ) ;
}
V_4 = F_13 ( V_19 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
V_4 = V_8 ;
goto V_20;
}
V_4 = F_14 ( V_16 , V_21 ) ;
if ( F_11 ( V_4 ) ) {
goto V_20;
}
F_15 ( V_16 -> V_22 , F_16 ( V_6 ) ,
V_23 ) ;
( ( char * ) V_16 -> V_22 ) [ V_23 ] = 0 ;
V_4 = V_11 ;
V_20:
( void ) F_17 ( V_19 ) ;
return ( V_4 ) ;
}
static char * F_18 ( struct V_24 * V_25 ,
struct V_24 * V_26 ,
char * V_27 )
{
V_25 -> string = V_27 ;
V_25 -> V_28 = V_26 -> V_28 ;
F_19 ( V_27 , V_26 -> string , V_26 -> V_28 ) ;
return ( V_27 + V_26 -> V_28 ) ;
}
T_1
F_20 ( T_2 V_13 ,
struct V_29 * * V_30 )
{
struct V_5 * V_6 ;
struct V_29 * V_31 ;
struct V_32 * V_33 = NULL ;
struct V_24 * V_34 = NULL ;
struct V_24 * V_35 = NULL ;
char * V_36 ;
T_5 type ;
T_6 V_37 ;
T_7 V_38 = 0 ;
T_7 V_39 = 0 ;
T_4 V_40 ;
T_4 V_41 ;
T_1 V_4 ;
if ( ! V_13 || ! V_30 ) {
return ( V_8 ) ;
}
V_4 = F_13 ( V_19 ) ;
if ( F_11 ( V_4 ) ) {
goto V_42;
}
V_6 = F_3 ( V_13 ) ;
if ( ! V_6 ) {
( void ) F_17 ( V_19 ) ;
return ( V_8 ) ;
}
V_40 = sizeof( struct V_29 ) ;
type = V_6 -> type ;
V_37 = V_6 -> V_37 . integer ;
if ( V_6 -> type == V_43 ) {
V_38 = V_6 -> V_44 -> V_45 . V_38 ;
}
V_4 = F_17 ( V_19 ) ;
if ( F_11 ( V_4 ) ) {
return ( V_4 ) ;
}
if ( ( type == V_46 ) || ( type == V_47 ) ) {
V_4 = F_21 ( V_6 , & V_34 ) ;
if ( F_8 ( V_4 ) ) {
V_40 += V_34 -> V_28 ;
V_39 |= V_48 ;
}
V_4 = F_22 ( V_6 , & V_35 ) ;
if ( F_8 ( V_4 ) ) {
V_40 += V_35 -> V_28 ;
V_39 |= V_49 ;
}
V_4 = F_23 ( V_6 , & V_33 ) ;
if ( F_8 ( V_4 ) ) {
V_40 +=
( V_33 -> V_50 -
sizeof( struct V_32 ) ) ;
V_39 |= V_51 ;
}
}
V_31 = F_24 ( V_40 ) ;
if ( ! V_31 ) {
V_4 = V_52 ;
goto V_42;
}
if ( ( type == V_46 ) || ( type == V_47 ) ) {
V_4 = F_25 ( V_6 , & V_31 -> V_53 ) ;
if ( F_8 ( V_4 ) ) {
V_39 |= V_54 ;
}
V_4 = F_26 ( V_55 , V_6 ,
& V_31 -> V_56 ) ;
if ( F_8 ( V_4 ) ) {
V_39 |= V_57 ;
}
V_4 = F_27 ( V_6 ,
V_58 ,
V_59 ,
V_31 -> V_60 ) ;
if ( F_8 ( V_4 ) ) {
V_39 |= V_61 ;
}
V_4 = F_27 ( V_6 ,
V_62 ,
V_63 ,
V_31 -> V_64 ) ;
if ( F_8 ( V_4 ) ) {
V_39 |= V_65 ;
}
}
V_36 = F_6 ( char , V_31 -> V_66 . V_67 ) ;
if ( V_33 ) {
V_36 +=
( ( V_68 ) V_33 -> V_69 *
sizeof( struct V_24 ) ) ;
}
if ( V_34 ) {
V_36 = F_18 ( & V_31 -> V_70 ,
V_34 , V_36 ) ;
if ( F_28 ( V_34 -> string ) ) {
V_31 -> V_71 |= V_72 ;
}
}
if ( V_35 ) {
V_36 = F_18 ( & V_31 -> V_73 ,
V_35 , V_36 ) ;
}
if ( V_33 ) {
V_31 -> V_66 . V_69 = V_33 -> V_69 ;
V_31 -> V_66 . V_50 = V_33 -> V_50 ;
for ( V_41 = 0 ; V_41 < V_33 -> V_69 ; V_41 ++ ) {
V_36 =
F_18 ( & V_31 -> V_66 .
V_67 [ V_41 ] , & V_33 -> V_67 [ V_41 ] ,
V_36 ) ;
if ( F_28 ( V_33 -> V_67 [ V_41 ] . string ) ) {
V_31 -> V_71 |= V_72 ;
}
}
}
V_31 -> V_40 = V_40 ;
V_31 -> type = type ;
V_31 -> V_37 = V_37 ;
V_31 -> V_38 = V_38 ;
V_31 -> V_39 = V_39 ;
* V_30 = V_31 ;
V_4 = V_11 ;
V_42:
if ( V_34 ) {
F_29 ( V_34 ) ;
}
if ( V_35 ) {
F_29 ( V_35 ) ;
}
if ( V_33 ) {
F_29 ( V_33 ) ;
}
return ( V_4 ) ;
}
T_1 F_30 ( T_7 * V_16 )
{
struct V_74 * V_75 =
F_6 ( struct V_74 , V_16 ) ;
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
return V_8 ;
}
if ( ! F_31 ( V_75 -> V_86 , V_87 ) &&
! F_31 ( V_75 -> V_86 , V_88 ) ) {
return V_89 ;
}
V_82 . V_90 = V_16 + sizeof( struct V_74 ) ;
V_84 = F_32 ( & V_82 ) ;
if ( V_84 != V_91 ) {
return V_8 ;
}
V_82 . V_90 += F_33 ( V_84 ) ;
V_82 . V_92 = F_34 ( & V_82 ) ;
V_78 = F_35 ( & V_82 ) ;
V_85 = * V_82 . V_90 ++ ;
V_77 = V_82 . V_90 ;
V_83 = F_36 ( V_82 . V_92 , V_77 ) ;
V_76 = F_37 ( V_83 ) ;
if ( ! V_76 ) {
return V_52 ;
}
V_80 = F_38 ( V_43 ) ;
if ( ! V_80 ) {
F_29 ( V_76 ) ;
return V_52 ;
}
V_4 = F_13 ( V_19 ) ;
if ( F_11 ( V_4 ) ) {
goto V_93;
}
V_4 =
F_39 ( NULL , V_78 , V_43 , V_94 ,
V_95 | V_96 ,
NULL , & V_6 ) ;
( void ) F_17 ( V_19 ) ;
if ( F_11 ( V_4 ) ) {
if ( V_4 != V_97 ) {
goto V_93;
}
if ( V_6 -> type != V_43 ) {
V_4 = V_98 ;
goto V_93;
}
}
F_19 ( V_76 , V_77 , V_83 ) ;
V_80 -> V_45 . V_77 = V_76 ;
V_80 -> V_45 . V_83 = V_83 ;
V_80 -> V_45 . V_38 = ( T_7 )
( V_85 & V_99 ) ;
if ( V_85 & V_100 ) {
V_80 -> V_45 . V_101 = V_102 ;
V_80 -> V_45 . V_103 = ( T_7 )
( ( V_85 & V_104 ) >> 4 ) ;
}
V_4 = F_40 ( V_6 , V_80 , V_43 ) ;
V_6 -> V_71 |= V_105 ;
F_41 ( V_80 ) ;
return V_4 ;
V_93:
F_29 ( V_76 ) ;
F_29 ( V_80 ) ;
return V_4 ;
}
