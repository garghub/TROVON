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
F_20 () ;
V_11 = F_21 ( 0 , L_1 , & V_12 ) ;
if ( V_11 <= 0 ) {
F_22 ( V_13 L_3 , V_11 ) ;
return - V_14 ;
}
V_8 = V_11 ;
V_7 = F_23 ( V_15 , L_4 ) ;
F_24 ( V_7 , NULL ,
F_7 ( V_8 , 0 ) ,
NULL , L_4 ) ;
V_11 = F_25 () ;
if ( V_11 < 0 ) {
F_22 ( V_13 L_5 , V_11 ) ;
return V_11 ;
}
F_2 ( & V_3 , V_2 ) ;
F_26 ( & V_5 ) ;
V_5 . V_16 = V_17 ;
V_5 . V_18 = 0 ;
V_19 = V_20 + F_27 ( V_21 ) ;
V_5 . V_22 = V_19 ;
F_3 ( & V_3 , V_2 ) ;
F_28 ( & V_5 ) ;
return V_11 ;
}
static int F_29 ( struct V_23 * V_24 , const struct V_25 * V_26 )
{
int V_11 ;
V_11 = F_30 ( V_24 ) ;
if ( V_11 < 0 ) {
V_11 = - V_27 ;
} else {
V_11 = F_31 ( V_24 , V_26 -> V_28 ) ;
if ( V_11 == 0 )
V_9 ++ ;
}
return V_11 ;
}
static void F_12 ( struct V_29 * V_30 )
{
int V_1 = 0 ;
if ( ! V_30 || V_30 -> V_31 != V_32 )
return;
switch ( V_30 -> V_33 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
F_32 ( 0 , V_30 -> V_38 + 0x4c ) ;
break;
default:
break;
}
if ( V_30 -> V_39 )
F_33 ( V_30 -> V_39 , V_30 ) ;
F_34 ( & V_30 -> V_40 ) ;
if ( V_30 -> V_41 ) {
F_35 ( V_30 -> V_41 ) ;
V_30 -> V_41 = NULL ;
}
if ( V_30 -> V_42 ) {
unsigned long V_2 ;
F_2 ( & V_43 , V_2 ) ;
V_30 -> V_44 = NULL ;
F_36 ( L_6 , V_30 -> V_42 ) ;
F_37 ( V_30 -> V_42 ) ;
V_30 -> V_42 = NULL ;
F_3 ( & V_43 , V_2 ) ;
}
for ( V_1 = 0 ; V_1 < V_45 ; V_1 ++ ) {
if ( V_30 -> V_46 [ V_1 ] ) {
F_37 ( V_30 -> V_46 [ V_1 ] -> V_47 ) ;
F_37 ( V_30 -> V_46 [ V_1 ] -> V_48 ) ;
F_37 ( V_30 -> V_46 [ V_1 ] -> V_49 ) ;
F_37 ( V_30 -> V_46 [ V_1 ] ) ;
V_30 -> V_46 [ V_1 ] = NULL ;
}
}
F_37 ( V_30 -> V_50 ) ;
V_10 [ V_30 -> V_51 ] = NULL ;
F_37 ( V_30 ) ;
}
static int F_31 ( struct V_23 * V_24 , int V_52 )
{
struct V_29 * V_30 ;
unsigned int V_53 ;
int V_1 = 0 ;
int V_11 = 0 ;
unsigned long V_2 ;
V_10 [ V_9 ] = F_38 ( sizeof( * V_30 ) , V_54 ) ;
V_30 = V_10 [ V_9 ] ;
if ( ! V_30 )
return - V_55 ;
V_30 -> V_42 = F_38 ( sizeof( V_56 ) * 8192 , V_54 ) ;
V_30 -> V_44 = V_30 -> V_42 ;
if ( ! V_30 -> V_44 ) {
F_37 ( V_30 ) ;
return - V_55 ;
}
V_30 -> V_31 = V_32 ;
V_30 -> V_51 = V_9 ;
V_30 -> V_57 = V_58 [ V_52 ] . V_57 ;
V_30 -> V_33 = V_58 [ V_52 ] . V_33 ;
V_30 -> V_24 = V_24 ;
V_30 -> V_59 = V_24 -> V_60 -> V_61 ;
V_30 -> V_62 = F_39 ( V_24 -> V_63 ) ;
V_30 -> V_64 = V_65 [ V_52 ] . V_64 ;
V_30 -> V_66 = V_65 [ V_52 ] . V_66 ;
if ( V_65 [ V_1 ] . V_67 )
V_30 -> V_68 |= V_69 ;
V_30 -> V_70 = V_71 ;
F_40 ( & V_30 -> V_72 ) ;
F_41 ( & V_30 -> V_73 ) ;
F_41 ( & V_30 -> V_74 ) ;
V_30 -> V_75 = V_76 ;
for ( V_1 = 0 ; V_1 < V_45 ; V_1 ++ )
V_30 -> V_46 [ V_1 ] = NULL ;
F_42 ( V_24 , V_77 , & V_30 -> V_78 ) ;
F_42 ( V_24 , V_79 , & V_30 -> V_80 ) ;
F_43 ( V_24 , V_81 , & V_30 -> V_82 ) ;
V_53 = V_24 -> V_39 ;
V_30 -> V_39 = V_53 ;
switch ( V_30 -> V_33 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_30 -> V_83 = V_84 | V_85 ;
V_30 -> V_86 = F_44 ( V_24 , 4 ) ;
if ( ! V_30 -> V_86 ) {
F_45 ( & V_30 -> V_24 -> V_87 ,
L_7 ) ;
return - V_88 ;
}
V_30 -> V_89 = F_46 ( V_24 , 4 ) ;
if ( V_30 -> V_86 & 1 )
V_30 -> V_86 &= ~ 3 ;
else
V_30 -> V_86 &= ~ 15 ;
V_30 -> V_38 = F_44 ( V_24 , 1 ) ;
V_30 -> V_90 = F_46 ( V_24 , 1 ) ;
V_30 -> V_38 = ( ( unsigned int ) ( V_30 -> V_38 ) ) & 0xFFFE ;
V_30 -> V_91 = & V_92 ;
V_30 -> V_93 = 0x8 ;
V_30 -> V_94 = 921600 ;
F_47 ( V_30 ) ;
V_30 -> V_91 -> V_95 ( V_30 ) ;
F_32 ( 0x43 , V_30 -> V_38 + 0x4c ) ;
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
if ( V_30 -> V_68 & V_69 )
V_30 -> V_83 = V_109 | V_85 ;
else
V_30 -> V_83 = V_110 | V_85 ;
V_30 -> V_86 = F_44 ( V_24 , 0 ) ;
V_30 -> V_89 = F_46 ( V_24 , 0 ) ;
if ( V_30 -> V_86 & 1 )
V_30 -> V_86 &= ~ 3 ;
else
V_30 -> V_86 &= ~ 15 ;
V_30 -> V_91 = & V_111 ;
V_30 -> V_93 = 0x200 ;
V_30 -> V_94 = 921600 ;
F_47 ( V_30 ) ;
if ( V_30 -> V_41 ) {
V_30 -> V_112 = F_48 ( V_30 -> V_41 + 0x8D ) ;
V_30 -> V_91 -> V_95 ( V_30 ) ;
}
break;
default:
F_45 ( & V_30 -> V_24 -> V_87 ,
L_8 ) ;
return - V_14 ;
}
V_11 = F_49 ( V_30 ) ;
if ( V_11 < 0 ) {
F_11 ( V_30 ) ;
F_22 ( V_13 L_9 , V_11 ) ;
V_30 -> V_75 = V_113 ;
V_30 -> V_70 = V_71 ;
goto V_114;
}
V_11 = F_50 ( V_30 ) ;
if ( V_11 < 0 ) {
F_22 ( V_13 L_10 , V_11 ) ;
V_30 -> V_75 = V_113 ;
V_30 -> V_70 = V_71 ;
goto V_114;
}
V_11 = F_51 ( V_30 ) ;
if ( V_11 < 0 ) {
F_11 ( V_30 ) ;
F_22 ( V_13 L_11 , V_11 ) ;
V_30 -> V_75 = V_113 ;
V_30 -> V_70 = V_71 ;
goto V_114;
}
V_30 -> V_75 = V_115 ;
V_30 -> V_70 = V_116 ;
F_52 ( V_30 ) ;
F_53 ( & V_30 -> V_40 , V_30 -> V_91 -> V_117 , ( unsigned long ) V_30 ) ;
F_2 ( & V_43 , V_2 ) ;
V_30 -> V_44 = NULL ;
F_36 ( L_6 , V_30 -> V_42 ) ;
F_37 ( V_30 -> V_42 ) ;
V_30 -> V_42 = NULL ;
F_3 ( & V_43 , V_2 ) ;
V_30 -> V_50 = F_38 ( V_118 , V_54 ) ;
F_54 ( & V_30 -> V_72 ) ;
return 0 ;
V_114:
return - V_14 ;
}
static int F_50 ( struct V_29 * V_30 )
{
int V_11 = 0 ;
if ( ! V_30 || V_30 -> V_31 != V_32 )
return - V_88 ;
if ( V_30 -> V_39 ) {
V_11 = F_55 ( V_30 -> V_39 , V_30 -> V_91 -> V_119 ,
V_120 , L_12 , V_30 ) ;
if ( V_11 ) {
F_45 ( & V_30 -> V_24 -> V_87 ,
L_13 , V_30 -> V_39 ) ;
V_30 -> V_75 = V_113 ;
V_30 -> V_70 = V_71 ;
V_11 = - V_88 ;
}
}
return V_11 ;
}
static void F_47 ( struct V_29 * V_30 )
{
if ( ! V_30 || V_30 -> V_31 != V_32 )
return;
V_30 -> V_41 = F_56 ( V_30 -> V_86 , 0x1000 ) ;
}
static void V_17 ( T_2 V_121 )
{
struct V_29 * V_30 ;
unsigned long V_2 ;
int V_1 ;
unsigned long V_122 ;
for ( V_1 = 0 ; V_1 < V_9 ; V_1 ++ ) {
V_30 = V_10 [ V_1 ] ;
F_2 ( & V_30 -> V_73 , V_2 ) ;
if ( V_30 -> V_75 == V_113 ) {
F_3 ( & V_30 -> V_73 , V_2 ) ;
continue;
}
F_57 ( & V_30 -> V_40 ) ;
F_3 ( & V_30 -> V_73 , V_2 ) ;
}
F_2 ( & V_3 , V_2 ) ;
V_19 += F_27 ( V_21 ) ;
V_122 = V_19 - V_20 ;
if ( ( T_2 ) V_122 >= 2 * V_21 )
V_19 = V_20 + F_27 ( V_21 ) ;
F_26 ( & V_5 ) ;
V_5 . V_16 = V_17 ;
V_5 . V_18 = 0 ;
V_5 . V_22 = V_19 ;
F_3 ( & V_3 , V_2 ) ;
if ( ! V_4 )
F_28 ( & V_5 ) ;
}
static void F_20 ( void )
{
int V_1 = 0 ;
V_9 = 0 ;
for ( V_1 = 0 ; V_1 < V_123 ; V_1 ++ )
V_10 [ V_1 ] = NULL ;
F_26 ( & V_5 ) ;
}
