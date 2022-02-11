static int F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
int error ;
V_6 = F_2 () ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_8 . V_9 = & V_2 -> V_8 ;
V_4 ( V_6 ) ;
error = F_3 ( V_6 ) ;
if ( error ) {
F_4 ( V_6 ) ;
return error ;
}
F_5 ( & V_2 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_7 ( & V_2 -> V_8 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
static T_2 F_9 ( T_3 V_10 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x3 ;
V_12 [ 1 ] . type = V_16 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
return V_15 ;
}
static T_2 F_11 ( T_3 V_10 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x4 ;
V_12 [ 1 ] . type = V_16 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
return V_15 ;
}
static T_2 F_12 ( T_3 V_10 , int V_20 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x02 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_20 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
return F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
}
static T_2 F_13 ( T_3 V_10 ,
unsigned char * V_21 ,
unsigned char * V_22 ,
unsigned char * V_23 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
struct V_24 V_25 = { V_26 , 0 } ;
unsigned char * V_27 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x01 ;
V_12 [ 1 ] . type = V_16 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , & V_25 ) ;
if ( F_14 ( V_15 ) ) {
union V_11 * V_28 ;
V_28 = V_25 . V_19 ;
V_27 = V_28 -> V_29 . V_19 ;
* V_21 = V_27 [ 0 ] ;
* V_22 = V_27 [ 1 ] ;
* V_23 = V_27 [ 2 ] ;
F_15 ( V_25 . V_19 ) ;
}
return V_15 ;
}
static void F_16 ( struct V_1 * V_8 , T_4 V_30 )
{
if ( V_30 == 0x81 ) {
unsigned char V_21 , V_22 , V_23 ;
T_2 V_15 ;
V_15 = F_13 ( V_8 -> V_10 , & V_21 , & V_22 , & V_23 ) ;
if ( F_14 ( V_15 ) ) {
struct V_5 * V_6 = F_7 ( & V_8 -> V_8 ) ;
F_17 ( V_6 , V_31 , V_21 ) ;
F_17 ( V_6 , V_32 , V_22 ) ;
F_17 ( V_6 , V_33 , V_23 ) ;
F_18 ( V_6 ) ;
}
}
}
static T_5 F_19 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_2 = F_20 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
return sprintf ( V_37 , L_2 , V_39 -> V_40 ) ;
}
static T_5 F_21 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
const char * V_37 , T_6 V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
unsigned long V_40 ;
int V_41 ;
V_2 = F_20 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
V_41 = F_22 ( V_37 , 0 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_39 -> V_40 = V_40 ;
F_12 ( V_2 -> V_10 , V_40 ) ;
return F_23 ( V_37 , V_18 ) ;
}
static int F_24 ( struct V_5 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_14 -> V_8 . V_9 ) ;
if ( F_14 ( F_9 ( V_2 -> V_10 ) ) )
return 0 ;
return - V_42 ;
}
static void F_25 ( struct V_5 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_14 -> V_8 . V_9 ) ;
F_11 ( V_2 -> V_10 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
F_27 ( V_43 , V_6 -> V_44 ) ;
F_28 ( V_6 , V_31 , 0 , 255 , 8 , 0 ) ;
F_28 ( V_6 , V_32 , 0 , 255 , 8 , 0 ) ;
F_28 ( V_6 , V_33 , 0 , 255 , 8 , 0 ) ;
V_6 -> V_45 = F_24 ;
V_6 -> V_46 = F_25 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int error ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_39 = F_30 ( sizeof( * V_39 ) , V_47 ) ;
if ( ! V_39 )
return - V_7 ;
V_39 -> V_40 = V_48 ;
F_12 ( V_2 -> V_10 , V_39 -> V_40 ) ;
error = F_31 ( & V_2 -> V_8 , & V_49 ) ;
if ( error )
goto V_50;
error = F_1 ( V_2 , L_3 ,
F_26 ) ;
if ( error )
goto V_51;
V_6 = F_7 ( & V_2 -> V_8 ) ;
F_5 ( & V_6 -> V_8 , V_39 ) ;
return 0 ;
V_51:
F_32 ( & V_2 -> V_8 , & V_49 ) ;
V_50:
F_15 ( V_39 ) ;
return error ;
}
static int F_33 ( struct V_1 * V_2 , int type )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
F_32 ( & V_2 -> V_8 , & V_49 ) ;
return F_6 ( V_2 ) ;
}
static T_2 F_34 ( T_3 V_10 ,
unsigned long long * V_17 )
{
union V_11 V_12 ;
struct V_13 V_14 ;
unsigned long long V_25 ;
T_2 V_15 ;
V_12 . type = V_16 ;
V_12 . integer . V_17 = 0x01 ;
V_14 . V_18 = 1 ;
V_14 . V_19 = & V_12 ;
V_15 = F_35 ( V_10 , L_4 , & V_14 , & V_25 ) ;
if ( F_14 ( V_15 ) )
* V_17 = V_25 ;
return V_15 ;
}
static void F_36 ( struct V_1 * V_8 , T_4 V_30 )
{
unsigned long long V_20 = 0 ;
struct V_5 * V_6 = F_7 ( & V_8 -> V_8 ) ;
if ( V_30 == 0x81 ) {
if ( F_14 ( F_34 ( V_8 -> V_10 , & V_20 ) ) )
F_37 ( V_6 , V_52 , ! V_20 ) ;
}
}
static void F_38 ( struct V_5 * V_6 )
{
unsigned long long V_20 = 0 ;
struct V_1 * V_2 ;
F_27 ( V_53 , V_6 -> V_44 ) ;
F_27 ( V_52 , V_6 -> V_54 ) ;
V_2 = F_20 ( V_6 -> V_8 . V_9 ) ;
if ( F_14 ( F_34 ( V_2 -> V_10 , & V_20 ) ) )
F_37 ( V_6 , V_52 , ! V_20 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , L_5 ,
F_38 ) ;
}
static int F_40 ( struct V_1 * V_2 , int type )
{
return F_6 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_7 ( & V_2 -> V_8 ) ;
unsigned long long V_20 = 0 ;
if ( F_14 ( F_34 ( V_2 -> V_10 , & V_20 ) ) )
F_37 ( V_6 , V_52 , ! V_20 ) ;
return 0 ;
}
static T_2 F_42 ( T_3 V_10 ,
unsigned long long * V_17 )
{
union V_11 V_12 ;
struct V_13 V_14 ;
unsigned long long V_25 ;
T_2 V_15 ;
V_12 . type = V_16 ;
V_12 . integer . V_17 = 0xC0 ;
V_14 . V_18 = 1 ;
V_14 . V_19 = & V_12 ;
V_15 = F_35 ( V_10 , L_6 , & V_14 , & V_25 ) ;
if ( F_14 ( V_15 ) )
* V_17 = V_25 ;
return V_15 ;
}
static T_2 F_43 ( T_3 V_10 ,
unsigned long long V_17 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
unsigned long long V_25 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0xC0 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_17 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_35 ( V_10 , L_7 , & V_14 , & V_25 ) ;
return V_15 ;
}
static int F_44 ( struct V_55 * V_56 )
{
T_2 V_15 ;
T_3 V_10 ;
unsigned long long V_57 ;
V_10 = F_45 ( V_56 ) ;
V_15 = F_42 ( V_10 , & V_57 ) ;
if ( F_14 ( V_15 ) )
return V_57 ;
else
return - 1 ;
}
static int F_46 ( struct V_55 * V_56 )
{
T_2 V_15 ;
T_3 V_10 ;
V_10 = F_45 ( V_56 ) ;
V_15 = F_43 ( V_10 , V_56 -> V_58 . V_57 ) ;
if ( F_14 ( V_15 ) )
return 0 ;
else
return - 1 ;
}
static T_2 F_47 ( T_3 V_10 ,
unsigned long long * V_17 )
{
union V_11 V_12 ;
struct V_13 V_14 ;
unsigned long long V_25 ;
T_2 V_15 ;
V_12 . type = V_16 ;
V_12 . integer . V_17 = 0xC1 ;
V_14 . V_18 = 1 ;
V_14 . V_19 = & V_12 ;
V_15 = F_35 ( V_10 , L_6 , & V_14 , & V_25 ) ;
if ( F_14 ( V_15 ) )
* V_17 = V_25 ;
return V_15 ;
}
static T_2 F_48 ( T_3 V_10 ,
unsigned long long V_17 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
unsigned long long V_25 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0xC1 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_17 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_35 ( V_10 , L_7 , & V_14 , & V_25 ) ;
return V_15 ;
}
static void F_49 ( struct V_59 * V_59 , void * V_60 )
{
T_2 V_15 ;
T_3 V_10 ;
unsigned long long V_61 ;
bool V_62 ;
V_10 = V_60 ;
V_15 = F_47 ( V_10 , & V_61 ) ;
if ( F_14 ( V_15 ) ) {
V_62 = V_61 & 1 ? false : true ;
F_50 ( V_59 , V_62 ) ;
}
}
static int F_51 ( void * V_60 , bool V_62 )
{
T_2 V_15 ;
T_3 V_10 ;
unsigned long long V_61 ;
bool V_63 ;
V_10 = V_60 ;
V_15 = F_47 ( V_10 , & V_61 ) ;
if ( F_52 ( V_15 ) )
return - V_64 ;
V_63 = V_61 & 1 ? false : true ;
if ( V_63 != V_62 ) {
V_61 = V_62 ? 0 : 1 ;
V_15 = F_48 ( V_10 , V_61 ) ;
if ( F_52 ( V_15 ) )
return - V_64 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_65 ;
struct V_66 * V_67 ;
struct V_68 V_58 ;
V_67 = F_30 ( sizeof( * V_67 ) , V_47 ) ;
if ( V_67 == NULL )
return - V_7 ;
memset ( & V_58 , 0 , sizeof( struct V_68 ) ) ;
V_58 . type = V_69 ;
V_58 . V_70 = 7 ;
V_67 -> V_56 = F_54 ( L_8 , & V_2 -> V_8 ,
V_2 -> V_10 , & V_71 ,
& V_58 ) ;
if ( F_55 ( V_67 -> V_56 ) ) {
V_65 = F_56 ( V_67 -> V_56 ) ;
goto V_72;
}
V_67 -> V_73 = F_57 ( L_9 , & V_2 -> V_8 , V_74 ,
& V_75 , V_2 -> V_10 ) ;
if ( V_67 -> V_73 ) {
V_65 = F_58 ( V_67 -> V_73 ) ;
if ( V_65 ) {
F_59 ( V_67 -> V_73 ) ;
V_67 -> V_73 = NULL ;
}
}
F_5 ( & V_2 -> V_8 , V_67 ) ;
return 0 ;
V_72:
F_15 ( V_67 ) ;
return V_65 ;
}
static int F_60 ( struct V_1 * V_2 , int type )
{
struct V_66 * V_67 ;
V_67 = F_7 ( & V_2 -> V_8 ) ;
F_61 ( V_67 -> V_56 ) ;
if ( V_67 -> V_73 ) {
F_62 ( V_67 -> V_73 ) ;
F_59 ( V_67 -> V_73 ) ;
}
F_15 ( V_67 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_8 , T_4 V_30 )
{
struct V_5 * V_6 ;
int V_76 = V_77 ;
if ( ( V_30 & 0x0F ) < F_64 ( V_78 ) )
V_76 = V_78 [ V_30 & 0x0F ] ;
V_6 = F_7 ( & V_8 -> V_8 ) ;
F_65 ( V_6 , V_76 , ! ( V_30 & 0x10 ) ) ;
F_18 ( V_6 ) ;
}
static void F_66 ( struct V_5 * V_6 )
{
int V_79 ;
F_27 ( V_80 , V_6 -> V_44 ) ;
for ( V_79 = 0 ; V_78 [ V_79 ] != V_77 ; V_79 ++ )
F_27 ( V_78 [ V_79 ] , V_6 -> V_81 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , L_10 ,
F_66 ) ;
}
static int F_68 ( struct V_1 * V_2 , int type )
{
return F_6 ( V_2 ) ;
}
static int F_69 ( void )
{
int V_41 ;
V_41 = F_70 ( & V_82 ) ;
if ( V_41 )
goto V_83;
V_41 = F_70 ( & V_84 ) ;
if ( V_41 )
goto V_85;
V_41 = F_70 ( & V_86 ) ;
if ( V_41 )
goto V_87;
V_41 = F_70 ( & V_88 ) ;
if ( V_41 )
goto V_89;
return V_41 ;
V_89:
F_71 ( & V_86 ) ;
V_87:
F_71 ( & V_84 ) ;
V_85:
F_71 ( & V_82 ) ;
V_83:
return V_41 ;
}
static void F_72 ( void )
{
F_71 ( & V_88 ) ;
F_71 ( & V_86 ) ;
F_71 ( & V_84 ) ;
F_71 ( & V_82 ) ;
}
