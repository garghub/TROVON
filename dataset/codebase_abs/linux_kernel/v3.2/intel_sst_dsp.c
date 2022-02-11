static int F_1 ( void )
{
union V_1 V_2 ;
F_2 ( L_1 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_3 |= 0x382 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_8 = 0 ;
V_2 . V_7 . V_9 = 0x1 ;
V_2 . V_7 . V_10 = 0x7 ;
V_2 . V_7 . V_11 = 0x1 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
return 0 ;
}
static int F_5 ( void )
{
union V_1 V_2 ;
F_2 ( L_2 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_3 |= 0x382 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
return 0 ;
}
static int F_6 ( void )
{
union V_1 V_2 ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_10 = 0 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
V_2 . V_7 . V_9 = 0 ;
V_2 . V_7 . V_11 = 0 ;
V_2 . V_7 . V_8 = 1 ;
F_2 ( L_3 , V_2 . V_3 ) ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
return 0 ;
}
static int F_7 ( void )
{
union V_1 V_2 ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_10 = 0 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_12 = 1 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_9 = 0 ;
V_2 . V_7 . V_11 = 0 ;
F_2 ( L_4 , V_2 . V_3 ) ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
F_2 ( L_5 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
T_1 V_17 ;
void T_2 * V_18 ;
F_2 ( L_6 ,
V_14 -> V_19 , V_14 -> V_20 ,
V_14 -> V_21 , V_14 -> type ) ;
F_2 ( L_7 , V_14 -> V_22 ) ;
V_16 = ( void * ) V_14 + sizeof( * V_14 ) ;
for ( V_17 = 0 ; V_17 < V_14 -> V_21 ; V_17 ++ ) {
if ( V_16 -> V_23 <= 0 ) {
F_9 ( L_8 ) ;
return - V_24 ;
}
switch ( V_16 -> type ) {
case V_25 :
V_18 = V_4 -> V_26 ;
break;
case V_27 :
V_18 = V_4 -> V_28 ;
break;
default:
F_9 ( L_9 ,
V_16 -> type , V_17 ) ;
return - V_24 ;
}
F_10 ( V_18 + V_16 -> V_29 ,
( void * ) V_16 + sizeof( * V_16 ) , V_16 -> V_23 ) ;
V_16 = ( void * ) V_16 + sizeof( * V_16 ) + V_16 -> V_23 ;
}
return 0 ;
}
static int F_11 ( const struct V_30 * V_31 )
{
struct V_32 * V_33 ;
T_1 V_17 ;
int V_34 ;
struct V_13 * V_14 ;
F_12 ( ! V_31 ) ;
V_33 = (struct V_32 * ) V_31 -> V_35 ;
if ( ( strncmp ( V_33 -> V_19 , V_36 , 4 ) != 0 ) ||
( V_31 -> V_23 != V_33 -> V_37 + sizeof( * V_33 ) ) ) {
F_9 ( L_10 ) ;
return - V_24 ;
}
F_2 ( L_11 ,
V_33 -> V_19 , V_33 -> V_37 , V_33 -> V_38 ,
V_33 -> V_39 , sizeof( * V_33 ) ) ;
V_14 = ( void * ) V_31 -> V_35 + sizeof( * V_33 ) ;
for ( V_17 = 0 ; V_17 < V_33 -> V_38 ; V_17 ++ ) {
V_34 = F_8 ( V_14 ) ;
if ( V_34 )
return V_34 ;
V_14 = ( void * ) V_14 + sizeof( * V_14 ) + V_14 -> V_20 ;
}
return 0 ;
}
int F_13 ( const struct V_30 * V_40 , void * V_41 )
{
int V_34 ;
F_2 ( L_12 ) ;
F_12 ( ! V_40 ) ;
if ( V_4 -> V_42 == V_43 )
V_34 = F_1 () ;
else if ( V_4 -> V_42 == V_44 )
V_34 = F_5 () ;
if ( V_34 )
return V_34 ;
V_34 = F_11 ( V_40 ) ;
if ( V_34 )
return V_34 ;
F_14 ( & V_4 -> V_45 ) ;
V_4 -> V_46 = V_47 ;
F_15 ( & V_4 -> V_45 ) ;
if ( V_4 -> V_42 == V_43 )
V_34 = F_6 () ;
else if ( V_4 -> V_42 == V_44 )
V_34 = F_7 () ;
if ( V_34 )
return V_34 ;
F_2 ( L_13 ) ;
return V_34 ;
}
static int F_16 ( const struct V_30 * V_48 ,
struct V_49 * V_50 )
{
int V_51 ;
T_3 V_52 ;
struct V_53 * V_54 = NULL ;
union V_1 V_2 ;
struct V_55 V_56 = { 0 } ;
int V_57 = 0 ;
if ( F_17 ( & V_54 ) )
return - V_58 ;
V_52 = F_18 ( V_4 ) ;
V_51 = F_19 ( V_4 ) ;
F_2 ( L_14 , V_51 , V_52 ) ;
if ( V_51 < 0 ) {
F_20 ( V_54 ) ;
return - V_58 ;
}
V_4 -> V_59 [ V_51 ] . V_60 = V_52 ;
F_21 ( & V_54 -> V_33 , V_61 , 1 , V_52 ) ;
V_54 -> V_33 . V_7 . V_35 = sizeof( T_1 ) + sizeof( V_56 ) ;
V_56 . V_62 = V_50 -> V_63 . V_64 . V_65 ;
memcpy ( V_54 -> V_66 , & V_54 -> V_33 , sizeof( T_1 ) ) ;
memcpy ( V_54 -> V_66 + sizeof( T_1 ) , & V_56 , sizeof( V_56 ) ) ;
F_22 ( & V_4 -> V_67 ) ;
F_23 ( & V_54 -> V_68 , & V_4 -> V_69 ) ;
F_24 ( & V_4 -> V_67 ) ;
F_25 ( & V_4 -> V_70 ) ;
V_57 = F_26 ( V_4 , & V_4 -> V_59 [ V_51 ] ) ;
if ( V_57 ) {
V_4 -> V_59 [ V_51 ] . V_60 = V_71 ;
F_9 ( L_15 ,
V_57 ) ;
return - V_72 ;
}
F_2 ( L_16 ) ;
F_14 ( & V_4 -> V_45 ) ;
V_4 -> V_46 = V_47 ;
F_15 ( & V_4 -> V_45 ) ;
V_2 . V_3 = F_27 ( V_4 -> V_5 + V_6 ) ;
V_2 . V_7 . V_9 = 1 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_10 = 0x7 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
F_11 ( V_48 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_10 = 0x0 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
V_2 . V_3 = F_3 ( V_4 -> V_5 , V_6 ) ;
V_2 . V_7 . V_9 = 0 ;
F_4 ( V_4 -> V_5 , V_6 , V_2 . V_3 ) ;
if ( F_17 ( & V_54 ) ) {
V_4 -> V_59 [ V_51 ] . V_60 = V_71 ;
return - V_58 ;
}
F_21 ( & V_54 -> V_33 , V_73 , 1 , V_52 ) ;
V_4 -> V_59 [ V_51 ] . V_60 = V_52 ;
V_54 -> V_33 . V_7 . V_35 = sizeof( T_1 ) + sizeof( * V_50 ) ;
V_50 -> V_52 = V_52 ;
memcpy ( V_54 -> V_66 , & V_54 -> V_33 , sizeof( T_1 ) ) ;
memcpy ( V_54 -> V_66 + sizeof( T_1 ) , V_50 , sizeof( * V_50 ) ) ;
F_22 ( & V_4 -> V_67 ) ;
F_23 ( & V_54 -> V_68 , & V_4 -> V_69 ) ;
F_24 ( & V_4 -> V_67 ) ;
F_25 ( & V_4 -> V_70 ) ;
F_2 ( L_17 ) ;
V_4 -> V_59 [ V_51 ] . V_74 . V_75 = false ;
V_57 = F_26 ( V_4 , & V_4 -> V_59 [ V_51 ] ) ;
if ( V_57 ) {
F_14 ( & V_4 -> V_45 ) ;
V_4 -> V_46 = V_76 ;
F_15 ( & V_4 -> V_45 ) ;
V_4 -> V_59 [ V_51 ] . V_60 = V_71 ;
return - V_72 ;
}
F_2 ( L_18 ) ;
V_4 -> V_59 [ V_51 ] . V_60 = V_71 ;
F_14 ( & V_4 -> V_45 ) ;
V_4 -> V_46 = V_77 ;
F_15 ( & V_4 -> V_45 ) ;
return 0 ;
}
static int F_28 ( const struct V_30 * V_48 ,
struct V_78 * V_79 ,
T_1 * V_22 )
{
struct V_32 * V_33 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
unsigned int V_80 , V_81 = 0 , V_82 = 0 ;
int V_83 = 0 ;
V_33 = (struct V_32 * ) V_48 -> V_35 ;
if ( V_33 -> V_38 != 1 ) {
F_9 ( L_19 ) ;
V_83 = - V_24 ;
goto exit;
}
V_14 = ( void * ) V_48 -> V_35 + sizeof( * V_33 ) ;
* V_22 = V_14 -> V_22 ;
F_2 ( L_20 , * V_22 ) ;
F_2 ( L_21 ,
V_14 -> V_19 , V_14 -> V_20 ,
V_14 -> V_21 , V_14 -> type ) ;
V_16 = ( void * ) V_14 + sizeof( * V_14 ) ;
for ( V_80 = 0 ; V_80 < V_14 -> V_21 ; V_80 ++ ) {
switch ( V_16 -> type ) {
case V_25 :
V_81 += V_16 -> V_23 ;
break;
case V_27 :
V_82 += V_16 -> V_23 ;
break;
default:
F_9 ( L_22 , V_80 ) ;
V_83 = - V_24 ;
goto exit;
}
V_16 = ( void * ) V_16 + sizeof( * V_16 ) + V_16 -> V_23 ;
}
if ( V_81 > V_79 -> V_84 || V_82 > V_79 -> V_85 ) {
F_9 ( L_23 ) ;
V_83 = - V_24 ;
goto exit;
} else
F_2 ( L_24 ) ;
F_2 ( L_25 ,
V_81 , V_82 , V_79 -> V_84 , V_79 -> V_85 ) ;
exit:
return V_83 ;
}
int F_29 ( struct V_86 * V_50 , T_3 V_87 )
{
char V_88 [ 20 ] ;
const char * type , * V_89 ;
int V_90 = 0 , error = 0 ;
T_1 V_22 ;
const struct V_30 * V_48 ;
struct V_49 V_91 = { { { 0 } ,} ,} ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
F_2 ( L_26 ,
V_50 -> V_64 . V_65 , V_50 -> V_92 . V_93 , V_87 ) ;
F_2 ( L_27 ,
V_50 -> V_64 . V_94 , V_50 -> V_64 . V_95 ,
V_50 -> V_64 . V_96 , V_50 -> V_64 . V_97 ) ;
F_2 ( L_28 ,
V_50 -> V_92 . V_84 , V_50 -> V_92 . V_98 ) ;
F_2 ( L_29 ,
V_50 -> V_92 . V_85 , V_50 -> V_92 . V_99 ) ;
switch ( V_50 -> V_64 . V_65 ) {
case V_100 :
type = L_30 ;
break;
case V_101 :
type = L_31 ;
break;
case V_102 :
type = L_32 ;
break;
case V_103 :
type = L_33 ;
break;
case V_104 :
type = L_34 ;
break;
default:
F_9 ( L_35 ) ;
error = - V_24 ;
goto V_105;
}
if ( V_87 == V_106 )
V_89 = L_36 ;
else
V_89 = L_37 ;
V_90 = strlen ( type ) + strlen ( V_89 ) ;
strncpy ( V_88 , type , sizeof( V_88 ) - 1 ) ;
strncpy ( V_88 + strlen ( type ) , V_89 , sizeof( V_88 ) - strlen ( type ) - 1 ) ;
V_90 += snprintf ( V_88 + V_90 , sizeof( V_88 ) - V_90 , L_38 ,
V_50 -> V_92 . V_93 ) ;
V_90 += snprintf ( V_88 + V_90 , sizeof( V_88 ) - V_90 , L_39 ) ;
F_2 ( L_40 , V_88 ) ;
error = F_30 ( & V_48 , V_88 , & V_4 -> V_107 -> V_108 ) ;
if ( error ) {
F_9 ( L_41 , error ) ;
goto V_105;
}
error = F_28 ( V_48 , & V_50 -> V_92 , & V_22 ) ;
if ( error )
goto V_109;
V_50 -> V_110 = V_22 ;
memcpy ( & V_91 . V_63 , V_50 , sizeof( * V_50 ) ) ;
error = F_16 ( V_48 , & V_91 ) ;
if ( error )
goto V_109;
F_2 ( L_42 ) ;
V_109:
F_31 ( V_48 ) ;
V_105:
return error ;
}
