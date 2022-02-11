static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
}
static void F_3 ( unsigned long V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_9 ;
bool V_10 = ( V_7 -> V_11 | V_7 -> V_12 ) ;
bool V_13 ;
switch ( V_3 ) {
case V_14 :
V_9 = F_4 ( V_15 - V_7 -> V_16 ) ;
if ( V_10 )
V_7 -> V_17 += V_9 ;
else
V_7 -> V_18 += V_9 ;
return;
case V_19 :
V_7 -> V_11 = true ;
V_7 -> V_20 ++ ;
V_13 = true ;
break;
case V_21 :
V_7 -> V_12 = true ;
V_7 -> V_22 ++ ;
V_13 = true ;
break;
case V_23 :
V_7 -> V_11 = false ;
V_7 -> V_24 ++ ;
V_13 = V_7 -> V_12 | V_7 -> V_11 ;
break;
case V_25 :
V_7 -> V_12 = false ;
V_7 -> V_26 ++ ;
V_13 = V_7 -> V_12 | V_7 -> V_11 ;
break;
default:
F_5 ( L_1 ) ;
return;
}
if ( V_13 != V_10 ) {
if ( V_13 )
F_1 ( V_5 -> V_2 ) ;
else
F_2 ( V_5 -> V_2 ) ;
F_6 ( L_2 , V_13 ? L_3 : L_4 ,
V_3 ? L_3 : L_4 ) ;
V_9 = F_4 ( V_15 - V_7 -> V_16 ) ;
if ( V_13 ) {
V_7 -> V_27 ++ ;
V_7 -> V_17 += V_9 ;
} else {
V_7 -> V_28 ++ ;
V_7 -> V_18 += V_9 ;
}
V_7 -> V_16 = V_15 ;
}
}
static int F_7 ( T_1 V_29 , struct V_4 * V_5 )
{
int V_30 = 0 ;
struct V_31 * V_32 = NULL ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( L_5 , V_5 , V_29 ) ;
V_32 = F_8 ( 1 , V_33 ) ;
if ( ! V_32 ) {
F_5 ( L_6 ) ;
return - V_34 ;
}
* F_9 ( V_32 , 1 ) = V_29 ;
F_10 ( & V_7 -> V_35 , V_32 ) ;
return V_30 ;
}
static void F_11 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_12 ( V_37 , struct V_6 ,
V_38 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
unsigned long V_39 ;
F_6 ( L_7 , V_5 ) ;
F_3 ( V_19 , V_5 ) ;
F_13 ( & V_7 -> V_40 ) ;
if ( F_7 ( V_41 , V_5 ) < 0 )
F_5 ( L_8 ) ;
V_7 -> V_42 ++ ;
V_39 = F_14 ( V_7 -> V_43 ) ;
F_15 ( & V_7 -> V_44 , V_15 + V_39 ) ;
F_16 ( & V_7 -> V_40 ) ;
F_17 ( V_5 ) ;
}
static void F_18 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_12 ( V_37 , struct V_6 ,
V_45 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_6 ( L_9 , V_5 ) ;
F_3 ( V_21 , V_5 ) ;
F_13 ( & V_7 -> V_40 ) ;
V_7 -> V_46 = V_47 ;
if ( F_7 ( V_48 , V_5 ) < 0 )
F_5 ( L_10 ) ;
V_7 -> V_49 ++ ;
F_16 ( & V_7 -> V_40 ) ;
F_17 ( V_5 ) ;
}
static void F_19 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_12 ( V_37 , struct V_6 ,
V_50 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_6 ( L_11 , V_5 ) ;
F_3 ( V_25 , V_5 ) ;
}
static void F_20 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_12 ( V_37 , struct V_6 ,
V_51 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
F_6 ( L_12 , V_5 ) ;
F_17 ( V_5 ) ;
F_3 ( V_23 , V_5 ) ;
}
static void F_21 ( unsigned long V_52 )
{
struct V_4 * V_5 = (struct V_4 * ) V_52 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_53 ;
F_6 ( L_13 , V_5 , V_7 -> V_54 ) ;
F_22 ( & V_7 -> V_40 ,
V_53 , V_55 ) ;
switch ( V_7 -> V_54 ) {
case V_56 :
if ( F_7 ( V_57 , V_5 ) < 0 ) {
F_5 ( L_14 ) ;
break;
}
V_7 -> V_54 = V_58 ;
V_7 -> V_59 ++ ;
F_23 ( V_7 -> V_60 , & V_7 -> V_51 ) ;
break;
case V_58 :
case V_61 :
default:
F_5 ( L_15 , V_7 -> V_54 ) ;
break;
}
F_24 ( & V_7 -> V_40 , V_53 ) ;
}
static void F_25 ( unsigned long V_52 )
{
struct V_4 * V_5 = (struct V_4 * ) V_52 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_53 , V_39 ;
bool V_62 = false ;
F_6 ( L_16 ,
V_5 , V_7 -> V_54 ) ;
F_22 ( & V_7 -> V_40 ,
V_53 , V_55 ) ;
switch ( V_7 -> V_54 ) {
case V_61 :
V_62 = true ;
if ( F_7 ( V_41 , V_5 ) < 0 ) {
F_5 ( L_10 ) ;
break;
}
V_7 -> V_42 ++ ;
V_39 = F_14 ( V_7 -> V_43 ) ;
F_15 ( & V_7 -> V_44 , V_15 + V_39 ) ;
break;
case V_58 :
case V_56 :
default:
F_5 ( L_15 , V_7 -> V_54 ) ;
break;
}
F_24 ( & V_7 -> V_40 , V_53 ) ;
if ( V_62 )
F_17 ( V_5 ) ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_6 ( L_17 , V_5 ) ;
V_7 = F_27 ( sizeof( struct V_6 ) , V_33 ) ;
if ( ! V_7 )
return - V_34 ;
F_28 ( & V_7 -> V_35 ) ;
F_28 ( & V_7 -> V_63 ) ;
F_29 ( & V_7 -> V_40 ) ;
V_7 -> V_60 = F_30 ( L_18 , 0 ) ;
if ( ! V_7 -> V_60 ) {
F_5 ( L_19 ) ;
F_31 ( V_7 ) ;
return - V_34 ;
}
F_32 ( & V_7 -> V_45 , F_18 ) ;
F_32 ( & V_7 -> V_38 , F_11 ) ;
F_32 ( & V_7 -> V_50 , F_19 ) ;
F_32 ( & V_7 -> V_51 , F_20 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_54 = V_58 ;
V_7 -> V_46 = V_64 ;
V_7 -> V_11 = false ;
V_7 -> V_12 = false ;
V_7 -> V_53 = 0 ;
V_7 -> V_49 = 0 ;
V_7 -> V_59 = 0 ;
V_7 -> V_42 = 0 ;
V_7 -> V_65 = 0 ;
V_7 -> V_66 = 0 ;
V_7 -> V_67 = 0 ;
V_7 -> V_16 = V_15 ;
V_7 -> V_18 = 0 ;
V_7 -> V_17 = 0 ;
V_7 -> V_27 = 0 ;
V_7 -> V_28 = 0 ;
V_7 -> V_20 = 0 ;
V_7 -> V_24 = 0 ;
V_7 -> V_22 = 0 ;
V_7 -> V_26 = 0 ;
V_5 -> V_8 = V_7 ;
F_33 ( & V_7 -> V_44 , F_25 ,
( V_68 ) V_5 ) ;
V_7 -> V_43 = V_69 ;
F_33 ( & V_7 -> V_70 , F_21 , ( V_68 ) V_5 ) ;
V_7 -> V_71 = V_72 ;
F_6 ( L_20 ,
V_7 -> V_71 , V_7 -> V_43 ) ;
return 0 ;
}
static void F_34 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_35 ( V_74 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_75 * V_76 ;
T_2 V_77 ;
if ( ! V_74 -> V_78 )
return;
V_76 = F_36 ( L_21 , V_74 -> V_78 ) ;
V_77 = V_79 ;
F_37 ( L_22 , V_77 , V_76 , & V_7 -> V_54 ) ;
F_37 ( L_23 , V_77 , V_76 , & V_7 -> V_46 ) ;
F_38 ( L_24 , V_77 , V_76 ,
& V_7 -> V_59 ) ;
F_38 ( L_25 , V_77 , V_76 ,
& V_7 -> V_42 ) ;
F_38 ( L_26 , V_77 , V_76 ,
& V_7 -> V_49 ) ;
F_38 ( L_27 , V_77 , V_76 ,
& V_7 -> V_66 ) ;
F_38 ( L_28 , V_77 , V_76 ,
& V_7 -> V_67 ) ;
F_38 ( L_29 , V_77 , V_76 ,
& V_7 -> V_65 ) ;
F_39 ( L_30 , V_77 , V_76 , & V_7 -> V_11 ) ;
F_38 ( L_31 , V_77 , V_76 , & V_7 -> V_20 ) ;
F_38 ( L_32 , V_77 , V_76 , & V_7 -> V_24 ) ;
F_39 ( L_33 , V_77 , V_76 , & V_7 -> V_12 ) ;
F_38 ( L_34 , V_77 , V_76 , & V_7 -> V_22 ) ;
F_38 ( L_35 , V_77 , V_76 , & V_7 -> V_26 ) ;
F_38 ( L_36 , V_77 , V_76 , & V_7 -> V_27 ) ;
F_38 ( L_37 , V_77 , V_76 , & V_7 -> V_28 ) ;
F_40 ( L_38 , V_77 , V_76 , & V_7 -> V_18 ) ;
F_40 ( L_39 , V_77 , V_76 , & V_7 -> V_17 ) ;
V_77 = V_79 | V_80 ;
F_40 ( L_40 , V_77 , V_76 , & V_7 -> V_43 ) ;
F_40 ( L_41 , V_77 , V_76 ,
& V_7 -> V_71 ) ;
}
static int F_41 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( L_42 , V_5 ) ;
F_42 ( & V_7 -> V_63 ) ;
F_42 ( & V_7 -> V_35 ) ;
return 0 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( L_43 , V_5 ) ;
F_3 ( V_14 , V_5 ) ;
F_42 ( & V_7 -> V_63 ) ;
F_42 ( & V_7 -> V_35 ) ;
F_44 ( & V_7 -> V_70 ) ;
F_44 ( & V_7 -> V_44 ) ;
F_45 ( V_7 -> V_60 ) ;
V_7 -> V_5 = NULL ;
F_46 ( V_7 -> V_81 ) ;
V_5 -> V_8 = NULL ;
F_31 ( V_7 ) ;
return 0 ;
}
static void F_47 ( struct V_4 * V_5 )
{
unsigned long V_53 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( L_44 , V_5 ) ;
F_48 ( & V_7 -> V_40 , V_53 ) ;
V_7 -> V_67 ++ ;
switch ( V_7 -> V_46 ) {
case V_64 :
F_23 ( V_7 -> V_60 , & V_7 -> V_45 ) ;
F_24 ( & V_7 -> V_40 , V_53 ) ;
return;
case V_47 :
if ( F_7 ( V_48 , V_5 ) < 0 ) {
F_5 ( L_10 ) ;
break;
}
V_7 -> V_49 ++ ;
break;
default:
F_5 ( L_45 ,
V_7 -> V_46 ) ;
break;
}
F_24 ( & V_7 -> V_40 , V_53 ) ;
F_17 ( V_5 ) ;
}
static void F_49 ( struct V_4 * V_5 )
{
unsigned long V_53 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( L_46 , V_5 ) ;
F_48 ( & V_7 -> V_40 , V_53 ) ;
V_7 -> V_66 ++ ;
switch ( V_7 -> V_46 ) {
case V_47 :
V_7 -> V_46 = V_64 ;
F_23 ( V_7 -> V_60 , & V_7 -> V_50 ) ;
break;
case V_64 :
default:
F_5 ( L_47 ,
V_7 -> V_46 ) ;
break;
}
F_24 ( & V_7 -> V_40 , V_53 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
unsigned long V_53 , V_82 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_31 * V_32 = NULL ;
F_6 ( L_48 , V_5 ) ;
F_48 ( & V_7 -> V_40 , V_53 ) ;
V_7 -> V_65 ++ ;
switch ( V_7 -> V_54 ) {
case V_56 :
F_6 ( L_49 ,
V_7 -> V_54 ) ;
break;
case V_61 :
while ( ( V_32 = F_51 ( & V_7 -> V_63 ) ) )
F_10 ( & V_7 -> V_35 , V_32 ) ;
F_44 ( & V_7 -> V_44 ) ;
V_82 = F_14 ( V_7 -> V_71 ) ;
F_15 ( & V_7 -> V_70 , V_15 + V_82 ) ;
V_7 -> V_54 = V_56 ;
break;
case V_58 :
default:
F_5 ( L_49 ,
V_7 -> V_54 ) ;
break;
}
F_24 ( & V_7 -> V_40 , V_53 ) ;
F_17 ( V_5 ) ;
}
static int F_52 ( struct V_4 * V_5 , struct V_31 * V_32 )
{
unsigned long V_53 = 0 , V_82 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_6 ( L_50 , V_5 , V_32 ,
V_7 -> V_54 ) ;
memcpy ( F_53 ( V_32 , 1 ) , & F_54 ( V_32 ) , 1 ) ;
if ( ! F_55 ( V_83 , & V_7 -> V_53 ) ) {
F_10 ( & V_7 -> V_35 , V_32 ) ;
return 0 ;
}
F_48 ( & V_7 -> V_40 , V_53 ) ;
switch ( V_7 -> V_54 ) {
case V_56 :
F_6 ( L_51 ) ;
F_10 ( & V_7 -> V_35 , V_32 ) ;
V_82 = F_14 ( V_7 -> V_71 ) ;
F_15 ( & V_7 -> V_70 , V_15 + V_82 ) ;
break;
case V_58 :
F_6 ( L_52 ) ;
F_10 ( & V_7 -> V_63 , V_32 ) ;
V_7 -> V_54 = V_61 ;
F_23 ( V_7 -> V_60 , & V_7 -> V_38 ) ;
break;
case V_61 :
F_6 ( L_53 ) ;
F_10 ( & V_7 -> V_63 , V_32 ) ;
break;
default:
F_5 ( L_54 ,
V_7 -> V_54 ) ;
F_46 ( V_32 ) ;
break;
}
F_24 ( & V_7 -> V_40 , V_53 ) ;
return 0 ;
}
static int F_56 ( struct V_73 * V_74 , struct V_31 * V_32 )
{
struct V_4 * V_5 = F_35 ( V_74 ) ;
F_6 ( L_55 , V_5 , V_57 ) ;
F_49 ( V_5 ) ;
F_46 ( V_32 ) ;
return 0 ;
}
static int F_57 ( struct V_73 * V_74 , struct V_31 * V_32 )
{
struct V_4 * V_5 = F_35 ( V_74 ) ;
F_6 ( L_55 , V_5 , V_41 ) ;
F_47 ( V_5 ) ;
F_46 ( V_32 ) ;
return 0 ;
}
static int F_58 ( struct V_73 * V_74 , struct V_31 * V_32 )
{
struct V_4 * V_5 = F_35 ( V_74 ) ;
F_6 ( L_55 , V_5 , V_48 ) ;
F_50 ( V_5 ) ;
F_46 ( V_32 ) ;
return 0 ;
}
static int F_59 ( struct V_4 * V_5 , const void * V_84 , int V_85 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! F_55 ( V_86 , & V_5 -> V_53 ) )
return - V_87 ;
V_7 -> V_81 = F_60 ( V_5 -> V_74 , V_7 -> V_81 , V_84 , V_85 ,
V_88 , F_61 ( V_88 ) ) ;
if ( F_62 ( V_7 -> V_81 ) ) {
int V_30 = F_63 ( V_7 -> V_81 ) ;
F_5 ( L_56 , V_5 -> V_74 -> V_89 , V_30 ) ;
V_7 -> V_81 = NULL ;
return V_30 ;
}
return V_85 ;
}
static struct V_31 * F_64 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
return F_51 ( & V_7 -> V_35 ) ;
}
static T_3 F_65 ( int V_90 )
{
switch ( V_90 ) {
case 9600 :
return V_91 ;
case 19200 :
return V_92 ;
case 38400 :
return V_93 ;
case 57600 :
return V_94 ;
case 115200 :
return V_95 ;
case 230400 :
return V_96 ;
case 460800 :
return V_97 ;
case 500000 :
return V_98 ;
case 921600 :
return V_99 ;
case 1000000 :
return V_100 ;
case 2000000 :
return V_101 ;
case 3000000 :
return V_102 ;
case 3500000 :
return V_103 ;
default:
return V_95 ;
}
}
static int F_66 ( struct V_73 * V_74 , T_3 V_104 )
{
struct V_4 * V_5 = F_35 ( V_74 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_31 * V_32 ;
T_1 V_29 [] = { 0x01 , 0x48 , 0xFC , 0x01 , 0x00 } ;
if ( V_104 > V_102 )
return - V_105 ;
V_29 [ 4 ] = V_104 ;
V_32 = F_8 ( sizeof( V_29 ) , V_33 ) ;
if ( ! V_32 ) {
F_5 ( L_57 ) ;
return - V_34 ;
}
memcpy ( F_9 ( V_32 , sizeof( V_29 ) ) , V_29 , sizeof( V_29 ) ) ;
F_54 ( V_32 ) = V_106 ;
F_10 ( & V_7 -> V_35 , V_32 ) ;
F_17 ( V_5 ) ;
F_67 ( V_107 ) ;
F_68 ( F_14 ( V_108 ) ) ;
F_67 ( V_109 ) ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_73 * V_74 = V_5 -> V_74 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_90 , V_110 = V_95 ;
int V_111 ;
F_70 ( L_58 , V_74 -> V_89 ) ;
F_71 ( V_83 , & V_7 -> V_53 ) ;
V_90 = 0 ;
if ( V_5 -> V_112 )
V_90 = V_5 -> V_112 ;
else if ( V_5 -> V_113 -> V_112 )
V_90 = V_5 -> V_113 -> V_112 ;
if ( V_90 )
F_72 ( V_5 , V_90 ) ;
V_90 = 0 ;
if ( V_5 -> V_114 )
V_90 = V_5 -> V_114 ;
else if ( V_5 -> V_113 -> V_114 )
V_90 = V_5 -> V_113 -> V_114 ;
if ( V_90 ) {
V_110 = F_65 ( V_90 ) ;
F_70 ( L_59 , V_74 -> V_89 , V_90 ) ;
V_111 = F_66 ( V_74 , V_110 ) ;
if ( V_111 ) {
F_5 ( L_60 ,
V_74 -> V_89 , V_111 ) ;
return V_111 ;
}
F_72 ( V_5 , V_90 ) ;
}
V_111 = F_73 ( V_74 , V_110 ) ;
if ( ! V_111 ) {
F_74 ( V_83 , & V_7 -> V_53 ) ;
F_34 ( V_74 ) ;
}
V_5 -> V_74 -> V_115 = V_116 ;
return V_111 ;
}
int T_4 F_75 ( void )
{
return F_76 ( & V_117 ) ;
}
int T_5 F_77 ( void )
{
return F_78 ( & V_117 ) ;
}
