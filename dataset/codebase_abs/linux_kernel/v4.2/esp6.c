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
static inline struct V_6 * F_12 ( struct V_1 * V_2 , T_2 * V_11 )
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
T_1 * V_22 = F_9 ( V_9 ) ;
V_21 -> V_23 = V_21 -> V_24 ;
V_21 -> V_24 = * V_22 ;
}
static void F_20 ( struct V_16 * V_17 )
{
F_19 ( V_17 , F_21 ( V_17 ) - sizeof( T_1 ) ) ;
}
static void F_22 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_20 ( V_17 ) ;
F_15 ( V_14 , V_15 ) ;
}
static int F_23 ( struct V_25 * V_26 , struct V_16 * V_17 )
{
int V_15 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_27 ;
struct V_16 * V_28 ;
void * V_9 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_33 ;
int V_34 ;
int V_3 ;
int V_35 ;
int V_10 ;
T_2 * V_11 ;
T_2 * V_36 ;
T_1 * V_22 ;
T_3 V_37 ;
V_2 = V_26 -> V_18 ;
V_31 = F_24 ( V_2 ) ;
V_33 = F_2 ( V_2 ) ;
V_34 = 0 ;
if ( V_26 -> V_38 ) {
struct V_39 * V_40 = (struct V_39 * ) F_25 ( V_17 ) ;
T_4 V_41 ;
V_41 = F_26 ( V_26 -> V_38 , F_27 ( V_26 , V_40 -> V_42 ) ) ;
if ( V_17 -> V_5 < V_41 )
V_34 = V_41 - V_17 -> V_5 ;
}
V_29 = F_5 ( F_28 ( V_2 ) , 4 ) ;
V_30 = F_5 ( V_17 -> V_5 + 2 + V_34 , V_29 ) ;
V_32 = V_30 - V_17 -> V_5 - V_34 ;
V_15 = F_29 ( V_17 , V_34 + V_32 + V_31 , & V_28 ) ;
if ( V_15 < 0 )
goto error;
V_3 = V_15 ;
V_35 = sizeof( * V_21 ) ;
V_10 = 0 ;
if ( V_26 -> V_43 . V_44 & V_45 ) {
V_10 += sizeof( T_1 ) ;
V_35 += V_10 ;
}
V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! V_9 ) {
V_15 = - V_46 ;
goto error;
}
V_22 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_27 = F_14 ( V_2 , V_12 ) ;
V_36 = F_30 ( V_28 ) ;
if ( V_34 ) {
memset ( V_36 , 0 , V_34 ) ;
V_36 += V_34 ;
}
do {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_32 - 2 ; V_47 ++ )
V_36 [ V_47 ] = V_47 + 1 ;
} while ( 0 );
V_36 [ V_32 - 2 ] = V_32 - 2 ;
V_36 [ V_32 - 1 ] = * F_31 ( V_17 ) ;
F_32 ( V_17 , V_28 , V_30 - V_17 -> V_5 + V_31 ) ;
F_33 ( V_17 , - F_34 ( V_17 ) ) ;
V_21 = V_20 ( V_17 ) ;
* F_31 ( V_17 ) = V_48 ;
V_21 -> V_23 = F_35 ( F_36 ( V_17 ) -> V_49 . V_50 . V_51 ) ;
F_37 ( V_12 , 0 , F_15 , V_17 ) ;
if ( ( V_26 -> V_43 . V_44 & V_45 ) ) {
V_21 = ( void * ) ( F_38 ( V_17 ) - sizeof( T_1 ) ) ;
* V_22 = V_21 -> V_24 ;
V_21 -> V_23 = F_35 ( F_36 ( V_17 ) -> V_49 . V_50 . V_52 ) ;
F_37 ( V_12 , 0 , F_22 , V_17 ) ;
}
V_21 -> V_24 = V_26 -> V_53 . V_24 ;
F_39 ( V_27 , V_3 ) ;
F_40 ( V_17 , V_27 ,
( unsigned char * ) V_21 - V_17 -> V_18 ,
V_35 + V_33 + V_30 + V_31 ) ;
F_41 ( V_12 , V_27 , V_27 , V_33 + V_30 , V_11 ) ;
F_42 ( V_12 , V_35 ) ;
V_37 = F_43 ( F_36 ( V_17 ) -> V_49 . V_50 . V_51 +
( ( V_54 ) F_36 ( V_17 ) -> V_49 . V_50 . V_52 << 32 ) ) ;
memset ( V_11 , 0 , V_33 ) ;
memcpy ( V_11 + V_33 - F_26 ( V_33 , 8 ) , ( T_2 * ) & V_37 + 8 - F_26 ( V_33 , 8 ) ,
F_26 ( V_33 , 8 ) ) ;
F_17 ( V_17 ) -> V_9 = V_9 ;
V_15 = F_44 ( V_12 ) ;
switch ( V_15 ) {
case - V_55 :
goto error;
case - V_56 :
V_15 = V_57 ;
break;
case 0 :
if ( ( V_26 -> V_43 . V_44 & V_45 ) )
F_20 ( V_17 ) ;
}
F_16 ( V_9 ) ;
error:
return V_15 ;
}
static int F_45 ( struct V_16 * V_17 , int V_15 )
{
struct V_25 * V_26 = F_46 ( V_17 ) ;
struct V_1 * V_2 = V_26 -> V_18 ;
int V_31 = F_24 ( V_2 ) ;
int V_58 = sizeof( struct V_20 ) + F_2 ( V_2 ) ;
int V_59 = V_17 -> V_5 - V_58 ;
int V_60 = F_47 ( V_17 ) ;
int V_61 ;
T_2 V_62 [ 2 ] ;
F_16 ( F_17 ( V_17 ) -> V_9 ) ;
if ( F_48 ( V_15 ) )
goto V_63;
if ( F_49 ( V_17 , V_17 -> V_5 - V_31 - 2 , V_62 , 2 ) )
F_50 () ;
V_15 = - V_64 ;
V_61 = V_62 [ 0 ] ;
if ( V_61 + 2 + V_31 >= V_59 ) {
F_51 ( L_1 ,
V_61 + 2 , V_59 - V_31 ) ;
goto V_63;
}
F_52 ( V_17 , V_17 -> V_5 - V_31 - V_61 - 2 ) ;
F_53 ( V_17 , V_58 ) ;
if ( V_26 -> V_43 . V_65 == V_66 )
F_54 ( V_17 ) ;
else
F_55 ( V_17 , - V_60 ) ;
V_15 = V_62 [ 1 ] ;
if ( V_15 == V_67 )
V_15 = - V_64 ;
V_63:
return V_15 ;
}
static void F_56 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_57 ( V_17 , F_45 ( V_17 , V_15 ) ) ;
}
static void F_58 ( struct V_16 * V_17 )
{
F_19 ( V_17 , 0 ) ;
F_53 ( V_17 , 4 ) ;
}
static void F_59 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
F_58 ( V_17 ) ;
F_56 ( V_14 , V_15 ) ;
}
static int F_60 ( struct V_25 * V_26 , struct V_16 * V_17 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 = V_26 -> V_18 ;
struct V_6 * V_12 ;
struct V_16 * V_28 ;
int V_33 = F_2 ( V_2 ) ;
int V_59 = V_17 -> V_5 - sizeof( * V_21 ) - V_33 ;
int V_3 ;
int V_35 ;
int V_10 ;
int V_68 = 0 ;
void * V_9 ;
T_1 * V_22 ;
T_2 * V_11 ;
struct V_7 * V_27 ;
if ( ! F_61 ( V_17 , sizeof( * V_21 ) + V_33 ) ) {
V_68 = - V_64 ;
goto V_63;
}
if ( V_59 <= 0 ) {
V_68 = - V_64 ;
goto V_63;
}
V_3 = F_29 ( V_17 , 0 , & V_28 ) ;
if ( V_3 < 0 ) {
V_68 = - V_64 ;
goto V_63;
}
V_68 = - V_46 ;
V_35 = sizeof( * V_21 ) ;
V_10 = 0 ;
if ( V_26 -> V_43 . V_44 & V_45 ) {
V_10 += sizeof( T_1 ) ;
V_35 += V_10 ;
}
V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! V_9 )
goto V_63;
F_17 ( V_17 ) -> V_9 = V_9 ;
V_22 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_27 = F_14 ( V_2 , V_12 ) ;
V_17 -> V_69 = V_70 ;
V_21 = (struct V_20 * ) V_17 -> V_18 ;
F_37 ( V_12 , 0 , F_56 , V_17 ) ;
if ( ( V_26 -> V_43 . V_44 & V_45 ) ) {
V_21 = ( void * ) F_33 ( V_17 , 4 ) ;
* V_22 = V_21 -> V_24 ;
V_21 -> V_24 = V_21 -> V_23 ;
V_21 -> V_23 = F_35 ( F_36 ( V_17 ) -> V_49 . V_71 . V_52 ) ;
F_37 ( V_12 , 0 , F_59 , V_17 ) ;
}
F_39 ( V_27 , V_3 ) ;
F_40 ( V_17 , V_27 , 0 , V_17 -> V_5 ) ;
F_41 ( V_12 , V_27 , V_27 , V_59 + V_33 , V_11 ) ;
F_42 ( V_12 , V_35 ) ;
V_68 = F_62 ( V_12 ) ;
if ( V_68 == - V_55 )
goto V_63;
if ( ( V_26 -> V_43 . V_44 & V_45 ) )
F_58 ( V_17 ) ;
V_68 = F_45 ( V_17 , V_68 ) ;
V_63:
return V_68 ;
}
static T_4 F_27 ( struct V_25 * V_26 , int V_72 )
{
struct V_1 * V_2 = V_26 -> V_18 ;
T_4 V_29 = F_5 ( F_28 ( V_2 ) , 4 ) ;
unsigned int V_73 ;
if ( V_26 -> V_43 . V_65 != V_66 )
V_73 = sizeof( struct V_74 ) ;
else
V_73 = 0 ;
return ( ( V_72 - V_26 -> V_43 . V_75 - F_24 ( V_2 ) -
V_73 ) & ~ ( V_29 - 1 ) ) + V_73 - 2 ;
}
static int F_63 ( struct V_16 * V_17 , struct V_76 * V_77 ,
T_2 type , T_2 V_78 , int V_19 , T_1 V_79 )
{
struct V_80 * V_80 = F_64 ( V_17 -> V_81 ) ;
const struct V_74 * V_82 = ( const struct V_74 * ) V_17 -> V_18 ;
struct V_20 * V_21 = (struct V_20 * ) ( V_17 -> V_18 + V_19 ) ;
struct V_25 * V_26 ;
if ( type != V_83 &&
type != V_84 )
return 0 ;
V_26 = F_65 ( V_80 , V_17 -> V_85 , ( const V_86 * ) & V_82 -> V_87 ,
V_21 -> V_24 , V_48 , V_88 ) ;
if ( ! V_26 )
return 0 ;
if ( type == V_84 )
F_66 ( V_17 , V_80 , V_17 -> V_81 -> V_89 , 0 ) ;
else
F_67 ( V_17 , V_80 , V_79 , 0 , 0 ) ;
F_68 ( V_26 ) ;
return 0 ;
}
static void F_69 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_18 ;
if ( ! V_2 )
return;
F_70 ( V_2 ) ;
}
static int F_71 ( struct V_25 * V_26 )
{
char V_90 [ V_91 ] ;
struct V_1 * V_2 ;
int V_15 ;
V_15 = - V_92 ;
if ( snprintf ( V_90 , V_91 , L_2 ,
V_26 -> V_93 , V_26 -> V_2 -> V_94 ) >= V_91 )
goto error;
V_2 = F_72 ( V_90 , 0 , 0 ) ;
V_15 = F_73 ( V_2 ) ;
if ( F_74 ( V_2 ) )
goto error;
V_26 -> V_18 = V_2 ;
V_15 = F_75 ( V_2 , V_26 -> V_2 -> V_95 ,
( V_26 -> V_2 -> V_96 + 7 ) / 8 ) ;
if ( V_15 )
goto error;
V_15 = F_76 ( V_2 , V_26 -> V_2 -> V_97 / 8 ) ;
if ( V_15 )
goto error;
error:
return V_15 ;
}
static int F_77 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
char * V_102 ;
char * V_103 ;
char V_104 [ V_91 ] ;
unsigned int V_105 ;
int V_15 ;
V_15 = - V_64 ;
if ( ! V_26 -> V_106 )
goto error;
V_15 = - V_92 ;
if ( ( V_26 -> V_43 . V_44 & V_45 ) ) {
if ( snprintf ( V_104 , V_91 ,
L_3 ,
V_26 -> V_93 ? : L_4 , V_26 -> V_93 ? L_5 : L_4 ,
V_26 -> V_107 ? V_26 -> V_107 -> V_94 : L_6 ,
V_26 -> V_106 -> V_94 ,
V_26 -> V_93 ? L_7 : L_4 ) >= V_91 )
goto error;
} else {
if ( snprintf ( V_104 , V_91 ,
L_8 ,
V_26 -> V_93 ? : L_4 , V_26 -> V_93 ? L_5 : L_4 ,
V_26 -> V_107 ? V_26 -> V_107 -> V_94 : L_6 ,
V_26 -> V_106 -> V_94 ,
V_26 -> V_93 ? L_7 : L_4 ) >= V_91 )
goto error;
}
V_2 = F_72 ( V_104 , 0 , 0 ) ;
V_15 = F_73 ( V_2 ) ;
if ( F_74 ( V_2 ) )
goto error;
V_26 -> V_18 = V_2 ;
V_105 = ( V_26 -> V_107 ? ( V_26 -> V_107 -> V_96 + 7 ) / 8 : 0 ) +
( V_26 -> V_106 -> V_96 + 7 ) / 8 + F_78 ( sizeof( * V_99 ) ) ;
V_15 = - V_46 ;
V_102 = F_8 ( V_105 , V_108 ) ;
if ( ! V_102 )
goto error;
V_103 = V_102 ;
V_101 = ( void * ) V_103 ;
V_101 -> V_109 = V_110 ;
V_101 -> V_111 = F_79 ( sizeof( * V_99 ) ) ;
V_99 = F_80 ( V_101 ) ;
V_103 += F_78 ( sizeof( * V_99 ) ) ;
if ( V_26 -> V_107 ) {
struct V_112 * V_113 ;
memcpy ( V_103 , V_26 -> V_107 -> V_95 , ( V_26 -> V_107 -> V_96 + 7 ) / 8 ) ;
V_103 += ( V_26 -> V_107 -> V_96 + 7 ) / 8 ;
V_113 = F_81 ( V_26 -> V_107 -> V_94 , 0 ) ;
F_82 ( ! V_113 ) ;
V_15 = - V_64 ;
if ( V_113 -> V_114 . V_115 . V_116 / 8 !=
F_24 ( V_2 ) ) {
F_83 ( L_9 ,
V_26 -> V_107 -> V_94 ,
F_24 ( V_2 ) ,
V_113 -> V_114 . V_115 . V_116 / 8 ) ;
goto V_117;
}
V_15 = F_76 (
V_2 , V_26 -> V_107 -> V_118 / 8 ) ;
if ( V_15 )
goto V_117;
}
V_99 -> V_119 = F_84 ( ( V_26 -> V_106 -> V_96 + 7 ) / 8 ) ;
memcpy ( V_103 , V_26 -> V_106 -> V_95 , ( V_26 -> V_106 -> V_96 + 7 ) / 8 ) ;
V_15 = F_75 ( V_2 , V_102 , V_105 ) ;
V_117:
F_16 ( V_102 ) ;
error:
return V_15 ;
}
static int F_85 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
T_4 V_120 ;
int V_15 ;
if ( V_26 -> V_121 )
return - V_64 ;
V_26 -> V_18 = NULL ;
if ( V_26 -> V_2 )
V_15 = F_71 ( V_26 ) ;
else
V_15 = F_77 ( V_26 ) ;
if ( V_15 )
goto error;
V_2 = V_26 -> V_18 ;
V_26 -> V_43 . V_75 = sizeof( struct V_20 ) +
F_2 ( V_2 ) ;
switch ( V_26 -> V_43 . V_65 ) {
case V_122 :
if ( V_26 -> V_123 . V_124 != V_88 )
V_26 -> V_43 . V_75 += V_125 +
( sizeof( struct V_74 ) - sizeof( struct V_126 ) ) ;
break;
case V_127 :
break;
case V_66 :
V_26 -> V_43 . V_75 += sizeof( struct V_74 ) ;
break;
default:
goto error;
}
V_120 = F_5 ( F_28 ( V_2 ) , 4 ) ;
V_26 -> V_43 . V_128 = V_120 + 1 + F_24 ( V_2 ) ;
error:
return V_15 ;
}
static int F_86 ( struct V_16 * V_17 , int V_15 )
{
return 0 ;
}
static int T_5 F_87 ( void )
{
if ( F_88 ( & V_129 , V_88 ) < 0 ) {
F_83 ( L_10 , V_130 ) ;
return - V_131 ;
}
if ( F_89 ( & V_132 , V_48 ) < 0 ) {
F_83 ( L_11 , V_130 ) ;
F_90 ( & V_129 , V_88 ) ;
return - V_131 ;
}
return 0 ;
}
static void T_6 F_91 ( void )
{
if ( F_92 ( & V_132 , V_48 ) < 0 )
F_83 ( L_12 , V_130 ) ;
if ( F_90 ( & V_129 , V_88 ) < 0 )
F_83 ( L_13 , V_130 ) ;
}
