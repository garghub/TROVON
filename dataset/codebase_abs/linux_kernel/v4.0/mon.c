static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) & V_3 -> V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_6 , const char * V_7 )
{
struct V_8 sin = {
. V_9 = V_10 ,
. V_11 . V_12 = F_3 ( V_13 ) ,
} ;
struct V_14 args = {
. V_6 = V_6 ,
. V_15 = V_16 ,
. V_17 = (struct V_1 * ) & sin ,
. V_18 = sizeof( sin ) ,
. V_19 = L_1 ,
. V_7 = V_7 ,
. V_20 = & V_21 ,
. V_22 = V_23 ,
. V_24 = V_25 ,
. V_26 = V_27 ,
} ;
return F_4 ( & args ) ;
}
static struct V_5 * F_5 ( struct V_28 * V_29 ,
struct V_5 * V_30 )
{
F_6 ( & V_29 -> V_31 ) ;
if ( V_29 -> V_32 == 0 ) {
if ( V_30 == NULL )
goto V_33;
V_29 -> V_34 = V_30 ;
}
V_30 = V_29 -> V_34 ;
V_29 -> V_32 ++ ;
V_33:
F_7 ( & V_29 -> V_31 ) ;
return V_30 ;
}
static struct V_5 * F_8 ( struct V_6 * V_6 , const char * V_7 )
{
struct V_5 * V_30 , * V_35 ;
struct V_28 * V_29 = F_9 ( V_6 , V_36 ) ;
V_30 = F_5 ( V_29 , NULL ) ;
if ( V_30 != NULL )
goto V_33;
V_30 = V_35 = F_2 ( V_6 , V_7 ) ;
if ( F_10 ( V_30 ) )
goto V_33;
V_30 = F_5 ( V_29 , V_35 ) ;
if ( V_30 != V_35 )
F_11 ( V_35 ) ;
V_33:
return V_30 ;
}
static void F_12 ( struct V_6 * V_6 )
{
struct V_28 * V_29 = F_9 ( V_6 , V_36 ) ;
struct V_5 * V_30 = NULL ;
F_6 ( & V_29 -> V_31 ) ;
V_29 -> V_32 -- ;
if ( V_29 -> V_32 == 0 ) {
V_30 = V_29 -> V_34 ;
V_29 -> V_34 = NULL ;
}
F_7 ( & V_29 -> V_31 ) ;
if ( V_30 != NULL )
F_11 ( V_30 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_1 V_37 , struct V_38 * V_39 ,
struct V_5 * V_30 )
{
int V_40 ;
struct V_41 args = {
. V_42 = & V_3 -> V_43 ,
. V_44 = V_45 ,
. V_46 = 3 ,
. V_37 = V_47 ,
. V_48 = V_3 -> V_49 ,
. V_7 = V_30 -> V_50 ,
} ;
struct V_51 V_52 = {
. V_53 = & args ,
. V_54 = V_39 ,
} ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_52 . V_55 = & V_30 -> V_56 [ V_37 ] ;
V_40 = F_14 ( V_30 , & V_52 , V_57 ) ;
if ( V_40 == - V_58 ) {
F_15 ( L_2 ,
V_40 ) ;
F_16 ( V_30 ) ;
V_40 = F_14 ( V_30 , & V_52 , V_57 ) ;
}
if ( V_40 < 0 )
F_15 ( L_3 ,
V_40 ) ;
else
V_40 = 0 ;
return V_40 ;
}
int F_17 ( const struct V_59 * V_60 )
{
struct V_2 * V_3 = V_60 -> V_61 ;
struct V_38 V_39 ;
int V_40 ;
struct V_5 * V_30 ;
const char * V_7 = NULL ;
F_15 ( L_4 , V_3 -> V_62 ) ;
if ( V_3 -> V_63 )
return 0 ;
if ( V_60 -> V_64 )
V_7 = V_60 -> V_64 -> V_50 ;
V_3 -> V_49 = V_65 ? V_3 -> V_62 : V_3 -> V_66 ;
V_30 = F_8 ( V_60 -> V_6 , V_7 ) ;
if ( F_10 ( V_30 ) ) {
V_40 = F_18 ( V_30 ) ;
F_15 ( L_5
L_6 , V_40 , V_60 -> V_6 ) ;
return V_40 ;
}
V_40 = F_13 ( V_3 , V_67 , & V_39 , V_30 ) ;
if ( F_19 ( V_39 . V_40 != 0 ) )
V_40 = - V_68 ;
if ( F_19 ( V_40 < 0 ) ) {
F_20 ( L_7 , V_3 -> V_62 ) ;
return V_40 ;
}
V_3 -> V_63 = 1 ;
if ( F_19 ( V_69 != V_39 . V_70 ) ) {
V_69 = V_39 . V_70 ;
F_15 ( L_8 , V_69 ) ;
}
return 0 ;
}
void F_21 ( const struct V_59 * V_60 )
{
struct V_2 * V_3 = V_60 -> V_61 ;
struct V_38 V_39 ;
int V_40 ;
if ( F_22 ( & V_3 -> V_71 ) == 1
&& V_3 -> V_63 && ! V_3 -> V_72 ) {
struct V_28 * V_29 = F_9 ( V_60 -> V_6 , V_36 ) ;
F_15 ( L_9 , V_3 -> V_62 ) ;
V_40 = F_13 ( V_3 , V_73 , & V_39 , V_29 -> V_34 ) ;
if ( V_39 . V_40 != 0 )
V_40 = - V_68 ;
if ( V_40 < 0 )
F_23 ( V_74 L_10 ,
V_3 -> V_62 ) ;
else
V_3 -> V_63 = 0 ;
F_12 ( V_60 -> V_6 ) ;
}
}
static struct V_2 * F_24 ( const char * V_75 ,
const T_2 V_76 )
{
struct V_2 * V_3 ;
F_25 (nsm, &nsm_handles, sm_link)
if ( strlen ( V_3 -> V_62 ) == V_76 &&
memcmp ( V_3 -> V_62 , V_75 , V_76 ) == 0 )
return V_3 ;
return NULL ;
}
static struct V_2 * F_26 ( const struct V_1 * V_77 )
{
struct V_2 * V_3 ;
F_25 (nsm, &nsm_handles, sm_link)
if ( F_27 ( F_1 ( V_3 ) , V_77 ) )
return V_3 ;
return NULL ;
}
static struct V_2 * F_28 ( const struct V_78 * V_42 )
{
struct V_2 * V_3 ;
F_25 (nsm, &nsm_handles, sm_link)
if ( memcmp ( V_3 -> V_43 . V_79 , V_42 -> V_79 ,
sizeof( V_42 -> V_79 ) ) == 0 )
return V_3 ;
return NULL ;
}
static void F_29 ( struct V_2 * V_3 )
{
T_3 * V_80 = ( T_3 * ) & V_3 -> V_43 . V_79 ;
T_4 V_81 ;
V_81 = F_30 () ;
F_31 ( V_81 , V_80 ) ;
F_31 ( ( unsigned long ) V_3 , V_80 + 1 ) ;
}
static struct V_2 * F_32 ( const struct V_1 * V_77 ,
const T_2 V_82 ,
const char * V_75 ,
const T_2 V_83 )
{
struct V_2 * V_35 ;
V_35 = F_33 ( sizeof( * V_35 ) + V_83 + 1 , V_84 ) ;
if ( F_19 ( V_35 == NULL ) )
return NULL ;
F_34 ( & V_35 -> V_71 , 1 ) ;
V_35 -> V_62 = ( char * ) ( V_35 + 1 ) ;
memcpy ( F_1 ( V_35 ) , V_77 , V_82 ) ;
V_35 -> V_85 = V_82 ;
F_29 ( V_35 ) ;
if ( F_35 ( F_1 ( V_35 ) , V_35 -> V_66 ,
sizeof( V_35 -> V_66 ) ) == 0 )
( void ) snprintf ( V_35 -> V_66 , sizeof( V_35 -> V_66 ) ,
L_11 ) ;
memcpy ( V_35 -> V_62 , V_75 , V_83 ) ;
V_35 -> V_62 [ V_83 ] = '\0' ;
return V_35 ;
}
struct V_2 * F_36 ( const struct V_1 * V_77 ,
const T_2 V_82 , const char * V_75 ,
const T_2 V_83 )
{
struct V_2 * V_86 , * V_35 = NULL ;
if ( V_75 && memchr ( V_75 , '/' , V_83 ) != NULL ) {
if ( F_37 () ) {
F_23 ( V_87 L_12
L_13 ,
( int ) V_83 , V_75 ) ;
}
return NULL ;
}
V_88:
F_6 ( & V_89 ) ;
if ( V_65 && V_75 != NULL )
V_86 = F_24 ( V_75 , V_83 ) ;
else
V_86 = F_26 ( V_77 ) ;
if ( V_86 != NULL ) {
F_38 ( & V_86 -> V_71 ) ;
F_7 ( & V_89 ) ;
F_39 ( V_35 ) ;
F_15 ( L_14
L_15 , V_86 -> V_62 ,
V_86 -> V_66 ,
F_22 ( & V_86 -> V_71 ) ) ;
return V_86 ;
}
if ( V_35 != NULL ) {
F_40 ( & V_35 -> V_90 , & V_91 ) ;
F_7 ( & V_89 ) ;
F_15 ( L_16 ,
V_35 -> V_62 , V_35 -> V_66 ) ;
return V_35 ;
}
F_7 ( & V_89 ) ;
V_35 = F_32 ( V_77 , V_82 , V_75 , V_83 ) ;
if ( F_19 ( V_35 == NULL ) )
return NULL ;
goto V_88;
}
struct V_2 * F_41 ( const struct V_92 * V_93 )
{
struct V_2 * V_86 ;
F_6 ( & V_89 ) ;
V_86 = F_28 ( & V_93 -> V_42 ) ;
if ( F_19 ( V_86 == NULL ) ) {
F_7 ( & V_89 ) ;
F_15 ( L_17 ,
V_93 -> V_76 , V_93 -> V_94 ) ;
return V_86 ;
}
F_38 ( & V_86 -> V_71 ) ;
F_7 ( & V_89 ) ;
F_15 ( L_18 ,
V_86 -> V_62 , V_86 -> V_66 ,
F_22 ( & V_86 -> V_71 ) ) ;
return V_86 ;
}
void F_42 ( struct V_2 * V_3 )
{
if ( F_43 ( & V_3 -> V_71 , & V_89 ) ) {
F_44 ( & V_3 -> V_90 ) ;
F_7 ( & V_89 ) ;
F_15 ( L_19 ,
V_3 -> V_62 , V_3 -> V_66 ) ;
F_39 ( V_3 ) ;
}
}
static void F_45 ( struct V_95 * V_96 , const char * string )
{
const T_1 V_76 = strlen ( string ) ;
T_5 * V_80 ;
V_80 = F_46 ( V_96 , 4 + V_76 ) ;
F_47 ( V_80 , string , V_76 ) ;
}
static void F_48 ( struct V_95 * V_96 , const struct V_41 * V_97 )
{
F_45 ( V_96 , V_97 -> V_48 ) ;
}
static void F_49 ( struct V_95 * V_96 , const struct V_41 * V_97 )
{
T_5 * V_80 ;
F_45 ( V_96 , V_97 -> V_7 ) ;
V_80 = F_46 ( V_96 , 4 + 4 + 4 ) ;
* V_80 ++ = F_50 ( V_97 -> V_44 ) ;
* V_80 ++ = F_50 ( V_97 -> V_46 ) ;
* V_80 = F_50 ( V_97 -> V_37 ) ;
}
static void F_51 ( struct V_95 * V_96 , const struct V_41 * V_97 )
{
F_48 ( V_96 , V_97 ) ;
F_49 ( V_96 , V_97 ) ;
}
static void F_52 ( struct V_95 * V_96 , const struct V_41 * V_97 )
{
T_5 * V_80 ;
V_80 = F_46 ( V_96 , V_98 ) ;
F_53 ( V_80 , V_97 -> V_42 -> V_79 , V_98 ) ;
}
static void F_54 ( struct V_99 * V_100 , struct V_95 * V_96 ,
const struct V_41 * V_97 )
{
F_51 ( V_96 , V_97 ) ;
F_52 ( V_96 , V_97 ) ;
}
static void F_55 ( struct V_99 * V_100 , struct V_95 * V_96 ,
const struct V_41 * V_97 )
{
F_51 ( V_96 , V_97 ) ;
}
static int F_56 ( struct V_99 * V_101 ,
struct V_95 * V_96 ,
struct V_38 * V_102 )
{
T_5 * V_80 ;
V_80 = F_57 ( V_96 , 4 + 4 ) ;
if ( F_19 ( V_80 == NULL ) )
return - V_68 ;
V_102 -> V_40 = F_58 ( V_80 ++ ) ;
V_102 -> V_70 = F_58 ( V_80 ) ;
F_15 ( L_20 ,
V_103 , V_102 -> V_40 , V_102 -> V_70 ) ;
return 0 ;
}
static int F_59 ( struct V_99 * V_101 ,
struct V_95 * V_96 ,
struct V_38 * V_102 )
{
T_5 * V_80 ;
V_80 = F_57 ( V_96 , 4 ) ;
if ( F_19 ( V_80 == NULL ) )
return - V_68 ;
V_102 -> V_70 = F_58 ( V_80 ) ;
F_15 ( L_21 , V_103 , V_102 -> V_70 ) ;
return 0 ;
}
