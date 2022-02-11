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
V_29 . V_8 . V_58 = 1 ;
V_29 . V_8 . V_59 = 1 ;
V_29 . V_8 . V_60 = V_28 -> V_10 ;
V_29 . V_8 . V_61 = V_62 ;
V_29 . V_8 . V_63 = 1 ;
V_29 . V_8 . V_64 = 1 ;
V_31 . V_7 = 0 ;
if ( F_23 ( V_28 ) -> V_49 == 0 ) {
V_31 . V_8 . V_65 = F_33 ( ( V_7 ) V_28 -> V_66 ) ;
V_31 . V_8 . V_67 = 0 ;
V_31 . V_8 . V_68 = V_28 -> V_10 ;
} else {
V_31 . V_8 . V_65 = F_33 ( ( V_7 ) V_28 -> V_66 ) ;
V_31 . V_8 . V_67 = 0 ;
V_31 . V_8 . V_68 = F_34 ( V_28 ) ;
F_35 ( V_28 ) [ 0 ] = V_31 . V_7 ;
for ( V_34 = 0 ; V_34 < F_23 ( V_28 ) -> V_49 ; V_34 ++ ) {
struct V_69 * V_70 = F_23 ( V_28 ) -> V_71 + V_34 ;
V_31 . V_8 . V_65 = F_33 (
( V_7 ) ( F_36 ( V_70 -> V_72 . V_73 ) +
V_70 -> V_74 ) ) ;
V_31 . V_8 . V_68 = V_70 -> V_68 ;
F_35 ( V_28 ) [ V_34 + 1 ] = V_31 . V_7 ;
}
V_31 . V_8 . V_65 = F_33 ( ( V_7 ) F_35 ( V_28 ) ) ;
V_31 . V_8 . V_68 = F_23 ( V_28 ) -> V_49 + 1 ;
V_29 . V_8 . V_59 = F_23 ( V_28 ) -> V_49 + 1 ;
V_29 . V_8 . V_75 = 1 ;
goto V_76;
}
#if V_41
V_42 = V_28 -> V_77 + 256 - ( ( unsigned long ) V_28 -> V_77 & 0x7f ) ;
if ( F_22 ( V_28 -> V_66 < V_42 ) ) {
goto V_76;
}
if ( F_22
( ( F_31 ( V_28 ) - V_42 ) < V_78 ) ) {
goto V_76;
}
if ( F_22 ( F_37 ( V_28 ) ) ) {
goto V_76;
}
if ( F_22 ( F_38 ( V_28 ) ) ) {
goto V_76;
}
if ( F_22 ( F_39 ( V_28 ) ) ) {
goto V_76;
}
if ( F_22 ( V_28 -> V_79 ) ) {
goto V_76;
}
if ( F_22 ( F_23 ( V_28 ) -> V_49 ) ) {
goto V_76;
}
if ( F_22
( V_28 -> V_80 !=
sizeof( * V_28 ) + F_40 ( V_28 ) ) ) {
goto V_76;
}
V_29 . V_8 . V_64 = 0 ;
V_31 . V_8 . V_81 = ( ( unsigned long ) V_28 -> V_66 >> 7 ) -
( ( unsigned long ) V_42 >> 7 ) ;
* (struct V_23 * * ) ( V_42 - sizeof( void * ) ) = V_28 ;
F_41 ( F_42 ( V_28 ) ) ;
F_43 ( V_28 , NULL ) ;
#ifdef F_44
F_45 ( V_28 -> V_82 ) ;
V_28 -> V_82 = NULL ;
#endif
F_46 ( V_28 ) ;
#ifdef F_47
V_28 -> V_83 = 0 ;
#ifdef F_48
V_28 -> V_84 = 0 ;
#endif
#endif
#endif
V_76:
if ( V_85 && ( V_28 -> V_86 == F_49 ( V_87 ) ) &&
( F_50 ( V_28 ) -> V_88 == 4 ) && ( F_50 ( V_28 ) -> V_89 == 5 ) &&
( ( F_50 ( V_28 ) -> V_90 == 0 ) || ( F_50 ( V_28 ) -> V_90 == 1 << 14 ) )
&& ( ( F_50 ( V_28 ) -> V_86 == V_91 )
|| ( F_50 ( V_28 ) -> V_86 == V_92 ) ) ) {
V_29 . V_8 . V_93 = sizeof( struct V_94 ) + 1 ;
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
if ( ( V_39 < - 100 ) && ! V_29 . V_8 . V_64 )
V_29 . V_8 . V_64 = 1 ;
if ( V_29 . V_8 . V_64 ) {
V_38 = V_35 ;
V_29 . V_8 . V_95 = V_20 -> V_2 + V_14 * 4 ;
} else {
V_38 = V_36 ;
}
if ( V_45 )
F_21 (
V_47 , V_96 , 1 ) ;
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 , V_18 ) ;
if ( F_22 ( F_9 ( & V_20 -> V_22 [ V_14 ] ) >=
V_97 ) ) {
if ( V_13 -> V_98 != 0 ) {
F_13 ( & V_20 -> V_22 [ V_14 ] . V_25 ,
V_18 ) ;
F_51 ( V_13 ) ;
F_11 ( & V_20 -> V_22 [ V_14 ] . V_25 ,
V_18 ) ;
} else {
V_38 = V_37 ;
goto V_50;
}
}
F_52 ( V_20 -> V_21 , V_20 -> V_99 + V_14 ,
V_100 ) ;
if ( F_22 ( F_53 ( V_20 -> V_21 ,
V_20 -> V_99 + V_14 ,
V_29 , V_31 ,
V_100 ) ) ) {
F_54 ( L_1 ,
V_13 -> V_101 ) ;
V_38 = V_37 ;
}
V_50:
V_24 = NULL ;
switch ( V_38 ) {
case V_37 :
V_28 -> V_27 = V_24 ;
V_24 = V_28 ;
V_20 -> V_102 . V_103 ++ ;
break;
case V_36 :
F_2 ( V_48 , - 1 ) ;
break;
case V_35 :
F_55 ( & V_20 -> V_22 [ V_14 ] , V_28 ) ;
break;
default:
F_56 () ;
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
F_57 ( V_47 , V_32 ) ;
F_57 ( V_47 + 8 , V_33 ) ;
} else {
V_40 = F_10 (
V_96 , 1 ) ;
}
if ( V_40 & 0x3ff ) {
F_58 ( & V_104 ) ;
}
F_3 () ;
return V_105 ;
}
int F_59 ( struct V_23 * V_28 , struct V_12 * V_13 )
{
struct V_19 * V_20 = F_7 ( V_13 ) ;
void * V_106 ;
void * V_107 ;
T_5 * V_108 = F_60 ( V_109 ) ;
if ( F_22 ( V_108 == NULL ) ) {
F_54 ( L_2 ,
V_13 -> V_101 ) ;
V_20 -> V_102 . V_103 ++ ;
F_14 ( V_28 ) ;
return 0 ;
}
V_106 = F_60 ( V_110 ) ;
if ( F_22 ( V_106 == NULL ) ) {
F_54 ( L_3 ,
V_13 -> V_101 ) ;
F_61 ( V_108 , V_109 , F_62 ( 1 ) ) ;
V_20 -> V_102 . V_103 ++ ;
F_14 ( V_28 ) ;
return 0 ;
}
V_107 = V_106 + sizeof( T_3 ) ;
V_107 += ( ( V_111 + 7 ) & 0xfff8 ) + 6 ;
memcpy ( V_107 , V_28 -> V_66 , V_28 -> V_10 ) ;
V_108 -> V_112 = V_28 -> V_113 ;
V_108 -> V_10 = V_28 -> V_10 ;
V_108 -> V_114 = V_20 -> V_21 ;
V_108 -> V_14 = V_20 -> V_21 & 0x7 ;
V_108 -> V_115 = V_116 ;
V_108 -> V_117 = V_118 ;
V_108 -> V_119 = V_116 ;
V_108 -> V_120 . V_7 = 0 ;
V_108 -> V_120 . V_8 . V_121 = 1 ;
V_108 -> V_122 . V_7 = 0 ;
V_108 -> V_122 . V_8 . V_65 = F_63 ( V_107 ) ;
V_108 -> V_122 . V_8 . V_67 = V_110 ;
V_108 -> V_122 . V_8 . V_68 = V_78 ;
V_108 -> V_122 . V_8 . V_81 = ( V_107 - V_106 ) >> 7 ;
if ( V_28 -> V_86 == F_49 ( V_87 ) ) {
V_108 -> V_120 . V_8 . V_123 = 14 ;
#if 0
work->word2.s.vlan_valid = 0;
work->word2.s.vlan_cfi = 0;
work->word2.s.vlan_id = 0;
work->word2.s.dec_ipcomp = 0;
#endif
V_108 -> V_120 . V_8 . V_124 =
( F_50 ( V_28 ) -> V_86 == V_91 )
|| ( F_50 ( V_28 ) -> V_86 == V_92 ) ;
#if 0
work->word2.s.dec_ipsec = 0;
work->word2.s.is_v6 = 0;
work->word2.s.software = 0;
work->word2.s.L4_error = 0;
#endif
V_108 -> V_120 . V_8 . V_125 = ! ( ( F_50 ( V_28 ) -> V_90 == 0 )
|| ( F_50 ( V_28 ) -> V_90 ==
1 << 14 ) ) ;
#if 0
work->word2.s.IP_exc = 0;
#endif
V_108 -> V_120 . V_8 . V_126 = ( V_28 -> V_127 == V_128 ) ;
V_108 -> V_120 . V_8 . V_129 = ( V_28 -> V_127 == V_130 ) ;
#if 0
work->word2.s.not_IP = 0;
work->word2.s.rcv_error = 0;
work->word2.s.err_code = 0;
#endif
memcpy ( V_108 -> V_131 , V_28 -> V_66 + 10 ,
sizeof( V_108 -> V_131 ) ) ;
} else {
#if 0
work->word2.snoip.vlan_valid = 0;
work->word2.snoip.vlan_cfi = 0;
work->word2.snoip.vlan_id = 0;
work->word2.snoip.software = 0;
#endif
V_108 -> V_120 . V_132 . V_133 = V_28 -> V_86 == F_49 ( V_134 ) ;
V_108 -> V_120 . V_132 . V_135 = V_28 -> V_86 == F_49 ( V_136 ) ;
V_108 -> V_120 . V_132 . V_126 =
( V_28 -> V_127 == V_128 ) ;
V_108 -> V_120 . V_132 . V_129 =
( V_28 -> V_127 == V_130 ) ;
V_108 -> V_120 . V_132 . V_137 = 1 ;
#if 0
work->word2.snoip.rcv_error = 0;
work->word2.snoip.err_code = 0;
#endif
memcpy ( V_108 -> V_131 , V_28 -> V_66 , sizeof( V_108 -> V_131 ) ) ;
}
F_64 ( V_108 , V_108 -> V_119 , V_108 -> V_117 , V_108 -> V_14 ,
V_108 -> V_115 ) ;
V_20 -> V_102 . V_138 ++ ;
V_20 -> V_102 . V_139 += V_28 -> V_10 ;
F_65 ( V_28 ) ;
return 0 ;
}
void F_66 ( struct V_12 * V_13 )
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
static void F_67 ( unsigned long V_140 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_141 ; V_21 ++ ) {
if ( V_142 [ V_21 ] ) {
struct V_12 * V_13 = V_142 [ V_21 ] ;
F_6 ( V_13 ) ;
}
}
}
static T_6 F_68 ( int V_143 , void * V_144 )
{
F_4 ( F_5 ( 1 ) , 0 ) ;
F_58 ( & V_104 ) ;
return V_145 ;
}
void F_69 ( void )
{
int V_34 ;
F_4 ( F_5 ( 1 ) , 0 ) ;
V_34 = F_70 ( V_146 ,
F_68 , 0 ,
L_4 , V_142 ) ;
if ( V_34 )
F_71 ( L_5 , V_146 ) ;
}
void F_72 ( void )
{
F_73 ( V_146 , V_142 ) ;
}
