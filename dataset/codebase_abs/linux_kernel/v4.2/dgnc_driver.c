static void F_1 ( void )
{
int V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_4 = 1 ;
F_3 ( & V_3 , V_2 ) ;
F_4 ( & V_5 ) ;
F_5 ( & V_6 ) ;
F_6 ( V_7 , F_7 ( V_8 , 0 ) ) ;
F_8 ( V_7 ) ;
F_9 ( V_8 , L_1 ) ;
for ( V_1 = 0 ; V_1 < V_9 ; ++ V_1 ) {
F_10 ( V_10 [ V_1 ] ) ;
F_11 ( V_10 [ V_1 ] ) ;
F_12 ( V_10 [ V_1 ] ) ;
}
F_13 () ;
if ( V_9 )
F_14 ( & V_6 ) ;
}
static int T_1 F_15 ( void )
{
int V_11 = 0 ;
V_11 = F_16 () ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_17 ( & V_6 ) ;
if ( V_11 < 0 ) {
if ( V_9 )
F_14 ( & V_6 ) ;
else
F_18 ( L_2 ) ;
F_1 () ;
} else {
F_19 ( & V_6 ) ;
}
return V_11 ;
}
static int F_16 ( void )
{
int V_11 = 0 ;
unsigned long V_2 ;
struct V_12 * V_13 ;
F_20 () ;
V_11 = F_21 ( 0 , L_1 , & V_14 ) ;
if ( V_11 < 0 ) {
F_22 ( V_15 L_3 , V_11 ) ;
return V_11 ;
}
V_8 = V_11 ;
V_7 = F_23 ( V_16 , L_4 ) ;
if ( F_24 ( V_7 ) ) {
V_11 = F_25 ( V_7 ) ;
F_22 ( V_15 L_5 , V_11 ) ;
goto V_17;
}
V_13 = F_26 ( V_7 , NULL ,
F_7 ( V_8 , 0 ) ,
NULL , L_4 ) ;
if ( F_24 ( V_13 ) ) {
V_11 = F_25 ( V_13 ) ;
F_22 ( V_15 L_6 , V_11 ) ;
goto V_18;
}
V_11 = F_27 () ;
if ( V_11 < 0 ) {
F_22 ( V_15 L_7 , V_11 ) ;
goto V_19;
}
F_2 ( & V_3 , V_2 ) ;
F_28 ( & V_5 , V_20 , 0 ) ;
V_21 = V_22 + F_29 ( V_23 ) ;
V_5 . V_24 = V_21 ;
F_3 ( & V_3 , V_2 ) ;
F_30 ( & V_5 ) ;
return 0 ;
V_19:
F_6 ( V_7 , F_7 ( V_8 , 0 ) ) ;
V_18:
F_8 ( V_7 ) ;
V_17:
F_9 ( V_8 , L_1 ) ;
return V_11 ;
}
static int F_31 ( struct V_25 * V_26 , const struct V_27 * V_28 )
{
int V_11 ;
V_11 = F_32 ( V_26 ) ;
if ( V_11 < 0 ) {
V_11 = - V_29 ;
} else {
V_11 = F_33 ( V_26 , V_28 -> V_30 ) ;
if ( V_11 == 0 )
V_9 ++ ;
}
return V_11 ;
}
static void F_12 ( struct V_31 * V_32 )
{
int V_1 = 0 ;
if ( ! V_32 || V_32 -> V_33 != V_34 )
return;
switch ( V_32 -> V_12 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_34 ( 0 , V_32 -> V_39 + 0x4c ) ;
break;
default:
break;
}
if ( V_32 -> V_40 )
F_35 ( V_32 -> V_40 , V_32 ) ;
F_36 ( & V_32 -> V_41 ) ;
if ( V_32 -> V_42 ) {
F_37 ( V_32 -> V_42 ) ;
V_32 -> V_42 = NULL ;
}
if ( V_32 -> V_43 ) {
unsigned long V_2 ;
F_2 ( & V_44 , V_2 ) ;
V_32 -> V_45 = NULL ;
F_38 ( & V_32 -> V_26 -> V_13 , L_8 , V_32 -> V_43 ) ;
F_39 ( V_32 -> V_43 ) ;
V_32 -> V_43 = NULL ;
F_3 ( & V_44 , V_2 ) ;
}
for ( V_1 = 0 ; V_1 < V_46 ; V_1 ++ ) {
if ( V_32 -> V_47 [ V_1 ] ) {
F_39 ( V_32 -> V_47 [ V_1 ] -> V_48 ) ;
F_39 ( V_32 -> V_47 [ V_1 ] -> V_49 ) ;
F_39 ( V_32 -> V_47 [ V_1 ] -> V_50 ) ;
F_39 ( V_32 -> V_47 [ V_1 ] ) ;
V_32 -> V_47 [ V_1 ] = NULL ;
}
}
V_10 [ V_32 -> V_51 ] = NULL ;
F_39 ( V_32 ) ;
}
static int F_33 ( struct V_25 * V_26 , int V_52 )
{
struct V_31 * V_32 ;
unsigned int V_53 ;
int V_1 = 0 ;
int V_11 = 0 ;
unsigned long V_2 ;
V_10 [ V_9 ] = F_40 ( sizeof( * V_32 ) , V_54 ) ;
V_32 = V_10 [ V_9 ] ;
if ( ! V_32 )
return - V_55 ;
V_32 -> V_43 = F_41 ( 8192 , sizeof( V_56 ) , V_54 ) ;
V_32 -> V_45 = V_32 -> V_43 ;
if ( ! V_32 -> V_45 ) {
F_39 ( V_32 ) ;
return - V_55 ;
}
V_32 -> V_33 = V_34 ;
V_32 -> V_51 = V_9 ;
V_32 -> V_57 = V_58 [ V_52 ] . V_57 ;
V_32 -> V_12 = V_58 [ V_52 ] . V_12 ;
V_32 -> V_26 = V_26 ;
V_32 -> V_59 = V_26 -> V_60 -> V_61 ;
V_32 -> V_62 = F_42 ( V_26 -> V_63 ) ;
V_32 -> V_64 = V_65 [ V_52 ] . V_64 ;
V_32 -> V_66 = V_65 [ V_52 ] . V_66 ;
if ( V_65 [ V_1 ] . V_67 )
V_32 -> V_68 |= V_69 ;
V_32 -> V_70 = V_71 ;
F_43 ( & V_32 -> V_72 ) ;
F_44 ( & V_32 -> V_73 ) ;
F_44 ( & V_32 -> V_74 ) ;
V_32 -> V_75 = V_76 ;
for ( V_1 = 0 ; V_1 < V_46 ; V_1 ++ )
V_32 -> V_47 [ V_1 ] = NULL ;
F_45 ( V_26 , V_77 , & V_32 -> V_78 ) ;
F_45 ( V_26 , V_79 , & V_32 -> V_80 ) ;
F_46 ( V_26 , V_81 , & V_32 -> V_82 ) ;
V_53 = V_26 -> V_40 ;
V_32 -> V_40 = V_53 ;
switch ( V_32 -> V_12 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_32 -> V_83 = V_84 | V_85 ;
V_32 -> V_86 = F_47 ( V_26 , 4 ) ;
if ( ! V_32 -> V_86 ) {
F_48 ( & V_32 -> V_26 -> V_13 ,
L_9 ) ;
return - V_87 ;
}
V_32 -> V_88 = F_49 ( V_26 , 4 ) ;
if ( V_32 -> V_86 & 1 )
V_32 -> V_86 &= ~ 3 ;
else
V_32 -> V_86 &= ~ 15 ;
V_32 -> V_39 = F_47 ( V_26 , 1 ) ;
V_32 -> V_89 = F_49 ( V_26 , 1 ) ;
V_32 -> V_39 = ( ( unsigned int ) ( V_32 -> V_39 ) ) & 0xFFFE ;
V_32 -> V_90 = & V_91 ;
V_32 -> V_92 = 0x8 ;
V_32 -> V_93 = 921600 ;
F_50 ( V_32 ) ;
V_32 -> V_90 -> V_94 ( V_32 ) ;
F_34 ( 0x43 , V_32 -> V_39 + 0x4c ) ;
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
V_32 -> V_86 = F_47 ( V_26 , 0 ) ;
V_32 -> V_88 = F_49 ( V_26 , 0 ) ;
if ( V_32 -> V_86 & 1 )
V_32 -> V_86 &= ~ 3 ;
else
V_32 -> V_86 &= ~ 15 ;
V_32 -> V_90 = & V_110 ;
V_32 -> V_92 = 0x200 ;
V_32 -> V_93 = 921600 ;
F_50 ( V_32 ) ;
if ( V_32 -> V_42 ) {
V_32 -> V_111 = F_51 ( V_32 -> V_42 + 0x8D ) ;
V_32 -> V_90 -> V_94 ( V_32 ) ;
}
break;
default:
F_48 ( & V_32 -> V_26 -> V_13 ,
L_10 ) ;
return - V_112 ;
}
V_11 = F_52 ( V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_15 L_11 , V_11 ) ;
goto V_113;
}
V_11 = F_53 ( V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_15 L_12 , V_11 ) ;
goto V_113;
}
V_11 = F_54 ( V_32 ) ;
if ( V_11 < 0 ) {
F_22 ( V_15 L_13 , V_11 ) ;
goto V_113;
}
V_32 -> V_75 = V_114 ;
V_32 -> V_70 = V_115 ;
F_55 ( V_32 ) ;
F_56 ( & V_32 -> V_41 ,
V_32 -> V_90 -> V_116 ,
( unsigned long ) V_32 ) ;
F_2 ( & V_44 , V_2 ) ;
V_32 -> V_45 = NULL ;
F_38 ( & V_32 -> V_26 -> V_13 , L_8 , V_32 -> V_43 ) ;
F_39 ( V_32 -> V_43 ) ;
V_32 -> V_43 = NULL ;
F_3 ( & V_44 , V_2 ) ;
F_57 ( & V_32 -> V_72 ) ;
return 0 ;
V_113:
F_11 ( V_32 ) ;
V_32 -> V_75 = V_117 ;
V_32 -> V_70 = V_71 ;
return - V_112 ;
}
static int F_53 ( struct V_31 * V_32 )
{
int V_11 = 0 ;
if ( ! V_32 || V_32 -> V_33 != V_34 )
return - V_87 ;
if ( V_32 -> V_40 ) {
V_11 = F_58 ( V_32 -> V_40 , V_32 -> V_90 -> V_118 ,
V_119 , L_14 , V_32 ) ;
if ( V_11 ) {
F_48 ( & V_32 -> V_26 -> V_13 ,
L_15 , V_32 -> V_40 ) ;
V_32 -> V_75 = V_117 ;
V_32 -> V_70 = V_71 ;
V_11 = - V_87 ;
}
}
return V_11 ;
}
static void F_50 ( struct V_31 * V_32 )
{
if ( ! V_32 || V_32 -> V_33 != V_34 )
return;
V_32 -> V_42 = F_59 ( V_32 -> V_86 , 0x1000 ) ;
}
static void V_20 ( T_2 V_120 )
{
struct V_31 * V_32 ;
unsigned long V_2 ;
int V_1 ;
unsigned long V_121 ;
for ( V_1 = 0 ; V_1 < V_9 ; V_1 ++ ) {
V_32 = V_10 [ V_1 ] ;
F_2 ( & V_32 -> V_73 , V_2 ) ;
if ( V_32 -> V_75 == V_117 ) {
F_3 ( & V_32 -> V_73 , V_2 ) ;
continue;
}
F_60 ( & V_32 -> V_41 ) ;
F_3 ( & V_32 -> V_73 , V_2 ) ;
}
F_2 ( & V_3 , V_2 ) ;
V_21 += F_29 ( V_23 ) ;
V_121 = V_21 - V_22 ;
if ( ( T_2 ) V_121 >= 2 * V_23 )
V_21 = V_22 + F_29 ( V_23 ) ;
F_28 ( & V_5 , V_20 , 0 ) ;
V_5 . V_24 = V_21 ;
F_3 ( & V_3 , V_2 ) ;
if ( ! V_4 )
F_30 ( & V_5 ) ;
}
static void F_20 ( void )
{
int V_1 = 0 ;
V_9 = 0 ;
for ( V_1 = 0 ; V_1 < V_122 ; V_1 ++ )
V_10 [ V_1 ] = NULL ;
F_61 ( & V_5 ) ;
}
