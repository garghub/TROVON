static inline char * F_1 ( int type )
{
switch ( type ) {
case V_1 :
return L_1 ;
case V_2 :
return L_2 ;
case V_3 :
return L_3 ;
case V_4 :
return L_4 ;
default:
return L_5 ;
}
}
static T_1 F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_1 ( V_11 -> type ) ) ;
}
static T_1 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_7 , & V_11 -> V_12 ) ;
}
static T_1 F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_8 ,
V_11 -> V_13 [ 0 ] [ 0 ] , V_11 -> V_13 [ 0 ] [ 1 ] ,
V_11 -> V_13 [ 0 ] [ 2 ] , V_11 -> V_13 [ 0 ] [ 3 ] ,
V_11 -> V_13 [ 0 ] [ 4 ] , V_11 -> V_13 [ 0 ] [ 5 ] ,
V_11 -> V_13 [ 0 ] [ 6 ] , V_11 -> V_13 [ 0 ] [ 7 ] ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
F_7 ( V_11 ) ;
}
static int F_8 ( struct V_5 * V_6 , void * V_14 )
{
return ! strncmp ( F_9 ( V_6 ) , L_9 , 6 ) ;
}
void F_10 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = V_11 -> V_16 ;
F_11 ( L_10 , V_11 ) ;
V_11 -> V_6 . type = & V_17 ;
V_11 -> V_6 . V_18 = V_19 ;
V_11 -> V_6 . V_20 = & V_16 -> V_6 ;
F_12 ( & V_11 -> V_6 ) ;
}
void F_13 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = V_11 -> V_16 ;
F_11 ( L_10 , V_11 ) ;
F_14 ( & V_11 -> V_6 , L_11 , V_16 -> V_21 , V_11 -> V_22 ) ;
if ( F_15 ( & V_11 -> V_6 ) < 0 ) {
F_16 ( L_12 ) ;
return;
}
F_17 ( V_16 ) ;
}
void F_18 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = V_11 -> V_16 ;
if ( ! F_19 ( & V_11 -> V_6 ) )
return;
while ( 1 ) {
struct V_5 * V_6 ;
V_6 = F_20 ( & V_11 -> V_6 , NULL , F_8 ) ;
if ( ! V_6 )
break;
F_21 ( V_6 , NULL , V_23 ) ;
F_22 ( V_6 ) ;
}
F_23 ( & V_11 -> V_6 ) ;
F_24 ( V_16 ) ;
}
static inline char * F_25 ( int V_24 )
{
switch ( V_24 ) {
case V_25 :
return L_13 ;
case V_26 :
return L_14 ;
case V_27 :
return L_15 ;
case V_28 :
return L_16 ;
case V_29 :
return L_17 ;
case V_30 :
return L_18 ;
case V_31 :
return L_19 ;
default:
return L_5 ;
}
}
static inline char * F_26 ( int type )
{
switch ( type ) {
case V_32 :
return L_20 ;
case V_33 :
return L_21 ;
default:
return L_5 ;
}
}
static T_1 F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_25 ( V_16 -> V_24 ) ) ;
}
static T_1 F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_26 ( V_16 -> V_34 ) ) ;
}
static T_1 F_30 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
char V_21 [ V_35 + 1 ] ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
V_21 [ V_36 ] = V_16 -> F_9 [ V_36 ] ;
V_21 [ V_35 ] = '\0' ;
return sprintf ( V_9 , L_6 , V_21 ) ;
}
static T_1 F_31 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_37 [ 2 ] ,
V_16 -> V_37 [ 1 ] , V_16 -> V_37 [ 0 ] ) ;
}
static T_1 F_32 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_7 , & V_16 -> V_38 ) ;
}
static T_1 F_33 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_8 ,
V_16 -> V_13 [ 0 ] [ 0 ] , V_16 -> V_13 [ 0 ] [ 1 ] ,
V_16 -> V_13 [ 0 ] [ 2 ] , V_16 -> V_13 [ 0 ] [ 3 ] ,
V_16 -> V_13 [ 0 ] [ 4 ] , V_16 -> V_13 [ 0 ] [ 5 ] ,
V_16 -> V_13 [ 0 ] [ 6 ] , V_16 -> V_13 [ 0 ] [ 7 ] ) ;
}
static T_1 F_34 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_23 , V_16 -> V_39 ) ;
}
static T_1 F_35 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_23 , V_16 -> V_40 ) ;
}
static T_1 F_36 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_23 , V_16 -> V_41 ) ;
}
static T_1 F_37 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_23 , V_16 -> V_42 ) ;
}
static T_1 F_38 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_2 V_43 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
unsigned int V_44 ;
int V_45 ;
V_45 = F_39 ( V_9 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_44 != 0 && ( V_44 < 500 || V_44 > 3600000 ) )
return - V_46 ;
V_16 -> V_42 = V_44 ;
return V_43 ;
}
static T_1 F_40 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_23 , V_16 -> V_47 ) ;
}
static T_1 F_41 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_2 V_43 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
T_3 V_44 ;
int V_45 ;
V_45 = F_42 ( V_9 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_44 == 0 || V_44 % 2 || V_44 < V_16 -> V_48 )
return - V_46 ;
V_16 -> V_47 = V_44 ;
return V_43 ;
}
static T_1 F_43 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
return sprintf ( V_9 , L_23 , V_16 -> V_48 ) ;
}
static T_1 F_44 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_2 V_43 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
T_3 V_44 ;
int V_45 ;
V_45 = F_42 ( V_9 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_44 == 0 || V_44 % 2 || V_44 > V_16 -> V_47 )
return - V_46 ;
V_16 -> V_48 = V_44 ;
return V_43 ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = F_28 ( V_6 ) ;
F_7 ( V_16 ) ;
F_46 ( V_49 ) ;
}
static int F_47 ( struct V_50 * V_51 , void * V_52 )
{
struct V_15 * V_16 = V_51 -> V_53 ;
struct V_54 * V_55 = & V_16 -> V_56 ;
struct V_57 * V_58 ;
F_48 ( V_16 ) ;
F_49 (e, &cache->all, all) {
struct V_59 * V_14 = & V_58 -> V_14 ;
F_50 ( V_51 , L_24 ,
& V_14 -> V_38 ,
V_14 -> V_60 , V_14 -> V_61 ,
V_14 -> V_62 , V_14 -> V_37 [ 2 ] ,
V_14 -> V_37 [ 1 ] , V_14 -> V_37 [ 0 ] ,
F_51 ( V_14 -> V_63 ) ,
V_14 -> V_64 , V_14 -> V_65 , V_58 -> V_66 ) ;
}
F_52 ( V_16 ) ;
return 0 ;
}
static int F_53 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_54 ( V_68 , F_47 , V_67 -> V_69 ) ;
}
static int F_55 ( struct V_50 * V_51 , void * V_52 )
{
struct V_15 * V_16 = V_51 -> V_53 ;
struct V_70 * V_71 ;
F_48 ( V_16 ) ;
F_49 (b, &hdev->blacklist, list)
F_50 ( V_51 , L_7 , & V_71 -> V_38 ) ;
F_52 ( V_16 ) ;
return 0 ;
}
static int F_56 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_54 ( V_68 , F_55 , V_67 -> V_69 ) ;
}
static void F_57 ( struct V_50 * V_51 , T_4 * V_72 )
{
T_5 V_73 , V_74 ;
T_3 V_75 , V_76 , V_77 , V_78 ;
V_74 = F_58 ( V_72 ) ;
V_78 = F_59 ( V_72 + 4 ) ;
V_77 = F_59 ( V_72 + 6 ) ;
V_76 = F_59 ( V_72 + 8 ) ;
V_75 = F_59 ( V_72 + 10 ) ;
V_73 = F_58 ( V_72 + 12 ) ;
F_50 ( V_51 , L_25 ,
V_73 , V_75 , V_76 , V_77 , V_78 , V_74 ) ;
}
static int F_60 ( struct V_50 * V_51 , void * V_52 )
{
struct V_15 * V_16 = V_51 -> V_53 ;
struct V_79 * V_72 ;
F_48 ( V_16 ) ;
F_49 (uuid, &hdev->uuids, list)
F_57 ( V_51 , V_72 -> V_72 ) ;
F_52 ( V_16 ) ;
return 0 ;
}
static int F_61 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_54 ( V_68 , F_60 , V_67 -> V_69 ) ;
}
static int F_62 ( void * V_14 , T_6 V_44 )
{
struct V_15 * V_16 = V_14 ;
F_48 ( V_16 ) ;
V_16 -> V_80 = V_44 ;
F_52 ( V_16 ) ;
return 0 ;
}
static int F_63 ( void * V_14 , T_6 * V_44 )
{
struct V_15 * V_16 = V_14 ;
F_48 ( V_16 ) ;
* V_44 = V_16 -> V_80 ;
F_52 ( V_16 ) ;
return 0 ;
}
void F_64 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_16 -> V_6 ;
V_6 -> type = & V_81 ;
V_6 -> V_18 = V_19 ;
F_65 ( V_49 ) ;
F_12 ( V_6 ) ;
}
int F_66 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_16 -> V_6 ;
int V_82 ;
F_11 ( L_26 , V_16 , V_16 -> V_21 , V_16 -> V_24 ) ;
F_14 ( V_6 , L_27 , V_16 -> V_21 ) ;
V_82 = F_15 ( V_6 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( ! V_83 )
return 0 ;
V_16 -> V_84 = F_67 ( V_16 -> V_21 , V_83 ) ;
if ( ! V_16 -> V_84 )
return 0 ;
F_68 ( L_28 , 0444 , V_16 -> V_84 ,
V_16 , & V_85 ) ;
F_68 ( L_29 , 0444 , V_16 -> V_84 ,
V_16 , & V_86 ) ;
F_68 ( L_30 , 0444 , V_16 -> V_84 , V_16 , & V_87 ) ;
F_68 ( L_31 , 0444 , V_16 -> V_84 , V_16 ,
& V_88 ) ;
return 0 ;
}
void F_69 ( struct V_15 * V_16 )
{
F_11 ( L_26 , V_16 , V_16 -> V_21 , V_16 -> V_24 ) ;
F_70 ( V_16 -> V_84 ) ;
F_23 ( & V_16 -> V_6 ) ;
}
int T_7 F_71 ( void )
{
V_83 = F_67 ( L_32 , NULL ) ;
V_19 = F_72 ( V_49 , L_32 ) ;
return F_73 ( V_19 ) ;
}
void F_74 ( void )
{
F_75 ( V_19 ) ;
F_70 ( V_83 ) ;
}
