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
if ( ! V_6 )
return - V_8 ;
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
T_1 * V_9 ;
if ( V_1 -> V_2 == NULL )
return NULL ;
V_9 = V_1 -> V_2 ;
if ( V_1 -> V_2 == V_1 -> V_3 )
V_1 -> V_2 = V_1 -> V_3 = NULL ;
else
V_1 -> V_2 = V_1 -> V_2 -> V_2 ;
return V_9 ;
}
static void F_6 ( T_2 * V_10 ) {
T_3 V_11 ;
T_3 V_12 ;
struct V_13 * V_14 = NULL ;
V_12 = F_7 ( V_10 -> V_15 + V_16 ) & 0xffff ;
while ( V_10 -> V_17 != V_12 ) {
V_11 = * ( T_3 * ) ( V_10 -> V_18 + V_10 -> V_17 ) ;
if ( ! V_11 ) ;
else if ( ! V_10 -> V_19 [ V_11 - 1 ] . V_20 ) {
F_8 (printk(L_1, desc1 -1, jiffies);)
* ( T_3 * ) ( V_10 -> V_18 + V_10 -> V_17 ) = 0 ;
}
else if ( V_10 -> V_19 [ V_11 - 1 ] . V_20 ) {
if ( ! ( V_14 = V_10 -> V_19 [ V_11 - 1 ] . V_21 ) ) {
F_9 ( L_2 ) ;
continue;
}
V_14 -> V_22 -- ;
V_10 -> V_19 [ V_11 - 1 ] . V_20 = 0 ;
F_10 (printk(L_3,
dev->desc_tbl[desc1 -1].txskb, desc1);)
if ( V_14 -> V_23 < V_10 -> V_24 ) {
F_11 ( V_10 -> V_19 [ V_11 - 1 ] . V_25 ) |= V_26 ;
if ( F_3 ( & V_10 -> V_27 , V_10 -> V_19 [ V_11 - 1 ] ) < 0 )
F_9 ( L_4 ) ;
}
V_10 -> V_19 [ V_11 - 1 ] . V_21 = NULL ;
V_10 -> V_19 [ V_11 - 1 ] . V_25 = NULL ;
}
V_10 -> V_17 += 2 ;
if ( V_10 -> V_17 > V_10 -> V_28 . V_29 )
V_10 -> V_17 = V_10 -> V_28 . V_30 ;
}
}
static T_4 F_12 ( T_2 * V_10 , struct V_13 * V_21 ) {
T_3 V_31 , V_32 ;
struct V_33 * V_34 ;
struct V_13 * V_14 = NULL ;
unsigned long V_35 ;
static unsigned long V_36 = 0 ;
int V_37 ;
F_6 ( V_10 ) ;
if( ( F_13 ( V_38 , V_36 + 50 ) ) || ( ( V_10 -> V_28 . V_39 == V_10 -> V_17 ) ) ) {
V_36 = V_38 ;
V_32 = 0 ;
while ( V_32 < V_10 -> V_40 ) {
if ( ! V_10 -> V_19 [ V_32 ] . V_20 ) {
V_32 ++ ;
continue;
}
V_37 = V_10 -> V_19 [ V_32 ] . V_21 -> V_37 ;
V_35 = V_38 - V_10 -> V_19 [ V_32 ] . V_20 ;
if ( V_35 >= V_37 ) {
F_8 (printk(L_5, i,dev->desc_tbl[i].timestamp, delta, jiffies);)
if ( V_10 -> V_28 . V_39 == V_10 -> V_28 . V_30 )
V_10 -> V_28 . V_39 = V_10 -> V_28 . V_29 ;
else
V_10 -> V_28 . V_39 -= 2 ;
* ( T_3 * ) ( V_10 -> V_18 + V_10 -> V_28 . V_39 ) = V_32 + 1 ;
if ( ! ( V_34 = V_10 -> V_19 [ V_32 ] . V_25 ) ||
! ( V_14 = V_10 -> V_19 [ V_32 ] . V_21 ) )
F_9 ( L_6 ) ;
else
V_14 -> V_22 -- ;
V_10 -> V_19 [ V_32 ] . V_20 = 0 ;
V_10 -> V_19 [ V_32 ] . V_21 = NULL ;
V_10 -> V_19 [ V_32 ] . V_25 = NULL ;
}
V_32 ++ ;
}
}
if ( V_10 -> V_28 . V_39 == V_10 -> V_17 )
return 0xFFFF ;
V_31 = * ( T_3 * ) ( V_10 -> V_18 + V_10 -> V_28 . V_39 ) ;
while ( ! V_31 || ( V_10 -> V_19 [ V_31 - 1 ] ) . V_20 ) {
V_10 -> V_28 . V_39 += 2 ;
if ( V_10 -> V_28 . V_39 > V_10 -> V_28 . V_29 )
V_10 -> V_28 . V_39 = V_10 -> V_28 . V_30 ;
if ( V_10 -> V_28 . V_39 == V_10 -> V_17 )
return 0xFFFF ;
V_31 = * ( T_3 * ) ( V_10 -> V_18 + V_10 -> V_28 . V_39 ) ;
}
V_10 -> V_19 [ V_31 - 1 ] . V_20 = V_38 ;
return V_31 ;
}
static void F_14 ( struct V_41 * V_42 , T_2 * V_10 ) {
T_5 V_43 ;
T_6 * V_44 ;
T_3 * V_45 ;
T_3 V_46 , V_47 ;
struct V_48 * V_49 = (struct V_48 * ) V_10 -> V_50 ;
struct V_51 * V_52 = (struct V_51 * ) V_10 -> V_53 ;
T_7 V_32 ;
if ( V_42 -> V_54 . V_55 . V_56 == V_57 ) {
V_44 = ( T_6 * ) & ( V_10 -> V_58 [ V_42 -> V_59 ] -> V_60 ) ;
V_44 -> V_61 ++ ;
V_43 = 0 ;
if( V_44 -> V_61 == 0x05 ) {
V_49 += V_42 -> V_59 ;
V_52 += V_42 -> V_59 ;
if( V_52 -> V_62 ) {
if( ( V_49 -> V_63 & 0x07 ) == V_64 ) {
F_15 ( 10 ) ;
if ( ( V_52 -> V_62 ) && ( ( V_49 -> V_63 & 0x07 ) == V_64 ) )
V_43 = 1 ;
}
else {
V_46 = V_49 -> V_65 ;
V_47 = V_49 -> V_66 ;
if( ( V_46 == V_10 -> V_58 [ V_42 -> V_59 ] -> V_67 )
&& ( V_47 == V_10 -> V_58 [ V_42 -> V_59 ] -> V_68 ) )
V_43 = 1 ;
V_10 -> V_58 [ V_42 -> V_59 ] -> V_67 = V_46 ;
V_10 -> V_58 [ V_42 -> V_59 ] -> V_68 = V_47 ;
}
}
V_44 -> V_61 = 0 ;
}
if ( V_43 ) {
F_8 (printk(L_7);)
F_16 ( 0xFFFD , V_10 -> V_15 + V_69 ) ;
F_15 ( 10 ) ;
V_49 -> V_63 &= 0xFFF8 ;
V_49 -> V_63 |= 0x0001 ;
V_45 = ( T_3 * ) V_10 -> V_70 ;
for( V_32 = 0 ; ( ( V_32 < V_10 -> V_71 ) && ( V_45 [ V_32 ] ) ) ; V_32 ++ ) ;
if ( V_32 < V_10 -> V_71 )
V_45 [ V_32 ] = V_42 -> V_59 ;
else
F_17 (printk(L_8,vcc->vci);)
F_16 ( V_72 , V_10 -> V_15 + V_69 ) ;
F_16 ( ~ ( V_73 | V_74 ) , V_10 -> V_15 + V_75 ) ;
F_16 ( V_73 , V_10 -> V_15 + V_76 ) ;
V_44 -> V_61 = 0 ;
}
}
}
static T_4
F_18 ( T_8 V_77 )
{
#define F_19 0x4000
#define F_20 9
#define F_21 5
#define F_22 0x1ff
#define F_23 0x1f
T_4 V_78 ;
T_8 V_79 = V_77 & 0x00ffffff ;
int V_32 = 0 ;
if ( V_77 == 0 )
return 0 ;
while ( V_79 != 1 ) {
V_79 >>= 1 ;
V_32 ++ ;
}
if ( V_32 == F_20 )
V_78 = F_19 | ( V_32 << F_20 ) | ( V_77 & F_22 ) ;
else if ( V_32 < F_20 )
V_78 = F_19 | ( V_32 << F_20 ) | ( ( V_77 << ( F_20 - V_32 ) ) & F_22 ) ;
else
V_78 = F_19 | ( V_32 << F_20 ) | ( ( V_77 >> ( V_32 - F_20 ) ) & F_22 ) ;
return V_78 ;
}
static void F_24 ( T_2 * V_10 , T_9 * V_80 ) {
V_80 -> V_81 = V_57 ;
V_80 -> V_23 = V_10 -> V_82 ;
V_80 -> V_83 = 0 ;
V_80 -> V_84 = 0x055cb7 ;
V_80 -> V_85 = 0xffffff ;
V_80 -> V_86 = 0x3a ;
V_80 -> V_87 = 0xf ;
V_80 -> V_88 = 0xb ;
V_80 -> V_89 = 0x4 ;
V_80 -> V_90 = 0x7 ;
V_80 -> V_91 = 0x3 ;
V_80 -> V_92 = 50 ;
}
static int
F_25 ( T_2 * V_10 , T_9 * V_80 ,
struct V_41 * V_42 , T_10 V_93 )
{
T_11 * V_94 ;
T_12 * V_95 ;
T_8 V_84 ;
T_10 V_90 , V_89 , V_96 ;
T_4 V_92 , V_97 , * V_98 ;
V_94 = ( T_11 * ) V_10 -> V_50 ;
V_94 += V_42 -> V_59 ;
switch ( V_93 ) {
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
memset ( ( V_99 ) V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_100 = V_101 ;
V_89 = 2 << V_80 -> V_89 ;
V_94 -> V_102 = V_89 << 8 | V_89 ;
V_90 = 100000 / ( 2 << ( 16 - V_80 -> V_90 ) ) ;
if ( V_90 == 0 ) V_90 = 1 ;
V_94 -> V_103 = ( ( ( V_80 -> V_89 + 1 ) & 0x0f ) << 12 ) | ( V_104 << 8 ) | V_90 ;
V_96 = V_80 -> V_85 / V_89 ;
if ( V_96 == 0 ) V_96 = 1 ;
V_94 -> V_105 = V_96 & 0xff ;
V_94 -> V_106 = F_18 ( V_80 -> V_23 ) ;
V_84 = F_26 ( V_80 -> V_84 , ( V_80 -> V_85 > V_80 -> V_86 ) ?
( ( V_80 -> V_85 / V_80 -> V_86 ) * 1000000 ) :
( 1000000 / ( V_80 -> V_86 / V_80 -> V_85 ) ) ) ;
V_94 -> V_107 = F_18 ( V_84 ) ;
V_92 = ( 10000 * V_80 -> V_92 ) / 8192 ;
if ( V_92 == 0 ) V_92 = 1 ;
V_94 -> V_108 = ( ( 7 - V_80 -> V_91 ) << 12 | V_92 ) & 0xfff ;
V_94 -> V_109 = F_18 ( V_80 -> V_83 ) ;
V_94 -> V_110 = V_94 -> V_107 ;
V_94 -> V_111 = 0x0042 ;
break;
case 0 :
V_98 = ( T_3 * ) ( V_10 -> V_112 + V_113 * V_10 -> V_114 ) ;
* ( V_98 + V_42 -> V_59 ) = V_115 | V_116 ;
V_95 = ( T_12 * ) ( V_10 -> V_112 + V_117 * V_10 -> V_114 ) ;
V_95 += V_42 -> V_59 ;
V_95 -> V_118 = ( 15 - V_80 -> V_88 ) & 0x000f ;
V_97 = V_80 -> V_23 << ( 15 - V_80 -> V_87 ) ;
if ( V_97 == 0 ) V_97 = 1 ;
V_95 -> V_119 = F_18 ( V_97 ) ;
V_10 -> V_58 [ V_42 -> V_59 ] -> V_60 = V_120 | V_121 ;
V_10 -> V_122 += V_80 -> V_83 ;
V_10 -> V_123 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_27 ( T_2 * V_10 , struct V_41 * V_42 ) {
T_8 V_124 = 0 , V_125 , V_126 ;
int V_127 ;
struct V_13 * V_13 ;
int V_128 = 0 , V_129 , V_130 , V_131 ;
T_8 V_132 ;
T_4 * V_133 , * V_134 ;
T_4 V_135 , V_136 ;
T_8 V_137 = 0 ;
T_8 V_138 = 0 ;
T_8 V_139 = 0 ;
if ( V_42 -> V_54 . V_55 . V_140 <= 0 ) {
F_17 (printk(L_9);)
return - 1 ;
}
V_126 = V_42 -> V_54 . V_55 . V_140 ;
V_127 = V_126 / V_10 -> V_141 ;
F_28 (printk(L_10,
entries, rate, dev->Granularity);)
if ( V_127 < 1 )
F_28 (printk(L_11);)
V_124 = V_127 * V_10 -> V_141 ;
V_125 = ( V_127 + 1 ) * V_10 -> V_141 ;
if ( 3 * ( V_126 - V_124 ) > ( V_125 - V_126 ) )
V_127 ++ ;
if ( V_127 > V_10 -> V_142 ) {
F_28 (printk(L_12);)
F_28 (printk(L_13,
entries, dev->CbrRemEntries);)
return - V_143 ;
}
V_13 = F_29 ( V_42 ) ;
V_13 -> V_144 = V_127 ;
V_10 -> V_122 += V_127 * V_10 -> V_141 ;
V_135 = 0 ;
V_132 = V_10 -> V_145 / V_127 ;
V_138 = V_10 -> V_145 % V_127 ;
V_130 = V_127 ;
V_137 = 0 ;
V_136 = V_42 -> V_59 ;
F_28 (printk(L_14,vcIndex,spacing,sp_mod);)
while ( V_130 )
{
if ( V_130 == V_127 )
{
V_128 = V_10 -> V_146 ;
V_10 -> V_146 += 2 ;
if ( V_10 -> V_146 >= V_10 -> V_145 )
V_10 -> V_146 -= V_10 -> V_145 ;
} else {
V_128 += ( T_8 ) ( V_132 + V_137 ) ;
V_137 = ( ( V_138 + V_139 ) / V_127 ) ;
V_139 = ( ( V_138 + V_139 ) % V_127 ) ;
}
if ( V_128 >= ( int ) V_10 -> V_145 )
V_128 -= V_10 -> V_145 ;
V_133 = ( T_4 * ) ( V_10 -> V_18 + V_147 * V_10 -> V_114 ) ;
V_131 = 0 ;
V_129 = V_128 ;
V_134 = ( T_4 * ) ( V_133 + V_129 ) ;
F_28 (printk(L_15,
testSlot, TstSchedTbl,toBeAssigned);)
memcpy ( ( V_99 ) & V_135 , ( V_99 ) V_134 , sizeof( V_135 ) ) ;
while ( V_135 )
{
V_131 ++ ;
V_129 = V_128 - V_131 ;
if ( V_129 < 0 ) {
V_129 += V_10 -> V_145 ;
F_28 (printk(L_16,
SchedTbl,testSlot);)
}
V_134 = ( T_4 * ) ( V_133 + V_129 ) ;
memcpy ( ( V_99 ) & V_135 , ( V_99 ) V_134 , sizeof( V_135 ) ) ;
if ( ! V_135 )
break;
V_129 = V_128 + V_131 ;
if ( V_129 >= ( int ) V_10 -> V_145 ) {
V_129 -= V_10 -> V_145 ;
F_28 (printk(L_17,dev->CbrTotEntries);)
F_28 (printk(L_18,
testSlot, toBeAssigned);)
}
V_134 = ( T_4 * ) ( V_133 + V_129 ) ;
F_28 (printk(L_19,
TstSchedTbl,cbrVC,inc);)
memcpy ( ( V_99 ) & V_135 , ( V_99 ) V_134 , sizeof( V_135 ) ) ;
}
memcpy ( ( V_99 ) V_134 , ( V_99 ) & V_136 , sizeof( * V_134 ) ) ;
V_10 -> V_142 -- ;
V_130 -- ;
}
V_10 -> V_148 ++ ;
if ( V_10 -> V_148 == 1 ) {
F_16 ( ( V_149 | V_150 | V_151 | ( 0x23 << 2 ) ) , V_10 -> V_15 + V_152 ) ;
F_28 (printk(L_20);)
}
return 0 ;
}
static void F_30 ( struct V_41 * V_42 ) {
T_2 * V_153 ;
T_4 * V_133 , V_154 = 0 ;
T_8 V_32 , V_155 ;
V_153 = F_31 ( V_42 -> V_10 ) ;
V_153 -> V_148 -- ;
V_133 = ( T_4 * ) ( V_153 -> V_18 + V_147 * V_153 -> V_114 ) ;
if ( V_153 -> V_148 == 0 ) {
F_16 ( ( V_150 | V_151 | ( 0x23 << 2 ) ) , V_153 -> V_15 + V_152 ) ;
F_28 (printk(L_21);)
}
V_155 = 0 ;
for ( V_32 = 0 ; V_32 < V_153 -> V_145 ; V_32 ++ )
{
if ( * V_133 == V_42 -> V_59 ) {
V_153 -> V_142 ++ ;
* V_133 = V_154 ;
F_28 (NumFound++;)
}
V_133 ++ ;
}
F_28 (printk(L_22,NumFound);)
}
static int F_32 ( T_2 * V_153 ) {
int V_79 = 0 ;
F_6 ( V_153 ) ;
if ( V_153 -> V_17 >= V_153 -> V_28 . V_39 )
V_79 = ( V_153 -> V_17 - V_153 -> V_28 . V_39 ) / 2 ;
else
V_79 = ( V_153 -> V_28 . V_29 - V_153 -> V_28 . V_39 + 2 + V_153 -> V_17 -
V_153 -> V_28 . V_30 ) / 2 ;
return V_79 ;
}
static int F_33 ( T_2 * V_153 ) {
struct V_33 * V_34 ;
int V_156 ;
struct V_41 * V_42 ;
V_156 = F_32 ( V_153 ) ;
while ( V_156 && ( V_34 = F_34 ( & V_153 -> V_157 ) ) ) {
if ( ! ( V_42 = F_35 ( V_34 ) -> V_42 ) ) {
F_36 ( V_34 ) ;
F_9 ( L_23 ) ;
break;
}
if ( ! F_37 ( V_158 , & V_42 -> V_159 ) ) {
F_36 ( V_34 ) ;
F_9 ( L_24 , V_42 -> V_59 ) ;
break;
}
if ( F_38 ( V_42 , V_34 ) ) {
F_39 ( & V_153 -> V_157 , V_34 ) ;
}
V_156 -- ;
}
return 0 ;
}
static void F_40 ( T_2 * V_153 ) {
struct V_41 * V_42 = NULL ;
struct V_33 * V_34 = NULL , * V_160 = NULL ;
struct V_13 * V_21 ;
T_1 * V_161 ;
F_6 ( V_153 ) ;
while ( ( V_161 = F_5 ( & V_153 -> V_27 ) ) ) {
V_34 = V_161 -> V_4 . V_25 ;
if ( ! V_34 ) {
F_9 ( L_25 ) ;
goto V_162;
}
V_42 = F_35 ( V_34 ) -> V_42 ;
if ( ! V_42 ) {
F_9 ( L_26 ) ;
F_36 ( V_34 ) ;
goto V_162;
}
V_21 = F_29 ( V_42 ) ;
if ( ! V_21 ) {
F_9 ( L_27 ) ;
F_36 ( V_34 ) ;
goto V_162;
}
V_160 = F_34 ( & V_21 -> V_163 ) ;
while ( V_160 && ( V_160 != V_34 ) ) {
if ( ! ( F_11 ( V_160 ) & V_26 ) ) {
F_9 ( L_28 , V_42 -> V_59 ) ;
}
F_17 (printk(L_29);)
if ( ( V_42 -> V_164 ) && ( V_160 -> V_165 != 0 ) )
{
V_42 -> V_164 ( V_42 , V_160 ) ;
F_10 (printk(L_30,
(long)skb1);)
}
else
F_36 ( V_160 ) ;
V_160 = F_34 ( & V_21 -> V_163 ) ;
}
if ( ! V_160 ) {
F_10 (printk(L_31,vcc->vci);)
F_2 ( & V_153 -> V_27 , V_161 ) ;
break;
}
if ( ( V_42 -> V_164 ) && ( V_34 -> V_165 != 0 ) )
{
V_42 -> V_164 ( V_42 , V_34 ) ;
F_10 (printk(L_32,(long)skb);)
}
else
F_36 ( V_34 ) ;
F_41 ( V_161 ) ;
}
F_33 ( V_153 ) ;
V_162:
return;
}
static T_4 F_42 ( T_2 * V_153 , T_8 V_166 )
{
T_3 V_167 ;
T_8 V_168 ;
int V_32 ;
F_43 ( V_169 + V_166 ) ;
V_167 = 0 ;
for ( V_32 = 15 ; V_32 >= 0 ; V_32 -- ) {
F_44 ( V_168 ) ;
V_167 |= ( V_168 << V_32 ) ;
}
V_170 ;
F_45 ( ~ V_171 ) ;
return V_167 ;
}
static void F_46 ( T_2 * V_153 ) {
T_3 V_172 = F_42 ( V_153 , 25 ) ;
V_153 -> V_172 = V_172 ;
if ( ( V_172 & V_173 ) == V_174 ) {
V_153 -> V_40 = V_175 ;
V_153 -> V_176 = V_177 ;
V_153 -> V_178 = V_179 ;
V_153 -> V_180 = V_181 ;
} else if ( ( V_172 & V_173 ) == V_182 ) {
if ( V_175 == V_183 )
V_153 -> V_40 = V_175 / 2 ;
else
V_153 -> V_40 = V_175 ;
V_153 -> V_176 = V_177 ;
if ( V_179 == V_184 )
V_153 -> V_178 = V_179 / 2 ;
else
V_153 -> V_178 = V_179 ;
V_153 -> V_180 = V_181 ;
}
else {
if ( V_175 == V_183 )
V_153 -> V_40 = V_175 / 8 ;
else
V_153 -> V_40 = V_175 ;
V_153 -> V_176 = V_177 ;
if ( V_179 == V_184 )
V_153 -> V_178 = V_179 / 8 ;
else
V_153 -> V_178 = V_179 ;
V_153 -> V_180 = V_181 ;
}
V_153 -> V_185 = V_186 + ( V_153 -> V_40 * V_153 -> V_176 ) ;
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
V_153 -> V_187 = V_172 & V_188 ;
F_47 (printk(L_34,
memType,iadev->phy_type);)
if ( V_153 -> V_187 == V_189 )
V_153 -> V_82 = ( T_8 ) ( ( ( 25600000 / 8 ) * 26 ) / ( 27 * 53 ) ) ;
else if ( V_153 -> V_187 == V_190 )
V_153 -> V_82 = ( T_8 ) ( ( ( 44736000 / 8 ) * 26 ) / ( 27 * 53 ) ) ;
else if ( V_153 -> V_187 == V_191 )
V_153 -> V_82 = ( T_8 ) ( ( ( 34368000 / 8 ) * 26 ) / ( 27 * 53 ) ) ;
else
V_153 -> V_82 = ( T_8 ) ( V_192 ) ;
F_47 (printk(L_35, iadev->LineRate);)
}
static T_8 F_48 ( struct V_193 * V_194 , unsigned int V_195 )
{
return F_7 ( V_194 -> V_196 + ( V_195 >> 2 ) ) ;
}
static void F_49 ( struct V_193 * V_194 , unsigned int V_195 , T_8 V_167 )
{
F_50 ( V_167 , V_194 -> V_196 + ( V_195 >> 2 ) ) ;
}
static void F_51 ( struct V_193 * V_153 )
{
T_8 V_63 ;
if ( V_153 -> V_187 & V_189 ) {
V_63 = F_48 ( V_153 , V_197 ) ;
V_153 -> V_198 = ( V_63 & V_199 ) ? 1 : 0 ;
} else if ( V_153 -> V_187 & V_190 ) {
F_48 ( V_153 , V_200 ) ;
V_63 = F_48 ( V_153 , V_201 ) ;
V_153 -> V_198 = ( V_63 & V_202 ) ? 0 : 1 ;
} else if ( V_153 -> V_187 & V_191 ) {
F_48 ( V_153 , V_203 ) ;
V_63 = F_48 ( V_153 , V_204 ) ;
V_153 -> V_198 = ( V_63 & V_205 ) ? 0 : 1 ;
} else {
V_63 = F_48 ( V_153 , V_206 ) ;
V_153 -> V_198 = ( V_63 & V_207 ) ? 0 : 1 ;
}
F_9 ( V_208 L_36 ,
V_153 -> V_198 ? L_37 : L_38 ) ;
}
static void F_52 ( struct V_193 * V_153 )
{
#if 0
mb25->mb25_master_ctrl = MB25_MC_DRIC | MB25_MC_DREC | MB25_MC_ENABLED;
#endif
F_49 ( V_153 , V_209 , V_210 | V_211 ) ;
F_49 ( V_153 , V_212 , 0 ) ;
V_153 -> V_198 =
( F_48 ( V_153 , V_197 ) & V_199 ) ? 1 : 0 ;
}
static void F_53 ( struct V_193 * V_153 ,
const struct V_213 * V_214 , int V_165 )
{
while ( V_165 -- ) {
F_49 ( V_153 , V_214 -> V_195 , V_214 -> V_167 ) ;
V_214 ++ ;
}
}
static void F_54 ( struct V_193 * V_153 )
{
static const struct V_213 V_215 [] = {
{ V_216 , 0x17 } ,
{ V_217 , 0x01 } ,
{ V_218 , 0x01 } ,
{ V_219 , 0 } ,
{ V_220 , 0 } ,
{ V_221 , 0 }
} ;
T_8 V_63 ;
V_63 = F_48 ( V_153 , V_201 ) ;
V_153 -> V_198 = ( V_63 & V_202 ) ? 0 : 1 ;
F_53 ( V_153 , V_215 , F_55 ( V_215 ) ) ;
}
static void F_56 ( struct V_193 * V_153 )
{
static const struct V_213 V_222 [] = {
{ V_223 , 0x04 } ,
{ V_224 , 0x20 } ,
{ V_225 , 0x1d } ,
{ V_226 , 0x30 } ,
{ V_227 , 0 } ,
{ V_228 , 0x01 } ,
{ V_219 , V_229 } ,
{ V_220 , 0x41 } ,
{ V_221 , 0x41 }
} ;
T_8 V_63 ;
V_63 = F_48 ( V_153 , V_204 ) ;
V_153 -> V_198 = ( V_63 & V_205 ) ? 0 : 1 ;
F_53 ( V_153 , V_222 , F_55 ( V_222 ) ) ;
}
static void F_57 ( struct V_193 * V_153 )
{
static const struct V_213 V_230 [] = {
{ V_231 , 0x28 } ,
{ V_232 , 0 } ,
{ V_233 , 0 } ,
{ V_234 , 0x2c } ,
{ V_235 , 0x81 } ,
{ V_236 , 0 } ,
{ V_237 , 0 } ,
{ V_238 , 0 } ,
{ V_239 , 0x01 } ,
{ V_240 , 0xff } ,
{ V_241 , 0xff } ,
{ V_242 , 0xff } ,
{ V_243 , 0xfe } ,
{ V_244 , 0 } ,
{ V_245 , 0 } ,
{ V_246 , 0 } ,
{ V_247 , 0x01 } ,
{ V_248 , 0xff } ,
{ V_249 , 0xff } ,
{ V_250 , 0xff } ,
{ V_251 , 0xff } ,
{ V_252 , 0xa4 } ,
{ V_253 , 0x10 } ,
{ V_254 , 0x55 }
} ;
if ( V_153 -> V_187 & V_190 )
F_54 ( V_153 ) ;
else
F_56 ( V_153 ) ;
F_53 ( V_153 , V_230 , F_55 ( V_230 ) ) ;
F_49 ( V_153 , V_219 , F_48 ( V_153 , V_219 ) &
~ ( V_255 | V_256 |
V_257 | V_258 ) ) ;
#ifdef F_58
V_259 -> V_260 |= V_261 ;
#endif
return;
}
static void F_59 ( T_5 * V_262 , int V_263 , char * V_264 )
{
int V_265 , V_266 ;
T_5 V_267 [ 120 ] ;
T_5 * V_268 = V_267 ;
V_266 = 0 ;
while( V_266 < V_263 ) {
V_268 += sprintf ( V_268 , L_39 , V_264 ) ;
for( V_265 = 0 ; V_266 + V_265 < V_263 && V_265 < 16 ; V_265 ++ ) {
if ( V_265 != 0 && ( V_265 % 4 ) == 0 )
V_268 += sprintf ( V_268 , L_40 ) ;
V_268 += sprintf ( V_268 , L_41 , V_262 [ V_266 + V_265 ] ) ;
}
while( V_265 ++ < 16 ) {
if ( ( V_265 % 4 ) == 0 )
sprintf ( V_268 , L_40 ) ;
V_268 += sprintf ( V_268 , L_42 ) ;
}
V_268 += sprintf ( V_268 , L_43 ) ;
for( V_265 = 0 ; V_266 + V_265 < V_263 && V_265 < 16 ; V_265 ++ ) {
if ( isprint ( ( int ) V_262 [ V_266 + V_265 ] ) )
V_268 += sprintf ( V_268 , L_44 , V_262 [ V_266 + V_265 ] ) ;
else
V_268 += sprintf ( V_268 , L_45 ) ;
}
F_9 ( L_46 , V_267 ) ;
V_266 += V_265 ;
V_268 = V_267 ;
}
}
static void F_60 ( T_2 * V_153 ) {
T_3 V_269 , V_270 , V_271 ;
T_8 V_32 ;
void T_13 * V_79 ;
V_269 = F_61 ( V_153 -> V_15 + V_16 ) ;
F_9 ( L_47 ,
V_269 , F_61 ( V_153 -> V_18 + V_269 ) ,
F_61 ( V_153 -> V_18 + V_269 - 2 ) ) ;
F_9 ( L_48 , V_153 -> V_17 ,
V_153 -> V_28 . V_39 ) ;
V_270 = F_61 ( V_153 -> V_15 + V_272 ) ;
V_271 = F_61 ( V_153 -> V_15 + V_273 ) ;
F_9 ( L_49 , V_270 , V_271 ) ;
V_32 = 0 ;
while ( V_270 != V_271 ) {
V_79 = V_153 -> V_18 + V_270 ;
F_9 ( L_50 , V_32 ++ , F_61 ( V_79 ) , V_79 ) ;
V_270 += 2 ;
}
for( V_32 = 0 ; V_32 < V_153 -> V_40 ; V_32 ++ )
F_9 ( L_51 , V_32 , V_153 -> V_19 [ V_32 ] . V_20 ) ;
}
static void F_62 ( struct V_274 * V_10 )
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
static void F_63 ( struct V_274 * V_10 , int V_275 )
{
T_2 * V_153 ;
V_153 = F_31 ( V_10 ) ;
F_16 ( V_275 , V_153 -> V_112 + V_153 -> V_276 . V_277 ) ;
V_153 -> V_276 . V_277 += 2 ;
if ( V_153 -> V_276 . V_277 > V_153 -> V_276 . V_278 )
V_153 -> V_276 . V_277 = V_153 -> V_276 . V_279 ;
F_16 ( V_153 -> V_276 . V_277 , V_153 -> V_280 + V_281 ) ;
}
static int F_64 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
struct V_41 * V_42 ;
unsigned short V_63 ;
struct V_282 T_13 * V_283 ;
int V_275 ;
struct V_284 * V_285 ;
int V_165 ;
struct V_33 * V_34 ;
T_7 V_286 , V_287 ;
V_153 = F_31 ( V_10 ) ;
if ( V_153 -> V_276 . V_288 == ( F_61 ( V_153 -> V_280 + V_289 ) & 0xffff ) )
{
F_9 (KERN_ERR DEV_LABEL L_52 , dev->number) ;
return - V_290 ;
}
V_275 = F_61 ( V_153 -> V_112 + V_153 -> V_276 . V_288 ) & 0x1fff ;
F_65 (printk(L_53,
iadev->reass_ram, iadev->rfL.pcq_rd, desc);
printk(L_54,
readw(iadev->reass_reg+PCQ_WR_PTR)&0xffff);)
if ( V_153 -> V_276 . V_288 == V_153 -> V_276 . V_291 )
V_153 -> V_276 . V_288 = V_153 -> V_276 . V_292 ;
else
V_153 -> V_276 . V_288 += 2 ;
F_16 ( V_153 -> V_276 . V_288 , V_153 -> V_280 + V_293 ) ;
V_283 = V_153 -> V_294 ;
V_283 += V_275 ;
if ( ! V_275 || ( V_275 > V_153 -> V_178 ) ||
( ( V_283 -> V_295 & 0xffff ) >= V_153 -> V_71 ) ) {
F_63 ( V_10 , V_275 ) ;
F_17 (printk(L_55, desc);)
return - 1 ;
}
V_42 = V_153 -> V_296 [ V_283 -> V_295 & 0xffff ] ;
if ( ! V_42 )
{
F_63 ( V_10 , V_275 ) ;
F_9 ( L_56 ) ;
return - 1 ;
}
V_63 = ( T_3 ) ( V_283 -> V_297 ) ;
if ( V_63 & ( V_298 | V_299 | V_300 ) )
{
F_66 ( & V_42 -> V_301 -> V_302 ) ;
F_17 (printk(L_57);)
if ( V_63 & V_298 ) {
F_17 (printk(L_58);)
}
else if ( V_63 & V_299 ) {
F_17 (printk(L_59);)
}
else {
F_17 (printk(L_60);)
}
goto V_303;
}
V_286 = ( V_283 -> V_304 << 16 ) | V_283 -> V_305 ;
V_287 = ( V_283 -> V_306 << 16 ) | V_283 -> V_307 ;
V_165 = V_287 - V_286 ;
if ( V_165 > V_153 -> V_180 ) {
F_9 ( L_61 , V_153 -> V_180 ) ;
F_66 ( & V_42 -> V_301 -> V_302 ) ;
goto V_303;
}
if ( ! ( V_34 = F_67 ( V_42 , V_165 , V_7 ) ) ) {
if ( V_42 -> V_59 < 32 )
F_9 ( L_62 ) ;
goto V_303;
}
F_68 ( V_34 , V_165 ) ;
F_35 ( V_34 ) -> V_42 = V_42 ;
F_69 ( V_34 ) = V_275 ;
F_70 ( & V_153 -> V_308 , V_34 ) ;
V_285 = V_153 -> V_309 . V_310 ;
V_285 -> V_311 = F_71 ( & V_153 -> V_312 -> V_10 , V_34 -> V_4 ,
V_165 , V_313 ) ;
V_285 -> V_314 = V_286 ;
V_285 -> V_315 = V_165 ;
V_285 -> V_316 = V_317 ;
if( ++ V_285 == V_153 -> V_309 . V_318 )
V_285 = V_153 -> V_309 . V_319 ;
V_153 -> V_309 . V_310 = V_285 ;
F_15 ( 1 ) ;
F_50 ( 1 , V_153 -> V_320 + V_321 ) ;
V_162: return 0 ;
V_303:
F_63 ( V_10 , V_275 ) ;
goto V_162;
}
static void F_72 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
T_3 V_63 ;
T_3 V_322 , V_32 ;
V_153 = F_31 ( V_10 ) ;
V_63 = F_7 ( V_153 -> V_280 + V_323 ) & 0xffff ;
F_10 (printk(L_63, status);)
if ( V_63 & V_324 )
{
V_322 = F_7 ( V_153 -> V_280 + V_325 ) & 0xffff ;
F_10 (printk(L_64, status);)
while( ! ( V_322 & V_326 ) )
{
F_64 ( V_10 ) ;
V_322 = F_7 ( V_153 -> V_280 + V_325 ) & 0xffff ;
}
V_153 -> V_327 = 1 ;
}
if ( V_63 & V_328 )
{
if ( V_153 -> V_327 ) {
V_153 -> V_329 = V_153 -> V_330 ;
V_153 -> V_331 = V_38 ;
V_153 -> V_327 = 0 ;
}
else if ( ( F_13 ( V_38 , V_153 -> V_331 + 50 ) ) &&
( ( V_153 -> V_330 - V_153 -> V_329 ) == 0 ) ) {
for ( V_32 = 1 ; V_32 <= V_153 -> V_178 ; V_32 ++ )
F_63 ( V_10 , V_32 ) ;
F_9 ( L_65 ) ;
F_16 ( ~ ( V_328 | V_332 ) , V_153 -> V_280 + V_333 ) ;
V_153 -> V_327 = 1 ;
}
F_10 (printk(L_66, status);)
}
if ( V_63 & V_332 )
{
F_10 (printk(L_67, status);)
F_62 ( V_10 ) ;
}
if ( V_63 & V_334 )
{
F_10 (printk(L_68, status);)
}
}
static void F_73 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
struct V_41 * V_42 ;
struct V_33 * V_34 ;
int V_275 ;
T_3 V_322 ;
struct V_284 * V_284 , * V_335 ;
T_7 V_336 ;
int V_165 ;
V_153 = F_31 ( V_10 ) ;
V_284 = V_153 -> V_309 . V_337 ;
V_336 = F_7 ( V_153 -> V_320 + V_338 ) & ( sizeof( struct V_284 ) * V_339 - 1 ) ;
V_335 = (struct V_284 * ) ( V_153 -> V_309 . V_319 + ( V_336 >> 4 ) ) ;
while( V_284 != V_335 )
{
V_34 = F_34 ( & V_153 -> V_308 ) ;
if ( ! V_34 )
goto V_340;
V_275 = F_69 ( V_34 ) ;
F_63 ( V_10 , V_275 ) ;
if ( ! ( V_165 = V_34 -> V_165 ) )
{
F_9 ( L_69 ) ;
F_36 ( V_34 ) ;
}
else
{
struct V_341 * V_342 ;
T_3 V_263 ;
struct V_13 * V_13 ;
F_74 ( & V_153 -> V_312 -> V_10 , V_153 -> V_309 . V_310 -> V_311 ,
V_165 , V_313 ) ;
V_42 = F_35 ( V_34 ) -> V_42 ;
if ( ! V_42 ) {
F_9 ( L_70 ) ;
F_36 ( V_34 ) ;
goto V_340;
}
V_13 = F_29 ( V_42 ) ;
if ( V_13 == NULL )
{
F_66 ( & V_42 -> V_301 -> V_302 ) ;
F_75 ( V_42 , V_34 -> V_343 ) ;
F_36 ( V_34 ) ;
goto V_340;
}
V_342 = (struct V_341 * ) ( ( T_5 * ) V_34 -> V_4 +
V_34 -> V_165 - sizeof( * V_342 ) ) ;
V_263 = F_76 ( V_342 -> V_263 ) ;
if ( ( V_263 > V_153 -> V_180 ) || ( V_263 >
( V_34 -> V_165 - sizeof( struct V_341 ) ) ) )
{
F_66 ( & V_42 -> V_301 -> V_302 ) ;
F_17 (printk(L_71,
length, skb->len);)
F_75 ( V_42 , V_34 -> V_343 ) ;
F_36 ( V_34 ) ;
goto V_340;
}
F_77 ( V_34 , V_263 ) ;
F_78 (printk(L_72, skb->len);
xdump(skb->data, skb->len, L_73);
printk(L_74);)
F_65 (printk(L_75);)
V_42 -> V_344 ( V_42 , V_34 ) ;
F_66 ( & V_42 -> V_301 -> V_345 ) ;
V_153 -> V_330 ++ ;
}
V_340:
if ( ++ V_284 == V_153 -> V_309 . V_318 )
V_284 = V_153 -> V_309 . V_319 ;
}
V_153 -> V_309 . V_337 = V_284 ;
if ( ! V_153 -> V_327 ) {
V_322 = F_7 ( V_153 -> V_280 + V_325 ) & 0xffff ;
if ( ! ( V_322 & V_346 ) ) {
V_322 = F_7 ( V_153 -> V_280 + V_333 ) & 0xffff ;
F_50 ( V_322 & ~ ( V_328 | V_324 ) ,
V_153 -> V_280 + V_333 ) ;
V_153 -> V_327 ++ ;
}
}
}
static int F_79 ( struct V_41 * V_42 )
{
T_2 * V_153 ;
T_3 T_13 * V_347 ;
T_3 T_13 * V_348 ;
F_10 (printk(L_76, vcc->vpi, vcc->vci);)
if ( V_42 -> V_54 . V_349 . V_56 == V_350 ) return 0 ;
V_153 = F_31 ( V_42 -> V_10 ) ;
if ( V_42 -> V_54 . V_349 . V_56 == V_57 ) {
if ( V_153 -> V_187 & V_189 ) {
F_9 ( L_77 ) ;
return - V_290 ;
}
}
V_347 = V_153 -> V_112 + V_351 * V_153 -> V_114 ;
V_347 += V_42 -> V_59 ;
* V_347 = V_42 -> V_59 << 6 ;
if ( ( V_42 -> V_54 . V_349 . V_56 == V_57 ) ||
( V_42 -> V_54 . V_55 . V_56 == V_57 ) )
{
T_9 V_80 ;
F_24 ( V_153 , & V_80 ) ;
F_25 ( V_153 , & V_80 , V_42 , 0 ) ;
}
else {
V_348 = V_153 -> V_112 + V_113 * V_153 -> V_114 ;
V_348 += V_42 -> V_59 ;
* V_348 = V_115 ;
}
if ( V_153 -> V_296 [ V_42 -> V_59 ] )
F_9 (KERN_CRIT DEV_LABEL L_78 ,
vcc->dev->number, vcc->vci) ;
V_153 -> V_296 [ V_42 -> V_59 ] = V_42 ;
return 0 ;
}
static int F_80 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
struct V_282 T_13 * V_283 ;
unsigned long V_352 = 0 ;
void * V_353 ;
struct V_354 * V_354 ;
T_4 * V_347 ;
T_4 * V_355 ;
int V_32 , V_356 , V_357 ;
T_3 V_358 ;
T_3 * V_359 ;
V_153 = F_31 ( V_10 ) ;
V_353 = F_81 ( & V_153 -> V_312 -> V_10 , V_360 ,
& V_153 -> V_361 , V_362 ) ;
if ( ! V_353 ) {
F_9 (KERN_ERR DEV_LABEL L_79 ) ;
goto V_363;
}
V_153 -> V_309 . V_319 = (struct V_284 * ) V_353 ;
V_153 -> V_309 . V_337 = V_153 -> V_309 . V_319 ;
V_153 -> V_309 . V_310 = V_153 -> V_309 . V_319 ;
V_153 -> V_309 . V_318 = (struct V_284 * ) ( ( unsigned long ) V_353 + sizeof( struct V_284 ) * V_339 ) ;
F_50 ( V_153 -> V_361 & 0xfffff000 ,
V_153 -> V_320 + V_338 ) ;
F_47 (printk(L_80,
iadev->dma+IPHASE5575_TX_LIST_ADDR,
readl(iadev->dma + IPHASE5575_TX_LIST_ADDR));
printk(L_81,
iadev->dma+IPHASE5575_RX_LIST_ADDR,
readl(iadev->dma + IPHASE5575_RX_LIST_ADDR));)
F_16 ( 0xffff , V_153 -> V_280 + V_333 ) ;
F_16 ( 0 , V_153 -> V_280 + V_364 ) ;
F_16 ( V_365 , V_153 -> V_280 + V_366 ) ;
F_16 ( V_367 >> 16 , V_153 -> V_280 + V_368 ) ;
F_16 ( V_153 -> V_180 , V_153 -> V_280 + V_369 ) ;
V_153 -> V_294 = V_153 -> V_112 + V_367 * V_153 -> V_114 ;
V_283 = V_153 -> V_294 ;
F_82 ( V_283 , 0 , sizeof( * V_283 ) ) ;
V_283 ++ ;
V_352 = V_153 -> V_185 ;
for( V_32 = 1 ; V_32 <= V_153 -> V_178 ; V_32 ++ )
{
F_82 ( V_283 , 0 , sizeof( * V_283 ) ) ;
V_283 -> V_304 = V_352 >> 16 ;
V_283 -> V_305 = V_352 & 0x0000ffff ;
V_283 ++ ;
V_352 += V_153 -> V_180 ;
}
F_47 (printk(L_82, buf_desc_ptr);)
V_32 = V_370 * V_153 -> V_114 ;
F_16 ( V_32 >> 16 , V_153 -> V_280 + V_371 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_372 ) ;
F_16 ( V_32 + V_153 -> V_178 * sizeof( T_3 ) ,
V_153 -> V_280 + V_373 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_374 ) ;
F_16 ( V_32 + V_153 -> V_178 * sizeof( T_3 ) ,
V_153 -> V_280 + V_281 ) ;
V_358 = F_61 ( V_153 -> V_280 + V_372 ) ;
V_359 = ( T_3 * ) ( V_153 -> V_112 + V_358 ) ;
for( V_32 = 1 ; V_32 <= V_153 -> V_178 ; V_32 ++ )
{
* V_359 = ( T_3 ) V_32 ;
V_359 ++ ;
}
F_47 (printk(L_83, freeq_start);)
V_32 = ( V_375 * V_153 -> V_114 ) & 0xffff ;
F_16 ( V_32 , V_153 -> V_280 + V_376 ) ;
F_16 ( V_32 + V_153 -> V_71 * sizeof( T_3 ) , V_153 -> V_280 + V_377 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_293 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_289 ) ;
V_32 = ( V_378 * V_153 -> V_114 ) & 0xffff ;
F_16 ( V_32 , V_153 -> V_280 + V_379 ) ;
F_16 ( V_32 + V_380 * sizeof( V_381 ) ,
V_153 -> V_280 + V_382 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_383 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_384 ) ;
V_153 -> V_276 . V_279 = F_61 ( V_153 -> V_280 + V_372 ) & 0xffff ;
V_153 -> V_276 . V_278 = F_61 ( V_153 -> V_280 + V_373 ) & 0xffff ;
V_153 -> V_276 . V_385 = F_61 ( V_153 -> V_280 + V_374 ) & 0xffff ;
V_153 -> V_276 . V_277 = F_61 ( V_153 -> V_280 + V_281 ) & 0xffff ;
V_153 -> V_276 . V_292 = F_61 ( V_153 -> V_280 + V_376 ) & 0xffff ;
V_153 -> V_276 . V_291 = F_61 ( V_153 -> V_280 + V_377 ) & 0xffff ;
V_153 -> V_276 . V_288 = F_61 ( V_153 -> V_280 + V_293 ) & 0xffff ;
V_153 -> V_276 . V_386 = F_61 ( V_153 -> V_280 + V_289 ) & 0xffff ;
F_47 (printk(L_84,
iadev->rfL.pcq_st, iadev->rfL.pcq_ed, iadev->rfL.pcq_rd,
iadev->rfL.pcq_wr);)
V_32 = V_113 * V_153 -> V_114 ;
F_16 ( ( V_32 >> 3 ) , V_153 -> V_280 + V_387 ) ;
V_355 = ( T_4 * ) ( V_153 -> V_112 + V_32 ) ;
V_356 = V_388 * V_153 -> V_114 ;
for( V_32 = 0 ; V_32 < V_356 ; V_32 ++ )
* V_355 ++ = V_115 ;
V_32 = 8 * 1024 ;
V_357 = 0 ;
while ( V_32 != V_153 -> V_71 ) {
V_32 /= 2 ;
V_357 ++ ;
}
V_32 = V_351 * V_153 -> V_114 ;
F_16 ( ( ( V_32 >> 3 ) & 0xfff8 ) | V_357 , V_153 -> V_280 + V_389 ) ;
V_347 = ( T_4 * ) ( V_153 -> V_112 + V_351 * V_153 -> V_114 ) ;
V_356 = V_390 * V_153 -> V_114 ;
for( V_32 = 0 ; V_32 < V_356 ; V_32 ++ )
{
* V_347 = ( V_32 << 6 ) | 15 ;
V_347 ++ ;
}
V_32 = V_117 * V_153 -> V_114 ;
F_16 ( V_32 >> 3 , V_153 -> V_280 + V_391 ) ;
V_32 = V_117 * V_153 -> V_114 ;
V_354 = (struct V_354 * ) ( V_153 -> V_112 + V_32 ) ;
V_356 = V_388 * V_153 -> V_114 ;
memset ( ( char * ) V_354 , 0 , V_356 * sizeof( * V_354 ) ) ;
for( V_32 = 0 ; V_32 < V_356 ; V_32 ++ ) {
V_354 -> V_88 = 0x0003 ;
V_354 -> V_97 = 0x5eb1 ;
V_354 ++ ;
}
F_16 ( 0xff00 , V_153 -> V_280 + V_392 ) ;
F_16 ( 0 , V_153 -> V_280 + V_393 ) ;
F_16 ( 0x1 , V_153 -> V_280 + V_394 ) ;
F_16 ( 0xF6F8 , V_153 -> V_280 + V_395 ) ;
V_32 = ( V_356 >> 6 ) & 0xFF ;
V_356 += 2 * ( V_356 - 1 ) ;
V_32 |= ( ( V_356 << 2 ) & 0xFF00 ) ;
F_16 ( V_32 , V_153 -> V_280 + V_396 ) ;
for( V_32 = 0 ; V_32 < V_153 -> V_40 ; V_32 ++ )
V_153 -> V_19 [ V_32 ] . V_20 = 0 ;
F_61 ( V_153 -> V_280 + V_323 ) ;
F_16 ( ~ ( V_328 | V_324 ) , V_153 -> V_280 + V_333 ) ;
F_83 ( & V_153 -> V_308 ) ;
V_153 -> V_397 = NULL ;
V_153 -> V_296 = F_84 ( 4 * V_153 -> V_71 , V_362 ) ;
if ( ! V_153 -> V_296 ) {
F_9 (KERN_ERR DEV_LABEL L_85 ,
dev->number) ;
goto V_398;
}
V_153 -> V_327 = 1 ;
V_153 -> V_330 = 0 ;
F_16 ( V_399 , V_153 -> V_280 + V_364 ) ;
return 0 ;
V_398:
F_85 ( & V_153 -> V_312 -> V_10 , V_360 , V_153 -> V_309 . V_319 ,
V_153 -> V_361 ) ;
V_363:
return - V_8 ;
}
static void F_86 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
unsigned short V_63 ;
unsigned long V_159 ;
V_153 = F_31 ( V_10 ) ;
V_63 = F_7 ( V_153 -> V_15 + V_76 ) ;
if ( V_63 & V_73 ) {
F_10 (printk(L_86);)
F_87 ( & V_153 -> V_400 , V_159 ) ;
F_40 ( V_153 ) ;
F_88 ( & V_153 -> V_400 , V_159 ) ;
F_16 ( V_73 , V_153 -> V_15 + V_76 ) ;
if ( V_153 -> V_401 )
F_89 ( & V_153 -> V_402 ) ;
}
if ( V_63 & V_74 )
{
F_10 (printk(L_87);)
}
}
static void F_90 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
struct V_284 * V_284 , * V_335 ;
struct V_33 * V_34 ;
struct V_41 * V_42 ;
struct V_13 * V_21 ;
T_7 V_336 ;
unsigned long V_159 ;
V_153 = F_31 ( V_10 ) ;
F_87 ( & V_153 -> V_400 , V_159 ) ;
V_284 = V_153 -> V_403 . V_337 ;
V_336 = F_7 ( V_153 -> V_320 + V_404 ) &
( sizeof( struct V_284 ) * V_339 - 1 ) ;
V_335 = (struct V_284 * ) ( V_153 -> V_403 . V_319 + ( V_336 >> 4 ) ) ;
while ( V_284 != V_335 )
{
V_34 = F_34 ( & V_153 -> V_405 ) ;
if ( ! V_34 ) break;
if ( ! ( ( V_284 - V_153 -> V_403 . V_319 ) % ( 2 * sizeof( struct V_284 ) ) ) ) {
F_74 ( & V_153 -> V_312 -> V_10 , V_284 -> V_311 , V_34 -> V_165 ,
V_406 ) ;
}
V_42 = F_35 ( V_34 ) -> V_42 ;
if ( ! V_42 ) {
F_9 ( L_88 ) ;
F_88 ( & V_153 -> V_400 , V_159 ) ;
F_36 ( V_34 ) ;
return;
}
V_21 = F_29 ( V_42 ) ;
if ( ! V_21 ) {
F_9 ( L_89 ) ;
F_88 ( & V_153 -> V_400 , V_159 ) ;
F_36 ( V_34 ) ;
return;
}
if ( V_42 -> V_54 . V_55 . V_23 >= V_153 -> V_24 ) {
if ( ( V_42 -> V_164 ) && ( V_34 -> V_165 != 0 ) )
{
V_42 -> V_164 ( V_42 , V_34 ) ;
}
else {
F_36 ( V_34 ) ;
}
}
else {
F_11 ( V_34 ) |= V_407 ;
F_70 ( & V_21 -> V_163 , V_34 ) ;
}
F_10 (printk(L_90, skb);)
if ( ++ V_284 == V_153 -> V_403 . V_318 )
V_284 = V_153 -> V_403 . V_319 ;
}
V_153 -> V_403 . V_337 = V_284 ;
F_88 ( & V_153 -> V_400 , V_159 ) ;
}
static int F_91 ( struct V_41 * V_42 )
{
struct V_13 * V_13 ;
T_2 * V_153 ;
struct V_48 * V_408 ;
struct V_51 * V_409 ;
int V_410 ;
F_10 (printk(L_91, vcc->vci);)
if ( V_42 -> V_54 . V_55 . V_56 == V_350 ) return 0 ;
V_153 = F_31 ( V_42 -> V_10 ) ;
if ( V_153 -> V_187 & V_189 ) {
if ( V_42 -> V_54 . V_55 . V_56 == V_57 ) {
F_9 ( L_77 ) ;
return - V_290 ;
}
if ( V_42 -> V_54 . V_55 . V_56 == V_411 ) {
F_9 ( L_92 ) ;
return - V_290 ;
}
}
V_13 = F_29 ( V_42 ) ;
memset ( ( V_99 ) V_13 , 0 , sizeof( * V_13 ) ) ;
if ( V_42 -> V_54 . V_55 . V_412 >
( V_153 -> V_176 - sizeof( struct V_341 ) ) ) {
F_9 ( L_93 ,
V_42 -> V_54 . V_55 . V_412 , V_153 -> V_176 ) ;
V_42 -> V_413 = NULL ;
F_41 ( V_13 ) ;
return - V_290 ;
}
V_13 -> V_22 = 0 ;
V_13 -> V_414 = 1 ;
if ( V_42 -> V_54 . V_55 . V_140 == V_415 )
V_42 -> V_54 . V_55 . V_23 = V_153 -> V_82 ;
else if ( ( V_42 -> V_54 . V_55 . V_140 == 0 ) && ( V_42 -> V_54 . V_55 . V_23 <= 0 ) )
V_42 -> V_54 . V_55 . V_23 = V_153 -> V_82 ;
else if ( ( V_42 -> V_54 . V_55 . V_140 > V_42 -> V_54 . V_55 . V_23 ) && ( V_42 -> V_54 . V_55 . V_140 > 0 ) )
V_42 -> V_54 . V_55 . V_23 = V_42 -> V_54 . V_55 . V_140 ;
if ( V_42 -> V_54 . V_55 . V_23 > V_153 -> V_82 )
V_42 -> V_54 . V_55 . V_23 = V_153 -> V_82 ;
V_13 -> V_23 = V_42 -> V_54 . V_55 . V_23 ;
if ( V_13 -> V_23 > ( V_153 -> V_82 / 6 ) ) V_13 -> V_37 = V_416 / 10 ;
else if ( V_13 -> V_23 > ( V_153 -> V_82 / 130 ) ) V_13 -> V_37 = V_416 ;
else if ( V_13 -> V_23 <= 170 ) V_13 -> V_37 = 16 * V_416 ;
else V_13 -> V_37 = 2700 * V_416 / V_13 -> V_23 ;
if ( V_13 -> V_23 < V_153 -> V_24 )
F_83 ( & V_13 -> V_163 ) ;
if ( V_13 -> V_23 < V_153 -> V_24 ) {
struct V_417 * V_418 = F_92 ( V_42 ) ;
if ( V_42 -> V_54 . V_55 . V_412 != 0 ) {
if ( V_13 -> V_23 > 60000 )
V_418 -> V_419 = V_42 -> V_54 . V_55 . V_412 * 5 ;
else if ( V_13 -> V_23 > 2000 )
V_418 -> V_419 = V_42 -> V_54 . V_55 . V_412 * 4 ;
else
V_418 -> V_419 = V_42 -> V_54 . V_55 . V_412 * 3 ;
}
else
V_418 -> V_419 = 24576 ;
}
V_408 = (struct V_48 * ) V_153 -> V_50 ;
V_409 = (struct V_51 * ) V_153 -> V_53 ;
V_408 += V_42 -> V_59 ;
V_409 += V_42 -> V_59 ;
memset ( ( V_99 ) V_408 , 0 , sizeof( * V_408 ) ) ;
memset ( ( V_99 ) V_409 , 0 , sizeof( * V_409 ) ) ;
V_409 -> V_420 = ( V_42 -> V_59 >> 12 ) & 0x000f ;
V_409 -> V_421 = ( V_42 -> V_59 & 0x0fff ) << 4 ;
if ( V_42 -> V_54 . V_55 . V_56 == V_422 )
{
V_408 -> type = V_423 ;
V_408 -> V_63 = V_424 ;
V_408 -> V_425 = F_18 ( V_153 -> V_82 ) ;
if ( V_42 -> V_54 . V_55 . V_23 > 0 )
V_408 -> V_425 = F_18 ( V_42 -> V_54 . V_55 . V_23 ) ;
F_93 (printk(L_94,
vcc->qos.txtp.max_pcr,vc->acr);)
}
else if ( V_42 -> V_54 . V_55 . V_56 == V_57 )
{ T_9 V_80 ;
F_8 (printk(L_95);)
F_24 ( V_153 , & V_80 ) ;
if ( V_42 -> V_54 . V_55 . V_23 > 0 )
V_80 . V_23 = V_42 -> V_54 . V_55 . V_23 ;
if ( V_42 -> V_54 . V_55 . V_426 > 0 ) {
int V_427 = V_153 -> V_122 + V_153 -> V_428 + V_42 -> V_54 . V_55 . V_426 ;
if ( V_427 > V_153 -> V_82 )
return - V_143 ;
V_80 . V_83 = V_42 -> V_54 . V_55 . V_426 ;
V_153 -> V_122 += V_42 -> V_54 . V_55 . V_426 ;
}
else V_80 . V_83 = 0 ;
if ( V_42 -> V_54 . V_55 . V_84 )
V_80 . V_84 = V_42 -> V_54 . V_55 . V_84 ;
if ( V_42 -> V_54 . V_55 . V_85 )
V_80 . V_85 = V_42 -> V_54 . V_55 . V_85 ;
if ( V_42 -> V_54 . V_55 . V_86 )
V_80 . V_86 = V_42 -> V_54 . V_55 . V_86 ;
if ( V_42 -> V_54 . V_55 . V_87 )
V_80 . V_87 = V_42 -> V_54 . V_55 . V_87 ;
if ( V_42 -> V_54 . V_55 . V_88 )
V_80 . V_88 = V_42 -> V_54 . V_55 . V_88 ;
if ( V_42 -> V_54 . V_55 . V_429 )
V_80 . V_89 = V_42 -> V_54 . V_55 . V_89 ;
if ( V_42 -> V_54 . V_55 . V_430 )
V_80 . V_90 = V_42 -> V_54 . V_55 . V_90 ;
if ( V_42 -> V_54 . V_55 . V_431 )
V_80 . V_92 = V_42 -> V_54 . V_55 . V_92 ;
if ( V_42 -> V_54 . V_55 . V_432 )
V_80 . V_91 = V_42 -> V_54 . V_55 . V_91 ;
if ( V_80 . V_84 > V_80 . V_23 )
V_80 . V_84 = V_80 . V_23 ;
F_8 (printk(L_96,
srv_p.pcr, srv_p.mcr);)
F_25 ( V_153 , & V_80 , V_42 , 1 ) ;
} else if ( V_42 -> V_54 . V_55 . V_56 == V_411 ) {
if ( V_153 -> V_187 & V_189 ) {
F_9 ( L_92 ) ;
return - V_290 ;
}
if ( V_42 -> V_54 . V_55 . V_140 > V_153 -> V_82 ) {
F_28 (printk(L_97);)
return - 1 ;
}
V_408 -> type = V_433 ;
V_408 -> V_63 = V_424 ;
if ( ( V_410 = F_27 ( V_153 , V_42 ) ) < 0 ) {
return V_410 ;
}
} else {
F_9 ( L_98 ) ;
}
V_153 -> V_58 [ V_42 -> V_59 ] -> V_60 |= V_120 ;
F_10 (printk(L_99);)
return 0 ;
}
static int F_94 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
struct V_434 * V_283 ;
unsigned int V_435 ;
void * V_353 ;
int V_32 ;
T_3 V_436 ;
T_3 * V_437 ;
T_3 V_438 ;
T_3 * V_439 ;
struct V_48 * V_408 ;
struct V_51 * V_409 ;
T_3 V_440 ;
T_8 V_357 ;
V_153 = F_31 ( V_10 ) ;
F_95 ( & V_153 -> V_400 ) ;
F_47 (printk(L_100,
readw(iadev->seg_reg+SEG_MASK_REG));)
V_353 = F_81 ( & V_153 -> V_312 -> V_10 , V_360 ,
& V_153 -> V_441 , V_362 ) ;
if ( ! V_353 ) {
F_9 (KERN_ERR DEV_LABEL L_79 ) ;
goto V_363;
}
V_153 -> V_403 . V_319 = (struct V_284 * ) V_353 ;
V_153 -> V_403 . V_337 = V_153 -> V_403 . V_319 ;
V_153 -> V_403 . V_310 = V_153 -> V_403 . V_319 ;
V_153 -> V_403 . V_318 = (struct V_284 * ) ( ( unsigned long ) V_353 + sizeof( struct V_284 ) * V_339 ) ;
F_50 ( V_153 -> V_441 & 0xfffff000 ,
V_153 -> V_320 + V_404 ) ;
F_16 ( 0xffff , V_153 -> V_15 + V_75 ) ;
F_16 ( 0 , V_153 -> V_15 + V_69 ) ;
F_16 ( V_442 , V_153 -> V_15 + V_443 ) ;
V_153 -> V_50 = V_153 -> V_18 + V_444 * V_153 -> V_114 ;
V_153 -> V_53 = V_153 -> V_18 + V_445 * V_153 -> V_114 ;
V_153 -> V_70 = V_153 -> V_18 + V_446 * V_153 -> V_114 ;
F_16 ( V_447 , V_153 -> V_15 + V_448 ) ;
V_283 = (struct V_434 * ) ( V_153 -> V_18 + V_447 ) ;
memset ( ( V_99 ) V_283 , 0 , sizeof( * V_283 ) ) ;
V_283 ++ ;
V_435 = V_186 ;
for( V_32 = 1 ; V_32 <= V_153 -> V_40 ; V_32 ++ )
{
memset ( ( V_99 ) V_283 , 0 , sizeof( * V_283 ) ) ;
V_283 -> V_297 = V_449 ;
V_283 -> V_304 = V_435 >> 16 ;
V_283 -> V_305 = V_435 & 0x0000ffff ;
V_283 ++ ;
V_435 += V_153 -> V_176 ;
}
V_153 -> V_450 = F_96 ( V_153 -> V_40 ,
sizeof( * V_153 -> V_450 ) ,
V_362 ) ;
if ( ! V_153 -> V_450 ) {
F_9 (KERN_ERR DEV_LABEL L_101 ) ;
goto V_398;
}
for ( V_32 = 0 ; V_32 < V_153 -> V_40 ; V_32 ++ )
{
struct V_341 * V_451 ;
V_451 = F_4 ( sizeof( * V_451 ) , V_362 | V_452 ) ;
if( ! V_451 ) {
F_9 (KERN_ERR DEV_LABEL L_102 ) ;
goto V_453;
}
V_153 -> V_450 [ V_32 ] . V_451 = V_451 ;
V_153 -> V_450 [ V_32 ] . V_287 = F_71 ( & V_153 -> V_312 -> V_10 ,
V_451 ,
sizeof( * V_451 ) ,
V_406 ) ;
}
V_153 -> V_19 = F_96 ( V_153 -> V_40 ,
sizeof( * V_153 -> V_19 ) ,
V_362 ) ;
if ( ! V_153 -> V_19 ) {
F_9 (KERN_ERR DEV_LABEL L_101 ) ;
goto V_454;
}
V_32 = V_455 * V_153 -> V_114 ;
F_16 ( V_32 >> 16 , V_153 -> V_15 + V_456 ) ;
F_16 ( V_32 , V_153 -> V_15 + V_272 ) ;
F_16 ( V_32 , V_153 -> V_15 + V_457 ) ;
F_16 ( V_32 + V_153 -> V_40 * sizeof( T_3 ) , V_153 -> V_15 + V_16 ) ;
V_153 -> V_17 = V_32 + V_153 -> V_40 * sizeof( T_3 ) ;
F_16 ( V_32 + 2 * V_153 -> V_40 * sizeof( T_3 ) ,
V_153 -> V_15 + V_273 ) ;
V_436 = F_61 ( V_153 -> V_15 + V_272 ) ;
V_437 = ( T_3 * ) ( V_153 -> V_18 + V_436 ) ;
for( V_32 = 1 ; V_32 <= V_153 -> V_40 ; V_32 ++ )
{
* V_437 = ( T_3 ) V_32 ;
V_437 ++ ;
}
V_32 = V_458 * V_153 -> V_114 ;
F_16 ( V_32 , V_153 -> V_15 + V_459 ) ;
F_16 ( V_32 + 2 * V_153 -> V_40 * sizeof( T_3 ) ,
V_153 -> V_15 + V_460 ) ;
F_16 ( V_32 , V_153 -> V_15 + V_461 ) ;
F_16 ( V_32 , V_153 -> V_15 + V_462 ) ;
V_153 -> V_28 . V_463 = F_61 ( V_153 -> V_15 + V_459 ) & 0xffff ;
V_153 -> V_28 . V_464 = F_61 ( V_153 -> V_15 + V_460 ) & 0xffff ;
V_153 -> V_28 . V_465 = F_61 ( V_153 -> V_15 + V_462 ) & 0xffff ;
V_153 -> V_28 . V_30 = F_61 ( V_153 -> V_15 + V_272 ) & 0xffff ;
V_153 -> V_28 . V_29 = F_61 ( V_153 -> V_15 + V_273 ) & 0xffff ;
V_153 -> V_28 . V_39 = F_61 ( V_153 -> V_15 + V_457 ) & 0xffff ;
V_438 = F_61 ( V_153 -> V_15 + V_459 ) ;
V_439 = ( T_3 * ) ( V_153 -> V_18 + V_438 ) ;
for( V_32 = 1 ; V_32 <= V_153 -> V_40 ; V_32 ++ )
{
* V_439 = ( T_3 ) 0 ;
V_439 ++ ;
}
F_47 (printk(L_103);)
#if 1
F_16 ( 0 , V_153 -> V_15 + V_466 ) ;
#else
V_440 = ( V_153 -> V_18 + V_147 * V_153 -> V_114 ) >> 17 ;
F_47 (printk(L_104, tmp16);)
F_16 ( V_440 , V_153 -> V_15 + V_466 ) ;
#endif
F_47 (printk(L_105,
readw(iadev->seg_reg+CBR_PTR_BASE));)
V_440 = ( V_147 * V_153 -> V_114 ) >> 1 ;
F_16 ( V_440 , V_153 -> V_15 + V_467 ) ;
F_47 (printk(L_106, tmp16,
readw(iadev->seg_reg+CBR_TAB_BEG));)
F_16 ( V_440 , V_153 -> V_15 + V_468 + 1 ) ;
V_440 = ( V_147 * V_153 -> V_114 + V_153 -> V_71 * 6 - 2 ) >> 1 ;
F_16 ( V_440 , V_153 -> V_15 + V_468 ) ;
F_47 (printk(L_107,
iadev->seg_reg, readw(iadev->seg_reg+CBR_PTR_BASE));)
F_47 (printk(L_108,
readw(iadev->seg_reg+CBR_TAB_BEG), readw(iadev->seg_reg+CBR_TAB_END),
readw(iadev->seg_reg+CBR_TAB_END+1));)
F_82 ( V_153 -> V_18 + V_147 * V_153 -> V_114 ,
0 , V_153 -> V_71 * 6 ) ;
V_153 -> V_142 = V_153 -> V_145 = V_153 -> V_71 * 3 ;
V_153 -> V_146 = 0 ;
V_153 -> V_141 = V_469 / V_153 -> V_145 ;
V_153 -> V_148 = 0 ;
V_357 = 0 ;
V_32 = 8 * 1024 ;
while ( V_32 != V_153 -> V_71 ) {
V_32 /= 2 ;
V_357 ++ ;
}
V_32 = V_444 * V_153 -> V_114 ;
F_16 ( V_357 | ( ( V_32 >> 8 ) & 0xfff8 ) , V_153 -> V_15 + V_470 ) ;
V_32 = V_445 * V_153 -> V_114 ;
F_16 ( ( V_32 >> 8 ) & 0xfffe , V_153 -> V_15 + V_471 ) ;
V_32 = V_472 * V_153 -> V_114 ;
F_16 ( ( V_32 & 0xffff ) >> 11 , V_153 -> V_15 + V_473 ) ;
V_32 = V_474 * V_153 -> V_114 ;
F_16 ( ( V_32 >> 7 ) & 0xffff , V_153 -> V_15 + V_475 ) ;
memset ( ( V_99 ) ( V_153 -> V_18 + V_472 * V_153 -> V_114 ) ,
0 , V_153 -> V_71 * 8 ) ;
V_32 = V_446 * V_153 -> V_114 ;
F_16 ( ( V_32 >> 11 ) & 0xffff , V_153 -> V_15 + V_476 ) ;
V_32 = V_477 * V_153 -> V_114 ;
F_16 ( ( V_32 >> 7 ) & 0xffff , V_153 -> V_15 + V_478 ) ;
V_32 = V_446 * V_153 -> V_114 ;
memset ( ( V_99 ) ( V_153 -> V_18 + V_32 ) , 0 , V_153 -> V_71 * 4 ) ;
V_408 = (struct V_48 * ) V_153 -> V_50 ;
V_409 = (struct V_51 * ) V_153 -> V_53 ;
V_153 -> V_58 = F_96 ( V_153 -> V_71 ,
sizeof( * V_153 -> V_58 ) ,
V_362 ) ;
if ( ! V_153 -> V_58 ) {
F_9 ( L_109 ) ;
goto V_479;
}
for( V_32 = 0 ; V_32 < V_153 -> V_71 ; V_32 ++ )
{
memset ( ( V_99 ) V_408 , 0 , sizeof( * V_408 ) ) ;
memset ( ( V_99 ) V_409 , 0 , sizeof( * V_409 ) ) ;
V_153 -> V_58 [ V_32 ] = F_4 ( sizeof( struct V_480 ) ,
V_362 ) ;
if ( ! V_153 -> V_58 [ V_32 ] )
goto V_481;
V_153 -> V_58 [ V_32 ] -> V_67 = 0 ;
V_153 -> V_58 [ V_32 ] -> V_68 = 0 ;
V_153 -> V_58 [ V_32 ] -> V_60 = V_482 ;
V_408 ++ ;
V_409 ++ ;
}
if ( V_153 -> V_187 & V_189 ) {
F_16 ( V_483 , V_153 -> V_15 + V_484 ) ;
F_16 ( ( V_150 | ( 0x23 << 2 ) ) , V_153 -> V_15 + V_152 ) ;
}
else {
F_16 ( F_18 ( V_153 -> V_82 ) , V_153 -> V_15 + V_484 ) ;
F_16 ( ( V_150 | V_151 | ( 0x23 << 2 ) ) , V_153 -> V_15 + V_152 ) ;
}
F_16 ( 0 , V_153 -> V_15 + V_485 ) ;
F_16 ( 0 , V_153 -> V_15 + V_486 ) ;
F_16 ( 0xaa00 , V_153 -> V_15 + V_487 ) ;
V_153 -> V_401 = 0 ;
F_97 ( & V_153 -> V_402 ) ;
F_97 ( & V_153 -> V_488 ) ;
F_83 ( & V_153 -> V_405 ) ;
F_1 ( & V_153 -> V_27 ) ;
F_16 ( V_489 , V_153 -> V_15 + V_490 ) ;
F_83 ( & V_153 -> V_157 ) ;
F_16 ( V_491 , V_153 -> V_15 + V_492 ) ;
F_16 ( V_72 , V_153 -> V_15 + V_69 ) ;
F_61 ( V_153 -> V_15 + V_76 ) ;
F_16 ( ~ ( V_73 | V_74 ) , V_153 -> V_15 + V_75 ) ;
F_16 ( V_73 , V_153 -> V_15 + V_76 ) ;
V_153 -> V_493 = 0 ;
V_153 -> V_24 = V_153 -> V_82 / 3 ;
return 0 ;
V_481:
while ( -- V_32 >= 0 )
F_41 ( V_153 -> V_58 [ V_32 ] ) ;
F_41 ( V_153 -> V_58 ) ;
V_479:
F_41 ( V_153 -> V_19 ) ;
V_454:
V_32 = V_153 -> V_40 ;
V_453:
while ( -- V_32 >= 0 ) {
struct V_494 * V_275 = V_153 -> V_450 + V_32 ;
F_74 ( & V_153 -> V_312 -> V_10 , V_275 -> V_287 ,
sizeof( * V_275 -> V_451 ) , V_406 ) ;
F_41 ( V_275 -> V_451 ) ;
}
F_41 ( V_153 -> V_450 ) ;
V_398:
F_85 ( & V_153 -> V_312 -> V_10 , V_360 , V_153 -> V_403 . V_319 ,
V_153 -> V_441 ) ;
V_363:
return - V_8 ;
}
static T_14 F_98 ( int V_495 , void * V_496 )
{
struct V_274 * V_10 ;
T_2 * V_153 ;
unsigned int V_63 ;
int V_497 = 0 ;
V_10 = V_496 ;
V_153 = F_31 ( V_10 ) ;
while( ( V_63 = F_7 ( V_153 -> V_195 + V_498 ) & 0x7f ) )
{
V_497 = 1 ;
F_10 (printk(L_110, status);)
if ( V_63 & V_499 )
{
F_10 (printk(L_111, status);)
F_72 ( V_10 ) ;
}
if ( V_63 & V_500 )
{
F_50 ( V_500 , V_153 -> V_195 + V_498 ) ;
F_73 ( V_10 ) ;
}
if ( V_63 & V_501 )
{
F_10 (printk(L_112);)
F_86 ( V_10 ) ;
}
if ( V_63 & V_502 )
{
F_50 ( V_502 , V_153 -> V_195 + V_498 ) ;
F_90 ( V_10 ) ;
}
if ( V_63 & ( V_503 | V_504 | V_505 ) )
{
if ( V_63 & V_503 )
F_51 ( V_153 ) ;
}
}
return F_99 ( V_497 ) ;
}
static int F_100 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
int V_32 ;
T_8 V_506 ;
T_4 V_507 ;
V_153 = F_31 ( V_10 ) ;
V_506 = F_101 ( F_102 ( F_7 (
V_153 -> V_195 + V_508 ) ) ) ;
V_507 = F_103 ( F_104 ( F_7 ( V_153 -> V_195 + V_509 ) ) ) ;
F_47 (printk(L_113, mac1, mac2);)
for ( V_32 = 0 ; V_32 < V_510 ; V_32 ++ )
V_10 -> V_511 [ V_32 ] = V_506 >> ( 8 * ( V_510 - 1 - V_32 ) ) ;
for ( V_32 = 0 ; V_32 < V_512 ; V_32 ++ )
V_10 -> V_511 [ V_32 + V_510 ] = V_507 >> ( 8 * ( V_512 - 1 - V_32 ) ) ;
return 0 ;
}
static int F_105 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
int V_32 , error = 1 ;
unsigned int V_312 [ 64 ] ;
V_153 = F_31 ( V_10 ) ;
for( V_32 = 0 ; V_32 < 64 ; V_32 ++ )
if ( ( error = F_106 ( V_153 -> V_312 ,
V_32 * 4 , & V_312 [ V_32 ] ) ) != V_513 )
return error ;
F_50 ( 0 , V_153 -> V_195 + V_514 ) ;
for( V_32 = 0 ; V_32 < 64 ; V_32 ++ )
if ( ( error = F_107 ( V_153 -> V_312 ,
V_32 * 4 , V_312 [ V_32 ] ) ) != V_513 )
return error ;
F_15 ( 5 ) ;
return 0 ;
}
static int F_108 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
unsigned long V_515 ;
void T_13 * V_516 ;
unsigned short V_517 ;
int error , V_32 ;
F_47 (printk(L_114);)
V_10 -> V_518 . V_519 = 0 ;
V_10 -> V_518 . V_520 = V_521 ;
V_153 = F_31 ( V_10 ) ;
V_515 = F_109 ( V_153 -> V_312 , 0 ) ;
V_153 -> V_495 = V_153 -> V_312 -> V_495 ;
error = F_110 ( V_153 -> V_312 , V_522 , & V_517 ) ;
if ( error ) {
F_9 (KERN_ERR DEV_LABEL L_115 ,
dev->number,error) ;
return - V_290 ;
}
F_47 (printk(DEV_LABEL L_116,
dev->number, iadev->pci->revision, real_base, iadev->irq);)
V_153 -> V_523 = F_111 ( V_153 -> V_312 , 0 ) ;
if ( V_153 -> V_523 == 0x100000 ) {
V_153 -> V_71 = 4096 ;
V_10 -> V_518 . V_520 = V_524 ;
V_153 -> V_114 = 4 ;
}
else if ( V_153 -> V_523 == 0x40000 ) {
V_153 -> V_71 = 1024 ;
V_153 -> V_114 = 1 ;
}
else {
F_9 ( L_117 , V_153 -> V_523 ) ;
return - V_290 ;
}
F_47 (printk (DEV_LABEL L_118, iadev->pci_map_size);)
F_112 ( V_153 -> V_312 ) ;
F_15 ( 10 ) ;
V_516 = F_113 ( V_515 , V_153 -> V_523 ) ;
if ( ! V_516 )
{
F_9 ( V_525 L_119 ,
V_10 -> V_526 ) ;
return - V_8 ;
}
F_47 (printk(DEV_LABEL L_120,
dev->number, iadev->pci->revision, base, iadev->irq);)
V_153 -> V_527 = V_153 -> V_523 / 2 ;
V_153 -> V_515 = V_515 ;
V_153 -> V_516 = V_516 ;
V_153 -> V_195 = V_516 + V_528 ;
V_153 -> V_15 = V_516 + V_529 ;
V_153 -> V_280 = V_516 + V_530 ;
V_153 -> V_196 = V_516 + V_531 ;
V_153 -> V_320 = V_516 + V_531 ;
V_153 -> V_532 = V_516 + V_533 ;
V_153 -> V_18 = V_516 + V_534 ;
V_153 -> V_112 = V_516 + V_535 ;
F_47 (printk(L_121,
iadev->reg,iadev->seg_reg,iadev->reass_reg,
iadev->phy, iadev->ram, iadev->seg_ram,
iadev->reass_ram);)
error = F_100 ( V_10 ) ;
if ( error ) {
F_114 ( V_153 -> V_516 ) ;
return error ;
}
F_9 ( L_122 ) ;
for ( V_32 = 0 ; V_32 < V_536 ; V_32 ++ )
F_9 ( L_123 , V_32 ? L_124 : L_125 , V_10 -> V_511 [ V_32 ] ) ;
F_9 ( L_74 ) ;
if ( F_105 ( V_10 ) ) {
F_114 ( V_153 -> V_516 ) ;
F_9 ( L_126 ) ;
return 1 ;
}
return 0 ;
}
static void F_115 ( T_2 * V_153 ) {
if ( ! V_153 -> V_198 )
return;
V_153 -> V_537 += F_61 ( V_153 -> V_280 + V_538 ) & 0xffff ;
V_153 -> V_537 += ( F_61 ( V_153 -> V_280 + V_539 ) & 0xffff ) << 16 ;
V_153 -> V_540 += F_61 ( V_153 -> V_280 + V_541 ) & 0xffff ;
V_153 -> V_542 += F_61 ( V_153 -> V_280 + V_543 ) & 0xffff ;
V_153 -> V_544 += F_61 ( V_153 -> V_15 + V_545 ) & 0xffff ;
V_153 -> V_544 += ( F_61 ( V_153 -> V_15 + V_546 ) & 0xffff ) << 16 ;
return;
}
static void F_116 ( unsigned long V_547 ) {
unsigned long V_159 ;
static T_5 V_548 [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_5 V_32 ;
static T_8 V_549 ;
for ( V_32 = 0 ; V_32 < V_550 ; V_32 ++ ) {
if ( V_551 [ V_32 ] ) {
V_549 = F_7 ( V_551 [ V_32 ] -> V_195 + V_552 ) ;
if ( V_548 [ V_32 ] == 0 ) {
V_548 [ V_32 ] ++ ;
V_549 &= ( ~ V_553 ) ;
F_50 ( V_549 , V_551 [ V_32 ] -> V_195 + V_552 ) ;
F_115 ( V_551 [ V_32 ] ) ;
}
else {
V_548 [ V_32 ] = 0 ;
V_549 |= V_553 ;
F_50 ( V_549 , V_551 [ V_32 ] -> V_195 + V_552 ) ;
F_87 ( & V_551 [ V_32 ] -> V_400 , V_159 ) ;
if ( V_551 [ V_32 ] -> V_401 )
F_89 ( & V_551 [ V_32 ] -> V_402 ) ;
F_40 ( V_551 [ V_32 ] ) ;
F_88 ( & V_551 [ V_32 ] -> V_400 , V_159 ) ;
}
}
}
F_117 ( & V_554 , V_38 + V_416 / 4 ) ;
return;
}
static void F_118 ( struct V_274 * V_10 , unsigned char V_555 ,
unsigned long V_166 )
{
F_50 ( V_555 , F_31 ( V_10 ) -> V_196 + V_166 ) ;
}
static unsigned char F_119 ( struct V_274 * V_10 , unsigned long V_166 )
{
return F_7 ( F_31 ( V_10 ) -> V_196 + V_166 ) ;
}
static void F_120 ( T_2 * V_153 )
{
int V_32 ;
F_41 ( V_153 -> V_19 ) ;
for ( V_32 = 0 ; V_32 < V_153 -> V_71 ; V_32 ++ )
F_41 ( V_153 -> V_58 [ V_32 ] ) ;
F_41 ( V_153 -> V_58 ) ;
for ( V_32 = 0 ; V_32 < V_153 -> V_40 ; V_32 ++ ) {
struct V_494 * V_275 = V_153 -> V_450 + V_32 ;
F_74 ( & V_153 -> V_312 -> V_10 , V_275 -> V_287 ,
sizeof( * V_275 -> V_451 ) , V_406 ) ;
F_41 ( V_275 -> V_451 ) ;
}
F_41 ( V_153 -> V_450 ) ;
F_85 ( & V_153 -> V_312 -> V_10 , V_360 , V_153 -> V_403 . V_319 ,
V_153 -> V_441 ) ;
}
static void F_121 ( T_2 * V_153 )
{
F_41 ( V_153 -> V_296 ) ;
F_85 ( & V_153 -> V_312 -> V_10 , V_360 , V_153 -> V_309 . V_319 ,
V_153 -> V_361 ) ;
}
static int F_122 ( struct V_274 * V_10 )
{
T_2 * V_153 ;
int error ;
unsigned char V_196 ;
T_8 V_549 ;
F_10 (printk(L_127);)
V_153 = F_31 ( V_10 ) ;
if ( F_123 ( V_153 -> V_495 , & F_98 , V_556 , V_525 , V_10 ) ) {
F_9 (KERN_ERR DEV_LABEL L_128 ,
dev->number, iadev->irq) ;
error = - V_557 ;
goto V_363;
}
if ( ( error = F_124 ( V_153 -> V_312 ,
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
V_549 = F_7 ( V_153 -> V_195 + V_552 ) ;
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
F_50 ( V_549 , V_153 -> V_195 + V_552 ) ;
F_47 (printk(L_132,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));
printk(L_133,
readl(iadev->reg+IPHASE5575_BUS_STATUS_REG));)
F_46 ( V_153 ) ;
error = F_94 ( V_10 ) ;
if ( error )
goto V_561;
error = F_80 ( V_10 ) ;
if ( error )
goto V_576;
V_549 = F_7 ( V_153 -> V_195 + V_552 ) ;
F_50 ( V_549 | V_562 , V_153 -> V_195 + V_552 ) ;
F_47 (printk(L_132,
readl(iadev->reg+IPHASE5575_BUS_CONTROL_REG));)
V_196 = 0 ;
F_47 (
if ((phy=ia_phy_get(dev,0)) == 0x30)
printk(L_134,phy&0x0f);
else
printk(L_135,phy);)
if ( V_153 -> V_187 & V_189 )
F_52 ( V_153 ) ;
else if ( V_153 -> V_187 & ( V_190 | V_191 ) )
F_57 ( V_153 ) ;
else {
error = V_230 ( V_10 ) ;
if ( error )
goto V_577;
if ( V_10 -> V_196 -> V_319 ) {
error = V_10 -> V_196 -> V_319 ( V_10 ) ;
if ( error )
goto V_577;
}
F_51 ( V_153 ) ;
}
return 0 ;
V_577:
F_121 ( V_153 ) ;
V_576:
F_120 ( V_153 ) ;
V_561:
F_125 ( V_153 -> V_495 , V_10 ) ;
V_363:
return error ;
}
static void F_126 ( struct V_41 * V_42 )
{
F_127 ( V_578 ) ;
T_4 * V_347 ;
T_2 * V_153 ;
struct V_13 * V_13 ;
struct V_33 * V_34 = NULL ;
struct V_579 V_580 , V_581 ;
unsigned long V_582 , V_159 ;
V_153 = F_31 ( V_42 -> V_10 ) ;
V_13 = F_29 ( V_42 ) ;
if ( ! V_13 ) return;
F_10 (printk(L_136,
ia_vcc->vc_desc_cnt,vcc->vci);)
F_128 ( V_158 , & V_42 -> V_159 ) ;
F_83 ( & V_580 ) ;
F_83 ( & V_581 ) ;
if ( V_42 -> V_54 . V_55 . V_56 != V_350 ) {
V_153 -> V_401 ++ ;
F_129 ( & V_153 -> V_488 , & V_578 , V_583 ) ;
F_130 ( F_131 ( 500 ) ) ;
F_132 ( & V_153 -> V_488 , & V_578 ) ;
F_87 ( & V_153 -> V_400 , V_159 ) ;
while( ( V_34 = F_34 ( & V_153 -> V_157 ) ) ) {
if ( F_35 ( V_34 ) -> V_42 == V_42 ) {
if ( V_42 -> V_164 ) V_42 -> V_164 ( V_42 , V_34 ) ;
else F_36 ( V_34 ) ;
}
else
F_70 ( & V_580 , V_34 ) ;
}
while( ( V_34 = F_34 ( & V_580 ) ) )
F_70 ( & V_153 -> V_157 , V_34 ) ;
F_10 (printk(L_137, ia_vcc->vc_desc_cnt);)
V_582 = 300000 / V_13 -> V_23 ;
if ( V_582 == 0 )
V_582 = 1 ;
F_88 ( & V_153 -> V_400 , V_159 ) ;
F_133 ( V_153 -> V_402 , ( V_13 -> V_22 <= 0 ) , V_582 ) ;
F_87 ( & V_153 -> V_400 , V_159 ) ;
V_153 -> V_401 -- ;
V_153 -> V_58 [ V_42 -> V_59 ] -> V_67 = 0 ;
V_153 -> V_58 [ V_42 -> V_59 ] -> V_68 = 0 ;
V_153 -> V_58 [ V_42 -> V_59 ] -> V_60 = V_482 ;
if ( V_42 -> V_54 . V_55 . V_56 == V_57 ) {
if ( V_42 -> V_54 . V_55 . V_426 > 0 )
V_153 -> V_122 -= V_42 -> V_54 . V_55 . V_426 ;
}
if ( V_42 -> V_54 . V_55 . V_56 == V_411 ) {
V_13 = F_29 ( V_42 ) ;
V_153 -> V_122 -= V_13 -> V_144 * V_153 -> V_141 ;
F_30 ( V_42 ) ;
}
F_88 ( & V_153 -> V_400 , V_159 ) ;
}
if ( V_42 -> V_54 . V_349 . V_56 != V_350 ) {
V_347 = ( T_4 * ) ( V_153 -> V_112 + V_113 * V_153 -> V_114 ) ;
V_347 += V_42 -> V_59 ;
* V_347 = V_115 ;
V_347 = ( T_4 * ) ( V_153 -> V_112 + V_351 * V_153 -> V_114 ) ;
V_347 += V_42 -> V_59 ;
* V_347 = ( V_42 -> V_59 << 6 ) | 15 ;
if ( V_42 -> V_54 . V_349 . V_56 == V_57 ) {
struct V_354 T_13 * V_354 =
( V_153 -> V_112 + V_117 * V_153 -> V_114 ) ;
V_354 += V_42 -> V_59 ;
V_354 -> V_88 = 0x0003 ;
V_354 -> V_97 = 0x5eb1 ;
}
F_73 ( V_42 -> V_10 ) ;
V_153 -> V_296 [ V_42 -> V_59 ] = NULL ;
}
F_41 ( F_29 ( V_42 ) ) ;
V_13 = NULL ;
V_42 -> V_413 = NULL ;
F_128 ( V_584 , & V_42 -> V_159 ) ;
return;
}
static int F_134 ( struct V_41 * V_42 )
{
struct V_13 * V_13 ;
int error ;
if ( ! F_37 ( V_585 , & V_42 -> V_159 ) )
{
F_10 (printk(L_138);)
V_42 -> V_413 = NULL ;
}
if ( V_42 -> V_59 != V_586 && V_42 -> V_587 != V_588 )
{
F_10 (printk(L_139);)
F_135 ( V_584 , & V_42 -> V_159 ) ;
}
if ( V_42 -> V_54 . V_589 != V_590 )
return - V_290 ;
F_10 (printk(DEV_LABEL L_140,
vcc->dev->number, vcc->vpi, vcc->vci);)
V_13 = F_4 ( sizeof( * V_13 ) , V_362 ) ;
if ( ! V_13 ) return - V_8 ;
V_42 -> V_413 = V_13 ;
if ( ( error = F_79 ( V_42 ) ) )
{
F_10 (printk(L_141);)
F_126 ( V_42 ) ;
return error ;
}
if ( ( error = F_91 ( V_42 ) ) )
{
F_10 (printk(L_142);)
F_126 ( V_42 ) ;
return error ;
}
F_135 ( V_158 , & V_42 -> V_159 ) ;
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
static int F_136 ( struct V_41 * V_42 , struct V_591 * V_54 , int V_159 )
{
F_10 (printk(L_144);)
return 0 ;
}
static int F_137 ( struct V_274 * V_10 , unsigned int V_592 , void T_15 * V_547 )
{
T_16 V_593 ;
T_2 * V_153 ;
int V_32 , V_594 ;
T_4 T_15 * V_595 ;
F_10 (printk(L_145);)
if ( V_592 != V_596 ) {
if ( ! V_10 -> V_196 -> V_597 ) return - V_290 ;
return V_10 -> V_196 -> V_597 ( V_10 , V_592 , V_547 ) ;
}
if ( F_138 ( & V_593 , V_547 , sizeof V_593 ) ) return - V_598 ;
V_594 = V_593 . V_63 ;
if ( ( V_594 < 0 ) || ( V_594 > V_550 ) )
V_594 = 0 ;
V_153 = V_551 [ V_594 ] ;
switch ( V_593 . V_592 ) {
case V_599 :
{
switch ( V_593 . V_600 ) {
case V_601 :
if ( ! F_139 ( V_602 ) ) return - V_603 ;
if ( F_140 ( V_593 . V_604 , V_153 , sizeof( T_2 ) ) )
return - V_598 ;
V_593 . V_63 = 0 ;
break;
case V_605 :
if ( ! F_139 ( V_602 ) ) return - V_603 ;
V_595 = ( T_4 T_15 * ) V_593 . V_604 ;
for( V_32 = 0 ; V_32 < 0x80 ; V_32 += 2 , V_595 ++ )
if( F_141 ( ( T_4 ) ( F_7 ( V_153 -> V_15 + V_32 ) & 0xffff ) , V_595 ) ) return - V_598 ;
V_593 . V_63 = 0 ;
V_593 . V_165 = 0x80 ;
break;
case V_606 :
if ( ! F_139 ( V_602 ) ) return - V_603 ;
V_595 = ( T_4 T_15 * ) V_593 . V_604 ;
for( V_32 = 0 ; V_32 < 0x80 ; V_32 += 2 , V_595 ++ )
if( F_141 ( ( T_4 ) ( F_7 ( V_153 -> V_280 + V_32 ) & 0xffff ) , V_595 ) ) return - V_598 ;
V_593 . V_63 = 0 ;
V_593 . V_165 = 0x80 ;
break;
case V_607 :
{
T_17 * V_608 ;
T_18 * V_28 ;
T_19 * V_276 ;
if ( ! F_139 ( V_602 ) ) return - V_603 ;
V_608 = F_4 ( sizeof( * V_608 ) , V_362 ) ;
if ( ! V_608 ) return - V_8 ;
V_28 = & V_608 -> V_609 ;
V_276 = & V_608 -> V_610 ;
for ( V_32 = 0 ; V_32 < ( sizeof ( T_19 ) ) / 4 ; V_32 ++ )
( ( T_7 * ) V_276 ) [ V_32 ] = F_7 ( V_153 -> V_280 + V_32 ) & 0xffff ;
for ( V_32 = 0 ; V_32 < ( sizeof ( T_18 ) ) / 4 ; V_32 ++ )
( ( T_7 * ) V_28 ) [ V_32 ] = F_7 ( V_153 -> V_15 + V_32 ) & 0xffff ;
if ( F_140 ( V_593 . V_604 , V_608 , sizeof( T_17 ) ) ) {
F_41 ( V_608 ) ;
return - V_598 ;
}
F_41 ( V_608 ) ;
F_9 ( L_146 , V_594 ) ;
V_593 . V_63 = 0 ;
}
break;
case V_611 :
{
if ( ! F_139 ( V_602 ) ) return - V_603 ;
F_60 ( V_153 ) ;
V_593 . V_63 = 0 ;
}
break;
case 0x6 :
{
V_593 . V_63 = 0 ;
F_9 ( L_147 , ( long ) F_142 ( & V_153 -> V_157 ) ) ;
F_9 ( L_148 , ( long ) F_5 ( & V_153 -> V_27 ) ) ;
}
break;
case 0x8 :
{
struct V_612 * V_301 ;
V_301 = & F_143 ( V_613 [ V_594 ] ) -> V_614 ;
F_9 ( L_149 , F_144 ( & V_301 -> V_615 ) ) ;
F_9 ( L_150 , F_144 ( & V_301 -> V_616 ) ) ;
F_9 ( L_151 , F_144 ( & V_301 -> V_617 ) ) ;
F_9 ( L_152 , F_144 ( & V_301 -> V_618 ) ) ;
F_9 ( L_153 , F_144 ( & V_301 -> V_619 ) ) ;
F_9 ( L_154 , F_144 ( & V_301 -> V_620 ) ) ;
F_9 ( L_155 , F_144 ( & V_301 -> V_621 ) ) ;
F_9 ( L_156 , F_144 ( & V_301 -> V_622 ) ) ;
F_9 ( L_157 , F_144 ( & V_301 -> V_623 ) ) ;
}
V_593 . V_63 = 0 ;
break;
case 0x9 :
if ( ! F_139 ( V_602 ) ) return - V_603 ;
for ( V_32 = 1 ; V_32 <= V_153 -> V_178 ; V_32 ++ )
F_63 ( V_613 [ V_594 ] , V_32 ) ;
F_16 ( ~ ( V_328 | V_332 ) ,
V_153 -> V_280 + V_333 ) ;
V_153 -> V_327 = 1 ;
V_593 . V_63 = 0 ;
break;
case 0xb :
if ( ! F_139 ( V_602 ) ) return - V_603 ;
F_51 ( V_153 ) ;
break;
case 0xa :
if ( ! F_139 ( V_602 ) ) return - V_603 ;
{
V_593 . V_63 = 0 ;
V_624 = V_593 . V_625 ;
F_9 ( L_158 ) ;
}
break;
default:
V_593 . V_63 = 0 ;
break;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_145 ( struct V_41 * V_42 , int V_626 , int V_627 ,
void T_15 * V_628 , int V_629 )
{
F_10 (printk(L_159);)
return - V_290 ;
}
static int F_146 ( struct V_41 * V_42 , int V_626 , int V_627 ,
void T_15 * V_628 , unsigned int V_629 )
{
F_10 (printk(L_160);)
return - V_290 ;
}
static int F_38 ( struct V_41 * V_42 , struct V_33 * V_34 ) {
T_2 * V_153 ;
struct V_284 * V_285 ;
struct V_434 T_13 * V_283 ;
int V_275 ;
int V_630 ;
int V_631 ;
struct V_341 * V_342 ;
struct V_13 * V_21 ;
V_153 = F_31 ( V_42 -> V_10 ) ;
V_21 = F_29 ( V_42 ) ;
if ( ! V_21 -> V_414 ) {
F_9 ( L_161 ) ;
if ( V_42 -> V_164 )
V_42 -> V_164 ( V_42 , V_34 ) ;
else
F_36 ( V_34 ) ;
return 0 ;
}
if ( V_34 -> V_165 > V_153 -> V_176 - 8 ) {
F_9 ( L_162 ) ;
if ( V_42 -> V_164 )
V_42 -> V_164 ( V_42 , V_34 ) ;
else
F_36 ( V_34 ) ;
return 0 ;
}
if ( ( unsigned long ) V_34 -> V_4 & 3 ) {
F_9 ( L_163 ) ;
if ( V_42 -> V_164 )
V_42 -> V_164 ( V_42 , V_34 ) ;
else
F_36 ( V_34 ) ;
return 0 ;
}
V_275 = F_12 ( V_153 , V_21 ) ;
if ( V_275 == 0xffff )
return 1 ;
V_630 = V_275 >> 13 ;
V_275 &= 0x1fff ;
if ( ( V_275 == 0 ) || ( V_275 > V_153 -> V_40 ) )
{
F_17 (printk(DEV_LABEL L_164, desc);)
F_66 ( & V_42 -> V_301 -> V_632 ) ;
if ( V_42 -> V_164 )
V_42 -> V_164 ( V_42 , V_34 ) ;
else
F_36 ( V_34 ) ;
return 0 ;
}
if ( V_630 )
{
F_17 (printk(DEV_LABEL L_165,
desc, comp_code);)
}
V_21 -> V_22 ++ ;
V_153 -> V_19 [ V_275 - 1 ] . V_21 = V_21 ;
V_153 -> V_19 [ V_275 - 1 ] . V_25 = V_34 ;
F_11 ( V_34 ) = 0 ;
V_153 -> V_28 . V_39 += 2 ;
if ( V_153 -> V_28 . V_39 > V_153 -> V_28 . V_29 )
V_153 -> V_28 . V_39 = V_153 -> V_28 . V_30 ;
F_16 ( V_153 -> V_28 . V_39 , V_153 -> V_15 + V_457 ) ;
* ( T_4 * ) ( V_153 -> V_18 + V_153 -> V_28 . V_465 ) = V_275 ;
V_153 -> V_28 . V_465 += 2 ;
if ( V_153 -> V_28 . V_465 > V_153 -> V_28 . V_464 )
V_153 -> V_28 . V_465 = V_153 -> V_28 . V_463 ;
V_631 = V_34 -> V_165 + sizeof( struct V_341 ) ;
V_631 = ( ( V_631 + 47 ) / 48 ) * 48 ;
F_147 (printk(L_166, total_len, total_len - skb->len);)
V_342 = V_153 -> V_450 [ V_275 - 1 ] . V_451 ;
F_147 (printk(L_167,
skb, skb->data, skb->len, desc);)
V_342 -> V_633 = 0 ;
V_342 -> V_263 = ( ( V_34 -> V_165 & 0xff ) << 8 ) | ( ( V_34 -> V_165 & 0xff00 ) >> 8 ) ;
V_342 -> V_634 = 0 ;
F_148 (printk(L_168,
skb->len, tcnter++);
xdump(skb->data, skb->len, L_169);
printk(L_74);)
V_283 = V_153 -> V_18 + V_447 ;
V_283 += V_275 ;
V_283 -> V_297 = V_449 | V_635 | V_636 | V_637 ;
F_16 ( V_73 , V_153 -> V_15 + V_76 ) ;
V_283 -> V_295 = V_42 -> V_59 ;
V_283 -> V_315 = V_631 ;
if ( V_42 -> V_54 . V_55 . V_56 == V_57 )
F_14 ( V_42 , V_153 ) ;
V_285 = V_153 -> V_403 . V_310 ;
memset ( ( V_99 ) V_285 , 0 , sizeof( * V_285 ) ) ;
V_285 -> V_311 = F_71 ( & V_153 -> V_312 -> V_10 , V_34 -> V_4 ,
V_34 -> V_165 , V_406 ) ;
V_285 -> V_314 = ( V_283 -> V_304 << 16 ) |
V_283 -> V_305 ;
V_285 -> V_315 = V_34 -> V_165 ;
if ( ( V_285 -> V_315 >> 2 ) == 0xb )
V_285 -> V_315 = 0x30 ;
V_285 -> V_316 = V_638 ;
V_285 -> V_639 = 0 ;
if ( ++ V_285 == V_153 -> V_403 . V_318 )
V_285 = V_153 -> V_403 . V_319 ;
V_285 -> V_311 = V_153 -> V_450 [ V_275 - 1 ] . V_287 ;
V_285 -> V_314 = ( ( V_283 -> V_304 << 16 ) |
V_283 -> V_305 ) + V_631 - sizeof( struct V_341 ) ;
V_285 -> V_315 = sizeof( struct V_341 ) ;
V_285 -> V_316 = V_317 ;
V_285 -> V_639 = V_153 -> V_28 . V_465 ;
if ( ++ V_285 == V_153 -> V_403 . V_318 )
V_285 = V_153 -> V_403 . V_319 ;
V_153 -> V_403 . V_310 = V_285 ;
F_69 ( V_34 ) = V_42 -> V_59 ;
F_70 ( & V_153 -> V_405 , V_34 ) ;
F_66 ( & V_42 -> V_301 -> V_632 ) ;
V_153 -> V_493 ++ ;
F_50 ( 2 , V_153 -> V_320 + V_640 ) ;
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
F_147 (printk(L_170);)
return 0 ;
}
static int F_149 ( struct V_41 * V_42 , struct V_33 * V_34 )
{
T_2 * V_153 ;
unsigned long V_159 ;
V_153 = F_31 ( V_42 -> V_10 ) ;
if ( ( ! V_34 ) || ( V_34 -> V_165 > ( V_153 -> V_176 - sizeof( struct V_341 ) ) ) )
{
if ( ! V_34 )
F_9 ( V_641 L_171 ) ;
else F_36 ( V_34 ) ;
return - V_290 ;
}
F_87 ( & V_153 -> V_400 , V_159 ) ;
if ( ! F_37 ( V_158 , & V_42 -> V_159 ) ) {
F_36 ( V_34 ) ;
F_88 ( & V_153 -> V_400 , V_159 ) ;
return - V_290 ;
}
F_35 ( V_34 ) -> V_42 = V_42 ;
if ( F_142 ( & V_153 -> V_157 ) ) {
F_70 ( & V_153 -> V_157 , V_34 ) ;
}
else {
if ( F_38 ( V_42 , V_34 ) ) {
F_70 ( & V_153 -> V_157 , V_34 ) ;
}
}
F_88 ( & V_153 -> V_400 , V_159 ) ;
return 0 ;
}
static int F_150 ( struct V_274 * V_10 , T_20 * V_642 , char * V_643 )
{
int V_644 = * V_642 , V_645 ;
char * V_646 ;
T_2 * V_153 = F_31 ( V_10 ) ;
if( ! V_644 -- ) {
if ( V_153 -> V_187 == V_189 ) {
V_645 = sprintf ( V_643 , L_172 ) ;
return V_645 ;
}
if ( V_153 -> V_187 == V_190 )
V_645 = sprintf ( V_643 , L_173 ) ;
else if ( V_153 -> V_187 == V_191 )
V_645 = sprintf ( V_643 , L_174 ) ;
else if ( V_153 -> V_187 == V_647 )
V_645 = sprintf ( V_643 , L_175 ) ;
else
V_645 = sprintf ( V_643 , L_176 ) ;
V_646 = V_643 + V_645 ;
if ( V_153 -> V_523 == 0x40000 )
V_645 += sprintf ( V_646 , L_177 ) ;
else
V_645 += sprintf ( V_646 , L_178 ) ;
V_646 = V_643 + V_645 ;
if ( ( V_153 -> V_172 & V_173 ) == V_174 )
V_645 += sprintf ( V_646 , L_179 ) ;
else if ( ( V_153 -> V_172 & V_173 ) == V_182 )
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
V_153 -> V_40 , V_153 -> V_176 ,
V_153 -> V_178 , V_153 -> V_180 ,
V_153 -> V_330 , V_153 -> V_493 ,
V_153 -> V_537 , V_153 -> V_544 ,
V_153 -> V_542 , V_153 -> V_540 ) ;
}
return 0 ;
}
static int F_151 ( struct V_648 * V_649 , const struct V_650 * V_651 )
{
struct V_274 * V_10 ;
T_2 * V_153 ;
int V_410 ;
V_153 = F_84 ( sizeof( * V_153 ) , V_362 ) ;
if ( ! V_153 ) {
V_410 = - V_8 ;
goto V_363;
}
V_153 -> V_312 = V_649 ;
F_47 (printk(L_192,
pdev->bus->number, PCI_SLOT(pdev->devfn), PCI_FUNC(pdev->devfn));)
if ( F_152 ( V_649 ) ) {
V_410 = - V_652 ;
goto V_653;
}
V_10 = F_153 ( V_525 , & V_649 -> V_10 , & V_654 , - 1 , NULL ) ;
if ( ! V_10 ) {
V_410 = - V_8 ;
goto V_655;
}
V_10 -> V_413 = V_153 ;
F_47 (printk(DEV_LABEL L_193, dev->number);)
F_47 (printk(L_194, dev,
iadev->LineRate);)
F_154 ( V_649 , V_10 ) ;
V_551 [ V_550 ] = V_153 ;
V_613 [ V_550 ] = V_10 ;
V_550 ++ ;
if ( F_108 ( V_10 ) || F_122 ( V_10 ) ) {
F_47 (printk(L_195);)
V_550 -- ;
V_551 [ V_550 ] = NULL ;
V_613 [ V_550 ] = NULL ;
V_410 = - V_290 ;
goto V_656;
}
F_10 (printk(L_196, iadev_count);)
V_153 -> V_657 = V_658 ;
V_658 = V_10 ;
return 0 ;
V_656:
F_155 ( V_10 ) ;
V_655:
F_156 ( V_649 ) ;
V_653:
F_41 ( V_153 ) ;
V_363:
return V_410 ;
}
static void F_157 ( struct V_648 * V_649 )
{
struct V_274 * V_10 = F_158 ( V_649 ) ;
T_2 * V_153 = F_31 ( V_10 ) ;
F_118 ( V_10 , F_119 ( V_10 , V_659 ) & ~ ( V_660 ) ,
V_659 ) ;
F_15 ( 1 ) ;
if ( V_10 -> V_196 && V_10 -> V_196 -> V_661 )
V_10 -> V_196 -> V_661 ( V_10 ) ;
F_125 ( V_153 -> V_495 , V_10 ) ;
V_550 -- ;
V_551 [ V_550 ] = NULL ;
V_613 [ V_550 ] = NULL ;
F_10 (printk(L_197, dev->number);)
F_155 ( V_10 ) ;
F_114 ( V_153 -> V_516 ) ;
F_156 ( V_649 ) ;
F_121 ( V_153 ) ;
F_120 ( V_153 ) ;
F_41 ( V_153 ) ;
}
static int T_21 F_159 ( void )
{
int V_410 ;
V_410 = F_160 ( & V_662 ) ;
if ( V_410 >= 0 ) {
V_554 . V_663 = V_38 + 3 * V_416 ;
F_161 ( & V_554 ) ;
} else
F_9 (KERN_ERR DEV_LABEL L_198 ) ;
return V_410 ;
}
static void T_22 F_162 ( void )
{
F_163 ( & V_662 ) ;
F_164 ( & V_554 ) ;
}
