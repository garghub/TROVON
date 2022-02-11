void F_1 ( void )
{
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
}
static int F_2 ( struct V_2 * V_2 , struct V_3 * V_3 )
{
unsigned int V_4 ;
struct V_5 * V_6 ;
if ( ! F_3 ( V_7 ) )
return - V_8 ;
F_4 ( V_2 , V_3 ) ;
V_6 = F_5 ( sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 ) {
F_6 ( V_7 ) ;
return - V_10 ;
}
for ( V_4 = 0 ; V_4 < F_7 ( V_1 ) ; V_4 ++ ) {
if ( ! V_1 [ V_4 ] ) {
V_1 [ V_4 ] = V_6 ;
break;
}
}
if ( V_4 == F_7 ( V_1 ) ) {
F_8 ( L_1 ) ;
F_9 ( V_6 ) ;
F_6 ( V_7 ) ;
return - V_11 ;
}
F_10 ( & V_6 -> V_12 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = V_4 ;
V_6 -> V_15 = V_2 -> V_16 ;
F_11 ( & V_6 -> V_17 ) ;
F_12 ( & V_6 -> V_18 ) ;
V_3 -> V_19 = V_6 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_2 , struct V_3 * V_3 )
{
struct V_5 * V_20 = V_3 -> V_19 ;
struct V_21 * V_22 , * V_23 ;
F_14 ( & V_20 -> V_17 ) ;
F_15 (packet, tmp, &client->queue_list, list) {
F_16 ( & V_22 -> V_24 ) ;
F_9 ( V_22 ) ;
}
V_1 [ V_20 -> V_14 ] = NULL ;
F_17 ( & V_20 -> V_17 ) ;
F_9 ( V_20 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_3 * V_3 , char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
struct V_5 * V_6 = V_3 -> V_19 ;
struct V_21 * V_28 ;
T_3 V_29 ;
int error ;
if ( ( V_3 -> V_30 & V_31 ) && ( V_6 -> V_13 == 0 ) )
return - V_32 ;
if ( ( ! V_25 ) || ( V_26 < sizeof( struct V_33 ) ) )
return - V_34 ;
if ( ! F_19 ( V_35 , V_25 , V_26 ) )
return - V_36 ;
error = F_20 ( V_6 -> V_18 ,
V_6 -> V_13 ) ;
if ( error )
return error ;
F_14 ( & V_6 -> V_17 ) ;
V_28 = F_21 ( & V_6 -> V_12 ,
struct V_21 , V_24 ) ;
F_16 ( & V_28 -> V_24 ) ;
V_6 -> V_13 -- ;
F_17 ( & V_6 -> V_17 ) ;
V_29 = F_22 ( V_26 , V_28 -> V_37 ) ;
error = F_23 ( V_25 , & V_28 -> V_38 , V_29 ) ;
F_9 ( V_28 ) ;
if ( error )
return - V_36 ;
return V_29 ;
}
static T_1 F_24 ( struct V_3 * V_3 , const char T_2 * V_39 ,
T_3 V_40 , T_4 * V_41 )
{
struct V_5 * V_6 = V_3 -> V_19 ;
struct V_42 * V_15 = V_6 -> V_15 ;
struct V_43 * V_44 = NULL ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 = NULL ;
struct V_53 * V_54 = NULL ;
T_3 V_29 = sizeof( struct V_33 ) ;
T_5 * V_55 ;
if ( V_40 < sizeof( struct V_49 ) ) {
F_25 ( V_56 , V_15 ,
L_2 ) ;
return - V_34 ;
}
V_44 = F_26 ( V_15 ) ;
if ( ! V_44 ) {
V_40 = - V_36 ;
goto V_57;
}
if ( V_40 >= V_58 )
V_29 = V_58 ;
else
V_29 = V_40 ;
V_46 = F_27 ( NULL , V_29 + V_59 ) ;
if ( ! V_46 ) {
V_40 = - V_10 ;
goto V_57;
}
V_46 -> V_60 = V_61 ;
F_28 ( V_46 , V_59 ) ;
V_50 = (struct V_49 * ) F_29 ( V_46 , V_29 ) ;
if ( F_30 ( V_50 , V_39 , V_29 ) ) {
V_40 = - V_36 ;
goto V_62;
}
if ( V_50 -> V_63 != V_64 ) {
F_25 ( V_56 , V_15 ,
L_3 ) ;
V_40 = - V_34 ;
goto V_62;
}
switch ( V_50 -> V_65 ) {
case V_66 :
if ( V_40 < sizeof( struct V_33 ) ) {
F_25 ( V_56 , V_15 ,
L_2 ) ;
V_40 = - V_34 ;
goto V_62;
}
if ( F_31 ( & V_15 -> V_67 ) != V_68 )
goto V_69;
V_52 = F_32 ( V_15 , V_50 -> V_70 ) ;
if ( ! V_52 )
goto V_69;
V_54 = F_33 ( V_52 ,
V_71 ) ;
if ( ! V_54 )
goto V_69;
if ( ! V_54 -> V_72 )
goto V_69;
if ( V_54 -> V_72 -> V_73 != V_74 )
goto V_69;
V_48 = (struct V_47 * ) V_50 ;
if ( V_29 == sizeof( * V_48 ) ) {
V_55 = V_54 -> V_72 -> V_75 -> V_76 ;
F_34 ( V_48 -> V_77 [ 0 ] , V_55 ) ;
}
break;
default:
F_25 ( V_56 , V_15 ,
L_4 ) ;
V_40 = - V_34 ;
goto V_62;
}
V_50 -> V_78 = V_6 -> V_14 ;
if ( V_50 -> V_79 != V_80 ) {
V_50 -> V_65 = V_81 ;
V_50 -> V_79 = V_80 ;
F_35 ( V_6 , V_50 ,
V_29 ) ;
goto V_62;
}
F_34 ( V_50 -> V_82 , V_44 -> V_75 -> V_76 ) ;
F_36 ( V_46 , V_54 ) ;
goto V_57;
V_69:
V_50 -> V_65 = V_83 ;
F_35 ( V_6 , V_50 , V_29 ) ;
V_62:
F_37 ( V_46 ) ;
V_57:
if ( V_44 )
F_38 ( V_44 ) ;
if ( V_54 )
F_39 ( V_54 ) ;
if ( V_52 )
F_40 ( V_52 ) ;
return V_40 ;
}
static unsigned int F_41 ( struct V_3 * V_3 , T_6 * V_84 )
{
struct V_5 * V_6 = V_3 -> V_19 ;
F_42 ( V_3 , & V_6 -> V_18 , V_84 ) ;
if ( V_6 -> V_13 > 0 )
return V_85 | V_86 ;
return 0 ;
}
int F_43 ( struct V_42 * V_15 )
{
struct V_87 * V_88 ;
if ( ! V_15 -> V_89 )
goto V_90;
V_88 = F_44 ( V_91 , 0600 , V_15 -> V_89 ,
V_15 , & V_92 ) ;
if ( ! V_88 )
goto V_90;
return 0 ;
V_90:
return - V_10 ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_49 * V_93 ,
T_3 V_37 )
{
struct V_21 * V_28 ;
T_3 V_40 ;
V_28 = F_5 ( sizeof( * V_28 ) , V_94 ) ;
if ( ! V_28 )
return;
V_40 = V_37 ;
if ( V_40 > sizeof( V_28 -> V_38 ) )
V_40 = sizeof( V_28 -> V_38 ) ;
F_10 ( & V_28 -> V_24 ) ;
memcpy ( & V_28 -> V_38 , V_93 , V_40 ) ;
V_28 -> V_37 = V_40 ;
F_14 ( & V_6 -> V_17 ) ;
if ( ! V_1 [ V_93 -> V_78 ] ) {
F_17 ( & V_6 -> V_17 ) ;
F_9 ( V_28 ) ;
return;
}
F_45 ( & V_28 -> V_24 , & V_6 -> V_12 ) ;
V_6 -> V_13 ++ ;
if ( V_6 -> V_13 > 100 ) {
V_28 = F_21 ( & V_6 -> V_12 ,
struct V_21 ,
V_24 ) ;
F_16 ( & V_28 -> V_24 ) ;
F_9 ( V_28 ) ;
V_6 -> V_13 -- ;
}
F_17 ( & V_6 -> V_17 ) ;
F_46 ( & V_6 -> V_18 ) ;
}
void F_47 ( struct V_49 * V_93 ,
T_3 V_37 )
{
struct V_5 * V_95 ;
V_95 = V_1 [ V_93 -> V_78 ] ;
if ( V_95 )
F_35 ( V_95 , V_93 , V_37 ) ;
}
