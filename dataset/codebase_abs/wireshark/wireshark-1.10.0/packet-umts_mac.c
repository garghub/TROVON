T_1 F_1 ( void ) { return V_1 ; }
static T_2 F_2 ( T_3 V_2 , T_3 V_3 )
{
const T_4 * V_4 = ( const T_4 * ) V_2 , * V_5 = ( const T_4 * ) V_3 ;
return V_4 -> V_6 == V_5 -> V_6 && V_4 -> V_7 == V_5 -> V_7 ;
}
static T_5 F_3 ( T_3 V_8 )
{
const T_4 * V_9 = ( const T_4 * ) V_8 ;
return ( V_9 -> V_7 << 4 ) | V_9 -> V_6 ;
}
static T_2 F_4 ( T_3 V_2 , T_3 V_3 )
{
const T_6 * V_4 = ( const T_6 * ) V_2 , * V_5 = ( const T_6 * ) V_3 ;
return V_4 -> V_10 == V_5 -> V_10 && V_4 -> V_11 == V_5 -> V_11 && V_4 -> type == V_5 -> type ;
}
static T_5 F_5 ( T_3 V_8 )
{
const T_6 * V_12 = ( const T_6 * ) V_8 ;
return ( V_12 -> V_10 << 2 ) | V_12 -> type ;
}
static T_7 F_6 ( T_7 V_13 , T_8 * V_14 )
{
T_7 V_15 ;
V_15 = V_13 >> 6 ;
switch ( V_15 ) {
case V_16 :
case V_17 :
* V_14 = 2 ;
return V_15 ;
}
V_15 = V_13 >> 4 ;
switch ( V_15 ) {
case V_18 :
* V_14 = 4 ;
return V_15 ;
}
* V_14 = 8 ;
V_15 = V_13 ;
switch ( V_15 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
return V_15 ;
default:
return V_15 ;
}
}
static T_8 F_7 ( T_9 * V_23 , T_10 * T_11 V_24 ,
T_12 * V_25 , T_8 V_26 , T_13 * V_27 , T_14 * V_28 , T_15 * V_29 )
{
T_7 V_30 ;
V_30 = F_8 ( V_23 , V_26 , 2 ) ;
F_9 ( V_25 , V_31 , V_23 , V_26 , 2 , V_32 ) ;
V_26 += 2 ;
if ( V_30 == V_33 ) {
F_9 ( V_25 , V_34 , V_23 , V_26 , 32 , V_32 ) ;
V_29 -> V_35 [ V_27 -> V_36 ] = F_10 ( V_23 , V_26 , 32 , FALSE ) ;
V_26 += 32 ;
} else if ( V_30 == V_37 ) {
F_9 ( V_25 , V_38 , V_23 , 4 , 16 , V_32 ) ;
V_29 -> V_35 [ V_27 -> V_36 ] = F_11 ( V_23 , V_26 , 16 , FALSE ) ;
V_26 += 16 ;
}
if ( V_28 -> V_39 [ V_27 -> V_36 ] ) {
T_16 * V_40 ;
if( V_29 ) {
V_29 -> V_41 [ V_27 -> V_36 ] = F_8 ( V_23 , V_26 , 4 ) + 1 ;
}
F_9 ( V_25 , V_42 , V_23 , V_26 , 4 , V_32 ) ;
V_26 += 4 ;
if( V_29 ) {
V_40 = F_12 ( V_25 , V_43 , V_23 , 0 , 0 , V_29 -> V_41 [ V_27 -> V_36 ] ) ;
F_13 ( V_40 ) ;
}
}
return V_26 ;
}
static void F_14 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_12 * V_44 = NULL ;
T_16 * V_45 ;
F_15 ( T_11 -> V_46 , V_47 , L_1 ) ;
F_15 ( T_11 -> V_46 , V_48 , L_2 ) ;
if ( V_25 ) {
T_16 * V_49 ;
V_49 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_44 = F_17 ( V_49 , V_52 ) ;
F_18 ( V_49 , L_3 ) ;
V_45 = F_12 ( V_44 , V_53 , V_23 , 0 , 0 , V_54 ) ;
F_13 ( V_45 ) ;
}
F_19 ( V_55 , V_23 , T_11 , V_25 ) ;
}
static void F_20 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_7 V_15 ;
T_7 V_56 ;
T_8 V_26 = 0 ;
T_9 * V_57 ;
T_12 * V_58 = NULL ;
T_16 * V_45 ;
T_14 * V_28 ;
T_13 * V_27 ;
T_15 * V_29 ;
T_16 * V_49 = NULL ;
T_7 V_59 ;
V_15 = F_8 ( V_23 , 0 , 2 ) ;
V_26 += 2 ;
F_15 ( T_11 -> V_46 , V_47 , L_1 ) ;
F_21 ( T_11 -> V_46 , V_48 ,
F_22 ( V_15 , V_60 , L_4 ) ) ;
V_49 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_58 = F_17 ( V_49 , V_61 ) ;
V_28 = ( T_14 * ) F_23 ( T_11 -> V_62 , V_50 , 0 ) ;
V_27 = ( T_13 * ) F_23 ( T_11 -> V_62 , V_63 , 0 ) ;
V_29 = ( T_15 * ) F_23 ( T_11 -> V_62 , V_64 , 0 ) ;
if ( ! V_28 || ! V_27 ) {
F_24 ( V_58 , V_23 , 0 , - 1 ,
L_5 ) ;
F_25 ( T_11 , V_49 , V_65 , V_66 , L_5 ) ;
return;
}
F_9 ( V_58 , V_67 , V_23 , 0 , 2 , V_32 ) ;
if ( V_15 == V_68 ) {
V_28 -> V_39 [ V_27 -> V_36 ] = 1 ;
V_26 = F_7 ( V_23 , T_11 , V_58 , V_26 , V_27 , V_28 , V_29 ) ;
}
V_56 = V_27 -> V_69 ;
switch ( V_15 ) {
case V_70 :
F_18 ( V_49 , L_6 ) ;
V_45 = F_12 ( V_58 , V_53 , V_23 , 0 , 0 , V_71 ) ;
F_13 ( V_45 ) ;
V_57 = F_26 ( V_23 , V_26 , V_27 -> V_72 [ V_56 ] - V_26 ) ;
F_27 ( T_11 , V_57 , L_7 ) ;
F_19 ( V_73 , V_57 , T_11 , V_25 ) ;
break;
case V_68 :
V_59 = F_8 ( V_23 , V_26 - 4 , 4 ) ;
V_29 -> V_74 [ V_56 ] = V_75 [ V_59 + 1 ] ;
V_28 -> V_76 [ V_56 ] = V_77 [ V_59 + 1 ] ;
V_29 -> V_41 [ V_56 ] = V_59 + 1 ;
switch ( V_28 -> V_76 [ V_56 ] ) {
case V_78 :
F_18 ( V_49 , L_8 ) ;
V_45 = F_12 ( V_58 , V_53 , V_23 , 0 , 0 , V_79 ) ;
F_13 ( V_45 ) ;
V_57 = F_26 ( V_23 , V_26 , V_27 -> V_72 [ V_56 ] - V_26 ) ;
F_27 ( T_11 , V_57 , L_9 ) ;
F_19 ( V_80 , V_57 , T_11 , V_25 ) ;
break;
case V_81 :
F_18 ( V_49 , L_10 ) ;
V_45 = F_12 ( V_58 , V_53 , V_23 , 0 , 0 , V_82 ) ;
F_13 ( V_45 ) ;
V_57 = F_26 ( V_23 , V_26 , V_27 -> V_72 [ V_56 ] - V_26 ) ;
F_27 ( T_11 , V_57 , L_11 ) ;
F_19 ( V_83 , V_57 , T_11 , V_25 ) ;
break;
case V_84 :
F_18 ( V_49 , L_12 ) ;
break;
default:
F_18 ( V_49 , L_13 ) ;
F_25 ( T_11 , NULL , V_65 , V_66 , L_14 ) ;
}
break;
default:
F_18 ( V_49 , L_15 ) ;
F_25 ( T_11 , NULL , V_65 , V_66 , L_16 ) ;
}
}
static void F_28 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_7 V_13 , V_15 ;
T_8 V_26 = 0 ;
T_8 V_85 , V_56 ;
T_12 * V_86 = NULL ;
T_16 * V_45 ;
T_14 * V_28 ;
T_13 * V_27 ;
T_15 * V_29 ;
struct V_87 * V_88 ;
T_16 * V_49 = NULL ;
T_1 V_59 ;
V_13 = F_29 ( V_23 , 0 ) ;
V_15 = F_6 ( V_13 , & V_26 ) ;
V_85 = V_26 ;
F_15 ( T_11 -> V_46 , V_47 , L_1 ) ;
F_21 ( T_11 -> V_46 , V_48 ,
F_22 ( V_15 , V_89 , L_4 ) ) ;
V_49 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_86 = F_17 ( V_49 , V_90 ) ;
V_28 = ( T_14 * ) F_23 ( T_11 -> V_62 , V_50 , 0 ) ;
V_27 = ( T_13 * ) F_23 ( T_11 -> V_62 , V_63 , 0 ) ;
V_29 = ( T_15 * ) F_23 ( T_11 -> V_62 , V_64 , 0 ) ;
if ( ! V_28 || ! V_27 ) {
F_24 ( V_86 , V_23 , 0 , - 1 ,
L_5 ) ;
F_25 ( T_11 , V_49 , V_65 , V_66 , L_5 ) ;
return;
}
F_9 ( V_86 , V_91 , V_23 , 0 , V_85 , V_32 ) ;
if ( V_15 == V_17 ) {
V_28 -> V_39 [ V_27 -> V_36 ] = 1 ;
V_26 = F_7 ( V_23 , T_11 , V_86 , V_26 , V_27 , V_28 , V_29 ) ;
}
V_56 = V_27 -> V_69 ;
switch ( V_15 ) {
T_9 * V_57 ;
case V_19 :
F_18 ( V_49 , L_6 ) ;
V_45 = F_12 ( V_86 , V_53 , V_23 , 0 , 0 , V_71 ) ;
F_13 ( V_45 ) ;
V_57 = F_30 ( V_23 , 1 ) ;
F_19 ( V_73 , V_57 , T_11 , V_25 ) ;
break;
case V_17 :
V_59 = F_8 ( V_23 , V_26 - 4 , 4 ) ;
V_29 -> V_74 [ V_27 -> V_36 ] = V_75 [ V_59 + 1 ] ;
V_28 -> V_76 [ V_27 -> V_36 ] = V_77 [ V_59 + 1 ] ;
switch ( V_28 -> V_76 [ V_27 -> V_36 ] ) {
case V_78 :
F_18 ( V_49 , L_8 ) ;
V_45 = F_12 ( V_86 , V_53 , V_23 , 0 , 0 , V_79 ) ;
F_13 ( V_45 ) ;
V_57 = F_26 ( V_23 , V_26 , V_27 -> V_72 [ V_56 ] - V_26 ) ;
F_27 ( T_11 , V_57 , L_9 ) ;
F_19 ( V_80 , V_57 , T_11 , V_25 ) ;
break;
case V_81 :
F_18 ( V_49 , L_10 ) ;
V_45 = F_12 ( V_86 , V_53 , V_23 , 0 , 0 , V_82 ) ;
F_13 ( V_45 ) ;
V_57 = F_26 ( V_23 , V_26 , V_27 -> V_72 [ V_56 ] - V_26 ) ;
F_27 ( T_11 , V_57 , L_9 ) ;
F_19 ( V_83 , V_57 , T_11 , V_25 ) ;
break;
case V_84 :
F_18 ( V_49 , L_12 ) ;
F_25 ( T_11 , NULL , V_92 , V_66 , L_17 ) ;
break;
default:
F_18 ( V_49 , L_18 ) ;
F_25 ( T_11 , NULL , V_65 , V_66 , L_19 ) ;
}
break;
case V_22 :
F_18 ( V_49 , L_20 ) ;
V_45 = F_12 ( V_86 , V_53 , V_23 , 0 , 0 , V_93 ) ;
F_13 ( V_45 ) ;
V_57 = F_30 ( V_23 , 1 ) ;
F_19 ( V_94 , V_57 , T_11 , V_25 ) ;
break;
case V_16 :
F_18 ( V_49 , L_21 ) ;
V_45 = F_12 ( V_86 , V_53 , V_23 , 0 , 0 , V_95 ) ;
F_13 ( V_45 ) ;
V_57 = F_26 ( V_23 , 2 , ( F_31 ( V_23 ) * 8 ) - 2 ) ;
F_27 ( T_11 , V_57 , L_22 ) ;
V_88 = ( V_87 * ) F_23 ( T_11 -> V_62 , V_96 , 0 ) ;
if ( ! V_88 ) {
V_88 = F_32 ( struct V_87 ) ;
F_33 ( T_11 -> V_62 , V_96 , 0 , V_88 ) ;
}
V_88 -> V_97 [ V_27 -> V_36 ] = V_98 ;
F_19 ( V_99 , V_57 , T_11 , V_25 ) ;
break;
case V_21 :
case V_20 :
case V_18 :
F_25 ( T_11 , NULL , V_92 , V_66 , L_23 ) ;
break;
default:
F_18 ( V_49 , L_24 ) ;
F_25 ( T_11 , NULL , V_65 , V_66 , L_25 ) ;
break;
}
}
static void F_34 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_8 V_100 ;
T_7 V_26 = 0 ;
T_14 * V_28 ;
T_13 * V_27 ;
T_15 * V_29 ;
T_12 * V_101 = NULL ;
T_16 * V_45 ;
T_9 * V_57 ;
T_16 * V_49 = NULL ;
F_15 ( T_11 -> V_46 , V_47 , L_1 ) ;
V_49 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_101 = F_17 ( V_49 , V_102 ) ;
V_28 = ( T_14 * ) F_23 ( T_11 -> V_62 , V_50 , 0 ) ;
V_27 = ( T_13 * ) F_23 ( T_11 -> V_62 , V_63 , 0 ) ;
V_29 = ( T_15 * ) F_23 ( T_11 -> V_62 , V_64 , 0 ) ;
if ( ! V_28 || ! V_27 ) {
if( ! V_28 ) {
F_35 ( L_26 ) ;
}
if( ! V_27 ) {
F_35 ( L_27 ) ;
}
V_49 = F_24 ( V_101 , V_23 , 0 , - 1 ,
L_5 ) ;
F_25 ( T_11 , V_49 , V_92 , V_66 , L_28 ) ;
return;
}
V_100 = V_27 -> V_36 ;
if ( V_28 -> V_39 [ V_100 ] ) {
if( V_29 ) {
V_29 -> V_41 [ V_27 -> V_36 ] = F_8 ( V_23 , V_26 , 4 ) + 1 ;
}
F_9 ( V_101 , V_42 , V_23 , 0 , 4 , V_32 ) ;
V_26 = 4 ;
}
if ( V_26 ) {
V_57 = F_26 ( V_23 , V_26 , V_27 -> V_72 [ V_100 ] - V_26 ) ;
F_27 ( T_11 , V_57 , L_9 ) ;
} else
V_57 = V_23 ;
switch ( V_28 -> V_76 [ V_100 ] ) {
case V_78 :
F_18 ( V_49 , L_8 ) ;
if( V_28 -> V_6 [ V_100 ] != 255 ) {
V_45 = F_12 ( V_101 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
if( V_28 -> V_103 [ V_100 ] ) {
V_45 = F_24 ( V_101 , V_23 , 0 , 0 , L_29 ) ;
F_13 ( V_45 ) ;
}
} else{
V_45 = F_24 ( V_101 , V_23 , 0 , 0 , L_30 ) ;
F_13 ( V_45 ) ;
}
V_45 = F_12 ( V_101 , V_53 , V_23 , 0 , 0 , V_79 ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_101 , V_104 , V_23 , 0 , 0 , V_28 -> V_105 [ V_100 ] ) ;
F_13 ( V_45 ) ;
F_19 ( V_80 , V_57 , T_11 , V_25 ) ;
break;
case V_81 :
F_18 ( V_49 , L_10 ) ;
if( V_28 -> V_6 [ V_100 ] != 255 ) {
V_45 = F_12 ( V_101 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
} else{
V_45 = F_24 ( V_101 , V_23 , 0 , 0 , L_30 ) ;
F_13 ( V_45 ) ;
}
V_45 = F_12 ( V_101 , V_53 , V_23 , 0 , 0 , V_82 ) ;
F_13 ( V_45 ) ;
F_19 ( V_83 , V_57 , T_11 , V_25 ) ;
break;
case V_84 :
F_18 ( V_49 , L_12 ) ;
if( V_28 -> V_6 [ V_100 ] != 255 ) {
V_45 = F_12 ( V_101 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
if( V_28 -> V_103 [ V_100 ] ) {
V_45 = F_24 ( V_101 , V_23 , 0 , 0 , L_29 ) ;
F_13 ( V_45 ) ;
}
} else{
V_45 = F_24 ( V_101 , V_23 , 0 , 0 , L_30 ) ;
F_13 ( V_45 ) ;
}
V_45 = F_12 ( V_101 , V_53 , V_23 , 0 , 0 , V_82 ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_101 , V_104 , V_23 , 0 , 0 , V_28 -> V_105 [ V_100 ] ) ;
F_13 ( V_45 ) ;
break;
default:
F_18 ( V_49 , L_31 ) ;
F_25 ( T_11 , NULL , V_65 , V_66 , L_32 ) ;
}
}
static void F_36 ( T_9 * V_23 , T_17 * V_106 , T_5 V_107 , T_5 V_108 , T_18 V_10 , T_8 V_11 , T_7 type )
{
T_6 * V_12 = F_37 ( T_6 ) ;
V_12 -> type = type ;
V_12 -> V_107 = V_107 ;
V_12 -> V_109 = ( T_7 * ) F_38 ( V_107 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_11 = V_11 ;
V_12 -> V_110 = NULL ;
switch ( type ) {
case V_111 :
F_39 ( V_106 -> V_112 == NULL ) ;
V_106 -> V_112 = V_12 ;
break;
case V_113 :
F_39 ( V_106 -> V_114 == NULL ) ;
V_106 -> V_114 = V_12 ;
break;
case V_115 :
F_39 ( V_106 -> V_116 == NULL ) ;
V_106 -> V_116 = V_12 ;
break;
}
F_40 ( V_23 , V_12 -> V_109 , V_108 , V_107 ) ;
}
static void F_41 ( T_19 * V_117 , T_6 * V_12 , T_5 V_118 , T_2 V_119 )
{
F_39 ( V_117 -> V_107 + V_12 -> V_107 <= V_118 ) ;
if ( V_119 ) {
memcpy ( V_117 -> V_109 + V_118 - V_12 -> V_107 - V_117 -> V_107 , V_12 -> V_109 , V_12 -> V_107 ) ;
} else {
memcpy ( V_117 -> V_109 + V_117 -> V_107 , V_12 -> V_109 , V_12 -> V_107 ) ;
}
V_117 -> V_107 += V_12 -> V_107 ;
F_42 ( V_12 -> V_109 ) ;
}
static T_9 * F_43 ( T_9 * V_23 , T_17 * * V_120 , T_8 V_121 , T_5 V_107 , T_4 * V_9 , T_5 V_10 )
{
T_19 * V_117 ;
T_6 * V_122 ;
T_8 V_123 ;
T_20 * V_124 ;
V_124 = ( T_20 * ) F_44 ( V_125 , V_9 ) ;
if ( V_124 == NULL ) {
T_4 * V_126 ;
V_124 = F_45 ( F_5 , F_4 ) ;
V_126 = F_37 ( T_4 ) ;
* V_126 = * V_9 ;
F_46 ( V_125 , V_126 , V_124 ) ;
}
V_117 = F_37 ( T_19 ) ;
V_117 -> V_107 = 0 ;
V_117 -> V_109 = ( T_7 * ) F_47 ( V_107 ) ;
V_122 = V_120 [ V_121 ] -> V_112 ;
F_46 ( V_124 , V_122 , V_117 ) ;
V_120 [ V_121 ] -> V_112 = NULL ;
F_41 ( V_117 , V_122 , V_107 , FALSE ) ;
V_117 -> V_127 = V_122 ;
V_117 -> V_10 = V_10 ;
for ( V_123 = ( V_121 + 1 ) % V_128 ; V_120 [ V_123 ] -> V_114 != NULL ; V_123 = ( V_123 + 1 ) % V_128 )
{
V_122 = V_122 -> V_110 = V_120 [ V_123 ] -> V_114 ;
F_46 ( V_124 , V_122 , V_117 ) ;
V_120 [ V_123 ] -> V_114 = NULL ;
F_41 ( V_117 , V_122 , V_107 , FALSE ) ;
}
F_39 ( V_120 [ V_123 ] -> V_116 != NULL ) ;
V_122 -> V_110 = V_120 [ V_123 ] -> V_116 ;
F_46 ( V_124 , V_122 -> V_110 , V_117 ) ;
V_120 [ V_123 ] -> V_116 = NULL ;
V_117 -> V_11 = V_123 ;
F_41 ( V_117 , V_122 -> V_110 , V_107 , FALSE ) ;
return F_48 ( V_23 , V_117 -> V_109 , V_117 -> V_107 , V_117 -> V_107 ) ;
}
static T_19 * F_49 ( T_5 V_10 , T_8 V_11 , T_7 type , T_4 * V_9 )
{
T_19 * V_117 = NULL ;
T_20 * V_124 = NULL ;
T_6 V_129 ;
V_124 = ( T_20 * ) F_44 ( V_125 , V_9 ) ;
if ( V_124 ) {
V_129 . V_10 = V_10 ;
V_129 . V_11 = V_11 ;
V_129 . type = type ;
V_117 = ( T_19 * ) F_44 ( V_124 , & V_129 ) ;
return V_117 ;
}
return NULL ;
}
static T_9 * F_50 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 , T_19 * V_117 , T_5 V_108 , T_8 V_130 , T_7 type )
{
T_9 * V_131 = NULL ;
if ( V_117 -> V_10 == T_11 -> V_62 -> V_132 ) {
T_6 * V_122 = V_117 -> V_127 ;
T_5 V_133 = 0 ;
V_131 = F_48 ( V_23 , V_117 -> V_109 , V_117 -> V_107 , V_117 -> V_107 ) ;
F_27 ( T_11 , V_131 , L_33 ) ;
F_24 ( V_25 , V_131 , 0 , - 1 , L_34 ) ;
while ( V_122 ) {
F_51 ( V_25 , V_134 , V_131 ,
V_133 , V_122 -> V_107 , V_122 -> V_10 ,
L_35 ,
V_122 -> V_10 , V_133 , V_133 + V_122 -> V_107 - 1 , V_122 -> V_107 ,
V_122 -> V_11 ) ;
V_133 += V_122 -> V_107 ;
V_122 = V_122 -> V_110 ;
}
return V_131 ;
} else {
V_131 = F_52 ( V_23 , V_108 , V_130 , - 1 ) ;
switch ( type ) {
case V_111 :
F_24 ( V_25 , V_131 , 0 , - 1 , L_36 ) ;
break;
case V_113 :
F_24 ( V_25 , V_131 , 0 , - 1 , L_37 ) ;
break;
case V_115 :
F_24 ( V_25 , V_131 , 0 , - 1 , L_38 ) ;
break;
}
F_12 ( V_25 , V_135 , V_131 , 0 , 0 , V_117 -> V_10 ) ;
return NULL ;
}
}
static T_5 F_53 ( T_17 * * V_120 , T_8 * V_11 )
{
T_5 V_107 = 0 ;
* V_11 = ( * V_11 == 0 ) ? ( T_8 ) ( V_128 - 1 ) : ( * V_11 ) - 1 ;
for (; V_120 [ * V_11 ] -> V_114 != NULL ; * V_11 = ( * V_11 == 0 ) ? ( T_8 ) ( V_128 - 1 ) : ( * V_11 ) - 1 )
V_107 += V_120 [ * V_11 ] -> V_114 -> V_107 ;
if ( V_120 [ * V_11 ] -> V_112 != NULL )
return V_107 + V_120 [ * V_11 ] -> V_112 -> V_107 ;
return 0 ;
}
static T_5 F_54 ( T_17 * * V_120 , T_8 V_11 )
{
T_5 V_107 = 0 ;
for ( V_11 = ( V_11 + 1 ) % V_128 ; V_120 [ V_11 ] -> V_114 != NULL ; V_11 = ( V_11 + 1 ) % V_128 )
V_107 += V_120 [ V_11 ] -> V_114 -> V_107 ;
if ( V_120 [ V_11 ] -> V_116 != NULL )
return V_107 + V_120 [ V_11 ] -> V_116 -> V_107 ;
return 0 ;
}
static T_17 * * F_55 ( T_4 * V_9 )
{
T_17 * * V_136 = ( T_17 * * ) F_44 ( V_137 , V_9 ) ;
if ( V_136 == NULL ) {
T_4 * V_126 ;
T_8 V_123 ;
V_136 = F_56 ( T_17 * , V_128 ) ;
for ( V_123 = 0 ; V_123 < V_128 ; V_123 ++ ) {
V_136 [ V_123 ] = F_32 ( T_17 ) ;
}
V_126 = F_37 ( T_4 ) ;
* V_126 = * V_9 ;
F_46 ( V_137 , V_126 , V_136 ) ;
}
return V_136 ;
}
T_9 * F_57 ( T_9 * V_23 V_24 , T_10 * T_11 , T_12 * V_25 V_24 , T_7 V_6 , T_5 V_7 , int V_108 , T_7 V_138 , T_8 V_11 , int V_139 , T_7 V_140 , T_8 V_130 )
{
T_4 V_9 ;
V_9 . V_6 = V_6 ;
V_9 . V_7 = V_7 ;
if ( T_11 -> V_62 -> V_141 . V_142 == FALSE ) {
T_17 * * V_120 = F_55 ( & V_9 ) ;
if ( V_140 == 1 && V_138 == 3 ) {
T_5 V_143 , V_144 ;
F_36 ( V_23 , V_120 [ V_11 ] , V_130 , V_108 , T_11 -> V_62 -> V_132 , V_11 , V_113 ) ;
V_144 = F_54 ( V_120 , V_11 ) ;
if ( V_144 > 0 ) {
V_143 = F_53 ( V_120 , & V_11 ) ;
if ( V_143 > 0 ) {
return F_43 ( V_23 , V_120 , V_11 , V_144 + V_143 + V_130 , & V_9 , T_11 -> V_62 -> V_132 ) ;
}
}
}
else if ( V_139 == 0 && ( V_138 & 1 ) == 1 ) {
T_5 V_107 = V_130 ;
F_36 ( V_23 , V_120 [ V_11 ] , V_130 , V_108 , T_11 -> V_62 -> V_132 , V_11 , V_115 ) ;
V_107 += F_53 ( V_120 , & V_11 ) ;
if ( V_107 > V_130 ) {
return F_43 ( V_23 , V_120 , V_11 , V_107 , & V_9 , T_11 -> V_62 -> V_132 ) ;
}
}
else if ( V_139 == V_140 - 1 && ( V_138 & 2 ) == 2 ) {
T_5 V_107 = V_130 ;
F_36 ( V_23 , V_120 [ V_11 ] , V_130 , V_108 , T_11 -> V_62 -> V_132 , V_11 , V_111 ) ;
V_107 += F_54 ( V_120 , V_11 ) ;
if ( V_107 > V_130 ) {
return F_43 ( V_23 , V_120 , V_11 , V_107 , & V_9 , T_11 -> V_62 -> V_132 ) ;
}
} else {
F_39 ( ( V_139 == 0 ) ? ( V_138 & 1 ) == 0 : ( ( V_139 == V_140 - 1 ) ? ( V_138 & 2 ) == 0 : TRUE ) ) ;
return F_52 ( V_23 , V_108 , V_130 , - 1 ) ;
}
} else if ( V_25 ) {
T_9 * V_131 = NULL ;
if ( V_140 == 1 && V_138 == 3 ) {
T_19 * V_117 = F_49 ( T_11 -> V_62 -> V_132 , V_11 , V_113 , & V_9 ) ;
if ( V_117 ) {
return F_50 ( V_23 , T_11 , V_25 , V_117 , V_108 , V_130 , V_113 ) ;
}
}
else if ( V_139 == 0 && ( V_138 & 1 ) == 1 ) {
T_19 * V_117 = F_49 ( T_11 -> V_62 -> V_132 , V_11 , V_115 , & V_9 ) ;
if ( V_117 ) {
return F_50 ( V_23 , T_11 , V_25 , V_117 , V_108 , V_130 , V_115 ) ;
}
}
else if ( V_139 == V_140 - 1 && ( V_138 & 2 ) == 2 ) {
T_19 * V_117 = F_49 ( T_11 -> V_62 -> V_132 , V_11 , V_111 , & V_9 ) ;
if ( V_117 ) {
return F_50 ( V_23 , T_11 , V_25 , V_117 , V_108 , V_130 , V_111 ) ;
}
} else {
V_131 = F_52 ( V_23 , V_108 , V_130 , - 1 ) ;
F_24 ( V_25 , V_131 , 0 , - 1 , L_39 ) ;
F_16 ( V_25 , V_145 , V_131 , 0 , - 1 , V_51 ) ;
return V_131 ;
}
}
return NULL ;
}
static void F_58 ( T_9 * V_23 , T_12 * V_25 , T_7 V_138 , T_5 V_146 , T_5 V_108 )
{
switch ( V_138 ) {
case 0 :
if ( V_146 > 1 ) {
F_24 ( V_25 , V_23 , V_108 , 1 , L_40 ) ;
} else {
F_24 ( V_25 , V_23 , V_108 , 1 , L_41 ) ;
}
break;
case 1 :
if ( V_146 > 1 ) {
F_24 ( V_25 , V_23 , V_108 , 1 , L_42 ) ;
} else {
F_24 ( V_25 , V_23 , V_108 , 1 , L_43 ) ;
}
break;
case 2 :
if ( V_146 > 1 ) {
F_24 ( V_25 , V_23 , V_108 , 1 , L_44 ) ;
} else {
F_24 ( V_25 , V_23 , V_108 , 1 , L_45 ) ;
}
break;
case 3 :
if ( V_146 > 1 ) {
F_24 ( V_25 , V_23 , V_108 , 1 , L_46 ) ;
} else {
F_24 ( V_25 , V_23 , V_108 , 1 , L_47 ) ;
}
break;
}
}
static void F_59 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 , T_16 * V_49 , T_7 V_6 )
{
switch ( V_77 [ V_6 ] ) {
case V_78 :
F_18 ( V_49 , L_8 ) ;
F_19 ( V_80 , V_23 , T_11 , V_25 ) ;
break;
case V_81 :
F_18 ( V_49 , L_10 ) ;
F_19 ( V_83 , V_23 , T_11 , V_25 ) ;
break;
case V_84 :
F_18 ( V_49 , L_12 ) ;
break;
default:
F_18 ( V_49 , L_48 ) ;
F_25 ( T_11 , V_49 , V_65 , V_66 , L_49 ) ;
break;
}
}
static void F_60 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_5 V_139 , V_147 = 0 , V_108 = 0 ;
T_7 V_138 ;
T_8 V_11 ;
T_16 * V_148 , * V_40 ;
T_12 * V_149 , * V_150 ;
T_21 * V_151 = ( T_21 * ) F_23 ( T_11 -> V_62 , V_50 , 0 ) ;
T_15 * V_29 = ( T_15 * ) F_23 ( T_11 -> V_62 , V_64 , 0 ) ;
struct T_13 * V_152 = (struct T_13 * ) F_23 ( T_11 -> V_62 , V_63 , 0 ) ;
F_39 ( V_151 != NULL && V_29 != NULL && V_152 != NULL ) ;
V_148 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_149 = F_17 ( V_148 , V_153 ) ;
V_138 = ( F_29 ( V_23 , V_108 ) & 0xc0 ) >> 6 ;
F_16 ( V_149 , V_154 , V_23 , V_108 , 1 , V_32 ) ;
F_58 ( V_23 , V_149 , V_138 , V_151 -> V_146 , V_108 ) ;
V_11 = F_8 ( V_23 , V_108 * 8 + 2 , V_155 ) ;
F_9 ( V_149 , V_156 , V_23 , V_108 * 8 + 2 , V_155 , V_32 ) ;
V_108 += ( 2 + V_155 ) / 8 ;
for ( V_139 = 0 ; V_139 < V_151 -> V_146 ; V_139 ++ ) {
T_16 * V_49 ;
T_9 * V_157 ;
T_7 V_6 = V_151 -> V_6 [ V_139 ] + 1 ;
T_5 V_158 = V_151 -> V_158 [ V_139 ] ;
V_49 = F_16 ( V_25 , V_159 , V_23 , V_108 , V_158 , V_51 ) ;
V_150 = F_17 ( V_49 , V_160 ) ;
F_18 ( V_49 , L_50 , V_6 , V_158 ) ;
V_40 = F_12 ( V_49 , V_43 , V_23 , 0 , 0 , V_6 ) ;
F_13 ( V_40 ) ;
V_29 -> V_74 [ V_139 ] = V_75 [ V_6 ] ;
V_29 -> V_35 [ V_139 ] = V_152 -> V_161 ;
V_29 -> V_41 [ V_139 ] = V_6 ;
V_29 -> V_162 [ V_139 ] = V_163 ;
V_29 -> V_164 [ V_139 ] = FALSE ;
V_29 -> V_165 [ V_139 ] = FALSE ;
V_157 = F_57 ( V_23 , T_11 , V_150 , V_6 , V_152 -> V_161 , V_108 , V_138 , V_11 , V_139 , V_151 -> V_146 , V_158 ) ;
if ( V_157 != NULL ) {
F_59 ( V_157 , T_11 , V_25 , V_49 , V_6 ) ;
}
V_108 += V_158 ;
V_147 += V_158 ;
}
F_18 ( V_148 , L_51 ,
V_138 , V_11 , V_147 , V_151 -> V_146 ) ;
F_61 ( V_148 , 1 + V_147 ) ;
}
static void F_62 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_12 * V_166 = NULL ;
T_16 * V_45 ;
T_14 * V_28 ;
T_13 * V_27 ;
T_8 V_100 ;
T_16 * V_49 = NULL ;
F_15 ( T_11 -> V_46 , V_47 , L_1 ) ;
V_49 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_166 = F_17 ( V_49 , V_167 ) ;
V_27 = ( T_13 * ) F_23 ( T_11 -> V_62 , V_63 , 0 ) ;
V_28 = ( T_14 * ) F_23 ( T_11 -> V_62 , V_50 , 0 ) ;
if ( ! V_28 || ! V_27 ) {
V_49 = F_24 ( V_166 , V_23 , 0 , - 1 ,
L_5 ) ;
F_25 ( T_11 , V_49 , V_92 , V_66 , L_28 ) ;
return;
}
V_100 = V_27 -> V_36 ;
switch ( V_28 -> V_76 [ V_100 ] ) {
case V_78 :
F_18 ( V_49 , L_8 ) ;
V_45 = F_12 ( V_166 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_166 , V_53 , V_23 , 0 , 0 , V_79 ) ;
F_13 ( V_45 ) ;
F_19 ( V_80 , V_23 , T_11 , V_25 ) ;
break;
case V_81 :
F_18 ( V_49 , L_10 ) ;
V_45 = F_12 ( V_166 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_166 , V_53 , V_23 , 0 , 0 , V_82 ) ;
F_13 ( V_45 ) ;
F_19 ( V_83 , V_23 , T_11 , V_25 ) ;
break;
case V_84 :
F_18 ( V_49 , L_12 ) ;
break;
default:
F_18 ( V_49 , L_48 ) ;
F_25 ( T_11 , V_49 , V_65 , V_66 , L_49 ) ;
break;
}
}
static void F_63 ( T_9 * V_23 , T_10 * T_11 , T_12 * V_25 )
{
T_12 * V_168 = NULL ;
T_16 * V_45 ;
T_13 * V_27 ;
T_14 * V_28 ;
T_8 V_100 ;
T_7 V_26 = 0 ;
T_9 * V_57 ;
T_16 * V_49 = NULL ;
T_15 * V_29 ;
F_15 ( T_11 -> V_46 , V_47 , L_1 ) ;
V_49 = F_16 ( V_25 , V_50 , V_23 , 0 , - 1 , V_51 ) ;
V_168 = F_17 ( V_49 , V_169 ) ;
V_27 = ( T_13 * ) F_23 ( T_11 -> V_62 , V_63 , 0 ) ;
V_28 = ( T_14 * ) F_23 ( T_11 -> V_62 , V_50 , 0 ) ;
V_100 = V_27 -> V_36 ;
V_26 = V_27 -> V_170 == V_171 ? 0 : 4 ;
if ( ! V_28 ) {
F_24 ( V_168 , V_23 , 0 , - 1 ,
L_5 ) ;
F_25 ( T_11 , V_49 , V_65 , V_66 , L_5 ) ;
return;
}
if ( V_28 -> V_39 [ V_100 ] ) {
F_9 ( V_168 , V_42 , V_23 , V_26 , 4 , V_32 ) ;
V_28 -> V_6 [ V_100 ] = F_8 ( V_23 , V_26 , 4 ) + 1 ;
V_28 -> V_103 [ V_100 ] = FALSE ;
V_28 -> V_76 [ V_100 ] = V_77 [ V_28 -> V_6 [ V_100 ] ] ;
V_29 = ( T_15 * ) F_23 ( T_11 -> V_62 , V_64 , 0 ) ;
V_29 -> V_41 [ V_100 ] = V_28 -> V_6 [ V_100 ] ;
V_29 -> V_74 [ V_100 ] = V_75 [ V_28 -> V_6 [ V_100 ] ] ;
V_26 += 4 ;
}
if ( ( V_26 % 8 ) == 0 ) {
V_57 = F_30 ( V_23 , V_26 / 8 ) ;
} else {
V_57 = F_26 ( V_23 , V_26 , V_28 -> V_172 ) ;
F_27 ( T_11 , V_57 , L_52 ) ;
}
switch ( V_28 -> V_76 [ V_100 ] ) {
case V_173 :
F_18 ( V_49 , L_6 ) ;
if( V_28 -> V_6 [ V_100 ] != 255 ) {
V_45 = F_12 ( V_168 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
if( V_28 -> V_103 [ V_100 ] ) {
V_45 = F_24 ( V_168 , V_23 , 0 , 0 , L_29 ) ;
F_13 ( V_45 ) ;
}
} else{
V_45 = F_24 ( V_168 , V_23 , 0 , 0 , L_30 ) ;
F_13 ( V_45 ) ;
}
V_45 = F_12 ( V_168 , V_53 , V_23 , 0 , 0 , V_79 ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_168 , V_174 , V_23 , 0 , 0 , V_28 -> V_175 [ V_100 ] ) ;
F_13 ( V_45 ) ;
F_19 ( V_73 , V_57 , T_11 , V_25 ) ;
break;
case V_78 :
F_18 ( V_49 , L_8 ) ;
if( V_28 -> V_6 [ V_100 ] != 255 ) {
V_45 = F_12 ( V_168 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
if( V_28 -> V_103 [ V_100 ] ) {
V_45 = F_24 ( V_168 , V_23 , 0 , 0 , L_29 ) ;
F_13 ( V_45 ) ;
}
} else{
V_45 = F_24 ( V_168 , V_23 , 0 , 0 , L_30 ) ;
F_13 ( V_45 ) ;
}
V_45 = F_12 ( V_168 , V_53 , V_23 , 0 , 0 , V_79 ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_168 , V_174 , V_23 , 0 , 0 , V_28 -> V_175 [ V_100 ] ) ;
F_13 ( V_45 ) ;
F_19 ( V_80 , V_57 , T_11 , V_25 ) ;
break;
case V_81 :
F_18 ( V_49 , L_10 ) ;
if( V_28 -> V_6 [ V_100 ] != 255 ) {
V_45 = F_12 ( V_168 , V_43 , V_23 , 0 , 0 , V_28 -> V_6 [ V_100 ] ) ;
F_13 ( V_45 ) ;
if( V_28 -> V_103 [ V_100 ] ) {
V_45 = F_24 ( V_168 , V_23 , 0 , 0 , L_29 ) ;
F_13 ( V_45 ) ;
}
} else{
V_45 = F_24 ( V_168 , V_23 , 0 , 0 , L_30 ) ;
F_13 ( V_45 ) ;
}
V_45 = F_12 ( V_168 , V_53 , V_23 , 0 , 0 , V_82 ) ;
F_13 ( V_45 ) ;
V_45 = F_12 ( V_168 , V_174 , V_23 , 0 , 0 , V_28 -> V_175 [ V_100 ] ) ;
F_13 ( V_45 ) ;
F_19 ( V_83 , V_57 , T_11 , V_25 ) ;
break;
case V_84 :
F_18 ( V_49 , L_12 ) ;
break;
default:
F_18 ( V_49 , L_53 ) ;
F_25 ( T_11 , NULL , V_65 , V_66 , L_54 ) ;
}
}
static void F_64 ( T_22 V_109 )
{
F_65 ( ( T_20 * ) V_109 ) ;
}
static void F_66 ( void )
{
if ( V_125 != NULL ) {
F_65 ( V_125 ) ;
}
if ( V_137 != NULL ) {
F_65 ( V_137 ) ;
}
V_125 = F_67 ( F_3 , F_2 , NULL , F_64 ) ;
V_137 = F_67 ( F_3 , F_2 , NULL , NULL ) ;
if ( V_1 == V_176 ) {
V_128 = 64 ;
V_155 = 6 ;
} else {
V_128 = 16384 ;
V_155 = 14 ;
}
}
void
F_68 ( void )
{
T_23 * V_177 ;
static T_1 * V_178 [] = {
& V_179 ,
& V_90 ,
& V_61 ,
& V_102 ,
& V_52 ,
& V_167 ,
& V_169 ,
& V_153 ,
& V_160
} ;
static T_24 V_180 [] = {
{ & V_67 ,
{ L_55 , L_56 ,
V_181 , V_182 , F_69 ( V_60 ) , 0 , NULL , V_183 }
} ,
{ & V_91 ,
{ L_55 , L_56 ,
V_181 , V_182 , F_69 ( V_89 ) , 0 , NULL , V_183 }
} ,
{ & V_42 ,
{ L_57 , L_58 ,
V_181 , V_182 , NULL , 0 , NULL , V_183 }
} ,
{ & V_31 ,
{ L_59 , L_60 ,
V_181 , V_184 , F_69 ( V_185 ) , 0 , NULL , V_183 }
} ,
{ & V_38 ,
{ L_61 , L_62 ,
V_186 , V_182 , NULL , 0x0 , NULL , V_183 }
} ,
{ & V_34 ,
{ L_63 , L_62 ,
V_187 , V_182 , NULL , 0x0 , NULL , V_183 }
} ,
{ & V_53 ,
{ L_64 , L_65 ,
V_186 , V_184 , F_69 ( V_188 ) , 0 , NULL , V_183 }
} ,
#if 0
{ &hf_mac_channel_str,
{ "Logical Channel", "mac.logical_channel",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
#endif
#if 0
{ &hf_mac_channel_hsdsch,
{ "MACd-FlowID", "mac.macd_flowid", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_174 ,
{ L_66 , L_67 , V_186 , V_184 , NULL , 0x0 , NULL , V_183 }
} ,
{ & V_43 ,
{ L_68 , L_69 , V_186 , V_184 , NULL , 0x0 , NULL , V_183 }
} ,
{ & V_104 ,
{ L_70 , L_71 , V_186 , V_184 , NULL , 0x0 , NULL , V_183 }
} ,
#if 0
{ &hf_mac_edch_type2_descriptors,
{ "MAC-is Descriptors",
"mac.edch.type2.descriptors", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
#if 0
{ &hf_mac_edch_type2_lchid,
{ "LCH-ID",
"mac.logical_channel_id", FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL
}
},
#endif
#if 0
{ &hf_mac_edch_type2_length,
{ "Length",
"mac.edch.type2.length", FT_UINT16, BASE_DEC, NULL, 0x0ffe,
NULL, HFILL
}
},
#endif
#if 0
{ &hf_mac_edch_type2_flag,
{ "Flag",
"mac.edch.type2.lchid", FT_UINT8, BASE_HEX, NULL, 0x01,
"Indicates if another entry follows", HFILL
}
},
#endif
{ & V_154 ,
{ L_72 ,
L_73 , V_181 , V_182 , NULL , 0xc0 ,
L_74 , V_183
}
} ,
{ & V_156 ,
{ L_75 ,
L_76 , V_186 , V_184 , NULL , 0 ,
L_77 , V_183
}
} ,
{ & V_159 ,
{ L_78 ,
L_79 , V_189 , V_190 , NULL , 0x0 ,
NULL , V_183
}
} ,
{ & V_145 ,
{ L_80 ,
L_81 , V_191 , V_190 , NULL , 0x0 ,
NULL , V_183
}
} ,
#if 0
{ &hf_mac_edch_type2_subframe_header,
{ "Subframe header",
"mac.edch.type2.subframeheader", FT_STRING, BASE_NONE, NULL, 0x0,
"EDCH Subframe header", HFILL
}
},
#endif
{ & V_135 ,
{ L_82 , L_83 ,
V_192 , V_190 , NULL , 0 , NULL , V_183 }
} ,
{ & V_134 ,
{ L_84 , L_85 ,
V_192 , V_190 , NULL , 0 , NULL , V_183 }
}
} ;
V_50 = F_70 ( L_1 , L_1 , L_86 ) ;
F_71 ( V_50 , V_180 , F_72 ( V_180 ) ) ;
F_73 ( V_178 , F_72 ( V_178 ) ) ;
F_74 ( L_87 , F_20 , V_50 ) ;
F_74 ( L_88 , F_28 , V_50 ) ;
F_74 ( L_89 , F_14 , V_50 ) ;
F_74 ( L_90 , F_34 , V_50 ) ;
F_74 ( L_91 , F_62 , V_50 ) ;
F_74 ( L_92 , F_60 , V_50 ) ;
F_74 ( L_93 , F_63 , V_50 ) ;
F_75 ( F_66 ) ;
V_177 = F_76 ( V_50 , NULL ) ;
F_77 ( V_177 , L_94 , L_95 ,
L_96 ,
& V_1 , V_193 , FALSE ) ;
}
void
F_78 ( void )
{
V_55 = F_79 ( L_97 ) ;
V_73 = F_79 ( L_98 ) ;
V_94 = F_79 ( L_99 ) ;
V_80 = F_79 ( L_100 ) ;
V_83 = F_79 ( L_101 ) ;
V_99 = F_79 ( L_102 ) ;
}
