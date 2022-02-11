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
F_10 ( V_26 , & V_18 -> V_23 ) ;
F_10 ( V_26 , & V_18 -> V_24 ) ;
return V_26 ;
}
static int
F_11 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_33 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_33 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_34 ) ;
}
F_15 ( V_9 , V_35 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_36 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_37 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_38 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
int
F_16 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 , int V_39 ,
T_14 * V_40 ,
void * V_41 )
{
T_13 * V_30 = ( T_13 * ) T_5 -> V_31 ;
T_15 V_42 , V_43 ;
V_44 ;
if ( V_30 -> V_32 )
return V_8 ;
#if 0
struct {
short len;
short size;
[size_is(size/2), length_is(len/2), ptr] unsigned short *string;
} HASH;
#endif
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_45 , & V_42 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_46 , & V_43 ) ;
V_8 = F_18 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_47 , V_48 ,
L_4 , V_39 , V_40 , V_41 ) ;
return V_8 ;
}
static int
F_19 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 , int V_39 , int T_16 V_6 ,
T_17 V_49 )
{
T_12 * V_29 ;
T_6 * V_50 = V_9 ;
if ( V_49 ) {
V_29 = F_20 (
V_9 , V_7 , V_8 , 0 , L_3 ,
F_21 ( V_39 ) ) ;
V_50 = F_14 ( V_29 , V_51 ) ;
}
return F_16 (
V_7 , V_8 , T_5 , V_50 , V_10 , V_39 ,
NULL , NULL ) ;
}
static int
F_22 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_52 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_52 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_53 ) ;
}
F_15 ( V_9 , V_54 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_55 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_56 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_57 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_58 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_59 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_60 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_61 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_62 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_63 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_64 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_65 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_66 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_67 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_68 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_69 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_70 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_23 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_5 ,
V_71 , 0 ) ;
return V_8 ;
}
static int
F_25 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_6 ,
V_72 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_73 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_74 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_75 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_76 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_77 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_78 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_79 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_80 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_81 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_82 , NULL ) ;
V_8 = F_26 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_83 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_7 , V_84 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_85 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_9 , V_86 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_27 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_10 , V_72 , V_89 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_11 , V_90 , 0 ) ;
return V_8 ;
}
static int
F_28 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_25 , V_48 ,
L_12 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_31 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
F_20 ( V_9 , V_7 , V_8 , 4 , L_13 ) ;
V_8 += 4 ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_32 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_10 , V_72 , V_89 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_11 , V_90 , 0 ) ;
return V_8 ;
}
static int
F_33 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_31 , V_88 ,
L_14 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_34 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_93 , NULL ) ;
return V_8 ;
}
static int
F_36 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_34 ) ;
return V_8 ;
}
static int
F_38 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_15 ) ;
V_9 = F_14 ( V_29 , V_95 ) ;
}
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_96 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_97 , NULL ) ;
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_98 , NULL ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_72 , 1 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_90 , 0 ) ;
#ifdef F_41
V_8 = F_42 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
#endif
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_44 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 V_6 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 16 ,
L_16 ) ;
V_9 = F_14 ( V_29 , V_51 ) ;
}
F_6 ( V_9 , V_99 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_45 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 V_6 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 16 ,
L_17 ) ;
V_9 = F_14 ( V_29 , V_100 ) ;
}
F_6 ( V_9 , V_101 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_46 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_44 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_45 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_47 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 V_6 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
F_6 ( V_9 , V_102 , V_7 , V_8 , 8 ,
V_15 ) ;
V_8 += 8 ;
return V_8 ;
}
static int
F_48 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_47 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
#if 0
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "NT ",
hf_netlogon_nt_owf_password, 0);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_data_length, NULL);
#endif
V_8 = F_19 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_103 , 0 , TRUE ) ;
V_8 = F_19 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_103 , 0 , TRUE ) ;
#if 0
offset = netlogon_dissect_LM_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_NT_OWF_PASSWORD(tvb, offset,
pinfo, tree, drep);
#endif
return V_8 ;
#if 0
offset = dissect_ndr_counted_byte_array_cb(
tvb, offset, pinfo, tree, drep, hf_netlogon_nt_chal_resp,
dissect_nt_chal_resp_cb,GINT_TO_POINTER(2));
offset = dissect_ndr_counted_byte_array(tvb, offset, pinfo, tree, drep,
hf_netlogon_lm_chal_resp, 0);
return offset;
#endif
}
static int
F_49 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_44 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_45 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_50 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_104 , 0 | V_105 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_106 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_88 ,
L_18 , - 1 ) ;
return V_8 ;
}
static int
F_51 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_15 V_107 = 0 ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_108 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_46 , V_48 ,
L_19 , - 1 ) ;
break;
case 2 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_48 , V_48 ,
L_20 , - 1 ) ;
break;
case 3 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_49 , V_48 ,
L_21 , - 1 ) ;
break;
case 4 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_50 , V_48 ,
L_22 , - 1 ) ;
break;
case 5 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_46 , V_48 ,
L_23 , - 1 ) ;
break;
case 6 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_48 , V_48 ,
L_24 , - 1 ) ;
break;
case 7 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_49 , V_48 ,
L_25 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_52 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 V_6 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
F_6 ( V_9 , V_109 , V_7 , V_8 , 8 ,
V_15 ) ;
V_8 += 8 ;
return V_8 ;
}
static int
F_53 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
T_18 V_110 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_52 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_44 ;
V_110 . V_111 = F_54 ( V_7 , V_8 ) ;
V_110 . V_112 = 0 ;
F_55 ( V_9 , V_113 , V_7 , V_8 , 4 , & V_110 ) ;
V_8 += 4 ;
return V_8 ;
}
static int
F_56 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_114 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_114 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_115 ) ;
}
F_15 ( V_9 , V_116 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_117 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_118 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_57 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_26 ) ;
V_9 = F_14 ( V_29 , V_119 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_120 , NULL ) ;
V_8 = F_56 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_58 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_57 ) ;
return V_8 ;
}
static int
F_59 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 V_6 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
F_6 ( V_9 , V_121 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_60 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_122 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_122 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_123 ) ;
}
F_15 ( V_9 , V_124 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_125 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_61 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_77 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_79 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_80 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_126 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_82 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_83 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_72 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_127 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_86 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_128 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_129 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_130 , 0 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_92 , NULL ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_131 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_120 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_133 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_58 , V_48 ,
L_27 , - 1 ) ;
V_8 = F_60 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_59 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_134 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_96 , 0 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_135 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_136 , NULL ) ;
V_8 = F_22 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_137 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_138 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_139 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_140 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_141 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_142 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_143 , NULL ) ;
return V_8 ;
}
static int
F_64 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_61 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
#if 0
int i;
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
for(i=0;i<2;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, drep);
for(i=0;i<7;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
#endif
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_144 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_145 , V_48 ,
L_28 , - 1 ) ;
return V_8 ;
}
static int
F_65 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_64 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_146 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_147 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_148 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_149 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_150 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_151 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_152 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_153 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_154 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_155 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_156 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_157 , 0 ) ;
return V_8 ;
}
int
F_66 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_158 ;
V_8 = F_61 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
#if 0
int i;
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_logoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_kickoff_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_last_set_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_can_change_time);
offset = dissect_ndr_nt_NTTIME(tvb, offset, pinfo, tree, drep,
hf_netlogon_pwd_must_change_time);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_acct_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_full_name, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_script, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_profile_path, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_home_dir, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_dir_drive, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_count16, NULL);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_bad_pw_count16, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_user_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_group_rid, NULL);
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_num_rids, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_GROUP_MEMBERSHIP_ARRAY, NDR_POINTER_UNIQUE,
"GROUP_MEMBERSHIP_ARRAY", -1);
offset = netlogon_dissect_USER_FLAGS(tvb, offset,
pinfo, tree, drep);
offset = netlogon_dissect_USER_SESSION_KEY(tvb, offset,
pinfo, tree, drep);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_srv, 0);
offset = dissect_ndr_counted_string(tvb, offset, pinfo, tree, drep,
hf_netlogon_logon_dom, 0);
offset = dissect_ndr_nt_PSID(tvb, offset, pinfo, tree, drep);
for(i=0;i<2;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
offset = netlogon_dissect_USER_ACCOUNT_CONTROL(tvb, offset,
pinfo, tree, drep);
for(i=0;i<7;i++){
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_long, NULL);
}
#endif
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_144 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_145 , V_48 ,
L_28 , - 1 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_159 , & V_158 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_58 , V_48 ,
L_29 , - 1 ) ;
return V_8 ;
}
static int
F_67 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_160 , 1 ) ;
return V_8 ;
}
static int
F_68 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_67 ) ;
return V_8 ;
}
int
F_69 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_161 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_162 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_68 , V_48 ,
L_30 , - 1 ) ;
return V_8 ;
}
static int
F_70 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_106 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_88 ,
L_31 , - 1 ) ;
return V_8 ;
}
static int
F_71 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_15 V_107 = 0 ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_163 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_25 , V_48 ,
L_32 , - 1 ) ;
break;
case 2 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_61 , V_48 ,
L_33 , - 1 ) ;
break;
case 3 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_64 , V_48 ,
L_34 , - 1 ) ;
break;
case 4 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_70 , V_48 ,
L_35 , - 1 ) ;
break;
case 5 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_70 , V_48 ,
L_36 , - 1 ) ;
break;
case 6 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_65 , V_48 ,
L_37 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_72 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_38 ,
V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_108 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_51 , V_88 ,
L_41 , - 1 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_163 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_73 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_71 , V_88 ,
L_42 , - 1 ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_164 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_74 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_38 ,
V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_108 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_51 , V_88 ,
L_41 , - 1 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_163 , NULL ) ;
return V_8 ;
}
static int
F_75 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_71 , V_88 ,
L_42 , - 1 ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_164 , NULL ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_76 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_38 ,
V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_108 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_51 , V_88 ,
L_43 , - 1 ) ;
return V_8 ;
}
static int
F_77 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static void F_78 ( T_4 * T_5 , unsigned char V_166 , T_9 * V_167 , char * V_20 )
{
if( V_166 ) {
V_167 -> V_22 = T_5 -> V_21 ;
V_167 -> V_21 = T_5 -> V_168 ;
F_79 ( & V_167 -> V_24 , & T_5 -> V_23 ) ;
F_79 ( & V_167 -> V_23 , & T_5 -> V_24 ) ;
V_167 -> V_20 = V_20 ;
}
else {
F_79 ( & V_167 -> V_24 , & T_5 -> V_24 ) ;
F_79 ( & V_167 -> V_23 , & T_5 -> V_23 ) ;
V_167 -> V_22 = T_5 -> V_168 ;
V_167 -> V_21 = T_5 -> V_21 ;
V_167 -> V_20 = V_20 ;
}
}
static int
F_80 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
T_19 * V_169 ;
T_19 * V_170 ;
T_9 * V_167 = ( T_9 * ) F_81 ( sizeof( T_9 ) ) ;
T_1 V_1 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_13 * V_30 = ( T_13 * ) T_5 -> V_31 ;
T_20 * V_171 = ( T_20 * ) V_30 -> V_172 ;
V_169 = ( T_19 * ) F_81 ( sizeof( T_19 ) ) ;
V_8 = F_23 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_18 (
V_7 , V_8 , T_5 , V_9 , V_10 ,
V_173 , V_88 ,
L_38 , V_84 ,
V_174 ,
F_82 ( V_89 | V_105 | 1 ) ) ;
F_2 ( L_44 , ( int ) strlen ( V_171 -> V_31 ) , V_8 , ( char * ) V_171 -> V_31 ) ;
V_169 -> V_175 = F_83 ( ( const T_1 * ) V_171 -> V_31 ) ;
F_2 ( L_45 , ( int ) strlen ( V_171 -> V_31 ) , V_8 , V_169 -> V_175 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_176 , & V_169 -> V_177 ) ;
memcpy ( V_1 , & V_169 -> V_177 , 8 ) ;
V_169 -> V_178 = T_5 -> V_179 -> V_180 ;
V_169 -> V_181 = - 1 ;
V_169 -> V_182 = NULL ;
F_78 ( T_5 , 0 , V_167 , NULL ) ;
V_170 = NULL ;
V_170 = ( T_19 * ) F_84 ( V_183 , V_167 ) ;
if ( ! V_170 ) {
F_2 ( L_46 , V_169 -> V_178 ) ;
F_85 ( V_183 , V_167 , V_169 ) ;
}
else {
while( V_170 -> V_182 != NULL && V_170 -> V_178 < V_169 -> V_178 ) {
F_2 ( L_47 ) ;
V_170 = V_170 -> V_182 ;
}
if( V_170 -> V_182 != NULL || V_170 -> V_178 == V_169 -> V_178 ) {
F_2 ( L_48 , V_169 -> V_178 ) ;
}
else {
F_2 ( L_49 , V_169 -> V_178 ) ;
V_170 -> V_181 = T_5 -> V_179 -> V_180 ;
V_170 -> V_182 = V_169 ;
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
existing_vars->next_start = pinfo->fd->num;
existing_vars->next = vars;
}
#endif
return V_8 ;
}
static int
F_86 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
T_19 * V_169 ;
T_9 V_167 ;
T_7 V_184 ;
F_78 ( T_5 , 1 , & V_167 , NULL ) ;
V_169 = ( T_19 * ) F_84 ( V_183 , ( T_8 * ) & V_167 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_185 , & V_184 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
if( V_169 != NULL ) {
while( V_169 != NULL && V_169 -> V_181 != - 1 && V_169 -> V_181 < ( int ) T_5 -> V_179 -> V_180 )
{
V_169 = V_169 -> V_182 ;
F_2 ( L_50 , V_169 -> V_181 , T_5 -> V_179 -> V_180 ) ;
}
if( V_169 == NULL )
{
F_2 ( L_51 ) ;
}
else
{
V_169 -> V_184 = V_184 ;
}
}
return V_8 ;
}
static int
F_87 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_186 , NULL ) ;
return V_8 ;
}
static int
F_88 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_52 , V_72 , V_89 ) ;
V_8 = F_87 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , V_89 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_52 , V_88 ,
L_53 , - 1 ) ;
return V_8 ;
}
static int
F_89 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_52 , V_88 ,
L_54 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_90 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 V_6 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
F_6 ( V_9 , V_187 , V_7 , V_8 , 16 ,
V_15 ) ;
V_8 += 16 ;
return V_8 ;
}
static int
F_91 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_52 , V_72 , 0 ) ;
V_8 = F_87 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_90 , V_88 ,
L_55 , - 1 ) ;
return V_8 ;
}
static int
F_92 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_93 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_56 , V_72 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_94 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
T_11 V_189 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_190 , & V_189 ) ;
F_6 ( V_9 , V_191 , V_7 , V_8 ,
V_189 , V_15 ) ;
V_8 += V_189 ;
return V_8 ;
}
static int
F_95 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_192 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_190 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_94 , V_48 ,
L_57 , - 1 ) ;
return V_8 ;
}
static int
F_96 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_72 , 3 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_127 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_120 , NULL ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_129 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_130 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_86 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_193 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_194 , 0 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_77 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_79 ) ;
V_8 = F_97 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_131 , NULL ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_92 , NULL ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_126 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_195 ) ;
V_8 = F_98 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_44 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_45 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_196 , NULL ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_197 , NULL ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_198 , NULL ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_199 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_200 , 0 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_201 , NULL ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_202 , NULL ) ;
V_8 = F_95 ( V_7 , V_8 , T_5 , V_9 ,
V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_100 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_85 , 3 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_204 , 0 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_80 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_205 , NULL ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_206 , NULL ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_83 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_82 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_207 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_208 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_101 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_209 , 3 ) ;
V_8 = F_57 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_210 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_102 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_30 -> V_39 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_30 -> V_39 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_103 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
return V_8 ;
}
static int
F_104 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_103 ) ;
return V_8 ;
}
static int
F_105 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_114 , NULL ) ;
return V_8 ;
}
static int
F_106 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_105 ) ;
return V_8 ;
}
static int
F_107 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_104 , V_48 ,
L_58 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_106 , V_48 ,
L_59 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_133 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_108 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_211 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_212 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_109 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_110 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_111 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_213 , NULL ) ;
return V_8 ;
}
static int
F_112 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_111 ) ;
return V_8 ;
}
static int
F_113 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_60 ) ;
V_9 = F_14 ( V_29 , V_214 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_215 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_216 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_217 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_218 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_219 , NULL ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_220 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_114 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_221 , NULL ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_222 ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_223 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_224 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_112 , V_48 ,
L_61 , - 1 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_85 , 0 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_113 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_225 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_226 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_115 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_227 , 0 ) ;
return V_8 ;
}
static int
F_116 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_115 ) ;
return V_8 ;
}
static int
F_117 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_85 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_228 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_116 , V_48 ,
L_62 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_118 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_114 , NULL ) ;
return V_8 ;
}
static int
F_119 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_118 ) ;
return V_8 ;
}
static int
F_120 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_229 , 1 ) ;
return V_8 ;
}
static int
F_121 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_120 ) ;
return V_8 ;
}
static int
F_122 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_230 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_231 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_119 , V_48 ,
L_63 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_121 , V_48 ,
L_64 , - 1 ) ;
V_8 = F_113 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_232 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_123 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
T_11 V_189 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_233 , NULL ) ;
V_8 += 4 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_234 , & V_189 ) ;
F_6 ( V_9 , V_30 -> V_39 , V_7 , V_8 ,
V_189 , V_15 ) ;
V_8 += V_189 ;
return V_8 ;
}
static int
F_124 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 , const char * V_20 , int V_39 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_3 , V_20 ) ;
V_9 = F_14 ( V_29 , V_235 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_234 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_233 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_123 , V_48 ,
V_20 , V_39 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_125 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_124 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ,
L_65 ,
V_236 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_237 ) ;
V_8 = F_124 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ,
L_66 ,
V_238 ) ;
V_8 = F_62 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_239 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_203 , NULL ) ;
V_8 = F_99 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_188 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_126 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_40 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_240 , NULL ) ;
return V_8 ;
}
static int
F_127 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
T_15 V_107 = 0 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_67 ) ;
V_9 = F_14 ( V_29 , V_241 ) ;
}
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_242 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_100 , V_48 ,
L_68 , - 1 ) ;
break;
case 2 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_101 , V_48 ,
L_69 , - 1 ) ;
break;
case 4 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_102 , V_48 ,
L_70 , V_209 ) ;
break;
case 5 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_96 , V_48 ,
L_71 , - 1 ) ;
break;
case 7 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_102 , V_48 ,
L_72 , V_72 ) ;
break;
case 8 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_107 , V_48 ,
L_73 , - 1 ) ;
break;
case 9 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_108 , V_48 ,
L_74 , - 1 ) ;
break;
case 11 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_102 , V_48 ,
L_75 , V_211 ) ;
break;
case 12 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_109 , V_48 ,
L_76 , - 1 ) ;
break;
case 13 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_114 , V_48 ,
L_77 , - 1 ) ;
break;
case 14 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_117 , V_48 ,
L_78 , - 1 ) ;
break;
case 16 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_122 , V_48 ,
L_79 , - 1 ) ;
break;
case 18 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_125 , V_48 ,
L_80 , - 1 ) ;
break;
case 20 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_93 , V_48 ,
L_81 , - 1 ) ;
break;
case 21 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_93 , V_48 ,
L_82 , - 1 ) ;
break;
case 22 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_126 , V_48 ,
L_83 , - 1 ) ;
break;
}
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_128 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
T_15 V_107 = 0 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_84 ) ;
V_9 = F_14 ( V_29 , V_243 ) ;
}
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_242 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_120 , NULL ) ;
break;
case 2 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 3 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 4 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 5 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 6 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 7 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 8 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 9 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 10 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 11 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 12 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 13 :
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
break;
case 14 :
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
break;
case 15 :
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
break;
case 16 :
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
break;
case 17 :
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
break;
case 18 :
V_8 = F_24 ( V_7 , V_8 , T_5 ,
V_9 , V_10 , V_48 , L_85 ,
V_244 , 0 ) ;
break;
case 19 :
V_8 = F_24 ( V_7 , V_8 , T_5 ,
V_9 , V_10 , V_48 , L_85 ,
V_244 , 0 ) ;
break;
case 20 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
case 21 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_132 , NULL ) ;
break;
}
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_129 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
T_15 type ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_86 ) ;
V_9 = F_14 ( V_29 , V_245 ) ;
}
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_242 , & type ) ;
F_130 ( V_29 , L_3 , F_131 (
type , V_246 , L_87 ) ) ;
V_8 = F_128 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_127 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_132 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_129 ) ;
return V_8 ;
}
static int
F_133 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_247 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_132 , V_48 ,
L_88 , - 1 ) ;
return V_8 ;
}
static int
F_134 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_5 , V_71 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_248 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_126 , V_88 ,
L_89 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_249 , NULL ) ;
return V_8 ;
}
static int
F_135 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_126 , V_88 ,
L_89 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_133 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_136 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_5 , V_71 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_248 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_250 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_249 , NULL ) ;
return V_8 ;
}
static int
F_137 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_250 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_133 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_138 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
F_6 ( V_9 , V_84 , V_7 , V_8 , 16 , V_251 | V_15 ) ;
V_8 += 16 ;
F_20 ( V_9 , V_7 , V_8 , 4 , L_91 ) ;
V_8 += 4 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_252 , NULL ) ;
return V_8 ;
}
static int
F_139 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_138 , V_88 ,
L_92 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_253 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_249 , NULL ) ;
return V_8 ;
}
static int
F_140 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_88 ,
L_93 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_253 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_255 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_138 , V_88 ,
L_92 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_141 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_256 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_249 , NULL ) ;
return V_8 ;
}
static int
F_142 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_88 ,
L_93 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_253 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_255 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_257 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_138 , V_88 ,
L_92 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_143 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_5 , V_71 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_85 , 0 ) ;
return V_8 ;
}
static int
F_144 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_227 , 0 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_145 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_258 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_259 , NULL ) ;
return V_8 ;
}
static int
F_146 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_258 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_259 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_94 ,
V_260 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_261 , NULL ) ;
return V_8 ;
}
static int
F_147 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_258 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_262 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_87 , NULL ) ;
return V_8 ;
}
static int
F_148 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_107 = 0 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_145 , V_48 ,
L_95 , - 1 ) ;
break;
case 2 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_146 , V_48 ,
L_96 , - 1 ) ;
break;
case 3 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_147 , V_48 ,
L_97 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_149 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_263 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , NULL ) ;
return V_8 ;
}
static int
F_150 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_148 , V_88 ,
L_98 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_151 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_5 ,
V_71 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_85 , 0 ) ;
return V_8 ;
}
static int
F_152 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_227 , 0 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_153 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_107 = 0 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 5 :
V_8 = F_24 ( V_7 , V_8 , T_5 ,
V_9 , V_10 , V_48 , L_99 ,
V_264 , 0 ) ;
break;
case 6 :
V_8 = F_24 ( V_7 , V_8 , T_5 ,
V_9 , V_10 , V_48 , L_99 ,
V_264 , 0 ) ;
break;
case 0xfffe :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
break;
case 8 :
V_8 = F_24 ( V_7 , V_8 , T_5 ,
V_9 , V_10 , V_48 , L_100 ,
V_266 , 0 ) ;
break;
}
return V_8 ;
}
static int
F_154 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_263 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_153 , V_88 ,
L_101 , - 1 ) ;
return V_8 ;
}
static int
F_155 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
T_11 V_267 ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_148 , V_88 ,
L_98 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_268 , & V_267 ) ;
if ( V_267 != 0 && F_156 ( T_5 -> V_269 , V_270 ) )
F_157 ( T_5 -> V_269 , V_270 , L_102 , F_131 ( V_267 , V_271 , L_103 ) ) ;
return V_8 ;
}
static int
F_158 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_5 , V_71 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_248 , NULL ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_272 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_250 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_249 , NULL ) ;
return V_8 ;
}
static int
F_159 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_250 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_133 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_160 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_5 , V_71 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_88 ,
L_104 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_221 , NULL ) ;
return V_8 ;
}
static int
F_161 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_133 , V_48 ,
L_90 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_162 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_263 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_153 , V_88 ,
L_101 , - 1 ) ;
return V_8 ;
}
static int
F_163 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_148 , V_88 ,
L_98 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_164 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_273 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_273 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_34 ) ;
}
F_15 ( V_9 , V_274 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_275 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_276 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_277 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_278 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_279 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_165 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_280 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_280 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_281 ) ;
}
F_15 ( V_9 , V_282 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_283 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_284 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_285 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_286 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_287 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_288 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_166 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_289 , & V_28 ) ;
if( V_27 ) {
V_29 = F_13 ( V_27 , V_289 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
V_9 = F_14 ( V_29 , V_290 ) ;
}
F_15 ( V_9 , V_291 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_292 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_293 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_294 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_295 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_296 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_297 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_298 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_299 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_300 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_301 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_302 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_303 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_304 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_305 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_306 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_307 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_167 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_28 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , NULL , V_10 ,
V_308 , & V_28 ) ;
if( V_27 ) {
V_29 = F_168 ( V_27 , V_308 ,
V_7 , V_8 - 4 , 4 , V_28 , L_105 , V_28 , ( V_28 == 0x0000ffff ) ? L_106 : L_107 ) ;
V_9 = F_14 ( V_29 , V_309 ) ;
}
F_15 ( V_9 , V_310 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_311 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_312 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_313 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_314 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_315 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_316 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_317 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_318 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_319 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_320 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_321 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
F_15 ( V_9 , V_322 ,
V_7 , V_8 - 4 , 4 , V_28 ) ;
return V_8 ;
}
static int
F_169 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_30 -> V_39 , NULL ) ;
return V_8 ;
}
static int
F_170 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_93 , NULL ) ;
return V_8 ;
}
static int
F_171 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_170 ) ;
return V_8 ;
}
static int
F_172 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_108 ) ;
V_9 = F_14 ( V_29 , V_323 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_324 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_171 , V_48 ,
L_85 , V_244 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_173 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_109 ) ;
V_9 = F_14 ( V_29 , V_325 ) ;
}
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_110 , V_227 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_111 , V_326 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_327 , NULL ) ;
V_8 = F_174 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_112 , V_96 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_113 , V_328 , 0 ) ;
V_8 = F_167 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_114 , V_329 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_115 ,
V_330 , 0 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_175 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_42 , V_331 ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_332 , & V_331 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_333 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_334 , & V_42 ) ;
if( V_331 * 2 == 16 ) {
V_8 = F_164 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_335 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_336 , NULL ) ;
V_8 = F_165 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
}
return V_8 ;
}
static int
F_176 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_42 ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_337 , & V_42 ) ;
F_6 ( V_9 , V_338 , V_7 , V_8 , V_42 ,
V_15 ) ;
V_8 += V_42 ;
return V_8 ;
}
static int
F_177 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 , int V_39 )
{
T_13 * V_30 = ( T_13 * ) T_5 -> V_31 ;
T_15 V_42 , V_43 ;
T_17 V_49 = TRUE ;
T_12 * V_29 ;
T_6 * V_50 = V_9 ;
if ( V_49 ) {
V_29 = F_20 (
V_9 , V_7 , V_8 , 0 , L_3 ,
F_21 ( V_39 ) ) ;
V_50 = F_14 ( V_29 , V_339 ) ;
}
V_44 ;
if ( V_30 -> V_32 )
return V_8 ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_45 , & V_42 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_46 , & V_43 ) ;
V_8 = F_18 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
F_175 , V_48 ,
L_116 , V_39 , NULL , NULL ) ;
return V_8 ;
}
static int
F_178 ( T_3 * V_7 V_6 , int V_8 V_6 , T_4 * T_5 V_6 , T_6 * V_9 V_6 , T_1 * V_10 V_6 )
{
V_8 = F_179 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_340 , 0 ) ;
return V_8 ;
}
static int
F_180 ( T_3 * V_7 , int V_8 , T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_181 ( V_7 , V_8 , T_5 , V_9 , V_10 , F_178 , V_48 , L_117 , V_341 ) ;
return V_8 ;
}
static int
F_182 ( T_3 * V_7 V_6 , int V_8 V_6 , T_4 * T_5 V_6 , T_6 * V_9 V_6 , T_1 * V_10 )
{
V_8 = F_183 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_342 , NULL ) ;
return V_8 ;
}
static int F_184 ( T_3 * V_7 , int V_8 , T_4 * T_5 , T_6 * V_9 , T_1 * V_10 , int V_39 V_6 , T_11 T_21 V_6 )
{
V_8 = F_185 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_343 , 0 ) ;
V_8 = F_185 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_344 , 0 ) ;
V_8 = F_185 ( V_7 , V_8 , T_5 , V_9 , V_10 , V_345 , 0 ) ;
V_8 = F_182 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_180 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_186 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_118 ) ;
V_9 = F_14 ( V_29 , V_346 ) ;
}
V_8 = F_184 ( V_7 , V_8 , T_5 , V_9 , V_10 , 0 , 0 ) ;
V_8 = F_177 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_347 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_149 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_150 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_151 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_135 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_136 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_348 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_137 , NULL ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_187 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_186 ) ;
return V_8 ;
}
static int
F_188 ( T_3 * V_7 V_6 , int V_8 ,
T_4 * T_5 V_6 , T_6 * V_9 V_6 ,
T_1 * V_10 V_6 )
{
T_12 * V_29 = NULL ;
T_6 * V_50 = NULL ;
T_11 V_42 ;
T_13 * V_30 ;
V_30 = ( T_13 * ) T_5 -> V_31 ;
if( V_30 -> V_32 ) {
return V_8 ;
}
if( V_9 ) {
V_29 = F_20 ( V_9 , V_7 , V_8 , 0 ,
L_119 ) ;
V_50 = F_14 ( V_29 , V_349 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_350 , & V_42 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
F_176 , V_48 ,
L_120 , - 1 ) ;
return V_8 ;
}
static int
F_189 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_188 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_121 ,
V_351 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_122 ,
V_352 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_123 , V_148 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_124 , V_149 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_125 , V_150 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_126 , V_151 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_353 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_354 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_150 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_151 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_355 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_136 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_348 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_137 , NULL ) ;
return V_8 ;
}
static int
F_190 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 ) {
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_189 , V_48 ,
L_127 , - 1 ) ;
return V_8 ;
}
static int
F_191 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_186 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_356 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_187 , V_48 ,
L_128 , - 1 ) ;
V_8 = F_188 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_357 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_149 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_150 , 0 ) ;
V_8 = F_39 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_151 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_355 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_358 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_348 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_137 , NULL ) ;
return V_8 ;
}
static int
F_192 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_107 = 0 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_191 , V_48 ,
L_129 , - 1 ) ;
break;
}
return V_8 ;
}
static int
F_193 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
int V_5 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_130 ) ;
V_9 = F_14 ( V_29 , V_359 ) ;
}
for( V_5 = 0 ; V_5 < 512 ; V_5 ++ ) {
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_360 , NULL ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_194 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_93 , NULL ) ;
return V_8 ;
}
static int
F_195 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_194 ) ;
return V_8 ;
}
static int
F_196 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_131 ) ;
V_9 = F_14 ( V_29 , V_361 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_195 , V_48 ,
L_85 , V_244 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_197 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_196 , V_48 ,
L_132 , - 1 ) ;
return V_8 ;
}
static int
F_198 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 , T_1 * V_10 )
{
T_11 V_362 ;
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_133 ) ;
V_9 = F_14 ( V_29 , V_363 ) ;
}
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_134 ,
V_364 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_135 ,
V_365 , 0 ) ;
V_8 = F_164 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_335 , & V_362 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_336 , & V_362 ) ;
V_8 = F_165 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_63 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_174 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_199 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_198 ) ;
return V_8 ;
}
static int
F_200 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_93 , NULL ) ;
return V_8 ;
}
static int
F_201 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_200 ) ;
return V_8 ;
}
static int
F_202 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_93 , NULL ) ;
return V_8 ;
}
static int
F_203 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_202 ) ;
return V_8 ;
}
static int
F_204 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_136 ) ;
V_9 = F_14 ( V_29 , V_366 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_201 , V_48 ,
L_85 , V_244 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_203 , V_48 ,
L_85 , V_244 ) ;
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_205 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_204 , V_48 ,
L_137 , - 1 ) ;
return V_8 ;
}
static int
F_206 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_27 ,
T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_9 = NULL ;
int V_94 = V_8 ;
T_11 V_107 = 0 ;
if( V_27 ) {
V_29 = F_20 ( V_27 , V_7 , V_8 , 0 ,
L_138 ) ;
V_9 = F_14 ( V_29 , V_367 ) ;
}
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , & V_107 ) ;
V_44 ;
switch( V_107 ) {
case 1 :
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
break;
}
F_43 ( V_29 , V_8 - V_94 ) ;
return V_8 ;
}
static int
F_207 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 ,
T_1 * V_10 )
{
T_11 V_107 ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_254 , & V_107 ) ;
if ( V_107 == 2 ) {
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_190 , V_48 ,
L_139 , - 1 ) ;
}
else {
if ( V_107 == 1 ) {
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_190 , V_48 ,
L_140 , - 1 ) ; }
}
return V_8 ;
}
static int
F_208 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_209 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_172 , V_88 ,
L_141 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_210 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_96 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_174 , V_48 ,
L_142 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_174 , V_48 ,
L_143 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_258 , NULL ) ;
return V_8 ;
}
static int
F_211 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_173 , V_48 ,
L_109 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_212 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
return V_8 ;
}
static int
F_213 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_206 , V_48 ,
L_145 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_214 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
return V_8 ;
}
static int
F_215 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_216 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
return V_8 ;
}
static int
F_217 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_169 , V_48 ,
L_146 , V_265 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_218 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_48 ,
L_147 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
return V_8 ;
}
static int
F_219 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
int V_5 ;
for( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_93 , NULL ) ;
}
return V_8 ;
}
static int
F_220 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_219 , V_48 ,
L_147 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_221 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_48 ,
L_147 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
return V_8 ;
}
static int
F_222 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_219 , V_48 ,
L_147 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int F_223 ( T_3 * V_7 , T_6 * V_9 , T_11 V_368 , int V_8 )
{
if ( V_9 ) {
T_6 * V_369 = NULL ;
T_12 * V_370 = NULL ;
V_370 = F_13 ( V_9 ,
V_371 ,
V_7 , V_8 , 4 , V_368 ) ;
V_369 = F_14 ( V_370 , V_372 ) ;
#if 0
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_80000000,
tvb, offset, 4, flags);
#endif
F_15 ( V_369 ,
V_373 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_374 ,
V_7 , V_8 , 4 , V_368 ) ;
#if 0
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_10000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_8000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_4000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_2000000,
tvb, offset, 4, flags);
proto_tree_add_boolean (negotiate_flags_tree,
hf_netlogon_neg_flags_800000,
tvb, offset, 4, flags);
#endif
F_15 ( V_369 ,
V_375 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_376 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_377 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_378 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_379 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_380 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_381 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_382 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_383 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_384 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_385 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_386 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_387 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_388 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_389 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_390 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_391 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_392 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_393 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_394 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_395 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_396 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_397 ,
V_7 , V_8 , 4 , V_368 ) ;
F_15 ( V_369 ,
V_398 ,
V_7 , V_8 , 4 , V_368 ) ;
}
return 0 ;
}
static int
F_224 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
T_11 V_368 ;
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_148 , V_72 , 0 ) ;
V_8 = F_87 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_38 , V_84 , 0 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_399 , NULL ) ;
#if 0
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_CREDENTIAL, NDR_POINTER_REF,
"Client Challenge", -1);
#endif
#if 0
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, drep,
hf_netlogon_neg_flags, NULL);
#endif
V_44 ;
V_368 = F_54 ( V_7 , V_8 ) ;
F_223 ( V_7 , V_9 , V_368 , V_8 ) ;
V_400 . V_401 = FALSE ;
V_400 . V_180 = 0 ;
V_8 += 4 ;
return V_8 ;
}
static int
F_225 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
return F_224 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
}
static void F_226 ( const char * V_402 , char * V_403 )
{
T_22 V_404 = 0 ;
T_22 V_5 ;
V_404 = strlen ( V_402 ) ;
if( V_403 != NULL )
{
for( V_5 = 0 ; V_5 < ( V_404 ) ; V_5 ++ )
{
V_403 [ V_5 * 2 ] = V_402 [ V_5 ] ;
V_403 [ V_5 * 2 + 1 ] = 0 ;
}
V_403 [ 2 * V_404 ] = '\0' ;
}
}
static T_11 F_227 ( T_23 * * V_405 , const char * T_24 V_6 )
{
#ifdef F_228
T_25 * V_406 ;
T_23 * V_407 ;
T_23 V_408 ;
int V_5 = 0 ;
T_11 V_409 = 0 ;
char V_410 [ 258 ] ;
int V_411 = 0 ;
int V_404 ;
if( ! V_412 ) {
* V_405 = NULL ;
return 0 ;
}
F_229 () ;
memset ( V_408 . V_413 , 0 , sizeof( T_23 ) ) ;
for( V_406 = V_414 ; V_406 ; V_406 = V_406 -> V_182 ) {
if( V_406 -> V_415 == 16 ) {
V_409 ++ ;
}
}
if ( T_24 [ 0 ] != '\0' && ( strlen ( T_24 ) < 129 ) ) {
V_409 ++ ;
F_2 ( L_149 , T_24 ) ;
V_404 = ( int ) strlen ( T_24 ) ;
F_226 ( T_24 , V_410 ) ;
F_230 ( V_408 . V_413 , V_410 , V_404 * 2 ) ;
F_1 ( V_408 . V_413 , 16 , L_150 , L_151 ) ;
V_411 = 1 ;
}
* V_405 = ( T_23 * ) F_231 ( V_409 * sizeof( T_23 ) ) ;
V_407 = * V_405 ;
if( V_411 ) {
memcpy ( V_407 [ 0 ] . V_413 , & ( V_408 . V_413 ) , sizeof( T_23 ) ) ;
V_5 ++ ;
}
for( V_406 = V_414 ; V_406 ; V_406 = V_406 -> V_182 ) {
if( V_406 -> V_415 == 16 ) {
memcpy ( V_407 [ V_5 ] . V_413 , V_406 -> V_416 , 16 ) ;
V_5 ++ ;
}
}
return V_409 ;
#else
* V_405 = NULL ;
return 0 ;
#endif
}
static int
F_232 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 , int V_417 )
{
T_11 V_368 ;
T_19 * V_169 ;
T_9 V_167 ;
T_7 V_418 ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_419 , & V_418 ) ;
V_368 = F_54 ( V_7 , V_8 ) ;
F_223 ( V_7 , V_9 , V_368 , V_8 ) ;
V_8 += 4 ;
V_44 ;
if( V_417 ) {
V_8 = F_233 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_420 , NULL ) ;
}
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
F_78 ( T_5 , 1 , & V_167 , NULL ) ;
V_169 = ( T_19 * ) F_84 ( V_183 , & V_167 ) ;
if( V_169 != NULL ) {
F_2 ( L_152 ) ;
F_2 ( L_153 , T_5 -> V_421 ) ;
while( V_169 != NULL && V_169 -> V_181 != - 1 && V_169 -> V_181 < ( int ) T_5 -> V_179 -> V_180 ) {
F_2 ( L_154 ) ;
V_169 = V_169 -> V_182 ;
}
if( V_169 == NULL ) {
F_2 ( L_155 ) ;
}
else {
T_23 * V_407 = NULL ;
T_11 V_422 = 0 ;
T_1 V_423 [ 16 ] ;
T_23 V_424 ;
int V_425 = 0 ;
unsigned int V_5 = 0 ;
V_169 -> V_368 = V_368 ;
V_169 -> V_426 = FALSE ;
V_422 = F_227 ( & V_407 , V_427 ) ;
F_2 ( L_156 , V_422 ) ;
if( V_368 & V_428 ) {
T_1 V_429 [ 4 ] ;
T_1 V_430 [ 16 ] ;
T_26 V_431 ;
T_1 V_432 [ 8 ] ;
T_7 V_433 ;
memset ( V_429 , 0 , 4 ) ;
F_234 ( & V_431 ) ;
F_235 ( & V_431 , V_429 , 4 ) ;
F_235 ( & V_431 , ( unsigned char * ) & V_169 -> V_177 , 8 ) ;
F_235 ( & V_431 , ( unsigned char * ) & V_169 -> V_184 , 8 ) ;
F_236 ( & V_431 , V_430 ) ;
F_1 ( V_430 , 8 , L_157 , L_151 ) ;
F_1 ( ( T_1 * ) & V_169 -> V_177 , 8 , L_158 , L_151 ) ;
F_1 ( ( T_1 * ) & V_169 -> V_184 , 8 , L_159 , L_151 ) ;
F_1 ( ( T_1 * ) & V_418 , 8 , L_160 , L_151 ) ;
for( V_5 = 0 ; V_5 < V_422 ; V_5 ++ )
{
V_424 = V_407 [ V_5 ] ;
F_237 ( V_430 , 16 , ( T_1 * ) & V_424 , 16 , V_423 ) ;
F_238 ( V_432 , ( unsigned char * ) & V_169 -> V_184 , V_423 , 1 ) ;
F_238 ( ( unsigned char * ) & V_433 , V_432 , V_423 + 7 , 1 ) ;
#if 0
printnbyte((guint8*)&calculated_cred,8,"Calculated creds:","\n");
#endif
if( V_433 == V_418 ) {
V_425 = 1 ;
break;
}
}
}
else if( V_368 & V_434 )
{
F_2 ( L_161 ) ;
memset ( V_423 , 0 , 16 ) ;
}
else
{
F_2 ( L_162 ) ;
memset ( V_423 , 0 , 16 ) ;
}
if( V_425 ) {
memcpy ( & V_169 -> V_423 , V_423 , 16 ) ;
F_2 ( L_163 ) ;
}
else {
F_2 ( L_164 ) ;
memset ( & V_169 -> V_423 , 0 , 16 ) ;
}
}
} else {
F_1 ( ( T_1 * ) & V_169 -> V_423 , 16 , L_165 , L_151 ) ;
}
return V_8 ;
}
static int
F_239 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
return F_232 ( V_7 , V_8 , T_5 , V_9 , V_10 , 1 ) ;
}
static int
F_240 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
return F_232 ( V_7 , V_8 , T_5 , V_9 , V_10 , 0 ) ;
}
static int
F_241 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_96 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_174 , V_48 ,
L_142 , - 1 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_166 , V_435 , 0 ) ;
V_8 = F_166 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_242 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_173 , V_48 ,
L_109 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_243 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_244 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_18 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_173 , V_48 , L_166 ,
V_435 , V_174 ,
F_82 ( V_89 | 1 ) ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_245 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_5 , V_84 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_38 ,
V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_167 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_207 , V_88 ,
L_168 , - 1 ) ;
return V_8 ;
}
static int
F_246 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_192 , V_88 ,
L_169 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_247 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_360 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_193 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_248 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_249 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_148 , V_72 , 0 ) ;
V_8 = F_87 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_38 ,
V_84 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
return V_8 ;
}
static int
F_250 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_40 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_44 , V_88 ,
L_170 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_251 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_88 ,
L_39 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_48 ,
L_147 , - 1 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
return V_8 ;
}
static int
F_252 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_53 , V_48 ,
L_40 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_253 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_48 ,
L_147 , - 1 ) ;
return V_8 ;
}
static int
F_254 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_197 , V_48 ,
L_171 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_255 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_172 ,
V_72 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_172 ,
V_96 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_174 , V_48 ,
L_173 , - 1 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_115 ,
V_435 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
return V_8 ;
}
static int
F_256 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_173 , V_48 ,
L_109 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_257 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_258 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_144 ,
V_244 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_169 , V_48 ,
L_146 , V_265 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_259 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_260 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_255 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_199 , V_48 ,
L_174 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_261 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_265 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_36 , V_48 ,
L_147 , - 1 ) ;
return V_8 ;
}
static int
F_262 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_205 , V_48 ,
L_137 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_263 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_264 (
V_7 , V_8 , T_5 , V_9 , V_10 , V_435 ,
V_174 ,
F_82 ( V_89 | 1 ) ) ;
return V_8 ;
}
static int
F_265 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_37 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_263 ) ;
return V_8 ;
}
static int
F_266 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_253 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_265 , V_48 ,
L_175 , - 1 ) ;
return V_8 ;
}
static int
F_267 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_268 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_266 , V_48 ,
L_176 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int
F_269 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_177 ,
V_84 , 0 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_38 ,
V_84 , 0 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_108 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_51 , V_88 ,
L_41 , - 1 ) ;
V_8 = F_17 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_163 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
#if 0
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_str_pointer_item(tvb, offset, pinfo, tree, drep,
NDR_POINTER_UNIQUE, "unknown string",
hf_netlogon_unknown_string, 0);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_LEVEL, NDR_POINTER_UNIQUE,
"LEVEL pointer: unknown_NETLOGON_LEVEL", -1);
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, drep,
hf_netlogon_unknown_short, NULL);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
#endif
return V_8 ;
}
static int
F_270 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_71 , V_88 ,
L_42 , - 1 ) ;
V_8 = F_35 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_164 , NULL ) ;
V_8 = F_11 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
#if 0
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_VALIDATION, NDR_POINTER_UNIQUE,
"VALIDATION: unknown_NETLOGON_VALIDATION", -1);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_char, NDR_POINTER_UNIQUE,
"BOOLEAN pointer: unknown_BOOLEAN", hf_netlogon_unknown_char);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
netlogon_dissect_pointer_long, NDR_POINTER_UNIQUE,
"ULONG pointer: unknown_ULONG", hf_netlogon_unknown_long);
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_netlogon_rc, NULL);
#endif
return V_8 ;
}
static int
F_271 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_164 ( V_7 , V_8 , T_5 , V_9 , V_10 ) ;
return V_8 ;
}
static int
F_272 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_255 , NULL ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_199 , V_48 ,
L_174 , - 1 ) ;
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_91 , NULL ) ;
return V_8 ;
}
static int
F_273 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_23 ( V_7 , V_8 ,
T_5 , V_9 , V_10 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_48 , L_8 , V_96 , 0 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_174 , V_48 ,
L_142 , - 1 ) ;
V_8 = F_29 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
F_174 , V_48 ,
L_178 , - 1 ) ;
V_8 = F_24 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_88 , L_179 , V_436 , 0 ) ;
return V_8 ;
}
static int
F_274 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_1 * V_10 )
{
V_8 = F_30 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_165 , NULL ) ;
return V_8 ;
}
static int F_275 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 ,
T_6 * V_9 , T_1 * V_10 )
{
T_12 * V_29 = NULL ;
T_6 * V_50 = NULL ;
T_11 V_437 , V_438 ;
static const int * V_439 [] = {
& V_440 ,
& V_441 ,
& V_442 ,
& V_443 ,
& V_444 ,
NULL
} ;
int V_42 ;
if ( V_9 ) {
V_29 = F_20 (
V_9 , V_7 , V_8 , - 1 ,
L_180 ) ;
V_50 = F_14 (
V_29 , V_445 ) ;
}
V_8 = F_233 (
V_7 , V_8 , T_5 , V_50 , V_10 ,
V_446 , & V_437 ) ;
F_276 ( V_50 , V_7 , V_8 , V_447 , V_448 , V_439 , ( V_10 [ 0 ] & V_14 ) ) ;
V_438 = ( ( V_10 [ 0 ] & V_14 )
? F_54 ( V_7 , V_8 )
: F_277 ( V_7 , V_8 ) ) ;
V_8 += 4 ;
if ( V_438 & 0x00000001 ) {
V_42 = F_278 ( V_7 , V_8 ) ;
F_6 ( V_50 , V_449 , V_7 , V_8 , V_42 , V_251 | V_15 ) ;
V_8 += V_42 ;
}
if ( V_438 & 0x00000002 ) {
V_42 = F_278 ( V_7 , V_8 ) ;
F_6 ( V_50 , V_450 , V_7 , V_8 , V_42 , V_251 | V_15 ) ;
V_8 += V_42 ;
}
if ( V_438 & 0x00000004 ) {
int V_94 = V_8 ;
char V_451 [ 256 ] ;
V_8 = F_279 ( V_7 , V_8 , V_451 , 255 , FALSE ) ;
F_280 ( V_50 , V_452 , V_7 , V_94 , V_8 - V_94 , V_451 ) ;
}
if ( V_438 & 0x00000008 ) {
int V_94 = V_8 ;
char V_451 [ 256 ] ;
V_8 = F_279 ( V_7 , V_8 , V_451 , 255 , FALSE ) ;
F_280 ( V_50 , V_453 , V_7 , V_94 , V_8 - V_94 , V_451 ) ;
}
if ( V_438 & 0x00000010 ) {
int V_94 = V_8 ;
char V_451 [ 256 ] ;
V_8 = F_279 ( V_7 , V_8 , V_451 , 255 , FALSE ) ;
F_280 ( V_50 , V_454 , V_7 , V_94 , V_8 - V_94 , V_451 ) ;
}
return V_8 ;
}
static int F_281 ( const T_1 * V_423 , int V_455 , T_7 V_456 , T_1 * V_457 )
{
T_1 V_429 [ 4 ] ;
T_1 * V_432 = ( T_1 * ) F_282 ( V_455 ) ;
T_1 V_458 [ 16 ] ;
T_1 V_459 [ 16 ] ;
int V_5 = 0 ;
memset ( V_459 , 0 , 16 ) ;
memset ( V_457 , 0 , 16 ) ;
if( memcmp ( V_423 , V_459 , 16 ) ) {
memset ( V_429 , 0 , 4 ) ;
for( V_5 = 0 ; V_5 < V_455 ; V_5 ++ ) {
V_432 [ V_5 ] = V_423 [ V_5 ] ^ 0xF0 ;
}
F_237 ( V_429 , 4 , V_432 , V_455 , V_458 ) ;
F_237 ( ( T_1 * ) & V_456 , 8 , V_458 , 16 , V_457 ) ;
F_283 ( V_432 ) ;
return 1 ;
}
else {
F_283 ( V_432 ) ;
return 0 ;
}
}
static T_7 F_284 ( T_1 * V_423 , T_7 V_460 , T_7 V_461 , unsigned char V_166 V_6 )
{
T_1 V_429 [ 4 ] ;
T_1 V_432 [ 16 ] ;
T_1 V_167 [ 16 ] ;
T_27 V_462 ;
T_1 * V_463 = ( T_1 * ) & V_461 ;
memset ( V_429 , 0 , 4 ) ;
F_237 ( V_429 , 4 , V_423 , 16 , V_432 ) ;
F_237 ( ( T_1 * ) & V_460 , 8 , V_432 , 16 , V_167 ) ;
F_285 ( & V_462 , V_167 , 16 ) ;
F_286 ( & V_462 , V_463 , 8 ) ;
return V_461 ;
}
static T_3 *
F_287 ( T_3 * V_7 , T_3 * T_28 V_6 ,
int V_8 , T_4 * T_5 , T_29 * T_30 V_6 , unsigned char V_166 )
{
T_3 * V_432 = NULL ;
T_1 * V_464 ;
T_19 * V_169 ;
T_9 V_167 ;
F_78 ( T_5 , V_166 , & V_167 , NULL ) ;
V_169 = ( T_19 * ) F_84 ( V_183 , & V_167 ) ;
if( V_169 != NULL ) {
while( V_169 != NULL && V_169 -> V_181 != - 1 && V_169 -> V_181 < ( int ) T_5 -> V_179 -> V_180 ) {
V_169 = V_169 -> V_182 ;
}
if( V_169 == NULL ) {
F_2 ( L_181 , F_288 ( V_183 ) ) ;
return ( V_432 ) ;
}
else {
if( V_169 -> V_426 == TRUE ) {
T_27 V_462 ;
int V_189 ;
T_7 V_465 = V_169 -> V_466 ;
V_189 = F_289 ( V_7 , V_8 ) ;
if ( V_189 < 0 ) {
return NULL ;
}
F_285 ( & V_462 , V_169 -> V_467 , 16 ) ;
F_286 ( & V_462 , ( T_1 * ) & V_465 , 8 ) ;
V_464 = ( T_1 * ) F_290 ( V_7 , V_8 , V_189 ) ;
F_285 ( & V_462 , V_169 -> V_467 , 16 ) ;
F_286 ( & V_462 , V_464 , V_189 ) ;
V_432 = F_291 ( V_7 , V_464 , V_189 , V_189 ) ;
}
else {
F_2 ( L_182 ) ;
}
}
} else {
F_2 ( L_183 , F_288 ( V_183 ) ) ;
return ( V_432 ) ;
}
return ( V_432 ) ;
}
static T_3 * F_292 ( T_3 * V_7 , T_3 * T_28 ,
int V_8 , T_4 * T_5 , T_29 * T_30 )
{
return F_287 ( V_7 , T_28 , V_8 , T_5 , T_30 , 0 ) ;
}
static T_3 * F_293 ( T_3 * V_7 , T_3 * T_28 ,
int V_8 , T_4 * T_5 , T_29 * T_30 )
{
return F_287 ( V_7 , T_28 , V_8 , T_5 , T_30 , 1 ) ;
}
static int
F_294 ( T_3 * V_7 , int V_8 , T_4 * T_5 V_6 ,
T_6 * V_9 , T_1 * V_10 V_6 , unsigned char V_166 )
{
T_19 * V_169 ;
T_9 V_167 ;
T_12 * V_468 = NULL ;
T_6 * V_50 = NULL ;
T_7 V_469 ;
T_7 V_470 ;
T_7 V_466 = 0 ;
int V_471 = 0 ;
F_78 ( T_5 , V_166 , & V_167 , NULL ) ;
V_169 = ( T_19 * ) F_84 ( V_183 , ( T_8 * ) & V_167 ) ;
if( ! ( V_400 . V_401 && V_400 . V_180 == T_5 -> V_179 -> V_180 ) ) {
V_468 = F_6 ( V_9 , V_472 , V_7 ,
V_8 , - 1 , V_15 ) ;
V_50 = F_14 ( V_468 , V_473 ) ;
F_6 ( V_50 , V_474 , V_7 ,
V_8 , 2 , V_475 ) ;
F_6 ( V_50 , V_476 , V_7 ,
V_8 + 2 , 2 , V_475 ) ;
F_6 ( V_50 , V_477 , V_7 ,
V_8 + 6 , 2 , V_15 ) ;
V_8 += 8 ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_478 , & V_469 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_479 , & V_470 ) ;
if ( F_295 ( V_7 , V_8 , 8 ) ) {
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_480 , & V_466 ) ;
}
V_471 = 1 ;
}
if( V_169 != NULL ) {
while( V_169 != NULL && V_169 -> V_181 != - 1 && V_169 -> V_181 < ( int ) T_5 -> V_179 -> V_180 ) {
V_169 = V_169 -> V_182 ;
}
if( V_169 == NULL ) {
F_2 ( L_181 , F_288 ( V_183 ) ) ;
return ( V_8 ) ;
}
else {
if( V_471 ) {
V_169 -> V_466 = V_466 ;
V_169 -> V_481 = F_284 ( V_169 -> V_423 , V_470 , V_469 , V_166 ) ;
}
if( F_281 ( V_169 -> V_423 , 16 , V_169 -> V_481 , V_169 -> V_467 ) )
{
V_169 -> V_426 = TRUE ;
}
else
{
F_2 ( L_184 ) ;
}
}
}
else
{
F_2 ( L_185 , V_169 == NULL , F_288 ( V_183 ) ) ;
}
V_400 . V_401 = TRUE ;
V_400 . V_180 = T_5 -> V_179 -> V_180 ;
return V_8 ;
}
static int
F_296 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_1 * V_10 )
{
return F_294 ( V_7 , V_8 , T_5 , V_9 , V_10 , 0 ) ;
}
static int
F_297 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_1 * V_10 )
{
return F_294 ( V_7 , V_8 , T_5 , V_9 , V_10 , 1 ) ;
}
static void
F_298 ( void )
{
if ( V_183 ) {
F_299 ( V_183 ) ;
}
V_183 = F_300 ( F_9 , F_7 ) ;
if ( V_482 ) {
F_299 ( V_482 ) ;
}
V_482 = F_300 ( F_9 , F_7 ) ;
}
void
F_301 ( void )
{
static T_31 V_483 [] = {
{ & V_484 ,
{ L_186 , L_187 , V_485 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_165 , {
L_188 , L_189 , V_488 , V_489 ,
F_302 ( V_490 ) , 0x0 , L_190 , V_487 } } ,
{ & V_91 ,
{ L_191 , L_192 , V_488 ,
V_489 , F_302 ( V_491 ) , 0x0 , NULL , V_487 } } ,
{ & V_268 ,
{ L_193 , L_194 , V_488 ,
V_489 , F_302 ( V_271 ) , 0x0 , NULL , V_487 } } ,
{ & V_97 , {
L_195 , L_196 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_98 , {
L_197 , L_198 , V_492 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_240 , {
L_199 , L_200 , V_492 , V_486 ,
NULL , 0x0 , L_201 , V_487 } } ,
{ & V_203 , {
L_202 , L_203 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_253 , {
L_204 , L_205 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_255 , {
L_206 , L_207 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_109 , {
L_208 , L_209 , V_493 , V_494 ,
NULL , 0x0 , L_210 , V_487 } } ,
{ & V_102 , {
L_211 , L_212 , V_493 , V_494 ,
NULL , 0x0 , L_213 , V_487 } } ,
{ & V_99 , {
L_214 , L_215 , V_493 , V_494 ,
NULL , 0x0 , L_216 , V_487 } } ,
{ & V_121 , {
L_217 , L_218 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_187 , {
L_219 , L_220 , V_493 , V_494 ,
NULL , 0x0 , L_221 , V_487 } } ,
{ & V_101 , {
L_222 , L_223 , V_493 , V_494 ,
NULL , 0x0 , L_224 , V_487 } } ,
{ & V_338 , {
L_225 , L_226 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_324 , {
L_227 , L_228 , V_488 , V_486 ,
NULL , 0 , L_229 , V_487 } } ,
{ & V_73 , {
L_230 , L_231 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_230 , {
L_232 , L_233 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_231 , {
L_234 , L_235 , V_488 , V_489 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_229 , {
L_236 , L_237 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_259 , {
L_238 , L_239 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_261 , {
L_240 , L_241 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_114 , {
L_242 , L_243 , V_488 , V_489 ,
NULL , 0 , NULL , V_487 } } ,
#if 0
{ &hf_netlogon_lsapolicy_referentid,
{ "Referent ID", "netlogon.lsapolicy.referentID", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_350 ,
{ L_229 , L_244 , V_488 , V_486 ,
NULL , 0x0 , L_245 , V_487 } } ,
#if 0
{ &hf_netlogon_lsapolicy_pointer,
{ "Pointer", "netlogon.lsapolicy.pointer", FT_BYTES, BASE_NONE,
NULL, 0x0, "Pointer to LSA POLICY", HFILL }},
#endif
{ & V_244 ,
{ L_246 , L_247 , V_495 , V_494 ,
NULL , 0 , L_248 , V_487 } } ,
{ & V_264 ,
{ L_249 , L_250 , V_495 , V_494 ,
NULL , 0 , L_251 , V_487 } } ,
{ & V_266 ,
{ L_100 , L_252 , V_495 , V_494 ,
NULL , 0 , L_253 , V_487 } } ,
{ & V_148 ,
{ L_254 , L_255 , V_495 , V_494 ,
NULL , 0 , L_256 , V_487 } } ,
{ & V_347 ,
{ L_257 , L_258 , V_495 , V_494 ,
NULL , 0 , L_259 , V_487 } } ,
{ & V_333 ,
{ L_260 , L_261 , V_488 , V_486 ,
NULL , 0 , L_259 , V_487 } } ,
{ & V_334 ,
{ L_229 , L_262 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_332 ,
{ L_263 , L_264 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_149 ,
{ L_265 , L_255 , V_495 , V_494 ,
NULL , 0 , L_266 , V_487 } } ,
{ & V_150 ,
{ L_267 , L_255 , V_495 , V_494 ,
NULL , 0 , L_268 , V_487 } } ,
{ & V_151 ,
{ L_269 , L_255 , V_495 , V_494 ,
NULL , 0 , L_270 , V_487 } } ,
{ & V_152 ,
{ L_271 , L_255 , V_495 , V_494 ,
NULL , 0 , L_272 , V_487 } } ,
{ & V_153 ,
{ L_273 , L_255 , V_495 , V_494 ,
NULL , 0 , L_274 , V_487 } } ,
{ & V_154 ,
{ L_275 , L_255 , V_495 , V_494 ,
NULL , 0 , L_276 , V_487 } } ,
{ & V_155 ,
{ L_277 , L_255 , V_495 , V_494 ,
NULL , 0 , L_278 , V_487 } } ,
{ & V_156 ,
{ L_279 , L_255 , V_495 , V_494 ,
NULL , 0 , L_280 , V_487 } } ,
{ & V_157 ,
{ L_281 , L_255 , V_495 , V_494 ,
NULL , 0 , L_282 , V_487 } } ,
{ & V_265 ,
{ L_283 , L_284 , V_488 , V_489 ,
NULL , 0x0 , L_285 , V_487 } } ,
{ & V_135 ,
{ L_286 , L_287 , V_488 , V_489 ,
NULL , 0x0 , L_288 , V_487 } } ,
{ & V_136 ,
{ L_289 , L_290 , V_488 , V_489 ,
NULL , 0x0 , L_291 , V_487 } } ,
{ & V_348 ,
{ L_292 , L_293 , V_488 , V_489 ,
NULL , 0x0 , L_294 , V_487 } } ,
{ & V_137 ,
{ L_295 , L_296 , V_488 , V_489 ,
NULL , 0x0 , L_297 , V_487 } } ,
{ & V_138 ,
{ L_298 , L_299 , V_488 , V_489 ,
NULL , 0x0 , L_300 , V_487 } } ,
{ & V_139 ,
{ L_301 , L_302 , V_488 , V_489 ,
NULL , 0x0 , L_303 , V_487 } } ,
{ & V_140 ,
{ L_304 , L_305 , V_488 , V_489 ,
NULL , 0x0 , L_306 , V_487 } } ,
{ & V_141 ,
{ L_307 , L_308 , V_488 , V_489 ,
NULL , 0x0 , L_309 , V_487 } } ,
{ & V_142 ,
{ L_310 , L_311 , V_488 , V_489 ,
NULL , 0x0 , L_312 , V_487 } } ,
{ & V_143 ,
{ L_313 , L_314 , V_488 , V_489 ,
NULL , 0x0 , L_315 , V_487 } } ,
{ & V_358 ,
{ L_316 , L_317 , V_488 , V_489 ,
NULL , 0x0 , L_318 , V_487 } } ,
{ & V_355 ,
{ L_319 , L_320 , V_488 , V_489 ,
NULL , 0x0 , L_321 , V_487 } } ,
{ & V_87 ,
{ L_322 , L_323 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_360 ,
{ L_324 , L_325 , V_485 , V_489 ,
NULL , 0x0 , L_326 , V_487 } } ,
{ & V_93 ,
{ L_327 , L_328 , V_496 , V_489 ,
NULL , 0x0 , L_329 , V_487 } } ,
{ & V_195 ,
{ L_330 , L_331 , V_497 , V_498 ,
NULL , 0x0 , L_332 , V_487 } } ,
{ & V_196 ,
{ L_333 , L_334 , V_496 , V_489 ,
NULL , 0x0 , L_335 , V_487 } } ,
{ & V_197 ,
{ L_336 , L_337 , V_496 , V_489 ,
NULL , 0x0 , L_338 , V_487 } } ,
{ & V_198 ,
{ L_339 , L_340 , V_496 , V_489 ,
NULL , 0x0 , L_341 , V_487 } } ,
{ & V_164 ,
{ L_342 , L_343 , V_496 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_192 ,
{ L_344 , L_345 , V_496 , V_486 ,
NULL , 0x0 , L_346 , V_487 } } ,
{ & V_223 ,
{ L_347 , L_348 , V_496 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_224 ,
{ L_349 , L_350 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_213 ,
{ L_351 , L_352 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_190 ,
{ L_229 , L_353 , V_488 , V_486 ,
NULL , 0x0 , L_354 , V_487 } } ,
#if 0
{ &hf_netlogon_nt_chal_resp,
{ "NT Chal resp", "netlogon.nt_chal_resp", FT_BYTES, BASE_NONE,
NULL, 0, "Challenge response for NT authentication", HFILL }},
#endif
{ & V_103 ,
{ L_355 , L_356 , V_493 , V_494 ,
NULL , 0 , L_357 , V_487 } } ,
{ & V_234 ,
{ L_358 , L_359 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_233 ,
{ L_360 , L_361 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
#if 0
{ &hf_netlogon_pac_data,
{ "Pac Data", "netlogon.pac.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_191 ,
{ L_362 , L_363 , V_493 , V_494 ,
NULL , 0 , L_344 , V_487 } } ,
#if 0
{ &hf_netlogon_auth_data,
{ "Auth Data", "netlogon.auth.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_236 ,
{ L_364 , L_365 , V_493 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_238 ,
{ L_366 , L_367 , V_493 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_72 ,
{ L_148 , L_368 , V_495 , V_494 ,
NULL , 0 , L_56 , V_487 } } ,
{ & V_193 ,
{ L_369 , L_370 , V_495 , V_494 ,
NULL , 0 , L_371 , V_487 } } ,
{ & V_210 ,
{ L_372 , L_373 , V_495 , V_494 ,
NULL , 0 , L_374 , V_487 } } ,
{ & V_127 ,
{ L_375 , L_376 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_199 ,
{ L_377 , L_378 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_200 ,
{ L_379 , L_380 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_86 ,
{ L_381 , L_382 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_128 ,
{ L_383 , L_384 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_129 ,
{ L_385 , L_386 , V_495 , V_494 ,
NULL , 0 , L_387 , V_487 } } ,
{ & V_130 ,
{ L_388 , L_389 , V_495 , V_494 ,
NULL , 0 , L_390 , V_487 } } ,
{ & V_134 ,
{ L_391 , L_392 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
#if 0
{ &hf_netlogon_principal,
{ "Principal", "netlogon.principal", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_96 ,
{ L_8 , L_393 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_159 ,
{ L_394 , L_395 , V_488 , V_486 ,
NULL , 0 , L_396 , V_487 } } ,
{ & V_84 ,
{ L_38 , L_397 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_435 ,
{ L_166 , L_398 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_227 ,
{ L_110 , L_399 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_329 ,
{ L_400 , L_401 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_328 ,
{ L_402 , L_403 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_326 ,
{ L_111 , L_404 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_327 ,
{ L_405 , L_406 , V_488 , V_486 ,
F_302 ( V_499 ) , 0 , NULL , V_487 } } ,
{ & V_330 ,
{ L_407 , L_408 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_352 ,
{ L_409 , L_410 , V_495 , V_494 ,
NULL , 0 , L_411 , V_487 } } ,
{ & V_90 ,
{ L_412 , L_413 , V_495 , V_494 ,
NULL , 0 , L_414 , V_487 } } ,
{ & V_353 ,
{ L_415 , L_416 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_354 ,
{ L_417 , L_418 , V_495 , V_494 ,
NULL , 0 , L_419 , V_487 } } ,
{ & V_194 ,
{ L_420 , L_421 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_351 ,
{ L_422 , L_423 , V_495 , V_494 ,
NULL , 0 , L_121 , V_487 } } ,
{ & V_209 ,
{ L_424 , L_425 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_211 ,
{ L_426 , L_427 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_436 ,
{ L_428 , L_429 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_364 ,
{ L_430 , L_431 , V_495 , V_494 ,
NULL , 0 , L_432 , V_487 } } ,
{ & V_365 ,
{ L_433 , L_434 , V_495 , V_494 ,
NULL , 0 , L_135 , V_487 } } ,
{ & V_357 ,
{ L_435 , L_436 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_85 ,
{ L_8 , L_393 , V_495 , V_494 ,
NULL , 0 , L_437 , V_487 } } ,
{ & V_204 ,
{ L_438 , L_439 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_260 ,
{ L_440 , L_441 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_146 ,
{ L_442 , L_443 , V_495 , V_494 ,
NULL , 0 , L_444 , V_487 } } ,
{ & V_147 ,
{ L_445 , L_446 , V_495 , V_494 ,
NULL , 0 , L_447 , V_487 } } ,
{ & V_71 ,
{ L_448 , L_449 , V_495 , V_494 ,
NULL , 0 , L_450 , V_487 } } ,
{ & V_188 ,
{ L_451 , L_452 , V_495 , V_494 ,
NULL , 0 , L_453 , V_487 } } ,
{ & V_92 ,
{ L_454 , L_455 , V_485 , V_486 ,
NULL , 0x0 , L_456 , V_487 } } ,
{ & V_75 ,
{ L_454 , L_457 , V_488 , V_486 ,
NULL , 0x0 , L_456 , V_487 } } ,
{ & V_131 ,
{ L_458 , L_459 , V_485 , V_486 ,
NULL , 0x0 , L_460 , V_487 } } ,
{ & V_76 ,
{ L_458 , L_461 , V_488 , V_486 ,
NULL , 0x0 , L_460 , V_487 } } ,
{ & V_201 ,
{ L_462 , L_463 , V_485 , V_486 ,
F_302 ( V_500 ) , 0x0 , L_464 , V_487 } } ,
{ & V_202 ,
{ L_465 , L_466 , V_485 , V_486 ,
NULL , 0x0 , L_467 , V_487 } } ,
{ & V_108 ,
{ L_468 , L_469 , V_485 , V_486 ,
NULL , 0x0 , L_470 , V_487 } } ,
{ & V_163 ,
{ L_471 , L_472 , V_485 , V_486 ,
NULL , 0x0 , L_473 , V_487 } } ,
{ & V_205 ,
{ L_474 , L_475 , V_485 , V_486 ,
NULL , 0x0 , L_476 , V_487 } } ,
{ & V_206 ,
{ L_477 , L_478 , V_485 , V_486 ,
NULL , 0x0 , L_479 , V_487 } } ,
{ & V_186 ,
{ L_480 , L_481 , V_485 , V_486 ,
F_302 ( V_501 ) , 0x0 , L_482 , V_487 } } ,
{ & V_272 ,
{ L_483 , L_484 , V_485 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_242 ,
{ L_485 , L_486 , V_485 , V_486 ,
F_302 ( V_246 ) , 0x0 , NULL , V_487 } } ,
{ & V_337 ,
{ L_487 , L_488 , V_488 , V_486 ,
NULL , 0x0 , L_489 , V_487 } } ,
{ & V_263 ,
{ L_490 , L_491 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_254 ,
{ L_468 , L_492 , V_488 , V_486 ,
NULL , 0x0 , L_470 , V_487 } } ,
{ & V_256 ,
{ L_493 , L_494 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_257 ,
{ L_495 , L_496 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_113 ,
{ L_497 , L_498 , V_497 , V_498 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_132 ,
{ L_499 , L_500 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_212 ,
{ L_501 , L_502 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_120 ,
{ L_503 , L_504 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_133 ,
{ L_505 , L_506 , V_488 , V_486 ,
NULL , 0x0 , L_507 , V_487 } } ,
{ & V_228 ,
{ L_508 , L_509 , V_488 , V_486 ,
NULL , 0x0 , L_510 , V_487 } } ,
{ & V_144 ,
{ L_511 , L_512 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_258 ,
{ L_321 , L_513 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_52 ,
{ L_514 , L_515 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_122 ,
{ L_516 , L_517 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_74 ,
{ L_518 , L_519 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_232 ,
{ L_520 , L_521 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_248 ,
{ L_522 , L_523 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_250 ,
{ L_524 , L_525 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_249 ,
{ L_526 , L_527 , V_488 , V_486 ,
NULL , 0x0 , L_528 , V_487 } } ,
{ & V_221 ,
{ L_529 , L_530 , V_488 , V_486 ,
NULL , 0x0 , L_531 , V_487 } } ,
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
{ & V_247 ,
{ L_532 , L_533 , V_488 , V_486 ,
NULL , 0x0 , L_534 , V_487 } } ,
{ & V_356 ,
{ L_535 , L_536 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_262 ,
{ L_537 , L_538 , V_488 , V_486 ,
NULL , 0x0 , L_539 , V_487 } } ,
{ & V_219 ,
{ L_540 , L_541 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_215 ,
{ L_542 , L_543 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_216 ,
{ L_544 , L_545 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_217 ,
{ L_546 , L_547 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_218 ,
{ L_548 , L_549 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_252 ,
{ L_550 , L_551 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_371 ,
{ L_552 , L_553 , V_488 , V_489 ,
NULL , 0x0 , L_554 , V_487 } } ,
#if 0
{ &hf_netlogon_neg_flags_80000000,
{ "Not used 80000000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_80000000, "Not used", HFILL }},
#endif
{ & V_373 ,
{ L_555 , L_556 , V_502 , 32 , F_303 ( & V_503 ) , V_504 , NULL , V_487 } } ,
{ & V_374 ,
{ L_557 , L_556 , V_502 , 32 , F_303 ( & V_503 ) , V_505 , L_558 , V_487 } } ,
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
{ & V_375 ,
{ L_559 , L_560 , V_502 , 32 , F_303 ( & V_503 ) , V_506 , L_561 , V_487 } } ,
#if 0
{ &hf_netlogon_neg_flags_800000,
{ "Not used 800000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_800000, "Not used", HFILL }},
#endif
{ & V_376 ,
{ L_562 , L_563 , V_502 , 32 , F_303 ( & V_503 ) , V_434 , L_564 , V_487 } } ,
{ & V_377 ,
{ L_565 , L_566 , V_502 , 32 , F_303 ( & V_503 ) , V_507 , L_567 , V_487 } } ,
{ & V_378 ,
{ L_568 , L_560 , V_502 , 32 , F_303 ( & V_503 ) , V_508 , L_569 , V_487 } } ,
{ & V_379 ,
{ L_570 , L_571 , V_502 , 32 , F_303 ( & V_503 ) , V_509 , NULL , V_487 } } ,
{ & V_380 ,
{ L_572 , L_573 , V_502 , 32 , F_303 ( & V_503 ) , V_510 , L_574 , V_487 } } ,
{ & V_381 ,
{ L_575 , L_576 , V_502 , 32 , F_303 ( & V_503 ) , V_511 , L_577 , V_487 } } ,
{ & V_382 ,
{ L_578 , L_579 , V_502 , 32 , F_303 ( & V_503 ) , V_512 , L_580 , V_487 } } ,
{ & V_383 ,
{ L_581 , L_582 , V_502 , 32 , F_303 ( & V_503 ) , V_513 , L_583 , V_487 } } ,
{ & V_384 ,
{ L_584 , L_585 , V_502 , 32 , F_303 ( & V_503 ) , V_428 , NULL , V_487 } } ,
{ & V_385 ,
{ L_586 , L_587 , V_502 , 32 , F_303 ( & V_503 ) , V_514 , NULL , V_487 } } ,
{ & V_386 ,
{ L_588 , L_589 , V_502 , 32 , F_303 ( & V_503 ) , V_515 , NULL , V_487 } } ,
{ & V_387 ,
{ L_590 , L_591 , V_502 , 32 , F_303 ( & V_503 ) , V_516 , NULL , V_487 } } ,
{ & V_388 ,
{ L_592 , L_593 , V_502 , 32 , F_303 ( & V_503 ) , V_517 , NULL , V_487 } } ,
{ & V_389 ,
{ L_594 , L_595 , V_502 , 32 , F_303 ( & V_503 ) , V_518 , NULL , V_487 } } ,
{ & V_390 ,
{ L_596 , L_597 , V_502 , 32 , F_303 ( & V_503 ) , V_519 , L_598 , V_487 } } ,
{ & V_391 ,
{ L_599 , L_600 , V_502 , 32 , F_303 ( & V_503 ) , V_520 , NULL , V_487 } } ,
{ & V_392 ,
{ L_601 , L_602 , V_502 , 32 , F_303 ( & V_503 ) , V_521 , NULL , V_487 } } ,
{ & V_393 ,
{ L_603 , L_604 , V_502 , 32 , F_303 ( & V_503 ) , V_522 , NULL , V_487 } } ,
{ & V_394 ,
{ L_605 , L_606 , V_502 , 32 , F_303 ( & V_503 ) , V_523 , L_607 , V_487 } } ,
{ & V_395 ,
{ L_608 , L_609 , V_502 , 32 , F_303 ( & V_503 ) , V_524 , L_610 , V_487 } } ,
{ & V_396 ,
{ L_611 , L_612 , V_502 , 32 , F_303 ( & V_503 ) , V_525 , L_613 , V_487 } } ,
{ & V_397 ,
{ L_614 , L_615 , V_502 , 32 , F_303 ( & V_503 ) , V_526 , L_616 , V_487 } } ,
{ & V_398 ,
{ L_617 , L_618 , V_502 , 32 , F_303 ( & V_503 ) , V_527 , NULL , V_487 } } ,
{ & V_308 ,
{ L_619 , L_620 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_322 ,
{ L_621 , L_622 ,
V_502 , 32 , F_303 ( & V_528 ) , V_529 ,
L_623 , V_487 } } ,
{ & V_321 ,
{ L_624 , L_625 ,
V_502 , 32 , F_303 ( & V_530 ) , V_531 ,
L_626 , V_487 } } ,
{ & V_320 ,
{ L_627 , L_628 ,
V_502 , 32 , F_303 ( & V_532 ) , V_533 ,
L_629 , V_487 } } ,
{ & V_319 ,
{ L_630 , L_631 ,
V_502 , 32 , F_303 ( & V_534 ) , V_535 ,
L_632 , V_487 } } ,
{ & V_318 ,
{ L_633 , L_634 ,
V_502 , 32 , F_303 ( & V_536 ) , V_537 ,
L_635 , V_487 } } ,
{ & V_317 ,
{ L_636 , L_637 ,
V_502 , 32 , F_303 ( & V_538 ) , V_539 ,
L_638 , V_487 } } ,
{ & V_316 ,
{ L_639 , L_640 ,
V_502 , 32 , F_303 ( & V_540 ) , V_541 ,
L_641 , V_487 } } ,
{ & V_315 ,
{ L_642 , L_643 ,
V_502 , 32 , F_303 ( & V_542 ) , V_543 ,
L_644 , V_487 } } ,
{ & V_314 ,
{ L_645 , L_646 ,
V_502 , 32 , F_303 ( & V_544 ) , V_545 ,
L_647 , V_487 } } ,
{ & V_313 ,
{ L_648 , L_649 ,
V_502 , 32 , F_303 ( & V_546 ) , V_547 ,
L_650 , V_487 } } ,
{ & V_312 ,
{ L_651 , L_652 ,
V_502 , 32 , F_303 ( & V_548 ) , V_549 ,
L_653 , V_487 } } ,
{ & V_311 ,
{ L_433 , L_654 ,
V_502 , 32 , F_303 ( & V_550 ) , V_551 ,
NULL , V_487 } } ,
{ & V_310 ,
{ L_113 , L_655 ,
V_502 , 32 , F_303 ( & V_552 ) , V_553 ,
NULL , V_487 } } ,
{ & V_289 ,
{ L_321 , L_656 , V_488 , V_489 ,
NULL , 0x0 , L_657 , V_487 } } ,
{ & V_307 ,
{ L_658 , L_659 ,
V_502 , 32 , F_303 ( & V_554 ) , V_555 ,
L_660 , V_487 } } ,
{ & V_306 ,
{ L_661 , L_662 ,
V_502 , 32 , F_303 ( & V_556 ) , V_557 ,
L_663 , V_487 } } ,
{ & V_305 ,
{ L_664 , L_665 ,
V_502 , 32 , F_303 ( & V_558 ) , V_559 ,
L_666 , V_487 } } ,
{ & V_304 ,
{ L_667 , L_668 ,
V_502 , 32 , F_303 ( & V_560 ) , V_561 ,
L_669 , V_487 } } ,
{ & V_303 ,
{ L_670 , L_671 ,
V_502 , 32 , F_303 ( & V_562 ) , V_563 ,
L_672 , V_487 } } ,
{ & V_302 ,
{ L_673 , L_674 ,
V_502 , 32 , F_303 ( & V_564 ) , V_565 ,
L_675 , V_487 } } ,
{ & V_301 ,
{ L_676 , L_677 ,
V_502 , 32 , F_303 ( & V_566 ) , V_567 ,
L_678 , V_487 } } ,
{ & V_300 ,
{ L_679 , L_680 ,
V_502 , 32 , F_303 ( & V_568 ) , V_569 ,
L_681 , V_487 } } ,
{ & V_299 ,
{ L_682 , L_683 ,
V_502 , 32 , F_303 ( & V_570 ) , V_571 ,
L_684 , V_487 } } ,
{ & V_298 ,
{ L_685 , L_686 ,
V_502 , 32 , F_303 ( & V_572 ) , V_573 ,
L_687 , V_487 } } ,
{ & V_297 ,
{ L_688 , L_689 ,
V_502 , 32 , F_303 ( & V_574 ) , V_575 ,
L_690 , V_487 } } ,
{ & V_296 ,
{ L_691 , L_692 ,
V_502 , 32 , F_303 ( & V_576 ) , V_577 ,
L_693 , V_487 } } ,
{ & V_295 ,
{ L_694 , L_695 ,
V_502 , 32 , F_303 ( & V_578 ) , V_579 ,
L_696 , V_487 } } ,
{ & V_293 ,
{ L_697 , L_698 ,
V_502 , 32 , F_303 ( & V_580 ) , V_581 ,
L_699 , V_487 } } ,
{ & V_294 ,
{ L_700 , L_701 ,
V_502 , 32 , F_303 ( & V_582 ) , V_583 ,
L_702 , V_487 } } ,
{ & V_292 ,
{ L_703 , L_704 ,
V_502 , 32 , F_303 ( & V_584 ) , V_585 ,
L_705 , V_487 } } ,
{ & V_291 ,
{ L_706 , L_707 ,
V_502 , 32 , F_303 ( & V_586 ) , V_587 ,
L_708 , V_487 } } ,
{ & V_280 ,
{ L_709 , L_710 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_288 ,
{ L_711 , L_712 , V_502 , 32 ,
F_303 ( & V_588 ) , 0x00000001 , NULL , V_487 } } ,
{ & V_287 ,
{ L_713 , L_714 , V_502 , 32 ,
F_303 ( & V_589 ) , 0x00000002 , NULL , V_487 } } ,
{ & V_286 ,
{ L_715 , L_716 , V_502 , 32 ,
F_303 ( & V_590 ) , 0x00000004 , NULL , V_487 } } ,
{ & V_285 ,
{ L_717 , L_718 , V_502 , 32 ,
F_303 ( & V_591 ) , 0x00000008 , NULL , V_487 } } ,
{ & V_284 ,
{ L_719 , L_720 , V_502 , 32 ,
F_303 ( & V_592 ) , 0x00000010 , NULL , V_487 } } ,
{ & V_283 ,
{ L_721 , L_722 , V_502 , 32 ,
F_303 ( & V_593 ) , 0x00000020 , NULL , V_487 } } ,
{ & V_282 ,
{ L_723 , L_724 , V_502 , 32 ,
F_303 ( & V_594 ) , 0x00000040 , NULL , V_487 } } ,
{ & V_336 ,
{ L_725 , L_726 , V_488 , V_486 ,
F_302 ( V_595 ) , 0x0 , NULL , V_487 } } ,
{ & V_33 ,
{ L_727 , L_728 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_35 ,
{ L_729 , L_730 ,
V_502 , 32 , F_303 ( & V_503 ) , V_596 ,
NULL , V_487 } } ,
{ & V_36 ,
{ L_731 , L_732 ,
V_502 , 32 , F_303 ( & V_503 ) , V_597 ,
NULL , V_487 } } ,
{ & V_37 ,
{ L_733 , L_734 ,
V_502 , 32 , F_303 ( & V_503 ) , V_598 ,
NULL , V_487 } } ,
{ & V_38 ,
{ L_735 , L_736 ,
V_502 , 32 , F_303 ( & V_503 ) , V_599 ,
NULL , V_487 } } ,
{ & V_273 ,
{ L_737 , L_738 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_274 ,
{ L_739 , L_740 ,
V_502 , 32 , F_303 ( & V_600 ) , V_601 ,
L_741 , V_487 } } ,
{ & V_278 ,
{ L_742 , L_743 ,
V_502 , 32 , F_303 ( & V_602 ) , V_603 ,
L_744 , V_487 } } ,
{ & V_279 ,
{ L_745 , L_746 ,
V_502 , 32 , F_303 ( & V_604 ) , V_605 ,
L_747 , V_487 } } ,
{ & V_275 ,
{ L_748 , L_749 ,
V_502 , 32 , F_303 ( & V_606 ) , V_607 ,
L_750 , V_487 } } ,
{ & V_276 ,
{ L_751 , L_752 ,
V_502 , 32 , F_303 ( & V_608 ) , V_609 ,
L_753 , V_487 } } ,
{ & V_277 ,
{ L_754 , L_755 ,
V_502 , 32 , F_303 ( & V_610 ) , V_611 ,
L_756 , V_487 } } ,
{ & V_335 ,
{ L_757 , L_758 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_77 ,
{ L_759 , L_760 , V_497 , V_498 ,
NULL , 0 , L_761 , V_487 } } ,
{ & V_80 ,
{ L_762 , L_763 , V_497 , V_498 ,
NULL , 0 , L_764 , V_487 } } ,
{ & V_79 ,
{ L_765 , L_766 , V_497 , V_498 ,
NULL , 0 , L_767 , V_487 } } ,
{ & V_78 ,
{ L_768 , L_769 , V_497 , V_498 ,
NULL , 0 , L_767 , V_487 } } ,
{ & V_126 ,
{ L_770 , L_771 , V_497 , V_498 ,
NULL , 0 , L_772 , V_487 } } ,
{ & V_81 ,
{ L_773 , L_774 , V_612 , V_494 ,
NULL , 0 , L_775 , V_487 } } ,
{ & V_82 ,
{ L_776 , L_777 , V_497 , V_498 ,
NULL , 0 , L_778 , V_487 } } ,
{ & V_83 ,
{ L_779 , L_780 , V_497 , V_498 ,
NULL , 0 , L_781 , V_487 } } ,
{ & V_208 ,
{ L_782 , L_783 , V_497 , V_498 ,
NULL , 0 , L_784 , V_487 } } ,
{ & V_207 ,
{ L_785 , L_786 , V_497 , V_498 ,
NULL , 0 , L_787 , V_487 } } ,
{ & V_225 ,
{ L_788 , L_789 , V_497 , V_498 ,
NULL , 0 , L_790 , V_487 } } ,
{ & V_226 ,
{ L_791 , L_792 , V_497 , V_498 ,
NULL , 0 , L_793 , V_487 } } ,
{ & V_237 ,
{ L_794 , L_795 , V_497 , V_498 ,
NULL , 0 , L_796 , V_487 } } ,
{ & V_239 ,
{ L_797 , L_798 , V_497 , V_498 ,
NULL , 0 , L_799 , V_487 } } ,
{ & V_222 ,
{ L_800 , L_801 , V_612 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_220 ,
{ L_802 , L_803 , V_612 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_399 ,
{ L_804 , L_805 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_419 ,
{ L_806 , L_807 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_420 ,
{ L_808 , L_809 , V_488 , V_486 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_176 ,
{ L_810 , L_811 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_185 ,
{ L_812 , L_813 , V_493 , V_494 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_446 ,
{ L_814 , L_815 , V_488 , V_489 ,
F_302 ( V_613 ) , 0x0 , NULL , V_487 } } ,
{ & V_447 ,
{ L_816 , L_817 , V_488 , V_489 ,
NULL , 0x0 , NULL , V_487 } } ,
{ & V_440 ,
{ L_818 , L_819 , V_502 , 32 ,
NULL , 0x00000001 , NULL , V_487 } } ,
{ & V_441 ,
{ L_820 , L_821 , V_502 , 32 ,
NULL , 0x00000002 , NULL , V_487 } } ,
{ & V_442 ,
{ L_433 , L_822 , V_502 , 32 ,
NULL , 0x00000004 , NULL , V_487 } } ,
{ & V_443 ,
{ L_428 , L_823 , V_502 , 32 ,
NULL , 0x00000008 , NULL , V_487 } } ,
{ & V_444 ,
{ L_824 , L_825 , V_502 , 32 ,
NULL , 0x00000010 , NULL , V_487 } } ,
{ & V_449 ,
{ L_818 , L_826 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_450 ,
{ L_820 , L_827 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_454 ,
{ L_824 , L_828 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_452 ,
{ L_433 , L_829 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_453 ,
{ L_428 , L_830 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_106 ,
{ L_831 , L_832 , V_488 , V_486 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_104 ,
{ L_833 , L_834 , V_495 , V_494 ,
NULL , 0 , NULL , V_487 } } ,
{ & V_472 ,
{ L_835 , L_836 , V_614 , V_494 ,
NULL , 0x0 , L_837 , V_487 } } ,
{ & V_474 ,
{ L_838 , L_839 , V_485 , V_489 ,
F_302 ( V_615 ) , 0 , NULL , V_487 } } ,
{ & V_476 ,
{ L_840 , L_841 , V_485 , V_489 ,
F_302 ( V_616 ) , 0 , NULL , V_487 } } ,
{ & V_477 ,
{ L_321 , L_842 , V_493 , V_494 , NULL ,
0x0 , NULL , V_487 } } ,
{ & V_479 ,
{ L_843 , L_844 , V_493 , V_494 , NULL ,
0x0 , NULL , V_487 } } ,
{ & V_478 ,
{ L_845 , L_846 , V_493 , V_494 , NULL ,
0x0 , NULL , V_487 } } ,
{ & V_480 ,
{ L_847 , L_848 , V_493 , V_494 , NULL ,
0x0 , NULL , V_487 } } ,
{ & V_118 ,
{ L_849 , L_850 ,
V_502 , 32 , F_303 ( & V_617 ) , 0x00000001 ,
L_851 , V_487 } } ,
{ & V_117 ,
{ L_852 , L_853 ,
V_502 , 32 , F_303 ( & V_618 ) , 0x00000002 ,
L_854 , V_487 } } ,
{ & V_116 ,
{ L_855 , L_856 ,
V_502 , 32 , F_303 ( & V_619 ) , 0x00000004 ,
L_857 , V_487 } } ,
{ & V_125 ,
{ L_858 , L_859 ,
V_502 , 32 , F_303 ( & V_620 ) , 0x00000020 ,
L_860 , V_487 } } ,
{ & V_124 ,
{ L_861 , L_862 ,
V_502 , 32 , F_303 ( & V_621 ) , 0x00000200 ,
L_863 , V_487 } } ,
{ & V_54 ,
{ L_864 , L_865 ,
V_502 , 32 , F_303 ( & V_622 ) , 0x00010000 ,
L_866 , V_487 } } ,
{ & V_55 ,
{ L_867 , L_868 ,
V_502 , 32 , F_303 ( & V_623 ) , 0x00008000 ,
L_869 , V_487 } } ,
{ & V_56 ,
{ L_870 , L_871 ,
V_502 , 32 , F_303 ( & V_624 ) , 0x00004000 ,
L_872 , V_487 } } ,
{ & V_57 ,
{ L_873 , L_874 ,
V_502 , 32 , F_303 ( & V_625 ) , 0x00002000 ,
L_875 , V_487 } } ,
{ & V_58 ,
{ L_876 , L_877 ,
V_502 , 32 , F_303 ( & V_626 ) , 0x00001000 ,
L_878 , V_487 } } ,
{ & V_59 ,
{ L_879 , L_880 ,
V_502 , 32 , F_303 ( & V_627 ) , 0x00000800 ,
L_881 , V_487 } } ,
{ & V_60 ,
{ L_882 , L_883 ,
V_502 , 32 , F_303 ( & V_628 ) , 0x00000400 ,
L_884 , V_487 } } ,
{ & V_61 ,
{ L_885 , L_886 ,
V_502 , 32 , F_303 ( & V_629 ) , 0x00000200 ,
L_887 , V_487 } } ,
{ & V_62 ,
{ L_888 , L_889 ,
V_502 , 32 , F_303 ( & V_630 ) , 0x00000100 ,
L_890 , V_487 } } ,
{ & V_63 ,
{ L_891 , L_892 ,
V_502 , 32 , F_303 ( & V_631 ) , 0x00000080 ,
L_893 , V_487 } } ,
{ & V_64 ,
{ L_894 , L_895 ,
V_502 , 32 , F_303 ( & V_632 ) , 0x00000040 ,
L_896 , V_487 } } ,
{ & V_65 ,
{ L_897 , L_898 ,
V_502 , 32 , F_303 ( & V_633 ) , 0x00000020 ,
L_899 , V_487 } } ,
{ & V_66 ,
{ L_900 , L_901 ,
V_502 , 32 , F_303 ( & V_634 ) , 0x00000010 ,
L_902 , V_487 } } ,
{ & V_67 ,
{ L_903 , L_904 ,
V_502 , 32 , F_303 ( & V_635 ) , 0x00000008 ,
L_905 , V_487 } } ,
{ & V_68 ,
{ L_906 , L_907 ,
V_502 , 32 , F_303 ( & V_636 ) , 0x00000004 ,
L_908 , V_487 } } ,
{ & V_69 ,
{ L_909 , L_910 ,
V_502 , 32 , F_303 ( & V_637 ) , 0x00000002 ,
L_911 , V_487 } } ,
{ & V_70 ,
{ L_912 , L_913 ,
V_502 , 32 , F_303 ( & V_638 ) , 0x00000001 ,
L_914 , V_487 } } ,
#if 0
{ &hf_netlogon_dnsdomaininfo,
{ "DnsDomainInfo", "netlogon.dnsdomaininfo", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_341 ,
{ L_915 , L_916 , V_614 , V_494 , NULL , 0 , NULL , V_487 } } ,
{ & V_340 ,
{ L_915 , L_917 , V_614 , V_494 , NULL , 0 , NULL , V_487 } } ,
{ & V_342 ,
{ L_918 , L_919 , V_639 , V_494 , NULL , 0 , NULL , V_487 } } ,
{ & V_345 ,
{ L_920 , L_921 , V_614 , V_494 , NULL , 0 , NULL , V_487 } } ,
{ & V_344 ,
{ L_922 , L_923 , V_614 , V_494 , NULL , 0 , NULL , V_487 } } ,
{ & V_343 ,
{ L_924 , L_925 , V_614 , V_494 , NULL , 0 , NULL , V_487 } } ,
{ & V_161 ,
{ L_926 , L_927 , V_495 , V_494 ,
NULL , 0 , L_928 , V_487 } } ,
{ & V_162 ,
{ L_929 , L_930 , V_488 , V_489 ,
NULL , 0x0 , L_931 , V_487 } } ,
{ & V_160 ,
{ L_932 , L_933 , V_495 , V_494 ,
NULL , 0 , L_934 , V_487 } } ,
} ;
static T_2 * V_640 [] = {
& V_641 ,
& V_372 ,
& V_235 ,
& V_214 ,
& V_95 ,
& V_245 ,
& V_323 ,
& V_325 ,
& V_359 ,
& V_361 ,
& V_366 ,
& V_243 ,
& V_367 ,
& V_241 ,
& V_51 ,
& V_100 ,
& V_119 ,
& V_363 ,
& V_642 ,
& V_346 ,
& V_349 ,
& V_34 ,
& V_281 ,
& V_290 ,
& V_309 ,
& V_445 ,
& V_448 ,
& V_473 ,
& V_115 ,
& V_123 ,
& V_339 ,
& V_53
} ;
V_643 = F_304 (
L_935 , L_936 , L_937 ) ;
F_305 ( V_643 , V_483 ,
F_306 ( V_483 ) ) ;
F_307 ( V_640 , F_306 ( V_640 ) ) ;
F_308 ( F_298 ) ;
}
void
F_309 ( void )
{
V_400 . V_401 = FALSE ;
V_400 . V_180 = 0 ;
F_310 ( V_643 , V_641 ,
& V_644 , V_645 ,
V_646 , V_484 ) ;
F_311 ( V_647 ,
V_648 ,
& V_649 ) ;
F_311 ( V_650 ,
V_648 ,
& V_649 ) ;
}
