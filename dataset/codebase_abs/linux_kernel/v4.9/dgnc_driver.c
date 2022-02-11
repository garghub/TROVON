static void F_1 ( bool V_1 )
{
int V_2 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
V_5 = 1 ;
F_3 ( & V_4 , V_3 ) ;
F_4 ( & V_6 ) ;
if ( V_1 )
F_5 ( & V_7 ) ;
F_6 ( V_8 , F_7 ( V_9 , 0 ) ) ;
F_8 ( V_8 ) ;
F_9 ( V_9 , L_1 ) ;
for ( V_2 = 0 ; V_2 < V_10 ; ++ V_2 ) {
F_10 ( V_11 [ V_2 ] ) ;
F_11 ( V_11 [ V_2 ] ) ;
F_12 ( V_11 [ V_2 ] ) ;
}
F_13 () ;
}
static void T_1 F_14 ( void )
{
F_1 ( true ) ;
F_15 ( & V_7 ) ;
}
static int T_2 F_16 ( void )
{
int V_12 ;
V_12 = F_17 () ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_18 ( & V_7 ) ;
if ( V_12 ) {
F_19 ( L_2 ) ;
F_1 ( false ) ;
return V_12 ;
}
F_20 ( & V_7 ) ;
return 0 ;
}
static int F_17 ( void )
{
int V_12 = 0 ;
unsigned long V_3 ;
struct V_13 * V_14 ;
F_21 ( & V_6 ) ;
V_12 = F_22 ( 0 , L_1 , & V_15 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_3 , V_12 ) ;
return V_12 ;
}
V_9 = V_12 ;
V_8 = F_24 ( V_17 , L_4 ) ;
if ( F_25 ( V_8 ) ) {
V_12 = F_26 ( V_8 ) ;
F_23 ( V_16 L_5 , V_12 ) ;
goto V_18;
}
V_14 = F_27 ( V_8 , NULL ,
F_7 ( V_9 , 0 ) ,
NULL , L_4 ) ;
if ( F_25 ( V_14 ) ) {
V_12 = F_26 ( V_14 ) ;
F_23 ( V_16 L_6 , V_12 ) ;
goto V_19;
}
V_12 = F_28 () ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_7 , V_12 ) ;
goto V_20;
}
F_2 ( & V_4 , V_3 ) ;
F_29 ( & V_6 , V_21 , 0 ) ;
V_22 = V_23 + F_30 ( V_24 ) ;
V_6 . V_25 = V_22 ;
F_3 ( & V_4 , V_3 ) ;
F_31 ( & V_6 ) ;
return 0 ;
V_20:
F_6 ( V_8 , F_7 ( V_9 , 0 ) ) ;
V_19:
F_8 ( V_8 ) ;
V_18:
F_9 ( V_9 , L_1 ) ;
return V_12 ;
}
static int F_32 ( struct V_26 * V_27 , const struct V_28 * V_29 )
{
int V_12 ;
struct V_11 * V_30 ;
V_12 = F_33 ( V_27 ) ;
if ( V_12 )
return - V_31 ;
V_30 = F_34 ( V_27 , V_29 -> V_32 ) ;
if ( F_25 ( V_30 ) )
return F_26 ( V_30 ) ;
V_12 = F_35 ( V_30 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_8 , V_12 ) ;
goto V_33;
}
V_12 = F_36 ( V_30 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_9 , V_12 ) ;
goto V_34;
}
V_12 = F_37 ( V_30 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_10 , V_12 ) ;
goto V_35;
}
V_30 -> V_36 = V_37 ;
V_30 -> V_38 = V_39 ;
F_38 ( V_30 ) ;
V_11 [ V_10 ++ ] = V_30 ;
return 0 ;
V_35:
F_39 ( V_30 ) ;
V_34:
F_40 ( V_30 ) ;
V_33:
F_41 ( V_30 ) ;
return V_12 ;
}
static void F_12 ( struct V_11 * V_30 )
{
int V_2 = 0 ;
if ( ! V_30 || V_30 -> V_40 != V_41 )
return;
switch ( V_30 -> V_13 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
F_42 ( 0 , V_30 -> V_46 + 0x4c ) ;
break;
default:
break;
}
if ( V_30 -> V_47 )
V_35 ( V_30 -> V_47 , V_30 ) ;
F_43 ( & V_30 -> V_48 ) ;
if ( V_30 -> V_49 ) {
F_44 ( V_30 -> V_49 ) ;
V_30 -> V_49 = NULL ;
}
for ( V_2 = 0 ; V_2 < V_50 ; V_2 ++ ) {
if ( V_30 -> V_51 [ V_2 ] ) {
F_41 ( V_30 -> V_51 [ V_2 ] -> V_52 ) ;
F_41 ( V_30 -> V_51 [ V_2 ] -> V_53 ) ;
F_41 ( V_30 -> V_51 [ V_2 ] -> V_54 ) ;
F_41 ( V_30 -> V_51 [ V_2 ] ) ;
V_30 -> V_51 [ V_2 ] = NULL ;
}
}
V_11 [ V_30 -> V_55 ] = NULL ;
F_41 ( V_30 ) ;
}
static struct V_11 * F_34 ( struct V_26 * V_27 , int V_56 )
{
struct V_11 * V_30 ;
unsigned int V_57 ;
int V_2 = 0 ;
int V_12 = 0 ;
V_30 = F_45 ( sizeof( * V_30 ) , V_58 ) ;
if ( ! V_30 )
return F_46 ( - V_59 ) ;
V_30 -> V_40 = V_41 ;
V_30 -> V_55 = V_10 ;
V_30 -> V_60 = V_61 [ V_56 ] . V_60 ;
V_30 -> V_13 = V_61 [ V_56 ] . V_13 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_62 = V_27 -> V_63 -> V_64 ;
V_30 -> V_65 = F_47 ( V_27 -> V_66 ) ;
V_30 -> V_67 = V_68 [ V_56 ] . V_67 ;
V_30 -> V_69 = V_68 [ V_56 ] . V_69 ;
if ( V_68 [ V_2 ] . V_70 )
V_30 -> V_71 |= V_72 ;
V_30 -> V_38 = V_73 ;
F_48 ( & V_30 -> V_74 ) ;
F_49 ( & V_30 -> V_75 ) ;
F_49 ( & V_30 -> V_76 ) ;
V_30 -> V_36 = V_77 ;
F_50 ( V_27 , V_78 , & V_30 -> V_79 ) ;
F_50 ( V_27 , V_80 , & V_30 -> V_81 ) ;
F_51 ( V_27 , V_82 , & V_30 -> V_83 ) ;
V_57 = V_27 -> V_47 ;
V_30 -> V_47 = V_57 ;
switch ( V_30 -> V_13 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_30 -> V_84 = V_85 | V_86 ;
V_30 -> V_87 = F_52 ( V_27 , 4 ) ;
if ( ! V_30 -> V_87 ) {
F_53 ( & V_30 -> V_27 -> V_14 ,
L_11 ) ;
V_12 = - V_88 ;
goto V_33;
}
V_30 -> V_89 = F_54 ( V_27 , 4 ) ;
if ( V_30 -> V_87 & 1 )
V_30 -> V_87 &= ~ 3 ;
else
V_30 -> V_87 &= ~ 15 ;
V_30 -> V_46 = F_52 ( V_27 , 1 ) ;
V_30 -> V_90 = F_54 ( V_27 , 1 ) ;
V_30 -> V_46 = ( ( unsigned int ) ( V_30 -> V_46 ) ) & 0xFFFE ;
V_30 -> V_91 = & V_92 ;
V_30 -> V_93 = 0x8 ;
V_30 -> V_94 = 921600 ;
V_12 = F_55 ( V_30 ) ;
if ( V_12 < 0 )
goto V_33;
V_30 -> V_91 -> V_95 ( V_30 ) ;
F_42 ( 0x43 , V_30 -> V_46 + 0x4c ) ;
break;
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
if ( V_30 -> V_71 & V_72 )
V_30 -> V_84 = V_109 | V_86 ;
else
V_30 -> V_84 = V_110 | V_86 ;
V_30 -> V_87 = F_52 ( V_27 , 0 ) ;
V_30 -> V_89 = F_54 ( V_27 , 0 ) ;
if ( V_30 -> V_87 & 1 )
V_30 -> V_87 &= ~ 3 ;
else
V_30 -> V_87 &= ~ 15 ;
V_30 -> V_91 = & V_111 ;
V_30 -> V_93 = 0x200 ;
V_30 -> V_94 = 921600 ;
V_12 = F_55 ( V_30 ) ;
if ( V_12 < 0 )
goto V_33;
V_30 -> V_112 = F_56 ( V_30 -> V_49 + 0x8D ) ;
V_30 -> V_91 -> V_95 ( V_30 ) ;
break;
default:
F_53 ( & V_30 -> V_27 -> V_14 ,
L_12 ) ;
V_12 = - V_113 ;
goto V_33;
}
F_57 ( & V_30 -> V_48 ,
V_30 -> V_91 -> V_114 ,
( unsigned long ) V_30 ) ;
F_58 ( & V_30 -> V_74 ) ;
return V_30 ;
V_33:
F_41 ( V_30 ) ;
return F_46 ( V_12 ) ;
}
static int F_36 ( struct V_11 * V_30 )
{
int V_12 = 0 ;
if ( V_30 -> V_47 ) {
V_12 = F_59 ( V_30 -> V_47 , V_30 -> V_91 -> V_115 ,
V_116 , L_13 , V_30 ) ;
if ( V_12 ) {
F_53 ( & V_30 -> V_27 -> V_14 ,
L_14 , V_30 -> V_47 ) ;
V_30 -> V_36 = V_117 ;
V_30 -> V_38 = V_73 ;
V_12 = - V_88 ;
}
}
return V_12 ;
}
static void F_39 ( struct V_11 * V_30 )
{
if ( V_30 -> V_47 )
V_35 ( V_30 -> V_47 , V_30 ) ;
}
static int F_55 ( struct V_11 * V_30 )
{
int V_12 = 0 ;
V_30 -> V_49 = F_60 ( V_30 -> V_87 , 0x1000 ) ;
if ( ! V_30 -> V_49 )
V_12 = - V_59 ;
return V_12 ;
}
static void V_21 ( T_3 V_118 )
{
struct V_11 * V_30 ;
unsigned long V_3 ;
int V_2 ;
unsigned long V_119 ;
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ ) {
V_30 = V_11 [ V_2 ] ;
F_2 ( & V_30 -> V_75 , V_3 ) ;
if ( V_30 -> V_36 == V_117 ) {
F_3 ( & V_30 -> V_75 , V_3 ) ;
continue;
}
F_61 ( & V_30 -> V_48 ) ;
F_3 ( & V_30 -> V_75 , V_3 ) ;
}
F_2 ( & V_4 , V_3 ) ;
V_22 += F_30 ( V_24 ) ;
V_119 = V_22 - V_23 ;
if ( ( T_3 ) V_119 >= 2 * V_24 )
V_22 = V_23 + F_30 ( V_24 ) ;
F_29 ( & V_6 , V_21 , 0 ) ;
V_6 . V_25 = V_22 ;
F_3 ( & V_4 , V_3 ) ;
if ( ! V_5 )
F_31 ( & V_6 ) ;
}
