static T_1 F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_5 V_4 )
{
T_6 * V_5 = NULL ;
T_6 * V_6 = NULL ;
T_4 * V_7 = NULL ;
T_7 V_8 = 0 ;
T_8 V_9 ;
if( F_2 ( V_1 ) < 16 ) {
return FALSE ;
}
if( F_3 ( V_1 , 0 , V_10 , 4 ) == - 1 ) {
return FALSE ;
}
F_4 ( V_2 -> V_11 , V_12 , L_1 ) ;
if( F_5 ( V_2 -> V_11 , V_13 ) ) {
F_6 ( V_2 -> V_11 , V_13 , L_2 , F_7 ( V_1 , 4 ) ) ;
}
if( V_3 ) {
V_5 = F_8 ( V_3 , V_14 , V_1 , 0 , - 1 , V_15 ) ;
V_7 = F_9 ( V_5 , V_16 ) ;
F_8 ( V_7 , V_17 , V_1 , V_8 , 4 , V_18 ) ;
V_8 += 4 ;
F_8 ( V_7 , V_19 , V_1 , V_8 , 4 , V_18 ) ;
V_8 += 4 ;
V_9 . V_20 = F_7 ( V_1 , V_8 ) ;
V_6 = F_8 ( V_7 , V_21 , V_1 , V_8 , 4 , V_18 ) ;
F_10 ( V_6 ) ;
V_8 += 4 ;
V_9 . V_22 = F_7 ( V_1 , V_8 ) * 1000 ;
V_6 = F_8 ( V_7 , V_23 , V_1 , V_8 , 4 , V_18 ) ;
F_10 ( V_6 ) ;
V_8 += 4 ;
F_11 ( V_7 , V_24 , V_1 , V_8 - 8 , 8 , & V_9 ) ;
#if 0
if(tvb_length_remaining(tvb, offset))
proto_tree_add_text(pktgen_tree, tvb, offset, -1, "Data (%u bytes)",
tvb_length_remaining(tvb, offset));
#else
if( F_12 ( V_1 , V_8 ) )
F_13 ( V_25 , F_14 ( V_1 , V_8 ) , V_2 ,
V_7 ) ;
#endif
}
return TRUE ;
}
void F_15 ( void )
{
static T_9 V_26 [] = {
{ & V_17 ,
{
L_3 , L_4 ,
V_27 , V_28 , NULL , 0x0 ,
L_5 , V_29
}
} ,
{ & V_19 ,
{
L_6 , L_7 ,
V_27 , V_30 , NULL , 0x0 ,
NULL , V_29
}
} ,
{ & V_21 ,
{
L_8 , L_9 ,
V_27 , V_30 , NULL , 0x0 ,
L_10 , V_29
}
} ,
{ & V_23 ,
{
L_11 , L_12 ,
V_27 , V_30 , NULL , 0x0 ,
L_13 , V_29
}
} ,
{ & V_24 ,
{
L_14 , L_15 ,
V_31 , V_32 , NULL , 0x0 ,
NULL , V_29
}
}
} ;
static T_10 * V_33 [] = {
& V_16
} ;
V_14 = F_16 ( L_16 , L_1 , L_17 ) ;
F_17 ( V_14 , V_26 , F_18 ( V_26 ) ) ;
F_19 ( V_33 , F_18 ( V_33 ) ) ;
}
void F_20 ( void )
{
F_21 ( L_18 , F_1 , V_14 ) ;
V_25 = F_22 ( L_19 ) ;
}
