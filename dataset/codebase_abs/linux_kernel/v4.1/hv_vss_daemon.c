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
char V_16 [ 1024 ] = { 0 } ;
unsigned int V_2 ;
int error = 0 , V_17 = 0 , V_18 = 0 ;
switch ( V_11 ) {
case V_19 :
V_2 = V_6 ;
break;
case V_20 :
V_2 = V_9 ;
break;
default:
return - 1 ;
}
V_13 = F_6 ( L_2 , L_3 ) ;
if ( V_13 == NULL )
return - 1 ;
while ( ( V_15 = F_7 ( V_13 ) ) ) {
if ( strncmp ( V_15 -> V_21 , V_12 , strlen ( V_12 ) ) )
continue;
if ( F_8 ( V_15 , V_22 ) != NULL )
continue;
if ( strcmp ( V_15 -> V_23 , L_4 ) == 0 )
continue;
if ( strcmp ( V_15 -> V_24 , L_5 ) == 0 ) {
V_17 = 1 ;
continue;
}
error |= F_1 ( V_15 -> V_24 , V_2 ) ;
if ( error && V_11 == V_19 )
goto V_25;
}
F_9 ( V_13 ) ;
if ( V_17 ) {
error |= F_1 ( L_5 , V_2 ) ;
if ( error && V_11 == V_19 )
goto V_25;
}
goto V_26;
V_25:
V_18 = V_7 ;
if ( V_15 ) {
strncpy ( V_16 , V_15 -> V_24 , sizeof( V_16 ) - 1 ) ;
F_9 ( V_13 ) ;
}
F_5 ( V_20 ) ;
if ( V_15 )
F_10 ( V_27 , L_6 ,
V_16 , V_18 , strerror ( V_18 ) ) ;
else
F_10 ( V_27 , L_7 , V_18 ,
strerror ( V_18 ) ) ;
V_26:
return error ;
}
static int F_11 ( int V_4 , struct V_28 * V_29 )
{
struct V_30 V_31 = { . V_32 = V_33 } ;
unsigned int V_34 ;
struct V_35 V_36 ;
struct V_37 V_38 [ 2 ] ;
V_34 = sizeof( struct V_28 ) + V_29 -> V_39 ;
V_31 . V_40 = F_12 () ;
V_31 . V_41 = F_13 ( V_34 ) ;
V_38 [ 0 ] . V_42 = & V_31 ;
V_38 [ 0 ] . V_43 = sizeof( V_31 ) ;
V_38 [ 1 ] . V_42 = V_29 ;
V_38 [ 1 ] . V_43 = V_34 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_44 = & V_45 ;
V_36 . V_46 = sizeof( V_45 ) ;
V_36 . V_47 = V_38 ;
V_36 . V_48 = 2 ;
return F_14 ( V_4 , & V_36 , 0 ) ;
}
void F_15 ( char * V_49 [] )
{
fprintf ( V_50 , L_8
L_9
L_10
L_11 , V_49 [ 0 ] ) ;
}
int main ( int V_51 , char * V_49 [] )
{
int V_4 , V_39 , V_52 ;
int error ;
struct V_28 * V_36 ;
struct V_53 V_54 ;
struct V_30 * V_55 ;
struct V_28 * V_56 ;
int V_57 ;
struct V_58 * V_59 ;
char * V_60 ;
T_2 V_61 ;
int V_62 = 1 , V_63 = 0 , V_64 ;
static struct V_65 V_66 [] = {
{ L_12 , V_67 , 0 , 'h' } ,
{ L_13 , V_67 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_64 = F_16 ( V_51 , V_49 , L_14 , V_66 ,
& V_63 ) ) != - 1 ) {
switch ( V_64 ) {
case 'n' :
V_62 = 0 ;
break;
case 'h' :
default:
F_15 ( V_49 ) ;
exit ( V_68 ) ;
}
}
if ( V_62 && F_17 ( 1 , 0 ) )
return 1 ;
F_18 ( L_15 , 0 , V_69 ) ;
F_10 ( V_70 , L_16 , F_12 () ) ;
V_61 = F_13 ( 0 ) + sizeof( struct V_28 ) + sizeof( struct V_58 ) ;
V_60 = calloc ( 1 , V_61 ) ;
if ( ! V_60 ) {
F_10 ( V_27 , L_17 ) ;
exit ( V_68 ) ;
}
V_4 = F_19 ( V_71 , V_72 , V_73 ) ;
if ( V_4 < 0 ) {
F_10 ( V_27 , L_18 ,
V_7 , strerror ( V_7 ) ) ;
exit ( V_68 ) ;
}
V_45 . V_74 = V_71 ;
V_45 . V_75 = 0 ;
V_45 . V_76 = 0 ;
V_45 . V_77 = 0 ;
error = F_20 ( V_4 , (struct V_78 * ) & V_45 , sizeof( V_45 ) ) ;
if ( error < 0 ) {
F_10 ( V_27 , L_19 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
exit ( V_68 ) ;
}
V_52 = V_79 ;
if ( F_21 ( V_4 , V_80 , V_81 , & V_52 , sizeof( V_52 ) ) < 0 ) {
F_10 ( V_27 , L_20 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
exit ( V_68 ) ;
}
V_36 = (struct V_28 * ) V_60 ;
V_36 -> V_82 . V_83 = V_79 ;
V_36 -> V_82 . V_84 = V_85 ;
V_36 -> V_86 = 0 ;
V_59 = (struct V_58 * ) V_36 -> V_87 ;
V_59 -> V_88 . V_11 = V_89 ;
V_36 -> V_39 = sizeof( struct V_58 ) ;
V_39 = F_11 ( V_4 , V_36 ) ;
if ( V_39 < 0 ) {
F_10 ( V_27 , L_21 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
exit ( V_68 ) ;
}
V_54 . V_4 = V_4 ;
while ( 1 ) {
struct V_78 * V_90 = (struct V_78 * ) & V_45 ;
T_3 V_91 = sizeof( V_45 ) ;
V_54 . V_92 = V_93 ;
V_54 . V_94 = 0 ;
if ( F_22 ( & V_54 , 1 , - 1 ) < 0 ) {
F_10 ( V_27 , L_22 , V_7 , strerror ( V_7 ) ) ;
if ( V_7 == V_10 ) {
F_4 ( V_4 ) ;
exit ( V_68 ) ;
}
else
continue;
}
V_39 = F_23 ( V_4 , V_60 , V_61 , 0 ,
V_90 , & V_91 ) ;
if ( V_39 < 0 ) {
F_10 ( V_27 , L_23 ,
V_45 . V_76 , V_7 , strerror ( V_7 ) ) ;
F_4 ( V_4 ) ;
return - 1 ;
}
if ( V_45 . V_76 ) {
F_10 ( V_95 ,
L_24 ,
V_45 . V_76 ) ;
continue;
}
V_55 = (struct V_30 * ) V_60 ;
if ( V_55 -> V_32 != V_33 )
continue;
V_56 = (struct V_28 * ) F_24 ( V_55 ) ;
V_59 = (struct V_58 * ) V_56 -> V_87 ;
V_57 = V_59 -> V_88 . V_11 ;
error = V_96 ;
switch ( V_57 ) {
case V_19 :
case V_20 :
error = F_5 ( V_57 ) ;
F_10 ( V_70 , L_25 ,
V_57 == V_19 ? L_26 : L_27 ,
error ? L_28 : L_29 ) ;
if ( error ) {
error = V_97 ;
F_10 ( V_27 , L_30 , V_57 ) ;
F_10 ( V_27 , L_31 ) ;
F_10 ( V_27 , L_32 ) ;
}
break;
default:
F_10 ( V_27 , L_33 , V_57 ) ;
}
V_59 -> error = error ;
V_39 = F_11 ( V_4 , V_56 ) ;
if ( V_39 < 0 ) {
F_10 ( V_27 , L_34 ,
V_7 , strerror ( V_7 ) ) ;
exit ( V_68 ) ;
}
}
}
