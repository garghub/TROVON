struct V_1 * F_1 ( const char * V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
if ( ! strcmp ( V_4 [ V_3 ] -> V_2 , V_2 ) )
break;
}
return V_4 [ V_3 ] ;
}
static struct V_1 * F_2 ( T_2 type )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
if ( V_4 [ V_3 ] -> V_5 == type )
break;
}
return V_4 [ V_3 ] ;
}
void F_3 ( char * V_6 , int V_7 , struct V_8 * V_9 )
{
char V_10 [ V_11 ] ;
struct V_1 * V_12 ;
int V_13 ;
V_12 = F_2 ( V_9 -> V_14 ) ;
if ( V_12 && ! V_12 -> V_15 ( V_9 , V_10 , sizeof( V_10 ) ) )
V_13 = F_4 ( V_6 , V_7 , L_1 , V_12 -> V_2 , V_10 ) ;
else {
T_1 V_3 ;
V_13 = F_4 ( V_6 , V_7 , L_2 , V_9 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < sizeof( V_9 -> V_16 ) ; V_3 ++ )
V_13 += F_4 ( V_6 - V_13 , V_7 + V_13 ,
L_3 , V_9 -> V_16 [ V_3 ] ) ;
}
}
struct V_17 * F_5 ( void )
{
struct V_17 * V_6 ;
int V_3 ;
V_6 = F_6 ( V_18 * F_7 ( V_19 ) ) ;
if ( ! V_6 )
return NULL ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
F_8 ( V_6 , V_20 ,
V_4 [ V_3 ] -> V_2 ,
strlen ( V_4 [ V_3 ] -> V_2 ) + 1 ) ;
}
return V_6 ;
}
static int F_9 ( const char * V_2 ,
struct V_21 * V_22 )
{
char V_23 [ V_24 ] ;
char * V_25 ;
char * V_26 ;
T_1 V_27 ;
T_1 V_28 ;
V_23 [ V_24 - 1 ] = 0 ;
strncpy ( V_23 , V_2 , V_24 ) ;
if ( V_23 [ V_24 - 1 ] != 0 )
return 0 ;
V_25 = V_23 ;
V_26 = strchr ( V_25 , ':' ) ;
if ( V_26 == NULL )
return 0 ;
* ( V_26 ++ ) = 0 ;
V_27 = V_26 - V_25 ;
V_28 = strlen ( V_26 ) + 1 ;
if ( ( V_27 <= 1 ) || ( V_27 > V_19 ) ||
( V_28 <= 1 ) || ( V_28 > V_29 ) )
return 0 ;
if ( V_22 ) {
strcpy ( V_22 -> V_25 , V_25 ) ;
strcpy ( V_22 -> V_26 , V_26 ) ;
}
return 1 ;
}
struct V_30 * F_10 ( const char * V_2 )
{
struct V_30 * V_31 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
V_31 = V_33 [ V_3 ] ;
if ( V_31 && ( ! strcmp ( V_31 -> V_2 , V_2 ) ) )
return V_31 ;
}
return NULL ;
}
struct V_17 * F_11 ( void )
{
struct V_17 * V_6 ;
struct V_30 * V_34 ;
int V_3 , V_35 ;
V_6 = F_6 ( V_32 * F_7 ( V_24 ) ) ;
if ( ! V_6 )
return NULL ;
F_12 ( & V_36 ) ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
V_34 = V_33 [ V_35 ] ;
if ( ! V_34 )
continue;
if ( V_34 -> V_37 == V_4 [ V_3 ] ) {
F_8 ( V_6 , V_38 ,
V_34 -> V_2 ,
strlen ( V_34 -> V_2 ) + 1 ) ;
}
}
}
F_13 ( & V_36 ) ;
return V_6 ;
}
void F_14 ( struct V_30 * V_31 , T_1 V_39 )
{
F_15 ( & V_31 -> V_40 , V_39 ) ;
F_16 () ;
F_17 ( V_31 -> V_41 ) ;
}
void F_18 ( struct V_30 * V_31 , T_1 V_39 )
{
F_19 ( & V_31 -> V_40 , V_39 ) ;
F_16 () ;
F_20 ( V_31 -> V_41 ) ;
}
int F_21 ( const char * V_2 , T_1 V_42 , T_1 V_43 )
{
struct V_30 * V_31 ;
struct V_1 * V_12 ;
struct V_21 V_44 ;
char V_45 [ 16 ] ;
T_1 V_46 ;
T_1 V_47 ;
T_1 V_3 ;
int V_48 = - V_49 ;
if ( ! V_50 ) {
F_22 ( L_4 ,
V_2 ) ;
return - V_51 ;
}
if ( ! F_9 ( V_2 , & V_44 ) ) {
F_22 ( L_5 , V_2 ) ;
return - V_49 ;
}
if ( F_23 ( V_42 ) &&
( V_42 != V_50 ) ) {
if ( F_24 ( V_42 , V_50 ) ) {
V_42 = V_50 & V_52 ;
V_48 = 0 ;
} else if ( F_25 ( V_42 ) )
V_48 = 0 ;
}
if ( V_48 ) {
F_22 ( L_6 ,
V_2 ) ;
return - V_49 ;
}
if ( ( V_43 > V_53 ) &&
( V_43 != V_54 ) ) {
F_22 ( L_7 , V_2 ) ;
return - V_49 ;
}
F_26 ( & V_36 ) ;
V_12 = F_1 ( V_44 . V_25 ) ;
if ( ! V_12 ) {
F_22 ( L_8 ,
V_2 , V_44 . V_25 ) ;
goto exit;
}
if ( V_43 == V_54 )
V_43 = V_12 -> V_43 ;
V_55:
V_46 = V_32 ;
V_47 = 1 ;
for ( V_3 = V_32 ; V_3 -- != 0 ; ) {
V_31 = V_33 [ V_3 ] ;
if ( ! V_31 ) {
V_46 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_31 -> V_2 ) ) {
F_22 ( L_9 ,
V_2 ) ;
goto exit;
}
if ( ( V_31 -> V_43 == V_43 ) &&
( ++ V_47 > 2 ) ) {
if ( V_43 -- == 0 ) {
F_22 ( L_10 ,
V_2 ) ;
goto exit;
}
F_22 ( L_11 ,
V_2 , V_43 + 1 , V_43 ) ;
goto V_55;
}
}
if ( V_46 >= V_32 ) {
F_22 ( L_12 ,
V_2 , V_32 ) ;
goto exit;
}
V_31 = F_27 ( sizeof( * V_31 ) , V_56 ) ;
if ( ! V_31 ) {
V_48 = - V_57 ;
goto exit;
}
strcpy ( V_31 -> V_2 , V_2 ) ;
V_31 -> V_37 = V_12 ;
V_48 = V_12 -> V_58 ( V_31 ) ;
if ( V_48 ) {
F_22 ( L_13 ,
V_2 , - V_48 ) ;
goto exit;
}
V_31 -> V_59 = V_46 ;
V_31 -> V_60 = V_12 -> V_60 ;
V_31 -> V_61 = V_12 -> V_61 ;
V_31 -> V_62 = V_42 ;
V_31 -> V_63 = V_46 + 'A' ;
V_31 -> V_43 = V_43 ;
V_48 = F_28 ( V_31 , & V_31 -> V_64 ) ;
if ( V_48 ) {
F_29 ( V_31 , false ) ;
F_22 ( L_14 ,
V_2 ) ;
goto exit;
}
V_33 [ V_46 ] = V_31 ;
F_30 ( L_15 ,
V_2 ,
F_31 ( V_45 , V_42 ) , V_43 ) ;
exit:
F_32 ( & V_36 ) ;
return V_48 ;
}
static int F_33 ( struct V_30 * V_31 )
{
F_12 ( & V_36 ) ;
F_30 ( L_16 , V_31 -> V_2 ) ;
F_34 ( V_31 -> V_41 ) ;
F_35 ( V_31 -> V_59 ) ;
F_28 ( V_31 , & V_31 -> V_64 ) ;
F_13 ( & V_36 ) ;
return 0 ;
}
static void F_29 ( struct V_30 * V_31 , bool V_65 )
{
T_1 V_3 ;
F_30 ( L_17 , V_31 -> V_2 ) ;
V_31 -> V_37 -> V_66 ( V_31 ) ;
F_36 ( V_31 -> V_59 , V_65 ) ;
if ( V_31 -> V_41 )
F_34 ( V_31 -> V_41 ) ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
if ( V_31 == V_33 [ V_3 ] ) {
V_33 [ V_3 ] = NULL ;
break;
}
}
F_37 ( V_31 ) ;
}
int F_38 ( const char * V_2 )
{
struct V_30 * V_31 ;
int V_48 ;
F_26 ( & V_36 ) ;
V_31 = F_10 ( V_2 ) ;
if ( V_31 == NULL ) {
F_22 ( L_18 , V_2 ) ;
V_48 = - V_49 ;
} else {
F_29 ( V_31 , false ) ;
V_48 = 0 ;
}
F_32 ( & V_36 ) ;
return V_48 ;
}
void F_39 ( const struct V_30 * V_34 ,
struct V_8 * V_9 , char * V_67 )
{
int V_7 = V_34 -> V_37 -> V_68 ;
if ( F_40 ( sizeof( V_9 -> V_16 ) < V_7 ) ) {
F_41 ( 1 , L_19 ) ;
return;
}
memcpy ( V_9 -> V_16 , V_67 , V_7 ) ;
memset ( V_9 -> V_16 + V_7 , 0 , sizeof( V_9 -> V_16 ) - V_7 ) ;
V_9 -> V_14 = V_34 -> V_37 -> V_5 ;
V_9 -> V_69 = ! memcmp ( V_67 , V_34 -> V_64 . V_16 , V_7 ) ;
}
int F_42 ( struct V_30 * V_34 )
{
struct V_70 * V_71 ;
char * V_72 = strchr ( ( const char * ) V_34 -> V_2 , ':' ) + 1 ;
V_71 = F_43 ( & V_73 , V_72 ) ;
if ( ! V_71 )
return - V_74 ;
V_34 -> V_75 = V_71 ;
memset ( V_34 -> V_64 . V_16 , 0 , sizeof( V_34 -> V_64 . V_16 ) ) ;
memcpy ( V_34 -> V_64 . V_16 , V_71 -> V_69 , V_34 -> V_37 -> V_68 ) ;
V_34 -> V_64 . V_14 = V_34 -> V_37 -> V_5 ;
V_34 -> V_64 . V_69 = 1 ;
V_34 -> V_76 = V_71 -> V_76 ;
F_39 ( V_34 , & V_34 -> V_77 , ( char * ) V_71 -> V_78 ) ;
F_44 ( V_71 -> V_79 , V_34 ) ;
return 0 ;
}
void F_45 ( struct V_30 * V_34 )
{
struct V_70 * V_71 = (struct V_70 * ) V_34 -> V_75 ;
F_46 ( V_71 -> V_79 , NULL ) ;
F_47 ( V_71 ) ;
}
int F_48 ( struct V_17 * V_6 , struct V_30 * V_34 ,
struct V_8 * V_39 )
{
struct V_17 * V_80 ;
int V_81 ;
struct V_70 * V_71 = (struct V_70 * ) V_34 -> V_75 ;
V_80 = F_49 ( V_6 , V_56 ) ;
if ( ! V_80 )
return 0 ;
V_81 = V_71 -> V_82 - F_50 ( V_6 ) ;
if ( ( V_81 > 0 ) &&
F_51 ( V_80 , F_52 ( V_81 ) , 0 , V_56 ) ) {
F_53 ( V_80 ) ;
return 0 ;
}
F_54 ( V_80 ) ;
V_80 -> V_71 = V_71 ;
V_80 -> V_83 = F_55 ( V_84 ) ;
F_56 ( V_80 , V_71 , V_84 , V_39 -> V_16 ,
V_71 -> V_78 , V_80 -> V_7 ) ;
F_57 ( V_80 ) ;
return 0 ;
}
void F_58 ( struct V_30 * V_34 , struct V_17 * V_6 ,
struct V_8 * V_39 )
{
V_34 -> V_37 -> V_85 ( V_6 , V_34 , V_39 ) ;
}
static int F_59 ( struct V_17 * V_6 , struct V_70 * V_71 ,
struct V_86 * V_87 , struct V_70 * V_88 )
{
struct V_30 * V_31 ;
if ( ! F_60 ( F_61 ( V_71 ) , & V_73 ) ) {
F_53 ( V_6 ) ;
return V_89 ;
}
F_62 () ;
V_31 = F_63 ( V_71 -> V_79 ) ;
if ( F_64 ( V_31 ) ) {
if ( F_64 ( V_6 -> V_90 <= V_91 ) ) {
V_6 -> V_92 = NULL ;
F_65 ( V_6 , V_31 ) ;
F_66 () ;
return V_93 ;
}
}
F_66 () ;
F_53 ( V_6 ) ;
return V_89 ;
}
static int F_67 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
struct V_30 * V_31 ;
struct V_70 * V_71 = F_68 ( V_97 ) ;
if ( ! F_60 ( F_61 ( V_71 ) , & V_73 ) )
return V_98 ;
F_62 () ;
V_31 = F_63 ( V_71 -> V_79 ) ;
if ( ! V_31 ) {
F_66 () ;
return V_98 ;
}
V_31 -> V_76 = V_71 -> V_76 ;
switch ( V_96 ) {
case V_99 :
if ( F_69 ( V_71 ) )
break;
case V_100 :
case V_101 :
F_33 ( V_31 ) ;
break;
case V_102 :
F_39 ( V_31 , & V_31 -> V_77 ,
( char * ) V_71 -> V_78 ) ;
F_33 ( V_31 ) ;
break;
case V_103 :
case V_104 :
F_38 ( V_31 -> V_2 ) ;
break;
}
F_66 () ;
return V_105 ;
}
int F_70 ( void )
{
int V_106 ;
V_106 = F_71 ( & V_107 ) ;
if ( V_106 )
return V_106 ;
F_72 ( & V_108 ) ;
return 0 ;
}
void F_73 ( void )
{
F_74 ( & V_107 ) ;
F_75 ( & V_108 ) ;
}
void F_76 ( void )
{
struct V_30 * V_31 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
V_31 = V_33 [ V_3 ] ;
if ( V_31 ) {
F_29 ( V_31 , true ) ;
V_33 [ V_3 ] = NULL ;
}
}
}
