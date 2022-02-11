static void F_1 ( const T_1 * V_1 , int V_2 , const char * V_3 , const char * V_4 )
{
int V_5 = 0 ;
F_2 ( L_1 , V_3 ) ;
for( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
{
F_2 ( L_2 , * ( V_1 + V_5 ) ) ;
}
F_2 ( L_3 , V_4 ) ;
}
static void F_1 ( const T_1 * V_1 V_6 , int V_2 V_6 , const char * V_3 V_6 , const char * V_4 V_6 ) {}
static T_2 F_3 ( T_3 * V_7 , T_2 V_8 , T_4 * T_5 V_6 ,
T_6 * V_9 , T_1 * V_10 ,
int V_11 , T_7 * V_12 )
{
T_7 V_13 ;
V_13 = ( ( V_10 [ 0 ] & V_14 )
? F_4 ( V_7 , V_8 )
: F_5 ( V_7 , V_8 ) ) ;
if ( V_9 ) {
F_6 ( V_9 , V_11 , V_7 , V_8 , 8 , V_15 ) ;
}
if ( V_12 )
* V_12 = V_13 ;
return V_8 + 8 ;
}
static T_2
F_7 ( T_8 V_16 , T_8 V_17 )
{
const T_9 * V_18 = ( const T_9 * ) V_16 ;
const T_9 * V_19 = ( const T_9 * ) V_17 ;
if( V_18 -> V_20 == NULL || V_19 -> V_20 == NULL )
return ( ( V_18 -> V_21 == V_19 -> V_21 ) && ( V_18 -> V_22 == V_19 -> V_22 ) && F_8 ( & V_18 -> V_23 , & V_19 -> V_23 ) &&
F_8 ( & V_18 -> V_24 , & V_19 -> V_24 ) ) ;
else
return ( ( strcmp ( V_18 -> V_20 , V_19 -> V_20 ) == 0 ) && F_8 ( & V_18 -> V_23 , & V_19 -> V_23 ) &&
F_8 ( & V_18 -> V_24 , & V_19 -> V_24 ) ) ;
}
static T_10
F_9 ( T_8 V_25 )
{
const T_9 * V_18 = ( const T_9 * ) V_25 ;
T_10 V_26 ;
if( V_18 -> V_20 == NULL ) {
V_26 = V_18 -> V_22 ;
V_26 += V_18 -> V_21 ;
}
else {
unsigned int V_5 = 0 ;
V_26 = 0 ;
for( V_5 = 0 ; V_18 -> V_20 [ V_5 ] ; V_5 ++ ) {
V_26 += V_18 -> V_20 [ V_5 ] ;
}
}
V_26 = F_10 ( V_26 , & V_18 -> V_23 ) ;
V_26 = F_10 ( V_26 , & V_18 -> V_24 ) ;
return V_26 ;
}
static int
F_11 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_30 [] = {
& V_31 ,
& V_32 ,
& V_33 ,
& V_34 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 ,
- 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_36 , V_37 , V_30 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_14 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 , int V_39 ,
T_13 * V_40 ,
void * V_41 )
{
T_14 V_42 , V_43 ;
V_44 ;
if ( V_28 -> V_35 )
return V_8 ;
#if 0
struct {
short len;
short size;
[size_is(size/2), length_is(len/2), ptr] unsigned short *string;
} HASH;
#endif
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_45 , & V_42 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_46 , & V_43 ) ;
V_8 = F_16 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_47 , V_48 ,
L_4 , V_39 , V_40 , V_41 ) ;
return V_8 ;
}
static int
F_17 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 , int V_39 , int T_15 V_6 ,
T_16 V_49 )
{
T_6 * V_50 = V_9 ;
if ( V_49 ) {
V_50 = F_18 (
V_9 , V_7 , V_8 , 0 , V_51 , NULL ,
F_19 ( V_39 ) ) ;
}
return F_14 (
V_7 , V_8 , T_5 , V_50 , V_28 , V_10 , V_39 ,
NULL , NULL ) ;
}
static int
F_20 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_52 [] = {
& V_53 ,
& V_54 ,
& V_55 ,
& V_56 ,
& V_57 ,
& V_58 ,
& V_59 ,
& V_60 ,
& V_61 ,
& V_62 ,
& V_63 ,
& V_64 ,
& V_65 ,
& V_66 ,
& V_67 ,
& V_68 ,
& V_69 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 ,
- 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_70 , V_71 , V_52 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_21 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_5 ,
V_72 , 0 ) ;
return V_8 ;
}
static int
F_23 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_6 ,
V_73 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_74 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_75 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_76 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_77 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_78 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_79 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_80 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_81 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_82 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_83 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_84 , NULL ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_7 , V_85 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_86 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_9 , V_87 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_25 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_10 , V_73 , V_90 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_11 , V_91 , 0 ) ;
return V_8 ;
}
static int
F_26 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_23 , V_48 ,
L_12 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_29 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_93 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_93 = F_30 ( V_7 , V_8 , F_31 ( V_10 ) ) ;
F_32 ( V_9 , V_94 , V_7 , V_8 , 4 , V_93 , L_13 ) ;
V_8 += 4 ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_95 , NULL ) ;
return V_8 ;
}
static int
F_33 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_10 , V_73 , V_90 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_11 , V_91 , 0 ) ;
return V_8 ;
}
static int
F_34 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_29 , V_89 ,
L_14 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_35 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_96 , NULL ) ;
return V_8 ;
}
static int
F_37 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_35 ) ;
return V_8 ;
}
static int
F_39 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_99 , & V_97 , L_15 ) ;
}
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_100 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_101 , NULL ) ;
V_8 = F_41 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_102 , NULL ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_73 , 1 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_91 , 0 ) ;
#ifdef F_42
V_8 = F_43 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
#endif
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_45 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 V_6 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
if( V_28 -> V_35 ) {
return V_8 ;
}
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 16 ,
V_51 , & V_97 , L_16 ) ;
}
F_6 ( V_9 , V_103 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_46 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 V_6 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
if( V_28 -> V_35 ) {
return V_8 ;
}
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 16 ,
V_104 , & V_97 , L_17 ) ;
}
F_6 ( V_9 , V_105 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_47 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_45 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_46 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_48 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 V_6 )
{
if( V_28 -> V_35 ) {
return V_8 ;
}
F_6 ( V_9 , V_106 , V_7 , V_8 , 8 ,
V_15 ) ;
V_8 += 8 ;
return V_8 ;
}
static int
F_49 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_48 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
#if 0
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "NT ",
hf_netlogon_nt_owf_password, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_data_length, NULL);
#endif
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_107 , 0 , TRUE ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_107 , 0 , TRUE ) ;
#if 0
offset = netlogon_dissect_LM_OWF_PASSWORD(tvb, offset,
pinfo, tree, di, drep);
offset = netlogon_dissect_NT_OWF_PASSWORD(tvb, offset,
pinfo, tree, di, drep);
#endif
return V_8 ;
#if 0
offset = dissect_ndr_counted_byte_array_cb(
tvb, offset, pinfo, tree, di, drep, hf_netlogon_nt_chal_resp,
dissect_nt_chal_resp_cb,GINT_TO_POINTER(2));
offset = dissect_ndr_counted_byte_array(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_lm_chal_resp, 0);
return offset;
#endif
}
static int
F_50 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_45 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_46 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_51 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_108 , 0 | V_109 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_110 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_89 ,
L_18 , - 1 ) ;
return V_8 ;
}
static int
F_52 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_14 V_111 = 0 ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_112 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_47 , V_48 ,
L_19 , - 1 ) ;
break;
case 2 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_49 , V_48 ,
L_20 , - 1 ) ;
break;
case 3 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_50 , V_48 ,
L_21 , - 1 ) ;
break;
case 4 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_51 , V_48 ,
L_22 , - 1 ) ;
break;
case 5 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_47 , V_48 ,
L_23 , - 1 ) ;
break;
case 6 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_49 , V_48 ,
L_24 , - 1 ) ;
break;
case 7 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_50 , V_48 ,
L_25 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_53 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 V_6 )
{
if( V_28 -> V_35 ) {
return V_8 ;
}
F_6 ( V_9 , V_113 , V_7 , V_8 , 8 ,
V_15 ) ;
V_8 += 8 ;
return V_8 ;
}
static int
F_54 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_18 V_114 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_53 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_44 ;
V_114 . V_115 = F_55 ( V_7 , V_8 ) ;
V_114 . V_116 = 0 ;
F_56 ( V_9 , V_117 , V_7 , V_8 , 4 , & V_114 ) ;
V_8 += 4 ;
return V_8 ;
}
static int
F_57 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_118 [] = {
& V_119 ,
& V_120 ,
& V_121 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 ,
- 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_122 , V_123 , V_118 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_58 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_124 , & V_97 , L_26 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_125 , NULL ) ;
V_8 = F_57 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_59 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_58 ) ;
return V_8 ;
}
static int
F_60 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 V_6 )
{
if( V_28 -> V_35 ) {
return V_8 ;
}
F_6 ( V_9 , V_126 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_61 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_127 [] = {
& V_128 ,
& V_129 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 ,
- 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_130 , V_131 , V_127 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_62 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_78 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_80 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_81 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_132 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_83 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_84 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_73 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_133 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_87 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_134 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_135 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_136 , 0 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_95 , NULL ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_137 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_125 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_139 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_59 , V_48 ,
L_27 , - 1 ) ;
V_8 = F_61 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_60 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_140 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_100 , 0 ) ;
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_141 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_142 , NULL ) ;
V_8 = F_20 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_143 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_144 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_145 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_146 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_147 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_148 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_149 , NULL ) ;
return V_8 ;
}
static int
F_65 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
#if 0
int i;
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, di, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, di, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, di, drep);
for(i=0;i<2;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_unknown_long, NULL);
}
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, di, drep);
for(i=0;i<7;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_unknown_long, NULL);
}
#endif
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_150 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_151 , V_48 ,
L_28 , - 1 ) ;
return V_8 ;
}
static int
F_66 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_65 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_152 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_153 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_154 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_155 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_156 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_157 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_158 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_159 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_160 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_161 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_162 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_163 , 0 ) ;
return V_8 ;
}
int
F_67 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_164 ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
#if 0
int i;
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, di, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, di, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, di, drep);
for(i=0;i<2;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_unknown_long, NULL);
}
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, di, drep);
for(i=0;i<7;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_unknown_long, NULL);
}
#endif
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_150 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_151 , V_48 ,
L_28 , - 1 ) ;
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_165 , & V_164 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_59 , V_48 ,
L_29 , - 1 ) ;
return V_8 ;
}
static int
F_68 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_166 , 1 ) ;
return V_8 ;
}
static int
F_69 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_68 ) ;
return V_8 ;
}
int
F_70 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_167 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_168 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_69 , V_48 ,
L_30 , - 1 ) ;
return V_8 ;
}
static int
F_71 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_110 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_89 ,
L_31 , - 1 ) ;
return V_8 ;
}
static int
F_72 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_14 V_111 = 0 ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_169 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_23 , V_48 ,
L_32 , - 1 ) ;
break;
case 2 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_62 , V_48 ,
L_33 , - 1 ) ;
break;
case 3 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_65 , V_48 ,
L_34 , - 1 ) ;
break;
case 4 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_71 , V_48 ,
L_35 , - 1 ) ;
break;
case 5 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_71 , V_48 ,
L_36 , - 1 ) ;
break;
case 6 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_66 , V_48 ,
L_37 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_73 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_112 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_52 , V_89 ,
L_41 , - 1 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_169 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_74 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_72 , V_89 ,
L_42 , - 1 ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_170 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_75 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_112 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_52 , V_89 ,
L_41 , - 1 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_169 , NULL ) ;
return V_8 ;
}
static int
F_76 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_72 , V_89 ,
L_42 , - 1 ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_170 , NULL ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_77 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_112 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_52 , V_89 ,
L_43 , - 1 ) ;
return V_8 ;
}
static int
F_78 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static void F_79 ( T_4 * T_5 , unsigned char V_172 , T_9 * V_173 , char * V_20 )
{
if( V_172 ) {
V_173 -> V_22 = T_5 -> V_21 ;
V_173 -> V_21 = T_5 -> V_174 ;
F_80 ( & V_173 -> V_24 , & T_5 -> V_23 ) ;
F_80 ( & V_173 -> V_23 , & T_5 -> V_24 ) ;
V_173 -> V_20 = V_20 ;
}
else {
F_80 ( & V_173 -> V_24 , & T_5 -> V_24 ) ;
F_80 ( & V_173 -> V_23 , & T_5 -> V_23 ) ;
V_173 -> V_22 = T_5 -> V_174 ;
V_173 -> V_21 = T_5 -> V_21 ;
V_173 -> V_20 = V_20 ;
}
}
static int
F_81 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
T_19 * V_175 ;
T_19 * V_176 ;
T_9 * V_173 ;
T_1 V_1 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_20 * V_177 = ( T_20 * ) V_28 -> V_178 ;
V_8 = F_21 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_16 (
V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_179 , V_89 ,
L_38 , V_85 ,
V_180 ,
F_82 ( V_90 | V_109 | 1 ) ) ;
F_2 ( L_44 , ( int ) strlen ( V_177 -> V_181 ) , V_8 , ( char * ) V_177 -> V_181 ) ;
V_175 = F_83 ( F_84 () , T_19 ) ;
V_175 -> V_182 = F_85 ( F_84 () , ( const T_1 * ) V_177 -> V_181 ) ;
F_2 ( L_45 , ( int ) strlen ( V_177 -> V_181 ) , V_8 , V_175 -> V_182 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_183 , & V_175 -> V_184 ) ;
memcpy ( V_1 , & V_175 -> V_184 , 8 ) ;
V_175 -> V_185 = T_5 -> V_186 ;
V_175 -> V_187 = - 1 ;
V_175 -> V_188 = NULL ;
V_173 = F_86 ( F_84 () , T_9 ) ;
F_79 ( T_5 , 0 , V_173 , NULL ) ;
V_176 = ( T_19 * ) F_87 ( V_189 , V_173 ) ;
if ( ! V_176 ) {
F_2 ( L_46 , V_175 -> V_185 ) ;
F_88 ( V_189 , V_173 , V_175 ) ;
}
else {
while( V_176 -> V_188 != NULL && V_176 -> V_185 < V_175 -> V_185 ) {
F_2 ( L_47 ) ;
V_176 = V_176 -> V_188 ;
}
if( V_176 -> V_188 != NULL || V_176 -> V_185 == V_175 -> V_185 ) {
F_2 ( L_48 , V_175 -> V_185 ) ;
}
else {
F_2 ( L_49 , V_175 -> V_185 ) ;
V_176 -> V_187 = T_5 -> V_186 ;
V_176 -> V_188 = V_175 ;
}
}
#if 0
generate_hash_key(pinfo,0,key,vars->client_name);
existing_vars = NULL;
existing_vars = g_hash_table_lookup(schannel_auths, key);
if (!existing_vars)
{
g_hash_table_insert(schannel_auths, key, vars);
}
else
{
while(existing_vars->next != NULL && existing_vars->start <= vars->start) {
existing_vars = existing_vars->next;
}
if(existing_vars->next != NULL || existing_vars == vars) {
debugprintf("It seems that I already record this vars (schannel hash)%d\n",vars->start);
}
else {
existing_vars->next_start = pinfo->num;
existing_vars->next = vars;
}
#endif
return V_8 ;
}
static int
F_89 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
T_19 * V_175 ;
T_9 V_173 ;
T_7 V_190 ;
F_79 ( T_5 , 1 , & V_173 , NULL ) ;
V_175 = ( T_19 * ) F_87 ( V_189 , ( T_8 * ) & V_173 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_191 , & V_190 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
if( V_175 != NULL ) {
while( V_175 != NULL && V_175 -> V_187 != - 1 && V_175 -> V_187 < ( int ) T_5 -> V_186 )
{
V_175 = V_175 -> V_188 ;
F_2 ( L_50 , V_175 -> V_187 , T_5 -> V_186 ) ;
}
if( V_175 == NULL )
{
F_2 ( L_51 ) ;
}
else
{
V_175 -> V_190 = V_190 ;
}
}
return V_8 ;
}
static int
F_90 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_192 , NULL ) ;
return V_8 ;
}
static int
F_91 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_52 , V_73 , V_90 ) ;
V_8 = F_90 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , V_90 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_53 , V_89 ,
L_53 , - 1 ) ;
return V_8 ;
}
static int
F_92 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_53 , V_89 ,
L_54 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_93 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 V_6 )
{
if( V_28 -> V_35 ) {
return V_8 ;
}
F_6 ( V_9 , V_193 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_94 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_52 , V_73 , 0 ) ;
V_8 = F_90 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_93 , V_89 ,
L_55 , - 1 ) ;
return V_8 ;
}
static int
F_95 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_96 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_56 , V_73 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_97 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_195 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_196 , & V_195 ) ;
F_6 ( V_9 , V_197 , V_7 , V_8 ,
V_195 , V_15 ) ;
V_8 += V_195 ;
return V_8 ;
}
static int
F_98 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_198 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_196 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_97 , V_48 ,
L_57 , - 1 ) ;
return V_8 ;
}
static int
F_99 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_73 , 3 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_133 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_125 , NULL ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_135 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_136 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_87 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_199 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_200 , 0 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_78 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_80 ) ;
V_8 = F_100 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_137 , NULL ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_95 , NULL ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_132 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_201 ) ;
V_8 = F_101 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_45 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_46 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_202 , NULL ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_203 , NULL ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_204 , NULL ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_205 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_206 , 0 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_207 , NULL ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_208 , NULL ) ;
V_8 = F_98 ( V_7 , V_8 , T_5 , V_9 ,
V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_103 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_86 , 3 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_210 , 0 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_81 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_211 , NULL ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_212 , NULL ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_84 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_83 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_213 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_214 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_104 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_215 , 3 ) ;
V_8 = F_58 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_216 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_105 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_28 -> V_39 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_28 -> V_39 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_106 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
return V_8 ;
}
static int
F_107 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_106 ) ;
return V_8 ;
}
static int
F_108 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_122 , NULL ) ;
return V_8 ;
}
static int
F_109 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_108 ) ;
return V_8 ;
}
static int
F_110 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_107 , V_48 ,
L_58 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_109 , V_48 ,
L_59 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_139 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_111 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_217 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_218 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_112 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_113 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_114 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_219 , NULL ) ;
return V_8 ;
}
static int
F_115 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_114 ) ;
return V_8 ;
}
static int
F_116 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_220 , & V_97 , L_60 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_221 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_222 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_223 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_224 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_225 , NULL ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_226 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_117 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_227 , NULL ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_228 ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_229 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_230 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_115 , V_48 ,
L_61 , - 1 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_86 , 0 ) ;
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_116 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_231 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_232 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_118 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_233 , 0 ) ;
return V_8 ;
}
static int
F_119 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_118 ) ;
return V_8 ;
}
static int
F_120 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_86 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_234 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_119 , V_48 ,
L_62 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_121 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_122 , NULL ) ;
return V_8 ;
}
static int
F_122 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_121 ) ;
return V_8 ;
}
static int
F_123 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_235 , 1 ) ;
return V_8 ;
}
static int
F_124 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_123 ) ;
return V_8 ;
}
static int
F_125 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_236 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_237 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_122 , V_48 ,
L_63 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_124 , V_48 ,
L_64 , - 1 ) ;
V_8 = F_116 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_238 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_126 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_195 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_239 , NULL ) ;
V_8 += 4 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_240 , & V_195 ) ;
F_6 ( V_9 , V_28 -> V_39 , V_7 , V_8 ,
V_195 , V_15 ) ;
V_8 += V_195 ;
return V_8 ;
}
static int
F_127 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 , const char * V_20 , int V_39 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_241 , & V_97 , V_20 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_240 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_239 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_126 , V_48 ,
V_20 , V_39 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_128 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_127 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ,
L_65 ,
V_242 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_243 ) ;
V_8 = F_127 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ,
L_66 ,
V_244 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_245 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_209 , NULL ) ;
V_8 = F_102 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_194 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_129 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_41 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_246 , NULL ) ;
return V_8 ;
}
static int
F_130 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
T_14 V_111 = 0 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_247 , & V_97 , L_67 ) ;
}
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_248 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_103 , V_48 ,
L_68 , - 1 ) ;
break;
case 2 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_104 , V_48 ,
L_69 , - 1 ) ;
break;
case 4 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_105 , V_48 ,
L_70 , V_215 ) ;
break;
case 5 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_99 , V_48 ,
L_71 , - 1 ) ;
break;
case 7 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_105 , V_48 ,
L_72 , V_73 ) ;
break;
case 8 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_110 , V_48 ,
L_73 , - 1 ) ;
break;
case 9 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_111 , V_48 ,
L_74 , - 1 ) ;
break;
case 11 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_105 , V_48 ,
L_75 , V_217 ) ;
break;
case 12 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_112 , V_48 ,
L_76 , - 1 ) ;
break;
case 13 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_117 , V_48 ,
L_77 , - 1 ) ;
break;
case 14 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_120 , V_48 ,
L_78 , - 1 ) ;
break;
case 16 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_125 , V_48 ,
L_79 , - 1 ) ;
break;
case 18 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_128 , V_48 ,
L_80 , - 1 ) ;
break;
case 20 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_96 , V_48 ,
L_81 , - 1 ) ;
break;
case 21 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_96 , V_48 ,
L_82 , - 1 ) ;
break;
case 22 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_129 , V_48 ,
L_83 , - 1 ) ;
break;
}
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_131 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
T_14 V_111 = 0 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_249 , & V_97 , L_84 ) ;
}
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_248 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_125 , NULL ) ;
break;
case 2 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 3 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 4 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 5 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 6 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 7 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 8 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 9 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 10 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 11 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 12 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 13 :
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
break;
case 14 :
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
break;
case 15 :
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
break;
case 16 :
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
break;
case 17 :
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
break;
case 18 :
V_8 = F_22 ( V_7 , V_8 , T_5 ,
V_9 , V_28 , V_10 , V_48 , L_85 ,
V_250 , 0 ) ;
break;
case 19 :
V_8 = F_22 ( V_7 , V_8 , T_5 ,
V_9 , V_28 , V_10 , V_48 , L_85 ,
V_250 , 0 ) ;
break;
case 20 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
case 21 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_138 , NULL ) ;
break;
}
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_132 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
T_14 type ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_251 , & V_97 , L_86 ) ;
}
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_248 , & type ) ;
F_133 ( V_97 , L_3 , F_134 (
type , V_252 , L_87 ) ) ;
V_8 = F_131 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_130 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_135 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_132 ) ;
return V_8 ;
}
static int
F_136 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_253 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_135 , V_48 ,
L_88 , - 1 ) ;
return V_8 ;
}
static int
F_137 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_72 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_254 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_129 , V_89 ,
L_89 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_255 , NULL ) ;
return V_8 ;
}
static int
F_138 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_129 , V_89 ,
L_89 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_136 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_139 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_72 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_254 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_256 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_255 , NULL ) ;
return V_8 ;
}
static int
F_140 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_256 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_136 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_141 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_257 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
F_6 ( V_9 , V_85 , V_7 , V_8 , 16 , V_258 | V_15 ) ;
V_8 += 16 ;
V_257 = F_30 ( V_7 , V_8 , F_31 ( V_10 ) ) ;
F_32 ( V_9 , V_259 , V_7 , V_8 , 4 , V_257 , L_13 ) ;
V_8 += 4 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_260 , NULL ) ;
return V_8 ;
}
static int
F_142 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_141 , V_89 ,
L_91 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_261 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_255 , NULL ) ;
return V_8 ;
}
static int
F_143 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_89 ,
L_92 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_261 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_263 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_141 , V_89 ,
L_91 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_144 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_264 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_255 , NULL ) ;
return V_8 ;
}
static int
F_145 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_89 ,
L_92 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_261 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_263 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_265 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_141 , V_89 ,
L_91 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_146 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_72 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_86 , 0 ) ;
return V_8 ;
}
static int
F_147 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_233 , 0 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_148 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_266 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_267 , NULL ) ;
return V_8 ;
}
static int
F_149 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_266 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_267 , NULL ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_93 ,
V_268 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_269 , NULL ) ;
return V_8 ;
}
static int
F_150 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_266 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_270 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_88 , NULL ) ;
return V_8 ;
}
static int
F_151 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_111 = 0 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_148 , V_48 ,
L_94 , - 1 ) ;
break;
case 2 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_149 , V_48 ,
L_95 , - 1 ) ;
break;
case 3 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_150 , V_48 ,
L_96 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_152 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_271 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , NULL ) ;
return V_8 ;
}
static int
F_153 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_151 , V_89 ,
L_97 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_154 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_5 ,
V_72 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_86 , 0 ) ;
return V_8 ;
}
static int
F_155 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_233 , 0 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_156 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_111 = 0 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 5 :
V_8 = F_22 ( V_7 , V_8 , T_5 ,
V_9 , V_28 , V_10 , V_48 , L_98 ,
V_272 , 0 ) ;
break;
case 6 :
V_8 = F_22 ( V_7 , V_8 , T_5 ,
V_9 , V_28 , V_10 , V_48 , L_98 ,
V_272 , 0 ) ;
break;
case 0xfffe :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
break;
case 8 :
V_8 = F_22 ( V_7 , V_8 , T_5 ,
V_9 , V_28 , V_10 , V_48 , L_99 ,
V_274 , 0 ) ;
break;
}
return V_8 ;
}
static int
F_157 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_271 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_156 , V_89 ,
L_100 , - 1 ) ;
return V_8 ;
}
static int
F_158 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_275 ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_151 , V_89 ,
L_97 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_276 , & V_275 ) ;
if ( V_275 != 0 )
F_159 ( T_5 -> V_277 , V_278 , L_101 , F_160 ( V_275 , & V_279 , L_102 ) ) ;
return V_8 ;
}
static int
F_161 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_72 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_254 , NULL ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_280 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_256 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_255 , NULL ) ;
return V_8 ;
}
static int
F_162 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_256 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_136 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_163 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_72 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_89 ,
L_103 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_227 , NULL ) ;
return V_8 ;
}
static int
F_164 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_136 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_165 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_271 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_156 , V_89 ,
L_100 , - 1 ) ;
return V_8 ;
}
static int
F_166 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_151 , V_89 ,
L_97 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_167 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_127 [] = {
& V_281 ,
& V_282 ,
& V_283 ,
& V_284 ,
& V_285 ,
& V_286 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 ,
- 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_287 , V_37 , V_127 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_168 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_118 [] = {
& V_288 ,
& V_289 ,
& V_290 ,
& V_291 ,
& V_292 ,
& V_293 ,
& V_294 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 ,
- 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_295 , V_296 , V_118 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_169 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
static const int * V_127 [] = {
& V_297 ,
& V_298 ,
& V_299 ,
& V_300 ,
& V_301 ,
& V_302 ,
& V_303 ,
& V_304 ,
& V_305 ,
& V_306 ,
& V_307 ,
& V_308 ,
& V_309 ,
& V_310 ,
& V_311 ,
& V_312 ,
& V_313 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 , - 1 , & V_29 ) ;
F_13 ( V_27 , V_7 , V_8 - 4 , V_314 , V_315 , V_127 , V_29 , V_38 ) ;
return V_8 ;
}
static int
F_170 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_29 ;
T_17 * V_97 ;
static const int * V_127 [] = {
& V_316 ,
& V_317 ,
& V_318 ,
& V_319 ,
& V_320 ,
& V_321 ,
& V_322 ,
& V_323 ,
& V_324 ,
& V_325 ,
& V_326 ,
& V_327 ,
& V_328 ,
NULL
} ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_28 , V_10 , - 1 , & V_29 ) ;
V_97 = F_13 ( V_27 , V_7 , V_8 - 4 , V_329 , V_330 , V_127 , V_29 , V_38 ) ;
if ( V_29 == 0x0000ffff )
F_133 ( V_97 , L_104 ) ;
return V_8 ;
}
static int
F_171 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_28 -> V_39 , NULL ) ;
return V_8 ;
}
static int
F_172 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_96 , NULL ) ;
return V_8 ;
}
static int
F_173 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_172 ) ;
return V_8 ;
}
static int
F_174 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_331 , & V_97 , L_105 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_332 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_173 , V_48 ,
L_85 , V_250 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_175 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_333 , & V_97 , L_106 ) ;
}
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_107 , V_233 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_108 , V_334 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_335 , NULL ) ;
V_8 = F_176 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_109 , V_100 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_110 , V_336 , 0 ) ;
V_8 = F_170 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_111 , V_337 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_112 ,
V_338 , 0 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_177 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_42 , V_339 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_340 , & V_339 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_341 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_342 , & V_42 ) ;
if( V_339 * 2 == 16 ) {
V_8 = F_167 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_343 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_344 , NULL ) ;
V_8 = F_168 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
}
return V_8 ;
}
static int
F_178 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_42 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_345 , & V_42 ) ;
F_6 ( V_9 , V_346 , V_7 , V_8 , V_42 ,
V_15 ) ;
V_8 += V_42 ;
return V_8 ;
}
static int
F_179 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 , int V_39 )
{
T_14 V_42 , V_43 ;
T_16 V_49 = TRUE ;
T_17 * V_97 ;
T_6 * V_50 = V_9 ;
if ( V_49 ) {
V_50 = F_18 (
V_9 , V_7 , V_8 , 0 , V_347 , & V_97 ,
F_19 ( V_39 ) ) ;
}
V_44 ;
if ( V_28 -> V_35 )
return V_8 ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_50 , V_28 , V_10 ,
V_45 , & V_42 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_50 , V_28 , V_10 ,
V_46 , & V_43 ) ;
V_8 = F_16 ( V_7 , V_8 , T_5 , V_50 , V_28 , V_10 ,
F_177 , V_48 ,
L_113 , V_39 , NULL , NULL ) ;
return V_8 ;
}
static int
F_180 ( T_3 * V_7 , int V_8 , T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_181 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_348 , 0 ) ;
return V_8 ;
}
static int
F_182 ( T_3 * V_7 , int V_8 , T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_183 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , F_180 , V_48 , L_114 , V_349 ) ;
return V_8 ;
}
static int
F_184 ( T_3 * V_7 , int V_8 , T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_185 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_350 , NULL ) ;
return V_8 ;
}
static int F_186 ( T_3 * V_7 , int V_8 , T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 , int V_39 V_6 , T_12 T_21 V_6 )
{
V_8 = F_187 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_351 , 0 ) ;
V_8 = F_187 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_352 , 0 ) ;
V_8 = F_187 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_353 , 0 ) ;
V_8 = F_184 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_182 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_188 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_354 , & V_97 , L_115 ) ;
}
V_8 = F_186 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , 0 , 0 ) ;
V_8 = F_179 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_355 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_155 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_156 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_157 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_141 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_142 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_356 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_143 , NULL ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_189 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_188 ) ;
return V_8 ;
}
static int
F_190 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_50 = NULL ;
T_12 V_42 ;
if( V_28 -> V_35 ) {
return V_8 ;
}
if( V_9 ) {
V_50 = F_18 ( V_9 , V_7 , V_8 , 0 ,
V_357 , & V_97 , L_116 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_50 , V_28 , V_10 ,
V_358 , & V_42 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_50 , V_28 , V_10 ,
F_178 , V_48 ,
L_117 , - 1 ) ;
return V_8 ;
}
static int
F_191 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_190 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_118 ,
V_359 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_119 ,
V_360 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_120 , V_154 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_121 , V_155 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_122 , V_156 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_123 , V_157 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_361 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_362 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_156 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_157 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_363 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_142 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_356 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_143 , NULL ) ;
return V_8 ;
}
static int
F_192 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 ) {
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_191 , V_48 ,
L_124 , - 1 ) ;
return V_8 ;
}
static int
F_193 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_188 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_364 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_189 , V_48 ,
L_125 , - 1 ) ;
V_8 = F_190 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_365 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_155 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_156 , 0 ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_157 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_363 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_366 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_356 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_143 , NULL ) ;
return V_8 ;
}
static int
F_194 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_111 = 0 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_193 , V_48 ,
L_126 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_195 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
int V_5 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_367 , & V_97 , L_127 ) ;
}
for( V_5 = 0 ; V_5 < 512 ; V_5 ++ ) {
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_368 , NULL ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_196 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_96 , NULL ) ;
return V_8 ;
}
static int
F_197 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_196 ) ;
return V_8 ;
}
static int
F_198 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_369 , & V_97 , L_128 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_197 , V_48 ,
L_85 , V_250 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_199 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_198 , V_48 ,
L_129 , - 1 ) ;
return V_8 ;
}
static int
F_200 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_370 ;
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_371 , NULL , L_130 ) ;
}
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_131 ,
V_372 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_132 ,
V_373 , 0 ) ;
V_8 = F_167 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_343 , & V_370 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_344 , & V_370 ) ;
V_8 = F_168 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_176 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_201 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_200 ) ;
return V_8 ;
}
static int
F_202 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_96 , NULL ) ;
return V_8 ;
}
static int
F_203 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_202 ) ;
return V_8 ;
}
static int
F_204 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_96 , NULL ) ;
return V_8 ;
}
static int
F_205 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_204 ) ;
return V_8 ;
}
static int
F_206 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_374 , & V_97 , L_133 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_203 , V_48 ,
L_85 , V_250 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_205 , V_48 ,
L_85 , V_250 ) ;
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_207 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_206 , V_48 ,
L_134 , - 1 ) ;
return V_8 ;
}
static int
F_208 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_11 * V_28 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_9 = NULL ;
int V_98 = V_8 ;
T_12 V_111 = 0 ;
if( V_27 ) {
V_9 = F_18 ( V_27 , V_7 , V_8 , 0 ,
V_375 , & V_97 , L_135 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , & V_111 ) ;
V_44 ;
switch( V_111 ) {
case 1 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
break;
}
F_44 ( V_97 , V_8 - V_98 ) ;
return V_8 ;
}
static int
F_209 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_11 * V_28 , T_1 * V_10 )
{
T_12 V_111 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_262 , & V_111 ) ;
if ( V_111 == 2 ) {
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_192 , V_48 ,
L_136 , - 1 ) ;
}
else {
if ( V_111 == 1 ) {
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_192 , V_48 ,
L_137 , - 1 ) ; }
}
return V_8 ;
}
static int
F_210 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_211 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_174 , V_89 ,
L_138 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_212 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_100 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_139 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_140 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_266 , NULL ) ;
return V_8 ;
}
static int
F_213 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_175 , V_48 ,
L_106 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_214 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_215 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_208 , V_48 ,
L_142 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_216 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_217 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_218 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
return V_8 ;
}
static int
F_219 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_171 , V_48 ,
L_143 , V_273 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_220 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_48 ,
L_144 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_221 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
int V_5 ;
for( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_96 , NULL ) ;
}
return V_8 ;
}
static int
F_222 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_221 , V_48 ,
L_144 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_223 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_48 ,
L_144 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_224 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_221 , V_48 ,
L_144 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int F_225 ( T_3 * V_7 , T_6 * V_9 , T_12 V_127 , int V_8 )
{
static const int * V_376 [] = {
#if 0
&hf_netlogon_neg_flags_80000000,
#endif
& V_377 ,
& V_378 ,
#if 0
&hf_netlogon_neg_flags_10000000,
&hf_netlogon_neg_flags_8000000,
&hf_netlogon_neg_flags_4000000,
&hf_netlogon_neg_flags_2000000,
&hf_netlogon_neg_flags_800000,
#endif
& V_379 ,
& V_380 ,
& V_381 ,
& V_382 ,
& V_383 ,
& V_384 ,
& V_385 ,
& V_386 ,
& V_387 ,
& V_388 ,
& V_389 ,
& V_390 ,
& V_391 ,
& V_392 ,
& V_393 ,
& V_394 ,
& V_395 ,
& V_396 ,
& V_397 ,
& V_398 ,
& V_399 ,
& V_400 ,
& V_401 ,
& V_402 ,
NULL
} ;
F_13 ( V_9 , V_7 , V_8 , V_403 , V_404 , V_376 , V_127 , V_38 ) ;
return 0 ;
}
static int
F_226 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
T_12 V_127 ;
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_145 , V_73 , 0 ) ;
V_8 = F_90 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_38 , V_85 , 0 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_405 , NULL ) ;
#if 0
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_CREDENTIAL, NDR_POINTER_REF,
"Client Challenge", -1);
#endif
#if 0
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_neg_flags, NULL);
#endif
V_44 ;
V_127 = F_55 ( V_7 , V_8 ) ;
F_225 ( V_7 , V_9 , V_127 , V_8 ) ;
V_406 . V_407 = FALSE ;
V_406 . V_186 = 0 ;
V_8 += 4 ;
return V_8 ;
}
static int
F_227 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
return F_226 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
}
static void F_228 ( const char * V_408 , char * V_409 )
{
T_22 V_410 = 0 ;
T_22 V_5 ;
V_410 = strlen ( V_408 ) ;
if( V_409 != NULL )
{
for( V_5 = 0 ; V_5 < ( V_410 ) ; V_5 ++ )
{
V_409 [ V_5 * 2 ] = V_408 [ V_5 ] ;
V_409 [ V_5 * 2 + 1 ] = 0 ;
}
V_409 [ 2 * V_410 ] = '\0' ;
}
}
static T_12 F_229 ( T_23 * * V_411 , const char * V_412 )
{
T_24 * V_413 ;
T_23 * V_414 ;
T_23 V_415 ;
int V_5 = 0 ;
T_12 V_416 = 0 ;
char V_417 [ 258 ] ;
int V_418 = 0 ;
int V_410 ;
if( ! V_419 ) {
* V_411 = NULL ;
return 0 ;
}
F_230 () ;
memset ( V_415 . V_420 , 0 , sizeof( T_23 ) ) ;
for( V_413 = V_421 ; V_413 ; V_413 = V_413 -> V_188 ) {
if( V_413 -> V_422 == 16 ) {
V_416 ++ ;
}
}
if ( V_412 [ 0 ] != '\0' && ( strlen ( V_412 ) < 129 ) ) {
V_416 ++ ;
F_2 ( L_146 , V_412 ) ;
V_410 = ( int ) strlen ( V_412 ) ;
F_228 ( V_412 , V_417 ) ;
F_231 ( V_415 . V_420 , V_417 , V_410 * 2 ) ;
F_1 ( V_415 . V_420 , 16 , L_147 , L_148 ) ;
V_418 = 1 ;
}
* V_411 = ( T_23 * ) F_232 ( F_233 () , V_416 * sizeof( T_23 ) ) ;
V_414 = * V_411 ;
if( V_418 ) {
memcpy ( V_414 [ 0 ] . V_420 , & ( V_415 . V_420 ) , sizeof( T_23 ) ) ;
V_5 ++ ;
}
for( V_413 = V_421 ; V_413 ; V_413 = V_413 -> V_188 ) {
if( V_413 -> V_422 == 16 ) {
memcpy ( V_414 [ V_5 ] . V_420 , V_413 -> V_423 , 16 ) ;
V_5 ++ ;
}
}
return V_416 ;
}
static int
F_234 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 , int V_424 )
{
T_12 V_127 ;
T_19 * V_175 ;
T_9 V_173 ;
T_7 V_425 ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_426 , & V_425 ) ;
V_127 = F_55 ( V_7 , V_8 ) ;
F_225 ( V_7 , V_9 , V_127 , V_8 ) ;
V_8 += 4 ;
V_44 ;
if( V_424 ) {
V_8 = F_235 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_427 , NULL ) ;
}
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
F_79 ( T_5 , 1 , & V_173 , NULL ) ;
V_175 = ( T_19 * ) F_87 ( V_189 , & V_173 ) ;
if( V_175 != NULL ) {
F_2 ( L_149 ) ;
while( V_175 != NULL && V_175 -> V_187 != - 1 && V_175 -> V_187 < ( int ) T_5 -> V_186 ) {
F_2 ( L_150 ) ;
V_175 = V_175 -> V_188 ;
}
if( V_175 == NULL ) {
F_2 ( L_151 ) ;
}
else {
#ifdef F_236
T_23 * V_414 = NULL ;
T_12 V_428 = 0 ;
unsigned int V_5 = 0 ;
T_23 V_429 ;
#endif
T_1 V_430 [ 16 ] ;
int V_431 = 0 ;
V_175 -> V_127 = V_127 ;
V_175 -> V_432 = FALSE ;
#ifdef F_236
V_428 = F_229 ( & V_414 , V_433 ) ;
F_2 ( L_152 , V_428 ) ;
#endif
if( V_127 & V_434 ) {
#ifdef F_236
T_1 V_435 [ 4 ] ;
T_1 V_436 [ 16 ] ;
T_25 V_437 ;
T_1 V_438 [ 8 ] ;
T_7 V_439 ;
memset ( V_435 , 0 , 4 ) ;
F_237 ( & V_437 ) ;
F_238 ( & V_437 , V_435 , 4 ) ;
F_238 ( & V_437 , ( unsigned char * ) & V_175 -> V_184 , 8 ) ;
F_238 ( & V_437 , ( unsigned char * ) & V_175 -> V_190 , 8 ) ;
F_239 ( & V_437 , V_436 ) ;
F_1 ( V_436 , 8 , L_153 , L_148 ) ;
F_1 ( ( T_1 * ) & V_175 -> V_184 , 8 , L_154 , L_148 ) ;
F_1 ( ( T_1 * ) & V_175 -> V_190 , 8 , L_155 , L_148 ) ;
F_1 ( ( T_1 * ) & V_425 , 8 , L_156 , L_148 ) ;
for( V_5 = 0 ; V_5 < V_428 ; V_5 ++ )
{
V_429 = V_414 [ V_5 ] ;
F_240 ( V_436 , 16 , ( T_1 * ) & V_429 , 16 , V_430 ) ;
F_241 ( V_438 , ( unsigned char * ) & V_175 -> V_190 , V_430 , 1 ) ;
F_241 ( ( unsigned char * ) & V_439 , V_438 , V_430 + 7 , 1 ) ;
#if 0
printnbyte((guint8*)&calculated_cred,8,"Calculated creds:","\n");
#endif
if( V_439 == V_425 ) {
V_431 = 1 ;
break;
}
}
#endif
}
else if( V_127 & V_440 )
{
F_2 ( L_157 ) ;
memset ( V_430 , 0 , 16 ) ;
}
else
{
F_2 ( L_158 ) ;
memset ( V_430 , 0 , 16 ) ;
}
if( V_431 ) {
memcpy ( & V_175 -> V_430 , V_430 , 16 ) ;
F_2 ( L_159 ) ;
}
else {
F_2 ( L_160 ) ;
memset ( & V_175 -> V_430 , 0 , 16 ) ;
}
}
} else {
F_1 ( ( T_1 * ) & V_175 -> V_430 , 16 , L_161 , L_148 ) ;
}
return V_8 ;
}
static int
F_242 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
return F_234 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , 1 ) ;
}
static int
F_243 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
return F_234 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , 0 ) ;
}
static int
F_244 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_100 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_139 , - 1 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_162 , V_441 , 0 ) ;
V_8 = F_169 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_245 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_175 , V_48 ,
L_106 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_246 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_247 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_16 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_179 , V_48 , L_162 ,
V_441 , V_180 ,
F_82 ( V_90 | 1 ) ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_248 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_85 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_163 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_209 , V_89 ,
L_164 , - 1 ) ;
return V_8 ;
}
static int
F_249 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_194 , V_89 ,
L_165 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_250 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_368 , NULL ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_195 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_251 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_252 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_145 , V_73 , 0 ) ;
V_8 = F_90 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
return V_8 ;
}
static int
F_253 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_45 , V_89 ,
L_166 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_254 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_39 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_48 ,
L_144 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_255 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_256 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_48 ,
L_144 , - 1 ) ;
return V_8 ;
}
static int
F_257 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_199 , V_48 ,
L_167 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_258 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_168 ,
V_73 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_168 ,
V_100 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_169 , - 1 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_112 ,
V_441 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_259 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_175 , V_48 ,
L_106 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_260 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_261 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_141 ,
V_250 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_171 , V_48 ,
L_143 , V_273 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_262 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_263 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_263 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_201 , V_48 ,
L_170 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_264 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_37 , V_48 ,
L_144 , - 1 ) ;
return V_8 ;
}
static int
F_265 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_207 , V_48 ,
L_134 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_266 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_267 (
V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_441 ,
V_180 ,
F_82 ( V_90 | 1 ) ) ;
return V_8 ;
}
static int
F_268 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_266 ) ;
return V_8 ;
}
static int
F_269 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_261 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_268 , V_48 ,
L_171 , - 1 ) ;
return V_8 ;
}
static int
F_270 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_271 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_269 , V_48 ,
L_172 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_272 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_173 ,
V_85 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_112 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_52 , V_89 ,
L_41 , - 1 ) ;
V_8 = F_15 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_169 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
#if 0
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, di, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_LEVEL, NDR_POINTER_UNIQUE,
"LEVEL pointer: unknown_NETLOGON_LEVEL", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
#endif
return V_8 ;
}
static int
F_273 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_72 , V_89 ,
L_42 , - 1 ) ;
V_8 = F_36 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_170 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
#if 0
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_VALIDATION, NDR_POINTER_UNIQUE,
"VALIDATION: unknown_NETLOGON_VALIDATION", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_pointer_char, NDR_POINTER_UNIQUE,
"BOOLEAN pointer: unknown_BOOLEAN", hf_netlogon_unknown_char);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, di, drep,
hf_netlogon_rc, NULL);
#endif
return V_8 ;
}
static int
F_274 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_167 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_275 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_263 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_201 , V_48 ,
L_170 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_276 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_8 , V_100 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_139 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_174 , - 1 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_175 , V_442 , 0 ) ;
return V_8 ;
}
static int
F_277 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int F_278 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 ,
T_6 * V_9 , T_11 * V_28 V_6 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_50 = NULL ;
T_12 V_443 ;
T_7 V_444 ;
static const int * V_445 [] = {
& V_446 ,
& V_447 ,
& V_448 ,
& V_449 ,
& V_450 ,
NULL
} ;
int V_42 ;
if ( V_9 ) {
V_50 = F_18 (
V_9 , V_7 , V_8 , - 1 , V_451 , & V_97 ,
L_176 ) ;
}
V_8 = F_235 (
V_7 , V_8 , T_5 , V_50 , V_10 ,
V_452 , & V_443 ) ;
F_279 ( V_50 , V_7 , V_8 ,
V_453 ,
V_454 ,
V_445 ,
( V_10 [ 0 ] & V_14 ) ?
V_455 :
V_456 ,
& V_444 ) ;
V_8 += 4 ;
if ( V_444 & 0x00000001 ) {
V_42 = F_280 ( V_7 , V_8 ) ;
F_6 ( V_50 , V_457 , V_7 , V_8 , V_42 , V_258 | V_15 ) ;
V_8 += V_42 ;
}
if ( V_444 & 0x00000002 ) {
V_42 = F_280 ( V_7 , V_8 ) ;
F_6 ( V_50 , V_458 , V_7 , V_8 , V_42 , V_258 | V_15 ) ;
V_8 += V_42 ;
}
if ( V_444 & 0x00000004 ) {
int V_98 = V_8 ;
char V_459 [ 256 ] ;
V_8 = F_281 ( V_7 , V_8 , V_459 , 255 , FALSE ) ;
F_282 ( V_50 , V_460 , V_7 , V_98 , V_8 - V_98 , V_459 ) ;
}
if ( V_444 & 0x00000008 ) {
int V_98 = V_8 ;
char V_459 [ 256 ] ;
V_8 = F_281 ( V_7 , V_8 , V_459 , 255 , FALSE ) ;
F_282 ( V_50 , V_461 , V_7 , V_98 , V_8 - V_98 , V_459 ) ;
}
if ( V_444 & 0x00000010 ) {
int V_98 = V_8 ;
char V_459 [ 256 ] ;
V_8 = F_281 ( V_7 , V_8 , V_459 , 255 , FALSE ) ;
F_282 ( V_50 , V_462 , V_7 , V_98 , V_8 - V_98 , V_459 ) ;
}
return V_8 ;
}
static int F_283 ( const T_1 * V_430 , int V_463 , T_7 V_464 , T_1 * V_465 )
{
T_1 V_435 [ 4 ] ;
T_1 * V_438 = ( T_1 * ) F_232 ( F_233 () , V_463 ) ;
T_1 V_466 [ 16 ] ;
T_1 V_467 [ 16 ] ;
int V_5 = 0 ;
memset ( V_467 , 0 , 16 ) ;
memset ( V_465 , 0 , 16 ) ;
if( memcmp ( V_430 , V_467 , 16 ) ) {
memset ( V_435 , 0 , 4 ) ;
for( V_5 = 0 ; V_5 < V_463 ; V_5 ++ ) {
V_438 [ V_5 ] = V_430 [ V_5 ] ^ 0xF0 ;
}
F_240 ( V_435 , 4 , V_438 , V_463 , V_466 ) ;
F_240 ( ( T_1 * ) & V_464 , 8 , V_466 , 16 , V_465 ) ;
return 1 ;
}
else {
return 0 ;
}
}
static T_7 F_284 ( T_1 * V_430 , T_7 V_468 , T_7 V_469 , unsigned char V_172 V_6 )
{
T_1 V_435 [ 4 ] ;
T_1 V_438 [ 16 ] ;
T_1 V_173 [ 16 ] ;
T_26 V_470 ;
T_1 * V_471 = ( T_1 * ) & V_469 ;
memset ( V_435 , 0 , 4 ) ;
F_240 ( V_435 , 4 , V_430 , 16 , V_438 ) ;
F_240 ( ( T_1 * ) & V_468 , 8 , V_438 , 16 , V_173 ) ;
F_285 ( & V_470 , V_173 , 16 ) ;
F_286 ( & V_470 , V_471 , 8 ) ;
return V_469 ;
}
static T_3 *
F_287 ( T_3 * V_7 , T_3 * T_27 V_6 ,
int V_8 , T_4 * T_5 , T_28 * T_29 V_6 , unsigned char V_172 )
{
T_3 * V_438 = NULL ;
T_1 * V_472 ;
T_19 * V_175 ;
T_9 V_173 ;
F_79 ( T_5 , V_172 , & V_173 , NULL ) ;
V_175 = ( T_19 * ) F_87 ( V_189 , & V_173 ) ;
if( V_175 != NULL ) {
while( V_175 != NULL && V_175 -> V_187 != - 1 && V_175 -> V_187 < ( int ) T_5 -> V_186 ) {
V_175 = V_175 -> V_188 ;
}
if( V_175 == NULL ) {
F_2 ( L_177 , F_288 ( V_189 ) ) ;
return ( V_438 ) ;
}
else {
if( V_175 -> V_432 == TRUE ) {
T_26 V_470 ;
int V_195 ;
T_7 V_473 = V_175 -> V_474 ;
V_195 = F_289 ( V_7 , V_8 ) ;
if ( V_195 < 0 ) {
return NULL ;
}
F_285 ( & V_470 , V_175 -> V_475 , 16 ) ;
F_286 ( & V_470 , ( T_1 * ) & V_473 , 8 ) ;
V_472 = ( T_1 * ) F_290 ( T_5 -> V_476 , V_7 , V_8 , V_195 ) ;
F_285 ( & V_470 , V_175 -> V_475 , 16 ) ;
F_286 ( & V_470 , V_472 , V_195 ) ;
V_438 = F_291 ( V_7 , V_472 , V_195 , V_195 ) ;
}
else {
F_2 ( L_178 ) ;
}
}
} else {
F_2 ( L_179 , F_288 ( V_189 ) ) ;
return ( V_438 ) ;
}
return ( V_438 ) ;
}
static T_3 * F_292 ( T_3 * V_7 , T_3 * T_27 ,
int V_8 , T_4 * T_5 , T_28 * T_29 )
{
return F_287 ( V_7 , T_27 , V_8 , T_5 , T_29 , 0 ) ;
}
static T_3 * F_293 ( T_3 * V_7 , T_3 * T_27 ,
int V_8 , T_4 * T_5 , T_28 * T_29 )
{
return F_287 ( V_7 , T_27 , V_8 , T_5 , T_29 , 1 ) ;
}
static int
F_294 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_1 * V_10 , unsigned char V_172 )
{
T_19 * V_175 ;
T_9 V_173 ;
T_17 * V_477 = NULL ;
T_6 * V_50 = NULL ;
T_7 V_478 ;
T_7 V_479 ;
T_7 V_474 = 0 ;
int V_480 = 0 ;
F_79 ( T_5 , V_172 , & V_173 , NULL ) ;
V_175 = ( T_19 * ) F_87 ( V_189 , ( T_8 * ) & V_173 ) ;
if( ! ( V_406 . V_407 && V_406 . V_186 == T_5 -> V_186 ) ) {
V_477 = F_6 ( V_9 , V_481 , V_7 ,
V_8 , - 1 , V_15 ) ;
V_50 = F_295 ( V_477 , V_482 ) ;
F_6 ( V_50 , V_483 , V_7 ,
V_8 , 2 , V_455 ) ;
F_6 ( V_50 , V_484 , V_7 ,
V_8 + 2 , 2 , V_455 ) ;
F_6 ( V_50 , V_485 , V_7 ,
V_8 + 6 , 2 , V_15 ) ;
V_8 += 8 ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_486 , & V_478 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_487 , & V_479 ) ;
if ( F_296 ( V_7 , V_8 , 8 ) ) {
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_488 , & V_474 ) ;
}
V_480 = 1 ;
}
if( V_175 != NULL ) {
while( V_175 != NULL && V_175 -> V_187 != - 1 && V_175 -> V_187 < ( int ) T_5 -> V_186 ) {
V_175 = V_175 -> V_188 ;
}
if( V_175 == NULL ) {
F_2 ( L_177 , F_288 ( V_189 ) ) ;
return ( V_8 ) ;
}
else {
if( V_480 ) {
V_175 -> V_474 = V_474 ;
V_175 -> V_489 = F_284 ( V_175 -> V_430 , V_479 , V_478 , V_172 ) ;
}
if( F_283 ( V_175 -> V_430 , 16 , V_175 -> V_489 , V_175 -> V_475 ) )
{
V_175 -> V_432 = TRUE ;
}
else
{
F_2 ( L_180 ) ;
}
}
}
else
{
F_2 ( L_181 , V_175 == NULL , F_288 ( V_189 ) ) ;
}
V_406 . V_407 = TRUE ;
V_406 . V_186 = T_5 -> V_186 ;
return V_8 ;
}
static int
F_297 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_11 * V_28 V_6 , T_1 * V_10 )
{
return F_294 ( V_7 , V_8 , T_5 , V_9 , V_10 , 0 ) ;
}
static int
F_298 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_11 * V_28 V_6 , T_1 * V_10 )
{
return F_294 ( V_7 , V_8 , T_5 , V_9 , V_10 , 1 ) ;
}
static void
F_299 ( void )
{
V_189 = F_300 ( F_9 , F_7 ) ;
V_490 = F_300 ( F_9 , F_7 ) ;
}
static void
F_301 ( void )
{
F_302 ( V_189 ) ;
F_302 ( V_490 ) ;
}
void
F_303 ( void )
{
static T_30 V_491 [] = {
{ & V_492 ,
{ L_182 , L_183 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_171 , {
L_184 , L_185 , V_496 , V_497 | V_498 ,
& V_499 , 0x0 , L_186 , V_495 } } ,
{ & V_92 ,
{ L_187 , L_188 , V_496 ,
V_497 | V_498 , & V_500 , 0x0 , NULL , V_495 } } ,
{ & V_276 ,
{ L_189 , L_190 , V_496 ,
V_497 | V_498 , & V_279 , 0x0 , NULL , V_495 } } ,
{ & V_101 , {
L_191 , L_192 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_102 , {
L_193 , L_194 , V_501 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_246 , {
L_195 , L_196 , V_501 , V_494 ,
NULL , 0x0 , L_197 , V_495 } } ,
{ & V_209 , {
L_198 , L_199 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_261 , {
L_200 , L_201 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_263 , {
L_202 , L_203 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_113 , {
L_204 , L_205 , V_502 , V_503 ,
NULL , 0x0 , L_206 , V_495 } } ,
{ & V_106 , {
L_207 , L_208 , V_502 , V_503 ,
NULL , 0x0 , L_209 , V_495 } } ,
{ & V_103 , {
L_210 , L_211 , V_502 , V_503 ,
NULL , 0x0 , L_212 , V_495 } } ,
{ & V_126 , {
L_213 , L_214 , V_502 , V_503 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_193 , {
L_215 , L_216 , V_502 , V_503 ,
NULL , 0x0 , L_217 , V_495 } } ,
{ & V_105 , {
L_218 , L_219 , V_502 , V_503 ,
NULL , 0x0 , L_220 , V_495 } } ,
{ & V_346 , {
L_221 , L_222 , V_502 , V_503 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_332 , {
L_223 , L_224 , V_496 , V_494 ,
NULL , 0 , L_225 , V_495 } } ,
{ & V_74 , {
L_226 , L_227 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_236 , {
L_228 , L_229 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_237 , {
L_230 , L_231 , V_496 , V_497 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_235 , {
L_232 , L_233 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_267 , {
L_234 , L_235 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_269 , {
L_236 , L_237 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_122 , {
L_238 , L_239 , V_496 , V_497 ,
NULL , 0 , NULL , V_495 } } ,
#if 0
{ &hf_netlogon_lsapolicy_referentid,
{ "Referent ID", "netlogon.lsapolicy.referentID", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_358 ,
{ L_225 , L_240 , V_496 , V_494 ,
NULL , 0x0 , L_241 , V_495 } } ,
#if 0
{ &hf_netlogon_lsapolicy_pointer,
{ "Pointer", "netlogon.lsapolicy.pointer", FT_BYTES, BASE_NONE,
NULL, 0x0, "Pointer to LSA POLICY", HFILL }},
#endif
{ & V_250 ,
{ L_242 , L_243 , V_504 , V_503 ,
NULL , 0 , L_244 , V_495 } } ,
{ & V_272 ,
{ L_245 , L_246 , V_504 , V_503 ,
NULL , 0 , L_247 , V_495 } } ,
{ & V_274 ,
{ L_99 , L_248 , V_504 , V_503 ,
NULL , 0 , L_249 , V_495 } } ,
{ & V_154 ,
{ L_250 , L_251 , V_504 , V_503 ,
NULL , 0 , L_252 , V_495 } } ,
{ & V_355 ,
{ L_253 , L_254 , V_504 , V_503 ,
NULL , 0 , L_255 , V_495 } } ,
{ & V_341 ,
{ L_256 , L_257 , V_496 , V_494 ,
NULL , 0 , L_255 , V_495 } } ,
{ & V_342 ,
{ L_225 , L_258 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_340 ,
{ L_259 , L_260 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_155 ,
{ L_261 , L_251 , V_504 , V_503 ,
NULL , 0 , L_262 , V_495 } } ,
{ & V_156 ,
{ L_263 , L_251 , V_504 , V_503 ,
NULL , 0 , L_264 , V_495 } } ,
{ & V_157 ,
{ L_265 , L_251 , V_504 , V_503 ,
NULL , 0 , L_266 , V_495 } } ,
{ & V_158 ,
{ L_267 , L_251 , V_504 , V_503 ,
NULL , 0 , L_268 , V_495 } } ,
{ & V_159 ,
{ L_269 , L_251 , V_504 , V_503 ,
NULL , 0 , L_270 , V_495 } } ,
{ & V_160 ,
{ L_271 , L_251 , V_504 , V_503 ,
NULL , 0 , L_272 , V_495 } } ,
{ & V_161 ,
{ L_273 , L_251 , V_504 , V_503 ,
NULL , 0 , L_274 , V_495 } } ,
{ & V_162 ,
{ L_275 , L_251 , V_504 , V_503 ,
NULL , 0 , L_276 , V_495 } } ,
{ & V_163 ,
{ L_277 , L_251 , V_504 , V_503 ,
NULL , 0 , L_278 , V_495 } } ,
{ & V_273 ,
{ L_279 , L_280 , V_496 , V_497 ,
NULL , 0x0 , L_281 , V_495 } } ,
{ & V_141 ,
{ L_282 , L_283 , V_496 , V_497 ,
NULL , 0x0 , L_284 , V_495 } } ,
{ & V_142 ,
{ L_285 , L_286 , V_496 , V_497 ,
NULL , 0x0 , L_287 , V_495 } } ,
{ & V_356 ,
{ L_288 , L_289 , V_496 , V_497 ,
NULL , 0x0 , L_290 , V_495 } } ,
{ & V_143 ,
{ L_291 , L_292 , V_496 , V_497 ,
NULL , 0x0 , L_293 , V_495 } } ,
{ & V_144 ,
{ L_294 , L_295 , V_496 , V_497 ,
NULL , 0x0 , L_296 , V_495 } } ,
{ & V_145 ,
{ L_297 , L_298 , V_496 , V_497 ,
NULL , 0x0 , L_299 , V_495 } } ,
{ & V_146 ,
{ L_300 , L_301 , V_496 , V_497 ,
NULL , 0x0 , L_302 , V_495 } } ,
{ & V_147 ,
{ L_303 , L_304 , V_496 , V_497 ,
NULL , 0x0 , L_305 , V_495 } } ,
{ & V_148 ,
{ L_306 , L_307 , V_496 , V_497 ,
NULL , 0x0 , L_308 , V_495 } } ,
{ & V_149 ,
{ L_309 , L_310 , V_496 , V_497 ,
NULL , 0x0 , L_311 , V_495 } } ,
{ & V_366 ,
{ L_312 , L_313 , V_496 , V_497 ,
NULL , 0x0 , L_314 , V_495 } } ,
{ & V_363 ,
{ L_315 , L_316 , V_496 , V_497 ,
NULL , 0x0 , L_317 , V_495 } } ,
{ & V_88 ,
{ L_318 , L_319 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_368 ,
{ L_320 , L_321 , V_493 , V_497 ,
NULL , 0x0 , L_322 , V_495 } } ,
{ & V_96 ,
{ L_323 , L_324 , V_505 , V_497 ,
NULL , 0x0 , L_325 , V_495 } } ,
{ & V_201 ,
{ L_326 , L_327 , V_506 , V_507 ,
NULL , 0x0 , L_328 , V_495 } } ,
{ & V_202 ,
{ L_329 , L_330 , V_505 , V_497 ,
NULL , 0x0 , L_331 , V_495 } } ,
{ & V_203 ,
{ L_332 , L_333 , V_505 , V_497 ,
NULL , 0x0 , L_334 , V_495 } } ,
{ & V_204 ,
{ L_335 , L_336 , V_505 , V_497 ,
NULL , 0x0 , L_337 , V_495 } } ,
{ & V_170 ,
{ L_338 , L_339 , V_505 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_198 ,
{ L_340 , L_341 , V_505 , V_494 ,
NULL , 0x0 , L_342 , V_495 } } ,
{ & V_229 ,
{ L_343 , L_344 , V_505 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_230 ,
{ L_345 , L_346 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_219 ,
{ L_347 , L_348 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_196 ,
{ L_225 , L_349 , V_496 , V_494 ,
NULL , 0x0 , L_350 , V_495 } } ,
#if 0
{ &hf_netlogon_nt_chal_resp,
{ "NT Chal resp", "netlogon.nt_chal_resp", FT_BYTES, BASE_NONE,
NULL, 0, "Challenge response for NT authentication", HFILL }},
#endif
{ & V_107 ,
{ L_351 , L_352 , V_502 , V_503 ,
NULL , 0 , L_353 , V_495 } } ,
{ & V_240 ,
{ L_354 , L_355 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_239 ,
{ L_356 , L_357 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
#if 0
{ &hf_netlogon_pac_data,
{ "Pac Data", "netlogon.pac.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_197 ,
{ L_358 , L_359 , V_502 , V_503 ,
NULL , 0 , L_340 , V_495 } } ,
#if 0
{ &hf_netlogon_auth_data,
{ "Auth Data", "netlogon.auth.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_242 ,
{ L_360 , L_361 , V_502 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_244 ,
{ L_362 , L_363 , V_502 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_73 ,
{ L_145 , L_364 , V_504 , V_503 ,
NULL , 0 , L_56 , V_495 } } ,
{ & V_199 ,
{ L_365 , L_366 , V_504 , V_503 ,
NULL , 0 , L_367 , V_495 } } ,
{ & V_216 ,
{ L_368 , L_369 , V_504 , V_503 ,
NULL , 0 , L_370 , V_495 } } ,
{ & V_133 ,
{ L_371 , L_372 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_205 ,
{ L_373 , L_374 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_206 ,
{ L_375 , L_376 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_87 ,
{ L_377 , L_378 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_134 ,
{ L_379 , L_380 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_135 ,
{ L_381 , L_382 , V_504 , V_503 ,
NULL , 0 , L_383 , V_495 } } ,
{ & V_136 ,
{ L_384 , L_385 , V_504 , V_503 ,
NULL , 0 , L_386 , V_495 } } ,
{ & V_140 ,
{ L_387 , L_388 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
#if 0
{ &hf_netlogon_principal,
{ "Principal", "netlogon.principal", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_100 ,
{ L_8 , L_389 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_165 ,
{ L_390 , L_391 , V_496 , V_494 ,
NULL , 0 , L_392 , V_495 } } ,
{ & V_85 ,
{ L_38 , L_393 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_441 ,
{ L_162 , L_394 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_233 ,
{ L_107 , L_395 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_337 ,
{ L_396 , L_397 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_336 ,
{ L_398 , L_399 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_334 ,
{ L_108 , L_400 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_335 ,
{ L_401 , L_402 , V_496 , V_494 ,
F_304 ( V_508 ) , 0 , NULL , V_495 } } ,
{ & V_338 ,
{ L_403 , L_404 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_360 ,
{ L_405 , L_406 , V_504 , V_503 ,
NULL , 0 , L_407 , V_495 } } ,
{ & V_91 ,
{ L_408 , L_409 , V_504 , V_503 ,
NULL , 0 , L_410 , V_495 } } ,
{ & V_361 ,
{ L_411 , L_412 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_362 ,
{ L_413 , L_414 , V_504 , V_503 ,
NULL , 0 , L_415 , V_495 } } ,
{ & V_200 ,
{ L_416 , L_417 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_359 ,
{ L_418 , L_419 , V_504 , V_503 ,
NULL , 0 , L_118 , V_495 } } ,
{ & V_215 ,
{ L_420 , L_421 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_217 ,
{ L_422 , L_423 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_442 ,
{ L_424 , L_425 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_372 ,
{ L_426 , L_427 , V_504 , V_503 ,
NULL , 0 , L_428 , V_495 } } ,
{ & V_373 ,
{ L_429 , L_430 , V_504 , V_503 ,
NULL , 0 , L_132 , V_495 } } ,
{ & V_365 ,
{ L_431 , L_432 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_86 ,
{ L_8 , L_389 , V_504 , V_503 ,
NULL , 0 , L_433 , V_495 } } ,
{ & V_210 ,
{ L_434 , L_435 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_268 ,
{ L_436 , L_437 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_152 ,
{ L_438 , L_439 , V_504 , V_503 ,
NULL , 0 , L_440 , V_495 } } ,
{ & V_153 ,
{ L_441 , L_442 , V_504 , V_503 ,
NULL , 0 , L_443 , V_495 } } ,
{ & V_72 ,
{ L_444 , L_445 , V_504 , V_503 ,
NULL , 0 , L_446 , V_495 } } ,
{ & V_194 ,
{ L_447 , L_448 , V_504 , V_503 ,
NULL , 0 , L_449 , V_495 } } ,
{ & V_95 ,
{ L_450 , L_451 , V_493 , V_494 ,
NULL , 0x0 , L_452 , V_495 } } ,
{ & V_76 ,
{ L_450 , L_453 , V_496 , V_494 ,
NULL , 0x0 , L_452 , V_495 } } ,
{ & V_137 ,
{ L_454 , L_455 , V_493 , V_494 ,
NULL , 0x0 , L_456 , V_495 } } ,
{ & V_77 ,
{ L_454 , L_457 , V_496 , V_494 ,
NULL , 0x0 , L_456 , V_495 } } ,
{ & V_207 ,
{ L_458 , L_459 , V_493 , V_494 | V_498 ,
& V_509 , 0x0 , L_460 , V_495 } } ,
{ & V_208 ,
{ L_461 , L_462 , V_493 , V_494 ,
NULL , 0x0 , L_463 , V_495 } } ,
{ & V_112 ,
{ L_464 , L_465 , V_493 , V_494 ,
NULL , 0x0 , L_466 , V_495 } } ,
{ & V_169 ,
{ L_467 , L_468 , V_493 , V_494 ,
NULL , 0x0 , L_469 , V_495 } } ,
{ & V_211 ,
{ L_470 , L_471 , V_493 , V_494 ,
NULL , 0x0 , L_472 , V_495 } } ,
{ & V_212 ,
{ L_473 , L_474 , V_493 , V_494 ,
NULL , 0x0 , L_475 , V_495 } } ,
{ & V_192 ,
{ L_476 , L_477 , V_493 , V_494 ,
F_304 ( V_510 ) , 0x0 , L_478 , V_495 } } ,
{ & V_280 ,
{ L_479 , L_480 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_248 ,
{ L_481 , L_482 , V_493 , V_494 ,
F_304 ( V_252 ) , 0x0 , NULL , V_495 } } ,
{ & V_345 ,
{ L_483 , L_484 , V_496 , V_494 ,
NULL , 0x0 , L_485 , V_495 } } ,
{ & V_271 ,
{ L_486 , L_487 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_262 ,
{ L_464 , L_488 , V_496 , V_494 ,
NULL , 0x0 , L_466 , V_495 } } ,
{ & V_264 ,
{ L_489 , L_490 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_265 ,
{ L_491 , L_492 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_117 ,
{ L_493 , L_494 , V_506 , V_507 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_138 ,
{ L_495 , L_496 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_218 ,
{ L_497 , L_498 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_125 ,
{ L_499 , L_500 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_139 ,
{ L_501 , L_502 , V_496 , V_494 ,
NULL , 0x0 , L_503 , V_495 } } ,
{ & V_234 ,
{ L_504 , L_505 , V_496 , V_494 ,
NULL , 0x0 , L_506 , V_495 } } ,
{ & V_150 ,
{ L_507 , L_508 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_266 ,
{ L_317 , L_509 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_70 ,
{ L_510 , L_511 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_130 ,
{ L_512 , L_513 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_75 ,
{ L_514 , L_515 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_238 ,
{ L_516 , L_517 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_254 ,
{ L_518 , L_519 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_256 ,
{ L_520 , L_521 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_255 ,
{ L_522 , L_523 , V_496 , V_494 ,
NULL , 0x0 , L_524 , V_495 } } ,
{ & V_227 ,
{ L_525 , L_526 , V_496 , V_494 ,
NULL , 0x0 , L_527 , V_495 } } ,
#if 0
{ &hf_netlogon_pac_size,
{ "Pac Size", "netlogon.pac.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size of PacData in bytes", HFILL }},
#endif
#if 0
{ &hf_netlogon_auth_size,
{ "Auth Size", "netlogon.auth.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "Size of AuthData in bytes", HFILL }},
#endif
{ & V_253 ,
{ L_528 , L_529 , V_496 , V_494 ,
NULL , 0x0 , L_530 , V_495 } } ,
{ & V_364 ,
{ L_531 , L_532 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_270 ,
{ L_533 , L_534 , V_496 , V_494 ,
NULL , 0x0 , L_535 , V_495 } } ,
{ & V_225 ,
{ L_536 , L_537 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_221 ,
{ L_538 , L_539 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_222 ,
{ L_540 , L_541 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_223 ,
{ L_542 , L_543 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_224 ,
{ L_544 , L_545 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_260 ,
{ L_546 , L_547 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_403 ,
{ L_548 , L_549 , V_496 , V_497 ,
NULL , 0x0 , L_550 , V_495 } } ,
#if 0
{ &hf_netlogon_neg_flags_80000000,
{ "Not used 80000000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_80000000, "Not used", HFILL }},
#endif
{ & V_377 ,
{ L_551 , L_552 , V_511 , 32 , F_305 ( & V_512 ) , V_513 , NULL , V_495 } } ,
{ & V_378 ,
{ L_553 , L_552 , V_511 , 32 , F_305 ( & V_512 ) , V_514 , L_554 , V_495 } } ,
#if 0
{ &hf_netlogon_neg_flags_10000000,
{ "Not used 10000000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_10000000, "Not used", HFILL }},
#endif
#if 0
{ &hf_netlogon_neg_flags_8000000,
{ "Not used 8000000", "ntlmssp.neg_flags.na800000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_8000000, "Not used", HFILL }},
#endif
#if 0
{ &hf_netlogon_neg_flags_4000000,
{ "Not used 4000000", "ntlmssp.neg_flags.na400000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_4000000, "Not used", HFILL }},
#endif
#if 0
{ &hf_netlogon_neg_flags_2000000,
{ "Not used 2000000", "ntlmssp.neg_flags.na200000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_2000000, "Not used", HFILL }},
#endif
{ & V_379 ,
{ L_555 , L_556 , V_511 , 32 , F_305 ( & V_512 ) , V_515 , L_557 , V_495 } } ,
#if 0
{ &hf_netlogon_neg_flags_800000,
{ "Not used 800000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_800000, "Not used", HFILL }},
#endif
{ & V_380 ,
{ L_558 , L_559 , V_511 , 32 , F_305 ( & V_512 ) , V_440 , L_560 , V_495 } } ,
{ & V_381 ,
{ L_561 , L_562 , V_511 , 32 , F_305 ( & V_512 ) , V_516 , L_563 , V_495 } } ,
{ & V_382 ,
{ L_564 , L_556 , V_511 , 32 , F_305 ( & V_512 ) , V_517 , L_565 , V_495 } } ,
{ & V_383 ,
{ L_566 , L_567 , V_511 , 32 , F_305 ( & V_512 ) , V_518 , NULL , V_495 } } ,
{ & V_384 ,
{ L_568 , L_569 , V_511 , 32 , F_305 ( & V_512 ) , V_519 , L_570 , V_495 } } ,
{ & V_385 ,
{ L_571 , L_572 , V_511 , 32 , F_305 ( & V_512 ) , V_520 , L_573 , V_495 } } ,
{ & V_386 ,
{ L_574 , L_575 , V_511 , 32 , F_305 ( & V_512 ) , V_521 , L_576 , V_495 } } ,
{ & V_387 ,
{ L_577 , L_578 , V_511 , 32 , F_305 ( & V_512 ) , V_522 , L_579 , V_495 } } ,
{ & V_388 ,
{ L_580 , L_581 , V_511 , 32 , F_305 ( & V_512 ) , V_434 , NULL , V_495 } } ,
{ & V_389 ,
{ L_582 , L_583 , V_511 , 32 , F_305 ( & V_512 ) , V_523 , NULL , V_495 } } ,
{ & V_390 ,
{ L_584 , L_585 , V_511 , 32 , F_305 ( & V_512 ) , V_524 , NULL , V_495 } } ,
{ & V_391 ,
{ L_586 , L_587 , V_511 , 32 , F_305 ( & V_512 ) , V_525 , NULL , V_495 } } ,
{ & V_392 ,
{ L_588 , L_589 , V_511 , 32 , F_305 ( & V_512 ) , V_526 , NULL , V_495 } } ,
{ & V_393 ,
{ L_590 , L_591 , V_511 , 32 , F_305 ( & V_512 ) , V_527 , NULL , V_495 } } ,
{ & V_394 ,
{ L_592 , L_593 , V_511 , 32 , F_305 ( & V_512 ) , V_528 , L_594 , V_495 } } ,
{ & V_395 ,
{ L_595 , L_596 , V_511 , 32 , F_305 ( & V_512 ) , V_529 , NULL , V_495 } } ,
{ & V_396 ,
{ L_597 , L_598 , V_511 , 32 , F_305 ( & V_512 ) , V_530 , NULL , V_495 } } ,
{ & V_397 ,
{ L_599 , L_600 , V_511 , 32 , F_305 ( & V_512 ) , V_531 , NULL , V_495 } } ,
{ & V_398 ,
{ L_601 , L_602 , V_511 , 32 , F_305 ( & V_512 ) , V_532 , L_603 , V_495 } } ,
{ & V_399 ,
{ L_604 , L_605 , V_511 , 32 , F_305 ( & V_512 ) , V_533 , L_606 , V_495 } } ,
{ & V_400 ,
{ L_607 , L_608 , V_511 , 32 , F_305 ( & V_512 ) , V_534 , L_609 , V_495 } } ,
{ & V_401 ,
{ L_610 , L_611 , V_511 , 32 , F_305 ( & V_512 ) , V_535 , L_612 , V_495 } } ,
{ & V_402 ,
{ L_613 , L_614 , V_511 , 32 , F_305 ( & V_512 ) , V_536 , NULL , V_495 } } ,
{ & V_329 ,
{ L_615 , L_616 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_328 ,
{ L_617 , L_618 ,
V_511 , 32 , F_305 ( & V_537 ) , V_538 ,
L_619 , V_495 } } ,
{ & V_327 ,
{ L_620 , L_621 ,
V_511 , 32 , F_305 ( & V_539 ) , V_540 ,
L_622 , V_495 } } ,
{ & V_326 ,
{ L_623 , L_624 ,
V_511 , 32 , F_305 ( & V_541 ) , V_542 ,
L_625 , V_495 } } ,
{ & V_325 ,
{ L_626 , L_627 ,
V_511 , 32 , F_305 ( & V_543 ) , V_544 ,
L_628 , V_495 } } ,
{ & V_324 ,
{ L_629 , L_630 ,
V_511 , 32 , F_305 ( & V_545 ) , V_546 ,
L_631 , V_495 } } ,
{ & V_323 ,
{ L_632 , L_633 ,
V_511 , 32 , F_305 ( & V_547 ) , V_548 ,
L_634 , V_495 } } ,
{ & V_322 ,
{ L_635 , L_636 ,
V_511 , 32 , F_305 ( & V_549 ) , V_550 ,
L_637 , V_495 } } ,
{ & V_321 ,
{ L_638 , L_639 ,
V_511 , 32 , F_305 ( & V_551 ) , V_552 ,
L_640 , V_495 } } ,
{ & V_320 ,
{ L_641 , L_642 ,
V_511 , 32 , F_305 ( & V_553 ) , V_554 ,
L_643 , V_495 } } ,
{ & V_319 ,
{ L_644 , L_645 ,
V_511 , 32 , F_305 ( & V_555 ) , V_556 ,
L_646 , V_495 } } ,
{ & V_318 ,
{ L_647 , L_648 ,
V_511 , 32 , F_305 ( & V_557 ) , V_558 ,
L_649 , V_495 } } ,
{ & V_317 ,
{ L_429 , L_650 ,
V_511 , 32 , F_305 ( & V_559 ) , V_560 ,
NULL , V_495 } } ,
{ & V_316 ,
{ L_110 , L_651 ,
V_511 , 32 , F_305 ( & V_561 ) , V_562 ,
NULL , V_495 } } ,
{ & V_314 ,
{ L_317 , L_652 , V_496 , V_497 ,
NULL , 0x0 , L_653 , V_495 } } ,
{ & V_313 ,
{ L_654 , L_655 ,
V_511 , 32 , F_305 ( & V_563 ) , V_564 ,
L_656 , V_495 } } ,
{ & V_312 ,
{ L_657 , L_658 ,
V_511 , 32 , F_305 ( & V_565 ) , V_566 ,
L_659 , V_495 } } ,
{ & V_311 ,
{ L_660 , L_661 ,
V_511 , 32 , F_305 ( & V_567 ) , V_568 ,
L_662 , V_495 } } ,
{ & V_310 ,
{ L_663 , L_664 ,
V_511 , 32 , F_305 ( & V_569 ) , V_570 ,
L_665 , V_495 } } ,
{ & V_309 ,
{ L_666 , L_667 ,
V_511 , 32 , F_305 ( & V_571 ) , V_572 ,
L_668 , V_495 } } ,
{ & V_308 ,
{ L_669 , L_670 ,
V_511 , 32 , F_305 ( & V_573 ) , V_574 ,
L_671 , V_495 } } ,
{ & V_307 ,
{ L_672 , L_673 ,
V_511 , 32 , F_305 ( & V_575 ) , V_576 ,
L_674 , V_495 } } ,
{ & V_306 ,
{ L_675 , L_676 ,
V_511 , 32 , F_305 ( & V_577 ) , V_578 ,
L_677 , V_495 } } ,
{ & V_305 ,
{ L_678 , L_679 ,
V_511 , 32 , F_305 ( & V_579 ) , V_580 ,
L_680 , V_495 } } ,
{ & V_304 ,
{ L_681 , L_682 ,
V_511 , 32 , F_305 ( & V_581 ) , V_582 ,
L_683 , V_495 } } ,
{ & V_303 ,
{ L_684 , L_685 ,
V_511 , 32 , F_305 ( & V_583 ) , V_584 ,
L_686 , V_495 } } ,
{ & V_302 ,
{ L_687 , L_688 ,
V_511 , 32 , F_305 ( & V_585 ) , V_586 ,
L_689 , V_495 } } ,
{ & V_301 ,
{ L_690 , L_691 ,
V_511 , 32 , F_305 ( & V_587 ) , V_588 ,
L_692 , V_495 } } ,
{ & V_299 ,
{ L_693 , L_694 ,
V_511 , 32 , F_305 ( & V_589 ) , V_590 ,
L_695 , V_495 } } ,
{ & V_300 ,
{ L_696 , L_697 ,
V_511 , 32 , F_305 ( & V_591 ) , V_592 ,
L_698 , V_495 } } ,
{ & V_298 ,
{ L_699 , L_700 ,
V_511 , 32 , F_305 ( & V_593 ) , V_594 ,
L_701 , V_495 } } ,
{ & V_297 ,
{ L_702 , L_703 ,
V_511 , 32 , F_305 ( & V_595 ) , V_596 ,
L_704 , V_495 } } ,
{ & V_295 ,
{ L_705 , L_706 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_294 ,
{ L_707 , L_708 , V_511 , 32 ,
F_305 ( & V_597 ) , 0x00000001 , NULL , V_495 } } ,
{ & V_293 ,
{ L_709 , L_710 , V_511 , 32 ,
F_305 ( & V_598 ) , 0x00000002 , NULL , V_495 } } ,
{ & V_292 ,
{ L_711 , L_712 , V_511 , 32 ,
F_305 ( & V_599 ) , 0x00000004 , NULL , V_495 } } ,
{ & V_291 ,
{ L_713 , L_714 , V_511 , 32 ,
F_305 ( & V_600 ) , 0x00000008 , NULL , V_495 } } ,
{ & V_290 ,
{ L_715 , L_716 , V_511 , 32 ,
F_305 ( & V_601 ) , 0x00000010 , NULL , V_495 } } ,
{ & V_289 ,
{ L_717 , L_718 , V_511 , 32 ,
F_305 ( & V_602 ) , 0x00000020 , NULL , V_495 } } ,
{ & V_288 ,
{ L_719 , L_720 , V_511 , 32 ,
F_305 ( & V_603 ) , 0x00000040 , NULL , V_495 } } ,
{ & V_344 ,
{ L_721 , L_722 , V_496 , V_494 ,
F_304 ( V_604 ) , 0x0 , NULL , V_495 } } ,
{ & V_36 ,
{ L_723 , L_724 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_31 ,
{ L_725 , L_726 ,
V_511 , 32 , F_305 ( & V_512 ) , V_605 ,
NULL , V_495 } } ,
{ & V_32 ,
{ L_727 , L_728 ,
V_511 , 32 , F_305 ( & V_512 ) , V_606 ,
NULL , V_495 } } ,
{ & V_33 ,
{ L_729 , L_730 ,
V_511 , 32 , F_305 ( & V_512 ) , V_607 ,
NULL , V_495 } } ,
{ & V_34 ,
{ L_731 , L_732 ,
V_511 , 32 , F_305 ( & V_512 ) , V_608 ,
NULL , V_495 } } ,
{ & V_287 ,
{ L_733 , L_734 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_281 ,
{ L_735 , L_736 ,
V_511 , 32 , F_305 ( & V_609 ) , V_610 ,
L_737 , V_495 } } ,
{ & V_285 ,
{ L_738 , L_739 ,
V_511 , 32 , F_305 ( & V_611 ) , V_612 ,
L_740 , V_495 } } ,
{ & V_286 ,
{ L_741 , L_742 ,
V_511 , 32 , F_305 ( & V_613 ) , V_614 ,
L_743 , V_495 } } ,
{ & V_282 ,
{ L_744 , L_745 ,
V_511 , 32 , F_305 ( & V_615 ) , V_616 ,
L_746 , V_495 } } ,
{ & V_283 ,
{ L_747 , L_748 ,
V_511 , 32 , F_305 ( & V_617 ) , V_618 ,
L_749 , V_495 } } ,
{ & V_284 ,
{ L_750 , L_751 ,
V_511 , 32 , F_305 ( & V_619 ) , V_620 ,
L_752 , V_495 } } ,
{ & V_343 ,
{ L_753 , L_754 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_78 ,
{ L_755 , L_756 , V_506 , V_507 ,
NULL , 0 , L_757 , V_495 } } ,
{ & V_81 ,
{ L_758 , L_759 , V_506 , V_507 ,
NULL , 0 , L_760 , V_495 } } ,
{ & V_80 ,
{ L_761 , L_762 , V_506 , V_507 ,
NULL , 0 , L_763 , V_495 } } ,
{ & V_79 ,
{ L_764 , L_765 , V_506 , V_507 ,
NULL , 0 , L_763 , V_495 } } ,
{ & V_132 ,
{ L_766 , L_767 , V_506 , V_507 ,
NULL , 0 , L_768 , V_495 } } ,
{ & V_82 ,
{ L_769 , L_770 , V_621 , V_503 ,
NULL , 0 , L_771 , V_495 } } ,
{ & V_83 ,
{ L_772 , L_773 , V_506 , V_507 ,
NULL , 0 , L_774 , V_495 } } ,
{ & V_84 ,
{ L_775 , L_776 , V_506 , V_507 ,
NULL , 0 , L_777 , V_495 } } ,
{ & V_214 ,
{ L_778 , L_779 , V_506 , V_507 ,
NULL , 0 , L_780 , V_495 } } ,
{ & V_213 ,
{ L_781 , L_782 , V_506 , V_507 ,
NULL , 0 , L_783 , V_495 } } ,
{ & V_231 ,
{ L_784 , L_785 , V_506 , V_507 ,
NULL , 0 , L_786 , V_495 } } ,
{ & V_232 ,
{ L_787 , L_788 , V_506 , V_507 ,
NULL , 0 , L_789 , V_495 } } ,
{ & V_243 ,
{ L_790 , L_791 , V_506 , V_507 ,
NULL , 0 , L_792 , V_495 } } ,
{ & V_245 ,
{ L_793 , L_794 , V_506 , V_507 ,
NULL , 0 , L_795 , V_495 } } ,
{ & V_228 ,
{ L_796 , L_797 , V_621 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_226 ,
{ L_798 , L_799 , V_621 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_405 ,
{ L_800 , L_801 , V_502 , V_503 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_426 ,
{ L_802 , L_803 , V_502 , V_503 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_427 ,
{ L_804 , L_805 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_183 ,
{ L_806 , L_807 , V_502 , V_503 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_191 ,
{ L_808 , L_809 , V_502 , V_503 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_452 ,
{ L_810 , L_811 , V_496 , V_497 ,
F_304 ( V_622 ) , 0x0 , NULL , V_495 } } ,
{ & V_453 ,
{ L_812 , L_813 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_446 ,
{ L_814 , L_815 , V_511 , 32 ,
NULL , 0x00000001 , NULL , V_495 } } ,
{ & V_447 ,
{ L_816 , L_817 , V_511 , 32 ,
NULL , 0x00000002 , NULL , V_495 } } ,
{ & V_448 ,
{ L_429 , L_818 , V_511 , 32 ,
NULL , 0x00000004 , NULL , V_495 } } ,
{ & V_449 ,
{ L_424 , L_819 , V_511 , 32 ,
NULL , 0x00000008 , NULL , V_495 } } ,
{ & V_450 ,
{ L_820 , L_821 , V_511 , 32 ,
NULL , 0x00000010 , NULL , V_495 } } ,
{ & V_457 ,
{ L_814 , L_822 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_458 ,
{ L_816 , L_823 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_462 ,
{ L_820 , L_824 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_460 ,
{ L_429 , L_825 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_461 ,
{ L_424 , L_826 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_110 ,
{ L_827 , L_828 , V_496 , V_494 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_108 ,
{ L_829 , L_830 , V_504 , V_503 ,
NULL , 0 , NULL , V_495 } } ,
{ & V_481 ,
{ L_831 , L_832 , V_623 , V_503 ,
NULL , 0x0 , L_833 , V_495 } } ,
{ & V_483 ,
{ L_834 , L_835 , V_493 , V_497 ,
F_304 ( V_624 ) , 0 , NULL , V_495 } } ,
{ & V_484 ,
{ L_836 , L_837 , V_493 , V_497 ,
F_304 ( V_625 ) , 0 , NULL , V_495 } } ,
{ & V_485 ,
{ L_317 , L_838 , V_502 , V_503 , NULL ,
0x0 , NULL , V_495 } } ,
{ & V_487 ,
{ L_839 , L_840 , V_502 , V_503 , NULL ,
0x0 , NULL , V_495 } } ,
{ & V_486 ,
{ L_841 , L_842 , V_502 , V_503 , NULL ,
0x0 , NULL , V_495 } } ,
{ & V_488 ,
{ L_843 , L_844 , V_502 , V_503 , NULL ,
0x0 , NULL , V_495 } } ,
{ & V_121 ,
{ L_845 , L_846 ,
V_511 , 32 , F_305 ( & V_626 ) , 0x00000001 ,
L_847 , V_495 } } ,
{ & V_120 ,
{ L_848 , L_849 ,
V_511 , 32 , F_305 ( & V_627 ) , 0x00000002 ,
L_850 , V_495 } } ,
{ & V_119 ,
{ L_851 , L_852 ,
V_511 , 32 , F_305 ( & V_628 ) , 0x00000004 ,
L_853 , V_495 } } ,
{ & V_129 ,
{ L_854 , L_855 ,
V_511 , 32 , F_305 ( & V_629 ) , 0x00000020 ,
L_856 , V_495 } } ,
{ & V_128 ,
{ L_857 , L_858 ,
V_511 , 32 , F_305 ( & V_630 ) , 0x00000200 ,
L_859 , V_495 } } ,
{ & V_53 ,
{ L_860 , L_861 ,
V_511 , 32 , F_305 ( & V_631 ) , 0x00010000 ,
L_862 , V_495 } } ,
{ & V_54 ,
{ L_863 , L_864 ,
V_511 , 32 , F_305 ( & V_632 ) , 0x00008000 ,
L_865 , V_495 } } ,
{ & V_55 ,
{ L_866 , L_867 ,
V_511 , 32 , F_305 ( & V_633 ) , 0x00004000 ,
L_868 , V_495 } } ,
{ & V_56 ,
{ L_869 , L_870 ,
V_511 , 32 , F_305 ( & V_634 ) , 0x00002000 ,
L_871 , V_495 } } ,
{ & V_57 ,
{ L_872 , L_873 ,
V_511 , 32 , F_305 ( & V_635 ) , 0x00001000 ,
L_874 , V_495 } } ,
{ & V_58 ,
{ L_875 , L_876 ,
V_511 , 32 , F_305 ( & V_636 ) , 0x00000800 ,
L_877 , V_495 } } ,
{ & V_59 ,
{ L_878 , L_879 ,
V_511 , 32 , F_305 ( & V_637 ) , 0x00000400 ,
L_880 , V_495 } } ,
{ & V_60 ,
{ L_881 , L_882 ,
V_511 , 32 , F_305 ( & V_638 ) , 0x00000200 ,
L_883 , V_495 } } ,
{ & V_61 ,
{ L_884 , L_885 ,
V_511 , 32 , F_305 ( & V_639 ) , 0x00000100 ,
L_886 , V_495 } } ,
{ & V_62 ,
{ L_887 , L_888 ,
V_511 , 32 , F_305 ( & V_640 ) , 0x00000080 ,
L_889 , V_495 } } ,
{ & V_63 ,
{ L_890 , L_891 ,
V_511 , 32 , F_305 ( & V_641 ) , 0x00000040 ,
L_892 , V_495 } } ,
{ & V_64 ,
{ L_893 , L_894 ,
V_511 , 32 , F_305 ( & V_642 ) , 0x00000020 ,
L_895 , V_495 } } ,
{ & V_65 ,
{ L_896 , L_897 ,
V_511 , 32 , F_305 ( & V_643 ) , 0x00000010 ,
L_898 , V_495 } } ,
{ & V_66 ,
{ L_899 , L_900 ,
V_511 , 32 , F_305 ( & V_644 ) , 0x00000008 ,
L_901 , V_495 } } ,
{ & V_67 ,
{ L_902 , L_903 ,
V_511 , 32 , F_305 ( & V_645 ) , 0x00000004 ,
L_904 , V_495 } } ,
{ & V_68 ,
{ L_905 , L_906 ,
V_511 , 32 , F_305 ( & V_646 ) , 0x00000002 ,
L_907 , V_495 } } ,
{ & V_69 ,
{ L_908 , L_909 ,
V_511 , 32 , F_305 ( & V_647 ) , 0x00000001 ,
L_910 , V_495 } } ,
#if 0
{ &hf_netlogon_dnsdomaininfo,
{ "DnsDomainInfo", "netlogon.dnsdomaininfo", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_349 ,
{ L_911 , L_912 , V_623 , V_503 , NULL , 0 , NULL , V_495 } } ,
{ & V_348 ,
{ L_911 , L_913 , V_623 , V_503 , NULL , 0 , NULL , V_495 } } ,
{ & V_350 ,
{ L_914 , L_915 , V_648 , V_503 , NULL , 0 , NULL , V_495 } } ,
{ & V_353 ,
{ L_916 , L_917 , V_623 , V_503 , NULL , 0 , NULL , V_495 } } ,
{ & V_352 ,
{ L_918 , L_919 , V_623 , V_503 , NULL , 0 , NULL , V_495 } } ,
{ & V_351 ,
{ L_920 , L_921 , V_623 , V_503 , NULL , 0 , NULL , V_495 } } ,
{ & V_167 ,
{ L_922 , L_923 , V_504 , V_503 ,
NULL , 0 , L_924 , V_495 } } ,
{ & V_168 ,
{ L_925 , L_926 , V_496 , V_497 ,
NULL , 0x0 , L_927 , V_495 } } ,
{ & V_166 ,
{ L_928 , L_929 , V_504 , V_503 ,
NULL , 0 , L_930 , V_495 } } ,
{ & V_94 ,
{ L_931 , L_932 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
{ & V_259 ,
{ L_933 , L_934 , V_496 , V_494 ,
NULL , 0x0 , NULL , V_495 } } ,
} ;
static T_2 * V_649 [] = {
& V_650 ,
& V_404 ,
& V_241 ,
& V_220 ,
& V_99 ,
& V_251 ,
& V_331 ,
& V_333 ,
& V_367 ,
& V_369 ,
& V_374 ,
& V_249 ,
& V_375 ,
& V_247 ,
& V_51 ,
& V_104 ,
& V_124 ,
& V_371 ,
& V_651 ,
& V_354 ,
& V_357 ,
& V_37 ,
& V_296 ,
& V_315 ,
& V_330 ,
& V_451 ,
& V_454 ,
& V_482 ,
& V_123 ,
& V_131 ,
& V_347 ,
& V_71
} ;
V_652 = F_306 (
L_935 , L_936 , L_937 ) ;
F_307 ( V_652 , V_491 ,
F_308 ( V_491 ) ) ;
F_309 ( V_649 , F_308 ( V_649 ) ) ;
F_310 ( F_299 ) ;
F_311 ( F_301 ) ;
}
void
F_312 ( void )
{
V_406 . V_407 = FALSE ;
V_406 . V_186 = 0 ;
F_313 ( V_652 , V_650 ,
& V_653 , V_654 ,
V_655 , V_492 ) ;
F_314 ( V_656 ,
V_657 ,
& V_658 ) ;
F_314 ( V_659 ,
V_657 ,
& V_658 ) ;
}
