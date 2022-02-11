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
struct V_24 V_25 = { . V_26 = V_27 } ;
unsigned int V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 [ 2 ] ;
V_28 = sizeof( struct V_22 ) + V_23 -> V_33 ;
V_25 . V_34 = F_11 () ;
V_25 . V_35 = F_12 ( V_28 ) ;
V_32 [ 0 ] . V_36 = & V_25 ;
V_32 [ 0 ] . V_37 = sizeof( V_25 ) ;
V_32 [ 1 ] . V_36 = V_23 ;
V_32 [ 1 ] . V_37 = V_28 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_38 = & V_39 ;
V_30 . V_40 = sizeof( V_39 ) ;
V_30 . V_41 = V_32 ;
V_30 . V_42 = 2 ;
return F_13 ( V_5 , & V_30 , 0 ) ;
}
int main ( void )
{
int V_5 , V_33 , V_43 ;
int error ;
struct V_22 * V_30 ;
struct V_44 V_45 ;
struct V_24 * V_46 ;
struct V_22 * V_47 ;
int V_48 ;
struct V_49 * V_50 ;
char * V_51 ;
char * V_52 ;
T_2 V_53 ;
if ( F_14 ( 1 , 0 ) )
return 1 ;
F_15 ( L_9 , 0 , V_54 ) ;
F_4 ( V_7 , L_10 , F_11 () ) ;
V_53 = V_55 + sizeof( struct V_22 ) + sizeof( struct V_49 ) ;
V_51 = calloc ( 1 , V_53 ) ;
V_52 = calloc ( 1 , V_53 ) ;
if ( ! ( V_51 && V_52 ) ) {
F_4 ( V_56 , L_11 ) ;
exit ( V_57 ) ;
}
V_5 = F_16 ( V_58 , V_59 , V_60 ) ;
if ( V_5 < 0 ) {
F_4 ( V_56 , L_12 ,
V_8 , strerror ( V_8 ) ) ;
exit ( V_57 ) ;
}
V_39 . V_61 = V_58 ;
V_39 . V_62 = 0 ;
V_39 . V_63 = 0 ;
V_39 . V_64 = 0 ;
error = F_17 ( V_5 , (struct V_65 * ) & V_39 , sizeof( V_39 ) ) ;
if ( error < 0 ) {
F_4 ( V_56 , L_13 , V_8 , strerror ( V_8 ) ) ;
F_5 ( V_5 ) ;
exit ( V_57 ) ;
}
V_43 = V_66 ;
if ( F_18 ( V_5 , V_67 , V_68 , & V_43 , sizeof( V_43 ) ) < 0 ) {
F_4 ( V_56 , L_14 , V_8 , strerror ( V_8 ) ) ;
F_5 ( V_5 ) ;
exit ( V_57 ) ;
}
V_30 = (struct V_22 * ) V_51 ;
V_30 -> V_69 . V_70 = V_66 ;
V_30 -> V_69 . V_71 = V_72 ;
V_30 -> V_73 = 0 ;
V_50 = (struct V_49 * ) V_30 -> V_74 ;
V_50 -> V_75 . V_9 = V_76 ;
V_30 -> V_33 = sizeof( struct V_49 ) ;
V_33 = F_10 ( V_5 , V_30 ) ;
if ( V_33 < 0 ) {
F_4 ( V_56 , L_15 , V_8 , strerror ( V_8 ) ) ;
F_5 ( V_5 ) ;
exit ( V_57 ) ;
}
V_45 . V_5 = V_5 ;
while ( 1 ) {
struct V_65 * V_77 = (struct V_65 * ) & V_39 ;
T_3 V_78 = sizeof( V_39 ) ;
V_45 . V_79 = V_80 ;
V_45 . V_81 = 0 ;
if ( F_19 ( & V_45 , 1 , - 1 ) < 0 ) {
F_4 ( V_56 , L_16 , V_8 , strerror ( V_8 ) ) ;
if ( V_8 == V_82 ) {
F_5 ( V_5 ) ;
exit ( V_57 ) ;
}
else
continue;
}
V_33 = F_20 ( V_5 , V_52 , V_53 , 0 ,
V_77 , & V_78 ) ;
if ( V_33 < 0 ) {
F_4 ( V_56 , L_17 ,
V_39 . V_63 , V_8 , strerror ( V_8 ) ) ;
F_5 ( V_5 ) ;
return - 1 ;
}
if ( V_39 . V_63 ) {
F_4 ( V_83 ,
L_18 ,
V_39 . V_63 ) ;
continue;
}
V_46 = (struct V_24 * ) V_52 ;
if ( V_46 -> V_26 != V_27 )
continue;
V_47 = (struct V_22 * ) F_21 ( V_46 ) ;
V_50 = (struct V_49 * ) V_47 -> V_74 ;
V_48 = V_50 -> V_75 . V_9 ;
error = V_84 ;
switch ( V_48 ) {
case V_15 :
case V_17 :
error = F_6 ( V_48 ) ;
if ( error )
error = V_85 ;
break;
default:
F_4 ( V_56 , L_19 , V_48 ) ;
}
V_50 -> error = error ;
V_33 = F_10 ( V_5 , V_47 ) ;
if ( V_33 < 0 ) {
F_4 ( V_56 , L_20 ,
V_8 , strerror ( V_8 ) ) ;
exit ( V_57 ) ;
}
}
}
