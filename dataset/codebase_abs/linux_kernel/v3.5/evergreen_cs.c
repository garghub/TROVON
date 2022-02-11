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
V_13 -> V_24 [ V_14 ] = 0xfffffff ;
V_13 -> V_25 [ V_14 ] = 0 ;
}
V_13 -> V_26 = 0xFFFFFFFF ;
V_13 -> V_27 = 0xFFFFFFFF ;
V_13 -> V_28 = true ;
V_13 -> V_29 = 0xffffffff ;
V_13 -> V_30 = 0xFFFFC000 ;
V_13 -> V_31 = 0xFFFFFFFF ;
V_13 -> V_32 = 0xFFFFFFFF ;
V_13 -> V_33 = 0xFFFFFFFF ;
V_13 -> V_34 = 0xFFFFFFFF ;
V_13 -> V_35 = 0xFFFFFFFF ;
V_13 -> V_36 = NULL ;
V_13 -> V_37 = NULL ;
V_13 -> V_38 = 0xFFFFFFFF ;
V_13 -> V_39 = 0xFFFFFFFF ;
V_13 -> V_40 = 0xFFFFFFFF ;
V_13 -> V_41 = NULL ;
V_13 -> V_42 = NULL ;
V_13 -> V_43 = true ;
V_13 -> V_44 = NULL ;
V_13 -> V_45 = 0xFFFFFFFF ;
V_13 -> V_46 = 0 ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
V_13 -> V_47 [ V_14 ] = 0 ;
V_13 -> V_48 [ V_14 ] = NULL ;
V_13 -> V_49 [ V_14 ] = 0xFFFFFFFF ;
}
V_13 -> V_50 = true ;
V_13 -> V_51 = false ;
}
static int F_4 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 )
{
V_55 -> V_57 = V_55 -> V_58 * V_55 -> V_59 * V_55 -> V_60 * V_55 -> V_61 ;
V_55 -> V_62 = V_55 -> V_60 ;
V_55 -> V_63 = 1 ;
V_55 -> V_64 = 1 ;
return 0 ;
}
static int F_5 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
unsigned V_63 ;
V_63 = F_6 ( 64 , V_13 -> V_65 / V_55 -> V_60 ) ;
V_55 -> V_57 = V_55 -> V_58 * V_55 -> V_59 * V_55 -> V_60 * V_55 -> V_61 ;
V_55 -> V_62 = V_13 -> V_65 ;
V_55 -> V_63 = V_63 ;
V_55 -> V_64 = 1 ;
if ( V_55 -> V_58 & ( V_63 - 1 ) ) {
if ( V_56 ) {
F_7 ( V_53 -> V_66 , L_1 ,
V_67 , __LINE__ , V_56 , V_55 -> V_58 , V_63 ) ;
}
return - V_68 ;
}
return 0 ;
}
static int F_8 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
unsigned V_63 ;
V_63 = V_13 -> V_65 / ( 8 * V_55 -> V_60 * V_55 -> V_61 ) ;
V_63 = F_6 ( 8 , V_63 ) ;
V_55 -> V_57 = V_55 -> V_58 * V_55 -> V_59 * V_55 -> V_60 ;
V_55 -> V_62 = V_13 -> V_65 ;
V_55 -> V_63 = V_63 ;
V_55 -> V_64 = 8 ;
if ( ( V_55 -> V_58 & ( V_63 - 1 ) ) ) {
if ( V_56 ) {
F_7 ( V_53 -> V_66 , L_2 ,
V_67 , __LINE__ , V_56 , V_55 -> V_58 , V_63 ,
V_13 -> V_65 , V_55 -> V_60 , V_55 -> V_61 ) ;
}
return - V_68 ;
}
if ( ( V_55 -> V_59 & ( 8 - 1 ) ) ) {
if ( V_56 ) {
F_7 ( V_53 -> V_66 , L_3 ,
V_67 , __LINE__ , V_56 , V_55 -> V_59 ) ;
}
return - V_68 ;
}
return 0 ;
}
static int F_9 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
unsigned V_63 , V_64 , V_69 , V_70 ;
unsigned V_71 , V_72 , V_73 ;
V_69 = 64 * V_55 -> V_60 * V_55 -> V_61 ;
V_70 = 1 ;
if ( V_69 > V_55 -> V_74 ) {
V_70 = V_69 / V_55 -> V_74 ;
}
V_69 = V_69 / V_70 ;
V_63 = ( 8 * V_55 -> V_75 * V_13 -> V_76 ) * V_55 -> V_77 ;
V_64 = ( 8 * V_55 -> V_78 * V_55 -> V_7 ) / V_55 -> V_77 ;
V_73 = ( V_63 / 8 ) * ( V_64 / 8 ) * V_69 ; ;
V_71 = V_55 -> V_58 / V_63 ;
V_72 = ( V_71 * V_55 -> V_59 ) / V_64 ;
V_55 -> V_57 = V_72 * V_73 * V_70 ;
V_55 -> V_62 = ( V_63 / 8 ) * ( V_64 / 8 ) * V_69 ;
V_55 -> V_63 = V_63 ;
V_55 -> V_64 = V_64 ;
if ( ( V_55 -> V_58 & ( V_63 - 1 ) ) ) {
if ( V_56 ) {
F_7 ( V_53 -> V_66 , L_1 ,
V_67 , __LINE__ , V_56 , V_55 -> V_58 , V_63 ) ;
}
return - V_68 ;
}
if ( ( V_55 -> V_59 & ( V_64 - 1 ) ) ) {
if ( V_56 ) {
F_7 ( V_53 -> V_66 , L_4 ,
V_67 , __LINE__ , V_56 , V_55 -> V_59 , V_64 ) ;
}
return - V_68 ;
}
return 0 ;
}
static int F_10 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 )
{
V_55 -> V_60 = F_11 ( V_55 -> V_79 ) ;
switch ( V_55 -> V_80 ) {
case V_6 :
return F_4 ( V_53 , V_55 , V_56 ) ;
case V_81 :
return F_5 ( V_53 , V_55 , V_56 ) ;
case V_5 :
return F_8 ( V_53 , V_55 , V_56 ) ;
case V_3 :
return F_9 ( V_53 , V_55 , V_56 ) ;
default:
F_7 ( V_53 -> V_66 , L_5 ,
V_67 , __LINE__ , V_56 , V_55 -> V_80 ) ;
return - V_68 ;
}
return - V_68 ;
}
static int F_12 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
const char * V_56 )
{
switch ( V_55 -> V_80 ) {
case V_3 :
break;
case V_6 :
case V_81 :
case V_5 :
return 0 ;
default:
F_7 ( V_53 -> V_66 , L_5 ,
V_67 , __LINE__ , V_56 , V_55 -> V_80 ) ;
return - V_68 ;
}
switch ( V_55 -> V_7 ) {
case 0 : V_55 -> V_7 = 2 ; break;
case 1 : V_55 -> V_7 = 4 ; break;
case 2 : V_55 -> V_7 = 8 ; break;
case 3 : V_55 -> V_7 = 16 ; break;
default:
F_7 ( V_53 -> V_66 , L_6 ,
V_67 , __LINE__ , V_56 , V_55 -> V_7 ) ;
return - V_68 ;
}
switch ( V_55 -> V_75 ) {
case 0 : V_55 -> V_75 = 1 ; break;
case 1 : V_55 -> V_75 = 2 ; break;
case 2 : V_55 -> V_75 = 4 ; break;
case 3 : V_55 -> V_75 = 8 ; break;
default:
F_7 ( V_53 -> V_66 , L_7 ,
V_67 , __LINE__ , V_56 , V_55 -> V_75 ) ;
return - V_68 ;
}
switch ( V_55 -> V_78 ) {
case 0 : V_55 -> V_78 = 1 ; break;
case 1 : V_55 -> V_78 = 2 ; break;
case 2 : V_55 -> V_78 = 4 ; break;
case 3 : V_55 -> V_78 = 8 ; break;
default:
F_7 ( V_53 -> V_66 , L_8 ,
V_67 , __LINE__ , V_56 , V_55 -> V_78 ) ;
return - V_68 ;
}
switch ( V_55 -> V_77 ) {
case 0 : V_55 -> V_77 = 1 ; break;
case 1 : V_55 -> V_77 = 2 ; break;
case 2 : V_55 -> V_77 = 4 ; break;
case 3 : V_55 -> V_77 = 8 ; break;
default:
F_7 ( V_53 -> V_66 , L_9 ,
V_67 , __LINE__ , V_56 , V_55 -> V_77 ) ;
return - V_68 ;
}
switch ( V_55 -> V_74 ) {
case 0 : V_55 -> V_74 = 64 ; break;
case 1 : V_55 -> V_74 = 128 ; break;
case 2 : V_55 -> V_74 = 256 ; break;
case 3 : V_55 -> V_74 = 512 ; break;
case 4 : V_55 -> V_74 = 1024 ; break;
case 5 : V_55 -> V_74 = 2048 ; break;
case 6 : V_55 -> V_74 = 4096 ; break;
default:
F_7 ( V_53 -> V_66 , L_10 ,
V_67 , __LINE__ , V_56 , V_55 -> V_74 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_13 ( struct V_52 * V_53 , unsigned V_82 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_54 V_55 ;
unsigned V_83 , V_84 , V_85 ;
unsigned long V_86 ;
int V_87 ;
V_85 = F_14 ( V_13 -> V_22 [ V_82 ] ) + 1 ;
V_83 = V_13 -> V_23 [ V_82 ] ;
V_84 = V_13 -> V_24 [ V_82 ] ;
V_55 . V_58 = ( V_83 + 1 ) * 8 ;
V_55 . V_59 = ( ( V_84 + 1 ) * 64 ) / V_55 . V_58 ;
V_55 . V_80 = F_15 ( V_13 -> V_21 [ V_82 ] ) ;
V_55 . V_79 = F_16 ( V_13 -> V_21 [ V_82 ] ) ;
V_55 . V_74 = F_17 ( V_13 -> V_88 [ V_82 ] ) ;
V_55 . V_7 = F_18 ( V_13 -> V_88 [ V_82 ] ) ;
V_55 . V_75 = F_19 ( V_13 -> V_88 [ V_82 ] ) ;
V_55 . V_78 = F_20 ( V_13 -> V_88 [ V_82 ] ) ;
V_55 . V_77 = F_21 ( V_13 -> V_88 [ V_82 ] ) ;
V_55 . V_61 = 1 ;
if ( ! F_22 ( V_55 . V_79 ) ) {
F_7 ( V_53 -> V_66 , L_11 ,
V_67 , __LINE__ , V_55 . V_79 ,
V_82 , V_13 -> V_21 [ V_82 ] ) ;
return - V_68 ;
}
V_87 = F_12 ( V_53 , & V_55 , L_12 ) ;
if ( V_87 ) {
return V_87 ;
}
V_87 = F_10 ( V_53 , & V_55 , L_12 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_13 ,
V_67 , __LINE__ , V_82 , V_13 -> V_23 [ V_82 ] ,
V_13 -> V_24 [ V_82 ] , V_13 -> V_88 [ V_82 ] ,
V_13 -> V_21 [ V_82 ] ) ;
return V_87 ;
}
V_86 = V_13 -> V_20 [ V_82 ] << 8 ;
if ( V_86 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_14 ,
V_67 , __LINE__ , V_82 , V_86 , V_55 . V_62 ) ;
return - V_68 ;
}
V_86 += V_55 . V_57 * V_85 ;
if ( V_86 > F_23 ( V_13 -> V_19 [ V_82 ] ) ) {
if ( ! V_55 . V_80 ) {
volatile T_1 * V_89 = V_53 -> V_89 . V_90 ;
unsigned long V_91 , V_59 , V_92 , V_93 , V_94 = 0 ;
if ( V_55 . V_59 > 8 ) {
V_94 = V_55 . V_59 - 8 ;
}
V_92 = F_23 ( V_13 -> V_19 [ V_82 ] ) ;
V_91 = V_13 -> V_20 [ V_82 ] << 8 ;
for ( V_59 = V_55 . V_59 ; V_59 > V_94 ; V_59 -- ) {
V_93 = V_59 * V_55 . V_58 * V_55 . V_60 * V_55 . V_61 ;
if ( ( V_91 + V_93 * V_85 ) <= V_92 ) {
break;
}
}
if ( V_59 > V_94 ) {
V_55 . V_59 = V_59 ;
V_84 = ( ( V_59 * V_55 . V_58 ) / 64 ) - 1 ;
if ( ! F_10 ( V_53 , & V_55 , L_12 ) ) {
V_91 += V_55 . V_57 * V_85 ;
if ( V_91 <= V_92 ) {
V_89 [ V_13 -> V_25 [ V_82 ] ] = V_84 ;
goto V_95;
}
}
}
}
F_7 ( V_53 -> V_66 , L_15
L_16 ,
V_67 , __LINE__ , V_82 , V_55 . V_57 ,
V_13 -> V_20 [ V_82 ] << 8 , V_85 ,
F_23 ( V_13 -> V_19 [ V_82 ] ) , V_84 ) ;
F_7 ( V_53 -> V_66 , L_17 ,
V_67 , __LINE__ , V_55 . V_58 , V_55 . V_59 ,
V_55 . V_80 , V_55 . V_60 , V_55 . V_61 ,
V_55 . V_75 , V_55 . V_78 ,
V_55 . V_74 , V_55 . V_77 ) ;
return - V_68 ;
}
V_95:
return 0 ;
}
static int F_24 ( struct V_52 * V_53 ,
unsigned V_58 , unsigned V_59 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
unsigned long V_93 ;
if ( V_13 -> V_44 == NULL ) {
F_7 ( V_53 -> V_66 , L_18 ,
V_67 , __LINE__ , V_13 -> V_33 ) ;
return - V_68 ;
}
if ( F_25 ( V_13 -> V_46 ) ) {
V_58 = F_26 ( V_58 , 16 * 8 ) ;
V_59 = F_26 ( V_59 , V_13 -> V_76 * 8 ) ;
} else {
switch ( V_13 -> V_76 ) {
case 8 :
V_58 = F_26 ( V_58 , 64 * 8 ) ;
V_59 = F_26 ( V_59 , 64 * 8 ) ;
break;
case 4 :
V_58 = F_26 ( V_58 , 64 * 8 ) ;
V_59 = F_26 ( V_59 , 32 * 8 ) ;
break;
case 2 :
V_58 = F_26 ( V_58 , 32 * 8 ) ;
V_59 = F_26 ( V_59 , 32 * 8 ) ;
break;
case 1 :
V_58 = F_26 ( V_58 , 32 * 8 ) ;
V_59 = F_26 ( V_59 , 16 * 8 ) ;
break;
default:
F_7 ( V_53 -> V_66 , L_19 ,
V_67 , __LINE__ , V_13 -> V_76 ) ;
return - V_68 ;
}
}
V_58 = V_58 / 8 ;
V_59 = V_59 / 8 ;
V_93 = V_58 * V_59 * 4 ;
V_93 += V_13 -> V_45 ;
if ( V_93 > F_23 ( V_13 -> V_44 ) ) {
F_7 ( V_53 -> V_66 , L_20 ,
V_67 , __LINE__ , F_23 ( V_13 -> V_44 ) ,
V_93 , V_58 , V_59 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_27 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_54 V_55 ;
unsigned V_83 , V_84 , V_85 ;
unsigned long V_86 ;
int V_87 ;
V_85 = F_28 ( V_13 -> V_30 ) + 1 ;
V_83 = F_29 ( V_13 -> V_31 ) ;
V_84 = V_13 -> V_29 ;
V_55 . V_58 = ( V_83 + 1 ) * 8 ;
V_55 . V_59 = ( ( V_84 + 1 ) * 64 ) / V_55 . V_58 ;
V_55 . V_80 = F_30 ( V_13 -> V_33 ) ;
V_55 . V_79 = F_31 ( V_13 -> V_38 ) ;
V_55 . V_74 = F_32 ( V_13 -> V_38 ) ;
V_55 . V_7 = F_33 ( V_13 -> V_33 ) ;
V_55 . V_75 = F_34 ( V_13 -> V_33 ) ;
V_55 . V_78 = F_35 ( V_13 -> V_33 ) ;
V_55 . V_77 = F_36 ( V_13 -> V_33 ) ;
V_55 . V_61 = 1 ;
if ( V_55 . V_79 != 1 ) {
F_7 ( V_53 -> V_66 , L_21 ,
V_67 , __LINE__ , V_55 . V_79 ) ;
return - V_68 ;
}
V_55 . V_79 = V_96 ;
V_87 = F_12 ( V_53 , & V_55 , L_22 ) ;
if ( V_87 ) {
return V_87 ;
}
V_87 = F_10 ( V_53 , & V_55 , NULL ) ;
if ( V_87 ) {
V_55 . V_79 = V_97 ;
V_87 = F_10 ( V_53 , & V_55 , L_22 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_23 ,
V_67 , __LINE__ , V_13 -> V_31 ,
V_13 -> V_29 , V_13 -> V_38 , V_13 -> V_33 ) ;
}
return V_87 ;
}
V_86 = V_13 -> V_39 << 8 ;
if ( V_86 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_24 ,
V_67 , __LINE__ , V_86 , V_55 . V_62 ) ;
return - V_68 ;
}
V_86 += V_55 . V_57 * V_85 ;
if ( V_86 > F_23 ( V_13 -> V_41 ) ) {
F_7 ( V_53 -> V_66 , L_25
L_26 ,
V_67 , __LINE__ , V_55 . V_57 ,
( unsigned long ) V_13 -> V_39 << 8 , V_85 ,
F_23 ( V_13 -> V_41 ) ) ;
F_7 ( V_53 -> V_66 , L_23 ,
V_67 , __LINE__ , V_13 -> V_31 ,
V_13 -> V_29 , V_13 -> V_38 , V_13 -> V_33 ) ;
return - V_68 ;
}
V_86 = V_13 -> V_40 << 8 ;
if ( V_86 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_27 ,
V_67 , __LINE__ , V_86 , V_55 . V_62 ) ;
return - V_68 ;
}
V_86 += V_55 . V_57 * V_85 ;
if ( V_86 > F_23 ( V_13 -> V_42 ) ) {
F_7 ( V_53 -> V_66 , L_28
L_26 ,
V_67 , __LINE__ , V_55 . V_57 ,
( unsigned long ) V_13 -> V_40 << 8 , V_85 ,
F_23 ( V_13 -> V_42 ) ) ;
return - V_68 ;
}
if ( F_37 ( V_13 -> V_33 ) ) {
V_87 = F_24 ( V_53 , V_55 . V_58 , V_55 . V_59 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_38 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_54 V_55 ;
unsigned V_83 , V_84 , V_85 ;
unsigned long V_86 ;
int V_87 ;
V_85 = F_28 ( V_13 -> V_30 ) + 1 ;
V_83 = F_29 ( V_13 -> V_31 ) ;
V_84 = V_13 -> V_29 ;
V_55 . V_58 = ( V_83 + 1 ) * 8 ;
V_55 . V_59 = ( ( V_84 + 1 ) * 64 ) / V_55 . V_58 ;
V_55 . V_80 = F_30 ( V_13 -> V_33 ) ;
V_55 . V_79 = F_39 ( V_13 -> V_33 ) ;
V_55 . V_74 = F_40 ( V_13 -> V_33 ) ;
V_55 . V_7 = F_33 ( V_13 -> V_33 ) ;
V_55 . V_75 = F_34 ( V_13 -> V_33 ) ;
V_55 . V_78 = F_35 ( V_13 -> V_33 ) ;
V_55 . V_77 = F_36 ( V_13 -> V_33 ) ;
V_55 . V_61 = 1 ;
switch ( V_55 . V_79 ) {
case V_98 :
V_55 . V_79 = V_99 ;
break;
case V_100 :
case V_101 :
V_55 . V_79 = V_97 ;
break;
default:
F_7 ( V_53 -> V_66 , L_29 ,
V_67 , __LINE__ , V_55 . V_79 ) ;
return - V_68 ;
}
V_87 = F_12 ( V_53 , & V_55 , L_30 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_31 ,
V_67 , __LINE__ , V_13 -> V_31 ,
V_13 -> V_29 , V_13 -> V_33 ) ;
return V_87 ;
}
V_87 = F_10 ( V_53 , & V_55 , L_30 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_31 ,
V_67 , __LINE__ , V_13 -> V_31 ,
V_13 -> V_29 , V_13 -> V_33 ) ;
return V_87 ;
}
V_86 = V_13 -> V_34 << 8 ;
if ( V_86 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_24 ,
V_67 , __LINE__ , V_86 , V_55 . V_62 ) ;
return - V_68 ;
}
V_86 += V_55 . V_57 * V_85 ;
if ( V_86 > F_23 ( V_13 -> V_36 ) ) {
F_7 ( V_53 -> V_66 , L_32
L_26 ,
V_67 , __LINE__ , V_55 . V_57 ,
( unsigned long ) V_13 -> V_34 << 8 , V_85 ,
F_23 ( V_13 -> V_36 ) ) ;
return - V_68 ;
}
V_86 = V_13 -> V_35 << 8 ;
if ( V_86 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_27 ,
V_67 , __LINE__ , V_86 , V_55 . V_62 ) ;
return - V_68 ;
}
V_86 += V_55 . V_57 * V_85 ;
if ( V_86 > F_23 ( V_13 -> V_37 ) ) {
F_7 ( V_53 -> V_66 , L_33
L_26 ,
V_67 , __LINE__ , V_55 . V_57 ,
( unsigned long ) V_13 -> V_35 << 8 , V_85 ,
F_23 ( V_13 -> V_37 ) ) ;
return - V_68 ;
}
if ( F_37 ( V_13 -> V_33 ) ) {
V_87 = F_24 ( V_53 , V_55 . V_58 , V_55 . V_59 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_41 ( struct V_52 * V_53 ,
struct V_102 * V_103 ,
struct V_102 * V_104 ,
unsigned V_105 )
{
struct V_54 V_55 ;
unsigned long V_106 , V_107 ;
unsigned V_108 , V_109 , V_85 , V_110 , V_111 , V_112 , V_14 ;
T_1 V_113 [ 8 ] ;
int V_87 ;
V_113 [ 0 ] = F_42 ( V_53 , V_105 + 0 ) ;
V_113 [ 1 ] = F_42 ( V_53 , V_105 + 1 ) ;
V_113 [ 2 ] = F_42 ( V_53 , V_105 + 2 ) ;
V_113 [ 3 ] = F_42 ( V_53 , V_105 + 3 ) ;
V_113 [ 4 ] = F_42 ( V_53 , V_105 + 4 ) ;
V_113 [ 5 ] = F_42 ( V_53 , V_105 + 5 ) ;
V_113 [ 6 ] = F_42 ( V_53 , V_105 + 6 ) ;
V_113 [ 7 ] = F_42 ( V_53 , V_105 + 7 ) ;
V_108 = F_43 ( V_113 [ 0 ] ) ;
V_109 = F_44 ( V_113 [ 5 ] ) ;
V_85 = F_45 ( V_113 [ 5 ] ) + 1 ;
V_110 = F_46 ( V_113 [ 0 ] ) + 1 ;
V_111 = F_47 ( V_113 [ 1 ] ) + 1 ;
V_112 = F_48 ( V_113 [ 1 ] ) + 1 ;
V_55 . V_79 = F_49 ( V_113 [ 7 ] ) ;
V_55 . V_58 = ( F_50 ( V_113 [ 0 ] ) + 1 ) * 8 ;
V_55 . V_58 = F_51 ( V_55 . V_79 , V_55 . V_58 ) ;
V_55 . V_59 = F_52 ( V_55 . V_79 , V_111 ) ;
V_55 . V_80 = F_53 ( V_113 [ 1 ] ) ;
V_55 . V_74 = F_54 ( V_113 [ 6 ] ) ;
V_55 . V_7 = F_55 ( V_113 [ 7 ] ) ;
V_55 . V_75 = F_56 ( V_113 [ 7 ] ) ;
V_55 . V_78 = F_57 ( V_113 [ 7 ] ) ;
V_55 . V_77 = F_58 ( V_113 [ 7 ] ) ;
V_55 . V_61 = 1 ;
V_106 = V_113 [ 2 ] << 8 ;
V_107 = V_113 [ 3 ] << 8 ;
if ( ! F_59 ( V_55 . V_79 , V_53 -> V_114 ) ) {
F_7 ( V_53 -> V_66 , L_34 ,
V_67 , __LINE__ , V_55 . V_79 ) ;
return - V_68 ;
}
switch ( V_108 ) {
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_112 = 1 ;
case V_120 :
break;
default:
F_7 ( V_53 -> V_66 , L_35 ,
V_67 , __LINE__ , V_108 ) ;
return - V_68 ;
}
V_87 = F_12 ( V_53 , & V_55 , L_36 ) ;
if ( V_87 ) {
return V_87 ;
}
F_10 ( V_53 , & V_55 , NULL ) ;
V_55 . V_59 = F_60 ( V_55 . V_59 , V_55 . V_64 ) ;
V_87 = F_10 ( V_53 , & V_55 , L_36 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_37 ,
V_67 , __LINE__ , V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 4 ] ,
V_113 [ 5 ] , V_113 [ 6 ] , V_113 [ 7 ] ) ;
return V_87 ;
}
if ( V_106 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_38 ,
V_67 , __LINE__ , V_106 , V_55 . V_62 ) ;
return - V_68 ;
}
if ( V_107 & ( V_55 . V_62 - 1 ) ) {
F_7 ( V_53 -> V_66 , L_39 ,
V_67 , __LINE__ , V_107 , V_55 . V_62 ) ;
return - V_68 ;
}
if ( V_108 == V_121 ) {
V_106 += V_55 . V_57 * V_112 ;
} else {
V_106 += V_55 . V_57 * V_85 ;
}
if ( V_106 > F_23 ( V_103 ) ) {
F_7 ( V_53 -> V_66 , L_40
L_41 ,
V_67 , __LINE__ , V_55 . V_57 ,
( unsigned long ) V_113 [ 2 ] << 8 , V_85 ,
V_112 , F_23 ( V_103 ) ,
V_55 . V_58 , V_55 . V_59 ) ;
return - V_68 ;
}
for ( V_14 = 1 ; V_14 <= V_109 ; V_14 ++ ) {
unsigned V_122 , V_123 , V_124 ;
V_122 = F_61 ( V_110 , V_14 ) ;
V_123 = F_61 ( V_111 , V_14 ) ;
V_124 = F_61 ( V_112 , V_14 ) ;
V_55 . V_58 = F_51 ( V_55 . V_79 , V_122 ) ;
V_55 . V_59 = F_52 ( V_55 . V_79 , V_123 ) ;
switch ( V_55 . V_80 ) {
case V_3 :
if ( V_55 . V_58 < V_55 . V_63 || V_55 . V_59 < V_55 . V_64 ) {
V_55 . V_80 = V_5 ;
}
F_10 ( V_53 , & V_55 , NULL ) ;
break;
case V_6 :
case V_81 :
case V_5 :
break;
default:
F_7 ( V_53 -> V_66 , L_42 ,
V_67 , __LINE__ , V_55 . V_80 ) ;
return - V_68 ;
}
V_55 . V_58 = F_60 ( V_55 . V_58 , V_55 . V_63 ) ;
V_55 . V_59 = F_60 ( V_55 . V_59 , V_55 . V_64 ) ;
V_87 = F_10 ( V_53 , & V_55 , L_43 ) ;
if ( V_87 ) {
return V_87 ;
}
if ( V_108 == V_121 ) {
V_107 += V_55 . V_57 * V_124 ;
} else {
V_107 += V_55 . V_57 * V_85 ;
}
if ( V_107 > F_23 ( V_104 ) ) {
F_7 ( V_53 -> V_66 , L_44
L_45
L_46 ,
V_67 , __LINE__ , V_14 , V_55 . V_57 ,
( unsigned long ) V_113 [ 3 ] << 8 , V_107 , V_85 ,
V_124 , F_23 ( V_104 ) ,
V_110 , V_111 , V_112 ) ;
F_7 ( V_53 -> V_66 , L_17 ,
V_67 , __LINE__ , V_55 . V_58 , V_55 . V_59 ,
V_55 . V_80 , V_55 . V_60 , V_55 . V_61 ,
V_55 . V_75 , V_55 . V_78 ,
V_55 . V_74 , V_55 . V_77 ) ;
return - V_68 ;
}
}
return 0 ;
}
static int F_62 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
unsigned V_91 , V_14 ;
int V_87 ;
unsigned V_125 = 0 ;
if ( V_13 -> V_50 && V_13 -> V_126 ) {
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
if ( V_13 -> V_126 & ( 1 << V_14 ) ) {
V_125 |= ( V_13 -> V_127 >> ( V_14 * 4 ) ) & 0xf ;
}
}
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
if ( V_125 & ( 1 << V_14 ) ) {
if ( V_13 -> V_48 [ V_14 ] ) {
T_2 V_86 = ( T_2 ) V_13 -> V_49 [ V_14 ] +
( T_2 ) V_13 -> V_47 [ V_14 ] ;
if ( V_86 > F_23 ( V_13 -> V_48 [ V_14 ] ) ) {
F_63 ( L_47 ,
V_14 , V_86 ,
F_23 ( V_13 -> V_48 [ V_14 ] ) ) ;
return - V_68 ;
}
} else {
F_7 ( V_53 -> V_66 , L_48 , V_14 ) ;
return - V_68 ;
}
}
}
V_13 -> V_50 = false ;
}
if ( V_13 -> V_51 )
return 0 ;
if ( V_13 -> V_28 ) {
V_91 = V_13 -> V_26 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
if ( ( V_91 >> ( V_14 * 4 ) ) & 0xF ) {
if ( V_13 -> V_19 [ V_14 ] == NULL ) {
F_7 ( V_53 -> V_66 , L_49 ,
V_67 , __LINE__ , V_13 -> V_26 , V_13 -> V_27 , V_14 ) ;
return - V_68 ;
}
V_87 = F_13 ( V_53 , V_14 ) ;
if ( V_87 ) {
return V_87 ;
}
}
}
V_13 -> V_28 = false ;
}
if ( V_13 -> V_43 ) {
if ( F_64 ( V_13 -> V_32 ) ) {
V_87 = F_27 ( V_53 ) ;
if ( V_87 )
return V_87 ;
}
if ( F_65 ( V_13 -> V_32 ) ) {
V_87 = F_38 ( V_53 ) ;
if ( V_87 )
return V_87 ;
}
V_13 -> V_43 = false ;
}
return 0 ;
}
int F_66 ( struct V_52 * V_53 ,
struct V_128 * V_129 ,
unsigned V_105 )
{
struct V_130 * V_131 = & V_53 -> V_132 [ V_53 -> V_133 ] ;
T_3 V_134 ;
if ( V_105 >= V_131 -> V_135 ) {
F_63 ( L_50 ,
V_105 , V_131 -> V_135 ) ;
return - V_68 ;
}
V_134 = F_42 ( V_53 , V_105 ) ;
V_129 -> V_105 = V_105 ;
V_129 -> type = F_67 ( V_134 ) ;
V_129 -> V_136 = F_68 ( V_134 ) ;
V_129 -> V_137 = 0 ;
switch ( V_129 -> type ) {
case V_138 :
V_129 -> V_139 = F_69 ( V_134 ) ;
break;
case V_140 :
V_129 -> V_141 = F_70 ( V_134 ) ;
break;
case V_142 :
V_129 -> V_136 = - 1 ;
break;
default:
F_63 ( L_51 , V_129 -> type , V_105 ) ;
return - V_68 ;
}
if ( ( V_129 -> V_136 + 1 + V_129 -> V_105 ) >= V_131 -> V_135 ) {
F_63 ( L_52 ,
V_129 -> V_105 , V_129 -> type , V_129 -> V_136 , V_131 -> V_135 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_71 ( struct V_52 * V_53 ,
struct V_143 * * V_144 )
{
struct V_130 * V_145 ;
struct V_128 V_146 ;
unsigned V_105 ;
int V_87 ;
if ( V_53 -> V_147 == - 1 ) {
F_63 ( L_53 ) ;
return - V_68 ;
}
* V_144 = NULL ;
V_145 = & V_53 -> V_132 [ V_53 -> V_147 ] ;
V_87 = F_66 ( V_53 , & V_146 , V_53 -> V_105 ) ;
if ( V_87 ) {
return V_87 ;
}
V_53 -> V_105 += V_146 . V_136 + 2 ;
if ( V_146 . type != V_140 || V_146 . V_141 != V_148 ) {
F_63 ( L_54 ,
V_146 . V_105 ) ;
return - V_68 ;
}
V_105 = F_42 ( V_53 , V_146 . V_105 + 1 ) ;
if ( V_105 >= V_145 -> V_135 ) {
F_63 ( L_55 ,
V_105 , V_145 -> V_135 ) ;
return - V_68 ;
}
* V_144 = V_53 -> V_149 [ ( V_105 / 4 ) ] ;
return 0 ;
}
static int F_72 ( struct V_52 * V_53 )
{
struct V_150 * V_151 ;
struct V_152 * V_153 ;
struct V_154 * V_154 ;
struct V_128 V_146 , V_155 ;
int V_156 ;
int V_87 ;
T_3 V_134 , V_157 , V_139 , V_158 ;
volatile T_3 * V_89 ;
V_89 = V_53 -> V_89 . V_90 ;
V_87 = F_66 ( V_53 , & V_155 , V_53 -> V_105 ) ;
if ( V_87 )
return V_87 ;
if ( V_155 . type != V_140 ||
V_155 . V_141 != V_159 ) {
F_63 ( L_56 ) ;
return - V_68 ;
}
V_158 = F_42 ( V_53 , V_155 . V_105 + 1 ) ;
if ( V_158 & 0x10 ) {
F_63 ( L_57 ) ;
return - V_68 ;
}
if ( ( V_158 & 0x7 ) != 0x3 ) {
F_63 ( L_58 ) ;
return - V_68 ;
}
if ( ( F_42 ( V_53 , V_155 . V_105 + 2 ) << 2 ) != V_160 ) {
F_63 ( L_59 ) ;
return - V_68 ;
}
if ( F_42 ( V_53 , V_155 . V_105 + 5 ) != V_161 ) {
F_63 ( L_60 ) ;
return - V_68 ;
}
V_87 = F_66 ( V_53 , & V_146 , V_53 -> V_105 + V_155 . V_136 + 2 ) ;
if ( V_87 )
return V_87 ;
V_157 = V_53 -> V_105 - 2 ;
V_53 -> V_105 += V_155 . V_136 + 2 ;
V_53 -> V_105 += V_146 . V_136 + 2 ;
V_134 = F_42 ( V_53 , V_157 ) ;
V_156 = F_42 ( V_53 , V_157 + 2 + 7 + 1 ) ;
V_139 = F_69 ( V_134 ) ;
V_151 = F_73 ( V_53 -> V_162 -> V_163 , V_156 , V_164 ) ;
if ( ! V_151 ) {
F_63 ( L_61 , V_156 ) ;
return - V_68 ;
}
V_153 = F_74 ( V_151 ) ;
V_154 = F_75 ( V_153 ) ;
V_156 = V_154 -> V_156 ;
if ( ! V_153 -> V_165 ) {
V_89 [ V_157 + 2 ] = F_76 ( 0 ) ;
V_89 [ V_157 + 3 ] = F_76 ( 0 ) ;
V_89 [ V_157 + 4 ] = F_76 ( 0 ) ;
V_89 [ V_157 + 5 ] = F_76 ( 0 ) ;
V_89 [ V_157 + 6 ] = F_76 ( 0 ) ;
V_89 [ V_157 + 7 ] = F_76 ( 0 ) ;
V_89 [ V_157 + 8 ] = F_76 ( 0 ) ;
} else {
switch ( V_139 ) {
case V_166 :
V_134 &= ~ V_167 ;
V_134 |= ( V_166 + V_154 -> V_168 ) >> 2 ;
V_89 [ V_157 ] = V_134 ;
V_89 [ V_157 + 4 ] = ( V_160 + V_154 -> V_168 ) >> 2 ;
break;
default:
F_63 ( L_62 ) ;
return - V_68 ;
}
}
return 0 ;
}
static int F_77 ( struct V_52 * V_53 ,
struct V_128 * V_129 ,
unsigned V_105 , unsigned V_139 )
{
int V_87 ;
switch ( V_139 ) {
case V_166 :
V_87 = F_72 ( V_53 ) ;
if ( V_87 ) {
F_63 ( L_63 ,
V_105 , V_139 ) ;
return V_87 ;
}
break;
default:
F_78 ( V_169 L_64 ,
V_139 , V_105 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_79 ( struct V_52 * V_53 ,
struct V_128 * V_129 )
{
unsigned V_139 , V_14 ;
unsigned V_105 ;
int V_87 ;
V_105 = V_129 -> V_105 + 1 ;
V_139 = V_129 -> V_139 ;
for ( V_14 = 0 ; V_14 <= V_129 -> V_136 ; V_14 ++ , V_105 ++ , V_139 += 4 ) {
V_87 = F_77 ( V_53 , V_129 , V_105 , V_139 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_80 ( struct V_52 * V_53 , T_1 V_139 , T_1 V_105 )
{
struct V_12 * V_13 = (struct V_12 * ) V_53 -> V_13 ;
struct V_143 * V_170 ;
T_1 V_171 ;
T_1 V_172 , V_14 , V_91 , * V_89 ;
int V_87 ;
if ( V_53 -> V_162 -> V_114 >= V_173 )
V_171 = F_81 ( V_174 ) ;
else
V_171 = F_81 ( V_175 ) ;
V_14 = ( V_139 >> 7 ) ;
if ( V_14 >= V_171 ) {
F_7 ( V_53 -> V_66 , L_65 , V_139 , V_105 ) ;
return - V_68 ;
}
V_172 = 1 << ( ( V_139 >> 2 ) & 31 ) ;
if ( V_53 -> V_162 -> V_114 >= V_173 ) {
if ( ! ( V_174 [ V_14 ] & V_172 ) )
return 0 ;
} else {
if ( ! ( V_175 [ V_14 ] & V_172 ) )
return 0 ;
}
V_89 = V_53 -> V_89 . V_90 ;
switch ( V_139 ) {
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
break;
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
break;
case V_210 :
V_13 -> V_32 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_211 :
if ( V_53 -> V_162 -> V_114 < V_173 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
break;
case V_212 :
if ( V_53 -> V_162 -> V_114 < V_173 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
break;
case V_213 :
V_13 -> V_33 = F_42 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_214 & V_215 ) ) {
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] &= ~ F_82 ( 0xf ) ;
V_13 -> V_33 &= ~ F_82 ( 0xf ) ;
V_89 [ V_105 ] |= F_82 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
V_13 -> V_33 |= F_82 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
if ( V_170 -> V_208 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_216 , V_217 ;
F_83 ( V_170 -> V_208 . V_1 ,
& V_75 , & V_78 , & V_216 ,
& V_217 ) ;
V_89 [ V_105 ] |= F_84 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_85 ( V_217 ) |
F_86 ( V_75 ) |
F_87 ( V_78 ) |
F_88 ( V_216 ) ;
}
}
V_13 -> V_43 = true ;
break;
case V_218 :
V_13 -> V_38 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_219 :
V_13 -> V_30 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_220 :
V_13 -> V_31 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_221 :
V_13 -> V_29 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_222 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_13 -> V_34 = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_36 = V_170 -> V_223 ;
V_13 -> V_43 = true ;
break;
case V_224 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_13 -> V_35 = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_37 = V_170 -> V_223 ;
V_13 -> V_43 = true ;
break;
case V_225 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_13 -> V_39 = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_41 = V_170 -> V_223 ;
V_13 -> V_43 = true ;
break;
case V_226 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_13 -> V_40 = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_42 = V_170 -> V_223 ;
V_13 -> V_43 = true ;
break;
case V_227 :
V_13 -> V_126 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_50 = true ;
break;
case V_228 :
V_13 -> V_127 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_50 = true ;
break;
case V_229 :
case V_230 :
case V_231 :
case V_232 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_91 = ( V_139 - V_229 ) / 16 ;
V_13 -> V_49 [ V_91 ] = F_42 ( V_53 , V_105 ) << 8 ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_48 [ V_91 ] = V_170 -> V_223 ;
V_13 -> V_50 = true ;
break;
case V_233 :
case V_234 :
case V_235 :
case V_236 :
V_91 = ( V_139 - V_233 ) / 16 ;
V_13 -> V_47 [ V_91 ] = F_42 ( V_53 , V_105 ) * 4 ;
V_13 -> V_50 = true ;
break;
case V_237 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_68
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
case V_238 :
V_13 -> V_26 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_239 :
V_13 -> V_27 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_240 :
if ( V_53 -> V_162 -> V_114 >= V_173 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_91 = F_42 ( V_53 , V_105 ) & V_241 ;
V_13 -> V_61 = 1 << V_91 ;
break;
case V_242 :
if ( V_53 -> V_162 -> V_114 < V_173 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_91 = F_42 ( V_53 , V_105 ) & V_243 ;
V_13 -> V_61 = 1 << V_91 ;
break;
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
V_91 = ( V_139 - V_244 ) / 0x3c ;
V_13 -> V_22 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_91 = ( ( V_139 - V_252 ) / 0x1c ) + 8 ;
V_13 -> V_22 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
V_91 = ( V_139 - V_256 ) / 0x3c ;
V_13 -> V_21 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_214 & V_215 ) ) {
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] |= F_89 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
V_13 -> V_21 [ V_91 ] |= F_89 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
}
V_13 -> V_28 = true ;
break;
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_91 = ( ( V_139 - V_264 ) / 0x1c ) + 8 ;
V_13 -> V_21 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_214 & V_215 ) ) {
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] |= F_89 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
V_13 -> V_21 [ V_91 ] |= F_89 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
}
V_13 -> V_28 = true ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
V_91 = ( V_139 - V_268 ) / 0x3c ;
V_13 -> V_23 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_276 :
case V_277 :
case V_278 :
case V_279 :
V_91 = ( ( V_139 - V_276 ) / 0x1c ) + 8 ;
V_13 -> V_23 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
V_91 = ( V_139 - V_280 ) / 0x3c ;
V_13 -> V_24 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_13 -> V_25 [ V_91 ] = V_105 ;
V_13 -> V_28 = true ;
break;
case V_288 :
case V_289 :
case V_290 :
case V_291 :
V_91 = ( ( V_139 - V_288 ) / 0x1c ) + 8 ;
V_13 -> V_24 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_13 -> V_25 [ V_91 ] = V_105 ;
V_13 -> V_28 = true ;
break;
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_214 & V_215 ) ) {
if ( V_170 -> V_208 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_216 , V_217 ;
F_83 ( V_170 -> V_208 . V_1 ,
& V_75 , & V_78 , & V_216 ,
& V_217 ) ;
V_89 [ V_105 ] |= F_90 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_91 ( V_217 ) |
F_92 ( V_75 ) |
F_93 ( V_78 ) |
F_94 ( V_216 ) ;
}
}
V_91 = ( ( V_139 - V_292 ) / 0x3c ) ;
V_13 -> V_88 [ V_91 ] = V_89 [ V_105 ] ;
V_13 -> V_28 = true ;
break;
case V_300 :
case V_301 :
case V_302 :
case V_303 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_214 & V_215 ) ) {
if ( V_170 -> V_208 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_216 , V_217 ;
F_83 ( V_170 -> V_208 . V_1 ,
& V_75 , & V_78 , & V_216 ,
& V_217 ) ;
V_89 [ V_105 ] |= F_90 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_91 ( V_217 ) |
F_92 ( V_75 ) |
F_93 ( V_78 ) |
F_94 ( V_216 ) ;
}
}
V_91 = ( ( V_139 - V_300 ) / 0x1c ) + 8 ;
V_13 -> V_88 [ V_91 ] = V_89 [ V_105 ] ;
V_13 -> V_28 = true ;
break;
case V_304 :
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
V_91 = ( V_139 - V_304 ) / 0x3c ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_95 ( V_53 -> V_66 , L_69 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_15 [ V_91 ] = V_170 -> V_223 ;
break;
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
V_91 = ( V_139 - V_312 ) / 0x3c ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_95 ( V_53 -> V_66 , L_69 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_16 [ V_91 ] = V_170 -> V_223 ;
break;
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
V_91 = ( V_139 - V_320 ) / 0x3c ;
V_13 -> V_18 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
break;
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
V_91 = ( V_139 - V_328 ) / 0x3c ;
V_13 -> V_17 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
break;
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_91 = ( V_139 - V_336 ) / 0x3c ;
V_13 -> V_20 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_91 ] = V_170 -> V_223 ;
V_13 -> V_28 = true ;
break;
case V_344 :
case V_345 :
case V_346 :
case V_347 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_91 = ( ( V_139 - V_344 ) / 0x1c ) + 8 ;
V_13 -> V_20 [ V_91 ] = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_91 ] = V_170 -> V_223 ;
V_13 -> V_28 = true ;
break;
case V_348 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_13 -> V_45 = F_42 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_13 -> V_44 = V_170 -> V_223 ;
V_13 -> V_43 = true ;
break;
case V_349 :
V_13 -> V_46 = F_42 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
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
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
case V_449 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
break;
case V_450 :
if ( V_53 -> V_162 -> V_114 >= V_173 ) {
F_7 ( V_53 -> V_66 , L_70
L_67 , V_139 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_70
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
break;
case V_451 :
if ( V_53 -> V_162 -> V_114 < V_173 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_66
L_67 , V_139 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
break;
case V_452 :
V_13 -> V_51 = ( F_42 ( V_53 , V_105 ) & 0x1 ) != 0 ;
break;
default:
F_7 ( V_53 -> V_66 , L_65 , V_139 , V_105 ) ;
return - V_68 ;
}
return 0 ;
}
static bool F_96 ( struct V_52 * V_53 , T_1 V_139 , T_1 V_105 )
{
T_1 V_171 , V_172 , V_14 ;
if ( V_53 -> V_162 -> V_114 >= V_173 )
V_171 = F_81 ( V_174 ) ;
else
V_171 = F_81 ( V_175 ) ;
V_14 = ( V_139 >> 7 ) ;
if ( V_14 >= V_171 ) {
F_7 ( V_53 -> V_66 , L_65 , V_139 , V_105 ) ;
return false ;
}
V_172 = 1 << ( ( V_139 >> 2 ) & 31 ) ;
if ( V_53 -> V_162 -> V_114 >= V_173 ) {
if ( ! ( V_174 [ V_14 ] & V_172 ) )
return true ;
} else {
if ( ! ( V_175 [ V_14 ] & V_172 ) )
return true ;
}
F_7 ( V_53 -> V_66 , L_65 , V_139 , V_105 ) ;
return false ;
}
static int F_97 ( struct V_52 * V_53 ,
struct V_128 * V_129 )
{
struct V_143 * V_170 ;
struct V_12 * V_13 ;
volatile T_1 * V_89 ;
unsigned V_105 ;
unsigned V_14 ;
unsigned V_453 , V_454 , V_139 ;
int V_87 ;
T_1 V_455 ;
V_13 = (struct V_12 * ) V_53 -> V_13 ;
V_89 = V_53 -> V_89 . V_90 ;
V_105 = V_129 -> V_105 + 1 ;
V_455 = F_42 ( V_53 , V_105 ) ;
switch ( V_129 -> V_141 ) {
case V_456 :
{
int V_457 ;
int V_91 ;
T_4 V_86 ;
if ( V_129 -> V_136 != 1 ) {
F_63 ( L_71 ) ;
return - V_68 ;
}
V_91 = F_42 ( V_53 , V_105 + 1 ) ;
V_457 = ( V_91 >> 16 ) & 0x7 ;
if ( V_457 == 0 )
return 0 ;
if ( V_457 > 2 ) {
F_63 ( L_72 , V_457 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_71 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
( V_455 & 0xfffffff0 ) +
( ( T_2 ) ( V_91 & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = ( V_91 & 0xffffff00 ) | ( F_98 ( V_86 ) & 0xff ) ;
}
break;
case V_458 :
if ( V_129 -> V_136 != 1 ) {
F_63 ( L_73 ) ;
return - V_68 ;
}
break;
case V_459 :
case V_460 :
case V_461 :
if ( V_129 -> V_136 ) {
F_63 ( L_74 ) ;
return - V_68 ;
}
break;
case V_462 :
if ( V_53 -> V_162 -> V_114 < V_173 ) {
F_63 ( L_75 ) ;
return - V_68 ;
}
if ( V_129 -> V_136 ) {
F_63 ( L_74 ) ;
return - V_68 ;
}
break;
case V_463 :
{
T_4 V_86 ;
if ( V_129 -> V_136 != 1 ) {
F_63 ( L_76 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_76 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
V_455 +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_98 ( V_86 ) & 0xff ;
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_464 :
{
T_4 V_86 ;
if ( V_129 -> V_136 != 3 ) {
F_63 ( L_78 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_78 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
V_455 +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_98 ( V_86 ) & 0xff ;
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_465 :
{
T_4 V_86 ;
if ( V_129 -> V_136 != 4 ) {
F_63 ( L_79 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_79 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
F_42 ( V_53 , V_105 + 1 ) +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_98 ( V_86 ) & 0xff ;
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_466 :
if ( V_129 -> V_136 != 1 ) {
F_63 ( L_80 ) ;
return - V_68 ;
}
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_81 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_467 :
if ( V_129 -> V_136 != 2 ) {
F_63 ( L_82 ) ;
return - V_68 ;
}
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_81 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_468 :
if ( V_129 -> V_136 < 2 ) {
F_63 ( L_83 ) ;
return - V_68 ;
}
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_469 :
if ( V_129 -> V_136 != 2 ) {
F_63 ( L_84 ) ;
return - V_68 ;
}
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_470 :
if ( V_129 -> V_136 != 3 ) {
F_63 ( L_85 ) ;
return - V_68 ;
}
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_471 :
if ( V_129 -> V_136 != 3 ) {
F_63 ( L_86 ) ;
return - V_68 ;
}
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_81 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_472 :
if ( V_129 -> V_136 != 1 ) {
F_63 ( L_87 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_87 ) ;
return - V_68 ;
}
V_89 [ V_105 + 0 ] = V_455 + ( T_1 ) ( V_170 -> V_208 . V_209 & 0xffffffff ) ;
V_87 = F_62 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_77 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_159 :
if ( V_129 -> V_136 != 5 ) {
F_63 ( L_88 ) ;
return - V_68 ;
}
if ( V_455 & 0x10 ) {
T_4 V_86 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_88 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
( F_42 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = ( V_89 [ V_105 + 1 ] & 0x3 ) | ( V_86 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] = F_98 ( V_86 ) & 0xff ;
}
break;
case V_473 :
if ( V_129 -> V_136 != 3 ) {
F_63 ( L_89 ) ;
return - V_68 ;
}
if ( F_42 ( V_53 , V_105 + 1 ) != 0xffffffff ||
F_42 ( V_53 , V_105 + 2 ) != 0 ) {
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_89 ) ;
return - V_68 ;
}
V_89 [ V_105 + 2 ] += ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
}
break;
case V_474 :
if ( V_129 -> V_136 != 2 && V_129 -> V_136 != 0 ) {
F_63 ( L_90 ) ;
return - V_68 ;
}
if ( V_129 -> V_136 ) {
T_4 V_86 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_90 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
( F_42 ( V_53 , V_105 + 1 ) & 0xfffffff8 ) +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffff8 ;
V_89 [ V_105 + 2 ] = F_98 ( V_86 ) & 0xff ;
}
break;
case V_475 :
{
T_4 V_86 ;
if ( V_129 -> V_136 != 4 ) {
F_63 ( L_91 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_91 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
( F_42 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffffc ;
V_89 [ V_105 + 2 ] = ( V_89 [ V_105 + 2 ] & 0xffffff00 ) | ( F_98 ( V_86 ) & 0xff ) ;
break;
}
case V_476 :
{
T_4 V_86 ;
if ( V_129 -> V_136 != 3 ) {
F_63 ( L_92 ) ;
return - V_68 ;
}
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_92 ) ;
return - V_68 ;
}
V_86 = V_170 -> V_208 . V_209 +
( F_42 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffffc ;
V_89 [ V_105 + 2 ] = ( V_89 [ V_105 + 2 ] & 0xffffff00 ) | ( F_98 ( V_86 ) & 0xff ) ;
break;
}
case V_477 :
V_453 = ( V_455 << 2 ) + V_478 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_478 ) ||
( V_453 >= V_479 ) ||
( V_454 >= V_479 ) ) {
F_63 ( L_93 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_129 -> V_136 ; V_14 ++ ) {
V_139 = V_453 + ( 4 * V_14 ) ;
V_87 = F_80 ( V_53 , V_139 , V_105 + 1 + V_14 ) ;
if ( V_87 )
return V_87 ;
}
break;
case V_480 :
V_453 = ( V_455 << 2 ) + V_481 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_481 ) ||
( V_453 >= V_482 ) ||
( V_454 >= V_482 ) ) {
F_63 ( L_94 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_129 -> V_136 ; V_14 ++ ) {
V_139 = V_453 + ( 4 * V_14 ) ;
V_87 = F_80 ( V_53 , V_139 , V_105 + 1 + V_14 ) ;
if ( V_87 )
return V_87 ;
}
break;
case V_483 :
if ( V_129 -> V_136 % 8 ) {
F_63 ( L_95 ) ;
return - V_68 ;
}
V_453 = ( V_455 << 2 ) + V_484 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_484 ) ||
( V_453 >= V_485 ) ||
( V_454 >= V_485 ) ) {
F_63 ( L_95 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < ( V_129 -> V_136 / 8 ) ; V_14 ++ ) {
struct V_102 * V_103 , * V_104 ;
T_1 V_106 , V_107 ;
T_1 V_93 , V_86 ;
switch ( F_99 ( F_42 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 7 ) ) ) {
case V_486 :
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_96 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_214 & V_215 ) ) {
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 1 ] |=
F_100 ( F_1 ( V_170 -> V_208 . V_1 ) ) ;
if ( V_170 -> V_208 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_216 , V_217 ;
F_83 ( V_170 -> V_208 . V_1 ,
& V_75 , & V_78 , & V_216 ,
& V_217 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 6 ] |= F_101 ( V_217 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 7 ] |=
F_102 ( V_75 ) |
F_103 ( V_78 ) |
F_104 ( V_216 ) |
F_105 ( F_2 ( V_13 -> V_7 ) ) ;
}
}
V_103 = V_170 -> V_223 ;
V_106 = ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_96 ) ;
return - V_68 ;
}
V_107 = ( T_1 ) ( ( V_170 -> V_208 . V_209 >> 8 ) & 0xffffffff ) ;
V_104 = V_170 -> V_223 ;
V_87 = F_41 ( V_53 , V_103 , V_104 , V_105 + 1 + ( V_14 * 8 ) ) ;
if ( V_87 )
return V_87 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] += V_106 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 3 ] += V_107 ;
break;
case V_487 :
{
T_4 V_488 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_97 ) ;
return - V_68 ;
}
V_86 = F_42 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 0 ) ;
V_93 = F_42 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 1 ) ;
if ( V_53 -> V_162 && ( V_93 + V_86 ) > F_23 ( V_170 -> V_223 ) ) {
F_7 ( V_53 -> V_66 , L_98 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 1 ] = F_23 ( V_170 -> V_223 ) - V_86 ;
}
V_488 = V_170 -> V_208 . V_209 + V_86 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 0 ] = V_488 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] = ( V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] & 0xffffff00 ) |
( F_98 ( V_488 ) & 0xff ) ;
break;
}
case V_489 :
case V_490 :
default:
F_63 ( L_95 ) ;
return - V_68 ;
}
}
break;
case V_491 :
break;
case V_492 :
V_453 = ( V_455 << 2 ) + V_493 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_493 ) ||
( V_453 >= V_494 ) ||
( V_454 >= V_494 ) ) {
F_63 ( L_99 ) ;
return - V_68 ;
}
break;
case V_495 :
V_453 = ( V_455 << 2 ) + V_496 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_496 ) ||
( V_453 >= V_497 ) ||
( V_454 >= V_497 ) ) {
F_63 ( L_100 ) ;
return - V_68 ;
}
break;
case V_498 :
V_453 = ( V_455 << 2 ) + V_499 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_499 ) ||
( V_453 >= V_500 ) ||
( V_454 >= V_500 ) ) {
F_63 ( L_101 ) ;
return - V_68 ;
}
break;
case V_501 :
if ( V_129 -> V_136 % 3 ) {
F_63 ( L_102 ) ;
return - V_68 ;
}
V_453 = ( V_455 << 2 ) + V_502 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_502 ) ||
( V_453 >= V_503 ) ||
( V_454 >= V_503 ) ) {
F_63 ( L_102 ) ;
return - V_68 ;
}
break;
case V_504 :
if ( V_129 -> V_136 != 4 ) {
F_63 ( L_103 ) ;
return - V_68 ;
}
if ( V_455 & 0x1 ) {
T_2 V_86 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_104 ) ;
return - V_68 ;
}
V_86 = F_42 ( V_53 , V_105 + 1 ) ;
V_86 += ( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_170 -> V_223 ) ) {
F_63 ( L_105 ,
V_86 + 4 , F_23 ( V_170 -> V_223 ) ) ;
return - V_68 ;
}
V_86 += V_170 -> V_208 . V_209 ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_98 ( V_86 ) & 0xff ;
}
if ( ( ( V_455 >> 1 ) & 0x3 ) == 2 ) {
T_2 V_86 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_106 ) ;
return - V_68 ;
}
V_86 = F_42 ( V_53 , V_105 + 3 ) ;
V_86 += ( ( T_2 ) ( F_42 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_170 -> V_223 ) ) {
F_63 ( L_107 ,
V_86 + 4 , F_23 ( V_170 -> V_223 ) ) ;
return - V_68 ;
}
V_86 += V_170 -> V_208 . V_209 ;
V_89 [ V_105 + 3 ] = V_86 ;
V_89 [ V_105 + 4 ] = F_98 ( V_86 ) & 0xff ;
}
break;
case V_505 :
if ( V_129 -> V_136 != 4 ) {
F_63 ( L_108 ) ;
return - V_68 ;
}
if ( V_455 & 0x1 ) {
T_2 V_86 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_109 ) ;
return - V_68 ;
}
V_86 = F_42 ( V_53 , V_105 + 1 ) ;
V_86 += ( ( T_2 ) ( F_42 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_170 -> V_223 ) ) {
F_63 ( L_110 ,
V_86 + 4 , F_23 ( V_170 -> V_223 ) ) ;
return - V_68 ;
}
V_86 += V_170 -> V_208 . V_209 ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_98 ( V_86 ) & 0xff ;
} else {
V_139 = F_42 ( V_53 , V_105 + 1 ) << 2 ;
if ( ! F_96 ( V_53 , V_139 , V_105 + 1 ) )
return - V_68 ;
}
if ( V_455 & 0x2 ) {
T_2 V_86 ;
V_87 = F_71 ( V_53 , & V_170 ) ;
if ( V_87 ) {
F_63 ( L_111 ) ;
return - V_68 ;
}
V_86 = F_42 ( V_53 , V_105 + 3 ) ;
V_86 += ( ( T_2 ) ( F_42 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_170 -> V_223 ) ) {
F_63 ( L_112 ,
V_86 + 4 , F_23 ( V_170 -> V_223 ) ) ;
return - V_68 ;
}
V_86 += V_170 -> V_208 . V_209 ;
V_89 [ V_105 + 3 ] = V_86 ;
V_89 [ V_105 + 4 ] = F_98 ( V_86 ) & 0xff ;
} else {
V_139 = F_42 ( V_53 , V_105 + 3 ) << 2 ;
if ( ! F_96 ( V_53 , V_139 , V_105 + 3 ) )
return - V_68 ;
}
break;
case V_148 :
break;
default:
F_63 ( L_113 , V_129 -> V_141 ) ;
return - V_68 ;
}
return 0 ;
}
int F_106 ( struct V_52 * V_53 )
{
struct V_128 V_129 ;
struct V_12 * V_13 ;
T_1 V_91 ;
int V_87 ;
if ( V_53 -> V_13 == NULL ) {
V_13 = F_107 ( sizeof( * V_13 ) , V_506 ) ;
if ( V_13 == NULL )
return - V_507 ;
F_3 ( V_13 ) ;
if ( V_53 -> V_162 -> V_114 >= V_173 )
V_91 = V_53 -> V_162 -> V_508 . V_509 . V_510 ;
else
V_91 = V_53 -> V_162 -> V_508 . V_511 . V_510 ;
switch ( V_91 & 0xf ) {
case 0 :
V_13 -> V_76 = 1 ;
break;
case 1 :
default:
V_13 -> V_76 = 2 ;
break;
case 2 :
V_13 -> V_76 = 4 ;
break;
case 3 :
V_13 -> V_76 = 8 ;
break;
}
switch ( ( V_91 & 0xf0 ) >> 4 ) {
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
switch ( ( V_91 & 0xf00 ) >> 8 ) {
case 0 :
V_13 -> V_65 = 256 ;
break;
case 1 :
default:
V_13 -> V_65 = 512 ;
break;
}
switch ( ( V_91 & 0xf000 ) >> 12 ) {
case 0 :
V_13 -> V_512 = 1 ;
break;
case 1 :
default:
V_13 -> V_512 = 2 ;
break;
case 2 :
V_13 -> V_512 = 4 ;
break;
}
V_53 -> V_13 = V_13 ;
}
do {
V_87 = F_66 ( V_53 , & V_129 , V_53 -> V_105 ) ;
if ( V_87 ) {
F_108 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return V_87 ;
}
V_53 -> V_105 += V_129 . V_136 + 2 ;
switch ( V_129 . type ) {
case V_138 :
V_87 = F_79 ( V_53 , & V_129 ) ;
break;
case V_142 :
break;
case V_140 :
V_87 = F_97 ( V_53 , & V_129 ) ;
break;
default:
F_63 ( L_114 , V_129 . type ) ;
F_108 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return - V_68 ;
}
if ( V_87 ) {
F_108 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return V_87 ;
}
} while ( V_53 -> V_105 < V_53 -> V_132 [ V_53 -> V_133 ] . V_135 );
#if 0
for (r = 0; r < p->ib.length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib.ptr[r]);
mdelay(1);
}
#endif
F_108 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return 0 ;
}
static bool F_109 ( T_1 V_139 )
{
if ( V_139 >= 0x28000 )
return true ;
switch ( V_139 ) {
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
case V_533 :
case V_534 :
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_369 :
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
case V_574 :
case V_575 :
case V_576 :
case V_577 :
case V_578 :
case V_579 :
case V_580 :
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
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_581 :
case V_582 :
return true ;
default:
return false ;
}
}
static int F_110 ( struct V_583 * V_162 ,
T_1 * V_89 , struct V_128 * V_129 )
{
T_1 V_105 = V_129 -> V_105 + 1 ;
T_1 V_455 = V_89 [ V_105 ] ;
T_1 V_453 , V_454 , V_139 , V_14 ;
switch ( V_129 -> V_141 ) {
case V_148 :
case V_584 :
case V_461 :
case V_585 :
case V_471 :
case V_472 :
case V_586 :
case V_456 :
case V_587 :
case V_588 :
case V_589 :
case V_590 :
case V_463 :
case V_465 :
case V_458 :
case V_469 :
case V_459 :
case V_464 :
case V_466 :
case V_468 :
case V_460 :
case V_467 :
case V_504 :
case V_470 :
case V_591 :
case V_592 :
case V_159 :
case V_593 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_480 :
case V_492 :
case V_495 :
case V_483 :
case V_501 :
case V_498 :
case V_594 :
case V_595 :
case V_596 :
case V_462 :
break;
case V_597 :
if ( V_455 & 0x100 ) {
V_139 = V_89 [ V_105 + 5 ] * 4 ;
if ( ! F_109 ( V_139 ) )
return - V_68 ;
}
break;
case V_505 :
if ( V_455 & 0x2 ) {
V_139 = V_89 [ V_105 + 3 ] * 4 ;
if ( ! F_109 ( V_139 ) )
return - V_68 ;
}
break;
case V_477 :
V_453 = ( V_455 << 2 ) + V_478 ;
V_454 = 4 * V_129 -> V_136 + V_453 - 4 ;
if ( ( V_453 < V_478 ) ||
( V_453 >= V_479 ) ||
( V_454 >= V_479 ) ) {
F_63 ( L_93 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_129 -> V_136 ; V_14 ++ ) {
V_139 = V_453 + ( 4 * V_14 ) ;
if ( ! F_109 ( V_139 ) )
return - V_68 ;
}
break;
default:
return - V_68 ;
}
return 0 ;
}
int F_111 ( struct V_583 * V_162 , struct V_598 * V_89 )
{
int V_599 = 0 ;
T_1 V_105 = 0 ;
struct V_128 V_129 ;
do {
V_129 . V_105 = V_105 ;
V_129 . type = F_67 ( V_89 -> V_90 [ V_105 ] ) ;
V_129 . V_136 = F_68 ( V_89 -> V_90 [ V_105 ] ) ;
V_129 . V_137 = 0 ;
switch ( V_129 . type ) {
case V_138 :
F_95 ( V_162 -> V_66 , L_115 ) ;
V_599 = - V_68 ;
break;
case V_142 :
V_105 += 1 ;
break;
case V_140 :
V_129 . V_141 = F_70 ( V_89 -> V_90 [ V_105 ] ) ;
V_599 = F_110 ( V_162 , V_89 -> V_90 , & V_129 ) ;
V_105 += V_129 . V_136 + 2 ;
break;
default:
F_95 ( V_162 -> V_66 , L_114 , V_129 . type ) ;
V_599 = - V_68 ;
break;
}
if ( V_599 )
break;
} while ( V_105 < V_89 -> V_135 );
return V_599 ;
}
