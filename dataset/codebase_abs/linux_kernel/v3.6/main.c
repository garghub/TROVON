static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_6 * V_8 = NULL ;
struct V_3 * V_9 ;
bool V_10 = false ;
F_2 (cb_pos, cb_next, mei_cb_list, cb_list) {
V_9 = (struct V_3 * ) V_7 -> V_11 ;
if ( V_9 == V_3 ) {
F_3 ( & V_7 -> V_12 ) ;
if ( V_2 -> V_13 == V_7 ) {
V_2 -> V_13 = NULL ;
F_4 ( V_2 , & V_2 -> V_14 ) ;
}
F_5 ( V_7 ) ;
V_7 = NULL ;
V_10 = true ;
}
}
return V_10 ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
bool V_10 = false ;
F_1 ( V_2 , V_3 , & V_2 -> V_15 . V_16 . V_12 ) ;
if ( F_1 ( V_2 , V_3 ,
& V_2 -> V_17 . V_16 . V_12 ) )
V_10 = true ;
F_1 ( V_2 , V_3 , & V_2 -> V_18 . V_16 . V_12 ) ;
if ( F_1 ( V_2 , V_3 , & V_2 -> V_19 . V_16 . V_12 ) )
V_10 = true ;
if ( F_1 ( V_2 , V_3 , & V_2 -> V_20 . V_16 . V_12 ) )
V_10 = true ;
if ( F_1 ( V_2 , V_3 , & V_2 -> V_21 . V_16 . V_12 ) )
V_10 = true ;
if ( V_2 -> V_13 && ! V_10 ) {
if ( V_2 -> V_13 -> V_11 == V_3 ) {
F_5 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_10 = true ;
}
}
return V_10 ;
}
static struct V_6 * F_7 (
struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_6 * V_24 = NULL ;
struct V_6 * V_25 = NULL ;
F_8 ( & V_2 -> V_26 -> V_2 , L_1 ) ;
F_2 (pos, next,
&dev->read_list.mei_cb.cb_list, cb_list) {
struct V_22 * V_27 ;
V_27 = (struct V_22 * ) V_24 -> V_28 ;
if ( F_9 ( V_23 , V_27 ) )
return V_24 ;
}
return NULL ;
}
static int F_10 ( struct V_29 * V_29 , struct V_3 * V_3 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
unsigned long V_30 ;
int V_31 ;
V_31 = - V_32 ;
if ( ! V_1 )
goto V_33;
V_2 = F_11 ( V_1 ) ;
if ( ! V_2 )
goto V_33;
F_12 ( & V_2 -> V_34 ) ;
V_31 = - V_35 ;
V_23 = F_13 ( V_2 ) ;
if ( ! V_23 )
goto V_36;
V_31 = - V_32 ;
if ( V_2 -> V_37 != V_38 ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_2 ,
V_2 -> V_37 ) ;
goto V_36;
}
V_31 = - V_39 ;
if ( V_2 -> V_40 >= V_41 )
goto V_36;
V_30 = F_14 ( V_2 -> V_42 , V_43 ) ;
if ( V_30 >= V_43 )
goto V_36;
V_23 -> V_44 = V_30 ;
F_8 ( & V_2 -> V_26 -> V_2 , L_3 , V_23 -> V_44 ) ;
V_2 -> V_40 ++ ;
F_15 ( & V_23 -> V_45 , & V_2 -> V_46 ) ;
F_16 ( V_23 -> V_44 , V_2 -> V_42 ) ;
V_23 -> V_47 = V_48 ;
V_23 -> V_49 = 0 ;
V_3 -> V_50 = V_23 ;
F_17 ( & V_2 -> V_34 ) ;
return F_18 ( V_29 , V_3 ) ;
V_36:
F_17 ( & V_2 -> V_34 ) ;
F_19 ( V_23 ) ;
V_33:
return V_31 ;
}
static int F_20 ( struct V_29 * V_29 , struct V_3 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_50 ;
struct V_6 * V_51 ;
struct V_1 * V_2 ;
int V_52 = 0 ;
if ( F_21 ( ! V_23 || ! V_23 -> V_2 ) )
return - V_32 ;
V_2 = V_23 -> V_2 ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_23 != & V_2 -> V_14 ) {
if ( V_23 -> V_47 == V_53 ) {
V_23 -> V_47 = V_54 ;
F_8 ( & V_2 -> V_26 -> V_2 ,
L_4
L_5 ,
V_23 -> V_44 ,
V_23 -> V_55 ) ;
V_52 = F_22 ( V_2 , V_23 ) ;
}
F_23 ( V_23 ) ;
F_8 ( & V_2 -> V_26 -> V_2 , L_6 ,
V_23 -> V_44 ,
V_23 -> V_55 ) ;
if ( V_2 -> V_40 > 0 ) {
F_24 ( V_23 -> V_44 , V_2 -> V_42 ) ;
V_2 -> V_40 -- ;
}
F_25 ( V_2 , V_23 -> V_44 ) ;
V_51 = NULL ;
if ( V_23 -> V_56 ) {
V_51 = F_7 ( V_2 , V_23 ) ;
if ( V_51 )
F_3 ( & V_51 -> V_12 ) ;
V_51 = V_23 -> V_56 ;
V_23 -> V_56 = NULL ;
}
V_3 -> V_50 = NULL ;
if ( V_51 ) {
F_5 ( V_51 ) ;
V_51 = NULL ;
}
F_19 ( V_23 ) ;
} else {
if ( V_2 -> V_40 > 0 )
V_2 -> V_40 -- ;
if ( V_2 -> V_57 == V_3 &&
V_2 -> V_58 != V_59 ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_7 ,
V_2 -> V_58 ) ;
V_2 -> V_60 = true ;
if ( V_2 -> V_58 == V_61 ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_8 ) ;
F_26 ( V_2 ) ;
}
}
if ( F_6 ( V_2 , V_3 ) )
V_2 -> V_58 = V_59 ;
}
F_17 ( & V_2 -> V_34 ) ;
return V_52 ;
}
static T_1 F_27 ( struct V_3 * V_3 , char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_22 * V_23 = V_3 -> V_50 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_51 = NULL ;
struct V_1 * V_2 ;
int V_65 ;
int V_52 ;
int V_31 ;
if ( F_21 ( ! V_23 || ! V_23 -> V_2 ) )
return - V_32 ;
V_2 = V_23 -> V_2 ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_37 != V_38 ) {
V_52 = - V_32 ;
goto V_33;
}
if ( ( V_23 -> V_49 & V_66 ) == 0 ) {
V_65 = F_28 ( V_2 , V_67 ) ;
if ( V_65 >= 0 ) {
struct V_68 * V_69 = & V_2 -> V_70 [ V_65 ] ;
if ( V_23 -> V_55 == V_69 -> V_71 ) {
V_52 = - V_72 ;
goto V_33;
}
}
} else {
V_23 -> V_49 &= ~ V_66 ;
}
if ( V_23 == & V_2 -> V_14 ) {
V_52 = F_29 ( V_2 , V_3 , V_62 , V_63 , V_64 ) ;
goto V_33;
}
if ( V_23 -> V_56 && V_23 -> V_56 -> V_73 > * V_64 ) {
V_51 = V_23 -> V_56 ;
goto V_74;
} else if ( V_23 -> V_56 && V_23 -> V_56 -> V_73 > 0 &&
V_23 -> V_56 -> V_73 <= * V_64 ) {
V_51 = V_23 -> V_56 ;
V_52 = 0 ;
goto free;
} else if ( ( ! V_23 -> V_56 || ! V_23 -> V_56 -> V_73 ) &&
* V_64 > 0 ) {
* V_64 = 0 ;
V_52 = 0 ;
goto V_33;
}
V_31 = F_30 ( V_2 , V_23 ) ;
if ( V_31 && V_31 != - V_75 ) {
F_8 ( & V_2 -> V_26 -> V_2 ,
L_9 , V_31 ) ;
V_52 = V_31 ;
goto V_33;
}
if ( V_76 != V_23 -> V_77 &&
! F_31 ( & V_23 -> V_78 ) ) {
if ( V_3 -> V_79 & V_80 ) {
V_52 = - V_81 ;
goto V_33;
}
F_17 ( & V_2 -> V_34 ) ;
if ( F_32 ( V_23 -> V_78 ,
( V_76 == V_23 -> V_77 ||
V_48 == V_23 -> V_47 ||
V_82 == V_23 -> V_47 ||
V_54 == V_23 -> V_47 ) ) ) {
if ( F_33 ( V_83 ) )
return - V_84 ;
return - V_85 ;
}
F_12 ( & V_2 -> V_34 ) ;
if ( V_48 == V_23 -> V_47 ||
V_82 == V_23 -> V_47 ||
V_54 == V_23 -> V_47 ) {
V_52 = - V_75 ;
goto V_33;
}
}
V_51 = V_23 -> V_56 ;
if ( ! V_51 ) {
V_52 = - V_32 ;
goto V_33;
}
if ( V_23 -> V_77 != V_76 ) {
V_52 = 0 ;
goto V_33;
}
V_74:
F_8 ( & V_2 -> V_26 -> V_2 , L_10 ,
V_51 -> V_86 . V_87 ) ;
F_8 ( & V_2 -> V_26 -> V_2 , L_11 ,
V_51 -> V_73 ) ;
if ( V_63 == 0 || V_62 == NULL || * V_64 > V_51 -> V_73 ) {
V_52 = - V_88 ;
goto free;
}
V_63 = F_34 ( T_3 , V_63 , ( V_51 -> V_73 - * V_64 ) ) ;
if ( F_35 ( V_62 , V_51 -> V_86 . V_89 + * V_64 , V_63 ) ) {
V_52 = - V_90 ;
goto free;
}
V_52 = V_63 ;
* V_64 += V_63 ;
if ( ( unsigned long ) * V_64 < V_51 -> V_73 )
goto V_33;
free:
V_7 = F_7 ( V_2 , V_23 ) ;
if ( V_7 )
F_3 ( & V_7 -> V_12 ) ;
F_5 ( V_51 ) ;
V_23 -> V_77 = V_91 ;
V_23 -> V_56 = NULL ;
V_23 -> V_92 = 0 ;
V_33:
F_8 ( & V_2 -> V_26 -> V_2 , L_12 , V_52 ) ;
F_17 ( & V_2 -> V_34 ) ;
return V_52 ;
}
static T_1 F_36 ( struct V_3 * V_3 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
struct V_22 * V_23 = V_3 -> V_50 ;
struct V_6 * V_93 = NULL ;
struct V_94 V_95 ;
struct V_1 * V_2 ;
unsigned long V_96 = 0 ;
int V_52 ;
int V_65 ;
if ( F_21 ( ! V_23 || ! V_23 -> V_2 ) )
return - V_32 ;
V_2 = V_23 -> V_2 ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_37 != V_38 ) {
F_17 ( & V_2 -> V_34 ) ;
return - V_32 ;
}
if ( V_23 == & V_2 -> V_14 ) {
V_93 = F_37 ( V_2 , V_3 ) ;
if ( V_93 ) {
V_96 = V_93 -> V_97 +
F_38 ( V_98 ) ;
if ( F_39 ( V_99 , V_96 ) ||
V_23 -> V_77 == V_76 ) {
* V_64 = 0 ;
F_3 ( & V_93 -> V_12 ) ;
F_5 ( V_93 ) ;
V_93 = NULL ;
}
}
}
if ( V_23 -> V_77 == V_76 ) {
* V_64 = 0 ;
V_93 = F_7 ( V_2 , V_23 ) ;
if ( V_93 ) {
F_3 ( & V_93 -> V_12 ) ;
F_5 ( V_93 ) ;
V_93 = NULL ;
V_23 -> V_77 = V_91 ;
V_23 -> V_56 = NULL ;
V_23 -> V_92 = 0 ;
}
} else if ( V_23 -> V_77 == V_91 && ! V_23 -> V_92 )
* V_64 = 0 ;
V_93 = F_40 ( sizeof( struct V_6 ) , V_100 ) ;
if ( ! V_93 ) {
F_17 ( & V_2 -> V_34 ) ;
return - V_35 ;
}
V_93 -> V_11 = V_3 ;
V_93 -> V_28 = V_23 ;
V_93 -> V_101 . V_89 = F_41 ( V_63 , V_100 ) ;
V_52 = - V_35 ;
if ( ! V_93 -> V_101 . V_89 )
goto V_102;
F_8 ( & V_2 -> V_26 -> V_2 , L_13 , ( int ) V_63 ) ;
V_52 = - V_90 ;
if ( F_42 ( V_93 -> V_101 . V_89 , V_62 , V_63 ) )
goto V_102;
V_23 -> V_49 = 0 ;
if ( V_63 == 4 &&
( ( memcmp ( V_103 [ 0 ] ,
V_93 -> V_101 . V_89 , 4 ) == 0 ) ||
( memcmp ( V_103 [ 1 ] ,
V_93 -> V_101 . V_89 , 4 ) == 0 ) ||
( memcmp ( V_103 [ 2 ] ,
V_93 -> V_101 . V_89 , 4 ) == 0 ) ) )
V_23 -> V_49 |= V_66 ;
F_43 ( & V_93 -> V_12 ) ;
if ( V_23 == & V_2 -> V_14 ) {
V_93 -> V_86 . V_89 =
F_41 ( V_2 -> V_104 , V_100 ) ;
if ( ! V_93 -> V_86 . V_89 ) {
V_52 = - V_35 ;
goto V_102;
}
if ( V_2 -> V_37 != V_38 ) {
V_52 = - V_32 ;
goto V_102;
}
for ( V_65 = 0 ; V_65 < V_2 -> V_105 ; V_65 ++ ) {
if ( V_2 -> V_70 [ V_65 ] . V_71 ==
V_2 -> V_14 . V_55 )
break;
}
if ( F_21 ( V_2 -> V_70 [ V_65 ] . V_71 != V_23 -> V_55 ) ) {
V_52 = - V_32 ;
goto V_102;
}
if ( V_65 == V_2 -> V_105 ||
( V_2 -> V_70 [ V_65 ] . V_71 !=
V_2 -> V_14 . V_55 ) ) {
V_52 = - V_32 ;
goto V_102;
} else if ( V_63 > V_2 -> V_70 [ V_65 ] . V_106 . V_107 ||
V_63 <= 0 ) {
V_52 = - V_88 ;
goto V_102;
}
V_93 -> V_86 . V_87 = V_2 -> V_104 ;
V_93 -> V_108 = V_109 ;
V_93 -> V_73 = 0 ;
V_93 -> V_101 . V_87 = V_63 ;
if ( V_2 -> V_14 . V_47 != V_53 ) {
V_52 = - V_32 ;
goto V_102;
}
if ( ! F_44 ( & V_2 -> V_15 . V_16 . V_12 ) ||
V_2 -> V_58 != V_59 ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_14 ,
( int ) V_2 -> V_58 ) ;
F_8 ( & V_2 -> V_26 -> V_2 , L_15 ) ;
F_15 ( & V_93 -> V_12 ,
& V_2 -> V_15 . V_16 . V_12 ) ;
V_52 = V_63 ;
} else {
F_8 ( & V_2 -> V_26 -> V_2 , L_16 ) ;
V_52 = F_45 ( V_2 , V_93 ) ;
if ( V_52 ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_17 ,
V_52 ) ;
goto V_102;
}
V_52 = V_63 ;
}
F_17 ( & V_2 -> V_34 ) ;
return V_52 ;
}
V_93 -> V_108 = V_110 ;
V_93 -> V_73 = 0 ;
V_93 -> V_101 . V_87 = V_63 ;
F_8 ( & V_2 -> V_26 -> V_2 , L_18 ,
V_23 -> V_44 , V_23 -> V_55 ) ;
if ( V_23 -> V_47 != V_53 ) {
V_52 = - V_32 ;
F_8 ( & V_2 -> V_26 -> V_2 , L_19 ,
V_23 -> V_44 ,
V_23 -> V_55 ) ;
goto V_102;
}
for ( V_65 = 0 ; V_65 < V_2 -> V_105 ; V_65 ++ ) {
if ( V_2 -> V_70 [ V_65 ] . V_71 ==
V_23 -> V_55 )
break;
}
if ( F_21 ( V_2 -> V_70 [ V_65 ] . V_71 != V_23 -> V_55 ) ) {
V_52 = - V_32 ;
goto V_102;
}
if ( V_65 == V_2 -> V_105 ) {
V_52 = - V_32 ;
goto V_102;
}
if ( V_63 > V_2 -> V_70 [ V_65 ] . V_106 . V_107 || V_63 <= 0 ) {
V_52 = - V_111 ;
goto V_102;
}
V_93 -> V_28 = V_23 ;
V_52 = F_46 ( V_2 , V_23 ) ;
if ( V_52 < 0 )
goto V_102;
if ( V_52 && V_2 -> V_112 ) {
V_52 = 0 ;
V_2 -> V_112 = false ;
if ( V_63 > F_47 ( V_2 ) ) {
V_95 . V_63 = F_47 ( V_2 ) ;
V_95 . V_113 = 0 ;
} else {
V_95 . V_63 = V_63 ;
V_95 . V_113 = 1 ;
}
V_95 . V_114 = V_23 -> V_44 ;
V_95 . V_115 = V_23 -> V_55 ;
V_95 . V_116 = 0 ;
F_8 ( & V_2 -> V_26 -> V_2 , L_20 ,
* ( ( V_117 * ) & V_95 ) ) ;
if ( F_48 ( V_2 , & V_95 ,
( unsigned char * ) ( V_93 -> V_101 . V_89 ) ,
V_95 . V_63 ) ) {
V_52 = - V_32 ;
goto V_102;
}
V_23 -> V_118 = V_119 ;
V_93 -> V_73 = V_95 . V_63 ;
if ( V_95 . V_113 ) {
if ( F_49 ( V_2 , V_23 ) ) {
V_52 = - V_32 ;
goto V_102;
}
F_15 ( & V_93 -> V_12 ,
& V_2 -> V_20 . V_16 . V_12 ) ;
} else {
F_15 ( & V_93 -> V_12 ,
& V_2 -> V_21 . V_16 . V_12 ) ;
}
} else {
V_93 -> V_73 = 0 ;
V_23 -> V_118 = V_119 ;
F_15 ( & V_93 -> V_12 ,
& V_2 -> V_21 . V_16 . V_12 ) ;
}
F_17 ( & V_2 -> V_34 ) ;
return V_63 ;
V_102:
F_17 ( & V_2 -> V_34 ) ;
F_5 ( V_93 ) ;
return V_52 ;
}
static long F_50 ( struct V_3 * V_3 , unsigned int V_120 , unsigned long V_89 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 = V_3 -> V_50 ;
struct V_121 * V_122 = NULL ;
int V_52 ;
if ( V_120 != V_123 )
return - V_111 ;
if ( F_21 ( ! V_23 || ! V_23 -> V_2 ) )
return - V_32 ;
V_2 = V_23 -> V_2 ;
F_8 ( & V_2 -> V_26 -> V_2 , L_21 , V_120 ) ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_37 != V_38 ) {
V_52 = - V_32 ;
goto V_33;
}
F_8 ( & V_2 -> V_26 -> V_2 , L_22 ) ;
V_122 = F_40 ( sizeof( struct V_121 ) ,
V_100 ) ;
if ( ! V_122 ) {
V_52 = - V_35 ;
goto V_33;
}
F_8 ( & V_2 -> V_26 -> V_2 , L_23 ) ;
if ( F_42 ( V_122 , ( char T_2 * ) V_89 ,
sizeof( struct V_121 ) ) ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_24 ) ;
V_52 = - V_90 ;
goto V_33;
}
V_52 = F_51 ( V_3 , V_122 ) ;
if ( V_52 )
goto V_33;
F_8 ( & V_2 -> V_26 -> V_2 , L_25 ) ;
if ( F_35 ( ( char T_2 * ) V_89 , V_122 ,
sizeof( struct V_121 ) ) ) {
F_8 ( & V_2 -> V_26 -> V_2 , L_26 ) ;
V_52 = - V_90 ;
goto V_33;
}
V_33:
F_19 ( V_122 ) ;
F_17 ( & V_2 -> V_34 ) ;
return V_52 ;
}
static long F_52 ( struct V_3 * V_3 ,
unsigned int V_120 , unsigned long V_89 )
{
return F_50 ( V_3 , V_120 , ( unsigned long ) F_53 ( V_89 ) ) ;
}
static unsigned int F_54 ( struct V_3 * V_3 , T_5 * V_124 )
{
struct V_22 * V_23 = V_3 -> V_50 ;
struct V_1 * V_2 ;
unsigned int V_125 = 0 ;
if ( F_21 ( ! V_23 || ! V_23 -> V_2 ) )
return V_125 ;
V_2 = V_23 -> V_2 ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_37 != V_38 )
goto V_33;
if ( V_23 == & V_2 -> V_14 ) {
F_17 ( & V_2 -> V_34 ) ;
F_55 ( V_3 , & V_2 -> V_14 . V_124 , V_124 ) ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_58 == V_61 &&
V_2 -> V_57 == V_3 ) {
V_125 |= ( V_126 | V_127 ) ;
F_8 ( & V_2 -> V_26 -> V_2 , L_27 ) ;
F_26 ( V_2 ) ;
}
goto V_33;
}
F_17 ( & V_2 -> V_34 ) ;
F_55 ( V_3 , & V_23 -> V_128 , V_124 ) ;
F_12 ( & V_2 -> V_34 ) ;
if ( V_129 == V_23 -> V_118 )
V_125 |= ( V_126 | V_127 ) ;
V_33:
F_17 ( & V_2 -> V_34 ) ;
return V_125 ;
}
static bool T_6 F_56 ( struct V_130 * V_26 ,
const struct V_131 * V_132 )
{
V_117 V_133 ;
if ( V_132 -> V_134 == V_135 ) {
F_57 ( V_26 , 0x48 , & V_133 ) ;
if ( ( V_133 & 0x600 ) == 0x200 ) {
F_58 ( & V_26 -> V_2 , L_28 ) ;
return false ;
}
}
return true ;
}
static int T_6 F_59 ( struct V_130 * V_26 ,
const struct V_131 * V_132 )
{
struct V_1 * V_2 ;
int V_31 ;
F_12 ( & V_136 ) ;
if ( ! F_56 ( V_26 , V_132 ) ) {
V_31 = - V_32 ;
goto V_137;
}
if ( V_1 ) {
V_31 = - V_138 ;
goto V_137;
}
V_31 = F_60 ( V_26 ) ;
if ( V_31 ) {
F_61 ( & V_26 -> V_2 , L_29 ) ;
goto V_137;
}
F_62 ( V_26 ) ;
V_31 = F_63 ( V_26 , V_139 ) ;
if ( V_31 ) {
F_61 ( & V_26 -> V_2 , L_30 ) ;
goto V_140;
}
V_2 = F_64 ( V_26 ) ;
if ( ! V_2 ) {
V_31 = - V_35 ;
goto V_141;
}
V_2 -> V_142 = F_65 ( V_26 , 0 , 0 ) ;
if ( ! V_2 -> V_142 ) {
F_61 ( & V_26 -> V_2 , L_31 ) ;
V_31 = - V_35 ;
goto V_143;
}
F_66 ( V_26 ) ;
if ( F_67 ( V_26 ) )
V_31 = F_68 ( V_26 -> V_144 ,
NULL ,
V_145 ,
V_146 , V_139 , V_2 ) ;
else
V_31 = F_68 ( V_26 -> V_144 ,
V_147 ,
V_145 ,
V_148 , V_139 , V_2 ) ;
if ( V_31 ) {
F_61 ( & V_26 -> V_2 , L_32 ,
V_26 -> V_144 ) ;
goto V_149;
}
F_69 ( & V_2 -> V_150 , V_151 ) ;
if ( F_70 ( V_2 ) ) {
F_61 ( & V_26 -> V_2 , L_33 ) ;
V_31 = - V_32 ;
goto V_152;
}
V_31 = F_71 ( & V_153 ) ;
if ( V_31 )
goto V_152;
V_1 = V_26 ;
F_72 ( V_26 , V_2 ) ;
F_73 ( & V_2 -> V_150 , V_154 ) ;
F_17 ( & V_136 ) ;
F_74 ( L_34 ) ;
return 0 ;
V_152:
V_2 -> V_155 = F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
F_77 () ;
F_78 ( V_26 -> V_144 , V_2 ) ;
V_149:
F_79 ( V_26 ) ;
F_80 ( V_26 , V_2 -> V_142 ) ;
V_143:
F_19 ( V_2 ) ;
V_141:
F_81 ( V_26 ) ;
V_140:
F_82 ( V_26 ) ;
V_137:
F_17 ( & V_136 ) ;
F_61 ( & V_26 -> V_2 , L_35 ) ;
return V_31 ;
}
static void T_7 F_83 ( struct V_130 * V_26 )
{
struct V_1 * V_2 ;
if ( V_1 != V_26 )
return;
V_2 = F_11 ( V_26 ) ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_34 ) ;
F_84 ( V_2 , false ) ;
V_1 = NULL ;
if ( V_2 -> V_14 . V_47 == V_53 ) {
V_2 -> V_14 . V_47 = V_54 ;
F_22 ( V_2 , & V_2 -> V_14 ) ;
}
if ( V_2 -> V_156 . V_47 == V_53 ) {
V_2 -> V_156 . V_47 = V_54 ;
F_22 ( V_2 , & V_2 -> V_156 ) ;
}
F_85 ( V_2 ) ;
F_8 ( & V_26 -> V_2 , L_36 ) ;
F_25 ( V_2 , V_2 -> V_156 . V_44 ) ;
F_25 ( V_2 , V_2 -> V_14 . V_44 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_105 = 0 ;
F_17 ( & V_2 -> V_34 ) ;
F_77 () ;
F_76 ( V_2 ) ;
F_78 ( V_26 -> V_144 , V_2 ) ;
F_79 ( V_26 ) ;
F_72 ( V_26 , NULL ) ;
if ( V_2 -> V_142 )
F_80 ( V_26 , V_2 -> V_142 ) ;
F_19 ( V_2 ) ;
F_81 ( V_26 ) ;
F_82 ( V_26 ) ;
F_86 ( & V_153 ) ;
}
static int F_87 ( struct V_134 * V_134 )
{
struct V_130 * V_26 = F_88 ( V_134 ) ;
struct V_1 * V_2 = F_11 ( V_26 ) ;
int V_31 ;
if ( ! V_2 )
return - V_32 ;
F_12 ( & V_2 -> V_34 ) ;
V_31 = F_84 ( V_2 , true ) ;
if ( V_2 -> V_37 == V_38 ||
V_2 -> V_37 == V_157 ) {
V_2 -> V_37 = V_158 ;
F_89 ( V_2 , 0 ) ;
}
F_17 ( & V_2 -> V_34 ) ;
F_78 ( V_26 -> V_144 , V_2 ) ;
F_79 ( V_26 ) ;
return V_31 ;
}
static int F_90 ( struct V_134 * V_134 )
{
struct V_130 * V_26 = F_88 ( V_134 ) ;
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_11 ( V_26 ) ;
if ( ! V_2 )
return - V_32 ;
F_66 ( V_26 ) ;
if ( F_67 ( V_26 ) )
V_31 = F_68 ( V_26 -> V_144 ,
NULL ,
V_145 ,
V_146 , V_139 , V_2 ) ;
else
V_31 = F_68 ( V_26 -> V_144 ,
V_147 ,
V_145 ,
V_148 , V_139 , V_2 ) ;
if ( V_31 ) {
F_61 ( & V_26 -> V_2 , L_37 ,
V_26 -> V_144 ) ;
return V_31 ;
}
F_12 ( & V_2 -> V_34 ) ;
V_2 -> V_37 = V_159 ;
F_89 ( V_2 , 1 ) ;
F_17 ( & V_2 -> V_34 ) ;
F_73 ( & V_2 -> V_150 , V_154 ) ;
return V_31 ;
}
