static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
return ( V_3 -> V_5 == V_4 -> V_5 ) ;
}
static T_4
F_2 ( T_2 V_1 )
{
const T_3 * V_6 = ( const T_3 * ) V_1 ;
T_4 V_7 ;
V_7 = V_6 -> V_5 ;
return V_7 ;
}
static void
F_3 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , int V_11 )
{
int V_12 , V_13 , V_14 , V_15 , V_16 ;
T_8 * V_17 ;
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_18 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_20 , V_8 , V_11 + 4 ,
V_16 , V_21 | V_22 ) ;
V_11 += 4 + V_16 + ( 4 - ( V_16 % 4 ) ) ;
V_12 = F_6 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_23 , V_8 , V_11 , 4 , V_19 ) ;
V_11 += 4 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_24 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_25 , V_8 , V_11 + 4 ,
V_16 , V_21 | V_22 ) ;
V_11 += 4 + V_16 + ( 4 - ( V_16 % 4 ) ) ;
V_13 = F_6 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_26 , V_8 , V_11 ,
4 , V_19 ) ;
V_11 += 4 ;
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ ) {
V_17 = F_5 ( V_10 , V_27 , V_8 , V_11 , 1 , V_19 ) ;
switch ( F_4 ( V_8 , V_11 ) ) {
case V_28 :
case V_29 :
F_5 ( V_10 , V_30 , V_8 ,
V_11 + 4 , 8 , V_22 ) ;
break;
case V_31 :
F_5 ( V_10 , V_32 ,
V_8 , V_11 + 4 , 3 , V_19 ) ;
break;
case V_33 :
F_5 ( V_10 , V_34 , V_8 ,
V_11 + 4 , 3 , V_22 ) ;
break;
case V_35 :
F_5 ( V_10 , V_30 , V_8 ,
V_11 + 4 , 8 , V_22 ) ;
F_5 ( V_10 , V_36 , V_8 ,
V_11 + 8 , 8 , V_22 ) ;
break;
case V_37 :
F_5 ( V_10 , V_32 ,
V_8 , V_11 + 4 , 3 , V_19 ) ;
F_5 ( V_10 , V_36 , V_8 ,
V_11 + 4 , 8 , V_22 ) ;
break;
case V_38 :
F_5 ( V_10 , V_34 , V_8 ,
V_11 + 4 , 3 , V_22 ) ;
F_5 ( V_10 , V_36 , V_8 ,
V_11 + 4 , 8 , V_22 ) ;
break;
default:
F_7 ( V_9 , V_17 , & V_39 ) ;
}
V_11 += 12 ;
}
}
}
static void
F_8 ( T_5 * V_8 , int V_11 , T_7 * V_40 , T_9 V_41 )
{
static const int * V_42 [] = {
& V_43 ,
& V_44 ,
& V_45 ,
NULL
} ;
if ( ! V_41 ) {
F_9 ( V_40 , V_8 , V_11 , V_46 ,
V_47 , V_42 , V_22 , V_48 | V_49 ) ;
F_5 ( V_40 , V_50 , V_8 , V_11 + 4 , 4 , V_19 ) ;
}
}
static void
F_10 ( T_5 * V_8 , T_7 * V_40 , T_9 V_41 )
{
int V_11 = 16 ;
static const int * V_42 [] = {
& V_51 ,
& V_52 ,
NULL
} ;
if ( ! V_41 ) {
F_9 ( V_40 , V_8 , V_11 , V_53 ,
V_54 , V_42 , V_22 , V_48 | V_49 ) ;
F_5 ( V_40 , V_55 , V_8 , V_11 + 4 , 4 , V_19 ) ;
}
}
static void
F_11 ( T_5 * V_8 , T_7 * V_10 , T_9 V_41 )
{
int V_56 , V_14 , V_16 ;
int V_11 = 16 ;
if ( V_10 ) {
if ( ! V_41 ) {
V_56 = F_6 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_57 , V_8 , V_11 ,
4 , V_19 ) ;
V_11 += 4 ;
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_18 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_20 , V_8 , V_11 + 1 ,
V_16 , V_21 | V_22 ) ;
V_11 += V_16 + 1 + ( V_16 % 4 ) ;
F_5 ( V_10 , V_23 , V_8 , V_11 ,
4 , V_19 ) ;
V_11 += 4 ;
}
}
}
}
static void
F_12 ( T_5 * V_8 , T_7 * V_10 , T_9 V_41 )
{
int V_56 , V_14 , V_16 ;
int V_11 = 16 ;
if ( V_10 ) {
if ( V_41 ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_18 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_20 , V_8 , V_11 + 1 ,
V_16 , V_21 | V_22 ) ;
}
else {
V_56 = F_6 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_58 , V_8 , V_11 ,
4 , V_19 ) ;
V_11 += 4 ;
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_24 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_25 , V_8 , V_11 + 1 ,
V_16 , V_21 | V_22 ) ;
V_11 += V_16 + 1 + ( V_16 % 4 ) ;
F_5 ( V_10 , V_59 , V_8 , V_11 ,
4 , V_19 ) ;
V_11 += 4 ;
}
}
}
}
static void
F_13 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , T_9 V_41 )
{
int V_56 , V_14 , V_16 ;
int V_11 = 16 ;
T_8 * V_17 ;
if ( V_41 ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_24 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_25 , V_8 , V_11 + 1 ,
V_16 , V_21 | V_22 ) ;
}
else {
V_56 = F_6 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_26 , V_8 , V_11 ,
4 , V_19 ) ;
V_11 += 4 ;
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ ) {
V_17 = F_5 ( V_10 , V_27 , V_8 , V_11 , 1 , V_19 ) ;
switch ( F_4 ( V_8 , V_11 ) ) {
case V_28 :
case V_29 :
F_5 ( V_10 , V_30 , V_8 ,
V_11 + 4 , 8 , V_22 ) ;
break;
case V_31 :
F_5 ( V_10 , V_32 ,
V_8 , V_11 + 4 , 3 , V_19 ) ;
break;
case V_33 :
F_5 ( V_10 , V_34 , V_8 ,
V_11 + 4 , 3 , V_22 ) ;
break;
default:
F_7 ( V_9 , V_17 , & V_39 ) ;
}
V_11 += 12 ;
}
}
}
static void
F_14 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , T_9 V_41 )
{
int V_11 = 16 ;
if ( ! V_41 ) {
F_3 ( V_8 , V_9 , V_10 , V_11 ) ;
}
}
static void
F_15 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , T_9 V_41 )
{
int V_11 = 16 ;
int V_16 ;
if ( V_41 ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_18 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_20 , V_8 , V_11 + 4 ,
V_16 , V_21 | V_22 ) ;
}
else {
F_3 ( V_8 , V_9 , V_10 , V_11 ) ;
}
}
static void
F_16 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , T_9 V_41 )
{
int V_11 = 16 ;
if ( V_41 ) {
F_3 ( V_8 , V_9 , V_10 , V_11 ) ;
}
}
static void
F_17 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , T_9 V_41 )
{
int V_11 = 16 ;
if ( V_41 ) {
F_3 ( V_8 , V_9 , V_10 , V_11 ) ;
}
}
static void
F_18 ( T_5 * V_8 , T_7 * V_10 , T_9 V_41 )
{
int V_11 = 16 ;
int V_16 ;
if ( V_10 ) {
if ( V_41 ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_18 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_20 , V_8 , V_11 + 4 ,
V_16 , V_21 | V_22 ) ;
}
}
}
static void
F_19 ( T_5 * V_8 V_60 , T_7 * V_10 V_60 , T_9 V_41 V_60 )
{
return;
}
static void
F_20 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , T_9 V_41 )
{
int V_56 , V_14 , V_16 , V_61 ;
int V_11 = 16 ;
T_8 * V_17 ;
if ( V_41 ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_24 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_25 , V_8 , V_11 + 1 ,
V_16 , V_21 | V_22 ) ;
V_16 += ( V_16 % 4 ) ;
V_61 = F_21 ( V_8 ) - V_11 - V_16 ;
V_56 = V_61 / 12 ;
V_11 += V_16 ;
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ ) {
V_17 = F_5 ( V_10 , V_27 , V_8 , V_11 , 1 , V_19 ) ;
switch ( F_4 ( V_8 , V_11 ) ) {
case V_28 :
case V_29 :
F_5 ( V_10 , V_30 , V_8 ,
V_11 + 4 , 8 , V_22 ) ;
break;
case V_31 :
F_5 ( V_10 , V_32 ,
V_8 , V_11 + 4 , 3 , V_19 ) ;
break;
case V_33 :
F_5 ( V_10 , V_34 , V_8 ,
V_11 + 4 , 3 , V_22 ) ;
break;
default:
F_7 ( V_9 , V_17 , & V_39 ) ;
}
V_11 += 12 ;
}
}
}
static void
F_22 ( T_5 * V_8 , T_7 * V_10 , T_9 V_41 )
{
int V_11 = 16 ;
int V_16 ;
if ( V_10 ) {
if ( V_41 ) {
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_18 , V_8 , V_11 ,
1 , V_19 ) ;
F_5 ( V_10 , V_20 , V_8 , V_11 + 4 ,
V_16 , V_21 | V_22 ) ;
V_16 += ( V_16 % 4 ) ;
V_11 += V_16 ;
V_16 = F_4 ( V_8 , V_11 ) ;
F_5 ( V_10 , V_24 , V_8 , V_11 , 1 , V_19 ) ;
F_5 ( V_10 , V_25 , V_8 , V_11 + 4 ,
V_16 , V_21 | V_22 ) ;
}
}
}
static void
F_23 ( T_5 * V_8 , T_7 * V_10 )
{
int V_11 = 0 ;
if ( V_10 ) {
F_5 ( V_10 , V_62 , V_8 , V_11 + 13 , 1 , V_19 ) ;
F_5 ( V_10 , V_63 , V_8 , V_11 + 14 , 1 , V_19 ) ;
F_5 ( V_10 , V_64 , V_8 , V_11 + 15 , 1 , V_19 ) ;
}
}
static int
F_24 ( T_5 * V_8 , T_6 * V_9 , T_7 * V_10 , void * V_65 )
{
T_8 * V_17 ;
T_7 * V_66 = NULL ;
int V_11 = 0 ;
T_10 V_67 ;
int V_68 ;
int V_69 = 0 ;
T_11 * V_70 ;
T_12 * V_71 ;
T_3 V_72 , * V_73 ;
T_9 V_41 = TRUE ;
T_13 * V_74 ;
if ( V_65 == NULL )
return 0 ;
V_74 = ( T_13 * ) V_65 ;
F_25 ( V_9 -> V_75 , V_76 , L_1 ) ;
F_26 ( V_8 , ( V_77 * ) & V_67 , V_11 , V_78 ) ;
V_67 . V_79 = F_4 ( V_8 , V_11 + 1 ) ;
V_67 . V_80 = F_27 ( V_8 , V_11 ) ;
V_67 . V_68 = F_28 ( V_67 . V_68 ) ;
V_68 = V_67 . V_68 ;
V_67 . V_81 = F_28 ( V_67 . V_81 ) ;
if ( V_10 ) {
V_17 = F_29 ( V_10 , V_82 , V_8 , 0 ,
F_30 ( V_8 ) ,
L_1 ) ;
V_66 = F_31 ( V_17 , V_83 ) ;
F_5 ( V_66 , V_84 , V_8 , V_11 + 8 , 2 , V_19 ) ;
F_5 ( V_66 , V_85 , V_8 , V_11 + 10 ,
2 , V_19 ) ;
}
if ( ( V_68 != V_86 ) && ( V_68 != V_87 ) ) {
V_70 = F_32 ( V_9 -> V_88 , & V_9 -> V_89 , & V_9 -> V_90 ,
V_9 -> V_91 , V_74 -> V_92 ,
V_74 -> V_93 , V_94 ) ;
if ( ! V_70 ) {
V_70 = F_33 ( V_9 -> V_88 , & V_9 -> V_89 , & V_9 -> V_90 ,
V_9 -> V_91 , V_74 -> V_92 ,
V_74 -> V_93 , V_94 ) ;
}
V_72 . V_5 = V_70 -> V_95 ;
V_71 = ( T_12 * ) F_34 ( V_96 ,
& V_72 ) ;
if ( V_71 ) {
V_71 -> V_68 = V_68 ;
}
else {
V_73 = F_35 ( F_36 () , T_3 ) ;
V_73 -> V_5 = V_70 -> V_95 ;
V_71 = F_35 ( F_36 () , T_12 ) ;
V_71 -> V_68 = V_68 ;
F_37 ( V_96 , V_73 , V_71 ) ;
}
F_38 ( V_9 -> V_75 , V_97 , F_39 ( V_68 , V_98 ,
L_2 ) ) ;
}
else {
V_70 = F_32 ( V_9 -> V_88 , & V_9 -> V_89 , & V_9 -> V_90 ,
V_9 -> V_91 , V_74 -> V_92 ,
V_74 -> V_93 , V_94 ) ;
V_41 = FALSE ;
if ( ! V_70 ) {
if ( V_68 == V_86 ) {
F_38 ( V_9 -> V_75 , V_97 ,
F_39 ( V_68 , V_98 ,
L_2 ) ) ;
F_40 ( V_66 , V_9 , & V_99 , V_8 , 0 , - 1 ,
L_3 ) ;
return 0 ;
}
}
else {
V_72 . V_5 = V_70 -> V_95 ;
V_71 = ( T_12 * ) F_34 ( V_96 , & V_72 ) ;
if ( V_71 != NULL ) {
if ( V_68 == V_86 )
V_68 = V_71 -> V_68 ;
else
V_69 = V_71 -> V_68 ;
}
if ( V_68 != V_87 ) {
F_41 ( V_9 -> V_75 , V_97 , L_4 ,
F_39 ( V_68 ,
V_98 , L_2 ) ) ;
}
else {
F_41 ( V_9 -> V_75 , V_97 , L_5 ,
F_39 ( V_69 ,
V_98 , L_2 ) ) ;
}
if ( ( V_71 == NULL ) && ( V_68 != V_87 ) ) {
F_40 ( V_66 , V_9 , & V_99 , V_8 , 0 , - 1 ,
L_6 ) ;
return 0 ;
}
}
}
switch ( V_68 ) {
case V_87 :
F_23 ( V_8 , V_66 ) ;
break;
case V_100 :
F_8 ( V_8 , 16 , V_66 , V_41 ) ;
break;
case V_101 :
F_10 ( V_8 , V_66 , V_41 ) ;
break;
case V_102 :
F_11 ( V_8 , V_66 , V_41 ) ;
break;
case V_103 :
F_12 ( V_8 , V_66 , V_41 ) ;
break;
case V_104 :
F_13 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_105 :
F_14 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_106 :
F_15 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_107 :
F_16 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_108 :
F_17 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_109 :
F_18 ( V_8 , V_66 , V_41 ) ;
break;
case V_110 :
F_19 ( V_8 , V_66 , V_41 ) ;
break;
case V_111 :
F_20 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_112 :
F_22 ( V_8 , V_66 , V_41 ) ;
break;
case V_113 :
F_20 ( V_8 , V_9 , V_66 , V_41 ) ;
break;
case V_114 :
F_22 ( V_8 , V_66 , V_41 ) ;
break;
case V_115 :
F_18 ( V_8 , V_66 , V_41 ) ;
break;
default:
F_42 ( V_8 , V_9 , V_10 ) ;
break;
}
return F_30 ( V_8 ) ;
}
void
F_43 ( void )
{
static T_14 V_116 [] = {
{ & V_84 ,
{ L_7 , L_8 ,
V_117 , V_118 , F_44 ( V_98 ) , 0x0 ,
NULL , V_119 } } ,
{ & V_50 ,
{ L_9 , L_10 ,
V_120 , V_118 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_55 ,
{ L_11 , L_12 ,
V_120 , V_118 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_58 ,
{ L_13 , L_14 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_18 ,
{ L_15 , L_16 ,
V_122 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_20 ,
{ L_17 , L_18 ,
V_123 , V_124 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_23 ,
{ L_19 , L_20 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_57 ,
{ L_21 , L_22 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_24 ,
{ L_23 , L_24 ,
V_122 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_25 ,
{ L_25 , L_26 ,
V_123 , V_124 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_59 ,
{ L_27 , L_28 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_26 ,
{ L_29 , L_30 ,
V_120 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_27 ,
{ L_31 , L_32 ,
V_122 , V_118 , F_44 ( V_125 ) , 0x0 ,
NULL , V_119 } } ,
#if 0
{ &hf_fcfzs_mbridlen,
{"Zone Member Identifier Length", "fcfzs.zonembr.idlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#endif
{ & V_30 ,
{ L_33 , L_34 ,
V_126 , V_124 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_34 ,
{ L_33 , L_35 ,
V_127 , V_128 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_32 ,
{ L_33 , L_36 ,
V_129 , V_118 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_62 ,
{ L_37 , L_38 ,
V_122 , V_118 , F_44 ( V_130 ) , 0x0 ,
NULL , V_119 } } ,
{ & V_63 ,
{ L_39 , L_40 ,
V_122 , V_118 , F_44 ( V_131 ) , 0x0 ,
NULL , V_119 } } ,
{ & V_64 ,
{ L_41 , L_42 ,
V_122 , V_118 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_85 ,
{ L_43 , L_44 ,
V_117 , V_121 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_36 ,
{ L_45 , L_46 ,
V_127 , V_124 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_46 ,
{ L_47 , L_48 ,
V_122 , V_118 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_43 ,
{ L_49 , L_50 ,
V_132 , 8 , F_45 ( & V_133 ) , 0x80 ,
NULL , V_119 } } ,
{ & V_44 ,
{ L_51 , L_52 ,
V_132 , 8 , F_45 ( & V_133 ) , 0x40 ,
NULL , V_119 } } ,
{ & V_45 ,
{ L_53 , L_54 ,
V_132 , 8 , F_45 ( & V_134 ) , 0x01 ,
NULL , V_119 } } ,
{ & V_53 ,
{ L_55 , L_56 ,
V_122 , V_118 , NULL , 0x0 ,
NULL , V_119 } } ,
{ & V_51 ,
{ L_57 , L_58 ,
V_132 , 8 , F_45 ( & V_135 ) , 0x80 ,
NULL , V_119 } } ,
{ & V_52 ,
{ L_59 , L_60 ,
V_132 , 8 , F_45 ( & V_135 ) , 0x40 ,
NULL , V_119 } } ,
} ;
static T_1 * V_136 [] = {
& V_83 ,
& V_47 ,
& V_54 ,
} ;
static T_15 V_137 [] = {
{ & V_99 , { L_61 , V_138 , V_139 , L_62 , V_140 } } ,
{ & V_39 , { L_63 , V_141 , V_139 , L_64 , V_140 } } ,
} ;
T_16 * V_142 ;
V_82 = F_46 ( L_65 , L_66 , L_67 ) ;
F_47 ( V_82 , V_116 , F_48 ( V_116 ) ) ;
F_49 ( V_136 , F_48 ( V_136 ) ) ;
V_142 = F_50 ( V_82 ) ;
F_51 ( V_142 , V_137 , F_48 ( V_137 ) ) ;
V_96 = F_52 ( F_53 () , F_36 () , F_2 , F_1 ) ;
}
void
F_54 ( void )
{
T_17 V_143 ;
V_143 = F_55 ( F_24 , V_82 ) ;
F_56 ( L_68 , V_144 , V_143 ) ;
}
