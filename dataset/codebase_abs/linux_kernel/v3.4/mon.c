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
static int F_5 ( struct V_2 * V_3 , T_1 V_27 , struct V_28 * V_29 ,
struct V_6 * V_6 )
{
struct V_5 * V_30 ;
int V_31 ;
struct V_32 args = {
. V_33 = & V_3 -> V_34 ,
. V_35 = V_36 ,
. V_37 = 3 ,
. V_27 = V_38 ,
. V_39 = V_3 -> V_40 ,
} ;
struct V_41 V_42 = {
. V_43 = & args ,
. V_44 = V_29 ,
} ;
V_30 = F_2 ( V_6 ) ;
if ( F_6 ( V_30 ) ) {
V_31 = F_7 ( V_30 ) ;
F_8 ( L_2
L_3 , V_31 ) ;
goto V_45;
}
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_42 . V_46 = & V_30 -> V_47 [ V_27 ] ;
V_31 = F_9 ( V_30 , & V_42 , 0 ) ;
if ( V_31 < 0 )
F_8 ( L_4 ,
V_31 ) ;
else
V_31 = 0 ;
F_10 ( V_30 ) ;
V_45:
return V_31 ;
}
int F_11 ( const struct V_48 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_50 ;
struct V_28 V_29 ;
int V_31 ;
F_8 ( L_5 , V_3 -> V_51 ) ;
if ( V_3 -> V_52 )
return 0 ;
V_3 -> V_40 = V_53 ? V_3 -> V_51 : V_3 -> V_54 ;
V_31 = F_5 ( V_3 , V_55 , & V_29 , V_49 -> V_6 ) ;
if ( F_12 ( V_29 . V_31 != 0 ) )
V_31 = - V_56 ;
if ( F_12 ( V_31 < 0 ) ) {
F_13 ( V_57 L_6 , V_3 -> V_51 ) ;
return V_31 ;
}
V_3 -> V_52 = 1 ;
if ( F_12 ( V_58 != V_29 . V_59 ) ) {
V_58 = V_29 . V_59 ;
F_8 ( L_7 , V_58 ) ;
}
return 0 ;
}
void F_14 ( const struct V_48 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_50 ;
struct V_28 V_29 ;
int V_31 ;
if ( F_15 ( & V_3 -> V_60 ) == 1
&& V_3 -> V_52 && ! V_3 -> V_61 ) {
F_8 ( L_8 , V_3 -> V_51 ) ;
V_31 = F_5 ( V_3 , V_62 , & V_29 , V_49 -> V_6 ) ;
if ( V_29 . V_31 != 0 )
V_31 = - V_56 ;
if ( V_31 < 0 )
F_13 ( V_57 L_9 ,
V_3 -> V_51 ) ;
else
V_3 -> V_52 = 0 ;
}
}
static struct V_2 * F_16 ( const char * V_63 ,
const T_2 V_64 )
{
struct V_2 * V_3 ;
F_17 (nsm, &nsm_handles, sm_link)
if ( strlen ( V_3 -> V_51 ) == V_64 &&
memcmp ( V_3 -> V_51 , V_63 , V_64 ) == 0 )
return V_3 ;
return NULL ;
}
static struct V_2 * F_18 ( const struct V_1 * V_65 )
{
struct V_2 * V_3 ;
F_17 (nsm, &nsm_handles, sm_link)
if ( F_19 ( F_1 ( V_3 ) , V_65 ) )
return V_3 ;
return NULL ;
}
static struct V_2 * F_20 ( const struct V_66 * V_33 )
{
struct V_2 * V_3 ;
F_17 (nsm, &nsm_handles, sm_link)
if ( memcmp ( V_3 -> V_34 . V_67 , V_33 -> V_67 ,
sizeof( V_33 -> V_67 ) ) == 0 )
return V_3 ;
return NULL ;
}
static void F_21 ( struct V_2 * V_3 )
{
T_3 * V_68 = ( T_3 * ) & V_3 -> V_34 . V_67 ;
struct V_69 V_70 ;
T_4 V_71 ;
F_22 ( & V_70 ) ;
V_71 = F_23 ( & V_70 ) ;
F_24 ( V_71 , V_68 ) ;
F_24 ( ( unsigned long ) V_3 , V_68 + 1 ) ;
}
static struct V_2 * F_25 ( const struct V_1 * V_65 ,
const T_2 V_72 ,
const char * V_63 ,
const T_2 V_73 )
{
struct V_2 * V_74 ;
V_74 = F_26 ( sizeof( * V_74 ) + V_73 + 1 , V_75 ) ;
if ( F_12 ( V_74 == NULL ) )
return NULL ;
F_27 ( & V_74 -> V_60 , 1 ) ;
V_74 -> V_51 = ( char * ) ( V_74 + 1 ) ;
memcpy ( F_1 ( V_74 ) , V_65 , V_72 ) ;
V_74 -> V_76 = V_72 ;
F_21 ( V_74 ) ;
if ( F_28 ( F_1 ( V_74 ) , V_74 -> V_54 ,
sizeof( V_74 -> V_54 ) ) == 0 )
( void ) snprintf ( V_74 -> V_54 , sizeof( V_74 -> V_54 ) ,
L_10 ) ;
memcpy ( V_74 -> V_51 , V_63 , V_73 ) ;
V_74 -> V_51 [ V_73 ] = '\0' ;
return V_74 ;
}
struct V_2 * F_29 ( const struct V_1 * V_65 ,
const T_2 V_72 , const char * V_63 ,
const T_2 V_73 )
{
struct V_2 * V_77 , * V_74 = NULL ;
if ( V_63 && memchr ( V_63 , '/' , V_73 ) != NULL ) {
if ( F_30 () ) {
F_13 ( V_78 L_11
L_12 ,
( int ) V_73 , V_63 ) ;
}
return NULL ;
}
V_79:
F_31 ( & V_80 ) ;
if ( V_53 && V_63 != NULL )
V_77 = F_16 ( V_63 , V_73 ) ;
else
V_77 = F_18 ( V_65 ) ;
if ( V_77 != NULL ) {
F_32 ( & V_77 -> V_60 ) ;
F_33 ( & V_80 ) ;
F_34 ( V_74 ) ;
F_8 ( L_13
L_14 , V_77 -> V_51 ,
V_77 -> V_54 ,
F_15 ( & V_77 -> V_60 ) ) ;
return V_77 ;
}
if ( V_74 != NULL ) {
F_35 ( & V_74 -> V_81 , & V_82 ) ;
F_33 ( & V_80 ) ;
F_8 ( L_15 ,
V_74 -> V_51 , V_74 -> V_54 ) ;
return V_74 ;
}
F_33 ( & V_80 ) ;
V_74 = F_25 ( V_65 , V_72 , V_63 , V_73 ) ;
if ( F_12 ( V_74 == NULL ) )
return NULL ;
goto V_79;
}
struct V_2 * F_36 ( const struct V_83 * V_84 )
{
struct V_2 * V_77 ;
F_31 ( & V_80 ) ;
V_77 = F_20 ( & V_84 -> V_33 ) ;
if ( F_12 ( V_77 == NULL ) ) {
F_33 ( & V_80 ) ;
F_8 ( L_16 ,
V_84 -> V_64 , V_84 -> V_85 ) ;
return V_77 ;
}
F_32 ( & V_77 -> V_60 ) ;
F_33 ( & V_80 ) ;
F_8 ( L_17 ,
V_77 -> V_51 , V_77 -> V_54 ,
F_15 ( & V_77 -> V_60 ) ) ;
return V_77 ;
}
void F_37 ( struct V_2 * V_3 )
{
if ( F_38 ( & V_3 -> V_60 , & V_80 ) ) {
F_39 ( & V_3 -> V_81 ) ;
F_33 ( & V_80 ) ;
F_8 ( L_18 ,
V_3 -> V_51 , V_3 -> V_54 ) ;
F_34 ( V_3 ) ;
}
}
static void F_40 ( struct V_86 * V_87 , const char * string )
{
const T_1 V_64 = strlen ( string ) ;
T_5 * V_68 ;
F_41 ( V_64 > V_88 ) ;
V_68 = F_42 ( V_87 , 4 + V_64 ) ;
F_43 ( V_68 , string , V_64 ) ;
}
static void F_44 ( struct V_86 * V_87 , const struct V_32 * V_89 )
{
F_40 ( V_87 , V_89 -> V_39 ) ;
}
static void F_45 ( struct V_86 * V_87 , const struct V_32 * V_89 )
{
T_5 * V_68 ;
F_40 ( V_87 , F_46 () -> V_90 ) ;
V_68 = F_42 ( V_87 , 4 + 4 + 4 ) ;
* V_68 ++ = F_47 ( V_89 -> V_35 ) ;
* V_68 ++ = F_47 ( V_89 -> V_37 ) ;
* V_68 = F_47 ( V_89 -> V_27 ) ;
}
static void F_48 ( struct V_86 * V_87 , const struct V_32 * V_89 )
{
F_44 ( V_87 , V_89 ) ;
F_45 ( V_87 , V_89 ) ;
}
static void F_49 ( struct V_86 * V_87 , const struct V_32 * V_89 )
{
T_5 * V_68 ;
V_68 = F_42 ( V_87 , V_91 ) ;
F_50 ( V_68 , V_89 -> V_33 -> V_67 , V_91 ) ;
}
static void F_51 ( struct V_92 * V_93 , struct V_86 * V_87 ,
const struct V_32 * V_89 )
{
F_48 ( V_87 , V_89 ) ;
F_49 ( V_87 , V_89 ) ;
}
static void F_52 ( struct V_92 * V_93 , struct V_86 * V_87 ,
const struct V_32 * V_89 )
{
F_48 ( V_87 , V_89 ) ;
}
static int F_53 ( struct V_92 * V_94 ,
struct V_86 * V_87 ,
struct V_28 * V_95 )
{
T_5 * V_68 ;
V_68 = F_54 ( V_87 , 4 + 4 ) ;
if ( F_12 ( V_68 == NULL ) )
return - V_56 ;
V_95 -> V_31 = F_55 ( V_68 ++ ) ;
V_95 -> V_59 = F_55 ( V_68 ) ;
F_8 ( L_19 ,
V_96 , V_95 -> V_31 , V_95 -> V_59 ) ;
return 0 ;
}
static int F_56 ( struct V_92 * V_94 ,
struct V_86 * V_87 ,
struct V_28 * V_95 )
{
T_5 * V_68 ;
V_68 = F_54 ( V_87 , 4 ) ;
if ( F_12 ( V_68 == NULL ) )
return - V_56 ;
V_95 -> V_59 = F_55 ( V_68 ) ;
F_8 ( L_20 , V_96 , V_95 -> V_59 ) ;
return 0 ;
}
