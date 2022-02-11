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
void F_19 ( enum V_53 V_54 ,
T_3 V_55 , T_3 V_56 ,
T_3 * V_57 , T_3 * V_58 )
{
unsigned V_59 = F_20 () ;
* V_58 = V_55 - V_59 ;
* V_57 = V_55 - V_56 ;
}
int F_21 ( struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_60 :
if ( V_7 -> V_61 . V_62 . V_63 == 24 )
return 24 ;
else
return 16 ;
case V_64 :
if ( V_7 -> V_65 . V_66 == 24 )
return 24 ;
else
return 16 ;
case V_67 :
if ( F_22 ( V_7 -> V_51 . V_68 ) > 16 )
return 24 ;
else
return 16 ;
case V_69 :
case V_70 :
case V_71 :
return 24 ;
default:
F_23 () ;
}
}
bool F_24 ( struct V_6 * V_7 ,
enum V_72 V_73 )
{
int V_74 ;
if ( V_73 != V_75 && V_73 != V_76 )
return false ;
if ( V_7 -> type == V_60 &&
( V_7 -> V_51 . V_77 & V_78 ) == 0 )
return false ;
switch ( V_7 -> type ) {
case V_60 :
V_74 = V_7 -> V_61 . V_62 . V_63 ;
break;
case V_71 :
case V_69 :
case V_70 :
V_74 = 24 ;
break;
case V_64 :
V_74 = V_7 -> V_65 . V_66 ;
break;
case V_67 :
V_74 = F_22 ( V_7 -> V_51 . V_68 ) ;
break;
default:
F_23 () ;
}
return V_74 > 16 ;
}
void F_25 ( struct V_79 * V_80 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_81 ;
int V_13 ;
switch ( V_7 -> type ) {
#ifdef F_26
case V_60 :
V_13 = F_27 ( V_7 ) ;
break;
#endif
#ifdef F_28
case V_64 :
V_13 = F_29 ( V_7 ) ;
break;
#endif
#ifdef F_9
case V_69 :
V_13 = F_30 ( V_7 ) ;
break;
#endif
#ifdef F_31
case V_70 :
V_13 = F_32 ( V_7 ) ;
break;
#endif
#ifdef F_33
case V_67 :
V_13 = F_34 ( V_7 ) ;
break;
#endif
case V_71 :
V_13 = F_35 ( V_7 ) ;
break;
default:
F_36 ( L_8 ,
V_7 -> V_82 ) ;
return;
}
if ( V_13 ) {
F_36 ( L_9 , V_7 -> V_82 ) ;
return;
}
V_81 = 0 ;
while ( ( V_4 = V_83 [ V_81 ++ ] ) != NULL ) {
V_13 = F_37 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 )
F_36 ( L_10 ) ;
}
V_13 = F_38 ( & V_80 -> V_2 . V_84 , & V_7 -> V_2 . V_84 ,
F_39 ( & V_7 -> V_2 ) ) ;
if ( V_13 )
F_36 ( L_11 ) ;
}
void F_40 ( struct V_79 * V_80 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_81 = 0 ;
F_41 ( & V_80 -> V_2 . V_84 , F_39 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_83 [ V_81 ++ ] ) != NULL )
F_42 ( & V_7 -> V_2 , V_4 ) ;
if ( V_7 -> V_85 )
V_7 -> V_85 -> V_86 ( V_7 -> V_85 ) ;
}
static int F_43 ( struct V_1 * V_2 , void * V_87 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_88 ) {
V_7 -> V_89 = false ;
return 0 ;
}
if ( ! V_7 -> V_14 -> V_90 ) {
F_36 ( L_12 ,
V_7 -> V_82 ) ;
return - V_91 ;
}
V_13 = V_7 -> V_14 -> V_90 ( V_7 ) ;
if ( V_13 )
return V_13 ;
V_7 -> V_89 = true ;
return 0 ;
}
int F_44 ( void )
{
int V_13 ;
struct V_92 * V_93 = F_45 () ;
V_13 = F_46 ( V_93 , NULL , NULL , F_43 ) ;
if ( V_13 ) {
F_47 () ;
return V_13 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_87 )
{
int V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_89 && V_7 -> V_14 -> V_94 ) {
V_13 = V_7 -> V_14 -> V_94 ( V_7 ) ;
if ( V_13 )
return V_13 ;
}
V_7 -> V_89 = false ;
return 0 ;
}
int F_47 ( void )
{
struct V_92 * V_93 = F_45 () ;
return F_46 ( V_93 , NULL , NULL , F_48 ) ;
}
static int F_49 ( struct V_1 * V_2 , void * V_87 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_9 != V_10 )
V_7 -> V_14 -> V_16 ( V_7 ) ;
return 0 ;
}
void F_50 ( void )
{
struct V_92 * V_93 = F_45 () ;
F_46 ( V_93 , NULL , NULL , F_49 ) ;
}
void F_51 ( struct V_6 * V_7 )
{
F_52 ( & V_7 -> V_2 ) ;
}
void F_53 ( struct V_6 * V_7 )
{
F_54 ( & V_7 -> V_2 ) ;
}
int F_55 ( struct V_1 * V_2 , void * V_87 )
{
return 1 ;
}
struct V_6 * F_56 ( void * V_87 ,
int (* F_55)( struct V_6 * V_7 , void * V_87 ) )
{
struct V_6 * V_7 = NULL ;
while ( ( V_7 = F_57 ( V_7 ) ) != NULL ) {
if ( F_55 ( V_7 , V_87 ) )
return V_7 ;
}
return NULL ;
}
int F_58 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_14 ) {
F_59 ( L_13 ) ;
return - V_95 ;
}
if ( ! F_60 ( V_7 -> V_2 . V_14 -> V_96 ) ) {
return - V_95 ;
}
return 0 ;
}
void F_61 ( struct V_6 * V_7 )
{
F_62 ( V_7 -> V_2 . V_14 -> V_96 ) ;
}
