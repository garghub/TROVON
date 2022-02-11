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
F_14 ( V_29 == NULL ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_52 . V_55 = & V_29 -> V_56 [ V_36 ] ;
V_39 = F_15 ( V_29 , & V_52 , V_57 ) ;
if ( V_39 < 0 )
F_16 ( L_2 ,
V_39 ) ;
else
V_39 = 0 ;
return V_39 ;
}
int F_17 ( const struct V_58 * V_59 )
{
struct V_2 * V_3 = V_59 -> V_60 ;
struct V_37 V_38 ;
int V_39 ;
struct V_5 * V_29 ;
F_16 ( L_3 , V_3 -> V_61 ) ;
if ( V_3 -> V_62 )
return 0 ;
V_3 -> V_48 = V_63 ? V_3 -> V_61 : V_3 -> V_64 ;
V_29 = F_8 ( V_59 -> V_6 ) ;
if ( F_10 ( V_29 ) ) {
V_39 = F_18 ( V_29 ) ;
F_16 ( L_4
L_5 , V_39 , V_59 -> V_6 ) ;
return V_39 ;
}
V_39 = F_13 ( V_3 , V_65 , & V_38 , V_29 ) ;
if ( F_19 ( V_38 . V_39 != 0 ) )
V_39 = - V_66 ;
if ( F_19 ( V_39 < 0 ) ) {
F_20 ( V_67 L_6 , V_3 -> V_61 ) ;
return V_39 ;
}
V_3 -> V_62 = 1 ;
if ( F_19 ( V_68 != V_38 . V_69 ) ) {
V_68 = V_38 . V_69 ;
F_16 ( L_7 , V_68 ) ;
}
return 0 ;
}
void F_21 ( const struct V_58 * V_59 )
{
struct V_2 * V_3 = V_59 -> V_60 ;
struct V_37 V_38 ;
int V_39 ;
if ( F_22 ( & V_3 -> V_70 ) == 1
&& V_3 -> V_62 && ! V_3 -> V_71 ) {
struct V_27 * V_28 = F_9 ( V_59 -> V_6 , V_35 ) ;
F_16 ( L_8 , V_3 -> V_61 ) ;
V_39 = F_13 ( V_3 , V_72 , & V_38 , V_28 -> V_33 ) ;
if ( V_38 . V_39 != 0 )
V_39 = - V_66 ;
if ( V_39 < 0 )
F_20 ( V_67 L_9 ,
V_3 -> V_61 ) ;
else
V_3 -> V_62 = 0 ;
F_12 ( V_59 -> V_6 ) ;
}
}
static struct V_2 * F_23 ( const char * V_73 ,
const T_2 V_74 )
{
struct V_2 * V_3 ;
F_24 (nsm, &nsm_handles, sm_link)
if ( strlen ( V_3 -> V_61 ) == V_74 &&
memcmp ( V_3 -> V_61 , V_73 , V_74 ) == 0 )
return V_3 ;
return NULL ;
}
static struct V_2 * F_25 ( const struct V_1 * V_75 )
{
struct V_2 * V_3 ;
F_24 (nsm, &nsm_handles, sm_link)
if ( F_26 ( F_1 ( V_3 ) , V_75 ) )
return V_3 ;
return NULL ;
}
static struct V_2 * F_27 ( const struct V_76 * V_41 )
{
struct V_2 * V_3 ;
F_24 (nsm, &nsm_handles, sm_link)
if ( memcmp ( V_3 -> V_42 . V_77 , V_41 -> V_77 ,
sizeof( V_41 -> V_77 ) ) == 0 )
return V_3 ;
return NULL ;
}
static void F_28 ( struct V_2 * V_3 )
{
T_3 * V_78 = ( T_3 * ) & V_3 -> V_42 . V_77 ;
struct V_79 V_80 ;
T_4 V_81 ;
F_29 ( & V_80 ) ;
V_81 = F_30 ( & V_80 ) ;
F_31 ( V_81 , V_78 ) ;
F_31 ( ( unsigned long ) V_3 , V_78 + 1 ) ;
}
static struct V_2 * F_32 ( const struct V_1 * V_75 ,
const T_2 V_82 ,
const char * V_73 ,
const T_2 V_83 )
{
struct V_2 * V_34 ;
V_34 = F_33 ( sizeof( * V_34 ) + V_83 + 1 , V_84 ) ;
if ( F_19 ( V_34 == NULL ) )
return NULL ;
F_34 ( & V_34 -> V_70 , 1 ) ;
V_34 -> V_61 = ( char * ) ( V_34 + 1 ) ;
memcpy ( F_1 ( V_34 ) , V_75 , V_82 ) ;
V_34 -> V_85 = V_82 ;
F_28 ( V_34 ) ;
if ( F_35 ( F_1 ( V_34 ) , V_34 -> V_64 ,
sizeof( V_34 -> V_64 ) ) == 0 )
( void ) snprintf ( V_34 -> V_64 , sizeof( V_34 -> V_64 ) ,
L_10 ) ;
memcpy ( V_34 -> V_61 , V_73 , V_83 ) ;
V_34 -> V_61 [ V_83 ] = '\0' ;
return V_34 ;
}
struct V_2 * F_36 ( const struct V_1 * V_75 ,
const T_2 V_82 , const char * V_73 ,
const T_2 V_83 )
{
struct V_2 * V_86 , * V_34 = NULL ;
if ( V_73 && memchr ( V_73 , '/' , V_83 ) != NULL ) {
if ( F_37 () ) {
F_20 ( V_87 L_11
L_12 ,
( int ) V_83 , V_73 ) ;
}
return NULL ;
}
V_88:
F_6 ( & V_89 ) ;
if ( V_63 && V_73 != NULL )
V_86 = F_23 ( V_73 , V_83 ) ;
else
V_86 = F_25 ( V_75 ) ;
if ( V_86 != NULL ) {
F_38 ( & V_86 -> V_70 ) ;
F_7 ( & V_89 ) ;
F_39 ( V_34 ) ;
F_16 ( L_13
L_14 , V_86 -> V_61 ,
V_86 -> V_64 ,
F_22 ( & V_86 -> V_70 ) ) ;
return V_86 ;
}
if ( V_34 != NULL ) {
F_40 ( & V_34 -> V_90 , & V_91 ) ;
F_7 ( & V_89 ) ;
F_16 ( L_15 ,
V_34 -> V_61 , V_34 -> V_64 ) ;
return V_34 ;
}
F_7 ( & V_89 ) ;
V_34 = F_32 ( V_75 , V_82 , V_73 , V_83 ) ;
if ( F_19 ( V_34 == NULL ) )
return NULL ;
goto V_88;
}
struct V_2 * F_41 ( const struct V_92 * V_93 )
{
struct V_2 * V_86 ;
F_6 ( & V_89 ) ;
V_86 = F_27 ( & V_93 -> V_41 ) ;
if ( F_19 ( V_86 == NULL ) ) {
F_7 ( & V_89 ) ;
F_16 ( L_16 ,
V_93 -> V_74 , V_93 -> V_94 ) ;
return V_86 ;
}
F_38 ( & V_86 -> V_70 ) ;
F_7 ( & V_89 ) ;
F_16 ( L_17 ,
V_86 -> V_61 , V_86 -> V_64 ,
F_22 ( & V_86 -> V_70 ) ) ;
return V_86 ;
}
void F_42 ( struct V_2 * V_3 )
{
if ( F_43 ( & V_3 -> V_70 , & V_89 ) ) {
F_44 ( & V_3 -> V_90 ) ;
F_7 ( & V_89 ) ;
F_16 ( L_18 ,
V_3 -> V_61 , V_3 -> V_64 ) ;
F_39 ( V_3 ) ;
}
}
static void F_45 ( struct V_95 * V_96 , const char * string )
{
const T_1 V_74 = strlen ( string ) ;
T_5 * V_78 ;
F_14 ( V_74 > V_97 ) ;
V_78 = F_46 ( V_96 , 4 + V_74 ) ;
F_47 ( V_78 , string , V_74 ) ;
}
static void F_48 ( struct V_95 * V_96 , const struct V_40 * V_98 )
{
F_45 ( V_96 , V_98 -> V_47 ) ;
}
static void F_49 ( struct V_95 * V_96 , const struct V_40 * V_98 )
{
T_5 * V_78 ;
F_45 ( V_96 , V_98 -> V_49 ) ;
V_78 = F_46 ( V_96 , 4 + 4 + 4 ) ;
* V_78 ++ = F_50 ( V_98 -> V_43 ) ;
* V_78 ++ = F_50 ( V_98 -> V_45 ) ;
* V_78 = F_50 ( V_98 -> V_36 ) ;
}
static void F_51 ( struct V_95 * V_96 , const struct V_40 * V_98 )
{
F_48 ( V_96 , V_98 ) ;
F_49 ( V_96 , V_98 ) ;
}
static void F_52 ( struct V_95 * V_96 , const struct V_40 * V_98 )
{
T_5 * V_78 ;
V_78 = F_46 ( V_96 , V_99 ) ;
F_53 ( V_78 , V_98 -> V_41 -> V_77 , V_99 ) ;
}
static void F_54 ( struct V_100 * V_101 , struct V_95 * V_96 ,
const struct V_40 * V_98 )
{
F_51 ( V_96 , V_98 ) ;
F_52 ( V_96 , V_98 ) ;
}
static void F_55 ( struct V_100 * V_101 , struct V_95 * V_96 ,
const struct V_40 * V_98 )
{
F_51 ( V_96 , V_98 ) ;
}
static int F_56 ( struct V_100 * V_102 ,
struct V_95 * V_96 ,
struct V_37 * V_103 )
{
T_5 * V_78 ;
V_78 = F_57 ( V_96 , 4 + 4 ) ;
if ( F_19 ( V_78 == NULL ) )
return - V_66 ;
V_103 -> V_39 = F_58 ( V_78 ++ ) ;
V_103 -> V_69 = F_58 ( V_78 ) ;
F_16 ( L_19 ,
V_104 , V_103 -> V_39 , V_103 -> V_69 ) ;
return 0 ;
}
static int F_59 ( struct V_100 * V_102 ,
struct V_95 * V_96 ,
struct V_37 * V_103 )
{
T_5 * V_78 ;
V_78 = F_57 ( V_96 , 4 ) ;
if ( F_19 ( V_78 == NULL ) )
return - V_66 ;
V_103 -> V_69 = F_58 ( V_78 ) ;
F_16 ( L_20 , V_104 , V_103 -> V_69 ) ;
return 0 ;
}
