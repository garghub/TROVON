static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
T_1 V_3 ;
V_3 = V_1 > 0 ? V_4 : V_1 +
V_4 ;
if ( V_3 > 0 )
F_2 ( V_2 , - V_3 ) ;
V_1 = - V_1 > V_4 ? V_4 :
- V_1 ;
return V_1 ;
}
static void F_3 ( void )
{
union V_5 V_6 ;
V_6 . V_7 = 0 ;
V_6 . V_8 . V_9 = 1 ;
V_6 . V_8 . V_10 = V_11 ;
F_4 ( F_5 ( 1 ) , V_6 . V_7 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
T_1 V_1 ;
int V_14 , V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
unsigned long V_18 ;
struct V_19 * V_20 = F_7 ( V_13 ) ;
V_15 = F_8 ( V_20 -> V_21 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( F_9 ( & V_20 -> V_22 [ V_14 ] ) == 0 )
continue;
V_1 = F_10 ( V_20 -> V_2 + V_14 * 4 ,
V_4 ) ;
V_1 = F_1 ( V_1 ,
V_20 -> V_2 + V_14 * 4 ) ;
V_16 += V_1 ;
if ( V_1 > 0 ) {
struct V_23 * V_24 = NULL ;
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
while ( V_1 > 0 ) {
struct V_23 * V_26 ;
V_26 = F_12 ( & V_20 -> V_22 [ V_14 ] ) ;
V_26 -> V_27 = V_24 ;
V_24 = V_26 ;
V_1 -- ;
}
F_13 ( & V_20 -> V_22 [ V_14 ] . V_25 ,
V_18 ) ;
while ( V_24 ) {
struct V_23 * V_26 = V_24 ;
V_24 = V_24 -> V_27 ;
F_14 ( V_26 ) ;
}
}
V_17 += F_9 ( & V_20 -> V_22 [ V_14 ] ) ;
}
if ( V_16 >= 0 && F_15 ( V_13 ) )
F_16 ( V_13 ) ;
if ( V_17 )
F_3 () ;
}
int F_17 ( struct V_23 * V_28 , struct V_12 * V_13 )
{
T_2 V_29 ;
union V_30 V_31 ;
T_3 V_32 ;
T_3 V_33 ;
int V_14 ;
int V_34 ;
enum { V_35 , V_36 , V_37 } V_38 ;
struct V_19 * V_20 = F_7 ( V_13 ) ;
struct V_23 * V_24 ;
T_1 V_1 ;
T_1 V_39 ;
T_4 V_40 ;
unsigned long V_18 ;
#if V_41
unsigned char * V_42 ;
#endif
F_18 ( V_20 ) ;
if ( ( V_43 > 1 ) ||
( V_44 > 1 ) ) {
V_14 = F_19 ( V_28 ) ;
if ( V_14 <= 0 )
V_14 = 0 ;
else if ( V_14 >= F_8 ( V_20 -> V_21 ) )
V_14 = 0 ;
} else
V_14 = 0 ;
if ( V_45 ) {
V_46 ;
V_32 = F_20 ( V_47 ) ;
V_33 = F_20 ( V_47 + 8 ) ;
F_21 ( V_47 + 8 ,
V_48 ,
0 ) ;
F_21 ( V_47 ,
V_20 -> V_2 + V_14 * 4 ,
V_4 ) ;
}
if ( F_22 ( F_23 ( V_28 ) -> V_49 > 5 ) ) {
if ( F_22 ( F_24 ( V_28 ) ) ) {
V_38 = V_37 ;
if ( V_45 ) {
V_46 ;
V_1 =
F_20 ( V_47 ) ;
} else {
V_1 = F_10 (
V_20 -> V_2 + V_14 * 4 , V_4 ) ;
}
V_1 = F_1 ( V_1 ,
V_20 -> V_2 + V_14 * 4 ) ;
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
goto V_50;
}
}
if ( ( V_28 -> V_10 < 64 ) && F_25 ( V_51 ) ) {
union V_52 V_53 ;
int V_54 = F_26 ( V_20 -> V_21 ) ;
int V_55 = F_27 ( V_20 -> V_21 ) ;
if ( V_54 < 2 ) {
V_53 . V_7 =
F_28 ( F_29 ( V_55 , V_54 ) ) ;
if ( V_53 . V_8 . V_56 == 0 ) {
int V_57 = 64 - V_28 -> V_10 ;
if ( ( F_30 ( V_28 ) + V_57 ) <=
F_31 ( V_28 ) )
memset ( F_32 ( V_28 , V_57 ) , 0 ,
V_57 ) ;
}
}
}
V_29 . V_7 = 0 ;
#ifdef F_33
V_29 . V_8 . V_58 = 1 ;
#endif
V_29 . V_8 . V_59 = 1 ;
V_29 . V_8 . V_60 = 1 ;
V_29 . V_8 . V_61 = V_28 -> V_10 ;
V_29 . V_8 . V_62 = V_63 ;
V_29 . V_8 . V_64 = 1 ;
V_29 . V_8 . V_65 = 1 ;
V_31 . V_7 = 0 ;
if ( F_23 ( V_28 ) -> V_49 == 0 ) {
V_31 . V_8 . V_66 = F_34 ( ( V_7 ) V_28 -> V_67 ) ;
V_31 . V_8 . V_68 = 0 ;
V_31 . V_8 . V_69 = V_28 -> V_10 ;
} else {
V_31 . V_8 . V_66 = F_34 ( ( V_7 ) V_28 -> V_67 ) ;
V_31 . V_8 . V_68 = 0 ;
V_31 . V_8 . V_69 = F_35 ( V_28 ) ;
F_36 ( V_28 ) [ 0 ] = V_31 . V_7 ;
for ( V_34 = 0 ; V_34 < F_23 ( V_28 ) -> V_49 ; V_34 ++ ) {
struct V_70 * V_71 = F_23 ( V_28 ) -> V_72 + V_34 ;
V_31 . V_8 . V_66 = F_34 (
( V_7 ) ( F_37 ( V_71 -> V_73 . V_74 ) +
V_71 -> V_75 ) ) ;
V_31 . V_8 . V_69 = V_71 -> V_69 ;
F_36 ( V_28 ) [ V_34 + 1 ] = V_31 . V_7 ;
}
V_31 . V_8 . V_66 = F_34 ( ( V_7 ) F_36 ( V_28 ) ) ;
V_31 . V_8 . V_69 = F_23 ( V_28 ) -> V_49 + 1 ;
V_29 . V_8 . V_60 = F_23 ( V_28 ) -> V_49 + 1 ;
V_29 . V_8 . V_76 = 1 ;
goto V_77;
}
#if V_41
V_42 = V_28 -> V_78 + 256 - ( ( unsigned long ) V_28 -> V_78 & 0x7f ) ;
if ( F_22 ( V_28 -> V_67 < V_42 ) ) {
goto V_77;
}
if ( F_22
( ( F_31 ( V_28 ) - V_42 ) < V_79 ) ) {
goto V_77;
}
if ( F_22 ( F_38 ( V_28 ) ) ) {
goto V_77;
}
if ( F_22 ( F_39 ( V_28 ) ) ) {
goto V_77;
}
if ( F_22 ( F_40 ( V_28 ) ) ) {
goto V_77;
}
if ( F_22 ( V_28 -> V_80 ) ) {
goto V_77;
}
if ( F_22 ( F_23 ( V_28 ) -> V_49 ) ) {
goto V_77;
}
if ( F_22
( V_28 -> V_81 !=
sizeof( * V_28 ) + F_41 ( V_28 ) ) ) {
goto V_77;
}
V_29 . V_8 . V_65 = 0 ;
V_31 . V_8 . V_82 = ( ( unsigned long ) V_28 -> V_67 >> 7 ) -
( ( unsigned long ) V_42 >> 7 ) ;
* (struct V_23 * * ) ( V_42 - sizeof( void * ) ) = V_28 ;
F_42 ( F_43 ( V_28 ) ) ;
F_44 ( V_28 , NULL ) ;
#ifdef F_45
F_46 ( V_28 -> V_83 ) ;
V_28 -> V_83 = NULL ;
#endif
F_47 ( V_28 ) ;
#ifdef F_48
V_28 -> V_84 = 0 ;
#ifdef F_49
V_28 -> V_85 = 0 ;
#endif
#endif
#endif
V_77:
if ( V_86 && ( V_28 -> V_87 == F_50 ( V_88 ) ) &&
( F_51 ( V_28 ) -> V_89 == 4 ) && ( F_51 ( V_28 ) -> V_90 == 5 ) &&
( ( F_51 ( V_28 ) -> V_91 == 0 ) || ( F_51 ( V_28 ) -> V_91 == F_50 ( 1 << 14 ) ) )
&& ( ( F_51 ( V_28 ) -> V_87 == V_92 )
|| ( F_51 ( V_28 ) -> V_87 == V_93 ) ) ) {
V_29 . V_8 . V_94 = sizeof( struct V_95 ) + 1 ;
}
if ( V_45 ) {
V_46 ;
V_1 = F_20 ( V_47 ) ;
V_39 = F_20 ( V_47 + 8 ) ;
} else {
V_1 = F_10 ( V_20 -> V_2 + V_14 * 4 ,
V_4 ) ;
V_39 =
F_10 ( V_48 , 0 ) ;
}
V_1 = F_1 ( V_1 , V_20 -> V_2 + V_14 * 4 ) ;
if ( ( V_39 < - 100 ) && ! V_29 . V_8 . V_65 )
V_29 . V_8 . V_65 = 1 ;
if ( V_29 . V_8 . V_65 ) {
V_38 = V_35 ;
V_29 . V_8 . V_96 = V_20 -> V_2 + V_14 * 4 ;
} else {
V_38 = V_36 ;
}
if ( V_45 )
F_21 (
V_47 , V_97 , 1 ) ;
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
if ( F_22 ( F_9 ( & V_20 -> V_22 [ V_14 ] ) >=
V_98 ) ) {
if ( V_13 -> V_99 != 0 ) {
F_13 ( & V_20 -> V_22 [ V_14 ] . V_25 ,
V_18 ) ;
F_52 ( V_13 ) ;
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 ,
V_18 ) ;
} else {
V_38 = V_37 ;
goto V_50;
}
}
F_53 ( V_20 -> V_21 , V_20 -> V_100 + V_14 ,
V_101 ) ;
if ( F_22 ( F_54 ( V_20 -> V_21 ,
V_20 -> V_100 + V_14 ,
V_29 , V_31 ,
V_101 ) ) ) {
F_55 ( L_1 ,
V_13 -> V_102 ) ;
V_38 = V_37 ;
}
V_50:
V_24 = NULL ;
switch ( V_38 ) {
case V_37 :
V_28 -> V_27 = V_24 ;
V_24 = V_28 ;
V_20 -> V_103 . V_104 ++ ;
break;
case V_36 :
F_2 ( V_48 , - 1 ) ;
break;
case V_35 :
F_56 ( & V_20 -> V_22 [ V_14 ] , V_28 ) ;
break;
default:
F_57 () ;
}
while ( V_1 > 0 ) {
struct V_23 * V_26 = F_12 ( & V_20 -> V_22 [ V_14 ] ) ;
V_26 -> V_27 = V_24 ;
V_24 = V_26 ;
V_1 -- ;
}
F_13 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
while ( V_24 ) {
struct V_23 * V_26 = V_24 ;
V_24 = V_24 -> V_27 ;
F_14 ( V_26 ) ;
}
if ( V_45 ) {
V_46 ;
V_40 = F_20 ( V_47 ) ;
F_58 ( V_47 , V_32 ) ;
F_58 ( V_47 + 8 , V_33 ) ;
} else {
V_40 = F_10 (
V_97 , 1 ) ;
}
if ( V_40 & 0x3ff ) {
F_59 ( & V_105 ) ;
}
F_3 () ;
return V_106 ;
}
int F_60 ( struct V_23 * V_28 , struct V_12 * V_13 )
{
struct V_19 * V_20 = F_7 ( V_13 ) ;
void * V_107 ;
void * V_108 ;
T_5 * V_109 = F_61 ( V_110 ) ;
if ( F_22 ( V_109 == NULL ) ) {
F_55 ( L_2 ,
V_13 -> V_102 ) ;
V_20 -> V_103 . V_104 ++ ;
F_14 ( V_28 ) ;
return 0 ;
}
V_107 = F_61 ( V_111 ) ;
if ( F_22 ( V_107 == NULL ) ) {
F_55 ( L_3 ,
V_13 -> V_102 ) ;
F_62 ( V_109 , V_110 , F_63 ( 1 ) ) ;
V_20 -> V_103 . V_104 ++ ;
F_14 ( V_28 ) ;
return 0 ;
}
V_108 = V_107 + sizeof( T_3 ) ;
V_108 += ( ( V_112 + 7 ) & 0xfff8 ) + 6 ;
memcpy ( V_108 , V_28 -> V_67 , V_28 -> V_10 ) ;
V_109 -> V_113 = V_28 -> V_114 ;
V_109 -> V_10 = V_28 -> V_10 ;
V_109 -> V_115 = V_20 -> V_21 ;
V_109 -> V_14 = V_20 -> V_21 & 0x7 ;
V_109 -> V_116 = V_117 ;
V_109 -> V_118 = V_119 ;
V_109 -> V_120 = V_117 ;
V_109 -> V_121 . V_7 = 0 ;
V_109 -> V_121 . V_8 . V_122 = 1 ;
V_109 -> V_123 . V_7 = 0 ;
V_109 -> V_123 . V_8 . V_66 = F_64 ( V_108 ) ;
V_109 -> V_123 . V_8 . V_68 = V_111 ;
V_109 -> V_123 . V_8 . V_69 = V_79 ;
V_109 -> V_123 . V_8 . V_82 = ( V_108 - V_107 ) >> 7 ;
if ( V_28 -> V_87 == F_50 ( V_88 ) ) {
V_109 -> V_121 . V_8 . V_124 = 14 ;
#if 0
work->word2.s.vlan_valid = 0;
work->word2.s.vlan_cfi = 0;
work->word2.s.vlan_id = 0;
work->word2.s.dec_ipcomp = 0;
#endif
V_109 -> V_121 . V_8 . V_125 =
( F_51 ( V_28 ) -> V_87 == V_92 )
|| ( F_51 ( V_28 ) -> V_87 == V_93 ) ;
#if 0
work->word2.s.dec_ipsec = 0;
work->word2.s.is_v6 = 0;
work->word2.s.software = 0;
work->word2.s.L4_error = 0;
#endif
V_109 -> V_121 . V_8 . V_126 = ! ( ( F_51 ( V_28 ) -> V_91 == 0 )
|| ( F_51 ( V_28 ) -> V_91 ==
1 << 14 ) ) ;
#if 0
work->word2.s.IP_exc = 0;
#endif
V_109 -> V_121 . V_8 . V_127 = ( V_28 -> V_128 == V_129 ) ;
V_109 -> V_121 . V_8 . V_130 = ( V_28 -> V_128 == V_131 ) ;
#if 0
work->word2.s.not_IP = 0;
work->word2.s.rcv_error = 0;
work->word2.s.err_code = 0;
#endif
memcpy ( V_109 -> V_132 , V_28 -> V_67 + 10 ,
sizeof( V_109 -> V_132 ) ) ;
} else {
#if 0
work->word2.snoip.vlan_valid = 0;
work->word2.snoip.vlan_cfi = 0;
work->word2.snoip.vlan_id = 0;
work->word2.snoip.software = 0;
#endif
V_109 -> V_121 . V_133 . V_134 = V_28 -> V_87 == F_50 ( V_135 ) ;
V_109 -> V_121 . V_133 . V_136 = V_28 -> V_87 == F_50 ( V_137 ) ;
V_109 -> V_121 . V_133 . V_127 =
( V_28 -> V_128 == V_129 ) ;
V_109 -> V_121 . V_133 . V_130 =
( V_28 -> V_128 == V_131 ) ;
V_109 -> V_121 . V_133 . V_138 = 1 ;
#if 0
work->word2.snoip.rcv_error = 0;
work->word2.snoip.err_code = 0;
#endif
memcpy ( V_109 -> V_132 , V_28 -> V_67 , sizeof( V_109 -> V_132 ) ) ;
}
F_65 ( V_109 , V_109 -> V_120 , V_109 -> V_118 , V_109 -> V_14 ,
V_109 -> V_116 ) ;
V_20 -> V_103 . V_139 ++ ;
V_20 -> V_103 . V_140 += V_28 -> V_10 ;
F_66 ( V_28 ) ;
return 0 ;
}
void F_67 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = F_7 ( V_13 ) ;
unsigned long V_18 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ ) {
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
while ( F_9 ( & V_20 -> V_22 [ V_14 ] ) )
F_14 ( F_12
( & V_20 -> V_22 [ V_14 ] ) ) ;
F_13 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
}
}
static void F_68 ( unsigned long V_141 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_142 ; V_21 ++ ) {
if ( V_143 [ V_21 ] ) {
struct V_12 * V_13 = V_143 [ V_21 ] ;
F_6 ( V_13 ) ;
}
}
}
static T_6 F_69 ( int V_144 , void * V_145 )
{
F_4 ( F_5 ( 1 ) , 0 ) ;
F_59 ( & V_105 ) ;
return V_146 ;
}
void F_70 ( void )
{
int V_34 ;
F_4 ( F_5 ( 1 ) , 0 ) ;
V_34 = F_71 ( V_147 ,
F_69 , 0 ,
L_4 , V_143 ) ;
if ( V_34 )
F_72 ( L_5 , V_147 ) ;
}
void F_73 ( void )
{
F_74 ( V_147 , V_143 ) ;
}
