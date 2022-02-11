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
struct V_31 * V_32 ,
T_1 * V_15 )
{
struct V_13 * V_14 = F_20 ( V_27 ) -> V_29 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_32 = ( void * ) ( F_28 ( V_27 ) - sizeof( T_1 ) ) ;
* V_15 = V_32 -> V_34 ;
V_32 -> V_33 = F_29 ( F_30 ( V_27 ) -> V_35 . V_36 . V_37 ) ;
}
V_32 -> V_34 = V_14 -> V_38 . V_34 ;
return V_32 ;
}
static void F_31 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_25 ( V_27 ) ;
F_19 ( V_24 , V_25 ) ;
}
static void F_32 ( T_2 * V_39 , int V_40 , int V_41 , T_3 V_42 )
{
if ( V_40 ) {
memset ( V_39 , 0 , V_40 ) ;
V_39 += V_40 ;
}
do {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_41 - 2 ; V_43 ++ )
V_39 [ V_43 ] = V_43 + 1 ;
} while ( 0 );
V_39 [ V_41 - 2 ] = V_41 - 2 ;
V_39 [ V_41 - 1 ] = V_42 ;
}
static int F_33 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
int V_25 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_17 , * V_44 ;
struct V_26 * V_45 ;
struct V_46 * V_46 ;
void * V_9 ;
int V_47 ;
int V_48 ;
int V_49 ;
int V_41 ;
int V_50 ;
int V_40 ;
int V_3 ;
int V_51 ;
int V_10 ;
int V_52 ;
T_2 * V_11 ;
T_2 * V_39 ;
T_2 * V_53 ;
T_1 * V_15 ;
T_4 V_54 ;
T_3 V_42 = * F_34 ( V_27 ) ;
V_2 = V_14 -> V_16 ;
V_49 = F_35 ( V_2 ) ;
V_50 = F_2 ( V_2 ) ;
V_40 = 0 ;
if ( V_14 -> V_55 ) {
struct V_56 * V_22 = (struct V_56 * ) F_20 ( V_27 ) ;
T_5 V_57 ;
V_57 = F_36 ( V_14 -> V_55 , F_37 ( V_14 , V_22 -> V_58 ) ) ;
if ( V_27 -> V_5 < V_57 )
V_40 = V_57 - V_27 -> V_5 ;
}
V_47 = F_5 ( F_38 ( V_2 ) , 4 ) ;
V_48 = F_5 ( V_27 -> V_5 + 2 + V_40 , V_47 ) ;
V_41 = V_48 - V_27 -> V_5 - V_40 ;
V_52 = V_40 + V_41 + V_49 ;
V_51 = sizeof( * V_32 ) ;
V_10 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_10 += sizeof( T_1 ) ;
V_51 += V_10 ;
}
* F_34 ( V_27 ) = V_59 ;
V_32 = V_31 ( V_27 ) ;
if ( ! F_39 ( V_27 ) ) {
if ( V_52 <= F_40 ( V_27 ) ) {
V_3 = 1 ;
V_45 = V_27 ;
V_39 = F_41 ( V_45 ) ;
goto V_60;
} else if ( ( F_42 ( V_27 ) -> V_61 < V_62 )
&& ! F_43 ( V_27 ) ) {
int V_63 ;
struct V_64 * V_65 = V_27 -> V_65 ;
struct V_66 * V_67 = & V_14 -> V_68 ;
V_63 = F_5 ( V_52 , V_69 ) ;
F_44 ( & V_14 -> V_70 ) ;
if ( F_45 ( ! F_46 ( V_63 , V_67 , V_8 ) ) ) {
F_47 ( & V_14 -> V_70 ) ;
goto V_71;
}
V_46 = V_67 -> V_46 ;
F_48 ( V_46 ) ;
V_53 = F_49 ( V_46 ) ;
V_39 = V_53 + V_67 -> V_30 ;
F_32 ( V_39 , V_40 , V_41 , V_42 ) ;
F_50 ( V_53 ) ;
V_3 = F_42 ( V_27 ) -> V_61 ;
F_51 ( V_27 , V_3 , V_46 , V_67 -> V_30 ,
V_52 ) ;
F_42 ( V_27 ) -> V_61 = ++ V_3 ;
V_67 -> V_30 = V_67 -> V_30 + V_63 ;
V_3 ++ ;
V_27 -> V_5 += V_52 ;
V_27 -> V_72 += V_52 ;
V_27 -> V_73 += V_52 ;
if ( V_65 )
F_52 ( V_52 , & V_65 -> V_74 ) ;
F_53 ( V_27 , - F_54 ( V_27 ) ) ;
V_32 -> V_33 = F_29 ( F_30 ( V_27 ) -> V_35 . V_36 . V_75 ) ;
V_32 -> V_34 = V_14 -> V_38 . V_34 ;
V_9 = F_1 ( V_2 , V_3 + 2 , V_10 ) ;
if ( ! V_9 ) {
F_47 ( & V_14 -> V_70 ) ;
V_25 = - V_76 ;
goto error;
}
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
V_44 = & V_17 [ V_3 ] ;
V_32 = F_27 ( V_27 , V_32 , V_15 ) ;
F_55 ( V_17 , V_3 ) ;
F_56 ( V_27 , V_17 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_51 + V_50 + V_48 + V_49 ) ;
V_63 = F_5 ( V_27 -> V_72 , V_69 ) ;
if ( F_45 ( ! F_46 ( V_63 , V_67 , V_8 ) ) ) {
F_47 ( & V_14 -> V_70 ) ;
V_25 = - V_76 ;
goto error;
}
F_42 ( V_27 ) -> V_61 = 1 ;
V_46 = V_67 -> V_46 ;
F_48 ( V_46 ) ;
F_51 ( V_27 , 0 , V_46 , V_67 -> V_30 , V_27 -> V_72 ) ;
V_67 -> V_30 = V_67 -> V_30 + V_63 ;
F_55 ( V_44 , F_42 ( V_27 ) -> V_61 + 1 ) ;
F_56 ( V_27 , V_44 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_51 + V_50 + V_48 + V_49 ) ;
F_47 ( & V_14 -> V_70 ) ;
goto V_77;
}
}
V_71:
V_25 = F_57 ( V_27 , V_52 , & V_45 ) ;
if ( V_25 < 0 )
goto error;
V_3 = V_25 ;
V_39 = F_41 ( V_45 ) ;
V_32 = V_31 ( V_27 ) ;
V_60:
F_32 ( V_39 , V_40 , V_41 , V_42 ) ;
F_58 ( V_27 , V_45 , V_48 - V_27 -> V_5 + V_49 ) ;
F_53 ( V_27 , - F_54 ( V_27 ) ) ;
V_32 -> V_33 = F_29 ( F_30 ( V_27 ) -> V_35 . V_36 . V_75 ) ;
V_32 -> V_34 = V_14 -> V_38 . V_34 ;
V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! V_9 ) {
V_25 = - V_76 ;
goto error;
}
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
V_44 = V_17 ;
V_32 = F_27 ( V_27 , V_32 , V_15 ) ;
F_55 ( V_17 , V_3 ) ;
F_56 ( V_27 , V_17 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_51 + V_50 + V_48 + V_49 ) ;
V_77:
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_59 ( V_12 , 0 , F_31 , V_27 ) ;
else
F_59 ( V_12 , 0 , F_19 , V_27 ) ;
F_60 ( V_12 , V_17 , V_44 , V_50 + V_48 , V_11 ) ;
F_61 ( V_12 , V_51 ) ;
V_54 = F_62 ( F_30 ( V_27 ) -> V_35 . V_36 . V_75 +
( ( V_78 ) F_30 ( V_27 ) -> V_35 . V_36 . V_37 << 32 ) ) ;
memset ( V_11 , 0 , V_50 ) ;
memcpy ( V_11 + V_50 - F_36 ( V_50 , 8 ) , ( T_2 * ) & V_54 + 8 - F_36 ( V_50 , 8 ) ,
F_36 ( V_50 , 8 ) ) ;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_25 = F_63 ( V_12 ) ;
switch ( V_25 ) {
case - V_79 :
goto error;
case - V_80 :
V_25 = V_81 ;
break;
case 0 :
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_25 ( V_27 ) ;
}
if ( V_17 != V_44 )
F_15 ( V_14 , V_9 ) ;
F_22 ( V_9 ) ;
error:
return V_25 ;
}
static int F_64 ( struct V_26 * V_27 , int V_25 )
{
struct V_13 * V_14 = F_65 ( V_27 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_49 = F_35 ( V_2 ) ;
int V_82 = sizeof( struct V_31 ) + F_2 ( V_2 ) ;
int V_83 = V_27 -> V_5 - V_82 ;
int V_84 = F_66 ( V_27 ) ;
int V_85 ;
T_2 V_86 [ 2 ] ;
F_22 ( F_21 ( V_27 ) -> V_9 ) ;
if ( F_45 ( V_25 ) )
goto V_87;
if ( F_67 ( V_27 , V_27 -> V_5 - V_49 - 2 , V_86 , 2 ) )
F_68 () ;
V_25 = - V_88 ;
V_85 = V_86 [ 0 ] ;
if ( V_85 + 2 + V_49 >= V_83 ) {
F_69 ( L_1 ,
V_85 + 2 , V_83 - V_49 ) ;
goto V_87;
}
F_70 ( V_27 , V_27 -> V_5 - V_49 - V_85 - 2 ) ;
F_71 ( V_27 , V_82 ) ;
if ( V_14 -> V_18 . V_89 == V_90 )
F_72 ( V_27 ) ;
else
F_73 ( V_27 , - V_84 ) ;
V_25 = V_86 [ 1 ] ;
if ( V_25 == V_91 )
V_25 = - V_88 ;
V_87:
return V_25 ;
}
static void F_74 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_75 ( V_27 , F_64 ( V_27 , V_25 ) ) ;
}
static void F_76 ( struct V_26 * V_27 )
{
F_24 ( V_27 , 0 ) ;
F_71 ( V_27 , 4 ) ;
}
static void F_77 ( struct V_26 * V_27 , T_1 * V_15 )
{
struct V_13 * V_14 = F_65 ( V_27 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_27 -> V_16 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_32 = ( void * ) F_53 ( V_27 , 4 ) ;
* V_15 = V_32 -> V_34 ;
V_32 -> V_34 = V_32 -> V_33 ;
V_32 -> V_33 = F_30 ( V_27 ) -> V_35 . V_92 . V_37 ;
}
}
static void F_78 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_76 ( V_27 ) ;
F_74 ( V_24 , V_25 ) ;
}
static int F_79 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_6 * V_12 ;
struct V_26 * V_45 ;
int V_50 = F_2 ( V_2 ) ;
int V_83 = V_27 -> V_5 - sizeof( * V_32 ) - V_50 ;
int V_3 ;
int V_51 ;
int V_10 ;
int V_93 = 0 ;
void * V_9 ;
T_1 * V_15 ;
T_2 * V_11 ;
struct V_7 * V_17 ;
if ( ! F_80 ( V_27 , sizeof( * V_32 ) + V_50 ) ) {
V_93 = - V_88 ;
goto V_87;
}
if ( V_83 <= 0 ) {
V_93 = - V_88 ;
goto V_87;
}
V_51 = sizeof( * V_32 ) ;
V_10 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_10 += sizeof( T_1 ) ;
V_51 += V_10 ;
}
if ( ! F_39 ( V_27 ) ) {
if ( ! F_81 ( V_27 ) ) {
V_3 = 1 ;
goto V_60;
} else if ( ! F_43 ( V_27 ) ) {
V_3 = F_42 ( V_27 ) -> V_61 ;
V_3 ++ ;
goto V_60;
}
}
V_3 = F_57 ( V_27 , 0 , & V_45 ) ;
if ( V_3 < 0 ) {
V_93 = - V_88 ;
goto V_87;
}
V_60:
V_93 = - V_76 ;
V_9 = F_1 ( V_2 , V_3 , V_10 ) ;
if ( ! V_9 )
goto V_87;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_10 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
F_77 ( V_27 , V_15 ) ;
F_55 ( V_17 , V_3 ) ;
F_56 ( V_27 , V_17 , 0 , V_27 -> V_5 ) ;
V_27 -> V_94 = V_95 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_59 ( V_12 , 0 , F_78 , V_27 ) ;
else
F_59 ( V_12 , 0 , F_74 , V_27 ) ;
F_60 ( V_12 , V_17 , V_17 , V_83 + V_50 , V_11 ) ;
F_61 ( V_12 , V_51 ) ;
V_93 = F_82 ( V_12 ) ;
if ( V_93 == - V_79 )
goto V_87;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_76 ( V_27 ) ;
V_93 = F_64 ( V_27 , V_93 ) ;
V_87:
return V_93 ;
}
static T_5 F_37 ( struct V_13 * V_14 , int V_96 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
T_5 V_47 = F_5 ( F_38 ( V_2 ) , 4 ) ;
unsigned int V_97 ;
if ( V_14 -> V_18 . V_89 != V_90 )
V_97 = sizeof( struct V_98 ) ;
else
V_97 = 0 ;
return ( ( V_96 - V_14 -> V_18 . V_99 - F_35 ( V_2 ) -
V_97 ) & ~ ( V_47 - 1 ) ) + V_97 - 2 ;
}
static int F_83 ( struct V_26 * V_27 , struct V_100 * V_101 ,
T_2 type , T_2 V_102 , int V_30 , T_1 V_103 )
{
struct V_104 * V_104 = F_84 ( V_27 -> V_105 ) ;
const struct V_98 * V_106 = ( const struct V_98 * ) V_27 -> V_16 ;
struct V_31 * V_32 = (struct V_31 * ) ( V_27 -> V_16 + V_30 ) ;
struct V_13 * V_14 ;
if ( type != V_107 &&
type != V_108 )
return 0 ;
V_14 = F_85 ( V_104 , V_27 -> V_109 , ( const V_110 * ) & V_106 -> V_111 ,
V_32 -> V_34 , V_59 , V_112 ) ;
if ( ! V_14 )
return 0 ;
if ( type == V_108 )
F_86 ( V_27 , V_104 , V_27 -> V_105 -> V_113 , 0 ,
F_87 ( V_104 , NULL ) ) ;
else
F_88 ( V_27 , V_104 , V_103 , 0 , 0 , F_87 ( V_104 , NULL ) ) ;
F_89 ( V_14 ) ;
return 0 ;
}
static void F_90 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
if ( ! V_2 )
return;
F_91 ( V_2 ) ;
}
static int F_92 ( struct V_13 * V_14 )
{
char V_114 [ V_115 ] ;
struct V_1 * V_2 ;
int V_25 ;
V_25 = - V_116 ;
if ( snprintf ( V_114 , V_115 , L_2 ,
V_14 -> V_117 , V_14 -> V_2 -> V_118 ) >= V_115 )
goto error;
V_2 = F_93 ( V_114 , 0 , 0 ) ;
V_25 = F_94 ( V_2 ) ;
if ( F_95 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_25 = F_96 ( V_2 , V_14 -> V_2 -> V_119 ,
( V_14 -> V_2 -> V_120 + 7 ) / 8 ) ;
if ( V_25 )
goto error;
V_25 = F_97 ( V_2 , V_14 -> V_2 -> V_121 / 8 ) ;
if ( V_25 )
goto error;
error:
return V_25 ;
}
static int F_98 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
char * V_126 ;
char * V_127 ;
char V_128 [ V_115 ] ;
unsigned int V_129 ;
int V_25 ;
V_25 = - V_88 ;
if ( ! V_14 -> V_130 )
goto error;
V_25 = - V_116 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
if ( snprintf ( V_128 , V_115 ,
L_3 ,
V_14 -> V_117 ? : L_4 , V_14 -> V_117 ? L_5 : L_4 ,
V_14 -> V_131 ? V_14 -> V_131 -> V_118 : L_6 ,
V_14 -> V_130 -> V_118 ,
V_14 -> V_117 ? L_7 : L_4 ) >= V_115 )
goto error;
} else {
if ( snprintf ( V_128 , V_115 ,
L_8 ,
V_14 -> V_117 ? : L_4 , V_14 -> V_117 ? L_5 : L_4 ,
V_14 -> V_131 ? V_14 -> V_131 -> V_118 : L_6 ,
V_14 -> V_130 -> V_118 ,
V_14 -> V_117 ? L_7 : L_4 ) >= V_115 )
goto error;
}
V_2 = F_93 ( V_128 , 0 , 0 ) ;
V_25 = F_94 ( V_2 ) ;
if ( F_95 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_129 = ( V_14 -> V_131 ? ( V_14 -> V_131 -> V_120 + 7 ) / 8 : 0 ) +
( V_14 -> V_130 -> V_120 + 7 ) / 8 + F_99 ( sizeof( * V_123 ) ) ;
V_25 = - V_76 ;
V_126 = F_8 ( V_129 , V_132 ) ;
if ( ! V_126 )
goto error;
V_127 = V_126 ;
V_125 = ( void * ) V_127 ;
V_125 -> V_133 = V_134 ;
V_125 -> V_135 = F_100 ( sizeof( * V_123 ) ) ;
V_123 = F_101 ( V_125 ) ;
V_127 += F_99 ( sizeof( * V_123 ) ) ;
if ( V_14 -> V_131 ) {
struct V_136 * V_137 ;
memcpy ( V_127 , V_14 -> V_131 -> V_119 , ( V_14 -> V_131 -> V_120 + 7 ) / 8 ) ;
V_127 += ( V_14 -> V_131 -> V_120 + 7 ) / 8 ;
V_137 = F_102 ( V_14 -> V_131 -> V_118 , 0 ) ;
F_103 ( ! V_137 ) ;
V_25 = - V_88 ;
if ( V_137 -> V_138 . V_139 . V_140 / 8 !=
F_35 ( V_2 ) ) {
F_104 ( L_9 ,
V_14 -> V_131 -> V_118 ,
F_35 ( V_2 ) ,
V_137 -> V_138 . V_139 . V_140 / 8 ) ;
goto V_141;
}
V_25 = F_97 (
V_2 , V_14 -> V_131 -> V_142 / 8 ) ;
if ( V_25 )
goto V_141;
}
V_123 -> V_143 = F_105 ( ( V_14 -> V_130 -> V_120 + 7 ) / 8 ) ;
memcpy ( V_127 , V_14 -> V_130 -> V_119 , ( V_14 -> V_130 -> V_120 + 7 ) / 8 ) ;
V_25 = F_96 ( V_2 , V_126 , V_129 ) ;
V_141:
F_22 ( V_126 ) ;
error:
return V_25 ;
}
static int F_106 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_5 V_144 ;
int V_25 ;
if ( V_14 -> V_145 )
return - V_88 ;
V_14 -> V_16 = NULL ;
if ( V_14 -> V_2 )
V_25 = F_92 ( V_14 ) ;
else
V_25 = F_98 ( V_14 ) ;
if ( V_25 )
goto error;
V_2 = V_14 -> V_16 ;
V_14 -> V_18 . V_99 = sizeof( struct V_31 ) +
F_2 ( V_2 ) ;
switch ( V_14 -> V_18 . V_89 ) {
case V_146 :
if ( V_14 -> V_147 . V_148 != V_112 )
V_14 -> V_18 . V_99 += V_149 +
( sizeof( struct V_98 ) - sizeof( struct V_150 ) ) ;
break;
case V_151 :
break;
case V_90 :
V_14 -> V_18 . V_99 += sizeof( struct V_98 ) ;
break;
default:
goto error;
}
V_144 = F_5 ( F_38 ( V_2 ) , 4 ) ;
V_14 -> V_18 . V_152 = V_144 + 1 + F_35 ( V_2 ) ;
error:
return V_25 ;
}
static int F_107 ( struct V_26 * V_27 , int V_25 )
{
return 0 ;
}
static int T_6 F_108 ( void )
{
if ( F_109 ( & V_153 , V_112 ) < 0 ) {
F_104 ( L_10 , V_154 ) ;
return - V_155 ;
}
if ( F_110 ( & V_156 , V_59 ) < 0 ) {
F_104 ( L_11 , V_154 ) ;
F_111 ( & V_153 , V_112 ) ;
return - V_155 ;
}
return 0 ;
}
static void T_7 F_112 ( void )
{
if ( F_113 ( & V_156 , V_59 ) < 0 )
F_104 ( L_12 , V_154 ) ;
if ( F_111 ( & V_153 , V_112 ) < 0 )
F_104 ( L_13 , V_154 ) ;
}
