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
static void F_12 ( struct V_11 * V_32 )
{
int V_2 = 0 ;
if ( ! V_32 || V_32 -> V_33 != V_34 )
return;
switch ( V_32 -> V_13 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_35 ( 0 , V_32 -> V_39 + 0x4c ) ;
break;
default:
break;
}
if ( V_32 -> V_40 )
F_36 ( V_32 -> V_40 , V_32 ) ;
F_37 ( & V_32 -> V_41 ) ;
if ( V_32 -> V_42 ) {
F_38 ( V_32 -> V_42 ) ;
V_32 -> V_42 = NULL ;
}
if ( V_32 -> V_43 ) {
unsigned long V_3 ;
F_2 ( & V_44 , V_3 ) ;
V_32 -> V_45 = NULL ;
F_39 ( & V_32 -> V_27 -> V_14 , L_8 , V_32 -> V_43 ) ;
F_40 ( V_32 -> V_43 ) ;
V_32 -> V_43 = NULL ;
F_3 ( & V_44 , V_3 ) ;
}
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ ) {
if ( V_32 -> V_47 [ V_2 ] ) {
F_40 ( V_32 -> V_47 [ V_2 ] -> V_48 ) ;
F_40 ( V_32 -> V_47 [ V_2 ] -> V_49 ) ;
F_40 ( V_32 -> V_47 [ V_2 ] -> V_50 ) ;
F_40 ( V_32 -> V_47 [ V_2 ] ) ;
V_32 -> V_47 [ V_2 ] = NULL ;
}
}
V_11 [ V_32 -> V_51 ] = NULL ;
F_40 ( V_32 ) ;
}
static int F_34 ( struct V_26 * V_27 , int V_52 )
{
struct V_11 * V_32 ;
unsigned int V_53 ;
int V_2 = 0 ;
int V_12 = 0 ;
unsigned long V_3 ;
V_11 [ V_10 ] = F_41 ( sizeof( * V_32 ) , V_54 ) ;
V_32 = V_11 [ V_10 ] ;
if ( ! V_32 )
return - V_55 ;
V_32 -> V_43 = F_42 ( 8192 , sizeof( V_56 ) , V_54 ) ;
V_32 -> V_45 = V_32 -> V_43 ;
if ( ! V_32 -> V_45 ) {
F_40 ( V_32 ) ;
return - V_55 ;
}
V_32 -> V_33 = V_34 ;
V_32 -> V_51 = V_10 ;
V_32 -> V_57 = V_58 [ V_52 ] . V_57 ;
V_32 -> V_13 = V_58 [ V_52 ] . V_13 ;
V_32 -> V_27 = V_27 ;
V_32 -> V_59 = V_27 -> V_60 -> V_61 ;
V_32 -> V_62 = F_43 ( V_27 -> V_63 ) ;
V_32 -> V_64 = V_65 [ V_52 ] . V_64 ;
V_32 -> V_66 = V_65 [ V_52 ] . V_66 ;
if ( V_65 [ V_2 ] . V_67 )
V_32 -> V_68 |= V_69 ;
V_32 -> V_70 = V_71 ;
F_44 ( & V_32 -> V_72 ) ;
F_45 ( & V_32 -> V_73 ) ;
F_45 ( & V_32 -> V_74 ) ;
V_32 -> V_75 = V_76 ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ )
V_32 -> V_47 [ V_2 ] = NULL ;
F_46 ( V_27 , V_77 , & V_32 -> V_78 ) ;
F_46 ( V_27 , V_79 , & V_32 -> V_80 ) ;
F_47 ( V_27 , V_81 , & V_32 -> V_82 ) ;
V_53 = V_27 -> V_40 ;
V_32 -> V_40 = V_53 ;
switch ( V_32 -> V_13 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_32 -> V_83 = V_84 | V_85 ;
V_32 -> V_86 = F_48 ( V_27 , 4 ) ;
if ( ! V_32 -> V_86 ) {
F_49 ( & V_32 -> V_27 -> V_14 ,
L_9 ) ;
return - V_87 ;
}
V_32 -> V_88 = F_50 ( V_27 , 4 ) ;
if ( V_32 -> V_86 & 1 )
V_32 -> V_86 &= ~ 3 ;
else
V_32 -> V_86 &= ~ 15 ;
V_32 -> V_39 = F_48 ( V_27 , 1 ) ;
V_32 -> V_89 = F_50 ( V_27 , 1 ) ;
V_32 -> V_39 = ( ( unsigned int ) ( V_32 -> V_39 ) ) & 0xFFFE ;
V_32 -> V_90 = & V_91 ;
V_32 -> V_92 = 0x8 ;
V_32 -> V_93 = 921600 ;
F_51 ( V_32 ) ;
V_32 -> V_90 -> V_94 ( V_32 ) ;
F_35 ( 0x43 , V_32 -> V_39 + 0x4c ) ;
break;
case V_95 :
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
if ( V_32 -> V_68 & V_69 )
V_32 -> V_83 = V_108 | V_85 ;
else
V_32 -> V_83 = V_109 | V_85 ;
V_32 -> V_86 = F_48 ( V_27 , 0 ) ;
V_32 -> V_88 = F_50 ( V_27 , 0 ) ;
if ( V_32 -> V_86 & 1 )
V_32 -> V_86 &= ~ 3 ;
else
V_32 -> V_86 &= ~ 15 ;
V_32 -> V_90 = & V_110 ;
V_32 -> V_92 = 0x200 ;
V_32 -> V_93 = 921600 ;
F_51 ( V_32 ) ;
if ( V_32 -> V_42 ) {
V_32 -> V_111 = F_52 ( V_32 -> V_42 + 0x8D ) ;
V_32 -> V_90 -> V_94 ( V_32 ) ;
}
break;
default:
F_49 ( & V_32 -> V_27 -> V_14 ,
L_10 ) ;
return - V_112 ;
}
V_12 = F_53 ( V_32 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_11 , V_12 ) ;
goto V_113;
}
V_12 = F_54 ( V_32 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_12 , V_12 ) ;
goto V_113;
}
V_12 = F_55 ( V_32 ) ;
if ( V_12 < 0 ) {
F_23 ( V_16 L_13 , V_12 ) ;
goto V_113;
}
V_32 -> V_75 = V_114 ;
V_32 -> V_70 = V_115 ;
F_56 ( V_32 ) ;
F_57 ( & V_32 -> V_41 ,
V_32 -> V_90 -> V_116 ,
( unsigned long ) V_32 ) ;
F_2 ( & V_44 , V_3 ) ;
V_32 -> V_45 = NULL ;
F_39 ( & V_32 -> V_27 -> V_14 , L_8 , V_32 -> V_43 ) ;
F_40 ( V_32 -> V_43 ) ;
V_32 -> V_43 = NULL ;
F_3 ( & V_44 , V_3 ) ;
F_58 ( & V_32 -> V_72 ) ;
return 0 ;
V_113:
F_11 ( V_32 ) ;
V_32 -> V_75 = V_117 ;
V_32 -> V_70 = V_71 ;
return - V_112 ;
}
static int F_54 ( struct V_11 * V_32 )
{
int V_12 = 0 ;
if ( ! V_32 || V_32 -> V_33 != V_34 )
return - V_87 ;
if ( V_32 -> V_40 ) {
V_12 = F_59 ( V_32 -> V_40 , V_32 -> V_90 -> V_118 ,
V_119 , L_14 , V_32 ) ;
if ( V_12 ) {
F_49 ( & V_32 -> V_27 -> V_14 ,
L_15 , V_32 -> V_40 ) ;
V_32 -> V_75 = V_117 ;
V_32 -> V_70 = V_71 ;
V_12 = - V_87 ;
}
}
return V_12 ;
}
static void F_51 ( struct V_11 * V_32 )
{
if ( ! V_32 || V_32 -> V_33 != V_34 )
return;
V_32 -> V_42 = F_60 ( V_32 -> V_86 , 0x1000 ) ;
}
static void V_21 ( T_2 V_120 )
{
struct V_11 * V_32 ;
unsigned long V_3 ;
int V_2 ;
unsigned long V_121 ;
for ( V_2 = 0 ; V_2 < V_10 ; V_2 ++ ) {
V_32 = V_11 [ V_2 ] ;
F_2 ( & V_32 -> V_73 , V_3 ) ;
if ( V_32 -> V_75 == V_117 ) {
F_3 ( & V_32 -> V_73 , V_3 ) ;
continue;
}
F_61 ( & V_32 -> V_41 ) ;
F_3 ( & V_32 -> V_73 , V_3 ) ;
}
F_2 ( & V_4 , V_3 ) ;
V_22 += F_30 ( V_24 ) ;
V_121 = V_22 - V_23 ;
if ( ( T_2 ) V_121 >= 2 * V_24 )
V_22 = V_23 + F_30 ( V_24 ) ;
F_29 ( & V_6 , V_21 , 0 ) ;
V_6 . V_25 = V_22 ;
F_3 ( & V_4 , V_3 ) ;
if ( ! V_5 )
F_31 ( & V_6 ) ;
}
