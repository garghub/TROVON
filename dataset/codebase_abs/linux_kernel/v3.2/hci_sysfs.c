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
static T_1 F_2 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_1 ( V_11 -> type ) ) ;
}
static T_1 F_4 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_5 ( & V_11 -> V_12 ) ) ;
}
static T_1 F_6 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_7 ,
V_11 -> V_13 [ 0 ] , V_11 -> V_13 [ 1 ] ,
V_11 -> V_13 [ 2 ] , V_11 -> V_13 [ 3 ] ,
V_11 -> V_13 [ 4 ] , V_11 -> V_13 [ 5 ] ,
V_11 -> V_13 [ 6 ] , V_11 -> V_13 [ 7 ] ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
void * V_14 = F_3 ( V_6 ) ;
F_8 ( V_14 ) ;
}
static void F_9 ( struct V_15 * V_16 )
{
struct V_10 * V_11 = F_10 ( V_16 , struct V_10 , V_17 ) ;
struct V_18 * V_19 = V_11 -> V_19 ;
F_11 ( & V_11 -> V_6 , L_8 , V_19 -> V_20 , V_11 -> V_21 ) ;
F_12 ( & V_11 -> V_6 , V_11 ) ;
if ( F_13 ( & V_11 -> V_6 ) < 0 ) {
F_14 ( L_9 ) ;
return;
}
F_15 ( V_19 ) ;
}
static int F_16 ( struct V_5 * V_6 , void * V_14 )
{
return ! strncmp ( F_17 ( V_6 ) , L_10 , 6 ) ;
}
static void F_18 ( struct V_15 * V_16 )
{
struct V_10 * V_11 = F_10 ( V_16 , struct V_10 , V_22 ) ;
struct V_18 * V_19 = V_11 -> V_19 ;
if ( ! F_19 ( & V_11 -> V_6 ) )
return;
while ( 1 ) {
struct V_5 * V_6 ;
V_6 = F_20 ( & V_11 -> V_6 , NULL , F_16 ) ;
if ( ! V_6 )
break;
F_21 ( V_6 , NULL , V_23 ) ;
F_22 ( V_6 ) ;
}
F_23 ( & V_11 -> V_6 ) ;
F_22 ( & V_11 -> V_6 ) ;
F_24 ( V_19 ) ;
}
void F_25 ( struct V_10 * V_11 )
{
struct V_18 * V_19 = V_11 -> V_19 ;
F_26 ( L_11 , V_11 ) ;
V_11 -> V_6 . type = & V_24 ;
V_11 -> V_6 . V_25 = V_26 ;
V_11 -> V_6 . V_27 = & V_19 -> V_6 ;
F_27 ( & V_11 -> V_6 ) ;
F_28 ( & V_11 -> V_17 , F_9 ) ;
F_28 ( & V_11 -> V_22 , F_18 ) ;
}
void F_29 ( struct V_10 * V_11 )
{
F_26 ( L_11 , V_11 ) ;
F_30 ( V_11 -> V_19 -> V_28 , & V_11 -> V_17 ) ;
}
void F_31 ( struct V_10 * V_11 )
{
F_26 ( L_11 , V_11 ) ;
F_30 ( V_11 -> V_19 -> V_28 , & V_11 -> V_22 ) ;
}
static inline char * F_32 ( int V_29 )
{
switch ( V_29 ) {
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
case V_36 :
return L_18 ;
default:
return L_5 ;
}
}
static inline char * F_33 ( int type )
{
switch ( type ) {
case V_37 :
return L_19 ;
case V_38 :
return L_20 ;
default:
return L_5 ;
}
}
static T_1 F_34 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_32 ( V_19 -> V_29 ) ) ;
}
static T_1 F_35 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_33 ( V_19 -> V_39 ) ) ;
}
static T_1 F_36 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
char V_20 [ V_40 + 1 ] ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
V_20 [ V_41 ] = V_19 -> F_17 [ V_41 ] ;
V_20 [ V_40 ] = '\0' ;
return sprintf ( V_9 , L_6 , V_20 ) ;
}
static T_1 F_37 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_21 ,
V_19 -> V_42 [ 2 ] , V_19 -> V_42 [ 1 ] , V_19 -> V_42 [ 0 ] ) ;
}
static T_1 F_38 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_5 ( & V_19 -> V_43 ) ) ;
}
static T_1 F_39 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_7 ,
V_19 -> V_13 [ 0 ] , V_19 -> V_13 [ 1 ] ,
V_19 -> V_13 [ 2 ] , V_19 -> V_13 [ 3 ] ,
V_19 -> V_13 [ 4 ] , V_19 -> V_13 [ 5 ] ,
V_19 -> V_13 [ 6 ] , V_19 -> V_13 [ 7 ] ) ;
}
static T_1 F_40 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_19 -> V_44 ) ;
}
static T_1 F_41 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_19 -> V_45 ) ;
}
static T_1 F_42 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_19 -> V_46 ) ;
}
static T_1 F_43 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_19 -> V_47 ) ;
}
static T_1 F_44 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 , T_2 V_48 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
unsigned int V_49 ;
int V_50 ;
V_50 = F_45 ( V_9 , 0 , & V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_49 != 0 && ( V_49 < 500 || V_49 > 3600000 ) )
return - V_51 ;
V_19 -> V_47 = V_49 ;
return V_48 ;
}
static T_1 F_46 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_19 -> V_52 ) ;
}
static T_1 F_47 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 , T_2 V_48 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
T_3 V_49 ;
int V_50 ;
V_50 = F_48 ( V_9 , 0 , & V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_49 == 0 || V_49 % 2 || V_49 < V_19 -> V_53 )
return - V_51 ;
V_19 -> V_52 = V_49 ;
return V_48 ;
}
static T_1 F_49 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_19 -> V_53 ) ;
}
static T_1 F_50 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 , T_2 V_48 )
{
struct V_18 * V_19 = F_3 ( V_6 ) ;
T_3 V_49 ;
int V_50 ;
V_50 = F_48 ( V_9 , 0 , & V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_49 == 0 || V_49 % 2 || V_49 > V_19 -> V_52 )
return - V_51 ;
V_19 -> V_53 = V_49 ;
return V_48 ;
}
static void F_51 ( struct V_5 * V_6 )
{
void * V_14 = F_3 ( V_6 ) ;
F_8 ( V_14 ) ;
}
static int F_52 ( struct V_54 * V_55 , void * V_56 )
{
struct V_18 * V_19 = V_55 -> V_57 ;
struct V_58 * V_59 = & V_19 -> V_60 ;
struct V_61 * V_62 ;
F_53 ( V_19 ) ;
for ( V_62 = V_59 -> V_63 ; V_62 ; V_62 = V_62 -> V_64 ) {
struct V_65 * V_14 = & V_62 -> V_14 ;
F_54 ( V_55 , L_23 ,
F_5 ( & V_14 -> V_43 ) ,
V_14 -> V_66 , V_14 -> V_67 ,
V_14 -> V_68 , V_14 -> V_42 [ 2 ] ,
V_14 -> V_42 [ 1 ] , V_14 -> V_42 [ 0 ] ,
F_55 ( V_14 -> V_69 ) ,
V_14 -> V_70 , V_14 -> V_71 , V_62 -> V_72 ) ;
}
F_56 ( V_19 ) ;
return 0 ;
}
static int F_57 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
return F_58 ( V_74 , F_52 , V_73 -> V_75 ) ;
}
static int F_59 ( struct V_54 * V_55 , void * V_56 )
{
struct V_18 * V_19 = V_55 -> V_57 ;
struct V_76 * V_77 ;
F_53 ( V_19 ) ;
F_60 (l, &hdev->blacklist) {
struct V_78 * V_79 ;
V_79 = F_61 ( V_77 , struct V_78 , V_63 ) ;
F_54 ( V_55 , L_6 , F_5 ( & V_79 -> V_43 ) ) ;
}
F_56 ( V_19 ) ;
return 0 ;
}
static int F_62 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
return F_58 ( V_74 , F_59 , V_73 -> V_75 ) ;
}
static void F_63 ( struct V_54 * V_55 , T_4 * V_80 )
{
T_5 V_81 , V_82 ;
T_3 V_83 , V_84 , V_85 , V_86 ;
memcpy ( & V_81 , & V_80 [ 0 ] , 4 ) ;
memcpy ( & V_83 , & V_80 [ 4 ] , 2 ) ;
memcpy ( & V_84 , & V_80 [ 6 ] , 2 ) ;
memcpy ( & V_85 , & V_80 [ 8 ] , 2 ) ;
memcpy ( & V_82 , & V_80 [ 10 ] , 4 ) ;
memcpy ( & V_86 , & V_80 [ 14 ] , 2 ) ;
F_54 ( V_55 , L_24 ,
F_64 ( V_81 ) , F_65 ( V_83 ) , F_65 ( V_84 ) ,
F_65 ( V_85 ) , F_64 ( V_82 ) , F_65 ( V_86 ) ) ;
}
static int F_66 ( struct V_54 * V_55 , void * V_56 )
{
struct V_18 * V_19 = V_55 -> V_57 ;
struct V_76 * V_77 ;
F_53 ( V_19 ) ;
F_60 (l, &hdev->uuids) {
struct V_87 * V_80 ;
V_80 = F_61 ( V_77 , struct V_87 , V_63 ) ;
F_63 ( V_55 , V_80 -> V_80 ) ;
}
F_56 ( V_19 ) ;
return 0 ;
}
static int F_67 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
return F_58 ( V_74 , F_66 , V_73 -> V_75 ) ;
}
static int F_68 ( void * V_14 , T_6 V_49 )
{
struct V_18 * V_19 = V_14 ;
F_53 ( V_19 ) ;
V_19 -> V_88 = V_49 ;
F_56 ( V_19 ) ;
return 0 ;
}
static int F_69 ( void * V_14 , T_6 * V_49 )
{
struct V_18 * V_19 = V_14 ;
F_53 ( V_19 ) ;
* V_49 = V_19 -> V_88 ;
F_56 ( V_19 ) ;
return 0 ;
}
int F_70 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = & V_19 -> V_6 ;
int V_89 ;
F_26 ( L_25 , V_19 , V_19 -> V_20 , V_19 -> V_29 ) ;
V_6 -> type = & V_90 ;
V_6 -> V_25 = V_26 ;
V_6 -> V_27 = V_19 -> V_27 ;
F_11 ( V_6 , L_26 , V_19 -> V_20 ) ;
F_12 ( V_6 , V_19 ) ;
V_89 = F_71 ( V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( ! V_91 )
return 0 ;
V_19 -> V_92 = F_72 ( V_19 -> V_20 , V_91 ) ;
if ( ! V_19 -> V_92 )
return 0 ;
F_73 ( L_27 , 0444 , V_19 -> V_92 ,
V_19 , & V_93 ) ;
F_73 ( L_28 , 0444 , V_19 -> V_92 ,
V_19 , & V_94 ) ;
F_73 ( L_29 , 0444 , V_19 -> V_92 , V_19 , & V_95 ) ;
F_73 ( L_30 , 0444 , V_19 -> V_92 , V_19 ,
& V_96 ) ;
return 0 ;
}
void F_74 ( struct V_18 * V_19 )
{
F_26 ( L_25 , V_19 , V_19 -> V_20 , V_19 -> V_29 ) ;
F_75 ( V_19 -> V_92 ) ;
F_23 ( & V_19 -> V_6 ) ;
}
int T_7 F_76 ( void )
{
V_91 = F_72 ( L_31 , NULL ) ;
V_26 = F_77 ( V_97 , L_31 ) ;
if ( F_78 ( V_26 ) )
return F_79 ( V_26 ) ;
return 0 ;
}
void F_80 ( void )
{
F_81 ( V_26 ) ;
F_75 ( V_91 ) ;
}
