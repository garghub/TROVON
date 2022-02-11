static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) & V_3 -> V_4 ;
}
static struct V_5 * F_2 ( void )
{
struct V_6 sin = {
. V_7 = V_8 ,
. V_9 . V_10 = F_3 ( V_11 ) ,
} ;
struct V_12 args = {
. V_13 = & V_14 ,
. V_15 = V_16 ,
. V_17 = (struct V_1 * ) & sin ,
. V_18 = sizeof( sin ) ,
. V_19 = L_1 ,
. V_20 = & V_21 ,
. V_22 = V_23 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
} ;
return F_4 ( & args ) ;
}
static int F_5 ( struct V_2 * V_3 , T_1 V_28 , struct V_29 * V_30 )
{
struct V_5 * V_31 ;
int V_32 ;
struct V_33 args = {
. V_34 = & V_3 -> V_35 ,
. V_36 = V_37 ,
. V_38 = 3 ,
. V_28 = V_39 ,
. V_40 = V_3 -> V_41 ,
} ;
struct V_42 V_43 = {
. V_44 = & args ,
. V_45 = V_30 ,
} ;
V_31 = F_2 () ;
if ( F_6 ( V_31 ) ) {
V_32 = F_7 ( V_31 ) ;
F_8 ( L_2
L_3 , V_32 ) ;
goto V_46;
}
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_43 . V_47 = & V_31 -> V_48 [ V_28 ] ;
V_32 = F_9 ( V_31 , & V_43 , 0 ) ;
if ( V_32 < 0 )
F_8 ( L_4 ,
V_32 ) ;
else
V_32 = 0 ;
F_10 ( V_31 ) ;
V_46:
return V_32 ;
}
int F_11 ( const struct V_49 * V_50 )
{
struct V_2 * V_3 = V_50 -> V_51 ;
struct V_29 V_30 ;
int V_32 ;
F_8 ( L_5 , V_3 -> V_52 ) ;
if ( V_3 -> V_53 )
return 0 ;
V_3 -> V_41 = V_54 ? V_3 -> V_52 : V_3 -> V_55 ;
V_32 = F_5 ( V_3 , V_56 , & V_30 ) ;
if ( F_12 ( V_30 . V_32 != 0 ) )
V_32 = - V_57 ;
if ( F_12 ( V_32 < 0 ) ) {
F_13 ( V_58 L_6 , V_3 -> V_52 ) ;
return V_32 ;
}
V_3 -> V_53 = 1 ;
if ( F_12 ( V_59 != V_30 . V_60 ) ) {
V_59 = V_30 . V_60 ;
F_8 ( L_7 , V_59 ) ;
}
return 0 ;
}
void F_14 ( const struct V_49 * V_50 )
{
struct V_2 * V_3 = V_50 -> V_51 ;
struct V_29 V_30 ;
int V_32 ;
if ( F_15 ( & V_3 -> V_61 ) == 1
&& V_3 -> V_53 && ! V_3 -> V_62 ) {
F_8 ( L_8 , V_3 -> V_52 ) ;
V_32 = F_5 ( V_3 , V_63 , & V_30 ) ;
if ( V_30 . V_32 != 0 )
V_32 = - V_57 ;
if ( V_32 < 0 )
F_13 ( V_58 L_9 ,
V_3 -> V_52 ) ;
else
V_3 -> V_53 = 0 ;
}
}
static struct V_2 * F_16 ( const char * V_64 ,
const T_2 V_65 )
{
struct V_2 * V_3 ;
F_17 (nsm, &nsm_handles, sm_link)
if ( strlen ( V_3 -> V_52 ) == V_65 &&
memcmp ( V_3 -> V_52 , V_64 , V_65 ) == 0 )
return V_3 ;
return NULL ;
}
static struct V_2 * F_18 ( const struct V_1 * V_66 )
{
struct V_2 * V_3 ;
F_17 (nsm, &nsm_handles, sm_link)
if ( F_19 ( F_1 ( V_3 ) , V_66 ) )
return V_3 ;
return NULL ;
}
static struct V_2 * F_20 ( const struct V_67 * V_34 )
{
struct V_2 * V_3 ;
F_17 (nsm, &nsm_handles, sm_link)
if ( memcmp ( V_3 -> V_35 . V_68 , V_34 -> V_68 ,
sizeof( V_34 -> V_68 ) ) == 0 )
return V_3 ;
return NULL ;
}
static void F_21 ( struct V_2 * V_3 )
{
T_3 * V_69 = ( T_3 * ) & V_3 -> V_35 . V_68 ;
struct V_70 V_71 ;
T_4 V_72 ;
F_22 ( & V_71 ) ;
V_72 = F_23 ( & V_71 ) ;
F_24 ( V_72 , V_69 ) ;
F_24 ( ( unsigned long ) V_3 , V_69 + 1 ) ;
}
static struct V_2 * F_25 ( const struct V_1 * V_66 ,
const T_2 V_73 ,
const char * V_64 ,
const T_2 V_74 )
{
struct V_2 * V_75 ;
V_75 = F_26 ( sizeof( * V_75 ) + V_74 + 1 , V_76 ) ;
if ( F_12 ( V_75 == NULL ) )
return NULL ;
F_27 ( & V_75 -> V_61 , 1 ) ;
V_75 -> V_52 = ( char * ) ( V_75 + 1 ) ;
memcpy ( F_1 ( V_75 ) , V_66 , V_73 ) ;
V_75 -> V_77 = V_73 ;
F_21 ( V_75 ) ;
if ( F_28 ( F_1 ( V_75 ) , V_75 -> V_55 ,
sizeof( V_75 -> V_55 ) ) == 0 )
( void ) snprintf ( V_75 -> V_55 , sizeof( V_75 -> V_55 ) ,
L_10 ) ;
memcpy ( V_75 -> V_52 , V_64 , V_74 ) ;
V_75 -> V_52 [ V_74 ] = '\0' ;
return V_75 ;
}
struct V_2 * F_29 ( const struct V_1 * V_66 ,
const T_2 V_73 , const char * V_64 ,
const T_2 V_74 )
{
struct V_2 * V_78 , * V_75 = NULL ;
if ( V_64 && memchr ( V_64 , '/' , V_74 ) != NULL ) {
if ( F_30 () ) {
F_13 ( V_79 L_11
L_12 ,
( int ) V_74 , V_64 ) ;
}
return NULL ;
}
V_80:
F_31 ( & V_81 ) ;
if ( V_54 && V_64 != NULL )
V_78 = F_16 ( V_64 , V_74 ) ;
else
V_78 = F_18 ( V_66 ) ;
if ( V_78 != NULL ) {
F_32 ( & V_78 -> V_61 ) ;
F_33 ( & V_81 ) ;
F_34 ( V_75 ) ;
F_8 ( L_13
L_14 , V_78 -> V_52 ,
V_78 -> V_55 ,
F_15 ( & V_78 -> V_61 ) ) ;
return V_78 ;
}
if ( V_75 != NULL ) {
F_35 ( & V_75 -> V_82 , & V_83 ) ;
F_33 ( & V_81 ) ;
F_8 ( L_15 ,
V_75 -> V_52 , V_75 -> V_55 ) ;
return V_75 ;
}
F_33 ( & V_81 ) ;
V_75 = F_25 ( V_66 , V_73 , V_64 , V_74 ) ;
if ( F_12 ( V_75 == NULL ) )
return NULL ;
goto V_80;
}
struct V_2 * F_36 ( const struct V_84 * V_85 )
{
struct V_2 * V_78 ;
F_31 ( & V_81 ) ;
V_78 = F_20 ( & V_85 -> V_34 ) ;
if ( F_12 ( V_78 == NULL ) ) {
F_33 ( & V_81 ) ;
F_8 ( L_16 ,
V_85 -> V_65 , V_85 -> V_86 ) ;
return V_78 ;
}
F_32 ( & V_78 -> V_61 ) ;
F_33 ( & V_81 ) ;
F_8 ( L_17 ,
V_78 -> V_52 , V_78 -> V_55 ,
F_15 ( & V_78 -> V_61 ) ) ;
return V_78 ;
}
void F_37 ( struct V_2 * V_3 )
{
if ( F_38 ( & V_3 -> V_61 , & V_81 ) ) {
F_39 ( & V_3 -> V_82 ) ;
F_33 ( & V_81 ) ;
F_8 ( L_18 ,
V_3 -> V_52 , V_3 -> V_55 ) ;
F_34 ( V_3 ) ;
}
}
static void F_40 ( struct V_87 * V_88 , const char * string )
{
const T_1 V_65 = strlen ( string ) ;
T_5 * V_69 ;
F_41 ( V_65 > V_89 ) ;
V_69 = F_42 ( V_88 , 4 + V_65 ) ;
F_43 ( V_69 , string , V_65 ) ;
}
static void F_44 ( struct V_87 * V_88 , const struct V_33 * V_90 )
{
F_40 ( V_88 , V_90 -> V_40 ) ;
}
static void F_45 ( struct V_87 * V_88 , const struct V_33 * V_90 )
{
T_5 * V_69 ;
F_40 ( V_88 , F_46 () -> V_91 ) ;
V_69 = F_42 ( V_88 , 4 + 4 + 4 ) ;
* V_69 ++ = F_47 ( V_90 -> V_36 ) ;
* V_69 ++ = F_47 ( V_90 -> V_38 ) ;
* V_69 = F_47 ( V_90 -> V_28 ) ;
}
static void F_48 ( struct V_87 * V_88 , const struct V_33 * V_90 )
{
F_44 ( V_88 , V_90 ) ;
F_45 ( V_88 , V_90 ) ;
}
static void F_49 ( struct V_87 * V_88 , const struct V_33 * V_90 )
{
T_5 * V_69 ;
V_69 = F_42 ( V_88 , V_92 ) ;
F_50 ( V_69 , V_90 -> V_34 -> V_68 , V_92 ) ;
}
static void F_51 ( struct V_93 * V_94 , struct V_87 * V_88 ,
const struct V_33 * V_90 )
{
F_48 ( V_88 , V_90 ) ;
F_49 ( V_88 , V_90 ) ;
}
static void F_52 ( struct V_93 * V_94 , struct V_87 * V_88 ,
const struct V_33 * V_90 )
{
F_48 ( V_88 , V_90 ) ;
}
static int F_53 ( struct V_93 * V_95 ,
struct V_87 * V_88 ,
struct V_29 * V_96 )
{
T_5 * V_69 ;
V_69 = F_54 ( V_88 , 4 + 4 ) ;
if ( F_12 ( V_69 == NULL ) )
return - V_57 ;
V_96 -> V_32 = F_55 ( V_69 ++ ) ;
V_96 -> V_60 = F_55 ( V_69 ) ;
F_8 ( L_19 ,
V_97 , V_96 -> V_32 , V_96 -> V_60 ) ;
return 0 ;
}
static int F_56 ( struct V_93 * V_95 ,
struct V_87 * V_88 ,
struct V_29 * V_96 )
{
T_5 * V_69 ;
V_69 = F_54 ( V_88 , 4 ) ;
if ( F_12 ( V_69 == NULL ) )
return - V_57 ;
V_96 -> V_60 = F_55 ( V_69 ) ;
F_8 ( L_20 , V_97 , V_96 -> V_60 ) ;
return 0 ;
}
