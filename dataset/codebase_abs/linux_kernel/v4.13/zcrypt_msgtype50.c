unsigned int F_1 ( struct V_1 * V_2 , int * V_3 )
{
if ( ! V_2 -> V_4 )
return - V_5 ;
if ( V_2 -> V_4 <= 128 )
* V_3 = V_6 ;
else if ( V_2 -> V_4 <= 256 )
* V_3 = V_7 ;
else
* V_3 = V_8 ;
return 0 ;
}
unsigned int F_2 ( struct V_9 * V_10 , int * V_3 )
{
if ( ! V_10 -> V_4 )
return - V_5 ;
if ( V_10 -> V_4 <= 128 )
* V_3 = V_11 ;
else if ( V_10 -> V_4 <= 256 )
* V_3 = V_12 ;
else
* V_3 = V_13 ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_1 * V_2 )
{
unsigned char * V_18 , * exp , * V_19 ;
int V_20 ;
V_20 = V_2 -> V_4 ;
if ( V_20 <= 128 ) {
struct V_21 * V_22 = V_17 -> V_23 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_17 -> V_24 = sizeof( * V_22 ) ;
V_22 -> V_25 . V_26 = V_27 ;
V_22 -> V_25 . V_28 = sizeof( * V_22 ) ;
V_22 -> V_29 = V_30 ;
V_18 = V_22 -> V_31 + sizeof( V_22 -> V_31 ) - V_20 ;
exp = V_22 -> V_32 + sizeof( V_22 -> V_32 ) - V_20 ;
V_19 = V_22 -> V_23 + sizeof( V_22 -> V_23 ) - V_20 ;
} else if ( V_20 <= 256 ) {
struct V_33 * V_34 = V_17 -> V_23 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_17 -> V_24 = sizeof( * V_34 ) ;
V_34 -> V_25 . V_26 = V_27 ;
V_34 -> V_25 . V_28 = sizeof( * V_34 ) ;
V_34 -> V_29 = V_35 ;
V_18 = V_34 -> V_31 + sizeof( V_34 -> V_31 ) - V_20 ;
exp = V_34 -> V_32 + sizeof( V_34 -> V_32 ) - V_20 ;
V_19 = V_34 -> V_23 + sizeof( V_34 -> V_23 ) - V_20 ;
} else {
struct V_36 * V_37 = V_17 -> V_23 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_17 -> V_24 = sizeof( * V_37 ) ;
V_37 -> V_25 . V_26 = V_27 ;
V_37 -> V_25 . V_28 = sizeof( * V_37 ) ;
V_37 -> V_29 = V_38 ;
V_18 = V_37 -> V_31 + sizeof( V_37 -> V_31 ) - V_20 ;
exp = V_37 -> V_32 + sizeof( V_37 -> V_32 ) - V_20 ;
V_19 = V_37 -> V_23 + sizeof( V_37 -> V_23 ) - V_20 ;
}
if ( F_4 ( V_18 , V_2 -> V_39 , V_20 ) ||
F_4 ( exp , V_2 -> V_40 , V_20 ) ||
F_4 ( V_19 , V_2 -> V_41 , V_20 ) )
return - V_42 ;
return 0 ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_9 * V_10 )
{
int V_20 , V_43 ;
unsigned char * V_44 , * V_45 , * V_46 , * V_47 , * V_48 , * V_19 ;
V_20 = V_10 -> V_4 ;
V_43 = ( V_20 + 1 ) / 2 ;
if ( V_20 <= 128 ) {
struct V_49 * V_50 = V_17 -> V_23 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_17 -> V_24 = sizeof( * V_50 ) ;
V_50 -> V_25 . V_26 = V_27 ;
V_50 -> V_25 . V_28 = sizeof( * V_50 ) ;
V_50 -> V_29 = V_51 ;
V_44 = V_50 -> V_44 + sizeof( V_50 -> V_44 ) - V_43 ;
V_45 = V_50 -> V_45 + sizeof( V_50 -> V_45 ) - V_43 ;
V_46 = V_50 -> V_46 + sizeof( V_50 -> V_46 ) - V_43 ;
V_47 = V_50 -> V_47 + sizeof( V_50 -> V_47 ) - V_43 ;
V_48 = V_50 -> V_48 + sizeof( V_50 -> V_48 ) - V_43 ;
V_19 = V_50 -> V_23 + sizeof( V_50 -> V_23 ) - V_20 ;
} else if ( V_20 <= 256 ) {
struct V_52 * V_53 = V_17 -> V_23 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_17 -> V_24 = sizeof( * V_53 ) ;
V_53 -> V_25 . V_26 = V_27 ;
V_53 -> V_25 . V_28 = sizeof( * V_53 ) ;
V_53 -> V_29 = V_54 ;
V_44 = V_53 -> V_44 + sizeof( V_53 -> V_44 ) - V_43 ;
V_45 = V_53 -> V_45 + sizeof( V_53 -> V_45 ) - V_43 ;
V_46 = V_53 -> V_46 + sizeof( V_53 -> V_46 ) - V_43 ;
V_47 = V_53 -> V_47 + sizeof( V_53 -> V_47 ) - V_43 ;
V_48 = V_53 -> V_48 + sizeof( V_53 -> V_48 ) - V_43 ;
V_19 = V_53 -> V_23 + sizeof( V_53 -> V_23 ) - V_20 ;
} else if ( ( V_20 <= 512 ) &&
( V_15 -> V_55 -> V_56 == V_57 ) ) {
struct V_58 * V_59 = V_17 -> V_23 ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_17 -> V_24 = sizeof( * V_59 ) ;
V_59 -> V_25 . V_26 = V_27 ;
V_59 -> V_25 . V_28 = sizeof( * V_59 ) ;
V_59 -> V_29 = V_60 ;
V_44 = V_59 -> V_44 + sizeof( V_59 -> V_44 ) - V_43 ;
V_45 = V_59 -> V_45 + sizeof( V_59 -> V_45 ) - V_43 ;
V_46 = V_59 -> V_46 + sizeof( V_59 -> V_46 ) - V_43 ;
V_47 = V_59 -> V_47 + sizeof( V_59 -> V_47 ) - V_43 ;
V_48 = V_59 -> V_48 + sizeof( V_59 -> V_48 ) - V_43 ;
V_19 = V_59 -> V_23 + sizeof( V_59 -> V_23 ) - V_20 ;
} else
return - V_5 ;
if ( F_4 ( V_44 , V_10 -> V_61 + V_62 , V_43 ) ||
F_4 ( V_45 , V_10 -> V_63 , V_43 ) ||
F_4 ( V_46 , V_10 -> V_64 + V_62 , V_43 ) ||
F_4 ( V_47 , V_10 -> V_65 , V_43 ) ||
F_4 ( V_48 , V_10 -> V_66 + V_62 , V_43 ) ||
F_4 ( V_19 , V_10 -> V_41 , V_20 ) )
return - V_42 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_16 * V_67 ,
char T_1 * V_68 ,
unsigned int V_69 )
{
struct V_70 * V_71 = V_67 -> V_23 ;
unsigned char * V_72 ;
if ( V_71 -> V_73 < sizeof( * V_71 ) + V_69 ) {
V_15 -> V_74 = 0 ;
F_7 ( L_1 ,
F_8 ( V_15 -> V_75 -> V_76 ) ,
F_9 ( V_15 -> V_75 -> V_76 ) ) ;
F_10 ( V_77 ,
L_2 ,
F_8 ( V_15 -> V_75 -> V_76 ) ,
F_9 ( V_15 -> V_75 -> V_76 ) ,
V_71 -> V_78 ) ;
return - V_79 ;
}
if ( V_15 -> V_55 -> V_80 == V_81 )
F_11 ( V_71 -> V_73 > V_82 ) ;
else
F_11 ( V_71 -> V_73 > V_83 ) ;
V_72 = V_67 -> V_23 + V_71 -> V_73 - V_69 ;
if ( F_12 ( V_68 , V_72 , V_69 ) )
return - V_42 ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_16 * V_67 ,
char T_1 * V_68 ,
unsigned int V_69 )
{
unsigned char V_84 = ( ( unsigned char * ) V_67 -> V_23 ) [ 1 ] ;
switch ( V_84 ) {
case V_85 :
case V_86 :
return F_14 ( V_15 , V_67 ) ;
case V_87 :
return F_6 ( V_15 , V_67 ,
V_68 , V_69 ) ;
default:
V_15 -> V_74 = 0 ;
F_7 ( L_1 ,
F_8 ( V_15 -> V_75 -> V_76 ) ,
F_9 ( V_15 -> V_75 -> V_76 ) ) ;
F_10 ( V_77 ,
L_3 ,
F_8 ( V_15 -> V_75 -> V_76 ) ,
F_9 ( V_15 -> V_75 -> V_76 ) ,
( unsigned int ) V_84 ) ;
return - V_79 ;
}
}
static void F_15 ( struct V_88 * V_89 ,
struct V_16 * V_90 ,
struct V_16 * V_67 )
{
static struct V_91 V_92 = {
. type = V_85 ,
. V_93 = V_94 ,
} ;
struct V_70 * V_71 ;
int V_24 ;
if ( ! V_67 )
goto V_95;
V_71 = V_67 -> V_23 ;
if ( V_71 -> type == V_87 ) {
if ( V_89 -> V_96 . V_97 == V_98 )
V_24 = F_16 ( int ,
V_82 , V_71 -> V_73 ) ;
else
V_24 = F_16 ( int ,
V_83 , V_71 -> V_73 ) ;
memcpy ( V_90 -> V_23 , V_67 -> V_23 , V_24 ) ;
} else
memcpy ( V_90 -> V_23 , V_67 -> V_23 , sizeof( V_92 ) ) ;
V_95:
F_17 ( (struct V_99 * ) V_90 -> V_100 ) ;
}
static long F_18 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_16 V_17 ;
struct V_99 V_101 ;
int V_102 ;
F_19 ( & V_17 ) ;
if ( V_15 -> V_55 -> V_80 == V_81 )
V_17 . V_23 = F_20 ( V_103 ,
V_104 ) ;
else
V_17 . V_23 = F_20 ( V_105 ,
V_104 ) ;
if ( ! V_17 . V_23 )
return - V_106 ;
V_17 . V_107 = F_15 ;
V_17 . V_108 = ( ( ( unsigned long long ) V_109 -> V_110 ) << 32 ) +
F_21 ( & V_111 ) ;
V_17 . V_100 = & V_101 ;
V_102 = F_3 ( V_15 , & V_17 , V_2 ) ;
if ( V_102 )
goto V_112;
F_22 ( & V_101 ) ;
F_23 ( V_15 -> V_75 , & V_17 ) ;
V_102 = F_24 ( & V_101 ) ;
if ( V_102 == 0 ) {
V_102 = V_17 . V_102 ;
if ( V_102 == 0 )
V_102 = F_13 ( V_15 , & V_17 , V_2 -> V_68 ,
V_2 -> V_69 ) ;
} else
F_25 ( V_15 -> V_75 , & V_17 ) ;
V_112:
F_26 ( V_17 . V_23 ) ;
return V_102 ;
}
static long F_27 ( struct V_14 * V_15 ,
struct V_9 * V_10 )
{
struct V_16 V_17 ;
struct V_99 V_101 ;
int V_102 ;
F_19 ( & V_17 ) ;
if ( V_15 -> V_55 -> V_80 == V_81 )
V_17 . V_23 = F_20 ( V_103 ,
V_104 ) ;
else
V_17 . V_23 = F_20 ( V_105 ,
V_104 ) ;
if ( ! V_17 . V_23 )
return - V_106 ;
V_17 . V_107 = F_15 ;
V_17 . V_108 = ( ( ( unsigned long long ) V_109 -> V_110 ) << 32 ) +
F_21 ( & V_111 ) ;
V_17 . V_100 = & V_101 ;
V_102 = F_5 ( V_15 , & V_17 , V_10 ) ;
if ( V_102 )
goto V_112;
F_22 ( & V_101 ) ;
F_23 ( V_15 -> V_75 , & V_17 ) ;
V_102 = F_24 ( & V_101 ) ;
if ( V_102 == 0 ) {
V_102 = V_17 . V_102 ;
if ( V_102 == 0 )
V_102 = F_13 ( V_15 , & V_17 , V_10 -> V_68 ,
V_10 -> V_69 ) ;
} else
F_25 ( V_15 -> V_75 , & V_17 ) ;
V_112:
F_26 ( V_17 . V_23 ) ;
return V_102 ;
}
void T_2 F_28 ( void )
{
F_29 ( & V_113 ) ;
}
void T_3 F_30 ( void )
{
F_31 ( & V_113 ) ;
}
