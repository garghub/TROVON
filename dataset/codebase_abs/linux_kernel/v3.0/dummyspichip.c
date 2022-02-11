static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( & V_7 -> V_2 ) ;
int V_10 ;
T_2 V_11 [ 14 ] = { 0xDE , 0xAD , 0xBE , 0xEF , 0x2B , 0xAD ,
0xCA , 0xFE , 0xBA , 0xBE , 0xB1 , 0x05 ,
0xF0 , 0x0D } ;
T_2 V_12 [ 14 ] ;
T_2 * V_13 ;
T_2 * V_14 ;
if ( F_4 ( & V_9 -> V_15 ) )
return - V_16 ;
V_13 = F_5 ( V_17 , V_18 ) ;
if ( V_13 == NULL ) {
V_10 = - V_19 ;
goto V_20;
}
V_14 = F_5 ( V_17 , V_18 ) ;
memset ( V_13 , 0xAA , V_17 ) ;
V_7 -> V_21 = 8 ;
V_7 -> V_22 -> V_23 ( V_7 ) ;
F_6 ( L_1
L_2 ) ;
V_10 = F_7 ( V_7 , 0xAA ) ;
if ( V_10 < 0 )
F_8 ( L_3
L_4 , V_10 ) ;
else
F_6 ( L_5 ) ;
F_6 ( L_6
L_7 ) ;
V_10 = F_9 ( V_7 , & V_11 [ 0 ] , 8 , & V_12 [ 0 ] , 8 ) ;
if ( V_10 < 0 )
F_8 ( L_8
L_4 , V_10 ) ;
else
F_6 ( L_9 ) ;
F_6 ( L_10
L_11 ) ;
V_10 = F_9 ( V_7 , & V_11 [ 0 ] , 14 , & V_12 [ 0 ] , 14 ) ;
if ( V_10 < 0 )
F_8 ( L_12
L_13 , V_10 ) ;
else
F_6 ( L_14 ) ;
F_6 ( L_15
L_16 ) ;
V_10 = F_10 ( V_7 , & V_11 [ 0 ] , 8 ) ;
if ( V_10 < 0 )
F_8 ( L_17
L_4 , V_10 ) ;
else
F_6 ( L_18 ) ;
V_10 = F_11 ( V_7 , & V_12 [ 0 ] , 8 ) ;
if ( V_10 < 0 )
F_8 ( L_19
L_4 , V_10 ) ;
else
F_6 ( L_20 ) ;
F_6 ( L_21
L_22 ) ;
V_10 = F_10 ( V_7 , & V_11 [ 0 ] , 14 ) ;
if ( V_10 < 0 )
F_8 ( L_23
L_24 ,
V_10 ) ;
else
F_6 ( L_25 ) ;
V_10 = F_11 ( V_7 , & V_12 [ 0 ] , 14 ) ;
if ( V_10 < 0 )
F_8 ( L_26
L_24 ,
V_10 ) ;
else
F_6 ( L_27 ) ;
F_6 ( L_28
L_29 ,
V_17 , V_17 ) ;
V_10 = F_10 ( V_7 , & V_13 [ 0 ] , V_17 ) ;
if ( V_10 < 0 )
F_8 ( L_30
L_24 ,
V_10 ) ;
else
F_6 ( L_31 ) ;
V_10 = F_11 ( V_7 , & V_14 [ 0 ] , V_17 ) ;
if ( V_10 < 0 )
F_8 ( L_32
L_24 ,
V_10 ) ;
else
F_6 ( L_33 ) ;
V_7 -> V_21 = 16 ;
V_7 -> V_22 -> V_23 ( V_7 ) ;
F_6 ( L_34
L_35 ) ;
V_10 = F_7 ( V_7 , 0xAA ) ;
if ( V_10 == - V_24 )
F_6 ( L_36
L_37 ) ;
else if ( V_10 < 0 )
F_8 ( L_38
L_4 , V_10 ) ;
else
F_8 ( L_38
L_39 ) ;
F_6 ( L_40
L_41 ) ;
V_10 = F_9 ( V_7 , & V_11 [ 0 ] , 8 , & V_12 [ 0 ] , 8 ) ;
if ( V_10 < 0 )
F_8 ( L_42
L_4 , V_10 ) ;
else
F_6 ( L_43 ) ;
F_6 ( L_44
L_45 ) ;
V_10 = F_9 ( V_7 , & V_11 [ 0 ] , 14 , & V_12 [ 0 ] , 14 ) ;
if ( V_10 < 0 )
F_8 ( L_46
L_13 , V_10 ) ;
else
F_6 ( L_47 ) ;
F_6 ( L_48
L_49 ,
V_17 , V_17 ) ;
V_10 = F_10 ( V_7 , & V_13 [ 0 ] , V_17 ) ;
if ( V_10 < 0 )
F_8 ( L_50
L_24 ,
V_10 ) ;
else
F_6 ( L_51 ) ;
V_10 = F_11 ( V_7 , & V_14 [ 0 ] , V_17 ) ;
if ( V_10 < 0 )
F_8 ( L_52
L_24 ,
V_10 ) ;
else
F_6 ( L_53 ) ;
V_10 = sprintf ( V_5 , L_54 ) ;
F_12 ( V_14 ) ;
F_12 ( V_13 ) ;
V_20:
F_13 ( & V_9 -> V_15 ) ;
return V_10 ;
}
static int T_3 F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
F_15 ( & V_7 -> V_2 , L_55 ) ;
V_9 = F_16 ( sizeof *V_9 , V_18 ) ;
if ( ! V_9 )
return - V_19 ;
F_17 ( & V_7 -> V_2 , V_9 ) ;
F_18 ( & V_9 -> V_15 ) ;
V_10 = F_19 ( & V_7 -> V_2 , & V_25 ) ;
if ( V_10 ) {
F_20 ( & V_7 -> V_2 , L_56 ) ;
goto V_26;
}
return 0 ;
V_26:
F_17 ( & V_7 -> V_2 , NULL ) ;
F_12 ( V_9 ) ;
return V_10 ;
}
static int T_4 F_21 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( & V_7 -> V_2 ) ;
F_15 ( & V_7 -> V_2 , L_57 ) ;
F_22 ( & V_7 -> V_2 , & V_25 ) ;
F_17 ( & V_7 -> V_2 , NULL ) ;
F_12 ( V_9 ) ;
return 0 ;
}
static int T_5 F_23 ( void )
{
return F_24 ( & V_27 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_27 ) ;
}
