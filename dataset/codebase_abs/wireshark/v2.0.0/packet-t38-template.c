static void F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
void F_5 ( T_1 * V_3 ,
T_2 * V_4 , int V_5 ,
int V_6 ,
const T_3 * V_7 , T_4 V_8 )
{
T_2 V_9 ;
T_5 * V_10 ;
T_6 * V_11 = NULL ;
if ( ( V_3 -> V_12 -> V_13 . V_14 ) || ( V_15 == NULL ) )
{
return;
}
F_6 ( & V_9 , V_16 , 0 , NULL ) ;
V_10 = F_7 ( V_8 , V_4 , & V_9 , V_17 , V_5 , V_6 ,
V_18 | ( ! V_6 ? V_19 : 0 ) ) ;
if ( ! V_10 || V_10 -> V_20 != V_8 ) {
V_10 = F_8 ( V_8 , V_4 , & V_9 , V_17 ,
( T_4 ) V_5 , ( T_4 ) V_6 ,
V_21 | ( ! V_6 ? V_22 : 0 ) ) ;
}
F_9 ( V_10 , V_15 ) ;
V_11 = ( T_6 * ) F_10 ( V_10 , V_23 ) ;
if ( ! V_11 ) {
V_11 = F_11 ( F_12 () , T_6 ) ;
F_13 ( V_10 , V_23 , V_11 ) ;
}
F_14 ( V_11 -> V_7 , V_7 , V_24 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_25 . V_26 = 0 ;
V_11 -> V_25 . V_27 = - 1 ;
V_11 -> V_25 . V_28 = 0 ;
V_11 -> V_25 . V_29 = - 1 ;
V_11 -> V_25 . V_30 = 0 ;
V_11 -> V_25 . V_31 = 0 ;
V_11 -> V_25 . V_32 = 0 ;
V_11 -> V_25 . V_33 = 0 ;
V_11 -> V_25 . V_34 = - 1 ;
V_11 -> V_35 . V_26 = 0 ;
V_11 -> V_35 . V_27 = - 1 ;
V_11 -> V_35 . V_28 = 0 ;
V_11 -> V_35 . V_29 = - 1 ;
V_11 -> V_35 . V_30 = 0 ;
V_11 -> V_35 . V_31 = 0 ;
V_11 -> V_35 . V_32 = 0 ;
V_11 -> V_35 . V_33 = 0 ;
V_11 -> V_35 . V_34 = - 1 ;
}
static T_7 *
F_15 ( T_8 * V_36 , T_1 * V_3 , T_4 V_37 )
{
T_7 * V_38 ;
T_9 * V_39 ;
T_9 * V_40 ;
T_4 V_41 , V_42 , V_30 , V_31 , V_43 ;
T_10 * V_44 ;
V_38 = F_16 ( V_36 , V_3 , V_37 , NULL ) ;
if ( V_3 -> V_12 -> V_13 . V_14 ) {
if ( V_38 != NULL && V_38 -> V_13 & V_45 ) {
return V_38 ;
} else {
return NULL ;
}
}
if ( V_38 == NULL ) {
return NULL ;
}
V_30 = 0 ;
V_31 = 0 ;
V_43 = 0 ;
for( V_39 = V_38 -> V_46 ; V_39 ; V_39 = V_39 -> V_46 ) {
if ( V_43 != V_39 -> V_47 ) {
V_30 += V_39 -> V_47 - V_43 ;
if ( ( V_39 -> V_47 - V_43 ) > V_31 ) {
V_31 = V_39 -> V_47 - V_43 ;
}
}
V_43 = V_39 -> V_47 + 1 ;
}
V_42 = 0 ;
V_40 = NULL ;
for( V_39 = V_38 -> V_46 ; V_39 ; V_39 = V_39 -> V_46 ) {
if( ! V_40 || V_40 -> V_47 != V_39 -> V_47 ) {
V_42 += V_39 -> V_48 ;
}
V_40 = V_39 ;
}
V_44 = ( T_10 * ) F_17 ( V_42 ) ;
V_38 -> V_49 = F_18 ( V_44 , V_42 , V_42 ) ;
V_38 -> V_48 = V_42 ;
V_41 = 0 ;
V_40 = NULL ;
for ( V_39 = V_38 -> V_46 ; V_39 && V_39 -> V_48 + V_41 <= V_42 ; V_39 = V_39 -> V_46 ) {
if ( V_39 -> V_48 ) {
if( ! V_40 || V_40 -> V_47 != V_39 -> V_47 ) {
F_19 ( V_39 -> V_49 , V_44 + V_41 , 0 , V_39 -> V_48 ) ;
V_41 += V_39 -> V_48 ;
} else {
V_39 -> V_13 |= V_50 ;
V_38 -> V_13 |= V_50 ;
if( ( V_40 -> V_48 != V_39 -> V_48 )
|| F_20 ( V_40 -> V_49 , 0 , F_21 ( V_39 -> V_49 , 0 , V_40 -> V_48 ) , V_40 -> V_48 ) ) {
V_39 -> V_13 |= V_51 ;
V_38 -> V_13 |= V_51 ;
}
}
}
V_40 = V_39 ;
}
for ( V_39 = V_38 -> V_46 ; V_39 ; V_39 = V_39 -> V_46 ) {
if( V_39 -> V_49 ) {
F_22 ( V_39 -> V_49 ) ;
V_39 -> V_49 = NULL ;
}
}
V_38 -> V_13 |= V_45 ;
V_38 -> V_52 = V_3 -> V_12 -> V_53 ;
F_23 ( V_3 -> V_54 , V_55 , L_1 , V_30 , V_31 ) ;
V_56 -> V_30 = V_30 ;
V_56 -> V_31 = V_31 ;
return V_38 ;
}
static void
F_24 ( T_1 * V_3 )
{
V_57 ++ ;
if ( V_57 == V_58 ) {
V_57 = 0 ;
}
V_59 = & V_60 [ V_57 ] ;
V_59 -> V_43 = 0 ;
V_59 -> V_61 = 0 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
V_59 -> V_8 = 0 ;
V_59 -> V_64 = 0 ;
V_59 -> V_65 [ 0 ] = '\0' ;
V_59 -> V_66 [ 0 ] = '\0' ;
V_59 -> V_32 = 0 ;
V_59 -> V_67 = 0 ;
V_68 = NULL ;
V_69 = NULL ;
V_68 = ( T_6 * ) F_25 ( F_12 () , V_3 , V_23 , 0 ) ;
V_70 = F_7 ( V_3 -> V_12 -> V_53 , & V_3 -> V_71 , & V_3 -> V_72 ,
V_3 -> V_73 ,
V_3 -> V_74 , V_3 -> V_75 , V_18 | V_19 ) ;
if ( ! V_70 ) {
V_70 = F_8 ( V_3 -> V_12 -> V_53 , & V_3 -> V_72 , & V_3 -> V_71 ,
V_3 -> V_73 , V_3 -> V_75 , V_3 -> V_74 , V_18 | V_19 ) ;
F_9 ( V_70 , V_15 ) ;
}
V_69 = ( T_6 * ) F_10 ( V_70 , V_23 ) ;
if ( ! V_69 ) {
V_69 = F_11 ( F_12 () , T_6 ) ;
V_69 -> V_7 [ 0 ] = '\0' ;
V_69 -> V_8 = 0 ;
V_69 -> V_25 . V_26 = 0 ;
V_69 -> V_25 . V_27 = - 1 ;
V_69 -> V_25 . V_28 = 0 ;
V_69 -> V_25 . V_29 = - 1 ;
V_69 -> V_25 . V_30 = 0 ;
V_69 -> V_25 . V_31 = 0 ;
V_69 -> V_25 . V_32 = 0 ;
V_69 -> V_25 . V_33 = 0 ;
V_69 -> V_25 . V_34 = - 1 ;
V_69 -> V_35 . V_26 = 0 ;
V_69 -> V_35 . V_27 = - 1 ;
V_69 -> V_35 . V_28 = 0 ;
V_69 -> V_35 . V_29 = - 1 ;
V_69 -> V_35 . V_30 = 0 ;
V_69 -> V_35 . V_31 = 0 ;
V_69 -> V_35 . V_32 = 0 ;
V_69 -> V_35 . V_33 = 0 ;
V_69 -> V_35 . V_34 = - 1 ;
F_13 ( V_70 , V_23 , V_69 ) ;
}
if ( ! V_68 ) {
V_68 = F_11 ( F_12 () , T_6 ) ;
F_14 ( V_68 -> V_7 , V_69 -> V_7 , V_24 ) ;
V_68 -> V_8 = V_69 -> V_8 ;
memcpy ( & ( V_68 -> V_25 ) , & ( V_69 -> V_25 ) , sizeof( V_76 ) ) ;
memcpy ( & ( V_68 -> V_35 ) , & ( V_69 -> V_35 ) , sizeof( V_76 ) ) ;
F_26 ( F_12 () , V_3 , V_23 , 0 , V_68 ) ;
}
if ( F_27 ( & V_70 -> V_77 -> V_78 , & V_3 -> V_72 ) ) {
V_79 = & ( V_69 -> V_25 ) ;
V_56 = & ( V_68 -> V_25 ) ;
} else {
V_79 = & ( V_69 -> V_35 ) ;
V_56 = & ( V_68 -> V_35 ) ;
}
V_59 -> V_8 = V_68 -> V_8 ;
}
static void
F_28 ( T_11 * V_80 , T_1 * V_3 , T_12 * V_81 )
{
T_10 V_82 ;
T_13 * V_83 ;
T_12 * V_84 ;
T_4 V_47 = 0 ;
if ( V_85 ) {
V_82 = F_29 ( V_80 , V_47 ) ;
if ( F_30 ( V_82 ) == 2 ) {
F_31 ( V_86 , V_80 , V_3 , V_81 ) ;
return;
}
}
F_32 ( V_3 -> V_54 , V_87 , L_2 ) ;
F_33 ( V_3 -> V_54 , V_55 ) ;
V_88 = TRUE ;
V_89 = 0 ;
V_83 = F_34 ( V_81 , V_23 , V_80 , 0 , - 1 , L_3 ) ;
V_84 = F_35 ( V_83 , V_90 ) ;
F_24 ( V_3 ) ;
if ( V_91 ) {
F_36 ( V_80 , V_84 , V_68 ) ;
}
F_37 ( V_3 -> V_54 , V_55 , L_4 ) ;
V_47 = F_38 ( V_80 , V_3 , V_84 , NULL ) ;
if ( F_39 ( V_80 , V_47 ) > 0 ) {
F_40 ( V_84 , V_3 , & V_92 , V_80 , V_47 , F_39 ( V_80 , V_47 ) ,
L_5 ) ;
F_37 ( V_3 -> V_54 , V_55 , L_6 ) ;
}
}
static void
F_41 ( T_11 * V_80 , T_1 * V_3 , T_12 * V_81 )
{
T_13 * V_83 ;
T_12 * V_84 ;
T_4 V_47 = 0 ;
T_11 * V_93 ;
T_14 V_94 = 1 ;
F_32 ( V_3 -> V_54 , V_87 , L_2 ) ;
F_33 ( V_3 -> V_54 , V_55 ) ;
V_88 = TRUE ;
V_89 = 0 ;
V_83 = F_34 ( V_81 , V_23 , V_80 , 0 , - 1 , L_3 ) ;
V_84 = F_35 ( V_83 , V_90 ) ;
F_24 ( V_3 ) ;
if ( V_91 ) {
F_36 ( V_80 , V_84 , V_68 ) ;
}
F_37 ( V_3 -> V_54 , V_55 , L_7 ) ;
while( F_39 ( V_80 , V_47 ) > 0 )
{
V_93 = F_42 ( V_80 , V_47 ) ;
V_47 += F_43 ( V_93 , V_3 , V_84 , NULL ) ;
V_94 ++ ;
if( F_39 ( V_80 , V_47 ) > 0 ) {
if( V_95 == V_96 ) {
F_40 ( V_84 , V_3 , & V_92 , V_80 , V_47 , F_39 ( V_80 , V_47 ) ,
L_5 ) ;
F_37 ( V_3 -> V_54 , V_55 , L_6 ) ;
break;
} else {
F_23 ( V_3 -> V_54 , V_55 , L_8 , V_94 ) ;
}
}
}
}
static void
F_44 ( T_11 * V_80 , T_1 * V_3 , T_12 * V_81 )
{
V_88 = TRUE ;
if( V_95 == V_96 ) {
F_45 ( V_80 , V_3 , V_81 , V_97 , V_98 ) ;
}
else if( ( V_95 == V_99 ) || ( F_46 ( V_80 , 1 ) == - 1 ) ) {
F_41 ( V_80 , V_3 , V_81 ) ;
}
else {
F_45 ( V_80 , V_3 , V_81 , V_97 , V_98 ) ;
}
}
void
F_36 ( T_11 * V_80 , T_12 * V_81 , T_6 * V_100 )
{
T_12 * V_101 ;
T_13 * V_102 ;
if ( ! V_100 || V_100 -> V_8 == 0 ) {
return;
}
V_102 = F_47 ( V_81 , V_103 , V_80 , 0 , 0 ,
L_9 ,
L_10 ,
V_100 -> V_7 ,
V_100 -> V_8 ) ;
F_48 ( V_102 ) ;
V_101 = F_35 ( V_102 , V_104 ) ;
if ( V_101 )
{
T_13 * V_105 = F_49 ( V_101 , V_106 ,
V_80 , 0 , 0 , V_100 -> V_8 ) ;
F_48 ( V_105 ) ;
V_105 = F_50 ( V_101 , V_107 ,
V_80 , 0 , 0 , V_100 -> V_7 ) ;
F_48 ( V_105 ) ;
}
}
void
F_51 ( void )
{
static T_15 V_108 [] =
{
#include "packet-t38-hfarr.c"
{ & V_103 ,
{ L_11 , L_12 , V_109 , V_110 ,
NULL , 0x0 , L_13 , V_111 } } ,
{ & V_106 ,
{ L_14 , L_15 , V_112 , V_110 ,
NULL , 0x0 , L_16 , V_111 } } ,
{ & V_107 ,
{ L_17 , L_18 , V_109 , V_110 ,
NULL , 0x0 , L_19 , V_111 } } ,
{ & V_113 ,
{ L_20 , L_21 ,
V_114 , V_110 , NULL , 0x00 , NULL , V_111 } } ,
{ & V_115 ,
{ L_22 , L_23 ,
V_112 , V_110 , NULL , 0x00 , NULL , V_111 } } ,
{ & V_116 ,
{ L_24 , L_25 ,
V_117 , V_110 , NULL , 0x0 , NULL , V_111 } } ,
{ & V_118 ,
{ L_26 ,
L_27 ,
V_117 , V_110 , NULL , 0x0 , NULL , V_111 } } ,
{ & V_119 ,
{ L_28 ,
L_29 ,
V_117 , V_110 , NULL , 0x0 , NULL , V_111 } } ,
{ & V_120 ,
{ L_30 , L_31 ,
V_117 , V_110 , NULL , 0x0 , NULL , V_111 } } ,
{ & V_121 ,
{ L_32 , L_33 ,
V_112 , V_110 , NULL , 0x00 , NULL , V_111 } } ,
{ & V_122 ,
{ L_34 , L_35 ,
V_123 , V_124 , NULL , 0x00 , NULL , V_111 } } ,
{ & V_125 ,
{ L_36 , L_37 ,
V_112 , V_110 , NULL , 0x00 , NULL , V_111 } } ,
{ & V_126 ,
{ L_38 , L_39 ,
V_123 , V_124 , NULL , 0x00 , NULL , V_111 } } ,
} ;
static T_16 * V_127 [] =
{
& V_90 ,
#include "packet-t38-ettarr.c"
& V_104 ,
& V_128 ,
& V_129
} ;
static T_17 V_130 [] = {
{ & V_92 , { L_40 , V_131 , V_132 , L_41 , V_133 } } ,
} ;
T_18 * V_134 ;
T_19 * V_135 ;
V_23 = F_52 ( L_2 , L_2 , L_42 ) ;
F_53 ( V_23 , V_108 , F_54 ( V_108 ) ) ;
F_55 ( V_127 , F_54 ( V_127 ) ) ;
V_135 = F_56 ( V_23 ) ;
F_57 ( V_135 , V_130 , F_54 ( V_130 ) ) ;
F_58 ( L_43 , F_28 , V_23 ) ;
F_59 ( F_1 ) ;
F_60 ( F_3 ) ;
V_136 = F_61 ( L_42 ) ;
V_134 = F_62 ( V_23 , V_137 ) ;
F_63 ( V_134 , L_44 ,
L_45 ,
L_46
L_47 ,
& V_138 ) ;
F_63 ( V_134 , L_48 ,
L_49 ,
L_50
L_51
L_52 ,
& V_85 ) ;
F_64 ( V_134 , L_53 ,
L_54 ,
L_55 ,
10 , & V_139 ) ;
F_64 ( V_134 , L_56 ,
L_57 ,
L_58 ,
10 , & V_140 ) ;
F_63 ( V_134 , L_59 ,
L_60 ,
L_61
L_62
L_63
L_64 ,
& V_97 ) ;
F_65 ( V_134 , L_65 ,
L_66 ,
L_67 ,
( T_16 * ) & V_95 , V_141 , FALSE ) ;
F_63 ( V_134 , L_68 ,
L_69 ,
L_70
L_71 ,
& V_91 ) ;
}
void
V_137 ( void )
{
static T_20 V_142 = FALSE ;
static T_21 V_143 ;
static T_21 V_144 ;
if ( ! V_142 ) {
V_15 = F_66 ( F_28 , V_23 ) ;
V_145 = F_66 ( F_44 , V_23 ) ;
V_98 = F_66 ( F_41 , V_23 ) ;
V_86 = F_67 ( L_72 ) ;
V_146 = F_67 ( L_73 ) ;
V_147 = F_67 ( L_74 ) ;
V_142 = TRUE ;
}
else {
F_68 ( L_53 , V_143 , V_145 ) ;
F_68 ( L_56 , V_144 , V_15 ) ;
}
V_143 = V_139 ;
V_144 = V_140 ;
F_69 ( L_53 , V_143 , V_145 ) ;
F_69 ( L_56 , V_144 , V_15 ) ;
}
