static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
const struct V_5 * V_4 = F_4 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_9 ;
if ( ! V_4 -> V_10 )
return - V_11 ;
if ( ! V_8 -> V_12 ) {
int V_12 = - V_13 ;
if ( V_2 -> V_14 )
V_12 = F_6 ( V_2 -> V_14 , 0 ) ;
if ( V_12 == - V_15 )
return V_12 ;
if ( V_12 < 0 )
V_12 = 0 ;
V_8 -> V_12 = V_12 ;
}
V_9 = F_7 ( V_2 -> V_14 , false ) ;
if ( V_9 < 0 )
return V_9 ;
return V_4 -> V_10 ( V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
const struct V_5 * V_4 = F_4 ( V_2 -> V_6 ) ;
return V_4 -> remove ( F_5 ( V_2 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
F_10 ( V_8 ) ;
}
static struct V_7 * F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 , T_1 V_20 , T_2 V_21 )
{
int V_22 ;
struct V_7 * V_8 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_23 ) ;
if ( ! V_8 )
return F_13 ( - V_24 ) ;
V_8 -> V_17 = V_17 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_21 = V_21 ;
V_8 -> V_2 . V_25 = & V_26 ;
V_8 -> V_2 . V_27 = V_17 -> V_2 ;
V_8 -> V_2 . V_14 = V_19 ;
V_8 -> V_2 . V_28 = F_9 ;
F_14 ( & V_8 -> V_2 , L_1 , V_29 , V_20 ) ;
V_22 = F_15 ( & V_8 -> V_2 ) ;
if ( V_22 < 0 ) {
F_16 ( & V_8 -> V_2 , L_2 ,
F_17 ( & V_8 -> V_2 ) , V_22 ) ;
goto V_30;
}
F_18 ( & V_8 -> V_2 , L_3 , F_17 ( & V_8 -> V_2 ) ) ;
V_30:
F_19 ( & V_8 -> V_2 ) ;
return F_13 ( V_22 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
F_21 ( & V_8 -> V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 , void * V_31 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
if ( V_2 -> V_25 == & V_26 )
F_20 ( V_8 ) ;
return 0 ;
}
int F_23 ( struct V_5 * V_32 )
{
V_32 -> V_6 . V_25 = & V_26 ;
return F_24 ( & V_32 -> V_6 ) ;
}
static int F_25 ( struct V_16 * V_17 )
{
if ( F_26 ( V_17 -> V_33 + V_34 ) & V_35 ) {
F_18 ( V_17 -> V_2 , L_4 ) ;
return - V_36 ;
}
F_27 ( & V_17 -> V_37 ) ;
F_28 ( V_38 | V_39 | V_40 ,
V_17 -> V_33 + V_41 ) ;
F_28 ( V_35 | V_42 ,
V_17 -> V_33 + V_34 ) ;
if ( ! F_29 ( & V_17 -> V_37 ,
F_30 ( 100 ) ) ) {
F_18 ( V_17 -> V_2 , L_5 ) ;
F_28 ( V_43 , V_17 -> V_33 + V_34 ) ;
F_28 ( F_26 ( V_17 -> V_33 + V_44 ) , V_17 -> V_33 + V_44 ) ;
return - V_45 ;
}
if ( V_17 -> V_46 & V_38 ) {
F_18 ( V_17 -> V_2 , L_6 ) ;
return - V_36 ;
}
if ( V_17 -> V_46 & V_39 ) {
if ( V_17 -> V_46 & V_47 ) {
F_18 ( V_17 -> V_2 , L_7 ) ;
return - V_48 ;
}
if ( V_17 -> V_46 & V_49 ) {
F_18 ( V_17 -> V_2 , L_8 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_31 ( struct V_16 * V_17 , T_2 V_21 , T_2 V_51 ,
T_3 * V_52 , T_4 V_53 )
{
T_3 V_54 ;
int V_9 ;
if ( ! V_52 )
return - V_48 ;
switch ( V_53 ) {
case 1 :
V_54 = V_55 ;
break;
case 2 :
V_54 = V_56 ;
break;
case 4 :
V_54 = V_57 ;
break;
default:
F_16 ( V_17 -> V_2 , L_9 , V_53 ) ;
return - V_48 ;
}
F_32 ( & V_17 -> V_58 ) ;
F_28 ( V_51 , V_17 -> V_33 + V_59 ) ;
F_28 ( F_33 ( V_21 ) , V_17 -> V_33 + V_60 ) ;
F_28 ( V_54 , V_17 -> V_33 + V_61 ) ;
V_9 = F_25 ( V_17 ) ;
if ( V_9 )
goto V_62;
* V_52 = F_26 ( V_17 -> V_33 + V_63 ) ;
V_62:
F_34 ( & V_17 -> V_58 ) ;
return V_9 ;
}
static int F_35 ( struct V_16 * V_17 , T_2 V_21 , T_2 V_51 ,
const T_3 * V_52 , T_4 V_53 )
{
T_3 V_54 ;
int V_9 ;
if ( ! V_52 )
return - V_48 ;
switch ( V_53 ) {
case 1 :
V_54 = V_64 ;
break;
case 2 :
V_54 = V_65 ;
break;
case 4 :
V_54 = V_66 ;
break;
default:
F_16 ( V_17 -> V_2 , L_9 , V_53 ) ;
return - V_48 ;
}
F_32 ( & V_17 -> V_58 ) ;
F_28 ( V_51 , V_17 -> V_33 + V_59 ) ;
F_28 ( F_33 ( V_21 ) , V_17 -> V_33 + V_60 ) ;
F_28 ( * V_52 , V_17 -> V_33 + V_63 ) ;
F_28 ( V_54 , V_17 -> V_33 + V_61 ) ;
V_9 = F_25 ( V_17 ) ;
F_34 ( & V_17 -> V_58 ) ;
return V_9 ;
}
static int F_36 ( void * V_67 , unsigned int V_68 ,
unsigned int * V_69 )
{
struct V_70 * V_71 = V_67 ;
struct V_7 * V_8 = V_71 -> V_8 ;
if ( V_68 > 0xff )
return - V_48 ;
return F_31 ( V_8 -> V_17 , V_8 -> V_21 , V_68 , V_69 , V_71 -> V_72 ) ;
}
static int F_37 ( void * V_67 , unsigned int V_68 ,
unsigned int V_69 )
{
struct V_70 * V_71 = V_67 ;
struct V_7 * V_8 = V_71 -> V_8 ;
return F_35 ( V_8 -> V_17 , V_8 -> V_21 , V_68 , & V_69 , V_71 -> V_72 ) ;
}
static void F_38 ( void * V_67 )
{
struct V_70 * V_71 = V_67 ;
F_10 ( V_71 ) ;
}
static struct V_70 * F_39 ( struct V_7 * V_8 ,
const struct V_73 * V_74 )
{
struct V_70 * V_71 ;
switch ( V_74 -> V_75 ) {
case 8 :
case 16 :
case 32 :
break;
default:
return F_13 ( - V_48 ) ;
}
V_71 = F_12 ( sizeof( * V_71 ) , V_23 ) ;
if ( ! V_71 )
return F_13 ( - V_24 ) ;
V_71 -> V_8 = V_8 ;
V_71 -> V_72 = V_74 -> V_75 / 8 ;
return V_71 ;
}
struct V_76 * F_40 ( struct V_7 * V_8 ,
const struct V_73 * V_74 ,
struct V_77 * V_78 ,
const char * V_79 )
{
struct V_70 * V_71 = F_39 ( V_8 , V_74 ) ;
if ( F_41 ( V_71 ) )
return F_42 ( V_71 ) ;
return F_43 ( & V_8 -> V_2 , & V_80 , V_71 , V_74 ,
V_78 , V_79 ) ;
}
static T_5 F_44 ( int V_12 , void * V_81 )
{
struct V_16 * V_17 = V_81 ;
T_3 V_46 ;
V_46 = F_26 ( V_17 -> V_33 + V_44 ) ;
V_17 -> V_46 = V_46 ;
V_46 &= ( V_38 | V_39 |
V_40 ) ;
F_28 ( V_46 , V_17 -> V_33 + V_44 ) ;
V_37 ( & V_17 -> V_37 ) ;
return V_82 ;
}
static int F_45 ( struct V_16 * V_17 )
{
int V_9 = 0 ;
T_3 V_68 ;
F_28 ( V_83 | V_84 |
V_85 | V_86 , V_17 -> V_33 + V_87 ) ;
F_46 ( V_17 -> V_33 + V_87 , V_68 ,
! ( V_68 & V_83 ) , 100 , 250000 ) ;
if ( V_68 & V_83 )
V_9 = - V_45 ;
F_28 ( F_26 ( V_17 -> V_33 + V_44 ) , V_17 -> V_33 + V_44 ) ;
return V_9 ;
}
static T_2 F_47 ( T_1 V_20 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < F_48 ( V_89 ) ; V_88 ++ )
if ( V_20 == V_89 [ V_88 ] . V_20 )
return V_89 [ V_88 ] . V_21 ;
return 0 ;
}
static int F_49 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_18 * V_90 , * V_91 = V_2 -> V_14 ;
T_3 V_20 ;
T_2 V_21 ;
int V_9 ;
if ( ! V_91 )
return - V_48 ;
F_50 (np, child) {
F_18 ( V_2 , L_10 ,
V_90 -> V_92 ) ;
V_9 = F_51 ( V_90 , L_11 , & V_20 ) ;
if ( V_9 ) {
F_16 ( V_2 , L_12 ,
V_90 -> V_92 , V_9 ) ;
continue;
}
V_21 = F_47 ( V_20 ) ;
if ( ! V_21 ) {
F_16 ( V_2 , L_13 ,
V_90 -> V_92 ) ;
continue;
}
F_28 ( V_93 , V_17 -> V_33 + V_61 ) ;
F_28 ( F_33 ( V_21 ) | F_52 ( V_20 ) ,
V_17 -> V_33 + V_60 ) ;
V_9 = F_25 ( V_17 ) ;
if ( V_9 )
F_53 ( V_2 , L_14 ,
V_90 -> V_92 , V_9 ) ;
}
F_50 (np, child) {
struct V_7 * V_8 ;
F_18 ( V_2 , L_15 , V_90 -> V_92 ) ;
V_9 = F_51 ( V_90 , L_11 , & V_20 ) ;
if ( V_9 )
continue;
V_21 = F_47 ( V_20 ) ;
if ( ! V_21 )
continue;
V_8 = F_11 ( V_17 , V_90 , V_20 , V_21 ) ;
if ( F_41 ( V_8 ) )
F_16 ( V_2 , L_16 ,
V_90 -> V_92 , F_54 ( V_8 ) ) ;
}
return 0 ;
}
static int F_55 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = & V_95 -> V_2 ;
struct V_18 * V_91 = V_2 -> V_14 ;
struct V_96 * V_97 ;
struct V_16 * V_17 ;
unsigned long V_98 ;
T_3 V_99 , V_100 = 3000000 ;
int V_101 , V_12 , V_9 ;
T_3 V_68 ;
F_51 ( V_91 , L_17 , & V_100 ) ;
if ( V_100 > V_102 ) {
F_16 ( V_2 ,
L_18 ,
V_100 ) ;
return - V_48 ;
}
V_17 = F_56 ( V_2 , sizeof( * V_17 ) , V_23 ) ;
if ( ! V_17 )
return - V_24 ;
V_17 -> V_2 = V_2 ;
F_57 ( V_95 , V_17 ) ;
V_97 = F_58 ( V_95 , V_103 , 0 ) ;
V_17 -> V_33 = F_59 ( V_2 , V_97 ) ;
if ( F_41 ( V_17 -> V_33 ) )
return F_54 ( V_17 -> V_33 ) ;
V_12 = F_60 ( V_95 , 0 ) ;
if ( V_12 < 0 ) {
F_16 ( V_2 , L_19 , V_12 ) ;
return V_12 ;
}
V_17 -> V_104 = F_61 ( V_2 , NULL ) ;
if ( F_41 ( V_17 -> V_104 ) ) {
V_9 = F_54 ( V_17 -> V_104 ) ;
F_16 ( V_2 , L_20 , V_9 ) ;
return V_9 ;
}
V_9 = F_62 ( V_17 -> V_104 ) ;
if ( V_9 ) {
F_16 ( V_2 , L_21 , V_9 ) ;
return V_9 ;
}
V_98 = F_63 ( V_17 -> V_104 ) ;
V_17 -> V_105 = F_64 ( V_2 , NULL ) ;
if ( F_41 ( V_17 -> V_105 ) ) {
V_9 = F_54 ( V_17 -> V_105 ) ;
F_16 ( V_2 , L_22 , V_9 ) ;
goto V_106;
}
V_9 = F_65 ( V_17 -> V_105 ) ;
if ( V_9 ) {
F_16 ( V_2 , L_23 , V_9 ) ;
goto V_106;
}
F_66 ( & V_17 -> V_37 ) ;
F_67 ( & V_17 -> V_58 ) ;
F_28 ( V_107 , V_17 -> V_33 + V_34 ) ;
F_46 ( V_17 -> V_33 + V_34 , V_68 ,
! ( V_68 & V_107 ) , 1000 , 100000 ) ;
V_101 = V_98 / V_100 / 2 ;
if ( ! V_101 )
V_101 = 1 ;
else if ( V_101 > V_108 + 1 )
V_101 = V_108 + 1 ;
V_99 = V_101 >> 1 ;
if ( ! V_99 )
V_99 = 1 ;
F_68 ( V_2 , L_24 , V_98 / V_101 / 2 ) ;
F_28 ( F_69 ( V_99 ) | F_70 ( V_101 - 1 ) ,
V_17 -> V_33 + V_109 ) ;
V_9 = F_71 ( V_2 , V_12 , F_44 , 0 , V_29 , V_17 ) ;
if ( V_9 ) {
F_16 ( V_2 , L_25 ,
V_12 , V_9 ) ;
goto V_110;
}
V_9 = F_45 ( V_17 ) ;
if ( V_9 )
F_53 ( V_2 , L_26 , V_9 ) ;
F_49 ( V_17 ) ;
return 0 ;
V_110:
F_72 ( V_17 -> V_105 ) ;
V_106:
F_73 ( V_17 -> V_104 ) ;
return V_9 ;
}
static int F_74 ( struct V_94 * V_95 )
{
struct V_16 * V_17 = F_75 ( V_95 ) ;
F_76 ( V_17 -> V_2 , NULL , F_22 ) ;
F_72 ( V_17 -> V_105 ) ;
F_73 ( V_17 -> V_104 ) ;
return 0 ;
}
static int T_6 F_77 ( void )
{
int V_9 ;
V_9 = F_78 ( & V_26 ) ;
if ( V_9 ) {
F_79 ( L_27 , V_9 ) ;
return V_9 ;
}
return F_80 ( & V_5 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_5 ) ;
F_83 ( & V_26 ) ;
}
