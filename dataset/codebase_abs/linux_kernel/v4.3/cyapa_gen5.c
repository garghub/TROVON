int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
F_2 ( & V_3 -> V_5 ) ;
F_3 ( & V_3 -> V_6 , 0 ) ;
F_4 ( & V_3 -> V_7 ) ;
V_3 -> V_8 = NULL ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = NULL ;
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_1 , T_2 * V_17 , T_3 V_18 )
{
int V_19 ;
if ( V_18 == 0 )
return 0 ;
if ( ! V_17 || V_18 > V_20 )
return - V_21 ;
V_19 = F_6 ( V_1 -> V_22 , V_17 , V_18 ) ;
if ( V_19 != V_18 )
return ( V_19 < 0 ) ? V_19 : - V_23 ;
return V_18 ;
}
T_1 F_7 ( struct V_1 * V_1 , T_2 * V_17 , T_3 V_18 )
{
int V_19 ;
if ( ! V_17 || ! V_18 )
return - V_21 ;
V_19 = F_8 ( V_1 -> V_22 , V_17 , V_18 ) ;
if ( V_19 != V_18 )
return ( V_19 < 0 ) ? V_19 : - V_23 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 ,
T_2 * V_17 , int * V_24 , T_4 V_25 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
int error ;
V_29 = 0 ;
if ( V_24 ) {
V_29 = ( * V_24 < V_20 ) ?
* V_24 : V_20 ;
* V_24 = 0 ;
}
V_27 = 8 ;
V_28 = 0 ;
do {
if ( V_28 > 5 )
return 0 ;
error = F_5 ( V_1 , V_3 -> V_30 ,
V_31 ) ;
if ( error < 0 )
return error ;
V_26 = F_10 ( V_3 -> V_30 ) ;
if ( V_26 == V_31 ) {
V_28 ++ ;
continue;
} else if ( V_26 > V_20 ) {
return - V_21 ;
} else if ( V_26 == 0 ) {
V_26 = V_31 ;
if ( V_17 && V_29 && V_25 &&
V_25 ( V_1 , V_3 -> V_30 , V_26 ) ) {
V_26 = F_11 ( V_29 , V_26 ) ;
memcpy ( V_17 , V_3 -> V_30 , V_26 ) ;
* V_24 = V_26 ;
return 0 ;
}
continue;
}
error = F_5 ( V_1 , V_3 -> V_30 , V_26 ) ;
if ( error < 0 )
return error ;
V_27 -- ;
V_28 = 0 ;
V_26 = F_10 ( V_3 -> V_30 ) ;
if ( V_26 <= V_31 ) {
V_28 ++ ;
} else if ( V_17 && V_29 && V_25 &&
V_25 ( V_1 , V_3 -> V_30 , V_26 ) ) {
V_26 = F_11 ( V_29 , V_26 ) ;
memcpy ( V_17 , V_3 -> V_30 , V_26 ) ;
* V_24 = V_26 ;
return 0 ;
}
error = - V_21 ;
} while ( V_27 );
return error ;
}
static int F_12 (
struct V_1 * V_1 ,
T_2 * V_32 , T_3 V_33 ,
unsigned long V_34 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int error ;
F_2 ( & V_3 -> V_5 ) ;
F_13 ( & V_3 -> V_6 ) ;
error = F_7 ( V_1 , V_32 , V_33 ) ;
if ( error ) {
F_14 ( & V_3 -> V_6 ) ;
return ( error < 0 ) ? error : - V_23 ;
}
V_34 = F_15 ( & V_3 -> V_5 ,
F_16 ( V_34 ) ) ;
if ( V_34 == 0 ) {
F_14 ( & V_3 -> V_6 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_17 (
struct V_1 * V_1 ,
T_2 * V_32 , T_3 V_33 ,
T_2 * V_11 , int * V_12 ,
unsigned long V_34 ,
T_4 V_25 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_36 ;
int V_26 ;
int error ;
F_13 ( & V_3 -> V_6 ) ;
error = F_7 ( V_1 , V_32 , V_33 ) ;
if ( error ) {
F_14 ( & V_3 -> V_6 ) ;
return error < 0 ? error : - V_23 ;
}
V_26 = V_12 ? * V_12 : 0 ;
if ( V_11 && V_12 && V_26 != 0 && V_25 ) {
V_36 = V_34 / 5 ;
do {
F_18 ( 3000 , 5000 ) ;
* V_12 = V_26 ;
error = F_9 ( V_1 ,
V_11 , V_12 , V_25 ) ;
if ( error || * V_12 == 0 )
continue;
else
break;
} while ( -- V_36 > 0 );
if ( ( error || * V_12 == 0 ) || V_36 <= 0 )
error = error ? error : - V_35 ;
}
F_14 ( & V_3 -> V_6 ) ;
return error ;
}
int F_19 (
struct V_1 * V_1 ,
T_2 * V_32 , int V_33 ,
T_2 * V_11 , int * V_12 ,
unsigned long V_34 ,
T_4 V_25 ,
bool V_37 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int error ;
if ( ! V_32 || ! V_33 )
return - V_21 ;
error = F_20 ( & V_3 -> V_7 ) ;
if ( error )
return error ;
V_3 -> V_8 = V_25 ;
V_3 -> V_11 = V_11 ;
V_3 -> V_12 = V_12 ;
if ( V_33 >= V_38 &&
V_32 [ 4 ] == V_39 ) {
V_3 -> V_9 = V_32 [ 6 ] & 0x7f ;
} else if ( V_33 >= V_40 &&
V_32 [ 4 ] == V_41 ) {
V_3 -> V_9 = V_32 [ 7 ] ;
}
if ( V_37 ) {
V_3 -> V_42 = true ;
error = F_12 ( V_1 , V_32 , V_33 ,
V_34 ) ;
if ( error == - V_35 && V_11 &&
V_12 && * V_12 != 0 && V_25 ) {
error = F_9 ( V_1 ,
V_11 , V_12 , V_25 ) ;
if ( error || * V_12 == 0 )
error = error ? error : - V_35 ;
}
} else {
V_3 -> V_42 = false ;
error = F_17 ( V_1 , V_32 , V_33 ,
V_11 , V_12 , V_34 , V_25 ) ;
}
V_3 -> V_8 = NULL ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = NULL ;
V_3 -> V_9 = V_10 ;
F_21 ( & V_3 -> V_7 ) ;
return error ;
}
bool F_22 ( struct V_1 * V_1 ,
T_2 * V_43 , int V_24 )
{
if ( ! V_43 || V_24 < V_44 )
return false ;
if ( V_43 [ V_45 ] == V_46 &&
V_43 [ V_47 ] == V_48 &&
V_43 [ V_49 ] == V_50 )
return true ;
return false ;
}
bool F_23 ( struct V_1 * V_1 ,
T_2 * V_43 , int V_24 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_12 ;
if ( ! V_43 || V_24 < V_51 )
return false ;
if ( V_43 [ V_45 ] == V_52 &&
V_43 [ V_47 ] == V_48 ) {
V_12 = F_10 ( & V_43 [ V_53 ] ) ;
if ( F_24 ( V_43 [ V_54 ] ) == 0x00 &&
V_12 == V_55 &&
V_43 [ 5 ] == V_3 -> V_9 ) {
return false ;
} else if ( F_24 ( V_43 [ V_54 ] ) ==
V_3 -> V_9 ) {
return true ;
}
}
return false ;
}
static bool F_25 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_24 )
{
if ( V_17 == NULL || V_24 < V_31 )
return false ;
if ( V_17 [ 0 ] == 0 && V_17 [ 1 ] == 0 )
return true ;
return false ;
}
static bool F_26 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_24 )
{
int V_12 ;
int V_56 ;
if ( V_24 != V_57 )
return false ;
V_12 = F_10 ( & V_17 [ V_53 ] ) ;
V_56 = F_10 ( & V_17 [ 16 ] ) ;
if ( V_12 == V_57 ) {
if ( V_17 [ V_45 ] == V_58 &&
V_56 == V_59 ) {
return true ;
} else if ( ( V_17 [ V_45 ] ==
V_60 ) &&
V_56 == V_61 ) {
return true ;
}
}
return false ;
}
static bool F_27 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_24 )
{
if ( V_24 == V_62 &&
V_17 [ V_45 ] ==
V_63 &&
( V_17 [ 4 ] & V_64 ) ==
V_65 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_1 )
{
T_2 V_11 [ V_57 ] ;
int V_56 ;
int V_26 ;
T_2 V_32 [ 2 ] ;
int V_19 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
V_19 = F_5 ( V_1 , V_11 , 3 ) ;
if ( V_19 != 3 )
return V_19 < 0 ? V_19 : - V_23 ;
V_26 = F_10 ( & V_11 [ V_53 ] ) ;
if ( V_26 == V_31 ) {
V_1 -> V_66 = V_67 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_32 [ 0 ] = 0x01 ;
V_32 [ 1 ] = 0x00 ;
V_26 = V_57 ;
error = F_19 ( V_1 ,
V_32 , V_31 ,
V_11 , & V_26 ,
300 ,
F_26 ,
false ) ;
if ( error )
return error ;
V_26 = F_10 (
& V_11 [ V_53 ] ) ;
V_56 = F_10 ( & V_11 [ 16 ] ) ;
if ( ( V_26 == V_57 ||
V_26 == V_31 ) &&
( V_11 [ V_45 ] ==
V_58 ) &&
V_56 == V_59 ) {
V_1 -> V_68 = V_69 ;
} else if ( ( V_26 == V_57 ||
V_26 == V_31 ) &&
( V_11 [ V_45 ] ==
V_60 ) &&
V_56 == V_61 ) {
V_1 -> V_68 = V_70 ;
} else {
V_1 -> V_68 = V_71 ;
}
}
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_2 * V_72 )
{
int V_26 ;
T_2 V_11 [ 32 ] ;
int V_56 ;
int V_19 ;
V_19 = F_5 ( V_1 , V_11 ,
V_57 ) ;
if ( V_19 != V_57 )
return V_19 < 0 ? V_19 : - V_23 ;
V_26 = F_10 ( & V_11 [ V_53 ] ) ;
V_56 = F_10 ( & V_11 [ 16 ] ) ;
if ( V_26 == V_31 ) {
if ( V_72 [ V_45 ] ==
V_58 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_69 ;
} else {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_70 ;
}
} else if ( V_26 == V_57 &&
V_11 [ 2 ] == V_58 &&
V_56 == V_59 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_69 ;
} else if ( V_26 == V_57 &&
( V_11 [ V_45 ] ==
V_60 ) &&
V_56 == V_61 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_70 ;
} else {
V_1 -> V_68 = V_71 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_2 * V_72 )
{
int V_26 ;
V_26 = F_10 ( & V_72 [ V_53 ] ) ;
switch ( V_72 [ V_45 ] ) {
case V_73 :
if ( V_26 < V_74 ||
V_26 > V_75 )
return - V_21 ;
break;
case V_76 :
case V_77 :
case V_78 :
if ( V_26 < V_79 ||
V_26 > V_80 )
return - V_21 ;
break;
case V_81 :
if ( V_26 != V_82 )
return - V_21 ;
break;
default:
return - V_21 ;
}
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_70 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_2 * V_72 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_26 ;
int V_19 ;
V_26 = F_10 ( & V_72 [ V_53 ] ) ;
V_19 = F_5 ( V_1 , V_3 -> V_30 , V_26 ) ;
if ( V_19 != V_26 )
return V_19 < 0 ? V_19 : - V_23 ;
if ( V_26 == V_31 ) {
if ( V_72 [ V_45 ] ==
V_46 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_69 ;
} else {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_70 ;
}
} else if ( ( V_3 -> V_30 [ V_45 ] ==
V_46 ) &&
( V_3 -> V_30 [ V_47 ] ==
V_48 ) &&
( V_3 -> V_30 [ V_49 ] ==
V_50 ) &&
( V_3 -> V_30 [ V_26 - 1 ] ==
V_83 ) ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_69 ;
} else if ( V_3 -> V_30 [ V_45 ] ==
V_52 &&
V_3 -> V_30 [ V_47 ] ==
V_48 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_70 ;
} else {
V_1 -> V_68 = V_71 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_2 * V_72 , int V_24 )
{
int V_26 ;
if ( ! V_72 || V_24 < 3 )
return - V_21 ;
V_1 -> V_68 = V_71 ;
V_26 = F_10 ( & V_72 [ V_53 ] ) ;
if ( V_26 == 0 || V_26 == V_31 ) {
F_28 ( V_1 ) ;
} else if ( V_26 == V_57 &&
( V_72 [ 2 ] == V_58 ||
V_72 [ 2 ] == V_60 ) ) {
F_29 ( V_1 , V_72 ) ;
} else if ( ( V_26 == V_84 ||
V_26 == V_85 ) &&
V_72 [ 2 ] == V_86 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_70 ;
} else if ( V_26 == V_87 &&
V_72 [ 2 ] == V_88 ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_68 = V_69 ;
} else if ( V_72 [ 2 ] == V_73 ||
V_72 [ 2 ] == V_76 ||
V_72 [ 2 ] == V_77 ||
V_72 [ 2 ] == V_78 ||
V_72 [ 2 ] == V_81 ) {
F_30 ( V_1 , V_72 ) ;
} else if ( V_72 [ 2 ] == V_46 ||
V_72 [ 2 ] == V_52 ) {
F_31 ( V_1 , V_72 ) ;
}
if ( V_1 -> V_66 == V_67 ) {
F_9 ( V_1 , NULL , NULL , NULL ) ;
if ( V_1 -> V_68 == V_70 ||
V_1 -> V_68 == V_69 )
return 0 ;
}
return - V_89 ;
}
static struct V_90 *
F_33 ( const struct V_91 * V_92 ,
int * V_93 )
{
int V_94 ;
V_94 = V_92 -> V_43 [ 0 ] + 1 ;
* V_93 = ( V_92 -> V_18 - V_94 ) /
sizeof( struct V_90 ) ;
return (struct V_90 * ) & V_92 -> V_43 [ V_94 ] ;
}
int F_34 ( struct V_1 * V_1 , const struct V_91 * V_92 )
{
struct V_90 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
T_2 V_32 [ V_104 ] ;
int V_33 ;
T_5 V_105 ;
T_5 V_106 = 0 ;
T_5 V_107 = 0 ;
T_2 V_11 [ 11 ] ;
int V_12 ;
int V_108 ;
T_2 * V_43 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_32 , 0 , V_104 ) ;
V_97 = (struct V_96 * ) V_32 ;
V_105 = V_109 + V_110 ;
V_33 = sizeof( struct V_96 ) + V_105 +
sizeof( struct V_102 ) ;
F_35 ( V_111 , & V_97 -> V_112 ) ;
F_35 ( V_33 - 2 , & V_97 -> V_26 ) ;
V_97 -> V_113 = V_41 ;
V_99 = & V_97 -> V_114 ;
V_99 -> V_115 = V_50 ;
V_99 -> V_116 = V_117 ;
F_35 ( V_105 , & V_99 -> V_118 ) ;
V_101 = (struct V_100 * ) V_97 -> V_43 ;
memcpy ( V_101 -> V_119 , V_120 , V_109 ) ;
V_95 = F_33 ( V_92 , & V_108 ) ;
V_43 = V_95 [ V_108 - 1 ] . V_121 ;
memcpy ( V_101 -> V_122 , V_43 ,
V_123 ) ;
V_107 = F_36 ( 0xffff , V_101 -> V_122 ,
V_123 ) ;
F_35 ( V_107 , & V_101 -> V_124 ) ;
V_103 = (struct V_102 * ) ( V_97 -> V_43 +
V_105 ) ;
V_106 = F_36 ( 0xffff , ( T_2 * ) V_99 ,
sizeof( struct V_98 ) + V_105 ) ;
F_35 ( V_106 , & V_103 -> V_125 ) ;
V_103 -> V_126 = V_83 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_32 , V_33 ,
V_11 , & V_12 , 12000 ,
F_22 , true ) ;
if ( error || V_12 != V_127 ||
V_11 [ 2 ] != V_46 ||
! F_37 ( V_11 ) )
return error ? error : - V_89 ;
return 0 ;
}
static bool F_38 ( struct V_1 * V_1 , T_2 * V_17 , int V_24 )
{
if ( V_17 == NULL || V_24 < V_31 )
return false ;
if ( V_17 [ 0 ] == 0 && V_17 [ 1 ] == 0 )
return true ;
if ( V_24 == V_128 &&
V_17 [ V_45 ] ==
V_46 &&
V_17 [ V_47 ] == V_48 &&
V_17 [ V_49 ] == V_50 &&
V_17 [ 10 ] == V_83 )
return true ;
return false ;
}
int F_39 ( struct V_1 * V_1 )
{
T_2 V_129 [] = { 0x04 , 0x00 ,
0x0B , 0x00 , 0x40 , 0x00 , 0x01 , 0x3b , 0x00 , 0x00 ,
0x20 , 0xc7 , 0x17
} ;
T_2 V_11 [ 11 ] ;
int V_12 ;
int error ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_129 , sizeof( V_129 ) ,
V_11 , & V_12 ,
5000 , F_38 , false ) ;
if ( error )
return error ;
if ( V_12 == V_128 ||
V_11 [ V_45 ] ==
V_46 )
return - V_89 ;
if ( V_11 [ 0 ] == 0x00 && V_11 [ 1 ] == 0x00 )
return 0 ;
return - V_130 ;
}
int F_40 ( struct V_1 * V_1 )
{
T_2 V_32 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2F , 0x00 , 0x01 } ;
T_2 V_11 [ 2 ] ;
int V_12 ;
int error ;
error = F_41 ( V_1 , 500 ) ;
if ( error < 0 )
return error ;
if ( F_42 ( V_1 ) )
return 0 ;
else if ( ! F_43 ( V_1 ) )
return - V_21 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_12 = sizeof( V_11 ) ;
memset ( V_11 , 0 , V_12 ) ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
5000 , F_25 ,
true ) ;
if ( error || V_11 [ 0 ] != 0x00 || V_11 [ 1 ] != 0x00 )
return error < 0 ? error : - V_89 ;
V_1 -> V_131 = false ;
if ( V_1 -> V_66 == V_67 )
V_1 -> V_68 = V_69 ;
else if ( V_1 -> V_66 == V_132 )
V_1 -> V_68 = V_133 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 ,
struct V_134 * V_135 )
{
if ( V_135 -> V_94 != 0x0C && V_135 -> V_94 != 0x12 )
return - V_21 ;
switch ( V_1 -> V_66 ) {
case V_132 :
if ( V_135 -> V_136 != 0x9B ||
V_135 -> V_137 != 0x0B )
return - V_21 ;
break;
case V_67 :
if ( V_1 -> V_138 < 2 ) {
if ( V_135 -> V_94 == 0x0C )
break;
return - V_21 ;
}
if ( V_135 -> V_136 != 0x91 ||
V_135 -> V_137 != 0x02 )
return - V_21 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
int F_45 ( struct V_1 * V_1 , const struct V_91 * V_92 )
{
struct V_139 * V_140 = & V_1 -> V_22 -> V_140 ;
struct V_90 * V_95 ;
const struct V_90 * V_141 ;
const struct V_142 * V_143 ;
int V_144 ;
T_6 V_145 , V_146 ;
T_5 V_147 , V_148 ;
T_5 V_149 ;
T_5 V_150 ;
int V_151 ;
if ( F_44 ( V_1 ,
(struct V_134 * ) V_92 -> V_43 ) ) {
F_46 ( V_140 , L_1 ,
V_152 ) ;
return - V_21 ;
}
V_95 =
F_33 ( V_92 , & V_144 ) ;
V_141 = & V_95 [ V_144 - 1 ] ;
if ( V_141 -> V_153 != 0x00 ||
F_47 ( & V_141 -> V_154 ) != 0x01ff ) {
F_46 ( V_140 , L_2 , V_152 ) ;
return - V_21 ;
}
V_143 = ( const void * ) V_141 -> V_121 ;
V_150 = F_36 ( 0xffff , V_141 -> V_121 ,
V_155 ) ;
if ( V_150 != F_10 ( & V_143 -> V_124 ) ) {
F_46 ( V_140 , L_3 , V_152 ) ;
return - V_21 ;
}
V_145 = F_48 ( & V_143 -> V_156 ) ;
V_147 = F_10 ( & V_143 -> V_157 ) ;
V_146 = F_48 ( & V_143 -> V_158 ) ;
V_148 = F_10 ( & V_143 -> V_159 ) ;
if ( V_145 % V_160 ||
V_147 % V_160 ||
V_146 % V_160 ||
V_148 % V_160 ) {
F_46 ( V_140 , L_4 , V_152 ) ;
return - V_21 ;
}
V_149 = 0xffffU ;
for ( V_151 = 0 ; V_151 < V_147 / V_160 ; V_151 ++ ) {
const T_2 * V_43 = V_95 [ V_151 ] . V_121 ;
V_149 = F_36 ( V_149 , V_43 , V_160 ) ;
}
if ( V_149 != F_10 ( & V_143 -> V_149 ) ) {
F_46 ( V_140 , L_5 , V_152 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_1 ,
struct V_90 * V_161 )
{
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_162 * V_163 ;
struct V_102 * V_103 ;
T_2 V_32 [ V_104 ] ;
T_5 V_33 ;
T_2 V_153 ;
T_5 V_164 ;
T_5 V_165 ;
T_2 * V_121 ;
T_5 V_166 ;
T_5 V_125 ;
T_2 V_11 [ 11 ] ;
int V_12 ;
int error ;
V_153 = V_161 -> V_153 ;
V_164 = F_47 ( & V_161 -> V_154 ) ;
V_165 = F_47 ( & V_161 -> V_165 ) ;
V_121 = V_161 -> V_121 ;
memset ( V_32 , 0 , V_104 ) ;
V_97 = (struct V_96 * ) V_32 ;
V_99 = & V_97 -> V_114 ;
V_33 = sizeof( struct V_96 ) +
sizeof( struct V_162 ) +
V_110 +
sizeof( struct V_102 ) ;
F_35 ( V_111 , & V_97 -> V_112 ) ;
F_35 ( V_33 - 2 , & V_97 -> V_26 ) ;
V_97 -> V_113 = V_41 ;
V_99 -> V_115 = V_50 ;
V_99 -> V_116 = V_167 ;
V_166 = sizeof( struct V_162 ) + V_165 ;
F_35 ( V_166 , & V_99 -> V_118 ) ;
V_163 = (struct V_162 * ) V_97 -> V_43 ;
V_163 -> V_153 = V_153 ;
F_35 ( V_164 , & V_163 -> V_164 ) ;
memcpy ( V_163 -> V_168 , V_121 , V_165 ) ;
V_103 = (struct V_102 * ) ( V_97 -> V_43 +
V_166 ) ;
V_125 = F_36 ( 0xffff , ( T_2 * ) V_99 ,
sizeof( struct V_98 ) + V_166 ) ;
F_35 ( V_125 , & V_103 -> V_125 ) ;
V_103 -> V_126 = V_83 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , V_33 ,
V_11 , & V_12 ,
500 , F_22 , true ) ;
if ( error || V_12 != V_169 ||
V_11 [ 2 ] != V_46 ||
! F_37 ( V_11 ) )
return error < 0 ? error : - V_89 ;
return 0 ;
}
int F_50 ( struct V_1 * V_1 ,
const struct V_91 * V_92 )
{
struct V_139 * V_140 = & V_1 -> V_22 -> V_140 ;
struct V_90 * V_95 ;
int V_144 ;
int V_151 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_95 =
F_33 ( V_92 , & V_144 ) ;
for ( V_151 = 0 ; V_151 < ( V_144 - 1 ) ; V_151 ++ ) {
error = F_49 ( V_1 , & V_95 [ V_151 ] ) ;
if ( error ) {
F_46 ( V_140 , L_6 ,
V_152 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , T_2 V_170 )
{
T_2 V_32 [ 8 ] = { 0x04 , 0x00 , 0x06 , 0x00 , 0x2f , 0x00 , 0x08 , 0x01 } ;
T_2 V_11 [ 6 ] ;
int V_12 ;
int error ;
V_32 [ 7 ] = V_170 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , false ) ;
if ( error || ! F_52 ( V_11 , 0x08 ) ||
! F_37 ( V_11 ) )
return error < 0 ? error : - V_21 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 ,
T_2 V_171 , T_5 V_172 )
{
struct V_173 * V_174 ;
struct V_175 * V_176 ;
T_2 V_32 [ V_104 ] ;
int V_33 ;
T_2 V_11 [ 7 ] ;
int V_12 ;
T_2 V_177 ;
int error ;
memset ( V_32 , 0 , V_104 ) ;
V_174 = (struct V_173 * ) V_32 ;
V_176 = (struct V_175 * )
V_174 -> V_176 ;
V_33 = sizeof( struct V_173 ) +
sizeof( struct V_175 ) ;
switch ( V_171 ) {
case V_178 :
V_177 = V_179 ;
break;
case V_180 :
V_177 = V_181 ;
break;
case V_182 :
V_177 = V_183 ;
break;
default:
return - V_21 ;
}
F_35 ( V_111 , & V_174 -> V_112 ) ;
F_35 ( V_33 - ( 4 - V_177 ) - 2 ,
& V_174 -> V_26 ) ;
V_174 -> V_113 = V_39 ;
V_174 -> V_116 = V_184 ;
V_176 -> V_171 = V_171 ;
V_176 -> V_177 = V_177 ;
F_54 ( ( T_6 ) V_172 , & V_176 -> V_185 ) ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , V_33 ,
V_11 , & V_12 ,
500 , F_23 , false ) ;
if ( error || V_11 [ 5 ] != V_171 ||
V_11 [ 6 ] != V_177 ||
! F_52 ( V_11 , V_184 ) )
return error < 0 ? error : - V_21 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 ,
T_2 V_171 , T_5 * V_172 )
{
struct V_173 * V_174 ;
struct V_186 * V_176 ;
T_2 V_32 [ V_104 ] ;
int V_33 ;
T_2 V_11 [ 11 ] ;
int V_12 ;
T_2 V_177 ;
T_5 V_187 , V_151 ;
int error ;
memset ( V_32 , 0 , V_104 ) ;
V_174 = (struct V_173 * ) V_32 ;
V_176 = (struct V_186 * )
V_174 -> V_176 ;
V_33 = sizeof( struct V_173 ) +
sizeof( struct V_186 ) ;
* V_172 = 0 ;
switch ( V_171 ) {
case V_178 :
V_177 = V_179 ;
break;
case V_180 :
V_177 = V_181 ;
break;
case V_182 :
V_177 = V_183 ;
break;
default:
return - V_21 ;
}
F_35 ( V_111 , & V_174 -> V_112 ) ;
F_35 ( V_33 - 2 , & V_174 -> V_26 ) ;
V_174 -> V_113 = V_39 ;
V_174 -> V_116 = V_188 ;
V_176 -> V_171 = V_171 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , V_33 ,
V_11 , & V_12 ,
500 , F_23 , false ) ;
if ( error || V_11 [ 5 ] != V_171 || V_11 [ 6 ] == 0 ||
! F_52 ( V_11 , V_188 ) )
return error < 0 ? error : - V_21 ;
V_187 = 0 ;
for ( V_151 = 0 ; V_151 < V_177 ; V_151 ++ )
V_187 |= ( 0xff << ( V_151 * 8 ) ) ;
* V_172 = F_10 ( & V_11 [ 7 ] ) & V_187 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_173 * V_174 ;
T_2 V_32 [ 10 ] ;
T_2 V_11 [ 7 ] ;
int V_12 ;
int error ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_174 = (struct V_173 * ) V_32 ;
F_35 ( V_111 , & V_174 -> V_112 ) ;
F_35 ( sizeof( V_32 ) - 2 , & V_174 -> V_26 ) ;
V_174 -> V_113 = V_39 ;
V_174 -> V_116 = V_184 ;
V_174 -> V_176 [ 0 ] = V_189 ;
V_174 -> V_176 [ 1 ] = 0x01 ;
V_174 -> V_176 [ 2 ] = 0x01 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , false ) ;
if ( error || V_11 [ 5 ] != V_189 ||
! F_52 ( V_11 , V_184 ) ||
V_11 [ 6 ] != 0x01 )
return error < 0 ? error : - V_21 ;
return 0 ;
}
int F_57 ( struct V_1 * V_1 , bool V_190 )
{
T_2 V_32 [] = { 0x04 , 0x00 , 0x06 , 0x00 , 0x2f , 0x00 , V_191 ,
( T_2 ) ! ! V_190
} ;
T_2 V_11 [ 6 ] ;
int V_12 ;
int error ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , false ) ;
if ( error || ! F_52 ( V_11 , V_191 ) ||
! F_37 ( V_11 ) ) {
error = ( error == - V_35 ) ? - V_192 : error ;
return error < 0 ? error : - V_21 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_1 , T_2 V_68 )
{
T_2 V_32 [] = { 0x05 , 0x00 , 0x00 , 0x08 } ;
T_2 V_11 [ 5 ] ;
int V_12 ;
int error ;
V_32 [ 2 ] = V_68 & V_193 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 , V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_27 , false ) ;
if ( error || ( ( V_11 [ 3 ] & V_193 ) != V_68 ) )
return - V_21 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 ,
T_2 V_194 , T_5 V_195 , bool V_196 )
{
struct V_139 * V_140 = & V_1 -> V_22 -> V_140 ;
T_2 V_170 ;
int error ;
if ( V_1 -> V_68 != V_70 )
return 0 ;
if ( F_60 ( V_1 ) == V_14 ) {
F_61 ( V_1 , V_197 ) ;
}
if ( F_62 ( V_1 ) &&
F_60 ( V_1 ) != V_197 )
if ( F_55 ( V_1 ,
V_182 ,
& V_1 -> V_15 ) != 0 )
F_63 ( V_1 , V_16 ) ;
if ( F_60 ( V_1 ) == V_194 ) {
if ( V_194 == V_197 ||
V_194 == V_198 ||
V_194 == V_199 ||
F_64 ( V_1 ) == V_195 ) {
return 0 ;
}
}
if ( V_194 == V_197 ) {
error = F_58 ( V_1 , V_200 ) ;
if ( error ) {
F_46 ( V_140 , L_7 , error ) ;
return error ;
}
F_61 ( V_1 , V_197 ) ;
return 0 ;
}
if ( F_60 ( V_1 ) == V_197 ) {
error = F_58 ( V_1 , V_201 ) ;
if ( error ) {
F_46 ( V_140 , L_8 , error ) ;
return error ;
}
}
if ( V_194 == V_198 ) {
error = F_51 ( V_1 ,
V_202 ) ;
if ( error ) {
F_46 ( V_140 , L_9 , error ) ;
return error ;
}
F_61 ( V_1 , V_198 ) ;
} else if ( V_194 == V_199 ) {
error = F_51 ( V_1 ,
V_203 ) ;
if ( error ) {
F_46 ( V_140 , L_10 , error ) ;
return error ;
}
F_61 ( V_1 , V_199 ) ;
} else {
if ( F_62 ( V_1 ) ||
V_195 != F_64 ( V_1 ) )
if ( F_53 ( V_1 ,
V_182 ,
V_195 ) == 0 )
F_63 ( V_1 , V_195 ) ;
if ( V_195 <= V_204 )
V_170 = V_205 ;
else
V_170 = V_206 ;
error = F_51 ( V_1 , V_170 ) ;
if ( error ) {
F_46 ( V_140 , L_11 ,
V_170 , error ) ;
return error ;
}
if ( V_196 )
F_56 ( V_1 ) ;
F_61 ( V_1 ,
F_65 ( V_195 ) ) ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_1 )
{
T_2 V_32 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x04 } ;
T_2 V_11 [ 6 ] ;
int V_12 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , true ) ;
if ( error || ! F_52 ( V_11 , 0x04 ) )
return - V_21 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_1 )
{
T_2 V_32 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x03 } ;
T_2 V_11 [ 6 ] ;
int V_12 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , true ) ;
if ( error || ! F_52 ( V_11 , 0x03 ) )
return - V_21 ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_1 ,
T_2 V_207 )
{
struct V_173 * V_174 ;
T_2 V_32 [ 8 ] ;
T_2 V_11 [ 6 ] ;
int V_12 ;
int error ;
F_9 ( V_1 , NULL , NULL , NULL ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_174 = (struct V_173 * ) V_32 ;
F_35 ( V_111 , & V_174 -> V_112 ) ;
F_35 ( sizeof( V_32 ) - 2 , & V_174 -> V_26 ) ;
V_174 -> V_113 = V_39 ;
V_174 -> V_116 = V_208 ;
V_174 -> V_176 [ 0 ] = V_207 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
5000 , F_23 , true ) ;
if ( error || ! F_52 ( V_11 , V_208 ) ||
! F_37 ( V_11 ) )
return error < 0 ? error : - V_89 ;
return 0 ;
}
T_1 F_69 ( struct V_139 * V_140 ,
struct V_209 * V_210 ,
const char * V_17 , T_3 V_211 )
{
struct V_1 * V_1 = F_70 ( V_140 ) ;
int error , V_212 ;
error = F_67 ( V_1 ) ;
if ( error )
return error ;
V_212 = F_68 ( V_1 ,
V_213 ) ;
if ( V_212 )
goto V_214;
V_212 = F_68 ( V_1 ,
V_215 ) ;
if ( V_212 )
goto V_214;
V_214:
error = F_66 ( V_1 ) ;
if ( error || V_212 )
return error ? error : V_212 ;
return V_211 ;
}
static T_7 F_71 ( T_7 V_185 , int V_216 )
{
if ( V_185 >> ( V_216 - 1 ) )
V_185 |= - 1 << V_216 ;
return V_185 ;
}
static T_7 F_72 ( T_2 V_217 , T_2 * V_17 , int V_29 )
{
int V_218 ;
bool V_219 ;
bool V_220 ;
T_7 V_185 ;
V_218 = ( V_217 & 0x07 ) ;
V_219 = ( ( V_217 & 0x10 ) == 0x00 ) ;
V_220 = ( ( V_217 & 0x20 ) == 0x00 ) ;
if ( V_29 < V_218 )
return 0 ;
switch ( V_218 ) {
case 1 :
V_185 = V_17 [ 0 ] ;
break;
case 2 :
if ( V_219 )
V_185 = F_47 ( V_17 ) ;
else
V_185 = F_10 ( V_17 ) ;
break;
case 4 :
if ( V_219 )
V_185 = F_73 ( V_17 ) ;
else
V_185 = F_48 ( V_17 ) ;
break;
default:
V_185 = 0 ;
break;
}
if ( ! V_220 )
V_185 = F_71 ( V_185 , V_218 * 8 ) ;
return V_185 ;
}
static void F_74 ( struct V_1 * V_1 ,
int * V_221 , int * V_222 )
{
if ( V_1 -> V_221 != 0 ) {
* V_221 = V_1 -> V_221 ;
* V_222 = ( V_1 -> V_223 == * V_221 ) ?
V_1 -> V_224 : V_1 -> V_223 ;
} else {
* V_222 = F_11 ( V_1 -> V_223 , V_1 -> V_224 ) ;
* V_221 = F_75 ( V_1 -> V_223 , V_1 -> V_224 ) ;
}
}
static int F_76 ( struct V_1 * V_1 ,
T_2 V_116 , T_2 V_225 , int * V_218 ,
int * V_226 , int * V_227 , int * V_228 )
{
struct V_173 * V_229 ;
T_2 V_32 [ 12 ] ;
T_2 V_11 [ 256 ] ;
int V_12 ;
int V_230 ;
int V_185 ;
T_5 V_231 ;
int V_232 ;
bool V_233 ;
int V_234 , V_211 , V_235 ;
int V_236 , V_237 , V_238 , V_239 , V_240 ;
int V_221 , V_222 ;
int V_151 ;
int error ;
if ( V_116 != V_241 ||
( V_225 != V_242 &&
V_225 != V_243 ) ||
! V_218 || ! V_226 || ! V_227 || ! V_228 )
return - V_21 ;
* V_226 = V_244 ;
* V_227 = V_245 ;
V_234 = V_211 = V_240 = 0 ;
V_221 = V_222 = 0 ;
if ( * V_218 == 0 ) {
V_233 = true ;
V_231 = 0 ;
* V_218 = 4 ;
V_236 = V_244 ;
V_237 = V_245 ;
V_238 = V_239 = V_240 = 0 ;
if ( V_225 == V_242 ) {
if ( V_1 -> V_246 == 0 ) {
F_74 ( V_1 ,
& V_221 , & V_222 ) ;
V_1 -> V_246 =
( V_221 + 3 ) & ~ 3u ;
}
V_235 =
( V_1 -> V_246 + 7 ) & ~ 7u ;
} else {
V_235 = 2 ;
}
} else {
V_233 = false ;
if ( * V_218 > 4 )
* V_218 = 4 ;
if ( V_225 == V_242 ) {
V_231 = V_1 -> V_246 * ( * V_218 ) ;
if ( V_1 -> V_221 == V_1 -> V_223 )
V_222 = V_1 -> V_224 ;
else
V_222 = V_1 -> V_223 ;
V_235 = ( ( V_1 -> V_246 + 7 ) &
~ 7u ) * V_222 ;
} else {
V_231 = 2 ;
V_235 = V_1 -> V_223 +
V_1 -> V_224 ;
V_235 = ( V_235 + 3 ) & ~ 3u ;
}
}
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_229 = (struct V_173 * ) V_32 ;
F_35 ( V_111 , & V_229 -> V_112 ) ;
F_35 ( sizeof( V_32 ) - 2 , & V_229 -> V_26 ) ;
V_229 -> V_113 = V_39 ;
V_229 -> V_116 = V_116 ;
do {
V_232 = ( 256 - V_247 ) /
( * V_218 ) ;
V_232 = F_11 ( V_232 , V_235 - V_211 ) ;
V_230 = V_232 * ( * V_218 ) ;
F_35 ( V_231 , & V_229 -> V_176 [ 0 ] ) ;
F_35 ( V_230 , & V_229 -> V_176 [ 2 ] ) ;
V_229 -> V_176 [ 4 ] = V_225 ;
V_12 = V_247 + V_230 ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 ,
true ) ;
if ( error || V_12 < V_247 ||
! F_52 ( V_11 , V_116 ) ||
! F_37 ( V_11 ) ||
V_11 [ 6 ] != V_225 )
return ( error < 0 ) ? error : - V_89 ;
V_230 = F_10 ( & V_11 [ 7 ] ) ;
if ( V_230 == 0 )
break;
* V_218 = ( V_11 [ 9 ] & V_248 ) ;
if ( V_230 < * V_218 )
return - V_21 ;
if ( V_233 &&
V_225 == V_243 ) {
* V_226 = F_72 (
V_11 [ 9 ] ,
& V_11 [ V_247 ] ,
* V_218 ) ;
* V_227 = F_72 (
V_11 [ 9 ] ,
& V_11 [ V_247 +
* V_218 ] ,
* V_218 ) ;
break;
}
V_231 += V_230 ;
for ( V_151 = 10 ; V_151 < ( V_230 + V_247 ) ;
V_151 += * V_218 ) {
V_185 = F_72 ( V_11 [ 9 ] ,
& V_11 [ V_151 ] , * V_218 ) ;
* V_227 = F_11 ( V_185 , * V_227 ) ;
* V_226 = F_75 ( V_185 , * V_226 ) ;
if ( V_225 == V_242 &&
V_240 < V_1 -> V_246 &&
V_233 ) {
if ( ! V_238 || V_185 > V_238 / 2 ) {
V_237 = F_11 ( V_185 , V_237 ) ;
V_236 = F_75 ( V_185 , V_236 ) ;
V_239 += V_185 ;
V_240 ++ ;
V_238 = V_239 / V_240 ;
}
}
V_234 += V_185 ;
V_211 ++ ;
if ( V_211 >= V_235 )
goto V_249;
}
} while ( true );
V_249:
* V_228 = V_211 ? ( V_234 / V_211 ) : 0 ;
if ( V_233 &&
V_225 == V_242 ) {
if ( V_240 == 0 )
return 0 ;
if ( V_240 == V_1 -> V_246 ) {
V_1 -> V_221 = V_1 -> V_221 ?
V_1 -> V_221 : V_221 ;
} else if ( V_240 == V_221 ) {
V_1 -> V_221 = V_1 -> V_221 ?
V_1 -> V_221 : V_221 ;
V_1 -> V_246 = V_221 ;
} else {
V_1 -> V_221 = V_1 -> V_221 ?
V_1 -> V_221 : V_222 ;
V_1 -> V_246 = V_240 ;
}
* V_227 = V_237 ;
* V_226 = V_236 ;
* V_228 = V_238 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_1 ,
int * V_250 , int * V_251 , int * V_252 ,
int * V_253 , int * V_254 , int * V_255 )
{
int V_218 ;
int error ;
* V_250 = * V_251 = * V_252 = 0 ;
* V_253 = * V_254 = * V_255 = 0 ;
V_218 = 0 ;
error = F_76 ( V_1 ,
V_241 ,
V_242 ,
& V_218 ,
V_250 , V_251 , V_252 ) ;
if ( error )
return error ;
error = F_76 ( V_1 ,
V_241 ,
V_242 ,
& V_218 ,
V_253 , V_254 , V_255 ) ;
return error ;
}
static int F_78 ( struct V_1 * V_1 ,
int * V_256 , int * V_257 ,
int * V_258 , int * V_259 , int * V_260 )
{
int V_218 ;
int error ;
* V_256 = * V_257 = 0 ;
* V_258 = * V_259 = * V_260 = 0 ;
V_218 = 0 ;
error = F_76 ( V_1 ,
V_241 ,
V_243 ,
& V_218 ,
V_258 , V_259 , V_260 ) ;
if ( error )
return error ;
* V_256 = * V_258 ;
* V_257 = * V_259 ;
error = F_76 ( V_1 ,
V_241 ,
V_243 ,
& V_218 ,
V_258 , V_259 , V_260 ) ;
return error ;
}
static T_1 F_79 ( struct V_1 * V_1 )
{
struct V_173 * V_174 ;
T_2 V_32 [ 7 ] ;
T_2 V_11 [ 6 ] ;
int V_12 ;
int error ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_174 = (struct V_173 * ) V_32 ;
F_35 ( V_111 , & V_174 -> V_112 ) ;
F_35 ( sizeof( V_32 ) - 2 , & V_174 -> V_26 ) ;
V_174 -> V_113 = V_39 ;
V_174 -> V_116 = V_261 ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , true ) ;
if ( error || V_12 != sizeof( V_11 ) ||
! F_52 ( V_11 ,
V_261 ) ||
! F_37 ( V_11 ) )
return error ? error : - V_89 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_1 ,
T_2 V_116 , T_2 V_262 , int V_263 ,
int * V_264 , int * V_265 , int * V_266 ,
T_2 * V_267 )
{
struct V_173 * V_174 ;
struct V_268 * V_269 ;
T_2 V_32 [ 12 ] ;
T_2 V_11 [ 256 ] ;
int V_12 ;
int V_232 ;
int V_230 ;
T_5 V_231 ;
T_7 V_185 ;
int V_234 , V_211 ;
int V_218 ;
T_7 * V_270 ;
int V_151 ;
int error ;
if ( V_116 != V_271 ||
( V_262 > V_272 ) ||
! V_264 || ! V_265 || ! V_266 )
return - V_21 ;
V_270 = ( T_7 * ) V_267 ;
* V_264 = V_244 ;
* V_265 = V_245 ;
V_234 = V_211 = 0 ;
V_231 = 0 ;
V_232 = ( 256 - V_247 ) / 4 ;
V_230 = V_232 * 4 ;
V_174 = (struct V_173 * ) V_32 ;
F_35 ( V_111 , & V_174 -> V_112 ) ;
F_35 ( sizeof( V_32 ) - 2 , & V_174 -> V_26 ) ;
V_174 -> V_113 = V_39 ;
V_174 -> V_116 = V_116 ;
V_269 = (struct V_268 * )
V_174 -> V_176 ;
do {
F_35 ( V_231 , & V_269 -> V_273 ) ;
F_35 ( V_232 ,
& V_269 -> V_232 ) ;
V_269 -> V_274 = V_262 ;
V_12 = V_247 + V_230 ;
error = F_19 ( V_1 ,
V_32 , sizeof( V_32 ) ,
V_11 , & V_12 ,
500 , F_23 , true ) ;
if ( error || V_12 < V_247 ||
! F_52 ( V_11 , V_116 ) ||
! F_37 ( V_11 ) ||
V_11 [ 6 ] != V_262 )
return error ? error : - V_89 ;
V_232 = F_10 ( & V_11 [ 7 ] ) ;
if ( V_232 == 0 )
break;
V_218 = ( V_11 [ 9 ] & V_248 ) ;
V_231 += V_232 ;
if ( V_232 ) {
for ( V_151 = V_247 ;
V_151 < ( V_232 * V_218 +
V_247 ) ;
V_151 += V_218 ) {
V_185 = F_72 ( V_11 [ 9 ] ,
& V_11 [ V_151 ] , V_218 ) ;
* V_265 = F_11 ( V_185 , * V_265 ) ;
* V_264 = F_75 ( V_185 , * V_264 ) ;
if ( V_270 )
F_54 ( V_185 , & V_270 [ V_211 ] ) ;
V_234 += V_185 ;
V_211 ++ ;
}
}
if ( V_211 >= V_263 )
break;
V_232 = ( sizeof( V_11 ) -
V_247 ) / V_218 ;
V_230 = V_232 * V_218 ;
} while ( true );
* V_266 = V_211 ? ( V_234 / V_211 ) : 0 ;
return 0 ;
}
static T_1 F_81 ( struct V_139 * V_140 ,
struct V_209 * V_210 , char * V_17 )
{
struct V_1 * V_1 = F_70 ( V_140 ) ;
int V_250 , V_251 , V_252 ;
int V_253 , V_254 , V_255 ;
int V_256 , V_257 ;
int V_258 , V_259 , V_260 ;
int V_275 , V_276 , V_277 ;
int V_278 , V_279 , V_280 ;
int V_281 , V_282 , V_283 ;
int V_284 , V_285 , V_286 ;
int V_287 , V_288 , V_289 ;
int V_290 , V_291 , V_292 ;
int error , V_293 ;
int V_18 ;
if ( ! F_43 ( V_1 ) )
return - V_294 ;
error = F_67 ( V_1 ) ;
if ( error )
return error ;
V_256 = V_257 = 0 ;
error = F_77 ( V_1 ,
& V_250 , & V_251 ,
& V_252 , & V_253 ,
& V_254 , & V_255 ) ;
if ( error )
goto V_214;
error = F_78 ( V_1 ,
& V_256 , & V_257 ,
& V_258 , & V_259 ,
& V_260 ) ;
if ( error )
goto V_214;
error = F_79 ( V_1 ) ;
if ( error )
goto V_214;
error = F_80 ( V_1 ,
V_271 ,
V_295 ,
V_1 -> V_223 * V_1 -> V_224 ,
& V_275 , & V_276 ,
& V_277 ,
NULL ) ;
if ( error )
goto V_214;
error = F_80 ( V_1 ,
V_271 ,
V_296 ,
V_1 -> V_223 + V_1 -> V_224 ,
& V_278 , & V_279 ,
& V_280 ,
NULL ) ;
if ( error )
goto V_214;
error = F_80 ( V_1 ,
V_271 ,
V_297 ,
V_1 -> V_223 * V_1 -> V_224 ,
& V_281 , & V_282 ,
& V_283 ,
NULL ) ;
if ( error )
goto V_214;
error = F_80 ( V_1 ,
V_271 ,
V_272 ,
V_1 -> V_223 + V_1 -> V_224 ,
& V_284 , & V_285 ,
& V_286 ,
NULL ) ;
if ( error )
goto V_214;
error = F_80 ( V_1 ,
V_271 ,
V_298 ,
V_1 -> V_223 * V_1 -> V_224 ,
& V_287 , & V_288 ,
& V_289 ,
NULL ) ;
if ( error )
goto V_214;
error = F_80 ( V_1 ,
V_271 ,
V_299 ,
V_1 -> V_223 + V_1 -> V_224 ,
& V_290 , & V_291 ,
& V_292 ,
NULL ) ;
if ( error )
goto V_214;
V_214:
V_293 = F_66 ( V_1 ) ;
if ( V_293 || error )
return V_293 ? V_293 : error ;
V_18 = F_82 ( V_17 , V_300 , L_12 ,
V_251 , V_250 , V_252 ,
V_254 , V_253 , V_255 ,
V_256 , V_257 ,
V_259 , V_258 , V_260 ) ;
V_18 += F_82 ( V_17 + V_18 , V_300 - V_18 ,
L_13 ,
V_276 , V_275 , V_277 ,
V_279 , V_278 , V_280 ,
V_282 , V_281 , V_283 ,
V_285 , V_284 , V_286 ,
V_288 , V_287 , V_289 ,
V_291 , V_290 , V_292 ) ;
return V_18 ;
}
bool F_83 ( struct V_1 * V_1 ,
T_2 * V_17 , int V_24 )
{
if ( F_52 ( V_17 , 0x02 ) )
return true ;
return false ;
}
static int F_84 ( struct V_1 * V_1 )
{
T_2 V_11 [ V_301 ] ;
int V_12 ;
int error ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_302 , V_303 ,
V_11 , & V_12 ,
500 , F_22 , false ) ;
if ( error || V_12 < V_301 ||
! F_37 ( V_11 ) )
return error ? error : - V_23 ;
memcpy ( & V_1 -> V_304 [ 0 ] , & V_11 [ 8 ] , 5 ) ;
V_1 -> V_304 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_304 [ 6 ] , & V_11 [ 13 ] , 6 ) ;
V_1 -> V_304 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_304 [ 13 ] , & V_11 [ 19 ] , 2 ) ;
V_1 -> V_304 [ 15 ] = '\0' ;
V_1 -> V_305 = V_11 [ 22 ] ;
V_1 -> V_306 = V_11 [ 23 ] ;
V_1 -> V_138 = ( V_11 [ 26 ] >> V_307 ) &
V_308 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_1 )
{
T_2 V_11 [ V_309 ] ;
int V_12 ;
T_5 V_310 ;
int error ;
V_12 = sizeof( V_11 ) ;
error = F_19 ( V_1 ,
V_311 , V_312 ,
V_11 , & V_12 ,
2000 , F_83 , false ) ;
if ( error || V_12 < sizeof( V_11 ) )
return error ? error : - V_23 ;
V_310 = F_10 ( & V_11 [ 7 ] ) ;
if ( ( V_310 & V_313 ) !=
V_314 )
return - V_21 ;
V_1 -> V_138 = ( V_11 [ 49 ] >> V_307 ) &
V_308 ;
if ( V_1 -> V_66 == V_67 && V_1 -> V_138 < 2 ) {
V_1 -> V_305 = V_11 [ 15 ] ;
V_1 -> V_306 = V_11 [ 16 ] ;
} else {
V_1 -> V_305 = V_11 [ 9 ] ;
V_1 -> V_306 = V_11 [ 10 ] ;
}
V_1 -> V_223 = V_11 [ 52 ] ;
V_1 -> V_224 = V_11 [ 53 ] ;
V_1 -> V_315 = F_10 ( & V_11 [ 54 ] ) / 100 ;
V_1 -> V_316 = F_10 ( & V_11 [ 56 ] ) / 100 ;
V_1 -> V_317 = F_10 ( & V_11 [ 58 ] ) ;
V_1 -> V_318 = F_10 ( & V_11 [ 60 ] ) ;
V_1 -> V_319 = F_10 ( & V_11 [ 62 ] ) ;
V_1 -> V_320 = V_11 [ 64 ] & 0x01 ;
V_1 -> V_321 = V_11 [ 65 ] & 0x01 ;
V_1 -> V_322 = ( V_11 [ 70 ] << 3 ) & V_323 ;
memcpy ( & V_1 -> V_304 [ 0 ] , & V_11 [ 33 ] , 5 ) ;
V_1 -> V_304 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_304 [ 6 ] , & V_11 [ 38 ] , 6 ) ;
V_1 -> V_304 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_304 [ 13 ] , & V_11 [ 44 ] , 2 ) ;
V_1 -> V_304 [ 15 ] = '\0' ;
if ( ! V_1 -> V_223 || ! V_1 -> V_224 ||
! V_1 -> V_315 || ! V_1 -> V_316 ||
! V_1 -> V_317 || ! V_1 -> V_318 || ! V_1 -> V_319 )
return - V_21 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_1 )
{
struct V_139 * V_140 = & V_1 -> V_22 -> V_140 ;
int error ;
if ( V_1 -> V_66 != V_67 )
return - V_130 ;
switch ( V_1 -> V_68 ) {
case V_69 :
error = F_39 ( V_1 ) ;
if ( error ) {
F_84 ( V_1 ) ;
goto V_249;
}
V_1 -> V_68 = V_70 ;
case V_70 :
error = F_59 ( V_1 ,
V_198 , 0 , false ) ;
if ( error )
F_87 ( V_140 , L_14 ,
V_152 ) ;
if ( V_1 -> V_138 >= 2 ) {
error = F_57 ( V_1 , true ) ;
if ( error )
F_87 ( V_140 ,
L_15 ,
V_152 ) ;
}
error = F_85 ( V_1 ) ;
if ( error )
goto V_249;
if ( memcmp ( V_1 -> V_304 , V_304 ,
strlen ( V_304 ) ) != 0 ) {
F_46 ( V_140 , L_16 ,
V_152 , V_1 -> V_304 ) ;
error = - V_21 ;
}
break;
default:
error = - V_21 ;
}
V_249:
return error ;
}
bool F_88 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_3 ;
int V_26 ;
if ( F_89 ( & V_3 -> V_6 ) ) {
if ( V_3 -> V_42 == false )
return false ;
F_5 ( V_1 , V_3 -> V_324 ,
V_31 ) ;
V_26 = F_10 ( V_3 -> V_324 ) ;
V_26 = ( V_26 <= V_31 ) ?
V_31 : V_26 ;
if ( V_26 > V_31 )
F_5 ( V_1 ,
V_3 -> V_324 , V_26 ) ;
if ( ! ( V_3 -> V_8 &&
V_3 -> V_8 ( V_1 ,
V_3 -> V_324 , V_26 ) ) ) {
V_26 = 0 ;
if ( V_3 -> V_12 )
V_26 = * V_3 -> V_12 ;
F_9 ( V_1 ,
V_3 -> V_11 ,
& V_26 ,
V_3 -> V_8 ) ;
if ( V_3 -> V_12 && V_26 != 0 ) {
* V_3 -> V_12 = V_26 ;
F_14 ( & V_3 -> V_6 ) ;
F_90 ( & V_3 -> V_5 ) ;
}
return false ;
}
if ( V_3 -> V_11 && V_3 -> V_12 ) {
* V_3 -> V_12 = ( * V_3 -> V_12 < V_26 ) ?
* V_3 -> V_12 : V_26 ;
memcpy ( V_3 -> V_11 , V_3 -> V_324 ,
* V_3 -> V_12 ) ;
}
F_14 ( & V_3 -> V_6 ) ;
F_90 ( & V_3 -> V_5 ) ;
return false ;
}
return true ;
}
static void F_91 ( struct V_1 * V_1 ,
const struct V_325 * V_326 )
{
struct V_327 * V_328 = V_1 -> V_328 ;
T_2 V_329 = V_326 -> V_330 [ V_331 ] ;
V_329 = ( V_329 << V_332 ) & V_323 ;
if ( V_1 -> V_322 & V_333 ) {
F_92 ( V_328 , V_334 ,
! ! ( V_329 & V_333 ) ) ;
}
if ( V_1 -> V_322 & V_335 ) {
F_92 ( V_328 , V_336 ,
! ! ( V_329 & V_335 ) ) ;
}
if ( V_1 -> V_322 & V_337 ) {
F_92 ( V_328 , V_338 ,
! ! ( V_329 & V_337 ) ) ;
}
F_93 ( V_328 ) ;
}
static void F_94 ( struct V_1 * V_1 ,
const struct V_325 * V_326 )
{
struct V_327 * V_328 = V_1 -> V_328 ;
T_2 V_339 = V_326 -> V_330 [ V_340 ] &
V_341 ;
F_95 ( V_328 , V_342 , V_339 ) ;
F_93 ( V_328 ) ;
}
static void F_96 ( struct V_1 * V_1 ,
const struct V_343 * V_344 )
{
struct V_327 * V_328 = V_1 -> V_328 ;
T_2 V_345 = F_97 ( V_344 -> V_346 ) ;
int V_347 = F_98 ( V_344 -> V_346 ) ;
int V_348 , V_349 ;
if ( V_345 == V_350 )
return;
F_99 ( V_328 , V_347 ) ;
F_100 ( V_328 , V_351 , true ) ;
V_348 = ( V_344 -> V_352 << 8 ) | V_344 -> V_353 ;
if ( V_1 -> V_320 )
V_348 = V_1 -> V_317 - V_348 ;
V_349 = ( V_344 -> V_354 << 8 ) | V_344 -> V_355 ;
if ( V_1 -> V_321 )
V_349 = V_1 -> V_318 - V_349 ;
F_95 ( V_328 , V_356 , V_348 ) ;
F_95 ( V_328 , V_357 , V_349 ) ;
F_95 ( V_328 , V_342 , 0 ) ;
F_95 ( V_328 , V_358 ,
V_344 -> V_359 ) ;
F_95 ( V_328 , V_360 ,
V_344 -> V_361 ) ;
F_95 ( V_328 , V_362 ,
V_344 -> V_363 ) ;
F_95 ( V_328 , V_364 ,
V_344 -> V_365 ) ;
F_95 ( V_328 , V_366 ,
V_344 -> V_367 ) ;
F_95 ( V_328 , V_368 ,
V_344 -> V_369 ) ;
}
static void F_101 ( struct V_1 * V_1 ,
const struct V_325 * V_326 )
{
struct V_327 * V_328 = V_1 -> V_328 ;
unsigned int V_370 ;
int V_151 ;
V_370 = V_326 -> V_330 [ V_371 ] &
V_372 ;
for ( V_151 = 0 ; V_151 < V_370 ; V_151 ++ )
F_96 ( V_1 ,
& V_326 -> V_373 [ V_151 ] ) ;
F_102 ( V_328 ) ;
F_93 ( V_328 ) ;
}
int F_103 ( struct V_1 * V_1 )
{
struct V_139 * V_140 = & V_1 -> V_22 -> V_140 ;
struct V_325 V_326 ;
unsigned int V_374 ;
T_2 V_113 ;
int V_19 ;
if ( ! F_43 ( V_1 ) ) {
F_46 ( V_140 , L_17 ,
V_1 -> V_66 , V_1 -> V_68 ) ;
return - V_21 ;
}
V_19 = F_5 ( V_1 , ( T_2 * ) & V_326 ,
V_31 ) ;
if ( V_19 != V_31 ) {
F_46 ( V_140 , L_18 , V_19 ) ;
return - V_21 ;
}
V_374 = F_10 (
& V_326 . V_330 [ V_53 ] ) ;
if ( V_374 < V_31 ) {
F_46 ( V_140 , L_19 ,
V_374 , V_326 . V_330 [ 0 ] ,
V_326 . V_330 [ 1 ] ) ;
return - V_21 ;
}
if ( V_374 == V_31 )
return 0 ;
V_19 = F_5 ( V_1 , ( T_2 * ) & V_326 , V_374 ) ;
if ( V_19 != V_374 ) {
F_46 ( V_140 , L_20 ,
V_374 , V_19 ) ;
return - V_21 ;
}
V_113 = V_326 . V_330 [ V_45 ] ;
if ( V_113 == V_81 &&
V_374 == V_82 ) {
F_104 ( V_140 ) ;
F_105 ( V_140 ) ;
F_106 ( V_140 ) ;
return 0 ;
} else if ( V_113 != V_73 &&
V_113 != V_76 &&
V_113 != V_77 &&
V_113 != V_78 &&
V_113 != V_375 ) {
F_46 ( V_140 , L_21 , V_113 ) ;
return - V_21 ;
}
if ( V_113 == V_73 &&
( V_374 < V_74 ||
V_374 > V_75 ) ) {
F_46 ( V_140 , L_22 , V_374 ) ;
return 0 ;
}
if ( ( V_113 == V_76 ||
V_113 == V_77 ||
V_113 == V_78 ) &&
( V_374 < V_79 ||
V_374 > V_80 ) ) {
F_46 ( V_140 , L_23 , V_374 ) ;
return 0 ;
}
if ( V_113 == V_375 &&
V_374 != V_376 ) {
F_46 ( V_140 , L_24 , V_374 ) ;
return 0 ;
}
if ( V_113 == V_73 )
F_101 ( V_1 , & V_326 ) ;
else if ( V_113 == V_375 )
F_94 ( V_1 , & V_326 ) ;
else
F_91 ( V_1 , & V_326 ) ;
return 0 ;
}
int F_107 ( struct V_1 * V_1 ) { return 0 ; }
int F_108 ( struct V_1 * V_1 ) { return 0 ; }
