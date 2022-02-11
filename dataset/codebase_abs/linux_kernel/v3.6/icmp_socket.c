void F_1 ( void )
{
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
}
static int F_2 ( struct V_2 * V_2 , struct V_3 * V_3 )
{
unsigned int V_4 ;
struct V_5 * V_6 ;
F_3 ( V_2 , V_3 ) ;
V_6 = F_4 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
for ( V_4 = 0 ; V_4 < F_5 ( V_1 ) ; V_4 ++ ) {
if ( ! V_1 [ V_4 ] ) {
V_1 [ V_4 ] = V_6 ;
break;
}
}
if ( V_4 == F_5 ( V_1 ) ) {
F_6 ( L_1 ) ;
F_7 ( V_6 ) ;
return - V_9 ;
}
F_8 ( & V_6 -> V_10 ) ;
V_6 -> V_11 = 0 ;
V_6 -> V_12 = V_4 ;
V_6 -> V_13 = V_2 -> V_14 ;
F_9 ( & V_6 -> V_15 ) ;
F_10 ( & V_6 -> V_16 ) ;
V_3 -> V_17 = V_6 ;
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_2 * V_2 , struct V_3 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 , * V_22 ;
F_13 ( & V_6 -> V_15 ) ;
F_14 (list_pos, list_pos_tmp, &socket_client->queue_list) {
V_19 = F_15 ( V_21 ,
struct V_18 , V_23 ) ;
F_16 ( V_21 ) ;
F_7 ( V_19 ) ;
}
V_1 [ V_6 -> V_12 ] = NULL ;
F_17 ( & V_6 -> V_15 ) ;
F_7 ( V_6 ) ;
F_18 () ;
return 0 ;
}
static T_1 F_19 ( struct V_3 * V_3 , char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
struct V_5 * V_6 = V_3 -> V_17 ;
struct V_18 * V_19 ;
T_3 V_27 ;
int error ;
if ( ( V_3 -> V_28 & V_29 ) && ( V_6 -> V_11 == 0 ) )
return - V_30 ;
if ( ( ! V_24 ) || ( V_25 < sizeof( struct V_31 ) ) )
return - V_32 ;
if ( ! F_20 ( V_33 , V_24 , V_25 ) )
return - V_34 ;
error = F_21 ( V_6 -> V_16 ,
V_6 -> V_11 ) ;
if ( error )
return error ;
F_13 ( & V_6 -> V_15 ) ;
V_19 = F_22 ( & V_6 -> V_10 ,
struct V_18 , V_23 ) ;
F_16 ( & V_19 -> V_23 ) ;
V_6 -> V_11 -- ;
F_17 ( & V_6 -> V_15 ) ;
V_27 = F_23 ( V_25 , V_19 -> V_35 ) ;
error = F_24 ( V_24 , & V_19 -> V_36 , V_27 ) ;
F_7 ( V_19 ) ;
if ( error )
return - V_34 ;
return V_27 ;
}
static T_1 F_25 ( struct V_3 * V_3 , const char T_2 * V_37 ,
T_3 V_38 , T_4 * V_39 )
{
struct V_5 * V_6 = V_3 -> V_17 ;
struct V_40 * V_13 = V_6 -> V_13 ;
struct V_41 * V_42 = NULL ;
struct V_43 * V_44 ;
struct V_45 * V_36 ;
struct V_46 * V_47 = NULL ;
struct V_48 * V_49 = NULL ;
T_3 V_27 = sizeof( struct V_31 ) ;
if ( V_38 < sizeof( struct V_31 ) ) {
F_26 ( V_50 , V_13 ,
L_2 ) ;
return - V_32 ;
}
V_42 = F_27 ( V_13 ) ;
if ( ! V_42 ) {
V_38 = - V_34 ;
goto V_51;
}
if ( V_38 >= sizeof( struct V_45 ) )
V_27 = sizeof( struct V_45 ) ;
V_44 = F_28 ( V_27 + V_52 ) ;
if ( ! V_44 ) {
V_38 = - V_8 ;
goto V_51;
}
F_29 ( V_44 , V_52 ) ;
V_36 = (struct V_45 * ) F_30 ( V_44 , V_27 ) ;
if ( F_31 ( V_36 , V_37 , V_27 ) ) {
V_38 = - V_34 ;
goto V_53;
}
if ( V_36 -> V_54 . V_55 != V_56 ) {
F_26 ( V_50 , V_13 ,
L_3 ) ;
V_38 = - V_32 ;
goto V_53;
}
if ( V_36 -> V_57 != V_58 ) {
F_26 ( V_50 , V_13 ,
L_4 ) ;
V_38 = - V_32 ;
goto V_53;
}
V_36 -> V_59 = V_6 -> V_12 ;
if ( V_36 -> V_54 . V_60 != V_61 ) {
V_36 -> V_57 = V_62 ;
V_36 -> V_54 . V_60 = V_61 ;
F_32 ( V_6 , V_36 ,
V_27 ) ;
goto V_53;
}
if ( F_33 ( & V_13 -> V_63 ) != V_64 )
goto V_65;
V_47 = F_34 ( V_13 , V_36 -> V_66 ) ;
if ( ! V_47 )
goto V_65;
V_49 = F_35 ( V_47 ) ;
if ( ! V_49 )
goto V_65;
if ( ! V_49 -> V_67 )
goto V_65;
if ( V_49 -> V_67 -> V_68 != V_69 )
goto V_65;
memcpy ( V_36 -> V_70 ,
V_42 -> V_71 -> V_72 , V_73 ) ;
if ( V_27 == sizeof( struct V_45 ) )
memcpy ( V_36 -> V_74 ,
V_49 -> V_67 -> V_71 -> V_72 , V_73 ) ;
F_36 ( V_44 , V_49 -> V_67 , V_49 -> V_75 ) ;
goto V_51;
V_65:
V_36 -> V_57 = V_76 ;
F_32 ( V_6 , V_36 , V_27 ) ;
V_53:
F_37 ( V_44 ) ;
V_51:
if ( V_42 )
F_38 ( V_42 ) ;
if ( V_49 )
F_39 ( V_49 ) ;
if ( V_47 )
F_40 ( V_47 ) ;
return V_38 ;
}
static unsigned int F_41 ( struct V_3 * V_3 , T_5 * V_77 )
{
struct V_5 * V_6 = V_3 -> V_17 ;
F_42 ( V_3 , & V_6 -> V_16 , V_77 ) ;
if ( V_6 -> V_11 > 0 )
return V_78 | V_79 ;
return 0 ;
}
int F_43 ( struct V_40 * V_13 )
{
struct V_80 * V_81 ;
if ( ! V_13 -> V_82 )
goto V_83;
V_81 = F_44 ( V_84 , V_85 | V_86 | V_87 ,
V_13 -> V_82 , V_13 , & V_88 ) ;
if ( ! V_81 )
goto V_83;
return 0 ;
V_83:
return - V_8 ;
}
static void F_32 ( struct V_5 * V_6 ,
struct V_45 * V_36 ,
T_3 V_35 )
{
struct V_18 * V_19 ;
V_19 = F_4 ( sizeof( * V_19 ) , V_89 ) ;
if ( ! V_19 )
return;
F_8 ( & V_19 -> V_23 ) ;
memcpy ( & V_19 -> V_36 , V_36 , V_35 ) ;
V_19 -> V_35 = V_35 ;
F_13 ( & V_6 -> V_15 ) ;
if ( ! V_1 [ V_36 -> V_59 ] ) {
F_17 ( & V_6 -> V_15 ) ;
F_7 ( V_19 ) ;
return;
}
F_45 ( & V_19 -> V_23 , & V_6 -> V_10 ) ;
V_6 -> V_11 ++ ;
if ( V_6 -> V_11 > 100 ) {
V_19 = F_22 ( & V_6 -> V_10 ,
struct V_18 ,
V_23 ) ;
F_16 ( & V_19 -> V_23 ) ;
F_7 ( V_19 ) ;
V_6 -> V_11 -- ;
}
F_17 ( & V_6 -> V_15 ) ;
F_46 ( & V_6 -> V_16 ) ;
}
void F_47 ( struct V_45 * V_36 ,
T_3 V_35 )
{
struct V_5 * V_90 ;
V_90 = V_1 [ V_36 -> V_59 ] ;
if ( V_90 )
F_32 ( V_90 , V_36 , V_35 ) ;
}
