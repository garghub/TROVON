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
V_26 = V_24 -> V_27 ;
V_26 -> V_28 . V_29 ( V_24 -> V_30 ) ;
F_13 ( V_24 ) ;
}
int F_14 ( struct V_25 * * V_31 , char * V_32 )
{
struct V_25 * V_33 ;
struct V_34 V_35 ;
int V_36 = 0 ;
* V_31 = NULL ;
V_33 = F_15 ( sizeof( struct V_25 ) , V_37 ) ;
if ( V_33 == NULL )
return - V_38 ;
V_33 -> V_28 = V_39 ;
V_33 -> V_28 . V_40 () ;
V_35 . V_41 = ( V_42 ) V_43 ;
V_35 . free = ( V_44 ) V_43 ;
V_35 . fread = ( V_45 ) F_9 ;
V_35 . fseek = ( V_46 ) F_10 ;
V_35 . ftell = ( V_47 ) F_11 ;
V_35 . fclose = ( V_48 ) F_1 ;
V_35 . fopen = ( V_49 ) F_3 ;
V_35 . V_50 = NULL ;
V_35 . V_51 = true ;
V_35 . V_52 = NULL ;
V_35 . V_53 = NULL ;
V_35 . V_54 = NULL ;
V_35 . V_55 = NULL ;
V_35 . V_56 = NULL ;
V_35 . V_57 = NULL ;
V_35 . V_58 = NULL ;
V_33 -> V_59 = V_35 ;
V_36 = V_33 -> V_28 . V_60 ( & V_33 -> V_61 , & V_35 ) ;
if ( V_36 ) {
F_16 ( V_33 ) ;
return - V_62 ;
}
* V_31 = V_33 ;
return 0 ;
}
void F_16 ( struct V_25 * V_63 )
{
if ( V_63 -> V_64 ) {
if ( V_63 -> V_65 )
V_63 -> V_28 . V_66 ( V_63 -> V_64 ,
& V_63 -> V_59 ) ;
V_63 -> V_28 . V_29 ( V_63 -> V_64 ) ;
}
if ( V_63 -> V_61 ) {
V_63 -> V_28 . V_67 ( V_63 -> V_61 ) ;
V_63 -> V_28 . V_68 () ;
}
F_13 ( V_63 ) ;
}
int F_17 ( struct V_25 * V_63 ,
struct V_69 * * V_70 )
{
int V_36 = 0 ;
* V_70 = (struct V_69 * ) V_63 -> V_64 ;
return V_36 ;
}
int F_18 ( struct V_25 * V_63 , char * V_71 ,
T_4 V_72 )
{
int V_36 = 0 ;
if ( V_72 <= V_73 )
F_19 ( V_71 , V_63 -> V_74 , V_72 ) ;
else
V_36 = - V_21 ;
return V_36 ;
}
int F_20 ( struct V_25 * V_63 , T_4 * V_75 )
{
* V_75 = V_63 -> V_76 ;
return 0 ;
}
int F_21 ( struct V_25 * V_63 ,
struct V_77 * * V_78 )
{
int V_36 = 0 ;
* V_78 = (struct V_77 * ) V_63 -> V_61 ;
return V_36 ;
}
int F_22 ( struct V_23 * V_24 , char * V_79 ,
T_4 * V_80 , T_4 * V_81 )
{
struct V_25 * V_63 ;
int V_36 = 0 ;
* V_80 = 0 ;
* V_81 = 0 ;
if ( V_24 != NULL ) {
V_63 = V_24 -> V_27 ;
V_36 = V_63 -> V_28 . V_82 ( V_24 -> V_30 , V_79 ,
V_80 , V_81 ) ;
} else {
V_36 = - V_62 ;
}
return V_36 ;
}
int F_23 ( struct V_25 * V_63 , char * V_83 ,
T_4 * V_84 )
{
struct V_85 * V_86 ;
F_24 ( V_87 , L_1 ,
V_88 , V_63 , V_83 , V_84 ) ;
if ( V_63 -> V_64 ) {
if ( ! V_63 -> V_28 .
V_89 ( V_63 -> V_64 , V_83 , & V_86 ) ) {
if ( ! V_63 -> V_28 .
V_90 ( V_63 -> V_64 , V_83 ,
& V_86 ) )
return - V_62 ;
}
} else {
return - V_62 ;
}
* V_84 = V_86 -> V_91 ;
return 0 ;
}
int F_25 ( struct V_25 * V_63 , T_4 V_92 , char * args [] ,
T_6 V_93 , void * V_94 , char * V_95 [] )
{
T_7 V_96 ;
struct V_34 V_97 ;
struct V_34 V_98 ;
int V_36 ;
T_4 V_99 ;
for ( V_99 = 0 ; V_99 < V_92 ; V_99 ++ ) {
if ( args [ V_99 ] == NULL ) {
V_92 = V_99 ;
break;
}
}
V_63 -> V_28 . V_100 ( V_63 -> V_61 , & V_97 ) ;
V_98 = V_97 ;
V_98 . V_54 = ( V_101 ) V_93 ;
V_98 . V_56 = V_94 ;
V_98 . V_41 = ( V_42 ) V_43 ;
V_98 . free = ( V_44 ) V_43 ;
V_98 . V_52 = NULL ;
V_98 . V_53 = NULL ;
V_96 = V_102 | V_103 | V_104 ;
V_36 = V_63 -> V_28 . V_105 ( V_63 -> V_64 , V_96 ,
& V_98 ,
& V_63 -> V_76 ) ;
if ( V_36 )
V_63 -> V_28 . V_29 ( V_63 -> V_64 ) ;
if ( ! V_36 )
V_63 -> V_65 = true ;
else
V_63 -> V_64 = NULL ;
return V_36 ;
}
int F_26 ( struct V_25 * V_26 , char * V_106 ,
T_4 V_96 , struct V_23 * * V_107 )
{
int V_36 = 0 ;
struct V_23 * V_24 = NULL ;
* V_107 = NULL ;
V_24 = F_15 ( sizeof( struct V_23 ) , V_37 ) ;
if ( V_24 == NULL )
V_36 = - V_38 ;
if ( ! V_36 ) {
V_24 -> V_27 = V_26 ;
V_36 = V_26 -> V_28 . V_108 ( V_26 -> V_61 , V_106 , V_96 ,
& V_24 -> V_30 ) ;
if ( ! V_36 )
* V_107 = V_24 ;
}
if ( V_36 )
F_27 ( L_2 ,
V_88 , V_36 , V_106 , V_96 ) ;
return V_36 ;
}
int F_28 ( struct V_25 * V_26 , char * V_106 ,
T_7 V_96 )
{
int V_36 = 0 ;
struct V_69 * V_24 ;
if ( V_26 -> V_64 ) {
if ( V_26 -> V_65 ) {
V_26 -> V_28 . V_66 ( V_26 -> V_64 , & V_26 -> V_59 ) ;
V_26 -> V_65 = false ;
}
V_26 -> V_28 . V_29 ( V_26 -> V_64 ) ;
V_26 -> V_64 = NULL ;
}
V_36 = V_26 -> V_28 . V_108 ( V_26 -> V_61 , V_106 , V_96 , & V_24 ) ;
if ( ! V_36 ) {
V_26 -> V_64 = V_24 ;
strncpy ( V_26 -> V_74 , V_106 , V_73 - 1 ) ;
V_26 -> V_74 [ V_73 - 1 ] = '\0' ;
}
if ( V_36 )
F_27 ( L_3 , V_88 ,
V_36 , V_106 ) ;
return V_36 ;
}
int F_29 ( struct V_23 * V_24 , char * V_79 ,
char * V_109 , T_4 V_110 )
{
int V_36 = 0 ;
if ( V_24 != NULL )
V_36 =
V_24 -> V_27 -> V_28 . V_111 ( V_24 -> V_30 , V_79 ,
V_109 , V_110 ) ;
else
V_36 = - V_62 ;
return V_36 ;
}
static bool V_43 ( void )
{
return true ;
}
