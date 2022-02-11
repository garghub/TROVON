static struct V_1 * F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
struct V_1 * V_7 = NULL ;
F_2 ( & V_3 -> V_8 -> V_3 , L_1 ) ;
F_3 (pos, next, &dev->read_list.list, list)
if ( F_4 ( V_5 , V_6 -> V_5 ) )
return V_6 ;
return NULL ;
}
static int F_5 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
unsigned long V_11 ;
int V_12 ;
V_12 = - V_13 ;
if ( ! V_14 )
goto V_15;
V_3 = F_6 ( V_14 ) ;
if ( ! V_3 )
goto V_15;
F_7 ( & V_3 -> V_16 ) ;
V_12 = - V_17 ;
V_5 = F_8 ( V_3 ) ;
if ( ! V_5 )
goto V_18;
V_12 = - V_13 ;
if ( V_3 -> V_19 != V_20 ) {
F_2 ( & V_3 -> V_8 -> V_3 , L_2 ,
F_9 ( V_3 -> V_19 ) ) ;
goto V_18;
}
V_12 = - V_21 ;
if ( V_3 -> V_22 >= V_23 ) {
F_10 ( & V_3 -> V_8 -> V_3 , L_3 ,
V_23 ) ;
goto V_18;
}
V_11 = F_11 ( V_3 -> V_24 , V_25 ) ;
if ( V_11 >= V_25 ) {
F_10 ( & V_3 -> V_8 -> V_3 , L_4 ,
V_25 ) ;
goto V_18;
}
V_5 -> V_26 = V_11 ;
F_2 ( & V_3 -> V_8 -> V_3 , L_5 , V_5 -> V_26 ) ;
V_3 -> V_22 ++ ;
F_12 ( & V_5 -> V_27 , & V_3 -> V_28 ) ;
F_13 ( V_5 -> V_26 , V_3 -> V_24 ) ;
V_5 -> V_29 = V_30 ;
V_5 -> V_31 = 0 ;
V_10 -> V_32 = V_5 ;
F_14 ( & V_3 -> V_16 ) ;
return F_15 ( V_9 , V_10 ) ;
V_18:
F_14 ( & V_3 -> V_16 ) ;
F_16 ( V_5 ) ;
V_15:
return V_12 ;
}
static int F_17 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_32 ;
struct V_1 * V_33 ;
struct V_2 * V_3 ;
int V_34 = 0 ;
if ( F_18 ( ! V_5 || ! V_5 -> V_3 ) )
return - V_13 ;
V_3 = V_5 -> V_3 ;
F_7 ( & V_3 -> V_16 ) ;
if ( V_5 == & V_3 -> V_35 ) {
V_34 = F_19 ( V_3 , V_10 ) ;
goto V_15;
}
if ( V_5 -> V_29 == V_36 ) {
V_5 -> V_29 = V_37 ;
F_2 ( & V_3 -> V_8 -> V_3 ,
L_6
L_7 ,
V_5 -> V_26 ,
V_5 -> V_38 ) ;
V_34 = F_20 ( V_3 , V_5 ) ;
}
F_21 ( V_5 ) ;
F_2 ( & V_3 -> V_8 -> V_3 , L_8 ,
V_5 -> V_26 ,
V_5 -> V_38 ) ;
if ( V_3 -> V_22 > 0 ) {
F_22 ( V_5 -> V_26 , V_3 -> V_24 ) ;
V_3 -> V_22 -- ;
}
F_23 ( V_3 , V_5 ) ;
V_33 = NULL ;
if ( V_5 -> V_39 ) {
V_33 = F_1 ( V_3 , V_5 ) ;
if ( V_33 )
F_24 ( & V_33 -> V_40 ) ;
V_33 = V_5 -> V_39 ;
V_5 -> V_39 = NULL ;
}
V_10 -> V_32 = NULL ;
if ( V_33 ) {
F_25 ( V_33 ) ;
V_33 = NULL ;
}
F_16 ( V_5 ) ;
V_15:
F_14 ( & V_3 -> V_16 ) ;
return V_34 ;
}
static T_1 F_26 ( struct V_10 * V_10 , char T_2 * V_41 ,
T_3 V_42 , T_4 * V_43 )
{
struct V_4 * V_5 = V_10 -> V_32 ;
struct V_1 * V_44 = NULL ;
struct V_1 * V_33 = NULL ;
struct V_2 * V_3 ;
int V_45 ;
int V_34 ;
int V_12 ;
if ( F_18 ( ! V_5 || ! V_5 -> V_3 ) )
return - V_13 ;
V_3 = V_5 -> V_3 ;
F_7 ( & V_3 -> V_16 ) ;
if ( V_3 -> V_19 != V_20 ) {
V_34 = - V_13 ;
goto V_15;
}
if ( ( V_5 -> V_31 & V_46 ) == 0 ) {
V_45 = F_27 ( V_3 , & V_47 ) ;
if ( V_45 >= 0 ) {
struct V_48 * V_49 = & V_3 -> V_50 [ V_45 ] ;
if ( V_5 -> V_38 == V_49 -> V_51 ) {
V_34 = - V_52 ;
goto V_15;
}
}
} else {
V_5 -> V_31 &= ~ V_46 ;
}
if ( V_5 == & V_3 -> V_35 ) {
V_34 = F_28 ( V_3 , V_10 , V_41 , V_42 , V_43 ) ;
goto V_15;
}
if ( V_5 -> V_39 && V_5 -> V_39 -> V_53 > * V_43 ) {
V_33 = V_5 -> V_39 ;
goto V_54;
} else if ( V_5 -> V_39 && V_5 -> V_39 -> V_53 > 0 &&
V_5 -> V_39 -> V_53 <= * V_43 ) {
V_33 = V_5 -> V_39 ;
V_34 = 0 ;
goto free;
} else if ( ( ! V_5 -> V_39 || ! V_5 -> V_39 -> V_53 ) && * V_43 > 0 ) {
* V_43 = 0 ;
V_34 = 0 ;
goto V_15;
}
V_12 = F_29 ( V_3 , V_5 ) ;
if ( V_12 && V_12 != - V_55 ) {
F_2 ( & V_3 -> V_8 -> V_3 ,
L_9 , V_12 ) ;
V_34 = V_12 ;
goto V_15;
}
if ( V_56 != V_5 -> V_57 &&
! F_30 ( & V_5 -> V_58 ) ) {
if ( V_10 -> V_59 & V_60 ) {
V_34 = - V_61 ;
goto V_15;
}
F_14 ( & V_3 -> V_16 ) ;
if ( F_31 ( V_5 -> V_58 ,
( V_56 == V_5 -> V_57 ||
V_30 == V_5 -> V_29 ||
V_62 == V_5 -> V_29 ||
V_37 == V_5 -> V_29 ) ) ) {
if ( F_32 ( V_63 ) )
return - V_64 ;
return - V_65 ;
}
F_7 ( & V_3 -> V_16 ) ;
if ( V_30 == V_5 -> V_29 ||
V_62 == V_5 -> V_29 ||
V_37 == V_5 -> V_29 ) {
V_34 = - V_55 ;
goto V_15;
}
}
V_33 = V_5 -> V_39 ;
if ( ! V_33 ) {
V_34 = - V_13 ;
goto V_15;
}
if ( V_5 -> V_57 != V_56 ) {
V_34 = 0 ;
goto V_15;
}
V_54:
F_2 ( & V_3 -> V_8 -> V_3 , L_10 ,
V_33 -> V_66 . V_67 ) ;
F_2 ( & V_3 -> V_8 -> V_3 , L_11 , V_33 -> V_53 ) ;
if ( V_42 == 0 || V_41 == NULL || * V_43 > V_33 -> V_53 ) {
V_34 = - V_68 ;
goto free;
}
V_42 = F_33 ( T_3 , V_42 , V_33 -> V_53 - * V_43 ) ;
if ( F_34 ( V_41 , V_33 -> V_66 . V_69 + * V_43 , V_42 ) ) {
V_34 = - V_70 ;
goto free;
}
V_34 = V_42 ;
* V_43 += V_42 ;
if ( ( unsigned long ) * V_43 < V_33 -> V_53 )
goto V_15;
free:
V_44 = F_1 ( V_3 , V_5 ) ;
if ( V_44 )
F_24 ( & V_44 -> V_40 ) ;
F_25 ( V_33 ) ;
V_5 -> V_57 = V_71 ;
V_5 -> V_39 = NULL ;
V_5 -> V_72 = 0 ;
V_15:
F_2 ( & V_3 -> V_8 -> V_3 , L_12 , V_34 ) ;
F_14 ( & V_3 -> V_16 ) ;
return V_34 ;
}
static T_1 F_35 ( struct V_10 * V_10 , const char T_2 * V_41 ,
T_3 V_42 , T_4 * V_43 )
{
struct V_4 * V_5 = V_10 -> V_32 ;
struct V_1 * V_73 = NULL ;
struct V_74 V_75 ;
struct V_2 * V_3 ;
unsigned long V_76 = 0 ;
int V_34 ;
int V_45 ;
if ( F_18 ( ! V_5 || ! V_5 -> V_3 ) )
return - V_13 ;
V_3 = V_5 -> V_3 ;
F_7 ( & V_3 -> V_16 ) ;
if ( V_3 -> V_19 != V_20 ) {
V_34 = - V_13 ;
goto V_12;
}
V_45 = F_36 ( V_3 , V_5 -> V_38 ) ;
if ( V_45 < 0 ) {
V_34 = - V_13 ;
goto V_12;
}
if ( V_42 > V_3 -> V_50 [ V_45 ] . V_77 . V_78 || V_42 <= 0 ) {
V_34 = - V_68 ;
goto V_12;
}
if ( V_5 -> V_29 != V_36 ) {
V_34 = - V_13 ;
F_10 ( & V_3 -> V_8 -> V_3 , L_13 ,
V_5 -> V_26 , V_5 -> V_38 ) ;
goto V_12;
}
if ( V_5 == & V_3 -> V_35 ) {
V_73 = F_37 ( V_3 , V_10 ) ;
if ( V_73 ) {
V_76 = V_73 -> V_79 +
F_38 ( V_80 ) ;
if ( F_39 ( V_81 , V_76 ) ||
V_5 -> V_57 == V_56 ) {
* V_43 = 0 ;
F_24 ( & V_73 -> V_40 ) ;
F_25 ( V_73 ) ;
V_73 = NULL ;
}
}
}
if ( V_5 -> V_57 == V_56 ) {
* V_43 = 0 ;
V_73 = F_1 ( V_3 , V_5 ) ;
if ( V_73 ) {
F_24 ( & V_73 -> V_40 ) ;
F_25 ( V_73 ) ;
V_73 = NULL ;
V_5 -> V_57 = V_71 ;
V_5 -> V_39 = NULL ;
V_5 -> V_72 = 0 ;
}
} else if ( V_5 -> V_57 == V_71 && ! V_5 -> V_72 )
* V_43 = 0 ;
V_73 = F_40 ( V_5 , V_10 ) ;
if ( ! V_73 ) {
F_10 ( & V_3 -> V_8 -> V_3 , L_14 ) ;
V_34 = - V_17 ;
goto V_12;
}
V_34 = F_41 ( V_73 , V_42 ) ;
if ( V_34 )
goto V_12;
F_2 ( & V_3 -> V_8 -> V_3 , L_15 , V_42 ) ;
V_34 = F_42 ( V_73 -> V_82 . V_69 , V_41 , V_42 ) ;
if ( V_34 )
goto V_12;
V_5 -> V_31 = 0 ;
if ( V_42 == 4 &&
( ( memcmp ( V_83 [ 0 ] ,
V_73 -> V_82 . V_69 , 4 ) == 0 ) ||
( memcmp ( V_83 [ 1 ] ,
V_73 -> V_82 . V_69 , 4 ) == 0 ) ||
( memcmp ( V_83 [ 2 ] ,
V_73 -> V_82 . V_69 , 4 ) == 0 ) ) )
V_5 -> V_31 |= V_46 ;
if ( V_5 == & V_3 -> V_35 ) {
V_34 = F_43 ( V_3 , V_73 ) ;
if ( V_34 ) {
F_10 ( & V_3 -> V_8 -> V_3 ,
L_16 , V_34 ) ;
goto V_12;
}
F_14 ( & V_3 -> V_16 ) ;
return V_42 ;
}
V_73 -> V_84 = V_85 ;
F_2 ( & V_3 -> V_8 -> V_3 , L_17 ,
V_5 -> V_26 , V_5 -> V_38 ) ;
V_34 = F_44 ( V_3 , V_5 ) ;
if ( V_34 < 0 )
goto V_12;
if ( V_34 == 0 || V_3 -> V_86 == false ) {
V_73 -> V_53 = 0 ;
V_75 . V_87 = 0 ;
V_5 -> V_88 = V_89 ;
goto V_15;
}
V_3 -> V_86 = false ;
if ( V_42 > F_45 ( V_3 ) ) {
V_75 . V_42 = F_45 ( V_3 ) ;
V_75 . V_87 = 0 ;
} else {
V_75 . V_42 = V_42 ;
V_75 . V_87 = 1 ;
}
V_75 . V_90 = V_5 -> V_26 ;
V_75 . V_91 = V_5 -> V_38 ;
V_75 . V_92 = 0 ;
F_2 ( & V_3 -> V_8 -> V_3 , L_18 ,
* ( ( V_93 * ) & V_75 ) ) ;
if ( F_46 ( V_3 , & V_75 ,
V_73 -> V_82 . V_69 , V_75 . V_42 ) ) {
V_34 = - V_13 ;
goto V_12;
}
V_5 -> V_88 = V_89 ;
V_73 -> V_53 = V_75 . V_42 ;
V_15:
if ( V_75 . V_87 ) {
if ( F_47 ( V_3 , V_5 ) ) {
V_34 = - V_13 ;
goto V_12;
}
F_12 ( & V_73 -> V_40 , & V_3 -> V_94 . V_40 ) ;
} else {
F_12 ( & V_73 -> V_40 , & V_3 -> V_95 . V_40 ) ;
}
F_14 ( & V_3 -> V_16 ) ;
return V_42 ;
V_12:
F_14 ( & V_3 -> V_16 ) ;
F_25 ( V_73 ) ;
return V_34 ;
}
static long F_48 ( struct V_10 * V_10 , unsigned int V_96 , unsigned long V_69 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 = V_10 -> V_32 ;
struct V_97 * V_98 = NULL ;
int V_34 ;
if ( V_96 != V_99 )
return - V_100 ;
if ( F_18 ( ! V_5 || ! V_5 -> V_3 ) )
return - V_13 ;
V_3 = V_5 -> V_3 ;
F_2 ( & V_3 -> V_8 -> V_3 , L_19 , V_96 ) ;
F_7 ( & V_3 -> V_16 ) ;
if ( V_3 -> V_19 != V_20 ) {
V_34 = - V_13 ;
goto V_15;
}
F_2 ( & V_3 -> V_8 -> V_3 , L_20 ) ;
V_98 = F_49 ( sizeof( struct V_97 ) ,
V_101 ) ;
if ( ! V_98 ) {
V_34 = - V_17 ;
goto V_15;
}
F_2 ( & V_3 -> V_8 -> V_3 , L_21 ) ;
if ( F_42 ( V_98 , ( char T_2 * ) V_69 ,
sizeof( struct V_97 ) ) ) {
F_2 ( & V_3 -> V_8 -> V_3 , L_22 ) ;
V_34 = - V_70 ;
goto V_15;
}
V_34 = F_50 ( V_10 , V_98 ) ;
if ( V_34 )
goto V_15;
F_2 ( & V_3 -> V_8 -> V_3 , L_23 ) ;
if ( F_34 ( ( char T_2 * ) V_69 , V_98 ,
sizeof( struct V_97 ) ) ) {
F_2 ( & V_3 -> V_8 -> V_3 , L_24 ) ;
V_34 = - V_70 ;
goto V_15;
}
V_15:
F_16 ( V_98 ) ;
F_14 ( & V_3 -> V_16 ) ;
return V_34 ;
}
static long F_51 ( struct V_10 * V_10 ,
unsigned int V_96 , unsigned long V_69 )
{
return F_48 ( V_10 , V_96 , ( unsigned long ) F_52 ( V_69 ) ) ;
}
static unsigned int F_53 ( struct V_10 * V_10 , T_5 * V_102 )
{
struct V_4 * V_5 = V_10 -> V_32 ;
struct V_2 * V_3 ;
unsigned int V_103 = 0 ;
if ( F_18 ( ! V_5 || ! V_5 -> V_3 ) )
return V_103 ;
V_3 = V_5 -> V_3 ;
F_7 ( & V_3 -> V_16 ) ;
if ( V_3 -> V_19 != V_20 )
goto V_15;
if ( V_5 == & V_3 -> V_35 ) {
V_103 = F_54 ( V_3 , V_10 , V_102 ) ;
goto V_15;
}
F_14 ( & V_3 -> V_16 ) ;
F_55 ( V_10 , & V_5 -> V_104 , V_102 ) ;
F_7 ( & V_3 -> V_16 ) ;
if ( V_105 == V_5 -> V_88 )
V_103 |= ( V_106 | V_107 ) ;
V_15:
F_14 ( & V_3 -> V_16 ) ;
return V_103 ;
}
static bool F_56 ( struct V_108 * V_8 ,
const struct V_109 * V_110 )
{
V_93 V_111 ;
if ( V_110 -> V_112 == V_113 ) {
F_57 ( V_8 , 0x48 , & V_111 ) ;
if ( ( V_111 & 0x600 ) == 0x200 ) {
F_58 ( & V_8 -> V_3 , L_25 ) ;
return false ;
}
}
return true ;
}
static int F_59 ( struct V_108 * V_8 ,
const struct V_109 * V_110 )
{
struct V_2 * V_3 ;
int V_12 ;
F_7 ( & V_114 ) ;
if ( ! F_56 ( V_8 , V_110 ) ) {
V_12 = - V_13 ;
goto V_115;
}
if ( V_14 ) {
V_12 = - V_116 ;
goto V_115;
}
V_12 = F_60 ( V_8 ) ;
if ( V_12 ) {
F_10 ( & V_8 -> V_3 , L_26 ) ;
goto V_115;
}
F_61 ( V_8 ) ;
V_12 = F_62 ( V_8 , V_117 ) ;
if ( V_12 ) {
F_10 ( & V_8 -> V_3 , L_27 ) ;
goto V_118;
}
V_3 = F_63 ( V_8 ) ;
if ( ! V_3 ) {
V_12 = - V_17 ;
goto V_119;
}
V_3 -> V_120 = F_64 ( V_8 , 0 , 0 ) ;
if ( ! V_3 -> V_120 ) {
F_10 ( & V_8 -> V_3 , L_28 ) ;
V_12 = - V_17 ;
goto V_121;
}
F_65 ( V_8 ) ;
if ( F_66 ( V_8 ) )
V_12 = F_67 ( V_8 -> V_122 ,
NULL ,
V_123 ,
V_124 , V_117 , V_3 ) ;
else
V_12 = F_67 ( V_8 -> V_122 ,
V_125 ,
V_123 ,
V_126 , V_117 , V_3 ) ;
if ( V_12 ) {
F_10 ( & V_8 -> V_3 , L_29 ,
V_8 -> V_122 ) ;
goto V_127;
}
F_68 ( & V_3 -> V_128 , V_129 ) ;
F_69 ( & V_3 -> V_130 , V_131 ) ;
if ( F_70 ( V_3 ) ) {
F_10 ( & V_8 -> V_3 , L_30 ) ;
V_12 = - V_13 ;
goto V_132;
}
V_12 = F_71 ( & V_133 ) ;
if ( V_12 )
goto V_132;
V_14 = V_8 ;
F_72 ( V_8 , V_3 ) ;
F_73 ( & V_3 -> V_128 , V_134 ) ;
F_14 ( & V_114 ) ;
F_74 ( L_31 ) ;
return 0 ;
V_132:
V_3 -> V_135 = F_75 ( V_3 ) ;
F_76 ( V_3 ) ;
F_77 () ;
F_78 ( V_8 -> V_122 , V_3 ) ;
V_127:
F_79 ( V_8 ) ;
F_80 ( V_8 , V_3 -> V_120 ) ;
V_121:
F_16 ( V_3 ) ;
V_119:
F_81 ( V_8 ) ;
V_118:
F_82 ( V_8 ) ;
V_115:
F_14 ( & V_114 ) ;
F_10 ( & V_8 -> V_3 , L_32 ) ;
return V_12 ;
}
static void F_83 ( struct V_108 * V_8 )
{
struct V_2 * V_3 ;
if ( V_14 != V_8 )
return;
V_3 = F_6 ( V_8 ) ;
if ( ! V_3 )
return;
F_7 ( & V_3 -> V_16 ) ;
F_84 ( & V_3 -> V_128 ) ;
F_85 ( V_3 ) ;
V_14 = NULL ;
if ( V_3 -> V_35 . V_29 == V_36 ) {
V_3 -> V_35 . V_29 = V_37 ;
F_20 ( V_3 , & V_3 -> V_35 ) ;
}
if ( V_3 -> V_136 . V_29 == V_36 ) {
V_3 -> V_136 . V_29 = V_37 ;
F_20 ( V_3 , & V_3 -> V_136 ) ;
}
F_86 ( V_3 ) ;
F_2 ( & V_8 -> V_3 , L_33 ) ;
F_23 ( V_3 , & V_3 -> V_136 ) ;
F_23 ( V_3 , & V_3 -> V_35 ) ;
V_3 -> V_137 = NULL ;
V_3 -> V_138 = 0 ;
F_14 ( & V_3 -> V_16 ) ;
F_77 () ;
F_76 ( V_3 ) ;
F_78 ( V_8 -> V_122 , V_3 ) ;
F_79 ( V_8 ) ;
F_72 ( V_8 , NULL ) ;
if ( V_3 -> V_120 )
F_80 ( V_8 , V_3 -> V_120 ) ;
F_16 ( V_3 ) ;
F_81 ( V_8 ) ;
F_82 ( V_8 ) ;
F_87 ( & V_133 ) ;
}
static int F_88 ( struct V_112 * V_112 )
{
struct V_108 * V_8 = F_89 ( V_112 ) ;
struct V_2 * V_3 = F_6 ( V_8 ) ;
int V_12 ;
if ( ! V_3 )
return - V_13 ;
F_7 ( & V_3 -> V_16 ) ;
F_84 ( & V_3 -> V_128 ) ;
V_12 = F_85 ( V_3 ) ;
if ( V_3 -> V_19 == V_20 ||
V_3 -> V_19 == V_139 ) {
V_3 -> V_19 = V_140 ;
F_90 ( V_3 , 0 ) ;
}
F_14 ( & V_3 -> V_16 ) ;
F_78 ( V_8 -> V_122 , V_3 ) ;
F_79 ( V_8 ) ;
return V_12 ;
}
static int F_91 ( struct V_112 * V_112 )
{
struct V_108 * V_8 = F_89 ( V_112 ) ;
struct V_2 * V_3 ;
int V_12 ;
V_3 = F_6 ( V_8 ) ;
if ( ! V_3 )
return - V_13 ;
F_65 ( V_8 ) ;
if ( F_66 ( V_8 ) )
V_12 = F_67 ( V_8 -> V_122 ,
NULL ,
V_123 ,
V_124 , V_117 , V_3 ) ;
else
V_12 = F_67 ( V_8 -> V_122 ,
V_125 ,
V_123 ,
V_126 , V_117 , V_3 ) ;
if ( V_12 ) {
F_10 ( & V_8 -> V_3 , L_34 ,
V_8 -> V_122 ) ;
return V_12 ;
}
F_7 ( & V_3 -> V_16 ) ;
V_3 -> V_19 = V_141 ;
F_90 ( V_3 , 1 ) ;
F_14 ( & V_3 -> V_16 ) ;
F_73 ( & V_3 -> V_128 , V_134 ) ;
return V_12 ;
}
