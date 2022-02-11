static int F_1 ( char * V_1 , unsigned int V_2 )
{
int V_3 , V_4 = F_2 ( V_1 , V_5 ) ;
if ( V_4 < 0 )
return 1 ;
V_3 = F_3 ( V_4 , V_2 , 0 ) ;
if ( V_3 ) {
if ( ( V_2 == V_6 && V_7 == V_8 ) ||
( V_2 == V_9 && V_7 == V_10 ) ) {
F_4 ( V_4 ) ;
return 0 ;
}
}
F_4 ( V_4 ) ;
return ! ! V_3 ;
}
static int F_5 ( int V_11 )
{
char V_12 [] = L_1 ;
T_1 * V_13 ;
struct V_14 * V_15 ;
unsigned int V_2 ;
int error = 0 , V_16 = 0 , V_17 = 0 ;
switch ( V_11 ) {
case V_18 :
V_2 = V_6 ;
break;
case V_19 :
V_2 = V_9 ;
break;
default:
return - 1 ;
}
V_13 = F_6 ( L_2 , L_3 ) ;
if ( V_13 == NULL )
return - 1 ;
while ( ( V_15 = F_7 ( V_13 ) ) ) {
if ( strncmp ( V_15 -> V_20 , V_12 , strlen ( V_12 ) ) )
continue;
if ( F_8 ( V_15 , V_21 ) != NULL )
continue;
if ( strcmp ( V_15 -> V_22 , L_4 ) == 0 )
continue;
if ( strcmp ( V_15 -> V_23 , L_5 ) == 0 ) {
V_16 = 1 ;
continue;
}
error |= F_1 ( V_15 -> V_23 , V_2 ) ;
if ( error && V_11 == V_18 )
goto V_24;
}
if ( V_16 ) {
error |= F_1 ( L_5 , V_2 ) ;
if ( error && V_11 == V_18 )
goto V_24;
}
goto V_25;
V_24:
V_17 = V_7 ;
F_5 ( V_19 ) ;
if ( V_15 )
F_9 ( V_26 , L_6 ,
V_15 -> V_23 , V_17 , strerror ( V_17 ) ) ;
else
F_9 ( V_26 , L_7 , V_17 ,
strerror ( V_17 ) ) ;
V_25:
F_10 ( V_13 ) ;
return error ;
}
static int F_11 ( int V_4 , struct V_27 * V_28 )
{
struct V_29 V_30 = { . V_31 = V_32 } ;
unsigned int V_33 ;
struct V_34 V_35 ;
struct V_36 V_37 [ 2 ] ;
V_33 = sizeof( struct V_27 ) + V_28 -> V_38 ;
V_30 . V_39 = F_12 () ;
V_30 . V_40 = F_13 ( V_33 ) ;
V_37 [ 0 ] . V_41 = & V_30 ;
V_37 [ 0 ] . V_42 = sizeof( V_30 ) ;
V_37 [ 1 ] . V_41 = V_28 ;
V_37 [ 1 ] . V_42 = V_33 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_43 = & V_44 ;
V_35 . V_45 = sizeof( V_44 ) ;
V_35 . V_46 = V_37 ;
V_35 . V_47 = 2 ;
return F_14 ( V_4 , & V_35 , 0 ) ;
}
void F_15 ( char * V_48 [] )
{
fprintf ( V_49 , L_8
L_9
L_10
L_11 , V_48 [ 0 ] ) ;
}
int main ( int V_50 , char * V_48 [] )
{
int V_4 , V_38 , V_51 ;
int error ;
struct V_27 * V_35 ;
struct V_52 V_53 ;
struct V_29 * V_54 ;
struct V_27 * V_55 ;
int V_56 ;
struct V_57 * V_58 ;
char * V_59 ;
T_2 V_60 ;
int V_61 = 1 , V_62 = 0 , V_63 ;
static struct V_64 V_65 [] = {
{ L_12 , V_66 , 0 , 'h' } ,
{ L_13 , V_66 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_63 = F_16 ( V_50 , V_48 , L_14 , V_65 ,
& V_62 ) ) != - 1 ) {
switch ( V_63 ) {
case 'n' :
V_61 = 0 ;
break;
case 'h' :
default:
F_15 ( V_48 ) ;
exit ( V_67 ) ;
}
}
if ( V_61 && F_17 ( 1 , 0 ) )
return 1 ;
F_18 ( L_15 , 0 , V_68 ) ;
F_9 ( V_69 , L_16 , F_12 () ) ;
V_60 = F_13 ( 0 ) + sizeof( struct V_27 ) + sizeof( struct V_57 ) ;
V_59 = calloc ( 1 , V_60 ) ;
if ( ! V_59 ) {
F_9 ( V_26 , L_17 ) ;
exit ( V_67 ) ;
}
V_4 = F_19 ( V_70 , V_71 , V_72 ) ;
if ( V_4 < 0 ) {
F_9 ( V_26 , L_18 ,
V_7 , strerror ( V_7 ) ) ;
exit ( V_67 ) ;
}
V_44 . V_73 = V_70 ;
V_44 . V_74 = 0 ;
V_44 . V_75 = 0 ;
V_44 . V_76 = 0 ;
error = F_20 ( V_4 , (struct V_77 * ) & V_44 , sizeof( V_44 ) ) ;
if ( error < 0 ) {
F_9 ( V_26 , L_19 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
exit ( V_67 ) ;
}
V_51 = V_78 ;
if ( F_21 ( V_4 , V_79 , V_80 , & V_51 , sizeof( V_51 ) ) < 0 ) {
F_9 ( V_26 , L_20 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
exit ( V_67 ) ;
}
V_35 = (struct V_27 * ) V_59 ;
V_35 -> V_81 . V_82 = V_78 ;
V_35 -> V_81 . V_83 = V_84 ;
V_35 -> V_85 = 0 ;
V_58 = (struct V_57 * ) V_35 -> V_86 ;
V_58 -> V_87 . V_11 = V_88 ;
V_35 -> V_38 = sizeof( struct V_57 ) ;
V_38 = F_11 ( V_4 , V_35 ) ;
if ( V_38 < 0 ) {
F_9 ( V_26 , L_21 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
exit ( V_67 ) ;
}
V_53 . V_4 = V_4 ;
while ( 1 ) {
struct V_77 * V_89 = (struct V_77 * ) & V_44 ;
T_3 V_90 = sizeof( V_44 ) ;
V_53 . V_91 = V_92 ;
V_53 . V_93 = 0 ;
if ( F_22 ( & V_53 , 1 , - 1 ) < 0 ) {
F_9 ( V_26 , L_22 , V_7 , strerror ( V_7 ) ) ;
if ( V_7 == V_10 ) {
F_4 ( V_4 ) ;
exit ( V_67 ) ;
}
else
continue;
}
V_38 = F_23 ( V_4 , V_59 , V_60 , 0 ,
V_89 , & V_90 ) ;
if ( V_38 < 0 ) {
F_9 ( V_26 , L_23 ,
V_44 . V_75 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
return - 1 ;
}
if ( V_44 . V_75 ) {
F_9 ( V_94 ,
L_24 ,
V_44 . V_75 ) ;
continue;
}
V_54 = (struct V_29 * ) V_59 ;
if ( V_54 -> V_31 != V_32 )
continue;
V_55 = (struct V_27 * ) F_24 ( V_54 ) ;
V_58 = (struct V_57 * ) V_55 -> V_86 ;
V_56 = V_58 -> V_87 . V_11 ;
error = V_95 ;
switch ( V_56 ) {
case V_18 :
case V_19 :
error = F_5 ( V_56 ) ;
F_9 ( V_69 , L_25 ,
V_56 == V_18 ? L_26 : L_27 ,
error ? L_28 : L_29 ) ;
if ( error ) {
error = V_96 ;
F_9 ( V_26 , L_30 , V_56 ) ;
F_9 ( V_26 , L_31 ) ;
F_9 ( V_26 , L_32 ) ;
}
break;
default:
F_9 ( V_26 , L_33 , V_56 ) ;
}
V_58 -> error = error ;
V_38 = F_11 ( V_4 , V_55 ) ;
if ( V_38 < 0 ) {
F_9 ( V_26 , L_34 ,
V_7 , strerror ( V_7 ) ) ;
exit ( V_67 ) ;
}
}
}
