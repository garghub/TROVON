static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_5 V_7 ;
T_10 V_8 ;
T_2 * V_9 ;
V_7 = V_4 ;
F_2 ( V_2 , V_1 , V_7 , V_5 , L_1 ) ;
V_8 = F_3 ( V_1 , V_7 ) ;
F_4 ( V_2 , V_10 , V_1 , V_7 , 1 , V_11 ) ;
switch( V_8 ) {
case 1 :
V_9 = F_5 ( V_1 , V_7 + 1 , V_5 - 1 ) ;
if( V_12 )
F_6 ( V_12 , V_9 , V_3 , V_13 ) ;
break;
case 2 :
break;
case 3 :
break;
default:
break;
}
V_7 += V_5 ;
F_7 ( V_5 , V_7 - V_4 ) ;
return ( V_7 - V_4 ) ;
}
static T_1
F_8 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_11 V_14 ;
V_14 = ( V_4 << 3 ) ;
F_9 ( V_2 , V_15 , V_1 , V_14 , 7 , V_11 ) ;
V_14 += 7 ;
F_9 ( V_2 , V_16 , V_1 , V_14 , 1 , V_11 ) ;
V_14 ++ ;
F_9 ( V_2 , V_17 , V_1 , V_14 , 56 , V_18 ) ;
V_14 += 56 ;
F_9 ( V_2 , V_19 , V_1 , V_14 , 56 , V_18 ) ;
return ( V_5 ) ;
}
static T_1
F_10 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_5 V_7 ;
V_7 = V_4 ;
F_4 ( V_2 , V_20 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_21 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_22 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_23 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_24 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_25 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_26 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_27 , V_1 , V_7 , 1 , V_11 ) ;
V_7 ++ ;
F_4 ( V_2 , V_28 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_29 , V_1 , V_7 , 1 , V_11 ) ;
F_4 ( V_2 , V_30 , V_1 , V_7 , 1 , V_11 ) ;
V_7 ++ ;
F_2 ( V_2 , V_1 , V_7 , V_5 - 2 , L_2 ) ;
return ( V_5 ) ;
}
static T_1
F_11 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_5 V_7 ;
V_7 = V_4 ;
F_4 ( V_2 , V_31 , V_1 , V_7 , 1 , V_11 ) ;
V_7 ++ ;
if ( V_5 == 2 )
{
F_4 ( V_2 , V_32 , V_1 , V_7 , 1 , V_11 ) ;
V_7 ++ ;
}
return ( V_7 - V_4 ) ;
}
static T_1
F_12 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 V_6 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_5 V_7 ;
T_10 V_33 ;
V_33 = V_4 << 3 ;
V_7 = V_4 ;
F_9 ( V_2 , V_34 , V_1 , V_33 , 4 , V_11 ) ;
V_33 = V_33 + 4 ;
F_9 ( V_2 , V_35 , V_1 , V_33 , 4 , V_11 ) ;
V_7 ++ ;
return ( V_7 - V_4 ) ;
}
static T_1
F_13 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_12 V_36 , V_37 , V_38 , V_39 ;
T_1 V_33 ;
V_33 = V_4 << 3 ;
F_9 ( V_2 , V_15 , V_1 , V_33 , 6 , V_11 ) ;
V_33 = V_33 + 6 ;
F_14 ( V_2 , V_40 , V_1 , V_33 , 1 , & V_37 , V_11 ) ;
V_33 ++ ;
F_14 ( V_2 , V_41 , V_1 , V_33 , 1 , & V_36 , V_11 ) ;
V_33 ++ ;
F_14 ( V_2 , V_42 , V_1 , V_33 , 1 , & V_38 , V_11 ) ;
V_33 ++ ;
if( V_38 == 1 )
{
F_9 ( V_2 , V_43 , V_1 , V_33 , 7 , V_11 ) ;
V_33 = V_33 + 7 ;
}
else
{
F_9 ( V_2 , V_15 , V_1 , V_33 , 7 , V_11 ) ;
V_33 = V_33 + 7 ;
}
F_14 ( V_2 , V_44 , V_1 , V_33 , 1 , & V_39 , V_11 ) ;
V_33 ++ ;
if( V_39 == 1 )
{
F_9 ( V_2 , V_45 , V_1 , V_33 , 7 , V_11 ) ;
V_33 = V_33 + 7 ;
}
else
{
F_9 ( V_2 , V_15 , V_1 , V_33 , 7 , V_11 ) ;
V_33 = V_33 + 7 ;
}
F_9 ( V_2 , V_46 , V_1 , V_33 , 2 , V_11 ) ;
return ( V_5 ) ;
}
static T_1
F_15 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
T_2 * V_47 ;
T_5 V_7 ;
V_7 = V_4 ;
V_47 = F_5 ( V_1 , V_7 , V_5 ) ;
F_16 ( V_47 , V_3 , V_2 ) ;
return ( V_5 ) ;
}
static T_1
F_17 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
F_2 ( V_2 , V_1 , V_4 , V_5 , L_3 ) ;
return V_5 ;
}
static T_1
F_18 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
F_2 ( V_2 , V_1 , V_4 , V_5 , L_3 ) ;
return V_5 ;
}
static T_1
F_19 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 , T_7 * T_8 V_6 , int T_9 V_6 )
{
F_2 ( V_2 , V_1 , V_4 , V_5 , L_3 ) ;
return V_5 ;
}
static void
F_20 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 )
{
T_5 V_7 ;
T_5 V_48 ;
T_6 V_49 ;
V_7 = V_4 ;
V_49 = V_5 ;
F_21 (BSSMAP_LE_LOCATION_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_LOC_TYPE, NULL)
F_21 ( V_50 , V_51 , V_52 , NULL ) ;
F_22 ( V_53 , V_51 , V_54 , NULL ) ;
F_22 ( V_55 , V_56 , V_57 , NULL ) ;
F_22 ( V_58 , V_51 , V_59 , NULL ) ;
F_22 ( V_60 , V_51 , V_61 , NULL ) ;
F_22 ( V_62 , V_56 , V_63 , NULL ) ;
F_22 ( V_64 , V_51 , V_65 , NULL ) ;
F_23 ( V_66 , V_56 , V_67 , NULL ) ;
F_22 ( V_68 , V_56 , V_69 , NULL ) ;
F_22 ( V_70 , V_56 , V_71 , NULL ) ;
F_22 ( V_72 , V_56 , V_73 , NULL ) ;
F_22 ( V_74 , V_56 , V_75 , NULL ) ;
F_22 ( V_76 , V_56 , V_77 , NULL ) ;
F_22 ( V_78 , V_56 , V_79 , NULL ) ;
F_22 ( V_80 , V_56 , V_81 , NULL ) ;
F_7 ( V_49 , 0 ) ;
}
static void
F_24 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 )
{
T_5 V_7 ;
T_5 V_48 ;
T_6 V_49 ;
V_7 = V_4 ;
V_49 = V_5 ;
F_22 ( V_82 , V_83 , V_84 , NULL ) ;
F_22 ( V_85 , V_56 , V_86 , NULL ) ;
F_22 ( V_87 , V_56 , V_88 , NULL ) ;
F_22 ( V_89 , V_56 , V_90 , NULL ) ;
F_22 ( V_91 , V_83 , V_92 , NULL ) ;
F_22 ( V_93 , V_56 , V_94 , NULL ) ;
F_7 ( V_49 , 0 ) ;
}
static void
F_25 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 )
{
T_5 V_7 ;
T_5 V_48 ;
T_6 V_49 ;
V_7 = V_4 ;
V_49 = V_5 ;
F_23 ( V_66 , V_56 , V_67 , NULL ) ;
F_22 ( V_95 , V_83 , V_96 , NULL ) ;
F_7 ( V_49 , 0 ) ;
}
static void
F_26 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 V_6 , T_5 V_4 , T_6 V_5 )
{
T_5 V_7 ;
T_5 V_48 ;
T_6 V_49 ;
V_7 = V_4 ;
V_49 = V_5 ;
F_21 ( V_50 , V_51 , V_52 , NULL ) ;
F_23 ( V_66 , V_56 , V_67 , NULL ) ;
F_7 ( V_49 , 0 ) ;
}
void
F_27 ( T_2 * V_1 , T_4 * V_3 , T_3 * V_2 )
{
static T_13 V_97 [ 4 ] ;
static T_13 * V_98 ;
static T_6 V_99 = 0 ;
T_10 V_100 ;
T_5 V_4 , V_101 ;
T_5 V_5 ;
T_11 V_102 ;
T_14 * V_103 = NULL ;
T_3 * V_104 = NULL ;
const T_7 * V_105 ;
T_15 * V_106 ;
V_106 = V_3 -> V_107 ;
if ( ! ( V_106 && V_106 -> V_108 . V_109 . V_110 ) ) {
V_106 = NULL ;
}
F_28 ( V_3 -> V_111 , V_112 , L_4 ) ;
V_99 ++ ;
if ( V_99 >= 4 )
{
V_99 = 0 ;
}
V_98 = & V_97 [ V_99 ] ;
V_4 = 0 ;
V_101 = V_4 ;
V_13 = V_2 ;
V_5 = F_29 ( V_1 ) ;
V_100 = F_3 ( V_1 , V_4 ++ ) ;
V_105 = F_30 ( ( T_5 ) V_100 , V_113 , & V_102 ) ;
if ( V_106 && ! V_106 -> V_108 . V_109 . V_114 ) {
V_106 -> V_108 . V_109 . V_114 = F_31 ( F_32 () ,
F_33 ( ( T_5 ) V_100 ,
V_113 , L_5 ) ) ;
}
if ( V_105 == NULL )
{
V_103 =
F_34 ( V_2 , V_115 , V_1 , 0 , V_5 ,
L_6 ,
V_100 ) ;
V_104 = F_35 ( V_103 , V_116 ) ;
}
else
{
V_103 =
F_34 ( V_2 , V_115 , V_1 , 0 , - 1 ,
L_7 ,
V_105 ) ;
V_104 = F_35 ( V_103 , V_117 [ V_102 ] ) ;
F_36 ( V_3 -> V_111 , V_112 , L_8 , V_105 ) ;
F_37 ( V_104 , V_118 ,
V_1 , V_101 , 1 , V_100 , L_9 , V_105 ) ;
}
V_98 -> V_119 = V_83 ;
V_98 -> V_120 = V_100 ;
F_38 ( V_121 , V_3 , V_98 ) ;
if ( V_105 == NULL ) return;
if ( V_4 >= V_5 ) return;
if ( V_122 [ V_102 ] == NULL )
{
F_2 ( V_104 ,
V_1 , V_4 , V_5 - V_4 ,
L_10 ) ;
}
else
{
(* V_122 [ V_102 ])( V_1 , V_104 , V_3 , V_4 , V_5 - V_4 ) ;
}
}
void
F_39 ( void )
{
T_6 V_123 ;
T_6 V_124 ;
static T_16 V_125 [] = {
{ & V_118 ,
{ L_11 , L_12 ,
V_126 , V_127 , F_40 ( V_113 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_129 ,
{ L_13 , L_14 ,
V_126 , V_127 , NULL , 0 ,
NULL , V_128 }
} ,
{ & V_10 ,
{ L_15 , L_16 ,
V_126 , V_130 , F_40 ( V_131 ) , 0x0 ,
L_17 , V_128 }
} ,
{ & V_15 ,
{ L_18 , L_19 ,
V_126 , V_127 , NULL , 0x0 ,
NULL , V_128 }
} ,
{ & V_16 ,
{ L_20 , L_21 ,
V_126 , V_130 , NULL , 0x0 ,
NULL , V_128 }
} ,
{ & V_17 ,
{ L_22 , L_23 ,
V_132 , V_127 , NULL , 0x0 , NULL ,
V_128 }
} ,
{ & V_19 ,
{ L_24 , L_25 ,
V_132 , V_127 , NULL , 0x0 ,
NULL , V_128 }
} ,
{ & V_20 ,
{ L_26 , L_27 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x80 ,
NULL , V_128 }
} ,
{ & V_21 ,
{ L_28 , L_29 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x40 ,
NULL , V_128 }
} ,
{ & V_22 ,
{ L_30 , L_31 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x20 ,
NULL , V_128 }
} ,
{ & V_23 ,
{ L_32 , L_33 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x08 ,
NULL , V_128 }
} ,
{ & V_24 ,
{ L_34 , L_35 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x10 ,
NULL , V_128 }
} ,
{ & V_25 ,
{ L_36 , L_37 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x04 ,
NULL , V_128 }
} ,
{ & V_26 ,
{ L_38 , L_39 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x02 ,
NULL , V_128 }
} ,
{ & V_27 ,
{ L_40 , L_41 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x01 ,
NULL , V_128 }
} ,
{ & V_28 ,
{ L_42 , L_43 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x04 ,
NULL , V_128 }
} ,
{ & V_29 ,
{ L_44 , L_45 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x02 ,
NULL , V_128 }
} ,
{ & V_30 ,
{ L_46 , L_47 ,
V_133 , 8 , F_41 ( & V_134 ) , 0x01 ,
NULL , V_128 }
} ,
{ & V_31 ,
{ L_48 , L_49 ,
V_126 , V_127 , F_40 ( V_135 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_32 ,
{ L_50 , L_51 ,
V_126 , V_127 , F_40 ( V_136 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_34 ,
{ L_52 , L_53 ,
V_126 , V_127 , F_40 ( V_137 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_35 ,
{ L_54 , L_55 ,
V_126 , V_127 , F_40 ( V_138 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_40 ,
{ L_56 , L_57 ,
V_126 , V_127 , F_40 ( V_139 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_41 ,
{ L_58 , L_59 ,
V_126 , V_127 , F_40 ( V_140 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_42 ,
{ L_60 , L_61 ,
V_126 , V_127 , F_40 ( V_141 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_43 ,
{ L_62 , L_63 ,
V_126 , V_127 , NULL , 0x0 ,
NULL , V_128 }
} ,
{ & V_45 ,
{ L_64 , L_65 ,
V_126 , V_127 , NULL , 0x0 ,
NULL , V_128 }
} ,
{ & V_44 ,
{ L_66 , L_67 ,
V_126 , V_127 , F_40 ( V_142 ) , 0x0 ,
NULL , V_128 }
} ,
{ & V_46 ,
{ L_68 , L_69 ,
V_126 , V_127 , F_40 ( V_143 ) , 0x0 ,
NULL , V_128 }
} ,
} ;
#define F_42 1
T_11 * V_144 [ F_42 + V_145 +
V_146 ] ;
V_144 [ 0 ] = & V_116 ;
V_124 = F_42 ;
for ( V_123 = 0 ; V_123 < V_145 ; V_123 ++ , V_124 ++ )
{
V_117 [ V_123 ] = - 1 ;
V_144 [ V_124 ] = & V_117 [ V_123 ] ;
}
for ( V_123 = 0 ; V_123 < V_146 ; V_123 ++ , V_124 ++ )
{
V_147 [ V_123 ] = - 1 ;
V_144 [ V_124 ] = & V_147 [ V_123 ] ;
}
V_115 =
F_43 ( L_70 , L_71 , L_72 ) ;
F_44 ( V_115 , V_125 , F_45 ( V_125 ) ) ;
F_46 ( V_144 , F_45 ( V_144 ) ) ;
F_47 ( L_72 , F_27 , V_115 ) ;
}
void
F_48 ( void )
{
T_17 V_148 ;
V_148 = F_49 ( L_72 ) ;
F_50 ( L_73 , V_83 , V_148 ) ;
V_12 = F_49 ( L_74 ) ;
}
