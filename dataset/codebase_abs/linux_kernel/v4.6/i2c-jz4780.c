static inline unsigned short F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned short V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned short V_6 ;
unsigned long V_7 = 5 ;
F_3 ( V_2 , V_8 , 0 ) ;
do {
V_6 = F_1 ( V_2 , V_9 ) ;
if ( ! ( V_6 & V_10 ) )
return 0 ;
F_6 ( 5000 , 15000 ) ;
} while ( -- V_7 );
F_7 ( & V_2 -> V_11 . V_12 , L_1 , V_6 ) ;
return - V_13 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned short V_6 ;
unsigned long V_7 = 5 ;
F_3 ( V_2 , V_8 , 1 ) ;
do {
V_6 = F_1 ( V_2 , V_9 ) ;
if ( V_6 & V_10 )
return 0 ;
F_6 ( 5000 , 15000 ) ;
} while ( -- V_7 );
F_7 ( & V_2 -> V_11 . V_12 , L_2 , V_6 ) ;
return - V_13 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned char V_14 )
{
unsigned short V_6 ;
unsigned long V_7 = 5 ;
do {
V_6 = F_1 ( V_2 , V_15 ) ;
if ( ( V_6 & V_16 ) &&
! ( V_6 & V_17 ) )
break;
F_6 ( 5000 , 15000 ) ;
} while ( -- V_7 );
if ( V_7 ) {
F_3 ( V_2 , V_18 , V_14 ) ;
return 0 ;
}
F_7 ( & V_2 -> V_11 . V_12 ,
L_3 ,
V_14 , V_6 ) ;
return - V_19 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_20 = F_11 ( V_2 -> V_21 ) / 1000 ;
int V_22 = 0 ;
int V_23 = 0 ;
int V_24 = 0 ;
int V_25 = 0 ;
int V_26 = 0 ;
unsigned short V_27 = 0 ;
int V_28 = V_2 -> V_29 ;
if ( F_5 ( V_2 ) )
F_12 ( & V_2 -> V_11 . V_12 , L_4 ) ;
V_24 = V_20 / V_28 ;
if ( V_28 <= 100 )
V_22 = ( V_24 * 4000 ) / ( 4700 + 4000 ) ;
else
V_22 = ( V_24 * 600 ) / ( 1300 + 600 ) ;
V_23 = V_24 - V_22 ;
if ( V_28 <= 100 ) {
V_27 = V_30 | V_31
| V_32 | V_33 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_3 ( V_2 , V_35 ,
F_13 ( V_22 ) ) ;
F_3 ( V_2 , V_36 ,
F_14 ( V_23 ) ) ;
} else {
V_27 = V_37 | V_31
| V_32 | V_33 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_3 ( V_2 , V_38 ,
F_15 ( V_22 ) ) ;
F_3 ( V_2 , V_39 ,
F_16 ( V_23 ) ) ;
}
if ( V_28 <= 100 ) {
V_25 = 300 ;
V_26 = 400 ;
} else {
V_25 = 450 ;
V_26 = 450 ;
}
V_26 = ( ( V_26 * V_20 ) / 1000000 ) - 1 ;
V_25 = ( ( V_25 * V_20 ) / 1000000 ) + 1 ;
if ( V_25 > 255 )
V_25 = 255 ;
if ( V_25 <= 0 )
V_25 = 1 ;
F_3 ( V_2 , V_40 , V_25 ) ;
if ( V_26 > 255 )
V_26 = 255 ;
if ( V_26 >= 0 ) {
V_26 |= V_41 ;
F_3 ( V_2 , V_42 , V_26 ) ;
} else {
F_3 ( V_2 , V_42 , 0 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_43 ;
unsigned long V_44 ;
unsigned short V_27 ;
F_18 ( & V_2 -> V_45 , V_44 ) ;
V_27 = F_1 ( V_2 , V_34 ) ;
V_27 &= ~ V_46 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_3 ( V_2 , V_47 , 0 ) ;
F_1 ( V_2 , V_48 ) ;
F_1 ( V_2 , V_49 ) ;
V_27 = F_1 ( V_2 , V_34 ) ;
V_27 &= ~ V_10 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_19 ( 10 ) ;
V_27 |= V_10 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_20 ( & V_2 -> V_45 , V_44 ) ;
V_43 = F_5 ( V_2 ) ;
if ( V_43 )
F_7 ( & V_2 -> V_11 . V_12 ,
L_5 ) ;
if ( F_21 ( F_1 ( V_2 , V_47 )
& F_1 ( V_2 , V_50 ) ) )
F_7 ( & V_2 -> V_11 . V_12 ,
L_6 ) ;
return V_43 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
return F_8 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ )
F_3 ( V_2 , V_53 , V_54 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_47 , 0 ) ;
F_25 ( & V_2 -> V_55 ) ;
}
static T_1 F_26 ( int V_56 , void * V_57 )
{
unsigned short V_27 ;
unsigned short V_58 ;
unsigned short V_59 ;
struct V_1 * V_2 = V_57 ;
unsigned long V_44 ;
F_18 ( & V_2 -> V_45 , V_44 ) ;
V_59 = F_1 ( V_2 , V_47 ) ;
V_58 = F_1 ( V_2 , V_50 ) ;
V_58 &= V_59 ;
if ( V_58 & V_60 ) {
F_24 ( V_2 ) ;
goto V_61;
}
if ( V_58 & V_62 ) {
F_12 ( & V_2 -> V_11 . V_12 , L_7 ) ;
F_24 ( V_2 ) ;
goto V_61;
}
if ( V_2 -> V_63 == 0 ) {
int V_64 ;
while ( ( F_1 ( V_2 , V_15 )
& V_65 ) ) {
* ( V_2 -> V_66 ++ ) = F_1 ( V_2 , V_53 )
& 0xff ;
V_2 -> V_67 ++ ;
if ( V_2 -> V_67 == V_2 -> V_68 ) {
F_24 ( V_2 ) ;
goto V_61;
}
}
V_64 = V_2 -> V_68 - V_2 -> V_67 ;
if ( V_64 <= V_69 )
F_3 ( V_2 , V_70 , V_64 - 1 ) ;
}
if ( V_58 & V_71 ) {
if ( V_2 -> V_63 == 0 ) {
int V_72 = V_2 -> V_68 - V_2 -> V_73 ;
int V_74 = ( V_69 - 1 )
- ( V_2 -> V_73
- V_2 -> V_67 ) ;
int V_75 = F_27 ( V_72 , V_74 ) ;
if ( V_2 -> V_73 != 0 )
V_75 = F_27 ( V_75 ,
V_69
- V_76 - 1 ) ;
if ( V_75 ) {
F_23 ( V_2 , V_75 ) ;
V_2 -> V_73 += V_75 ;
}
V_72 = V_2 -> V_68 - V_2 -> V_73 ;
if ( V_72 == 0 ) {
V_59 = F_1 ( V_2 , V_47 ) ;
V_59 &= ~ V_77 ;
F_3 ( V_2 , V_47 , V_59 ) ;
V_27 = F_1 ( V_2 , V_34 ) ;
V_27 &= ~ V_46 ;
F_3 ( V_2 , V_34 , V_27 ) ;
}
} else {
unsigned short V_78 ;
unsigned short V_79 ;
V_79 = F_1 ( V_2 , V_15 ) ;
while ( ( V_79 & V_80 ) &&
( V_2 -> V_81 > 0 ) ) {
V_79 = F_1 ( V_2 , V_15 ) ;
V_78 = * V_2 -> V_82 ;
V_78 &= ~ V_54 ;
F_3 ( V_2 , V_53 ,
V_78 ) ;
V_2 -> V_82 ++ ;
V_2 -> V_81 -- ;
}
if ( V_2 -> V_81 == 0 ) {
if ( ! V_2 -> V_83 ) {
V_27 = F_1 ( V_2 ,
V_34 ) ;
V_27 &= ~ V_46 ;
F_3 ( V_2 , V_34 ,
V_27 ) ;
}
F_24 ( V_2 ) ;
goto V_61;
}
}
}
V_61:
F_20 ( & V_2 -> V_45 , V_44 ) ;
return V_84 ;
}
static void F_28 ( struct V_1 * V_2 , int V_85 )
{
int V_52 ;
F_7 ( & V_2 -> V_11 . V_12 , L_8 , V_85 ) ;
F_7 ( & V_2 -> V_11 . V_12 , L_9 ,
F_1 ( V_2 , V_18 ) ) ;
F_7 ( & V_2 -> V_11 . V_12 , L_10 ,
V_2 -> V_86 , V_2 -> V_87 [ V_2 -> V_86 ] ) ;
F_7 ( & V_2 -> V_11 . V_12 , L_11 ,
V_2 -> V_86 , V_2 -> V_88 [ V_2 -> V_86 ] ) ;
for ( V_52 = 0 ; V_52 < 16 ; V_52 ++ ) {
if ( V_85 & F_29 ( V_52 ) )
F_12 ( & V_2 -> V_11 . V_12 , L_12 ,
V_52 , V_89 [ V_52 ] ) ;
}
}
static inline int F_30 ( struct V_1 * V_2 ,
unsigned char * V_90 , int V_91 , int V_92 ,
int V_93 )
{
int V_43 = 0 ;
long V_94 ;
int V_95 = V_96 * ( V_91 + 5 ) ;
unsigned short V_27 ;
unsigned long V_44 ;
memset ( V_90 , 0 , V_91 ) ;
F_18 ( & V_2 -> V_45 , V_44 ) ;
V_2 -> V_83 = 0 ;
V_2 -> V_63 = 0 ;
V_2 -> V_66 = V_90 ;
V_2 -> V_68 = V_91 ;
V_2 -> V_67 = 0 ;
V_2 -> V_73 = 0 ;
if ( V_91 <= V_69 )
F_3 ( V_2 , V_70 , V_91 - 1 ) ;
else
F_3 ( V_2 , V_70 , V_97 ) ;
F_3 ( V_2 , V_98 , V_76 ) ;
F_3 ( V_2 , V_47 ,
V_99 | V_77
| V_100 | V_101 ) ;
V_27 = F_1 ( V_2 , V_34 ) ;
V_27 |= V_46 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_20 ( & V_2 -> V_45 , V_44 ) ;
V_94 = F_31 ( & V_2 -> V_55 ,
F_32 ( V_95 ) ) ;
if ( ! V_94 ) {
F_7 ( & V_2 -> V_11 . V_12 , L_13 ) ;
F_12 ( & V_2 -> V_11 . V_12 , L_10 ,
V_2 -> V_86 , V_2 -> V_87 [ V_2 -> V_86 ] ) ;
F_12 ( & V_2 -> V_11 . V_12 , L_11 ,
V_2 -> V_86 , V_2 -> V_88 [ V_2 -> V_86 ] ) ;
V_43 = - V_102 ;
}
V_27 = F_1 ( V_2 , V_103 ) ;
if ( V_27 ) {
F_28 ( V_2 , V_27 ) ;
V_43 = - V_102 ;
}
return V_43 ;
}
static inline int F_33 ( struct V_1 * V_2 ,
unsigned char * V_90 , int V_91 ,
int V_92 , int V_93 )
{
int V_43 = 0 ;
int V_95 = V_96 * ( V_91 + 5 ) ;
long V_94 ;
unsigned short V_27 ;
unsigned long V_44 ;
F_18 ( & V_2 -> V_45 , V_44 ) ;
if ( V_93 < ( V_92 - 1 ) )
V_2 -> V_83 = 1 ;
else
V_2 -> V_83 = 0 ;
V_2 -> V_63 = 1 ;
V_2 -> V_82 = V_90 ;
V_2 -> V_81 = V_91 ;
F_3 ( V_2 , V_98 , V_76 ) ;
F_3 ( V_2 , V_47 , V_77
| V_100 ) ;
V_27 = F_1 ( V_2 , V_34 ) ;
V_27 |= V_46 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_20 ( & V_2 -> V_45 , V_44 ) ;
V_94 = F_31 ( & V_2 -> V_55 ,
F_32 ( V_95 ) ) ;
if ( V_94 && ! V_2 -> V_83 ) {
unsigned short V_79 ;
int V_104 ;
V_94 = V_96 * 100 ;
for (; V_94 > 0 ; V_94 -- ) {
V_79 = F_1 ( V_2 , V_15 ) ;
V_104 = ( V_79 & V_17 ) ||
! ( V_79 & V_16 ) ;
if ( ! V_104 )
break;
F_19 ( 10 ) ;
}
}
if ( ! V_94 ) {
F_7 ( & V_2 -> V_11 . V_12 , L_14 ) ;
V_43 = - V_102 ;
}
V_27 = F_1 ( V_2 , V_103 ) ;
if ( V_27 ) {
F_28 ( V_2 , V_27 ) ;
V_43 = - V_102 ;
}
return V_43 ;
}
static int F_34 ( struct V_105 * V_11 , struct V_106 * V_107 ,
int V_108 )
{
int V_52 = - V_102 ;
int V_43 = 0 ;
struct V_1 * V_2 = V_11 -> V_109 ;
V_43 = F_22 ( V_2 ) ;
if ( V_43 ) {
F_7 ( & V_2 -> V_11 . V_12 , L_15 ) ;
goto V_110;
}
if ( V_107 -> V_111 != F_1 ( V_2 , V_18 ) ) {
V_43 = F_9 ( V_2 , V_107 -> V_111 ) ;
if ( V_43 )
goto V_110;
}
for ( V_52 = 0 ; V_52 < V_108 ; V_52 ++ , V_107 ++ ) {
if ( V_107 -> V_44 & V_112 )
V_43 = F_30 ( V_2 , V_107 -> V_90 , V_107 -> V_91 ,
V_108 , V_52 ) ;
else
V_43 = F_33 ( V_2 , V_107 -> V_90 , V_107 -> V_91 ,
V_108 , V_52 ) ;
if ( V_43 )
goto V_110;
}
V_43 = V_52 ;
V_110:
F_17 ( V_2 ) ;
return V_43 ;
}
static T_2 F_35 ( struct V_105 * V_11 )
{
return V_113 | V_114 ;
}
static int F_36 ( struct V_115 * V_116 )
{
int V_43 = 0 ;
unsigned int V_117 = 0 ;
unsigned short V_27 ;
struct V_118 * V_119 ;
struct V_1 * V_2 ;
V_2 = F_37 ( & V_116 -> V_12 , sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
V_2 -> V_11 . V_122 = V_123 ;
V_2 -> V_11 . V_124 = & V_125 ;
V_2 -> V_11 . V_109 = V_2 ;
V_2 -> V_11 . V_126 = 5 ;
V_2 -> V_11 . V_12 . V_127 = & V_116 -> V_12 ;
V_2 -> V_11 . V_12 . V_128 = V_116 -> V_12 . V_128 ;
sprintf ( V_2 -> V_11 . V_129 , L_16 , V_116 -> V_129 ) ;
F_38 ( & V_2 -> V_55 ) ;
F_39 ( & V_2 -> V_45 ) ;
V_119 = F_40 ( V_116 , V_130 , 0 ) ;
V_2 -> V_4 = F_41 ( & V_116 -> V_12 , V_119 ) ;
if ( F_42 ( V_2 -> V_4 ) )
return F_43 ( V_2 -> V_4 ) ;
F_44 ( V_116 , V_2 ) ;
V_2 -> V_21 = F_45 ( & V_116 -> V_12 , NULL ) ;
if ( F_42 ( V_2 -> V_21 ) )
return F_43 ( V_2 -> V_21 ) ;
V_43 = F_46 ( V_2 -> V_21 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_47 ( V_116 -> V_12 . V_128 , L_17 ,
& V_117 ) ;
if ( V_43 ) {
F_7 ( & V_116 -> V_12 , L_18 ) ;
goto V_131;
}
V_2 -> V_29 = V_117 / 1000 ;
if ( V_2 -> V_29 == 0 ) {
V_43 = - V_132 ;
F_7 ( & V_116 -> V_12 , L_19 ) ;
goto V_131;
}
F_10 ( V_2 ) ;
F_48 ( & V_116 -> V_12 , L_20 , V_2 -> V_29 ) ;
V_27 = F_1 ( V_2 , V_34 ) ;
V_27 &= ~ V_46 ;
F_3 ( V_2 , V_34 , V_27 ) ;
F_3 ( V_2 , V_47 , 0x0 ) ;
V_2 -> V_86 = 0 ;
memset ( V_2 -> V_87 , 0 , V_133 ) ;
memset ( V_2 -> V_88 , 0 , V_133 ) ;
V_2 -> V_134 = F_49 ( V_116 , 0 ) ;
V_43 = F_50 ( & V_116 -> V_12 , V_2 -> V_134 , F_26 , 0 ,
F_51 ( & V_116 -> V_12 ) , V_2 ) ;
if ( V_43 )
goto V_131;
V_43 = F_52 ( & V_2 -> V_11 ) ;
if ( V_43 < 0 ) {
F_7 ( & V_116 -> V_12 , L_21 ) ;
goto V_131;
}
return 0 ;
V_131:
F_53 ( V_2 -> V_21 ) ;
return V_43 ;
}
static int F_54 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_55 ( V_116 ) ;
F_53 ( V_2 -> V_21 ) ;
F_56 ( & V_2 -> V_11 ) ;
return 0 ;
}
