static inline void F_1 ( struct V_1 * V_2 ,
T_1 type ,
T_1 V_3 ,
T_1 V_4 ,
T_1 * V_5 ,
T_1 * V_6 )
{
T_2 V_7 , V_8 ;
V_7 = V_2 -> V_9 [ ( type ) ] . V_10 +
V_2 -> V_9 [ type ] . V_11 * V_3 ;
V_8 = V_7 + V_2 -> V_9 [ type ] . V_11 * V_4 ;
* V_5 = ( T_1 ) ( V_7 / V_12 ) ;
* V_6 = ( T_1 ) ( ( V_8 - 1 ) / V_12 ) ;
* V_6 += 1 ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 type ,
T_1 V_3 ,
T_1 V_4 ,
T_1 * V_13 ,
T_1 * V_14 )
{
T_2 V_15 , V_8 ;
V_15 = V_2 -> V_9 [ type ] . V_10 +
V_2 -> V_9 [ type ] . V_11 * V_3 ;
V_8 = V_15 + ( V_2 ) -> V_9 [ ( type ) ] . V_11 * ( V_4 ) ;
* ( V_13 ) = ( T_1 ) ( V_15 / V_16 ) ;
* ( V_14 ) = ( T_1 ) ( ( V_8 - 1 ) / V_16 ) ;
* ( V_14 ) += 1 ;
}
static inline void F_3 ( T_2 V_17 ,
T_1 V_3 ,
enum V_18 type ,
struct V_19 * V_20 )
{
V_20 -> V_21 = V_17 | ( V_22 << V_23 ) |
( ( ( type == V_24 ) ? 0 : 1 ) <<
V_25 ) |
( 1 << V_26 ) ;
V_20 -> V_27 = ( V_3 | ( 1 << V_28 ) | ( 1 << 15 ) ) ;
}
static inline void F_4 ( T_1 V_3 , enum V_18 type ,
struct V_19 * V_20 )
{
V_20 -> V_21 = ( V_22 <<
V_23 ) |
( ( ( type == V_24 ) ? 0 : 1 ) <<
V_25 ) ;
V_20 -> V_27 = ( V_3 | ( 1 << V_28 ) | ( 1 << 15 ) ) ;
}
enum V_29 F_5 ( struct V_30 * V_31 ,
T_3 V_32 ,
T_2 V_17 , T_1 V_5 ,
enum V_18 type ,
bool V_33 )
{
struct V_34 V_35 ;
V_35 . V_4 = 1 ;
V_35 . V_32 = V_32 ;
if ( V_33 )
F_3 ( V_17 , V_5 , type , V_35 . V_20 ) ;
else
F_4 ( V_5 , type , V_35 . V_20 ) ;
return V_31 -> V_36 -> V_37 ( V_31 , & V_35 ) ;
}
static enum V_29 F_6 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 V_38 ,
T_1 V_39 ,
bool V_33 )
{
struct V_40 * V_41 ;
struct V_34 V_35 ;
T_2 V_17 ;
T_1 V_42 ;
enum V_29 V_43 = 0 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_32 = V_2 -> V_32 ;
for ( V_42 = V_38 ; V_42 < V_38 + V_39 ; V_42 ++ ) {
V_41 = & V_2 -> V_44 . V_41 [ V_42 ] ;
if ( ! V_41 ||
( ! V_41 -> V_45 && V_33 ) ||
( V_41 -> V_45 && ! V_33 ) )
continue;
if ( V_33 ) {
V_17 = ( V_41 -> V_46 == V_24 ) ?
V_41 -> V_47 . V_48 . V_49 . V_17 :
V_41 -> V_47 . V_50 . V_51 . V_17 ;
F_3 ( V_17 , V_42 , V_41 -> V_46 ,
& V_35 . V_20 [ V_35 . V_4 ] ) ;
} else {
F_4 ( V_42 , V_41 -> V_46 ,
& V_35 . V_20 [ V_35 . V_4 ] ) ;
}
V_35 . V_4 ++ ;
if ( V_35 . V_4 == V_52 ) {
V_43 = V_31 -> V_36 -> V_37 ( V_31 , & V_35 ) ;
if ( V_43 ) {
F_7 ( V_31 , V_53 ,
L_1 ,
V_43 ) ;
return V_43 ;
}
V_35 . V_4 = 0 ;
}
}
if ( V_35 . V_4 )
V_43 = V_31 -> V_36 -> V_37 ( V_31 , & V_35 ) ;
return V_43 ;
}
struct V_54 * F_8 ( struct V_30 * V_31 , T_3 V_32 )
{
struct V_54 * V_55 = NULL ;
T_4 V_3 ;
for ( V_3 = 0 ; V_3 < V_56 ; V_3 ++ ) {
if ( V_31 -> V_55 [ V_3 ] &&
( ( T_3 ) V_31 -> V_55 [ V_3 ] -> V_57 == V_32 ) ) {
V_55 = V_31 -> V_55 [ V_3 ] ;
break;
}
}
return V_55 ;
}
struct V_1 * F_9 ( struct V_30 * V_31 ,
T_3 V_32 )
{
struct V_1 * V_2 = NULL ;
T_4 V_3 ;
for ( V_3 = 0 ; V_3 < V_56 ; V_3 ++ ) {
if ( V_31 -> V_55 [ V_3 ] &&
( ( T_3 ) V_31 -> V_55 [ V_3 ] -> V_57 == V_32 ) ) {
V_2 = & V_31 -> V_55 [ V_3 ] -> V_2 ;
break;
}
}
return V_2 ;
}
static enum V_29 F_10 ( struct V_30 * V_31 ,
struct V_58 * V_59 )
{
if ( V_59 -> V_60 >= V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 )
return V_62 ;
if ( ( V_59 -> V_60 + V_59 -> V_63 ) >
V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 )
return V_64 ;
if ( ! V_59 -> V_65 )
return 0 ;
return F_6 ( V_31 , V_59 -> V_2 ,
V_59 -> V_2 -> V_66 [ 0 ] ,
V_59 -> V_65 , true ) ;
}
enum V_29 F_11 ( struct V_30 * V_31 ,
struct V_58 * V_59 )
{
struct V_40 * V_41 ;
T_1 V_5 , V_67 ;
T_1 V_13 = 0 , V_68 = 0 ;
T_1 V_69 = 0 , V_70 = 0 ;
T_1 V_42 , V_71 ;
bool V_72 = false ;
enum V_29 V_43 = 0 ;
if ( V_59 -> V_60 >= V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 )
return V_62 ;
if ( ( V_59 -> V_60 + V_59 -> V_63 ) >
V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 ) {
F_7 ( V_31 , V_53 ,
L_2 ,
V_73 , V_59 -> V_61 , V_59 -> V_60 , V_59 -> V_63 ,
V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 ) ;
return V_64 ;
}
if ( ! V_31 -> V_74 )
return F_12 ( V_31 , V_59 -> V_61 , 0 , V_59 -> V_63 ) ;
F_1 ( V_59 -> V_2 , V_59 -> V_61 ,
V_59 -> V_60 , V_59 -> V_63 ,
& V_5 , & V_67 ) ;
if ( V_5 >= V_59 -> V_2 -> V_44 . V_39 ||
V_67 > V_59 -> V_2 -> V_44 . V_39 ) {
return V_75 ;
}
F_2 ( V_59 -> V_2 , V_59 -> V_61 ,
V_59 -> V_60 , V_59 -> V_63 , & V_13 , & V_68 ) ;
for ( V_71 = V_5 ; V_71 < V_67 ; V_71 ++ ) {
V_43 = F_13 ( V_31 -> V_76 , V_59 -> V_2 ,
V_71 ,
V_59 -> V_46 ,
V_12 ) ;
if ( V_43 )
goto V_77;
V_41 = & V_59 -> V_2 -> V_44 . V_41 [ V_71 ] ;
if ( ( V_41 -> V_46 == V_24 ) &&
( ( V_31 -> V_2 == V_59 -> V_2 ) &&
( V_59 -> V_61 != V_78 ) ) ) {
V_69 = F_14 ( V_13 , ( V_71 * V_22 ) ) ;
V_70 = F_15 ( V_68 ,
( V_71 + 1 ) * V_22 ) ;
for ( V_42 = V_69 ; V_42 < V_70 ; V_42 ++ ) {
V_43 = F_16 ( V_31 -> V_76 , V_59 -> V_2 ,
V_42 , NULL ) ;
if ( V_43 ) {
V_72 = true ;
break;
}
}
if ( V_72 ) {
while ( V_42 && ( V_42 > V_69 ) ) {
F_17 ( V_31 -> V_76 , V_59 -> V_2 , ( V_42 - 1 ) ,
V_59 -> V_74 ) ;
V_42 -- ;
}
}
}
if ( V_41 -> V_45 )
continue;
V_59 -> V_2 -> V_66 [ V_59 -> V_65 ] = ( T_4 ) V_71 ;
V_59 -> V_65 ++ ;
V_41 -> V_45 = true ;
}
return F_10 ( V_31 , V_59 ) ;
V_77:
while ( V_71 && ( V_71 > V_5 ) ) {
V_41 = & V_59 -> V_2 -> V_44 . V_41 [ V_71 - 1 ] ;
switch ( V_41 -> V_46 ) {
case V_24 :
V_69 = F_14 ( V_13 ,
( V_71 - 1 ) * V_22 ) ;
V_70 = F_15 ( V_68 , ( V_71 * V_22 ) ) ;
for ( V_42 = V_69 ; V_42 < V_70 ; V_42 ++ )
F_18 ( V_59 -> V_2 , V_42 ) ;
break;
case V_79 :
F_18 ( V_59 -> V_2 , ( V_71 - 1 ) ) ;
break;
default:
V_43 = V_80 ;
break;
}
V_71 -- ;
}
return V_43 ;
}
static enum V_29 F_19 ( struct V_30 * V_31 ,
struct V_81 * V_59 ,
bool V_82 )
{
struct V_40 * V_41 ;
enum V_29 V_43 = 0 ;
T_1 V_42 , V_5 ;
struct V_83 * V_84 ;
if ( V_31 -> V_74 && ! V_82 )
V_43 = F_6 ( V_31 , V_59 -> V_2 ,
V_59 -> V_2 -> V_66 [ 0 ] ,
V_59 -> V_85 , false ) ;
if ( V_43 )
F_7 ( V_31 , V_53 , L_3 , V_73 ) ;
for ( V_42 = 0 ; V_42 < V_59 -> V_85 ; V_42 ++ ) {
V_5 = V_59 -> V_2 -> V_66 [ V_42 ] ;
V_41 = & V_59 -> V_2 -> V_44 . V_41 [ V_5 ] ;
if ( ! V_41 )
continue;
V_84 = ( V_41 -> V_46 == V_24 ) ?
& V_41 -> V_47 . V_48 . V_49 :
& V_41 -> V_47 . V_50 . V_51 ;
if ( ! V_84 || ! V_84 -> V_86 )
F_7 ( V_31 , V_53 , L_4 , V_73 ) ;
else
F_20 ( V_31 -> V_76 , V_84 ) ;
}
return V_43 ;
}
enum V_29 F_21 ( struct V_30 * V_31 ,
struct V_81 * V_59 ,
bool V_82 )
{
struct V_87 * V_48 ;
T_1 V_5 , V_67 ;
T_1 V_13 , V_68 , V_88 ;
T_1 V_42 , V_71 ;
enum V_29 V_43 = 0 ;
if ( V_59 -> V_60 >= V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 ) {
F_7 ( V_31 , V_53 ,
L_5 ,
V_73 , V_59 -> V_60 , V_59 -> V_61 ,
V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 ) ;
return V_62 ;
}
if ( ( V_59 -> V_60 + V_59 -> V_63 ) >
V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 ) {
F_7 ( V_31 , V_53 ,
L_6 ,
V_73 , V_59 -> V_60 , V_59 -> V_63 ,
V_59 -> V_61 ,
V_59 -> V_2 -> V_9 [ V_59 -> V_61 ] . V_4 ) ;
return V_64 ;
}
if ( ! V_31 -> V_74 ) {
V_43 = F_22 ( V_31 , V_59 -> V_61 , 0 ,
V_59 -> V_63 ) ;
if ( V_59 -> V_61 != V_78 )
return V_43 ;
}
F_2 ( V_59 -> V_2 , V_59 -> V_61 ,
V_59 -> V_60 , V_59 -> V_63 , & V_13 , & V_68 ) ;
for ( V_71 = V_13 ; V_71 < V_68 ; V_71 ++ ) {
V_5 = V_71 / V_89 ;
if ( V_59 -> V_2 -> V_44 . V_41 [ V_5 ] . V_46 !=
V_24 )
continue;
V_88 = V_71 % V_89 ;
V_48 = & V_59 -> V_2 -> V_44 . V_41 [ V_5 ] . V_47 . V_48 ;
if ( V_48 -> V_90 [ V_88 ] . V_45 ) {
V_43 = F_17 ( V_31 -> V_76 , V_59 -> V_2 , V_71 ,
V_59 -> V_74 ) ;
if ( V_43 ) {
F_7 ( V_31 , V_53 , L_7 , V_73 ) ;
return V_43 ;
}
}
}
F_1 ( V_59 -> V_2 , V_59 -> V_61 ,
V_59 -> V_60 , V_59 -> V_63 , & V_5 , & V_67 ) ;
if ( V_5 >= V_59 -> V_2 -> V_44 . V_39 ||
V_67 > V_59 -> V_2 -> V_44 . V_39 ) {
F_7 ( V_31 , V_53 , L_8 , V_73 ) ;
return V_75 ;
}
for ( V_42 = V_5 ; V_42 < V_67 ; V_42 ++ ) {
if ( ! V_59 -> V_2 -> V_44 . V_41 [ V_42 ] . V_45 )
continue;
switch ( V_59 -> V_2 -> V_44 . V_41 [ V_42 ] . V_46 ) {
case V_79 :
V_43 = F_23 ( V_59 -> V_2 , V_42 ) ;
if ( ! V_43 ) {
V_59 -> V_2 -> V_66 [ V_59 -> V_85 ] = ( T_4 ) V_42 ;
V_59 -> V_85 ++ ;
}
break;
case V_24 :
V_43 = F_18 ( V_59 -> V_2 , V_42 ) ;
if ( ! V_43 ) {
V_59 -> V_2 -> V_66 [ V_59 -> V_85 ] = ( T_4 ) V_42 ;
V_59 -> V_85 ++ ;
}
break;
default:
break;
}
}
return F_19 ( V_31 , V_59 , V_82 ) ;
}
enum V_29 F_13 ( struct V_91 * V_76 ,
struct V_1 * V_2 ,
T_1 V_38 ,
enum V_18 type ,
T_2 V_92 )
{
enum V_29 V_43 = 0 ;
struct V_40 * V_41 ;
bool V_93 = false ;
struct V_83 V_84 ;
T_2 V_94 ;
V_41 = & V_2 -> V_44 . V_41 [ V_38 ] ;
if ( ! V_41 -> V_45 ) {
if ( type == V_24 )
V_94 = V_16 ;
else
V_94 = V_92 ;
V_43 = F_24 ( V_76 , & V_84 , V_94 ,
V_95 ) ;
if ( V_43 )
goto exit;
V_93 = true ;
if ( type == V_24 ) {
V_43 = F_25 ( V_76 ,
& V_41 -> V_47 . V_48 . V_96 ,
sizeof( struct V_97 ) * 512 ) ;
if ( V_43 )
goto exit;
V_41 -> V_47 . V_48 . V_90 = (struct V_97 * )
V_41 -> V_47 . V_48 . V_96 . V_86 ;
memcpy ( & V_41 -> V_47 . V_48 . V_49 , & V_84 , sizeof( struct V_83 ) ) ;
} else {
memcpy ( & V_41 -> V_47 . V_50 . V_51 , & V_84 , sizeof( struct V_83 ) ) ;
V_41 -> V_47 . V_50 . V_98 = V_38 ;
}
V_2 -> V_44 . V_41 [ V_38 ] . V_46 = type ;
F_26 ( & V_2 -> V_44 ) ;
}
if ( V_41 -> V_46 == V_79 )
F_27 ( & V_41 -> V_47 . V_50 ) ;
exit:
if ( V_43 )
if ( V_93 )
F_20 ( V_76 , & V_84 ) ;
return V_43 ;
}
enum V_29 F_16 ( struct V_91 * V_76 ,
struct V_1 * V_2 ,
T_1 V_99 ,
struct V_83 * V_100 )
{
enum V_29 V_43 = 0 ;
struct V_87 * V_48 ;
struct V_97 * V_90 ;
struct V_83 V_84 ;
struct V_83 * V_101 = & V_84 ;
T_1 V_5 , V_88 ;
T_2 * V_102 ;
T_2 V_103 ;
if ( V_99 / V_89 >= V_2 -> V_44 . V_39 )
return V_104 ;
V_5 = ( V_99 / V_89 ) ;
if ( V_2 -> V_44 . V_41 [ V_5 ] . V_46 != V_24 )
return 0 ;
V_88 = ( V_99 % V_89 ) ;
V_48 = & V_2 -> V_44 . V_41 [ V_5 ] . V_47 . V_48 ;
V_90 = & V_48 -> V_90 [ V_88 ] ;
if ( ! V_90 -> V_45 ) {
if ( V_100 ) {
V_90 -> V_100 = true ;
V_101 = V_100 ;
} else {
V_43 = F_24 ( V_76 , V_101 ,
V_16 ,
V_95 ) ;
if ( V_43 )
return V_43 ;
V_90 -> V_100 = false ;
}
memcpy ( & V_90 -> V_50 . V_51 , V_101 , sizeof( struct V_83 ) ) ;
V_90 -> V_50 . V_98 = V_99 ;
V_90 -> V_50 . V_46 = V_24 ;
V_103 = V_101 -> V_17 | 0x1 ;
V_102 = ( T_2 * ) V_48 -> V_49 . V_86 ;
V_102 += V_88 ;
memcpy ( V_102 , & V_103 , sizeof( * V_102 ) ) ;
V_90 -> V_38 = V_5 ;
V_90 -> V_45 = true ;
F_28 ( V_48 ) ;
if ( V_2 -> V_32 < V_105 )
F_29 ( V_76 , V_5 , V_88 ) ;
else if ( V_76 -> V_106 . V_32 != V_2 -> V_32 )
F_30 ( V_76 , V_5 , V_88 ,
V_2 -> V_32 ) ;
}
F_27 ( & V_90 -> V_50 ) ;
return 0 ;
}
enum V_29 F_17 ( struct V_91 * V_76 ,
struct V_1 * V_2 ,
T_1 V_3 ,
bool V_74 )
{
struct V_97 * V_90 ;
struct V_87 * V_48 ;
struct V_40 * V_41 ;
T_1 V_5 , V_88 ;
struct V_83 * V_84 ;
T_2 * V_102 ;
V_5 = V_3 / V_89 ;
V_88 = V_3 % V_89 ;
if ( V_5 >= V_2 -> V_44 . V_39 )
return V_104 ;
V_41 = & V_2 -> V_44 . V_41 [ V_5 ] ;
if ( V_41 -> V_46 != V_24 )
return V_80 ;
V_48 = & V_2 -> V_44 . V_41 [ V_5 ] . V_47 . V_48 ;
V_90 = & V_48 -> V_90 [ V_88 ] ;
F_31 ( & V_90 -> V_50 ) ;
if ( V_90 -> V_50 . V_107 )
return 0 ;
V_90 -> V_45 = false ;
F_32 ( V_48 ) ;
V_102 = ( T_2 * ) V_48 -> V_49 . V_86 ;
V_102 += V_88 ;
memset ( V_102 , 0 , sizeof( T_2 ) ) ;
if ( V_74 )
F_29 ( V_76 , V_5 , V_3 ) ;
else
F_30 ( V_76 , V_5 , V_3 ,
V_2 -> V_32 ) ;
if ( ! V_90 -> V_100 ) {
V_84 = & V_90 -> V_50 . V_51 ;
if ( ! V_84 || ! V_84 -> V_86 )
return V_108 ;
F_20 ( V_76 , V_84 ) ;
}
if ( ! V_48 -> V_107 )
F_33 ( V_76 , & V_48 -> V_96 ) ;
return 0 ;
}
enum V_29 F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_40 * V_41 ;
V_41 = & V_2 -> V_44 . V_41 [ V_3 ] ;
F_31 ( & V_41 -> V_47 . V_50 ) ;
if ( V_41 -> V_47 . V_50 . V_107 )
return V_109 ;
F_34 ( & V_2 -> V_44 ) ;
V_41 -> V_45 = false ;
return 0 ;
}
enum V_29 F_18 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_40 * V_41 ;
V_41 = & V_2 -> V_44 . V_41 [ V_3 ] ;
if ( V_41 -> V_47 . V_48 . V_107 )
return V_109 ;
V_41 -> V_45 = false ;
F_34 ( & V_2 -> V_44 ) ;
return 0 ;
}
enum V_29 F_35 ( struct V_30 * V_31 ,
T_3 V_110 ,
T_1 * V_111 )
{
struct V_1 * V_2 ;
enum V_29 V_43 = 0 ;
T_1 V_42 ;
if ( ( V_110 < V_105 ) ||
( V_110 >= V_105 +
V_56 ) ) {
F_7 ( V_31 , V_53 , L_9 ,
V_73 , V_110 ) ;
return V_112 ;
}
V_43 = F_36 ( V_31 , V_110 ) ;
if ( V_43 )
return V_43 ;
V_2 = F_9 ( V_31 , V_110 ) ;
for ( V_42 = V_113 ; V_42 < V_114 ; V_42 ++ )
if ( V_111 )
V_2 -> V_9 [ V_42 ] . V_4 =
V_111 [ V_42 - V_113 ] ;
else
V_2 -> V_9 [ V_42 ] . V_4 = V_2 -> V_9 [ V_42 ] . V_115 ;
return 0 ;
}
