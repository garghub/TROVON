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
static void F_14 ( void )
{
F_1 ( true ) ;
F_15 ( & V_7 ) ;
}
static int T_1 F_16 ( void )
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
V_12 = F_33 ( V_27 ) ;
if ( V_12 )
return - V_30 ;
V_12 = F_34 ( V_27 , V_29 -> V_31 ) ;
if ( V_12 == 0 )
V_10 ++ ;
return V_12 ;
}
static void F_12 ( struct V_32 * V_33 )
{
int V_2 = 0 ;
if ( ! V_33 || V_33 -> V_34 != V_35 )
return;
switch ( V_33 -> V_13 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
F_35 ( 0 , V_33 -> V_40 + 0x4c ) ;
break;
default:
break;
}
if ( V_33 -> V_41 )
F_36 ( V_33 -> V_41 , V_33 ) ;
F_37 ( & V_33 -> V_42 ) ;
if ( V_33 -> V_43 ) {
F_38 ( V_33 -> V_43 ) ;
V_33 -> V_43 = NULL ;
}
if ( V_33 -> V_44 ) {
unsigned long V_3 ;
F_2 ( & V_45 , V_3 ) ;
V_33 -> V_46 = NULL ;
F_39 ( & V_33 -> V_27 -> V_14 , L_8 , V_33 -> V_44 ) ;
F_40 ( V_33 -> V_44 ) ;
V_33 -> V_44 = NULL ;
F_3 ( & V_45 , V_3 ) ;
}
for ( V_2 = 0 ; V_2 < V_47 ; V_2 ++ ) {
if ( V_33 -> V_48 [ V_2 ] ) {
F_40 ( V_33 -> V_48 [ V_2 ] -> V_49 ) ;
F_40 ( V_33 -> V_48 [ V_2 ] -> V_50 ) ;
F_40 ( V_33 -> V_48 [ V_2 ] -> V_51 ) ;
F_40 ( V_33 -> V_48 [ V_2 ] ) ;
V_33 -> V_48 [ V_2 ] = NULL ;
}
}
V_11 [ V_33 -> V_52 ] = NULL ;
F_40 ( V_33 ) ;
}
static int F_34 ( struct V_26 * V_27 , int V_53 )
{
struct V_32 * V_33 ;
unsigned int V_54 ;
int V_2 = 0 ;
int V_12 = 0 ;
unsigned long V_3 ;
V_11 [ V_10 ] = F_41 ( sizeof( * V_33 ) , V_55 ) ;
V_33 = V_11 [ V_10 ] ;
if ( ! V_33 )
return - V_56 ;
V_33 -> V_44 = F_42 ( 8192 , sizeof( V_57 ) , V_55 ) ;
V_33 -> V_46 = V_33 -> V_44 ;
if ( ! V_33 -> V_46 ) {
F_40 ( V_33 ) ;
return - V_56 ;
}
V_33 -> V_34 = V_35 ;
V_33 -> V_52 = V_10 ;
V_33 -> V_58 = V_59 [ V_53 ] . V_58 ;
V_33 -> V_13 = V_59 [ V_53 ] . V_13 ;
V_33 -> V_27 = V_27 ;
V_33 -> V_60 = V_27 -> V_61 -> V_62 ;
V_33 -> V_63 = F_43 ( V_27 -> V_64 ) ;
V_33 -> V_65 = V_66 [ V_53 ] . V_65 ;
V_33 -> V_67 = V_66 [ V_53 ] . V_67 ;
if ( V_66 [ V_2 ] . V_68 )
V_33 -> V_69 |= V_70 ;
V_33 -> V_71 = V_72 ;
F_44 ( & V_33 -> V_73 ) ;
F_45 ( & V_33 -> V_74 ) ;
F_45 ( & V_33 -> V_75 ) ;
V_33 -> V_76 = V_77 ;
for ( V_2 = 0 ; V_2 < V_47 ; V_2 ++ )
V_33 -> V_48 [ V_2 ] = NULL ;
F_46 ( V_27 , V_78 , & V_33 -> V_79 ) ;
F_46 ( V_27 , V_80 , & V_33 -> V_81 ) ;
F_47 ( V_27 , V_82 , & V_33 -> V_83 ) ;
V_54 = V_27 -> V_41 ;
V_33 -> V_41 = V_54 ;
switch ( V_33 -> V_13 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_33 -> V_84 = V_85 | V_86 ;
V_33 -> V_87 = F_48 ( V_27 , 4 ) ;
if ( ! V_33 -> V_87 ) {
F_49 ( & V_33 -> V_27 -> V_14 ,
L_9 ) ;
return - V_88 ;
}
V_33 -> V_89 = F_50 ( V_27 , 4 ) ;
if ( V_33 -> V_87 & 1 )
V_33 -> V_87 &= ~ 3 ;
else
V_33 -> V_87 &= ~ 15 ;
V_33 -> V_40 = F_48 ( V_27 , 1 ) ;
V_33 -> V_90 = F_50 ( V_27 , 1 ) ;
V_33 -> V_40 = ( ( unsigned int ) ( V_33 -> V_40 ) ) & 0xFFFE ;
V_33 -> V_91 = & V_92 ;
V_33 -> V_93 = 0x8 ;
V_33 -> V_94 = 921600 ;
F_51 ( V_33 ) ;
V_33 -> V_91 -> V_95 ( V_33 ) ;
F_35 ( 0x43 , V_33 -> V_40 + 0x4c ) ;
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
if ( V_33 -> V_69 & V_70 )
V_33 -> V_84 = V_109 | V_86 ;
else
V_33 -> V_84 = V_110 | V_86 ;
V_33 -> V_87 = F_48 ( V_27 , 0 ) ;
V_33 -> V_89 = F_50 ( V_27 , 0 ) ;
if ( V_33 -> V_87 & 1 )
V_33 -> V_87 &= ~ 3 ;
else
V_33 -> V_87 &= ~ 15 ;
V_33 -> V_91 = & V_111 ;
V_33 -> V_93 = 0x200 ;
V_33 -> V_94 = 921600 ;
F_51 ( V_33 ) ;
if ( V_33 -> V_43 ) {
V_33 -> V_112 = F_52 ( V_33 -> V_43 + 0x8D ) ;
V_33 -> V_91 -> V_95 ( V_33 ) ;
}
break;
default:
F_49 ( & V_33 -> V_27 -> V_14 ,
L_10 ) ;
return - V_113 ;
}
V_12 = F_53 ( V_33 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_11 , V_12 ) ;
goto V_114;
}
V_12 = F_54 ( V_33 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_12 , V_12 ) ;
goto V_114;
}
V_12 = F_55 ( V_33 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_13 , V_12 ) ;
goto V_114;
}
V_33 -> V_76 = V_115 ;
V_33 -> V_71 = V_116 ;
F_56 ( V_33 ) ;
F_57 ( & V_33 -> V_42 ,
V_33 -> V_91 -> V_117 ,
( unsigned long ) V_33 ) ;
F_2 ( & V_45 , V_3 ) ;
V_33 -> V_46 = NULL ;
F_39 ( & V_33 -> V_27 -> V_14 , L_8 , V_33 -> V_44 ) ;
F_40 ( V_33 -> V_44 ) ;
V_33 -> V_44 = NULL ;
F_3 ( & V_45 , V_3 ) ;
F_58 ( & V_33 -> V_73 ) ;
return 0 ;
V_114:
F_11 ( V_33 ) ;
V_33 -> V_76 = V_118 ;
V_33 -> V_71 = V_72 ;
return - V_113 ;
}
static int F_54 ( struct V_32 * V_33 )
{
int V_12 = 0 ;
if ( ! V_33 || V_33 -> V_34 != V_35 )
return - V_88 ;
if ( V_33 -> V_41 ) {
V_12 = F_59 ( V_33 -> V_41 , V_33 -> V_91 -> V_119 ,
V_120 , L_14 , V_33 ) ;
if ( V_12 ) {
F_49 ( & V_33 -> V_27 -> V_14 ,
L_15 , V_33 -> V_41 ) ;
V_33 -> V_76 = V_118 ;
V_33 -> V_71 = V_72 ;
V_12 = - V_88 ;
}
}
return V_12 ;
}
static void F_51 ( struct V_32 * V_33 )
{
if ( ! V_33 || V_33 -> V_34 != V_35 )
return;
V_33 -> V_43 = F_60 ( V_33 -> V_87 , 0x1000 ) ;
}
static void V_21 ( T_2 V_121 )
{
struct V_32 * V_33 ;
unsigned long V_3 ;
int V_2 ;
unsigned long V_122 ;
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ ) {
V_33 = V_11 [ V_2 ] ;
F_2 ( & V_33 -> V_74 , V_3 ) ;
if ( V_33 -> V_76 == V_118 ) {
F_3 ( & V_33 -> V_74 , V_3 ) ;
continue;
}
F_61 ( & V_33 -> V_42 ) ;
F_3 ( & V_33 -> V_74 , V_3 ) ;
}
F_2 ( & V_4 , V_3 ) ;
V_22 += F_30 ( V_24 ) ;
V_122 = V_22 - V_23 ;
if ( ( T_2 ) V_122 >= 2 * V_24 )
V_22 = V_23 + F_30 ( V_24 ) ;
F_29 ( & V_6 , V_21 , 0 ) ;
V_6 . V_25 = V_22 ;
F_3 ( & V_4 , V_3 ) ;
if ( ! V_5 )
F_31 ( & V_6 ) ;
}
