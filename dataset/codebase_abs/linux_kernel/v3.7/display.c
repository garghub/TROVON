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
V_7 -> V_14 -> V_16 ( V_7 ) ;
V_7 -> V_14 -> V_36 ( V_7 , & V_22 ) ;
V_13 = V_7 -> V_14 -> V_15 ( V_7 ) ;
if ( V_13 )
return V_13 ;
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
static int F_23 ( struct V_6 * V_7 , bool V_65 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
int V_70 , V_13 ;
V_67 = F_24 ( V_7 ) ;
F_25 ( V_7 -> V_71 ) ;
F_25 ( V_67 -> V_1 ) ;
V_13 = F_26 ( V_67 , V_7 ) ;
if ( V_13 ) {
F_27 ( L_8 ) ;
return V_13 ;
}
V_69 = F_28 ( V_7 -> V_72 ) ;
if ( V_69 -> V_71 && ! V_65 )
return 0 ;
if ( V_69 -> V_71 )
V_69 -> V_73 ( V_69 ) ;
V_13 = V_69 -> V_74 ( V_69 , V_67 ) ;
if ( V_13 ) {
F_27 ( L_9 ) ;
F_29 ( V_67 ) ;
return V_13 ;
}
for ( V_70 = 0 ; V_70 < F_30 () ; ++ V_70 ) {
struct V_75 * V_76 = F_31 ( V_70 ) ;
if ( ! V_76 -> V_77 || V_65 ) {
if ( V_76 -> V_77 )
V_76 -> V_78 ( V_76 ) ;
V_13 = V_76 -> V_79 ( V_76 , V_69 ) ;
if ( V_13 ) {
F_27 ( L_10 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
if ( V_7 -> V_71 ) {
struct V_68 * V_69 = V_7 -> V_71 -> V_77 ;
if ( V_69 )
V_69 -> V_73 ( V_69 ) ;
F_29 ( V_7 -> V_71 ) ;
}
}
int F_33 ( struct V_80 * V_81 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_70 , V_13 ;
const char * V_82 = F_34 () ;
bool V_65 ;
V_65 = V_82 && strcmp ( V_82 , V_7 -> V_83 ) == 0 ;
F_23 ( V_7 , V_65 ) ;
V_70 = 0 ;
while ( ( V_4 = V_84 [ V_70 ++ ] ) != NULL ) {
V_13 = F_35 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 ) {
for ( V_70 = V_70 - 2 ; V_70 >= 0 ; V_70 -- ) {
V_4 = V_84 [ V_70 ] ;
F_36 ( & V_7 -> V_2 , V_4 ) ;
}
F_32 ( V_7 ) ;
F_27 ( L_11 ) ;
return V_13 ;
}
}
V_13 = F_37 ( & V_81 -> V_2 . V_85 , & V_7 -> V_2 . V_85 ,
F_38 ( & V_7 -> V_2 ) ) ;
if ( V_13 ) {
while ( ( V_4 = V_84 [ V_70 ++ ] ) != NULL )
F_36 ( & V_7 -> V_2 , V_4 ) ;
F_32 ( V_7 ) ;
F_27 ( L_12 ) ;
return V_13 ;
}
return 0 ;
}
void F_39 ( struct V_80 * V_81 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_70 = 0 ;
F_40 ( & V_81 -> V_2 . V_85 , F_38 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_84 [ V_70 ++ ] ) != NULL )
F_36 ( & V_7 -> V_2 , V_4 ) ;
F_32 ( V_7 ) ;
}
static int F_41 ( struct V_1 * V_2 , void * V_86 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_87 ) {
V_7 -> V_88 = false ;
return 0 ;
}
if ( ! V_7 -> V_14 -> V_89 ) {
F_27 ( L_13 ,
V_7 -> V_83 ) ;
return - V_90 ;
}
V_13 = V_7 -> V_14 -> V_89 ( V_7 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_88 = true ;
return 0 ;
}
int F_42 ( void )
{
int V_13 ;
struct V_91 * V_92 = F_43 () ;
V_13 = F_44 ( V_92 , NULL , NULL , F_41 ) ;
if ( V_13 ) {
F_45 () ;
return V_13 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , void * V_86 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_88 && V_7 -> V_14 -> V_93 ) {
V_13 = V_7 -> V_14 -> V_93 ( V_7 ) ;
if ( V_13 )
return V_13 ;
}
V_7 -> V_88 = false ;
return 0 ;
}
int F_45 ( void )
{
struct V_91 * V_92 = F_43 () ;
return F_44 ( V_92 , NULL , NULL , F_46 ) ;
}
static int F_47 ( struct V_1 * V_2 , void * V_86 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_10 )
V_7 -> V_14 -> V_16 ( V_7 ) ;
return 0 ;
}
void F_48 ( void )
{
struct V_91 * V_92 = F_43 () ;
F_44 ( V_92 , NULL , NULL , F_47 ) ;
}
void F_49 ( struct V_6 * V_7 )
{
F_50 ( & V_7 -> V_2 ) ;
}
void F_51 ( struct V_6 * V_7 )
{
F_52 ( & V_7 -> V_2 ) ;
}
int F_53 ( struct V_1 * V_2 , void * V_86 )
{
return 1 ;
}
struct V_6 * F_54 ( void * V_86 ,
int (* F_53)( struct V_6 * V_7 , void * V_86 ) )
{
struct V_6 * V_7 = NULL ;
while ( ( V_7 = F_55 ( V_7 ) ) != NULL ) {
if ( F_53 ( V_7 , V_86 ) )
return V_7 ;
}
return NULL ;
}
int F_56 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_14 ) {
F_57 ( L_14 ) ;
return - V_94 ;
}
if ( ! F_58 ( V_7 -> V_2 . V_14 -> V_95 ) ) {
return - V_94 ;
}
return 0 ;
}
void F_59 ( struct V_6 * V_7 )
{
F_60 ( V_7 -> V_2 . V_14 -> V_95 ) ;
}
