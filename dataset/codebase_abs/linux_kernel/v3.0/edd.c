static int
F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 < F_2 (unsigned char, edd.mbr_signature_nr, EDD_MBR_SIG_MAX) ;
}
static int
F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 < F_2 (unsigned char, edd.edd_info_nr, EDDMAXNR) ;
}
static inline struct V_4 *
F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_5 ;
}
static inline void
F_5 ( struct V_1 * V_2 , int V_6 )
{
V_2 -> V_3 = V_6 ;
if ( F_1 ( V_2 ) )
V_2 -> V_7 = V_8 . V_7 [ V_6 ] ;
if ( F_3 ( V_2 ) )
V_2 -> V_5 = & V_8 . V_4 [ V_6 ] ;
}
static T_1
F_6 ( struct V_9 * V_10 , struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_14 = F_7 ( V_10 ) ;
struct V_15 * V_16 = F_8 ( V_12 ) ;
T_1 V_17 = - V_18 ;
if ( V_16 -> V_19 )
V_17 = V_16 -> V_19 ( V_14 , V_13 ) ;
return V_17 ;
}
static T_1
F_9 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
int V_6 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( isprint ( V_5 -> V_22 . V_23 [ V_6 ] ) ) {
V_20 += F_10 ( V_20 , V_24 , L_1 , V_5 -> V_22 . V_23 [ V_6 ] ) ;
} else {
V_20 += F_10 ( V_20 , V_24 , L_2 ) ;
}
}
if ( ! strncmp ( V_5 -> V_22 . V_23 , L_3 , 3 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_4 ,
V_5 -> V_22 . V_25 . V_26 . V_27 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_23 , L_5 , 4 ) ||
! strncmp ( V_5 -> V_22 . V_23 , L_6 , 3 ) ) {
V_20 += F_10 ( V_20 , V_24 ,
L_7 ,
V_5 -> V_22 . V_25 . V_28 . V_29 ,
V_5 -> V_22 . V_25 . V_28 . V_30 ,
V_5 -> V_22 . V_25 . V_28 . V_31 ,
V_5 -> V_22 . V_25 . V_28 . V_32 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_23 , L_8 , 4 ) ||
! strncmp ( V_5 -> V_22 . V_23 , L_9 , 4 ) ||
! strncmp ( V_5 -> V_22 . V_23 , L_10 , 4 ) ) {
V_20 += F_10 ( V_20 , V_24 ,
L_11 ,
V_5 -> V_22 . V_25 . V_33 . V_34 ) ;
} else {
V_20 += F_10 ( V_20 , V_24 , L_12 ,
V_5 -> V_22 . V_25 . V_35 . V_34 ) ;
}
return ( V_20 - V_13 ) ;
}
static T_1
F_11 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
int V_6 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
if ( isprint ( V_5 -> V_22 . V_36 [ V_6 ] ) ) {
V_20 += F_10 ( V_20 , V_24 , L_1 , V_5 -> V_22 . V_36 [ V_6 ] ) ;
} else {
V_20 += F_10 ( V_20 , V_24 , L_2 ) ;
}
}
if ( ! strncmp ( V_5 -> V_22 . V_36 , L_13 , 5 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_14 ,
V_5 -> V_22 . V_37 . V_38 . V_39 ,
V_5 -> V_22 . V_37 . V_38 . V_40 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_15 , 3 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_16 ,
V_5 -> V_22 . V_37 . V_41 . V_39 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_17 , 4 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_18 ,
V_5 -> V_22 . V_37 . V_42 . V_43 ,
V_5 -> V_22 . V_37 . V_42 . V_40 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_19 , 3 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_20 ,
V_5 -> V_22 . V_37 . V_44 . V_45 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_21 , 4 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_22 ,
V_5 -> V_22 . V_37 . V_46 . V_47 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_23 , 5 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_24 ,
V_5 -> V_22 . V_37 . V_48 . V_49 ,
V_5 -> V_22 . V_37 . V_48 . V_40 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_25 , 3 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_26 ,
V_5 -> V_22 . V_37 . V_50 . V_51 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_27 , 4 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_28 ,
V_5 -> V_22 . V_37 . V_52 . V_53 ) ;
} else if ( ! strncmp ( V_5 -> V_22 . V_36 , L_29 , 4 ) ) {
V_20 += F_10 ( V_20 , V_24 , L_16 ,
V_5 -> V_22 . V_37 . V_54 . V_39 ) ;
} else {
V_20 += F_10 ( V_20 , V_24 , L_30 ,
V_5 -> V_22 . V_37 . V_35 . V_55 ,
V_5 -> V_22 . V_37 . V_35 . V_56 ) ;
}
return ( V_20 - V_13 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
T_1 V_57 = sizeof ( V_5 -> V_22 ) ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
if ( ! ( V_5 -> V_22 . V_58 == 0xBEDD || V_5 -> V_22 . V_58 == 0xDDBE ) )
V_57 = V_5 -> V_22 . V_59 ;
if ( V_57 > ( sizeof( V_5 -> V_22 ) ) )
V_57 = sizeof( V_5 -> V_22 ) ;
memcpy ( V_13 , & V_5 -> V_22 , V_57 ) ;
return V_57 ;
}
static T_1
F_13 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += F_10 ( V_20 , V_24 , L_31 , V_5 -> V_60 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 , char * V_13 )
{
char * V_20 = V_13 ;
V_20 += F_10 ( V_20 , V_24 , L_32 , V_2 -> V_7 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_15 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
if ( V_5 -> V_61 & V_62 ) {
V_20 += F_10 ( V_20 , V_24 , L_33 ) ;
}
if ( V_5 -> V_61 & V_63 ) {
V_20 += F_10 ( V_20 , V_24 , L_34 ) ;
}
if ( V_5 -> V_61 & V_64 ) {
V_20 += F_10 ( V_20 , V_24 , L_35 ) ;
}
if ( V_5 -> V_61 & V_65 ) {
V_20 += F_10 ( V_20 , V_24 , L_36 ) ;
}
return ( V_20 - V_13 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
if ( V_5 -> V_22 . V_66 & V_67 )
V_20 += F_10 ( V_20 , V_24 , L_37 ) ;
if ( V_5 -> V_22 . V_66 & V_68 )
V_20 += F_10 ( V_20 , V_24 , L_38 ) ;
if ( V_5 -> V_22 . V_66 & V_69 )
V_20 += F_10 ( V_20 , V_24 , L_39 ) ;
if ( V_5 -> V_22 . V_66 & V_70 )
V_20 += F_10 ( V_20 , V_24 , L_40 ) ;
if ( V_5 -> V_22 . V_66 & V_71 )
V_20 += F_10 ( V_20 , V_24 , L_41 ) ;
if ( V_5 -> V_22 . V_66 & V_72 )
V_20 += F_10 ( V_20 , V_24 , L_42 ) ;
if ( V_5 -> V_22 . V_66 & V_73 )
V_20 += F_10 ( V_20 , V_24 , L_43 ) ;
if ( V_5 -> V_22 . V_66 & V_74 )
V_20 += F_10 ( V_20 , V_24 , L_44 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_17 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += snprintf ( V_20 , V_24 , L_45 , V_5 -> V_75 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_18 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += snprintf ( V_20 , V_24 , L_45 , V_5 -> V_76 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_19 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += snprintf ( V_20 , V_24 , L_45 , V_5 -> V_77 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += F_10 ( V_20 , V_24 , L_45 , V_5 -> V_22 . V_78 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_21 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += F_10 ( V_20 , V_24 , L_45 , V_5 -> V_22 . V_79 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += F_10 ( V_20 , V_24 , L_45 , V_5 -> V_22 . V_80 ) ;
return ( V_20 - V_13 ) ;
}
static T_1
F_23 ( struct V_1 * V_2 , char * V_13 )
{
struct V_4 * V_5 ;
char * V_20 = V_13 ;
if ( ! V_2 )
return - V_21 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 || ! V_13 )
return - V_21 ;
V_20 += F_10 ( V_20 , V_24 , L_46 , V_5 -> V_22 . V_81 ) ;
return ( V_20 - V_13 ) ;
}
static int
F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_75 > 0 ;
}
static int
F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_76 > 0 ;
}
static int
F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_77 > 0 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_22 . V_78 > 0 ;
}
static int
F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_22 . V_79 > 0 ;
}
static int
F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return V_5 -> V_22 . V_80 > 0 ;
}
static int
F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_6 ;
T_2 V_82 = 0 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
if ( ! ( V_5 -> V_22 . V_58 == 0xBEDD || V_5 -> V_22 . V_58 == 0xDDBE ) ) {
return 0 ;
}
if ( V_5 -> V_22 . V_83 != 44 )
return 0 ;
for ( V_6 = 30 ; V_6 < V_5 -> V_22 . V_83 + 30 ; V_6 ++ )
V_82 += * ( ( ( T_2 * ) & V_5 -> V_22 ) + V_6 ) ;
if ( V_82 )
return 0 ;
return 1 ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_14 = F_7 ( V_10 ) ;
F_32 ( V_14 ) ;
}
static int
F_33 ( struct V_1 * V_2 , const char * type )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( type && V_5 ) {
if ( ! strncmp ( V_5 -> V_22 . V_23 , type , strlen ( type ) ) ||
! strncmp ( V_5 -> V_22 . V_36 , type , strlen ( type ) ) )
return 1 ;
}
return 0 ;
}
static struct V_84 *
F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( F_33 ( V_2 , L_6 ) ) {
return F_35 ( V_5 -> V_22 . V_25 . V_28 . V_29 ,
F_36 ( V_5 -> V_22 . V_25 . V_28 . V_30 ,
V_5 -> V_22 . V_25 . V_28 .
V_31 ) ) ;
}
return NULL ;
}
static int
F_37 ( struct V_1 * V_2 )
{
struct V_84 * V_84 = F_34 ( V_2 ) ;
int V_17 ;
if ( ! V_84 )
return 1 ;
V_17 = F_38 ( & V_2 -> V_10 , & V_84 -> V_14 . V_10 , L_47 ) ;
F_39 ( V_84 ) ;
return V_17 ;
}
static inline void
F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_10 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_15 * V_12 ;
int error = 0 ;
int V_6 ;
for ( V_6 = 0 ; ( V_12 = V_85 [ V_6 ] ) && ! error ; V_6 ++ ) {
if ( ! V_12 -> V_86 ||
( V_12 -> V_86 && V_12 -> V_86 ( V_2 ) ) )
error = F_43 ( & V_2 -> V_10 , & V_12 -> V_12 ) ;
}
if ( ! error ) {
F_37 ( V_2 ) ;
}
}
static int
F_44 ( struct V_1 * V_2 , int V_6 )
{
int error ;
if ( ! V_2 )
return 1 ;
F_5 ( V_2 , V_6 ) ;
V_2 -> V_10 . V_87 = V_88 ;
error = F_45 ( & V_2 -> V_10 , & V_89 , NULL ,
L_48 , 0x80 + V_6 ) ;
if ( ! error ) {
F_42 ( V_2 ) ;
F_46 ( & V_2 -> V_10 , V_90 ) ;
}
return error ;
}
static inline int F_47 ( void )
{
return F_48 (unsigned char,
min_t(unsigned char, EDD_MBR_SIG_MAX, edd.mbr_signature_nr),
min_t(unsigned char, EDDMAXNR, edd.edd_info_nr)) ;
}
static int T_3
F_49 ( void )
{
int V_6 ;
int V_91 = 0 ;
struct V_1 * V_2 ;
F_50 ( V_92 L_49 ,
V_93 , V_94 , F_47 () ) ;
if ( ! F_47 () ) {
F_50 ( V_92 L_50 ) ;
return - V_95 ;
}
V_88 = F_51 ( L_51 , NULL , V_96 ) ;
if ( ! V_88 )
return - V_97 ;
for ( V_6 = 0 ; V_6 < F_47 () ; V_6 ++ ) {
V_2 = F_52 ( sizeof ( * V_2 ) , V_98 ) ;
if ( ! V_2 ) {
V_91 = - V_97 ;
goto V_99;
}
V_91 = F_44 ( V_2 , V_6 ) ;
if ( V_91 ) {
F_32 ( V_2 ) ;
goto V_99;
}
V_100 [ V_6 ] = V_2 ;
}
return 0 ;
V_99:
while ( -- V_6 >= 0 )
F_40 ( V_100 [ V_6 ] ) ;
F_53 ( V_88 ) ;
return V_91 ;
}
static void T_4
F_54 ( void )
{
int V_6 ;
struct V_1 * V_2 ;
for ( V_6 = 0 ; V_6 < F_47 () ; V_6 ++ ) {
if ( ( V_2 = V_100 [ V_6 ] ) )
F_40 ( V_2 ) ;
}
F_53 ( V_88 ) ;
}
