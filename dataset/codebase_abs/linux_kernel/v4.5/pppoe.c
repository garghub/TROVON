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
V_38 -> V_40 & ( V_41 | V_42 ) ) {
F_27 ( V_38 ) ;
V_38 -> V_43 ( V_38 ) ;
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
static int F_31 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
struct V_32 * V_33 = F_32 ( V_47 ) ;
switch ( V_46 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
F_24 ( V_33 ) ;
break;
default:
break;
}
return V_52 ;
}
static int F_33 ( struct V_37 * V_38 , struct V_53 * V_54 )
{
struct V_18 * V_26 = F_34 ( V_38 ) ;
struct V_18 * V_55 ;
if ( V_54 -> V_56 == V_57 )
goto V_58;
if ( V_38 -> V_40 & V_42 ) {
F_35 ( & V_26 -> V_59 , V_54 ) ;
} else if ( V_38 -> V_40 & V_60 ) {
V_55 = F_17 ( F_36 ( V_38 ) ,
& V_26 -> V_61 ) ;
if ( V_55 == NULL )
goto V_58;
if ( ( F_15 ( V_55 ) -> V_40 & V_41 ) == 0 )
goto V_62;
if ( ! F_37 ( F_15 ( V_55 ) , V_54 ) )
goto V_62;
F_30 ( F_15 ( V_55 ) ) ;
} else {
if ( F_38 ( V_38 , V_54 ) )
goto V_58;
}
return V_63 ;
V_62:
F_30 ( F_15 ( V_55 ) ) ;
V_58:
F_39 ( V_54 ) ;
return V_64 ;
}
static int F_40 ( struct V_53 * V_54 , struct V_32 * V_33 ,
struct V_65 * V_66 , struct V_32 * V_67 )
{
struct V_68 * V_69 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
int V_70 ;
V_54 = F_41 ( V_54 , V_71 ) ;
if ( ! V_54 )
goto V_72;
if ( ! F_42 ( V_54 , sizeof( struct V_68 ) ) )
goto V_73;
V_69 = V_68 ( V_54 ) ;
V_70 = F_43 ( V_69 -> V_74 ) ;
F_44 ( V_54 , sizeof( * V_69 ) ) ;
if ( V_54 -> V_70 < V_70 )
goto V_73;
if ( F_45 ( V_54 , V_70 ) )
goto V_73;
V_19 = F_2 ( F_25 ( V_33 ) ) ;
V_26 = F_12 ( V_19 , V_69 -> V_1 , F_46 ( V_54 ) -> V_75 , V_33 -> V_20 ) ;
if ( ! V_26 )
goto V_73;
return F_47 ( F_15 ( V_26 ) , V_54 , 0 ) ;
V_73:
F_39 ( V_54 ) ;
V_72:
return V_64 ;
}
static void F_48 ( struct V_76 * V_77 )
{
struct V_18 * V_26 = F_49 ( V_77 , struct V_18 ,
V_78 . V_35 . V_79 ) ;
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
static int F_50 ( struct V_53 * V_54 , struct V_32 * V_33 ,
struct V_65 * V_66 , struct V_32 * V_67 )
{
struct V_68 * V_69 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
V_54 = F_41 ( V_54 , V_71 ) ;
if ( ! V_54 )
goto V_72;
if ( ! F_42 ( V_54 , sizeof( struct V_68 ) ) )
goto abort;
V_69 = V_68 ( V_54 ) ;
if ( V_69 -> V_80 != V_81 )
goto abort;
V_19 = F_2 ( F_25 ( V_33 ) ) ;
V_26 = F_12 ( V_19 , V_69 -> V_1 , F_46 ( V_54 ) -> V_75 , V_33 -> V_20 ) ;
if ( V_26 )
if ( ! F_51 ( & V_26 -> V_78 . V_35 . V_79 ) )
F_30 ( F_15 ( V_26 ) ) ;
abort:
F_39 ( V_54 ) ;
V_72:
return V_63 ;
}
static int F_52 ( struct V_3 * V_3 , struct V_82 * V_37 , int V_83 )
{
struct V_37 * V_38 ;
V_38 = F_53 ( V_3 , V_84 , V_85 , & V_86 , V_83 ) ;
if ( ! V_38 )
return - V_87 ;
F_54 ( V_37 , V_38 ) ;
V_37 -> V_88 = V_89 ;
V_37 -> V_90 = & V_91 ;
V_38 -> V_92 = F_33 ;
V_38 -> V_40 = V_93 ;
V_38 -> V_94 = V_95 ;
V_38 -> V_96 = V_84 ;
V_38 -> V_97 = V_98 ;
F_55 ( & F_34 ( V_38 ) -> V_78 . V_35 . V_79 ,
F_48 ) ;
return 0 ;
}
static int F_56 ( struct V_82 * V_37 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
struct V_3 * V_3 = NULL ;
if ( ! V_38 )
return 0 ;
F_26 ( V_38 ) ;
if ( F_57 ( V_38 , V_99 ) ) {
F_29 ( V_38 ) ;
return - V_100 ;
}
V_26 = F_34 ( V_38 ) ;
if ( V_26 -> V_39 ) {
F_28 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
F_27 ( V_38 ) ;
V_38 -> V_40 = V_101 ;
V_3 = F_36 ( V_38 ) ;
V_19 = F_2 ( V_3 ) ;
F_21 ( V_19 , V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ,
V_26 -> V_24 ) ;
F_58 ( V_38 ) ;
V_37 -> V_38 = NULL ;
F_59 ( & V_38 -> V_102 ) ;
F_29 ( V_38 ) ;
F_30 ( V_38 ) ;
return 0 ;
}
static int F_60 ( struct V_82 * V_37 , struct V_103 * V_104 ,
int V_105 , int V_106 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_30 * V_31 = (struct V_30 * ) V_104 ;
struct V_18 * V_26 = F_34 ( V_38 ) ;
struct V_32 * V_33 = NULL ;
struct V_2 * V_19 ;
struct V_3 * V_3 = NULL ;
int error ;
F_26 ( V_38 ) ;
error = - V_107 ;
if ( V_31 -> V_108 != V_98 )
goto V_109;
error = - V_110 ;
if ( ( V_38 -> V_40 & V_41 ) &&
F_1 ( V_31 -> V_34 . V_35 . V_1 ) )
goto V_109;
error = - V_27 ;
if ( ( V_38 -> V_40 & V_101 ) &&
! F_1 ( V_31 -> V_34 . V_35 . V_1 ) )
goto V_109;
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
V_26 -> V_24 = 0 ;
memset ( & V_26 -> V_23 , 0 , sizeof( V_26 -> V_23 ) ) ;
memset ( & V_26 -> V_61 , 0 , sizeof( V_26 -> V_61 ) ) ;
memset ( & V_26 -> V_59 , 0 , sizeof( V_26 -> V_59 ) ) ;
V_26 -> V_25 = NULL ;
V_26 -> V_111 = 0 ;
V_38 -> V_40 = V_93 ;
}
if ( F_1 ( V_31 -> V_34 . V_35 . V_1 ) ) {
error = - V_112 ;
V_3 = F_36 ( V_38 ) ;
V_33 = F_61 ( V_3 , V_31 -> V_34 . V_35 . V_33 ) ;
if ( ! V_33 )
goto V_113;
V_26 -> V_39 = V_33 ;
V_26 -> V_24 = V_33 -> V_20 ;
V_19 = F_2 ( V_3 ) ;
if ( ! ( V_33 -> V_106 & V_114 ) ) {
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
V_26 -> V_59 . V_115 = ( sizeof( struct V_68 ) +
V_33 -> V_116 ) ;
V_26 -> V_59 . V_117 = V_33 -> V_117 - sizeof( struct V_68 ) - 2 ;
V_26 -> V_59 . V_118 = V_38 ;
V_26 -> V_59 . V_90 = & V_119 ;
error = F_62 ( F_25 ( V_33 ) , & V_26 -> V_59 ) ;
if ( error ) {
F_21 ( V_19 , V_26 -> V_23 . V_1 ,
V_26 -> V_23 . V_8 , V_26 -> V_24 ) ;
goto V_113;
}
V_38 -> V_40 = V_41 ;
}
V_26 -> V_111 = V_31 -> V_34 . V_35 . V_1 ;
V_109:
F_29 ( V_38 ) ;
return error ;
V_113:
if ( V_26 -> V_39 ) {
F_28 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
goto V_109;
}
static int F_63 ( struct V_82 * V_37 , struct V_103 * V_120 ,
int * V_121 , int V_122 )
{
int V_70 = sizeof( struct V_30 ) ;
struct V_30 V_31 ;
V_31 . V_123 = V_124 ;
V_31 . V_108 = V_98 ;
memcpy ( & V_31 . V_34 . V_35 , & F_34 ( V_37 -> V_38 ) -> V_23 ,
sizeof( struct V_5 ) ) ;
memcpy ( V_120 , & V_31 , V_70 ) ;
* V_121 = V_70 ;
return 0 ;
}
static int F_64 ( struct V_82 * V_37 , unsigned int V_125 ,
unsigned long V_126 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 = F_34 ( V_38 ) ;
int V_127 ;
int V_128 ;
switch ( V_125 ) {
case V_129 :
V_128 = - V_130 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_128 = - V_131 ;
if ( F_65 ( V_26 -> V_39 -> V_117 -
sizeof( struct V_68 ) -
V_132 ,
( int V_133 * ) V_126 ) )
break;
V_128 = 0 ;
break;
case V_134 :
V_128 = - V_130 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_128 = - V_131 ;
if ( F_66 ( V_127 , ( int V_133 * ) V_126 ) )
break;
if ( V_127 < ( V_26 -> V_39 -> V_117
- sizeof( struct V_68 )
- V_132 ) )
V_128 = 0 ;
else
V_128 = - V_107 ;
break;
case V_135 :
V_128 = - V_131 ;
if ( F_66 ( V_127 , ( int V_133 * ) V_126 ) )
break;
V_128 = 0 ;
break;
case V_136 :
{
struct V_18 * V_55 ;
V_128 = - V_110 ;
if ( V_38 -> V_40 & ( V_42 | V_101 ) )
break;
V_128 = - V_137 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_128 = - V_131 ;
if ( F_67 ( & V_26 -> V_61 ,
( void V_133 * ) V_126 ,
sizeof( struct V_30 ) ) )
break;
V_128 = - V_107 ;
if ( V_26 -> V_61 . V_123 != V_124 ||
V_26 -> V_61 . V_108 != V_98 )
break;
V_55 = F_17 ( F_36 ( V_38 ) , & V_26 -> V_61 ) ;
if ( ! V_55 )
break;
F_30 ( F_15 ( V_55 ) ) ;
V_38 -> V_40 |= V_60 ;
V_128 = 0 ;
break;
}
case V_138 :
V_128 = - V_27 ;
if ( ! ( V_38 -> V_40 & V_60 ) )
break;
V_38 -> V_40 &= ~ V_60 ;
V_128 = 0 ;
break;
default:
V_128 = - V_139 ;
}
return V_128 ;
}
static int F_68 ( struct V_82 * V_37 , struct V_140 * V_141 ,
T_2 V_142 )
{
struct V_53 * V_54 ;
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 = F_34 ( V_38 ) ;
int error ;
struct V_68 V_143 ;
struct V_68 * V_69 ;
struct V_32 * V_33 ;
char * V_144 ;
F_26 ( V_38 ) ;
if ( F_57 ( V_38 , V_99 ) || ! ( V_38 -> V_40 & V_41 ) ) {
error = - V_137 ;
goto V_109;
}
V_143 . V_145 = 1 ;
V_143 . type = 1 ;
V_143 . V_80 = 0 ;
V_143 . V_1 = V_26 -> V_111 ;
V_33 = V_26 -> V_39 ;
error = - V_146 ;
if ( V_142 > ( V_33 -> V_117 + V_33 -> V_116 ) )
goto V_109;
V_54 = F_69 ( V_38 , V_142 + V_33 -> V_116 + 32 ,
0 , V_85 ) ;
if ( ! V_54 ) {
error = - V_87 ;
goto V_109;
}
F_70 ( V_54 , V_33 -> V_116 ) ;
F_71 ( V_54 ) ;
V_54 -> V_33 = V_33 ;
V_54 -> V_147 = V_38 -> V_148 ;
V_54 -> V_149 = F_72 ( V_150 ) ;
V_69 = (struct V_68 * ) F_73 ( V_54 , V_142 + sizeof( struct V_68 ) ) ;
V_144 = ( char * ) & V_69 -> V_151 [ 0 ] ;
error = F_74 ( V_144 , V_141 , V_142 ) ;
if ( error < 0 ) {
F_39 ( V_54 ) ;
goto V_109;
}
error = V_142 ;
F_75 ( V_54 , V_33 , V_150 ,
V_26 -> V_23 . V_8 , NULL , V_142 ) ;
memcpy ( V_69 , & V_143 , sizeof( struct V_68 ) ) ;
V_69 -> V_74 = F_76 ( V_142 ) ;
F_77 ( V_54 ) ;
V_109:
F_29 ( V_38 ) ;
return error ;
}
static int F_37 ( struct V_37 * V_38 , struct V_53 * V_54 )
{
struct V_18 * V_26 = F_34 ( V_38 ) ;
struct V_32 * V_33 = V_26 -> V_39 ;
struct V_68 * V_69 ;
int V_152 = V_54 -> V_70 ;
if ( F_57 ( V_38 , V_99 ) || ! ( V_38 -> V_40 & V_41 ) )
goto abort;
if ( ! V_33 )
goto abort;
if ( F_78 ( V_54 , sizeof( * V_69 ) + V_33 -> V_116 ) )
goto abort;
F_79 ( V_54 , sizeof( * V_69 ) ) ;
F_71 ( V_54 ) ;
V_69 = V_68 ( V_54 ) ;
V_69 -> V_145 = 1 ;
V_69 -> type = 1 ;
V_69 -> V_80 = 0 ;
V_69 -> V_1 = V_26 -> V_111 ;
V_69 -> V_74 = F_76 ( V_152 ) ;
V_54 -> V_149 = F_72 ( V_150 ) ;
V_54 -> V_33 = V_33 ;
F_75 ( V_54 , V_33 , V_150 ,
V_26 -> V_23 . V_8 , NULL , V_152 ) ;
F_77 ( V_54 ) ;
return 1 ;
abort:
F_39 ( V_54 ) ;
return 1 ;
}
static int F_80 ( struct V_153 * V_59 , struct V_53 * V_54 )
{
struct V_37 * V_38 = (struct V_37 * ) V_59 -> V_118 ;
return F_37 ( V_38 , V_54 ) ;
}
static int F_81 ( struct V_82 * V_37 , struct V_140 * V_141 ,
T_2 V_142 , int V_106 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_53 * V_54 ;
int error = 0 ;
if ( V_38 -> V_40 & V_42 ) {
error = - V_154 ;
goto V_109;
}
V_54 = F_82 ( V_38 , V_106 & ~ V_155 ,
V_106 & V_155 , & error ) ;
if ( error < 0 )
goto V_109;
if ( V_54 ) {
V_142 = F_83 ( T_2 , V_142 , V_54 -> V_70 ) ;
error = F_84 ( V_54 , 0 , V_141 , V_142 ) ;
if ( error == 0 ) {
F_85 ( V_54 ) ;
return V_142 ;
}
}
F_39 ( V_54 ) ;
V_109:
return error ;
}
static int F_86 ( struct V_156 * V_157 , void * V_158 )
{
struct V_18 * V_26 ;
char * V_159 ;
if ( V_158 == V_160 ) {
F_87 ( V_157 , L_1 ) ;
goto V_72;
}
V_26 = V_158 ;
V_159 = V_26 -> V_23 . V_33 ;
F_88 ( V_157 , L_2 ,
V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 , V_159 ) ;
V_72:
return 0 ;
}
static inline struct V_18 * F_89 ( struct V_2 * V_19 , T_3 V_161 )
{
struct V_18 * V_26 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_36 ; V_11 ++ ) {
V_26 = V_19 -> V_22 [ V_11 ] ;
while ( V_26 ) {
if ( ! V_161 -- )
goto V_72;
V_26 = V_26 -> V_25 ;
}
}
V_72:
return V_26 ;
}
static void * F_90 ( struct V_156 * V_157 , T_3 * V_161 )
__acquires( V_19 -> V_29 )
{
struct V_2 * V_19 = F_2 ( F_91 ( V_157 ) ) ;
T_3 V_162 = * V_161 ;
F_13 ( & V_19 -> V_29 ) ;
return V_162 ? F_89 ( V_19 , -- V_162 ) : V_160 ;
}
static void * F_92 ( struct V_156 * V_157 , void * V_158 , T_3 * V_161 )
{
struct V_2 * V_19 = F_2 ( F_91 ( V_157 ) ) ;
struct V_18 * V_26 ;
++ * V_161 ;
if ( V_158 == V_160 ) {
V_26 = F_89 ( V_19 , 0 ) ;
goto V_72;
}
V_26 = V_158 ;
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
V_72:
return V_26 ;
}
static void F_93 ( struct V_156 * V_157 , void * V_158 )
__releases( V_19 -> V_29 )
{
struct V_2 * V_19 = F_2 ( F_91 ( V_157 ) ) ;
F_16 ( & V_19 -> V_29 ) ;
}
static int F_94 ( struct V_163 * V_163 , struct V_164 * V_164 )
{
return F_95 ( V_163 , V_164 , & V_165 ,
sizeof( struct V_166 ) ) ;
}
static T_4 int F_96 ( struct V_3 * V_3 )
{
struct V_2 * V_19 = F_2 ( V_3 ) ;
struct V_167 * V_168 ;
F_97 ( & V_19 -> V_29 ) ;
V_168 = F_98 ( L_3 , V_169 , V_3 -> V_170 , & V_171 ) ;
#ifdef F_99
if ( ! V_168 )
return - V_87 ;
#endif
return 0 ;
}
static T_5 void F_100 ( struct V_3 * V_3 )
{
F_101 ( L_3 , V_3 -> V_170 ) ;
}
static int T_6 F_102 ( void )
{
int V_128 ;
V_128 = F_103 ( & V_172 ) ;
if ( V_128 )
goto V_72;
V_128 = F_104 ( & V_86 , 0 ) ;
if ( V_128 )
goto V_173;
V_128 = F_105 ( V_98 , & V_174 ) ;
if ( V_128 )
goto V_175;
F_106 ( & V_176 ) ;
F_106 ( & V_177 ) ;
F_107 ( & V_178 ) ;
return 0 ;
V_175:
F_108 ( & V_86 ) ;
V_173:
F_109 ( & V_172 ) ;
V_72:
return V_128 ;
}
static void T_7 F_110 ( void )
{
F_111 ( & V_178 ) ;
F_112 ( & V_177 ) ;
F_112 ( & V_176 ) ;
F_113 ( V_98 ) ;
F_108 ( & V_86 ) ;
F_109 ( & V_172 ) ;
}
