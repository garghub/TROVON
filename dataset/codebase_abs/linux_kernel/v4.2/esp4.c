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
static inline T_1 * F_9 ( void * V_9 )
{
return F_10 ( ( T_1 * ) V_9 , F_7 ( T_1 ) ) ;
}
static inline T_2 * F_11 ( struct V_1 * V_2 , void * V_9 , int V_4 )
{
return F_2 ( V_2 ) ?
F_10 ( ( T_2 * ) V_9 + V_4 ,
F_3 ( V_2 ) + 1 ) : V_9 + V_4 ;
}
static inline struct V_6 * F_12 ( struct V_1 * V_2 , T_2 * V_10 )
{
struct V_6 * V_11 ;
V_11 = ( void * ) F_10 ( V_10 + F_2 ( V_2 ) ,
F_4 () ) ;
F_13 ( V_11 , V_2 ) ;
return V_11 ;
}
static inline struct V_7 * F_14 ( struct V_1 * V_2 ,
struct V_6 * V_11 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_11 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static void F_15 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_16 ( F_17 ( V_16 ) -> V_9 ) ;
F_18 ( V_16 , V_14 ) ;
}
static void F_19 ( struct V_15 * V_16 , unsigned int V_18 )
{
struct V_19 * V_20 = ( void * ) ( V_16 -> V_17 + V_18 ) ;
void * V_9 = F_17 ( V_16 ) -> V_9 ;
T_1 * V_21 = F_9 ( V_9 ) ;
V_20 -> V_22 = V_20 -> V_23 ;
V_20 -> V_23 = * V_21 ;
}
static void F_20 ( struct V_15 * V_16 )
{
F_19 ( V_16 , F_21 ( V_16 ) - sizeof( T_1 ) ) ;
}
static void F_22 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_20 ( V_16 ) ;
F_15 ( V_13 , V_14 ) ;
}
static int F_23 ( struct V_24 * V_25 , struct V_15 * V_16 )
{
int V_14 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_6 * V_11 ;
struct V_7 * V_26 ;
struct V_15 * V_27 ;
void * V_9 ;
T_2 * V_10 ;
T_2 * V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
int V_34 ;
int V_3 ;
int V_35 ;
int V_4 ;
T_1 * V_21 ;
T_3 V_36 ;
V_2 = V_25 -> V_17 ;
V_31 = F_24 ( V_2 ) ;
V_33 = F_2 ( V_2 ) ;
V_34 = 0 ;
if ( V_25 -> V_37 ) {
struct V_38 * V_39 = (struct V_38 * ) F_25 ( V_16 ) ;
T_4 V_40 ;
V_40 = F_26 ( V_25 -> V_37 , F_27 ( V_25 , V_39 -> V_41 ) ) ;
if ( V_16 -> V_5 < V_40 )
V_34 = V_40 - V_16 -> V_5 ;
}
V_29 = F_5 ( F_28 ( V_2 ) , 4 ) ;
V_30 = F_5 ( V_16 -> V_5 + 2 + V_34 , V_29 ) ;
V_32 = V_30 - V_16 -> V_5 - V_34 ;
V_14 = F_29 ( V_16 , V_34 + V_32 + V_31 , & V_27 ) ;
if ( V_14 < 0 )
goto error;
V_3 = V_14 ;
V_35 = sizeof( * V_20 ) ;
V_4 = 0 ;
if ( V_25 -> V_42 . V_43 & V_44 ) {
V_4 += sizeof( T_1 ) ;
V_35 += V_4 ;
}
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_9 ) {
V_14 = - V_45 ;
goto error;
}
V_21 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_12 ( V_2 , V_10 ) ;
V_26 = F_14 ( V_2 , V_11 ) ;
V_28 = F_30 ( V_27 ) ;
if ( V_34 ) {
memset ( V_28 , 0 , V_34 ) ;
V_28 += V_34 ;
}
do {
int V_46 ;
for ( V_46 = 0 ; V_46 < V_32 - 2 ; V_46 ++ )
V_28 [ V_46 ] = V_46 + 1 ;
} while ( 0 );
V_28 [ V_32 - 2 ] = V_32 - 2 ;
V_28 [ V_32 - 1 ] = * F_31 ( V_16 ) ;
F_32 ( V_16 , V_27 , V_30 - V_16 -> V_5 + V_31 ) ;
F_33 ( V_16 , - F_34 ( V_16 ) ) ;
V_20 = V_19 ( V_16 ) ;
* F_31 ( V_16 ) = V_47 ;
if ( V_25 -> V_48 ) {
struct V_49 * V_48 = V_25 -> V_48 ;
struct V_50 * V_51 ;
T_1 * V_52 ;
T_5 V_53 , V_54 ;
int V_55 ;
F_35 ( & V_25 -> V_56 ) ;
V_53 = V_48 -> V_57 ;
V_54 = V_48 -> V_58 ;
V_55 = V_48 -> V_55 ;
F_36 ( & V_25 -> V_56 ) ;
V_51 = (struct V_50 * ) V_20 ;
V_51 -> V_59 = V_53 ;
V_51 -> V_60 = V_54 ;
V_51 -> V_5 = F_37 ( V_16 -> V_5 - F_21 ( V_16 ) ) ;
V_51 -> V_61 = 0 ;
switch ( V_55 ) {
default:
case V_62 :
V_20 = (struct V_19 * ) ( V_51 + 1 ) ;
break;
case V_63 :
V_52 = ( T_1 * ) ( V_51 + 1 ) ;
V_52 [ 0 ] = V_52 [ 1 ] = 0 ;
V_20 = (struct V_19 * ) ( V_52 + 2 ) ;
break;
}
* F_31 ( V_16 ) = V_64 ;
}
V_20 -> V_22 = F_38 ( F_39 ( V_16 ) -> V_65 . V_66 . V_67 ) ;
F_40 ( V_11 , 0 , F_15 , V_16 ) ;
if ( ( V_25 -> V_42 . V_43 & V_44 ) ) {
V_20 = ( void * ) ( F_41 ( V_16 ) - sizeof( T_1 ) ) ;
* V_21 = V_20 -> V_23 ;
V_20 -> V_22 = F_38 ( F_39 ( V_16 ) -> V_65 . V_66 . V_68 ) ;
F_40 ( V_11 , 0 , F_22 , V_16 ) ;
}
V_20 -> V_23 = V_25 -> V_69 . V_23 ;
F_42 ( V_26 , V_3 ) ;
F_43 ( V_16 , V_26 ,
( unsigned char * ) V_20 - V_16 -> V_17 ,
V_35 + V_33 + V_30 + V_31 ) ;
F_44 ( V_11 , V_26 , V_26 , V_33 + V_30 , V_10 ) ;
F_45 ( V_11 , V_35 ) ;
V_36 = F_46 ( F_39 ( V_16 ) -> V_65 . V_66 . V_67 +
( ( V_70 ) F_39 ( V_16 ) -> V_65 . V_66 . V_68 << 32 ) ) ;
memset ( V_10 , 0 , V_33 ) ;
memcpy ( V_10 + V_33 - F_26 ( V_33 , 8 ) , ( T_2 * ) & V_36 + 8 - F_26 ( V_33 , 8 ) ,
F_26 ( V_33 , 8 ) ) ;
F_17 ( V_16 ) -> V_9 = V_9 ;
V_14 = F_47 ( V_11 ) ;
switch ( V_14 ) {
case - V_71 :
goto error;
case - V_72 :
V_14 = V_73 ;
break;
case 0 :
if ( ( V_25 -> V_42 . V_43 & V_44 ) )
F_20 ( V_16 ) ;
}
F_16 ( V_9 ) ;
error:
return V_14 ;
}
static int F_48 ( struct V_15 * V_16 , int V_14 )
{
const struct V_74 * V_75 ;
struct V_24 * V_25 = F_49 ( V_16 ) ;
struct V_1 * V_2 = V_25 -> V_17 ;
int V_31 = F_24 ( V_2 ) ;
int V_76 = sizeof( struct V_19 ) + F_2 ( V_2 ) ;
int V_77 = V_16 -> V_5 - V_76 ;
int V_78 ;
T_2 V_79 [ 2 ] ;
int V_80 ;
F_16 ( F_17 ( V_16 ) -> V_9 ) ;
if ( F_50 ( V_14 ) )
goto V_81;
if ( F_51 ( V_16 , V_16 -> V_5 - V_31 - 2 , V_79 , 2 ) )
F_52 () ;
V_14 = - V_82 ;
V_80 = V_79 [ 0 ] ;
if ( V_80 + 2 + V_31 >= V_77 )
goto V_81;
V_75 = F_53 ( V_16 ) ;
V_78 = V_75 -> V_78 * 4 ;
if ( V_25 -> V_48 ) {
struct V_49 * V_48 = V_25 -> V_48 ;
struct V_50 * V_51 = ( void * ) ( F_54 ( V_16 ) + V_78 ) ;
if ( V_75 -> V_83 != V_25 -> V_42 . V_83 . V_84 ||
V_51 -> V_59 != V_48 -> V_57 ) {
T_6 V_85 ;
V_85 . V_84 = V_75 -> V_83 ;
F_55 ( V_25 , & V_85 , V_51 -> V_59 ) ;
}
if ( V_25 -> V_42 . V_86 == V_87 )
V_16 -> V_88 = V_89 ;
}
F_56 ( V_16 , V_16 -> V_5 - V_31 - V_80 - 2 ) ;
F_57 ( V_16 , V_76 ) ;
if ( V_25 -> V_42 . V_86 == V_90 )
F_58 ( V_16 ) ;
else
F_59 ( V_16 , - V_78 ) ;
V_14 = V_79 [ 1 ] ;
if ( V_14 == V_91 )
V_14 = - V_82 ;
V_81:
return V_14 ;
}
static void F_60 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_61 ( V_16 , F_48 ( V_16 , V_14 ) ) ;
}
static void F_62 ( struct V_15 * V_16 )
{
F_19 ( V_16 , 0 ) ;
F_57 ( V_16 , 4 ) ;
}
static void F_63 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_62 ( V_16 ) ;
F_60 ( V_13 , V_14 ) ;
}
static int F_64 ( struct V_24 * V_25 , struct V_15 * V_16 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_25 -> V_17 ;
struct V_6 * V_11 ;
struct V_15 * V_27 ;
int V_33 = F_2 ( V_2 ) ;
int V_77 = V_16 -> V_5 - sizeof( * V_20 ) - V_33 ;
int V_3 ;
int V_35 ;
int V_4 ;
T_1 * V_21 ;
void * V_9 ;
T_2 * V_10 ;
struct V_7 * V_26 ;
int V_14 = - V_82 ;
if ( ! F_65 ( V_16 , sizeof( * V_20 ) + V_33 ) )
goto V_81;
if ( V_77 <= 0 )
goto V_81;
V_14 = F_29 ( V_16 , 0 , & V_27 ) ;
if ( V_14 < 0 )
goto V_81;
V_3 = V_14 ;
V_35 = sizeof( * V_20 ) ;
V_4 = 0 ;
if ( V_25 -> V_42 . V_43 & V_44 ) {
V_4 += sizeof( T_1 ) ;
V_35 += V_4 ;
}
V_14 = - V_45 ;
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_9 )
goto V_81;
F_17 ( V_16 ) -> V_9 = V_9 ;
V_21 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_12 ( V_2 , V_10 ) ;
V_26 = F_14 ( V_2 , V_11 ) ;
V_16 -> V_88 = V_92 ;
V_20 = (struct V_19 * ) V_16 -> V_17 ;
F_40 ( V_11 , 0 , F_60 , V_16 ) ;
if ( ( V_25 -> V_42 . V_43 & V_44 ) ) {
V_20 = ( void * ) F_33 ( V_16 , 4 ) ;
* V_21 = V_20 -> V_23 ;
V_20 -> V_23 = V_20 -> V_22 ;
V_20 -> V_22 = F_38 ( F_39 ( V_16 ) -> V_65 . V_93 . V_68 ) ;
F_40 ( V_11 , 0 , F_63 , V_16 ) ;
}
F_42 ( V_26 , V_3 ) ;
F_43 ( V_16 , V_26 , 0 , V_16 -> V_5 ) ;
F_44 ( V_11 , V_26 , V_26 , V_77 + V_33 , V_10 ) ;
F_45 ( V_11 , V_35 ) ;
V_14 = F_66 ( V_11 ) ;
if ( V_14 == - V_71 )
goto V_81;
if ( ( V_25 -> V_42 . V_43 & V_44 ) )
F_62 ( V_16 ) ;
V_14 = F_48 ( V_16 , V_14 ) ;
V_81:
return V_14 ;
}
static T_4 F_27 ( struct V_24 * V_25 , int V_94 )
{
struct V_1 * V_2 = V_25 -> V_17 ;
T_4 V_29 = F_5 ( F_28 ( V_2 ) , 4 ) ;
unsigned int V_95 ;
switch ( V_25 -> V_42 . V_86 ) {
case V_87 :
case V_96 :
V_95 = sizeof( struct V_74 ) ;
break;
case V_90 :
V_95 = 0 ;
break;
default:
F_52 () ;
}
return ( ( V_94 - V_25 -> V_42 . V_97 - F_24 ( V_2 ) -
V_95 ) & ~ ( V_29 - 1 ) ) + V_95 - 2 ;
}
static int F_67 ( struct V_15 * V_16 , T_4 V_98 )
{
struct V_99 * V_99 = F_68 ( V_16 -> V_100 ) ;
const struct V_74 * V_75 = ( const struct V_74 * ) V_16 -> V_17 ;
struct V_19 * V_20 = (struct V_19 * ) ( V_16 -> V_17 + ( V_75 -> V_78 << 2 ) ) ;
struct V_24 * V_25 ;
switch ( F_69 ( V_16 ) -> type ) {
case V_101 :
if ( F_69 ( V_16 ) -> V_102 != V_103 )
return 0 ;
case V_104 :
break;
default:
return 0 ;
}
V_25 = F_70 ( V_99 , V_16 -> V_105 , ( const T_6 * ) & V_75 -> V_106 ,
V_20 -> V_23 , V_47 , V_107 ) ;
if ( ! V_25 )
return 0 ;
if ( F_69 ( V_16 ) -> type == V_101 )
F_71 ( V_16 , V_99 , V_98 , 0 , 0 , V_47 , 0 ) ;
else
F_72 ( V_16 , V_99 , 0 , 0 , V_47 , 0 ) ;
F_73 ( V_25 ) ;
return 0 ;
}
static void F_74 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_17 ;
if ( ! V_2 )
return;
F_75 ( V_2 ) ;
}
static int F_76 ( struct V_24 * V_25 )
{
char V_108 [ V_109 ] ;
struct V_1 * V_2 ;
int V_14 ;
V_14 = - V_110 ;
if ( snprintf ( V_108 , V_109 , L_1 ,
V_25 -> V_111 , V_25 -> V_2 -> V_112 ) >= V_109 )
goto error;
V_2 = F_77 ( V_108 , 0 , 0 ) ;
V_14 = F_78 ( V_2 ) ;
if ( F_79 ( V_2 ) )
goto error;
V_25 -> V_17 = V_2 ;
V_14 = F_80 ( V_2 , V_25 -> V_2 -> V_113 ,
( V_25 -> V_2 -> V_114 + 7 ) / 8 ) ;
if ( V_14 )
goto error;
V_14 = F_81 ( V_2 , V_25 -> V_2 -> V_115 / 8 ) ;
if ( V_14 )
goto error;
error:
return V_14 ;
}
static int F_82 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
char * V_120 ;
char * V_121 ;
char V_122 [ V_109 ] ;
unsigned int V_123 ;
int V_14 ;
V_14 = - V_82 ;
if ( ! V_25 -> V_124 )
goto error;
V_14 = - V_110 ;
if ( ( V_25 -> V_42 . V_43 & V_44 ) ) {
if ( snprintf ( V_122 , V_109 ,
L_2 ,
V_25 -> V_111 ? : L_3 , V_25 -> V_111 ? L_4 : L_3 ,
V_25 -> V_125 ? V_25 -> V_125 -> V_112 : L_5 ,
V_25 -> V_124 -> V_112 ,
V_25 -> V_111 ? L_6 : L_3 ) >= V_109 )
goto error;
} else {
if ( snprintf ( V_122 , V_109 ,
L_7 ,
V_25 -> V_111 ? : L_3 , V_25 -> V_111 ? L_4 : L_3 ,
V_25 -> V_125 ? V_25 -> V_125 -> V_112 : L_5 ,
V_25 -> V_124 -> V_112 ,
V_25 -> V_111 ? L_6 : L_3 ) >= V_109 )
goto error;
}
V_2 = F_77 ( V_122 , 0 , 0 ) ;
V_14 = F_78 ( V_2 ) ;
if ( F_79 ( V_2 ) )
goto error;
V_25 -> V_17 = V_2 ;
V_123 = ( V_25 -> V_125 ? ( V_25 -> V_125 -> V_114 + 7 ) / 8 : 0 ) +
( V_25 -> V_124 -> V_114 + 7 ) / 8 + F_83 ( sizeof( * V_117 ) ) ;
V_14 = - V_45 ;
V_120 = F_8 ( V_123 , V_126 ) ;
if ( ! V_120 )
goto error;
V_121 = V_120 ;
V_119 = ( void * ) V_121 ;
V_119 -> V_127 = V_128 ;
V_119 -> V_129 = F_84 ( sizeof( * V_117 ) ) ;
V_117 = F_85 ( V_119 ) ;
V_121 += F_83 ( sizeof( * V_117 ) ) ;
if ( V_25 -> V_125 ) {
struct V_130 * V_131 ;
memcpy ( V_121 , V_25 -> V_125 -> V_113 , ( V_25 -> V_125 -> V_114 + 7 ) / 8 ) ;
V_121 += ( V_25 -> V_125 -> V_114 + 7 ) / 8 ;
V_131 = F_86 ( V_25 -> V_125 -> V_112 , 0 ) ;
F_87 ( ! V_131 ) ;
V_14 = - V_82 ;
if ( V_131 -> V_132 . V_133 . V_134 / 8 !=
F_24 ( V_2 ) ) {
F_88 ( L_8 ,
V_25 -> V_125 -> V_112 ,
F_24 ( V_2 ) ,
V_131 -> V_132 . V_133 . V_134 / 8 ) ;
goto V_135;
}
V_14 = F_81 (
V_2 , V_25 -> V_125 -> V_136 / 8 ) ;
if ( V_14 )
goto V_135;
}
V_117 -> V_137 = F_89 ( ( V_25 -> V_124 -> V_114 + 7 ) / 8 ) ;
memcpy ( V_121 , V_25 -> V_124 -> V_113 , ( V_25 -> V_124 -> V_114 + 7 ) / 8 ) ;
V_14 = F_80 ( V_2 , V_120 , V_123 ) ;
V_135:
F_16 ( V_120 ) ;
error:
return V_14 ;
}
static int F_90 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
T_4 V_138 ;
int V_14 ;
V_25 -> V_17 = NULL ;
if ( V_25 -> V_2 )
V_14 = F_76 ( V_25 ) ;
else
V_14 = F_82 ( V_25 ) ;
if ( V_14 )
goto error;
V_2 = V_25 -> V_17 ;
V_25 -> V_42 . V_97 = sizeof( struct V_19 ) +
F_2 ( V_2 ) ;
if ( V_25 -> V_42 . V_86 == V_90 )
V_25 -> V_42 . V_97 += sizeof( struct V_74 ) ;
else if ( V_25 -> V_42 . V_86 == V_96 && V_25 -> V_139 . V_140 != V_141 )
V_25 -> V_42 . V_97 += V_142 ;
if ( V_25 -> V_48 ) {
struct V_49 * V_48 = V_25 -> V_48 ;
switch ( V_48 -> V_55 ) {
default:
goto error;
case V_62 :
V_25 -> V_42 . V_97 += sizeof( struct V_50 ) ;
break;
case V_63 :
V_25 -> V_42 . V_97 += sizeof( struct V_50 ) + 2 * sizeof( T_4 ) ;
break;
}
}
V_138 = F_5 ( F_28 ( V_2 ) , 4 ) ;
V_25 -> V_42 . V_143 = V_138 + 1 + F_24 ( V_2 ) ;
error:
return V_14 ;
}
static int F_91 ( struct V_15 * V_16 , int V_14 )
{
return 0 ;
}
static int T_7 F_92 ( void )
{
if ( F_93 ( & V_144 , V_107 ) < 0 ) {
F_88 ( L_9 , V_145 ) ;
return - V_146 ;
}
if ( F_94 ( & V_147 , V_47 ) < 0 ) {
F_88 ( L_10 , V_145 ) ;
F_95 ( & V_144 , V_107 ) ;
return - V_146 ;
}
return 0 ;
}
static void T_8 F_96 ( void )
{
if ( F_97 ( & V_147 , V_47 ) < 0 )
F_88 ( L_11 , V_145 ) ;
if ( F_95 ( & V_144 , V_107 ) < 0 )
F_88 ( L_12 , V_145 ) ;
}
