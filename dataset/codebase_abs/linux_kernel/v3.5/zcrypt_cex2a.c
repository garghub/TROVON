static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned char * V_7 , * exp , * V_8 ;
int V_9 ;
V_9 = V_6 -> V_10 ;
if ( V_9 <= 128 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_4 -> V_14 = sizeof( * V_12 ) ;
V_12 -> V_15 . V_16 = V_17 ;
V_12 -> V_15 . V_18 = sizeof( * V_12 ) ;
V_12 -> V_19 = V_20 ;
V_7 = V_12 -> V_21 + sizeof( V_12 -> V_21 ) - V_9 ;
exp = V_12 -> V_22 + sizeof( V_12 -> V_22 ) - V_9 ;
V_8 = V_12 -> V_13 + sizeof( V_12 -> V_13 ) - V_9 ;
} else if ( V_9 <= 256 ) {
struct V_23 * V_24 = V_4 -> V_13 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_4 -> V_14 = sizeof( * V_24 ) ;
V_24 -> V_15 . V_16 = V_17 ;
V_24 -> V_15 . V_18 = sizeof( * V_24 ) ;
V_24 -> V_19 = V_25 ;
V_7 = V_24 -> V_21 + sizeof( V_24 -> V_21 ) - V_9 ;
exp = V_24 -> V_22 + sizeof( V_24 -> V_22 ) - V_9 ;
V_8 = V_24 -> V_13 + sizeof( V_24 -> V_13 ) - V_9 ;
} else {
struct V_26 * V_27 = V_4 -> V_13 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_4 -> V_14 = sizeof( * V_27 ) ;
V_27 -> V_15 . V_16 = V_17 ;
V_27 -> V_15 . V_18 = sizeof( * V_27 ) ;
V_27 -> V_19 = V_28 ;
V_7 = V_27 -> V_21 + sizeof( V_27 -> V_21 ) - V_9 ;
exp = V_27 -> V_22 + sizeof( V_27 -> V_22 ) - V_9 ;
V_8 = V_27 -> V_13 + sizeof( V_27 -> V_13 ) - V_9 ;
}
if ( F_2 ( V_7 , V_6 -> V_29 , V_9 ) ||
F_2 ( exp , V_6 -> V_30 , V_9 ) ||
F_2 ( V_8 , V_6 -> V_31 , V_9 ) )
return - V_32 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 )
{
int V_9 , V_35 , V_36 , V_37 , V_38 ;
unsigned char * V_39 , * V_40 , * V_41 , * V_42 , * V_43 , * V_8 ;
V_9 = V_34 -> V_10 ;
V_35 = V_9 / 2 ;
V_36 = V_9 / 2 + 8 ;
if ( V_2 -> V_44 == V_45 )
V_38 = 256 ;
else
V_38 = 128 ;
if ( V_36 > V_38 ) {
V_37 = V_36 - V_38 ;
V_36 = V_38 ;
} else
V_37 = 0 ;
if ( V_36 <= 64 ) {
struct V_46 * V_47 = V_4 -> V_13 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_4 -> V_14 = sizeof( * V_47 ) ;
V_47 -> V_15 . V_16 = V_17 ;
V_47 -> V_15 . V_18 = sizeof( * V_47 ) ;
V_47 -> V_19 = V_48 ;
V_39 = V_47 -> V_39 + sizeof( V_47 -> V_39 ) - V_36 ;
V_40 = V_47 -> V_40 + sizeof( V_47 -> V_40 ) - V_35 ;
V_41 = V_47 -> V_41 + sizeof( V_47 -> V_41 ) - V_36 ;
V_42 = V_47 -> V_42 + sizeof( V_47 -> V_42 ) - V_35 ;
V_43 = V_47 -> V_43 + sizeof( V_47 -> V_43 ) - V_36 ;
V_8 = V_47 -> V_13 + sizeof( V_47 -> V_13 ) - V_9 ;
} else if ( V_36 <= 128 ) {
struct V_49 * V_50 = V_4 -> V_13 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_4 -> V_14 = sizeof( * V_50 ) ;
V_50 -> V_15 . V_16 = V_17 ;
V_50 -> V_15 . V_18 = sizeof( * V_50 ) ;
V_50 -> V_19 = V_51 ;
V_39 = V_50 -> V_39 + sizeof( V_50 -> V_39 ) - V_36 ;
V_40 = V_50 -> V_40 + sizeof( V_50 -> V_40 ) - V_35 ;
V_41 = V_50 -> V_41 + sizeof( V_50 -> V_41 ) - V_36 ;
V_42 = V_50 -> V_42 + sizeof( V_50 -> V_42 ) - V_35 ;
V_43 = V_50 -> V_43 + sizeof( V_50 -> V_43 ) - V_36 ;
V_8 = V_50 -> V_13 + sizeof( V_50 -> V_13 ) - V_9 ;
} else {
struct V_52 * V_53 = V_4 -> V_13 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_4 -> V_14 = sizeof( * V_53 ) ;
V_53 -> V_15 . V_16 = V_17 ;
V_53 -> V_15 . V_18 = sizeof( * V_53 ) ;
V_53 -> V_19 = V_54 ;
V_39 = V_53 -> V_39 + sizeof( V_53 -> V_39 ) - V_36 ;
V_40 = V_53 -> V_40 + sizeof( V_53 -> V_40 ) - V_35 ;
V_41 = V_53 -> V_41 + sizeof( V_53 -> V_41 ) - V_36 ;
V_42 = V_53 -> V_42 + sizeof( V_53 -> V_42 ) - V_35 ;
V_43 = V_53 -> V_43 + sizeof( V_53 -> V_43 ) - V_36 ;
V_8 = V_53 -> V_13 + sizeof( V_53 -> V_13 ) - V_9 ;
}
if ( F_2 ( V_39 , V_34 -> V_55 + V_37 , V_36 ) ||
F_2 ( V_40 , V_34 -> V_56 , V_35 ) ||
F_2 ( V_41 , V_34 -> V_57 + V_37 , V_36 ) ||
F_2 ( V_42 , V_34 -> V_58 , V_35 ) ||
F_2 ( V_43 , V_34 -> V_59 + V_37 , V_36 ) ||
F_2 ( V_8 , V_34 -> V_31 , V_9 ) )
return - V_32 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_60 ,
char T_1 * V_61 ,
unsigned int V_62 )
{
struct V_63 * V_64 = V_60 -> V_13 ;
unsigned char * V_65 ;
if ( V_64 -> V_66 < sizeof( * V_64 ) + V_62 ) {
V_2 -> V_67 = 0 ;
return - V_68 ;
}
if ( V_2 -> V_69 == V_70 )
F_5 ( V_64 -> V_66 > V_71 ) ;
else
F_5 ( V_64 -> V_66 > V_72 ) ;
V_65 = V_60 -> V_13 + V_64 -> V_66 - V_62 ;
if ( F_6 ( V_61 , V_65 , V_62 ) )
return - V_32 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_60 ,
char T_1 * V_61 ,
unsigned int V_62 )
{
switch ( ( ( unsigned char * ) V_60 -> V_13 ) [ 1 ] ) {
case V_73 :
case V_74 :
return F_8 ( V_2 , V_60 ) ;
case V_75 :
return F_4 ( V_2 , V_60 ,
V_61 , V_62 ) ;
default:
V_2 -> V_67 = 0 ;
return - V_68 ;
}
}
static void F_9 ( struct V_76 * V_77 ,
struct V_3 * V_78 ,
struct V_3 * V_60 )
{
static struct V_79 V_80 = {
. type = V_73 ,
. V_81 = V_82 ,
} ;
struct V_63 * V_64 ;
int V_14 ;
if ( F_10 ( V_60 ) ) {
memcpy ( V_78 -> V_13 , & V_80 , sizeof( V_80 ) ) ;
goto V_83;
}
V_64 = V_60 -> V_13 ;
if ( V_64 -> type == V_75 ) {
if ( V_77 -> V_84 == V_85 )
V_14 = F_11 ( V_71 , ( int ) V_64 -> V_66 ) ;
else
V_14 = F_11 ( V_72 , ( int ) V_64 -> V_66 ) ;
memcpy ( V_78 -> V_13 , V_60 -> V_13 , V_14 ) ;
} else
memcpy ( V_78 -> V_13 , V_60 -> V_13 , sizeof V_80 ) ;
V_83:
F_12 ( (struct V_86 * ) V_78 -> V_87 ) ;
}
static long F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 V_4 ;
struct V_86 V_88 ;
int V_89 ;
F_14 ( & V_4 ) ;
if ( V_2 -> V_69 == V_70 )
V_4 . V_13 = F_15 ( V_90 , V_91 ) ;
else
V_4 . V_13 = F_15 ( V_92 , V_91 ) ;
if ( ! V_4 . V_13 )
return - V_93 ;
V_4 . V_94 = F_9 ;
V_4 . V_95 = ( ( ( unsigned long long ) V_96 -> V_97 ) << 32 ) +
F_16 ( & V_98 ) ;
V_4 . V_87 = & V_88 ;
V_89 = F_1 ( V_2 , & V_4 , V_6 ) ;
if ( V_89 )
goto V_99;
F_17 ( & V_88 ) ;
F_18 ( V_2 -> V_77 , & V_4 ) ;
V_89 = F_19 ( & V_88 ) ;
if ( V_89 == 0 )
V_89 = F_7 ( V_2 , & V_4 , V_6 -> V_61 ,
V_6 -> V_62 ) ;
else
F_20 ( V_2 -> V_77 , & V_4 ) ;
V_99:
F_21 ( V_4 . V_13 ) ;
return V_89 ;
}
static long F_22 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_3 V_4 ;
struct V_86 V_88 ;
int V_89 ;
F_14 ( & V_4 ) ;
if ( V_2 -> V_69 == V_70 )
V_4 . V_13 = F_15 ( V_90 , V_91 ) ;
else
V_4 . V_13 = F_15 ( V_92 , V_91 ) ;
if ( ! V_4 . V_13 )
return - V_93 ;
V_4 . V_94 = F_9 ;
V_4 . V_95 = ( ( ( unsigned long long ) V_96 -> V_97 ) << 32 ) +
F_16 ( & V_98 ) ;
V_4 . V_87 = & V_88 ;
V_89 = F_3 ( V_2 , & V_4 , V_34 ) ;
if ( V_89 )
goto V_99;
F_17 ( & V_88 ) ;
F_18 ( V_2 -> V_77 , & V_4 ) ;
V_89 = F_19 ( & V_88 ) ;
if ( V_89 == 0 )
V_89 = F_7 ( V_2 , & V_4 , V_34 -> V_61 ,
V_34 -> V_62 ) ;
else
F_20 ( V_2 -> V_77 , & V_4 ) ;
V_99:
F_21 ( V_4 . V_13 ) ;
return V_89 ;
}
static int F_23 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = NULL ;
int V_89 = 0 ;
switch ( V_77 -> V_84 ) {
case V_85 :
V_2 = F_24 ( V_71 ) ;
if ( ! V_2 )
return - V_93 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_100 = L_1 ;
V_2 -> V_101 = V_102 ;
V_2 -> V_44 = V_103 ;
V_2 -> V_104 = 1 ;
V_2 -> V_105 = V_106 ;
V_2 -> V_107 = V_103 ;
break;
case V_108 :
V_2 = F_24 ( V_72 ) ;
if ( ! V_2 )
return - V_93 ;
V_2 -> V_69 = V_109 ;
V_2 -> V_100 = L_2 ;
V_2 -> V_101 = V_102 ;
V_2 -> V_44 = V_103 ;
V_2 -> V_107 = V_103 ;
if ( F_25 ( V_77 -> V_110 ) ) {
V_2 -> V_44 = V_45 ;
V_2 -> V_107 = V_45 ;
}
V_2 -> V_104 = 1 ;
V_2 -> V_105 = V_111 ;
break;
}
if ( V_2 != NULL ) {
V_2 -> V_77 = V_77 ;
V_2 -> V_112 = & V_113 ;
V_2 -> V_67 = 1 ;
V_77 -> V_60 = & V_2 -> V_60 ;
V_77 -> V_87 = V_2 ;
V_89 = F_26 ( V_2 ) ;
}
if ( V_89 ) {
V_77 -> V_87 = NULL ;
F_27 ( V_2 ) ;
}
return V_89 ;
}
static void F_28 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_87 ;
F_29 ( V_2 ) ;
}
int T_2 F_30 ( void )
{
return F_31 ( & V_114 , V_115 , L_3 ) ;
}
void T_3 F_32 ( void )
{
F_33 ( & V_114 ) ;
}
