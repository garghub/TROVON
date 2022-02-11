static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 -> V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_6 ( V_6 -> V_9 ) ;
while ( ! F_7 ( & V_6 -> V_10 ) ) {
V_8 = F_8 ( V_6 -> V_10 . V_11 ,
struct V_7 , V_12 ) ;
F_9 ( & V_8 -> V_12 ) ;
F_10 ( V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
}
F_10 ( V_6 ) ;
}
int F_11 ( void )
{
struct V_5 * V_6 ;
while ( ! F_7 ( & V_14 ) ) {
V_6 = F_8 ( V_14 . V_11 ,
struct V_5 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_5 ( V_6 ) ;
}
return 0 ;
}
T_1 struct V_5 * F_12 ( T_2 * V_16 )
{
struct V_5 * V_6 ;
F_13 (fs_devices, &fs_uuids, list) {
if ( memcmp ( V_16 , V_6 -> V_16 , V_17 ) == 0 )
return V_6 ;
}
return NULL ;
}
static void F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 , struct V_20 * V_22 )
{
struct V_20 * V_23 ;
V_23 = V_19 -> V_21 ;
V_19 -> V_21 = V_21 ;
if ( V_19 -> V_22 )
V_22 -> V_24 = V_23 ;
else
V_19 -> V_22 = V_22 ;
}
static T_1 int F_15 ( struct V_7 * V_8 )
{
struct V_20 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_3 ;
struct V_18 * V_19 ;
struct V_20 * V_22 ;
struct V_20 * V_29 ;
int V_30 = 0 ;
unsigned long V_31 ;
unsigned long V_32 = 0 ;
unsigned long V_33 ;
unsigned long V_34 = 0 ;
int V_35 = 0 ;
int V_36 = 0 ;
struct V_37 V_38 ;
F_16 ( & V_38 ) ;
V_27 = F_17 ( V_8 -> V_39 ) ;
V_3 = V_8 -> V_40 -> V_3 ;
V_33 = F_18 ( V_3 ) ;
V_33 = V_33 * 2 / 3 ;
V_41:
F_19 ( & V_8 -> V_42 ) ;
V_43:
V_31 = 0 ;
if ( ! V_35 && V_8 -> V_44 . V_21 ) {
V_19 = & V_8 -> V_44 ;
V_35 = 1 ;
} else {
V_19 = & V_8 -> V_19 ;
V_35 = 0 ;
}
V_25 = V_19 -> V_21 ;
V_22 = V_19 -> V_22 ;
F_6 ( V_25 && ! V_22 ) ;
if ( V_8 -> V_44 . V_21 == NULL &&
V_8 -> V_19 . V_21 == NULL ) {
V_30 = 0 ;
V_8 -> V_45 = 0 ;
} else {
V_30 = 1 ;
V_8 -> V_45 = 1 ;
}
V_19 -> V_21 = NULL ;
V_19 -> V_22 = NULL ;
F_20 ( & V_8 -> V_42 ) ;
while ( V_25 ) {
F_21 () ;
if ( ( V_31 > 32 &&
V_19 != & V_8 -> V_44 &&
V_8 -> V_44 . V_21 ) ||
( V_31 > 64 && V_19 == & V_8 -> V_44 &&
V_8 -> V_19 . V_21 ) ) {
F_19 ( & V_8 -> V_42 ) ;
F_14 ( V_19 , V_25 , V_22 ) ;
goto V_43;
}
V_29 = V_25 ;
V_25 = V_25 -> V_24 ;
V_29 -> V_24 = NULL ;
F_22 ( & V_3 -> V_46 ) ;
if ( F_23 ( & V_3 -> V_46 ) < V_33 &&
F_24 ( & V_3 -> V_47 ) )
F_25 ( & V_3 -> V_47 ) ;
F_26 ( F_23 ( & V_29 -> V_48 ) == 0 ) ;
if ( V_19 == & V_8 -> V_44 ) {
V_36 = 1 ;
} else if ( V_36 ) {
F_27 ( & V_38 ) ;
F_16 ( & V_38 ) ;
V_36 = 0 ;
}
F_28 ( V_29 -> V_49 , V_29 ) ;
V_31 ++ ;
V_32 ++ ;
if ( F_29 () )
F_30 () ;
if ( V_25 && F_31 ( V_27 ) && V_32 > 8 &&
V_3 -> V_6 -> V_50 > 1 ) {
struct V_51 * V_52 ;
V_52 = V_53 -> V_51 ;
if ( V_52 && V_52 -> V_54 > 0 &&
F_32 ( V_55 , V_52 -> V_34 + V_56 / 50UL ) &&
( V_34 == 0 ||
V_52 -> V_34 == V_34 ) ) {
V_34 = V_52 -> V_34 ;
if ( F_29 () )
F_30 () ;
continue;
}
F_19 ( & V_8 -> V_42 ) ;
F_14 ( V_19 , V_25 , V_22 ) ;
V_8 -> V_45 = 1 ;
F_20 ( & V_8 -> V_42 ) ;
F_33 ( & V_8 -> V_57 ) ;
goto V_58;
}
}
F_30 () ;
if ( V_30 )
goto V_41;
F_19 ( & V_8 -> V_42 ) ;
if ( V_8 -> V_19 . V_21 || V_8 -> V_44 . V_21 )
goto V_43;
F_20 ( & V_8 -> V_42 ) ;
V_58:
F_27 ( & V_38 ) ;
return 0 ;
}
static void F_34 ( struct V_59 * V_57 )
{
struct V_7 * V_8 ;
V_8 = F_35 ( V_57 , struct V_7 , V_57 ) ;
F_15 ( V_8 ) ;
}
static T_1 int F_36 ( const char * V_60 ,
struct V_61 * V_62 ,
T_3 V_63 , struct V_5 * * V_64 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_3 V_65 = F_37 ( V_62 ) ;
char * V_13 ;
V_6 = F_12 ( V_62 -> V_16 ) ;
if ( ! V_6 ) {
V_6 = F_38 ( sizeof( * V_6 ) , V_66 ) ;
if ( ! V_6 )
return - V_67 ;
F_39 ( & V_6 -> V_10 ) ;
F_39 ( & V_6 -> V_68 ) ;
F_40 ( & V_6 -> V_15 , & V_14 ) ;
memcpy ( V_6 -> V_16 , V_62 -> V_16 , V_17 ) ;
V_6 -> V_69 = V_63 ;
V_6 -> V_70 = V_65 ;
F_41 ( & V_6 -> V_71 ) ;
V_8 = NULL ;
} else {
V_8 = F_42 ( & V_6 -> V_10 , V_63 ,
V_62 -> V_72 . V_73 ) ;
}
if ( ! V_8 ) {
if ( V_6 -> V_9 )
return - V_74 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_66 ) ;
if ( ! V_8 ) {
return - V_67 ;
}
V_8 -> V_63 = V_63 ;
V_8 -> V_57 . V_75 = F_34 ;
memcpy ( V_8 -> V_73 , V_62 -> V_72 . V_73 ,
V_76 ) ;
F_43 ( & V_8 -> V_42 ) ;
V_8 -> V_13 = F_44 ( V_60 , V_66 ) ;
if ( ! V_8 -> V_13 ) {
F_10 ( V_8 ) ;
return - V_67 ;
}
F_39 ( & V_8 -> V_77 ) ;
F_2 ( & V_6 -> V_71 ) ;
F_45 ( & V_8 -> V_12 , & V_6 -> V_10 ) ;
F_4 ( & V_6 -> V_71 ) ;
V_8 -> V_6 = V_6 ;
V_6 -> V_78 ++ ;
} else if ( ! V_8 -> V_13 || strcmp ( V_8 -> V_13 , V_60 ) ) {
V_13 = F_44 ( V_60 , V_66 ) ;
if ( ! V_13 )
return - V_67 ;
F_10 ( V_8 -> V_13 ) ;
V_8 -> V_13 = V_13 ;
if ( V_8 -> V_79 ) {
V_6 -> V_80 -- ;
V_8 -> V_79 = 0 ;
}
}
if ( V_65 > V_6 -> V_70 ) {
V_6 -> V_69 = V_63 ;
V_6 -> V_70 = V_65 ;
}
* V_64 = V_6 ;
return 0 ;
}
static struct V_5 * F_46 ( struct V_5 * V_81 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_7 * V_82 ;
V_6 = F_38 ( sizeof( * V_6 ) , V_66 ) ;
if ( ! V_6 )
return F_47 ( - V_67 ) ;
F_39 ( & V_6 -> V_10 ) ;
F_39 ( & V_6 -> V_68 ) ;
F_39 ( & V_6 -> V_15 ) ;
F_41 ( & V_6 -> V_71 ) ;
V_6 -> V_69 = V_81 -> V_69 ;
V_6 -> V_70 = V_81 -> V_70 ;
memcpy ( V_6 -> V_16 , V_81 -> V_16 , sizeof( V_6 -> V_16 ) ) ;
F_13 (orig_dev, &orig->devices, dev_list) {
V_8 = F_38 ( sizeof( * V_8 ) , V_66 ) ;
if ( ! V_8 )
goto error;
V_8 -> V_13 = F_44 ( V_82 -> V_13 , V_66 ) ;
if ( ! V_8 -> V_13 ) {
F_10 ( V_8 ) ;
goto error;
}
V_8 -> V_63 = V_82 -> V_63 ;
V_8 -> V_57 . V_75 = F_34 ;
memcpy ( V_8 -> V_73 , V_82 -> V_73 , sizeof( V_8 -> V_73 ) ) ;
F_43 ( & V_8 -> V_42 ) ;
F_39 ( & V_8 -> V_12 ) ;
F_39 ( & V_8 -> V_77 ) ;
F_40 ( & V_8 -> V_12 , & V_6 -> V_10 ) ;
V_8 -> V_6 = V_6 ;
V_6 -> V_78 ++ ;
}
return V_6 ;
error:
F_5 ( V_6 ) ;
return F_47 ( - V_67 ) ;
}
int F_48 ( struct V_5 * V_6 )
{
struct V_7 * V_8 , * V_11 ;
F_2 ( & V_83 ) ;
V_30:
F_49 (device, next, &fs_devices->devices, dev_list) {
if ( V_8 -> V_84 )
continue;
if ( V_8 -> V_39 ) {
F_50 ( V_8 -> V_39 , V_8 -> V_85 ) ;
V_8 -> V_39 = NULL ;
V_6 -> V_50 -- ;
}
if ( V_8 -> V_86 ) {
F_51 ( & V_8 -> V_77 ) ;
V_8 -> V_86 = 0 ;
V_6 -> V_87 -- ;
}
F_51 ( & V_8 -> V_12 ) ;
V_6 -> V_78 -- ;
F_10 ( V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
}
if ( V_6 -> V_88 ) {
V_6 = V_6 -> V_88 ;
goto V_30;
}
F_4 ( & V_83 ) ;
return 0 ;
}
static void F_52 ( struct V_89 * V_57 )
{
struct V_7 * V_8 ;
V_8 = F_35 ( V_57 , struct V_7 , V_90 ) ;
if ( V_8 -> V_39 )
F_50 ( V_8 -> V_39 , V_8 -> V_85 ) ;
F_10 ( V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
}
static void F_53 ( struct V_91 * V_21 )
{
struct V_7 * V_8 ;
V_8 = F_35 ( V_21 , struct V_7 , V_92 ) ;
F_54 ( & V_8 -> V_90 , F_52 ) ;
F_55 ( & V_8 -> V_90 ) ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( -- V_6 -> V_9 > 0 )
return 0 ;
F_2 ( & V_6 -> V_71 ) ;
F_13 (device, &fs_devices->devices, dev_list) {
struct V_7 * V_93 ;
if ( V_8 -> V_39 )
V_6 -> V_50 -- ;
if ( V_8 -> V_86 ) {
F_51 ( & V_8 -> V_77 ) ;
V_6 -> V_87 -- ;
}
if ( V_8 -> V_94 )
V_6 -> V_95 -- ;
V_93 = F_57 ( sizeof( * V_93 ) , V_66 ) ;
F_26 ( ! V_93 ) ;
memcpy ( V_93 , V_8 , sizeof( * V_93 ) ) ;
V_93 -> V_13 = F_44 ( V_8 -> V_13 , V_66 ) ;
F_26 ( V_8 -> V_13 && ! V_93 -> V_13 ) ;
V_93 -> V_39 = NULL ;
V_93 -> V_86 = 0 ;
V_93 -> V_84 = 0 ;
V_93 -> V_94 = 0 ;
F_58 ( & V_8 -> V_12 , & V_93 -> V_12 ) ;
F_59 ( & V_8 -> V_92 , F_53 ) ;
}
F_4 ( & V_6 -> V_71 ) ;
F_6 ( V_6 -> V_50 ) ;
F_6 ( V_6 -> V_87 ) ;
V_6 -> V_9 = 0 ;
V_6 -> V_96 = 0 ;
return 0 ;
}
int F_60 ( struct V_5 * V_6 )
{
struct V_5 * V_97 = NULL ;
int V_98 ;
F_2 ( & V_83 ) ;
V_98 = F_56 ( V_6 ) ;
if ( ! V_6 -> V_9 ) {
V_97 = V_6 -> V_88 ;
V_6 -> V_88 = NULL ;
}
F_4 ( & V_83 ) ;
while ( V_97 ) {
V_6 = V_97 ;
V_97 = V_6 -> V_88 ;
F_56 ( V_6 ) ;
F_5 ( V_6 ) ;
}
return V_98 ;
}
static int F_61 ( struct V_5 * V_6 ,
T_4 V_99 , void * V_100 )
{
struct V_101 * V_102 ;
struct V_103 * V_39 ;
struct V_104 * V_21 = & V_6 -> V_10 ;
struct V_7 * V_8 ;
struct V_103 * V_105 = NULL ;
struct V_106 * V_107 ;
struct V_61 * V_62 ;
T_3 V_69 = 0 ;
T_3 V_108 = 0 ;
T_3 V_63 ;
int V_96 = 1 ;
int V_98 = 0 ;
V_99 |= V_109 ;
F_13 (device, head, dev_list) {
if ( V_8 -> V_39 )
continue;
if ( ! V_8 -> V_13 )
continue;
V_39 = F_62 ( V_8 -> V_13 , V_99 , V_100 ) ;
if ( F_63 ( V_39 ) ) {
F_64 ( V_110 L_1 , V_8 -> V_13 ) ;
goto error;
}
F_65 ( V_39 , 4096 ) ;
V_107 = F_66 ( V_39 ) ;
if ( ! V_107 ) {
V_98 = - V_111 ;
goto V_112;
}
V_62 = (struct V_61 * ) V_107 -> V_113 ;
V_63 = F_67 ( & V_62 -> V_72 ) ;
if ( V_63 != V_8 -> V_63 )
goto V_114;
if ( memcmp ( V_8 -> V_73 , V_62 -> V_72 . V_73 ,
V_76 ) )
goto V_114;
V_8 -> V_115 = F_37 ( V_62 ) ;
if ( ! V_108 || V_8 -> V_115 > V_108 ) {
V_69 = V_63 ;
V_108 = V_8 -> V_115 ;
V_105 = V_39 ;
}
if ( F_68 ( V_62 ) & V_116 ) {
V_8 -> V_86 = 0 ;
} else {
V_8 -> V_86 = ! F_69 ( V_39 ) ;
V_96 = 0 ;
}
V_102 = F_70 ( V_39 ) ;
if ( F_71 ( V_102 ) ) {
V_8 -> V_94 = 1 ;
V_6 -> V_95 ++ ;
}
V_8 -> V_39 = V_39 ;
V_8 -> V_84 = 0 ;
V_8 -> V_85 = V_99 ;
if ( ! F_72 ( F_70 ( V_39 ) ) )
V_6 -> V_117 = 1 ;
V_6 -> V_50 ++ ;
if ( V_8 -> V_86 ) {
V_6 -> V_87 ++ ;
F_40 ( & V_8 -> V_77 ,
& V_6 -> V_68 ) ;
}
F_73 ( V_107 ) ;
continue;
V_114:
F_73 ( V_107 ) ;
V_112:
F_50 ( V_39 , V_99 ) ;
error:
continue;
}
if ( V_6 -> V_50 == 0 ) {
V_98 = - V_118 ;
goto V_119;
}
V_6 -> V_96 = V_96 ;
V_6 -> V_9 = 1 ;
V_6 -> V_105 = V_105 ;
V_6 -> V_69 = V_69 ;
V_6 -> V_70 = V_108 ;
V_6 -> V_120 = 0 ;
V_119:
return V_98 ;
}
int F_74 ( struct V_5 * V_6 ,
T_4 V_99 , void * V_100 )
{
int V_98 ;
F_2 ( & V_83 ) ;
if ( V_6 -> V_9 ) {
V_6 -> V_9 ++ ;
V_98 = 0 ;
} else {
V_98 = F_61 ( V_6 , V_99 , V_100 ) ;
}
F_4 ( & V_83 ) ;
return V_98 ;
}
int F_75 ( const char * V_60 , T_4 V_99 , void * V_100 ,
struct V_5 * * V_64 )
{
struct V_61 * V_62 ;
struct V_103 * V_39 ;
struct V_106 * V_107 ;
int V_98 ;
T_3 V_63 ;
T_3 V_121 ;
F_2 ( & V_83 ) ;
V_99 |= V_109 ;
V_39 = F_62 ( V_60 , V_99 , V_100 ) ;
if ( F_63 ( V_39 ) ) {
V_98 = F_76 ( V_39 ) ;
goto error;
}
V_98 = F_65 ( V_39 , 4096 ) ;
if ( V_98 )
goto V_112;
V_107 = F_66 ( V_39 ) ;
if ( ! V_107 ) {
V_98 = - V_111 ;
goto V_112;
}
V_62 = (struct V_61 * ) V_107 -> V_113 ;
V_63 = F_67 ( & V_62 -> V_72 ) ;
V_121 = F_37 ( V_62 ) ;
if ( V_62 -> V_122 [ 0 ] )
F_64 ( V_110 L_2 , V_62 -> V_122 ) ;
else
F_64 ( V_110 L_3 , V_62 -> V_16 ) ;
F_64 ( V_123 L_4 ,
( unsigned long long ) V_63 , ( unsigned long long ) V_121 , V_60 ) ;
V_98 = F_36 ( V_60 , V_62 , V_63 , V_64 ) ;
F_73 ( V_107 ) ;
V_112:
F_50 ( V_39 , V_99 ) ;
error:
F_4 ( & V_83 ) ;
return V_98 ;
}
int F_77 ( struct V_7 * V_8 , T_3 V_124 ,
T_3 V_125 , T_3 * V_126 )
{
struct V_127 V_128 ;
struct V_1 * V_2 = V_8 -> V_40 ;
struct V_129 * V_130 ;
struct V_131 * V_60 ;
T_3 V_132 ;
int V_98 ;
int V_133 ;
struct V_134 * V_135 ;
* V_126 = 0 ;
if ( V_124 >= V_8 -> V_136 )
return 0 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_60 -> V_137 = 2 ;
V_128 . V_138 = V_8 -> V_63 ;
V_128 . V_139 = V_124 ;
V_128 . type = V_140 ;
V_98 = F_79 ( NULL , V_2 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto V_119;
if ( V_98 > 0 ) {
V_98 = F_80 ( V_2 , V_60 , V_128 . V_138 , V_128 . type ) ;
if ( V_98 < 0 )
goto V_119;
}
while ( 1 ) {
V_135 = V_60 -> V_141 [ 0 ] ;
V_133 = V_60 -> V_142 [ 0 ] ;
if ( V_133 >= F_81 ( V_135 ) ) {
V_98 = F_82 ( V_2 , V_60 ) ;
if ( V_98 == 0 )
continue;
if ( V_98 < 0 )
goto V_119;
break;
}
F_83 ( V_135 , & V_128 , V_133 ) ;
if ( V_128 . V_138 < V_8 -> V_63 )
goto V_11;
if ( V_128 . V_138 > V_8 -> V_63 )
break;
if ( F_84 ( & V_128 ) != V_140 )
goto V_11;
V_130 = F_85 ( V_135 , V_133 , struct V_129 ) ;
V_132 = V_128 . V_139 + F_86 ( V_135 ,
V_130 ) ;
if ( V_128 . V_139 <= V_124 && V_132 > V_125 ) {
* V_126 = V_125 - V_124 + 1 ;
break;
} else if ( V_128 . V_139 <= V_124 && V_132 > V_124 )
* V_126 += V_132 - V_124 ;
else if ( V_128 . V_139 > V_124 && V_132 <= V_125 )
* V_126 += V_132 - V_128 . V_139 ;
else if ( V_128 . V_139 > V_124 && V_128 . V_139 <= V_125 ) {
* V_126 += V_125 - V_128 . V_139 + 1 ;
break;
} else if ( V_128 . V_139 > V_125 )
break;
V_11:
V_60 -> V_142 [ 0 ] ++ ;
}
V_98 = 0 ;
V_119:
F_87 ( V_60 ) ;
return V_98 ;
}
int F_88 ( struct V_143 * V_144 ,
struct V_7 * V_8 , T_3 V_145 ,
T_3 * V_124 , T_3 * V_146 )
{
struct V_127 V_128 ;
struct V_1 * V_2 = V_8 -> V_40 ;
struct V_129 * V_130 ;
struct V_131 * V_60 ;
T_3 V_147 ;
T_3 V_148 ;
T_3 V_149 ;
T_3 V_132 ;
T_3 V_150 ;
T_3 V_151 = V_8 -> V_136 ;
int V_98 ;
int V_133 ;
struct V_134 * V_135 ;
V_150 = F_89 ( V_2 -> V_3 -> V_152 , 1024ull * 1024 ) ;
V_148 = V_150 ;
V_149 = 0 ;
V_147 = 0 ;
if ( V_150 >= V_151 ) {
V_98 = - V_153 ;
goto error;
}
V_60 = F_78 () ;
if ( ! V_60 ) {
V_98 = - V_67 ;
goto error;
}
V_60 -> V_137 = 2 ;
V_128 . V_138 = V_8 -> V_63 ;
V_128 . V_139 = V_150 ;
V_128 . type = V_140 ;
V_98 = F_79 ( V_144 , V_2 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto V_119;
if ( V_98 > 0 ) {
V_98 = F_80 ( V_2 , V_60 , V_128 . V_138 , V_128 . type ) ;
if ( V_98 < 0 )
goto V_119;
}
while ( 1 ) {
V_135 = V_60 -> V_141 [ 0 ] ;
V_133 = V_60 -> V_142 [ 0 ] ;
if ( V_133 >= F_81 ( V_135 ) ) {
V_98 = F_82 ( V_2 , V_60 ) ;
if ( V_98 == 0 )
continue;
if ( V_98 < 0 )
goto V_119;
break;
}
F_83 ( V_135 , & V_128 , V_133 ) ;
if ( V_128 . V_138 < V_8 -> V_63 )
goto V_11;
if ( V_128 . V_138 > V_8 -> V_63 )
break;
if ( F_84 ( & V_128 ) != V_140 )
goto V_11;
if ( V_128 . V_139 > V_150 ) {
V_147 = V_128 . V_139 - V_150 ;
if ( V_147 > V_149 ) {
V_148 = V_150 ;
V_149 = V_147 ;
}
if ( V_147 >= V_145 ) {
V_98 = 0 ;
goto V_119;
}
}
V_130 = F_85 ( V_135 , V_133 , struct V_129 ) ;
V_132 = V_128 . V_139 + F_86 ( V_135 ,
V_130 ) ;
if ( V_132 > V_150 )
V_150 = V_132 ;
V_11:
V_60 -> V_142 [ 0 ] ++ ;
F_30 () ;
}
if ( V_151 > V_150 )
V_147 = V_151 - V_150 ;
if ( V_147 > V_149 ) {
V_148 = V_150 ;
V_149 = V_147 ;
}
if ( V_147 < V_145 )
V_98 = - V_153 ;
else
V_98 = 0 ;
V_119:
F_87 ( V_60 ) ;
error:
* V_124 = V_148 ;
if ( V_146 )
* V_146 = V_149 ;
return V_98 ;
}
static int F_90 ( struct V_143 * V_144 ,
struct V_7 * V_8 ,
T_3 V_124 )
{
int V_98 ;
struct V_131 * V_60 ;
struct V_1 * V_2 = V_8 -> V_40 ;
struct V_127 V_128 ;
struct V_127 V_154 ;
struct V_134 * V_155 = NULL ;
struct V_129 * V_156 = NULL ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_8 -> V_63 ;
V_128 . V_139 = V_124 ;
V_128 . type = V_140 ;
V_98 = F_79 ( V_144 , V_2 , & V_128 , V_60 , - 1 , 1 ) ;
if ( V_98 > 0 ) {
V_98 = F_80 ( V_2 , V_60 , V_128 . V_138 ,
V_140 ) ;
if ( V_98 )
goto V_119;
V_155 = V_60 -> V_141 [ 0 ] ;
F_83 ( V_155 , & V_154 , V_60 -> V_142 [ 0 ] ) ;
V_156 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] ,
struct V_129 ) ;
F_26 ( V_154 . V_139 > V_124 || V_154 . V_139 +
F_86 ( V_155 , V_156 ) < V_124 ) ;
} else if ( V_98 == 0 ) {
V_155 = V_60 -> V_141 [ 0 ] ;
V_156 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] ,
struct V_129 ) ;
}
F_26 ( V_98 ) ;
if ( V_8 -> V_157 > 0 )
V_8 -> V_157 -= F_86 ( V_155 , V_156 ) ;
V_98 = F_91 ( V_144 , V_2 , V_60 ) ;
V_119:
F_87 ( V_60 ) ;
return V_98 ;
}
int F_92 ( struct V_143 * V_144 ,
struct V_7 * V_8 ,
T_3 V_158 , T_3 V_159 ,
T_3 V_160 , T_3 V_124 , T_3 V_145 )
{
int V_98 ;
struct V_131 * V_60 ;
struct V_1 * V_2 = V_8 -> V_40 ;
struct V_129 * V_156 ;
struct V_134 * V_155 ;
struct V_127 V_128 ;
F_6 ( ! V_8 -> V_84 ) ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_8 -> V_63 ;
V_128 . V_139 = V_124 ;
V_128 . type = V_140 ;
V_98 = F_93 ( V_144 , V_2 , V_60 , & V_128 ,
sizeof( * V_156 ) ) ;
F_26 ( V_98 ) ;
V_155 = V_60 -> V_141 [ 0 ] ;
V_156 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] ,
struct V_129 ) ;
F_94 ( V_155 , V_156 , V_158 ) ;
F_95 ( V_155 , V_156 , V_159 ) ;
F_96 ( V_155 , V_156 , V_160 ) ;
F_97 ( V_155 , V_2 -> V_3 -> V_161 ,
( unsigned long ) F_98 ( V_156 ) ,
V_76 ) ;
F_99 ( V_155 , V_156 , V_145 ) ;
F_100 ( V_155 ) ;
F_87 ( V_60 ) ;
return V_98 ;
}
static T_1 int F_101 ( struct V_1 * V_2 ,
T_3 V_138 , T_3 * V_139 )
{
struct V_131 * V_60 ;
int V_98 ;
struct V_127 V_128 ;
struct V_162 * V_163 ;
struct V_127 V_154 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_138 ;
V_128 . V_139 = ( T_3 ) - 1 ;
V_128 . type = V_164 ;
V_98 = F_79 ( NULL , V_2 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto error;
F_26 ( V_98 == 0 ) ;
V_98 = F_80 ( V_2 , V_60 , 0 , V_164 ) ;
if ( V_98 ) {
* V_139 = 0 ;
} else {
F_83 ( V_60 -> V_141 [ 0 ] , & V_154 ,
V_60 -> V_142 [ 0 ] ) ;
if ( V_154 . V_138 != V_138 )
* V_139 = 0 ;
else {
V_163 = F_85 ( V_60 -> V_141 [ 0 ] , V_60 -> V_142 [ 0 ] ,
struct V_162 ) ;
* V_139 = V_154 . V_139 +
F_102 ( V_60 -> V_141 [ 0 ] , V_163 ) ;
}
}
V_98 = 0 ;
error:
F_87 ( V_60 ) ;
return V_98 ;
}
static T_1 int F_103 ( struct V_1 * V_2 , T_3 * V_138 )
{
int V_98 ;
struct V_127 V_128 ;
struct V_127 V_154 ;
struct V_131 * V_60 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_166 ;
V_128 . type = V_167 ;
V_128 . V_139 = ( T_3 ) - 1 ;
V_98 = F_79 ( NULL , V_2 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto error;
F_26 ( V_98 == 0 ) ;
V_98 = F_80 ( V_2 , V_60 , V_166 ,
V_167 ) ;
if ( V_98 ) {
* V_138 = 1 ;
} else {
F_83 ( V_60 -> V_141 [ 0 ] , & V_154 ,
V_60 -> V_142 [ 0 ] ) ;
* V_138 = V_154 . V_139 + 1 ;
}
V_98 = 0 ;
error:
F_87 ( V_60 ) ;
return V_98 ;
}
int F_104 ( struct V_143 * V_144 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_98 ;
struct V_131 * V_60 ;
struct V_168 * V_72 ;
struct V_134 * V_155 ;
struct V_127 V_128 ;
unsigned long V_169 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_166 ;
V_128 . type = V_167 ;
V_128 . V_139 = V_8 -> V_63 ;
V_98 = F_93 ( V_144 , V_2 , V_60 , & V_128 ,
sizeof( * V_72 ) ) ;
if ( V_98 )
goto V_119;
V_155 = V_60 -> V_141 [ 0 ] ;
V_72 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] , struct V_168 ) ;
F_105 ( V_155 , V_72 , V_8 -> V_63 ) ;
F_106 ( V_155 , V_72 , 0 ) ;
F_107 ( V_155 , V_72 , V_8 -> type ) ;
F_108 ( V_155 , V_72 , V_8 -> V_170 ) ;
F_109 ( V_155 , V_72 , V_8 -> V_171 ) ;
F_110 ( V_155 , V_72 , V_8 -> V_172 ) ;
F_111 ( V_155 , V_72 , V_8 -> V_136 ) ;
F_112 ( V_155 , V_72 , V_8 -> V_157 ) ;
F_113 ( V_155 , V_72 , 0 ) ;
F_114 ( V_155 , V_72 , 0 ) ;
F_115 ( V_155 , V_72 , 0 ) ;
F_116 ( V_155 , V_72 , 0 ) ;
V_169 = ( unsigned long ) F_117 ( V_72 ) ;
F_97 ( V_155 , V_8 -> V_73 , V_169 , V_76 ) ;
V_169 = ( unsigned long ) F_118 ( V_72 ) ;
F_97 ( V_155 , V_2 -> V_3 -> V_16 , V_169 , V_76 ) ;
F_100 ( V_155 ) ;
V_98 = 0 ;
V_119:
F_87 ( V_60 ) ;
return V_98 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_98 ;
struct V_131 * V_60 ;
struct V_127 V_128 ;
struct V_143 * V_144 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_144 = F_120 ( V_2 , 0 ) ;
if ( F_63 ( V_144 ) ) {
F_87 ( V_60 ) ;
return F_76 ( V_144 ) ;
}
V_128 . V_138 = V_166 ;
V_128 . type = V_167 ;
V_128 . V_139 = V_8 -> V_63 ;
F_1 ( V_2 ) ;
V_98 = F_79 ( V_144 , V_2 , & V_128 , V_60 , - 1 , 1 ) ;
if ( V_98 < 0 )
goto V_119;
if ( V_98 > 0 ) {
V_98 = - V_173 ;
goto V_119;
}
V_98 = F_91 ( V_144 , V_2 , V_60 ) ;
if ( V_98 )
goto V_119;
V_119:
F_87 ( V_60 ) ;
F_3 ( V_2 ) ;
F_121 ( V_144 , V_2 ) ;
return V_98 ;
}
int F_122 ( struct V_1 * V_2 , char * V_174 )
{
struct V_7 * V_8 ;
struct V_7 * V_175 ;
struct V_103 * V_39 ;
struct V_106 * V_107 = NULL ;
struct V_61 * V_62 ;
struct V_5 * V_176 ;
T_3 V_177 ;
T_3 V_63 ;
T_3 V_78 ;
T_2 * V_178 ;
int V_98 = 0 ;
bool V_179 = false ;
F_2 ( & V_83 ) ;
F_2 ( & V_2 -> V_3 -> V_180 ) ;
V_177 = V_2 -> V_3 -> V_181 |
V_2 -> V_3 -> V_182 |
V_2 -> V_3 -> V_183 ;
if ( ( V_177 & V_184 ) &&
V_2 -> V_3 -> V_6 -> V_78 <= 4 ) {
F_64 ( V_185 L_5
L_6 ) ;
V_98 = - V_111 ;
goto V_119;
}
if ( ( V_177 & V_186 ) &&
V_2 -> V_3 -> V_6 -> V_78 <= 2 ) {
F_64 ( V_185 L_7
L_8 ) ;
V_98 = - V_111 ;
goto V_119;
}
if ( strcmp ( V_174 , L_9 ) == 0 ) {
struct V_104 * V_10 ;
struct V_7 * V_187 ;
V_8 = NULL ;
V_10 = & V_2 -> V_3 -> V_6 -> V_10 ;
F_13 (tmp, devices, dev_list) {
if ( V_187 -> V_84 && ! V_187 -> V_39 ) {
V_8 = V_187 ;
break;
}
}
V_39 = NULL ;
V_107 = NULL ;
V_62 = NULL ;
if ( ! V_8 ) {
F_64 ( V_185 L_10
L_11 ) ;
goto V_119;
}
} else {
V_39 = F_62 ( V_174 , V_188 | V_109 ,
V_2 -> V_3 -> V_189 ) ;
if ( F_63 ( V_39 ) ) {
V_98 = F_76 ( V_39 ) ;
goto V_119;
}
F_65 ( V_39 , 4096 ) ;
V_107 = F_66 ( V_39 ) ;
if ( ! V_107 ) {
V_98 = - V_111 ;
goto V_112;
}
V_62 = (struct V_61 * ) V_107 -> V_113 ;
V_63 = F_67 ( & V_62 -> V_72 ) ;
V_178 = V_62 -> V_72 . V_73 ;
V_8 = F_123 ( V_2 , V_63 , V_178 ,
V_62 -> V_16 ) ;
if ( ! V_8 ) {
V_98 = - V_173 ;
goto V_114;
}
}
if ( V_8 -> V_86 && V_2 -> V_3 -> V_6 -> V_87 == 1 ) {
F_64 ( V_185 L_12
L_13 ) ;
V_98 = - V_111 ;
goto V_114;
}
if ( V_8 -> V_86 ) {
F_1 ( V_2 ) ;
F_51 ( & V_8 -> V_77 ) ;
F_3 ( V_2 ) ;
V_2 -> V_3 -> V_6 -> V_87 -- ;
V_179 = true ;
}
V_98 = F_124 ( V_8 , 0 ) ;
if ( V_98 )
goto V_190;
V_98 = F_119 ( V_2 -> V_3 -> V_165 , V_8 ) ;
if ( V_98 )
goto V_190;
V_8 -> V_84 = 0 ;
F_125 ( V_2 , V_8 ) ;
V_176 = V_8 -> V_6 ;
F_2 ( & V_2 -> V_3 -> V_6 -> V_71 ) ;
F_126 ( & V_8 -> V_12 ) ;
V_8 -> V_6 -> V_78 -- ;
if ( V_8 -> V_79 )
V_2 -> V_3 -> V_6 -> V_80 -- ;
V_175 = F_8 ( V_2 -> V_3 -> V_6 -> V_10 . V_11 ,
struct V_7 , V_12 ) ;
if ( V_8 -> V_39 == V_2 -> V_3 -> V_191 -> V_192 )
V_2 -> V_3 -> V_191 -> V_192 = V_175 -> V_39 ;
if ( V_8 -> V_39 == V_2 -> V_3 -> V_6 -> V_105 )
V_2 -> V_3 -> V_6 -> V_105 = V_175 -> V_39 ;
if ( V_8 -> V_39 )
V_8 -> V_6 -> V_50 -- ;
F_59 ( & V_8 -> V_92 , F_53 ) ;
F_4 ( & V_2 -> V_3 -> V_6 -> V_71 ) ;
V_78 = F_127 ( & V_2 -> V_3 -> V_193 ) - 1 ;
F_128 ( & V_2 -> V_3 -> V_193 , V_78 ) ;
if ( V_176 -> V_50 == 0 ) {
struct V_5 * V_6 ;
V_6 = V_2 -> V_3 -> V_6 ;
while ( V_6 ) {
if ( V_6 -> V_88 == V_176 )
break;
V_6 = V_6 -> V_88 ;
}
V_6 -> V_88 = V_176 -> V_88 ;
V_176 -> V_88 = NULL ;
F_1 ( V_2 ) ;
F_56 ( V_176 ) ;
F_3 ( V_2 ) ;
F_5 ( V_176 ) ;
}
if ( V_179 ) {
memset ( & V_62 -> V_194 , 0 , sizeof( V_62 -> V_194 ) ) ;
F_129 ( V_107 ) ;
F_130 ( V_107 ) ;
}
V_98 = 0 ;
V_114:
F_73 ( V_107 ) ;
V_112:
if ( V_39 )
F_50 ( V_39 , V_188 | V_109 ) ;
V_119:
F_4 ( & V_2 -> V_3 -> V_180 ) ;
F_4 ( & V_83 ) ;
return V_98 ;
V_190:
if ( V_8 -> V_86 ) {
F_1 ( V_2 ) ;
F_40 ( & V_8 -> V_77 ,
& V_2 -> V_3 -> V_6 -> V_68 ) ;
F_3 ( V_2 ) ;
V_2 -> V_3 -> V_6 -> V_87 ++ ;
}
goto V_114;
}
static int F_131 ( struct V_143 * V_144 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_3 -> V_6 ;
struct V_5 * V_195 ;
struct V_5 * V_97 ;
struct V_61 * V_62 = & V_2 -> V_3 -> V_193 ;
struct V_7 * V_8 ;
T_3 V_196 ;
F_26 ( ! F_132 ( & V_83 ) ) ;
if ( ! V_6 -> V_96 )
return - V_111 ;
V_97 = F_38 ( sizeof( * V_6 ) , V_66 ) ;
if ( ! V_97 )
return - V_67 ;
V_195 = F_46 ( V_6 ) ;
if ( F_63 ( V_195 ) ) {
F_10 ( V_97 ) ;
return F_76 ( V_195 ) ;
}
F_40 ( & V_195 -> V_15 , & V_14 ) ;
memcpy ( V_97 , V_6 , sizeof( * V_97 ) ) ;
V_97 -> V_9 = 1 ;
F_39 ( & V_97 -> V_10 ) ;
F_39 ( & V_97 -> V_68 ) ;
F_41 ( & V_97 -> V_71 ) ;
F_2 ( & V_2 -> V_3 -> V_6 -> V_71 ) ;
F_133 ( & V_6 -> V_10 , & V_97 -> V_10 ,
V_197 ) ;
F_4 ( & V_2 -> V_3 -> V_6 -> V_71 ) ;
F_134 ( & V_6 -> V_68 , & V_97 -> V_68 ) ;
F_13 (device, &seed_devices->devices, dev_list) {
V_8 -> V_6 = V_97 ;
}
V_6 -> V_96 = 0 ;
V_6 -> V_78 = 0 ;
V_6 -> V_50 = 0 ;
V_6 -> V_88 = V_97 ;
F_135 ( V_6 -> V_16 ) ;
memcpy ( V_2 -> V_3 -> V_16 , V_6 -> V_16 , V_17 ) ;
memcpy ( V_62 -> V_16 , V_6 -> V_16 , V_17 ) ;
V_196 = F_68 ( V_62 ) &
~ V_116 ;
F_136 ( V_62 , V_196 ) ;
return 0 ;
}
static int F_137 ( struct V_143 * V_144 ,
struct V_1 * V_2 )
{
struct V_131 * V_60 ;
struct V_134 * V_155 ;
struct V_168 * V_72 ;
struct V_7 * V_8 ;
struct V_127 V_128 ;
T_2 V_198 [ V_76 ] ;
T_2 V_178 [ V_76 ] ;
T_3 V_63 ;
int V_98 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_128 . V_138 = V_166 ;
V_128 . V_139 = 0 ;
V_128 . type = V_167 ;
while ( 1 ) {
V_98 = F_79 ( V_144 , V_2 , & V_128 , V_60 , 0 , 1 ) ;
if ( V_98 < 0 )
goto error;
V_155 = V_60 -> V_141 [ 0 ] ;
V_199:
if ( V_60 -> V_142 [ 0 ] >= F_81 ( V_155 ) ) {
V_98 = F_82 ( V_2 , V_60 ) ;
if ( V_98 > 0 )
break;
if ( V_98 < 0 )
goto error;
V_155 = V_60 -> V_141 [ 0 ] ;
F_83 ( V_155 , & V_128 , V_60 -> V_142 [ 0 ] ) ;
F_138 ( V_60 ) ;
continue;
}
F_83 ( V_155 , & V_128 , V_60 -> V_142 [ 0 ] ) ;
if ( V_128 . V_138 != V_166 ||
V_128 . type != V_167 )
break;
V_72 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] ,
struct V_168 ) ;
V_63 = F_139 ( V_155 , V_72 ) ;
F_140 ( V_155 , V_178 ,
( unsigned long ) F_117 ( V_72 ) ,
V_76 ) ;
F_140 ( V_155 , V_198 ,
( unsigned long ) F_118 ( V_72 ) ,
V_76 ) ;
V_8 = F_123 ( V_2 , V_63 , V_178 , V_198 ) ;
F_26 ( ! V_8 ) ;
if ( V_8 -> V_6 -> V_96 ) {
F_106 ( V_155 , V_72 ,
V_8 -> V_115 ) ;
F_100 ( V_155 ) ;
}
V_60 -> V_142 [ 0 ] ++ ;
goto V_199;
}
V_98 = 0 ;
error:
F_87 ( V_60 ) ;
return V_98 ;
}
int F_141 ( struct V_1 * V_2 , char * V_174 )
{
struct V_101 * V_102 ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
struct V_103 * V_39 ;
struct V_104 * V_10 ;
struct V_200 * V_191 = V_2 -> V_3 -> V_191 ;
T_3 V_136 ;
int V_201 = 0 ;
int V_98 = 0 ;
if ( ( V_191 -> V_202 & V_203 ) && ! V_2 -> V_3 -> V_6 -> V_96 )
return - V_111 ;
V_39 = F_62 ( V_174 , V_109 ,
V_2 -> V_3 -> V_189 ) ;
if ( F_63 ( V_39 ) )
return F_76 ( V_39 ) ;
if ( V_2 -> V_3 -> V_6 -> V_96 ) {
V_201 = 1 ;
F_142 ( & V_191 -> V_204 ) ;
F_2 ( & V_83 ) ;
}
F_143 ( V_39 -> V_205 -> V_206 ) ;
F_2 ( & V_2 -> V_3 -> V_180 ) ;
V_10 = & V_2 -> V_3 -> V_6 -> V_10 ;
F_13 (device, devices, dev_list) {
if ( V_8 -> V_39 == V_39 ) {
V_98 = - V_207 ;
goto error;
}
}
V_8 = F_38 ( sizeof( * V_8 ) , V_66 ) ;
if ( ! V_8 ) {
V_98 = - V_67 ;
goto error;
}
V_8 -> V_13 = F_44 ( V_174 , V_66 ) ;
if ( ! V_8 -> V_13 ) {
F_10 ( V_8 ) ;
V_98 = - V_67 ;
goto error;
}
V_98 = F_103 ( V_2 , & V_8 -> V_63 ) ;
if ( V_98 ) {
F_10 ( V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
goto error;
}
V_144 = F_120 ( V_2 , 0 ) ;
if ( F_63 ( V_144 ) ) {
F_10 ( V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
V_98 = F_76 ( V_144 ) ;
goto error;
}
F_1 ( V_2 ) ;
V_102 = F_70 ( V_39 ) ;
if ( F_71 ( V_102 ) )
V_8 -> V_94 = 1 ;
V_8 -> V_86 = 1 ;
V_8 -> V_57 . V_75 = F_34 ;
F_135 ( V_8 -> V_73 ) ;
F_43 ( & V_8 -> V_42 ) ;
V_8 -> V_115 = V_144 -> V_121 ;
V_8 -> V_171 = V_2 -> V_208 ;
V_8 -> V_170 = V_2 -> V_208 ;
V_8 -> V_172 = V_2 -> V_208 ;
V_8 -> V_136 = F_144 ( V_39 -> V_205 ) ;
V_8 -> V_209 = V_8 -> V_136 ;
V_8 -> V_40 = V_2 -> V_3 -> V_40 ;
V_8 -> V_39 = V_39 ;
V_8 -> V_84 = 1 ;
V_8 -> V_85 = V_109 ;
F_65 ( V_8 -> V_39 , 4096 ) ;
if ( V_201 ) {
V_191 -> V_202 &= ~ V_203 ;
V_98 = F_131 ( V_144 , V_2 ) ;
F_26 ( V_98 ) ;
}
V_8 -> V_6 = V_2 -> V_3 -> V_6 ;
F_2 ( & V_2 -> V_3 -> V_6 -> V_71 ) ;
F_45 ( & V_8 -> V_12 , & V_2 -> V_3 -> V_6 -> V_10 ) ;
F_40 ( & V_8 -> V_77 ,
& V_2 -> V_3 -> V_6 -> V_68 ) ;
V_2 -> V_3 -> V_6 -> V_78 ++ ;
V_2 -> V_3 -> V_6 -> V_50 ++ ;
V_2 -> V_3 -> V_6 -> V_87 ++ ;
if ( V_8 -> V_94 )
V_2 -> V_3 -> V_6 -> V_95 ++ ;
V_2 -> V_3 -> V_6 -> V_120 += V_8 -> V_136 ;
if ( ! F_72 ( F_70 ( V_39 ) ) )
V_2 -> V_3 -> V_6 -> V_117 = 1 ;
V_136 = F_145 ( & V_2 -> V_3 -> V_193 ) ;
F_146 ( & V_2 -> V_3 -> V_193 ,
V_136 + V_8 -> V_136 ) ;
V_136 = F_127 ( & V_2 -> V_3 -> V_193 ) ;
F_128 ( & V_2 -> V_3 -> V_193 ,
V_136 + 1 ) ;
F_4 ( & V_2 -> V_3 -> V_6 -> V_71 ) ;
if ( V_201 ) {
V_98 = F_147 ( V_144 , V_2 , V_8 ) ;
F_26 ( V_98 ) ;
V_98 = F_137 ( V_144 , V_2 ) ;
F_26 ( V_98 ) ;
} else {
V_98 = F_104 ( V_144 , V_2 , V_8 ) ;
}
F_148 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_121 ( V_144 , V_2 ) ;
if ( V_201 ) {
F_4 ( & V_83 ) ;
F_149 ( & V_191 -> V_204 ) ;
V_98 = F_150 ( V_2 ) ;
F_26 ( V_98 ) ;
}
V_119:
F_4 ( & V_2 -> V_3 -> V_180 ) ;
return V_98 ;
error:
F_50 ( V_39 , V_109 ) ;
if ( V_201 ) {
F_4 ( & V_83 ) ;
F_149 ( & V_191 -> V_204 ) ;
}
goto V_119;
}
static T_1 int F_151 ( struct V_143 * V_144 ,
struct V_7 * V_8 )
{
int V_98 ;
struct V_131 * V_60 ;
struct V_1 * V_2 ;
struct V_168 * V_72 ;
struct V_134 * V_155 ;
struct V_127 V_128 ;
V_2 = V_8 -> V_40 -> V_3 -> V_165 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_166 ;
V_128 . type = V_167 ;
V_128 . V_139 = V_8 -> V_63 ;
V_98 = F_79 ( V_144 , V_2 , & V_128 , V_60 , 0 , 1 ) ;
if ( V_98 < 0 )
goto V_119;
if ( V_98 > 0 ) {
V_98 = - V_173 ;
goto V_119;
}
V_155 = V_60 -> V_141 [ 0 ] ;
V_72 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] , struct V_168 ) ;
F_105 ( V_155 , V_72 , V_8 -> V_63 ) ;
F_107 ( V_155 , V_72 , V_8 -> type ) ;
F_108 ( V_155 , V_72 , V_8 -> V_170 ) ;
F_109 ( V_155 , V_72 , V_8 -> V_171 ) ;
F_110 ( V_155 , V_72 , V_8 -> V_172 ) ;
F_111 ( V_155 , V_72 , V_8 -> V_209 ) ;
F_112 ( V_155 , V_72 , V_8 -> V_157 ) ;
F_100 ( V_155 ) ;
V_119:
F_87 ( V_60 ) ;
return V_98 ;
}
static int F_152 ( struct V_143 * V_144 ,
struct V_7 * V_8 , T_3 V_210 )
{
struct V_61 * V_193 =
& V_8 -> V_40 -> V_3 -> V_193 ;
T_3 V_211 = F_145 ( V_193 ) ;
T_3 V_212 = V_210 - V_8 -> V_136 ;
if ( ! V_8 -> V_86 )
return - V_213 ;
if ( V_210 <= V_8 -> V_136 )
return - V_111 ;
F_146 ( V_193 , V_211 + V_212 ) ;
V_8 -> V_6 -> V_120 += V_212 ;
V_8 -> V_136 = V_210 ;
V_8 -> V_209 = V_210 ;
F_148 ( V_8 -> V_40 -> V_3 ) ;
return F_151 ( V_144 , V_8 ) ;
}
int F_153 ( struct V_143 * V_144 ,
struct V_7 * V_8 , T_3 V_210 )
{
int V_98 ;
F_1 ( V_8 -> V_40 ) ;
V_98 = F_152 ( V_144 , V_8 , V_210 ) ;
F_3 ( V_8 -> V_40 ) ;
return V_98 ;
}
static int F_154 ( struct V_143 * V_144 ,
struct V_1 * V_2 ,
T_3 V_158 , T_3 V_159 ,
T_3 V_160 )
{
int V_98 ;
struct V_131 * V_60 ;
struct V_127 V_128 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_159 ;
V_128 . V_139 = V_160 ;
V_128 . type = V_164 ;
V_98 = F_79 ( V_144 , V_2 , & V_128 , V_60 , - 1 , 1 ) ;
F_26 ( V_98 ) ;
V_98 = F_91 ( V_144 , V_2 , V_60 ) ;
F_87 ( V_60 ) ;
return V_98 ;
}
static int F_155 ( struct V_1 * V_2 , T_3 V_159 , T_3
V_160 )
{
struct V_61 * V_193 = & V_2 -> V_3 -> V_193 ;
struct V_214 * V_215 ;
struct V_162 * V_163 ;
T_2 * V_169 ;
int V_98 = 0 ;
T_5 V_216 ;
T_5 V_217 ;
T_5 V_146 = 0 ;
T_5 V_29 ;
struct V_127 V_128 ;
V_217 = F_156 ( V_193 ) ;
V_169 = V_193 -> V_218 ;
V_29 = 0 ;
while ( V_29 < V_217 ) {
V_215 = (struct V_214 * ) V_169 ;
F_157 ( & V_128 , V_215 ) ;
V_146 = sizeof( * V_215 ) ;
if ( V_128 . type == V_164 ) {
V_163 = (struct V_162 * ) ( V_169 + V_146 ) ;
V_216 = F_158 ( V_163 ) ;
V_146 += F_159 ( V_216 ) ;
} else {
V_98 = - V_118 ;
break;
}
if ( V_128 . V_138 == V_159 &&
V_128 . V_139 == V_160 ) {
memmove ( V_169 , V_169 + V_146 , V_217 - ( V_29 + V_146 ) ) ;
V_217 -= V_146 ;
F_160 ( V_193 , V_217 ) ;
} else {
V_169 += V_146 ;
V_29 += V_146 ;
}
}
return V_98 ;
}
static int F_161 ( struct V_1 * V_2 ,
T_3 V_158 , T_3 V_159 ,
T_3 V_160 )
{
struct V_219 * V_220 ;
struct V_1 * V_221 ;
struct V_143 * V_144 ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
int V_98 ;
int V_226 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_221 = V_2 -> V_3 -> V_221 ;
V_220 = & V_2 -> V_3 -> V_227 . V_228 ;
V_98 = F_162 ( V_221 , V_160 ) ;
if ( V_98 )
return - V_153 ;
V_98 = F_163 ( V_221 , V_160 ) ;
if ( V_98 )
return V_98 ;
V_144 = F_120 ( V_2 , 0 ) ;
F_26 ( F_63 ( V_144 ) ) ;
F_1 ( V_2 ) ;
F_164 ( & V_220 -> V_229 ) ;
V_223 = F_165 ( V_220 , V_160 , 1 ) ;
F_166 ( & V_220 -> V_229 ) ;
F_26 ( V_223 -> V_124 > V_160 ||
V_223 -> V_124 + V_223 -> V_146 < V_160 ) ;
V_225 = (struct V_224 * ) V_223 -> V_39 ;
for ( V_226 = 0 ; V_226 < V_225 -> V_216 ; V_226 ++ ) {
V_98 = F_90 ( V_144 , V_225 -> V_230 [ V_226 ] . V_231 ,
V_225 -> V_230 [ V_226 ] . V_232 ) ;
F_26 ( V_98 ) ;
if ( V_225 -> V_230 [ V_226 ] . V_231 ) {
V_98 = F_151 ( V_144 , V_225 -> V_230 [ V_226 ] . V_231 ) ;
F_26 ( V_98 ) ;
}
}
V_98 = F_154 ( V_144 , V_2 , V_158 , V_159 ,
V_160 ) ;
F_26 ( V_98 ) ;
F_167 ( V_2 , V_225 , V_160 , V_223 -> V_146 ) ;
if ( V_225 -> type & V_233 ) {
V_98 = F_155 ( V_2 , V_159 , V_160 ) ;
F_26 ( V_98 ) ;
}
V_98 = F_168 ( V_144 , V_221 , V_160 ) ;
F_26 ( V_98 ) ;
F_169 ( & V_220 -> V_229 ) ;
F_170 ( V_220 , V_223 ) ;
F_171 ( & V_220 -> V_229 ) ;
F_10 ( V_225 ) ;
V_223 -> V_39 = NULL ;
F_172 ( V_223 ) ;
F_172 ( V_223 ) ;
F_3 ( V_2 ) ;
F_173 ( V_144 , V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_1 * V_165 = V_2 -> V_3 -> V_165 ;
struct V_131 * V_60 ;
struct V_134 * V_155 ;
struct V_162 * V_163 ;
struct V_127 V_128 ;
struct V_127 V_154 ;
T_3 V_158 = V_165 -> V_234 . V_138 ;
T_3 V_235 ;
bool V_236 = false ;
int V_237 = 0 ;
int V_98 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_30:
V_128 . V_138 = V_238 ;
V_128 . V_139 = ( T_3 ) - 1 ;
V_128 . type = V_164 ;
while ( 1 ) {
V_98 = F_79 ( NULL , V_165 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto error;
F_26 ( V_98 == 0 ) ;
V_98 = F_80 ( V_165 , V_60 , V_128 . V_138 ,
V_128 . type ) ;
if ( V_98 < 0 )
goto error;
if ( V_98 > 0 )
break;
V_155 = V_60 -> V_141 [ 0 ] ;
F_83 ( V_155 , & V_154 , V_60 -> V_142 [ 0 ] ) ;
V_163 = F_85 ( V_155 , V_60 -> V_142 [ 0 ] ,
struct V_162 ) ;
V_235 = F_174 ( V_155 , V_163 ) ;
F_138 ( V_60 ) ;
if ( V_235 & V_233 ) {
V_98 = F_161 ( V_165 , V_158 ,
V_154 . V_138 ,
V_154 . V_139 ) ;
if ( V_98 == - V_153 )
V_237 ++ ;
else if ( V_98 )
F_175 () ;
}
if ( V_154 . V_139 == 0 )
break;
V_128 . V_139 = V_154 . V_139 - 1 ;
}
V_98 = 0 ;
if ( V_237 && ! V_236 ) {
V_237 = 0 ;
V_236 = true ;
goto V_30;
} else if ( V_237 && V_236 ) {
F_6 ( 1 ) ;
V_98 = - V_153 ;
}
error:
F_87 ( V_60 ) ;
return V_98 ;
}
static T_3 F_176 ( T_3 V_239 , int V_240 )
{
if ( V_240 == 10 )
return V_239 ;
V_239 *= V_240 ;
F_177 ( V_239 , 10 ) ;
return V_239 ;
}
int F_178 ( struct V_1 * V_40 )
{
int V_98 ;
struct V_104 * V_10 = & V_40 -> V_3 -> V_6 -> V_10 ;
struct V_7 * V_8 ;
T_3 V_241 ;
T_3 V_242 ;
struct V_131 * V_60 ;
struct V_127 V_128 ;
struct V_1 * V_165 = V_40 -> V_3 -> V_165 ;
struct V_143 * V_144 ;
struct V_127 V_154 ;
if ( V_40 -> V_3 -> V_191 -> V_202 & V_203 )
return - V_243 ;
if ( ! F_179 ( V_244 ) )
return - V_245 ;
F_2 ( & V_40 -> V_3 -> V_180 ) ;
V_40 = V_40 -> V_3 -> V_40 ;
F_13 (device, devices, dev_list) {
V_241 = V_8 -> V_136 ;
V_242 = F_176 ( V_241 , 1 ) ;
V_242 = F_180 ( V_242 , ( T_3 ) 1 * 1024 * 1024 ) ;
if ( ! V_8 -> V_86 ||
V_8 -> V_136 - V_8 -> V_157 > V_242 )
continue;
V_98 = F_124 ( V_8 , V_241 - V_242 ) ;
if ( V_98 == - V_153 )
break;
F_26 ( V_98 ) ;
V_144 = F_120 ( V_40 , 0 ) ;
F_26 ( F_63 ( V_144 ) ) ;
V_98 = F_153 ( V_144 , V_8 , V_241 ) ;
F_26 ( V_98 ) ;
F_173 ( V_144 , V_40 ) ;
}
V_60 = F_78 () ;
if ( ! V_60 ) {
V_98 = - V_67 ;
goto error;
}
V_128 . V_138 = V_238 ;
V_128 . V_139 = ( T_3 ) - 1 ;
V_128 . type = V_164 ;
while ( 1 ) {
V_98 = F_79 ( NULL , V_165 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto error;
if ( V_98 == 0 )
break;
V_98 = F_80 ( V_165 , V_60 , 0 ,
V_164 ) ;
if ( V_98 )
break;
F_83 ( V_60 -> V_141 [ 0 ] , & V_154 ,
V_60 -> V_142 [ 0 ] ) ;
if ( V_154 . V_138 != V_128 . V_138 )
break;
if ( V_154 . V_139 == 0 )
break;
F_138 ( V_60 ) ;
V_98 = F_161 ( V_165 ,
V_165 -> V_234 . V_138 ,
V_154 . V_138 ,
V_154 . V_139 ) ;
if ( V_98 && V_98 != - V_153 )
goto error;
V_128 . V_139 = V_154 . V_139 - 1 ;
}
V_98 = 0 ;
error:
F_87 ( V_60 ) ;
F_4 ( & V_40 -> V_3 -> V_180 ) ;
return V_98 ;
}
int F_124 ( struct V_7 * V_8 , T_3 V_210 )
{
struct V_143 * V_144 ;
struct V_1 * V_2 = V_8 -> V_40 ;
struct V_129 * V_130 = NULL ;
struct V_131 * V_60 ;
T_3 V_126 ;
T_3 V_158 ;
T_3 V_159 ;
T_3 V_160 ;
int V_98 ;
int V_133 ;
int V_237 = 0 ;
bool V_236 = false ;
struct V_134 * V_135 ;
struct V_127 V_128 ;
struct V_61 * V_193 = & V_2 -> V_3 -> V_193 ;
T_3 V_211 = F_145 ( V_193 ) ;
T_3 V_241 = V_8 -> V_136 ;
T_3 V_212 = V_8 -> V_136 - V_210 ;
if ( V_210 >= V_8 -> V_136 )
return - V_111 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_60 -> V_137 = 2 ;
F_1 ( V_2 ) ;
V_8 -> V_136 = V_210 ;
if ( V_8 -> V_86 )
V_8 -> V_6 -> V_120 -= V_212 ;
F_3 ( V_2 ) ;
V_30:
V_128 . V_138 = V_8 -> V_63 ;
V_128 . V_139 = ( T_3 ) - 1 ;
V_128 . type = V_140 ;
while ( 1 ) {
V_98 = F_79 ( NULL , V_2 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto V_58;
V_98 = F_80 ( V_2 , V_60 , 0 , V_128 . type ) ;
if ( V_98 < 0 )
goto V_58;
if ( V_98 ) {
V_98 = 0 ;
F_138 ( V_60 ) ;
break;
}
V_135 = V_60 -> V_141 [ 0 ] ;
V_133 = V_60 -> V_142 [ 0 ] ;
F_83 ( V_135 , & V_128 , V_60 -> V_142 [ 0 ] ) ;
if ( V_128 . V_138 != V_8 -> V_63 ) {
F_138 ( V_60 ) ;
break;
}
V_130 = F_85 ( V_135 , V_133 , struct V_129 ) ;
V_126 = F_86 ( V_135 , V_130 ) ;
if ( V_128 . V_139 + V_126 <= V_210 ) {
F_138 ( V_60 ) ;
break;
}
V_158 = F_181 ( V_135 , V_130 ) ;
V_159 = F_182 ( V_135 , V_130 ) ;
V_160 = F_183 ( V_135 , V_130 ) ;
F_138 ( V_60 ) ;
V_98 = F_161 ( V_2 , V_158 , V_159 ,
V_160 ) ;
if ( V_98 && V_98 != - V_153 )
goto V_58;
if ( V_98 == - V_153 )
V_237 ++ ;
V_128 . V_139 -= 1 ;
}
if ( V_237 && ! V_236 ) {
V_237 = 0 ;
V_236 = true ;
goto V_30;
} else if ( V_237 && V_236 ) {
V_98 = - V_153 ;
F_1 ( V_2 ) ;
V_8 -> V_136 = V_241 ;
if ( V_8 -> V_86 )
V_8 -> V_6 -> V_120 += V_212 ;
F_3 ( V_2 ) ;
goto V_58;
}
V_144 = F_120 ( V_2 , 0 ) ;
if ( F_63 ( V_144 ) ) {
V_98 = F_76 ( V_144 ) ;
goto V_58;
}
F_1 ( V_2 ) ;
V_8 -> V_209 = V_210 ;
V_98 = F_151 ( V_144 , V_8 ) ;
if ( V_98 ) {
F_3 ( V_2 ) ;
F_173 ( V_144 , V_2 ) ;
goto V_58;
}
F_6 ( V_212 > V_211 ) ;
F_146 ( V_193 , V_211 - V_212 ) ;
F_3 ( V_2 ) ;
F_173 ( V_144 , V_2 ) ;
V_58:
F_87 ( V_60 ) ;
return V_98 ;
}
static int F_184 ( struct V_143 * V_144 ,
struct V_1 * V_2 ,
struct V_127 * V_128 ,
struct V_162 * V_163 , int V_246 )
{
struct V_61 * V_193 = & V_2 -> V_3 -> V_193 ;
struct V_214 V_215 ;
T_5 V_217 ;
T_2 * V_169 ;
V_217 = F_156 ( V_193 ) ;
if ( V_217 + V_246 > V_247 )
return - V_248 ;
V_169 = V_193 -> V_218 + V_217 ;
F_185 ( & V_215 , V_128 ) ;
memcpy ( V_169 , & V_215 , sizeof( V_215 ) ) ;
V_169 += sizeof( V_215 ) ;
memcpy ( V_169 , V_163 , V_246 ) ;
V_246 += sizeof( V_215 ) ;
F_160 ( V_193 , V_217 + V_246 ) ;
return 0 ;
}
static int F_186 ( const void * V_249 , const void * V_250 )
{
const struct V_251 * V_252 = V_249 ;
const struct V_251 * V_253 = V_250 ;
if ( V_252 -> V_254 > V_253 -> V_254 )
return - 1 ;
if ( V_252 -> V_254 < V_253 -> V_254 )
return 1 ;
if ( V_252 -> V_255 > V_253 -> V_255 )
return - 1 ;
if ( V_252 -> V_255 < V_253 -> V_255 )
return 1 ;
return 0 ;
}
static int F_187 ( struct V_143 * V_144 ,
struct V_1 * V_221 ,
struct V_224 * * V_256 ,
T_3 * V_257 , T_3 * V_258 ,
T_3 V_124 , T_3 type )
{
struct V_28 * V_259 = V_221 -> V_3 ;
struct V_5 * V_6 = V_259 -> V_6 ;
struct V_104 * V_29 ;
struct V_224 * V_225 = NULL ;
struct V_219 * V_220 ;
struct V_222 * V_223 ;
struct V_251 * V_260 = NULL ;
T_3 V_255 ;
int V_216 ;
int V_261 ;
int V_262 ;
int V_263 ;
int V_264 ;
int V_265 ;
int V_266 ;
int V_98 ;
T_3 V_267 ;
T_3 V_268 ;
T_3 V_269 ;
T_3 V_145 ;
int V_270 ;
int V_226 ;
int V_271 ;
if ( ( type & V_186 ) &&
( type & V_272 ) ) {
F_6 ( 1 ) ;
type &= ~ V_272 ;
}
if ( F_7 ( & V_6 -> V_68 ) )
return - V_153 ;
V_261 = 1 ;
V_262 = 1 ;
V_265 = 1 ;
V_266 = 1 ;
V_263 = 0 ;
V_264 = 1 ;
if ( type & ( V_272 ) ) {
V_262 = 2 ;
V_266 = 2 ;
V_263 = 1 ;
} else if ( type & ( V_273 ) ) {
V_264 = 2 ;
} else if ( type & ( V_186 ) ) {
V_265 = 2 ;
V_266 = 2 ;
V_263 = 2 ;
V_264 = 2 ;
} else if ( type & ( V_184 ) ) {
V_261 = 2 ;
V_265 = 2 ;
V_266 = 2 ;
V_264 = 4 ;
} else {
V_263 = 1 ;
}
if ( type & V_274 ) {
V_267 = 1024 * 1024 * 1024 ;
V_268 = 10 * V_267 ;
} else if ( type & V_275 ) {
V_267 = 256 * 1024 * 1024 ;
V_268 = V_267 ;
} else if ( type & V_233 ) {
V_267 = 8 * 1024 * 1024 ;
V_268 = 2 * V_267 ;
} else {
F_64 ( V_185 L_14 ,
type ) ;
F_26 ( 1 ) ;
}
V_268 = F_180 ( F_176 ( V_6 -> V_120 , 1 ) ,
V_268 ) ;
V_260 = F_38 ( sizeof( * V_260 ) * V_6 -> V_87 ,
V_66 ) ;
if ( ! V_260 )
return - V_67 ;
V_29 = V_6 -> V_68 . V_11 ;
V_270 = 0 ;
while ( V_29 != & V_6 -> V_68 ) {
struct V_7 * V_8 ;
T_3 V_254 ;
T_3 V_276 ;
V_8 = F_8 ( V_29 , struct V_7 , V_77 ) ;
V_29 = V_29 -> V_11 ;
if ( ! V_8 -> V_86 ) {
F_64 ( V_185
L_15 ) ;
F_6 ( 1 ) ;
continue;
}
if ( ! V_8 -> V_84 )
continue;
if ( V_8 -> V_136 > V_8 -> V_157 )
V_255 = V_8 -> V_136 - V_8 -> V_157 ;
else
V_255 = 0 ;
if ( V_255 == 0 )
continue;
V_98 = F_88 ( V_144 , V_8 ,
V_267 * V_262 ,
& V_276 , & V_254 ) ;
if ( V_98 && V_98 != - V_153 )
goto error;
if ( V_98 == 0 )
V_254 = V_267 * V_262 ;
if ( V_254 < V_277 * V_262 )
continue;
V_260 [ V_270 ] . V_276 = V_276 ;
V_260 [ V_270 ] . V_254 = V_254 ;
V_260 [ V_270 ] . V_255 = V_255 ;
V_260 [ V_270 ] . V_231 = V_8 ;
++ V_270 ;
}
F_188 ( V_260 , V_270 , sizeof( struct V_251 ) ,
F_186 , NULL ) ;
V_270 -= V_270 % V_265 ;
if ( V_270 < V_265 * V_261 || V_270 < V_264 ) {
V_98 = - V_153 ;
goto error;
}
if ( V_263 && V_270 > V_263 )
V_270 = V_263 ;
V_269 = V_260 [ V_270 - 1 ] . V_254 ;
V_216 = V_270 * V_262 ;
if ( V_269 * V_216 > V_268 * V_266 ) {
V_269 = V_268 * V_266 ;
F_177 ( V_269 , V_216 ) ;
}
F_177 ( V_269 , V_262 ) ;
F_177 ( V_269 , V_277 ) ;
V_269 *= V_277 ;
V_225 = F_57 ( F_189 ( V_216 ) , V_66 ) ;
if ( ! V_225 ) {
V_98 = - V_67 ;
goto error;
}
V_225 -> V_216 = V_216 ;
for ( V_226 = 0 ; V_226 < V_270 ; ++ V_226 ) {
for ( V_271 = 0 ; V_271 < V_262 ; ++ V_271 ) {
int V_278 = V_226 * V_262 + V_271 ;
V_225 -> V_230 [ V_278 ] . V_231 = V_260 [ V_226 ] . V_231 ;
V_225 -> V_230 [ V_278 ] . V_232 = V_260 [ V_226 ] . V_276 +
V_271 * V_269 ;
}
}
V_225 -> V_172 = V_221 -> V_208 ;
V_225 -> V_279 = V_277 ;
V_225 -> V_170 = V_277 ;
V_225 -> V_171 = V_277 ;
V_225 -> type = type ;
V_225 -> V_261 = V_261 ;
* V_256 = V_225 ;
V_145 = V_269 * ( V_216 / V_266 ) ;
* V_258 = V_269 ;
* V_257 = V_145 ;
F_190 ( V_259 -> V_165 , V_225 , V_124 , V_145 ) ;
V_223 = F_191 () ;
if ( ! V_223 ) {
V_98 = - V_67 ;
goto error;
}
V_223 -> V_39 = (struct V_103 * ) V_225 ;
V_223 -> V_124 = V_124 ;
V_223 -> V_146 = V_145 ;
V_223 -> V_280 = 0 ;
V_223 -> V_281 = V_223 -> V_146 ;
V_220 = & V_221 -> V_3 -> V_227 . V_228 ;
F_169 ( & V_220 -> V_229 ) ;
V_98 = F_192 ( V_220 , V_223 ) ;
F_171 ( & V_220 -> V_229 ) ;
F_26 ( V_98 ) ;
F_172 ( V_223 ) ;
V_98 = F_193 ( V_144 , V_221 , 0 , type ,
V_238 ,
V_124 , V_145 ) ;
F_26 ( V_98 ) ;
for ( V_226 = 0 ; V_226 < V_225 -> V_216 ; ++ V_226 ) {
struct V_7 * V_8 ;
T_3 V_276 ;
V_8 = V_225 -> V_230 [ V_226 ] . V_231 ;
V_276 = V_225 -> V_230 [ V_226 ] . V_232 ;
V_98 = F_92 ( V_144 , V_8 ,
V_259 -> V_165 -> V_234 . V_138 ,
V_238 ,
V_124 , V_276 , V_269 ) ;
F_26 ( V_98 ) ;
}
F_10 ( V_260 ) ;
return 0 ;
error:
F_10 ( V_225 ) ;
F_10 ( V_260 ) ;
return V_98 ;
}
static int F_194 ( struct V_143 * V_144 ,
struct V_1 * V_221 ,
struct V_224 * V_225 , T_3 V_160 ,
T_3 V_282 , T_3 V_269 )
{
T_3 V_276 ;
struct V_127 V_128 ;
struct V_1 * V_165 = V_221 -> V_3 -> V_165 ;
struct V_7 * V_8 ;
struct V_162 * V_163 ;
struct V_283 * V_284 ;
T_6 V_246 = F_159 ( V_225 -> V_216 ) ;
int V_285 = 0 ;
int V_98 ;
V_163 = F_38 ( V_246 , V_66 ) ;
if ( ! V_163 )
return - V_67 ;
V_285 = 0 ;
while ( V_285 < V_225 -> V_216 ) {
V_8 = V_225 -> V_230 [ V_285 ] . V_231 ;
V_8 -> V_157 += V_269 ;
V_98 = F_151 ( V_144 , V_8 ) ;
F_26 ( V_98 ) ;
V_285 ++ ;
}
V_285 = 0 ;
V_284 = & V_163 -> V_284 ;
while ( V_285 < V_225 -> V_216 ) {
V_8 = V_225 -> V_230 [ V_285 ] . V_231 ;
V_276 = V_225 -> V_230 [ V_285 ] . V_232 ;
F_195 ( V_284 , V_8 -> V_63 ) ;
F_196 ( V_284 , V_276 ) ;
memcpy ( V_284 -> V_178 , V_8 -> V_73 , V_76 ) ;
V_284 ++ ;
V_285 ++ ;
}
F_197 ( V_163 , V_282 ) ;
F_198 ( V_163 , V_221 -> V_234 . V_138 ) ;
F_199 ( V_163 , V_225 -> V_279 ) ;
F_200 ( V_163 , V_225 -> type ) ;
F_201 ( V_163 , V_225 -> V_216 ) ;
F_202 ( V_163 , V_225 -> V_279 ) ;
F_203 ( V_163 , V_225 -> V_279 ) ;
F_204 ( V_163 , V_221 -> V_208 ) ;
F_205 ( V_163 , V_225 -> V_261 ) ;
V_128 . V_138 = V_238 ;
V_128 . type = V_164 ;
V_128 . V_139 = V_160 ;
V_98 = F_206 ( V_144 , V_165 , & V_128 , V_163 , V_246 ) ;
F_26 ( V_98 ) ;
if ( V_225 -> type & V_233 ) {
V_98 = F_184 ( V_144 , V_165 , & V_128 , V_163 ,
V_246 ) ;
F_26 ( V_98 ) ;
}
F_10 ( V_163 ) ;
return 0 ;
}
int F_207 ( struct V_143 * V_144 ,
struct V_1 * V_221 , T_3 type )
{
T_3 V_160 ;
T_3 V_282 ;
T_3 V_269 ;
struct V_224 * V_225 ;
struct V_1 * V_165 = V_221 -> V_3 -> V_165 ;
int V_98 ;
V_98 = F_101 ( V_165 , V_238 ,
& V_160 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_187 ( V_144 , V_221 , & V_225 , & V_282 ,
& V_269 , V_160 , type ) ;
if ( V_98 )
return V_98 ;
V_98 = F_194 ( V_144 , V_221 , V_225 , V_160 ,
V_282 , V_269 ) ;
F_26 ( V_98 ) ;
return 0 ;
}
static T_1 int F_147 ( struct V_143 * V_144 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_3 V_160 ;
T_3 V_286 ;
T_3 V_282 ;
T_3 V_287 ;
T_3 V_269 ;
T_3 V_288 ;
T_3 V_289 ;
struct V_224 * V_225 ;
struct V_224 * V_290 ;
struct V_28 * V_3 = V_2 -> V_3 ;
struct V_1 * V_221 = V_3 -> V_221 ;
int V_98 ;
V_98 = F_101 ( V_3 -> V_165 ,
V_238 , & V_160 ) ;
if ( V_98 )
return V_98 ;
V_289 = V_275 |
( V_3 -> V_291 &
V_3 -> V_183 ) ;
V_289 = F_208 ( V_2 , V_289 ) ;
V_98 = F_187 ( V_144 , V_221 , & V_225 , & V_282 ,
& V_269 , V_160 , V_289 ) ;
F_26 ( V_98 ) ;
V_286 = V_160 + V_282 ;
V_289 = V_233 |
( V_3 -> V_292 &
V_3 -> V_182 ) ;
V_289 = F_208 ( V_2 , V_289 ) ;
V_98 = F_187 ( V_144 , V_221 , & V_290 ,
& V_287 , & V_288 ,
V_286 , V_289 ) ;
F_26 ( V_98 ) ;
V_98 = F_104 ( V_144 , V_3 -> V_165 , V_8 ) ;
F_26 ( V_98 ) ;
V_98 = F_194 ( V_144 , V_221 , V_225 , V_160 ,
V_282 , V_269 ) ;
F_26 ( V_98 ) ;
V_98 = F_194 ( V_144 , V_221 , V_290 ,
V_286 , V_287 ,
V_288 ) ;
F_26 ( V_98 ) ;
return 0 ;
}
int F_209 ( struct V_1 * V_2 , T_3 V_160 )
{
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_293 * V_228 = & V_2 -> V_3 -> V_227 ;
int V_294 = 0 ;
int V_226 ;
F_164 ( & V_228 -> V_228 . V_229 ) ;
V_223 = F_165 ( & V_228 -> V_228 , V_160 , 1 ) ;
F_166 ( & V_228 -> V_228 . V_229 ) ;
if ( ! V_223 )
return 1 ;
if ( F_210 ( V_2 , V_295 ) ) {
F_172 ( V_223 ) ;
return 0 ;
}
V_225 = (struct V_224 * ) V_223 -> V_39 ;
for ( V_226 = 0 ; V_226 < V_225 -> V_216 ; V_226 ++ ) {
if ( ! V_225 -> V_230 [ V_226 ] . V_231 -> V_86 ) {
V_294 = 1 ;
break;
}
}
F_172 ( V_223 ) ;
return V_294 ;
}
void F_211 ( struct V_293 * V_296 )
{
F_212 ( & V_296 -> V_228 ) ;
}
void F_213 ( struct V_293 * V_296 )
{
struct V_222 * V_223 ;
while ( 1 ) {
F_169 ( & V_296 -> V_228 . V_229 ) ;
V_223 = F_165 ( & V_296 -> V_228 , 0 , ( T_3 ) - 1 ) ;
if ( V_223 )
F_170 ( & V_296 -> V_228 , V_223 ) ;
F_171 ( & V_296 -> V_228 . V_229 ) ;
if ( ! V_223 )
break;
F_10 ( V_223 -> V_39 ) ;
F_172 ( V_223 ) ;
F_172 ( V_223 ) ;
}
}
int F_214 ( struct V_293 * V_228 , T_3 V_297 , T_3 V_146 )
{
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_219 * V_220 = & V_228 -> V_228 ;
int V_98 ;
F_164 ( & V_220 -> V_229 ) ;
V_223 = F_165 ( V_220 , V_297 , V_146 ) ;
F_166 ( & V_220 -> V_229 ) ;
F_26 ( ! V_223 ) ;
F_26 ( V_223 -> V_124 > V_297 || V_223 -> V_124 + V_223 -> V_146 < V_297 ) ;
V_225 = (struct V_224 * ) V_223 -> V_39 ;
if ( V_225 -> type & ( V_272 | V_186 ) )
V_98 = V_225 -> V_216 ;
else if ( V_225 -> type & V_184 )
V_98 = V_225 -> V_261 ;
else
V_98 = 1 ;
F_172 ( V_223 ) ;
return V_98 ;
}
static int F_215 ( struct V_224 * V_225 , int V_298 , int V_239 ,
int V_299 )
{
int V_226 ;
if ( V_225 -> V_230 [ V_299 ] . V_231 -> V_39 )
return V_299 ;
for ( V_226 = V_298 ; V_226 < V_298 + V_239 ; V_226 ++ ) {
if ( V_225 -> V_230 [ V_226 ] . V_231 -> V_39 )
return V_226 ;
}
return V_299 ;
}
static int F_216 ( struct V_293 * V_228 , int V_300 ,
T_3 V_297 , T_3 * V_126 ,
struct V_301 * * V_302 ,
int V_303 )
{
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_219 * V_220 = & V_228 -> V_228 ;
T_3 V_139 ;
T_3 V_304 ;
T_3 V_305 ;
T_3 V_306 ;
T_3 V_307 ;
T_3 V_308 ;
int V_309 = 8 ;
int V_310 = 1 ;
int V_311 ;
int V_226 ;
int V_216 ;
int V_312 = 0 ;
struct V_301 * V_313 = NULL ;
if ( V_302 && ! ( V_300 & ( V_314 | V_315 ) ) )
V_309 = 1 ;
V_30:
if ( V_302 ) {
V_313 = F_38 ( F_217 ( V_309 ) ,
V_66 ) ;
if ( ! V_313 )
return - V_67 ;
F_218 ( & V_313 -> error , 0 ) ;
}
F_164 ( & V_220 -> V_229 ) ;
V_223 = F_165 ( V_220 , V_297 , * V_126 ) ;
F_166 ( & V_220 -> V_229 ) ;
if ( ! V_223 ) {
F_64 ( V_316 L_16 ,
( unsigned long long ) V_297 ,
( unsigned long long ) * V_126 ) ;
F_175 () ;
}
F_26 ( V_223 -> V_124 > V_297 || V_223 -> V_124 + V_223 -> V_146 < V_297 ) ;
V_225 = (struct V_224 * ) V_223 -> V_39 ;
V_139 = V_297 - V_223 -> V_124 ;
if ( V_303 > V_225 -> V_216 )
V_303 = 0 ;
if ( V_300 & V_314 ) {
if ( V_225 -> type & ( V_186 |
V_272 ) ) {
V_310 = V_225 -> V_216 ;
V_312 = 1 ;
} else if ( V_225 -> type & V_184 ) {
V_310 = V_225 -> V_261 ;
V_312 = 1 ;
}
}
if ( V_300 & V_315 ) {
if ( V_225 -> type & ( V_273 |
V_186 |
V_272 |
V_184 ) ) {
V_310 = V_225 -> V_216 ;
}
}
if ( V_302 && ( V_300 & ( V_314 | V_315 ) ) &&
V_309 < V_310 ) {
V_309 = V_225 -> V_216 ;
F_172 ( V_223 ) ;
F_10 ( V_313 ) ;
goto V_30;
}
V_306 = V_139 ;
F_177 ( V_306 , V_225 -> V_279 ) ;
V_304 = V_306 * V_225 -> V_279 ;
F_26 ( V_139 < V_304 ) ;
V_304 = V_139 - V_304 ;
if ( V_300 & V_315 )
* V_126 = F_219 ( T_3 , V_223 -> V_146 - V_139 , * V_126 ) ;
else if ( V_225 -> type & ( V_273 |
V_186 |
V_184 |
V_272 ) ) {
* V_126 = F_219 ( T_3 , V_223 -> V_146 - V_139 ,
V_225 -> V_279 - V_304 ) ;
} else {
* V_126 = V_223 -> V_146 - V_139 ;
}
if ( ! V_302 )
goto V_119;
V_216 = 1 ;
V_311 = 0 ;
V_307 = V_306 ;
V_308 = ( V_139 + * V_126 + V_225 -> V_279 - 1 ) &
( ~ ( V_225 -> V_279 - 1 ) ) ;
F_177 ( V_308 , V_225 -> V_279 ) ;
V_305 = V_308 * V_225 -> V_279 -
( V_139 + * V_126 ) ;
if ( V_225 -> type & V_273 ) {
if ( V_300 & V_315 )
V_216 = F_219 ( T_3 , V_225 -> V_216 ,
V_308 - V_307 ) ;
V_311 = F_177 ( V_306 , V_225 -> V_216 ) ;
} else if ( V_225 -> type & V_186 ) {
if ( V_300 & ( V_314 | V_315 ) )
V_216 = V_225 -> V_216 ;
else if ( V_303 )
V_311 = V_303 - 1 ;
else {
V_311 = F_215 ( V_225 , 0 ,
V_225 -> V_216 ,
V_53 -> V_317 % V_225 -> V_216 ) ;
}
} else if ( V_225 -> type & V_272 ) {
if ( V_300 & ( V_314 | V_315 ) )
V_216 = V_225 -> V_216 ;
else if ( V_303 )
V_311 = V_303 - 1 ;
} else if ( V_225 -> type & V_184 ) {
int V_240 = V_225 -> V_216 / V_225 -> V_261 ;
V_311 = F_177 ( V_306 , V_240 ) ;
V_311 *= V_225 -> V_261 ;
if ( V_300 & V_314 )
V_216 = V_225 -> V_261 ;
else if ( V_300 & V_315 )
V_216 = F_219 ( T_3 , V_225 -> V_261 *
( V_308 - V_307 ) ,
V_225 -> V_216 ) ;
else if ( V_303 )
V_311 += V_303 - 1 ;
else {
V_311 = F_215 ( V_225 , V_311 ,
V_225 -> V_261 , V_311 +
V_53 -> V_317 % V_225 -> V_261 ) ;
}
} else {
V_311 = F_177 ( V_306 , V_225 -> V_216 ) ;
}
F_26 ( V_311 >= V_225 -> V_216 ) ;
if ( V_300 & V_315 ) {
for ( V_226 = 0 ; V_226 < V_216 ; V_226 ++ ) {
V_313 -> V_230 [ V_226 ] . V_232 =
V_225 -> V_230 [ V_311 ] . V_232 +
V_304 + V_306 * V_225 -> V_279 ;
V_313 -> V_230 [ V_226 ] . V_231 = V_225 -> V_230 [ V_311 ] . V_231 ;
if ( V_225 -> type & V_273 ) {
T_3 V_230 ;
T_5 V_318 = 0 ;
int V_271 ;
F_220 ( V_308 - 1 ,
V_225 -> V_216 ,
& V_318 ) ;
for ( V_271 = 0 ; V_271 < V_225 -> V_216 ; V_271 ++ ) {
T_5 V_319 ;
F_220 ( V_308 - 1 - V_271 ,
V_225 -> V_216 , & V_319 ) ;
if ( V_319 == V_311 )
break;
}
V_230 = V_308 - 1 - V_271 ;
F_177 ( V_230 , V_225 -> V_216 ) ;
V_313 -> V_230 [ V_226 ] . V_126 = V_225 -> V_279 *
( V_230 - V_306 + 1 ) ;
if ( V_226 == 0 ) {
V_313 -> V_230 [ V_226 ] . V_126 -=
V_304 ;
V_304 = 0 ;
}
if ( V_311 == V_318 )
V_313 -> V_230 [ V_226 ] . V_126 -=
V_305 ;
} else if ( V_225 -> type & V_184 ) {
T_3 V_230 ;
int V_271 ;
int V_240 = V_225 -> V_216 /
V_225 -> V_261 ;
T_5 V_318 = 0 ;
F_220 ( V_308 - 1 ,
V_240 , & V_318 ) ;
V_318 *= V_225 -> V_261 ;
for ( V_271 = 0 ; V_271 < V_240 ; V_271 ++ ) {
T_5 V_319 ;
F_220 ( V_308 - 1 - V_271 ,
V_240 , & V_319 ) ;
if ( V_319 ==
V_311 / V_225 -> V_261 )
break;
}
V_230 = V_308 - 1 - V_271 ;
F_177 ( V_230 , V_240 ) ;
V_313 -> V_230 [ V_226 ] . V_126 = V_225 -> V_279 *
( V_230 - V_306 + 1 ) ;
if ( V_226 < V_225 -> V_261 ) {
V_313 -> V_230 [ V_226 ] . V_126 -=
V_304 ;
if ( V_226 == V_225 -> V_261 - 1 )
V_304 = 0 ;
}
if ( V_311 >= V_318 &&
V_311 <= ( V_318 +
V_225 -> V_261 - 1 ) ) {
V_313 -> V_230 [ V_226 ] . V_126 -=
V_305 ;
}
} else
V_313 -> V_230 [ V_226 ] . V_126 = * V_126 ;
V_311 ++ ;
if ( V_311 == V_225 -> V_216 ) {
V_311 = 0 ;
V_306 ++ ;
}
}
} else {
for ( V_226 = 0 ; V_226 < V_216 ; V_226 ++ ) {
V_313 -> V_230 [ V_226 ] . V_232 =
V_225 -> V_230 [ V_311 ] . V_232 +
V_304 +
V_306 * V_225 -> V_279 ;
V_313 -> V_230 [ V_226 ] . V_231 =
V_225 -> V_230 [ V_311 ] . V_231 ;
V_311 ++ ;
}
}
if ( V_302 ) {
* V_302 = V_313 ;
V_313 -> V_216 = V_216 ;
V_313 -> V_312 = V_312 ;
}
V_119:
F_172 ( V_223 ) ;
return 0 ;
}
int F_221 ( struct V_293 * V_228 , int V_300 ,
T_3 V_297 , T_3 * V_126 ,
struct V_301 * * V_302 , int V_303 )
{
return F_216 ( V_228 , V_300 , V_297 , V_126 , V_302 ,
V_303 ) ;
}
int F_222 ( struct V_293 * V_228 ,
T_3 V_320 , T_3 V_232 , T_3 V_63 ,
T_3 * * V_297 , int * V_321 , int * V_279 )
{
struct V_219 * V_220 = & V_228 -> V_228 ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
T_3 * V_322 ;
T_3 V_323 ;
T_3 V_126 ;
T_3 V_306 ;
int V_226 , V_271 , V_324 = 0 ;
F_164 ( & V_220 -> V_229 ) ;
V_223 = F_165 ( V_220 , V_320 , 1 ) ;
F_166 ( & V_220 -> V_229 ) ;
F_26 ( ! V_223 || V_223 -> V_124 != V_320 ) ;
V_225 = (struct V_224 * ) V_223 -> V_39 ;
V_126 = V_223 -> V_146 ;
if ( V_225 -> type & V_184 )
F_177 ( V_126 , V_225 -> V_216 / V_225 -> V_261 ) ;
else if ( V_225 -> type & V_273 )
F_177 ( V_126 , V_225 -> V_216 ) ;
V_322 = F_38 ( sizeof( T_3 ) * V_225 -> V_216 , V_66 ) ;
F_26 ( ! V_322 ) ;
for ( V_226 = 0 ; V_226 < V_225 -> V_216 ; V_226 ++ ) {
if ( V_63 && V_225 -> V_230 [ V_226 ] . V_231 -> V_63 != V_63 )
continue;
if ( V_225 -> V_230 [ V_226 ] . V_232 > V_232 ||
V_225 -> V_230 [ V_226 ] . V_232 + V_126 <= V_232 )
continue;
V_306 = V_232 - V_225 -> V_230 [ V_226 ] . V_232 ;
F_177 ( V_306 , V_225 -> V_279 ) ;
if ( V_225 -> type & V_184 ) {
V_306 = V_306 * V_225 -> V_216 + V_226 ;
F_177 ( V_306 , V_225 -> V_261 ) ;
} else if ( V_225 -> type & V_273 ) {
V_306 = V_306 * V_225 -> V_216 + V_226 ;
}
V_323 = V_320 + V_306 * V_225 -> V_279 ;
F_6 ( V_324 >= V_225 -> V_216 ) ;
for ( V_271 = 0 ; V_271 < V_324 ; V_271 ++ ) {
if ( V_322 [ V_271 ] == V_323 )
break;
}
if ( V_271 == V_324 ) {
F_6 ( V_324 >= V_225 -> V_216 ) ;
V_322 [ V_324 ++ ] = V_323 ;
}
}
* V_297 = V_322 ;
* V_321 = V_324 ;
* V_279 = V_225 -> V_279 ;
F_172 ( V_223 ) ;
return 0 ;
}
static void F_223 ( struct V_20 * V_20 , int V_325 )
{
struct V_301 * V_313 = V_20 -> V_326 ;
int V_327 = 0 ;
if ( V_325 )
F_224 ( & V_313 -> error ) ;
if ( V_20 == V_313 -> V_328 )
V_327 = 1 ;
if ( F_225 ( & V_313 -> V_329 ) ) {
if ( ! V_327 ) {
F_226 ( V_20 ) ;
V_20 = V_313 -> V_328 ;
}
V_20 -> V_326 = V_313 -> V_330 ;
V_20 -> V_331 = V_313 -> V_332 ;
if ( F_23 ( & V_313 -> error ) > V_313 -> V_312 ) {
V_325 = - V_118 ;
} else if ( V_325 ) {
F_227 ( V_333 , & V_20 -> V_334 ) ;
V_325 = 0 ;
}
F_10 ( V_313 ) ;
F_228 ( V_20 , V_325 ) ;
} else if ( ! V_327 ) {
F_226 ( V_20 ) ;
}
}
static T_1 int F_229 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
int V_300 , struct V_20 * V_20 )
{
int V_335 = 1 ;
struct V_18 * V_19 ;
if ( ! ( V_300 & V_314 ) ) {
F_230 ( V_20 ) ;
F_28 ( V_300 , V_20 ) ;
F_226 ( V_20 ) ;
return 0 ;
}
F_224 ( & V_2 -> V_3 -> V_46 ) ;
F_6 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
V_20 -> V_49 |= V_300 ;
F_19 ( & V_8 -> V_42 ) ;
if ( V_20 -> V_49 & V_336 )
V_19 = & V_8 -> V_44 ;
else
V_19 = & V_8 -> V_19 ;
if ( V_19 -> V_22 )
V_19 -> V_22 -> V_24 = V_20 ;
V_19 -> V_22 = V_20 ;
if ( ! V_19 -> V_21 )
V_19 -> V_21 = V_20 ;
if ( V_8 -> V_45 )
V_335 = 0 ;
F_20 ( & V_8 -> V_42 ) ;
if ( V_335 )
F_231 ( & V_2 -> V_3 -> V_337 ,
& V_8 -> V_57 ) ;
return 0 ;
}
int F_232 ( struct V_1 * V_2 , int V_300 , struct V_20 * V_20 ,
int V_303 , int V_338 )
{
struct V_293 * V_228 ;
struct V_7 * V_231 ;
struct V_20 * V_339 = V_20 ;
T_3 V_297 = ( T_3 ) V_20 -> V_340 << 9 ;
T_3 V_126 = 0 ;
T_3 V_341 ;
struct V_301 * V_313 = NULL ;
int V_98 ;
int V_342 = 0 ;
int V_343 = 1 ;
V_126 = V_20 -> V_344 ;
V_228 = & V_2 -> V_3 -> V_227 ;
V_341 = V_126 ;
V_98 = F_221 ( V_228 , V_300 , V_297 , & V_341 , & V_313 ,
V_303 ) ;
F_26 ( V_98 ) ;
V_343 = V_313 -> V_216 ;
if ( V_341 < V_126 ) {
F_64 ( V_316 L_17
L_18 , ( unsigned long long ) V_297 ,
( unsigned long long ) V_126 ,
( unsigned long long ) V_341 ) ;
F_175 () ;
}
V_313 -> V_332 = V_339 -> V_331 ;
V_313 -> V_330 = V_339 -> V_326 ;
V_313 -> V_328 = V_339 ;
F_218 ( & V_313 -> V_329 , V_313 -> V_216 ) ;
while ( V_342 < V_343 ) {
if ( V_343 > 1 ) {
if ( V_342 < V_343 - 1 ) {
V_20 = F_233 ( V_339 , V_66 ) ;
F_26 ( ! V_20 ) ;
} else {
V_20 = V_339 ;
}
V_20 -> V_326 = V_313 ;
V_20 -> V_331 = F_223 ;
}
V_20 -> V_340 = V_313 -> V_230 [ V_342 ] . V_232 >> 9 ;
V_231 = V_313 -> V_230 [ V_342 ] . V_231 ;
if ( V_231 && V_231 -> V_39 && ( V_300 != V_345 || V_231 -> V_86 ) ) {
V_20 -> V_346 = V_231 -> V_39 ;
if ( V_338 )
F_229 ( V_2 , V_231 , V_300 , V_20 ) ;
else
F_28 ( V_300 , V_20 ) ;
} else {
V_20 -> V_346 = V_2 -> V_3 -> V_6 -> V_105 ;
V_20 -> V_340 = V_297 >> 9 ;
F_228 ( V_20 , - V_118 ) ;
}
V_342 ++ ;
}
if ( V_343 == 1 )
F_10 ( V_313 ) ;
return 0 ;
}
struct V_7 * F_123 ( struct V_1 * V_2 , T_3 V_63 ,
T_2 * V_73 , T_2 * V_16 )
{
struct V_7 * V_8 ;
struct V_5 * V_176 ;
V_176 = V_2 -> V_3 -> V_6 ;
while ( V_176 ) {
if ( ! V_16 ||
! memcmp ( V_176 -> V_16 , V_16 , V_76 ) ) {
V_8 = F_42 ( & V_176 -> V_10 ,
V_63 , V_73 ) ;
if ( V_8 )
return V_8 ;
}
V_176 = V_176 -> V_88 ;
}
return NULL ;
}
static struct V_7 * F_234 ( struct V_1 * V_2 ,
T_3 V_63 , T_2 * V_178 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 = V_2 -> V_3 -> V_6 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_66 ) ;
if ( ! V_8 )
return NULL ;
F_40 ( & V_8 -> V_12 ,
& V_6 -> V_10 ) ;
V_8 -> V_40 = V_2 -> V_3 -> V_40 ;
V_8 -> V_63 = V_63 ;
V_8 -> V_57 . V_75 = F_34 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_79 = 1 ;
V_6 -> V_78 ++ ;
V_6 -> V_80 ++ ;
F_43 ( & V_8 -> V_42 ) ;
F_39 ( & V_8 -> V_77 ) ;
memcpy ( V_8 -> V_73 , V_178 , V_76 ) ;
return V_8 ;
}
static int F_235 ( struct V_1 * V_2 , struct V_127 * V_128 ,
struct V_134 * V_155 ,
struct V_162 * V_163 )
{
struct V_293 * V_228 = & V_2 -> V_3 -> V_227 ;
struct V_224 * V_225 ;
struct V_222 * V_223 ;
T_3 V_297 ;
T_3 V_126 ;
T_3 V_63 ;
T_2 V_73 [ V_76 ] ;
int V_216 ;
int V_98 ;
int V_226 ;
V_297 = V_128 -> V_139 ;
V_126 = F_102 ( V_155 , V_163 ) ;
F_164 ( & V_228 -> V_228 . V_229 ) ;
V_223 = F_165 ( & V_228 -> V_228 , V_297 , 1 ) ;
F_166 ( & V_228 -> V_228 . V_229 ) ;
if ( V_223 && V_223 -> V_124 <= V_297 && V_223 -> V_124 + V_223 -> V_146 > V_297 ) {
F_172 ( V_223 ) ;
return 0 ;
} else if ( V_223 ) {
F_172 ( V_223 ) ;
}
V_223 = F_191 () ;
if ( ! V_223 )
return - V_67 ;
V_216 = F_236 ( V_155 , V_163 ) ;
V_225 = F_57 ( F_189 ( V_216 ) , V_66 ) ;
if ( ! V_225 ) {
F_172 ( V_223 ) ;
return - V_67 ;
}
V_223 -> V_39 = (struct V_103 * ) V_225 ;
V_223 -> V_124 = V_297 ;
V_223 -> V_146 = V_126 ;
V_223 -> V_280 = 0 ;
V_223 -> V_281 = V_223 -> V_146 ;
V_225 -> V_216 = V_216 ;
V_225 -> V_171 = F_237 ( V_155 , V_163 ) ;
V_225 -> V_170 = F_238 ( V_155 , V_163 ) ;
V_225 -> V_172 = F_239 ( V_155 , V_163 ) ;
V_225 -> V_279 = F_240 ( V_155 , V_163 ) ;
V_225 -> type = F_174 ( V_155 , V_163 ) ;
V_225 -> V_261 = F_241 ( V_155 , V_163 ) ;
for ( V_226 = 0 ; V_226 < V_216 ; V_226 ++ ) {
V_225 -> V_230 [ V_226 ] . V_232 =
F_242 ( V_155 , V_163 , V_226 ) ;
V_63 = F_243 ( V_155 , V_163 , V_226 ) ;
F_140 ( V_155 , V_73 , ( unsigned long )
F_244 ( V_163 , V_226 ) ,
V_76 ) ;
V_225 -> V_230 [ V_226 ] . V_231 = F_123 ( V_2 , V_63 , V_73 ,
NULL ) ;
if ( ! V_225 -> V_230 [ V_226 ] . V_231 && ! F_210 ( V_2 , V_295 ) ) {
F_10 ( V_225 ) ;
F_172 ( V_223 ) ;
return - V_118 ;
}
if ( ! V_225 -> V_230 [ V_226 ] . V_231 ) {
V_225 -> V_230 [ V_226 ] . V_231 =
F_234 ( V_2 , V_63 , V_73 ) ;
if ( ! V_225 -> V_230 [ V_226 ] . V_231 ) {
F_10 ( V_225 ) ;
F_172 ( V_223 ) ;
return - V_118 ;
}
}
V_225 -> V_230 [ V_226 ] . V_231 -> V_84 = 1 ;
}
F_169 ( & V_228 -> V_228 . V_229 ) ;
V_98 = F_192 ( & V_228 -> V_228 , V_223 ) ;
F_171 ( & V_228 -> V_228 . V_229 ) ;
F_26 ( V_98 ) ;
F_172 ( V_223 ) ;
return 0 ;
}
static int F_245 ( struct V_134 * V_155 ,
struct V_168 * V_72 ,
struct V_7 * V_8 )
{
unsigned long V_169 ;
V_8 -> V_63 = F_139 ( V_155 , V_72 ) ;
V_8 -> V_209 = F_246 ( V_155 , V_72 ) ;
V_8 -> V_136 = V_8 -> V_209 ;
V_8 -> V_157 = F_247 ( V_155 , V_72 ) ;
V_8 -> type = F_248 ( V_155 , V_72 ) ;
V_8 -> V_170 = F_249 ( V_155 , V_72 ) ;
V_8 -> V_171 = F_250 ( V_155 , V_72 ) ;
V_8 -> V_172 = F_251 ( V_155 , V_72 ) ;
V_169 = ( unsigned long ) F_117 ( V_72 ) ;
F_140 ( V_155 , V_8 -> V_73 , V_169 , V_76 ) ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 , T_2 * V_16 )
{
struct V_5 * V_6 ;
int V_98 ;
F_2 ( & V_83 ) ;
V_6 = V_2 -> V_3 -> V_6 -> V_88 ;
while ( V_6 ) {
if ( ! memcmp ( V_6 -> V_16 , V_16 , V_76 ) ) {
V_98 = 0 ;
goto V_119;
}
V_6 = V_6 -> V_88 ;
}
V_6 = F_12 ( V_16 ) ;
if ( ! V_6 ) {
V_98 = - V_173 ;
goto V_119;
}
V_6 = F_46 ( V_6 ) ;
if ( F_63 ( V_6 ) ) {
V_98 = F_76 ( V_6 ) ;
goto V_119;
}
V_98 = F_61 ( V_6 , V_188 ,
V_2 -> V_3 -> V_189 ) ;
if ( V_98 )
goto V_119;
if ( ! V_6 -> V_96 ) {
F_56 ( V_6 ) ;
F_5 ( V_6 ) ;
V_98 = - V_111 ;
goto V_119;
}
V_6 -> V_88 = V_2 -> V_3 -> V_6 -> V_88 ;
V_2 -> V_3 -> V_6 -> V_88 = V_6 ;
V_119:
F_4 ( & V_83 ) ;
return V_98 ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_134 * V_155 ,
struct V_168 * V_72 )
{
struct V_7 * V_8 ;
T_3 V_63 ;
int V_98 ;
T_2 V_198 [ V_76 ] ;
T_2 V_178 [ V_76 ] ;
V_63 = F_139 ( V_155 , V_72 ) ;
F_140 ( V_155 , V_178 ,
( unsigned long ) F_117 ( V_72 ) ,
V_76 ) ;
F_140 ( V_155 , V_198 ,
( unsigned long ) F_118 ( V_72 ) ,
V_76 ) ;
if ( memcmp ( V_198 , V_2 -> V_3 -> V_16 , V_76 ) ) {
V_98 = F_252 ( V_2 , V_198 ) ;
if ( V_98 && ! F_210 ( V_2 , V_295 ) )
return V_98 ;
}
V_8 = F_123 ( V_2 , V_63 , V_178 , V_198 ) ;
if ( ! V_8 || ! V_8 -> V_39 ) {
if ( ! F_210 ( V_2 , V_295 ) )
return - V_118 ;
if ( ! V_8 ) {
F_64 ( V_347 L_19 ,
( unsigned long long ) V_63 ) ;
V_8 = F_234 ( V_2 , V_63 , V_178 ) ;
if ( ! V_8 )
return - V_67 ;
} else if ( ! V_8 -> V_79 ) {
V_2 -> V_3 -> V_6 -> V_80 ++ ;
V_8 -> V_79 = 1 ;
}
}
if ( V_8 -> V_6 != V_2 -> V_3 -> V_6 ) {
F_26 ( V_8 -> V_86 ) ;
if ( V_8 -> V_115 !=
F_254 ( V_155 , V_72 ) )
return - V_111 ;
}
F_245 ( V_155 , V_72 , V_8 ) ;
V_8 -> V_40 = V_2 -> V_3 -> V_40 ;
V_8 -> V_84 = 1 ;
if ( V_8 -> V_86 )
V_8 -> V_6 -> V_120 += V_8 -> V_136 ;
V_98 = 0 ;
return V_98 ;
}
int F_255 ( struct V_1 * V_2 )
{
struct V_61 * V_193 = & V_2 -> V_3 -> V_193 ;
struct V_134 * V_191 ;
struct V_214 * V_215 ;
struct V_162 * V_163 ;
T_2 * V_169 ;
unsigned long V_348 ;
int V_98 = 0 ;
T_5 V_216 ;
T_5 V_217 ;
T_5 V_146 = 0 ;
T_5 V_29 ;
struct V_127 V_128 ;
V_191 = F_256 ( V_2 , V_349 ,
V_350 ) ;
if ( ! V_191 )
return - V_67 ;
F_257 ( V_191 ) ;
F_258 ( V_2 -> V_234 . V_138 , V_191 , 0 ) ;
F_97 ( V_191 , V_193 , 0 , V_350 ) ;
V_217 = F_156 ( V_193 ) ;
V_169 = V_193 -> V_218 ;
V_348 = F_259 ( struct V_61 , V_218 ) ;
V_29 = 0 ;
while ( V_29 < V_217 ) {
V_215 = (struct V_214 * ) V_169 ;
F_157 ( & V_128 , V_215 ) ;
V_146 = sizeof( * V_215 ) ; V_169 += V_146 ;
V_348 += V_146 ;
V_29 += V_146 ;
if ( V_128 . type == V_164 ) {
V_163 = (struct V_162 * ) V_348 ;
V_98 = F_235 ( V_2 , & V_128 , V_191 , V_163 ) ;
if ( V_98 )
break;
V_216 = F_236 ( V_191 , V_163 ) ;
V_146 = F_159 ( V_216 ) ;
} else {
V_98 = - V_118 ;
break;
}
V_169 += V_146 ;
V_348 += V_146 ;
V_29 += V_146 ;
}
F_260 ( V_191 ) ;
return V_98 ;
}
int F_261 ( struct V_1 * V_2 )
{
struct V_131 * V_60 ;
struct V_134 * V_155 ;
struct V_127 V_128 ;
struct V_127 V_154 ;
int V_98 ;
int V_133 ;
V_2 = V_2 -> V_3 -> V_165 ;
V_60 = F_78 () ;
if ( ! V_60 )
return - V_67 ;
V_128 . V_138 = V_166 ;
V_128 . V_139 = 0 ;
V_128 . type = 0 ;
V_30:
V_98 = F_79 ( NULL , V_2 , & V_128 , V_60 , 0 , 0 ) ;
if ( V_98 < 0 )
goto error;
while ( 1 ) {
V_155 = V_60 -> V_141 [ 0 ] ;
V_133 = V_60 -> V_142 [ 0 ] ;
if ( V_133 >= F_81 ( V_155 ) ) {
V_98 = F_82 ( V_2 , V_60 ) ;
if ( V_98 == 0 )
continue;
if ( V_98 < 0 )
goto error;
break;
}
F_83 ( V_155 , & V_154 , V_133 ) ;
if ( V_128 . V_138 == V_166 ) {
if ( V_154 . V_138 != V_166 )
break;
if ( V_154 . type == V_167 ) {
struct V_168 * V_72 ;
V_72 = F_85 ( V_155 , V_133 ,
struct V_168 ) ;
V_98 = F_253 ( V_2 , V_155 , V_72 ) ;
if ( V_98 )
goto error;
}
} else if ( V_154 . type == V_164 ) {
struct V_162 * V_163 ;
V_163 = F_85 ( V_155 , V_133 , struct V_162 ) ;
V_98 = F_235 ( V_2 , & V_154 , V_155 , V_163 ) ;
if ( V_98 )
goto error;
}
V_60 -> V_142 [ 0 ] ++ ;
}
if ( V_128 . V_138 == V_166 ) {
V_128 . V_138 = 0 ;
F_138 ( V_60 ) ;
goto V_30;
}
V_98 = 0 ;
error:
F_87 ( V_60 ) ;
return V_98 ;
}
