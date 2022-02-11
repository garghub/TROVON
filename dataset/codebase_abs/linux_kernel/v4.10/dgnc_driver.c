static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_2 -> V_4 = F_2 ( V_2 -> V_5 , 0x1000 ) ;
if ( ! V_2 -> V_4 )
V_3 = - V_6 ;
return V_3 ;
}
static struct V_1 * F_3 ( struct V_7 * V_8 , int V_9 )
{
struct V_1 * V_2 ;
unsigned int V_10 ;
int V_11 = 0 ;
int V_3 = 0 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return F_5 ( - V_6 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 [ V_9 ] . V_17 ;
V_2 -> V_19 = V_18 [ V_9 ] . V_19 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_20 = V_8 -> V_21 -> V_22 ;
V_2 -> V_23 = F_6 ( V_8 -> V_24 ) ;
V_2 -> V_25 = V_26 [ V_9 ] . V_25 ;
V_2 -> V_27 = V_26 [ V_9 ] . V_27 ;
if ( V_26 [ V_11 ] . V_28 )
V_2 -> V_29 |= V_30 ;
V_2 -> V_31 = V_32 ;
F_7 ( & V_2 -> V_33 ) ;
F_8 ( & V_2 -> V_34 ) ;
F_8 ( & V_2 -> V_35 ) ;
V_2 -> V_36 = V_37 ;
F_9 ( V_8 , V_38 , & V_2 -> V_39 ) ;
F_9 ( V_8 , V_40 , & V_2 -> V_41 ) ;
F_10 ( V_8 , V_42 , & V_2 -> V_43 ) ;
V_10 = V_8 -> V_44 ;
V_2 -> V_44 = V_10 ;
switch ( V_2 -> V_19 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_2 -> V_49 = V_50 | V_51 ;
V_2 -> V_5 = F_11 ( V_8 , 4 ) ;
if ( ! V_2 -> V_5 ) {
F_12 ( & V_2 -> V_8 -> V_52 ,
L_1 ) ;
V_3 = - V_53 ;
goto V_54;
}
V_2 -> V_55 = F_13 ( V_8 , 4 ) ;
if ( V_2 -> V_5 & 1 )
V_2 -> V_5 &= ~ 3 ;
else
V_2 -> V_5 &= ~ 15 ;
V_2 -> V_56 = F_11 ( V_8 , 1 ) ;
V_2 -> V_57 = F_13 ( V_8 , 1 ) ;
V_2 -> V_56 = ( ( unsigned int ) ( V_2 -> V_56 ) ) & 0xFFFE ;
V_2 -> V_58 = & V_59 ;
V_2 -> V_60 = 0x8 ;
V_2 -> V_61 = 921600 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_54;
V_2 -> V_58 -> V_62 ( V_2 ) ;
F_14 ( 0x43 , V_2 -> V_56 + 0x4c ) ;
break;
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
case V_74 :
case V_75 :
if ( V_2 -> V_29 & V_30 )
V_2 -> V_49 = V_76 | V_51 ;
else
V_2 -> V_49 = V_77 | V_51 ;
V_2 -> V_5 = F_11 ( V_8 , 0 ) ;
V_2 -> V_55 = F_13 ( V_8 , 0 ) ;
if ( V_2 -> V_5 & 1 )
V_2 -> V_5 &= ~ 3 ;
else
V_2 -> V_5 &= ~ 15 ;
V_2 -> V_58 = & V_78 ;
V_2 -> V_60 = 0x200 ;
V_2 -> V_61 = 921600 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_54;
V_2 -> V_79 = F_15 ( V_2 -> V_4 + 0x8D ) ;
V_2 -> V_58 -> V_62 ( V_2 ) ;
break;
default:
F_12 ( & V_2 -> V_8 -> V_52 ,
L_2 ) ;
V_3 = - V_80 ;
goto V_54;
}
F_16 ( & V_2 -> V_81 ,
V_2 -> V_58 -> V_82 ,
( unsigned long ) V_2 ) ;
F_17 ( & V_2 -> V_33 ) ;
return V_2 ;
V_54:
F_18 ( V_2 ) ;
return F_5 ( V_3 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_44 ) {
V_3 = F_20 ( V_2 -> V_44 , V_2 -> V_58 -> V_83 ,
V_84 , L_3 , V_2 ) ;
if ( V_3 ) {
F_12 ( & V_2 -> V_8 -> V_52 ,
L_4 , V_2 -> V_44 ) ;
V_2 -> V_36 = V_85 ;
V_2 -> V_31 = V_32 ;
V_3 = - V_53 ;
}
}
return V_3 ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 )
F_22 ( V_2 -> V_44 , V_2 ) ;
}
static void F_23 ( T_1 V_86 )
{
struct V_1 * V_2 ;
unsigned long V_87 ;
int V_11 ;
unsigned long V_88 ;
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
V_2 = V_1 [ V_11 ] ;
F_24 ( & V_2 -> V_34 , V_87 ) ;
if ( V_2 -> V_36 == V_85 ) {
F_25 ( & V_2 -> V_34 , V_87 ) ;
continue;
}
F_26 ( & V_2 -> V_81 ) ;
F_25 ( & V_2 -> V_34 , V_87 ) ;
}
F_24 ( & V_89 , V_87 ) ;
V_90 += F_27 ( V_91 ) ;
V_88 = V_90 - V_92 ;
if ( ( T_1 ) V_88 >= 2 * V_91 )
V_90 = V_92 + F_27 ( V_91 ) ;
F_28 ( & V_93 , F_23 , 0 ) ;
V_93 . V_94 = V_90 ;
F_25 ( & V_89 , V_87 ) ;
if ( ! V_95 )
F_29 ( & V_93 ) ;
}
static int F_30 ( struct V_7 * V_8 , const struct V_96 * V_97 )
{
int V_3 ;
struct V_1 * V_2 ;
V_3 = F_31 ( V_8 ) ;
if ( V_3 )
return - V_98 ;
V_2 = F_3 ( V_8 , V_97 -> V_99 ) ;
if ( F_32 ( V_2 ) )
return F_33 ( V_2 ) ;
V_3 = F_34 ( V_2 ) ;
if ( V_3 < 0 ) {
F_35 ( V_100 L_5 , V_3 ) ;
goto V_54;
}
V_3 = F_19 ( V_2 ) ;
if ( V_3 < 0 ) {
F_35 ( V_100 L_6 , V_3 ) ;
goto V_101;
}
V_3 = F_36 ( V_2 ) ;
if ( V_3 < 0 ) {
F_35 ( V_100 L_7 , V_3 ) ;
goto F_22;
}
V_2 -> V_36 = V_102 ;
V_2 -> V_31 = V_103 ;
V_1 [ V_16 ++ ] = V_2 ;
return 0 ;
F_22:
F_21 ( V_2 ) ;
V_101:
F_37 ( V_2 ) ;
V_54:
F_18 ( V_2 ) ;
return V_3 ;
}
static int F_38 ( void )
{
int V_3 = 0 ;
unsigned long V_87 ;
struct V_19 * V_52 ;
F_39 ( & V_93 ) ;
V_3 = F_40 ( 0 , L_8 , & V_104 ) ;
if ( V_3 < 0 ) {
F_35 ( V_100 L_9 , V_3 ) ;
return V_3 ;
}
V_105 = V_3 ;
V_106 = F_41 ( V_107 , L_10 ) ;
if ( F_32 ( V_106 ) ) {
V_3 = F_33 ( V_106 ) ;
F_35 ( V_100 L_11 , V_3 ) ;
goto V_108;
}
V_52 = F_42 ( V_106 , NULL ,
F_43 ( V_105 , 0 ) ,
NULL , L_10 ) ;
if ( F_32 ( V_52 ) ) {
V_3 = F_33 ( V_52 ) ;
F_35 ( V_100 L_12 , V_3 ) ;
goto V_109;
}
F_24 ( & V_89 , V_87 ) ;
F_28 ( & V_93 , F_23 , 0 ) ;
V_90 = V_92 + F_27 ( V_91 ) ;
V_93 . V_94 = V_90 ;
F_25 ( & V_89 , V_87 ) ;
F_29 ( & V_93 ) ;
return 0 ;
V_109:
F_44 ( V_106 ) ;
V_108:
F_45 ( V_105 , L_8 ) ;
return V_3 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
if ( ! V_2 || V_2 -> V_13 != V_14 )
return;
switch ( V_2 -> V_19 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
F_14 ( 0 , V_2 -> V_56 + 0x4c ) ;
break;
default:
break;
}
if ( V_2 -> V_44 )
F_22 ( V_2 -> V_44 , V_2 ) ;
F_47 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_4 ) {
F_48 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
for ( V_11 = 0 ; V_11 < V_110 ; V_11 ++ ) {
if ( V_2 -> V_111 [ V_11 ] ) {
F_18 ( V_2 -> V_111 [ V_11 ] -> V_112 ) ;
F_18 ( V_2 -> V_111 [ V_11 ] -> V_113 ) ;
F_18 ( V_2 -> V_111 [ V_11 ] -> V_114 ) ;
F_18 ( V_2 -> V_111 [ V_11 ] ) ;
V_2 -> V_111 [ V_11 ] = NULL ;
}
}
V_1 [ V_2 -> V_15 ] = NULL ;
F_18 ( V_2 ) ;
}
static void F_49 ( void )
{
int V_11 ;
unsigned long V_87 ;
F_24 ( & V_89 , V_87 ) ;
V_95 = 1 ;
F_25 ( & V_89 , V_87 ) ;
F_50 ( & V_93 ) ;
F_51 ( V_106 , F_43 ( V_105 , 0 ) ) ;
F_44 ( V_106 ) ;
F_45 ( V_105 , L_8 ) ;
for ( V_11 = 0 ; V_11 < V_16 ; ++ V_11 ) {
F_52 ( V_1 [ V_11 ] ) ;
F_46 ( V_1 [ V_11 ] ) ;
}
}
static void T_2 F_53 ( void )
{
F_49 () ;
F_54 ( & V_115 ) ;
}
static int T_3 F_55 ( void )
{
int V_3 ;
V_3 = F_38 () ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_56 ( & V_115 ) ;
if ( V_3 ) {
F_57 ( L_13 ) ;
F_49 () ;
return V_3 ;
}
return 0 ;
}
