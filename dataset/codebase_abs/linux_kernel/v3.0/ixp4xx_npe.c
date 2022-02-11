int F_1 ( struct V_1 * V_1 )
{
return ( F_2 ( & V_1 -> V_2 -> V_3 ) & V_4 ) != 0 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_5 , int V_6 , T_1 V_7 )
{
F_4 ( V_7 , & V_1 -> V_2 -> V_8 ) ;
F_4 ( V_5 , & V_1 -> V_2 -> V_9 ) ;
F_4 ( V_6 , & V_1 -> V_2 -> V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_1 V_5 , int V_6 )
{
F_4 ( V_5 , & V_1 -> V_2 -> V_9 ) ;
F_4 ( V_6 , & V_1 -> V_2 -> V_3 ) ;
F_2 ( & V_1 -> V_2 -> V_8 ) ;
F_2 ( & V_1 -> V_2 -> V_8 ) ;
return F_2 ( & V_1 -> V_2 -> V_8 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_10 )
{
T_1 V_11 = F_5 ( V_1 , V_10 , V_12 ) ;
F_3 ( V_1 , V_10 , V_13 , V_11 & ~ V_14 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_16 ) ;
F_6 ( V_1 , V_17 ) ;
F_4 ( V_18 , & V_1 -> V_2 -> V_3 ) ;
F_4 ( V_19 , & V_1 -> V_2 -> V_3 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_4 ( V_20 , & V_1 -> V_2 -> V_3 ) ;
F_4 ( V_18 , & V_1 -> V_2 -> V_3 ) ;
}
static int T_2 F_9 ( struct V_1 * V_1 , T_1 V_21 , T_1 V_22 ,
T_1 V_23 )
{
T_1 V_24 ;
int V_25 ;
F_3 ( V_1 , V_17 , V_13 ,
V_14 | ( V_23 << V_26 ) ) ;
F_3 ( V_1 , V_27 , V_13 ,
( V_22 << V_28 ) |
( V_22 << V_29 ) ) ;
F_4 ( V_18 , & V_1 -> V_2 -> V_3 ) ;
F_3 ( V_1 , V_30 , V_13 , V_21 ) ;
V_24 = F_2 ( & V_1 -> V_2 -> V_31 ) ;
F_4 ( V_32 , & V_1 -> V_2 -> V_3 ) ;
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ ) {
if ( V_24 != F_2 ( & V_1 -> V_2 -> V_31 ) )
return 0 ;
F_10 ( 1 ) ;
}
F_11 ( V_34 , V_1 , L_1 ) ;
return - V_35 ;
}
static int T_2 F_12 ( struct V_1 * V_1 , T_1 V_5 ,
T_3 V_11 , T_1 V_22 )
{
T_1 V_21 = V_36 |
V_5 << 9 |
( V_11 & 0x1F ) << 4 |
( V_11 & ~ 0x1F ) << ( 18 - 5 ) ;
return F_9 ( V_1 , V_21 , V_22 , 1 ) ;
}
static int T_2 F_13 ( struct V_1 * V_1 , T_1 V_5 ,
T_4 V_11 , T_1 V_22 )
{
T_1 V_21 = V_37 |
V_5 << 9 |
( V_11 & 0x1F ) << 4 |
( V_11 & ~ 0x1F ) << ( 18 - 5 ) ;
return F_9 ( V_1 , V_21 , V_22 , 1 ) ;
}
static int T_2 F_14 ( struct V_1 * V_1 , T_1 V_5 ,
T_1 V_11 , T_1 V_22 )
{
if ( F_13 ( V_1 , V_5 , V_11 >> 16 , V_22 ) )
return - V_35 ;
return F_13 ( V_1 , V_5 + 2 , V_11 & 0xFFFF , V_22 ) ;
}
static int F_15 ( struct V_1 * V_1 )
{
T_1 V_11 , V_38 , V_39 , V_40 ;
int V_25 ;
V_38 = ( F_2 ( & V_1 -> V_2 -> V_41 ) | 0x3F000000 ) &
0x3F3FFFFF ;
F_4 ( V_38 & 0x3F00FFFF , & V_1 -> V_2 -> V_41 ) ;
V_39 = F_2 ( & V_1 -> V_2 -> V_39 ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_39 ) ;
V_40 = F_5 ( V_1 , V_42 , V_12 ) ;
F_3 ( V_1 , V_42 , V_13 , V_40 |
V_43 | V_44 ) ;
while ( F_2 ( & V_1 -> V_2 -> V_45 ) & V_46 )
;
while ( F_2 ( & V_1 -> V_2 -> V_47 ) & V_48 )
F_11 ( V_49 , V_1 , L_2 ,
F_2 ( & V_1 -> V_2 -> V_50 ) ) ;
while ( F_2 ( & V_1 -> V_2 -> V_47 ) & V_51 )
if ( F_9 ( V_1 , V_52 , 0 , 0 ) )
return - V_35 ;
F_4 ( V_53 , & V_1 -> V_2 -> V_54 ) ;
if ( F_9 ( V_1 , V_55 , 0 , 0 ) )
return - V_35 ;
for ( V_11 = 0 ; V_11 < V_56 ; V_11 ++ ) {
if ( F_13 ( V_1 , V_57 , V_11 >> 1 , 0 ) )
return - V_35 ;
if ( F_14 ( V_1 , ( V_11 & 1 ) * 4 , 0 , 0 ) )
return - V_35 ;
}
V_11 = F_5 ( V_1 , V_58 , V_12 ) ;
V_11 &= ~ V_59 ;
V_11 |= ( 0 << 16 ) & V_59 ;
F_3 ( V_1 , V_58 , V_13 , V_11 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
if ( V_25 ) {
if ( F_12 ( V_1 , V_60 , 0x80 , V_25 ) )
return - V_35 ;
if ( F_13 ( V_1 , V_61 , 0 , V_25 ) )
return - V_35 ;
}
if ( F_13 ( V_1 , V_57 , 0x820 , V_25 ) )
return - V_35 ;
if ( F_12 ( V_1 , V_62 , 0 , V_25 ) )
return - V_35 ;
}
F_3 ( V_1 , V_17 , V_13 , 0 ) ;
F_4 ( V_18 , & V_1 -> V_2 -> V_3 ) ;
F_4 ( V_39 , & V_1 -> V_2 -> V_39 ) ;
F_3 ( V_1 , V_42 , V_13 , V_40 ) ;
for ( V_11 = 0 ; V_11 < F_16 ( V_63 ) ; V_11 ++ )
F_3 ( V_1 , V_63 [ V_11 ] . V_10 , V_13 ,
V_63 [ V_11 ] . V_11 ) ;
F_4 ( V_64 , & V_1 -> V_2 -> V_3 ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_39 ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_65 [ 0 ] ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_65 [ 1 ] ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_65 [ 2 ] ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_65 [ 3 ] ) ;
F_4 ( 0 , & V_1 -> V_2 -> V_31 ) ;
V_11 = F_17 () ;
F_18 ( V_11 &
~ ( V_66 << V_1 -> V_67 ) ) ;
F_18 ( V_11 |
( V_66 << V_1 -> V_67 ) ) ;
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ ) {
if ( F_17 () &
( V_66 << V_1 -> V_67 ) )
break;
F_10 ( 1 ) ;
}
if ( V_25 == V_33 )
return - V_35 ;
F_8 ( V_1 ) ;
F_4 ( V_38 , & V_1 -> V_2 -> V_41 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_1 , const void * V_68 , const char * V_69 )
{
const T_1 * V_70 = V_68 ;
int V_71 = 0 ;
F_20 ( V_1 , L_3 ,
V_69 , V_70 [ 0 ] , V_70 [ 1 ] ) ;
if ( F_2 ( & V_1 -> V_2 -> V_47 ) & V_51 ) {
F_20 ( V_1 , L_4 ) ;
return - V_72 ;
}
F_4 ( V_70 [ 0 ] , & V_1 -> V_2 -> V_50 ) ;
if ( ! ( F_2 ( & V_1 -> V_2 -> V_47 ) & V_73 ) ) {
F_20 ( V_1 , L_5 ) ;
return - V_72 ;
}
F_4 ( V_70 [ 1 ] , & V_1 -> V_2 -> V_50 ) ;
while ( ( V_71 < V_33 ) &&
( F_2 ( & V_1 -> V_2 -> V_47 ) & V_51 ) ) {
F_10 ( 1 ) ;
V_71 ++ ;
}
if ( V_71 == V_33 ) {
F_20 ( V_1 , L_6 ) ;
return - V_35 ;
}
#if V_74 > 1
F_20 ( V_1 , L_7 , V_71 ) ;
#endif
return 0 ;
}
int F_21 ( struct V_1 * V_1 , void * V_68 , const char * V_69 )
{
T_1 * V_75 = V_68 ;
int V_71 = 0 , V_76 = 0 ;
F_20 ( V_1 , L_8 , V_69 ) ;
while ( V_71 < V_33 ) {
if ( F_2 ( & V_1 -> V_2 -> V_47 ) & V_48 ) {
V_75 [ V_76 ++ ] = F_2 ( & V_1 -> V_2 -> V_50 ) ;
if ( V_76 == 2 )
break;
} else {
F_10 ( 1 ) ;
V_71 ++ ;
}
}
switch( V_76 ) {
case 1 :
F_20 ( V_1 , L_9 , V_75 [ 0 ] ) ;
break;
case 2 :
F_20 ( V_1 , L_10 , V_75 [ 0 ] , V_75 [ 1 ] ) ;
break;
}
if ( V_71 == V_33 ) {
F_20 ( V_1 , L_11 ) ;
return - V_35 ;
}
#if V_74 > 1
F_20 ( V_1 , L_12 , V_71 ) ;
#endif
return 0 ;
}
int F_22 ( struct V_1 * V_1 , void * V_68 , const char * V_69 )
{
int V_77 ;
T_1 * V_70 = V_68 , V_75 [ 2 ] ;
if ( ( V_77 = F_19 ( V_1 , V_68 , V_69 ) ) != 0 )
return V_77 ;
if ( ( V_77 = F_21 ( V_1 , V_75 , V_69 ) ) != 0 )
return V_77 ;
if ( ( V_75 [ 0 ] != V_70 [ 0 ] ) || ( V_75 [ 1 ] != V_70 [ 1 ] ) ) {
F_20 ( V_1 , L_13 ,
V_69 ) ;
return - V_72 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 , const char * V_78 , struct V_79 * V_80 )
{
const struct V_81 * V_82 ;
struct V_83 {
T_1 type ;
T_1 V_84 ;
} * V_85 ;
struct V_86 {
T_1 V_87 ;
T_1 V_67 ;
T_1 V_88 ;
union {
T_1 V_7 [ 0 ] ;
struct V_83 V_89 [ 0 ] ;
};
} * V_90 ;
struct V_91 {
T_1 V_92 ;
T_1 V_88 ;
T_1 V_7 [ 0 ] ;
} * V_93 ;
int V_25 , V_94 , V_95 , V_96 , V_97 , V_89 , V_98 ;
T_1 V_6 ;
if ( ( V_95 = F_24 ( & V_82 , V_78 , V_80 ) ) != 0 )
return V_95 ;
V_95 = - V_99 ;
if ( V_82 -> V_88 < sizeof( struct V_86 ) ) {
F_11 ( V_34 , V_1 , L_14 ) ;
goto V_95;
}
V_90 = (struct V_86 * ) V_82 -> V_7 ;
#if V_100
F_11 ( V_49 , V_1 , L_15 ,
V_90 -> V_87 , V_90 -> V_67 , V_90 -> V_88 , V_90 -> V_88 * 4 ) ;
#endif
if ( V_90 -> V_87 == F_25 ( V_101 ) ) {
V_90 -> V_67 = F_25 ( V_90 -> V_67 ) ;
V_90 -> V_88 = F_25 ( V_90 -> V_88 ) ;
} else if ( V_90 -> V_87 != V_101 ) {
F_11 ( V_34 , V_1 , L_16 ,
V_90 -> V_87 ) ;
goto V_95;
}
if ( ( V_90 -> V_88 * 4 + sizeof( struct V_86 ) ) != V_82 -> V_88 ) {
F_11 ( V_34 , V_1 ,
L_17 ) ;
goto V_95;
}
if ( ( ( V_90 -> V_67 >> 24 ) & 0xF ) != V_1 -> V_67 ) {
F_11 ( V_34 , V_1 , L_18 ) ;
goto V_95;
}
if ( V_90 -> V_87 == F_25 ( V_101 ) )
for ( V_25 = 0 ; V_25 < V_90 -> V_88 ; V_25 ++ )
V_90 -> V_7 [ V_25 ] = F_25 ( V_90 -> V_7 [ V_25 ] ) ;
if ( F_26 () && ( ( V_90 -> V_67 >> 28 ) & 0xF ) ) {
F_11 ( V_102 , V_1 , L_19
L_20 ) ;
goto V_95;
}
if ( F_1 ( V_1 ) ) {
F_11 ( V_102 , V_1 , L_21
L_22 ) ;
V_95 = - V_103 ;
goto V_95;
}
#if 0
npe_stop(npe);
npe_reset(npe);
#endif
F_11 ( V_102 , V_1 , L_23
L_24 , ( V_90 -> V_67 >> 16 ) & 0xFF ,
( V_90 -> V_67 >> 8 ) & 0xFF , V_90 -> V_67 & 0xFF ) ;
if ( F_26 () ) {
if ( ! V_1 -> V_67 )
V_97 = V_104 ;
else
V_97 = V_105 ;
V_96 = V_106 ;
} else {
V_97 = V_107 ;
V_96 = V_108 ;
}
for ( V_89 = 0 ; V_89 * sizeof( struct V_83 ) / 4 < V_90 -> V_88 ;
V_89 ++ )
if ( V_90 -> V_89 [ V_89 ] . type == V_109 )
break;
if ( V_89 * sizeof( struct V_83 ) / 4 >= V_90 -> V_88 ) {
F_11 ( V_102 , V_1 , L_25
L_26 ) ;
goto V_95;
}
#if V_100
F_11 ( V_49 , V_1 , L_27 , V_89 ) ;
#endif
V_98 = V_89 * sizeof( struct V_83 ) / 4 + 1 ;
for ( V_25 = 0 , V_85 = V_90 -> V_89 ; V_25 < V_89 ; V_25 ++ , V_85 ++ ) {
if ( V_85 -> V_84 > V_90 -> V_88 - sizeof( struct V_91 ) / 4
|| V_85 -> V_84 < V_98 ) {
F_11 ( V_102 , V_1 , L_28
L_29 , V_85 -> V_84 , V_25 ) ;
goto V_95;
}
V_93 = (struct V_91 * ) & V_90 -> V_7 [ V_85 -> V_84 ] ;
if ( V_85 -> type == V_110 ) {
if ( V_93 -> V_92 + V_93 -> V_88 > V_97 )
goto V_111;
V_6 = V_112 ;
} else if ( V_85 -> type == V_113 ) {
if ( V_93 -> V_92 + V_93 -> V_88 > V_96 )
goto V_111;
V_6 = V_114 ;
} else {
F_11 ( V_102 , V_1 , L_30
L_31 , V_25 , V_85 -> type ) ;
goto V_95;
}
if ( V_85 -> V_84 + sizeof( * V_93 ) / 4 + V_93 -> V_88 > V_90 -> V_88 ) {
F_11 ( V_102 , V_1 , L_32
L_33
L_34 , V_25 ,
V_85 -> type == V_110 ? 'I' : 'D' ,
V_93 -> V_92 , V_93 -> V_88 ) ;
goto V_95;
}
for ( V_94 = 0 ; V_94 < V_93 -> V_88 ; V_94 ++ )
F_3 ( V_1 , V_93 -> V_92 + V_94 , V_6 , V_93 -> V_7 [ V_94 ] ) ;
}
F_7 ( V_1 ) ;
if ( ! F_1 ( V_1 ) )
F_11 ( V_34 , V_1 , L_35 ) ;
F_27 ( V_82 ) ;
return 0 ;
V_111:
F_11 ( V_102 , V_1 , L_36
L_37 , V_25 ,
V_85 -> type == V_110 ? 'I' : 'D' ,
V_93 -> V_92 , V_93 -> V_88 ) ;
V_95:
F_27 ( V_82 ) ;
return V_95 ;
}
struct V_1 * F_28 ( unsigned V_67 )
{
if ( V_67 < V_115 )
if ( V_116 [ V_67 ] . V_117 )
if ( F_29 ( V_118 ) )
return & V_116 [ V_67 ] ;
return NULL ;
}
void F_30 ( struct V_1 * V_1 )
{
F_31 ( V_118 ) ;
}
static int T_5 F_32 ( void )
{
int V_25 , V_119 = 0 ;
for ( V_25 = 0 ; V_25 < V_115 ; V_25 ++ ) {
struct V_1 * V_1 = & V_116 [ V_25 ] ;
if ( ! ( F_17 () &
( V_66 << V_25 ) ) )
continue;
if ( ! ( V_1 -> V_120 = F_33 ( V_1 -> V_121 ,
V_122 ,
F_34 ( V_1 ) ) ) ) {
F_11 ( V_34 , V_1 ,
L_38 ) ;
continue;
}
if ( F_15 ( V_1 ) )
continue;
V_1 -> V_117 = 1 ;
V_119 ++ ;
}
if ( ! V_119 )
return - V_123 ;
return 0 ;
}
static void T_6 F_35 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_115 ; V_25 ++ )
if ( V_116 [ V_25 ] . V_120 ) {
F_15 ( & V_116 [ V_25 ] ) ;
F_36 ( V_116 [ V_25 ] . V_120 ) ;
}
}
