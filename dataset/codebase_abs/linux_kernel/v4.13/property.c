static inline bool F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_2 ) && V_2 -> type == V_3 ;
}
static inline struct V_4 * F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ?
F_4 ( V_2 , struct V_4 , V_2 ) : NULL ;
}
static const struct V_5 * F_5 ( struct V_4 * V_6 ,
const char * V_7 )
{
const struct V_5 * V_8 ;
if ( ! V_6 || ! V_6 -> V_9 )
return NULL ;
for ( V_8 = V_6 -> V_9 ; V_8 -> V_7 ; V_8 ++ )
if ( ! strcmp ( V_7 , V_8 -> V_7 ) )
return V_8 ;
return NULL ;
}
static const void * F_6 ( struct V_4 * V_6 ,
const char * V_10 , T_1 V_11 )
{
const struct V_5 * V_8 ;
const void * V_12 ;
V_8 = F_5 ( V_6 , V_10 ) ;
if ( ! V_8 )
return F_7 ( - V_13 ) ;
if ( V_8 -> V_14 )
V_12 = V_8 -> V_12 . V_15 ;
else
V_12 = & V_8 -> V_16 . V_15 ;
if ( ! V_12 )
return F_7 ( - V_17 ) ;
if ( V_11 > V_8 -> V_11 )
return F_7 ( - V_18 ) ;
return V_12 ;
}
static int F_8 ( struct V_4 * V_6 ,
const char * V_10 ,
T_2 * V_19 , T_1 V_20 )
{
const void * V_12 ;
T_1 V_11 = V_20 * sizeof( * V_19 ) ;
V_12 = F_6 ( V_6 , V_10 , V_11 ) ;
if ( F_9 ( V_12 ) )
return F_10 ( V_12 ) ;
memcpy ( V_19 , V_12 , V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_6 ,
const char * V_10 ,
T_3 * V_19 , T_1 V_20 )
{
const void * V_12 ;
T_1 V_11 = V_20 * sizeof( * V_19 ) ;
V_12 = F_6 ( V_6 , V_10 , V_11 ) ;
if ( F_9 ( V_12 ) )
return F_10 ( V_12 ) ;
memcpy ( V_19 , V_12 , V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_6 ,
const char * V_10 ,
T_4 * V_19 , T_1 V_20 )
{
const void * V_12 ;
T_1 V_11 = V_20 * sizeof( * V_19 ) ;
V_12 = F_6 ( V_6 , V_10 , V_11 ) ;
if ( F_9 ( V_12 ) )
return F_10 ( V_12 ) ;
memcpy ( V_19 , V_12 , V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_6 ,
const char * V_10 ,
T_5 * V_19 , T_1 V_20 )
{
const void * V_12 ;
T_1 V_11 = V_20 * sizeof( * V_19 ) ;
V_12 = F_6 ( V_6 , V_10 , V_11 ) ;
if ( F_9 ( V_12 ) )
return F_10 ( V_12 ) ;
memcpy ( V_19 , V_12 , V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_6 ,
const char * V_10 , T_1 V_11 )
{
const struct V_5 * V_8 ;
V_8 = F_5 ( V_6 , V_10 ) ;
if ( ! V_8 )
return - V_13 ;
return V_8 -> V_11 / V_11 ;
}
static int F_15 ( struct V_4 * V_6 ,
const char * V_10 ,
const char * * V_21 , T_1 V_20 )
{
const struct V_5 * V_8 ;
const void * V_12 ;
T_1 V_22 , V_11 ;
V_8 = F_5 ( V_6 , V_10 ) ;
if ( ! V_8 )
return - V_13 ;
if ( ! V_8 -> V_14 )
V_22 = 1 ;
else
V_22 = F_14 ( V_6 , V_10 ,
sizeof( const char * ) ) ;
if ( ! V_21 )
return V_22 ;
V_22 = F_16 ( V_20 , V_22 ) ;
V_11 = V_22 * sizeof( * V_21 ) ;
V_12 = F_6 ( V_6 , V_10 , V_11 ) ;
if ( F_9 ( V_12 ) )
return F_10 ( V_12 ) ;
memcpy ( V_21 , V_12 , V_11 ) ;
return V_22 ;
}
struct V_1 * F_17 ( struct V_23 * V_24 )
{
return F_18 ( V_25 ) && V_24 -> V_26 ?
& V_24 -> V_26 -> V_2 : V_24 -> V_2 ;
}
static bool F_19 ( struct V_1 * V_2 ,
const char * V_10 )
{
return ! ! F_5 ( F_3 ( V_2 ) , V_10 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
const char * V_10 ,
unsigned int V_27 , void * V_28 ,
T_1 V_20 )
{
struct V_4 * V_29 = F_3 ( V_2 ) ;
if ( ! V_28 )
return F_14 ( V_29 , V_10 , V_27 ) ;
switch ( V_27 ) {
case sizeof( T_2 ) :
return F_8 ( V_29 , V_10 , V_28 , V_20 ) ;
case sizeof( T_3 ) :
return F_11 ( V_29 , V_10 , V_28 , V_20 ) ;
case sizeof( T_4 ) :
return F_12 ( V_29 , V_10 , V_28 , V_20 ) ;
case sizeof( T_5 ) :
return F_13 ( V_29 , V_10 , V_28 , V_20 ) ;
}
return - V_30 ;
}
static int F_21 ( struct V_1 * V_2 ,
const char * V_10 ,
const char * * V_28 , T_1 V_20 )
{
return F_15 ( F_3 ( V_2 ) , V_10 ,
V_28 , V_20 ) ;
}
bool F_22 ( struct V_23 * V_24 , const char * V_10 )
{
return F_23 ( F_17 ( V_24 ) , V_10 ) ;
}
bool F_23 ( struct V_1 * V_2 , const char * V_10 )
{
bool V_31 ;
V_31 = F_24 ( V_2 , V_32 , V_10 ) ;
if ( V_31 == false && ! F_2 ( V_2 ) &&
! F_2 ( V_2 -> V_33 ) )
V_31 = F_24 ( V_2 -> V_33 , V_32 ,
V_10 ) ;
return V_31 ;
}
int F_25 ( struct V_23 * V_24 , const char * V_10 ,
T_2 * V_28 , T_1 V_20 )
{
return F_26 ( F_17 ( V_24 ) , V_10 , V_28 , V_20 ) ;
}
int F_27 ( struct V_23 * V_24 , const char * V_10 ,
T_3 * V_28 , T_1 V_20 )
{
return F_28 ( F_17 ( V_24 ) , V_10 , V_28 , V_20 ) ;
}
int F_29 ( struct V_23 * V_24 , const char * V_10 ,
T_4 * V_28 , T_1 V_20 )
{
return F_30 ( F_17 ( V_24 ) , V_10 , V_28 , V_20 ) ;
}
int F_31 ( struct V_23 * V_24 , const char * V_10 ,
T_5 * V_28 , T_1 V_20 )
{
return F_32 ( F_17 ( V_24 ) , V_10 , V_28 , V_20 ) ;
}
int F_33 ( struct V_23 * V_24 , const char * V_10 ,
const char * * V_28 , T_1 V_20 )
{
return F_34 ( F_17 ( V_24 ) , V_10 , V_28 , V_20 ) ;
}
int F_35 ( struct V_23 * V_24 , const char * V_10 ,
const char * * V_28 )
{
return F_36 ( F_17 ( V_24 ) , V_10 , V_28 ) ;
}
int F_37 ( struct V_23 * V_24 , const char * V_10 ,
const char * string )
{
return F_38 ( F_17 ( V_24 ) , V_10 , string ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const char * V_10 ,
unsigned int V_27 , void * V_28 ,
T_1 V_20 )
{
int V_31 ;
V_31 = F_40 ( V_2 , V_34 , V_10 ,
V_27 , V_28 , V_20 ) ;
if ( V_31 == - V_13 && ! F_2 ( V_2 ) &&
! F_2 ( V_2 -> V_33 ) )
V_31 = F_40 (
V_2 -> V_33 , V_34 , V_10 ,
V_27 , V_28 , V_20 ) ;
return V_31 ;
}
int F_26 ( struct V_1 * V_2 ,
const char * V_10 , T_2 * V_28 , T_1 V_20 )
{
return F_39 ( V_2 , V_10 , sizeof( T_2 ) ,
V_28 , V_20 ) ;
}
int F_28 ( struct V_1 * V_2 ,
const char * V_10 , T_3 * V_28 , T_1 V_20 )
{
return F_39 ( V_2 , V_10 , sizeof( T_3 ) ,
V_28 , V_20 ) ;
}
int F_30 ( struct V_1 * V_2 ,
const char * V_10 , T_4 * V_28 , T_1 V_20 )
{
return F_39 ( V_2 , V_10 , sizeof( T_4 ) ,
V_28 , V_20 ) ;
}
int F_32 ( struct V_1 * V_2 ,
const char * V_10 , T_5 * V_28 , T_1 V_20 )
{
return F_39 ( V_2 , V_10 , sizeof( T_5 ) ,
V_28 , V_20 ) ;
}
int F_34 ( struct V_1 * V_2 ,
const char * V_10 , const char * * V_28 ,
T_1 V_20 )
{
int V_31 ;
V_31 = F_40 ( V_2 , V_35 , V_10 ,
V_28 , V_20 ) ;
if ( V_31 == - V_13 && ! F_2 ( V_2 ) &&
! F_2 ( V_2 -> V_33 ) )
V_31 = F_40 ( V_2 -> V_33 ,
V_35 , V_10 ,
V_28 , V_20 ) ;
return V_31 ;
}
int F_36 ( struct V_1 * V_2 ,
const char * V_10 , const char * * V_28 )
{
int V_31 = F_34 ( V_2 , V_10 , V_28 , 1 ) ;
return V_31 < 0 ? V_31 : 0 ;
}
int F_38 ( struct V_1 * V_2 ,
const char * V_10 , const char * string )
{
const char * * V_19 ;
int V_20 , V_31 ;
V_20 = F_34 ( V_2 , V_10 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_20 == 0 )
return - V_17 ;
V_19 = F_41 ( V_20 , sizeof( * V_19 ) , V_36 ) ;
if ( ! V_19 )
return - V_37 ;
V_31 = F_34 ( V_2 , V_10 , V_19 , V_20 ) ;
if ( V_31 < 0 )
goto V_38;
V_31 = F_42 ( V_19 , V_20 , string ) ;
if ( V_31 < 0 )
V_31 = - V_17 ;
V_38:
F_43 ( V_19 ) ;
return V_31 ;
}
static int F_44 ( struct V_5 * V_39 ,
const struct V_5 * V_40 )
{
char * * V_41 ;
T_1 V_20 = V_40 -> V_11 / sizeof( * V_41 ) ;
int V_42 ;
V_41 = F_41 ( V_20 , sizeof( * V_41 ) , V_36 ) ;
if ( ! V_41 )
return - V_37 ;
for ( V_42 = 0 ; V_42 < V_20 ; V_42 ++ ) {
V_41 [ V_42 ] = F_45 ( V_40 -> V_12 . V_43 [ V_42 ] , V_36 ) ;
if ( ! V_41 [ V_42 ] && V_40 -> V_12 . V_43 [ V_42 ] ) {
while ( -- V_42 >= 0 )
F_43 ( V_41 [ V_42 ] ) ;
F_43 ( V_41 ) ;
return - V_37 ;
}
}
V_39 -> V_12 . V_15 = V_41 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_39 ,
const struct V_5 * V_40 )
{
int error ;
V_39 -> V_7 = F_45 ( V_40 -> V_7 , V_36 ) ;
if ( ! V_39 -> V_7 )
return - V_37 ;
if ( V_40 -> V_14 ) {
if ( ! V_40 -> V_11 ) {
error = - V_17 ;
goto V_44;
}
if ( V_40 -> V_45 ) {
error = F_44 ( V_39 , V_40 ) ;
if ( error )
goto V_44;
} else {
V_39 -> V_12 . V_15 = F_47 ( V_40 -> V_12 . V_15 ,
V_40 -> V_11 , V_36 ) ;
if ( ! V_39 -> V_12 . V_15 ) {
error = - V_37 ;
goto V_44;
}
}
} else if ( V_40 -> V_45 ) {
V_39 -> V_16 . V_43 = F_45 ( V_40 -> V_16 . V_43 , V_36 ) ;
if ( ! V_39 -> V_16 . V_43 && V_40 -> V_16 . V_43 ) {
error = - V_37 ;
goto V_44;
}
} else {
V_39 -> V_16 . V_15 = V_40 -> V_16 . V_15 ;
}
V_39 -> V_11 = V_40 -> V_11 ;
V_39 -> V_14 = V_40 -> V_14 ;
V_39 -> V_45 = V_40 -> V_45 ;
return 0 ;
V_44:
F_43 ( V_39 -> V_7 ) ;
return error ;
}
static void F_48 ( const struct V_5 * V_46 )
{
T_1 V_42 , V_20 ;
if ( V_46 -> V_14 ) {
if ( V_46 -> V_45 && V_46 -> V_12 . V_43 ) {
V_20 = V_46 -> V_11 / sizeof( const char * ) ;
for ( V_42 = 0 ; V_42 < V_20 ; V_42 ++ )
F_43 ( V_46 -> V_12 . V_43 [ V_42 ] ) ;
}
F_43 ( V_46 -> V_12 . V_15 ) ;
} else if ( V_46 -> V_45 ) {
F_43 ( V_46 -> V_16 . V_43 ) ;
}
F_43 ( V_46 -> V_7 ) ;
}
struct V_5 *
F_49 ( const struct V_5 * V_9 )
{
struct V_5 * V_46 ;
int V_42 , V_47 = 0 ;
while ( V_9 [ V_47 ] . V_7 )
V_47 ++ ;
V_46 = F_41 ( V_47 + 1 , sizeof( * V_46 ) , V_36 ) ;
if ( ! V_46 )
return F_7 ( - V_37 ) ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ ) {
int V_31 = F_46 ( & V_46 [ V_42 ] , & V_9 [ V_42 ] ) ;
if ( V_31 ) {
while ( -- V_42 >= 0 )
F_48 ( & V_46 [ V_42 ] ) ;
F_43 ( V_46 ) ;
return F_7 ( V_31 ) ;
}
}
return V_46 ;
}
void F_50 ( const struct V_5 * V_9 )
{
const struct V_5 * V_46 ;
for ( V_46 = V_9 ; V_46 -> V_7 ; V_46 ++ )
F_48 ( V_46 ) ;
F_43 ( V_9 ) ;
}
static void F_51 ( struct V_4 * V_6 )
{
if ( ! V_6 )
return;
F_50 ( V_6 -> V_9 ) ;
F_43 ( V_6 ) ;
}
static struct V_4 * F_52 ( const struct V_4 * V_6 )
{
struct V_5 * V_9 ;
struct V_4 * V_46 ;
V_46 = F_53 ( sizeof( * V_46 ) , V_36 ) ;
if ( ! V_46 )
return F_7 ( - V_37 ) ;
V_9 = F_49 ( V_6 -> V_9 ) ;
if ( F_9 ( V_9 ) ) {
F_43 ( V_46 ) ;
return F_54 ( V_9 ) ;
}
V_46 -> V_9 = V_9 ;
return V_46 ;
}
void F_55 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_24 ) ;
if ( ! V_2 )
return;
if ( F_1 ( V_2 ) ) {
F_56 ( V_24 , NULL ) ;
F_51 ( F_3 ( V_2 ) ) ;
} else {
V_2 = V_2 -> V_33 ;
if ( ! F_9 ( V_2 ) && F_1 ( V_2 ) ) {
F_57 ( V_24 , NULL ) ;
F_51 ( F_3 ( V_2 ) ) ;
}
}
}
int F_58 ( struct V_23 * V_24 ,
const struct V_5 * V_9 )
{
struct V_4 * V_46 , V_6 ;
if ( ! V_9 )
return - V_13 ;
V_6 . V_9 = V_9 ;
V_46 = F_52 ( & V_6 ) ;
if ( F_9 ( V_46 ) )
return F_10 ( V_46 ) ;
V_46 -> V_2 . type = V_3 ;
V_46 -> V_2 . V_48 = & V_49 ;
F_57 ( V_24 , & V_46 -> V_2 ) ;
return 0 ;
}
struct V_1 * F_59 ( struct V_1 * V_2 )
{
struct V_1 * V_50 = F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
return V_50 ;
}
struct V_1 * F_60 ( struct V_1 * V_2 )
{
return F_62 ( V_2 , V_51 ) ;
}
struct V_1 * F_63 ( struct V_1 * V_2 ,
struct V_1 * V_52 )
{
return F_62 ( V_2 , V_53 , V_52 ) ;
}
struct V_1 * F_64 ( struct V_23 * V_24 ,
struct V_1 * V_52 )
{
struct V_54 * V_55 = F_65 ( V_24 ) ;
struct V_1 * V_2 = NULL ;
if ( V_24 -> V_26 )
V_2 = & V_24 -> V_26 -> V_2 ;
else if ( V_55 )
V_2 = F_66 ( V_55 ) ;
return F_63 ( V_2 , V_52 ) ;
}
struct V_1 * F_67 ( struct V_1 * V_2 ,
const char * V_56 )
{
return F_62 ( V_2 , V_57 , V_56 ) ;
}
struct V_1 * F_68 ( struct V_23 * V_24 ,
const char * V_56 )
{
return F_67 ( F_17 ( V_24 ) , V_56 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_58 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_59 ) ;
}
bool F_71 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , V_60 ) ;
}
unsigned int F_72 ( struct V_23 * V_24 )
{
struct V_1 * V_52 ;
unsigned int V_61 = 0 ;
F_73 (dev, child)
V_61 ++ ;
return V_61 ;
}
bool F_74 ( struct V_23 * V_24 )
{
if ( F_18 ( V_25 ) && V_24 -> V_26 )
return true ;
return F_75 ( F_65 ( V_24 ) ) ;
}
enum V_62 F_76 ( struct V_23 * V_24 )
{
enum V_62 V_63 = V_64 ;
if ( F_18 ( V_25 ) && V_24 -> V_26 ) {
if ( F_77 ( V_24 -> V_26 ) )
V_63 = V_65 ;
else
V_63 = V_66 ;
} else
V_63 = F_78 ( F_65 ( V_24 ) ) ;
return V_63 ;
}
int F_79 ( struct V_23 * V_24 )
{
const char * V_67 ;
int V_68 , V_42 ;
V_68 = F_35 ( V_24 , L_1 , & V_67 ) ;
if ( V_68 < 0 )
V_68 = F_35 ( V_24 ,
L_2 , & V_67 ) ;
if ( V_68 < 0 )
return V_68 ;
for ( V_42 = 0 ; V_42 < V_69 ; V_42 ++ )
if ( ! strcasecmp ( V_67 , F_80 ( V_42 ) ) )
return V_42 ;
return - V_70 ;
}
static void * F_81 ( struct V_23 * V_24 ,
const char * V_7 , char * V_71 ,
int V_72 )
{
int V_31 = F_25 ( V_24 , V_7 , V_71 , V_72 ) ;
if ( V_31 == 0 && V_72 == V_73 && F_82 ( V_71 ) )
return V_71 ;
return NULL ;
}
void * F_83 ( struct V_23 * V_24 , char * V_71 , int V_72 )
{
char * V_74 ;
V_74 = F_81 ( V_24 , L_3 , V_71 , V_72 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_81 ( V_24 , L_4 , V_71 , V_72 ) ;
if ( V_74 )
return V_74 ;
return F_81 ( V_24 , L_5 , V_71 , V_72 ) ;
}
struct V_1 *
F_84 ( struct V_1 * V_2 ,
struct V_1 * V_75 )
{
return F_62 ( V_2 , V_76 , V_75 ) ;
}
struct V_1 *
F_85 ( struct V_1 * V_77 )
{
struct V_1 * V_78 , * V_50 ;
V_78 = F_60 ( V_77 ) ;
V_50 = F_62 ( V_78 , V_79 ) ;
F_61 ( V_78 ) ;
return V_50 ;
}
struct V_1 *
F_86 ( struct V_1 * V_2 )
{
struct V_1 * V_77 , * V_50 ;
V_77 = F_87 ( V_2 ) ;
V_50 = F_85 ( V_77 ) ;
F_61 ( V_77 ) ;
return V_50 ;
}
struct V_1 * F_88 ( struct V_1 * V_2 )
{
return F_59 ( F_87 ( V_2 ) ) ;
}
struct V_1 *
F_87 ( struct V_1 * V_2 )
{
return F_62 ( V_2 , V_80 ) ;
}
struct V_1 * F_89 ( struct V_1 * V_2 ,
T_4 V_81 , T_4 V_82 )
{
struct V_1 * V_77 = NULL ;
while ( ( V_77 = F_84 ( V_2 , V_77 ) ) ) {
struct V_83 V_84 ;
struct V_1 * V_85 ;
int V_31 ;
V_31 = F_90 ( V_77 , & V_84 ) ;
if ( V_31 < 0 )
continue;
if ( V_84 . V_78 != V_81 || V_84 . V_86 != V_82 )
continue;
V_85 = F_86 ( V_77 ) ;
if ( ! V_85 )
return NULL ;
return F_71 ( V_85 ) ? V_85 : NULL ;
}
return NULL ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_83 * V_77 )
{
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
return F_40 ( V_2 , V_87 , V_77 ) ;
}
