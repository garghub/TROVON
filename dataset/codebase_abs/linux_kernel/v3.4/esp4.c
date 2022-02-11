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
static inline struct V_6 * F_12 (
struct V_1 * V_2 , T_2 * V_10 )
{
struct V_6 * V_11 ;
V_11 = ( void * ) F_10 ( V_10 + F_2 ( V_2 ) ,
F_4 () ) ;
F_13 ( V_11 , V_2 ) ;
return V_11 ;
}
static inline struct V_12 * F_14 ( struct V_1 * V_2 , T_2 * V_10 )
{
struct V_12 * V_11 ;
V_11 = ( void * ) F_10 ( V_10 + F_2 ( V_2 ) ,
F_4 () ) ;
F_15 ( V_11 , V_2 ) ;
return V_11 ;
}
static inline struct V_7 * F_16 ( struct V_1 * V_2 ,
struct V_12 * V_11 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_11 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static inline struct V_7 * F_17 (
struct V_1 * V_2 , struct V_6 * V_11 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_11 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static void F_18 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_19 ( F_20 ( V_17 ) -> V_9 ) ;
F_21 ( V_17 , V_15 ) ;
}
static int F_22 ( struct V_19 * V_20 , struct V_16 * V_17 )
{
int V_15 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_6 * V_11 ;
struct V_7 * V_23 ;
struct V_7 * V_24 ;
struct V_25 * V_26 ;
struct V_16 * V_27 ;
void * V_9 ;
T_2 * V_10 ;
T_2 * V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
int V_3 ;
int V_34 ;
int V_35 ;
int V_4 ;
T_1 * V_36 ;
V_15 = - V_37 ;
V_26 = V_20 -> V_18 ;
V_2 = V_26 -> V_2 ;
V_31 = F_23 ( V_2 ) ;
V_33 = 0 ;
if ( V_20 -> V_38 ) {
struct V_39 * V_40 = (struct V_39 * ) F_24 ( V_17 ) ;
T_3 V_41 ;
V_41 = F_25 ( V_20 -> V_38 , F_26 ( V_20 , V_40 -> V_42 ) ) ;
if ( V_17 -> V_5 < V_41 )
V_33 = V_41 - V_17 -> V_5 ;
}
V_29 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_30 = F_5 ( V_17 -> V_5 + 2 + V_33 , V_29 ) ;
if ( V_26 -> V_43 )
V_30 = F_5 ( V_30 , V_26 -> V_43 ) ;
V_32 = V_30 - V_17 -> V_5 - V_33 ;
V_15 = F_28 ( V_17 , V_33 + V_32 + V_31 , & V_27 ) ;
if ( V_15 < 0 )
goto error;
V_3 = V_15 ;
V_34 = sizeof( * V_22 ) ;
V_35 = 1 ;
V_4 = 0 ;
if ( V_20 -> V_44 . V_45 & V_46 ) {
V_35 += 2 ;
V_4 += sizeof( T_1 ) ;
V_34 += V_4 ;
}
V_9 = F_1 ( V_2 , V_3 + V_35 , V_4 ) ;
if ( ! V_9 )
goto error;
V_36 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_12 ( V_2 , V_10 ) ;
V_24 = F_17 ( V_2 , V_11 ) ;
V_23 = V_24 + V_35 ;
V_28 = F_29 ( V_27 ) ;
if ( V_33 ) {
memset ( V_28 , 0 , V_33 ) ;
V_28 += V_33 ;
}
do {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_32 - 2 ; V_47 ++ )
V_28 [ V_47 ] = V_47 + 1 ;
} while ( 0 );
V_28 [ V_32 - 2 ] = V_32 - 2 ;
V_28 [ V_32 - 1 ] = * F_30 ( V_17 ) ;
F_31 ( V_17 , V_27 , V_30 - V_17 -> V_5 + V_31 ) ;
F_32 ( V_17 , - F_33 ( V_17 ) ) ;
V_22 = V_21 ( V_17 ) ;
* F_30 ( V_17 ) = V_48 ;
if ( V_20 -> V_49 ) {
struct V_50 * V_49 = V_20 -> V_49 ;
struct V_51 * V_52 ;
T_1 * V_53 ;
T_4 V_54 , V_55 ;
int V_56 ;
F_34 ( & V_20 -> V_57 ) ;
V_54 = V_49 -> V_58 ;
V_55 = V_49 -> V_59 ;
V_56 = V_49 -> V_56 ;
F_35 ( & V_20 -> V_57 ) ;
V_52 = (struct V_51 * ) V_22 ;
V_52 -> V_60 = V_54 ;
V_52 -> V_61 = V_55 ;
V_52 -> V_5 = F_36 ( V_17 -> V_5 - F_37 ( V_17 ) ) ;
V_52 -> V_62 = 0 ;
switch ( V_56 ) {
default:
case V_63 :
V_22 = (struct V_21 * ) ( V_52 + 1 ) ;
break;
case V_64 :
V_53 = ( T_1 * ) ( V_52 + 1 ) ;
V_53 [ 0 ] = V_53 [ 1 ] = 0 ;
V_22 = (struct V_21 * ) ( V_53 + 2 ) ;
break;
}
* F_30 ( V_17 ) = V_65 ;
}
V_22 -> V_66 = V_20 -> V_67 . V_66 ;
V_22 -> V_68 = F_38 ( F_39 ( V_17 ) -> V_69 . V_70 . V_71 ) ;
F_40 ( V_23 , V_3 ) ;
F_41 ( V_17 , V_23 ,
V_22 -> V_72 + F_2 ( V_2 ) - V_17 -> V_18 ,
V_30 + V_31 ) ;
if ( ( V_20 -> V_44 . V_45 & V_46 ) ) {
F_40 ( V_24 , 3 ) ;
F_42 ( V_24 , & V_22 -> V_66 , sizeof( T_1 ) ) ;
* V_36 = F_38 ( F_39 ( V_17 ) -> V_69 . V_70 . V_73 ) ;
F_42 ( V_24 + 1 , V_36 , V_4 ) ;
F_42 ( V_24 + 2 , & V_22 -> V_68 , sizeof( T_1 ) ) ;
} else
F_43 ( V_24 , V_22 , sizeof( * V_22 ) ) ;
F_44 ( V_11 , 0 , F_18 , V_17 ) ;
F_45 ( V_11 , V_23 , V_23 , V_30 , V_10 ) ;
F_46 ( V_11 , V_24 , V_34 ) ;
F_47 ( V_11 , V_22 -> V_72 ,
F_39 ( V_17 ) -> V_69 . V_70 . V_71 ) ;
F_20 ( V_17 ) -> V_9 = V_9 ;
V_15 = F_48 ( V_11 ) ;
if ( V_15 == - V_74 )
goto error;
if ( V_15 == - V_75 )
V_15 = V_76 ;
F_19 ( V_9 ) ;
error:
return V_15 ;
}
static int F_49 ( struct V_16 * V_17 , int V_15 )
{
const struct V_77 * V_78 ;
struct V_19 * V_20 = F_50 ( V_17 ) ;
struct V_25 * V_26 = V_20 -> V_18 ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_31 = F_23 ( V_2 ) ;
int V_79 = sizeof( struct V_21 ) + F_2 ( V_2 ) ;
int V_80 = V_17 -> V_5 - V_79 ;
int V_81 ;
T_2 V_82 [ 2 ] ;
int V_43 ;
F_19 ( F_20 ( V_17 ) -> V_9 ) ;
if ( F_51 ( V_15 ) )
goto V_83;
if ( F_52 ( V_17 , V_17 -> V_5 - V_31 - 2 , V_82 , 2 ) )
F_53 () ;
V_15 = - V_84 ;
V_43 = V_82 [ 0 ] ;
if ( V_43 + 2 + V_31 >= V_80 )
goto V_83;
V_78 = F_54 ( V_17 ) ;
V_81 = V_78 -> V_81 * 4 ;
if ( V_20 -> V_49 ) {
struct V_50 * V_49 = V_20 -> V_49 ;
struct V_51 * V_52 = ( void * ) ( F_55 ( V_17 ) + V_81 ) ;
if ( V_78 -> V_85 != V_20 -> V_44 . V_85 . V_86 ||
V_52 -> V_60 != V_49 -> V_58 ) {
T_5 V_87 ;
V_87 . V_86 = V_78 -> V_85 ;
F_56 ( V_20 , & V_87 , V_52 -> V_60 ) ;
}
if ( V_20 -> V_44 . V_88 == V_89 )
V_17 -> V_90 = V_91 ;
}
F_57 ( V_17 , V_17 -> V_5 - V_31 - V_43 - 2 ) ;
F_58 ( V_17 , V_79 ) ;
F_59 ( V_17 , - V_81 ) ;
V_15 = V_82 [ 1 ] ;
if ( V_15 == V_92 )
V_15 = - V_84 ;
V_83:
return V_15 ;
}
static void F_60 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_61 ( V_17 , F_49 ( V_17 , V_15 ) ) ;
}
static int F_62 ( struct V_19 * V_20 , struct V_16 * V_17 )
{
struct V_21 * V_22 ;
struct V_25 * V_26 = V_20 -> V_18 ;
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_12 * V_11 ;
struct V_16 * V_27 ;
int V_80 = V_17 -> V_5 - sizeof( * V_22 ) - F_2 ( V_2 ) ;
int V_3 ;
int V_34 ;
int V_35 ;
int V_4 ;
T_1 * V_36 ;
void * V_9 ;
T_2 * V_10 ;
struct V_7 * V_23 ;
struct V_7 * V_24 ;
int V_15 = - V_84 ;
if ( ! F_63 ( V_17 , sizeof( * V_22 ) + F_2 ( V_2 ) ) )
goto V_83;
if ( V_80 <= 0 )
goto V_83;
if ( ( V_15 = F_28 ( V_17 , 0 , & V_27 ) ) < 0 )
goto V_83;
V_3 = V_15 ;
V_34 = sizeof( * V_22 ) ;
V_35 = 1 ;
V_4 = 0 ;
if ( V_20 -> V_44 . V_45 & V_46 ) {
V_35 += 2 ;
V_4 += sizeof( T_1 ) ;
V_34 += V_4 ;
}
V_15 = - V_37 ;
V_9 = F_1 ( V_2 , V_3 + V_35 , V_4 ) ;
if ( ! V_9 )
goto V_83;
F_20 ( V_17 ) -> V_9 = V_9 ;
V_36 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_14 ( V_2 , V_10 ) ;
V_24 = F_16 ( V_2 , V_11 ) ;
V_23 = V_24 + V_35 ;
V_17 -> V_90 = V_93 ;
V_22 = (struct V_21 * ) V_17 -> V_18 ;
V_10 = V_22 -> V_72 ;
F_40 ( V_23 , V_3 ) ;
F_41 ( V_17 , V_23 , sizeof( * V_22 ) + F_2 ( V_2 ) , V_80 ) ;
if ( ( V_20 -> V_44 . V_45 & V_46 ) ) {
F_40 ( V_24 , 3 ) ;
F_42 ( V_24 , & V_22 -> V_66 , sizeof( T_1 ) ) ;
* V_36 = F_39 ( V_17 ) -> V_69 . V_94 . V_73 ;
F_42 ( V_24 + 1 , V_36 , V_4 ) ;
F_42 ( V_24 + 2 , & V_22 -> V_68 , sizeof( T_1 ) ) ;
} else
F_43 ( V_24 , V_22 , sizeof( * V_22 ) ) ;
F_64 ( V_11 , 0 , F_60 , V_17 ) ;
F_65 ( V_11 , V_23 , V_23 , V_80 , V_10 ) ;
F_66 ( V_11 , V_24 , V_34 ) ;
V_15 = F_67 ( V_11 ) ;
if ( V_15 == - V_74 )
goto V_83;
V_15 = F_49 ( V_17 , V_15 ) ;
V_83:
return V_15 ;
}
static T_3 F_26 ( struct V_19 * V_20 , int V_95 )
{
struct V_25 * V_26 = V_20 -> V_18 ;
T_3 V_29 = F_5 ( F_27 ( V_26 -> V_2 ) , 4 ) ;
T_3 V_96 = F_68 ( T_3 , V_29 , V_26 -> V_43 ) ;
T_3 V_97 ;
V_95 -= V_20 -> V_44 . V_98 + F_23 ( V_26 -> V_2 ) ;
V_97 = V_95 & ( V_96 - 1 ) ;
V_95 &= ~ ( V_96 - 1 ) ;
switch ( V_20 -> V_44 . V_88 ) {
case V_99 :
break;
default:
case V_89 :
V_95 -= V_29 - 4 ;
V_95 += F_69 ( T_3 , V_29 - 4 , V_97 ) ;
break;
case V_100 :
V_95 += F_69 ( T_3 , V_101 , V_97 ) ;
break;
}
return V_95 - 2 ;
}
static void F_70 ( struct V_16 * V_17 , T_3 V_102 )
{
struct V_103 * V_103 = F_71 ( V_17 -> V_104 ) ;
const struct V_77 * V_78 = ( const struct V_77 * ) V_17 -> V_18 ;
struct V_21 * V_22 = (struct V_21 * ) ( V_17 -> V_18 + ( V_78 -> V_81 << 2 ) ) ;
struct V_19 * V_20 ;
if ( F_72 ( V_17 ) -> type != V_105 ||
F_72 ( V_17 ) -> V_106 != V_107 )
return;
V_20 = F_73 ( V_103 , V_17 -> V_108 , ( const T_5 * ) & V_78 -> V_109 ,
V_22 -> V_66 , V_48 , V_110 ) ;
if ( ! V_20 )
return;
F_74 ( V_111 L_1 ,
F_75 ( V_22 -> V_66 ) , F_75 ( V_78 -> V_109 ) ) ;
F_76 ( V_20 ) ;
}
static void F_77 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_18 ;
if ( ! V_26 )
return;
F_78 ( V_26 -> V_2 ) ;
F_19 ( V_26 ) ;
}
static int F_79 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_18 ;
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_80 ( V_20 -> V_2 -> V_112 , 0 , 0 ) ;
V_15 = F_81 ( V_2 ) ;
if ( F_82 ( V_2 ) )
goto error;
V_26 -> V_2 = V_2 ;
V_15 = F_83 ( V_2 , V_20 -> V_2 -> V_113 ,
( V_20 -> V_2 -> V_114 + 7 ) / 8 ) ;
if ( V_15 )
goto error;
V_15 = F_84 ( V_2 , V_20 -> V_2 -> V_115 / 8 ) ;
if ( V_15 )
goto error;
error:
return V_15 ;
}
static int F_85 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_18 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
char * V_120 ;
char * V_121 ;
char V_122 [ V_123 ] ;
unsigned int V_124 ;
int V_15 ;
V_15 = - V_84 ;
if ( V_20 -> V_125 == NULL )
goto error;
V_15 = - V_126 ;
if ( ( V_20 -> V_44 . V_45 & V_46 ) ) {
if ( snprintf ( V_122 , V_123 ,
L_2 ,
V_20 -> V_127 ? V_20 -> V_127 -> V_112 : L_3 ,
V_20 -> V_125 -> V_112 ) >= V_123 )
goto error;
} else {
if ( snprintf ( V_122 , V_123 ,
L_4 ,
V_20 -> V_127 ? V_20 -> V_127 -> V_112 : L_3 ,
V_20 -> V_125 -> V_112 ) >= V_123 )
goto error;
}
V_2 = F_80 ( V_122 , 0 , 0 ) ;
V_15 = F_81 ( V_2 ) ;
if ( F_82 ( V_2 ) )
goto error;
V_26 -> V_2 = V_2 ;
V_124 = ( V_20 -> V_127 ? ( V_20 -> V_127 -> V_114 + 7 ) / 8 : 0 ) +
( V_20 -> V_125 -> V_114 + 7 ) / 8 + F_86 ( sizeof( * V_117 ) ) ;
V_15 = - V_37 ;
V_120 = F_8 ( V_124 , V_128 ) ;
if ( ! V_120 )
goto error;
V_121 = V_120 ;
V_119 = ( void * ) V_121 ;
V_119 -> V_129 = V_130 ;
V_119 -> V_131 = F_87 ( sizeof( * V_117 ) ) ;
V_117 = F_88 ( V_119 ) ;
V_121 += F_86 ( sizeof( * V_117 ) ) ;
if ( V_20 -> V_127 ) {
struct V_132 * V_133 ;
memcpy ( V_121 , V_20 -> V_127 -> V_113 , ( V_20 -> V_127 -> V_114 + 7 ) / 8 ) ;
V_121 += ( V_20 -> V_127 -> V_114 + 7 ) / 8 ;
V_133 = F_89 ( V_20 -> V_127 -> V_112 , 0 ) ;
F_90 ( ! V_133 ) ;
V_15 = - V_84 ;
if ( V_133 -> V_134 . V_135 . V_136 / 8 !=
F_23 ( V_2 ) ) {
F_74 ( V_137 L_5 ,
V_20 -> V_127 -> V_112 ,
F_23 ( V_2 ) ,
V_133 -> V_134 . V_135 . V_136 / 8 ) ;
goto V_138;
}
V_15 = F_84 (
V_2 , V_20 -> V_127 -> V_139 / 8 ) ;
if ( V_15 )
goto V_138;
}
V_117 -> V_140 = F_91 ( ( V_20 -> V_125 -> V_114 + 7 ) / 8 ) ;
memcpy ( V_121 , V_20 -> V_125 -> V_113 , ( V_20 -> V_125 -> V_114 + 7 ) / 8 ) ;
V_15 = F_83 ( V_2 , V_120 , V_124 ) ;
V_138:
F_19 ( V_120 ) ;
error:
return V_15 ;
}
static int F_92 ( struct V_19 * V_20 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
T_3 V_96 ;
int V_15 ;
V_26 = F_93 ( sizeof( * V_26 ) , V_128 ) ;
if ( V_26 == NULL )
return - V_37 ;
V_20 -> V_18 = V_26 ;
if ( V_20 -> V_2 )
V_15 = F_79 ( V_20 ) ;
else
V_15 = F_85 ( V_20 ) ;
if ( V_15 )
goto error;
V_2 = V_26 -> V_2 ;
V_26 -> V_43 = 0 ;
V_20 -> V_44 . V_98 = sizeof( struct V_21 ) +
F_2 ( V_2 ) ;
if ( V_20 -> V_44 . V_88 == V_99 )
V_20 -> V_44 . V_98 += sizeof( struct V_77 ) ;
else if ( V_20 -> V_44 . V_88 == V_100 && V_20 -> V_141 . V_142 != V_143 )
V_20 -> V_44 . V_98 += V_101 ;
if ( V_20 -> V_49 ) {
struct V_50 * V_49 = V_20 -> V_49 ;
switch ( V_49 -> V_56 ) {
default:
goto error;
case V_63 :
V_20 -> V_44 . V_98 += sizeof( struct V_51 ) ;
break;
case V_64 :
V_20 -> V_44 . V_98 += sizeof( struct V_51 ) + 2 * sizeof( T_3 ) ;
break;
}
}
V_96 = F_5 ( F_27 ( V_2 ) , 4 ) ;
if ( V_26 -> V_43 )
V_96 = F_68 ( T_3 , V_96 , V_26 -> V_43 ) ;
V_20 -> V_44 . V_144 = V_96 + 1 + F_23 ( V_26 -> V_2 ) ;
error:
return V_15 ;
}
static int T_6 F_94 ( void )
{
if ( F_95 ( & V_145 , V_110 ) < 0 ) {
F_96 ( L_6 , V_146 ) ;
return - V_147 ;
}
if ( F_97 ( & V_148 , V_48 ) < 0 ) {
F_96 ( L_7 , V_146 ) ;
F_98 ( & V_145 , V_110 ) ;
return - V_147 ;
}
return 0 ;
}
static void T_7 F_99 ( void )
{
if ( F_100 ( & V_148 , V_48 ) < 0 )
F_96 ( L_8 , V_146 ) ;
if ( F_98 ( & V_145 , V_110 ) < 0 )
F_96 ( L_9 , V_146 ) ;
}
