static void F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
void F_3 ( T_1 * V_3 ,
T_2 * V_4 , int V_5 ,
int V_6 ,
const T_3 * V_7 , T_4 V_8 )
{
T_2 V_9 ;
T_5 * V_10 ;
T_6 * V_11 = NULL ;
if ( V_3 -> V_12 -> V_13 . V_14 )
{
return;
}
F_4 ( & V_9 , V_15 , 0 , NULL ) ;
V_10 = F_5 ( V_8 , V_4 , & V_9 , V_16 , V_5 , V_6 ,
V_17 | ( ! V_6 ? V_18 : 0 ) ) ;
if ( ! V_10 || V_10 -> V_19 != V_8 ) {
V_10 = F_6 ( V_8 , V_4 , & V_9 , V_16 ,
( T_4 ) V_5 , ( T_4 ) V_6 ,
V_20 | ( ! V_6 ? V_21 : 0 ) ) ;
}
F_7 ( V_10 , V_22 ) ;
V_11 = ( T_6 * ) F_8 ( V_10 , V_23 ) ;
if ( ! V_11 ) {
V_11 = F_9 ( T_6 ) ;
F_10 ( V_10 , V_23 , V_11 ) ;
}
F_11 ( V_11 -> V_7 , V_7 , V_24 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_25 . V_26 = 0 ;
V_11 -> V_25 . V_27 = - 1 ;
V_11 -> V_25 . V_28 = 0 ;
V_11 -> V_25 . V_29 = - 1 ;
V_11 -> V_25 . V_30 = 0 ;
V_11 -> V_25 . V_31 = 0 ;
V_11 -> V_25 . V_32 = 0 ;
V_11 -> V_33 . V_26 = 0 ;
V_11 -> V_33 . V_27 = - 1 ;
V_11 -> V_33 . V_28 = 0 ;
V_11 -> V_33 . V_29 = - 1 ;
V_11 -> V_33 . V_30 = 0 ;
V_11 -> V_33 . V_31 = 0 ;
V_11 -> V_33 . V_32 = 0 ;
}
T_7 *
F_12 ( T_8 * V_34 , T_1 * V_3 , T_4 V_35 )
{
T_7 * V_36 ;
T_7 * V_37 ;
T_7 * V_38 ;
T_4 V_39 , V_40 , V_30 , V_31 , V_41 ;
V_36 = F_13 ( V_34 , V_3 , V_35 , NULL ) ;
if ( V_3 -> V_12 -> V_13 . V_14 ) {
if ( V_36 != NULL && V_36 -> V_13 & V_42 ) {
return V_36 ;
} else {
return NULL ;
}
}
if ( V_36 == NULL ) {
return NULL ;
}
V_30 = 0 ;
V_31 = 0 ;
V_41 = 0 ;
for( V_37 = V_36 -> V_43 ; V_37 ; V_37 = V_37 -> V_43 ) {
if ( V_41 != V_37 -> V_44 ) {
V_30 += V_37 -> V_44 - V_41 ;
if ( ( V_37 -> V_44 - V_41 ) > V_31 ) {
V_31 = V_37 -> V_44 - V_41 ;
}
}
V_41 = V_37 -> V_44 + 1 ;
}
V_40 = 0 ;
V_38 = NULL ;
for( V_37 = V_36 -> V_43 ; V_37 ; V_37 = V_37 -> V_43 ) {
if( ! V_38 || V_38 -> V_44 != V_37 -> V_44 ) {
V_40 += V_37 -> V_45 ;
}
V_38 = V_37 ;
}
V_36 -> V_46 = ( char * ) F_14 ( V_40 ) ;
V_36 -> V_45 = V_40 ;
V_39 = 0 ;
V_38 = NULL ;
for ( V_37 = V_36 -> V_43 ; V_37 && V_37 -> V_45 + V_39 <= V_40 ; V_37 = V_37 -> V_43 ) {
if ( V_37 -> V_45 ) {
if( ! V_38 || V_38 -> V_44 != V_37 -> V_44 ) {
memcpy ( V_36 -> V_46 + V_39 , V_37 -> V_46 , V_37 -> V_45 ) ;
V_39 += V_37 -> V_45 ;
} else {
V_37 -> V_13 |= V_47 ;
V_36 -> V_13 |= V_47 ;
if( ( V_38 -> V_45 != V_37 -> V_48 )
|| memcmp ( V_38 -> V_46 , V_37 -> V_46 , V_38 -> V_45 ) ) {
V_37 -> V_13 |= V_49 ;
V_36 -> V_13 |= V_49 ;
}
}
}
V_38 = V_37 ;
}
for ( V_37 = V_36 -> V_43 ; V_37 ; V_37 = V_37 -> V_43 ) {
if( V_37 -> V_46 ) {
F_15 ( V_37 -> V_46 ) ;
V_37 -> V_46 = NULL ;
}
}
V_36 -> V_13 |= V_42 ;
V_36 -> V_50 = V_3 -> V_12 -> V_51 ;
F_16 ( V_3 -> V_52 , V_53 , L_1 , V_30 , V_31 ) ;
V_54 -> V_30 = V_30 ;
V_54 -> V_31 = V_31 ;
return V_36 ;
}
static void
F_17 ( T_1 * V_3 )
{
V_55 ++ ;
if ( V_55 == V_56 ) {
V_55 = 0 ;
}
V_57 = & V_58 [ V_55 ] ;
V_57 -> V_41 = 0 ;
V_57 -> V_59 = 0 ;
V_57 -> V_60 = 0 ;
V_57 -> V_61 = 0 ;
V_57 -> V_8 = 0 ;
V_57 -> V_62 = 0 ;
V_57 -> V_63 [ 0 ] = '\0' ;
V_57 -> V_64 [ 0 ] = '\0' ;
V_57 -> V_32 = 0 ;
V_57 -> V_65 = 0 ;
V_66 = NULL ;
V_67 = NULL ;
V_66 = ( T_6 * ) F_18 ( V_3 -> V_12 , V_23 , 0 ) ;
V_68 = F_5 ( V_3 -> V_12 -> V_51 , & V_3 -> V_69 , & V_3 -> V_70 ,
V_3 -> V_71 ,
V_3 -> V_72 , V_3 -> V_73 , V_17 | V_18 ) ;
if ( ! V_68 ) {
V_68 = F_6 ( V_3 -> V_12 -> V_51 , & V_3 -> V_70 , & V_3 -> V_69 ,
V_3 -> V_71 , V_3 -> V_73 , V_3 -> V_72 , V_17 | V_18 ) ;
F_7 ( V_68 , V_22 ) ;
}
if ( ! V_66 ) {
V_67 = ( T_6 * ) F_8 ( V_68 , V_23 ) ;
if ( ! V_67 ) {
V_67 = F_9 ( T_6 ) ;
V_67 -> V_7 [ 0 ] = '\0' ;
V_67 -> V_8 = 0 ;
V_67 -> V_25 . V_26 = 0 ;
V_67 -> V_25 . V_27 = - 1 ;
V_67 -> V_25 . V_28 = 0 ;
V_67 -> V_25 . V_29 = - 1 ;
V_67 -> V_25 . V_30 = 0 ;
V_67 -> V_25 . V_31 = 0 ;
V_67 -> V_25 . V_32 = 0 ;
V_67 -> V_25 . V_74 = 0 ;
V_67 -> V_25 . V_75 = - 1 ;
V_67 -> V_33 . V_26 = 0 ;
V_67 -> V_33 . V_27 = - 1 ;
V_67 -> V_33 . V_28 = 0 ;
V_67 -> V_33 . V_29 = - 1 ;
V_67 -> V_33 . V_30 = 0 ;
V_67 -> V_33 . V_31 = 0 ;
V_67 -> V_33 . V_32 = 0 ;
V_67 -> V_33 . V_74 = 0 ;
V_67 -> V_33 . V_75 = - 1 ;
F_10 ( V_68 , V_23 , V_67 ) ;
}
V_66 = F_9 ( T_6 ) ;
F_11 ( V_66 -> V_7 , V_67 -> V_7 , V_24 ) ;
V_66 -> V_8 = V_67 -> V_8 ;
memcpy ( & ( V_66 -> V_25 ) , & ( V_67 -> V_25 ) , sizeof( V_76 ) ) ;
memcpy ( & ( V_66 -> V_33 ) , & ( V_67 -> V_33 ) , sizeof( V_76 ) ) ;
F_19 ( V_3 -> V_12 , V_23 , 0 , V_66 ) ;
}
if ( F_20 ( & V_68 -> V_77 -> V_78 , & V_3 -> V_70 ) ) {
V_79 = & ( V_67 -> V_25 ) ;
V_54 = & ( V_66 -> V_25 ) ;
} else {
V_79 = & ( V_67 -> V_33 ) ;
V_54 = & ( V_66 -> V_33 ) ;
}
V_57 -> V_8 = V_66 -> V_8 ;
}
static void
F_21 ( T_9 * V_80 , T_1 * V_3 , T_10 * V_81 )
{
T_11 V_82 ;
T_12 * V_83 ;
T_10 * V_84 ;
T_4 V_44 = 0 ;
if ( V_85 ) {
V_82 = F_22 ( V_80 , V_44 ) ;
if ( F_23 ( V_82 ) == 2 ) {
F_24 ( V_86 , V_80 , V_3 , V_81 ) ;
return;
}
}
F_25 ( V_3 -> V_52 , V_87 , L_2 ) ;
F_26 ( V_3 -> V_52 , V_53 ) ;
V_88 = TRUE ;
V_89 = 0 ;
V_83 = F_27 ( V_81 , V_23 , V_80 , 0 , - 1 , L_3 ) ;
V_84 = F_28 ( V_83 , V_90 ) ;
F_17 ( V_3 ) ;
if ( V_91 ) {
F_29 ( V_80 , V_84 , V_66 ) ;
}
F_30 ( V_3 -> V_52 , V_53 , L_4 ) ;
V_44 = F_31 ( V_80 , V_3 , V_84 , NULL ) ;
if ( F_32 ( V_80 , V_44 ) > 0 ) {
if ( V_84 ) {
F_33 ( V_84 , V_80 , V_44 , F_34 ( V_80 , V_44 ) ,
L_5 ) ;
}
F_30 ( V_3 -> V_52 , V_53 , L_6 ) ;
}
}
static void
F_35 ( T_9 * V_80 , T_1 * V_3 , T_10 * V_81 )
{
T_12 * V_83 ;
T_10 * V_84 ;
T_4 V_44 = 0 ;
T_9 * V_92 ;
T_13 V_93 = 1 ;
F_25 ( V_3 -> V_52 , V_87 , L_2 ) ;
F_26 ( V_3 -> V_52 , V_53 ) ;
V_88 = TRUE ;
V_89 = 0 ;
V_83 = F_27 ( V_81 , V_23 , V_80 , 0 , - 1 , L_3 ) ;
V_84 = F_28 ( V_83 , V_90 ) ;
F_17 ( V_3 ) ;
if ( V_91 ) {
F_29 ( V_80 , V_84 , V_66 ) ;
}
F_30 ( V_3 -> V_52 , V_53 , L_7 ) ;
while( F_32 ( V_80 , V_44 ) > 0 )
{
V_92 = F_36 ( V_80 , V_44 ) ;
V_44 += F_37 ( V_92 , V_3 , V_84 , NULL ) ;
V_93 ++ ;
if( F_32 ( V_80 , V_44 ) > 0 ) {
if( V_94 == V_95 ) {
if( V_84 ) {
F_33 ( V_84 , V_80 , V_44 , F_34 ( V_80 , V_44 ) ,
L_5 ) ;
}
F_30 ( V_3 -> V_52 , V_53 , L_6 ) ;
break;
} else {
F_16 ( V_3 -> V_52 , V_53 , L_8 , V_93 ) ;
}
}
}
}
static void
F_38 ( T_9 * V_80 , T_1 * V_3 , T_10 * V_81 )
{
V_88 = TRUE ;
if( V_94 == V_95 ) {
F_39 ( V_80 , V_3 , V_81 , V_96 , V_97 ) ;
}
else if( ( V_94 == V_98 ) || ( F_40 ( V_80 , 1 ) == - 1 ) ) {
F_35 ( V_80 , V_3 , V_81 ) ;
}
else {
F_39 ( V_80 , V_3 , V_81 , V_96 , V_97 ) ;
}
}
static void
F_41 ( T_9 * V_80 , T_1 * V_3 , T_10 * V_81 )
{
if( V_3 -> V_99 == V_100 )
{
F_38 ( V_80 , V_3 , V_81 ) ;
}
else if( V_3 -> V_99 == V_101 )
{
F_21 ( V_80 , V_3 , V_81 ) ;
}
}
void
F_29 ( T_9 * V_80 , T_10 * V_81 , T_6 * V_102 )
{
T_10 * V_103 ;
T_12 * V_104 ;
if ( ! V_102 || V_102 -> V_8 == 0 ) {
return;
}
V_104 = F_42 ( V_81 , V_105 , V_80 , 0 , 0 ,
L_9 ,
L_10 ,
V_102 -> V_7 ,
V_102 -> V_8 ) ;
F_43 ( V_104 ) ;
V_103 = F_28 ( V_104 , V_106 ) ;
if ( V_103 )
{
T_12 * V_107 = F_44 ( V_103 , V_108 ,
V_80 , 0 , 0 , V_102 -> V_8 ) ;
F_43 ( V_107 ) ;
V_107 = F_45 ( V_103 , V_109 ,
V_80 , 0 , 0 , V_102 -> V_7 ) ;
F_43 ( V_107 ) ;
}
}
void
F_46 ( void )
{
static T_14 V_110 [] =
{
#include "packet-t38-hfarr.c"
{ & V_105 ,
{ L_11 , L_12 , V_111 , V_112 ,
NULL , 0x0 , L_13 , V_113 } } ,
{ & V_108 ,
{ L_14 , L_15 , V_114 , V_112 ,
NULL , 0x0 , L_16 , V_113 } } ,
{ & V_109 ,
{ L_17 , L_18 , V_111 , V_112 ,
NULL , 0x0 , L_19 , V_113 } } ,
{ & V_115 ,
{ L_20 , L_21 ,
V_116 , V_112 , NULL , 0x00 , NULL , V_113 } } ,
{ & V_117 ,
{ L_22 , L_23 ,
V_114 , V_112 , NULL , 0x00 , NULL , V_113 } } ,
{ & V_118 ,
{ L_24 , L_25 ,
V_119 , V_112 , NULL , 0x0 , NULL , V_113 } } ,
{ & V_120 ,
{ L_26 ,
L_27 ,
V_119 , V_112 , NULL , 0x0 , NULL , V_113 } } ,
{ & V_121 ,
{ L_28 ,
L_29 ,
V_119 , V_112 , NULL , 0x0 , NULL , V_113 } } ,
{ & V_122 ,
{ L_30 , L_31 ,
V_119 , V_112 , NULL , 0x0 , NULL , V_113 } } ,
{ & V_123 ,
{ L_32 , L_33 ,
V_114 , V_112 , NULL , 0x00 , NULL , V_113 } } ,
{ & V_124 ,
{ L_34 , L_35 ,
V_125 , V_126 , NULL , 0x00 , NULL , V_113 } } ,
{ & V_127 ,
{ L_36 , L_37 ,
V_114 , V_112 , NULL , 0x00 , NULL , V_113 } } ,
{ & V_128 ,
{ L_38 , L_39 ,
V_125 , V_126 , NULL , 0x00 , NULL , V_113 } } ,
} ;
static T_15 * V_129 [] =
{
& V_90 ,
#include "packet-t38-ettarr.c"
& V_106 ,
& V_130 ,
& V_131
} ;
T_16 * V_132 ;
V_23 = F_47 ( L_2 , L_2 , L_40 ) ;
F_48 ( V_23 , V_110 , F_49 ( V_110 ) ) ;
F_50 ( V_129 , F_49 ( V_129 ) ) ;
F_51 ( L_40 , F_41 , V_23 ) ;
F_52 ( F_1 ) ;
V_133 = F_53 ( L_40 ) ;
V_132 = F_54 ( V_23 , V_134 ) ;
F_55 ( V_132 , L_41 ,
L_42 ,
L_43
L_44 ,
& V_135 ) ;
F_55 ( V_132 , L_45 ,
L_46 ,
L_47
L_48
L_49 ,
& V_85 ) ;
F_56 ( V_132 , L_50 ,
L_51 ,
L_52 ,
10 , & V_136 ) ;
F_56 ( V_132 , L_53 ,
L_54 ,
L_55 ,
10 , & V_137 ) ;
F_55 ( V_132 , L_56 ,
L_57 ,
L_58
L_59
L_60
L_61 ,
& V_96 ) ;
F_57 ( V_132 , L_62 ,
L_63 ,
L_64 ,
( T_15 * ) & V_94 , V_138 , FALSE ) ;
F_55 ( V_132 , L_65 ,
L_66 ,
L_67
L_68 ,
& V_91 ) ;
}
void
V_134 ( void )
{
static T_17 V_139 = FALSE ;
static T_18 V_140 ;
static T_18 V_141 ;
if ( ! V_139 ) {
V_22 = F_58 ( F_21 , V_23 ) ;
V_142 = F_58 ( F_38 , V_23 ) ;
V_97 = F_58 ( F_35 , V_23 ) ;
V_86 = F_59 ( L_69 ) ;
V_143 = F_59 ( L_70 ) ;
V_144 = F_59 ( L_71 ) ;
V_139 = TRUE ;
}
else {
F_60 ( L_50 , V_140 , V_142 ) ;
F_60 ( L_53 , V_141 , V_22 ) ;
}
V_140 = V_136 ;
V_141 = V_137 ;
F_61 ( L_50 , V_140 , V_142 ) ;
F_61 ( L_53 , V_141 , V_22 ) ;
}
