static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) & V_3 -> V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_6 )
{
struct V_7 sin = {
. V_8 = V_9 ,
. V_10 . V_11 = F_3 ( V_12 ) ,
} ;
struct V_13 args = {
. V_6 = V_6 ,
. V_14 = V_15 ,
. V_16 = (struct V_1 * ) & sin ,
. V_17 = sizeof( sin ) ,
. V_18 = L_1 ,
. V_19 = & V_20 ,
. V_21 = V_22 ,
. V_23 = V_24 ,
. V_25 = V_26 ,
} ;
return F_4 ( & args ) ;
}
static struct V_5 * F_5 ( struct V_27 * V_28 ,
struct V_5 * V_29 )
{
F_6 ( & V_28 -> V_30 ) ;
if ( V_28 -> V_31 == 0 ) {
if ( V_29 == NULL )
goto V_32;
V_28 -> V_33 = V_29 ;
}
V_29 = V_28 -> V_33 ;
V_28 -> V_31 ++ ;
V_32:
F_7 ( & V_28 -> V_30 ) ;
return V_29 ;
}
static struct V_5 * F_8 ( struct V_6 * V_6 )
{
struct V_5 * V_29 , * V_34 ;
struct V_27 * V_28 = F_9 ( V_6 , V_35 ) ;
V_29 = F_5 ( V_28 , NULL ) ;
if ( V_29 != NULL )
goto V_32;
V_29 = V_34 = F_2 ( V_6 ) ;
if ( F_10 ( V_29 ) )
goto V_32;
V_29 = F_5 ( V_28 , V_34 ) ;
if ( V_29 != V_34 )
F_11 ( V_34 ) ;
V_32:
return V_29 ;
}
static void F_12 ( struct V_6 * V_6 )
{
struct V_27 * V_28 = F_9 ( V_6 , V_35 ) ;
struct V_5 * V_29 = NULL ;
F_6 ( & V_28 -> V_30 ) ;
V_28 -> V_31 -- ;
if ( V_28 -> V_31 == 0 ) {
V_29 = V_28 -> V_33 ;
V_28 -> V_33 = NULL ;
}
F_7 ( & V_28 -> V_30 ) ;
if ( V_29 != NULL )
F_11 ( V_29 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_1 V_36 , struct V_37 * V_38 ,
struct V_5 * V_29 )
{
int V_39 ;
struct V_40 args = {
. V_41 = & V_3 -> V_42 ,
. V_43 = V_44 ,
. V_45 = 3 ,
. V_36 = V_46 ,
. V_47 = V_3 -> V_48 ,
. V_49 = V_29 -> V_50 ,
} ;
struct V_51 V_52 = {
. V_53 = & args ,
. V_54 = V_38 ,
} ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_52 . V_55 = & V_29 -> V_56 [ V_36 ] ;
V_39 = F_14 ( V_29 , & V_52 , V_57 ) ;
if ( V_39 == - V_58 ) {
F_15 ( L_2 ,
V_39 ) ;
F_16 ( V_29 ) ;
V_39 = F_14 ( V_29 , & V_52 , V_57 ) ;
}
if ( V_39 < 0 )
F_15 ( L_3 ,
V_39 ) ;
else
V_39 = 0 ;
return V_39 ;
}
int F_17 ( const struct V_59 * V_60 )
{
struct V_2 * V_3 = V_60 -> V_61 ;
struct V_37 V_38 ;
int V_39 ;
struct V_5 * V_29 ;
F_15 ( L_4 , V_3 -> V_62 ) ;
if ( V_3 -> V_63 )
return 0 ;
V_3 -> V_48 = V_64 ? V_3 -> V_62 : V_3 -> V_65 ;
V_29 = F_8 ( V_60 -> V_6 ) ;
if ( F_10 ( V_29 ) ) {
V_39 = F_18 ( V_29 ) ;
F_15 ( L_5
L_6 , V_39 , V_60 -> V_6 ) ;
return V_39 ;
}
V_39 = F_13 ( V_3 , V_66 , & V_38 , V_29 ) ;
if ( F_19 ( V_38 . V_39 != 0 ) )
V_39 = - V_67 ;
if ( F_19 ( V_39 < 0 ) ) {
F_20 ( V_68 L_7 , V_3 -> V_62 ) ;
return V_39 ;
}
V_3 -> V_63 = 1 ;
if ( F_19 ( V_69 != V_38 . V_70 ) ) {
V_69 = V_38 . V_70 ;
F_15 ( L_8 , V_69 ) ;
}
return 0 ;
}
void F_21 ( const struct V_59 * V_60 )
{
struct V_2 * V_3 = V_60 -> V_61 ;
struct V_37 V_38 ;
int V_39 ;
if ( F_22 ( & V_3 -> V_71 ) == 1
&& V_3 -> V_63 && ! V_3 -> V_72 ) {
struct V_27 * V_28 = F_9 ( V_60 -> V_6 , V_35 ) ;
F_15 ( L_9 , V_3 -> V_62 ) ;
V_39 = F_13 ( V_3 , V_73 , & V_38 , V_28 -> V_33 ) ;
if ( V_38 . V_39 != 0 )
V_39 = - V_67 ;
if ( V_39 < 0 )
F_20 ( V_68 L_10 ,
V_3 -> V_62 ) ;
else
V_3 -> V_63 = 0 ;
F_12 ( V_60 -> V_6 ) ;
}
}
static struct V_2 * F_23 ( const char * V_74 ,
const T_2 V_75 )
{
struct V_2 * V_3 ;
F_24 (nsm, &nsm_handles, sm_link)
if ( strlen ( V_3 -> V_62 ) == V_75 &&
memcmp ( V_3 -> V_62 , V_74 , V_75 ) == 0 )
return V_3 ;
return NULL ;
}
static struct V_2 * F_25 ( const struct V_1 * V_76 )
{
struct V_2 * V_3 ;
F_24 (nsm, &nsm_handles, sm_link)
if ( F_26 ( F_1 ( V_3 ) , V_76 ) )
return V_3 ;
return NULL ;
}
static struct V_2 * F_27 ( const struct V_77 * V_41 )
{
struct V_2 * V_3 ;
F_24 (nsm, &nsm_handles, sm_link)
if ( memcmp ( V_3 -> V_42 . V_78 , V_41 -> V_78 ,
sizeof( V_41 -> V_78 ) ) == 0 )
return V_3 ;
return NULL ;
}
static void F_28 ( struct V_2 * V_3 )
{
T_3 * V_79 = ( T_3 * ) & V_3 -> V_42 . V_78 ;
T_4 V_80 ;
V_80 = F_29 () ;
F_30 ( V_80 , V_79 ) ;
F_30 ( ( unsigned long ) V_3 , V_79 + 1 ) ;
}
static struct V_2 * F_31 ( const struct V_1 * V_76 ,
const T_2 V_81 ,
const char * V_74 ,
const T_2 V_82 )
{
struct V_2 * V_34 ;
V_34 = F_32 ( sizeof( * V_34 ) + V_82 + 1 , V_83 ) ;
if ( F_19 ( V_34 == NULL ) )
return NULL ;
F_33 ( & V_34 -> V_71 , 1 ) ;
V_34 -> V_62 = ( char * ) ( V_34 + 1 ) ;
memcpy ( F_1 ( V_34 ) , V_76 , V_81 ) ;
V_34 -> V_84 = V_81 ;
F_28 ( V_34 ) ;
if ( F_34 ( F_1 ( V_34 ) , V_34 -> V_65 ,
sizeof( V_34 -> V_65 ) ) == 0 )
( void ) snprintf ( V_34 -> V_65 , sizeof( V_34 -> V_65 ) ,
L_11 ) ;
memcpy ( V_34 -> V_62 , V_74 , V_82 ) ;
V_34 -> V_62 [ V_82 ] = '\0' ;
return V_34 ;
}
struct V_2 * F_35 ( const struct V_1 * V_76 ,
const T_2 V_81 , const char * V_74 ,
const T_2 V_82 )
{
struct V_2 * V_85 , * V_34 = NULL ;
if ( V_74 && memchr ( V_74 , '/' , V_82 ) != NULL ) {
if ( F_36 () ) {
F_20 ( V_86 L_12
L_13 ,
( int ) V_82 , V_74 ) ;
}
return NULL ;
}
V_87:
F_6 ( & V_88 ) ;
if ( V_64 && V_74 != NULL )
V_85 = F_23 ( V_74 , V_82 ) ;
else
V_85 = F_25 ( V_76 ) ;
if ( V_85 != NULL ) {
F_37 ( & V_85 -> V_71 ) ;
F_7 ( & V_88 ) ;
F_38 ( V_34 ) ;
F_15 ( L_14
L_15 , V_85 -> V_62 ,
V_85 -> V_65 ,
F_22 ( & V_85 -> V_71 ) ) ;
return V_85 ;
}
if ( V_34 != NULL ) {
F_39 ( & V_34 -> V_89 , & V_90 ) ;
F_7 ( & V_88 ) ;
F_15 ( L_16 ,
V_34 -> V_62 , V_34 -> V_65 ) ;
return V_34 ;
}
F_7 ( & V_88 ) ;
V_34 = F_31 ( V_76 , V_81 , V_74 , V_82 ) ;
if ( F_19 ( V_34 == NULL ) )
return NULL ;
goto V_87;
}
struct V_2 * F_40 ( const struct V_91 * V_92 )
{
struct V_2 * V_85 ;
F_6 ( & V_88 ) ;
V_85 = F_27 ( & V_92 -> V_41 ) ;
if ( F_19 ( V_85 == NULL ) ) {
F_7 ( & V_88 ) ;
F_15 ( L_17 ,
V_92 -> V_75 , V_92 -> V_93 ) ;
return V_85 ;
}
F_37 ( & V_85 -> V_71 ) ;
F_7 ( & V_88 ) ;
F_15 ( L_18 ,
V_85 -> V_62 , V_85 -> V_65 ,
F_22 ( & V_85 -> V_71 ) ) ;
return V_85 ;
}
void F_41 ( struct V_2 * V_3 )
{
if ( F_42 ( & V_3 -> V_71 , & V_88 ) ) {
F_43 ( & V_3 -> V_89 ) ;
F_7 ( & V_88 ) ;
F_15 ( L_19 ,
V_3 -> V_62 , V_3 -> V_65 ) ;
F_38 ( V_3 ) ;
}
}
static void F_44 ( struct V_94 * V_95 , const char * string )
{
const T_1 V_75 = strlen ( string ) ;
T_5 * V_79 ;
V_79 = F_45 ( V_95 , 4 + V_75 ) ;
F_46 ( V_79 , string , V_75 ) ;
}
static void F_47 ( struct V_94 * V_95 , const struct V_40 * V_96 )
{
F_44 ( V_95 , V_96 -> V_47 ) ;
}
static void F_48 ( struct V_94 * V_95 , const struct V_40 * V_96 )
{
T_5 * V_79 ;
F_44 ( V_95 , V_96 -> V_49 ) ;
V_79 = F_45 ( V_95 , 4 + 4 + 4 ) ;
* V_79 ++ = F_49 ( V_96 -> V_43 ) ;
* V_79 ++ = F_49 ( V_96 -> V_45 ) ;
* V_79 = F_49 ( V_96 -> V_36 ) ;
}
static void F_50 ( struct V_94 * V_95 , const struct V_40 * V_96 )
{
F_47 ( V_95 , V_96 ) ;
F_48 ( V_95 , V_96 ) ;
}
static void F_51 ( struct V_94 * V_95 , const struct V_40 * V_96 )
{
T_5 * V_79 ;
V_79 = F_45 ( V_95 , V_97 ) ;
F_52 ( V_79 , V_96 -> V_41 -> V_78 , V_97 ) ;
}
static void F_53 ( struct V_98 * V_99 , struct V_94 * V_95 ,
const struct V_40 * V_96 )
{
F_50 ( V_95 , V_96 ) ;
F_51 ( V_95 , V_96 ) ;
}
static void F_54 ( struct V_98 * V_99 , struct V_94 * V_95 ,
const struct V_40 * V_96 )
{
F_50 ( V_95 , V_96 ) ;
}
static int F_55 ( struct V_98 * V_100 ,
struct V_94 * V_95 ,
struct V_37 * V_101 )
{
T_5 * V_79 ;
V_79 = F_56 ( V_95 , 4 + 4 ) ;
if ( F_19 ( V_79 == NULL ) )
return - V_67 ;
V_101 -> V_39 = F_57 ( V_79 ++ ) ;
V_101 -> V_70 = F_57 ( V_79 ) ;
F_15 ( L_20 ,
V_102 , V_101 -> V_39 , V_101 -> V_70 ) ;
return 0 ;
}
static int F_58 ( struct V_98 * V_100 ,
struct V_94 * V_95 ,
struct V_37 * V_101 )
{
T_5 * V_79 ;
V_79 = F_56 ( V_95 , 4 ) ;
if ( F_19 ( V_79 == NULL ) )
return - V_67 ;
V_101 -> V_70 = F_57 ( V_79 ) ;
F_15 ( L_21 , V_102 , V_101 -> V_70 ) ;
return 0 ;
}
