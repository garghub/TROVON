static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_8 = V_7 -> V_9 != V_10 ;
return snprintf ( V_5 , V_11 , L_1 , V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 , V_8 ;
V_13 = F_4 ( V_5 , 0 , & V_8 ) ;
if ( V_13 )
return V_13 ;
V_8 = ! ! V_8 ;
if ( V_8 != ( V_7 -> V_9 != V_10 ) ) {
if ( V_8 ) {
V_13 = V_7 -> V_14 -> V_15 ( V_7 ) ;
if ( V_13 )
return V_13 ;
} else {
V_7 -> V_14 -> V_16 ( V_7 ) ;
}
}
return V_12 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_17 V_18 = V_19 ;
if ( V_7 -> V_14 -> V_20 )
V_18 = V_7 -> V_14 -> V_20 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_1 , V_18 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_21 , V_13 ;
enum V_17 V_18 ;
if ( ! V_7 -> V_14 -> V_22 )
return - V_23 ;
V_13 = F_4 ( V_5 , 0 , & V_21 ) ;
if ( V_13 )
return V_13 ;
switch ( V_21 ) {
case V_24 :
case V_19 :
case V_25 :
V_18 = (enum V_17 ) V_21 ;
break;
default:
return - V_23 ;
}
V_13 = V_7 -> V_14 -> V_22 ( V_7 , V_18 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_11 , L_1 ,
V_7 -> V_14 -> V_26 ?
V_7 -> V_14 -> V_26 ( V_7 ) : 0 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_27 , V_13 ;
if ( ! V_7 -> V_14 -> V_28 || ! V_7 -> V_14 -> V_26 )
return - V_29 ;
V_13 = F_4 ( V_5 , 0 , & V_27 ) ;
if ( V_13 )
return V_13 ;
V_27 = ! ! V_27 ;
V_13 = V_7 -> V_14 -> V_28 ( V_7 , V_27 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 V_31 ;
if ( ! V_7 -> V_14 -> V_32 )
return - V_29 ;
V_7 -> V_14 -> V_32 ( V_7 , & V_31 ) ;
return snprintf ( V_5 , V_11 , L_2 ,
V_31 . V_33 ,
V_31 . V_34 , V_31 . V_35 , V_31 . V_36 , V_31 . V_37 ,
V_31 . V_38 , V_31 . V_39 , V_31 . V_40 , V_31 . V_41 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 V_31 ;
int V_13 , V_42 ;
if ( ! V_7 -> V_14 -> V_43 || ! V_7 -> V_14 -> V_44 )
return - V_29 ;
V_42 = 0 ;
#ifdef F_11
if ( strncmp ( L_3 , V_5 , 3 ) == 0 ) {
V_31 = V_45 ;
V_42 = 1 ;
} else if ( strncmp ( L_4 , V_5 , 4 ) == 0 ) {
V_31 = V_46 ;
V_42 = 1 ;
}
#endif
if ( ! V_42 && sscanf ( V_5 , L_5 ,
& V_31 . V_33 ,
& V_31 . V_34 , & V_31 . V_35 , & V_31 . V_36 , & V_31 . V_37 ,
& V_31 . V_38 , & V_31 . V_39 , & V_31 . V_40 , & V_31 . V_41 ) != 9 )
return - V_23 ;
V_13 = V_7 -> V_14 -> V_44 ( V_7 , & V_31 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_14 -> V_43 ( V_7 , & V_31 ) ;
return V_12 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_47 ;
if ( ! V_7 -> V_14 -> V_48 )
return - V_29 ;
V_47 = V_7 -> V_14 -> V_48 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_47 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_49 , V_13 ;
if ( ! V_7 -> V_14 -> V_50 || ! V_7 -> V_14 -> V_48 )
return - V_29 ;
V_13 = F_4 ( V_5 , 0 , & V_49 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_50 ( V_7 , V_49 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_51 ;
if ( ! V_7 -> V_14 -> V_52 )
return - V_29 ;
V_51 = V_7 -> V_14 -> V_52 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_51 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_51 , V_13 ;
if ( ! V_7 -> V_14 -> V_53 || ! V_7 -> V_14 -> V_52 )
return - V_29 ;
V_13 = F_4 ( V_5 , 0 , & V_51 ) ;
if ( V_13 )
return V_13 ;
V_51 = ! ! V_51 ;
V_13 = V_7 -> V_14 -> V_53 ( V_7 , V_51 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_54 ;
if ( ! V_7 -> V_14 -> V_55 )
return - V_29 ;
V_54 = V_7 -> V_14 -> V_55 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_7 , V_54 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_54 ;
int V_13 ;
if ( ! V_7 -> V_14 -> V_55 || ! V_7 -> V_14 -> V_56 )
return - V_29 ;
V_13 = F_18 ( V_5 , 0 , & V_54 ) ;
if ( V_13 )
return V_13 ;
if ( V_54 > 0xfffff )
return - V_23 ;
V_13 = V_7 -> V_14 -> V_56 ( V_7 , V_54 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
void F_19 ( struct V_6 * V_7 ,
T_4 * V_57 , T_4 * V_58 )
{
* V_57 = V_7 -> V_59 . V_60 . V_34 ;
* V_58 = V_7 -> V_59 . V_60 . V_38 ;
}
void F_20 ( enum V_61 V_62 ,
T_3 V_63 , enum V_64 * V_65 ,
T_3 * V_66 , T_3 * V_67 )
{
unsigned V_68 ;
* V_65 = V_69 ;
V_68 = 16 * 32 / 8 ;
* V_67 = V_63 - 1 ;
* V_66 = V_63 - V_68 ;
}
int F_21 ( struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_70 :
if ( V_7 -> V_71 . V_72 . V_73 == 24 )
return 24 ;
else
return 16 ;
case V_74 :
case V_75 :
if ( V_7 -> V_76 . V_77 == 24 )
return 24 ;
else
return 16 ;
case V_78 :
case V_79 :
case V_80 :
return 24 ;
default:
F_22 () ;
}
}
bool F_23 ( struct V_6 * V_7 ,
enum V_81 V_18 )
{
int V_82 ;
if ( V_18 != V_83 && V_18 != V_84 )
return false ;
if ( V_7 -> type == V_70 &&
( V_7 -> V_59 . V_85 & V_86 ) == 0 )
return false ;
switch ( V_7 -> type ) {
case V_70 :
V_82 = V_7 -> V_71 . V_72 . V_73 ;
break;
case V_80 :
case V_78 :
case V_79 :
V_82 = 24 ;
break;
case V_74 :
case V_75 :
V_82 = V_7 -> V_76 . V_77 ;
break;
default:
F_22 () ;
}
return V_82 > 16 ;
}
void F_24 ( struct V_87 * V_88 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_89 ;
int V_13 ;
switch ( V_7 -> type ) {
#ifdef F_25
case V_70 :
V_13 = F_26 ( V_7 ) ;
break;
#endif
#ifdef F_27
case V_74 :
V_13 = F_28 ( V_7 ) ;
break;
#endif
#ifdef F_11
case V_78 :
V_13 = F_29 ( V_7 ) ;
break;
#endif
#ifdef F_30
case V_79 :
V_13 = F_31 ( V_7 ) ;
break;
#endif
#ifdef F_32
case V_75 :
V_13 = F_33 ( V_7 ) ;
break;
#endif
case V_80 :
V_13 = F_34 ( V_7 ) ;
break;
default:
F_35 ( L_8 ,
V_7 -> V_90 ) ;
return;
}
if ( V_13 ) {
F_35 ( L_9 , V_7 -> V_90 ) ;
return;
}
V_89 = 0 ;
while ( ( V_4 = V_91 [ V_89 ++ ] ) != NULL ) {
V_13 = F_36 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 )
F_35 ( L_10 ) ;
}
V_13 = F_37 ( & V_88 -> V_2 . V_92 , & V_7 -> V_2 . V_92 ,
F_38 ( & V_7 -> V_2 ) ) ;
if ( V_13 )
F_35 ( L_11 ) ;
}
void F_39 ( struct V_87 * V_88 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_89 = 0 ;
F_40 ( & V_88 -> V_2 . V_92 , F_38 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_91 [ V_89 ++ ] ) != NULL )
F_41 ( & V_7 -> V_2 , V_4 ) ;
if ( V_7 -> V_93 )
V_7 -> V_93 -> V_94 ( V_7 -> V_93 ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_95 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_96 ) {
V_7 -> V_97 = false ;
return 0 ;
}
if ( ! V_7 -> V_14 -> V_98 ) {
F_35 ( L_12 ,
V_7 -> V_90 ) ;
return - V_99 ;
}
V_13 = V_7 -> V_14 -> V_98 ( V_7 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_97 = true ;
return 0 ;
}
int F_43 ( void )
{
int V_13 ;
struct V_100 * V_101 = F_44 () ;
V_13 = F_45 ( V_101 , NULL , NULL , F_42 ) ;
if ( V_13 ) {
F_46 () ;
return V_13 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , void * V_95 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_97 && V_7 -> V_14 -> V_102 ) {
V_13 = V_7 -> V_14 -> V_102 ( V_7 ) ;
if ( V_13 )
return V_13 ;
}
V_7 -> V_97 = false ;
return 0 ;
}
int F_46 ( void )
{
struct V_100 * V_101 = F_44 () ;
return F_45 ( V_101 , NULL , NULL , F_47 ) ;
}
static int F_48 ( struct V_1 * V_2 , void * V_95 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_10 )
V_7 -> V_14 -> V_16 ( V_7 ) ;
return 0 ;
}
void F_49 ( void )
{
struct V_100 * V_101 = F_44 () ;
F_45 ( V_101 , NULL , NULL , F_48 ) ;
}
void F_50 ( struct V_6 * V_7 )
{
F_51 ( & V_7 -> V_2 ) ;
}
void F_52 ( struct V_6 * V_7 )
{
F_53 ( & V_7 -> V_2 ) ;
}
int F_54 ( struct V_1 * V_2 , void * V_95 )
{
return 1 ;
}
struct V_6 * F_55 ( void * V_95 ,
int (* F_54)( struct V_6 * V_7 , void * V_95 ) )
{
struct V_6 * V_7 = NULL ;
while ( ( V_7 = F_56 ( V_7 ) ) != NULL ) {
if ( F_54 ( V_7 , V_95 ) )
return V_7 ;
}
return NULL ;
}
int F_57 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_14 ) {
F_58 ( L_13 ) ;
return - V_103 ;
}
if ( ! F_59 ( V_7 -> V_2 . V_14 -> V_104 ) ) {
return - V_103 ;
}
return 0 ;
}
void F_60 ( struct V_6 * V_7 )
{
F_61 ( V_7 -> V_2 . V_14 -> V_104 ) ;
}
