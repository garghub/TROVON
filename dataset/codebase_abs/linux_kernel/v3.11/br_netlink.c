static inline T_1 F_1 ( void )
{
return F_2 ( 1 )
+ F_2 ( 2 )
+ F_2 ( 4 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ F_2 ( 1 )
+ 0 ;
}
static inline T_1 F_3 ( void )
{
return F_4 ( sizeof( struct V_1 ) )
+ F_2 ( V_2 )
+ F_2 ( V_3 )
+ F_2 ( 4 )
+ F_2 ( 4 )
+ F_2 ( 4 )
+ F_2 ( 1 )
+ F_2 ( F_1 () ) ;
}
static int F_5 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
T_2 V_8 = ! ! ( V_7 -> V_9 & V_10 ) ;
if ( F_6 ( V_5 , V_11 , V_7 -> V_12 ) ||
F_7 ( V_5 , V_13 , V_7 -> V_14 ) ||
F_8 ( V_5 , V_15 , V_7 -> V_16 ) ||
F_6 ( V_5 , V_17 , V_8 ) ||
F_6 ( V_5 , V_18 , ! ! ( V_7 -> V_9 & V_19 ) ) ||
F_6 ( V_5 , V_20 , ! ! ( V_7 -> V_9 & V_21 ) ) ||
F_6 ( V_5 , V_22 , ! ! ( V_7 -> V_9 & V_23 ) ) ||
F_6 ( V_5 , V_24 , ! ! ( V_7 -> V_9 & V_25 ) ) ||
F_6 ( V_5 , V_26 , ! ! ( V_7 -> V_9 & V_27 ) ) )
return - V_28 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
const struct V_6 * V_29 ,
T_3 V_30 , T_3 V_31 , int V_32 , unsigned int V_9 ,
T_3 V_33 , const struct V_34 * V_35 )
{
const struct V_36 * V_37 ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
T_2 V_41 = F_10 ( V_35 ) ? V_35 -> V_41 : V_42 ;
if ( V_29 )
V_37 = V_29 -> V_37 ;
else
V_37 = F_11 ( V_35 ) ;
F_12 ( V_37 , L_1 ,
V_32 , V_35 -> V_43 , V_37 -> V_35 -> V_43 ) ;
V_40 = F_13 ( V_5 , V_30 , V_31 , V_32 , sizeof( * V_38 ) , V_9 ) ;
if ( V_40 == NULL )
return - V_28 ;
V_38 = F_14 ( V_40 ) ;
V_38 -> V_44 = V_45 ;
V_38 -> V_46 = 0 ;
V_38 -> V_47 = V_35 -> type ;
V_38 -> V_48 = V_35 -> V_49 ;
V_38 -> V_50 = F_15 ( V_35 ) ;
V_38 -> V_51 = 0 ;
if ( F_16 ( V_5 , V_52 , V_35 -> V_43 ) ||
F_8 ( V_5 , V_53 , V_37 -> V_35 -> V_49 ) ||
F_8 ( V_5 , V_54 , V_35 -> V_55 ) ||
F_6 ( V_5 , V_56 , V_41 ) ||
( V_35 -> V_57 &&
F_17 ( V_5 , V_58 , V_35 -> V_57 , V_35 -> V_59 ) ) ||
( V_35 -> V_49 != V_35 -> V_60 &&
F_8 ( V_5 , V_61 , V_35 -> V_60 ) ) )
goto V_62;
if ( V_32 == V_63 && V_29 ) {
struct V_64 * V_65
= F_18 ( V_5 , V_66 | V_67 ) ;
if ( V_65 == NULL || F_5 ( V_5 , V_29 ) < 0 )
goto V_62;
F_19 ( V_5 , V_65 ) ;
}
if ( V_33 & V_68 ) {
struct V_64 * V_69 ;
const struct V_70 * V_71 ;
struct V_72 V_73 ;
T_4 V_74 ;
T_4 V_75 ;
if ( V_29 )
V_71 = F_20 ( V_29 ) ;
else
V_71 = F_21 ( V_37 ) ;
if ( ! V_71 || F_22 ( V_71 -> V_76 , V_77 ) )
goto V_78;
V_69 = F_18 ( V_5 , V_79 ) ;
if ( ! V_69 )
goto V_62;
V_75 = F_23 ( V_71 ) ;
F_24 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_73 . V_74 = V_74 ;
V_73 . V_9 = 0 ;
if ( V_74 == V_75 )
V_73 . V_9 |= V_80 ;
if ( F_25 ( V_74 , V_71 -> V_81 ) )
V_73 . V_9 |= V_82 ;
if ( F_17 ( V_5 , V_83 ,
sizeof( V_73 ) , & V_73 ) )
goto V_62;
}
F_19 ( V_5 , V_69 ) ;
}
V_78:
return F_26 ( V_5 , V_40 ) ;
V_62:
F_27 ( V_5 , V_40 ) ;
return - V_28 ;
}
void F_28 ( int V_32 , struct V_6 * V_29 )
{
struct V_84 * V_84 ;
struct V_4 * V_5 ;
int V_85 = - V_86 ;
if ( ! V_29 )
return;
V_84 = F_29 ( V_29 -> V_35 ) ;
F_12 ( V_29 -> V_37 , L_2 ,
( unsigned int ) V_29 -> V_87 , V_29 -> V_35 -> V_43 , V_32 ) ;
V_5 = F_30 ( F_3 () , V_88 ) ;
if ( V_5 == NULL )
goto V_89;
V_85 = F_9 ( V_5 , V_29 , 0 , 0 , V_32 , 0 , 0 , V_29 -> V_35 ) ;
if ( V_85 < 0 ) {
F_31 ( V_85 == - V_28 ) ;
F_32 ( V_5 ) ;
goto V_89;
}
F_33 ( V_5 , V_84 , 0 , V_90 , NULL , V_88 ) ;
return;
V_89:
if ( V_85 < 0 )
F_34 ( V_84 , V_90 , V_85 ) ;
}
int F_35 ( struct V_4 * V_5 , T_3 V_30 , T_3 V_31 ,
struct V_34 * V_35 , T_3 V_33 )
{
int V_85 = 0 ;
struct V_6 * V_29 = F_36 ( V_35 ) ;
if ( ! V_29 && ! ( V_33 & V_68 ) )
goto V_91;
V_85 = F_9 ( V_5 , V_29 , V_30 , V_31 , V_63 , V_92 ,
V_33 , V_35 ) ;
V_91:
return V_85 ;
}
static int F_37 ( struct V_36 * V_37 ,
struct V_6 * V_7 ,
struct V_64 * V_93 ,
int V_94 )
{
struct V_64 * V_95 [ V_96 + 1 ] ;
int V_85 = 0 ;
V_85 = F_38 ( V_95 , V_96 , V_93 , V_97 ) ;
if ( V_85 )
return V_85 ;
if ( V_95 [ V_83 ] ) {
struct V_72 * V_73 ;
V_73 = F_39 ( V_95 [ V_83 ] ) ;
if ( V_73 -> V_74 >= V_77 )
return - V_98 ;
switch ( V_94 ) {
case V_99 :
if ( V_7 ) {
V_85 = F_40 ( V_7 , V_73 -> V_74 , V_73 -> V_9 ) ;
if ( V_85 )
break;
if ( V_73 -> V_9 & V_100 )
V_85 = F_41 ( V_7 -> V_37 , V_73 -> V_74 ,
V_73 -> V_9 ) ;
} else
V_85 = F_41 ( V_37 , V_73 -> V_74 , V_73 -> V_9 ) ;
if ( V_85 )
break;
break;
case V_101 :
if ( V_7 ) {
F_42 ( V_7 , V_73 -> V_74 ) ;
if ( V_73 -> V_9 & V_100 )
F_43 ( V_7 -> V_37 , V_73 -> V_74 ) ;
} else
F_43 ( V_37 , V_73 -> V_74 ) ;
break;
}
}
return V_85 ;
}
static int F_44 ( struct V_6 * V_7 , T_2 V_12 )
{
if ( V_12 > V_102 )
return - V_98 ;
if ( V_7 -> V_37 -> V_103 == V_104 )
return - V_105 ;
if ( ! F_10 ( V_7 -> V_35 ) ||
( ! F_45 ( V_7 -> V_35 ) && V_12 != V_106 ) )
return - V_107 ;
V_7 -> V_12 = V_12 ;
F_46 ( V_7 ) ;
F_47 ( V_7 -> V_37 ) ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 , struct V_64 * V_95 [] ,
int V_108 , unsigned long V_109 )
{
if ( V_95 [ V_108 ] ) {
T_2 V_110 = F_49 ( V_95 [ V_108 ] ) ;
if ( V_110 )
V_7 -> V_9 |= V_109 ;
else
V_7 -> V_9 &= ~ V_109 ;
}
}
static int F_50 ( struct V_6 * V_7 , struct V_64 * V_95 [] )
{
int V_85 ;
F_48 ( V_7 , V_95 , V_17 , V_10 ) ;
F_48 ( V_7 , V_95 , V_18 , V_19 ) ;
F_48 ( V_7 , V_95 , V_22 , V_23 ) ;
F_48 ( V_7 , V_95 , V_20 , V_21 ) ;
F_48 ( V_7 , V_95 , V_24 , V_25 ) ;
F_48 ( V_7 , V_95 , V_26 , V_27 ) ;
if ( V_95 [ V_15 ] ) {
V_85 = F_51 ( V_7 , F_52 ( V_95 [ V_15 ] ) ) ;
if ( V_85 )
return V_85 ;
}
if ( V_95 [ V_13 ] ) {
V_85 = F_53 ( V_7 , F_54 ( V_95 [ V_13 ] ) ) ;
if ( V_85 )
return V_85 ;
}
if ( V_95 [ V_11 ] ) {
V_85 = F_44 ( V_7 , F_49 ( V_95 [ V_11 ] ) ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
int F_55 ( struct V_34 * V_35 , struct V_39 * V_40 )
{
struct V_64 * V_111 ;
struct V_64 * V_112 ;
struct V_6 * V_7 ;
struct V_64 * V_95 [ V_113 + 1 ] ;
int V_85 = 0 ;
V_111 = F_56 ( V_40 , sizeof( struct V_1 ) , V_66 ) ;
V_112 = F_56 ( V_40 , sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_111 && ! V_112 )
return 0 ;
V_7 = F_57 ( V_35 ) ;
if ( ! V_7 && ! V_112 )
return - V_98 ;
if ( V_7 && V_111 ) {
if ( V_111 -> V_114 & V_67 ) {
V_85 = F_38 ( V_95 , V_113 ,
V_111 , V_115 ) ;
if ( V_85 )
return V_85 ;
F_58 ( & V_7 -> V_37 -> V_116 ) ;
V_85 = F_50 ( V_7 , V_95 ) ;
F_59 ( & V_7 -> V_37 -> V_116 ) ;
} else {
if ( F_60 ( V_111 ) < sizeof( T_2 ) )
return - V_98 ;
F_58 ( & V_7 -> V_37 -> V_116 ) ;
V_85 = F_44 ( V_7 , F_49 ( V_111 ) ) ;
F_59 ( & V_7 -> V_37 -> V_116 ) ;
}
if ( V_85 )
goto V_91;
}
if ( V_112 ) {
V_85 = F_37 ( (struct V_36 * ) F_11 ( V_35 ) , V_7 ,
V_112 , V_99 ) ;
}
if ( V_85 == 0 )
F_28 ( V_63 , V_7 ) ;
V_91:
return V_85 ;
}
int F_61 ( struct V_34 * V_35 , struct V_39 * V_40 )
{
struct V_64 * V_112 ;
struct V_6 * V_7 ;
int V_85 ;
V_112 = F_56 ( V_40 , sizeof( struct V_1 ) , V_79 ) ;
if ( ! V_112 )
return 0 ;
V_7 = F_57 ( V_35 ) ;
if ( ! V_7 && ! ( V_35 -> V_117 & V_118 ) )
return - V_98 ;
V_85 = F_37 ( (struct V_36 * ) F_11 ( V_35 ) , V_7 ,
V_112 , V_101 ) ;
return V_85 ;
}
static int F_62 ( struct V_64 * V_95 [] , struct V_64 * V_119 [] )
{
if ( V_95 [ V_58 ] ) {
if ( F_60 ( V_95 [ V_58 ] ) != V_120 )
return - V_98 ;
if ( ! F_63 ( F_39 ( V_95 [ V_58 ] ) ) )
return - V_121 ;
}
return 0 ;
}
static T_1 F_64 ( const struct V_34 * V_35 )
{
struct V_70 * V_71 ;
if ( F_65 ( V_35 ) )
V_71 = F_20 ( F_36 ( V_35 ) ) ;
else if ( V_35 -> V_117 & V_118 )
V_71 = F_21 ( (struct V_36 * ) F_11 ( V_35 ) ) ;
else
return 0 ;
if ( ! V_71 )
return 0 ;
return V_71 -> V_122 * F_2 ( sizeof( struct V_72 ) ) ;
}
int T_5 F_66 ( void )
{
int V_85 ;
F_67 () ;
V_85 = F_68 ( & V_123 ) ;
if ( V_85 )
goto V_91;
V_85 = F_69 ( & V_124 ) ;
if ( V_85 )
goto V_125;
return 0 ;
V_125:
F_70 ( & V_123 ) ;
V_91:
F_71 () ;
return V_85 ;
}
void T_6 F_72 ( void )
{
F_71 () ;
F_70 ( & V_123 ) ;
F_73 ( & V_124 ) ;
}
