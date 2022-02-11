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
static void F_15 ( struct V_13 * V_14 , void * V_9 )
{
T_1 * V_15 ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_10 = 0 ;
T_2 * V_11 ;
struct V_6 * V_12 ;
struct V_7 * V_17 ;
if ( V_14 -> V_18 . V_19 & V_20 )
V_10 += sizeof( T_1 ) ;
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
if ( V_12 -> V_21 != V_12 -> V_22 )
for ( V_17 = F_16 ( V_12 -> V_21 ) ; V_17 ; V_17 = F_16 ( V_17 ) )
F_17 ( F_18 ( V_17 ) ) ;
}
static void F_19 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
void * V_9 ;
struct V_28 * V_22 = F_20 ( V_27 ) ;
struct V_13 * V_14 = V_22 -> V_29 ;
V_9 = F_21 ( V_27 ) -> V_9 ;
F_15 ( V_14 , V_9 ) ;
F_22 ( V_9 ) ;
F_23 ( V_27 , V_25 ) ;
}
static void F_24 ( struct V_26 * V_27 , unsigned int V_30 )
{
struct V_31 * V_32 = ( void * ) ( V_27 -> V_16 + V_30 ) ;
void * V_9 = F_21 ( V_27 ) -> V_9 ;
T_1 * V_15 = F_9 ( V_9 ) ;
V_32 -> V_33 = V_32 -> V_34 ;
V_32 -> V_34 = * V_15 ;
}
static void F_25 ( struct V_26 * V_27 )
{
F_24 ( V_27 , F_26 ( V_27 ) - sizeof( T_1 ) ) ;
}
static struct V_31 * F_27 ( struct V_26 * V_27 ,
struct V_13 * V_14 ,
struct V_31 * V_32 ,
T_1 * V_15 )
{
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
struct V_35 * V_36 = V_35 ( V_27 ) ;
V_32 = ( void * ) ( F_28 ( V_27 ) - sizeof( T_1 ) ) ;
* V_15 = V_32 -> V_34 ;
if ( V_36 )
V_32 -> V_33 = F_29 ( V_36 -> V_37 . V_38 ) ;
else
V_32 -> V_33 = F_29 ( F_30 ( V_27 ) -> V_37 . V_39 . V_38 ) ;
}
V_32 -> V_34 = V_14 -> V_40 . V_34 ;
return V_32 ;
}
static void F_31 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_25 ( V_27 ) ;
F_19 ( V_24 , V_25 ) ;
}
static void F_32 ( T_2 * V_41 , int V_42 , int V_43 , T_3 V_44 )
{
if ( V_42 ) {
memset ( V_41 , 0 , V_42 ) ;
V_41 += V_42 ;
}
do {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_43 - 2 ; V_45 ++ )
V_41 [ V_45 ] = V_45 + 1 ;
} while ( 0 );
V_41 [ V_43 - 2 ] = V_43 - 2 ;
V_41 [ V_43 - 1 ] = V_44 ;
}
int F_33 ( struct V_13 * V_14 , struct V_26 * V_27 , struct V_46 * V_47 )
{
T_2 * V_41 ;
T_2 * V_48 ;
int V_3 ;
struct V_49 * V_49 ;
struct V_31 * V_32 ;
struct V_26 * V_50 ;
int V_51 = V_47 -> V_51 ;
V_32 = V_31 ( V_27 ) ;
if ( ! F_34 ( V_27 ) ) {
if ( V_51 <= F_35 ( V_27 ) ) {
V_3 = 1 ;
V_50 = V_27 ;
V_41 = F_36 ( V_50 ) ;
goto V_52;
} else if ( ( F_37 ( V_27 ) -> V_53 < V_54 )
&& ! F_38 ( V_27 ) ) {
int V_55 ;
struct V_56 * V_57 = V_27 -> V_57 ;
struct V_58 * V_59 = & V_14 -> V_60 ;
V_47 -> V_61 = false ;
V_55 = F_5 ( V_51 , V_62 ) ;
F_39 ( & V_14 -> V_63 ) ;
if ( F_40 ( ! F_41 ( V_55 , V_59 , V_8 ) ) ) {
F_42 ( & V_14 -> V_63 ) ;
goto V_64;
}
V_49 = V_59 -> V_49 ;
F_43 ( V_49 ) ;
V_48 = F_44 ( V_49 ) ;
V_41 = V_48 + V_59 -> V_30 ;
F_32 ( V_41 , V_47 -> V_42 , V_47 -> V_43 , V_47 -> V_44 ) ;
F_45 ( V_48 ) ;
F_42 ( & V_14 -> V_63 ) ;
V_3 = F_37 ( V_27 ) -> V_53 ;
F_46 ( V_27 , V_3 , V_49 , V_59 -> V_30 ,
V_51 ) ;
F_37 ( V_27 ) -> V_53 = ++ V_3 ;
V_59 -> V_30 = V_59 -> V_30 + V_55 ;
V_3 ++ ;
V_27 -> V_5 += V_51 ;
V_27 -> V_65 += V_51 ;
V_27 -> V_66 += V_51 ;
if ( V_57 )
F_47 ( V_51 , & V_57 -> V_67 ) ;
goto V_68;
}
}
V_64:
V_3 = F_48 ( V_27 , V_51 , & V_50 ) ;
if ( V_3 < 0 )
goto V_68;
V_41 = F_36 ( V_50 ) ;
V_52:
F_32 ( V_41 , V_47 -> V_42 , V_47 -> V_43 , V_47 -> V_44 ) ;
F_49 ( V_27 , V_50 , V_51 ) ;
V_68:
return V_3 ;
}
int F_50 ( struct V_13 * V_14 , struct V_26 * V_27 , struct V_46 * V_47 )
{
T_2 * V_11 ;
int V_69 ;
void * V_9 ;
int V_70 ;
int V_71 ;
int V_10 ;
T_1 * V_15 ;
struct V_49 * V_49 ;
struct V_31 * V_32 ;
struct V_6 * V_12 ;
struct V_1 * V_2 ;
struct V_7 * V_17 , * V_72 ;
int V_25 = - V_73 ;
V_71 = sizeof( struct V_31 ) ;
V_10 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_10 += sizeof( T_1 ) ;
V_71 += sizeof( T_1 ) ;
}
V_2 = V_14 -> V_16 ;
V_69 = F_51 ( V_2 ) ;
V_70 = F_2 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_47 -> V_3 + 2 , V_10 ) ;
if ( ! V_9 )
goto error;
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
if ( V_47 -> V_61 )
V_72 = V_17 ;
else
V_72 = & V_17 [ V_47 -> V_3 ] ;
V_32 = F_27 ( V_27 , V_14 , V_31 ( V_27 ) , V_15 ) ;
F_52 ( V_17 , V_47 -> V_3 ) ;
F_53 ( V_27 , V_17 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_71 + V_70 + V_47 -> V_74 + V_69 ) ;
if ( ! V_47 -> V_61 ) {
int V_55 ;
struct V_58 * V_59 = & V_14 -> V_60 ;
V_55 = F_5 ( V_27 -> V_65 , V_62 ) ;
F_39 ( & V_14 -> V_63 ) ;
if ( F_40 ( ! F_41 ( V_55 , V_59 , V_8 ) ) ) {
F_42 ( & V_14 -> V_63 ) ;
goto error;
}
F_37 ( V_27 ) -> V_53 = 1 ;
V_49 = V_59 -> V_49 ;
F_43 ( V_49 ) ;
F_46 ( V_27 , 0 , V_49 , V_59 -> V_30 , V_27 -> V_65 ) ;
V_59 -> V_30 = V_59 -> V_30 + V_55 ;
F_42 ( & V_14 -> V_63 ) ;
F_52 ( V_72 , F_37 ( V_27 ) -> V_53 + 1 ) ;
F_53 ( V_27 , V_72 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_71 + V_70 + V_47 -> V_74 + V_69 ) ;
}
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_54 ( V_12 , 0 , F_31 , V_27 ) ;
else
F_54 ( V_12 , 0 , F_19 , V_27 ) ;
F_55 ( V_12 , V_17 , V_72 , V_70 + V_47 -> V_74 , V_11 ) ;
F_56 ( V_12 , V_71 ) ;
memset ( V_11 , 0 , V_70 ) ;
memcpy ( V_11 + V_70 - F_57 ( V_70 , 8 ) , ( T_2 * ) & V_47 -> V_75 + 8 - F_57 ( V_70 , 8 ) ,
F_57 ( V_70 , 8 ) ) ;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_25 = F_58 ( V_12 ) ;
switch ( V_25 ) {
case - V_76 :
goto error;
case - V_77 :
V_25 = V_78 ;
break;
case 0 :
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_25 ( V_27 ) ;
}
if ( V_17 != V_72 )
F_15 ( V_14 , V_9 ) ;
F_22 ( V_9 ) ;
error:
return V_25 ;
}
static int F_59 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
int V_69 ;
int V_79 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_46 V_47 ;
V_47 . V_61 = true ;
V_47 . V_44 = * F_60 ( V_27 ) ;
* F_60 ( V_27 ) = V_80 ;
V_2 = V_14 -> V_16 ;
V_69 = F_51 ( V_2 ) ;
V_47 . V_42 = 0 ;
if ( V_14 -> V_81 ) {
struct V_82 * V_22 = (struct V_82 * ) F_20 ( V_27 ) ;
T_4 V_83 ;
V_83 = F_57 ( V_14 -> V_81 , F_61 ( V_14 , V_22 -> V_84 ) ) ;
if ( V_27 -> V_5 < V_83 )
V_47 . V_42 = V_83 - V_27 -> V_5 ;
}
V_79 = F_5 ( F_62 ( V_2 ) , 4 ) ;
V_47 . V_74 = F_5 ( V_27 -> V_5 + 2 + V_47 . V_42 , V_79 ) ;
V_47 . V_43 = V_47 . V_74 - V_27 -> V_5 - V_47 . V_42 ;
V_47 . V_51 = V_47 . V_42 + V_47 . V_43 + V_69 ;
V_47 . V_3 = F_33 ( V_14 , V_27 , & V_47 ) ;
if ( V_47 . V_3 < 0 )
return V_47 . V_3 ;
V_32 = V_31 ( V_27 ) ;
V_32 -> V_34 = V_14 -> V_40 . V_34 ;
V_32 -> V_33 = F_29 ( F_30 ( V_27 ) -> V_37 . V_39 . V_85 ) ;
V_47 . V_75 = F_63 ( F_30 ( V_27 ) -> V_37 . V_39 . V_85 +
( ( V_86 ) F_30 ( V_27 ) -> V_37 . V_39 . V_38 << 32 ) ) ;
F_64 ( V_27 , - F_65 ( V_27 ) ) ;
return F_50 ( V_14 , V_27 , & V_47 ) ;
}
int F_66 ( struct V_26 * V_27 , int V_25 )
{
struct V_13 * V_14 = F_67 ( V_27 ) ;
struct V_35 * V_36 = V_35 ( V_27 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_69 = F_51 ( V_2 ) ;
int V_87 = sizeof( struct V_31 ) + F_2 ( V_2 ) ;
int V_88 = V_27 -> V_5 - V_87 ;
int V_89 = F_68 ( V_27 ) ;
int V_90 ;
T_2 V_91 [ 2 ] ;
if ( ! V_36 || ( V_36 && ! ( V_36 -> V_19 & V_92 ) ) )
F_22 ( F_21 ( V_27 ) -> V_9 ) ;
if ( F_40 ( V_25 ) )
goto V_68;
if ( F_69 ( V_27 , V_27 -> V_5 - V_69 - 2 , V_91 , 2 ) )
F_70 () ;
V_25 = - V_93 ;
V_90 = V_91 [ 0 ] ;
if ( V_90 + 2 + V_69 >= V_88 ) {
F_71 ( L_1 ,
V_90 + 2 , V_88 - V_69 ) ;
goto V_68;
}
F_72 ( V_27 , V_27 -> V_5 - V_69 - V_90 - 2 ) ;
F_73 ( V_27 , V_87 ) ;
if ( V_14 -> V_18 . V_94 == V_95 )
F_74 ( V_27 ) ;
else
F_75 ( V_27 , - V_89 ) ;
V_25 = V_91 [ 1 ] ;
if ( V_25 == V_96 )
V_25 = - V_93 ;
V_68:
return V_25 ;
}
static void F_76 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_77 ( V_27 , F_66 ( V_27 , V_25 ) ) ;
}
static void F_78 ( struct V_26 * V_27 )
{
F_24 ( V_27 , 0 ) ;
F_73 ( V_27 , 4 ) ;
}
static void F_79 ( struct V_26 * V_27 , T_1 * V_15 )
{
struct V_13 * V_14 = F_67 ( V_27 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_27 -> V_16 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_32 = ( void * ) F_64 ( V_27 , 4 ) ;
* V_15 = V_32 -> V_34 ;
V_32 -> V_34 = V_32 -> V_33 ;
V_32 -> V_33 = F_30 ( V_27 ) -> V_37 . V_97 . V_38 ;
}
}
static void F_80 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_78 ( V_27 ) ;
F_76 ( V_24 , V_25 ) ;
}
static int F_81 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_6 * V_12 ;
struct V_26 * V_50 ;
int V_70 = F_2 ( V_2 ) ;
int V_88 = V_27 -> V_5 - sizeof( * V_32 ) - V_70 ;
int V_3 ;
int V_71 ;
int V_10 ;
int V_98 = 0 ;
void * V_9 ;
T_1 * V_15 ;
T_2 * V_11 ;
struct V_7 * V_17 ;
if ( ! F_82 ( V_27 , sizeof( * V_32 ) + V_70 ) ) {
V_98 = - V_93 ;
goto V_68;
}
if ( V_88 <= 0 ) {
V_98 = - V_93 ;
goto V_68;
}
V_71 = sizeof( * V_32 ) ;
V_10 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_10 += sizeof( T_1 ) ;
V_71 += V_10 ;
}
if ( ! F_34 ( V_27 ) ) {
if ( ! F_83 ( V_27 ) ) {
V_3 = 1 ;
goto V_52;
} else if ( ! F_38 ( V_27 ) ) {
V_3 = F_37 ( V_27 ) -> V_53 ;
V_3 ++ ;
goto V_52;
}
}
V_3 = F_48 ( V_27 , 0 , & V_50 ) ;
if ( V_3 < 0 ) {
V_98 = - V_93 ;
goto V_68;
}
V_52:
V_98 = - V_73 ;
V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! V_9 )
goto V_68;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
F_79 ( V_27 , V_15 ) ;
F_52 ( V_17 , V_3 ) ;
F_53 ( V_27 , V_17 , 0 , V_27 -> V_5 ) ;
V_27 -> V_99 = V_100 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_54 ( V_12 , 0 , F_80 , V_27 ) ;
else
F_54 ( V_12 , 0 , F_76 , V_27 ) ;
F_55 ( V_12 , V_17 , V_17 , V_88 + V_70 , V_11 ) ;
F_56 ( V_12 , V_71 ) ;
V_98 = F_84 ( V_12 ) ;
if ( V_98 == - V_76 )
goto V_68;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_78 ( V_27 ) ;
V_98 = F_66 ( V_27 , V_98 ) ;
V_68:
return V_98 ;
}
static T_4 F_61 ( struct V_13 * V_14 , int V_101 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
T_4 V_79 = F_5 ( F_62 ( V_2 ) , 4 ) ;
unsigned int V_102 ;
if ( V_14 -> V_18 . V_94 != V_95 )
V_102 = sizeof( struct V_103 ) ;
else
V_102 = 0 ;
return ( ( V_101 - V_14 -> V_18 . V_104 - F_51 ( V_2 ) -
V_102 ) & ~ ( V_79 - 1 ) ) + V_102 - 2 ;
}
static int F_85 ( struct V_26 * V_27 , struct V_105 * V_106 ,
T_2 type , T_2 V_107 , int V_30 , T_1 V_108 )
{
struct V_109 * V_109 = F_86 ( V_27 -> V_110 ) ;
const struct V_103 * V_111 = ( const struct V_103 * ) V_27 -> V_16 ;
struct V_31 * V_32 = (struct V_31 * ) ( V_27 -> V_16 + V_30 ) ;
struct V_13 * V_14 ;
if ( type != V_112 &&
type != V_113 )
return 0 ;
V_14 = F_87 ( V_109 , V_27 -> V_114 , ( const V_115 * ) & V_111 -> V_116 ,
V_32 -> V_34 , V_80 , V_117 ) ;
if ( ! V_14 )
return 0 ;
if ( type == V_113 )
F_88 ( V_27 , V_109 , V_27 -> V_110 -> V_118 , 0 ,
F_89 ( V_109 , NULL ) ) ;
else
F_90 ( V_27 , V_109 , V_108 , 0 , 0 , F_89 ( V_109 , NULL ) ) ;
F_91 ( V_14 ) ;
return 0 ;
}
static void F_92 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
if ( ! V_2 )
return;
F_93 ( V_2 ) ;
}
static int F_94 ( struct V_13 * V_14 )
{
char V_119 [ V_120 ] ;
struct V_1 * V_2 ;
int V_25 ;
T_4 V_121 = 0 ;
V_25 = - V_122 ;
if ( snprintf ( V_119 , V_120 , L_2 ,
V_14 -> V_123 , V_14 -> V_2 -> V_124 ) >= V_120 )
goto error;
if ( V_14 -> V_125 . V_126 )
V_121 |= V_127 ;
V_2 = F_95 ( V_119 , 0 , V_121 ) ;
V_25 = F_96 ( V_2 ) ;
if ( F_97 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_25 = F_98 ( V_2 , V_14 -> V_2 -> V_128 ,
( V_14 -> V_2 -> V_129 + 7 ) / 8 ) ;
if ( V_25 )
goto error;
V_25 = F_99 ( V_2 , V_14 -> V_2 -> V_130 / 8 ) ;
if ( V_25 )
goto error;
error:
return V_25 ;
}
static int F_100 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
char * V_135 ;
char * V_136 ;
char V_137 [ V_120 ] ;
unsigned int V_138 ;
int V_25 ;
T_4 V_121 = 0 ;
V_25 = - V_93 ;
if ( ! V_14 -> V_139 )
goto error;
V_25 = - V_122 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
if ( snprintf ( V_137 , V_120 ,
L_3 ,
V_14 -> V_123 ? : L_4 , V_14 -> V_123 ? L_5 : L_4 ,
V_14 -> V_140 ? V_14 -> V_140 -> V_124 : L_6 ,
V_14 -> V_139 -> V_124 ,
V_14 -> V_123 ? L_7 : L_4 ) >= V_120 )
goto error;
} else {
if ( snprintf ( V_137 , V_120 ,
L_8 ,
V_14 -> V_123 ? : L_4 , V_14 -> V_123 ? L_5 : L_4 ,
V_14 -> V_140 ? V_14 -> V_140 -> V_124 : L_6 ,
V_14 -> V_139 -> V_124 ,
V_14 -> V_123 ? L_7 : L_4 ) >= V_120 )
goto error;
}
if ( V_14 -> V_125 . V_126 )
V_121 |= V_127 ;
V_2 = F_95 ( V_137 , 0 , V_121 ) ;
V_25 = F_96 ( V_2 ) ;
if ( F_97 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_138 = ( V_14 -> V_140 ? ( V_14 -> V_140 -> V_129 + 7 ) / 8 : 0 ) +
( V_14 -> V_139 -> V_129 + 7 ) / 8 + F_101 ( sizeof( * V_132 ) ) ;
V_25 = - V_73 ;
V_135 = F_8 ( V_138 , V_141 ) ;
if ( ! V_135 )
goto error;
V_136 = V_135 ;
V_134 = ( void * ) V_136 ;
V_134 -> V_142 = V_143 ;
V_134 -> V_144 = F_102 ( sizeof( * V_132 ) ) ;
V_132 = F_103 ( V_134 ) ;
V_136 += F_101 ( sizeof( * V_132 ) ) ;
if ( V_14 -> V_140 ) {
struct V_145 * V_146 ;
memcpy ( V_136 , V_14 -> V_140 -> V_128 , ( V_14 -> V_140 -> V_129 + 7 ) / 8 ) ;
V_136 += ( V_14 -> V_140 -> V_129 + 7 ) / 8 ;
V_146 = F_104 ( V_14 -> V_140 -> V_124 , 0 ) ;
F_105 ( ! V_146 ) ;
V_25 = - V_93 ;
if ( V_146 -> V_147 . V_148 . V_149 / 8 !=
F_51 ( V_2 ) ) {
F_106 ( L_9 ,
V_14 -> V_140 -> V_124 ,
F_51 ( V_2 ) ,
V_146 -> V_147 . V_148 . V_149 / 8 ) ;
goto V_150;
}
V_25 = F_99 (
V_2 , V_14 -> V_140 -> V_151 / 8 ) ;
if ( V_25 )
goto V_150;
}
V_132 -> V_152 = F_107 ( ( V_14 -> V_139 -> V_129 + 7 ) / 8 ) ;
memcpy ( V_136 , V_14 -> V_139 -> V_128 , ( V_14 -> V_139 -> V_129 + 7 ) / 8 ) ;
V_25 = F_98 ( V_2 , V_135 , V_138 ) ;
V_150:
F_22 ( V_135 ) ;
error:
return V_25 ;
}
static int F_108 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_4 V_153 ;
int V_25 ;
if ( V_14 -> V_154 )
return - V_93 ;
V_14 -> V_16 = NULL ;
if ( V_14 -> V_2 )
V_25 = F_94 ( V_14 ) ;
else
V_25 = F_100 ( V_14 ) ;
if ( V_25 )
goto error;
V_2 = V_14 -> V_16 ;
V_14 -> V_18 . V_104 = sizeof( struct V_31 ) +
F_2 ( V_2 ) ;
switch ( V_14 -> V_18 . V_94 ) {
case V_155 :
if ( V_14 -> V_156 . V_157 != V_117 )
V_14 -> V_18 . V_104 += V_158 +
( sizeof( struct V_103 ) - sizeof( struct V_159 ) ) ;
break;
case V_160 :
break;
case V_95 :
V_14 -> V_18 . V_104 += sizeof( struct V_103 ) ;
break;
default:
goto error;
}
V_153 = F_5 ( F_62 ( V_2 ) , 4 ) ;
V_14 -> V_18 . V_161 = V_153 + 1 + F_51 ( V_2 ) ;
error:
return V_25 ;
}
static int F_109 ( struct V_26 * V_27 , int V_25 )
{
return 0 ;
}
static int T_5 F_110 ( void )
{
if ( F_111 ( & V_162 , V_117 ) < 0 ) {
F_106 ( L_10 , V_163 ) ;
return - V_164 ;
}
if ( F_112 ( & V_165 , V_80 ) < 0 ) {
F_106 ( L_11 , V_163 ) ;
F_113 ( & V_162 , V_117 ) ;
return - V_164 ;
}
return 0 ;
}
static void T_6 F_114 ( void )
{
if ( F_115 ( & V_165 , V_80 ) < 0 )
F_106 ( L_12 , V_163 ) ;
if ( F_113 ( & V_162 , V_117 ) < 0 )
F_106 ( L_13 , V_163 ) ;
}
