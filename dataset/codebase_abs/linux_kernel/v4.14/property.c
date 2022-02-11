static inline bool F_1 ( const struct V_1 * V_2 )
{
return ! F_2 ( V_2 ) && V_2 -> V_3 == & V_4 ;
}
static const struct V_5 *
F_3 ( const struct V_6 * V_7 , const char * V_8 )
{
const struct V_5 * V_9 ;
if ( ! V_7 || ! V_7 -> V_10 )
return NULL ;
for ( V_9 = V_7 -> V_10 ; V_9 -> V_8 ; V_9 ++ )
if ( ! strcmp ( V_8 , V_9 -> V_8 ) )
return V_9 ;
return NULL ;
}
static const void * F_4 ( const struct V_6 * V_7 ,
const char * V_11 , T_1 V_12 )
{
const struct V_5 * V_9 ;
const void * V_13 ;
V_9 = F_3 ( V_7 , V_11 ) ;
if ( ! V_9 )
return F_5 ( - V_14 ) ;
if ( V_9 -> V_15 )
V_13 = V_9 -> V_13 . V_16 ;
else
V_13 = & V_9 -> V_17 . V_16 ;
if ( ! V_13 )
return F_5 ( - V_18 ) ;
if ( V_12 > V_9 -> V_12 )
return F_5 ( - V_19 ) ;
return V_13 ;
}
static int F_6 ( const struct V_6 * V_7 ,
const char * V_11 ,
T_2 * V_20 , T_1 V_21 )
{
const void * V_13 ;
T_1 V_12 = V_21 * sizeof( * V_20 ) ;
V_13 = F_4 ( V_7 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
memcpy ( V_20 , V_13 , V_12 ) ;
return 0 ;
}
static int F_9 ( const struct V_6 * V_7 ,
const char * V_11 ,
T_3 * V_20 , T_1 V_21 )
{
const void * V_13 ;
T_1 V_12 = V_21 * sizeof( * V_20 ) ;
V_13 = F_4 ( V_7 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
memcpy ( V_20 , V_13 , V_12 ) ;
return 0 ;
}
static int F_10 ( const struct V_6 * V_7 ,
const char * V_11 ,
T_4 * V_20 , T_1 V_21 )
{
const void * V_13 ;
T_1 V_12 = V_21 * sizeof( * V_20 ) ;
V_13 = F_4 ( V_7 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
memcpy ( V_20 , V_13 , V_12 ) ;
return 0 ;
}
static int F_11 ( const struct V_6 * V_7 ,
const char * V_11 ,
T_5 * V_20 , T_1 V_21 )
{
const void * V_13 ;
T_1 V_12 = V_21 * sizeof( * V_20 ) ;
V_13 = F_4 ( V_7 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
memcpy ( V_20 , V_13 , V_12 ) ;
return 0 ;
}
static int F_12 ( const struct V_6 * V_7 ,
const char * V_11 , T_1 V_12 )
{
const struct V_5 * V_9 ;
V_9 = F_3 ( V_7 , V_11 ) ;
if ( ! V_9 )
return - V_14 ;
return V_9 -> V_12 / V_12 ;
}
static int F_13 ( const struct V_6 * V_7 ,
const char * V_11 ,
const char * * V_22 , T_1 V_21 )
{
const struct V_5 * V_9 ;
const void * V_13 ;
T_1 V_23 , V_12 ;
V_9 = F_3 ( V_7 , V_11 ) ;
if ( ! V_9 )
return - V_14 ;
if ( ! V_9 -> V_15 )
V_23 = 1 ;
else
V_23 = F_12 ( V_7 , V_11 ,
sizeof( const char * ) ) ;
if ( ! V_22 )
return V_23 ;
V_23 = F_14 ( V_21 , V_23 ) ;
V_12 = V_23 * sizeof( * V_22 ) ;
V_13 = F_4 ( V_7 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
memcpy ( V_22 , V_13 , V_12 ) ;
return V_23 ;
}
struct V_1 * F_15 ( struct V_24 * V_25 )
{
return F_16 ( V_26 ) && V_25 -> V_27 ?
& V_25 -> V_27 -> V_2 : V_25 -> V_2 ;
}
static bool F_17 ( const struct V_1 * V_2 ,
const char * V_11 )
{
return ! ! F_3 ( F_18 ( V_2 ) , V_11 ) ;
}
static int F_19 ( const struct V_1 * V_2 ,
const char * V_11 ,
unsigned int V_28 , void * V_29 ,
T_1 V_21 )
{
const struct V_6 * V_30 = F_18 ( V_2 ) ;
if ( ! V_29 )
return F_12 ( V_30 , V_11 , V_28 ) ;
switch ( V_28 ) {
case sizeof( T_2 ) :
return F_6 ( V_30 , V_11 , V_29 , V_21 ) ;
case sizeof( T_3 ) :
return F_9 ( V_30 , V_11 , V_29 , V_21 ) ;
case sizeof( T_4 ) :
return F_10 ( V_30 , V_11 , V_29 , V_21 ) ;
case sizeof( T_5 ) :
return F_11 ( V_30 , V_11 , V_29 , V_21 ) ;
}
return - V_31 ;
}
static int
F_20 ( const struct V_1 * V_2 ,
const char * V_11 ,
const char * * V_29 , T_1 V_21 )
{
return F_13 ( F_18 ( V_2 ) , V_11 ,
V_29 , V_21 ) ;
}
bool F_21 ( struct V_24 * V_25 , const char * V_11 )
{
return F_22 ( F_15 ( V_25 ) , V_11 ) ;
}
bool F_22 ( const struct V_1 * V_2 ,
const char * V_11 )
{
bool V_32 ;
V_32 = F_23 ( V_2 , V_33 , V_11 ) ;
if ( V_32 == false && ! F_2 ( V_2 ) &&
! F_2 ( V_2 -> V_34 ) )
V_32 = F_23 ( V_2 -> V_34 , V_33 ,
V_11 ) ;
return V_32 ;
}
int F_24 ( struct V_24 * V_25 , const char * V_11 ,
T_2 * V_29 , T_1 V_21 )
{
return F_25 ( F_15 ( V_25 ) , V_11 , V_29 , V_21 ) ;
}
int F_26 ( struct V_24 * V_25 , const char * V_11 ,
T_3 * V_29 , T_1 V_21 )
{
return F_27 ( F_15 ( V_25 ) , V_11 , V_29 , V_21 ) ;
}
int F_28 ( struct V_24 * V_25 , const char * V_11 ,
T_4 * V_29 , T_1 V_21 )
{
return F_29 ( F_15 ( V_25 ) , V_11 , V_29 , V_21 ) ;
}
int F_30 ( struct V_24 * V_25 , const char * V_11 ,
T_5 * V_29 , T_1 V_21 )
{
return F_31 ( F_15 ( V_25 ) , V_11 , V_29 , V_21 ) ;
}
int F_32 ( struct V_24 * V_25 , const char * V_11 ,
const char * * V_29 , T_1 V_21 )
{
return F_33 ( F_15 ( V_25 ) , V_11 , V_29 , V_21 ) ;
}
int F_34 ( struct V_24 * V_25 , const char * V_11 ,
const char * * V_29 )
{
return F_35 ( F_15 ( V_25 ) , V_11 , V_29 ) ;
}
int F_36 ( struct V_24 * V_25 , const char * V_11 ,
const char * string )
{
return F_37 ( F_15 ( V_25 ) , V_11 , string ) ;
}
static int F_38 ( const struct V_1 * V_2 ,
const char * V_11 ,
unsigned int V_28 , void * V_29 ,
T_1 V_21 )
{
int V_32 ;
V_32 = F_39 ( V_2 , V_35 , V_11 ,
V_28 , V_29 , V_21 ) ;
if ( V_32 == - V_14 && ! F_2 ( V_2 ) &&
! F_2 ( V_2 -> V_34 ) )
V_32 = F_39 (
V_2 -> V_34 , V_35 , V_11 ,
V_28 , V_29 , V_21 ) ;
return V_32 ;
}
int F_25 ( const struct V_1 * V_2 ,
const char * V_11 , T_2 * V_29 , T_1 V_21 )
{
return F_38 ( V_2 , V_11 , sizeof( T_2 ) ,
V_29 , V_21 ) ;
}
int F_27 ( const struct V_1 * V_2 ,
const char * V_11 , T_3 * V_29 , T_1 V_21 )
{
return F_38 ( V_2 , V_11 , sizeof( T_3 ) ,
V_29 , V_21 ) ;
}
int F_29 ( const struct V_1 * V_2 ,
const char * V_11 , T_4 * V_29 , T_1 V_21 )
{
return F_38 ( V_2 , V_11 , sizeof( T_4 ) ,
V_29 , V_21 ) ;
}
int F_31 ( const struct V_1 * V_2 ,
const char * V_11 , T_5 * V_29 , T_1 V_21 )
{
return F_38 ( V_2 , V_11 , sizeof( T_5 ) ,
V_29 , V_21 ) ;
}
int F_33 ( const struct V_1 * V_2 ,
const char * V_11 , const char * * V_29 ,
T_1 V_21 )
{
int V_32 ;
V_32 = F_39 ( V_2 , V_36 , V_11 ,
V_29 , V_21 ) ;
if ( V_32 == - V_14 && ! F_2 ( V_2 ) &&
! F_2 ( V_2 -> V_34 ) )
V_32 = F_39 ( V_2 -> V_34 ,
V_36 , V_11 ,
V_29 , V_21 ) ;
return V_32 ;
}
int F_35 ( const struct V_1 * V_2 ,
const char * V_11 , const char * * V_29 )
{
int V_32 = F_33 ( V_2 , V_11 , V_29 , 1 ) ;
return V_32 < 0 ? V_32 : 0 ;
}
int F_37 ( const struct V_1 * V_2 ,
const char * V_11 , const char * string )
{
const char * * V_20 ;
int V_21 , V_32 ;
V_21 = F_33 ( V_2 , V_11 , NULL , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 == 0 )
return - V_18 ;
V_20 = F_40 ( V_21 , sizeof( * V_20 ) , V_37 ) ;
if ( ! V_20 )
return - V_38 ;
V_32 = F_33 ( V_2 , V_11 , V_20 , V_21 ) ;
if ( V_32 < 0 )
goto V_39;
V_32 = F_41 ( V_20 , V_21 , string ) ;
if ( V_32 < 0 )
V_32 = - V_18 ;
V_39:
F_42 ( V_20 ) ;
return V_32 ;
}
int F_43 ( const struct V_1 * V_2 ,
const char * V_9 , const char * V_40 ,
unsigned int V_41 , unsigned int V_42 ,
struct V_43 * args )
{
return F_39 ( V_2 , V_44 , V_9 , V_40 ,
V_41 , V_42 , args ) ;
}
static int F_44 ( struct V_5 * V_45 ,
const struct V_5 * V_46 )
{
char * * V_47 ;
T_1 V_21 = V_46 -> V_12 / sizeof( * V_47 ) ;
int V_48 ;
V_47 = F_40 ( V_21 , sizeof( * V_47 ) , V_37 ) ;
if ( ! V_47 )
return - V_38 ;
for ( V_48 = 0 ; V_48 < V_21 ; V_48 ++ ) {
V_47 [ V_48 ] = F_45 ( V_46 -> V_13 . V_49 [ V_48 ] , V_37 ) ;
if ( ! V_47 [ V_48 ] && V_46 -> V_13 . V_49 [ V_48 ] ) {
while ( -- V_48 >= 0 )
F_42 ( V_47 [ V_48 ] ) ;
F_42 ( V_47 ) ;
return - V_38 ;
}
}
V_45 -> V_13 . V_16 = V_47 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_45 ,
const struct V_5 * V_46 )
{
int error ;
V_45 -> V_8 = F_45 ( V_46 -> V_8 , V_37 ) ;
if ( ! V_45 -> V_8 )
return - V_38 ;
if ( V_46 -> V_15 ) {
if ( ! V_46 -> V_12 ) {
error = - V_18 ;
goto V_50;
}
if ( V_46 -> V_51 ) {
error = F_44 ( V_45 , V_46 ) ;
if ( error )
goto V_50;
} else {
V_45 -> V_13 . V_16 = F_47 ( V_46 -> V_13 . V_16 ,
V_46 -> V_12 , V_37 ) ;
if ( ! V_45 -> V_13 . V_16 ) {
error = - V_38 ;
goto V_50;
}
}
} else if ( V_46 -> V_51 ) {
V_45 -> V_17 . V_49 = F_45 ( V_46 -> V_17 . V_49 , V_37 ) ;
if ( ! V_45 -> V_17 . V_49 && V_46 -> V_17 . V_49 ) {
error = - V_38 ;
goto V_50;
}
} else {
V_45 -> V_17 . V_16 = V_46 -> V_17 . V_16 ;
}
V_45 -> V_12 = V_46 -> V_12 ;
V_45 -> V_15 = V_46 -> V_15 ;
V_45 -> V_51 = V_46 -> V_51 ;
return 0 ;
V_50:
F_42 ( V_45 -> V_8 ) ;
return error ;
}
static void F_48 ( const struct V_5 * V_52 )
{
T_1 V_48 , V_21 ;
if ( V_52 -> V_15 ) {
if ( V_52 -> V_51 && V_52 -> V_13 . V_49 ) {
V_21 = V_52 -> V_12 / sizeof( const char * ) ;
for ( V_48 = 0 ; V_48 < V_21 ; V_48 ++ )
F_42 ( V_52 -> V_13 . V_49 [ V_48 ] ) ;
}
F_42 ( V_52 -> V_13 . V_16 ) ;
} else if ( V_52 -> V_51 ) {
F_42 ( V_52 -> V_17 . V_49 ) ;
}
F_42 ( V_52 -> V_8 ) ;
}
struct V_5 *
F_49 ( const struct V_5 * V_10 )
{
struct V_5 * V_52 ;
int V_48 , V_53 = 0 ;
while ( V_10 [ V_53 ] . V_8 )
V_53 ++ ;
V_52 = F_40 ( V_53 + 1 , sizeof( * V_52 ) , V_37 ) ;
if ( ! V_52 )
return F_5 ( - V_38 ) ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
int V_32 = F_46 ( & V_52 [ V_48 ] , & V_10 [ V_48 ] ) ;
if ( V_32 ) {
while ( -- V_48 >= 0 )
F_48 ( & V_52 [ V_48 ] ) ;
F_42 ( V_52 ) ;
return F_5 ( V_32 ) ;
}
}
return V_52 ;
}
void F_50 ( const struct V_5 * V_10 )
{
const struct V_5 * V_52 ;
for ( V_52 = V_10 ; V_52 -> V_8 ; V_52 ++ )
F_48 ( V_52 ) ;
F_42 ( V_10 ) ;
}
static void F_51 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_50 ( V_7 -> V_10 ) ;
F_42 ( V_7 ) ;
}
static struct V_6 * F_52 ( const struct V_6 * V_7 )
{
struct V_5 * V_10 ;
struct V_6 * V_52 ;
V_52 = F_53 ( sizeof( * V_52 ) , V_37 ) ;
if ( ! V_52 )
return F_5 ( - V_38 ) ;
V_10 = F_49 ( V_7 -> V_10 ) ;
if ( F_7 ( V_10 ) ) {
F_42 ( V_52 ) ;
return F_54 ( V_10 ) ;
}
V_52 -> V_10 = V_10 ;
return V_52 ;
}
void F_55 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_2 = F_15 ( V_25 ) ;
if ( ! V_2 )
return;
V_7 = F_18 ( V_2 ) ;
if ( V_7 ) {
F_56 ( V_25 , NULL ) ;
} else {
V_7 = F_18 ( V_2 -> V_34 ) ;
if ( V_7 && V_25 == V_7 -> V_25 )
F_57 ( V_25 , NULL ) ;
}
if ( V_7 && V_25 == V_7 -> V_25 )
F_51 ( V_7 ) ;
}
int F_58 ( struct V_24 * V_25 ,
const struct V_5 * V_10 )
{
struct V_6 * V_52 , V_7 ;
if ( ! V_10 )
return - V_14 ;
V_7 . V_10 = V_10 ;
V_52 = F_52 ( & V_7 ) ;
if ( F_7 ( V_52 ) )
return F_8 ( V_52 ) ;
V_52 -> V_2 . V_3 = & V_4 ;
F_57 ( V_25 , & V_52 -> V_2 ) ;
V_52 -> V_25 = V_25 ;
return 0 ;
}
struct V_1 * F_59 ( struct V_1 * V_2 )
{
struct V_1 * V_54 = F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
return V_54 ;
}
struct V_1 * F_60 ( const struct V_1 * V_2 )
{
return F_62 ( V_2 , V_55 ) ;
}
struct V_1 *
F_63 ( const struct V_1 * V_2 ,
struct V_1 * V_56 )
{
return F_62 ( V_2 , V_57 , V_56 ) ;
}
struct V_1 * F_64 ( struct V_24 * V_25 ,
struct V_1 * V_56 )
{
struct V_58 * V_59 = F_65 ( V_25 ) ;
struct V_1 * V_2 = NULL ;
if ( V_25 -> V_27 )
V_2 = & V_25 -> V_27 -> V_2 ;
else if ( V_59 )
V_2 = F_66 ( V_59 ) ;
return F_63 ( V_2 , V_56 ) ;
}
struct V_1 *
F_67 ( const struct V_1 * V_2 ,
const char * V_60 )
{
return F_62 ( V_2 , V_61 , V_60 ) ;
}
struct V_1 * F_68 ( struct V_24 * V_25 ,
const char * V_60 )
{
return F_67 ( F_15 ( V_25 ) , V_60 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_62 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_63 ) ;
}
bool F_71 ( const struct V_1 * V_2 )
{
return F_23 ( V_2 , V_64 ) ;
}
unsigned int F_72 ( struct V_24 * V_25 )
{
struct V_1 * V_56 ;
unsigned int V_65 = 0 ;
F_73 (dev, child)
V_65 ++ ;
return V_65 ;
}
bool F_74 ( struct V_24 * V_25 )
{
if ( F_16 ( V_26 ) && V_25 -> V_27 )
return true ;
return F_75 ( F_65 ( V_25 ) ) ;
}
enum V_66 F_76 ( struct V_24 * V_25 )
{
enum V_66 V_67 = V_68 ;
if ( F_16 ( V_26 ) && V_25 -> V_27 ) {
if ( F_77 ( V_25 -> V_27 ) )
V_67 = V_69 ;
else
V_67 = V_70 ;
} else
V_67 = F_78 ( F_65 ( V_25 ) ) ;
return V_67 ;
}
int F_79 ( struct V_24 * V_25 )
{
const char * V_71 ;
int V_72 , V_48 ;
V_72 = F_34 ( V_25 , L_1 , & V_71 ) ;
if ( V_72 < 0 )
V_72 = F_34 ( V_25 ,
L_2 , & V_71 ) ;
if ( V_72 < 0 )
return V_72 ;
for ( V_48 = 0 ; V_48 < V_73 ; V_48 ++ )
if ( ! strcasecmp ( V_71 , F_80 ( V_48 ) ) )
return V_48 ;
return - V_74 ;
}
static void * F_81 ( struct V_24 * V_25 ,
const char * V_8 , char * V_75 ,
int V_76 )
{
int V_32 = F_24 ( V_25 , V_8 , V_75 , V_76 ) ;
if ( V_32 == 0 && V_76 == V_77 && F_82 ( V_75 ) )
return V_75 ;
return NULL ;
}
void * F_83 ( struct V_24 * V_25 , char * V_75 , int V_76 )
{
char * V_78 ;
V_78 = F_81 ( V_25 , L_3 , V_75 , V_76 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_81 ( V_25 , L_4 , V_75 , V_76 ) ;
if ( V_78 )
return V_78 ;
return F_81 ( V_25 , L_5 , V_75 , V_76 ) ;
}
struct V_1 *
F_84 ( const struct V_1 * V_2 ,
struct V_1 * V_79 )
{
return F_62 ( V_2 , V_80 , V_79 ) ;
}
struct V_1 *
F_85 ( const struct V_1 * V_81 )
{
struct V_1 * V_82 , * V_54 ;
V_82 = F_60 ( V_81 ) ;
V_54 = F_62 ( V_82 , V_83 ) ;
F_61 ( V_82 ) ;
return V_54 ;
}
struct V_1 *
F_86 ( const struct V_1 * V_2 )
{
struct V_1 * V_81 , * V_54 ;
V_81 = F_87 ( V_2 ) ;
V_54 = F_85 ( V_81 ) ;
F_61 ( V_81 ) ;
return V_54 ;
}
struct V_1 *
F_88 ( const struct V_1 * V_2 )
{
return F_59 ( F_87 ( V_2 ) ) ;
}
struct V_1 *
F_87 ( const struct V_1 * V_2 )
{
return F_62 ( V_2 , V_84 ) ;
}
struct V_1 *
F_89 ( const struct V_1 * V_2 , T_4 V_85 ,
T_4 V_86 )
{
struct V_1 * V_81 = NULL ;
while ( ( V_81 = F_84 ( V_2 , V_81 ) ) ) {
struct V_87 V_88 ;
struct V_1 * V_89 ;
int V_32 ;
V_32 = F_90 ( V_81 , & V_88 ) ;
if ( V_32 < 0 )
continue;
if ( V_88 . V_82 != V_85 || V_88 . V_90 != V_86 )
continue;
V_89 = F_86 ( V_81 ) ;
if ( ! V_89 )
return NULL ;
return F_71 ( V_89 ) ? V_89 : NULL ;
}
return NULL ;
}
int F_90 ( const struct V_1 * V_2 ,
struct V_87 * V_81 )
{
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
return F_39 ( V_2 , V_91 , V_81 ) ;
}
