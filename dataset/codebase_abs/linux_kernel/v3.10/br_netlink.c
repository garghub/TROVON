static inline T_1 F_1 ( void )
{
return F_2 ( 1 )
+ F_2 ( 2 )
+ F_2 ( 4 )
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
F_6 ( V_5 , V_22 , ! ! ( V_7 -> V_9 & V_23 ) ) )
return - V_24 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
const struct V_6 * V_25 ,
T_3 V_26 , T_3 V_27 , int V_28 , unsigned int V_9 ,
T_3 V_29 , const struct V_30 * V_31 )
{
const struct V_32 * V_33 ;
struct V_1 * V_34 ;
struct V_35 * V_36 ;
T_2 V_37 = F_10 ( V_31 ) ? V_31 -> V_37 : V_38 ;
if ( V_25 )
V_33 = V_25 -> V_33 ;
else
V_33 = F_11 ( V_31 ) ;
F_12 ( V_33 , L_1 ,
V_28 , V_31 -> V_39 , V_33 -> V_31 -> V_39 ) ;
V_36 = F_13 ( V_5 , V_26 , V_27 , V_28 , sizeof( * V_34 ) , V_9 ) ;
if ( V_36 == NULL )
return - V_24 ;
V_34 = F_14 ( V_36 ) ;
V_34 -> V_40 = V_41 ;
V_34 -> V_42 = 0 ;
V_34 -> V_43 = V_31 -> type ;
V_34 -> V_44 = V_31 -> V_45 ;
V_34 -> V_46 = F_15 ( V_31 ) ;
V_34 -> V_47 = 0 ;
if ( F_16 ( V_5 , V_48 , V_31 -> V_39 ) ||
F_8 ( V_5 , V_49 , V_33 -> V_31 -> V_45 ) ||
F_8 ( V_5 , V_50 , V_31 -> V_51 ) ||
F_6 ( V_5 , V_52 , V_37 ) ||
( V_31 -> V_53 &&
F_17 ( V_5 , V_54 , V_31 -> V_53 , V_31 -> V_55 ) ) ||
( V_31 -> V_45 != V_31 -> V_56 &&
F_8 ( V_5 , V_57 , V_31 -> V_56 ) ) )
goto V_58;
if ( V_28 == V_59 && V_25 ) {
struct V_60 * V_61
= F_18 ( V_5 , V_62 | V_63 ) ;
if ( V_61 == NULL || F_5 ( V_5 , V_25 ) < 0 )
goto V_58;
F_19 ( V_5 , V_61 ) ;
}
if ( V_29 & V_64 ) {
struct V_60 * V_65 ;
const struct V_66 * V_67 ;
struct V_68 V_69 ;
T_4 V_70 ;
T_4 V_71 ;
if ( V_25 )
V_67 = F_20 ( V_25 ) ;
else
V_67 = F_21 ( V_33 ) ;
if ( ! V_67 || F_22 ( V_67 -> V_72 , V_73 ) )
goto V_74;
V_65 = F_18 ( V_5 , V_75 ) ;
if ( ! V_65 )
goto V_58;
V_71 = F_23 ( V_67 ) ;
F_24 (vid, pv->vlan_bitmap, BR_VLAN_BITMAP_LEN) {
V_69 . V_70 = V_70 ;
V_69 . V_9 = 0 ;
if ( V_70 == V_71 )
V_69 . V_9 |= V_76 ;
if ( F_25 ( V_70 , V_67 -> V_77 ) )
V_69 . V_9 |= V_78 ;
if ( F_17 ( V_5 , V_79 ,
sizeof( V_69 ) , & V_69 ) )
goto V_58;
}
F_19 ( V_5 , V_65 ) ;
}
V_74:
return F_26 ( V_5 , V_36 ) ;
V_58:
F_27 ( V_5 , V_36 ) ;
return - V_24 ;
}
void F_28 ( int V_28 , struct V_6 * V_25 )
{
struct V_80 * V_80 ;
struct V_4 * V_5 ;
int V_81 = - V_82 ;
if ( ! V_25 )
return;
V_80 = F_29 ( V_25 -> V_31 ) ;
F_12 ( V_25 -> V_33 , L_2 ,
( unsigned int ) V_25 -> V_83 , V_25 -> V_31 -> V_39 , V_28 ) ;
V_5 = F_30 ( F_3 () , V_84 ) ;
if ( V_5 == NULL )
goto V_85;
V_81 = F_9 ( V_5 , V_25 , 0 , 0 , V_28 , 0 , 0 , V_25 -> V_31 ) ;
if ( V_81 < 0 ) {
F_31 ( V_81 == - V_24 ) ;
F_32 ( V_5 ) ;
goto V_85;
}
F_33 ( V_5 , V_80 , 0 , V_86 , NULL , V_84 ) ;
return;
V_85:
if ( V_81 < 0 )
F_34 ( V_80 , V_86 , V_81 ) ;
}
int F_35 ( struct V_4 * V_5 , T_3 V_26 , T_3 V_27 ,
struct V_30 * V_31 , T_3 V_29 )
{
int V_81 = 0 ;
struct V_6 * V_25 = F_36 ( V_31 ) ;
if ( ! V_25 && ! ( V_29 & V_64 ) )
goto V_87;
V_81 = F_9 ( V_5 , V_25 , V_26 , V_27 , V_59 , V_88 ,
V_29 , V_31 ) ;
V_87:
return V_81 ;
}
static int F_37 ( struct V_32 * V_33 ,
struct V_6 * V_7 ,
struct V_60 * V_89 ,
int V_90 )
{
struct V_60 * V_91 [ V_92 + 1 ] ;
int V_81 = 0 ;
V_81 = F_38 ( V_91 , V_92 , V_89 , V_93 ) ;
if ( V_81 )
return V_81 ;
if ( V_91 [ V_79 ] ) {
struct V_68 * V_69 ;
V_69 = F_39 ( V_91 [ V_79 ] ) ;
if ( V_69 -> V_70 >= V_94 )
return - V_95 ;
switch ( V_90 ) {
case V_96 :
if ( V_7 ) {
V_81 = F_40 ( V_7 , V_69 -> V_70 , V_69 -> V_9 ) ;
if ( V_81 )
break;
if ( V_69 -> V_9 & V_97 )
V_81 = F_41 ( V_7 -> V_33 , V_69 -> V_70 ,
V_69 -> V_9 ) ;
} else
V_81 = F_41 ( V_33 , V_69 -> V_70 , V_69 -> V_9 ) ;
if ( V_81 )
break;
break;
case V_98 :
if ( V_7 ) {
F_42 ( V_7 , V_69 -> V_70 ) ;
if ( V_69 -> V_9 & V_97 )
F_43 ( V_7 -> V_33 , V_69 -> V_70 ) ;
} else
F_43 ( V_33 , V_69 -> V_70 ) ;
break;
}
}
return V_81 ;
}
static int F_44 ( struct V_6 * V_7 , T_2 V_12 )
{
if ( V_12 > V_99 )
return - V_95 ;
if ( V_7 -> V_33 -> V_100 == V_101 )
return - V_102 ;
if ( ! F_10 ( V_7 -> V_31 ) ||
( ! F_45 ( V_7 -> V_31 ) && V_12 != V_103 ) )
return - V_104 ;
V_7 -> V_12 = V_12 ;
F_46 ( V_7 ) ;
F_47 ( V_7 -> V_33 ) ;
return 0 ;
}
static void F_48 ( struct V_6 * V_7 , struct V_60 * V_91 [] ,
int V_105 , unsigned long V_106 )
{
if ( V_91 [ V_105 ] ) {
T_2 V_107 = F_49 ( V_91 [ V_105 ] ) ;
if ( V_107 )
V_7 -> V_9 |= V_106 ;
else
V_7 -> V_9 &= ~ V_106 ;
}
}
static int F_50 ( struct V_6 * V_7 , struct V_60 * V_91 [] )
{
int V_81 ;
F_48 ( V_7 , V_91 , V_17 , V_10 ) ;
F_48 ( V_7 , V_91 , V_18 , V_19 ) ;
F_48 ( V_7 , V_91 , V_22 , V_23 ) ;
F_48 ( V_7 , V_91 , V_20 , V_21 ) ;
if ( V_91 [ V_15 ] ) {
V_81 = F_51 ( V_7 , F_52 ( V_91 [ V_15 ] ) ) ;
if ( V_81 )
return V_81 ;
}
if ( V_91 [ V_13 ] ) {
V_81 = F_53 ( V_7 , F_54 ( V_91 [ V_13 ] ) ) ;
if ( V_81 )
return V_81 ;
}
if ( V_91 [ V_11 ] ) {
V_81 = F_44 ( V_7 , F_49 ( V_91 [ V_11 ] ) ) ;
if ( V_81 )
return V_81 ;
}
return 0 ;
}
int F_55 ( struct V_30 * V_31 , struct V_35 * V_36 )
{
struct V_60 * V_108 ;
struct V_60 * V_109 ;
struct V_6 * V_7 ;
struct V_60 * V_91 [ V_110 + 1 ] ;
int V_81 = 0 ;
V_108 = F_56 ( V_36 , sizeof( struct V_1 ) , V_62 ) ;
V_109 = F_56 ( V_36 , sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_108 && ! V_109 )
return 0 ;
V_7 = F_57 ( V_31 ) ;
if ( ! V_7 && ! V_109 )
return - V_95 ;
if ( V_7 && V_108 ) {
if ( V_108 -> V_111 & V_63 ) {
V_81 = F_38 ( V_91 , V_110 ,
V_108 , V_112 ) ;
if ( V_81 )
return V_81 ;
F_58 ( & V_7 -> V_33 -> V_113 ) ;
V_81 = F_50 ( V_7 , V_91 ) ;
F_59 ( & V_7 -> V_33 -> V_113 ) ;
} else {
if ( F_60 ( V_108 ) < sizeof( T_2 ) )
return - V_95 ;
F_58 ( & V_7 -> V_33 -> V_113 ) ;
V_81 = F_44 ( V_7 , F_49 ( V_108 ) ) ;
F_59 ( & V_7 -> V_33 -> V_113 ) ;
}
if ( V_81 )
goto V_87;
}
if ( V_109 ) {
V_81 = F_37 ( (struct V_32 * ) F_11 ( V_31 ) , V_7 ,
V_109 , V_96 ) ;
}
if ( V_81 == 0 )
F_28 ( V_59 , V_7 ) ;
V_87:
return V_81 ;
}
int F_61 ( struct V_30 * V_31 , struct V_35 * V_36 )
{
struct V_60 * V_109 ;
struct V_6 * V_7 ;
int V_81 ;
V_109 = F_56 ( V_36 , sizeof( struct V_1 ) , V_75 ) ;
if ( ! V_109 )
return 0 ;
V_7 = F_57 ( V_31 ) ;
if ( ! V_7 && ! ( V_31 -> V_114 & V_115 ) )
return - V_95 ;
V_81 = F_37 ( (struct V_32 * ) F_11 ( V_31 ) , V_7 ,
V_109 , V_98 ) ;
return V_81 ;
}
static int F_62 ( struct V_60 * V_91 [] , struct V_60 * V_116 [] )
{
if ( V_91 [ V_54 ] ) {
if ( F_60 ( V_91 [ V_54 ] ) != V_117 )
return - V_95 ;
if ( ! F_63 ( F_39 ( V_91 [ V_54 ] ) ) )
return - V_118 ;
}
return 0 ;
}
static T_1 F_64 ( const struct V_30 * V_31 )
{
struct V_66 * V_67 ;
if ( F_65 ( V_31 ) )
V_67 = F_20 ( F_36 ( V_31 ) ) ;
else if ( V_31 -> V_114 & V_115 )
V_67 = F_21 ( (struct V_32 * ) F_11 ( V_31 ) ) ;
else
return 0 ;
if ( ! V_67 )
return 0 ;
return V_67 -> V_119 * F_2 ( sizeof( struct V_68 ) ) ;
}
int T_5 F_66 ( void )
{
int V_81 ;
F_67 () ;
V_81 = F_68 ( & V_120 ) ;
if ( V_81 )
goto V_87;
V_81 = F_69 ( & V_121 ) ;
if ( V_81 )
goto V_122;
return 0 ;
V_122:
F_70 ( & V_120 ) ;
V_87:
F_71 () ;
return V_81 ;
}
void T_6 F_72 ( void )
{
F_71 () ;
F_70 ( & V_120 ) ;
F_73 ( & V_121 ) ;
}
