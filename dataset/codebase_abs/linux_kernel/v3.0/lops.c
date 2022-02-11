static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( ! V_7 -> V_8 ) ;
F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) )
F_5 ( V_2 , 0 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( V_2 , V_4 ) ;
V_6 = V_4 -> V_9 ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 )
F_9 ( & V_6 -> V_12 , & V_6 -> V_11 -> V_13 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_11 ( V_4 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_6 , 1 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
F_2 ( ! F_6 ( V_4 ) ) ;
F_2 ( ! F_15 ( V_4 ) ) ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 ) {
F_19 ( & V_6 -> V_12 ) ;
F_20 ( V_4 ) ;
} else {
struct V_17 * V_18 = V_6 -> V_19 ;
F_21 ( & V_6 -> V_20 , & V_18 -> V_21 ) ;
F_12 ( & V_18 -> V_22 ) ;
}
V_6 -> V_11 = V_16 ;
F_21 ( & V_6 -> V_12 , & V_16 -> V_23 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_22 ( V_24 , & V_6 -> V_19 -> V_25 ) ;
F_13 ( V_6 , 0 ) ;
F_23 ( V_4 ) ;
F_24 ( & V_2 -> V_14 ) ;
}
static inline struct V_26 * F_25 ( struct V_3 * V_4 )
{
return (struct V_26 * ) V_4 -> V_27 ;
}
static inline T_1 * F_26 ( struct V_3 * V_4 )
{
struct V_26 * V_28 = F_25 ( V_4 ) ;
return ( V_29 T_1 * ) ( V_28 + 1 ) ;
}
static inline T_1 * F_27 ( struct V_3 * V_4 )
{
return ( V_29 T_1 * ) ( V_4 -> V_27 + V_4 -> V_30 ) ;
}
static struct V_3 * F_28 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_3 * V_4 = F_29 ( V_2 ) ;
struct V_26 * V_28 = F_25 ( V_4 ) ;
V_28 -> V_32 . V_33 = F_30 ( V_34 ) ;
V_28 -> V_32 . V_35 = F_30 ( V_36 ) ;
V_28 -> V_32 . V_37 = F_30 ( V_38 ) ;
V_28 -> V_31 = F_30 ( V_31 ) ;
V_28 -> V_39 = 0 ;
V_28 -> V_40 = 0 ;
V_28 -> V_41 = 0 ;
memset ( V_28 -> V_42 , 0 , sizeof( V_28 -> V_42 ) ) ;
return V_4 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_5 * V_6 = F_32 ( V_44 , struct V_5 , V_45 ) ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
F_16 ( V_6 -> V_50 ) ;
F_33 ( V_2 ) ;
if ( ! F_34 ( & V_6 -> V_51 ) )
goto V_52;
V_49 = V_7 -> V_8 ;
V_49 -> V_53 = 1 ;
V_49 -> V_54 ++ ;
F_21 ( & V_6 -> V_51 , & V_49 -> V_55 ) ;
if ( ! F_34 ( & V_44 -> V_56 ) )
goto V_52;
F_35 ( V_24 , & V_6 -> V_19 -> V_25 ) ;
F_35 ( V_57 , & V_6 -> V_19 -> V_25 ) ;
F_36 ( V_2 , V_6 -> V_50 ) ;
F_1 ( V_2 , V_6 -> V_50 ) ;
V_47 = (struct V_46 * ) V_6 -> V_50 -> V_27 ;
V_47 -> V_58 = F_37 ( 0 ) ;
V_47 -> V_59 = F_30 ( V_2 -> V_60 -> V_61 ) ;
V_2 -> V_62 ++ ;
F_21 ( & V_44 -> V_56 , & V_2 -> V_63 ) ;
V_49 -> V_64 ++ ;
V_52:
F_38 ( V_2 ) ;
F_23 ( V_6 -> V_50 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_26 * V_28 ;
struct V_5 * V_65 = NULL , * V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned V_70 ;
T_1 * V_71 ;
V_68 = F_40 ( V_2 ) ;
F_33 ( V_2 ) ;
V_67 = V_2 -> V_62 ;
V_65 = V_66 = F_41 ( V_65 , & V_2 -> V_63 , V_45 . V_56 ) ;
while( V_67 ) {
V_69 = V_67 ;
if ( V_67 > V_68 )
V_69 = V_68 ;
F_38 ( V_2 ) ;
V_4 = F_28 ( V_2 , V_72 ) ;
F_33 ( V_2 ) ;
V_28 = F_25 ( V_4 ) ;
V_71 = F_26 ( V_4 ) ;
V_28 -> V_39 = F_30 ( V_69 + 1 ) ;
V_28 -> V_40 = F_30 ( V_69 ) ;
V_70 = 0 ;
F_42 (bd1, &sdp->sd_log_le_buf,
bd_le.le_list) {
* V_71 ++ = F_37 ( V_65 -> V_50 -> V_73 ) ;
if ( ++ V_70 >= V_69 )
break;
}
F_38 ( V_2 ) ;
F_43 ( V_74 , V_4 ) ;
F_33 ( V_2 ) ;
V_70 = 0 ;
F_42 (bd2, &sdp->sd_log_le_buf,
bd_le.le_list) {
F_11 ( V_66 -> V_50 ) ;
F_38 ( V_2 ) ;
F_16 ( V_66 -> V_50 ) ;
V_4 = F_44 ( V_2 , V_66 -> V_50 ) ;
F_43 ( V_74 , V_4 ) ;
F_33 ( V_2 ) ;
if ( ++ V_70 >= V_69 )
break;
}
F_2 ( V_67 < V_69 ) ;
V_67 -= V_69 ;
}
F_38 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_75 * V_76 = & V_2 -> V_63 ;
struct V_5 * V_6 ;
while ( ! F_34 ( V_76 ) ) {
V_6 = F_46 ( V_76 -> V_77 , struct V_5 , V_45 . V_56 ) ;
F_47 ( & V_6 -> V_45 . V_56 ) ;
V_2 -> V_62 -- ;
F_14 ( V_2 , V_6 -> V_50 , V_16 ) ;
}
F_48 ( V_2 , ! V_2 -> V_62 ) ;
}
static void F_49 ( struct V_78 * V_79 ,
struct V_80 * V_76 , int V_81 )
{
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
if ( V_81 != 0 )
return;
V_2 -> V_83 = 0 ;
V_2 -> V_84 = 0 ;
}
static int F_51 ( struct V_78 * V_79 , unsigned int V_85 ,
struct V_26 * V_28 , T_1 * V_71 ,
int V_81 )
{
struct V_86 * V_87 = F_52 ( V_79 -> V_82 ) ;
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
struct V_17 * V_18 = V_87 -> V_88 ;
unsigned int V_89 = F_53 ( V_28 -> V_40 ) ;
struct V_3 * V_90 , * V_91 ;
T_3 V_92 ;
int error = 0 ;
if ( V_81 != 1 || F_53 ( V_28 -> V_31 ) != V_72 )
return 0 ;
F_54 ( V_2 , & V_85 ) ;
for (; V_89 ; F_54 ( V_2 , & V_85 ) , V_89 -- ) {
V_92 = F_55 ( * V_71 ++ ) ;
V_2 -> V_83 ++ ;
if ( F_56 ( V_2 , V_92 , V_85 ) )
continue;
error = F_57 ( V_79 , V_85 , & V_90 ) ;
if ( error )
return error ;
V_91 = F_58 ( V_18 , V_92 ) ;
memcpy ( V_91 -> V_27 , V_90 -> V_27 , V_90 -> V_30 ) ;
if ( F_36 ( V_2 , V_91 ) )
error = - V_93 ;
else
F_17 ( V_91 ) ;
F_20 ( V_90 ) ;
F_20 ( V_91 ) ;
if ( error )
break;
V_2 -> V_84 ++ ;
}
return error ;
}
static void F_59 ( struct V_78 * V_79 , int error , int V_81 )
{
struct V_86 * V_87 = F_52 ( V_79 -> V_82 ) ;
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
if ( error ) {
F_60 ( V_87 -> V_88 ) ;
return;
}
if ( V_81 != 1 )
return;
F_60 ( V_87 -> V_88 ) ;
F_61 ( V_2 , L_1 ,
V_79 -> V_61 , V_2 -> V_84 , V_2 -> V_83 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_5 * V_6 = F_32 ( V_44 , struct V_5 , V_45 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
struct V_48 * V_49 ;
V_49 = V_7 -> V_8 ;
V_49 -> V_53 = 1 ;
V_49 -> V_94 ++ ;
V_2 -> V_95 ++ ;
F_12 ( & V_18 -> V_96 ) ;
F_35 ( V_24 , & V_18 -> V_25 ) ;
F_21 ( & V_44 -> V_56 , & V_2 -> V_97 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_26 * V_28 ;
struct V_46 * V_47 ;
struct V_3 * V_4 ;
unsigned int V_98 ;
struct V_75 * V_76 = & V_2 -> V_97 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_95 )
return;
V_4 = F_28 ( V_2 , V_99 ) ;
V_28 = F_25 ( V_4 ) ;
V_28 -> V_39 = F_30 ( F_64 ( V_2 , V_2 -> V_95 ,
sizeof( T_3 ) ) ) ;
V_28 -> V_40 = F_30 ( V_2 -> V_95 ) ;
V_98 = sizeof( struct V_26 ) ;
F_65 (bd, head, bd_le.le_list) {
V_2 -> V_95 -- ;
if ( V_98 + sizeof( T_3 ) > V_2 -> V_100 . V_101 ) {
F_43 ( V_74 , V_4 ) ;
V_4 = F_29 ( V_2 ) ;
V_47 = (struct V_46 * ) V_4 -> V_27 ;
V_47 -> V_33 = F_30 ( V_34 ) ;
V_47 -> V_35 = F_30 ( V_102 ) ;
V_47 -> V_37 = F_30 ( V_103 ) ;
V_98 = sizeof( struct V_46 ) ;
}
* ( T_1 * ) ( V_4 -> V_27 + V_98 ) = F_37 ( V_6 -> V_104 ) ;
V_98 += sizeof( T_3 ) ;
}
F_5 ( V_2 , ! V_2 -> V_95 ) ;
F_43 ( V_74 , V_4 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_75 * V_76 = & V_2 -> V_97 ;
struct V_5 * V_6 ;
struct V_17 * V_18 ;
while ( ! F_34 ( V_76 ) ) {
V_6 = F_46 ( V_76 -> V_77 , struct V_5 , V_45 . V_56 ) ;
F_47 ( & V_6 -> V_45 . V_56 ) ;
V_18 = V_6 -> V_19 ;
F_24 ( & V_18 -> V_96 ) ;
F_22 ( V_24 , & V_18 -> V_25 ) ;
F_67 ( V_105 , V_6 ) ;
}
}
static void F_68 ( struct V_78 * V_79 ,
struct V_80 * V_76 , int V_81 )
{
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
if ( V_81 != 0 )
return;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = V_76 -> V_108 ;
}
static int F_69 ( struct V_78 * V_79 , unsigned int V_85 ,
struct V_26 * V_28 , T_1 * V_71 ,
int V_81 )
{
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
unsigned int V_89 = F_53 ( V_28 -> V_39 ) ;
unsigned int V_109 = F_53 ( V_28 -> V_40 ) ;
struct V_3 * V_4 ;
unsigned int V_98 ;
T_3 V_92 ;
int V_110 = 1 ;
int error ;
if ( V_81 != 0 || F_53 ( V_28 -> V_31 ) != V_99 )
return 0 ;
V_98 = sizeof( struct V_26 ) ;
for (; V_89 ; F_54 ( V_2 , & V_85 ) , V_89 -- ) {
error = F_57 ( V_79 , V_85 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_110 )
F_70 ( V_2 , V_4 , V_102 ) ;
while ( V_98 + sizeof( T_3 ) <= V_2 -> V_100 . V_101 ) {
V_92 = F_55 ( * ( T_1 * ) ( V_4 -> V_27 + V_98 ) ) ;
error = F_71 ( V_2 , V_92 , V_85 ) ;
if ( error < 0 ) {
F_20 ( V_4 ) ;
return error ;
}
else if ( error )
V_2 -> V_106 ++ ;
if ( ! -- V_109 )
break;
V_98 += sizeof( T_3 ) ;
}
F_20 ( V_4 ) ;
V_98 = sizeof( struct V_46 ) ;
V_110 = 0 ;
}
return 0 ;
}
static void F_72 ( struct V_78 * V_79 , int error , int V_81 )
{
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
if ( error ) {
F_73 ( V_2 ) ;
return;
}
if ( V_81 != 1 )
return;
F_61 ( V_2 , L_2 ,
V_79 -> V_61 , V_2 -> V_106 ) ;
F_73 ( V_2 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_111 * V_112 ;
struct V_48 * V_49 = V_7 -> V_8 ;
V_49 -> V_53 = 1 ;
V_112 = F_32 ( V_44 , struct V_111 , V_113 ) ;
F_33 ( V_2 ) ;
if ( ! F_34 ( & V_44 -> V_56 ) ) {
F_38 ( V_2 ) ;
return;
}
F_75 ( V_112 ) ;
V_2 -> V_114 ++ ;
F_21 ( & V_44 -> V_56 , & V_2 -> V_115 ) ;
F_38 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_75 * V_76 = & V_2 -> V_115 ;
struct V_111 * V_112 ;
while ( ! F_34 ( V_76 ) ) {
V_112 = F_46 ( V_76 -> V_77 , struct V_111 , V_113 . V_56 ) ;
F_47 ( & V_112 -> V_113 . V_56 ) ;
V_2 -> V_114 -- ;
F_77 ( V_112 ) ;
F_78 ( V_112 ) ;
}
F_48 ( V_2 , ! V_2 -> V_114 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_5 * V_6 = F_32 ( V_44 , struct V_5 , V_45 ) ;
struct V_48 * V_49 = V_7 -> V_8 ;
struct V_116 * V_117 = V_6 -> V_50 -> V_118 -> V_117 ;
struct V_86 * V_87 = F_52 ( V_117 -> V_119 ) ;
F_16 ( V_6 -> V_50 ) ;
F_33 ( V_2 ) ;
if ( V_49 ) {
if ( ! F_34 ( & V_6 -> V_51 ) )
goto V_52;
V_49 -> V_53 = 1 ;
if ( F_80 ( V_87 ) ) {
V_49 -> V_54 ++ ;
F_21 ( & V_6 -> V_51 , & V_49 -> V_55 ) ;
}
}
if ( ! F_34 ( & V_44 -> V_56 ) )
goto V_52;
F_35 ( V_24 , & V_6 -> V_19 -> V_25 ) ;
F_35 ( V_57 , & V_6 -> V_19 -> V_25 ) ;
if ( F_80 ( V_87 ) ) {
F_1 ( V_2 , V_6 -> V_50 ) ;
V_49 -> V_120 ++ ;
V_2 -> V_121 ++ ;
F_81 ( & V_44 -> V_56 , & V_2 -> V_122 ) ;
} else {
F_81 ( & V_44 -> V_56 , & V_2 -> V_123 ) ;
}
V_52:
F_38 ( V_2 ) ;
F_23 ( V_6 -> V_50 ) ;
}
static void F_82 ( struct V_3 * V_4 )
{
void * V_124 ;
T_4 * V_71 ;
F_83 ( V_4 ) ;
V_124 = F_84 ( V_4 -> V_118 , V_125 ) ;
V_71 = V_124 + F_85 ( V_4 ) ;
if ( * V_71 == F_30 ( V_34 ) )
F_86 ( V_4 ) ;
F_87 ( V_124 , V_125 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_75 * V_126 , struct V_75 * V_127 ,
unsigned int V_70 )
{
struct V_3 * V_128 ;
struct V_26 * V_28 ;
struct V_5 * V_6 ;
T_1 * V_71 ;
if ( ! V_4 )
return;
V_28 = F_25 ( V_4 ) ;
V_28 -> V_39 = F_30 ( V_70 + 1 ) ;
V_28 -> V_40 = F_30 ( V_70 ) ;
V_71 = F_26 ( V_4 ) ;
F_11 ( V_4 ) ;
F_43 ( V_74 , V_4 ) ;
F_33 ( V_2 ) ;
while( ! F_34 ( V_126 ) ) {
V_6 = F_46 ( V_126 -> V_77 , struct V_5 , V_45 . V_56 ) ;
F_89 ( & V_6 -> V_45 . V_56 , V_127 ) ;
F_11 ( V_6 -> V_50 ) ;
while ( F_55 ( * V_71 ) != V_6 -> V_50 -> V_73 ) {
F_90 ( V_2 ) ;
V_71 += 2 ;
}
F_38 ( V_2 ) ;
F_16 ( V_6 -> V_50 ) ;
if ( F_91 ( V_6 -> V_50 ) ) {
void * V_124 ;
V_128 = F_29 ( V_2 ) ;
V_124 = F_84 ( V_6 -> V_50 -> V_118 , V_125 ) ;
memcpy ( V_128 -> V_27 , V_124 + F_85 ( V_6 -> V_50 ) ,
V_128 -> V_30 ) ;
F_87 ( V_124 , V_125 ) ;
* ( T_4 * ) V_128 -> V_27 = 0 ;
F_83 ( V_6 -> V_50 ) ;
F_23 ( V_6 -> V_50 ) ;
F_20 ( V_6 -> V_50 ) ;
} else {
V_128 = F_44 ( V_2 , V_6 -> V_50 ) ;
}
F_43 ( V_74 , V_128 ) ;
F_33 ( V_2 ) ;
V_71 += 2 ;
}
F_38 ( V_2 ) ;
F_20 ( V_4 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = NULL ;
struct V_3 * V_4 = NULL ;
unsigned int V_70 = 0 ;
T_1 * V_71 = NULL , * V_129 = NULL ;
F_93 ( V_130 ) ;
F_93 ( V_131 ) ;
F_33 ( V_2 ) ;
while ( ! F_34 ( & V_2 -> V_122 ) ) {
if ( V_71 == V_129 ) {
F_38 ( V_2 ) ;
F_88 ( V_2 , V_4 , & V_131 , & V_130 , V_70 ) ;
V_70 = 0 ;
V_4 = F_28 ( V_2 , V_132 ) ;
V_71 = F_26 ( V_4 ) ;
V_129 = F_27 ( V_4 ) - 1 ;
F_33 ( V_2 ) ;
continue;
}
V_6 = F_46 ( V_2 -> V_122 . V_77 , struct V_5 , V_45 . V_56 ) ;
F_89 ( & V_6 -> V_45 . V_56 , & V_131 ) ;
F_82 ( V_6 -> V_50 ) ;
* V_71 ++ = F_37 ( V_6 -> V_50 -> V_73 ) ;
* V_71 ++ = F_37 ( F_91 ( V_4 ) ? 1 : 0 ) ;
V_70 ++ ;
}
F_38 ( V_2 ) ;
F_88 ( V_2 , V_4 , & V_131 , & V_130 , V_70 ) ;
F_33 ( V_2 ) ;
F_94 ( & V_130 , & V_2 -> V_122 ) ;
F_38 ( V_2 ) ;
}
static int F_95 ( struct V_78 * V_79 , unsigned int V_85 ,
struct V_26 * V_28 ,
T_1 * V_71 , int V_81 )
{
struct V_86 * V_87 = F_52 ( V_79 -> V_82 ) ;
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
struct V_17 * V_18 = V_87 -> V_88 ;
unsigned int V_89 = F_53 ( V_28 -> V_40 ) ;
struct V_3 * V_90 , * V_91 ;
T_3 V_92 ;
T_3 V_133 ;
int error = 0 ;
if ( V_81 != 1 || F_53 ( V_28 -> V_31 ) != V_132 )
return 0 ;
F_54 ( V_2 , & V_85 ) ;
for (; V_89 ; F_54 ( V_2 , & V_85 ) , V_89 -- ) {
V_92 = F_55 ( * V_71 ++ ) ;
V_133 = F_55 ( * V_71 ++ ) ;
V_2 -> V_83 ++ ;
if ( F_56 ( V_2 , V_92 , V_85 ) )
continue;
error = F_57 ( V_79 , V_85 , & V_90 ) ;
if ( error )
return error ;
V_91 = F_58 ( V_18 , V_92 ) ;
memcpy ( V_91 -> V_27 , V_90 -> V_27 , V_90 -> V_30 ) ;
if ( V_133 ) {
T_4 * V_134 = ( T_4 * ) V_91 -> V_27 ;
* V_134 = F_30 ( V_34 ) ;
}
F_17 ( V_91 ) ;
F_20 ( V_90 ) ;
F_20 ( V_91 ) ;
if ( error )
break;
V_2 -> V_84 ++ ;
}
return error ;
}
static void F_96 ( struct V_78 * V_79 , int error , int V_81 )
{
struct V_86 * V_87 = F_52 ( V_79 -> V_82 ) ;
struct V_1 * V_2 = F_50 ( V_79 -> V_82 ) ;
if ( error ) {
F_60 ( V_87 -> V_88 ) ;
return;
}
if ( V_81 != 1 )
return;
F_60 ( V_87 -> V_88 ) ;
F_61 ( V_2 , L_3 ,
V_79 -> V_61 , V_2 -> V_84 , V_2 -> V_83 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_75 * V_76 = & V_2 -> V_122 ;
struct V_5 * V_6 ;
while ( ! F_34 ( V_76 ) ) {
V_6 = F_46 ( V_76 -> V_77 , struct V_5 , V_45 . V_56 ) ;
F_47 ( & V_6 -> V_45 . V_56 ) ;
V_2 -> V_121 -- ;
F_14 ( V_2 , V_6 -> V_50 , V_16 ) ;
}
F_48 ( V_2 , ! V_2 -> V_121 ) ;
}
