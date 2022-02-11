int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ V_5 + 1 ] ;
V_6 = V_7 ;
if ( ! F_2 ( V_1 -> V_8 , V_4 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 != V_9 )
return - 1 ;
return 0 ;
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
return 0 ;
}
return 1 ;
}
static T_3
F_3 ( T_4 V_8 , struct V_22 * V_23 , T_5 * V_24 ,
int * V_2 , T_2 * * V_3 )
{
T_6 V_25 [ V_26 ] ;
T_7 V_27 ;
T_8 V_28 ;
V_6 = V_7 ;
if ( ! F_4 ( V_8 , V_25 , sizeof V_25 , V_2 , V_3 ) ) {
return FALSE ;
}
V_27 . V_29 = V_25 [ 28 ] ;
V_23 -> V_30 = F_5 ( V_27 . V_29 ) ;
if ( V_23 -> V_30 == V_31 ) {
* V_2 = V_32 ;
* V_3 = F_6 ( L_3 ,
V_27 . V_29 ) ;
return FALSE ;
}
V_28 = F_7 ( & V_25 [ 0 ] ) ;
if ( V_28 < V_33 ) {
* V_2 = V_34 ;
* V_3 = F_6 ( L_4 ,
V_28 ) ;
return FALSE ;
}
V_28 -= V_33 ;
if ( V_23 -> V_30 == V_35 ) {
if ( V_28 < 3 ) {
* V_2 = V_34 ;
* V_3 = F_6 ( L_4 ,
V_28 + V_33 ) ;
return FALSE ;
}
V_28 -= 3 ;
if ( ! F_8 ( V_8 , 3 , V_2 ) )
return FALSE ;
}
if ( V_28 > V_36 ) {
* V_2 = V_34 ;
* V_3 = F_6 ( L_5 ,
V_28 , V_36 ) ;
return FALSE ;
}
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_28 ;
V_23 -> V_42 = V_28 ;
V_23 -> V_43 . V_44 = F_7 ( & V_25 [ 4 ] ) ;
V_23 -> V_43 . V_45 = 0 ;
F_9 ( V_23 -> V_30 , & V_23 -> V_46 , V_25 ) ;
return F_10 ( V_8 , V_24 , V_23 , V_2 , V_3 ) ;
}
static T_3 V_13 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_9 * V_47 )
{
* V_47 = F_11 ( V_1 -> V_8 ) ;
if ( ! F_3 ( V_1 -> V_8 , & V_1 -> V_23 , V_1 -> V_48 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_49 == V_31 )
V_1 -> V_49 = V_1 -> V_23 . V_30 ;
else {
if ( V_1 -> V_49 != V_1 -> V_23 . V_30 )
V_1 -> V_49 = V_50 ;
}
return TRUE ;
}
static T_3 V_15 ( T_1 * V_1 , T_9 V_51 ,
struct V_22 * V_23 , T_5 * V_24 , int * V_2 , T_2 * * V_3 )
{
if ( F_12 ( V_1 -> V_52 , V_51 , V_53 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_3 ( V_1 -> V_52 , V_23 , V_24 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_9 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_13 ( T_4 V_8 , struct V_22 * V_23 , T_5 * V_24 ,
int * V_2 , T_2 * * V_3 )
{
T_6 V_25 [ V_54 ] ;
T_10 V_27 ;
T_8 V_28 ;
V_6 = V_7 ;
if ( ! F_4 ( V_8 , V_25 , sizeof V_25 , V_2 , V_3 ) ) {
return FALSE ;
}
V_27 . V_29 = V_25 [ 28 ] ;
V_23 -> V_30 = F_5 ( V_27 . V_29 ) ;
#if 0
if (phdr->pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("iptrace: interface type IFT=0x%02x unknown or unsupported",
pkt_hdr.if_type);
return FALSE;
}
#endif
V_28 = F_7 ( & V_25 [ 0 ] ) ;
if ( V_28 < V_55 ) {
* V_2 = V_34 ;
* V_3 = F_6 ( L_4 ,
V_28 ) ;
return FALSE ;
}
V_28 -= V_55 ;
if ( V_23 -> V_30 == V_35 ) {
if ( V_28 < 3 ) {
* V_2 = V_34 ;
* V_3 = F_6 ( L_4 ,
V_28 + V_55 ) ;
return FALSE ;
}
V_28 -= 3 ;
if ( ! F_8 ( V_8 , 3 , V_2 ) )
return FALSE ;
}
if ( V_28 > V_36 ) {
* V_2 = V_34 ;
* V_3 = F_6 ( L_5 ,
V_28 , V_36 ) ;
return FALSE ;
}
V_23 -> V_37 = V_38 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_28 ;
V_23 -> V_42 = V_28 ;
V_23 -> V_43 . V_44 = F_7 ( & V_25 [ 32 ] ) ;
V_23 -> V_43 . V_45 = F_7 ( & V_25 [ 36 ] ) ;
F_9 ( V_23 -> V_30 , & V_23 -> V_46 , V_25 ) ;
return F_10 ( V_8 , V_24 , V_23 , V_2 , V_3 ) ;
}
static T_3 V_19 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_9 * V_47 )
{
* V_47 = F_11 ( V_1 -> V_8 ) ;
if ( ! F_13 ( V_1 -> V_8 , & V_1 -> V_23 , V_1 -> V_48 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_49 == V_31 )
V_1 -> V_49 = V_1 -> V_23 . V_30 ;
else {
if ( V_1 -> V_49 != V_1 -> V_23 . V_30 )
V_1 -> V_49 = V_50 ;
}
return TRUE ;
}
static T_3 V_20 ( T_1 * V_1 , T_9 V_51 ,
struct V_22 * V_23 , T_5 * V_24 , int * V_2 , T_2 * * V_3 )
{
if ( F_12 ( V_1 -> V_52 , V_51 , V_53 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_1 -> V_52 , V_23 , V_24 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_9 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_10 ( T_4 V_8 , T_5 * V_24 , struct V_22 * V_23 ,
int * V_2 , T_2 * * V_3 )
{
if ( ! F_14 ( V_8 , V_24 , V_23 -> V_42 , V_2 , V_3 ) )
return FALSE ;
if ( V_23 -> V_30 == V_56 ) {
F_15 ( V_23 , F_16 ( V_24 ) ) ;
}
return TRUE ;
}
static void
F_9 ( int V_57 , union V_58 * V_46 ,
T_6 * V_25 )
{
char V_59 [ 9 ] ;
char * V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
switch ( V_57 ) {
case V_56 :
memcpy ( V_59 , & V_25 [ 20 ] , 8 ) ;
V_59 [ 8 ] = '\0' ;
V_60 = strchr ( V_59 , '.' ) ;
if ( V_60 ) {
* V_60 = '\0' ;
V_61 = ( int ) strtoul ( V_59 , NULL , 10 ) ;
V_60 ++ ;
V_62 = ( int ) strtoul ( V_60 , NULL , 10 ) ;
}
V_46 -> V_63 . V_64 = V_25 [ 29 ] ;
V_46 -> V_63 . V_65 = V_61 ;
V_46 -> V_63 . V_66 = V_62 ;
V_46 -> V_63 . V_67 = 0 ;
V_46 -> V_63 . V_68 = 0 ;
V_46 -> V_63 . V_69 = 0 ;
V_46 -> V_63 . V_70 = 0 ;
V_46 -> V_63 . V_71 = 0 ;
break;
case V_72 :
V_46 -> V_73 . V_74 = 0 ;
break;
}
}
static int
F_5 ( unsigned int V_75 )
{
static const int V_76 [] = {
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_77 ,
V_31 ,
V_72 ,
V_72 ,
V_31 ,
V_78 ,
V_31 ,
V_31 ,
V_77 ,
V_31 ,
V_31 ,
V_35 ,
V_79 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_77 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_31 ,
V_56 ,
} ;
#define F_17 (sizeof ift_encap / sizeof ift_encap[0])
if ( V_75 < F_17 ) {
return V_76 [ V_75 ] ;
}
else {
switch( V_75 ) {
case V_80 :
return V_81 ;
break;
case V_82 :
return V_77 ;
break;
default:
return V_31 ;
}
}
}
