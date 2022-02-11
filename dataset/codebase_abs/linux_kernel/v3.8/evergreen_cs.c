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
V_73 = ( V_63 / 8 ) * ( V_64 / 8 ) * V_69 ;
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
V_58 = V_58 >> 3 ;
V_59 = V_59 >> 3 ;
V_93 = F_27 ( V_58 * V_59 * 4 , V_13 -> V_76 * ( 2 << 10 ) ) ;
V_93 += V_13 -> V_45 ;
if ( V_93 > F_23 ( V_13 -> V_44 ) ) {
F_7 ( V_53 -> V_66 , L_20 ,
V_67 , __LINE__ , F_23 ( V_13 -> V_44 ) ,
V_93 , V_58 , V_59 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_28 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_54 V_55 ;
unsigned V_83 , V_84 , V_85 ;
unsigned long V_86 ;
int V_87 ;
V_85 = F_29 ( V_13 -> V_30 ) + 1 ;
V_83 = F_30 ( V_13 -> V_31 ) ;
V_84 = V_13 -> V_29 ;
V_55 . V_58 = ( V_83 + 1 ) * 8 ;
V_55 . V_59 = ( ( V_84 + 1 ) * 64 ) / V_55 . V_58 ;
V_55 . V_80 = F_31 ( V_13 -> V_33 ) ;
V_55 . V_79 = F_32 ( V_13 -> V_38 ) ;
V_55 . V_74 = F_33 ( V_13 -> V_38 ) ;
V_55 . V_7 = F_34 ( V_13 -> V_33 ) ;
V_55 . V_75 = F_35 ( V_13 -> V_33 ) ;
V_55 . V_78 = F_36 ( V_13 -> V_33 ) ;
V_55 . V_77 = F_37 ( V_13 -> V_33 ) ;
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
if ( F_38 ( V_13 -> V_33 ) ) {
V_87 = F_24 ( V_53 , V_55 . V_58 , V_55 . V_59 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_39 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_54 V_55 ;
unsigned V_83 , V_84 , V_85 ;
unsigned long V_86 ;
int V_87 ;
V_85 = F_29 ( V_13 -> V_30 ) + 1 ;
V_83 = F_30 ( V_13 -> V_31 ) ;
V_84 = V_13 -> V_29 ;
V_55 . V_58 = ( V_83 + 1 ) * 8 ;
V_55 . V_59 = ( ( V_84 + 1 ) * 64 ) / V_55 . V_58 ;
V_55 . V_80 = F_31 ( V_13 -> V_33 ) ;
V_55 . V_79 = F_40 ( V_13 -> V_33 ) ;
V_55 . V_74 = F_41 ( V_13 -> V_33 ) ;
V_55 . V_7 = F_34 ( V_13 -> V_33 ) ;
V_55 . V_75 = F_35 ( V_13 -> V_33 ) ;
V_55 . V_78 = F_36 ( V_13 -> V_33 ) ;
V_55 . V_77 = F_37 ( V_13 -> V_33 ) ;
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
if ( F_38 ( V_13 -> V_33 ) ) {
V_87 = F_24 ( V_53 , V_55 . V_58 , V_55 . V_59 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_42 ( struct V_52 * V_53 ,
struct V_102 * V_103 ,
struct V_102 * V_104 ,
unsigned V_105 )
{
struct V_54 V_55 ;
unsigned long V_106 , V_107 ;
unsigned V_108 , V_109 , V_85 , V_110 , V_111 , V_112 , V_14 ;
T_1 V_113 [ 8 ] ;
int V_87 ;
V_113 [ 0 ] = F_43 ( V_53 , V_105 + 0 ) ;
V_113 [ 1 ] = F_43 ( V_53 , V_105 + 1 ) ;
V_113 [ 2 ] = F_43 ( V_53 , V_105 + 2 ) ;
V_113 [ 3 ] = F_43 ( V_53 , V_105 + 3 ) ;
V_113 [ 4 ] = F_43 ( V_53 , V_105 + 4 ) ;
V_113 [ 5 ] = F_43 ( V_53 , V_105 + 5 ) ;
V_113 [ 6 ] = F_43 ( V_53 , V_105 + 6 ) ;
V_113 [ 7 ] = F_43 ( V_53 , V_105 + 7 ) ;
V_108 = F_44 ( V_113 [ 0 ] ) ;
V_109 = F_45 ( V_113 [ 5 ] ) ;
V_85 = F_46 ( V_113 [ 5 ] ) + 1 ;
V_110 = F_47 ( V_113 [ 0 ] ) + 1 ;
V_111 = F_48 ( V_113 [ 1 ] ) + 1 ;
V_112 = F_49 ( V_113 [ 1 ] ) + 1 ;
V_55 . V_79 = F_50 ( V_113 [ 7 ] ) ;
V_55 . V_58 = ( F_51 ( V_113 [ 0 ] ) + 1 ) * 8 ;
V_55 . V_58 = F_52 ( V_55 . V_79 , V_55 . V_58 ) ;
V_55 . V_59 = F_53 ( V_55 . V_79 , V_111 ) ;
V_55 . V_80 = F_54 ( V_113 [ 1 ] ) ;
V_55 . V_74 = F_55 ( V_113 [ 6 ] ) ;
V_55 . V_7 = F_56 ( V_113 [ 7 ] ) ;
V_55 . V_75 = F_57 ( V_113 [ 7 ] ) ;
V_55 . V_78 = F_58 ( V_113 [ 7 ] ) ;
V_55 . V_77 = F_59 ( V_113 [ 7 ] ) ;
V_55 . V_61 = 1 ;
V_106 = V_113 [ 2 ] << 8 ;
V_107 = V_113 [ 3 ] << 8 ;
if ( ! F_60 ( V_55 . V_79 , V_53 -> V_114 ) ) {
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
break;
case V_120 :
case V_121 :
V_55 . V_61 = 1 << V_109 ;
V_109 = 0 ;
V_112 = 1 ;
break;
case V_122 :
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
V_55 . V_59 = F_61 ( V_55 . V_59 , V_55 . V_64 ) ;
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
if ( V_108 == V_123 ) {
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
if ( ! V_104 ) {
if ( V_109 ) {
F_7 ( V_53 -> V_66 , L_42 ,
V_67 , __LINE__ ) ;
return - V_68 ;
} else {
return 0 ;
}
}
for ( V_14 = 1 ; V_14 <= V_109 ; V_14 ++ ) {
unsigned V_124 , V_125 , V_126 ;
V_124 = F_62 ( V_110 , V_14 ) ;
V_125 = F_62 ( V_111 , V_14 ) ;
V_126 = F_62 ( V_112 , V_14 ) ;
V_55 . V_58 = F_52 ( V_55 . V_79 , V_124 ) ;
V_55 . V_59 = F_53 ( V_55 . V_79 , V_125 ) ;
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
F_7 ( V_53 -> V_66 , L_43 ,
V_67 , __LINE__ , V_55 . V_80 ) ;
return - V_68 ;
}
V_55 . V_58 = F_61 ( V_55 . V_58 , V_55 . V_63 ) ;
V_55 . V_59 = F_61 ( V_55 . V_59 , V_55 . V_64 ) ;
V_87 = F_10 ( V_53 , & V_55 , L_44 ) ;
if ( V_87 ) {
return V_87 ;
}
if ( V_108 == V_123 ) {
V_107 += V_55 . V_57 * V_126 ;
} else {
V_107 += V_55 . V_57 * V_85 ;
}
if ( V_107 > F_23 ( V_104 ) ) {
F_7 ( V_53 -> V_66 , L_45
L_46
L_47 ,
V_67 , __LINE__ , V_14 , V_55 . V_57 ,
( unsigned long ) V_113 [ 3 ] << 8 , V_107 , V_85 ,
V_126 , F_23 ( V_104 ) ,
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
static int F_63 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
unsigned V_91 , V_14 ;
int V_87 ;
unsigned V_127 = 0 ;
if ( V_13 -> V_50 && V_13 -> V_128 ) {
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
if ( V_13 -> V_128 & ( 1 << V_14 ) ) {
V_127 |= ( V_13 -> V_129 >> ( V_14 * 4 ) ) & 0xf ;
}
}
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
if ( V_127 & ( 1 << V_14 ) ) {
if ( V_13 -> V_48 [ V_14 ] ) {
T_2 V_86 = ( T_2 ) V_13 -> V_49 [ V_14 ] +
( T_2 ) V_13 -> V_47 [ V_14 ] ;
if ( V_86 > F_23 ( V_13 -> V_48 [ V_14 ] ) ) {
F_64 ( L_48 ,
V_14 , V_86 ,
F_23 ( V_13 -> V_48 [ V_14 ] ) ) ;
return - V_68 ;
}
} else {
F_7 ( V_53 -> V_66 , L_49 , V_14 ) ;
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
F_7 ( V_53 -> V_66 , L_50 ,
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
if ( F_32 ( V_13 -> V_38 ) != V_130 &&
F_65 ( V_13 -> V_32 ) ) {
V_87 = F_28 ( V_53 ) ;
if ( V_87 )
return V_87 ;
}
if ( F_40 ( V_13 -> V_33 ) != V_131 &&
F_66 ( V_13 -> V_32 ) ) {
V_87 = F_39 ( V_53 ) ;
if ( V_87 )
return V_87 ;
}
V_13 -> V_43 = false ;
}
return 0 ;
}
static int F_67 ( struct V_52 * V_53 ,
struct V_132 * V_133 ,
unsigned V_105 )
{
struct V_134 * V_135 = & V_53 -> V_136 [ V_53 -> V_137 ] ;
T_3 V_138 ;
if ( V_105 >= V_135 -> V_139 ) {
F_64 ( L_51 ,
V_105 , V_135 -> V_139 ) ;
return - V_68 ;
}
V_138 = F_43 ( V_53 , V_105 ) ;
V_133 -> V_105 = V_105 ;
V_133 -> type = F_68 ( V_138 ) ;
V_133 -> V_140 = F_69 ( V_138 ) ;
V_133 -> V_141 = 0 ;
switch ( V_133 -> type ) {
case V_142 :
V_133 -> V_143 = F_70 ( V_138 ) ;
break;
case V_144 :
V_133 -> V_145 = F_71 ( V_138 ) ;
break;
case V_146 :
V_133 -> V_140 = - 1 ;
break;
default:
F_64 ( L_52 , V_133 -> type , V_105 ) ;
return - V_68 ;
}
if ( ( V_133 -> V_140 + 1 + V_133 -> V_105 ) >= V_135 -> V_139 ) {
F_64 ( L_53 ,
V_133 -> V_105 , V_133 -> type , V_133 -> V_140 , V_135 -> V_139 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_72 ( struct V_52 * V_53 ,
struct V_147 * * V_148 )
{
struct V_134 * V_149 ;
struct V_132 V_150 ;
unsigned V_105 ;
int V_87 ;
if ( V_53 -> V_151 == - 1 ) {
F_64 ( L_54 ) ;
return - V_68 ;
}
* V_148 = NULL ;
V_149 = & V_53 -> V_136 [ V_53 -> V_151 ] ;
V_87 = F_67 ( V_53 , & V_150 , V_53 -> V_105 ) ;
if ( V_87 ) {
return V_87 ;
}
V_53 -> V_105 += V_150 . V_140 + 2 ;
if ( V_150 . type != V_144 || V_150 . V_145 != V_152 ) {
F_64 ( L_55 ,
V_150 . V_105 ) ;
return - V_68 ;
}
V_105 = F_43 ( V_53 , V_150 . V_105 + 1 ) ;
if ( V_105 >= V_149 -> V_139 ) {
F_64 ( L_56 ,
V_105 , V_149 -> V_139 ) ;
return - V_68 ;
}
* V_148 = V_53 -> V_153 [ ( V_105 / 4 ) ] ;
return 0 ;
}
static bool F_73 ( struct V_52 * V_53 )
{
struct V_132 V_150 ;
int V_87 ;
V_87 = F_67 ( V_53 , & V_150 , V_53 -> V_105 ) ;
if ( V_87 ) {
return false ;
}
if ( V_150 . type != V_144 || V_150 . V_145 != V_152 ) {
return false ;
}
return true ;
}
static int F_74 ( struct V_52 * V_53 )
{
struct V_154 * V_155 ;
struct V_156 * V_157 ;
struct V_158 * V_158 ;
struct V_132 V_150 , V_159 ;
int V_160 ;
int V_87 ;
T_3 V_138 , V_161 , V_143 , V_162 ;
volatile T_3 * V_89 ;
V_89 = V_53 -> V_89 . V_90 ;
V_87 = F_67 ( V_53 , & V_159 , V_53 -> V_105 ) ;
if ( V_87 )
return V_87 ;
if ( V_159 . type != V_144 ||
V_159 . V_145 != V_163 ) {
F_64 ( L_57 ) ;
return - V_68 ;
}
V_162 = F_43 ( V_53 , V_159 . V_105 + 1 ) ;
if ( V_162 & 0x10 ) {
F_64 ( L_58 ) ;
return - V_68 ;
}
if ( ( V_162 & 0x7 ) != 0x3 ) {
F_64 ( L_59 ) ;
return - V_68 ;
}
if ( ( F_43 ( V_53 , V_159 . V_105 + 2 ) << 2 ) != V_164 ) {
F_64 ( L_60 ) ;
return - V_68 ;
}
if ( F_43 ( V_53 , V_159 . V_105 + 5 ) != V_165 ) {
F_64 ( L_61 ) ;
return - V_68 ;
}
V_87 = F_67 ( V_53 , & V_150 , V_53 -> V_105 + V_159 . V_140 + 2 ) ;
if ( V_87 )
return V_87 ;
V_161 = V_53 -> V_105 - 2 ;
V_53 -> V_105 += V_159 . V_140 + 2 ;
V_53 -> V_105 += V_150 . V_140 + 2 ;
V_138 = F_43 ( V_53 , V_161 ) ;
V_160 = F_43 ( V_53 , V_161 + 2 + 7 + 1 ) ;
V_143 = F_70 ( V_138 ) ;
V_155 = F_75 ( V_53 -> V_166 -> V_167 , V_160 , V_168 ) ;
if ( ! V_155 ) {
F_64 ( L_62 , V_160 ) ;
return - V_68 ;
}
V_157 = F_76 ( V_155 ) ;
V_158 = F_77 ( V_157 ) ;
V_160 = V_158 -> V_160 ;
if ( ! V_157 -> V_169 ) {
V_89 [ V_161 + 2 ] = F_78 ( 0 ) ;
V_89 [ V_161 + 3 ] = F_78 ( 0 ) ;
V_89 [ V_161 + 4 ] = F_78 ( 0 ) ;
V_89 [ V_161 + 5 ] = F_78 ( 0 ) ;
V_89 [ V_161 + 6 ] = F_78 ( 0 ) ;
V_89 [ V_161 + 7 ] = F_78 ( 0 ) ;
V_89 [ V_161 + 8 ] = F_78 ( 0 ) ;
} else {
switch ( V_143 ) {
case V_170 :
V_138 &= ~ V_171 ;
V_138 |= ( V_170 + V_158 -> V_172 ) >> 2 ;
V_89 [ V_161 ] = V_138 ;
V_89 [ V_161 + 4 ] = ( V_164 + V_158 -> V_172 ) >> 2 ;
break;
default:
F_64 ( L_63 ) ;
return - V_68 ;
}
}
return 0 ;
}
static int F_79 ( struct V_52 * V_53 ,
struct V_132 * V_133 ,
unsigned V_105 , unsigned V_143 )
{
int V_87 ;
switch ( V_143 ) {
case V_170 :
V_87 = F_74 ( V_53 ) ;
if ( V_87 ) {
F_64 ( L_64 ,
V_105 , V_143 ) ;
return V_87 ;
}
break;
default:
F_80 ( V_173 L_65 ,
V_143 , V_105 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_81 ( struct V_52 * V_53 ,
struct V_132 * V_133 )
{
unsigned V_143 , V_14 ;
unsigned V_105 ;
int V_87 ;
V_105 = V_133 -> V_105 + 1 ;
V_143 = V_133 -> V_143 ;
for ( V_14 = 0 ; V_14 <= V_133 -> V_140 ; V_14 ++ , V_105 ++ , V_143 += 4 ) {
V_87 = F_79 ( V_53 , V_133 , V_105 , V_143 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_82 ( struct V_52 * V_53 , T_1 V_143 , T_1 V_105 )
{
struct V_12 * V_13 = (struct V_12 * ) V_53 -> V_13 ;
struct V_147 * V_174 ;
T_1 V_175 ;
T_1 V_176 , V_14 , V_91 , * V_89 ;
int V_87 ;
if ( V_53 -> V_166 -> V_114 >= V_177 )
V_175 = F_83 ( V_178 ) ;
else
V_175 = F_83 ( V_179 ) ;
V_14 = ( V_143 >> 7 ) ;
if ( V_14 >= V_175 ) {
F_7 ( V_53 -> V_66 , L_66 , V_143 , V_105 ) ;
return - V_68 ;
}
V_176 = 1 << ( ( V_143 >> 2 ) & 31 ) ;
if ( V_53 -> V_166 -> V_114 >= V_177 ) {
if ( ! ( V_178 [ V_14 ] & V_176 ) )
return 0 ;
} else {
if ( ! ( V_179 [ V_14 ] & V_176 ) )
return 0 ;
}
V_89 = V_53 -> V_89 . V_90 ;
switch ( V_143 ) {
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
break;
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
break;
case V_214 :
V_13 -> V_32 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_215 :
if ( V_53 -> V_166 -> V_114 < V_177 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
break;
case V_216 :
if ( V_53 -> V_166 -> V_114 < V_177 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
break;
case V_217 :
V_13 -> V_33 = F_43 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_218 & V_219 ) ) {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] &= ~ F_84 ( 0xf ) ;
V_13 -> V_33 &= ~ F_84 ( 0xf ) ;
V_89 [ V_105 ] |= F_84 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
V_13 -> V_33 |= F_84 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
if ( V_174 -> V_212 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_220 , V_221 ;
F_85 ( V_174 -> V_212 . V_1 ,
& V_75 , & V_78 , & V_220 ,
& V_221 ) ;
V_89 [ V_105 ] |= F_86 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_87 ( V_221 ) |
F_88 ( V_75 ) |
F_89 ( V_78 ) |
F_90 ( V_220 ) ;
}
}
V_13 -> V_43 = true ;
break;
case V_222 :
V_13 -> V_38 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_223 :
V_13 -> V_30 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_224 :
V_13 -> V_31 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_225 :
V_13 -> V_29 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_226 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_13 -> V_34 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_36 = V_174 -> V_227 ;
V_13 -> V_43 = true ;
break;
case V_228 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_13 -> V_35 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_37 = V_174 -> V_227 ;
V_13 -> V_43 = true ;
break;
case V_229 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_13 -> V_39 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_41 = V_174 -> V_227 ;
V_13 -> V_43 = true ;
break;
case V_230 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_13 -> V_40 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_42 = V_174 -> V_227 ;
V_13 -> V_43 = true ;
break;
case V_231 :
V_13 -> V_128 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_50 = true ;
break;
case V_232 :
V_13 -> V_129 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_50 = true ;
break;
case V_233 :
case V_234 :
case V_235 :
case V_236 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_91 = ( V_143 - V_233 ) / 16 ;
V_13 -> V_49 [ V_91 ] = F_43 ( V_53 , V_105 ) << 8 ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_48 [ V_91 ] = V_174 -> V_227 ;
V_13 -> V_50 = true ;
break;
case V_237 :
case V_238 :
case V_239 :
case V_240 :
V_91 = ( V_143 - V_237 ) / 16 ;
V_13 -> V_47 [ V_91 ] = F_43 ( V_53 , V_105 ) * 4 ;
V_13 -> V_50 = true ;
break;
case V_241 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_69
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
case V_242 :
V_13 -> V_26 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_243 :
V_13 -> V_27 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_244 :
if ( V_53 -> V_166 -> V_114 >= V_177 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 ) & V_245 ;
V_13 -> V_61 = 1 << V_91 ;
break;
case V_246 :
if ( V_53 -> V_166 -> V_114 < V_177 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 ) & V_247 ;
V_13 -> V_61 = 1 << V_91 ;
break;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_91 = ( V_143 - V_248 ) / 0x3c ;
V_13 -> V_22 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
V_91 = ( ( V_143 - V_256 ) / 0x1c ) + 8 ;
V_13 -> V_22 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_91 = ( V_143 - V_260 ) / 0x3c ;
V_13 -> V_21 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_218 & V_219 ) ) {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] |= F_91 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
V_13 -> V_21 [ V_91 ] |= F_91 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
}
V_13 -> V_28 = true ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
V_91 = ( ( V_143 - V_268 ) / 0x1c ) + 8 ;
V_13 -> V_21 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_218 & V_219 ) ) {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] |= F_91 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
V_13 -> V_21 [ V_91 ] |= F_91 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
}
V_13 -> V_28 = true ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
V_91 = ( V_143 - V_272 ) / 0x3c ;
V_13 -> V_23 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_280 :
case V_281 :
case V_282 :
case V_283 :
V_91 = ( ( V_143 - V_280 ) / 0x1c ) + 8 ;
V_13 -> V_23 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
V_91 = ( V_143 - V_284 ) / 0x3c ;
V_13 -> V_24 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_25 [ V_91 ] = V_105 ;
V_13 -> V_28 = true ;
break;
case V_292 :
case V_293 :
case V_294 :
case V_295 :
V_91 = ( ( V_143 - V_292 ) / 0x1c ) + 8 ;
V_13 -> V_24 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_25 [ V_91 ] = V_105 ;
V_13 -> V_28 = true ;
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_218 & V_219 ) ) {
if ( V_174 -> V_212 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_220 , V_221 ;
F_85 ( V_174 -> V_212 . V_1 ,
& V_75 , & V_78 , & V_220 ,
& V_221 ) ;
V_89 [ V_105 ] |= F_92 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_93 ( V_221 ) |
F_94 ( V_75 ) |
F_95 ( V_78 ) |
F_96 ( V_220 ) ;
}
}
V_91 = ( ( V_143 - V_296 ) / 0x3c ) ;
V_13 -> V_88 [ V_91 ] = V_89 [ V_105 ] ;
V_13 -> V_28 = true ;
break;
case V_304 :
case V_305 :
case V_306 :
case V_307 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_218 & V_219 ) ) {
if ( V_174 -> V_212 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_220 , V_221 ;
F_85 ( V_174 -> V_212 . V_1 ,
& V_75 , & V_78 , & V_220 ,
& V_221 ) ;
V_89 [ V_105 ] |= F_92 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_93 ( V_221 ) |
F_94 ( V_75 ) |
F_95 ( V_78 ) |
F_96 ( V_220 ) ;
}
}
V_91 = ( ( V_143 - V_304 ) / 0x1c ) + 8 ;
V_13 -> V_88 [ V_91 ] = V_89 [ V_105 ] ;
V_13 -> V_28 = true ;
break;
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
V_91 = ( V_143 - V_308 ) / 0x3c ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_97 ( V_53 -> V_66 , L_70 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_15 [ V_91 ] = V_174 -> V_227 ;
break;
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
V_91 = ( V_143 - V_316 ) / 0x3c ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_97 ( V_53 -> V_66 , L_70 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_16 [ V_91 ] = V_174 -> V_227 ;
break;
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
V_91 = ( V_143 - V_324 ) / 0x3c ;
V_13 -> V_18 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
break;
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
V_91 = ( V_143 - V_332 ) / 0x3c ;
V_13 -> V_17 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
break;
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_91 = ( V_143 - V_340 ) / 0x3c ;
V_13 -> V_20 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_91 ] = V_174 -> V_227 ;
V_13 -> V_28 = true ;
break;
case V_348 :
case V_349 :
case V_350 :
case V_351 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_91 = ( ( V_143 - V_348 ) / 0x1c ) + 8 ;
V_13 -> V_20 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_91 ] = V_174 -> V_227 ;
V_13 -> V_28 = true ;
break;
case V_352 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_13 -> V_45 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_13 -> V_44 = V_174 -> V_227 ;
V_13 -> V_43 = true ;
break;
case V_353 :
V_13 -> V_46 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] |= 3 ;
V_13 -> V_43 = true ;
break;
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
case V_450 :
case V_451 :
case V_452 :
case V_453 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
break;
case V_454 :
if ( V_53 -> V_166 -> V_114 >= V_177 ) {
F_7 ( V_53 -> V_66 , L_71
L_68 , V_143 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_71
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
break;
case V_455 :
if ( V_53 -> V_166 -> V_114 < V_177 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_67
L_68 , V_143 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
break;
case V_456 :
V_13 -> V_51 = ( F_43 ( V_53 , V_105 ) & 0x1 ) != 0 ;
break;
default:
F_7 ( V_53 -> V_66 , L_66 , V_143 , V_105 ) ;
return - V_68 ;
}
return 0 ;
}
static bool F_98 ( struct V_52 * V_53 , T_1 V_143 , T_1 V_105 )
{
T_1 V_175 , V_176 , V_14 ;
if ( V_53 -> V_166 -> V_114 >= V_177 )
V_175 = F_83 ( V_178 ) ;
else
V_175 = F_83 ( V_179 ) ;
V_14 = ( V_143 >> 7 ) ;
if ( V_14 >= V_175 ) {
F_7 ( V_53 -> V_66 , L_66 , V_143 , V_105 ) ;
return false ;
}
V_176 = 1 << ( ( V_143 >> 2 ) & 31 ) ;
if ( V_53 -> V_166 -> V_114 >= V_177 ) {
if ( ! ( V_178 [ V_14 ] & V_176 ) )
return true ;
} else {
if ( ! ( V_179 [ V_14 ] & V_176 ) )
return true ;
}
F_7 ( V_53 -> V_66 , L_66 , V_143 , V_105 ) ;
return false ;
}
static int F_99 ( struct V_52 * V_53 ,
struct V_132 * V_133 )
{
struct V_147 * V_174 ;
struct V_12 * V_13 ;
volatile T_1 * V_89 ;
unsigned V_105 ;
unsigned V_14 ;
unsigned V_457 , V_458 , V_143 ;
int V_87 ;
T_1 V_459 ;
V_13 = (struct V_12 * ) V_53 -> V_13 ;
V_89 = V_53 -> V_89 . V_90 ;
V_105 = V_133 -> V_105 + 1 ;
V_459 = F_43 ( V_53 , V_105 ) ;
switch ( V_133 -> V_145 ) {
case V_460 :
{
int V_461 ;
int V_91 ;
T_4 V_86 ;
if ( V_133 -> V_140 != 1 ) {
F_64 ( L_72 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 + 1 ) ;
V_461 = ( V_91 >> 16 ) & 0x7 ;
if ( V_461 == 0 )
return 0 ;
if ( V_461 > 2 ) {
F_64 ( L_73 , V_461 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_72 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
( V_459 & 0xfffffff0 ) +
( ( T_2 ) ( V_91 & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = ( V_91 & 0xffffff00 ) | ( F_100 ( V_86 ) & 0xff ) ;
}
break;
case V_462 :
if ( V_133 -> V_140 != 1 ) {
F_64 ( L_74 ) ;
return - V_68 ;
}
break;
case V_463 :
case V_464 :
case V_465 :
if ( V_133 -> V_140 ) {
F_64 ( L_75 ) ;
return - V_68 ;
}
break;
case V_466 :
if ( V_53 -> V_166 -> V_114 < V_177 ) {
F_64 ( L_76 ) ;
return - V_68 ;
}
if ( V_133 -> V_140 ) {
F_64 ( L_75 ) ;
return - V_68 ;
}
break;
case V_467 :
{
T_4 V_86 ;
if ( V_133 -> V_140 != 1 ) {
F_64 ( L_77 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_77 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
V_459 +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_100 ( V_86 ) & 0xff ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_468 :
{
T_4 V_86 ;
if ( V_133 -> V_140 != 3 ) {
F_64 ( L_79 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_79 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
V_459 +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_100 ( V_86 ) & 0xff ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_469 :
{
T_4 V_86 ;
if ( V_133 -> V_140 != 4 ) {
F_64 ( L_80 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_80 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
F_43 ( V_53 , V_105 + 1 ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_100 ( V_86 ) & 0xff ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_470 :
if ( V_133 -> V_140 != 1 ) {
F_64 ( L_81 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_82 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_471 :
if ( V_133 -> V_140 != 2 ) {
F_64 ( L_83 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_82 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_472 :
if ( V_133 -> V_140 < 2 ) {
F_64 ( L_84 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_473 :
if ( V_133 -> V_140 != 2 ) {
F_64 ( L_85 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_474 :
if ( V_133 -> V_140 != 3 ) {
F_64 ( L_86 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_475 :
if ( V_133 -> V_140 != 3 ) {
F_64 ( L_87 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_82 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_476 :
if ( V_133 -> V_140 != 1 ) {
F_64 ( L_88 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_88 ) ;
return - V_68 ;
}
V_89 [ V_105 + 0 ] = V_459 + ( T_1 ) ( V_174 -> V_212 . V_213 & 0xffffffff ) ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_78 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_163 :
if ( V_133 -> V_140 != 5 ) {
F_64 ( L_89 ) ;
return - V_68 ;
}
if ( V_459 & 0x10 ) {
T_4 V_86 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_89 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = ( V_89 [ V_105 + 1 ] & 0x3 ) | ( V_86 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] = F_100 ( V_86 ) & 0xff ;
}
break;
case V_477 :
{
T_1 V_478 , V_93 , V_479 ;
T_2 V_86 , V_91 ;
if ( V_133 -> V_140 != 4 ) {
F_64 ( L_90 ) ;
return - V_68 ;
}
V_478 = F_43 ( V_53 , V_105 + 4 ) ;
V_93 = V_478 & 0x1fffff ;
V_479 = F_43 ( V_53 , V_105 + 1 ) ;
if ( ( ( ( V_479 & 0x60000000 ) >> 29 ) != 0 ) ||
( ( ( V_479 & 0x00300000 ) >> 20 ) != 0 ) ||
( ( ( ( V_479 & 0x00300000 ) >> 20 ) == 0 ) &&
( V_478 & V_480 ) ) ||
( ( ( ( V_479 & 0x60000000 ) >> 29 ) == 0 ) &&
( V_478 & V_481 ) ) ) {
if ( V_93 % 4 ) {
F_64 ( L_91 ) ;
return - V_68 ;
}
}
if ( V_478 & V_481 ) {
if ( ( ( V_479 & 0x60000000 ) >> 29 ) != 1 ) {
F_64 ( L_92 ) ;
return - V_68 ;
}
} else {
if ( V_478 & V_482 ) {
F_64 ( L_93 ) ;
return - V_68 ;
}
if ( ( ( V_479 & 0x60000000 ) >> 29 ) == 0 ) {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_94 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_86 = V_174 -> V_212 . V_213 + V_91 ;
if ( ( V_91 + V_93 ) > F_23 ( V_174 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_95 ,
V_91 + V_93 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 ] = V_86 ;
V_89 [ V_105 + 1 ] = ( V_89 [ V_105 + 1 ] & 0xffffff00 ) | ( F_100 ( V_86 ) & 0xff ) ;
} else if ( ( ( V_479 & 0x60000000 ) >> 29 ) != 2 ) {
F_64 ( L_96 ) ;
return - V_68 ;
}
}
if ( V_478 & V_480 ) {
if ( ( ( V_479 & 0x00300000 ) >> 20 ) != 1 ) {
F_64 ( L_97 ) ;
return - V_68 ;
}
} else {
if ( V_478 & V_483 ) {
F_64 ( L_98 ) ;
return - V_68 ;
}
if ( ( ( V_479 & 0x00300000 ) >> 20 ) == 0 ) {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_99 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 + 2 ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 3 ) & 0xff ) << 32 ) ;
V_86 = V_174 -> V_212 . V_213 + V_91 ;
if ( ( V_91 + V_93 ) > F_23 ( V_174 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_100 ,
V_91 + V_93 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 2 ] = V_86 ;
V_89 [ V_105 + 3 ] = F_100 ( V_86 ) & 0xff ;
} else {
F_64 ( L_101 ) ;
return - V_68 ;
}
}
break;
}
case V_484 :
if ( V_133 -> V_140 != 3 ) {
F_64 ( L_102 ) ;
return - V_68 ;
}
if ( F_43 ( V_53 , V_105 + 1 ) != 0xffffffff ||
F_43 ( V_53 , V_105 + 2 ) != 0 ) {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_102 ) ;
return - V_68 ;
}
V_89 [ V_105 + 2 ] += ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
}
break;
case V_485 :
if ( V_133 -> V_140 != 2 && V_133 -> V_140 != 0 ) {
F_64 ( L_103 ) ;
return - V_68 ;
}
if ( V_133 -> V_140 ) {
T_4 V_86 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_103 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffff8 ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffff8 ;
V_89 [ V_105 + 2 ] = F_100 ( V_86 ) & 0xff ;
}
break;
case V_486 :
{
T_4 V_86 ;
if ( V_133 -> V_140 != 4 ) {
F_64 ( L_104 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_104 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffffc ;
V_89 [ V_105 + 2 ] = ( V_89 [ V_105 + 2 ] & 0xffffff00 ) | ( F_100 ( V_86 ) & 0xff ) ;
break;
}
case V_487 :
{
T_4 V_86 ;
if ( V_133 -> V_140 != 3 ) {
F_64 ( L_105 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_105 ) ;
return - V_68 ;
}
V_86 = V_174 -> V_212 . V_213 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffffc ;
V_89 [ V_105 + 2 ] = ( V_89 [ V_105 + 2 ] & 0xffffff00 ) | ( F_100 ( V_86 ) & 0xff ) ;
break;
}
case V_488 :
V_457 = ( V_459 << 2 ) + V_489 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_489 ) ||
( V_457 >= V_490 ) ||
( V_458 >= V_490 ) ) {
F_64 ( L_106 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_133 -> V_140 ; V_14 ++ ) {
V_143 = V_457 + ( 4 * V_14 ) ;
V_87 = F_82 ( V_53 , V_143 , V_105 + 1 + V_14 ) ;
if ( V_87 )
return V_87 ;
}
break;
case V_491 :
V_457 = ( V_459 << 2 ) + V_492 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_492 ) ||
( V_457 >= V_493 ) ||
( V_458 >= V_493 ) ) {
F_64 ( L_107 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_133 -> V_140 ; V_14 ++ ) {
V_143 = V_457 + ( 4 * V_14 ) ;
V_87 = F_82 ( V_53 , V_143 , V_105 + 1 + V_14 ) ;
if ( V_87 )
return V_87 ;
}
break;
case V_494 :
if ( V_133 -> V_140 % 8 ) {
F_64 ( L_108 ) ;
return - V_68 ;
}
V_457 = ( V_459 << 2 ) + V_495 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_495 ) ||
( V_457 >= V_496 ) ||
( V_458 >= V_496 ) ) {
F_64 ( L_108 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < ( V_133 -> V_140 / 8 ) ; V_14 ++ ) {
struct V_102 * V_103 , * V_104 ;
T_1 V_106 , V_107 ;
T_1 V_93 , V_86 , V_497 , V_498 ;
switch ( F_101 ( F_43 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 7 ) ) ) {
case V_499 :
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_109 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_218 & V_219 ) ) {
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 1 ] |=
F_102 ( F_1 ( V_174 -> V_212 . V_1 ) ) ;
if ( V_174 -> V_212 . V_1 & V_2 ) {
unsigned V_75 , V_78 , V_220 , V_221 ;
F_85 ( V_174 -> V_212 . V_1 ,
& V_75 , & V_78 , & V_220 ,
& V_221 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 6 ] |= F_103 ( V_221 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 7 ] |=
F_104 ( V_75 ) |
F_105 ( V_78 ) |
F_106 ( V_220 ) |
F_107 ( F_2 ( V_13 -> V_7 ) ) ;
}
}
V_103 = V_174 -> V_227 ;
V_106 = ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_498 = V_89 [ V_105 + 1 + ( V_14 * 8 ) + 0 ] & 0x7 ;
V_497 = V_89 [ V_105 + 1 + ( V_14 * 8 ) + 3 ] ;
if ( ( V_498 == V_500 || V_498 == V_501 ) &&
! V_497 &&
! F_73 ( V_53 ) ) {
V_107 = 0 ;
V_104 = NULL ;
} else {
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_109 ) ;
return - V_68 ;
}
V_107 = ( T_1 ) ( ( V_174 -> V_212 . V_213 >> 8 ) & 0xffffffff ) ;
V_104 = V_174 -> V_227 ;
}
V_87 = F_42 ( V_53 , V_103 , V_104 , V_105 + 1 + ( V_14 * 8 ) ) ;
if ( V_87 )
return V_87 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] += V_106 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 3 ] += V_107 ;
break;
case V_502 :
{
T_4 V_503 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_110 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 0 ) ;
V_93 = F_43 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 1 ) ;
if ( V_53 -> V_166 && ( V_93 + V_86 ) > F_23 ( V_174 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_111 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 1 ] = F_23 ( V_174 -> V_227 ) - V_86 ;
}
V_503 = V_174 -> V_212 . V_213 + V_86 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 0 ] = V_503 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] = ( V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] & 0xffffff00 ) |
( F_100 ( V_503 ) & 0xff ) ;
break;
}
case V_504 :
case V_505 :
default:
F_64 ( L_108 ) ;
return - V_68 ;
}
}
break;
case V_506 :
break;
case V_507 :
V_457 = ( V_459 << 2 ) + V_508 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_508 ) ||
( V_457 >= V_509 ) ||
( V_458 >= V_509 ) ) {
F_64 ( L_112 ) ;
return - V_68 ;
}
break;
case V_510 :
V_457 = ( V_459 << 2 ) + V_511 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_511 ) ||
( V_457 >= V_512 ) ||
( V_458 >= V_512 ) ) {
F_64 ( L_113 ) ;
return - V_68 ;
}
break;
case V_513 :
V_457 = ( V_459 << 2 ) + V_514 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_514 ) ||
( V_457 >= V_515 ) ||
( V_458 >= V_515 ) ) {
F_64 ( L_114 ) ;
return - V_68 ;
}
break;
case V_516 :
if ( V_133 -> V_140 % 3 ) {
F_64 ( L_115 ) ;
return - V_68 ;
}
V_457 = ( V_459 << 2 ) + V_517 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_517 ) ||
( V_457 >= V_518 ) ||
( V_458 >= V_518 ) ) {
F_64 ( L_115 ) ;
return - V_68 ;
}
break;
case V_519 :
if ( V_133 -> V_140 != 4 ) {
F_64 ( L_116 ) ;
return - V_68 ;
}
if ( V_459 & 0x1 ) {
T_2 V_86 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_117 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 ) ;
V_86 += ( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_174 -> V_227 ) ) {
F_64 ( L_118 ,
V_86 + 4 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_86 += V_174 -> V_212 . V_213 ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_100 ( V_86 ) & 0xff ;
}
if ( ( ( V_459 >> 1 ) & 0x3 ) == 2 ) {
T_2 V_86 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_119 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 3 ) ;
V_86 += ( ( T_2 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_174 -> V_227 ) ) {
F_64 ( L_120 ,
V_86 + 4 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_86 += V_174 -> V_212 . V_213 ;
V_89 [ V_105 + 3 ] = V_86 ;
V_89 [ V_105 + 4 ] = F_100 ( V_86 ) & 0xff ;
}
break;
case V_520 :
{
T_2 V_86 ;
if ( V_133 -> V_140 != 3 ) {
F_64 ( L_121 ) ;
return - V_68 ;
}
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_122 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 0 ) ;
V_86 += ( ( T_2 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) ) << 32UL ;
if ( V_86 & 0x7 ) {
F_64 ( L_123 ) ;
return - V_68 ;
}
if ( ( V_86 + 8 ) > F_23 ( V_174 -> V_227 ) ) {
F_64 ( L_124 ,
V_86 + 8 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_86 += V_174 -> V_212 . V_213 ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_100 ( V_86 ) & 0xff ;
break;
}
case V_521 :
if ( V_133 -> V_140 != 4 ) {
F_64 ( L_125 ) ;
return - V_68 ;
}
if ( V_459 & 0x1 ) {
T_2 V_86 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_126 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 ) ;
V_86 += ( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_174 -> V_227 ) ) {
F_64 ( L_127 ,
V_86 + 4 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_86 += V_174 -> V_212 . V_213 ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_100 ( V_86 ) & 0xff ;
} else {
V_143 = F_43 ( V_53 , V_105 + 1 ) << 2 ;
if ( ! F_98 ( V_53 , V_143 , V_105 + 1 ) )
return - V_68 ;
}
if ( V_459 & 0x2 ) {
T_2 V_86 ;
V_87 = F_72 ( V_53 , & V_174 ) ;
if ( V_87 ) {
F_64 ( L_128 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 3 ) ;
V_86 += ( ( T_2 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_174 -> V_227 ) ) {
F_64 ( L_129 ,
V_86 + 4 , F_23 ( V_174 -> V_227 ) ) ;
return - V_68 ;
}
V_86 += V_174 -> V_212 . V_213 ;
V_89 [ V_105 + 3 ] = V_86 ;
V_89 [ V_105 + 4 ] = F_100 ( V_86 ) & 0xff ;
} else {
V_143 = F_43 ( V_53 , V_105 + 3 ) << 2 ;
if ( ! F_98 ( V_53 , V_143 , V_105 + 3 ) )
return - V_68 ;
}
break;
case V_152 :
break;
default:
F_64 ( L_130 , V_133 -> V_145 ) ;
return - V_68 ;
}
return 0 ;
}
int F_108 ( struct V_52 * V_53 )
{
struct V_132 V_133 ;
struct V_12 * V_13 ;
T_1 V_91 ;
int V_87 ;
if ( V_53 -> V_13 == NULL ) {
V_13 = F_109 ( sizeof( * V_13 ) , V_522 ) ;
if ( V_13 == NULL )
return - V_523 ;
F_3 ( V_13 ) ;
if ( V_53 -> V_166 -> V_114 >= V_177 )
V_91 = V_53 -> V_166 -> V_524 . V_525 . V_526 ;
else
V_91 = V_53 -> V_166 -> V_524 . V_527 . V_526 ;
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
V_13 -> V_528 = 1 ;
break;
case 1 :
default:
V_13 -> V_528 = 2 ;
break;
case 2 :
V_13 -> V_528 = 4 ;
break;
}
V_53 -> V_13 = V_13 ;
}
do {
V_87 = F_67 ( V_53 , & V_133 , V_53 -> V_105 ) ;
if ( V_87 ) {
F_110 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return V_87 ;
}
V_53 -> V_105 += V_133 . V_140 + 2 ;
switch ( V_133 . type ) {
case V_142 :
V_87 = F_81 ( V_53 , & V_133 ) ;
break;
case V_146 :
break;
case V_144 :
V_87 = F_99 ( V_53 , & V_133 ) ;
break;
default:
F_64 ( L_131 , V_133 . type ) ;
F_110 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return - V_68 ;
}
if ( V_87 ) {
F_110 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return V_87 ;
}
} while ( V_53 -> V_105 < V_53 -> V_136 [ V_53 -> V_137 ] . V_139 );
#if 0
for (r = 0; r < p->ib.length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib.ptr[r]);
mdelay(1);
}
#endif
F_110 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return 0 ;
}
int F_111 ( struct V_52 * V_53 )
{
struct V_134 * V_135 = & V_53 -> V_136 [ V_53 -> V_137 ] ;
struct V_147 * V_529 , * V_530 , * V_531 ;
T_1 V_138 , V_532 , V_140 , V_533 , V_534 , V_535 ;
volatile T_1 * V_89 = V_53 -> V_89 . V_90 ;
T_1 V_105 , V_459 ;
T_2 V_536 , V_537 , V_538 ;
int V_87 ;
do {
if ( V_53 -> V_105 >= V_135 -> V_139 ) {
F_64 ( L_51 ,
V_53 -> V_105 , V_135 -> V_139 ) ;
return - V_68 ;
}
V_105 = V_53 -> V_105 ;
V_138 = F_43 ( V_53 , V_105 ) ;
V_532 = F_112 ( V_138 ) ;
V_140 = F_113 ( V_138 ) ;
V_533 = F_114 ( V_138 ) ;
V_534 = F_115 ( V_138 ) ;
V_535 = F_116 ( V_138 ) ;
switch ( V_532 ) {
case V_539 :
V_87 = F_117 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_132 ) ;
return - V_68 ;
}
if ( V_533 ) {
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
V_53 -> V_105 += V_140 + 7 ;
} else {
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += V_140 + 3 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_133 ,
V_537 , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
break;
case V_540 :
V_87 = F_117 ( V_53 , & V_529 ) ;
if ( V_87 ) {
F_64 ( L_134 ) ;
return - V_68 ;
}
V_87 = F_117 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_134 ) ;
return - V_68 ;
}
if ( V_533 ) {
V_459 = F_43 ( V_53 , V_105 + 2 ) ;
if ( V_534 ) {
switch ( V_535 ) {
case 0 :
if ( V_459 & ( 1 << 31 ) ) {
F_64 ( L_135 ) ;
return - V_68 ;
}
V_87 = F_117 ( V_53 , & V_531 ) ;
if ( V_87 ) {
F_64 ( L_135 ) ;
return - V_68 ;
}
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 <<= 8 ;
V_538 = F_43 ( V_53 , V_105 + 2 ) ;
V_538 <<= 8 ;
V_536 = F_43 ( V_53 , V_105 + 8 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 9 ) & 0xff ) ) << 32 ;
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_136 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_137 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_538 + ( V_140 * 4 ) ) > F_23 ( V_531 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_137 ,
V_538 + ( V_140 * 4 ) , F_23 ( V_531 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_531 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 8 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 9 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 10 ;
break;
case 1 :
if ( V_53 -> V_114 < V_177 ) {
F_64 ( L_138 ) ;
return - V_68 ;
}
if ( V_459 & ( 1 << 31 ) ) {
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
} else {
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
}
V_53 -> V_105 += 12 ;
break;
case 3 :
if ( V_459 & ( 1 << 31 ) ) {
F_64 ( L_139 ) ;
return - V_68 ;
}
V_87 = F_117 ( V_53 , & V_531 ) ;
if ( V_87 ) {
F_64 ( L_139 ) ;
return - V_68 ;
}
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 <<= 8 ;
V_538 = F_43 ( V_53 , V_105 + 2 ) ;
V_538 <<= 8 ;
V_536 = F_43 ( V_53 , V_105 + 8 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 9 ) & 0xff ) ) << 32 ;
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_140 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_141 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_538 + ( V_140 * 4 ) ) > F_23 ( V_531 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_142 ,
V_538 + ( V_140 * 4 ) , F_23 ( V_531 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_531 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 8 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 9 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 10 ;
break;
case 4 :
if ( V_459 & ( 1 << 31 ) ) {
V_536 = F_43 ( V_53 , V_105 + 1 ) ;
V_536 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_212 . V_213 >> 8 ) ;
V_537 = F_43 ( V_53 , V_105 + 7 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
} else {
V_536 = F_43 ( V_53 , V_105 + 7 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
}
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_143 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_144 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
V_53 -> V_105 += 9 ;
break;
case 5 :
if ( V_53 -> V_114 < V_177 ) {
F_64 ( L_138 ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 4 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
V_53 -> V_105 += 13 ;
break;
case 7 :
if ( V_459 & ( 1 << 31 ) ) {
F_64 ( L_139 ) ;
return - V_68 ;
}
V_87 = F_117 ( V_53 , & V_531 ) ;
if ( V_87 ) {
F_64 ( L_139 ) ;
return - V_68 ;
}
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 <<= 8 ;
V_538 = F_43 ( V_53 , V_105 + 2 ) ;
V_538 <<= 8 ;
V_536 = F_43 ( V_53 , V_105 + 8 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 9 ) & 0xff ) ) << 32 ;
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_140 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_141 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_538 + ( V_140 * 4 ) ) > F_23 ( V_531 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_142 ,
V_538 + ( V_140 * 4 ) , F_23 ( V_531 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_531 -> V_212 . V_213 >> 8 ) ;
V_89 [ V_105 + 8 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 9 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 10 ;
break;
default:
F_64 ( L_145 , V_535 ) ;
return - V_68 ;
}
} else {
switch ( V_535 ) {
case 0 :
if ( V_459 & ( 1 << 31 ) ) {
V_536 = F_43 ( V_53 , V_105 + 1 ) ;
V_536 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_212 . V_213 >> 8 ) ;
V_537 = F_43 ( V_53 , V_105 + 7 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
} else {
V_536 = F_43 ( V_53 , V_105 + 7 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 >> 8 ) ;
}
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_140 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_141 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
V_53 -> V_105 += 9 ;
break;
default:
F_64 ( L_145 , V_535 ) ;
return - V_68 ;
}
}
} else {
if ( V_534 ) {
switch ( V_535 ) {
case 0 :
V_536 = F_43 ( V_53 , V_105 + 2 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 3 ) & 0xff ) ) << 32 ;
if ( ( V_536 + V_140 ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_146 ,
V_536 + V_140 , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + V_140 ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_147 ,
V_537 + V_140 , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xffffffff ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xffffffff ) ;
V_89 [ V_105 + 3 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
V_89 [ V_105 + 4 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 5 ;
break;
case 1 :
if ( V_53 -> V_114 < V_177 ) {
F_64 ( L_148 ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xffffffff ) ;
V_89 [ V_105 + 2 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_89 [ V_105 + 4 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xffffffff ) ;
V_89 [ V_105 + 5 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 9 ;
break;
case 4 :
V_87 = F_117 ( V_53 , & V_531 ) ;
if ( V_87 ) {
F_64 ( L_149 ) ;
return - V_68 ;
}
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
V_538 = F_43 ( V_53 , V_105 + 2 ) ;
V_538 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 5 ) & 0xff ) ) << 32 ;
V_536 = F_43 ( V_53 , V_105 + 3 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 6 ) & 0xff ) ) << 32 ;
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_150 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_151 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_538 + ( V_140 * 4 ) ) > F_23 ( V_531 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_152 ,
V_538 + ( V_140 * 4 ) , F_23 ( V_531 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_531 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 3 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 4 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
V_89 [ V_105 + 5 ] += F_100 ( V_531 -> V_212 . V_213 ) & 0xff ;
V_89 [ V_105 + 6 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 7 ;
break;
default:
F_64 ( L_145 , V_535 ) ;
return - V_68 ;
}
} else {
V_536 = F_43 ( V_53 , V_105 + 2 ) ;
V_536 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 3 ) & 0xff ) ) << 32 ;
if ( ( V_536 + ( V_140 * 4 ) ) > F_23 ( V_529 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_153 ,
V_536 + ( V_140 * 4 ) , F_23 ( V_529 -> V_227 ) ) ;
return - V_68 ;
}
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_154 ,
V_537 + ( V_140 * 4 ) , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_529 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 3 ] += F_100 ( V_530 -> V_212 . V_213 ) & 0xff ;
V_89 [ V_105 + 4 ] += F_100 ( V_529 -> V_212 . V_213 ) & 0xff ;
V_53 -> V_105 += 5 ;
}
}
break;
case V_541 :
V_87 = F_117 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_155 ) ;
return - V_68 ;
}
V_537 = F_43 ( V_53 , V_105 + 1 ) ;
V_537 |= ( ( T_2 ) ( F_43 ( V_53 , V_105 + 3 ) & 0x00ff0000 ) ) << 16 ;
if ( ( V_537 + ( V_140 * 4 ) ) > F_23 ( V_530 -> V_227 ) ) {
F_7 ( V_53 -> V_66 , L_156 ,
V_537 , F_23 ( V_530 -> V_227 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_530 -> V_212 . V_213 & 0xfffffffc ) ;
V_89 [ V_105 + 3 ] += ( F_100 ( V_530 -> V_212 . V_213 ) << 16 ) & 0x00ff0000 ;
V_53 -> V_105 += 4 ;
break;
case V_542 :
V_53 -> V_105 += 1 ;
break;
default:
F_64 ( L_52 , V_532 , V_105 ) ;
return - V_68 ;
}
} while ( V_53 -> V_105 < V_53 -> V_136 [ V_53 -> V_137 ] . V_139 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib.ptr[r]);
mdelay(1);
}
#endif
return 0 ;
}
static bool F_118 ( T_1 V_143 )
{
if ( V_143 >= 0x28000 )
return true ;
switch ( V_143 ) {
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
case V_373 :
case V_574 :
case V_575 :
case V_576 :
case V_577 :
case V_578 :
case V_579 :
case V_580 :
case V_581 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_586 :
case V_587 :
case V_588 :
case V_589 :
case V_590 :
case V_591 :
case V_592 :
case V_593 :
case V_594 :
case V_595 :
case V_596 :
case V_597 :
case V_598 :
case V_599 :
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
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
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_615 :
case V_616 :
return true ;
default:
F_64 ( L_157 , V_143 ) ;
return false ;
}
}
static int F_119 ( struct V_617 * V_166 ,
T_1 * V_89 , struct V_132 * V_133 )
{
T_1 V_105 = V_133 -> V_105 + 1 ;
T_1 V_459 = V_89 [ V_105 ] ;
T_1 V_457 , V_458 , V_143 , V_14 ;
T_1 V_478 , V_479 ;
switch ( V_133 -> V_145 ) {
case V_152 :
case V_618 :
case V_465 :
case V_619 :
case V_475 :
case V_476 :
case V_620 :
case V_460 :
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_467 :
case V_469 :
case V_462 :
case V_473 :
case V_463 :
case V_468 :
case V_470 :
case V_472 :
case V_464 :
case V_471 :
case V_519 :
case V_474 :
case V_625 :
case V_626 :
case V_163 :
case V_520 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_491 :
case V_507 :
case V_510 :
case V_494 :
case V_516 :
case V_513 :
case V_627 :
case V_628 :
case V_629 :
case V_466 :
break;
case V_630 :
if ( V_459 & 0x100 ) {
V_143 = V_89 [ V_105 + 5 ] * 4 ;
if ( ! F_118 ( V_143 ) )
return - V_68 ;
}
break;
case V_521 :
if ( V_459 & 0x2 ) {
V_143 = V_89 [ V_105 + 3 ] * 4 ;
if ( ! F_118 ( V_143 ) )
return - V_68 ;
}
break;
case V_488 :
V_457 = ( V_459 << 2 ) + V_489 ;
V_458 = 4 * V_133 -> V_140 + V_457 - 4 ;
if ( ( V_457 < V_489 ) ||
( V_457 >= V_490 ) ||
( V_458 >= V_490 ) ) {
F_64 ( L_106 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_133 -> V_140 ; V_14 ++ ) {
V_143 = V_457 + ( 4 * V_14 ) ;
if ( ! F_118 ( V_143 ) )
return - V_68 ;
}
break;
case V_477 :
V_478 = V_89 [ V_105 + 4 ] ;
V_479 = V_89 [ V_105 + 1 ] ;
if ( ( ( ( V_479 & 0x60000000 ) >> 29 ) != 0 ) ||
( ( ( V_479 & 0x00300000 ) >> 20 ) != 0 ) ||
( ( ( ( V_479 & 0x00300000 ) >> 20 ) == 0 ) &&
( V_478 & V_480 ) ) ||
( ( ( ( V_479 & 0x60000000 ) >> 29 ) == 0 ) &&
( V_478 & V_481 ) ) ) {
if ( ( V_478 & 0x1fffff ) % 4 ) {
F_64 ( L_91 ) ;
return - V_68 ;
}
}
if ( V_478 & V_481 ) {
if ( ( ( V_479 & 0x60000000 ) >> 29 ) == 0 ) {
V_457 = V_459 << 2 ;
if ( V_478 & V_482 ) {
V_143 = V_457 ;
if ( ! F_118 ( V_143 ) ) {
F_64 ( L_158 ) ;
return - V_68 ;
}
} else {
for ( V_14 = 0 ; V_14 < ( V_478 & 0x1fffff ) ; V_14 ++ ) {
V_143 = V_457 + ( 4 * V_14 ) ;
if ( ! F_118 ( V_143 ) ) {
F_64 ( L_158 ) ;
return - V_68 ;
}
}
}
}
}
if ( V_478 & V_480 ) {
if ( ( ( V_479 & 0x00300000 ) >> 20 ) == 0 ) {
V_457 = V_89 [ V_105 + 2 ] ;
if ( V_478 & V_483 ) {
V_143 = V_457 ;
if ( ! F_118 ( V_143 ) ) {
F_64 ( L_159 ) ;
return - V_68 ;
}
} else {
for ( V_14 = 0 ; V_14 < ( V_478 & 0x1fffff ) ; V_14 ++ ) {
V_143 = V_457 + ( 4 * V_14 ) ;
if ( ! F_118 ( V_143 ) ) {
F_64 ( L_159 ) ;
return - V_68 ;
}
}
}
}
}
break;
default:
return - V_68 ;
}
return 0 ;
}
int F_120 ( struct V_617 * V_166 , struct V_631 * V_89 )
{
int V_632 = 0 ;
T_1 V_105 = 0 ;
struct V_132 V_133 ;
do {
V_133 . V_105 = V_105 ;
V_133 . type = F_68 ( V_89 -> V_90 [ V_105 ] ) ;
V_133 . V_140 = F_69 ( V_89 -> V_90 [ V_105 ] ) ;
V_133 . V_141 = 0 ;
switch ( V_133 . type ) {
case V_142 :
F_97 ( V_166 -> V_66 , L_160 ) ;
V_632 = - V_68 ;
break;
case V_146 :
V_105 += 1 ;
break;
case V_144 :
V_133 . V_145 = F_71 ( V_89 -> V_90 [ V_105 ] ) ;
V_632 = F_119 ( V_166 , V_89 -> V_90 , & V_133 ) ;
V_105 += V_133 . V_140 + 2 ;
break;
default:
F_97 ( V_166 -> V_66 , L_131 , V_133 . type ) ;
V_632 = - V_68 ;
break;
}
if ( V_632 )
break;
} while ( V_105 < V_89 -> V_139 );
return V_632 ;
}
int F_121 ( struct V_617 * V_166 , struct V_631 * V_89 )
{
T_1 V_105 = 0 ;
T_1 V_138 , V_532 , V_140 , V_533 , V_534 , V_535 ;
do {
V_138 = V_89 -> V_90 [ V_105 ] ;
V_532 = F_112 ( V_138 ) ;
V_140 = F_113 ( V_138 ) ;
V_533 = F_114 ( V_138 ) ;
V_534 = F_115 ( V_138 ) ;
V_535 = F_116 ( V_138 ) ;
switch ( V_532 ) {
case V_539 :
if ( V_533 )
V_105 += V_140 + 7 ;
else
V_105 += V_140 + 3 ;
break;
case V_540 :
if ( V_533 ) {
if ( V_534 ) {
switch ( V_535 ) {
case 0 :
V_105 += 10 ;
break;
case 1 :
V_105 += 12 ;
break;
case 3 :
V_105 += 10 ;
break;
case 4 :
V_105 += 9 ;
break;
case 5 :
V_105 += 13 ;
break;
case 7 :
V_105 += 10 ;
break;
default:
F_64 ( L_145 , V_535 ) ;
return - V_68 ;
}
} else {
switch ( V_535 ) {
case 0 :
V_105 += 9 ;
break;
default:
F_64 ( L_145 , V_535 ) ;
return - V_68 ;
}
}
} else {
if ( V_534 ) {
switch ( V_535 ) {
case 0 :
V_105 += 5 ;
break;
case 1 :
V_105 += 9 ;
break;
case 4 :
V_105 += 7 ;
break;
default:
F_64 ( L_145 , V_535 ) ;
return - V_68 ;
}
} else {
V_105 += 5 ;
}
}
break;
case V_541 :
V_105 += 4 ;
break;
case V_542 :
V_105 += 1 ;
break;
default:
F_64 ( L_52 , V_532 , V_105 ) ;
return - V_68 ;
}
} while ( V_105 < V_89 -> V_139 );
return 0 ;
}
