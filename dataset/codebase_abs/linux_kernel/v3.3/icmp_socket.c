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
V_25 = F_23 ( V_23 , V_17 -> V_33 ) ;
error = F_24 ( V_22 , & V_17 -> V_29 , V_25 ) ;
F_7 ( V_17 ) ;
if ( error )
return - V_32 ;
return V_25 ;
}
static T_1 F_25 ( struct V_3 * V_3 , const char T_2 * V_34 ,
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
F_26 ( V_44 , V_12 ,
L_3
L_4 ) ;
return - V_30 ;
}
V_38 = F_27 ( V_12 ) ;
if ( ! V_38 ) {
V_35 = - V_32 ;
goto V_45;
}
if ( V_35 >= sizeof( struct V_41 ) )
V_25 = sizeof( struct V_41 ) ;
V_40 = F_28 ( V_25 + sizeof( struct V_46 ) ) ;
if ( ! V_40 ) {
V_35 = - V_7 ;
goto V_45;
}
F_29 ( V_40 , sizeof( struct V_46 ) ) ;
V_29 = (struct V_41 * ) F_30 ( V_40 , V_25 ) ;
if ( F_31 ( V_29 , V_34 , V_25 ) ) {
V_35 = - V_32 ;
goto V_47;
}
if ( V_29 -> V_48 != V_49 ) {
F_26 ( V_44 , V_12 ,
L_3
L_5 ) ;
V_35 = - V_30 ;
goto V_47;
}
if ( V_29 -> V_50 != V_51 ) {
F_26 ( V_44 , V_12 ,
L_3
L_6 ) ;
V_35 = - V_30 ;
goto V_47;
}
V_29 -> V_52 = V_5 -> V_11 ;
if ( V_29 -> V_53 != V_54 ) {
V_29 -> V_50 = V_55 ;
V_29 -> V_53 = V_54 ;
F_32 ( V_5 , V_29 , V_25 ) ;
goto V_47;
}
if ( F_33 ( & V_12 -> V_56 ) != V_57 )
goto V_58;
V_42 = F_34 ( V_12 , V_29 -> V_59 ) ;
if ( ! V_42 )
goto V_58;
V_43 = F_35 ( V_42 ) ;
if ( ! V_43 )
goto V_58;
if ( ! V_43 -> V_60 )
goto V_58;
if ( V_43 -> V_60 -> V_61 != V_62 )
goto V_58;
memcpy ( V_29 -> V_63 ,
V_38 -> V_64 -> V_65 , V_66 ) ;
if ( V_25 == sizeof( struct V_41 ) )
memcpy ( V_29 -> V_67 ,
V_43 -> V_60 -> V_64 -> V_65 , V_66 ) ;
F_36 ( V_40 , V_43 -> V_60 , V_43 -> V_68 ) ;
goto V_45;
V_58:
V_29 -> V_50 = V_69 ;
F_32 ( V_5 , V_29 , V_25 ) ;
V_47:
F_37 ( V_40 ) ;
V_45:
if ( V_38 )
F_38 ( V_38 ) ;
if ( V_43 )
F_39 ( V_43 ) ;
if ( V_42 )
F_40 ( V_42 ) ;
return V_35 ;
}
static unsigned int F_41 ( struct V_3 * V_3 , T_5 * V_70 )
{
struct V_5 * V_5 = V_3 -> V_16 ;
F_42 ( V_3 , & V_5 -> V_15 , V_70 ) ;
if ( V_5 -> V_10 > 0 )
return V_71 | V_72 ;
return 0 ;
}
int F_43 ( struct V_12 * V_12 )
{
struct V_73 * V_74 ;
if ( ! V_12 -> V_75 )
goto V_76;
V_74 = F_44 ( V_77 , V_78 | V_79 | V_80 ,
V_12 -> V_75 , V_12 , & V_81 ) ;
if ( V_74 )
goto V_76;
return 0 ;
V_76:
return 1 ;
}
static void F_32 ( struct V_5 * V_5 ,
struct V_41 * V_29 ,
T_3 V_33 )
{
struct V_17 * V_17 ;
V_17 = F_4 ( sizeof( * V_17 ) , V_82 ) ;
if ( ! V_17 )
return;
F_8 ( & V_17 -> V_21 ) ;
memcpy ( & V_17 -> V_29 , V_29 , V_33 ) ;
V_17 -> V_33 = V_33 ;
F_13 ( & V_5 -> V_14 ) ;
if ( ! V_1 [ V_29 -> V_52 ] ) {
F_17 ( & V_5 -> V_14 ) ;
F_7 ( V_17 ) ;
return;
}
F_45 ( & V_17 -> V_21 , & V_5 -> V_9 ) ;
V_5 -> V_10 ++ ;
if ( V_5 -> V_10 > 100 ) {
V_17 = F_22 ( & V_5 -> V_9 ,
struct V_17 , V_21 ) ;
F_16 ( & V_17 -> V_21 ) ;
F_7 ( V_17 ) ;
V_5 -> V_10 -- ;
}
F_17 ( & V_5 -> V_14 ) ;
F_46 ( & V_5 -> V_15 ) ;
}
void F_47 ( struct V_41 * V_29 ,
T_3 V_33 )
{
struct V_5 * V_83 = V_1 [ V_29 -> V_52 ] ;
if ( V_83 )
F_32 ( V_83 , V_29 , V_33 ) ;
}
