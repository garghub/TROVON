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
case V_27 :
V_9 -> V_11 = V_7 -> V_28 ;
break;
default:
F_7 ( L_1 ,
V_9 -> V_9 ) ;
return - V_29 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_30 * V_31 =
(struct V_30 * ) V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_32 ;
T_1 T_2 * V_21 ;
void T_4 * V_33 = ( void T_4 * ) ( ( unsigned long ) ( V_31 -> V_33 ) ) ;
void * V_34 ;
int V_35 ;
if ( F_9 ( V_31 -> V_36 != 0 ) ) {
F_7 ( L_2 ) ;
return - V_29 ;
}
V_32 = ( V_37 - V_38 + 1 ) << 2 ;
if ( V_31 -> V_39 < V_32 )
V_32 = V_31 -> V_39 ;
V_34 = F_10 ( V_32 ) ;
if ( F_9 ( V_34 == NULL ) ) {
F_7 ( L_3 ) ;
return - V_40 ;
}
V_21 = V_7 -> V_22 ;
F_11 ( V_34 , & V_21 [ V_38 ] , V_32 ) ;
V_35 = F_12 ( V_33 , V_34 , V_32 ) ;
if ( V_35 )
V_35 = - V_41 ;
F_13 ( V_34 ) ;
if ( F_9 ( V_35 != 0 ) )
F_7 ( L_4 ) ;
return V_35 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_42 * V_43 = F_15 ( V_5 ) -> V_43 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_44 * V_31 =
(struct V_44 * ) V_3 ;
struct V_45 * V_46 ;
struct V_47 * V_48 = V_47 ( V_5 -> V_49 ) ;
struct V_50 T_4 * V_51 ;
struct V_50 * V_52 = NULL ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_3 V_59 ;
int V_35 ;
V_59 = V_31 -> V_59 ;
V_51 = (struct V_50 * ) ( unsigned long ) V_31 -> V_51 ;
if ( F_9 ( V_59 == 0 ) )
return 0 ;
if ( V_51 == NULL ) {
F_7 ( L_5 ) ;
V_35 = - V_29 ;
goto V_60;
}
V_52 = F_16 ( V_59 , sizeof( * V_52 ) , V_61 ) ;
if ( V_52 == NULL ) {
F_7 ( L_6 ) ;
V_35 = - V_40 ;
goto V_60;
}
V_35 = F_17 ( V_52 , V_51 , V_59 * sizeof( * V_52 ) ) ;
if ( V_35 ) {
F_7 ( L_7 ) ;
V_35 = - V_41 ;
goto V_62;
}
F_18 ( V_2 ) ;
V_54 = F_19 ( V_2 , V_31 -> V_63 ) ;
if ( ! V_54 ) {
F_7 ( L_8 ) ;
V_35 = - V_64 ;
goto V_65;
}
V_56 = F_20 ( V_54 ) ;
V_35 = F_21 ( & V_48 -> V_66 , true ) ;
if ( F_9 ( V_35 != 0 ) )
goto V_67;
V_35 = F_22 ( V_7 , V_43 , V_31 -> V_68 ,
V_69 ,
& V_58 ) ;
if ( V_35 )
goto V_70;
V_46 = F_23 ( V_58 ) ;
V_35 = F_24 ( V_7 , V_5 ,
V_56 , V_46 , V_31 -> V_68 ,
V_31 -> V_71 , V_31 -> V_72 ,
V_52 , V_59 ) ;
F_25 ( & V_46 ) ;
V_70:
F_26 ( & V_48 -> V_66 ) ;
V_67:
F_27 ( V_54 ) ;
V_65:
F_28 ( V_2 ) ;
V_62:
F_29 ( V_52 ) ;
V_60:
return V_35 ;
}
int F_30 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_73 * V_31 =
(struct V_73 * ) V_3 ;
struct V_74 T_4 * V_75 =
(struct V_74 T_4 * )
( unsigned long ) V_31 -> V_76 ;
struct V_47 * V_48 = V_47 ( V_5 -> V_49 ) ;
struct V_50 T_4 * V_51 ;
struct V_50 * V_52 = NULL ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_3 V_59 ;
int V_35 ;
V_59 = V_31 -> V_59 ;
V_51 = (struct V_50 * ) ( unsigned long ) V_31 -> V_51 ;
if ( F_9 ( V_59 == 0 ) )
return 0 ;
if ( V_51 == NULL ) {
F_7 ( L_9 ) ;
V_35 = - V_29 ;
goto V_60;
}
V_52 = F_16 ( V_59 , sizeof( * V_52 ) , V_61 ) ;
if ( V_52 == NULL ) {
F_7 ( L_6 ) ;
V_35 = - V_40 ;
goto V_60;
}
V_35 = F_17 ( V_52 , V_51 , V_59 * sizeof( * V_52 ) ) ;
if ( V_35 ) {
F_7 ( L_7 ) ;
V_35 = - V_41 ;
goto V_62;
}
F_18 ( V_2 ) ;
V_54 = F_19 ( V_2 , V_31 -> V_63 ) ;
if ( ! V_54 ) {
F_7 ( L_8 ) ;
V_35 = - V_64 ;
goto V_65;
}
V_56 = F_20 ( V_54 ) ;
if ( ! V_56 -> V_77 ) {
F_7 ( L_10 ) ;
V_35 = - V_29 ;
goto V_67;
}
V_35 = F_21 ( & V_48 -> V_66 , true ) ;
if ( F_9 ( V_35 != 0 ) )
goto V_67;
V_35 = F_31 ( V_7 , V_5 ,
V_56 , V_75 ,
V_52 , V_59 ) ;
F_26 ( & V_48 -> V_66 ) ;
V_67:
F_27 ( V_54 ) ;
V_65:
F_28 ( V_2 ) ;
V_62:
F_29 ( V_52 ) ;
V_60:
return V_35 ;
}
unsigned int F_32 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
struct V_4 * V_5 = V_79 -> V_82 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_83 -> V_2 ) ;
F_33 ( V_7 , V_84 ) ;
return F_34 ( V_79 , V_81 ) ;
}
T_5 F_35 ( struct V_78 * V_79 , char T_4 * V_33 ,
T_6 V_85 , T_7 * V_86 )
{
struct V_4 * V_5 = V_79 -> V_82 ;
struct V_6 * V_7 =
F_2 ( V_5 -> V_83 -> V_2 ) ;
F_33 ( V_7 , V_84 ) ;
return F_36 ( V_79 , V_33 , V_85 , V_86 ) ;
}
