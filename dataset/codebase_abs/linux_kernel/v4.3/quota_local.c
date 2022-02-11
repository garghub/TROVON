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
return V_8 & ( ( 1 << V_2 -> V_10 ) - 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_7 , T_1 V_8 )
{
int V_9 = F_1 ( V_2 ) ;
return ( ( V_8 >> V_2 -> V_10 ) -
F_4 ( V_2 , V_7 ) - 1 ) * V_9
+ ( ( unsigned int ) ( V_8 & ( ( 1 << V_2 -> V_10 ) - 1 ) ) ) /
sizeof( struct V_5 ) ;
}
static int F_10 ( struct V_11 * V_11 , struct V_12 * V_13 ,
void (* F_11)( struct V_12 * , void * ) , void * V_14 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
T_2 * V_16 ;
int V_17 ;
V_16 = F_12 ( F_13 ( V_2 ) ,
V_18 ) ;
if ( F_14 ( V_16 ) ) {
V_17 = F_15 ( V_16 ) ;
F_16 ( V_17 ) ;
return V_17 ;
}
V_17 = F_17 ( V_16 , F_18 ( V_11 ) , V_13 ,
V_19 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
F_19 ( F_13 ( V_2 ) , V_16 ) ;
return V_17 ;
}
F_20 ( V_13 ) ;
F_11 ( V_13 , V_14 ) ;
F_21 ( V_13 ) ;
F_22 ( V_16 , V_13 ) ;
V_17 = F_19 ( F_13 ( V_2 ) , V_16 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int F_23 ( struct V_11 * V_11 , T_3 V_20 ,
struct V_12 * * V_13 )
{
int V_21 = 0 ;
struct V_12 * V_22 = * V_13 ;
if ( F_24 ( V_11 ) >> V_11 -> V_15 -> V_10 <= V_20 ) {
F_25 ( V_11 -> V_15 ,
L_1 ,
( unsigned long long ) F_26 ( V_11 ) -> V_23 ,
( unsigned long long ) V_20 ,
( unsigned long long ) F_24 ( V_11 ) ) ;
return - V_24 ;
}
V_21 = F_27 ( V_11 , V_20 , 1 , & V_22 , 0 ,
V_25 ) ;
if ( V_21 )
F_16 ( V_21 ) ;
if ( ! V_21 && ! * V_13 )
* V_13 = V_22 ;
return V_21 ;
}
static int F_28 ( struct V_1 * V_2 , int type )
{
unsigned int V_26 [ V_27 ] = V_28 ;
unsigned int V_29 [ V_27 ] = V_30 ;
unsigned int V_31 [ V_27 ] = V_32 ;
unsigned int V_33 [ V_27 ] = V_34 ;
unsigned int V_35 [ V_27 ] = { V_36 ,
V_37 } ;
struct V_12 * V_13 = NULL ;
struct V_11 * V_38 = F_29 ( V_2 ) -> V_39 [ type ] ;
struct V_11 * V_40 = NULL ;
struct V_41 * V_42 ;
int V_17 , V_43 = 0 ;
V_17 = F_23 ( V_38 , 0 , & V_13 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
F_30 ( V_44 , L_2 ,
type ) ;
goto V_45;
}
V_42 = (struct V_41 * ) ( V_13 -> V_46 ) ;
if ( F_31 ( V_42 -> V_47 ) != V_26 [ type ] ) {
F_30 ( V_44 , L_3
L_4 , F_31 ( V_42 -> V_47 ) ,
V_26 [ type ] , type ) ;
goto V_45;
}
if ( F_31 ( V_42 -> V_48 ) != V_29 [ type ] ) {
F_30 ( V_44 , L_5
L_4 , F_31 ( V_42 -> V_48 ) ,
V_29 [ type ] , type ) ;
goto V_45;
}
F_32 ( V_13 ) ;
V_13 = NULL ;
V_40 = F_33 ( F_13 ( V_2 ) , V_35 [ type ] ,
V_49 ) ;
if ( ! V_40 ) {
F_30 ( V_44 , L_6
L_7 , type ) ;
goto V_45;
}
V_17 = F_23 ( V_40 , 0 , & V_13 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
F_30 ( V_44 , L_8
L_7 , type ) ;
goto V_45;
}
V_42 = (struct V_41 * ) ( V_13 -> V_46 ) ;
if ( F_31 ( V_42 -> V_47 ) != V_31 [ type ] ) {
F_30 ( V_44 , L_9
L_10 ,
F_31 ( V_42 -> V_47 ) , V_31 [ type ] , type ) ;
goto V_45;
}
if ( F_31 ( V_42 -> V_48 ) != V_33 [ type ] ) {
F_30 ( V_44 , L_11
L_10 ,
F_31 ( V_42 -> V_48 ) , V_33 [ type ] ,
type ) ;
goto V_45;
}
V_43 = 1 ;
V_45:
F_32 ( V_13 ) ;
F_34 ( V_40 ) ;
return V_43 ;
}
static void F_35 ( struct V_50 * V_51 )
{
struct V_52 * V_53 , * V_54 ;
F_36 (pos, next, head, qc_chunk) {
F_37 ( & V_53 -> V_55 ) ;
F_32 ( V_53 -> V_56 ) ;
F_38 ( V_57 , V_53 ) ;
}
}
static int F_39 ( struct V_11 * V_11 ,
struct V_58 * V_59 ,
struct V_50 * V_51 )
{
struct V_52 * V_60 ;
int V_61 , V_17 ;
F_40 ( V_51 ) ;
for ( V_61 = 0 ; V_61 < F_31 ( V_59 -> V_62 ) ; V_61 ++ ) {
V_60 = F_41 ( V_57 , V_63 ) ;
if ( ! V_60 ) {
F_35 ( V_51 ) ;
return - V_64 ;
}
V_60 -> V_65 = V_61 ;
V_60 -> V_56 = NULL ;
V_17 = F_23 ( V_11 ,
F_4 ( V_11 -> V_15 , V_61 ) ,
& V_60 -> V_56 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
F_38 ( V_57 , V_60 ) ;
F_35 ( V_51 ) ;
return V_17 ;
}
F_42 ( & V_60 -> V_55 , V_51 ) ;
}
return 0 ;
}
static void F_43 ( struct V_12 * V_13 , void * V_14 )
{
struct V_66 * V_67 = V_14 ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
F_44 ( & V_72 ) ;
V_59 -> V_73 = F_45 ( V_69 -> V_73 ) ;
V_59 -> V_62 = F_45 ( V_69 -> V_62 ) ;
V_59 -> V_74 = F_45 ( V_69 -> V_74 ) ;
F_46 ( & V_72 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_6 * V_75 ,
int V_76 ,
struct V_50 * V_51 )
{
struct V_77 * V_21 ;
V_21 = F_48 ( sizeof( struct V_77 ) , V_63 ) ;
if ( ! V_21 )
return - V_64 ;
V_21 -> V_78 = V_76 ;
V_21 -> V_79 = F_48 ( V_2 -> V_3 , V_63 ) ;
if ( ! V_21 -> V_79 ) {
F_49 ( V_21 ) ;
return - V_64 ;
}
memcpy ( V_21 -> V_79 , V_75 -> V_80 ,
( F_3 ( V_2 ) + 7 ) >> 3 ) ;
F_42 ( & V_21 -> V_81 , V_51 ) ;
return 0 ;
}
static void F_50 ( struct V_50 * V_51 )
{
struct V_77 * V_54 ;
struct V_77 * V_82 ;
F_36 (rchunk, next, head, rc_list) {
F_37 ( & V_82 -> V_81 ) ;
F_49 ( V_82 -> V_79 ) ;
F_49 ( V_82 ) ;
}
}
void F_51 ( struct V_83 * V_84 )
{
int type ;
for ( type = 0 ; type < V_27 ; type ++ )
F_50 ( & ( V_84 -> V_85 [ type ] ) ) ;
F_49 ( V_84 ) ;
}
static int F_52 ( struct V_11 * V_86 ,
struct V_58 * V_59 ,
int type ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = V_86 -> V_15 ;
struct V_12 * V_87 ;
struct V_6 * V_75 ;
int V_61 , V_88 = F_31 ( V_59 -> V_62 ) ;
int V_17 = 0 ;
for ( V_61 = 0 ; V_61 < V_88 ; V_61 ++ ) {
V_87 = NULL ;
V_17 = F_23 ( V_86 ,
F_4 ( V_2 , V_61 ) ,
& V_87 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
break;
}
V_75 = (struct V_6 * ) V_87 -> V_46 ;
if ( F_31 ( V_75 -> V_89 ) < F_3 ( V_2 ) )
V_17 = F_47 ( V_2 , V_75 , V_61 , V_51 ) ;
F_32 ( V_87 ) ;
if ( V_17 < 0 )
break;
}
if ( V_17 < 0 )
F_50 ( V_51 ) ;
return V_17 ;
}
static struct V_83 * F_53 ( void )
{
int type ;
struct V_83 * V_84 ;
V_84 = F_48 ( sizeof( struct V_83 ) , V_63 ) ;
if ( ! V_84 )
return NULL ;
for ( type = 0 ; type < V_27 ; type ++ )
F_40 ( & ( V_84 -> V_85 [ type ] ) ) ;
return V_84 ;
}
struct V_83 * F_54 (
struct V_90 * V_91 ,
int V_92 )
{
unsigned int V_93 [ V_27 ] = {
V_94 ,
V_95 } ;
unsigned int V_35 [ V_27 ] = { V_96 ,
V_97 } ;
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_58 * V_59 ;
struct V_11 * V_86 ;
struct V_12 * V_13 ;
int type ;
int V_17 = 0 ;
struct V_83 * V_84 ;
F_55 ( V_98 L_12
L_13 , V_91 -> V_99 , V_92 ) ;
V_84 = F_53 () ;
if ( ! V_84 )
return F_56 ( - V_64 ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_57 ( V_2 , V_93 [ type ] ) )
continue;
V_86 = F_33 ( V_91 , V_35 [ type ] , V_92 ) ;
if ( ! V_86 ) {
V_17 = - V_100 ;
goto V_101;
}
V_17 = F_58 ( V_86 , NULL , 1 ,
V_102 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_103;
}
V_13 = NULL ;
V_17 = F_23 ( V_86 , 0 , & V_13 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
F_30 ( V_44 , L_14
L_15 , V_92 , type ) ;
goto V_104;
}
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
V_17 = F_52 ( V_86 , V_59 , type ,
& V_84 -> V_85 [ type ] ) ;
F_32 ( V_13 ) ;
V_104:
F_59 ( V_86 , 1 ) ;
V_103:
F_34 ( V_86 ) ;
if ( V_17 < 0 )
break;
}
V_101:
if ( V_17 < 0 ) {
F_51 ( V_84 ) ;
V_84 = F_56 ( V_17 ) ;
}
return V_84 ;
}
static int F_60 ( struct V_11 * V_86 ,
int type ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = V_86 -> V_15 ;
struct V_68 * V_69 = F_61 ( V_2 , type ) -> V_70 ;
struct V_6 * V_75 ;
struct V_5 * V_105 ;
struct V_106 * V_106 ;
T_2 * V_16 ;
struct V_12 * V_87 = NULL , * V_107 = NULL ;
int V_17 = 0 ;
int V_108 , V_76 ;
struct V_77 * V_82 , * V_54 ;
T_4 V_109 , V_110 ;
F_62 ( ( unsigned long ) V_86 -> V_111 , type ) ;
F_36 (rchunk, next, &(rec->r_list[type]), rc_list) {
V_76 = V_82 -> V_78 ;
V_87 = NULL ;
V_17 = F_23 ( V_86 ,
F_4 ( V_2 , V_76 ) ,
& V_87 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
break;
}
V_75 = (struct V_6 * ) V_87 -> V_46 ;
F_63 (bit, rchunk->rc_bitmap, ol_chunk_entries(sb)) {
V_107 = NULL ;
V_17 = F_23 ( V_86 ,
F_5 ( V_2 , V_76 , V_108 ) ,
& V_107 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
break;
}
V_105 = (struct V_5 * ) ( V_107 -> V_46 +
F_6 ( V_2 , V_76 , V_108 ) ) ;
V_106 = F_64 ( V_2 ,
F_65 ( & V_112 , type ,
F_66 ( V_105 -> V_113 ) ) ) ;
if ( F_14 ( V_106 ) ) {
V_17 = F_15 ( V_106 ) ;
F_30 ( V_44 , L_16
L_17
L_18 ,
( unsigned ) F_66 ( V_105 -> V_113 ) ,
type ) ;
goto V_114;
}
V_17 = F_67 ( V_69 , 1 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_115;
}
V_16 = F_12 ( F_13 ( V_2 ) ,
V_116 ) ;
if ( F_14 ( V_16 ) ) {
V_17 = F_15 ( V_16 ) ;
F_16 ( V_17 ) ;
goto V_117;
}
F_68 ( & F_29 ( V_2 ) -> V_118 ) ;
F_44 ( & V_72 ) ;
V_109 = F_66 ( V_105 -> V_119 ) ;
V_110 = F_66 ( V_105 -> V_120 ) ;
V_106 -> V_121 . V_122 += V_109 ;
V_106 -> V_121 . V_123 += V_110 ;
F_46 ( & V_72 ) ;
V_17 = F_69 ( V_106 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_124;
}
V_17 = F_17 ( V_16 ,
F_18 ( V_86 ) ,
V_107 , V_19 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_124;
}
F_20 ( V_107 ) ;
F_70 ( ! F_71 ( V_108 , V_75 -> V_80 ) ) ;
F_72 ( V_108 , V_75 -> V_80 ) ;
F_73 ( & V_75 -> V_89 , 1 ) ;
F_21 ( V_107 ) ;
F_22 ( V_16 , V_107 ) ;
V_124:
F_74 ( & F_29 ( V_2 ) -> V_118 ) ;
F_19 ( F_13 ( V_2 ) , V_16 ) ;
V_117:
F_75 ( V_69 , 1 ) ;
V_115:
F_76 ( V_106 ) ;
V_114:
F_32 ( V_107 ) ;
if ( V_17 < 0 )
break;
}
F_32 ( V_87 ) ;
F_37 ( & V_82 -> V_81 ) ;
F_49 ( V_82 -> V_79 ) ;
F_49 ( V_82 ) ;
if ( V_17 < 0 )
break;
}
if ( V_17 < 0 )
F_50 ( & ( V_84 -> V_85 [ type ] ) ) ;
if ( V_17 )
F_16 ( V_17 ) ;
return V_17 ;
}
int F_77 ( struct V_90 * V_91 ,
struct V_83 * V_84 ,
int V_92 )
{
unsigned int V_35 [ V_27 ] = { V_96 ,
V_97 } ;
struct V_1 * V_2 = V_91 -> V_2 ;
struct V_58 * V_59 ;
struct V_12 * V_13 ;
T_2 * V_16 ;
int type ;
int V_17 = 0 ;
struct V_11 * V_86 ;
unsigned int V_125 ;
F_55 ( V_98 L_19
L_13 , V_91 -> V_99 , V_92 ) ;
F_68 ( & F_29 ( V_2 ) -> V_126 ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( F_78 ( & ( V_84 -> V_85 [ type ] ) ) )
continue;
F_79 ( V_92 ) ;
V_86 = F_33 ( V_91 , V_35 [ type ] , V_92 ) ;
if ( ! V_86 ) {
V_17 = - V_100 ;
goto V_101;
}
V_17 = F_58 ( V_86 , NULL , 1 ,
V_127 ) ;
if ( V_17 == - V_128 ) {
F_55 ( V_98 L_20
L_21
L_22 , V_91 -> V_99 , V_92 ) ;
V_17 = 0 ;
goto V_103;
} else if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_103;
}
V_13 = NULL ;
V_17 = F_23 ( V_86 , 0 , & V_13 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
F_30 ( V_44 , L_14
L_15 , V_92 , type ) ;
goto V_104;
}
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
V_125 = F_31 ( V_59 -> V_73 ) ;
if ( ! ( V_125 & V_129 ) )
V_17 = F_60 ( V_86 ,
type ,
V_84 ) ;
if ( V_92 == V_91 -> V_92 )
goto V_130;
V_16 = F_12 ( V_91 ,
V_131 ) ;
if ( F_14 ( V_16 ) ) {
V_17 = F_15 ( V_16 ) ;
F_16 ( V_17 ) ;
goto V_130;
}
V_17 = F_17 ( V_16 , F_18 ( V_86 ) ,
V_13 ,
V_19 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
F_20 ( V_13 ) ;
V_59 -> V_73 = F_45 ( V_125 | V_129 ) ;
F_21 ( V_13 ) ;
F_22 ( V_16 , V_13 ) ;
V_132:
F_19 ( V_91 , V_16 ) ;
V_130:
F_32 ( V_13 ) ;
V_104:
F_59 ( V_86 , 1 ) ;
V_103:
F_34 ( V_86 ) ;
if ( V_17 < 0 )
break;
}
V_101:
F_74 ( & F_29 ( V_2 ) -> V_126 ) ;
F_49 ( V_84 ) ;
return V_17 ;
}
static int F_80 ( struct V_1 * V_2 , int type )
{
struct V_58 * V_59 ;
struct V_66 * V_67 = F_61 ( V_2 , type ) ;
struct V_68 * V_69 ;
struct V_11 * V_86 = F_29 ( V_2 ) -> V_39 [ type ] ;
int V_17 ;
struct V_12 * V_13 = NULL ;
struct V_83 * V_84 ;
int V_133 = 0 ;
F_74 ( & F_29 ( V_2 ) -> V_118 ) ;
V_67 -> V_134 = 0x7fffffffffffffffLL ;
V_67 -> V_135 = 0x7fffffffffffffffLL ;
V_69 = F_48 ( sizeof( struct V_68 ) , V_63 ) ;
if ( ! V_69 ) {
F_30 ( V_44 , L_23
L_24 ) ;
goto V_45;
}
V_67 -> V_70 = V_69 ;
V_69 -> V_136 = type ;
F_40 ( & V_69 -> V_137 ) ;
V_69 -> V_138 = NULL ;
V_69 -> V_139 = NULL ;
V_69 -> V_140 = NULL ;
V_17 = F_81 ( V_2 , type ) ;
if ( V_17 < 0 )
goto V_45;
V_17 = F_82 ( V_86 , & V_69 -> V_139 , 1 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_45;
}
V_133 = 1 ;
V_17 = F_23 ( V_86 , 0 , & V_13 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
F_30 ( V_44 , L_14
L_7 , type ) ;
goto V_45;
}
V_59 = (struct V_58 * ) ( V_13 -> V_46 +
V_71 ) ;
V_69 -> V_73 = F_31 ( V_59 -> V_73 ) ;
V_69 -> V_62 = F_31 ( V_59 -> V_62 ) ;
V_69 -> V_74 = F_31 ( V_59 -> V_74 ) ;
V_69 -> V_140 = V_13 ;
if ( ! ( V_69 -> V_73 & V_129 ) ) {
V_84 = F_13 ( V_2 ) -> V_141 ;
if ( ! V_84 ) {
V_84 = F_53 () ;
if ( ! V_84 ) {
V_17 = - V_64 ;
F_16 ( V_17 ) ;
goto V_45;
}
F_13 ( V_2 ) -> V_141 = V_84 ;
}
V_17 = F_52 ( V_86 , V_59 , type ,
& V_84 -> V_85 [ type ] ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_45;
}
}
V_17 = F_39 ( V_86 ,
V_59 ,
& V_69 -> V_137 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_45;
}
V_69 -> V_73 &= ~ V_129 ;
V_17 = F_10 ( V_86 , V_13 , F_43 , V_67 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_45;
}
F_68 ( & F_29 ( V_2 ) -> V_118 ) ;
return 0 ;
V_45:
if ( V_69 ) {
F_34 ( V_69 -> V_142 ) ;
F_83 ( F_13 ( V_2 ) , & V_69 -> V_143 ) ;
F_84 ( & V_69 -> V_143 ) ;
F_32 ( V_69 -> V_139 ) ;
if ( V_133 )
F_59 ( V_86 , 1 ) ;
F_35 ( & V_69 -> V_137 ) ;
F_49 ( V_69 ) ;
}
F_32 ( V_13 ) ;
F_68 ( & F_29 ( V_2 ) -> V_118 ) ;
return - 1 ;
}
static int F_85 ( struct V_1 * V_2 , int type )
{
struct V_66 * V_67 = F_61 ( V_2 , type ) ;
struct V_12 * V_13 = ( (struct V_68 * ) V_67 -> V_70 )
-> V_140 ;
int V_17 ;
V_17 = F_10 ( F_29 ( V_2 ) -> V_39 [ type ] , V_13 , F_43 ,
V_67 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
return - 1 ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , int type )
{
struct V_66 * V_67 = F_61 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_52 * V_76 ;
struct V_6 * V_75 ;
int V_144 = 1 , V_145 ;
int V_17 ;
F_34 ( V_69 -> V_142 ) ;
F_83 ( F_13 ( V_2 ) , & V_69 -> V_143 ) ;
F_84 ( & V_69 -> V_143 ) ;
F_87 (chunk, &oinfo->dqi_chunk, qc_chunk) {
V_75 = (struct V_6 * )
( V_76 -> V_56 -> V_46 ) ;
if ( V_76 -> V_65 < V_69 -> V_62 - 1 ) {
V_145 = F_3 ( V_2 ) ;
} else {
V_145 = ( V_69 -> V_74 -
F_4 ( V_2 , V_76 -> V_65 ) - 1 )
* F_1 ( V_2 ) ;
}
if ( F_31 ( V_75 -> V_89 ) != V_145 ) {
F_30 ( V_44 , L_25
L_26 , type ) ;
V_144 = 0 ;
}
}
F_35 ( & V_69 -> V_137 ) ;
if ( V_69 -> V_138 ) {
F_51 ( V_69 -> V_138 ) ;
V_144 = 0 ;
}
if ( ! V_144 )
goto V_101;
V_69 -> V_73 |= V_129 ;
V_17 = F_10 ( F_29 ( V_2 ) -> V_39 [ type ] ,
V_69 -> V_140 ,
F_43 ,
V_67 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_101:
F_59 ( F_29 ( V_2 ) -> V_39 [ type ] , 1 ) ;
F_32 ( V_69 -> V_140 ) ;
F_32 ( V_69 -> V_139 ) ;
F_49 ( V_69 ) ;
return 0 ;
}
static void F_88 ( struct V_12 * V_13 , void * V_14 )
{
struct V_146 * V_147 = V_14 ;
struct V_5 * V_105 ;
struct V_1 * V_2 = V_147 -> V_148 . V_149 ;
V_105 = (struct V_5 * ) ( V_13 -> V_46
+ F_8 ( V_2 , V_147 -> V_150 ) ) ;
V_105 -> V_113 = F_89 ( F_90 ( & V_112 ,
V_147 -> V_148 . V_151 ) ) ;
F_44 ( & V_72 ) ;
V_105 -> V_119 = F_89 ( V_147 -> V_148 . V_121 . V_122 -
V_147 -> V_152 ) ;
V_105 -> V_120 = F_89 ( V_147 -> V_148 . V_121 . V_123 -
V_147 -> V_153 ) ;
F_46 ( & V_72 ) ;
F_91 (
( unsigned long long ) F_66 ( V_105 -> V_119 ) ,
( unsigned long long ) F_66 ( V_105 -> V_120 ) ,
F_90 ( & V_112 , V_147 -> V_148 . V_151 ) ) ;
}
int F_92 ( struct V_106 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_149 ;
struct V_146 * V_147 = F_93 ( V_106 ) ;
struct V_12 * V_13 ;
struct V_11 * V_86 = F_29 ( V_2 ) -> V_39 [ V_106 -> V_151 . type ] ;
int V_17 ;
V_17 = F_94 ( V_86 , V_147 -> V_154 ,
& V_13 ) ;
if ( V_17 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_10 ( V_86 , V_13 , F_88 , V_147 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_101:
F_32 ( V_13 ) ;
return V_17 ;
}
static struct V_52 * F_95 ( struct V_1 * V_2 ,
int type ,
int * V_155 )
{
struct V_66 * V_67 = F_61 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_52 * V_76 ;
struct V_6 * V_75 ;
int V_156 = 0 , V_145 ;
F_87 (chunk, &oinfo->dqi_chunk, qc_chunk) {
V_75 = (struct V_6 * )
V_76 -> V_56 -> V_46 ;
if ( F_31 ( V_75 -> V_89 ) > 0 ) {
V_156 = 1 ;
break;
}
}
if ( ! V_156 )
return NULL ;
if ( V_76 -> V_65 < V_69 -> V_62 - 1 ) {
V_145 = F_3 ( V_2 ) ;
} else {
V_145 = ( V_69 -> V_74 -
F_4 ( V_2 , V_76 -> V_65 ) - 1 )
* F_1 ( V_2 ) ;
}
V_156 = F_96 ( V_75 -> V_80 , V_145 , 0 ) ;
if ( V_156 == V_145 ) {
F_30 ( V_44 , L_27
L_28 , V_76 -> V_65 ,
F_31 ( V_75 -> V_89 ) , type ) ;
return F_56 ( - V_24 ) ;
}
* V_155 = V_156 ;
return V_76 ;
}
static struct V_52 * F_97 (
struct V_1 * V_2 ,
int type ,
int * V_155 )
{
struct V_66 * V_67 = F_61 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_11 * V_86 = F_29 ( V_2 ) -> V_39 [ type ] ;
struct V_52 * V_76 = NULL ;
struct V_6 * V_75 ;
int V_17 ;
T_2 * V_16 ;
struct V_12 * V_13 = NULL , * V_157 = NULL ;
T_3 V_158 ;
V_17 = F_98 ( V_86 , NULL ,
F_24 ( V_86 ) + 2 * V_2 -> V_3 ,
F_24 ( V_86 ) ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_99 ( V_86 , V_69 -> V_139 ,
F_24 ( V_86 ) + 2 * V_2 -> V_3 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_76 = F_41 ( V_57 , V_63 ) ;
if ( ! V_76 ) {
V_17 = - V_64 ;
F_16 ( V_17 ) ;
goto V_101;
}
V_16 = F_12 ( F_13 ( V_2 ) ,
V_131 +
2 * V_18 ) ;
if ( F_14 ( V_16 ) ) {
V_17 = F_15 ( V_16 ) ;
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_100 ( V_86 , V_69 -> V_74 ,
& V_158 , NULL , NULL ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
V_13 = F_101 ( V_2 , V_158 ) ;
if ( ! V_13 ) {
V_17 = - V_64 ;
F_16 ( V_17 ) ;
goto V_132;
}
V_75 = (struct V_6 * ) V_13 -> V_46 ;
F_102 ( F_18 ( V_86 ) , V_13 ) ;
V_17 = F_17 ( V_16 , F_18 ( V_86 ) , V_13 ,
V_159 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
F_20 ( V_13 ) ;
V_75 -> V_89 = F_45 ( F_1 ( V_2 ) ) ;
memset ( V_75 -> V_80 , 0 ,
V_2 -> V_3 - sizeof( struct V_6 ) -
V_4 ) ;
F_21 ( V_13 ) ;
F_22 ( V_16 , V_13 ) ;
V_17 = F_100 ( V_86 , V_69 -> V_74 + 1 ,
& V_158 , NULL , NULL ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
V_157 = F_101 ( V_2 , V_158 ) ;
if ( ! V_157 ) {
V_17 = - V_64 ;
F_16 ( V_17 ) ;
goto V_132;
}
F_102 ( F_18 ( V_86 ) , V_157 ) ;
V_17 = F_17 ( V_16 , F_18 ( V_86 ) , V_157 ,
V_159 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
F_20 ( V_157 ) ;
memset ( V_157 -> V_46 , 0 , V_2 -> V_3 - V_4 ) ;
F_21 ( V_157 ) ;
F_22 ( V_16 , V_157 ) ;
V_69 -> V_74 += 2 ;
V_69 -> V_62 ++ ;
V_17 = F_85 ( V_2 , type ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
V_17 = F_19 ( F_13 ( V_2 ) , V_16 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
F_42 ( & V_76 -> V_55 , & V_69 -> V_137 ) ;
V_76 -> V_65 = F_103 ( V_76 -> V_55 . V_160 ,
struct V_52 ,
V_55 ) -> V_65 + 1 ;
V_76 -> V_56 = V_13 ;
* V_155 = 0 ;
return V_76 ;
V_132:
F_19 ( F_13 ( V_2 ) , V_16 ) ;
V_101:
F_32 ( V_13 ) ;
F_32 ( V_157 ) ;
F_38 ( V_57 , V_76 ) ;
return F_56 ( V_17 ) ;
}
static struct V_52 * F_104 (
struct V_1 * V_2 ,
int type ,
int * V_155 )
{
struct V_66 * V_67 = F_61 ( V_2 , type ) ;
struct V_68 * V_69 = V_67 -> V_70 ;
struct V_52 * V_76 ;
struct V_11 * V_86 = F_29 ( V_2 ) -> V_39 [ type ] ;
struct V_6 * V_75 ;
int V_9 = F_1 ( V_2 ) ;
unsigned int V_161 ;
struct V_12 * V_13 ;
T_3 V_158 ;
int V_17 ;
T_2 * V_16 ;
if ( F_78 ( & V_69 -> V_137 ) )
return F_97 ( V_2 , type , V_155 ) ;
V_76 = F_103 ( V_69 -> V_137 . V_160 ,
struct V_52 , V_55 ) ;
V_161 = V_69 -> V_74 -
F_4 ( V_2 , V_76 -> V_65 ) - 1 ;
if ( F_2 ( V_2 ) == V_161 )
return F_97 ( V_2 , type , V_155 ) ;
V_17 = F_98 ( V_86 , NULL ,
F_24 ( V_86 ) + V_2 -> V_3 ,
F_24 ( V_86 ) ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_99 ( V_86 , V_69 -> V_139 ,
F_24 ( V_86 ) + V_2 -> V_3 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_100 ( V_86 , V_69 -> V_74 ,
& V_158 , NULL , NULL ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_13 = F_101 ( V_2 , V_158 ) ;
if ( ! V_13 ) {
V_17 = - V_64 ;
F_16 ( V_17 ) ;
goto V_101;
}
F_102 ( F_18 ( V_86 ) , V_13 ) ;
V_16 = F_12 ( F_13 ( V_2 ) ,
V_131 +
2 * V_18 ) ;
if ( F_14 ( V_16 ) ) {
V_17 = F_15 ( V_16 ) ;
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_17 ( V_16 , F_18 ( V_86 ) , V_13 ,
V_159 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
F_20 ( V_13 ) ;
memset ( V_13 -> V_46 , 0 , V_2 -> V_3 ) ;
F_21 ( V_13 ) ;
F_22 ( V_16 , V_13 ) ;
V_17 = F_17 ( V_16 , F_18 ( V_86 ) ,
V_76 -> V_56 ,
V_19 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
V_75 = (struct V_6 * ) V_76 -> V_56 -> V_46 ;
F_20 ( V_76 -> V_56 ) ;
F_73 ( & V_75 -> V_89 , F_1 ( V_2 ) ) ;
F_21 ( V_76 -> V_56 ) ;
F_22 ( V_16 , V_76 -> V_56 ) ;
V_69 -> V_74 ++ ;
V_17 = F_85 ( V_2 , type ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_132;
}
V_17 = F_19 ( F_13 ( V_2 ) , V_16 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
* V_155 = V_161 * V_9 ;
return V_76 ;
V_132:
F_19 ( F_13 ( V_2 ) , V_16 ) ;
V_101:
return F_56 ( V_17 ) ;
}
static void F_105 ( struct V_12 * V_13 , void * V_14 )
{
int * V_155 = V_14 ;
struct V_6 * V_75 ;
V_75 = (struct V_6 * ) V_13 -> V_46 ;
F_106 ( * V_155 , V_75 -> V_80 ) ;
F_73 ( & V_75 -> V_89 , - 1 ) ;
}
int F_107 ( struct V_106 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_149 ;
int type = V_106 -> V_151 . type ;
struct V_11 * V_86 = F_29 ( V_2 ) -> V_39 [ type ] ;
struct V_52 * V_76 ;
struct V_146 * V_147 = F_93 ( V_106 ) ;
int V_155 ;
int V_17 ;
T_3 V_162 ;
F_108 ( & F_26 ( V_86 ) -> V_163 ) ;
V_76 = F_95 ( V_2 , type , & V_155 ) ;
if ( ! V_76 ) {
V_76 = F_104 ( V_2 , type , & V_155 ) ;
if ( F_14 ( V_76 ) ) {
V_17 = F_15 ( V_76 ) ;
goto V_101;
}
} else if ( F_14 ( V_76 ) ) {
V_17 = F_15 ( V_76 ) ;
goto V_101;
}
V_147 -> V_150 = F_7 ( V_2 , V_76 -> V_65 , V_155 ) ;
V_147 -> V_164 = V_76 ;
V_17 = F_100 ( V_86 ,
F_5 ( V_2 , V_76 -> V_65 , V_155 ) ,
& V_147 -> V_154 ,
& V_162 ,
NULL ) ;
V_17 = F_92 ( V_106 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_17 = F_10 ( V_86 , V_76 -> V_56 , F_105 ,
& V_155 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_101:
F_109 ( & F_26 ( V_86 ) -> V_163 ) ;
return V_17 ;
}
int F_110 ( T_2 * V_16 , struct V_106 * V_106 )
{
int V_17 ;
int type = V_106 -> V_151 . type ;
struct V_146 * V_147 = F_93 ( V_106 ) ;
struct V_1 * V_2 = V_106 -> V_149 ;
struct V_6 * V_75 ;
int V_155 ;
V_17 = F_17 ( V_16 ,
F_18 ( F_29 ( V_2 ) -> V_39 [ type ] ) ,
V_147 -> V_164 -> V_56 , V_19 ) ;
if ( V_17 < 0 ) {
F_16 ( V_17 ) ;
goto V_101;
}
V_155 = F_9 ( V_2 , V_147 -> V_164 -> V_65 ,
V_147 -> V_150 ) ;
V_75 = (struct V_6 * )
( V_147 -> V_164 -> V_56 -> V_46 ) ;
F_20 ( V_147 -> V_164 -> V_56 ) ;
F_72 ( V_155 , V_75 -> V_80 ) ;
F_73 ( & V_75 -> V_89 , 1 ) ;
F_21 ( V_147 -> V_164 -> V_56 ) ;
F_22 ( V_16 , V_147 -> V_164 -> V_56 ) ;
V_101:
return V_17 ;
}
