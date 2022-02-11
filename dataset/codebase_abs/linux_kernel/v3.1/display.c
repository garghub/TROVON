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
return snprintf ( V_5 , V_11 , L_1 ,
V_7 -> V_14 -> V_17 ?
V_7 -> V_14 -> V_17 ( V_7 ) : 0 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_18 , V_13 ;
if ( ! V_7 -> V_14 -> V_19 || ! V_7 -> V_14 -> V_17 )
return - V_20 ;
V_13 = F_4 ( V_5 , 0 , & V_18 ) ;
if ( V_13 )
return V_13 ;
V_18 = ! ! V_18 ;
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
V_13 = F_4 ( V_5 , 0 , & V_41 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_7 -> V_14 -> V_42 ( V_7 , V_41 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_43 ;
if ( ! V_7 -> V_14 -> V_44 )
return - V_20 ;
V_43 = V_7 -> V_14 -> V_44 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_6 , V_43 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_43 , V_13 ;
if ( ! V_7 -> V_14 -> V_45 || ! V_7 -> V_14 -> V_44 )
return - V_20 ;
V_13 = F_4 ( V_5 , 0 , & V_43 ) ;
if ( V_13 )
return V_13 ;
V_43 = ! ! V_43 ;
V_13 = V_7 -> V_14 -> V_45 ( V_7 , V_43 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_46 ;
if ( ! V_7 -> V_14 -> V_47 )
return - V_20 ;
V_46 = V_7 -> V_14 -> V_47 ( V_7 ) ;
return snprintf ( V_5 , V_11 , L_7 , V_46 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_46 ;
int V_13 ;
if ( ! V_7 -> V_14 -> V_47 || ! V_7 -> V_14 -> V_48 )
return - V_20 ;
V_13 = F_16 ( V_5 , 0 , & V_46 ) ;
if ( V_13 )
return V_13 ;
if ( V_46 > 0xfffff )
return - V_38 ;
V_13 = V_7 -> V_14 -> V_48 ( V_7 , V_46 ) ;
if ( V_13 )
return V_13 ;
return V_12 ;
}
void F_17 ( struct V_6 * V_7 ,
T_4 * V_49 , T_4 * V_50 )
{
* V_49 = V_7 -> V_51 . V_52 . V_25 ;
* V_50 = V_7 -> V_51 . V_52 . V_29 ;
}
void F_18 ( enum V_53 V_54 ,
T_3 V_55 , T_3 V_56 ,
T_3 * V_57 , T_3 * V_58 )
{
unsigned V_59 = F_19 () ;
* V_58 = V_55 - V_59 ;
* V_57 = V_55 - V_56 ;
}
int F_20 ( struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_60 :
if ( V_7 -> V_61 . V_62 . V_63 == 24 )
return 24 ;
else
return 16 ;
case V_64 :
case V_65 :
if ( V_7 -> V_66 . V_67 == 24 )
return 24 ;
else
return 16 ;
case V_68 :
case V_69 :
case V_70 :
return 24 ;
default:
F_21 () ;
}
}
bool F_22 ( struct V_6 * V_7 ,
enum V_71 V_72 )
{
int V_73 ;
if ( V_72 != V_74 && V_72 != V_75 )
return false ;
if ( V_7 -> type == V_60 &&
( V_7 -> V_51 . V_76 & V_77 ) == 0 )
return false ;
switch ( V_7 -> type ) {
case V_60 :
V_73 = V_7 -> V_61 . V_62 . V_63 ;
break;
case V_70 :
case V_68 :
case V_69 :
V_73 = 24 ;
break;
case V_64 :
case V_65 :
V_73 = V_7 -> V_66 . V_67 ;
break;
default:
F_21 () ;
}
return V_73 > 16 ;
}
void F_23 ( struct V_78 * V_79 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_80 ;
int V_13 ;
switch ( V_7 -> type ) {
#ifdef F_24
case V_60 :
V_13 = F_25 ( V_7 ) ;
break;
#endif
#ifdef F_26
case V_64 :
V_13 = F_27 ( V_7 ) ;
break;
#endif
#ifdef F_9
case V_68 :
V_13 = F_28 ( V_7 ) ;
break;
#endif
#ifdef F_29
case V_69 :
V_13 = F_30 ( V_7 ) ;
break;
#endif
#ifdef F_31
case V_65 :
V_13 = F_32 ( V_7 ) ;
break;
#endif
case V_70 :
V_13 = F_33 ( V_7 ) ;
break;
default:
F_34 ( L_8 ,
V_7 -> V_81 ) ;
return;
}
if ( V_13 ) {
F_34 ( L_9 , V_7 -> V_81 ) ;
return;
}
V_80 = 0 ;
while ( ( V_4 = V_82 [ V_80 ++ ] ) != NULL ) {
V_13 = F_35 ( & V_7 -> V_2 , V_4 ) ;
if ( V_13 )
F_34 ( L_10 ) ;
}
V_13 = F_36 ( & V_79 -> V_2 . V_83 , & V_7 -> V_2 . V_83 ,
F_37 ( & V_7 -> V_2 ) ) ;
if ( V_13 )
F_34 ( L_11 ) ;
}
void F_38 ( struct V_78 * V_79 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 ;
int V_80 = 0 ;
F_39 ( & V_79 -> V_2 . V_83 , F_37 ( & V_7 -> V_2 ) ) ;
while ( ( V_4 = V_82 [ V_80 ++ ] ) != NULL )
F_40 ( & V_7 -> V_2 , V_4 ) ;
if ( V_7 -> V_84 )
V_7 -> V_84 -> V_85 ( V_7 -> V_84 ) ;
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
F_34 ( L_12 ,
V_7 -> V_81 ) ;
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
F_57 ( L_13 ) ;
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
