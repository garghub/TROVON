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
V_31 = F_11 ( V_33 [ V_3 ] ) ;
if ( V_31 && ( ! strcmp ( V_31 -> V_2 , V_2 ) ) )
return V_31 ;
}
return NULL ;
}
struct V_17 * F_12 ( void )
{
struct V_17 * V_6 ;
struct V_30 * V_34 ;
int V_3 , V_35 ;
V_6 = F_6 ( V_32 * F_7 ( V_24 ) ) ;
if ( ! V_6 )
return NULL ;
for ( V_3 = 0 ; V_4 [ V_3 ] != NULL ; V_3 ++ ) {
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
V_34 = F_11 ( V_33 [ V_35 ] ) ;
if ( ! V_34 )
continue;
if ( V_34 -> V_36 == V_4 [ V_3 ] ) {
F_8 ( V_6 , V_37 ,
V_34 -> V_2 ,
strlen ( V_34 -> V_2 ) + 1 ) ;
}
}
}
return V_6 ;
}
void F_13 ( T_1 V_38 , T_1 V_39 )
{
struct V_30 * V_31 ;
F_14 () ;
V_31 = F_15 ( V_33 [ V_38 ] ) ;
if ( V_31 ) {
F_16 ( & V_31 -> V_40 , V_39 , true ) ;
F_17 ( V_31 -> V_41 ) ;
}
F_18 () ;
}
void F_19 ( T_1 V_38 , T_1 V_39 )
{
struct V_30 * V_31 ;
F_14 () ;
V_31 = F_15 ( V_33 [ V_38 ] ) ;
if ( V_31 ) {
F_16 ( & V_31 -> V_40 , V_39 , false ) ;
F_20 ( V_31 -> V_41 ) ;
}
F_18 () ;
}
int F_21 ( const char * V_2 , T_1 V_42 , T_1 V_43 )
{
struct V_30 * V_31 ;
struct V_1 * V_12 ;
struct V_21 V_44 ;
char V_45 [ 16 ] ;
T_1 V_38 ;
T_1 V_46 ;
T_1 V_3 ;
int V_47 = - V_48 ;
if ( ! V_49 ) {
F_22 ( L_4 ,
V_2 ) ;
return - V_50 ;
}
if ( ! F_9 ( V_2 , & V_44 ) ) {
F_22 ( L_5 , V_2 ) ;
return - V_48 ;
}
if ( F_23 ( V_42 ) &&
( V_42 != V_49 ) ) {
if ( F_24 ( V_42 , V_49 ) ) {
V_42 = V_49 & V_51 ;
V_47 = 0 ;
} else if ( F_25 ( V_42 ) )
V_47 = 0 ;
}
if ( V_47 ) {
F_22 ( L_6 ,
V_2 ) ;
return - V_48 ;
}
if ( ( V_43 > V_52 ) &&
( V_43 != V_53 ) ) {
F_22 ( L_7 , V_2 ) ;
return - V_48 ;
}
V_12 = F_1 ( V_44 . V_25 ) ;
if ( ! V_12 ) {
F_22 ( L_8 ,
V_2 , V_44 . V_25 ) ;
return - V_48 ;
}
if ( V_43 == V_53 )
V_43 = V_12 -> V_43 ;
V_54:
V_38 = V_32 ;
V_46 = 1 ;
for ( V_3 = V_32 ; V_3 -- != 0 ; ) {
V_31 = F_11 ( V_33 [ V_3 ] ) ;
if ( ! V_31 ) {
V_38 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_31 -> V_2 ) ) {
F_22 ( L_9 ,
V_2 ) ;
return - V_48 ;
}
if ( ( V_31 -> V_43 == V_43 ) &&
( ++ V_46 > 2 ) ) {
if ( V_43 -- == 0 ) {
F_22 ( L_10 ,
V_2 ) ;
return - V_48 ;
}
F_22 ( L_11 ,
V_2 , V_43 + 1 , V_43 ) ;
goto V_54;
}
}
if ( V_38 >= V_32 ) {
F_22 ( L_12 ,
V_2 , V_32 ) ;
return - V_48 ;
}
V_31 = F_26 ( sizeof( * V_31 ) , V_55 ) ;
if ( ! V_31 )
return - V_56 ;
strcpy ( V_31 -> V_2 , V_2 ) ;
V_31 -> V_36 = V_12 ;
V_47 = V_12 -> V_57 ( V_31 ) ;
if ( V_47 ) {
F_22 ( L_13 ,
V_2 , - V_47 ) ;
return - V_48 ;
}
V_31 -> V_58 = V_38 ;
V_31 -> V_59 = V_12 -> V_59 ;
V_31 -> V_60 = V_12 -> V_60 ;
V_31 -> V_61 = V_42 ;
V_31 -> V_62 = V_38 + 'A' ;
V_31 -> V_43 = V_43 ;
V_47 = F_27 ( V_31 , & V_31 -> V_63 ) ;
if ( V_47 ) {
F_28 ( V_31 , false ) ;
F_22 ( L_14 ,
V_2 ) ;
return - V_48 ;
}
F_29 ( V_33 [ V_38 ] , V_31 ) ;
F_30 ( L_15 ,
V_2 ,
F_31 ( V_45 , V_42 ) , V_43 ) ;
return V_47 ;
}
static int F_32 ( struct V_30 * V_31 )
{
F_30 ( L_16 , V_31 -> V_2 ) ;
F_33 ( V_31 -> V_58 ) ;
F_34 ( V_31 ) ;
return 0 ;
}
static void F_28 ( struct V_30 * V_31 , bool V_64 )
{
T_1 V_3 ;
F_30 ( L_17 , V_31 -> V_2 ) ;
V_31 -> V_36 -> V_65 ( V_31 ) ;
F_35 ( V_31 -> V_58 , V_64 ) ;
if ( V_31 -> V_41 )
F_36 ( V_31 -> V_41 ) ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
if ( V_31 == F_11 ( V_33 [ V_3 ] ) ) {
F_37 ( V_33 [ V_3 ] , NULL ) ;
break;
}
}
F_38 ( V_31 , V_66 ) ;
}
int F_39 ( const char * V_2 )
{
struct V_30 * V_31 ;
int V_47 ;
V_31 = F_10 ( V_2 ) ;
if ( V_31 == NULL ) {
F_22 ( L_18 , V_2 ) ;
V_47 = - V_48 ;
} else {
F_28 ( V_31 , false ) ;
V_47 = 0 ;
}
return V_47 ;
}
int F_40 ( struct V_30 * V_34 )
{
struct V_67 * V_68 ;
char * V_69 = strchr ( ( const char * ) V_34 -> V_2 , ':' ) + 1 ;
V_68 = F_41 ( & V_70 , V_69 ) ;
if ( ! V_68 )
return - V_71 ;
F_29 ( V_34 -> V_72 , V_68 ) ;
memset ( & V_34 -> V_63 , 0 , sizeof( V_34 -> V_63 ) ) ;
memcpy ( V_34 -> V_63 . V_16 , V_68 -> V_73 , V_34 -> V_36 -> V_74 ) ;
V_34 -> V_63 . V_14 = V_34 -> V_36 -> V_5 ;
V_34 -> V_63 . V_73 = 1 ;
V_34 -> V_75 = V_68 -> V_75 ;
V_34 -> V_36 -> V_76 ( V_34 , & V_34 -> V_77 , ( char * ) V_68 -> V_78 ) ;
F_29 ( V_68 -> V_79 , V_34 ) ;
return 0 ;
}
void F_42 ( struct V_30 * V_34 )
{
struct V_67 * V_68 ;
V_68 = (struct V_67 * ) F_11 ( V_34 -> V_72 ) ;
F_37 ( V_34 -> V_72 , NULL ) ;
F_37 ( V_68 -> V_79 , NULL ) ;
F_43 () ;
F_44 ( V_68 ) ;
}
int F_45 ( struct V_17 * V_6 , struct V_30 * V_34 ,
struct V_8 * V_39 )
{
struct V_17 * V_80 ;
struct V_67 * V_68 ;
int V_81 ;
V_68 = (struct V_67 * ) F_15 ( V_34 -> V_72 ) ;
if ( ! V_68 )
return 0 ;
V_80 = F_46 ( V_6 , V_55 ) ;
if ( ! V_80 )
return 0 ;
V_81 = V_68 -> V_82 - F_47 ( V_6 ) ;
if ( ( V_81 > 0 ) &&
F_48 ( V_80 , F_49 ( V_81 ) , 0 , V_55 ) ) {
F_50 ( V_80 ) ;
return 0 ;
}
F_51 ( V_80 ) ;
V_80 -> V_68 = V_68 ;
V_80 -> V_83 = F_52 ( V_84 ) ;
F_53 ( V_80 , V_68 , V_84 , V_39 -> V_16 ,
V_68 -> V_78 , V_80 -> V_7 ) ;
F_54 ( V_80 ) ;
return 0 ;
}
void F_55 ( T_1 V_38 , struct V_17 * V_6 ,
struct V_8 * V_39 )
{
struct V_30 * V_31 ;
F_14 () ;
V_31 = F_15 ( V_33 [ V_38 ] ) ;
if ( F_56 ( V_31 ) )
V_31 -> V_36 -> V_85 ( V_6 , V_31 , V_39 ) ;
F_18 () ;
}
static int F_57 ( struct V_17 * V_6 , struct V_67 * V_68 ,
struct V_86 * V_87 , struct V_67 * V_88 )
{
struct V_30 * V_31 ;
if ( ! F_58 ( F_59 ( V_68 ) , & V_70 ) ) {
F_50 ( V_6 ) ;
return V_89 ;
}
F_14 () ;
V_31 = F_15 ( V_68 -> V_79 ) ;
if ( F_56 ( V_31 ) ) {
if ( F_56 ( V_6 -> V_90 <= V_91 ) ) {
V_6 -> V_92 = NULL ;
F_60 ( V_6 , V_31 ) ;
F_18 () ;
return V_93 ;
}
}
F_18 () ;
F_50 ( V_6 ) ;
return V_89 ;
}
static int F_61 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
struct V_30 * V_31 ;
struct V_67 * V_68 = F_62 ( V_97 ) ;
if ( ! F_58 ( F_59 ( V_68 ) , & V_70 ) )
return V_98 ;
V_31 = F_11 ( V_68 -> V_79 ) ;
if ( ! V_31 )
return V_98 ;
V_31 -> V_75 = V_68 -> V_75 ;
switch ( V_96 ) {
case V_99 :
if ( F_63 ( V_68 ) )
break;
case V_100 :
case V_101 :
F_32 ( V_31 ) ;
break;
case V_102 :
V_31 -> V_36 -> V_76 ( V_31 , & V_31 -> V_77 ,
( char * ) V_68 -> V_78 ) ;
F_32 ( V_31 ) ;
break;
case V_103 :
case V_104 :
F_28 ( V_31 , false ) ;
break;
}
return V_105 ;
}
int F_64 ( void )
{
int V_106 ;
V_106 = F_65 ( & V_107 ) ;
if ( V_106 )
return V_106 ;
F_66 ( & V_108 ) ;
return 0 ;
}
void F_67 ( void )
{
F_68 ( & V_107 ) ;
F_69 ( & V_108 ) ;
}
void F_70 ( void )
{
struct V_30 * V_31 ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
V_31 = F_11 ( V_33 [ V_3 ] ) ;
if ( V_31 ) {
F_28 ( V_31 , true ) ;
V_33 [ V_3 ] = NULL ;
}
}
}
