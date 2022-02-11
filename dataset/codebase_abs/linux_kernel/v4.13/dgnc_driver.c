static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , 0x1000 ) ;
if ( ! V_2 -> V_3 )
return - V_5 ;
return 0 ;
}
static struct V_1 * F_3 ( struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_2 ;
unsigned int V_9 ;
int V_10 = 0 ;
int V_11 = 0 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return F_5 ( - V_5 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 [ V_8 ] . V_15 ;
V_2 -> V_17 = V_16 [ V_8 ] . V_17 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_18 = V_7 -> V_19 -> V_20 ;
V_2 -> V_21 = F_6 ( V_7 -> V_22 ) ;
V_2 -> V_23 = V_24 [ V_8 ] . V_23 ;
V_2 -> V_25 = V_24 [ V_8 ] . V_25 ;
if ( V_24 [ V_10 ] . V_26 )
V_2 -> V_27 |= V_28 ;
V_2 -> V_29 = V_30 ;
F_7 ( & V_2 -> V_31 ) ;
F_8 ( & V_2 -> V_32 ) ;
F_8 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = V_35 ;
F_9 ( V_7 , V_36 , & V_2 -> V_37 ) ;
F_9 ( V_7 , V_38 , & V_2 -> V_39 ) ;
F_10 ( V_7 , V_40 , & V_2 -> V_41 ) ;
V_9 = V_7 -> V_42 ;
V_2 -> V_42 = V_9 ;
switch ( V_2 -> V_17 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
V_2 -> V_47 = V_48 | V_49 ;
V_2 -> V_4 = F_11 ( V_7 , 4 ) ;
if ( ! V_2 -> V_4 ) {
F_12 ( & V_2 -> V_7 -> V_50 ,
L_1 ) ;
V_11 = - V_51 ;
goto V_52;
}
V_2 -> V_53 = F_13 ( V_7 , 4 ) ;
if ( V_2 -> V_4 & 1 )
V_2 -> V_4 &= ~ 3 ;
else
V_2 -> V_4 &= ~ 15 ;
V_2 -> V_54 = F_11 ( V_7 , 1 ) ;
V_2 -> V_55 = F_13 ( V_7 , 1 ) ;
V_2 -> V_54 = ( ( unsigned int ) ( V_2 -> V_54 ) ) & 0xFFFE ;
V_2 -> V_56 = & V_57 ;
V_2 -> V_58 = 0x8 ;
V_2 -> V_59 = 921600 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 )
goto V_52;
V_2 -> V_56 -> V_60 ( V_2 ) ;
F_14 ( 0x43 , V_2 -> V_54 + 0x4c ) ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
if ( V_2 -> V_27 & V_28 )
V_2 -> V_47 = V_74 | V_49 ;
else
V_2 -> V_47 = V_75 | V_49 ;
V_2 -> V_4 = F_11 ( V_7 , 0 ) ;
V_2 -> V_53 = F_13 ( V_7 , 0 ) ;
if ( V_2 -> V_4 & 1 )
V_2 -> V_4 &= ~ 3 ;
else
V_2 -> V_4 &= ~ 15 ;
V_2 -> V_56 = & V_76 ;
V_2 -> V_58 = 0x200 ;
V_2 -> V_59 = 921600 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 )
goto V_52;
V_2 -> V_77 = F_15 ( V_2 -> V_3 + 0x8D ) ;
V_2 -> V_56 -> V_60 ( V_2 ) ;
break;
default:
F_12 ( & V_2 -> V_7 -> V_50 ,
L_2 ) ;
V_11 = - V_78 ;
goto V_52;
}
F_16 ( & V_2 -> V_79 ,
V_2 -> V_56 -> V_80 ,
( unsigned long ) V_2 ) ;
F_17 ( & V_2 -> V_31 ) ;
return V_2 ;
V_52:
F_18 ( V_2 ) ;
return F_5 ( V_11 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 ) {
int V_11 = F_20 ( V_2 -> V_42 , V_2 -> V_56 -> V_81 ,
V_82 , L_3 , V_2 ) ;
if ( V_11 ) {
F_12 ( & V_2 -> V_7 -> V_50 ,
L_4 , V_2 -> V_42 ) ;
V_2 -> V_34 = V_83 ;
V_2 -> V_29 = V_30 ;
return - V_51 ;
}
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 )
F_22 ( V_2 -> V_42 , V_2 ) ;
}
static void F_23 ( T_1 V_84 )
{
struct V_1 * V_2 ;
unsigned long V_85 ;
int V_10 ;
unsigned long V_86 ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
V_2 = V_1 [ V_10 ] ;
F_24 ( & V_2 -> V_32 , V_85 ) ;
if ( V_2 -> V_34 == V_83 ) {
F_25 ( & V_2 -> V_32 , V_85 ) ;
continue;
}
F_26 ( & V_2 -> V_79 ) ;
F_25 ( & V_2 -> V_32 , V_85 ) ;
}
F_24 ( & V_87 , V_85 ) ;
V_88 += F_27 ( V_89 ) ;
V_86 = V_88 - V_90 ;
if ( ( T_1 ) V_86 >= 2 * V_89 )
V_88 = V_90 + F_27 ( V_89 ) ;
F_28 ( & V_91 , F_23 , 0 ) ;
V_91 . V_92 = V_88 ;
F_25 ( & V_87 , V_85 ) ;
if ( ! V_93 )
F_29 ( & V_91 ) ;
}
static int F_30 ( struct V_6 * V_7 , const struct V_94 * V_95 )
{
int V_11 ;
struct V_1 * V_2 ;
V_11 = F_31 ( V_7 ) ;
if ( V_11 )
return - V_96 ;
V_2 = F_3 ( V_7 , V_95 -> V_97 ) ;
if ( F_32 ( V_2 ) )
return F_33 ( V_2 ) ;
V_11 = F_34 ( V_2 ) ;
if ( V_11 < 0 ) {
F_35 ( V_98 L_5 , V_11 ) ;
goto V_52;
}
V_11 = F_19 ( V_2 ) ;
if ( V_11 < 0 ) {
F_35 ( V_98 L_6 , V_11 ) ;
goto V_99;
}
V_11 = F_36 ( V_2 ) ;
if ( V_11 < 0 ) {
F_35 ( V_98 L_7 , V_11 ) ;
goto F_22;
}
V_2 -> V_34 = V_100 ;
V_2 -> V_29 = V_101 ;
V_1 [ V_14 ++ ] = V_2 ;
return 0 ;
F_22:
F_21 ( V_2 ) ;
V_99:
F_37 ( V_2 ) ;
V_52:
F_18 ( V_2 ) ;
return V_11 ;
}
static int F_38 ( void )
{
int V_11 = 0 ;
unsigned long V_85 ;
struct V_17 * V_50 ;
F_39 ( & V_91 ) ;
V_11 = F_40 ( 0 , L_8 , & V_102 ) ;
if ( V_11 < 0 ) {
F_35 ( V_98 L_9 , V_11 ) ;
return V_11 ;
}
V_103 = V_11 ;
V_104 = F_41 ( V_105 , L_10 ) ;
if ( F_32 ( V_104 ) ) {
V_11 = F_33 ( V_104 ) ;
F_35 ( V_98 L_11 , V_11 ) ;
goto V_106;
}
V_50 = F_42 ( V_104 , NULL ,
F_43 ( V_103 , 0 ) ,
NULL , L_10 ) ;
if ( F_32 ( V_50 ) ) {
V_11 = F_33 ( V_50 ) ;
F_35 ( V_98 L_12 , V_11 ) ;
goto V_107;
}
F_24 ( & V_87 , V_85 ) ;
F_28 ( & V_91 , F_23 , 0 ) ;
V_88 = V_90 + F_27 ( V_89 ) ;
V_91 . V_92 = V_88 ;
F_25 ( & V_87 , V_85 ) ;
F_29 ( & V_91 ) ;
return 0 ;
V_107:
F_44 ( V_104 ) ;
V_106:
F_45 ( V_103 , L_8 ) ;
return V_11 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( ! V_2 )
return;
switch ( V_2 -> V_17 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_14 ( 0 , V_2 -> V_54 + 0x4c ) ;
break;
default:
break;
}
if ( V_2 -> V_42 )
F_22 ( V_2 -> V_42 , V_2 ) ;
F_47 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_3 ) {
F_48 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
for ( V_10 = 0 ; V_10 < V_108 ; V_10 ++ ) {
if ( V_2 -> V_109 [ V_10 ] ) {
F_18 ( V_2 -> V_109 [ V_10 ] -> V_110 ) ;
F_18 ( V_2 -> V_109 [ V_10 ] -> V_111 ) ;
F_18 ( V_2 -> V_109 [ V_10 ] -> V_112 ) ;
F_18 ( V_2 -> V_109 [ V_10 ] ) ;
V_2 -> V_109 [ V_10 ] = NULL ;
}
}
V_1 [ V_2 -> V_13 ] = NULL ;
F_18 ( V_2 ) ;
}
static void F_49 ( void )
{
int V_10 ;
unsigned long V_85 ;
F_24 ( & V_87 , V_85 ) ;
V_93 = 1 ;
F_25 ( & V_87 , V_85 ) ;
F_50 ( & V_91 ) ;
F_51 ( V_104 , F_43 ( V_103 , 0 ) ) ;
F_44 ( V_104 ) ;
F_45 ( V_103 , L_8 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; ++ V_10 ) {
F_52 ( V_1 [ V_10 ] ) ;
F_46 ( V_1 [ V_10 ] ) ;
}
}
static void T_2 F_53 ( void )
{
F_49 () ;
F_54 ( & V_113 ) ;
}
static int T_3 F_55 ( void )
{
int V_11 ;
V_11 = F_38 () ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_56 ( & V_113 ) ;
if ( V_11 ) {
F_57 ( L_13 ) ;
F_49 () ;
return V_11 ;
}
return 0 ;
}
