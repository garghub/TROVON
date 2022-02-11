static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
if ( V_3 )
V_2 -> V_4 -> V_5 |= V_6 ;
else
V_2 -> V_4 -> V_5 &= ~ V_6 ;
F_2 () ;
F_3 ( V_2 , V_2 -> V_4 -> V_5 , V_5 ) ;
}
static T_1 F_4 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
T_2 V_9 = F_5 ( V_2 , V_5 ) ;
T_2 V_10 = F_5 ( V_2 , V_11 ) ;
F_6 ( V_2 -> V_12 , L_1 ,
V_9 , V_10 ) ;
if ( ! ( V_9 & V_6 ) )
return V_13 ;
F_1 ( V_2 , V_14 ) ;
F_7 ( & V_2 -> V_15 ) ;
F_6 ( V_2 -> V_12 , L_2 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_17 = V_18 + F_9 ( V_19 ) ;
while ( ( F_5 ( V_2 , V_11 ) & V_20 ) ) {
if ( F_10 ( V_18 , V_17 ) )
return - V_21 ;
F_11 () ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
unsigned long V_17 = F_9 ( V_19 ) ;
if ( V_2 -> V_7 >= 0 ) {
if ( ! F_13 ( & V_2 -> V_15 , V_17 ) )
V_22 = - V_21 ;
} else {
T_2 V_23 ;
unsigned long V_24 = V_18 + V_17 ;
do {
V_23 = F_5 ( V_2 , V_11 ) &
V_20 ;
if ( F_10 ( V_18 , V_24 ) ) {
V_22 = - V_21 ;
break;
}
F_11 () ;
} while ( ! V_23 );
}
if ( V_2 -> V_7 < 0 || V_22 == - V_21 )
F_1 ( V_2 , V_14 ) ;
return V_22 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_2 V_25 )
{
T_2 V_26 = V_2 -> V_4 -> V_11 ;
V_2 -> V_4 -> V_11 = ( V_26 & ~ V_27 ) | V_25 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_28 V_29 )
{
int V_30 = 0 ;
struct V_31 * V_32 = V_2 -> V_4 ;
V_30 = F_8 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_2 -> V_7 >= 0 )
F_16 ( & V_2 -> V_15 ) ;
F_1 ( V_2 , V_33 ) ;
V_32 -> V_11 |= V_34 ;
F_3 ( V_2 , V_32 -> V_11 , V_11 ) ;
V_30 = F_12 ( V_2 ) ;
if ( V_30 ) {
F_6 ( V_2 -> V_12 , L_3 ,
V_35 [ V_29 ] ) ;
goto V_36;
}
if ( ( V_37 || V_38 ) &&
F_5 ( V_2 , V_11 ) & V_39 ) {
V_30 = - V_40 ;
F_6 ( V_2 -> V_12 , L_4 ,
V_35 [ V_29 ] ) ;
}
V_36:
F_3 ( V_2 , 0 , V_41 ) ;
F_3 ( V_2 , 0 , V_11 ) ;
return V_30 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_3 * V_42 , unsigned int V_43 ,
struct V_44 * V_45 )
{
int V_46 , V_47 , V_30 ;
enum V_28 V_29 ;
T_2 V_5 ;
struct V_31 * V_32 = V_2 -> V_4 ;
int V_48 = V_45 -> V_49 & V_50 ;
if ( V_48 || V_43 <= V_51 ) {
V_29 = ( V_45 -> V_49 & V_52 ) ? V_53
: V_54 ;
V_32 -> V_55 |= V_56 ;
} else {
V_29 = ( V_45 -> V_49 & V_52 ) ? V_37 : V_38 ;
V_32 -> V_55 &= ~ V_56 ;
}
F_3 ( V_2 , V_32 -> V_55 , V_55 ) ;
V_5 = V_32 -> V_5 & ~ V_57 ;
if ( V_29 == V_38 || V_29 == V_54 )
V_32 -> V_5 = V_5 | V_58 ;
else
V_32 -> V_5 = V_5 | V_59 ;
F_3 ( V_2 , V_60 & ( V_43 << V_61 ) ,
V_41 ) ;
if ( V_29 == V_38 || V_29 == V_54 ) {
for ( V_46 = 0 ; V_46 < V_43 ; V_46 += 4 ) {
T_2 V_62 = 0 ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_62 >>= 8 ;
if ( ( V_46 + V_47 ) < V_43 )
V_62 |= V_42 [ V_46 + V_47 ] << 24 ;
}
F_3 ( V_2 , V_62 , V_63 [ V_46 >> 2 ] ) ;
}
}
V_30 = F_15 ( V_2 , V_29 ) ;
if ( V_30 != 0 ) {
F_6 ( V_2 -> V_12 , L_5 , V_35 [ V_29 ] ) ;
return V_30 ;
}
if ( V_29 == V_37 || V_29 == V_53 ) {
for ( V_46 = 0 ; V_46 < V_43 ; V_46 += 4 ) {
T_2 V_64 = F_5 ( V_2 , V_65 [ V_46 >> 2 ] ) ;
for ( V_47 = 0 ; V_47 < 4 &&
( V_47 + V_46 ) < V_43 ; V_47 ++ ) {
V_42 [ V_46 + V_47 ] = V_64 & 0xff ;
V_64 >>= 8 ;
}
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 * V_42 , unsigned int V_66 )
{
enum V_28 V_29 = V_66 ? V_38 : V_54 ;
F_3 ( V_2 , 1 , V_41 ) ;
F_3 ( V_2 , * V_42 , V_63 ) ;
return F_15 ( V_2 , V_29 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_44 * V_67 )
{
unsigned char V_68 ;
if ( V_67 -> V_49 & V_69 ) {
V_68 = 0xF0 | ( ( V_67 -> V_68 & 0x300 ) >> 7 ) ;
F_3 ( V_2 , V_68 , V_70 ) ;
V_68 = V_67 -> V_68 & 0xFF ;
if ( F_18 ( V_2 , & V_68 , 0 ) < 0 )
return - V_40 ;
if ( V_67 -> V_49 & V_52 ) {
F_14 ( V_2 , V_71
| V_72 ) ;
V_68 = 0xF0 | ( ( V_67 -> V_68 & 0x300 ) >> 7 ) | 0x01 ;
if ( F_18 ( V_2 , & V_68 , 0 ) < 0 )
return - V_40 ;
}
} else {
V_68 = V_67 -> V_68 << 1 ;
if ( V_67 -> V_49 & V_52 )
V_68 |= 1 ;
F_3 ( V_2 , V_68 , V_70 ) ;
}
return 0 ;
}
static int F_20 ( struct V_73 * V_74 ,
struct V_44 V_75 [] , int V_76 )
{
struct V_1 * V_2 = F_21 ( V_74 ) ;
struct V_44 * V_45 ;
int V_30 = 0 ;
int V_77 ;
int V_78 ;
T_3 * V_79 ;
int V_43 = 0 ;
if ( V_2 -> V_80 )
return - V_81 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_45 = & V_75 [ V_77 ] ;
V_43 = V_45 -> V_43 ;
V_79 = V_45 -> V_42 ;
F_6 ( V_2 -> V_12 ,
L_6 , V_77 ,
V_76 - 1 , V_45 -> V_49 ,
V_45 -> V_42 ? V_45 -> V_42 [ 0 ] : '0' , V_45 -> V_43 ) ;
if ( V_77 < ( V_76 - 1 ) && ( V_75 [ V_77 + 1 ] . V_49 & V_82 ) )
F_14 ( V_2 , ~ ( V_27 ) ) ;
else
F_14 ( V_2 ,
V_71 | V_72 ) ;
if ( ! ( V_45 -> V_49 & V_82 ) ) {
V_30 = F_19 ( V_2 , V_45 ) ;
if ( V_30 < 0 ) {
F_6 ( V_2 -> V_12 ,
L_7 ,
V_45 -> V_68 , V_77 , V_30 ) ;
goto V_83;
}
}
while ( V_43 ) {
V_78 = F_22 ( V_43 , V_51 ) ;
if ( V_43 <= V_51 && V_77 == ( V_76 - 1 ) )
F_14 ( V_2 ,
~ ( V_27 ) ) ;
V_30 = F_17 ( V_2 , V_79 ,
V_78 , V_45 ) ;
if ( V_30 < 0 )
goto V_83;
V_43 -= V_78 ;
V_79 += V_78 ;
}
}
V_30 = V_76 ;
V_83:
return V_30 ;
}
static T_2 F_23 ( struct V_73 * V_84 )
{
return V_85 | V_86 | V_87
| V_88 | V_89 ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_77 = 0 , V_90 = F_25 ( V_91 ) ;
T_2 V_92 = V_2 -> V_92 ;
for ( V_77 = 0 ; V_77 < V_90 ; V_77 ++ ) {
if ( V_91 [ V_77 ] . V_93 == V_92 ) {
V_2 -> V_4 -> V_5 &= ~ ( V_94
| V_95 ) ;
V_2 -> V_4 -> V_5 |= ( V_91 [ V_77 ] . V_96 |
V_91 [ V_77 ] . V_97 ) ;
F_3 ( V_2 , V_2 -> V_4 -> V_5 , V_5 ) ;
break;
}
}
if ( V_77 == V_90 ) {
V_77 = ( F_5 ( V_2 , V_5 ) & V_94 ) >>
V_98 ;
F_26 ( V_2 -> V_12 , L_8 ,
V_91 [ V_77 ] . V_93 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_4 -> V_55 = V_99 ;
F_3 ( V_2 , V_2 -> V_4 -> V_55 , V_55 ) ;
F_24 ( V_2 ) ;
}
static int F_28 ( struct V_100 * V_101 )
{
int V_30 = 0 ;
struct V_1 * V_2 ;
struct V_73 * V_84 ;
struct V_102 * V_103 ;
const char * V_104 ;
V_2 = F_29 ( & V_101 -> V_2 , sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return - V_106 ;
V_2 -> V_4 = F_29 ( & V_101 -> V_2 , sizeof( struct V_31 * ) ,
V_105 ) ;
if ( ! V_2 -> V_4 )
return - V_106 ;
F_30 ( V_101 , V_2 ) ;
V_2 -> V_12 = & V_101 -> V_2 ;
F_31 ( & V_2 -> V_15 ) ;
V_103 = F_32 ( V_101 , V_107 , 0 ) ;
V_2 -> V_108 = F_33 ( V_2 -> V_12 , V_103 ) ;
if ( F_34 ( V_2 -> V_108 ) ) {
V_30 = - V_106 ;
goto V_109;
}
V_30 = F_35 ( V_2 -> V_12 -> V_110 , L_9 ,
& V_104 ) ;
if ( V_30 < 0 )
V_104 = NULL ;
V_2 -> V_7 = F_36 ( V_101 , 0 ) ;
F_1 ( V_2 , V_14 ) ;
V_30 = F_37 ( & V_101 -> V_2 , V_2 -> V_7 , F_4 ,
V_111 ,
V_104 ? V_104 : V_101 -> V_112 ,
V_2 ) ;
if ( V_30 ) {
F_6 ( V_2 -> V_12 , L_10 ) ;
V_2 -> V_7 = - 1 ;
}
if ( F_38 ( V_2 -> V_12 -> V_110 ,
L_11 , & V_2 -> V_92 ) ) {
F_26 ( V_2 -> V_12 , L_12 ,
V_91 [ 0 ] . V_93 ) ;
V_2 -> V_92 = V_91 [ 0 ] . V_93 ;
}
F_27 ( V_2 ) ;
V_84 = & V_2 -> V_74 ;
F_39 ( V_84 , V_2 ) ;
V_84 -> V_113 = V_114 ;
F_40 ( V_84 -> V_112 , L_13 , sizeof( V_84 -> V_112 ) ) ;
if ( V_104 )
F_41 ( V_84 -> V_112 , V_104 , sizeof( V_84 -> V_112 ) ) ;
V_84 -> V_115 = & V_116 ;
V_84 -> V_2 . V_117 = & V_101 -> V_2 ;
V_84 -> V_2 . V_110 = V_101 -> V_2 . V_110 ;
V_30 = F_42 ( V_84 ) ;
if ( V_30 ) {
F_43 ( V_2 -> V_12 , L_14 ) ;
goto V_109;
}
F_44 ( V_2 -> V_12 , L_15 ,
V_104 ? V_104 : L_16 , V_2 -> V_92 ,
( V_2 -> V_7 >= 0 ) ? L_17 : L_18 ) ;
return 0 ;
V_109:
return V_30 ;
}
static int F_45 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = F_46 ( V_101 ) ;
F_47 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_2 )
{
struct V_1 * V_118 = F_49 ( V_2 ) ;
F_50 ( & V_118 -> V_74 ) ;
V_118 -> V_80 = true ;
F_51 ( & V_118 -> V_74 ) ;
return 0 ;
}
static int F_52 ( struct V_12 * V_2 )
{
struct V_1 * V_118 = F_49 ( V_2 ) ;
F_50 ( & V_118 -> V_74 ) ;
F_27 ( V_118 ) ;
V_118 -> V_80 = false ;
F_51 ( & V_118 -> V_74 ) ;
return 0 ;
}
