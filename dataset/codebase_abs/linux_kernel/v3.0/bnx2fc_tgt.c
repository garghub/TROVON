static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 , L_1 ) ;
F_3 ( V_4 , & V_3 -> V_5 ) ;
F_4 ( V_6 , & V_3 -> V_5 ) ;
F_5 ( & V_3 -> V_7 ) ;
}
static void F_6 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 , L_2 ) ;
F_3 ( V_4 , & V_3 -> V_5 ) ;
F_4 ( V_8 , & V_3 -> V_5 ) ;
F_5 ( & V_3 -> V_9 ) ;
}
static void F_7 ( struct V_10 * V_11 ,
struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = V_11 -> V_21 ;
int V_22 ;
int V_23 = 0 ;
V_22 = F_8 ( V_3 , V_11 , V_13 ) ;
if ( V_22 ) {
F_9 (KERN_ERR PFX L_3
L_4 , rport->port_id) ;
goto V_24;
}
V_22 = F_10 ( V_20 , V_3 ) ;
if ( V_22 ) {
F_9 (KERN_ERR PFX L_5 ) ;
goto V_24;
}
V_25:
F_3 ( V_8 , & V_3 -> V_5 ) ;
V_22 = F_11 ( V_11 , V_3 ) ;
if ( V_22 ) {
F_9 (KERN_ERR PFX L_6 ) ;
goto V_24;
}
F_12 ( & V_3 -> V_26 , F_6 , ( unsigned long ) V_3 ) ;
F_13 ( & V_3 -> V_26 , V_27 + V_28 ) ;
F_14 ( V_3 -> V_9 ,
( F_15 (
V_8 ,
& V_3 -> V_5 ) ) ) ;
if ( F_16 ( V_29 ) )
F_17 ( V_29 ) ;
F_18 ( & V_3 -> V_26 ) ;
if ( ! ( F_15 ( V_4 , & V_3 -> V_5 ) ) ) {
if ( F_19 ( V_30 ,
& V_3 -> V_5 ) ) {
F_2 ( V_3 , L_7
L_8 , V_23 ++ ) ;
F_20 ( 1000 ) ;
if ( V_23 > 3 ) {
V_23 = 0 ;
goto V_24;
}
goto V_25;
}
goto V_24;
}
if ( F_21 ( V_3 ) ) {
F_9 (KERN_ERR PFX L_9 ) ;
V_15 -> V_31 . V_32 ( V_13 ) ;
}
return;
V_24:
F_2 ( V_3 , L_10 ) ;
V_15 -> V_31 . V_32 ( V_13 ) ;
F_22 ( V_20 , V_3 ) ;
if ( V_3 -> V_33 != - 1 )
F_23 ( V_20 , V_3 -> V_33 ) ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_36 * V_38 ;
int V_39 ;
int V_23 = 0 ;
F_2 ( V_3 , L_11 ,
V_3 -> V_40 . V_41 ) ;
F_25 ( & V_3 -> V_42 ) ;
V_3 -> V_43 = 1 ;
F_26 (list, tmp, &tgt->active_cmd_queue) {
V_23 ++ ;
V_35 = (struct V_34 * ) V_37 ;
F_27 ( & V_35 -> V_44 ) ;
V_35 -> V_45 = 0 ;
F_28 ( V_35 , L_12 ) ;
if ( F_29 ( & V_35 -> V_46 ) ) {
if ( F_19 ( V_47 ,
& V_35 -> V_48 ) ) {
F_28 ( V_35 , L_13
L_14 ) ;
F_30 ( & V_35 -> V_49 ) ;
}
F_31 ( & V_35 -> V_50 ,
V_51 ) ;
}
F_4 ( V_52 , & V_35 -> V_48 ) ;
F_4 ( V_53 , & V_35 -> V_48 ) ;
V_39 = F_32 ( V_35 ) ;
F_33 ( V_39 ) ;
}
F_26 (list, tmp, &tgt->els_queue) {
V_23 ++ ;
V_35 = (struct V_34 * ) V_37 ;
F_27 ( & V_35 -> V_44 ) ;
V_35 -> V_45 = 0 ;
F_28 ( V_35 , L_15 ) ;
if ( F_29 ( & V_35 -> V_46 ) )
F_31 ( & V_35 -> V_50 ,
V_51 ) ;
if ( ( V_35 -> V_54 ) && ( V_35 -> V_55 ) ) {
V_35 -> V_54 ( V_35 -> V_55 ) ;
V_35 -> V_55 = NULL ;
}
V_39 = F_32 ( V_35 ) ;
F_33 ( V_39 ) ;
}
F_26 (list, tmp, &tgt->io_retire_queue) {
V_23 ++ ;
V_35 = (struct V_34 * ) V_37 ;
F_27 ( & V_35 -> V_44 ) ;
F_28 ( V_35 , L_16 ) ;
if ( F_29 ( & V_35 -> V_46 ) )
F_31 ( & V_35 -> V_50 , V_51 ) ;
F_3 ( V_56 , & V_35 -> V_48 ) ;
}
F_2 ( V_3 , L_17 , V_23 ) ;
V_23 = 0 ;
F_34 ( & V_3 -> V_42 ) ;
while ( ( V_3 -> V_40 . V_41 != 0 ) && ( V_23 ++ < V_57 ) )
F_35 ( 25 ) ;
if ( V_3 -> V_40 . V_41 != 0 )
F_9 (KERN_ERR PFX L_18
L_19 ,
tgt->rdata->ids.port_id, tgt->num_active_ios.counter) ;
F_25 ( & V_3 -> V_42 ) ;
V_3 -> V_43 = 0 ;
F_34 ( & V_3 -> V_42 ) ;
}
static void F_36 ( struct V_10 * V_11 ,
struct V_2 * V_3 )
{
struct V_19 * V_20 = V_11 -> V_21 ;
F_2 ( V_3 , L_20 ,
V_3 -> V_40 . V_41 ) ;
F_3 ( V_6 , & V_3 -> V_5 ) ;
F_37 ( V_11 , V_3 ) ;
F_12 ( & V_3 -> V_58 , F_1 , ( unsigned long ) V_3 ) ;
F_13 ( & V_3 -> V_58 , V_27 + V_28 ) ;
F_2 ( V_3 , L_21 ) ;
F_14 ( V_3 -> V_7 ,
( F_15 (
V_6 ,
& V_3 -> V_5 ) ) ) ;
if ( F_16 ( V_29 ) )
F_17 ( V_29 ) ;
F_18 ( & V_3 -> V_58 ) ;
F_2 ( V_3 , L_22 ,
V_3 -> V_5 ) ;
F_24 ( V_3 ) ;
if ( F_15 ( V_59 , & V_3 -> V_5 ) ) {
F_2 ( V_3 , L_23 ) ;
F_3 ( V_6 , & V_3 -> V_5 ) ;
F_38 ( V_20 , V_3 ) ;
F_12 ( & V_3 -> V_58 ,
F_1 , ( unsigned long ) V_3 ) ;
F_13 ( & V_3 -> V_58 , V_27 + V_28 ) ;
F_14 ( V_3 -> V_7 ,
( F_15 (
V_6 ,
& V_3 -> V_5 ) ) ) ;
if ( ! ( F_15 ( V_60 , & V_3 -> V_5 ) ) )
F_9 (KERN_ERR PFX L_24 ) ;
F_2 ( V_3 , L_25 ,
V_3 -> V_5 ) ;
if ( F_16 ( V_29 ) )
F_17 ( V_29 ) ;
F_18 ( & V_3 -> V_58 ) ;
} else
F_9 (KERN_ERR PFX L_26
L_27 ) ;
F_22 ( V_20 , V_3 ) ;
F_23 ( V_20 , V_3 -> V_33 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = V_11 -> V_21 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_11 = V_11 ;
if ( V_20 -> V_61 >= V_62 ) {
F_2 ( V_3 , L_28 ) ;
V_3 -> V_33 = - 1 ;
return - 1 ;
}
V_3 -> V_33 = F_39 ( V_20 , V_3 ) ;
if ( V_3 -> V_33 == - 1 )
return - 1 ;
F_2 ( V_3 , L_29 , V_3 -> V_33 ) ;
V_3 -> V_63 = V_64 ;
V_3 -> V_65 = V_66 ;
V_3 -> V_67 = V_68 ;
V_3 -> V_69 = 1 ;
V_3 -> V_70 = 1 ;
V_3 -> V_71 = 0 ;
V_3 -> V_72 = 0 ;
V_3 -> V_73 = 0x8000 ;
V_3 -> V_74 = 0 ;
F_40 ( & V_3 -> V_40 , 0 ) ;
V_3 -> V_75 = 2 ;
F_41 ( & V_3 -> V_42 ) ;
F_41 ( & V_3 -> V_76 ) ;
F_42 ( & V_3 -> V_77 ) ;
F_42 ( & V_3 -> V_78 ) ;
F_42 ( & V_3 -> V_79 ) ;
F_42 ( & V_3 -> V_80 ) ;
F_43 ( & V_3 -> V_9 ) ;
F_43 ( & V_3 -> V_7 ) ;
return 0 ;
}
void F_44 ( struct V_14 * V_15 ,
struct V_12 * V_13 ,
enum V_81 V_82 )
{
struct V_10 * V_11 = F_45 ( V_15 ) ;
struct V_19 * V_20 = V_11 -> V_21 ;
struct V_17 * V_18 = V_13 -> V_18 ;
struct V_83 * V_84 ;
struct V_2 * V_3 ;
T_1 V_85 ;
F_46 ( V_15 , L_30 ,
V_82 , V_13 -> V_86 . V_85 ) ;
switch ( V_82 ) {
case V_87 :
if ( ! V_18 ) {
F_9 (KERN_ALERT PFX L_31 ) ;
break;
}
V_84 = V_18 -> V_88 ;
if ( V_18 -> V_85 == V_89 ) {
F_9 (KERN_ALERT PFX L_32 ,
rdata->ids.port_id) ;
break;
}
if ( V_13 -> V_90 != V_91 ) {
F_46 ( V_15 , L_33
L_34 ) ;
break;
}
if ( ! ( V_13 -> V_86 . V_92 & V_93 ) ) {
F_46 ( V_15 , L_35
L_34 ) ;
break;
}
F_47 ( & V_20 -> V_94 ) ;
V_3 = (struct V_2 * ) & V_84 [ 1 ] ;
if ( F_15 ( V_4 , & V_3 -> V_5 ) ) {
F_2 ( V_3 , L_36 ) ;
F_48 ( & V_20 -> V_94 ) ;
return;
}
F_7 ( V_11 , V_3 , V_13 ) ;
F_2 ( V_3 , L_37 ,
V_20 -> V_61 ) ;
if ( F_15 ( V_4 , & V_3 -> V_5 ) ) {
F_2 ( V_3 , L_38 ) ;
V_20 -> V_61 ++ ;
F_4 ( V_95 , & V_3 -> V_5 ) ;
} else {
F_2 ( V_3 , L_39
L_40 ) ;
}
F_48 ( & V_20 -> V_94 ) ;
break;
case V_96 :
case V_97 :
case V_98 :
V_85 = V_13 -> V_86 . V_85 ;
if ( V_85 == V_89 )
break;
if ( ! V_18 ) {
F_9 (KERN_ALERT PFX L_41 ,
port_id) ;
break;
}
V_84 = V_18 -> V_88 ;
F_47 ( & V_20 -> V_94 ) ;
V_3 = (struct V_2 * ) & V_84 [ 1 ] ;
if ( ! ( F_15 ( V_4 , & V_3 -> V_5 ) ) ) {
F_48 ( & V_20 -> V_94 ) ;
break;
}
F_3 ( V_95 , & V_3 -> V_5 ) ;
F_36 ( V_11 , V_3 ) ;
V_20 -> V_61 -- ;
F_2 ( V_3 , L_42 ,
V_20 -> V_61 ) ;
if ( ( V_20 -> V_99 ) &&
( V_20 -> V_61 == 0 ) ) {
F_5 ( & V_20 -> V_100 ) ;
}
if ( F_15 ( V_101 , & V_3 -> V_5 ) ) {
F_9 (KERN_ERR PFX L_43 ) ;
F_47 ( & V_15 -> V_102 . V_103 ) ;
V_15 -> V_31 . V_104 ( V_13 ) ;
F_48 ( & V_15 -> V_102 . V_103 ) ;
}
F_48 ( & V_20 -> V_94 ) ;
break;
case V_105 :
break;
}
}
struct V_2 * F_49 ( struct V_10 * V_11 ,
T_1 V_85 )
{
struct V_19 * V_20 = V_11 -> V_21 ;
struct V_2 * V_3 ;
struct V_12 * V_13 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_62 ; V_23 ++ ) {
V_3 = V_20 -> V_106 [ V_23 ] ;
if ( ( V_3 ) && ( V_3 -> V_11 == V_11 ) ) {
V_13 = V_3 -> V_13 ;
if ( V_13 -> V_86 . V_85 == V_85 ) {
if ( V_13 -> V_107 != V_108 ) {
F_2 ( V_3 , L_44
L_45 ) ;
return V_3 ;
} else {
F_9 (KERN_ERR PFX L_46
L_47 ,
rdata->ids.port_id) ;
return NULL ;
}
}
}
}
return NULL ;
}
static T_1 F_39 ( struct V_19 * V_20 ,
struct V_2 * V_3 )
{
T_1 V_109 , V_110 ;
F_25 ( & V_20 -> V_111 ) ;
V_110 = V_20 -> V_112 ;
V_109 = V_20 -> V_112 ++ ;
if ( V_20 -> V_112 == V_62 )
V_20 -> V_112 = 0 ;
while ( V_20 -> V_106 [ V_109 ] != NULL ) {
V_109 ++ ;
if ( V_109 == V_62 )
V_109 = 0 ;
if ( V_109 == V_110 ) {
F_34 ( & V_20 -> V_111 ) ;
return - 1 ;
}
}
V_20 -> V_106 [ V_109 ] = V_3 ;
V_3 -> V_33 = V_109 ;
F_34 ( & V_20 -> V_111 ) ;
return V_109 ;
}
static void F_23 ( struct V_19 * V_20 , T_1 V_109 )
{
F_25 ( & V_20 -> V_111 ) ;
V_20 -> V_106 [ V_109 ] = NULL ;
V_20 -> V_112 = V_109 ;
F_34 ( & V_20 -> V_111 ) ;
}
static int F_10 ( struct V_19 * V_20 ,
struct V_2 * V_3 )
{
T_2 V_113 ;
int V_114 ;
T_1 * V_115 ;
V_3 -> V_116 = V_3 -> V_63 * V_117 ;
V_3 -> V_116 = ( V_3 -> V_116 + ( V_118 - 1 ) ) & V_119 ;
V_3 -> V_120 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_116 ,
& V_3 -> V_123 , V_124 ) ;
if ( ! V_3 -> V_120 ) {
F_9 (KERN_ALERT PFX L_48 ,
tgt->sq_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_120 , 0 , V_3 -> V_116 ) ;
V_3 -> V_126 = V_3 -> V_67 * V_127 ;
V_3 -> V_126 = ( V_3 -> V_126 + ( V_118 - 1 ) ) & V_119 ;
V_3 -> V_128 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_126 ,
& V_3 -> V_129 , V_124 ) ;
if ( ! V_3 -> V_128 ) {
F_9 (KERN_ALERT PFX L_49 ,
tgt->cq_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_128 , 0 , V_3 -> V_126 ) ;
V_3 -> V_130 = V_3 -> V_65 * V_131 ;
V_3 -> V_130 = ( V_3 -> V_130 + ( V_118 - 1 ) ) & V_119 ;
V_3 -> V_132 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_130 ,
& V_3 -> V_133 , V_124 ) ;
if ( ! V_3 -> V_132 ) {
F_9 (KERN_ALERT PFX L_50 ,
tgt->rq_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_132 , 0 , V_3 -> V_130 ) ;
V_3 -> V_134 = ( V_3 -> V_130 / V_118 ) * sizeof( void * ) ;
V_3 -> V_134 = ( V_3 -> V_134 + ( V_118 - 1 ) ) & V_119 ;
V_3 -> V_135 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_134 ,
& V_3 -> V_136 , V_124 ) ;
if ( ! V_3 -> V_135 ) {
F_9 (KERN_ALERT PFX L_51 ,
tgt->rq_pbl_size) ;
goto V_125;
}
memset ( V_3 -> V_135 , 0 , V_3 -> V_134 ) ;
V_114 = V_3 -> V_130 / V_118 ;
V_113 = V_3 -> V_133 ;
V_115 = ( T_1 * ) V_3 -> V_135 ;
while ( V_114 -- ) {
* V_115 = ( T_1 ) V_113 ;
V_115 ++ ;
* V_115 = ( T_1 ) ( ( V_137 ) V_113 >> 32 ) ;
V_115 ++ ;
V_113 += V_118 ;
}
V_3 -> V_138 = V_3 -> V_63 * V_139 ;
V_3 -> V_138 = ( V_3 -> V_138 + ( V_118 - 1 ) ) &
V_119 ;
V_3 -> V_140 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_138 ,
& V_3 -> V_141 , V_124 ) ;
if ( ! V_3 -> V_140 ) {
F_9 (KERN_ALERT PFX L_52 ,
tgt->xferq_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_140 , 0 , V_3 -> V_138 ) ;
V_3 -> V_142 = V_3 -> V_63 * V_143 ;
V_3 -> V_142 = ( V_3 -> V_142 + ( V_118 - 1 ) ) &
V_119 ;
V_3 -> V_144 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_142 ,
& V_3 -> V_145 , V_124 ) ;
if ( ! V_3 -> V_144 ) {
F_9 (KERN_ALERT PFX L_53 ,
tgt->confq_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_144 , 0 , V_3 -> V_142 ) ;
V_3 -> V_146 =
( V_3 -> V_142 / V_118 ) * sizeof( void * ) ;
V_3 -> V_146 =
( V_3 -> V_146 + ( V_118 - 1 ) ) & V_119 ;
V_3 -> V_147 = F_50 ( & V_20 -> V_121 -> V_122 ,
V_3 -> V_146 ,
& V_3 -> V_148 , V_124 ) ;
if ( ! V_3 -> V_147 ) {
F_9 (KERN_ALERT PFX L_54 ,
tgt->confq_pbl_size) ;
goto V_125;
}
memset ( V_3 -> V_147 , 0 , V_3 -> V_146 ) ;
V_114 = V_3 -> V_142 / V_118 ;
V_113 = V_3 -> V_145 ;
V_115 = ( T_1 * ) V_3 -> V_147 ;
while ( V_114 -- ) {
* V_115 = ( T_1 ) V_113 ;
V_115 ++ ;
* V_115 = ( T_1 ) ( ( V_137 ) V_113 >> 32 ) ;
V_115 ++ ;
V_113 += V_118 ;
}
V_3 -> V_149 = sizeof( struct V_150 ) ;
V_3 -> V_151 = F_50 ( & V_20 -> V_121 -> V_122 ,
V_3 -> V_149 ,
& V_3 -> V_152 , V_124 ) ;
if ( ! V_3 -> V_151 ) {
F_9 (KERN_ALERT PFX L_55 ,
tgt->conn_db_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_151 , 0 , V_3 -> V_149 ) ;
V_3 -> V_153 = ( V_3 -> V_63 + 8 ) * V_117 ;
V_3 -> V_153 = ( V_3 -> V_153 + ( V_118 - 1 ) ) &
V_119 ;
V_3 -> V_154 = F_50 ( & V_20 -> V_121 -> V_122 , V_3 -> V_153 ,
& V_3 -> V_155 , V_124 ) ;
if ( ! V_3 -> V_154 ) {
F_9 (KERN_ALERT PFX L_56 ,
tgt->lcq_mem_size) ;
goto V_125;
}
memset ( V_3 -> V_154 , 0 , V_3 -> V_153 ) ;
V_3 -> V_151 -> V_156 . V_157 = - 1 ;
V_3 -> V_151 -> V_158 = 0x8000 ;
return 0 ;
V_125:
F_22 ( V_20 , V_3 ) ;
F_23 ( V_20 , V_3 -> V_33 ) ;
return - V_159 ;
}
static void F_22 ( struct V_19 * V_20 ,
struct V_2 * V_3 )
{
F_2 ( V_3 , L_57 ) ;
if ( V_3 -> V_160 ) {
F_51 ( V_3 -> V_160 ) ;
V_3 -> V_160 = NULL ;
}
if ( V_3 -> V_154 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_153 ,
V_3 -> V_154 , V_3 -> V_155 ) ;
V_3 -> V_154 = NULL ;
}
if ( V_3 -> V_151 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_149 ,
V_3 -> V_151 , V_3 -> V_152 ) ;
V_3 -> V_151 = NULL ;
}
if ( V_3 -> V_147 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_146 ,
V_3 -> V_147 , V_3 -> V_148 ) ;
V_3 -> V_147 = NULL ;
}
if ( V_3 -> V_144 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_142 ,
V_3 -> V_144 , V_3 -> V_145 ) ;
V_3 -> V_144 = NULL ;
}
if ( V_3 -> V_140 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_138 ,
V_3 -> V_140 , V_3 -> V_141 ) ;
V_3 -> V_140 = NULL ;
}
if ( V_3 -> V_135 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_134 ,
V_3 -> V_135 , V_3 -> V_136 ) ;
V_3 -> V_135 = NULL ;
}
if ( V_3 -> V_132 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_130 ,
V_3 -> V_132 , V_3 -> V_133 ) ;
V_3 -> V_132 = NULL ;
}
F_25 ( & V_3 -> V_76 ) ;
if ( V_3 -> V_128 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_126 ,
V_3 -> V_128 , V_3 -> V_129 ) ;
V_3 -> V_128 = NULL ;
}
F_34 ( & V_3 -> V_76 ) ;
if ( V_3 -> V_120 ) {
F_52 ( & V_20 -> V_121 -> V_122 , V_3 -> V_116 ,
V_3 -> V_120 , V_3 -> V_123 ) ;
V_3 -> V_120 = NULL ;
}
}
