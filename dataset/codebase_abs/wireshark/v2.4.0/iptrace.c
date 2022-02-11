T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ V_5 + 1 ] ;
if ( ! F_2 ( V_1 -> V_6 , V_4 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 != V_7 )
return V_8 ;
return V_9 ;
}
V_4 [ V_5 ] = '\0' ;
if ( strcmp ( V_4 , L_1 ) == 0 ) {
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
}
else if ( strcmp ( V_4 , L_2 ) == 0 ) {
V_1 -> V_10 = V_18 ;
V_1 -> V_12 = V_19 ;
V_1 -> V_14 = V_20 ;
V_1 -> V_16 = V_21 ;
}
else {
return V_9 ;
}
return V_22 ;
}
static T_4
F_3 ( T_5 V_6 , struct V_23 * V_24 , T_6 * V_25 ,
int * V_2 , T_3 * * V_3 )
{
T_7 V_26 [ V_27 ] ;
T_8 V_28 ;
T_9 V_29 ;
if ( ! F_4 ( V_6 , V_26 , sizeof V_26 , V_2 , V_3 ) ) {
return FALSE ;
}
V_28 . V_30 = V_26 [ 28 ] ;
V_24 -> V_31 = F_5 ( V_28 . V_30 ) ;
if ( V_24 -> V_31 == V_32 ) {
* V_2 = V_33 ;
* V_3 = F_6 ( L_3 ,
V_28 . V_30 ) ;
return FALSE ;
}
V_29 = F_7 ( & V_26 [ 0 ] ) ;
if ( V_29 < V_34 ) {
* V_2 = V_35 ;
* V_3 = F_6 ( L_4 ,
V_29 ) ;
return FALSE ;
}
V_29 -= V_34 ;
if ( V_24 -> V_31 == V_36 ) {
if ( V_29 < 3 ) {
* V_2 = V_35 ;
* V_3 = F_6 ( L_4 ,
V_29 + V_34 ) ;
return FALSE ;
}
V_29 -= 3 ;
if ( ! F_2 ( V_6 , NULL , 3 , V_2 , V_3 ) )
return FALSE ;
}
if ( V_29 > V_37 ) {
* V_2 = V_35 ;
* V_3 = F_6 ( L_5 ,
V_29 , V_37 ) ;
return FALSE ;
}
V_24 -> V_38 = V_39 ;
V_24 -> V_40 = V_41 ;
V_24 -> V_42 = V_29 ;
V_24 -> V_43 = V_29 ;
V_24 -> V_44 . V_45 = F_7 ( & V_26 [ 4 ] ) ;
V_24 -> V_44 . V_46 = 0 ;
F_8 ( V_24 -> V_31 , & V_24 -> V_47 , V_26 ) ;
return F_9 ( V_6 , V_25 , V_24 , V_2 , V_3 ) ;
}
static T_4 V_13 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_10 * V_48 )
{
* V_48 = F_10 ( V_1 -> V_6 ) ;
if ( ! F_3 ( V_1 -> V_6 , & V_1 -> V_24 , V_1 -> V_49 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_50 == V_32 )
V_1 -> V_50 = V_1 -> V_24 . V_31 ;
else {
if ( V_1 -> V_50 != V_1 -> V_24 . V_31 )
V_1 -> V_50 = V_51 ;
}
return TRUE ;
}
static T_4 V_15 ( T_2 * V_1 , T_10 V_52 ,
struct V_23 * V_24 , T_6 * V_25 , int * V_2 , T_3 * * V_3 )
{
if ( F_11 ( V_1 -> V_53 , V_52 , V_54 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_3 ( V_1 -> V_53 , V_24 , V_25 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_7 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_12 ( T_5 V_6 , struct V_23 * V_24 , T_6 * V_25 ,
int * V_2 , T_3 * * V_3 )
{
T_7 V_26 [ V_55 ] ;
T_11 V_28 ;
T_9 V_29 ;
if ( ! F_4 ( V_6 , V_26 , sizeof V_26 , V_2 , V_3 ) ) {
return FALSE ;
}
V_28 . V_30 = V_26 [ 28 ] ;
V_24 -> V_31 = F_5 ( V_28 . V_30 ) ;
#if 0
if (phdr->pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
#endif
V_29 = F_7 ( & V_26 [ 0 ] ) ;
if ( V_29 < V_56 ) {
* V_2 = V_35 ;
* V_3 = F_6 ( L_4 ,
V_29 ) ;
return FALSE ;
}
V_29 -= V_56 ;
if ( V_24 -> V_31 == V_36 ) {
if ( V_29 < 3 ) {
* V_2 = V_35 ;
* V_3 = F_6 ( L_4 ,
V_29 + V_56 ) ;
return FALSE ;
}
V_29 -= 3 ;
if ( ! F_2 ( V_6 , NULL , 3 , V_2 , V_3 ) )
return FALSE ;
}
if ( V_29 > V_37 ) {
* V_2 = V_35 ;
* V_3 = F_6 ( L_5 ,
V_29 , V_37 ) ;
return FALSE ;
}
V_24 -> V_38 = V_39 ;
V_24 -> V_40 = V_41 ;
V_24 -> V_42 = V_29 ;
V_24 -> V_43 = V_29 ;
V_24 -> V_44 . V_45 = F_7 ( & V_26 [ 32 ] ) ;
V_24 -> V_44 . V_46 = F_7 ( & V_26 [ 36 ] ) ;
F_8 ( V_24 -> V_31 , & V_24 -> V_47 , V_26 ) ;
return F_9 ( V_6 , V_25 , V_24 , V_2 , V_3 ) ;
}
static T_4 V_19 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_10 * V_48 )
{
* V_48 = F_10 ( V_1 -> V_6 ) ;
if ( ! F_12 ( V_1 -> V_6 , & V_1 -> V_24 , V_1 -> V_49 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_50 == V_32 )
V_1 -> V_50 = V_1 -> V_24 . V_31 ;
else {
if ( V_1 -> V_50 != V_1 -> V_24 . V_31 )
V_1 -> V_50 = V_51 ;
}
return TRUE ;
}
static T_4 V_20 ( T_2 * V_1 , T_10 V_52 ,
struct V_23 * V_24 , T_6 * V_25 , int * V_2 , T_3 * * V_3 )
{
if ( F_11 ( V_1 -> V_53 , V_52 , V_54 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_12 ( V_1 -> V_53 , V_24 , V_25 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_7 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_9 ( T_5 V_6 , T_6 * V_25 , struct V_23 * V_24 ,
int * V_2 , T_3 * * V_3 )
{
if ( ! F_13 ( V_6 , V_25 , V_24 -> V_43 , V_2 , V_3 ) )
return FALSE ;
if ( V_24 -> V_31 == V_57 ) {
F_14 ( V_24 , F_15 ( V_25 ) ) ;
}
return TRUE ;
}
static void
F_8 ( int V_58 , union V_59 * V_47 ,
T_7 * V_26 )
{
char V_60 [ 9 ] ;
char * V_61 ;
int V_62 = 0 ;
int V_63 = 0 ;
switch ( V_58 ) {
case V_57 :
memcpy ( V_60 , & V_26 [ 20 ] , 8 ) ;
V_60 [ 8 ] = '\0' ;
V_61 = strchr ( V_60 , '.' ) ;
if ( V_61 ) {
* V_61 = '\0' ;
V_62 = ( int ) strtoul ( V_60 , NULL , 10 ) ;
V_61 ++ ;
V_63 = ( int ) strtoul ( V_61 , NULL , 10 ) ;
}
V_47 -> V_64 . V_65 = V_26 [ 29 ] ;
V_47 -> V_64 . V_66 = V_62 ;
V_47 -> V_64 . V_67 = V_63 ;
V_47 -> V_64 . V_68 = 0 ;
V_47 -> V_64 . V_69 = 0 ;
V_47 -> V_64 . V_70 = 0 ;
V_47 -> V_64 . V_71 = 0 ;
V_47 -> V_64 . V_72 = 0 ;
break;
case V_73 :
V_47 -> V_74 . V_75 = 0 ;
break;
}
}
static int
F_5 ( unsigned int V_76 )
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
#define F_16 (sizeof ift_encap / sizeof ift_encap[0])
if ( V_76 < F_16 ) {
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
