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
static int F_12 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
struct V_13 * V_22 ;
int V_23 ;
if ( V_24 . V_25 < 0 )
return 0 ;
V_22 = V_21 -> V_26 . V_27 -> V_28 ;
if ( ! V_22 ) {
F_14 ( L_2 ) ;
return - V_29 ;
}
V_23 = F_15 ( V_2 -> log . V_30 . V_31 , L_1 , V_22 ) ;
if ( V_23 < 0 && V_23 != - V_32 ) {
F_14 ( L_3 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 () ;
F_18 ( V_2 -> log . V_30 . V_31 , V_2 -> log . V_33 -> V_34 -> V_35 . V_36 ) ;
F_19 ( V_2 -> log . V_30 . V_31 ) ;
}
static void * F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> log . V_30 . V_31 )
return NULL ;
return F_18 ( V_2 -> log . V_30 . V_31 , 0 ) ;
}
static bool F_21 ( struct V_1 * V_2 ,
enum V_37 type ,
unsigned int V_38 )
{
unsigned int V_39 = V_2 -> log . V_40 [ type ] ;
bool V_41 = false ;
if ( V_38 != V_39 ) {
V_41 = true ;
V_2 -> log . V_40 [ type ] = V_38 ;
V_2 -> log . V_42 [ type ] += V_38 - V_39 ;
if ( V_38 < V_39 ) {
V_2 -> log . V_42 [ type ] += 16 ;
}
F_22 ( L_4 ) ;
}
return V_41 ;
}
static unsigned int F_23 ( enum V_37 type )
{
switch ( type ) {
case V_43 :
return ( V_44 + 1 ) * V_45 ;
case V_46 :
return ( V_47 + 1 ) * V_45 ;
case V_48 :
return ( V_49 + 1 ) * V_45 ;
default:
F_24 ( type ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_50 , V_51 , V_52 , V_53 , V_38 ;
struct V_54 * V_55 , * V_56 ;
struct V_54 V_57 ;
enum V_37 type ;
void * V_58 , * V_59 ;
bool V_60 ;
if ( F_26 ( ! V_2 -> log . V_30 . V_61 ) )
return;
V_55 = V_58 = V_2 -> log . V_30 . V_61 ;
V_56 = V_59 = F_20 ( V_2 ) ;
V_58 += V_45 ;
V_59 += V_45 ;
for ( type = V_43 ; type < V_62 ; type ++ ) {
memcpy ( & V_57 , V_55 ,
sizeof( struct V_54 ) ) ;
V_50 = F_23 ( type ) ;
V_51 = V_57 . V_63 ;
V_52 = V_57 . V_64 ;
V_38 = V_57 . V_65 ;
V_2 -> log . V_66 [ type ] += V_57 . V_67 ;
V_60 = F_21 ( V_2 , type , V_38 ) ;
V_55 -> V_63 = V_52 ;
V_55 -> V_67 = 0 ;
V_55 ++ ;
if ( F_27 ( ! V_56 ) )
continue;
memcpy ( V_56 , & V_57 ,
sizeof( struct V_54 ) ) ;
V_56 -> V_68 = V_52 ;
V_56 ++ ;
if ( F_27 ( V_60 ) ) {
V_51 = 0 ;
V_52 = V_50 ;
} else if ( F_27 ( ( V_51 > V_50 ) ||
( V_52 > V_50 ) ) ) {
F_14 ( L_5 ) ;
V_51 = 0 ;
V_52 = V_50 ;
}
if ( V_51 > V_52 ) {
F_28 ( V_59 , V_58 , V_52 ) ;
V_53 = V_50 - V_51 ;
} else {
V_53 = V_52 - V_51 ;
}
F_28 ( V_59 + V_51 ,
V_58 + V_51 , V_53 ) ;
V_58 += V_50 ;
V_59 += V_50 ;
}
if ( V_56 )
F_16 ( V_2 ) ;
else {
F_22 ( L_6 ) ;
V_2 -> log . V_69 ++ ;
}
}
static void F_29 ( struct V_70 * V_71 )
{
struct V_1 * V_2 =
F_30 ( V_71 , struct V_1 , log . V_30 . V_72 ) ;
F_31 ( V_2 ) ;
}
static bool F_32 ( struct V_1 * V_2 )
{
return V_2 -> log . V_30 . V_61 != NULL ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
void * V_73 ;
struct V_74 * V_75 ;
T_2 V_76 , V_77 ;
int V_23 = 0 ;
F_34 ( & V_21 -> V_26 . V_78 ) ;
F_35 ( F_32 ( V_2 ) ) ;
V_73 = F_36 ( V_2 -> log . V_33 -> V_34 , V_79 ) ;
if ( F_37 ( V_73 ) ) {
F_14 ( L_7 , V_23 ) ;
return F_38 ( V_73 ) ;
}
V_2 -> log . V_30 . V_61 = V_73 ;
V_77 = V_2 -> log . V_33 -> V_34 -> V_35 . V_36 ;
V_76 = 8 ;
V_75 = F_39 ( NULL , NULL , V_77 ,
V_76 , & V_80 , V_21 ) ;
if ( ! V_75 ) {
F_14 ( L_8 ) ;
V_23 = - V_81 ;
goto V_82;
}
F_35 ( V_75 -> V_77 < V_77 ) ;
V_2 -> log . V_30 . V_31 = V_75 ;
F_40 ( & V_2 -> log . V_30 . V_72 , F_29 ) ;
V_2 -> log . V_30 . V_83 = F_41 ( L_9 ,
V_84 | V_85 ) ;
if ( ! V_2 -> log . V_30 . V_83 ) {
F_14 ( L_10 ) ;
V_23 = - V_81 ;
goto V_86;
}
return 0 ;
V_86:
F_42 ( V_2 -> log . V_30 . V_31 ) ;
V_82:
F_43 ( V_2 -> log . V_33 -> V_34 ) ;
V_2 -> log . V_30 . V_61 = NULL ;
return V_23 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! F_32 ( V_2 ) )
return;
F_45 ( V_2 -> log . V_30 . V_83 ) ;
F_42 ( V_2 -> log . V_30 . V_31 ) ;
F_43 ( V_2 -> log . V_33 -> V_34 ) ;
V_2 -> log . V_30 . V_61 = NULL ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
int V_23 ;
F_34 ( & V_21 -> V_26 . V_78 ) ;
if ( ! F_32 ( V_2 ) ) {
V_23 = F_33 ( V_2 ) ;
if ( V_23 )
goto V_87;
}
V_23 = F_12 ( V_2 ) ;
if ( V_23 )
goto V_88;
return 0 ;
V_88:
F_44 ( V_2 ) ;
V_87:
V_24 . V_25 = - 1 ;
return V_23 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
F_25 ( V_2 ) ;
F_47 ( V_21 ) ;
F_1 ( V_2 ) ;
F_48 ( V_21 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_13 ( V_2 ) ;
if ( ! V_24 . V_89 || ( V_24 . V_25 < 0 ) )
return;
F_50 ( V_21 ) ;
V_72 ( & V_2 -> log . V_30 . V_72 ) ;
F_4 ( V_2 ) ;
F_31 ( V_2 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_90 * V_33 ;
unsigned long V_91 ;
T_4 V_36 , V_92 ;
int V_23 ;
F_35 ( V_2 -> log . V_33 ) ;
if ( V_24 . V_25 > V_93 )
V_24 . V_25 = V_93 ;
V_36 = ( 1 + V_47 + 1 +
V_44 + 1 +
V_49 + 1 ) << V_94 ;
if ( F_26 ( ! F_52 () ) ) {
V_23 = - V_95 ;
goto V_87;
}
V_33 = F_53 ( V_2 , V_36 ) ;
if ( F_37 ( V_33 ) ) {
V_23 = F_38 ( V_33 ) ;
goto V_87;
}
V_2 -> log . V_33 = V_33 ;
if ( V_24 . V_25 >= 0 ) {
V_23 = F_33 ( V_2 ) ;
if ( V_23 < 0 )
goto V_96;
}
V_92 = V_97 | V_98 |
( V_47 << V_99 ) |
( V_44 << V_100 ) |
( V_49 << V_101 ) ;
V_91 = F_54 ( V_33 ) >> V_94 ;
V_2 -> log . V_92 = ( V_91 << V_102 ) | V_92 ;
return 0 ;
V_96:
F_55 ( & V_2 -> log . V_33 ) ;
V_87:
V_24 . V_25 = - 1 ;
return V_23 ;
}
void F_56 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_55 ( & V_2 -> log . V_33 ) ;
}
int F_57 ( struct V_20 * V_21 , T_5 V_6 )
{
struct V_1 * V_2 = & V_21 -> V_2 ;
union F_5 V_103 ;
int V_23 ;
V_103 . V_104 = V_6 ;
if ( V_103 . V_105 < V_106 ||
V_103 . V_105 > V_93 )
return - V_95 ;
if ( ! V_103 . V_107 && ( V_24 . V_25 < 0 ) )
return 0 ;
V_23 = F_5 ( V_2 , V_103 . V_104 ) ;
if ( V_23 < 0 ) {
F_58 ( L_11 , V_23 ) ;
return V_23 ;
}
if ( V_103 . V_107 ) {
V_24 . V_25 = V_103 . V_105 ;
V_23 = F_46 ( V_2 ) ;
if ( V_23 < 0 ) {
F_58 ( L_12 , V_23 ) ;
return V_23 ;
}
F_59 ( V_21 ) ;
} else {
F_49 ( V_2 ) ;
V_24 . V_25 = - 1 ;
}
return V_23 ;
}
void F_60 ( struct V_20 * V_21 )
{
if ( ! V_24 . V_89 || V_24 . V_25 < 0 )
return;
F_61 ( & V_21 -> V_26 . V_78 ) ;
F_46 ( & V_21 -> V_2 ) ;
F_62 ( & V_21 -> V_26 . V_78 ) ;
}
void F_63 ( struct V_20 * V_21 )
{
if ( ! V_24 . V_89 )
return;
F_61 ( & V_21 -> V_26 . V_78 ) ;
F_50 ( V_21 ) ;
F_44 ( & V_21 -> V_2 ) ;
F_62 ( & V_21 -> V_26 . V_78 ) ;
}
