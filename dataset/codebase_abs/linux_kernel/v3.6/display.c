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
struct V_21 V_22 = V_7 -> V_33 . V_34 ;
int V_13 , V_35 ;
if ( ! V_7 -> V_14 -> V_36 || ! V_7 -> V_14 -> V_37 )
return - V_20 ;
V_35 = 0 ;
#ifdef F_9
if ( strncmp ( L_3 , V_5 , 3 ) == 0 ) {
V_22 = V_38 ;
V_35 = 1 ;
} else if ( strncmp ( L_4 , V_5 , 4 ) == 0 ) {
V_22 = V_39 ;
V_35 = 1 ;
}
#endif
if ( ! V_35 && sscanf ( V_5 , L_5 ,
& V_22 . V_24 ,
& V_22 . V_25 , & V_22 . V_26 , & V_22 . V_27 , & V_22 . V_28 ,
& V_22 . V_29 , & V_22 . V_30 , & V_22 . V_31 , & V_22 . V_32 ) != 9 )
return - V_40 ;
V_13 = V_7 -> V_14 -> V_37 ( V_7 , & V_22 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_14 -> V_36 ( V_7 , & V_22 ) ;
return V_12 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_41 ;
if ( ! V_7 -> V_14 -> V_42 )
return - V_20 ;
V_41 = V_7 -> V_14 -> V_42 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_41 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_43 , V_13 ;
if ( ! V_7 -> V_14 -> V_44 || ! V_7 -> V_14 -> V_42 )
return - V_20 ;
V_13 = F_12 ( V_5 , 0 , & V_43 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_44 ( V_7 , V_43 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_45 ;
if ( ! V_7 -> V_14 -> V_46 )
return - V_20 ;
V_45 = V_7 -> V_14 -> V_46 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_45 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
bool V_45 ;
if ( ! V_7 -> V_14 -> V_47 || ! V_7 -> V_14 -> V_46 )
return - V_20 ;
V_13 = F_4 ( V_5 , & V_45 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_47 ( V_7 , V_45 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_48 ;
if ( ! V_7 -> V_14 -> V_49 )
return - V_20 ;
V_48 = V_7 -> V_14 -> V_49 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_7 , V_48 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_48 ;
int V_13 ;
if ( ! V_7 -> V_14 -> V_49 || ! V_7 -> V_14 -> V_50 )
return - V_20 ;
V_13 = F_17 ( V_5 , 0 , & V_48 ) ;
if ( V_13 )
return V_13 ;
if ( V_48 > 0xfffff )
return - V_40 ;
V_13 = V_7 -> V_14 -> V_50 ( V_7 , V_48 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
void F_18 ( struct V_6 * V_7 ,
T_4 * V_51 , T_4 * V_52 )
{
* V_51 = V_7 -> V_33 . V_34 . V_25 ;
* V_52 = V_7 -> V_33 . V_34 . V_29 ;
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
if ( F_20 ( V_7 -> V_33 . V_61 ) > 16 )
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
struct V_21 * V_34 )
{
* V_34 = V_7 -> V_33 . V_34 ;
}
void F_23 ( struct V_65 * V_66 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_67 ;
int V_13 ;
V_67 = 0 ;
while ( ( V_4 = V_68 [ V_67 ++ ] ) != NULL ) {
V_13 = F_24 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 )
F_25 ( L_8 ) ;
}
V_13 = F_26 ( & V_66 -> V_2 . V_69 , & V_7 -> V_2 . V_69 ,
F_27 ( & V_7 -> V_2 ) ) ;
if ( V_13 )
F_25 ( L_9 ) ;
}
void F_28 ( struct V_65 * V_66 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_67 = 0 ;
F_29 ( & V_66 -> V_2 . V_69 , F_27 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_68 [ V_67 ++ ] ) != NULL )
F_30 ( & V_7 -> V_2 , V_4 ) ;
if ( V_7 -> V_70 )
V_7 -> V_70 -> V_71 ( V_7 -> V_70 ) ;
}
static int F_31 ( struct V_1 * V_2 , void * V_72 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_73 ) {
V_7 -> V_74 = false ;
return 0 ;
}
if ( ! V_7 -> V_14 -> V_75 ) {
F_25 ( L_10 ,
V_7 -> V_76 ) ;
return - V_77 ;
}
V_13 = V_7 -> V_14 -> V_75 ( V_7 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_74 = true ;
return 0 ;
}
int F_32 ( void )
{
int V_13 ;
struct V_78 * V_79 = F_33 () ;
V_13 = F_34 ( V_79 , NULL , NULL , F_31 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_72 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_74 && V_7 -> V_14 -> V_80 ) {
V_13 = V_7 -> V_14 -> V_80 ( V_7 ) ;
if ( V_13 )
return V_13 ;
}
V_7 -> V_74 = false ;
return 0 ;
}
int F_35 ( void )
{
struct V_78 * V_79 = F_33 () ;
return F_34 ( V_79 , NULL , NULL , F_36 ) ;
}
static int F_37 ( struct V_1 * V_2 , void * V_72 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_10 )
V_7 -> V_14 -> V_16 ( V_7 ) ;
return 0 ;
}
void F_38 ( void )
{
struct V_78 * V_79 = F_33 () ;
F_34 ( V_79 , NULL , NULL , F_37 ) ;
}
void F_39 ( struct V_6 * V_7 )
{
F_40 ( & V_7 -> V_2 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
F_42 ( & V_7 -> V_2 ) ;
}
int F_43 ( struct V_1 * V_2 , void * V_72 )
{
return 1 ;
}
struct V_6 * F_44 ( void * V_72 ,
int (* F_43)( struct V_6 * V_7 , void * V_72 ) )
{
struct V_6 * V_7 = NULL ;
while ( ( V_7 = F_45 ( V_7 ) ) != NULL ) {
if ( F_43 ( V_7 , V_72 ) )
return V_7 ;
}
return NULL ;
}
int F_46 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_14 ) {
F_47 ( L_11 ) ;
return - V_81 ;
}
if ( ! F_48 ( V_7 -> V_2 . V_14 -> V_82 ) ) {
return - V_81 ;
}
return 0 ;
}
void F_49 ( struct V_6 * V_7 )
{
F_50 ( V_7 -> V_2 . V_14 -> V_82 ) ;
}
