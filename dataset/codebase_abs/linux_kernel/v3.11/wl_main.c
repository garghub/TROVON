int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 = V_5 ;
int V_6 ;
unsigned long V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( L_1 ) ;
F_4 ( V_10 ) ;
memset ( & ( V_9 -> V_11 ) , 0 , sizeof( V_12 ) ) ;
F_5 ( & ( V_9 -> V_13 ) ) ;
V_9 -> V_14 = V_15 ;
V_9 -> V_16 = V_17 ;
V_9 -> V_2 = V_2 ;
F_6 ( V_10 , L_2 , L_3 , V_18 & 0x0FFFF ) ;
F_6 ( V_10 , L_4 , L_5 ,
V_19 [ 0 ] & 0x0FF , V_19 [ 1 ] & 0x0FF ,
V_19 [ 2 ] & 0x0FF , V_19 [ 3 ] & 0x0FF ) ;
F_6 ( V_10 , V_20 , L_6 , V_21 ) ;
F_6 ( V_10 , V_22 , L_6 , V_23 ) ;
F_6 ( V_10 , V_24 , L_7 , V_25 ) ;
F_6 ( V_10 , V_26 , L_7 , V_27 ) ;
F_6 ( V_10 , V_28 , L_7 , V_29 ) ;
F_6 ( V_10 , V_30 , L_7 , V_31 ) ;
F_6 ( V_10 , V_32 , L_6 , V_33 ) ;
F_6 ( V_10 , V_34 , L_6 , V_35 ) ;
F_6 ( V_10 , V_36 , L_6 , V_37 ) ;
F_6 ( V_10 , V_38 , L_6 , V_39 ) ;
F_6 ( V_10 , V_40 , L_6 , V_41 ) ;
F_6 ( V_10 , V_42 , L_6 , V_43 ) ;
F_6 ( V_10 , V_44 , L_7 , V_45 ) ;
F_6 ( V_10 , V_46 , L_7 , V_47 ) ;
F_6 ( V_10 , V_48 , L_6 , V_49 ) ;
F_6 ( V_10 , V_50 , L_7 , V_51 ) ;
F_6 ( V_10 , V_52 , L_8 , V_53 ) ;
#if 1
F_6 ( V_10 , V_54 , L_7 , V_55 ) ;
F_6 ( V_10 , V_56 , L_6 , V_57 ) ;
F_6 ( V_10 , V_58 , L_6 , V_59 ) ;
F_6 ( V_10 , V_60 , L_6 , V_61 ) ;
F_6 ( V_10 , V_62 , L_6 , V_63 ) ;
#ifdef F_7
F_6 ( V_10 , V_64 , L_7 , V_65 ) ;
F_6 ( V_10 , V_66 , L_7 , V_67 ) ;
F_6 ( V_10 , V_68 , L_7 , V_69 ) ;
F_6 ( V_10 , V_70 , L_7 , V_71 ) ;
F_6 ( V_10 , V_72 , L_7 , V_73 ) ;
F_6 ( V_10 , V_74 , L_7 , V_75 ) ;
F_6 ( V_10 , V_76 , L_7 , V_77 ) ;
F_6 ( V_10 , V_78 , L_7 , V_79 ) ;
F_6 ( V_10 , V_80 , L_7 , V_81 ) ;
F_6 ( V_10 , V_82 , L_7 , V_83 ) ;
F_6 ( V_10 , V_84 , L_7 , V_85 ) ;
F_6 ( V_10 , V_86 , L_7 , V_87 ) ;
F_6 ( V_10 , V_88 , L_9 ,
V_89 ) ;
F_6 ( V_10 , V_90 , L_9 ,
V_91 ) ;
F_6 ( V_10 , V_92 , L_9 ,
V_93 ) ;
F_6 ( V_10 , V_94 , L_9 ,
V_95 ) ;
F_6 ( V_10 , V_96 , L_9 ,
V_97 ) ;
F_6 ( V_10 , V_98 , L_9 ,
V_99 ) ;
#endif
#endif
F_8 ( ! V_21 || ( strlen ( V_21 ) <= V_100 ) ) ;
F_8 ( ! V_23 || ( strlen ( V_23 ) <= V_100 ) ) ;
F_8 ( ( V_25 <= V_101 ) ) ;
F_8 ( ( V_27 >= V_102 ) && ( V_27 <= V_103 ) ) ;
F_8 ( ( V_29 >= V_104 ) && ( V_29 <= V_105 ) ) ;
F_8 ( ( V_31 <= V_106 ) ) ;
F_8 ( ! V_33 || strchr ( L_10 , V_33 [ 0 ] ) != NULL ) ;
F_8 ( ! V_35 || ( strlen ( V_34 ) <= V_100 ) ) ;
F_8 ( ( V_107 <= V_108 ) ) ;
F_8 ( F_9 ( V_37 ) ) ;
F_8 ( F_9 ( V_39 ) ) ;
F_8 ( F_9 ( V_41 ) ) ;
F_8 ( F_9 ( V_43 ) ) ;
F_8 ( ( V_45 >= V_109 ) && ( V_45 <= V_110 ) ) ;
F_8 ( ( V_47 >= V_111 ) &&
( V_47 <= V_112 ) ) ;
F_8 ( ! V_49 || ( strlen ( V_49 ) <= 255 ) ) ;
F_8 ( ( V_51 < V_113 ) ) ;
F_8 ( ! V_114 || strchr ( L_10 , V_114 [ 0 ] ) != NULL ) ;
F_8 ( ! V_115 || strchr ( L_10 , V_115 [ 0 ] ) != NULL ) ;
F_8 ( ( V_116 <= V_117 ) ) ;
F_8 ( ( V_118 >= V_119 ) && ( V_118 <= V_120 ) ) ;
F_8 ( V_53 <= V_121 ||
( V_53 & 0x7FFF ) <= V_121 ) ;
F_8 ( ! V_122 || strchr ( L_10 , V_122 [ 0 ] ) != NULL ) ;
F_8 ( ! V_123 || strchr ( L_10 , V_123 [ 0 ] ) != NULL ) ;
F_8 ( ( V_124 <= V_125 ) ) ;
F_8 ( ( V_126 <= V_127 ) ) ;
F_8 ( ( V_128 <= V_129 ) ) ;
F_8 ( ( V_130 <= V_131 ) ) ;
F_8 ( ! V_132 || strchr ( L_10 , V_132 [ 0 ] ) != NULL ) ;
F_8 ( ( V_133 <= V_134 ) ) ;
F_8 ( ( V_55 >= V_135 ) ) ;
F_8 ( ! V_57 || strchr ( L_10 , V_57 [ 0 ] ) != NULL ) ;
F_8 ( ! V_59 || strchr ( L_10 , V_59 [ 0 ] ) != NULL ) ;
F_8 ( ! V_61 || strchr ( L_10 , V_61 [ 0 ] ) != NULL ) ;
F_8 ( ! V_63 || strchr ( L_10 , V_63 [ 0 ] ) != NULL ) ;
#ifdef F_7
F_8 ( ( V_65 <= V_106 ) ) ;
F_8 ( ( V_67 <= V_106 ) ) ;
F_8 ( ( V_69 <= V_106 ) ) ;
F_8 ( ( V_71 <= V_106 ) ) ;
F_8 ( ( V_73 <= V_106 ) ) ;
F_8 ( ( V_75 <= V_106 ) ) ;
F_8 ( ( V_77 >= V_104 ) && ( V_77 <= V_105 ) ) ;
F_8 ( ( V_79 >= V_104 ) && ( V_79 <= V_105 ) ) ;
F_8 ( ( V_81 >= V_104 ) && ( V_81 <= V_105 ) ) ;
F_8 ( ( V_83 >= V_104 ) && ( V_83 <= V_105 ) ) ;
F_8 ( ( V_85 >= V_104 ) && ( V_85 <= V_105 ) ) ;
F_8 ( ( V_87 >= V_104 ) && ( V_87 <= V_105 ) ) ;
#endif
F_8 ( ( V_136 >= V_137 ) && ( V_136 <= V_138 ) ) ;
F_8 ( ( V_139 <= V_139 ) ) ;
V_9 -> V_140 = V_25 ;
V_9 -> V_141 = V_27 ;
V_9 -> V_142 [ 0 ] = V_143 ;
V_9 -> V_142 [ 1 ] = V_144 ;
V_9 -> V_145 = V_31 ;
V_9 -> V_146 [ 0 ] = V_147 ;
V_9 -> V_146 [ 1 ] = V_148 ;
if ( strchr ( L_11 , V_33 [ 0 ] ) != NULL ) {
V_9 -> V_149 = 1 ;
} else {
V_9 -> V_149 = 0 ;
}
if ( V_21 && ( strlen ( V_21 ) <= V_150 ) ) {
strcpy ( V_9 -> V_151 , V_21 ) ;
}
if ( V_23 && ( strlen ( V_23 ) <= V_150 ) ) {
strcpy ( V_9 -> V_151 , V_23 ) ;
}
if ( V_35 && ( strlen ( V_35 ) <= V_150 ) ) {
strcpy ( V_9 -> V_152 , V_35 ) ;
}
V_9 -> V_153 = V_107 ;
if ( V_37 && ( strlen ( V_37 ) <= V_154 ) ) {
strcpy ( V_9 -> V_155 , V_37 ) ;
}
if ( V_39 && ( strlen ( V_39 ) <= V_154 ) ) {
strcpy ( V_9 -> V_156 , V_39 ) ;
}
if ( V_41 && ( strlen ( V_41 ) <= V_154 ) ) {
strcpy ( V_9 -> V_157 , V_41 ) ;
}
if ( V_43 && ( strlen ( V_43 ) <= V_154 ) ) {
strcpy ( V_9 -> V_158 , V_43 ) ;
}
V_9 -> V_159 = V_45 ;
F_10 ( V_9 -> V_155 , & ( V_9 -> V_160 . V_161 [ 0 ] ) ) ;
F_10 ( V_9 -> V_156 , & ( V_9 -> V_160 . V_161 [ 1 ] ) ) ;
F_10 ( V_9 -> V_157 , & ( V_9 -> V_160 . V_161 [ 2 ] ) ) ;
F_10 ( V_9 -> V_158 , & ( V_9 -> V_160 . V_161 [ 3 ] ) ) ;
V_9 -> V_162 = 1 ;
V_9 -> V_163 = V_51 ;
if ( strchr ( L_11 , V_114 [ 0 ] ) != NULL ) {
V_9 -> V_164 = 1 ;
} else {
V_9 -> V_164 = 0 ;
}
if ( strchr ( L_11 , V_115 [ 0 ] ) != NULL ) {
V_9 -> V_165 = 1 ;
} else {
V_9 -> V_165 = 0 ;
}
V_9 -> V_166 = V_116 ;
V_9 -> V_167 [ 0 ] = V_168 ;
V_9 -> V_167 [ 1 ] = V_169 ;
V_9 -> V_170 [ 0 ] = V_171 ;
V_9 -> V_170 [ 1 ] = V_172 ;
#if 1
V_9 -> V_173 = V_118 ;
V_9 -> V_174 = V_124 ;
V_9 -> V_175 = V_126 ;
V_9 -> V_176 = V_128 ;
V_9 -> V_177 = V_130 ;
V_9 -> V_178 = V_53 ;
if ( strchr ( L_11 , V_122 [ 0 ] ) != NULL ) {
V_9 -> V_179 = 1 ;
} else {
V_9 -> V_179 = 0 ;
}
if ( strchr ( L_12 , V_123 [ 0 ] ) != NULL ) {
V_9 -> V_180 = 0 ;
} else {
V_9 -> V_180 = 1 ;
}
if ( strchr ( L_11 , V_132 [ 0 ] ) != NULL ) {
V_9 -> V_181 = 1 ;
} else {
V_9 -> V_181 = 0 ;
}
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_183 [ V_6 ] = V_184 [ V_6 ] ;
}
V_9 -> V_185 = V_133 ;
#endif
#if 1
V_9 -> V_186 = V_55 ;
if ( strchr ( L_11 , V_57 [ 0 ] ) != NULL ) {
V_9 -> V_187 = 1 ;
} else {
V_9 -> V_187 = 0 ;
}
if ( strchr ( L_12 , V_59 [ 0 ] ) != NULL ) {
V_9 -> V_188 = 0 ;
} else {
V_9 -> V_188 = 1 ;
}
if ( strchr ( L_11 , V_61 [ 0 ] ) != NULL ) {
V_9 -> V_189 = 1 ;
} else {
V_9 -> V_189 = 0 ;
}
if ( strchr ( L_11 , V_63 [ 0 ] ) != NULL ) {
V_9 -> V_190 = 1 ;
} else {
V_9 -> V_190 = 0 ;
}
V_9 -> V_191 = V_136 ;
V_9 -> V_192 = V_139 ;
#ifdef F_7
V_9 -> V_193 [ 0 ] . V_194 = V_65 ;
V_9 -> V_193 [ 1 ] . V_194 = V_67 ;
V_9 -> V_193 [ 2 ] . V_194 = V_69 ;
V_9 -> V_193 [ 3 ] . V_194 = V_71 ;
V_9 -> V_193 [ 4 ] . V_194 = V_73 ;
V_9 -> V_193 [ 5 ] . V_194 = V_75 ;
V_9 -> V_193 [ 0 ] . V_195 = V_77 ;
V_9 -> V_193 [ 1 ] . V_195 = V_79 ;
V_9 -> V_193 [ 2 ] . V_195 = V_81 ;
V_9 -> V_193 [ 3 ] . V_195 = V_83 ;
V_9 -> V_193 [ 4 ] . V_195 = V_85 ;
V_9 -> V_193 [ 5 ] . V_195 = V_87 ;
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_193 [ 0 ] . V_196 [ V_6 ] = V_89 [ V_6 ] ;
}
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_193 [ 1 ] . V_196 [ V_6 ] = V_91 [ V_6 ] ;
}
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_193 [ 2 ] . V_196 [ V_6 ] = V_93 [ V_6 ] ;
}
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_193 [ 3 ] . V_196 [ V_6 ] = V_95 [ V_6 ] ;
}
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_193 [ 4 ] . V_196 [ V_6 ] = V_97 [ V_6 ] ;
}
for( V_6 = 0 ; V_6 < V_182 ; V_6 ++ ) {
V_9 -> V_193 [ 5 ] . V_196 [ V_6 ] = V_99 [ V_6 ] ;
}
#endif
#endif
#ifdef F_11
if ( strchr ( L_11 , V_197 [ 0 ] ) != NULL ) {
V_9 -> V_197 = 1 ;
} else {
V_9 -> V_197 = 0 ;
}
#endif
F_12 ( V_9 , & V_7 ) ;
V_9 -> V_198 = V_199 ;
memset ( & ( V_9 -> V_200 ) , 0 , sizeof( V_9 -> V_200 ) ) ;
V_9 -> V_200 . V_201 = FALSE ;
memset ( & ( V_9 -> V_202 ) , 0 , sizeof( V_9 -> V_202 ) ) ;
V_9 -> V_202 . V_201 = FALSE ;
V_9 -> V_203 = 0 ;
memset ( V_9 -> V_204 , 0 , sizeof( V_9 -> V_204 ) ) ;
F_13 ( & ( V_9 -> V_205 ) ) ;
V_9 -> V_206 . V_207 = NULL ;
V_9 -> V_206 . V_208 = 0 ;
for( V_6 = 0 ; V_6 < V_209 ; V_6 ++ ) {
F_14 ( & ( V_9 -> V_204 [ V_6 ] . V_210 ) , & ( V_9 -> V_205 ) ) ;
}
for( V_6 = 0 ; V_6 < V_211 ; V_6 ++ ) {
F_13 ( & ( V_9 -> V_212 [ V_6 ] ) ) ;
}
V_9 -> V_213 = TRUE ;
V_9 -> V_214 = 0 ;
#ifdef F_15
#ifdef F_16
F_17 ( V_10 , L_13 ) ;
V_9 -> V_215 = 1 ;
#else
F_17 ( V_10 , L_14 ) ;
V_9 -> V_215 = 0 ;
#endif
#endif
F_18 ( & V_9 -> V_216 , V_217 , ( unsigned long ) V_9 ) ;
F_17 ( V_10 , L_15 ) ;
V_4 = F_19 ( & V_9 -> V_11 , V_2 -> V_218 ) ;
if ( V_4 != V_5 && V_4 != V_219 ) {
F_20 ( V_10 , L_16 , V_4 ) ;
F_21 ( V_9 , & V_7 ) ;
goto V_220;
}
V_9 -> V_221 . V_222 = V_2 -> V_218 ;
V_9 -> V_221 . V_223 = V_224 ;
V_9 -> V_221 . V_225 = V_2 -> V_226 ;
V_9 -> V_221 . V_227 = V_9 -> V_11 . V_228 ;
V_9 -> V_229 . V_230 = ( sizeof( V_9 -> V_229 ) / sizeof( V_231 ) ) - 1 ;
V_9 -> V_229 . V_232 = V_233 ;
V_9 -> V_229 . V_234 = V_235 ;
V_9 -> V_229 . V_236 = V_237 ;
V_9 -> V_229 . V_238 = V_239 ;
V_9 -> V_229 . V_240 = V_241 ;
F_17 ( V_10 , L_17 ) ;
V_4 = F_22 ( V_9 ) ;
if ( V_4 != V_5 ) {
F_20 ( V_10 , L_18 ) ;
F_21 ( V_9 , & V_7 ) ;
goto V_220;
}
F_23 ( V_9 ) ;
#if 0
if ( wl_adapter_is_open( lp->dev )) {
DBG_TRACE( DbgInfo, "Enabling Port 0\n" );
hcf_status = wl_enable( lp );
if ( hcf_status != HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, "Enable port 0 failed: 0x%x\n", hcf_status );
}
#if ( V_242 ) & V_243
DBG_TRACE( DbgInfo, "Enabling WDS Ports\n" );
#endif
}
#endif
memcpy ( V_9 -> V_2 -> V_244 , V_9 -> V_183 , V_182 ) ;
V_2 -> V_245 = V_182 ;
V_9 -> V_246 = TRUE ;
#ifdef F_24
F_25 ( V_2 ) ;
#endif
F_26 ( V_9 ) ;
V_9 -> V_162 = V_247 ;
#ifdef F_11
if ( V_9 -> V_197 == 1 ) {
F_17 ( V_10 , L_19 ) ;
F_27 ( V_9 ) ;
V_9 -> V_14 = V_15 ;
F_28 ( V_9 ) ;
F_19 ( & V_9 -> V_11 , V_248 ) ;
}
#endif
F_21 ( V_9 , & V_7 ) ;
F_17 ( DbgInfo, L_20mac_address L_21%02X%cL_22wlagsL_23driver/wlags49L_24wl_insert() FAILED\nL_25wl_resetL_26devL_27%s (0x%p)L_28dev->base_addrL_27(%#03lx)L_29Device Base Address: %#03lx\nL_30hcf_connect() failed, status: 0x%x\nL_31wl_go() failed, status: 0x%x\nL_32Device Base Address INVALID!!!\nL_33wl_goL_34Disable port 0 failed: 0x%x\nL_35Disable port 0 succes : %d retries\nL_36Disable port 0 failed after: %d retries\nL_37Disabling WDS Ports\nL_38F/W image:%s:\nL_39No image file found\nL_40F/W image file found\nL_41error in vmalloc\nL_42buffer too small, %d\nL_43read O.K.: %d bytes %.12s\nL_44no more to read\nL_45file not read in one swoop or other errorL_46 , give up, too complicated, rc = %0X\nL_47still have to change code to get a real download now !!!!!!!!\nL_48before dhf_download_binary\nL_49after dhf_download_binary, before dhf_download_fw\nL_50after dhf_download_fw\nL_51Downloading STA firmware...\nL_52Firmware Download failed\nL_53downloaded station F/W\nL_54downloaded AP F/W\nL_55unknown F/W type\nL_56ComponentID:%04x variant:%04x major:%04x minor:%04x\nL_57Could not retrieve MAC address\nL_58Card MAC Address: %pM\nL_59wl_set_wep_keysL_26lpL_27%s (0x%p)L_60Key 1 len: %d\nL_61Key 2 len: %d\nL_62Key 3 len: %d\nL_63Key 4 len: %d\nL_64encrypt: %d, ID: %d\nL_65set key: %s(%d) [%d]\nL_66wl_applyL_67lpL_27%s (0x%p)L_68Disconnect failed\nL_69Disable failed\nL_70wl_put_ltv() failed\nL_71wl_put_ltv_initL_72lp pointer is NULL\nL_73CFG_CNTL_OPT : 0x%04x\nL_74CFG_CNTL_OPT result : 0x%04x\nL_75CFG_REG_INFO_LOG\nL_76CFG_REG_INFO_LOG result : 0x%04x\nL_77wl_put_ltvL_78lp pointer is NULL\nL_79Create IBSSL_80CFG_CNF_OWN_NAME : %s\nL_81CFG_CNF_OWN_NAME : EMPTY\nL_82CFG_CNF_OWN_NAME result : 0x%04x\nL_83CFG_TX_RATE_CNTL 2.4GHz : 0x%04x\nL_84CFG_TX_RATE_CNTL 5.0GHz : 0x%04x\nL_85CFG_TX_RATE_CNTL result : 0x%04x\nL_86CFG_CNF_PM_ENABLED : 0x%04x\nL_87ANYL_88anyL_89CFG_DESIRED_SSID : %s\nL_90CFG_DESIRED_SSID : ANY\nL_91CFG_DESIRED_SSID result : 0x%04x\nL_92CFG_PROBE_DATA_RATE 2.4GHz : 0x%04x\nL_93CFG_PROBE_DATA_RATE 5.0GHz : 0x%04x\nL_94CFG_PROBE_DATA_RATE result : 0x%04x\nL_95MAC Address : %pM\nL_96CFG_NIC_MAC_ADDR\nL_97CFG_CNF_OWN_MAC_ADDR\nL_98CFG_XXX_MAC_ADDR result : 0x%04x\nL_99ANYL_100anyL_101CFG_CNF_OWN_SSID : %s\nL_102CFG_CNF_OWN_SSID : ANY\nL_103CFG_CNF_OWN_SSID result : 0x%04x\nL_104wl_module_initL_105standardL_106%s\nL_107*** Modified for kernel 2.6 by Henk de Groot <pe1dnn@amsat.org>\nL_108*** Based on 7.18 version by Andrey Borzenkov <arvidjaar@mail.ru> $Revision: 39 $\nL_109Access Point Mode (AP) Support: YES\nL_110Access Point Mode (AP) Support: NO\nL_111wl_module_exitL_112wlagsL_113EXITING ISR, IN RTS MODE...\nL_114NOT OUR INTERRUPT\nL_115wl_isr_handler lp adapter pointer is NULL!!!\nL_116wl_removeL_117devL_27%s (0x%p)L_118wl_suspendL_117devL_27%s (0x%p)L_119wl_resumeL_117devL_27%s (0x%p)L_120wl_releaseL_117devL_27%s (0x%p)L_121Calling unregister_netdev(), as it wasn't called yet\n" );
wl_remove( dev );
lp->is_registered = FALSE;
}
DBG_LEAVE( DbgInfo );
return;
} // wl_release
/*============================================================================*/
/*******************************************************************************
* wl_get_irq_mask()
*******************************************************************************
*
* DESCRIPTION:
*
* Accessor function to retrieve the irq_mask module parameter
*
* PARAMETERS:
*
* N/A
*
* RETURNS:
*
* The irq_mask module parameter
*
******************************************************************************/
p_u16 wl_get_irq_mask( void )
{
return irq_mask;
} // wl_get_irq_mask
/*============================================================================*/
/*******************************************************************************
* wl_get_irq_list()
*******************************************************************************
*
* DESCRIPTION:
*
* Accessor function to retrieve the irq_list module parameter
*
* PARAMETERS:
*
* N/A
*
* RETURNS:
*
* The irq_list module parameter
*
******************************************************************************/
p_s8 * wl_get_irq_list( void )
{
return irq_list;
} // wl_get_irq_list
/*============================================================================*/
/*******************************************************************************
* wl_enable()
*******************************************************************************
*
* DESCRIPTION:
*
* Used to enable MAC ports
*
* PARAMETERS:
*
* lp - pointer to the device's private adapter structure
*
* RETURNS:
*
* N/A
*
******************************************************************************/
int wl_enable( struct wl_private *lp )
{
int hcf_status = HCF_SUCCESS;
DBG_FUNC( L_122 );
DBG_ENTER( DbgInfo );
if ( lp->portState == WVLAN_PORT_STATE_ENABLED ) {
DBG_TRACE( DbgInfo, L_123 );
} else if ( lp->portState == WVLAN_PORT_STATE_CONNECTED ) {
DBG_TRACE( DbgInfo, L_124 );
} else {
hcf_status = hcf_cntl( &lp->hcfCtx, HCF_CNTL_ENABLE );
if ( hcf_status == HCF_SUCCESS ) {
lp->portState = WVLAN_PORT_STATE_ENABLED;
#ifdef F_16
if ( lp->use_dma ) {
wl_pci_dma_hcf_supply( lp );
}
#endif
}
}
if ( hcf_status != HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, L_125, hcf_status );
}
DBG_LEAVE( DbgInfo );
return hcf_status;
}
#ifdef F_7
void wl_enable_wds_ports( struct wl_private * lp )
{
DBG_FUNC( L_126 );
DBG_ENTER( DbgInfo );
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ){
DBG_ERROR( DbgInfo, L_127 );
}
DBG_LEAVE( DbgInfo );
return;
}
#endif
int wl_connect( struct wl_private *lp )
{
int hcf_status;
DBG_FUNC( L_128 );
DBG_ENTER( DbgInfo );
if ( lp->portState != WVLAN_PORT_STATE_ENABLED ) {
DBG_TRACE( DbgInfo, L_129 );
DBG_LEAVE( DbgInfo );
return HCF_SUCCESS;
}
hcf_status = hcf_cntl( &lp->hcfCtx, HCF_CNTL_CONNECT );
if ( hcf_status == HCF_SUCCESS ) {
lp->portState = WVLAN_PORT_STATE_CONNECTED;
}
DBG_LEAVE( DbgInfo );
return hcf_status;
}
int wl_disconnect( struct wl_private *lp )
{
int hcf_status;
DBG_FUNC( L_130 );
DBG_ENTER( DbgInfo );
if ( lp->portState != WVLAN_PORT_STATE_CONNECTED ) {
DBG_TRACE( DbgInfo, L_131 );
DBG_LEAVE( DbgInfo );
return HCF_SUCCESS;
}
hcf_status = hcf_cntl( &lp->hcfCtx, HCF_CNTL_DISCONNECT );
if ( hcf_status == HCF_SUCCESS ) {
lp->portState = WVLAN_PORT_STATE_ENABLED;
}
DBG_LEAVE( DbgInfo );
return hcf_status;
}
int wl_disable( struct wl_private *lp )
{
int hcf_status = HCF_SUCCESS;
DBG_FUNC( L_132 );
DBG_ENTER( DbgInfo );
if ( lp->portState == WVLAN_PORT_STATE_DISABLED ) {
DBG_TRACE( DbgInfo, L_133 );
} else {
hcf_status = hcf_cntl( &lp->hcfCtx, HCF_CNTL_DISABLE );
if ( hcf_status == HCF_SUCCESS ) {
lp->portState = WVLAN_PORT_STATE_DISABLED;
#ifdef F_16
if ( lp->use_dma ) {
wl_pci_dma_hcf_reclaim( lp );
}
#endif
}
}
if ( hcf_status != HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, L_125, hcf_status );
}
DBG_LEAVE( DbgInfo );
return hcf_status;
}
#ifdef F_7
void wl_disable_wds_ports( struct wl_private * lp )
{
DBG_FUNC( L_134 );
DBG_ENTER( DbgInfo );
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ){
DBG_ERROR( DbgInfo, L_127 );
}
DBG_LEAVE( DbgInfo );
return;
}
#endif
#ifndef F_29
int wl_mbx( struct wl_private *lp )
{
int hcf_status = HCF_SUCCESS;
DBG_FUNC( L_135 );
DBG_ENTER( DbgInfo );
DBG_TRACE( DbgInfo, L_136,
lp->hcfCtx.IFB_MBInfoLen );
memset( &( lp->ltvRecord ), 0, sizeof( ltv_t ));
lp->ltvRecord.len = MB_SIZE;
lp->ltvRecord.typ = CFG_MB_INFO;
hcf_status = hcf_get_info( &lp->hcfCtx, (LTVP)&( lp->ltvRecord ));
if ( hcf_status != HCF_SUCCESS ) {
DBG_ERROR( DbgInfo, L_137, hcf_status );
DBG_LEAVE( DbgInfo );
return hcf_status;
}
if ( lp->ltvRecord.typ == CFG_MB_INFO ) {
DBG_LEAVE( DbgInfo );
return hcf_status;
}
wl_endian_translate_mailbox( &( lp->ltvRecord ));
wl_process_mailbox( lp );
DBG_LEAVE( DbgInfo );
return hcf_status;
}
void wl_endian_translate_mailbox( ltv_t *ltv )
{
DBG_FUNC( L_138 );
DBG_ENTER( DbgInfo );
switch( ltv->typ ) {
case CFG_TALLIES:
break;
case CFG_SCAN:
{
int num_aps;
SCAN_RS_STRCT *aps = (SCAN_RS_STRCT *)&ltv->u.u8[0];
num_aps = (hcf_16)(( (size_t)(ltv->len - 1 ) * 2 ) /
( sizeof( SCAN_RS_STRCT )));
while( num_aps >= 1 ) {
num_aps--;
aps[num_aps].channel_id =
CNV_LITTLE_TO_INT( aps[num_aps].channel_id );
aps[num_aps].noise_level =
CNV_LITTLE_TO_INT( aps[num_aps].noise_level );
aps[num_aps].signal_level =
CNV_LITTLE_TO_INT( aps[num_aps].signal_level );
aps[num_aps].beacon_interval_time =
CNV_LITTLE_TO_INT( aps[num_aps].beacon_interval_time );
aps[num_aps].capability =
CNV_LITTLE_TO_INT( aps[num_aps].capability );
aps[num_aps].ssid_len =
CNV_LITTLE_TO_INT( aps[num_aps].ssid_len );
aps[num_aps].ssid_val[aps[num_aps].ssid_len] = 0;
}
}
break;
case CFG_ACS_SCAN:
{
PROBE_RESP *probe_resp = (PROBE_RESP *)ltv;
probe_resp->frameControl = CNV_LITTLE_TO_INT( probe_resp->frameControl );
probe_resp->durID = CNV_LITTLE_TO_INT( probe_resp->durID );
probe_resp->sequence = CNV_LITTLE_TO_INT( probe_resp->sequence );
probe_resp->dataLength = CNV_LITTLE_TO_INT( probe_resp->dataLength );
#ifndef F_15
probe_resp->lenType = CNV_LITTLE_TO_INT( probe_resp->lenType );
#endif
probe_resp->beaconInterval = CNV_LITTLE_TO_INT( probe_resp->beaconInterval );
probe_resp->capability = CNV_LITTLE_TO_INT( probe_resp->capability );
probe_resp->flags = CNV_LITTLE_TO_INT( probe_resp->flags );
}
break;
case CFG_LINK_STAT:
#define F_30 ((LINK_STATUS_STRCT *)ltv)
ls->linkStatus = CNV_LITTLE_TO_INT( ls->linkStatus );
break;
#undef F_30
case CFG_ASSOC_STAT:
{
ASSOC_STATUS_STRCT *as = (ASSOC_STATUS_STRCT *)ltv;
as->assocStatus = CNV_LITTLE_TO_INT( as->assocStatus );
}
break;
case CFG_SECURITY_STAT:
{
SECURITY_STATUS_STRCT *ss = (SECURITY_STATUS_STRCT *)ltv;
ss->securityStatus = CNV_LITTLE_TO_INT( ss->securityStatus );
ss->reason = CNV_LITTLE_TO_INT( ss->reason );
}
break;
case CFG_WMP:
break;
case CFG_NULL:
break;
default:
break;
}
DBG_LEAVE( DbgInfo );
return;
}
void wl_process_mailbox( struct wl_private *lp )
{
ltv_t *ltv;
hcf_16 ltv_val = 0xFFFF;
DBG_FUNC( L_139 );
DBG_ENTER( DbgInfo );
ltv = &( lp->ltvRecord );
switch( ltv->typ ) {
case CFG_TALLIES:
DBG_TRACE( DbgInfo, L_140 );
break;
case CFG_SCAN:
DBG_TRACE( DbgInfo, L_141 );
{
int num_aps;
SCAN_RS_STRCT *aps = (SCAN_RS_STRCT *)&ltv->u.u8[0];
num_aps = (hcf_16)(( (size_t)(ltv->len - 1 ) * 2 ) /
( sizeof( SCAN_RS_STRCT )));
lp->scan_results.num_aps = num_aps;
DBG_TRACE( DbgInfo, L_142, num_aps );
while( num_aps >= 1 ) {
num_aps--;
DBG_TRACE( DbgInfo, L_143, num_aps );
DBG_TRACE( DbgInfo, L_144 );
DBG_TRACE( DbgInfo, L_145,
aps[num_aps].channel_id );
DBG_TRACE( DbgInfo, L_146,
aps[num_aps].noise_level );
DBG_TRACE( DbgInfo, L_147,
aps[num_aps].signal_level );
DBG_TRACE( DbgInfo, L_148,
aps[num_aps].beacon_interval_time );
DBG_TRACE( DbgInfo, L_149,
aps[num_aps].capability );
DBG_TRACE( DbgInfo, L_150,
aps[num_aps].ssid_len );
DBG_TRACE(DbgInfo, L_151,
aps[num_aps].bssid);
if ( aps[num_aps].ssid_len != 0 ) {
DBG_TRACE( DbgInfo, L_152,
aps[num_aps].ssid_val );
} else {
DBG_TRACE( DbgInfo, L_152, L_153 );
}
DBG_TRACE( DbgInfo, L_154 );
memcpy( &( lp->scan_results.APTable[num_aps]), &( aps[num_aps] ),
sizeof( SCAN_RS_STRCT ));
}
lp->scan_results.scan_complete = TRUE;
}
break;
case CFG_ACS_SCAN:
DBG_TRACE( DbgInfo, L_155 );
{
PROBE_RESP *probe_rsp = (PROBE_RESP *)ltv;
hcf_8 *wpa_ie = NULL;
hcf_16 wpa_ie_len = 0;
DBG_TRACE( DbgInfo, L_156,
lp->dev->name );
DBG_TRACE( DbgInfo, L_157,
lp->dev->name, probe_rsp->length );
if ( probe_rsp->length > 1 ) {
DBG_TRACE( DbgInfo, L_158,
lp->dev->name, probe_rsp->infoType );
DBG_TRACE( DbgInfo, L_159,
lp->dev->name, probe_rsp->signal );
DBG_TRACE( DbgInfo, L_160,
lp->dev->name, probe_rsp->silence );
DBG_TRACE( DbgInfo, L_161,
lp->dev->name, probe_rsp->rxFlow );
DBG_TRACE( DbgInfo, L_162,
lp->dev->name, probe_rsp->rate );
DBG_TRACE( DbgInfo, L_163,
lp->dev->name, probe_rsp->frameControl );
DBG_TRACE( DbgInfo, L_164,
lp->dev->name, probe_rsp->durID );
DBG_TRACE(DbgInfo, L_165,
lp->dev->name, probe_rsp->address1);
DBG_TRACE(DbgInfo, L_166,
lp->dev->name, probe_rsp->address2);
DBG_TRACE(DbgInfo, L_167,
lp->dev->name, probe_rsp->BSSID);
DBG_TRACE( DbgInfo, L_168,
lp->dev->name, probe_rsp->sequence );
DBG_TRACE(DbgInfo, L_169,
lp->dev->name, probe_rsp->address4);
DBG_TRACE( DbgInfo, L_170,
lp->dev->name, probe_rsp->dataLength );
DBG_TRACE(DbgInfo, L_171,
lp->dev->name, probe_rsp->DA);
DBG_TRACE(DbgInfo, L_172,
lp->dev->name, probe_rsp->SA);
DBG_TRACE(DbgInfo, L_173
L_174,
lp->dev->name,
probe_rsp->timeStamp[0],
probe_rsp->timeStamp[1],
probe_rsp->timeStamp[2],
probe_rsp->timeStamp[3],
probe_rsp->timeStamp[4],
probe_rsp->timeStamp[5],
probe_rsp->timeStamp[6],
probe_rsp->timeStamp[7]);
DBG_TRACE( DbgInfo, L_175,
lp->dev->name, probe_rsp->beaconInterval );
DBG_TRACE( DbgInfo, L_176,
lp->dev->name, probe_rsp->capability );
DBG_TRACE( DbgInfo, L_177,
lp->dev->name, probe_rsp->rawData[1] );
if ( probe_rsp->rawData[1] > 0 ) {
char ssid[HCF_MAX_NAME_LEN];
memset( ssid, 0, sizeof( ssid ));
strncpy( ssid, &probe_rsp->rawData[2],
min_t(u8,
probe_rsp->rawData[1],
HCF_MAX_NAME_LEN - 1));
DBG_TRACE( DbgInfo, L_178,
lp->dev->name, ssid );
}
wpa_ie = wl_parse_wpa_ie( probe_rsp, &wpa_ie_len );
if ( wpa_ie != NULL ) {
DBG_TRACE( DbgInfo, L_179,
lp->dev->name, wl_print_wpa_ie( wpa_ie, wpa_ie_len ));
}
DBG_TRACE( DbgInfo, L_180,
lp->dev->name, probe_rsp->flags );
}
DBG_TRACE( DbgInfo, L_181 );
if ( probe_rsp->length == 1 ) {
DBG_TRACE( DbgInfo, L_182 );
lp->probe_results.num_aps = lp->probe_num_aps;
lp->probe_results.scan_complete = TRUE;
lp->probe_num_aps = 0;
wl_wext_event_scan_complete( lp->dev );
} else {
if ( lp->probe_num_aps == 0 ) {
memcpy( &( lp->probe_results.ProbeTable[lp->probe_num_aps] ),
probe_rsp, sizeof( PROBE_RESP ));
lp->probe_num_aps++;
} else {
int count;
int unique = 1;
for( count = 0; count < lp->probe_num_aps; count++ ) {
if ( memcmp( &( probe_rsp->BSSID ),
lp->probe_results.ProbeTable[count].BSSID,
ETH_ALEN ) == 0 ) {
unique = 0;
}
}
if ( unique ) {
if ( lp->probe_num_aps < MAX_NAPS )
{
memcpy( &( lp->probe_results.ProbeTable[lp->probe_num_aps] ),
probe_rsp, sizeof( PROBE_RESP ));
}
else
{
DBG_WARNING( DbgInfo, L_183 );
}
lp->probe_num_aps++;
}
}
}
}
break;
case CFG_LINK_STAT:
#define F_30 ((LINK_STATUS_STRCT *)ltv)
DBG_TRACE( DbgInfo, L_184 );
switch( ls->linkStatus ) {
case 1:
DBG_TRACE( DbgInfo, L_185 );
wl_wext_event_ap( lp->dev );
break;
case 2:
DBG_TRACE( DbgInfo, L_186 );
break;
case 3:
DBG_TRACE( DbgInfo, L_187 );
break;
case 4:
DBG_TRACE( DbgInfo, L_188 );
break;
case 5:
DBG_TRACE( DbgInfo, L_189 );
break;
default:
DBG_TRACE( DbgInfo, L_190,
ls->linkStatus );
break;
}
break;
#undef F_30
case CFG_ASSOC_STAT:
DBG_TRACE( DbgInfo, L_191 );
{
ASSOC_STATUS_STRCT *as = (ASSOC_STATUS_STRCT *)ltv;
switch( as->assocStatus ) {
case 1:
DBG_TRACE( DbgInfo, L_192 );
break;
case 2:
DBG_TRACE( DbgInfo, L_193 );
break;
case 3:
DBG_TRACE( DbgInfo, L_194 );
break;
default:
DBG_TRACE( DbgInfo, L_195,
as->assocStatus );
break;
}
DBG_TRACE(DbgInfo, L_196,
as->staAddr);
if (( as->assocStatus == 2 ) && ( as->len == 8 )) {
DBG_TRACE(DbgInfo, L_197,
as->oldApAddr);
}
}
break;
case CFG_SECURITY_STAT:
DBG_TRACE( DbgInfo, L_198 );
{
SECURITY_STATUS_STRCT *ss = (SECURITY_STATUS_STRCT *)ltv;
switch( ss->securityStatus ) {
case 1:
DBG_TRACE( DbgInfo, L_199 );
break;
case 2:
DBG_TRACE( DbgInfo, L_200 );
break;
case 3:
DBG_TRACE( DbgInfo, L_201 );
break;
case 4:
DBG_TRACE( DbgInfo, L_202 );
break;
case 5:
DBG_TRACE( DbgInfo, L_203 );
break;
default:
DBG_TRACE( DbgInfo, L_204,
ss->securityStatus );
break;
}
DBG_TRACE(DbgInfo, L_205,
ss->staAddr);
DBG_TRACE(DbgInfo, L_206,
ss->reason);
}
break;
case CFG_WMP:
DBG_TRACE( DbgInfo, L_207, ltv->len );
{
WMP_RSP_STRCT *wmp_rsp = (WMP_RSP_STRCT *)ltv;
DBG_TRACE( DbgInfo, L_208,
wmp_rsp->wmpRsp.wmpHdr.type );
switch( wmp_rsp->wmpRsp.wmpHdr.type ) {
case WVLAN_WMP_PDU_TYPE_LT_RSP:
{
#if V_249
LINKTEST_RSP_STRCT *lt_rsp = (LINKTEST_RSP_STRCT *)ltv;
#endif
DBG_TRACE( DbgInfo, L_209 );
DBG_TRACE( DbgInfo, L_210 );
DBG_TRACE( DbgInfo, L_211, lt_rsp->len );
DBG_TRACE( DbgInfo, L_212, lt_rsp->ltRsp.ltRsp.name );
DBG_TRACE( DbgInfo, L_213, lt_rsp->ltRsp.ltRsp.signal );
DBG_TRACE( DbgInfo, L_214, lt_rsp->ltRsp.ltRsp.noise );
DBG_TRACE( DbgInfo, L_215, lt_rsp->ltRsp.ltRsp.rxFlow );
DBG_TRACE( DbgInfo, L_216, lt_rsp->ltRsp.ltRsp.dataRate );
DBG_TRACE( DbgInfo, L_217, lt_rsp->ltRsp.ltRsp.protocol );
DBG_TRACE( DbgInfo, L_218, lt_rsp->ltRsp.ltRsp.station );
DBG_TRACE( DbgInfo, L_219, lt_rsp->ltRsp.ltRsp.dataRateCap );
DBG_TRACE( DbgInfo, L_220,
lt_rsp->ltRsp.ltRsp.powerMgmt[0],
lt_rsp->ltRsp.ltRsp.powerMgmt[1],
lt_rsp->ltRsp.ltRsp.powerMgmt[2],
lt_rsp->ltRsp.ltRsp.powerMgmt[3] );
DBG_TRACE( DbgInfo, L_221,
lt_rsp->ltRsp.ltRsp.robustness[0],
lt_rsp->ltRsp.ltRsp.robustness[1],
lt_rsp->ltRsp.ltRsp.robustness[2],
lt_rsp->ltRsp.ltRsp.robustness[3] );
DBG_TRACE( DbgInfo, L_222, lt_rsp->ltRsp.ltRsp.scaling );
}
break;
default:
break;
}
}
break;
case CFG_NULL:
DBG_TRACE( DbgInfo, L_223 );
break;
case CFG_UPDATED_INFO_RECORD:
DBG_TRACE( DbgInfo, L_224 );
ltv_val = CNV_INT_TO_LITTLE( ltv->u.u16[0] );
switch( ltv_val ) {
case CFG_CUR_COUNTRY_INFO:
DBG_TRACE( DbgInfo, L_225 );
wl_connect( lp );
break;
case CFG_PORT_STAT:
break;
default:
DBG_WARNING( DbgInfo, L_226, ltv_val );
}
break;
default:
DBG_TRACE( DbgInfo, L_227, ltv->typ );
break;
}
DBG_LEAVE( DbgInfo );
return;
}
#endif
#ifdef F_7
void wl_wds_netdev_register( struct wl_private *lp )
{
int count;
DBG_FUNC( L_228 );
DBG_ENTER( DbgInfo );
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
for( count = 0; count < NUM_WDS_PORTS; count++ ) {
if ( WVLAN_VALID_MAC_ADDRESS( lp->wds_port[count].wdsAddress )) {
if ( register_netdev( lp->wds_port[count].dev ) != 0 ) {
DBG_WARNING( DbgInfo, L_229,
( count + 1 ));
}
lp->wds_port[count].is_registered = TRUE;
memcpy( lp->wds_port[count].dev->dev_addr, lp->MACAddress, ETH_ALEN );
lp->wds_port[count].dev->addr_len = ETH_ALEN;
}
}
}
DBG_LEAVE( DbgInfo );
return;
}
void wl_wds_netdev_deregister( struct wl_private *lp )
{
int count;
DBG_FUNC( L_230 );
DBG_ENTER( DbgInfo );
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
for( count = 0; count < NUM_WDS_PORTS; count++ ) {
if ( WVLAN_VALID_MAC_ADDRESS( lp->wds_port[count].wdsAddress )) {
unregister_netdev( lp->wds_port[count].dev );
}
lp->wds_port[count].is_registered = FALSE;
}
}
DBG_LEAVE( DbgInfo );
return;
}
#endif
#if 0
static void printf_hcf_16(struct seq_file *m, const char *s, hcf_16 *p, int n)
{
int i, len;
seq_printf(m, "%-20.20s: ", s);
len = 22;
for (i = 0; i < n; i++) {
if (len % 80 > 75)
seq_putc(m, '\n');
seq_printf(m, "%04X ", p[i]);
}
seq_putc(m, '\n');
}
static void printf_hcf_8(struct seq_file *m, const char *s, hcf_8 *p, int n)
{
int i, len;
seq_printf(m, "%-20.20s: ", s);
len = 22;
for (i = 0; i <= n; i++) {
if (len % 80 > 77)
seq_putc(m, '\n');
seq_printf(m, "%02X ", p[i]);
}
seq_putc(m, '\n');
}
static void printf_strct(struct seq_file *m, const char *s, hcf_16 *p)
{
int i, len;
seq_printf(m, "%-20.20s: ", s);
len = 22;
for ( i = 0; i <= *p; i++ ) {
if (len % 80 > 75)
seq_putc(m, '\n');
seq_printf(m,"%04X ", p[i]);
}
seq_putc(m, '\n');
}
int scull_read_procmem(struct seq_file *m, void *v)
{
struct wl_private *lp = m->private;
IFBP ifbp;
CFG_HERMES_TALLIES_STRCT *p;
if (lp == NULL) {
seq_puts(m, "No wl_private in scull_read_procmem\n" );
} else if ( lp->wlags49_type == 0 ){
ifbp = &lp->hcfCtx;
seq_printf(m, "Magic: 0x%04X\n", ifbp->IFB_Magic );
seq_printf(m, "IOBase: 0x%04X\n", ifbp->IFB_IOBase );
seq_printf(m, "LinkStat: 0x%04X\n", ifbp->IFB_LinkStat );
seq_printf(m, "DSLinkStat: 0x%04X\n", ifbp->IFB_DSLinkStat );
seq_printf(m, "TickIni: 0x%08lX\n", ifbp->IFB_TickIni );
seq_printf(m, "TickCnt: 0x%04X\n", ifbp->IFB_TickCnt );
seq_printf(m, "IntOffCnt: 0x%04X\n", ifbp->IFB_IntOffCnt );
printf_hcf_16(m, "IFB_FWIdentity",
&ifbp->IFB_FWIdentity.len, ifbp->IFB_FWIdentity.len + 1 );
} else if ( lp->wlags49_type == 1 ) {
seq_printf(m, "Channel: 0x%04X\n", lp->Channel );
#ifdef F_31
#endif
seq_printf(m, "IFB: 0x%p\n", &lp->hcfCtx );
seq_printf(m, "flags: %#.8lX\n", lp->flags );
seq_printf(m, "DebugFlag(wl_private) 0x%04X\n", lp->DebugFlag );
#if V_249
seq_printf(m, "DebugFlag (DbgInfo): 0x%08lX\n", DbgInfo->DebugFlag );
#endif
seq_printf(m, "is_registered: 0x%04X\n", lp->is_registered );
printf_strct( m, "driverInfo", (hcf_16*)&lp->driverInfo );
printf_strct( m, "driverIdentity", (hcf_16*)&lp->driverIdentity );
printf_strct( m, "StationIdentity", (hcf_16*)&lp->StationIdentity );
printf_strct( m, "PrimaryIdentity", (hcf_16*)&lp->hcfCtx.IFB_PRIIdentity );
printf_strct( m, "PrimarySupplier", (hcf_16*)&lp->hcfCtx.IFB_PRISup );
printf_strct( m, "NICIdentity", (hcf_16*)&lp->NICIdentity );
seq_printf(m, "txBytes: 0x%08lX\n", lp->txBytes );
seq_printf(m, "maxPort: 0x%04X\n", lp->maxPort );
seq_printf(m, "PortType: 0x%04X\n", lp->PortType );
seq_printf(m, "Channel: 0x%04X\n", lp->Channel );
seq_printf(m, "TxRateControl[2]: 0x%04X 0x%04X\n",
lp->TxRateControl[0], lp->TxRateControl[1] );
seq_printf(m, "DistanceBetweenAPs: 0x%04X\n", lp->DistanceBetweenAPs );
seq_printf(m, "RTSThreshold: 0x%04X\n", lp->RTSThreshold );
seq_printf(m, "PMEnabled: 0x%04X\n", lp->PMEnabled );
seq_printf(m, "MicrowaveRobustness: 0x%04X\n", lp->MicrowaveRobustness );
seq_printf(m, "CreateIBSS: 0x%04X\n", lp->CreateIBSS );
seq_printf(m, "MulticastReceive: 0x%04X\n", lp->MulticastReceive );
seq_printf(m, "MaxSleepDuration: 0x%04X\n", lp->MaxSleepDuration );
printf_hcf_8(m, "MACAddress", lp->MACAddress, ETH_ALEN );
seq_printf(m, "NetworkName: %.32s\n", lp->NetworkName );
seq_printf(m, "EnableEncryption: 0x%04X\n", lp->EnableEncryption );
printf_hcf_8( m, "Key1", lp->Key1, MAX_KEY_LEN );
seq_printf(m, "TransmitKeyID: 0x%04X\n", lp->TransmitKeyID );
seq_printf(m, "driverEnable: 0x%04X\n", lp->driverEnable );
seq_printf(m, "wolasEnable: 0x%04X\n", lp->wolasEnable );
seq_printf(m, "atimWindow: 0x%04X\n", lp->atimWindow );
seq_printf(m, "holdoverDuration: 0x%04X\n", lp->holdoverDuration );
seq_printf(m, "authentication: 0x%04X\n", lp->authentication );
seq_printf(m, "promiscuousMode: 0x%04X\n", lp->promiscuousMode );
seq_printf(m, "DownloadFirmware: 0x%04X\n", lp->DownloadFirmware );
seq_printf(m, "AuthKeyMgmtSuite: 0x%04X\n", lp->AuthKeyMgmtSuite );
seq_printf(m, "loadBalancing: 0x%04X\n", lp->loadBalancing );
seq_printf(m, "mediumDistribution: 0x%04X\n", lp->mediumDistribution );
seq_printf(m, "txPowLevel: 0x%04X\n", lp->txPowLevel );
seq_printf(m, "connectionControl: 0x%04X\n", lp->connectionControl );
seq_printf(m, "ownBeaconInterval: 0x%04X\n", lp->ownBeaconInterval );
seq_printf(m, "coexistence: 0x%04X\n", lp->coexistence );
seq_printf(m, "netif_queue_on: 0x%04X\n", lp->netif_queue_on );
seq_printf(m, "txQ_count: 0x%04X\n", lp->txQ_count );
seq_printf(m, "probe_num_aps: 0x%04X\n", lp->probe_num_aps );
seq_printf(m, "use_dma: 0x%04X\n", lp->use_dma );
#ifdef F_11
seq_printf(m, "useRTS: 0x%04X\n", lp->useRTS );
#endif
#if 1
seq_printf(m, "DTIMPeriod: 0x%04X\n", lp->DTIMPeriod );
seq_printf(m, "multicastPMBuffering: 0x%04X\n", lp->multicastPMBuffering );
seq_printf(m, "RejectAny: 0x%04X\n", lp->RejectAny );
seq_printf(m, "ExcludeUnencrypted: 0x%04X\n", lp->ExcludeUnencrypted );
seq_printf(m, "intraBSSRelay: 0x%04X\n", lp->intraBSSRelay );
seq_printf(m, "wlags49_type: 0x%08lX\n", lp->wlags49_type );
#ifdef F_7
#endif
#endif
} else if ( lp->wlags49_type == 2 ){
seq_printf(m, "tallies to be added\n" );
p = &lp->hcfCtx.IFB_NIC_Tallies;
seq_printf(m, "TxUnicastFrames: %08lX\n", p->TxUnicastFrames );
seq_printf(m, "TxMulticastFrames: %08lX\n", p->TxMulticastFrames );
seq_printf(m, "TxFragments: %08lX\n", p->TxFragments );
seq_printf(m, "TxUnicastOctets: %08lX\n", p->TxUnicastOctets );
seq_printf(m, "TxMulticastOctets: %08lX\n", p->TxMulticastOctets );
seq_printf(m, "TxDeferredTransmissions: %08lX\n", p->TxDeferredTransmissions );
seq_printf(m, "TxSingleRetryFrames: %08lX\n", p->TxSingleRetryFrames );
seq_printf(m, "TxMultipleRetryFrames: %08lX\n", p->TxMultipleRetryFrames );
seq_printf(m, "TxRetryLimitExceeded: %08lX\n", p->TxRetryLimitExceeded );
seq_printf(m, "TxDiscards: %08lX\n", p->TxDiscards );
seq_printf(m, "RxUnicastFrames: %08lX\n", p->RxUnicastFrames );
seq_printf(m, "RxMulticastFrames: %08lX\n", p->RxMulticastFrames );
seq_printf(m, "RxFragments: %08lX\n", p->RxFragments );
seq_printf(m, "RxUnicastOctets: %08lX\n", p->RxUnicastOctets );
seq_printf(m, "RxMulticastOctets: %08lX\n", p->RxMulticastOctets );
seq_printf(m, "RxFCSErrors: %08lX\n", p->RxFCSErrors );
seq_printf(m, "RxDiscardsNoBuffer: %08lX\n", p->RxDiscardsNoBuffer );
seq_printf(m, "TxDiscardsWrongSA: %08lX\n", p->TxDiscardsWrongSA );
seq_printf(m, "RxWEPUndecryptable: %08lX\n", p->RxWEPUndecryptable );
seq_printf(m, "RxMsgInMsgFragments: %08lX\n", p->RxMsgInMsgFragments );
seq_printf(m, "RxMsgInBadMsgFragments: %08lX\n", p->RxMsgInBadMsgFragments );
seq_printf(m, "RxDiscardsWEPICVError: %08lX\n", p->RxDiscardsWEPICVError );
seq_printf(m, "RxDiscardsWEPExcluded: %08lX\n", p->RxDiscardsWEPExcluded );
#if ( V_250 ) & V_251
#endif
} else if ( lp->wlags49_type & 0x8000 ) {
#if V_249
DbgInfo->DebugFlag = lp->wlags49_type & 0x7FFF;
#endif
lp->wlags49_type = 0;
} else {
seq_printf(m, "unknown value for wlags49_type: 0x%08lX\n", lp->wlags49_type );
seq_puts(m,
"0x0000 - IFB\n"
"0x0001 - wl_private\n"
"0x0002 - Tallies\n"
"0x8xxx - Change debufflag\n"
"ERROR 0001\nWARNING 0002\nNOTICE 0004\nTRACE 0008\n"
"VERBOSE 0010\nPARAM 0020\nBREAK 0040\nRX 0100\n"
"TX 0200\nDS 0400\n");
}
return 0;
}
static int write_int(struct file *file, const char *buffer, unsigned long count, void *data)
{
static char proc_number[11];
unsigned int nr = 0;
DBG_FUNC( "write_int" );
DBG_ENTER( DbgInfo );
if (count > 9) {
count = -EINVAL;
} else if ( copy_from_user(proc_number, buffer, count) ) {
count = -EFAULT;
}
if (count > 0 ) {
proc_number[count] = 0;
nr = simple_strtoul(proc_number , NULL, 0);
*(unsigned int *)data = nr;
if ( nr & 0x8000 ) {
#if V_249
DbgInfo->DebugFlag = nr & 0x7FFF;
#endif
}
}
DBG_PRINT( "value: %08X\n", nr );
DBG_LEAVE( DbgInfo );
return count;
}
#endif
#ifdef F_32
#define F_33 ( T_1 ) (jiffies+(x))
#define F_34 0x8000
lp->timer_oor_cnt = DS_OOR;
init_timer( &lp->timer_oor );
lp->timer_oor.function = timer_oor;
lp->timer_oor.data = (unsigned long)lp;
lp->timer_oor.expires = RUN_AT( 3 * HZ );
add_timer( &lp->timer_oor );
printk(KERN_NOTICE L_231, jiffies );
#endif
#ifdef F_32
void timer_oor( u_long arg )
{
struct wl_private *lp = (struct wl_private *)arg;
DBG_FUNC( L_232 );
DBG_ENTER( DbgInfo );
DBG_PARAM( DbgInfo, L_233, L_234, arg );
printk(KERN_NOTICE L_235, jiffies, lp->timer_oor_cnt );
lp->timer_oor_cnt += 10;
if ( (lp->timer_oor_cnt & ~DS_OOR) > 300 ) {
lp->timer_oor_cnt = 300;
}
lp->timer_oor_cnt |= DS_OOR;
init_timer( &lp->timer_oor );
lp->timer_oor.function = timer_oor;
lp->timer_oor.data = (unsigned long)lp;
lp->timer_oor.expires = RUN_AT( (lp->timer_oor_cnt & ~DS_OOR) * HZ );
add_timer( &lp->timer_oor );
DBG_LEAVE( DbgInfo );
}
#endif
MODULE_LICENSE(L_236);
