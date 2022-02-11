static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_3 ) {
F_2 ( V_2 -> V_7 , V_5 -> V_8 , V_5 -> V_9 ) ;
F_3 ( V_2 -> V_7 ) ;
} else
F_4 ( V_2 -> V_7 ) ;
}
static void F_5 ( struct V_10 * V_11 , int V_12 , int V_8 , int V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_8 *= F_6 ( V_11 ) ;
V_9 *= F_7 ( V_11 ) ;
if ( V_5 -> V_8 == V_8 && V_5 -> V_9 == V_9 && ( V_12 == V_14 ) == ! V_5 -> V_15 )
return;
V_5 -> V_15 = 0 ;
if ( V_5 -> V_3 )
F_1 ( V_2 , 0 ) ;
V_5 -> V_8 = V_8 - V_11 -> V_16 . V_17 ;
V_5 -> V_9 = V_9 - V_11 -> V_16 . V_18 ;
switch ( V_12 ) {
case V_14 :
V_5 -> V_3 = 0 ;
break;
case V_19 :
case V_20 :
if ( V_5 -> V_3 )
F_1 ( V_2 , V_5 -> V_3 ) ;
else
V_5 -> V_21 = V_22 ;
V_5 -> V_15 = 1 ;
break;
}
}
static int F_8 ( struct V_10 * V_11 , int V_23 , int V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 -> V_13 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 V_25 = ~ F_9 ( V_11 , V_11 -> V_26 , & V_2 -> V_2 ) ;
if ( V_23 > 64 || V_24 > 64 || V_23 < 0 || V_24 < 0 )
return - V_27 ;
V_5 -> V_24 = V_24 ;
V_5 -> V_23 = V_23 ;
F_10 ( V_2 -> V_7 , V_25 , V_23 , V_24 ) ;
return 1 ;
}
static void F_11 ( unsigned long V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_15 )
goto V_29;
if ( V_5 -> V_21 && -- V_5 -> V_21 == 0 ) {
V_5 -> V_3 ^= 1 ;
F_1 ( V_2 , V_5 -> V_3 ) ;
V_5 -> V_21 = V_5 -> V_30 ;
}
V_29:
V_5 -> V_31 . V_32 = V_33 + V_34 ;
F_12 ( & V_5 -> V_31 ) ;
}
static void T_2 F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_5 -> V_15 = 1 ;
V_5 -> V_3 = 1 ;
V_5 -> V_8 = V_5 -> V_9 = 0 ;
V_5 -> V_23 = V_5 -> V_24 = 0 ;
V_5 -> V_21 = V_22 ;
V_5 -> V_30 = V_35 ;
F_14 ( & V_5 -> V_31 ) ;
V_5 -> V_31 . V_28 = ( unsigned long ) V_2 ;
V_5 -> V_31 . V_36 = F_11 ;
F_15 ( & V_5 -> V_31 , V_33 + V_34 ) ;
}
static void T_3 F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
F_17 ( & V_5 -> V_31 ) ;
}
static void F_18 ( struct V_37 * V_38 )
{
* V_38 = V_39 ;
}
static int F_19 ( struct V_40 * V_41 , int V_42 ,
struct V_13 * V_2 )
{
struct V_1 * V_43 = (struct V_1 * ) V_2 ;
memset ( V_41 , 0 , sizeof( struct V_40 ) ) ;
strcpy ( V_41 -> V_44 , L_1 ) ;
V_41 -> V_45 = V_43 -> V_46 ;
V_41 -> V_47 = V_43 -> V_48 ;
V_41 -> type = V_49 ;
V_41 -> V_50 = 1 ;
V_41 -> V_51 = 1 ;
V_41 -> V_52 = V_53 ;
V_41 -> V_54 = 1280 ;
V_41 -> V_55 = V_56 ;
return 0 ;
}
static void F_20 ( struct V_10 * V_11 , int V_42 ,
struct V_1 * V_2 )
{
struct V_40 V_41 ;
V_11 -> V_13 = & V_2 -> V_2 ;
F_21 ( & V_11 -> V_16 , V_42 , & V_2 -> V_2 ) ;
if ( V_11 -> V_26 && V_11 -> V_26 -> V_57 && V_11 -> V_26 -> V_57 -> V_58 )
V_11 -> V_26 -> V_57 -> V_58 ( V_11 -> V_26 , V_14 ) ;
V_11 -> V_59 = & V_60 ;
V_11 -> V_61 = 0 ;
F_19 ( & V_41 , V_42 , & V_2 -> V_2 ) ;
V_11 -> V_62 = ( T_1 * ) V_41 . V_45 ;
V_11 -> V_52 = V_41 . V_52 ;
V_11 -> type = V_41 . type ;
V_11 -> V_63 = V_41 . V_63 ;
V_11 -> V_50 = V_41 . V_50 ;
V_11 -> V_51 = V_41 . V_51 ;
V_11 -> V_54 = V_41 . V_54 ;
V_11 -> V_64 = 2048 ;
V_11 -> V_65 = 1 ;
V_11 -> V_66 = 0 ;
V_11 -> V_67 = V_68 ;
F_8 ( V_11 , F_6 ( V_11 ) , F_7 ( V_11 ) ) ;
}
static int F_22 ( struct V_69 * V_70 , int V_71 , int V_42 ,
struct V_13 * V_2 )
{
static T_4 V_72 [ 2 ] = { 0x0000 , 0x000f } ;
static struct V_69 V_73 = { 0 , 2 , V_72 , V_72 , V_72 , NULL } ;
F_23 ( & V_73 , V_70 , V_71 ? 0 : 2 ) ;
return 0 ;
}
static int F_24 ( struct V_69 * V_70 , int V_71 , int V_42 ,
struct V_13 * V_2 )
{
T_4 V_72 [ 2 ] = { 0x0000 , 0x000f } ;
if ( V_70 -> V_74 == 0
&& V_70 -> V_75 == 2
&& memcmp ( V_70 -> V_76 , V_72 , sizeof( V_72 ) ) == 0
&& memcmp ( V_70 -> V_77 , V_72 , sizeof( V_72 ) ) == 0
&& memcmp ( V_70 -> V_78 , V_72 , sizeof( V_72 ) ) == 0
&& V_70 -> V_79 == NULL )
return 0 ;
else
return - V_27 ;
}
static int F_25 ( struct V_13 * V_2 , T_5 V_80 , unsigned long V_81 )
{
return - V_82 ;
}
static int F_26 ( int V_42 , struct V_13 * V_2 )
{
struct V_1 * V_43 = (struct V_1 * ) V_2 ;
struct V_10 * V_83 = ( V_84 < 0 ) ? & V_43 -> V_11 : ( V_85 + V_84 ) ;
struct V_10 * V_86 = ( V_42 < 0 ) ? & V_43 -> V_11 : ( V_85 + V_42 ) ;
if ( V_83 -> V_26 && V_83 -> V_26 -> V_57 && V_83 -> V_26 -> V_57 -> V_58 )
V_83 -> V_26 -> V_57 -> V_58 ( V_83 -> V_26 , V_14 ) ;
V_84 = V_42 ;
F_20 ( V_86 , V_42 , V_43 ) ;
return 0 ;
}
static void F_27 ( struct V_87 * V_16 ,
struct V_37 * V_38 )
{
V_16 -> V_88 = 1280 ;
V_16 -> V_89 = 1024 ;
V_16 -> V_90 = 2048 ;
V_16 -> V_91 = 1024 ;
V_16 -> V_17 = 0 ;
V_16 -> V_18 = 0 ;
V_16 -> V_92 = 8 ;
V_16 -> V_93 = 1 ;
V_16 -> V_76 . V_94 = 0 ;
V_16 -> V_76 . V_95 = 0 ;
V_16 -> V_76 . V_96 = 0 ;
V_16 -> V_77 . V_94 = 0 ;
V_16 -> V_77 . V_95 = 1 ;
V_16 -> V_77 . V_96 = 0 ;
V_16 -> V_78 . V_94 = 0 ;
V_16 -> V_78 . V_95 = 0 ;
V_16 -> V_78 . V_96 = 0 ;
V_16 -> V_79 . V_94 = 0 ;
V_16 -> V_79 . V_95 = 0 ;
V_16 -> V_79 . V_96 = 0 ;
V_16 -> V_97 = 0 ;
V_16 -> V_98 &= ~ V_99 & V_100 ;
V_16 -> V_101 = 0 ;
V_16 -> V_102 = V_103 ;
V_16 -> V_104 &= ~ V_105 & V_106 ;
}
static int F_28 ( struct V_87 * V_16 , int V_42 ,
struct V_13 * V_2 )
{
if ( V_42 < 0 ) {
struct V_37 V_38 ;
memset ( V_16 , 0 , sizeof( struct V_87 ) ) ;
F_18 ( & V_38 ) ;
F_27 ( V_16 , & V_38 ) ;
} else
* V_16 = V_2 -> V_16 ;
return 0 ;
}
static int F_21 ( struct V_87 * V_16 , int V_42 ,
struct V_13 * V_2 )
{
struct V_37 V_38 ;
F_18 ( & V_38 ) ;
F_27 ( V_16 , & V_38 ) ;
V_2 -> V_16 = * V_16 ;
return 0 ;
}
static int F_29 ( int V_42 , struct V_13 * V_2 )
{
struct V_1 * V_43 = (struct V_1 * ) V_2 ;
struct V_10 * V_11 = ( V_42 < 0 ) ? & V_43 -> V_11 : ( V_85 + V_42 ) ;
if ( V_42 == V_84 )
F_5 ( V_11 , V_14 , V_43 -> V_6 . V_8 , V_43 -> V_6 . V_9 ) ;
return 0 ;
}
static void F_30 ( int V_107 , struct V_13 * V_2 )
{
struct V_1 * V_43 = (struct V_1 * ) V_2 ;
T_1 V_108 = V_107 ? 0x00 : 0x0f ;
F_31 ( V_43 -> V_109 , 1 , V_108 , V_108 , V_108 ) ;
F_5 ( & V_43 -> V_11 , V_14 , V_43 -> V_6 . V_8 , V_43 -> V_6 . V_9 ) ;
}
static int T_2 F_32 ( int V_110 )
{
unsigned long V_111 = F_33 ( F_34 ( V_110 ) ) ;
struct V_1 * V_43 = & V_112 [ V_110 ] ;
memset ( V_43 , 0 , sizeof( struct V_1 ) ) ;
V_43 -> V_109 = (struct V_113 * ) ( V_111 + V_114 ) ;
V_43 -> V_7 = (struct V_115 * ) ( V_111 + V_116 ) ;
V_43 -> V_46 = V_111 + V_117 ;
V_43 -> V_48 = 2048 * 1024 ;
V_43 -> V_118 = 2048 ;
strcpy ( V_43 -> V_2 . V_119 , L_1 ) ;
V_43 -> V_2 . V_120 = - 1 ;
V_43 -> V_2 . V_121 = V_122 ;
V_43 -> V_2 . V_123 = & V_124 ;
V_43 -> V_2 . V_11 = & V_43 -> V_11 ;
V_43 -> V_2 . V_125 = NULL ;
V_43 -> V_2 . V_126 = & F_26 ;
V_43 -> V_2 . V_127 = & F_29 ;
V_43 -> V_2 . V_107 = & F_30 ;
F_20 ( & V_43 -> V_11 , V_84 , V_43 ) ;
F_35 ( V_43 -> V_109 ) ;
F_31 ( V_43 -> V_109 , 0 , 0x00 , 0x00 , 0x00 ) ;
F_31 ( V_43 -> V_109 , 1 , 0x0f , 0x0f , 0x0f ) ;
F_36 ( V_43 -> V_7 ) ;
F_13 ( V_43 ) ;
memset ( ( void * ) V_43 -> V_46 , 0 , V_43 -> V_48 ) ;
if ( F_37 ( & V_43 -> V_2 ) < 0 )
return - V_27 ;
F_38 ( V_128 L_2 ,
F_39 ( V_43 -> V_2 . V_120 ) , V_43 -> V_2 . V_119 , V_110 ) ;
return 0 ;
}
static int T_3 F_40 ( int V_110 )
{
struct V_1 * V_43 = & V_112 [ V_110 ] ;
if ( F_41 ( & V_43 -> V_2 ) < 0 )
return - V_27 ;
return 0 ;
}
int T_2 F_42 ( void )
{
int V_129 ;
int V_130 = 0 ;
while ( ( V_129 = F_43 ( L_1 ) ) >= 0 ) {
V_130 = 1 ;
F_44 ( V_129 ) ;
F_32 ( V_129 ) ;
}
return V_130 ? 0 : - V_131 ;
}
static void T_3 F_45 ( void )
{
int V_129 ;
while ( ( V_129 = F_43 ( L_1 ) ) >= 0 ) {
F_40 ( V_129 ) ;
F_46 ( V_129 ) ;
}
}
