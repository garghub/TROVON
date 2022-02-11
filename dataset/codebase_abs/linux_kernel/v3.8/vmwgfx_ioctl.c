int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 =
(struct V_8 * ) V_3 ;
switch ( V_9 -> V_9 ) {
case V_10 :
V_9 -> V_11 = F_3 ( V_7 ) ;
break;
case V_12 :
V_9 -> V_11 = F_4 ( V_7 ) ;
break;
case V_13 :
V_9 -> V_11 = F_5 ( V_7 ) ? 1 : 0 ;
break;
case V_14 :
V_9 -> V_11 = V_7 -> V_15 ;
break;
case V_16 :
V_9 -> V_11 = V_7 -> V_17 . V_15 ;
break;
case V_18 :
V_9 -> V_11 = V_7 -> V_19 ;
break;
case V_20 :
{
T_1 T_2 * V_21 = V_7 -> V_22 ;
const struct V_23 * V_17 = & V_7 -> V_17 ;
V_9 -> V_11 =
F_6 ( V_21 +
( ( V_17 -> V_15 &
V_24 ) ?
V_25 :
V_26 ) ) ;
break;
}
default:
F_7 ( L_1 ,
V_9 -> V_9 ) ;
return - V_27 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_28 * V_29 =
(struct V_28 * ) V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_30 ;
T_1 T_2 * V_21 ;
void T_4 * V_31 = ( void T_4 * ) ( ( unsigned long ) ( V_29 -> V_31 ) ) ;
void * V_32 ;
int V_33 ;
if ( F_9 ( V_29 -> V_34 != 0 ) ) {
F_7 ( L_2 ) ;
return - V_27 ;
}
V_30 = ( V_35 - V_36 + 1 ) << 2 ;
if ( V_29 -> V_37 < V_30 )
V_30 = V_29 -> V_37 ;
V_32 = F_10 ( V_30 ) ;
if ( F_9 ( V_32 == NULL ) ) {
F_7 ( L_3 ) ;
return - V_38 ;
}
V_21 = V_7 -> V_22 ;
F_11 ( V_32 , & V_21 [ V_36 ] , V_30 ) ;
V_33 = F_12 ( V_31 , V_32 , V_30 ) ;
if ( V_33 )
V_33 = - V_39 ;
F_13 ( V_32 ) ;
if ( F_9 ( V_33 != 0 ) )
F_7 ( L_4 ) ;
return V_33 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_40 * V_41 = F_15 ( V_5 ) -> V_41 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_42 * V_29 =
(struct V_42 * ) V_3 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = V_45 ( V_5 -> V_47 ) ;
struct V_48 T_4 * V_49 ;
struct V_48 * V_50 = NULL ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_3 V_57 ;
int V_33 ;
V_57 = V_29 -> V_57 ;
V_49 = (struct V_48 * ) ( unsigned long ) V_29 -> V_49 ;
if ( F_9 ( V_57 == 0 ) )
return 0 ;
if ( V_49 == NULL ) {
F_7 ( L_5 ) ;
V_33 = - V_27 ;
goto V_58;
}
V_50 = F_16 ( V_57 , sizeof( * V_50 ) , V_59 ) ;
if ( V_50 == NULL ) {
F_7 ( L_6 ) ;
V_33 = - V_38 ;
goto V_58;
}
V_33 = F_17 ( V_50 , V_49 , V_57 * sizeof( * V_50 ) ) ;
if ( V_33 ) {
F_7 ( L_7 ) ;
V_33 = - V_39 ;
goto V_60;
}
V_33 = F_18 ( & V_2 -> V_61 . V_62 ) ;
if ( F_9 ( V_33 != 0 ) ) {
V_33 = - V_63 ;
goto V_64;
}
V_52 = F_19 ( V_2 , V_29 -> V_65 , V_66 ) ;
if ( ! V_52 ) {
F_7 ( L_8 ) ;
V_33 = - V_27 ;
goto V_67;
}
V_54 = F_20 ( F_21 ( V_52 ) ) ;
V_33 = F_22 ( & V_46 -> V_68 , true ) ;
if ( F_9 ( V_33 != 0 ) )
goto V_69;
V_33 = F_23 ( V_7 , V_41 , V_29 -> V_70 ,
V_71 ,
& V_56 ) ;
if ( V_33 )
goto V_72;
V_44 = F_24 ( V_56 ) ;
V_33 = F_25 ( V_7 , V_5 ,
V_54 , V_44 , V_29 -> V_70 ,
V_29 -> V_73 , V_29 -> V_74 ,
V_50 , V_57 ) ;
F_26 ( & V_44 ) ;
V_72:
F_27 ( & V_46 -> V_68 ) ;
V_69:
V_67:
F_28 ( & V_2 -> V_61 . V_62 ) ;
V_64:
V_60:
F_29 ( V_50 ) ;
V_58:
return V_33 ;
}
int F_30 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_75 * V_29 =
(struct V_75 * ) V_3 ;
struct V_76 T_4 * V_77 =
(struct V_76 T_4 * )
( unsigned long ) V_29 -> V_78 ;
struct V_45 * V_46 = V_45 ( V_5 -> V_47 ) ;
struct V_48 T_4 * V_49 ;
struct V_48 * V_50 = NULL ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_3 V_57 ;
int V_33 ;
V_57 = V_29 -> V_57 ;
V_49 = (struct V_48 * ) ( unsigned long ) V_29 -> V_49 ;
if ( F_9 ( V_57 == 0 ) )
return 0 ;
if ( V_49 == NULL ) {
F_7 ( L_9 ) ;
V_33 = - V_27 ;
goto V_58;
}
V_50 = F_16 ( V_57 , sizeof( * V_50 ) , V_59 ) ;
if ( V_50 == NULL ) {
F_7 ( L_6 ) ;
V_33 = - V_38 ;
goto V_58;
}
V_33 = F_17 ( V_50 , V_49 , V_57 * sizeof( * V_50 ) ) ;
if ( V_33 ) {
F_7 ( L_7 ) ;
V_33 = - V_39 ;
goto V_60;
}
V_33 = F_18 ( & V_2 -> V_61 . V_62 ) ;
if ( F_9 ( V_33 != 0 ) ) {
V_33 = - V_63 ;
goto V_64;
}
V_52 = F_19 ( V_2 , V_29 -> V_65 , V_66 ) ;
if ( ! V_52 ) {
F_7 ( L_8 ) ;
V_33 = - V_27 ;
goto V_67;
}
V_54 = F_20 ( F_21 ( V_52 ) ) ;
if ( ! V_54 -> V_79 ) {
F_7 ( L_10 ) ;
V_33 = - V_27 ;
goto V_67;
}
V_33 = F_22 ( & V_46 -> V_68 , true ) ;
if ( F_9 ( V_33 != 0 ) )
goto V_69;
V_33 = F_31 ( V_7 , V_5 ,
V_54 , V_77 ,
V_50 , V_57 ) ;
F_27 ( & V_46 -> V_68 ) ;
V_69:
V_67:
F_28 ( & V_2 -> V_61 . V_62 ) ;
V_64:
V_60:
F_29 ( V_50 ) ;
V_58:
return V_33 ;
}
unsigned int F_32 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
struct V_4 * V_5 = V_81 -> V_84 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_85 -> V_2 ) ;
F_33 ( V_7 , V_86 ) ;
return F_34 ( V_81 , V_83 ) ;
}
T_5 F_35 ( struct V_80 * V_81 , char T_4 * V_31 ,
T_6 V_87 , T_7 * V_88 )
{
struct V_4 * V_5 = V_81 -> V_84 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_85 -> V_2 ) ;
F_33 ( V_7 , V_86 ) ;
return F_36 ( V_81 , V_31 , V_87 , V_88 ) ;
}
