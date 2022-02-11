static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 & V_2 )
return V_3 ;
else if ( V_1 & V_4 )
return V_5 ;
else
return V_6 ;
}
static T_1 F_2 ( T_1 V_7 )
{
switch ( V_7 ) {
case 2 :
return V_8 ;
case 4 :
return V_9 ;
case 8 :
default:
return V_10 ;
case 16 :
return V_11 ;
}
}
static void F_3 ( struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
V_13 -> V_15 [ V_14 ] = NULL ;
V_13 -> V_16 [ V_14 ] = NULL ;
V_13 -> V_17 [ V_14 ] = 0 ;
V_13 -> V_18 [ V_14 ] = 0 ;
}
for ( V_14 = 0 ; V_14 < 12 ; V_14 ++ ) {
V_13 -> V_19 [ V_14 ] = NULL ;
V_13 -> V_20 [ V_14 ] = 0xFFFFFFFF ;
V_13 -> V_21 [ V_14 ] = 0 ;
V_13 -> V_22 [ V_14 ] = 0xFFFFFFFF ;
V_13 -> V_23 [ V_14 ] = 0 ;
V_13 -> V_24 [ V_14 ] = 0 ;
}
V_13 -> V_25 = 0xFFFFFFFF ;
V_13 -> V_26 = 0xFFFFFFFF ;
V_13 -> V_27 = true ;
V_13 -> V_28 = 0xFFFFC000 ;
V_13 -> V_29 = 0xFFFFFFFF ;
V_13 -> V_30 = 0xFFFFFFFF ;
V_13 -> V_31 = 0xFFFFFFFF ;
V_13 -> V_32 = 0xFFFFFFFF ;
V_13 -> V_33 = 0xFFFFFFFF ;
V_13 -> V_34 = NULL ;
V_13 -> V_35 = NULL ;
V_13 -> V_36 = 0xFFFFFFFF ;
V_13 -> V_37 = 0xFFFFFFFF ;
V_13 -> V_38 = 0xFFFFFFFF ;
V_13 -> V_39 = NULL ;
V_13 -> V_40 = NULL ;
V_13 -> V_41 = true ;
V_13 -> V_42 = NULL ;
V_13 -> V_43 = 0xFFFFFFFF ;
V_13 -> V_44 = 0 ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
V_13 -> V_45 [ V_14 ] = 0 ;
V_13 -> V_46 [ V_14 ] = NULL ;
V_13 -> V_47 [ V_14 ] = 0xFFFFFFFF ;
}
V_13 -> V_48 = true ;
V_13 -> V_49 = false ;
}
static int F_4 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 )
{
V_53 -> V_55 = V_53 -> V_56 * V_53 -> V_57 * V_53 -> V_58 * V_53 -> V_59 ;
V_53 -> V_60 = V_53 -> V_58 ;
V_53 -> V_61 = 1 ;
V_53 -> V_62 = 1 ;
return 0 ;
}
static int F_5 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
unsigned V_61 ;
V_61 = F_6 ( 64 , V_13 -> V_63 / V_53 -> V_58 ) ;
V_53 -> V_55 = V_53 -> V_56 * V_53 -> V_57 * V_53 -> V_58 * V_53 -> V_59 ;
V_53 -> V_60 = V_13 -> V_63 ;
V_53 -> V_61 = V_61 ;
V_53 -> V_62 = 1 ;
if ( V_53 -> V_56 & ( V_61 - 1 ) ) {
if ( V_54 ) {
F_7 ( V_51 -> V_64 , L_1 ,
V_65 , __LINE__ , V_54 , V_53 -> V_56 , V_61 ) ;
}
return - V_66 ;
}
return 0 ;
}
static int F_8 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
unsigned V_61 ;
V_61 = V_13 -> V_63 / ( 8 * V_53 -> V_58 * V_53 -> V_59 ) ;
V_61 = F_6 ( 8 , V_61 ) ;
V_53 -> V_55 = V_53 -> V_56 * V_53 -> V_57 * V_53 -> V_58 ;
V_53 -> V_60 = V_13 -> V_63 ;
V_53 -> V_61 = V_61 ;
V_53 -> V_62 = 8 ;
if ( ( V_53 -> V_56 & ( V_61 - 1 ) ) ) {
if ( V_54 ) {
F_7 ( V_51 -> V_64 , L_2 ,
V_65 , __LINE__ , V_54 , V_53 -> V_56 , V_61 ,
V_13 -> V_63 , V_53 -> V_58 , V_53 -> V_59 ) ;
}
return - V_66 ;
}
if ( ( V_53 -> V_57 & ( 8 - 1 ) ) ) {
if ( V_54 ) {
F_7 ( V_51 -> V_64 , L_3 ,
V_65 , __LINE__ , V_54 , V_53 -> V_57 ) ;
}
return - V_66 ;
}
return 0 ;
}
static int F_9 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
unsigned V_61 , V_62 , V_67 , V_68 ;
V_67 = 64 * V_53 -> V_58 * V_53 -> V_59 ;
V_61 = V_13 -> V_63 / ( 8 * V_53 -> V_58 * V_53 -> V_59 ) ;
V_61 = F_6 ( 8 , V_61 ) ;
V_68 = 1 ;
if ( V_67 > V_53 -> V_69 ) {
V_68 = V_67 / V_53 -> V_69 ;
}
V_67 = V_67 / V_68 ;
V_61 = ( 8 * V_53 -> V_70 * V_13 -> V_71 ) * V_53 -> V_72 ;
V_62 = ( 8 * V_53 -> V_73 * V_53 -> V_7 ) / V_53 -> V_72 ;
V_53 -> V_55 = V_53 -> V_56 * V_53 -> V_57 * V_53 -> V_58 * V_68 ;
V_53 -> V_60 = ( V_61 / 8 ) * ( V_62 / 8 ) * V_67 ;
V_53 -> V_61 = V_61 ;
V_53 -> V_62 = V_62 ;
if ( ( V_53 -> V_56 & ( V_61 - 1 ) ) ) {
if ( V_54 ) {
F_7 ( V_51 -> V_64 , L_1 ,
V_65 , __LINE__ , V_54 , V_53 -> V_56 , V_61 ) ;
}
return - V_66 ;
}
if ( ( V_53 -> V_57 & ( V_62 - 1 ) ) ) {
if ( V_54 ) {
F_7 ( V_51 -> V_64 , L_4 ,
V_65 , __LINE__ , V_54 , V_53 -> V_57 , V_62 ) ;
}
return - V_66 ;
}
return 0 ;
}
static int F_10 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 )
{
V_53 -> V_58 = F_11 ( V_53 -> V_74 ) ;
switch ( V_53 -> V_75 ) {
case V_6 :
return F_4 ( V_51 , V_53 , V_54 ) ;
case V_76 :
return F_5 ( V_51 , V_53 , V_54 ) ;
case V_5 :
return F_8 ( V_51 , V_53 , V_54 ) ;
case V_3 :
return F_9 ( V_51 , V_53 , V_54 ) ;
default:
F_7 ( V_51 -> V_64 , L_5 ,
V_65 , __LINE__ , V_54 , V_53 -> V_75 ) ;
return - V_66 ;
}
return - V_66 ;
}
static int F_12 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
const char * V_54 )
{
switch ( V_53 -> V_75 ) {
case V_3 :
break;
case V_6 :
case V_76 :
case V_5 :
return 0 ;
default:
F_7 ( V_51 -> V_64 , L_5 ,
V_65 , __LINE__ , V_54 , V_53 -> V_75 ) ;
return - V_66 ;
}
switch ( V_53 -> V_7 ) {
case 0 : V_53 -> V_7 = 2 ; break;
case 1 : V_53 -> V_7 = 4 ; break;
case 2 : V_53 -> V_7 = 8 ; break;
case 3 : V_53 -> V_7 = 16 ; break;
default:
F_7 ( V_51 -> V_64 , L_6 ,
V_65 , __LINE__ , V_54 , V_53 -> V_7 ) ;
return - V_66 ;
}
switch ( V_53 -> V_70 ) {
case 0 : V_53 -> V_70 = 1 ; break;
case 1 : V_53 -> V_70 = 2 ; break;
case 2 : V_53 -> V_70 = 4 ; break;
case 3 : V_53 -> V_70 = 8 ; break;
default:
F_7 ( V_51 -> V_64 , L_7 ,
V_65 , __LINE__ , V_54 , V_53 -> V_70 ) ;
return - V_66 ;
}
switch ( V_53 -> V_73 ) {
case 0 : V_53 -> V_73 = 1 ; break;
case 1 : V_53 -> V_73 = 2 ; break;
case 2 : V_53 -> V_73 = 4 ; break;
case 3 : V_53 -> V_73 = 8 ; break;
default:
F_7 ( V_51 -> V_64 , L_8 ,
V_65 , __LINE__ , V_54 , V_53 -> V_73 ) ;
return - V_66 ;
}
switch ( V_53 -> V_72 ) {
case 0 : V_53 -> V_72 = 1 ; break;
case 1 : V_53 -> V_72 = 2 ; break;
case 2 : V_53 -> V_72 = 4 ; break;
case 3 : V_53 -> V_72 = 8 ; break;
default:
F_7 ( V_51 -> V_64 , L_9 ,
V_65 , __LINE__ , V_54 , V_53 -> V_72 ) ;
return - V_66 ;
}
switch ( V_53 -> V_69 ) {
case 0 : V_53 -> V_69 = 64 ; break;
case 1 : V_53 -> V_69 = 128 ; break;
case 2 : V_53 -> V_69 = 256 ; break;
case 3 : V_53 -> V_69 = 512 ; break;
case 4 : V_53 -> V_69 = 1024 ; break;
case 5 : V_53 -> V_69 = 2048 ; break;
case 6 : V_53 -> V_69 = 4096 ; break;
default:
F_7 ( V_51 -> V_64 , L_10 ,
V_65 , __LINE__ , V_54 , V_53 -> V_69 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_13 ( struct V_50 * V_51 , unsigned V_77 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
struct V_52 V_53 ;
unsigned V_78 , V_79 , V_80 ;
unsigned long V_81 ;
int V_82 ;
V_80 = F_14 ( V_13 -> V_22 [ V_77 ] ) + 1 ;
V_78 = V_13 -> V_23 [ V_77 ] ;
V_79 = V_13 -> V_24 [ V_77 ] ;
V_53 . V_56 = ( V_78 + 1 ) * 8 ;
V_53 . V_57 = ( ( V_79 + 1 ) * 64 ) / V_53 . V_56 ;
V_53 . V_75 = F_15 ( V_13 -> V_21 [ V_77 ] ) ;
V_53 . V_74 = F_16 ( V_13 -> V_21 [ V_77 ] ) ;
V_53 . V_69 = F_17 ( V_13 -> V_83 [ V_77 ] ) ;
V_53 . V_7 = F_18 ( V_13 -> V_83 [ V_77 ] ) ;
V_53 . V_70 = F_19 ( V_13 -> V_83 [ V_77 ] ) ;
V_53 . V_73 = F_20 ( V_13 -> V_83 [ V_77 ] ) ;
V_53 . V_72 = F_21 ( V_13 -> V_83 [ V_77 ] ) ;
V_53 . V_59 = 1 ;
if ( ! F_22 ( V_53 . V_74 ) ) {
F_7 ( V_51 -> V_64 , L_11 ,
V_65 , __LINE__ , V_53 . V_74 ,
V_77 , V_13 -> V_21 [ V_77 ] ) ;
return - V_66 ;
}
V_82 = F_12 ( V_51 , & V_53 , L_12 ) ;
if ( V_82 ) {
return V_82 ;
}
V_82 = F_10 ( V_51 , & V_53 , L_12 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_13 ,
V_65 , __LINE__ , V_77 , V_13 -> V_23 [ V_77 ] ,
V_13 -> V_24 [ V_77 ] , V_13 -> V_83 [ V_77 ] ,
V_13 -> V_21 [ V_77 ] ) ;
return V_82 ;
}
V_81 = V_13 -> V_20 [ V_77 ] << 8 ;
if ( V_81 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_14 ,
V_65 , __LINE__ , V_77 , V_81 , V_53 . V_60 ) ;
return - V_66 ;
}
V_81 += V_53 . V_55 * V_80 ;
if ( V_81 > F_23 ( V_13 -> V_19 [ V_77 ] ) ) {
F_7 ( V_51 -> V_64 , L_15
L_16 ,
V_65 , __LINE__ , V_77 , V_53 . V_55 ,
V_13 -> V_20 [ V_77 ] << 8 , V_80 ,
F_23 ( V_13 -> V_19 [ V_77 ] ) , V_79 ) ;
F_7 ( V_51 -> V_64 , L_17 ,
V_65 , __LINE__ , V_53 . V_56 , V_53 . V_57 ,
V_53 . V_75 , V_53 . V_58 , V_53 . V_59 ,
V_53 . V_70 , V_53 . V_73 ,
V_53 . V_69 , V_53 . V_72 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_24 ( struct V_50 * V_51 ,
unsigned V_56 , unsigned V_57 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
unsigned long V_84 ;
if ( V_13 -> V_42 == NULL ) {
F_7 ( V_51 -> V_64 , L_18 ,
V_65 , __LINE__ , V_13 -> V_31 ) ;
return - V_66 ;
}
if ( F_25 ( V_13 -> V_44 ) ) {
V_56 = F_26 ( V_56 , 16 * 8 ) ;
V_57 = F_26 ( V_57 , V_13 -> V_71 * 8 ) ;
} else {
switch ( V_13 -> V_71 ) {
case 8 :
V_56 = F_26 ( V_56 , 64 * 8 ) ;
V_57 = F_26 ( V_57 , 64 * 8 ) ;
break;
case 4 :
V_56 = F_26 ( V_56 , 64 * 8 ) ;
V_57 = F_26 ( V_57 , 32 * 8 ) ;
break;
case 2 :
V_56 = F_26 ( V_56 , 32 * 8 ) ;
V_57 = F_26 ( V_57 , 32 * 8 ) ;
break;
case 1 :
V_56 = F_26 ( V_56 , 32 * 8 ) ;
V_57 = F_26 ( V_57 , 16 * 8 ) ;
break;
default:
F_7 ( V_51 -> V_64 , L_19 ,
V_65 , __LINE__ , V_13 -> V_71 ) ;
return - V_66 ;
}
}
V_56 = V_56 / 8 ;
V_57 = V_57 / 8 ;
V_84 = V_56 * V_57 * 4 ;
V_84 += V_13 -> V_43 ;
if ( V_84 > F_23 ( V_13 -> V_42 ) ) {
F_7 ( V_51 -> V_64 , L_20 ,
V_65 , __LINE__ , F_23 ( V_13 -> V_42 ) ,
V_84 , V_56 , V_57 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_27 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
struct V_52 V_53 ;
unsigned V_78 , V_79 , V_80 ;
unsigned long V_81 ;
int V_82 ;
V_80 = F_28 ( V_13 -> V_28 ) + 1 ;
V_78 = F_29 ( V_13 -> V_29 ) ;
V_79 = V_13 -> V_85 ;
V_53 . V_56 = ( V_78 + 1 ) * 8 ;
V_53 . V_57 = ( ( V_79 + 1 ) * 64 ) / V_53 . V_56 ;
V_53 . V_75 = F_30 ( V_13 -> V_31 ) ;
V_53 . V_74 = F_31 ( V_13 -> V_36 ) ;
V_53 . V_69 = F_32 ( V_13 -> V_36 ) ;
V_53 . V_7 = F_33 ( V_13 -> V_31 ) ;
V_53 . V_70 = F_34 ( V_13 -> V_31 ) ;
V_53 . V_73 = F_35 ( V_13 -> V_31 ) ;
V_53 . V_72 = F_36 ( V_13 -> V_31 ) ;
V_53 . V_59 = 1 ;
if ( V_53 . V_74 != 1 ) {
F_7 ( V_51 -> V_64 , L_21 ,
V_65 , __LINE__ , V_53 . V_74 ) ;
return - V_66 ;
}
V_53 . V_74 = V_86 ;
V_82 = F_12 ( V_51 , & V_53 , L_22 ) ;
if ( V_82 ) {
return V_82 ;
}
V_82 = F_10 ( V_51 , & V_53 , NULL ) ;
if ( V_82 ) {
V_53 . V_74 = V_87 ;
V_82 = F_10 ( V_51 , & V_53 , L_22 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_23 ,
V_65 , __LINE__ , V_13 -> V_29 ,
V_13 -> V_85 , V_13 -> V_36 , V_13 -> V_31 ) ;
}
return V_82 ;
}
V_81 = V_13 -> V_37 << 8 ;
if ( V_81 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_24 ,
V_65 , __LINE__ , V_81 , V_53 . V_60 ) ;
return - V_66 ;
}
V_81 += V_53 . V_55 * V_80 ;
if ( V_81 > F_23 ( V_13 -> V_39 ) ) {
F_7 ( V_51 -> V_64 , L_25
L_26 ,
V_65 , __LINE__ , V_53 . V_55 ,
( unsigned long ) V_13 -> V_37 << 8 , V_80 ,
F_23 ( V_13 -> V_39 ) ) ;
F_7 ( V_51 -> V_64 , L_23 ,
V_65 , __LINE__ , V_13 -> V_29 ,
V_13 -> V_85 , V_13 -> V_36 , V_13 -> V_31 ) ;
return - V_66 ;
}
V_81 = V_13 -> V_38 << 8 ;
if ( V_81 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_27 ,
V_65 , __LINE__ , V_81 , V_53 . V_60 ) ;
return - V_66 ;
}
V_81 += V_53 . V_55 * V_80 ;
if ( V_81 > F_23 ( V_13 -> V_40 ) ) {
F_7 ( V_51 -> V_64 , L_28
L_26 ,
V_65 , __LINE__ , V_53 . V_55 ,
( unsigned long ) V_13 -> V_38 << 8 , V_80 ,
F_23 ( V_13 -> V_40 ) ) ;
return - V_66 ;
}
if ( F_37 ( V_13 -> V_31 ) ) {
V_82 = F_24 ( V_51 , V_53 . V_56 , V_53 . V_57 ) ;
if ( V_82 ) {
return V_82 ;
}
}
return 0 ;
}
static int F_38 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
struct V_52 V_53 ;
unsigned V_78 , V_79 , V_80 ;
unsigned long V_81 ;
int V_82 ;
V_80 = F_28 ( V_13 -> V_28 ) + 1 ;
V_78 = F_29 ( V_13 -> V_29 ) ;
V_79 = V_13 -> V_85 ;
V_53 . V_56 = ( V_78 + 1 ) * 8 ;
V_53 . V_57 = ( ( V_79 + 1 ) * 64 ) / V_53 . V_56 ;
V_53 . V_75 = F_30 ( V_13 -> V_31 ) ;
V_53 . V_74 = F_39 ( V_13 -> V_31 ) ;
V_53 . V_69 = F_40 ( V_13 -> V_31 ) ;
V_53 . V_7 = F_33 ( V_13 -> V_31 ) ;
V_53 . V_70 = F_34 ( V_13 -> V_31 ) ;
V_53 . V_73 = F_35 ( V_13 -> V_31 ) ;
V_53 . V_72 = F_36 ( V_13 -> V_31 ) ;
V_53 . V_59 = 1 ;
switch ( V_53 . V_74 ) {
case V_88 :
V_53 . V_74 = V_89 ;
break;
case V_90 :
case V_91 :
V_53 . V_74 = V_87 ;
break;
default:
F_7 ( V_51 -> V_64 , L_29 ,
V_65 , __LINE__ , V_53 . V_74 ) ;
return - V_66 ;
}
V_82 = F_12 ( V_51 , & V_53 , L_30 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_31 ,
V_65 , __LINE__ , V_13 -> V_29 ,
V_13 -> V_85 , V_13 -> V_31 ) ;
return V_82 ;
}
V_82 = F_10 ( V_51 , & V_53 , L_30 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_31 ,
V_65 , __LINE__ , V_13 -> V_29 ,
V_13 -> V_85 , V_13 -> V_31 ) ;
return V_82 ;
}
V_81 = V_13 -> V_32 << 8 ;
if ( V_81 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_24 ,
V_65 , __LINE__ , V_81 , V_53 . V_60 ) ;
return - V_66 ;
}
V_81 += V_53 . V_55 * V_80 ;
if ( V_81 > F_23 ( V_13 -> V_34 ) ) {
F_7 ( V_51 -> V_64 , L_32
L_26 ,
V_65 , __LINE__ , V_53 . V_55 ,
( unsigned long ) V_13 -> V_32 << 8 , V_80 ,
F_23 ( V_13 -> V_34 ) ) ;
return - V_66 ;
}
V_81 = V_13 -> V_33 << 8 ;
if ( V_81 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_27 ,
V_65 , __LINE__ , V_81 , V_53 . V_60 ) ;
return - V_66 ;
}
V_81 += V_53 . V_55 * V_80 ;
if ( V_81 > F_23 ( V_13 -> V_35 ) ) {
F_7 ( V_51 -> V_64 , L_33
L_26 ,
V_65 , __LINE__ , V_53 . V_55 ,
( unsigned long ) V_13 -> V_33 << 8 , V_80 ,
F_23 ( V_13 -> V_35 ) ) ;
return - V_66 ;
}
if ( F_37 ( V_13 -> V_31 ) ) {
V_82 = F_24 ( V_51 , V_53 . V_56 , V_53 . V_57 ) ;
if ( V_82 ) {
return V_82 ;
}
}
return 0 ;
}
static int F_41 ( struct V_50 * V_51 ,
struct V_92 * V_93 ,
struct V_92 * V_94 ,
unsigned V_95 )
{
struct V_52 V_53 ;
unsigned long V_96 , V_97 ;
unsigned V_98 , V_99 , V_80 , V_100 , V_101 , V_102 , V_14 ;
T_1 V_103 [ 8 ] ;
int V_82 ;
V_103 [ 0 ] = F_42 ( V_51 , V_95 + 0 ) ;
V_103 [ 1 ] = F_42 ( V_51 , V_95 + 1 ) ;
V_103 [ 2 ] = F_42 ( V_51 , V_95 + 2 ) ;
V_103 [ 3 ] = F_42 ( V_51 , V_95 + 3 ) ;
V_103 [ 4 ] = F_42 ( V_51 , V_95 + 4 ) ;
V_103 [ 5 ] = F_42 ( V_51 , V_95 + 5 ) ;
V_103 [ 6 ] = F_42 ( V_51 , V_95 + 6 ) ;
V_103 [ 7 ] = F_42 ( V_51 , V_95 + 7 ) ;
V_98 = F_43 ( V_103 [ 0 ] ) ;
V_99 = F_44 ( V_103 [ 5 ] ) ;
V_80 = F_45 ( V_103 [ 5 ] ) + 1 ;
V_100 = F_46 ( V_103 [ 0 ] ) + 1 ;
V_101 = F_47 ( V_103 [ 1 ] ) + 1 ;
V_102 = F_48 ( V_103 [ 1 ] ) + 1 ;
V_53 . V_74 = F_49 ( V_103 [ 7 ] ) ;
V_53 . V_56 = ( F_50 ( V_103 [ 0 ] ) + 1 ) * 8 ;
V_53 . V_56 = F_51 ( V_53 . V_74 , V_53 . V_56 ) ;
V_53 . V_57 = F_52 ( V_53 . V_74 , V_101 ) ;
V_53 . V_75 = F_53 ( V_103 [ 1 ] ) ;
V_53 . V_69 = F_54 ( V_103 [ 6 ] ) ;
V_53 . V_7 = F_55 ( V_103 [ 7 ] ) ;
V_53 . V_70 = F_56 ( V_103 [ 7 ] ) ;
V_53 . V_73 = F_57 ( V_103 [ 7 ] ) ;
V_53 . V_72 = F_58 ( V_103 [ 7 ] ) ;
V_53 . V_59 = 1 ;
V_96 = V_103 [ 2 ] << 8 ;
V_97 = V_103 [ 3 ] << 8 ;
if ( ! F_59 ( V_53 . V_74 , V_51 -> V_104 ) ) {
F_7 ( V_51 -> V_64 , L_34 ,
V_65 , __LINE__ , V_53 . V_74 ) ;
return - V_66 ;
}
switch ( V_98 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
V_102 = 1 ;
case V_110 :
break;
default:
F_7 ( V_51 -> V_64 , L_35 ,
V_65 , __LINE__ , V_98 ) ;
return - V_66 ;
}
V_82 = F_12 ( V_51 , & V_53 , L_36 ) ;
if ( V_82 ) {
return V_82 ;
}
F_10 ( V_51 , & V_53 , NULL ) ;
V_53 . V_57 = F_60 ( V_53 . V_57 , V_53 . V_62 ) ;
V_82 = F_10 ( V_51 , & V_53 , L_36 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_37 ,
V_65 , __LINE__ , V_103 [ 0 ] , V_103 [ 1 ] , V_103 [ 4 ] ,
V_103 [ 5 ] , V_103 [ 6 ] , V_103 [ 7 ] ) ;
return V_82 ;
}
if ( V_96 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_38 ,
V_65 , __LINE__ , V_96 , V_53 . V_60 ) ;
return - V_66 ;
}
if ( V_97 & ( V_53 . V_60 - 1 ) ) {
F_7 ( V_51 -> V_64 , L_39 ,
V_65 , __LINE__ , V_97 , V_53 . V_60 ) ;
return - V_66 ;
}
if ( V_98 == V_111 ) {
V_96 += V_53 . V_55 * V_102 ;
} else {
V_96 += V_53 . V_55 * V_80 ;
}
if ( V_96 > F_23 ( V_93 ) ) {
F_7 ( V_51 -> V_64 , L_40
L_41 ,
V_65 , __LINE__ , V_53 . V_55 ,
( unsigned long ) V_103 [ 2 ] << 8 , V_80 ,
V_102 , F_23 ( V_93 ) ,
V_53 . V_56 , V_53 . V_57 ) ;
return - V_66 ;
}
for ( V_14 = 1 ; V_14 <= V_99 ; V_14 ++ ) {
unsigned V_112 , V_113 , V_114 ;
V_112 = F_61 ( V_100 , V_14 ) ;
V_113 = F_61 ( V_101 , V_14 ) ;
V_114 = F_61 ( V_102 , V_14 ) ;
V_53 . V_56 = F_51 ( V_53 . V_74 , V_112 ) ;
V_53 . V_57 = F_52 ( V_53 . V_74 , V_113 ) ;
switch ( V_53 . V_75 ) {
case V_3 :
if ( V_53 . V_56 < V_53 . V_61 || V_53 . V_57 < V_53 . V_62 ) {
V_53 . V_75 = V_5 ;
}
F_10 ( V_51 , & V_53 , NULL ) ;
break;
case V_6 :
case V_76 :
case V_5 :
break;
default:
F_7 ( V_51 -> V_64 , L_42 ,
V_65 , __LINE__ , V_53 . V_75 ) ;
return - V_66 ;
}
V_53 . V_56 = F_60 ( V_53 . V_56 , V_53 . V_61 ) ;
V_53 . V_57 = F_60 ( V_53 . V_57 , V_53 . V_62 ) ;
V_82 = F_10 ( V_51 , & V_53 , L_43 ) ;
if ( V_82 ) {
return V_82 ;
}
if ( V_98 == V_111 ) {
V_97 += V_53 . V_55 * V_114 ;
} else {
V_97 += V_53 . V_55 * V_80 ;
}
if ( V_97 > F_23 ( V_94 ) ) {
F_7 ( V_51 -> V_64 , L_44
L_45
L_46 ,
V_65 , __LINE__ , V_14 , V_53 . V_55 ,
( unsigned long ) V_103 [ 3 ] << 8 , V_97 , V_80 ,
V_114 , F_23 ( V_94 ) ,
V_100 , V_101 , V_102 ) ;
F_7 ( V_51 -> V_64 , L_17 ,
V_65 , __LINE__ , V_53 . V_56 , V_53 . V_57 ,
V_53 . V_75 , V_53 . V_58 , V_53 . V_59 ,
V_53 . V_70 , V_53 . V_73 ,
V_53 . V_69 , V_53 . V_72 ) ;
return - V_66 ;
}
}
return 0 ;
}
static int F_62 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = V_51 -> V_13 ;
unsigned V_115 , V_14 ;
int V_82 ;
unsigned V_116 = 0 ;
if ( V_13 -> V_48 && V_13 -> V_117 ) {
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
if ( V_13 -> V_117 & ( 1 << V_14 ) ) {
V_116 |= ( V_13 -> V_118 >> ( V_14 * 4 ) ) & 0xf ;
}
}
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
if ( V_116 & ( 1 << V_14 ) ) {
if ( V_13 -> V_46 [ V_14 ] ) {
T_2 V_81 = ( T_2 ) V_13 -> V_47 [ V_14 ] +
( T_2 ) V_13 -> V_45 [ V_14 ] ;
if ( V_81 > F_23 ( V_13 -> V_46 [ V_14 ] ) ) {
F_63 ( L_47 ,
V_14 , V_81 ,
F_23 ( V_13 -> V_46 [ V_14 ] ) ) ;
return - V_66 ;
}
} else {
F_7 ( V_51 -> V_64 , L_48 , V_14 ) ;
return - V_66 ;
}
}
}
V_13 -> V_48 = false ;
}
if ( V_13 -> V_49 )
return 0 ;
if ( V_13 -> V_27 ) {
V_115 = V_13 -> V_25 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
if ( ( V_115 >> ( V_14 * 4 ) ) & 0xF ) {
if ( V_13 -> V_19 [ V_14 ] == NULL ) {
F_7 ( V_51 -> V_64 , L_49 ,
V_65 , __LINE__ , V_13 -> V_25 , V_13 -> V_26 , V_14 ) ;
return - V_66 ;
}
V_82 = F_13 ( V_51 , V_14 ) ;
if ( V_82 ) {
return V_82 ;
}
}
}
V_13 -> V_27 = false ;
}
if ( V_13 -> V_41 ) {
if ( F_64 ( V_13 -> V_30 ) ) {
V_82 = F_27 ( V_51 ) ;
if ( V_82 )
return V_82 ;
}
if ( F_65 ( V_13 -> V_30 ) ) {
V_82 = F_38 ( V_51 ) ;
if ( V_82 )
return V_82 ;
}
V_13 -> V_41 = false ;
}
return 0 ;
}
int F_66 ( struct V_50 * V_51 ,
struct V_119 * V_120 ,
unsigned V_95 )
{
struct V_121 * V_122 = & V_51 -> V_123 [ V_51 -> V_124 ] ;
T_3 V_125 ;
if ( V_95 >= V_122 -> V_126 ) {
F_63 ( L_50 ,
V_95 , V_122 -> V_126 ) ;
return - V_66 ;
}
V_125 = F_42 ( V_51 , V_95 ) ;
V_120 -> V_95 = V_95 ;
V_120 -> type = F_67 ( V_125 ) ;
V_120 -> V_127 = F_68 ( V_125 ) ;
V_120 -> V_128 = 0 ;
switch ( V_120 -> type ) {
case V_129 :
V_120 -> V_130 = F_69 ( V_125 ) ;
break;
case V_131 :
V_120 -> V_132 = F_70 ( V_125 ) ;
break;
case V_133 :
V_120 -> V_127 = - 1 ;
break;
default:
F_63 ( L_51 , V_120 -> type , V_95 ) ;
return - V_66 ;
}
if ( ( V_120 -> V_127 + 1 + V_120 -> V_95 ) >= V_122 -> V_126 ) {
F_63 ( L_52 ,
V_120 -> V_95 , V_120 -> type , V_120 -> V_127 , V_122 -> V_126 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_71 ( struct V_50 * V_51 ,
struct V_134 * * V_135 )
{
struct V_121 * V_136 ;
struct V_119 V_137 ;
unsigned V_95 ;
int V_82 ;
if ( V_51 -> V_138 == - 1 ) {
F_63 ( L_53 ) ;
return - V_66 ;
}
* V_135 = NULL ;
V_136 = & V_51 -> V_123 [ V_51 -> V_138 ] ;
V_82 = F_66 ( V_51 , & V_137 , V_51 -> V_95 ) ;
if ( V_82 ) {
return V_82 ;
}
V_51 -> V_95 += V_137 . V_127 + 2 ;
if ( V_137 . type != V_131 || V_137 . V_132 != V_139 ) {
F_63 ( L_54 ,
V_137 . V_95 ) ;
return - V_66 ;
}
V_95 = F_42 ( V_51 , V_137 . V_95 + 1 ) ;
if ( V_95 >= V_136 -> V_126 ) {
F_63 ( L_55 ,
V_95 , V_136 -> V_126 ) ;
return - V_66 ;
}
* V_135 = V_51 -> V_140 [ ( V_95 / 4 ) ] ;
return 0 ;
}
static int F_72 ( struct V_50 * V_51 )
{
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_145 * V_145 ;
struct V_119 V_137 , V_146 ;
int V_147 ;
int V_82 ;
T_3 V_125 , V_148 , V_130 , V_149 ;
volatile T_3 * V_150 ;
V_150 = V_51 -> V_150 -> V_151 ;
V_82 = F_66 ( V_51 , & V_146 , V_51 -> V_95 ) ;
if ( V_82 )
return V_82 ;
if ( V_146 . type != V_131 ||
V_146 . V_132 != V_152 ) {
F_63 ( L_56 ) ;
return - V_66 ;
}
V_149 = F_42 ( V_51 , V_146 . V_95 + 1 ) ;
if ( V_149 & 0x10 ) {
F_63 ( L_57 ) ;
return - V_66 ;
}
if ( ( V_149 & 0x7 ) != 0x3 ) {
F_63 ( L_58 ) ;
return - V_66 ;
}
if ( ( F_42 ( V_51 , V_146 . V_95 + 2 ) << 2 ) != V_153 ) {
F_63 ( L_59 ) ;
return - V_66 ;
}
if ( F_42 ( V_51 , V_146 . V_95 + 5 ) != V_154 ) {
F_63 ( L_60 ) ;
return - V_66 ;
}
V_82 = F_66 ( V_51 , & V_137 , V_51 -> V_95 + V_146 . V_127 + 2 ) ;
if ( V_82 )
return V_82 ;
V_148 = V_51 -> V_95 - 2 ;
V_51 -> V_95 += V_146 . V_127 + 2 ;
V_51 -> V_95 += V_137 . V_127 + 2 ;
V_125 = F_42 ( V_51 , V_148 ) ;
V_147 = F_42 ( V_51 , V_148 + 2 + 7 + 1 ) ;
V_130 = F_69 ( V_125 ) ;
V_142 = F_73 ( V_51 -> V_155 -> V_156 , V_147 , V_157 ) ;
if ( ! V_142 ) {
F_63 ( L_61 , V_147 ) ;
return - V_66 ;
}
V_144 = F_74 ( V_142 ) ;
V_145 = F_75 ( V_144 ) ;
V_147 = V_145 -> V_147 ;
if ( ! V_144 -> V_158 ) {
V_150 [ V_148 + 2 ] = F_76 ( 0 ) ;
V_150 [ V_148 + 3 ] = F_76 ( 0 ) ;
V_150 [ V_148 + 4 ] = F_76 ( 0 ) ;
V_150 [ V_148 + 5 ] = F_76 ( 0 ) ;
V_150 [ V_148 + 6 ] = F_76 ( 0 ) ;
V_150 [ V_148 + 7 ] = F_76 ( 0 ) ;
V_150 [ V_148 + 8 ] = F_76 ( 0 ) ;
} else {
switch ( V_130 ) {
case V_159 :
V_125 &= ~ V_160 ;
V_125 |= ( V_159 + V_145 -> V_161 ) >> 2 ;
V_150 [ V_148 ] = V_125 ;
V_150 [ V_148 + 4 ] = ( V_153 + V_145 -> V_161 ) >> 2 ;
break;
default:
F_63 ( L_62 ) ;
return - V_66 ;
}
}
return 0 ;
}
static int F_77 ( struct V_50 * V_51 ,
struct V_119 * V_120 ,
unsigned V_95 , unsigned V_130 )
{
int V_82 ;
switch ( V_130 ) {
case V_159 :
V_82 = F_72 ( V_51 ) ;
if ( V_82 ) {
F_63 ( L_63 ,
V_95 , V_130 ) ;
return V_82 ;
}
break;
default:
F_78 ( V_162 L_64 ,
V_130 , V_95 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_79 ( struct V_50 * V_51 ,
struct V_119 * V_120 )
{
unsigned V_130 , V_14 ;
unsigned V_95 ;
int V_82 ;
V_95 = V_120 -> V_95 + 1 ;
V_130 = V_120 -> V_130 ;
for ( V_14 = 0 ; V_14 <= V_120 -> V_127 ; V_14 ++ , V_95 ++ , V_130 += 4 ) {
V_82 = F_77 ( V_51 , V_120 , V_95 , V_130 ) ;
if ( V_82 ) {
return V_82 ;
}
}
return 0 ;
}
static int F_80 ( struct V_50 * V_51 , T_1 V_130 , T_1 V_95 )
{
struct V_12 * V_13 = (struct V_12 * ) V_51 -> V_13 ;
struct V_134 * V_163 ;
T_1 V_164 ;
T_1 V_165 , V_14 , V_115 , * V_150 ;
int V_82 ;
if ( V_51 -> V_155 -> V_104 >= V_166 )
V_164 = F_81 ( V_167 ) ;
else
V_164 = F_81 ( V_168 ) ;
V_14 = ( V_130 >> 7 ) ;
if ( V_14 >= V_164 ) {
F_7 ( V_51 -> V_64 , L_65 , V_130 , V_95 ) ;
return - V_66 ;
}
V_165 = 1 << ( ( V_130 >> 2 ) & 31 ) ;
if ( V_51 -> V_155 -> V_104 >= V_166 ) {
if ( ! ( V_167 [ V_14 ] & V_165 ) )
return 0 ;
} else {
if ( ! ( V_168 [ V_14 ] & V_165 ) )
return 0 ;
}
V_150 = V_51 -> V_150 -> V_151 ;
switch ( V_130 ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
break;
case V_203 :
V_13 -> V_30 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_41 = true ;
break;
case V_204 :
if ( V_51 -> V_155 -> V_104 < V_166 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
break;
case V_205 :
if ( V_51 -> V_155 -> V_104 < V_166 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
break;
case V_206 :
V_13 -> V_31 = F_42 ( V_51 , V_95 ) ;
if ( ! ( V_51 -> V_207 & V_208 ) ) {
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] &= ~ F_82 ( 0xf ) ;
V_13 -> V_31 &= ~ F_82 ( 0xf ) ;
V_150 [ V_95 ] |= F_82 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
V_13 -> V_31 |= F_82 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
if ( V_163 -> V_201 . V_1 & V_2 ) {
unsigned V_70 , V_73 , V_209 , V_210 ;
F_83 ( V_163 -> V_201 . V_1 ,
& V_70 , & V_73 , & V_209 ,
& V_210 ) ;
V_150 [ V_95 ] |= F_84 ( F_2 ( V_13 -> V_7 ) ) ;
V_150 [ V_95 ] |= F_85 ( V_210 ) |
F_86 ( V_70 ) |
F_87 ( V_73 ) |
F_88 ( V_209 ) ;
}
}
V_13 -> V_41 = true ;
break;
case V_211 :
V_13 -> V_36 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_41 = true ;
break;
case V_212 :
V_13 -> V_28 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_41 = true ;
break;
case V_213 :
V_13 -> V_29 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_41 = true ;
break;
case V_214 :
V_13 -> V_85 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_41 = true ;
break;
case V_215 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_13 -> V_32 = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_34 = V_163 -> V_216 ;
V_13 -> V_41 = true ;
break;
case V_217 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_13 -> V_33 = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_35 = V_163 -> V_216 ;
V_13 -> V_41 = true ;
break;
case V_218 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_13 -> V_37 = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_39 = V_163 -> V_216 ;
V_13 -> V_41 = true ;
break;
case V_219 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_13 -> V_38 = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_40 = V_163 -> V_216 ;
V_13 -> V_41 = true ;
break;
case V_220 :
V_13 -> V_117 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_48 = true ;
break;
case V_221 :
V_13 -> V_118 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_48 = true ;
break;
case V_222 :
case V_223 :
case V_224 :
case V_225 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_115 = ( V_130 - V_222 ) / 16 ;
V_13 -> V_47 [ V_115 ] = F_42 ( V_51 , V_95 ) << 8 ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_46 [ V_115 ] = V_163 -> V_216 ;
V_13 -> V_48 = true ;
break;
case V_226 :
case V_227 :
case V_228 :
case V_229 :
V_115 = ( V_130 - V_226 ) / 16 ;
V_13 -> V_45 [ V_115 ] = F_42 ( V_51 , V_95 ) * 4 ;
V_13 -> V_48 = true ;
break;
case V_230 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_68
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
case V_231 :
V_13 -> V_25 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_232 :
V_13 -> V_26 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_233 :
if ( V_51 -> V_155 -> V_104 >= V_166 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_115 = F_42 ( V_51 , V_95 ) & V_234 ;
V_13 -> V_59 = 1 << V_115 ;
break;
case V_235 :
if ( V_51 -> V_155 -> V_104 < V_166 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_115 = F_42 ( V_51 , V_95 ) & V_236 ;
V_13 -> V_59 = 1 << V_115 ;
break;
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
V_115 = ( V_130 - V_237 ) / 0x3c ;
V_13 -> V_22 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
V_115 = ( ( V_130 - V_245 ) / 0x1c ) + 8 ;
V_13 -> V_22 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
V_115 = ( V_130 - V_249 ) / 0x3c ;
V_13 -> V_21 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
if ( ! ( V_51 -> V_207 & V_208 ) ) {
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] |= F_89 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
V_13 -> V_21 [ V_115 ] |= F_89 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
}
V_13 -> V_27 = true ;
break;
case V_257 :
case V_258 :
case V_259 :
case V_260 :
V_115 = ( ( V_130 - V_257 ) / 0x1c ) + 8 ;
V_13 -> V_21 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
if ( ! ( V_51 -> V_207 & V_208 ) ) {
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] |= F_89 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
V_13 -> V_21 [ V_115 ] |= F_89 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
}
V_13 -> V_27 = true ;
break;
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
V_115 = ( V_130 - V_261 ) / 0x3c ;
V_13 -> V_23 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_269 :
case V_270 :
case V_271 :
case V_272 :
V_115 = ( ( V_130 - V_269 ) / 0x1c ) + 8 ;
V_13 -> V_23 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
V_115 = ( V_130 - V_273 ) / 0x3c ;
V_13 -> V_24 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_281 :
case V_282 :
case V_283 :
case V_284 :
V_115 = ( ( V_130 - V_281 ) / 0x1c ) + 8 ;
V_13 -> V_24 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_13 -> V_27 = true ;
break;
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
if ( ! ( V_51 -> V_207 & V_208 ) ) {
if ( V_163 -> V_201 . V_1 & V_2 ) {
unsigned V_70 , V_73 , V_209 , V_210 ;
F_83 ( V_163 -> V_201 . V_1 ,
& V_70 , & V_73 , & V_209 ,
& V_210 ) ;
V_150 [ V_95 ] |= F_90 ( F_2 ( V_13 -> V_7 ) ) ;
V_150 [ V_95 ] |= F_91 ( V_210 ) |
F_92 ( V_70 ) |
F_93 ( V_73 ) |
F_94 ( V_209 ) ;
}
}
V_115 = ( ( V_130 - V_285 ) / 0x3c ) ;
V_13 -> V_83 [ V_115 ] = V_150 [ V_95 ] ;
V_13 -> V_27 = true ;
break;
case V_293 :
case V_294 :
case V_295 :
case V_296 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
if ( ! ( V_51 -> V_207 & V_208 ) ) {
if ( V_163 -> V_201 . V_1 & V_2 ) {
unsigned V_70 , V_73 , V_209 , V_210 ;
F_83 ( V_163 -> V_201 . V_1 ,
& V_70 , & V_73 , & V_209 ,
& V_210 ) ;
V_150 [ V_95 ] |= F_90 ( F_2 ( V_13 -> V_7 ) ) ;
V_150 [ V_95 ] |= F_91 ( V_210 ) |
F_92 ( V_70 ) |
F_93 ( V_73 ) |
F_94 ( V_209 ) ;
}
}
V_115 = ( ( V_130 - V_293 ) / 0x1c ) + 8 ;
V_13 -> V_83 [ V_115 ] = V_150 [ V_95 ] ;
V_13 -> V_27 = true ;
break;
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
V_115 = ( V_130 - V_297 ) / 0x3c ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_95 ( V_51 -> V_64 , L_69 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_15 [ V_115 ] = V_163 -> V_216 ;
break;
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
V_115 = ( V_130 - V_305 ) / 0x3c ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_95 ( V_51 -> V_64 , L_69 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_16 [ V_115 ] = V_163 -> V_216 ;
break;
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
V_115 = ( V_130 - V_313 ) / 0x3c ;
V_13 -> V_18 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
break;
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
V_115 = ( V_130 - V_321 ) / 0x3c ;
V_13 -> V_17 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
break;
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_115 = ( V_130 - V_329 ) / 0x3c ;
V_13 -> V_20 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_115 ] = V_163 -> V_216 ;
V_13 -> V_27 = true ;
break;
case V_337 :
case V_338 :
case V_339 :
case V_340 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_115 = ( ( V_130 - V_337 ) / 0x1c ) + 8 ;
V_13 -> V_20 [ V_115 ] = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_115 ] = V_163 -> V_216 ;
V_13 -> V_27 = true ;
break;
case V_341 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_13 -> V_43 = F_42 ( V_51 , V_95 ) ;
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_13 -> V_42 = V_163 -> V_216 ;
V_13 -> V_41 = true ;
break;
case V_342 :
V_13 -> V_44 = F_42 ( V_51 , V_95 ) ;
V_13 -> V_41 = true ;
break;
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
case V_437 :
case V_438 :
case V_439 :
case V_440 :
case V_441 :
case V_442 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
break;
case V_443 :
if ( V_51 -> V_155 -> V_104 >= V_166 ) {
F_7 ( V_51 -> V_64 , L_70
L_67 , V_130 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_70
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
break;
case V_444 :
if ( V_51 -> V_155 -> V_104 < V_166 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_66
L_67 , V_130 ) ;
return - V_66 ;
}
V_150 [ V_95 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
break;
case V_445 :
V_13 -> V_49 = ( F_42 ( V_51 , V_95 ) & 0x1 ) != 0 ;
break;
default:
F_7 ( V_51 -> V_64 , L_65 , V_130 , V_95 ) ;
return - V_66 ;
}
return 0 ;
}
static bool F_96 ( struct V_50 * V_51 , T_1 V_130 , T_1 V_95 )
{
T_1 V_164 , V_165 , V_14 ;
if ( V_51 -> V_155 -> V_104 >= V_166 )
V_164 = F_81 ( V_167 ) ;
else
V_164 = F_81 ( V_168 ) ;
V_14 = ( V_130 >> 7 ) ;
if ( V_14 >= V_164 ) {
F_7 ( V_51 -> V_64 , L_65 , V_130 , V_95 ) ;
return false ;
}
V_165 = 1 << ( ( V_130 >> 2 ) & 31 ) ;
if ( V_51 -> V_155 -> V_104 >= V_166 ) {
if ( ! ( V_167 [ V_14 ] & V_165 ) )
return true ;
} else {
if ( ! ( V_168 [ V_14 ] & V_165 ) )
return true ;
}
F_7 ( V_51 -> V_64 , L_65 , V_130 , V_95 ) ;
return false ;
}
static int F_97 ( struct V_50 * V_51 ,
struct V_119 * V_120 )
{
struct V_134 * V_163 ;
struct V_12 * V_13 ;
volatile T_1 * V_150 ;
unsigned V_95 ;
unsigned V_14 ;
unsigned V_446 , V_447 , V_130 ;
int V_82 ;
T_1 V_448 ;
V_13 = (struct V_12 * ) V_51 -> V_13 ;
V_150 = V_51 -> V_150 -> V_151 ;
V_95 = V_120 -> V_95 + 1 ;
V_448 = F_42 ( V_51 , V_95 ) ;
switch ( V_120 -> V_132 ) {
case V_449 :
{
int V_450 ;
int V_115 ;
T_4 V_81 ;
if ( V_120 -> V_127 != 1 ) {
F_63 ( L_71 ) ;
return - V_66 ;
}
V_115 = F_42 ( V_51 , V_95 + 1 ) ;
V_450 = ( V_115 >> 16 ) & 0x7 ;
if ( V_450 == 0 )
return 0 ;
if ( V_450 > 2 ) {
F_63 ( L_72 , V_450 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_71 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
( V_448 & 0xfffffff0 ) +
( ( T_2 ) ( V_115 & 0xff ) << 32 ) ;
V_150 [ V_95 + 0 ] = V_81 ;
V_150 [ V_95 + 1 ] = ( V_115 & 0xffffff00 ) | ( F_98 ( V_81 ) & 0xff ) ;
}
break;
case V_451 :
if ( V_120 -> V_127 != 1 ) {
F_63 ( L_73 ) ;
return - V_66 ;
}
break;
case V_452 :
case V_453 :
case V_454 :
if ( V_120 -> V_127 ) {
F_63 ( L_74 ) ;
return - V_66 ;
}
break;
case V_455 :
if ( V_51 -> V_155 -> V_104 < V_166 ) {
F_63 ( L_75 ) ;
return - V_66 ;
}
if ( V_120 -> V_127 ) {
F_63 ( L_74 ) ;
return - V_66 ;
}
break;
case V_456 :
{
T_4 V_81 ;
if ( V_120 -> V_127 != 1 ) {
F_63 ( L_76 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_76 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
V_448 +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 1 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 0 ] = V_81 ;
V_150 [ V_95 + 1 ] = F_98 ( V_81 ) & 0xff ;
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
}
case V_457 :
{
T_4 V_81 ;
if ( V_120 -> V_127 != 3 ) {
F_63 ( L_78 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_78 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
V_448 +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 1 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 0 ] = V_81 ;
V_150 [ V_95 + 1 ] = F_98 ( V_81 ) & 0xff ;
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
}
case V_458 :
{
T_4 V_81 ;
if ( V_120 -> V_127 != 4 ) {
F_63 ( L_79 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_79 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
F_42 ( V_51 , V_95 + 1 ) +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 1 ] = V_81 ;
V_150 [ V_95 + 2 ] = F_98 ( V_81 ) & 0xff ;
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
}
case V_459 :
if ( V_120 -> V_127 != 1 ) {
F_63 ( L_80 ) ;
return - V_66 ;
}
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_81 , V_65 , __LINE__ , V_95 ) ;
return V_82 ;
}
break;
case V_460 :
if ( V_120 -> V_127 != 2 ) {
F_63 ( L_82 ) ;
return - V_66 ;
}
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_81 , V_65 , __LINE__ , V_95 ) ;
return V_82 ;
}
break;
case V_461 :
if ( V_120 -> V_127 < 2 ) {
F_63 ( L_83 ) ;
return - V_66 ;
}
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
case V_462 :
if ( V_120 -> V_127 != 2 ) {
F_63 ( L_84 ) ;
return - V_66 ;
}
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
case V_463 :
if ( V_120 -> V_127 != 3 ) {
F_63 ( L_85 ) ;
return - V_66 ;
}
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
case V_464 :
if ( V_120 -> V_127 != 3 ) {
F_63 ( L_86 ) ;
return - V_66 ;
}
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_81 , V_65 , __LINE__ , V_95 ) ;
return V_82 ;
}
break;
case V_465 :
if ( V_120 -> V_127 != 1 ) {
F_63 ( L_87 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_87 ) ;
return - V_66 ;
}
V_150 [ V_95 + 0 ] = V_448 + ( T_1 ) ( V_163 -> V_201 . V_202 & 0xffffffff ) ;
V_82 = F_62 ( V_51 ) ;
if ( V_82 ) {
F_7 ( V_51 -> V_64 , L_77 , V_65 , __LINE__ ) ;
return V_82 ;
}
break;
case V_152 :
if ( V_120 -> V_127 != 5 ) {
F_63 ( L_88 ) ;
return - V_66 ;
}
if ( V_448 & 0x10 ) {
T_4 V_81 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_88 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
( F_42 ( V_51 , V_95 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 1 ] = ( V_150 [ V_95 + 1 ] & 0x3 ) | ( V_81 & 0xfffffffc ) ;
V_150 [ V_95 + 2 ] = F_98 ( V_81 ) & 0xff ;
}
break;
case V_466 :
if ( V_120 -> V_127 != 3 ) {
F_63 ( L_89 ) ;
return - V_66 ;
}
if ( F_42 ( V_51 , V_95 + 1 ) != 0xffffffff ||
F_42 ( V_51 , V_95 + 2 ) != 0 ) {
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_89 ) ;
return - V_66 ;
}
V_150 [ V_95 + 2 ] += ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
}
break;
case V_467 :
if ( V_120 -> V_127 != 2 && V_120 -> V_127 != 0 ) {
F_63 ( L_90 ) ;
return - V_66 ;
}
if ( V_120 -> V_127 ) {
T_4 V_81 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_90 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
( F_42 ( V_51 , V_95 + 1 ) & 0xfffffff8 ) +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 1 ] = V_81 & 0xfffffff8 ;
V_150 [ V_95 + 2 ] = F_98 ( V_81 ) & 0xff ;
}
break;
case V_468 :
{
T_4 V_81 ;
if ( V_120 -> V_127 != 4 ) {
F_63 ( L_91 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_91 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
( F_42 ( V_51 , V_95 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 1 ] = V_81 & 0xfffffffc ;
V_150 [ V_95 + 2 ] = ( V_150 [ V_95 + 2 ] & 0xffffff00 ) | ( F_98 ( V_81 ) & 0xff ) ;
break;
}
case V_469 :
{
T_4 V_81 ;
if ( V_120 -> V_127 != 3 ) {
F_63 ( L_92 ) ;
return - V_66 ;
}
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_92 ) ;
return - V_66 ;
}
V_81 = V_163 -> V_201 . V_202 +
( F_42 ( V_51 , V_95 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) << 32 ) ;
V_150 [ V_95 + 1 ] = V_81 & 0xfffffffc ;
V_150 [ V_95 + 2 ] = ( V_150 [ V_95 + 2 ] & 0xffffff00 ) | ( F_98 ( V_81 ) & 0xff ) ;
break;
}
case V_470 :
V_446 = ( V_448 << 2 ) + V_471 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_471 ) ||
( V_446 >= V_472 ) ||
( V_447 >= V_472 ) ) {
F_63 ( L_93 ) ;
return - V_66 ;
}
for ( V_14 = 0 ; V_14 < V_120 -> V_127 ; V_14 ++ ) {
V_130 = V_446 + ( 4 * V_14 ) ;
V_82 = F_80 ( V_51 , V_130 , V_95 + 1 + V_14 ) ;
if ( V_82 )
return V_82 ;
}
break;
case V_473 :
V_446 = ( V_448 << 2 ) + V_474 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_474 ) ||
( V_446 >= V_475 ) ||
( V_447 >= V_475 ) ) {
F_63 ( L_94 ) ;
return - V_66 ;
}
for ( V_14 = 0 ; V_14 < V_120 -> V_127 ; V_14 ++ ) {
V_130 = V_446 + ( 4 * V_14 ) ;
V_82 = F_80 ( V_51 , V_130 , V_95 + 1 + V_14 ) ;
if ( V_82 )
return V_82 ;
}
break;
case V_476 :
if ( V_120 -> V_127 % 8 ) {
F_63 ( L_95 ) ;
return - V_66 ;
}
V_446 = ( V_448 << 2 ) + V_477 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_477 ) ||
( V_446 >= V_478 ) ||
( V_447 >= V_478 ) ) {
F_63 ( L_95 ) ;
return - V_66 ;
}
for ( V_14 = 0 ; V_14 < ( V_120 -> V_127 / 8 ) ; V_14 ++ ) {
struct V_92 * V_93 , * V_94 ;
T_1 V_96 , V_97 ;
T_1 V_84 , V_81 ;
switch ( F_99 ( F_42 ( V_51 , V_95 + 1 + ( V_14 * 8 ) + 7 ) ) ) {
case V_479 :
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_96 ) ;
return - V_66 ;
}
if ( ! ( V_51 -> V_207 & V_208 ) ) {
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 1 ] |=
F_100 ( F_1 ( V_163 -> V_201 . V_1 ) ) ;
if ( V_163 -> V_201 . V_1 & V_2 ) {
unsigned V_70 , V_73 , V_209 , V_210 ;
F_83 ( V_163 -> V_201 . V_1 ,
& V_70 , & V_73 , & V_209 ,
& V_210 ) ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 6 ] |= F_101 ( V_210 ) ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 7 ] |=
F_102 ( V_70 ) |
F_103 ( V_73 ) |
F_104 ( V_209 ) |
F_105 ( F_2 ( V_13 -> V_7 ) ) ;
}
}
V_93 = V_163 -> V_216 ;
V_96 = ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_96 ) ;
return - V_66 ;
}
V_97 = ( T_1 ) ( ( V_163 -> V_201 . V_202 >> 8 ) & 0xffffffff ) ;
V_94 = V_163 -> V_216 ;
V_82 = F_41 ( V_51 , V_93 , V_94 , V_95 + 1 + ( V_14 * 8 ) ) ;
if ( V_82 )
return V_82 ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 2 ] += V_96 ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 3 ] += V_97 ;
break;
case V_480 :
{
T_4 V_481 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_97 ) ;
return - V_66 ;
}
V_81 = F_42 ( V_51 , V_95 + 1 + ( V_14 * 8 ) + 0 ) ;
V_84 = F_42 ( V_51 , V_95 + 1 + ( V_14 * 8 ) + 1 ) ;
if ( V_51 -> V_155 && ( V_84 + V_81 ) > F_23 ( V_163 -> V_216 ) ) {
F_7 ( V_51 -> V_64 , L_98 ) ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 1 ] = F_23 ( V_163 -> V_216 ) - V_81 ;
}
V_481 = V_163 -> V_201 . V_202 + V_81 ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 0 ] = V_481 ;
V_150 [ V_95 + 1 + ( V_14 * 8 ) + 2 ] = ( V_150 [ V_95 + 1 + ( V_14 * 8 ) + 2 ] & 0xffffff00 ) |
( F_98 ( V_481 ) & 0xff ) ;
break;
}
case V_482 :
case V_483 :
default:
F_63 ( L_95 ) ;
return - V_66 ;
}
}
break;
case V_484 :
break;
case V_485 :
V_446 = ( V_448 << 2 ) + V_486 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_486 ) ||
( V_446 >= V_487 ) ||
( V_447 >= V_487 ) ) {
F_63 ( L_99 ) ;
return - V_66 ;
}
break;
case V_488 :
V_446 = ( V_448 << 2 ) + V_489 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_489 ) ||
( V_446 >= V_490 ) ||
( V_447 >= V_490 ) ) {
F_63 ( L_100 ) ;
return - V_66 ;
}
break;
case V_491 :
V_446 = ( V_448 << 2 ) + V_492 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_492 ) ||
( V_446 >= V_493 ) ||
( V_447 >= V_493 ) ) {
F_63 ( L_101 ) ;
return - V_66 ;
}
break;
case V_494 :
if ( V_120 -> V_127 % 3 ) {
F_63 ( L_102 ) ;
return - V_66 ;
}
V_446 = ( V_448 << 2 ) + V_495 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_495 ) ||
( V_446 >= V_496 ) ||
( V_447 >= V_496 ) ) {
F_63 ( L_102 ) ;
return - V_66 ;
}
break;
case V_497 :
if ( V_120 -> V_127 != 4 ) {
F_63 ( L_103 ) ;
return - V_66 ;
}
if ( V_448 & 0x1 ) {
T_2 V_81 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_104 ) ;
return - V_66 ;
}
V_81 = F_42 ( V_51 , V_95 + 1 ) ;
V_81 += ( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_81 + 4 ) > F_23 ( V_163 -> V_216 ) ) {
F_63 ( L_105 ,
V_81 + 4 , F_23 ( V_163 -> V_216 ) ) ;
return - V_66 ;
}
V_81 += V_163 -> V_201 . V_202 ;
V_150 [ V_95 + 1 ] = V_81 ;
V_150 [ V_95 + 2 ] = F_98 ( V_81 ) & 0xff ;
}
if ( ( ( V_448 >> 1 ) & 0x3 ) == 2 ) {
T_2 V_81 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_106 ) ;
return - V_66 ;
}
V_81 = F_42 ( V_51 , V_95 + 3 ) ;
V_81 += ( ( T_2 ) ( F_42 ( V_51 , V_95 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_81 + 4 ) > F_23 ( V_163 -> V_216 ) ) {
F_63 ( L_107 ,
V_81 + 4 , F_23 ( V_163 -> V_216 ) ) ;
return - V_66 ;
}
V_81 += V_163 -> V_201 . V_202 ;
V_150 [ V_95 + 3 ] = V_81 ;
V_150 [ V_95 + 4 ] = F_98 ( V_81 ) & 0xff ;
}
break;
case V_498 :
if ( V_120 -> V_127 != 4 ) {
F_63 ( L_108 ) ;
return - V_66 ;
}
if ( V_448 & 0x1 ) {
T_2 V_81 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_109 ) ;
return - V_66 ;
}
V_81 = F_42 ( V_51 , V_95 + 1 ) ;
V_81 += ( ( T_2 ) ( F_42 ( V_51 , V_95 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_81 + 4 ) > F_23 ( V_163 -> V_216 ) ) {
F_63 ( L_110 ,
V_81 + 4 , F_23 ( V_163 -> V_216 ) ) ;
return - V_66 ;
}
V_81 += V_163 -> V_201 . V_202 ;
V_150 [ V_95 + 1 ] = V_81 ;
V_150 [ V_95 + 2 ] = F_98 ( V_81 ) & 0xff ;
} else {
V_130 = F_42 ( V_51 , V_95 + 1 ) << 2 ;
if ( ! F_96 ( V_51 , V_130 , V_95 + 1 ) )
return - V_66 ;
}
if ( V_448 & 0x2 ) {
T_2 V_81 ;
V_82 = F_71 ( V_51 , & V_163 ) ;
if ( V_82 ) {
F_63 ( L_111 ) ;
return - V_66 ;
}
V_81 = F_42 ( V_51 , V_95 + 3 ) ;
V_81 += ( ( T_2 ) ( F_42 ( V_51 , V_95 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_81 + 4 ) > F_23 ( V_163 -> V_216 ) ) {
F_63 ( L_112 ,
V_81 + 4 , F_23 ( V_163 -> V_216 ) ) ;
return - V_66 ;
}
V_81 += V_163 -> V_201 . V_202 ;
V_150 [ V_95 + 3 ] = V_81 ;
V_150 [ V_95 + 4 ] = F_98 ( V_81 ) & 0xff ;
} else {
V_130 = F_42 ( V_51 , V_95 + 3 ) << 2 ;
if ( ! F_96 ( V_51 , V_130 , V_95 + 3 ) )
return - V_66 ;
}
break;
case V_139 :
break;
default:
F_63 ( L_113 , V_120 -> V_132 ) ;
return - V_66 ;
}
return 0 ;
}
int F_106 ( struct V_50 * V_51 )
{
struct V_119 V_120 ;
struct V_12 * V_13 ;
T_1 V_115 ;
int V_82 ;
if ( V_51 -> V_13 == NULL ) {
V_13 = F_107 ( sizeof( * V_13 ) , V_499 ) ;
if ( V_13 == NULL )
return - V_500 ;
F_3 ( V_13 ) ;
if ( V_51 -> V_155 -> V_104 >= V_166 )
V_115 = V_51 -> V_155 -> V_501 . V_502 . V_503 ;
else
V_115 = V_51 -> V_155 -> V_501 . V_504 . V_503 ;
switch ( V_115 & 0xf ) {
case 0 :
V_13 -> V_71 = 1 ;
break;
case 1 :
default:
V_13 -> V_71 = 2 ;
break;
case 2 :
V_13 -> V_71 = 4 ;
break;
case 3 :
V_13 -> V_71 = 8 ;
break;
}
switch ( ( V_115 & 0xf0 ) >> 4 ) {
case 0 :
V_13 -> V_7 = 4 ;
break;
case 1 :
default:
V_13 -> V_7 = 8 ;
break;
case 2 :
V_13 -> V_7 = 16 ;
break;
}
switch ( ( V_115 & 0xf00 ) >> 8 ) {
case 0 :
V_13 -> V_63 = 256 ;
break;
case 1 :
default:
V_13 -> V_63 = 512 ;
break;
}
switch ( ( V_115 & 0xf000 ) >> 12 ) {
case 0 :
V_13 -> V_505 = 1 ;
break;
case 1 :
default:
V_13 -> V_505 = 2 ;
break;
case 2 :
V_13 -> V_505 = 4 ;
break;
}
V_51 -> V_13 = V_13 ;
}
do {
V_82 = F_66 ( V_51 , & V_120 , V_51 -> V_95 ) ;
if ( V_82 ) {
F_108 ( V_51 -> V_13 ) ;
V_51 -> V_13 = NULL ;
return V_82 ;
}
V_51 -> V_95 += V_120 . V_127 + 2 ;
switch ( V_120 . type ) {
case V_129 :
V_82 = F_79 ( V_51 , & V_120 ) ;
break;
case V_133 :
break;
case V_131 :
V_82 = F_97 ( V_51 , & V_120 ) ;
break;
default:
F_63 ( L_114 , V_120 . type ) ;
F_108 ( V_51 -> V_13 ) ;
V_51 -> V_13 = NULL ;
return - V_66 ;
}
if ( V_82 ) {
F_108 ( V_51 -> V_13 ) ;
V_51 -> V_13 = NULL ;
return V_82 ;
}
} while ( V_51 -> V_95 < V_51 -> V_123 [ V_51 -> V_124 ] . V_126 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib->ptr[r]);
mdelay(1);
}
#endif
F_108 ( V_51 -> V_13 ) ;
V_51 -> V_13 = NULL ;
return 0 ;
}
static bool F_109 ( T_1 V_130 )
{
if ( V_130 >= 0x28000 )
return true ;
switch ( V_130 ) {
case V_506 :
case V_507 :
case V_508 :
case V_509 :
case V_510 :
case V_511 :
case V_512 :
case V_513 :
case V_514 :
case V_515 :
case V_516 :
case V_517 :
case V_518 :
case V_519 :
case V_520 :
case V_521 :
case V_522 :
case V_523 :
case V_524 :
case V_525 :
case V_526 :
case V_527 :
case V_528 :
case V_529 :
case V_530 :
case V_531 :
case V_532 :
case V_362 :
case V_533 :
case V_534 :
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
case V_542 :
case V_543 :
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
case V_550 :
case V_551 :
case V_552 :
case V_553 :
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_564 :
case V_565 :
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
case V_571 :
case V_572 :
case V_573 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_574 :
case V_575 :
return true ;
default:
return false ;
}
}
static int F_110 ( struct V_576 * V_155 ,
T_1 * V_150 , struct V_119 * V_120 )
{
T_1 V_95 = V_120 -> V_95 + 1 ;
T_1 V_448 = V_150 [ V_95 ] ;
T_1 V_446 , V_447 , V_130 , V_14 ;
switch ( V_120 -> V_132 ) {
case V_139 :
case V_577 :
case V_454 :
case V_578 :
case V_464 :
case V_465 :
case V_579 :
case V_449 :
case V_580 :
case V_581 :
case V_582 :
case V_583 :
case V_456 :
case V_458 :
case V_451 :
case V_462 :
case V_452 :
case V_457 :
case V_459 :
case V_461 :
case V_453 :
case V_460 :
case V_497 :
case V_463 :
case V_584 :
case V_585 :
case V_152 :
case V_586 :
case V_466 :
case V_467 :
case V_468 :
case V_469 :
case V_473 :
case V_485 :
case V_488 :
case V_476 :
case V_494 :
case V_491 :
case V_587 :
case V_588 :
case V_589 :
case V_455 :
break;
case V_590 :
if ( V_448 & 0x100 ) {
V_130 = V_150 [ V_95 + 5 ] * 4 ;
if ( ! F_109 ( V_130 ) )
return - V_66 ;
}
break;
case V_498 :
if ( V_448 & 0x2 ) {
V_130 = V_150 [ V_95 + 3 ] * 4 ;
if ( ! F_109 ( V_130 ) )
return - V_66 ;
}
break;
case V_470 :
V_446 = ( V_448 << 2 ) + V_471 ;
V_447 = 4 * V_120 -> V_127 + V_446 - 4 ;
if ( ( V_446 < V_471 ) ||
( V_446 >= V_472 ) ||
( V_447 >= V_472 ) ) {
F_63 ( L_93 ) ;
return - V_66 ;
}
for ( V_14 = 0 ; V_14 < V_120 -> V_127 ; V_14 ++ ) {
V_130 = V_446 + ( 4 * V_14 ) ;
if ( ! F_109 ( V_130 ) )
return - V_66 ;
}
break;
default:
return - V_66 ;
}
return 0 ;
}
int F_111 ( struct V_576 * V_155 , struct V_591 * V_150 )
{
int V_592 = 0 ;
T_1 V_95 = 0 ;
struct V_119 V_120 ;
do {
V_120 . V_95 = V_95 ;
V_120 . type = F_67 ( V_150 -> V_151 [ V_95 ] ) ;
V_120 . V_127 = F_68 ( V_150 -> V_151 [ V_95 ] ) ;
V_120 . V_128 = 0 ;
switch ( V_120 . type ) {
case V_129 :
F_95 ( V_155 -> V_64 , L_115 ) ;
V_592 = - V_66 ;
break;
case V_133 :
V_95 += 1 ;
break;
case V_131 :
V_120 . V_132 = F_70 ( V_150 -> V_151 [ V_95 ] ) ;
V_592 = F_110 ( V_155 , V_150 -> V_151 , & V_120 ) ;
V_95 += V_120 . V_127 + 2 ;
break;
default:
F_95 ( V_155 -> V_64 , L_114 , V_120 . type ) ;
V_592 = - V_66 ;
break;
}
if ( V_592 )
break;
} while ( V_95 < V_150 -> V_126 );
return V_592 ;
}
