static bool F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_3 V_4 ;
T_3 V_5 = 256 * 1024 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_3 = NULL ;
V_4 = F_3 ( V_2 -> V_8 , 0 ) ;
V_3 = F_4 ( V_4 , V_5 ) ;
if ( ! V_3 ) {
return false ;
}
if ( V_5 == 0 || V_3 [ 0 ] != 0x55 || V_3 [ 1 ] != 0xaa ) {
F_5 ( V_3 ) ;
return false ;
}
V_2 -> V_3 = F_6 ( V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
F_5 ( V_3 ) ;
return false ;
}
F_7 ( V_2 -> V_3 , V_3 , V_5 ) ;
F_5 ( V_3 ) ;
return true ;
}
static bool F_8 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_9 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
if ( V_5 == 0 || V_3 [ 0 ] != 0x55 || V_3 [ 1 ] != 0xaa ) {
F_10 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
V_2 -> V_3 = F_11 ( V_3 , V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
F_10 ( V_2 -> V_8 , V_3 ) ;
return false ;
}
F_10 ( V_2 -> V_8 , V_3 ) ;
return true ;
}
static bool F_12 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_4 V_5 ;
V_2 -> V_3 = NULL ;
V_3 = F_13 ( V_2 -> V_8 , & V_5 ) ;
if ( ! V_3 ) {
return false ;
}
if ( V_5 == 0 || V_3 [ 0 ] != 0x55 || V_3 [ 1 ] != 0xaa ) {
return false ;
}
V_2 -> V_3 = F_11 ( V_3 , V_5 , V_9 ) ;
if ( V_2 -> V_3 == NULL ) {
return false ;
}
return true ;
}
static int F_14 ( T_5 V_10 , T_1 * V_3 ,
int V_11 , int V_12 )
{
T_6 V_13 ;
union V_14 V_15 [ 2 ] , * V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 = { V_21 , NULL } ;
V_18 . V_22 = 2 ;
V_18 . V_23 = & V_15 [ 0 ] ;
V_15 [ 0 ] . type = V_24 ;
V_15 [ 0 ] . integer . V_25 = V_11 ;
V_15 [ 1 ] . type = V_24 ;
V_15 [ 1 ] . integer . V_25 = V_12 ;
V_13 = F_15 ( V_10 , NULL , & V_18 , & V_20 ) ;
if ( F_16 ( V_13 ) ) {
F_17 ( L_1 , F_18 ( V_13 ) ) ;
return - V_26 ;
}
V_16 = (union V_14 * ) V_20 . V_23 ;
memcpy ( V_3 + V_11 , V_16 -> V_20 . V_23 , V_16 -> V_20 . V_27 ) ;
V_12 = V_16 -> V_20 . V_27 ;
F_19 ( V_20 . V_23 ) ;
return V_12 ;
}
static bool F_20 ( struct V_1 * V_2 )
{
int V_28 ;
int V_5 = 256 * 1024 ;
int V_29 ;
struct V_30 * V_8 = NULL ;
T_5 V_31 , V_10 ;
T_6 V_13 ;
bool V_32 = false ;
if ( V_2 -> V_6 & V_7 )
return false ;
while ( ( V_8 = F_21 ( V_33 << 8 , V_8 ) ) != NULL ) {
V_31 = F_22 ( & V_8 -> V_34 ) ;
if ( ! V_31 )
continue;
V_13 = F_23 ( V_31 , L_2 , & V_10 ) ;
if ( ! F_16 ( V_13 ) ) {
V_32 = true ;
break;
}
}
if ( ! V_32 ) {
while ( ( V_8 = F_21 ( V_35 << 8 , V_8 ) ) != NULL ) {
V_31 = F_22 ( & V_8 -> V_34 ) ;
if ( ! V_31 )
continue;
V_13 = F_23 ( V_31 , L_2 , & V_10 ) ;
if ( ! F_16 ( V_13 ) ) {
V_32 = true ;
break;
}
}
}
if ( ! V_32 )
return false ;
V_2 -> V_3 = F_6 ( V_5 , V_9 ) ;
if ( ! V_2 -> V_3 ) {
F_24 ( L_3 ) ;
return false ;
}
for ( V_29 = 0 ; V_29 < V_5 / V_36 ; V_29 ++ ) {
V_28 = F_14 ( V_10 ,
V_2 -> V_3 ,
( V_29 * V_36 ) ,
V_36 ) ;
if ( V_28 < V_36 )
break;
}
if ( V_29 == 0 || V_2 -> V_3 [ 0 ] != 0x55 || V_2 -> V_3 [ 1 ] != 0xaa ) {
F_19 ( V_2 -> V_3 ) ;
return false ;
}
return true ;
}
static inline bool F_20 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_25 ( struct V_1 * V_2 )
{
T_7 V_37 ;
T_7 V_38 ;
T_7 V_39 ;
T_7 V_40 ;
T_7 V_41 ;
bool V_42 ;
V_37 = F_26 ( V_43 ) ;
V_38 = F_26 ( V_44 ) ;
V_39 = F_26 ( V_45 ) ;
V_40 = F_26 ( V_46 ) ;
V_41 = F_26 ( V_47 ) ;
F_27 ( V_43 , ( V_37 & ~ V_48 ) ) ;
if ( ! F_28 ( V_2 ) ) {
F_27 ( V_44 ,
( V_38 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_45 ,
( V_39 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_46 ,
( V_40 & ~ V_51 ) ) ;
}
F_27 ( V_47 , V_41 | V_52 ) ;
V_42 = F_8 ( V_2 ) ;
F_27 ( V_43 , V_37 ) ;
if ( ! F_28 ( V_2 ) ) {
F_27 ( V_44 , V_38 ) ;
F_27 ( V_45 , V_39 ) ;
F_27 ( V_46 , V_40 ) ;
}
F_27 ( V_47 , V_41 ) ;
return V_42 ;
}
static bool F_29 ( struct V_1 * V_2 )
{
T_8 V_53 ;
T_8 V_37 ;
T_8 V_38 ;
T_8 V_39 ;
T_8 V_40 ;
T_8 V_41 ;
T_8 V_54 = 0 ;
T_8 V_55 ;
bool V_42 ;
V_53 = F_26 ( V_56 ) ;
V_37 = F_26 ( V_43 ) ;
V_38 = F_26 ( V_44 ) ;
V_39 = F_26 ( V_45 ) ;
V_40 = F_26 ( V_46 ) ;
V_41 = F_26 ( V_47 ) ;
F_27 ( V_56 , ( V_53 & ~ V_57 ) ) ;
F_27 ( V_43 , ( V_37 & ~ V_48 ) ) ;
F_27 ( V_44 ,
( V_38 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_45 ,
( V_39 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_46 ,
( V_40 & ~ V_51 ) ) ;
if ( V_2 -> V_58 == V_59 ) {
V_54 = F_26 ( V_60 ) ;
F_27 ( V_60 , ( V_54 |
V_61 ) ) ;
V_55 = 0 ;
while ( ! ( V_55 & V_62 ) )
V_55 = F_26 ( V_63 ) ;
F_27 ( V_47 , ( V_41 & ~ V_52 ) ) ;
} else
F_27 ( V_47 , ( V_41 | V_52 ) ) ;
V_42 = F_8 ( V_2 ) ;
if ( V_2 -> V_58 == V_59 ) {
F_27 ( V_60 , V_54 ) ;
V_55 = 0 ;
while ( ! ( V_55 & V_62 ) )
V_55 = F_26 ( V_63 ) ;
}
F_27 ( V_56 , V_53 ) ;
F_27 ( V_43 , V_37 ) ;
F_27 ( V_44 , V_38 ) ;
F_27 ( V_45 , V_39 ) ;
F_27 ( V_46 , V_40 ) ;
F_27 ( V_47 , V_41 ) ;
return V_42 ;
}
static bool F_30 ( struct V_1 * V_2 )
{
T_8 V_53 ;
T_8 V_37 ;
T_8 V_38 ;
T_8 V_39 ;
T_8 V_40 ;
T_8 V_41 ;
T_8 V_64 ;
T_8 V_65 ;
T_8 V_66 ;
T_8 V_67 ;
T_8 V_68 ;
T_8 V_69 ;
bool V_42 ;
V_53 = F_26 ( V_56 ) ;
V_37 = F_26 ( V_43 ) ;
V_38 = F_26 ( V_44 ) ;
V_39 = F_26 ( V_45 ) ;
V_40 = F_26 ( V_46 ) ;
V_41 = F_26 ( V_47 ) ;
V_64 = F_26 ( V_70 ) ;
V_65 = F_26 ( V_71 ) ;
V_66 = F_26 ( V_72 ) ;
V_67 = F_26 ( V_73 ) ;
V_68 = F_26 ( V_74 ) ;
V_69 = F_26 ( V_75 ) ;
F_27 ( V_56 , ( V_53 & ~ V_57 ) ) ;
F_27 ( V_43 , ( V_37 & ~ V_48 ) ) ;
F_27 ( V_44 ,
( V_38 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_45 ,
( V_39 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_46 ,
( V_40 & ~ V_51 ) ) ;
F_27 ( V_47 ,
( ( V_41 & ~ V_76 ) |
( 1 << V_77 ) |
V_52 ) ) ;
F_27 ( V_70 , ( V_64 & ~ V_78 ) ) ;
F_27 ( V_71 ,
( V_65 & ~ 0x400 ) ) ;
F_27 ( V_72 ,
( V_66 & ~ 0x400 ) ) ;
F_27 ( V_73 ,
( V_67 & ~ 0x400 ) ) ;
F_27 ( V_74 ,
( V_68 & ~ 0x400 ) ) ;
F_27 ( V_75 , ( V_69 | 0x400 ) ) ;
V_42 = F_8 ( V_2 ) ;
F_27 ( V_56 , V_53 ) ;
F_27 ( V_43 , V_37 ) ;
F_27 ( V_44 , V_38 ) ;
F_27 ( V_45 , V_39 ) ;
F_27 ( V_46 , V_40 ) ;
F_27 ( V_47 , V_41 ) ;
F_27 ( V_70 , V_64 ) ;
F_27 ( V_71 , V_65 ) ;
F_27 ( V_72 , V_66 ) ;
F_27 ( V_73 , V_67 ) ;
F_27 ( V_74 , V_68 ) ;
F_27 ( V_75 , V_69 ) ;
return V_42 ;
}
static bool F_31 ( struct V_1 * V_2 )
{
T_8 V_79 ;
T_8 V_53 ;
T_8 V_37 ;
T_8 V_38 ;
T_8 V_39 ;
T_8 V_40 ;
T_8 V_80 ;
T_8 V_81 ;
T_8 V_82 ;
bool V_42 ;
V_79 = F_26 ( V_83 ) ;
V_53 = F_26 ( V_56 ) ;
V_37 = F_26 ( V_84 ) ;
V_38 = F_26 ( V_44 ) ;
V_39 = F_26 ( V_45 ) ;
V_40 = F_26 ( V_46 ) ;
V_80 = F_26 ( V_85 ) ;
V_81 = F_26 ( V_86 ) ;
V_82 = F_26 ( V_87 ) ;
F_27 ( V_83 ,
( ( V_79 & ~ V_88 ) |
( 0xc << V_89 ) ) ) ;
F_27 ( V_85 , 0 ) ;
F_27 ( V_86 , 0 ) ;
F_27 ( V_87 , 0 ) ;
F_27 ( V_56 , ( V_53 & ~ V_57 ) ) ;
F_27 ( V_84 , ( V_37 & ~ V_90 ) ) ;
F_27 ( V_44 ,
( V_38 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_45 ,
( V_39 & ~ ( V_49 |
V_50 ) ) ) ;
F_27 ( V_46 ,
( V_40 & ~ V_51 ) ) ;
V_42 = F_8 ( V_2 ) ;
F_27 ( V_83 , V_79 ) ;
F_27 ( V_56 , V_53 ) ;
F_27 ( V_84 , V_37 ) ;
F_27 ( V_44 , V_38 ) ;
F_27 ( V_45 , V_39 ) ;
F_27 ( V_46 , V_40 ) ;
F_27 ( V_85 , V_80 ) ;
F_27 ( V_86 , V_81 ) ;
F_27 ( V_87 , V_82 ) ;
return V_42 ;
}
static bool F_32 ( struct V_1 * V_2 )
{
T_8 V_79 ;
T_8 V_53 ;
T_8 V_37 ;
T_8 V_91 ;
T_8 V_92 ;
T_8 V_93 ;
T_8 V_94 ;
bool V_42 ;
V_79 = F_26 ( V_83 ) ;
V_53 = F_26 ( V_56 ) ;
if ( V_2 -> V_6 & V_95 )
V_37 = F_26 ( V_84 ) ;
else
V_37 = F_26 ( V_96 ) ;
V_91 = F_26 ( V_97 ) ;
V_92 = 0 ;
V_93 = F_26 ( V_98 ) ;
V_94 = 0 ;
if ( V_2 -> V_99 -> V_8 -> V_100 == V_101 ) {
V_94 = F_26 ( V_102 ) ;
}
if ( ! ( V_2 -> V_6 & V_103 ) ) {
V_92 = F_26 ( V_104 ) ;
}
F_27 ( V_83 ,
( ( V_79 & ~ V_88 ) |
( 0xc << V_89 ) ) ) ;
F_27 ( V_56 , ( V_53 & ~ V_57 ) ) ;
if ( V_2 -> V_6 & V_95 )
F_27 ( V_84 , ( V_37 & ~ V_90 ) ) ;
else
F_27 ( V_96 , ( V_37 & ~ V_105 ) ) ;
F_27 ( V_97 ,
( ( V_91 & ~ V_106 ) |
( V_107 |
V_108 ) ) ) ;
if ( ! ( V_2 -> V_6 & V_103 ) ) {
F_27 ( V_104 ,
( ( V_92 & ~ V_109 ) |
V_110 ) ) ;
}
F_27 ( V_98 ,
( ( V_93 & ~ V_111 ) |
( V_112 |
V_113 ) ) ) ;
if ( V_2 -> V_99 -> V_8 -> V_100 == V_101 ) {
F_27 ( V_102 , ( V_94 & ~ V_114 ) ) ;
}
V_42 = F_8 ( V_2 ) ;
F_27 ( V_83 , V_79 ) ;
F_27 ( V_56 , V_53 ) ;
if ( V_2 -> V_6 & V_95 )
F_27 ( V_84 , V_37 ) ;
else
F_27 ( V_96 , V_37 ) ;
F_27 ( V_97 , V_91 ) ;
if ( ! ( V_2 -> V_6 & V_103 ) ) {
F_27 ( V_104 , V_92 ) ;
}
F_27 ( V_98 , V_93 ) ;
if ( V_2 -> V_99 -> V_8 -> V_100 == V_101 ) {
F_27 ( V_102 , V_94 ) ;
}
return V_42 ;
}
static bool F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 & V_7 )
return F_1 ( V_2 ) ;
else if ( V_2 -> V_58 >= V_115 )
return F_25 ( V_2 ) ;
else if ( V_2 -> V_58 >= V_116 )
return F_29 ( V_2 ) ;
else if ( V_2 -> V_58 >= V_117 )
return F_30 ( V_2 ) ;
else if ( V_2 -> V_58 >= V_118 )
return F_31 ( V_2 ) ;
else
return F_32 ( V_2 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
bool V_28 = false ;
struct V_119 * V_120 ;
T_9 V_121 ;
T_10 * V_122 ;
T_11 * V_123 ;
T_12 * V_124 ;
if ( ! F_35 ( F_36 ( L_4 , 1 , & V_120 , & V_121 ) ) )
return false ;
if ( V_121 < sizeof( T_10 ) ) {
F_24 ( L_5 ) ;
goto V_125;
}
V_122 = ( T_10 * ) V_120 ;
if ( V_122 -> V_126 + sizeof( T_12 ) > V_121 ) {
F_24 ( L_6 ) ;
goto V_125;
}
V_123 = ( T_11 * ) ( ( char * ) V_120 + V_122 -> V_126 ) ;
V_124 = & V_123 -> V_127 ;
F_37 ( L_7 ,
V_124 -> V_128 , V_124 -> V_129 , V_124 -> V_130 ,
V_124 -> V_131 , V_124 -> V_132 , V_124 -> V_133 ) ;
if ( V_124 -> V_128 != V_2 -> V_8 -> V_134 -> V_135 ||
V_124 -> V_129 != F_38 ( V_2 -> V_8 -> V_136 ) ||
V_124 -> V_130 != F_39 ( V_2 -> V_8 -> V_136 ) ||
V_124 -> V_131 != V_2 -> V_8 -> V_137 ||
V_124 -> V_132 != V_2 -> V_8 -> V_100 ) {
F_37 ( L_8 ) ;
goto V_125;
} ;
if ( V_122 -> V_126 + sizeof( T_12 ) + V_124 -> V_133 > V_121 ) {
F_24 ( L_9 ) ;
goto V_125;
}
V_2 -> V_3 = F_11 ( & V_123 -> V_138 , V_124 -> V_133 , V_9 ) ;
V_28 = ! ! V_2 -> V_3 ;
V_125:
return V_28 ;
}
static inline bool F_34 ( struct V_1 * V_2 )
{
return false ;
}
bool F_40 ( struct V_1 * V_2 )
{
bool V_42 ;
T_13 V_139 ;
V_42 = F_20 ( V_2 ) ;
if ( V_42 == false )
V_42 = F_34 ( V_2 ) ;
if ( V_42 == false )
V_42 = F_1 ( V_2 ) ;
if ( V_42 == false )
V_42 = F_8 ( V_2 ) ;
if ( V_42 == false ) {
V_42 = F_33 ( V_2 ) ;
}
if ( V_42 == false ) {
V_42 = F_12 ( V_2 ) ;
}
if ( V_42 == false || V_2 -> V_3 == NULL ) {
F_24 ( L_10 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
if ( V_2 -> V_3 [ 0 ] != 0x55 || V_2 -> V_3 [ 1 ] != 0xaa ) {
F_17 ( L_11 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
goto V_140;
}
V_139 = F_41 ( 0x18 ) ;
if ( F_42 ( V_139 + 0x14 ) != 0x0 ) {
F_37 ( L_12 ) ;
goto V_140;
}
V_2 -> V_141 = F_41 ( 0x48 ) ;
if ( ! V_2 -> V_141 ) {
goto V_140;
}
V_139 = V_2 -> V_141 + 4 ;
if ( ! memcmp ( V_2 -> V_3 + V_139 , L_13 , 4 ) ||
! memcmp ( V_2 -> V_3 + V_139 , L_14 , 4 ) ) {
V_2 -> V_142 = true ;
} else {
V_2 -> V_142 = false ;
}
F_43 ( L_15 , V_2 -> V_142 ? L_13 : L_16 ) ;
return true ;
V_140:
F_19 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return false ;
}
