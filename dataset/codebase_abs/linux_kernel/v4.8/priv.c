static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
T_2 V_5 , V_6 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_5 = F_3 ( V_2 , & V_4 ) ;
if ( V_5 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_5 , V_4 , & V_6 , sizeof( V_6 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_1 , V_6 ) ;
F_7 ( V_2 -> V_14 , V_6 ) ;
F_8 ( V_2 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_3 V_16 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_18 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 3 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_15 , V_4 , & V_16 , sizeof( V_16 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_16 &= 0x7fffe000u ;
if ( F_10 ( V_2 -> V_14 , V_16 ) )
return F_2 ( V_2 , V_19 ) ;
F_11 ( V_2 , V_16 ) ;
F_12 ( V_2 , 1 , V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_3 V_16 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_20 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 3 )
return F_2 ( V_2 , V_13 ) ;
V_16 = F_14 ( V_2 ) ;
V_3 = F_15 ( V_2 , V_15 , V_4 , & V_16 , sizeof( V_16 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_2 , V_16 , V_15 ) ;
F_12 ( V_2 , 0 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_4 V_21 = V_2 -> V_21 ;
T_2 V_22 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_23 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_3 ( V_2 , & V_4 ) ;
if ( V_22 & 1 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_15 ( V_2 , V_22 , V_4 , & V_21 , sizeof( V_21 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_3 , V_21 , V_22 ) ;
F_17 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_19 ( V_2 ) ;
if ( ! ( V_2 -> V_7 . V_8 -> V_24 & ( V_25 | V_26 | V_27 ) ) )
return V_3 ;
V_3 = F_20 () ;
F_6 ( V_2 , 3 , L_4 , V_3 ) ;
if ( ! V_3 )
V_2 -> V_7 . V_8 -> V_24 &= ~ ( V_25 | V_26 | V_27 ) ;
return V_3 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_17 . V_28 ++ ;
V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_29 . V_30 ) {
F_22 ( V_2 ) ;
F_6 ( V_2 , 4 , L_5 , L_6 ) ;
return - V_31 ;
}
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned long V_32 ;
unsigned char V_33 ;
int V_34 , V_35 ;
int V_3 ;
V_3 = F_21 ( V_2 ) ;
if ( V_3 )
return V_3 != - V_31 ? V_3 : 0 ;
F_24 ( V_2 , & V_34 , & V_35 ) ;
V_32 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
V_32 = F_25 ( V_2 , V_32 ) ;
V_32 = F_26 ( V_2 , V_32 ) ;
V_32 = F_27 ( V_2 -> V_14 , F_28 ( V_32 ) ) ;
if ( F_29 ( V_32 ) )
return F_2 ( V_2 , V_19 ) ;
F_30 ( & V_41 -> V_42 -> V_43 ) ;
V_3 = F_31 ( V_41 -> V_42 , V_32 , & V_33 ) ;
F_32 ( & V_41 -> V_42 -> V_43 ) ;
if ( V_3 )
return F_2 ( V_2 , V_19 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] &= ~ 0xff ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] |= V_33 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned long V_32 ;
int V_34 , V_35 ;
int V_3 ;
V_3 = F_21 ( V_2 ) ;
if ( V_3 )
return V_3 != - V_31 ? V_3 : 0 ;
F_24 ( V_2 , & V_34 , & V_35 ) ;
V_32 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
V_32 = F_25 ( V_2 , V_32 ) ;
V_32 = F_26 ( V_2 , V_32 ) ;
V_32 = F_27 ( V_2 -> V_14 , F_28 ( V_32 ) ) ;
if ( F_29 ( V_32 ) )
return F_2 ( V_2 , V_19 ) ;
F_30 ( & V_41 -> V_42 -> V_43 ) ;
V_3 = F_34 ( V_41 -> V_42 , V_32 ) ;
F_32 ( & V_41 -> V_42 -> V_43 ) ;
if ( V_3 < 0 )
return F_2 ( V_2 , V_19 ) ;
F_8 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned char V_44 = V_2 -> V_7 . V_8 -> V_45 >> 28 ;
unsigned long V_46 , V_47 ;
unsigned char V_33 , V_48 ;
int V_34 , V_35 ;
int V_3 ;
V_3 = F_21 ( V_2 ) ;
if ( V_3 )
return V_3 != - V_31 ? V_3 : 0 ;
if ( ! F_36 ( V_2 -> V_14 , 8 ) )
V_44 &= ~ V_49 ;
if ( ! F_36 ( V_2 -> V_14 , 10 ) )
V_44 &= ~ ( V_50 | V_51 ) ;
if ( ! F_36 ( V_2 -> V_14 , 14 ) )
V_44 &= ~ V_52 ;
F_24 ( V_2 , & V_34 , & V_35 ) ;
V_33 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & 0xfe ;
V_46 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
V_46 = F_25 ( V_2 , V_46 ) ;
if ( V_44 & V_49 ) {
V_47 = ( V_46 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
} else {
V_46 = F_26 ( V_2 , V_46 ) ;
V_47 = V_46 + V_53 ;
}
while ( V_46 != V_47 ) {
unsigned long V_32 = F_27 ( V_2 -> V_14 , F_28 ( V_46 ) ) ;
if ( F_29 ( V_32 ) )
return F_2 ( V_2 , V_19 ) ;
F_30 ( & V_41 -> V_42 -> V_43 ) ;
V_3 = F_37 ( V_41 -> V_42 , V_32 , V_33 , & V_48 ,
V_44 & V_52 , V_44 & V_51 ,
V_44 & V_50 ) ;
F_32 ( & V_41 -> V_42 -> V_43 ) ;
if ( V_3 < 0 )
return F_2 ( V_2 , V_19 ) ;
V_46 += V_53 ;
} ;
if ( V_44 & ( V_50 | V_51 ) ) {
if ( V_44 & V_49 ) {
F_8 ( V_2 , 3 ) ;
} else {
F_8 ( V_2 , V_3 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] &= ~ 0xff00UL ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] |= ( T_2 ) V_48 << 8 ;
}
}
if ( V_44 & V_49 ) {
if ( F_38 ( V_2 -> V_7 . V_8 -> V_9 ) . V_54 == V_55 )
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] &= ~ V_40 ;
else
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] &= ~ 0xfffff000UL ;
V_47 = F_25 ( V_2 , V_47 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] |= V_47 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
V_2 -> V_17 . V_56 ++ ;
if ( F_38 ( V_2 -> V_7 . V_8 -> V_9 ) . V_57 )
return F_2 ( V_2 , V_12 ) ;
F_40 ( V_2 -> V_14 -> V_7 . V_58 , ! F_41 ( V_2 ) ) ;
F_22 ( V_2 ) ;
F_6 ( V_2 , 4 , L_5 , L_7 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_5 V_32 ;
int V_35 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
F_24 ( V_2 , NULL , & V_35 ) ;
V_32 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
V_32 = F_25 ( V_2 , V_32 ) ;
if ( F_43 ( V_2 , V_32 ) )
return F_44 ( V_2 , & V_2 -> V_7 . V_59 ) ;
V_32 = F_26 ( V_2 , V_32 ) ;
if ( F_10 ( V_2 -> V_14 , V_32 ) )
return F_2 ( V_2 , V_19 ) ;
if ( F_45 ( V_2 -> V_14 , V_32 , V_53 ) )
return - V_60 ;
F_8 ( V_2 , 0 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] = 0 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
unsigned long V_63 ;
T_3 V_64 [ 3 ] ;
int V_3 ;
T_2 V_32 ;
T_1 V_4 ;
V_32 = F_3 ( V_2 , & V_4 ) ;
if ( V_32 & 3 )
return F_2 ( V_2 , V_13 ) ;
V_62 = F_47 ( V_2 -> V_14 , V_2 -> V_7 . V_8 -> V_65 [ 6 ] , 0 ) ;
if ( ! V_62 ) {
F_8 ( V_2 , 0 ) ;
return 0 ;
}
V_64 [ 0 ] = V_62 -> V_66 . V_67 << 16 | V_62 -> V_66 . V_68 ;
V_64 [ 1 ] = V_62 -> V_66 . V_69 ;
V_64 [ 2 ] = V_62 -> V_66 . V_70 ;
if ( V_32 ) {
V_63 = sizeof( V_64 ) - 4 ;
V_3 = F_15 ( V_2 , V_32 , V_4 , & V_64 , V_63 ) ;
if ( V_3 ) {
V_3 = F_5 ( V_2 , V_3 ) ;
goto V_71;
}
} else {
V_63 = sizeof( V_64 ) ;
if ( F_48 ( V_2 , V_72 , & V_64 , V_63 ) ) {
V_3 = - V_60 ;
goto V_71;
}
}
F_49 ( V_62 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
V_71:
if ( F_50 ( V_2 -> V_14 , V_62 ) ) {
F_49 ( V_62 ) ;
V_3 = - V_60 ;
}
return V_3 ? - V_60 : 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = NULL ;
const T_2 V_73 = 0xffUL << 24 ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] )
V_62 = F_47 ( V_2 -> V_14 , V_73 ,
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] ) ;
V_2 -> V_36 -> V_74 = V_75 ;
V_2 -> V_36 -> V_76 . V_77 = ! ! V_62 ;
if ( V_62 ) {
V_2 -> V_36 -> V_76 . V_67 = V_62 -> V_66 . V_67 ;
V_2 -> V_36 -> V_76 . V_68 = V_62 -> V_66 . V_68 ;
V_2 -> V_36 -> V_76 . V_69 = V_62 -> V_66 . V_69 ;
V_2 -> V_36 -> V_76 . V_70 = V_62 -> V_66 . V_70 ;
}
V_2 -> V_36 -> V_76 . V_45 = V_2 -> V_7 . V_8 -> V_45 ;
F_49 ( V_62 ) ;
return - V_78 ;
}
static int F_52 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 4 , L_5 , L_8 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_2 -> V_14 -> V_7 . V_79 ) {
if ( V_2 -> V_7 . V_8 -> V_80 == 0xb236 )
return F_46 ( V_2 ) ;
if ( V_2 -> V_7 . V_8 -> V_80 == 0xb235 )
return F_51 ( V_2 ) ;
return - V_81 ;
} else {
F_8 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_53 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_82 ;
V_2 -> V_17 . V_83 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_82 = * V_2 -> V_14 -> V_7 . V_84 . V_85 >> 32 ;
V_3 = F_48 ( V_2 , F_54 ( struct V_86 , V_87 ) ,
& V_82 , sizeof( V_82 ) ) ;
if ( V_3 )
return V_3 ;
F_6 ( V_2 , 3 , L_9 , V_82 ) ;
F_55 ( V_2 , V_82 ) ;
return 0 ;
}
int F_56 ( T_6 * V_88 )
{
if ( V_88 -> V_10 & V_89 )
return 0 ;
if ( ( V_88 -> V_10 & V_90 ) == V_91 ) {
if ( V_88 -> V_32 & ~ V_92 )
return 0 ;
}
if ( ! ( V_88 -> V_10 & V_90 ) && ( V_88 -> V_32 & ~ V_93 ) )
return 0 ;
if ( ( V_88 -> V_10 & V_90 ) == V_94 )
return 0 ;
if ( V_88 -> V_32 & 1 )
return 0 ;
return 1 ;
}
int F_57 ( struct V_1 * V_2 )
{
T_6 * V_9 = & V_2 -> V_7 . V_8 -> V_9 ;
T_7 V_95 ;
T_2 V_32 ;
int V_3 ;
T_1 V_4 ;
if ( V_9 -> V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_32 = F_3 ( V_2 , & V_4 ) ;
if ( V_32 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_32 , V_4 , & V_95 , sizeof( V_95 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
if ( ! ( V_95 . V_10 & V_96 ) )
return F_2 ( V_2 , V_13 ) ;
V_9 -> V_10 = ( V_95 . V_10 & ~ V_96 ) << 32 ;
V_9 -> V_10 |= V_95 . V_32 & V_97 ;
V_9 -> V_32 = V_95 . V_32 & ~ V_97 ;
if ( ! F_56 ( V_9 ) )
return F_2 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_6 V_95 ;
T_2 V_32 ;
int V_3 ;
T_1 V_4 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_32 = F_3 ( V_2 , & V_4 ) ;
if ( V_32 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_32 , V_4 , & V_95 , sizeof( V_95 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_2 -> V_7 . V_8 -> V_9 = V_95 ;
if ( ! F_56 ( & V_2 -> V_7 . V_8 -> V_9 ) )
return F_2 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_2 V_98 = V_2 -> V_14 -> V_7 . V_84 . V_99 ;
T_2 V_15 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_100 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_15 ( V_2 , V_15 , V_4 , & V_98 , sizeof( V_98 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_10 , V_98 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
int V_103 = 0 ;
int V_104 ;
V_103 = F_61 ( & V_2 -> V_14 -> V_105 ) ;
if ( F_62 ( V_102 , 3 , 2 , 2 ) )
V_102 -> V_106 = 0 ;
if ( V_102 -> V_106 < 8 )
V_102 -> V_106 ++ ;
for ( V_104 = V_102 -> V_106 - 1 ; V_104 > 0 ; V_104 -- )
memcpy ( & V_102 -> V_107 [ V_104 ] , & V_102 -> V_107 [ V_104 - 1 ] , sizeof( V_102 -> V_107 [ 0 ] ) ) ;
memset ( & V_102 -> V_107 [ 0 ] , 0 , sizeof( V_102 -> V_107 [ 0 ] ) ) ;
V_102 -> V_107 [ 0 ] . V_108 = V_103 ;
V_102 -> V_107 [ 0 ] . V_109 = V_103 ;
V_102 -> V_107 [ 0 ] . V_110 = 0 ;
V_102 -> V_107 [ 0 ] . V_111 = 0 ;
V_102 -> V_107 [ 0 ] . V_112 = 1000 ;
memcpy ( V_102 -> V_107 [ 0 ] . V_113 , L_11 , 8 ) ;
F_63 ( V_102 -> V_107 [ 0 ] . V_113 , 8 ) ;
memcpy ( V_102 -> V_107 [ 0 ] . V_114 , L_12 , 16 ) ;
F_63 ( V_102 -> V_107 [ 0 ] . V_114 , 16 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_2 V_32 , T_1 V_4 ,
T_8 V_115 , T_8 V_116 , T_4 V_117 )
{
V_2 -> V_36 -> V_74 = V_118 ;
V_2 -> V_36 -> V_119 . V_32 = V_32 ;
V_2 -> V_36 -> V_119 . V_4 = V_4 ;
V_2 -> V_36 -> V_119 . V_115 = V_115 ;
V_2 -> V_36 -> V_119 . V_116 = V_116 ;
V_2 -> V_36 -> V_119 . V_117 = V_117 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_115 = ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_116 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0xff ;
int V_117 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] & 0xffff ;
unsigned long V_102 = 0 ;
T_2 V_15 ;
int V_3 = 0 ;
T_1 V_4 ;
V_2 -> V_17 . V_120 ++ ;
F_6 ( V_2 , 3 , L_13 , V_115 , V_116 , V_117 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_115 > 3 ) {
F_8 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0x0fffff00
|| V_2 -> V_36 -> V_37 . V_38 . V_39 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_13 ) ;
if ( V_115 == 0 ) {
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] = 3 << 28 ;
F_8 ( V_2 , 0 ) ;
return 0 ;
}
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 0xfff )
return F_2 ( V_2 , V_13 ) ;
switch ( V_115 ) {
case 1 :
case 2 :
V_102 = F_66 ( V_121 ) ;
if ( ! V_102 )
goto V_122;
if ( F_62 ( ( void * ) V_102 , V_115 , V_116 , V_117 ) )
goto V_122;
break;
case 3 :
if ( V_116 != 2 || V_117 != 2 )
goto V_122;
V_102 = F_66 ( V_121 ) ;
if ( ! V_102 )
goto V_122;
F_60 ( V_2 , ( void * ) V_102 ) ;
break;
}
V_3 = F_15 ( V_2 , V_15 , V_4 , ( void * ) V_102 , V_53 ) ;
if ( V_3 ) {
V_3 = F_5 ( V_2 , V_3 ) ;
goto V_123;
}
if ( V_2 -> V_14 -> V_7 . V_124 ) {
F_64 ( V_2 , V_15 , V_4 , V_115 , V_116 , V_117 ) ;
V_3 = - V_78 ;
}
F_67 ( V_2 , V_115 , V_116 , V_117 , V_15 ) ;
F_68 ( V_102 ) ;
F_8 ( V_2 , 0 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] = 0 ;
return V_3 ;
V_122:
F_8 ( V_2 , 3 ) ;
V_123:
F_68 ( V_102 ) ;
return V_3 ;
}
int F_69 ( struct V_1 * V_2 )
{
T_9 V_125 ;
V_125 = V_126 [ V_2 -> V_7 . V_8 -> V_80 & 0x00ff ] ;
if ( V_125 )
return V_125 ( V_2 ) ;
return - V_81 ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_34 , V_35 ;
F_24 ( V_2 , & V_34 , & V_35 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] &= 0xffffffff00000000UL ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] |= V_2 -> V_7 . V_8 -> V_9 . V_10 >> 32 ;
if ( V_35 ) {
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] &= 0xffffffff00000000UL ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] |=
V_2 -> V_7 . V_8 -> V_9 . V_10 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
bool V_127 = false , V_128 = false , V_129 ;
int V_34 , V_35 ;
unsigned long V_46 , V_47 ;
unsigned char V_33 ;
V_2 -> V_17 . V_130 ++ ;
F_24 ( V_2 , & V_34 , & V_35 ) ;
if ( ! F_36 ( V_2 -> V_14 , 8 ) )
return F_2 ( V_2 , V_131 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_132 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_133 &&
! F_36 ( V_2 -> V_14 , 14 ) )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_134 &&
F_36 ( V_2 -> V_14 , 10 ) ) {
V_127 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_135 ;
V_128 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_136 ;
}
V_129 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_133 ;
V_33 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_137 ;
V_46 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] & V_40 ;
V_46 = F_25 ( V_2 , V_46 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_138 ) {
if ( F_43 ( V_2 , V_46 ) )
return F_44 ( V_2 , & V_2 -> V_7 . V_59 ) ;
}
switch ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_139 ) {
case 0x00000000 :
V_46 = F_26 ( V_2 , V_46 ) ;
V_47 = ( V_46 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_47 = ( V_46 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
case 0x00002000 :
if ( ! F_36 ( V_2 -> V_14 , 78 ) ||
F_38 ( V_2 -> V_7 . V_8 -> V_9 ) . V_54 == V_140 )
return F_2 ( V_2 , V_13 ) ;
V_47 = ( V_46 + ( 1UL << 31 ) ) & ~ ( ( 1UL << 31 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_13 ) ;
}
while ( V_46 != V_47 ) {
unsigned long V_141 ;
V_141 = F_27 ( V_2 -> V_14 , F_28 ( V_46 ) ) ;
if ( F_29 ( V_141 ) )
return F_2 ( V_2 , V_19 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_138 ) {
if ( F_72 ( ( void V_142 * ) V_141 , V_53 ) )
return F_2 ( V_2 , V_19 ) ;
}
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_134 ) {
int V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_30 ( & V_41 -> V_42 -> V_43 ) ;
V_3 = F_37 ( V_41 -> V_42 , V_141 ,
V_33 , NULL , V_129 , V_127 , V_128 ) ;
F_32 ( & V_41 -> V_42 -> V_43 ) ;
if ( V_3 < 0 )
return F_2 ( V_2 , V_19 ) ;
}
V_46 += V_53 ;
}
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_34 ] & V_139 ) {
if ( F_38 ( V_2 -> V_7 . V_8 -> V_9 ) . V_54 == V_55 ) {
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] = V_47 ;
} else {
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] &= ~ 0xffffffffUL ;
V_47 = F_25 ( V_2 , V_47 ) ;
V_2 -> V_36 -> V_37 . V_38 . V_39 [ V_35 ] |= V_47 ;
}
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_143 = ( V_2 -> V_7 . V_8 -> V_144 & ~ V_40 ) >> 3 ;
unsigned long * V_144 ;
struct V_145 * V_145 ;
int V_146 ;
F_6 ( V_2 , 4 , L_14 , V_143 ) ;
V_145 = V_2 -> V_7 . V_145 ;
V_2 -> V_17 . V_147 ++ ;
if ( ! V_2 -> V_14 -> V_7 . V_148 )
return F_2 ( V_2 , V_131 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( ( ( V_2 -> V_7 . V_8 -> V_45 & 0xf0000000 ) >> 28 ) > 6 )
return F_2 ( V_2 , V_13 ) ;
F_22 ( V_2 ) ;
V_2 -> V_7 . V_8 -> V_144 &= V_40 ;
V_144 = F_74 ( V_2 -> V_7 . V_8 -> V_144 ) ;
F_30 ( & V_145 -> V_42 -> V_43 ) ;
for ( V_146 = 0 ; V_146 < V_143 ; ++ V_146 )
F_75 ( V_145 , V_144 [ V_146 ] ) ;
F_32 ( & V_145 -> V_42 -> V_43 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
T_9 V_125 ;
V_125 = V_149 [ V_2 -> V_7 . V_8 -> V_80 & 0x00ff ] ;
if ( V_125 )
return V_125 ( V_2 ) ;
return - V_81 ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_34 = ( V_2 -> V_7 . V_8 -> V_80 & 0x00f0 ) >> 4 ;
int V_150 = V_2 -> V_7 . V_8 -> V_80 & 0x000f ;
int V_151 , V_3 , V_152 ;
T_3 V_153 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_154 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_78 ( V_2 , & V_4 ) ;
if ( V_22 & 3 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_15 , V_34 , V_150 , V_22 ) ;
F_79 ( V_2 , 0 , V_34 , V_150 , V_22 ) ;
V_152 = ( ( V_150 - V_34 ) & 0xf ) + 1 ;
V_3 = F_4 ( V_2 , V_22 , V_4 , V_153 , V_152 * sizeof( T_3 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_151 = V_34 ;
V_152 = 0 ;
do {
V_2 -> V_7 . V_8 -> V_65 [ V_151 ] &= 0xffffffff00000000ul ;
V_2 -> V_7 . V_8 -> V_65 [ V_151 ] |= V_153 [ V_152 ++ ] ;
if ( V_151 == V_150 )
break;
V_151 = ( V_151 + 1 ) % 16 ;
} while ( 1 );
F_80 ( V_155 , V_2 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_34 = ( V_2 -> V_7 . V_8 -> V_80 & 0x00f0 ) >> 4 ;
int V_150 = V_2 -> V_7 . V_8 -> V_80 & 0x000f ;
int V_151 , V_3 , V_152 ;
T_3 V_153 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_156 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_78 ( V_2 , & V_4 ) ;
if ( V_22 & 3 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_16 , V_34 , V_150 , V_22 ) ;
F_82 ( V_2 , 0 , V_34 , V_150 , V_22 ) ;
V_151 = V_34 ;
V_152 = 0 ;
do {
V_153 [ V_152 ++ ] = V_2 -> V_7 . V_8 -> V_65 [ V_151 ] ;
if ( V_151 == V_150 )
break;
V_151 = ( V_151 + 1 ) % 16 ;
} while ( 1 );
V_3 = F_15 ( V_2 , V_22 , V_4 , V_153 , V_152 * sizeof( T_3 ) ) ;
return V_3 ? F_5 ( V_2 , V_3 ) : 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_34 = ( V_2 -> V_7 . V_8 -> V_80 & 0x00f0 ) >> 4 ;
int V_150 = V_2 -> V_7 . V_8 -> V_80 & 0x000f ;
int V_151 , V_3 , V_152 ;
T_2 V_153 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_157 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_84 ( V_2 , & V_4 ) ;
if ( V_22 & 7 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_17 , V_34 , V_150 , V_22 ) ;
F_79 ( V_2 , 1 , V_34 , V_150 , V_22 ) ;
V_152 = ( ( V_150 - V_34 ) & 0xf ) + 1 ;
V_3 = F_4 ( V_2 , V_22 , V_4 , V_153 , V_152 * sizeof( T_2 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_151 = V_34 ;
V_152 = 0 ;
do {
V_2 -> V_7 . V_8 -> V_65 [ V_151 ] = V_153 [ V_152 ++ ] ;
if ( V_151 == V_150 )
break;
V_151 = ( V_151 + 1 ) % 16 ;
} while ( 1 );
F_80 ( V_155 , V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_34 = ( V_2 -> V_7 . V_8 -> V_80 & 0x00f0 ) >> 4 ;
int V_150 = V_2 -> V_7 . V_8 -> V_80 & 0x000f ;
int V_151 , V_3 , V_152 ;
T_2 V_153 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_158 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_84 ( V_2 , & V_4 ) ;
if ( V_22 & 7 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_18 , V_34 , V_150 , V_22 ) ;
F_82 ( V_2 , 1 , V_34 , V_150 , V_22 ) ;
V_151 = V_34 ;
V_152 = 0 ;
do {
V_153 [ V_152 ++ ] = V_2 -> V_7 . V_8 -> V_65 [ V_151 ] ;
if ( V_151 == V_150 )
break;
V_151 = ( V_151 + 1 ) % 16 ;
} while ( 1 );
V_3 = F_15 ( V_2 , V_22 , V_4 , V_153 , V_152 * sizeof( T_2 ) ) ;
return V_3 ? F_5 ( V_2 , V_3 ) : 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
T_9 V_125 ;
V_125 = V_159 [ V_2 -> V_7 . V_8 -> V_45 & 0xff ] ;
if ( V_125 )
return V_125 ( V_2 ) ;
return - V_81 ;
}
static int F_87 ( struct V_1 * V_2 )
{
T_2 V_160 , V_161 ;
unsigned long V_162 , V_163 ;
int V_164 = 0 , V_165 = 0 ;
bool V_166 ;
T_1 V_4 ;
V_2 -> V_17 . V_167 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
F_88 ( V_2 , & V_160 , & V_161 , & V_4 , NULL ) ;
if ( V_161 & 0xf0 )
return - V_81 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_168 )
F_89 ( V_2 ) ;
V_164 = F_90 ( V_2 , V_160 , V_4 , & V_163 , V_169 ) ;
if ( V_164 == V_170 ) {
V_165 = 1 ;
V_164 = F_90 ( V_2 , V_160 , V_4 , & V_163 ,
V_171 ) ;
}
if ( V_164 ) {
if ( V_164 == V_19 || V_164 == V_172 ) {
V_164 = F_2 ( V_2 , V_164 ) ;
} else if ( V_164 > 0 ) {
F_8 ( V_2 , 3 ) ;
V_164 = 0 ;
}
goto V_173;
}
V_162 = F_91 ( V_2 -> V_14 , F_28 ( V_163 ) , & V_166 ) ;
if ( F_29 ( V_162 ) ) {
V_164 = F_2 ( V_2 , V_19 ) ;
} else {
if ( ! V_166 )
V_165 = 1 ;
F_8 ( V_2 , V_165 ) ;
}
V_173:
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_168 )
F_92 ( V_2 ) ;
return V_164 ;
}
int F_93 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_7 . V_8 -> V_80 & 0x00ff ) == 0x01 )
return F_87 ( V_2 ) ;
return - V_81 ;
}
static int F_94 ( struct V_1 * V_2 )
{
T_3 V_174 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_13 ) ;
V_174 = V_2 -> V_36 -> V_37 . V_38 . V_39 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_7 . V_8 -> V_175 = V_174 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
F_8 ( V_2 , 3 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 )
{
T_9 V_125 ;
V_125 = V_176 [ V_2 -> V_7 . V_8 -> V_80 & 0x00ff ] ;
if ( V_125 )
return V_125 ( V_2 ) ;
return - V_81 ;
}
