static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_5 * V_6 ;
T_3 * V_7 ;
T_3 * V_8 ;
T_3 * V_9 ;
T_6 V_10 ;
T_6 V_11 ;
const char * V_12 ;
T_6 V_13 ;
T_6 V_14 ;
T_6 V_15 ;
T_7 V_16 ;
T_7 V_17 ;
T_8 * V_18 ;
T_9 * V_19 ;
T_10 * V_20 ;
T_11 V_21 [ 2 ] ;
T_12 V_22 [ 4 ] ;
V_16 = F_2 ( V_1 ) ;
if ( V_16 < V_23 )
return 0 ;
V_10 = F_3 ( V_1 , 0 ) ;
if ( V_10 & 0xC000 || F_4 ( V_1 , 4 ) == 0x2112a442
|| F_4 ( V_1 , 4 ) == 0x7f5a9bc7 )
return 0 ;
V_12 = F_5 ( V_10 , V_24 ) ;
if ( V_12 == NULL )
return 0 ;
V_11 = F_3 ( V_1 , 2 ) ;
if ( V_16 != V_23 + V_11 )
return 0 ;
V_22 [ 0 ] = F_4 ( V_1 , 4 ) ;
V_22 [ 1 ] = F_4 ( V_1 , 8 ) ;
V_22 [ 2 ] = F_4 ( V_1 , 12 ) ;
V_22 [ 3 ] = F_4 ( V_1 , 16 ) ;
V_21 [ 0 ] . V_25 = 4 ;
V_21 [ 0 ] . V_26 = V_22 ;
V_21 [ 1 ] . V_25 = 0 ;
V_21 [ 1 ] . V_26 = NULL ;
V_18 = F_6 ( V_2 ) ;
V_19 = ( T_9 * ) F_7 ( V_18 , V_27 ) ;
if ( ! V_19 ) {
V_19 = F_8 ( T_9 ) ;
V_19 -> V_28 = F_9 ( V_29 , L_1 ) ;
F_10 ( V_18 , V_27 , V_19 ) ;
}
if( ! V_2 -> V_30 -> V_31 . V_32 ) {
if ( ( ( V_10 & V_33 ) >> 4 ) == V_34 ) {
V_20 = F_8 ( T_10 ) ;
V_20 -> V_35 = V_2 -> V_30 -> V_36 ;
V_20 -> V_37 = 0 ;
V_20 -> V_38 = V_2 -> V_30 -> V_39 ;
F_11 ( V_19 -> V_28 , V_21 ,
( void * ) V_20 ) ;
} else {
V_20 = ( T_10 * ) F_12 ( V_19 -> V_28 ,
V_21 ) ;
if( V_20 ) {
V_20 -> V_37 = V_2 -> V_30 -> V_36 ;
}
}
} else {
V_20 = ( T_10 * ) F_12 ( V_19 -> V_28 , V_21 ) ;
}
if( ! V_20 ) {
V_20 = F_13 ( T_10 ) ;
V_20 -> V_35 = 0 ;
V_20 -> V_37 = 0 ;
V_20 -> V_38 = V_2 -> V_30 -> V_39 ;
}
F_14 ( V_2 -> V_40 , V_41 , L_2 ) ;
F_15 ( V_2 -> V_40 , V_42 , L_3 ,
V_12 ) ;
if ( V_3 ) {
T_7 V_43 ;
V_5 = F_16 ( V_3 , V_27 , V_1 , 0 , - 1 , V_44 ) ;
V_7 = F_17 ( V_5 , V_45 ) ;
if ( ( ( V_10 & V_33 ) >> 4 ) == V_34 ) {
if ( V_20 -> V_37 ) {
T_5 * V_46 ;
V_46 = F_18 ( V_7 , V_47 ,
V_1 , 0 , 0 ,
V_20 -> V_37 ) ;
F_19 ( V_46 ) ;
}
}
else if ( ( ( ( V_10 & V_33 ) >> 4 ) == V_48 ) ||
( ( ( V_10 & V_33 ) >> 4 ) == V_49 ) ) {
if( V_20 -> V_35 ) {
T_5 * V_46 ;
T_13 V_50 ;
V_46 = F_18 ( V_7 , V_51 , V_1 , 0 , 0 , V_20 -> V_35 ) ;
F_19 ( V_46 ) ;
F_20 ( & V_50 , & V_2 -> V_30 -> V_39 , & V_20 -> V_38 ) ;
V_46 = F_21 ( V_7 , V_52 , V_1 , 0 , 0 , & V_50 ) ;
F_19 ( V_46 ) ;
}
}
F_18 ( V_7 , V_53 , V_1 , 0 , 2 , V_10 ) ;
F_18 ( V_7 , V_54 , V_1 , 2 , 2 , V_11 ) ;
F_16 ( V_7 , V_55 , V_1 , 4 , 16 , V_44 ) ;
V_43 = F_4 ( V_1 , 4 ) ;
if ( V_11 > 0 ) {
V_6 = F_16 ( V_7 , V_56 , V_1 , V_23 , V_11 , V_44 ) ;
V_8 = F_17 ( V_6 , V_57 ) ;
V_15 = V_23 ;
while( V_11 > 0 ) {
V_13 = F_3 ( V_1 , V_15 ) ;
V_14 = F_3 ( V_1 , V_15 + 2 ) ;
V_6 = F_22 ( V_8 , V_1 , V_15 ,
V_58 + V_14 ,
L_4 ,
F_23 ( V_13 , V_59 , L_5 ) ) ;
V_9 = F_17 ( V_6 , V_60 ) ;
F_18 ( V_9 , V_61 , V_1 ,
V_15 , 2 , V_13 ) ;
V_15 += 2 ;
if ( V_58 + V_14 > V_11 ) {
F_24 ( V_9 ,
V_62 , V_1 , V_15 , 2 ,
V_14 ,
L_6 ,
V_14 ) ;
break;
}
F_18 ( V_9 , V_62 , V_1 ,
V_15 , 2 , V_14 ) ;
V_15 += 2 ;
switch( V_13 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
if ( V_14 < 2 )
break;
F_16 ( V_9 , V_71 , V_1 , V_15 + 1 , 1 , V_72 ) ;
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_73 , V_1 , V_15 + 2 , 2 , V_72 ) ;
switch( F_25 ( V_1 , V_15 + 1 ) ) {
case 1 :
if ( V_14 < 8 )
break;
F_16 ( V_9 , V_74 , V_1 , V_15 + 4 , 4 , V_72 ) ;
break;
case 2 :
if ( V_14 < 20 )
break;
F_16 ( V_9 , V_75 , V_1 , V_15 + 4 , 16 , V_44 ) ;
break;
}
break;
case V_76 :
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_77 , V_1 , V_15 , 4 , V_72 ) ;
F_16 ( V_9 , V_78 , V_1 , V_15 , 4 , V_72 ) ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
if ( V_14 < 1 )
break;
F_16 ( V_9 , V_84 , V_1 , V_15 , V_14 , V_44 ) ;
break;
case V_85 :
if ( V_14 < 3 )
break;
F_16 ( V_9 , V_86 , V_1 , V_15 + 2 , 1 , V_72 ) ;
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_87 , V_1 , V_15 + 3 , 1 , V_72 ) ;
if ( V_14 < 5 )
break;
F_16 ( V_9 , V_88 , V_1 , V_15 + 4 , ( V_14 - 4 ) , V_89 | V_44 ) ;
break;
case V_90 :
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_91 , V_1 , V_15 , 4 , V_72 ) ;
break;
case V_92 :
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_93 , V_1 , V_15 , 4 , V_72 ) ;
break;
case V_94 :
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_95 , V_1 , V_15 , 4 , V_72 ) ;
break;
case V_96 :
F_16 ( V_9 , V_97 , V_1 , V_15 , V_14 , V_44 ) ;
break;
case V_98 :
for ( V_17 = 0 ; V_17 < V_14 ; V_17 += 4 ) {
F_16 ( V_9 , V_99 , V_1 , V_15 + V_17 , 2 , V_72 ) ;
F_16 ( V_9 , V_99 , V_1 , V_15 + V_17 + 2 , 2 , V_72 ) ;
}
break;
case V_100 :
F_16 ( V_9 , V_101 , V_1 , V_15 , V_14 , V_89 | V_44 ) ;
break;
case V_102 :
if ( V_14 < 2 )
break;
F_16 ( V_9 , V_71 , V_1 , V_15 + 1 , 1 , V_72 ) ;
if ( V_14 < 4 )
break;
F_16 ( V_9 , V_103 , V_1 , V_15 + 2 , 2 , V_72 ) ;
V_5 = F_18 ( V_9 , V_73 , V_1 , V_15 + 2 , 2 ,
F_3 ( V_1 , V_15 + 2 ) ^
( V_43 >> 16 ) ) ;
F_19 ( V_5 ) ;
if ( V_14 < 8 )
break;
switch( F_25 ( V_1 , V_15 + 1 ) ) {
case 1 :
if ( V_14 < 8 )
break;
F_16 ( V_9 , V_104 , V_1 , V_15 + 4 , 4 , V_72 ) ;
V_5 = F_26 ( V_9 , V_74 , V_1 , V_15 + 4 , 4 ,
F_27 ( V_1 , V_15 + 4 ) ^ F_28 ( V_43 ) ) ;
F_19 ( V_5 ) ;
break;
case 2 :
if ( V_14 < 20 )
break;
F_16 ( V_9 , V_105 , V_1 , V_15 + 4 , 16 , V_44 ) ;
break;
}
break;
case V_106 :
if ( V_14 < 2 )
break;
F_16 ( V_9 , V_71 , V_1 , V_15 + 1 , 1 , V_72 ) ;
break;
case V_107 :
F_16 ( V_9 , V_108 , V_1 , V_15 , V_14 , V_89 | V_44 ) ;
break;
default:
break;
}
V_15 += V_14 ;
V_11 -= V_58 + V_14 ;
}
}
}
return F_2 ( V_1 ) ;
}
static T_14
F_29 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( F_1 ( V_1 , V_2 , V_3 , NULL ) == 0 )
return FALSE ;
return TRUE ;
}
void
F_30 ( void )
{
static T_15 V_109 [] = {
{ & V_53 ,
{ L_7 , L_8 , V_110 ,
V_111 , F_31 ( V_24 ) , 0x0 , NULL , V_112 }
} ,
{ & V_54 ,
{ L_9 , L_10 , V_110 ,
V_111 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_55 ,
{ L_11 , L_12 , V_113 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_56 ,
{ L_13 , L_14 , V_115 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_47 ,
{ L_15 , L_16 ,
V_116 , V_114 , NULL , 0x0 ,
L_17 , V_112 } } ,
{ & V_51 ,
{ L_18 , L_19 ,
V_116 , V_114 , NULL , 0x0 ,
L_20 , V_112 } } ,
{ & V_52 ,
{ L_21 , L_22 ,
V_117 , V_114 , NULL , 0x0 ,
L_23 , V_112 } } ,
{ & V_61 ,
{ L_24 , L_25 , V_110 ,
V_111 , F_31 ( V_59 ) , 0x0 , NULL , V_112 }
} ,
{ & V_62 ,
{ L_26 , L_27 , V_110 ,
V_118 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_84 ,
{ L_28 , L_29 , V_113 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_71 ,
{ L_30 , L_31 , V_110 ,
V_111 , F_31 ( V_119 ) , 0x0 , NULL , V_112 }
} ,
{ & V_74 ,
{ L_32 , L_33 , V_120 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_75 ,
{ L_32 , L_34 , V_121 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_73 ,
{ L_35 , L_36 , V_110 ,
V_118 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_77 ,
{ L_37 , L_38 , V_122 ,
16 , F_32 ( & V_123 ) , 0x0004 , NULL , V_112 }
} ,
{ & V_78 ,
{ L_39 , L_40 , V_122 ,
16 , F_32 ( & V_123 ) , 0x0002 , NULL , V_112 }
} ,
{ & V_99 ,
{ L_41 , L_42 , V_110 ,
V_111 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_86 ,
{ L_43 , L_44 , V_124 ,
V_118 , NULL , 0x07 , NULL , V_112 }
} ,
{ & V_87 ,
{ L_45 , L_46 , V_124 ,
V_118 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_88 ,
{ L_47 , L_48 , V_125 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_104 ,
{ L_49 , L_50 , V_120 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_105 ,
{ L_49 , L_51 , V_121 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_103 ,
{ L_52 , L_53 , V_110 ,
V_118 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_101 ,
{ L_54 , L_55 , V_125 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_91 ,
{ L_56 , L_57 , V_126 ,
V_118 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_93 ,
{ L_58 , L_59 , V_126 ,
V_111 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_95 ,
{ L_60 , L_61 , V_126 ,
V_118 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_97 ,
{ L_62 , L_63 , V_113 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
{ & V_108 ,
{ L_64 , L_65 , V_125 ,
V_114 , NULL , 0x0 , NULL , V_112 }
} ,
} ;
static T_16 * V_127 [] = {
& V_45 ,
& V_57 ,
& V_60 ,
} ;
V_27 = F_33 ( L_66 ,
L_67 , L_68 ) ;
F_34 ( V_27 , V_109 , F_35 ( V_109 ) ) ;
F_36 ( V_127 , F_35 ( V_127 ) ) ;
F_37 ( L_68 , F_1 , V_27 ) ;
F_37 ( L_69 , F_29 , V_27 ) ;
}
void
F_38 ( void )
{
#if 0
dissector_handle_t classicstun_handle;
classicstun_handle = find_dissector("classicstun");
dissector_add_uint("tcp.port", TCP_PORT_STUN, classicstun_handle);
dissector_add_uint("udp.port", UDP_PORT_STUN, classicstun_handle);
#endif
F_39 ( L_70 , F_29 , V_27 ) ;
F_39 ( L_71 , F_29 , V_27 ) ;
}
