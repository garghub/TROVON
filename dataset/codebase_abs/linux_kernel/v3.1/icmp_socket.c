void F_1 ( void )
{
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
}
static int F_2 ( struct V_2 * V_2 , struct V_3 * V_3 )
{
unsigned int V_4 ;
struct V_5 * V_5 ;
F_3 ( V_2 , V_3 ) ;
V_5 = F_4 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
for ( V_4 = 0 ; V_4 < F_5 ( V_1 ) ; V_4 ++ ) {
if ( ! V_1 [ V_4 ] ) {
V_1 [ V_4 ] = V_5 ;
break;
}
}
if ( V_4 == F_5 ( V_1 ) ) {
F_6 ( L_1
L_2 ) ;
F_7 ( V_5 ) ;
return - V_8 ;
}
F_8 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = V_4 ;
V_5 -> V_12 = V_2 -> V_13 ;
F_9 ( & V_5 -> V_14 ) ;
F_10 ( & V_5 -> V_15 ) ;
V_3 -> V_16 = V_5 ;
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_2 * V_2 , struct V_3 * V_3 )
{
struct V_5 * V_5 = V_3 -> V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 , * V_20 ;
F_13 ( & V_5 -> V_14 ) ;
F_14 (list_pos, list_pos_tmp, &socket_client->queue_list) {
V_17 = F_15 ( V_19 ,
struct V_17 , V_21 ) ;
F_16 ( V_19 ) ;
F_7 ( V_17 ) ;
}
V_1 [ V_5 -> V_11 ] = NULL ;
F_17 ( & V_5 -> V_14 ) ;
F_7 ( V_5 ) ;
F_18 () ;
return 0 ;
}
static T_1 F_19 ( struct V_3 * V_3 , char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
struct V_5 * V_5 = V_3 -> V_16 ;
struct V_17 * V_17 ;
T_3 V_25 ;
int error ;
if ( ( V_3 -> V_26 & V_27 ) && ( V_5 -> V_10 == 0 ) )
return - V_28 ;
if ( ( ! V_22 ) || ( V_23 < sizeof( struct V_29 ) ) )
return - V_30 ;
if ( ! F_20 ( V_31 , V_22 , V_23 ) )
return - V_32 ;
error = F_21 ( V_5 -> V_15 ,
V_5 -> V_10 ) ;
if ( error )
return error ;
F_13 ( & V_5 -> V_14 ) ;
V_17 = F_22 ( & V_5 -> V_9 ,
struct V_17 , V_21 ) ;
F_16 ( & V_17 -> V_21 ) ;
V_5 -> V_10 -- ;
F_17 ( & V_5 -> V_14 ) ;
error = F_23 ( V_22 , & V_17 -> V_29 ,
V_17 -> V_33 ) ;
V_25 = V_17 -> V_33 ;
F_7 ( V_17 ) ;
if ( error )
return - V_32 ;
return V_25 ;
}
static T_1 F_24 ( struct V_3 * V_3 , const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_5 * V_5 = V_3 -> V_16 ;
struct V_12 * V_12 = V_5 -> V_12 ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
struct V_41 * V_29 ;
struct V_42 * V_42 = NULL ;
struct V_43 * V_43 = NULL ;
T_3 V_25 = sizeof( struct V_29 ) ;
if ( V_35 < sizeof( struct V_29 ) ) {
F_25 ( V_44 , V_12 ,
L_3
L_4 ) ;
return - V_30 ;
}
V_38 = F_26 ( V_12 ) ;
if ( ! V_38 ) {
V_35 = - V_32 ;
goto V_45;
}
if ( V_35 >= sizeof( struct V_41 ) )
V_25 = sizeof( struct V_41 ) ;
V_40 = F_27 ( V_25 + sizeof( struct V_46 ) ) ;
if ( ! V_40 ) {
V_35 = - V_7 ;
goto V_45;
}
F_28 ( V_40 , sizeof( struct V_46 ) ) ;
V_29 = (struct V_41 * ) F_29 ( V_40 , V_25 ) ;
if ( ! F_20 ( V_47 , V_34 , V_25 ) ) {
V_35 = - V_32 ;
goto V_48;
}
if ( F_30 ( V_29 , V_34 , V_25 ) ) {
V_35 = - V_32 ;
goto V_48;
}
if ( V_29 -> V_49 != V_50 ) {
F_25 ( V_44 , V_12 ,
L_3
L_5 ) ;
V_35 = - V_30 ;
goto V_48;
}
if ( V_29 -> V_51 != V_52 ) {
F_25 ( V_44 , V_12 ,
L_3
L_6 ) ;
V_35 = - V_30 ;
goto V_48;
}
V_29 -> V_53 = V_5 -> V_11 ;
if ( V_29 -> V_54 != V_55 ) {
V_29 -> V_51 = V_56 ;
V_29 -> V_57 = V_55 ;
F_31 ( V_5 , V_29 , V_25 ) ;
goto V_48;
}
if ( F_32 ( & V_12 -> V_58 ) != V_59 )
goto V_60;
V_42 = F_33 ( V_12 , V_29 -> V_61 ) ;
if ( ! V_42 )
goto V_60;
V_43 = F_34 ( V_42 ) ;
if ( ! V_43 )
goto V_60;
if ( ! V_43 -> V_62 )
goto V_60;
if ( V_43 -> V_62 -> V_63 != V_64 )
goto V_60;
memcpy ( V_29 -> V_65 ,
V_38 -> V_66 -> V_67 , V_68 ) ;
if ( V_25 == sizeof( struct V_41 ) )
memcpy ( V_29 -> V_69 ,
V_43 -> V_62 -> V_66 -> V_67 , V_68 ) ;
F_35 ( V_40 , V_43 -> V_62 , V_43 -> V_70 ) ;
goto V_45;
V_60:
V_29 -> V_51 = V_71 ;
F_31 ( V_5 , V_29 , V_25 ) ;
V_48:
F_36 ( V_40 ) ;
V_45:
if ( V_38 )
F_37 ( V_38 ) ;
if ( V_43 )
F_38 ( V_43 ) ;
if ( V_42 )
F_39 ( V_42 ) ;
return V_35 ;
}
static unsigned int F_40 ( struct V_3 * V_3 , T_5 * V_72 )
{
struct V_5 * V_5 = V_3 -> V_16 ;
F_41 ( V_3 , & V_5 -> V_15 , V_72 ) ;
if ( V_5 -> V_10 > 0 )
return V_73 | V_74 ;
return 0 ;
}
int F_42 ( struct V_12 * V_12 )
{
struct V_75 * V_76 ;
if ( ! V_12 -> V_77 )
goto V_78;
V_76 = F_43 ( V_79 , V_80 | V_81 | V_82 ,
V_12 -> V_77 , V_12 , & V_83 ) ;
if ( V_76 )
goto V_78;
return 0 ;
V_78:
return 1 ;
}
static void F_31 ( struct V_5 * V_5 ,
struct V_41 * V_29 ,
T_3 V_33 )
{
struct V_17 * V_17 ;
V_17 = F_4 ( sizeof( * V_17 ) , V_84 ) ;
if ( ! V_17 )
return;
F_8 ( & V_17 -> V_21 ) ;
memcpy ( & V_17 -> V_29 , V_29 , V_33 ) ;
V_17 -> V_33 = V_33 ;
F_13 ( & V_5 -> V_14 ) ;
if ( ! V_1 [ V_29 -> V_53 ] ) {
F_17 ( & V_5 -> V_14 ) ;
F_7 ( V_17 ) ;
return;
}
F_44 ( & V_17 -> V_21 , & V_5 -> V_9 ) ;
V_5 -> V_10 ++ ;
if ( V_5 -> V_10 > 100 ) {
V_17 = F_22 ( & V_5 -> V_9 ,
struct V_17 , V_21 ) ;
F_16 ( & V_17 -> V_21 ) ;
F_7 ( V_17 ) ;
V_5 -> V_10 -- ;
}
F_17 ( & V_5 -> V_14 ) ;
F_45 ( & V_5 -> V_15 ) ;
}
void F_46 ( struct V_41 * V_29 ,
T_3 V_33 )
{
struct V_5 * V_85 = V_1 [ V_29 -> V_53 ] ;
if ( V_85 )
F_31 ( V_85 , V_29 , V_33 ) ;
}
