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
for ( V_3 = 0 , V_31 = V_32 ; V_3 < V_33 ; V_3 ++ , V_31 ++ ) {
if ( V_31 -> V_34 && ( ! strcmp ( V_31 -> V_2 , V_2 ) ) )
return V_31 ;
}
return NULL ;
}
struct V_17 * F_11 ( void )
{
struct V_17 * V_6 ;
struct V_30 * V_35 ;
int V_3 , V_36 ;
V_6 = F_6 ( V_33 * F_7 ( V_24 ) ) ;
if ( ! V_6 )
return NULL ;
F_12 ( & V_37 ) ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ ) {
V_35 = & V_32 [ V_36 ] ;
if ( V_35 -> V_34 && ( V_35 -> V_38 == V_4 [ V_3 ] ) ) {
F_8 ( V_6 , V_39 ,
V_35 -> V_2 ,
strlen ( V_35 -> V_2 ) + 1 ) ;
}
}
}
F_13 ( & V_37 ) ;
return V_6 ;
}
void F_14 ( struct V_30 * V_31 , T_1 V_40 )
{
F_15 ( & V_31 -> V_41 , V_40 ) ;
F_16 () ;
F_17 ( V_31 -> V_42 ) ;
}
void F_18 ( struct V_30 * V_31 , T_1 V_40 )
{
F_19 ( & V_31 -> V_41 , V_40 ) ;
F_16 () ;
F_20 ( V_31 -> V_42 ) ;
}
int F_21 ( const char * V_2 , T_1 V_43 , T_1 V_44 )
{
struct V_30 * V_31 ;
struct V_1 * V_12 ;
struct V_21 V_45 ;
char V_46 [ 16 ] ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_3 ;
int V_49 = - V_50 ;
if ( ! V_51 ) {
F_22 ( L_4 ,
V_2 ) ;
return - V_52 ;
}
if ( ! F_9 ( V_2 , & V_45 ) ) {
F_22 ( L_5 , V_2 ) ;
return - V_50 ;
}
if ( F_23 ( V_43 ) &&
( V_43 != V_51 ) ) {
if ( F_24 ( V_43 , V_51 ) ) {
V_43 = V_51 & V_53 ;
V_49 = 0 ;
} else if ( F_25 ( V_43 ) )
V_49 = 0 ;
}
if ( V_49 ) {
F_22 ( L_6 ,
V_2 ) ;
return - V_50 ;
}
if ( ( V_44 > V_54 ) &&
( V_44 != V_55 ) ) {
F_22 ( L_7 , V_2 ) ;
return - V_50 ;
}
F_26 ( & V_37 ) ;
V_12 = F_1 ( V_45 . V_25 ) ;
if ( ! V_12 ) {
F_22 ( L_8 ,
V_2 , V_45 . V_25 ) ;
goto exit;
}
if ( V_44 == V_55 )
V_44 = V_12 -> V_44 ;
V_56:
V_47 = V_33 ;
V_48 = 1 ;
for ( V_3 = V_33 ; V_3 -- != 0 ; ) {
if ( ! V_32 [ V_3 ] . V_34 ) {
V_47 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_32 [ V_3 ] . V_2 ) ) {
F_22 ( L_9 ,
V_2 ) ;
goto exit;
}
if ( ( V_32 [ V_3 ] . V_44 == V_44 ) &&
( ++ V_48 > 2 ) ) {
if ( V_44 -- == 0 ) {
F_22 ( L_10 ,
V_2 ) ;
goto exit;
}
F_22 ( L_11 ,
V_2 , V_44 + 1 , V_44 ) ;
goto V_56;
}
}
if ( V_47 >= V_33 ) {
F_22 ( L_12 ,
V_2 , V_33 ) ;
goto exit;
}
V_31 = & V_32 [ V_47 ] ;
strcpy ( V_31 -> V_2 , V_2 ) ;
V_31 -> V_38 = V_12 ;
V_49 = V_12 -> V_57 ( V_31 ) ;
if ( V_49 ) {
F_22 ( L_13 ,
V_2 , - V_49 ) ;
goto exit;
}
V_31 -> V_58 = V_47 ;
V_31 -> V_59 = V_12 -> V_59 ;
V_31 -> V_60 = V_12 -> V_60 ;
V_31 -> V_61 = V_47 + 'A' ;
V_31 -> V_34 = 1 ;
V_31 -> V_44 = V_44 ;
F_27 ( & V_31 -> V_62 ) ;
F_28 ( & V_31 -> V_63 ) ;
V_49 = F_29 ( V_31 , & V_31 -> V_64 , V_43 ) ;
if ( V_49 ) {
F_30 ( V_31 ) ;
F_22 ( L_14 ,
V_2 ) ;
goto exit;
}
F_31 ( L_15 ,
V_2 ,
F_32 ( V_46 , V_43 ) , V_44 ) ;
exit:
F_33 ( & V_37 ) ;
return V_49 ;
}
static int F_34 ( struct V_30 * V_31 )
{
struct V_65 * V_66 ;
struct V_65 * V_67 ;
F_12 ( & V_37 ) ;
F_31 ( L_16 , V_31 -> V_2 ) ;
F_35 ( & V_31 -> V_63 ) ;
F_36 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct V_68 * V_69 = V_66 -> V_70 ;
F_35 ( & V_69 -> V_63 ) ;
F_37 ( V_66 ) ;
F_38 ( & V_69 -> V_63 ) ;
}
F_38 ( & V_31 -> V_63 ) ;
F_13 ( & V_37 ) ;
return 0 ;
}
static void F_30 ( struct V_30 * V_31 )
{
struct V_65 * V_66 ;
struct V_65 * V_67 ;
struct V_71 * V_72 ;
F_31 ( L_17 , V_31 -> V_2 ) ;
F_35 ( & V_31 -> V_63 ) ;
V_31 -> V_38 -> V_73 ( V_31 ) ;
F_36 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
F_39 ( V_66 ) ;
}
V_72 = V_31 -> V_42 ;
V_31 -> V_42 = NULL ;
F_38 ( & V_31 -> V_63 ) ;
if ( V_72 )
F_40 ( V_72 ) ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
}
int F_41 ( const char * V_2 )
{
struct V_30 * V_31 ;
int V_49 ;
F_26 ( & V_37 ) ;
V_31 = F_10 ( V_2 ) ;
if ( V_31 == NULL ) {
F_22 ( L_18 , V_2 ) ;
V_49 = - V_50 ;
} else {
F_30 ( V_31 ) ;
V_49 = 0 ;
}
F_33 ( & V_37 ) ;
return V_49 ;
}
void F_42 ( const struct V_30 * V_35 ,
struct V_8 * V_9 , char * V_74 )
{
int V_7 = V_35 -> V_38 -> V_75 ;
if ( F_43 ( sizeof( V_9 -> V_16 ) < V_7 ) ) {
F_44 ( 1 , L_19 ) ;
return;
}
memcpy ( V_9 -> V_16 , V_74 , V_7 ) ;
memset ( V_9 -> V_16 + V_7 , 0 , sizeof( V_9 -> V_16 ) - V_7 ) ;
V_9 -> V_14 = V_35 -> V_38 -> V_5 ;
V_9 -> V_76 = ! memcmp ( V_74 , V_35 -> V_64 . V_16 , V_7 ) ;
}
int F_45 ( struct V_30 * V_35 )
{
struct V_77 * V_78 ;
char * V_79 = strchr ( ( const char * ) V_35 -> V_2 , ':' ) + 1 ;
V_78 = F_46 ( & V_80 , V_79 ) ;
if ( ! V_78 )
return - V_81 ;
V_35 -> V_82 = V_78 ;
memset ( V_35 -> V_64 . V_16 , 0 , sizeof( V_35 -> V_64 . V_16 ) ) ;
memcpy ( V_35 -> V_64 . V_16 , V_78 -> V_76 , V_35 -> V_38 -> V_75 ) ;
V_35 -> V_64 . V_14 = V_35 -> V_38 -> V_5 ;
V_35 -> V_64 . V_76 = 1 ;
V_35 -> V_83 = V_78 -> V_83 ;
F_42 ( V_35 , & V_35 -> V_84 , ( char * ) V_78 -> V_85 ) ;
F_47 ( V_78 -> V_86 , V_35 ) ;
return 0 ;
}
void F_48 ( struct V_30 * V_35 )
{
struct V_77 * V_78 = (struct V_77 * ) V_35 -> V_82 ;
F_49 ( V_78 -> V_86 , NULL ) ;
F_50 ( V_78 ) ;
}
int F_51 ( struct V_17 * V_6 , struct V_30 * V_35 ,
struct V_8 * V_40 )
{
struct V_17 * V_87 ;
int V_88 ;
struct V_77 * V_78 = (struct V_77 * ) V_35 -> V_82 ;
V_87 = F_52 ( V_6 , V_89 ) ;
if ( ! V_87 )
return 0 ;
V_88 = V_78 -> V_90 - F_53 ( V_6 ) ;
if ( ( V_88 > 0 ) &&
F_54 ( V_87 , F_55 ( V_88 ) , 0 , V_89 ) ) {
F_56 ( V_87 ) ;
return 0 ;
}
F_57 ( V_87 ) ;
V_87 -> V_78 = V_78 ;
V_87 -> V_91 = F_58 ( V_92 ) ;
F_59 ( V_87 , V_78 , V_92 , V_40 -> V_16 ,
V_78 -> V_85 , V_87 -> V_7 ) ;
F_60 ( V_87 ) ;
return 0 ;
}
void F_61 ( struct V_30 * V_35 , struct V_17 * V_6 ,
struct V_8 * V_40 )
{
V_35 -> V_38 -> V_93 ( V_6 , V_35 , V_40 ) ;
}
static int F_62 ( struct V_17 * V_6 , struct V_77 * V_78 ,
struct V_94 * V_95 , struct V_77 * V_96 )
{
struct V_30 * V_31 ;
if ( ! F_63 ( F_64 ( V_78 ) , & V_80 ) ) {
F_56 ( V_6 ) ;
return V_97 ;
}
F_65 () ;
V_31 = F_66 ( V_78 -> V_86 ) ;
if ( F_67 ( V_31 ) ) {
if ( F_67 ( V_6 -> V_98 <= V_99 ) ) {
V_6 -> V_100 = NULL ;
F_68 ( V_6 , V_31 ) ;
F_69 () ;
return V_101 ;
}
}
F_69 () ;
F_56 ( V_6 ) ;
return V_97 ;
}
static int F_70 ( struct V_102 * V_103 , unsigned long V_104 ,
void * V_105 )
{
struct V_30 * V_31 ;
struct V_77 * V_78 = F_71 ( V_105 ) ;
if ( ! F_63 ( F_64 ( V_78 ) , & V_80 ) )
return V_106 ;
F_65 () ;
V_31 = F_66 ( V_78 -> V_86 ) ;
if ( ! V_31 ) {
F_69 () ;
return V_106 ;
}
V_31 -> V_83 = V_78 -> V_83 ;
switch ( V_104 ) {
case V_107 :
if ( F_72 ( V_78 ) )
break;
case V_108 :
case V_109 :
case V_110 :
F_34 ( V_31 ) ;
break;
case V_111 :
case V_112 :
F_41 ( V_31 -> V_2 ) ;
break;
}
F_69 () ;
return V_113 ;
}
int F_73 ( void )
{
int V_114 ;
V_114 = F_74 ( & V_115 ) ;
if ( V_114 )
return V_114 ;
F_75 ( & V_116 ) ;
return 0 ;
}
void F_76 ( void )
{
F_77 ( & V_115 ) ;
F_78 ( & V_116 ) ;
}
void F_79 ( void )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_33 ; V_3 ++ ) {
if ( V_32 [ V_3 ] . V_34 )
F_30 ( & V_32 [ V_3 ] ) ;
}
}
