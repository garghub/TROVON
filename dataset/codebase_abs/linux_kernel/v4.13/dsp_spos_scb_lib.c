static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 = ( int ) ( V_4 - V_6 -> V_8 . V_9 ) ;
if ( F_2 ( V_6 -> V_8 . V_10 <= 0 ) )
return;
if ( F_2 ( V_7 < 0 ||
V_7 >= V_6 -> V_8 . V_10 ) )
return;
V_6 -> V_8 . V_9 [ V_7 ] . V_11 = 1 ;
if ( V_7 < V_6 -> V_8 . V_12 ) {
V_6 -> V_8 . V_12 = V_7 ;
}
if ( V_7 == V_6 -> V_8 . V_10 - 1 )
V_6 -> V_8 . V_10 -- ;
if ( V_6 -> V_8 . V_12 > V_6 -> V_8 . V_10 ) {
V_6 -> V_8 . V_12 = V_6 -> V_8 . V_10 ;
}
}
static void F_3 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_14 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_23 , V_24 ;
void T_1 * V_25 = V_2 -> V_26 . V_27 [ 1 ] . V_28 + V_29 ;
V_6 = V_2 -> V_5 ;
F_4 ( & V_2 -> V_30 ) ;
F_5 ( V_16 , L_1 , V_21 -> V_31 , V_21 -> V_32 ) ;
for ( V_24 = 0 , V_23 = 0 ; V_23 < 0x10 ; V_23 ++ , V_24 ++ ) {
if ( V_24 == 4 ) {
F_5 ( V_16 , L_2 ) ;
V_24 = 0 ;
}
F_5 ( V_16 , L_3 , F_6 ( V_25 + ( V_21 -> V_31 + V_23 ) * sizeof( V_33 ) ) ) ;
}
F_5 ( V_16 , L_2 ) ;
if ( V_21 -> V_34 != NULL ) {
F_5 ( V_16 , L_4 ,
V_21 -> V_34 -> V_32 ,
V_21 -> V_34 -> V_31 ) ;
} else F_5 ( V_16 , L_5 ) ;
F_5 ( V_16 , L_6 ,
V_21 -> V_35 -> V_32 ,
V_21 -> V_35 -> V_31 ,
V_21 -> V_36 -> V_32 ,
V_21 -> V_36 -> V_31 ,
V_21 -> V_37 -> V_38 ,
V_21 -> V_37 -> V_31 ) ;
F_5 ( V_16 , L_7 , V_21 -> V_39 , V_21 -> V_40 ) ;
F_7 ( & V_2 -> V_30 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_21 -> V_34 ) {
if ( F_2 ( V_21 -> V_34 -> V_35 != V_21 &&
V_21 -> V_34 -> V_36 != V_21 ) )
return;
if ( V_21 -> V_34 -> V_35 == V_21 ) {
if ( V_21 -> V_36 == V_6 -> V_41 ) {
V_21 -> V_34 -> V_35 = V_21 -> V_35 ;
if ( V_21 -> V_35 != V_6 -> V_41 ) {
V_21 -> V_35 -> V_34 = V_21 -> V_34 ;
}
V_21 -> V_35 = V_6 -> V_41 ;
} else {
V_21 -> V_34 -> V_35 = V_21 -> V_36 ;
if ( V_21 -> V_36 != V_6 -> V_41 ) {
V_21 -> V_36 -> V_34 = V_21 -> V_34 ;
}
V_21 -> V_36 = V_6 -> V_41 ;
}
} else {
V_21 -> V_34 -> V_36 = V_21 -> V_36 ;
if ( V_21 -> V_36 != V_6 -> V_41 ) {
V_21 -> V_36 -> V_34 = V_21 -> V_34 ;
}
V_21 -> V_36 = V_6 -> V_41 ;
}
F_9 ( V_2 , V_21 -> V_34 ) ;
F_9 ( V_2 , V_21 ) ;
V_21 -> V_34 = NULL ;
}
}
static void F_10 ( struct V_1 * V_2 , V_33 V_42 ,
int V_43 )
{
void T_1 * V_25 = V_2 -> V_26 . V_27 [ 2 ] . V_28 + V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 ; ++ V_44 ) {
F_11 ( 0 , V_25 ) ;
V_25 += 4 ;
}
}
void F_12 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
unsigned long V_45 ;
if ( F_2 ( V_21 -> V_39 < 0 ||
V_21 -> V_39 >= V_6 -> V_46 ||
( V_6 -> V_47 + V_21 -> V_39 ) != V_21 ) )
return;
#if 0
if (snd_BUG_ON(scb->sub_list_ptr != ins->the_null_scb ||
scb->next_scb_ptr != ins->the_null_scb))
goto _end;
#endif
F_13 ( & V_2 -> V_48 , V_45 ) ;
F_8 ( V_2 , V_21 ) ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
F_15 ( V_21 ) ;
if ( F_2 ( ! V_21 -> V_49 ) )
return;
F_1 ( V_2 , V_21 -> V_49 ) ;
V_6 -> V_47 [ V_21 -> V_39 ] . V_11 = 1 ;
#ifdef F_16
F_17 ( V_6 -> V_47 [ V_21 -> V_39 ] . V_50 ) ;
V_6 -> V_47 [ V_21 -> V_39 ] . V_50 = NULL ;
#endif
if ( V_21 -> V_39 < V_6 -> V_51 )
V_6 -> V_51 = V_21 -> V_39 ;
if ( V_21 -> V_39 == V_6 -> V_46 - 1 ) {
V_6 -> V_46 -- ;
}
if ( V_6 -> V_51 > V_6 -> V_46 ) {
V_6 -> V_51 = V_6 -> V_46 ;
}
#if 0
for(i = scb->index + 1;i < ins->nscb; ++i) {
ins->scbs[i - 1].index = i - 1;
}
#endif
}
void F_15 ( struct V_20 * V_21 )
{
if ( V_21 -> V_52 ) {
struct V_17 * V_18 = V_21 -> V_52 -> V_19 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_18 ( V_2 -> V_53 -> V_54 ,
L_8 ,
V_21 -> V_32 ) ;
F_19 ( V_21 -> V_52 ) ;
V_21 -> V_52 = NULL ;
F_17 ( V_18 ) ;
}
}
void F_20 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_13 * V_14 ;
struct V_17 * V_18 ;
if ( V_6 -> V_55 != NULL && V_6 -> V_56 != NULL &&
V_21 -> V_52 == NULL ) {
if ( ( V_14 = F_21 ( V_6 -> V_55 , V_21 -> V_32 ,
V_6 -> V_56 ) ) != NULL ) {
V_18 = F_22 ( sizeof( struct V_17 ) , V_57 ) ;
if ( ! V_18 ) {
F_19 ( V_14 ) ;
V_14 = NULL ;
goto V_58;
}
V_18 -> V_2 = V_2 ;
V_18 -> V_22 = V_21 ;
V_14 -> V_59 = V_60 ;
V_14 -> V_19 = V_18 ;
V_14 -> V_61 = V_62 | V_63 | V_64 ;
V_14 -> V_65 . V_66 . V_67 = F_3 ;
if ( F_23 ( V_14 ) < 0 ) {
F_19 ( V_14 ) ;
F_17 ( V_18 ) ;
V_14 = NULL ;
}
}
V_58:
V_21 -> V_52 = V_14 ;
}
}
static struct V_20 *
F_24 ( struct V_1 * V_2 , char * V_68 , V_33 * V_69 , V_33 V_70 ,
struct V_3 * V_37 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
unsigned long V_45 ;
if ( F_2 ( ! V_6 -> V_41 ) )
return NULL ;
V_69 [ V_73 ] =
( V_6 -> V_41 -> V_31 << 0x10 ) | V_6 -> V_41 -> V_31 ;
V_69 [ V_74 ] &= 0xFFFF0000 ;
V_69 [ V_74 ] |= V_37 -> V_31 ;
F_18 ( V_2 -> V_53 -> V_54 , L_9 , V_68 ) ;
V_21 = F_25 ( V_2 , V_68 , V_69 , V_70 ) ;
V_21 -> V_35 = V_6 -> V_41 ;
V_21 -> V_36 = V_6 -> V_41 ;
V_21 -> V_34 = V_71 ;
V_21 -> V_37 = V_37 ;
if ( V_21 -> V_34 ) {
#if 0
dev_dbg(chip->card->dev,
"scb->parent_scb_ptr = %s\n",
scb->parent_scb_ptr->scb_name);
dev_dbg(chip->card->dev,
"scb->parent_scb_ptr->next_scb_ptr = %s\n",
scb->parent_scb_ptr->next_scb_ptr->scb_name);
dev_dbg(chip->card->dev,
"scb->parent_scb_ptr->sub_list_ptr = %s\n",
scb->parent_scb_ptr->sub_list_ptr->scb_name);
#endif
if ( V_72 == V_75 ) {
if ( F_2 ( V_21 -> V_34 -> V_36 !=
V_6 -> V_41 ) )
return NULL ;
V_21 -> V_34 -> V_36 = V_21 ;
} else if ( V_72 == V_76 ) {
if ( F_2 ( V_21 -> V_34 -> V_35 !=
V_6 -> V_41 ) )
return NULL ;
V_21 -> V_34 -> V_35 = V_21 ;
} else {
F_26 () ;
}
F_13 ( & V_2 -> V_48 , V_45 ) ;
F_9 ( V_2 , V_21 -> V_34 ) ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
}
F_20 ( V_2 , V_21 ) ;
return V_21 ;
}
static struct V_20 *
F_27 ( struct V_1 * V_2 , char * V_68 , V_33 * V_69 ,
V_33 V_70 , char * V_77 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_3 * V_37 ;
V_37 = F_28 ( V_2 , V_77 ,
V_78 ) ;
if ( V_37 == NULL ) {
F_29 ( V_2 -> V_53 -> V_54 ,
L_10 , V_77 ) ;
return NULL ;
}
return F_24 ( V_2 , V_68 , V_69 , V_70 , V_37 ,
V_71 , V_72 ) ;
}
struct V_20 *
F_30 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_79 V_80 = {
{ 0 ,
0 ,
0 ,
0
} ,
{ 0 ,
0 ,
0 ,
0 ,
0
} ,
0 , 0 ,
0 , V_81 ,
0 , 0 ,
0 , 0 ,
0x0001 , 0x8000 ,
0x0001 , 0x0000 ,
0x00060000
} ;
V_21 = F_27 ( V_2 , L_11 , ( V_33 * ) & V_80 ,
V_82 ,
L_12 , NULL , V_83 ) ;
return V_21 ;
}
struct V_20 *
F_31 ( struct V_1 * V_2 , char * V_84 ,
T_2 V_85 , T_2 V_86 , T_2 V_87 ,
V_33 V_70 , struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_88 V_89 = {
{ 0 ,
0 ,
0 ,
0
} ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
0 , 0 ,
0 , V_81 ,
0 ,
0 ,
V_85 , V_86 ,
0x0000 , 0x0080 ,
0 , V_87
} ;
V_21 = F_27 ( V_2 , V_84 , ( V_33 * ) & V_89 ,
V_70 , L_13 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_32 ( struct V_1 * V_2 , char * V_84 ,
T_2 V_85 , T_2 V_86 , T_2 V_42 ,
V_33 V_70 , struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_90 V_91 = {
{ 0 ,
0 ,
0 ,
0
} ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
#if 0
SyncIOSCB,NULL_SCB_ADDR
#else
0 , 0 ,
#endif
0 , 0 ,
V_92 + V_93 ,
V_42 << 0x10 ,
V_85 , V_86 ,
0x0000 , 0x0000 ,
0x80008000
} ;
V_21 = F_27 ( V_2 , V_84 , ( V_33 * ) & V_91 ,
V_70 , L_14 , V_71 ,
V_72 ) ;
return V_21 ;
}
static struct V_20 *
F_33 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_42 , V_33 V_70 ,
int V_94 , V_33 V_95 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_96 V_97 = {
{ V_98 +
V_99 +
V_100 +
V_101 +
V_102 +
15 ,
V_103 +
V_104 +
V_94 ,
V_95 ,
V_105 +
V_42
} ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
V_81 , V_81 ,
0 , V_81 ,
V_106 +
( 19 << V_107 ) +
( ( V_70 >> 4 ) << V_108 ) +
V_92 +
V_109 ,
( V_42 << 0x10 ) ,
0 ,
{
0xffff , 0xffff ,
0xffff , 0xffff
}
} ;
if ( V_6 -> V_110 == NULL ) {
V_6 -> V_110 = F_28 ( V_2 , L_15 ,
V_78 ) ;
if ( V_6 -> V_110 == NULL ) {
F_29 ( V_2 -> V_53 -> V_54 ,
L_16 ) ;
return NULL ;
}
}
V_21 = F_24 ( V_2 , V_32 , ( V_33 * ) & V_97 ,
V_70 , V_6 -> V_110 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_34 ( struct V_1 * V_2 , char * V_32 ,
int V_111 ,
T_2 V_112 ,
T_2 V_113 , V_33 V_70 ,
struct V_20 * V_71 ,
int V_72 ,
int V_114 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
unsigned int V_115 , V_116 ;
unsigned int V_117 ;
unsigned int V_118 , V_119 ;
F_18 ( V_2 -> V_53 -> V_54 , L_17 ,
V_32 , V_111 ) ;
V_115 = V_111 << 16 ;
V_117 = V_115 / 48000 ;
V_115 -= V_117 * 48000 ;
V_115 <<= 10 ;
V_117 <<= 10 ;
V_116 = V_115 / 48000 ;
V_117 += V_116 ;
V_115 -= V_116 * 48000 ;
V_118 = V_115 / V_120 ;
V_115 -= V_118 * V_120 ;
V_119 = V_115 ;
{
struct V_121 V_122 = {
0x0028 , 0x00c8 ,
0x5555 , 0x0000 ,
0x0000 , 0x0000 ,
V_112 , 1 ,
V_118 , V_119 ,
V_92 + V_109 ,
0x0000 , V_113 ,
0x0 ,
0x080 , ( V_113 + ( 24 * 4 ) ) ,
0 , 0 ,
0 , 0 ,
V_92 + V_123 ,
V_112 << 0x10 ,
V_117 ,
{
0xffff - V_6 -> V_124 , 0xffff - V_6 -> V_125 ,
0xffff - V_6 -> V_124 , 0xffff - V_6 -> V_125
}
} ;
if ( V_6 -> V_126 == NULL ) {
V_6 -> V_126 = F_28 ( V_2 , L_18 ,
V_78 ) ;
if ( V_6 -> V_126 == NULL ) {
F_29 ( V_2 -> V_53 -> V_54 ,
L_19 ) ;
return NULL ;
}
}
F_10 ( V_2 , V_112 , 8 ) ;
F_10 ( V_2 , V_113 , 32 ) ;
if ( V_114 ) {
F_2 ( V_111 != 48000 ) ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_122 ,
V_70 , L_20 , V_71 ,
V_72 ) ;
} else {
V_21 = F_24 ( V_2 , V_32 , ( V_33 * ) & V_122 ,
V_70 , V_6 -> V_126 , V_71 ,
V_72 ) ;
}
}
return V_21 ;
}
struct V_20 *
F_35 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_127 , V_33 V_70 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_128 V_129 = {
{ 0 ,
0 ,
V_127 ,
0
} ,
{
0 ,
0 ,
0 ,
0 ,
0x00000080
} ,
0 , 0 ,
0 , 0 ,
V_92 + V_109 ,
( V_127 + ( 16 * 4 ) ) << 0x10 ,
0 ,
{
0x8000 , 0x8000 ,
0x8000 , 0x8000
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_129 ,
V_70 , L_21 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_36 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_127 , T_2 V_130 , V_33 V_70 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_131 V_132 = {
{
V_133 +
V_134 +
V_135 +
V_101 +
V_102 +
15 ,
V_103 +
V_136 +
V_137 ,
V_105 +
V_127 ,
0x0
} ,
{ 0 , 0 , 0 , 0 , 0 , } ,
0 , 0 ,
0 , V_130 ,
V_106 +
( 19 << V_107 ) +
( ( V_70 >> 4 ) << V_108 ) +
V_138 +
V_92 +
V_93 ,
( V_127 + ( 32 * 4 ) ) << 0x10 ,
1 , 0 ,
0x0001 , 0x0080 ,
0xFFFF , 0
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_132 ,
V_70 , L_22 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_37 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_139 ,
T_2 V_140 ,
V_33 V_70 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_141 V_142 = {
0x0028 , 0x00c8 ,
0x5555 , 0x0000 ,
0x0000 , 0x0000 ,
V_139 , V_140 ,
0x0028 , 0x00c8 ,
V_92 + V_143 ,
0xFF800000 ,
0 ,
0x0080 , V_140 + ( 25 * 4 ) ,
0 , 0 ,
0 , 0 ,
V_92 + V_123 ,
V_139 << 0x10 ,
0x04000000 ,
{
0x8000 , 0x8000 ,
0xFFFF , 0xFFFF
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_142 ,
V_70 , L_23 , V_71 ,
V_72 ) ;
return V_21 ;
}
static struct V_20 *
F_38 ( struct V_1 * V_2 , char * V_32 , V_33 V_70 ,
struct V_20 * V_144 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_145 V_146 = {
{ 0 ,
0 ,
0 ,
0
} ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
0 , 0 ,
0 , 0 ,
V_92 + V_147 ,
0 ,
0 , V_144 -> V_31 ,
{
0x8000 , 0x8000 ,
0x8000 , 0x8000
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_146 ,
V_70 , L_24 , V_71 ,
V_72 ) ;
return V_21 ;
}
static struct V_20 *
F_39 ( struct V_1 * V_2 , char * V_32 , V_33 V_70 ,
T_2 V_148 ,
T_2 V_149 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_150 V_151 = {
0xfc00 , 0x03ff ,
0x0058 , 0x0028 ,
0 , V_148 ,
0 , 0 ,
0 ,
0 , 0x2aab ,
{
0 ,
0 ,
0
} ,
0 , 0 ,
0 , V_70 + V_152 ,
V_92 + V_143 ,
( V_149 ) << 0x10 ,
0x18000000 ,
0x8000 , 0x8000 ,
0x8000 , 0x8000
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_151 ,
V_70 , L_25 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_40 ( struct V_1 * V_2 , char * V_32 , V_33 V_70 ,
T_2 V_148 ,
T_2 V_149 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_153 V_154 = {
0xfe00 , 0x01ff ,
0x0064 , 0x001c ,
0 , V_148 ,
0 , 0 ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
0 , 0 ,
0 , V_70 ,
V_155 |
V_92 ,
( ( V_149 + ( 16 * 4 ) ) << 0x10 ) ,
0x18000000 ,
0xffff - V_6 -> V_156 , 0xffff - V_6 -> V_157 ,
0xffff - V_6 -> V_156 , 0xffff - V_6 -> V_157 ,
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_154 ,
V_70 , L_26 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_41 ( struct V_1 * V_2 , char * V_32 , V_33 V_70 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_158 V_159 = {
0 , 0 ,
0 ,
0 ,
0 , 0 ,
0 ,
0 ,
0 , 0 ,
{ 0 , 0 } ,
0 , 0 ,
0 , 0 ,
{
0 ,
0 ,
0 ,
0 ,
0
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_159 ,
V_70 , L_27 , V_71 ,
V_72 ) ;
return V_21 ;
}
struct V_20 *
F_42 ( struct V_1 * V_2 , char * V_32 , V_33 V_70 ,
T_2 V_160 ,
struct V_20 * V_161 ,
struct V_20 * V_71 ,
int V_72 )
{
struct V_20 * V_21 ;
struct V_162 V_163 = {
0 ,
0 ,
V_160 << 0x10 ,
0 , V_161 -> V_31 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 , 0 ,
0 , 0 ,
V_92 + V_93 ,
V_160 << 0x10 ,
0 ,
{ 0x8000 , 0x8000 ,
0xffff , 0xffff
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_163 ,
V_70 , L_28 , V_71 ,
V_72 ) ;
return V_21 ;
}
static struct V_20 *
F_43 ( struct V_1 * V_2 , struct V_20 * V_164 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 = V_164 ;
while ( V_21 -> V_36 != V_6 -> V_41 ) {
if ( F_2 ( ! V_21 -> V_36 ) )
return NULL ;
V_21 = V_21 -> V_36 ;
}
return V_21 ;
}
struct V_165 *
F_44 ( struct V_1 * V_2 ,
V_33 V_166 , void * V_19 ,
V_33 V_167 ,
int V_168 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_169 = NULL , * V_170 , * V_171 = NULL ;
struct V_20 * V_172 = NULL ;
char V_32 [ V_173 ] ;
int V_44 , V_174 = - 1 , V_175 , V_176 = - 1 , V_114 = 0 ;
unsigned long V_45 ;
switch ( V_168 ) {
case V_177 :
V_171 = V_6 -> V_129 ;
break;
case V_178 :
V_171 = V_6 -> V_179 ;
break;
case V_180 :
V_171 = V_6 -> V_181 ;
break;
case V_182 :
F_26 () ;
break;
case V_183 :
if ( F_2 ( ! V_6 -> V_184 ) )
return NULL ;
V_171 = V_6 -> V_184 ;
if ( V_166 == 48000 ) {
F_18 ( V_2 -> V_53 -> V_54 , L_29 ) ;
V_114 = 1 ;
}
break;
default:
F_26 () ;
return NULL ;
}
if ( ! V_166 ) V_166 = 44100 ;
for ( V_44 = 0 ; V_44 < V_185 &&
( V_174 == - 1 || V_169 == NULL ) ; ++ V_44 ) {
if ( V_44 == V_137 ) continue;
if ( V_6 -> V_186 [ V_44 ] . V_187 ) {
if ( ! V_169 &&
V_6 -> V_186 [ V_44 ] . V_166 == V_166 &&
V_6 -> V_186 [ V_44 ] . V_171 == V_171 ) {
V_169 = V_6 -> V_186 [ V_44 ] . V_169 ;
V_6 -> V_186 [ V_44 ] . V_169 -> V_40 ++ ;
V_176 = V_6 -> V_186 [ V_44 ] . V_188 ;
}
} else if ( V_174 == - 1 ) {
V_174 = V_44 ;
}
}
if ( V_174 == - 1 ) {
F_29 ( V_2 -> V_53 -> V_54 , L_30 ) ;
return NULL ;
}
if ( V_169 == NULL ) {
if ( V_6 -> V_189 >= V_190 ) {
F_29 ( V_2 -> V_53 -> V_54 ,
L_31 ) ;
return NULL ;
}
for ( V_44 = 0 ; V_44 < V_190 ; ++ V_44 ) {
if ( V_6 -> V_191 [ V_44 ] == 0 ) {
V_176 = V_44 ;
V_6 -> V_191 [ V_44 ] = 1 ;
break;
}
}
if ( F_2 ( V_176 == - 1 ) )
return NULL ;
if ( V_171 -> V_35 == V_6 -> V_41 ) {
V_172 = V_171 ;
V_175 = V_76 ;
} else {
V_172 = F_43 ( V_2 , V_171 -> V_35 ) ;
V_175 = V_75 ;
}
snprintf ( V_32 , V_173 , L_32 , V_176 ) ;
F_18 ( V_2 -> V_53 -> V_54 ,
L_33 , V_32 ) ;
V_169 = F_34 ( V_2 , V_32 ,
V_166 ,
V_192 [ V_176 ] ,
V_113 [ V_176 ] ,
0x400 + ( V_176 * 0x10 ) ,
V_172 ,
V_175 ,
V_114 ) ;
if ( ! V_169 ) {
F_29 ( V_2 -> V_53 -> V_54 ,
L_34 ) ;
return NULL ;
}
V_6 -> V_189 ++ ;
}
snprintf ( V_32 , V_173 , L_35 , V_174 ) ;
F_18 ( V_2 -> V_53 -> V_54 , L_36 ,
V_32 , V_168 ) ;
V_170 = F_33 ( V_2 , V_32 ,
V_193 [ V_174 ] ,
( V_174 * 0x10 ) + 0x200 ,
V_174 ,
V_167 ,
NULL ,
0
) ;
if ( ! V_170 ) {
F_29 ( V_2 -> V_53 -> V_54 ,
L_37 ) ;
return NULL ;
}
F_13 ( & V_2 -> V_48 , V_45 ) ;
V_6 -> V_186 [ V_174 ] . V_166 = V_166 ;
V_6 -> V_186 [ V_174 ] . V_97 = V_170 ;
V_6 -> V_186 [ V_174 ] . V_169 = V_169 ;
V_6 -> V_186 [ V_174 ] . V_194 = 1 ;
V_6 -> V_186 [ V_174 ] . V_19 = V_19 ;
V_6 -> V_186 [ V_174 ] . V_188 = V_176 ;
V_6 -> V_186 [ V_174 ] . V_187 = 1 ;
V_6 -> V_186 [ V_174 ] . V_195 = V_174 ;
V_6 -> V_186 [ V_174 ] . V_171 = V_171 ;
V_6 -> V_196 ++ ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return ( V_6 -> V_186 + V_174 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_165 * V_197 ,
int V_198 )
{
V_33 V_199 = F_46 ( V_2 , V_197 -> V_97 -> V_31 << 2 ) ;
V_199 &= ~ V_200 ;
switch ( V_198 ) {
case 2048 :
V_199 |= V_99 ;
break;
case 1024 :
V_199 |= V_201 ;
break;
case 512 :
V_199 |= V_202 ;
break;
case 256 :
V_199 |= V_203 ;
break;
case 128 :
V_199 |= V_133 ;
break;
case 64 :
V_199 |= V_204 ;
break;
case 32 :
V_199 |= V_205 ;
break;
default:
F_18 ( V_2 -> V_53 -> V_54 ,
L_38 , V_198 ) ;
return - V_206 ;
}
F_47 ( V_2 , V_197 -> V_97 -> V_31 << 2 , V_199 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 ,
int V_198 )
{
V_33 V_199 = F_46 ( V_2 , V_207 << 2 ) ;
V_199 &= ~ V_208 ;
switch ( V_198 ) {
case 2048 :
V_199 |= V_135 ;
break;
case 1024 :
V_199 |= V_209 ;
break;
case 512 :
V_199 |= V_210 ;
break;
case 256 :
V_199 |= V_211 ;
break;
case 128 :
V_199 |= V_212 ;
break;
case 64 :
V_199 |= V_100 ;
break;
case 32 :
V_199 |= V_213 ;
break;
default:
F_18 ( V_2 -> V_53 -> V_54 ,
L_38 , V_198 ) ;
return - V_206 ;
}
F_47 ( V_2 , V_207 << 2 , V_199 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_165 * V_197 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
unsigned long V_45 ;
if ( F_2 ( ! V_197 -> V_187 ||
V_6 -> V_196 <= 0 ||
V_197 -> V_169 -> V_40 <= 0 ) )
return;
F_13 ( & V_2 -> V_48 , V_45 ) ;
V_197 -> V_194 = 1 ;
V_197 -> V_187 = 0 ;
V_197 -> V_19 = NULL ;
V_197 -> V_169 -> V_40 -- ;
V_6 -> V_196 -- ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
F_12 ( V_2 , V_197 -> V_97 ) ;
if ( ! V_197 -> V_169 -> V_40 ) {
F_12 ( V_2 , V_197 -> V_169 ) ;
if ( F_2 ( V_197 -> V_188 < 0 ||
V_197 -> V_188 >= V_190 ) )
return;
V_6 -> V_191 [ V_197 -> V_188 ] = 0 ;
V_6 -> V_189 -- ;
}
}
int F_50 ( struct V_1 * V_2 ,
struct V_165 * V_197 )
{
unsigned long V_45 ;
if ( F_2 ( ! V_197 -> V_187 ||
V_2 -> V_5 -> V_196 <= 0 ) )
return - V_214 ;
F_13 ( & V_2 -> V_48 , V_45 ) ;
if ( V_197 -> V_194 ) {
F_14 ( & V_2 -> V_48 , V_45 ) ;
return - V_214 ;
}
V_197 -> V_194 = 1 ;
F_8 ( V_2 , V_197 -> V_97 ) ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_165 * V_197 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_71 ;
struct V_20 * V_169 = V_197 -> V_169 ;
unsigned long V_45 ;
F_13 ( & V_2 -> V_48 , V_45 ) ;
if ( V_197 -> V_194 == 0 ) {
F_14 ( & V_2 -> V_48 , V_45 ) ;
return - V_214 ;
}
V_71 = V_169 ;
if ( V_169 -> V_35 != V_6 -> V_41 ) {
V_169 -> V_35 -> V_34 = V_197 -> V_97 ;
V_197 -> V_97 -> V_36 = V_169 -> V_35 ;
}
V_169 -> V_35 = V_197 -> V_97 ;
F_2 ( V_197 -> V_97 -> V_34 ) ;
V_197 -> V_97 -> V_34 = V_71 ;
F_9 ( V_2 , V_197 -> V_97 ) ;
F_9 ( V_2 , V_71 ) ;
V_197 -> V_194 = 0 ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return 0 ;
}
struct V_20 *
F_52 ( struct V_1 * V_2 , struct V_20 * V_215 ,
T_2 V_216 , char * V_32 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_217 ;
struct V_20 * V_218 ;
int V_175 ;
if ( F_2 ( ! V_6 -> V_219 ) )
return NULL ;
if ( V_6 -> V_219 -> V_35 != V_6 -> V_41 ) {
V_217 = F_43 ( V_2 , V_6 -> V_219 -> V_35 ) ;
V_175 = V_75 ;
} else {
V_217 = V_6 -> V_219 ;
V_175 = V_76 ;
}
V_218 = F_38 ( V_2 , V_32 , V_216 ,
V_215 , V_217 ,
V_175 ) ;
return V_218 ;
}
int F_53 ( struct V_1 * V_2 , struct V_20 * V_220 )
{
unsigned long V_45 ;
if ( F_2 ( ! V_220 -> V_34 ) )
return - V_206 ;
F_54 ( V_2 , V_220 , 0 , 0 ) ;
F_13 ( & V_2 -> V_48 , V_45 ) ;
F_8 ( V_2 , V_220 ) ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , struct V_20 * V_220 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_71 ;
if ( F_2 ( V_220 -> V_34 ) )
return - V_206 ;
if ( F_2 ( ! V_6 -> V_129 ) )
return - V_206 ;
if ( V_6 -> V_129 -> V_35 != V_6 -> V_41 ) {
V_71 = F_43 ( V_2 , V_6 -> V_129 -> V_35 ) ;
V_71 -> V_36 = V_220 ;
} else {
V_71 = V_6 -> V_129 ;
V_71 -> V_35 = V_220 ;
}
V_220 -> V_34 = V_71 ;
F_9 ( V_2 , V_71 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( ! ( V_6 -> V_221 & V_222 ) ) {
F_57 ( V_2 ) ;
}
if ( V_6 -> V_221 & V_223 ) {
V_6 -> V_221 |= V_224 ;
return - V_225 ;
}
if ( F_2 ( V_6 -> V_184 ) )
return - V_206 ;
if ( F_2 ( V_6 -> V_129 -> V_36 !=
V_6 -> V_41 ) )
return - V_206 ;
F_47 ( V_2 , ( V_6 -> V_226 -> V_31 + 2 ) << 2 ,
( V_227 + 0x10 ) << 0x10 ) ;
V_6 -> V_184 = F_39 ( V_2 , L_39 , V_228 ,
V_229 ,
V_230 ,
V_6 -> V_129 ,
V_75 ) ;
if ( ! V_6 -> V_184 ) return - V_231 ;
V_6 -> V_232 = F_38 ( V_2 , L_40 ,
V_233 ,
V_6 -> V_226 ,
V_6 -> V_184 ,
V_76 ) ;
if ( ! V_6 -> V_232 ) return - V_231 ;
V_6 -> V_221 |= V_224 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_6 -> V_221 & V_223 ) {
V_6 -> V_221 &= ~ V_224 ;
return - V_225 ;
}
if ( F_2 ( ! V_6 -> V_184 ) )
return - V_206 ;
if ( F_2 ( ! V_6 -> V_232 ) )
return - V_206 ;
if ( F_2 ( V_6 -> V_129 -> V_36 != V_6 -> V_184 ) )
return - V_206 ;
if ( F_2 ( V_6 -> V_184 -> V_34 !=
V_6 -> V_129 ) )
return - V_206 ;
F_12 ( V_2 , V_6 -> V_232 ) ;
F_12 ( V_2 , V_6 -> V_184 ) ;
V_6 -> V_232 = NULL ;
V_6 -> V_184 = NULL ;
F_10 ( V_2 , V_230 , 256 ) ;
V_6 -> V_221 &= ~ V_224 ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_6 -> V_221 & V_224 ) {
F_58 ( V_2 ) ;
V_6 -> V_221 |= V_224 ;
}
if ( ! ( V_6 -> V_221 & V_222 ) ) {
F_57 ( V_2 ) ;
}
V_6 -> V_184 = F_39 ( V_2 , L_39 , V_228 ,
V_229 ,
V_230 ,
V_6 -> V_129 ,
V_75 ) ;
F_60 ( V_2 , V_234 , V_6 -> V_235 ) ;
V_6 -> V_221 |= V_223 ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( F_2 ( ! V_6 -> V_184 ) )
return - V_206 ;
V_6 -> V_221 &= ~ V_223 ;
F_60 ( V_2 , V_234 , V_6 -> V_236 ) ;
if ( V_6 -> V_232 != NULL ) {
F_12 ( V_2 , V_6 -> V_232 ) ;
V_6 -> V_232 = NULL ;
}
F_12 ( V_2 , V_6 -> V_184 ) ;
V_6 -> V_184 = NULL ;
F_10 ( V_2 , V_230 , 256 ) ;
if ( V_6 -> V_221 & V_224 ) {
F_56 ( V_2 ) ;
}
return 0 ;
}
