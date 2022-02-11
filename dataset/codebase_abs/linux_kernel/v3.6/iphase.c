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
static T_8 F_48 ( struct V_192 * V_193 , unsigned int V_194 )
{
return F_7 ( V_193 -> V_195 + ( V_194 >> 2 ) ) ;
}
static void F_49 ( struct V_192 * V_193 , unsigned int V_194 , T_8 V_166 )
{
F_50 ( V_166 , V_193 -> V_195 + ( V_194 >> 2 ) ) ;
}
static void F_51 ( struct V_192 * V_152 )
{
T_8 V_62 ;
if ( V_152 -> V_186 & V_188 ) {
V_62 = F_48 ( V_152 , V_196 ) ;
V_152 -> V_197 = ( V_62 & V_198 ) ? 1 : 0 ;
} else if ( V_152 -> V_186 & V_189 ) {
F_48 ( V_152 , V_199 ) ;
V_62 = F_48 ( V_152 , V_200 ) ;
V_152 -> V_197 = ( V_62 & V_201 ) ? 0 : 1 ;
} else if ( V_152 -> V_186 & V_190 ) {
F_48 ( V_152 , V_202 ) ;
V_62 = F_48 ( V_152 , V_203 ) ;
V_152 -> V_197 = ( V_62 & V_204 ) ? 0 : 1 ;
} else {
V_62 = F_48 ( V_152 , V_205 ) ;
V_152 -> V_197 = ( V_62 & V_206 ) ? 0 : 1 ;
}
F_9 ( V_207 L_36 ,
V_152 -> V_197 ? L_37 : L_38 ) ;
}
static void F_52 ( struct V_192 * V_152 )
{
#if 0
mb25->mb25_master_ctrl = MB25_MC_DRIC | MB25_MC_DREC | MB25_MC_ENABLED;
#endif
F_49 ( V_152 , V_208 , V_209 | V_210 ) ;
F_49 ( V_152 , V_211 , 0 ) ;
V_152 -> V_197 =
( F_48 ( V_152 , V_196 ) & V_198 ) ? 1 : 0 ;
}
static void F_53 ( struct V_192 * V_152 ,
const struct V_212 * V_213 , int V_164 )
{
while ( V_164 -- ) {
F_49 ( V_152 , V_213 -> V_194 , V_213 -> V_166 ) ;
V_213 ++ ;
}
}
static void F_54 ( struct V_192 * V_152 )
{
static const struct V_212 V_214 [] = {
{ V_215 , 0x17 } ,
{ V_216 , 0x01 } ,
{ V_217 , 0x01 } ,
{ V_218 , 0 } ,
{ V_219 , 0 } ,
{ V_220 , 0 }
} ;
T_8 V_62 ;
V_62 = F_48 ( V_152 , V_200 ) ;
V_152 -> V_197 = ( V_62 & V_201 ) ? 0 : 1 ;
F_53 ( V_152 , V_214 , F_55 ( V_214 ) ) ;
}
static void F_56 ( struct V_192 * V_152 )
{
static const struct V_212 V_221 [] = {
{ V_222 , 0x04 } ,
{ V_223 , 0x20 } ,
{ V_224 , 0x1d } ,
{ V_225 , 0x30 } ,
{ V_226 , 0 } ,
{ V_227 , 0x01 } ,
{ V_218 , V_228 } ,
{ V_219 , 0x41 } ,
{ V_220 , 0x41 }
} ;
T_8 V_62 ;
V_62 = F_48 ( V_152 , V_203 ) ;
V_152 -> V_197 = ( V_62 & V_204 ) ? 0 : 1 ;
F_53 ( V_152 , V_221 , F_55 ( V_221 ) ) ;
}
static void F_57 ( struct V_192 * V_152 )
{
static const struct V_212 V_229 [] = {
{ V_230 , 0x28 } ,
{ V_231 , 0 } ,
{ V_232 , 0 } ,
{ V_233 , 0x2c } ,
{ V_234 , 0x81 } ,
{ V_235 , 0 } ,
{ V_236 , 0 } ,
{ V_237 , 0 } ,
{ V_238 , 0x01 } ,
{ V_239 , 0xff } ,
{ V_240 , 0xff } ,
{ V_241 , 0xff } ,
{ V_242 , 0xfe } ,
{ V_243 , 0 } ,
{ V_244 , 0 } ,
{ V_245 , 0 } ,
{ V_246 , 0x01 } ,
{ V_247 , 0xff } ,
{ V_248 , 0xff } ,
{ V_249 , 0xff } ,
{ V_250 , 0xff } ,
{ V_251 , 0xa4 } ,
{ V_252 , 0x10 } ,
{ V_253 , 0x55 }
} ;
if ( V_152 -> V_186 & V_189 )
F_54 ( V_152 ) ;
else
F_56 ( V_152 ) ;
F_53 ( V_152 , V_229 , F_55 ( V_229 ) ) ;
F_49 ( V_152 , V_218 , F_48 ( V_152 , V_218 ) &
~ ( V_254 | V_255 |
V_256 | V_257 ) ) ;
#ifdef F_58
V_258 -> V_259 |= V_260 ;
#endif
return;
}
static void F_59 ( T_5 * V_261 , int V_262 , char * V_263 )
{
int V_264 , V_265 ;
T_5 V_266 [ 120 ] ;
T_5 * V_267 = V_266 ;
V_265 = 0 ;
while( V_265 < V_262 ) {
V_267 += sprintf ( V_267 , L_39 , V_263 ) ;
for( V_264 = 0 ; V_265 + V_264 < V_262 && V_264 < 16 ; V_264 ++ ) {
if ( V_264 != 0 && ( V_264 % 4 ) == 0 )
V_267 += sprintf ( V_267 , L_40 ) ;
V_267 += sprintf ( V_267 , L_41 , V_261 [ V_265 + V_264 ] ) ;
}
while( V_264 ++ < 16 ) {
if ( ( V_264 % 4 ) == 0 )
sprintf ( V_267 , L_40 ) ;
V_267 += sprintf ( V_267 , L_42 ) ;
}
V_267 += sprintf ( V_267 , L_43 ) ;
for( V_264 = 0 ; V_265 + V_264 < V_262 && V_264 < 16 ; V_264 ++ ) {
if ( isprint ( ( int ) V_261 [ V_265 + V_264 ] ) )
V_267 += sprintf ( V_267 , L_44 , V_261 [ V_265 + V_264 ] ) ;
else
V_267 += sprintf ( V_267 , L_45 ) ;
}
F_9 ( L_46 , V_266 ) ;
V_265 += V_264 ;
V_267 = V_266 ;
}
}
static void F_60 ( T_2 * V_152 ) {
T_3 V_268 , V_269 , V_270 ;
T_8 V_31 ;
void T_13 * V_78 ;
V_268 = F_61 ( V_152 -> V_14 + V_15 ) ;
F_9 ( L_47 ,
V_268 , F_61 ( V_152 -> V_17 + V_268 ) ,
F_61 ( V_152 -> V_17 + V_268 - 2 ) ) ;
F_9 ( L_48 , V_152 -> V_16 ,
V_152 -> V_27 . V_38 ) ;
V_269 = F_61 ( V_152 -> V_14 + V_271 ) ;
V_270 = F_61 ( V_152 -> V_14 + V_272 ) ;
F_9 ( L_49 , V_269 , V_270 ) ;
V_31 = 0 ;
while ( V_269 != V_270 ) {
V_78 = V_152 -> V_17 + V_269 ;
F_9 ( L_50 , V_31 ++ , F_61 ( V_78 ) , V_78 ) ;
V_269 += 2 ;
}
for( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ )
F_9 ( L_51 , V_31 , V_152 -> V_18 [ V_31 ] . V_19 ) ;
}
static void F_62 ( struct V_273 * V_9 )
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
static void F_63 ( struct V_273 * V_9 , int V_274 )
{
T_2 * V_152 ;
V_152 = F_31 ( V_9 ) ;
F_16 ( V_274 , V_152 -> V_111 + V_152 -> V_275 . V_276 ) ;
V_152 -> V_275 . V_276 += 2 ;
if ( V_152 -> V_275 . V_276 > V_152 -> V_275 . V_277 )
V_152 -> V_275 . V_276 = V_152 -> V_275 . V_278 ;
F_16 ( V_152 -> V_275 . V_276 , V_152 -> V_279 + V_280 ) ;
}
static int F_64 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
struct V_40 * V_41 ;
unsigned short V_62 ;
struct V_281 T_13 * V_282 ;
int V_274 ;
struct V_283 * V_284 ;
int V_164 ;
struct V_32 * V_33 ;
T_7 V_285 , V_286 ;
V_152 = F_31 ( V_9 ) ;
if ( V_152 -> V_275 . V_287 == ( F_61 ( V_152 -> V_279 + V_288 ) & 0xffff ) )
{
F_9 (KERN_ERR DEV_LABEL L_52 , dev->number) ;
return - V_289 ;
}
V_274 = F_61 ( V_152 -> V_111 + V_152 -> V_275 . V_287 ) & 0x1fff ;
F_65 (printk(L_53,
iadev->reass_ram, iadev->rfL.pcq_rd, desc);
printk(L_54,
readw(iadev->reass_reg+PCQ_WR_PTR)&0xffff);)
if ( V_152 -> V_275 . V_287 == V_152 -> V_275 . V_290 )
V_152 -> V_275 . V_287 = V_152 -> V_275 . V_291 ;
else
V_152 -> V_275 . V_287 += 2 ;
F_16 ( V_152 -> V_275 . V_287 , V_152 -> V_279 + V_292 ) ;
V_282 = V_152 -> V_293 ;
V_282 += V_274 ;
if ( ! V_274 || ( V_274 > V_152 -> V_177 ) ||
( ( V_282 -> V_294 & 0xffff ) > V_152 -> V_70 ) ) {
F_63 ( V_9 , V_274 ) ;
F_17 (printk(L_55, desc);)
return - 1 ;
}
V_41 = V_152 -> V_295 [ V_282 -> V_294 & 0xffff ] ;
if ( ! V_41 )
{
F_63 ( V_9 , V_274 ) ;
F_9 ( L_56 ) ;
return - 1 ;
}
V_62 = ( T_3 ) ( V_282 -> V_296 ) ;
if ( V_62 & ( V_297 | V_298 | V_299 ) )
{
F_66 ( & V_41 -> V_300 -> V_301 ) ;
F_17 (printk(L_57);)
if ( V_62 & V_297 ) {
F_17 (printk(L_58);)
}
else if ( V_62 & V_298 ) {
F_17 (printk(L_59);)
}
else {
F_17 (printk(L_60);)
}
goto V_302;
}
V_285 = ( V_282 -> V_303 << 16 ) | V_282 -> V_304 ;
V_286 = ( V_282 -> V_305 << 16 ) | V_282 -> V_306 ;
V_164 = V_286 - V_285 ;
if ( V_164 > V_152 -> V_179 ) {
F_9 ( L_61 , V_152 -> V_179 ) ;
F_66 ( & V_41 -> V_300 -> V_301 ) ;
goto V_302;
}
if ( ! ( V_33 = F_67 ( V_41 , V_164 , V_7 ) ) ) {
if ( V_41 -> V_58 < 32 )
F_9 ( L_62 ) ;
goto V_302;
}
F_68 ( V_33 , V_164 ) ;
F_35 ( V_33 ) -> V_41 = V_41 ;
F_69 ( V_33 ) = V_274 ;
F_70 ( & V_152 -> V_307 , V_33 ) ;
V_284 = V_152 -> V_308 . V_309 ;
V_284 -> V_310 = F_71 ( V_152 -> V_311 , V_33 -> V_4 ,
V_164 , V_312 ) ;
V_284 -> V_313 = V_285 ;
V_284 -> V_314 = V_164 ;
V_284 -> V_315 = V_316 ;
if( ++ V_284 == V_152 -> V_308 . V_317 )
V_284 = V_152 -> V_308 . V_318 ;
V_152 -> V_308 . V_309 = V_284 ;
F_15 ( 1 ) ;
F_50 ( 1 , V_152 -> V_319 + V_320 ) ;
V_161: return 0 ;
V_302:
F_63 ( V_9 , V_274 ) ;
goto V_161;
}
static void F_72 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
T_3 V_62 ;
T_3 V_321 , V_31 ;
V_152 = F_31 ( V_9 ) ;
V_62 = F_7 ( V_152 -> V_279 + V_322 ) & 0xffff ;
F_10 (printk(L_63, status);)
if ( V_62 & V_323 )
{
V_321 = F_7 ( V_152 -> V_279 + V_324 ) & 0xffff ;
F_10 (printk(L_64, status);)
while( ! ( V_321 & V_325 ) )
{
F_64 ( V_9 ) ;
V_321 = F_7 ( V_152 -> V_279 + V_324 ) & 0xffff ;
}
V_152 -> V_326 = 1 ;
}
if ( V_62 & V_327 )
{
if ( V_152 -> V_326 ) {
V_152 -> V_328 = V_152 -> V_329 ;
V_152 -> V_330 = V_37 ;
V_152 -> V_326 = 0 ;
}
else if ( ( F_13 ( V_37 , V_152 -> V_330 + 50 ) ) &&
( ( V_152 -> V_329 - V_152 -> V_328 ) == 0 ) ) {
for ( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
F_63 ( V_9 , V_31 ) ;
F_9 ( L_65 ) ;
F_16 ( ~ ( V_327 | V_331 ) , V_152 -> V_279 + V_332 ) ;
V_152 -> V_326 = 1 ;
}
F_10 (printk(L_66, status);)
}
if ( V_62 & V_331 )
{
F_10 (printk(L_67, status);)
F_62 ( V_9 ) ;
}
if ( V_62 & V_333 )
{
F_10 (printk(L_68, status);)
}
}
static void F_73 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
struct V_40 * V_41 ;
struct V_32 * V_33 ;
int V_274 ;
T_3 V_321 ;
struct V_283 * V_283 , * V_334 ;
T_7 V_335 ;
int V_164 ;
V_152 = F_31 ( V_9 ) ;
V_283 = V_152 -> V_308 . V_336 ;
V_335 = F_7 ( V_152 -> V_319 + V_337 ) & ( sizeof( struct V_283 ) * V_338 - 1 ) ;
V_334 = (struct V_283 * ) ( V_152 -> V_308 . V_318 + ( V_335 >> 4 ) ) ;
while( V_283 != V_334 )
{
V_33 = F_34 ( & V_152 -> V_307 ) ;
if ( ! V_33 )
goto V_339;
V_274 = F_69 ( V_33 ) ;
F_63 ( V_9 , V_274 ) ;
if ( ! ( V_164 = V_33 -> V_164 ) )
{
F_9 ( L_69 ) ;
F_36 ( V_33 ) ;
}
else
{
struct V_340 * V_341 ;
T_3 V_262 ;
struct V_12 * V_12 ;
F_74 ( V_152 -> V_311 , V_152 -> V_308 . V_309 -> V_310 ,
V_164 , V_312 ) ;
V_41 = F_35 ( V_33 ) -> V_41 ;
if ( ! V_41 ) {
F_9 ( L_70 ) ;
F_36 ( V_33 ) ;
goto V_339;
}
V_12 = F_29 ( V_41 ) ;
if ( V_12 == NULL )
{
F_66 ( & V_41 -> V_300 -> V_301 ) ;
F_75 ( V_41 , V_33 -> V_342 ) ;
F_36 ( V_33 ) ;
goto V_339;
}
V_341 = (struct V_340 * ) ( ( T_5 * ) V_33 -> V_4 +
V_33 -> V_164 - sizeof( * V_341 ) ) ;
V_262 = F_76 ( V_341 -> V_262 ) ;
if ( ( V_262 > V_152 -> V_179 ) || ( V_262 >
( V_33 -> V_164 - sizeof( struct V_340 ) ) ) )
{
F_66 ( & V_41 -> V_300 -> V_301 ) ;
F_17 (printk(L_71,
length, skb->len);)
F_75 ( V_41 , V_33 -> V_342 ) ;
F_36 ( V_33 ) ;
goto V_339;
}
F_77 ( V_33 , V_262 ) ;
F_78 (printk(L_72, skb->len);
xdump(skb->data, skb->len, L_73);
printk(L_74);)
F_65 (printk(L_75);)
V_41 -> V_343 ( V_41 , V_33 ) ;
F_66 ( & V_41 -> V_300 -> V_344 ) ;
V_152 -> V_329 ++ ;
}
V_339:
if ( ++ V_283 == V_152 -> V_308 . V_317 )
V_283 = V_152 -> V_308 . V_318 ;
}
V_152 -> V_308 . V_336 = V_283 ;
if ( ! V_152 -> V_326 ) {
V_321 = F_7 ( V_152 -> V_279 + V_324 ) & 0xffff ;
if ( ! ( V_321 & V_345 ) ) {
V_321 = F_7 ( V_152 -> V_279 + V_332 ) & 0xffff ;
F_50 ( V_321 & ~ ( V_327 | V_323 ) ,
V_152 -> V_279 + V_332 ) ;
V_152 -> V_326 ++ ;
}
}
}
static int F_79 ( struct V_40 * V_41 )
{
T_2 * V_152 ;
T_3 T_13 * V_346 ;
T_3 T_13 * V_347 ;
F_10 (printk(L_76, vcc->vpi, vcc->vci);)
if ( V_41 -> V_53 . V_348 . V_55 == V_349 ) return 0 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
if ( V_41 -> V_53 . V_348 . V_55 == V_56 ) {
if ( V_152 -> V_186 & V_188 ) {
F_9 ( L_77 ) ;
return - V_289 ;
}
}
V_346 = V_152 -> V_111 + V_350 * V_152 -> V_113 ;
V_346 += V_41 -> V_58 ;
* V_346 = V_41 -> V_58 << 6 ;
if ( ( V_41 -> V_53 . V_348 . V_55 == V_56 ) ||
( V_41 -> V_53 . V_54 . V_55 == V_56 ) )
{
T_9 V_79 ;
F_24 ( V_152 , & V_79 ) ;
F_25 ( V_152 , & V_79 , V_41 , 0 ) ;
}
else {
V_347 = V_152 -> V_111 + V_112 * V_152 -> V_113 ;
V_347 += V_41 -> V_58 ;
* V_347 = V_114 ;
}
if ( V_152 -> V_295 [ V_41 -> V_58 ] )
F_9 (KERN_CRIT DEV_LABEL L_78 ,
vcc->dev->number, vcc->vci) ;
V_152 -> V_295 [ V_41 -> V_58 ] = V_41 ;
return 0 ;
}
static int F_80 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
struct V_281 T_13 * V_282 ;
unsigned long V_351 = 0 ;
void * V_352 ;
struct V_353 * V_353 ;
T_4 * V_346 ;
T_4 * V_354 ;
int V_31 , V_355 , V_356 ;
T_3 V_357 ;
T_3 * V_358 ;
V_152 = F_31 ( V_9 ) ;
V_352 = F_81 ( V_152 -> V_311 , V_359 ,
& V_152 -> V_360 ) ;
if ( ! V_352 ) {
F_9 (KERN_ERR DEV_LABEL L_79 ) ;
goto V_361;
}
V_152 -> V_308 . V_318 = (struct V_283 * ) V_352 ;
V_152 -> V_308 . V_336 = V_152 -> V_308 . V_318 ;
V_152 -> V_308 . V_309 = V_152 -> V_308 . V_318 ;
V_152 -> V_308 . V_317 = (struct V_283 * ) ( ( unsigned long ) V_352 + sizeof( struct V_283 ) * V_338 ) ;
F_50 ( V_152 -> V_360 & 0xfffff000 ,
V_152 -> V_319 + V_337 ) ;
F_47 (printk(L_80,
iadev->dma+IPHASE5575_TX_LIST_ADDR,
readl(iadev->dma + IPHASE5575_TX_LIST_ADDR));
printk(L_81,
iadev->dma+IPHASE5575_RX_LIST_ADDR,
readl(iadev->dma + IPHASE5575_RX_LIST_ADDR));)
F_16 ( 0xffff , V_152 -> V_279 + V_332 ) ;
F_16 ( 0 , V_152 -> V_279 + V_362 ) ;
F_16 ( V_363 , V_152 -> V_279 + V_364 ) ;
F_16 ( V_365 >> 16 , V_152 -> V_279 + V_366 ) ;
F_16 ( V_152 -> V_179 , V_152 -> V_279 + V_367 ) ;
V_152 -> V_293 = V_152 -> V_111 + V_365 * V_152 -> V_113 ;
V_282 = V_152 -> V_293 ;
F_82 ( V_282 , 0 , sizeof( * V_282 ) ) ;
V_282 ++ ;
V_351 = V_152 -> V_184 ;
for( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
{
F_82 ( V_282 , 0 , sizeof( * V_282 ) ) ;
V_282 -> V_303 = V_351 >> 16 ;
V_282 -> V_304 = V_351 & 0x0000ffff ;
V_282 ++ ;
V_351 += V_152 -> V_179 ;
}
F_47 (printk(L_82, buf_desc_ptr);)
V_31 = V_368 * V_152 -> V_113 ;
F_16 ( V_31 >> 16 , V_152 -> V_279 + V_369 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_370 ) ;
F_16 ( V_31 + V_152 -> V_177 * sizeof( T_3 ) ,
V_152 -> V_279 + V_371 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_372 ) ;
F_16 ( V_31 + V_152 -> V_177 * sizeof( T_3 ) ,
V_152 -> V_279 + V_280 ) ;
V_357 = F_61 ( V_152 -> V_279 + V_370 ) ;
V_358 = ( T_3 * ) ( V_152 -> V_111 + V_357 ) ;
for( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
{
* V_358 = ( T_3 ) V_31 ;
V_358 ++ ;
}
F_47 (printk(L_83, freeq_start);)
V_31 = ( V_373 * V_152 -> V_113 ) & 0xffff ;
F_16 ( V_31 , V_152 -> V_279 + V_374 ) ;
F_16 ( V_31 + V_152 -> V_70 * sizeof( T_3 ) , V_152 -> V_279 + V_375 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_292 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_288 ) ;
V_31 = ( V_376 * V_152 -> V_113 ) & 0xffff ;
F_16 ( V_31 , V_152 -> V_279 + V_377 ) ;
F_16 ( V_31 + V_378 * sizeof( V_379 ) ,
V_152 -> V_279 + V_380 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_381 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_382 ) ;
V_152 -> V_275 . V_278 = F_61 ( V_152 -> V_279 + V_370 ) & 0xffff ;
V_152 -> V_275 . V_277 = F_61 ( V_152 -> V_279 + V_371 ) & 0xffff ;
V_152 -> V_275 . V_383 = F_61 ( V_152 -> V_279 + V_372 ) & 0xffff ;
V_152 -> V_275 . V_276 = F_61 ( V_152 -> V_279 + V_280 ) & 0xffff ;
V_152 -> V_275 . V_291 = F_61 ( V_152 -> V_279 + V_374 ) & 0xffff ;
V_152 -> V_275 . V_290 = F_61 ( V_152 -> V_279 + V_375 ) & 0xffff ;
V_152 -> V_275 . V_287 = F_61 ( V_152 -> V_279 + V_292 ) & 0xffff ;
V_152 -> V_275 . V_384 = F_61 ( V_152 -> V_279 + V_288 ) & 0xffff ;
F_47 (printk(L_84,
iadev->rfL.pcq_st, iadev->rfL.pcq_ed, iadev->rfL.pcq_rd,
iadev->rfL.pcq_wr);)
V_31 = V_112 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 3 ) , V_152 -> V_279 + V_385 ) ;
V_354 = ( T_4 * ) ( V_152 -> V_111 + V_31 ) ;
V_355 = V_386 * V_152 -> V_113 ;
for( V_31 = 0 ; V_31 < V_355 ; V_31 ++ )
* V_354 ++ = V_114 ;
V_31 = 8 * 1024 ;
V_356 = 0 ;
while ( V_31 != V_152 -> V_70 ) {
V_31 /= 2 ;
V_356 ++ ;
}
V_31 = V_350 * V_152 -> V_113 ;
F_16 ( ( ( V_31 >> 3 ) & 0xfff8 ) | V_356 , V_152 -> V_279 + V_387 ) ;
V_346 = ( T_4 * ) ( V_152 -> V_111 + V_350 * V_152 -> V_113 ) ;
V_355 = V_388 * V_152 -> V_113 ;
for( V_31 = 0 ; V_31 < V_355 ; V_31 ++ )
{
* V_346 = ( V_31 << 6 ) | 15 ;
V_346 ++ ;
}
V_31 = V_116 * V_152 -> V_113 ;
F_16 ( V_31 >> 3 , V_152 -> V_279 + V_389 ) ;
V_31 = V_116 * V_152 -> V_113 ;
V_353 = (struct V_353 * ) ( V_152 -> V_111 + V_31 ) ;
V_355 = V_386 * V_152 -> V_113 ;
memset ( ( char * ) V_353 , 0 , V_355 * sizeof( * V_353 ) ) ;
for( V_31 = 0 ; V_31 < V_355 ; V_31 ++ ) {
V_353 -> V_87 = 0x0003 ;
V_353 -> V_96 = 0x5eb1 ;
V_353 ++ ;
}
F_16 ( 0xff00 , V_152 -> V_279 + V_390 ) ;
F_16 ( 0 , V_152 -> V_279 + V_391 ) ;
F_16 ( 0x1 , V_152 -> V_279 + V_392 ) ;
F_16 ( 0xF6F8 , V_152 -> V_279 + V_393 ) ;
V_31 = ( V_355 >> 6 ) & 0xFF ;
V_355 += 2 * ( V_355 - 1 ) ;
V_31 |= ( ( V_355 << 2 ) & 0xFF00 ) ;
F_16 ( V_31 , V_152 -> V_279 + V_394 ) ;
for( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ )
V_152 -> V_18 [ V_31 ] . V_19 = 0 ;
F_61 ( V_152 -> V_279 + V_322 ) ;
F_16 ( ~ ( V_327 | V_323 ) , V_152 -> V_279 + V_332 ) ;
F_83 ( & V_152 -> V_307 ) ;
V_152 -> V_395 = NULL ;
V_152 -> V_295 = F_84 ( 4 * V_152 -> V_70 , V_396 ) ;
if ( ! V_152 -> V_295 ) {
F_9 (KERN_ERR DEV_LABEL L_85 ,
dev->number) ;
goto V_397;
}
V_152 -> V_326 = 1 ;
V_152 -> V_329 = 0 ;
F_16 ( V_398 , V_152 -> V_279 + V_362 ) ;
return 0 ;
V_397:
F_85 ( V_152 -> V_311 , V_359 , V_152 -> V_308 . V_318 ,
V_152 -> V_360 ) ;
V_361:
return - V_399 ;
}
static void F_86 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
unsigned short V_62 ;
unsigned long V_158 ;
V_152 = F_31 ( V_9 ) ;
V_62 = F_7 ( V_152 -> V_14 + V_75 ) ;
if ( V_62 & V_72 ) {
F_10 (printk(L_86);)
F_87 ( & V_152 -> V_400 , V_158 ) ;
F_40 ( V_152 ) ;
F_88 ( & V_152 -> V_400 , V_158 ) ;
F_16 ( V_72 , V_152 -> V_14 + V_75 ) ;
if ( V_152 -> V_401 )
F_89 ( & V_152 -> V_402 ) ;
}
if ( V_62 & V_73 )
{
F_10 (printk(L_87);)
}
}
static void F_90 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
struct V_283 * V_283 , * V_334 ;
struct V_32 * V_33 ;
struct V_40 * V_41 ;
struct V_12 * V_20 ;
T_7 V_335 ;
unsigned long V_158 ;
V_152 = F_31 ( V_9 ) ;
F_87 ( & V_152 -> V_400 , V_158 ) ;
V_283 = V_152 -> V_403 . V_336 ;
V_335 = F_7 ( V_152 -> V_319 + V_404 ) &
( sizeof( struct V_283 ) * V_338 - 1 ) ;
V_334 = (struct V_283 * ) ( V_152 -> V_403 . V_318 + ( V_335 >> 4 ) ) ;
while ( V_283 != V_334 )
{
V_33 = F_34 ( & V_152 -> V_405 ) ;
if ( ! V_33 ) break;
if ( ! ( ( V_283 - V_152 -> V_403 . V_318 ) % ( 2 * sizeof( struct V_283 ) ) ) ) {
F_74 ( V_152 -> V_311 , V_283 -> V_310 , V_33 -> V_164 ,
V_406 ) ;
}
V_41 = F_35 ( V_33 ) -> V_41 ;
if ( ! V_41 ) {
F_9 ( L_88 ) ;
F_88 ( & V_152 -> V_400 , V_158 ) ;
F_36 ( V_33 ) ;
return;
}
V_20 = F_29 ( V_41 ) ;
if ( ! V_20 ) {
F_9 ( L_89 ) ;
F_88 ( & V_152 -> V_400 , V_158 ) ;
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
F_11 ( V_33 ) |= V_407 ;
F_70 ( & V_20 -> V_162 , V_33 ) ;
}
F_10 (printk(L_90, skb);)
if ( ++ V_283 == V_152 -> V_403 . V_317 )
V_283 = V_152 -> V_403 . V_318 ;
}
V_152 -> V_403 . V_336 = V_283 ;
F_88 ( & V_152 -> V_400 , V_158 ) ;
}
static int F_91 ( struct V_40 * V_41 )
{
struct V_12 * V_12 ;
T_2 * V_152 ;
struct V_47 * V_408 ;
struct V_50 * V_409 ;
int V_410 ;
F_10 (printk(L_91, vcc->vci);)
if ( V_41 -> V_53 . V_54 . V_55 == V_349 ) return 0 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
if ( V_152 -> V_186 & V_188 ) {
if ( V_41 -> V_53 . V_54 . V_55 == V_56 ) {
F_9 ( L_77 ) ;
return - V_289 ;
}
if ( V_41 -> V_53 . V_54 . V_55 == V_411 ) {
F_9 ( L_92 ) ;
return - V_289 ;
}
}
V_12 = F_29 ( V_41 ) ;
memset ( ( V_98 ) V_12 , 0 , sizeof( * V_12 ) ) ;
if ( V_41 -> V_53 . V_54 . V_412 >
( V_152 -> V_175 - sizeof( struct V_340 ) ) ) {
F_9 ( L_93 ,
V_41 -> V_53 . V_54 . V_412 , V_152 -> V_175 ) ;
V_41 -> V_413 = NULL ;
F_41 ( V_12 ) ;
return - V_289 ;
}
V_12 -> V_21 = 0 ;
V_12 -> V_414 = 1 ;
if ( V_41 -> V_53 . V_54 . V_139 == V_415 )
V_41 -> V_53 . V_54 . V_22 = V_152 -> V_81 ;
else if ( ( V_41 -> V_53 . V_54 . V_139 == 0 ) && ( V_41 -> V_53 . V_54 . V_22 <= 0 ) )
V_41 -> V_53 . V_54 . V_22 = V_152 -> V_81 ;
else if ( ( V_41 -> V_53 . V_54 . V_139 > V_41 -> V_53 . V_54 . V_22 ) && ( V_41 -> V_53 . V_54 . V_139 > 0 ) )
V_41 -> V_53 . V_54 . V_22 = V_41 -> V_53 . V_54 . V_139 ;
if ( V_41 -> V_53 . V_54 . V_22 > V_152 -> V_81 )
V_41 -> V_53 . V_54 . V_22 = V_152 -> V_81 ;
V_12 -> V_22 = V_41 -> V_53 . V_54 . V_22 ;
if ( V_12 -> V_22 > ( V_152 -> V_81 / 6 ) ) V_12 -> V_36 = V_416 / 10 ;
else if ( V_12 -> V_22 > ( V_152 -> V_81 / 130 ) ) V_12 -> V_36 = V_416 ;
else if ( V_12 -> V_22 <= 170 ) V_12 -> V_36 = 16 * V_416 ;
else V_12 -> V_36 = 2700 * V_416 / V_12 -> V_22 ;
if ( V_12 -> V_22 < V_152 -> V_23 )
F_83 ( & V_12 -> V_162 ) ;
if ( V_12 -> V_22 < V_152 -> V_23 ) {
struct V_417 * V_418 = F_92 ( V_41 ) ;
if ( V_41 -> V_53 . V_54 . V_412 != 0 ) {
if ( V_12 -> V_22 > 60000 )
V_418 -> V_419 = V_41 -> V_53 . V_54 . V_412 * 5 ;
else if ( V_12 -> V_22 > 2000 )
V_418 -> V_419 = V_41 -> V_53 . V_54 . V_412 * 4 ;
else
V_418 -> V_419 = V_41 -> V_53 . V_54 . V_412 * 3 ;
}
else
V_418 -> V_419 = 24576 ;
}
V_408 = (struct V_47 * ) V_152 -> V_49 ;
V_409 = (struct V_50 * ) V_152 -> V_52 ;
V_408 += V_41 -> V_58 ;
V_409 += V_41 -> V_58 ;
memset ( ( V_98 ) V_408 , 0 , sizeof( * V_408 ) ) ;
memset ( ( V_98 ) V_409 , 0 , sizeof( * V_409 ) ) ;
V_409 -> V_420 = ( V_41 -> V_58 >> 12 ) & 0x000f ;
V_409 -> V_421 = ( V_41 -> V_58 & 0x0fff ) << 4 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_422 )
{
V_408 -> type = V_423 ;
V_408 -> V_62 = V_424 ;
V_408 -> V_425 = F_18 ( V_152 -> V_81 ) ;
if ( V_41 -> V_53 . V_54 . V_22 > 0 )
V_408 -> V_425 = F_18 ( V_41 -> V_53 . V_54 . V_22 ) ;
F_93 (printk(L_94,
vcc->qos.txtp.max_pcr,vc->acr);)
}
else if ( V_41 -> V_53 . V_54 . V_55 == V_56 )
{ T_9 V_79 ;
F_8 (printk(L_95);)
F_24 ( V_152 , & V_79 ) ;
if ( V_41 -> V_53 . V_54 . V_22 > 0 )
V_79 . V_22 = V_41 -> V_53 . V_54 . V_22 ;
if ( V_41 -> V_53 . V_54 . V_426 > 0 ) {
int V_427 = V_152 -> V_121 + V_152 -> V_428 + V_41 -> V_53 . V_54 . V_426 ;
if ( V_427 > V_152 -> V_81 )
return - V_142 ;
V_79 . V_82 = V_41 -> V_53 . V_54 . V_426 ;
V_152 -> V_121 += V_41 -> V_53 . V_54 . V_426 ;
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
if ( V_41 -> V_53 . V_54 . V_429 )
V_79 . V_88 = V_41 -> V_53 . V_54 . V_88 ;
if ( V_41 -> V_53 . V_54 . V_430 )
V_79 . V_89 = V_41 -> V_53 . V_54 . V_89 ;
if ( V_41 -> V_53 . V_54 . V_431 )
V_79 . V_91 = V_41 -> V_53 . V_54 . V_91 ;
if ( V_41 -> V_53 . V_54 . V_432 )
V_79 . V_90 = V_41 -> V_53 . V_54 . V_90 ;
if ( V_79 . V_83 > V_79 . V_22 )
V_79 . V_83 = V_79 . V_22 ;
F_8 (printk(L_96,
srv_p.pcr, srv_p.mcr);)
F_25 ( V_152 , & V_79 , V_41 , 1 ) ;
} else if ( V_41 -> V_53 . V_54 . V_55 == V_411 ) {
if ( V_152 -> V_186 & V_188 ) {
F_9 ( L_92 ) ;
return - V_289 ;
}
if ( V_41 -> V_53 . V_54 . V_139 > V_152 -> V_81 ) {
F_28 (printk(L_97);)
return - 1 ;
}
V_408 -> type = V_433 ;
V_408 -> V_62 = V_424 ;
if ( ( V_410 = F_27 ( V_152 , V_41 ) ) < 0 ) {
return V_410 ;
}
}
else
F_9 ( L_98 ) ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_59 |= V_119 ;
F_10 (printk(L_99);)
return 0 ;
}
static int F_94 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
struct V_434 * V_282 ;
unsigned int V_435 ;
void * V_352 ;
int V_31 ;
T_3 V_436 ;
T_3 * V_437 ;
T_3 V_438 ;
T_3 * V_439 ;
struct V_47 * V_408 ;
struct V_50 * V_409 ;
T_3 V_440 ;
T_8 V_356 ;
V_152 = F_31 ( V_9 ) ;
F_95 ( & V_152 -> V_400 ) ;
F_47 (printk(L_100,
readw(iadev->seg_reg+SEG_MASK_REG));)
V_352 = F_81 ( V_152 -> V_311 , V_359 ,
& V_152 -> V_441 ) ;
if ( ! V_352 ) {
F_9 (KERN_ERR DEV_LABEL L_79 ) ;
goto V_361;
}
V_152 -> V_403 . V_318 = (struct V_283 * ) V_352 ;
V_152 -> V_403 . V_336 = V_152 -> V_403 . V_318 ;
V_152 -> V_403 . V_309 = V_152 -> V_403 . V_318 ;
V_152 -> V_403 . V_317 = (struct V_283 * ) ( ( unsigned long ) V_352 + sizeof( struct V_283 ) * V_338 ) ;
F_50 ( V_152 -> V_441 & 0xfffff000 ,
V_152 -> V_319 + V_404 ) ;
F_16 ( 0xffff , V_152 -> V_14 + V_74 ) ;
F_16 ( 0 , V_152 -> V_14 + V_68 ) ;
F_16 ( V_442 , V_152 -> V_14 + V_443 ) ;
V_152 -> V_49 = V_152 -> V_17 + V_444 * V_152 -> V_113 ;
V_152 -> V_52 = V_152 -> V_17 + V_445 * V_152 -> V_113 ;
V_152 -> V_69 = V_152 -> V_17 + V_446 * V_152 -> V_113 ;
F_16 ( V_447 , V_152 -> V_14 + V_448 ) ;
V_282 = (struct V_434 * ) ( V_152 -> V_17 + V_447 ) ;
memset ( ( V_98 ) V_282 , 0 , sizeof( * V_282 ) ) ;
V_282 ++ ;
V_435 = V_185 ;
for( V_31 = 1 ; V_31 <= V_152 -> V_39 ; V_31 ++ )
{
memset ( ( V_98 ) V_282 , 0 , sizeof( * V_282 ) ) ;
V_282 -> V_296 = V_449 ;
V_282 -> V_303 = V_435 >> 16 ;
V_282 -> V_304 = V_435 & 0x0000ffff ;
V_282 ++ ;
V_435 += V_152 -> V_175 ;
}
V_152 -> V_450 = F_4 ( V_152 -> V_39 * sizeof( struct V_451 ) , V_396 ) ;
if ( ! V_152 -> V_450 ) {
F_9 (KERN_ERR DEV_LABEL L_101 ) ;
goto V_397;
}
for ( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ )
{
struct V_340 * V_452 ;
V_452 = F_4 ( sizeof( * V_452 ) , V_396 | V_453 ) ;
if( ! V_452 ) {
F_9 (KERN_ERR DEV_LABEL L_102 ) ;
goto V_454;
}
V_152 -> V_450 [ V_31 ] . V_452 = V_452 ;
V_152 -> V_450 [ V_31 ] . V_286 = F_71 ( V_152 -> V_311 ,
V_452 , sizeof( * V_452 ) , V_406 ) ;
}
V_152 -> V_18 = F_4 ( V_152 -> V_39 *
sizeof( struct V_5 ) , V_396 ) ;
if ( ! V_152 -> V_18 ) {
F_9 (KERN_ERR DEV_LABEL L_101 ) ;
goto V_455;
}
V_31 = V_456 * V_152 -> V_113 ;
F_16 ( V_31 >> 16 , V_152 -> V_14 + V_457 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_271 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_458 ) ;
F_16 ( V_31 + V_152 -> V_39 * sizeof( T_3 ) , V_152 -> V_14 + V_15 ) ;
V_152 -> V_16 = V_31 + V_152 -> V_39 * sizeof( T_3 ) ;
F_16 ( V_31 + 2 * V_152 -> V_39 * sizeof( T_3 ) ,
V_152 -> V_14 + V_272 ) ;
V_436 = F_61 ( V_152 -> V_14 + V_271 ) ;
V_437 = ( T_3 * ) ( V_152 -> V_17 + V_436 ) ;
for( V_31 = 1 ; V_31 <= V_152 -> V_39 ; V_31 ++ )
{
* V_437 = ( T_3 ) V_31 ;
V_437 ++ ;
}
V_31 = V_459 * V_152 -> V_113 ;
F_16 ( V_31 , V_152 -> V_14 + V_460 ) ;
F_16 ( V_31 + 2 * V_152 -> V_39 * sizeof( T_3 ) ,
V_152 -> V_14 + V_461 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_462 ) ;
F_16 ( V_31 , V_152 -> V_14 + V_463 ) ;
V_152 -> V_27 . V_464 = F_61 ( V_152 -> V_14 + V_460 ) & 0xffff ;
V_152 -> V_27 . V_465 = F_61 ( V_152 -> V_14 + V_461 ) & 0xffff ;
V_152 -> V_27 . V_466 = F_61 ( V_152 -> V_14 + V_463 ) & 0xffff ;
V_152 -> V_27 . V_29 = F_61 ( V_152 -> V_14 + V_271 ) & 0xffff ;
V_152 -> V_27 . V_28 = F_61 ( V_152 -> V_14 + V_272 ) & 0xffff ;
V_152 -> V_27 . V_38 = F_61 ( V_152 -> V_14 + V_458 ) & 0xffff ;
V_438 = F_61 ( V_152 -> V_14 + V_460 ) ;
V_439 = ( T_3 * ) ( V_152 -> V_17 + V_438 ) ;
for( V_31 = 1 ; V_31 <= V_152 -> V_39 ; V_31 ++ )
{
* V_439 = ( T_3 ) 0 ;
V_439 ++ ;
}
F_47 (printk(L_103);)
#if 1
F_16 ( 0 , V_152 -> V_14 + V_467 ) ;
#else
V_440 = ( V_152 -> V_17 + V_146 * V_152 -> V_113 ) >> 17 ;
F_47 (printk(L_104, tmp16);)
F_16 ( V_440 , V_152 -> V_14 + V_467 ) ;
#endif
F_47 (printk(L_105,
readw(iadev->seg_reg+CBR_PTR_BASE));)
V_440 = ( V_146 * V_152 -> V_113 ) >> 1 ;
F_16 ( V_440 , V_152 -> V_14 + V_468 ) ;
F_47 (printk(L_106, tmp16,
readw(iadev->seg_reg+CBR_TAB_BEG));)
F_16 ( V_440 , V_152 -> V_14 + V_469 + 1 ) ;
V_440 = ( V_146 * V_152 -> V_113 + V_152 -> V_70 * 6 - 2 ) >> 1 ;
F_16 ( V_440 , V_152 -> V_14 + V_469 ) ;
F_47 (printk(L_107,
iadev->seg_reg, readw(iadev->seg_reg+CBR_PTR_BASE));)
F_47 (printk(L_108,
readw(iadev->seg_reg+CBR_TAB_BEG), readw(iadev->seg_reg+CBR_TAB_END),
readw(iadev->seg_reg+CBR_TAB_END+1));)
F_82 ( V_152 -> V_17 + V_146 * V_152 -> V_113 ,
0 , V_152 -> V_70 * 6 ) ;
V_152 -> V_141 = V_152 -> V_144 = V_152 -> V_70 * 3 ;
V_152 -> V_145 = 0 ;
V_152 -> V_140 = V_470 / V_152 -> V_144 ;
V_152 -> V_147 = 0 ;
V_356 = 0 ;
V_31 = 8 * 1024 ;
while ( V_31 != V_152 -> V_70 ) {
V_31 /= 2 ;
V_356 ++ ;
}
V_31 = V_444 * V_152 -> V_113 ;
F_16 ( V_356 | ( ( V_31 >> 8 ) & 0xfff8 ) , V_152 -> V_14 + V_471 ) ;
V_31 = V_445 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 8 ) & 0xfffe , V_152 -> V_14 + V_472 ) ;
V_31 = V_473 * V_152 -> V_113 ;
F_16 ( ( V_31 & 0xffff ) >> 11 , V_152 -> V_14 + V_474 ) ;
V_31 = V_475 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 7 ) & 0xffff , V_152 -> V_14 + V_476 ) ;
memset ( ( V_98 ) ( V_152 -> V_17 + V_473 * V_152 -> V_113 ) ,
0 , V_152 -> V_70 * 8 ) ;
V_31 = V_446 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 11 ) & 0xffff , V_152 -> V_14 + V_477 ) ;
V_31 = V_478 * V_152 -> V_113 ;
F_16 ( ( V_31 >> 7 ) & 0xffff , V_152 -> V_14 + V_479 ) ;
V_31 = V_446 * V_152 -> V_113 ;
memset ( ( V_98 ) ( V_152 -> V_17 + V_31 ) , 0 , V_152 -> V_70 * 4 ) ;
V_408 = (struct V_47 * ) V_152 -> V_49 ;
V_409 = (struct V_50 * ) V_152 -> V_52 ;
V_152 -> V_57 = F_4 ( sizeof( long ) * V_152 -> V_70 , V_396 ) ;
if ( ! V_152 -> V_57 ) {
F_9 ( L_109 ) ;
goto V_480;
}
for( V_31 = 0 ; V_31 < V_152 -> V_70 ; V_31 ++ )
{
memset ( ( V_98 ) V_408 , 0 , sizeof( * V_408 ) ) ;
memset ( ( V_98 ) V_409 , 0 , sizeof( * V_409 ) ) ;
V_152 -> V_57 [ V_31 ] = F_4 ( sizeof( struct V_481 ) ,
V_396 ) ;
if ( ! V_152 -> V_57 [ V_31 ] )
goto V_482;
V_152 -> V_57 [ V_31 ] -> V_66 = 0 ;
V_152 -> V_57 [ V_31 ] -> V_67 = 0 ;
V_152 -> V_57 [ V_31 ] -> V_59 = V_483 ;
V_408 ++ ;
V_409 ++ ;
}
if ( V_152 -> V_186 & V_188 ) {
F_16 ( V_484 , V_152 -> V_14 + V_485 ) ;
F_16 ( ( V_149 | ( 0x23 << 2 ) ) , V_152 -> V_14 + V_151 ) ;
}
else {
F_16 ( F_18 ( V_152 -> V_81 ) , V_152 -> V_14 + V_485 ) ;
F_16 ( ( V_149 | V_150 | ( 0x23 << 2 ) ) , V_152 -> V_14 + V_151 ) ;
}
F_16 ( 0 , V_152 -> V_14 + V_486 ) ;
F_16 ( 0 , V_152 -> V_14 + V_487 ) ;
F_16 ( 0xaa00 , V_152 -> V_14 + V_488 ) ;
V_152 -> V_401 = 0 ;
F_96 ( & V_152 -> V_402 ) ;
F_96 ( & V_152 -> V_489 ) ;
F_83 ( & V_152 -> V_405 ) ;
F_1 ( & V_152 -> V_26 ) ;
F_16 ( V_490 , V_152 -> V_14 + V_491 ) ;
F_83 ( & V_152 -> V_156 ) ;
F_16 ( V_492 , V_152 -> V_14 + V_493 ) ;
F_16 ( V_71 , V_152 -> V_14 + V_68 ) ;
F_61 ( V_152 -> V_14 + V_75 ) ;
F_16 ( ~ ( V_72 | V_73 ) , V_152 -> V_14 + V_74 ) ;
F_16 ( V_72 , V_152 -> V_14 + V_75 ) ;
V_152 -> V_494 = 0 ;
V_152 -> V_23 = V_152 -> V_81 / 3 ;
return 0 ;
V_482:
while ( -- V_31 >= 0 )
F_41 ( V_152 -> V_57 [ V_31 ] ) ;
F_41 ( V_152 -> V_57 ) ;
V_480:
F_41 ( V_152 -> V_18 ) ;
V_455:
V_31 = V_152 -> V_39 ;
V_454:
while ( -- V_31 >= 0 ) {
struct V_451 * V_274 = V_152 -> V_450 + V_31 ;
F_74 ( V_152 -> V_311 , V_274 -> V_286 ,
sizeof( * V_274 -> V_452 ) , V_406 ) ;
F_41 ( V_274 -> V_452 ) ;
}
F_41 ( V_152 -> V_450 ) ;
V_397:
F_85 ( V_152 -> V_311 , V_359 , V_152 -> V_403 . V_318 ,
V_152 -> V_441 ) ;
V_361:
return - V_399 ;
}
static T_14 F_97 ( int V_495 , void * V_496 )
{
struct V_273 * V_9 ;
T_2 * V_152 ;
unsigned int V_62 ;
int V_497 = 0 ;
V_9 = V_496 ;
V_152 = F_31 ( V_9 ) ;
while( ( V_62 = F_7 ( V_152 -> V_194 + V_498 ) & 0x7f ) )
{
V_497 = 1 ;
F_10 (printk(L_110, status);)
if ( V_62 & V_499 )
{
F_10 (printk(L_111, status);)
F_72 ( V_9 ) ;
}
if ( V_62 & V_500 )
{
F_50 ( V_500 , V_152 -> V_194 + V_498 ) ;
F_73 ( V_9 ) ;
}
if ( V_62 & V_501 )
{
F_10 (printk(L_112);)
F_86 ( V_9 ) ;
}
if ( V_62 & V_502 )
{
F_50 ( V_502 , V_152 -> V_194 + V_498 ) ;
F_90 ( V_9 ) ;
}
if ( V_62 & ( V_503 | V_504 | V_505 ) )
{
if ( V_62 & V_503 )
F_51 ( V_152 ) ;
}
}
return F_98 ( V_497 ) ;
}
static int F_99 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
int V_31 ;
T_8 V_506 ;
T_4 V_507 ;
V_152 = F_31 ( V_9 ) ;
V_506 = F_100 ( F_101 ( F_7 (
V_152 -> V_194 + V_508 ) ) ) ;
V_507 = F_102 ( F_103 ( F_7 ( V_152 -> V_194 + V_509 ) ) ) ;
F_47 (printk(L_113, mac1, mac2);)
for ( V_31 = 0 ; V_31 < V_510 ; V_31 ++ )
V_9 -> V_511 [ V_31 ] = V_506 >> ( 8 * ( V_510 - 1 - V_31 ) ) ;
for ( V_31 = 0 ; V_31 < V_512 ; V_31 ++ )
V_9 -> V_511 [ V_31 + V_510 ] = V_507 >> ( 8 * ( V_512 - 1 - V_31 ) ) ;
return 0 ;
}
static int F_104 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
int V_31 , error = 1 ;
unsigned int V_311 [ 64 ] ;
V_152 = F_31 ( V_9 ) ;
for( V_31 = 0 ; V_31 < 64 ; V_31 ++ )
if ( ( error = F_105 ( V_152 -> V_311 ,
V_31 * 4 , & V_311 [ V_31 ] ) ) != V_513 )
return error ;
F_50 ( 0 , V_152 -> V_194 + V_514 ) ;
for( V_31 = 0 ; V_31 < 64 ; V_31 ++ )
if ( ( error = F_106 ( V_152 -> V_311 ,
V_31 * 4 , V_311 [ V_31 ] ) ) != V_513 )
return error ;
F_15 ( 5 ) ;
return 0 ;
}
static int T_15 F_107 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
unsigned long V_515 ;
void T_13 * V_516 ;
unsigned short V_517 ;
int error , V_31 ;
F_47 (printk(L_114);)
V_9 -> V_518 . V_519 = 0 ;
V_9 -> V_518 . V_520 = V_521 ;
V_152 = F_31 ( V_9 ) ;
V_515 = F_108 ( V_152 -> V_311 , 0 ) ;
V_152 -> V_495 = V_152 -> V_311 -> V_495 ;
error = F_109 ( V_152 -> V_311 , V_522 , & V_517 ) ;
if ( error ) {
F_9 (KERN_ERR DEV_LABEL L_115 ,
dev->number,error) ;
return - V_289 ;
}
F_47 (printk(DEV_LABEL L_116,
dev->number, iadev->pci->revision, real_base, iadev->irq);)
V_152 -> V_523 = F_110 ( V_152 -> V_311 , 0 ) ;
if ( V_152 -> V_523 == 0x100000 ) {
V_152 -> V_70 = 4096 ;
V_9 -> V_518 . V_520 = V_524 ;
V_152 -> V_113 = 4 ;
}
else if ( V_152 -> V_523 == 0x40000 ) {
V_152 -> V_70 = 1024 ;
V_152 -> V_113 = 1 ;
}
else {
F_9 ( L_117 , V_152 -> V_523 ) ;
return - V_289 ;
}
F_47 (printk (DEV_LABEL L_118, iadev->pci_map_size);)
F_111 ( V_152 -> V_311 ) ;
F_15 ( 10 ) ;
V_516 = F_112 ( V_515 , V_152 -> V_523 ) ;
if ( ! V_516 )
{
F_9 ( V_525 L_119 ,
V_9 -> V_526 ) ;
return - V_399 ;
}
F_47 (printk(DEV_LABEL L_120,
dev->number, iadev->pci->revision, base, iadev->irq);)
V_152 -> V_527 = V_152 -> V_523 / 2 ;
V_152 -> V_515 = V_515 ;
V_152 -> V_516 = V_516 ;
V_152 -> V_194 = V_516 + V_528 ;
V_152 -> V_14 = V_516 + V_529 ;
V_152 -> V_279 = V_516 + V_530 ;
V_152 -> V_195 = V_516 + V_531 ;
V_152 -> V_319 = V_516 + V_531 ;
V_152 -> V_532 = V_516 + V_533 ;
V_152 -> V_17 = V_516 + V_534 ;
V_152 -> V_111 = V_516 + V_535 ;
F_47 (printk(L_121,
iadev->reg,iadev->seg_reg,iadev->reass_reg,
iadev->phy, iadev->ram, iadev->seg_ram,
iadev->reass_ram);)
error = F_99 ( V_9 ) ;
if ( error ) {
F_113 ( V_152 -> V_516 ) ;
return error ;
}
F_9 ( L_122 ) ;
for ( V_31 = 0 ; V_31 < V_536 ; V_31 ++ )
F_9 ( L_123 , V_31 ? L_124 : L_125 , V_9 -> V_511 [ V_31 ] ) ;
F_9 ( L_74 ) ;
if ( F_104 ( V_9 ) ) {
F_113 ( V_152 -> V_516 ) ;
F_9 ( L_126 ) ;
return 1 ;
}
return 0 ;
}
static void F_114 ( T_2 * V_152 ) {
if ( ! V_152 -> V_197 )
return;
V_152 -> V_537 += F_61 ( V_152 -> V_279 + V_538 ) & 0xffff ;
V_152 -> V_537 += ( F_61 ( V_152 -> V_279 + V_539 ) & 0xffff ) << 16 ;
V_152 -> V_540 += F_61 ( V_152 -> V_279 + V_541 ) & 0xffff ;
V_152 -> V_542 += F_61 ( V_152 -> V_279 + V_543 ) & 0xffff ;
V_152 -> V_544 += F_61 ( V_152 -> V_14 + V_545 ) & 0xffff ;
V_152 -> V_544 += ( F_61 ( V_152 -> V_14 + V_546 ) & 0xffff ) << 16 ;
return;
}
static void F_115 ( unsigned long V_547 ) {
unsigned long V_158 ;
static T_5 V_548 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_5 V_31 ;
static T_8 V_549 ;
for ( V_31 = 0 ; V_31 < V_550 ; V_31 ++ ) {
if ( V_551 [ V_31 ] ) {
V_549 = F_7 ( V_551 [ V_31 ] -> V_194 + V_552 ) ;
if ( V_548 [ V_31 ] == 0 ) {
V_548 [ V_31 ] ++ ;
V_549 &= ( ~ V_553 ) ;
F_50 ( V_549 , V_551 [ V_31 ] -> V_194 + V_552 ) ;
F_114 ( V_551 [ V_31 ] ) ;
}
else {
V_548 [ V_31 ] = 0 ;
V_549 |= V_553 ;
F_50 ( V_549 , V_551 [ V_31 ] -> V_194 + V_552 ) ;
F_87 ( & V_551 [ V_31 ] -> V_400 , V_158 ) ;
if ( V_551 [ V_31 ] -> V_401 )
F_89 ( & V_551 [ V_31 ] -> V_402 ) ;
F_40 ( V_551 [ V_31 ] ) ;
F_88 ( & V_551 [ V_31 ] -> V_400 , V_158 ) ;
}
}
}
F_116 ( & V_554 , V_37 + V_416 / 4 ) ;
return;
}
static void F_117 ( struct V_273 * V_9 , unsigned char V_555 ,
unsigned long V_165 )
{
F_50 ( V_555 , F_31 ( V_9 ) -> V_195 + V_165 ) ;
}
static unsigned char F_118 ( struct V_273 * V_9 , unsigned long V_165 )
{
return F_7 ( F_31 ( V_9 ) -> V_195 + V_165 ) ;
}
static void F_119 ( T_2 * V_152 )
{
int V_31 ;
F_41 ( V_152 -> V_18 ) ;
for ( V_31 = 0 ; V_31 < V_152 -> V_70 ; V_31 ++ )
F_41 ( V_152 -> V_57 [ V_31 ] ) ;
F_41 ( V_152 -> V_57 ) ;
for ( V_31 = 0 ; V_31 < V_152 -> V_39 ; V_31 ++ ) {
struct V_451 * V_274 = V_152 -> V_450 + V_31 ;
F_74 ( V_152 -> V_311 , V_274 -> V_286 ,
sizeof( * V_274 -> V_452 ) , V_406 ) ;
F_41 ( V_274 -> V_452 ) ;
}
F_41 ( V_152 -> V_450 ) ;
F_85 ( V_152 -> V_311 , V_359 , V_152 -> V_403 . V_318 ,
V_152 -> V_441 ) ;
}
static void F_120 ( T_2 * V_152 )
{
F_41 ( V_152 -> V_295 ) ;
F_85 ( V_152 -> V_311 , V_359 , V_152 -> V_308 . V_318 ,
V_152 -> V_360 ) ;
}
static int T_15 F_121 ( struct V_273 * V_9 )
{
T_2 * V_152 ;
int error ;
unsigned char V_195 ;
T_8 V_549 ;
F_10 (printk(L_127);)
V_152 = F_31 ( V_9 ) ;
if ( F_122 ( V_152 -> V_495 , & F_97 , V_556 , V_525 , V_9 ) ) {
F_9 (KERN_ERR DEV_LABEL L_128 ,
dev->number, iadev->irq) ;
error = - V_557 ;
goto V_361;
}
if ( ( error = F_123 ( V_152 -> V_311 ,
V_522 ,
V_558 | V_559 ) ) )
{
F_9 (KERN_ERR DEV_LABEL L_129
L_130 ,dev->number, error) ;
error = - V_560 ;
goto V_561;
}
F_15 ( 10 ) ;
F_47 (printk(L_131,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));)
V_549 = F_7 ( V_152 -> V_194 + V_552 ) ;
V_549 = ( V_549 & ( V_553 | V_562 ) )
| V_563
| V_564
| V_565
| V_566
| V_567
| V_568
| V_569
| V_570
| V_571
| V_572
| V_573
| V_574
| V_575 ;
F_50 ( V_549 , V_152 -> V_194 + V_552 ) ;
F_47 (printk(L_132,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));
printk(L_133,
readl(iadev->reg+IPHASE5575_BUS_STATUS_REG));)
F_46 ( V_152 ) ;
error = F_94 ( V_9 ) ;
if ( error )
goto V_561;
error = F_80 ( V_9 ) ;
if ( error )
goto V_576;
V_549 = F_7 ( V_152 -> V_194 + V_552 ) ;
F_50 ( V_549 | V_562 , V_152 -> V_194 + V_552 ) ;
F_47 (printk(L_132,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));)
V_195 = 0 ;
F_47 (
if ((phy=ia_phy_get(dev,0)) == 0x30)
printk(L_134,phy&0x0f);
else
printk(L_135,phy);)
if ( V_152 -> V_186 & V_188 )
F_52 ( V_152 ) ;
else if ( V_152 -> V_186 & ( V_189 | V_190 ) )
F_57 ( V_152 ) ;
else {
error = V_229 ( V_9 ) ;
if ( error )
goto V_577;
if ( V_9 -> V_195 -> V_318 ) {
error = V_9 -> V_195 -> V_318 ( V_9 ) ;
if ( error )
goto V_577;
}
F_51 ( V_152 ) ;
}
return 0 ;
V_577:
F_120 ( V_152 ) ;
V_576:
F_119 ( V_152 ) ;
V_561:
F_124 ( V_152 -> V_495 , V_9 ) ;
V_361:
return error ;
}
static void F_125 ( struct V_40 * V_41 )
{
F_126 ( V_578 ) ;
T_4 * V_346 ;
T_2 * V_152 ;
struct V_12 * V_12 ;
struct V_32 * V_33 = NULL ;
struct V_579 V_580 , V_581 ;
unsigned long V_582 , V_158 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
V_12 = F_29 ( V_41 ) ;
if ( ! V_12 ) return;
F_10 (printk(L_136,
ia_vcc->vc_desc_cnt,vcc->vci);)
F_127 ( V_157 , & V_41 -> V_158 ) ;
F_83 ( & V_580 ) ;
F_83 ( & V_581 ) ;
if ( V_41 -> V_53 . V_54 . V_55 != V_349 ) {
V_152 -> V_401 ++ ;
F_128 ( & V_152 -> V_489 , & V_578 , V_583 ) ;
F_129 ( 50 ) ;
F_130 ( & V_152 -> V_489 , & V_578 ) ;
F_87 ( & V_152 -> V_400 , V_158 ) ;
while( ( V_33 = F_34 ( & V_152 -> V_156 ) ) ) {
if ( F_35 ( V_33 ) -> V_41 == V_41 ) {
if ( V_41 -> V_163 ) V_41 -> V_163 ( V_41 , V_33 ) ;
else F_36 ( V_33 ) ;
}
else
F_70 ( & V_580 , V_33 ) ;
}
while( ( V_33 = F_34 ( & V_580 ) ) )
F_70 ( & V_152 -> V_156 , V_33 ) ;
F_10 (printk(L_137, ia_vcc->vc_desc_cnt);)
V_582 = 300000 / V_12 -> V_22 ;
if ( V_582 == 0 )
V_582 = 1 ;
F_88 ( & V_152 -> V_400 , V_158 ) ;
F_131 ( V_152 -> V_402 , ( V_12 -> V_21 <= 0 ) , V_582 ) ;
F_87 ( & V_152 -> V_400 , V_158 ) ;
V_152 -> V_401 -- ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_66 = 0 ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_67 = 0 ;
V_152 -> V_57 [ V_41 -> V_58 ] -> V_59 = V_483 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_56 ) {
if ( V_41 -> V_53 . V_54 . V_426 > 0 )
V_152 -> V_121 -= V_41 -> V_53 . V_54 . V_426 ;
}
if ( V_41 -> V_53 . V_54 . V_55 == V_411 ) {
V_12 = F_29 ( V_41 ) ;
V_152 -> V_121 -= V_12 -> V_143 * V_152 -> V_140 ;
F_30 ( V_41 ) ;
}
F_88 ( & V_152 -> V_400 , V_158 ) ;
}
if ( V_41 -> V_53 . V_348 . V_55 != V_349 ) {
V_346 = ( T_4 * ) ( V_152 -> V_111 + V_112 * V_152 -> V_113 ) ;
V_346 += V_41 -> V_58 ;
* V_346 = V_114 ;
V_346 = ( T_4 * ) ( V_152 -> V_111 + V_350 * V_152 -> V_113 ) ;
V_346 += V_41 -> V_58 ;
* V_346 = ( V_41 -> V_58 << 6 ) | 15 ;
if ( V_41 -> V_53 . V_348 . V_55 == V_56 ) {
struct V_353 T_13 * V_353 =
( V_152 -> V_111 + V_116 * V_152 -> V_113 ) ;
V_353 += V_41 -> V_58 ;
V_353 -> V_87 = 0x0003 ;
V_353 -> V_96 = 0x5eb1 ;
}
F_73 ( V_41 -> V_9 ) ;
V_152 -> V_295 [ V_41 -> V_58 ] = NULL ;
}
F_41 ( F_29 ( V_41 ) ) ;
V_12 = NULL ;
V_41 -> V_413 = NULL ;
F_127 ( V_584 , & V_41 -> V_158 ) ;
return;
}
static int F_132 ( struct V_40 * V_41 )
{
struct V_12 * V_12 ;
int error ;
if ( ! F_37 ( V_585 , & V_41 -> V_158 ) )
{
F_10 (printk(L_138);)
V_41 -> V_413 = NULL ;
}
if ( V_41 -> V_58 != V_586 && V_41 -> V_587 != V_588 )
{
F_10 (printk(L_139);)
F_133 ( V_584 , & V_41 -> V_158 ) ;
}
if ( V_41 -> V_53 . V_589 != V_590 )
return - V_289 ;
F_10 (printk(DEV_LABEL L_140,
vcc->dev->number, vcc->vpi, vcc->vci);)
V_12 = F_4 ( sizeof( * V_12 ) , V_396 ) ;
if ( ! V_12 ) return - V_399 ;
V_41 -> V_413 = V_12 ;
if ( ( error = F_79 ( V_41 ) ) )
{
F_10 (printk(L_141);)
F_125 ( V_41 ) ;
return error ;
}
if ( ( error = F_91 ( V_41 ) ) )
{
F_10 (printk(L_142);)
F_125 ( V_41 ) ;
return error ;
}
F_133 ( V_157 , & V_41 -> V_158 ) ;
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
F_10 (printk(L_143);)
return 0 ;
}
static int F_134 ( struct V_40 * V_41 , struct V_591 * V_53 , int V_158 )
{
F_10 (printk(L_144);)
return 0 ;
}
static int F_135 ( struct V_273 * V_9 , unsigned int V_592 , void T_16 * V_547 )
{
T_17 V_593 ;
T_2 * V_152 ;
int V_31 , V_594 ;
T_4 T_16 * V_595 ;
F_10 (printk(L_145);)
if ( V_592 != V_596 ) {
if ( ! V_9 -> V_195 -> V_597 ) return - V_289 ;
return V_9 -> V_195 -> V_597 ( V_9 , V_592 , V_547 ) ;
}
if ( F_136 ( & V_593 , V_547 , sizeof V_593 ) ) return - V_598 ;
V_594 = V_593 . V_62 ;
if ( ( V_594 < 0 ) || ( V_594 > V_550 ) )
V_594 = 0 ;
V_152 = V_551 [ V_594 ] ;
switch ( V_593 . V_592 ) {
case V_599 :
{
switch ( V_593 . V_600 ) {
case V_601 :
if ( ! F_137 ( V_602 ) ) return - V_603 ;
if ( F_138 ( V_593 . V_604 , V_152 , sizeof( T_2 ) ) )
return - V_598 ;
V_593 . V_62 = 0 ;
break;
case V_605 :
if ( ! F_137 ( V_602 ) ) return - V_603 ;
V_595 = ( T_4 T_16 * ) V_593 . V_604 ;
for( V_31 = 0 ; V_31 < 0x80 ; V_31 += 2 , V_595 ++ )
if( F_139 ( ( T_4 ) ( F_7 ( V_152 -> V_14 + V_31 ) & 0xffff ) , V_595 ) ) return - V_598 ;
V_593 . V_62 = 0 ;
V_593 . V_164 = 0x80 ;
break;
case V_606 :
if ( ! F_137 ( V_602 ) ) return - V_603 ;
V_595 = ( T_4 T_16 * ) V_593 . V_604 ;
for( V_31 = 0 ; V_31 < 0x80 ; V_31 += 2 , V_595 ++ )
if( F_139 ( ( T_4 ) ( F_7 ( V_152 -> V_279 + V_31 ) & 0xffff ) , V_595 ) ) return - V_598 ;
V_593 . V_62 = 0 ;
V_593 . V_164 = 0x80 ;
break;
case V_607 :
{
T_18 * V_608 ;
T_19 * V_27 ;
T_20 * V_275 ;
if ( ! F_137 ( V_602 ) ) return - V_603 ;
V_608 = F_4 ( sizeof( * V_608 ) , V_396 ) ;
if ( ! V_608 ) return - V_399 ;
V_27 = & V_608 -> V_609 ;
V_275 = & V_608 -> V_610 ;
for ( V_31 = 0 ; V_31 < ( sizeof ( T_20 ) ) / 4 ; V_31 ++ )
( ( T_7 * ) V_275 ) [ V_31 ] = F_7 ( V_152 -> V_279 + V_31 ) & 0xffff ;
for ( V_31 = 0 ; V_31 < ( sizeof ( T_19 ) ) / 4 ; V_31 ++ )
( ( T_7 * ) V_27 ) [ V_31 ] = F_7 ( V_152 -> V_14 + V_31 ) & 0xffff ;
if ( F_138 ( V_593 . V_604 , V_608 , sizeof( T_18 ) ) ) {
F_41 ( V_608 ) ;
return - V_598 ;
}
F_41 ( V_608 ) ;
F_9 ( L_146 , V_594 ) ;
V_593 . V_62 = 0 ;
}
break;
case V_611 :
{
if ( ! F_137 ( V_602 ) ) return - V_603 ;
F_60 ( V_152 ) ;
V_593 . V_62 = 0 ;
}
break;
case 0x6 :
{
V_593 . V_62 = 0 ;
F_9 ( L_147 , ( long ) F_140 ( & V_152 -> V_156 ) ) ;
F_9 ( L_148 , ( long ) F_5 ( & V_152 -> V_26 ) ) ;
}
break;
case 0x8 :
{
struct V_612 * V_300 ;
V_300 = & F_141 ( V_613 [ V_594 ] ) -> V_614 ;
F_9 ( L_149 , F_142 ( & V_300 -> V_615 ) ) ;
F_9 ( L_150 , F_142 ( & V_300 -> V_616 ) ) ;
F_9 ( L_151 , F_142 ( & V_300 -> V_617 ) ) ;
F_9 ( L_152 , F_142 ( & V_300 -> V_618 ) ) ;
F_9 ( L_153 , F_142 ( & V_300 -> V_619 ) ) ;
F_9 ( L_154 , F_142 ( & V_300 -> V_620 ) ) ;
F_9 ( L_155 , F_142 ( & V_300 -> V_621 ) ) ;
F_9 ( L_156 , F_142 ( & V_300 -> V_622 ) ) ;
F_9 ( L_157 , F_142 ( & V_300 -> V_623 ) ) ;
}
V_593 . V_62 = 0 ;
break;
case 0x9 :
if ( ! F_137 ( V_602 ) ) return - V_603 ;
for ( V_31 = 1 ; V_31 <= V_152 -> V_177 ; V_31 ++ )
F_63 ( V_613 [ V_594 ] , V_31 ) ;
F_16 ( ~ ( V_327 | V_331 ) ,
V_152 -> V_279 + V_332 ) ;
V_152 -> V_326 = 1 ;
V_593 . V_62 = 0 ;
break;
case 0xb :
if ( ! F_137 ( V_602 ) ) return - V_603 ;
F_51 ( V_152 ) ;
break;
case 0xa :
if ( ! F_137 ( V_602 ) ) return - V_603 ;
{
V_593 . V_62 = 0 ;
V_624 = V_593 . V_625 ;
F_9 ( L_158 ) ;
}
break;
default:
V_593 . V_62 = 0 ;
break;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_143 ( struct V_40 * V_41 , int V_626 , int V_627 ,
void T_16 * V_628 , int V_629 )
{
F_10 (printk(L_159);)
return - V_289 ;
}
static int F_144 ( struct V_40 * V_41 , int V_626 , int V_627 ,
void T_16 * V_628 , unsigned int V_629 )
{
F_10 (printk(L_160);)
return - V_289 ;
}
static int F_38 ( struct V_40 * V_41 , struct V_32 * V_33 ) {
T_2 * V_152 ;
struct V_283 * V_284 ;
struct V_434 T_13 * V_282 ;
int V_274 ;
int V_630 ;
int V_631 ;
struct V_340 * V_341 ;
struct V_12 * V_20 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
V_20 = F_29 ( V_41 ) ;
if ( ! V_20 -> V_414 ) {
F_9 ( L_161 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
if ( V_33 -> V_164 > V_152 -> V_175 - 8 ) {
F_9 ( L_162 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
if ( ( unsigned long ) V_33 -> V_4 & 3 ) {
F_9 ( L_163 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
V_274 = F_12 ( V_152 , V_20 ) ;
if ( V_274 == 0xffff )
return 1 ;
V_630 = V_274 >> 13 ;
V_274 &= 0x1fff ;
if ( ( V_274 == 0 ) || ( V_274 > V_152 -> V_39 ) )
{
F_17 (printk(DEV_LABEL L_164, desc);)
F_66 ( & V_41 -> V_300 -> V_632 ) ;
if ( V_41 -> V_163 )
V_41 -> V_163 ( V_41 , V_33 ) ;
else
F_36 ( V_33 ) ;
return 0 ;
}
if ( V_630 )
{
F_17 (printk(DEV_LABEL L_165,
desc, comp_code);)
}
V_20 -> V_21 ++ ;
V_152 -> V_18 [ V_274 - 1 ] . V_20 = V_20 ;
V_152 -> V_18 [ V_274 - 1 ] . V_24 = V_33 ;
F_11 ( V_33 ) = 0 ;
V_152 -> V_27 . V_38 += 2 ;
if ( V_152 -> V_27 . V_38 > V_152 -> V_27 . V_28 )
V_152 -> V_27 . V_38 = V_152 -> V_27 . V_29 ;
F_16 ( V_152 -> V_27 . V_38 , V_152 -> V_14 + V_458 ) ;
* ( T_4 * ) ( V_152 -> V_17 + V_152 -> V_27 . V_466 ) = V_274 ;
V_152 -> V_27 . V_466 += 2 ;
if ( V_152 -> V_27 . V_466 > V_152 -> V_27 . V_465 )
V_152 -> V_27 . V_466 = V_152 -> V_27 . V_464 ;
V_631 = V_33 -> V_164 + sizeof( struct V_340 ) ;
V_631 = ( ( V_631 + 47 ) / 48 ) * 48 ;
F_145 (printk(L_166, total_len, total_len - skb->len);)
V_341 = V_152 -> V_450 [ V_274 - 1 ] . V_452 ;
F_145 (printk(L_167,
skb, skb->data, skb->len, desc);)
V_341 -> V_633 = 0 ;
V_341 -> V_262 = ( ( V_33 -> V_164 & 0xff ) << 8 ) | ( ( V_33 -> V_164 & 0xff00 ) >> 8 ) ;
V_341 -> V_634 = 0 ;
F_146 (printk(L_168,
skb->len, tcnter++);
xdump(skb->data, skb->len, L_169);
printk(L_74);)
V_282 = V_152 -> V_17 + V_447 ;
V_282 += V_274 ;
V_282 -> V_296 = V_449 | V_635 | V_636 | V_637 ;
F_16 ( V_72 , V_152 -> V_14 + V_75 ) ;
V_282 -> V_294 = V_41 -> V_58 ;
V_282 -> V_314 = V_631 ;
if ( V_41 -> V_53 . V_54 . V_55 == V_56 )
F_14 ( V_41 , V_152 ) ;
V_284 = V_152 -> V_403 . V_309 ;
memset ( ( V_98 ) V_284 , 0 , sizeof( * V_284 ) ) ;
V_284 -> V_310 = F_71 ( V_152 -> V_311 , V_33 -> V_4 ,
V_33 -> V_164 , V_406 ) ;
V_284 -> V_313 = ( V_282 -> V_303 << 16 ) |
V_282 -> V_304 ;
V_284 -> V_314 = V_33 -> V_164 ;
if ( ( V_284 -> V_314 >> 2 ) == 0xb )
V_284 -> V_314 = 0x30 ;
V_284 -> V_315 = V_638 ;
V_284 -> V_639 = 0 ;
if ( ++ V_284 == V_152 -> V_403 . V_317 )
V_284 = V_152 -> V_403 . V_318 ;
V_284 -> V_310 = V_152 -> V_450 [ V_274 - 1 ] . V_286 ;
V_284 -> V_313 = ( ( V_282 -> V_303 << 16 ) |
V_282 -> V_304 ) + V_631 - sizeof( struct V_340 ) ;
V_284 -> V_314 = sizeof( struct V_340 ) ;
V_284 -> V_315 = V_316 ;
V_284 -> V_639 = V_152 -> V_27 . V_466 ;
if ( ++ V_284 == V_152 -> V_403 . V_317 )
V_284 = V_152 -> V_403 . V_318 ;
V_152 -> V_403 . V_309 = V_284 ;
F_69 ( V_33 ) = V_41 -> V_58 ;
F_70 ( & V_152 -> V_405 , V_33 ) ;
F_66 ( & V_41 -> V_300 -> V_632 ) ;
V_152 -> V_494 ++ ;
F_50 ( 2 , V_152 -> V_319 + V_640 ) ;
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
F_145 (printk(L_170);)
return 0 ;
}
static int F_147 ( struct V_40 * V_41 , struct V_32 * V_33 )
{
T_2 * V_152 ;
unsigned long V_158 ;
V_152 = F_31 ( V_41 -> V_9 ) ;
if ( ( ! V_33 ) || ( V_33 -> V_164 > ( V_152 -> V_175 - sizeof( struct V_340 ) ) ) )
{
if ( ! V_33 )
F_9 ( V_641 L_171 ) ;
else F_36 ( V_33 ) ;
return - V_289 ;
}
F_87 ( & V_152 -> V_400 , V_158 ) ;
if ( ! F_37 ( V_157 , & V_41 -> V_158 ) ) {
F_36 ( V_33 ) ;
F_88 ( & V_152 -> V_400 , V_158 ) ;
return - V_289 ;
}
F_35 ( V_33 ) -> V_41 = V_41 ;
if ( F_140 ( & V_152 -> V_156 ) ) {
F_70 ( & V_152 -> V_156 , V_33 ) ;
}
else {
if ( F_38 ( V_41 , V_33 ) ) {
F_70 ( & V_152 -> V_156 , V_33 ) ;
}
}
F_88 ( & V_152 -> V_400 , V_158 ) ;
return 0 ;
}
static int F_148 ( struct V_273 * V_9 , T_21 * V_642 , char * V_643 )
{
int V_644 = * V_642 , V_645 ;
char * V_646 ;
T_2 * V_152 = F_31 ( V_9 ) ;
if( ! V_644 -- ) {
if ( V_152 -> V_186 == V_188 ) {
V_645 = sprintf ( V_643 , L_172 ) ;
return V_645 ;
}
if ( V_152 -> V_186 == V_189 )
V_645 = sprintf ( V_643 , L_173 ) ;
else if ( V_152 -> V_186 == V_190 )
V_645 = sprintf ( V_643 , L_174 ) ;
else if ( V_152 -> V_186 == V_647 )
V_645 = sprintf ( V_643 , L_175 ) ;
else
V_645 = sprintf ( V_643 , L_176 ) ;
V_646 = V_643 + V_645 ;
if ( V_152 -> V_523 == 0x40000 )
V_645 += sprintf ( V_646 , L_177 ) ;
else
V_645 += sprintf ( V_646 , L_178 ) ;
V_646 = V_643 + V_645 ;
if ( ( V_152 -> V_171 & V_172 ) == V_173 )
V_645 += sprintf ( V_646 , L_179 ) ;
else if ( ( V_152 -> V_171 & V_172 ) == V_181 )
V_645 += sprintf ( V_646 , L_180 ) ;
else
V_645 += sprintf ( V_646 , L_181 ) ;
return V_645 ;
}
if ( ! V_644 ) {
return sprintf ( V_643 , L_182
L_183
L_184
L_185
L_186
L_187
L_188
L_189
L_190
L_191 ,
V_152 -> V_39 , V_152 -> V_175 ,
V_152 -> V_177 , V_152 -> V_179 ,
V_152 -> V_329 , V_152 -> V_494 ,
V_152 -> V_537 , V_152 -> V_544 ,
V_152 -> V_542 , V_152 -> V_540 ) ;
}
return 0 ;
}
static int T_15 F_149 ( struct V_648 * V_649 ,
const struct V_650 * V_651 )
{
struct V_273 * V_9 ;
T_2 * V_152 ;
int V_410 ;
V_152 = F_84 ( sizeof( * V_152 ) , V_396 ) ;
if ( ! V_152 ) {
V_410 = - V_399 ;
goto V_361;
}
V_152 -> V_311 = V_649 ;
F_47 (printk(L_192,
pdev->bus->number, PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));)
if ( F_150 ( V_649 ) ) {
V_410 = - V_652 ;
goto V_653;
}
V_9 = F_151 ( V_525 , & V_649 -> V_9 , & V_654 , - 1 , NULL ) ;
if ( ! V_9 ) {
V_410 = - V_399 ;
goto V_655;
}
V_9 -> V_413 = V_152 ;
F_47 (printk(DEV_LABEL L_193, dev->number);)
F_47 (printk(L_194, dev,
iadev->LineRate);)
F_152 ( V_649 , V_9 ) ;
V_551 [ V_550 ] = V_152 ;
V_613 [ V_550 ] = V_9 ;
V_550 ++ ;
if ( F_107 ( V_9 ) || F_121 ( V_9 ) ) {
F_47 (printk(L_195);)
V_550 -- ;
V_551 [ V_550 ] = NULL ;
V_613 [ V_550 ] = NULL ;
V_410 = - V_289 ;
goto V_656;
}
F_10 (printk(L_196, iadev_count);)
V_152 -> V_657 = V_658 ;
V_658 = V_9 ;
return 0 ;
V_656:
F_153 ( V_9 ) ;
V_655:
F_154 ( V_649 ) ;
V_653:
F_41 ( V_152 ) ;
V_361:
return V_410 ;
}
static void T_22 F_155 ( struct V_648 * V_649 )
{
struct V_273 * V_9 = F_156 ( V_649 ) ;
T_2 * V_152 = F_31 ( V_9 ) ;
F_117 ( V_9 , F_118 ( V_9 , V_659 ) & ~ ( V_660 ) ,
V_659 ) ;
F_15 ( 1 ) ;
if ( V_9 -> V_195 && V_9 -> V_195 -> V_661 )
V_9 -> V_195 -> V_661 ( V_9 ) ;
F_124 ( V_152 -> V_495 , V_9 ) ;
V_550 -- ;
V_551 [ V_550 ] = NULL ;
V_613 [ V_550 ] = NULL ;
F_10 (printk(L_197, dev->number);)
F_153 ( V_9 ) ;
F_113 ( V_152 -> V_516 ) ;
F_154 ( V_649 ) ;
F_120 ( V_152 ) ;
F_119 ( V_152 ) ;
F_41 ( V_152 ) ;
}
static int T_23 F_157 ( void )
{
int V_410 ;
V_410 = F_158 ( & V_662 ) ;
if ( V_410 >= 0 ) {
V_554 . V_663 = V_37 + 3 * V_416 ;
F_159 ( & V_554 ) ;
} else
F_9 (KERN_ERR DEV_LABEL L_198 ) ;
return V_410 ;
}
static void T_24 F_160 ( void )
{
F_161 ( & V_662 ) ;
F_162 ( & V_554 ) ;
}
