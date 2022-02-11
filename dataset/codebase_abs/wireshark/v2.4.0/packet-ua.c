static void F_1 ( T_1 V_1 ,
T_2 * V_2 ,
T_3 * V_3 ,
T_4 * V_4 ,
T_5 V_5 ,
T_5 V_6 ,
T_5 V_7 )
{
switch ( V_6 & 0x7f )
{
case 0x15 :
case 0x16 :
{
F_2 ( V_8 ,
F_3 ( V_4 , V_5 , V_7 ) ,
V_3 ,
V_2 ) ;
break;
}
case 0x00 :
case 0x01 :
case 0x02 :
case 0x03 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x09 :
case 0x0A :
case 0x0B :
case 0x0C :
case 0x0D :
case 0x0E :
case 0x0F :
case 0x11 :
case 0x12 :
case 0x13 :
case 0x14 :
case 0x17 :
case 0x18 :
case 0x1F :
case 0x20 :
case 0x21 :
case 0x22 :
case 0x23 :
case 0x24 :
case 0x25 :
case 0x26 :
case 0x27 :
case 0x28 :
case 0x29 :
case 0x2A :
case 0x2B :
case 0x2C :
case 0x2D :
case 0x2E :
case 0x30 :
case 0x31 :
case 0x32 :
case 0x33 :
case 0x35 :
case 0x36 :
case 0x38 :
case 0x39 :
case 0x3A :
case 0x3B :
case 0x3C :
case 0x3D :
case 0x3E :
case 0x3F :
case 0x40 :
case 0x41 :
case 0x42 :
case 0x43 :
case 0x44 :
case 0x45 :
case 0x46 :
case 0x47 :
case 0x48 :
case 0x49 :
case 0x4A :
case 0x4B :
case 0x4C :
case 0x4D :
case 0x4E :
case 0x4F :
case 0x50 :
{
F_4 ( V_9 ,
F_3 ( V_4 , V_5 , V_7 ) ,
V_3 ,
V_2 , & V_1 ) ;
break;
}
default:
{
F_5 ( V_3 -> V_10 , V_11 , L_1 , F_6 ( V_4 , ( V_5 + 2 ) ) ) ;
F_7 ( F_3 ( V_4 , V_5 , V_7 ) ,
V_3 ,
V_2 ) ;
break;
}
}
}
static void F_8 ( T_4 * V_4 ,
T_3 * V_3 ,
T_2 * V_2 ,
T_1 V_1 )
{
T_5 V_5 = 0 ;
T_6 * V_12 ;
T_2 * V_13 ;
V_12 = F_9 ( V_2 , V_14 , V_4 , 0 , - 1 ,
L_2 ,
( ( V_1 == V_15 ) ?
L_3 : L_4 ) ) ;
V_13 = F_10 ( V_12 , V_16 ) ;
while ( F_11 ( V_4 , V_5 ) )
{
T_5 V_7 ;
T_5 V_6 ;
V_7 = F_12 ( V_4 , V_5 ) + 2 ;
V_6 = F_6 ( V_4 , V_5 + 2 ) ;
if ( V_17 && ( V_6 == 0x13 ) && ( F_6 ( V_4 , V_5 + 3 ) == 0x01 ) )
{
T_7 V_18 ;
T_8 V_19 ;
T_5 V_20 ;
V_18 . V_21 = NULL ;
V_19 = 0 ;
V_20 = V_5 + 5 ;
while ( V_20 < V_5 + V_7 )
{
switch ( F_6 ( V_4 , V_20 ) )
{
case 0x00 :
{
break;
}
case 0x01 :
{
F_13 ( & V_18 , V_22 , 4 , V_4 , V_20 + 2 ) ;
break;
}
case 0x02 :
{
V_19 = F_14 ( V_4 , V_20 + 2 ) ;
break;
}
}
V_20 += F_6 ( V_4 , V_20 + 1 ) + 2 ;
}
if ( ( V_18 . V_21 != NULL ) && ( V_19 != 0 ) )
{
F_15 ( V_3 , V_23 , & V_18 , V_19 , 0 ,
L_5 , V_3 -> V_24 , 0 , NULL ) ;
F_16 ( V_3 , & V_18 , V_19 + 1 , 0 ,
L_5 , V_3 -> V_24 ) ;
}
}
F_1 ( V_1 , V_13 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
V_5 += V_7 ;
}
}
static int F_17 ( T_4 * V_4 , T_3 * V_3 , T_2 * V_2 , void * V_21 V_25 )
{
F_8 ( V_4 , V_3 , V_2 , V_15 ) ;
return F_18 ( V_4 ) ;
}
static int F_19 ( T_4 * V_4 , T_3 * V_3 , T_2 * V_2 , void * V_21 V_25 )
{
F_8 ( V_4 , V_3 , V_2 , V_26 ) ;
return F_18 ( V_4 ) ;
}
void F_20 ( void )
{
T_9 * V_27 ;
static T_5 * V_28 [] =
{
& V_16 ,
} ;
V_14 = F_21 ( L_6 , L_5 , L_7 ) ;
F_22 ( L_8 , F_17 , V_14 ) ;
F_22 ( L_9 , F_19 , V_14 ) ;
F_23 ( V_28 , F_24 ( V_28 ) ) ;
V_27 = F_25 ( V_14 , NULL ) ;
F_26 ( V_27 , L_10 ,
L_11 ,
L_12 ,
& V_17 ) ;
}
void F_27 ( void )
{
#if 0
dissector_handle_t handle_ua_msg;
handle_ua_msg = find_dissector("ua_sys_to_term");
dissector_add_uint("uaudp.opcode", UAUDP_DATA, handle_ua_msg);
handle_ua_msg = find_dissector("ua_term_to_sys");
dissector_add_uint("uaudp.opcode", UAUDP_DATA, handle_ua_msg);
ua_opcode_dissector_table =
register_dissector_table("ua.opcode",
"ua.opcode",
FT_UINT8,
BASE_HEX);
#endif
V_8 = F_28 ( L_13 , V_14 ) ;
V_9 = F_28 ( L_14 , V_14 ) ;
}
