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
V_26 = V_20 -> V_18 ;
V_2 = V_26 -> V_2 ;
V_31 = F_23 ( V_2 ) ;
V_33 = 0 ;
if ( V_20 -> V_37 ) {
struct V_38 * V_39 = (struct V_38 * ) F_24 ( V_17 ) ;
T_3 V_40 ;
V_40 = F_25 ( V_20 -> V_37 , F_26 ( V_20 , V_39 -> V_41 ) ) ;
if ( V_17 -> V_5 < V_40 )
V_33 = V_40 - V_17 -> V_5 ;
}
V_29 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_30 = F_5 ( V_17 -> V_5 + 2 + V_33 , V_29 ) ;
if ( V_26 -> V_42 )
V_30 = F_5 ( V_30 , V_26 -> V_42 ) ;
V_32 = V_30 - V_17 -> V_5 - V_33 ;
V_15 = F_28 ( V_17 , V_33 + V_32 + V_31 , & V_27 ) ;
if ( V_15 < 0 )
goto error;
V_3 = V_15 ;
V_34 = sizeof( * V_22 ) ;
V_35 = 1 ;
V_4 = 0 ;
if ( V_20 -> V_43 . V_44 & V_45 ) {
V_35 += 2 ;
V_4 += sizeof( T_1 ) ;
V_34 += V_4 ;
}
V_9 = F_1 ( V_2 , V_3 + V_35 , V_4 ) ;
if ( ! V_9 ) {
V_15 = - V_46 ;
goto error;
}
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
if ( ( V_20 -> V_43 . V_44 & V_45 ) ) {
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
int V_42 ;
F_19 ( F_20 ( V_17 ) -> V_9 ) ;
if ( F_51 ( V_15 ) )
goto V_83;
if ( F_52 ( V_17 , V_17 -> V_5 - V_31 - 2 , V_82 , 2 ) )
F_53 () ;
V_15 = - V_84 ;
V_42 = V_82 [ 0 ] ;
if ( V_42 + 2 + V_31 >= V_80 )
goto V_83;
V_78 = F_54 ( V_17 ) ;
V_81 = V_78 -> V_81 * 4 ;
if ( V_20 -> V_49 ) {
struct V_50 * V_49 = V_20 -> V_49 ;
struct V_51 * V_52 = ( void * ) ( F_55 ( V_17 ) + V_81 ) ;
if ( V_78 -> V_85 != V_20 -> V_43 . V_85 . V_86 ||
V_52 -> V_60 != V_49 -> V_58 ) {
T_5 V_87 ;
V_87 . V_86 = V_78 -> V_85 ;
F_56 ( V_20 , & V_87 , V_52 -> V_60 ) ;
}
if ( V_20 -> V_43 . V_88 == V_89 )
V_17 -> V_90 = V_91 ;
}
F_57 ( V_17 , V_17 -> V_5 - V_31 - V_42 - 2 ) ;
F_58 ( V_17 , V_79 ) ;
if ( V_20 -> V_43 . V_88 == V_92 )
F_59 ( V_17 ) ;
else
F_60 ( V_17 , - V_81 ) ;
V_15 = V_82 [ 1 ] ;
if ( V_15 == V_93 )
V_15 = - V_84 ;
V_83:
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
if ( ! F_64 ( V_17 , sizeof( * V_22 ) + F_2 ( V_2 ) ) )
goto V_83;
if ( V_80 <= 0 )
goto V_83;
if ( ( V_15 = F_28 ( V_17 , 0 , & V_27 ) ) < 0 )
goto V_83;
V_3 = V_15 ;
V_34 = sizeof( * V_22 ) ;
V_35 = 1 ;
V_4 = 0 ;
if ( V_20 -> V_43 . V_44 & V_45 ) {
V_35 += 2 ;
V_4 += sizeof( T_1 ) ;
V_34 += V_4 ;
}
V_15 = - V_46 ;
V_9 = F_1 ( V_2 , V_3 + V_35 , V_4 ) ;
if ( ! V_9 )
goto V_83;
F_20 ( V_17 ) -> V_9 = V_9 ;
V_36 = F_9 ( V_9 ) ;
V_10 = F_11 ( V_2 , V_9 , V_4 ) ;
V_11 = F_14 ( V_2 , V_10 ) ;
V_24 = F_16 ( V_2 , V_11 ) ;
V_23 = V_24 + V_35 ;
V_17 -> V_90 = V_94 ;
V_22 = (struct V_21 * ) V_17 -> V_18 ;
V_10 = V_22 -> V_72 ;
F_40 ( V_23 , V_3 ) ;
F_41 ( V_17 , V_23 , sizeof( * V_22 ) + F_2 ( V_2 ) , V_80 ) ;
if ( ( V_20 -> V_43 . V_44 & V_45 ) ) {
F_40 ( V_24 , 3 ) ;
F_42 ( V_24 , & V_22 -> V_66 , sizeof( T_1 ) ) ;
* V_36 = F_39 ( V_17 ) -> V_69 . V_95 . V_73 ;
F_42 ( V_24 + 1 , V_36 , V_4 ) ;
F_42 ( V_24 + 2 , & V_22 -> V_68 , sizeof( T_1 ) ) ;
} else
F_43 ( V_24 , V_22 , sizeof( * V_22 ) ) ;
F_65 ( V_11 , 0 , F_61 , V_17 ) ;
F_66 ( V_11 , V_23 , V_23 , V_80 , V_10 ) ;
F_67 ( V_11 , V_24 , V_34 ) ;
V_15 = F_68 ( V_11 ) ;
if ( V_15 == - V_74 )
goto V_83;
V_15 = F_49 ( V_17 , V_15 ) ;
V_83:
return V_15 ;
}
static T_3 F_26 ( struct V_19 * V_20 , int V_96 )
{
struct V_25 * V_26 = V_20 -> V_18 ;
T_3 V_29 = F_5 ( F_27 ( V_26 -> V_2 ) , 4 ) ;
T_3 V_97 = F_69 ( T_3 , V_29 , V_26 -> V_42 ) ;
unsigned int V_98 ;
switch ( V_20 -> V_43 . V_88 ) {
case V_89 :
case V_99 :
V_98 = sizeof( struct V_77 ) ;
break;
case V_92 :
V_98 = 0 ;
break;
default:
F_53 () ;
}
return ( ( V_96 - V_20 -> V_43 . V_100 - F_23 ( V_26 -> V_2 ) -
V_98 ) & ~ ( V_97 - 1 ) ) + V_98 - 2 ;
}
static void F_70 ( struct V_16 * V_17 , T_3 V_101 )
{
struct V_102 * V_102 = F_71 ( V_17 -> V_103 ) ;
const struct V_77 * V_78 = ( const struct V_77 * ) V_17 -> V_18 ;
struct V_21 * V_22 = (struct V_21 * ) ( V_17 -> V_18 + ( V_78 -> V_81 << 2 ) ) ;
struct V_19 * V_20 ;
switch ( F_72 ( V_17 ) -> type ) {
case V_104 :
if ( F_72 ( V_17 ) -> V_105 != V_106 )
return;
case V_107 :
break;
default:
return;
}
V_20 = F_73 ( V_102 , V_17 -> V_108 , ( const T_5 * ) & V_78 -> V_109 ,
V_22 -> V_66 , V_48 , V_110 ) ;
if ( ! V_20 )
return;
if ( F_72 ( V_17 ) -> type == V_104 )
F_74 ( V_17 , V_102 , V_101 , 0 , 0 , V_48 , 0 ) ;
else
F_75 ( V_17 , V_102 , 0 , 0 , V_48 , 0 ) ;
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
V_2 = F_80 ( V_20 -> V_2 -> V_111 , 0 , 0 ) ;
V_15 = F_81 ( V_2 ) ;
if ( F_82 ( V_2 ) )
goto error;
V_26 -> V_2 = V_2 ;
V_15 = F_83 ( V_2 , V_20 -> V_2 -> V_112 ,
( V_20 -> V_2 -> V_113 + 7 ) / 8 ) ;
if ( V_15 )
goto error;
V_15 = F_84 ( V_2 , V_20 -> V_2 -> V_114 / 8 ) ;
if ( V_15 )
goto error;
error:
return V_15 ;
}
static int F_85 ( struct V_19 * V_20 )
{
struct V_25 * V_26 = V_20 -> V_18 ;
struct V_1 * V_2 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
char * V_119 ;
char * V_120 ;
char V_121 [ V_122 ] ;
unsigned int V_123 ;
int V_15 ;
V_15 = - V_84 ;
if ( V_20 -> V_124 == NULL )
goto error;
V_15 = - V_125 ;
if ( ( V_20 -> V_43 . V_44 & V_45 ) ) {
if ( snprintf ( V_121 , V_122 ,
L_1 ,
V_20 -> V_126 ? V_20 -> V_126 -> V_111 : L_2 ,
V_20 -> V_124 -> V_111 ) >= V_122 )
goto error;
} else {
if ( snprintf ( V_121 , V_122 ,
L_3 ,
V_20 -> V_126 ? V_20 -> V_126 -> V_111 : L_2 ,
V_20 -> V_124 -> V_111 ) >= V_122 )
goto error;
}
V_2 = F_80 ( V_121 , 0 , 0 ) ;
V_15 = F_81 ( V_2 ) ;
if ( F_82 ( V_2 ) )
goto error;
V_26 -> V_2 = V_2 ;
V_123 = ( V_20 -> V_126 ? ( V_20 -> V_126 -> V_113 + 7 ) / 8 : 0 ) +
( V_20 -> V_124 -> V_113 + 7 ) / 8 + F_86 ( sizeof( * V_116 ) ) ;
V_15 = - V_46 ;
V_119 = F_8 ( V_123 , V_127 ) ;
if ( ! V_119 )
goto error;
V_120 = V_119 ;
V_118 = ( void * ) V_120 ;
V_118 -> V_128 = V_129 ;
V_118 -> V_130 = F_87 ( sizeof( * V_116 ) ) ;
V_116 = F_88 ( V_118 ) ;
V_120 += F_86 ( sizeof( * V_116 ) ) ;
if ( V_20 -> V_126 ) {
struct V_131 * V_132 ;
memcpy ( V_120 , V_20 -> V_126 -> V_112 , ( V_20 -> V_126 -> V_113 + 7 ) / 8 ) ;
V_120 += ( V_20 -> V_126 -> V_113 + 7 ) / 8 ;
V_132 = F_89 ( V_20 -> V_126 -> V_111 , 0 ) ;
F_90 ( ! V_132 ) ;
V_15 = - V_84 ;
if ( V_132 -> V_133 . V_134 . V_135 / 8 !=
F_23 ( V_2 ) ) {
F_91 ( V_136 L_4 ,
V_20 -> V_126 -> V_111 ,
F_23 ( V_2 ) ,
V_132 -> V_133 . V_134 . V_135 / 8 ) ;
goto V_137;
}
V_15 = F_84 (
V_2 , V_20 -> V_126 -> V_138 / 8 ) ;
if ( V_15 )
goto V_137;
}
V_116 -> V_139 = F_92 ( ( V_20 -> V_124 -> V_113 + 7 ) / 8 ) ;
memcpy ( V_120 , V_20 -> V_124 -> V_112 , ( V_20 -> V_124 -> V_113 + 7 ) / 8 ) ;
V_15 = F_83 ( V_2 , V_119 , V_123 ) ;
V_137:
F_19 ( V_119 ) ;
error:
return V_15 ;
}
static int F_93 ( struct V_19 * V_20 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
T_3 V_97 ;
int V_15 ;
V_26 = F_94 ( sizeof( * V_26 ) , V_127 ) ;
if ( V_26 == NULL )
return - V_46 ;
V_20 -> V_18 = V_26 ;
if ( V_20 -> V_2 )
V_15 = F_79 ( V_20 ) ;
else
V_15 = F_85 ( V_20 ) ;
if ( V_15 )
goto error;
V_2 = V_26 -> V_2 ;
V_26 -> V_42 = 0 ;
V_20 -> V_43 . V_100 = sizeof( struct V_21 ) +
F_2 ( V_2 ) ;
if ( V_20 -> V_43 . V_88 == V_92 )
V_20 -> V_43 . V_100 += sizeof( struct V_77 ) ;
else if ( V_20 -> V_43 . V_88 == V_99 && V_20 -> V_140 . V_141 != V_142 )
V_20 -> V_43 . V_100 += V_143 ;
if ( V_20 -> V_49 ) {
struct V_50 * V_49 = V_20 -> V_49 ;
switch ( V_49 -> V_56 ) {
default:
goto error;
case V_63 :
V_20 -> V_43 . V_100 += sizeof( struct V_51 ) ;
break;
case V_64 :
V_20 -> V_43 . V_100 += sizeof( struct V_51 ) + 2 * sizeof( T_3 ) ;
break;
}
}
V_97 = F_5 ( F_27 ( V_2 ) , 4 ) ;
if ( V_26 -> V_42 )
V_97 = F_69 ( T_3 , V_97 , V_26 -> V_42 ) ;
V_20 -> V_43 . V_144 = V_97 + 1 + F_23 ( V_26 -> V_2 ) ;
error:
return V_15 ;
}
static int T_6 F_95 ( void )
{
if ( F_96 ( & V_145 , V_110 ) < 0 ) {
F_97 ( L_5 , V_146 ) ;
return - V_147 ;
}
if ( F_98 ( & V_148 , V_48 ) < 0 ) {
F_97 ( L_6 , V_146 ) ;
F_99 ( & V_145 , V_110 ) ;
return - V_147 ;
}
return 0 ;
}
static void T_7 F_100 ( void )
{
if ( F_101 ( & V_148 , V_48 ) < 0 )
F_97 ( L_7 , V_146 ) ;
if ( F_99 ( & V_145 , V_110 ) < 0 )
F_97 ( L_8 , V_146 ) ;
}
