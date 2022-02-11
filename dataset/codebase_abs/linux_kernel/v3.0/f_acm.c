static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_12 = V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_4 . V_5 . V_16 -> V_15 ;
if ( V_11 -> V_17 != 0 ) {
F_5 ( V_15 , L_1 ,
V_12 -> V_18 , V_11 -> V_17 ) ;
return;
}
if ( V_11 -> V_19 != sizeof( V_12 -> V_20 ) ) {
F_5 ( V_15 , L_2 ,
V_12 -> V_18 , V_11 -> V_19 ) ;
F_6 ( V_9 ) ;
} else {
struct V_21 * V_22 = V_11 -> V_23 ;
V_12 -> V_20 = * V_22 ;
}
}
static int F_7 ( struct V_2 * V_3 , const struct V_24 * V_25 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
struct V_10 * V_11 = V_15 -> V_11 ;
int V_22 = - V_26 ;
T_1 V_27 = F_8 ( V_25 -> V_28 ) ;
T_1 V_29 = F_8 ( V_25 -> V_30 ) ;
T_1 V_31 = F_8 ( V_25 -> V_32 ) ;
switch ( ( V_25 -> V_33 << 8 ) | V_25 -> V_34 ) {
case ( ( V_35 | V_36 | V_37 ) << 8 )
| V_38 :
if ( V_31 != sizeof( struct V_21 )
|| V_27 != V_12 -> V_39 )
goto V_40;
V_22 = V_31 ;
V_15 -> V_41 -> V_42 -> V_13 = V_12 ;
V_11 -> V_43 = F_4 ;
break;
case ( ( V_44 | V_36 | V_37 ) << 8 )
| V_45 :
if ( V_27 != V_12 -> V_39 )
goto V_40;
V_22 = F_9 ( unsigned , V_31 ,
sizeof( struct V_21 ) ) ;
memcpy ( V_11 -> V_23 , & V_12 -> V_20 , V_22 ) ;
break;
case ( ( V_35 | V_36 | V_37 ) << 8 )
| V_46 :
if ( V_27 != V_12 -> V_39 )
goto V_40;
V_22 = 0 ;
V_12 -> V_47 = V_29 ;
break;
default:
V_40:
F_10 ( V_15 , L_3 ,
V_25 -> V_33 , V_25 -> V_34 ,
V_29 , V_27 , V_31 ) ;
}
if ( V_22 >= 0 ) {
F_5 ( V_15 , L_4 ,
V_12 -> V_18 , V_25 -> V_33 , V_25 -> V_34 ,
V_29 , V_27 , V_31 ) ;
V_11 -> V_48 = 0 ;
V_11 -> V_49 = V_22 ;
V_22 = F_11 ( V_15 -> V_41 -> V_42 , V_11 , V_50 ) ;
if ( V_22 < 0 )
ERROR ( V_15 , L_5 ,
V_12 -> V_18 , V_22 ) ;
}
return V_22 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_51 , unsigned V_52 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
if ( V_51 == V_12 -> V_39 ) {
if ( V_12 -> V_53 -> V_13 ) {
F_10 ( V_15 , L_6 , V_51 ) ;
F_13 ( V_12 -> V_53 ) ;
} else {
F_10 ( V_15 , L_7 , V_51 ) ;
V_12 -> V_54 = F_14 ( V_15 -> V_41 ,
V_12 -> V_55 . V_53 ,
V_12 -> V_56 . V_53 ) ;
}
F_15 ( V_12 -> V_53 , V_12 -> V_54 ) ;
V_12 -> V_53 -> V_13 = V_12 ;
} else if ( V_51 == V_12 -> V_57 ) {
if ( V_12 -> V_4 . V_58 -> V_13 ) {
F_5 ( V_15 , L_8 , V_12 -> V_18 ) ;
F_16 ( & V_12 -> V_4 ) ;
} else {
F_5 ( V_15 , L_9 , V_12 -> V_18 ) ;
V_12 -> V_4 . V_59 = F_14 ( V_15 -> V_41 ,
V_12 -> V_55 . V_58 , V_12 -> V_56 . V_58 ) ;
V_12 -> V_4 . V_60 = F_14 ( V_15 -> V_41 ,
V_12 -> V_55 . V_61 , V_12 -> V_56 . V_61 ) ;
}
F_17 ( & V_12 -> V_4 , V_12 -> V_18 ) ;
} else
return - V_62 ;
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_16 -> V_15 ;
F_5 ( V_15 , L_10 , V_12 -> V_18 ) ;
F_16 ( & V_12 -> V_4 ) ;
F_13 ( V_12 -> V_53 ) ;
V_12 -> V_53 -> V_13 = NULL ;
}
static int F_19 ( struct V_1 * V_12 , T_2 type , T_1 V_22 ,
void * V_63 , unsigned V_49 )
{
struct V_8 * V_9 = V_12 -> V_53 ;
struct V_10 * V_11 ;
struct V_64 * V_53 ;
const unsigned V_65 = sizeof( * V_53 ) + V_49 ;
void * V_23 ;
int V_17 ;
V_11 = V_12 -> V_66 ;
V_12 -> V_66 = NULL ;
V_12 -> V_67 = false ;
V_11 -> V_49 = V_65 ;
V_53 = V_11 -> V_23 ;
V_23 = V_53 + 1 ;
V_53 -> V_68 = V_44 | V_36
| V_37 ;
V_53 -> V_69 = type ;
V_53 -> V_30 = F_20 ( V_22 ) ;
V_53 -> V_28 = F_20 ( V_12 -> V_39 ) ;
V_53 -> V_32 = F_20 ( V_49 ) ;
memcpy ( V_23 , V_63 , V_49 ) ;
F_21 ( & V_12 -> V_70 ) ;
V_17 = F_11 ( V_9 , V_11 , V_50 ) ;
F_22 ( & V_12 -> V_70 ) ;
if ( V_17 < 0 ) {
ERROR ( V_12 -> V_4 . V_5 . V_16 -> V_15 ,
L_11 ,
V_12 -> V_18 , V_17 ) ;
V_12 -> V_66 = V_11 ;
}
return V_17 ;
}
static int F_23 ( struct V_1 * V_12 )
{
struct V_14 * V_15 = V_12 -> V_4 . V_5 . V_16 -> V_15 ;
int V_17 ;
F_22 ( & V_12 -> V_70 ) ;
if ( V_12 -> V_66 ) {
F_5 ( V_15 , L_12 ,
V_12 -> V_18 , V_12 -> V_71 ) ;
V_17 = F_19 ( V_12 , V_72 ,
0 , & V_12 -> V_71 , sizeof( V_12 -> V_71 ) ) ;
} else {
V_12 -> V_67 = true ;
V_17 = 0 ;
}
F_21 ( & V_12 -> V_70 ) ;
return V_17 ;
}
static void F_24 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_12 = V_11 -> V_73 ;
T_2 V_74 = false ;
F_22 ( & V_12 -> V_70 ) ;
if ( V_11 -> V_17 != - V_75 )
V_74 = V_12 -> V_67 ;
V_12 -> V_66 = V_11 ;
F_21 ( & V_12 -> V_70 ) ;
if ( V_74 )
F_23 ( V_12 ) ;
}
static void F_25 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_71 |= V_76 | V_77 ;
F_23 ( V_12 ) ;
}
static void F_26 ( struct V_6 * V_4 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
V_12 -> V_71 &= ~ ( V_76 | V_77 ) ;
F_23 ( V_12 ) ;
}
static int F_27 ( struct V_6 * V_4 , int V_78 )
{
struct V_1 * V_12 = F_3 ( V_4 ) ;
T_1 V_79 ;
V_79 = V_12 -> V_71 ;
V_79 &= ~ V_80 ;
if ( V_78 )
V_79 |= V_80 ;
V_12 -> V_71 = V_79 ;
return F_23 ( V_12 ) ;
}
static int
F_28 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_14 * V_15 = V_82 -> V_15 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_17 ;
struct V_8 * V_9 ;
V_17 = F_29 ( V_82 , V_3 ) ;
if ( V_17 < 0 )
goto V_83;
V_12 -> V_39 = V_17 ;
V_84 . V_85 = V_17 ;
V_86 . V_87 = V_17 ;
V_88 . V_89 = V_17 ;
V_17 = F_29 ( V_82 , V_3 ) ;
if ( V_17 < 0 )
goto V_83;
V_12 -> V_57 = V_17 ;
V_90 . V_87 = V_17 ;
V_88 . V_91 = V_17 ;
V_92 . V_93 = V_17 ;
V_17 = - V_94 ;
V_9 = F_30 ( V_15 -> V_41 , & V_95 ) ;
if ( ! V_9 )
goto V_83;
V_12 -> V_4 . V_58 = V_9 ;
V_9 -> V_13 = V_15 ;
V_9 = F_30 ( V_15 -> V_41 , & V_96 ) ;
if ( ! V_9 )
goto V_83;
V_12 -> V_4 . V_61 = V_9 ;
V_9 -> V_13 = V_15 ;
V_9 = F_30 ( V_15 -> V_41 , & V_97 ) ;
if ( ! V_9 )
goto V_83;
V_12 -> V_53 = V_9 ;
V_9 -> V_13 = V_15 ;
V_12 -> V_66 = F_31 ( V_9 ,
sizeof( struct V_64 ) + 2 ,
V_98 ) ;
if ( ! V_12 -> V_66 )
goto V_83;
V_12 -> V_66 -> V_43 = F_24 ;
V_12 -> V_66 -> V_73 = V_12 ;
V_3 -> V_99 = F_32 ( V_100 ) ;
if ( ! V_3 -> V_99 )
goto V_83;
V_12 -> V_56 . V_58 = F_33 ( V_100 ,
V_3 -> V_99 , & V_95 ) ;
V_12 -> V_56 . V_61 = F_33 ( V_100 ,
V_3 -> V_99 , & V_96 ) ;
V_12 -> V_56 . V_53 = F_33 ( V_100 ,
V_3 -> V_99 , & V_97 ) ;
if ( F_34 ( V_82 -> V_15 -> V_41 ) ) {
V_101 . V_102 =
V_95 . V_102 ;
V_103 . V_102 =
V_96 . V_102 ;
V_104 . V_102 =
V_97 . V_102 ;
V_3 -> V_105 = F_32 ( V_106 ) ;
V_12 -> V_55 . V_58 = F_33 ( V_106 ,
V_3 -> V_105 , & V_101 ) ;
V_12 -> V_55 . V_61 = F_33 ( V_106 ,
V_3 -> V_105 , & V_103 ) ;
V_12 -> V_55 . V_53 = F_33 ( V_106 ,
V_3 -> V_105 , & V_104 ) ;
}
F_5 ( V_15 , L_13 ,
V_12 -> V_18 ,
F_34 ( V_82 -> V_15 -> V_41 ) ? L_14 : L_15 ,
V_12 -> V_4 . V_58 -> V_107 , V_12 -> V_4 . V_61 -> V_107 ,
V_12 -> V_53 -> V_107 ) ;
return 0 ;
V_83:
if ( V_12 -> V_66 )
F_35 ( V_12 -> V_53 , V_12 -> V_66 ) ;
if ( V_12 -> V_53 )
V_12 -> V_53 -> V_13 = NULL ;
if ( V_12 -> V_4 . V_61 )
V_12 -> V_4 . V_61 -> V_13 = NULL ;
if ( V_12 -> V_4 . V_58 )
V_12 -> V_4 . V_58 -> V_13 = NULL ;
ERROR ( V_15 , L_16 , V_3 -> V_107 , V_3 , V_17 ) ;
return V_17 ;
}
static void
F_36 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( F_34 ( V_82 -> V_15 -> V_41 ) )
F_37 ( V_3 -> V_105 ) ;
F_37 ( V_3 -> V_99 ) ;
F_35 ( V_12 -> V_53 , V_12 -> V_66 ) ;
F_38 ( V_12 ) ;
}
static inline bool F_39 ( struct V_81 * V_82 )
{
return true ;
}
int F_40 ( struct V_81 * V_82 , T_2 V_18 )
{
struct V_1 * V_12 ;
int V_17 ;
if ( ! F_39 ( V_82 ) )
return - V_62 ;
if ( V_108 [ V_109 ] . V_110 == 0 ) {
V_17 = F_41 ( V_82 -> V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_108 [ V_109 ] . V_110 = V_17 ;
V_86 . V_111 = V_17 ;
V_17 = F_41 ( V_82 -> V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_108 [ V_112 ] . V_110 = V_17 ;
V_90 . V_111 = V_17 ;
V_17 = F_41 ( V_82 -> V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
V_108 [ V_113 ] . V_110 = V_17 ;
V_84 . V_114 = V_17 ;
}
V_12 = F_42 ( sizeof *V_12 , V_98 ) ;
if ( ! V_12 )
return - V_115 ;
F_43 ( & V_12 -> V_70 ) ;
V_12 -> V_18 = V_18 ;
V_12 -> V_4 . V_116 = F_25 ;
V_12 -> V_4 . V_117 = F_26 ;
V_12 -> V_4 . V_118 = F_27 ;
V_12 -> V_4 . V_5 . V_107 = L_17 ;
V_12 -> V_4 . V_5 . V_119 = V_120 ;
V_12 -> V_4 . V_5 . V_121 = F_28 ;
V_12 -> V_4 . V_5 . V_122 = F_36 ;
V_12 -> V_4 . V_5 . V_123 = F_12 ;
V_12 -> V_4 . V_5 . V_124 = F_7 ;
V_12 -> V_4 . V_5 . V_125 = F_18 ;
V_17 = F_44 ( V_82 , & V_12 -> V_4 . V_5 ) ;
if ( V_17 )
F_38 ( V_12 ) ;
return V_17 ;
}
