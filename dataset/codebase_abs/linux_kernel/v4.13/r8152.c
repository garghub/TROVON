static
int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
int V_7 ;
void * V_8 ;
V_8 = F_2 ( V_5 , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_7 = F_3 ( V_2 -> V_11 , F_4 ( V_2 -> V_11 , 0 ) ,
V_12 , V_13 ,
V_3 , V_4 , V_8 , V_5 , 500 ) ;
memcpy ( V_6 , V_8 , V_5 ) ;
F_5 ( V_8 ) ;
return V_7 ;
}
static
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
int V_7 ;
void * V_8 ;
V_8 = F_7 ( V_6 , V_5 , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_7 = F_3 ( V_2 -> V_11 , F_8 ( V_2 -> V_11 , 0 ) ,
V_14 , V_15 ,
V_3 , V_4 , V_8 , V_5 , 500 ) ;
F_5 ( V_8 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
void * V_6 , T_1 type )
{
T_1 V_16 = 64 ;
int V_7 = 0 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( ( V_5 & 3 ) || ! V_5 || ( V_4 & 3 ) || ! V_6 )
return - V_20 ;
if ( ( V_21 ) V_4 + ( V_21 ) V_5 > 0xffff )
return - V_20 ;
while ( V_5 ) {
if ( V_5 > V_16 ) {
V_7 = F_1 ( V_2 , V_4 , type , V_16 , V_6 ) ;
if ( V_7 < 0 )
break;
V_4 += V_16 ;
V_6 += V_16 ;
V_5 -= V_16 ;
} else {
V_7 = F_1 ( V_2 , V_4 , type , V_5 , V_6 ) ;
if ( V_7 < 0 )
break;
V_4 += V_5 ;
V_6 += V_5 ;
V_5 = 0 ;
break;
}
}
if ( V_7 == - V_19 )
F_11 ( V_17 , & V_2 -> V_18 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 ,
T_1 V_5 , void * V_6 , T_1 type )
{
int V_7 ;
T_1 V_23 , V_24 , V_25 ;
T_1 V_16 = 512 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( ( V_5 & 3 ) || ! V_5 || ( V_4 & 3 ) || ! V_6 )
return - V_20 ;
if ( ( V_21 ) V_4 + ( V_21 ) V_5 > 0xffff )
return - V_20 ;
V_23 = V_22 & V_26 ;
V_24 = V_22 & V_27 ;
V_25 = V_23 | ( V_23 << 4 ) ;
V_7 = F_6 ( V_2 , V_4 , type | V_25 , 4 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
V_4 += 4 ;
V_6 += 4 ;
V_5 -= 4 ;
if ( V_5 ) {
V_5 -= 4 ;
while ( V_5 ) {
if ( V_5 > V_16 ) {
V_7 = F_6 ( V_2 , V_4 ,
type | V_29 ,
V_16 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
V_4 += V_16 ;
V_6 += V_16 ;
V_5 -= V_16 ;
} else {
V_7 = F_6 ( V_2 , V_4 ,
type | V_29 ,
V_5 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
V_4 += V_5 ;
V_6 += V_5 ;
V_5 = 0 ;
break;
}
}
V_25 = V_24 | ( V_24 >> 4 ) ;
V_7 = F_6 ( V_2 , V_4 , type | V_25 , 4 , V_6 ) ;
if ( V_7 < 0 )
goto V_28;
}
V_28:
if ( V_7 == - V_19 )
F_11 ( V_17 , & V_2 -> V_18 ) ;
return V_7 ;
}
static inline
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_9 ( V_2 , V_4 , V_5 , V_6 , V_30 ) ;
}
static inline
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_12 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_30 ) ;
}
static inline
int F_15 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_12 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_31 ) ;
}
static V_21 F_16 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
T_2 V_6 ;
F_9 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 , type ) ;
return F_17 ( V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
T_2 V_8 = F_19 ( V_6 ) ;
F_12 ( V_2 , V_4 , V_29 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_1 V_25 = V_32 ;
T_3 V_33 = V_4 & 2 ;
V_4 &= ~ 3 ;
V_25 <<= V_33 ;
F_9 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type | V_25 ) ;
V_6 = F_17 ( V_8 ) ;
V_6 >>= ( V_33 * 8 ) ;
V_6 &= 0xffff ;
return ( T_1 ) V_6 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
V_21 V_34 = 0xffff ;
T_2 V_8 ;
T_1 V_25 = V_32 ;
T_3 V_33 = V_4 & 2 ;
V_6 &= V_34 ;
if ( V_4 & 2 ) {
V_25 <<= V_33 ;
V_34 <<= ( V_33 * 8 ) ;
V_6 <<= ( V_33 * 8 ) ;
V_4 &= ~ 3 ;
}
V_8 = F_19 ( V_6 ) ;
F_12 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_3 F_22 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_33 = V_4 & 3 ;
V_4 &= ~ 3 ;
F_9 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_17 ( V_8 ) ;
V_6 >>= ( V_33 * 8 ) ;
V_6 &= 0xff ;
return ( T_3 ) V_6 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
V_21 V_34 = 0xff ;
T_2 V_8 ;
T_1 V_25 = V_35 ;
T_3 V_33 = V_4 & 3 ;
V_6 &= V_34 ;
if ( V_4 & 3 ) {
V_25 <<= V_33 ;
V_34 <<= ( V_33 * 8 ) ;
V_6 <<= ( V_33 * 8 ) ;
V_4 &= ~ 3 ;
}
V_8 = F_19 ( V_6 ) ;
F_12 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_36 )
{
T_1 V_37 , V_38 ;
V_37 = V_36 & 0xf000 ;
if ( V_37 != V_2 -> V_37 ) {
F_21 ( V_2 , V_30 , V_39 , V_37 ) ;
V_2 -> V_37 = V_37 ;
}
V_38 = ( V_36 & 0x0fff ) | 0xb000 ;
return F_20 ( V_2 , V_30 , V_38 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_6 )
{
T_1 V_37 , V_38 ;
V_37 = V_36 & 0xf000 ;
if ( V_37 != V_2 -> V_37 ) {
F_21 ( V_2 , V_30 , V_39 , V_37 ) ;
V_2 -> V_37 = V_37 ;
}
V_38 = ( V_36 & 0x0fff ) | 0xb000 ;
F_21 ( V_2 , V_30 , V_38 , V_6 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , V_21 V_40 , V_21 V_3 )
{
F_25 ( V_2 , V_41 + V_40 * 2 , V_3 ) ;
}
static inline int F_27 ( struct V_1 * V_2 , V_21 V_40 )
{
return F_24 ( V_2 , V_41 + V_40 * 2 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_6 )
{
F_25 ( V_2 , V_42 , V_36 ) ;
F_25 ( V_2 , V_43 , V_6 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_36 )
{
F_25 ( V_2 , V_42 , V_36 ) ;
return F_24 ( V_2 , V_43 ) ;
}
static int F_30 ( struct V_44 * V_45 , int V_46 , int V_47 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_7 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( V_46 != V_48 )
return - V_49 ;
V_7 = F_27 ( V_2 , V_47 ) ;
return V_7 ;
}
static
void F_32 ( struct V_44 * V_45 , int V_46 , int V_47 , int V_50 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( V_46 != V_48 )
return;
F_26 ( V_2 , V_47 , V_50 ) ;
}
static int F_33 ( struct V_44 * V_45 , void * V_51 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
struct V_52 * V_36 = V_51 ;
int V_7 = - V_53 ;
if ( ! F_34 ( V_36 -> V_54 ) )
goto V_55;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_55;
F_36 ( & V_2 -> V_57 ) ;
memcpy ( V_45 -> V_58 , V_36 -> V_54 , V_45 -> V_59 ) ;
F_23 ( V_2 , V_30 , V_60 , V_61 ) ;
F_14 ( V_2 , V_62 , V_63 , 8 , V_36 -> V_54 ) ;
F_23 ( V_2 , V_30 , V_60 , V_64 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_55:
return V_7 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_52 * V_65 )
{
T_4 V_66 ;
struct V_67 V_68 = { V_69 , NULL } ;
union V_70 * V_71 ;
int V_7 = - V_49 ;
V_21 V_72 ;
unsigned char V_73 [ 6 ] ;
V_72 = F_20 ( V_2 , V_31 , V_74 ) ;
if ( ( V_72 & V_75 ) != 0x1000 )
return - V_19 ;
V_72 = F_22 ( V_2 , V_31 , V_76 ) ;
if ( ( V_72 & V_77 ) != 1 )
return - V_19 ;
V_66 = F_40 ( NULL , L_1 , NULL , & V_68 ) ;
V_71 = (union V_70 * ) V_68 . V_78 ;
if ( ! F_41 ( V_66 ) )
return - V_19 ;
if ( V_71 -> type != V_79 || V_71 -> string . V_80 != 0x17 ) {
F_42 ( V_2 , V_81 , V_2 -> V_45 ,
L_2 ,
V_71 -> type , V_71 -> string . V_80 ) ;
goto V_82;
}
if ( strncmp ( V_71 -> string . V_78 , L_3 , 9 ) != 0 ||
strncmp ( V_71 -> string . V_78 + 0x15 , L_4 , 1 ) != 0 ) {
F_42 ( V_2 , V_81 , V_2 -> V_45 ,
L_5 ) ;
goto V_82;
}
V_7 = F_43 ( V_73 , V_71 -> string . V_78 + 9 , 6 ) ;
if ( ! ( V_7 == 0 && F_34 ( V_73 ) ) ) {
F_42 ( V_2 , V_81 , V_2 -> V_45 ,
L_6 ,
V_7 , V_73 ) ;
V_7 = - V_49 ;
goto V_82;
}
memcpy ( V_65 -> V_54 , V_73 , 6 ) ;
F_44 ( V_2 -> V_45 -> V_58 , V_65 -> V_54 ) ;
F_45 ( V_2 , V_81 , V_2 -> V_45 ,
L_7 , V_65 -> V_54 ) ;
V_82:
F_5 ( V_71 ) ;
return V_7 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_44 * V_83 = V_2 -> V_45 ;
struct V_52 V_65 ;
int V_7 ;
if ( V_2 -> V_84 == V_85 ) {
V_7 = F_13 ( V_2 , V_62 , 8 , V_65 . V_54 ) ;
} else {
V_7 = F_39 ( V_2 , & V_65 ) ;
if ( V_7 < 0 )
V_7 = F_13 ( V_2 , V_86 , 8 , V_65 . V_54 ) ;
}
if ( V_7 < 0 ) {
F_47 ( V_2 , V_81 , V_83 , L_8 ) ;
} else if ( ! F_34 ( V_65 . V_54 ) ) {
F_47 ( V_2 , V_81 , V_83 , L_9 ,
V_65 . V_54 ) ;
F_48 ( V_83 ) ;
F_44 ( V_65 . V_54 , V_83 -> V_58 ) ;
V_7 = F_33 ( V_83 , & V_65 ) ;
F_45 ( V_2 , V_81 , V_83 , L_10 ,
V_65 . V_54 ) ;
} else {
if ( V_2 -> V_84 == V_85 )
F_44 ( V_83 -> V_58 , V_65 . V_54 ) ;
else
V_7 = F_33 ( V_83 , & V_65 ) ;
}
return V_7 ;
}
static void F_49 ( struct V_87 * V_87 )
{
struct V_44 * V_45 ;
int V_66 = V_87 -> V_66 ;
struct V_88 * V_89 ;
struct V_1 * V_2 ;
V_89 = V_87 -> V_90 ;
if ( ! V_89 )
return;
V_2 = V_89 -> V_90 ;
if ( ! V_2 )
return;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
return;
V_45 = V_2 -> V_45 ;
if ( ! F_50 ( V_45 ) )
return;
F_51 ( V_2 -> V_11 ) ;
switch ( V_66 ) {
case 0 :
if ( V_87 -> V_92 < V_93 )
break;
F_52 ( & V_2 -> V_94 ) ;
F_53 ( & V_89 -> V_95 , & V_2 -> V_96 ) ;
F_54 ( & V_2 -> V_94 ) ;
F_55 ( & V_2 -> V_97 ) ;
return;
case - V_98 :
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_2 -> V_45 ) ;
return;
case - V_99 :
return;
case - V_100 :
if ( F_57 () )
F_58 ( V_45 , L_11 ) ;
break;
default:
if ( F_57 () )
F_58 ( V_45 , L_12 , V_66 ) ;
break;
}
F_59 ( V_2 , V_89 , V_101 ) ;
}
static void F_60 ( struct V_87 * V_87 )
{
struct V_102 * V_103 ;
struct V_44 * V_45 ;
struct V_104 * V_89 ;
struct V_1 * V_2 ;
int V_66 = V_87 -> V_66 ;
V_89 = V_87 -> V_90 ;
if ( ! V_89 )
return;
V_2 = V_89 -> V_90 ;
if ( ! V_2 )
return;
V_45 = V_2 -> V_45 ;
V_103 = & V_45 -> V_103 ;
if ( V_66 ) {
if ( F_57 () )
F_58 ( V_45 , L_13 , V_66 ) ;
V_103 -> V_105 += V_89 -> V_106 ;
} else {
V_103 -> V_107 += V_89 -> V_106 ;
V_103 -> V_108 += V_89 -> V_109 ;
}
F_52 ( & V_2 -> V_110 ) ;
F_53 ( & V_89 -> V_95 , & V_2 -> V_111 ) ;
F_54 ( & V_2 -> V_110 ) ;
F_61 ( V_2 -> V_56 ) ;
if ( ! F_50 ( V_45 ) )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
return;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_62 ( & V_2 -> V_112 ) )
F_55 ( & V_2 -> V_97 ) ;
}
static void F_63 ( struct V_87 * V_87 )
{
struct V_1 * V_2 ;
T_5 * V_113 ;
int V_66 = V_87 -> V_66 ;
int V_114 ;
V_2 = V_87 -> V_90 ;
if ( ! V_2 )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
return;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
switch ( V_66 ) {
case 0 :
break;
case - V_115 :
case - V_98 :
F_56 ( V_2 -> V_45 ) ;
case - V_99 :
case - V_116 :
F_45 ( V_2 , V_117 , V_2 -> V_45 ,
L_14 , V_66 ) ;
return;
case - V_118 :
F_45 ( V_2 , V_117 , V_2 -> V_45 , L_15 ) ;
goto V_119;
default:
F_45 ( V_2 , V_117 , V_2 -> V_45 , L_16 , V_66 ) ;
goto V_119;
}
V_113 = V_87 -> V_120 ;
if ( V_121 & F_64 ( V_113 [ 0 ] ) ) {
if ( ! F_50 ( V_2 -> V_45 ) ) {
F_11 ( V_122 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
}
} else {
if ( F_50 ( V_2 -> V_45 ) ) {
F_66 ( V_2 -> V_45 ) ;
F_11 ( V_122 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
}
}
V_119:
V_114 = F_67 ( V_87 , V_101 ) ;
if ( V_114 == - V_19 ) {
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_2 -> V_45 ) ;
} else if ( V_114 ) {
F_47 ( V_2 , V_117 , V_2 -> V_45 ,
L_17 , V_114 ) ;
}
}
static inline void * F_68 ( void * V_6 )
{
return ( void * ) F_69 ( ( V_124 ) V_6 , V_125 ) ;
}
static inline void * F_70 ( void * V_6 )
{
return ( void * ) F_69 ( ( V_124 ) V_6 , V_126 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
F_72 ( V_2 -> V_129 [ V_127 ] . V_87 ) ;
V_2 -> V_129 [ V_127 ] . V_87 = NULL ;
F_5 ( V_2 -> V_129 [ V_127 ] . V_68 ) ;
V_2 -> V_129 [ V_127 ] . V_68 = NULL ;
V_2 -> V_129 [ V_127 ] . V_130 = NULL ;
}
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ ) {
F_72 ( V_2 -> V_132 [ V_127 ] . V_87 ) ;
V_2 -> V_132 [ V_127 ] . V_87 = NULL ;
F_5 ( V_2 -> V_132 [ V_127 ] . V_68 ) ;
V_2 -> V_132 [ V_127 ] . V_68 = NULL ;
V_2 -> V_132 [ V_127 ] . V_130 = NULL ;
}
F_72 ( V_2 -> V_133 ) ;
V_2 -> V_133 = NULL ;
F_5 ( V_2 -> V_134 ) ;
V_2 -> V_134 = NULL ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_135 * V_56 = V_2 -> V_56 ;
struct V_136 * V_137 = V_56 -> V_138 ;
struct V_139 * V_140 = V_137 -> V_141 + 2 ;
struct V_87 * V_87 ;
int V_142 , V_127 ;
T_3 * V_73 ;
V_142 = V_45 -> V_83 . V_143 ? F_74 ( V_45 -> V_83 . V_143 ) : - 1 ;
F_75 ( & V_2 -> V_94 ) ;
F_75 ( & V_2 -> V_110 ) ;
F_76 ( & V_2 -> V_111 ) ;
F_76 ( & V_2 -> V_96 ) ;
F_77 ( & V_2 -> V_112 ) ;
F_77 ( & V_2 -> V_144 ) ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
V_73 = F_78 ( V_145 , V_9 , V_142 ) ;
if ( ! V_73 )
goto V_146;
if ( V_73 != F_68 ( V_73 ) ) {
F_5 ( V_73 ) ;
V_73 = F_78 ( V_145 + V_125 , V_9 ,
V_142 ) ;
if ( ! V_73 )
goto V_146;
}
V_87 = F_79 ( 0 , V_9 ) ;
if ( ! V_87 ) {
F_5 ( V_73 ) ;
goto V_146;
}
F_76 ( & V_2 -> V_129 [ V_127 ] . V_95 ) ;
V_2 -> V_129 [ V_127 ] . V_90 = V_2 ;
V_2 -> V_129 [ V_127 ] . V_87 = V_87 ;
V_2 -> V_129 [ V_127 ] . V_68 = V_73 ;
V_2 -> V_129 [ V_127 ] . V_130 = F_68 ( V_73 ) ;
}
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ ) {
V_73 = F_78 ( V_145 , V_9 , V_142 ) ;
if ( ! V_73 )
goto V_146;
if ( V_73 != F_70 ( V_73 ) ) {
F_5 ( V_73 ) ;
V_73 = F_78 ( V_145 + V_126 , V_9 ,
V_142 ) ;
if ( ! V_73 )
goto V_146;
}
V_87 = F_79 ( 0 , V_9 ) ;
if ( ! V_87 ) {
F_5 ( V_73 ) ;
goto V_146;
}
F_76 ( & V_2 -> V_132 [ V_127 ] . V_95 ) ;
V_2 -> V_132 [ V_127 ] . V_90 = V_2 ;
V_2 -> V_132 [ V_127 ] . V_87 = V_87 ;
V_2 -> V_132 [ V_127 ] . V_68 = V_73 ;
V_2 -> V_132 [ V_127 ] . V_130 = F_70 ( V_73 ) ;
F_53 ( & V_2 -> V_132 [ V_127 ] . V_95 , & V_2 -> V_111 ) ;
}
V_2 -> V_133 = F_79 ( 0 , V_9 ) ;
if ( ! V_2 -> V_133 )
goto V_146;
V_2 -> V_134 = F_2 ( V_147 , V_9 ) ;
if ( ! V_2 -> V_134 )
goto V_146;
V_2 -> V_148 = ( int ) V_140 -> V_149 . V_150 ;
F_80 ( V_2 -> V_133 , V_2 -> V_11 , F_81 ( V_2 -> V_11 , 3 ) ,
V_2 -> V_134 , V_147 , F_63 ,
V_2 , V_2 -> V_148 ) ;
return 0 ;
V_146:
F_71 ( V_2 ) ;
return - V_10 ;
}
static struct V_104 * F_82 ( struct V_1 * V_2 )
{
struct V_104 * V_89 = NULL ;
unsigned long V_18 ;
if ( F_83 ( & V_2 -> V_111 ) )
return NULL ;
F_84 ( & V_2 -> V_110 , V_18 ) ;
if ( ! F_83 ( & V_2 -> V_111 ) ) {
struct V_151 * V_152 ;
V_152 = V_2 -> V_111 . V_153 ;
F_85 ( V_152 ) ;
V_89 = F_86 ( V_152 , struct V_104 , V_95 ) ;
}
F_87 ( & V_2 -> V_110 , V_18 ) ;
return V_89 ;
}
static void F_88 ( struct V_1 * V_2 , struct V_154 * V_155 ,
struct V_156 * V_95 )
{
if ( F_89 ( V_155 ) -> V_157 ) {
T_6 V_158 = V_2 -> V_45 -> V_158 ;
struct V_156 V_159 ;
struct V_154 * V_160 , * V_161 ;
V_158 &= ~ ( V_162 | V_163 | V_164 ) ;
V_160 = F_90 ( V_155 , V_158 ) ;
if ( F_91 ( V_160 ) || ! V_160 )
goto V_165;
F_92 ( & V_159 ) ;
do {
V_161 = V_160 ;
V_160 = V_160 -> V_153 ;
V_161 -> V_153 = NULL ;
F_93 ( & V_159 , V_161 ) ;
} while ( V_160 );
F_94 ( & V_159 , V_95 ) ;
F_95 ( V_155 ) ;
} else if ( V_155 -> V_166 == V_167 ) {
if ( F_96 ( V_155 ) < 0 )
goto V_165;
F_97 ( V_95 , V_155 ) ;
} else {
struct V_102 * V_103 ;
V_165:
V_103 = & V_2 -> V_45 -> V_103 ;
V_103 -> V_168 ++ ;
F_95 ( V_155 ) ;
}
}
static int F_98 ( struct V_154 * V_155 )
{
const struct V_169 * V_170 ;
struct V_171 * V_172 ;
int V_7 ;
V_7 = F_99 ( V_155 , 0 ) ;
if ( V_7 )
return V_7 ;
V_170 = F_100 ( V_155 ) ;
V_172 = F_101 ( V_155 ) ;
V_172 -> V_173 = 0 ;
V_172 -> V_173 = ~ F_102 ( 0 , & V_170 -> V_174 , & V_170 -> V_175 , 0 ) ;
return V_7 ;
}
static inline void F_103 ( struct V_176 * V_149 , struct V_154 * V_155 )
{
if ( F_104 ( V_155 ) ) {
V_21 V_177 ;
V_177 = V_178 | F_105 ( F_106 ( V_155 ) ) ;
V_149 -> V_177 |= F_107 ( V_177 ) ;
}
}
static inline void F_108 ( struct V_179 * V_149 , struct V_154 * V_155 )
{
V_21 V_177 = F_109 ( V_149 -> V_177 ) ;
if ( V_177 & V_180 )
F_110 ( V_155 , F_111 ( V_181 ) ,
F_105 ( V_177 & 0xffff ) ) ;
}
static int F_112 ( struct V_1 * V_2 , struct V_176 * V_149 ,
struct V_154 * V_155 , V_21 V_182 , V_21 V_183 )
{
V_21 V_184 = F_89 ( V_155 ) -> V_157 ;
V_21 V_185 , V_177 = 0 ;
int V_7 = V_186 ;
F_113 ( V_182 > V_187 ) ;
V_185 = V_182 | V_188 | V_189 ;
if ( V_184 ) {
if ( V_183 > V_190 ) {
F_42 ( V_2 , V_191 , V_2 -> V_45 ,
L_18 ,
V_183 ) ;
V_7 = V_192 ;
goto V_193;
}
switch ( F_114 ( V_155 ) ) {
case F_111 ( V_194 ) :
V_185 |= V_195 ;
break;
case F_111 ( V_196 ) :
if ( F_98 ( V_155 ) ) {
V_7 = V_192 ;
goto V_193;
}
V_185 |= V_197 ;
break;
default:
F_113 ( 1 ) ;
break;
}
V_185 |= V_183 << V_198 ;
V_177 |= F_115 ( V_184 , V_199 ) << V_200 ;
} else if ( V_155 -> V_166 == V_167 ) {
T_3 V_201 ;
if ( V_183 > V_202 ) {
F_42 ( V_2 , V_191 , V_2 -> V_45 ,
L_19 ,
V_183 ) ;
V_7 = V_203 ;
goto V_193;
}
switch ( F_114 ( V_155 ) ) {
case F_111 ( V_194 ) :
V_177 |= V_204 ;
V_201 = F_116 ( V_155 ) -> V_205 ;
break;
case F_111 ( V_196 ) :
V_177 |= V_206 ;
V_201 = F_100 ( V_155 ) -> V_207 ;
break;
default:
V_201 = V_208 ;
break;
}
if ( V_201 == V_209 )
V_177 |= V_210 ;
else if ( V_201 == V_211 )
V_177 |= V_212 ;
else
F_113 ( 1 ) ;
V_177 |= V_183 << V_213 ;
}
V_149 -> V_177 = F_107 ( V_177 ) ;
V_149 -> V_185 = F_107 ( V_185 ) ;
V_193:
return V_7 ;
}
static int F_117 ( struct V_1 * V_2 , struct V_104 * V_89 )
{
struct V_156 V_214 , * V_112 = & V_2 -> V_112 ;
int V_215 , V_7 ;
T_3 * V_216 ;
F_92 ( & V_214 ) ;
F_52 ( & V_112 -> V_217 ) ;
F_118 ( V_112 , & V_214 ) ;
F_54 ( & V_112 -> V_217 ) ;
V_216 = V_89 -> V_130 ;
V_89 -> V_106 = 0 ;
V_89 -> V_109 = 0 ;
V_215 = V_145 ;
while ( V_215 >= V_93 + sizeof( struct V_176 ) ) {
struct V_176 * V_176 ;
struct V_154 * V_155 ;
unsigned int V_182 ;
V_21 V_218 ;
V_155 = F_119 ( & V_214 ) ;
if ( ! V_155 )
break;
V_182 = V_155 -> V_182 + sizeof( * V_176 ) ;
if ( V_182 > V_215 ) {
F_97 ( & V_214 , V_155 ) ;
break;
}
V_216 = F_70 ( V_216 ) ;
V_176 = (struct V_176 * ) V_216 ;
V_218 = ( V_21 ) F_120 ( V_155 ) ;
if ( F_112 ( V_2 , V_176 , V_155 , V_155 -> V_182 , V_218 ) ) {
F_88 ( V_2 , V_155 , & V_214 ) ;
continue;
}
F_103 ( V_176 , V_155 ) ;
V_216 += sizeof( * V_176 ) ;
V_182 = V_155 -> V_182 ;
if ( F_121 ( V_155 , 0 , V_216 , V_182 ) < 0 ) {
struct V_102 * V_103 = & V_2 -> V_45 -> V_103 ;
V_103 -> V_168 ++ ;
F_122 ( V_155 ) ;
V_216 -= sizeof( * V_176 ) ;
continue;
}
V_216 += V_182 ;
V_89 -> V_109 += V_182 ;
V_89 -> V_106 ++ ;
F_122 ( V_155 ) ;
V_215 = V_145 - ( int ) ( F_70 ( V_216 ) - V_89 -> V_130 ) ;
}
if ( ! F_62 ( & V_214 ) ) {
F_52 ( & V_112 -> V_217 ) ;
F_94 ( & V_214 , V_112 ) ;
F_54 ( & V_112 -> V_217 ) ;
}
F_123 ( V_2 -> V_45 ) ;
if ( F_124 ( V_2 -> V_45 ) &&
F_125 ( & V_2 -> V_112 ) < V_2 -> V_219 )
F_126 ( V_2 -> V_45 ) ;
F_127 ( V_2 -> V_45 ) ;
V_7 = F_128 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_220;
F_129 ( V_89 -> V_87 , V_2 -> V_11 , F_130 ( V_2 -> V_11 , 2 ) ,
V_89 -> V_130 , ( int ) ( V_216 - ( T_3 * ) V_89 -> V_130 ) ,
( V_221 ) F_60 , V_89 ) ;
V_7 = F_67 ( V_89 -> V_87 , V_101 ) ;
if ( V_7 < 0 )
F_61 ( V_2 -> V_56 ) ;
V_220:
return V_7 ;
}
static T_3 F_131 ( struct V_1 * V_2 , struct V_179 * V_179 )
{
T_3 V_222 = V_223 ;
V_21 V_177 , V_224 ;
if ( ! ( V_2 -> V_45 -> V_158 & V_225 ) )
goto V_226;
V_177 = F_109 ( V_179 -> V_177 ) ;
V_224 = F_109 ( V_179 -> V_224 ) ;
if ( V_177 & V_227 ) {
if ( V_224 & V_228 )
V_222 = V_223 ;
else if ( ( V_177 & V_229 ) && ( V_224 & V_230 ) )
V_222 = V_223 ;
else if ( ( V_177 & V_231 ) && ( V_224 & V_232 ) )
V_222 = V_223 ;
else
V_222 = V_233 ;
} else if ( V_177 & V_234 ) {
if ( ( V_177 & V_229 ) && ! ( V_224 & V_230 ) )
V_222 = V_233 ;
else if ( ( V_177 & V_231 ) && ! ( V_224 & V_232 ) )
V_222 = V_233 ;
}
V_226:
return V_222 ;
}
static int F_132 ( struct V_1 * V_2 , int V_235 )
{
unsigned long V_18 ;
struct V_151 * V_152 , * V_153 , V_144 ;
int V_7 = 0 , V_236 = 0 ;
struct V_237 * V_97 = & V_2 -> V_97 ;
if ( ! F_62 ( & V_2 -> V_144 ) ) {
while ( V_236 < V_235 ) {
struct V_154 * V_155 = F_119 ( & V_2 -> V_144 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_102 * V_103 = & V_45 -> V_103 ;
unsigned int V_238 ;
if ( ! V_155 )
break;
V_238 = V_155 -> V_182 ;
F_133 ( V_97 , V_155 ) ;
V_236 ++ ;
V_103 -> V_239 ++ ;
V_103 -> V_240 += V_238 ;
}
}
if ( F_83 ( & V_2 -> V_96 ) )
goto V_55;
F_76 ( & V_144 ) ;
F_84 ( & V_2 -> V_94 , V_18 ) ;
F_134 ( & V_2 -> V_96 , & V_144 ) ;
F_87 ( & V_2 -> V_94 , V_18 ) ;
F_135 (cursor, next, &rx_queue) {
struct V_179 * V_179 ;
struct V_88 * V_89 ;
int V_241 = 0 ;
struct V_87 * V_87 ;
T_3 * V_242 ;
F_85 ( V_152 ) ;
V_89 = F_86 ( V_152 , struct V_88 , V_95 ) ;
V_87 = V_89 -> V_87 ;
if ( V_87 -> V_92 < V_93 )
goto V_243;
V_179 = V_89 -> V_130 ;
V_242 = V_89 -> V_130 ;
V_241 += sizeof( struct V_179 ) ;
while ( V_87 -> V_92 > V_241 ) {
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_102 * V_103 = & V_45 -> V_103 ;
unsigned int V_238 ;
struct V_154 * V_155 ;
if ( F_136 ( F_125 ( & V_2 -> V_144 ) >= 1000 ) )
break;
V_238 = F_109 ( V_179 -> V_185 ) & V_244 ;
if ( V_238 < V_93 )
break;
V_241 += V_238 ;
if ( V_87 -> V_92 < V_241 )
break;
V_238 -= V_245 ;
V_242 += sizeof( struct V_179 ) ;
V_155 = F_137 ( V_97 , V_238 ) ;
if ( ! V_155 ) {
V_103 -> V_246 ++ ;
goto V_247;
}
V_155 -> V_166 = F_131 ( V_2 , V_179 ) ;
memcpy ( V_155 -> V_6 , V_242 , V_238 ) ;
F_138 ( V_155 , V_238 ) ;
V_155 -> V_205 = F_139 ( V_155 , V_45 ) ;
F_108 ( V_179 , V_155 ) ;
if ( V_236 < V_235 ) {
F_133 ( V_97 , V_155 ) ;
V_236 ++ ;
V_103 -> V_239 ++ ;
V_103 -> V_240 += V_238 ;
} else {
F_93 ( & V_2 -> V_144 , V_155 ) ;
}
V_247:
V_242 = F_68 ( V_242 + V_238 + V_245 ) ;
V_179 = (struct V_179 * ) V_242 ;
V_241 = ( int ) ( V_242 - ( T_3 * ) V_89 -> V_130 ) ;
V_241 += sizeof( struct V_179 ) ;
}
V_243:
if ( ! V_7 ) {
V_7 = F_59 ( V_2 , V_89 , V_101 ) ;
} else {
V_87 -> V_92 = 0 ;
F_53 ( & V_89 -> V_95 , V_153 ) ;
}
}
if ( ! F_83 ( & V_144 ) ) {
F_84 ( & V_2 -> V_94 , V_18 ) ;
F_140 ( & V_144 , & V_2 -> V_96 ) ;
F_87 ( & V_2 -> V_94 , V_18 ) ;
}
V_55:
return V_236 ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_114 ;
do {
struct V_104 * V_89 ;
if ( F_62 ( & V_2 -> V_112 ) )
break;
V_89 = F_82 ( V_2 ) ;
if ( ! V_89 )
break;
V_114 = F_117 ( V_2 , V_89 ) ;
if ( V_114 ) {
struct V_44 * V_45 = V_2 -> V_45 ;
if ( V_114 == - V_19 ) {
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_45 ) ;
} else {
struct V_102 * V_103 = & V_45 -> V_103 ;
unsigned long V_18 ;
F_42 ( V_2 , V_191 , V_45 ,
L_20 , V_114 ) ;
V_103 -> V_168 += V_89 -> V_106 ;
F_84 ( & V_2 -> V_110 , V_18 ) ;
F_53 ( & V_89 -> V_95 , & V_2 -> V_111 ) ;
F_87 ( & V_2 -> V_110 , V_18 ) ;
}
}
} while ( V_114 == 0 );
}
static void F_142 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
return;
if ( ! F_50 ( V_2 -> V_45 ) )
return;
F_143 ( V_248 , & V_2 -> V_18 ) ;
F_141 ( V_2 ) ;
}
static int F_144 ( struct V_237 * V_97 , int V_235 )
{
struct V_1 * V_2 = F_145 ( V_97 , struct V_1 , V_97 ) ;
int V_236 ;
V_236 = F_132 ( V_2 , V_235 ) ;
F_142 ( V_2 ) ;
if ( V_236 < V_235 ) {
if ( ! F_146 ( V_97 , V_236 ) )
goto V_249;
if ( ! F_83 ( & V_2 -> V_96 ) )
F_55 ( V_97 ) ;
else if ( ! F_62 ( & V_2 -> V_112 ) &&
! F_83 ( & V_2 -> V_111 ) )
F_55 ( V_97 ) ;
}
V_249:
return V_236 ;
}
static
int F_59 ( struct V_1 * V_2 , struct V_88 * V_89 , T_7 V_250 )
{
int V_7 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) ||
! F_10 ( V_91 , & V_2 -> V_18 ) || ! F_50 ( V_2 -> V_45 ) )
return 0 ;
F_129 ( V_89 -> V_87 , V_2 -> V_11 , F_147 ( V_2 -> V_11 , 1 ) ,
V_89 -> V_130 , V_145 ,
( V_221 ) F_49 , V_89 ) ;
V_7 = F_67 ( V_89 -> V_87 , V_250 ) ;
if ( V_7 == - V_19 ) {
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_2 -> V_45 ) ;
} else if ( V_7 ) {
struct V_87 * V_87 = V_89 -> V_87 ;
unsigned long V_18 ;
V_87 -> V_92 = 0 ;
F_84 ( & V_2 -> V_94 , V_18 ) ;
F_53 ( & V_89 -> V_95 , & V_2 -> V_96 ) ;
F_87 ( & V_2 -> V_94 , V_18 ) ;
F_47 ( V_2 , V_251 , V_2 -> V_45 ,
L_21 , V_89 , V_7 ) ;
F_55 ( & V_2 -> V_97 ) ;
}
return V_7 ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = & V_2 -> V_45 -> V_103 ;
struct V_156 V_214 , * V_112 = & V_2 -> V_112 ;
struct V_154 * V_155 ;
if ( F_62 ( V_112 ) )
return;
F_92 ( & V_214 ) ;
F_149 ( & V_112 -> V_217 ) ;
F_118 ( V_112 , & V_214 ) ;
F_150 ( & V_112 -> V_217 ) ;
while ( ( V_155 = F_119 ( & V_214 ) ) ) {
F_95 ( V_155 ) ;
V_103 -> V_168 ++ ;
}
}
static void F_151 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
F_42 ( V_2 , V_191 , V_45 , L_22 ) ;
F_152 ( V_2 -> V_56 ) ;
}
static void F_153 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
if ( F_50 ( V_45 ) ) {
F_11 ( V_252 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
}
}
static void F_154 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
V_21 V_253 [ 2 ] ;
T_2 V_8 [ 2 ] ;
V_21 V_72 ;
F_66 ( V_45 ) ;
V_72 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 &= ~ V_255 ;
V_72 |= V_256 | V_257 ;
if ( V_45 -> V_18 & V_258 ) {
F_155 ( V_2 , V_259 , V_45 , L_23 ) ;
V_72 |= V_260 | V_261 ;
V_253 [ 1 ] = 0xffffffff ;
V_253 [ 0 ] = 0xffffffff ;
} else if ( ( F_156 ( V_45 ) > V_262 ) ||
( V_45 -> V_18 & V_263 ) ) {
V_72 |= V_260 ;
V_253 [ 1 ] = 0xffffffff ;
V_253 [ 0 ] = 0xffffffff ;
} else {
struct V_264 * V_265 ;
V_253 [ 1 ] = 0 ;
V_253 [ 0 ] = 0 ;
F_157 (ha, netdev) {
int V_266 = F_158 ( V_267 , V_265 -> V_36 ) >> 26 ;
V_253 [ V_266 >> 5 ] |= 1 << ( V_266 & 31 ) ;
V_72 |= V_260 ;
}
}
V_8 [ 0 ] = F_19 ( F_159 ( V_253 [ 1 ] ) ) ;
V_8 [ 1 ] = F_19 ( F_159 ( V_253 [ 0 ] ) ) ;
F_14 ( V_2 , V_268 , V_29 , sizeof( V_8 ) , V_8 ) ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
F_126 ( V_45 ) ;
}
static T_6
F_160 ( struct V_154 * V_155 , struct V_44 * V_83 ,
T_6 V_158 )
{
V_21 V_184 = F_89 ( V_155 ) -> V_157 ;
int V_269 = V_184 ? V_190 : V_202 ;
int V_218 = F_120 ( V_155 ) ;
if ( ( V_184 || V_155 -> V_166 == V_167 ) && V_218 > V_269 )
V_158 &= ~ ( V_270 | V_271 ) ;
else if ( ( V_155 -> V_182 + sizeof( struct V_176 ) ) > V_145 )
V_158 &= ~ V_271 ;
return V_158 ;
}
static T_8 F_161 ( struct V_154 * V_155 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
F_162 ( V_155 ) ;
F_163 ( & V_2 -> V_112 , V_155 ) ;
if ( ! F_83 ( & V_2 -> V_111 ) ) {
if ( F_10 ( V_272 , & V_2 -> V_18 ) ) {
F_11 ( V_248 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
} else {
F_51 ( V_2 -> V_11 ) ;
F_55 ( & V_2 -> V_97 ) ;
}
} else if ( F_125 ( & V_2 -> V_112 ) > V_2 -> V_219 ) {
F_66 ( V_45 ) ;
}
return V_273 ;
}
static void F_164 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_30 , V_274 ) ;
V_72 &= ~ V_275 ;
F_21 ( V_2 , V_30 , V_274 , V_72 ) ;
V_72 |= V_275 ;
F_21 ( V_2 , V_30 , V_274 , V_72 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
int V_127 ;
F_23 ( V_2 , V_30 , V_276 , V_277 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
if ( ! ( F_22 ( V_2 , V_30 , V_276 ) & V_277 ) )
break;
F_166 ( 100 , 400 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
V_2 -> V_219 = V_145 / ( V_45 -> V_278 + V_279 + V_245 +
sizeof( struct V_176 ) ) ;
}
static inline T_3 F_168 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_30 , V_280 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_3 V_281 ;
V_281 = F_168 ( V_2 ) ;
if ( V_281 & V_282 ) {
V_72 = F_20 ( V_2 , V_30 , V_283 ) ;
V_72 |= V_284 ;
F_21 ( V_2 , V_30 , V_283 , V_72 ) ;
} else {
V_72 = F_20 ( V_2 , V_30 , V_283 ) ;
V_72 &= ~ V_284 ;
F_21 ( V_2 , V_30 , V_283 , V_72 ) ;
}
}
static void F_170 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_30 , V_286 ) ;
if ( V_285 )
V_72 |= V_287 ;
else
V_72 &= ~ V_287 ;
F_21 ( V_2 , V_30 , V_286 , V_72 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
int V_127 , V_7 = 0 ;
F_76 ( & V_2 -> V_96 ) ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
F_76 ( & V_2 -> V_129 [ V_127 ] . V_95 ) ;
V_7 = F_59 ( V_2 , & V_2 -> V_129 [ V_127 ] , V_9 ) ;
if ( V_7 )
break;
}
if ( V_7 && ++ V_127 < V_128 ) {
struct V_151 V_144 ;
unsigned long V_18 ;
F_76 ( & V_144 ) ;
do {
struct V_88 * V_89 = & V_2 -> V_129 [ V_127 ++ ] ;
struct V_87 * V_87 = V_89 -> V_87 ;
V_87 -> V_92 = 0 ;
F_53 ( & V_89 -> V_95 , & V_144 ) ;
} while ( V_127 < V_128 );
F_84 ( & V_2 -> V_94 , V_18 ) ;
F_140 ( & V_144 , & V_2 -> V_96 ) ;
F_87 ( & V_2 -> V_94 , V_18 ) ;
}
return V_7 ;
}
static int F_172 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ )
F_173 ( V_2 -> V_129 [ V_127 ] . V_87 ) ;
while ( ! F_62 ( & V_2 -> V_144 ) )
F_95 ( F_119 ( & V_2 -> V_144 ) ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
V_21 V_72 ;
F_164 ( V_2 ) ;
V_72 = F_22 ( V_2 , V_30 , V_276 ) ;
V_72 |= V_288 | V_289 ;
F_23 ( V_2 , V_30 , V_276 , V_72 ) ;
F_170 ( V_2 , false ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_167 ( V_2 ) ;
F_169 ( V_2 ) ;
return F_174 ( V_2 ) ;
}
static inline void F_176 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_31 , V_290 ,
V_291 | V_292 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
V_21 V_72 = V_2 -> V_293 / 8 ;
switch ( V_2 -> V_84 ) {
case V_294 :
case V_295 :
case V_296 :
case V_297 :
F_21 ( V_2 , V_31 , V_298 ,
V_72 ) ;
break;
case V_299 :
case V_300 :
F_21 ( V_2 , V_31 , V_298 ,
128 / 8 ) ;
F_21 ( V_2 , V_31 , V_301 ,
V_72 ) ;
F_176 ( V_2 ) ;
break;
default:
break;
}
}
static void F_178 ( struct V_1 * V_2 )
{
V_21 V_72 = V_145 - F_179 ( V_2 -> V_45 -> V_278 ) ;
switch ( V_2 -> V_84 ) {
case V_294 :
case V_295 :
case V_296 :
case V_297 :
F_21 ( V_2 , V_31 , V_302 ,
V_72 / 4 ) ;
break;
case V_299 :
case V_300 :
F_21 ( V_2 , V_31 , V_302 ,
V_72 / 8 ) ;
F_176 ( V_2 ) ;
break;
default:
F_113 ( 1 ) ;
break;
}
}
static int F_180 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_167 ( V_2 ) ;
F_169 ( V_2 ) ;
F_177 ( V_2 ) ;
F_178 ( V_2 ) ;
return F_174 ( V_2 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_148 ( V_2 ) ;
return;
}
V_72 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 &= ~ V_255 ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
F_148 ( V_2 ) ;
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ )
F_173 ( V_2 -> V_132 [ V_127 ] . V_87 ) ;
F_170 ( V_2 , true ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( ( V_72 & V_304 ) == V_304 )
break;
F_166 ( 1000 , 2000 ) ;
}
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
if ( F_20 ( V_2 , V_30 , V_305 ) & V_306 )
break;
F_166 ( 1000 , 2000 ) ;
}
F_172 ( V_2 ) ;
F_165 ( V_2 ) ;
}
static void F_182 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_31 , V_307 ) ;
if ( V_285 )
V_72 |= V_308 ;
else
V_72 &= ~ V_308 ;
F_21 ( V_2 , V_31 , V_307 , V_72 ) ;
V_72 = F_20 ( V_2 , V_31 , V_309 ) ;
V_72 &= ~ V_310 ;
F_21 ( V_2 , V_31 , V_309 , V_72 ) ;
}
static void F_183 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_30 , V_311 ) ;
if ( V_285 )
V_72 |= V_312 ;
else
V_72 &= ~ V_312 ;
F_21 ( V_2 , V_30 , V_311 , V_72 ) ;
}
static int F_184 ( struct V_44 * V_83 ,
T_6 V_158 )
{
T_6 V_313 = V_158 ^ V_83 -> V_158 ;
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_249;
F_36 ( & V_2 -> V_57 ) ;
if ( V_313 & V_314 ) {
if ( V_158 & V_314 )
F_183 ( V_2 , true ) ;
else
F_183 ( V_2 , false ) ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_7 ;
}
static V_21 F_185 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_21 V_315 = 0 ;
V_72 = F_20 ( V_2 , V_30 , V_316 ) ;
if ( V_72 & V_317 )
V_315 |= V_318 ;
V_72 = F_20 ( V_2 , V_30 , V_319 ) ;
if ( V_72 & V_320 )
V_315 |= V_321 ;
if ( V_72 & V_322 )
V_315 |= V_323 ;
if ( V_72 & V_324 )
V_315 |= V_325 ;
V_72 = F_20 ( V_2 , V_30 , V_326 ) ;
if ( V_72 & V_327 )
V_315 |= V_328 ;
return V_315 ;
}
static void F_186 ( struct V_1 * V_2 , V_21 V_315 )
{
V_21 V_72 ;
F_23 ( V_2 , V_30 , V_60 , V_61 ) ;
V_72 = F_20 ( V_2 , V_30 , V_316 ) ;
V_72 &= ~ V_317 ;
if ( V_315 & V_318 )
V_72 |= V_317 ;
F_21 ( V_2 , V_30 , V_316 , V_72 ) ;
V_72 = F_20 ( V_2 , V_30 , V_319 ) ;
V_72 &= ~ ( V_320 | V_322 | V_324 ) ;
if ( V_315 & V_321 )
V_72 |= V_320 ;
if ( V_315 & V_323 )
V_72 |= V_322 ;
if ( V_315 & V_325 )
V_72 |= V_324 ;
F_21 ( V_2 , V_30 , V_319 , V_72 ) ;
F_23 ( V_2 , V_30 , V_60 , V_64 ) ;
V_72 = F_20 ( V_2 , V_30 , V_326 ) ;
V_72 &= ~ V_327 ;
if ( V_315 & V_328 )
V_72 |= V_327 ;
F_21 ( V_2 , V_30 , V_326 , V_72 ) ;
if ( V_315 & V_329 )
F_187 ( & V_2 -> V_11 -> V_83 , true ) ;
else
F_187 ( & V_2 -> V_11 -> V_83 , false ) ;
}
static void F_188 ( struct V_1 * V_2 , bool V_285 )
{
if ( V_285 ) {
F_21 ( V_2 , V_30 , V_330 ,
V_331 ) ;
F_21 ( V_2 , V_30 , V_332 ,
V_333 ) ;
F_21 ( V_2 , V_30 , V_334 ,
V_335 | V_336 |
V_337 | V_338 ) ;
F_21 ( V_2 , V_30 , V_339 ,
V_340 | V_341 | V_342 |
V_343 | V_344 | V_345 |
V_346 ) ;
} else {
F_21 ( V_2 , V_30 , V_330 , 0 ) ;
F_21 ( V_2 , V_30 , V_332 , 0 ) ;
F_21 ( V_2 , V_30 , V_334 , 0 ) ;
F_21 ( V_2 , V_30 , V_339 , 0 ) ;
}
}
static void F_189 ( struct V_1 * V_2 , bool V_285 )
{
T_3 V_347 [ 8 ] ;
if ( V_285 )
memset ( V_347 , 0xff , sizeof( V_347 ) ) ;
else
memset ( V_347 , 0x00 , sizeof( V_347 ) ) ;
F_15 ( V_2 , V_348 , V_63 , sizeof( V_347 ) , V_347 ) ;
}
static void F_190 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_31 , V_349 ) ;
if ( V_285 )
V_72 |= V_350 ;
else
V_72 &= ~ V_350 ;
F_21 ( V_2 , V_31 , V_349 , V_72 ) ;
}
static void F_191 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_31 , V_351 ) ;
if ( V_285 )
V_72 |= V_352 ;
else
V_72 &= ~ V_352 ;
F_21 ( V_2 , V_31 , V_351 , V_72 ) ;
}
static void F_192 ( struct V_1 * V_2 , V_21 V_353 , V_21 V_354 )
{
V_21 V_72 ;
V_72 = F_16 ( V_2 , V_31 , V_355 ) ;
V_72 &= ~ V_354 ;
V_72 |= V_353 ;
F_18 ( V_2 , V_31 , V_355 , V_72 ) ;
}
static void F_193 ( struct V_1 * V_2 , bool V_285 )
{
T_1 V_6 ;
if ( V_285 ) {
F_28 ( V_2 , 0x8045 , 0 ) ;
F_28 ( V_2 , 0x804d , 0x1222 ) ;
F_28 ( V_2 , 0x805d , 0x0022 ) ;
} else {
F_28 ( V_2 , 0x8045 , 0x2444 ) ;
F_28 ( V_2 , 0x804d , 0x2444 ) ;
F_28 ( V_2 , 0x805d , 0x2444 ) ;
}
V_6 = F_29 ( V_2 , V_356 ) ;
V_6 |= V_357 ;
F_28 ( V_2 , V_356 , V_6 ) ;
F_192 ( V_2 , V_358 , 0 ) ;
}
static T_1 F_194 ( struct V_1 * V_2 , T_1 V_359 )
{
T_1 V_6 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < 500 ; V_127 ++ ) {
V_6 = F_24 ( V_2 , V_360 ) ;
V_6 &= V_361 ;
if ( V_359 ) {
if ( V_6 == V_359 )
break;
} else if ( V_6 == V_362 || V_6 == V_363 ||
V_6 == V_364 ) {
break;
}
F_195 ( 20 ) ;
}
return V_6 ;
}
static void F_196 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 = F_22 ( V_2 , V_31 , V_365 ) ;
if ( V_285 ) {
V_72 |= V_366 | V_367 | V_368 ;
F_23 ( V_2 , V_31 , V_365 , V_72 ) ;
V_72 = F_22 ( V_2 , V_31 , 0xcfff ) ;
V_72 |= F_197 ( 0 ) ;
F_23 ( V_2 , V_31 , 0xcfff , V_72 ) ;
} else {
T_1 V_6 ;
V_72 &= ~ ( V_366 | V_367 ) ;
F_23 ( V_2 , V_31 , V_365 , V_72 ) ;
V_72 = F_22 ( V_2 , V_31 , 0xcfff ) ;
V_72 &= ~ F_197 ( 0 ) ;
F_23 ( V_2 , V_31 , 0xcfff , V_72 ) ;
V_72 = F_20 ( V_2 , V_31 , V_74 ) ;
V_72 &= ~ V_369 ;
F_21 ( V_2 , V_31 , V_74 , V_72 ) ;
V_6 = F_194 ( V_2 , 0 ) ;
switch ( V_6 ) {
case V_363 :
case V_364 :
F_193 ( V_2 ,
F_10 ( V_370 , & V_2 -> V_18 ) ) ;
V_6 = F_27 ( V_2 , V_371 ) ;
V_6 &= ~ V_372 ;
V_6 |= V_373 ;
F_26 ( V_2 , V_371 , V_6 ) ;
V_6 = F_194 ( V_2 , V_362 ) ;
default:
if ( V_6 != V_362 )
F_42 ( V_2 , V_259 , V_2 -> V_45 ,
L_24 ) ;
break;
}
}
}
static void F_198 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_31 , V_365 ) ;
if ( V_285 )
V_72 |= V_374 | V_368 ;
else
V_72 &= ~ ( V_374 | V_368 ) ;
F_21 ( V_2 , V_31 , V_365 , V_72 ) ;
V_72 = F_20 ( V_2 , V_31 , V_74 ) ;
V_72 &= ~ V_369 ;
F_21 ( V_2 , V_31 , V_74 , V_72 ) ;
}
static void F_199 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_31 , V_365 ) ;
if ( V_285 )
V_72 |= V_374 | V_368 ;
else
V_72 &= ~ V_374 ;
F_21 ( V_2 , V_31 , V_365 , V_72 ) ;
V_72 = F_20 ( V_2 , V_31 , V_74 ) ;
V_72 &= ~ V_369 ;
F_21 ( V_2 , V_31 , V_74 , V_72 ) ;
}
static void F_200 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
V_72 = F_22 ( V_2 , V_30 , 0xd38a ) ;
if ( V_285 )
V_72 |= F_197 ( 0 ) ;
else
V_72 &= ~ F_197 ( 0 ) ;
F_23 ( V_2 , V_30 , 0xd38a , V_72 ) ;
V_72 = F_22 ( V_2 , V_30 , 0xd38c ) ;
V_72 &= ~ F_197 ( 0 ) ;
F_23 ( V_2 , V_30 , 0xd38c , V_72 ) ;
}
static bool F_201 ( struct V_1 * V_2 )
{
struct V_375 * V_11 = V_2 -> V_11 ;
return ( V_11 -> V_376 -> V_149 . V_377 & V_378 ) ;
}
static void F_202 ( struct V_1 * V_2 , bool V_285 )
{
if ( V_285 ) {
V_21 V_72 ;
F_186 ( V_2 , V_329 ) ;
F_23 ( V_2 , V_30 , V_60 , V_61 ) ;
V_72 = F_20 ( V_2 , V_30 , V_316 ) ;
V_72 |= V_379 ;
F_21 ( V_2 , V_30 , V_316 , V_72 ) ;
F_23 ( V_2 , V_30 , V_60 , V_64 ) ;
} else {
V_21 V_72 ;
F_186 ( V_2 , V_2 -> V_380 ) ;
F_23 ( V_2 , V_30 , V_60 , V_61 ) ;
V_72 = F_20 ( V_2 , V_30 , V_316 ) ;
V_72 &= ~ V_379 ;
F_21 ( V_2 , V_30 , V_316 , V_72 ) ;
F_23 ( V_2 , V_30 , V_60 , V_64 ) ;
}
}
static void F_203 ( struct V_1 * V_2 , bool V_285 )
{
if ( V_285 ) {
F_189 ( V_2 , false ) ;
F_191 ( V_2 , false ) ;
F_188 ( V_2 , true ) ;
F_202 ( V_2 , true ) ;
} else {
F_202 ( V_2 , false ) ;
F_188 ( V_2 , false ) ;
switch ( V_2 -> V_84 ) {
case V_294 :
case V_295 :
break;
case V_296 :
case V_297 :
default:
F_191 ( V_2 , true ) ;
break;
}
F_189 ( V_2 , true ) ;
}
}
static void F_204 ( struct V_1 * V_2 , bool V_285 )
{
if ( V_285 ) {
F_200 ( V_2 , true ) ;
F_190 ( V_2 , false ) ;
F_191 ( V_2 , false ) ;
F_202 ( V_2 , true ) ;
F_196 ( V_2 , true ) ;
} else {
F_196 ( V_2 , false ) ;
F_200 ( V_2 , false ) ;
F_202 ( V_2 , false ) ;
F_191 ( V_2 , true ) ;
F_190 ( V_2 , true ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
{
V_21 V_72 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_381 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_382 :
V_72 = F_20 ( V_2 , V_30 , V_383 ) ;
V_72 &= ~ ( V_384 | V_385 |
V_386 ) ;
F_21 ( V_2 , V_30 , V_383 , V_72 ) ;
break;
case V_299 :
case V_300 :
F_23 ( V_2 , V_30 , V_383 , 0xff ) ;
break;
default:
break;
}
F_21 ( V_2 , V_30 , V_387 , V_388 ) ;
F_21 ( V_2 , V_30 , V_389 , 0 ) ;
F_18 ( V_2 , V_30 , V_390 , 0 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_22 ( V_2 , V_31 , V_391 ) ;
V_72 &= ~ ( V_392 | V_393 ) ;
F_23 ( V_2 , V_31 , V_391 , V_72 ) ;
V_72 |= V_392 | V_393 ;
F_23 ( V_2 , V_31 , V_391 , V_72 ) ;
}
static void F_207 ( struct V_1 * V_2 , bool V_285 )
{
if ( V_285 ) {
F_25 ( V_2 , V_394 , V_395 | V_396 |
V_397 | V_398 ) ;
} else {
F_25 ( V_2 , V_394 , V_396 | V_397 |
V_398 ) ;
F_195 ( 20 ) ;
}
}
static inline void F_208 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_47 )
{
F_25 ( V_2 , V_399 , V_400 | V_83 ) ;
F_25 ( V_2 , V_401 , V_47 ) ;
F_25 ( V_2 , V_399 , V_402 | V_83 ) ;
}
static T_1 F_209 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_47 )
{
T_1 V_6 ;
F_208 ( V_2 , V_83 , V_47 ) ;
V_6 = F_24 ( V_2 , V_401 ) ;
F_25 ( V_2 , V_399 , 0x0000 ) ;
return V_6 ;
}
static void F_210 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_47 , T_1 V_6 )
{
F_208 ( V_2 , V_83 , V_47 ) ;
F_25 ( V_2 , V_401 , V_6 ) ;
F_25 ( V_2 , V_399 , 0x0000 ) ;
}
static void F_211 ( struct V_1 * V_2 , bool V_285 )
{
T_1 V_403 , V_404 , V_405 ;
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_30 , V_406 ) ;
V_403 = F_24 ( V_2 , V_407 ) & ~ V_408 ;
V_404 = F_24 ( V_2 , V_409 ) ;
V_405 = F_24 ( V_2 , V_410 ) & ~ V_411 ;
if ( V_285 ) {
V_72 |= V_412 | V_413 ;
V_403 |= V_414 | V_415 | V_416 | V_417 ;
V_403 |= F_212 ( 1 ) ;
V_404 |= V_418 | V_419 ;
V_405 |= F_213 ( 42 ) ;
} else {
V_72 &= ~ ( V_412 | V_413 ) ;
V_403 &= ~ ( V_414 | V_415 | V_416 |
V_417 ) ;
V_403 |= F_212 ( 7 ) ;
V_404 &= ~ ( V_418 | V_419 ) ;
V_405 |= F_213 ( 511 ) ;
}
F_21 ( V_2 , V_30 , V_406 , V_72 ) ;
F_25 ( V_2 , V_407 , V_403 ) ;
F_25 ( V_2 , V_409 , V_404 ) ;
F_25 ( V_2 , V_410 , V_405 ) ;
}
static void F_214 ( struct V_1 * V_2 )
{
F_211 ( V_2 , true ) ;
F_210 ( V_2 , V_420 , V_421 , V_422 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
T_1 V_423 ;
V_423 = F_27 ( V_2 , V_424 ) ;
V_423 |= V_425 | V_426 ;
F_26 ( V_2 , V_424 , V_423 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_207 ( V_2 , false ) ;
F_181 ( V_2 ) ;
F_207 ( V_2 , true ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
F_214 ( V_2 ) ;
F_207 ( V_2 , true ) ;
F_215 ( V_2 ) ;
F_11 ( V_427 , & V_2 -> V_18 ) ;
}
static void F_218 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
V_72 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 &= ~ V_255 ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
F_170 ( V_2 , true ) ;
F_205 ( V_2 ) ;
F_23 ( V_2 , V_30 , V_60 , V_64 ) ;
F_23 ( V_2 , V_30 , V_276 , 0x00 ) ;
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
V_72 &= ~ V_428 ;
F_23 ( V_2 , V_30 , V_303 , V_72 ) ;
V_72 = F_20 ( V_2 , V_30 , V_429 ) ;
V_72 &= ~ V_430 ;
F_21 ( V_2 , V_30 , V_429 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
V_72 = F_20 ( V_2 , V_30 , V_429 ) ;
V_72 |= V_432 ;
F_21 ( V_2 , V_30 , V_429 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
F_165 ( V_2 ) ;
F_18 ( V_2 , V_30 , V_433 , V_434 ) ;
if ( V_2 -> V_11 -> V_281 == V_435 ||
V_2 -> V_11 -> V_281 == V_436 ) {
F_18 ( V_2 , V_30 , V_437 ,
V_438 ) ;
F_18 ( V_2 , V_30 , V_439 ,
V_440 ) ;
} else {
F_18 ( V_2 , V_30 , V_437 ,
V_441 ) ;
F_18 ( V_2 , V_30 , V_439 ,
V_442 ) ;
}
F_18 ( V_2 , V_30 , V_443 , V_444 ) ;
F_23 ( V_2 , V_31 , V_445 , V_446 ) ;
F_18 ( V_2 , V_31 , V_447 , V_448 ) ;
F_18 ( V_2 , V_31 , V_449 ,
V_450 | V_451 ) ;
F_183 ( V_2 , V_2 -> V_45 -> V_158 & V_314 ) ;
F_21 ( V_2 , V_30 , V_452 , V_453 ) ;
V_72 = F_20 ( V_2 , V_30 , V_305 ) ;
V_72 |= V_454 ;
F_21 ( V_2 , V_30 , V_305 , V_72 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
V_72 &= ~ V_428 ;
F_23 ( V_2 , V_30 , V_303 , V_72 ) ;
F_18 ( V_2 , V_30 , V_433 , V_455 ) ;
F_18 ( V_2 , V_30 , V_437 , V_456 ) ;
F_18 ( V_2 , V_30 , V_439 , V_457 ) ;
F_181 ( V_2 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
V_72 = F_20 ( V_2 , V_30 , V_429 ) ;
V_72 |= V_432 ;
F_21 ( V_2 , V_30 , V_429 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
F_21 ( V_2 , V_30 , V_452 , V_453 ) ;
F_183 ( V_2 , true ) ;
V_72 = F_20 ( V_2 , V_30 , V_458 ) ;
V_72 |= V_459 ;
F_21 ( V_2 , V_30 , V_458 , V_72 ) ;
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
V_72 |= V_428 | V_460 ;
F_23 ( V_2 , V_30 , V_303 , V_72 ) ;
F_170 ( V_2 , false ) ;
V_72 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 |= V_257 | V_260 | V_256 ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
}
static int F_220 ( struct V_1 * V_2 , bool V_461 )
{
T_1 V_6 ;
int V_127 ;
V_6 = F_24 ( V_2 , V_462 ) ;
if ( V_461 )
V_6 |= V_463 ;
else
V_6 &= ~ V_463 ;
F_25 ( V_2 , V_462 , V_6 ) ;
for ( V_127 = 0 ; V_461 && V_127 < 5000 ; V_127 ++ ) {
F_166 ( 1000 , 2000 ) ;
if ( F_24 ( V_2 , V_464 ) & V_465 )
break;
}
if ( V_461 && ! ( F_24 ( V_2 , V_464 ) & V_465 ) ) {
F_47 ( V_2 , V_466 , V_2 -> V_45 , L_25 ) ;
F_220 ( V_2 , false ) ;
return - V_100 ;
} else {
return 0 ;
}
}
static void F_221 ( struct V_1 * V_2 , bool V_285 )
{
T_1 V_6 ;
V_6 = F_24 ( V_2 , V_467 ) ;
if ( V_285 ) {
V_6 |= V_468 ;
F_25 ( V_2 , V_467 , V_6 ) ;
} else {
int V_127 ;
V_6 &= ~ V_468 ;
F_25 ( V_2 , V_467 , V_6 ) ;
for ( V_127 = 0 ; V_127 < 20 ; V_127 ++ ) {
F_166 ( 1000 , 2000 ) ;
if ( F_20 ( V_2 , V_30 , 0xe000 ) & 0x0100 )
break;
}
}
}
static void F_222 ( struct V_1 * V_2 , bool V_285 )
{
F_221 ( V_2 , V_285 ) ;
if ( V_285 )
F_192 ( V_2 , V_469 , 0 ) ;
else
F_192 ( V_2 , 0 , V_469 ) ;
}
static void F_223 ( struct V_1 * V_2 , bool V_285 )
{
V_21 V_72 ;
T_1 V_470 ;
V_72 = F_20 ( V_2 , V_30 , V_406 ) ;
V_470 = F_24 ( V_2 , V_471 ) ;
if ( V_285 ) {
V_72 |= V_412 | V_413 ;
V_470 |= V_472 ;
} else {
V_72 &= ~ ( V_412 | V_413 ) ;
V_470 &= ~ V_472 ;
}
F_21 ( V_2 , V_30 , V_406 , V_72 ) ;
F_25 ( V_2 , V_471 , V_470 ) ;
}
static void F_224 ( struct V_1 * V_2 , bool V_285 )
{
F_223 ( V_2 , V_285 ) ;
if ( V_285 )
F_192 ( V_2 , V_473 , 0 ) ;
else
F_192 ( V_2 , 0 , V_473 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
F_215 ( V_2 ) ;
F_192 ( V_2 , V_474 , 0 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_1 V_6 ;
F_221 ( V_2 , false ) ;
F_223 ( V_2 , false ) ;
F_25 ( V_2 , V_475 , 0 ) ;
if ( V_2 -> V_84 == V_294 ) {
V_6 = F_24 ( V_2 , V_471 ) ;
V_6 &= ~ V_476 ;
F_25 ( V_2 , V_471 , V_6 ) ;
}
V_6 = F_24 ( V_2 , V_467 ) ;
V_6 |= V_477 ;
F_25 ( V_2 , V_467 , V_6 ) ;
V_6 = F_24 ( V_2 , V_478 ) ;
V_6 |= V_479 ;
F_25 ( V_2 , V_478 , V_6 ) ;
V_6 = F_24 ( V_2 , V_467 ) ;
V_6 |= V_480 ;
F_25 ( V_2 , V_467 , V_6 ) ;
F_28 ( V_2 , V_481 , 0x0b13 ) ;
V_72 = F_20 ( V_2 , V_30 , V_482 ) ;
V_72 |= V_483 ;
F_21 ( V_2 , V_30 , V_482 , V_72 ) ;
F_28 ( V_2 , V_484 , 0xf70f ) ;
F_28 ( V_2 , V_485 , 0x00af ) ;
F_28 ( V_2 , V_486 , 0x0208 ) ;
F_223 ( V_2 , true ) ;
F_25 ( V_2 , V_475 , V_487 | V_422 ) ;
F_221 ( V_2 , true ) ;
F_215 ( V_2 ) ;
switch ( V_2 -> V_84 ) {
case V_294 :
case V_295 :
break;
case V_296 :
case V_297 :
default:
F_191 ( V_2 , true ) ;
break;
}
F_11 ( V_427 , & V_2 -> V_18 ) ;
}
static V_21 F_227 ( struct V_1 * V_2 , T_3 V_36 )
{
V_21 V_72 ;
F_21 ( V_2 , V_30 , V_488 , V_489 | V_36 ) ;
V_72 = F_20 ( V_2 , V_30 , V_488 ) ;
V_72 = ( V_72 & V_490 ) << 9 ;
V_72 |= F_20 ( V_2 , V_30 , V_491 ) ;
return V_72 ;
}
static void F_228 ( struct V_1 * V_2 )
{
V_21 V_72 , V_492 = 0 ;
T_1 V_6 ;
F_222 ( V_2 , false ) ;
F_224 ( V_2 , false ) ;
F_25 ( V_2 , V_475 , 0 ) ;
F_193 ( V_2 , F_10 ( V_370 , & V_2 -> V_18 ) ) ;
V_6 = F_29 ( V_2 , V_356 ) ;
V_6 |= V_493 ;
F_28 ( V_2 , V_356 , V_6 ) ;
V_6 = F_24 ( V_2 , V_494 ) ;
V_6 |= V_495 ;
F_25 ( V_2 , V_494 , V_6 ) ;
V_72 = F_227 ( V_2 , 0x7d ) ;
V_6 = ( T_1 ) ( ( ( V_72 & 0x1fff0 ) >> 1 ) | ( V_72 & 0x7 ) ) ;
if ( V_6 != 0xffff )
F_25 ( V_2 , V_496 , V_6 ) ;
V_72 = F_24 ( V_2 , 0xc426 ) ;
V_72 &= 0x3fff ;
if ( V_72 ) {
V_21 V_497 ;
V_497 = ( 16000000 / V_72 ) & V_498 ;
V_72 = F_20 ( V_2 , V_31 , V_499 ) ;
V_72 = ( V_72 & ~ V_498 ) | V_497 ;
F_21 ( V_2 , V_31 , V_499 , V_72 ) ;
}
V_72 = F_20 ( V_2 , V_30 , V_482 ) ;
V_72 |= V_483 ;
F_21 ( V_2 , V_30 , V_482 , V_72 ) ;
if ( ! F_220 ( V_2 , true ) ) {
V_6 = F_24 ( V_2 , V_467 ) ;
V_6 |= V_477 ;
F_25 ( V_2 , V_467 , V_6 ) ;
V_6 = F_24 ( V_2 , V_478 ) ;
V_6 |= V_500 | V_501 | V_502 ;
F_25 ( V_2 , V_478 , V_6 ) ;
F_25 ( V_2 , V_503 , 0 ) ;
F_25 ( V_2 , V_503 , F_229 ( 5 ) ) ;
V_492 |= V_504 | V_505 |
V_506 | V_507 |
V_508 ;
F_220 ( V_2 , false ) ;
}
F_192 ( V_2 , V_492 , 0 ) ;
F_224 ( V_2 , true ) ;
F_25 ( V_2 , V_475 , V_487 | V_422 ) ;
F_222 ( V_2 , true ) ;
F_225 ( V_2 ) ;
F_191 ( V_2 , true ) ;
F_11 ( V_427 , & V_2 -> V_18 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
F_188 ( V_2 , false ) ;
F_170 ( V_2 , true ) ;
F_205 ( V_2 ) ;
V_72 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 &= ~ V_255 ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
F_165 ( V_2 ) ;
F_206 ( V_2 ) ;
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
V_72 &= ~ V_428 ;
F_23 ( V_2 , V_30 , V_303 , V_72 ) ;
V_72 = F_20 ( V_2 , V_30 , V_429 ) ;
V_72 &= ~ V_430 ;
F_21 ( V_2 , V_30 , V_429 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
V_72 = F_20 ( V_2 , V_30 , V_429 ) ;
V_72 |= V_432 ;
F_21 ( V_2 , V_30 , V_429 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
F_183 ( V_2 , V_2 -> V_45 -> V_158 & V_314 ) ;
V_72 = V_2 -> V_45 -> V_278 + V_279 + V_245 ;
F_21 ( V_2 , V_30 , V_452 , V_72 ) ;
F_23 ( V_2 , V_30 , V_509 , V_510 ) ;
V_72 = F_20 ( V_2 , V_30 , V_305 ) ;
V_72 |= V_454 ;
F_21 ( V_2 , V_30 , V_305 , V_72 ) ;
F_165 ( V_2 ) ;
F_18 ( V_2 , V_30 , V_433 , V_434 ) ;
F_21 ( V_2 , V_30 , V_437 , V_511 ) ;
F_21 ( V_2 , V_30 , V_439 , V_512 ) ;
F_18 ( V_2 , V_30 , V_443 , V_513 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
F_188 ( V_2 , true ) ;
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
V_72 &= ~ V_428 ;
F_23 ( V_2 , V_30 , V_303 , V_72 ) ;
F_181 ( V_2 ) ;
F_206 ( V_2 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
V_72 = F_20 ( V_2 , V_30 , V_429 ) ;
V_72 |= V_432 ;
F_21 ( V_2 , V_30 , V_429 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
if ( V_72 & V_431 )
break;
F_166 ( 1000 , 2000 ) ;
}
V_72 = V_2 -> V_45 -> V_278 + V_279 + V_245 ;
F_21 ( V_2 , V_30 , V_452 , V_72 ) ;
switch ( V_2 -> V_84 ) {
case V_294 :
case V_295 :
case V_296 :
case V_297 :
V_72 = F_20 ( V_2 , V_30 , V_383 ) ;
V_72 &= ~ V_514 ;
F_21 ( V_2 , V_30 , V_383 , V_72 ) ;
break;
case V_299 :
case V_300 :
F_21 ( V_2 , V_30 , V_515 , 0x00ff ) ;
break;
default:
break;
}
F_183 ( V_2 , true ) ;
V_72 = F_20 ( V_2 , V_30 , V_458 ) ;
V_72 |= V_459 ;
F_21 ( V_2 , V_30 , V_458 , V_72 ) ;
V_72 = F_22 ( V_2 , V_30 , V_303 ) ;
V_72 |= V_428 | V_460 ;
F_23 ( V_2 , V_30 , V_303 , V_72 ) ;
F_170 ( V_2 , false ) ;
V_72 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 |= V_257 | V_260 | V_256 ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
}
static void F_232 ( struct V_1 * V_2 )
{
F_221 ( V_2 , false ) ;
F_181 ( V_2 ) ;
F_206 ( V_2 ) ;
F_221 ( V_2 , true ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
F_222 ( V_2 , false ) ;
F_181 ( V_2 ) ;
F_206 ( V_2 ) ;
F_222 ( V_2 , true ) ;
}
static int F_234 ( struct V_1 * V_2 , T_3 V_516 , T_1 V_281 , T_3 V_517 )
{
T_1 V_518 , V_423 , V_519 ;
enum V_520 V_521 ;
int V_7 = 0 ;
V_423 = F_27 ( V_2 , V_424 ) ;
V_423 &= ~ ( V_522 | V_523 |
V_524 | V_525 ) ;
if ( V_2 -> V_526 . V_527 ) {
V_519 = F_27 ( V_2 , V_528 ) ;
V_519 &= ~ ( V_529 | V_530 ) ;
} else {
V_519 = 0 ;
}
if ( V_516 == V_531 ) {
if ( V_281 == V_532 ) {
V_518 = 0 ;
V_423 |= V_522 | V_523 ;
V_521 = V_533 ;
} else if ( V_281 == V_534 ) {
V_518 = V_535 ;
V_423 |= V_524 | V_525 ;
V_521 = V_536 ;
} else if ( V_281 == V_537 && V_2 -> V_526 . V_527 ) {
V_518 = V_538 ;
V_519 |= V_529 | V_530 ;
V_521 = V_539 ;
} else {
V_7 = - V_49 ;
goto V_249;
}
if ( V_517 == V_540 ) {
V_518 |= V_541 ;
if ( V_281 != V_537 )
V_521 ++ ;
}
} else {
if ( V_281 == V_532 ) {
if ( V_517 == V_540 ) {
V_423 |= V_522 | V_523 ;
V_521 = V_542 ;
} else {
V_423 |= V_522 ;
V_521 = V_543 ;
}
} else if ( V_281 == V_534 ) {
if ( V_517 == V_540 ) {
V_423 |= V_522 | V_523 ;
V_423 |= V_524 | V_525 ;
V_521 = V_544 ;
} else {
V_423 |= V_522 ;
V_423 |= V_524 ;
V_521 = V_545 ;
}
} else if ( V_281 == V_537 && V_2 -> V_526 . V_527 ) {
if ( V_517 == V_540 ) {
V_423 |= V_522 | V_523 ;
V_423 |= V_524 | V_525 ;
V_519 |= V_529 | V_530 ;
} else {
V_423 |= V_522 ;
V_423 |= V_524 ;
V_519 |= V_530 ;
}
V_521 = V_539 ;
} else {
V_7 = - V_49 ;
goto V_249;
}
V_518 = V_546 | V_547 ;
}
if ( F_235 ( V_427 , & V_2 -> V_18 ) )
V_518 |= V_373 ;
if ( V_2 -> V_526 . V_527 )
F_26 ( V_2 , V_528 , V_519 ) ;
F_26 ( V_2 , V_424 , V_423 ) ;
F_26 ( V_2 , V_371 , V_518 ) ;
switch ( V_2 -> V_84 ) {
case V_299 :
case V_300 :
F_192 ( V_2 , F_236 ( V_521 ) ,
V_548 ) ;
break;
default:
break;
}
if ( V_518 & V_373 ) {
int V_127 ;
for ( V_127 = 0 ; V_127 < 50 ; V_127 ++ ) {
F_195 ( 20 ) ;
if ( ( F_27 ( V_2 , V_371 ) & V_373 ) == 0 )
break;
}
}
V_249:
return V_7 ;
}
static void F_237 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_207 ( V_2 , false ) ;
F_218 ( V_2 ) ;
F_207 ( V_2 , true ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_148 ( V_2 ) ;
return;
}
F_182 ( V_2 , false ) ;
F_207 ( V_2 , false ) ;
F_219 ( V_2 ) ;
F_207 ( V_2 , true ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_189 ( V_2 , false ) ;
F_191 ( V_2 , false ) ;
F_221 ( V_2 , false ) ;
F_230 ( V_2 ) ;
F_221 ( V_2 , true ) ;
switch ( V_2 -> V_84 ) {
case V_294 :
case V_295 :
break;
case V_296 :
case V_297 :
default:
F_191 ( V_2 , true ) ;
break;
}
F_189 ( V_2 , true ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_148 ( V_2 ) ;
return;
}
F_189 ( V_2 , false ) ;
F_191 ( V_2 , false ) ;
F_198 ( V_2 , false ) ;
F_221 ( V_2 , false ) ;
F_231 ( V_2 ) ;
F_221 ( V_2 , true ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_190 ( V_2 , false ) ;
F_191 ( V_2 , false ) ;
F_222 ( V_2 , false ) ;
F_230 ( V_2 ) ;
F_18 ( V_2 , V_31 , V_447 , V_549 ) ;
F_222 ( V_2 , true ) ;
F_191 ( V_2 , true ) ;
F_190 ( V_2 , true ) ;
}
static void F_242 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_148 ( V_2 ) ;
return;
}
F_190 ( V_2 , false ) ;
F_191 ( V_2 , false ) ;
F_199 ( V_2 , false ) ;
F_222 ( V_2 , false ) ;
F_231 ( V_2 ) ;
F_222 ( V_2 , true ) ;
}
static bool F_243 ( struct V_1 * V_2 )
{
T_1 V_550 ;
F_21 ( V_2 , V_30 , V_39 , 0x2000 ) ;
V_2 -> V_37 = 0x2000 ;
F_23 ( V_2 , V_30 , 0xb014 , 0x4c ) ;
V_550 = F_20 ( V_2 , V_30 , 0xb01a ) ;
if ( V_550 & 0xc000 )
return false ;
else
return true ;
}
static bool F_244 ( struct V_1 * V_2 )
{
T_1 V_551 = F_24 ( V_2 , V_552 ) & 0xff ;
if ( V_551 == V_553 || V_551 == V_554 )
return false ;
else
return true ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_237 * V_97 = & V_2 -> V_97 ;
T_3 V_281 ;
V_281 = F_168 ( V_2 ) ;
if ( V_281 & V_555 ) {
if ( ! F_50 ( V_45 ) ) {
V_2 -> V_556 . V_285 ( V_2 ) ;
F_11 ( V_252 , & V_2 -> V_18 ) ;
F_66 ( V_45 ) ;
F_246 ( V_97 ) ;
F_247 ( V_45 ) ;
F_171 ( V_2 ) ;
F_248 ( & V_2 -> V_97 ) ;
F_126 ( V_45 ) ;
F_45 ( V_2 , V_259 , V_45 , L_26 ) ;
} else if ( F_124 ( V_45 ) &&
F_125 ( & V_2 -> V_112 ) < V_2 -> V_219 ) {
F_126 ( V_45 ) ;
}
} else {
if ( F_50 ( V_45 ) ) {
F_249 ( V_45 ) ;
F_246 ( V_97 ) ;
V_2 -> V_556 . V_557 ( V_2 ) ;
F_248 ( V_97 ) ;
F_45 ( V_2 , V_259 , V_45 , L_27 ) ;
}
}
}
static void F_250 ( struct V_558 * V_559 )
{
struct V_1 * V_2 = F_145 ( V_559 , struct V_1 , V_123 . V_559 ) ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) || ! F_251 ( V_2 -> V_45 ) )
return;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
goto V_55;
if ( ! F_252 ( & V_2 -> V_57 ) ) {
F_65 ( & V_2 -> V_123 , 0 ) ;
goto V_55;
}
if ( F_235 ( V_122 , & V_2 -> V_18 ) )
F_245 ( V_2 ) ;
if ( F_235 ( V_252 , & V_2 -> V_18 ) )
F_154 ( V_2 -> V_45 ) ;
if ( F_235 ( V_248 , & V_2 -> V_18 ) &&
F_50 ( V_2 -> V_45 ) )
F_55 ( & V_2 -> V_97 ) ;
F_37 ( & V_2 -> V_57 ) ;
V_55:
F_38 ( V_2 -> V_56 ) ;
}
static void F_253 ( struct V_558 * V_559 )
{
struct V_1 * V_2 = F_145 ( V_559 , struct V_1 , V_560 . V_559 ) ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_556 . V_561 ( V_2 ) ;
F_234 ( V_2 , V_2 -> V_516 , V_2 -> V_281 , V_2 -> V_517 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
}
static int F_254 ( struct V_562 * V_563 , unsigned long V_564 ,
void * V_6 )
{
struct V_1 * V_2 = F_145 ( V_563 , struct V_1 , V_565 ) ;
switch ( V_564 ) {
case V_566 :
case V_567 :
F_35 ( V_2 -> V_56 ) ;
break;
case V_568 :
case V_569 :
F_38 ( V_2 -> V_56 ) ;
break;
case V_570 :
case V_571 :
default:
break;
}
return V_572 ;
}
static int F_255 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_114 = 0 ;
V_114 = F_73 ( V_2 ) ;
if ( V_114 )
goto V_249;
V_114 = F_35 ( V_2 -> V_56 ) ;
if ( V_114 < 0 )
goto V_573;
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_556 . V_574 ( V_2 ) ;
F_249 ( V_45 ) ;
F_256 ( V_45 ) ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
V_114 = F_67 ( V_2 -> V_133 , V_9 ) ;
if ( V_114 ) {
if ( V_114 == - V_19 )
F_56 ( V_2 -> V_45 ) ;
F_42 ( V_2 , V_575 , V_45 , L_28 ,
V_114 ) ;
goto V_576;
}
F_248 ( & V_2 -> V_97 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
#ifdef F_257
V_2 -> V_565 . V_577 = F_254 ;
F_258 ( & V_2 -> V_565 ) ;
#endif
return 0 ;
V_576:
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_573:
F_71 ( V_2 ) ;
V_249:
return V_114 ;
}
static int F_259 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_114 = 0 ;
#ifdef F_257
F_260 ( & V_2 -> V_565 ) ;
#endif
F_246 ( & V_2 -> V_97 ) ;
F_143 ( V_91 , & V_2 -> V_18 ) ;
F_173 ( V_2 -> V_133 ) ;
F_261 ( & V_2 -> V_123 ) ;
F_66 ( V_45 ) ;
V_114 = F_35 ( V_2 -> V_56 ) ;
if ( V_114 < 0 || F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_148 ( V_2 ) ;
F_172 ( V_2 ) ;
} else {
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_556 . V_578 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
}
F_71 ( V_2 ) ;
return V_114 ;
}
static void F_262 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_20 ( V_2 , V_30 , V_579 ) ;
V_72 |= V_580 ;
F_21 ( V_2 , V_30 , V_579 , V_72 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_1 V_6 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
V_6 = F_27 ( V_2 , V_371 ) ;
if ( V_6 & V_372 ) {
V_6 &= ~ V_372 ;
F_26 ( V_2 , V_371 , V_6 ) ;
}
F_207 ( V_2 , false ) ;
if ( V_2 -> V_84 == V_85 ) {
V_72 = F_20 ( V_2 , V_30 , V_581 ) ;
V_72 &= ~ V_582 ;
F_21 ( V_2 , V_30 , V_581 , V_72 ) ;
}
F_182 ( V_2 , false ) ;
V_72 = F_20 ( V_2 , V_30 , V_482 ) ;
V_72 |= V_583 | V_483 ;
F_21 ( V_2 , V_30 , V_482 , V_72 ) ;
V_72 = F_16 ( V_2 , V_30 , V_330 ) ;
V_72 &= ~ V_584 ;
V_72 |= V_585 | V_586 ;
F_18 ( V_2 , V_30 , V_330 , V_72 ) ;
V_72 = V_587 | V_588 |
V_589 | V_590 ;
F_21 ( V_2 , V_30 , V_591 , V_72 ) ;
F_262 ( V_2 ) ;
V_72 = F_20 ( V_2 , V_31 , V_592 ) ;
V_72 &= ~ ( V_593 | V_594 ) ;
F_21 ( V_2 , V_31 , V_592 , V_72 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_1 V_6 ;
int V_127 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_189 ( V_2 , false ) ;
for ( V_127 = 0 ; V_127 < 500 ; V_127 ++ ) {
if ( F_20 ( V_2 , V_30 , V_595 ) &
V_596 )
break;
F_195 ( 20 ) ;
}
V_6 = F_194 ( V_2 , 0 ) ;
if ( V_2 -> V_84 == V_294 || V_2 -> V_84 == V_295 ||
V_2 -> V_84 == V_296 )
F_25 ( V_2 , V_597 , V_598 | V_599 | V_600 ) ;
V_6 = F_27 ( V_2 , V_371 ) ;
if ( V_6 & V_372 ) {
V_6 &= ~ V_372 ;
F_26 ( V_2 , V_371 , V_6 ) ;
}
V_6 = F_194 ( V_2 , V_362 ) ;
F_191 ( V_2 , false ) ;
if ( V_2 -> V_84 == V_295 ) {
V_72 = F_20 ( V_2 , V_31 , V_601 ) ;
V_72 &= ~ V_602 ;
V_72 |= F_265 ( 96 ) ;
F_21 ( V_2 , V_31 , V_601 , V_72 ) ;
V_72 = F_22 ( V_2 , V_31 , V_603 ) ;
V_72 |= V_604 | V_605 ;
F_23 ( V_2 , V_31 , V_603 , V_72 ) ;
} else if ( V_2 -> V_84 == V_296 ) {
V_72 = F_22 ( V_2 , V_30 , V_606 ) ;
V_72 &= ~ V_607 ;
F_23 ( V_2 , V_30 , V_606 , V_72 ) ;
V_72 = F_22 ( V_2 , V_31 , V_608 ) ;
if ( F_20 ( V_2 , V_31 , V_609 ) == 0 )
V_72 &= ~ V_610 ;
else
V_72 |= V_610 ;
F_23 ( V_2 , V_31 , V_608 , V_72 ) ;
} else if ( V_2 -> V_84 == V_297 ) {
V_72 = F_22 ( V_2 , V_31 , V_608 ) ;
if ( F_20 ( V_2 , V_31 , V_609 ) == 0 )
V_72 &= ~ V_610 ;
else
V_72 |= V_610 ;
F_23 ( V_2 , V_31 , V_608 , V_72 ) ;
}
V_72 = F_22 ( V_2 , V_31 , V_611 ) ;
V_72 |= V_612 ;
F_23 ( V_2 , V_31 , V_611 , V_72 ) ;
V_72 = F_20 ( V_2 , V_31 , V_613 ) ;
V_72 &= ~ V_614 ;
F_21 ( V_2 , V_31 , V_613 , V_72 ) ;
V_72 = F_20 ( V_2 , V_30 , V_581 ) ;
V_72 &= ~ V_582 ;
F_21 ( V_2 , V_30 , V_581 , V_72 ) ;
V_72 = V_615 | V_616 ;
if ( V_2 -> V_84 == V_295 && V_2 -> V_11 -> V_281 < V_617 )
V_72 |= V_618 ;
else
V_72 |= V_619 ;
F_23 ( V_2 , V_31 , V_620 , V_72 ) ;
V_72 = F_20 ( V_2 , V_31 , V_621 ) ;
V_72 &= ~ V_622 ;
V_72 |= V_623 | V_624 ;
F_21 ( V_2 , V_31 , V_621 , V_72 ) ;
F_21 ( V_2 , V_31 , V_625 , 0x0001 ) ;
F_198 ( V_2 , false ) ;
F_189 ( V_2 , true ) ;
F_188 ( V_2 , false ) ;
F_266 ( V_2 -> V_11 ) ;
V_72 = F_20 ( V_2 , V_31 , V_592 ) ;
V_72 &= ~ ( V_593 | V_594 ) ;
F_21 ( V_2 , V_31 , V_592 , V_72 ) ;
F_262 ( V_2 ) ;
switch ( V_2 -> V_11 -> V_281 ) {
case V_617 :
case V_626 :
V_2 -> V_293 = V_627 ;
break;
case V_628 :
V_2 -> V_293 = V_629 ;
break;
default:
V_2 -> V_293 = V_630 ;
break;
}
}
static void F_267 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_1 V_6 ;
int V_127 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_190 ( V_2 , false ) ;
for ( V_127 = 0 ; V_127 < 500 ; V_127 ++ ) {
if ( F_20 ( V_2 , V_30 , V_595 ) &
V_596 )
break;
F_195 ( 20 ) ;
}
V_6 = F_194 ( V_2 , 0 ) ;
V_6 = F_27 ( V_2 , V_371 ) ;
if ( V_6 & V_372 ) {
V_6 &= ~ V_372 ;
F_26 ( V_2 , V_371 , V_6 ) ;
}
V_6 = F_194 ( V_2 , V_362 ) ;
F_191 ( V_2 , false ) ;
F_21 ( V_2 , V_31 , V_631 , 0x0fff ) ;
F_21 ( V_2 , V_31 , V_632 , 500 ) ;
F_199 ( V_2 , false ) ;
F_196 ( V_2 , false ) ;
F_200 ( V_2 , false ) ;
F_202 ( V_2 , false ) ;
F_190 ( V_2 , true ) ;
F_266 ( V_2 -> V_11 ) ;
V_72 = F_20 ( V_2 , V_30 , V_332 ) ;
V_72 |= V_633 ;
F_21 ( V_2 , V_30 , V_332 , V_72 ) ;
F_11 ( V_370 , & V_2 -> V_18 ) ;
V_72 = F_20 ( V_2 , V_31 , V_592 ) ;
V_72 &= ~ ( V_593 | V_594 ) ;
F_21 ( V_2 , V_31 , V_592 , V_72 ) ;
F_262 ( V_2 ) ;
V_2 -> V_293 = 15000 ;
}
static int F_268 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_269 ( V_56 ) ;
struct V_44 * V_45 ;
if ( ! V_2 )
return 0 ;
V_45 = V_2 -> V_45 ;
if ( ! F_251 ( V_45 ) )
return 0 ;
F_66 ( V_45 ) ;
F_246 ( & V_2 -> V_97 ) ;
F_143 ( V_91 , & V_2 -> V_18 ) ;
F_173 ( V_2 -> V_133 ) ;
F_261 ( & V_2 -> V_123 ) ;
if ( F_50 ( V_45 ) ) {
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_556 . V_557 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
}
return 0 ;
}
static int F_270 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_269 ( V_56 ) ;
struct V_44 * V_45 ;
if ( ! V_2 )
return 0 ;
V_45 = V_2 -> V_45 ;
if ( ! F_251 ( V_45 ) )
return 0 ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
if ( F_50 ( V_45 ) ) {
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_556 . V_285 ( V_2 ) ;
F_171 ( V_2 ) ;
F_153 ( V_45 ) ;
F_37 ( & V_2 -> V_57 ) ;
}
F_248 ( & V_2 -> V_97 ) ;
F_126 ( V_45 ) ;
F_67 ( V_2 -> V_133 , V_9 ) ;
if ( ! F_83 ( & V_2 -> V_96 ) )
F_55 ( & V_2 -> V_97 ) ;
return 0 ;
}
static bool F_271 ( struct V_1 * V_2 )
{
bool V_634 = ! ! F_50 ( V_2 -> V_45 ) ;
bool V_635 = ! ! ( F_168 ( V_2 ) & V_555 ) ;
if ( F_272 ( & V_2 -> V_123 . V_559 ) || V_634 != V_635 )
return true ;
if ( ! V_634 && V_2 -> V_556 . V_636 ( V_2 ) )
return true ;
else if ( ! F_62 ( & V_2 -> V_112 ) )
return true ;
else
return false ;
}
static int F_273 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
if ( F_251 ( V_45 ) && V_45 -> V_18 & V_637 ) {
struct V_237 * V_97 = & V_2 -> V_97 ;
V_2 -> V_556 . V_638 ( V_2 , false ) ;
F_246 ( V_97 ) ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
if ( F_50 ( V_45 ) ) {
if ( F_168 ( V_2 ) & V_555 ) {
F_171 ( V_2 ) ;
} else {
F_249 ( V_45 ) ;
V_2 -> V_556 . V_557 ( V_2 ) ;
F_45 ( V_2 , V_259 , V_45 , L_29 ) ;
}
}
F_248 ( V_97 ) ;
F_143 ( V_272 , & V_2 -> V_18 ) ;
F_274 () ;
if ( ! F_83 ( & V_2 -> V_96 ) )
F_55 ( & V_2 -> V_97 ) ;
F_67 ( V_2 -> V_133 , V_639 ) ;
} else {
if ( V_45 -> V_18 & V_637 )
V_2 -> V_556 . V_638 ( V_2 , false ) ;
F_143 ( V_272 , & V_2 -> V_18 ) ;
}
return 0 ;
}
static int F_275 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
F_276 ( V_45 ) ;
if ( F_251 ( V_45 ) && V_45 -> V_18 & V_637 ) {
V_2 -> V_556 . V_574 ( V_2 ) ;
F_249 ( V_45 ) ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
F_67 ( V_2 -> V_133 , V_639 ) ;
}
return 0 ;
}
static int F_277 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
int V_7 = 0 ;
F_11 ( V_272 , & V_2 -> V_18 ) ;
F_274 () ;
if ( F_251 ( V_45 ) && F_10 ( V_91 , & V_2 -> V_18 ) ) {
V_21 V_640 = 0 ;
if ( F_50 ( V_45 ) ) {
V_21 V_72 ;
V_640 = F_16 ( V_2 , V_30 , V_254 ) ;
V_72 = V_640 & ~ V_255 ;
F_18 ( V_2 , V_30 , V_254 , V_72 ) ;
F_170 ( V_2 , true ) ;
V_72 = F_22 ( V_2 , V_30 ,
V_303 ) ;
if ( ! ( V_72 & V_641 ) ) {
F_170 ( V_2 , false ) ;
F_18 ( V_2 , V_30 , V_254 , V_640 ) ;
F_143 ( V_272 , & V_2 -> V_18 ) ;
F_274 () ;
V_7 = - V_642 ;
goto V_55;
}
}
F_143 ( V_91 , & V_2 -> V_18 ) ;
F_173 ( V_2 -> V_133 ) ;
V_2 -> V_556 . V_638 ( V_2 , true ) ;
if ( F_50 ( V_45 ) ) {
struct V_237 * V_97 = & V_2 -> V_97 ;
F_246 ( V_97 ) ;
F_172 ( V_2 ) ;
F_170 ( V_2 , false ) ;
F_18 ( V_2 , V_30 , V_254 , V_640 ) ;
F_248 ( V_97 ) ;
}
if ( F_271 ( V_2 ) ) {
F_273 ( V_2 ) ;
V_7 = - V_642 ;
}
}
V_55:
return V_7 ;
}
static int F_278 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
int V_7 = 0 ;
F_56 ( V_45 ) ;
if ( F_251 ( V_45 ) && F_10 ( V_91 , & V_2 -> V_18 ) ) {
struct V_237 * V_97 = & V_2 -> V_97 ;
F_143 ( V_91 , & V_2 -> V_18 ) ;
F_173 ( V_2 -> V_133 ) ;
F_246 ( V_97 ) ;
F_261 ( & V_2 -> V_123 ) ;
V_2 -> V_556 . V_578 ( V_2 ) ;
F_248 ( V_97 ) ;
}
return V_7 ;
}
static int F_279 ( struct V_135 * V_56 , T_9 V_643 )
{
struct V_1 * V_2 = F_269 ( V_56 ) ;
int V_7 ;
F_36 ( & V_2 -> V_57 ) ;
if ( F_280 ( V_643 ) )
V_7 = F_277 ( V_2 ) ;
else
V_7 = F_278 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
return V_7 ;
}
static int F_281 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_269 ( V_56 ) ;
int V_7 ;
F_36 ( & V_2 -> V_57 ) ;
if ( F_10 ( V_272 , & V_2 -> V_18 ) )
V_7 = F_273 ( V_2 ) ;
else
V_7 = F_275 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
return V_7 ;
}
static int F_282 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_269 ( V_56 ) ;
F_143 ( V_272 , & V_2 -> V_18 ) ;
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_556 . V_644 ( V_2 ) ;
F_283 ( V_645 , & V_2 -> V_560 , 0 ) ;
F_37 ( & V_2 -> V_57 ) ;
return F_281 ( V_56 ) ;
}
static void F_284 ( struct V_44 * V_83 , struct V_646 * V_647 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
if ( ! F_201 ( V_2 ) ) {
V_647 -> V_648 = 0 ;
V_647 -> V_315 = 0 ;
} else {
F_36 ( & V_2 -> V_57 ) ;
V_647 -> V_648 = V_329 ;
V_647 -> V_315 = F_185 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
}
F_38 ( V_2 -> V_56 ) ;
}
static int F_285 ( struct V_44 * V_83 , struct V_646 * V_647 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
if ( ! F_201 ( V_2 ) )
return - V_649 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_650;
F_36 ( & V_2 -> V_57 ) ;
F_186 ( V_2 , V_647 -> V_315 ) ;
V_2 -> V_380 = V_647 -> V_315 & V_329 ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_650:
return V_7 ;
}
static V_21 F_286 ( struct V_44 * V_83 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
return V_2 -> V_651 ;
}
static void F_287 ( struct V_44 * V_83 , V_21 V_3 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
V_2 -> V_651 = V_3 ;
}
static void F_288 ( struct V_44 * V_45 ,
struct V_652 * V_653 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
F_289 ( V_653 -> V_654 , V_655 , sizeof( V_653 -> V_654 ) ) ;
F_289 ( V_653 -> V_84 , V_656 , sizeof( V_653 -> V_84 ) ) ;
F_290 ( V_2 -> V_11 , V_653 -> V_657 , sizeof( V_653 -> V_657 ) ) ;
}
static
int F_291 ( struct V_44 * V_45 ,
struct V_658 * V_659 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_7 ;
if ( ! V_2 -> V_526 . V_660 )
return - V_649 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_249;
F_36 ( & V_2 -> V_57 ) ;
F_292 ( & V_2 -> V_526 , V_659 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_7 ;
}
static int F_293 ( struct V_44 * V_83 ,
const struct V_658 * V_659 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_249;
F_36 ( & V_2 -> V_57 ) ;
V_7 = F_234 ( V_2 , V_659 -> V_661 . V_516 , V_659 -> V_661 . V_281 ,
V_659 -> V_661 . V_517 ) ;
if ( ! V_7 ) {
V_2 -> V_516 = V_659 -> V_661 . V_516 ;
V_2 -> V_281 = V_659 -> V_661 . V_281 ;
V_2 -> V_517 = V_659 -> V_661 . V_517 ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_7 ;
}
static int F_294 ( struct V_44 * V_83 , int V_662 )
{
switch ( V_662 ) {
case V_663 :
return F_295 ( V_664 ) ;
default:
return - V_649 ;
}
}
static void F_296 ( struct V_44 * V_83 ,
struct V_665 * V_103 , T_10 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
struct V_666 V_667 ;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
F_9 ( V_2 , V_668 , sizeof( V_667 ) , & V_667 , V_30 ) ;
F_38 ( V_2 -> V_56 ) ;
V_6 [ 0 ] = F_297 ( V_667 . V_107 ) ;
V_6 [ 1 ] = F_297 ( V_667 . V_239 ) ;
V_6 [ 2 ] = F_297 ( V_667 . V_105 ) ;
V_6 [ 3 ] = F_109 ( V_667 . V_669 ) ;
V_6 [ 4 ] = F_298 ( V_667 . V_670 ) ;
V_6 [ 5 ] = F_298 ( V_667 . V_671 ) ;
V_6 [ 6 ] = F_109 ( V_667 . V_672 ) ;
V_6 [ 7 ] = F_109 ( V_667 . V_673 ) ;
V_6 [ 8 ] = F_297 ( V_667 . V_674 ) ;
V_6 [ 9 ] = F_297 ( V_667 . V_675 ) ;
V_6 [ 10 ] = F_109 ( V_667 . V_676 ) ;
V_6 [ 11 ] = F_298 ( V_667 . V_677 ) ;
V_6 [ 12 ] = F_298 ( V_667 . V_678 ) ;
}
static void F_299 ( struct V_44 * V_83 , V_21 V_679 , T_3 * V_6 )
{
switch ( V_679 ) {
case V_663 :
memcpy ( V_6 , * V_664 , sizeof( V_664 ) ) ;
break;
}
}
static int F_300 ( struct V_1 * V_2 , struct V_680 * V_681 )
{
V_21 V_72 , V_682 , V_683 , V_648 = 0 ;
T_1 V_50 ;
V_50 = F_209 ( V_2 , V_684 , V_685 ) ;
V_648 = F_301 ( V_50 ) ;
V_50 = F_209 ( V_2 , V_420 , V_421 ) ;
V_683 = F_302 ( V_50 ) ;
V_50 = F_209 ( V_2 , V_420 , V_686 ) ;
V_682 = F_302 ( V_50 ) ;
V_72 = F_20 ( V_2 , V_30 , V_406 ) ;
V_72 &= V_412 | V_413 ;
V_681 -> V_687 = ! ! V_72 ;
V_681 -> V_688 = ! ! ( V_648 & V_683 & V_682 ) ;
V_681 -> V_648 = V_648 ;
V_681 -> V_689 = V_683 ;
V_681 -> V_690 = V_682 ;
return 0 ;
}
static int F_303 ( struct V_1 * V_2 , struct V_680 * V_681 )
{
T_1 V_50 = F_304 ( V_681 -> V_689 ) ;
F_211 ( V_2 , V_681 -> V_687 ) ;
if ( ! V_681 -> V_687 )
V_50 = 0 ;
F_210 ( V_2 , V_420 , V_421 , V_50 ) ;
return 0 ;
}
static int F_305 ( struct V_1 * V_2 , struct V_680 * V_681 )
{
V_21 V_72 , V_682 , V_683 , V_648 = 0 ;
T_1 V_50 ;
V_50 = F_24 ( V_2 , V_691 ) ;
V_648 = F_301 ( V_50 ) ;
V_50 = F_24 ( V_2 , V_475 ) ;
V_683 = F_302 ( V_50 ) ;
V_50 = F_24 ( V_2 , V_692 ) ;
V_682 = F_302 ( V_50 ) ;
V_72 = F_20 ( V_2 , V_30 , V_406 ) ;
V_72 &= V_412 | V_413 ;
V_681 -> V_687 = ! ! V_72 ;
V_681 -> V_688 = ! ! ( V_648 & V_683 & V_682 ) ;
V_681 -> V_648 = V_648 ;
V_681 -> V_689 = V_683 ;
V_681 -> V_690 = V_682 ;
return 0 ;
}
static int F_306 ( struct V_1 * V_2 , struct V_680 * V_681 )
{
T_1 V_50 = F_304 ( V_681 -> V_689 ) ;
F_223 ( V_2 , V_681 -> V_687 ) ;
if ( ! V_681 -> V_687 )
V_50 = 0 ;
F_25 ( V_2 , V_475 , V_50 ) ;
return 0 ;
}
static int F_307 ( struct V_1 * V_2 , struct V_680 * V_681 )
{
T_1 V_50 = F_304 ( V_681 -> V_689 ) ;
F_224 ( V_2 , V_681 -> V_687 ) ;
if ( ! V_681 -> V_687 )
V_50 = 0 ;
F_25 ( V_2 , V_475 , V_50 ) ;
return 0 ;
}
static int
F_308 ( struct V_44 * V_693 , struct V_680 * V_694 )
{
struct V_1 * V_2 = F_31 ( V_693 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_249;
F_36 ( & V_2 -> V_57 ) ;
V_7 = V_2 -> V_556 . V_695 ( V_2 , V_694 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_7 ;
}
static int
F_309 ( struct V_44 * V_693 , struct V_680 * V_694 )
{
struct V_1 * V_2 = F_31 ( V_693 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_249;
F_36 ( & V_2 -> V_57 ) ;
V_7 = V_2 -> V_556 . V_696 ( V_2 , V_694 ) ;
if ( ! V_7 )
V_7 = F_310 ( & V_2 -> V_526 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_7 ;
}
static int F_311 ( struct V_44 * V_83 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_249;
F_36 ( & V_2 -> V_57 ) ;
V_7 = F_310 ( & V_2 -> V_526 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_7 ;
}
static int F_312 ( struct V_44 * V_45 ,
struct V_697 * V_293 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_381 :
case V_382 :
return - V_649 ;
default:
break;
}
V_293 -> V_698 = V_2 -> V_293 ;
return 0 ;
}
static int F_313 ( struct V_44 * V_45 ,
struct V_697 * V_293 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_7 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_381 :
case V_382 :
return - V_649 ;
default:
break;
}
if ( V_293 -> V_698 > V_630 )
return - V_49 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
F_36 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_293 != V_293 -> V_698 ) {
V_2 -> V_293 = V_293 -> V_698 ;
if ( F_251 ( V_2 -> V_45 ) && F_50 ( V_45 ) )
F_177 ( V_2 ) ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
return V_7 ;
}
static int F_314 ( struct V_44 * V_45 , struct V_699 * V_700 , int V_659 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
struct V_701 * V_6 = F_315 ( V_700 ) ;
int V_114 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
V_114 = F_35 ( V_2 -> V_56 ) ;
if ( V_114 < 0 )
goto V_249;
switch ( V_659 ) {
case V_702 :
V_6 -> V_46 = V_48 ;
break;
case V_703 :
F_36 ( & V_2 -> V_57 ) ;
V_6 -> V_704 = F_27 ( V_2 , V_6 -> V_705 ) ;
F_37 ( & V_2 -> V_57 ) ;
break;
case V_706 :
if ( ! F_316 ( V_707 ) ) {
V_114 = - V_20 ;
break;
}
F_36 ( & V_2 -> V_57 ) ;
F_26 ( V_2 , V_6 -> V_705 , V_6 -> V_708 ) ;
F_37 ( & V_2 -> V_57 ) ;
break;
default:
V_114 = - V_649 ;
}
F_38 ( V_2 -> V_56 ) ;
V_249:
return V_114 ;
}
static int F_317 ( struct V_44 * V_83 , int V_709 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_381 :
case V_382 :
V_83 -> V_278 = V_709 ;
return 0 ;
default:
break;
}
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
F_36 ( & V_2 -> V_57 ) ;
V_83 -> V_278 = V_709 ;
if ( F_251 ( V_83 ) ) {
V_21 V_710 = V_709 + V_279 + V_245 ;
F_21 ( V_2 , V_30 , V_452 , V_710 ) ;
if ( F_50 ( V_83 ) )
F_178 ( V_2 ) ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
return V_7 ;
}
static void F_318 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( V_2 -> V_84 != V_85 )
F_182 ( V_2 , true ) ;
}
static void F_319 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_198 ( V_2 , false ) ;
}
static void F_320 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_199 ( V_2 , false ) ;
}
static int F_321 ( struct V_1 * V_2 )
{
struct V_556 * V_711 = & V_2 -> V_556 ;
int V_7 = 0 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_381 :
case V_382 :
V_711 -> V_644 = F_263 ;
V_711 -> V_285 = F_175 ;
V_711 -> V_557 = F_216 ;
V_711 -> V_574 = F_237 ;
V_711 -> V_578 = F_238 ;
V_711 -> V_712 = F_318 ;
V_711 -> V_695 = F_300 ;
V_711 -> V_696 = F_303 ;
V_711 -> V_636 = F_243 ;
V_711 -> V_561 = F_217 ;
V_711 -> V_638 = F_202 ;
break;
case V_294 :
case V_295 :
case V_296 :
case V_297 :
V_711 -> V_644 = F_264 ;
V_711 -> V_285 = F_180 ;
V_711 -> V_557 = F_232 ;
V_711 -> V_574 = F_239 ;
V_711 -> V_578 = F_240 ;
V_711 -> V_712 = F_319 ;
V_711 -> V_695 = F_305 ;
V_711 -> V_696 = F_306 ;
V_711 -> V_636 = F_244 ;
V_711 -> V_561 = F_226 ;
V_711 -> V_638 = F_203 ;
break;
case V_299 :
case V_300 :
V_711 -> V_644 = F_267 ;
V_711 -> V_285 = F_180 ;
V_711 -> V_557 = F_233 ;
V_711 -> V_574 = F_241 ;
V_711 -> V_578 = F_242 ;
V_711 -> V_712 = F_320 ;
V_711 -> V_695 = F_305 ;
V_711 -> V_696 = F_307 ;
V_711 -> V_636 = F_244 ;
V_711 -> V_561 = F_228 ;
V_711 -> V_638 = F_204 ;
break;
default:
V_7 = - V_19 ;
F_47 ( V_2 , V_81 , V_2 -> V_45 , L_30 ) ;
break;
}
return V_7 ;
}
static T_3 F_322 ( struct V_135 * V_56 )
{
struct V_375 * V_11 = F_323 ( V_56 ) ;
V_21 V_72 = 0 ;
T_2 * V_8 ;
T_3 V_84 ;
int V_7 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return 0 ;
V_7 = F_3 ( V_11 , F_4 ( V_11 , 0 ) ,
V_12 , V_13 ,
V_305 , V_30 , V_8 , sizeof( * V_8 ) , 500 ) ;
if ( V_7 > 0 )
V_72 = ( F_17 ( * V_8 ) >> 16 ) & V_713 ;
F_5 ( V_8 ) ;
switch ( V_72 ) {
case 0x4c00 :
V_84 = V_85 ;
break;
case 0x4c10 :
V_84 = V_381 ;
break;
case 0x5c00 :
V_84 = V_294 ;
break;
case 0x5c10 :
V_84 = V_295 ;
break;
case 0x5c20 :
V_84 = V_296 ;
break;
case 0x5c30 :
V_84 = V_297 ;
break;
case 0x4800 :
V_84 = V_382 ;
break;
case 0x6000 :
V_84 = V_299 ;
break;
case 0x6010 :
V_84 = V_300 ;
break;
default:
V_84 = V_714 ;
F_324 ( & V_56 -> V_83 , L_31 , V_72 ) ;
break;
}
F_325 ( & V_56 -> V_83 , L_32 , V_84 ) ;
return V_84 ;
}
static int F_326 ( struct V_135 * V_56 ,
const struct V_715 * V_716 )
{
struct V_375 * V_11 = F_323 ( V_56 ) ;
T_3 V_84 = F_322 ( V_56 ) ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_7 ;
if ( V_84 == V_714 )
return - V_19 ;
if ( V_11 -> V_376 -> V_149 . V_717 != 1 ) {
F_327 ( V_11 , 1 ) ;
return - V_19 ;
}
F_328 ( V_11 ) ;
V_45 = F_329 ( sizeof( struct V_1 ) ) ;
if ( ! V_45 ) {
F_330 ( & V_56 -> V_83 , L_33 ) ;
return - V_10 ;
}
F_331 ( V_45 , & V_56 -> V_83 ) ;
V_2 = F_31 ( V_45 ) ;
V_2 -> V_651 = 0x7FFF ;
V_2 -> V_11 = V_11 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_84 = V_84 ;
switch ( V_84 ) {
case V_85 :
case V_381 :
case V_382 :
V_2 -> V_526 . V_527 = 0 ;
break;
default:
V_2 -> V_526 . V_527 = 1 ;
break;
}
V_7 = F_321 ( V_2 ) ;
if ( V_7 )
goto V_249;
F_332 ( & V_2 -> V_57 ) ;
F_333 ( & V_2 -> V_123 , F_250 ) ;
F_333 ( & V_2 -> V_560 , F_253 ) ;
V_45 -> V_718 = & V_719 ;
V_45 -> V_720 = V_721 ;
V_45 -> V_158 |= V_225 | V_722 | V_162 |
V_723 | V_724 | V_163 |
V_164 | V_314 |
V_725 ;
V_45 -> V_726 = V_225 | V_722 | V_162 |
V_723 | V_724 |
V_163 | V_164 |
V_314 | V_725 ;
V_45 -> V_727 = V_162 | V_722 | V_723 |
V_728 | V_724 |
V_163 | V_164 ;
if ( V_2 -> V_84 == V_85 ) {
V_45 -> V_158 &= ~ V_225 ;
V_45 -> V_726 &= ~ V_225 ;
}
V_45 -> V_729 = & V_711 ;
F_334 ( V_45 , V_730 ) ;
V_45 -> V_731 = V_732 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_381 :
V_45 -> V_733 = V_734 ;
break;
default:
V_45 -> V_733 = V_735 ;
break;
}
V_2 -> V_526 . V_83 = V_45 ;
V_2 -> V_526 . V_660 = F_30 ;
V_2 -> V_526 . V_736 = F_32 ;
V_2 -> V_526 . V_737 = 0x3f ;
V_2 -> V_526 . V_738 = 0x1f ;
V_2 -> V_526 . V_46 = V_48 ;
V_2 -> V_516 = V_739 ;
V_2 -> V_281 = V_2 -> V_526 . V_527 ? V_537 : V_534 ;
V_2 -> V_517 = V_540 ;
V_56 -> V_740 = 1 ;
V_2 -> V_556 . V_644 ( V_2 ) ;
F_283 ( V_645 , & V_2 -> V_560 , 0 ) ;
F_46 ( V_2 ) ;
F_335 ( V_56 , V_2 ) ;
F_336 ( V_45 , & V_2 -> V_97 , F_144 , V_741 ) ;
V_7 = F_337 ( V_45 ) ;
if ( V_7 != 0 ) {
F_47 ( V_2 , V_81 , V_45 , L_34 ) ;
goto V_55;
}
if ( ! F_201 ( V_2 ) )
F_186 ( V_2 , 0 ) ;
V_2 -> V_380 = F_185 ( V_2 ) ;
if ( V_2 -> V_380 )
F_187 ( & V_11 -> V_83 , true ) ;
else
F_187 ( & V_11 -> V_83 , false ) ;
F_45 ( V_2 , V_81 , V_45 , L_35 , V_656 ) ;
return 0 ;
V_55:
F_338 ( & V_2 -> V_97 ) ;
F_335 ( V_56 , NULL ) ;
V_249:
F_339 ( V_45 ) ;
return V_7 ;
}
static void F_340 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_269 ( V_56 ) ;
F_335 ( V_56 , NULL ) ;
if ( V_2 ) {
struct V_375 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_742 == V_743 )
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_338 ( & V_2 -> V_97 ) ;
F_341 ( V_2 -> V_45 ) ;
F_261 ( & V_2 -> V_560 ) ;
V_2 -> V_556 . V_712 ( V_2 ) ;
F_339 ( V_2 -> V_45 ) ;
}
}
