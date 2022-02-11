static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_9 ;
F_2 ( 0 , V_2 -> V_10 + V_11 ) ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
F_2 ( F_3 ( V_6 -> V_13 ) & 0xf , V_2 -> V_10 + V_14 ) ;
F_2 ( F_4 ( V_6 -> V_13 ) , V_2 -> V_10 + V_15 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_2 ( 0 , V_2 -> V_10 + V_16 ) ;
V_9 = 100 ;
while ( V_9 -- ) {
if ( ! ( F_5 ( V_2 -> V_10 + V_17 ) &
V_18 ) ) {
V_7 [ V_8 ] =
( ( F_5 ( V_2 -> V_10 +
V_19 ) << 8 ) |
( F_5 ( V_2 -> V_10 + V_16 ) ) ) ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
break;
}
F_6 ( 1 ) ;
}
if ( ! V_9 ) {
F_7 ( V_2 , L_1 ) ;
V_7 [ 0 ] = 0 ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
return - V_20 ;
}
}
return V_8 ;
}
static T_1 F_8 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_3 * V_4 = V_2 -> V_26 ;
unsigned char V_27 , V_28 ;
int V_9 = 50 ;
while ( V_9 -- ) {
if ( ! ( F_5 ( V_2 -> V_10 + V_17 ) &
V_18 ) )
break;
F_6 ( 1 ) ;
}
if ( ! V_9 ) {
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
F_7 ( V_2 , L_2 ) ;
F_9 ( V_2 , V_4 ) ;
V_4 -> V_29 -> V_30 |= V_31 | V_32 ;
F_10 ( V_2 , V_4 ) ;
return V_33 ;
}
V_27 = F_5 ( V_2 -> V_10 + V_16 ) ;
V_28 = F_5 ( V_2 -> V_10 + V_19 ) ;
F_11 ( V_4 -> V_29 , ( V_28 << 8 ) | V_27 ) ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
if ( ++ V_24 -> V_34 >= V_24 -> V_35 )
V_24 -> V_34 = 0 ;
V_4 -> V_29 -> V_36 ++ ;
if ( V_4 -> V_29 -> V_36 >= V_24 -> V_37 ) {
V_4 -> V_29 -> V_36 = 0 ;
V_24 -> V_38 ++ ;
}
if ( ! V_24 -> V_39 )
if ( V_24 -> V_38 >= V_24 -> V_40 ) {
F_9 ( V_2 , V_4 ) ;
V_4 -> V_29 -> V_30 |= V_31 ;
}
F_10 ( V_2 , V_4 ) ;
return V_33 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned short * V_41 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_44 ;
V_4 -> V_29 -> V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
F_11 ( V_4 -> V_29 , V_41 [ V_42 ++ ] ) ;
if ( ++ V_24 -> V_34 >=
V_24 -> V_35 ) {
V_24 -> V_34 = 0 ;
}
V_4 -> V_29 -> V_36 ++ ;
if ( V_4 -> V_29 -> V_36 >= V_24 -> V_37 ) {
V_4 -> V_29 -> V_36 = 0 ;
V_24 -> V_38 ++ ;
}
if ( ! V_24 -> V_39 )
if ( V_24 -> V_38 >= V_24 -> V_40 ) {
F_9 ( V_2 , V_4 ) ;
V_4 -> V_29 -> V_30 |= V_31 ;
V_4 -> V_29 -> V_30 |= V_45 ;
break;
}
}
F_10 ( V_2 , V_4 ) ;
}
static T_1 F_13 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_3 * V_4 = V_2 -> V_26 ;
int V_43 , V_42 , V_46 ;
unsigned long V_47 ;
unsigned short * V_41 ;
F_14 ( V_24 -> V_48 ) ;
V_46 = V_24 -> V_49 ;
if ( ( V_24 -> V_50 > - 1 ) || V_24 -> V_39 ) {
V_24 -> V_49 = 1 - V_24 -> V_49 ;
F_15 ( V_24 -> V_48 , V_51 ) ;
V_47 = F_16 () ;
F_17 ( V_24 -> V_48 ,
V_24 -> V_52 [ V_24 -> V_49 ] ) ;
if ( V_24 -> V_50 ) {
F_18 ( V_24 -> V_48 ,
V_24 -> V_53 [ V_24 ->
V_49 ] ) ;
} else {
F_18 ( V_24 -> V_48 , V_24 -> V_54 ) ;
}
F_19 ( V_47 ) ;
F_20 ( V_24 -> V_48 ) ;
}
V_24 -> V_50 -- ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
V_41 = ( unsigned short * ) V_24 -> V_55 [ V_46 ] ;
V_43 = ( V_24 -> V_53 [ 0 ] >> 1 ) - V_24 -> V_56 ;
V_42 = V_24 -> V_56 ;
V_24 -> V_56 = 0 ;
F_12 ( V_2 , V_4 , V_41 , V_42 , V_43 ) ;
return V_33 ;
}
static T_1 F_21 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_23 * V_24 = V_2 -> V_25 ;
if ( ! V_2 -> V_57 ) {
F_7 ( V_2 , L_3 ) ;
return V_33 ;
}
switch ( V_24 -> V_58 ) {
case V_59 :
case V_60 :
return F_13 ( V_21 , V_22 ) ;
case V_61 :
case V_62 :
return F_8 ( V_21 , V_22 ) ;
}
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
if ( ! V_2 -> V_21 || ! V_24 -> V_63 || ! V_24 -> V_58 ) {
if ( V_24 -> V_64 ) {
V_24 -> V_64 = 0 ;
return V_33 ;
}
F_7 ( V_2 , L_4 ) ;
return V_65 ;
}
F_7 ( V_2 , L_5 ) ;
return V_65 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_66 * V_67 )
{
const struct V_68 * V_69 = F_23 ( V_2 ) ;
int V_70 = 0 ;
int V_71 , V_72 = 0 , V_73 = 0 ;
V_70 |= F_24 ( & V_67 -> V_74 , V_75 ) ;
V_70 |= F_24 ( & V_67 -> V_76 , V_77 ) ;
V_70 |= F_24 ( & V_67 -> V_78 , V_79 | V_80 ) ;
V_70 |= F_24 ( & V_67 -> V_81 , V_82 ) ;
V_70 |= F_24 ( & V_67 -> V_83 , V_82 | V_84 ) ;
if ( V_70 )
return 1 ;
V_70 |= F_25 ( V_67 -> V_78 ) ;
V_70 |= F_25 ( V_67 -> V_83 ) ;
if ( V_70 )
return 2 ;
V_70 |= F_26 ( & V_67 -> V_85 , 0 ) ;
V_70 |= F_26 ( & V_67 -> V_86 , 0 ) ;
if ( V_67 -> V_78 == V_80 )
V_70 |= F_27 ( & V_67 -> V_87 ,
V_69 -> V_88 ) ;
else
V_70 |= F_26 ( & V_67 -> V_87 , 0 ) ;
V_70 |= F_26 ( & V_67 -> V_89 , V_67 -> V_90 ) ;
if ( V_67 -> V_83 == V_82 )
V_70 |= F_27 ( & V_67 -> V_91 , 1 ) ;
else
V_70 |= F_26 ( & V_67 -> V_91 , 0 ) ;
if ( V_70 )
return 3 ;
if ( V_67 -> V_78 == V_80 ) {
V_71 = V_67 -> V_87 ;
F_28 ( V_69 -> V_92 ,
& V_72 , & V_73 ,
& V_67 -> V_87 , V_67 -> V_93 ) ;
if ( V_67 -> V_87 < V_69 -> V_88 )
V_67 -> V_87 = V_69 -> V_88 ;
if ( V_71 != V_67 -> V_87 )
V_70 ++ ;
}
if ( V_70 )
return 4 ;
if ( V_67 -> V_94 ) {
if ( ! F_29 ( V_2 , V_4 , V_67 -> V_94 ,
V_67 -> V_90 ) )
return 5 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_68 * V_69 = F_23 ( V_2 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned int V_72 = 0 , V_73 = 0 , V_47 , V_95 , V_96 ;
struct V_66 * V_67 = & V_4 -> V_29 -> V_67 ;
unsigned int V_97 ;
if ( V_67 -> V_74 != V_75 )
return - V_98 ;
if ( V_67 -> V_76 != V_77 )
return - V_98 ;
if ( V_67 -> V_81 != V_82 )
return - V_98 ;
if ( V_67 -> V_89 != V_67 -> V_90 )
return - V_98 ;
if ( V_24 -> V_63 )
return - V_99 ;
if ( V_67 -> V_78 == V_80 ) {
if ( V_67 -> V_87 < V_69 -> V_88 )
V_67 -> V_87 = V_69 -> V_88 ;
F_28 ( V_69 -> V_92 ,
& V_72 , & V_73 ,
& V_67 -> V_87 , V_67 -> V_93 ) ;
if ( V_72 == 1 ) {
V_72 = 2 ;
V_73 /= 2 ;
}
if ( V_73 == 1 ) {
V_73 = 2 ;
V_72 /= 2 ;
}
}
F_31 ( V_2 , - 1 , 0 , 0 ) ;
V_97 = F_29 ( V_2 , V_4 , V_67 -> V_94 , V_67 -> V_90 ) ;
if ( V_97 < 1 )
return - V_98 ;
F_32 ( V_2 , V_4 , V_67 -> V_94 , V_97 ) ;
F_6 ( 1 ) ;
V_24 -> V_37 = V_67 -> V_90 ;
V_24 -> V_38 = 0 ;
V_4 -> V_29 -> V_36 = 0 ;
V_24 -> V_63 = 1 ;
V_24 -> V_56 = 0 ;
V_24 -> V_64 = 0 ;
if ( V_67 -> V_83 == V_82 ) {
V_24 -> V_40 = V_67 -> V_91 ;
V_24 -> V_39 = 0 ;
} else {
V_24 -> V_40 = 0 ;
V_24 -> V_39 = 1 ;
}
if ( V_24 -> V_48 ) {
V_95 = V_24 -> V_53 [ 0 ] ;
if ( ! V_24 -> V_39 ) {
V_95 = V_4 -> V_29 -> V_67 . V_90 *
V_4 -> V_29 -> V_67 . V_90 *
sizeof( short ) ;
V_24 -> V_50 = V_95 /
V_24 -> V_53 [ 0 ] ;
V_24 -> V_54 = V_95 % V_24 -> V_53 [ 0 ] ;
V_24 -> V_50 -- ;
if ( V_24 -> V_50 >= 0 )
V_95 = V_24 -> V_53 [ 0 ] ;
} else
V_24 -> V_50 = - 1 ;
V_24 -> V_49 = 0 ;
F_15 ( V_24 -> V_48 , V_51 ) ;
V_47 = F_16 () ;
F_33 ( V_24 -> V_48 ) ;
F_17 ( V_24 -> V_48 , V_24 -> V_52 [ 0 ] ) ;
F_18 ( V_24 -> V_48 , V_95 ) ;
F_19 ( V_47 ) ;
F_20 ( V_24 -> V_48 ) ;
}
F_31 ( V_2 , 1 , V_72 , V_73 ) ;
V_96 = ( ( V_24 -> V_48 & 0x3 ) << 4 ) | ( V_2 -> V_21 & 0x7 ) ;
switch ( V_67 -> V_78 ) {
case V_80 :
V_24 -> V_58 = V_59 ;
F_2 ( 0x32 , V_2 -> V_10 + V_11 ) ;
F_2 ( V_96 , V_2 -> V_10 + V_17 ) ;
break;
default:
V_24 -> V_58 = V_60 ;
F_2 ( 0x34 , V_2 -> V_10 + V_11 ) ;
F_2 ( V_96 , V_2 -> V_10 + V_17 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned long V_93 ;
unsigned int V_100 , V_101 , V_44 ;
if ( ! V_24 -> V_48 )
return 0 ;
F_35 ( & V_2 -> V_102 , V_93 ) ;
for ( V_44 = 0 ; V_44 < 20 ; V_44 ++ ) {
V_100 = F_36 ( V_24 -> V_48 ) ;
V_101 = F_36 ( V_24 -> V_48 ) ;
if ( V_100 == V_101 )
break;
}
if ( V_100 != V_101 ) {
F_37 ( & V_2 -> V_102 , V_93 ) ;
return 0 ;
}
V_100 = V_24 -> V_53 [ 0 ] - V_100 ;
V_100 >>= 1 ;
V_101 = V_100 - V_24 -> V_56 ;
if ( V_101 < 1 ) {
F_37 ( & V_2 -> V_102 , V_93 ) ;
return 0 ;
}
F_12 ( V_2 , V_4 ,
( unsigned short * ) V_24 -> V_55 [ V_24 ->
V_49 ] ,
V_24 -> V_56 , V_101 ) ;
V_24 -> V_56 = V_100 ;
F_37 ( & V_2 -> V_102 , V_93 ) ;
return V_4 -> V_29 -> V_103 - V_4 -> V_29 -> V_104 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
if ( V_24 -> V_63 > 0 ) {
switch ( V_24 -> V_58 ) {
case V_59 :
case V_60 :
F_14 ( V_24 -> V_48 ) ;
case V_61 :
case V_62 :
F_2 ( F_5 ( V_2 -> V_10 + V_11 ) & 0x73 ,
V_2 -> V_10 + V_11 ) ;
F_6 ( 1 ) ;
F_2 ( 0 , V_2 -> V_10 + V_11 ) ;
F_2 ( 0xb0 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0x70 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0 , V_2 -> V_10 + V_16 ) ;
F_5 ( V_2 -> V_10 + V_16 ) ;
F_5 ( V_2 -> V_10 + V_19 ) ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
F_2 ( 0 , V_2 -> V_10 + V_11 ) ;
V_24 -> V_63 = 0 ;
V_24 -> V_64 = V_24 -> V_58 ;
V_24 -> V_58 = 0 ;
V_24 -> V_106 = V_4 ;
break;
}
}
return 0 ;
}
static int F_38 ( unsigned long V_10 )
{
F_2 ( 0x00 , V_10 + V_14 ) ;
F_6 ( 1 ) ;
if ( F_5 ( V_10 + V_14 ) != 0x00 )
return 1 ;
F_2 ( 0x55 , V_10 + V_14 ) ;
F_6 ( 1 ) ;
if ( F_5 ( V_10 + V_14 ) != 0x55 )
return 1 ;
F_2 ( 0x00 , V_10 + V_14 ) ;
F_6 ( 1 ) ;
F_2 ( 0x18 , V_10 + V_11 ) ;
F_6 ( 1 ) ;
if ( F_5 ( V_10 + V_11 ) != 0x18 )
return 1 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_10 + V_11 ) ;
F_2 ( 0 , V_2 -> V_10 + V_14 ) ;
F_2 ( 0 , V_2 -> V_10 + V_12 ) ;
F_2 ( 0xb0 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0x70 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0x30 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0 , V_2 -> V_10 + V_15 ) ;
}
static void
F_31 ( struct V_1 * V_2 , int V_107 , unsigned int V_72 ,
unsigned int V_73 )
{
F_2 ( 0x32 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0xff , V_2 -> V_10 + V_108 ) ;
F_2 ( 0x00 , V_2 -> V_10 + V_108 ) ;
F_6 ( 1 ) ;
F_2 ( 0xb4 , V_2 -> V_10 + V_105 ) ;
F_2 ( 0x74 , V_2 -> V_10 + V_105 ) ;
F_6 ( 1 ) ;
if ( V_107 == 1 ) {
F_40 ( V_2 -> V_109 , L_6 ,
V_107 , V_72 , V_73 ) ;
F_2 ( V_73 & 0xff , V_2 -> V_10 + V_110 ) ;
F_2 ( ( V_73 >> 8 ) & 0xff , V_2 -> V_10 + V_110 ) ;
F_2 ( V_72 & 0xff , V_2 -> V_10 + V_111 ) ;
F_2 ( ( V_72 >> 8 ) & 0xff , V_2 -> V_10 + V_111 ) ;
}
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_94 ,
unsigned int V_112 )
{
unsigned int V_113 [ 16 ] ;
unsigned int V_44 , V_114 , V_97 , V_115 ;
if ( V_112 < 1 ) {
F_7 ( V_2 , L_7 ) ;
return 0 ;
}
if ( V_112 > 1 ) {
V_113 [ 0 ] = V_94 [ 0 ] ;
for ( V_44 = 1 , V_97 = 1 ; V_44 < V_112 ; V_44 ++ , V_97 ++ ) {
if ( V_94 [ 0 ] == V_94 [ V_44 ] )
break;
V_114 =
( F_3 ( V_113 [ V_44 - 1 ] ) + 1 ) % V_112 ;
if ( V_114 != F_3 ( V_94 [ V_44 ] ) ) {
F_40 ( V_2 -> V_109 ,
L_8 ,
V_44 , F_3 ( V_94 [ V_44 ] ) , V_114 ,
F_3 ( V_94 [ 0 ] ) ) ;
return 0 ;
}
V_113 [ V_44 ] = V_94 [ V_44 ] ;
}
for ( V_44 = 0 , V_115 = 0 ; V_44 < V_112 ; V_44 ++ ) {
if ( V_94 [ V_44 ] != V_113 [ V_44 % V_97 ] ) {
F_40 ( V_2 -> V_109 ,
L_9 ,
V_44 , F_3 ( V_113 [ V_44 ] ) ,
F_4 ( V_113 [ V_44 ] ) ,
F_41 ( V_113 [ V_44 ] ) ,
F_3 ( V_94 [ V_44 % V_97 ] ) ,
F_4 ( V_94 [ V_44 % V_97 ] ) ,
F_41 ( V_113 [ V_44 % V_97 ] ) ) ;
return 0 ;
}
}
} else {
V_97 = 1 ;
}
return V_97 ;
}
static void
F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int * V_94 ,
unsigned int V_97 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned int V_44 ;
V_24 -> V_35 = V_97 ;
V_24 -> V_34 = 0 ;
for ( V_44 = 0 ; V_44 < V_97 ; V_44 ++ ) {
V_24 -> V_116 [ V_44 ] = F_3 ( V_94 [ V_44 ] ) ;
F_2 ( F_3 ( V_94 [ 0 ] ) & 0xf , V_2 -> V_10 + V_14 ) ;
F_2 ( F_4 ( V_94 [ 0 ] ) , V_2 -> V_10 + V_15 ) ;
}
F_6 ( 1 ) ;
F_2 ( V_24 -> V_116 [ 0 ] |
( V_24 -> V_116 [ V_97 - 1 ] << 4 ) ,
V_2 -> V_10 + V_14 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
const struct V_68 * V_69 = F_23 ( V_2 ) ;
struct V_23 * V_24 ;
int V_119 ;
unsigned int V_48 ;
unsigned long V_120 ;
struct V_3 * V_4 ;
V_119 = F_43 ( V_2 , V_118 -> V_121 [ 0 ] , V_69 -> V_122 ) ;
if ( V_119 )
return V_119 ;
if ( F_38 ( V_2 -> V_10 ) ) {
F_44 ( V_2 -> V_109 , L_10 ) ;
return - V_20 ;
}
V_24 = F_45 ( V_2 , sizeof( * V_24 ) ) ;
if ( ! V_24 )
return - V_123 ;
if ( ( 1 << V_118 -> V_121 [ 1 ] ) & V_69 -> V_124 ) {
V_119 = F_46 ( V_118 -> V_121 [ 1 ] , F_21 , 0 ,
V_2 -> V_125 , V_2 ) ;
if ( V_119 == 0 )
V_2 -> V_21 = V_118 -> V_121 [ 1 ] ;
}
V_24 -> V_63 = 0 ;
V_24 -> V_58 = 0 ;
V_48 = 0 ;
V_24 -> V_48 = V_48 ;
if ( ! V_2 -> V_21 )
goto V_126;
if ( V_69 -> V_127 != 0 ) {
V_48 = V_118 -> V_121 [ 2 ] ;
if ( V_48 < 1 )
goto V_126;
if ( ( ( 1 << V_48 ) & V_69 -> V_127 ) == 0 ) {
F_44 ( V_2 -> V_109 ,
L_11 ) ;
return - V_98 ;
}
V_119 = F_47 ( V_48 , V_2 -> V_125 ) ;
if ( V_119 ) {
F_44 ( V_2 -> V_109 ,
L_12 , V_48 ) ;
return - V_99 ;
}
V_24 -> V_48 = V_48 ;
V_120 = 2 ;
V_24 -> V_55 [ 0 ] = F_48 ( V_128 , V_120 ) ;
if ( ! V_24 -> V_55 [ 0 ] ) {
F_44 ( V_2 -> V_109 ,
L_13 ) ;
return - V_99 ;
}
V_24 -> V_129 [ 0 ] = V_120 ;
V_24 -> V_52 [ 0 ] = F_49 ( ( void * ) V_24 -> V_55 [ 0 ] ) ;
V_24 -> V_53 [ 0 ] = ( 1 << V_120 ) * V_130 ;
V_24 -> V_55 [ 1 ] = F_48 ( V_128 , V_120 ) ;
if ( ! V_24 -> V_55 [ 1 ] ) {
F_44 ( V_2 -> V_109 ,
L_13 ) ;
return - V_99 ;
}
V_24 -> V_129 [ 1 ] = V_120 ;
V_24 -> V_52 [ 1 ] = F_49 ( ( void * ) V_24 -> V_55 [ 1 ] ) ;
V_24 -> V_53 [ 1 ] = ( 1 << V_120 ) * V_130 ;
}
V_126:
V_119 = F_50 ( V_2 , 1 ) ;
if ( V_119 )
return V_119 ;
V_4 = & V_2 -> V_131 [ 0 ] ;
if ( V_69 -> V_132 > 0 ) {
V_4 -> type = V_133 ;
V_4 -> V_134 = V_135 | V_136 ;
V_4 -> V_137 = V_69 -> V_132 ;
V_4 -> V_138 = V_69 -> V_139 ;
V_4 -> V_140 = V_69 -> V_141 ;
V_4 -> V_142 = F_1 ;
if ( V_2 -> V_21 ) {
V_2 -> V_26 = V_4 ;
V_4 -> V_134 |= V_135 ;
V_4 -> V_143 = V_69 -> V_144 ;
V_4 -> V_145 = F_22 ;
V_4 -> V_146 = F_30 ;
V_4 -> V_147 = F_34 ;
V_4 -> V_148 = F_9 ;
}
} else {
V_4 -> type = V_149 ;
}
#if 0
case COMEDI_SUBD_AO:
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = board->ao_maxdata;
s->len_chanlist = board->ao_chanlist;
s->range_table = board->ao_range_type;
break;
case COMEDI_SUBD_DI:
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_dichan;
s->maxdata = 1;
s->len_chanlist = board->n_dichan;
s->range_table = &range_digital;
break;
case COMEDI_SUBD_DO:
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_dochan;
s->maxdata = 1;
s->len_chanlist = board->n_dochan;
s->range_table = &range_digital;
break;
#endif
F_39 ( V_2 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
if ( V_2 -> V_25 ) {
F_9 ( V_2 , V_2 -> V_26 ) ;
F_39 ( V_2 ) ;
if ( V_24 -> V_48 )
F_52 ( V_24 -> V_48 ) ;
if ( V_24 -> V_55 [ 0 ] )
F_53 ( V_24 -> V_55 [ 0 ] , V_24 -> V_129 [ 0 ] ) ;
if ( V_24 -> V_55 [ 1 ] )
F_53 ( V_24 -> V_55 [ 1 ] , V_24 -> V_129 [ 1 ] ) ;
}
F_54 ( V_2 ) ;
}
