int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_6 ) ;
struct V_8 * V_9 = & V_2 -> V_10 ;
struct V_11 V_12 ;
int V_13 ;
if ( ! V_2 -> V_14 || ! V_2 -> V_15 )
return - V_16 ;
V_12 . V_17 = V_18 | V_19 | V_20 ;
V_12 . V_21 = V_22 ;
V_12 . V_23 = F_3 ( V_24 << 8 ) ;
V_12 . V_25 = F_3 ( 0 ) ;
V_12 . V_26 = F_3 ( sizeof( * V_9 ) ) ;
F_4 ( & V_2 -> V_27 ) ;
V_13 = V_2 -> V_14 -> V_28 ( & ( V_2 -> V_7 ) , & V_12 ) ;
F_5 ( & V_2 -> V_27 ) ;
if ( V_13 < 0 )
goto V_29;
V_4 = F_6 ( & V_6 -> V_30 , struct V_3 , V_31 ) ;
F_7 ( & V_4 -> V_31 ) ;
if ( V_4 -> V_12 . V_32 > sizeof( * V_9 ) ) {
V_13 = - V_33 ;
goto V_34;
}
memcpy ( V_9 , V_4 -> V_12 . V_35 , sizeof( * V_9 ) ) ;
V_2 -> V_36 = 1 ;
V_13 = 0 ;
V_34:
V_4 -> V_12 . V_37 = 0 ;
V_4 -> V_12 . V_38 = V_4 -> V_12 . V_32 ;
F_8 ( & ( V_6 -> V_39 ) , & ( V_4 -> V_12 ) ) ;
V_29:
return V_13 ;
}
static T_1 F_9 ( struct V_40 * V_40 , struct V_41 * V_42 ,
struct V_43 * V_44 , char * V_29 ,
T_2 V_45 , T_3 V_46 )
{
struct V_47 * V_48 = F_10 ( V_42 ) ;
struct V_1 * V_2 = (struct V_1 * ) F_11 ( V_48 ) ;
char * V_49 = ( char * ) & V_2 -> V_10 ;
unsigned long V_50 ;
int V_13 ;
F_12 ( & V_2 -> V_27 , V_50 ) ;
if ( ! V_2 -> V_36 ) {
V_13 = - V_51 ;
goto V_52;
}
memcpy ( V_29 , V_49 + V_45 , V_46 ) ;
V_13 = V_46 ;
V_52:
F_13 ( & V_2 -> V_27 , V_50 ) ;
return V_13 ;
}
static T_1 F_14 ( struct V_47 * V_48 , struct V_53 * V_44 ,
const char * V_54 , T_3 V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) F_11 ( V_48 ) ;
int V_55 ;
int V_56 = 0 ;
int V_57 ;
struct V_58 * V_58 ;
unsigned long V_50 ;
int V_13 ;
V_55 = F_15 ( V_54 , 0 , & V_56 ) ;
if ( V_55 != 0 )
return - V_16 ;
F_12 ( & V_2 -> V_27 , V_50 ) ;
if ( ! V_2 || ! V_2 -> V_14 || ! V_2 -> V_15 ) {
F_16 ( V_48 , L_1 ) ;
V_13 = - V_51 ;
goto V_52;
}
if ( V_56 != - 1 ) {
if ( V_2 -> V_59 ) {
F_16 ( V_48 , L_2 ) ;
V_13 = - V_60 ;
goto V_52;
}
F_17 ( & V_2 -> V_61 . V_27 ) ;
if ( V_2 -> V_61 . V_37 != V_62 ) {
V_13 = - V_16 ;
goto V_63;
}
V_58 = F_18 ( V_56 , & V_57 ) ;
if ( ! V_58 ) {
F_16 ( V_48 , L_3 ) ;
V_13 = - V_16 ;
goto V_63;
}
V_2 -> V_61 . V_64 = V_58 ;
F_19 ( & V_2 -> V_61 . V_27 ) ;
F_13 ( & V_2 -> V_27 , V_50 ) ;
V_2 -> V_61 . V_65 = F_20 ( & V_66 ,
& V_2 -> V_61 , L_4 ) ;
V_2 -> V_61 . V_67 = F_20 ( & V_68 ,
& V_2 -> V_61 , L_5 ) ;
F_12 ( & V_2 -> V_27 , V_50 ) ;
F_17 ( & V_2 -> V_61 . V_27 ) ;
V_2 -> V_61 . V_37 = V_69 ;
F_19 ( & V_2 -> V_61 . V_27 ) ;
F_21 ( & V_2 -> V_70 ) ;
F_22 ( V_2 ) ;
V_2 -> V_59 = 1 ;
} else {
if ( ! V_2 -> V_59 ) {
F_16 ( V_48 , L_6 ) ;
V_13 = - V_16 ;
goto V_52;
}
F_17 ( & V_2 -> V_61 . V_27 ) ;
if ( V_2 -> V_61 . V_37 != V_69 ) {
V_13 = - V_16 ;
goto V_63;
}
F_19 ( & V_2 -> V_61 . V_27 ) ;
F_23 ( & V_2 -> V_61 , V_71 ) ;
}
F_13 ( & V_2 -> V_27 , V_50 ) ;
return V_46 ;
V_63:
F_19 ( & V_2 -> V_61 . V_27 ) ;
V_52:
F_13 ( & V_2 -> V_27 , V_50 ) ;
return V_13 ;
}
static T_1 F_24 ( struct V_47 * V_48 ,
struct V_53 * V_44 , char * V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) F_11 ( V_48 ) ;
int V_37 ;
if ( ! V_2 ) {
F_16 ( V_48 , L_7 ) ;
return - V_51 ;
}
F_17 ( & V_2 -> V_61 . V_27 ) ;
V_37 = V_2 -> V_61 . V_37 ;
F_19 ( & V_2 -> V_61 . V_27 ) ;
return snprintf ( V_29 , V_72 , L_8 , V_37 ) ;
}
