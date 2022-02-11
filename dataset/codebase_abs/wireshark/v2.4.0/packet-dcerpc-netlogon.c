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
existing_vars = wmem_map_lookup(schannel_auths, key);
if (!existing_vars)
{
wmem_map_insert(schannel_auths, key, vars);
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
F_231 ( V_423 , V_415 . V_420 , V_417 , V_410 * 2 ) ;
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
memcpy ( V_414 [ V_5 ] . V_420 , V_413 -> V_424 , 16 ) ;
V_5 ++ ;
}
}
return V_416 ;
}
static int
F_234 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 , int V_425 )
{
T_12 V_127 ;
T_19 * V_175 ;
T_9 V_173 ;
T_7 V_426 ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_427 , & V_426 ) ;
V_127 = F_55 ( V_7 , V_8 ) ;
F_225 ( V_7 , V_9 , V_127 , V_8 ) ;
V_8 += 4 ;
V_44 ;
if( V_425 ) {
V_8 = F_235 ( V_7 , V_8 , T_5 , V_9 , V_10 ,
V_428 , NULL ) ;
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
T_12 V_429 = 0 ;
unsigned int V_5 = 0 ;
T_23 V_430 ;
#endif
T_1 V_431 [ 16 ] ;
int V_432 = 0 ;
V_175 -> V_127 = V_127 ;
V_175 -> V_433 = FALSE ;
#ifdef F_236
V_429 = F_229 ( & V_414 , V_434 ) ;
F_2 ( L_152 , V_429 ) ;
#endif
if( V_127 & V_435 ) {
#ifdef F_236
T_1 V_436 [ 4 ] = { 0 } ;
T_1 V_437 [ V_438 ] ;
T_25 V_439 ;
T_1 V_440 [ 8 ] = { 0 } ;
T_7 V_441 ;
if ( ! F_237 ( & V_439 , V_442 , 0 ) ) {
F_238 ( V_439 , V_436 , 4 ) ;
F_238 ( V_439 , ( T_1 * ) & V_175 -> V_184 , 8 ) ;
F_238 ( V_439 , ( T_1 * ) & V_175 -> V_190 , 8 ) ;
memcpy ( V_437 , F_239 ( V_439 , 0 ) , 16 ) ;
F_240 ( V_439 ) ;
}
F_1 ( V_437 , 8 , L_153 , L_148 ) ;
F_1 ( ( T_1 * ) & V_175 -> V_184 , 8 , L_154 , L_148 ) ;
F_1 ( ( T_1 * ) & V_175 -> V_190 , 8 , L_155 , L_148 ) ;
F_1 ( ( T_1 * ) & V_426 , 8 , L_156 , L_148 ) ;
for( V_5 = 0 ; V_5 < V_429 ; V_5 ++ )
{
V_430 = V_414 [ V_5 ] ;
if ( ! F_241 ( V_442 , V_431 , V_437 , V_438 , ( T_1 * ) & V_430 , 16 ) ) {
F_242 ( V_440 , ( unsigned char * ) & V_175 -> V_190 , V_431 ) ;
F_242 ( ( unsigned char * ) & V_441 , V_440 , V_431 + 7 ) ;
#if 0
printnbyte((guint8*)&calculated_cred,8,"Calculated creds:","\n");
#endif
if( V_441 == V_426 ) {
V_432 = 1 ;
break;
}
}
}
#endif
}
#if 0
else if( flags&NETLOGON_FLAG_USEAES)
{
debugprintf("AES not supported yet\n");
memset(session_key,0,16);
}
#endif
else
{
F_2 ( L_157 ) ;
memset ( V_431 , 0 , 16 ) ;
}
if( V_432 ) {
memcpy ( & V_175 -> V_431 , V_431 , 16 ) ;
F_2 ( L_158 ) ;
}
else {
F_2 ( L_159 ) ;
memset ( & V_175 -> V_431 , 0 , 16 ) ;
}
}
} else {
F_1 ( ( T_1 * ) & V_175 -> V_431 , 16 , L_160 , L_148 ) ;
}
return V_8 ;
}
static int
F_243 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
return F_234 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , 1 ) ;
}
static int
F_244 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
return F_234 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , 0 ) ;
}
static int
F_245 ( T_3 * V_7 , int V_8 ,
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
V_48 , L_161 , V_443 , 0 ) ;
V_8 = F_169 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_246 ( T_3 * V_7 , int V_8 ,
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
F_247 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_248 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_16 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_179 , V_48 , L_161 ,
V_443 , V_180 ,
F_82 ( V_90 | 1 ) ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_249 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_5 , V_85 , 0 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_38 ,
V_85 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_162 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_209 , V_89 ,
L_163 , - 1 ) ;
return V_8 ;
}
static int
F_250 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_194 , V_89 ,
L_164 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_251 ( T_3 * V_7 , int V_8 ,
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
F_252 ( T_3 * V_7 , int V_8 ,
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
F_253 ( T_3 * V_7 , int V_8 ,
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
F_254 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_54 , V_89 ,
L_40 , - 1 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_45 , V_89 ,
L_165 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_255 ( T_3 * V_7 , int V_8 ,
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
F_256 ( T_3 * V_7 , int V_8 ,
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
F_257 ( T_3 * V_7 , int V_8 ,
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
F_258 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_199 , V_48 ,
L_166 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_259 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_167 ,
V_73 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_167 ,
V_100 , 0 ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_176 , V_48 ,
L_168 , - 1 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_112 ,
V_443 , 0 ) ;
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_273 , NULL ) ;
return V_8 ;
}
static int
F_260 ( T_3 * V_7 , int V_8 ,
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
F_261 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_262 ( T_3 * V_7 , int V_8 ,
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
F_263 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_264 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_263 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_201 , V_48 ,
L_169 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_265 ( T_3 * V_7 , int V_8 ,
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
F_266 ( T_3 * V_7 , int V_8 ,
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
F_267 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_268 (
V_7 , V_8 , T_5 , V_9 , V_28 , V_10 , V_443 ,
V_180 ,
F_82 ( V_90 | 1 ) ) ;
return V_8 ;
}
static int
F_269 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_38 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_267 ) ;
return V_8 ;
}
static int
F_270 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_261 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_269 , V_48 ,
L_170 , - 1 ) ;
return V_8 ;
}
static int
F_271 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_272 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_270 , V_48 ,
L_171 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int
F_273 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_48 , L_172 ,
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
F_274 ( T_3 * V_7 , int V_8 ,
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
F_275 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_21 ( V_7 , V_8 ,
T_5 , V_9 , V_28 , V_10 ) ;
V_8 = F_167 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ) ;
return V_8 ;
}
static int
F_276 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_12 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_263 , NULL ) ;
V_8 = F_27 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
F_201 , V_48 ,
L_169 , - 1 ) ;
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_92 , NULL ) ;
return V_8 ;
}
static int
F_277 ( T_3 * V_7 , int V_8 ,
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
L_173 , - 1 ) ;
V_8 = F_22 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_89 , L_174 , V_444 , 0 ) ;
return V_8 ;
}
static int
F_278 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 , T_6 * V_9 , T_11 * V_28 , T_1 * V_10 )
{
V_8 = F_28 ( V_7 , V_8 , T_5 , V_9 , V_28 , V_10 ,
V_171 , NULL ) ;
return V_8 ;
}
static int F_279 ( T_3 * V_7 , int V_8 ,
T_4 * T_5 ,
T_6 * V_9 , T_11 * V_28 V_6 , T_1 * V_10 )
{
T_17 * V_97 = NULL ;
T_6 * V_50 = NULL ;
T_12 V_445 ;
T_7 V_446 ;
static const int * V_447 [] = {
& V_448 ,
& V_449 ,
& V_450 ,
& V_451 ,
& V_452 ,
NULL
} ;
int V_42 ;
if ( V_9 ) {
V_50 = F_18 (
V_9 , V_7 , V_8 , - 1 , V_453 , & V_97 ,
L_175 ) ;
}
V_8 = F_235 (
V_7 , V_8 , T_5 , V_50 , V_10 ,
V_454 , & V_445 ) ;
F_280 ( V_50 , V_7 , V_8 ,
V_455 ,
V_456 ,
V_447 ,
( V_10 [ 0 ] & V_14 ) ?
V_457 :
V_458 ,
& V_446 ) ;
V_8 += 4 ;
if ( V_446 & 0x00000001 ) {
V_42 = F_281 ( V_7 , V_8 ) ;
F_6 ( V_50 , V_459 , V_7 , V_8 , V_42 , V_258 | V_15 ) ;
V_8 += V_42 ;
}
if ( V_446 & 0x00000002 ) {
V_42 = F_281 ( V_7 , V_8 ) ;
F_6 ( V_50 , V_460 , V_7 , V_8 , V_42 , V_258 | V_15 ) ;
V_8 += V_42 ;
}
if ( V_446 & 0x00000004 ) {
int V_98 = V_8 ;
char V_461 [ 256 ] ;
V_8 = F_282 ( V_7 , V_8 , V_461 , 255 , FALSE ) ;
F_283 ( V_50 , V_462 , V_7 , V_98 , V_8 - V_98 , V_461 ) ;
}
if ( V_446 & 0x00000008 ) {
int V_98 = V_8 ;
char V_461 [ 256 ] ;
V_8 = F_282 ( V_7 , V_8 , V_461 , 255 , FALSE ) ;
F_283 ( V_50 , V_463 , V_7 , V_98 , V_8 - V_98 , V_461 ) ;
}
if ( V_446 & 0x00000010 ) {
int V_98 = V_8 ;
char V_461 [ 256 ] ;
V_8 = F_282 ( V_7 , V_8 , V_461 , 255 , FALSE ) ;
F_283 ( V_50 , V_464 , V_7 , V_98 , V_8 - V_98 , V_461 ) ;
}
return V_8 ;
}
static int F_284 ( const T_1 * V_431 , int V_465 , T_7 V_466 , T_1 * V_467 )
{
T_1 V_436 [ 4 ] = { 0 } ;
T_1 * V_440 = ( T_1 * ) F_232 ( F_233 () , V_465 ) ;
T_1 V_468 [ V_438 ] ;
T_1 V_469 [ 16 ] ;
int V_5 = 0 ;
memset ( V_469 , 0 , 16 ) ;
memset ( V_467 , 0 , 16 ) ;
if( memcmp ( V_431 , V_469 , 16 ) ) {
for( V_5 = 0 ; V_5 < V_465 ; V_5 ++ ) {
V_440 [ V_5 ] = V_431 [ V_5 ] ^ 0xF0 ;
}
if ( F_241 ( V_442 , V_468 , V_436 , 4 , V_440 , V_465 ) ) {
return 0 ;
}
if ( F_241 ( V_442 , V_467 , ( T_1 * ) & V_466 , 8 , V_468 , V_438 ) ) {
return 0 ;
}
return 1 ;
} else {
return 0 ;
}
}
static T_7 F_285 ( T_1 * V_431 , T_7 V_470 , T_7 V_471 , unsigned char V_172 V_6 )
{
T_1 V_436 [ 4 ] = { 0 } ;
T_1 V_440 [ V_438 ] ;
T_1 V_173 [ V_438 ] ;
T_26 V_472 ;
T_1 * V_473 = ( T_1 * ) & V_471 ;
if ( F_241 ( V_442 , V_440 , V_436 , 4 , V_431 , 16 ) ) {
return 0 ;
}
if ( F_241 ( V_442 , V_173 , ( T_1 * ) & V_470 , 8 , V_440 , V_438 ) ) {
return 0 ;
}
if ( ! F_286 ( & V_472 , V_474 , V_475 , 0 ) ) {
if ( ! F_287 ( V_472 , V_173 , V_438 ) ) {
F_288 ( V_472 , V_473 , 8 , NULL , 0 ) ;
}
F_289 ( V_472 ) ;
}
return V_471 ;
}
static T_3 *
F_290 ( T_3 * V_7 , T_3 * T_27 V_6 ,
int V_8 , T_4 * T_5 , T_28 * T_29 V_6 , unsigned char V_172 )
{
T_3 * V_440 = NULL ;
T_1 * V_476 ;
T_19 * V_175 ;
T_9 V_173 ;
F_79 ( T_5 , V_172 , & V_173 , NULL ) ;
V_175 = ( T_19 * ) F_87 ( V_189 , & V_173 ) ;
if( V_175 != NULL ) {
while( V_175 != NULL && V_175 -> V_187 != - 1 && V_175 -> V_187 < ( int ) T_5 -> V_186 ) {
V_175 = V_175 -> V_188 ;
}
if( V_175 == NULL ) {
F_2 ( L_176 , F_291 ( V_189 ) ) ;
return ( V_440 ) ;
}
else {
if( V_175 -> V_433 == TRUE ) {
T_26 V_472 ;
int V_195 ;
T_7 V_477 = V_175 -> V_478 ;
V_195 = F_292 ( V_7 , V_8 ) ;
if ( V_195 < 0 ) {
return NULL ;
}
if ( F_286 ( & V_472 , V_474 , V_475 , 0 ) ) {
return NULL ;
}
if ( F_287 ( V_472 , V_175 -> V_479 , 16 ) ) {
F_289 ( V_472 ) ;
return NULL ;
}
F_288 ( V_472 , ( T_1 * ) & V_477 , 8 , NULL , 0 ) ;
V_476 = ( T_1 * ) F_293 ( T_5 -> V_480 , V_7 , V_8 , V_195 ) ;
F_294 ( V_472 ) ;
F_288 ( V_472 , V_476 , V_195 , NULL , 0 ) ;
F_289 ( V_472 ) ;
V_440 = F_295 ( V_7 , V_476 , V_195 , V_195 ) ;
}
else {
F_2 ( L_177 ) ;
}
}
} else {
F_2 ( L_178 , F_291 ( V_189 ) ) ;
return ( V_440 ) ;
}
return ( V_440 ) ;
}
static T_3 * F_296 ( T_3 * V_7 , T_3 * T_27 ,
int V_8 , T_4 * T_5 , T_28 * T_29 )
{
return F_290 ( V_7 , T_27 , V_8 , T_5 , T_29 , 0 ) ;
}
static T_3 * F_297 ( T_3 * V_7 , T_3 * T_27 ,
int V_8 , T_4 * T_5 , T_28 * T_29 )
{
return F_290 ( V_7 , T_27 , V_8 , T_5 , T_29 , 1 ) ;
}
static int
F_298 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_1 * V_10 , unsigned char V_172 )
{
T_19 * V_175 ;
T_9 V_173 ;
T_17 * V_481 = NULL ;
T_6 * V_50 = NULL ;
T_7 V_482 ;
T_7 V_483 ;
T_7 V_478 = 0 ;
int V_484 = 0 ;
F_79 ( T_5 , V_172 , & V_173 , NULL ) ;
V_175 = ( T_19 * ) F_87 ( V_189 , ( T_8 * ) & V_173 ) ;
if( ! ( V_406 . V_407 && V_406 . V_186 == T_5 -> V_186 ) ) {
V_481 = F_6 ( V_9 , V_485 , V_7 ,
V_8 , - 1 , V_15 ) ;
V_50 = F_299 ( V_481 , V_486 ) ;
F_6 ( V_50 , V_487 , V_7 ,
V_8 , 2 , V_457 ) ;
F_6 ( V_50 , V_488 , V_7 ,
V_8 + 2 , 2 , V_457 ) ;
F_6 ( V_50 , V_489 , V_7 ,
V_8 + 6 , 2 , V_15 ) ;
V_8 += 8 ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_490 , & V_482 ) ;
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_491 , & V_483 ) ;
if ( F_300 ( V_7 , V_8 , 8 ) ) {
V_8 = F_3 ( V_7 , V_8 , T_5 , V_50 , V_10 ,
V_492 , & V_478 ) ;
}
V_484 = 1 ;
}
if( V_175 != NULL ) {
while( V_175 != NULL && V_175 -> V_187 != - 1 && V_175 -> V_187 < ( int ) T_5 -> V_186 ) {
V_175 = V_175 -> V_188 ;
}
if( V_175 == NULL ) {
F_2 ( L_176 , F_291 ( V_189 ) ) ;
return ( V_8 ) ;
}
else {
if( V_484 ) {
V_175 -> V_478 = V_478 ;
V_175 -> V_493 = F_285 ( V_175 -> V_431 , V_483 , V_482 , V_172 ) ;
}
if( F_284 ( V_175 -> V_431 , 16 , V_175 -> V_493 , V_175 -> V_479 ) )
{
V_175 -> V_433 = TRUE ;
}
else
{
F_2 ( L_179 ) ;
}
}
}
else
{
F_2 ( L_180 , V_175 == NULL , F_291 ( V_189 ) ) ;
}
V_406 . V_407 = TRUE ;
V_406 . V_186 = T_5 -> V_186 ;
return V_8 ;
}
static int
F_301 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_11 * V_28 V_6 , T_1 * V_10 )
{
return F_298 ( V_7 , V_8 , T_5 , V_9 , V_10 , 0 ) ;
}
static int
F_302 ( T_3 * V_7 , int V_8 , T_4 * T_5 ,
T_6 * V_9 , T_11 * V_28 V_6 , T_1 * V_10 )
{
return F_298 ( V_7 , V_8 , T_5 , V_9 , V_10 , 1 ) ;
}
void
F_303 ( void )
{
static T_30 V_494 [] = {
{ & V_495 ,
{ L_181 , L_182 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_171 , {
L_183 , L_184 , V_499 , V_500 | V_501 ,
& V_502 , 0x0 , L_185 , V_498 } } ,
{ & V_92 ,
{ L_186 , L_187 , V_499 ,
V_500 | V_501 , & V_503 , 0x0 , NULL , V_498 } } ,
{ & V_276 ,
{ L_188 , L_189 , V_499 ,
V_500 | V_501 , & V_279 , 0x0 , NULL , V_498 } } ,
{ & V_101 , {
L_190 , L_191 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_102 , {
L_192 , L_193 , V_504 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_246 , {
L_194 , L_195 , V_504 , V_497 ,
NULL , 0x0 , L_196 , V_498 } } ,
{ & V_209 , {
L_197 , L_198 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_261 , {
L_199 , L_200 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_263 , {
L_201 , L_202 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_113 , {
L_203 , L_204 , V_505 , V_506 ,
NULL , 0x0 , L_205 , V_498 } } ,
{ & V_106 , {
L_206 , L_207 , V_505 , V_506 ,
NULL , 0x0 , L_208 , V_498 } } ,
{ & V_103 , {
L_209 , L_210 , V_505 , V_506 ,
NULL , 0x0 , L_211 , V_498 } } ,
{ & V_126 , {
L_212 , L_213 , V_505 , V_506 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_193 , {
L_214 , L_215 , V_505 , V_506 ,
NULL , 0x0 , L_216 , V_498 } } ,
{ & V_105 , {
L_217 , L_218 , V_505 , V_506 ,
NULL , 0x0 , L_219 , V_498 } } ,
{ & V_346 , {
L_220 , L_221 , V_505 , V_506 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_332 , {
L_222 , L_223 , V_499 , V_497 ,
NULL , 0 , L_224 , V_498 } } ,
{ & V_74 , {
L_225 , L_226 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_236 , {
L_227 , L_228 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_237 , {
L_229 , L_230 , V_499 , V_500 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_235 , {
L_231 , L_232 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_267 , {
L_233 , L_234 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_269 , {
L_235 , L_236 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_122 , {
L_237 , L_238 , V_499 , V_500 ,
NULL , 0 , NULL , V_498 } } ,
#if 0
{ &hf_netlogon_lsapolicy_referentid,
{ "Referent ID", "netlogon.lsapolicy.referentID", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_358 ,
{ L_224 , L_239 , V_499 , V_497 ,
NULL , 0x0 , L_240 , V_498 } } ,
#if 0
{ &hf_netlogon_lsapolicy_pointer,
{ "Pointer", "netlogon.lsapolicy.pointer", FT_BYTES, BASE_NONE,
NULL, 0x0, "Pointer to LSA POLICY", HFILL }},
#endif
{ & V_250 ,
{ L_241 , L_242 , V_507 , V_506 ,
NULL , 0 , L_243 , V_498 } } ,
{ & V_272 ,
{ L_244 , L_245 , V_507 , V_506 ,
NULL , 0 , L_246 , V_498 } } ,
{ & V_274 ,
{ L_99 , L_247 , V_507 , V_506 ,
NULL , 0 , L_248 , V_498 } } ,
{ & V_154 ,
{ L_249 , L_250 , V_507 , V_506 ,
NULL , 0 , L_251 , V_498 } } ,
{ & V_355 ,
{ L_252 , L_253 , V_507 , V_506 ,
NULL , 0 , L_254 , V_498 } } ,
{ & V_341 ,
{ L_255 , L_256 , V_499 , V_497 ,
NULL , 0 , L_254 , V_498 } } ,
{ & V_342 ,
{ L_224 , L_257 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_340 ,
{ L_258 , L_259 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_155 ,
{ L_260 , L_250 , V_507 , V_506 ,
NULL , 0 , L_261 , V_498 } } ,
{ & V_156 ,
{ L_262 , L_250 , V_507 , V_506 ,
NULL , 0 , L_263 , V_498 } } ,
{ & V_157 ,
{ L_264 , L_250 , V_507 , V_506 ,
NULL , 0 , L_265 , V_498 } } ,
{ & V_158 ,
{ L_266 , L_250 , V_507 , V_506 ,
NULL , 0 , L_267 , V_498 } } ,
{ & V_159 ,
{ L_268 , L_250 , V_507 , V_506 ,
NULL , 0 , L_269 , V_498 } } ,
{ & V_160 ,
{ L_270 , L_250 , V_507 , V_506 ,
NULL , 0 , L_271 , V_498 } } ,
{ & V_161 ,
{ L_272 , L_250 , V_507 , V_506 ,
NULL , 0 , L_273 , V_498 } } ,
{ & V_162 ,
{ L_274 , L_250 , V_507 , V_506 ,
NULL , 0 , L_275 , V_498 } } ,
{ & V_163 ,
{ L_276 , L_250 , V_507 , V_506 ,
NULL , 0 , L_277 , V_498 } } ,
{ & V_273 ,
{ L_278 , L_279 , V_499 , V_500 ,
NULL , 0x0 , L_280 , V_498 } } ,
{ & V_141 ,
{ L_281 , L_282 , V_499 , V_500 ,
NULL , 0x0 , L_283 , V_498 } } ,
{ & V_142 ,
{ L_284 , L_285 , V_499 , V_500 ,
NULL , 0x0 , L_286 , V_498 } } ,
{ & V_356 ,
{ L_287 , L_288 , V_499 , V_500 ,
NULL , 0x0 , L_289 , V_498 } } ,
{ & V_143 ,
{ L_290 , L_291 , V_499 , V_500 ,
NULL , 0x0 , L_292 , V_498 } } ,
{ & V_144 ,
{ L_293 , L_294 , V_499 , V_500 ,
NULL , 0x0 , L_295 , V_498 } } ,
{ & V_145 ,
{ L_296 , L_297 , V_499 , V_500 ,
NULL , 0x0 , L_298 , V_498 } } ,
{ & V_146 ,
{ L_299 , L_300 , V_499 , V_500 ,
NULL , 0x0 , L_301 , V_498 } } ,
{ & V_147 ,
{ L_302 , L_303 , V_499 , V_500 ,
NULL , 0x0 , L_304 , V_498 } } ,
{ & V_148 ,
{ L_305 , L_306 , V_499 , V_500 ,
NULL , 0x0 , L_307 , V_498 } } ,
{ & V_149 ,
{ L_308 , L_309 , V_499 , V_500 ,
NULL , 0x0 , L_310 , V_498 } } ,
{ & V_366 ,
{ L_311 , L_312 , V_499 , V_500 ,
NULL , 0x0 , L_313 , V_498 } } ,
{ & V_363 ,
{ L_314 , L_315 , V_499 , V_500 ,
NULL , 0x0 , L_316 , V_498 } } ,
{ & V_88 ,
{ L_317 , L_318 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_368 ,
{ L_319 , L_320 , V_496 , V_500 ,
NULL , 0x0 , L_321 , V_498 } } ,
{ & V_96 ,
{ L_322 , L_323 , V_508 , V_500 ,
NULL , 0x0 , L_324 , V_498 } } ,
{ & V_201 ,
{ L_325 , L_326 , V_509 , V_510 ,
NULL , 0x0 , L_327 , V_498 } } ,
{ & V_202 ,
{ L_328 , L_329 , V_508 , V_500 ,
NULL , 0x0 , L_330 , V_498 } } ,
{ & V_203 ,
{ L_331 , L_332 , V_508 , V_500 ,
NULL , 0x0 , L_333 , V_498 } } ,
{ & V_204 ,
{ L_334 , L_335 , V_508 , V_500 ,
NULL , 0x0 , L_336 , V_498 } } ,
{ & V_170 ,
{ L_337 , L_338 , V_508 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_198 ,
{ L_339 , L_340 , V_508 , V_497 ,
NULL , 0x0 , L_341 , V_498 } } ,
{ & V_229 ,
{ L_342 , L_343 , V_508 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_230 ,
{ L_344 , L_345 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_219 ,
{ L_346 , L_347 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_196 ,
{ L_224 , L_348 , V_499 , V_497 ,
NULL , 0x0 , L_349 , V_498 } } ,
#if 0
{ &hf_netlogon_nt_chal_resp,
{ "NT Chal resp", "netlogon.nt_chal_resp", FT_BYTES, BASE_NONE,
NULL, 0, "Challenge response for NT authentication", HFILL }},
#endif
{ & V_107 ,
{ L_350 , L_351 , V_505 , V_506 ,
NULL , 0 , L_352 , V_498 } } ,
{ & V_240 ,
{ L_353 , L_354 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_239 ,
{ L_355 , L_356 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
#if 0
{ &hf_netlogon_pac_data,
{ "Pac Data", "netlogon.pac.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_197 ,
{ L_357 , L_358 , V_505 , V_506 ,
NULL , 0 , L_339 , V_498 } } ,
#if 0
{ &hf_netlogon_auth_data,
{ "Auth Data", "netlogon.auth.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_242 ,
{ L_359 , L_360 , V_505 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_244 ,
{ L_361 , L_362 , V_505 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_73 ,
{ L_145 , L_363 , V_507 , V_506 ,
NULL , 0 , L_56 , V_498 } } ,
{ & V_199 ,
{ L_364 , L_365 , V_507 , V_506 ,
NULL , 0 , L_366 , V_498 } } ,
{ & V_216 ,
{ L_367 , L_368 , V_507 , V_506 ,
NULL , 0 , L_369 , V_498 } } ,
{ & V_133 ,
{ L_370 , L_371 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_205 ,
{ L_372 , L_373 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_206 ,
{ L_374 , L_375 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_87 ,
{ L_376 , L_377 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_134 ,
{ L_378 , L_379 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_135 ,
{ L_380 , L_381 , V_507 , V_506 ,
NULL , 0 , L_382 , V_498 } } ,
{ & V_136 ,
{ L_383 , L_384 , V_507 , V_506 ,
NULL , 0 , L_385 , V_498 } } ,
{ & V_140 ,
{ L_386 , L_387 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
#if 0
{ &hf_netlogon_principal,
{ "Principal", "netlogon.principal", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ & V_100 ,
{ L_8 , L_388 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_165 ,
{ L_389 , L_390 , V_499 , V_497 ,
NULL , 0 , L_391 , V_498 } } ,
{ & V_85 ,
{ L_38 , L_392 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_443 ,
{ L_161 , L_393 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_233 ,
{ L_107 , L_394 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_337 ,
{ L_395 , L_396 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_336 ,
{ L_397 , L_398 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_334 ,
{ L_108 , L_399 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_335 ,
{ L_400 , L_401 , V_499 , V_497 ,
F_304 ( V_511 ) , 0 , NULL , V_498 } } ,
{ & V_338 ,
{ L_402 , L_403 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_360 ,
{ L_404 , L_405 , V_507 , V_506 ,
NULL , 0 , L_406 , V_498 } } ,
{ & V_91 ,
{ L_407 , L_408 , V_507 , V_506 ,
NULL , 0 , L_409 , V_498 } } ,
{ & V_361 ,
{ L_410 , L_411 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_362 ,
{ L_412 , L_413 , V_507 , V_506 ,
NULL , 0 , L_414 , V_498 } } ,
{ & V_200 ,
{ L_415 , L_416 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_359 ,
{ L_417 , L_418 , V_507 , V_506 ,
NULL , 0 , L_118 , V_498 } } ,
{ & V_215 ,
{ L_419 , L_420 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_217 ,
{ L_421 , L_422 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_444 ,
{ L_423 , L_424 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_372 ,
{ L_425 , L_426 , V_507 , V_506 ,
NULL , 0 , L_427 , V_498 } } ,
{ & V_373 ,
{ L_428 , L_429 , V_507 , V_506 ,
NULL , 0 , L_132 , V_498 } } ,
{ & V_365 ,
{ L_430 , L_431 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_86 ,
{ L_8 , L_388 , V_507 , V_506 ,
NULL , 0 , L_432 , V_498 } } ,
{ & V_210 ,
{ L_433 , L_434 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_268 ,
{ L_435 , L_436 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_152 ,
{ L_437 , L_438 , V_507 , V_506 ,
NULL , 0 , L_439 , V_498 } } ,
{ & V_153 ,
{ L_440 , L_441 , V_507 , V_506 ,
NULL , 0 , L_442 , V_498 } } ,
{ & V_72 ,
{ L_443 , L_444 , V_507 , V_506 ,
NULL , 0 , L_445 , V_498 } } ,
{ & V_194 ,
{ L_446 , L_447 , V_507 , V_506 ,
NULL , 0 , L_448 , V_498 } } ,
{ & V_95 ,
{ L_449 , L_450 , V_496 , V_497 ,
NULL , 0x0 , L_451 , V_498 } } ,
{ & V_76 ,
{ L_449 , L_452 , V_499 , V_497 ,
NULL , 0x0 , L_451 , V_498 } } ,
{ & V_137 ,
{ L_453 , L_454 , V_496 , V_497 ,
NULL , 0x0 , L_455 , V_498 } } ,
{ & V_77 ,
{ L_453 , L_456 , V_499 , V_497 ,
NULL , 0x0 , L_455 , V_498 } } ,
{ & V_207 ,
{ L_457 , L_458 , V_496 , V_497 | V_501 ,
& V_512 , 0x0 , L_459 , V_498 } } ,
{ & V_208 ,
{ L_460 , L_461 , V_496 , V_497 ,
NULL , 0x0 , L_462 , V_498 } } ,
{ & V_112 ,
{ L_463 , L_464 , V_496 , V_497 ,
NULL , 0x0 , L_465 , V_498 } } ,
{ & V_169 ,
{ L_466 , L_467 , V_496 , V_497 ,
NULL , 0x0 , L_468 , V_498 } } ,
{ & V_211 ,
{ L_469 , L_470 , V_496 , V_497 ,
NULL , 0x0 , L_471 , V_498 } } ,
{ & V_212 ,
{ L_472 , L_473 , V_496 , V_497 ,
NULL , 0x0 , L_474 , V_498 } } ,
{ & V_192 ,
{ L_475 , L_476 , V_496 , V_497 ,
F_304 ( V_513 ) , 0x0 , L_477 , V_498 } } ,
{ & V_280 ,
{ L_478 , L_479 , V_496 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_248 ,
{ L_480 , L_481 , V_496 , V_497 ,
F_304 ( V_252 ) , 0x0 , NULL , V_498 } } ,
{ & V_345 ,
{ L_482 , L_483 , V_499 , V_497 ,
NULL , 0x0 , L_484 , V_498 } } ,
{ & V_271 ,
{ L_485 , L_486 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_262 ,
{ L_463 , L_487 , V_499 , V_497 ,
NULL , 0x0 , L_465 , V_498 } } ,
{ & V_264 ,
{ L_488 , L_489 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_265 ,
{ L_490 , L_491 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_117 ,
{ L_492 , L_493 , V_509 , V_510 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_138 ,
{ L_494 , L_495 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_218 ,
{ L_496 , L_497 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_125 ,
{ L_498 , L_499 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_139 ,
{ L_500 , L_501 , V_499 , V_497 ,
NULL , 0x0 , L_502 , V_498 } } ,
{ & V_234 ,
{ L_503 , L_504 , V_499 , V_497 ,
NULL , 0x0 , L_505 , V_498 } } ,
{ & V_150 ,
{ L_506 , L_507 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_266 ,
{ L_316 , L_508 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_70 ,
{ L_509 , L_510 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_130 ,
{ L_511 , L_512 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_75 ,
{ L_513 , L_514 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_238 ,
{ L_515 , L_516 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_254 ,
{ L_517 , L_518 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_256 ,
{ L_519 , L_520 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_255 ,
{ L_521 , L_522 , V_499 , V_497 ,
NULL , 0x0 , L_523 , V_498 } } ,
{ & V_227 ,
{ L_524 , L_525 , V_499 , V_497 ,
NULL , 0x0 , L_526 , V_498 } } ,
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
{ L_527 , L_528 , V_499 , V_497 ,
NULL , 0x0 , L_529 , V_498 } } ,
{ & V_364 ,
{ L_530 , L_531 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_270 ,
{ L_532 , L_533 , V_499 , V_497 ,
NULL , 0x0 , L_534 , V_498 } } ,
{ & V_225 ,
{ L_535 , L_536 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_221 ,
{ L_537 , L_538 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_222 ,
{ L_539 , L_540 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_223 ,
{ L_541 , L_542 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_224 ,
{ L_543 , L_544 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_260 ,
{ L_545 , L_546 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_403 ,
{ L_547 , L_548 , V_499 , V_500 ,
NULL , 0x0 , L_549 , V_498 } } ,
#if 0
{ &hf_netlogon_neg_flags_80000000,
{ "Not used 80000000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_80000000, "Not used", HFILL }},
#endif
{ & V_377 ,
{ L_550 , L_551 , V_514 , 32 , F_305 ( & V_515 ) , V_516 , NULL , V_498 } } ,
{ & V_378 ,
{ L_552 , L_551 , V_514 , 32 , F_305 ( & V_515 ) , V_517 , L_553 , V_498 } } ,
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
{ L_554 , L_555 , V_514 , 32 , F_305 ( & V_515 ) , V_518 , L_556 , V_498 } } ,
#if 0
{ &hf_netlogon_neg_flags_800000,
{ "Not used 800000", "ntlmssp.neg_flags.na8000000", FT_BOOLEAN, 32, TFS(&tfs_set_notset), NETLOGON_FLAG_800000, "Not used", HFILL }},
#endif
{ & V_380 ,
{ L_557 , L_558 , V_514 , 32 , F_305 ( & V_515 ) , V_519 , L_559 , V_498 } } ,
{ & V_381 ,
{ L_560 , L_561 , V_514 , 32 , F_305 ( & V_515 ) , V_520 , L_562 , V_498 } } ,
{ & V_382 ,
{ L_563 , L_555 , V_514 , 32 , F_305 ( & V_515 ) , V_521 , L_564 , V_498 } } ,
{ & V_383 ,
{ L_565 , L_566 , V_514 , 32 , F_305 ( & V_515 ) , V_522 , NULL , V_498 } } ,
{ & V_384 ,
{ L_567 , L_568 , V_514 , 32 , F_305 ( & V_515 ) , V_523 , L_569 , V_498 } } ,
{ & V_385 ,
{ L_570 , L_571 , V_514 , 32 , F_305 ( & V_515 ) , V_524 , L_572 , V_498 } } ,
{ & V_386 ,
{ L_573 , L_574 , V_514 , 32 , F_305 ( & V_515 ) , V_525 , L_575 , V_498 } } ,
{ & V_387 ,
{ L_576 , L_577 , V_514 , 32 , F_305 ( & V_515 ) , V_526 , L_578 , V_498 } } ,
{ & V_388 ,
{ L_579 , L_580 , V_514 , 32 , F_305 ( & V_515 ) , V_435 , NULL , V_498 } } ,
{ & V_389 ,
{ L_581 , L_582 , V_514 , 32 , F_305 ( & V_515 ) , V_527 , NULL , V_498 } } ,
{ & V_390 ,
{ L_583 , L_584 , V_514 , 32 , F_305 ( & V_515 ) , V_528 , NULL , V_498 } } ,
{ & V_391 ,
{ L_585 , L_586 , V_514 , 32 , F_305 ( & V_515 ) , V_529 , NULL , V_498 } } ,
{ & V_392 ,
{ L_587 , L_588 , V_514 , 32 , F_305 ( & V_515 ) , V_530 , NULL , V_498 } } ,
{ & V_393 ,
{ L_589 , L_590 , V_514 , 32 , F_305 ( & V_515 ) , V_531 , NULL , V_498 } } ,
{ & V_394 ,
{ L_591 , L_592 , V_514 , 32 , F_305 ( & V_515 ) , V_532 , L_593 , V_498 } } ,
{ & V_395 ,
{ L_594 , L_595 , V_514 , 32 , F_305 ( & V_515 ) , V_533 , NULL , V_498 } } ,
{ & V_396 ,
{ L_596 , L_597 , V_514 , 32 , F_305 ( & V_515 ) , V_534 , NULL , V_498 } } ,
{ & V_397 ,
{ L_598 , L_599 , V_514 , 32 , F_305 ( & V_515 ) , V_535 , NULL , V_498 } } ,
{ & V_398 ,
{ L_600 , L_601 , V_514 , 32 , F_305 ( & V_515 ) , V_536 , L_602 , V_498 } } ,
{ & V_399 ,
{ L_603 , L_604 , V_514 , 32 , F_305 ( & V_515 ) , V_537 , L_605 , V_498 } } ,
{ & V_400 ,
{ L_606 , L_607 , V_514 , 32 , F_305 ( & V_515 ) , V_538 , L_608 , V_498 } } ,
{ & V_401 ,
{ L_609 , L_610 , V_514 , 32 , F_305 ( & V_515 ) , V_539 , L_611 , V_498 } } ,
{ & V_402 ,
{ L_612 , L_613 , V_514 , 32 , F_305 ( & V_515 ) , V_540 , NULL , V_498 } } ,
{ & V_329 ,
{ L_614 , L_615 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_328 ,
{ L_616 , L_617 ,
V_514 , 32 , F_305 ( & V_541 ) , V_542 ,
L_618 , V_498 } } ,
{ & V_327 ,
{ L_619 , L_620 ,
V_514 , 32 , F_305 ( & V_543 ) , V_544 ,
L_621 , V_498 } } ,
{ & V_326 ,
{ L_622 , L_623 ,
V_514 , 32 , F_305 ( & V_545 ) , V_546 ,
L_624 , V_498 } } ,
{ & V_325 ,
{ L_625 , L_626 ,
V_514 , 32 , F_305 ( & V_547 ) , V_548 ,
L_627 , V_498 } } ,
{ & V_324 ,
{ L_628 , L_629 ,
V_514 , 32 , F_305 ( & V_549 ) , V_550 ,
L_630 , V_498 } } ,
{ & V_323 ,
{ L_631 , L_632 ,
V_514 , 32 , F_305 ( & V_551 ) , V_552 ,
L_633 , V_498 } } ,
{ & V_322 ,
{ L_634 , L_635 ,
V_514 , 32 , F_305 ( & V_553 ) , V_554 ,
L_636 , V_498 } } ,
{ & V_321 ,
{ L_637 , L_638 ,
V_514 , 32 , F_305 ( & V_555 ) , V_556 ,
L_639 , V_498 } } ,
{ & V_320 ,
{ L_640 , L_641 ,
V_514 , 32 , F_305 ( & V_557 ) , V_558 ,
L_642 , V_498 } } ,
{ & V_319 ,
{ L_643 , L_644 ,
V_514 , 32 , F_305 ( & V_559 ) , V_560 ,
L_645 , V_498 } } ,
{ & V_318 ,
{ L_646 , L_647 ,
V_514 , 32 , F_305 ( & V_561 ) , V_562 ,
L_648 , V_498 } } ,
{ & V_317 ,
{ L_428 , L_649 ,
V_514 , 32 , F_305 ( & V_563 ) , V_564 ,
NULL , V_498 } } ,
{ & V_316 ,
{ L_110 , L_650 ,
V_514 , 32 , F_305 ( & V_565 ) , V_566 ,
NULL , V_498 } } ,
{ & V_314 ,
{ L_316 , L_651 , V_499 , V_500 ,
NULL , 0x0 , L_652 , V_498 } } ,
{ & V_313 ,
{ L_653 , L_654 ,
V_514 , 32 , F_305 ( & V_567 ) , V_568 ,
L_655 , V_498 } } ,
{ & V_312 ,
{ L_656 , L_657 ,
V_514 , 32 , F_305 ( & V_569 ) , V_570 ,
L_658 , V_498 } } ,
{ & V_311 ,
{ L_659 , L_660 ,
V_514 , 32 , F_305 ( & V_571 ) , V_572 ,
L_661 , V_498 } } ,
{ & V_310 ,
{ L_662 , L_663 ,
V_514 , 32 , F_305 ( & V_573 ) , V_574 ,
L_664 , V_498 } } ,
{ & V_309 ,
{ L_665 , L_666 ,
V_514 , 32 , F_305 ( & V_575 ) , V_576 ,
L_667 , V_498 } } ,
{ & V_308 ,
{ L_668 , L_669 ,
V_514 , 32 , F_305 ( & V_577 ) , V_578 ,
L_670 , V_498 } } ,
{ & V_307 ,
{ L_671 , L_672 ,
V_514 , 32 , F_305 ( & V_579 ) , V_580 ,
L_673 , V_498 } } ,
{ & V_306 ,
{ L_674 , L_675 ,
V_514 , 32 , F_305 ( & V_581 ) , V_582 ,
L_676 , V_498 } } ,
{ & V_305 ,
{ L_677 , L_678 ,
V_514 , 32 , F_305 ( & V_583 ) , V_584 ,
L_679 , V_498 } } ,
{ & V_304 ,
{ L_680 , L_681 ,
V_514 , 32 , F_305 ( & V_585 ) , V_586 ,
L_682 , V_498 } } ,
{ & V_303 ,
{ L_683 , L_684 ,
V_514 , 32 , F_305 ( & V_587 ) , V_588 ,
L_685 , V_498 } } ,
{ & V_302 ,
{ L_686 , L_687 ,
V_514 , 32 , F_305 ( & V_589 ) , V_590 ,
L_688 , V_498 } } ,
{ & V_301 ,
{ L_689 , L_690 ,
V_514 , 32 , F_305 ( & V_591 ) , V_592 ,
L_691 , V_498 } } ,
{ & V_299 ,
{ L_692 , L_693 ,
V_514 , 32 , F_305 ( & V_593 ) , V_594 ,
L_694 , V_498 } } ,
{ & V_300 ,
{ L_695 , L_696 ,
V_514 , 32 , F_305 ( & V_595 ) , V_596 ,
L_697 , V_498 } } ,
{ & V_298 ,
{ L_698 , L_699 ,
V_514 , 32 , F_305 ( & V_597 ) , V_598 ,
L_700 , V_498 } } ,
{ & V_297 ,
{ L_701 , L_702 ,
V_514 , 32 , F_305 ( & V_599 ) , V_600 ,
L_703 , V_498 } } ,
{ & V_295 ,
{ L_704 , L_705 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_294 ,
{ L_706 , L_707 , V_514 , 32 ,
F_305 ( & V_601 ) , 0x00000001 , NULL , V_498 } } ,
{ & V_293 ,
{ L_708 , L_709 , V_514 , 32 ,
F_305 ( & V_602 ) , 0x00000002 , NULL , V_498 } } ,
{ & V_292 ,
{ L_710 , L_711 , V_514 , 32 ,
F_305 ( & V_603 ) , 0x00000004 , NULL , V_498 } } ,
{ & V_291 ,
{ L_712 , L_713 , V_514 , 32 ,
F_305 ( & V_604 ) , 0x00000008 , NULL , V_498 } } ,
{ & V_290 ,
{ L_714 , L_715 , V_514 , 32 ,
F_305 ( & V_605 ) , 0x00000010 , NULL , V_498 } } ,
{ & V_289 ,
{ L_716 , L_717 , V_514 , 32 ,
F_305 ( & V_606 ) , 0x00000020 , NULL , V_498 } } ,
{ & V_288 ,
{ L_718 , L_719 , V_514 , 32 ,
F_305 ( & V_607 ) , 0x00000040 , NULL , V_498 } } ,
{ & V_344 ,
{ L_720 , L_721 , V_499 , V_497 ,
F_304 ( V_608 ) , 0x0 , NULL , V_498 } } ,
{ & V_36 ,
{ L_722 , L_723 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_31 ,
{ L_724 , L_725 ,
V_514 , 32 , F_305 ( & V_515 ) , V_609 ,
NULL , V_498 } } ,
{ & V_32 ,
{ L_726 , L_727 ,
V_514 , 32 , F_305 ( & V_515 ) , V_610 ,
NULL , V_498 } } ,
{ & V_33 ,
{ L_728 , L_729 ,
V_514 , 32 , F_305 ( & V_515 ) , V_611 ,
NULL , V_498 } } ,
{ & V_34 ,
{ L_730 , L_731 ,
V_514 , 32 , F_305 ( & V_515 ) , V_612 ,
NULL , V_498 } } ,
{ & V_287 ,
{ L_732 , L_733 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_281 ,
{ L_734 , L_735 ,
V_514 , 32 , F_305 ( & V_613 ) , V_614 ,
L_736 , V_498 } } ,
{ & V_285 ,
{ L_737 , L_738 ,
V_514 , 32 , F_305 ( & V_615 ) , V_616 ,
L_739 , V_498 } } ,
{ & V_286 ,
{ L_740 , L_741 ,
V_514 , 32 , F_305 ( & V_617 ) , V_618 ,
L_742 , V_498 } } ,
{ & V_282 ,
{ L_743 , L_744 ,
V_514 , 32 , F_305 ( & V_619 ) , V_620 ,
L_745 , V_498 } } ,
{ & V_283 ,
{ L_746 , L_747 ,
V_514 , 32 , F_305 ( & V_621 ) , V_622 ,
L_748 , V_498 } } ,
{ & V_284 ,
{ L_749 , L_750 ,
V_514 , 32 , F_305 ( & V_623 ) , V_624 ,
L_751 , V_498 } } ,
{ & V_343 ,
{ L_752 , L_753 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_78 ,
{ L_754 , L_755 , V_509 , V_510 ,
NULL , 0 , L_756 , V_498 } } ,
{ & V_81 ,
{ L_757 , L_758 , V_509 , V_510 ,
NULL , 0 , L_759 , V_498 } } ,
{ & V_80 ,
{ L_760 , L_761 , V_509 , V_510 ,
NULL , 0 , L_762 , V_498 } } ,
{ & V_79 ,
{ L_763 , L_764 , V_509 , V_510 ,
NULL , 0 , L_762 , V_498 } } ,
{ & V_132 ,
{ L_765 , L_766 , V_509 , V_510 ,
NULL , 0 , L_767 , V_498 } } ,
{ & V_82 ,
{ L_768 , L_769 , V_625 , V_506 ,
NULL , 0 , L_770 , V_498 } } ,
{ & V_83 ,
{ L_771 , L_772 , V_509 , V_510 ,
NULL , 0 , L_773 , V_498 } } ,
{ & V_84 ,
{ L_774 , L_775 , V_509 , V_510 ,
NULL , 0 , L_776 , V_498 } } ,
{ & V_214 ,
{ L_777 , L_778 , V_509 , V_510 ,
NULL , 0 , L_779 , V_498 } } ,
{ & V_213 ,
{ L_780 , L_781 , V_509 , V_510 ,
NULL , 0 , L_782 , V_498 } } ,
{ & V_231 ,
{ L_783 , L_784 , V_509 , V_510 ,
NULL , 0 , L_785 , V_498 } } ,
{ & V_232 ,
{ L_786 , L_787 , V_509 , V_510 ,
NULL , 0 , L_788 , V_498 } } ,
{ & V_243 ,
{ L_789 , L_790 , V_509 , V_510 ,
NULL , 0 , L_791 , V_498 } } ,
{ & V_245 ,
{ L_792 , L_793 , V_509 , V_510 ,
NULL , 0 , L_794 , V_498 } } ,
{ & V_228 ,
{ L_795 , L_796 , V_625 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_226 ,
{ L_797 , L_798 , V_625 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_405 ,
{ L_799 , L_800 , V_505 , V_506 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_427 ,
{ L_801 , L_802 , V_505 , V_506 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_428 ,
{ L_803 , L_804 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_183 ,
{ L_805 , L_806 , V_505 , V_506 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_191 ,
{ L_807 , L_808 , V_505 , V_506 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_454 ,
{ L_809 , L_810 , V_499 , V_500 ,
F_304 ( V_626 ) , 0x0 , NULL , V_498 } } ,
{ & V_455 ,
{ L_811 , L_812 , V_499 , V_500 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_448 ,
{ L_813 , L_814 , V_514 , 32 ,
NULL , 0x00000001 , NULL , V_498 } } ,
{ & V_449 ,
{ L_815 , L_816 , V_514 , 32 ,
NULL , 0x00000002 , NULL , V_498 } } ,
{ & V_450 ,
{ L_428 , L_817 , V_514 , 32 ,
NULL , 0x00000004 , NULL , V_498 } } ,
{ & V_451 ,
{ L_423 , L_818 , V_514 , 32 ,
NULL , 0x00000008 , NULL , V_498 } } ,
{ & V_452 ,
{ L_819 , L_820 , V_514 , 32 ,
NULL , 0x00000010 , NULL , V_498 } } ,
{ & V_459 ,
{ L_813 , L_821 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_460 ,
{ L_815 , L_822 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_464 ,
{ L_819 , L_823 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_462 ,
{ L_428 , L_824 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_463 ,
{ L_423 , L_825 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_110 ,
{ L_826 , L_827 , V_499 , V_497 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_108 ,
{ L_828 , L_829 , V_507 , V_506 ,
NULL , 0 , NULL , V_498 } } ,
{ & V_485 ,
{ L_830 , L_831 , V_627 , V_506 ,
NULL , 0x0 , L_832 , V_498 } } ,
{ & V_487 ,
{ L_833 , L_834 , V_496 , V_500 ,
F_304 ( V_628 ) , 0 , NULL , V_498 } } ,
{ & V_488 ,
{ L_835 , L_836 , V_496 , V_500 ,
F_304 ( V_629 ) , 0 , NULL , V_498 } } ,
{ & V_489 ,
{ L_316 , L_837 , V_505 , V_506 , NULL ,
0x0 , NULL , V_498 } } ,
{ & V_491 ,
{ L_838 , L_839 , V_505 , V_506 , NULL ,
0x0 , NULL , V_498 } } ,
{ & V_490 ,
{ L_840 , L_841 , V_505 , V_506 , NULL ,
0x0 , NULL , V_498 } } ,
{ & V_492 ,
{ L_842 , L_843 , V_505 , V_506 , NULL ,
0x0 , NULL , V_498 } } ,
{ & V_121 ,
{ L_844 , L_845 ,
V_514 , 32 , F_305 ( & V_630 ) , 0x00000001 ,
L_846 , V_498 } } ,
{ & V_120 ,
{ L_847 , L_848 ,
V_514 , 32 , F_305 ( & V_631 ) , 0x00000002 ,
L_849 , V_498 } } ,
{ & V_119 ,
{ L_850 , L_851 ,
V_514 , 32 , F_305 ( & V_632 ) , 0x00000004 ,
L_852 , V_498 } } ,
{ & V_129 ,
{ L_853 , L_854 ,
V_514 , 32 , F_305 ( & V_633 ) , 0x00000020 ,
L_855 , V_498 } } ,
{ & V_128 ,
{ L_856 , L_857 ,
V_514 , 32 , F_305 ( & V_634 ) , 0x00000200 ,
L_858 , V_498 } } ,
{ & V_53 ,
{ L_859 , L_860 ,
V_514 , 32 , F_305 ( & V_635 ) , 0x00010000 ,
L_861 , V_498 } } ,
{ & V_54 ,
{ L_862 , L_863 ,
V_514 , 32 , F_305 ( & V_636 ) , 0x00008000 ,
L_864 , V_498 } } ,
{ & V_55 ,
{ L_865 , L_866 ,
V_514 , 32 , F_305 ( & V_637 ) , 0x00004000 ,
L_867 , V_498 } } ,
{ & V_56 ,
{ L_868 , L_869 ,
V_514 , 32 , F_305 ( & V_638 ) , 0x00002000 ,
L_870 , V_498 } } ,
{ & V_57 ,
{ L_871 , L_872 ,
V_514 , 32 , F_305 ( & V_639 ) , 0x00001000 ,
L_873 , V_498 } } ,
{ & V_58 ,
{ L_874 , L_875 ,
V_514 , 32 , F_305 ( & V_640 ) , 0x00000800 ,
L_876 , V_498 } } ,
{ & V_59 ,
{ L_877 , L_878 ,
V_514 , 32 , F_305 ( & V_641 ) , 0x00000400 ,
L_879 , V_498 } } ,
{ & V_60 ,
{ L_880 , L_881 ,
V_514 , 32 , F_305 ( & V_642 ) , 0x00000200 ,
L_882 , V_498 } } ,
{ & V_61 ,
{ L_883 , L_884 ,
V_514 , 32 , F_305 ( & V_643 ) , 0x00000100 ,
L_885 , V_498 } } ,
{ & V_62 ,
{ L_886 , L_887 ,
V_514 , 32 , F_305 ( & V_644 ) , 0x00000080 ,
L_888 , V_498 } } ,
{ & V_63 ,
{ L_889 , L_890 ,
V_514 , 32 , F_305 ( & V_645 ) , 0x00000040 ,
L_891 , V_498 } } ,
{ & V_64 ,
{ L_892 , L_893 ,
V_514 , 32 , F_305 ( & V_646 ) , 0x00000020 ,
L_894 , V_498 } } ,
{ & V_65 ,
{ L_895 , L_896 ,
V_514 , 32 , F_305 ( & V_647 ) , 0x00000010 ,
L_897 , V_498 } } ,
{ & V_66 ,
{ L_898 , L_899 ,
V_514 , 32 , F_305 ( & V_648 ) , 0x00000008 ,
L_900 , V_498 } } ,
{ & V_67 ,
{ L_901 , L_902 ,
V_514 , 32 , F_305 ( & V_649 ) , 0x00000004 ,
L_903 , V_498 } } ,
{ & V_68 ,
{ L_904 , L_905 ,
V_514 , 32 , F_305 ( & V_650 ) , 0x00000002 ,
L_906 , V_498 } } ,
{ & V_69 ,
{ L_907 , L_908 ,
V_514 , 32 , F_305 ( & V_651 ) , 0x00000001 ,
L_909 , V_498 } } ,
#if 0
{ &hf_netlogon_dnsdomaininfo,
{ "DnsDomainInfo", "netlogon.dnsdomaininfo", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
#endif
{ & V_349 ,
{ L_910 , L_911 , V_627 , V_506 , NULL , 0 , NULL , V_498 } } ,
{ & V_348 ,
{ L_910 , L_912 , V_627 , V_506 , NULL , 0 , NULL , V_498 } } ,
{ & V_350 ,
{ L_913 , L_914 , V_652 , V_506 , NULL , 0 , NULL , V_498 } } ,
{ & V_353 ,
{ L_915 , L_916 , V_627 , V_506 , NULL , 0 , NULL , V_498 } } ,
{ & V_352 ,
{ L_917 , L_918 , V_627 , V_506 , NULL , 0 , NULL , V_498 } } ,
{ & V_351 ,
{ L_919 , L_920 , V_627 , V_506 , NULL , 0 , NULL , V_498 } } ,
{ & V_167 ,
{ L_921 , L_922 , V_507 , V_506 ,
NULL , 0 , L_923 , V_498 } } ,
{ & V_168 ,
{ L_924 , L_925 , V_499 , V_500 ,
NULL , 0x0 , L_926 , V_498 } } ,
{ & V_166 ,
{ L_927 , L_928 , V_507 , V_506 ,
NULL , 0 , L_929 , V_498 } } ,
{ & V_94 ,
{ L_930 , L_931 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
{ & V_259 ,
{ L_932 , L_933 , V_499 , V_497 ,
NULL , 0x0 , NULL , V_498 } } ,
} ;
static T_2 * V_653 [] = {
& V_654 ,
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
& V_655 ,
& V_354 ,
& V_357 ,
& V_37 ,
& V_296 ,
& V_315 ,
& V_330 ,
& V_453 ,
& V_456 ,
& V_486 ,
& V_123 ,
& V_131 ,
& V_347 ,
& V_71
} ;
V_656 = F_306 ( L_934 , L_935 , L_936 ) ;
F_307 ( V_656 , V_494 , F_308 ( V_494 ) ) ;
F_309 ( V_653 , F_308 ( V_653 ) ) ;
V_189 = F_310 ( F_311 () , F_84 () , F_9 , F_7 ) ;
#if 0
schannel_auths = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), netlogon_auth_hash, netlogon_auth_equal);
#endif
}
void
F_312 ( void )
{
V_406 . V_407 = FALSE ;
V_406 . V_186 = 0 ;
F_313 ( V_656 , V_654 ,
& V_657 , V_658 ,
V_659 , V_495 ) ;
F_314 ( V_660 ,
V_661 ,
& V_662 ) ;
F_314 ( V_663 ,
V_661 ,
& V_662 ) ;
}
