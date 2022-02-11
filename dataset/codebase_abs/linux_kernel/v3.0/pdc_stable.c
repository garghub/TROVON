static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return - V_5 ;
V_4 = & V_2 -> V_4 ;
F_2 ( L_1 , V_6 ,
V_2 , V_4 , V_2 -> V_7 ) ;
if ( F_3 ( V_2 -> V_7 , V_4 , sizeof( * V_4 ) ) != V_8 )
return - V_9 ;
V_2 -> V_10 = F_4 ( (struct V_11 * ) V_4 ) ;
V_2 -> V_12 = 1 ;
F_2 ( L_2 , V_6 , V_2 -> V_10 ) ;
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_6 ( ! V_2 ) ;
V_4 = & V_2 -> V_4 ;
if ( ! V_2 -> V_12 ) {
F_6 ( ! V_2 -> V_10 ) ;
F_7 ( V_2 -> V_10 , (struct V_11 * ) V_4 ) ;
}
F_2 ( L_3 , V_6 ,
V_2 , V_4 , V_2 -> V_7 ) ;
if ( F_8 ( V_2 -> V_7 , V_4 , sizeof( * V_4 ) ) != V_8 ) {
F_9 ( V_13 L_4
L_5
L_6 , V_6 ) ;
F_10 ( 1 ) ;
}
V_2 -> V_12 = 2 ;
F_2 ( L_2 , V_6 , V_2 -> V_10 ) ;
}
static T_1
F_11 ( struct V_1 * V_2 , char * V_14 )
{
char * V_15 = V_14 ;
struct V_3 * V_4 ;
short V_16 ;
if ( ! V_2 || ! V_14 )
return - V_5 ;
F_12 ( & V_2 -> V_17 ) ;
V_4 = & V_2 -> V_4 ;
V_16 = V_2 -> V_12 ;
F_13 ( & V_2 -> V_17 ) ;
if ( ! V_16 )
return - V_18 ;
for ( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
if ( V_4 -> V_19 [ V_16 ] >= 128 )
continue;
V_15 += sprintf ( V_15 , L_7 , ( unsigned char ) V_4 -> V_19 [ V_16 ] ) ;
}
V_15 += sprintf ( V_15 , L_8 , ( unsigned char ) V_4 -> V_20 ) ;
return V_15 - V_14 ;
}
static T_1
F_14 ( struct V_1 * V_2 , const char * V_14 , T_2 V_21 )
{
struct V_11 V_22 ;
unsigned short V_16 ;
char V_23 [ V_21 + 1 ] , * V_24 ;
struct V_25 * V_10 ;
int V_26 ;
if ( ! V_2 || ! V_14 || ! V_21 )
return - V_5 ;
memset ( V_23 , 0 , V_21 + 1 ) ;
strncpy ( V_23 , V_14 , V_21 ) ;
memset ( & V_22 , 0xff , sizeof( V_22 ) ) ;
if ( ! ( V_24 = strrchr ( V_23 , '/' ) ) )
return - V_5 ;
V_22 . V_20 = F_15 ( V_24 + 1 , NULL , 10 ) ;
V_23 [ V_24 - V_23 ] = '\0' ;
F_2 ( L_9 , V_6 , V_22 . V_20 ) ;
for ( V_16 = 5 ; ( ( V_24 = strrchr ( V_23 , '/' ) ) ) && ( V_24 - V_23 > 0 ) && ( F_16 ( V_16 ) ) ; V_16 -- ) {
V_22 . V_19 [ V_16 ] = F_15 ( V_24 + 1 , NULL , 10 ) ;
V_23 [ V_24 - V_23 ] = '\0' ;
F_2 ( L_10 , V_6 , V_16 , V_22 . V_19 [ V_16 ] ) ;
}
V_22 . V_19 [ V_16 ] = F_15 ( V_23 , NULL , 10 ) ;
F_2 ( L_10 , V_6 , V_16 , V_22 . V_19 [ V_16 ] ) ;
if ( ! ( V_10 = F_4 ( (struct V_11 * ) & V_22 ) ) ) {
F_9 ( V_27 L_11
L_12 , V_6 , V_2 -> V_28 , V_14 ) ;
return - V_5 ;
}
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_10 = V_10 ;
F_5 ( V_2 ) ;
F_18 ( & V_2 -> V_29 , L_13 ) ;
V_26 = F_19 ( & V_2 -> V_29 , & V_2 -> V_10 -> V_29 , L_13 ) ;
F_10 ( V_26 ) ;
F_20 ( & V_2 -> V_17 ) ;
F_9 (KERN_INFO PDCS_PREFIX L_14 ,
entry->name, buf) ;
return V_21 ;
}
static T_1
F_21 ( struct V_1 * V_2 , char * V_14 )
{
char * V_15 = V_14 ;
struct V_3 * V_4 ;
short V_16 ;
if ( ! V_2 || ! V_14 )
return - V_5 ;
F_12 ( & V_2 -> V_17 ) ;
V_4 = & V_2 -> V_4 ;
V_16 = V_2 -> V_12 ;
F_13 ( & V_2 -> V_17 ) ;
if ( ! V_16 )
return - V_18 ;
for ( V_16 = 0 ; V_16 < 6 && V_4 -> V_30 [ V_16 ] ; V_16 ++ )
V_15 += sprintf ( V_15 , L_15 , V_4 -> V_30 [ V_16 ] ) ;
V_15 += sprintf ( V_15 , L_16 ) ;
return V_15 - V_14 ;
}
static T_1
F_22 ( struct V_1 * V_2 , const char * V_14 , T_2 V_21 )
{
unsigned int V_30 [ 6 ] ;
unsigned short V_16 ;
char V_23 [ V_21 + 1 ] , * V_24 ;
if ( ! V_2 || ! V_14 || ! V_21 )
return - V_5 ;
memset ( V_23 , 0 , V_21 + 1 ) ;
strncpy ( V_23 , V_14 , V_21 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
if ( F_23 ( ! isdigit ( * V_23 ) ) )
return - V_5 ;
V_30 [ 0 ] = F_15 ( V_23 , NULL , 10 ) ;
F_2 ( L_17 , V_6 , V_30 [ 0 ] ) ;
V_24 = V_23 ;
for ( V_16 = 1 ; ( ( V_24 = strchr ( V_24 , '.' ) ) ) && ( F_16 ( V_16 < 6 ) ) ; V_16 ++ ) {
if ( F_23 ( ! isdigit ( * ( ++ V_24 ) ) ) )
return - V_5 ;
V_30 [ V_16 ] = F_15 ( V_24 , NULL , 10 ) ;
F_2 ( L_18 , V_6 , V_16 , V_30 [ V_16 ] ) ;
}
F_17 ( & V_2 -> V_17 ) ;
memcpy ( & V_2 -> V_4 . V_30 , & V_30 , sizeof( V_30 ) ) ;
F_5 ( V_2 ) ;
F_20 ( & V_2 -> V_17 ) ;
F_9 (KERN_INFO PDCS_PREFIX L_19 ,
entry->name, buf) ;
return V_21 ;
}
static T_1
F_24 ( struct V_31 * V_29 , struct V_32 * V_33 , char * V_14 )
{
struct V_1 * V_2 = F_25 ( V_29 ) ;
struct V_34 * V_35 = F_26 ( V_33 ) ;
T_1 V_26 = 0 ;
if ( V_35 -> V_36 )
V_26 = V_35 -> V_36 ( V_2 , V_14 ) ;
return V_26 ;
}
static T_1
F_27 ( struct V_31 * V_29 , struct V_32 * V_33 ,
const char * V_14 , T_2 V_21 )
{
struct V_1 * V_2 = F_25 ( V_29 ) ;
struct V_34 * V_35 = F_26 ( V_33 ) ;
T_1 V_26 = 0 ;
if ( ! F_28 ( V_37 ) )
return - V_38 ;
if ( V_35 -> V_39 )
V_26 = V_35 -> V_39 ( V_2 , V_14 , V_21 ) ;
return V_26 ;
}
static T_1 F_29 ( struct V_31 * V_29 ,
struct V_40 * V_33 ,
char * V_14 )
{
char * V_15 = V_14 ;
if ( ! V_14 )
return - V_5 ;
V_15 += sprintf ( V_15 , L_20 , V_41 ) ;
return V_15 - V_14 ;
}
static T_1 F_30 ( struct V_31 * V_29 ,
struct V_40 * V_33 ,
char * V_14 , int V_42 )
{
char * V_15 = V_14 ;
struct V_1 * V_43 ;
if ( ! V_14 )
return - V_5 ;
V_43 = & V_44 ;
F_12 ( & V_43 -> V_17 ) ;
V_15 += sprintf ( V_15 , L_21 , ( V_43 -> V_4 . V_45 & V_42 ) ?
L_22 : L_23 ) ;
F_13 ( & V_43 -> V_17 ) ;
return V_15 - V_14 ;
}
static T_1 F_31 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
return F_30 ( V_29 , V_33 , V_14 , V_46 ) ;
}
static T_1 F_32 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
return F_30 ( V_29 , V_33 , V_14 , V_47 ) ;
}
static T_1 F_33 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
char * V_15 = V_14 ;
struct V_1 * V_43 ;
if ( ! V_14 )
return - V_5 ;
V_43 = & V_44 ;
F_12 ( & V_43 -> V_17 ) ;
V_15 += sprintf ( V_15 , L_8 , ( V_43 -> V_4 . V_45 & V_48 ) ?
( 1 << ( V_43 -> V_4 . V_45 & V_48 ) ) : 0 ) ;
F_13 ( & V_43 -> V_17 ) ;
return V_15 - V_14 ;
}
static T_1 F_34 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
char * V_15 = V_14 ;
if ( ! V_14 )
return - V_5 ;
V_15 += sprintf ( V_15 , L_24 ,
F_35 ( V_49 ) , V_49 ) ;
return V_15 - V_14 ;
}
static T_1 F_36 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
char * V_15 = V_14 ;
T_3 V_50 [ 4 ] ;
if ( ! V_14 )
return - V_5 ;
if ( F_3 ( V_51 , & V_50 , sizeof( V_50 ) ) != V_8 )
return - V_9 ;
V_15 += sprintf ( V_15 , L_25 , V_50 [ 0 ] ) ;
V_15 += sprintf ( V_15 , L_25 , V_50 [ 1 ] ) ;
V_15 += sprintf ( V_15 , L_25 , V_50 [ 2 ] ) ;
V_15 += sprintf ( V_15 , L_25 , V_50 [ 3 ] ) ;
return V_15 - V_14 ;
}
static T_1 F_37 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
char * V_15 = V_14 ;
T_3 V_50 ;
if ( ! V_14 )
return - V_5 ;
if ( F_3 ( V_52 , & V_50 , sizeof( V_50 ) ) != V_8 )
return - V_9 ;
V_15 += sprintf ( V_15 , L_26 , ( V_50 >> 16 ) ) ;
return V_15 - V_14 ;
}
static T_1 F_38 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
char * V_15 = V_14 ;
T_3 V_50 ;
if ( ! V_14 )
return - V_5 ;
if ( F_3 ( V_53 , & V_50 , sizeof( V_50 ) ) != V_8 )
return - V_9 ;
if ( ( V_50 & 0x0F ) < 0x0E )
V_15 += sprintf ( V_15 , L_27 , ( 1 << ( V_50 & 0x0F ) ) * 256 ) ;
else
V_15 += sprintf ( V_15 , L_28 ) ;
V_15 += sprintf ( V_15 , L_16 ) ;
return V_15 - V_14 ;
}
static T_1 F_39 ( struct V_31 * V_29 ,
struct V_40 * V_33 , char * V_14 )
{
char * V_15 = V_14 ;
unsigned long V_54 ;
unsigned short V_16 ;
T_3 V_50 ;
if ( F_23 ( V_41 <= 224 ) )
return - V_18 ;
V_54 = V_41 - 224 ;
if ( ! V_14 )
return - V_5 ;
for ( V_16 = 0 ; V_16 < V_54 ; V_16 += 4 ) {
if ( F_23 ( F_3 ( V_55 + V_16 , & V_50 ,
sizeof( V_50 ) ) != V_8 ) )
return - V_9 ;
V_15 += sprintf ( V_15 , L_25 , V_50 ) ;
}
return V_15 - V_14 ;
}
static T_1 F_40 ( struct V_31 * V_29 ,
struct V_40 * V_33 , const char * V_14 ,
T_2 V_21 , int V_42 )
{
struct V_1 * V_43 ;
unsigned char V_45 ;
char V_23 [ V_21 + 1 ] , * V_24 ;
char V_56 ;
if ( ! F_28 ( V_37 ) )
return - V_38 ;
if ( ! V_14 || ! V_21 )
return - V_5 ;
memset ( V_23 , 0 , V_21 + 1 ) ;
strncpy ( V_23 , V_14 , V_21 ) ;
V_43 = & V_44 ;
F_12 ( & V_43 -> V_17 ) ;
V_45 = V_43 -> V_4 . V_45 ;
F_13 ( & V_43 -> V_17 ) ;
F_2 ( L_29 , V_6 , V_45 ) ;
V_24 = F_41 ( V_23 ) ;
V_56 = * V_24 ++ - '0' ;
if ( ( V_56 != 0 ) && ( V_56 != 1 ) )
goto V_57;
if ( V_56 == 0 )
V_45 &= ~ V_42 ;
else
V_45 |= V_42 ;
F_2 ( L_30 , V_6 , V_45 ) ;
F_17 ( & V_43 -> V_17 ) ;
V_43 -> V_4 . V_45 = V_45 ;
F_5 ( V_43 ) ;
F_20 ( & V_43 -> V_17 ) ;
F_9 (KERN_INFO PDCS_PREFIX L_31 ,
(knob & PF_AUTOBOOT) ? L_32 : L_33 ,
(flags & knob) ? L_22 : L_23 ) ;
return V_21 ;
V_57:
F_9 ( V_27 L_34 , V_6 ) ;
return - V_5 ;
}
static T_1 F_42 ( struct V_31 * V_29 ,
struct V_40 * V_33 ,
const char * V_14 , T_2 V_21 )
{
return F_40 ( V_29 , V_33 , V_14 , V_21 , V_46 ) ;
}
static T_1 F_43 ( struct V_31 * V_29 ,
struct V_40 * V_33 ,
const char * V_14 , T_2 V_21 )
{
return F_40 ( V_29 , V_33 , V_14 , V_21 , V_47 ) ;
}
static T_1 F_44 ( struct V_31 * V_29 ,
struct V_40 * V_33 ,
const char * V_14 , T_2 V_21 )
{
T_4 V_23 [ 16 ] ;
if ( ! F_28 ( V_37 ) )
return - V_38 ;
if ( ! V_14 || ! V_21 )
return - V_5 ;
if ( F_23 ( V_49 != V_58 ) )
return - V_59 ;
if ( V_21 > 16 )
return - V_60 ;
memset ( V_23 , 0 , 16 ) ;
memcpy ( V_23 , V_14 , V_21 ) ;
if ( F_8 ( V_51 , & V_23 , sizeof( V_23 ) ) != V_8 )
return - V_9 ;
return V_21 ;
}
static T_1 F_45 ( struct V_31 * V_29 ,
struct V_40 * V_33 ,
const char * V_14 , T_2 V_21 )
{
unsigned long V_54 ;
unsigned short V_16 ;
T_4 V_23 [ 4 ] ;
if ( ! F_28 ( V_37 ) )
return - V_38 ;
if ( ! V_14 || ! V_21 )
return - V_5 ;
if ( F_23 ( V_41 <= 224 ) )
return - V_61 ;
if ( F_23 ( V_49 != V_58 ) )
return - V_59 ;
V_54 = V_41 - 224 ;
if ( V_21 > V_54 )
return - V_60 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 += 4 ) {
memset ( V_23 , 0 , 4 ) ;
memcpy ( V_23 , V_14 + V_16 , ( V_21 - V_16 < 4 ) ? V_21 - V_16 : 4 ) ;
if ( F_23 ( F_8 ( V_55 + V_16 , & V_23 ,
sizeof( V_23 ) ) != V_8 ) )
return - V_9 ;
}
return V_21 ;
}
static inline int T_5
F_46 ( void )
{
unsigned short V_16 ;
struct V_1 * V_2 ;
int V_62 ;
for ( V_16 = 0 ; ( V_2 = V_63 [ V_16 ] ) ; V_16 ++ )
F_47 ( & V_2 -> V_17 ) ;
for ( V_16 = 0 ; ( V_2 = V_63 [ V_16 ] ) ; V_16 ++ ) {
F_17 ( & V_2 -> V_17 ) ;
V_62 = F_1 ( V_2 ) ;
F_20 ( & V_2 -> V_17 ) ;
if ( V_62 < 0 )
continue;
V_2 -> V_29 . V_64 = V_65 ;
V_62 = F_48 ( & V_2 -> V_29 , & V_66 , NULL ,
L_35 , V_2 -> V_28 ) ;
if ( V_62 )
return V_62 ;
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_12 = 2 ;
if ( V_2 -> V_10 ) {
V_62 = F_19 ( & V_2 -> V_29 , & V_2 -> V_10 -> V_29 , L_13 ) ;
F_10 ( V_62 ) ;
}
F_20 ( & V_2 -> V_17 ) ;
F_49 ( & V_2 -> V_29 , V_67 ) ;
}
return 0 ;
}
static inline void
F_50 ( void )
{
unsigned short V_16 ;
struct V_1 * V_2 ;
for ( V_16 = 0 ; ( V_2 = V_63 [ V_16 ] ) ; V_16 ++ ) {
F_12 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_12 >= 2 )
F_51 ( & V_2 -> V_29 ) ;
F_13 ( & V_2 -> V_17 ) ;
}
}
static int T_5
F_52 ( void )
{
int V_68 = 0 , error = 0 ;
T_3 V_50 ;
if ( F_53 ( & V_41 ) != V_8 )
return - V_69 ;
if ( V_41 < 96 )
return - V_18 ;
F_9 (KERN_INFO PDCS_PREFIX L_36 , PDCS_VERSION) ;
if ( F_3 ( V_70 , & V_50 , sizeof( V_50 ) ) != V_8 )
return - V_9 ;
V_49 = ( V_71 ) ( V_50 >> 16 ) ;
V_72 = F_54 ( L_37 , V_73 ) ;
if ( ! V_72 ) {
V_68 = - V_74 ;
goto V_75;
}
error = F_55 ( V_72 , & V_76 ) ;
V_65 = F_56 ( L_38 , NULL , V_72 ) ;
if ( ! V_65 ) {
V_68 = - V_74 ;
goto V_77;
}
if ( ( V_68 = F_46 () ) )
goto V_78;
return V_68 ;
V_78:
F_50 () ;
F_57 ( V_65 ) ;
V_77:
F_51 ( V_72 ) ;
V_75:
F_9 (KERN_INFO PDCS_PREFIX L_39 ) ;
return V_68 ;
}
static void T_6
F_58 ( void )
{
F_50 () ;
F_57 ( V_65 ) ;
F_51 ( V_72 ) ;
}
