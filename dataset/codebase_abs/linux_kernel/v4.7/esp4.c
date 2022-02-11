static void * F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
unsigned int V_5 ;
V_5 = V_4 ;
V_5 += F_2 ( V_2 ) ;
if ( V_5 ) {
V_5 += F_3 ( V_2 ) &
~ ( F_4 () - 1 ) ;
V_5 = F_5 ( V_5 , F_4 () ) ;
}
V_5 += sizeof( struct V_6 ) + F_6 ( V_2 ) ;
V_5 = F_5 ( V_5 , F_7 ( struct V_7 ) ) ;
V_5 += sizeof( struct V_7 ) * V_3 ;
return F_8 ( V_5 , V_8 ) ;
}
static inline void * F_9 ( void * V_9 )
{
return F_10 ( V_9 , F_7 ( struct V_10 ) ) ;
}
static inline T_1 * F_11 ( struct V_1 * V_2 , void * V_9 , int V_4 )
{
return F_2 ( V_2 ) ?
F_10 ( ( T_1 * ) V_9 + V_4 ,
F_3 ( V_2 ) + 1 ) : V_9 + V_4 ;
}
static inline struct V_6 * F_12 ( struct V_1 * V_2 , T_1 * V_11 )
{
struct V_6 * V_12 ;
V_12 = ( void * ) F_10 ( V_11 + F_2 ( V_2 ) ,
F_4 () ) ;
F_13 ( V_12 , V_2 ) ;
return V_12 ;
}
static inline struct V_7 * F_14 ( struct V_1 * V_2 ,
struct V_6 * V_12 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_12 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static void F_15 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_16 ( F_17 ( V_17 ) -> V_9 ) ;
F_18 ( V_17 , V_15 ) ;
}
static void F_19 ( struct V_16 * V_17 , unsigned int V_19 )
{
struct V_20 * V_21 = ( void * ) ( V_17 -> V_18 + V_19 ) ;
void * V_9 = F_17 ( V_17 ) -> V_9 ;
T_2 * V_22 = F_9 ( V_9 ) ;
V_21 -> V_23 = V_21 -> V_24 ;
V_21 -> V_24 = * V_22 ;
}
static void F_20 ( struct V_16 * V_17 )
{
void * V_9 = F_17 ( V_17 ) -> V_9 ;
struct V_10 * V_25 = F_9 ( V_9 ) ;
F_19 ( V_17 , F_21 ( V_17 ) + V_25 -> V_26 -
sizeof( T_2 ) ) ;
}
static void F_22 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_20 ( V_17 ) ;
F_15 ( V_14 , V_15 ) ;
}
static int F_23 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
int V_15 ;
struct V_10 * V_25 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_29 ;
struct V_16 * V_30 ;
void * V_9 ;
T_1 * V_11 ;
T_1 * V_31 ;
int V_32 ;
int V_33 ;
int V_34 ;
int V_35 ;
int V_36 ;
int V_37 ;
int V_3 ;
int V_38 ;
int V_4 ;
T_3 V_39 ;
V_2 = V_28 -> V_18 ;
V_34 = F_24 ( V_2 ) ;
V_36 = F_2 ( V_2 ) ;
V_37 = 0 ;
if ( V_28 -> V_40 ) {
struct V_41 * V_42 = (struct V_41 * ) F_25 ( V_17 ) ;
T_4 V_43 ;
V_43 = F_26 ( V_28 -> V_40 , F_27 ( V_28 , V_42 -> V_44 ) ) ;
if ( V_17 -> V_5 < V_43 )
V_37 = V_43 - V_17 -> V_5 ;
}
V_32 = F_5 ( F_28 ( V_2 ) , 4 ) ;
V_33 = F_5 ( V_17 -> V_5 + 2 + V_37 , V_32 ) ;
V_35 = V_33 - V_17 -> V_5 - V_37 ;
V_15 = F_29 ( V_17 , V_37 + V_35 + V_34 , & V_30 ) ;
if ( V_15 < 0 )
goto error;
V_3 = V_15 ;
V_38 = sizeof( * V_21 ) ;
V_4 = 0 ;
if ( V_28 -> V_45 . V_46 & V_47 ) {
V_4 += sizeof( * V_25 ) ;
V_38 += sizeof( T_2 ) ;
}
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_9 ) {
V_15 = - V_48 ;
goto error;
}
V_25 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_4 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_29 = F_14 ( V_2 , V_12 ) ;
V_31 = F_30 ( V_30 ) ;
if ( V_37 ) {
memset ( V_31 , 0 , V_37 ) ;
V_31 += V_37 ;
}
do {
int V_49 ;
for ( V_49 = 0 ; V_49 < V_35 - 2 ; V_49 ++ )
V_31 [ V_49 ] = V_49 + 1 ;
} while ( 0 );
V_31 [ V_35 - 2 ] = V_35 - 2 ;
V_31 [ V_35 - 1 ] = * F_31 ( V_17 ) ;
F_32 ( V_17 , V_30 , V_33 - V_17 -> V_5 + V_34 ) ;
F_33 ( V_17 , - F_34 ( V_17 ) ) ;
V_21 = V_20 ( V_17 ) ;
* F_31 ( V_17 ) = V_50 ;
if ( V_28 -> V_51 ) {
struct V_52 * V_51 = V_28 -> V_51 ;
struct V_53 * V_54 ;
T_2 * V_55 ;
T_5 V_56 , V_57 ;
int V_58 ;
F_35 ( & V_28 -> V_59 ) ;
V_56 = V_51 -> V_60 ;
V_57 = V_51 -> V_61 ;
V_58 = V_51 -> V_58 ;
F_36 ( & V_28 -> V_59 ) ;
V_54 = (struct V_53 * ) V_21 ;
V_54 -> V_62 = V_56 ;
V_54 -> V_63 = V_57 ;
V_54 -> V_5 = F_37 ( V_17 -> V_5 - F_21 ( V_17 ) ) ;
V_54 -> V_64 = 0 ;
switch ( V_58 ) {
default:
case V_65 :
V_21 = (struct V_20 * ) ( V_54 + 1 ) ;
break;
case V_66 :
V_55 = ( T_2 * ) ( V_54 + 1 ) ;
V_55 [ 0 ] = V_55 [ 1 ] = 0 ;
V_21 = (struct V_20 * ) ( V_55 + 2 ) ;
break;
}
* F_31 ( V_17 ) = V_67 ;
}
V_21 -> V_23 = F_38 ( F_39 ( V_17 ) -> V_68 . V_69 . V_70 ) ;
F_40 ( V_12 , 0 , F_15 , V_17 ) ;
if ( ( V_28 -> V_45 . V_46 & V_47 ) ) {
V_25 -> V_26 = ( unsigned char * ) V_21 -
F_41 ( V_17 ) ;
V_21 = (struct V_20 * ) ( ( unsigned char * ) V_21 - 4 ) ;
V_25 -> V_22 = V_21 -> V_24 ;
V_21 -> V_23 = F_38 ( F_39 ( V_17 ) -> V_68 . V_69 . V_71 ) ;
F_40 ( V_12 , 0 , F_22 , V_17 ) ;
}
V_21 -> V_24 = V_28 -> V_72 . V_24 ;
F_42 ( V_29 , V_3 ) ;
F_43 ( V_17 , V_29 ,
( unsigned char * ) V_21 - V_17 -> V_18 ,
V_38 + V_36 + V_33 + V_34 ) ;
F_44 ( V_12 , V_29 , V_29 , V_36 + V_33 , V_11 ) ;
F_45 ( V_12 , V_38 ) ;
V_39 = F_46 ( F_39 ( V_17 ) -> V_68 . V_69 . V_70 +
( ( V_73 ) F_39 ( V_17 ) -> V_68 . V_69 . V_71 << 32 ) ) ;
memset ( V_11 , 0 , V_36 ) ;
memcpy ( V_11 + V_36 - F_26 ( V_36 , 8 ) , ( T_1 * ) & V_39 + 8 - F_26 ( V_36 , 8 ) ,
F_26 ( V_36 , 8 ) ) ;
F_17 ( V_17 ) -> V_9 = V_9 ;
V_15 = F_47 ( V_12 ) ;
switch ( V_15 ) {
case - V_74 :
goto error;
case - V_75 :
V_15 = V_76 ;
break;
case 0 :
if ( ( V_28 -> V_45 . V_46 & V_47 ) )
F_20 ( V_17 ) ;
}
F_16 ( V_9 ) ;
error:
return V_15 ;
}
static int F_48 ( struct V_16 * V_17 , int V_15 )
{
const struct V_77 * V_78 ;
struct V_27 * V_28 = F_49 ( V_17 ) ;
struct V_1 * V_2 = V_28 -> V_18 ;
int V_34 = F_24 ( V_2 ) ;
int V_79 = sizeof( struct V_20 ) + F_2 ( V_2 ) ;
int V_80 = V_17 -> V_5 - V_79 ;
int V_81 ;
T_1 V_82 [ 2 ] ;
int V_83 ;
F_16 ( F_17 ( V_17 ) -> V_9 ) ;
if ( F_50 ( V_15 ) )
goto V_84;
if ( F_51 ( V_17 , V_17 -> V_5 - V_34 - 2 , V_82 , 2 ) )
F_52 () ;
V_15 = - V_85 ;
V_83 = V_82 [ 0 ] ;
if ( V_83 + 2 + V_34 >= V_80 )
goto V_84;
V_78 = F_53 ( V_17 ) ;
V_81 = V_78 -> V_81 * 4 ;
if ( V_28 -> V_51 ) {
struct V_52 * V_51 = V_28 -> V_51 ;
struct V_53 * V_54 = ( void * ) ( F_54 ( V_17 ) + V_81 ) ;
if ( V_78 -> V_86 != V_28 -> V_45 . V_86 . V_87 ||
V_54 -> V_62 != V_51 -> V_60 ) {
T_6 V_88 ;
V_88 . V_87 = V_78 -> V_86 ;
F_55 ( V_28 , & V_88 , V_54 -> V_62 ) ;
}
if ( V_28 -> V_45 . V_89 == V_90 )
V_17 -> V_91 = V_92 ;
}
F_56 ( V_17 , V_17 -> V_5 - V_34 - V_83 - 2 ) ;
F_57 ( V_17 , V_79 ) ;
if ( V_28 -> V_45 . V_89 == V_93 )
F_58 ( V_17 ) ;
else
F_59 ( V_17 , - V_81 ) ;
V_15 = V_82 [ 1 ] ;
if ( V_15 == V_94 )
V_15 = - V_85 ;
V_84:
return V_15 ;
}
static void F_60 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_61 ( V_17 , F_48 ( V_17 , V_15 ) ) ;
}
static void F_62 ( struct V_16 * V_17 )
{
F_19 ( V_17 , 0 ) ;
F_57 ( V_17 , 4 ) ;
}
static void F_63 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_62 ( V_17 ) ;
F_60 ( V_14 , V_15 ) ;
}
static int F_64 ( struct V_27 * V_28 , struct V_16 * V_17 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 = V_28 -> V_18 ;
struct V_6 * V_12 ;
struct V_16 * V_30 ;
int V_36 = F_2 ( V_2 ) ;
int V_80 = V_17 -> V_5 - sizeof( * V_21 ) - V_36 ;
int V_3 ;
int V_38 ;
int V_95 ;
T_2 * V_22 ;
void * V_9 ;
T_1 * V_11 ;
struct V_7 * V_29 ;
int V_15 = - V_85 ;
if ( ! F_65 ( V_17 , sizeof( * V_21 ) + V_36 ) )
goto V_84;
if ( V_80 <= 0 )
goto V_84;
V_15 = F_29 ( V_17 , 0 , & V_30 ) ;
if ( V_15 < 0 )
goto V_84;
V_3 = V_15 ;
V_38 = sizeof( * V_21 ) ;
V_95 = 0 ;
if ( V_28 -> V_45 . V_46 & V_47 ) {
V_95 += sizeof( T_2 ) ;
V_38 += V_95 ;
}
V_15 = - V_48 ;
V_9 = F_1 ( V_2 , V_3 , V_95 ) ;
if ( ! V_9 )
goto V_84;
F_17 ( V_17 ) -> V_9 = V_9 ;
V_22 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_95 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_29 = F_14 ( V_2 , V_12 ) ;
V_17 -> V_91 = V_96 ;
V_21 = (struct V_20 * ) V_17 -> V_18 ;
F_40 ( V_12 , 0 , F_60 , V_17 ) ;
if ( ( V_28 -> V_45 . V_46 & V_47 ) ) {
V_21 = ( void * ) F_33 ( V_17 , 4 ) ;
* V_22 = V_21 -> V_24 ;
V_21 -> V_24 = V_21 -> V_23 ;
V_21 -> V_23 = F_38 ( F_39 ( V_17 ) -> V_68 . V_97 . V_71 ) ;
F_40 ( V_12 , 0 , F_63 , V_17 ) ;
}
F_42 ( V_29 , V_3 ) ;
F_43 ( V_17 , V_29 , 0 , V_17 -> V_5 ) ;
F_44 ( V_12 , V_29 , V_29 , V_80 + V_36 , V_11 ) ;
F_45 ( V_12 , V_38 ) ;
V_15 = F_66 ( V_12 ) ;
if ( V_15 == - V_74 )
goto V_84;
if ( ( V_28 -> V_45 . V_46 & V_47 ) )
F_62 ( V_17 ) ;
V_15 = F_48 ( V_17 , V_15 ) ;
V_84:
return V_15 ;
}
static T_4 F_27 ( struct V_27 * V_28 , int V_98 )
{
struct V_1 * V_2 = V_28 -> V_18 ;
T_4 V_32 = F_5 ( F_28 ( V_2 ) , 4 ) ;
unsigned int V_99 ;
switch ( V_28 -> V_45 . V_89 ) {
case V_90 :
case V_100 :
V_99 = sizeof( struct V_77 ) ;
break;
case V_93 :
V_99 = 0 ;
break;
default:
F_52 () ;
}
return ( ( V_98 - V_28 -> V_45 . V_101 - F_24 ( V_2 ) -
V_99 ) & ~ ( V_32 - 1 ) ) + V_99 - 2 ;
}
static int F_67 ( struct V_16 * V_17 , T_4 V_102 )
{
struct V_103 * V_103 = F_68 ( V_17 -> V_104 ) ;
const struct V_77 * V_78 = ( const struct V_77 * ) V_17 -> V_18 ;
struct V_20 * V_21 = (struct V_20 * ) ( V_17 -> V_18 + ( V_78 -> V_81 << 2 ) ) ;
struct V_27 * V_28 ;
switch ( F_69 ( V_17 ) -> type ) {
case V_105 :
if ( F_69 ( V_17 ) -> V_106 != V_107 )
return 0 ;
case V_108 :
break;
default:
return 0 ;
}
V_28 = F_70 ( V_103 , V_17 -> V_109 , ( const T_6 * ) & V_78 -> V_110 ,
V_21 -> V_24 , V_50 , V_111 ) ;
if ( ! V_28 )
return 0 ;
if ( F_69 ( V_17 ) -> type == V_105 )
F_71 ( V_17 , V_103 , V_102 , 0 , 0 , V_50 , 0 ) ;
else
F_72 ( V_17 , V_103 , 0 , 0 , V_50 , 0 ) ;
F_73 ( V_28 ) ;
return 0 ;
}
static void F_74 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_18 ;
if ( ! V_2 )
return;
F_75 ( V_2 ) ;
}
static int F_76 ( struct V_27 * V_28 )
{
char V_112 [ V_113 ] ;
struct V_1 * V_2 ;
int V_15 ;
V_15 = - V_114 ;
if ( snprintf ( V_112 , V_113 , L_1 ,
V_28 -> V_115 , V_28 -> V_2 -> V_116 ) >= V_113 )
goto error;
V_2 = F_77 ( V_112 , 0 , 0 ) ;
V_15 = F_78 ( V_2 ) ;
if ( F_79 ( V_2 ) )
goto error;
V_28 -> V_18 = V_2 ;
V_15 = F_80 ( V_2 , V_28 -> V_2 -> V_117 ,
( V_28 -> V_2 -> V_118 + 7 ) / 8 ) ;
if ( V_15 )
goto error;
V_15 = F_81 ( V_2 , V_28 -> V_2 -> V_119 / 8 ) ;
if ( V_15 )
goto error;
error:
return V_15 ;
}
static int F_82 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
char * V_124 ;
char * V_125 ;
char V_126 [ V_113 ] ;
unsigned int V_127 ;
int V_15 ;
V_15 = - V_85 ;
if ( ! V_28 -> V_128 )
goto error;
V_15 = - V_114 ;
if ( ( V_28 -> V_45 . V_46 & V_47 ) ) {
if ( snprintf ( V_126 , V_113 ,
L_2 ,
V_28 -> V_115 ? : L_3 , V_28 -> V_115 ? L_4 : L_3 ,
V_28 -> V_129 ? V_28 -> V_129 -> V_116 : L_5 ,
V_28 -> V_128 -> V_116 ,
V_28 -> V_115 ? L_6 : L_3 ) >= V_113 )
goto error;
} else {
if ( snprintf ( V_126 , V_113 ,
L_7 ,
V_28 -> V_115 ? : L_3 , V_28 -> V_115 ? L_4 : L_3 ,
V_28 -> V_129 ? V_28 -> V_129 -> V_116 : L_5 ,
V_28 -> V_128 -> V_116 ,
V_28 -> V_115 ? L_6 : L_3 ) >= V_113 )
goto error;
}
V_2 = F_77 ( V_126 , 0 , 0 ) ;
V_15 = F_78 ( V_2 ) ;
if ( F_79 ( V_2 ) )
goto error;
V_28 -> V_18 = V_2 ;
V_127 = ( V_28 -> V_129 ? ( V_28 -> V_129 -> V_118 + 7 ) / 8 : 0 ) +
( V_28 -> V_128 -> V_118 + 7 ) / 8 + F_83 ( sizeof( * V_121 ) ) ;
V_15 = - V_48 ;
V_124 = F_8 ( V_127 , V_130 ) ;
if ( ! V_124 )
goto error;
V_125 = V_124 ;
V_123 = ( void * ) V_125 ;
V_123 -> V_131 = V_132 ;
V_123 -> V_133 = F_84 ( sizeof( * V_121 ) ) ;
V_121 = F_85 ( V_123 ) ;
V_125 += F_83 ( sizeof( * V_121 ) ) ;
if ( V_28 -> V_129 ) {
struct V_134 * V_135 ;
memcpy ( V_125 , V_28 -> V_129 -> V_117 , ( V_28 -> V_129 -> V_118 + 7 ) / 8 ) ;
V_125 += ( V_28 -> V_129 -> V_118 + 7 ) / 8 ;
V_135 = F_86 ( V_28 -> V_129 -> V_116 , 0 ) ;
F_87 ( ! V_135 ) ;
V_15 = - V_85 ;
if ( V_135 -> V_136 . V_137 . V_138 / 8 !=
F_24 ( V_2 ) ) {
F_88 ( L_8 ,
V_28 -> V_129 -> V_116 ,
F_24 ( V_2 ) ,
V_135 -> V_136 . V_137 . V_138 / 8 ) ;
goto V_139;
}
V_15 = F_81 (
V_2 , V_28 -> V_129 -> V_140 / 8 ) ;
if ( V_15 )
goto V_139;
}
V_121 -> V_141 = F_89 ( ( V_28 -> V_128 -> V_118 + 7 ) / 8 ) ;
memcpy ( V_125 , V_28 -> V_128 -> V_117 , ( V_28 -> V_128 -> V_118 + 7 ) / 8 ) ;
V_15 = F_80 ( V_2 , V_124 , V_127 ) ;
V_139:
F_16 ( V_124 ) ;
error:
return V_15 ;
}
static int F_90 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
T_4 V_142 ;
int V_15 ;
V_28 -> V_18 = NULL ;
if ( V_28 -> V_2 )
V_15 = F_76 ( V_28 ) ;
else
V_15 = F_82 ( V_28 ) ;
if ( V_15 )
goto error;
V_2 = V_28 -> V_18 ;
V_28 -> V_45 . V_101 = sizeof( struct V_20 ) +
F_2 ( V_2 ) ;
if ( V_28 -> V_45 . V_89 == V_93 )
V_28 -> V_45 . V_101 += sizeof( struct V_77 ) ;
else if ( V_28 -> V_45 . V_89 == V_100 && V_28 -> V_143 . V_144 != V_145 )
V_28 -> V_45 . V_101 += V_146 ;
if ( V_28 -> V_51 ) {
struct V_52 * V_51 = V_28 -> V_51 ;
switch ( V_51 -> V_58 ) {
default:
goto error;
case V_65 :
V_28 -> V_45 . V_101 += sizeof( struct V_53 ) ;
break;
case V_66 :
V_28 -> V_45 . V_101 += sizeof( struct V_53 ) + 2 * sizeof( T_4 ) ;
break;
}
}
V_142 = F_5 ( F_28 ( V_2 ) , 4 ) ;
V_28 -> V_45 . V_147 = V_142 + 1 + F_24 ( V_2 ) ;
error:
return V_15 ;
}
static int F_91 ( struct V_16 * V_17 , int V_15 )
{
return 0 ;
}
static int T_7 F_92 ( void )
{
if ( F_93 ( & V_148 , V_111 ) < 0 ) {
F_88 ( L_9 , V_149 ) ;
return - V_150 ;
}
if ( F_94 ( & V_151 , V_50 ) < 0 ) {
F_88 ( L_10 , V_149 ) ;
F_95 ( & V_148 , V_111 ) ;
return - V_150 ;
}
return 0 ;
}
static void T_8 F_96 ( void )
{
if ( F_97 ( & V_151 , V_50 ) < 0 )
F_88 ( L_11 , V_149 ) ;
if ( F_95 ( & V_148 , V_111 ) < 0 )
F_88 ( L_12 , V_149 ) ;
}
