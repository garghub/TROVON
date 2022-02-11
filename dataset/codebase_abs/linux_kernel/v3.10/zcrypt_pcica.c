static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned char * V_7 , * V_8 , * V_9 ;
int V_10 ;
V_10 = V_6 -> V_11 ;
if ( V_10 <= 128 ) {
struct V_12 * V_13 = V_4 -> V_9 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_4 -> V_14 = sizeof( * V_13 ) ;
V_13 -> V_15 . V_16 = V_17 ;
V_13 -> V_15 . V_18 = sizeof( * V_13 ) ;
V_13 -> V_15 . V_19 = V_20 ;
V_13 -> V_15 . V_21 = V_22 ;
V_7 = V_13 -> V_7 + sizeof( V_13 -> V_7 ) - V_10 ;
V_8 = V_13 -> V_8 + sizeof( V_13 -> V_8 ) - V_10 ;
V_9 = V_13 -> V_9 + sizeof( V_13 -> V_9 ) - V_10 ;
} else {
struct V_23 * V_24 = V_4 -> V_9 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_4 -> V_14 = sizeof( * V_24 ) ;
V_24 -> V_15 . V_16 = V_25 ;
V_24 -> V_15 . V_18 = sizeof( * V_24 ) ;
V_24 -> V_15 . V_19 = V_20 ;
V_24 -> V_15 . V_21 = V_22 ;
V_7 = V_24 -> V_7 + sizeof( V_24 -> V_7 ) - V_10 ;
V_8 = V_24 -> V_8 + sizeof( V_24 -> V_8 ) - V_10 ;
V_9 = V_24 -> V_9 + sizeof( V_24 -> V_9 ) - V_10 ;
}
if ( F_2 ( V_7 , V_6 -> V_26 , V_10 ) ||
F_2 ( V_8 , V_6 -> V_27 , V_10 ) ||
F_2 ( V_9 , V_6 -> V_28 , V_10 ) )
return - V_29 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_30 * V_31 )
{
unsigned char * V_32 , * V_33 , * V_34 , * V_35 , * V_36 , * V_37 ;
int V_10 , V_38 , V_39 ;
V_10 = V_31 -> V_11 ;
V_38 = V_10 / 2 ;
V_39 = V_10 / 2 + 8 ;
if ( V_10 <= 128 ) {
struct V_40 * V_41 = V_4 -> V_9 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_4 -> V_14 = sizeof( * V_41 ) ;
V_41 -> V_15 . V_19 = V_20 ;
V_41 -> V_15 . V_21 = V_22 ;
V_41 -> V_15 . V_16 = V_42 ;
V_41 -> V_15 . V_18 = sizeof( * V_41 ) ;
V_32 = V_41 -> V_32 + sizeof( V_41 -> V_32 ) - V_39 ;
V_33 = V_41 -> V_33 + sizeof( V_41 -> V_33 ) - V_38 ;
V_34 = V_41 -> V_34 + sizeof( V_41 -> V_34 ) - V_39 ;
V_35 = V_41 -> V_35 + sizeof( V_41 -> V_35 ) - V_38 ;
V_36 = V_41 -> V_36 + sizeof( V_41 -> V_36 ) - V_39 ;
V_37 = V_41 -> V_9 + sizeof( V_41 -> V_9 ) - V_10 ;
} else {
struct V_43 * V_44 = V_4 -> V_9 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_4 -> V_14 = sizeof( * V_44 ) ;
V_44 -> V_15 . V_19 = V_20 ;
V_44 -> V_15 . V_21 = V_22 ;
V_44 -> V_15 . V_16 = V_45 ;
V_44 -> V_15 . V_18 = sizeof( * V_44 ) ;
V_32 = V_44 -> V_32 + sizeof( V_44 -> V_32 ) - V_39 ;
V_33 = V_44 -> V_33 + sizeof( V_44 -> V_33 ) - V_38 ;
V_34 = V_44 -> V_34 + sizeof( V_44 -> V_34 ) - V_39 ;
V_35 = V_44 -> V_35 + sizeof( V_44 -> V_35 ) - V_38 ;
V_36 = V_44 -> V_36 + sizeof( V_44 -> V_36 ) - V_39 ;
V_37 = V_44 -> V_9 + sizeof( V_44 -> V_9 ) - V_10 ;
}
if ( F_2 ( V_32 , V_31 -> V_46 , V_39 ) ||
F_2 ( V_33 , V_31 -> V_47 , V_38 ) ||
F_2 ( V_34 , V_31 -> V_48 , V_39 ) ||
F_2 ( V_35 , V_31 -> V_49 , V_38 ) ||
F_2 ( V_36 , V_31 -> V_50 , V_39 ) ||
F_2 ( V_37 , V_31 -> V_28 , V_10 ) )
return - V_29 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_51 ,
char T_1 * V_52 ,
unsigned int V_53 )
{
struct V_54 * V_55 = V_51 -> V_9 ;
char * V_56 ;
if ( V_55 -> V_57 < sizeof( * V_55 ) + V_53 ) {
V_2 -> V_58 = 0 ;
return - V_59 ;
}
F_5 ( V_55 -> V_57 > V_60 ) ;
V_56 = V_51 -> V_9 + V_55 -> V_57 - V_53 ;
if ( F_6 ( V_52 , V_56 , V_53 ) )
return - V_29 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_51 ,
char T_1 * V_52 ,
unsigned int V_53 )
{
switch ( ( ( unsigned char * ) V_51 -> V_9 ) [ 1 ] ) {
case V_61 :
case V_62 :
return F_8 ( V_2 , V_51 ) ;
case V_63 :
return F_4 ( V_2 , V_51 ,
V_52 , V_53 ) ;
default:
V_2 -> V_58 = 0 ;
return - V_59 ;
}
}
static void F_9 ( struct V_64 * V_65 ,
struct V_3 * V_66 ,
struct V_3 * V_51 )
{
static struct V_67 V_68 = {
. type = V_61 ,
. V_69 = V_70 ,
} ;
struct V_54 * V_55 ;
int V_14 ;
if ( F_10 ( V_51 ) ) {
memcpy ( V_66 -> V_9 , & V_68 , sizeof( V_68 ) ) ;
goto V_71;
}
V_55 = V_51 -> V_9 ;
if ( V_55 -> V_72 == V_63 ) {
V_14 = F_11 ( V_60 , ( int ) V_55 -> V_57 ) ;
memcpy ( V_66 -> V_9 , V_51 -> V_9 , V_14 ) ;
} else
memcpy ( V_66 -> V_9 , V_51 -> V_9 , sizeof V_68 ) ;
V_71:
F_12 ( (struct V_73 * ) V_66 -> V_74 ) ;
}
static long F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 V_4 ;
struct V_73 V_75 ;
int V_76 ;
F_14 ( & V_4 ) ;
V_4 . V_9 = F_15 ( V_77 , V_78 ) ;
if ( ! V_4 . V_9 )
return - V_79 ;
V_4 . V_80 = F_9 ;
V_4 . V_81 = ( ( ( unsigned long long ) V_82 -> V_83 ) << 32 ) +
F_16 ( & V_84 ) ;
V_4 . V_74 = & V_75 ;
V_76 = F_1 ( V_2 , & V_4 , V_6 ) ;
if ( V_76 )
goto V_85;
F_17 ( & V_75 ) ;
F_18 ( V_2 -> V_65 , & V_4 ) ;
V_76 = F_19 ( & V_75 ) ;
if ( V_76 == 0 )
V_76 = F_7 ( V_2 , & V_4 , V_6 -> V_52 ,
V_6 -> V_53 ) ;
else
F_20 ( V_2 -> V_65 , & V_4 ) ;
V_85:
F_21 ( V_4 . V_9 ) ;
return V_76 ;
}
static long F_22 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_3 V_4 ;
struct V_73 V_75 ;
int V_76 ;
F_14 ( & V_4 ) ;
V_4 . V_9 = F_15 ( V_77 , V_78 ) ;
if ( ! V_4 . V_9 )
return - V_79 ;
V_4 . V_80 = F_9 ;
V_4 . V_81 = ( ( ( unsigned long long ) V_82 -> V_83 ) << 32 ) +
F_16 ( & V_84 ) ;
V_4 . V_74 = & V_75 ;
V_76 = F_3 ( V_2 , & V_4 , V_31 ) ;
if ( V_76 )
goto V_85;
F_17 ( & V_75 ) ;
F_18 ( V_2 -> V_65 , & V_4 ) ;
V_76 = F_19 ( & V_75 ) ;
if ( V_76 == 0 )
V_76 = F_7 ( V_2 , & V_4 , V_31 -> V_52 ,
V_31 -> V_53 ) ;
else
F_20 ( V_2 -> V_65 , & V_4 ) ;
V_85:
F_21 ( V_4 . V_9 ) ;
return V_76 ;
}
static int F_23 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
int V_76 ;
V_2 = F_24 ( V_60 ) ;
if ( ! V_2 )
return - V_79 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_86 = & V_87 ;
V_2 -> V_58 = 1 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = L_1 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = V_96 ;
V_2 -> V_97 = V_94 ;
V_65 -> V_51 = & V_2 -> V_51 ;
V_65 -> V_74 = V_2 ;
V_76 = F_25 ( V_2 ) ;
if ( V_76 )
goto V_85;
return 0 ;
V_85:
V_65 -> V_74 = NULL ;
F_26 ( V_2 ) ;
return V_76 ;
}
static void F_27 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_74 ;
F_28 ( V_2 ) ;
}
int T_2 F_29 ( void )
{
return F_30 ( & V_98 , V_99 , L_2 ) ;
}
void F_31 ( void )
{
F_32 ( & V_98 ) ;
}
