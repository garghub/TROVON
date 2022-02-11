static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 , int type )
{
struct V_6 * V_6 = & V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
void * V_17 ;
struct V_18 * V_19 ;
int V_20 = ( type & V_21 ) ? 0 : sizeof( struct V_22 ) ;
V_16 = F_3 ( V_2 ) ;
if ( V_16 < 0 )
goto V_23;
V_15 = V_16 ;
V_16 = - V_24 ;
V_12 = F_4 ( V_9 , V_15 + sizeof( struct V_18 ) + V_20 ,
V_25 , 0 ) ;
if ( ! V_12 )
goto V_23;
V_14 = F_5 ( V_12 ) ;
V_17 = V_14 + 1 ;
V_16 = F_6 ( V_2 , V_17 , V_15 ) ;
if ( V_16 < 0 )
goto V_26;
V_15 = V_16 ;
V_19 = V_17 + V_15 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_5 = V_5 ;
V_19 -> type = type ;
V_19 -> V_27 = V_2 -> V_27 ;
V_14 -> V_14 = V_28 ;
V_14 -> V_4 = 0 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_5 = sizeof( struct V_18 ) + V_15 + V_20 ;
V_14 -> V_29 = V_15 ;
V_14 -> V_30 = 0 ;
F_7 ( V_14 ) ;
F_8 ( V_19 ) ;
if ( V_20 ) {
struct V_22 * V_31 = (struct V_22 * ) ( V_19 + 1 ) ;
V_31 -> V_32 = V_6 -> V_33 ;
V_31 -> V_34 = V_6 -> V_35 ;
V_31 -> V_36 = V_6 -> V_37 ;
V_31 -> V_38 = V_6 -> V_39 ;
V_31 -> V_40 = V_6 -> V_41 ;
V_31 -> V_42 = V_6 -> V_43 ;
V_31 -> V_5 = V_6 -> V_44 ;
V_31 -> V_45 = V_6 -> V_46 ;
F_9 ( V_31 ) ;
}
F_10 ( V_14 , V_12 , V_15 + sizeof( struct V_18 ) + V_20 ) ;
return F_11 ( V_12 , V_9 ) ;
V_26:
F_12 ( V_12 ) ;
V_23:
F_13 ( L_1 , V_47 , V_16 ) ;
return V_16 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , int type )
{
struct V_8 * V_9 = F_2 ( V_2 -> V_7 . V_10 ) ;
struct V_48 * V_49 ;
int V_16 = - V_24 ;
struct V_50 V_50 ;
struct V_6 * V_6 = & V_2 -> V_7 ;
F_15 ( L_2
L_3 ,
V_47 , & V_2 -> V_7 , V_2 -> V_27 ,
V_4 , V_5 , type , V_2 -> V_51 ,
! ! F_16 ( V_52 , & V_2 -> V_53 ) ) ;
if ( ! F_17 ( V_2 , type ) )
return 0 ;
V_49 = F_18 ( V_9 , V_4 , V_5 , NULL ) ;
if ( F_19 ( V_49 ) )
return F_20 ( V_49 ) ;
V_16 = F_1 ( V_2 , V_49 -> V_54 , V_4 , V_5 ,
type | V_21 ) ;
if ( V_16 )
goto V_55;
V_16 = F_21 ( & V_49 -> V_56 , V_9 -> V_57 ) ;
if ( V_16 )
V_16 = V_49 -> V_16 ;
else
V_16 = - V_58 ;
if ( V_16 ) {
F_13 ( L_4 ,
V_47 , & V_2 -> V_7 , V_2 -> V_27 , V_49 -> V_54 , V_4 , V_5 , V_16 ) ;
}
if ( V_16 && ( V_16 != - V_59 ) )
goto V_55;
if ( ! V_16 ) {
F_9 ( & V_49 -> V_31 ) ;
V_50 . V_60 = V_61 | V_62 | V_63 | V_64 | V_65 ;
V_50 . V_66 = V_49 -> V_31 . V_32 ;
V_50 . V_67 = V_49 -> V_31 . V_36 ;
V_50 . V_68 = V_49 -> V_31 . V_38 ;
V_50 . V_69 = V_49 -> V_31 . V_5 ;
V_50 . V_70 = V_71 ;
F_15 ( L_5 ,
V_47 , & V_2 -> V_7 , V_2 -> V_27 , V_49 -> V_54 , V_4 , V_6 -> V_44 , V_49 -> V_31 . V_5 ) ;
V_16 = F_22 ( V_6 , & V_50 ) ;
if ( ! V_16 ) {
struct V_72 * V_72 = F_23 ( V_6 ) ;
if ( V_72 ) {
F_24 ( V_72 , V_50 . V_60 ) ;
F_25 ( V_72 ) ;
}
}
}
V_2 -> V_51 = type ;
F_26 ( V_52 , & V_2 -> V_53 ) ;
F_27 ( V_9 , V_49 ) ;
return 0 ;
V_55:
F_27 ( V_9 , V_49 ) ;
return V_16 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , int type )
{
F_15 ( L_6 ,
V_47 , & V_2 -> V_7 , V_2 -> V_27 , V_4 , V_5 , type ) ;
V_2 -> V_51 = 0 ;
F_29 ( V_73 , & V_2 -> V_53 ) ;
F_29 ( V_52 , & V_2 -> V_53 ) ;
return F_1 ( V_2 , V_2 -> V_27 , V_4 , V_5 , type ) ;
}
