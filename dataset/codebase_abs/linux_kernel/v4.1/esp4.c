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
struct V_16 * V_25 ;
void * V_9 ;
T_2 * V_10 ;
T_2 * V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_3 ;
int V_32 ;
int V_33 ;
int V_4 ;
T_1 * V_34 ;
V_2 = V_20 -> V_18 ;
V_29 = F_23 ( V_2 ) ;
V_31 = 0 ;
if ( V_20 -> V_35 ) {
struct V_36 * V_37 = (struct V_36 * ) F_24 ( V_17 ) ;
T_3 V_38 ;
V_38 = F_25 ( V_20 -> V_35 , F_26 ( V_20 , V_37 -> V_39 ) ) ;
if ( V_17 -> V_5 < V_38 )
V_31 = V_38 - V_17 -> V_5 ;
}
V_27 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_28 = F_5 ( V_17 -> V_5 + 2 + V_31 , V_27 ) ;
V_30 = V_28 - V_17 -> V_5 - V_31 ;
V_15 = F_28 ( V_17 , V_31 + V_30 + V_29 , & V_25 ) ;
if ( V_15 < 0 )
goto error;
V_3 = V_15 ;
V_32 = sizeof( * V_22 ) ;
V_33 = 1 ;
V_4 = 0 ;
if ( V_20 -> V_40 . V_41 & V_42 ) {
V_33 += 2 ;
V_4 += sizeof( T_1 ) ;
V_32 += V_4 ;
}
V_9 = F_1 ( V_2 , V_3 + V_33 , V_4 ) ;
if ( ! V_9 ) {
V_15 = - V_43 ;
goto error;
}
V_34 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_12 ( V_2 , V_10 ) ;
V_24 = F_17 ( V_2 , V_11 ) ;
V_23 = V_24 + V_33 ;
V_26 = F_29 ( V_25 ) ;
if ( V_31 ) {
memset ( V_26 , 0 , V_31 ) ;
V_26 += V_31 ;
}
do {
int V_44 ;
for ( V_44 = 0 ; V_44 < V_30 - 2 ; V_44 ++ )
V_26 [ V_44 ] = V_44 + 1 ;
} while ( 0 );
V_26 [ V_30 - 2 ] = V_30 - 2 ;
V_26 [ V_30 - 1 ] = * F_30 ( V_17 ) ;
F_31 ( V_17 , V_25 , V_28 - V_17 -> V_5 + V_29 ) ;
F_32 ( V_17 , - F_33 ( V_17 ) ) ;
V_22 = V_21 ( V_17 ) ;
* F_30 ( V_17 ) = V_45 ;
if ( V_20 -> V_46 ) {
struct V_47 * V_46 = V_20 -> V_46 ;
struct V_48 * V_49 ;
T_1 * V_50 ;
T_4 V_51 , V_52 ;
int V_53 ;
F_34 ( & V_20 -> V_54 ) ;
V_51 = V_46 -> V_55 ;
V_52 = V_46 -> V_56 ;
V_53 = V_46 -> V_53 ;
F_35 ( & V_20 -> V_54 ) ;
V_49 = (struct V_48 * ) V_22 ;
V_49 -> V_57 = V_51 ;
V_49 -> V_58 = V_52 ;
V_49 -> V_5 = F_36 ( V_17 -> V_5 - F_37 ( V_17 ) ) ;
V_49 -> V_59 = 0 ;
switch ( V_53 ) {
default:
case V_60 :
V_22 = (struct V_21 * ) ( V_49 + 1 ) ;
break;
case V_61 :
V_50 = ( T_1 * ) ( V_49 + 1 ) ;
V_50 [ 0 ] = V_50 [ 1 ] = 0 ;
V_22 = (struct V_21 * ) ( V_50 + 2 ) ;
break;
}
* F_30 ( V_17 ) = V_62 ;
}
V_22 -> V_63 = V_20 -> V_64 . V_63 ;
V_22 -> V_65 = F_38 ( F_39 ( V_17 ) -> V_66 . V_67 . V_68 ) ;
F_40 ( V_23 , V_3 ) ;
F_41 ( V_17 , V_23 ,
V_22 -> V_69 + F_2 ( V_2 ) - V_17 -> V_18 ,
V_28 + V_29 ) ;
if ( ( V_20 -> V_40 . V_41 & V_42 ) ) {
F_40 ( V_24 , 3 ) ;
F_42 ( V_24 , & V_22 -> V_63 , sizeof( T_1 ) ) ;
* V_34 = F_38 ( F_39 ( V_17 ) -> V_66 . V_67 . V_70 ) ;
F_42 ( V_24 + 1 , V_34 , V_4 ) ;
F_42 ( V_24 + 2 , & V_22 -> V_65 , sizeof( T_1 ) ) ;
} else
F_43 ( V_24 , V_22 , sizeof( * V_22 ) ) ;
F_44 ( V_11 , 0 , F_18 , V_17 ) ;
F_45 ( V_11 , V_23 , V_23 , V_28 , V_10 ) ;
F_46 ( V_11 , V_24 , V_32 ) ;
F_47 ( V_11 , V_22 -> V_69 ,
F_39 ( V_17 ) -> V_66 . V_67 . V_68 +
( ( V_71 ) F_39 ( V_17 ) -> V_66 . V_67 . V_70 << 32 ) ) ;
F_20 ( V_17 ) -> V_9 = V_9 ;
V_15 = F_48 ( V_11 ) ;
if ( V_15 == - V_72 )
goto error;
if ( V_15 == - V_73 )
V_15 = V_74 ;
F_19 ( V_9 ) ;
error:
return V_15 ;
}
static int F_49 ( struct V_16 * V_17 , int V_15 )
{
const struct V_75 * V_76 ;
struct V_19 * V_20 = F_50 ( V_17 ) ;
struct V_1 * V_2 = V_20 -> V_18 ;
int V_29 = F_23 ( V_2 ) ;
int V_77 = sizeof( struct V_21 ) + F_2 ( V_2 ) ;
int V_78 = V_17 -> V_5 - V_77 ;
int V_79 ;
T_2 V_80 [ 2 ] ;
int V_81 ;
F_19 ( F_20 ( V_17 ) -> V_9 ) ;
if ( F_51 ( V_15 ) )
goto V_82;
if ( F_52 ( V_17 , V_17 -> V_5 - V_29 - 2 , V_80 , 2 ) )
F_53 () ;
V_15 = - V_83 ;
V_81 = V_80 [ 0 ] ;
if ( V_81 + 2 + V_29 >= V_78 )
goto V_82;
V_76 = F_54 ( V_17 ) ;
V_79 = V_76 -> V_79 * 4 ;
if ( V_20 -> V_46 ) {
struct V_47 * V_46 = V_20 -> V_46 ;
struct V_48 * V_49 = ( void * ) ( F_55 ( V_17 ) + V_79 ) ;
if ( V_76 -> V_84 != V_20 -> V_40 . V_84 . V_85 ||
V_49 -> V_57 != V_46 -> V_55 ) {
T_5 V_86 ;
V_86 . V_85 = V_76 -> V_84 ;
F_56 ( V_20 , & V_86 , V_49 -> V_57 ) ;
}
if ( V_20 -> V_40 . V_87 == V_88 )
V_17 -> V_89 = V_90 ;
}
F_57 ( V_17 , V_17 -> V_5 - V_29 - V_81 - 2 ) ;
F_58 ( V_17 , V_77 ) ;
if ( V_20 -> V_40 . V_87 == V_91 )
F_59 ( V_17 ) ;
else
F_60 ( V_17 , - V_79 ) ;
V_15 = V_80 [ 1 ] ;
if ( V_15 == V_92 )
V_15 = - V_83 ;
V_82:
return V_15 ;
}
static void F_61 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_62 ( V_17 , F_49 ( V_17 , V_15 ) ) ;
}
static int F_63 ( struct V_19 * V_20 , struct V_16 * V_17 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 = V_20 -> V_18 ;
struct V_12 * V_11 ;
struct V_16 * V_25 ;
int V_78 = V_17 -> V_5 - sizeof( * V_22 ) - F_2 ( V_2 ) ;
int V_3 ;
int V_32 ;
int V_33 ;
int V_4 ;
T_1 * V_34 ;
void * V_9 ;
T_2 * V_10 ;
struct V_7 * V_23 ;
struct V_7 * V_24 ;
int V_15 = - V_83 ;
if ( ! F_64 ( V_17 , sizeof( * V_22 ) + F_2 ( V_2 ) ) )
goto V_82;
if ( V_78 <= 0 )
goto V_82;
V_15 = F_28 ( V_17 , 0 , & V_25 ) ;
if ( V_15 < 0 )
goto V_82;
V_3 = V_15 ;
V_32 = sizeof( * V_22 ) ;
V_33 = 1 ;
V_4 = 0 ;
if ( V_20 -> V_40 . V_41 & V_42 ) {
V_33 += 2 ;
V_4 += sizeof( T_1 ) ;
V_32 += V_4 ;
}
V_15 = - V_43 ;
V_9 = F_1 ( V_2 , V_3 + V_33 , V_4 ) ;
if ( ! V_9 )
goto V_82;
F_20 ( V_17 ) -> V_9 = V_9 ;
V_34 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_14 ( V_2 , V_10 ) ;
V_24 = F_16 ( V_2 , V_11 ) ;
V_23 = V_24 + V_33 ;
V_17 -> V_89 = V_93 ;
V_22 = (struct V_21 * ) V_17 -> V_18 ;
V_10 = V_22 -> V_69 ;
F_40 ( V_23 , V_3 ) ;
F_41 ( V_17 , V_23 , sizeof( * V_22 ) + F_2 ( V_2 ) , V_78 ) ;
if ( ( V_20 -> V_40 . V_41 & V_42 ) ) {
F_40 ( V_24 , 3 ) ;
F_42 ( V_24 , & V_22 -> V_63 , sizeof( T_1 ) ) ;
* V_34 = F_39 ( V_17 ) -> V_66 . V_94 . V_70 ;
F_42 ( V_24 + 1 , V_34 , V_4 ) ;
F_42 ( V_24 + 2 , & V_22 -> V_65 , sizeof( T_1 ) ) ;
} else
F_43 ( V_24 , V_22 , sizeof( * V_22 ) ) ;
F_65 ( V_11 , 0 , F_61 , V_17 ) ;
F_66 ( V_11 , V_23 , V_23 , V_78 , V_10 ) ;
F_67 ( V_11 , V_24 , V_32 ) ;
V_15 = F_68 ( V_11 ) ;
if ( V_15 == - V_72 )
goto V_82;
V_15 = F_49 ( V_17 , V_15 ) ;
V_82:
return V_15 ;
}
static T_3 F_26 ( struct V_19 * V_20 , int V_95 )
{
struct V_1 * V_2 = V_20 -> V_18 ;
T_3 V_27 = F_5 ( F_27 ( V_2 ) , 4 ) ;
unsigned int V_96 ;
switch ( V_20 -> V_40 . V_87 ) {
case V_88 :
case V_97 :
V_96 = sizeof( struct V_75 ) ;
break;
case V_91 :
V_96 = 0 ;
break;
default:
F_53 () ;
}
return ( ( V_95 - V_20 -> V_40 . V_98 - F_23 ( V_2 ) -
V_96 ) & ~ ( V_27 - 1 ) ) + V_96 - 2 ;
}
static int F_69 ( struct V_16 * V_17 , T_3 V_99 )
{
struct V_100 * V_100 = F_70 ( V_17 -> V_101 ) ;
const struct V_75 * V_76 = ( const struct V_75 * ) V_17 -> V_18 ;
struct V_21 * V_22 = (struct V_21 * ) ( V_17 -> V_18 + ( V_76 -> V_79 << 2 ) ) ;
struct V_19 * V_20 ;
switch ( F_71 ( V_17 ) -> type ) {
case V_102 :
if ( F_71 ( V_17 ) -> V_103 != V_104 )
return 0 ;
case V_105 :
break;
default:
return 0 ;
}
V_20 = F_72 ( V_100 , V_17 -> V_106 , ( const T_5 * ) & V_76 -> V_107 ,
V_22 -> V_63 , V_45 , V_108 ) ;
if ( ! V_20 )
return 0 ;
if ( F_71 ( V_17 ) -> type == V_102 )
F_73 ( V_17 , V_100 , V_99 , 0 , 0 , V_45 , 0 ) ;
else
F_74 ( V_17 , V_100 , 0 , 0 , V_45 , 0 ) ;
F_75 ( V_20 ) ;
return 0 ;
}
static void F_76 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_18 ;
if ( ! V_2 )
return;
F_77 ( V_2 ) ;
}
static int F_78 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_79 ( V_20 -> V_2 -> V_109 , 0 , 0 ) ;
V_15 = F_80 ( V_2 ) ;
if ( F_81 ( V_2 ) )
goto error;
V_20 -> V_18 = V_2 ;
V_15 = F_82 ( V_2 , V_20 -> V_2 -> V_110 ,
( V_20 -> V_2 -> V_111 + 7 ) / 8 ) ;
if ( V_15 )
goto error;
V_15 = F_83 ( V_2 , V_20 -> V_2 -> V_112 / 8 ) ;
if ( V_15 )
goto error;
error:
return V_15 ;
}
static int F_84 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
char * V_117 ;
char * V_118 ;
char V_119 [ V_120 ] ;
unsigned int V_121 ;
int V_15 ;
V_15 = - V_83 ;
if ( ! V_20 -> V_122 )
goto error;
V_15 = - V_123 ;
if ( ( V_20 -> V_40 . V_41 & V_42 ) ) {
if ( snprintf ( V_119 , V_120 ,
L_1 ,
V_20 -> V_124 ? V_20 -> V_124 -> V_109 : L_2 ,
V_20 -> V_122 -> V_109 ) >= V_120 )
goto error;
} else {
if ( snprintf ( V_119 , V_120 ,
L_3 ,
V_20 -> V_124 ? V_20 -> V_124 -> V_109 : L_2 ,
V_20 -> V_122 -> V_109 ) >= V_120 )
goto error;
}
V_2 = F_79 ( V_119 , 0 , 0 ) ;
V_15 = F_80 ( V_2 ) ;
if ( F_81 ( V_2 ) )
goto error;
V_20 -> V_18 = V_2 ;
V_121 = ( V_20 -> V_124 ? ( V_20 -> V_124 -> V_111 + 7 ) / 8 : 0 ) +
( V_20 -> V_122 -> V_111 + 7 ) / 8 + F_85 ( sizeof( * V_114 ) ) ;
V_15 = - V_43 ;
V_117 = F_8 ( V_121 , V_125 ) ;
if ( ! V_117 )
goto error;
V_118 = V_117 ;
V_116 = ( void * ) V_118 ;
V_116 -> V_126 = V_127 ;
V_116 -> V_128 = F_86 ( sizeof( * V_114 ) ) ;
V_114 = F_87 ( V_116 ) ;
V_118 += F_85 ( sizeof( * V_114 ) ) ;
if ( V_20 -> V_124 ) {
struct V_129 * V_130 ;
memcpy ( V_118 , V_20 -> V_124 -> V_110 , ( V_20 -> V_124 -> V_111 + 7 ) / 8 ) ;
V_118 += ( V_20 -> V_124 -> V_111 + 7 ) / 8 ;
V_130 = F_88 ( V_20 -> V_124 -> V_109 , 0 ) ;
F_89 ( ! V_130 ) ;
V_15 = - V_83 ;
if ( V_130 -> V_131 . V_132 . V_133 / 8 !=
F_23 ( V_2 ) ) {
F_90 ( L_4 ,
V_20 -> V_124 -> V_109 ,
F_23 ( V_2 ) ,
V_130 -> V_131 . V_132 . V_133 / 8 ) ;
goto V_134;
}
V_15 = F_83 (
V_2 , V_20 -> V_124 -> V_135 / 8 ) ;
if ( V_15 )
goto V_134;
}
V_114 -> V_136 = F_91 ( ( V_20 -> V_122 -> V_111 + 7 ) / 8 ) ;
memcpy ( V_118 , V_20 -> V_122 -> V_110 , ( V_20 -> V_122 -> V_111 + 7 ) / 8 ) ;
V_15 = F_82 ( V_2 , V_117 , V_121 ) ;
V_134:
F_19 ( V_117 ) ;
error:
return V_15 ;
}
static int F_92 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
T_3 V_137 ;
int V_15 ;
V_20 -> V_18 = NULL ;
if ( V_20 -> V_2 )
V_15 = F_78 ( V_20 ) ;
else
V_15 = F_84 ( V_20 ) ;
if ( V_15 )
goto error;
V_2 = V_20 -> V_18 ;
V_20 -> V_40 . V_98 = sizeof( struct V_21 ) +
F_2 ( V_2 ) ;
if ( V_20 -> V_40 . V_87 == V_91 )
V_20 -> V_40 . V_98 += sizeof( struct V_75 ) ;
else if ( V_20 -> V_40 . V_87 == V_97 && V_20 -> V_138 . V_139 != V_140 )
V_20 -> V_40 . V_98 += V_141 ;
if ( V_20 -> V_46 ) {
struct V_47 * V_46 = V_20 -> V_46 ;
switch ( V_46 -> V_53 ) {
default:
goto error;
case V_60 :
V_20 -> V_40 . V_98 += sizeof( struct V_48 ) ;
break;
case V_61 :
V_20 -> V_40 . V_98 += sizeof( struct V_48 ) + 2 * sizeof( T_3 ) ;
break;
}
}
V_137 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_20 -> V_40 . V_142 = V_137 + 1 + F_23 ( V_2 ) ;
error:
return V_15 ;
}
static int F_93 ( struct V_16 * V_17 , int V_15 )
{
return 0 ;
}
static int T_6 F_94 ( void )
{
if ( F_95 ( & V_143 , V_108 ) < 0 ) {
F_90 ( L_5 , V_144 ) ;
return - V_145 ;
}
if ( F_96 ( & V_146 , V_45 ) < 0 ) {
F_90 ( L_6 , V_144 ) ;
F_97 ( & V_143 , V_108 ) ;
return - V_145 ;
}
return 0 ;
}
static void T_7 F_98 ( void )
{
if ( F_99 ( & V_146 , V_45 ) < 0 )
F_90 ( L_7 , V_144 ) ;
if ( F_97 ( & V_143 , V_108 ) < 0 )
F_90 ( L_8 , V_144 ) ;
}
