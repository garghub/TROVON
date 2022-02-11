static inline bool F_1 ( T_1 V_1 )
{
return V_1 != 0 ;
}
static inline struct V_2 * F_2 ( struct V_3 * V_3 )
{
F_3 ( ! V_3 ) ;
return F_4 ( V_3 , V_4 ) ;
}
static inline int F_5 ( struct V_5 * V_6 , struct V_5 * V_7 )
{
return V_6 -> V_1 == V_7 -> V_1 && F_6 ( V_6 -> V_8 , V_7 -> V_8 ) ;
}
static inline int F_7 ( struct V_5 * V_6 , T_1 V_1 , char * V_9 )
{
return V_6 -> V_1 == V_1 && F_6 ( V_6 -> V_8 , V_9 ) ;
}
static int F_8 ( T_1 V_1 , unsigned char * V_9 )
{
unsigned char V_10 = 0 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_10 ^= V_9 [ V_11 ] ;
for ( V_11 = 0 ; V_11 < sizeof( V_13 ) * 8 ; V_11 += 8 )
V_10 ^= ( V_14 V_15 ) V_1 >> V_11 ;
for ( V_11 = 8 ; ( V_11 >>= 1 ) >= V_16 ; )
V_10 ^= V_10 >> V_11 ;
return V_10 & V_17 ;
}
static struct V_18 * F_9 ( struct V_2 * V_19 , T_1 V_1 ,
unsigned char * V_9 , int V_20 )
{
int V_10 = F_8 ( V_1 , V_9 ) ;
struct V_18 * V_21 ;
V_21 = V_19 -> V_22 [ V_10 ] ;
while ( V_21 ) {
if ( F_7 ( & V_21 -> V_23 , V_1 , V_9 ) &&
V_21 -> V_24 == V_20 )
return V_21 ;
V_21 = V_21 -> V_25 ;
}
return NULL ;
}
static int F_10 ( struct V_2 * V_19 , struct V_18 * V_26 )
{
int V_10 = F_8 ( V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ) ;
struct V_18 * V_21 ;
V_21 = V_19 -> V_22 [ V_10 ] ;
while ( V_21 ) {
if ( F_5 ( & V_21 -> V_23 , & V_26 -> V_23 ) &&
V_21 -> V_24 == V_26 -> V_24 )
return - V_27 ;
V_21 = V_21 -> V_25 ;
}
V_26 -> V_25 = V_19 -> V_22 [ V_10 ] ;
V_19 -> V_22 [ V_10 ] = V_26 ;
return 0 ;
}
static void F_11 ( struct V_2 * V_19 , T_1 V_1 ,
char * V_9 , int V_20 )
{
int V_10 = F_8 ( V_1 , V_9 ) ;
struct V_18 * V_21 , * * V_28 ;
V_21 = V_19 -> V_22 [ V_10 ] ;
V_28 = & V_19 -> V_22 [ V_10 ] ;
while ( V_21 ) {
if ( F_7 ( & V_21 -> V_23 , V_1 , V_9 ) &&
V_21 -> V_24 == V_20 ) {
* V_28 = V_21 -> V_25 ;
break;
}
V_28 = & V_21 -> V_25 ;
V_21 = V_21 -> V_25 ;
}
}
static inline struct V_18 * F_12 ( struct V_2 * V_19 , T_1 V_1 ,
unsigned char * V_9 , int V_20 )
{
struct V_18 * V_26 ;
F_13 ( & V_19 -> V_29 ) ;
V_26 = F_9 ( V_19 , V_1 , V_9 , V_20 ) ;
if ( V_26 )
F_14 ( F_15 ( V_26 ) ) ;
F_16 ( & V_19 -> V_29 ) ;
return V_26 ;
}
static inline struct V_18 * F_17 ( struct V_3 * V_3 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_2 * V_19 ;
struct V_18 * V_18 = NULL ;
int V_20 ;
F_18 () ;
V_33 = F_19 ( V_3 , V_31 -> V_34 . V_35 . V_33 ) ;
if ( V_33 ) {
V_20 = V_33 -> V_20 ;
V_19 = F_2 ( V_3 ) ;
V_18 = F_12 ( V_19 , V_31 -> V_34 . V_35 . V_1 ,
V_31 -> V_34 . V_35 . V_8 , V_20 ) ;
}
F_20 () ;
return V_18 ;
}
static inline void F_21 ( struct V_2 * V_19 , T_1 V_1 ,
char * V_9 , int V_20 )
{
F_22 ( & V_19 -> V_29 ) ;
F_11 ( V_19 , V_1 , V_9 , V_20 ) ;
F_23 ( & V_19 -> V_29 ) ;
}
static void F_24 ( struct V_32 * V_33 )
{
struct V_2 * V_19 ;
int V_11 ;
V_19 = F_2 ( F_25 ( V_33 ) ) ;
F_22 ( & V_19 -> V_29 ) ;
for ( V_11 = 0 ; V_11 < V_36 ; V_11 ++ ) {
struct V_18 * V_26 = V_19 -> V_22 [ V_11 ] ;
struct V_37 * V_38 ;
while ( V_26 ) {
while ( V_26 && V_26 -> V_39 != V_33 ) {
V_26 = V_26 -> V_25 ;
}
if ( ! V_26 )
break;
V_38 = F_15 ( V_26 ) ;
F_14 ( V_38 ) ;
F_23 ( & V_19 -> V_29 ) ;
F_26 ( V_38 ) ;
if ( V_26 -> V_39 == V_33 &&
V_38 -> V_40 & ( V_41 | V_42 | V_43 ) ) {
F_27 ( V_38 ) ;
V_38 -> V_40 = V_43 ;
V_38 -> V_44 ( V_38 ) ;
V_26 -> V_39 = NULL ;
F_28 ( V_33 ) ;
}
F_29 ( V_38 ) ;
F_30 ( V_38 ) ;
F_3 ( F_2 ( F_25 ( V_33 ) ) == NULL ) ;
F_22 ( & V_19 -> V_29 ) ;
V_26 = V_19 -> V_22 [ V_11 ] ;
}
}
F_23 ( & V_19 -> V_29 ) ;
}
static int F_31 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
struct V_32 * V_33 = F_32 ( V_48 ) ;
switch ( V_47 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_24 ( V_33 ) ;
break;
default:
break;
}
return V_53 ;
}
static int F_33 ( struct V_37 * V_38 , struct V_54 * V_55 )
{
struct V_18 * V_26 = F_34 ( V_38 ) ;
struct V_18 * V_56 ;
if ( V_55 -> V_57 == V_58 )
goto V_59;
if ( V_38 -> V_40 & V_42 ) {
F_35 ( & V_26 -> V_60 , V_55 ) ;
} else if ( V_38 -> V_40 & V_61 ) {
V_56 = F_17 ( F_36 ( V_38 ) ,
& V_26 -> V_62 ) ;
if ( V_56 == NULL )
goto V_59;
if ( ( F_15 ( V_56 ) -> V_40 & V_41 ) == 0 )
goto V_63;
if ( ! F_37 ( F_15 ( V_56 ) , V_55 ) )
goto V_63;
} else {
if ( F_38 ( V_38 , V_55 ) )
goto V_59;
}
return V_64 ;
V_63:
F_30 ( F_15 ( V_56 ) ) ;
V_59:
F_39 ( V_55 ) ;
return V_65 ;
}
static int F_40 ( struct V_54 * V_55 , struct V_32 * V_33 ,
struct V_66 * V_67 , struct V_32 * V_68 )
{
struct V_69 * V_70 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
int V_71 ;
V_55 = F_41 ( V_55 , V_72 ) ;
if ( ! V_55 )
goto V_73;
if ( ! F_42 ( V_55 , sizeof( struct V_69 ) ) )
goto V_74;
V_70 = V_69 ( V_55 ) ;
V_71 = F_43 ( V_70 -> V_75 ) ;
F_44 ( V_55 , sizeof( * V_70 ) ) ;
if ( V_55 -> V_71 < V_71 )
goto V_74;
if ( F_45 ( V_55 , V_71 ) )
goto V_74;
V_19 = F_2 ( F_25 ( V_33 ) ) ;
V_26 = F_12 ( V_19 , V_70 -> V_1 , F_46 ( V_55 ) -> V_76 , V_33 -> V_20 ) ;
if ( ! V_26 )
goto V_74;
return F_47 ( F_15 ( V_26 ) , V_55 , 0 ) ;
V_74:
F_39 ( V_55 ) ;
V_73:
return V_65 ;
}
static void F_48 ( struct V_77 * V_78 )
{
struct V_18 * V_26 = F_49 ( V_78 , struct V_18 ,
V_79 . V_35 . V_80 ) ;
struct V_37 * V_38 = F_15 ( V_26 ) ;
F_26 ( V_38 ) ;
if ( V_26 -> V_39 ) {
F_28 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
F_27 ( V_38 ) ;
F_29 ( V_38 ) ;
F_30 ( V_38 ) ;
}
static int F_50 ( struct V_54 * V_55 , struct V_32 * V_33 ,
struct V_66 * V_67 , struct V_32 * V_68 )
{
struct V_69 * V_70 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
V_55 = F_41 ( V_55 , V_72 ) ;
if ( ! V_55 )
goto V_73;
if ( ! F_42 ( V_55 , sizeof( struct V_69 ) ) )
goto abort;
V_70 = V_69 ( V_55 ) ;
if ( V_70 -> V_81 != V_82 )
goto abort;
V_19 = F_2 ( F_25 ( V_33 ) ) ;
V_26 = F_12 ( V_19 , V_70 -> V_1 , F_46 ( V_55 ) -> V_76 , V_33 -> V_20 ) ;
if ( V_26 ) {
struct V_37 * V_38 = F_15 ( V_26 ) ;
F_51 ( V_38 ) ;
if ( F_52 ( V_38 ) == 0 ) {
V_38 -> V_40 = V_43 ;
}
F_53 ( V_38 ) ;
if ( ! F_54 ( & V_26 -> V_79 . V_35 . V_80 ) )
F_30 ( V_38 ) ;
}
abort:
F_39 ( V_55 ) ;
V_73:
return V_64 ;
}
static int F_55 ( struct V_3 * V_3 , struct V_83 * V_37 , int V_84 )
{
struct V_37 * V_38 ;
V_38 = F_56 ( V_3 , V_85 , V_86 , & V_87 , V_84 ) ;
if ( ! V_38 )
return - V_88 ;
F_57 ( V_37 , V_38 ) ;
V_37 -> V_89 = V_90 ;
V_37 -> V_91 = & V_92 ;
V_38 -> V_93 = F_33 ;
V_38 -> V_40 = V_94 ;
V_38 -> V_95 = V_96 ;
V_38 -> V_97 = V_85 ;
V_38 -> V_98 = V_99 ;
return 0 ;
}
static int F_58 ( struct V_83 * V_37 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
struct V_3 * V_3 = NULL ;
if ( ! V_38 )
return 0 ;
F_26 ( V_38 ) ;
if ( F_59 ( V_38 , V_100 ) ) {
F_29 ( V_38 ) ;
return - V_101 ;
}
V_26 = F_34 ( V_38 ) ;
if ( V_38 -> V_40 & ( V_41 | V_42 | V_43 ) ) {
F_28 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
F_27 ( V_38 ) ;
V_38 -> V_40 = V_102 ;
V_3 = F_36 ( V_38 ) ;
V_19 = F_2 ( V_3 ) ;
F_21 ( V_19 , V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ,
V_26 -> V_24 ) ;
F_60 ( V_38 ) ;
V_37 -> V_38 = NULL ;
F_61 ( & V_38 -> V_103 ) ;
F_29 ( V_38 ) ;
F_30 ( V_38 ) ;
return 0 ;
}
static int F_62 ( struct V_83 * V_37 , struct V_104 * V_105 ,
int V_106 , int V_107 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_30 * V_31 = (struct V_30 * ) V_105 ;
struct V_18 * V_26 = F_34 ( V_38 ) ;
struct V_32 * V_33 = NULL ;
struct V_2 * V_19 ;
struct V_3 * V_3 = NULL ;
int error ;
F_26 ( V_38 ) ;
F_63 ( & V_26 -> V_79 . V_35 . V_80 , F_48 ) ;
error = - V_108 ;
if ( V_31 -> V_109 != V_99 )
goto V_110;
error = - V_111 ;
if ( ( V_38 -> V_40 & V_41 ) &&
F_1 ( V_31 -> V_34 . V_35 . V_1 ) )
goto V_110;
error = - V_27 ;
if ( ( V_38 -> V_40 & V_102 ) &&
! F_1 ( V_31 -> V_34 . V_35 . V_1 ) )
goto V_110;
error = 0 ;
if ( F_1 ( V_26 -> V_23 . V_1 ) ) {
F_27 ( V_38 ) ;
V_19 = F_2 ( F_36 ( V_38 ) ) ;
F_21 ( V_19 , V_26 -> V_23 . V_1 ,
V_26 -> V_23 . V_8 , V_26 -> V_24 ) ;
if ( V_26 -> V_39 ) {
F_28 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
memset ( F_15 ( V_26 ) + 1 , 0 ,
sizeof( struct V_18 ) - sizeof( struct V_37 ) ) ;
V_38 -> V_40 = V_94 ;
}
if ( F_1 ( V_31 -> V_34 . V_35 . V_1 ) ) {
error = - V_112 ;
V_3 = F_36 ( V_38 ) ;
V_33 = F_64 ( V_3 , V_31 -> V_34 . V_35 . V_33 ) ;
if ( ! V_33 )
goto V_113;
V_26 -> V_39 = V_33 ;
V_26 -> V_24 = V_33 -> V_20 ;
V_19 = F_2 ( V_3 ) ;
if ( ! ( V_33 -> V_107 & V_114 ) ) {
goto V_113;
}
memcpy ( & V_26 -> V_23 ,
& V_31 -> V_34 . V_35 ,
sizeof( struct V_5 ) ) ;
F_22 ( & V_19 -> V_29 ) ;
error = F_10 ( V_19 , V_26 ) ;
F_23 ( & V_19 -> V_29 ) ;
if ( error < 0 )
goto V_113;
V_26 -> V_60 . V_115 = ( sizeof( struct V_69 ) +
V_33 -> V_116 ) ;
V_26 -> V_60 . V_117 = V_33 -> V_117 - sizeof( struct V_69 ) - 2 ;
V_26 -> V_60 . V_118 = V_38 ;
V_26 -> V_60 . V_91 = & V_119 ;
error = F_65 ( F_25 ( V_33 ) , & V_26 -> V_60 ) ;
if ( error ) {
F_21 ( V_19 , V_26 -> V_23 . V_1 ,
V_26 -> V_23 . V_8 , V_26 -> V_24 ) ;
goto V_113;
}
V_38 -> V_40 = V_41 ;
}
V_26 -> V_120 = V_31 -> V_34 . V_35 . V_1 ;
V_110:
F_29 ( V_38 ) ;
return error ;
V_113:
if ( V_26 -> V_39 ) {
F_28 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
goto V_110;
}
static int F_66 ( struct V_83 * V_37 , struct V_104 * V_121 ,
int * V_122 , int V_123 )
{
int V_71 = sizeof( struct V_30 ) ;
struct V_30 V_31 ;
V_31 . V_124 = V_125 ;
V_31 . V_109 = V_99 ;
memcpy ( & V_31 . V_34 . V_35 , & F_34 ( V_37 -> V_38 ) -> V_23 ,
sizeof( struct V_5 ) ) ;
memcpy ( V_121 , & V_31 , V_71 ) ;
* V_122 = V_71 ;
return 0 ;
}
static int F_67 ( struct V_83 * V_37 , unsigned int V_126 ,
unsigned long V_127 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 = F_34 ( V_38 ) ;
int V_128 ;
int V_129 ;
switch ( V_126 ) {
case V_130 :
V_129 = - V_131 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_129 = - V_132 ;
if ( F_68 ( V_26 -> V_39 -> V_117 -
sizeof( struct V_69 ) -
V_133 ,
( int V_134 * ) V_127 ) )
break;
V_129 = 0 ;
break;
case V_135 :
V_129 = - V_131 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_129 = - V_132 ;
if ( F_69 ( V_128 , ( int V_134 * ) V_127 ) )
break;
if ( V_128 < ( V_26 -> V_39 -> V_117
- sizeof( struct V_69 )
- V_133 ) )
V_129 = 0 ;
else
V_129 = - V_108 ;
break;
case V_136 :
V_129 = - V_132 ;
if ( F_69 ( V_128 , ( int V_134 * ) V_127 ) )
break;
V_129 = 0 ;
break;
case V_137 :
{
struct V_18 * V_56 ;
V_129 = - V_111 ;
if ( V_38 -> V_40 & ( V_42 | V_43 | V_102 ) )
break;
V_129 = - V_138 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_129 = - V_132 ;
if ( F_70 ( & V_26 -> V_62 ,
( void V_134 * ) V_127 ,
sizeof( struct V_30 ) ) )
break;
V_129 = - V_108 ;
if ( V_26 -> V_62 . V_124 != V_125 ||
V_26 -> V_62 . V_109 != V_99 )
break;
V_56 = F_17 ( F_36 ( V_38 ) , & V_26 -> V_62 ) ;
if ( ! V_56 )
break;
F_30 ( F_15 ( V_56 ) ) ;
V_38 -> V_40 |= V_61 ;
V_129 = 0 ;
break;
}
case V_139 :
V_129 = - V_27 ;
if ( ! ( V_38 -> V_40 & V_61 ) )
break;
V_38 -> V_40 &= ~ V_61 ;
V_129 = 0 ;
break;
default:
V_129 = - V_140 ;
}
return V_129 ;
}
static int F_71 ( struct V_83 * V_37 , struct V_141 * V_142 ,
T_2 V_143 )
{
struct V_54 * V_55 ;
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 = F_34 ( V_38 ) ;
int error ;
struct V_69 V_144 ;
struct V_69 * V_70 ;
struct V_32 * V_33 ;
char * V_145 ;
F_26 ( V_38 ) ;
if ( F_59 ( V_38 , V_100 ) || ! ( V_38 -> V_40 & V_41 ) ) {
error = - V_138 ;
goto V_110;
}
V_144 . V_146 = 1 ;
V_144 . type = 1 ;
V_144 . V_81 = 0 ;
V_144 . V_1 = V_26 -> V_120 ;
V_33 = V_26 -> V_39 ;
error = - V_147 ;
if ( V_143 > ( V_33 -> V_117 + V_33 -> V_116 ) )
goto V_110;
V_55 = F_72 ( V_38 , V_143 + V_33 -> V_116 + 32 ,
0 , V_86 ) ;
if ( ! V_55 ) {
error = - V_88 ;
goto V_110;
}
F_73 ( V_55 , V_33 -> V_116 ) ;
F_74 ( V_55 ) ;
V_55 -> V_33 = V_33 ;
V_55 -> V_148 = V_38 -> V_149 ;
V_55 -> V_150 = F_75 ( V_151 ) ;
V_70 = (struct V_69 * ) F_76 ( V_55 , V_143 + sizeof( struct V_69 ) ) ;
V_145 = ( char * ) & V_70 -> V_152 [ 0 ] ;
error = F_77 ( V_145 , V_142 , V_143 ) ;
if ( error < 0 ) {
F_39 ( V_55 ) ;
goto V_110;
}
error = V_143 ;
F_78 ( V_55 , V_33 , V_151 ,
V_26 -> V_23 . V_8 , NULL , V_143 ) ;
memcpy ( V_70 , & V_144 , sizeof( struct V_69 ) ) ;
V_70 -> V_75 = F_79 ( V_143 ) ;
F_80 ( V_55 ) ;
V_110:
F_29 ( V_38 ) ;
return error ;
}
static int F_37 ( struct V_37 * V_38 , struct V_54 * V_55 )
{
struct V_18 * V_26 = F_34 ( V_38 ) ;
struct V_32 * V_33 = V_26 -> V_39 ;
struct V_69 * V_70 ;
int V_153 = V_55 -> V_71 ;
if ( F_59 ( V_38 , V_100 ) || ! ( V_38 -> V_40 & V_41 ) )
goto abort;
if ( ! V_33 )
goto abort;
if ( F_81 ( V_55 , sizeof( * V_70 ) + V_33 -> V_116 ) )
goto abort;
F_82 ( V_55 , sizeof( * V_70 ) ) ;
F_74 ( V_55 ) ;
V_70 = V_69 ( V_55 ) ;
V_70 -> V_146 = 1 ;
V_70 -> type = 1 ;
V_70 -> V_81 = 0 ;
V_70 -> V_1 = V_26 -> V_120 ;
V_70 -> V_75 = F_79 ( V_153 ) ;
V_55 -> V_150 = F_75 ( V_151 ) ;
V_55 -> V_33 = V_33 ;
F_78 ( V_55 , V_33 , V_151 ,
V_26 -> V_23 . V_8 , NULL , V_153 ) ;
F_80 ( V_55 ) ;
return 1 ;
abort:
F_39 ( V_55 ) ;
return 1 ;
}
static int F_83 ( struct V_154 * V_60 , struct V_54 * V_55 )
{
struct V_37 * V_38 = (struct V_37 * ) V_60 -> V_118 ;
return F_37 ( V_38 , V_55 ) ;
}
static int F_84 ( struct V_83 * V_37 , struct V_141 * V_142 ,
T_2 V_143 , int V_107 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_54 * V_55 ;
int error = 0 ;
if ( V_38 -> V_40 & V_42 ) {
error = - V_155 ;
goto V_110;
}
V_55 = F_85 ( V_38 , V_107 & ~ V_156 ,
V_107 & V_156 , & error ) ;
if ( error < 0 )
goto V_110;
if ( V_55 ) {
V_143 = F_86 ( T_2 , V_143 , V_55 -> V_71 ) ;
error = F_87 ( V_55 , 0 , V_142 , V_143 ) ;
if ( error == 0 ) {
F_88 ( V_55 ) ;
return V_143 ;
}
}
F_39 ( V_55 ) ;
V_110:
return error ;
}
static int F_89 ( struct V_157 * V_158 , void * V_159 )
{
struct V_18 * V_26 ;
char * V_160 ;
if ( V_159 == V_161 ) {
F_90 ( V_158 , L_1 ) ;
goto V_73;
}
V_26 = V_159 ;
V_160 = V_26 -> V_23 . V_33 ;
F_91 ( V_158 , L_2 ,
V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 , V_160 ) ;
V_73:
return 0 ;
}
static inline struct V_18 * F_92 ( struct V_2 * V_19 , T_3 V_162 )
{
struct V_18 * V_26 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_36 ; V_11 ++ ) {
V_26 = V_19 -> V_22 [ V_11 ] ;
while ( V_26 ) {
if ( ! V_162 -- )
goto V_73;
V_26 = V_26 -> V_25 ;
}
}
V_73:
return V_26 ;
}
static void * F_93 ( struct V_157 * V_158 , T_3 * V_162 )
__acquires( V_19 -> V_29 )
{
struct V_2 * V_19 = F_2 ( F_94 ( V_158 ) ) ;
T_3 V_163 = * V_162 ;
F_13 ( & V_19 -> V_29 ) ;
return V_163 ? F_92 ( V_19 , -- V_163 ) : V_161 ;
}
static void * F_95 ( struct V_157 * V_158 , void * V_159 , T_3 * V_162 )
{
struct V_2 * V_19 = F_2 ( F_94 ( V_158 ) ) ;
struct V_18 * V_26 ;
++ * V_162 ;
if ( V_159 == V_161 ) {
V_26 = F_92 ( V_19 , 0 ) ;
goto V_73;
}
V_26 = V_159 ;
if ( V_26 -> V_25 )
V_26 = V_26 -> V_25 ;
else {
int V_10 = F_8 ( V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ) ;
V_26 = NULL ;
while ( ++ V_10 < V_36 ) {
V_26 = V_19 -> V_22 [ V_10 ] ;
if ( V_26 )
break;
}
}
V_73:
return V_26 ;
}
static void F_96 ( struct V_157 * V_158 , void * V_159 )
__releases( V_19 -> V_29 )
{
struct V_2 * V_19 = F_2 ( F_94 ( V_158 ) ) ;
F_16 ( & V_19 -> V_29 ) ;
}
static int F_97 ( struct V_164 * V_164 , struct V_165 * V_165 )
{
return F_98 ( V_164 , V_165 , & V_166 ,
sizeof( struct V_167 ) ) ;
}
static T_4 int F_99 ( struct V_3 * V_3 )
{
struct V_2 * V_19 = F_2 ( V_3 ) ;
struct V_168 * V_169 ;
F_100 ( & V_19 -> V_29 ) ;
V_169 = F_101 ( L_3 , V_170 , V_3 -> V_171 , & V_172 ) ;
#ifdef F_102
if ( ! V_169 )
return - V_88 ;
#endif
return 0 ;
}
static T_5 void F_103 ( struct V_3 * V_3 )
{
F_104 ( L_3 , V_3 -> V_171 ) ;
}
static int T_6 F_105 ( void )
{
int V_129 ;
V_129 = F_106 ( & V_173 ) ;
if ( V_129 )
goto V_73;
V_129 = F_107 ( & V_87 , 0 ) ;
if ( V_129 )
goto V_174;
V_129 = F_108 ( V_99 , & V_175 ) ;
if ( V_129 )
goto V_176;
F_109 ( & V_177 ) ;
F_109 ( & V_178 ) ;
F_110 ( & V_179 ) ;
return 0 ;
V_176:
F_111 ( & V_87 ) ;
V_174:
F_112 ( & V_173 ) ;
V_73:
return V_129 ;
}
static void T_7 F_113 ( void )
{
F_114 ( & V_179 ) ;
F_115 ( & V_178 ) ;
F_115 ( & V_177 ) ;
F_116 ( V_99 ) ;
F_111 ( & V_87 ) ;
F_112 ( & V_173 ) ;
}
