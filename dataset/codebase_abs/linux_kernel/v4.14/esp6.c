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
struct V_1 * V_2 = V_14 -> V_15 ;
int V_10 = 0 ;
T_2 * V_11 ;
struct V_6 * V_12 ;
struct V_7 * V_16 ;
if ( V_14 -> V_17 . V_18 & V_19 )
V_10 += sizeof( T_1 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
if ( V_12 -> V_20 != V_12 -> V_21 )
for ( V_16 = F_16 ( V_12 -> V_20 ) ; V_16 ; V_16 = F_16 ( V_16 ) )
F_17 ( F_18 ( V_16 ) ) ;
}
static void F_19 ( struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = V_23 -> V_15 ;
void * V_9 ;
struct V_27 * V_21 = F_20 ( V_26 ) ;
struct V_13 * V_14 = V_21 -> V_28 ;
V_9 = F_21 ( V_26 ) -> V_9 ;
F_15 ( V_14 , V_9 ) ;
F_22 ( V_9 ) ;
F_23 ( V_26 , V_24 ) ;
}
static void F_24 ( struct V_25 * V_26 , unsigned int V_29 )
{
struct V_30 * V_31 = ( void * ) ( V_26 -> V_15 + V_29 ) ;
void * V_9 = F_21 ( V_26 ) -> V_9 ;
T_1 * V_32 = F_9 ( V_9 ) ;
V_31 -> V_33 = V_31 -> V_34 ;
V_31 -> V_34 = * V_32 ;
}
static void F_25 ( struct V_25 * V_26 )
{
F_24 ( V_26 , F_26 ( V_26 ) - sizeof( T_1 ) ) ;
}
static struct V_30 * F_27 ( struct V_25 * V_26 ,
struct V_13 * V_14 ,
struct V_30 * V_31 ,
T_1 * V_32 )
{
if ( ( V_14 -> V_17 . V_18 & V_19 ) ) {
struct V_35 * V_36 = V_35 ( V_26 ) ;
V_31 = ( void * ) ( F_28 ( V_26 ) - sizeof( T_1 ) ) ;
* V_32 = V_31 -> V_34 ;
if ( V_36 )
V_31 -> V_33 = F_29 ( V_36 -> V_37 . V_38 ) ;
else
V_31 -> V_33 = F_29 ( F_30 ( V_26 ) -> V_37 . V_39 . V_38 ) ;
}
V_31 -> V_34 = V_14 -> V_40 . V_34 ;
return V_31 ;
}
static void F_31 ( struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = V_23 -> V_15 ;
F_25 ( V_26 ) ;
F_19 ( V_23 , V_24 ) ;
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
int F_33 ( struct V_13 * V_14 , struct V_25 * V_26 , struct V_46 * V_47 )
{
T_2 * V_41 ;
T_2 * V_48 ;
int V_3 ;
struct V_49 * V_49 ;
struct V_25 * V_50 ;
int V_51 = V_47 -> V_51 ;
if ( ! F_34 ( V_26 ) ) {
if ( V_51 <= F_35 ( V_26 ) ) {
V_3 = 1 ;
V_50 = V_26 ;
V_41 = F_36 ( V_50 ) ;
goto V_52;
} else if ( ( F_37 ( V_26 ) -> V_53 < V_54 )
&& ! F_38 ( V_26 ) ) {
int V_55 ;
struct V_56 * V_57 = V_26 -> V_57 ;
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
V_41 = V_48 + V_59 -> V_29 ;
F_32 ( V_41 , V_47 -> V_42 , V_47 -> V_43 , V_47 -> V_44 ) ;
F_45 ( V_48 ) ;
V_3 = F_37 ( V_26 ) -> V_53 ;
F_46 ( V_26 , V_3 , V_49 , V_59 -> V_29 ,
V_51 ) ;
F_37 ( V_26 ) -> V_53 = ++ V_3 ;
V_59 -> V_29 = V_59 -> V_29 + V_55 ;
F_42 ( & V_14 -> V_63 ) ;
V_3 ++ ;
V_26 -> V_5 += V_51 ;
V_26 -> V_65 += V_51 ;
V_26 -> V_66 += V_51 ;
if ( V_57 )
F_47 ( V_51 , & V_57 -> V_67 ) ;
goto V_68;
}
}
V_64:
V_3 = F_48 ( V_26 , V_51 , & V_50 ) ;
if ( V_3 < 0 )
goto V_68;
V_41 = F_36 ( V_50 ) ;
V_52:
F_32 ( V_41 , V_47 -> V_42 , V_47 -> V_43 , V_47 -> V_44 ) ;
F_49 ( V_26 , V_50 , V_51 ) ;
V_68:
return V_3 ;
}
int F_50 ( struct V_13 * V_14 , struct V_25 * V_26 , struct V_46 * V_47 )
{
T_2 * V_11 ;
int V_69 ;
void * V_9 ;
int V_70 ;
int V_71 ;
int V_10 ;
T_1 * V_32 ;
struct V_49 * V_49 ;
struct V_30 * V_31 ;
struct V_6 * V_12 ;
struct V_1 * V_2 ;
struct V_7 * V_16 , * V_72 ;
int V_24 = - V_73 ;
V_71 = sizeof( struct V_30 ) ;
V_10 = 0 ;
if ( V_14 -> V_17 . V_18 & V_19 ) {
V_10 += sizeof( T_1 ) ;
V_71 += sizeof( T_1 ) ;
}
V_2 = V_14 -> V_15 ;
V_69 = F_51 ( V_2 ) ;
V_70 = F_2 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_47 -> V_3 + 2 , V_10 ) ;
if ( ! V_9 )
goto error;
V_32 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_16 = F_14 ( V_2 , V_12 ) ;
if ( V_47 -> V_61 )
V_72 = V_16 ;
else
V_72 = & V_16 [ V_47 -> V_3 ] ;
V_31 = F_27 ( V_26 , V_14 , V_30 ( V_26 ) , V_32 ) ;
F_52 ( V_16 , V_47 -> V_3 ) ;
V_24 = F_53 ( V_26 , V_16 ,
( unsigned char * ) V_31 - V_26 -> V_15 ,
V_71 + V_70 + V_47 -> V_74 + V_69 ) ;
if ( F_40 ( V_24 < 0 ) )
goto V_75;
if ( ! V_47 -> V_61 ) {
int V_55 ;
struct V_58 * V_59 = & V_14 -> V_60 ;
V_55 = F_5 ( V_26 -> V_65 , V_62 ) ;
F_39 ( & V_14 -> V_63 ) ;
if ( F_40 ( ! F_41 ( V_55 , V_59 , V_8 ) ) ) {
F_42 ( & V_14 -> V_63 ) ;
goto V_75;
}
F_37 ( V_26 ) -> V_53 = 1 ;
V_49 = V_59 -> V_49 ;
F_43 ( V_49 ) ;
F_46 ( V_26 , 0 , V_49 , V_59 -> V_29 , V_26 -> V_65 ) ;
V_59 -> V_29 = V_59 -> V_29 + V_55 ;
F_42 ( & V_14 -> V_63 ) ;
F_52 ( V_72 , F_37 ( V_26 ) -> V_53 + 1 ) ;
V_24 = F_53 ( V_26 , V_72 ,
( unsigned char * ) V_31 - V_26 -> V_15 ,
V_71 + V_70 + V_47 -> V_74 + V_69 ) ;
if ( F_40 ( V_24 < 0 ) )
goto V_75;
}
if ( ( V_14 -> V_17 . V_18 & V_19 ) )
F_54 ( V_12 , 0 , F_31 , V_26 ) ;
else
F_54 ( V_12 , 0 , F_19 , V_26 ) ;
F_55 ( V_12 , V_16 , V_72 , V_70 + V_47 -> V_74 , V_11 ) ;
F_56 ( V_12 , V_71 ) ;
memset ( V_11 , 0 , V_70 ) ;
memcpy ( V_11 + V_70 - F_57 ( V_70 , 8 ) , ( T_2 * ) & V_47 -> V_76 + 8 - F_57 ( V_70 , 8 ) ,
F_57 ( V_70 , 8 ) ) ;
F_21 ( V_26 ) -> V_9 = V_9 ;
V_24 = F_58 ( V_12 ) ;
switch ( V_24 ) {
case - V_77 :
goto error;
case - V_78 :
V_24 = V_79 ;
break;
case 0 :
if ( ( V_14 -> V_17 . V_18 & V_19 ) )
F_25 ( V_26 ) ;
}
if ( V_16 != V_72 )
F_15 ( V_14 , V_9 ) ;
V_75:
F_22 ( V_9 ) ;
error:
return V_24 ;
}
static int F_59 ( struct V_13 * V_14 , struct V_25 * V_26 )
{
int V_69 ;
int V_80 ;
struct V_30 * V_31 ;
struct V_1 * V_2 ;
struct V_46 V_47 ;
V_47 . V_61 = true ;
V_47 . V_44 = * F_60 ( V_26 ) ;
* F_60 ( V_26 ) = V_81 ;
V_2 = V_14 -> V_15 ;
V_69 = F_51 ( V_2 ) ;
V_47 . V_42 = 0 ;
if ( V_14 -> V_82 ) {
struct V_83 * V_21 = (struct V_83 * ) F_20 ( V_26 ) ;
T_4 V_84 ;
V_84 = F_57 ( V_14 -> V_82 , F_61 ( V_14 , V_21 -> V_85 ) ) ;
if ( V_26 -> V_5 < V_84 )
V_47 . V_42 = V_84 - V_26 -> V_5 ;
}
V_80 = F_5 ( F_62 ( V_2 ) , 4 ) ;
V_47 . V_74 = F_5 ( V_26 -> V_5 + 2 + V_47 . V_42 , V_80 ) ;
V_47 . V_43 = V_47 . V_74 - V_26 -> V_5 - V_47 . V_42 ;
V_47 . V_51 = V_47 . V_42 + V_47 . V_43 + V_69 ;
V_47 . V_3 = F_33 ( V_14 , V_26 , & V_47 ) ;
if ( V_47 . V_3 < 0 )
return V_47 . V_3 ;
V_31 = V_30 ( V_26 ) ;
V_31 -> V_34 = V_14 -> V_40 . V_34 ;
V_31 -> V_33 = F_29 ( F_30 ( V_26 ) -> V_37 . V_39 . V_86 ) ;
V_47 . V_76 = F_63 ( F_30 ( V_26 ) -> V_37 . V_39 . V_86 +
( ( V_87 ) F_30 ( V_26 ) -> V_37 . V_39 . V_38 << 32 ) ) ;
F_64 ( V_26 , - F_65 ( V_26 ) ) ;
return F_50 ( V_14 , V_26 , & V_47 ) ;
}
static inline int F_66 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_67 ( V_26 ) ;
struct V_35 * V_36 = V_35 ( V_26 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
int V_69 , V_88 , V_89 ;
int V_90 , V_91 ;
T_5 V_92 ;
T_2 V_93 [ 2 ] ;
int V_94 ;
V_69 = F_51 ( V_2 ) ;
V_88 = sizeof( struct V_30 ) + F_2 ( V_2 ) ;
V_89 = V_26 -> V_5 - V_88 ;
if ( V_36 && ( V_36 -> V_18 & V_95 ) ) {
V_94 = V_36 -> V_44 ;
goto V_68;
}
if ( F_68 ( V_26 , V_26 -> V_5 - V_69 - 2 , V_93 , 2 ) )
F_69 () ;
V_94 = - V_96 ;
V_90 = V_93 [ 0 ] ;
if ( V_90 + 2 + V_69 >= V_89 ) {
F_70 ( L_1 ,
V_90 + 2 , V_89 - V_69 ) ;
goto V_68;
}
V_91 = V_69 + V_90 + 2 ;
if ( V_26 -> V_97 == V_98 ) {
V_92 = F_71 ( V_26 , V_26 -> V_5 - V_91 , V_91 , 0 ) ;
V_26 -> V_99 = F_72 ( V_26 -> V_99 , V_92 ,
V_26 -> V_5 - V_91 ) ;
}
F_73 ( V_26 , V_26 -> V_5 - V_91 ) ;
V_94 = V_93 [ 1 ] ;
V_68:
return V_94 ;
}
int F_74 ( struct V_25 * V_26 , int V_24 )
{
struct V_13 * V_14 = F_67 ( V_26 ) ;
struct V_35 * V_36 = V_35 ( V_26 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
int V_88 = sizeof( struct V_30 ) + F_2 ( V_2 ) ;
int V_100 = F_75 ( V_26 ) ;
if ( ! V_36 || ( V_36 && ! ( V_36 -> V_18 & V_101 ) ) )
F_22 ( F_21 ( V_26 ) -> V_9 ) ;
if ( F_40 ( V_24 ) )
goto V_68;
V_24 = F_66 ( V_26 ) ;
if ( F_40 ( V_24 < 0 ) )
goto V_68;
F_76 ( V_26 , F_77 ( V_26 ) ,
F_75 ( V_26 ) ) ;
F_78 ( V_26 , V_88 ) ;
if ( V_14 -> V_17 . V_102 == V_103 )
F_79 ( V_26 ) ;
else
F_80 ( V_26 , - V_100 ) ;
if ( V_24 == V_104 )
V_24 = - V_96 ;
V_68:
return V_24 ;
}
static void F_81 ( struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = V_23 -> V_15 ;
F_82 ( V_26 , F_74 ( V_26 , V_24 ) ) ;
}
static void F_83 ( struct V_25 * V_26 )
{
F_24 ( V_26 , 0 ) ;
F_84 ( V_26 , 4 ) ;
}
static void F_85 ( struct V_25 * V_26 , T_1 * V_32 )
{
struct V_13 * V_14 = F_67 ( V_26 ) ;
struct V_30 * V_31 = (struct V_30 * ) V_26 -> V_15 ;
if ( ( V_14 -> V_17 . V_18 & V_19 ) ) {
V_31 = F_64 ( V_26 , 4 ) ;
* V_32 = V_31 -> V_34 ;
V_31 -> V_34 = V_31 -> V_33 ;
V_31 -> V_33 = F_30 ( V_26 ) -> V_37 . V_105 . V_38 ;
}
}
static void F_86 ( struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 = V_23 -> V_15 ;
F_83 ( V_26 ) ;
F_81 ( V_23 , V_24 ) ;
}
static int F_87 ( struct V_13 * V_14 , struct V_25 * V_26 )
{
struct V_30 * V_31 ;
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_6 * V_12 ;
struct V_25 * V_50 ;
int V_70 = F_2 ( V_2 ) ;
int V_89 = V_26 -> V_5 - sizeof( * V_31 ) - V_70 ;
int V_3 ;
int V_71 ;
int V_10 ;
int V_94 = 0 ;
void * V_9 ;
T_1 * V_32 ;
T_2 * V_11 ;
struct V_7 * V_16 ;
if ( ! F_88 ( V_26 , sizeof( * V_31 ) + V_70 ) ) {
V_94 = - V_96 ;
goto V_68;
}
if ( V_89 <= 0 ) {
V_94 = - V_96 ;
goto V_68;
}
V_71 = sizeof( * V_31 ) ;
V_10 = 0 ;
if ( V_14 -> V_17 . V_18 & V_19 ) {
V_10 += sizeof( T_1 ) ;
V_71 += V_10 ;
}
if ( ! F_34 ( V_26 ) ) {
if ( ! F_89 ( V_26 ) ) {
V_3 = 1 ;
goto V_52;
} else if ( ! F_38 ( V_26 ) ) {
V_3 = F_37 ( V_26 ) -> V_53 ;
V_3 ++ ;
goto V_52;
}
}
V_3 = F_48 ( V_26 , 0 , & V_50 ) ;
if ( V_3 < 0 ) {
V_94 = - V_96 ;
goto V_68;
}
V_52:
V_94 = - V_73 ;
V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! V_9 )
goto V_68;
F_21 ( V_26 ) -> V_9 = V_9 ;
V_32 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_16 = F_14 ( V_2 , V_12 ) ;
F_85 ( V_26 , V_32 ) ;
F_52 ( V_16 , V_3 ) ;
V_94 = F_53 ( V_26 , V_16 , 0 , V_26 -> V_5 ) ;
if ( F_40 ( V_94 < 0 ) )
goto V_68;
V_26 -> V_97 = V_106 ;
if ( ( V_14 -> V_17 . V_18 & V_19 ) )
F_54 ( V_12 , 0 , F_86 , V_26 ) ;
else
F_54 ( V_12 , 0 , F_81 , V_26 ) ;
F_55 ( V_12 , V_16 , V_16 , V_89 + V_70 , V_11 ) ;
F_56 ( V_12 , V_71 ) ;
V_94 = F_90 ( V_12 ) ;
if ( V_94 == - V_77 )
goto V_68;
if ( ( V_14 -> V_17 . V_18 & V_19 ) )
F_83 ( V_26 ) ;
V_94 = F_74 ( V_26 , V_94 ) ;
V_68:
return V_94 ;
}
static T_4 F_61 ( struct V_13 * V_14 , int V_107 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_4 V_80 = F_5 ( F_62 ( V_2 ) , 4 ) ;
unsigned int V_108 ;
if ( V_14 -> V_17 . V_102 != V_103 )
V_108 = sizeof( struct V_109 ) ;
else
V_108 = 0 ;
return ( ( V_107 - V_14 -> V_17 . V_110 - F_51 ( V_2 ) -
V_108 ) & ~ ( V_80 - 1 ) ) + V_108 - 2 ;
}
static int F_91 ( struct V_25 * V_26 , struct V_111 * V_112 ,
T_2 type , T_2 V_113 , int V_29 , T_1 V_114 )
{
struct V_115 * V_115 = F_92 ( V_26 -> V_116 ) ;
const struct V_109 * V_117 = ( const struct V_109 * ) V_26 -> V_15 ;
struct V_30 * V_31 = (struct V_30 * ) ( V_26 -> V_15 + V_29 ) ;
struct V_13 * V_14 ;
if ( type != V_118 &&
type != V_119 )
return 0 ;
V_14 = F_93 ( V_115 , V_26 -> V_120 , ( const V_121 * ) & V_117 -> V_122 ,
V_31 -> V_34 , V_81 , V_123 ) ;
if ( ! V_14 )
return 0 ;
if ( type == V_119 )
F_94 ( V_26 , V_115 , V_26 -> V_116 -> V_124 , 0 ,
F_95 ( V_115 , NULL ) ) ;
else
F_96 ( V_26 , V_115 , V_114 , 0 , 0 , F_95 ( V_115 , NULL ) ) ;
F_97 ( V_14 ) ;
return 0 ;
}
static void F_98 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
if ( ! V_2 )
return;
F_99 ( V_2 ) ;
}
static int F_100 ( struct V_13 * V_14 )
{
char V_125 [ V_126 ] ;
struct V_1 * V_2 ;
int V_24 ;
T_4 V_127 = 0 ;
V_24 = - V_128 ;
if ( snprintf ( V_125 , V_126 , L_2 ,
V_14 -> V_129 , V_14 -> V_2 -> V_130 ) >= V_126 )
goto error;
if ( V_14 -> V_131 . V_132 )
V_127 |= V_133 ;
V_2 = F_101 ( V_125 , 0 , V_127 ) ;
V_24 = F_102 ( V_2 ) ;
if ( F_103 ( V_2 ) )
goto error;
V_14 -> V_15 = V_2 ;
V_24 = F_104 ( V_2 , V_14 -> V_2 -> V_134 ,
( V_14 -> V_2 -> V_135 + 7 ) / 8 ) ;
if ( V_24 )
goto error;
V_24 = F_105 ( V_2 , V_14 -> V_2 -> V_136 / 8 ) ;
if ( V_24 )
goto error;
error:
return V_24 ;
}
static int F_106 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
char * V_141 ;
char * V_142 ;
char V_143 [ V_126 ] ;
unsigned int V_144 ;
int V_24 ;
T_4 V_127 = 0 ;
V_24 = - V_96 ;
if ( ! V_14 -> V_145 )
goto error;
V_24 = - V_128 ;
if ( ( V_14 -> V_17 . V_18 & V_19 ) ) {
if ( snprintf ( V_143 , V_126 ,
L_3 ,
V_14 -> V_129 ? : L_4 , V_14 -> V_129 ? L_5 : L_4 ,
V_14 -> V_146 ? V_14 -> V_146 -> V_130 : L_6 ,
V_14 -> V_145 -> V_130 ,
V_14 -> V_129 ? L_7 : L_4 ) >= V_126 )
goto error;
} else {
if ( snprintf ( V_143 , V_126 ,
L_8 ,
V_14 -> V_129 ? : L_4 , V_14 -> V_129 ? L_5 : L_4 ,
V_14 -> V_146 ? V_14 -> V_146 -> V_130 : L_6 ,
V_14 -> V_145 -> V_130 ,
V_14 -> V_129 ? L_7 : L_4 ) >= V_126 )
goto error;
}
if ( V_14 -> V_131 . V_132 )
V_127 |= V_133 ;
V_2 = F_101 ( V_143 , 0 , V_127 ) ;
V_24 = F_102 ( V_2 ) ;
if ( F_103 ( V_2 ) )
goto error;
V_14 -> V_15 = V_2 ;
V_144 = ( V_14 -> V_146 ? ( V_14 -> V_146 -> V_135 + 7 ) / 8 : 0 ) +
( V_14 -> V_145 -> V_135 + 7 ) / 8 + F_107 ( sizeof( * V_138 ) ) ;
V_24 = - V_73 ;
V_141 = F_8 ( V_144 , V_147 ) ;
if ( ! V_141 )
goto error;
V_142 = V_141 ;
V_140 = ( void * ) V_142 ;
V_140 -> V_148 = V_149 ;
V_140 -> V_150 = F_108 ( sizeof( * V_138 ) ) ;
V_138 = F_109 ( V_140 ) ;
V_142 += F_107 ( sizeof( * V_138 ) ) ;
if ( V_14 -> V_146 ) {
struct V_151 * V_152 ;
memcpy ( V_142 , V_14 -> V_146 -> V_134 , ( V_14 -> V_146 -> V_135 + 7 ) / 8 ) ;
V_142 += ( V_14 -> V_146 -> V_135 + 7 ) / 8 ;
V_152 = F_110 ( V_14 -> V_146 -> V_130 , 0 ) ;
F_111 ( ! V_152 ) ;
V_24 = - V_96 ;
if ( V_152 -> V_153 . V_154 . V_155 / 8 !=
F_51 ( V_2 ) ) {
F_112 ( L_9 ,
V_14 -> V_146 -> V_130 ,
F_51 ( V_2 ) ,
V_152 -> V_153 . V_154 . V_155 / 8 ) ;
goto V_156;
}
V_24 = F_105 (
V_2 , V_14 -> V_146 -> V_157 / 8 ) ;
if ( V_24 )
goto V_156;
}
V_138 -> V_158 = F_113 ( ( V_14 -> V_145 -> V_135 + 7 ) / 8 ) ;
memcpy ( V_142 , V_14 -> V_145 -> V_134 , ( V_14 -> V_145 -> V_135 + 7 ) / 8 ) ;
V_24 = F_104 ( V_2 , V_141 , V_144 ) ;
V_156:
F_22 ( V_141 ) ;
error:
return V_24 ;
}
static int F_114 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_4 V_159 ;
int V_24 ;
if ( V_14 -> V_160 )
return - V_96 ;
V_14 -> V_15 = NULL ;
if ( V_14 -> V_2 )
V_24 = F_100 ( V_14 ) ;
else
V_24 = F_106 ( V_14 ) ;
if ( V_24 )
goto error;
V_2 = V_14 -> V_15 ;
V_14 -> V_17 . V_110 = sizeof( struct V_30 ) +
F_2 ( V_2 ) ;
switch ( V_14 -> V_17 . V_102 ) {
case V_161 :
if ( V_14 -> V_162 . V_163 != V_123 )
V_14 -> V_17 . V_110 += V_164 +
( sizeof( struct V_109 ) - sizeof( struct V_165 ) ) ;
break;
case V_166 :
break;
case V_103 :
V_14 -> V_17 . V_110 += sizeof( struct V_109 ) ;
break;
default:
goto error;
}
V_159 = F_5 ( F_62 ( V_2 ) , 4 ) ;
V_14 -> V_17 . V_167 = V_159 + 1 + F_51 ( V_2 ) ;
error:
return V_24 ;
}
static int F_115 ( struct V_25 * V_26 , int V_24 )
{
return 0 ;
}
static int T_6 F_116 ( void )
{
if ( F_117 ( & V_168 , V_123 ) < 0 ) {
F_112 ( L_10 , V_169 ) ;
return - V_170 ;
}
if ( F_118 ( & V_171 , V_81 ) < 0 ) {
F_112 ( L_11 , V_169 ) ;
F_119 ( & V_168 , V_123 ) ;
return - V_170 ;
}
return 0 ;
}
static void T_7 F_120 ( void )
{
if ( F_121 ( & V_171 , V_81 ) < 0 )
F_112 ( L_12 , V_169 ) ;
if ( F_119 ( & V_168 , V_123 ) < 0 )
F_112 ( L_13 , V_169 ) ;
}
