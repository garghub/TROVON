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
int F_15 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_9 ( V_2 , V_4 , V_5 , V_6 , V_31 ) ;
}
static inline
int F_16 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_12 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_31 ) ;
}
static V_21 F_17 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
T_2 V_6 ;
F_9 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 , type ) ;
return F_18 ( V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
T_2 V_8 = F_20 ( V_6 ) ;
F_12 ( V_2 , V_4 , V_29 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_32 = V_4 & 2 ;
V_4 &= ~ 3 ;
F_9 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_18 ( V_8 ) ;
V_6 >>= ( V_32 * 8 ) ;
V_6 &= 0xffff ;
return ( T_1 ) V_6 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
V_21 V_33 = 0xffff ;
T_2 V_8 ;
T_1 V_25 = V_34 ;
T_3 V_32 = V_4 & 2 ;
V_6 &= V_33 ;
if ( V_4 & 2 ) {
V_25 <<= V_32 ;
V_33 <<= ( V_32 * 8 ) ;
V_6 <<= ( V_32 * 8 ) ;
V_4 &= ~ 3 ;
}
V_8 = F_20 ( V_6 ) ;
F_12 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_3 F_23 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_32 = V_4 & 3 ;
V_4 &= ~ 3 ;
F_9 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_18 ( V_8 ) ;
V_6 >>= ( V_32 * 8 ) ;
V_6 &= 0xff ;
return ( T_3 ) V_6 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
V_21 V_33 = 0xff ;
T_2 V_8 ;
T_1 V_25 = V_35 ;
T_3 V_32 = V_4 & 3 ;
V_6 &= V_33 ;
if ( V_4 & 3 ) {
V_25 <<= V_32 ;
V_33 <<= ( V_32 * 8 ) ;
V_6 <<= ( V_32 * 8 ) ;
V_4 &= ~ 3 ;
}
V_8 = F_20 ( V_6 ) ;
F_12 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_36 )
{
T_1 V_37 , V_38 ;
V_37 = V_36 & 0xf000 ;
if ( V_37 != V_2 -> V_37 ) {
F_22 ( V_2 , V_30 , V_39 , V_37 ) ;
V_2 -> V_37 = V_37 ;
}
V_38 = ( V_36 & 0x0fff ) | 0xb000 ;
return F_21 ( V_2 , V_30 , V_38 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_6 )
{
T_1 V_37 , V_38 ;
V_37 = V_36 & 0xf000 ;
if ( V_37 != V_2 -> V_37 ) {
F_22 ( V_2 , V_30 , V_39 , V_37 ) ;
V_2 -> V_37 = V_37 ;
}
V_38 = ( V_36 & 0x0fff ) | 0xb000 ;
F_22 ( V_2 , V_30 , V_38 , V_6 ) ;
}
static inline void F_27 ( struct V_1 * V_2 , V_21 V_40 , V_21 V_3 )
{
F_26 ( V_2 , V_41 + V_40 * 2 , V_3 ) ;
}
static inline int F_28 ( struct V_1 * V_2 , V_21 V_40 )
{
return F_25 ( V_2 , V_41 + V_40 * 2 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_36 , T_1 V_6 )
{
F_26 ( V_2 , V_42 , V_36 ) ;
F_26 ( V_2 , V_43 , V_6 ) ;
}
static int F_30 ( struct V_44 * V_45 , int V_46 , int V_47 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_7 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( V_46 != V_48 )
return - V_49 ;
V_7 = F_28 ( V_2 , V_47 ) ;
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
F_27 ( V_2 , V_47 , V_50 ) ;
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
F_24 ( V_2 , V_30 , V_60 , V_61 ) ;
F_14 ( V_2 , V_62 , V_63 , 8 , V_36 -> V_54 ) ;
F_24 ( V_2 , V_30 , V_60 , V_64 ) ;
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
V_72 = F_21 ( V_2 , V_31 , V_74 ) ;
if ( ( V_72 & V_75 ) != 0x1000 )
return - V_19 ;
V_72 = F_23 ( V_2 , V_31 , V_76 ) ;
if ( ( V_72 & V_77 ) != 1 )
return - V_19 ;
V_66 = F_40 ( NULL , L_1 , NULL , & V_68 ) ;
V_71 = (union V_70 * ) V_68 . V_78 ;
if ( ! F_41 ( V_66 ) )
return - V_19 ;
if ( V_71 -> type != V_79 || V_71 -> string . V_80 != 0x17 ) {
F_42 ( V_2 , V_81 , V_2 -> V_45 ,
L_2
L_3 ,
V_71 -> type , V_71 -> string . V_80 ) ;
goto V_82;
}
if ( strncmp ( V_71 -> string . V_78 , L_4 , 9 ) != 0 ||
strncmp ( V_71 -> string . V_78 + 0x15 , L_5 , 1 ) != 0 ) {
F_42 ( V_2 , V_81 , V_2 -> V_45 ,
L_6 ) ;
goto V_82;
}
V_7 = F_43 ( V_73 , V_71 -> string . V_78 + 9 , 6 ) ;
if ( ! ( V_7 == 0 && F_34 ( V_73 ) ) ) {
F_42 ( V_2 , V_81 , V_2 -> V_45 ,
L_7
L_8 , V_7 , V_73 ) ;
V_7 = - V_49 ;
goto V_82;
}
memcpy ( V_65 -> V_54 , V_73 , 6 ) ;
F_44 ( V_2 -> V_45 -> V_58 , V_65 -> V_54 ) ;
F_45 ( V_2 , V_81 , V_2 -> V_45 ,
L_9 , V_65 -> V_54 ) ;
V_82:
F_5 ( V_71 ) ;
return V_7 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_44 * V_83 = V_2 -> V_45 ;
struct V_52 V_65 ;
int V_7 ;
if ( V_2 -> V_84 == V_85 )
V_7 = F_13 ( V_2 , V_62 , 8 , V_65 . V_54 ) ;
else {
V_7 = F_39 ( V_2 , & V_65 ) ;
if ( V_7 < 0 )
V_7 = F_13 ( V_2 , V_86 , 8 , V_65 . V_54 ) ;
}
if ( V_7 < 0 ) {
F_47 ( V_2 , V_81 , V_83 , L_10 ) ;
} else if ( ! F_34 ( V_65 . V_54 ) ) {
F_47 ( V_2 , V_81 , V_83 , L_11 ,
V_65 . V_54 ) ;
F_48 ( V_83 ) ;
F_44 ( V_65 . V_54 , V_83 -> V_58 ) ;
V_7 = F_33 ( V_83 , & V_65 ) ;
F_45 ( V_2 , V_81 , V_83 , L_12 ,
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
F_58 ( V_45 , L_13 ) ;
break;
default:
if ( F_57 () )
F_58 ( V_45 , L_14 , V_66 ) ;
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
F_58 ( V_45 , L_15 , V_66 ) ;
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
L_16 , V_66 ) ;
return;
case - V_118 :
F_45 ( V_2 , V_117 , V_2 -> V_45 , L_17 ) ;
goto V_119;
default:
F_45 ( V_2 , V_117 , V_2 -> V_45 , L_18 , V_66 ) ;
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
F_11 ( V_122 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
}
}
V_119:
V_114 = F_66 ( V_87 , V_101 ) ;
if ( V_114 == - V_19 ) {
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_2 -> V_45 ) ;
} else if ( V_114 ) {
F_47 ( V_2 , V_117 , V_2 -> V_45 ,
L_19 , V_114 ) ;
}
}
static inline void * F_67 ( void * V_6 )
{
return ( void * ) F_68 ( ( V_124 ) V_6 , V_125 ) ;
}
static inline void * F_69 ( void * V_6 )
{
return ( void * ) F_68 ( ( V_124 ) V_6 , V_126 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
F_71 ( V_2 -> V_129 [ V_127 ] . V_87 ) ;
V_2 -> V_129 [ V_127 ] . V_87 = NULL ;
F_5 ( V_2 -> V_129 [ V_127 ] . V_68 ) ;
V_2 -> V_129 [ V_127 ] . V_68 = NULL ;
V_2 -> V_129 [ V_127 ] . V_130 = NULL ;
}
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ ) {
F_71 ( V_2 -> V_132 [ V_127 ] . V_87 ) ;
V_2 -> V_132 [ V_127 ] . V_87 = NULL ;
F_5 ( V_2 -> V_132 [ V_127 ] . V_68 ) ;
V_2 -> V_132 [ V_127 ] . V_68 = NULL ;
V_2 -> V_132 [ V_127 ] . V_130 = NULL ;
}
F_71 ( V_2 -> V_133 ) ;
V_2 -> V_133 = NULL ;
F_5 ( V_2 -> V_134 ) ;
V_2 -> V_134 = NULL ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_135 * V_56 = V_2 -> V_56 ;
struct V_136 * V_137 = V_56 -> V_138 ;
struct V_139 * V_140 = V_137 -> V_141 + 2 ;
struct V_87 * V_87 ;
int V_142 , V_127 ;
T_3 * V_73 ;
V_142 = V_45 -> V_83 . V_143 ? F_73 ( V_45 -> V_83 . V_143 ) : - 1 ;
F_74 ( & V_2 -> V_94 ) ;
F_74 ( & V_2 -> V_110 ) ;
F_75 ( & V_2 -> V_111 ) ;
F_76 ( & V_2 -> V_112 ) ;
F_76 ( & V_2 -> V_144 ) ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
V_73 = F_77 ( V_145 , V_9 , V_142 ) ;
if ( ! V_73 )
goto V_146;
if ( V_73 != F_67 ( V_73 ) ) {
F_5 ( V_73 ) ;
V_73 = F_77 ( V_145 + V_125 , V_9 ,
V_142 ) ;
if ( ! V_73 )
goto V_146;
}
V_87 = F_78 ( 0 , V_9 ) ;
if ( ! V_87 ) {
F_5 ( V_73 ) ;
goto V_146;
}
F_75 ( & V_2 -> V_129 [ V_127 ] . V_95 ) ;
V_2 -> V_129 [ V_127 ] . V_90 = V_2 ;
V_2 -> V_129 [ V_127 ] . V_87 = V_87 ;
V_2 -> V_129 [ V_127 ] . V_68 = V_73 ;
V_2 -> V_129 [ V_127 ] . V_130 = F_67 ( V_73 ) ;
}
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ ) {
V_73 = F_77 ( V_145 , V_9 , V_142 ) ;
if ( ! V_73 )
goto V_146;
if ( V_73 != F_69 ( V_73 ) ) {
F_5 ( V_73 ) ;
V_73 = F_77 ( V_145 + V_126 , V_9 ,
V_142 ) ;
if ( ! V_73 )
goto V_146;
}
V_87 = F_78 ( 0 , V_9 ) ;
if ( ! V_87 ) {
F_5 ( V_73 ) ;
goto V_146;
}
F_75 ( & V_2 -> V_132 [ V_127 ] . V_95 ) ;
V_2 -> V_132 [ V_127 ] . V_90 = V_2 ;
V_2 -> V_132 [ V_127 ] . V_87 = V_87 ;
V_2 -> V_132 [ V_127 ] . V_68 = V_73 ;
V_2 -> V_132 [ V_127 ] . V_130 = F_69 ( V_73 ) ;
F_53 ( & V_2 -> V_132 [ V_127 ] . V_95 , & V_2 -> V_111 ) ;
}
V_2 -> V_133 = F_78 ( 0 , V_9 ) ;
if ( ! V_2 -> V_133 )
goto V_146;
V_2 -> V_134 = F_2 ( V_147 , V_9 ) ;
if ( ! V_2 -> V_134 )
goto V_146;
V_2 -> V_148 = ( int ) V_140 -> V_149 . V_150 ;
F_79 ( V_2 -> V_133 , V_2 -> V_11 , F_80 ( V_2 -> V_11 , 3 ) ,
V_2 -> V_134 , V_147 , F_63 ,
V_2 , V_2 -> V_148 ) ;
return 0 ;
V_146:
F_70 ( V_2 ) ;
return - V_10 ;
}
static struct V_104 * F_81 ( struct V_1 * V_2 )
{
struct V_104 * V_89 = NULL ;
unsigned long V_18 ;
if ( F_82 ( & V_2 -> V_111 ) )
return NULL ;
F_83 ( & V_2 -> V_110 , V_18 ) ;
if ( ! F_82 ( & V_2 -> V_111 ) ) {
struct V_151 * V_152 ;
V_152 = V_2 -> V_111 . V_153 ;
F_84 ( V_152 ) ;
V_89 = F_85 ( V_152 , struct V_104 , V_95 ) ;
}
F_86 ( & V_2 -> V_110 , V_18 ) ;
return V_89 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_154 * V_155 ,
struct V_156 * V_95 )
{
if ( F_88 ( V_155 ) -> V_157 ) {
T_6 V_158 = V_2 -> V_45 -> V_158 ;
struct V_156 V_159 ;
struct V_154 * V_160 , * V_161 ;
V_158 &= ~ ( V_162 | V_163 | V_164 ) ;
V_160 = F_89 ( V_155 , V_158 ) ;
if ( F_90 ( V_160 ) || ! V_160 )
goto V_165;
F_91 ( & V_159 ) ;
do {
V_161 = V_160 ;
V_160 = V_160 -> V_153 ;
V_161 -> V_153 = NULL ;
F_92 ( & V_159 , V_161 ) ;
} while ( V_160 );
F_93 ( & V_159 , V_95 ) ;
F_94 ( V_155 ) ;
} else if ( V_155 -> V_166 == V_167 ) {
if ( F_95 ( V_155 ) < 0 )
goto V_165;
F_96 ( V_95 , V_155 ) ;
} else {
struct V_102 * V_103 ;
V_165:
V_103 = & V_2 -> V_45 -> V_103 ;
V_103 -> V_168 ++ ;
F_94 ( V_155 ) ;
}
}
static int F_97 ( struct V_154 * V_155 )
{
const struct V_169 * V_170 ;
struct V_171 * V_172 ;
int V_7 ;
V_7 = F_98 ( V_155 , 0 ) ;
if ( V_7 )
return V_7 ;
V_170 = F_99 ( V_155 ) ;
V_172 = F_100 ( V_155 ) ;
V_172 -> V_173 = 0 ;
V_172 -> V_173 = ~ F_101 ( 0 , & V_170 -> V_174 , & V_170 -> V_175 , 0 ) ;
return V_7 ;
}
static inline void F_102 ( struct V_176 * V_149 , struct V_154 * V_155 )
{
if ( F_103 ( V_155 ) ) {
V_21 V_177 ;
V_177 = V_178 | F_104 ( F_105 ( V_155 ) ) ;
V_149 -> V_177 |= F_106 ( V_177 ) ;
}
}
static inline void F_107 ( struct V_179 * V_149 , struct V_154 * V_155 )
{
V_21 V_177 = F_108 ( V_149 -> V_177 ) ;
if ( V_177 & V_180 )
F_109 ( V_155 , F_110 ( V_181 ) ,
F_104 ( V_177 & 0xffff ) ) ;
}
static int F_111 ( struct V_1 * V_2 , struct V_176 * V_149 ,
struct V_154 * V_155 , V_21 V_182 , V_21 V_183 )
{
V_21 V_184 = F_88 ( V_155 ) -> V_157 ;
V_21 V_185 , V_177 = 0 ;
int V_7 = V_186 ;
F_112 ( V_182 > V_187 ) ;
V_185 = V_182 | V_188 | V_189 ;
if ( V_184 ) {
if ( V_183 > V_190 ) {
F_42 ( V_2 , V_191 , V_2 -> V_45 ,
L_20 ,
V_183 ) ;
V_7 = V_192 ;
goto V_193;
}
switch ( F_113 ( V_155 ) ) {
case F_110 ( V_194 ) :
V_185 |= V_195 ;
break;
case F_110 ( V_196 ) :
if ( F_97 ( V_155 ) ) {
V_7 = V_192 ;
goto V_193;
}
V_185 |= V_197 ;
break;
default:
F_112 ( 1 ) ;
break;
}
V_185 |= V_183 << V_198 ;
V_177 |= F_114 ( V_184 , V_199 ) << V_200 ;
} else if ( V_155 -> V_166 == V_167 ) {
T_3 V_201 ;
if ( V_183 > V_202 ) {
F_42 ( V_2 , V_191 , V_2 -> V_45 ,
L_21 ,
V_183 ) ;
V_7 = V_203 ;
goto V_193;
}
switch ( F_113 ( V_155 ) ) {
case F_110 ( V_194 ) :
V_177 |= V_204 ;
V_201 = F_115 ( V_155 ) -> V_205 ;
break;
case F_110 ( V_196 ) :
V_177 |= V_206 ;
V_201 = F_99 ( V_155 ) -> V_207 ;
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
F_112 ( 1 ) ;
V_177 |= V_183 << V_213 ;
}
V_149 -> V_177 = F_106 ( V_177 ) ;
V_149 -> V_185 = F_106 ( V_185 ) ;
V_193:
return V_7 ;
}
static int F_116 ( struct V_1 * V_2 , struct V_104 * V_89 )
{
struct V_156 V_214 , * V_112 = & V_2 -> V_112 ;
int V_215 , V_7 ;
T_3 * V_216 ;
F_91 ( & V_214 ) ;
F_52 ( & V_112 -> V_217 ) ;
F_117 ( V_112 , & V_214 ) ;
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
V_155 = F_118 ( & V_214 ) ;
if ( ! V_155 )
break;
V_182 = V_155 -> V_182 + sizeof( * V_176 ) ;
if ( V_182 > V_215 ) {
F_96 ( & V_214 , V_155 ) ;
break;
}
V_216 = F_69 ( V_216 ) ;
V_176 = (struct V_176 * ) V_216 ;
V_218 = ( V_21 ) F_119 ( V_155 ) ;
if ( F_111 ( V_2 , V_176 , V_155 , V_155 -> V_182 , V_218 ) ) {
F_87 ( V_2 , V_155 , & V_214 ) ;
continue;
}
F_102 ( V_176 , V_155 ) ;
V_216 += sizeof( * V_176 ) ;
V_182 = V_155 -> V_182 ;
if ( F_120 ( V_155 , 0 , V_216 , V_182 ) < 0 ) {
struct V_102 * V_103 = & V_2 -> V_45 -> V_103 ;
V_103 -> V_168 ++ ;
F_121 ( V_155 ) ;
V_216 -= sizeof( * V_176 ) ;
continue;
}
V_216 += V_182 ;
V_89 -> V_109 += V_182 ;
V_89 -> V_106 ++ ;
F_121 ( V_155 ) ;
V_215 = V_145 - ( int ) ( F_69 ( V_216 ) - V_89 -> V_130 ) ;
}
if ( ! F_62 ( & V_214 ) ) {
F_52 ( & V_112 -> V_217 ) ;
F_93 ( & V_214 , V_112 ) ;
F_54 ( & V_112 -> V_217 ) ;
}
F_122 ( V_2 -> V_45 ) ;
if ( F_123 ( V_2 -> V_45 ) &&
F_124 ( & V_2 -> V_112 ) < V_2 -> V_219 )
F_125 ( V_2 -> V_45 ) ;
F_126 ( V_2 -> V_45 ) ;
V_7 = F_127 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_220;
F_128 ( V_89 -> V_87 , V_2 -> V_11 , F_129 ( V_2 -> V_11 , 2 ) ,
V_89 -> V_130 , ( int ) ( V_216 - ( T_3 * ) V_89 -> V_130 ) ,
( V_221 ) F_60 , V_89 ) ;
V_7 = F_66 ( V_89 -> V_87 , V_101 ) ;
if ( V_7 < 0 )
F_61 ( V_2 -> V_56 ) ;
V_220:
return V_7 ;
}
static T_3 F_130 ( struct V_1 * V_2 , struct V_179 * V_179 )
{
T_3 V_222 = V_223 ;
V_21 V_177 , V_224 ;
if ( V_2 -> V_84 == V_85 )
goto V_225;
V_177 = F_108 ( V_179 -> V_177 ) ;
V_224 = F_108 ( V_179 -> V_224 ) ;
if ( V_177 & V_226 ) {
if ( V_224 & V_227 )
V_222 = V_223 ;
else if ( ( V_177 & V_228 ) && ( V_224 & V_229 ) )
V_222 = V_223 ;
else if ( ( V_177 & V_230 ) && ( V_224 & V_231 ) )
V_222 = V_223 ;
else
V_222 = V_232 ;
} else if ( V_233 ) {
if ( ( V_177 & V_228 ) && ! ( V_224 & V_229 ) )
V_222 = V_232 ;
else if ( ( V_177 & V_230 ) && ! ( V_224 & V_231 ) )
V_222 = V_232 ;
}
V_225:
return V_222 ;
}
static int F_131 ( struct V_1 * V_2 , int V_234 )
{
unsigned long V_18 ;
struct V_151 * V_152 , * V_153 , V_144 ;
int V_7 = 0 , V_235 = 0 ;
if ( ! F_62 ( & V_2 -> V_144 ) ) {
while ( V_235 < V_234 ) {
struct V_154 * V_155 = F_118 ( & V_2 -> V_144 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_102 * V_103 = & V_45 -> V_103 ;
unsigned int V_236 ;
if ( ! V_155 )
break;
V_236 = V_155 -> V_182 ;
F_132 ( & V_2 -> V_97 , V_155 ) ;
V_235 ++ ;
V_103 -> V_237 ++ ;
V_103 -> V_238 += V_236 ;
}
}
if ( F_82 ( & V_2 -> V_96 ) )
goto V_55;
F_75 ( & V_144 ) ;
F_83 ( & V_2 -> V_94 , V_18 ) ;
F_133 ( & V_2 -> V_96 , & V_144 ) ;
F_86 ( & V_2 -> V_94 , V_18 ) ;
F_134 (cursor, next, &rx_queue) {
struct V_179 * V_179 ;
struct V_88 * V_89 ;
int V_239 = 0 ;
struct V_87 * V_87 ;
T_3 * V_240 ;
F_84 ( V_152 ) ;
V_89 = F_85 ( V_152 , struct V_88 , V_95 ) ;
V_87 = V_89 -> V_87 ;
if ( V_87 -> V_92 < V_93 )
goto V_241;
V_179 = V_89 -> V_130 ;
V_240 = V_89 -> V_130 ;
V_239 += sizeof( struct V_179 ) ;
while ( V_87 -> V_92 > V_239 ) {
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_102 * V_103 = & V_45 -> V_103 ;
unsigned int V_236 ;
struct V_154 * V_155 ;
V_236 = F_108 ( V_179 -> V_185 ) & V_242 ;
if ( V_236 < V_93 )
break;
V_239 += V_236 ;
if ( V_87 -> V_92 < V_239 )
break;
V_236 -= V_243 ;
V_240 += sizeof( struct V_179 ) ;
V_155 = F_135 ( V_45 , V_236 ) ;
if ( ! V_155 ) {
V_103 -> V_244 ++ ;
goto V_245;
}
V_155 -> V_166 = F_130 ( V_2 , V_179 ) ;
memcpy ( V_155 -> V_6 , V_240 , V_236 ) ;
F_136 ( V_155 , V_236 ) ;
V_155 -> V_205 = F_137 ( V_155 , V_45 ) ;
F_107 ( V_179 , V_155 ) ;
if ( V_235 < V_234 ) {
F_132 ( & V_2 -> V_97 , V_155 ) ;
V_235 ++ ;
V_103 -> V_237 ++ ;
V_103 -> V_238 += V_236 ;
} else {
F_92 ( & V_2 -> V_144 , V_155 ) ;
}
V_245:
V_240 = F_67 ( V_240 + V_236 + V_243 ) ;
V_179 = (struct V_179 * ) V_240 ;
V_239 = ( int ) ( V_240 - ( T_3 * ) V_89 -> V_130 ) ;
V_239 += sizeof( struct V_179 ) ;
}
V_241:
if ( ! V_7 ) {
V_7 = F_59 ( V_2 , V_89 , V_101 ) ;
} else {
V_87 -> V_92 = 0 ;
F_53 ( & V_89 -> V_95 , V_153 ) ;
}
}
if ( ! F_82 ( & V_144 ) ) {
F_83 ( & V_2 -> V_94 , V_18 ) ;
F_138 ( & V_144 , & V_2 -> V_96 ) ;
F_86 ( & V_2 -> V_94 , V_18 ) ;
}
V_55:
return V_235 ;
}
static void F_139 ( struct V_1 * V_2 )
{
int V_114 ;
do {
struct V_104 * V_89 ;
if ( F_62 ( & V_2 -> V_112 ) )
break;
V_89 = F_81 ( V_2 ) ;
if ( ! V_89 )
break;
V_114 = F_116 ( V_2 , V_89 ) ;
if ( V_114 ) {
struct V_44 * V_45 = V_2 -> V_45 ;
if ( V_114 == - V_19 ) {
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_45 ) ;
} else {
struct V_102 * V_103 = & V_45 -> V_103 ;
unsigned long V_18 ;
F_42 ( V_2 , V_191 , V_45 ,
L_22 , V_114 ) ;
V_103 -> V_168 += V_89 -> V_106 ;
F_83 ( & V_2 -> V_110 , V_18 ) ;
F_53 ( & V_89 -> V_95 , & V_2 -> V_111 ) ;
F_86 ( & V_2 -> V_110 , V_18 ) ;
}
}
} while ( V_114 == 0 );
}
static void F_140 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
return;
if ( ! F_50 ( V_2 -> V_45 ) )
return;
F_141 ( V_246 , & V_2 -> V_18 ) ;
F_139 ( V_2 ) ;
}
static int F_142 ( struct V_247 * V_97 , int V_234 )
{
struct V_1 * V_2 = F_143 ( V_97 , struct V_1 , V_97 ) ;
int V_235 ;
V_235 = F_131 ( V_2 , V_234 ) ;
F_140 ( V_2 ) ;
if ( V_235 < V_234 ) {
F_144 ( V_97 ) ;
if ( ! F_82 ( & V_2 -> V_96 ) )
F_55 ( V_97 ) ;
}
return V_235 ;
}
static
int F_59 ( struct V_1 * V_2 , struct V_88 * V_89 , T_7 V_248 )
{
int V_7 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) ||
! F_10 ( V_91 , & V_2 -> V_18 ) || ! F_50 ( V_2 -> V_45 ) )
return 0 ;
F_128 ( V_89 -> V_87 , V_2 -> V_11 , F_145 ( V_2 -> V_11 , 1 ) ,
V_89 -> V_130 , V_145 ,
( V_221 ) F_49 , V_89 ) ;
V_7 = F_66 ( V_89 -> V_87 , V_248 ) ;
if ( V_7 == - V_19 ) {
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_56 ( V_2 -> V_45 ) ;
} else if ( V_7 ) {
struct V_87 * V_87 = V_89 -> V_87 ;
unsigned long V_18 ;
V_87 -> V_92 = 0 ;
F_83 ( & V_2 -> V_94 , V_18 ) ;
F_53 ( & V_89 -> V_95 , & V_2 -> V_96 ) ;
F_86 ( & V_2 -> V_94 , V_18 ) ;
F_47 ( V_2 , V_249 , V_2 -> V_45 ,
L_23 , V_89 , V_7 ) ;
F_55 ( & V_2 -> V_97 ) ;
}
return V_7 ;
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = & V_2 -> V_45 -> V_103 ;
struct V_156 V_214 , * V_112 = & V_2 -> V_112 ;
struct V_154 * V_155 ;
if ( F_62 ( V_112 ) )
return;
F_91 ( & V_214 ) ;
F_147 ( & V_112 -> V_217 ) ;
F_117 ( V_112 , & V_214 ) ;
F_148 ( & V_112 -> V_217 ) ;
while ( ( V_155 = F_118 ( & V_214 ) ) ) {
F_94 ( V_155 ) ;
V_103 -> V_168 ++ ;
}
}
static void F_149 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
F_42 ( V_2 , V_191 , V_45 , L_24 ) ;
F_150 ( V_2 -> V_56 ) ;
}
static void F_151 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
if ( F_50 ( V_45 ) ) {
F_11 ( V_250 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
}
}
static void F_152 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
V_21 V_251 [ 2 ] ;
T_2 V_8 [ 2 ] ;
V_21 V_72 ;
F_153 ( V_45 ) ;
V_72 = F_17 ( V_2 , V_30 , V_252 ) ;
V_72 &= ~ V_253 ;
V_72 |= V_254 | V_255 ;
if ( V_45 -> V_18 & V_256 ) {
F_154 ( V_2 , V_257 , V_45 , L_25 ) ;
V_72 |= V_258 | V_259 ;
V_251 [ 1 ] = 0xffffffff ;
V_251 [ 0 ] = 0xffffffff ;
} else if ( ( F_155 ( V_45 ) > V_260 ) ||
( V_45 -> V_18 & V_261 ) ) {
V_72 |= V_258 ;
V_251 [ 1 ] = 0xffffffff ;
V_251 [ 0 ] = 0xffffffff ;
} else {
struct V_262 * V_263 ;
V_251 [ 1 ] = 0 ;
V_251 [ 0 ] = 0 ;
F_156 (ha, netdev) {
int V_264 = F_157 ( V_265 , V_263 -> V_36 ) >> 26 ;
V_251 [ V_264 >> 5 ] |= 1 << ( V_264 & 31 ) ;
V_72 |= V_258 ;
}
}
V_8 [ 0 ] = F_20 ( F_158 ( V_251 [ 1 ] ) ) ;
V_8 [ 1 ] = F_20 ( F_158 ( V_251 [ 0 ] ) ) ;
F_14 ( V_2 , V_266 , V_29 , sizeof( V_8 ) , V_8 ) ;
F_19 ( V_2 , V_30 , V_252 , V_72 ) ;
F_125 ( V_45 ) ;
}
static T_6
F_159 ( struct V_154 * V_155 , struct V_44 * V_83 ,
T_6 V_158 )
{
V_21 V_184 = F_88 ( V_155 ) -> V_157 ;
int V_267 = V_184 ? V_190 : V_202 ;
int V_218 = F_119 ( V_155 ) ;
if ( ( V_184 || V_155 -> V_166 == V_167 ) && V_218 > V_267 )
V_158 &= ~ ( V_268 | V_269 ) ;
else if ( ( V_155 -> V_182 + sizeof( struct V_176 ) ) > V_145 )
V_158 &= ~ V_269 ;
return V_158 ;
}
static T_8 F_160 ( struct V_154 * V_155 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
F_161 ( V_155 ) ;
F_162 ( & V_2 -> V_112 , V_155 ) ;
if ( ! F_82 ( & V_2 -> V_111 ) ) {
if ( F_10 ( V_270 , & V_2 -> V_18 ) ) {
F_11 ( V_246 , & V_2 -> V_18 ) ;
F_65 ( & V_2 -> V_123 , 0 ) ;
} else {
F_51 ( V_2 -> V_11 ) ;
F_55 ( & V_2 -> V_97 ) ;
}
} else if ( F_124 ( & V_2 -> V_112 ) > V_2 -> V_219 ) {
F_153 ( V_45 ) ;
}
return V_271 ;
}
static void F_163 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_30 , V_272 ) ;
V_72 &= ~ V_273 ;
F_22 ( V_2 , V_30 , V_272 , V_72 ) ;
V_72 |= V_273 ;
F_22 ( V_2 , V_30 , V_272 , V_72 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
int V_127 ;
F_24 ( V_2 , V_30 , V_274 , V_275 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
if ( ! ( F_23 ( V_2 , V_30 , V_274 ) & V_275 ) )
break;
F_165 ( 100 , 400 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
V_2 -> V_219 = V_145 / ( V_45 -> V_276 + V_277 + V_278 +
sizeof( struct V_176 ) ) ;
}
static inline T_3 F_167 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , V_30 , V_279 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_3 V_280 ;
V_280 = F_167 ( V_2 ) ;
if ( V_280 & V_281 ) {
V_72 = F_21 ( V_2 , V_30 , V_282 ) ;
V_72 |= V_283 ;
F_22 ( V_2 , V_30 , V_282 , V_72 ) ;
} else {
V_72 = F_21 ( V_2 , V_30 , V_282 ) ;
V_72 &= ~ V_283 ;
F_22 ( V_2 , V_30 , V_282 , V_72 ) ;
}
}
static void F_169 ( struct V_1 * V_2 , bool V_284 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_30 , V_285 ) ;
if ( V_284 )
V_72 |= V_286 ;
else
V_72 &= ~ V_286 ;
F_22 ( V_2 , V_30 , V_285 , V_72 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
int V_127 , V_7 = 0 ;
F_75 ( & V_2 -> V_96 ) ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
F_75 ( & V_2 -> V_129 [ V_127 ] . V_95 ) ;
V_7 = F_59 ( V_2 , & V_2 -> V_129 [ V_127 ] , V_9 ) ;
if ( V_7 )
break;
}
if ( V_7 && ++ V_127 < V_128 ) {
struct V_151 V_144 ;
unsigned long V_18 ;
F_75 ( & V_144 ) ;
do {
struct V_88 * V_89 = & V_2 -> V_129 [ V_127 ++ ] ;
struct V_87 * V_87 = V_89 -> V_87 ;
V_87 -> V_92 = 0 ;
F_53 ( & V_89 -> V_95 , & V_144 ) ;
} while ( V_127 < V_128 );
F_83 ( & V_2 -> V_94 , V_18 ) ;
F_138 ( & V_144 , & V_2 -> V_96 ) ;
F_86 ( & V_2 -> V_94 , V_18 ) ;
}
return V_7 ;
}
static int F_171 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ )
F_172 ( V_2 -> V_129 [ V_127 ] . V_87 ) ;
while ( ! F_62 ( & V_2 -> V_144 ) )
F_94 ( F_118 ( & V_2 -> V_144 ) ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
V_21 V_72 ;
F_163 ( V_2 ) ;
V_72 = F_23 ( V_2 , V_30 , V_274 ) ;
V_72 |= V_287 | V_288 ;
F_24 ( V_2 , V_30 , V_274 , V_72 ) ;
F_169 ( V_2 , false ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_166 ( V_2 ) ;
F_168 ( V_2 ) ;
return F_173 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
V_21 V_72 = V_2 -> V_289 / 8 ;
F_22 ( V_2 , V_31 , V_290 , V_72 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
V_21 V_276 = V_2 -> V_45 -> V_276 ;
V_21 V_72 = ( V_145 - V_276 - V_277 - V_278 ) / 8 ;
F_22 ( V_2 , V_31 , V_291 , V_72 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_178 ( V_2 -> V_11 ) ;
F_166 ( V_2 ) ;
F_168 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
return F_173 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_146 ( V_2 ) ;
return;
}
V_72 = F_17 ( V_2 , V_30 , V_252 ) ;
V_72 &= ~ V_253 ;
F_19 ( V_2 , V_30 , V_252 , V_72 ) ;
F_146 ( V_2 ) ;
for ( V_127 = 0 ; V_127 < V_131 ; V_127 ++ )
F_172 ( V_2 -> V_132 [ V_127 ] . V_87 ) ;
F_169 ( V_2 , true ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( ( V_72 & V_293 ) == V_293 )
break;
F_165 ( 1000 , 2000 ) ;
}
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
if ( F_21 ( V_2 , V_30 , V_294 ) & V_295 )
break;
F_165 ( 1000 , 2000 ) ;
}
F_171 ( V_2 ) ;
F_164 ( V_2 ) ;
}
static void F_180 ( struct V_1 * V_2 , bool V_284 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_31 , V_296 ) ;
if ( V_284 )
V_72 |= V_297 ;
else
V_72 &= ~ V_297 ;
F_22 ( V_2 , V_31 , V_296 , V_72 ) ;
V_72 = F_21 ( V_2 , V_31 , V_298 ) ;
V_72 &= ~ V_299 ;
F_22 ( V_2 , V_31 , V_298 , V_72 ) ;
}
static void F_181 ( struct V_1 * V_2 , bool V_284 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_30 , V_300 ) ;
if ( V_284 )
V_72 |= V_301 ;
else
V_72 &= ~ V_301 ;
F_22 ( V_2 , V_30 , V_300 , V_72 ) ;
}
static int F_182 ( struct V_44 * V_83 ,
T_6 V_158 )
{
T_6 V_302 = V_158 ^ V_83 -> V_158 ;
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_303;
F_36 ( & V_2 -> V_57 ) ;
if ( V_302 & V_304 ) {
if ( V_158 & V_304 )
F_181 ( V_2 , true ) ;
else
F_181 ( V_2 , false ) ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_7 ;
}
static V_21 F_183 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_21 V_305 = 0 ;
V_72 = F_21 ( V_2 , V_30 , V_306 ) ;
if ( V_72 & V_307 )
V_305 |= V_308 ;
V_72 = F_21 ( V_2 , V_30 , V_309 ) ;
if ( V_72 & V_310 )
V_305 |= V_311 ;
if ( V_72 & V_312 )
V_305 |= V_313 ;
if ( V_72 & V_314 )
V_305 |= V_315 ;
V_72 = F_21 ( V_2 , V_30 , V_316 ) ;
if ( V_72 & V_317 )
V_305 |= V_318 ;
return V_305 ;
}
static void F_184 ( struct V_1 * V_2 , V_21 V_305 )
{
V_21 V_72 ;
F_24 ( V_2 , V_30 , V_60 , V_61 ) ;
V_72 = F_21 ( V_2 , V_30 , V_306 ) ;
V_72 &= ~ V_307 ;
if ( V_305 & V_308 )
V_72 |= V_307 ;
F_22 ( V_2 , V_30 , V_306 , V_72 ) ;
V_72 = F_21 ( V_2 , V_30 , V_309 ) ;
V_72 &= ~ ( V_310 | V_312 | V_314 ) ;
if ( V_305 & V_311 )
V_72 |= V_310 ;
if ( V_305 & V_313 )
V_72 |= V_312 ;
if ( V_305 & V_315 )
V_72 |= V_314 ;
F_22 ( V_2 , V_30 , V_309 , V_72 ) ;
F_24 ( V_2 , V_30 , V_60 , V_64 ) ;
V_72 = F_21 ( V_2 , V_30 , V_316 ) ;
V_72 &= ~ V_317 ;
if ( V_305 & V_318 )
V_72 |= V_317 ;
F_22 ( V_2 , V_30 , V_316 , V_72 ) ;
if ( V_305 & V_319 )
F_185 ( & V_2 -> V_11 -> V_83 , true ) ;
else
F_185 ( & V_2 -> V_11 -> V_83 , false ) ;
}
static void F_186 ( struct V_1 * V_2 , bool V_284 )
{
T_3 V_320 [ 8 ] ;
if ( V_284 )
memset ( V_320 , 0xff , sizeof( V_320 ) ) ;
else
memset ( V_320 , 0x00 , sizeof( V_320 ) ) ;
F_16 ( V_2 , V_321 , V_63 , sizeof( V_320 ) , V_320 ) ;
}
static void F_187 ( struct V_1 * V_2 , bool V_284 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_31 , V_322 ) ;
if ( V_284 && V_2 -> V_84 != V_323 && V_2 -> V_84 != V_324 )
V_72 |= V_325 ;
else
V_72 &= ~ V_325 ;
F_22 ( V_2 , V_31 , V_322 , V_72 ) ;
}
static void F_188 ( struct V_1 * V_2 , bool V_284 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_31 , V_326 ) ;
if ( V_284 )
V_72 |= V_327 | V_328 ;
else
V_72 &= ~ ( V_327 | V_328 ) ;
F_22 ( V_2 , V_31 , V_326 , V_72 ) ;
V_72 = F_21 ( V_2 , V_31 , V_74 ) ;
V_72 &= ~ V_329 ;
F_22 ( V_2 , V_31 , V_74 , V_72 ) ;
}
static bool F_189 ( struct V_1 * V_2 )
{
struct V_330 * V_11 = V_2 -> V_11 ;
return ( V_11 -> V_331 -> V_149 . V_332 & V_333 ) ;
}
static void F_190 ( struct V_1 * V_2 , bool V_284 )
{
if ( V_284 ) {
V_21 V_72 ;
F_184 ( V_2 , V_319 ) ;
F_24 ( V_2 , V_30 , V_60 , V_61 ) ;
V_72 = F_21 ( V_2 , V_30 , V_306 ) ;
V_72 |= V_334 ;
F_22 ( V_2 , V_30 , V_306 , V_72 ) ;
F_24 ( V_2 , V_30 , V_60 , V_64 ) ;
} else {
V_21 V_72 ;
F_184 ( V_2 , V_2 -> V_335 ) ;
F_24 ( V_2 , V_30 , V_60 , V_61 ) ;
V_72 = F_21 ( V_2 , V_30 , V_306 ) ;
V_72 &= ~ V_334 ;
F_22 ( V_2 , V_30 , V_306 , V_72 ) ;
F_24 ( V_2 , V_30 , V_60 , V_64 ) ;
}
}
static void F_191 ( struct V_1 * V_2 , bool V_284 )
{
F_190 ( V_2 , V_284 ) ;
if ( V_284 ) {
F_186 ( V_2 , false ) ;
F_187 ( V_2 , false ) ;
} else {
F_187 ( V_2 , true ) ;
F_186 ( V_2 , true ) ;
}
}
static void F_192 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_127 ;
V_6 = F_28 ( V_2 , V_336 ) ;
if ( V_6 & V_337 )
return;
V_6 |= V_337 ;
F_27 ( V_2 , V_336 , V_6 ) ;
for ( V_127 = 0 ; V_127 < 50 ; V_127 ++ ) {
F_193 ( 20 ) ;
if ( ( F_28 ( V_2 , V_336 ) & V_337 ) == 0 )
break;
}
}
static void F_194 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_30 , V_338 ) ;
V_72 &= ~ ( V_339 | V_340 | V_341 ) ;
F_22 ( V_2 , V_30 , V_338 , V_72 ) ;
F_22 ( V_2 , V_30 , V_342 , V_343 ) ;
F_22 ( V_2 , V_30 , V_344 , 0 ) ;
F_19 ( V_2 , V_30 , V_345 , 0 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_23 ( V_2 , V_31 , V_346 ) ;
V_72 &= ~ ( V_347 | V_348 ) ;
F_24 ( V_2 , V_31 , V_346 , V_72 ) ;
V_72 |= V_347 | V_348 ;
F_24 ( V_2 , V_31 , V_346 , V_72 ) ;
}
static void F_196 ( struct V_1 * V_2 , bool V_284 )
{
if ( V_284 ) {
F_26 ( V_2 , V_349 , V_350 | V_351 |
V_352 | V_353 ) ;
} else {
F_26 ( V_2 , V_349 , V_351 | V_352 |
V_353 ) ;
F_193 ( 20 ) ;
}
}
static void F_197 ( struct V_1 * V_2 )
{
F_196 ( V_2 , false ) ;
F_179 ( V_2 ) ;
F_196 ( V_2 , true ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_28 ( V_2 , V_336 ) ;
if ( V_6 & V_354 ) {
V_6 &= ~ V_354 ;
F_27 ( V_2 , V_336 , V_6 ) ;
}
F_11 ( V_355 , & V_2 -> V_18 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
V_72 = F_17 ( V_2 , V_30 , V_252 ) ;
V_72 &= ~ V_253 ;
F_19 ( V_2 , V_30 , V_252 , V_72 ) ;
F_169 ( V_2 , true ) ;
F_194 ( V_2 ) ;
F_198 ( V_2 ) ;
F_24 ( V_2 , V_30 , V_60 , V_64 ) ;
F_24 ( V_2 , V_30 , V_274 , 0x00 ) ;
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
V_72 &= ~ V_356 ;
F_24 ( V_2 , V_30 , V_292 , V_72 ) ;
V_72 = F_21 ( V_2 , V_30 , V_357 ) ;
V_72 &= ~ V_358 ;
F_22 ( V_2 , V_30 , V_357 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
V_72 = F_21 ( V_2 , V_30 , V_357 ) ;
V_72 |= V_360 ;
F_22 ( V_2 , V_30 , V_357 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
F_164 ( V_2 ) ;
F_19 ( V_2 , V_30 , V_361 , V_362 ) ;
if ( V_2 -> V_11 -> V_280 == V_363 ||
V_2 -> V_11 -> V_280 == V_364 ) {
F_19 ( V_2 , V_30 , V_365 ,
V_366 ) ;
F_19 ( V_2 , V_30 , V_367 ,
V_368 ) ;
} else {
F_19 ( V_2 , V_30 , V_365 ,
V_369 ) ;
F_19 ( V_2 , V_30 , V_367 ,
V_370 ) ;
}
F_19 ( V_2 , V_30 , V_371 , V_372 ) ;
F_24 ( V_2 , V_31 , V_373 , V_374 ) ;
F_19 ( V_2 , V_31 , V_375 , V_376 ) ;
F_19 ( V_2 , V_31 , V_377 ,
V_378 | V_379 ) ;
F_181 ( V_2 , V_2 -> V_45 -> V_158 & V_304 ) ;
F_22 ( V_2 , V_30 , V_380 , V_381 ) ;
V_72 = F_21 ( V_2 , V_30 , V_294 ) ;
V_72 |= V_382 ;
F_22 ( V_2 , V_30 , V_294 , V_72 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
V_72 &= ~ V_356 ;
F_24 ( V_2 , V_30 , V_292 , V_72 ) ;
F_19 ( V_2 , V_30 , V_361 , V_383 ) ;
F_19 ( V_2 , V_30 , V_365 , V_384 ) ;
F_19 ( V_2 , V_30 , V_367 , V_385 ) ;
F_179 ( V_2 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
V_72 = F_21 ( V_2 , V_30 , V_357 ) ;
V_72 |= V_360 ;
F_22 ( V_2 , V_30 , V_357 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
F_22 ( V_2 , V_30 , V_380 , V_381 ) ;
F_181 ( V_2 , true ) ;
V_72 = F_21 ( V_2 , V_30 , V_386 ) ;
V_72 |= V_387 ;
F_22 ( V_2 , V_30 , V_386 , V_72 ) ;
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
V_72 |= V_356 | V_388 ;
F_24 ( V_2 , V_30 , V_292 , V_72 ) ;
F_169 ( V_2 , false ) ;
V_72 = F_17 ( V_2 , V_30 , V_252 ) ;
V_72 |= V_255 | V_258 | V_254 ;
F_19 ( V_2 , V_30 , V_252 , V_72 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_1 V_6 ;
if ( V_2 -> V_84 == V_323 || V_2 -> V_84 == V_324 ||
V_2 -> V_84 == V_389 )
F_26 ( V_2 , V_390 , V_391 | V_392 | V_393 ) ;
V_6 = F_28 ( V_2 , V_336 ) ;
if ( V_6 & V_354 ) {
V_6 &= ~ V_354 ;
F_27 ( V_2 , V_336 , V_6 ) ;
}
if ( V_2 -> V_84 == V_323 ) {
V_6 = F_25 ( V_2 , V_394 ) ;
V_6 &= ~ V_395 ;
F_26 ( V_2 , V_394 , V_6 ) ;
}
V_6 = F_25 ( V_2 , V_396 ) ;
V_6 |= V_397 ;
F_26 ( V_2 , V_396 , V_6 ) ;
V_6 = F_25 ( V_2 , V_398 ) ;
V_6 |= V_399 ;
F_26 ( V_2 , V_398 , V_6 ) ;
V_6 = F_25 ( V_2 , V_396 ) ;
V_6 |= V_400 ;
F_26 ( V_2 , V_396 , V_6 ) ;
F_29 ( V_2 , V_401 , 0x0b13 ) ;
V_72 = F_21 ( V_2 , V_30 , V_402 ) ;
V_72 |= V_403 ;
F_22 ( V_2 , V_30 , V_402 , V_72 ) ;
F_29 ( V_2 , V_404 , 0xf70f ) ;
F_29 ( V_2 , V_405 , 0x00af ) ;
F_29 ( V_2 , V_406 , 0x0208 ) ;
F_11 ( V_355 , & V_2 -> V_18 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
F_169 ( V_2 , true ) ;
F_194 ( V_2 ) ;
V_72 = F_17 ( V_2 , V_30 , V_252 ) ;
V_72 &= ~ V_253 ;
F_19 ( V_2 , V_30 , V_252 , V_72 ) ;
F_201 ( V_2 ) ;
F_164 ( V_2 ) ;
F_195 ( V_2 ) ;
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
V_72 &= ~ V_356 ;
F_24 ( V_2 , V_30 , V_292 , V_72 ) ;
V_72 = F_21 ( V_2 , V_30 , V_357 ) ;
V_72 &= ~ V_358 ;
F_22 ( V_2 , V_30 , V_357 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
V_72 = F_21 ( V_2 , V_30 , V_357 ) ;
V_72 |= V_360 ;
F_22 ( V_2 , V_30 , V_357 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
F_181 ( V_2 , V_2 -> V_45 -> V_158 & V_304 ) ;
F_22 ( V_2 , V_30 , V_380 , V_407 ) ;
F_24 ( V_2 , V_30 , V_408 , V_409 ) ;
V_72 = F_21 ( V_2 , V_30 , V_294 ) ;
V_72 |= V_382 ;
F_22 ( V_2 , V_30 , V_294 , V_72 ) ;
F_164 ( V_2 ) ;
F_19 ( V_2 , V_30 , V_361 , V_362 ) ;
F_22 ( V_2 , V_30 , V_365 , V_410 ) ;
F_22 ( V_2 , V_30 , V_367 , V_411 ) ;
F_19 ( V_2 , V_30 , V_371 , V_412 ) ;
V_72 = F_21 ( V_2 , V_31 , V_413 ) ;
V_72 &= ~ ( V_414 | V_415 ) ;
F_22 ( V_2 , V_31 , V_413 , V_72 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
V_72 &= ~ V_356 ;
F_24 ( V_2 , V_30 , V_292 , V_72 ) ;
F_179 ( V_2 ) ;
F_195 ( V_2 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
V_72 = F_21 ( V_2 , V_30 , V_357 ) ;
V_72 |= V_360 ;
F_22 ( V_2 , V_30 , V_357 , V_72 ) ;
for ( V_127 = 0 ; V_127 < 1000 ; V_127 ++ ) {
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
if ( V_72 & V_359 )
break;
F_165 ( 1000 , 2000 ) ;
}
F_22 ( V_2 , V_30 , V_380 , V_407 ) ;
V_72 = F_21 ( V_2 , V_30 , V_338 ) ;
V_72 &= ~ V_416 ;
F_22 ( V_2 , V_30 , V_338 , V_72 ) ;
F_181 ( V_2 , true ) ;
V_72 = F_21 ( V_2 , V_30 , V_386 ) ;
V_72 |= V_387 ;
F_22 ( V_2 , V_30 , V_386 , V_72 ) ;
V_72 = F_23 ( V_2 , V_30 , V_292 ) ;
V_72 |= V_356 | V_388 ;
F_24 ( V_2 , V_30 , V_292 , V_72 ) ;
F_169 ( V_2 , false ) ;
V_72 = F_17 ( V_2 , V_30 , V_252 ) ;
V_72 |= V_255 | V_258 | V_254 ;
F_19 ( V_2 , V_30 , V_252 , V_72 ) ;
}
static void F_204 ( struct V_1 * V_2 , bool V_284 )
{
T_1 V_6 ;
V_6 = F_25 ( V_2 , V_396 ) ;
if ( V_284 ) {
V_6 |= V_417 ;
F_26 ( V_2 , V_396 , V_6 ) ;
} else {
V_6 &= ~ V_417 ;
F_26 ( V_2 , V_396 , V_6 ) ;
F_193 ( 20 ) ;
}
}
static void F_205 ( struct V_1 * V_2 )
{
F_204 ( V_2 , false ) ;
F_179 ( V_2 ) ;
F_195 ( V_2 ) ;
F_204 ( V_2 , true ) ;
F_206 ( V_2 -> V_11 ) ;
}
static int F_207 ( struct V_1 * V_2 , T_3 V_418 , T_1 V_280 , T_3 V_419 )
{
T_1 V_420 , V_421 , V_422 ;
int V_7 = 0 ;
F_208 ( & V_2 -> V_123 ) ;
V_421 = F_28 ( V_2 , V_423 ) ;
V_421 &= ~ ( V_424 | V_425 |
V_426 | V_427 ) ;
if ( V_2 -> V_428 . V_429 ) {
V_422 = F_28 ( V_2 , V_430 ) ;
V_422 &= ~ ( V_431 | V_432 ) ;
} else {
V_422 = 0 ;
}
if ( V_418 == V_433 ) {
if ( V_280 == V_434 ) {
V_420 = 0 ;
V_421 |= V_424 | V_425 ;
} else if ( V_280 == V_435 ) {
V_420 = V_436 ;
V_421 |= V_426 | V_427 ;
} else if ( V_280 == V_437 && V_2 -> V_428 . V_429 ) {
V_420 = V_438 ;
V_422 |= V_431 | V_432 ;
} else {
V_7 = - V_49 ;
goto V_303;
}
if ( V_419 == V_439 )
V_420 |= V_440 ;
} else {
if ( V_280 == V_434 ) {
if ( V_419 == V_439 )
V_421 |= V_424 | V_425 ;
else
V_421 |= V_424 ;
} else if ( V_280 == V_435 ) {
if ( V_419 == V_439 ) {
V_421 |= V_424 | V_425 ;
V_421 |= V_426 | V_427 ;
} else {
V_421 |= V_424 ;
V_421 |= V_426 ;
}
} else if ( V_280 == V_437 && V_2 -> V_428 . V_429 ) {
if ( V_419 == V_439 ) {
V_421 |= V_424 | V_425 ;
V_421 |= V_426 | V_427 ;
V_422 |= V_431 | V_432 ;
} else {
V_421 |= V_424 ;
V_421 |= V_426 ;
V_422 |= V_432 ;
}
} else {
V_7 = - V_49 ;
goto V_303;
}
V_420 = V_441 | V_442 ;
}
if ( F_10 ( V_355 , & V_2 -> V_18 ) )
V_420 |= V_337 ;
if ( V_2 -> V_428 . V_429 )
F_27 ( V_2 , V_430 , V_422 ) ;
F_27 ( V_2 , V_423 , V_421 ) ;
F_27 ( V_2 , V_336 , V_420 ) ;
if ( F_209 ( V_355 , & V_2 -> V_18 ) ) {
int V_127 ;
for ( V_127 = 0 ; V_127 < 50 ; V_127 ++ ) {
F_193 ( 20 ) ;
if ( ( F_28 ( V_2 , V_336 ) & V_337 ) == 0 )
break;
}
}
V_303:
return V_7 ;
}
static void F_210 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_196 ( V_2 , false ) ;
F_199 ( V_2 ) ;
F_196 ( V_2 , true ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_146 ( V_2 ) ;
return;
}
F_180 ( V_2 , false ) ;
F_196 ( V_2 , false ) ;
F_200 ( V_2 ) ;
F_196 ( V_2 , true ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_186 ( V_2 , false ) ;
F_204 ( V_2 , false ) ;
F_202 ( V_2 ) ;
F_204 ( V_2 , true ) ;
F_187 ( V_2 , true ) ;
F_186 ( V_2 , true ) ;
F_206 ( V_2 -> V_11 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_146 ( V_2 ) ;
return;
}
F_186 ( V_2 , false ) ;
F_187 ( V_2 , false ) ;
F_188 ( V_2 , false ) ;
F_204 ( V_2 , false ) ;
F_203 ( V_2 ) ;
F_204 ( V_2 , true ) ;
}
static bool F_214 ( struct V_1 * V_2 )
{
T_1 V_443 ;
F_22 ( V_2 , V_30 , V_39 , 0x2000 ) ;
V_2 -> V_37 = 0x2000 ;
F_24 ( V_2 , V_30 , 0xb014 , 0x4c ) ;
V_443 = F_21 ( V_2 , V_30 , 0xb01a ) ;
if ( V_443 & 0xc000 )
return false ;
else
return true ;
}
static bool F_215 ( struct V_1 * V_2 )
{
T_1 V_444 = F_25 ( V_2 , V_445 ) & 0xff ;
if ( V_444 == V_446 || V_444 == V_447 )
return false ;
else
return true ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
T_3 V_280 ;
V_280 = F_167 ( V_2 ) ;
if ( V_280 & V_448 ) {
if ( ! F_50 ( V_45 ) ) {
V_2 -> V_449 . V_284 ( V_2 ) ;
F_11 ( V_250 , & V_2 -> V_18 ) ;
F_217 ( & V_2 -> V_97 ) ;
F_218 ( V_45 ) ;
F_170 ( V_2 ) ;
F_219 ( & V_2 -> V_97 ) ;
}
} else {
if ( F_50 ( V_45 ) ) {
F_220 ( V_45 ) ;
F_217 ( & V_2 -> V_97 ) ;
V_2 -> V_449 . V_450 ( V_2 ) ;
F_219 ( & V_2 -> V_97 ) ;
}
}
}
static void F_221 ( struct V_451 * V_452 )
{
struct V_1 * V_2 = F_143 ( V_452 , struct V_1 , V_123 . V_452 ) ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) || ! F_222 ( V_2 -> V_45 ) )
return;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
if ( ! F_10 ( V_91 , & V_2 -> V_18 ) )
goto V_55;
if ( ! F_223 ( & V_2 -> V_57 ) ) {
F_65 ( & V_2 -> V_123 , 0 ) ;
goto V_55;
}
if ( F_209 ( V_122 , & V_2 -> V_18 ) )
F_216 ( V_2 ) ;
if ( F_209 ( V_250 , & V_2 -> V_18 ) )
F_152 ( V_2 -> V_45 ) ;
if ( F_209 ( V_246 , & V_2 -> V_18 ) &&
F_50 ( V_2 -> V_45 ) )
F_55 ( & V_2 -> V_97 ) ;
if ( F_209 ( V_355 , & V_2 -> V_18 ) )
F_192 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
V_55:
F_38 ( V_2 -> V_56 ) ;
}
static int F_224 ( struct V_453 * V_454 , unsigned long V_455 ,
void * V_6 )
{
struct V_1 * V_2 = F_143 ( V_454 , struct V_1 , V_456 ) ;
switch ( V_455 ) {
case V_457 :
case V_458 :
F_35 ( V_2 -> V_56 ) ;
break;
case V_459 :
case V_460 :
F_38 ( V_2 -> V_56 ) ;
break;
case V_461 :
case V_462 :
default:
break;
}
return V_463 ;
}
static int F_225 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_114 = 0 ;
V_114 = F_72 ( V_2 ) ;
if ( V_114 )
goto V_303;
F_220 ( V_45 ) ;
V_114 = F_35 ( V_2 -> V_56 ) ;
if ( V_114 < 0 ) {
F_70 ( V_2 ) ;
goto V_303;
}
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_449 . V_464 ( V_2 ) ;
F_207 ( V_2 , V_465 ,
V_2 -> V_428 . V_429 ? V_437 : V_435 ,
V_439 ) ;
F_220 ( V_45 ) ;
F_226 ( V_45 ) ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
V_114 = F_66 ( V_2 -> V_133 , V_9 ) ;
if ( V_114 ) {
if ( V_114 == - V_19 )
F_56 ( V_2 -> V_45 ) ;
F_42 ( V_2 , V_466 , V_45 , L_26 ,
V_114 ) ;
F_70 ( V_2 ) ;
} else {
F_219 ( & V_2 -> V_97 ) ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
#ifdef F_227
V_2 -> V_456 . V_467 = F_224 ;
F_228 ( & V_2 -> V_456 ) ;
#endif
V_303:
return V_114 ;
}
static int F_229 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_114 = 0 ;
#ifdef F_227
F_230 ( & V_2 -> V_456 ) ;
#endif
F_217 ( & V_2 -> V_97 ) ;
F_141 ( V_91 , & V_2 -> V_18 ) ;
F_172 ( V_2 -> V_133 ) ;
F_208 ( & V_2 -> V_123 ) ;
F_153 ( V_45 ) ;
V_114 = F_35 ( V_2 -> V_56 ) ;
if ( V_114 < 0 || F_10 ( V_17 , & V_2 -> V_18 ) ) {
F_146 ( V_2 ) ;
F_171 ( V_2 ) ;
} else {
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_449 . V_468 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
}
F_70 ( V_2 ) ;
return V_114 ;
}
static inline void F_231 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_47 )
{
F_26 ( V_2 , V_469 , V_470 | V_83 ) ;
F_26 ( V_2 , V_471 , V_47 ) ;
F_26 ( V_2 , V_469 , V_472 | V_83 ) ;
}
static T_1 F_232 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_47 )
{
T_1 V_6 ;
F_231 ( V_2 , V_83 , V_47 ) ;
V_6 = F_25 ( V_2 , V_471 ) ;
F_26 ( V_2 , V_469 , 0x0000 ) ;
return V_6 ;
}
static void F_233 ( struct V_1 * V_2 , T_1 V_83 , T_1 V_47 , T_1 V_6 )
{
F_231 ( V_2 , V_83 , V_47 ) ;
F_26 ( V_2 , V_471 , V_6 ) ;
F_26 ( V_2 , V_469 , 0x0000 ) ;
}
static void F_234 ( struct V_1 * V_2 , bool V_284 )
{
T_1 V_473 , V_474 , V_475 ;
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_30 , V_476 ) ;
V_473 = F_25 ( V_2 , V_477 ) & ~ V_478 ;
V_474 = F_25 ( V_2 , V_479 ) ;
V_475 = F_25 ( V_2 , V_480 ) & ~ V_481 ;
if ( V_284 ) {
V_72 |= V_482 | V_483 ;
V_473 |= V_484 | V_485 | V_486 | V_487 ;
V_473 |= F_235 ( 1 ) ;
V_474 |= V_488 | V_489 ;
V_475 |= F_236 ( 42 ) ;
} else {
V_72 &= ~ ( V_482 | V_483 ) ;
V_473 &= ~ ( V_484 | V_485 | V_486 |
V_487 ) ;
V_473 |= F_235 ( 7 ) ;
V_474 &= ~ ( V_488 | V_489 ) ;
V_475 |= F_236 ( 511 ) ;
}
F_22 ( V_2 , V_30 , V_476 , V_72 ) ;
F_26 ( V_2 , V_477 , V_473 ) ;
F_26 ( V_2 , V_479 , V_474 ) ;
F_26 ( V_2 , V_480 , V_475 ) ;
}
static void F_237 ( struct V_1 * V_2 )
{
F_234 ( V_2 , true ) ;
F_233 ( V_2 , V_490 , V_491 , V_492 ) ;
}
static void F_238 ( struct V_1 * V_2 , bool V_284 )
{
V_21 V_72 ;
T_1 V_493 ;
V_72 = F_21 ( V_2 , V_30 , V_476 ) ;
V_493 = F_25 ( V_2 , V_394 ) ;
if ( V_284 ) {
V_72 |= V_482 | V_483 ;
V_493 |= V_494 ;
} else {
V_72 &= ~ ( V_482 | V_483 ) ;
V_493 &= ~ V_494 ;
}
F_22 ( V_2 , V_30 , V_476 , V_72 ) ;
F_26 ( V_2 , V_394 , V_493 ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
F_238 ( V_2 , true ) ;
F_26 ( V_2 , V_495 , V_496 | V_492 ) ;
}
static void F_240 ( struct V_1 * V_2 )
{
T_1 V_421 ;
V_421 = F_28 ( V_2 , V_423 ) ;
V_421 |= V_497 | V_498 ;
F_27 ( V_2 , V_423 , V_421 ) ;
}
static void F_241 ( struct V_1 * V_2 )
{
V_21 V_72 ;
V_72 = F_21 ( V_2 , V_30 , V_499 ) ;
V_72 |= V_500 ;
F_22 ( V_2 , V_30 , V_499 , V_72 ) ;
}
static void F_242 ( struct V_1 * V_2 )
{
V_21 V_72 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_196 ( V_2 , false ) ;
if ( V_2 -> V_84 == V_85 ) {
V_72 = F_21 ( V_2 , V_30 , V_501 ) ;
V_72 &= ~ V_502 ;
F_22 ( V_2 , V_30 , V_501 , V_72 ) ;
}
F_180 ( V_2 , false ) ;
V_72 = F_21 ( V_2 , V_30 , V_402 ) ;
V_72 |= V_503 | V_403 ;
F_22 ( V_2 , V_30 , V_402 , V_72 ) ;
V_72 = F_17 ( V_2 , V_30 , V_504 ) ;
V_72 &= ~ V_505 ;
V_72 |= V_506 | V_507 ;
F_19 ( V_2 , V_30 , V_504 , V_72 ) ;
V_72 = V_508 | V_509 |
V_510 | V_511 ;
F_22 ( V_2 , V_30 , V_512 , V_72 ) ;
F_237 ( V_2 ) ;
F_196 ( V_2 , true ) ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
V_72 = F_21 ( V_2 , V_31 , V_413 ) ;
V_72 &= ~ ( V_414 | V_415 ) ;
F_22 ( V_2 , V_31 , V_413 , V_72 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
V_21 V_72 ;
int V_127 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_204 ( V_2 , false ) ;
F_186 ( V_2 , false ) ;
for ( V_127 = 0 ; V_127 < 500 ; V_127 ++ ) {
if ( F_21 ( V_2 , V_30 , V_513 ) &
V_514 )
break;
F_193 ( 20 ) ;
}
for ( V_127 = 0 ; V_127 < 500 ; V_127 ++ ) {
V_72 = F_25 ( V_2 , V_515 ) & V_516 ;
if ( V_72 == V_517 || V_72 == V_518 )
break;
F_193 ( 20 ) ;
}
F_178 ( V_2 -> V_11 ) ;
F_187 ( V_2 , false ) ;
if ( V_2 -> V_84 == V_324 ) {
V_72 = F_21 ( V_2 , V_31 , V_519 ) ;
V_72 &= ~ V_520 ;
V_72 |= F_244 ( 96 ) ;
F_22 ( V_2 , V_31 , V_519 , V_72 ) ;
V_72 = F_23 ( V_2 , V_31 , V_521 ) ;
V_72 |= V_522 | V_523 ;
F_24 ( V_2 , V_31 , V_521 , V_72 ) ;
} else if ( V_2 -> V_84 == V_389 ) {
V_72 = F_23 ( V_2 , V_30 , V_524 ) ;
V_72 &= ~ V_525 ;
F_24 ( V_2 , V_30 , V_524 , V_72 ) ;
V_72 = F_23 ( V_2 , V_31 , V_526 ) ;
if ( F_21 ( V_2 , V_31 , V_527 ) == 0 )
V_72 &= ~ V_528 ;
else
V_72 |= V_528 ;
F_24 ( V_2 , V_31 , V_526 , V_72 ) ;
} else if ( V_2 -> V_84 == V_529 ) {
V_72 = F_23 ( V_2 , V_31 , V_526 ) ;
if ( F_21 ( V_2 , V_31 , V_527 ) == 0 )
V_72 &= ~ V_528 ;
else
V_72 |= V_528 ;
F_24 ( V_2 , V_31 , V_526 , V_72 ) ;
}
V_72 = F_23 ( V_2 , V_31 , V_530 ) ;
V_72 |= V_531 ;
F_24 ( V_2 , V_31 , V_530 , V_72 ) ;
V_72 = F_21 ( V_2 , V_31 , V_532 ) ;
V_72 &= ~ V_533 ;
F_22 ( V_2 , V_31 , V_532 , V_72 ) ;
V_72 = F_21 ( V_2 , V_30 , V_501 ) ;
V_72 &= ~ V_502 ;
F_22 ( V_2 , V_30 , V_501 , V_72 ) ;
V_72 = V_534 | V_535 ;
if ( V_2 -> V_84 == V_324 && V_2 -> V_11 -> V_280 < V_536 )
V_72 |= V_537 ;
else
V_72 |= V_538 ;
F_24 ( V_2 , V_31 , V_539 , V_72 ) ;
V_72 = F_21 ( V_2 , V_31 , V_540 ) ;
V_72 &= ~ V_541 ;
V_72 |= V_542 | V_543 ;
F_22 ( V_2 , V_31 , V_540 , V_72 ) ;
F_22 ( V_2 , V_31 , V_544 , 0x0001 ) ;
F_188 ( V_2 , false ) ;
F_186 ( V_2 , true ) ;
F_22 ( V_2 , V_30 , V_504 , 0 ) ;
F_22 ( V_2 , V_30 , V_545 , 0 ) ;
F_22 ( V_2 , V_30 , V_546 , 0 ) ;
F_22 ( V_2 , V_30 , V_547 , 0 ) ;
F_239 ( V_2 ) ;
F_204 ( V_2 , true ) ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
F_187 ( V_2 , true ) ;
}
static int F_245 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_246 ( V_56 ) ;
struct V_44 * V_45 ;
if ( ! V_2 )
return 0 ;
V_45 = V_2 -> V_45 ;
if ( ! F_222 ( V_45 ) )
return 0 ;
F_217 ( & V_2 -> V_97 ) ;
F_141 ( V_91 , & V_2 -> V_18 ) ;
F_172 ( V_2 -> V_133 ) ;
F_208 ( & V_2 -> V_123 ) ;
if ( F_50 ( V_45 ) ) {
F_153 ( V_45 ) ;
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_449 . V_450 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
}
return 0 ;
}
static int F_247 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_246 ( V_56 ) ;
struct V_44 * V_45 ;
if ( ! V_2 )
return 0 ;
V_45 = V_2 -> V_45 ;
if ( ! F_222 ( V_45 ) )
return 0 ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
if ( F_50 ( V_45 ) ) {
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_449 . V_284 ( V_2 ) ;
F_151 ( V_45 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_125 ( V_45 ) ;
}
F_219 ( & V_2 -> V_97 ) ;
return 0 ;
}
static bool F_248 ( struct V_1 * V_2 )
{
bool V_548 = ! ! F_50 ( V_2 -> V_45 ) ;
bool V_549 = ! ! ( F_167 ( V_2 ) & V_448 ) ;
if ( F_249 ( & V_2 -> V_123 . V_452 ) || V_548 != V_549 )
return true ;
if ( ! V_548 && V_2 -> V_449 . V_550 ( V_2 ) )
return true ;
else
return false ;
}
static int F_250 ( struct V_135 * V_56 , T_9 V_551 )
{
struct V_1 * V_2 = F_246 ( V_56 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
int V_7 = 0 ;
F_36 ( & V_2 -> V_57 ) ;
if ( F_251 ( V_551 ) ) {
if ( F_222 ( V_45 ) && F_248 ( V_2 ) ) {
V_7 = - V_552 ;
goto V_55;
}
F_11 ( V_270 , & V_2 -> V_18 ) ;
} else {
F_56 ( V_45 ) ;
}
if ( F_222 ( V_45 ) && F_10 ( V_91 , & V_2 -> V_18 ) ) {
F_141 ( V_91 , & V_2 -> V_18 ) ;
F_172 ( V_2 -> V_133 ) ;
F_217 ( & V_2 -> V_97 ) ;
if ( F_10 ( V_270 , & V_2 -> V_18 ) ) {
F_171 ( V_2 ) ;
V_2 -> V_449 . V_553 ( V_2 , true ) ;
} else {
F_208 ( & V_2 -> V_123 ) ;
V_2 -> V_449 . V_468 ( V_2 ) ;
}
F_219 ( & V_2 -> V_97 ) ;
}
V_55:
F_37 ( & V_2 -> V_57 ) ;
return V_7 ;
}
static int F_252 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_246 ( V_56 ) ;
F_36 ( & V_2 -> V_57 ) ;
if ( ! F_10 ( V_270 , & V_2 -> V_18 ) ) {
V_2 -> V_449 . V_554 ( V_2 ) ;
F_253 ( V_2 -> V_45 ) ;
}
if ( F_222 ( V_2 -> V_45 ) && V_2 -> V_45 -> V_18 & V_555 ) {
if ( F_10 ( V_270 , & V_2 -> V_18 ) ) {
V_2 -> V_449 . V_553 ( V_2 , false ) ;
F_141 ( V_270 , & V_2 -> V_18 ) ;
F_217 ( & V_2 -> V_97 ) ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
if ( F_50 ( V_2 -> V_45 ) )
F_170 ( V_2 ) ;
F_219 ( & V_2 -> V_97 ) ;
} else {
V_2 -> V_449 . V_464 ( V_2 ) ;
F_207 ( V_2 , V_465 ,
V_2 -> V_428 . V_429 ?
V_437 : V_435 ,
V_439 ) ;
F_220 ( V_2 -> V_45 ) ;
F_11 ( V_91 , & V_2 -> V_18 ) ;
}
F_66 ( V_2 -> V_133 , V_9 ) ;
} else if ( F_10 ( V_270 , & V_2 -> V_18 ) ) {
if ( V_2 -> V_45 -> V_18 & V_555 )
V_2 -> V_449 . V_553 ( V_2 , false ) ;
F_141 ( V_270 , & V_2 -> V_18 ) ;
}
F_37 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int F_254 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_246 ( V_56 ) ;
F_141 ( V_270 , & V_2 -> V_18 ) ;
return F_252 ( V_56 ) ;
}
static void F_255 ( struct V_44 * V_83 , struct V_556 * V_557 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
if ( ! F_189 ( V_2 ) ) {
V_557 -> V_558 = 0 ;
V_557 -> V_305 = 0 ;
} else {
F_36 ( & V_2 -> V_57 ) ;
V_557 -> V_558 = V_319 ;
V_557 -> V_305 = F_183 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
}
F_38 ( V_2 -> V_56 ) ;
}
static int F_256 ( struct V_44 * V_83 , struct V_556 * V_557 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
if ( ! F_189 ( V_2 ) )
return - V_559 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_560;
F_36 ( & V_2 -> V_57 ) ;
F_184 ( V_2 , V_557 -> V_305 ) ;
V_2 -> V_335 = V_557 -> V_305 & V_319 ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_560:
return V_7 ;
}
static V_21 F_257 ( struct V_44 * V_83 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
return V_2 -> V_561 ;
}
static void F_258 ( struct V_44 * V_83 , V_21 V_3 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
V_2 -> V_561 = V_3 ;
}
static void F_259 ( struct V_44 * V_45 ,
struct V_562 * V_563 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
F_260 ( V_563 -> V_564 , V_565 , sizeof( V_563 -> V_564 ) ) ;
F_260 ( V_563 -> V_84 , V_566 , sizeof( V_563 -> V_84 ) ) ;
F_261 ( V_2 -> V_11 , V_563 -> V_567 , sizeof( V_563 -> V_567 ) ) ;
}
static
int F_262 ( struct V_44 * V_45 , struct V_568 * V_569 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_7 ;
if ( ! V_2 -> V_428 . V_570 )
return - V_559 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_303;
F_36 ( & V_2 -> V_57 ) ;
V_7 = F_263 ( & V_2 -> V_428 , V_569 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_7 ;
}
static int F_264 ( struct V_44 * V_83 , struct V_568 * V_569 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_303;
F_36 ( & V_2 -> V_57 ) ;
V_7 = F_207 ( V_2 , V_569 -> V_418 , V_569 -> V_280 , V_569 -> V_419 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_7 ;
}
static int F_265 ( struct V_44 * V_83 , int V_571 )
{
switch ( V_571 ) {
case V_572 :
return F_266 ( V_573 ) ;
default:
return - V_559 ;
}
}
static void F_267 ( struct V_44 * V_83 ,
struct V_574 * V_103 , T_10 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
struct V_575 V_576 ;
if ( F_35 ( V_2 -> V_56 ) < 0 )
return;
F_9 ( V_2 , V_577 , sizeof( V_576 ) , & V_576 , V_30 ) ;
F_38 ( V_2 -> V_56 ) ;
V_6 [ 0 ] = F_268 ( V_576 . V_107 ) ;
V_6 [ 1 ] = F_268 ( V_576 . V_237 ) ;
V_6 [ 2 ] = F_268 ( V_576 . V_105 ) ;
V_6 [ 3 ] = F_108 ( V_576 . V_578 ) ;
V_6 [ 4 ] = F_269 ( V_576 . V_579 ) ;
V_6 [ 5 ] = F_269 ( V_576 . V_580 ) ;
V_6 [ 6 ] = F_108 ( V_576 . V_581 ) ;
V_6 [ 7 ] = F_108 ( V_576 . V_582 ) ;
V_6 [ 8 ] = F_268 ( V_576 . V_583 ) ;
V_6 [ 9 ] = F_268 ( V_576 . V_584 ) ;
V_6 [ 10 ] = F_108 ( V_576 . V_585 ) ;
V_6 [ 11 ] = F_269 ( V_576 . V_586 ) ;
V_6 [ 12 ] = F_269 ( V_576 . V_587 ) ;
}
static void F_270 ( struct V_44 * V_83 , V_21 V_588 , T_3 * V_6 )
{
switch ( V_588 ) {
case V_572 :
memcpy ( V_6 , * V_573 , sizeof( V_573 ) ) ;
break;
}
}
static int F_271 ( struct V_1 * V_2 , struct V_589 * V_590 )
{
V_21 V_72 , V_591 , V_592 , V_558 = 0 ;
T_1 V_50 ;
V_50 = F_232 ( V_2 , V_593 , V_594 ) ;
V_558 = F_272 ( V_50 ) ;
V_50 = F_232 ( V_2 , V_490 , V_491 ) ;
V_592 = F_273 ( V_50 ) ;
V_50 = F_232 ( V_2 , V_490 , V_595 ) ;
V_591 = F_273 ( V_50 ) ;
V_72 = F_21 ( V_2 , V_30 , V_476 ) ;
V_72 &= V_482 | V_483 ;
V_590 -> V_596 = ! ! V_72 ;
V_590 -> V_597 = ! ! ( V_558 & V_592 & V_591 ) ;
V_590 -> V_558 = V_558 ;
V_590 -> V_598 = V_592 ;
V_590 -> V_599 = V_591 ;
return 0 ;
}
static int F_274 ( struct V_1 * V_2 , struct V_589 * V_590 )
{
T_1 V_50 = F_275 ( V_590 -> V_598 ) ;
F_234 ( V_2 , V_590 -> V_596 ) ;
if ( ! V_590 -> V_596 )
V_50 = 0 ;
F_233 ( V_2 , V_490 , V_491 , V_50 ) ;
return 0 ;
}
static int F_276 ( struct V_1 * V_2 , struct V_589 * V_590 )
{
V_21 V_72 , V_591 , V_592 , V_558 = 0 ;
T_1 V_50 ;
V_50 = F_25 ( V_2 , V_600 ) ;
V_558 = F_272 ( V_50 ) ;
V_50 = F_25 ( V_2 , V_495 ) ;
V_592 = F_273 ( V_50 ) ;
V_50 = F_25 ( V_2 , V_601 ) ;
V_591 = F_273 ( V_50 ) ;
V_72 = F_21 ( V_2 , V_30 , V_476 ) ;
V_72 &= V_482 | V_483 ;
V_590 -> V_596 = ! ! V_72 ;
V_590 -> V_597 = ! ! ( V_558 & V_592 & V_591 ) ;
V_590 -> V_558 = V_558 ;
V_590 -> V_598 = V_592 ;
V_590 -> V_599 = V_591 ;
return 0 ;
}
static int F_277 ( struct V_1 * V_2 , struct V_589 * V_590 )
{
T_1 V_50 = F_275 ( V_590 -> V_598 ) ;
F_238 ( V_2 , V_590 -> V_596 ) ;
if ( ! V_590 -> V_596 )
V_50 = 0 ;
F_26 ( V_2 , V_495 , V_50 ) ;
return 0 ;
}
static int
F_278 ( struct V_44 * V_602 , struct V_589 * V_603 )
{
struct V_1 * V_2 = F_31 ( V_602 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_303;
F_36 ( & V_2 -> V_57 ) ;
V_7 = V_2 -> V_449 . V_604 ( V_2 , V_603 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_7 ;
}
static int
F_279 ( struct V_44 * V_602 , struct V_589 * V_603 )
{
struct V_1 * V_2 = F_31 ( V_602 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_303;
F_36 ( & V_2 -> V_57 ) ;
V_7 = V_2 -> V_449 . V_605 ( V_2 , V_603 ) ;
if ( ! V_7 )
V_7 = F_280 ( & V_2 -> V_428 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_7 ;
}
static int F_281 ( struct V_44 * V_83 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
goto V_303;
F_36 ( & V_2 -> V_57 ) ;
V_7 = F_280 ( & V_2 -> V_428 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_7 ;
}
static int F_282 ( struct V_44 * V_45 ,
struct V_606 * V_289 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_607 :
return - V_559 ;
default:
break;
}
V_289 -> V_608 = V_2 -> V_289 ;
return 0 ;
}
static int F_283 ( struct V_44 * V_45 ,
struct V_606 * V_289 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
int V_7 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_607 :
return - V_559 ;
default:
break;
}
if ( V_289 -> V_608 > V_609 )
return - V_49 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
F_36 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_289 != V_289 -> V_608 ) {
V_2 -> V_289 = V_289 -> V_608 ;
if ( F_222 ( V_2 -> V_45 ) && F_50 ( V_45 ) )
F_175 ( V_2 ) ;
}
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
return V_7 ;
}
static int F_284 ( struct V_44 * V_45 , struct V_610 * V_611 , int V_569 )
{
struct V_1 * V_2 = F_31 ( V_45 ) ;
struct V_612 * V_6 = F_285 ( V_611 ) ;
int V_114 ;
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
V_114 = F_35 ( V_2 -> V_56 ) ;
if ( V_114 < 0 )
goto V_303;
switch ( V_569 ) {
case V_613 :
V_6 -> V_46 = V_48 ;
break;
case V_614 :
F_36 ( & V_2 -> V_57 ) ;
V_6 -> V_615 = F_28 ( V_2 , V_6 -> V_616 ) ;
F_37 ( & V_2 -> V_57 ) ;
break;
case V_617 :
if ( ! F_286 ( V_618 ) ) {
V_114 = - V_20 ;
break;
}
F_36 ( & V_2 -> V_57 ) ;
F_27 ( V_2 , V_6 -> V_616 , V_6 -> V_619 ) ;
F_37 ( & V_2 -> V_57 ) ;
break;
default:
V_114 = - V_559 ;
}
F_38 ( V_2 -> V_56 ) ;
V_303:
return V_114 ;
}
static int F_287 ( struct V_44 * V_83 , int V_620 )
{
struct V_1 * V_2 = F_31 ( V_83 ) ;
int V_7 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_607 :
return F_288 ( V_83 , V_620 ) ;
default:
break;
}
if ( V_620 < 68 || V_620 > V_621 )
return - V_49 ;
V_7 = F_35 ( V_2 -> V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
F_36 ( & V_2 -> V_57 ) ;
V_83 -> V_276 = V_620 ;
if ( F_222 ( V_83 ) && F_50 ( V_83 ) )
F_176 ( V_2 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( V_2 -> V_56 ) ;
return V_7 ;
}
static void F_289 ( struct V_1 * V_2 )
{
V_21 V_72 ;
T_1 V_84 ;
V_72 = F_21 ( V_2 , V_30 , V_622 ) ;
V_84 = ( T_1 ) ( V_72 & V_623 ) ;
switch ( V_84 ) {
case 0x4c00 :
V_2 -> V_84 = V_85 ;
break;
case 0x4c10 :
V_2 -> V_84 = V_607 ;
break;
case 0x5c00 :
V_2 -> V_84 = V_323 ;
V_2 -> V_428 . V_429 = 1 ;
break;
case 0x5c10 :
V_2 -> V_84 = V_324 ;
V_2 -> V_428 . V_429 = 1 ;
break;
case 0x5c20 :
V_2 -> V_84 = V_389 ;
V_2 -> V_428 . V_429 = 1 ;
break;
case 0x5c30 :
V_2 -> V_84 = V_529 ;
V_2 -> V_428 . V_429 = 1 ;
break;
default:
F_45 ( V_2 , V_81 , V_2 -> V_45 ,
L_27 , V_84 ) ;
break;
}
}
static void F_290 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
if ( V_2 -> V_84 != V_85 )
F_180 ( V_2 , true ) ;
}
static void F_291 ( struct V_1 * V_2 )
{
if ( F_10 ( V_17 , & V_2 -> V_18 ) )
return;
F_188 ( V_2 , false ) ;
}
static int F_292 ( struct V_1 * V_2 )
{
struct V_449 * V_624 = & V_2 -> V_449 ;
int V_7 = 0 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_607 :
V_624 -> V_554 = F_242 ;
V_624 -> V_284 = F_174 ;
V_624 -> V_450 = F_197 ;
V_624 -> V_464 = F_210 ;
V_624 -> V_468 = F_211 ;
V_624 -> V_625 = F_290 ;
V_624 -> V_604 = F_271 ;
V_624 -> V_605 = F_274 ;
V_624 -> V_550 = F_214 ;
V_624 -> V_553 = F_190 ;
break;
case V_323 :
case V_324 :
case V_389 :
case V_529 :
V_624 -> V_554 = F_243 ;
V_624 -> V_284 = F_177 ;
V_624 -> V_450 = F_205 ;
V_624 -> V_464 = F_212 ;
V_624 -> V_468 = F_213 ;
V_624 -> V_625 = F_291 ;
V_624 -> V_604 = F_276 ;
V_624 -> V_605 = F_277 ;
V_624 -> V_550 = F_215 ;
V_624 -> V_553 = F_191 ;
break;
default:
V_7 = - V_19 ;
F_47 ( V_2 , V_81 , V_2 -> V_45 , L_28 ) ;
break;
}
return V_7 ;
}
static int F_293 ( struct V_135 * V_56 ,
const struct V_626 * V_627 )
{
struct V_330 * V_11 = F_294 ( V_56 ) ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_7 ;
if ( V_11 -> V_331 -> V_149 . V_628 != 1 ) {
F_295 ( V_11 , 1 ) ;
return - V_19 ;
}
F_296 ( V_11 ) ;
V_45 = F_297 ( sizeof( struct V_1 ) ) ;
if ( ! V_45 ) {
F_298 ( & V_56 -> V_83 , L_29 ) ;
return - V_10 ;
}
F_299 ( V_45 , & V_56 -> V_83 ) ;
V_2 = F_31 ( V_45 ) ;
V_2 -> V_561 = 0x7FFF ;
V_2 -> V_11 = V_11 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_56 = V_56 ;
F_289 ( V_2 ) ;
V_7 = F_292 ( V_2 ) ;
if ( V_7 )
goto V_303;
F_300 ( & V_2 -> V_57 ) ;
F_301 ( & V_2 -> V_123 , F_221 ) ;
V_45 -> V_629 = & V_630 ;
V_45 -> V_631 = V_632 ;
V_45 -> V_158 |= V_633 | V_634 | V_162 |
V_635 | V_636 | V_163 |
V_164 | V_304 |
V_637 ;
V_45 -> V_638 = V_633 | V_634 | V_162 |
V_635 | V_636 |
V_163 | V_164 |
V_304 | V_637 ;
V_45 -> V_639 = V_162 | V_634 | V_635 |
V_640 | V_636 |
V_163 | V_164 ;
V_45 -> V_641 = & V_624 ;
F_302 ( V_45 , V_642 ) ;
V_2 -> V_428 . V_83 = V_45 ;
V_2 -> V_428 . V_570 = F_30 ;
V_2 -> V_428 . V_643 = F_32 ;
V_2 -> V_428 . V_644 = 0x3f ;
V_2 -> V_428 . V_645 = 0x1f ;
V_2 -> V_428 . V_46 = V_48 ;
switch ( V_11 -> V_280 ) {
case V_536 :
case V_646 :
V_2 -> V_289 = V_647 ;
break;
case V_648 :
V_2 -> V_289 = V_649 ;
break;
default:
V_2 -> V_289 = V_609 ;
break;
}
V_56 -> V_650 = 1 ;
V_2 -> V_449 . V_554 ( V_2 ) ;
F_46 ( V_2 ) ;
F_303 ( V_56 , V_2 ) ;
F_304 ( V_45 , & V_2 -> V_97 , F_142 , V_651 ) ;
V_7 = F_305 ( V_45 ) ;
if ( V_7 != 0 ) {
F_47 ( V_2 , V_81 , V_45 , L_30 ) ;
goto V_55;
}
if ( ! F_189 ( V_2 ) )
F_184 ( V_2 , 0 ) ;
V_2 -> V_335 = F_183 ( V_2 ) ;
if ( V_2 -> V_335 )
F_185 ( & V_11 -> V_83 , true ) ;
else
F_185 ( & V_11 -> V_83 , false ) ;
F_45 ( V_2 , V_81 , V_45 , L_31 , V_566 ) ;
return 0 ;
V_55:
F_306 ( & V_2 -> V_97 ) ;
F_303 ( V_56 , NULL ) ;
V_303:
F_307 ( V_45 ) ;
return V_7 ;
}
static void F_308 ( struct V_135 * V_56 )
{
struct V_1 * V_2 = F_246 ( V_56 ) ;
F_303 ( V_56 , NULL ) ;
if ( V_2 ) {
struct V_330 * V_11 = V_2 -> V_11 ;
if ( V_11 -> V_652 == V_653 )
F_11 ( V_17 , & V_2 -> V_18 ) ;
F_306 ( & V_2 -> V_97 ) ;
F_309 ( V_2 -> V_45 ) ;
V_2 -> V_449 . V_625 ( V_2 ) ;
F_307 ( V_2 -> V_45 ) ;
}
}
