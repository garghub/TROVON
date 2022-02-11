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
T_2 * V_89 = V_53 -> V_89 . V_90 ;
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
if ( V_55 . V_61 <= 1 && V_107 & ( V_55 . V_62 - 1 ) ) {
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
T_3 V_86 = ( T_3 ) V_13 -> V_49 [ V_14 ] +
( T_3 ) V_13 -> V_47 [ V_14 ] ;
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
T_1 V_79 = F_16 ( V_13 -> V_21 [ V_14 ] ) ;
if ( V_79 != V_130 &&
( V_91 >> ( V_14 * 4 ) ) & 0xF ) {
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
if ( F_32 ( V_13 -> V_38 ) != V_131 &&
F_65 ( V_13 -> V_32 ) ) {
V_87 = F_28 ( V_53 ) ;
if ( V_87 )
return V_87 ;
}
if ( F_40 ( V_13 -> V_33 ) != V_132 &&
F_66 ( V_13 -> V_32 ) ) {
V_87 = F_39 ( V_53 ) ;
if ( V_87 )
return V_87 ;
}
V_13 -> V_43 = false ;
}
return 0 ;
}
static int F_67 ( struct V_52 * V_53 )
{
static T_2 V_133 [ 6 ] = {
V_134 + V_135 ,
V_134 + V_136 ,
V_134 + V_137 ,
V_134 + V_138 ,
V_134 + V_139 ,
V_134 + V_140
} ;
static T_2 V_141 [ 6 ] = {
V_142 + V_135 ,
V_142 + V_136 ,
V_142 + V_137 ,
V_142 + V_138 ,
V_142 + V_139 ,
V_142 + V_140
} ;
return F_68 ( V_53 , V_133 , V_141 ) ;
}
static int F_69 ( struct V_52 * V_53 ,
struct V_143 * V_144 ,
unsigned V_105 , unsigned V_145 )
{
int V_87 ;
switch ( V_145 ) {
case V_134 :
V_87 = F_67 ( V_53 ) ;
if ( V_87 ) {
F_64 ( L_51 ,
V_105 , V_145 ) ;
return V_87 ;
}
break;
default:
F_70 ( V_146 L_52 ,
V_145 , V_105 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_71 ( struct V_52 * V_53 ,
struct V_143 * V_144 )
{
unsigned V_145 , V_14 ;
unsigned V_105 ;
int V_87 ;
V_105 = V_144 -> V_105 + 1 ;
V_145 = V_144 -> V_145 ;
for ( V_14 = 0 ; V_14 <= V_144 -> V_147 ; V_14 ++ , V_105 ++ , V_145 += 4 ) {
V_87 = F_69 ( V_53 , V_144 , V_105 , V_145 ) ;
if ( V_87 ) {
return V_87 ;
}
}
return 0 ;
}
static int F_72 ( struct V_52 * V_53 , T_1 V_145 , T_1 V_105 )
{
struct V_12 * V_13 = (struct V_12 * ) V_53 -> V_13 ;
struct V_148 * V_149 ;
T_1 V_91 , * V_89 ;
int V_87 ;
V_89 = V_53 -> V_89 . V_90 ;
switch ( V_145 ) {
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
break;
case V_183 :
V_13 -> V_32 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_184 :
if ( V_53 -> V_185 -> V_114 < V_186 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
break;
case V_187 :
if ( V_53 -> V_185 -> V_114 < V_186 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
break;
case V_188 :
V_13 -> V_33 = F_43 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_189 & V_190 ) ) {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] &= ~ F_74 ( 0xf ) ;
V_13 -> V_33 &= ~ F_74 ( 0xf ) ;
V_89 [ V_105 ] |= F_74 ( F_1 ( V_149 -> V_1 ) ) ;
V_13 -> V_33 |= F_74 ( F_1 ( V_149 -> V_1 ) ) ;
if ( V_149 -> V_1 & V_2 ) {
unsigned V_75 , V_78 , V_191 , V_192 ;
F_75 ( V_149 -> V_1 ,
& V_75 , & V_78 , & V_191 ,
& V_192 ) ;
V_89 [ V_105 ] |= F_76 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_77 ( V_192 ) |
F_78 ( V_75 ) |
F_79 ( V_78 ) |
F_80 ( V_191 ) ;
}
}
V_13 -> V_43 = true ;
break;
case V_193 :
V_13 -> V_38 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_194 :
V_13 -> V_30 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_195 :
V_13 -> V_31 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_196 :
V_13 -> V_29 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_43 = true ;
break;
case V_197 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_13 -> V_34 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_36 = V_149 -> V_198 ;
V_13 -> V_43 = true ;
break;
case V_199 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_13 -> V_35 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_37 = V_149 -> V_198 ;
V_13 -> V_43 = true ;
break;
case V_200 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_13 -> V_39 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_41 = V_149 -> V_198 ;
V_13 -> V_43 = true ;
break;
case V_201 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_13 -> V_40 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_42 = V_149 -> V_198 ;
V_13 -> V_43 = true ;
break;
case V_202 :
V_13 -> V_128 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_50 = true ;
break;
case V_203 :
V_13 -> V_129 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_50 = true ;
break;
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_91 = ( V_145 - V_204 ) / 16 ;
V_13 -> V_49 [ V_91 ] = F_43 ( V_53 , V_105 ) << 8 ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_48 [ V_91 ] = V_149 -> V_198 ;
V_13 -> V_50 = true ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
V_91 = ( V_145 - V_208 ) / 16 ;
V_13 -> V_47 [ V_91 ] = F_43 ( V_53 , V_105 ) * 4 ;
V_13 -> V_50 = true ;
break;
case V_212 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_55
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
case V_213 :
V_13 -> V_26 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_214 :
V_13 -> V_27 = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_215 :
if ( V_53 -> V_185 -> V_114 >= V_186 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 ) & V_216 ;
V_13 -> V_61 = 1 << V_91 ;
break;
case V_217 :
if ( V_53 -> V_185 -> V_114 < V_186 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 ) & V_218 ;
V_13 -> V_61 = 1 << V_91 ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
V_91 = ( V_145 - V_219 ) / 0x3c ;
V_13 -> V_22 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
V_91 = ( ( V_145 - V_227 ) / 0x1c ) + 8 ;
V_13 -> V_22 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
V_91 = ( V_145 - V_231 ) / 0x3c ;
V_13 -> V_21 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_189 & V_190 ) ) {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] |= F_81 ( F_1 ( V_149 -> V_1 ) ) ;
V_13 -> V_21 [ V_91 ] |= F_81 ( F_1 ( V_149 -> V_1 ) ) ;
}
V_13 -> V_28 = true ;
break;
case V_239 :
case V_240 :
case V_241 :
case V_242 :
V_91 = ( ( V_145 - V_239 ) / 0x1c ) + 8 ;
V_13 -> V_21 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
if ( ! ( V_53 -> V_189 & V_190 ) ) {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] |= F_81 ( F_1 ( V_149 -> V_1 ) ) ;
V_13 -> V_21 [ V_91 ] |= F_81 ( F_1 ( V_149 -> V_1 ) ) ;
}
V_13 -> V_28 = true ;
break;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_91 = ( V_145 - V_243 ) / 0x3c ;
V_13 -> V_23 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_91 = ( ( V_145 - V_251 ) / 0x1c ) + 8 ;
V_13 -> V_23 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_28 = true ;
break;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
V_91 = ( V_145 - V_255 ) / 0x3c ;
V_13 -> V_24 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_25 [ V_91 ] = V_105 ;
V_13 -> V_28 = true ;
break;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
V_91 = ( ( V_145 - V_263 ) / 0x1c ) + 8 ;
V_13 -> V_24 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_13 -> V_25 [ V_91 ] = V_105 ;
V_13 -> V_28 = true ;
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_189 & V_190 ) ) {
if ( V_149 -> V_1 & V_2 ) {
unsigned V_75 , V_78 , V_191 , V_192 ;
F_75 ( V_149 -> V_1 ,
& V_75 , & V_78 , & V_191 ,
& V_192 ) ;
V_89 [ V_105 ] |= F_82 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_83 ( V_192 ) |
F_84 ( V_75 ) |
F_85 ( V_78 ) |
F_86 ( V_191 ) ;
}
}
V_91 = ( ( V_145 - V_267 ) / 0x3c ) ;
V_13 -> V_88 [ V_91 ] = V_89 [ V_105 ] ;
V_13 -> V_28 = true ;
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_189 & V_190 ) ) {
if ( V_149 -> V_1 & V_2 ) {
unsigned V_75 , V_78 , V_191 , V_192 ;
F_75 ( V_149 -> V_1 ,
& V_75 , & V_78 , & V_191 ,
& V_192 ) ;
V_89 [ V_105 ] |= F_82 ( F_2 ( V_13 -> V_7 ) ) ;
V_89 [ V_105 ] |= F_83 ( V_192 ) |
F_84 ( V_75 ) |
F_85 ( V_78 ) |
F_86 ( V_191 ) ;
}
}
V_91 = ( ( V_145 - V_275 ) / 0x1c ) + 8 ;
V_13 -> V_88 [ V_91 ] = V_89 [ V_105 ] ;
V_13 -> V_28 = true ;
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
V_91 = ( V_145 - V_279 ) / 0x3c ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_87 ( V_53 -> V_66 , L_56 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_15 [ V_91 ] = V_149 -> V_198 ;
break;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
V_91 = ( V_145 - V_287 ) / 0x3c ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_87 ( V_53 -> V_66 , L_56 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_16 [ V_91 ] = V_149 -> V_198 ;
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
V_91 = ( V_145 - V_295 ) / 0x3c ;
V_13 -> V_18 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
break;
case V_303 :
case V_304 :
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
V_91 = ( V_145 - V_303 ) / 0x3c ;
V_13 -> V_17 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
break;
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_91 = ( V_145 - V_311 ) / 0x3c ;
V_13 -> V_20 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_91 ] = V_149 -> V_198 ;
V_13 -> V_28 = true ;
break;
case V_319 :
case V_320 :
case V_321 :
case V_322 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_91 = ( ( V_145 - V_319 ) / 0x1c ) + 8 ;
V_13 -> V_20 [ V_91 ] = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_19 [ V_91 ] = V_149 -> V_198 ;
V_13 -> V_28 = true ;
break;
case V_323 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_13 -> V_45 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_13 -> V_44 = V_149 -> V_198 ;
V_13 -> V_43 = true ;
break;
case V_324 :
V_13 -> V_46 = F_43 ( V_53 , V_105 ) ;
V_89 [ V_105 ] |= 3 ;
V_13 -> V_43 = true ;
break;
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
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
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
break;
case V_425 :
if ( V_53 -> V_185 -> V_114 >= V_186 ) {
F_7 ( V_53 -> V_66 , L_57
L_54 , V_145 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_57
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
break;
case V_426 :
if ( V_53 -> V_185 -> V_114 < V_186 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_53
L_54 , V_145 ) ;
return - V_68 ;
}
V_89 [ V_105 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
break;
case V_427 :
V_13 -> V_51 = ( F_43 ( V_53 , V_105 ) & 0x1 ) != 0 ;
break;
default:
F_7 ( V_53 -> V_66 , L_58 , V_145 , V_105 ) ;
return - V_68 ;
}
return 0 ;
}
static inline bool F_88 ( struct V_52 * V_53 , T_1 V_145 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
T_1 V_428 , V_14 ;
V_14 = ( V_145 >> 7 ) ;
if ( F_89 ( V_14 >= V_429 ) ) {
return false ;
}
V_428 = 1 << ( ( V_145 >> 2 ) & 31 ) ;
if ( ! ( V_13 -> V_430 [ V_14 ] & V_428 ) )
return true ;
return false ;
}
static int F_90 ( struct V_52 * V_53 ,
struct V_143 * V_144 )
{
struct V_148 * V_149 ;
struct V_12 * V_13 ;
T_2 * V_89 ;
unsigned V_105 ;
unsigned V_14 ;
unsigned V_431 , V_432 , V_145 ;
int V_87 ;
T_1 V_433 ;
V_13 = (struct V_12 * ) V_53 -> V_13 ;
V_89 = V_53 -> V_89 . V_90 ;
V_105 = V_144 -> V_105 + 1 ;
V_433 = F_43 ( V_53 , V_105 ) ;
switch ( V_144 -> V_434 ) {
case V_435 :
{
int V_436 ;
int V_91 ;
T_4 V_86 ;
if ( V_144 -> V_147 != 1 ) {
F_64 ( L_59 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 + 1 ) ;
V_436 = ( V_91 >> 16 ) & 0x7 ;
if ( V_436 == 0 )
return 0 ;
if ( V_436 > 2 ) {
F_64 ( L_60 , V_436 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_59 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
( V_433 & 0xfffffff0 ) +
( ( T_3 ) ( V_91 & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = ( V_91 & 0xffffff00 ) | ( F_91 ( V_86 ) & 0xff ) ;
}
break;
case V_437 :
if ( V_144 -> V_147 != 1 ) {
F_64 ( L_61 ) ;
return - V_68 ;
}
break;
case V_438 :
case V_439 :
case V_440 :
if ( V_144 -> V_147 ) {
F_64 ( L_62 ) ;
return - V_68 ;
}
break;
case V_441 :
if ( V_53 -> V_185 -> V_114 < V_186 ) {
F_64 ( L_63 ) ;
return - V_68 ;
}
if ( V_144 -> V_147 ) {
F_64 ( L_62 ) ;
return - V_68 ;
}
break;
case V_442 :
{
T_4 V_86 ;
if ( V_144 -> V_147 != 1 ) {
F_64 ( L_64 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_64 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
V_433 +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_91 ( V_86 ) & 0xff ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_443 :
{
if ( V_144 -> V_147 != 0 ) {
F_64 ( L_66 ) ;
return - V_68 ;
}
break;
}
case V_444 :
{
T_4 V_86 ;
if ( V_144 -> V_147 != 3 ) {
F_64 ( L_67 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_67 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
V_433 +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_91 ( V_86 ) & 0xff ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_445 :
{
T_4 V_86 ;
if ( V_144 -> V_147 != 4 ) {
F_64 ( L_68 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_68 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
F_43 ( V_53 , V_105 + 1 ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_91 ( V_86 ) & 0xff ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_446 :
if ( V_144 -> V_147 != 1 ) {
F_64 ( L_69 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_70 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_447 :
if ( V_144 -> V_147 != 2 ) {
F_64 ( L_71 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_70 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_448 :
if ( V_144 -> V_147 < 2 ) {
F_64 ( L_72 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_449 :
if ( V_144 -> V_147 != 2 ) {
F_64 ( L_73 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_450 :
if ( V_144 -> V_147 != 3 ) {
F_64 ( L_74 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_451 :
{
if ( V_144 -> V_147 != 2 ) {
F_64 ( L_75 ) ;
return - V_68 ;
}
if ( V_433 != 1 ) {
F_64 ( L_75 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_75 ) ;
return - V_68 ;
}
V_13 -> V_452 = F_23 ( V_149 -> V_198 ) ;
V_89 [ V_105 + 1 ] = V_149 -> V_182 ;
V_89 [ V_105 + 2 ] = F_91 ( V_149 -> V_182 ) & 0xff ;
break;
}
case V_453 :
case V_454 :
{
T_3 V_93 = V_144 -> V_434 == V_453 ? 16 : 20 ;
if ( V_144 -> V_147 != 1 ) {
F_64 ( L_76 ) ;
return - V_68 ;
}
if ( V_433 + V_93 > V_13 -> V_452 ) {
F_7 ( V_53 -> V_66 , L_77 ,
V_433 , V_93 , V_13 -> V_452 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
}
case V_455 :
if ( V_144 -> V_147 != 3 ) {
F_64 ( L_78 ) ;
return - V_68 ;
}
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_70 , V_67 , __LINE__ , V_105 ) ;
return V_87 ;
}
break;
case V_456 :
if ( V_144 -> V_147 != 1 ) {
F_64 ( L_79 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_79 ) ;
return - V_68 ;
}
V_89 [ V_105 + 0 ] = V_433 + ( T_1 ) ( V_149 -> V_182 & 0xffffffff ) ;
V_87 = F_63 ( V_53 ) ;
if ( V_87 ) {
F_7 ( V_53 -> V_66 , L_65 , V_67 , __LINE__ ) ;
return V_87 ;
}
break;
case V_457 :
if ( V_144 -> V_147 != 5 ) {
F_64 ( L_80 ) ;
return - V_68 ;
}
if ( V_433 & 0x10 ) {
T_4 V_86 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_80 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = ( V_89 [ V_105 + 1 ] & 0x3 ) | ( V_86 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] = F_91 ( V_86 ) & 0xff ;
} else if ( V_433 & 0x100 ) {
F_64 ( L_81 ) ;
return - V_68 ;
}
break;
case V_458 :
{
T_1 V_459 , V_93 , V_460 ;
T_3 V_86 , V_91 ;
if ( V_144 -> V_147 != 4 ) {
F_64 ( L_82 ) ;
return - V_68 ;
}
V_459 = F_43 ( V_53 , V_105 + 4 ) ;
V_93 = V_459 & 0x1fffff ;
V_460 = F_43 ( V_53 , V_105 + 1 ) ;
if ( ( ( ( V_460 & 0x60000000 ) >> 29 ) != 0 ) ||
( ( ( V_460 & 0x00300000 ) >> 20 ) != 0 ) ||
( ( ( ( V_460 & 0x00300000 ) >> 20 ) == 0 ) &&
( V_459 & V_461 ) ) ||
( ( ( ( V_460 & 0x60000000 ) >> 29 ) == 0 ) &&
( V_459 & V_462 ) ) ) {
if ( V_93 % 4 ) {
F_64 ( L_83 ) ;
return - V_68 ;
}
}
if ( V_459 & V_462 ) {
if ( ( ( V_460 & 0x60000000 ) >> 29 ) != 1 ) {
F_64 ( L_84 ) ;
return - V_68 ;
}
} else {
if ( V_459 & V_463 ) {
F_64 ( L_85 ) ;
return - V_68 ;
}
if ( ( ( V_460 & 0x60000000 ) >> 29 ) == 0 ) {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_86 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) << 32 ) ;
V_86 = V_149 -> V_182 + V_91 ;
if ( ( V_91 + V_93 ) > F_23 ( V_149 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_87 ,
V_91 + V_93 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 ] = V_86 ;
V_89 [ V_105 + 1 ] = ( V_89 [ V_105 + 1 ] & 0xffffff00 ) | ( F_91 ( V_86 ) & 0xff ) ;
} else if ( ( ( V_460 & 0x60000000 ) >> 29 ) != 2 ) {
F_64 ( L_88 ) ;
return - V_68 ;
}
}
if ( V_459 & V_461 ) {
if ( ( ( V_460 & 0x00300000 ) >> 20 ) != 1 ) {
F_64 ( L_89 ) ;
return - V_68 ;
}
} else {
if ( V_459 & V_464 ) {
F_64 ( L_90 ) ;
return - V_68 ;
}
if ( ( ( V_460 & 0x00300000 ) >> 20 ) == 0 ) {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_91 ) ;
return - V_68 ;
}
V_91 = F_43 ( V_53 , V_105 + 2 ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 3 ) & 0xff ) << 32 ) ;
V_86 = V_149 -> V_182 + V_91 ;
if ( ( V_91 + V_93 ) > F_23 ( V_149 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_92 ,
V_91 + V_93 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 2 ] = V_86 ;
V_89 [ V_105 + 3 ] = F_91 ( V_86 ) & 0xff ;
} else {
F_64 ( L_93 ) ;
return - V_68 ;
}
}
break;
}
case V_465 :
if ( V_144 -> V_147 ) {
F_64 ( L_94 ) ;
return - V_68 ;
}
break;
case V_466 :
if ( V_144 -> V_147 != 3 ) {
F_64 ( L_95 ) ;
return - V_68 ;
}
if ( F_43 ( V_53 , V_105 + 1 ) != 0xffffffff ||
F_43 ( V_53 , V_105 + 2 ) != 0 ) {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_95 ) ;
return - V_68 ;
}
V_89 [ V_105 + 2 ] += ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
}
break;
case V_467 :
if ( V_144 -> V_147 != 2 && V_144 -> V_147 != 0 ) {
F_64 ( L_96 ) ;
return - V_68 ;
}
if ( V_144 -> V_147 ) {
T_4 V_86 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_96 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffff8 ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffff8 ;
V_89 [ V_105 + 2 ] = F_91 ( V_86 ) & 0xff ;
}
break;
case V_468 :
{
T_4 V_86 ;
if ( V_144 -> V_147 != 4 ) {
F_64 ( L_97 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_97 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffffc ;
V_89 [ V_105 + 2 ] = ( V_89 [ V_105 + 2 ] & 0xffffff00 ) | ( F_91 ( V_86 ) & 0xff ) ;
break;
}
case V_469 :
{
T_4 V_86 ;
if ( V_144 -> V_147 != 3 ) {
F_64 ( L_98 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_98 ) ;
return - V_68 ;
}
V_86 = V_149 -> V_182 +
( F_43 ( V_53 , V_105 + 1 ) & 0xfffffffc ) +
( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) << 32 ) ;
V_89 [ V_105 + 1 ] = V_86 & 0xfffffffc ;
V_89 [ V_105 + 2 ] = ( V_89 [ V_105 + 2 ] & 0xffffff00 ) | ( F_91 ( V_86 ) & 0xff ) ;
break;
}
case V_470 :
V_431 = ( V_433 << 2 ) + V_471 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_471 ) ||
( V_431 >= V_472 ) ||
( V_432 >= V_472 ) ) {
F_64 ( L_99 ) ;
return - V_68 ;
}
for ( V_145 = V_431 , V_105 ++ ; V_145 <= V_432 ; V_145 += 4 , V_105 ++ ) {
if ( F_88 ( V_53 , V_145 ) )
continue;
V_87 = F_72 ( V_53 , V_145 , V_105 ) ;
if ( V_87 )
return V_87 ;
}
break;
case V_473 :
V_431 = ( V_433 << 2 ) + V_474 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_474 ) ||
( V_431 >= V_475 ) ||
( V_432 >= V_475 ) ) {
F_64 ( L_100 ) ;
return - V_68 ;
}
for ( V_145 = V_431 , V_105 ++ ; V_145 <= V_432 ; V_145 += 4 , V_105 ++ ) {
if ( F_88 ( V_53 , V_145 ) )
continue;
V_87 = F_72 ( V_53 , V_145 , V_105 ) ;
if ( V_87 )
return V_87 ;
}
break;
case V_476 :
if ( V_144 -> V_147 % 8 ) {
F_64 ( L_101 ) ;
return - V_68 ;
}
V_431 = ( V_433 << 2 ) + V_477 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_477 ) ||
( V_431 >= V_478 ) ||
( V_432 >= V_478 ) ) {
F_64 ( L_101 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < ( V_144 -> V_147 / 8 ) ; V_14 ++ ) {
struct V_102 * V_103 , * V_104 ;
T_1 V_106 , V_107 ;
T_1 V_93 , V_86 , V_479 , V_480 ;
switch ( F_92 ( F_43 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 7 ) ) ) {
case V_481 :
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_102 ) ;
return - V_68 ;
}
if ( ! ( V_53 -> V_189 & V_190 ) ) {
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 1 ] |=
F_93 ( F_1 ( V_149 -> V_1 ) ) ;
if ( V_149 -> V_1 & V_2 ) {
unsigned V_75 , V_78 , V_191 , V_192 ;
F_75 ( V_149 -> V_1 ,
& V_75 , & V_78 , & V_191 ,
& V_192 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 6 ] |= F_94 ( V_192 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 7 ] |=
F_95 ( V_75 ) |
F_96 ( V_78 ) |
F_97 ( V_191 ) |
F_98 ( F_2 ( V_13 -> V_7 ) ) ;
}
}
V_103 = V_149 -> V_198 ;
V_106 = ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_480 = V_89 [ V_105 + 1 + ( V_14 * 8 ) + 0 ] & 0x7 ;
V_479 = V_89 [ V_105 + 1 + ( V_14 * 8 ) + 3 ] ;
if ( ( V_480 == V_482 || V_480 == V_483 ) &&
! V_479 &&
! F_99 ( V_53 ) ) {
V_107 = 0 ;
V_104 = NULL ;
} else {
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_102 ) ;
return - V_68 ;
}
V_107 = ( T_1 ) ( ( V_149 -> V_182 >> 8 ) & 0xffffffff ) ;
V_104 = V_149 -> V_198 ;
}
V_87 = F_42 ( V_53 , V_103 , V_104 , V_105 + 1 + ( V_14 * 8 ) ) ;
if ( V_87 )
return V_87 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] += V_106 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 3 ] += V_107 ;
break;
case V_484 :
{
T_4 V_485 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_103 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 0 ) ;
V_93 = F_43 ( V_53 , V_105 + 1 + ( V_14 * 8 ) + 1 ) ;
if ( V_53 -> V_185 && ( V_93 + V_86 ) > F_23 ( V_149 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_104 ) ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 1 ] = F_23 ( V_149 -> V_198 ) - V_86 ;
}
V_485 = V_149 -> V_182 + V_86 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 0 ] = V_485 ;
V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] = ( V_89 [ V_105 + 1 + ( V_14 * 8 ) + 2 ] & 0xffffff00 ) |
( F_91 ( V_485 ) & 0xff ) ;
break;
}
case V_486 :
case V_487 :
default:
F_64 ( L_101 ) ;
return - V_68 ;
}
}
break;
case V_488 :
break;
case V_489 :
V_431 = ( V_433 << 2 ) + V_490 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_490 ) ||
( V_431 >= V_491 ) ||
( V_432 >= V_491 ) ) {
F_64 ( L_105 ) ;
return - V_68 ;
}
break;
case V_492 :
V_431 = ( V_433 << 2 ) + V_493 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_493 ) ||
( V_431 >= V_494 ) ||
( V_432 >= V_494 ) ) {
F_64 ( L_106 ) ;
return - V_68 ;
}
break;
case V_495 :
V_431 = ( V_433 << 2 ) + V_496 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_496 ) ||
( V_431 >= V_497 ) ||
( V_432 >= V_497 ) ) {
F_64 ( L_107 ) ;
return - V_68 ;
}
break;
case V_498 :
if ( V_144 -> V_147 % 3 ) {
F_64 ( L_108 ) ;
return - V_68 ;
}
V_431 = ( V_433 << 2 ) + V_499 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_499 ) ||
( V_431 >= V_500 ) ||
( V_432 >= V_500 ) ) {
F_64 ( L_108 ) ;
return - V_68 ;
}
break;
case V_501 :
if ( V_144 -> V_147 != 4 ) {
F_64 ( L_109 ) ;
return - V_68 ;
}
if ( V_433 & 0x1 ) {
T_3 V_86 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_110 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 ) ;
V_86 += ( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_149 -> V_198 ) ) {
F_64 ( L_111 ,
V_86 + 4 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_86 += V_149 -> V_182 ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_91 ( V_86 ) & 0xff ;
}
if ( ( ( V_433 >> 1 ) & 0x3 ) == 2 ) {
T_3 V_86 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_112 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 3 ) ;
V_86 += ( ( T_3 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_149 -> V_198 ) ) {
F_64 ( L_113 ,
V_86 + 4 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_86 += V_149 -> V_182 ;
V_89 [ V_105 + 3 ] = V_86 ;
V_89 [ V_105 + 4 ] = F_91 ( V_86 ) & 0xff ;
}
break;
case V_502 :
{
T_3 V_86 ;
if ( V_144 -> V_147 != 3 ) {
F_64 ( L_114 ) ;
return - V_68 ;
}
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_115 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 0 ) ;
V_86 += ( ( T_3 ) ( F_43 ( V_53 , V_105 + 1 ) & 0xff ) ) << 32UL ;
if ( V_86 & 0x7 ) {
F_64 ( L_116 ) ;
return - V_68 ;
}
if ( ( V_86 + 8 ) > F_23 ( V_149 -> V_198 ) ) {
F_64 ( L_117 ,
V_86 + 8 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_86 += V_149 -> V_182 ;
V_89 [ V_105 + 0 ] = V_86 ;
V_89 [ V_105 + 1 ] = F_91 ( V_86 ) & 0xff ;
break;
}
case V_503 :
if ( V_144 -> V_147 != 4 ) {
F_64 ( L_118 ) ;
return - V_68 ;
}
if ( V_433 & 0x1 ) {
T_3 V_86 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_119 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 ) ;
V_86 += ( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_149 -> V_198 ) ) {
F_64 ( L_120 ,
V_86 + 4 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_86 += V_149 -> V_182 ;
V_89 [ V_105 + 1 ] = V_86 ;
V_89 [ V_105 + 2 ] = F_91 ( V_86 ) & 0xff ;
} else {
V_145 = F_43 ( V_53 , V_105 + 1 ) << 2 ;
if ( ! F_88 ( V_53 , V_145 ) ) {
F_7 ( V_53 -> V_66 , L_58 ,
V_145 , V_105 + 1 ) ;
return - V_68 ;
}
}
if ( V_433 & 0x2 ) {
T_3 V_86 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_121 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 3 ) ;
V_86 += ( ( T_3 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
if ( ( V_86 + 4 ) > F_23 ( V_149 -> V_198 ) ) {
F_64 ( L_122 ,
V_86 + 4 , F_23 ( V_149 -> V_198 ) ) ;
return - V_68 ;
}
V_86 += V_149 -> V_182 ;
V_89 [ V_105 + 3 ] = V_86 ;
V_89 [ V_105 + 4 ] = F_91 ( V_86 ) & 0xff ;
} else {
V_145 = F_43 ( V_53 , V_105 + 3 ) << 2 ;
if ( ! F_88 ( V_53 , V_145 ) ) {
F_7 ( V_53 -> V_66 , L_58 ,
V_145 , V_105 + 3 ) ;
return - V_68 ;
}
}
break;
case V_504 :
{
T_2 V_505 ;
T_2 V_506 ;
T_2 V_507 ;
if ( V_144 -> V_147 != 2 ) {
F_64 ( L_123 ) ;
return - V_68 ;
}
V_506 = V_508 ;
V_506 -= V_474 ;
V_506 >>= 2 ;
V_505 = V_433 >> 16 ;
if ( V_505 < V_506 || V_505 > ( V_506 + 11 ) ) {
F_7 ( V_53 -> V_66 , L_124 ,
V_505 , V_105 ) ;
return - V_68 ;
}
V_507 = F_100 ( V_433 ) ;
if ( V_507 == V_509 ) {
T_4 V_86 ;
T_2 V_510 ;
V_87 = F_73 ( V_53 , & V_149 , 0 ) ;
if ( V_87 ) {
F_64 ( L_125 ) ;
return - V_68 ;
}
V_86 = F_43 ( V_53 , V_105 + 1 ) ;
V_510 = V_86 & 0x3 ;
V_86 &= ~ 0x3 ;
V_86 += ( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
V_86 += V_149 -> V_182 ;
V_89 [ V_105 + 1 ] = ( V_86 & 0xfffffffc ) | V_510 ;
V_89 [ V_105 + 2 ] = F_91 ( V_86 ) & 0xff ;
} else {
F_64 ( L_126 ) ;
return - V_68 ;
}
break;
}
case V_511 :
break;
default:
F_64 ( L_127 , V_144 -> V_434 ) ;
return - V_68 ;
}
return 0 ;
}
int F_101 ( struct V_52 * V_53 )
{
struct V_143 V_144 ;
struct V_12 * V_13 ;
T_1 V_91 ;
int V_87 ;
if ( V_53 -> V_13 == NULL ) {
V_13 = F_102 ( sizeof( * V_13 ) , V_512 ) ;
if ( V_13 == NULL )
return - V_513 ;
F_3 ( V_13 ) ;
if ( V_53 -> V_185 -> V_114 >= V_186 ) {
V_91 = V_53 -> V_185 -> V_514 . V_515 . V_516 ;
V_13 -> V_430 = V_517 ;
} else {
V_91 = V_53 -> V_185 -> V_514 . V_518 . V_516 ;
V_13 -> V_430 = V_519 ;
}
F_103 ( F_104 ( V_517 ) != V_429 ) ;
F_103 ( F_104 ( V_519 ) != V_429 ) ;
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
V_13 -> V_520 = 1 ;
break;
case 1 :
default:
V_13 -> V_520 = 2 ;
break;
case 2 :
V_13 -> V_520 = 4 ;
break;
}
V_53 -> V_13 = V_13 ;
}
do {
V_87 = F_105 ( V_53 , & V_144 , V_53 -> V_105 ) ;
if ( V_87 ) {
F_106 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return V_87 ;
}
V_53 -> V_105 += V_144 . V_147 + 2 ;
switch ( V_144 . type ) {
case V_521 :
V_87 = F_71 ( V_53 , & V_144 ) ;
break;
case V_522 :
break;
case V_523 :
V_87 = F_90 ( V_53 , & V_144 ) ;
break;
default:
F_64 ( L_128 , V_144 . type ) ;
F_106 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return - V_68 ;
}
if ( V_87 ) {
F_106 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return V_87 ;
}
} while ( V_53 -> V_105 < V_53 -> V_524 -> V_525 );
#if 0
for (r = 0; r < p->ib.length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib.ptr[r]);
mdelay(1);
}
#endif
F_106 ( V_53 -> V_13 ) ;
V_53 -> V_13 = NULL ;
return 0 ;
}
int F_107 ( struct V_52 * V_53 )
{
struct V_526 * V_527 = V_53 -> V_524 ;
struct V_148 * V_528 , * V_529 , * V_530 ;
T_1 V_531 , V_532 , V_147 , V_533 ;
T_2 * V_89 = V_53 -> V_89 . V_90 ;
T_1 V_105 ;
T_3 V_534 , V_535 , V_536 ;
int V_87 ;
do {
if ( V_53 -> V_105 >= V_527 -> V_525 ) {
F_64 ( L_129 ,
V_53 -> V_105 , V_527 -> V_525 ) ;
return - V_68 ;
}
V_105 = V_53 -> V_105 ;
V_531 = F_43 ( V_53 , V_105 ) ;
V_532 = F_108 ( V_531 ) ;
V_147 = F_109 ( V_531 ) ;
V_533 = F_110 ( V_531 ) ;
switch ( V_532 ) {
case V_537 :
V_87 = F_111 ( V_53 , & V_529 ) ;
if ( V_87 ) {
F_64 ( L_130 ) ;
return - V_68 ;
}
switch ( V_533 ) {
case 8 :
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
V_53 -> V_105 += V_147 + 7 ;
break;
case 0 :
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 2 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
V_53 -> V_105 += V_147 + 3 ;
break;
default:
F_64 ( L_131 , V_105 , V_531 ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_132 ,
V_535 , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
break;
case V_538 :
V_87 = F_111 ( V_53 , & V_528 ) ;
if ( V_87 ) {
F_64 ( L_133 ) ;
return - V_68 ;
}
V_87 = F_111 ( V_53 , & V_529 ) ;
if ( V_87 ) {
F_64 ( L_133 ) ;
return - V_68 ;
}
switch ( V_533 ) {
case 0x00 :
V_534 = F_43 ( V_53 , V_105 + 2 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 3 ) & 0xff ) ) << 32 ;
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_134 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_135 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 3 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
V_89 [ V_105 + 4 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_53 -> V_105 += 5 ;
break;
case 0x08 :
if ( F_43 ( V_53 , V_105 + 2 ) & ( 1 << 31 ) ) {
V_534 = F_43 ( V_53 , V_105 + 1 ) ;
V_534 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_528 -> V_182 >> 8 ) ;
V_535 = F_43 ( V_53 , V_105 + 7 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
} else {
V_534 = F_43 ( V_53 , V_105 + 7 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
}
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_136 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_137 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
V_53 -> V_105 += 9 ;
break;
case 0x40 :
V_534 = F_43 ( V_53 , V_105 + 2 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 3 ) & 0xff ) ) << 32 ;
if ( ( V_534 + V_147 ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_138 ,
V_534 + V_147 , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + V_147 ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_139 ,
V_535 + V_147 , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 & 0xffffffff ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_528 -> V_182 & 0xffffffff ) ;
V_89 [ V_105 + 3 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
V_89 [ V_105 + 4 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_53 -> V_105 += 5 ;
break;
case 0x41 :
if ( V_53 -> V_114 < V_186 ) {
F_64 ( L_140 ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_528 -> V_182 & 0xffffffff ) ;
V_89 [ V_105 + 2 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_89 [ V_105 + 4 ] += ( T_1 ) ( V_529 -> V_182 & 0xffffffff ) ;
V_89 [ V_105 + 5 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
V_53 -> V_105 += 9 ;
break;
case 0x44 :
V_87 = F_111 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_141 ) ;
return - V_68 ;
}
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 4 ) & 0xff ) ) << 32 ;
V_536 = F_43 ( V_53 , V_105 + 2 ) ;
V_536 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 5 ) & 0xff ) ) << 32 ;
V_534 = F_43 ( V_53 , V_105 + 3 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 6 ) & 0xff ) ) << 32 ;
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_142 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_143 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_536 + ( V_147 * 4 ) ) > F_23 ( V_530 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_144 ,
V_536 + ( V_147 * 4 ) , F_23 ( V_530 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_530 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 3 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 4 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
V_89 [ V_105 + 5 ] += F_91 ( V_530 -> V_182 ) & 0xff ;
V_89 [ V_105 + 6 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_53 -> V_105 += 7 ;
break;
case 0x48 :
if ( F_43 ( V_53 , V_105 + 2 ) & ( 1 << 31 ) ) {
F_64 ( L_145 ) ;
return - V_68 ;
}
V_87 = F_111 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_145 ) ;
return - V_68 ;
}
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 <<= 8 ;
V_536 = F_43 ( V_53 , V_105 + 2 ) ;
V_536 <<= 8 ;
V_534 = F_43 ( V_53 , V_105 + 8 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 9 ) & 0xff ) ) << 32 ;
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_146 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_147 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_536 + ( V_147 * 4 ) ) > F_23 ( V_530 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_147 ,
V_536 + ( V_147 * 4 ) , F_23 ( V_530 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_530 -> V_182 >> 8 ) ;
V_89 [ V_105 + 8 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 9 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_53 -> V_105 += 10 ;
break;
case 0x49 :
if ( V_53 -> V_114 < V_186 ) {
F_64 ( L_148 ) ;
return - V_68 ;
}
if ( F_43 ( V_53 , V_105 + 2 ) & ( 1 << 31 ) ) {
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_528 -> V_182 >> 8 ) ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
} else {
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
}
V_53 -> V_105 += 12 ;
break;
case 0x4b :
if ( F_43 ( V_53 , V_105 + 2 ) & ( 1 << 31 ) ) {
F_64 ( L_149 ) ;
return - V_68 ;
}
V_87 = F_111 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_149 ) ;
return - V_68 ;
}
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 <<= 8 ;
V_536 = F_43 ( V_53 , V_105 + 2 ) ;
V_536 <<= 8 ;
V_534 = F_43 ( V_53 , V_105 + 8 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 9 ) & 0xff ) ) << 32 ;
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_150 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_151 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_536 + ( V_147 * 4 ) ) > F_23 ( V_530 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_152 ,
V_536 + ( V_147 * 4 ) , F_23 ( V_530 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_530 -> V_182 >> 8 ) ;
V_89 [ V_105 + 8 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 9 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_53 -> V_105 += 10 ;
break;
case 0x4c :
if ( F_43 ( V_53 , V_105 + 2 ) & ( 1 << 31 ) ) {
V_534 = F_43 ( V_53 , V_105 + 1 ) ;
V_534 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_528 -> V_182 >> 8 ) ;
V_535 = F_43 ( V_53 , V_105 + 7 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_91 ( V_529 -> V_182 ) & 0xff ;
} else {
V_534 = F_43 ( V_53 , V_105 + 7 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 8 ) & 0xff ) ) << 32 ;
V_89 [ V_105 + 7 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 8 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 <<= 8 ;
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
}
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_153 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_154 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
V_53 -> V_105 += 9 ;
break;
case 0x4d :
if ( V_53 -> V_114 < V_186 ) {
F_64 ( L_148 ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_528 -> V_182 >> 8 ) ;
V_89 [ V_105 + 4 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
V_53 -> V_105 += 13 ;
break;
case 0x4f :
if ( F_43 ( V_53 , V_105 + 2 ) & ( 1 << 31 ) ) {
F_64 ( L_149 ) ;
return - V_68 ;
}
V_87 = F_111 ( V_53 , & V_530 ) ;
if ( V_87 ) {
F_64 ( L_149 ) ;
return - V_68 ;
}
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 <<= 8 ;
V_536 = F_43 ( V_53 , V_105 + 2 ) ;
V_536 <<= 8 ;
V_534 = F_43 ( V_53 , V_105 + 8 ) ;
V_534 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 9 ) & 0xff ) ) << 32 ;
if ( ( V_534 + ( V_147 * 4 ) ) > F_23 ( V_528 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_150 ,
V_534 + ( V_147 * 4 ) , F_23 ( V_528 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_151 ,
V_535 + ( V_147 * 4 ) , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
if ( ( V_536 + ( V_147 * 4 ) ) > F_23 ( V_530 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_152 ,
V_536 + ( V_147 * 4 ) , F_23 ( V_530 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 >> 8 ) ;
V_89 [ V_105 + 2 ] += ( T_1 ) ( V_530 -> V_182 >> 8 ) ;
V_89 [ V_105 + 8 ] += ( T_1 ) ( V_528 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 9 ] += F_91 ( V_528 -> V_182 ) & 0xff ;
V_53 -> V_105 += 10 ;
break;
default:
F_64 ( L_155 , V_105 , V_531 ) ;
return - V_68 ;
}
break;
case V_539 :
V_87 = F_111 ( V_53 , & V_529 ) ;
if ( V_87 ) {
F_64 ( L_156 ) ;
return - V_68 ;
}
V_535 = F_43 ( V_53 , V_105 + 1 ) ;
V_535 |= ( ( T_3 ) ( F_43 ( V_53 , V_105 + 3 ) & 0x00ff0000 ) ) << 16 ;
if ( ( V_535 + ( V_147 * 4 ) ) > F_23 ( V_529 -> V_198 ) ) {
F_7 ( V_53 -> V_66 , L_157 ,
V_535 , F_23 ( V_529 -> V_198 ) ) ;
return - V_68 ;
}
V_89 [ V_105 + 1 ] += ( T_1 ) ( V_529 -> V_182 & 0xfffffffc ) ;
V_89 [ V_105 + 3 ] += ( F_91 ( V_529 -> V_182 ) << 16 ) & 0x00ff0000 ;
V_53 -> V_105 += 4 ;
break;
case V_540 :
V_53 -> V_105 += 1 ;
break;
default:
F_64 ( L_158 , V_532 , V_105 ) ;
return - V_68 ;
}
} while ( V_53 -> V_105 < V_53 -> V_524 -> V_525 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib.ptr[r]);
mdelay(1);
}
#endif
return 0 ;
}
static bool F_112 ( T_1 V_145 )
{
if ( V_145 >= 0x28000 )
return true ;
switch ( V_145 ) {
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
case V_344 :
case V_572 :
case V_573 :
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
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
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
case V_613 :
case V_614 :
return true ;
default:
F_64 ( L_159 , V_145 ) ;
return false ;
}
}
static int F_113 ( struct V_615 * V_185 ,
T_1 * V_89 , struct V_143 * V_144 )
{
T_1 V_105 = V_144 -> V_105 + 1 ;
T_1 V_433 = V_89 [ V_105 ] ;
T_1 V_431 , V_432 , V_145 , V_14 ;
T_1 V_459 , V_460 ;
switch ( V_144 -> V_434 ) {
case V_511 :
break;
case V_451 :
if ( V_433 != 1 ) {
F_64 ( L_160 ) ;
return - V_68 ;
}
break;
case V_440 :
case V_443 :
case V_455 :
case V_456 :
case V_616 :
case V_435 :
case V_617 :
case V_618 :
case V_453 :
case V_454 :
case V_442 :
case V_445 :
case V_437 :
case V_449 :
case V_438 :
case V_444 :
case V_446 :
case V_448 :
case V_439 :
case V_447 :
case V_501 :
case V_450 :
case V_619 :
case V_620 :
case V_457 :
case V_502 :
case V_465 :
case V_466 :
case V_467 :
case V_468 :
case V_469 :
case V_473 :
case V_489 :
case V_492 :
case V_476 :
case V_498 :
case V_495 :
case V_621 :
case V_622 :
case V_623 :
case V_441 :
break;
case V_624 :
if ( V_433 & 0x100 ) {
V_145 = V_89 [ V_105 + 5 ] * 4 ;
if ( ! F_112 ( V_145 ) )
return - V_68 ;
}
break;
case V_503 :
if ( V_433 & 0x2 ) {
V_145 = V_89 [ V_105 + 3 ] * 4 ;
if ( ! F_112 ( V_145 ) )
return - V_68 ;
}
break;
case V_470 :
V_431 = ( V_433 << 2 ) + V_471 ;
V_432 = 4 * V_144 -> V_147 + V_431 - 4 ;
if ( ( V_431 < V_471 ) ||
( V_431 >= V_472 ) ||
( V_432 >= V_472 ) ) {
F_64 ( L_99 ) ;
return - V_68 ;
}
for ( V_14 = 0 ; V_14 < V_144 -> V_147 ; V_14 ++ ) {
V_145 = V_431 + ( 4 * V_14 ) ;
if ( ! F_112 ( V_145 ) )
return - V_68 ;
}
break;
case V_458 :
V_459 = V_89 [ V_105 + 4 ] ;
V_460 = V_89 [ V_105 + 1 ] ;
if ( ( ( ( V_460 & 0x60000000 ) >> 29 ) != 0 ) ||
( ( ( V_460 & 0x00300000 ) >> 20 ) != 0 ) ||
( ( ( ( V_460 & 0x00300000 ) >> 20 ) == 0 ) &&
( V_459 & V_461 ) ) ||
( ( ( ( V_460 & 0x60000000 ) >> 29 ) == 0 ) &&
( V_459 & V_462 ) ) ) {
if ( ( V_459 & 0x1fffff ) % 4 ) {
F_64 ( L_83 ) ;
return - V_68 ;
}
}
if ( V_459 & V_462 ) {
if ( ( ( V_460 & 0x60000000 ) >> 29 ) == 0 ) {
V_431 = V_433 << 2 ;
if ( V_459 & V_463 ) {
V_145 = V_431 ;
if ( ! F_112 ( V_145 ) ) {
F_64 ( L_161 ) ;
return - V_68 ;
}
} else {
for ( V_14 = 0 ; V_14 < ( V_459 & 0x1fffff ) ; V_14 ++ ) {
V_145 = V_431 + ( 4 * V_14 ) ;
if ( ! F_112 ( V_145 ) ) {
F_64 ( L_161 ) ;
return - V_68 ;
}
}
}
}
}
if ( V_459 & V_461 ) {
if ( ( ( V_460 & 0x00300000 ) >> 20 ) == 0 ) {
V_431 = V_89 [ V_105 + 2 ] ;
if ( V_459 & V_464 ) {
V_145 = V_431 ;
if ( ! F_112 ( V_145 ) ) {
F_64 ( L_162 ) ;
return - V_68 ;
}
} else {
for ( V_14 = 0 ; V_14 < ( V_459 & 0x1fffff ) ; V_14 ++ ) {
V_145 = V_431 + ( 4 * V_14 ) ;
if ( ! F_112 ( V_145 ) ) {
F_64 ( L_162 ) ;
return - V_68 ;
}
}
}
}
}
break;
case V_504 : {
T_2 V_505 ;
T_2 V_506 ;
if ( V_144 -> V_147 != 2 ) {
F_64 ( L_123 ) ;
return - V_68 ;
}
V_506 = V_508 ;
V_506 -= V_474 ;
V_506 >>= 2 ;
V_505 = V_433 >> 16 ;
if ( V_505 < V_506 || V_505 > ( V_506 + 11 ) ) {
F_64 ( L_124 ,
V_505 , V_105 ) ;
return - V_68 ;
}
break;
}
default:
return - V_68 ;
}
return 0 ;
}
int F_114 ( struct V_615 * V_185 , struct V_625 * V_89 )
{
int V_626 = 0 ;
T_1 V_105 = 0 ;
struct V_143 V_144 ;
do {
V_144 . V_105 = V_105 ;
V_144 . type = F_115 ( V_89 -> V_90 [ V_105 ] ) ;
V_144 . V_147 = F_116 ( V_89 -> V_90 [ V_105 ] ) ;
V_144 . V_627 = 0 ;
switch ( V_144 . type ) {
case V_521 :
F_87 ( V_185 -> V_66 , L_163 ) ;
V_626 = - V_68 ;
break;
case V_522 :
V_105 += 1 ;
break;
case V_523 :
V_144 . V_434 = F_117 ( V_89 -> V_90 [ V_105 ] ) ;
V_626 = F_113 ( V_185 , V_89 -> V_90 , & V_144 ) ;
V_105 += V_144 . V_147 + 2 ;
break;
default:
F_87 ( V_185 -> V_66 , L_128 , V_144 . type ) ;
V_626 = - V_68 ;
break;
}
if ( V_626 )
break;
} while ( V_105 < V_89 -> V_525 );
return V_626 ;
}
int F_118 ( struct V_615 * V_185 , struct V_625 * V_89 )
{
T_1 V_105 = 0 ;
T_1 V_531 , V_532 , V_147 , V_533 ;
do {
V_531 = V_89 -> V_90 [ V_105 ] ;
V_532 = F_108 ( V_531 ) ;
V_147 = F_109 ( V_531 ) ;
V_533 = F_110 ( V_531 ) ;
switch ( V_532 ) {
case V_537 :
switch ( V_533 ) {
case 8 :
V_105 += V_147 + 7 ;
break;
case 0 :
V_105 += V_147 + 3 ;
break;
default:
F_64 ( L_131 , V_105 , V_89 -> V_90 [ V_105 ] ) ;
return - V_68 ;
}
break;
case V_538 :
switch ( V_533 ) {
case 0x00 :
V_105 += 5 ;
break;
case 0x08 :
V_105 += 9 ;
break;
case 0x40 :
V_105 += 5 ;
break;
case 0x41 :
V_105 += 9 ;
break;
case 0x44 :
V_105 += 7 ;
break;
case 0x48 :
V_105 += 10 ;
break;
case 0x49 :
V_105 += 12 ;
break;
case 0x4b :
V_105 += 10 ;
break;
case 0x4c :
V_105 += 9 ;
break;
case 0x4d :
V_105 += 13 ;
break;
case 0x4f :
V_105 += 10 ;
break;
default:
F_64 ( L_155 , V_105 , V_89 -> V_90 [ V_105 ] ) ;
return - V_68 ;
}
break;
case V_539 :
V_105 += 4 ;
break;
case V_540 :
V_105 += 1 ;
break;
default:
F_64 ( L_158 , V_532 , V_105 ) ;
return - V_68 ;
}
} while ( V_105 < V_89 -> V_525 );
return 0 ;
}
