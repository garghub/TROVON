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
T_6 V_14 , V_15 ;
T_7 V_16 ;
T_6 V_17 ;
T_8 V_18 ;
T_8 V_19 ;
T_9 * V_20 ;
T_10 * V_21 ;
T_11 * V_22 ;
T_12 V_23 [ 2 ] ;
T_7 V_24 [ 4 ] ;
V_18 = F_2 ( V_1 ) ;
if ( V_18 < V_25 )
return 0 ;
V_10 = F_3 ( V_1 , 0 ) ;
if ( V_10 & 0xC000 || F_4 ( V_1 , 4 ) == 0x2112a442
|| F_4 ( V_1 , 4 ) == 0x7f5a9bc7 )
return 0 ;
V_12 = F_5 ( V_10 , V_26 ) ;
if ( V_12 == NULL )
return 0 ;
V_11 = F_3 ( V_1 , 2 ) ;
if ( V_18 != V_25 + V_11 )
return 0 ;
V_24 [ 0 ] = F_4 ( V_1 , 4 ) ;
V_24 [ 1 ] = F_4 ( V_1 , 8 ) ;
V_24 [ 2 ] = F_4 ( V_1 , 12 ) ;
V_24 [ 3 ] = F_4 ( V_1 , 16 ) ;
V_23 [ 0 ] . V_27 = 4 ;
V_23 [ 0 ] . V_28 = V_24 ;
V_23 [ 1 ] . V_27 = 0 ;
V_23 [ 1 ] . V_28 = NULL ;
V_20 = F_6 ( V_2 ) ;
V_21 = ( T_10 * ) F_7 ( V_20 , V_29 ) ;
if ( ! V_21 ) {
V_21 = F_8 ( F_9 () , T_10 ) ;
V_21 -> V_30 = F_10 ( F_9 () ) ;
F_11 ( V_20 , V_29 , V_21 ) ;
}
if( ! V_2 -> V_31 -> V_32 . V_33 ) {
if ( ( ( V_10 & V_34 ) >> 4 ) == V_35 ) {
V_22 = F_8 ( F_9 () , T_11 ) ;
V_22 -> V_36 = V_2 -> V_37 ;
V_22 -> V_38 = 0 ;
V_22 -> V_39 = V_2 -> V_40 ;
F_12 ( V_21 -> V_30 , V_23 ,
( void * ) V_22 ) ;
} else {
V_22 = ( T_11 * ) F_13 ( V_21 -> V_30 ,
V_23 ) ;
if( V_22 ) {
V_22 -> V_38 = V_2 -> V_37 ;
}
}
} else {
V_22 = ( T_11 * ) F_13 ( V_21 -> V_30 , V_23 ) ;
}
if( ! V_22 ) {
V_22 = F_8 ( F_14 () , T_11 ) ;
V_22 -> V_36 = 0 ;
V_22 -> V_38 = 0 ;
V_22 -> V_39 = V_2 -> V_40 ;
}
F_15 ( V_2 -> V_41 , V_42 , L_1 ) ;
F_16 ( V_2 -> V_41 , V_43 , L_2 ,
V_12 ) ;
if ( V_3 ) {
T_8 V_44 ;
V_5 = F_17 ( V_3 , V_29 , V_1 , 0 , - 1 , V_45 ) ;
V_7 = F_18 ( V_5 , V_46 ) ;
if ( ( ( V_10 & V_34 ) >> 4 ) == V_35 ) {
if ( V_22 -> V_38 ) {
T_5 * V_47 ;
V_47 = F_19 ( V_7 , V_48 ,
V_1 , 0 , 0 ,
V_22 -> V_38 ) ;
F_20 ( V_47 ) ;
}
}
else if ( ( ( ( V_10 & V_34 ) >> 4 ) == V_49 ) ||
( ( ( V_10 & V_34 ) >> 4 ) == V_50 ) ) {
if( V_22 -> V_36 ) {
T_5 * V_47 ;
T_13 V_51 ;
V_47 = F_19 ( V_7 , V_52 , V_1 , 0 , 0 , V_22 -> V_36 ) ;
F_20 ( V_47 ) ;
F_21 ( & V_51 , & V_2 -> V_40 , & V_22 -> V_39 ) ;
V_47 = F_22 ( V_7 , V_53 , V_1 , 0 , 0 , & V_51 ) ;
F_20 ( V_47 ) ;
}
}
F_19 ( V_7 , V_54 , V_1 , 0 , 2 , V_10 ) ;
F_19 ( V_7 , V_55 , V_1 , 2 , 2 , V_11 ) ;
F_17 ( V_7 , V_56 , V_1 , 4 , 16 , V_45 ) ;
V_44 = F_4 ( V_1 , 4 ) ;
if ( V_11 > 0 ) {
V_6 = F_17 ( V_7 , V_57 , V_1 , V_25 , V_11 , V_45 ) ;
V_8 = F_18 ( V_6 , V_58 ) ;
V_17 = V_25 ;
while( V_11 > 0 ) {
V_13 = F_3 ( V_1 , V_17 ) ;
V_14 = F_3 ( V_1 , V_17 + 2 ) ;
V_9 = F_23 ( V_8 , V_1 , V_17 ,
V_59 + V_14 , V_60 , NULL ,
L_3 ,
F_24 ( V_13 , V_61 , L_4 ) ) ;
F_19 ( V_9 , V_62 , V_1 ,
V_17 , 2 , V_13 ) ;
V_17 += 2 ;
if ( V_59 + V_14 > V_11 ) {
F_25 ( V_9 ,
V_63 , V_1 , V_17 , 2 ,
V_14 ,
L_5 ,
V_14 ) ;
break;
}
F_19 ( V_9 , V_63 , V_1 ,
V_17 , 2 , V_14 ) ;
V_17 += 2 ;
switch( V_13 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
if ( V_14 < 2 )
break;
F_17 ( V_9 , V_72 , V_1 , V_17 + 1 , 1 , V_73 ) ;
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_74 , V_1 , V_17 + 2 , 2 , V_73 ) ;
switch( F_26 ( V_1 , V_17 + 1 ) ) {
case 1 :
if ( V_14 < 8 )
break;
F_17 ( V_9 , V_75 , V_1 , V_17 + 4 , 4 , V_73 ) ;
break;
case 2 :
if ( V_14 < 20 )
break;
F_17 ( V_9 , V_76 , V_1 , V_17 + 4 , 16 , V_45 ) ;
break;
}
break;
case V_77 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_78 , V_1 , V_17 , 4 , V_73 ) ;
F_17 ( V_9 , V_79 , V_1 , V_17 , 4 , V_73 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( V_14 < 1 )
break;
F_17 ( V_9 , V_85 , V_1 , V_17 , V_14 , V_45 ) ;
break;
case V_86 :
if ( V_14 < 3 )
break;
F_17 ( V_9 , V_87 , V_1 , V_17 + 2 , 1 , V_73 ) ;
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_88 , V_1 , V_17 + 3 , 1 , V_73 ) ;
if ( V_14 < 5 )
break;
F_17 ( V_9 , V_89 , V_1 , V_17 + 4 , ( V_14 - 4 ) , V_90 | V_45 ) ;
break;
case V_91 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_92 , V_1 , V_17 , 4 , V_73 ) ;
break;
case V_93 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_94 , V_1 , V_17 , 4 , V_73 ) ;
break;
case V_95 :
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_96 , V_1 , V_17 , 4 , V_73 ) ;
break;
case V_97 :
F_17 ( V_9 , V_98 , V_1 , V_17 , V_14 , V_45 ) ;
break;
case V_99 :
for ( V_19 = 0 ; V_19 < V_14 ; V_19 += 4 ) {
F_17 ( V_9 , V_100 , V_1 , V_17 + V_19 , 2 , V_73 ) ;
F_17 ( V_9 , V_100 , V_1 , V_17 + V_19 + 2 , 2 , V_73 ) ;
}
break;
case V_101 :
F_17 ( V_9 , V_102 , V_1 , V_17 , V_14 , V_90 | V_45 ) ;
break;
case V_103 :
if ( V_14 < 2 )
break;
F_17 ( V_9 , V_72 , V_1 , V_17 + 1 , 1 , V_73 ) ;
if ( V_14 < 4 )
break;
F_17 ( V_9 , V_104 , V_1 , V_17 + 2 , 2 , V_73 ) ;
V_15 = F_3 ( V_1 , V_17 + 2 ) ^ ( V_44 >> 16 ) ;
V_5 = F_19 ( V_9 , V_74 , V_1 , V_17 + 2 , 2 , V_15 ) ;
F_20 ( V_5 ) ;
switch( F_26 ( V_1 , V_17 + 1 ) ) {
case 1 :
if ( V_14 < 8 )
break;
F_17 ( V_9 , V_105 , V_1 , V_17 + 4 , 4 , V_73 ) ;
V_16 = F_27 ( V_1 , V_17 + 4 ) ^ F_28 ( V_44 ) ;
V_5 = F_29 ( V_9 , V_75 , V_1 , V_17 + 4 , 4 , V_16 ) ;
F_20 ( V_5 ) ;
break;
case 2 :
if ( V_14 < 20 )
break;
F_17 ( V_9 , V_106 , V_1 , V_17 + 4 , 16 , V_45 ) ;
break;
}
break;
case V_107 :
if ( V_14 < 2 )
break;
F_17 ( V_9 , V_72 , V_1 , V_17 + 1 , 1 , V_73 ) ;
break;
case V_108 :
F_17 ( V_9 , V_109 , V_1 , V_17 , V_14 , V_90 | V_45 ) ;
break;
default:
break;
}
V_17 += V_14 ;
V_11 -= V_59 + V_14 ;
}
}
}
return F_30 ( V_1 ) ;
}
static T_14
F_31 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( F_1 ( V_1 , V_2 , V_3 , NULL ) == 0 )
return FALSE ;
return TRUE ;
}
void
F_32 ( void )
{
static T_15 V_110 [] = {
{ & V_54 ,
{ L_6 , L_7 , V_111 ,
V_112 , F_33 ( V_26 ) , 0x0 , NULL , V_113 }
} ,
{ & V_55 ,
{ L_8 , L_9 , V_111 ,
V_112 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_56 ,
{ L_10 , L_11 , V_114 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_57 ,
{ L_12 , L_13 , V_116 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_48 ,
{ L_14 , L_15 ,
V_117 , V_115 , NULL , 0x0 ,
L_16 , V_113 } } ,
{ & V_52 ,
{ L_17 , L_18 ,
V_117 , V_115 , NULL , 0x0 ,
L_19 , V_113 } } ,
{ & V_53 ,
{ L_20 , L_21 ,
V_118 , V_115 , NULL , 0x0 ,
L_22 , V_113 } } ,
{ & V_62 ,
{ L_23 , L_24 , V_111 ,
V_112 , F_33 ( V_61 ) , 0x0 , NULL , V_113 }
} ,
{ & V_63 ,
{ L_25 , L_26 , V_111 ,
V_119 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_85 ,
{ L_27 , L_28 , V_114 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_72 ,
{ L_29 , L_30 , V_111 ,
V_112 , F_33 ( V_120 ) , 0x0 , NULL , V_113 }
} ,
{ & V_75 ,
{ L_31 , L_32 , V_121 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_76 ,
{ L_31 , L_33 , V_122 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_74 ,
{ L_34 , L_35 , V_111 ,
V_119 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_78 ,
{ L_36 , L_37 , V_123 ,
16 , F_34 ( & V_124 ) , 0x0004 , NULL , V_113 }
} ,
{ & V_79 ,
{ L_38 , L_39 , V_123 ,
16 , F_34 ( & V_124 ) , 0x0002 , NULL , V_113 }
} ,
{ & V_100 ,
{ L_40 , L_41 , V_111 ,
V_112 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_87 ,
{ L_42 , L_43 , V_125 ,
V_119 , NULL , 0x07 , NULL , V_113 }
} ,
{ & V_88 ,
{ L_44 , L_45 , V_125 ,
V_119 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_89 ,
{ L_46 , L_47 , V_126 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_105 ,
{ L_48 , L_49 , V_121 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_106 ,
{ L_48 , L_50 , V_122 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_104 ,
{ L_51 , L_52 , V_111 ,
V_119 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_102 ,
{ L_53 , L_54 , V_126 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_92 ,
{ L_55 , L_56 , V_127 ,
V_119 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_94 ,
{ L_57 , L_58 , V_127 ,
V_112 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_96 ,
{ L_59 , L_60 , V_127 ,
V_119 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_98 ,
{ L_61 , L_62 , V_114 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
{ & V_109 ,
{ L_63 , L_64 , V_126 ,
V_115 , NULL , 0x0 , NULL , V_113 }
} ,
} ;
static T_16 * V_128 [] = {
& V_46 ,
& V_58 ,
& V_60 ,
} ;
V_29 = F_35 ( L_65 ,
L_66 , L_67 ) ;
F_36 ( V_29 , V_110 , F_37 ( V_110 ) ) ;
F_38 ( V_128 , F_37 ( V_128 ) ) ;
F_39 ( L_67 , F_1 , V_29 ) ;
F_39 ( L_68 , F_31 , V_29 ) ;
}
void
F_40 ( void )
{
#if 0
dissector_handle_t classicstun_handle;
classicstun_handle = find_dissector("classicstun");
dissector_add_uint_with_preference("tcp.port", TCP_PORT_STUN, classicstun_handle);
dissector_add_uint_with_preference("udp.port", UDP_PORT_STUN, classicstun_handle);
#endif
F_41 ( L_69 , F_31 , L_70 , L_71 , V_29 , V_129 ) ;
F_41 ( L_72 , F_31 , L_73 , L_74 , V_29 , V_129 ) ;
}
