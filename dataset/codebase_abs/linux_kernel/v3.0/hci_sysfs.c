static inline char * F_1 ( int type )
{
switch ( type ) {
case V_1 :
return L_1 ;
case V_2 :
return L_2 ;
case V_3 :
return L_3 ;
default:
return L_4 ;
}
}
static T_1 F_2 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_5 , F_1 ( V_10 -> type ) ) ;
}
static T_1 F_4 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_5 , F_5 ( & V_10 -> V_11 ) ) ;
}
static T_1 F_6 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_6 ,
V_10 -> V_12 [ 0 ] , V_10 -> V_12 [ 1 ] ,
V_10 -> V_12 [ 2 ] , V_10 -> V_12 [ 3 ] ,
V_10 -> V_12 [ 4 ] , V_10 -> V_12 [ 5 ] ,
V_10 -> V_12 [ 6 ] , V_10 -> V_12 [ 7 ] ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
void * V_13 = F_3 ( V_5 ) ;
F_8 ( V_13 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_10 ( V_15 , struct V_9 , V_16 ) ;
struct V_17 * V_18 = V_10 -> V_18 ;
F_11 ( & V_10 -> V_5 , L_7 , V_18 -> V_19 , V_10 -> V_20 ) ;
F_12 ( & V_10 -> V_5 , V_10 ) ;
if ( F_13 ( & V_10 -> V_5 ) < 0 ) {
F_14 ( L_8 ) ;
return;
}
F_15 ( V_18 ) ;
}
static int F_16 ( struct V_4 * V_5 , void * V_13 )
{
return ! strncmp ( F_17 ( V_5 ) , L_9 , 6 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_9 * V_10 = F_10 ( V_15 , struct V_9 , V_21 ) ;
struct V_17 * V_18 = V_10 -> V_18 ;
if ( ! F_19 ( & V_10 -> V_5 ) )
return;
while ( 1 ) {
struct V_4 * V_5 ;
V_5 = F_20 ( & V_10 -> V_5 , NULL , F_16 ) ;
if ( ! V_5 )
break;
F_21 ( V_5 , NULL , V_22 ) ;
F_22 ( V_5 ) ;
}
F_23 ( & V_10 -> V_5 ) ;
F_22 ( & V_10 -> V_5 ) ;
F_24 ( V_18 ) ;
}
void F_25 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = V_10 -> V_18 ;
F_26 ( L_10 , V_10 ) ;
V_10 -> V_5 . type = & V_23 ;
V_10 -> V_5 . V_24 = V_25 ;
V_10 -> V_5 . V_26 = & V_18 -> V_5 ;
F_27 ( & V_10 -> V_5 ) ;
F_28 ( & V_10 -> V_16 , F_9 ) ;
F_28 ( & V_10 -> V_21 , F_18 ) ;
}
void F_29 ( struct V_9 * V_10 )
{
F_26 ( L_10 , V_10 ) ;
F_30 ( V_10 -> V_18 -> V_27 , & V_10 -> V_16 ) ;
}
void F_31 ( struct V_9 * V_10 )
{
F_26 ( L_10 , V_10 ) ;
F_30 ( V_10 -> V_18 -> V_27 , & V_10 -> V_21 ) ;
}
static inline char * F_32 ( int V_28 )
{
switch ( V_28 ) {
case V_29 :
return L_11 ;
case V_30 :
return L_12 ;
case V_31 :
return L_13 ;
case V_32 :
return L_14 ;
case V_33 :
return L_15 ;
case V_34 :
return L_16 ;
case V_35 :
return L_17 ;
default:
return L_4 ;
}
}
static inline char * F_33 ( int type )
{
switch ( type ) {
case V_36 :
return L_18 ;
case V_37 :
return L_19 ;
default:
return L_4 ;
}
}
static T_1 F_34 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_5 , F_32 ( V_18 -> V_28 ) ) ;
}
static T_1 F_35 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_5 , F_33 ( V_18 -> V_38 ) ) ;
}
static T_1 F_36 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
char V_19 [ V_39 + 1 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
V_19 [ V_40 ] = V_18 -> F_17 [ V_40 ] ;
V_19 [ V_39 ] = '\0' ;
return sprintf ( V_8 , L_5 , V_19 ) ;
}
static T_1 F_37 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_20 ,
V_18 -> V_41 [ 2 ] , V_18 -> V_41 [ 1 ] , V_18 -> V_41 [ 0 ] ) ;
}
static T_1 F_38 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_5 , F_5 ( & V_18 -> V_42 ) ) ;
}
static T_1 F_39 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_6 ,
V_18 -> V_12 [ 0 ] , V_18 -> V_12 [ 1 ] ,
V_18 -> V_12 [ 2 ] , V_18 -> V_12 [ 3 ] ,
V_18 -> V_12 [ 4 ] , V_18 -> V_12 [ 5 ] ,
V_18 -> V_12 [ 6 ] , V_18 -> V_12 [ 7 ] ) ;
}
static T_1 F_40 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_21 , V_18 -> V_43 ) ;
}
static T_1 F_41 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_21 , V_18 -> V_44 ) ;
}
static T_1 F_42 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_21 , V_18 -> V_45 ) ;
}
static T_1 F_43 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_21 , V_18 -> V_46 ) ;
}
static T_1 F_44 ( struct V_4 * V_5 , struct V_6 * V_7 , const char * V_8 , T_2 V_47 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
unsigned int V_48 ;
int V_49 ;
V_49 = F_45 ( V_8 , 0 , & V_48 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_48 != 0 && ( V_48 < 500 || V_48 > 3600000 ) )
return - V_50 ;
V_18 -> V_46 = V_48 ;
return V_47 ;
}
static T_1 F_46 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_21 , V_18 -> V_51 ) ;
}
static T_1 F_47 ( struct V_4 * V_5 , struct V_6 * V_7 , const char * V_8 , T_2 V_47 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
T_3 V_48 ;
int V_49 ;
V_49 = F_48 ( V_8 , 0 , & V_48 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_48 == 0 || V_48 % 2 || V_48 < V_18 -> V_52 )
return - V_50 ;
V_18 -> V_51 = V_48 ;
return V_47 ;
}
static T_1 F_49 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_8 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_21 , V_18 -> V_52 ) ;
}
static T_1 F_50 ( struct V_4 * V_5 , struct V_6 * V_7 , const char * V_8 , T_2 V_47 )
{
struct V_17 * V_18 = F_3 ( V_5 ) ;
T_3 V_48 ;
int V_49 ;
V_49 = F_48 ( V_8 , 0 , & V_48 ) ;
if ( V_49 < 0 )
return V_49 ;
if ( V_48 == 0 || V_48 % 2 || V_48 > V_18 -> V_51 )
return - V_50 ;
V_18 -> V_52 = V_48 ;
return V_47 ;
}
static void F_51 ( struct V_4 * V_5 )
{
void * V_13 = F_3 ( V_5 ) ;
F_8 ( V_13 ) ;
}
static int F_52 ( struct V_53 * V_54 , void * V_55 )
{
struct V_17 * V_18 = V_54 -> V_56 ;
struct V_57 * V_58 = & V_18 -> V_59 ;
struct V_60 * V_61 ;
F_53 ( V_18 ) ;
for ( V_61 = V_58 -> V_62 ; V_61 ; V_61 = V_61 -> V_63 ) {
struct V_64 * V_13 = & V_61 -> V_13 ;
F_54 ( V_54 , L_22 ,
F_5 ( & V_13 -> V_42 ) ,
V_13 -> V_65 , V_13 -> V_66 ,
V_13 -> V_67 , V_13 -> V_41 [ 2 ] ,
V_13 -> V_41 [ 1 ] , V_13 -> V_41 [ 0 ] ,
F_55 ( V_13 -> V_68 ) ,
V_13 -> V_69 , V_13 -> V_70 , V_61 -> V_71 ) ;
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_57 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_58 ( V_73 , F_52 , V_72 -> V_74 ) ;
}
static int F_59 ( struct V_53 * V_54 , void * V_55 )
{
struct V_17 * V_18 = V_54 -> V_56 ;
struct V_75 * V_76 ;
F_53 ( V_18 ) ;
F_60 (l, &hdev->blacklist) {
struct V_77 * V_78 ;
V_78 = F_61 ( V_76 , struct V_77 , V_62 ) ;
F_54 ( V_54 , L_5 , F_5 ( & V_78 -> V_42 ) ) ;
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_62 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_58 ( V_73 , F_59 , V_72 -> V_74 ) ;
}
static void F_63 ( struct V_53 * V_54 , T_4 * V_79 )
{
T_5 V_80 , V_81 ;
T_3 V_82 , V_83 , V_84 , V_85 ;
memcpy ( & V_80 , & V_79 [ 0 ] , 4 ) ;
memcpy ( & V_82 , & V_79 [ 4 ] , 2 ) ;
memcpy ( & V_83 , & V_79 [ 6 ] , 2 ) ;
memcpy ( & V_84 , & V_79 [ 8 ] , 2 ) ;
memcpy ( & V_81 , & V_79 [ 10 ] , 4 ) ;
memcpy ( & V_85 , & V_79 [ 14 ] , 2 ) ;
F_54 ( V_54 , L_23 ,
F_64 ( V_80 ) , F_65 ( V_82 ) , F_65 ( V_83 ) ,
F_65 ( V_84 ) , F_64 ( V_81 ) , F_65 ( V_85 ) ) ;
}
static int F_66 ( struct V_53 * V_54 , void * V_55 )
{
struct V_17 * V_18 = V_54 -> V_56 ;
struct V_75 * V_76 ;
F_53 ( V_18 ) ;
F_60 (l, &hdev->uuids) {
struct V_86 * V_79 ;
V_79 = F_61 ( V_76 , struct V_86 , V_62 ) ;
F_63 ( V_54 , V_79 -> V_79 ) ;
}
F_56 ( V_18 ) ;
return 0 ;
}
static int F_67 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_58 ( V_73 , F_66 , V_72 -> V_74 ) ;
}
static int F_68 ( void * V_13 , T_6 V_48 )
{
struct V_17 * V_18 = V_13 ;
F_53 ( V_18 ) ;
V_18 -> V_87 = V_48 ;
F_56 ( V_18 ) ;
return 0 ;
}
static int F_69 ( void * V_13 , T_6 * V_48 )
{
struct V_17 * V_18 = V_13 ;
F_53 ( V_18 ) ;
* V_48 = V_18 -> V_87 ;
F_56 ( V_18 ) ;
return 0 ;
}
int F_70 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = & V_18 -> V_5 ;
int V_88 ;
F_26 ( L_24 , V_18 , V_18 -> V_19 , V_18 -> V_28 ) ;
V_5 -> type = & V_89 ;
V_5 -> V_24 = V_25 ;
V_5 -> V_26 = V_18 -> V_26 ;
F_11 ( V_5 , L_25 , V_18 -> V_19 ) ;
F_12 ( V_5 , V_18 ) ;
V_88 = F_71 ( V_5 ) ;
if ( V_88 < 0 )
return V_88 ;
if ( ! V_90 )
return 0 ;
V_18 -> V_91 = F_72 ( V_18 -> V_19 , V_90 ) ;
if ( ! V_18 -> V_91 )
return 0 ;
F_73 ( L_26 , 0444 , V_18 -> V_91 ,
V_18 , & V_92 ) ;
F_73 ( L_27 , 0444 , V_18 -> V_91 ,
V_18 , & V_93 ) ;
F_73 ( L_28 , 0444 , V_18 -> V_91 , V_18 , & V_94 ) ;
F_73 ( L_29 , 0444 , V_18 -> V_91 , V_18 ,
& V_95 ) ;
return 0 ;
}
void F_74 ( struct V_17 * V_18 )
{
F_26 ( L_24 , V_18 , V_18 -> V_19 , V_18 -> V_28 ) ;
F_75 ( V_18 -> V_91 ) ;
F_23 ( & V_18 -> V_5 ) ;
}
int T_7 F_76 ( void )
{
V_90 = F_72 ( L_30 , NULL ) ;
V_25 = F_77 ( V_96 , L_30 ) ;
if ( F_78 ( V_25 ) )
return F_79 ( V_25 ) ;
return 0 ;
}
void F_80 ( void )
{
F_81 ( V_25 ) ;
F_75 ( V_90 ) ;
}
