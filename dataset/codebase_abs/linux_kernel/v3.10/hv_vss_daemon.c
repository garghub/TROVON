static int F_1 ( char * V_1 , unsigned int V_2 , char * V_3 )
{
int V_4 , V_5 = F_2 ( V_1 , V_6 ) ;
if ( V_5 < 0 )
return 1 ;
V_4 = F_3 ( V_5 , V_2 , 0 ) ;
F_4 ( V_7 , L_1 , V_3 , V_1 , strerror ( V_8 ) ) ;
F_5 ( V_5 ) ;
return ! ! V_4 ;
}
static int F_6 ( int V_9 )
{
char * V_3 ;
char V_10 [] = L_2 ;
T_1 * V_11 ;
struct V_12 * V_13 ;
unsigned int V_2 ;
int error = 0 , V_14 = 0 ;
switch ( V_9 ) {
case V_15 :
V_2 = V_16 ;
V_3 = L_3 ;
break;
case V_17 :
V_2 = V_18 ;
V_3 = L_4 ;
break;
default:
return - 1 ;
}
V_11 = F_7 ( L_5 , L_6 ) ;
if ( V_11 == NULL )
return - 1 ;
while ( ( V_13 = F_8 ( V_11 ) ) ) {
if ( strncmp ( V_13 -> V_19 , V_10 , strlen ( V_10 ) ) )
continue;
if ( strcmp ( V_13 -> V_20 , L_7 ) == 0 )
continue;
if ( strcmp ( V_13 -> V_21 , L_8 ) == 0 ) {
V_14 = 1 ;
continue;
}
error |= F_1 ( V_13 -> V_21 , V_2 , V_3 ) ;
}
F_9 ( V_11 ) ;
if ( V_14 ) {
error |= F_1 ( L_8 , V_2 , V_3 ) ;
}
return error ;
}
static int F_10 ( int V_5 , struct V_22 * V_23 )
{
struct V_24 * V_25 ;
unsigned int V_26 ;
struct V_27 V_28 ;
char V_29 [ 64 ] ;
struct V_30 V_31 [ 2 ] ;
V_26 = F_11 ( sizeof( struct V_22 ) + V_23 -> V_32 ) ;
V_25 = (struct V_24 * ) V_29 ;
V_25 -> V_33 = 0 ;
V_25 -> V_34 = F_12 () ;
V_25 -> V_35 = V_36 ;
V_25 -> V_37 = F_13 ( V_26 - sizeof( * V_25 ) ) ;
V_25 -> V_38 = 0 ;
V_31 [ 0 ] . V_39 = V_25 ;
V_31 [ 0 ] . V_40 = sizeof( * V_25 ) ;
V_31 [ 1 ] . V_39 = V_23 ;
V_31 [ 1 ] . V_40 = V_26 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_41 = & V_42 ;
V_28 . V_43 = sizeof( V_42 ) ;
V_28 . V_44 = V_31 ;
V_28 . V_45 = 2 ;
return F_14 ( V_5 , & V_28 , 0 ) ;
}
int main ( void )
{
int V_5 , V_32 , V_46 ;
int error ;
struct V_22 * V_28 ;
struct V_47 V_48 ;
struct V_24 * V_49 ;
struct V_22 * V_50 ;
int V_51 ;
struct V_52 * V_53 ;
if ( F_15 ( 1 , 0 ) )
return 1 ;
F_16 ( L_9 , 0 , V_54 ) ;
F_4 ( V_7 , L_10 , F_12 () ) ;
V_5 = F_17 ( V_55 , V_56 , V_57 ) ;
if ( V_5 < 0 ) {
F_4 ( V_58 , L_11 , V_5 ) ;
exit ( V_59 ) ;
}
V_42 . V_60 = V_55 ;
V_42 . V_61 = 0 ;
V_42 . V_62 = 0 ;
V_42 . V_63 = 0 ;
error = F_18 ( V_5 , (struct V_64 * ) & V_42 , sizeof( V_42 ) ) ;
if ( error < 0 ) {
F_4 ( V_58 , L_12 , error ) ;
F_5 ( V_5 ) ;
exit ( V_59 ) ;
}
V_46 = V_65 ;
F_19 ( V_5 , V_66 , V_67 , & V_46 , sizeof( V_46 ) ) ;
V_28 = (struct V_22 * ) V_68 ;
V_28 -> V_69 . V_70 = V_65 ;
V_28 -> V_69 . V_71 = V_72 ;
V_28 -> V_73 = 0 ;
V_53 = (struct V_52 * ) V_28 -> V_74 ;
V_53 -> V_75 . V_9 = V_76 ;
V_28 -> V_32 = sizeof( struct V_52 ) ;
V_32 = F_10 ( V_5 , V_28 ) ;
if ( V_32 < 0 ) {
F_4 ( V_58 , L_13 , V_32 ) ;
F_5 ( V_5 ) ;
exit ( V_59 ) ;
}
V_48 . V_5 = V_5 ;
while ( 1 ) {
struct V_64 * V_77 = (struct V_64 * ) & V_42 ;
T_2 V_78 = sizeof( V_42 ) ;
V_48 . V_79 = V_80 ;
V_48 . V_81 = 0 ;
F_20 ( & V_48 , 1 , - 1 ) ;
V_32 = F_21 ( V_5 , V_82 , sizeof( V_82 ) , 0 ,
V_77 , & V_78 ) ;
if ( V_32 < 0 ) {
F_4 ( V_58 , L_14 ,
V_42 . V_62 , V_8 , strerror ( V_8 ) ) ;
F_5 ( V_5 ) ;
return - 1 ;
}
if ( V_42 . V_62 ) {
F_4 ( V_83 ,
L_15 ,
V_42 . V_62 ) ;
continue;
}
V_49 = (struct V_24 * ) V_82 ;
if ( V_49 -> V_35 != V_36 )
continue;
V_50 = (struct V_22 * ) F_22 ( V_49 ) ;
V_53 = (struct V_52 * ) V_50 -> V_74 ;
V_51 = V_53 -> V_75 . V_9 ;
error = V_84 ;
switch ( V_51 ) {
case V_15 :
case V_17 :
error = F_6 ( V_51 ) ;
if ( error )
error = V_85 ;
break;
default:
F_4 ( V_58 , L_16 , V_51 ) ;
}
V_53 -> error = error ;
V_32 = F_10 ( V_5 , V_50 ) ;
if ( V_32 < 0 ) {
F_4 ( V_58 , L_17 , V_32 ) ;
exit ( V_59 ) ;
}
}
}
