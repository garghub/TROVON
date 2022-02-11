static inline T_1 F_1 ( T_2 V_1 , void * V_2 )
{
return * ( ( T_1 * ) ( V_2 + ( V_1 + 1 ) * V_3 ) ) ;
}
static T_3 F_2 ( T_3 V_4 )
{
return ( 0x10000 * V_4 ) / 100 ;
}
static void F_3 ( struct V_5 * V_6 )
{
V_6 -> V_7 . V_8 = sizeof( V_6 -> V_7 ) ;
V_6 -> V_7 . V_9 = sizeof( V_6 -> V_7 ) ;
V_6 -> V_7 . V_10 = sizeof( V_6 -> V_11 ) ;
V_6 -> V_7 . V_12 = sizeof( V_6 -> V_13 ) ;
V_6 -> V_7 . V_14 = V_6 -> V_7 . V_8 + V_6 -> V_7 . V_10 ;
V_6 -> V_7 . V_15 = V_6 -> V_7 . V_14 + V_6 -> V_7 . V_12 ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
if ( F_5 ( V_17 , 1 , 1 , 1 ) )
return;
F_6 ( V_6 -> V_11 . V_18 ) ;
memcpy ( V_6 -> V_11 . V_19 , V_17 -> type , sizeof( V_6 -> V_11 . V_19 ) ) ;
memcpy ( V_6 -> V_11 . V_20 , V_17 -> V_21 , sizeof( V_6 -> V_11 . V_20 ) ) ;
memcpy ( V_6 -> V_11 . V_22 , V_17 -> V_23 , sizeof( V_6 -> V_11 . V_22 ) ) ;
memcpy ( V_6 -> V_11 . V_24 , V_17 -> V_25 , sizeof( V_6 -> V_11 . V_24 ) ) ;
V_6 -> V_11 . V_26 |= V_27 | V_28 ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_29 * V_17 )
{
if ( F_5 ( V_17 , 2 , 2 , 2 ) )
return;
V_6 -> V_13 . V_30 = V_17 -> V_31 ;
memcpy ( V_6 -> V_13 . V_32 , V_17 -> V_33 , sizeof( V_6 -> V_13 . V_32 ) ) ;
V_6 -> V_13 . V_34 |= V_35 ;
}
static void F_8 ( struct V_5 * V_6 )
{
void * V_17 ;
V_17 = ( void * ) F_9 ( V_36 ) ;
if ( ! V_17 )
return;
F_4 ( V_6 , V_17 ) ;
F_7 ( V_6 , V_17 ) ;
F_10 ( ( unsigned long ) V_17 , 0 ) ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_37 * V_38 ,
void * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_7 . V_40 ; V_39 ++ ) {
switch ( F_1 ( V_38 -> V_40 [ V_39 ] . V_1 , V_2 ) ) {
case V_41 :
if ( V_38 -> V_40 [ V_39 ] . V_42 == V_43 )
V_6 -> V_11 . V_44 ++ ;
else
V_6 -> V_11 . V_45 ++ ;
break;
case V_46 :
if ( V_38 -> V_40 [ V_39 ] . V_42 == V_43 )
V_6 -> V_11 . V_47 ++ ;
else
V_6 -> V_11 . V_48 ++ ;
break;
}
}
V_6 -> V_11 . V_26 |= V_49 ;
}
static struct V_50 * F_12 ( struct F_12 * V_51 ,
bool V_52 ,
void * V_2 ,
struct V_50 * V_38 )
{
int V_39 , V_53 = 0 , V_54 = 0 , V_55 = 0 ;
struct V_56 * V_56 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_7 . V_57 ; V_39 ++ ) {
if ( ! ( V_38 -> V_40 [ V_39 ] . V_58 & V_59 ) )
continue;
switch ( F_1 ( V_38 -> V_40 [ V_39 ] . V_1 , V_2 ) ) {
case V_41 :
V_56 = & V_51 -> V_60 ;
if ( V_38 -> V_40 [ V_39 ] . V_61 < V_43 )
V_54 |= V_38 -> V_40 [ V_39 ] . V_61 ;
break;
case V_46 :
V_56 = & V_51 -> V_62 ;
if ( V_38 -> V_40 [ V_39 ] . V_61 < V_43 )
V_55 |= V_38 -> V_40 [ V_39 ] . V_61 ;
break;
default:
continue;
}
if ( ! V_52 )
continue;
V_53 |= V_38 -> V_40 [ V_39 ] . V_58 & V_63 ;
V_56 -> V_64 |= V_38 -> V_40 [ V_39 ] . V_65 ;
V_56 -> V_66 |= V_38 -> V_40 [ V_39 ] . V_67 ;
if ( V_38 -> V_40 [ V_39 ] . V_42 == V_43 )
V_56 -> V_68 += 1 ;
else
V_56 -> V_69 += 1 ;
}
if ( V_52 && V_53 ) {
V_51 -> V_60 . V_70 = V_54 ;
V_51 -> V_62 . V_70 = V_55 ;
}
V_51 -> V_60 . V_71 += V_54 ;
V_51 -> V_62 . V_71 += V_55 ;
return (struct V_50 * ) & V_38 -> V_40 [ V_39 ] ;
}
static void F_13 ( struct V_5 * V_6 )
{
int V_39 , V_72 , V_73 ;
bool V_52 ;
void * V_74 ;
void * V_2 = NULL ;
struct V_75 * V_76 ;
struct V_50 * V_77 ;
struct V_37 * V_78 ;
struct F_12 V_79 = {} ;
V_73 = F_14 ( ( unsigned long ) V_80 |
( unsigned long ) V_81 , 0 , NULL ) ;
if ( V_73 <= 0 )
return;
V_74 = F_15 ( V_82 * V_73 ) ;
if ( ! V_74 )
return;
V_72 = F_14 ( ( unsigned long ) V_83 |
( unsigned long ) V_81 , V_73 , V_74 ) ;
if ( V_72 < 0 )
goto V_84;
V_2 = ( void * ) F_9 ( V_36 | V_85 ) ;
if ( ! V_2 || F_16 ( V_2 ) )
goto V_84;
V_76 = V_74 ;
V_77 = V_74 + sizeof( * V_76 ) ;
for ( V_39 = 0 ; V_39 < V_76 -> V_86 ; V_39 ++ ) {
V_52 = ( void * ) V_77 - V_74 == V_76 -> V_87 ;
V_77 = F_12 ( & V_79 , V_52 , V_2 ,
V_77 ) ;
}
V_78 = (struct V_37 * ) V_77 ;
V_77 = V_74 + V_76 -> V_87 ;
if ( V_77 -> V_7 . V_88 )
V_6 -> V_13 . V_89 = V_90 ;
V_6 -> V_13 . V_34 |= V_91 ;
V_6 -> V_13 . V_92 = F_2 ( V_79 . V_60 . V_66 ) ;
V_6 -> V_13 . V_93 = F_2 ( V_79 . V_62 . V_66 ) ;
memcpy ( V_6 -> V_13 . V_94 , V_77 -> V_7 . V_95 ,
sizeof( V_6 -> V_13 . V_94 ) ) ;
V_6 -> V_13 . V_96 = V_79 . V_60 . V_69 ;
V_6 -> V_13 . V_97 = V_79 . V_60 . V_68 ;
V_6 -> V_13 . V_98 = V_79 . V_62 . V_69 ;
V_6 -> V_13 . V_99 = V_79 . V_62 . V_68 ;
V_6 -> V_13 . V_34 |= V_100 ;
V_6 -> V_13 . V_101 = F_2 ( V_79 . V_60 . V_64 ) ;
V_6 -> V_13 . V_102 = F_2 ( V_79 . V_62 . V_64 ) ;
V_6 -> V_13 . V_34 |= V_103 ;
if ( ! ( V_76 -> V_104 & V_105 ) ) {
V_6 -> V_7 . V_106 |= V_107 ;
goto V_84;
}
F_11 ( V_6 , V_78 , V_2 ) ;
if ( V_79 . V_60 . V_70 ) {
V_6 -> V_13 . V_108 = V_6 -> V_11 . V_45 * 0x10000 *
V_79 . V_60 . V_70 / V_79 . V_60 . V_71 ;
}
if ( V_79 . V_62 . V_70 ) {
V_6 -> V_13 . V_109 = V_6 -> V_11 . V_48 * 0x10000 *
V_79 . V_62 . V_70 / V_79 . V_62 . V_71 ;
}
V_6 -> V_13 . V_34 |= V_110 ;
V_84:
F_17 ( ( unsigned long ) V_2 ) ;
F_18 ( V_74 ) ;
}
static int F_19 ( T_1 V_111 )
{
register T_1 T_4 V_112 ( L_1 ) = 0 ;
register T_1 T_5 V_112 ( L_2 ) = V_111 ;
int V_113 ;
asm volatile(
".insn rre,0xB2560000,%[code],%[addr]\n"
"ipm %[cc]\n"
"srl %[cc],28\n"
: [cc] "=d" (cc)
: [code] "d" (code), [addr] "a" (addr)
: "3", "memory", "cc");
return V_113 ;
}
int F_20 ( struct V_114 * V_115 )
{
int V_116 , V_117 , V_72 = 0 ;
T_1 T_4 , T_5 , V_113 = 0 ;
struct V_5 * V_6 = NULL ;
if ( ! F_21 ( V_115 -> V_118 , 74 ) )
return F_22 ( V_115 , V_119 ) ;
if ( ! F_23 ( & V_115 -> V_118 -> V_120 . V_121 ) ) {
F_24 ( V_115 ) ;
return 0 ;
}
F_25 ( V_115 , & V_116 , & V_117 ) ;
T_4 = V_115 -> V_122 -> V_123 . V_124 . V_125 [ V_116 ] ;
T_5 = V_115 -> V_122 -> V_123 . V_124 . V_125 [ V_117 ] ;
V_115 -> V_126 . V_127 ++ ;
F_26 ( V_115 , 3 , L_3 , T_4 , T_5 ) ;
F_27 ( V_115 , T_4 , T_5 ) ;
if ( V_116 == V_117 || V_116 & 1 || V_117 & 1 )
return F_22 ( V_115 , V_128 ) ;
if ( T_4 & 0xffff ) {
V_113 = 3 ;
goto V_84;
}
if ( T_5 & ~ V_129 )
return F_22 ( V_115 , V_128 ) ;
V_72 = F_28 ( V_115 , T_5 , V_117 , & V_113 , 1 ) ;
if ( V_72 )
return F_29 ( V_115 , V_72 ) ;
V_6 = ( void * ) F_30 ( V_36 ) ;
if ( ! V_6 )
return - V_130 ;
if ( F_31 ( 74 ) ) {
V_113 = F_19 ( ( T_1 ) V_6 ) ;
goto V_84;
}
F_3 ( V_6 ) ;
F_8 ( V_6 ) ;
F_13 ( V_6 ) ;
V_84:
if ( ! V_113 ) {
V_72 = F_28 ( V_115 , T_5 , V_117 , V_6 , V_82 ) ;
if ( V_72 ) {
F_17 ( ( unsigned long ) V_6 ) ;
return F_29 ( V_115 , V_72 ) ;
}
}
F_17 ( ( unsigned long ) V_6 ) ;
V_115 -> V_122 -> V_123 . V_124 . V_125 [ V_117 + 1 ] = V_113 ? 4 : 0 ;
F_32 ( V_115 , V_113 ) ;
return V_72 ;
}
