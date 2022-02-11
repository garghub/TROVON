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
V_8 = F_2 ( V_5 , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
memcpy ( V_8 , V_6 , V_5 ) ;
V_7 = F_3 ( V_2 -> V_11 , F_7 ( V_2 -> V_11 , 0 ) ,
V_14 , V_15 ,
V_3 , V_4 , V_8 , V_5 , 500 ) ;
F_5 ( V_8 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 ,
void * V_6 , T_1 type )
{
T_1 V_16 = 64 ;
int V_7 = 0 ;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
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
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 ,
T_1 V_5 , void * V_6 , T_1 type )
{
int V_7 ;
T_1 V_23 , V_24 , V_25 ;
T_1 V_16 = 512 ;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
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
return V_7 ;
}
static inline
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_8 ( V_2 , V_4 , V_5 , V_6 , V_30 ) ;
}
static inline
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_10 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_30 ) ;
}
static inline
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 , void * V_6 )
{
return F_8 ( V_2 , V_4 , V_5 , V_6 , V_31 ) ;
}
static inline
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_22 , T_1 V_5 , void * V_6 )
{
return F_10 ( V_2 , V_4 , V_22 , V_5 , V_6 , V_31 ) ;
}
static V_21 F_15 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
T_2 V_6 ;
F_8 ( V_2 , V_4 , sizeof( V_6 ) , & V_6 , type ) ;
return F_16 ( V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
{
T_2 V_8 = F_18 ( V_6 ) ;
F_10 ( V_2 , V_4 , V_29 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_32 = V_4 & 2 ;
V_4 &= ~ 3 ;
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_16 ( V_8 ) ;
V_6 >>= ( V_32 * 8 ) ;
V_6 &= 0xffff ;
return ( T_1 ) V_6 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
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
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 |= F_16 ( V_8 ) & ~ V_33 ;
V_8 = F_18 ( V_6 ) ;
F_10 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static T_3 F_21 ( struct V_1 * V_2 , T_1 type , T_1 V_4 )
{
V_21 V_6 ;
T_2 V_8 ;
T_3 V_32 = V_4 & 3 ;
V_4 &= ~ 3 ;
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 = F_16 ( V_8 ) ;
V_6 >>= ( V_32 * 8 ) ;
V_6 &= 0xff ;
return ( T_3 ) V_6 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 type , T_1 V_4 , V_21 V_6 )
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
F_8 ( V_2 , V_4 , sizeof( V_8 ) , & V_8 , type ) ;
V_6 |= F_16 ( V_8 ) & ~ V_33 ;
V_8 = F_18 ( V_6 ) ;
F_10 ( V_2 , V_4 , V_25 , sizeof( V_8 ) , & V_8 , type ) ;
}
static void F_23 ( struct V_1 * V_2 , V_21 V_36 , V_21 V_3 )
{
V_21 V_37 ;
int V_38 ;
V_37 = V_39 | ( ( V_36 & 0x1f ) << 16 ) |
( V_3 & 0xffff ) ;
F_17 ( V_2 , V_30 , V_40 , V_37 ) ;
for ( V_38 = 20 ; V_38 > 0 ; V_38 -- ) {
F_24 ( 25 ) ;
V_37 = F_15 ( V_2 , V_30 , V_40 ) ;
if ( ! ( V_37 & V_39 ) )
break;
}
F_24 ( 20 ) ;
}
static int F_25 ( struct V_1 * V_2 , V_21 V_36 )
{
V_21 V_37 ;
int V_38 ;
V_37 = ( V_36 & 0x1f ) << 16 ;
F_17 ( V_2 , V_30 , V_40 , V_37 ) ;
for ( V_38 = 20 ; V_38 > 0 ; V_38 -- ) {
F_24 ( 25 ) ;
V_37 = F_15 ( V_2 , V_30 , V_40 ) ;
if ( V_37 & V_39 )
break;
}
F_24 ( 20 ) ;
if ( ! ( V_37 & V_39 ) )
return - V_41 ;
return ( T_1 ) ( V_37 & 0xffff ) ;
}
static int F_26 ( struct V_42 * V_43 , int V_44 , int V_45 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( V_44 != V_46 )
return - V_47 ;
return F_25 ( V_2 , V_45 ) ;
}
static
void F_28 ( struct V_42 * V_43 , int V_44 , int V_45 , int V_48 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( V_44 != V_46 )
return;
F_23 ( V_2 , V_45 , V_48 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_49 , T_1 V_6 )
{
T_1 V_50 , V_51 ;
V_50 = V_49 & 0xf000 ;
if ( V_50 != V_2 -> V_50 ) {
F_20 ( V_2 , V_30 , V_52 , V_50 ) ;
V_2 -> V_50 = V_50 ;
}
V_51 = ( V_49 & 0x0fff ) | 0xb000 ;
F_20 ( V_2 , V_30 , V_51 , V_6 ) ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
struct V_42 * V_53 = V_2 -> V_43 ;
T_3 V_54 [ 8 ] = { 0 } ;
if ( F_11 ( V_2 , V_55 , sizeof( V_54 ) , V_54 ) < 0 )
F_31 ( V_2 , V_56 , V_53 , L_1 ) ;
else {
memcpy ( V_53 -> V_57 , V_54 , V_53 -> V_58 ) ;
memcpy ( V_53 -> V_59 , V_53 -> V_57 , V_53 -> V_58 ) ;
}
}
static int F_32 ( struct V_42 * V_43 , void * V_60 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_61 * V_49 = V_60 ;
if ( ! F_33 ( V_49 -> V_62 ) )
return - V_63 ;
memcpy ( V_43 -> V_57 , V_49 -> V_62 , V_43 -> V_58 ) ;
F_22 ( V_2 , V_30 , V_64 , V_65 ) ;
F_12 ( V_2 , V_55 , V_66 , 8 , V_49 -> V_62 ) ;
F_22 ( V_2 , V_30 , V_64 , V_67 ) ;
return 0 ;
}
static struct V_68 * F_34 ( struct V_42 * V_53 )
{
return & V_53 -> V_69 ;
}
static void F_35 ( struct V_70 * V_70 )
{
struct V_42 * V_43 ;
unsigned long V_18 ;
int V_71 = V_70 -> V_71 ;
struct V_72 * V_73 ;
struct V_1 * V_2 ;
int V_74 ;
V_73 = V_70 -> V_75 ;
if ( ! V_73 )
return;
V_2 = V_73 -> V_75 ;
if ( ! V_2 )
return;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_9 ( V_76 , & V_2 -> V_18 ) )
return;
V_43 = V_2 -> V_43 ;
if ( ! F_36 ( V_43 ) )
return;
switch ( V_71 ) {
case 0 :
if ( V_70 -> V_77 < V_78 )
break;
F_37 ( & V_2 -> V_79 , V_18 ) ;
F_38 ( & V_73 -> V_80 , & V_2 -> V_81 ) ;
F_39 ( & V_2 -> V_79 , V_18 ) ;
F_40 ( & V_2 -> V_82 ) ;
return;
case - V_83 :
F_41 ( V_17 , & V_2 -> V_18 ) ;
F_42 ( V_2 -> V_43 ) ;
return;
case - V_84 :
return;
case - V_85 :
F_43 ( L_2 ) ;
break;
default:
F_43 ( L_3 , V_71 ) ;
break;
}
V_74 = F_44 ( V_2 , V_73 , V_86 ) ;
if ( V_74 == - V_19 ) {
F_42 ( V_2 -> V_43 ) ;
} else if ( V_74 ) {
F_37 ( & V_2 -> V_79 , V_18 ) ;
F_38 ( & V_73 -> V_80 , & V_2 -> V_81 ) ;
F_39 ( & V_2 -> V_79 , V_18 ) ;
F_40 ( & V_2 -> V_82 ) ;
}
}
static void F_45 ( struct V_70 * V_70 )
{
struct V_68 * V_69 ;
unsigned long V_18 ;
struct V_87 * V_73 ;
struct V_1 * V_2 ;
int V_71 = V_70 -> V_71 ;
V_73 = V_70 -> V_75 ;
if ( ! V_73 )
return;
V_2 = V_73 -> V_75 ;
if ( ! V_2 )
return;
V_69 = F_34 ( V_2 -> V_43 ) ;
if ( V_71 ) {
F_43 ( L_4 , V_71 ) ;
V_69 -> V_88 += V_73 -> V_89 ;
} else {
V_69 -> V_90 += V_73 -> V_89 ;
V_69 -> V_91 += V_73 -> V_92 ;
}
F_37 ( & V_2 -> V_93 , V_18 ) ;
F_38 ( & V_73 -> V_80 , & V_2 -> V_94 ) ;
F_39 ( & V_2 -> V_93 , V_18 ) ;
if ( ! F_36 ( V_2 -> V_43 ) )
return;
if ( ! F_9 ( V_76 , & V_2 -> V_18 ) )
return;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_46 ( & V_2 -> V_95 ) )
F_40 ( & V_2 -> V_82 ) ;
}
static void F_47 ( struct V_70 * V_70 )
{
struct V_1 * V_2 ;
T_4 * V_96 ;
int V_71 = V_70 -> V_71 ;
int V_97 ;
V_2 = V_70 -> V_75 ;
if ( ! V_2 )
return;
if ( ! F_9 ( V_76 , & V_2 -> V_18 ) )
return;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return;
switch ( V_71 ) {
case 0 :
break;
case - V_98 :
case - V_83 :
F_42 ( V_2 -> V_43 ) ;
case - V_84 :
return;
case - V_99 :
F_48 ( V_2 , V_100 , V_2 -> V_43 , L_5 ) ;
goto V_101;
default:
F_48 ( V_2 , V_100 , V_2 -> V_43 , L_6 , V_71 ) ;
goto V_101;
}
V_96 = V_70 -> V_102 ;
if ( V_103 & F_49 ( V_96 [ 0 ] ) ) {
if ( ! ( V_2 -> V_104 & V_105 ) ) {
F_41 ( V_106 , & V_2 -> V_18 ) ;
F_50 ( & V_2 -> V_107 , 0 ) ;
}
} else {
if ( V_2 -> V_104 & V_105 ) {
F_41 ( V_106 , & V_2 -> V_18 ) ;
F_50 ( & V_2 -> V_107 , 0 ) ;
}
}
V_101:
V_97 = F_51 ( V_70 , V_86 ) ;
if ( V_97 == - V_19 )
F_42 ( V_2 -> V_43 ) ;
else if ( V_97 )
F_52 ( V_2 , V_100 , V_2 -> V_43 ,
L_7 , V_97 ) ;
}
static inline void * F_53 ( void * V_6 )
{
return ( void * ) F_54 ( ( V_108 ) V_6 , 8 ) ;
}
static inline void * F_55 ( void * V_6 )
{
return ( void * ) F_54 ( ( V_108 ) V_6 , 4 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_109 ; V_38 ++ ) {
if ( V_2 -> V_110 [ V_38 ] . V_70 ) {
F_57 ( V_2 -> V_110 [ V_38 ] . V_70 ) ;
V_2 -> V_110 [ V_38 ] . V_70 = NULL ;
}
if ( V_2 -> V_110 [ V_38 ] . V_111 ) {
F_5 ( V_2 -> V_110 [ V_38 ] . V_111 ) ;
V_2 -> V_110 [ V_38 ] . V_111 = NULL ;
V_2 -> V_110 [ V_38 ] . V_112 = NULL ;
}
}
for ( V_38 = 0 ; V_38 < V_113 ; V_38 ++ ) {
if ( V_2 -> V_114 [ V_38 ] . V_70 ) {
F_57 ( V_2 -> V_114 [ V_38 ] . V_70 ) ;
V_2 -> V_114 [ V_38 ] . V_70 = NULL ;
}
if ( V_2 -> V_114 [ V_38 ] . V_111 ) {
F_5 ( V_2 -> V_114 [ V_38 ] . V_111 ) ;
V_2 -> V_114 [ V_38 ] . V_111 = NULL ;
V_2 -> V_114 [ V_38 ] . V_112 = NULL ;
}
}
if ( V_2 -> V_115 ) {
F_57 ( V_2 -> V_115 ) ;
V_2 -> V_115 = NULL ;
}
if ( V_2 -> V_116 ) {
F_5 ( V_2 -> V_116 ) ;
V_2 -> V_116 = NULL ;
}
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_117 * V_118 = V_2 -> V_118 ;
struct V_119 * V_120 = V_118 -> V_121 ;
struct V_122 * V_123 = V_120 -> V_124 + 2 ;
struct V_70 * V_70 ;
int V_125 , V_38 ;
T_3 * V_126 ;
V_125 = V_43 -> V_53 . V_127 ? F_59 ( V_43 -> V_53 . V_127 ) : - 1 ;
F_60 ( & V_2 -> V_79 ) ;
F_60 ( & V_2 -> V_93 ) ;
F_61 ( & V_2 -> V_81 ) ;
F_61 ( & V_2 -> V_94 ) ;
F_62 ( & V_2 -> V_95 ) ;
for ( V_38 = 0 ; V_38 < V_109 ; V_38 ++ ) {
V_126 = F_63 ( V_128 , V_9 , V_125 ) ;
if ( ! V_126 )
goto V_129;
if ( V_126 != F_53 ( V_126 ) ) {
F_5 ( V_126 ) ;
V_126 = F_63 ( V_128 + 8 , V_9 , V_125 ) ;
if ( ! V_126 )
goto V_129;
}
V_70 = F_64 ( 0 , V_9 ) ;
if ( ! V_70 ) {
F_5 ( V_126 ) ;
goto V_129;
}
F_61 ( & V_2 -> V_110 [ V_38 ] . V_80 ) ;
V_2 -> V_110 [ V_38 ] . V_75 = V_2 ;
V_2 -> V_110 [ V_38 ] . V_70 = V_70 ;
V_2 -> V_110 [ V_38 ] . V_111 = V_126 ;
V_2 -> V_110 [ V_38 ] . V_112 = F_53 ( V_126 ) ;
}
for ( V_38 = 0 ; V_38 < V_113 ; V_38 ++ ) {
V_126 = F_63 ( V_128 , V_9 , V_125 ) ;
if ( ! V_126 )
goto V_129;
if ( V_126 != F_55 ( V_126 ) ) {
F_5 ( V_126 ) ;
V_126 = F_63 ( V_128 + 4 , V_9 , V_125 ) ;
if ( ! V_126 )
goto V_129;
}
V_70 = F_64 ( 0 , V_9 ) ;
if ( ! V_70 ) {
F_5 ( V_126 ) ;
goto V_129;
}
F_61 ( & V_2 -> V_114 [ V_38 ] . V_80 ) ;
V_2 -> V_114 [ V_38 ] . V_75 = V_2 ;
V_2 -> V_114 [ V_38 ] . V_70 = V_70 ;
V_2 -> V_114 [ V_38 ] . V_111 = V_126 ;
V_2 -> V_114 [ V_38 ] . V_112 = F_55 ( V_126 ) ;
F_38 ( & V_2 -> V_114 [ V_38 ] . V_80 , & V_2 -> V_94 ) ;
}
V_2 -> V_115 = F_64 ( 0 , V_9 ) ;
if ( ! V_2 -> V_115 )
goto V_129;
V_2 -> V_116 = F_2 ( V_130 , V_9 ) ;
if ( ! V_2 -> V_116 )
goto V_129;
V_2 -> V_131 = ( int ) V_123 -> V_132 . V_133 ;
F_65 ( V_2 -> V_115 , V_2 -> V_11 , F_66 ( V_2 -> V_11 , 3 ) ,
V_2 -> V_116 , V_130 , F_47 ,
V_2 , V_2 -> V_131 ) ;
return 0 ;
V_129:
F_56 ( V_2 ) ;
return - V_10 ;
}
static struct V_87 * F_67 ( struct V_1 * V_2 )
{
struct V_87 * V_73 = NULL ;
unsigned long V_18 ;
F_37 ( & V_2 -> V_93 , V_18 ) ;
if ( ! F_68 ( & V_2 -> V_94 ) ) {
struct V_134 * V_135 ;
V_135 = V_2 -> V_94 . V_136 ;
F_69 ( V_135 ) ;
V_73 = F_70 ( V_135 , struct V_87 , V_80 ) ;
}
F_39 ( & V_2 -> V_93 , V_18 ) ;
return V_73 ;
}
static void
F_71 ( struct V_1 * V_2 , struct V_137 * V_132 , struct V_138 * V_139 )
{
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
V_132 -> V_140 = F_72 ( ( V_139 -> V_141 & V_142 ) | V_143 | V_144 ) ;
if ( V_139 -> V_145 == V_146 ) {
T_5 V_147 ;
T_3 V_148 ;
V_21 V_149 = 0 ;
if ( V_139 -> V_147 == F_73 ( V_150 ) )
V_147 = F_74 ( V_139 ) -> V_151 ;
else
V_147 = V_139 -> V_147 ;
switch ( V_147 ) {
case F_73 ( V_152 ) :
V_149 |= V_153 ;
V_148 = F_75 ( V_139 ) -> V_147 ;
break;
case F_73 ( V_154 ) :
V_149 |= V_155 ;
V_148 = F_76 ( V_139 ) -> V_156 ;
break;
default:
V_148 = V_157 ;
break;
}
if ( V_148 == V_158 ) {
V_149 |= V_159 ;
V_149 |= ( F_77 ( V_139 ) & 0x7fff ) << 17 ;
} else if ( V_148 == V_160 ) {
V_149 |= V_161 ;
} else {
F_78 ( 1 ) ;
}
V_132 -> V_149 = F_72 ( V_149 ) ;
}
}
static int F_79 ( struct V_1 * V_2 , struct V_87 * V_73 )
{
V_21 V_162 ;
T_3 * V_163 ;
V_163 = V_73 -> V_112 ;
V_73 -> V_89 = V_73 -> V_92 = 0 ;
V_162 = V_128 - sizeof( struct V_137 ) ;
while ( V_162 >= V_78 ) {
struct V_137 * V_137 ;
struct V_138 * V_139 ;
unsigned int V_141 ;
V_139 = F_80 ( & V_2 -> V_95 ) ;
if ( ! V_139 )
break;
V_141 = V_139 -> V_141 ;
if ( V_162 < V_141 ) {
F_81 ( & V_2 -> V_95 , V_139 ) ;
break;
}
V_137 = (struct V_137 * ) V_163 ;
V_163 += sizeof( * V_137 ) ;
F_71 ( V_2 , V_137 , V_139 ) ;
memcpy ( V_163 , V_139 -> V_6 , V_141 ) ;
V_73 -> V_89 ++ ;
V_73 -> V_92 += V_141 ;
F_82 ( V_139 ) ;
V_163 = F_55 ( V_163 + V_141 ) ;
V_162 = V_128 - sizeof( * V_137 ) -
( V_21 ) ( ( void * ) V_163 - V_73 -> V_112 ) ;
}
F_83 ( V_73 -> V_70 , V_2 -> V_11 , F_84 ( V_2 -> V_11 , 2 ) ,
V_73 -> V_112 , ( int ) ( V_163 - ( T_3 * ) V_73 -> V_112 ) ,
( V_164 ) F_45 , V_73 ) ;
return F_51 ( V_73 -> V_70 , V_86 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
struct V_134 * V_135 , * V_136 ;
F_37 ( & V_2 -> V_79 , V_18 ) ;
F_86 (cursor, next, &tp->rx_done) {
struct V_165 * V_165 ;
struct V_72 * V_73 ;
unsigned V_166 ;
int V_167 = 0 ;
struct V_70 * V_70 ;
T_3 * V_168 ;
int V_7 ;
F_69 ( V_135 ) ;
F_39 ( & V_2 -> V_79 , V_18 ) ;
V_73 = F_70 ( V_135 , struct V_72 , V_80 ) ;
V_70 = V_73 -> V_70 ;
if ( V_70 -> V_77 < V_78 )
goto V_169;
V_165 = V_73 -> V_112 ;
V_168 = V_73 -> V_112 ;
V_166 = F_87 ( V_165 -> V_140 ) & V_170 ;
V_167 += sizeof( struct V_165 ) + V_166 ;
while ( V_70 -> V_77 >= V_167 ) {
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_68 * V_69 ;
struct V_138 * V_139 ;
if ( V_166 < V_78 )
break;
V_69 = F_34 ( V_43 ) ;
V_166 -= 4 ;
V_168 += sizeof( struct V_165 ) ;
V_139 = F_88 ( V_43 , V_166 ) ;
if ( ! V_139 ) {
V_69 -> V_171 ++ ;
break;
}
memcpy ( V_139 -> V_6 , V_168 , V_166 ) ;
F_89 ( V_139 , V_166 ) ;
V_139 -> V_147 = F_90 ( V_139 , V_43 ) ;
F_91 ( V_139 ) ;
V_69 -> V_172 ++ ;
V_69 -> V_173 += V_166 ;
V_168 = F_53 ( V_168 + V_166 + 4 ) ;
V_165 = (struct V_165 * ) V_168 ;
V_166 = F_87 ( V_165 -> V_140 ) & V_170 ;
V_167 = ( int ) ( V_168 - ( T_3 * ) V_73 -> V_112 ) ;
V_167 += sizeof( struct V_165 ) + V_166 ;
}
V_169:
V_7 = F_44 ( V_2 , V_73 , V_86 ) ;
F_37 ( & V_2 -> V_79 , V_18 ) ;
if ( V_7 && V_7 != - V_19 ) {
F_38 ( & V_73 -> V_80 , V_136 ) ;
F_40 ( & V_2 -> V_82 ) ;
}
}
F_39 ( & V_2 -> V_79 , V_18 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_97 ;
do {
struct V_87 * V_73 ;
if ( F_46 ( & V_2 -> V_95 ) )
break;
V_73 = F_67 ( V_2 ) ;
if ( ! V_73 )
break;
V_97 = F_79 ( V_2 , V_73 ) ;
if ( V_97 ) {
struct V_68 * V_69 ;
struct V_42 * V_43 ;
unsigned long V_18 ;
V_43 = V_2 -> V_43 ;
V_69 = F_34 ( V_43 ) ;
if ( V_97 == - V_19 ) {
F_42 ( V_43 ) ;
} else {
F_93 ( V_2 , V_174 , V_43 ,
L_8 , V_97 ) ;
V_69 -> V_175 += V_73 -> V_89 ;
F_37 ( & V_2 -> V_93 , V_18 ) ;
F_38 ( & V_73 -> V_80 , & V_2 -> V_94 ) ;
F_39 ( & V_2 -> V_93 , V_18 ) ;
}
}
} while ( V_97 == 0 );
}
static void F_94 ( unsigned long V_6 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_6 ;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
return;
if ( ! F_9 ( V_76 , & V_2 -> V_18 ) )
return;
if ( ! F_36 ( V_2 -> V_43 ) )
return;
F_85 ( V_2 ) ;
F_92 ( V_2 ) ;
}
static
int F_44 ( struct V_1 * V_2 , struct V_72 * V_73 , T_6 V_176 )
{
F_83 ( V_73 -> V_70 , V_2 -> V_11 , F_95 ( V_2 -> V_11 , 1 ) ,
V_73 -> V_112 , V_128 ,
( V_164 ) F_35 , V_73 ) ;
return F_51 ( V_73 -> V_70 , V_176 ) ;
}
static void F_96 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
int V_38 ;
F_93 ( V_2 , V_174 , V_43 , L_9 ) ;
for ( V_38 = 0 ; V_38 < V_113 ; V_38 ++ )
F_97 ( V_2 -> V_114 [ V_38 ] . V_70 ) ;
}
static void F_98 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( V_2 -> V_104 & V_105 ) {
F_41 ( V_177 , & V_2 -> V_18 ) ;
F_50 ( & V_2 -> V_107 , 0 ) ;
}
}
static void F_99 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
V_21 V_178 [ 2 ] ;
T_2 V_8 [ 2 ] ;
V_21 V_37 ;
F_100 ( V_177 , & V_2 -> V_18 ) ;
F_101 ( V_43 ) ;
V_37 = F_15 ( V_2 , V_30 , V_179 ) ;
V_37 &= ~ V_180 ;
V_37 |= V_181 | V_182 ;
if ( V_43 -> V_18 & V_183 ) {
F_31 ( V_2 , V_184 , V_43 , L_10 ) ;
V_37 |= V_185 | V_186 ;
V_178 [ 1 ] = V_178 [ 0 ] = 0xffffffff ;
} else if ( ( F_102 ( V_43 ) > V_187 ) ||
( V_43 -> V_18 & V_188 ) ) {
V_37 |= V_185 ;
V_178 [ 1 ] = V_178 [ 0 ] = 0xffffffff ;
} else {
struct V_189 * V_190 ;
V_178 [ 1 ] = V_178 [ 0 ] = 0 ;
F_103 (ha, netdev) {
int V_191 = F_104 ( V_192 , V_190 -> V_49 ) >> 26 ;
V_178 [ V_191 >> 5 ] |= 1 << ( V_191 & 31 ) ;
V_37 |= V_185 ;
}
}
V_8 [ 0 ] = F_18 ( F_105 ( V_178 [ 1 ] ) ) ;
V_8 [ 1 ] = F_18 ( F_105 ( V_178 [ 0 ] ) ) ;
F_12 ( V_2 , V_193 , V_29 , sizeof( V_8 ) , V_8 ) ;
F_17 ( V_2 , V_30 , V_179 , V_37 ) ;
F_106 ( V_43 ) ;
}
static T_7 F_107 ( struct V_138 * V_139 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_68 * V_69 = F_34 ( V_43 ) ;
unsigned long V_18 ;
struct V_87 * V_73 = NULL ;
struct V_137 * V_137 ;
unsigned int V_141 ;
T_3 * V_163 ;
int V_97 ;
F_108 ( V_139 ) ;
if ( F_46 ( & V_2 -> V_95 ) )
V_73 = F_67 ( V_2 ) ;
if ( ! V_73 ) {
F_109 ( & V_2 -> V_95 , V_139 ) ;
return V_194 ;
}
V_137 = (struct V_137 * ) V_73 -> V_112 ;
V_163 = V_73 -> V_112 + sizeof( * V_137 ) ;
V_73 -> V_89 = V_73 -> V_92 = 0 ;
V_141 = V_139 -> V_141 ;
F_71 ( V_2 , V_137 , V_139 ) ;
memcpy ( V_163 , V_139 -> V_6 , V_141 ) ;
F_82 ( V_139 ) ;
V_73 -> V_89 ++ ;
V_73 -> V_92 += V_141 ;
F_83 ( V_73 -> V_70 , V_2 -> V_11 , F_84 ( V_2 -> V_11 , 2 ) ,
V_73 -> V_112 , V_141 + sizeof( * V_137 ) ,
( V_164 ) F_45 , V_73 ) ;
V_97 = F_51 ( V_73 -> V_70 , V_86 ) ;
if ( V_97 ) {
if ( V_97 == - V_19 ) {
F_42 ( V_2 -> V_43 ) ;
} else {
F_93 ( V_2 , V_174 , V_43 ,
L_8 , V_97 ) ;
V_69 -> V_175 ++ ;
F_37 ( & V_2 -> V_93 , V_18 ) ;
F_38 ( & V_73 -> V_80 , & V_2 -> V_94 ) ;
F_39 ( & V_2 -> V_93 , V_18 ) ;
}
}
return V_194 ;
}
static void F_110 ( struct V_1 * V_2 )
{
V_21 V_37 ;
V_37 = F_19 ( V_2 , V_30 , V_195 ) ;
V_37 &= ~ V_196 ;
F_20 ( V_2 , V_30 , V_195 , V_37 ) ;
V_37 |= V_196 ;
F_20 ( V_2 , V_30 , V_195 , V_37 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
int V_38 ;
F_22 ( V_2 , V_30 , V_197 , V_198 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
if ( ! ( F_21 ( V_2 , V_30 , V_197 ) & V_198 ) )
break;
F_24 ( 100 ) ;
}
}
static inline T_3 F_112 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_30 , V_199 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 , V_7 ;
T_3 V_104 ;
V_104 = F_112 ( V_2 ) ;
if ( V_104 & V_200 ) {
V_37 = F_19 ( V_2 , V_30 , V_201 ) ;
V_37 |= V_202 ;
F_20 ( V_2 , V_30 , V_201 , V_37 ) ;
} else {
V_37 = F_19 ( V_2 , V_30 , V_201 ) ;
V_37 &= ~ V_202 ;
F_20 ( V_2 , V_30 , V_201 , V_37 ) ;
}
F_110 ( V_2 ) ;
V_37 = F_21 ( V_2 , V_30 , V_197 ) ;
V_37 |= V_203 | V_204 ;
F_22 ( V_2 , V_30 , V_197 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_205 ) ;
V_37 &= ~ V_206 ;
F_20 ( V_2 , V_30 , V_205 , V_37 ) ;
F_61 ( & V_2 -> V_81 ) ;
V_7 = 0 ;
for ( V_38 = 0 ; V_38 < V_109 ; V_38 ++ ) {
F_61 ( & V_2 -> V_110 [ V_38 ] . V_80 ) ;
V_7 |= F_44 ( V_2 , & V_2 -> V_110 [ V_38 ] , V_9 ) ;
}
return V_7 ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = F_34 ( V_2 -> V_43 ) ;
struct V_138 * V_139 ;
V_21 V_37 ;
int V_38 ;
V_37 = F_15 ( V_2 , V_30 , V_179 ) ;
V_37 &= ~ V_180 ;
F_17 ( V_2 , V_30 , V_179 , V_37 ) ;
while ( ( V_139 = F_80 ( & V_2 -> V_95 ) ) ) {
F_115 ( V_139 ) ;
V_69 -> V_175 ++ ;
}
for ( V_38 = 0 ; V_38 < V_113 ; V_38 ++ )
F_116 ( V_2 -> V_114 [ V_38 ] . V_70 ) ;
V_37 = F_19 ( V_2 , V_30 , V_205 ) ;
V_37 |= V_206 ;
F_20 ( V_2 , V_30 , V_205 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
if ( ( V_37 & V_208 ) == V_208 )
break;
F_117 ( 1 ) ;
}
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
if ( F_19 ( V_2 , V_30 , V_209 ) & V_210 )
break;
F_117 ( 1 ) ;
}
for ( V_38 = 0 ; V_38 < V_109 ; V_38 ++ )
F_116 ( V_2 -> V_110 [ V_38 ] . V_70 ) ;
F_111 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
V_37 = F_15 ( V_2 , V_30 , V_179 ) ;
V_37 &= ~ V_180 ;
F_17 ( V_2 , V_30 , V_179 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_205 ) ;
V_37 |= V_206 ;
F_20 ( V_2 , V_30 , V_205 , V_37 ) ;
F_22 ( V_2 , V_30 , V_64 , V_67 ) ;
F_22 ( V_2 , V_30 , V_197 , 0x00 ) ;
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
V_37 &= ~ V_211 ;
F_22 ( V_2 , V_30 , V_207 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_212 ) ;
V_37 &= ~ V_213 ;
F_20 ( V_2 , V_30 , V_212 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
if ( V_37 & V_214 )
break;
F_117 ( 1 ) ;
}
V_37 = F_19 ( V_2 , V_30 , V_212 ) ;
V_37 |= V_215 ;
F_20 ( V_2 , V_30 , V_212 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
if ( V_37 & V_214 )
break;
F_117 ( 1 ) ;
}
F_111 ( V_2 ) ;
F_17 ( V_2 , V_30 , V_216 , V_217 ) ;
V_37 = F_19 ( V_2 , V_31 , V_218 ) ;
V_37 &= V_219 ;
if ( V_37 == V_220 ) {
F_17 ( V_2 , V_30 , V_221 ,
V_222 ) ;
F_17 ( V_2 , V_30 , V_223 ,
V_224 ) ;
} else {
F_17 ( V_2 , V_30 , V_221 ,
V_225 ) ;
F_17 ( V_2 , V_30 , V_223 ,
V_226 ) ;
}
F_17 ( V_2 , V_30 , V_227 , V_228 ) ;
F_22 ( V_2 , V_31 , V_229 , V_230 ) ;
F_17 ( V_2 , V_31 , V_231 , V_232 ) ;
F_17 ( V_2 , V_31 , V_233 ,
V_234 | V_235 ) ;
V_37 = F_19 ( V_2 , V_30 , V_236 ) ;
V_37 &= ~ V_237 ;
F_20 ( V_2 , V_30 , V_236 , V_37 ) ;
F_20 ( V_2 , V_30 , V_238 , V_239 ) ;
V_37 = F_19 ( V_2 , V_30 , V_209 ) ;
V_37 |= V_240 ;
F_20 ( V_2 , V_30 , V_209 , V_37 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
V_37 &= ~ V_211 ;
F_22 ( V_2 , V_30 , V_207 , V_37 ) ;
F_17 ( V_2 , V_30 , V_216 , V_241 ) ;
F_17 ( V_2 , V_30 , V_221 , V_242 ) ;
F_17 ( V_2 , V_30 , V_223 , V_243 ) ;
F_114 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
if ( V_37 & V_214 )
break;
F_117 ( 1 ) ;
}
V_37 = F_19 ( V_2 , V_30 , V_212 ) ;
V_37 |= V_215 ;
F_20 ( V_2 , V_30 , V_212 , V_37 ) ;
for ( V_38 = 0 ; V_38 < 1000 ; V_38 ++ ) {
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
if ( V_37 & V_214 )
break;
F_117 ( 1 ) ;
}
F_20 ( V_2 , V_30 , V_238 , V_239 ) ;
V_37 = F_19 ( V_2 , V_30 , V_244 ) ;
V_37 |= V_245 ;
F_20 ( V_2 , V_30 , V_244 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_236 ) ;
V_37 |= V_237 ;
F_20 ( V_2 , V_30 , V_236 , V_37 ) ;
V_37 = F_19 ( V_2 , V_30 , V_246 ) ;
V_37 |= V_247 ;
F_20 ( V_2 , V_30 , V_246 , V_37 ) ;
V_37 = F_21 ( V_2 , V_30 , V_207 ) ;
V_37 |= V_211 | V_248 ;
F_22 ( V_2 , V_30 , V_207 , V_37 ) ;
F_22 ( V_2 , V_30 , V_249 , V_250 ) ;
V_37 = F_19 ( V_2 , V_30 , V_205 ) ;
V_37 &= ~ V_206 ;
F_20 ( V_2 , V_30 , V_205 , V_37 ) ;
V_37 = F_15 ( V_2 , V_30 , V_179 ) ;
V_37 |= V_182 | V_185 | V_181 ;
F_17 ( V_2 , V_30 , V_179 , V_37 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_251 , V_252 | V_253 | V_254 ) ;
F_121 ( 20 ) ;
}
static inline void F_122 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_251 , V_255 | V_252 |
V_253 | V_254 ) ;
}
static int F_123 ( struct V_1 * V_2 , T_3 V_256 , T_1 V_104 , T_3 V_257 )
{
T_1 V_258 , V_259 ;
int V_7 = 0 ;
F_124 ( & V_2 -> V_107 ) ;
V_259 = F_25 ( V_2 , V_260 ) ;
V_259 &= ~ ( V_261 | V_262 |
V_263 | V_264 ) ;
if ( V_256 == V_265 ) {
if ( V_104 == V_266 ) {
V_258 = 0 ;
V_259 |= V_261 | V_262 ;
} else if ( V_104 == V_267 ) {
V_258 = V_268 ;
V_259 |= V_263 | V_264 ;
} else {
V_7 = - V_47 ;
goto V_269;
}
if ( V_257 == V_270 )
V_258 |= V_271 ;
} else {
if ( V_104 == V_266 ) {
if ( V_257 == V_270 )
V_259 |= V_261 | V_262 ;
else
V_259 |= V_261 ;
} else if ( V_104 == V_267 ) {
if ( V_257 == V_270 ) {
V_259 |= V_261 | V_262 ;
V_259 |= V_263 | V_264 ;
} else {
V_259 |= V_261 ;
V_259 |= V_263 ;
}
} else {
V_7 = - V_47 ;
goto V_269;
}
V_258 = V_272 | V_273 ;
}
F_23 ( V_2 , V_260 , V_259 ) ;
F_23 ( V_2 , V_274 , V_258 ) ;
V_269:
return V_7 ;
}
static void F_125 ( struct V_1 * V_2 )
{
V_21 V_37 ;
V_37 = F_19 ( V_2 , V_31 , V_275 ) ;
V_37 &= ~ V_276 ;
F_20 ( V_2 , V_31 , V_275 , V_37 ) ;
F_120 ( V_2 ) ;
F_119 ( V_2 ) ;
F_122 ( V_2 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
T_3 V_104 ;
F_100 ( V_106 , & V_2 -> V_18 ) ;
V_104 = F_112 ( V_2 ) ;
if ( V_104 & V_105 ) {
if ( ! ( V_2 -> V_104 & V_105 ) ) {
F_113 ( V_2 ) ;
F_41 ( V_177 , & V_2 -> V_18 ) ;
F_127 ( V_43 ) ;
}
} else {
if ( V_2 -> V_104 & V_105 ) {
F_128 ( V_43 ) ;
F_129 ( & V_2 -> V_82 ) ;
F_114 ( V_2 ) ;
F_130 ( & V_2 -> V_82 ) ;
}
}
V_2 -> V_104 = V_104 ;
}
static void F_131 ( struct V_277 * V_278 )
{
struct V_1 * V_2 = F_132 ( V_278 , struct V_1 , V_107 . V_278 ) ;
if ( ! F_9 ( V_76 , & V_2 -> V_18 ) )
goto V_279;
if ( F_9 ( V_17 , & V_2 -> V_18 ) )
goto V_279;
if ( F_9 ( V_106 , & V_2 -> V_18 ) )
F_126 ( V_2 ) ;
if ( F_9 ( V_177 , & V_2 -> V_18 ) )
F_99 ( V_2 -> V_43 ) ;
V_279:
return;
}
static int F_133 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
int V_97 = 0 ;
V_97 = F_51 ( V_2 -> V_115 , V_9 ) ;
if ( V_97 ) {
if ( V_97 == - V_19 )
F_42 ( V_2 -> V_43 ) ;
F_93 ( V_2 , V_280 , V_43 ,
L_11 , V_97 ) ;
return V_97 ;
}
F_123 ( V_2 , V_281 , V_267 , V_270 ) ;
V_2 -> V_104 = 0 ;
F_128 ( V_43 ) ;
F_134 ( V_43 ) ;
F_41 ( V_76 , & V_2 -> V_18 ) ;
return V_97 ;
}
static int F_135 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
int V_97 = 0 ;
F_116 ( V_2 -> V_115 ) ;
F_100 ( V_76 , & V_2 -> V_18 ) ;
F_124 ( & V_2 -> V_107 ) ;
F_101 ( V_43 ) ;
F_129 ( & V_2 -> V_82 ) ;
F_114 ( V_2 ) ;
F_130 ( & V_2 -> V_82 ) ;
return V_97 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_30 , V_282 , 0 ) ;
F_17 ( V_2 , V_30 , V_283 , 0 ) ;
F_17 ( V_2 , V_30 , V_284 , 0 ) ;
F_17 ( V_2 , V_30 , V_285 , 0 ) ;
F_17 ( V_2 , V_31 , V_286 , 0 ) ;
F_17 ( V_2 , V_31 , V_287 , 0 ) ;
F_17 ( V_2 , V_31 , V_288 , 0 ) ;
F_17 ( V_2 , V_31 , V_289 , 0 ) ;
F_117 ( 3 ) ;
F_20 ( V_2 , V_30 , V_290 , 0 ) ;
F_20 ( V_2 , V_31 , V_291 , 0 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
V_21 V_37 ;
V_37 = F_19 ( V_2 , V_30 , V_292 ) ;
V_37 |= V_293 | V_294 ;
F_20 ( V_2 , V_30 , V_292 , V_37 ) ;
F_29 ( V_2 , V_295 , V_296 | V_297 |
V_298 | V_299 |
V_300 | V_301 |
V_302 | V_303 |
V_304 ) ;
F_29 ( V_2 , V_305 , V_306 | V_307 |
V_308 | V_309 |
V_310 ) ;
F_29 ( V_2 , V_311 , V_312 | V_313 | V_314 ) ;
F_29 ( V_2 , V_315 , V_316 | V_317 ) ;
F_29 ( V_2 , V_318 , V_319 ) ;
F_29 ( V_2 , V_315 , V_320 | V_317 ) ;
F_29 ( V_2 , V_318 , V_321 ) ;
F_29 ( V_2 , V_315 , 0x0000 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
T_1 V_259 ;
V_259 = F_25 ( V_2 , V_260 ) ;
V_259 |= V_322 | V_323 ;
F_23 ( V_2 , V_260 , V_259 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_274 , V_272 ) ;
F_120 ( V_2 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
V_21 V_37 ;
int V_38 ;
F_136 ( V_2 ) ;
if ( V_2 -> V_324 == V_325 ) {
V_37 = F_19 ( V_2 , V_30 , V_326 ) ;
V_37 &= ~ V_327 ;
F_20 ( V_2 , V_30 , V_326 , V_37 ) ;
}
F_139 ( V_2 ) ;
V_37 = F_19 ( V_2 , V_31 , V_275 ) ;
V_37 &= ~ V_276 ;
F_20 ( V_2 , V_31 , V_275 , V_37 ) ;
V_37 = F_19 ( V_2 , V_31 , V_328 ) ;
V_37 &= ~ V_329 ;
F_20 ( V_2 , V_31 , V_328 , V_37 ) ;
F_118 ( V_2 ) ;
V_37 = F_19 ( V_2 , V_30 , V_330 ) ;
V_37 |= V_331 | V_332 ;
F_20 ( V_2 , V_30 , V_330 , V_37 ) ;
V_37 = F_15 ( V_2 , V_30 , V_333 ) ;
V_37 &= ~ V_334 ;
V_37 |= V_335 | V_336 ;
F_17 ( V_2 , V_30 , V_333 , V_37 ) ;
V_37 = V_337 | V_338 |
V_339 | V_340 ;
F_20 ( V_2 , V_30 , V_341 , V_37 ) ;
F_137 ( V_2 ) ;
F_122 ( V_2 ) ;
F_138 ( V_2 ) ;
F_23 ( V_2 , V_274 , V_342 | V_272 |
V_273 ) ;
for ( V_38 = 0 ; V_38 < 100 ; V_38 ++ ) {
F_24 ( 100 ) ;
if ( ! ( F_25 ( V_2 , V_274 ) & V_342 ) )
break;
}
V_37 = F_19 ( V_2 , V_31 , V_343 ) ;
V_37 &= ~ V_344 ;
F_20 ( V_2 , V_31 , V_343 , V_37 ) ;
}
static int F_141 ( struct V_117 * V_118 , T_8 V_345 )
{
struct V_1 * V_2 = F_142 ( V_118 ) ;
F_42 ( V_2 -> V_43 ) ;
if ( F_143 ( V_2 -> V_43 ) ) {
F_100 ( V_76 , & V_2 -> V_18 ) ;
F_116 ( V_2 -> V_115 ) ;
F_124 ( & V_2 -> V_107 ) ;
F_129 ( & V_2 -> V_82 ) ;
}
F_125 ( V_2 ) ;
return 0 ;
}
static int F_144 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_142 ( V_118 ) ;
F_140 ( V_2 ) ;
F_145 ( V_2 -> V_43 ) ;
if ( F_143 ( V_2 -> V_43 ) ) {
F_123 ( V_2 , V_281 , V_267 , V_270 ) ;
V_2 -> V_104 = 0 ;
F_128 ( V_2 -> V_43 ) ;
F_41 ( V_76 , & V_2 -> V_18 ) ;
F_51 ( V_2 -> V_115 , V_9 ) ;
F_130 ( & V_2 -> V_82 ) ;
}
return 0 ;
}
static void F_146 ( struct V_42 * V_43 ,
struct V_346 * V_347 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
strncpy ( V_347 -> V_348 , V_349 , V_350 ) ;
strncpy ( V_347 -> V_324 , V_351 , V_350 ) ;
F_147 ( V_2 -> V_11 , V_347 -> V_352 , sizeof( V_347 -> V_352 ) ) ;
}
static
int F_148 ( struct V_42 * V_43 , struct V_353 * V_354 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
if ( ! V_2 -> V_355 . V_356 )
return - V_357 ;
return F_149 ( & V_2 -> V_355 , V_354 ) ;
}
static int F_150 ( struct V_42 * V_53 , struct V_353 * V_354 )
{
struct V_1 * V_2 = F_27 ( V_53 ) ;
return F_123 ( V_2 , V_354 -> V_256 , V_354 -> V_104 , V_354 -> V_257 ) ;
}
static int F_151 ( struct V_42 * V_43 , struct V_358 * V_359 , int V_354 )
{
struct V_1 * V_2 = F_27 ( V_43 ) ;
struct V_360 * V_6 = F_152 ( V_359 ) ;
int V_97 = 0 ;
switch ( V_354 ) {
case V_361 :
V_6 -> V_44 = V_46 ;
break;
case V_362 :
V_6 -> V_363 = F_25 ( V_2 , V_6 -> V_364 ) ;
break;
case V_365 :
if ( ! F_153 ( V_366 ) ) {
V_97 = - V_20 ;
break;
}
F_23 ( V_2 , V_6 -> V_364 , V_6 -> V_367 ) ;
break;
default:
V_97 = - V_357 ;
}
return V_97 ;
}
static void F_154 ( struct V_1 * V_2 )
{
V_21 V_37 ;
T_1 V_324 ;
V_37 = F_19 ( V_2 , V_30 , V_368 ) ;
V_324 = ( T_1 ) ( V_37 & V_369 ) ;
switch ( V_324 ) {
case 0x4c00 :
V_2 -> V_324 = V_325 ;
break;
case 0x4c10 :
V_2 -> V_324 = V_370 ;
break;
default:
F_48 ( V_2 , V_56 , V_2 -> V_43 ,
L_12 , V_324 ) ;
break;
}
}
static int F_155 ( struct V_117 * V_118 ,
const struct V_371 * V_372 )
{
struct V_373 * V_11 = F_156 ( V_118 ) ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_7 ;
if ( V_11 -> V_374 -> V_132 . V_375 != 1 ) {
F_157 ( V_11 , 1 ) ;
return - V_19 ;
}
V_43 = F_158 ( sizeof( struct V_1 ) ) ;
if ( ! V_43 ) {
F_159 ( & V_118 -> V_53 , L_13 ) ;
return - V_10 ;
}
F_160 ( V_43 , & V_118 -> V_53 ) ;
V_2 = F_27 ( V_43 ) ;
V_2 -> V_376 = 0x7FFF ;
F_161 ( & V_2 -> V_82 , F_94 , ( unsigned long ) V_2 ) ;
F_162 ( & V_2 -> V_107 , F_131 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_118 = V_118 ;
V_43 -> V_377 = & V_378 ;
V_43 -> V_379 = V_380 ;
V_43 -> V_381 |= V_382 ;
V_43 -> V_383 = V_382 ;
F_163 ( V_43 , & V_384 ) ;
V_2 -> V_355 . V_53 = V_43 ;
V_2 -> V_355 . V_356 = F_26 ;
V_2 -> V_355 . V_385 = F_28 ;
V_2 -> V_355 . V_386 = 0x3f ;
V_2 -> V_355 . V_387 = 0x1f ;
V_2 -> V_355 . V_44 = V_46 ;
V_2 -> V_355 . V_388 = 0 ;
F_154 ( V_2 ) ;
F_140 ( V_2 ) ;
F_30 ( V_2 ) ;
V_7 = F_58 ( V_2 ) ;
if ( V_7 )
goto V_269;
F_164 ( V_118 , V_2 ) ;
V_7 = F_165 ( V_43 ) ;
if ( V_7 != 0 ) {
F_52 ( V_2 , V_56 , V_43 , L_14 ) ;
goto V_279;
}
F_48 ( V_2 , V_56 , V_43 , L_15 , V_351 ) ;
return 0 ;
V_279:
F_164 ( V_118 , NULL ) ;
V_269:
F_166 ( V_43 ) ;
return V_7 ;
}
static void F_167 ( struct V_1 * V_2 )
{
V_21 V_37 ;
if ( V_2 -> V_324 != V_325 ) {
V_37 = F_19 ( V_2 , V_31 , V_275 ) ;
V_37 |= V_276 ;
F_20 ( V_2 , V_31 , V_275 , V_37 ) ;
}
V_37 = F_19 ( V_2 , V_31 , V_328 ) ;
V_37 &= ~ V_329 ;
F_20 ( V_2 , V_31 , V_328 , V_37 ) ;
}
static void F_168 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_142 ( V_118 ) ;
F_164 ( V_118 , NULL ) ;
if ( V_2 ) {
F_41 ( V_17 , & V_2 -> V_18 ) ;
F_169 ( & V_2 -> V_82 ) ;
F_170 ( V_2 -> V_43 ) ;
F_167 ( V_2 ) ;
F_56 ( V_2 ) ;
F_166 ( V_2 -> V_43 ) ;
}
}
