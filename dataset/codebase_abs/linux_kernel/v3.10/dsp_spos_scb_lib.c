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
F_18 ( L_8 , V_21 -> V_32 ) ;
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
if ( V_6 -> V_53 != NULL && V_6 -> V_54 != NULL &&
V_21 -> V_52 == NULL ) {
if ( ( V_14 = F_21 ( V_6 -> V_53 , V_21 -> V_32 ,
V_6 -> V_54 ) ) != NULL ) {
V_18 = F_22 ( sizeof( struct V_17 ) , V_55 ) ;
if ( ! V_18 ) {
F_19 ( V_14 ) ;
V_14 = NULL ;
goto V_56;
}
V_18 -> V_2 = V_2 ;
V_18 -> V_22 = V_21 ;
V_14 -> V_57 = V_58 ;
V_14 -> V_19 = V_18 ;
V_14 -> V_59 = V_60 | V_61 | V_62 ;
V_14 -> V_63 . V_64 . V_65 = F_3 ;
if ( F_23 ( V_14 ) < 0 ) {
F_19 ( V_14 ) ;
F_17 ( V_18 ) ;
V_14 = NULL ;
}
}
V_56:
V_21 -> V_52 = V_14 ;
}
}
static struct V_20 *
F_24 ( struct V_1 * V_2 , char * V_66 , V_33 * V_67 , V_33 V_68 ,
struct V_3 * V_37 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
unsigned long V_45 ;
if ( F_2 ( ! V_6 -> V_41 ) )
return NULL ;
V_67 [ V_71 ] =
( V_6 -> V_41 -> V_31 << 0x10 ) | V_6 -> V_41 -> V_31 ;
V_67 [ V_72 ] &= 0xFFFF0000 ;
V_67 [ V_72 ] |= V_37 -> V_31 ;
F_18 ( L_9 , V_66 ) ;
V_21 = F_25 ( V_2 , V_66 , V_67 , V_68 ) ;
V_21 -> V_35 = V_6 -> V_41 ;
V_21 -> V_36 = V_6 -> V_41 ;
V_21 -> V_34 = V_69 ;
V_21 -> V_37 = V_37 ;
if ( V_21 -> V_34 ) {
#if 0
printk ("scb->parent_scb_ptr = %s\n",scb->parent_scb_ptr->scb_name);
printk ("scb->parent_scb_ptr->next_scb_ptr = %s\n",scb->parent_scb_ptr->next_scb_ptr->scb_name);
printk ("scb->parent_scb_ptr->sub_list_ptr = %s\n",scb->parent_scb_ptr->sub_list_ptr->scb_name);
#endif
if ( V_70 == V_73 ) {
if ( F_2 ( V_21 -> V_34 -> V_36 !=
V_6 -> V_41 ) )
return NULL ;
V_21 -> V_34 -> V_36 = V_21 ;
} else if ( V_70 == V_74 ) {
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
F_27 ( struct V_1 * V_2 , char * V_66 , V_33 * V_67 ,
V_33 V_68 , char * V_75 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_3 * V_37 ;
V_37 = F_28 ( V_2 , V_75 ,
V_76 ) ;
if ( V_37 == NULL ) {
F_29 ( V_77 L_10 , V_75 ) ;
return NULL ;
}
return F_24 ( V_2 , V_66 , V_67 , V_68 , V_37 ,
V_69 , V_70 ) ;
}
struct V_20 *
F_30 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_78 V_79 = {
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
0 , V_80 ,
0 , 0 ,
0 , 0 ,
0x0001 , 0x8000 ,
0x0001 , 0x0000 ,
0x00060000
} ;
V_21 = F_27 ( V_2 , L_11 , ( V_33 * ) & V_79 ,
V_81 ,
L_12 , NULL , V_82 ) ;
return V_21 ;
}
struct V_20 *
F_31 ( struct V_1 * V_2 , char * V_83 ,
T_2 V_84 , T_2 V_85 , T_2 V_86 ,
V_33 V_68 , struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_87 V_88 = {
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
0 , V_80 ,
0 ,
0 ,
V_84 , V_85 ,
0x0000 , 0x0080 ,
0 , V_86
} ;
V_21 = F_27 ( V_2 , V_83 , ( V_33 * ) & V_88 ,
V_68 , L_13 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_32 ( struct V_1 * V_2 , char * V_83 ,
T_2 V_84 , T_2 V_85 , T_2 V_42 ,
V_33 V_68 , struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_89 V_90 = {
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
V_91 + V_92 ,
V_42 << 0x10 ,
V_84 , V_85 ,
0x0000 , 0x0000 ,
0x80008000
} ;
V_21 = F_27 ( V_2 , V_83 , ( V_33 * ) & V_90 ,
V_68 , L_14 , V_69 ,
V_70 ) ;
return V_21 ;
}
static struct V_20 *
F_33 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_42 , V_33 V_68 ,
int V_93 , V_33 V_94 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_95 V_96 = {
{ V_97 +
V_98 +
V_99 +
V_100 +
V_101 +
15 ,
V_102 +
V_103 +
V_93 ,
V_94 ,
V_104 +
V_42
} ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
V_80 , V_80 ,
0 , V_80 ,
V_105 +
( 19 << V_106 ) +
( ( V_68 >> 4 ) << V_107 ) +
V_91 +
V_108 ,
( V_42 << 0x10 ) ,
0 ,
{
0xffff , 0xffff ,
0xffff , 0xffff
}
} ;
if ( V_6 -> V_109 == NULL ) {
V_6 -> V_109 = F_28 ( V_2 , L_15 ,
V_76 ) ;
if ( V_6 -> V_109 == NULL ) {
F_29 ( V_77 L_16 ) ;
return NULL ;
}
}
V_21 = F_24 ( V_2 , V_32 , ( V_33 * ) & V_96 ,
V_68 , V_6 -> V_109 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_34 ( struct V_1 * V_2 , char * V_32 ,
int V_110 ,
T_2 V_111 ,
T_2 V_112 , V_33 V_68 ,
struct V_20 * V_69 ,
int V_70 ,
int V_113 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
unsigned int V_114 , V_115 ;
unsigned int V_116 ;
unsigned int V_117 , V_118 ;
F_18 ( L_17 , V_32 , V_110 ) ;
V_114 = V_110 << 16 ;
V_116 = V_114 / 48000 ;
V_114 -= V_116 * 48000 ;
V_114 <<= 10 ;
V_116 <<= 10 ;
V_115 = V_114 / 48000 ;
V_116 += V_115 ;
V_114 -= V_115 * 48000 ;
V_117 = V_114 / V_119 ;
V_114 -= V_117 * V_119 ;
V_118 = V_114 ;
{
struct V_120 V_121 = {
0x0028 , 0x00c8 ,
0x5555 , 0x0000 ,
0x0000 , 0x0000 ,
V_111 , 1 ,
V_117 , V_118 ,
V_91 + V_108 ,
0x0000 , V_112 ,
0x0 ,
0x080 , ( V_112 + ( 24 * 4 ) ) ,
0 , 0 ,
0 , 0 ,
V_91 + V_122 ,
V_111 << 0x10 ,
V_116 ,
{
0xffff - V_6 -> V_123 , 0xffff - V_6 -> V_124 ,
0xffff - V_6 -> V_123 , 0xffff - V_6 -> V_124
}
} ;
if ( V_6 -> V_125 == NULL ) {
V_6 -> V_125 = F_28 ( V_2 , L_18 ,
V_76 ) ;
if ( V_6 -> V_125 == NULL ) {
F_29 ( V_77 L_19 ) ;
return NULL ;
}
}
F_10 ( V_2 , V_111 , 8 ) ;
F_10 ( V_2 , V_112 , 32 ) ;
if ( V_113 ) {
F_2 ( V_110 != 48000 ) ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_121 ,
V_68 , L_20 , V_69 ,
V_70 ) ;
} else {
V_21 = F_24 ( V_2 , V_32 , ( V_33 * ) & V_121 ,
V_68 , V_6 -> V_125 , V_69 ,
V_70 ) ;
}
}
return V_21 ;
}
struct V_20 *
F_35 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_126 , V_33 V_68 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_127 V_128 = {
{ 0 ,
0 ,
V_126 ,
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
V_91 + V_108 ,
( V_126 + ( 16 * 4 ) ) << 0x10 ,
0 ,
{
0x8000 , 0x8000 ,
0x8000 , 0x8000
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_128 ,
V_68 , L_21 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_36 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_126 , T_2 V_129 , V_33 V_68 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_130 V_131 = {
{
V_132 +
V_133 +
V_134 +
V_100 +
V_101 +
15 ,
V_102 +
V_135 +
V_136 ,
V_104 +
V_126 ,
0x0
} ,
{ 0 , 0 , 0 , 0 , 0 , } ,
0 , 0 ,
0 , V_129 ,
V_105 +
( 19 << V_106 ) +
( ( V_68 >> 4 ) << V_107 ) +
V_137 +
V_91 +
V_92 ,
( V_126 + ( 32 * 4 ) ) << 0x10 ,
1 , 0 ,
0x0001 , 0x0080 ,
0xFFFF , 0
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_131 ,
V_68 , L_22 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_37 ( struct V_1 * V_2 , char * V_32 ,
T_2 V_138 ,
T_2 V_139 ,
V_33 V_68 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_140 V_141 = {
0x0028 , 0x00c8 ,
0x5555 , 0x0000 ,
0x0000 , 0x0000 ,
V_138 , V_139 ,
0x0028 , 0x00c8 ,
V_91 + V_142 ,
0xFF800000 ,
0 ,
0x0080 , V_139 + ( 25 * 4 ) ,
0 , 0 ,
0 , 0 ,
V_91 + V_122 ,
V_138 << 0x10 ,
0x04000000 ,
{
0x8000 , 0x8000 ,
0xFFFF , 0xFFFF
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_141 ,
V_68 , L_23 , V_69 ,
V_70 ) ;
return V_21 ;
}
static struct V_20 *
F_38 ( struct V_1 * V_2 , char * V_32 , V_33 V_68 ,
struct V_20 * V_143 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_144 V_145 = {
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
V_91 + V_146 ,
0 ,
0 , V_143 -> V_31 ,
{
0x8000 , 0x8000 ,
0x8000 , 0x8000
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_145 ,
V_68 , L_24 , V_69 ,
V_70 ) ;
return V_21 ;
}
static struct V_20 *
F_39 ( struct V_1 * V_2 , char * V_32 , V_33 V_68 ,
T_2 V_147 ,
T_2 V_148 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_149 V_150 = {
0xfc00 , 0x03ff ,
0x0058 , 0x0028 ,
0 , V_147 ,
0 , 0 ,
0 ,
0 , 0x2aab ,
{
0 ,
0 ,
0
} ,
0 , 0 ,
0 , V_68 + V_151 ,
V_91 + V_142 ,
( V_148 ) << 0x10 ,
0x18000000 ,
0x8000 , 0x8000 ,
0x8000 , 0x8000
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_150 ,
V_68 , L_25 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_40 ( struct V_1 * V_2 , char * V_32 , V_33 V_68 ,
T_2 V_147 ,
T_2 V_148 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_152 V_153 = {
0xfe00 , 0x01ff ,
0x0064 , 0x001c ,
0 , V_147 ,
0 , 0 ,
{
0 ,
0 ,
0 ,
0 ,
0
} ,
0 , 0 ,
0 , V_68 ,
V_154 |
V_91 ,
( ( V_148 + ( 16 * 4 ) ) << 0x10 ) ,
0x18000000 ,
0xffff - V_6 -> V_155 , 0xffff - V_6 -> V_156 ,
0xffff - V_6 -> V_155 , 0xffff - V_6 -> V_156 ,
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_153 ,
V_68 , L_26 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_41 ( struct V_1 * V_2 , char * V_32 , V_33 V_68 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_157 V_158 = {
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
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_158 ,
V_68 , L_27 , V_69 ,
V_70 ) ;
return V_21 ;
}
struct V_20 *
F_42 ( struct V_1 * V_2 , char * V_32 , V_33 V_68 ,
T_2 V_159 ,
struct V_20 * V_160 ,
struct V_20 * V_69 ,
int V_70 )
{
struct V_20 * V_21 ;
struct V_161 V_162 = {
0 ,
0 ,
V_159 << 0x10 ,
0 , V_160 -> V_31 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0 , 0 ,
0 , 0 ,
V_91 + V_92 ,
V_159 << 0x10 ,
0 ,
{ 0x8000 , 0x8000 ,
0xffff , 0xffff
}
} ;
V_21 = F_27 ( V_2 , V_32 , ( V_33 * ) & V_162 ,
V_68 , L_28 , V_69 ,
V_70 ) ;
return V_21 ;
}
static struct V_20 *
F_43 ( struct V_1 * V_2 , struct V_20 * V_163 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_21 = V_163 ;
while ( V_21 -> V_36 != V_6 -> V_41 ) {
if ( F_2 ( ! V_21 -> V_36 ) )
return NULL ;
V_21 = V_21 -> V_36 ;
}
return V_21 ;
}
struct V_164 *
F_44 ( struct V_1 * V_2 ,
V_33 V_165 , void * V_19 ,
V_33 V_166 ,
int V_167 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_168 = NULL , * V_169 , * V_170 = NULL ;
struct V_20 * V_171 = NULL ;
char V_32 [ V_172 ] ;
int V_44 , V_173 = - 1 , V_174 , V_175 = - 1 , V_113 = 0 ;
unsigned long V_45 ;
switch ( V_167 ) {
case V_176 :
V_170 = V_6 -> V_128 ;
break;
case V_177 :
V_170 = V_6 -> V_178 ;
break;
case V_179 :
V_170 = V_6 -> V_180 ;
break;
case V_181 :
F_26 () ;
break;
case V_182 :
if ( F_2 ( ! V_6 -> V_183 ) )
return NULL ;
V_170 = V_6 -> V_183 ;
if ( V_165 == 48000 ) {
F_18 ( L_29 ) ;
V_113 = 1 ;
}
break;
default:
F_26 () ;
return NULL ;
}
if ( ! V_165 ) V_165 = 44100 ;
for ( V_44 = 0 ; V_44 < V_184 &&
( V_173 == - 1 || V_168 == NULL ) ; ++ V_44 ) {
if ( V_44 == V_136 ) continue;
if ( V_6 -> V_185 [ V_44 ] . V_186 ) {
if ( ! V_168 &&
V_6 -> V_185 [ V_44 ] . V_165 == V_165 &&
V_6 -> V_185 [ V_44 ] . V_170 == V_170 ) {
V_168 = V_6 -> V_185 [ V_44 ] . V_168 ;
V_6 -> V_185 [ V_44 ] . V_168 -> V_40 ++ ;
V_175 = V_6 -> V_185 [ V_44 ] . V_187 ;
}
} else if ( V_173 == - 1 ) {
V_173 = V_44 ;
}
}
if ( V_173 == - 1 ) {
F_29 ( V_77 L_30 ) ;
return NULL ;
}
if ( V_168 == NULL ) {
if ( V_6 -> V_188 >= V_189 ) {
F_29 ( V_77 L_31 ) ;
return NULL ;
}
for ( V_44 = 0 ; V_44 < V_189 ; ++ V_44 ) {
if ( V_6 -> V_190 [ V_44 ] == 0 ) {
V_175 = V_44 ;
V_6 -> V_190 [ V_44 ] = 1 ;
break;
}
}
if ( F_2 ( V_175 == - 1 ) )
return NULL ;
if ( V_170 -> V_35 == V_6 -> V_41 ) {
V_171 = V_170 ;
V_174 = V_74 ;
} else {
V_171 = F_43 ( V_2 , V_170 -> V_35 ) ;
V_174 = V_73 ;
}
snprintf ( V_32 , V_172 , L_32 , V_175 ) ;
F_18 ( L_33 , V_32 ) ;
V_168 = F_34 ( V_2 , V_32 ,
V_165 ,
V_191 [ V_175 ] ,
V_112 [ V_175 ] ,
0x400 + ( V_175 * 0x10 ) ,
V_171 ,
V_174 ,
V_113 ) ;
if ( ! V_168 ) {
F_29 ( V_77 L_34 ) ;
return NULL ;
}
V_6 -> V_188 ++ ;
}
snprintf ( V_32 , V_172 , L_35 , V_173 ) ;
F_18 ( L_36 , V_32 ,
V_167 ) ;
V_169 = F_33 ( V_2 , V_32 ,
V_192 [ V_173 ] ,
( V_173 * 0x10 ) + 0x200 ,
V_173 ,
V_166 ,
NULL ,
0
) ;
if ( ! V_169 ) {
F_29 ( V_77 L_37 ) ;
return NULL ;
}
F_13 ( & V_2 -> V_48 , V_45 ) ;
V_6 -> V_185 [ V_173 ] . V_165 = V_165 ;
V_6 -> V_185 [ V_173 ] . V_96 = V_169 ;
V_6 -> V_185 [ V_173 ] . V_168 = V_168 ;
V_6 -> V_185 [ V_173 ] . V_193 = 1 ;
V_6 -> V_185 [ V_173 ] . V_19 = V_19 ;
V_6 -> V_185 [ V_173 ] . V_187 = V_175 ;
V_6 -> V_185 [ V_173 ] . V_186 = 1 ;
V_6 -> V_185 [ V_173 ] . V_194 = V_173 ;
V_6 -> V_185 [ V_173 ] . V_170 = V_170 ;
V_6 -> V_195 ++ ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return ( V_6 -> V_185 + V_173 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_164 * V_196 ,
int V_197 )
{
V_33 V_198 = F_46 ( V_2 , V_196 -> V_96 -> V_31 << 2 ) ;
V_198 &= ~ V_199 ;
switch ( V_197 ) {
case 2048 :
V_198 |= V_98 ;
break;
case 1024 :
V_198 |= V_200 ;
break;
case 512 :
V_198 |= V_201 ;
break;
case 256 :
V_198 |= V_202 ;
break;
case 128 :
V_198 |= V_132 ;
break;
case 64 :
V_198 |= V_203 ;
break;
case 32 :
V_198 |= V_204 ;
break;
default:
F_18 ( L_38 , V_197 ) ;
return - V_205 ;
}
F_47 ( V_2 , V_196 -> V_96 -> V_31 << 2 , V_198 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 ,
int V_197 )
{
V_33 V_198 = F_46 ( V_2 , V_206 << 2 ) ;
V_198 &= ~ V_207 ;
switch ( V_197 ) {
case 2048 :
V_198 |= V_134 ;
break;
case 1024 :
V_198 |= V_208 ;
break;
case 512 :
V_198 |= V_209 ;
break;
case 256 :
V_198 |= V_210 ;
break;
case 128 :
V_198 |= V_211 ;
break;
case 64 :
V_198 |= V_99 ;
break;
case 32 :
V_198 |= V_212 ;
break;
default:
F_18 ( L_38 , V_197 ) ;
return - V_205 ;
}
F_47 ( V_2 , V_206 << 2 , V_198 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_164 * V_196 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
unsigned long V_45 ;
if ( F_2 ( ! V_196 -> V_186 ||
V_6 -> V_195 <= 0 ||
V_196 -> V_168 -> V_40 <= 0 ) )
return;
F_13 ( & V_2 -> V_48 , V_45 ) ;
V_196 -> V_193 = 1 ;
V_196 -> V_186 = 0 ;
V_196 -> V_19 = NULL ;
V_196 -> V_168 -> V_40 -- ;
V_6 -> V_195 -- ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
F_12 ( V_2 , V_196 -> V_96 ) ;
if ( ! V_196 -> V_168 -> V_40 ) {
F_12 ( V_2 , V_196 -> V_168 ) ;
if ( F_2 ( V_196 -> V_187 < 0 ||
V_196 -> V_187 >= V_189 ) )
return;
V_6 -> V_190 [ V_196 -> V_187 ] = 0 ;
V_6 -> V_188 -- ;
}
}
int F_50 ( struct V_1 * V_2 ,
struct V_164 * V_196 )
{
unsigned long V_45 ;
if ( F_2 ( ! V_196 -> V_186 ||
V_2 -> V_5 -> V_195 <= 0 ) )
return - V_213 ;
F_13 ( & V_2 -> V_48 , V_45 ) ;
if ( V_196 -> V_193 ) {
F_14 ( & V_2 -> V_48 , V_45 ) ;
return - V_213 ;
}
V_196 -> V_193 = 1 ;
F_8 ( V_2 , V_196 -> V_96 ) ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_164 * V_196 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_69 ;
struct V_20 * V_168 = V_196 -> V_168 ;
unsigned long V_45 ;
F_13 ( & V_2 -> V_48 , V_45 ) ;
if ( V_196 -> V_193 == 0 ) {
F_14 ( & V_2 -> V_48 , V_45 ) ;
return - V_213 ;
}
V_69 = V_168 ;
if ( V_168 -> V_35 != V_6 -> V_41 ) {
V_168 -> V_35 -> V_34 = V_196 -> V_96 ;
V_196 -> V_96 -> V_36 = V_168 -> V_35 ;
}
V_168 -> V_35 = V_196 -> V_96 ;
F_2 ( V_196 -> V_96 -> V_34 ) ;
V_196 -> V_96 -> V_34 = V_69 ;
F_9 ( V_2 , V_196 -> V_96 ) ;
F_9 ( V_2 , V_69 ) ;
V_196 -> V_193 = 0 ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return 0 ;
}
struct V_20 *
F_52 ( struct V_1 * V_2 , struct V_20 * V_214 ,
T_2 V_215 , char * V_32 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_216 ;
struct V_20 * V_217 ;
int V_174 ;
if ( F_2 ( ! V_6 -> V_218 ) )
return NULL ;
if ( V_6 -> V_218 -> V_35 != V_6 -> V_41 ) {
V_216 = F_43 ( V_2 , V_6 -> V_218 -> V_35 ) ;
V_174 = V_73 ;
} else {
V_216 = V_6 -> V_218 ;
V_174 = V_74 ;
}
V_217 = F_38 ( V_2 , V_32 , V_215 ,
V_214 , V_216 ,
V_174 ) ;
return V_217 ;
}
int F_53 ( struct V_1 * V_2 , struct V_20 * V_219 )
{
unsigned long V_45 ;
if ( F_2 ( ! V_219 -> V_34 ) )
return - V_205 ;
F_54 ( V_2 , V_219 , 0 , 0 ) ;
F_13 ( & V_2 -> V_48 , V_45 ) ;
F_8 ( V_2 , V_219 ) ;
F_14 ( & V_2 -> V_48 , V_45 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , struct V_20 * V_219 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_20 * V_69 ;
if ( F_2 ( V_219 -> V_34 ) )
return - V_205 ;
if ( F_2 ( ! V_6 -> V_128 ) )
return - V_205 ;
if ( V_6 -> V_128 -> V_35 != V_6 -> V_41 ) {
V_69 = F_43 ( V_2 , V_6 -> V_128 -> V_35 ) ;
V_69 -> V_36 = V_219 ;
} else {
V_69 = V_6 -> V_128 ;
V_69 -> V_35 = V_219 ;
}
V_219 -> V_34 = V_69 ;
F_9 ( V_2 , V_69 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( ! ( V_6 -> V_220 & V_221 ) ) {
F_57 ( V_2 ) ;
}
if ( V_6 -> V_220 & V_222 ) {
V_6 -> V_220 |= V_223 ;
return - V_224 ;
}
if ( F_2 ( V_6 -> V_183 ) )
return - V_205 ;
if ( F_2 ( V_6 -> V_128 -> V_36 !=
V_6 -> V_41 ) )
return - V_205 ;
F_47 ( V_2 , ( V_6 -> V_225 -> V_31 + 2 ) << 2 ,
( V_226 + 0x10 ) << 0x10 ) ;
V_6 -> V_183 = F_39 ( V_2 , L_39 , V_227 ,
V_228 ,
V_229 ,
V_6 -> V_128 ,
V_73 ) ;
if ( ! V_6 -> V_183 ) return - V_230 ;
V_6 -> V_231 = F_38 ( V_2 , L_40 ,
V_232 ,
V_6 -> V_225 ,
V_6 -> V_183 ,
V_74 ) ;
if ( ! V_6 -> V_231 ) return - V_230 ;
V_6 -> V_220 |= V_223 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_6 -> V_220 & V_222 ) {
V_6 -> V_220 &= ~ V_223 ;
return - V_224 ;
}
if ( F_2 ( ! V_6 -> V_183 ) )
return - V_205 ;
if ( F_2 ( ! V_6 -> V_231 ) )
return - V_205 ;
if ( F_2 ( V_6 -> V_128 -> V_36 != V_6 -> V_183 ) )
return - V_205 ;
if ( F_2 ( V_6 -> V_183 -> V_34 !=
V_6 -> V_128 ) )
return - V_205 ;
F_12 ( V_2 , V_6 -> V_231 ) ;
F_12 ( V_2 , V_6 -> V_183 ) ;
V_6 -> V_231 = NULL ;
V_6 -> V_183 = NULL ;
F_10 ( V_2 , V_229 , 256 ) ;
V_6 -> V_220 &= ~ V_223 ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( V_6 -> V_220 & V_223 ) {
F_58 ( V_2 ) ;
V_6 -> V_220 |= V_223 ;
}
if ( ! ( V_6 -> V_220 & V_221 ) ) {
F_57 ( V_2 ) ;
}
V_6 -> V_183 = F_39 ( V_2 , L_39 , V_227 ,
V_228 ,
V_229 ,
V_6 -> V_128 ,
V_73 ) ;
F_60 ( V_2 , V_233 , V_6 -> V_234 ) ;
V_6 -> V_220 |= V_222 ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
if ( F_2 ( ! V_6 -> V_183 ) )
return - V_205 ;
V_6 -> V_220 &= ~ V_222 ;
F_60 ( V_2 , V_233 , V_6 -> V_235 ) ;
if ( V_6 -> V_231 != NULL ) {
F_12 ( V_2 , V_6 -> V_231 ) ;
V_6 -> V_231 = NULL ;
}
F_12 ( V_2 , V_6 -> V_183 ) ;
V_6 -> V_183 = NULL ;
F_10 ( V_2 , V_229 , 256 ) ;
if ( V_6 -> V_220 & V_223 ) {
F_56 ( V_2 ) ;
}
return 0 ;
}
