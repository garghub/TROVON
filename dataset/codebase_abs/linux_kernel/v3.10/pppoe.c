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
return V_6 -> V_1 == V_7 -> V_1 && ! memcmp ( V_6 -> V_8 , V_7 -> V_8 , V_9 ) ;
}
static inline int F_6 ( struct V_5 * V_6 , T_1 V_1 , char * V_10 )
{
return V_6 -> V_1 == V_1 && ! memcmp ( V_6 -> V_8 , V_10 , V_9 ) ;
}
static int F_7 ( T_1 V_1 , unsigned char * V_10 )
{
unsigned char V_11 = 0 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ )
V_11 ^= V_10 [ V_12 ] ;
for ( V_12 = 0 ; V_12 < sizeof( V_13 ) * 8 ; V_12 += 8 )
V_11 ^= ( V_14 V_15 ) V_1 >> V_12 ;
for ( V_12 = 8 ; ( V_12 >>= 1 ) >= V_16 ; )
V_11 ^= V_11 >> V_12 ;
return V_11 & V_17 ;
}
static struct V_18 * F_8 ( struct V_2 * V_19 , T_1 V_1 ,
unsigned char * V_10 , int V_20 )
{
int V_11 = F_7 ( V_1 , V_10 ) ;
struct V_18 * V_21 ;
V_21 = V_19 -> V_22 [ V_11 ] ;
while ( V_21 ) {
if ( F_6 ( & V_21 -> V_23 , V_1 , V_10 ) &&
V_21 -> V_24 == V_20 )
return V_21 ;
V_21 = V_21 -> V_25 ;
}
return NULL ;
}
static int F_9 ( struct V_2 * V_19 , struct V_18 * V_26 )
{
int V_11 = F_7 ( V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ) ;
struct V_18 * V_21 ;
V_21 = V_19 -> V_22 [ V_11 ] ;
while ( V_21 ) {
if ( F_5 ( & V_21 -> V_23 , & V_26 -> V_23 ) &&
V_21 -> V_24 == V_26 -> V_24 )
return - V_27 ;
V_21 = V_21 -> V_25 ;
}
V_26 -> V_25 = V_19 -> V_22 [ V_11 ] ;
V_19 -> V_22 [ V_11 ] = V_26 ;
return 0 ;
}
static void F_10 ( struct V_2 * V_19 , T_1 V_1 ,
char * V_10 , int V_20 )
{
int V_11 = F_7 ( V_1 , V_10 ) ;
struct V_18 * V_21 , * * V_28 ;
V_21 = V_19 -> V_22 [ V_11 ] ;
V_28 = & V_19 -> V_22 [ V_11 ] ;
while ( V_21 ) {
if ( F_6 ( & V_21 -> V_23 , V_1 , V_10 ) &&
V_21 -> V_24 == V_20 ) {
* V_28 = V_21 -> V_25 ;
break;
}
V_28 = & V_21 -> V_25 ;
V_21 = V_21 -> V_25 ;
}
}
static inline struct V_18 * F_11 ( struct V_2 * V_19 , T_1 V_1 ,
unsigned char * V_10 , int V_20 )
{
struct V_18 * V_26 ;
F_12 ( & V_19 -> V_29 ) ;
V_26 = F_8 ( V_19 , V_1 , V_10 , V_20 ) ;
if ( V_26 )
F_13 ( F_14 ( V_26 ) ) ;
F_15 ( & V_19 -> V_29 ) ;
return V_26 ;
}
static inline struct V_18 * F_16 ( struct V_3 * V_3 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_2 * V_19 ;
struct V_18 * V_18 = NULL ;
int V_20 ;
F_17 () ;
V_33 = F_18 ( V_3 , V_31 -> V_34 . V_35 . V_33 ) ;
if ( V_33 ) {
V_20 = V_33 -> V_20 ;
V_19 = F_2 ( V_3 ) ;
V_18 = F_11 ( V_19 , V_31 -> V_34 . V_35 . V_1 ,
V_31 -> V_34 . V_35 . V_8 , V_20 ) ;
}
F_19 () ;
return V_18 ;
}
static inline void F_20 ( struct V_2 * V_19 , T_1 V_1 ,
char * V_10 , int V_20 )
{
F_21 ( & V_19 -> V_29 ) ;
F_10 ( V_19 , V_1 , V_10 , V_20 ) ;
F_22 ( & V_19 -> V_29 ) ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_2 * V_19 ;
int V_12 ;
V_19 = F_2 ( F_24 ( V_33 ) ) ;
F_21 ( & V_19 -> V_29 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ ) {
struct V_18 * V_26 = V_19 -> V_22 [ V_12 ] ;
struct V_37 * V_38 ;
while ( V_26 ) {
while ( V_26 && V_26 -> V_39 != V_33 ) {
V_26 = V_26 -> V_25 ;
}
if ( ! V_26 )
break;
V_38 = F_14 ( V_26 ) ;
F_13 ( V_38 ) ;
F_22 ( & V_19 -> V_29 ) ;
F_25 ( V_38 ) ;
if ( V_26 -> V_39 == V_33 &&
V_38 -> V_40 & ( V_41 | V_42 | V_43 ) ) {
F_26 ( V_38 ) ;
V_38 -> V_40 = V_43 ;
V_38 -> V_44 ( V_38 ) ;
V_26 -> V_39 = NULL ;
F_27 ( V_33 ) ;
}
F_28 ( V_38 ) ;
F_29 ( V_38 ) ;
F_3 ( F_2 ( F_24 ( V_33 ) ) == NULL ) ;
F_21 ( & V_19 -> V_29 ) ;
V_26 = V_19 -> V_22 [ V_12 ] ;
}
}
F_22 ( & V_19 -> V_29 ) ;
}
static int F_30 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
struct V_32 * V_33 = (struct V_32 * ) V_48 ;
switch ( V_47 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_23 ( V_33 ) ;
break;
default:
break;
}
return V_53 ;
}
static int F_31 ( struct V_37 * V_38 , struct V_54 * V_55 )
{
struct V_18 * V_26 = F_32 ( V_38 ) ;
struct V_18 * V_56 ;
if ( V_38 -> V_40 & V_42 ) {
F_33 ( & V_26 -> V_57 , V_55 ) ;
} else if ( V_38 -> V_40 & V_58 ) {
V_56 = F_16 ( F_34 ( V_38 ) ,
& V_26 -> V_59 ) ;
if ( V_56 == NULL )
goto V_60;
if ( ( F_14 ( V_56 ) -> V_40 & V_41 ) == 0 )
goto V_61;
if ( ! F_35 ( F_14 ( V_56 ) , V_55 ) )
goto V_61;
} else {
if ( F_36 ( V_38 , V_55 ) )
goto V_60;
}
return V_62 ;
V_61:
F_29 ( F_14 ( V_56 ) ) ;
V_60:
F_37 ( V_55 ) ;
return V_63 ;
}
static int F_38 ( struct V_54 * V_55 , struct V_32 * V_33 ,
struct V_64 * V_65 , struct V_32 * V_66 )
{
struct V_67 * V_68 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
int V_69 ;
V_55 = F_39 ( V_55 , V_70 ) ;
if ( ! V_55 )
goto V_71;
if ( ! F_40 ( V_55 , sizeof( struct V_67 ) ) )
goto V_72;
V_68 = V_67 ( V_55 ) ;
V_69 = F_41 ( V_68 -> V_73 ) ;
F_42 ( V_55 , sizeof( * V_68 ) ) ;
if ( V_55 -> V_69 < V_69 )
goto V_72;
if ( F_43 ( V_55 , V_69 ) )
goto V_72;
V_19 = F_2 ( F_24 ( V_33 ) ) ;
V_26 = F_11 ( V_19 , V_68 -> V_1 , F_44 ( V_55 ) -> V_74 , V_33 -> V_20 ) ;
if ( ! V_26 )
goto V_72;
return F_45 ( F_14 ( V_26 ) , V_55 , 0 ) ;
V_72:
F_37 ( V_55 ) ;
V_71:
return V_63 ;
}
static int F_46 ( struct V_54 * V_55 , struct V_32 * V_33 ,
struct V_64 * V_65 , struct V_32 * V_66 )
{
struct V_67 * V_68 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
V_55 = F_39 ( V_55 , V_70 ) ;
if ( ! V_55 )
goto V_71;
if ( ! F_40 ( V_55 , sizeof( struct V_67 ) ) )
goto abort;
V_68 = V_67 ( V_55 ) ;
if ( V_68 -> V_75 != V_76 )
goto abort;
V_19 = F_2 ( F_24 ( V_33 ) ) ;
V_26 = F_11 ( V_19 , V_68 -> V_1 , F_44 ( V_55 ) -> V_74 , V_33 -> V_20 ) ;
if ( V_26 ) {
struct V_37 * V_38 = F_14 ( V_26 ) ;
F_47 ( V_38 ) ;
if ( F_48 ( V_38 ) == 0 ) {
V_38 -> V_40 = V_43 ;
}
F_49 ( V_38 ) ;
F_29 ( V_38 ) ;
}
abort:
F_37 ( V_55 ) ;
V_71:
return V_62 ;
}
static int F_50 ( struct V_3 * V_3 , struct V_77 * V_37 )
{
struct V_37 * V_38 ;
V_38 = F_51 ( V_3 , V_78 , V_79 , & V_80 ) ;
if ( ! V_38 )
return - V_81 ;
F_52 ( V_37 , V_38 ) ;
V_37 -> V_82 = V_83 ;
V_37 -> V_84 = & V_85 ;
V_38 -> V_86 = F_31 ;
V_38 -> V_40 = V_87 ;
V_38 -> V_88 = V_89 ;
V_38 -> V_90 = V_78 ;
V_38 -> V_91 = V_92 ;
return 0 ;
}
static int F_53 ( struct V_77 * V_37 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 ;
struct V_2 * V_19 ;
struct V_3 * V_3 = NULL ;
if ( ! V_38 )
return 0 ;
F_25 ( V_38 ) ;
if ( F_54 ( V_38 , V_93 ) ) {
F_28 ( V_38 ) ;
return - V_94 ;
}
V_26 = F_32 ( V_38 ) ;
if ( V_38 -> V_40 & ( V_41 | V_42 | V_43 ) ) {
F_27 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
F_26 ( V_38 ) ;
V_38 -> V_40 = V_95 ;
V_3 = F_34 ( V_38 ) ;
V_19 = F_2 ( V_3 ) ;
F_20 ( V_19 , V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ,
V_26 -> V_24 ) ;
F_55 ( V_38 ) ;
V_37 -> V_38 = NULL ;
F_56 ( & V_38 -> V_96 ) ;
F_28 ( V_38 ) ;
F_29 ( V_38 ) ;
return 0 ;
}
static int F_57 ( struct V_77 * V_37 , struct V_97 * V_98 ,
int V_99 , int V_100 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_30 * V_31 = (struct V_30 * ) V_98 ;
struct V_18 * V_26 = F_32 ( V_38 ) ;
struct V_32 * V_33 = NULL ;
struct V_2 * V_19 ;
struct V_3 * V_3 = NULL ;
int error ;
F_25 ( V_38 ) ;
error = - V_101 ;
if ( V_31 -> V_102 != V_92 )
goto V_103;
error = - V_104 ;
if ( ( V_38 -> V_40 & V_41 ) &&
F_1 ( V_31 -> V_34 . V_35 . V_1 ) )
goto V_103;
error = - V_27 ;
if ( ( V_38 -> V_40 & V_95 ) &&
! F_1 ( V_31 -> V_34 . V_35 . V_1 ) )
goto V_103;
error = 0 ;
if ( F_1 ( V_26 -> V_23 . V_1 ) ) {
F_26 ( V_38 ) ;
V_19 = F_2 ( F_34 ( V_38 ) ) ;
F_20 ( V_19 , V_26 -> V_23 . V_1 ,
V_26 -> V_23 . V_8 , V_26 -> V_24 ) ;
if ( V_26 -> V_39 ) {
F_27 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
memset ( F_14 ( V_26 ) + 1 , 0 ,
sizeof( struct V_18 ) - sizeof( struct V_37 ) ) ;
V_38 -> V_40 = V_87 ;
}
if ( F_1 ( V_31 -> V_34 . V_35 . V_1 ) ) {
error = - V_105 ;
V_3 = F_34 ( V_38 ) ;
V_33 = F_58 ( V_3 , V_31 -> V_34 . V_35 . V_33 ) ;
if ( ! V_33 )
goto V_106;
V_26 -> V_39 = V_33 ;
V_26 -> V_24 = V_33 -> V_20 ;
V_19 = F_2 ( V_3 ) ;
if ( ! ( V_33 -> V_100 & V_107 ) ) {
goto V_106;
}
memcpy ( & V_26 -> V_23 ,
& V_31 -> V_34 . V_35 ,
sizeof( struct V_5 ) ) ;
F_21 ( & V_19 -> V_29 ) ;
error = F_9 ( V_19 , V_26 ) ;
F_22 ( & V_19 -> V_29 ) ;
if ( error < 0 )
goto V_106;
V_26 -> V_57 . V_108 = ( sizeof( struct V_67 ) +
V_33 -> V_109 ) ;
V_26 -> V_57 . V_110 = V_33 -> V_110 - sizeof( struct V_67 ) ;
V_26 -> V_57 . V_111 = V_38 ;
V_26 -> V_57 . V_84 = & V_112 ;
error = F_59 ( F_24 ( V_33 ) , & V_26 -> V_57 ) ;
if ( error ) {
F_20 ( V_19 , V_26 -> V_23 . V_1 ,
V_26 -> V_23 . V_8 , V_26 -> V_24 ) ;
goto V_106;
}
V_38 -> V_40 = V_41 ;
}
V_26 -> V_113 = V_31 -> V_34 . V_35 . V_1 ;
V_103:
F_28 ( V_38 ) ;
return error ;
V_106:
if ( V_26 -> V_39 ) {
F_27 ( V_26 -> V_39 ) ;
V_26 -> V_39 = NULL ;
}
goto V_103;
}
static int F_60 ( struct V_77 * V_37 , struct V_97 * V_114 ,
int * V_115 , int V_116 )
{
int V_69 = sizeof( struct V_30 ) ;
struct V_30 V_31 ;
V_31 . V_117 = V_118 ;
V_31 . V_102 = V_92 ;
memcpy ( & V_31 . V_34 . V_35 , & F_32 ( V_37 -> V_38 ) -> V_23 ,
sizeof( struct V_5 ) ) ;
memcpy ( V_114 , & V_31 , V_69 ) ;
* V_115 = V_69 ;
return 0 ;
}
static int F_61 ( struct V_77 * V_37 , unsigned int V_119 ,
unsigned long V_120 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 = F_32 ( V_38 ) ;
int V_121 ;
int V_122 ;
switch ( V_119 ) {
case V_123 :
V_122 = - V_124 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_122 = - V_125 ;
if ( F_62 ( V_26 -> V_39 -> V_110 -
sizeof( struct V_67 ) -
V_126 ,
( int V_127 * ) V_120 ) )
break;
V_122 = 0 ;
break;
case V_128 :
V_122 = - V_124 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_122 = - V_125 ;
if ( F_63 ( V_121 , ( int V_127 * ) V_120 ) )
break;
if ( V_121 < ( V_26 -> V_39 -> V_110
- sizeof( struct V_67 )
- V_126 ) )
V_122 = 0 ;
else
V_122 = - V_101 ;
break;
case V_129 :
V_122 = - V_125 ;
if ( F_63 ( V_121 , ( int V_127 * ) V_120 ) )
break;
V_122 = 0 ;
break;
case V_130 :
{
struct V_18 * V_56 ;
V_122 = - V_104 ;
if ( V_38 -> V_40 & ( V_42 | V_43 | V_95 ) )
break;
V_122 = - V_131 ;
if ( ! ( V_38 -> V_40 & V_41 ) )
break;
V_122 = - V_125 ;
if ( F_64 ( & V_26 -> V_59 ,
( void V_127 * ) V_120 ,
sizeof( struct V_30 ) ) )
break;
V_122 = - V_101 ;
if ( V_26 -> V_59 . V_117 != V_118 ||
V_26 -> V_59 . V_102 != V_92 )
break;
V_56 = F_16 ( F_34 ( V_38 ) , & V_26 -> V_59 ) ;
if ( ! V_56 )
break;
F_29 ( F_14 ( V_56 ) ) ;
V_38 -> V_40 |= V_58 ;
V_122 = 0 ;
break;
}
case V_132 :
V_122 = - V_27 ;
if ( ! ( V_38 -> V_40 & V_58 ) )
break;
V_38 -> V_40 &= ~ V_58 ;
V_122 = 0 ;
break;
default:
V_122 = - V_133 ;
}
return V_122 ;
}
static int F_65 ( struct V_134 * V_135 , struct V_77 * V_37 ,
struct V_136 * V_137 , T_2 V_138 )
{
struct V_54 * V_55 ;
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_18 * V_26 = F_32 ( V_38 ) ;
int error ;
struct V_67 V_139 ;
struct V_67 * V_68 ;
struct V_32 * V_33 ;
char * V_140 ;
F_25 ( V_38 ) ;
if ( F_54 ( V_38 , V_93 ) || ! ( V_38 -> V_40 & V_41 ) ) {
error = - V_131 ;
goto V_103;
}
V_139 . V_141 = 1 ;
V_139 . type = 1 ;
V_139 . V_75 = 0 ;
V_139 . V_1 = V_26 -> V_113 ;
V_33 = V_26 -> V_39 ;
error = - V_142 ;
if ( V_138 > ( V_33 -> V_110 + V_33 -> V_109 ) )
goto V_103;
V_55 = F_66 ( V_38 , V_138 + V_33 -> V_109 + 32 ,
0 , V_79 ) ;
if ( ! V_55 ) {
error = - V_81 ;
goto V_103;
}
F_67 ( V_55 , V_33 -> V_109 ) ;
F_68 ( V_55 ) ;
V_55 -> V_33 = V_33 ;
V_55 -> V_143 = V_38 -> V_144 ;
V_55 -> V_145 = F_69 ( V_146 ) ;
V_68 = (struct V_67 * ) F_70 ( V_55 , V_138 + sizeof( struct V_67 ) ) ;
V_140 = ( char * ) & V_68 -> V_147 [ 0 ] ;
error = F_71 ( V_140 , V_137 -> V_148 , V_138 ) ;
if ( error < 0 ) {
F_37 ( V_55 ) ;
goto V_103;
}
error = V_138 ;
F_72 ( V_55 , V_33 , V_146 ,
V_26 -> V_23 . V_8 , NULL , V_138 ) ;
memcpy ( V_68 , & V_139 , sizeof( struct V_67 ) ) ;
V_68 -> V_73 = F_73 ( V_138 ) ;
F_74 ( V_55 ) ;
V_103:
F_28 ( V_38 ) ;
return error ;
}
static int F_35 ( struct V_37 * V_38 , struct V_54 * V_55 )
{
struct V_18 * V_26 = F_32 ( V_38 ) ;
struct V_32 * V_33 = V_26 -> V_39 ;
struct V_67 * V_68 ;
int V_149 = V_55 -> V_69 ;
if ( F_54 ( V_38 , V_93 ) || ! ( V_38 -> V_40 & V_41 ) )
goto abort;
if ( ! V_33 )
goto abort;
if ( F_75 ( V_55 , sizeof( * V_68 ) + V_33 -> V_109 ) )
goto abort;
F_76 ( V_55 , sizeof( * V_68 ) ) ;
F_68 ( V_55 ) ;
V_68 = V_67 ( V_55 ) ;
V_68 -> V_141 = 1 ;
V_68 -> type = 1 ;
V_68 -> V_75 = 0 ;
V_68 -> V_1 = V_26 -> V_113 ;
V_68 -> V_73 = F_73 ( V_149 ) ;
V_55 -> V_145 = F_69 ( V_146 ) ;
V_55 -> V_33 = V_33 ;
F_72 ( V_55 , V_33 , V_146 ,
V_26 -> V_23 . V_8 , NULL , V_149 ) ;
F_74 ( V_55 ) ;
return 1 ;
abort:
F_37 ( V_55 ) ;
return 1 ;
}
static int F_77 ( struct V_150 * V_57 , struct V_54 * V_55 )
{
struct V_37 * V_38 = (struct V_37 * ) V_57 -> V_111 ;
return F_35 ( V_38 , V_55 ) ;
}
static int F_78 ( struct V_134 * V_135 , struct V_77 * V_37 ,
struct V_136 * V_137 , T_2 V_138 , int V_100 )
{
struct V_37 * V_38 = V_37 -> V_38 ;
struct V_54 * V_55 ;
int error = 0 ;
if ( V_38 -> V_40 & V_42 ) {
error = - V_151 ;
goto V_103;
}
V_55 = F_79 ( V_38 , V_100 & ~ V_152 ,
V_100 & V_152 , & error ) ;
if ( error < 0 )
goto V_103;
V_137 -> V_153 = 0 ;
if ( V_55 ) {
V_138 = F_80 ( T_2 , V_138 , V_55 -> V_69 ) ;
error = F_81 ( V_55 , 0 , V_137 -> V_148 , V_138 ) ;
if ( error == 0 ) {
F_82 ( V_55 ) ;
return V_138 ;
}
}
F_37 ( V_55 ) ;
V_103:
return error ;
}
static int F_83 ( struct V_154 * V_155 , void * V_156 )
{
struct V_18 * V_26 ;
char * V_157 ;
if ( V_156 == V_158 ) {
F_84 ( V_155 , L_1 ) ;
goto V_71;
}
V_26 = V_156 ;
V_157 = V_26 -> V_23 . V_33 ;
F_85 ( V_155 , L_2 ,
V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 , V_157 ) ;
V_71:
return 0 ;
}
static inline struct V_18 * F_86 ( struct V_2 * V_19 , T_3 V_159 )
{
struct V_18 * V_26 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ ) {
V_26 = V_19 -> V_22 [ V_12 ] ;
while ( V_26 ) {
if ( ! V_159 -- )
goto V_71;
V_26 = V_26 -> V_25 ;
}
}
V_71:
return V_26 ;
}
static void * F_87 ( struct V_154 * V_155 , T_3 * V_159 )
__acquires( V_19 -> V_29 )
{
struct V_2 * V_19 = F_2 ( F_88 ( V_155 ) ) ;
T_3 V_160 = * V_159 ;
F_12 ( & V_19 -> V_29 ) ;
return V_160 ? F_86 ( V_19 , -- V_160 ) : V_158 ;
}
static void * F_89 ( struct V_154 * V_155 , void * V_156 , T_3 * V_159 )
{
struct V_2 * V_19 = F_2 ( F_88 ( V_155 ) ) ;
struct V_18 * V_26 ;
++ * V_159 ;
if ( V_156 == V_158 ) {
V_26 = F_86 ( V_19 , 0 ) ;
goto V_71;
}
V_26 = V_156 ;
if ( V_26 -> V_25 )
V_26 = V_26 -> V_25 ;
else {
int V_11 = F_7 ( V_26 -> V_23 . V_1 , V_26 -> V_23 . V_8 ) ;
V_26 = NULL ;
while ( ++ V_11 < V_36 ) {
V_26 = V_19 -> V_22 [ V_11 ] ;
if ( V_26 )
break;
}
}
V_71:
return V_26 ;
}
static void F_90 ( struct V_154 * V_155 , void * V_156 )
__releases( V_19 -> V_29 )
{
struct V_2 * V_19 = F_2 ( F_88 ( V_155 ) ) ;
F_15 ( & V_19 -> V_29 ) ;
}
static int F_91 ( struct V_161 * V_161 , struct V_162 * V_162 )
{
return F_92 ( V_161 , V_162 , & V_163 ,
sizeof( struct V_164 ) ) ;
}
static T_4 int F_93 ( struct V_3 * V_3 )
{
struct V_2 * V_19 = F_2 ( V_3 ) ;
struct V_165 * V_166 ;
F_94 ( & V_19 -> V_29 ) ;
V_166 = F_95 ( L_3 , V_167 , V_3 -> V_168 , & V_169 ) ;
#ifdef F_96
if ( ! V_166 )
return - V_81 ;
#endif
return 0 ;
}
static T_5 void F_97 ( struct V_3 * V_3 )
{
F_98 ( L_3 , V_3 -> V_168 ) ;
}
static int T_6 F_99 ( void )
{
int V_122 ;
V_122 = F_100 ( & V_170 ) ;
if ( V_122 )
goto V_71;
V_122 = F_101 ( & V_80 , 0 ) ;
if ( V_122 )
goto V_171;
V_122 = F_102 ( V_92 , & V_172 ) ;
if ( V_122 )
goto V_173;
F_103 ( & V_174 ) ;
F_103 ( & V_175 ) ;
F_104 ( & V_176 ) ;
return 0 ;
V_173:
F_105 ( & V_80 ) ;
V_171:
F_106 ( & V_170 ) ;
V_71:
return V_122 ;
}
static void T_7 F_107 ( void )
{
F_108 ( & V_176 ) ;
F_109 ( & V_175 ) ;
F_109 ( & V_174 ) ;
F_110 ( V_92 ) ;
F_105 ( & V_80 ) ;
F_106 ( & V_170 ) ;
}
