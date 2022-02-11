int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 . V_6 . V_7 )
return 0 ;
V_4 -> V_8 = true ;
V_4 -> V_9 = true ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 100 ;
if ( 0 != V_2 -> V_5 . V_6 . V_12 ) {
V_4 -> V_13 = true ;
V_4 -> V_14 = true ;
V_4 -> V_15 = V_2 -> V_5 . V_6 . V_16 ;
V_4 -> V_17 = V_2 -> V_5 . V_6 . V_18 ;
} else {
V_4 -> V_15 = 0 ;
V_4 -> V_17 = 0 ;
}
return 0 ;
}
int F_2 ( struct V_1 * V_2 , T_1 * V_19 )
{
T_1 V_20 ;
T_1 V_21 ;
T_2 V_22 ;
if ( V_2 -> V_5 . V_6 . V_7 )
return 0 ;
V_20 = F_3 ( V_2 -> V_23 , V_24 , V_25 , V_26 ) ;
V_21 = F_3 ( V_2 -> V_23 , V_24 , V_27 , V_28 ) ;
if ( 0 == V_20 )
return - V_29 ;
V_22 = ( T_2 ) V_21 * 100 ;
F_4 ( V_22 , V_20 ) ;
* V_19 = ( T_1 ) V_22 ;
if ( * V_19 > 100 )
* V_19 = 100 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_19 )
{
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_30 )
{
if ( V_2 -> V_31 ) {
V_2 -> V_32 = F_3 ( V_2 -> V_23 , V_24 , V_33 , V_34 ) ;
V_2 -> V_35 = F_3 ( V_2 -> V_23 , V_24 , V_33 , V_36 ) ;
V_2 -> V_31 = false ;
}
F_7 ( V_2 -> V_23 , V_24 , V_33 , V_36 , 0 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_33 , V_34 , V_30 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 ) {
F_7 ( V_2 -> V_23 , V_24 , V_33 , V_34 , V_2 -> V_32 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_33 , V_36 , V_2 -> V_35 ) ;
V_2 -> V_31 = true ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_37 ;
if ( F_10 ( V_2 -> V_38 . V_39 , V_40 ) ) {
F_11 ( V_2 -> V_23 , V_41 , V_42 ) ;
V_37 = ( F_12 ( V_2 -> V_43 , V_44 ) == 0 ) ? 0 : - V_29 ;
} else {
F_11 ( V_2 -> V_23 , V_41 , V_45 ) ;
V_37 = ( F_12 ( V_2 -> V_43 , V_44 ) == 0 ) ? 0 : - V_29 ;
}
return V_37 ;
}
int F_13 ( struct V_1 * V_2 )
{
return ( F_12 ( V_2 -> V_43 , V_46 ) == 0 ) ? 0 : - V_29 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_19 )
{
T_1 V_20 ;
T_1 V_21 ;
T_2 V_22 ;
if ( V_2 -> V_5 . V_6 . V_7 )
return - V_29 ;
if ( V_19 > 100 )
V_19 = 100 ;
if ( F_10 ( V_2 -> V_38 . V_39 , V_47 ) )
F_13 ( V_2 ) ;
V_20 = F_3 ( V_2 -> V_23 , V_24 , V_25 , V_26 ) ;
if ( 0 == V_20 )
return - V_29 ;
V_22 = ( T_2 ) V_19 * V_20 ;
F_4 ( V_22 , 100 ) ;
V_21 = ( T_1 ) V_22 ;
F_7 ( V_2 -> V_23 , V_24 , V_48 , V_49 , V_21 ) ;
return F_6 ( V_2 , V_50 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_5 . V_6 . V_7 )
return 0 ;
if ( F_10 ( V_2 -> V_38 . V_39 , V_47 ) ) {
V_37 = F_6 ( V_2 , V_50 ) ;
if ( 0 == V_37 )
V_37 = F_9 ( V_2 ) ;
} else
V_37 = F_8 ( V_2 ) ;
return V_37 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_19 )
{
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_3 ( V_2 -> V_23 , V_24 , V_52 , V_53 ) ;
if ( 0 != ( 0x200 & V_51 ) )
V_51 = V_54 ;
else
V_51 = ( V_51 & 0x1ff ) ;
V_51 = V_51 * V_55 ;
return V_51 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_56 , T_1 V_57 )
{
T_1 V_58 = V_59 * V_55 ;
T_1 V_60 = V_61 * V_55 ;
if ( V_58 < V_56 )
V_58 = V_56 ;
if ( V_60 > V_57 )
V_60 = V_57 ;
if ( V_58 > V_60 )
return - V_29 ;
F_7 ( V_2 -> V_23 , V_24 , V_62 , V_63 , ( V_60 / V_55 ) ) ;
F_7 ( V_2 -> V_23 , V_24 , V_62 , V_64 , ( V_58 / V_55 ) ) ;
F_7 ( V_2 -> V_23 , V_24 , V_65 , V_66 , ( V_60 / V_55 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( 0 != V_2 -> V_5 . V_6 . V_12 )
F_7 ( V_2 -> V_23 , V_24 ,
V_67 , V_68 ,
V_2 -> V_5 . V_6 . V_12 - 1 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_33 , V_69 , 0x28 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_70 ;
V_70 = F_3 ( V_2 -> V_23 , V_24 , V_62 , V_71 ) ;
V_70 &= ~ ( V_72 | V_73 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_62 , V_71 , V_70 ) ;
return ( F_12 ( V_2 -> V_43 , V_74 ) == 0 ) ? 0 : - 1 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_70 ;
V_70 = F_3 ( V_2 -> V_23 , V_24 , V_62 , V_71 ) ;
V_70 |= ( V_72 | V_73 ) ;
F_7 ( V_2 -> V_23 , V_24 , V_62 , V_71 , V_70 ) ;
return ( F_12 ( V_2 -> V_43 , V_75 ) == 0 ) ? 0 : - 1 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_37 = F_21 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 . V_7 )
F_8 ( V_2 ) ;
return V_37 ;
}
int F_23 ( struct V_1 * V_2 , void * V_76 , void * V_77 , void * V_78 , int V_37 )
{
struct V_79 * V_80 = (struct V_79 * ) ( V_2 -> V_81 ) ;
T_3 V_82 = { V_83 } ;
T_1 V_20 ;
T_1 V_84 , V_85 , V_86 , V_87 ;
T_4 V_88 , V_89 , V_90 ;
T_1 V_91 ;
int V_92 ;
T_2 V_22 ;
if ( ! F_10 ( V_2 -> V_38 . V_39 , V_47 ) )
return 0 ;
if ( 0 == V_80 -> V_93 ) {
F_24 ( V_2 -> V_38 . V_39 , V_47 ) ;
return 0 ;
}
V_20 = F_3 ( V_2 -> V_23 , V_24 , V_25 , V_26 ) ;
if ( 0 == V_20 ) {
F_24 ( V_2 -> V_38 . V_39 , V_47 ) ;
return 0 ;
}
V_22 = V_2 -> V_5 . V_94 . V_95 * V_20 ;
F_4 ( V_22 , 10000 ) ;
V_88 = ( T_4 ) V_22 ;
V_84 = V_2 -> V_5 . V_94 . V_96 - V_2 -> V_5 . V_94 . V_97 ;
V_85 = V_2 -> V_5 . V_94 . V_98 - V_2 -> V_5 . V_94 . V_96 ;
V_86 = V_2 -> V_5 . V_94 . V_99 - V_2 -> V_5 . V_94 . V_95 ;
V_87 = V_2 -> V_5 . V_94 . V_100 - V_2 -> V_5 . V_94 . V_99 ;
V_89 = ( T_4 ) ( ( 50 + ( ( 16 * V_20 * V_86 ) / V_84 ) ) / 100 ) ;
V_90 = ( T_4 ) ( ( 50 + ( ( 16 * V_20 * V_87 ) / V_85 ) ) / 100 ) ;
V_82 . V_101 = F_25 ( ( 50 + V_2 -> V_5 . V_94 . V_97 ) / 100 ) ;
V_82 . V_102 = F_25 ( ( 50 + V_2 -> V_5 . V_94 . V_96 ) / 100 ) ;
V_82 . V_103 = F_25 ( ( 50 + V_2 -> V_5 . V_94 . V_104 ) / 100 ) ;
V_82 . V_105 = F_25 ( V_89 ) ;
V_82 . V_106 = F_25 ( V_90 ) ;
V_82 . V_107 = F_25 ( V_88 ) ;
V_82 . V_108 = F_25 ( V_2 -> V_5 . V_94 . V_109 ) ;
V_82 . V_110 = F_25 ( 1 ) ;
V_82 . V_111 = F_25 ( 1 ) ;
V_82 . V_112 = F_25 ( 5 ) ;
V_91 = F_26 ( V_2 ) ;
V_82 . V_113 = F_27 ( ( V_2 -> V_5 . V_94 . V_114 * V_91 ) / 1600 ) ;
V_82 . V_115 = F_25 ( ( T_4 ) V_20 ) ;
V_82 . V_116 = ( V_117 ) F_3 ( V_2 -> V_23 , V_24 , V_118 , V_119 ) ;
V_82 . V_120 = 1 ;
V_92 = F_28 ( V_2 -> V_43 , V_80 -> V_93 , ( V_117 * ) & V_82 , ( T_1 ) sizeof( V_82 ) , V_80 -> V_121 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , void * V_76 , void * V_77 , void * V_78 , int V_37 )
{
if ( F_10 ( V_2 -> V_38 . V_39 , V_47 ) ) {
F_9 ( V_2 ) ;
F_6 ( V_2 , V_50 ) ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 , void * V_76 , void * V_77 , void * V_78 , int V_37 )
{
struct V_122 * V_123 = (struct V_122 * ) V_76 ;
if ( V_123 == NULL )
return - V_29 ;
return F_18 ( V_2 , V_123 -> V_124 , V_123 -> V_125 ) ;
}
int F_31 ( struct V_1 * V_2 , void * V_76 , void * V_77 , void * V_78 , int V_37 )
{
return F_19 ( V_2 ) ;
}
int F_32 ( struct V_1 * V_2 , void * V_76 , void * V_77 , void * V_78 , int V_37 )
{
return F_20 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 , void * V_76 , void * V_77 , void * V_78 , int V_37 )
{
return F_21 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_6 . V_7 )
F_8 ( V_2 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_37 ;
V_37 = F_36 ( V_2 , & V_126 , & ( V_2 -> V_127 ) ) ;
if ( 0 == V_37 ) {
V_37 = F_36 ( V_2 ,
& V_128 ,
& ( V_2 -> V_129 ) ) ;
if ( 0 != V_37 )
F_37 ( V_2 , & ( V_2 -> V_127 ) ) ;
}
if ( 0 == V_37 )
V_2 -> V_31 = true ;
return V_37 ;
}
