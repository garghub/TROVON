static void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = NULL ;
V_1 -> V_3 = NULL ;
}
static void F_2 ( T_1 * V_1 , T_1 * V_4 )
{
V_4 -> V_2 = NULL ;
if ( V_1 -> V_2 == NULL )
V_1 -> V_2 = V_1 -> V_3 = V_4 ;
else {
V_4 -> V_2 = V_1 -> V_2 ;
V_1 -> V_2 = V_4 ;
}
return;
}
static int F_3 ( T_1 * V_1 , struct V_5 V_4 ) {
T_1 * V_6 = F_4 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 ) return - 1 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_2 = NULL ;
if ( V_1 -> V_2 == NULL )
V_1 -> V_2 = V_1 -> V_3 = V_6 ;
else {
V_1 -> V_3 -> V_2 = V_6 ;
V_1 -> V_3 = V_1 -> V_3 -> V_2 ;
}
return 1 ;
}
static T_1 * F_5 ( T_1 * V_1 ) {
T_1 * V_8 ;
if ( V_1 -> V_2 == NULL )
return NULL ;
V_8 = V_1 -> V_2 ;
if ( V_1 -> V_2 == V_1 -> V_3 )
V_1 -> V_2 = V_1 -> V_3 = NULL ;
else
V_1 -> V_2 = V_1 -> V_2 -> V_2 ;
return V_8 ;
}
static void F_6 ( T_2 * V_9 ) {
T_3 V_10 ;
T_3 V_11 ;
struct V_12 * V_13 = NULL ;
V_11 = F_7 ( V_9 -> V_14 + V_15 ) & 0xffff ;
while ( V_9 -> V_16 != V_11 ) {
V_10 = * ( T_3 * ) ( V_9 -> V_17 + V_9 -> V_16 ) ;
if ( ! V_10 ) ;
else if ( ! V_9 -> V_18 [ V_10 - 1 ] . V_19 ) {
F_8 (printk(L_1, desc1 -1, jiffies);)
* ( T_3 * ) ( V_9 -> V_17 + V_9 -> V_16 ) = 0 ;
}
else if ( V_9 -> V_18 [ V_10 - 1 ] . V_19 ) {
if ( ! ( V_13 = V_9 -> V_18 [ V_10 - 1 ] . V_20 ) ) {
F_9 ( L_2 ) ;
continue;
}
V_13 -> V_21 -- ;
V_9 -> V_18 [ V_10 - 1 ] . V_19 = 0 ;
F_10 (printk(L_3,
dev->desc_tbl[desc1 -1].txskb, desc1);)
if ( V_13 -> V_22 < V_9 -> V_23 ) {
F_11 ( V_9 -> V_18 [ V_10 - 1 ] . V_24 ) |= V_25 ;
if ( F_3 ( & V_9 -> V_26 , V_9 -> V_18 [ V_10 - 1 ] ) < 0 )
F_9 ( L_4 ) ;
}
V_9 -> V_18 [ V_10 - 1 ] . V_20 = NULL ;
V_9 -> V_18 [ V_10 - 1 ] . V_24 = NULL ;
}
V_9 -> V_16 += 2 ;
if ( V_9 -> V_16 > V_9 -> V_27 . V_28 )
V_9 -> V_16 = V_9 -> V_27 . V_29 ;
}
}
static T_4 F_12 ( T_2 * V_9 , struct V_12 * V_20 ) {
T_3 V_30 , V_31 ;
struct V_32 * V_33 ;
struct V_12 * V_13 = NULL ;
unsigned long V_34 ;
static unsigned long V_35 = 0 ;
int V_36 ;
F_6 ( V_9 ) ;
if( ( F_13 ( V_37 , V_35 + 50 ) ) || ( ( V_9 -> V_27 . V_38 == V_9 -> V_16 ) ) ) {
V_35 = V_37 ;
V_31 = 0 ;
while ( V_31 < V_9 -> V_39 ) {
if ( ! V_9 -> V_18 [ V_31 ] . V_19 ) {
V_31 ++ ;
continue;
}
V_36 = V_9 -> V_18 [ V_31 ] . V_20 -> V_36 ;
V_34 = V_37 - V_9 -> V_18 [ V_31 ] . V_19 ;
if ( V_34 >= V_36 ) {
F_8 (printk(L_5, i,dev->desc_tbl[i].timestamp, delta, jiffies);)
if ( V_9 -> V_27 . V_38 == V_9 -> V_27 . V_29 )
V_9 -> V_27 . V_38 = V_9 -> V_27 . V_28 ;
else
V_9 -> V_27 . V_38 -= 2 ;
* ( T_3 * ) ( V_9 -> V_17 + V_9 -> V_27 . V_38 ) = V_31 + 1 ;
if ( ! ( V_33 = V_9 -> V_18 [ V_31 ] . V_24 ) ||
! ( V_13 = V_9 -> V_18 [ V_31 ] . V_20 ) )
F_9 ( L_6 ) ;
else
V_13 -> V_21 -- ;
V_9 -> V_18 [ V_31 ] . V_19 = 0 ;
V_9 -> V_18 [ V_31 ] . V_20 = NULL ;
V_9 -> V_18 [ V_31 ] . V_24 = NULL ;
}
V_31 ++ ;
}
}
if ( V_9 -> V_27 . V_38 == V_9 -> V_16 )
return 0xFFFF ;
V_30 = * ( T_3 * ) ( V_9 -> V_17 + V_9 -> V_27 . V_38 ) ;
while ( ! V_30 || ( V_9 -> V_18 [ V_30 - 1 ] ) . V_19 ) {
V_9 -> V_27 . V_38 += 2 ;
if ( V_9 -> V_27 . V_38 > V_9 -> V_27 . V_28 )
V_9 -> V_27 . V_38 = V_9 -> V_27 . V_29 ;
if ( V_9 -> V_27 . V_38 == V_9 -> V_16 )
return 0xFFFF ;
V_30 = * ( T_3 * ) ( V_9 -> V_17 + V_9 -> V_27 . V_38 ) ;
}
V_9 -> V_18 [ V_30 - 1 ] . V_19 = V_37 ;
return V_30 ;
}
static void F_14 ( struct V_40 * V_41 , T_2 * V_9 ) {
T_5 V_42 ;
T_6 * V_43 ;
T_3 * V_44 ;
T_3 V_45 , V_46 ;
struct V_47 * V_48 = (struct V_47 * ) V_9 -> V_49 ;
struct V_50 * V_51 = (struct V_50 * ) V_9 -> V_52 ;
T_7 V_31 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_56 ) {
V_43 = ( T_6 * ) & ( V_9 -> V_57 [ V_41 -> V_58 ] -> V_59 ) ;
V_43 -> V_60 ++ ;
V_42 = 0 ;
if( V_43 -> V_60 == 0x05 ) {
V_48 += V_41 -> V_58 ;
V_51 += V_41 -> V_58 ;
if( V_51 -> V_61 ) {
if( ( V_48 -> V_62 & 0x07 ) == V_63 ) {
F_15 ( 10 ) ;
if ( ( V_51 -> V_61 ) && ( ( V_48 -> V_62 & 0x07 ) == V_63 ) )
V_42 = 1 ;
}
else {
V_45 = V_48 -> V_64 ;
V_46 = V_48 -> V_65 ;
if( ( V_45 == V_9 -> V_57 [ V_41 -> V_58 ] -> V_66 )
&& ( V_46 == V_9 -> V_57 [ V_41 -> V_58 ] -> V_67 ) )
V_42 = 1 ;
V_9 -> V_57 [ V_41 -> V_58 ] -> V_66 = V_45 ;
V_9 -> V_57 [ V_41 -> V_58 ] -> V_67 = V_46 ;
}
}
V_43 -> V_60 = 0 ;
}
if ( V_42 ) {
F_8 (printk(L_7);)
F_16 ( 0xFFFD , V_9 -> V_14 + V_68 ) ;
F_15 ( 10 ) ;
V_48 -> V_62 &= 0xFFF8 ;
V_48 -> V_62 |= 0x0001 ;
V_44 = ( T_3 * ) V_9 -> V_69 ;
for( V_31 = 0 ; ( ( V_31 < V_9 -> V_70 ) && ( V_44 [ V_31 ] ) ) ; V_31 ++ ) ;
if ( V_31 < V_9 -> V_70 )
V_44 [ V_31 ] = V_41 -> V_58 ;
else
F_17 (printk(L_8,vcc->vci);)
F_16 ( V_71 , V_9 -> V_14 + V_68 ) ;
F_16 ( ~ ( V_72 | V_73 ) , V_9 -> V_14 + V_74 ) ;
F_16 ( V_72 , V_9 -> V_14 + V_75 ) ;
V_43 -> V_60 = 0 ;
}
}
}
static T_4
F_18 ( T_8 V_76 )
{
#define F_19 0x4000
#define F_20 9
#define F_21 5
#define F_22 0x1ff
#define F_23 0x1f
T_4 V_77 ;
T_8 V_78 = V_76 & 0x00ffffff ;
int V_31 = 0 ;
if ( V_76 == 0 )
return 0 ;
while ( V_78 != 1 ) {
V_78 >>= 1 ;
V_31 ++ ;
}
if ( V_31 == F_20 )
V_77 = F_19 | ( V_31 << F_20 ) | ( V_76 & F_22 ) ;
else if ( V_31 < F_20 )
V_77 = F_19 | ( V_31 << F_20 ) | ( ( V_76 << ( F_20 - V_31 ) ) & F_22 ) ;
else
V_77 = F_19 | ( V_31 << F_20 ) | ( ( V_76 >> ( V_31 - F_20 ) ) & F_22 ) ;
return V_77 ;
}
static void F_24 ( T_2 * V_9 , T_9 * V_79 ) {
V_79 -> V_80 = V_56 ;
V_79 -> V_22 = V_9 -> V_81 ;
V_79 -> V_82 = 0 ;
V_79 -> V_83 = 0x055cb7 ;
V_79 -> V_84 = 0xffffff ;
V_79 -> V_85 = 0x3a ;
V_79 -> V_86 = 0xf ;
V_79 -> V_87 = 0xb ;
V_79 -> V_88 = 0x4 ;
V_79 -> V_89 = 0x7 ;
V_79 -> V_90 = 0x3 ;
V_79 -> V_91 = 50 ;
}
static int
F_25 ( T_2 * V_9 , T_9 * V_79 ,
struct V_40 * V_41 , T_10 V_92 )
{
T_11 * V_93 ;
T_12 * V_94 ;
T_8 V_83 ;
T_10 V_89 , V_88 , V_95 ;
T_4 V_91 , V_96 , * V_97 ;
V_93 = ( T_11 * ) V_9 -> V_49 ;
V_93 += V_41 -> V_58 ;
switch ( V_92 ) {
case 1 :
#if 0
if (srv_p->pcr == 0)
return INVALID_PCR;
if (srv_p->pcr > dev->LineRate)
srv_p->pcr = dev->LineRate;
if ((srv_p->mcr + dev->sum_mcr) > dev->LineRate)
return MCR_UNAVAILABLE;
if (srv_p->mcr > srv_p->pcr)
return INVALID_MCR;
if (!(srv_p->icr))
srv_p->icr = srv_p->pcr;
if ((srv_p->icr < srv_p->mcr) || (srv_p->icr > srv_p->pcr))
return INVALID_ICR;
if ((srv_p->tbe < MIN_TBE) || (srv_p->tbe > MAX_TBE))
return INVALID_TBE;
if ((srv_p->frtt < MIN_FRTT) || (srv_p->frtt > MAX_FRTT))
return INVALID_FRTT;
if (srv_p->nrm > MAX_NRM)
return INVALID_NRM;
if (srv_p->trm > MAX_TRM)
return INVALID_TRM;
if (srv_p->adtf > MAX_ADTF)
return INVALID_ADTF;
else if (srv_p->adtf == 0)
srv_p->adtf = 1;
if (srv_p->cdf > MAX_CDF)
return INVALID_CDF;
if (srv_p->rif > MAX_RIF)
return INVALID_RIF;
if (srv_p->rdf > MAX_RDF)
return INVALID_RDF;
#endif
memset ( ( V_98 ) V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> V_99 = V_100 ;
V_88 = 2 << V_79 -> V_88 ;
V_93 -> V_101 = V_88 << 8 | V_88 ;
V_89 = 100000 / ( 2 << ( 16 - V_79 -> V_89 ) ) ;
if ( V_89 == 0 ) V_89 = 1 ;
V_93 -> V_102 = ( ( ( V_79 -> V_88 + 1 ) & 0x0f ) << 12 ) | ( V_103 << 8 ) | V_89 ;
V_95 = V_79 -> V_84 / V_88 ;
if ( V_95 == 0 ) V_95 = 1 ;
V_93 -> V_104 = V_95 & 0xff ;
V_93 -> V_105 = F_18 ( V_79 -> V_22 ) ;
V_83 = F_26 ( V_79 -> V_83 , ( V_79 -> V_84 > V_79 -> V_85 ) ?
( ( V_79 -> V_84 / V_79 -> V_85 ) * 1000000 ) :
( 1000000 / ( V_79 -> V_85 / V_79 -> V_84 ) ) ) ;
V_93 -> V_106 = F_18 ( V_83 ) ;
V_91 = ( 10000 * V_79 -> V_91 ) / 8192 ;
if ( V_91 == 0 ) V_91 = 1 ;
V_93 -> V_107 = ( ( 7 - V_79 -> V_90 ) << 12 | V_91 ) & 0xfff ;
V_93 -> V_108 = F_18 ( V_79 -> V_82 ) ;
V_93 -> V_109 = V_93 -> V_106 ;
V_93 -> V_110 = 0x0042 ;
break;
case 0 :
V_97 = ( T_3 * ) ( V_9 -> V_111 + V_112 * V_9 -> V_113 ) ;
* ( V_97 + V_41 -> V_58 ) = V_114 | V_115 ;
V_94 = ( T_12 * ) ( V_9 -> V_111 + V_116 * V_9 -> V_113 ) ;
V_94 += V_41 -> V_58 ;
V_94 -> V_117 = ( 15 - V_79 -> V_87 ) & 0x000f ;
V_96 = V_79 -> V_22 << ( 15 - V_79 -> V_86 ) ;
if ( V_96 == 0 ) V_96 = 1 ;
V_94 -> V_118 = F_18 ( V_96 ) ;
V_9 -> V_57 [ V_41 -> V_58 ] -> V_59 = V_119 | V_120 ;
V_9 -> V_121 += V_79 -> V_82 ;
V_9 -> V_122 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_27 ( T_2 * V_9 , struct V_40 * V_41 ) {
T_8 V_123 = 0 , V_124 , V_125 ;
int V_126 ;
struct V_12 * V_12 ;
int V_127 = 0 , V_128 , V_129 , V_130 ;
T_8 V_131 ;
T_4 * V_132 , * V_133 ;
T_4 V_134 , V_135 ;
T_8 V_136 = 0 ;
T_8 V_137 = 0 ;
T_8 V_138 = 0 ;
if ( V_41 -> V_53 . V_54 . V_139 <= 0 ) {
F_17 (printk(L_9);)
return - 1 ;
}
V_125 = V_41 -> V_53 . V_54 . V_139 ;
V_126 = V_125 / V_9 -> V_140 ;
F_28 (printk(L_10,
entries, rate, dev->Granularity);)
if ( V_126 < 1 )
F_28 (printk(L_11);)
V_123 = V_126 * V_9 -> V_140 ;
V_124 = ( V_126 + 1 ) * V_9 -> V_140 ;
if ( 3 * ( V_125 - V_123 ) > ( V_124 - V_125 ) )
V_126 ++ ;
if ( V_126 > V_9 -> V_141 ) {
F_28 (printk(L_12);)
F_28 (printk(L_13,
entries, dev->CbrRemEntries);)
return - V_142 ;
}
V_12 = F_29 ( V_41 ) ;
V_12 -> V_143 = V_126 ;
V_9 -> V_121 += V_126 * V_9 -> V_140 ;
V_134 = 0 ;
V_131 = V_9 -> V_144 / V_126 ;
V_137 = V_9 -> V_144 % V_126 ;
V_129 = V_126 ;
V_136 = 0 ;
V_135 = V_41 -> V_58 ;
F_28 (printk(L_14,vcIndex,spacing,sp_mod);)
while ( V_129 )
{
if ( V_129 == V_126 )
{
V_127 = V_9 -> V_145 ;
V_9 -> V_145 += 2 ;
if ( V_9 -> V_145 >= V_9 -> V_144 )
V_9 -> V_145 -= V_9 -> V_144 ;
} else {
V_127 += ( T_8 ) ( V_131 + V_136 ) ;
V_136 = ( ( V_137 + V_138 ) / V_126 ) ;
V_138 = ( ( V_137 + V_138 ) % V_126 ) ;
}
if ( V_127 >= ( int ) V_9 -> V_144 )
V_127 -= V_9 -> V_144 ;
V_132 = ( T_4 * ) ( V_9 -> V_17 + V_146 * V_9 -> V_113 ) ;
V_130 = 0 ;
V_128 = V_127 ;
V_133 = ( T_4 * ) ( V_132 + V_128 ) ;
F_28 (printk(L_15,
testSlot, TstSchedTbl,toBeAssigned);)
memcpy ( ( V_98 ) & V_134 , ( V_98 ) V_133 , sizeof( V_134 ) ) ;
while ( V_134 )
{
V_130 ++ ;
V_128 = V_127 - V_130 ;
if ( V_128 < 0 ) {
V_128 += V_9 -> V_144 ;
F_28 (printk(L_16,
SchedTbl,testSlot);)
}
V_133 = ( T_4 * ) ( V_132 + V_128 ) ;
memcpy ( ( V_98 ) & V_134 , ( V_98 ) V_133 , sizeof( V_134 ) ) ;
if ( ! V_134 )
break;
V_128 = V_127 + V_130 ;
if ( V_128 >= ( int ) V_9 -> V_144 ) {
V_128 -= V_9 -> V_144 ;
F_28 (printk(L_17,dev->CbrTotEntries);)
F_28 (printk(L_18,
testSlot, toBeAssigned);)
}
V_133 = ( T_4 * ) ( V_132 + V_128 ) ;
F_28 (printk(L_19,
TstSchedTbl,cbrVC,inc);)
memcpy ( ( V_98 ) & V_134 , ( V_98 ) V_133 , sizeof( V_134 ) ) ;
}
memcpy ( ( V_98 ) V_133 , ( V_98 ) & V_135 , sizeof( * V_133 ) ) ;
V_9 -> V_141 -- ;
V_129 -- ;
}
V_9 -> V_147 ++ ;
if ( V_9 -> V_147 == 1 ) {
F_16 ( ( V_148 | V_149 | V_150 | ( 0x23 << 2 ) ) , V_9 -> V_14 + V_151 ) ;
F_28 (printk(L_20);)
}
return 0 ;
}
static void F_30 ( struct V_40 * V_41 ) {
T_2 * V_152 ;
T_4 * V_132 , V_153 = 0 ;
T_8 V_31 , V_154 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
V_152 -> V_147 -- ;
V_132 = ( T_4 * ) ( V_152 -> V_17 + V_146 * V_152 -> V_113 ) ;
if ( V_152 -> V_147 == 0 ) {
F_16 ( ( V_149 | V_150 | ( 0x23 << 2 ) ) , V_152 -> V_14 + V_151 ) ;
F_28 (printk(L_21);)
}
V_154 = 0 ;
for ( V_31 = 0 ; V_31 < V_152 -> V_144 ; V_31 ++ )
{
if ( * V_132 == V_41 -> V_58 ) {
V_152 -> V_141 ++ ;
* V_132 = V_153 ;
F_28 (NumFound++;)
}
V_132 ++ ;
}
F_28 (printk(L_22,NumFound);)
}
static int F_32 ( T_2 * V_152 ) {
int V_78 = 0 ;
F_6 ( V_152 ) ;
if ( V_152 -> V_16 >= V_152 -> V_27 . V_38 )
V_78 = ( V_152 -> V_16 - V_152 -> V_27 . V_38 ) / 2 ;
else
V_78 = ( V_152 -> V_27 . V_28 - V_152 -> V_27 . V_38 + 2 + V_152 -> V_16 -
V_152 -> V_27 . V_29 ) / 2 ;
return V_78 ;
}
static int F_33 ( T_2 * V_152 ) {
struct V_32 * V_33 ;
int V_155 ;
struct V_40 * V_41 ;
V_155 = F_32 ( V_152 ) ;
while ( V_155 && ( V_33 = F_34 ( & V_152 -> V_156 ) ) ) {
if ( ! ( V_41 = F_35 ( V_33 ) -> V_41 ) ) {
F_36 ( V_33 ) ;
F_9 ( L_23 ) ;
break;
}
if ( ! F_37 ( V_157 , & V_41 -> V_158 ) ) {
F_36 ( V_33 ) ;
F_9 ( L_24 , V_41 -> V_58 ) ;
break;
}
if ( F_38 ( V_41 , V_33 ) ) {
F_39 ( & V_152 -> V_156 , V_33 ) ;
}
V_155 -- ;
}
return 0 ;
}
static void F_40 ( T_2 * V_152 ) {
struct V_40 * V_41 = NULL ;
struct V_32 * V_33 = NULL , * V_159 = NULL ;
struct V_12 * V_20 ;
T_1 * V_160 ;
F_6 ( V_152 ) ;
while ( ( V_160 = F_5 ( & V_152 -> V_26 ) ) ) {
V_33 = V_160 -> V_4 . V_24 ;
if ( ! V_33 ) {
F_9 ( L_25 ) ;
goto V_161;
}
V_41 = F_35 ( V_33 ) -> V_41 ;
if ( ! V_41 ) {
F_9 ( L_26 ) ;
F_36 ( V_33 ) ;
goto V_161;
}
V_20 = F_29 ( V_41 ) ;
if ( ! V_20 ) {
F_9 ( L_27 ) ;
F_36 ( V_33 ) ;
goto V_161;
}
V_159 = F_34 ( & V_20 -> V_162 ) ;
while ( V_159 && ( V_159 != V_33 ) ) {
if ( ! ( F_11 ( V_159 ) & V_25 ) ) {
F_9 ( L_28 , V_41 -> V_58 ) ;
}
F_17 (printk(L_29);)
if ( ( V_41 -> V_163 ) && ( V_159 -> V_164 != 0 ) )
{
V_41 -> V_163 ( V_41 , V_159 ) ;
F_10 (printk(L_30,
(long)skb1);)
}
else
F_36 ( V_159 ) ;
V_159 = F_34 ( & V_20 -> V_162 ) ;
}
if ( ! V_159 ) {
F_10 (printk(L_31,vcc->vci);)
F_2 ( & V_152 -> V_26 , V_160 ) ;
break;
}
if ( ( V_41 -> V_163 ) && ( V_33 -> V_164 != 0 ) )
{
V_41 -> V_163 ( V_41 , V_33 ) ;
F_10 (printk(L_32,(long)skb);)
}
else
F_36 ( V_33 ) ;
F_41 ( V_160 ) ;
}
F_33 ( V_152 ) ;
V_161:
return;
}
static T_4 F_42 ( T_2 * V_152 , T_8 V_165 )
{
T_3 V_166 ;
T_8 V_167 ;
int V_31 ;
F_43 ( V_168 + V_165 ) ;
V_166 = 0 ;
for ( V_31 = 15 ; V_31 >= 0 ; V_31 -- ) {
F_44 ( V_167 ) ;
V_166 |= ( V_167 << V_31 ) ;
}
V_169 ;
F_45 ( ~ V_170 ) ;
return V_166 ;
}
static void F_46 ( T_2 * V_152 ) {
T_3 V_171 = F_42 ( V_152 , 25 ) ;
V_152 -> V_171 = V_171 ;
if ( ( V_171 & V_172 ) == V_173 ) {
V_152 -> V_39 = V_174 ;
V_152 -> V_175 = V_176 ;
V_152 -> V_177 = V_178 ;
V_152 -> V_179 = V_180 ;
} else if ( ( V_171 & V_172 ) == V_181 ) {
if ( V_174 == V_182 )
V_152 -> V_39 = V_174 / 2 ;
else
V_152 -> V_39 = V_174 ;
V_152 -> V_175 = V_176 ;
if ( V_178 == V_183 )
V_152 -> V_177 = V_178 / 2 ;
else
V_152 -> V_177 = V_178 ;
V_152 -> V_179 = V_180 ;
}
else {
if ( V_174 == V_182 )
V_152 -> V_39 = V_174 / 8 ;
else
V_152 -> V_39 = V_174 ;
V_152 -> V_175 = V_176 ;
if ( V_178 == V_183 )
V_152 -> V_177 = V_178 / 8 ;
else
V_152 -> V_177 = V_178 ;
V_152 -> V_179 = V_180 ;
}
V_152 -> V_184 = V_185 + ( V_152 -> V_39 * V_152 -> V_175 ) ;
F_47 (printk(L_33,
iadev->num_tx_desc, iadev->tx_buf_sz, iadev->num_rx_desc,
iadev->rx_buf_sz, iadev->rx_pkt_ram);)
#if 0
if ((memType & FE_MASK) == FE_SINGLE_MODE) {
iadev->phy_type = PHY_OC3C_S;
else if ((memType & FE_MASK) == FE_UTP_OPTION)
iadev->phy_type = PHY_UTP155;
else
iadev->phy_type = PHY_OC3C_M;
#endif
V_152 -> V_186 = V_171 & V_187 ;
F_47 (printk(L_34,
memType,iadev->phy_type);)
if ( V_152 -> V_186 == V_188 )
V_152 -> V_81 = ( T_8 ) ( ( ( 25600000 / 8 ) * 26 ) / ( 27 * 53 ) ) ;
else if ( V_152 -> V_186 == V_189 )
V_152 -> V_81 = ( T_8 ) ( ( ( 44736000 / 8 ) * 26 ) / ( 27 * 53 ) ) ;
else if ( V_152 -> V_186 == V_190 )
V_152 -> V_81 = ( T_8 ) ( ( ( 34368000 / 8 ) * 26 ) / ( 27 * 53 ) ) ;
else
V_152 -> V_81 = ( T_8 ) ( V_191 ) ;
F_47 (printk(L_35, iadev->LineRate);)
}
static void F_48 ( T_2 * V_152 ) {
volatile T_13 * V_192 ;
volatile T_14 * V_193 ;
volatile T_15 * V_194 ;
if( V_152 -> V_186 & V_188 ) {
V_193 = ( T_14 * ) V_152 -> V_195 ;
V_152 -> V_196 = Boolean ( V_193 -> V_197 & V_198 ) ;
} else if ( V_152 -> V_186 & V_189 ) {
V_194 = ( T_15 * ) V_152 -> V_195 ;
( void ) V_194 -> V_199 ;
V_152 -> V_196 =
Boolean ( ! ( V_194 -> V_200 & V_201 ) ) ;
} else if ( V_152 -> V_186 & V_190 ) {
V_194 = ( T_15 * ) V_152 -> V_195 ;
( void ) V_194 -> V_202 ;
V_152 -> V_196 =
Boolean ( ! ( V_194 -> V_203 & V_204 ) ) ;
}
else {
V_192 = ( T_13 * ) V_152 -> V_195 ;
( void ) V_192 -> V_205 ;
V_152 -> V_196 = Boolean ( ! ( V_192 -> V_205 & V_206 ) ) ;
}
if ( V_152 -> V_196 )
F_9 ( L_36 ) ;
else
F_9 ( L_37 ) ;
return;
}
static void F_49 ( T_2 * V_152 )
{
volatile T_14 * V_193 = ( T_14 * ) V_152 -> V_195 ;
#if 0
mb25->mb25_master_ctrl = MB25_MC_DRIC | MB25_MC_DREC | MB25_MC_ENABLED;
#endif
V_193 -> V_207 = V_208 | V_209 ;
V_193 -> V_210 = 0 ;
V_152 -> V_196 = Boolean ( V_193 -> V_197 & V_198 ) ;
return;
}
static void F_50 ( T_2 * V_152 )
{
volatile T_15 * V_194 = ( T_15 * ) V_152 -> V_195 ;
if ( V_152 -> V_186 & V_189 )
{
V_152 -> V_196 =
Boolean ( ! ( V_194 -> V_200 & V_201 ) ) ;
V_194 -> V_211 = 0x17 ;
V_194 -> V_212 = 1 ;
V_194 -> V_213 = 1 ;
V_194 -> V_214 = 0 ;
V_194 -> V_215 = 0 ;
V_194 -> V_216 = 0 ;
}
else
{
V_152 -> V_196 =
Boolean ( ! ( V_194 -> V_203 & V_204 ) ) ;
V_194 -> V_217 = 0x4 ;
V_194 -> V_218 = 0x20 ;
V_194 -> V_219 = 0x1d ;
V_194 -> V_220 = 0x30 ;
V_194 -> V_221 = 0x0 ;
V_194 -> V_222 = 0x1 ;
V_194 -> V_214 = V_223 ;
V_194 -> V_215 = 0x41 ;
V_194 -> V_216 = 0x41 ;
}
V_194 -> V_224 = 0x28 ;
V_194 -> V_225 = 0 ;
V_194 -> V_226 = 0 ;
V_194 -> V_227 = 0x2c ;
V_194 -> V_228 = 0x81 ;
V_194 -> V_229 =
V_194 -> V_230 =
V_194 -> V_231 = 0 ;
V_194 -> V_232 = 1 ;
V_194 -> V_233 = 0xff ;
V_194 -> V_234 = 0xff ;
V_194 -> V_235 = 0xff ;
V_194 -> V_236 = 0xfe ;
V_194 -> V_237 =
V_194 -> V_238 =
V_194 -> V_239 = 0 ;
V_194 -> V_240 = 1 ;
V_194 -> V_241 =
V_194 -> V_242 =
V_194 -> V_243 =
V_194 -> V_244 = 0xff ;
V_194 -> V_245 = 0xa4 ;
V_194 -> V_246 = 0x10 ;
V_194 -> V_247 = 0x55 ;
V_194 -> V_214 &= ~ ( V_248 |
V_249 |
V_250 |
V_251 ) ;
#ifdef F_51
V_194 -> V_252 |= V_253 ;
#endif
return;
}
static void F_52 ( T_5 * V_254 , int V_255 , char * V_256 )
{
int V_257 , V_258 ;
T_5 V_259 [ 120 ] ;
T_5 * V_260 = V_259 ;
V_258 = 0 ;
while( V_258 < V_255 ) {
V_260 += sprintf ( V_260 , L_38 , V_256 ) ;
for( V_257 = 0 ; V_258 + V_257 < V_255 && V_257 < 16 ; V_257 ++ ) {
if ( V_257 != 0 && ( V_257 % 4 ) == 0 )
V_260 += sprintf ( V_260 , L_39 ) ;
V_260 += sprintf ( V_260 , L_40 , V_254 [ V_258 + V_257 ] ) ;
}
while( V_257 ++ < 16 ) {
if ( ( V_257 % 4 ) == 0 )
sprintf ( V_260 , L_39 ) ;
V_260 += sprintf ( V_260 , L_41 ) ;
}
V_260 += sprintf ( V_260 , L_42 ) ;
for( V_257 = 0 ; V_258 + V_257 < V_255 && V_257 < 16 ; V_257 ++ ) {
if ( isprint ( ( int ) V_254 [ V_258 + V_257 ] ) )
V_260 += sprintf ( V_260 , L_43 , V_254 [ V_258 + V_257 ] ) ;
else
V_260 += sprintf ( V_260 , L_44 ) ;
}
F_9 ( L_45 , V_259 ) ;
V_258 += V_257 ;
V_260 = V_259 ;
}
}
static void F_53 ( T_2 * V_152 ) {
T_3 V_261 , V_262 , V_263 ;
T_8 V_31 ;
void T_16 * V_78 ;
V_261 = F_54 ( V_152 -> V_14 + V_15 ) ;
F_9 ( L_46 ,
V_261 , F_54 ( V_152 -> V_17 + V_261 ) ,
F_54 ( V_152 -> V_17 + V_261 - 2 ) ) ;
F_9 ( L_47 , V_152 -> V_16 ,
V_152 -> V_27 . V_38 ) ;
V_262 = F_54 ( V_152 -> V_14 + V_264 ) ;
V_263 = F_54 ( V_152 -> V_14 + V_265 ) ;
F_9 ( L_48 , V_262 , V_263 ) ;
V_31 = 0 ;
while ( V_262 != V_263 ) {
V_78 = V_152 -> V_17 + V_262 ;
F_9 ( L_49 , V_31 ++ , F_54 ( V_78 ) , V_78 ) ;
V_262 += 2 ;
}
for( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ )
F_9 ( L_50 , V_31 , V_152 -> V_18 [ V_31 ] . V_19 ) ;
}
static void F_55 ( struct V_266 * V_9 )
{
#if 0
IADEV *iadev;
u_short state;
u_short excpq_rd_ptr;
int vci, error = 1;
iadev = INPH_IA_DEV(dev);
state = readl(iadev->reass_reg + STATE_REG) & 0xffff;
while((state & EXCPQ_EMPTY) != EXCPQ_EMPTY)
{ printk("state = %x \n", state);
excpq_rd_ptr = readw(iadev->reass_reg + EXCP_Q_RD_PTR) & 0xffff;
printk("state = %x excpq_rd_ptr = %x \n", state, excpq_rd_ptr);
if (excpq_rd_ptr == *(u16*)(iadev->reass_reg + EXCP_Q_WR_PTR))
IF_ERR(printk("excpq_rd_ptr is wrong!!!\n");)
vci = readw(iadev->reass_ram+excpq_rd_ptr);
error = readw(iadev->reass_ram+excpq_rd_ptr+2) & 0x0007;
excpq_rd_ptr += 4;
if (excpq_rd_ptr > (readw(iadev->reass_reg + EXCP_Q_ED_ADR)& 0xffff))
excpq_rd_ptr = readw(iadev->reass_reg + EXCP_Q_ST_ADR)& 0xffff;
writew( excpq_rd_ptr, iadev->reass_reg + EXCP_Q_RD_PTR);
state = readl(iadev->reass_reg + STATE_REG) & 0xffff;
}
#endif
}
static void F_56 ( struct V_266 * V_9 , int V_267 )
{
T_2 * V_152 ;
V_152 = F_31 ( V_9 ) ;
F_16 ( V_267 , V_152 -> V_111 + V_152 -> V_268 . V_269 ) ;
V_152 -> V_268 . V_269 += 2 ;
if ( V_152 -> V_268 . V_269 > V_152 -> V_268 . V_270 )
V_152 -> V_268 . V_269 = V_152 -> V_268 . V_271 ;
F_16 ( V_152 -> V_268 . V_269 , V_152 -> V_272 + V_273 ) ;
}
static int F_57 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
struct V_40 * V_41 ;
unsigned short V_62 ;
struct V_274 T_16 * V_275 ;
int V_267 ;
struct V_276 * V_277 ;
int V_164 ;
struct V_32 * V_33 ;
T_7 V_278 , V_279 ;
V_152 = F_31 ( V_9 ) ;
if ( V_152 -> V_268 . V_280 == ( F_54 ( V_152 -> V_272 + V_281 ) & 0xffff ) )
{
F_9 (KERN_ERR DEV_LABEL L_51 , dev->number) ;
return - V_282 ;
}
V_267 = F_54 ( V_152 -> V_111 + V_152 -> V_268 . V_280 ) & 0x1fff ;
F_58 (printk(L_52,
iadev->reass_ram, iadev->rfL.pcq_rd, desc);
printk(L_53,
readw(iadev->reass_reg+PCQ_WR_PTR)&0xffff);)
if ( V_152 -> V_268 . V_280 == V_152 -> V_268 . V_283 )
V_152 -> V_268 . V_280 = V_152 -> V_268 . V_284 ;
else
V_152 -> V_268 . V_280 += 2 ;
F_16 ( V_152 -> V_268 . V_280 , V_152 -> V_272 + V_285 ) ;
V_275 = V_152 -> V_286 ;
V_275 += V_267 ;
if ( ! V_267 || ( V_267 > V_152 -> V_177 ) ||
( ( V_275 -> V_287 & 0xffff ) > V_152 -> V_70 ) ) {
F_56 ( V_9 , V_267 ) ;
F_17 (printk(L_54, desc);)
return - 1 ;
}
V_41 = V_152 -> V_288 [ V_275 -> V_287 & 0xffff ] ;
if ( ! V_41 )
{
F_56 ( V_9 , V_267 ) ;
F_9 ( L_55 ) ;
return - 1 ;
}
V_62 = ( T_3 ) ( V_275 -> V_289 ) ;
if ( V_62 & ( V_290 | V_291 | V_292 ) )
{
F_59 ( & V_41 -> V_293 -> V_294 ) ;
F_17 (printk(L_56);)
if ( V_62 & V_290 ) {
F_17 (printk(L_57);)
}
else if ( V_62 & V_291 ) {
F_17 (printk(L_58);)
}
else {
F_17 (printk(L_59);)
}
goto V_295;
}
V_278 = ( V_275 -> V_296 << 16 ) | V_275 -> V_297 ;
V_279 = ( V_275 -> V_298 << 16 ) | V_275 -> V_299 ;
V_164 = V_279 - V_278 ;
if ( V_164 > V_152 -> V_179 ) {
F_9 ( L_60 , V_152 -> V_179 ) ;
F_59 ( & V_41 -> V_293 -> V_294 ) ;
goto V_295;
}
if ( ! ( V_33 = F_60 ( V_41 , V_164 , V_7 ) ) ) {
if ( V_41 -> V_58 < 32 )
F_9 ( L_61 ) ;
goto V_295;
}
F_61 ( V_33 , V_164 ) ;
F_35 ( V_33 ) -> V_41 = V_41 ;
F_62 ( V_33 ) = V_267 ;
F_63 ( & V_152 -> V_300 , V_33 ) ;
V_277 = V_152 -> V_301 . V_302 ;
V_277 -> V_303 = F_64 ( V_152 -> V_304 , V_33 -> V_4 ,
V_164 , V_305 ) ;
V_277 -> V_306 = V_278 ;
V_277 -> V_307 = V_164 ;
V_277 -> V_308 = V_309 ;
if( ++ V_277 == V_152 -> V_301 . V_310 )
V_277 = V_152 -> V_301 . V_311 ;
V_152 -> V_301 . V_302 = V_277 ;
F_15 ( 1 ) ;
F_65 ( 1 , V_152 -> V_312 + V_313 ) ;
V_161: return 0 ;
V_295:
F_56 ( V_9 , V_267 ) ;
goto V_161;
}
static void F_66 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
T_3 V_62 ;
T_3 V_314 , V_31 ;
V_152 = F_31 ( V_9 ) ;
V_62 = F_7 ( V_152 -> V_272 + V_315 ) & 0xffff ;
F_10 (printk(L_62, status);)
if ( V_62 & V_316 )
{
V_314 = F_7 ( V_152 -> V_272 + V_317 ) & 0xffff ;
F_10 (printk(L_63, status);)
while( ! ( V_314 & V_318 ) )
{
F_57 ( V_9 ) ;
V_314 = F_7 ( V_152 -> V_272 + V_317 ) & 0xffff ;
}
V_152 -> V_319 = 1 ;
}
if ( V_62 & V_320 )
{
if ( V_152 -> V_319 ) {
V_152 -> V_321 = V_152 -> V_322 ;
V_152 -> V_323 = V_37 ;
V_152 -> V_319 = 0 ;
}
else if ( ( F_13 ( V_37 , V_152 -> V_323 + 50 ) ) &&
( ( V_152 -> V_322 - V_152 -> V_321 ) == 0 ) ) {
for ( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
F_56 ( V_9 , V_31 ) ;
F_9 ( L_64 ) ;
F_16 ( ~ ( V_320 | V_324 ) , V_152 -> V_272 + V_325 ) ;
V_152 -> V_319 = 1 ;
}
F_10 (printk(L_65, status);)
}
if ( V_62 & V_324 )
{
F_10 (printk(L_66, status);)
F_55 ( V_9 ) ;
}
if ( V_62 & V_326 )
{
F_10 (printk(L_67, status);)
}
}
static void F_67 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
struct V_40 * V_41 ;
struct V_32 * V_33 ;
int V_267 ;
T_3 V_314 ;
struct V_276 * V_276 , * V_327 ;
T_7 V_328 ;
int V_164 ;
V_152 = F_31 ( V_9 ) ;
V_276 = V_152 -> V_301 . V_329 ;
V_328 = F_7 ( V_152 -> V_312 + V_330 ) & ( sizeof( struct V_276 ) * V_331 - 1 ) ;
V_327 = (struct V_276 * ) ( V_152 -> V_301 . V_311 + ( V_328 >> 4 ) ) ;
while( V_276 != V_327 )
{
V_33 = F_34 ( & V_152 -> V_300 ) ;
if ( ! V_33 )
goto V_332;
V_267 = F_62 ( V_33 ) ;
F_56 ( V_9 , V_267 ) ;
if ( ! ( V_164 = V_33 -> V_164 ) )
{
F_9 ( L_68 ) ;
F_36 ( V_33 ) ;
}
else
{
struct V_333 * V_334 ;
T_3 V_255 ;
struct V_12 * V_12 ;
F_68 ( V_152 -> V_304 , V_152 -> V_301 . V_302 -> V_303 ,
V_164 , V_305 ) ;
V_41 = F_35 ( V_33 ) -> V_41 ;
if ( ! V_41 ) {
F_9 ( L_69 ) ;
F_36 ( V_33 ) ;
goto V_332;
}
V_12 = F_29 ( V_41 ) ;
if ( V_12 == NULL )
{
F_59 ( & V_41 -> V_293 -> V_294 ) ;
F_36 ( V_33 ) ;
F_69 ( V_41 , F_70 ( V_164 ) ) ;
goto V_332;
}
V_334 = (struct V_333 * ) ( ( T_5 * ) V_33 -> V_4 +
V_33 -> V_164 - sizeof( * V_334 ) ) ;
V_255 = F_71 ( V_334 -> V_255 ) ;
if ( ( V_255 > V_152 -> V_179 ) || ( V_255 >
( V_33 -> V_164 - sizeof( struct V_333 ) ) ) )
{
F_59 ( & V_41 -> V_293 -> V_294 ) ;
F_17 (printk(L_70,
length, skb->len);)
F_36 ( V_33 ) ;
F_69 ( V_41 , F_70 ( V_164 ) ) ;
goto V_332;
}
F_72 ( V_33 , V_255 ) ;
F_73 (printk(L_71, skb->len);
xdump(skb->data, skb->len, L_72);
printk(L_73);)
F_58 (printk(L_74);)
V_41 -> V_335 ( V_41 , V_33 ) ;
F_59 ( & V_41 -> V_293 -> V_336 ) ;
V_152 -> V_322 ++ ;
}
V_332:
if ( ++ V_276 == V_152 -> V_301 . V_310 )
V_276 = V_152 -> V_301 . V_311 ;
}
V_152 -> V_301 . V_329 = V_276 ;
if ( ! V_152 -> V_319 ) {
V_314 = F_7 ( V_152 -> V_272 + V_317 ) & 0xffff ;
if ( ! ( V_314 & V_337 ) ) {
V_314 = F_7 ( V_152 -> V_272 + V_325 ) & 0xffff ;
F_65 ( V_314 & ~ ( V_320 | V_316 ) ,
V_152 -> V_272 + V_325 ) ;
V_152 -> V_319 ++ ;
}
}
}
static int F_74 ( struct V_40 * V_41 )
{
T_2 * V_152 ;
T_3 T_16 * V_338 ;
T_3 T_16 * V_339 ;
F_10 (printk(L_75, vcc->vpi, vcc->vci);)
if ( V_41 -> V_53 . V_340 . V_55 == V_341 ) return 0 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
if ( V_41 -> V_53 . V_340 . V_55 == V_56 ) {
if ( V_152 -> V_186 & V_188 ) {
F_9 ( L_76 ) ;
return - V_282 ;
}
}
V_338 = V_152 -> V_111 + V_342 * V_152 -> V_113 ;
V_338 += V_41 -> V_58 ;
* V_338 = V_41 -> V_58 << 6 ;
if ( ( V_41 -> V_53 . V_340 . V_55 == V_56 ) ||
( V_41 -> V_53 . V_54 . V_55 == V_56 ) )
{
T_9 V_79 ;
F_24 ( V_152 , & V_79 ) ;
F_25 ( V_152 , & V_79 , V_41 , 0 ) ;
}
else {
V_339 = V_152 -> V_111 + V_112 * V_152 -> V_113 ;
V_339 += V_41 -> V_58 ;
* V_339 = V_114 ;
}
if ( V_152 -> V_288 [ V_41 -> V_58 ] )
F_9 (KERN_CRIT DEV_LABEL L_77 ,
vcc->dev->number, vcc->vci) ;
V_152 -> V_288 [ V_41 -> V_58 ] = V_41 ;
return 0 ;
}
static int F_75 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
struct V_274 T_16 * V_275 ;
unsigned long V_343 = 0 ;
void * V_344 ;
struct V_345 * V_345 ;
T_4 * V_338 ;
T_4 * V_346 ;
int V_31 , V_347 , V_348 ;
T_3 V_349 ;
T_3 * V_350 ;
V_152 = F_31 ( V_9 ) ;
V_344 = F_76 ( V_152 -> V_304 , V_351 ,
& V_152 -> V_352 ) ;
if ( ! V_344 ) {
F_9 (KERN_ERR DEV_LABEL L_78 ) ;
goto V_353;
}
V_152 -> V_301 . V_311 = (struct V_276 * ) V_344 ;
V_152 -> V_301 . V_329 = V_152 -> V_301 . V_311 ;
V_152 -> V_301 . V_302 = V_152 -> V_301 . V_311 ;
V_152 -> V_301 . V_310 = (struct V_276 * ) ( ( unsigned long ) V_344 + sizeof( struct V_276 ) * V_331 ) ;
F_65 ( V_152 -> V_352 & 0xfffff000 ,
V_152 -> V_312 + V_330 ) ;
F_47 (printk(L_79,
iadev->dma+IPHASE5575_TX_LIST_ADDR,
*(u32*)(iadev->dma+IPHASE5575_TX_LIST_ADDR));
printk(L_80,
iadev->dma+IPHASE5575_RX_LIST_ADDR,
*(u32*)(iadev->dma+IPHASE5575_RX_LIST_ADDR));)
F_16 ( 0xffff , V_152 -> V_272 + V_325 ) ;
F_16 ( 0 , V_152 -> V_272 + V_354 ) ;
F_16 ( V_355 , V_152 -> V_272 + V_356 ) ;
F_16 ( V_357 >> 16 , V_152 -> V_272 + V_358 ) ;
F_16 ( V_152 -> V_179 , V_152 -> V_272 + V_359 ) ;
V_152 -> V_286 = V_152 -> V_111 + V_357 * V_152 -> V_113 ;
V_275 = V_152 -> V_286 ;
F_77 ( V_275 , 0 , sizeof( * V_275 ) ) ;
V_275 ++ ;
V_343 = V_152 -> V_184 ;
for( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
{
F_77 ( V_275 , 0 , sizeof( * V_275 ) ) ;
V_275 -> V_296 = V_343 >> 16 ;
V_275 -> V_297 = V_343 & 0x0000ffff ;
V_275 ++ ;
V_343 += V_152 -> V_179 ;
}
F_47 (printk(L_81, buf_desc_ptr);)
V_31 = V_360 * V_152 -> V_113 ;
F_16 ( V_31 >> 16 , V_152 -> V_272 + V_361 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_362 ) ;
F_16 ( V_31 + V_152 -> V_177 * sizeof( T_3 ) ,
V_152 -> V_272 + V_363 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_364 ) ;
F_16 ( V_31 + V_152 -> V_177 * sizeof( T_3 ) ,
V_152 -> V_272 + V_273 ) ;
V_349 = F_54 ( V_152 -> V_272 + V_362 ) ;
V_350 = ( T_3 * ) ( V_152 -> V_111 + V_349 ) ;
for( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
{
* V_350 = ( T_3 ) V_31 ;
V_350 ++ ;
}
F_47 (printk(L_82, freeq_start);)
V_31 = ( V_365 * V_152 -> V_113 ) & 0xffff ;
F_16 ( V_31 , V_152 -> V_272 + V_366 ) ;
F_16 ( V_31 + V_152 -> V_70 * sizeof( T_3 ) , V_152 -> V_272 + V_367 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_285 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_281 ) ;
V_31 = ( V_368 * V_152 -> V_113 ) & 0xffff ;
F_16 ( V_31 , V_152 -> V_272 + V_369 ) ;
F_16 ( V_31 + V_370 * sizeof( V_371 ) ,
V_152 -> V_272 + V_372 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_373 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_374 ) ;
V_152 -> V_268 . V_271 = F_54 ( V_152 -> V_272 + V_362 ) & 0xffff ;
V_152 -> V_268 . V_270 = F_54 ( V_152 -> V_272 + V_363 ) & 0xffff ;
V_152 -> V_268 . V_375 = F_54 ( V_152 -> V_272 + V_364 ) & 0xffff ;
V_152 -> V_268 . V_269 = F_54 ( V_152 -> V_272 + V_273 ) & 0xffff ;
V_152 -> V_268 . V_284 = F_54 ( V_152 -> V_272 + V_366 ) & 0xffff ;
V_152 -> V_268 . V_283 = F_54 ( V_152 -> V_272 + V_367 ) & 0xffff ;
V_152 -> V_268 . V_280 = F_54 ( V_152 -> V_272 + V_285 ) & 0xffff ;
V_152 -> V_268 . V_376 = F_54 ( V_152 -> V_272 + V_281 ) & 0xffff ;
F_47 (printk(L_83,
iadev->rfL.pcq_st, iadev->rfL.pcq_ed, iadev->rfL.pcq_rd,
iadev->rfL.pcq_wr);)
V_31 = V_112 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 3 ) , V_152 -> V_272 + V_377 ) ;
V_346 = ( T_4 * ) ( V_152 -> V_111 + V_31 ) ;
V_347 = V_378 * V_152 -> V_113 ;
for( V_31 = 0 ; V_31 < V_347 ; V_31 ++ )
* V_346 ++ = V_114 ;
V_31 = 8 * 1024 ;
V_348 = 0 ;
while ( V_31 != V_152 -> V_70 ) {
V_31 /= 2 ;
V_348 ++ ;
}
V_31 = V_342 * V_152 -> V_113 ;
F_16 ( ( ( V_31 >> 3 ) & 0xfff8 ) | V_348 , V_152 -> V_272 + V_379 ) ;
V_338 = ( T_4 * ) ( V_152 -> V_111 + V_342 * V_152 -> V_113 ) ;
V_347 = V_380 * V_152 -> V_113 ;
for( V_31 = 0 ; V_31 < V_347 ; V_31 ++ )
{
* V_338 = ( V_31 << 6 ) | 15 ;
V_338 ++ ;
}
V_31 = V_116 * V_152 -> V_113 ;
F_16 ( V_31 >> 3 , V_152 -> V_272 + V_381 ) ;
V_31 = V_116 * V_152 -> V_113 ;
V_345 = (struct V_345 * ) ( V_152 -> V_111 + V_31 ) ;
V_347 = V_378 * V_152 -> V_113 ;
memset ( ( char * ) V_345 , 0 , V_347 * sizeof( * V_345 ) ) ;
for( V_31 = 0 ; V_31 < V_347 ; V_31 ++ ) {
V_345 -> V_87 = 0x0003 ;
V_345 -> V_96 = 0x5eb1 ;
V_345 ++ ;
}
F_16 ( 0xff00 , V_152 -> V_272 + V_382 ) ;
F_16 ( 0 , V_152 -> V_272 + V_383 ) ;
F_16 ( 0x1 , V_152 -> V_272 + V_384 ) ;
F_16 ( 0xF6F8 , V_152 -> V_272 + V_385 ) ;
V_31 = ( V_347 >> 6 ) & 0xFF ;
V_347 += 2 * ( V_347 - 1 ) ;
V_31 |= ( ( V_347 << 2 ) & 0xFF00 ) ;
F_16 ( V_31 , V_152 -> V_272 + V_386 ) ;
for( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ )
V_152 -> V_18 [ V_31 ] . V_19 = 0 ;
F_54 ( V_152 -> V_272 + V_315 ) ;
F_16 ( ~ ( V_320 | V_316 ) , V_152 -> V_272 + V_325 ) ;
F_78 ( & V_152 -> V_300 ) ;
V_152 -> V_387 = NULL ;
V_152 -> V_288 = F_79 ( 4 * V_152 -> V_70 , V_388 ) ;
if ( ! V_152 -> V_288 ) {
F_9 (KERN_ERR DEV_LABEL L_84 ,
dev->number) ;
goto V_389;
}
V_152 -> V_319 = 1 ;
V_152 -> V_322 = 0 ;
F_16 ( V_390 , V_152 -> V_272 + V_354 ) ;
return 0 ;
V_389:
F_80 ( V_152 -> V_304 , V_351 , V_152 -> V_301 . V_311 ,
V_152 -> V_352 ) ;
V_353:
return - V_391 ;
}
static void F_81 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
unsigned short V_62 ;
unsigned long V_158 ;
V_152 = F_31 ( V_9 ) ;
V_62 = F_7 ( V_152 -> V_14 + V_75 ) ;
if ( V_62 & V_72 ) {
F_10 (printk(L_85);)
F_82 ( & V_152 -> V_392 , V_158 ) ;
F_40 ( V_152 ) ;
F_83 ( & V_152 -> V_392 , V_158 ) ;
F_16 ( V_72 , V_152 -> V_14 + V_75 ) ;
if ( V_152 -> V_393 )
F_84 ( & V_152 -> V_394 ) ;
}
if ( V_62 & V_73 )
{
F_10 (printk(L_86);)
}
}
static void F_85 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
struct V_276 * V_276 , * V_327 ;
struct V_32 * V_33 ;
struct V_40 * V_41 ;
struct V_12 * V_20 ;
T_7 V_328 ;
unsigned long V_158 ;
V_152 = F_31 ( V_9 ) ;
F_82 ( & V_152 -> V_392 , V_158 ) ;
V_276 = V_152 -> V_395 . V_329 ;
V_328 = F_7 ( V_152 -> V_312 + V_396 ) &
( sizeof( struct V_276 ) * V_331 - 1 ) ;
V_327 = (struct V_276 * ) ( V_152 -> V_395 . V_311 + ( V_328 >> 4 ) ) ;
while ( V_276 != V_327 )
{
V_33 = F_34 ( & V_152 -> V_397 ) ;
if ( ! V_33 ) break;
if ( ! ( ( V_276 - V_152 -> V_395 . V_311 ) % ( 2 * sizeof( struct V_276 ) ) ) ) {
F_68 ( V_152 -> V_304 , V_276 -> V_303 , V_33 -> V_164 ,
V_398 ) ;
}
V_41 = F_35 ( V_33 ) -> V_41 ;
if ( ! V_41 ) {
F_9 ( L_87 ) ;
F_83 ( & V_152 -> V_392 , V_158 ) ;
F_36 ( V_33 ) ;
return;
}
V_20 = F_29 ( V_41 ) ;
if ( ! V_20 ) {
F_9 ( L_88 ) ;
F_83 ( & V_152 -> V_392 , V_158 ) ;
F_36 ( V_33 ) ;
return;
}
if ( V_41 -> V_53 . V_54 . V_22 >= V_152 -> V_23 ) {
if ( ( V_41 -> V_163 ) && ( V_33 -> V_164 != 0 ) )
{
V_41 -> V_163 ( V_41 , V_33 ) ;
}
else {
F_36 ( V_33 ) ;
}
}
else {
F_11 ( V_33 ) |= V_399 ;
F_63 ( & V_20 -> V_162 , V_33 ) ;
}
F_10 (printk(L_89, skb);)
if ( ++ V_276 == V_152 -> V_395 . V_310 )
V_276 = V_152 -> V_395 . V_311 ;
}
V_152 -> V_395 . V_329 = V_276 ;
F_83 ( & V_152 -> V_392 , V_158 ) ;
}
static int F_86 ( struct V_40 * V_41 )
{
struct V_12 * V_12 ;
T_2 * V_152 ;
struct V_47 * V_400 ;
struct V_50 * V_401 ;
int V_402 ;
F_10 (printk(L_90, vcc->vci);)
if ( V_41 -> V_53 . V_54 . V_55 == V_341 ) return 0 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
if ( V_152 -> V_186 & V_188 ) {
if ( V_41 -> V_53 . V_54 . V_55 == V_56 ) {
F_9 ( L_76 ) ;
return - V_282 ;
}
if ( V_41 -> V_53 . V_54 . V_55 == V_403 ) {
F_9 ( L_91 ) ;
return - V_282 ;
}
}
V_12 = F_29 ( V_41 ) ;
memset ( ( V_98 ) V_12 , 0 , sizeof( * V_12 ) ) ;
if ( V_41 -> V_53 . V_54 . V_404 >
( V_152 -> V_175 - sizeof( struct V_333 ) ) ) {
F_9 ( L_92 ,
V_41 -> V_53 . V_54 . V_404 , V_152 -> V_175 ) ;
V_41 -> V_405 = NULL ;
F_41 ( V_12 ) ;
return - V_282 ;
}
V_12 -> V_21 = 0 ;
V_12 -> V_406 = 1 ;
if ( V_41 -> V_53 . V_54 . V_139 == V_407 )
V_41 -> V_53 . V_54 . V_22 = V_152 -> V_81 ;
else if ( ( V_41 -> V_53 . V_54 . V_139 == 0 ) && ( V_41 -> V_53 . V_54 . V_22 <= 0 ) )
V_41 -> V_53 . V_54 . V_22 = V_152 -> V_81 ;
else if ( ( V_41 -> V_53 . V_54 . V_139 > V_41 -> V_53 . V_54 . V_22 ) && ( V_41 -> V_53 . V_54 . V_139 > 0 ) )
V_41 -> V_53 . V_54 . V_22 = V_41 -> V_53 . V_54 . V_139 ;
if ( V_41 -> V_53 . V_54 . V_22 > V_152 -> V_81 )
V_41 -> V_53 . V_54 . V_22 = V_152 -> V_81 ;
V_12 -> V_22 = V_41 -> V_53 . V_54 . V_22 ;
if ( V_12 -> V_22 > ( V_152 -> V_81 / 6 ) ) V_12 -> V_36 = V_408 / 10 ;
else if ( V_12 -> V_22 > ( V_152 -> V_81 / 130 ) ) V_12 -> V_36 = V_408 ;
else if ( V_12 -> V_22 <= 170 ) V_12 -> V_36 = 16 * V_408 ;
else V_12 -> V_36 = 2700 * V_408 / V_12 -> V_22 ;
if ( V_12 -> V_22 < V_152 -> V_23 )
F_78 ( & V_12 -> V_162 ) ;
if ( V_12 -> V_22 < V_152 -> V_23 ) {
struct V_409 * V_410 = F_87 ( V_41 ) ;
if ( V_41 -> V_53 . V_54 . V_404 != 0 ) {
if ( V_12 -> V_22 > 60000 )
V_410 -> V_411 = V_41 -> V_53 . V_54 . V_404 * 5 ;
else if ( V_12 -> V_22 > 2000 )
V_410 -> V_411 = V_41 -> V_53 . V_54 . V_404 * 4 ;
else
V_410 -> V_411 = V_41 -> V_53 . V_54 . V_404 * 3 ;
}
else
V_410 -> V_411 = 24576 ;
}
V_400 = (struct V_47 * ) V_152 -> V_49 ;
V_401 = (struct V_50 * ) V_152 -> V_52 ;
V_400 += V_41 -> V_58 ;
V_401 += V_41 -> V_58 ;
memset ( ( V_98 ) V_400 , 0 , sizeof( * V_400 ) ) ;
memset ( ( V_98 ) V_401 , 0 , sizeof( * V_401 ) ) ;
V_401 -> V_412 = ( V_41 -> V_58 >> 12 ) & 0x000f ;
V_401 -> V_413 = ( V_41 -> V_58 & 0x0fff ) << 4 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_414 )
{
V_400 -> type = V_415 ;
V_400 -> V_62 = V_416 ;
V_400 -> V_417 = F_18 ( V_152 -> V_81 ) ;
if ( V_41 -> V_53 . V_54 . V_22 > 0 )
V_400 -> V_417 = F_18 ( V_41 -> V_53 . V_54 . V_22 ) ;
F_88 (printk(L_93,
vcc->qos.txtp.max_pcr,vc->acr);)
}
else if ( V_41 -> V_53 . V_54 . V_55 == V_56 )
{ T_9 V_79 ;
F_8 (printk(L_94);)
F_24 ( V_152 , & V_79 ) ;
if ( V_41 -> V_53 . V_54 . V_22 > 0 )
V_79 . V_22 = V_41 -> V_53 . V_54 . V_22 ;
if ( V_41 -> V_53 . V_54 . V_418 > 0 ) {
int V_419 = V_152 -> V_121 + V_152 -> V_420 + V_41 -> V_53 . V_54 . V_418 ;
if ( V_419 > V_152 -> V_81 )
return - V_142 ;
V_79 . V_82 = V_41 -> V_53 . V_54 . V_418 ;
V_152 -> V_121 += V_41 -> V_53 . V_54 . V_418 ;
}
else V_79 . V_82 = 0 ;
if ( V_41 -> V_53 . V_54 . V_83 )
V_79 . V_83 = V_41 -> V_53 . V_54 . V_83 ;
if ( V_41 -> V_53 . V_54 . V_84 )
V_79 . V_84 = V_41 -> V_53 . V_54 . V_84 ;
if ( V_41 -> V_53 . V_54 . V_85 )
V_79 . V_85 = V_41 -> V_53 . V_54 . V_85 ;
if ( V_41 -> V_53 . V_54 . V_86 )
V_79 . V_86 = V_41 -> V_53 . V_54 . V_86 ;
if ( V_41 -> V_53 . V_54 . V_87 )
V_79 . V_87 = V_41 -> V_53 . V_54 . V_87 ;
if ( V_41 -> V_53 . V_54 . V_421 )
V_79 . V_88 = V_41 -> V_53 . V_54 . V_88 ;
if ( V_41 -> V_53 . V_54 . V_422 )
V_79 . V_89 = V_41 -> V_53 . V_54 . V_89 ;
if ( V_41 -> V_53 . V_54 . V_423 )
V_79 . V_91 = V_41 -> V_53 . V_54 . V_91 ;
if ( V_41 -> V_53 . V_54 . V_424 )
V_79 . V_90 = V_41 -> V_53 . V_54 . V_90 ;
if ( V_79 . V_83 > V_79 . V_22 )
V_79 . V_83 = V_79 . V_22 ;
F_8 (printk(L_95,
srv_p.pcr, srv_p.mcr);)
F_25 ( V_152 , & V_79 , V_41 , 1 ) ;
} else if ( V_41 -> V_53 . V_54 . V_55 == V_403 ) {
if ( V_152 -> V_186 & V_188 ) {
F_9 ( L_91 ) ;
return - V_282 ;
}
if ( V_41 -> V_53 . V_54 . V_139 > V_152 -> V_81 ) {
F_28 (printk(L_96);)
return - 1 ;
}
V_400 -> type = V_425 ;
V_400 -> V_62 = V_416 ;
if ( ( V_402 = F_27 ( V_152 , V_41 ) ) < 0 ) {
return V_402 ;
}
}
else
F_9 ( L_97 ) ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_59 |= V_119 ;
F_10 (printk(L_98);)
return 0 ;
}
static int F_89 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
struct V_426 * V_275 ;
unsigned int V_427 ;
void * V_344 ;
int V_31 ;
T_3 V_428 ;
T_3 * V_429 ;
T_3 V_430 ;
T_3 * V_431 ;
struct V_47 * V_400 ;
struct V_50 * V_401 ;
T_3 V_432 ;
T_8 V_348 ;
V_152 = F_31 ( V_9 ) ;
F_90 ( & V_152 -> V_392 ) ;
F_47 (printk(L_99,
readw(iadev->seg_reg+SEG_MASK_REG));)
V_344 = F_76 ( V_152 -> V_304 , V_351 ,
& V_152 -> V_433 ) ;
if ( ! V_344 ) {
F_9 (KERN_ERR DEV_LABEL L_78 ) ;
goto V_353;
}
V_152 -> V_395 . V_311 = (struct V_276 * ) V_344 ;
V_152 -> V_395 . V_329 = V_152 -> V_395 . V_311 ;
V_152 -> V_395 . V_302 = V_152 -> V_395 . V_311 ;
V_152 -> V_395 . V_310 = (struct V_276 * ) ( ( unsigned long ) V_344 + sizeof( struct V_276 ) * V_331 ) ;
F_65 ( V_152 -> V_433 & 0xfffff000 ,
V_152 -> V_312 + V_396 ) ;
F_16 ( 0xffff , V_152 -> V_14 + V_74 ) ;
F_16 ( 0 , V_152 -> V_14 + V_68 ) ;
F_16 ( V_434 , V_152 -> V_14 + V_435 ) ;
V_152 -> V_49 = V_152 -> V_17 + V_436 * V_152 -> V_113 ;
V_152 -> V_52 = V_152 -> V_17 + V_437 * V_152 -> V_113 ;
V_152 -> V_69 = V_152 -> V_17 + V_438 * V_152 -> V_113 ;
F_16 ( V_439 , V_152 -> V_14 + V_440 ) ;
V_275 = (struct V_426 * ) ( V_152 -> V_17 + V_439 ) ;
memset ( ( V_98 ) V_275 , 0 , sizeof( * V_275 ) ) ;
V_275 ++ ;
V_427 = V_185 ;
for( V_31 = 1 ; V_31 <= V_152 -> V_39 ; V_31 ++ )
{
memset ( ( V_98 ) V_275 , 0 , sizeof( * V_275 ) ) ;
V_275 -> V_289 = V_441 ;
V_275 -> V_296 = V_427 >> 16 ;
V_275 -> V_297 = V_427 & 0x0000ffff ;
V_275 ++ ;
V_427 += V_152 -> V_175 ;
}
V_152 -> V_442 = F_4 ( V_152 -> V_39 * sizeof( struct V_443 ) , V_388 ) ;
if ( ! V_152 -> V_442 ) {
F_9 (KERN_ERR DEV_LABEL L_100 ) ;
goto V_389;
}
for ( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ )
{
struct V_333 * V_444 ;
V_444 = F_4 ( sizeof( * V_444 ) , V_388 | V_445 ) ;
if( ! V_444 ) {
F_9 (KERN_ERR DEV_LABEL L_101 ) ;
goto V_446;
}
V_152 -> V_442 [ V_31 ] . V_444 = V_444 ;
V_152 -> V_442 [ V_31 ] . V_279 = F_64 ( V_152 -> V_304 ,
V_444 , sizeof( * V_444 ) , V_398 ) ;
}
V_152 -> V_18 = F_4 ( V_152 -> V_39 *
sizeof( struct V_5 ) , V_388 ) ;
if ( ! V_152 -> V_18 ) {
F_9 (KERN_ERR DEV_LABEL L_100 ) ;
goto V_447;
}
V_31 = V_448 * V_152 -> V_113 ;
F_16 ( V_31 >> 16 , V_152 -> V_14 + V_449 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_264 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_450 ) ;
F_16 ( V_31 + V_152 -> V_39 * sizeof( T_3 ) , V_152 -> V_14 + V_15 ) ;
V_152 -> V_16 = V_31 + V_152 -> V_39 * sizeof( T_3 ) ;
F_16 ( V_31 + 2 * V_152 -> V_39 * sizeof( T_3 ) ,
V_152 -> V_14 + V_265 ) ;
V_428 = F_54 ( V_152 -> V_14 + V_264 ) ;
V_429 = ( T_3 * ) ( V_152 -> V_17 + V_428 ) ;
for( V_31 = 1 ; V_31 <= V_152 -> V_39 ; V_31 ++ )
{
* V_429 = ( T_3 ) V_31 ;
V_429 ++ ;
}
V_31 = V_451 * V_152 -> V_113 ;
F_16 ( V_31 , V_152 -> V_14 + V_452 ) ;
F_16 ( V_31 + 2 * V_152 -> V_39 * sizeof( T_3 ) ,
V_152 -> V_14 + V_453 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_454 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_455 ) ;
V_152 -> V_27 . V_456 = F_54 ( V_152 -> V_14 + V_452 ) & 0xffff ;
V_152 -> V_27 . V_457 = F_54 ( V_152 -> V_14 + V_453 ) & 0xffff ;
V_152 -> V_27 . V_458 = F_54 ( V_152 -> V_14 + V_455 ) & 0xffff ;
V_152 -> V_27 . V_29 = F_54 ( V_152 -> V_14 + V_264 ) & 0xffff ;
V_152 -> V_27 . V_28 = F_54 ( V_152 -> V_14 + V_265 ) & 0xffff ;
V_152 -> V_27 . V_38 = F_54 ( V_152 -> V_14 + V_450 ) & 0xffff ;
V_430 = F_54 ( V_152 -> V_14 + V_452 ) ;
V_431 = ( T_3 * ) ( V_152 -> V_17 + V_430 ) ;
for( V_31 = 1 ; V_31 <= V_152 -> V_39 ; V_31 ++ )
{
* V_431 = ( T_3 ) 0 ;
V_431 ++ ;
}
F_47 (printk(L_102);)
#if 1
F_16 ( 0 , V_152 -> V_14 + V_459 ) ;
#else
V_432 = ( V_152 -> V_17 + V_146 * V_152 -> V_113 ) >> 17 ;
F_47 (printk(L_103, tmp16);)
F_16 ( V_432 , V_152 -> V_14 + V_459 ) ;
#endif
F_47 (printk(L_104,
readw(iadev->seg_reg+CBR_PTR_BASE));)
V_432 = ( V_146 * V_152 -> V_113 ) >> 1 ;
F_16 ( V_432 , V_152 -> V_14 + V_460 ) ;
F_47 (printk(L_105, tmp16,
readw(iadev->seg_reg+CBR_TAB_BEG));)
F_16 ( V_432 , V_152 -> V_14 + V_461 + 1 ) ;
V_432 = ( V_146 * V_152 -> V_113 + V_152 -> V_70 * 6 - 2 ) >> 1 ;
F_16 ( V_432 , V_152 -> V_14 + V_461 ) ;
F_47 (printk(L_106,
iadev->seg_reg, readw(iadev->seg_reg+CBR_PTR_BASE));)
F_47 (printk(L_107,
readw(iadev->seg_reg+CBR_TAB_BEG), readw(iadev->seg_reg+CBR_TAB_END),
readw(iadev->seg_reg+CBR_TAB_END+1));)
F_77 ( V_152 -> V_17 + V_146 * V_152 -> V_113 ,
0 , V_152 -> V_70 * 6 ) ;
V_152 -> V_141 = V_152 -> V_144 = V_152 -> V_70 * 3 ;
V_152 -> V_145 = 0 ;
V_152 -> V_140 = V_462 / V_152 -> V_144 ;
V_152 -> V_147 = 0 ;
V_348 = 0 ;
V_31 = 8 * 1024 ;
while ( V_31 != V_152 -> V_70 ) {
V_31 /= 2 ;
V_348 ++ ;
}
V_31 = V_436 * V_152 -> V_113 ;
F_16 ( V_348 | ( ( V_31 >> 8 ) & 0xfff8 ) , V_152 -> V_14 + V_463 ) ;
V_31 = V_437 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 8 ) & 0xfffe , V_152 -> V_14 + V_464 ) ;
V_31 = V_465 * V_152 -> V_113 ;
F_16 ( ( V_31 & 0xffff ) >> 11 , V_152 -> V_14 + V_466 ) ;
V_31 = V_467 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 7 ) & 0xffff , V_152 -> V_14 + V_468 ) ;
memset ( ( V_98 ) ( V_152 -> V_17 + V_465 * V_152 -> V_113 ) ,
0 , V_152 -> V_70 * 8 ) ;
V_31 = V_438 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 11 ) & 0xffff , V_152 -> V_14 + V_469 ) ;
V_31 = V_470 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 7 ) & 0xffff , V_152 -> V_14 + V_471 ) ;
V_31 = V_438 * V_152 -> V_113 ;
memset ( ( V_98 ) ( V_152 -> V_17 + V_31 ) , 0 , V_152 -> V_70 * 4 ) ;
V_400 = (struct V_47 * ) V_152 -> V_49 ;
V_401 = (struct V_50 * ) V_152 -> V_52 ;
V_152 -> V_57 = F_4 ( sizeof( long ) * V_152 -> V_70 , V_388 ) ;
if ( ! V_152 -> V_57 ) {
F_9 ( L_108 ) ;
goto V_472;
}
for( V_31 = 0 ; V_31 < V_152 -> V_70 ; V_31 ++ )
{
memset ( ( V_98 ) V_400 , 0 , sizeof( * V_400 ) ) ;
memset ( ( V_98 ) V_401 , 0 , sizeof( * V_401 ) ) ;
V_152 -> V_57 [ V_31 ] = F_4 ( sizeof( struct V_473 ) ,
V_388 ) ;
if ( ! V_152 -> V_57 [ V_31 ] )
goto V_474;
V_152 -> V_57 [ V_31 ] -> V_66 = 0 ;
V_152 -> V_57 [ V_31 ] -> V_67 = 0 ;
V_152 -> V_57 [ V_31 ] -> V_59 = V_475 ;
V_400 ++ ;
V_401 ++ ;
}
if ( V_152 -> V_186 & V_188 ) {
F_16 ( V_476 , V_152 -> V_14 + V_477 ) ;
F_16 ( ( V_149 | ( 0x23 << 2 ) ) , V_152 -> V_14 + V_151 ) ;
}
else {
F_16 ( F_18 ( V_152 -> V_81 ) , V_152 -> V_14 + V_477 ) ;
F_16 ( ( V_149 | V_150 | ( 0x23 << 2 ) ) , V_152 -> V_14 + V_151 ) ;
}
F_16 ( 0 , V_152 -> V_14 + V_478 ) ;
F_16 ( 0 , V_152 -> V_14 + V_479 ) ;
F_16 ( 0xaa00 , V_152 -> V_14 + V_480 ) ;
V_152 -> V_393 = 0 ;
F_91 ( & V_152 -> V_394 ) ;
F_91 ( & V_152 -> V_481 ) ;
F_78 ( & V_152 -> V_397 ) ;
F_1 ( & V_152 -> V_26 ) ;
F_16 ( V_482 , V_152 -> V_14 + V_483 ) ;
F_78 ( & V_152 -> V_156 ) ;
F_16 ( V_484 , V_152 -> V_14 + V_485 ) ;
F_16 ( V_71 , V_152 -> V_14 + V_68 ) ;
F_54 ( V_152 -> V_14 + V_75 ) ;
F_16 ( ~ ( V_72 | V_73 ) , V_152 -> V_14 + V_74 ) ;
F_16 ( V_72 , V_152 -> V_14 + V_75 ) ;
V_152 -> V_486 = 0 ;
V_152 -> V_23 = V_152 -> V_81 / 3 ;
return 0 ;
V_474:
while ( -- V_31 >= 0 )
F_41 ( V_152 -> V_57 [ V_31 ] ) ;
F_41 ( V_152 -> V_57 ) ;
V_472:
F_41 ( V_152 -> V_18 ) ;
V_447:
V_31 = V_152 -> V_39 ;
V_446:
while ( -- V_31 >= 0 ) {
struct V_443 * V_267 = V_152 -> V_442 + V_31 ;
F_68 ( V_152 -> V_304 , V_267 -> V_279 ,
sizeof( * V_267 -> V_444 ) , V_398 ) ;
F_41 ( V_267 -> V_444 ) ;
}
F_41 ( V_152 -> V_442 ) ;
V_389:
F_80 ( V_152 -> V_304 , V_351 , V_152 -> V_395 . V_311 ,
V_152 -> V_433 ) ;
V_353:
return - V_391 ;
}
static T_17 F_92 ( int V_487 , void * V_488 )
{
struct V_266 * V_9 ;
T_2 * V_152 ;
unsigned int V_62 ;
int V_489 = 0 ;
V_9 = V_488 ;
V_152 = F_31 ( V_9 ) ;
while( ( V_62 = F_7 ( V_152 -> V_490 + V_491 ) & 0x7f ) )
{
V_489 = 1 ;
F_10 (printk(L_109, status);)
if ( V_62 & V_492 )
{
F_10 (printk(L_110, status);)
F_66 ( V_9 ) ;
}
if ( V_62 & V_493 )
{
* ( T_7 * ) ( V_152 -> V_490 + V_491 ) = V_493 ;
F_67 ( V_9 ) ;
}
if ( V_62 & V_494 )
{
F_10 (printk(L_111);)
F_81 ( V_9 ) ;
}
if ( V_62 & V_495 )
{
* ( T_7 * ) ( V_152 -> V_490 + V_491 ) = V_495 ;
F_85 ( V_9 ) ;
}
if ( V_62 & ( V_496 | V_497 | V_498 ) )
{
if ( V_62 & V_496 )
F_48 ( V_152 ) ;
}
}
return F_93 ( V_489 ) ;
}
static int F_94 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
int V_31 ;
T_8 V_499 ;
T_4 V_500 ;
V_152 = F_31 ( V_9 ) ;
V_499 = F_95 ( F_96 ( F_7 (
V_152 -> V_490 + V_501 ) ) ) ;
V_500 = F_97 ( F_98 ( F_7 ( V_152 -> V_490 + V_502 ) ) ) ;
F_47 (printk(L_112, mac1, mac2);)
for ( V_31 = 0 ; V_31 < V_503 ; V_31 ++ )
V_9 -> V_504 [ V_31 ] = V_499 >> ( 8 * ( V_503 - 1 - V_31 ) ) ;
for ( V_31 = 0 ; V_31 < V_505 ; V_31 ++ )
V_9 -> V_504 [ V_31 + V_503 ] = V_500 >> ( 8 * ( V_505 - 1 - V_31 ) ) ;
return 0 ;
}
static int F_99 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
int V_31 , error = 1 ;
unsigned int V_304 [ 64 ] ;
V_152 = F_31 ( V_9 ) ;
for( V_31 = 0 ; V_31 < 64 ; V_31 ++ )
if ( ( error = F_100 ( V_152 -> V_304 ,
V_31 * 4 , & V_304 [ V_31 ] ) ) != V_506 )
return error ;
F_65 ( 0 , V_152 -> V_490 + V_507 ) ;
for( V_31 = 0 ; V_31 < 64 ; V_31 ++ )
if ( ( error = F_101 ( V_152 -> V_304 ,
V_31 * 4 , V_304 [ V_31 ] ) ) != V_506 )
return error ;
F_15 ( 5 ) ;
return 0 ;
}
static int T_18 F_102 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
unsigned long V_508 ;
void T_16 * V_509 ;
unsigned short V_510 ;
int error , V_31 ;
F_47 (printk(L_113);)
V_9 -> V_511 . V_512 = 0 ;
V_9 -> V_511 . V_513 = V_514 ;
V_152 = F_31 ( V_9 ) ;
V_508 = F_103 ( V_152 -> V_304 , 0 ) ;
V_152 -> V_487 = V_152 -> V_304 -> V_487 ;
error = F_104 ( V_152 -> V_304 , V_515 , & V_510 ) ;
if ( error ) {
F_9 (KERN_ERR DEV_LABEL L_114 ,
dev->number,error) ;
return - V_282 ;
}
F_47 (printk(DEV_LABEL L_115,
dev->number, iadev->pci->revision, real_base, iadev->irq);)
V_152 -> V_516 = F_105 ( V_152 -> V_304 , 0 ) ;
if ( V_152 -> V_516 == 0x100000 ) {
V_152 -> V_70 = 4096 ;
V_9 -> V_511 . V_513 = V_517 ;
V_152 -> V_113 = 4 ;
}
else if ( V_152 -> V_516 == 0x40000 ) {
V_152 -> V_70 = 1024 ;
V_152 -> V_113 = 1 ;
}
else {
F_9 ( L_116 , V_152 -> V_516 ) ;
return - V_282 ;
}
F_47 (printk (DEV_LABEL L_117, iadev->pci_map_size);)
F_106 ( V_152 -> V_304 ) ;
F_15 ( 10 ) ;
V_509 = F_107 ( V_508 , V_152 -> V_516 ) ;
if ( ! V_509 )
{
F_9 ( V_518 L_118 ,
V_9 -> V_519 ) ;
return error ;
}
F_47 (printk(DEV_LABEL L_119,
dev->number, iadev->pci->revision, base, iadev->irq);)
V_152 -> V_520 = V_152 -> V_516 / 2 ;
V_152 -> V_508 = V_508 ;
V_152 -> V_509 = V_509 ;
V_152 -> V_490 = V_509 + V_521 ;
V_152 -> V_14 = V_509 + V_522 ;
V_152 -> V_272 = V_509 + V_523 ;
V_152 -> V_195 = V_509 + V_524 ;
V_152 -> V_312 = V_509 + V_524 ;
V_152 -> V_525 = V_509 + V_526 ;
V_152 -> V_17 = V_509 + V_527 ;
V_152 -> V_111 = V_509 + V_528 ;
F_47 (printk(L_120,
iadev->reg,iadev->seg_reg,iadev->reass_reg,
iadev->phy, iadev->ram, iadev->seg_ram,
iadev->reass_ram);)
error = F_94 ( V_9 ) ;
if ( error ) {
F_108 ( V_152 -> V_509 ) ;
return error ;
}
F_9 ( L_121 ) ;
for ( V_31 = 0 ; V_31 < V_529 ; V_31 ++ )
F_9 ( L_122 , V_31 ? L_123 : L_124 , V_9 -> V_504 [ V_31 ] ) ;
F_9 ( L_73 ) ;
if ( F_99 ( V_9 ) ) {
F_108 ( V_152 -> V_509 ) ;
F_9 ( L_125 ) ;
return 1 ;
}
return 0 ;
}
static void F_109 ( T_2 * V_152 ) {
if ( ! V_152 -> V_196 )
return;
V_152 -> V_530 += F_54 ( V_152 -> V_272 + V_531 ) & 0xffff ;
V_152 -> V_530 += ( F_54 ( V_152 -> V_272 + V_532 ) & 0xffff ) << 16 ;
V_152 -> V_533 += F_54 ( V_152 -> V_272 + V_534 ) & 0xffff ;
V_152 -> V_535 += F_54 ( V_152 -> V_272 + V_536 ) & 0xffff ;
V_152 -> V_537 += F_54 ( V_152 -> V_14 + V_538 ) & 0xffff ;
V_152 -> V_537 += ( F_54 ( V_152 -> V_14 + V_539 ) & 0xffff ) << 16 ;
return;
}
static void F_110 ( unsigned long V_540 ) {
unsigned long V_158 ;
static T_5 V_541 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_5 V_31 ;
static T_8 V_542 ;
for ( V_31 = 0 ; V_31 < V_543 ; V_31 ++ ) {
if ( V_544 [ V_31 ] ) {
V_542 = F_7 ( V_544 [ V_31 ] -> V_490 + V_545 ) ;
if ( V_541 [ V_31 ] == 0 ) {
V_541 [ V_31 ] ++ ;
V_542 &= ( ~ V_546 ) ;
F_65 ( V_542 , V_544 [ V_31 ] -> V_490 + V_545 ) ;
F_109 ( V_544 [ V_31 ] ) ;
}
else {
V_541 [ V_31 ] = 0 ;
V_542 |= V_546 ;
F_65 ( V_542 , V_544 [ V_31 ] -> V_490 + V_545 ) ;
F_82 ( & V_544 [ V_31 ] -> V_392 , V_158 ) ;
if ( V_544 [ V_31 ] -> V_393 )
F_84 ( & V_544 [ V_31 ] -> V_394 ) ;
F_40 ( V_544 [ V_31 ] ) ;
F_83 ( & V_544 [ V_31 ] -> V_392 , V_158 ) ;
}
}
}
F_111 ( & V_547 , V_37 + V_408 / 4 ) ;
return;
}
static void F_112 ( struct V_266 * V_9 , unsigned char V_548 ,
unsigned long V_165 )
{
F_65 ( V_548 , F_31 ( V_9 ) -> V_195 + V_165 ) ;
}
static unsigned char F_113 ( struct V_266 * V_9 , unsigned long V_165 )
{
return F_7 ( F_31 ( V_9 ) -> V_195 + V_165 ) ;
}
static void F_114 ( T_2 * V_152 )
{
int V_31 ;
F_41 ( V_152 -> V_18 ) ;
for ( V_31 = 0 ; V_31 < V_152 -> V_70 ; V_31 ++ )
F_41 ( V_152 -> V_57 [ V_31 ] ) ;
F_41 ( V_152 -> V_57 ) ;
for ( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ ) {
struct V_443 * V_267 = V_152 -> V_442 + V_31 ;
F_68 ( V_152 -> V_304 , V_267 -> V_279 ,
sizeof( * V_267 -> V_444 ) , V_398 ) ;
F_41 ( V_267 -> V_444 ) ;
}
F_41 ( V_152 -> V_442 ) ;
F_80 ( V_152 -> V_304 , V_351 , V_152 -> V_395 . V_311 ,
V_152 -> V_433 ) ;
}
static void F_115 ( T_2 * V_152 )
{
F_41 ( V_152 -> V_288 ) ;
F_80 ( V_152 -> V_304 , V_351 , V_152 -> V_301 . V_311 ,
V_152 -> V_352 ) ;
}
static int T_18 F_116 ( struct V_266 * V_9 )
{
T_2 * V_152 ;
int error ;
unsigned char V_195 ;
T_8 V_542 ;
F_10 (printk(L_126);)
V_152 = F_31 ( V_9 ) ;
if ( F_117 ( V_152 -> V_487 , & F_92 , V_549 , V_518 , V_9 ) ) {
F_9 (KERN_ERR DEV_LABEL L_127 ,
dev->number, iadev->irq) ;
error = - V_550 ;
goto V_353;
}
if ( ( error = F_118 ( V_152 -> V_304 ,
V_515 ,
V_551 | V_552 ) ) )
{
F_9 (KERN_ERR DEV_LABEL L_128
L_129 ,dev->number, error) ;
error = - V_553 ;
goto V_554;
}
F_15 ( 10 ) ;
F_47 (printk(L_130,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));)
V_542 = F_7 ( V_152 -> V_490 + V_545 ) ;
V_542 = ( V_542 & ( V_546 | V_555 ) )
| V_556
| V_557
| V_558
| V_559
| V_560
| V_561
| V_562
| V_563
| V_564
| V_565
| V_566
| V_567
| V_568 ;
F_65 ( V_542 , V_152 -> V_490 + V_545 ) ;
F_47 (printk(L_131,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));
printk(L_132,
readl(iadev->reg+IPHASE5575_BUS_STATUS_REG));)
F_46 ( V_152 ) ;
error = F_89 ( V_9 ) ;
if ( error )
goto V_554;
error = F_75 ( V_9 ) ;
if ( error )
goto V_569;
V_542 = F_7 ( V_152 -> V_490 + V_545 ) ;
F_65 ( V_542 | V_555 , V_152 -> V_490 + V_545 ) ;
F_47 (printk(L_131,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));)
V_195 = 0 ;
F_47 (
if ((phy=ia_phy_get(dev,0)) == 0x30)
printk(L_133,phy&0x0f);
else
printk(L_134,phy);)
if ( V_152 -> V_186 & V_188 )
F_49 ( V_152 ) ;
else if ( V_152 -> V_186 & ( V_189 | V_190 ) )
F_50 ( V_152 ) ;
else {
error = F_119 ( V_9 ) ;
if ( error )
goto V_570;
if ( V_9 -> V_195 -> V_311 ) {
error = V_9 -> V_195 -> V_311 ( V_9 ) ;
if ( error )
goto V_570;
}
F_48 ( V_152 ) ;
}
return 0 ;
V_570:
F_115 ( V_152 ) ;
V_569:
F_114 ( V_152 ) ;
V_554:
F_120 ( V_152 -> V_487 , V_9 ) ;
V_353:
return error ;
}
static void F_121 ( struct V_40 * V_41 )
{
F_122 ( V_571 ) ;
T_4 * V_338 ;
T_2 * V_152 ;
struct V_12 * V_12 ;
struct V_32 * V_33 = NULL ;
struct V_572 V_573 , V_574 ;
unsigned long V_575 , V_158 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
V_12 = F_29 ( V_41 ) ;
if ( ! V_12 ) return;
F_10 (printk(L_135,
ia_vcc->vc_desc_cnt,vcc->vci);)
F_123 ( V_157 , & V_41 -> V_158 ) ;
F_78 ( & V_573 ) ;
F_78 ( & V_574 ) ;
if ( V_41 -> V_53 . V_54 . V_55 != V_341 ) {
V_152 -> V_393 ++ ;
F_124 ( & V_152 -> V_481 , & V_571 , V_576 ) ;
F_125 ( 50 ) ;
F_126 ( & V_152 -> V_481 , & V_571 ) ;
F_82 ( & V_152 -> V_392 , V_158 ) ;
while( ( V_33 = F_34 ( & V_152 -> V_156 ) ) ) {
if ( F_35 ( V_33 ) -> V_41 == V_41 ) {
if ( V_41 -> V_163 ) V_41 -> V_163 ( V_41 , V_33 ) ;
else F_36 ( V_33 ) ;
}
else
F_63 ( & V_573 , V_33 ) ;
}
while( ( V_33 = F_34 ( & V_573 ) ) )
F_63 ( & V_152 -> V_156 , V_33 ) ;
F_10 (printk(L_136, ia_vcc->vc_desc_cnt);)
V_575 = 300000 / V_12 -> V_22 ;
if ( V_575 == 0 )
V_575 = 1 ;
F_83 ( & V_152 -> V_392 , V_158 ) ;
F_127 ( V_152 -> V_394 , ( V_12 -> V_21 <= 0 ) , V_575 ) ;
F_82 ( & V_152 -> V_392 , V_158 ) ;
V_152 -> V_393 -- ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_66 = 0 ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_67 = 0 ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_59 = V_475 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_56 ) {
if ( V_41 -> V_53 . V_54 . V_418 > 0 )
V_152 -> V_121 -= V_41 -> V_53 . V_54 . V_418 ;
}
if ( V_41 -> V_53 . V_54 . V_55 == V_403 ) {
V_12 = F_29 ( V_41 ) ;
V_152 -> V_121 -= V_12 -> V_143 * V_152 -> V_140 ;
F_30 ( V_41 ) ;
}
F_83 ( & V_152 -> V_392 , V_158 ) ;
}
if ( V_41 -> V_53 . V_340 . V_55 != V_341 ) {
V_338 = ( T_4 * ) ( V_152 -> V_111 + V_112 * V_152 -> V_113 ) ;
V_338 += V_41 -> V_58 ;
* V_338 = V_114 ;
V_338 = ( T_4 * ) ( V_152 -> V_111 + V_342 * V_152 -> V_113 ) ;
V_338 += V_41 -> V_58 ;
* V_338 = ( V_41 -> V_58 << 6 ) | 15 ;
if ( V_41 -> V_53 . V_340 . V_55 == V_56 ) {
struct V_345 T_16 * V_345 =
( V_152 -> V_111 + V_116 * V_152 -> V_113 ) ;
V_345 += V_41 -> V_58 ;
V_345 -> V_87 = 0x0003 ;
V_345 -> V_96 = 0x5eb1 ;
}
F_67 ( V_41 -> V_9 ) ;
V_152 -> V_288 [ V_41 -> V_58 ] = NULL ;
}
F_41 ( F_29 ( V_41 ) ) ;
V_12 = NULL ;
V_41 -> V_405 = NULL ;
F_123 ( V_577 , & V_41 -> V_158 ) ;
return;
}
static int F_128 ( struct V_40 * V_41 )
{
struct V_12 * V_12 ;
int error ;
if ( ! F_37 ( V_578 , & V_41 -> V_158 ) )
{
F_10 (printk(L_137);)
V_41 -> V_405 = NULL ;
}
if ( V_41 -> V_58 != V_579 && V_41 -> V_580 != V_581 )
{
F_10 (printk(L_138);)
F_129 ( V_577 , & V_41 -> V_158 ) ;
}
if ( V_41 -> V_53 . V_582 != V_583 )
return - V_282 ;
F_10 (printk(DEV_LABEL L_139,
vcc->dev->number, vcc->vpi, vcc->vci);)
V_12 = F_4 ( sizeof( * V_12 ) , V_388 ) ;
if ( ! V_12 ) return - V_391 ;
V_41 -> V_405 = V_12 ;
if ( ( error = F_74 ( V_41 ) ) )
{
F_10 (printk(L_140);)
F_121 ( V_41 ) ;
return error ;
}
if ( ( error = F_86 ( V_41 ) ) )
{
F_10 (printk(L_141);)
F_121 ( V_41 ) ;
return error ;
}
F_129 ( V_157 , & V_41 -> V_158 ) ;
#if 0
{
static u8 first = 1;
if (first) {
ia_timer.expires = jiffies + 3*HZ;
add_timer(&ia_timer);
first = 0;
}
}
#endif
F_10 (printk(L_142);)
return 0 ;
}
static int F_130 ( struct V_40 * V_41 , struct V_584 * V_53 , int V_158 )
{
F_10 (printk(L_143);)
return 0 ;
}
static int F_131 ( struct V_266 * V_9 , unsigned int V_585 , void T_19 * V_540 )
{
T_20 V_586 ;
T_2 * V_152 ;
int V_31 , V_587 ;
T_4 T_19 * V_588 ;
F_10 (printk(L_144);)
if ( V_585 != V_589 ) {
if ( ! V_9 -> V_195 -> V_590 ) return - V_282 ;
return V_9 -> V_195 -> V_590 ( V_9 , V_585 , V_540 ) ;
}
if ( F_132 ( & V_586 , V_540 , sizeof V_586 ) ) return - V_591 ;
V_587 = V_586 . V_62 ;
if ( ( V_587 < 0 ) || ( V_587 > V_543 ) )
V_587 = 0 ;
V_152 = V_544 [ V_587 ] ;
switch ( V_586 . V_585 ) {
case V_592 :
{
switch ( V_586 . V_593 ) {
case V_594 :
if ( ! F_133 ( V_595 ) ) return - V_596 ;
if ( F_134 ( V_586 . V_597 , V_152 , sizeof( T_2 ) ) )
return - V_591 ;
V_586 . V_62 = 0 ;
break;
case V_598 :
if ( ! F_133 ( V_595 ) ) return - V_596 ;
V_588 = ( T_4 T_19 * ) V_586 . V_597 ;
for( V_31 = 0 ; V_31 < 0x80 ; V_31 += 2 , V_588 ++ )
if( F_135 ( ( T_4 ) ( F_7 ( V_152 -> V_14 + V_31 ) & 0xffff ) , V_588 ) ) return - V_591 ;
V_586 . V_62 = 0 ;
V_586 . V_164 = 0x80 ;
break;
case V_599 :
if ( ! F_133 ( V_595 ) ) return - V_596 ;
V_588 = ( T_4 T_19 * ) V_586 . V_597 ;
for( V_31 = 0 ; V_31 < 0x80 ; V_31 += 2 , V_588 ++ )
if( F_135 ( ( T_4 ) ( F_7 ( V_152 -> V_272 + V_31 ) & 0xffff ) , V_588 ) ) return - V_591 ;
V_586 . V_62 = 0 ;
V_586 . V_164 = 0x80 ;
break;
case V_600 :
{
T_21 * V_601 ;
T_22 * V_27 ;
T_23 * V_268 ;
if ( ! F_133 ( V_595 ) ) return - V_596 ;
V_601 = F_4 ( sizeof( * V_601 ) , V_388 ) ;
if ( ! V_601 ) return - V_391 ;
V_27 = & V_601 -> V_602 ;
V_268 = & V_601 -> V_603 ;
for ( V_31 = 0 ; V_31 < ( sizeof ( T_23 ) ) / 4 ; V_31 ++ )
( ( T_7 * ) V_268 ) [ V_31 ] = F_7 ( V_152 -> V_272 + V_31 ) & 0xffff ;
for ( V_31 = 0 ; V_31 < ( sizeof ( T_22 ) ) / 4 ; V_31 ++ )
( ( T_7 * ) V_27 ) [ V_31 ] = F_7 ( V_152 -> V_14 + V_31 ) & 0xffff ;
if ( F_134 ( V_586 . V_597 , V_601 , sizeof( T_21 ) ) ) {
F_41 ( V_601 ) ;
return - V_591 ;
}
F_41 ( V_601 ) ;
F_9 ( L_145 , V_587 ) ;
V_586 . V_62 = 0 ;
}
break;
case V_604 :
{
if ( ! F_133 ( V_595 ) ) return - V_596 ;
F_53 ( V_152 ) ;
V_586 . V_62 = 0 ;
}
break;
case 0x6 :
{
V_586 . V_62 = 0 ;
F_9 ( L_146 , ( long ) F_136 ( & V_152 -> V_156 ) ) ;
F_9 ( L_147 , ( long ) F_5 ( & V_152 -> V_26 ) ) ;
}
break;
case 0x8 :
{
struct V_605 * V_293 ;
V_293 = & F_137 ( V_606 [ V_587 ] ) -> V_607 ;
F_9 ( L_148 , F_138 ( & V_293 -> V_608 ) ) ;
F_9 ( L_149 , F_138 ( & V_293 -> V_609 ) ) ;
F_9 ( L_150 , F_138 ( & V_293 -> V_610 ) ) ;
F_9 ( L_151 , F_138 ( & V_293 -> V_611 ) ) ;
F_9 ( L_152 , F_138 ( & V_293 -> V_612 ) ) ;
F_9 ( L_153 , F_138 ( & V_293 -> V_613 ) ) ;
F_9 ( L_154 , F_138 ( & V_293 -> V_614 ) ) ;
F_9 ( L_155 , F_138 ( & V_293 -> V_615 ) ) ;
F_9 ( L_156 , F_138 ( & V_293 -> V_616 ) ) ;
}
V_586 . V_62 = 0 ;
break;
case 0x9 :
if ( ! F_133 ( V_595 ) ) return - V_596 ;
for ( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
F_56 ( V_606 [ V_587 ] , V_31 ) ;
F_16 ( ~ ( V_320 | V_324 ) ,
V_152 -> V_272 + V_325 ) ;
V_152 -> V_319 = 1 ;
V_586 . V_62 = 0 ;
break;
case 0xb :
if ( ! F_133 ( V_595 ) ) return - V_596 ;
F_48 ( V_152 ) ;
break;
case 0xa :
if ( ! F_133 ( V_595 ) ) return - V_596 ;
{
V_586 . V_62 = 0 ;
V_617 = V_586 . V_618 ;
F_9 ( L_157 ) ;
}
break;
default:
V_586 . V_62 = 0 ;
break;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_139 ( struct V_40 * V_41 , int V_619 , int V_620 ,
void T_19 * V_621 , int V_622 )
{
F_10 (printk(L_158);)
return - V_282 ;
}
static int F_140 ( struct V_40 * V_41 , int V_619 , int V_620 ,
void T_19 * V_621 , unsigned int V_622 )
{
F_10 (printk(L_159);)
return - V_282 ;
}
static int F_38 ( struct V_40 * V_41 , struct V_32 * V_33 ) {
T_2 * V_152 ;
struct V_276 * V_277 ;
struct V_426 T_16 * V_275 ;
int V_267 ;
int V_623 ;
int V_624 ;
struct V_333 * V_334 ;
struct V_12 * V_20 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
V_20 = F_29 ( V_41 ) ;
if ( ! V_20 -> V_406 ) {
F_9 ( L_160 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
if ( V_33 -> V_164 > V_152 -> V_175 - 8 ) {
F_9 ( L_161 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
if ( ( unsigned long ) V_33 -> V_4 & 3 ) {
F_9 ( L_162 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
V_267 = F_12 ( V_152 , V_20 ) ;
if ( V_267 == 0xffff )
return 1 ;
V_623 = V_267 >> 13 ;
V_267 &= 0x1fff ;
if ( ( V_267 == 0 ) || ( V_267 > V_152 -> V_39 ) )
{
F_17 (printk(DEV_LABEL L_163, desc);)
F_59 ( & V_41 -> V_293 -> V_625 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
if ( V_623 )
{
F_17 (printk(DEV_LABEL L_164,
desc, comp_code);)
}
V_20 -> V_21 ++ ;
V_152 -> V_18 [ V_267 - 1 ] . V_20 = V_20 ;
V_152 -> V_18 [ V_267 - 1 ] . V_24 = V_33 ;
F_11 ( V_33 ) = 0 ;
V_152 -> V_27 . V_38 += 2 ;
if ( V_152 -> V_27 . V_38 > V_152 -> V_27 . V_28 )
V_152 -> V_27 . V_38 = V_152 -> V_27 . V_29 ;
F_16 ( V_152 -> V_27 . V_38 , V_152 -> V_14 + V_450 ) ;
* ( T_4 * ) ( V_152 -> V_17 + V_152 -> V_27 . V_458 ) = V_267 ;
V_152 -> V_27 . V_458 += 2 ;
if ( V_152 -> V_27 . V_458 > V_152 -> V_27 . V_457 )
V_152 -> V_27 . V_458 = V_152 -> V_27 . V_456 ;
V_624 = V_33 -> V_164 + sizeof( struct V_333 ) ;
V_624 = ( ( V_624 + 47 ) / 48 ) * 48 ;
F_141 (printk(L_165, total_len, total_len - skb->len);)
V_334 = V_152 -> V_442 [ V_267 - 1 ] . V_444 ;
F_141 (printk(L_166,
skb, skb->data, skb->len, desc);)
V_334 -> V_626 = 0 ;
V_334 -> V_255 = ( ( V_33 -> V_164 & 0xff ) << 8 ) | ( ( V_33 -> V_164 & 0xff00 ) >> 8 ) ;
V_334 -> V_627 = 0 ;
F_142 (printk(L_167,
skb->len, tcnter++);
xdump(skb->data, skb->len, L_168);
printk(L_73);)
V_275 = V_152 -> V_17 + V_439 ;
V_275 += V_267 ;
V_275 -> V_289 = V_441 | V_628 | V_629 | V_630 ;
F_16 ( V_72 , V_152 -> V_14 + V_75 ) ;
V_275 -> V_287 = V_41 -> V_58 ;
V_275 -> V_307 = V_624 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_56 )
F_14 ( V_41 , V_152 ) ;
V_277 = V_152 -> V_395 . V_302 ;
memset ( ( V_98 ) V_277 , 0 , sizeof( * V_277 ) ) ;
V_277 -> V_303 = F_64 ( V_152 -> V_304 , V_33 -> V_4 ,
V_33 -> V_164 , V_398 ) ;
V_277 -> V_306 = ( V_275 -> V_296 << 16 ) |
V_275 -> V_297 ;
V_277 -> V_307 = V_33 -> V_164 ;
if ( ( V_277 -> V_307 >> 2 ) == 0xb )
V_277 -> V_307 = 0x30 ;
V_277 -> V_308 = V_631 ;
V_277 -> V_632 = 0 ;
if ( ++ V_277 == V_152 -> V_395 . V_310 )
V_277 = V_152 -> V_395 . V_311 ;
V_277 -> V_303 = V_152 -> V_442 [ V_267 - 1 ] . V_279 ;
V_277 -> V_306 = ( ( V_275 -> V_296 << 16 ) |
V_275 -> V_297 ) + V_624 - sizeof( struct V_333 ) ;
V_277 -> V_307 = sizeof( struct V_333 ) ;
V_277 -> V_308 = V_309 ;
V_277 -> V_632 = V_152 -> V_27 . V_458 ;
if ( ++ V_277 == V_152 -> V_395 . V_310 )
V_277 = V_152 -> V_395 . V_311 ;
V_152 -> V_395 . V_302 = V_277 ;
F_62 ( V_33 ) = V_41 -> V_58 ;
F_63 ( & V_152 -> V_397 , V_33 ) ;
F_59 ( & V_41 -> V_293 -> V_625 ) ;
V_152 -> V_486 ++ ;
F_65 ( 2 , V_152 -> V_312 + V_633 ) ;
#if 0
if (atomic_read(&vcc->stats->tx) % 20 == 0) {
if (iavcc->vc_desc_cnt > 10) {
vcc->tx_quota = vcc->tx_quota * 3 / 4;
printk("Tx1: vcc->tx_quota = %d \n", (u32)vcc->tx_quota );
iavcc->flow_inc = -1;
iavcc->saved_tx_quota = vcc->tx_quota;
} else if ((iavcc->flow_inc < 0) && (iavcc->vc_desc_cnt < 3)) {
printk("Tx2: vcc->tx_quota = %d \n", (u32)vcc->tx_quota );
iavcc->flow_inc = 0;
}
}
#endif
F_141 (printk(L_169);)
return 0 ;
}
static int F_143 ( struct V_40 * V_41 , struct V_32 * V_33 )
{
T_2 * V_152 ;
unsigned long V_158 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
if ( ( ! V_33 ) || ( V_33 -> V_164 > ( V_152 -> V_175 - sizeof( struct V_333 ) ) ) )
{
if ( ! V_33 )
F_9 ( V_634 L_170 ) ;
else F_36 ( V_33 ) ;
return - V_282 ;
}
F_82 ( & V_152 -> V_392 , V_158 ) ;
if ( ! F_37 ( V_157 , & V_41 -> V_158 ) ) {
F_36 ( V_33 ) ;
F_83 ( & V_152 -> V_392 , V_158 ) ;
return - V_282 ;
}
F_35 ( V_33 ) -> V_41 = V_41 ;
if ( F_136 ( & V_152 -> V_156 ) ) {
F_63 ( & V_152 -> V_156 , V_33 ) ;
}
else {
if ( F_38 ( V_41 , V_33 ) ) {
F_63 ( & V_152 -> V_156 , V_33 ) ;
}
}
F_83 ( & V_152 -> V_392 , V_158 ) ;
return 0 ;
}
static int F_144 ( struct V_266 * V_9 , T_24 * V_635 , char * V_636 )
{
int V_637 = * V_635 , V_638 ;
char * V_639 ;
T_2 * V_152 = F_31 ( V_9 ) ;
if( ! V_637 -- ) {
if ( V_152 -> V_186 == V_188 ) {
V_638 = sprintf ( V_636 , L_171 ) ;
return V_638 ;
}
if ( V_152 -> V_186 == V_189 )
V_638 = sprintf ( V_636 , L_172 ) ;
else if ( V_152 -> V_186 == V_190 )
V_638 = sprintf ( V_636 , L_173 ) ;
else if ( V_152 -> V_186 == V_640 )
V_638 = sprintf ( V_636 , L_174 ) ;
else
V_638 = sprintf ( V_636 , L_175 ) ;
V_639 = V_636 + V_638 ;
if ( V_152 -> V_516 == 0x40000 )
V_638 += sprintf ( V_639 , L_176 ) ;
else
V_638 += sprintf ( V_639 , L_177 ) ;
V_639 = V_636 + V_638 ;
if ( ( V_152 -> V_171 & V_172 ) == V_173 )
V_638 += sprintf ( V_639 , L_178 ) ;
else if ( ( V_152 -> V_171 & V_172 ) == V_181 )
V_638 += sprintf ( V_639 , L_179 ) ;
else
V_638 += sprintf ( V_639 , L_180 ) ;
return V_638 ;
}
if ( ! V_637 ) {
return sprintf ( V_636 , L_181
L_182
L_183
L_184
L_185
L_186
L_187
L_188
L_189
L_190 ,
V_152 -> V_39 , V_152 -> V_175 ,
V_152 -> V_177 , V_152 -> V_179 ,
V_152 -> V_322 , V_152 -> V_486 ,
V_152 -> V_530 , V_152 -> V_537 ,
V_152 -> V_535 , V_152 -> V_533 ) ;
}
return 0 ;
}
static int T_18 F_145 ( struct V_641 * V_642 ,
const struct V_643 * V_644 )
{
struct V_266 * V_9 ;
T_2 * V_152 ;
int V_402 ;
V_152 = F_79 ( sizeof( * V_152 ) , V_388 ) ;
if ( ! V_152 ) {
V_402 = - V_391 ;
goto V_353;
}
V_152 -> V_304 = V_642 ;
F_47 (printk(L_191,
pdev->bus->number, PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));)
if ( F_146 ( V_642 ) ) {
V_402 = - V_645 ;
goto V_646;
}
V_9 = F_147 ( V_518 , & V_642 -> V_9 , & V_647 , - 1 , NULL ) ;
if ( ! V_9 ) {
V_402 = - V_391 ;
goto V_648;
}
V_9 -> V_405 = V_152 ;
F_47 (printk(DEV_LABEL L_192, dev->number);)
F_47 (printk(L_193, dev,
iadev->LineRate);)
F_148 ( V_642 , V_9 ) ;
V_544 [ V_543 ] = V_152 ;
V_606 [ V_543 ] = V_9 ;
V_543 ++ ;
if ( F_102 ( V_9 ) || F_116 ( V_9 ) ) {
F_47 (printk(L_194);)
V_543 -- ;
V_544 [ V_543 ] = NULL ;
V_606 [ V_543 ] = NULL ;
V_402 = - V_282 ;
goto V_649;
}
F_10 (printk(L_195, iadev_count);)
V_152 -> V_650 = V_651 ;
V_651 = V_9 ;
return 0 ;
V_649:
F_149 ( V_9 ) ;
V_648:
F_150 ( V_642 ) ;
V_646:
F_41 ( V_152 ) ;
V_353:
return V_402 ;
}
static void T_25 F_151 ( struct V_641 * V_642 )
{
struct V_266 * V_9 = F_152 ( V_642 ) ;
T_2 * V_152 = F_31 ( V_9 ) ;
F_112 ( V_9 , F_113 ( V_9 , V_652 ) & ~ ( V_653 ) ,
V_652 ) ;
F_15 ( 1 ) ;
if ( V_9 -> V_195 && V_9 -> V_195 -> V_654 )
V_9 -> V_195 -> V_654 ( V_9 ) ;
F_120 ( V_152 -> V_487 , V_9 ) ;
V_543 -- ;
V_544 [ V_543 ] = NULL ;
V_606 [ V_543 ] = NULL ;
F_10 (printk(L_196, dev->number);)
F_149 ( V_9 ) ;
F_108 ( V_152 -> V_509 ) ;
F_150 ( V_642 ) ;
F_115 ( V_152 ) ;
F_114 ( V_152 ) ;
F_41 ( V_152 ) ;
}
static int T_26 F_153 ( void )
{
int V_402 ;
V_402 = F_154 ( & V_655 ) ;
if ( V_402 >= 0 ) {
V_547 . V_656 = V_37 + 3 * V_408 ;
F_155 ( & V_547 ) ;
} else
F_9 (KERN_ERR DEV_LABEL L_197 ) ;
return V_402 ;
}
static void T_27 F_156 ( void )
{
F_157 ( & V_655 ) ;
F_158 ( & V_547 ) ;
}
