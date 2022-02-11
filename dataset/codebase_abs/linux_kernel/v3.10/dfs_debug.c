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
V_13 += snprintf ( V_12 + V_13 , V_14 - V_13 , L_1
L_2 ,
V_9 -> V_18 , V_9 -> V_19 ,
( V_6 -> V_10 -> V_20 . V_21 & V_22 ) ?
L_3 : L_4 ) ;
V_13 += snprintf ( V_12 + V_13 , V_14 - V_13 , L_5 ) ;
F_3 ( L_6 , V_23 ) ;
F_3 ( L_7 , V_24 ) ;
F_3 ( L_8 , V_25 ) ;
F_3 ( L_9 , V_26 ) ;
F_3 ( L_10 , V_27 ) ;
F_3 ( L_11 , V_28 ) ;
F_3 ( L_12 , V_29 ) ;
F_3 ( L_13 , V_30 ) ;
F_3 ( L_14 , V_31 ) ;
V_13 += snprintf ( V_12 + V_13 , V_14 - V_13 , L_15
L_16 , V_6 -> V_32 -> V_33 ) ;
F_3 ( L_17 , V_34 ) ;
F_3 ( L_18 , V_35 ) ;
V_13 += snprintf ( V_12 + V_13 , V_14 - V_13 , L_19 ) ;
F_4 ( L_20 , V_36 ) ;
F_4 ( L_21 , V_37 ) ;
F_4 ( L_22 , V_38 ) ;
F_4 ( L_23 , V_39 ) ;
F_4 ( L_24 , V_40 ) ;
F_4 ( L_25 , V_41 ) ;
F_4 ( L_26 , V_42 ) ;
if ( V_13 > V_14 )
V_13 = V_14 ;
V_15 = F_5 ( V_2 , V_3 , V_4 , V_12 , V_13 ) ;
F_6 ( V_12 ) ;
return V_15 ;
}
static T_1 F_7 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
unsigned long V_43 ;
char V_12 [ 32 ] ;
T_1 V_13 ;
V_13 = F_8 ( V_3 , sizeof( V_12 ) - 1 ) ;
if ( F_9 ( V_12 , V_2 , V_13 ) )
return - V_44 ;
V_12 [ V_13 ] = '\0' ;
if ( F_10 ( V_12 , 0 , & V_43 ) )
return - V_45 ;
if ( V_43 == V_46 )
memset ( & V_6 -> V_47 . V_48 . V_49 , 0 ,
sizeof( V_6 -> V_47 . V_48 . V_49 ) ) ;
return V_3 ;
}
static T_1 F_11 ( struct V_1 * V_1 ,
const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
F_12 ( V_6 -> V_50 ) ;
return V_3 ;
}
void F_13 ( struct V_5 * V_6 )
{
F_14 ( L_27 , V_51 ,
V_6 -> V_47 . V_52 , V_6 , & V_53 ) ;
F_14 ( L_28 , V_54 ,
V_6 -> V_47 . V_52 , V_6 , & V_55 ) ;
}
