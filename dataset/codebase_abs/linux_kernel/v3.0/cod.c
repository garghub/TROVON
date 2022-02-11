static T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_3 ;
F_2 ( V_2 , NULL ) ;
return 0 ;
}
static struct V_1 * F_3 ( const char * V_4 , const char * V_5 )
{
T_2 V_6 ;
struct V_1 * V_2 ;
V_6 = F_4 () ;
F_5 ( F_6 () ) ;
V_2 = F_7 ( V_4 , V_7 , 0 ) ;
if ( F_8 ( V_2 ) )
V_2 = NULL ;
F_5 ( V_6 ) ;
return V_2 ;
}
static T_1 F_9 ( void T_3 * V_8 , T_1 V_9 , T_1 V_10 ,
struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_3 ;
if ( ( V_9 > 0 ) && ( V_10 > 0 ) && V_8 ) {
T_4 V_11 ;
T_2 V_6 ;
V_6 = F_4 () ;
F_5 ( F_6 () ) ;
V_11 = V_2 -> V_12 -> V_13 ( V_2 , V_8 , V_9 * V_10 ,
& ( V_2 -> V_14 ) ) ;
F_5 ( V_6 ) ;
if ( ! V_11 )
return - V_15 ;
return V_11 / V_9 ;
}
return - V_16 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_18 )
{
T_5 V_19 ;
if ( ! V_2 )
return - V_3 ;
V_19 = V_2 -> V_12 -> V_20 ( V_2 , V_17 , V_18 ) ;
if ( ( T_1 ) V_19 < 0 )
return - V_21 ;
return 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_5 V_19 ;
if ( ! V_2 )
return - V_3 ;
V_19 = V_2 -> V_12 -> V_20 ( V_2 , 0 , V_22 ) ;
if ( ( T_1 ) V_19 < 0 )
return - V_21 ;
return V_19 ;
}
void F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_24 != NULL ) ;
F_13 ( V_24 -> V_28 ) ;
V_26 = V_24 -> V_28 ;
V_26 -> V_29 . V_30 ( V_24 -> V_31 ) ;
F_14 ( V_24 ) ;
}
int F_15 ( struct V_25 * * V_32 , char * V_33 )
{
struct V_25 * V_34 ;
struct V_35 V_36 ;
int V_37 = 0 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_32 != NULL ) ;
* V_32 = NULL ;
V_34 = F_16 ( sizeof( struct V_25 ) , V_38 ) ;
if ( V_34 == NULL )
return - V_39 ;
V_34 -> V_29 = V_40 ;
V_34 -> V_29 . V_41 () ;
V_36 . V_42 = ( V_43 ) V_44 ;
V_36 . free = ( V_45 ) V_44 ;
V_36 . fread = ( V_46 ) F_9 ;
V_36 . fseek = ( V_47 ) F_10 ;
V_36 . ftell = ( V_48 ) F_11 ;
V_36 . fclose = ( V_49 ) F_1 ;
V_36 . fopen = ( V_50 ) F_3 ;
V_36 . V_51 = NULL ;
V_36 . V_52 = true ;
V_36 . V_53 = NULL ;
V_36 . V_54 = NULL ;
V_36 . V_55 = NULL ;
V_36 . V_56 = NULL ;
V_36 . V_57 = NULL ;
V_36 . V_58 = NULL ;
V_36 . V_59 = NULL ;
V_34 -> V_60 = V_36 ;
V_37 = V_34 -> V_29 . V_61 ( & V_34 -> V_62 , & V_36 ) ;
if ( V_37 ) {
F_17 ( V_34 ) ;
return - V_63 ;
}
* V_32 = V_34 ;
return 0 ;
}
void F_17 ( struct V_25 * V_64 )
{
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
if ( V_64 -> V_65 ) {
if ( V_64 -> V_66 )
V_64 -> V_29 . V_67 ( V_64 -> V_65 ,
& V_64 -> V_60 ) ;
V_64 -> V_29 . V_30 ( V_64 -> V_65 ) ;
}
if ( V_64 -> V_62 ) {
V_64 -> V_29 . V_68 ( V_64 -> V_62 ) ;
V_64 -> V_29 . V_69 () ;
}
F_14 ( V_64 ) ;
}
void F_18 ( void )
{
F_13 ( V_27 > 0 ) ;
V_27 -- ;
F_19 ( V_27 >= 0 ) ;
}
int F_20 ( struct V_25 * V_64 ,
struct V_70 * * V_71 )
{
int V_37 = 0 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
F_13 ( V_71 != NULL ) ;
* V_71 = (struct V_70 * ) V_64 -> V_65 ;
return V_37 ;
}
int F_21 ( struct V_25 * V_64 , char * V_72 ,
T_4 V_73 )
{
int V_37 = 0 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
F_13 ( V_72 != NULL ) ;
if ( V_73 <= V_74 )
strncpy ( V_72 , V_64 -> V_75 , V_73 ) ;
else
V_37 = - V_21 ;
return V_37 ;
}
int F_22 ( struct V_25 * V_64 , T_4 * V_76 )
{
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
F_13 ( V_76 != NULL ) ;
* V_76 = V_64 -> V_77 ;
return 0 ;
}
int F_23 ( struct V_25 * V_64 ,
struct V_78 * * V_79 )
{
int V_37 = 0 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
F_13 ( V_79 != NULL ) ;
* V_79 = (struct V_78 * ) V_64 -> V_62 ;
return V_37 ;
}
int F_24 ( struct V_23 * V_24 , char * V_80 ,
T_4 * V_81 , T_4 * V_82 )
{
struct V_25 * V_64 ;
int V_37 = 0 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_24 != NULL ) ;
F_13 ( V_24 -> V_28 ) ;
F_13 ( V_80 != NULL ) ;
F_13 ( V_81 != NULL ) ;
F_13 ( V_82 != NULL ) ;
* V_81 = 0 ;
* V_82 = 0 ;
if ( V_24 != NULL ) {
V_64 = V_24 -> V_28 ;
V_37 = V_64 -> V_29 . V_83 ( V_24 -> V_31 , V_80 ,
V_81 , V_82 ) ;
} else {
V_37 = - V_63 ;
}
F_19 ( ! V_37 || ( ( * V_81 == 0 ) && ( * V_82 == 0 ) ) ) ;
return V_37 ;
}
int F_25 ( struct V_25 * V_64 , char * V_84 ,
T_4 * V_85 )
{
struct V_86 * V_87 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
F_13 ( V_84 != NULL ) ;
F_13 ( V_85 != NULL ) ;
F_26 ( V_88 , L_1 ,
V_89 , V_64 , V_84 , V_85 ) ;
if ( V_64 -> V_65 ) {
if ( ! V_64 -> V_29 .
V_90 ( V_64 -> V_65 , V_84 , & V_87 ) ) {
if ( ! V_64 -> V_29 .
V_91 ( V_64 -> V_65 , V_84 ,
& V_87 ) )
return - V_63 ;
}
} else {
return - V_63 ;
}
* V_85 = V_87 -> V_92 ;
return 0 ;
}
bool F_27 ( void )
{
bool V_93 = true ;
F_13 ( V_27 >= 0 ) ;
if ( V_93 )
V_27 ++ ;
F_19 ( ( V_93 && V_27 > 0 ) || ( ! V_93 && V_27 >= 0 ) ) ;
return V_93 ;
}
int F_28 ( struct V_25 * V_64 , T_4 V_94 , char * args [] ,
T_6 V_95 , void * V_96 , char * V_97 [] )
{
T_7 V_98 ;
struct V_35 V_99 ;
struct V_35 V_100 ;
int V_37 ;
T_4 V_101 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_64 ) ;
F_13 ( V_94 > 0 ) ;
F_13 ( args != NULL ) ;
F_13 ( args [ 0 ] != NULL ) ;
F_13 ( V_95 != NULL ) ;
F_13 ( V_64 -> V_65 != NULL ) ;
for ( V_101 = 0 ; V_101 < V_94 ; V_101 ++ ) {
if ( args [ V_101 ] == NULL ) {
V_94 = V_101 ;
break;
}
}
V_64 -> V_29 . V_102 ( V_64 -> V_62 , & V_99 ) ;
V_100 = V_99 ;
V_100 . V_55 = ( V_103 ) V_95 ;
V_100 . V_57 = V_96 ;
V_100 . V_42 = ( V_43 ) V_44 ;
V_100 . free = ( V_45 ) V_44 ;
V_100 . V_53 = NULL ;
V_100 . V_54 = NULL ;
V_98 = V_104 | V_105 | V_106 ;
V_37 = V_64 -> V_29 . V_107 ( V_64 -> V_65 , V_98 ,
& V_100 ,
& V_64 -> V_77 ) ;
if ( V_37 )
V_64 -> V_29 . V_30 ( V_64 -> V_65 ) ;
if ( ! V_37 )
V_64 -> V_66 = true ;
else
V_64 -> V_65 = NULL ;
return V_37 ;
}
int F_29 ( struct V_25 * V_26 , char * V_108 ,
T_4 V_98 , struct V_23 * * V_109 )
{
int V_37 = 0 ;
struct V_23 * V_24 = NULL ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_26 ) ;
F_13 ( V_108 != NULL ) ;
F_13 ( V_98 == V_110 || V_98 == V_111 ) ;
F_13 ( V_109 != NULL ) ;
* V_109 = NULL ;
V_24 = F_16 ( sizeof( struct V_23 ) , V_38 ) ;
if ( V_24 == NULL )
V_37 = - V_39 ;
if ( ! V_37 ) {
V_24 -> V_28 = V_26 ;
V_37 = V_26 -> V_29 . V_112 ( V_26 -> V_62 , V_108 , V_98 ,
& V_24 -> V_31 ) ;
if ( ! V_37 )
* V_109 = V_24 ;
}
if ( V_37 )
F_30 ( L_2 ,
V_89 , V_37 , V_108 , V_98 ) ;
return V_37 ;
}
int F_31 ( struct V_25 * V_26 , char * V_108 ,
T_7 V_98 )
{
int V_37 = 0 ;
struct V_70 * V_24 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_26 ) ;
F_13 ( V_108 != NULL ) ;
if ( V_26 -> V_65 ) {
if ( V_26 -> V_66 ) {
V_26 -> V_29 . V_67 ( V_26 -> V_65 , & V_26 -> V_60 ) ;
V_26 -> V_66 = false ;
}
V_26 -> V_29 . V_30 ( V_26 -> V_65 ) ;
V_26 -> V_65 = NULL ;
}
V_37 = V_26 -> V_29 . V_112 ( V_26 -> V_62 , V_108 , V_98 , & V_24 ) ;
if ( ! V_37 ) {
V_26 -> V_65 = V_24 ;
strncpy ( V_26 -> V_75 , V_108 , V_74 - 1 ) ;
V_26 -> V_75 [ V_74 - 1 ] = '\0' ;
}
if ( V_37 )
F_30 ( L_3 , V_89 ,
V_37 , V_108 ) ;
return V_37 ;
}
int F_32 ( struct V_23 * V_24 , char * V_80 ,
char * V_113 , T_4 V_114 )
{
int V_37 = 0 ;
F_13 ( V_27 > 0 ) ;
F_13 ( V_24 != NULL ) ;
F_13 ( V_24 -> V_28 ) ;
F_13 ( V_80 != NULL ) ;
F_13 ( V_113 != NULL ) ;
if ( V_24 != NULL )
V_37 =
V_24 -> V_28 -> V_29 . V_115 ( V_24 -> V_31 , V_80 ,
V_113 , V_114 ) ;
else
V_37 = - V_63 ;
return V_37 ;
}
static bool V_44 ( void )
{
return true ;
}
