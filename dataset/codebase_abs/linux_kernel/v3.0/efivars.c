static unsigned long
F_1 ( T_1 * V_1 , unsigned long V_2 )
{
unsigned long V_3 = 0 ;
while ( * V_1 ++ != 0 && V_3 < V_2 )
V_3 ++ ;
return V_3 ;
}
static inline unsigned long
F_2 ( T_1 * V_1 , unsigned long V_2 )
{
return F_1 ( V_1 , V_2 / sizeof( T_1 ) ) * sizeof( T_1 ) ;
}
static T_2
F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
T_2 V_7 ;
F_4 ( & V_4 -> V_8 ) ;
V_6 -> V_9 = 1024 ;
V_7 = V_4 -> V_10 -> V_11 ( V_6 -> V_12 ,
& V_6 -> V_13 ,
& V_6 -> V_14 ,
& V_6 -> V_9 ,
V_6 -> V_15 ) ;
F_5 ( & V_4 -> V_8 ) ;
if ( V_7 != V_16 ) {
F_6 ( V_17 L_1 ,
V_7 ) ;
}
return V_7 ;
}
static T_3
F_7 ( struct V_18 * V_19 , char * V_20 )
{
struct V_5 * V_6 = & V_19 -> V_6 ;
char * V_21 = V_20 ;
if ( ! V_19 || ! V_20 )
return 0 ;
F_8 ( & V_6 -> V_13 , V_21 ) ;
V_21 += strlen ( V_21 ) ;
V_21 += sprintf ( V_21 , L_2 ) ;
return V_21 - V_20 ;
}
static T_3
F_9 ( struct V_18 * V_19 , char * V_20 )
{
struct V_5 * V_6 = & V_19 -> V_6 ;
char * V_21 = V_20 ;
T_2 V_7 ;
if ( ! V_19 || ! V_20 )
return - V_22 ;
V_7 = F_3 ( V_19 -> V_4 , V_6 ) ;
if ( V_7 != V_16 )
return - V_23 ;
if ( V_6 -> V_14 & 0x1 )
V_21 += sprintf ( V_21 , L_3 ) ;
if ( V_6 -> V_14 & 0x2 )
V_21 += sprintf ( V_21 , L_4 ) ;
if ( V_6 -> V_14 & 0x4 )
V_21 += sprintf ( V_21 , L_5 ) ;
return V_21 - V_20 ;
}
static T_3
F_10 ( struct V_18 * V_19 , char * V_20 )
{
struct V_5 * V_6 = & V_19 -> V_6 ;
char * V_21 = V_20 ;
T_2 V_7 ;
if ( ! V_19 || ! V_20 )
return - V_22 ;
V_7 = F_3 ( V_19 -> V_4 , V_6 ) ;
if ( V_7 != V_16 )
return - V_23 ;
V_21 += sprintf ( V_21 , L_6 , V_6 -> V_9 ) ;
return V_21 - V_20 ;
}
static T_3
F_11 ( struct V_18 * V_19 , char * V_20 )
{
struct V_5 * V_6 = & V_19 -> V_6 ;
T_2 V_7 ;
if ( ! V_19 || ! V_20 )
return - V_22 ;
V_7 = F_3 ( V_19 -> V_4 , V_6 ) ;
if ( V_7 != V_16 )
return - V_23 ;
memcpy ( V_20 , V_6 -> V_15 , V_6 -> V_9 ) ;
return V_6 -> V_9 ;
}
static T_3
F_12 ( struct V_18 * V_19 , const char * V_20 , T_4 V_24 )
{
struct V_5 * V_25 , * V_6 = & V_19 -> V_6 ;
struct V_4 * V_4 = V_19 -> V_4 ;
T_2 V_7 = V_26 ;
if ( V_24 != sizeof( struct V_5 ) )
return - V_22 ;
V_25 = (struct V_5 * ) V_20 ;
if ( memcmp ( V_25 -> V_12 , V_6 -> V_12 , sizeof( V_6 -> V_12 ) ) ||
F_13 ( V_25 -> V_13 , V_6 -> V_13 ) ) {
F_6 ( V_27 L_7 ) ;
return - V_22 ;
}
if ( ( V_25 -> V_9 <= 0 ) || ( V_25 -> V_14 == 0 ) ) {
F_6 ( V_27 L_8 ) ;
return - V_22 ;
}
F_4 ( & V_4 -> V_8 ) ;
V_7 = V_4 -> V_10 -> V_28 ( V_25 -> V_12 ,
& V_25 -> V_13 ,
V_25 -> V_14 ,
V_25 -> V_9 ,
V_25 -> V_15 ) ;
F_5 ( & V_4 -> V_8 ) ;
if ( V_7 != V_16 ) {
F_6 ( V_17 L_9 ,
V_7 ) ;
return - V_23 ;
}
memcpy ( & V_19 -> V_6 , V_25 , V_24 ) ;
return V_24 ;
}
static T_3
F_14 ( struct V_18 * V_19 , char * V_20 )
{
struct V_5 * V_6 = & V_19 -> V_6 ;
T_2 V_7 ;
if ( ! V_19 || ! V_20 )
return 0 ;
V_7 = F_3 ( V_19 -> V_4 , V_6 ) ;
if ( V_7 != V_16 )
return - V_23 ;
memcpy ( V_20 , V_6 , sizeof( * V_6 ) ) ;
return sizeof( * V_6 ) ;
}
static T_3 F_15 ( struct V_29 * V_30 , struct V_31 * V_32 ,
char * V_20 )
{
struct V_18 * V_6 = F_16 ( V_30 ) ;
struct V_33 * V_34 = F_17 ( V_32 ) ;
T_3 V_35 = - V_23 ;
if ( ! F_18 ( V_36 ) )
return - V_37 ;
if ( V_34 -> V_38 ) {
V_35 = V_34 -> V_38 ( V_6 , V_20 ) ;
}
return V_35 ;
}
static T_3 F_19 ( struct V_29 * V_30 , struct V_31 * V_32 ,
const char * V_20 , T_4 V_24 )
{
struct V_18 * V_6 = F_16 ( V_30 ) ;
struct V_33 * V_34 = F_17 ( V_32 ) ;
T_3 V_35 = - V_23 ;
if ( ! F_18 ( V_36 ) )
return - V_37 ;
if ( V_34 -> V_39 )
V_35 = V_34 -> V_39 ( V_6 , V_20 , V_24 ) ;
return V_35 ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_18 * V_6 = F_21 ( V_30 , struct V_18 , V_30 ) ;
F_22 ( V_6 ) ;
}
static inline void
F_23 ( struct V_18 * V_6 )
{
F_24 ( & V_6 -> V_30 ) ;
}
static T_3 F_25 ( struct V_40 * V_41 , struct V_29 * V_30 ,
struct V_42 * V_43 ,
char * V_20 , T_5 V_44 , T_4 V_24 )
{
struct V_5 * V_25 = (struct V_5 * ) V_20 ;
struct V_4 * V_4 = V_43 -> V_45 ;
struct V_18 * V_46 , * V_47 ;
unsigned long V_48 , V_49 ;
T_2 V_7 = V_26 ;
int V_50 = 0 ;
if ( ! F_18 ( V_36 ) )
return - V_37 ;
F_4 ( & V_4 -> V_8 ) ;
F_26 (search_efivar, n, &efivars->list, list) {
V_48 = F_2 ( V_46 -> V_6 . V_12 , 1024 ) ;
V_49 = F_2 ( V_25 -> V_12 , 1024 ) ;
if ( V_48 == V_49 &&
! memcmp ( & ( V_46 -> V_6 . V_12 ) ,
V_25 -> V_12 , V_48 ) &&
! F_13 ( V_46 -> V_6 . V_13 ,
V_25 -> V_13 ) ) {
V_50 = 1 ;
break;
}
}
if ( V_50 ) {
F_5 ( & V_4 -> V_8 ) ;
return - V_22 ;
}
V_7 = V_4 -> V_10 -> V_28 ( V_25 -> V_12 ,
& V_25 -> V_13 ,
V_25 -> V_14 ,
V_25 -> V_9 ,
V_25 -> V_15 ) ;
if ( V_7 != V_16 ) {
F_6 ( V_17 L_9 ,
V_7 ) ;
F_5 ( & V_4 -> V_8 ) ;
return - V_23 ;
}
F_5 ( & V_4 -> V_8 ) ;
V_7 = F_27 ( V_4 ,
F_2 ( V_25 -> V_12 ,
1024 ) ,
V_25 -> V_12 ,
& V_25 -> V_13 ) ;
if ( V_7 ) {
F_6 ( V_17 L_10 ) ;
}
return V_24 ;
}
static T_3 F_28 ( struct V_40 * V_41 , struct V_29 * V_30 ,
struct V_42 * V_43 ,
char * V_20 , T_5 V_44 , T_4 V_24 )
{
struct V_5 * V_51 = (struct V_5 * ) V_20 ;
struct V_4 * V_4 = V_43 -> V_45 ;
struct V_18 * V_46 , * V_47 ;
unsigned long V_48 , V_49 ;
T_2 V_7 = V_26 ;
int V_50 = 0 ;
if ( ! F_18 ( V_36 ) )
return - V_37 ;
F_4 ( & V_4 -> V_8 ) ;
F_26 (search_efivar, n, &efivars->list, list) {
V_48 = F_2 ( V_46 -> V_6 . V_12 , 1024 ) ;
V_49 = F_2 ( V_51 -> V_12 , 1024 ) ;
if ( V_48 == V_49 &&
! memcmp ( & ( V_46 -> V_6 . V_12 ) ,
V_51 -> V_12 , V_48 ) &&
! F_13 ( V_46 -> V_6 . V_13 ,
V_51 -> V_13 ) ) {
V_50 = 1 ;
break;
}
}
if ( ! V_50 ) {
F_5 ( & V_4 -> V_8 ) ;
return - V_22 ;
}
V_51 -> V_14 = 0 ;
V_51 -> V_9 = 0 ;
V_7 = V_4 -> V_10 -> V_28 ( V_51 -> V_12 ,
& V_51 -> V_13 ,
V_51 -> V_14 ,
V_51 -> V_9 ,
V_51 -> V_15 ) ;
if ( V_7 != V_16 ) {
F_6 ( V_17 L_9 ,
V_7 ) ;
F_5 ( & V_4 -> V_8 ) ;
return - V_23 ;
}
F_29 ( & V_46 -> V_52 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_23 ( V_46 ) ;
return V_24 ;
}
static T_3 F_30 ( struct V_29 * V_30 ,
struct V_53 * V_32 , char * V_20 )
{
char * V_21 = V_20 ;
if ( ! V_30 || ! V_20 )
return - V_22 ;
if ( V_54 . V_55 != V_56 )
V_21 += sprintf ( V_21 , L_11 , V_54 . V_55 ) ;
if ( V_54 . V_57 != V_56 )
V_21 += sprintf ( V_21 , L_12 , V_54 . V_57 ) ;
if ( V_54 . V_58 != V_56 )
V_21 += sprintf ( V_21 , L_13 , V_54 . V_58 ) ;
if ( V_54 . V_59 != V_56 )
V_21 += sprintf ( V_21 , L_14 , V_54 . V_59 ) ;
if ( V_54 . V_60 != V_56 )
V_21 += sprintf ( V_21 , L_15 , V_54 . V_60 ) ;
if ( V_54 . V_61 != V_56 )
V_21 += sprintf ( V_21 , L_16 , V_54 . V_61 ) ;
if ( V_54 . V_62 != V_56 )
V_21 += sprintf ( V_21 , L_17 , V_54 . V_62 ) ;
return V_21 - V_20 ;
}
static int
F_27 ( struct V_4 * V_4 ,
unsigned long V_63 ,
T_1 * V_64 ,
T_6 * V_65 )
{
int V_66 , V_67 = V_63 / sizeof( T_1 ) + 38 ;
char * V_68 ;
struct V_18 * V_69 ;
V_68 = F_31 ( V_67 + 1 , V_70 ) ;
V_69 = F_31 ( sizeof( struct V_18 ) , V_70 ) ;
if ( ! V_68 || ! V_69 ) {
F_22 ( V_68 ) ;
F_22 ( V_69 ) ;
return 1 ;
}
V_69 -> V_4 = V_4 ;
memcpy ( V_69 -> V_6 . V_12 , V_64 ,
V_63 ) ;
memcpy ( & ( V_69 -> V_6 . V_13 ) , V_65 , sizeof( T_6 ) ) ;
for ( V_66 = 0 ; V_66 < ( int ) ( V_63 / sizeof( T_1 ) ) ; V_66 ++ ) {
V_68 [ V_66 ] = V_64 [ V_66 ] & 0xFF ;
}
* ( V_68 + strlen ( V_68 ) ) = '-' ;
F_8 ( V_65 , V_68 + strlen ( V_68 ) ) ;
V_69 -> V_30 . V_71 = V_4 -> V_71 ;
V_66 = F_32 ( & V_69 -> V_30 , & V_72 , NULL ,
L_18 , V_68 ) ;
if ( V_66 ) {
F_22 ( V_68 ) ;
F_22 ( V_69 ) ;
return 1 ;
}
F_33 ( & V_69 -> V_30 , V_73 ) ;
F_22 ( V_68 ) ;
V_68 = NULL ;
F_4 ( & V_4 -> V_8 ) ;
F_34 ( & V_69 -> V_52 , & V_4 -> V_52 ) ;
F_5 ( & V_4 -> V_8 ) ;
return 0 ;
}
static int
F_35 ( struct V_4 * V_4 )
{
struct V_42 * V_32 ;
int error ;
V_32 = F_31 ( sizeof( * V_32 ) , V_70 ) ;
if ( ! V_32 )
return - V_74 ;
V_32 -> V_32 . V_75 = L_19 ;
V_32 -> V_32 . V_76 = 0200 ;
V_32 -> V_77 = F_25 ;
V_32 -> V_45 = V_4 ;
V_4 -> V_25 = V_32 ;
V_32 = F_31 ( sizeof( * V_32 ) , V_70 ) ;
if ( ! V_32 ) {
error = - V_74 ;
goto V_78;
}
V_32 -> V_32 . V_75 = L_20 ;
V_32 -> V_32 . V_76 = 0200 ;
V_32 -> V_77 = F_28 ;
V_32 -> V_45 = V_4 ;
V_4 -> V_51 = V_32 ;
F_36 ( V_4 -> V_25 ) ;
F_36 ( V_4 -> V_51 ) ;
error = F_37 ( & V_4 -> V_71 -> V_30 ,
V_4 -> V_25 ) ;
if ( error ) {
F_6 ( V_27 L_21
L_22 , error ) ;
goto V_78;
}
error = F_37 ( & V_4 -> V_71 -> V_30 ,
V_4 -> V_51 ) ;
if ( error ) {
F_6 ( V_27 L_23
L_22 , error ) ;
F_38 ( & V_4 -> V_71 -> V_30 ,
V_4 -> V_25 ) ;
goto V_78;
}
return 0 ;
V_78:
F_22 ( V_4 -> V_51 ) ;
V_4 -> V_51 = NULL ;
F_22 ( V_4 -> V_25 ) ;
V_4 -> V_25 = NULL ;
return error ;
}
void F_39 ( struct V_4 * V_4 )
{
struct V_18 * V_19 , * V_47 ;
F_26 (entry, n, &efivars->list, list) {
F_4 ( & V_4 -> V_8 ) ;
F_29 ( & V_19 -> V_52 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_23 ( V_19 ) ;
}
if ( V_4 -> V_25 )
F_38 ( & V_4 -> V_71 -> V_30 , V_4 -> V_25 ) ;
if ( V_4 -> V_51 )
F_38 ( & V_4 -> V_71 -> V_30 , V_4 -> V_51 ) ;
F_22 ( V_4 -> V_25 ) ;
F_22 ( V_4 -> V_51 ) ;
F_40 ( V_4 -> V_71 ) ;
}
int F_41 ( struct V_4 * V_4 ,
const struct V_79 * V_10 ,
struct V_29 * V_80 )
{
T_2 V_7 = V_26 ;
T_6 V_65 ;
T_1 * V_64 ;
unsigned long V_63 = 1024 ;
int error = 0 ;
V_64 = F_31 ( V_63 , V_70 ) ;
if ( ! V_64 ) {
F_6 ( V_27 L_24 ) ;
return - V_74 ;
}
F_42 ( & V_4 -> V_8 ) ;
F_43 ( & V_4 -> V_52 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_71 = F_44 ( L_25 , NULL , V_80 ) ;
if ( ! V_4 -> V_71 ) {
F_6 ( V_27 L_26 ) ;
error = - V_74 ;
goto V_81;
}
do {
V_63 = 1024 ;
V_7 = V_10 -> V_82 ( & V_63 ,
V_64 ,
& V_65 ) ;
switch ( V_7 ) {
case V_16 :
F_27 ( V_4 ,
V_63 ,
V_64 ,
& V_65 ) ;
break;
case V_26 :
break;
default:
F_6 ( V_17 L_27 ,
V_7 ) ;
V_7 = V_26 ;
break;
}
} while ( V_7 != V_26 );
error = F_35 ( V_4 ) ;
if ( error )
F_39 ( V_4 ) ;
V_81:
F_22 ( V_64 ) ;
return error ;
}
static int T_7
F_45 ( void )
{
int error = 0 ;
F_6 ( V_83 L_28 , V_84 ,
V_85 ) ;
if ( ! V_86 )
return 0 ;
V_87 = F_46 ( L_29 , V_88 ) ;
if ( ! V_87 ) {
F_6 ( V_27 L_30 ) ;
return - V_74 ;
}
V_10 . V_11 = V_54 . V_11 ;
V_10 . V_28 = V_54 . V_28 ;
V_10 . V_82 = V_54 . V_82 ;
error = F_41 ( & V_89 , & V_10 , V_87 ) ;
if ( error )
goto V_90;
error = F_47 ( V_87 , & V_91 ) ;
if ( error ) {
F_6 ( V_27
L_31 ,
error ) ;
goto V_92;
}
return 0 ;
V_92:
F_39 ( & V_89 ) ;
V_90:
F_24 ( V_87 ) ;
return error ;
}
static void T_8
F_48 ( void )
{
if ( V_86 ) {
F_39 ( & V_89 ) ;
F_24 ( V_87 ) ;
}
}
