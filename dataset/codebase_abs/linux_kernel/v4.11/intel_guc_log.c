static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [] = {
V_4
} ;
return F_2 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 [] = {
V_5 ,
0
} ;
return F_2 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_3 [] = {
V_7 ,
V_6
} ;
return F_2 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
static int F_6 ( struct V_8 * V_9 ,
void * V_10 ,
void * V_11 ,
T_2 V_12 )
{
if ( F_7 ( V_9 ) )
return 0 ;
return 1 ;
}
static struct V_13 * F_8 ( const char * V_14 ,
struct V_13 * V_15 ,
T_3 V_16 ,
struct V_8 * V_9 ,
int * V_17 )
{
struct V_13 * V_18 ;
* V_17 = 1 ;
if ( ! V_15 )
return NULL ;
V_18 = F_9 ( L_1 , V_16 ,
V_15 , V_9 , & V_19 ) ;
return V_18 ;
}
static int F_10 ( struct V_13 * V_13 )
{
F_11 ( V_13 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> log . V_20 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
struct V_23 * V_24 ;
T_2 V_25 , V_26 ;
V_26 = V_2 -> log . V_27 -> V_28 -> V_29 . V_30 ;
V_25 = 8 ;
V_24 = F_16 ( NULL , NULL , V_26 ,
V_25 , & V_31 , V_22 ) ;
if ( ! V_24 ) {
F_17 ( L_2 ) ;
return - V_32 ;
}
F_18 ( V_24 -> V_26 < V_26 ) ;
V_2 -> log . V_20 = V_24 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
struct V_13 * V_33 ;
int V_34 ;
V_33 = V_22 -> V_35 . V_36 -> V_37 ;
if ( ! V_33 ) {
F_17 ( L_3 ) ;
return - V_38 ;
}
V_34 = F_20 ( V_2 -> log . V_20 , L_1 , V_33 ) ;
if ( V_34 ) {
F_17 ( L_4 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 () ;
F_23 ( V_2 -> log . V_20 , V_2 -> log . V_27 -> V_28 -> V_29 . V_30 ) ;
F_24 ( V_2 -> log . V_20 ) ;
}
static void * F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> log . V_20 )
return NULL ;
return F_23 ( V_2 -> log . V_20 , 0 ) ;
}
static bool F_26 ( struct V_1 * V_2 ,
enum V_39 type ,
unsigned int V_40 )
{
unsigned int V_41 = V_2 -> log . V_42 [ type ] ;
bool V_43 = false ;
if ( V_40 != V_41 ) {
V_43 = true ;
V_2 -> log . V_42 [ type ] = V_40 ;
V_2 -> log . V_44 [ type ] += V_40 - V_41 ;
if ( V_40 < V_41 ) {
V_2 -> log . V_44 [ type ] += 16 ;
}
F_27 ( L_5 ) ;
}
return V_43 ;
}
static unsigned int F_28 ( enum V_39 type )
{
switch ( type ) {
case V_45 :
return ( V_46 + 1 ) * V_47 ;
case V_48 :
return ( V_49 + 1 ) * V_47 ;
case V_50 :
return ( V_51 + 1 ) * V_47 ;
default:
F_29 ( type ) ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_52 , V_53 , V_54 , V_55 , V_40 ;
struct V_56 * V_57 , * V_58 ;
struct V_56 V_59 ;
enum V_39 type ;
void * V_60 , * V_61 ;
bool V_62 ;
if ( F_31 ( ! V_2 -> log . V_63 ) )
return;
V_57 = V_60 = V_2 -> log . V_63 ;
V_58 = V_61 = F_25 ( V_2 ) ;
V_60 += V_47 ;
V_61 += V_47 ;
for ( type = V_45 ; type < V_64 ; type ++ ) {
memcpy ( & V_59 , V_57 ,
sizeof( struct V_56 ) ) ;
V_52 = F_28 ( type ) ;
V_53 = V_59 . V_65 ;
V_54 = V_59 . V_66 ;
V_40 = V_59 . V_67 ;
V_2 -> log . V_68 [ type ] += V_59 . V_69 ;
V_62 = F_26 ( V_2 , type , V_40 ) ;
V_57 -> V_65 = V_54 ;
V_57 -> V_69 = 0 ;
V_57 ++ ;
if ( F_32 ( ! V_58 ) )
continue;
memcpy ( V_58 , & V_59 ,
sizeof( struct V_56 ) ) ;
V_58 -> V_70 = V_54 ;
V_58 ++ ;
if ( F_32 ( V_62 ) ) {
V_53 = 0 ;
V_54 = V_52 ;
} else if ( F_32 ( ( V_53 > V_52 ) ||
( V_54 > V_52 ) ) ) {
F_17 ( L_6 ) ;
V_53 = 0 ;
V_54 = V_52 ;
}
if ( V_53 > V_54 ) {
F_33 ( V_61 , V_60 , V_54 ) ;
V_55 = V_52 - V_53 ;
} else {
V_55 = V_54 - V_53 ;
}
F_33 ( V_61 + V_53 ,
V_60 + V_53 , V_55 ) ;
V_60 += V_52 ;
V_61 += V_52 ;
}
if ( V_58 )
F_21 ( V_2 ) ;
else {
F_27 ( L_7 ) ;
V_2 -> log . V_71 ++ ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
F_35 ( & V_22 -> V_35 . V_72 ) ;
F_36 ( V_22 ) ;
if ( V_2 -> log . V_73 )
F_37 ( V_2 -> log . V_73 ) ;
V_2 -> log . V_73 = NULL ;
if ( V_2 -> log . V_20 )
F_12 ( V_2 ) ;
V_2 -> log . V_20 = NULL ;
if ( V_2 -> log . V_63 )
F_38 ( V_2 -> log . V_27 -> V_28 ) ;
V_2 -> log . V_63 = NULL ;
}
static void F_39 ( struct V_74 * V_75 )
{
struct V_1 * V_2 =
F_40 ( V_75 , struct V_1 , log . V_76 ) ;
F_41 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
void * V_77 ;
int V_34 ;
F_35 ( & V_22 -> V_35 . V_72 ) ;
if ( V_78 . V_79 < 0 )
return 0 ;
if ( ! V_2 -> log . V_63 ) {
V_77 = F_43 ( V_2 -> log . V_27 -> V_28 , V_80 ) ;
if ( F_44 ( V_77 ) ) {
V_34 = F_45 ( V_77 ) ;
F_17 ( L_8 , V_34 ) ;
return V_34 ;
}
V_2 -> log . V_63 = V_77 ;
}
if ( ! V_2 -> log . V_20 ) {
V_34 = F_14 ( V_2 ) ;
if ( V_34 )
return V_34 ;
}
if ( ! V_2 -> log . V_73 ) {
F_46 ( & V_2 -> log . V_76 , F_39 ) ;
V_2 -> log . V_73 = F_47 ( L_9 ,
V_81 | V_82 ) ;
if ( V_2 -> log . V_73 == NULL ) {
F_17 ( L_10 ) ;
return - V_32 ;
}
}
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_83 * V_27 ;
unsigned long V_84 ;
T_4 V_30 , V_85 ;
if ( V_78 . V_79 > V_86 )
V_78 . V_79 = V_86 ;
V_30 = ( 1 + V_49 + 1 +
V_46 + 1 +
V_51 + 1 ) << V_87 ;
V_27 = V_2 -> log . V_27 ;
if ( ! V_27 ) {
if ( F_31 ( ! F_49 () ) ) {
V_78 . V_79 = - 1 ;
return;
}
V_27 = F_50 ( V_2 , V_30 ) ;
if ( F_44 ( V_27 ) ) {
V_78 . V_79 = - 1 ;
return;
}
V_2 -> log . V_27 = V_27 ;
if ( F_42 ( V_2 ) ) {
F_34 ( V_2 ) ;
F_51 ( & V_2 -> log . V_27 ) ;
V_78 . V_79 = - 1 ;
return;
}
}
V_85 = V_88 | V_89 |
( V_49 << V_90 ) |
( V_46 << V_91 ) |
( V_51 << V_92 ) ;
V_84 = F_52 ( V_27 ) >> V_87 ;
V_2 -> log . V_85 = ( V_84 << V_93 ) | V_85 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
int V_34 ;
F_35 ( & V_22 -> V_35 . V_72 ) ;
if ( V_78 . V_79 < 0 )
return - V_94 ;
V_34 = F_42 ( V_2 ) ;
if ( V_34 )
goto V_95;
V_34 = F_19 ( V_2 ) ;
if ( V_34 )
goto V_95;
return 0 ;
V_95:
F_34 ( V_2 ) ;
V_78 . V_79 = - 1 ;
return V_34 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
F_30 ( V_2 ) ;
F_54 ( V_22 ) ;
F_1 ( V_2 ) ;
F_55 ( V_22 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
if ( ! V_78 . V_96 || ( V_78 . V_79 < 0 ) )
return;
F_36 ( V_22 ) ;
V_76 ( & V_2 -> log . V_76 ) ;
F_4 ( V_2 ) ;
F_41 ( V_2 ) ;
}
int F_57 ( struct V_21 * V_22 , T_5 V_6 )
{
struct V_1 * V_2 = & V_22 -> V_2 ;
union F_5 V_97 ;
int V_34 ;
V_97 . V_98 = V_6 ;
if ( V_97 . V_99 < V_100 ||
V_97 . V_99 > V_86 )
return - V_94 ;
if ( ! V_97 . V_101 && ( V_78 . V_79 < 0 ) )
return 0 ;
V_34 = F_5 ( V_2 , V_97 . V_98 ) ;
if ( V_34 < 0 ) {
F_58 ( L_11 , V_34 ) ;
return V_34 ;
}
V_78 . V_79 = V_97 . V_99 ;
if ( ! V_22 -> V_2 . log . V_20 ) {
V_34 = F_53 ( V_2 ) ;
if ( ! V_34 )
F_59 ( V_22 ) ;
} else if ( ! V_97 . V_101 ) {
F_56 ( V_2 ) ;
V_78 . V_79 = - 1 ;
} else {
F_59 ( V_22 ) ;
}
return V_34 ;
}
void F_60 ( struct V_21 * V_22 )
{
if ( ! V_78 . V_96 )
return;
F_61 ( & V_22 -> V_35 . V_72 ) ;
F_53 ( & V_22 -> V_2 ) ;
F_62 ( & V_22 -> V_35 . V_72 ) ;
}
void F_63 ( struct V_21 * V_22 )
{
if ( ! V_78 . V_96 )
return;
F_61 ( & V_22 -> V_35 . V_72 ) ;
F_34 ( & V_22 -> V_2 ) ;
F_62 ( & V_22 -> V_35 . V_72 ) ;
}
