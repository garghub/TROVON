int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ 12 ] ;
V_6 = V_7 ;
V_4 = F_2 ( V_5 , 11 , V_1 -> V_8 ) ;
if ( V_4 != 11 ) {
* V_2 = F_3 ( V_1 -> V_8 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_9 )
return - 1 ;
return 0 ;
}
V_5 [ 11 ] = '\0' ;
if ( strcmp ( V_5 , L_1 ) == 0 ) {
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
}
else if ( strcmp ( V_5 , L_2 ) == 0 ) {
V_1 -> V_10 = V_18 ;
V_1 -> V_12 = V_19 ;
V_1 -> V_14 = V_20 ;
V_1 -> V_16 = V_21 ;
}
else {
return 0 ;
}
return 1 ;
}
static T_3
F_4 ( T_4 V_8 , struct V_22 * V_23 , T_5 * V_24 ,
int * V_2 , T_2 * * V_3 )
{
T_6 V_25 [ V_26 ] ;
int V_27 ;
T_7 V_28 ;
T_8 V_29 ;
V_27 = F_5 ( V_8 , V_25 , V_26 ,
V_2 , V_3 ) ;
if ( V_27 <= 0 ) {
return FALSE ;
}
V_28 . V_30 = V_25 [ 28 ] ;
V_23 -> V_31 = F_6 ( V_28 . V_30 ) ;
if ( V_23 -> V_31 == V_32 ) {
* V_2 = V_33 ;
* V_3 = F_7 ( L_3 ,
V_28 . V_30 ) ;
return FALSE ;
}
V_29 = F_8 ( & V_25 [ 0 ] ) ;
if ( V_29 < V_34 ) {
* V_2 = V_35 ;
* V_3 = F_7 ( L_4 ,
V_29 ) ;
return FALSE ;
}
V_29 -= V_34 ;
if ( V_23 -> V_31 == V_36 ) {
if ( V_29 < 3 ) {
* V_2 = V_35 ;
* V_3 = F_7 ( L_4 ,
V_29 + V_34 ) ;
return FALSE ;
}
V_29 -= 3 ;
if ( ! F_9 ( V_8 , 3 , V_2 ) )
return FALSE ;
}
if ( V_29 > V_37 ) {
* V_2 = V_35 ;
* V_3 = F_7 ( L_5 ,
V_29 , V_37 ) ;
return FALSE ;
}
V_23 -> V_38 = V_39 ;
V_23 -> V_40 = V_29 ;
V_23 -> V_41 = V_29 ;
V_23 -> V_42 . V_43 = F_8 ( & V_25 [ 4 ] ) ;
V_23 -> V_42 . V_44 = 0 ;
F_10 ( V_23 -> V_31 , & V_23 -> V_45 , V_25 ) ;
return F_11 ( V_8 , V_24 , V_23 , V_2 , V_3 ) ;
}
static T_3 V_13 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_9 * V_46 )
{
* V_46 = F_12 ( V_1 -> V_8 ) ;
if ( ! F_4 ( V_1 -> V_8 , & V_1 -> V_23 , V_1 -> V_47 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_48 == V_32 )
V_1 -> V_48 = V_1 -> V_23 . V_31 ;
else {
if ( V_1 -> V_48 != V_1 -> V_23 . V_31 )
V_1 -> V_48 = V_49 ;
}
return TRUE ;
}
static T_3 V_15 ( T_1 * V_1 , T_9 V_50 ,
struct V_22 * V_23 , T_5 * V_24 , int V_29 V_51 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_13 ( V_1 -> V_52 , V_50 , V_53 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_4 ( V_1 -> V_52 , V_23 , V_24 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_9 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_14 ( T_4 V_8 , struct V_22 * V_23 , T_5 * V_24 ,
int * V_2 , T_2 * * V_3 )
{
T_6 V_25 [ V_54 ] ;
int V_27 ;
T_10 V_28 ;
T_8 V_29 ;
V_27 = F_5 ( V_8 , V_25 , V_54 ,
V_2 , V_3 ) ;
if ( V_27 <= 0 ) {
return FALSE ;
}
V_28 . V_30 = V_25 [ 28 ] ;
V_23 -> V_31 = F_6 ( V_28 . V_30 ) ;
#if 0
if (phdr->pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
#endif
V_29 = F_8 ( & V_25 [ 0 ] ) ;
if ( V_29 < V_55 ) {
* V_2 = V_35 ;
* V_3 = F_7 ( L_4 ,
V_29 ) ;
return FALSE ;
}
V_29 -= V_55 ;
if ( V_23 -> V_31 == V_36 ) {
if ( V_29 < 3 ) {
* V_2 = V_35 ;
* V_3 = F_7 ( L_4 ,
V_29 + V_55 ) ;
return FALSE ;
}
V_29 -= 3 ;
if ( ! F_9 ( V_8 , 3 , V_2 ) )
return FALSE ;
}
if ( V_29 > V_37 ) {
* V_2 = V_35 ;
* V_3 = F_7 ( L_5 ,
V_29 , V_37 ) ;
return FALSE ;
}
V_23 -> V_38 = V_39 ;
V_23 -> V_40 = V_29 ;
V_23 -> V_41 = V_29 ;
V_23 -> V_42 . V_43 = F_8 ( & V_25 [ 32 ] ) ;
V_23 -> V_42 . V_44 = F_8 ( & V_25 [ 36 ] ) ;
F_10 ( V_23 -> V_31 , & V_23 -> V_45 , V_25 ) ;
return F_11 ( V_8 , V_24 , V_23 , V_2 , V_3 ) ;
}
static T_3 V_19 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_9 * V_46 )
{
* V_46 = F_12 ( V_1 -> V_8 ) ;
if ( ! F_14 ( V_1 -> V_8 , & V_1 -> V_23 , V_1 -> V_47 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_48 == V_32 )
V_1 -> V_48 = V_1 -> V_23 . V_31 ;
else {
if ( V_1 -> V_48 != V_1 -> V_23 . V_31 )
V_1 -> V_48 = V_49 ;
}
return TRUE ;
}
static T_3 V_20 ( T_1 * V_1 , T_9 V_50 ,
struct V_22 * V_23 , T_5 * V_24 , int V_29 V_51 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_13 ( V_1 -> V_52 , V_50 , V_53 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_14 ( V_1 -> V_52 , V_23 , V_24 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_9 ;
return FALSE ;
}
return TRUE ;
}
static int
F_5 ( T_4 V_8 , T_6 * V_25 , int V_56 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_6 = V_7 ;
V_4 = F_2 ( V_25 , V_56 , V_8 ) ;
if ( V_4 != V_56 ) {
* V_2 = F_3 ( V_8 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_9 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static T_3
F_11 ( T_4 V_8 , T_5 * V_24 , struct V_22 * V_23 ,
int * V_2 , T_2 * * V_3 )
{
if ( ! F_15 ( V_8 , V_24 , V_23 -> V_41 , V_2 , V_3 ) )
return FALSE ;
if ( V_23 -> V_31 == V_57 ) {
F_16 ( F_17 ( V_24 ) , V_23 -> V_41 ,
& V_23 -> V_45 ) ;
}
return TRUE ;
}
static void
F_10 ( int V_58 , union V_59 * V_45 ,
T_6 * V_25 )
{
char V_60 [ 9 ] ;
char * V_61 ;
int V_62 = 0 ;
int V_63 = 0 ;
switch ( V_58 ) {
case V_57 :
memcpy ( V_60 , & V_25 [ 20 ] , 8 ) ;
V_60 [ 8 ] = '\0' ;
V_61 = strchr ( V_60 , '.' ) ;
if ( V_61 ) {
* V_61 = '\0' ;
V_62 = ( int ) strtoul ( V_60 , NULL , 10 ) ;
V_61 ++ ;
V_63 = ( int ) strtoul ( V_61 , NULL , 10 ) ;
}
V_45 -> V_64 . V_65 = V_25 [ 29 ] ;
V_45 -> V_64 . V_66 = V_62 ;
V_45 -> V_64 . V_67 = V_63 ;
V_45 -> V_64 . V_68 = 0 ;
V_45 -> V_64 . V_69 = 0 ;
V_45 -> V_64 . V_70 = 0 ;
V_45 -> V_64 . V_71 = 0 ;
V_45 -> V_64 . V_72 = 0 ;
break;
case V_73 :
V_45 -> V_74 . V_75 = 0 ;
break;
}
}
static int
F_6 ( unsigned int V_76 )
{
static const int V_77 [] = {
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_78 ,
V_32 ,
V_73 ,
V_73 ,
V_32 ,
V_79 ,
V_32 ,
V_32 ,
V_78 ,
V_32 ,
V_32 ,
V_36 ,
V_80 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_78 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_32 ,
V_57 ,
} ;
#define F_18 (sizeof ift_encap / sizeof ift_encap[0])
if ( V_76 < F_18 ) {
return V_77 [ V_76 ] ;
}
else {
switch( V_76 ) {
case V_81 :
return V_82 ;
break;
case V_83 :
return V_78 ;
break;
default:
return V_32 ;
}
}
}
