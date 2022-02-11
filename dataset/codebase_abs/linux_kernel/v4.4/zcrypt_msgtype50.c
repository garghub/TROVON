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
int V_9 , V_35 ;
unsigned char * V_36 , * V_37 , * V_38 , * V_39 , * V_40 , * V_8 ;
V_9 = V_34 -> V_10 ;
V_35 = ( V_9 + 1 ) / 2 ;
if ( V_9 <= 128 ) {
struct V_41 * V_42 = V_4 -> V_13 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_4 -> V_14 = sizeof( * V_42 ) ;
V_42 -> V_15 . V_16 = V_17 ;
V_42 -> V_15 . V_18 = sizeof( * V_42 ) ;
V_42 -> V_19 = V_43 ;
V_36 = V_42 -> V_36 + sizeof( V_42 -> V_36 ) - V_35 ;
V_37 = V_42 -> V_37 + sizeof( V_42 -> V_37 ) - V_35 ;
V_38 = V_42 -> V_38 + sizeof( V_42 -> V_38 ) - V_35 ;
V_39 = V_42 -> V_39 + sizeof( V_42 -> V_39 ) - V_35 ;
V_40 = V_42 -> V_40 + sizeof( V_42 -> V_40 ) - V_35 ;
V_8 = V_42 -> V_13 + sizeof( V_42 -> V_13 ) - V_9 ;
} else if ( V_9 <= 256 ) {
struct V_44 * V_45 = V_4 -> V_13 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_4 -> V_14 = sizeof( * V_45 ) ;
V_45 -> V_15 . V_16 = V_17 ;
V_45 -> V_15 . V_18 = sizeof( * V_45 ) ;
V_45 -> V_19 = V_46 ;
V_36 = V_45 -> V_36 + sizeof( V_45 -> V_36 ) - V_35 ;
V_37 = V_45 -> V_37 + sizeof( V_45 -> V_37 ) - V_35 ;
V_38 = V_45 -> V_38 + sizeof( V_45 -> V_38 ) - V_35 ;
V_39 = V_45 -> V_39 + sizeof( V_45 -> V_39 ) - V_35 ;
V_40 = V_45 -> V_40 + sizeof( V_45 -> V_40 ) - V_35 ;
V_8 = V_45 -> V_13 + sizeof( V_45 -> V_13 ) - V_9 ;
} else if ( ( V_9 <= 512 ) &&
( V_2 -> V_47 == V_48 ) ) {
struct V_49 * V_50 = V_4 -> V_13 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_4 -> V_14 = sizeof( * V_50 ) ;
V_50 -> V_15 . V_16 = V_17 ;
V_50 -> V_15 . V_18 = sizeof( * V_50 ) ;
V_50 -> V_19 = V_51 ;
V_36 = V_50 -> V_36 + sizeof( V_50 -> V_36 ) - V_35 ;
V_37 = V_50 -> V_37 + sizeof( V_50 -> V_37 ) - V_35 ;
V_38 = V_50 -> V_38 + sizeof( V_50 -> V_38 ) - V_35 ;
V_39 = V_50 -> V_39 + sizeof( V_50 -> V_39 ) - V_35 ;
V_40 = V_50 -> V_40 + sizeof( V_50 -> V_40 ) - V_35 ;
V_8 = V_50 -> V_13 + sizeof( V_50 -> V_13 ) - V_9 ;
} else
return - V_52 ;
if ( F_2 ( V_36 , V_34 -> V_53 + V_54 , V_35 ) ||
F_2 ( V_37 , V_34 -> V_55 , V_35 ) ||
F_2 ( V_38 , V_34 -> V_56 + V_54 , V_35 ) ||
F_2 ( V_39 , V_34 -> V_57 , V_35 ) ||
F_2 ( V_40 , V_34 -> V_58 + V_54 , V_35 ) ||
F_2 ( V_8 , V_34 -> V_31 , V_9 ) )
return - V_32 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
char T_1 * V_60 ,
unsigned int V_61 )
{
struct V_62 * V_63 = V_59 -> V_13 ;
unsigned char * V_64 ;
if ( V_63 -> V_65 < sizeof( * V_63 ) + V_61 ) {
V_2 -> V_66 = 0 ;
F_5 ( L_1 ,
V_2 -> V_67 -> V_68 ) ;
F_6 ( V_69 , V_2 , L_2 ,
V_2 -> V_67 -> V_68 , V_2 -> V_66 , V_63 -> V_70 ) ;
return - V_71 ;
}
if ( V_2 -> V_72 == V_73 )
F_7 ( V_63 -> V_65 > V_74 ) ;
else
F_7 ( V_63 -> V_65 > V_75 ) ;
V_64 = V_59 -> V_13 + V_63 -> V_65 - V_61 ;
if ( F_8 ( V_60 , V_64 , V_61 ) )
return - V_32 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
char T_1 * V_60 ,
unsigned int V_61 )
{
switch ( ( ( unsigned char * ) V_59 -> V_13 ) [ 1 ] ) {
case V_76 :
case V_77 :
return F_10 ( V_2 , V_59 ) ;
case V_78 :
return F_4 ( V_2 , V_59 ,
V_60 , V_61 ) ;
default:
V_2 -> V_66 = 0 ;
F_5 ( L_1 ,
V_2 -> V_67 -> V_68 ) ;
F_6 ( V_69 , V_2 , L_3 ,
V_2 -> V_67 -> V_68 , V_2 -> V_66 ) ;
return - V_71 ;
}
}
static void F_11 ( struct V_79 * V_67 ,
struct V_3 * V_80 ,
struct V_3 * V_59 )
{
static struct V_81 V_82 = {
. type = V_76 ,
. V_83 = V_84 ,
} ;
struct V_62 * V_63 ;
int V_14 ;
if ( ! V_59 )
goto V_85;
V_63 = V_59 -> V_13 ;
if ( V_63 -> type == V_78 ) {
if ( V_67 -> V_86 == V_87 )
V_14 = F_12 ( int ,
V_74 , V_63 -> V_65 ) ;
else
V_14 = F_12 ( int ,
V_75 , V_63 -> V_65 ) ;
memcpy ( V_80 -> V_13 , V_59 -> V_13 , V_14 ) ;
} else
memcpy ( V_80 -> V_13 , V_59 -> V_13 , sizeof( V_82 ) ) ;
V_85:
F_13 ( (struct V_88 * ) V_80 -> V_89 ) ;
}
static long F_14 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 V_4 ;
struct V_88 V_90 ;
int V_91 ;
F_15 ( & V_4 ) ;
if ( V_2 -> V_72 == V_73 )
V_4 . V_13 = F_16 ( V_92 ,
V_93 ) ;
else
V_4 . V_13 = F_16 ( V_94 ,
V_93 ) ;
if ( ! V_4 . V_13 )
return - V_95 ;
V_4 . V_96 = F_11 ;
V_4 . V_97 = ( ( ( unsigned long long ) V_98 -> V_99 ) << 32 ) +
F_17 ( & V_100 ) ;
V_4 . V_89 = & V_90 ;
V_91 = F_1 ( V_2 , & V_4 , V_6 ) ;
if ( V_91 )
goto V_101;
F_18 ( & V_90 ) ;
F_19 ( V_2 -> V_67 , & V_4 ) ;
V_91 = F_20 ( & V_90 ) ;
if ( V_91 == 0 ) {
V_91 = V_4 . V_91 ;
if ( V_91 == 0 )
V_91 = F_9 ( V_2 , & V_4 , V_6 -> V_60 ,
V_6 -> V_61 ) ;
} else
F_21 ( V_2 -> V_67 , & V_4 ) ;
V_101:
F_22 ( V_4 . V_13 ) ;
return V_91 ;
}
static long F_23 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_3 V_4 ;
struct V_88 V_90 ;
int V_91 ;
F_15 ( & V_4 ) ;
if ( V_2 -> V_72 == V_73 )
V_4 . V_13 = F_16 ( V_92 ,
V_93 ) ;
else
V_4 . V_13 = F_16 ( V_94 ,
V_93 ) ;
if ( ! V_4 . V_13 )
return - V_95 ;
V_4 . V_96 = F_11 ;
V_4 . V_97 = ( ( ( unsigned long long ) V_98 -> V_99 ) << 32 ) +
F_17 ( & V_100 ) ;
V_4 . V_89 = & V_90 ;
V_91 = F_3 ( V_2 , & V_4 , V_34 ) ;
if ( V_91 )
goto V_101;
F_18 ( & V_90 ) ;
F_19 ( V_2 -> V_67 , & V_4 ) ;
V_91 = F_20 ( & V_90 ) ;
if ( V_91 == 0 ) {
V_91 = V_4 . V_91 ;
if ( V_91 == 0 )
V_91 = F_9 ( V_2 , & V_4 , V_34 -> V_60 ,
V_34 -> V_61 ) ;
} else
F_21 ( V_2 -> V_67 , & V_4 ) ;
V_101:
F_22 ( V_4 . V_13 ) ;
return V_91 ;
}
int T_2 F_24 ( void )
{
F_25 ( & V_102 ) ;
return 0 ;
}
void T_3 F_26 ( void )
{
F_27 ( & V_102 ) ;
}
