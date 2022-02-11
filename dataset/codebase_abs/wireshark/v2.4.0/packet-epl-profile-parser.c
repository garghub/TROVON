static T_1
F_1 ( const char * V_1 )
{
if ( F_2 ( V_1 , L_1 ) )
return TRUE ;
for (; F_3 ( * V_1 ) ; V_1 ++ )
;
if ( F_4 ( * V_1 ) == 'h' )
return TRUE ;
return FALSE ;
}
static T_2
F_5 ( T_3 * V_2 , const T_4 * V_3 , const T_4 * V_4 , T_5 * * error )
{
T_2 V_5 = 0 ;
const char * V_6 ;
char * V_7 = F_6 ( V_2 , V_3 , V_4 , error ) ;
if ( ! V_7 )
return 0 ;
if ( F_1 ( V_7 ) )
F_7 ( V_7 , & V_6 , & V_5 ) ;
else
F_8 ( V_7 , & V_6 , & V_5 ) ;
F_9 ( V_7 ) ;
return V_5 ;
}
static void
F_10 ( void * V_4 V_8 , void * V_9 , void * T_6 V_8 )
{
T_7 * V_10 = ( (struct V_11 * ) V_9 ) -> V_10 ;
if ( V_10 )
F_11 ( V_10 ) ;
}
void
F_12 ( void )
{
struct V_12 * V_13 ;
V_14 = F_13 ( F_14 () , V_15 , V_16 ) ;
for ( V_13 = V_17 ; V_13 -> V_18 ; V_13 ++ )
{
const struct V_19 * type = F_15 ( V_13 -> V_18 ) ;
F_16 ( V_14 , F_17 ( V_13 -> V_20 ) , ( void * ) type ) ;
}
}
struct V_21 *
F_18 ( struct V_21 * V_21 , const char * V_22 )
{
T_3 * V_2 ;
T_5 * V_23 ;
char * * V_24 , * * V_25 ;
char * V_7 ;
T_8 V_26 ;
V_2 = F_19 () ;
if ( ! F_20 ( V_2 , V_22 , V_27 , & V_23 ) ) {
F_21 ( NULL , V_28 , L_2 , V_22 ) ;
V_21 = NULL ;
goto V_29;
}
V_21 -> V_30 = F_22 ( V_21 -> V_31 , V_22 ) ;
V_7 = F_6 ( V_2 , L_3 , L_4 , NULL ) ;
V_21 -> V_18 = F_23 ( V_21 -> V_31 , V_7 , strcspn ( V_7 , L_5 ) ) ;
F_9 ( V_7 ) ;
V_25 = F_24 ( V_2 , & V_26 ) ;
for ( V_24 = V_25 ; * V_24 ; V_24 ++ )
{
char * V_18 ;
const char * V_6 ;
T_2 V_32 = 0 , V_33 ;
struct V_11 * V_34 = NULL ;
struct V_35 V_36 = V_37 ;
T_1 V_38 = TRUE ;
if ( ! F_3 ( * * V_24 ) )
continue;
F_7 ( * V_24 , & V_6 , & V_32 ) ;
if ( * V_6 == '\0' )
{
V_36 . V_32 = V_32 ;
}
else if ( F_2 ( V_6 , L_6 ) )
{
if ( ! F_7 ( V_6 + 3 , & V_6 , & V_36 . V_32 )
|| V_36 . V_32 > 0xFF )
continue;
V_38 = FALSE ;
}
else continue;
V_36 . V_39 = F_5 ( V_2 , * V_24 , L_7 , NULL ) ;
if ( ! V_36 . V_39 )
continue;
V_33 = F_5 ( V_2 , * V_24 , L_8 , NULL ) ;
if ( V_33 )
V_36 . type = ( const struct V_19 * ) F_25 ( V_14 , F_17 ( V_33 ) ) ;
if ( ( V_18 = F_6 ( V_2 , * V_24 , L_9 , NULL ) ) )
{
T_8 V_40 = strcspn ( V_18 , L_5 ) + 1 ;
F_26 (
V_36 . V_18 ,
V_18 ,
V_40 > sizeof V_36 . V_18 ? sizeof V_36 . V_18 : V_40
) ;
F_9 ( V_18 ) ;
}
V_34 = F_27 ( V_21 , V_32 ) ;
if ( V_38 )
{
V_34 -> V_41 = V_36 ;
}
else
{
struct V_42 V_43 = V_44 ;
if ( ! V_34 -> V_10 )
{
V_34 -> V_10 = F_28 (
V_21 -> V_31 ,
sizeof ( struct V_42 ) ,
V_45
) ;
}
V_43 . V_41 = V_36 ;
F_29 ( V_34 -> V_10 , V_43 . V_41 . V_32 , & V_43 . V_46 ) ;
}
}
F_30 ( V_21 -> V_47 , F_10 , NULL ) ;
V_29:
F_31 ( V_2 ) ;
return V_21 ;
}
void
F_32 ( void )
{
}
struct V_21 *
F_33 ( struct V_21 * V_21 , const char * V_48 )
{
T_9 V_49 = NULL ;
T_10 * V_50 = NULL ;
struct V_51 * V_52 = NULL ;
struct V_53 * V_53 = NULL ;
T_11 * V_54 = NULL ;
V_50 = F_34 ( V_48 ) ;
if ( ! V_50 )
{
F_21 ( NULL , V_28 , L_2 , V_48 ) ;
V_21 = NULL ;
goto V_29;
}
V_49 = F_35 ( V_50 ) ;
if( ! V_49 )
{
F_21 ( NULL , V_28 , L_10 ) ;
V_21 = NULL ;
goto V_29;
}
for ( V_52 = V_55 ; V_52 -> V_56 ; V_52 ++ )
{
if( F_36 ( V_49 , V_52 -> V_57 , V_52 -> V_56 ) != 0 )
{
F_21 ( NULL , V_28 , L_11 , V_52 -> V_57 , V_52 -> V_56 ) ;
V_21 = NULL ;
goto V_29;
}
}
V_21 -> V_30 = F_22 ( V_21 -> V_31 , V_48 ) ;
V_21 -> V_58 = V_54 = ( T_11 * ) F_37 ( V_15 , V_16 , NULL , F_9 ) ;
for ( V_53 = V_59 ; V_53 -> V_60 ; V_53 ++ )
{
T_12 V_61 = F_38 ( V_53 -> V_60 , V_49 ) ;
if ( ! V_61 || ! V_61 -> V_62 )
{
F_21 ( NULL , V_28 , L_12 , V_53 -> V_60 ) ;
F_39 ( V_61 ) ;
V_21 = NULL ;
goto V_29;
}
if ( V_53 -> V_63 && V_61 -> V_62 -> V_64 )
V_53 -> V_63 ( V_61 -> V_62 , V_21 ) ;
F_39 ( V_61 ) ;
}
F_40 ( V_21 ) ;
V_29:
if ( V_54 )
F_41 ( V_54 ) ;
if ( V_49 )
F_42 ( V_49 ) ;
if ( V_50 )
F_43 ( V_50 ) ;
return V_21 ;
}
static int
F_44 ( T_13 V_65 , void * V_66 )
{
struct V_21 * V_21 = (struct V_21 * ) V_66 ;
if ( V_65 -> V_64 == 1
&& V_65 -> V_67 [ 0 ] -> type == V_68
&& V_65 -> V_67 [ 0 ] -> V_69 )
{
V_21 -> V_18 = F_22 ( V_21 -> V_31 , ( char * ) V_65 -> V_67 [ 0 ] -> V_69 -> V_70 ) ;
return 0 ;
}
return - 1 ;
}
static int
F_45 ( T_13 V_65 , void * V_66 )
{
T_14 V_71 ;
int V_72 ;
struct V_21 * V_21 = (struct V_21 * ) V_66 ;
for( V_72 = 0 ; V_72 < V_65 -> V_64 ; ++ V_72 )
{
T_15 V_73 ;
if( ! V_65 -> V_67 [ V_72 ] || V_65 -> V_67 [ V_72 ] -> type != V_68 )
return - 1 ;
V_71 = V_65 -> V_67 [ V_72 ] ;
for( V_73 = V_71 -> V_74 ; V_73 ; V_73 = V_73 -> V_75 )
{
const char * V_6 ;
const char * V_4 = ( const char * ) V_73 -> V_18 ;
const char * V_7 = ( const char * ) V_73 -> V_69 -> V_70 ;
if ( F_46 ( L_13 , V_4 ) )
{
T_16 * V_76 ;
T_2 V_32 = 0 ;
if ( ! F_7 ( V_7 , & V_6 , & V_32 ) )
continue;
for ( V_76 = V_71 -> V_69 ; V_76 ; V_76 = V_76 -> V_75 )
{
if ( V_76 -> type == V_68 )
{
struct V_33 * type ;
const struct V_19 * V_77 = F_15 ( ( char * ) V_76 -> V_18 ) ;
if ( ! V_77 )
{
F_21 ( NULL , V_78 , L_14 , V_76 -> V_18 ) ;
continue;
}
type = F_47 ( struct V_33 , 1 ) ;
type -> V_20 = V_32 ;
type -> V_77 = V_77 ;
F_48 ( ( T_11 * ) V_21 -> V_58 , F_17 ( type -> V_20 ) , type ) ;
continue;
}
}
}
}
}
return 0 ;
}
static T_1
F_49 ( T_16 * V_71 , struct V_35 * V_79 , struct V_21 * V_21 ) {
T_15 V_73 ;
const char * V_80 = NULL , * V_81 = NULL ;
const char * V_6 ;
for( V_73 = V_71 -> V_74 ; V_73 ; V_73 = V_73 -> V_75 )
{
const char * V_4 = ( char * ) V_73 -> V_18 ,
* V_7 = ( char * ) V_73 -> V_69 -> V_70 ;
if ( F_46 ( L_15 , V_4 ) )
{
if ( ! F_7 ( V_7 , & V_6 , & V_79 -> V_32 ) )
return FALSE ;
} else if ( F_46 ( L_16 , V_4 ) ) {
if ( ! F_7 ( V_7 , & V_6 , & V_79 -> V_32 ) )
return FALSE ;
} else if ( F_46 ( L_17 , V_4 ) ) {
F_26 ( V_79 -> V_18 , V_7 , sizeof V_79 -> V_18 ) ;
} else if ( F_46 ( L_18 , V_4 ) ) {
V_79 -> V_39 = 0 ;
F_7 ( V_7 , & V_6 , & V_79 -> V_39 ) ;
} else if ( F_46 ( L_13 , V_4 ) ) {
T_2 V_20 ;
if ( F_7 ( V_7 , & V_6 , & V_20 ) )
{
struct V_33 * type = (struct V_33 * ) F_50 ( ( T_11 * ) V_21 -> V_58 , F_17 ( V_20 ) ) ;
if ( type ) V_79 -> type = type -> V_77 ;
}
} else if ( F_46 ( L_19 , V_4 ) ) {
V_80 = V_7 ;
} else if ( F_46 ( L_20 , V_4 ) ) {
V_81 = V_7 ;
}
#if 0
else if (g_str_equal("PDOmapping", key)) {
obj.PDOmapping = get_index(ObjectPDOmapping_tostr, val);
assert(obj.PDOmapping >= 0);
}
#endif
}
if ( V_81 )
V_79 -> V_9 = F_51 ( V_81 , NULL , 0 ) ;
else if ( V_80 )
V_79 -> V_9 = F_51 ( V_80 , NULL , 0 ) ;
else
V_79 -> V_9 = 0 ;
return TRUE ;
}
static int
F_52 ( T_13 V_65 , void * V_66 )
{
int V_72 ;
struct V_21 * V_21 = (struct V_21 * ) V_66 ;
for( V_72 = 0 ; V_72 < V_65 -> V_64 ; ++ V_72 )
{
T_14 V_71 = V_65 -> V_67 [ V_72 ] ;
struct V_35 V_36 = V_37 ;
if ( ! V_65 -> V_67 [ V_72 ] || V_65 -> V_67 [ V_72 ] -> type != V_68 )
continue;
F_49 ( V_71 , & V_36 , V_21 ) ;
if ( V_36 . V_32 )
{
struct V_11 * V_34 = F_53 ( V_21 , V_36 . V_32 ) ;
V_34 -> V_41 = V_36 ;
if ( V_36 . V_39 == V_82 || V_36 . V_39 == V_83 )
{
T_16 * V_84 ;
struct V_42 V_43 = V_44 ;
V_34 -> V_10 = F_28 ( V_21 -> V_31 , sizeof ( struct V_42 ) , V_45 ) ;
for ( V_84 = V_71 -> V_69 ; V_84 ; V_84 = V_84 -> V_75 )
{
if ( V_84 -> type != V_68 )
continue;
if ( F_49 ( V_84 , & V_43 . V_41 , V_21 ) )
{
F_29 ( V_34 -> V_10 ,
V_43 . V_41 . V_32 , & V_43 . V_46 ) ;
}
if ( V_43 . V_41 . V_9 && F_54 (
V_21 , V_34 -> V_41 . V_32 , ( V_85 ) V_43 . V_41 . V_32 , V_43 . V_41 . V_9 ) )
{
F_21 ( NULL , V_78 ,
L_21 , V_34 -> V_41 . V_18 , V_43 . V_41 . V_18 ) ;
}
}
F_11 ( V_34 -> V_10 ) ;
}
}
}
return 0 ;
}
static T_1
F_55 ( T_17 * V_31 V_8 , T_18 T_19 V_8 , void * V_58 )
{
T_20 * V_86 = ( T_20 * ) V_58 ;
F_56 ( V_86 , TRUE ) ;
return FALSE ;
}
static T_7 *
F_28 ( T_17 * V_31 , const T_21 V_87 , T_22 V_88 )
{
T_7 * V_89 ;
if ( V_87 < sizeof( V_90 ) ) return NULL ;
V_89 = F_57 ( V_31 , T_7 ) ;
if ( ! V_89 ) return NULL ;
V_89 -> V_88 = V_88 ;
V_89 -> V_31 = V_31 ;
V_89 -> V_86 = F_58 ( FALSE , FALSE , V_87 ) ;
V_89 -> V_91 = TRUE ;
F_59 ( V_31 , F_55 , V_89 -> V_86 ) ;
return V_89 ;
}
T_1
F_60 ( T_7 * V_89 )
{
return V_89 -> V_86 -> V_92 == 0 ;
}
T_1
F_61 ( T_7 * V_89 )
{
return V_89 -> V_91 ;
}
static void
F_29 ( T_7 * V_89 , T_23 V_93 , T_24 * V_58 )
{
if ( V_89 -> V_86 -> V_92 )
V_89 -> V_91 = FALSE ;
V_58 -> V_94 = V_58 -> V_95 = V_93 ;
F_62 ( V_89 -> V_86 , V_58 , 1 ) ;
}
static int
F_63 ( const void * V_96 , const void * V_97 )
{
return * ( const T_23 * ) V_96 - * ( const T_23 * ) V_97 ;
}
static void
F_11 ( T_7 * V_89 )
{
T_24 * V_98 , * V_99 = NULL ;
T_21 V_72 , V_92 ;
V_92 = V_89 -> V_86 -> V_92 ;
if ( V_89 -> V_91 )
return;
F_64 ( V_89 -> V_86 , F_63 ) ;
V_99 = V_98 = ( T_24 * ) V_89 -> V_86 -> V_58 ;
for ( V_72 = 1 ; V_72 < V_92 ; V_72 ++ ) {
V_98 = ( T_24 * ) ( ( char * ) V_98 + F_65 ( V_89 -> V_86 ) ) ;
while ( V_72 < V_92 && V_98 -> V_95 - V_99 -> V_94 <= 1 && V_89 -> V_88 ( V_98 , V_99 ) ) {
V_99 -> V_94 = V_98 -> V_94 ;
F_66 ( V_89 -> V_86 , V_72 ) ;
V_92 -- ;
}
V_99 = V_98 ;
}
V_89 -> V_91 = 1 ;
}
static int
F_67 ( const void * V_100 , const void * V_101 )
{
const T_24 * V_96 = ( const T_24 * ) V_100 ,
* V_97 = ( const T_24 * ) V_101 ;
if ( V_96 -> V_95 <= V_97 -> V_94 && V_97 -> V_95 <= V_96 -> V_94 )
return 0 ;
return V_96 -> V_95 - V_97 -> V_95 ;
}
static void *
F_68 ( const void * V_4 , T_20 * V_86 , int (* F_69)( const void * , const void * ) )
{
return bsearch ( V_4 , V_86 -> V_58 , V_86 -> V_92 , F_65 ( V_86 ) , F_69 ) ;
}
T_24 *
F_70 ( T_7 * V_89 , T_23 V_9 ) {
F_11 ( V_89 ) ;
T_24 V_102 ;
V_102 . V_95 = V_9 ;
V_102 . V_94 = V_9 ;
return ( T_24 * ) F_68 ( & V_102 , V_89 -> V_86 , F_67 ) ;
}
