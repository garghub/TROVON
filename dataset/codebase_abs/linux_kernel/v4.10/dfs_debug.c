static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 -> V_11 ;
char * V_12 ;
unsigned int V_13 = 0 , V_14 = 8000 ;
T_1 V_15 = 0 ;
V_12 = F_2 ( V_14 , V_16 ) ;
if ( V_12 == NULL )
return - V_17 ;
V_13 += F_3 ( V_12 + V_13 , V_14 - V_13 , L_1
L_2 ,
V_9 -> V_18 , V_9 -> V_19 ,
( V_6 -> V_10 -> V_20 . V_21 & V_22 ) ?
L_3 : L_4 ) ;
if ( ! V_6 -> V_23 ) {
V_13 += F_3 ( V_12 + V_13 , V_14 - V_13 ,
L_5 ) ;
goto exit;
}
V_24 = V_6 -> V_23 -> V_25 ( V_6 -> V_23 ) ;
V_13 += F_3 ( V_12 + V_13 , V_14 - V_13 , L_6 ) ;
F_4 ( L_7 , V_26 ) ;
F_4 ( L_8 , V_27 ) ;
F_4 ( L_9 , V_28 ) ;
F_4 ( L_10 , V_29 ) ;
F_4 ( L_11 , V_30 ) ;
F_4 ( L_12 , V_31 ) ;
F_4 ( L_13 , V_32 ) ;
F_4 ( L_14 , V_33 ) ;
F_4 ( L_15 , V_34 ) ;
V_13 += F_3 ( V_12 + V_13 , V_14 - V_13 , L_16
L_17 ,
V_6 -> V_23 -> V_35 ) ;
F_4 ( L_18 , V_36 ) ;
F_4 ( L_19 , V_37 ) ;
V_13 += F_3 ( V_12 + V_13 , V_14 - V_13 , L_20 ) ;
F_5 ( L_21 , V_38 ) ;
F_5 ( L_22 , V_39 ) ;
F_5 ( L_23 , V_40 ) ;
F_5 ( L_24 , V_41 ) ;
F_5 ( L_25 , V_42 ) ;
F_5 ( L_26 , V_43 ) ;
F_5 ( L_27 , V_44 ) ;
exit:
if ( V_13 > V_14 )
V_13 = V_14 ;
V_15 = F_6 ( V_2 , V_3 , V_4 , V_12 , V_13 ) ;
F_7 ( V_12 ) ;
return V_15 ;
}
static T_1 F_8 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
unsigned long V_45 ;
char V_12 [ 32 ] ;
T_1 V_13 ;
V_13 = F_9 ( V_3 , sizeof( V_12 ) - 1 ) ;
if ( F_10 ( V_12 , V_2 , V_13 ) )
return - V_46 ;
V_12 [ V_13 ] = '\0' ;
if ( F_11 ( V_12 , 0 , & V_45 ) )
return - V_47 ;
if ( V_45 == V_48 )
memset ( & V_6 -> V_49 . V_50 . V_51 , 0 ,
sizeof( V_6 -> V_49 . V_50 . V_51 ) ) ;
return V_3 ;
}
static T_1 F_12 ( struct V_1 * V_1 ,
const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
F_13 ( V_6 -> V_52 ) ;
return V_3 ;
}
void F_14 ( struct V_5 * V_6 )
{
F_15 ( L_28 , V_53 ,
V_6 -> V_49 . V_54 , V_6 , & V_55 ) ;
F_15 ( L_29 , V_56 ,
V_6 -> V_49 . V_54 , V_6 , & V_57 ) ;
}
