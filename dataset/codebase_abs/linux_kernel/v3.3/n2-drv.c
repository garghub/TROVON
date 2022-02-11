static int F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case V_2 :
return 0 ;
case V_3 :
return - V_4 ;
case V_5 :
return - V_6 ;
case V_7 :
return - V_8 ;
case V_9 :
return - V_10 ;
case V_11 :
case V_12 :
return - V_13 ;
default:
return - V_14 ;
}
}
static unsigned long F_2 ( unsigned long V_15 ,
unsigned long V_16 )
{
unsigned long V_1 , V_17 , V_18 , V_19 , V_20 ;
int V_21 = 0 , V_22 = 0 ;
while ( 1 ) {
V_1 = F_3 ( V_15 , V_16 , & V_17 ,
& V_18 ,
& V_19 ,
& V_20 ) ;
if ( V_1 == V_2 )
break;
if ( V_1 == V_9 ) {
if ( ++ V_22 >= V_23 )
break;
F_4 ( 1 ) ;
} else if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
break;
F_5 ( V_18 ) ;
} else
break;
}
return V_1 ;
}
static unsigned long F_6 ( struct V_25 * V_26 , int V_16 )
{
unsigned long V_15 = F_7 ( & V_26 -> V_27 [ 0 ] ) ;
return F_2 ( V_15 , V_16 ) ;
}
static unsigned long F_8 ( struct V_25 * V_26 , int V_16 ,
unsigned long V_17 ,
unsigned long V_28 ,
unsigned long V_29 ,
unsigned long * V_18 )
{
unsigned long V_1 ;
if ( V_26 -> V_30 == 1 ) {
V_1 = F_9 ( V_28 , V_17 ,
V_29 , V_18 ) ;
} else {
V_1 = F_10 ( V_28 , V_17 ,
V_29 , V_16 ) ;
if ( V_1 == V_2 )
V_1 = F_6 ( V_26 , V_16 ) ;
* V_18 = V_31 ;
}
return V_1 ;
}
static int F_11 ( unsigned long V_32 )
{
unsigned long V_18 , V_1 ;
int V_21 = 0 , V_33 = 0 ;
while ( 1 ) {
V_1 = F_12 ( V_32 , & V_18 ) ;
if ( V_1 == V_2 )
return 0 ;
if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
return - V_34 ;
F_5 ( V_18 ) ;
} else if ( V_1 == V_5 ) {
return - V_6 ;
} else if ( V_1 == V_7 ) {
if ( ++ V_33 >= V_35 )
return - V_8 ;
F_4 ( 10000 ) ;
} else
return - V_36 ;
}
}
static unsigned long F_13 ( struct V_25 * V_26 ,
unsigned long V_16 ,
unsigned long V_32 ,
unsigned long V_37 ,
unsigned long * V_18 )
{
unsigned long V_1 ;
if ( V_26 -> V_30 == 1 ) {
V_1 = F_14 ( V_32 , V_37 , V_18 ) ;
} else {
V_1 = F_15 ( V_32 , V_37 ,
V_16 , V_18 ) ;
if ( ! * V_18 )
* V_18 = V_31 ;
}
return V_1 ;
}
static int F_16 ( struct V_25 * V_26 ,
unsigned long V_16 ,
unsigned long V_32 ,
unsigned long V_37 )
{
unsigned long V_18 , V_1 ;
int V_21 = 0 ;
while ( 1 ) {
V_1 = F_13 ( V_26 , V_16 ,
V_32 , V_37 ,
& V_18 ) ;
if ( V_1 == V_2 )
return 0 ;
if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
return - V_34 ;
F_5 ( V_18 ) ;
} else if ( V_1 == V_5 ) {
return - V_6 ;
} else if ( V_1 == V_7 ) {
return - V_8 ;
} else
return - V_36 ;
}
}
static int F_17 ( struct V_25 * V_26 ,
unsigned long V_28 ,
unsigned long V_16 ,
unsigned long V_17 )
{
unsigned long V_1 , V_18 ;
int V_21 = 0 , V_22 = 0 ;
while ( 1 ) {
V_1 = F_8 ( V_26 , V_16 , V_17 , V_28 ,
V_26 -> V_38 , & V_18 ) ;
if ( V_1 == V_2 )
return 0 ;
if ( V_1 == V_3 ) {
if ( ++ V_21 >= V_24 )
return - V_34 ;
F_5 ( V_18 ) ;
} else if ( V_1 == V_9 ) {
if ( ++ V_22 >= V_23 )
return - V_10 ;
F_4 ( 1 ) ;
} else
return - V_36 ;
}
}
static int F_18 ( struct V_25 * V_26 )
{
unsigned long V_1 ;
unsigned long V_39 ;
if ( V_26 -> V_30 == 1 ) {
V_1 = F_19 () ;
} else {
V_1 = F_3 ( 0UL , ~ 0UL , & V_39 , & V_39 , & V_39 , & V_39 ) ;
switch ( V_1 ) {
case V_3 :
case V_5 :
break;
default:
V_1 = V_2 ;
break;
}
}
return F_1 ( V_1 ) ;
}
static void F_20 ( struct V_25 * V_26 )
{
int V_40 ;
V_26 -> V_41 |= V_42 ;
V_26 -> V_43 = V_44 ;
V_26 -> V_45 = V_31 ;
V_26 -> V_38 = V_46 ;
for ( V_40 = 0 ; V_40 < V_26 -> V_47 ; V_40 ++ ) {
struct V_48 * V_49 = & V_26 -> V_50 [ V_40 ] ;
V_49 -> V_51 [ 0 ] = V_52 ;
V_49 -> V_51 [ 1 ] = V_53 ;
V_49 -> V_51 [ 2 ] = V_54 ;
V_49 -> V_51 [ 3 ] = V_55 ;
}
V_26 -> V_56 = V_57 ;
}
static int F_21 ( struct V_25 * V_26 )
{
int V_40 , V_58 , V_59 = - V_36 ;
V_58 = 0 ;
for ( V_40 = 0 ; V_40 < 100 ; V_40 ++ ) {
V_59 = F_18 ( V_26 ) ;
if ( V_59 != - V_4 )
break;
if ( ++ V_58 > 100 ) {
F_22 ( & V_26 -> V_60 -> V_61 ,
L_1 ) ;
return - V_36 ;
}
F_4 ( 1 ) ;
}
return V_59 ;
}
static int F_23 ( struct V_25 * V_26 )
{
int V_59 = F_21 ( V_26 ) ;
if ( V_59 == - V_6 )
return 0 ;
if ( V_59 )
return V_59 ;
F_20 ( V_26 ) ;
return 0 ;
}
static int F_24 ( struct V_62 * V_63 , T_1 * V_64 )
{
struct V_25 * V_26 = (struct V_25 * ) V_63 -> V_65 ;
unsigned long V_15 = F_7 ( & V_26 -> V_66 ) ;
int V_67 ;
if ( ! ( V_26 -> V_41 & V_68 ) ) {
V_67 = 0 ;
} else if ( V_26 -> V_41 & V_69 ) {
V_26 -> V_41 &= ~ V_69 ;
* V_64 = V_26 -> V_70 ;
V_67 = 4 ;
} else {
int V_59 = F_11 ( V_15 ) ;
if ( ! V_59 ) {
V_26 -> V_70 = V_26 -> V_66 >> 32 ;
* V_64 = V_26 -> V_66 & 0xffffffff ;
V_67 = 4 ;
} else {
F_22 ( & V_26 -> V_60 -> V_61 , L_2 ) ;
V_26 -> V_41 &= ~ V_68 ;
if ( ! ( V_26 -> V_41 & V_71 ) )
F_25 ( & V_26 -> V_72 , 0 ) ;
V_67 = 0 ;
}
}
return V_67 ;
}
static int F_26 ( struct V_25 * V_26 )
{
unsigned long V_15 = F_7 ( & V_26 -> V_66 ) ;
return F_11 ( V_15 ) ;
}
static int F_27 ( struct V_25 * V_26 , unsigned long V_16 ,
T_2 * V_73 , T_2 V_74 ,
T_2 * V_70 , unsigned long V_75 ,
T_2 * V_76 , T_2 V_77 )
{
unsigned long V_78 = F_7 ( V_76 ) ;
unsigned long V_79 = F_7 ( V_73 ) ;
unsigned long V_80 = F_7 ( V_70 ) ;
int V_59 ;
V_59 = F_17 ( V_26 , V_79 , V_16 , V_74 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_16 ( V_26 , V_16 ,
V_80 , V_75 ) ;
( void ) F_17 ( V_26 , V_78 , V_16 ,
V_77 ) ;
return V_59 ;
}
static T_2 F_28 ( T_2 V_81 , T_2 V_82 , int V_83 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_83 ; V_40 ++ ) {
int V_84 = ( ( V_85 ) V_82 < 0 ) ;
V_82 <<= 1 ;
if ( V_84 )
V_82 ^= V_81 ;
}
return V_82 ;
}
static int F_29 ( struct V_25 * V_26 , T_2 V_82 )
{
int V_40 , V_83 = 0 ;
for ( V_40 = 1 ; V_40 < V_86 ; V_40 ++ ) {
if ( V_26 -> V_87 [ V_40 ] == V_82 )
V_83 ++ ;
}
return V_83 ;
}
static void F_30 ( struct V_25 * V_26 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_86 ; V_40 ++ )
F_22 ( & V_26 -> V_60 -> V_61 , L_3 ,
V_40 , V_26 -> V_87 [ V_40 ] ) ;
}
static int F_31 ( struct V_25 * V_26 , unsigned long V_16 )
{
T_2 V_82 = V_88 ;
int V_59 , V_89 , V_90 ;
V_89 = 0 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
V_89 += F_29 ( V_26 , V_82 ) ;
if ( V_89 >= V_92 )
break;
V_82 = F_28 ( V_93 , V_82 , 1 ) ;
}
V_59 = 0 ;
if ( V_90 >= V_91 ) {
V_59 = - V_36 ;
F_22 ( & V_26 -> V_60 -> V_61 , L_4 , V_16 ) ;
F_30 ( V_26 ) ;
} else
F_32 ( & V_26 -> V_60 -> V_61 , L_5 , V_16 ) ;
return V_59 ;
}
static int F_33 ( struct V_25 * V_26 , unsigned long V_16 )
{
int V_59 ;
V_26 -> V_94 [ 0 ] = ( 0x2 << V_95 ) ;
V_26 -> V_94 [ 1 ] = ( 0x2 << V_95 ) ;
V_26 -> V_94 [ 2 ] = ( 0x2 << V_95 ) ;
V_26 -> V_94 [ 3 ] = ( ( 0x2 << V_95 ) |
V_96 |
( ( V_97 - 2 ) << V_98 ) ) ;
V_59 = F_27 ( V_26 , V_16 , V_26 -> V_94 ,
V_99 ,
V_26 -> V_87 ,
sizeof( V_26 -> V_87 ) ,
& V_26 -> V_50 [ V_16 ] . V_51 [ 0 ] ,
V_26 -> V_56 ) ;
if ( V_59 )
return V_59 ;
return F_31 ( V_26 , V_16 ) ;
}
static int F_34 ( struct V_25 * V_26 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_26 -> V_47 ; V_40 ++ ) {
int V_59 = F_33 ( V_26 , V_40 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static int F_35 ( struct V_25 * V_26 )
{
int V_16 , V_59 ;
V_59 = 0 ;
for ( V_16 = 0 ; V_16 < V_26 -> V_47 ; V_16 ++ ) {
struct V_48 * V_49 = & V_26 -> V_50 [ V_16 ] ;
unsigned long V_100 = F_7 ( & V_49 -> V_51 [ 0 ] ) ;
int V_101 ;
T_2 V_102 ;
V_102 = ( ( V_26 -> V_45 << V_98 ) |
( 2 << V_95 ) |
V_96 ) ;
for ( V_101 = 0 ; V_101 < 3 ; V_101 ++ )
V_49 -> V_51 [ V_101 ] = V_102 |
( V_101 << V_103 ) |
( V_104 << V_101 ) ;
V_49 -> V_51 [ 3 ] = V_102 |
( V_104 | V_105 | V_106 ) ;
V_59 = F_17 ( V_26 , V_100 , V_16 ,
V_107 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
static void F_36 ( struct V_108 * V_72 )
{
struct V_25 * V_26 = F_37 ( V_72 , struct V_25 , V_72 . V_72 ) ;
int V_59 = 0 ;
if ( ! ( V_26 -> V_41 & V_42 ) ) {
V_59 = F_26 ( V_26 ) ;
} else {
F_38 () ;
V_59 = F_34 ( V_26 ) ;
F_39 () ;
if ( ! V_59 )
V_59 = F_35 ( V_26 ) ;
}
if ( ! V_59 ) {
V_26 -> V_41 |= V_68 ;
F_32 ( & V_26 -> V_60 -> V_61 , L_6 ) ;
}
if ( V_59 && ! ( V_26 -> V_41 & V_71 ) )
F_25 ( & V_26 -> V_72 , V_109 * 2 ) ;
}
static void T_3 F_40 ( void )
{
static int V_110 ;
if ( V_110 ++ == 0 )
F_41 ( L_7 , V_111 ) ;
}
static int T_3 F_42 ( struct V_112 * V_60 )
{
const struct V_113 * V_114 ;
int V_115 ;
int V_59 = - V_116 ;
struct V_25 * V_26 ;
V_114 = F_43 ( V_117 , & V_60 -> V_61 ) ;
if ( ! V_114 )
return - V_14 ;
V_115 = ( V_114 -> V_64 != NULL ) ;
F_40 () ;
V_26 = F_44 ( sizeof( * V_26 ) , V_118 ) ;
if ( ! V_26 )
goto V_119;
V_26 -> V_60 = V_60 ;
F_45 ( & V_26 -> V_72 , F_36 ) ;
if ( V_115 )
V_26 -> V_41 |= V_120 ;
V_59 = - V_36 ;
V_26 -> V_30 = 2 ;
if ( F_46 ( V_121 ,
V_26 -> V_30 ,
& V_26 -> V_122 ) ) {
V_26 -> V_30 = 1 ;
if ( F_46 ( V_121 ,
V_26 -> V_30 ,
& V_26 -> V_122 ) ) {
F_22 ( & V_60 -> V_61 , L_8
L_9 ) ;
goto V_123;
}
}
if ( V_26 -> V_41 & V_120 ) {
if ( V_26 -> V_30 < 2 ) {
F_22 ( & V_60 -> V_61 , L_10
L_11 ,
V_26 -> V_30 ) ;
goto V_124;
}
V_26 -> V_47 = F_47 ( V_60 -> V_61 . V_125 ,
L_12 , 0 ) ;
if ( ! V_26 -> V_47 ) {
F_22 ( & V_60 -> V_61 , L_13 ) ;
goto V_124;
}
} else
V_26 -> V_47 = 1 ;
F_32 ( & V_60 -> V_61 , L_14 ,
V_26 -> V_30 , V_26 -> V_122 ) ;
V_26 -> V_50 = F_44 ( sizeof( struct V_48 ) * V_26 -> V_47 ,
V_118 ) ;
V_59 = - V_116 ;
if ( ! V_26 -> V_50 )
goto V_124;
V_59 = F_23 ( V_26 ) ;
if ( V_59 )
goto V_126;
F_32 ( & V_60 -> V_61 , L_15 ,
( ( V_26 -> V_41 & V_120 ) ?
L_16 : L_17 ) ,
V_26 -> V_47 ) ;
V_26 -> V_62 . V_127 = L_18 ;
V_26 -> V_62 . V_128 = F_24 ;
V_26 -> V_62 . V_65 = ( unsigned long ) V_26 ;
V_59 = F_48 ( & V_26 -> V_62 ) ;
if ( V_59 )
goto V_126;
F_49 ( & V_60 -> V_61 , V_26 ) ;
F_25 ( & V_26 -> V_72 , 0 ) ;
return 0 ;
V_126:
F_50 ( V_26 -> V_50 ) ;
V_26 -> V_50 = NULL ;
V_124:
F_51 ( V_121 ) ;
V_123:
F_50 ( V_26 ) ;
V_119:
return V_59 ;
}
static int T_4 F_52 ( struct V_112 * V_60 )
{
struct V_25 * V_26 = F_53 ( & V_60 -> V_61 ) ;
V_26 -> V_41 |= V_71 ;
F_54 ( & V_26 -> V_72 ) ;
F_55 ( & V_26 -> V_62 ) ;
F_51 ( V_121 ) ;
F_50 ( V_26 -> V_50 ) ;
V_26 -> V_50 = NULL ;
F_50 ( V_26 ) ;
F_49 ( & V_60 -> V_61 , NULL ) ;
return 0 ;
}
