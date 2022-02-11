static inline const char * F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
switch ( V_2 -> V_3 . type ) {
case V_5 :
return L_1 ;
case V_6 :
return L_2 ;
case V_7 :
return L_3 ;
case V_8 :
return L_4 ;
default:
return L_5 ;
}
} else {
switch ( V_2 -> V_3 . type ) {
case V_5 :
return L_6 ;
case V_6 :
return L_7 ;
case V_9 :
return L_8 ;
case V_7 :
return L_9 ;
case V_8 :
return L_10 ;
default:
return L_5 ;
}
}
return L_11 ;
}
const char * F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
switch ( V_2 -> V_3 . type ) {
case V_5 :
return L_12 ;
case V_6 :
return L_13 ;
case V_7 :
return L_14 ;
case V_8 :
return L_15 ;
default:
return L_16 ;
}
} else {
switch ( V_2 -> V_3 . type ) {
case V_5 :
switch ( V_2 -> V_3 . V_10 ) {
case V_11 :
return L_17 ;
case V_12 :
return L_18 ;
case V_13 :
return L_19 ;
case V_14 :
return L_20 ;
case V_15 :
return L_21 ;
case V_16 :
return L_22 ;
case V_17 :
return L_23 ;
case V_18 :
return L_24 ;
default:
return L_25 ;
}
case V_6 :
return L_26 ;
case V_9 :
return L_27 ;
case V_7 :
return L_28 ;
case V_8 :
return L_29 ;
default:
return L_16 ;
}
}
return L_30 ;
}
void F_3 ( struct V_1 * V_2 , unsigned long V_19 ,
int V_20 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_23 = V_19 ;
if ( V_20 )
V_2 -> V_24 &= V_19 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
int F_7 ( struct V_1 * V_2 , unsigned long V_19 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_26 = ( V_2 -> V_27 & V_19 ) ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
int F_8 ( struct V_1 * V_2 , unsigned long V_19 )
{
return F_9 ( V_2 -> V_25 ,
F_7 ( V_2 , V_19 ) == 0 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_30 ;
F_11 ( V_2 , 5 , L_31 ) ;
F_12 (pool_entry, tmp,
&card->qdio.in_buf_pool.entry_list, list) {
F_13 ( & V_29 -> V_31 ) ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
void * V_32 ;
int V_33 , V_34 ;
F_11 ( V_2 , 5 , L_32 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_36 . V_37 ; ++ V_33 ) {
V_29 = F_15 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 ) {
F_16 ( V_2 ) ;
return - V_39 ;
}
for ( V_34 = 0 ; V_34 < F_17 ( V_2 ) ; ++ V_34 ) {
V_32 = ( void * ) F_18 ( V_38 ) ;
if ( ! V_32 ) {
while ( V_34 > 0 )
F_19 ( ( unsigned long )
V_29 -> V_40 [ -- V_34 ] ) ;
F_20 ( V_29 ) ;
F_16 ( V_2 ) ;
return - V_39 ;
}
V_29 -> V_40 [ V_34 ] = V_32 ;
}
F_21 ( & V_29 -> V_41 ,
& V_2 -> V_35 . V_36 . V_42 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , int V_43 )
{
F_11 ( V_2 , 2 , L_33 ) ;
if ( ( V_2 -> V_44 != V_45 ) &&
( V_2 -> V_44 != V_46 ) )
return - V_47 ;
F_10 ( V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_35 . V_48 . V_37 = V_43 ;
V_2 -> V_35 . V_36 . V_37 = V_43 ;
return F_14 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
F_11 ( V_2 , 5 , L_34 ) ;
if ( V_2 -> V_51 . V_44 != V_52 )
return - V_53 ;
V_50 = F_24 ( & V_2 -> V_51 ) ;
if ( ! V_50 ) {
F_25 ( & V_2 -> V_54 -> V_55 , L_35
L_36 ) ;
F_26 ( 2 , L_37
L_38 , F_27 ( & V_2 -> V_54 -> V_55 ) ) ;
return - V_39 ;
}
F_28 ( & V_2 -> V_51 , V_50 -> V_56 , V_57 ) ;
F_11 ( V_2 , 6 , L_39 ) ;
V_26 = F_29 ( V_2 -> V_51 . V_58 , & V_2 -> V_51 . V_59 ,
( V_60 ) V_50 , 0 , 0 ) ;
if ( V_26 ) {
F_26 ( 2 , L_40
L_41 , F_27 ( & V_2 -> V_54 -> V_55 ) , V_26 ) ;
F_30 ( & V_2 -> V_51 . V_61 , 0 ) ;
V_2 -> V_62 = 1 ;
F_31 ( V_2 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
return V_26 ;
}
static struct V_63 * F_32 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_33 ( sizeof( struct V_63 ) , V_65 ) ;
if ( V_64 ) {
F_30 ( & V_64 -> V_66 , 1 ) ;
F_30 ( & V_64 -> V_67 , 0 ) ;
V_64 -> V_2 = V_2 ;
} ;
return V_64 ;
}
static void F_34 ( struct V_63 * V_64 )
{
F_35 ( F_36 ( & V_64 -> V_66 ) <= 0 ) ;
F_37 ( & V_64 -> V_66 ) ;
}
static void F_38 ( struct V_63 * V_64 )
{
F_35 ( F_36 ( & V_64 -> V_66 ) <= 0 ) ;
if ( F_39 ( & V_64 -> V_66 ) )
F_20 ( V_64 ) ;
}
static void F_40 ( struct V_68 * V_69 , int V_26 ,
struct V_1 * V_2 )
{
char * V_70 ;
int V_71 = V_69 -> V_72 . V_73 ;
V_70 = F_41 ( V_71 ) ;
if ( V_26 )
F_26 ( 2 , L_42
L_43 ,
V_70 , V_71 , F_27 ( & V_2 -> V_54 -> V_55 ) ,
F_42 ( V_2 ) , V_26 ,
F_43 ( V_26 ) ) ;
else
F_26 ( 5 , L_44 ,
V_70 , V_71 , F_27 ( & V_2 -> V_54 -> V_55 ) ,
F_42 ( V_2 ) ) ;
}
static struct V_68 * F_44 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_68 * V_69 = NULL ;
F_11 ( V_2 , 5 , L_45 ) ;
if ( F_45 ( V_50 -> V_56 ) ) {
V_69 = (struct V_68 * ) F_46 ( V_50 -> V_56 ) ;
if ( F_47 ( V_69 ) ) {
if ( V_69 -> V_72 . V_73 != V_74 &&
V_69 -> V_72 . V_73 != V_75 &&
V_69 -> V_72 . V_73 != V_76 &&
V_69 -> V_72 . V_73 != V_77 )
F_40 ( V_69 ,
V_69 -> V_72 . V_78 , V_2 ) ;
return V_69 ;
} else {
switch ( V_69 -> V_72 . V_73 ) {
case V_79 :
F_25 ( & V_2 -> V_54 -> V_55 ,
L_46
L_47 ,
F_42 ( V_2 ) ,
V_2 -> V_3 . V_80 ) ;
V_2 -> V_81 = 0 ;
if ( V_2 -> V_55 && F_48 ( V_2 -> V_55 ) )
F_49 ( V_2 -> V_55 ) ;
return NULL ;
case V_82 :
F_50 ( & V_2 -> V_54 -> V_55 ,
L_48
L_49 ,
F_42 ( V_2 ) ,
V_2 -> V_3 . V_80 ) ;
F_51 ( V_2 -> V_55 ) ;
V_2 -> V_81 = 1 ;
if ( V_2 -> V_3 . V_83 )
V_2 -> V_3 . V_83 = 2 ;
F_31 ( V_2 ) ;
return NULL ;
case V_76 :
return V_69 ;
case V_84 :
F_11 ( V_2 , 3 , L_50 ) ;
break;
case V_85 :
F_11 ( V_2 , 3 , L_51 ) ;
break;
default:
F_26 ( 2 , L_52
L_53 ) ;
break;
}
}
}
return V_69 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_63 * V_64 , * V_86 ;
unsigned long V_21 ;
F_11 ( V_2 , 4 , L_54 ) ;
F_4 ( & V_2 -> V_87 , V_21 ) ;
F_12 (reply, r, &card->cmd_waiter_list, list) {
F_34 ( V_64 ) ;
V_64 -> V_26 = - V_53 ;
F_37 ( & V_64 -> V_67 ) ;
F_53 ( & V_64 -> V_31 ) ;
F_6 ( & V_64 -> V_25 ) ;
F_38 ( V_64 ) ;
}
F_5 ( & V_2 -> V_87 , V_21 ) ;
F_30 ( & V_2 -> V_88 . V_61 , 0 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
unsigned char * V_89 )
{
if ( ! V_89 )
return 0 ;
F_55 ( V_90 , 2 , V_89 , V_91 ) ;
if ( ( V_89 [ 2 ] & 0xc0 ) == 0xc0 ) {
F_26 ( 2 , L_55
L_56 ,
V_89 [ 4 ] ,
( ( V_89 [ 4 ] == 0x22 ) ?
L_57 : L_58 ) ) ;
F_11 ( V_2 , 2 , L_59 ) ;
F_11 ( V_2 , 2 , L_60 ) ;
F_56 ( V_2 , 2 , L_61 , - V_53 ) ;
if ( V_89 [ 4 ] == 0xf6 ) {
F_57 ( & V_2 -> V_54 -> V_55 ,
L_62
L_63 ) ;
return - V_47 ;
}
return - V_53 ;
}
return 0 ;
}
static void F_28 ( struct V_92 * V_93 , unsigned char * V_50 ,
T_1 V_94 )
{
struct V_1 * V_2 ;
V_2 = F_58 ( V_93 -> V_58 ) ;
F_11 ( V_2 , 4 , L_64 ) ;
if ( V_93 == & V_2 -> V_51 )
memcpy ( & V_93 -> V_59 , V_95 , sizeof( struct V_96 ) ) ;
else
memcpy ( & V_93 -> V_59 , V_97 , sizeof( struct V_96 ) ) ;
V_93 -> V_59 . V_98 = V_94 ;
V_93 -> V_59 . V_99 = ( T_1 ) F_59 ( V_50 ) ;
}
static struct V_49 * F_60 ( struct V_92 * V_93 )
{
T_2 V_100 ;
F_11 ( F_58 ( V_93 -> V_58 ) , 6 , L_65 ) ;
V_100 = V_93 -> V_101 ;
do {
if ( V_93 -> V_50 [ V_100 ] . V_44 == V_102 ) {
V_93 -> V_50 [ V_100 ] . V_44 = V_103 ;
V_93 -> V_101 = ( V_93 -> V_101 + 1 ) %
V_104 ;
memset ( V_93 -> V_50 [ V_100 ] . V_56 , 0 , V_57 ) ;
return V_93 -> V_50 + V_100 ;
}
V_100 = ( V_100 + 1 ) % V_104 ;
} while ( V_100 != V_93 -> V_101 );
return NULL ;
}
void F_61 ( struct V_92 * V_93 ,
struct V_49 * V_50 )
{
unsigned long V_21 ;
F_11 ( F_58 ( V_93 -> V_58 ) , 6 , L_66 ) ;
F_4 ( & V_93 -> V_105 , V_21 ) ;
memset ( V_50 -> V_56 , 0 , V_57 ) ;
V_50 -> V_44 = V_102 ;
V_50 -> V_106 = V_107 ;
V_50 -> V_26 = 0 ;
F_5 ( & V_93 -> V_105 , V_21 ) ;
}
static struct V_49 * F_24 ( struct V_92 * V_93 )
{
struct V_49 * V_89 = NULL ;
unsigned long V_21 ;
F_4 ( & V_93 -> V_105 , V_21 ) ;
V_89 = F_60 ( V_93 ) ;
F_5 ( & V_93 -> V_105 , V_21 ) ;
return V_89 ;
}
struct V_49 * F_62 ( struct V_92 * V_93 )
{
struct V_49 * V_89 ;
F_63 ( V_93 -> V_25 ,
( ( V_89 = F_24 ( V_93 ) ) != NULL ) ) ;
return V_89 ;
}
void F_64 ( struct V_92 * V_93 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_104 ; V_108 ++ )
F_61 ( V_93 , & V_93 -> V_50 [ V_108 ] ) ;
V_93 -> V_109 = 0 ;
V_93 -> V_101 = 0 ;
}
static void V_107 ( struct V_92 * V_93 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 , * V_86 ;
struct V_68 * V_69 ;
unsigned long V_21 ;
int V_110 ;
int V_26 = 0 ;
V_2 = F_58 ( V_93 -> V_58 ) ;
F_11 ( V_2 , 4 , L_67 ) ;
V_26 = F_54 ( V_2 , V_50 -> V_56 ) ;
switch ( V_26 ) {
case 0 :
break;
case - V_53 :
F_52 ( V_2 ) ;
F_31 ( V_2 ) ;
default:
goto V_111;
}
V_69 = F_44 ( V_2 , V_50 ) ;
if ( ( V_69 == NULL ) && ( V_2 -> V_44 != V_45 ) )
goto V_111;
if ( V_2 -> V_3 . type == V_9 &&
V_69 &&
V_69 -> V_72 . V_73 != V_82 &&
V_2 -> V_112 . V_113 != NULL ) {
V_2 -> V_112 . V_113 ( V_2 -> V_55 , V_69 ) ;
goto V_111;
}
F_4 ( & V_2 -> V_87 , V_21 ) ;
F_12 (reply, r, &card->cmd_waiter_list, list) {
if ( ( V_64 -> V_114 == V_115 ) ||
( ( V_69 ) && ( V_64 -> V_114 == V_69 -> V_72 . V_114 ) ) ) {
F_34 ( V_64 ) ;
F_53 ( & V_64 -> V_31 ) ;
F_5 ( & V_2 -> V_87 , V_21 ) ;
V_110 = 0 ;
if ( V_64 -> V_106 != NULL ) {
if ( V_69 ) {
V_64 -> V_116 = ( V_117 ) ( ( char * ) V_69 -
( char * ) V_50 -> V_56 ) ;
V_110 = V_64 -> V_106 ( V_2 ,
V_64 ,
( unsigned long ) V_69 ) ;
} else
V_110 = V_64 -> V_106 ( V_2 ,
V_64 ,
( unsigned long ) V_50 ) ;
}
if ( V_69 )
V_64 -> V_26 = ( V_118 ) V_69 -> V_72 . V_78 ;
else if ( V_50 -> V_26 )
V_64 -> V_26 = V_50 -> V_26 ;
if ( V_110 ) {
F_4 ( & V_2 -> V_87 , V_21 ) ;
F_65 ( & V_64 -> V_31 ,
& V_2 -> V_119 ) ;
F_5 ( & V_2 -> V_87 , V_21 ) ;
} else {
F_37 ( & V_64 -> V_67 ) ;
F_6 ( & V_64 -> V_25 ) ;
}
F_38 ( V_64 ) ;
goto V_111;
}
}
F_5 ( & V_2 -> V_87 , V_21 ) ;
V_111:
memcpy ( & V_2 -> V_114 . V_120 ,
F_66 ( V_50 -> V_56 ) ,
V_121 ) ;
F_61 ( V_93 , V_50 ) ;
}
static int F_67 ( struct V_92 * V_93 )
{
int V_108 ;
F_68 ( V_122 , 2 , L_68 ) ;
for ( V_108 = 0 ; V_108 < V_104 ; V_108 ++ ) {
V_93 -> V_50 [ V_108 ] . V_56 =
F_15 ( V_57 , V_123 | V_38 ) ;
if ( V_93 -> V_50 [ V_108 ] . V_56 == NULL )
break;
V_93 -> V_50 [ V_108 ] . V_44 = V_102 ;
V_93 -> V_50 [ V_108 ] . V_93 = V_93 ;
V_93 -> V_50 [ V_108 ] . V_106 = V_107 ;
V_93 -> V_50 [ V_108 ] . V_26 = 0 ;
}
if ( V_108 < V_104 ) {
while ( V_108 -- > 0 )
F_20 ( V_93 -> V_50 [ V_108 ] . V_56 ) ;
return - V_39 ;
}
V_93 -> V_109 = 0 ;
V_93 -> V_101 = 0 ;
F_30 ( & V_93 -> V_61 , 0 ) ;
F_69 ( & V_93 -> V_105 ) ;
F_70 ( & V_93 -> V_25 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned long V_124 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
if ( ! ( V_2 -> V_23 & V_124 ) ||
( V_2 -> V_24 & V_124 ) ) {
F_5 ( & V_2 -> V_22 , V_21 ) ;
return - V_47 ;
}
V_2 -> V_24 |= V_124 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 , unsigned long V_124 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_24 &= ~ V_124 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
void F_73 ( struct V_1 * V_2 , unsigned long V_124 )
{
unsigned long V_21 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
V_2 -> V_27 &= ~ V_124 ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
F_6 ( & V_2 -> V_25 ) ;
}
static int F_74 ( struct V_1 * V_2 , unsigned long V_124 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
if ( V_2 -> V_24 & V_124 ) {
if ( ( V_2 -> V_23 & V_124 ) &&
! ( V_2 -> V_27 & V_124 ) ) {
V_26 = 1 ;
V_2 -> V_24 &= ~ V_124 ;
V_2 -> V_27 |= V_124 ;
} else
V_26 = - V_47 ;
}
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
int F_75 ( struct V_1 * V_2 , unsigned long V_124 )
{
int V_26 = 0 ;
F_63 ( V_2 -> V_25 ,
( V_26 = F_74 ( V_2 , V_124 ) ) >= 0 ) ;
return V_26 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_11 ( V_2 , 2 , L_69 ) ;
if ( F_71 ( V_2 , V_125 ) == 0 )
F_76 ( & V_2 -> V_126 ) ;
}
static int F_77 ( struct V_127 * V_128 , struct V_129 * V_129 )
{
int V_130 , V_131 ;
char * V_132 ;
struct V_1 * V_2 ;
V_132 = ( char * ) V_129 -> V_133 ;
V_131 = V_129 -> V_134 . V_69 . V_131 ;
V_130 = V_129 -> V_134 . V_69 . V_130 ;
V_2 = F_58 ( V_128 ) ;
if ( V_131 & ( V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 ) ) {
F_11 ( V_2 , 2 , L_70 ) ;
F_25 ( & V_128 -> V_55 , L_35
L_36 ) ;
F_26 ( 2 , L_71 ,
F_27 ( & V_128 -> V_55 ) , V_130 , V_131 ) ;
F_78 ( V_141 , L_72 , V_142 ,
16 , 1 , V_129 , 64 , 1 ) ;
return 1 ;
}
if ( V_130 & V_143 ) {
if ( V_132 [ V_144 ] &
V_145 ) {
F_11 ( V_2 , 2 , L_73 ) ;
return 1 ;
}
if ( V_132 [ V_146 ] &
V_147 ) {
F_11 ( V_2 , 2 , L_74 ) ;
return 1 ;
}
if ( ( V_132 [ 2 ] == 0xaf ) && ( V_132 [ 3 ] == 0xfe ) ) {
F_11 ( V_2 , 2 , L_75 ) ;
return 1 ;
}
if ( ( ! V_132 [ 0 ] ) && ( ! V_132 [ 1 ] ) && ( ! V_132 [ 2 ] ) && ( ! V_132 [ 3 ] ) ) {
F_11 ( V_2 , 2 , L_76 ) ;
return 0 ;
}
F_11 ( V_2 , 2 , L_77 ) ;
return 1 ;
}
return 0 ;
}
static long F_79 ( struct V_127 * V_128 ,
unsigned long V_148 , struct V_129 * V_129 )
{
struct V_1 * V_2 ;
V_2 = F_58 ( V_128 ) ;
if ( ! F_80 ( V_129 ) )
return 0 ;
switch ( F_81 ( V_129 ) ) {
case - V_53 :
F_26 ( 2 , L_78 ,
F_27 ( & V_128 -> V_55 ) ) ;
F_11 ( V_2 , 2 , L_79 ) ;
F_56 ( V_2 , 2 , L_61 , - V_53 ) ;
break;
case - V_149 :
F_25 ( & V_128 -> V_55 , L_80
L_81 ) ;
F_11 ( V_2 , 2 , L_79 ) ;
F_56 ( V_2 , 2 , L_61 , - V_149 ) ;
if ( V_148 == V_150 ) {
if ( V_2 && ( V_2 -> V_56 . V_58 == V_128 ) ) {
V_2 -> V_56 . V_44 = V_151 ;
F_6 ( & V_2 -> V_25 ) ;
}
}
break;
default:
F_26 ( 2 , L_82 ,
F_27 ( & V_128 -> V_55 ) , F_81 ( V_129 ) ) ;
F_11 ( V_2 , 2 , L_79 ) ;
F_11 ( V_2 , 2 , L_83 ) ;
}
return F_81 ( V_129 ) ;
}
static void F_82 ( struct V_127 * V_128 , unsigned long V_148 ,
struct V_129 * V_129 )
{
int V_26 ;
int V_131 , V_130 ;
struct V_49 * V_89 ;
struct V_92 * V_93 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
T_2 V_100 ;
if ( F_79 ( V_128 , V_148 , V_129 ) )
return;
V_131 = V_129 -> V_134 . V_69 . V_131 ;
V_130 = V_129 -> V_134 . V_69 . V_130 ;
V_2 = F_58 ( V_128 ) ;
if ( ! V_2 )
return;
F_11 ( V_2 , 5 , L_84 ) ;
if ( V_2 -> V_51 . V_58 == V_128 ) {
V_93 = & V_2 -> V_51 ;
F_11 ( V_2 , 5 , L_85 ) ;
} else if ( V_2 -> V_88 . V_58 == V_128 ) {
V_93 = & V_2 -> V_88 ;
F_11 ( V_2 , 5 , L_86 ) ;
} else {
V_93 = & V_2 -> V_56 ;
F_11 ( V_2 , 5 , L_87 ) ;
}
F_30 ( & V_93 -> V_61 , 0 ) ;
if ( V_129 -> V_134 . V_69 . V_152 & ( V_153 ) )
V_93 -> V_44 = V_154 ;
if ( V_129 -> V_134 . V_69 . V_152 & ( V_155 ) )
V_93 -> V_44 = V_156 ;
if ( ( V_93 == & V_2 -> V_56 ) && ( V_148 != 0 ) &&
( V_148 != V_150 ) )
goto V_111;
if ( V_148 == V_157 ) {
F_11 ( V_2 , 6 , L_88 ) ;
V_148 = 0 ;
}
if ( V_148 == V_158 ) {
F_11 ( V_2 , 6 , L_89 ) ;
V_148 = 0 ;
}
if ( ( V_130 & V_159 ) ||
( V_130 & V_143 ) ||
( V_131 ) ) {
if ( V_129 -> V_160 . V_161 . V_162 . V_163 ) {
F_25 ( & V_93 -> V_58 -> V_55 ,
L_90
L_91 ) ;
F_26 ( 2 , L_92
L_93 ,
F_27 ( & V_93 -> V_58 -> V_55 ) , V_131 , V_130 ) ;
F_78 ( V_141 , L_72 ,
V_142 , 16 , 1 , V_129 , 32 , 1 ) ;
F_78 ( V_141 , L_94 ,
V_142 , 16 , 1 , V_129 -> V_133 , 32 , 1 ) ;
}
if ( V_148 == V_150 ) {
V_93 -> V_44 = V_151 ;
goto V_111;
}
V_26 = F_77 ( V_128 , V_129 ) ;
if ( V_26 ) {
F_52 ( V_2 ) ;
F_31 ( V_2 ) ;
goto V_111;
}
}
if ( V_148 == V_150 ) {
V_93 -> V_44 = V_164 ;
goto V_111;
}
if ( V_148 ) {
V_89 = (struct V_49 * ) F_83 ( ( V_60 ) V_148 ) ;
V_89 -> V_44 = V_165 ;
}
if ( V_93 == & V_2 -> V_56 )
return;
if ( V_93 == & V_2 -> V_51 &&
V_93 -> V_44 == V_52 )
F_23 ( V_2 ) ;
V_50 = V_93 -> V_50 ;
V_100 = V_93 -> V_109 ;
while ( V_50 [ V_100 ] . V_44 == V_165 ) {
if ( V_50 [ V_100 ] . V_106 != NULL )
V_50 [ V_100 ] . V_106 ( V_93 , V_50 + V_100 ) ;
V_100 = ( V_100 + 1 ) % V_104 ;
}
V_93 -> V_109 = V_100 ;
V_111:
F_6 ( & V_2 -> V_25 ) ;
return;
}
static void F_84 ( struct V_166 * V_167 ,
struct V_168 * V_169 )
{
int V_33 ;
struct V_170 * V_171 ;
if ( V_169 -> V_89 -> V_172 [ 0 ] . V_173 & V_174 )
F_85 ( & V_167 -> V_175 ) ;
V_171 = F_86 ( & V_169 -> V_176 ) ;
while ( V_171 ) {
F_85 ( & V_171 -> V_177 ) ;
F_87 ( V_171 ) ;
V_171 = F_86 ( & V_169 -> V_176 ) ;
}
for ( V_33 = 0 ; V_33 < F_17 ( V_167 -> V_2 ) ; ++ V_33 ) {
if ( V_169 -> V_89 -> V_172 [ V_33 ] . V_178 && V_169 -> V_179 [ V_33 ] )
F_88 ( V_180 ,
V_169 -> V_89 -> V_172 [ V_33 ] . V_178 ) ;
V_169 -> V_179 [ V_33 ] = 0 ;
V_169 -> V_89 -> V_172 [ V_33 ] . V_181 = 0 ;
V_169 -> V_89 -> V_172 [ V_33 ] . V_178 = NULL ;
V_169 -> V_89 -> V_172 [ V_33 ] . V_182 = 0 ;
V_169 -> V_89 -> V_172 [ V_33 ] . V_173 = 0 ;
}
V_169 -> V_89 -> V_172 [ 15 ] . V_182 = 0 ;
V_169 -> V_89 -> V_172 [ 15 ] . V_173 = 0 ;
V_169 -> V_183 = 0 ;
F_30 ( & V_169 -> V_44 , V_184 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
F_11 ( V_2 , 2 , L_95 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_185 ; ++ V_33 )
if ( V_2 -> V_35 . V_186 [ V_33 ] ) {
for ( V_34 = 0 ; V_34 < V_187 ; ++ V_34 )
F_84 ( V_2 -> V_35 . V_186 [ V_33 ] ,
& V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 , * V_30 ;
int V_33 = 0 ;
F_12 (pool_entry, tmp,
&card->qdio.init_pool.entry_list, init_list) {
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 )
F_19 ( ( unsigned long ) V_29 -> V_40 [ V_33 ] ) ;
F_13 ( & V_29 -> V_41 ) ;
F_20 ( V_29 ) ;
}
}
static void F_90 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
if ( F_91 ( & V_2 -> V_35 . V_44 , V_189 ) ==
V_189 )
return;
F_20 ( V_2 -> V_35 . V_190 ) ;
V_2 -> V_35 . V_190 = NULL ;
F_16 ( V_2 ) ;
if ( V_2 -> V_35 . V_186 ) {
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_185 ; ++ V_33 ) {
for ( V_34 = 0 ; V_34 < V_187 ; ++ V_34 )
F_84 ( V_2 -> V_35 . V_186 [ V_33 ] ,
& V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] ) ;
F_20 ( V_2 -> V_35 . V_186 [ V_33 ] ) ;
}
F_20 ( V_2 -> V_35 . V_186 ) ;
V_2 -> V_35 . V_186 = NULL ;
}
}
static void F_92 ( struct V_92 * V_93 )
{
int V_108 ;
F_68 ( V_122 , 2 , L_96 ) ;
for ( V_108 = 0 ; V_108 < V_104 ; V_108 ++ )
F_20 ( V_93 -> V_50 [ V_108 ] . V_56 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_127 * V_58 ;
struct V_191 {
T_3 V_21 ;
T_3 V_192 ;
T_3 V_193 ;
T_3 V_80 ;
T_3 V_194 ;
T_3 V_195 ;
T_3 V_196 ;
T_3 V_197 ;
} * V_198 ;
F_68 ( V_122 , 2 , L_97 ) ;
V_58 = V_2 -> V_56 . V_58 ;
V_198 = (struct V_191 * ) F_94 ( V_58 , 0 ) ;
if ( V_198 != NULL ) {
if ( ( V_198 -> V_197 & 0x02 ) == 0x02 ) {
if ( ( F_36 ( & V_2 -> V_35 . V_44 ) !=
V_189 ) &&
( V_2 -> V_35 . V_185 == 4 ) )
F_90 ( V_2 ) ;
V_2 -> V_35 . V_185 = 1 ;
if ( V_2 -> V_35 . V_199 != 0 )
F_50 ( & V_2 -> V_54 -> V_55 ,
L_98 ) ;
V_2 -> V_35 . V_199 = 0 ;
} else {
if ( ( F_36 ( & V_2 -> V_35 . V_44 ) !=
V_189 ) &&
( V_2 -> V_35 . V_185 == 1 ) ) {
F_90 ( V_2 ) ;
V_2 -> V_35 . V_199 = 2 ;
}
V_2 -> V_35 . V_185 = 4 ;
}
V_2 -> V_3 . V_200 = 0x4100 + V_198 -> V_193 ;
F_20 ( V_198 ) ;
}
F_95 ( V_122 , 2 , L_99 , V_2 -> V_35 . V_185 ) ;
F_95 ( V_122 , 2 , L_100 , V_2 -> V_3 . V_200 ) ;
return;
}
static void F_96 ( struct V_1 * V_2 )
{
F_68 ( V_122 , 4 , L_101 ) ;
F_30 ( & V_2 -> V_35 . V_44 , V_189 ) ;
V_2 -> V_35 . V_201 = V_202 ;
if ( V_2 -> V_3 . type == V_6 )
V_2 -> V_35 . V_36 . V_37 = V_203 ;
else
V_2 -> V_35 . V_36 . V_37 = V_204 ;
V_2 -> V_35 . V_48 . V_37 = V_2 -> V_35 . V_36 . V_37 ;
F_97 ( & V_2 -> V_35 . V_48 . V_42 ) ;
F_97 ( & V_2 -> V_35 . V_36 . V_42 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
V_2 -> V_205 . V_206 . type = V_207 ;
V_2 -> V_205 . V_208 . type = V_207 ;
V_2 -> V_205 . V_209 = V_210 ;
V_2 -> V_205 . V_211 = V_212 ;
V_2 -> V_205 . V_213 = 0 ;
V_2 -> V_205 . V_214 = V_215 ;
V_2 -> V_205 . V_216 = 0 ;
V_2 -> V_205 . V_217 = V_218 ;
V_2 -> V_205 . V_219 = V_220 ;
}
static int F_99 ( struct V_1 * V_2 , unsigned long V_124 )
{
unsigned long V_21 ;
int V_26 = 0 ;
F_4 ( & V_2 -> V_22 , V_21 ) ;
F_56 ( V_2 , 4 , L_102 ,
( T_3 ) V_2 -> V_24 ,
( T_3 ) V_2 -> V_23 ,
( T_3 ) V_2 -> V_27 ) ;
V_26 = ( V_2 -> V_24 & V_124 ) ;
F_5 ( & V_2 -> V_22 , V_21 ) ;
return V_26 ;
}
static void F_100 ( struct V_221 * V_222 )
{
struct V_1 * V_2 = F_101 ( V_222 , struct V_1 ,
V_126 ) ;
F_11 ( V_2 , 2 , L_103 ) ;
if ( V_2 -> V_51 . V_44 != V_52 &&
V_2 -> V_88 . V_44 != V_52 )
return;
if ( F_99 ( V_2 , V_125 ) )
F_102 ( V_2 -> V_223 . V_224 , ( void * ) V_2 ,
L_104 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
F_68 ( V_122 , 2 , L_105 ) ;
F_55 ( V_122 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_51 . V_44 = V_151 ;
V_2 -> V_88 . V_44 = V_151 ;
V_2 -> V_56 . V_44 = V_151 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_81 = 0 ;
V_2 -> V_62 = 0 ;
V_2 -> V_55 = NULL ;
F_69 ( & V_2 -> V_225 ) ;
F_69 ( & V_2 -> V_226 ) ;
F_69 ( & V_2 -> V_87 ) ;
F_69 ( & V_2 -> V_227 ) ;
F_69 ( & V_2 -> V_22 ) ;
F_104 ( & V_2 -> V_228 ) ;
F_104 ( & V_2 -> V_229 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_27 = 0 ;
F_105 ( & V_2 -> V_126 , F_100 ) ;
F_97 ( & V_2 -> V_230 ) ;
F_97 ( V_2 -> V_231 ) ;
F_97 ( & V_2 -> V_119 ) ;
F_70 ( & V_2 -> V_25 ) ;
F_98 ( V_2 ) ;
F_97 ( & V_2 -> V_232 . V_233 ) ;
V_2 -> V_232 . V_234 = 0 ;
V_2 -> V_232 . V_235 = 0 ;
V_2 -> V_232 . V_236 = 0 ;
F_96 ( V_2 ) ;
return 0 ;
}
static void F_106 ( struct V_237 * V_238 , struct V_239 * V_240 )
{
struct V_1 * V_2 = F_101 ( V_240 , struct V_1 ,
V_241 ) ;
if ( V_2 -> V_3 . V_242 [ 0 ] )
F_107 ( V_238 , L_106 ,
F_108 ( V_2 ) , V_2 -> V_3 . V_242 ) ;
}
static struct V_1 * F_109 ( void )
{
struct V_1 * V_2 ;
F_68 ( V_122 , 2 , L_107 ) ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_123 | V_38 ) ;
if ( ! V_2 )
goto V_111;
F_55 ( V_122 , 2 , & V_2 , sizeof( void * ) ) ;
V_2 -> V_231 = F_15 ( sizeof( struct V_243 ) , V_38 ) ;
if ( ! V_2 -> V_231 ) {
F_68 ( V_122 , 0 , L_108 ) ;
goto V_244;
}
if ( F_67 ( & V_2 -> V_51 ) )
goto V_245;
if ( F_67 ( & V_2 -> V_88 ) )
goto V_246;
V_2 -> V_205 . V_247 = - 1 ;
V_2 -> V_241 . V_248 = F_106 ;
F_110 ( & V_2 -> V_241 ) ;
return V_2 ;
V_246:
F_92 ( & V_2 -> V_51 ) ;
V_245:
F_20 ( V_2 -> V_231 ) ;
V_244:
F_20 ( V_2 ) ;
V_111:
return NULL ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_33 = 0 ;
F_68 ( V_122 , 2 , L_109 ) ;
V_2 -> V_35 . V_249 = V_250 ;
V_2 -> V_35 . V_199 = V_251 ;
while ( V_252 [ V_33 ] [ V_253 ] ) {
if ( ( F_112 ( V_2 ) -> V_254 . V_255 ==
V_252 [ V_33 ] [ V_256 ] ) &&
( F_112 ( V_2 ) -> V_254 . V_257 ==
V_252 [ V_33 ] [ V_253 ] ) ) {
V_2 -> V_3 . type = V_252 [ V_33 ] [ V_253 ] ;
V_2 -> V_35 . V_185 =
V_252 [ V_33 ] [ V_258 ] ;
V_2 -> V_3 . V_259 =
V_252 [ V_33 ] [ V_260 ] ;
F_93 ( V_2 ) ;
return 0 ;
}
V_33 ++ ;
}
V_2 -> V_3 . type = V_261 ;
F_57 ( & V_2 -> V_54 -> V_55 , L_110
L_111 ) ;
return - V_262 ;
}
static int F_113 ( struct V_92 * V_93 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_58 ( V_93 -> V_58 ) ;
F_11 ( V_2 , 3 , L_112 ) ;
F_4 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
V_26 = F_115 ( V_93 -> V_58 , V_157 ) ;
F_5 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_116 ( V_2 -> V_25 ,
V_93 -> V_44 == V_154 , V_263 ) ;
if ( V_26 == - V_264 )
return V_26 ;
if ( V_93 -> V_44 != V_154 )
return - V_265 ;
V_93 -> V_44 = V_151 ;
return 0 ;
}
static int F_117 ( struct V_92 * V_93 )
{
unsigned long V_21 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_58 ( V_93 -> V_58 ) ;
F_11 ( V_2 , 3 , L_113 ) ;
F_4 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
V_26 = F_118 ( V_93 -> V_58 , V_158 ) ;
F_5 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_116 ( V_2 -> V_25 ,
V_93 -> V_44 == V_156 , V_263 ) ;
if ( V_26 == - V_264 )
return V_26 ;
if ( V_93 -> V_44 != V_156 )
return - V_265 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_266 = 0 , V_267 = 0 , V_268 = 0 ;
F_11 ( V_2 , 3 , L_114 ) ;
V_266 = F_117 ( & V_2 -> V_51 ) ;
V_267 = F_117 ( & V_2 -> V_88 ) ;
V_268 = F_117 ( & V_2 -> V_56 ) ;
if ( V_266 )
return V_266 ;
if ( V_267 )
return V_267 ;
return V_268 ;
}
static int F_120 ( struct V_1 * V_2 )
{
int V_266 = 0 , V_267 = 0 , V_268 = 0 ;
F_11 ( V_2 , 3 , L_115 ) ;
V_266 = F_113 ( & V_2 -> V_51 ) ;
V_267 = F_113 ( & V_2 -> V_88 ) ;
V_268 = F_113 ( & V_2 -> V_56 ) ;
if ( V_266 )
return V_266 ;
if ( V_267 )
return V_267 ;
return V_268 ;
}
static int F_121 ( struct V_1 * V_2 , int V_269 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_116 ) ;
if ( V_269 )
V_26 = F_119 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_120 ( V_2 ) ;
}
int F_122 ( struct V_1 * V_2 , int V_270 )
{
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_117 ) ;
switch ( F_123 ( & V_2 -> V_35 . V_44 , V_271 ,
V_272 ) ) {
case V_271 :
if ( V_2 -> V_3 . type == V_6 )
V_26 = F_124 ( F_125 ( V_2 ) ,
V_273 ) ;
else
V_26 = F_124 ( F_125 ( V_2 ) ,
V_274 ) ;
if ( V_26 )
F_56 ( V_2 , 3 , L_118 , V_26 ) ;
F_126 ( F_125 ( V_2 ) ) ;
F_30 ( & V_2 -> V_35 . V_44 , V_275 ) ;
break;
case V_272 :
return V_26 ;
default:
break;
}
V_26 = F_121 ( V_2 , V_270 ) ;
if ( V_26 )
F_56 ( V_2 , 3 , L_119 , V_26 ) ;
V_2 -> V_44 = V_45 ;
return V_26 ;
}
static int F_127 ( struct V_1 * V_2 , void * * V_89 ,
int * V_181 )
{
struct V_276 * V_276 ;
char * V_277 ;
int V_278 ;
struct V_92 * V_93 = & V_2 -> V_56 ;
unsigned long V_21 ;
V_276 = F_128 ( V_93 -> V_58 , V_279 ) ;
if ( ! V_276 || V_276 -> V_69 == 0 )
return - V_280 ;
V_277 = F_33 ( V_276 -> V_98 , V_38 | V_123 ) ;
if ( ! V_277 )
return - V_39 ;
V_93 -> V_59 . V_281 = V_276 -> V_69 ;
V_93 -> V_59 . V_99 = ( T_1 ) F_59 ( V_277 ) ;
V_93 -> V_59 . V_98 = V_276 -> V_98 ;
V_93 -> V_59 . V_21 = V_282 ;
V_93 -> V_44 = V_283 ;
F_4 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
V_278 = F_129 ( V_93 -> V_58 , & V_93 -> V_59 ,
V_150 , V_284 , 0 ,
V_285 ) ;
F_5 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
if ( ! V_278 )
F_63 ( V_2 -> V_25 ,
( V_93 -> V_44 == V_164 ||
V_93 -> V_44 == V_151 ) ) ;
if ( V_93 -> V_44 == V_151 )
V_278 = - V_53 ;
else
V_93 -> V_44 = V_151 ;
if ( V_278 ) {
F_20 ( V_277 ) ;
* V_89 = NULL ;
* V_181 = 0 ;
} else {
* V_181 = V_276 -> V_98 ;
* V_89 = V_277 ;
}
return V_278 ;
}
static void F_130 ( struct V_1 * V_2 , char * V_286 )
{
F_68 ( V_122 , 2 , L_120 ) ;
V_2 -> V_3 . V_80 = V_286 [ 30 ] ;
V_2 -> V_3 . V_287 = V_286 [ 31 ] ;
V_2 -> V_3 . V_288 = V_286 [ 63 ] ;
V_2 -> V_3 . V_4 = ( ( V_286 [ 0x10 ] == V_289 [ 'V' ] ) &&
( V_286 [ 0x11 ] == V_289 [ 'M' ] ) ) ;
}
static void F_131 ( struct V_1 * V_2 , char * V_286 )
{
F_68 ( V_122 , 2 , L_121 ) ;
if ( V_286 [ 74 ] == 0xF0 && V_286 [ 75 ] == 0xF0 && V_286 [ 76 ] == 0xF5 ) {
V_2 -> V_3 . V_290 . V_291 = 250 ;
V_2 -> V_3 . V_290 . V_292 = 5 ;
V_2 -> V_3 . V_290 . V_293 = 15 ;
} else {
V_2 -> V_3 . V_290 . V_291 = 0 ;
V_2 -> V_3 . V_290 . V_292 = 0 ;
V_2 -> V_3 . V_290 . V_293 = 0 ;
}
}
static void F_132 ( struct V_1 * V_2 )
{
V_2 -> V_294 . V_295 = 0x00010103UL ;
V_2 -> V_294 . V_296 = 0x00010108UL ;
V_2 -> V_294 . V_297 = 0x0001010aUL ;
V_2 -> V_294 . V_298 = 0x0001010bUL ;
V_2 -> V_294 . V_299 = 0x0001010dUL ;
}
static void F_133 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
V_2 -> V_3 . V_200 = V_300 ;
break;
case V_5 :
case V_9 :
V_2 -> V_3 . V_200 = V_301 ;
break;
default:
break;
}
}
static int F_134 ( struct V_92 * V_93 ,
void (* F_135)( struct V_92 * ,
struct V_49 * ) )
{
struct V_49 * V_50 ;
unsigned long V_21 ;
int V_26 ;
struct V_1 * V_2 ;
F_68 ( V_122 , 2 , L_122 ) ;
V_2 = F_58 ( V_93 -> V_58 ) ;
V_50 = F_24 ( V_93 ) ;
V_50 -> V_106 = F_135 ;
memcpy ( & V_93 -> V_59 , V_95 , sizeof( struct V_96 ) ) ;
V_93 -> V_59 . V_98 = V_57 ;
V_93 -> V_59 . V_99 = ( T_1 ) F_59 ( V_50 -> V_56 ) ;
F_63 ( V_2 -> V_25 ,
F_123 ( & V_93 -> V_61 , 0 , 1 ) == 0 ) ;
F_68 ( V_122 , 6 , L_39 ) ;
F_4 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
V_26 = F_29 ( V_93 -> V_58 ,
& V_93 -> V_59 , ( V_60 ) V_50 , 0 , 0 ) ;
F_5 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
if ( V_26 ) {
F_26 ( 2 , L_123 , V_26 ) ;
F_95 ( V_122 , 2 , L_119 , V_26 ) ;
F_30 ( & V_93 -> V_61 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_116 ( V_2 -> V_25 ,
V_93 -> V_44 == V_52 , V_263 ) ;
if ( V_26 == - V_264 )
return V_26 ;
if ( V_93 -> V_44 != V_52 ) {
V_26 = - V_265 ;
F_95 ( V_122 , 2 , L_124 , V_26 ) ;
F_64 ( V_93 ) ;
} else
V_26 = 0 ;
return V_26 ;
}
static int F_136 ( struct V_92 * V_93 ,
void (* F_135)( struct V_92 * ,
struct V_49 * ) )
{
struct V_1 * V_2 ;
struct V_49 * V_50 ;
unsigned long V_21 ;
V_117 V_302 ;
T_2 V_30 ;
int V_26 ;
struct V_303 V_304 ;
V_2 = F_58 ( V_93 -> V_58 ) ;
F_68 ( V_122 , 2 , L_125 ) ;
V_50 = F_24 ( V_93 ) ;
V_50 -> V_106 = F_135 ;
memcpy ( & V_93 -> V_59 , V_97 , sizeof( struct V_96 ) ) ;
V_93 -> V_59 . V_98 = V_305 ;
V_93 -> V_59 . V_99 = ( T_1 ) F_59 ( V_50 -> V_56 ) ;
if ( V_93 == & V_2 -> V_88 ) {
memcpy ( V_50 -> V_56 , V_306 , V_305 ) ;
memcpy ( F_137 ( V_50 -> V_56 ) ,
& V_2 -> V_114 . V_307 , V_121 ) ;
V_2 -> V_114 . V_307 ++ ;
} else {
memcpy ( V_50 -> V_56 , V_308 , V_305 ) ;
memcpy ( F_137 ( V_50 -> V_56 ) ,
& V_2 -> V_114 . V_307 , V_121 ) ;
}
V_30 = ( ( T_2 ) V_2 -> V_3 . V_309 ) | 0x80 ;
memcpy ( F_138 ( V_50 -> V_56 ) , & V_30 , 1 ) ;
memcpy ( F_139 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_295 , V_310 ) ;
memcpy ( F_140 ( V_50 -> V_56 ) ,
& V_2 -> V_3 . V_200 , sizeof( V_117 ) ) ;
F_141 ( F_125 ( V_2 ) , & V_304 ) ;
memcpy ( F_142 ( V_50 -> V_56 ) , & V_304 . V_311 , 2 ) ;
V_302 = ( V_2 -> V_3 . V_288 << 8 ) + V_2 -> V_3 . V_287 ;
memcpy ( F_143 ( V_50 -> V_56 ) , & V_302 , 2 ) ;
F_63 ( V_2 -> V_25 ,
F_123 ( & V_93 -> V_61 , 0 , 1 ) == 0 ) ;
F_68 ( V_122 , 6 , L_39 ) ;
F_4 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
V_26 = F_29 ( V_93 -> V_58 ,
& V_93 -> V_59 , ( V_60 ) V_50 , 0 , 0 ) ;
F_5 ( F_114 ( V_93 -> V_58 ) , V_21 ) ;
if ( V_26 ) {
F_26 ( 2 , L_126 ,
V_26 ) ;
F_95 ( V_122 , 2 , L_118 , V_26 ) ;
F_30 ( & V_93 -> V_61 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_26 = F_116 ( V_2 -> V_25 ,
V_93 -> V_44 == V_312 , V_263 ) ;
if ( V_26 == - V_264 )
return V_26 ;
if ( V_93 -> V_44 != V_312 ) {
F_25 ( & V_93 -> V_58 -> V_55 , L_127
L_128 ) ;
F_26 ( 2 , L_129 ,
F_27 ( & V_93 -> V_58 -> V_55 ) ) ;
F_95 ( V_122 , 2 , L_119 , - V_265 ) ;
F_64 ( V_93 ) ;
return - V_265 ;
}
return F_134 ( V_93 , F_135 ) ;
}
static int F_144 ( int V_313 )
{
if ( ( V_313 & 0xff ) == 8 )
return ( V_313 & 0xff ) + 0x400 ;
if ( ( ( V_313 >> 8 ) & 3 ) == 1 )
return ( V_313 & 0xff ) + 0x200 ;
return V_313 ;
}
static void F_145 ( struct V_92 * V_93 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_117 V_302 ;
F_68 ( V_122 , 2 , L_130 ) ;
if ( V_93 -> V_44 == V_151 ) {
V_93 -> V_44 = V_312 ;
goto V_111;
}
V_2 = F_58 ( V_93 -> V_58 ) ;
if ( ! ( F_146 ( V_50 -> V_56 ) ) ) {
if ( F_147 ( V_50 -> V_56 ) == V_314 )
F_57 ( & V_2 -> V_88 . V_58 -> V_55 ,
L_131
L_132 ) ;
else
F_26 ( 2 , L_133
L_134 ,
F_27 ( & V_2 -> V_88 . V_58 -> V_55 ) ) ;
goto V_111;
}
memcpy ( & V_302 , F_140 ( V_50 -> V_56 ) , 2 ) ;
if ( ( V_302 & ~ 0x0100 ) != F_144 ( V_2 -> V_3 . V_200 ) ) {
F_26 ( 2 , L_135
L_136
L_137 , F_27 ( & V_2 -> V_88 . V_58 -> V_55 ) ,
V_2 -> V_3 . V_200 , V_302 ) ;
goto V_111;
}
V_93 -> V_44 = V_52 ;
V_111:
F_61 ( V_93 , V_50 ) ;
}
static void F_148 ( struct V_92 * V_93 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_117 V_302 ;
F_68 ( V_122 , 2 , L_138 ) ;
if ( V_93 -> V_44 == V_151 ) {
V_93 -> V_44 = V_312 ;
goto V_111;
}
V_2 = F_58 ( V_93 -> V_58 ) ;
if ( F_54 ( V_2 , V_50 -> V_56 ) )
goto V_111;
if ( ! ( F_146 ( V_50 -> V_56 ) ) ) {
switch ( F_147 ( V_50 -> V_56 ) ) {
case V_314 :
F_57 ( & V_2 -> V_88 . V_58 -> V_55 ,
L_131
L_132 ) ;
break;
case V_315 :
case V_316 :
F_57 ( & V_2 -> V_51 . V_58 -> V_55 ,
L_139
L_140 ) ;
break;
default:
F_26 ( 2 , L_141
L_134 ,
F_27 ( & V_2 -> V_51 . V_58 -> V_55 ) ) ;
}
F_56 ( V_2 , 2 , L_142 ,
F_147 ( V_50 -> V_56 ) ) ;
goto V_111;
}
if ( ( ! F_149 ( V_50 -> V_56 ) ) ||
( V_2 -> V_3 . type == V_5 ) )
V_2 -> V_3 . V_317 = 1 ;
memcpy ( & V_302 , F_140 ( V_50 -> V_56 ) , 2 ) ;
if ( V_302 != F_144 ( V_2 -> V_3 . V_200 ) ) {
F_26 ( 2 , L_143
L_144 ,
F_27 ( & V_2 -> V_51 . V_58 -> V_55 ) ,
V_2 -> V_3 . V_200 , V_302 ) ;
goto V_111;
}
memcpy ( & V_2 -> V_294 . V_318 ,
F_139 ( V_50 -> V_56 ) ,
V_310 ) ;
memcpy ( & V_2 -> V_3 . V_242 [ 0 ] ,
F_150 ( V_50 -> V_56 ) , V_319 ) ;
V_93 -> V_44 = V_52 ;
V_111:
F_61 ( V_93 , V_50 ) ;
}
void F_151 ( struct V_1 * V_2 , int V_94 ,
struct V_49 * V_50 )
{
F_28 ( & V_2 -> V_88 , V_50 -> V_56 , V_94 ) ;
V_50 -> V_106 = F_61 ;
memcpy ( F_137 ( V_50 -> V_56 ) ,
& V_2 -> V_114 . V_307 , V_121 ) ;
V_2 -> V_114 . V_307 ++ ;
memcpy ( F_66 ( V_50 -> V_56 ) ,
& V_2 -> V_114 . V_320 , V_121 ) ;
V_2 -> V_114 . V_320 ++ ;
memcpy ( F_152 ( V_50 -> V_56 ) ,
& V_2 -> V_114 . V_120 , V_121 ) ;
F_55 ( V_90 , 2 , V_50 -> V_56 , V_91 ) ;
}
int F_153 ( struct V_1 * V_2 , int V_94 ,
struct V_49 * V_50 ,
int (* F_154)( struct V_1 * , struct V_63 * ,
unsigned long ) ,
void * V_321 )
{
int V_26 ;
unsigned long V_21 ;
struct V_63 * V_64 = NULL ;
unsigned long V_322 , V_323 ;
struct V_68 * V_69 ;
F_11 ( V_2 , 2 , L_145 ) ;
if ( V_2 -> V_62 ) {
F_61 ( V_50 -> V_93 , V_50 ) ;
return - V_53 ;
}
V_64 = F_32 ( V_2 ) ;
if ( ! V_64 ) {
return - V_39 ;
}
V_64 -> V_106 = F_154 ;
V_64 -> V_324 = V_321 ;
if ( V_2 -> V_44 == V_45 )
V_64 -> V_114 = V_115 ;
else
V_64 -> V_114 = V_2 -> V_114 . V_325 ++ ;
F_70 ( & V_64 -> V_25 ) ;
F_4 ( & V_2 -> V_87 , V_21 ) ;
F_65 ( & V_64 -> V_31 , & V_2 -> V_119 ) ;
F_5 ( & V_2 -> V_87 , V_21 ) ;
F_55 ( V_90 , 2 , V_50 -> V_56 , V_91 ) ;
while ( F_123 ( & V_2 -> V_88 . V_61 , 0 , 1 ) ) ;
F_151 ( V_2 , V_94 , V_50 ) ;
if ( F_45 ( V_50 -> V_56 ) )
V_323 = V_326 ;
else
V_323 = V_263 ;
V_322 = V_327 + V_323 ;
F_11 ( V_2 , 6 , L_39 ) ;
F_4 ( F_114 ( V_2 -> V_88 . V_58 ) , V_21 ) ;
V_26 = F_29 ( V_2 -> V_88 . V_58 , & V_2 -> V_88 . V_59 ,
( V_60 ) V_50 , 0 , 0 ) ;
F_5 ( F_114 ( V_2 -> V_88 . V_58 ) , V_21 ) ;
if ( V_26 ) {
F_26 ( 2 , L_146
L_147 ,
F_27 ( & V_2 -> V_88 . V_58 -> V_55 ) , V_26 ) ;
F_56 ( V_2 , 2 , L_148 , V_26 ) ;
F_4 ( & V_2 -> V_87 , V_21 ) ;
F_53 ( & V_64 -> V_31 ) ;
F_38 ( V_64 ) ;
F_5 ( & V_2 -> V_87 , V_21 ) ;
F_61 ( V_50 -> V_93 , V_50 ) ;
F_30 ( & V_2 -> V_88 . V_61 , 0 ) ;
F_6 ( & V_2 -> V_25 ) ;
return V_26 ;
}
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
if ( ( V_69 -> V_72 . V_73 == V_329 ) &&
( V_69 -> V_72 . V_330 == V_331 ) ) {
if ( ! F_155 ( V_64 -> V_25 ,
F_36 ( & V_64 -> V_67 ) , V_323 ) )
goto V_332;
} else {
while ( ! F_36 ( & V_64 -> V_67 ) ) {
if ( F_156 ( V_327 , V_322 ) )
goto V_332;
F_157 () ;
} ;
}
if ( V_64 -> V_26 == - V_53 )
goto error;
V_26 = V_64 -> V_26 ;
F_38 ( V_64 ) ;
return V_26 ;
V_332:
V_64 -> V_26 = - V_265 ;
F_4 ( & V_64 -> V_2 -> V_87 , V_21 ) ;
F_53 ( & V_64 -> V_31 ) ;
F_5 ( & V_64 -> V_2 -> V_87 , V_21 ) ;
F_37 ( & V_64 -> V_67 ) ;
error:
F_30 ( & V_2 -> V_88 . V_61 , 0 ) ;
F_61 ( V_50 -> V_93 , V_50 ) ;
V_2 -> V_88 . V_109 = ( V_2 -> V_88 . V_109 + 1 ) % V_104 ;
V_26 = V_64 -> V_26 ;
F_38 ( V_64 ) ;
return V_26 ;
}
static int F_158 ( struct V_1 * V_2 , struct V_63 * V_64 ,
unsigned long V_56 )
{
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_149 ) ;
V_50 = (struct V_49 * ) V_56 ;
memcpy ( & V_2 -> V_294 . V_333 ,
F_159 ( V_50 -> V_56 ) ,
V_310 ) ;
F_95 ( V_122 , 2 , L_61 , V_50 -> V_26 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_150 ) ;
V_50 = F_62 ( & V_2 -> V_88 ) ;
memcpy ( V_50 -> V_56 , V_334 , V_335 ) ;
memcpy ( F_161 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_318 , V_310 ) ;
memcpy ( F_162 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_296 , V_310 ) ;
V_26 = F_153 ( V_2 , V_335 , V_50 ,
F_158 , NULL ) ;
return V_26 ;
}
static int F_163 ( struct V_1 * V_2 , struct V_63 * V_64 ,
unsigned long V_56 )
{
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_151 ) ;
V_50 = (struct V_49 * ) V_56 ;
memcpy ( & V_2 -> V_294 . V_336 ,
F_164 ( V_50 -> V_56 ) ,
V_310 ) ;
F_95 ( V_122 , 2 , L_61 , V_50 -> V_26 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_152 ) ;
V_50 = F_62 ( & V_2 -> V_88 ) ;
memcpy ( V_50 -> V_56 , V_337 , V_338 ) ;
memcpy ( F_166 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_318 , V_310 ) ;
memcpy ( F_167 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_297 , V_310 ) ;
memcpy ( F_168 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_333 , V_310 ) ;
V_26 = F_153 ( V_2 , V_338 , V_50 ,
F_163 , NULL ) ;
return V_26 ;
}
static inline int F_169 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_261 :
return 1500 ;
case V_6 :
return V_2 -> V_3 . V_339 ;
case V_5 :
switch ( V_2 -> V_3 . V_10 ) {
case V_12 :
case V_16 :
return 2000 ;
default:
return 1492 ;
}
case V_7 :
case V_8 :
return 1492 ;
default:
return 1500 ;
}
}
static inline int F_170 ( int V_340 )
{
switch ( V_340 ) {
case 0x4000 :
return 8192 ;
case 0x6000 :
return 16384 ;
case 0xa000 :
return 32768 ;
case 0xffff :
return 57344 ;
default:
return 0 ;
}
}
static inline int F_171 ( struct V_1 * V_2 , int V_341 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
case V_6 :
return ( ( V_341 >= 576 ) &&
( V_341 <= V_2 -> V_3 . V_339 ) ) ;
case V_9 :
case V_261 :
default:
return 1 ;
}
}
static int F_172 ( struct V_1 * V_2 , struct V_63 * V_64 ,
unsigned long V_56 )
{
V_117 V_341 , V_340 ;
V_117 V_94 ;
T_2 V_10 ;
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_153 ) ;
V_50 = (struct V_49 * ) V_56 ;
memcpy ( & V_2 -> V_294 . V_342 ,
F_173 ( V_50 -> V_56 ) ,
V_310 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
memcpy ( & V_340 , F_174 ( V_50 -> V_56 ) , 2 ) ;
V_341 = F_170 ( V_340 ) ;
if ( ! V_341 ) {
V_50 -> V_26 = - V_343 ;
F_95 ( V_122 , 2 , L_61 , V_50 -> V_26 ) ;
return 0 ;
}
if ( V_2 -> V_3 . V_344 && ( V_2 -> V_3 . V_344 != V_341 ) ) {
if ( V_2 -> V_55 &&
( ( V_2 -> V_55 -> V_341 == V_2 -> V_3 . V_344 ) ||
( V_2 -> V_55 -> V_341 > V_341 ) ) )
V_2 -> V_55 -> V_341 = V_341 ;
F_90 ( V_2 ) ;
}
V_2 -> V_3 . V_344 = V_341 ;
V_2 -> V_3 . V_339 = V_341 ;
V_2 -> V_35 . V_201 = V_341 + 2 * V_345 ;
} else {
V_2 -> V_3 . V_344 = F_169 ( V_2 ) ;
V_2 -> V_3 . V_339 = * ( V_117 * ) F_174 (
V_50 -> V_56 ) ;
V_2 -> V_35 . V_201 = V_202 ;
}
memcpy ( & V_94 , F_175 ( V_50 -> V_56 ) , 2 ) ;
if ( V_94 >= V_346 ) {
memcpy ( & V_10 ,
F_176 ( V_50 -> V_56 ) , 1 ) ;
V_2 -> V_3 . V_10 = V_10 ;
} else
V_2 -> V_3 . V_10 = 0 ;
F_95 ( V_122 , 2 , L_154 , V_2 -> V_3 . V_10 ) ;
F_95 ( V_122 , 2 , L_61 , V_50 -> V_26 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_26 ;
char V_347 ;
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_155 ) ;
V_50 = F_62 ( & V_2 -> V_88 ) ;
memcpy ( V_50 -> V_56 , V_348 , V_349 ) ;
* ( F_178 ( V_50 -> V_56 ) ) =
( T_2 ) V_2 -> V_3 . V_309 ;
if ( V_2 -> V_205 . V_247 )
if ( V_2 -> V_3 . type == V_9 )
V_347 = V_350 ;
else
V_347 = V_351 ;
else
V_347 = V_352 ;
memcpy ( F_179 ( V_50 -> V_56 ) , & V_347 , 1 ) ;
memcpy ( F_180 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_336 , V_310 ) ;
memcpy ( F_181 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_298 , V_310 ) ;
memcpy ( F_182 ( V_50 -> V_56 ) ,
V_2 -> V_3 . V_353 , 9 ) ;
V_26 = F_153 ( V_2 , V_349 , V_50 ,
F_172 , NULL ) ;
return V_26 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_63 * V_64 ,
unsigned long V_56 )
{
struct V_49 * V_50 ;
int V_26 = 0 ;
F_68 ( V_122 , 2 , L_156 ) ;
V_50 = (struct V_49 * ) V_56 ;
memcpy ( & V_2 -> V_294 . V_354 ,
F_184 ( V_50 -> V_56 ) ,
V_310 ) ;
if ( ! strncmp ( L_157 , F_184 ( V_50 -> V_56 ) ,
3 ) ) {
F_68 ( V_122 , 2 , L_158 ) ;
F_57 ( & V_2 -> V_54 -> V_55 , L_159
L_160 ) ;
V_50 -> V_26 = - V_355 ;
}
F_95 ( V_122 , 2 , L_61 , V_50 -> V_26 ) ;
return V_26 ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_26 ;
V_117 V_302 ;
struct V_49 * V_50 ;
struct V_303 V_356 ;
F_68 ( V_122 , 2 , L_161 ) ;
V_50 = F_62 ( & V_2 -> V_88 ) ;
memcpy ( V_50 -> V_56 , V_357 , V_358 ) ;
memcpy ( F_186 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_336 , V_310 ) ;
memcpy ( F_187 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_299 , V_310 ) ;
memcpy ( F_188 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_342 , V_310 ) ;
F_141 ( F_125 ( V_2 ) , & V_356 ) ;
memcpy ( F_189 ( V_50 -> V_56 ) , & V_356 . V_311 , 2 ) ;
V_302 = ( V_2 -> V_3 . V_288 << 8 ) + V_2 -> V_3 . V_287 ;
memcpy ( F_190 ( V_50 -> V_56 ) , & V_302 , 2 ) ;
V_26 = F_153 ( V_2 , V_358 , V_50 ,
F_183 , NULL ) ;
return V_26 ;
}
static int F_191 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
F_68 ( V_122 , 2 , L_162 ) ;
if ( F_123 ( & V_2 -> V_35 . V_44 , V_189 ,
V_275 ) != V_189 )
return 0 ;
V_2 -> V_35 . V_190 = F_15 ( sizeof( struct V_359 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_190 )
goto V_360;
F_68 ( V_122 , 2 , L_163 ) ;
F_55 ( V_122 , 2 , & V_2 -> V_35 . V_190 , sizeof( void * ) ) ;
memset ( V_2 -> V_35 . V_190 , 0 , sizeof( struct V_359 ) ) ;
for ( V_33 = 0 ; V_33 < V_187 ; ++ V_33 )
V_2 -> V_35 . V_190 -> V_188 [ V_33 ] . V_89 =
& V_2 -> V_35 . V_190 -> V_361 [ V_33 ] ;
if ( F_14 ( V_2 ) )
goto V_362;
V_2 -> V_35 . V_186 =
F_15 ( V_2 -> V_35 . V_185 *
sizeof( struct V_166 * ) , V_38 ) ;
if ( ! V_2 -> V_35 . V_186 )
goto V_363;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_185 ; ++ V_33 ) {
V_2 -> V_35 . V_186 [ V_33 ] = F_15 ( sizeof( struct V_166 ) ,
V_38 ) ;
if ( ! V_2 -> V_35 . V_186 [ V_33 ] )
goto V_364;
F_95 ( V_122 , 2 , L_164 , V_33 ) ;
F_55 ( V_122 , 2 , & V_2 -> V_35 . V_186 [ V_33 ] , sizeof( void * ) ) ;
memset ( V_2 -> V_35 . V_186 [ V_33 ] , 0 , sizeof( struct V_166 ) ) ;
V_2 -> V_35 . V_186 [ V_33 ] -> V_365 = V_33 ;
for ( V_34 = 0 ; V_34 < V_187 ; ++ V_34 ) {
V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] . V_89 =
& V_2 -> V_35 . V_186 [ V_33 ] -> V_361 [ V_34 ] ;
F_192 ( & V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] .
V_176 ) ;
F_193 (
& V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] . V_176 . V_87 ,
& V_366 ) ;
F_97 ( & V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] . V_367 ) ;
}
}
return 0 ;
V_364:
while ( V_33 > 0 )
F_20 ( V_2 -> V_35 . V_186 [ -- V_33 ] ) ;
F_20 ( V_2 -> V_35 . V_186 ) ;
V_2 -> V_35 . V_186 = NULL ;
V_363:
F_16 ( V_2 ) ;
V_362:
F_20 ( V_2 -> V_35 . V_190 ) ;
V_2 -> V_35 . V_190 = NULL ;
V_360:
F_30 ( & V_2 -> V_35 . V_44 , V_189 ) ;
return - V_39 ;
}
static void F_194 ( struct V_1 * V_2 ,
char * V_368 )
{
V_368 [ 0 ] = V_289 [ 'P' ] ;
V_368 [ 1 ] = V_289 [ 'C' ] ;
V_368 [ 2 ] = V_289 [ 'I' ] ;
V_368 [ 3 ] = V_289 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_368 [ 4 ] ) ) = F_195 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_368 [ 8 ] ) ) = F_196 ( V_2 ) ;
* ( ( unsigned int * ) ( & V_368 [ 12 ] ) ) = F_197 ( V_2 ) ;
}
static void F_198 ( struct V_1 * V_2 ,
char * V_368 )
{
V_368 [ 16 ] = V_289 [ 'B' ] ;
V_368 [ 17 ] = V_289 [ 'L' ] ;
V_368 [ 18 ] = V_289 [ 'K' ] ;
V_368 [ 19 ] = V_289 [ 'T' ] ;
* ( ( unsigned int * ) ( & V_368 [ 20 ] ) ) = V_2 -> V_3 . V_290 . V_291 ;
* ( ( unsigned int * ) ( & V_368 [ 24 ] ) ) = V_2 -> V_3 . V_290 . V_292 ;
* ( ( unsigned int * ) ( & V_368 [ 28 ] ) ) =
V_2 -> V_3 . V_290 . V_293 ;
}
static int F_199 ( struct V_1 * V_2 )
{
F_68 ( V_122 , 3 , L_165 ) ;
return F_200 ( F_125 ( V_2 ) ) ;
}
static int F_201 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_166 ) ;
V_50 = F_62 ( & V_2 -> V_88 ) ;
memcpy ( V_50 -> V_56 , V_369 , V_370 ) ;
memcpy ( F_202 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_336 , V_310 ) ;
memcpy ( F_203 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_354 , V_310 ) ;
V_26 = F_153 ( V_2 , V_370 , V_50 , NULL , NULL ) ;
return V_26 ;
}
static int F_204 ( struct V_1 * V_2 )
{
int V_26 ;
F_68 ( V_122 , 2 , L_167 ) ;
V_26 = F_23 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_118 , V_26 ) ;
return V_26 ;
}
V_26 = F_160 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_119 , V_26 ) ;
goto V_371;
}
V_26 = F_165 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_124 , V_26 ) ;
goto V_371;
}
V_26 = F_177 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_168 , V_26 ) ;
goto V_371;
}
V_26 = F_185 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_169 , V_26 ) ;
goto V_371;
}
V_26 = F_191 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_169 , V_26 ) ;
goto V_371;
}
V_26 = F_205 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_170 , V_26 ) ;
F_90 ( V_2 ) ;
goto V_371;
}
V_26 = F_199 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_171 , V_26 ) ;
goto V_371;
}
V_26 = F_201 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_172 , V_26 ) ;
goto V_371;
}
return 0 ;
V_371:
F_122 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
return V_26 ;
}
static void F_206 ( struct V_1 * V_2 )
{
char V_372 [ 15 ] ;
int V_33 ;
sprintf ( V_372 , L_173 , V_2 -> V_3 . V_353 + 1 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
V_372 [ V_33 ] =
( char ) V_373 [ ( T_2 ) V_372 [ V_33 ] ] ;
V_372 [ 8 ] = 0 ;
F_50 ( & V_2 -> V_54 -> V_55 , L_174
L_175 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? L_176 : L_58 ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? V_2 -> V_3 . V_242 : L_58 ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? L_177 : L_58 ,
F_2 ( V_2 ) ,
V_372 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_353 [ 0 ] )
F_50 ( & V_2 -> V_54 -> V_55 , L_178
L_179
L_180 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? L_176 : L_58 ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? V_2 -> V_3 . V_242 : L_58 ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? L_177 : L_58 ,
F_2 ( V_2 ) ) ;
else
F_50 ( & V_2 -> V_54 -> V_55 , L_178
L_181 ,
F_1 ( V_2 ) ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? L_176 : L_58 ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? V_2 -> V_3 . V_242 : L_58 ,
( V_2 -> V_3 . V_242 [ 0 ] ) ? L_177 : L_58 ,
F_2 ( V_2 ) ) ;
}
void F_208 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_5 :
case V_7 :
case V_8 :
if ( ! V_2 -> V_3 . V_242 [ 0 ] ) {
sprintf ( V_2 -> V_3 . V_242 , L_182 ,
V_2 -> V_3 . V_242 [ 2 ] ,
V_2 -> V_3 . V_242 [ 3 ] ) ;
V_2 -> V_3 . V_242 [ V_319 ] = 0 ;
break;
}
case V_6 :
if ( ( V_2 -> V_3 . V_4 ) ||
( V_2 -> V_3 . V_242 [ 0 ] & 0x80 ) ) {
V_2 -> V_3 . V_242 [ 0 ] = ( char ) V_373 [ ( T_2 )
V_2 -> V_3 . V_242 [ 0 ] ] ;
V_2 -> V_3 . V_242 [ 1 ] = ( char ) V_373 [ ( T_2 )
V_2 -> V_3 . V_242 [ 1 ] ] ;
V_2 -> V_3 . V_242 [ 2 ] = ( char ) V_373 [ ( T_2 )
V_2 -> V_3 . V_242 [ 2 ] ] ;
V_2 -> V_3 . V_242 [ 3 ] = ( char ) V_373 [ ( T_2 )
V_2 -> V_3 . V_242 [ 3 ] ] ;
V_2 -> V_3 . V_242 [ V_319 ] = 0 ;
}
break;
default:
memset ( & V_2 -> V_3 . V_242 [ 0 ] , 0 , V_319 + 1 ) ;
}
if ( V_2 -> V_3 . V_317 )
F_206 ( V_2 ) ;
else
F_207 ( V_2 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_28 * V_374 ;
F_11 ( V_2 , 5 , L_183 ) ;
F_210 (entry,
&card->qdio.init_pool.entry_list, init_list) {
F_211 ( V_2 , V_374 ) ;
}
}
static inline struct V_28 * F_212 (
struct V_1 * V_2 )
{
struct V_243 * V_375 ;
struct V_28 * V_374 ;
int V_33 , free ;
struct V_376 * V_376 ;
if ( F_213 ( & V_2 -> V_35 . V_48 . V_42 ) )
return NULL ;
F_214 (plh, &card->qdio.in_buf_pool.entry_list) {
V_374 = F_215 ( V_375 , struct V_28 , V_31 ) ;
free = 1 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_216 ( F_217 ( V_374 -> V_40 [ V_33 ] ) ) > 1 ) {
free = 0 ;
break;
}
}
if ( free ) {
F_53 ( & V_374 -> V_31 ) ;
return V_374 ;
}
}
V_374 = F_215 ( V_2 -> V_35 . V_48 . V_42 . V_377 ,
struct V_28 , V_31 ) ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
if ( F_216 ( F_217 ( V_374 -> V_40 [ V_33 ] ) ) > 1 ) {
V_376 = F_218 ( V_65 ) ;
if ( ! V_376 ) {
return NULL ;
} else {
F_19 ( ( unsigned long ) V_374 -> V_40 [ V_33 ] ) ;
V_374 -> V_40 [ V_33 ] = F_219 ( V_376 ) ;
if ( V_2 -> V_205 . V_216 )
V_2 -> V_378 . V_379 ++ ;
}
}
}
F_53 ( & V_374 -> V_31 ) ;
return V_374 ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_380 * V_169 )
{
struct V_28 * V_29 ;
int V_33 ;
V_29 = F_212 ( V_2 ) ;
if ( ! V_29 )
return 1 ;
V_169 -> V_29 = V_29 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) ; ++ V_33 ) {
V_169 -> V_89 -> V_172 [ V_33 ] . V_181 = V_345 ;
V_169 -> V_89 -> V_172 [ V_33 ] . V_178 = V_29 -> V_40 [ V_33 ] ;
if ( V_33 == F_17 ( V_2 ) - 1 )
V_169 -> V_89 -> V_172 [ V_33 ] . V_182 = V_381 ;
else
V_169 -> V_89 -> V_172 [ V_33 ] . V_182 = 0 ;
V_169 -> V_89 -> V_172 [ V_33 ] . V_173 = 0 ;
}
return 0 ;
}
int F_221 ( struct V_1 * V_2 )
{
int V_33 , V_34 ;
int V_26 ;
F_68 ( V_122 , 2 , L_184 ) ;
memset ( V_2 -> V_35 . V_190 -> V_361 , 0 ,
V_187 * sizeof( struct V_382 ) ) ;
F_209 ( V_2 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_48 . V_37 - 1 ; ++ V_33 )
F_220 ( V_2 , & V_2 -> V_35 . V_190 -> V_188 [ V_33 ] ) ;
V_2 -> V_35 . V_190 -> V_383 =
V_2 -> V_35 . V_48 . V_37 - 1 ;
V_26 = F_222 ( F_125 ( V_2 ) , V_384 , 0 , 0 ,
V_2 -> V_35 . V_48 . V_37 - 1 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_118 , V_26 ) ;
return V_26 ;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_35 . V_185 ; ++ V_33 ) {
memset ( V_2 -> V_35 . V_186 [ V_33 ] -> V_361 , 0 ,
V_187 * sizeof( struct V_382 ) ) ;
for ( V_34 = 0 ; V_34 < V_187 ; ++ V_34 ) {
F_84 ( V_2 -> V_35 . V_186 [ V_33 ] ,
& V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] ) ;
}
V_2 -> V_35 . V_186 [ V_33 ] -> V_2 = V_2 ;
V_2 -> V_35 . V_186 [ V_33 ] -> V_385 = 0 ;
V_2 -> V_35 . V_186 [ V_33 ] -> V_386 = 0 ;
F_30 ( & V_2 -> V_35 . V_186 [ V_33 ] -> V_387 , 0 ) ;
F_30 ( & V_2 -> V_35 . V_186 [ V_33 ] -> V_175 , 0 ) ;
F_30 ( & V_2 -> V_35 . V_186 [ V_33 ] -> V_44 ,
V_388 ) ;
}
return 0 ;
}
static inline T_2 F_223 ( enum V_389 V_10 )
{
switch ( V_10 ) {
case V_12 :
return 2 ;
default:
return 1 ;
}
}
static void F_224 ( struct V_1 * V_2 ,
struct V_68 * V_69 , T_2 V_73 ,
enum V_390 V_391 )
{
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 -> V_72 . V_73 = V_73 ;
V_69 -> V_72 . V_392 = V_393 ;
V_69 -> V_72 . V_114 = V_2 -> V_114 . V_325 ;
V_69 -> V_72 . V_394 = F_223 ( V_2 -> V_3 . V_10 ) ;
V_69 -> V_72 . V_395 = ( T_2 ) V_2 -> V_3 . V_309 ;
if ( V_2 -> V_205 . V_247 )
V_69 -> V_72 . V_396 = 2 ;
else
V_69 -> V_72 . V_396 = 1 ;
V_69 -> V_72 . V_397 = 1 ;
V_69 -> V_72 . V_330 = V_391 ;
V_69 -> V_72 . V_398 = 0 ;
V_69 -> V_72 . V_399 = 0 ;
}
struct V_49 * F_225 ( struct V_1 * V_2 ,
enum V_400 V_401 , enum V_390 V_391 )
{
struct V_49 * V_50 ;
struct V_68 * V_69 ;
V_50 = F_62 ( & V_2 -> V_88 ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
F_224 ( V_2 , V_69 , V_401 , V_391 ) ;
return V_50 ;
}
void F_226 ( struct V_1 * V_2 , struct V_49 * V_50 ,
char V_347 )
{
memcpy ( V_50 -> V_56 , V_402 , V_328 ) ;
memcpy ( F_227 ( V_50 -> V_56 ) , & V_347 , 1 ) ;
memcpy ( F_228 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_354 , V_310 ) ;
}
int F_229 ( struct V_1 * V_2 , struct V_49 * V_50 ,
int (* F_154)( struct V_1 * , struct V_63 * ,
unsigned long ) ,
void * V_321 )
{
int V_26 ;
char V_347 ;
F_11 ( V_2 , 4 , L_185 ) ;
if ( V_2 -> V_205 . V_247 )
if ( V_2 -> V_3 . type == V_9 )
V_347 = V_350 ;
else
V_347 = V_351 ;
else
V_347 = V_352 ;
F_226 ( V_2 , V_50 , V_347 ) ;
V_26 = F_153 ( V_2 , V_403 ,
V_50 , F_154 , V_321 ) ;
if ( V_26 == - V_265 ) {
F_52 ( V_2 ) ;
F_31 ( V_2 ) ;
}
return V_26 ;
}
int F_230 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
F_68 ( V_122 , 2 , L_186 ) ;
V_50 = F_225 ( V_2 , V_82 , 0 ) ;
V_26 = F_229 ( V_2 , V_50 , NULL , NULL ) ;
return V_26 ;
}
int F_231 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
F_11 ( V_2 , 4 , L_187 ) ;
V_69 = (struct V_68 * ) V_56 ;
if ( V_69 -> V_72 . V_78 == 0 )
V_69 -> V_72 . V_78 =
V_69 -> V_56 . V_404 . V_72 . V_78 ;
return 0 ;
}
static int F_232 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
F_11 ( V_2 , 3 , L_188 ) ;
V_69 = (struct V_68 * ) V_56 ;
if ( V_69 -> V_56 . V_404 . V_56 . V_405 . V_406 & 0x7f ) {
V_2 -> V_3 . V_10 =
V_69 -> V_56 . V_404 . V_56 . V_405 . V_406 ;
F_95 ( V_122 , 2 , L_189 , V_2 -> V_3 . V_10 ) ;
}
V_2 -> V_205 . V_407 . V_408 =
V_69 -> V_56 . V_404 . V_56 . V_405 . V_409 ;
return F_231 ( V_2 , V_64 , ( unsigned long ) V_69 ) ;
}
struct V_49 * F_233 ( struct V_1 * V_2 ,
T_1 V_73 , T_1 V_410 )
{
struct V_49 * V_50 ;
struct V_68 * V_69 ;
V_50 = F_225 ( V_2 , V_411 ,
V_331 ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
V_69 -> V_56 . V_404 . V_72 . V_412 = V_410 ;
V_69 -> V_56 . V_404 . V_72 . V_413 = V_73 ;
V_69 -> V_56 . V_404 . V_72 . V_414 = 1 ;
V_69 -> V_56 . V_404 . V_72 . V_415 = 1 ;
return V_50 ;
}
int F_234 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
F_11 ( V_2 , 3 , L_190 ) ;
V_50 = F_233 ( V_2 , V_416 ,
sizeof( struct V_417 ) ) ;
V_26 = F_229 ( V_2 , V_50 , F_232 , NULL ) ;
return V_26 ;
}
static int F_235 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
F_68 ( V_122 , 2 , L_191 ) ;
V_69 = (struct V_68 * ) V_56 ;
if ( V_69 -> V_72 . V_330 == V_331 ) {
V_2 -> V_205 . V_418 . V_408 = V_69 -> V_72 . V_398 ;
V_2 -> V_205 . V_418 . V_419 = V_69 -> V_72 . V_399 ;
} else {
V_2 -> V_205 . V_420 . V_408 = V_69 -> V_72 . V_398 ;
V_2 -> V_205 . V_420 . V_419 = V_69 -> V_72 . V_399 ;
}
F_68 ( V_122 , 2 , L_192 ) ;
F_95 ( V_122 , 2 , L_193 , V_69 -> V_72 . V_398 ) ;
F_95 ( V_122 , 2 , L_193 , V_69 -> V_72 . V_399 ) ;
return 0 ;
}
int F_236 ( struct V_1 * V_2 , enum V_390 V_391 )
{
int V_26 ;
struct V_49 * V_50 ;
F_95 ( V_122 , 2 , L_194 , V_391 ) ;
V_50 = F_225 ( V_2 , V_421 , V_391 ) ;
V_26 = F_229 ( V_2 , V_50 , F_235 , NULL ) ;
return V_26 ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
V_117 V_26 ;
V_69 = (struct V_68 * ) V_56 ;
V_26 = V_69 -> V_72 . V_78 ;
if ( V_26 )
F_56 ( V_2 , 2 , L_195 , V_26 ) ;
else
V_2 -> V_3 . V_422 = V_69 -> V_56 . V_423 . V_424 ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_68 * V_69 ;
F_68 ( V_122 , 2 , L_196 ) ;
V_50 = F_225 ( V_2 , V_77 , 0 ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
V_69 -> V_56 . V_423 . V_425 = 16 ;
V_69 -> V_56 . V_423 . V_426 = V_427 ;
return F_229 ( V_2 , V_50 , F_237 , NULL ) ;
}
static void F_239 ( struct V_1 * V_2 , struct V_428 * V_429 )
{
unsigned long V_3 = F_240 ( V_38 ) ;
struct V_430 * V_431 = (struct V_430 * ) V_3 ;
struct V_432 * V_433 = (struct V_432 * ) V_3 ;
struct V_303 V_434 ;
int V_313 , V_26 ;
V_429 -> V_80 = V_2 -> V_3 . V_80 ;
F_141 ( F_112 ( V_2 ) , & V_434 ) ;
V_429 -> V_435 = V_434 . V_435 ;
V_429 -> V_311 = V_434 . V_311 ;
if ( ! V_3 )
return;
V_26 = F_241 ( NULL , 0 , 0 , 0 ) ;
if ( V_26 == - V_436 )
V_313 = V_26 ;
else
V_313 = ( ( ( unsigned int ) V_26 ) >> 28 ) ;
if ( ( V_313 >= 2 ) && ( F_241 ( V_431 , 2 , 2 , 2 ) != - V_436 ) )
V_429 -> V_437 = V_431 -> V_438 ;
if ( ( V_313 >= 3 ) && ( F_241 ( V_433 , 3 , 2 , 2 ) != - V_436 ) ) {
F_242 ( V_433 -> V_439 [ 0 ] . V_440 , sizeof( V_433 -> V_439 [ 0 ] . V_440 ) ) ;
memcpy ( V_429 -> V_441 , V_433 -> V_439 [ 0 ] . V_440 , sizeof( V_429 -> V_441 ) ) ;
}
F_19 ( V_3 ) ;
return;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
V_117 V_26 ;
V_69 = (struct V_68 * ) V_56 ;
V_26 = V_69 -> V_72 . V_78 ;
if ( V_26 )
F_56 ( V_2 , 2 , L_197 , V_26 ) ;
return 0 ;
}
int F_244 ( struct V_1 * V_2 , enum V_442 V_443 )
{
struct V_49 * V_50 ;
struct V_68 * V_69 ;
F_68 ( V_122 , 2 , L_198 ) ;
V_50 = F_225 ( V_2 , V_77 , 0 ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
V_69 -> V_56 . V_423 . V_425 = 80 ;
V_69 -> V_56 . V_423 . V_426 = V_444 ;
V_69 -> V_56 . V_423 . type = 1 ;
V_69 -> V_56 . V_423 . V_443 = V_443 ;
switch ( V_443 ) {
case V_445 :
V_69 -> V_56 . V_423 . V_205 = 0x0003 ;
V_69 -> V_56 . V_423 . V_424 = 0x00010000 +
sizeof( struct V_428 ) ;
F_239 ( V_2 ,
(struct V_428 * ) V_69 -> V_56 . V_423 . V_446 ) ;
break;
case V_447 :
V_69 -> V_56 . V_423 . V_205 = 0x0001 ;
break;
case V_448 :
break;
}
return F_229 ( V_2 , V_50 , F_243 , NULL ) ;
}
int F_245 ( struct V_1 * V_2 , struct V_382 * V_169 ,
unsigned int V_449 , const char * V_450 )
{
if ( V_449 ) {
F_11 ( V_2 , 2 , V_450 ) ;
F_56 ( V_2 , 2 , L_199 ,
V_169 -> V_172 [ 15 ] . V_173 ) ;
F_56 ( V_2 , 2 , L_200 ,
V_169 -> V_172 [ 14 ] . V_173 ) ;
F_56 ( V_2 , 2 , L_201 , V_449 ) ;
if ( ( V_169 -> V_172 [ 15 ] . V_173 ) == 0x12 ) {
V_2 -> V_451 . V_452 ++ ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
void F_246 ( struct V_1 * V_2 , int V_100 )
{
struct V_359 * V_167 = V_2 -> V_35 . V_190 ;
int V_98 ;
int V_33 ;
int V_26 ;
int V_453 = 0 ;
V_98 = ( V_100 < V_167 -> V_383 ) ?
V_2 -> V_35 . V_48 . V_37 -
( V_167 -> V_383 - V_100 ) :
V_2 -> V_35 . V_48 . V_37 -
( V_167 -> V_383 + V_187 - V_100 ) ;
if ( V_98 >= F_247 ( V_2 ) ) {
for ( V_33 = V_167 -> V_383 ;
V_33 < V_167 -> V_383 + V_98 ; ++ V_33 ) {
if ( F_220 ( V_2 ,
& V_167 -> V_188 [ V_33 % V_187 ] ) ) {
break;
} else {
V_453 ++ ;
}
}
if ( V_453 < V_98 ) {
F_30 ( & V_2 -> V_454 , 3 ) ;
V_98 = V_453 ;
} else {
F_248 ( & V_2 -> V_454 , - 1 , 0 ) ;
}
if ( V_2 -> V_205 . V_216 ) {
V_2 -> V_378 . V_455 ++ ;
V_2 -> V_378 . V_456 =
F_249 () ;
}
V_26 = F_222 ( F_125 ( V_2 ) , V_384 , 0 ,
V_167 -> V_383 , V_98 ) ;
if ( V_2 -> V_205 . V_216 )
V_2 -> V_378 . V_457 +=
F_249 () -
V_2 -> V_378 . V_456 ;
if ( V_26 ) {
F_25 ( & V_2 -> V_54 -> V_55 ,
L_202 , V_26 ) ;
F_11 ( V_2 , 2 , L_203 ) ;
}
V_167 -> V_383 = ( V_167 -> V_383 + V_98 ) %
V_187 ;
}
}
static int F_250 ( struct V_1 * V_2 ,
struct V_168 * V_89 , unsigned int V_458 )
{
int V_459 = V_89 -> V_89 -> V_172 [ 15 ] . V_173 ;
F_11 ( V_2 , 6 , L_204 ) ;
if ( V_2 -> V_3 . type == V_6 ) {
if ( V_459 == 0 ) {
V_458 = 0 ;
} else {
V_458 = 1 ;
}
}
F_245 ( V_2 , V_89 -> V_89 , V_458 , L_205 ) ;
if ( ! V_458 )
return V_460 ;
if ( ( V_459 >= 15 ) && ( V_459 <= 31 ) )
return V_461 ;
F_11 ( V_2 , 1 , L_206 ) ;
F_56 ( V_2 , 1 , L_207 ,
( V_118 ) V_458 , ( T_3 ) V_459 ) ;
return V_462 ;
}
static void F_251 ( struct V_166 * V_167 )
{
if ( ! V_167 -> V_386 ) {
if ( F_36 ( & V_167 -> V_387 )
>= V_463 ) {
F_11 ( V_167 -> V_2 , 6 , L_208 ) ;
if ( V_167 -> V_2 -> V_205 . V_216 )
V_167 -> V_2 -> V_378 . V_464 ++ ;
V_167 -> V_386 = 1 ;
}
}
}
static int F_252 ( struct V_166 * V_167 )
{
struct V_168 * V_89 ;
int V_465 = 0 ;
if ( V_167 -> V_386 ) {
if ( F_36 ( & V_167 -> V_387 )
<= V_466 ) {
F_11 ( V_167 -> V_2 , 6 , L_209 ) ;
if ( V_167 -> V_2 -> V_205 . V_216 )
V_167 -> V_2 -> V_378 . V_467 ++ ;
V_167 -> V_386 = 0 ;
V_89 = & V_167 -> V_188 [ V_167 -> V_385 ] ;
if ( ( F_36 ( & V_89 -> V_44 ) ==
V_184 ) &&
( V_89 -> V_183 > 0 ) ) {
F_30 ( & V_89 -> V_44 ,
V_468 ) ;
V_465 ++ ;
V_167 -> V_385 =
( V_167 -> V_385 + 1 ) %
V_187 ;
}
}
}
return V_465 ;
}
static int F_253 ( struct V_166 * V_167 )
{
struct V_168 * V_89 ;
V_89 = & V_167 -> V_188 [ V_167 -> V_385 ] ;
if ( ( F_36 ( & V_89 -> V_44 ) == V_184 ) &&
( V_89 -> V_183 > 0 ) ) {
F_30 ( & V_89 -> V_44 , V_468 ) ;
V_167 -> V_385 =
( V_167 -> V_385 + 1 ) % V_187 ;
return 1 ;
}
return 0 ;
}
static void F_254 ( struct V_166 * V_167 , int V_100 ,
int V_98 )
{
struct V_168 * V_169 ;
int V_26 ;
int V_33 ;
unsigned int V_469 ;
for ( V_33 = V_100 ; V_33 < V_100 + V_98 ; ++ V_33 ) {
V_169 = & V_167 -> V_188 [ V_33 % V_187 ] ;
V_169 -> V_89 -> V_172 [ V_169 -> V_183 - 1 ] . V_182 |=
V_381 ;
if ( V_167 -> V_2 -> V_3 . type == V_6 )
continue;
if ( ! V_167 -> V_386 ) {
if ( ( F_36 ( & V_167 -> V_387 ) >=
( V_463 -
V_470 ) ) &&
! F_36 ( & V_167 -> V_175 ) ) {
F_37 ( & V_167 -> V_175 ) ;
V_169 -> V_89 -> V_172 [ 0 ] . V_173 |= V_174 ;
}
} else {
if ( ! F_36 ( & V_167 -> V_175 ) ) {
F_37 ( & V_167 -> V_175 ) ;
V_169 -> V_89 -> V_172 [ 0 ] . V_173 |= V_174 ;
}
}
}
V_167 -> V_2 -> V_55 -> V_471 = V_327 ;
if ( V_167 -> V_2 -> V_205 . V_216 ) {
V_167 -> V_2 -> V_378 . V_472 ++ ;
V_167 -> V_2 -> V_378 . V_473 =
F_249 () ;
}
V_469 = V_474 ;
if ( F_36 ( & V_167 -> V_175 ) )
V_469 |= V_475 ;
V_26 = F_222 ( F_125 ( V_167 -> V_2 ) , V_469 ,
V_167 -> V_365 , V_100 , V_98 ) ;
if ( V_167 -> V_2 -> V_205 . V_216 )
V_167 -> V_2 -> V_378 . V_476 +=
F_249 () -
V_167 -> V_2 -> V_378 . V_473 ;
F_255 ( V_98 , & V_167 -> V_387 ) ;
if ( V_26 ) {
V_167 -> V_2 -> V_451 . V_477 += V_98 ;
if ( V_26 == V_478 )
return;
F_11 ( V_167 -> V_2 , 2 , L_210 ) ;
F_56 ( V_167 -> V_2 , 2 , L_148 , V_26 ) ;
F_31 ( V_167 -> V_2 ) ;
return;
}
if ( V_167 -> V_2 -> V_205 . V_216 )
V_167 -> V_2 -> V_378 . V_479 += V_98 ;
}
static void F_256 ( struct V_166 * V_167 )
{
int V_100 ;
int V_480 = 0 ;
int V_481 = 0 ;
if ( ( F_36 ( & V_167 -> V_387 ) <= V_466 ) ||
! F_36 ( & V_167 -> V_175 ) ) {
if ( F_91 ( & V_167 -> V_44 , V_482 ) ==
V_388 ) {
F_257 ( V_167 -> V_2 -> V_55 ) ;
V_100 = V_167 -> V_385 ;
V_481 = V_167 -> V_386 ;
F_258 () ;
V_480 += F_252 ( V_167 ) ;
if ( ! V_480 &&
! F_36 ( & V_167 -> V_175 ) )
V_480 +=
F_253 ( V_167 ) ;
if ( V_167 -> V_2 -> V_205 . V_216 &&
V_481 )
V_167 -> V_2 -> V_378 . V_483 +=
V_480 ;
if ( V_480 )
F_254 ( V_167 , V_100 , V_480 ) ;
F_30 ( & V_167 -> V_44 , V_388 ) ;
}
}
}
void F_259 ( struct V_127 * V_58 , int V_167 ,
unsigned long V_484 )
{
struct V_1 * V_2 = (struct V_1 * ) V_484 ;
if ( V_2 -> V_55 && ( V_2 -> V_55 -> V_21 & V_485 ) )
F_260 ( & V_2 -> V_486 ) ;
}
void F_261 ( struct V_127 * V_58 , unsigned int V_458 ,
unsigned int V_167 , int V_487 , int V_98 ,
unsigned long V_484 )
{
struct V_1 * V_2 = (struct V_1 * ) V_484 ;
if ( V_458 )
F_31 ( V_2 ) ;
}
void F_262 ( struct V_127 * V_58 ,
unsigned int V_449 , int V_488 , int V_487 ,
int V_98 , unsigned long V_484 )
{
struct V_1 * V_2 = (struct V_1 * ) V_484 ;
struct V_166 * V_167 = V_2 -> V_35 . V_186 [ V_488 ] ;
struct V_168 * V_89 ;
int V_33 ;
F_11 ( V_2 , 6 , L_211 ) ;
if ( V_449 & V_489 ) {
F_11 ( V_2 , 2 , L_212 ) ;
F_257 ( V_2 -> V_55 ) ;
F_31 ( V_2 ) ;
return;
}
if ( V_2 -> V_205 . V_216 ) {
V_2 -> V_378 . V_490 ++ ;
V_2 -> V_378 . V_491 =
F_249 () ;
}
for ( V_33 = V_487 ; V_33 < ( V_487 + V_98 ) ; ++ V_33 ) {
V_89 = & V_167 -> V_188 [ V_33 % V_187 ] ;
F_250 ( V_2 , V_89 , V_449 ) ;
F_84 ( V_167 , V_89 ) ;
}
F_263 ( V_98 , & V_167 -> V_387 ) ;
if ( V_2 -> V_3 . type != V_6 )
F_256 ( V_167 ) ;
F_264 ( V_167 -> V_2 -> V_55 ) ;
if ( V_2 -> V_205 . V_216 )
V_2 -> V_378 . V_492 += F_249 () -
V_2 -> V_378 . V_491 ;
}
int F_265 ( struct V_1 * V_2 , struct V_170 * V_171 ,
int V_493 , int V_494 )
{
if ( ! V_493 && ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) )
return V_2 -> V_35 . V_199 ;
switch ( V_2 -> V_35 . V_185 ) {
case 4 :
if ( V_494 && V_2 -> V_3 . V_259 )
return V_2 -> V_3 . V_259 &
( V_2 -> V_35 . V_185 - 1 ) ;
if ( V_2 -> V_35 . V_249 && ( V_493 == 4 ) ) {
const T_3 V_495 = F_266 ( V_171 ) -> V_495 ;
if ( V_2 -> V_35 . V_249 ==
V_496 ) {
if ( V_495 & V_497 )
return 3 ;
if ( V_495 & V_498 )
return 2 ;
if ( V_495 & V_499 )
return 1 ;
if ( V_495 & V_500 )
return 0 ;
}
if ( V_2 -> V_35 . V_249 ==
V_501 )
return 3 - ( V_495 >> 6 ) ;
} else if ( V_2 -> V_35 . V_249 && ( V_493 == 6 ) ) {
}
return V_2 -> V_35 . V_199 ;
case 1 :
default:
return V_2 -> V_35 . V_199 ;
}
}
int F_267 ( struct V_1 * V_2 , void * V_72 ,
struct V_170 * V_171 , int V_502 )
{
int V_503 = V_171 -> V_94 - V_171 -> V_504 ;
int V_505 = F_268 ( ( unsigned long ) V_171 -> V_56 + V_503 - 1 ) -
F_269 ( ( unsigned long ) V_171 -> V_56 ) ;
V_505 += F_270 ( V_171 ) -> V_506 ;
if ( ( V_505 + V_502 ) > F_17 ( V_2 ) ) {
F_26 ( 2 , L_213
L_214 ,
( V_505 + V_502 ) , V_171 -> V_94 ) ;
return 0 ;
}
return V_505 ;
}
int F_271 ( struct V_170 * V_171 , int V_94 )
{
int V_507 , V_508 , V_509 ;
if ( ( ( unsigned long ) V_171 -> V_56 & V_510 ) !=
( ( ( unsigned long ) V_171 -> V_56 + V_94 - 1 ) & V_510 ) ) {
V_507 = F_272 ( V_171 ) ;
V_508 = V_345 - ( ( unsigned long ) V_171 -> V_56 % V_345 ) ;
V_509 = V_94 - V_508 ;
if ( V_509 > V_507 )
return 1 ;
memmove ( V_171 -> V_56 - V_509 , V_171 -> V_56 , V_171 -> V_94 - V_171 -> V_504 ) ;
V_171 -> V_56 -= V_509 ;
F_26 ( 2 , L_215 , V_94 , V_509 ) ;
}
return 0 ;
}
static inline void F_273 ( struct V_170 * V_171 ,
struct V_382 * V_89 , int V_511 , int * V_183 ,
int V_116 )
{
int V_181 = V_171 -> V_94 - V_171 -> V_504 ;
int V_512 ;
int V_172 ;
char * V_56 ;
int V_513 , V_108 ;
struct V_514 * V_515 ;
V_172 = * V_183 ;
V_56 = V_171 -> V_56 ;
V_513 = ( V_511 == 0 ? 1 : 0 ) ;
if ( V_116 >= 0 ) {
V_56 = V_171 -> V_56 + V_116 ;
V_181 -= V_116 ;
V_513 = 0 ;
}
while ( V_181 > 0 ) {
V_512 = V_345 - ( ( unsigned long ) V_56 % V_345 ) ;
if ( V_181 < V_512 )
V_512 = V_181 ;
V_89 -> V_172 [ V_172 ] . V_178 = V_56 ;
V_89 -> V_172 [ V_172 ] . V_181 = V_512 ;
V_181 -= V_512 ;
if ( ! V_181 ) {
if ( V_513 )
if ( F_270 ( V_171 ) -> V_506 )
V_89 -> V_172 [ V_172 ] . V_182 =
V_516 ;
else
V_89 -> V_172 [ V_172 ] . V_182 = 0 ;
else
V_89 -> V_172 [ V_172 ] . V_182 =
V_517 ;
} else {
if ( V_513 )
V_89 -> V_172 [ V_172 ] . V_182 =
V_516 ;
else
V_89 -> V_172 [ V_172 ] . V_182 =
V_517 ;
}
V_56 += V_512 ;
V_172 ++ ;
V_513 = 0 ;
}
for ( V_108 = 0 ; V_108 < F_270 ( V_171 ) -> V_506 ; V_108 ++ ) {
V_515 = & F_270 ( V_171 ) -> V_518 [ V_108 ] ;
V_89 -> V_172 [ V_172 ] . V_178 = ( char * ) F_274 ( V_515 -> V_376 )
+ V_515 -> V_519 ;
V_89 -> V_172 [ V_172 ] . V_181 = V_515 -> V_520 ;
V_89 -> V_172 [ V_172 ] . V_182 = V_517 ;
V_172 ++ ;
}
if ( V_89 -> V_172 [ V_172 - 1 ] . V_182 )
V_89 -> V_172 [ V_172 - 1 ] . V_182 = V_521 ;
* V_183 = V_172 ;
}
static inline int F_275 ( struct V_166 * V_167 ,
struct V_168 * V_169 , struct V_170 * V_171 ,
struct V_522 * V_72 , int V_116 , int V_523 )
{
struct V_382 * V_89 ;
int V_480 = 0 , V_524 , V_525 = 0 ;
V_89 = V_169 -> V_89 ;
F_37 ( & V_171 -> V_177 ) ;
F_276 ( & V_169 -> V_176 , V_171 ) ;
if ( V_72 -> V_72 . V_526 . V_254 == V_527 ) {
int V_172 = V_169 -> V_183 ;
V_524 = sizeof( struct V_528 ) +
( (struct V_528 * ) V_72 ) -> V_424 . V_529 ;
V_89 -> V_172 [ V_172 ] . V_178 = V_171 -> V_56 ;
V_89 -> V_172 [ V_172 ] . V_181 = V_524 ;
V_89 -> V_172 [ V_172 ] . V_182 = V_516 ;
V_169 -> V_183 ++ ;
V_171 -> V_56 += V_524 ;
V_171 -> V_94 -= V_524 ;
V_525 = 1 ;
}
if ( V_116 >= 0 ) {
int V_172 = V_169 -> V_183 ;
V_89 -> V_172 [ V_172 ] . V_178 = V_72 ;
V_89 -> V_172 [ V_172 ] . V_181 = sizeof( struct V_522 ) +
V_523 ;
V_89 -> V_172 [ V_172 ] . V_182 = V_516 ;
V_169 -> V_179 [ V_172 ] = 1 ;
V_169 -> V_183 ++ ;
}
F_273 ( V_171 , V_89 , V_525 ,
( int * ) & V_169 -> V_183 , V_116 ) ;
if ( ! V_167 -> V_386 ) {
F_11 ( V_167 -> V_2 , 6 , L_216 ) ;
F_30 ( & V_169 -> V_44 , V_468 ) ;
V_480 = 1 ;
} else {
F_11 ( V_167 -> V_2 , 6 , L_217 ) ;
if ( V_167 -> V_2 -> V_205 . V_216 )
V_167 -> V_2 -> V_378 . V_530 ++ ;
if ( V_169 -> V_183 >=
F_17 ( V_167 -> V_2 ) ) {
F_30 ( & V_169 -> V_44 , V_468 ) ;
V_480 = 1 ;
}
}
return V_480 ;
}
int F_277 ( struct V_1 * V_2 ,
struct V_166 * V_167 , struct V_170 * V_171 ,
struct V_522 * V_72 , int V_505 ,
int V_116 , int V_523 )
{
struct V_168 * V_89 ;
int V_100 ;
while ( F_123 ( & V_167 -> V_44 , V_388 ,
V_531 ) != V_388 ) ;
V_100 = V_167 -> V_385 ;
V_89 = & V_167 -> V_188 [ V_167 -> V_385 ] ;
if ( F_36 ( & V_89 -> V_44 ) != V_184 )
goto V_111;
V_167 -> V_385 = ( V_167 -> V_385 + 1 ) %
V_187 ;
F_30 ( & V_167 -> V_44 , V_388 ) ;
F_275 ( V_167 , V_89 , V_171 , V_72 , V_116 , V_523 ) ;
F_254 ( V_167 , V_100 , 1 ) ;
return 0 ;
V_111:
F_30 ( & V_167 -> V_44 , V_388 ) ;
return - V_532 ;
}
int F_278 ( struct V_1 * V_2 , struct V_166 * V_167 ,
struct V_170 * V_171 , struct V_522 * V_72 ,
int V_505 )
{
struct V_168 * V_89 ;
int V_533 ;
int V_465 = 0 ;
int V_386 = 0 ;
int V_30 ;
int V_26 = 0 ;
while ( F_123 ( & V_167 -> V_44 , V_388 ,
V_531 ) != V_388 ) ;
V_533 = V_167 -> V_385 ;
V_89 = & V_167 -> V_188 [ V_167 -> V_385 ] ;
if ( F_36 ( & V_89 -> V_44 ) != V_184 ) {
F_30 ( & V_167 -> V_44 , V_388 ) ;
return - V_532 ;
}
F_251 ( V_167 ) ;
if ( V_167 -> V_386 ) {
V_386 = 1 ;
if ( ( F_17 ( V_2 ) -
V_89 -> V_183 ) < V_505 ) {
F_30 ( & V_89 -> V_44 , V_468 ) ;
V_465 ++ ;
V_167 -> V_385 =
( V_167 -> V_385 + 1 ) %
V_187 ;
V_89 = & V_167 -> V_188 [ V_167 -> V_385 ] ;
if ( F_36 ( & V_89 -> V_44 ) !=
V_184 ) {
F_254 ( V_167 , V_533 ,
V_465 ) ;
F_30 ( & V_167 -> V_44 ,
V_388 ) ;
return - V_532 ;
}
}
}
V_30 = F_275 ( V_167 , V_89 , V_171 , V_72 , - 1 , 0 ) ;
V_167 -> V_385 = ( V_167 -> V_385 + V_30 ) %
V_187 ;
V_465 += V_30 ;
if ( V_465 )
F_254 ( V_167 , V_533 , V_465 ) ;
else if ( ! F_36 ( & V_167 -> V_175 ) )
F_91 ( & V_167 -> V_44 , V_482 ) ;
while ( F_279 ( & V_167 -> V_44 ) ) {
V_465 = 0 ;
V_533 = V_167 -> V_385 ;
V_465 += F_252 ( V_167 ) ;
if ( ! V_465 && ! F_36 ( & V_167 -> V_175 ) )
V_465 += F_253 ( V_167 ) ;
if ( V_465 )
F_254 ( V_167 , V_533 , V_465 ) ;
}
if ( V_167 -> V_2 -> V_205 . V_216 && V_386 )
V_167 -> V_2 -> V_378 . V_483 += V_465 ;
return V_26 ;
}
static int F_280 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
struct V_417 * V_534 ;
F_11 ( V_2 , 4 , L_218 ) ;
V_69 = (struct V_68 * ) V_56 ;
V_534 = & ( V_69 -> V_56 . V_404 ) ;
F_231 ( V_2 , V_64 , ( unsigned long ) V_69 ) ;
if ( V_69 -> V_72 . V_78 ) {
F_56 ( V_2 , 4 , L_219 , V_69 -> V_72 . V_78 ) ;
V_534 -> V_56 . V_535 = V_536 ;
}
V_2 -> V_3 . V_537 = V_534 -> V_56 . V_535 ;
return 0 ;
}
void F_281 ( struct V_1 * V_2 )
{
enum V_538 V_535 ;
struct V_539 * V_55 = V_2 -> V_55 ;
struct V_49 * V_50 ;
struct V_68 * V_69 ;
F_11 ( V_2 , 4 , L_220 ) ;
if ( ( ( V_55 -> V_21 & V_540 ) &&
( V_2 -> V_3 . V_537 == V_541 ) ) ||
( ! ( V_55 -> V_21 & V_540 ) &&
( V_2 -> V_3 . V_537 == V_536 ) ) )
return;
V_535 = V_536 ;
if ( V_55 -> V_21 & V_540 )
V_535 = V_541 ;
F_56 ( V_2 , 4 , L_221 , V_535 ) ;
V_50 = F_233 ( V_2 , V_542 ,
sizeof( struct V_417 ) ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
V_69 -> V_56 . V_404 . V_56 . V_535 = V_535 ;
F_229 ( V_2 , V_50 , F_280 , NULL ) ;
}
int F_282 ( struct V_539 * V_55 , int V_543 )
{
struct V_1 * V_2 ;
char V_372 [ 15 ] ;
V_2 = V_55 -> V_544 ;
F_11 ( V_2 , 4 , L_222 ) ;
sprintf ( V_372 , L_223 , V_543 ) ;
F_11 ( V_2 , 4 , V_372 ) ;
if ( V_543 < 64 )
return - V_343 ;
if ( V_543 > 65535 )
return - V_343 ;
if ( ( ! F_283 ( V_2 , V_545 ) ) &&
( ! F_171 ( V_2 , V_543 ) ) )
return - V_343 ;
V_55 -> V_341 = V_543 ;
return 0 ;
}
struct V_546 * F_284 ( struct V_539 * V_55 )
{
struct V_1 * V_2 ;
V_2 = V_55 -> V_544 ;
F_11 ( V_2 , 5 , L_224 ) ;
return & V_2 -> V_451 ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
F_11 ( V_2 , 4 , L_225 ) ;
V_69 = (struct V_68 * ) V_56 ;
if ( ! V_2 -> V_205 . V_247 ||
! ( V_2 -> V_3 . V_547 & V_548 ) ) {
memcpy ( V_2 -> V_55 -> V_549 ,
& V_69 -> V_56 . V_404 . V_56 . V_550 . V_178 ,
V_551 ) ;
V_2 -> V_3 . V_547 |= V_548 ;
}
F_231 ( V_2 , V_64 , ( unsigned long ) V_69 ) ;
return 0 ;
}
int F_286 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_49 * V_50 ;
struct V_68 * V_69 ;
F_11 ( V_2 , 4 , L_226 ) ;
V_50 = F_233 ( V_2 , V_552 ,
sizeof( struct V_417 ) ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
V_69 -> V_56 . V_404 . V_56 . V_550 . V_69 = V_553 ;
V_69 -> V_56 . V_404 . V_56 . V_550 . V_554 = V_551 ;
memcpy ( & V_69 -> V_56 . V_404 . V_56 . V_550 . V_178 ,
V_2 -> V_55 -> V_549 , V_551 ) ;
V_26 = F_229 ( V_2 , V_50 , F_285 ,
NULL ) ;
return V_26 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_56 )
{
struct V_68 * V_69 ;
struct V_555 * V_556 ;
F_11 ( V_2 , 4 , L_227 ) ;
V_69 = (struct V_68 * ) V_56 ;
V_556 = & V_69 -> V_56 . V_404 . V_56 . V_557 ;
F_95 ( V_122 , 2 , L_227 ) ;
F_95 ( V_122 , 2 , L_173 , V_2 -> V_54 -> V_55 . V_558 . V_440 ) ;
F_95 ( V_122 , 2 , L_228 ,
V_69 -> V_56 . V_404 . V_72 . V_78 ) ;
switch ( V_69 -> V_56 . V_404 . V_72 . V_78 ) {
case V_559 :
case V_560 :
case V_561 :
{
V_2 -> V_205 . V_219 = V_556 -> V_562 ;
if ( V_2 -> V_205 . V_219 == V_220 ) {
F_50 ( & V_2 -> V_54 -> V_55 ,
L_229 ) ;
} else {
F_50 ( & V_2 -> V_54 -> V_55 ,
L_230 ) ;
}
F_26 ( 3 , L_231 ,
V_2 -> V_54 -> V_55 . V_558 . V_440 ,
V_556 -> V_562 ,
V_69 -> V_56 . V_404 . V_72 . V_78 ) ;
break;
}
case V_563 :
{
F_26 ( 3 , L_232 ,
V_2 -> V_54 -> V_55 . V_558 . V_440 ,
V_556 -> V_562 ,
V_69 -> V_56 . V_404 . V_72 . V_78 ) ;
F_57 ( & V_2 -> V_54 -> V_55 , L_233
L_234 ) ;
V_2 -> V_205 . V_219 = V_220 ;
break;
}
case V_564 :
{
F_26 ( 3 , L_235 ,
V_2 -> V_54 -> V_55 . V_558 . V_440 ,
V_556 -> V_562 ,
V_69 -> V_56 . V_404 . V_72 . V_78 ) ;
F_57 ( & V_2 -> V_54 -> V_55 ,
L_236
L_237 ) ;
V_2 -> V_205 . V_219 = V_220 ;
break;
}
case V_565 :
{
F_26 ( 3 , L_235 ,
V_2 -> V_54 -> V_55 . V_558 . V_440 ,
V_556 -> V_562 ,
V_69 -> V_56 . V_404 . V_72 . V_78 ) ;
F_57 ( & V_2 -> V_54 -> V_55 ,
L_238 ) ;
V_2 -> V_205 . V_219 = V_220 ;
break;
}
default:
{
F_26 ( 3 , L_239
L_240 ,
V_2 -> V_54 -> V_55 . V_558 . V_440 ,
V_556 -> V_562 ,
V_69 -> V_56 . V_404 . V_72 . V_78 ) ;
V_2 -> V_205 . V_219 = V_220 ;
break;
}
}
F_231 ( V_2 , V_64 , ( unsigned long ) V_69 ) ;
return 0 ;
}
static int F_288 ( struct V_1 * V_2 ,
enum V_566 V_219 )
{
int V_26 ;
struct V_49 * V_50 ;
struct V_68 * V_69 ;
struct V_555 * V_556 ;
F_11 ( V_2 , 4 , L_241 ) ;
F_95 ( V_122 , 2 , L_241 ) ;
F_95 ( V_122 , 2 , L_173 , V_2 -> V_54 -> V_55 . V_558 . V_440 ) ;
V_50 = F_233 ( V_2 , V_567 ,
sizeof( struct V_568 ) +
sizeof( struct V_555 ) ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
V_556 = & V_69 -> V_56 . V_404 . V_56 . V_557 ;
V_556 -> V_562 = V_219 ;
V_26 = F_229 ( V_2 , V_50 , F_287 ,
NULL ) ;
F_95 ( V_122 , 2 , L_228 , V_26 ) ;
return V_26 ;
}
int F_289 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
F_11 ( V_2 , 4 , L_242 ) ;
if ( ( V_2 -> V_3 . type == V_5 ||
V_2 -> V_3 . type == V_8 ) &&
F_290 ( V_2 , V_567 ) ) {
V_26 = F_288 ( V_2 ,
V_2 -> V_205 . V_219 ) ;
if ( V_26 ) {
F_26 ( 3 ,
L_243 ,
V_2 -> V_54 -> V_55 . V_558 . V_440 ,
V_26 ) ;
}
} else if ( V_2 -> V_205 . V_219 != V_220 ) {
V_2 -> V_205 . V_219 = V_220 ;
F_57 ( & V_2 -> V_54 -> V_55 , L_233
L_234 ) ;
V_26 = - V_280 ;
}
return V_26 ;
}
void F_291 ( struct V_539 * V_55 )
{
struct V_1 * V_2 ;
V_2 = V_55 -> V_544 ;
F_11 ( V_2 , 4 , L_244 ) ;
V_2 -> V_451 . V_477 ++ ;
F_31 ( V_2 ) ;
}
int F_292 ( struct V_539 * V_55 , int V_569 , int V_570 )
{
struct V_1 * V_2 = V_55 -> V_544 ;
int V_26 = 0 ;
switch ( V_570 ) {
case V_571 :
V_26 = V_572 ;
if ( ( V_2 -> V_3 . V_10 != V_13 ) &&
( V_2 -> V_3 . V_10 != V_573 ) &&
( V_2 -> V_3 . V_10 != V_14 ) )
V_26 |= V_574 ;
break;
case V_575 :
V_26 = V_576 | V_577 | V_578 |
V_579 | V_580 | V_581 | V_582 |
V_583 ;
break;
case V_584 :
V_26 = ( V_55 -> V_549 [ 0 ] << 16 ) | ( V_55 -> V_549 [ 1 ] << 8 ) |
V_55 -> V_549 [ 2 ] ;
V_26 = ( V_26 >> 5 ) & 0xFFFF ;
break;
case V_585 :
V_26 = ( V_55 -> V_549 [ 2 ] << 10 ) & 0xFFFF ;
break;
case V_586 :
V_26 = V_587 ;
break;
case V_588 :
V_26 = V_589 | V_590 | V_591 | V_592 |
V_593 | V_594 ;
break;
case V_595 :
break;
case V_596 :
break;
case V_597 :
break;
case V_598 :
break;
case V_599 :
V_26 = V_2 -> V_451 . V_600 ;
break;
case V_601 :
break;
case V_602 :
break;
case V_603 :
break;
case V_604 :
break;
case V_605 :
break;
case V_606 :
break;
case V_607 :
break;
default:
break;
}
return V_26 ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_49 * V_50 , int V_94 ,
int (* F_154)( struct V_1 * , struct V_63 * ,
unsigned long ) ,
void * V_321 )
{
V_118 V_608 , V_609 ;
F_11 ( V_2 , 4 , L_245 ) ;
memcpy ( V_50 -> V_56 , V_402 , V_328 ) ;
memcpy ( F_228 ( V_50 -> V_56 ) ,
& V_2 -> V_294 . V_354 , V_310 ) ;
V_608 = ( V_610 ) V_328 + V_94 ;
V_609 = ( V_610 ) V_94 ;
memcpy ( F_294 ( V_50 -> V_56 ) , & V_608 , 2 ) ;
memcpy ( F_295 ( V_50 -> V_56 ) , & V_609 , 2 ) ;
memcpy ( F_296 ( V_50 -> V_56 ) , & V_609 , 2 ) ;
memcpy ( F_297 ( V_50 -> V_56 ) , & V_609 , 2 ) ;
return F_153 ( V_2 , V_328 + V_94 , V_50 ,
F_154 , V_321 ) ;
}
static int F_298 ( struct V_1 * V_2 ,
struct V_63 * V_64 , unsigned long V_611 )
{
struct V_68 * V_69 ;
struct V_612 * V_613 ;
struct V_614 * V_615 ;
unsigned char * V_56 ;
V_117 V_504 ;
F_11 ( V_2 , 3 , L_246 ) ;
V_69 = (struct V_68 * ) V_611 ;
V_56 = ( unsigned char * ) ( ( char * ) V_69 - V_64 -> V_116 ) ;
V_613 = (struct V_612 * ) V_64 -> V_324 ;
V_615 = & V_69 -> V_56 . V_404 . V_56 . V_615 ;
if ( V_69 -> V_72 . V_78 ) {
F_56 ( V_2 , 4 , L_247 , V_69 -> V_72 . V_78 ) ;
return 0 ;
}
if ( V_69 -> V_56 . V_404 . V_72 . V_78 ) {
V_69 -> V_72 . V_78 =
V_69 -> V_56 . V_404 . V_72 . V_78 ;
F_56 ( V_2 , 4 , L_248 , V_69 -> V_72 . V_78 ) ;
return 0 ;
}
V_504 = * ( ( V_117 * ) F_295 ( V_56 ) ) ;
if ( V_69 -> V_56 . V_404 . V_72 . V_415 == 1 )
V_504 -= ( V_117 ) ( ( char * ) & V_615 -> V_56 - ( char * ) V_69 ) ;
else
V_504 -= ( V_117 ) ( ( char * ) & V_615 -> V_616 - ( char * ) V_69 ) ;
if ( ( V_613 -> V_617 - V_613 -> V_618 ) < V_504 ) {
F_56 ( V_2 , 4 , L_249 , - V_39 ) ;
V_69 -> V_72 . V_78 = - V_39 ;
return 0 ;
}
F_56 ( V_2 , 4 , L_250 ,
V_69 -> V_56 . V_404 . V_72 . V_414 ) ;
F_56 ( V_2 , 4 , L_251 ,
V_69 -> V_56 . V_404 . V_72 . V_415 ) ;
if ( V_69 -> V_56 . V_404 . V_72 . V_415 == 1 ) {
memcpy ( V_613 -> V_619 + V_613 -> V_618 ,
( char * ) V_615 ,
V_504 + F_299 ( struct V_614 , V_56 ) ) ;
V_613 -> V_618 += F_299 ( struct V_614 , V_56 ) ;
} else {
memcpy ( V_613 -> V_619 + V_613 -> V_618 ,
( char * ) & V_615 -> V_616 , V_504 ) ;
}
V_613 -> V_618 += V_504 ;
F_56 ( V_2 , 4 , L_252 ,
V_69 -> V_56 . V_404 . V_72 . V_414 ) ;
F_56 ( V_2 , 4 , L_253 ,
V_69 -> V_56 . V_404 . V_72 . V_415 ) ;
if ( V_69 -> V_56 . V_404 . V_72 . V_415 <
V_69 -> V_56 . V_404 . V_72 . V_414 )
return 1 ;
return 0 ;
}
int F_300 ( struct V_1 * V_2 , char T_4 * V_619 )
{
struct V_49 * V_50 ;
struct V_68 * V_69 ;
struct V_620 * V_621 ;
int V_622 ;
struct V_612 V_613 = { 0 , } ;
int V_26 = 0 ;
F_11 ( V_2 , 3 , L_254 ) ;
if ( V_2 -> V_3 . V_4 )
return - V_280 ;
if ( ( ! F_290 ( V_2 , V_623 ) ) &&
( ! V_2 -> V_205 . V_247 ) ) {
return - V_280 ;
}
if ( F_301 ( & V_622 , V_619 + sizeof( int ) , sizeof( int ) ) )
return - V_624 ;
V_621 = F_302 ( V_619 , V_622 + sizeof( struct V_625 ) ) ;
if ( F_80 ( V_621 ) ) {
F_11 ( V_2 , 2 , L_255 ) ;
return F_81 ( V_621 ) ;
}
V_613 . V_617 = V_621 -> V_72 . V_504 ;
V_613 . V_619 = F_33 ( V_613 . V_617 , V_38 ) ;
if ( ! V_613 . V_619 ) {
F_20 ( V_621 ) ;
return - V_39 ;
}
V_613 . V_618 = sizeof( struct V_625 ) ;
V_50 = F_233 ( V_2 , V_623 ,
V_626 + V_622 ) ;
V_69 = (struct V_68 * ) ( V_50 -> V_56 + V_328 ) ;
memcpy ( & V_69 -> V_56 . V_404 . V_56 . V_615 , & V_621 -> V_69 , V_622 ) ;
V_26 = F_293 ( V_2 , V_50 , V_627 + V_622 ,
F_298 , ( void * ) & V_613 ) ;
if ( V_26 )
F_26 ( 2 , L_256 ,
F_42 ( V_2 ) , V_26 ) ;
else {
if ( F_303 ( V_619 , V_613 . V_619 , V_613 . V_617 ) )
V_26 = - V_624 ;
}
F_20 ( V_621 ) ;
F_20 ( V_613 . V_619 ) ;
return V_26 ;
}
static inline int F_304 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . type ) {
case V_6 :
return 2 ;
default:
return 0 ;
}
}
static void F_305 ( struct V_1 * V_2 )
{
int V_26 ;
int V_181 ;
char * V_286 ;
struct V_127 * V_628 ;
int V_629 = 0 ;
F_68 ( V_122 , 2 , L_257 ) ;
V_628 = F_125 ( V_2 ) ;
if ( ! V_628 -> V_630 ) {
V_629 = 1 ;
V_26 = F_306 ( V_628 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_124 , V_26 ) ;
goto V_111;
}
}
V_26 = F_127 ( V_2 , ( void * * ) & V_286 , & V_181 ) ;
if ( V_26 ) {
F_26 ( 2 , L_258 ,
F_27 ( & V_2 -> V_54 -> V_55 ) , V_26 ) ;
F_95 ( V_122 , 2 , L_169 , V_26 ) ;
goto V_631;
}
F_130 ( V_2 , V_286 ) ;
F_131 ( V_2 , V_286 ) ;
F_20 ( V_286 ) ;
V_26 = F_307 ( V_628 , & V_2 -> V_632 ) ;
if ( V_26 )
F_95 ( V_122 , 2 , L_170 , V_26 ) ;
V_631:
if ( V_629 == 1 )
F_308 ( V_628 ) ;
V_111:
return;
}
static int F_205 ( struct V_1 * V_2 )
{
struct V_633 V_634 ;
char * V_635 ;
struct V_382 * * V_636 ;
struct V_382 * * V_637 ;
int V_33 , V_34 , V_638 ;
int V_26 = 0 ;
F_68 ( V_122 , 2 , L_259 ) ;
V_635 = F_33 ( V_187 * sizeof( char ) ,
V_38 ) ;
if ( ! V_635 )
return - V_39 ;
F_194 ( V_2 , V_635 ) ;
F_198 ( V_2 , V_635 ) ;
V_636 = F_15 ( V_187 * sizeof( void * ) ,
V_38 ) ;
if ( ! V_636 ) {
F_20 ( V_635 ) ;
return - V_39 ;
}
for ( V_33 = 0 ; V_33 < V_187 ; ++ V_33 )
V_636 [ V_33 ] = (struct V_382 * )
F_309 ( V_2 -> V_35 . V_190 -> V_188 [ V_33 ] . V_89 ) ;
V_637 =
F_15 ( V_2 -> V_35 . V_185 * V_187 *
sizeof( void * ) , V_38 ) ;
if ( ! V_637 ) {
F_20 ( V_636 ) ;
F_20 ( V_635 ) ;
return - V_39 ;
}
for ( V_33 = 0 , V_638 = 0 ; V_33 < V_2 -> V_35 . V_185 ; ++ V_33 )
for ( V_34 = 0 ; V_34 < V_187 ; ++ V_34 , ++ V_638 ) {
V_637 [ V_638 ] = (struct V_382 * ) F_309 (
V_2 -> V_35 . V_186 [ V_33 ] -> V_188 [ V_34 ] . V_89 ) ;
}
memset ( & V_634 , 0 , sizeof( struct V_633 ) ) ;
V_634 . V_128 = F_125 ( V_2 ) ;
V_634 . V_639 = F_304 ( V_2 ) ;
V_634 . V_640 = 0 ;
V_634 . V_635 = V_635 ;
V_634 . V_641 = 1 ;
V_634 . V_642 = V_2 -> V_35 . V_185 ;
V_634 . V_643 = V_2 -> V_223 . V_643 ;
V_634 . V_644 = V_2 -> V_223 . V_644 ;
V_634 . V_645 = V_2 -> V_223 . V_646 ;
V_634 . V_647 = ( unsigned long ) V_2 ;
V_634 . V_648 = ( void * * ) V_636 ;
V_634 . V_649 = ( void * * ) V_637 ;
V_634 . V_650 =
( V_2 -> V_3 . type == V_6 ) ? 8 : 32 ;
if ( F_123 ( & V_2 -> V_35 . V_44 , V_275 ,
V_271 ) == V_275 ) {
V_26 = F_310 ( & V_634 ) ;
if ( V_26 ) {
F_30 ( & V_2 -> V_35 . V_44 , V_275 ) ;
goto V_111;
}
V_26 = F_311 ( & V_634 ) ;
if ( V_26 ) {
F_30 ( & V_2 -> V_35 . V_44 , V_275 ) ;
F_126 ( F_125 ( V_2 ) ) ;
}
}
V_111:
F_20 ( V_637 ) ;
F_20 ( V_636 ) ;
F_20 ( V_635 ) ;
return V_26 ;
}
static void F_312 ( struct V_1 * V_2 )
{
F_68 ( V_122 , 2 , L_260 ) ;
F_55 ( V_122 , 2 , & V_2 , sizeof( void * ) ) ;
F_92 ( & V_2 -> V_51 ) ;
F_92 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_55 )
F_313 ( V_2 -> V_55 ) ;
F_20 ( V_2 -> V_231 ) ;
F_90 ( V_2 ) ;
F_314 ( & V_2 -> V_241 ) ;
F_20 ( V_2 ) ;
}
static int F_315 ( const char * V_169 , struct V_651 * V_652 ,
unsigned long V_653 )
{
return F_316 ( V_652 , V_653 ,
& V_654 , 3 , V_169 ) ;
}
int F_317 ( struct V_1 * V_2 )
{
int V_655 = 0 ;
int V_26 ;
F_68 ( V_122 , 2 , L_261 ) ;
F_30 ( & V_2 -> V_454 , 0 ) ;
F_93 ( V_2 ) ;
V_656:
if ( V_655 )
F_26 ( 2 , L_262 ,
F_27 ( & V_2 -> V_54 -> V_55 ) ) ;
F_308 ( F_125 ( V_2 ) ) ;
F_308 ( F_318 ( V_2 ) ) ;
F_308 ( F_112 ( V_2 ) ) ;
V_26 = F_306 ( F_112 ( V_2 ) ) ;
if ( V_26 )
goto V_657;
V_26 = F_306 ( F_318 ( V_2 ) ) ;
if ( V_26 )
goto V_657;
V_26 = F_306 ( F_125 ( V_2 ) ) ;
if ( V_26 )
goto V_657;
V_26 = F_122 ( V_2 , V_2 -> V_3 . type != V_6 ) ;
V_657:
if ( V_26 == - V_264 ) {
F_68 ( V_122 , 2 , L_263 ) ;
return V_26 ;
} else if ( V_26 ) {
F_95 ( V_122 , 2 , L_118 , V_26 ) ;
if ( ++ V_655 > 3 )
goto V_111;
else
goto V_656;
}
F_305 ( V_2 ) ;
F_132 ( V_2 ) ;
F_133 ( V_2 ) ;
V_26 = F_136 ( & V_2 -> V_51 , F_148 ) ;
if ( V_26 == - V_264 ) {
F_68 ( V_122 , 2 , L_264 ) ;
return V_26 ;
} else if ( V_26 ) {
F_95 ( V_122 , 2 , L_124 , V_26 ) ;
if ( -- V_655 < 0 )
goto V_111;
else
goto V_656;
}
V_26 = F_136 ( & V_2 -> V_88 , F_145 ) ;
if ( V_26 == - V_264 ) {
F_68 ( V_122 , 2 , L_265 ) ;
return V_26 ;
} else if ( V_26 ) {
F_95 ( V_122 , 2 , L_168 , V_26 ) ;
if ( -- V_655 < 0 )
goto V_111;
else
goto V_656;
}
V_2 -> V_62 = 0 ;
V_26 = F_204 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_169 , V_26 ) ;
goto V_111;
}
V_2 -> V_205 . V_418 . V_408 = 0 ;
V_2 -> V_205 . V_407 . V_408 = 0 ;
V_2 -> V_3 . V_422 = 0 ;
F_236 ( V_2 , V_331 ) ;
if ( F_283 ( V_2 , V_658 ) )
F_234 ( V_2 ) ;
if ( F_290 ( V_2 , V_659 ) )
F_238 ( V_2 ) ;
return 0 ;
V_111:
F_25 ( & V_2 -> V_54 -> V_55 , L_90
L_91 ) ;
F_26 ( 2 , L_266 ,
F_27 ( & V_2 -> V_54 -> V_55 ) , V_26 ) ;
return V_26 ;
}
static inline int F_319 ( struct V_660 * V_172 ,
struct V_170 * * V_661 , int V_116 , int * V_662 , int V_504 )
{
struct V_376 * V_376 = F_217 ( V_172 -> V_178 ) ;
if ( * V_661 == NULL ) {
* V_661 = F_320 ( 64 + V_663 ) ;
if ( ! ( * V_661 ) )
return - V_39 ;
F_321 ( * V_661 , V_663 ) ;
if ( V_504 <= 64 ) {
memcpy ( F_322 ( * V_661 , V_504 ) , V_172 -> V_178 + V_116 ,
V_504 ) ;
} else {
F_323 ( V_376 ) ;
memcpy ( F_322 ( * V_661 , 64 ) , V_172 -> V_178 + V_116 , 64 ) ;
F_324 ( * V_661 , * V_662 , V_376 , V_116 + 64 ,
V_504 - 64 ) ;
( * V_661 ) -> V_504 += V_504 - 64 ;
( * V_661 ) -> V_94 += V_504 - 64 ;
( * V_661 ) -> V_664 += V_504 - 64 ;
( * V_662 ) ++ ;
}
} else {
F_323 ( V_376 ) ;
F_324 ( * V_661 , * V_662 , V_376 , V_116 , V_504 ) ;
( * V_661 ) -> V_504 += V_504 ;
( * V_661 ) -> V_94 += V_504 ;
( * V_661 ) -> V_664 += V_504 ;
( * V_662 ) ++ ;
}
return 0 ;
}
struct V_170 * F_325 ( struct V_1 * V_2 ,
struct V_382 * V_89 ,
struct V_660 * * V_665 , int * V_666 ,
struct V_522 * * V_72 )
{
struct V_660 * V_172 = * V_665 ;
int V_116 = * V_666 ;
struct V_170 * V_171 = NULL ;
int V_667 = 0 ;
void * V_668 ;
int V_504 ;
int V_669 = 0 ;
int V_670 = 0 ;
int V_515 = 0 ;
if ( V_172 -> V_181 < V_116 + sizeof( struct V_522 ) ) {
if ( F_326 ( V_172 ) )
return NULL ;
V_172 ++ ;
V_116 = 0 ;
if ( V_172 -> V_181 < sizeof( struct V_522 ) )
return NULL ;
}
* V_72 = V_172 -> V_178 + V_116 ;
V_116 += sizeof( struct V_522 ) ;
switch ( ( * V_72 ) -> V_72 . V_671 . V_254 ) {
case V_672 :
V_667 = ( * V_72 ) -> V_72 . V_671 . V_673 ;
break;
case V_674 :
V_667 = ( * V_72 ) -> V_72 . V_526 . V_181 ;
if ( ( V_2 -> V_3 . V_10 == V_16 ) ||
( V_2 -> V_3 . V_10 == V_12 ) )
V_669 = V_675 ;
else
V_669 = V_663 ;
break;
case V_676 :
V_667 = ( * V_72 ) -> V_72 . V_677 . V_678 ;
V_669 = sizeof( struct V_522 ) ;
break;
default:
break;
}
if ( ! V_667 )
return NULL ;
if ( ( V_667 >= V_2 -> V_205 . V_217 ) &&
( ! ( V_2 -> V_3 . type == V_9 ) ) &&
( ! F_36 ( & V_2 -> V_454 ) ) ) {
V_670 = 1 ;
} else {
V_171 = F_320 ( V_667 + V_669 ) ;
if ( ! V_171 )
goto V_679;
if ( V_669 )
F_321 ( V_171 , V_669 ) ;
}
V_668 = V_172 -> V_178 + V_116 ;
while ( V_667 ) {
V_504 = F_327 ( V_667 , ( int ) ( V_172 -> V_181 - V_116 ) ) ;
if ( V_504 ) {
if ( V_670 ) {
if ( F_319 ( V_172 , & V_171 , V_116 ,
& V_515 , V_504 ) )
goto V_679;
} else {
memcpy ( F_322 ( V_171 , V_504 ) , V_668 ,
V_504 ) ;
}
}
V_667 -= V_504 ;
if ( V_667 ) {
if ( F_326 ( V_172 ) ) {
F_11 ( V_2 , 4 , L_267 ) ;
F_328 ( V_2 , 2 , V_89 , sizeof( void * ) ) ;
F_87 ( V_171 ) ;
V_2 -> V_451 . V_600 ++ ;
return NULL ;
}
V_172 ++ ;
V_116 = 0 ;
V_668 = V_172 -> V_178 ;
} else {
V_116 += V_504 ;
}
}
* V_665 = V_172 ;
* V_666 = V_116 ;
if ( V_670 && V_2 -> V_205 . V_216 ) {
V_2 -> V_378 . V_680 ++ ;
V_2 -> V_378 . V_681 += F_270 ( V_171 ) -> V_506 ;
}
return V_171 ;
V_679:
if ( F_329 () ) {
F_11 ( V_2 , 2 , L_268 ) ;
}
V_2 -> V_451 . V_452 ++ ;
return NULL ;
}
static void F_330 ( void )
{
int V_682 ;
for ( V_682 = 0 ; V_682 < V_683 ; V_682 ++ ) {
F_331 ( V_684 [ V_682 ] . V_254 ) ;
V_684 [ V_682 ] . V_254 = NULL ;
}
}
void F_332 ( T_5 * V_254 , int V_313 , char * V_685 , ... )
{
char V_686 [ 32 ] ;
T_6 args ;
if ( V_313 > V_254 -> V_313 )
return;
va_start ( args , V_685 ) ;
vsnprintf ( V_686 , sizeof( V_686 ) , V_685 , args ) ;
va_end ( args ) ;
F_333 ( V_254 , V_313 , V_686 ) ;
}
static int F_334 ( void )
{
int V_278 ;
int V_682 ;
for ( V_682 = 0 ; V_682 < V_683 ; V_682 ++ ) {
V_684 [ V_682 ] . V_254 = F_335 ( V_684 [ V_682 ] . V_440 ,
V_684 [ V_682 ] . V_687 ,
V_684 [ V_682 ] . V_688 ,
V_684 [ V_682 ] . V_94 ) ;
if ( V_684 [ V_682 ] . V_254 == NULL ) {
F_330 () ;
return - V_39 ;
}
V_278 = F_336 ( V_684 [ V_682 ] . V_254 , V_684 [ V_682 ] . V_689 ) ;
if ( V_278 ) {
F_330 () ;
return V_278 ;
}
F_337 ( V_684 [ V_682 ] . V_254 , V_684 [ V_682 ] . V_313 ) ;
}
return 0 ;
}
int F_338 ( struct V_1 * V_2 ,
enum V_690 V_223 )
{
int V_26 = 0 ;
switch ( V_223 ) {
case V_691 :
V_2 -> V_223 . V_692 = F_339 (
F_340 ( V_693 ) ,
L_269 ) ;
break;
case V_694 :
V_2 -> V_223 . V_692 = F_339 (
F_340 ( V_695 ) ,
L_270 ) ;
break;
}
if ( ! V_2 -> V_223 . V_692 ) {
F_57 ( & V_2 -> V_54 -> V_55 , L_271
L_272 , V_223 ) ;
V_26 = - V_343 ;
}
return V_26 ;
}
void F_341 ( struct V_1 * V_2 )
{
if ( V_2 -> V_205 . V_247 )
F_342 ( V_695 ) ;
else
F_342 ( V_693 ) ;
V_2 -> V_223 . V_692 = NULL ;
}
static int F_343 ( struct V_696 * V_54 )
{
struct V_1 * V_2 ;
struct V_651 * V_55 ;
int V_26 ;
unsigned long V_21 ;
char V_697 [ 20 ] ;
F_68 ( V_122 , 2 , L_273 ) ;
V_55 = & V_54 -> V_55 ;
if ( ! F_344 ( V_55 ) )
return - V_698 ;
F_95 ( V_122 , 2 , L_173 , F_27 ( & V_54 -> V_55 ) ) ;
V_2 = F_109 () ;
if ( ! V_2 ) {
F_95 ( V_122 , 2 , L_118 , - V_39 ) ;
V_26 = - V_39 ;
goto V_699;
}
snprintf ( V_697 , sizeof( V_697 ) , L_274 ,
F_27 ( & V_54 -> V_55 ) ) ;
V_2 -> V_700 = F_335 ( V_697 , 2 , 1 , 8 ) ;
if ( ! V_2 -> V_700 ) {
F_95 ( V_122 , 2 , L_173 , L_275 ) ;
V_26 = - V_39 ;
goto V_701;
}
F_336 ( V_2 -> V_700 , & V_702 ) ;
V_2 -> V_51 . V_58 = V_54 -> V_128 [ 0 ] ;
V_2 -> V_88 . V_58 = V_54 -> V_128 [ 1 ] ;
V_2 -> V_56 . V_58 = V_54 -> V_128 [ 2 ] ;
F_345 ( & V_54 -> V_55 , V_2 ) ;
V_2 -> V_54 = V_54 ;
V_54 -> V_128 [ 0 ] -> V_703 = F_82 ;
V_54 -> V_128 [ 1 ] -> V_703 = F_82 ;
V_54 -> V_128 [ 2 ] -> V_703 = F_82 ;
V_26 = F_111 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_124 , V_26 ) ;
goto V_704;
}
V_26 = F_103 ( V_2 ) ;
if ( V_26 ) {
F_95 ( V_122 , 2 , L_119 , V_26 ) ;
goto V_704;
}
if ( V_2 -> V_3 . type == V_9 )
V_26 = F_346 ( V_55 ) ;
else
V_26 = F_347 ( V_55 ) ;
if ( V_26 )
goto V_704;
switch ( V_2 -> V_3 . type ) {
case V_9 :
case V_7 :
V_26 = F_338 ( V_2 , V_694 ) ;
if ( V_26 )
goto V_705;
V_26 = V_2 -> V_223 . V_692 -> V_706 ( V_2 -> V_54 ) ;
if ( V_26 )
goto V_707;
case V_5 :
case V_8 :
default:
break;
}
F_348 ( & V_708 . V_709 , V_21 ) ;
F_65 ( & V_2 -> V_31 , & V_708 . V_31 ) ;
F_349 ( & V_708 . V_709 , V_21 ) ;
F_305 ( V_2 ) ;
return 0 ;
V_707:
F_341 ( V_2 ) ;
V_705:
if ( V_2 -> V_3 . type == V_9 )
F_350 ( V_55 ) ;
else
F_351 ( V_55 ) ;
V_704:
F_331 ( V_2 -> V_700 ) ;
V_701:
F_312 ( V_2 ) ;
V_699:
F_352 ( V_55 ) ;
return V_26 ;
}
static void F_353 ( struct V_696 * V_54 )
{
unsigned long V_21 ;
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
F_68 ( V_122 , 2 , L_276 ) ;
if ( V_2 -> V_3 . type == V_9 ) {
F_350 ( & V_54 -> V_55 ) ;
} else {
F_351 ( & V_54 -> V_55 ) ;
}
if ( V_2 -> V_223 . V_692 ) {
V_2 -> V_223 . V_692 -> remove ( V_54 ) ;
F_341 ( V_2 ) ;
}
F_331 ( V_2 -> V_700 ) ;
F_348 ( & V_708 . V_709 , V_21 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_349 ( & V_708 . V_709 , V_21 ) ;
F_312 ( V_2 ) ;
F_345 ( & V_54 -> V_55 , NULL ) ;
F_352 ( & V_54 -> V_55 ) ;
return;
}
static int F_355 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
int V_26 = 0 ;
int V_710 ;
if ( ! V_2 -> V_223 . V_692 ) {
if ( V_2 -> V_3 . type == V_6 )
V_710 = V_691 ;
else
V_710 = V_694 ;
V_26 = F_338 ( V_2 , V_710 ) ;
if ( V_26 )
goto V_711;
V_26 = V_2 -> V_223 . V_692 -> V_706 ( V_2 -> V_54 ) ;
if ( V_26 )
goto V_711;
}
V_26 = V_2 -> V_223 . V_692 -> V_712 ( V_54 ) ;
V_711:
return V_26 ;
}
static int F_356 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
return V_2 -> V_223 . V_692 -> V_713 ( V_54 ) ;
}
static void F_357 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
if ( V_2 -> V_223 . V_692 &&
V_2 -> V_223 . V_692 -> V_714 )
V_2 -> V_223 . V_692 -> V_714 ( V_54 ) ;
}
static int F_358 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
if ( V_2 -> V_223 . V_692 &&
V_2 -> V_223 . V_692 -> V_715 )
return V_2 -> V_223 . V_692 -> V_715 ( V_54 ) ;
return 0 ;
}
static void F_359 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
if ( V_2 -> V_223 . V_692 &&
V_2 -> V_223 . V_692 -> V_716 )
V_2 -> V_223 . V_692 -> V_716 ( V_54 ) ;
}
static int F_360 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
if ( V_2 -> V_223 . V_692 &&
V_2 -> V_223 . V_692 -> V_717 )
return V_2 -> V_223 . V_692 -> V_717 ( V_54 ) ;
return 0 ;
}
static int F_361 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
if ( V_2 -> V_223 . V_692 &&
V_2 -> V_223 . V_692 -> V_718 )
return V_2 -> V_223 . V_692 -> V_718 ( V_54 ) ;
return 0 ;
}
static int F_362 ( struct V_696 * V_54 )
{
struct V_1 * V_2 = F_354 ( & V_54 -> V_55 ) ;
if ( V_2 -> V_223 . V_692 &&
V_2 -> V_223 . V_692 -> V_719 )
return V_2 -> V_223 . V_692 -> V_719 ( V_54 ) ;
return 0 ;
}
static T_7
F_363 ( struct V_720 * V_721 , const char * V_169 ,
T_8 V_98 )
{
int V_711 ;
V_711 = F_315 ( V_169 , V_722 ,
V_723 . V_653 ) ;
if ( V_711 )
return V_711 ;
else
return V_98 ;
}
int F_364 ( struct V_539 * V_55 , int V_724 )
{
switch ( V_724 ) {
case V_725 :
return ( sizeof( V_726 ) / V_727 ) ;
default:
return - V_343 ;
}
}
void F_365 ( struct V_539 * V_55 ,
struct V_728 * V_451 , T_9 * V_56 )
{
struct V_1 * V_2 = V_55 -> V_544 ;
V_56 [ 0 ] = V_2 -> V_451 . V_729 -
V_2 -> V_378 . V_730 ;
V_56 [ 1 ] = V_2 -> V_378 . V_731 ;
V_56 [ 2 ] = V_2 -> V_451 . V_732 -
V_2 -> V_378 . V_733 ;
V_56 [ 3 ] = V_2 -> V_378 . V_479 ;
V_56 [ 4 ] = V_2 -> V_451 . V_732 - V_2 -> V_378 . V_733
- V_2 -> V_378 . V_530 ;
V_56 [ 5 ] = V_2 -> V_378 . V_479 - V_2 -> V_378 . V_483 ;
V_56 [ 6 ] = V_2 -> V_378 . V_530 ;
V_56 [ 7 ] = V_2 -> V_378 . V_483 ;
V_56 [ 8 ] = V_2 -> V_378 . V_734 ;
V_56 [ 9 ] = V_2 -> V_378 . V_735 ;
V_56 [ 10 ] = V_2 -> V_378 . V_680 ;
V_56 [ 11 ] = V_2 -> V_378 . V_681 ;
V_56 [ 12 ] = V_2 -> V_378 . V_379 ;
V_56 [ 13 ] = ( V_2 -> V_378 . V_736 >> 10 ) ;
V_56 [ 14 ] = V_2 -> V_378 . V_737 ;
V_56 [ 15 ] = V_2 -> V_378 . V_464 ;
V_56 [ 16 ] = V_2 -> V_378 . V_467 ;
V_56 [ 17 ] = V_466 ;
V_56 [ 18 ] = V_463 ;
V_56 [ 19 ] = F_36 ( & V_2 -> V_35 . V_186 [ 0 ] -> V_387 ) ;
V_56 [ 20 ] = ( V_2 -> V_35 . V_185 > 1 ) ?
F_36 ( & V_2 -> V_35 . V_186 [ 1 ] -> V_387 ) : 0 ;
V_56 [ 21 ] = ( V_2 -> V_35 . V_185 > 2 ) ?
F_36 ( & V_2 -> V_35 . V_186 [ 2 ] -> V_387 ) : 0 ;
V_56 [ 22 ] = ( V_2 -> V_35 . V_185 > 3 ) ?
F_36 ( & V_2 -> V_35 . V_186 [ 3 ] -> V_387 ) : 0 ;
V_56 [ 23 ] = V_2 -> V_378 . V_738 ;
V_56 [ 24 ] = V_2 -> V_378 . V_739 ;
V_56 [ 25 ] = V_2 -> V_378 . V_457 ;
V_56 [ 26 ] = V_2 -> V_378 . V_455 ;
V_56 [ 27 ] = V_2 -> V_378 . V_492 ;
V_56 [ 28 ] = V_2 -> V_378 . V_490 ;
V_56 [ 29 ] = V_2 -> V_378 . V_740 ;
V_56 [ 30 ] = V_2 -> V_378 . V_741 ;
V_56 [ 31 ] = V_2 -> V_378 . V_476 ;
V_56 [ 32 ] = V_2 -> V_378 . V_472 ;
V_56 [ 33 ] = V_2 -> V_378 . V_742 ;
V_56 [ 34 ] = V_2 -> V_378 . V_743 ;
}
void F_366 ( struct V_539 * V_55 , V_610 V_724 , T_3 * V_56 )
{
switch ( V_724 ) {
case V_725 :
memcpy ( V_56 , & V_726 ,
sizeof( V_726 ) ) ;
break;
default:
F_35 ( 1 ) ;
break;
}
}
void F_367 ( struct V_539 * V_55 ,
struct V_744 * V_3 )
{
struct V_1 * V_2 = V_55 -> V_544 ;
if ( V_2 -> V_205 . V_247 )
strcpy ( V_3 -> V_745 , L_270 ) ;
else
strcpy ( V_3 -> V_745 , L_269 ) ;
strcpy ( V_3 -> V_746 , L_277 ) ;
strcpy ( V_3 -> V_747 , V_2 -> V_3 . V_242 ) ;
sprintf ( V_3 -> V_748 , L_278 ,
F_368 ( V_2 ) ,
F_369 ( V_2 ) ,
F_370 ( V_2 ) ) ;
}
int F_371 ( struct V_539 * V_749 ,
struct V_750 * V_751 )
{
struct V_1 * V_2 = V_749 -> V_544 ;
enum V_389 V_10 ;
if ( ( V_2 -> V_3 . type == V_6 ) || ( V_2 -> V_3 . V_4 ) )
V_10 = V_14 ;
else
V_10 = V_2 -> V_3 . V_10 ;
V_751 -> V_752 = V_753 ;
V_751 -> V_754 = V_755 ;
V_751 -> V_756 = V_757 ;
V_751 -> V_758 = V_759 ;
V_751 -> V_760 = V_761 ;
switch ( V_10 ) {
case V_11 :
case V_15 :
V_751 -> V_754 |= V_762 |
V_763 |
V_764 |
V_765 |
V_766 ;
V_751 -> V_756 |= V_767 |
V_768 |
V_769 |
V_770 |
V_771 ;
V_751 -> V_772 = V_773 ;
V_751 -> V_774 = V_775 ;
break;
case V_13 :
case V_17 :
V_751 -> V_754 |= V_762 |
V_763 |
V_764 |
V_765 |
V_776 |
V_777 |
V_778 ;
V_751 -> V_756 |= V_767 |
V_768 |
V_769 |
V_770 |
V_779 |
V_780 |
V_781 ;
V_751 -> V_772 = V_782 ;
V_751 -> V_774 = V_783 ;
break;
case V_14 :
V_751 -> V_754 |= V_762 |
V_763 |
V_764 |
V_765 |
V_776 |
V_777 |
V_784 |
V_778 ;
V_751 -> V_756 |= V_767 |
V_768 |
V_769 |
V_770 |
V_779 |
V_780 |
V_785 |
V_781 ;
V_751 -> V_772 = V_786 ;
V_751 -> V_774 = V_783 ;
break;
default:
V_751 -> V_754 |= V_762 |
V_763 |
V_766 ;
V_751 -> V_756 |= V_767 |
V_768 |
V_771 ;
V_751 -> V_772 = V_787 ;
V_751 -> V_774 = V_775 ;
}
return 0 ;
}
static int T_10 F_372 ( void )
{
int V_26 ;
F_373 ( L_279 ) ;
F_97 ( & V_708 . V_31 ) ;
F_374 ( & V_708 . V_709 ) ;
V_26 = F_334 () ;
if ( V_26 )
goto V_788;
V_26 = F_375 ( & V_654 ) ;
if ( V_26 )
goto V_789;
V_26 = F_376 ( & V_723 ) ;
if ( V_26 )
goto V_790;
V_26 = F_377 ( & V_723 . V_745 ,
& V_791 ) ;
if ( V_26 )
goto V_792;
V_722 = F_378 ( L_280 ) ;
V_26 = F_80 ( V_722 ) ? F_81 ( V_722 ) : 0 ;
if ( V_26 )
goto V_793;
V_180 = F_379 ( L_281 ,
sizeof( struct V_522 ) + V_663 , 64 , 0 , NULL ) ;
if ( ! V_180 ) {
V_26 = - V_39 ;
goto V_794;
}
return 0 ;
V_794:
F_380 ( V_722 ) ;
V_793:
F_381 ( & V_723 . V_745 ,
& V_791 ) ;
V_792:
F_382 ( & V_723 ) ;
V_790:
F_383 ( & V_654 ) ;
V_789:
F_26 ( 2 , L_282 , V_26 ) ;
F_330 () ;
V_788:
F_384 ( L_283 ) ;
return V_26 ;
}
static void T_11 F_385 ( void )
{
F_380 ( V_722 ) ;
F_381 ( & V_723 . V_745 ,
& V_791 ) ;
F_382 ( & V_723 ) ;
F_383 ( & V_654 ) ;
F_386 ( V_180 ) ;
F_330 () ;
F_373 ( L_284 ) ;
}
