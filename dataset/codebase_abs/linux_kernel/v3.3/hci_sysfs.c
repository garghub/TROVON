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
static int F_9 ( struct V_5 * V_6 , void * V_14 )
{
return ! strncmp ( F_10 ( V_6 ) , L_8 , 6 ) ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = V_11 -> V_16 ;
F_12 ( L_9 , V_11 ) ;
V_11 -> V_6 . type = & V_17 ;
V_11 -> V_6 . V_18 = V_19 ;
V_11 -> V_6 . V_20 = & V_16 -> V_6 ;
F_13 ( & V_11 -> V_6 ) ;
}
void F_14 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = V_11 -> V_16 ;
F_12 ( L_9 , V_11 ) ;
F_15 ( & V_11 -> V_6 , L_10 , V_16 -> V_21 , V_11 -> V_22 ) ;
F_16 ( & V_11 -> V_6 , V_11 ) ;
if ( F_17 ( & V_11 -> V_6 ) < 0 ) {
F_18 ( L_11 ) ;
return;
}
F_19 ( V_16 ) ;
}
void F_20 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = V_11 -> V_16 ;
if ( ! F_21 ( & V_11 -> V_6 ) )
return;
while ( 1 ) {
struct V_5 * V_6 ;
V_6 = F_22 ( & V_11 -> V_6 , NULL , F_9 ) ;
if ( ! V_6 )
break;
F_23 ( V_6 , NULL , V_23 ) ;
F_24 ( V_6 ) ;
}
F_25 ( & V_11 -> V_6 ) ;
F_24 ( & V_11 -> V_6 ) ;
F_26 ( V_16 ) ;
}
static inline char * F_27 ( int V_24 )
{
switch ( V_24 ) {
case V_25 :
return L_12 ;
case V_26 :
return L_13 ;
case V_27 :
return L_14 ;
case V_28 :
return L_15 ;
case V_29 :
return L_16 ;
case V_30 :
return L_17 ;
case V_31 :
return L_18 ;
default:
return L_5 ;
}
}
static inline char * F_28 ( int type )
{
switch ( type ) {
case V_32 :
return L_19 ;
case V_33 :
return L_20 ;
default:
return L_5 ;
}
}
static T_1 F_29 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_27 ( V_16 -> V_24 ) ) ;
}
static T_1 F_30 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_28 ( V_16 -> V_34 ) ) ;
}
static T_1 F_31 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
char V_21 [ V_35 + 1 ] ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
V_21 [ V_36 ] = V_16 -> F_10 [ V_36 ] ;
V_21 [ V_35 ] = '\0' ;
return sprintf ( V_9 , L_6 , V_21 ) ;
}
static T_1 F_32 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_21 ,
V_16 -> V_37 [ 2 ] , V_16 -> V_37 [ 1 ] , V_16 -> V_37 [ 0 ] ) ;
}
static T_1 F_33 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_5 ( & V_16 -> V_38 ) ) ;
}
static T_1 F_34 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_7 ,
V_16 -> V_13 [ 0 ] , V_16 -> V_13 [ 1 ] ,
V_16 -> V_13 [ 2 ] , V_16 -> V_13 [ 3 ] ,
V_16 -> V_13 [ 4 ] , V_16 -> V_13 [ 5 ] ,
V_16 -> V_13 [ 6 ] , V_16 -> V_13 [ 7 ] ) ;
}
static T_1 F_35 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_39 ) ;
}
static T_1 F_36 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_40 ) ;
}
static T_1 F_37 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_41 ) ;
}
static T_1 F_38 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_42 ) ;
}
static T_1 F_39 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 , T_2 V_43 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
unsigned int V_44 ;
int V_45 ;
V_45 = F_40 ( V_9 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_44 != 0 && ( V_44 < 500 || V_44 > 3600000 ) )
return - V_46 ;
V_16 -> V_42 = V_44 ;
return V_43 ;
}
static T_1 F_41 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_47 ) ;
}
static T_1 F_42 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 , T_2 V_43 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
T_3 V_44 ;
int V_45 ;
V_45 = F_43 ( V_9 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_44 == 0 || V_44 % 2 || V_44 < V_16 -> V_48 )
return - V_46 ;
V_16 -> V_47 = V_44 ;
return V_43 ;
}
static T_1 F_44 ( struct V_5 * V_6 , struct V_7 * V_8 , char * V_9 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_22 , V_16 -> V_48 ) ;
}
static T_1 F_45 ( struct V_5 * V_6 , struct V_7 * V_8 , const char * V_9 , T_2 V_43 )
{
struct V_15 * V_16 = F_3 ( V_6 ) ;
T_3 V_44 ;
int V_45 ;
V_45 = F_43 ( V_9 , 0 , & V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_44 == 0 || V_44 % 2 || V_44 > V_16 -> V_47 )
return - V_46 ;
V_16 -> V_48 = V_44 ;
return V_43 ;
}
static void F_46 ( struct V_5 * V_6 )
{
void * V_14 = F_3 ( V_6 ) ;
F_8 ( V_14 ) ;
}
static int F_47 ( struct V_49 * V_50 , void * V_51 )
{
struct V_15 * V_16 = V_50 -> V_52 ;
struct V_53 * V_54 = & V_16 -> V_55 ;
struct V_56 * V_57 ;
F_48 ( V_16 ) ;
for ( V_57 = V_54 -> V_58 ; V_57 ; V_57 = V_57 -> V_59 ) {
struct V_60 * V_14 = & V_57 -> V_14 ;
F_49 ( V_50 , L_23 ,
F_5 ( & V_14 -> V_38 ) ,
V_14 -> V_61 , V_14 -> V_62 ,
V_14 -> V_63 , V_14 -> V_37 [ 2 ] ,
V_14 -> V_37 [ 1 ] , V_14 -> V_37 [ 0 ] ,
F_50 ( V_14 -> V_64 ) ,
V_14 -> V_65 , V_14 -> V_66 , V_57 -> V_67 ) ;
}
F_51 ( V_16 ) ;
return 0 ;
}
static int F_52 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_53 ( V_69 , F_47 , V_68 -> V_70 ) ;
}
static int F_54 ( struct V_49 * V_50 , void * V_51 )
{
struct V_15 * V_16 = V_50 -> V_52 ;
struct V_71 * V_72 ;
F_48 ( V_16 ) ;
F_55 (b, &hdev->blacklist, list)
F_49 ( V_50 , L_6 , F_5 ( & V_72 -> V_38 ) ) ;
F_51 ( V_16 ) ;
return 0 ;
}
static int F_56 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_53 ( V_69 , F_54 , V_68 -> V_70 ) ;
}
static void F_57 ( struct V_49 * V_50 , T_4 * V_73 )
{
T_5 V_74 , V_75 ;
T_3 V_76 , V_77 , V_78 , V_79 ;
memcpy ( & V_74 , & V_73 [ 0 ] , 4 ) ;
memcpy ( & V_76 , & V_73 [ 4 ] , 2 ) ;
memcpy ( & V_77 , & V_73 [ 6 ] , 2 ) ;
memcpy ( & V_78 , & V_73 [ 8 ] , 2 ) ;
memcpy ( & V_75 , & V_73 [ 10 ] , 4 ) ;
memcpy ( & V_79 , & V_73 [ 14 ] , 2 ) ;
F_49 ( V_50 , L_24 ,
F_58 ( V_74 ) , F_59 ( V_76 ) , F_59 ( V_77 ) ,
F_59 ( V_78 ) , F_58 ( V_75 ) , F_59 ( V_79 ) ) ;
}
static int F_60 ( struct V_49 * V_50 , void * V_51 )
{
struct V_15 * V_16 = V_50 -> V_52 ;
struct V_80 * V_73 ;
F_48 ( V_16 ) ;
F_55 (uuid, &hdev->uuids, list)
F_57 ( V_50 , V_73 -> V_73 ) ;
F_51 ( V_16 ) ;
return 0 ;
}
static int F_61 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_53 ( V_69 , F_60 , V_68 -> V_70 ) ;
}
static int F_62 ( void * V_14 , T_6 V_44 )
{
struct V_15 * V_16 = V_14 ;
F_48 ( V_16 ) ;
V_16 -> V_81 = V_44 ;
F_51 ( V_16 ) ;
return 0 ;
}
static int F_63 ( void * V_14 , T_6 * V_44 )
{
struct V_15 * V_16 = V_14 ;
F_48 ( V_16 ) ;
* V_44 = V_16 -> V_81 ;
F_51 ( V_16 ) ;
return 0 ;
}
void F_64 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_16 -> V_6 ;
V_6 -> type = & V_82 ;
V_6 -> V_18 = V_19 ;
F_16 ( V_6 , V_16 ) ;
F_13 ( V_6 ) ;
}
int F_65 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_16 -> V_6 ;
int V_83 ;
F_12 ( L_25 , V_16 , V_16 -> V_21 , V_16 -> V_24 ) ;
V_6 -> V_20 = V_16 -> V_20 ;
F_15 ( V_6 , L_26 , V_16 -> V_21 ) ;
V_83 = F_17 ( V_6 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( ! V_84 )
return 0 ;
V_16 -> V_85 = F_66 ( V_16 -> V_21 , V_84 ) ;
if ( ! V_16 -> V_85 )
return 0 ;
F_67 ( L_27 , 0444 , V_16 -> V_85 ,
V_16 , & V_86 ) ;
F_67 ( L_28 , 0444 , V_16 -> V_85 ,
V_16 , & V_87 ) ;
F_67 ( L_29 , 0444 , V_16 -> V_85 , V_16 , & V_88 ) ;
F_67 ( L_30 , 0444 , V_16 -> V_85 , V_16 ,
& V_89 ) ;
return 0 ;
}
void F_68 ( struct V_15 * V_16 )
{
F_12 ( L_25 , V_16 , V_16 -> V_21 , V_16 -> V_24 ) ;
F_69 ( V_16 -> V_85 ) ;
F_25 ( & V_16 -> V_6 ) ;
}
int T_7 F_70 ( void )
{
V_84 = F_66 ( L_31 , NULL ) ;
V_19 = F_71 ( V_90 , L_31 ) ;
if ( F_72 ( V_19 ) )
return F_73 ( V_19 ) ;
return 0 ;
}
void F_74 ( void )
{
F_75 ( V_19 ) ;
F_69 ( V_84 ) ;
}
