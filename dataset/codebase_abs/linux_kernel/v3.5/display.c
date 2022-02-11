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
int V_13 ;
bool V_8 ;
V_13 = F_4 ( V_5 , & V_8 ) ;
if ( V_13 )
return V_13 ;
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
return snprintf ( V_5 , V_11 , L_1 ,
V_7 -> V_14 -> V_17 ?
V_7 -> V_14 -> V_17 ( V_7 ) : 0 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
bool V_18 ;
if ( ! V_7 -> V_14 -> V_19 || ! V_7 -> V_14 -> V_17 )
return - V_20 ;
V_13 = F_4 ( V_5 , & V_18 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_19 ( V_7 , V_18 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 V_22 ;
if ( ! V_7 -> V_14 -> V_23 )
return - V_20 ;
V_7 -> V_14 -> V_23 ( V_7 , & V_22 ) ;
return snprintf ( V_5 , V_11 , L_2 ,
V_22 . V_24 ,
V_22 . V_25 , V_22 . V_26 , V_22 . V_27 , V_22 . V_28 ,
V_22 . V_29 , V_22 . V_30 , V_22 . V_31 , V_22 . V_32 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_21 V_22 ;
int V_13 , V_33 ;
if ( ! V_7 -> V_14 -> V_34 || ! V_7 -> V_14 -> V_35 )
return - V_20 ;
V_33 = 0 ;
#ifdef F_9
if ( strncmp ( L_3 , V_5 , 3 ) == 0 ) {
V_22 = V_36 ;
V_33 = 1 ;
} else if ( strncmp ( L_4 , V_5 , 4 ) == 0 ) {
V_22 = V_37 ;
V_33 = 1 ;
}
#endif
if ( ! V_33 && sscanf ( V_5 , L_5 ,
& V_22 . V_24 ,
& V_22 . V_25 , & V_22 . V_26 , & V_22 . V_27 , & V_22 . V_28 ,
& V_22 . V_29 , & V_22 . V_30 , & V_22 . V_31 , & V_22 . V_32 ) != 9 )
return - V_38 ;
V_13 = V_7 -> V_14 -> V_35 ( V_7 , & V_22 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_14 -> V_34 ( V_7 , & V_22 ) ;
return V_12 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_39 ;
if ( ! V_7 -> V_14 -> V_40 )
return - V_20 ;
V_39 = V_7 -> V_14 -> V_40 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_39 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_41 , V_13 ;
if ( ! V_7 -> V_14 -> V_42 || ! V_7 -> V_14 -> V_40 )
return - V_20 ;
V_13 = F_12 ( V_5 , 0 , & V_41 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_42 ( V_7 , V_41 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_43 ;
if ( ! V_7 -> V_14 -> V_44 )
return - V_20 ;
V_43 = V_7 -> V_14 -> V_44 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_43 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
bool V_43 ;
if ( ! V_7 -> V_14 -> V_45 || ! V_7 -> V_14 -> V_44 )
return - V_20 ;
V_13 = F_4 ( V_5 , & V_43 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_45 ( V_7 , V_43 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_46 ;
if ( ! V_7 -> V_14 -> V_47 )
return - V_20 ;
V_46 = V_7 -> V_14 -> V_47 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_7 , V_46 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_46 ;
int V_13 ;
if ( ! V_7 -> V_14 -> V_47 || ! V_7 -> V_14 -> V_48 )
return - V_20 ;
V_13 = F_17 ( V_5 , 0 , & V_46 ) ;
if ( V_13 )
return V_13 ;
if ( V_46 > 0xfffff )
return - V_38 ;
V_13 = V_7 -> V_14 -> V_48 ( V_7 , V_46 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
void F_18 ( struct V_6 * V_7 ,
T_4 * V_49 , T_4 * V_50 )
{
* V_49 = V_7 -> V_51 . V_52 . V_25 ;
* V_50 = V_7 -> V_51 . V_52 . V_29 ;
}
int F_19 ( struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_53 :
if ( V_7 -> V_54 . V_55 . V_56 == 24 )
return 24 ;
else
return 16 ;
case V_57 :
if ( V_7 -> V_58 . V_59 == 24 )
return 24 ;
else
return 16 ;
case V_60 :
if ( F_20 ( V_7 -> V_51 . V_61 ) > 16 )
return 24 ;
else
return 16 ;
case V_62 :
case V_63 :
case V_64 :
return 24 ;
default:
F_21 () ;
return 0 ;
}
}
void F_22 ( struct V_6 * V_7 ,
struct V_21 * V_52 )
{
* V_52 = V_7 -> V_51 . V_52 ;
}
bool F_23 ( struct V_6 * V_7 ,
enum V_65 V_66 )
{
int V_67 ;
if ( V_66 != V_68 && V_66 != V_69 )
return false ;
if ( V_7 -> type == V_53 &&
( V_7 -> V_51 . V_70 & V_71 ) == 0 )
return false ;
switch ( V_7 -> type ) {
case V_53 :
V_67 = V_7 -> V_54 . V_55 . V_56 ;
break;
case V_64 :
case V_62 :
case V_63 :
V_67 = 24 ;
break;
case V_57 :
V_67 = V_7 -> V_58 . V_59 ;
break;
case V_60 :
V_67 = F_20 ( V_7 -> V_51 . V_61 ) ;
break;
default:
F_21 () ;
return false ;
}
return V_67 > 16 ;
}
void F_24 ( struct V_72 * V_73 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_74 ;
int V_13 ;
V_74 = 0 ;
while ( ( V_4 = V_75 [ V_74 ++ ] ) != NULL ) {
V_13 = F_25 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 )
F_26 ( L_8 ) ;
}
V_13 = F_27 ( & V_73 -> V_2 . V_76 , & V_7 -> V_2 . V_76 ,
F_28 ( & V_7 -> V_2 ) ) ;
if ( V_13 )
F_26 ( L_9 ) ;
}
void F_29 ( struct V_72 * V_73 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_74 = 0 ;
F_30 ( & V_73 -> V_2 . V_76 , F_28 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_75 [ V_74 ++ ] ) != NULL )
F_31 ( & V_7 -> V_2 , V_4 ) ;
if ( V_7 -> V_77 )
V_7 -> V_77 -> V_78 ( V_7 -> V_77 ) ;
}
static int F_32 ( struct V_1 * V_2 , void * V_79 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_80 ) {
V_7 -> V_81 = false ;
return 0 ;
}
if ( ! V_7 -> V_14 -> V_82 ) {
F_26 ( L_10 ,
V_7 -> V_83 ) ;
return - V_84 ;
}
V_13 = V_7 -> V_14 -> V_82 ( V_7 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_81 = true ;
return 0 ;
}
int F_33 ( void )
{
int V_13 ;
struct V_85 * V_86 = F_34 () ;
V_13 = F_35 ( V_86 , NULL , NULL , F_32 ) ;
if ( V_13 ) {
F_36 () ;
return V_13 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_79 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_81 && V_7 -> V_14 -> V_87 ) {
V_13 = V_7 -> V_14 -> V_87 ( V_7 ) ;
if ( V_13 )
return V_13 ;
}
V_7 -> V_81 = false ;
return 0 ;
}
int F_36 ( void )
{
struct V_85 * V_86 = F_34 () ;
return F_35 ( V_86 , NULL , NULL , F_37 ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_79 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_10 )
V_7 -> V_14 -> V_16 ( V_7 ) ;
return 0 ;
}
void F_39 ( void )
{
struct V_85 * V_86 = F_34 () ;
F_35 ( V_86 , NULL , NULL , F_38 ) ;
}
void F_40 ( struct V_6 * V_7 )
{
F_41 ( & V_7 -> V_2 ) ;
}
void F_42 ( struct V_6 * V_7 )
{
F_43 ( & V_7 -> V_2 ) ;
}
int F_44 ( struct V_1 * V_2 , void * V_79 )
{
return 1 ;
}
struct V_6 * F_45 ( void * V_79 ,
int (* F_44)( struct V_6 * V_7 , void * V_79 ) )
{
struct V_6 * V_7 = NULL ;
while ( ( V_7 = F_46 ( V_7 ) ) != NULL ) {
if ( F_44 ( V_7 , V_79 ) )
return V_7 ;
}
return NULL ;
}
int F_47 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_14 ) {
F_48 ( L_11 ) ;
return - V_88 ;
}
if ( ! F_49 ( V_7 -> V_2 . V_14 -> V_89 ) ) {
return - V_88 ;
}
return 0 ;
}
void F_50 ( struct V_6 * V_7 )
{
F_51 ( V_7 -> V_2 . V_14 -> V_89 ) ;
}
