static T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_4 ,
int (* F_2)( struct V_5 * , unsigned long ) )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
char * V_7 ;
unsigned long V_8 ;
int V_9 ;
if ( ! F_4 ( F_5 ( V_6 -> V_10 ) -> V_11 , V_12 ) )
return - V_13 ;
V_8 = F_6 ( V_3 , & V_7 , 0 ) ;
if ( V_7 == V_3 )
return - V_14 ;
if ( ! F_7 () )
return F_8 () ;
V_9 = (* F_2)( V_6 , V_8 ) ;
if ( ! V_9 )
F_9 ( V_6 -> V_10 ) ;
F_10 () ;
return V_9 ? V_9 : V_4 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_1 , F_12 ( V_6 -> V_17 ) ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
return sprintf ( V_3 , L_1 ,
F_12 ( F_3 ( V_2 ) -> V_19 ) ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_20 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
return sprintf ( V_3 , L_1 ,
F_12 ( F_3 ( V_2 ) -> V_21 ) ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_22 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_1 , F_12 ( V_6 -> V_23 ) ) ;
}
static int F_19 ( struct V_5 * V_6 , unsigned long V_8 )
{
return F_20 ( V_6 , V_8 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_19 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_24 ) ;
}
static int F_23 ( struct V_5 * V_6 , unsigned long V_8 )
{
F_24 ( V_6 , V_8 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_23 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_3 , V_6 -> V_25 ) ;
}
static int F_27 ( struct V_5 * V_6 , unsigned long V_8 )
{
if ( V_8 & V_26 )
return - V_14 ;
V_6 -> V_25 = V_8 ;
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_27 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 ,
( V_6 -> V_27 . V_28 [ 0 ] << 8 ) | V_6 -> V_27 . V_28 [ 1 ] ) ;
}
static int F_30 ( struct V_5 * V_6 , unsigned long V_8 )
{
F_31 ( V_6 , ( V_29 ) V_8 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_30 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
return F_34 ( V_3 , & F_3 ( V_2 ) -> V_30 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
return F_34 ( V_3 , & F_3 ( V_2 ) -> V_27 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
return sprintf ( V_3 , L_2 , F_3 ( V_2 ) -> V_31 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
return sprintf ( V_3 , L_2 , F_3 ( V_2 ) -> V_32 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
return sprintf ( V_3 , L_2 , F_3 ( V_2 ) -> V_33 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_34 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_4 , F_41 ( & V_6 -> V_35 ) ) ;
}
static T_1 F_42 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_4 , F_41 ( & V_6 -> V_36 ) ) ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_4 , F_41 ( & V_6 -> V_37 ) ) ;
}
static T_1 F_44 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_4 , F_41 ( & V_6 -> V_38 . V_39 ) ) ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_5 ,
V_6 -> V_40 [ 0 ] , V_6 -> V_40 [ 1 ] ,
V_6 -> V_40 [ 2 ] , V_6 -> V_40 [ 3 ] ,
V_6 -> V_40 [ 4 ] , V_6 -> V_40 [ 5 ] ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_3 V_41 [ 6 ] ;
int V_42 ;
if ( ! F_4 ( F_5 ( V_6 -> V_10 ) -> V_11 , V_12 ) )
return - V_13 ;
if ( sscanf ( V_3 , L_6 ,
& V_41 [ 0 ] , & V_41 [ 1 ] , & V_41 [ 2 ] ,
& V_41 [ 3 ] , & V_41 [ 4 ] , & V_41 [ 5 ] ) != 6 )
return - V_14 ;
if ( ! F_47 ( V_41 ) )
return - V_14 ;
if ( V_41 [ 5 ] == 1 ||
V_41 [ 5 ] == 2 ||
V_41 [ 5 ] == 3 )
return - V_14 ;
if ( ! F_7 () )
return F_8 () ;
F_48 ( & V_6 -> V_43 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ )
V_6 -> V_40 [ V_42 ] = V_41 [ V_42 ] ;
F_49 ( & V_6 -> V_43 ) ;
V_6 -> V_44 = true ;
F_50 ( V_6 ) ;
F_9 ( V_6 -> V_10 ) ;
F_10 () ;
return V_4 ;
}
static int F_51 ( struct V_5 * V_6 , unsigned long V_8 )
{
F_52 ( V_6 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_51 ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_45 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_46 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , ! V_6 -> V_47 ) ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_48 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_49 ) ;
}
static int F_59 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_49 = ! ! V_8 ;
return 0 ;
}
static T_1
F_60 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_59 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_50 ) ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_51 ) ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_52 ) ;
}
static int F_64 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_52 = V_8 ;
return 0 ;
}
static T_1 F_65 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_64 ) ;
}
static T_1 F_66 ( struct V_1 * V_2 , struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_53 ) ;
}
static T_1 F_67 ( struct V_1 * V_2 , struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_54 ) ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_55 ) ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_56 ) ;
}
static T_1 F_70 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_57 ) ;
}
static int F_71 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_57 = V_8 ;
return 0 ;
}
static T_1 F_72 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_71 ) ;
}
static T_1 F_73 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_58 ) ;
}
static int F_74 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_58 = V_8 ;
return 0 ;
}
static T_1 F_75 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_74 ) ;
}
static T_1 F_76 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_1 ,
F_12 ( V_6 -> V_59 ) ) ;
}
static int F_77 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_59 = F_78 ( V_8 ) ;
return 0 ;
}
static T_1 F_79 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_77 ) ;
}
static T_1 F_80 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_1 ,
F_12 ( V_6 -> V_60 ) ) ;
}
static int F_81 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_60 = F_78 ( V_8 ) ;
return 0 ;
}
static T_1 F_82 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_81 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_1 ,
F_12 ( V_6 -> V_61 ) ) ;
}
static int F_84 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_61 = F_78 ( V_8 ) ;
return 0 ;
}
static T_1 F_85 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_84 ) ;
}
static T_1 F_86 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_1 ,
F_12 ( V_6 -> V_62 ) ) ;
}
static int F_87 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_62 = F_78 ( V_8 ) ;
return 0 ;
}
static T_1 F_88 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_87 ) ;
}
static T_1 F_89 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf (
V_3 , L_1 ,
F_12 ( V_6 -> V_63 ) ) ;
}
static int F_90 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_63 = F_78 ( V_8 ) ;
return 0 ;
}
static T_1 F_91 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_90 ) ;
}
static T_1 F_92 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf (
V_3 , L_1 ,
F_12 ( V_6 -> V_64 ) ) ;
}
static int F_93 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_64 = F_78 ( V_8 ) ;
return 0 ;
}
static T_1 F_94 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_93 ) ;
}
static T_1 F_95 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_65 ) ;
}
static int F_96 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_65 = ! ! V_8 ;
return 0 ;
}
static T_1 F_97 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_96 ) ;
}
static T_1 F_98 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_66 ) ;
}
static T_1 F_99 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_67 ) ;
}
static T_1 F_100 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_68 ) ;
}
static int F_101 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_68 = V_8 ? true : false ;
return 0 ;
}
static T_1 F_102 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_101 ) ;
}
static T_1 F_103 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_69 ) ;
}
static int F_104 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_69 = V_8 ? true : false ;
return 0 ;
}
static T_1 F_105 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_104 ) ;
}
static T_1 F_106 (
struct V_1 * V_2 , struct V_15 * V_16 , char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_70 ) ;
}
static int F_107 ( struct V_5 * V_6 , unsigned long V_8 )
{
V_6 -> V_70 = V_8 ? true : false ;
return 0 ;
}
static T_1 F_108 (
struct V_1 * V_2 , struct V_15 * V_16 , const char * V_3 ,
T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , F_107 ) ;
}
static T_1 F_109 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_71 ) ;
}
static T_1 F_110 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_72 ) ;
}
static T_1 F_111 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_8 , F_112 ( V_6 -> V_73 ) ) ;
}
static T_1 F_113 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_74 ) ;
}
static T_1 F_114 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_2 , V_6 -> V_75 ) ;
}
static T_1 F_115 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_76 ) ;
}
static T_1 F_116 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
char * V_3 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
return sprintf ( V_3 , L_7 , V_6 -> V_77 ) ;
}
static T_1 F_117 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const char * V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_78 ) ;
}
static T_1 F_118 ( struct V_79 * V_80 , struct V_81 * V_82 ,
struct V_83 * V_84 ,
char * V_3 , T_4 V_85 , T_2 V_86 )
{
struct V_1 * V_10 = F_119 ( V_82 ) ;
struct V_5 * V_6 = F_3 ( V_10 ) ;
int V_87 ;
if ( V_85 % sizeof( struct V_88 ) != 0 )
return - V_14 ;
V_87 = F_120 ( V_6 , V_3 ,
V_86 / sizeof( struct V_88 ) ,
V_85 / sizeof( struct V_88 ) ) ;
if ( V_87 > 0 )
V_87 *= sizeof( struct V_88 ) ;
return V_87 ;
}
int F_121 ( struct V_89 * V_10 )
{
struct V_81 * V_90 = & V_10 -> V_10 . V_82 ;
struct V_5 * V_6 = F_122 ( V_10 ) ;
int V_9 ;
V_9 = F_123 ( V_90 , & V_91 ) ;
if ( V_9 ) {
F_124 ( L_9 ,
V_92 , V_10 -> V_93 , V_91 . V_93 ) ;
goto V_94;
}
V_9 = F_125 ( V_90 , & V_95 ) ;
if ( V_9 ) {
F_124 ( L_10 ,
V_92 , V_10 -> V_93 , V_95 . V_16 . V_93 ) ;
goto V_96;
}
V_6 -> V_97 = F_126 ( V_98 , V_90 ) ;
if ( ! V_6 -> V_97 ) {
F_124 ( L_11 ,
V_92 , V_10 -> V_93 , V_98 ) ;
V_9 = - V_99 ;
goto V_100;
}
return 0 ;
V_100:
F_127 ( & V_10 -> V_10 . V_82 , & V_95 ) ;
V_96:
F_128 ( & V_10 -> V_10 . V_82 , & V_91 ) ;
V_94:
return V_9 ;
}
void F_129 ( struct V_89 * V_10 )
{
struct V_81 * V_82 = & V_10 -> V_10 . V_82 ;
struct V_5 * V_6 = F_122 ( V_10 ) ;
F_130 ( V_6 -> V_97 ) ;
F_127 ( V_82 , & V_95 ) ;
F_128 ( V_82 , & V_91 ) ;
}
