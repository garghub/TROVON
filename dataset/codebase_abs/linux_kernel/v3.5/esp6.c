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
static inline T_2 * F_11 ( struct V_1 * V_2 , void * V_9 , int V_10 )
{
return F_2 ( V_2 ) ?
F_10 ( ( T_2 * ) V_9 + V_10 ,
F_3 ( V_2 ) + 1 ) : V_9 + V_10 ;
}
static inline struct V_6 * F_12 (
struct V_1 * V_2 , T_2 * V_11 )
{
struct V_6 * V_12 ;
V_12 = ( void * ) F_10 ( V_11 + F_2 ( V_2 ) ,
F_4 () ) ;
F_13 ( V_12 , V_2 ) ;
return V_12 ;
}
static inline struct V_13 * F_14 ( struct V_1 * V_2 , T_2 * V_11 )
{
struct V_13 * V_12 ;
V_12 = ( void * ) F_10 ( V_11 + F_2 ( V_2 ) ,
F_4 () ) ;
F_15 ( V_12 , V_2 ) ;
return V_12 ;
}
static inline struct V_7 * F_16 ( struct V_1 * V_2 ,
struct V_13 * V_12 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_12 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static inline struct V_7 * F_17 (
struct V_1 * V_2 , struct V_6 * V_12 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_12 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static void F_18 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
F_19 ( F_20 ( V_18 ) -> V_9 ) ;
F_21 ( V_18 , V_16 ) ;
}
static int F_22 ( struct V_20 * V_21 , struct V_17 * V_18 )
{
int V_16 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_24 ;
struct V_7 * V_25 ;
struct V_17 * V_26 ;
void * V_9 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_3 ;
int V_32 ;
int V_33 ;
int V_10 ;
T_2 * V_11 ;
T_2 * V_34 ;
T_1 * V_35 ;
struct V_36 * V_37 = V_21 -> V_19 ;
V_16 = - V_38 ;
V_2 = V_37 -> V_2 ;
V_29 = F_23 ( V_2 ) ;
V_31 = 0 ;
if ( V_21 -> V_39 ) {
struct V_40 * V_41 = (struct V_40 * ) F_24 ( V_18 ) ;
T_3 V_42 ;
V_42 = F_25 ( V_21 -> V_39 , F_26 ( V_21 , V_41 -> V_43 ) ) ;
if ( V_18 -> V_5 < V_42 )
V_31 = V_42 - V_18 -> V_5 ;
}
V_27 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_28 = F_5 ( V_18 -> V_5 + 2 + V_31 , V_27 ) ;
if ( V_37 -> V_44 )
V_28 = F_5 ( V_28 , V_37 -> V_44 ) ;
V_30 = V_28 - V_18 -> V_5 - V_31 ;
V_16 = F_28 ( V_18 , V_31 + V_30 + V_29 , & V_26 ) ;
if ( V_16 < 0 )
goto error;
V_3 = V_16 ;
V_32 = sizeof( * V_23 ) ;
V_33 = 1 ;
V_10 = 0 ;
if ( V_21 -> V_45 . V_46 & V_47 ) {
V_33 += 2 ;
V_10 += sizeof( T_1 ) ;
V_32 += V_10 ;
}
V_9 = F_1 ( V_2 , V_3 + V_33 , V_10 ) ;
if ( ! V_9 )
goto error;
V_35 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_25 = F_17 ( V_2 , V_12 ) ;
V_24 = V_25 + V_33 ;
V_34 = F_29 ( V_26 ) ;
if ( V_31 ) {
memset ( V_34 , 0 , V_31 ) ;
V_34 += V_31 ;
}
do {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_30 - 2 ; V_48 ++ )
V_34 [ V_48 ] = V_48 + 1 ;
} while ( 0 );
V_34 [ V_30 - 2 ] = V_30 - 2 ;
V_34 [ V_30 - 1 ] = * F_30 ( V_18 ) ;
F_31 ( V_18 , V_26 , V_28 - V_18 -> V_5 + V_29 ) ;
F_32 ( V_18 , - F_33 ( V_18 ) ) ;
V_23 = V_22 ( V_18 ) ;
* F_30 ( V_18 ) = V_49 ;
V_23 -> V_50 = V_21 -> V_51 . V_50 ;
V_23 -> V_52 = F_34 ( F_35 ( V_18 ) -> V_53 . V_54 . V_55 ) ;
F_36 ( V_24 , V_3 ) ;
F_37 ( V_18 , V_24 ,
V_23 -> V_56 + F_2 ( V_2 ) - V_18 -> V_19 ,
V_28 + V_29 ) ;
if ( ( V_21 -> V_45 . V_46 & V_47 ) ) {
F_36 ( V_25 , 3 ) ;
F_38 ( V_25 , & V_23 -> V_50 , sizeof( T_1 ) ) ;
* V_35 = F_34 ( F_35 ( V_18 ) -> V_53 . V_54 . V_57 ) ;
F_38 ( V_25 + 1 , V_35 , V_10 ) ;
F_38 ( V_25 + 2 , & V_23 -> V_52 , sizeof( T_1 ) ) ;
} else
F_39 ( V_25 , V_23 , sizeof( * V_23 ) ) ;
F_40 ( V_12 , 0 , F_18 , V_18 ) ;
F_41 ( V_12 , V_24 , V_24 , V_28 , V_11 ) ;
F_42 ( V_12 , V_25 , V_32 ) ;
F_43 ( V_12 , V_23 -> V_56 ,
F_35 ( V_18 ) -> V_53 . V_54 . V_55 ) ;
F_20 ( V_18 ) -> V_9 = V_9 ;
V_16 = F_44 ( V_12 ) ;
if ( V_16 == - V_58 )
goto error;
if ( V_16 == - V_59 )
V_16 = V_60 ;
F_19 ( V_9 ) ;
error:
return V_16 ;
}
static int F_45 ( struct V_17 * V_18 , int V_16 )
{
struct V_20 * V_21 = F_46 ( V_18 ) ;
struct V_36 * V_37 = V_21 -> V_19 ;
struct V_1 * V_2 = V_37 -> V_2 ;
int V_29 = F_23 ( V_2 ) ;
int V_61 = sizeof( struct V_22 ) + F_2 ( V_2 ) ;
int V_62 = V_18 -> V_5 - V_61 ;
int V_63 = F_47 ( V_18 ) ;
int V_44 ;
T_2 V_64 [ 2 ] ;
F_19 ( F_20 ( V_18 ) -> V_9 ) ;
if ( F_48 ( V_16 ) )
goto V_65;
if ( F_49 ( V_18 , V_18 -> V_5 - V_29 - 2 , V_64 , 2 ) )
F_50 () ;
V_16 = - V_66 ;
V_44 = V_64 [ 0 ] ;
if ( V_44 + 2 + V_29 >= V_62 ) {
F_51 ( V_67 L_1
L_2 , V_44 + 2 , V_62 - V_29 ) ;
goto V_65;
}
F_52 ( V_18 , V_18 -> V_5 - V_29 - V_44 - 2 ) ;
F_53 ( V_18 , V_61 ) ;
F_54 ( V_18 , - V_63 ) ;
V_16 = V_64 [ 1 ] ;
if ( V_16 == V_68 )
V_16 = - V_66 ;
V_65:
return V_16 ;
}
static void F_55 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
F_56 ( V_18 , F_45 ( V_18 , V_16 ) ) ;
}
static int F_57 ( struct V_20 * V_21 , struct V_17 * V_18 )
{
struct V_22 * V_23 ;
struct V_36 * V_37 = V_21 -> V_19 ;
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_13 * V_12 ;
struct V_17 * V_26 ;
int V_62 = V_18 -> V_5 - sizeof( * V_23 ) - F_2 ( V_2 ) ;
int V_3 ;
int V_32 ;
int V_33 ;
int V_10 ;
int V_69 = 0 ;
void * V_9 ;
T_1 * V_35 ;
T_2 * V_11 ;
struct V_7 * V_24 ;
struct V_7 * V_25 ;
if ( ! F_58 ( V_18 , sizeof( * V_23 ) + F_2 ( V_2 ) ) ) {
V_69 = - V_66 ;
goto V_65;
}
if ( V_62 <= 0 ) {
V_69 = - V_66 ;
goto V_65;
}
if ( ( V_3 = F_28 ( V_18 , 0 , & V_26 ) ) < 0 ) {
V_69 = - V_66 ;
goto V_65;
}
V_69 = - V_38 ;
V_32 = sizeof( * V_23 ) ;
V_33 = 1 ;
V_10 = 0 ;
if ( V_21 -> V_45 . V_46 & V_47 ) {
V_33 += 2 ;
V_10 += sizeof( T_1 ) ;
V_32 += V_10 ;
}
V_9 = F_1 ( V_2 , V_3 + V_33 , V_10 ) ;
if ( ! V_9 )
goto V_65;
F_20 ( V_18 ) -> V_9 = V_9 ;
V_35 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_14 ( V_2 , V_11 ) ;
V_25 = F_16 ( V_2 , V_12 ) ;
V_24 = V_25 + V_33 ;
V_18 -> V_70 = V_71 ;
V_23 = (struct V_22 * ) V_18 -> V_19 ;
V_11 = V_23 -> V_56 ;
F_36 ( V_24 , V_3 ) ;
F_37 ( V_18 , V_24 , sizeof( * V_23 ) + F_2 ( V_2 ) , V_62 ) ;
if ( ( V_21 -> V_45 . V_46 & V_47 ) ) {
F_36 ( V_25 , 3 ) ;
F_38 ( V_25 , & V_23 -> V_50 , sizeof( T_1 ) ) ;
* V_35 = F_35 ( V_18 ) -> V_53 . V_72 . V_57 ;
F_38 ( V_25 + 1 , V_35 , V_10 ) ;
F_38 ( V_25 + 2 , & V_23 -> V_52 , sizeof( T_1 ) ) ;
} else
F_39 ( V_25 , V_23 , sizeof( * V_23 ) ) ;
F_59 ( V_12 , 0 , F_55 , V_18 ) ;
F_60 ( V_12 , V_24 , V_24 , V_62 , V_11 ) ;
F_61 ( V_12 , V_25 , V_32 ) ;
V_69 = F_62 ( V_12 ) ;
if ( V_69 == - V_58 )
goto V_65;
V_69 = F_45 ( V_18 , V_69 ) ;
V_65:
return V_69 ;
}
static T_3 F_26 ( struct V_20 * V_21 , int V_73 )
{
struct V_36 * V_37 = V_21 -> V_19 ;
T_3 V_27 = F_5 ( F_27 ( V_37 -> V_2 ) , 4 ) ;
T_3 V_74 = F_63 ( T_3 , V_27 , V_37 -> V_44 ) ;
unsigned int V_75 ;
if ( V_21 -> V_45 . V_76 != V_77 )
V_75 = sizeof( struct V_78 ) ;
else
V_75 = 0 ;
return ( ( V_73 - V_21 -> V_45 . V_79 - F_23 ( V_37 -> V_2 ) -
V_75 ) & ~ ( V_74 - 1 ) ) + ( V_75 - 2 ) ;
}
static void F_64 ( struct V_17 * V_18 , struct V_80 * V_81 ,
T_2 type , T_2 V_82 , int V_83 , T_1 V_84 )
{
struct V_85 * V_85 = F_65 ( V_18 -> V_86 ) ;
const struct V_78 * V_87 = ( const struct V_78 * ) V_18 -> V_19 ;
struct V_22 * V_23 = (struct V_22 * ) ( V_18 -> V_19 + V_83 ) ;
struct V_20 * V_21 ;
if ( type != V_88 &&
type != V_89 )
return;
V_21 = F_66 ( V_85 , V_18 -> V_90 , ( const V_91 * ) & V_87 -> V_92 ,
V_23 -> V_50 , V_49 , V_93 ) ;
if ( ! V_21 )
return;
F_67 ( L_3 ,
F_68 ( V_23 -> V_50 ) , & V_87 -> V_92 ) ;
F_69 ( V_21 ) ;
}
static void F_70 ( struct V_20 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_19 ;
if ( ! V_37 )
return;
F_71 ( V_37 -> V_2 ) ;
F_19 ( V_37 ) ;
}
static int F_72 ( struct V_20 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_19 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_73 ( V_21 -> V_2 -> V_94 , 0 , 0 ) ;
V_16 = F_74 ( V_2 ) ;
if ( F_75 ( V_2 ) )
goto error;
V_37 -> V_2 = V_2 ;
V_16 = F_76 ( V_2 , V_21 -> V_2 -> V_95 ,
( V_21 -> V_2 -> V_96 + 7 ) / 8 ) ;
if ( V_16 )
goto error;
V_16 = F_77 ( V_2 , V_21 -> V_2 -> V_97 / 8 ) ;
if ( V_16 )
goto error;
error:
return V_16 ;
}
static int F_78 ( struct V_20 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_19 ;
struct V_1 * V_2 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
char * V_102 ;
char * V_103 ;
char V_104 [ V_105 ] ;
unsigned int V_106 ;
int V_16 ;
V_16 = - V_66 ;
if ( V_21 -> V_107 == NULL )
goto error;
V_16 = - V_108 ;
if ( ( V_21 -> V_45 . V_46 & V_47 ) ) {
if ( snprintf ( V_104 , V_105 ,
L_4 ,
V_21 -> V_109 ? V_21 -> V_109 -> V_94 : L_5 ,
V_21 -> V_107 -> V_94 ) >= V_105 )
goto error;
} else {
if ( snprintf ( V_104 , V_105 ,
L_6 ,
V_21 -> V_109 ? V_21 -> V_109 -> V_94 : L_5 ,
V_21 -> V_107 -> V_94 ) >= V_105 )
goto error;
}
V_2 = F_73 ( V_104 , 0 , 0 ) ;
V_16 = F_74 ( V_2 ) ;
if ( F_75 ( V_2 ) )
goto error;
V_37 -> V_2 = V_2 ;
V_106 = ( V_21 -> V_109 ? ( V_21 -> V_109 -> V_96 + 7 ) / 8 : 0 ) +
( V_21 -> V_107 -> V_96 + 7 ) / 8 + F_79 ( sizeof( * V_99 ) ) ;
V_16 = - V_38 ;
V_102 = F_8 ( V_106 , V_110 ) ;
if ( ! V_102 )
goto error;
V_103 = V_102 ;
V_101 = ( void * ) V_103 ;
V_101 -> V_111 = V_112 ;
V_101 -> V_113 = F_80 ( sizeof( * V_99 ) ) ;
V_99 = F_81 ( V_101 ) ;
V_103 += F_79 ( sizeof( * V_99 ) ) ;
if ( V_21 -> V_109 ) {
struct V_114 * V_115 ;
memcpy ( V_103 , V_21 -> V_109 -> V_95 , ( V_21 -> V_109 -> V_96 + 7 ) / 8 ) ;
V_103 += ( V_21 -> V_109 -> V_96 + 7 ) / 8 ;
V_115 = F_82 ( V_21 -> V_109 -> V_94 , 0 ) ;
F_83 ( ! V_115 ) ;
V_16 = - V_66 ;
if ( V_115 -> V_116 . V_117 . V_118 / 8 !=
F_23 ( V_2 ) ) {
F_84 ( V_119 L_7 ,
V_21 -> V_109 -> V_94 ,
F_23 ( V_2 ) ,
V_115 -> V_116 . V_117 . V_118 / 8 ) ;
goto V_120;
}
V_16 = F_77 (
V_2 , V_21 -> V_109 -> V_121 / 8 ) ;
if ( V_16 )
goto V_120;
}
V_99 -> V_122 = F_85 ( ( V_21 -> V_107 -> V_96 + 7 ) / 8 ) ;
memcpy ( V_103 , V_21 -> V_107 -> V_95 , ( V_21 -> V_107 -> V_96 + 7 ) / 8 ) ;
V_16 = F_76 ( V_2 , V_102 , V_106 ) ;
V_120:
F_19 ( V_102 ) ;
error:
return V_16 ;
}
static int F_86 ( struct V_20 * V_21 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 ;
T_3 V_74 ;
int V_16 ;
if ( V_21 -> V_123 )
return - V_66 ;
V_37 = F_87 ( sizeof( * V_37 ) , V_110 ) ;
if ( V_37 == NULL )
return - V_38 ;
V_21 -> V_19 = V_37 ;
if ( V_21 -> V_2 )
V_16 = F_72 ( V_21 ) ;
else
V_16 = F_78 ( V_21 ) ;
if ( V_16 )
goto error;
V_2 = V_37 -> V_2 ;
V_37 -> V_44 = 0 ;
V_21 -> V_45 . V_79 = sizeof( struct V_22 ) +
F_2 ( V_2 ) ;
switch ( V_21 -> V_45 . V_76 ) {
case V_124 :
if ( V_21 -> V_125 . V_126 != V_93 )
V_21 -> V_45 . V_79 += V_127 +
( sizeof( struct V_78 ) - sizeof( struct V_128 ) ) ;
break;
case V_129 :
break;
case V_77 :
V_21 -> V_45 . V_79 += sizeof( struct V_78 ) ;
break;
default:
goto error;
}
V_74 = F_5 ( F_27 ( V_2 ) , 4 ) ;
if ( V_37 -> V_44 )
V_74 = F_63 ( T_3 , V_74 , V_37 -> V_44 ) ;
V_21 -> V_45 . V_130 = V_74 + 1 + F_23 ( V_37 -> V_2 ) ;
error:
return V_16 ;
}
static int T_4 F_88 ( void )
{
if ( F_89 ( & V_131 , V_93 ) < 0 ) {
F_90 ( L_8 , V_132 ) ;
return - V_133 ;
}
if ( F_91 ( & V_134 , V_49 ) < 0 ) {
F_90 ( L_9 , V_132 ) ;
F_92 ( & V_131 , V_93 ) ;
return - V_133 ;
}
return 0 ;
}
static void T_5 F_93 ( void )
{
if ( F_94 ( & V_134 , V_49 ) < 0 )
F_90 ( L_10 , V_132 ) ;
if ( F_92 ( & V_131 , V_93 ) < 0 )
F_90 ( L_11 , V_132 ) ;
}
