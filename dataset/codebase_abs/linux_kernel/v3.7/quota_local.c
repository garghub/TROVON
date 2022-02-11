static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 - V_4 ) /
sizeof( struct V_5 ) ) ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 - sizeof( struct V_6 ) -
V_4 ) << 3 ) /
F_1 ( V_2 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) * F_1 ( V_2 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_7 )
{
return 1 + ( F_2 ( V_2 ) + 1 ) * V_7 ;
}
static unsigned int F_5 ( struct V_1 * V_2 , int V_7 , int V_8 )
{
int V_9 = F_1 ( V_2 ) ;
return F_4 ( V_2 , V_7 ) + 1 + V_8 / V_9 ;
}
static unsigned int F_6 ( struct V_1 * V_2 , int V_7 , int V_8 )
{
int V_9 = F_1 ( V_2 ) ;
return ( V_8 % V_9 ) * sizeof( struct V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , int V_7 , int V_8 )
{
return ( F_5 ( V_2 , V_7 , V_8 ) << V_2 -> V_10 ) +
F_6 ( V_2 , V_7 , V_8 ) ;
}
static inline unsigned int F_8 ( struct V_1 * V_2 , T_1 V_8 )
{
return V_8 >> V_2 -> V_10 ;
}
static inline unsigned int F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
return V_8 & ( ( 1 << V_2 -> V_10 ) - 1 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_7 , T_1 V_8 )
{
int V_9 = F_1 ( V_2 ) ;
return ( ( V_8 >> V_2 -> V_10 ) -
F_4 ( V_2 , V_7 ) - 1 ) * V_9
+ ( ( unsigned int ) ( V_8 & ( ( 1 << V_2 -> V_10 ) - 1 ) ) ) /
sizeof( struct V_5 ) ;
}
static int F_11 ( struct V_11 * V_11 , struct V_12 * V_13 ,
void (* F_12)( struct V_12 * , void * ) , void * V_14 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
T_2 * V_16 ;
int V_17 ;
V_16 = F_13 ( F_14 ( V_2 ) ,
V_18 ) ;
if ( F_15 ( V_16 ) ) {
V_17 = F_16 ( V_16 ) ;
F_17 ( V_17 ) ;
return V_17 ;
}
V_17 = F_18 ( V_16 , F_19 ( V_11 ) , V_13 ,
V_19 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
F_20 ( F_14 ( V_2 ) , V_16 ) ;
return V_17 ;
}
F_21 ( V_13 ) ;
F_12 ( V_13 , V_14 ) ;
F_22 ( V_13 ) ;
F_23 ( V_16 , V_13 ) ;
V_17 = F_20 ( F_14 ( V_2 ) , V_16 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int F_24 ( struct V_11 * V_11 , T_3 V_20 ,
struct V_12 * * V_13 )
{
int V_21 = 0 ;
struct V_12 * V_22 = * V_13 ;
if ( F_25 ( V_11 ) >> V_11 -> V_15 -> V_10 <= V_20 ) {
F_26 ( V_11 -> V_15 ,
L_1
L_2 ,
( unsigned long long ) F_27 ( V_11 ) -> V_23 ,
( unsigned long long ) V_20 ,
( unsigned long long ) F_25 ( V_11 ) ) ;
return - V_24 ;
}
V_21 = F_28 ( V_11 , V_20 , 1 , & V_22 , 0 ,
V_25 ) ;
if ( V_21 )
F_17 ( V_21 ) ;
if ( ! V_21 && ! * V_13 )
* V_13 = V_22 ;
return V_21 ;
}
static int F_29 ( struct V_1 * V_2 , int type )
{
unsigned int V_26 [ V_27 ] = V_28 ;
unsigned int V_29 [ V_27 ] = V_30 ;
unsigned int V_31 [ V_27 ] = V_32 ;
unsigned int V_33 [ V_27 ] = V_34 ;
unsigned int V_35 [ V_27 ] = { V_36 ,
V_37 } ;
struct V_12 * V_13 = NULL ;
struct V_11 * V_38 = F_30 ( V_2 ) -> V_39 [ type ] ;
struct V_11 * V_40 = NULL ;
struct V_41 * V_42 ;
int V_17 , V_43 = 0 ;
V_17 = F_24 ( V_38 , 0 , & V_13 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
F_31 ( V_44 , L_3 ,
type ) ;
goto V_45;
}
V_42 = (struct V_41 * ) ( V_13 -> V_46 ) ;
if ( F_32 ( V_42 -> V_47 ) != V_26 [ type ] ) {
F_31 ( V_44 , L_4
L_5 , F_32 ( V_42 -> V_47 ) ,
V_26 [ type ] , type ) ;
goto V_45;
}
if ( F_32 ( V_42 -> V_48 ) != V_29 [ type ] ) {
F_31 ( V_44 , L_6
L_5 , F_32 ( V_42 -> V_48 ) ,
V_29 [ type ] , type ) ;
goto V_45;
}
F_33 ( V_13 ) ;
V_13 = NULL ;
V_40 = F_34 ( F_14 ( V_2 ) , V_35 [ type ] ,
V_49 ) ;
if ( ! V_40 ) {
F_31 ( V_44 , L_7
L_8 , type ) ;
goto V_45;
}
V_17 = F_24 ( V_40 , 0 , & V_13 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
F_31 ( V_44 , L_9
L_8 , type ) ;
goto V_45;
}
V_42 = (struct V_41 * ) ( V_13 -> V_46 ) ;
if ( F_32 ( V_42 -> V_47 ) != V_31 [ type ] ) {
F_31 ( V_44 , L_10
L_11 ,
F_32 ( V_42 -> V_47 ) , V_31 [ type ] , type ) ;
goto V_45;
}
if ( F_32 ( V_42 -> V_48 ) != V_33 [ type ] ) {
F_31 ( V_44 , L_12
L_11 ,
F_32 ( V_42 -> V_48 ) , V_33 [ type ] ,
type ) ;
goto V_45;
}
V_43 = 1 ;
V_45:
F_33 ( V_13 ) ;
F_35 ( V_40 ) ;
return V_43 ;
}
static void F_36 ( struct V_50 * V_51 )
{
struct V_52 * V_53 , * V_54 ;
F_37 (pos, next, head, qc_chunk) {
F_38 ( & V_53 -> V_55 ) ;
F_33 ( V_53 -> V_56 ) ;
F_39 ( V_57 , V_53 ) ;
}
}
static int F_40 ( struct V_11 * V_11 ,
struct V_58 * V_59 ,
struct V_50 * V_51 )
{
struct V_52 * V_60 ;
int V_61 , V_17 ;
F_41 ( V_51 ) ;
for ( V_61 = 0 ; V_61 < F_32 ( V_59 -> V_62 ) ; V_61 ++ ) {
V_60 = F_42 ( V_57 , V_63 ) ;
if ( ! V_60 ) {
F_36 ( V_51 ) ;
return - V_64 ;
}
V_60 -> V_65 = V_61 ;
V_60 -> V_56 = NULL ;
V_17 = F_24 ( V_11 ,
F_4 ( V_11 -> V_15 , V_61 ) ,
& V_60 -> V_56 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
F_39 ( V_57 , V_60 ) ;
F_36 ( V_51 ) ;
return V_17 ;
}
F_43 ( & V_60 -> V_55 , V_51 ) ;
}
return 0 ;
}
static void F_44 ( struct V_12 * V_13 , void * V_14 )
{
struct V_66 * V_67 = V_14 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
F_45 ( & V_72 ) ;
V_59 -> V_73 = F_46 ( V_67 -> V_73 & V_74 ) ;
V_59 -> V_62 = F_46 ( V_69 -> V_62 ) ;
V_59 -> V_75 = F_46 ( V_69 -> V_75 ) ;
F_47 ( & V_72 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_6 * V_76 ,
int V_77 ,
struct V_50 * V_51 )
{
struct V_78 * V_21 ;
V_21 = F_49 ( sizeof( struct V_78 ) , V_63 ) ;
if ( ! V_21 )
return - V_64 ;
V_21 -> V_79 = V_77 ;
V_21 -> V_80 = F_49 ( V_2 -> V_3 , V_63 ) ;
if ( ! V_21 -> V_80 ) {
F_50 ( V_21 ) ;
return - V_64 ;
}
memcpy ( V_21 -> V_80 , V_76 -> V_81 ,
( F_3 ( V_2 ) + 7 ) >> 3 ) ;
F_43 ( & V_21 -> V_82 , V_51 ) ;
return 0 ;
}
static void F_51 ( struct V_50 * V_51 )
{
struct V_78 * V_54 ;
struct V_78 * V_83 ;
F_37 (rchunk, next, head, rc_list) {
F_38 ( & V_83 -> V_82 ) ;
F_50 ( V_83 -> V_80 ) ;
F_50 ( V_83 ) ;
}
}
void F_52 ( struct V_84 * V_85 )
{
int type ;
for ( type = 0 ; type < V_27 ; type ++ )
F_51 ( & ( V_85 -> V_86 [ type ] ) ) ;
F_50 ( V_85 ) ;
}
static int F_53 ( struct V_11 * V_87 ,
struct V_58 * V_59 ,
int type ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = V_87 -> V_15 ;
struct V_12 * V_88 ;
struct V_6 * V_76 ;
int V_61 , V_89 = F_32 ( V_59 -> V_62 ) ;
int V_17 = 0 ;
for ( V_61 = 0 ; V_61 < V_89 ; V_61 ++ ) {
V_88 = NULL ;
V_17 = F_24 ( V_87 ,
F_4 ( V_2 , V_61 ) ,
& V_88 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
break;
}
V_76 = (struct V_6 * ) V_88 -> V_46 ;
if ( F_32 ( V_76 -> V_90 ) < F_3 ( V_2 ) )
V_17 = F_48 ( V_2 , V_76 , V_61 , V_51 ) ;
F_33 ( V_88 ) ;
if ( V_17 < 0 )
break;
}
if ( V_17 < 0 )
F_51 ( V_51 ) ;
return V_17 ;
}
static struct V_84 * F_54 ( void )
{
int type ;
struct V_84 * V_85 ;
V_85 = F_49 ( sizeof( struct V_84 ) , V_63 ) ;
if ( ! V_85 )
return NULL ;
for ( type = 0 ; type < V_27 ; type ++ )
F_41 ( & ( V_85 -> V_86 [ type ] ) ) ;
return V_85 ;
}
struct V_84 * F_55 (
struct V_91 * V_92 ,
int V_93 )
{
unsigned int V_94 [ V_27 ] = { V_95 ,
V_96 } ;
unsigned int V_35 [ V_27 ] = { V_97 ,
V_98 } ;
struct V_1 * V_2 = V_92 -> V_2 ;
struct V_58 * V_59 ;
struct V_11 * V_87 ;
struct V_12 * V_13 ;
int type ;
int V_17 = 0 ;
struct V_84 * V_85 ;
F_56 ( V_99 L_13
L_14 , V_92 -> V_100 , V_93 ) ;
V_85 = F_54 () ;
if ( ! V_85 )
return F_57 ( - V_64 ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_58 ( V_2 , V_94 [ type ] ) )
continue;
V_87 = F_34 ( V_92 , V_35 [ type ] , V_93 ) ;
if ( ! V_87 ) {
V_17 = - V_101 ;
goto V_102;
}
V_17 = F_59 ( V_87 , NULL , 1 ,
V_103 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_104;
}
V_13 = NULL ;
V_17 = F_24 ( V_87 , 0 , & V_13 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
F_31 ( V_44 , L_15
L_16 , V_93 , type ) ;
goto V_105;
}
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
V_17 = F_53 ( V_87 , V_59 , type ,
& V_85 -> V_86 [ type ] ) ;
F_33 ( V_13 ) ;
V_105:
F_60 ( V_87 , 1 ) ;
V_104:
F_35 ( V_87 ) ;
if ( V_17 < 0 )
break;
}
V_102:
if ( V_17 < 0 ) {
F_52 ( V_85 ) ;
V_85 = F_57 ( V_17 ) ;
}
return V_85 ;
}
static int F_61 ( struct V_11 * V_87 ,
int type ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_87 -> V_15 ;
struct V_68 * V_69 = F_62 ( V_2 , type ) -> V_70 ;
struct V_6 * V_76 ;
struct V_5 * V_106 ;
struct V_107 * V_107 ;
T_2 * V_16 ;
struct V_12 * V_88 = NULL , * V_108 = NULL ;
int V_17 = 0 ;
int V_109 , V_77 ;
struct V_78 * V_83 , * V_54 ;
T_4 V_110 , V_111 ;
F_63 ( ( unsigned long ) V_87 -> V_112 , type ) ;
F_37 (rchunk, next, &(rec->r_list[type]), rc_list) {
V_77 = V_83 -> V_79 ;
V_88 = NULL ;
V_17 = F_24 ( V_87 ,
F_4 ( V_2 , V_77 ) ,
& V_88 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
break;
}
V_76 = (struct V_6 * ) V_88 -> V_46 ;
F_64 (bit, rchunk->rc_bitmap, ol_chunk_entries(sb)) {
V_108 = NULL ;
V_17 = F_24 ( V_87 ,
F_5 ( V_2 , V_77 , V_109 ) ,
& V_108 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
break;
}
V_106 = (struct V_5 * ) ( V_108 -> V_46 +
F_6 ( V_2 , V_77 , V_109 ) ) ;
V_107 = F_65 ( V_2 ,
F_66 ( & V_113 , type ,
F_67 ( V_106 -> V_114 ) ) ) ;
if ( ! V_107 ) {
V_17 = - V_24 ;
F_31 ( V_44 , L_17
L_18
L_19 ,
( unsigned ) F_67 ( V_106 -> V_114 ) ,
type ) ;
goto V_115;
}
V_17 = F_68 ( V_69 , 1 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_116;
}
V_16 = F_13 ( F_14 ( V_2 ) ,
V_117 ) ;
if ( F_15 ( V_16 ) ) {
V_17 = F_16 ( V_16 ) ;
F_17 ( V_17 ) ;
goto V_118;
}
F_69 ( & F_30 ( V_2 ) -> V_119 ) ;
F_45 ( & V_72 ) ;
V_110 = F_67 ( V_106 -> V_120 ) ;
V_111 = F_67 ( V_106 -> V_121 ) ;
V_107 -> V_122 . V_123 += V_110 ;
V_107 -> V_122 . V_124 += V_111 ;
F_47 ( & V_72 ) ;
V_17 = F_70 ( V_107 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_125;
}
V_17 = F_18 ( V_16 ,
F_19 ( V_87 ) ,
V_108 , V_19 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_125;
}
F_21 ( V_108 ) ;
F_71 ( ! F_72 ( V_109 , V_76 -> V_81 ) ) ;
F_73 ( V_109 , V_76 -> V_81 ) ;
F_74 ( & V_76 -> V_90 , 1 ) ;
F_22 ( V_108 ) ;
F_23 ( V_16 , V_108 ) ;
V_125:
F_75 ( & F_30 ( V_2 ) -> V_119 ) ;
F_20 ( F_14 ( V_2 ) , V_16 ) ;
V_118:
F_76 ( V_69 , 1 ) ;
V_116:
F_77 ( V_107 ) ;
V_115:
F_33 ( V_108 ) ;
if ( V_17 < 0 )
break;
}
F_33 ( V_88 ) ;
F_38 ( & V_83 -> V_82 ) ;
F_50 ( V_83 -> V_80 ) ;
F_50 ( V_83 ) ;
if ( V_17 < 0 )
break;
}
if ( V_17 < 0 )
F_51 ( & ( V_85 -> V_86 [ type ] ) ) ;
if ( V_17 )
F_17 ( V_17 ) ;
return V_17 ;
}
int F_78 ( struct V_91 * V_92 ,
struct V_84 * V_85 ,
int V_93 )
{
unsigned int V_35 [ V_27 ] = { V_97 ,
V_98 } ;
struct V_1 * V_2 = V_92 -> V_2 ;
struct V_58 * V_59 ;
struct V_12 * V_13 ;
T_2 * V_16 ;
int type ;
int V_17 = 0 ;
struct V_11 * V_87 ;
unsigned int V_126 ;
F_56 ( V_99 L_20
L_14 , V_92 -> V_100 , V_93 ) ;
F_69 ( & F_30 ( V_2 ) -> V_127 ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( F_79 ( & ( V_85 -> V_86 [ type ] ) ) )
continue;
F_80 ( V_93 ) ;
V_87 = F_34 ( V_92 , V_35 [ type ] , V_93 ) ;
if ( ! V_87 ) {
V_17 = - V_101 ;
goto V_102;
}
V_17 = F_59 ( V_87 , NULL , 1 ,
V_128 ) ;
if ( V_17 == - V_129 ) {
F_56 ( V_99 L_21
L_22
L_23 , V_92 -> V_100 , V_93 ) ;
V_17 = 0 ;
goto V_104;
} else if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_104;
}
V_13 = NULL ;
V_17 = F_24 ( V_87 , 0 , & V_13 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
F_31 ( V_44 , L_15
L_16 , V_93 , type ) ;
goto V_105;
}
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
V_126 = F_32 ( V_59 -> V_73 ) ;
if ( ! ( V_126 & V_130 ) )
V_17 = F_61 ( V_87 ,
type ,
V_85 ) ;
if ( V_93 == V_92 -> V_93 )
goto V_131;
V_16 = F_13 ( V_92 ,
V_132 ) ;
if ( F_15 ( V_16 ) ) {
V_17 = F_16 ( V_16 ) ;
F_17 ( V_17 ) ;
goto V_131;
}
V_17 = F_18 ( V_16 , F_19 ( V_87 ) ,
V_13 ,
V_19 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
F_21 ( V_13 ) ;
V_59 -> V_73 = F_46 ( V_126 | V_130 ) ;
F_22 ( V_13 ) ;
F_23 ( V_16 , V_13 ) ;
V_133:
F_20 ( V_92 , V_16 ) ;
V_131:
F_33 ( V_13 ) ;
V_105:
F_60 ( V_87 , 1 ) ;
V_104:
F_35 ( V_87 ) ;
if ( V_17 < 0 )
break;
}
V_102:
F_75 ( & F_30 ( V_2 ) -> V_127 ) ;
F_50 ( V_85 ) ;
return V_17 ;
}
static int F_81 ( struct V_1 * V_2 , int type )
{
struct V_58 * V_59 ;
struct V_66 * V_67 = F_62 ( V_2 , type ) ;
struct V_68 * V_69 ;
struct V_11 * V_87 = F_30 ( V_2 ) -> V_39 [ type ] ;
int V_17 ;
struct V_12 * V_13 = NULL ;
struct V_84 * V_85 ;
int V_134 = 0 ;
F_75 ( & F_30 ( V_2 ) -> V_119 ) ;
V_67 -> V_135 = 0x7fffffffffffffffLL ;
V_67 -> V_136 = 0x7fffffffffffffffLL ;
V_69 = F_49 ( sizeof( struct V_68 ) , V_63 ) ;
if ( ! V_69 ) {
F_31 ( V_44 , L_24
L_25 ) ;
goto V_45;
}
V_67 -> V_70 = V_69 ;
V_69 -> V_137 = type ;
F_41 ( & V_69 -> V_138 ) ;
V_69 -> V_139 = NULL ;
V_69 -> V_140 = NULL ;
V_69 -> V_141 = NULL ;
V_17 = F_82 ( V_2 , type ) ;
if ( V_17 < 0 )
goto V_45;
V_17 = F_83 ( V_87 , & V_69 -> V_140 , 1 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_45;
}
V_134 = 1 ;
V_17 = F_24 ( V_87 , 0 , & V_13 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
F_31 ( V_44 , L_15
L_8 , type ) ;
goto V_45;
}
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
V_67 -> V_73 = F_32 ( V_59 -> V_73 ) ;
V_69 -> V_62 = F_32 ( V_59 -> V_62 ) ;
V_69 -> V_75 = F_32 ( V_59 -> V_75 ) ;
V_69 -> V_141 = V_13 ;
if ( ! ( V_67 -> V_73 & V_130 ) ) {
V_85 = F_14 ( V_2 ) -> V_142 ;
if ( ! V_85 ) {
V_85 = F_54 () ;
if ( ! V_85 ) {
V_17 = - V_64 ;
F_17 ( V_17 ) ;
goto V_45;
}
F_14 ( V_2 ) -> V_142 = V_85 ;
}
V_17 = F_53 ( V_87 , V_59 , type ,
& V_85 -> V_86 [ type ] ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_45;
}
}
V_17 = F_40 ( V_87 ,
V_59 ,
& V_69 -> V_138 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_45;
}
V_67 -> V_73 &= ~ V_130 ;
V_17 = F_11 ( V_87 , V_13 , F_44 , V_67 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_45;
}
F_69 ( & F_30 ( V_2 ) -> V_119 ) ;
return 0 ;
V_45:
if ( V_69 ) {
F_35 ( V_69 -> V_143 ) ;
F_84 ( F_14 ( V_2 ) , & V_69 -> V_144 ) ;
F_85 ( & V_69 -> V_144 ) ;
F_33 ( V_69 -> V_140 ) ;
if ( V_134 )
F_60 ( V_87 , 1 ) ;
F_36 ( & V_69 -> V_138 ) ;
F_50 ( V_69 ) ;
}
F_33 ( V_13 ) ;
F_69 ( & F_30 ( V_2 ) -> V_119 ) ;
return - 1 ;
}
static int F_86 ( struct V_1 * V_2 , int type )
{
struct V_66 * V_67 = F_62 ( V_2 , type ) ;
struct V_12 * V_13 = ( (struct V_68 * ) V_67 -> V_70 )
-> V_141 ;
int V_17 ;
V_17 = F_11 ( F_30 ( V_2 ) -> V_39 [ type ] , V_13 , F_44 ,
V_67 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , int type )
{
struct V_66 * V_67 = F_62 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_52 * V_77 ;
struct V_6 * V_76 ;
int V_145 = 1 , V_146 ;
int V_17 ;
F_35 ( V_69 -> V_143 ) ;
F_84 ( F_14 ( V_2 ) , & V_69 -> V_144 ) ;
F_85 ( & V_69 -> V_144 ) ;
F_88 (chunk, &oinfo->dqi_chunk, qc_chunk) {
V_76 = (struct V_6 * )
( V_77 -> V_56 -> V_46 ) ;
if ( V_77 -> V_65 < V_69 -> V_62 - 1 ) {
V_146 = F_3 ( V_2 ) ;
} else {
V_146 = ( V_69 -> V_75 -
F_4 ( V_2 , V_77 -> V_65 ) - 1 )
* F_1 ( V_2 ) ;
}
if ( F_32 ( V_76 -> V_90 ) != V_146 ) {
F_31 ( V_44 , L_26
L_27 , type ) ;
V_145 = 0 ;
}
}
F_36 ( & V_69 -> V_138 ) ;
if ( V_69 -> V_139 ) {
F_52 ( V_69 -> V_139 ) ;
V_145 = 0 ;
}
if ( ! V_145 )
goto V_102;
V_67 -> V_73 |= V_130 ;
V_17 = F_11 ( F_30 ( V_2 ) -> V_39 [ type ] ,
V_69 -> V_141 ,
F_44 ,
V_67 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_102:
F_60 ( F_30 ( V_2 ) -> V_39 [ type ] , 1 ) ;
F_33 ( V_69 -> V_141 ) ;
F_33 ( V_69 -> V_140 ) ;
F_50 ( V_69 ) ;
return 0 ;
}
static void F_89 ( struct V_12 * V_13 , void * V_14 )
{
struct V_147 * V_148 = V_14 ;
struct V_5 * V_106 ;
struct V_1 * V_2 = V_148 -> V_149 . V_150 ;
V_106 = (struct V_5 * ) ( V_13 -> V_46
+ F_9 ( V_2 , V_148 -> V_151 ) ) ;
V_106 -> V_114 = F_90 ( F_91 ( & V_113 ,
V_148 -> V_149 . V_152 ) ) ;
F_45 ( & V_72 ) ;
V_106 -> V_120 = F_90 ( V_148 -> V_149 . V_122 . V_123 -
V_148 -> V_153 ) ;
V_106 -> V_121 = F_90 ( V_148 -> V_149 . V_122 . V_124 -
V_148 -> V_154 ) ;
F_47 ( & V_72 ) ;
F_92 (
( unsigned long long ) F_67 ( V_106 -> V_120 ) ,
( unsigned long long ) F_67 ( V_106 -> V_121 ) ,
F_91 ( & V_113 , V_148 -> V_149 . V_152 ) ) ;
}
int F_93 ( struct V_107 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_150 ;
struct V_147 * V_148 = F_94 ( V_107 ) ;
struct V_12 * V_13 ;
struct V_11 * V_87 = F_30 ( V_2 ) -> V_39 [ V_107 -> V_152 . type ] ;
int V_17 ;
V_17 = F_95 ( V_87 , V_148 -> V_155 ,
& V_13 ) ;
if ( V_17 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_11 ( V_87 , V_13 , F_89 , V_148 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_102:
F_33 ( V_13 ) ;
return V_17 ;
}
static struct V_52 * F_96 ( struct V_1 * V_2 ,
int type ,
int * V_156 )
{
struct V_66 * V_67 = F_62 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_52 * V_77 ;
struct V_6 * V_76 ;
int V_157 = 0 , V_146 ;
F_88 (chunk, &oinfo->dqi_chunk, qc_chunk) {
V_76 = (struct V_6 * )
V_77 -> V_56 -> V_46 ;
if ( F_32 ( V_76 -> V_90 ) > 0 ) {
V_157 = 1 ;
break;
}
}
if ( ! V_157 )
return NULL ;
if ( V_77 -> V_65 < V_69 -> V_62 - 1 ) {
V_146 = F_3 ( V_2 ) ;
} else {
V_146 = ( V_69 -> V_75 -
F_4 ( V_2 , V_77 -> V_65 ) - 1 )
* F_1 ( V_2 ) ;
}
V_157 = F_97 ( V_76 -> V_81 , V_146 , 0 ) ;
if ( V_157 == V_146 ) {
F_31 ( V_44 , L_28
L_29 , V_77 -> V_65 ,
F_32 ( V_76 -> V_90 ) , type ) ;
return F_57 ( - V_24 ) ;
}
* V_156 = V_157 ;
return V_77 ;
}
static struct V_52 * F_98 (
struct V_1 * V_2 ,
int type ,
int * V_156 )
{
struct V_66 * V_67 = F_62 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_11 * V_87 = F_30 ( V_2 ) -> V_39 [ type ] ;
struct V_52 * V_77 = NULL ;
struct V_6 * V_76 ;
int V_17 ;
T_2 * V_16 ;
struct V_12 * V_13 = NULL , * V_158 = NULL ;
T_3 V_159 ;
V_17 = F_99 ( V_87 , NULL ,
V_87 -> V_160 + 2 * V_2 -> V_3 ,
V_87 -> V_160 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_100 ( V_87 , V_69 -> V_140 ,
V_87 -> V_160 + 2 * V_2 -> V_3 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_77 = F_42 ( V_57 , V_63 ) ;
if ( ! V_77 ) {
V_17 = - V_64 ;
F_17 ( V_17 ) ;
goto V_102;
}
V_16 = F_13 ( F_14 ( V_2 ) ,
V_132 +
2 * V_18 ) ;
if ( F_15 ( V_16 ) ) {
V_17 = F_16 ( V_16 ) ;
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_101 ( V_87 , V_69 -> V_75 ,
& V_159 , NULL , NULL ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
V_13 = F_102 ( V_2 , V_159 ) ;
if ( ! V_13 ) {
V_17 = - V_64 ;
F_17 ( V_17 ) ;
goto V_133;
}
V_76 = (struct V_6 * ) V_13 -> V_46 ;
F_103 ( F_19 ( V_87 ) , V_13 ) ;
V_17 = F_18 ( V_16 , F_19 ( V_87 ) , V_13 ,
V_161 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
F_21 ( V_13 ) ;
V_76 -> V_90 = F_46 ( F_1 ( V_2 ) ) ;
memset ( V_76 -> V_81 , 0 ,
V_2 -> V_3 - sizeof( struct V_6 ) -
V_4 ) ;
F_22 ( V_13 ) ;
F_23 ( V_16 , V_13 ) ;
V_17 = F_101 ( V_87 , V_69 -> V_75 + 1 ,
& V_159 , NULL , NULL ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
V_158 = F_102 ( V_2 , V_159 ) ;
if ( ! V_158 ) {
V_17 = - V_64 ;
F_17 ( V_17 ) ;
goto V_133;
}
F_103 ( F_19 ( V_87 ) , V_158 ) ;
V_17 = F_18 ( V_16 , F_19 ( V_87 ) , V_158 ,
V_161 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
F_21 ( V_158 ) ;
memset ( V_158 -> V_46 , 0 , V_2 -> V_3 - V_4 ) ;
F_22 ( V_158 ) ;
F_23 ( V_16 , V_158 ) ;
V_69 -> V_75 += 2 ;
V_69 -> V_62 ++ ;
V_17 = F_86 ( V_2 , type ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
V_17 = F_20 ( F_14 ( V_2 ) , V_16 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
F_43 ( & V_77 -> V_55 , & V_69 -> V_138 ) ;
V_77 -> V_65 = F_104 ( V_77 -> V_55 . V_162 ,
struct V_52 ,
V_55 ) -> V_65 + 1 ;
V_77 -> V_56 = V_13 ;
* V_156 = 0 ;
return V_77 ;
V_133:
F_20 ( F_14 ( V_2 ) , V_16 ) ;
V_102:
F_33 ( V_13 ) ;
F_33 ( V_158 ) ;
F_39 ( V_57 , V_77 ) ;
return F_57 ( V_17 ) ;
}
static struct V_52 * F_105 (
struct V_1 * V_2 ,
int type ,
int * V_156 )
{
struct V_66 * V_67 = F_62 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_52 * V_77 ;
struct V_11 * V_87 = F_30 ( V_2 ) -> V_39 [ type ] ;
struct V_6 * V_76 ;
int V_9 = F_1 ( V_2 ) ;
unsigned int V_163 ;
struct V_12 * V_13 ;
T_3 V_159 ;
int V_17 ;
T_2 * V_16 ;
if ( F_79 ( & V_69 -> V_138 ) )
return F_98 ( V_2 , type , V_156 ) ;
V_77 = F_104 ( V_69 -> V_138 . V_162 ,
struct V_52 , V_55 ) ;
V_163 = V_69 -> V_75 -
F_4 ( V_2 , V_77 -> V_65 ) - 1 ;
if ( F_2 ( V_2 ) == V_163 )
return F_98 ( V_2 , type , V_156 ) ;
V_17 = F_99 ( V_87 , NULL ,
V_87 -> V_160 + V_2 -> V_3 ,
V_87 -> V_160 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_100 ( V_87 , V_69 -> V_140 ,
V_87 -> V_160 + V_2 -> V_3 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_101 ( V_87 , V_69 -> V_75 ,
& V_159 , NULL , NULL ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_13 = F_102 ( V_2 , V_159 ) ;
if ( ! V_13 ) {
V_17 = - V_64 ;
F_17 ( V_17 ) ;
goto V_102;
}
F_103 ( F_19 ( V_87 ) , V_13 ) ;
V_16 = F_13 ( F_14 ( V_2 ) ,
V_132 +
2 * V_18 ) ;
if ( F_15 ( V_16 ) ) {
V_17 = F_16 ( V_16 ) ;
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_18 ( V_16 , F_19 ( V_87 ) , V_13 ,
V_161 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
F_21 ( V_13 ) ;
memset ( V_13 -> V_46 , 0 , V_2 -> V_3 ) ;
F_22 ( V_13 ) ;
F_23 ( V_16 , V_13 ) ;
V_17 = F_18 ( V_16 , F_19 ( V_87 ) ,
V_77 -> V_56 ,
V_19 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
V_76 = (struct V_6 * ) V_77 -> V_56 -> V_46 ;
F_21 ( V_77 -> V_56 ) ;
F_74 ( & V_76 -> V_90 , F_1 ( V_2 ) ) ;
F_22 ( V_77 -> V_56 ) ;
F_23 ( V_16 , V_77 -> V_56 ) ;
V_69 -> V_75 ++ ;
V_17 = F_86 ( V_2 , type ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_133;
}
V_17 = F_20 ( F_14 ( V_2 ) , V_16 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
* V_156 = V_163 * V_9 ;
return V_77 ;
V_133:
F_20 ( F_14 ( V_2 ) , V_16 ) ;
V_102:
return F_57 ( V_17 ) ;
}
static void F_106 ( struct V_12 * V_13 , void * V_14 )
{
int * V_156 = V_14 ;
struct V_6 * V_76 ;
V_76 = (struct V_6 * ) V_13 -> V_46 ;
F_107 ( * V_156 , V_76 -> V_81 ) ;
F_74 ( & V_76 -> V_90 , - 1 ) ;
}
int F_108 ( struct V_107 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_150 ;
int type = V_107 -> V_152 . type ;
struct V_11 * V_87 = F_30 ( V_2 ) -> V_39 [ type ] ;
struct V_52 * V_77 ;
struct V_147 * V_148 = F_94 ( V_107 ) ;
int V_156 ;
int V_17 ;
T_3 V_164 ;
F_109 ( & F_27 ( V_87 ) -> V_165 ) ;
V_77 = F_96 ( V_2 , type , & V_156 ) ;
if ( ! V_77 ) {
V_77 = F_105 ( V_2 , type , & V_156 ) ;
if ( F_15 ( V_77 ) ) {
V_17 = F_16 ( V_77 ) ;
goto V_102;
}
} else if ( F_15 ( V_77 ) ) {
V_17 = F_16 ( V_77 ) ;
goto V_102;
}
V_148 -> V_151 = F_7 ( V_2 , V_77 -> V_65 , V_156 ) ;
V_148 -> V_166 = V_77 ;
V_17 = F_101 ( V_87 ,
F_5 ( V_2 , V_77 -> V_65 , V_156 ) ,
& V_148 -> V_155 ,
& V_164 ,
NULL ) ;
V_17 = F_93 ( V_107 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_17 = F_11 ( V_87 , V_77 -> V_56 , F_106 ,
& V_156 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_102:
F_110 ( & F_27 ( V_87 ) -> V_165 ) ;
return V_17 ;
}
int F_111 ( T_2 * V_16 , struct V_107 * V_107 )
{
int V_17 ;
int type = V_107 -> V_152 . type ;
struct V_147 * V_148 = F_94 ( V_107 ) ;
struct V_1 * V_2 = V_107 -> V_150 ;
struct V_6 * V_76 ;
int V_156 ;
V_17 = F_18 ( V_16 ,
F_19 ( F_30 ( V_2 ) -> V_39 [ type ] ) ,
V_148 -> V_166 -> V_56 , V_19 ) ;
if ( V_17 < 0 ) {
F_17 ( V_17 ) ;
goto V_102;
}
V_156 = F_10 ( V_2 , V_148 -> V_166 -> V_65 ,
V_148 -> V_151 ) ;
V_76 = (struct V_6 * )
( V_148 -> V_166 -> V_56 -> V_46 ) ;
F_21 ( V_148 -> V_166 -> V_56 ) ;
F_73 ( V_156 , V_76 -> V_81 ) ;
F_74 ( & V_76 -> V_90 , 1 ) ;
F_22 ( V_148 -> V_166 -> V_56 ) ;
F_23 ( V_16 , V_148 -> V_166 -> V_56 ) ;
V_102:
F_112 ( V_167 , & V_107 -> V_168 ) ;
return V_17 ;
}
