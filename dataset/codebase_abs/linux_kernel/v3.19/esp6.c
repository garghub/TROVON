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
V_2 = V_21 -> V_19 ;
V_29 = F_23 ( V_2 ) ;
V_31 = 0 ;
if ( V_21 -> V_36 ) {
struct V_37 * V_38 = (struct V_37 * ) F_24 ( V_18 ) ;
T_3 V_39 ;
V_39 = F_25 ( V_21 -> V_36 , F_26 ( V_21 , V_38 -> V_40 ) ) ;
if ( V_18 -> V_5 < V_39 )
V_31 = V_39 - V_18 -> V_5 ;
}
V_27 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_28 = F_5 ( V_18 -> V_5 + 2 + V_31 , V_27 ) ;
V_30 = V_28 - V_18 -> V_5 - V_31 ;
V_16 = F_28 ( V_18 , V_31 + V_30 + V_29 , & V_26 ) ;
if ( V_16 < 0 )
goto error;
V_3 = V_16 ;
V_32 = sizeof( * V_23 ) ;
V_33 = 1 ;
V_10 = 0 ;
if ( V_21 -> V_41 . V_42 & V_43 ) {
V_33 += 2 ;
V_10 += sizeof( T_1 ) ;
V_32 += V_10 ;
}
V_9 = F_1 ( V_2 , V_3 + V_33 , V_10 ) ;
if ( ! V_9 ) {
V_16 = - V_44 ;
goto error;
}
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
int V_45 ;
for ( V_45 = 0 ; V_45 < V_30 - 2 ; V_45 ++ )
V_34 [ V_45 ] = V_45 + 1 ;
} while ( 0 );
V_34 [ V_30 - 2 ] = V_30 - 2 ;
V_34 [ V_30 - 1 ] = * F_30 ( V_18 ) ;
F_31 ( V_18 , V_26 , V_28 - V_18 -> V_5 + V_29 ) ;
F_32 ( V_18 , - F_33 ( V_18 ) ) ;
V_23 = V_22 ( V_18 ) ;
* F_30 ( V_18 ) = V_46 ;
V_23 -> V_47 = V_21 -> V_48 . V_47 ;
V_23 -> V_49 = F_34 ( F_35 ( V_18 ) -> V_50 . V_51 . V_52 ) ;
F_36 ( V_24 , V_3 ) ;
F_37 ( V_18 , V_24 ,
V_23 -> V_53 + F_2 ( V_2 ) - V_18 -> V_19 ,
V_28 + V_29 ) ;
if ( ( V_21 -> V_41 . V_42 & V_43 ) ) {
F_36 ( V_25 , 3 ) ;
F_38 ( V_25 , & V_23 -> V_47 , sizeof( T_1 ) ) ;
* V_35 = F_34 ( F_35 ( V_18 ) -> V_50 . V_51 . V_54 ) ;
F_38 ( V_25 + 1 , V_35 , V_10 ) ;
F_38 ( V_25 + 2 , & V_23 -> V_49 , sizeof( T_1 ) ) ;
} else
F_39 ( V_25 , V_23 , sizeof( * V_23 ) ) ;
F_40 ( V_12 , 0 , F_18 , V_18 ) ;
F_41 ( V_12 , V_24 , V_24 , V_28 , V_11 ) ;
F_42 ( V_12 , V_25 , V_32 ) ;
F_43 ( V_12 , V_23 -> V_53 ,
F_35 ( V_18 ) -> V_50 . V_51 . V_52 ) ;
F_20 ( V_18 ) -> V_9 = V_9 ;
V_16 = F_44 ( V_12 ) ;
if ( V_16 == - V_55 )
goto error;
if ( V_16 == - V_56 )
V_16 = V_57 ;
F_19 ( V_9 ) ;
error:
return V_16 ;
}
static int F_45 ( struct V_17 * V_18 , int V_16 )
{
struct V_20 * V_21 = F_46 ( V_18 ) ;
struct V_1 * V_2 = V_21 -> V_19 ;
int V_29 = F_23 ( V_2 ) ;
int V_58 = sizeof( struct V_22 ) + F_2 ( V_2 ) ;
int V_59 = V_18 -> V_5 - V_58 ;
int V_60 = F_47 ( V_18 ) ;
int V_61 ;
T_2 V_62 [ 2 ] ;
F_19 ( F_20 ( V_18 ) -> V_9 ) ;
if ( F_48 ( V_16 ) )
goto V_63;
if ( F_49 ( V_18 , V_18 -> V_5 - V_29 - 2 , V_62 , 2 ) )
F_50 () ;
V_16 = - V_64 ;
V_61 = V_62 [ 0 ] ;
if ( V_61 + 2 + V_29 >= V_59 ) {
F_51 ( L_1 ,
V_61 + 2 , V_59 - V_29 ) ;
goto V_63;
}
F_52 ( V_18 , V_18 -> V_5 - V_29 - V_61 - 2 ) ;
F_53 ( V_18 , V_58 ) ;
if ( V_21 -> V_41 . V_65 == V_66 )
F_54 ( V_18 ) ;
else
F_55 ( V_18 , - V_60 ) ;
V_16 = V_62 [ 1 ] ;
if ( V_16 == V_67 )
V_16 = - V_64 ;
V_63:
return V_16 ;
}
static void F_56 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = V_15 -> V_19 ;
F_57 ( V_18 , F_45 ( V_18 , V_16 ) ) ;
}
static int F_58 ( struct V_20 * V_21 , struct V_17 * V_18 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 = V_21 -> V_19 ;
struct V_13 * V_12 ;
struct V_17 * V_26 ;
int V_59 = V_18 -> V_5 - sizeof( * V_23 ) - F_2 ( V_2 ) ;
int V_3 ;
int V_32 ;
int V_33 ;
int V_10 ;
int V_68 = 0 ;
void * V_9 ;
T_1 * V_35 ;
T_2 * V_11 ;
struct V_7 * V_24 ;
struct V_7 * V_25 ;
if ( ! F_59 ( V_18 , sizeof( * V_23 ) + F_2 ( V_2 ) ) ) {
V_68 = - V_64 ;
goto V_63;
}
if ( V_59 <= 0 ) {
V_68 = - V_64 ;
goto V_63;
}
V_3 = F_28 ( V_18 , 0 , & V_26 ) ;
if ( V_3 < 0 ) {
V_68 = - V_64 ;
goto V_63;
}
V_68 = - V_44 ;
V_32 = sizeof( * V_23 ) ;
V_33 = 1 ;
V_10 = 0 ;
if ( V_21 -> V_41 . V_42 & V_43 ) {
V_33 += 2 ;
V_10 += sizeof( T_1 ) ;
V_32 += V_10 ;
}
V_9 = F_1 ( V_2 , V_3 + V_33 , V_10 ) ;
if ( ! V_9 )
goto V_63;
F_20 ( V_18 ) -> V_9 = V_9 ;
V_35 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_14 ( V_2 , V_11 ) ;
V_25 = F_16 ( V_2 , V_12 ) ;
V_24 = V_25 + V_33 ;
V_18 -> V_69 = V_70 ;
V_23 = (struct V_22 * ) V_18 -> V_19 ;
V_11 = V_23 -> V_53 ;
F_36 ( V_24 , V_3 ) ;
F_37 ( V_18 , V_24 , sizeof( * V_23 ) + F_2 ( V_2 ) , V_59 ) ;
if ( ( V_21 -> V_41 . V_42 & V_43 ) ) {
F_36 ( V_25 , 3 ) ;
F_38 ( V_25 , & V_23 -> V_47 , sizeof( T_1 ) ) ;
* V_35 = F_35 ( V_18 ) -> V_50 . V_71 . V_54 ;
F_38 ( V_25 + 1 , V_35 , V_10 ) ;
F_38 ( V_25 + 2 , & V_23 -> V_49 , sizeof( T_1 ) ) ;
} else
F_39 ( V_25 , V_23 , sizeof( * V_23 ) ) ;
F_60 ( V_12 , 0 , F_56 , V_18 ) ;
F_61 ( V_12 , V_24 , V_24 , V_59 , V_11 ) ;
F_62 ( V_12 , V_25 , V_32 ) ;
V_68 = F_63 ( V_12 ) ;
if ( V_68 == - V_55 )
goto V_63;
V_68 = F_45 ( V_18 , V_68 ) ;
V_63:
return V_68 ;
}
static T_3 F_26 ( struct V_20 * V_21 , int V_72 )
{
struct V_1 * V_2 = V_21 -> V_19 ;
T_3 V_27 = F_5 ( F_27 ( V_2 ) , 4 ) ;
unsigned int V_73 ;
if ( V_21 -> V_41 . V_65 != V_66 )
V_73 = sizeof( struct V_74 ) ;
else
V_73 = 0 ;
return ( ( V_72 - V_21 -> V_41 . V_75 - F_23 ( V_2 ) -
V_73 ) & ~ ( V_27 - 1 ) ) + V_73 - 2 ;
}
static int F_64 ( struct V_17 * V_18 , struct V_76 * V_77 ,
T_2 type , T_2 V_78 , int V_79 , T_1 V_80 )
{
struct V_81 * V_81 = F_65 ( V_18 -> V_82 ) ;
const struct V_74 * V_83 = ( const struct V_74 * ) V_18 -> V_19 ;
struct V_22 * V_23 = (struct V_22 * ) ( V_18 -> V_19 + V_79 ) ;
struct V_20 * V_21 ;
if ( type != V_84 &&
type != V_85 )
return 0 ;
V_21 = F_66 ( V_81 , V_18 -> V_86 , ( const V_87 * ) & V_83 -> V_88 ,
V_23 -> V_47 , V_46 , V_89 ) ;
if ( ! V_21 )
return 0 ;
if ( type == V_85 )
F_67 ( V_18 , V_81 , V_18 -> V_82 -> V_90 , 0 ) ;
else
F_68 ( V_18 , V_81 , V_80 , 0 , 0 ) ;
F_69 ( V_21 ) ;
return 0 ;
}
static void F_70 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_19 ;
if ( ! V_2 )
return;
F_71 ( V_2 ) ;
}
static int F_72 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_73 ( V_21 -> V_2 -> V_91 , 0 , 0 ) ;
V_16 = F_74 ( V_2 ) ;
if ( F_75 ( V_2 ) )
goto error;
V_21 -> V_19 = V_2 ;
V_16 = F_76 ( V_2 , V_21 -> V_2 -> V_92 ,
( V_21 -> V_2 -> V_93 + 7 ) / 8 ) ;
if ( V_16 )
goto error;
V_16 = F_77 ( V_2 , V_21 -> V_2 -> V_94 / 8 ) ;
if ( V_16 )
goto error;
error:
return V_16 ;
}
static int F_78 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
char * V_99 ;
char * V_100 ;
char V_101 [ V_102 ] ;
unsigned int V_103 ;
int V_16 ;
V_16 = - V_64 ;
if ( V_21 -> V_104 == NULL )
goto error;
V_16 = - V_105 ;
if ( ( V_21 -> V_41 . V_42 & V_43 ) ) {
if ( snprintf ( V_101 , V_102 ,
L_2 ,
V_21 -> V_106 ? V_21 -> V_106 -> V_91 : L_3 ,
V_21 -> V_104 -> V_91 ) >= V_102 )
goto error;
} else {
if ( snprintf ( V_101 , V_102 ,
L_4 ,
V_21 -> V_106 ? V_21 -> V_106 -> V_91 : L_3 ,
V_21 -> V_104 -> V_91 ) >= V_102 )
goto error;
}
V_2 = F_73 ( V_101 , 0 , 0 ) ;
V_16 = F_74 ( V_2 ) ;
if ( F_75 ( V_2 ) )
goto error;
V_21 -> V_19 = V_2 ;
V_103 = ( V_21 -> V_106 ? ( V_21 -> V_106 -> V_93 + 7 ) / 8 : 0 ) +
( V_21 -> V_104 -> V_93 + 7 ) / 8 + F_79 ( sizeof( * V_96 ) ) ;
V_16 = - V_44 ;
V_99 = F_8 ( V_103 , V_107 ) ;
if ( ! V_99 )
goto error;
V_100 = V_99 ;
V_98 = ( void * ) V_100 ;
V_98 -> V_108 = V_109 ;
V_98 -> V_110 = F_80 ( sizeof( * V_96 ) ) ;
V_96 = F_81 ( V_98 ) ;
V_100 += F_79 ( sizeof( * V_96 ) ) ;
if ( V_21 -> V_106 ) {
struct V_111 * V_112 ;
memcpy ( V_100 , V_21 -> V_106 -> V_92 , ( V_21 -> V_106 -> V_93 + 7 ) / 8 ) ;
V_100 += ( V_21 -> V_106 -> V_93 + 7 ) / 8 ;
V_112 = F_82 ( V_21 -> V_106 -> V_91 , 0 ) ;
F_83 ( ! V_112 ) ;
V_16 = - V_64 ;
if ( V_112 -> V_113 . V_114 . V_115 / 8 !=
F_23 ( V_2 ) ) {
F_84 ( L_5 ,
V_21 -> V_106 -> V_91 ,
F_23 ( V_2 ) ,
V_112 -> V_113 . V_114 . V_115 / 8 ) ;
goto V_116;
}
V_16 = F_77 (
V_2 , V_21 -> V_106 -> V_117 / 8 ) ;
if ( V_16 )
goto V_116;
}
V_96 -> V_118 = F_85 ( ( V_21 -> V_104 -> V_93 + 7 ) / 8 ) ;
memcpy ( V_100 , V_21 -> V_104 -> V_92 , ( V_21 -> V_104 -> V_93 + 7 ) / 8 ) ;
V_16 = F_76 ( V_2 , V_99 , V_103 ) ;
V_116:
F_19 ( V_99 ) ;
error:
return V_16 ;
}
static int F_86 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
T_3 V_119 ;
int V_16 ;
if ( V_21 -> V_120 )
return - V_64 ;
V_21 -> V_19 = NULL ;
if ( V_21 -> V_2 )
V_16 = F_72 ( V_21 ) ;
else
V_16 = F_78 ( V_21 ) ;
if ( V_16 )
goto error;
V_2 = V_21 -> V_19 ;
V_21 -> V_41 . V_75 = sizeof( struct V_22 ) +
F_2 ( V_2 ) ;
switch ( V_21 -> V_41 . V_65 ) {
case V_121 :
if ( V_21 -> V_122 . V_123 != V_89 )
V_21 -> V_41 . V_75 += V_124 +
( sizeof( struct V_74 ) - sizeof( struct V_125 ) ) ;
break;
case V_126 :
break;
case V_66 :
V_21 -> V_41 . V_75 += sizeof( struct V_74 ) ;
break;
default:
goto error;
}
V_119 = F_5 ( F_27 ( V_2 ) , 4 ) ;
V_21 -> V_41 . V_127 = V_119 + 1 + F_23 ( V_2 ) ;
error:
return V_16 ;
}
static int F_87 ( struct V_17 * V_18 , int V_16 )
{
return 0 ;
}
static int T_4 F_88 ( void )
{
if ( F_89 ( & V_128 , V_89 ) < 0 ) {
F_84 ( L_6 , V_129 ) ;
return - V_130 ;
}
if ( F_90 ( & V_131 , V_46 ) < 0 ) {
F_84 ( L_7 , V_129 ) ;
F_91 ( & V_128 , V_89 ) ;
return - V_130 ;
}
return 0 ;
}
static void T_5 F_92 ( void )
{
if ( F_93 ( & V_131 , V_46 ) < 0 )
F_84 ( L_8 , V_129 ) ;
if ( F_91 ( & V_128 , V_89 ) < 0 )
F_84 ( L_9 , V_129 ) ;
}
