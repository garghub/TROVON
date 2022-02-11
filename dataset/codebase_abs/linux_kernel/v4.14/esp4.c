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
static inline void * F_9 ( void * V_9 )
{
return F_10 ( V_9 , F_7 ( struct V_10 ) ) ;
}
static inline T_1 * F_11 ( struct V_1 * V_2 , void * V_9 , int V_4 )
{
return F_2 ( V_2 ) ?
F_10 ( ( T_1 * ) V_9 + V_4 ,
F_3 ( V_2 ) + 1 ) : V_9 + V_4 ;
}
static inline struct V_6 * F_12 ( struct V_1 * V_2 , T_1 * V_11 )
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
struct V_10 * V_15 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_4 = 0 ;
T_1 * V_11 ;
struct V_6 * V_12 ;
struct V_7 * V_17 ;
if ( V_14 -> V_18 . V_19 & V_20 )
V_4 += sizeof( * V_15 ) ;
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_4 ) ;
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
T_2 * V_33 = F_9 ( V_9 ) ;
V_32 -> V_34 = V_32 -> V_35 ;
V_32 -> V_35 = * V_33 ;
}
static void F_25 ( struct V_26 * V_27 )
{
void * V_9 = F_21 ( V_27 ) -> V_9 ;
struct V_10 * V_15 = F_9 ( V_9 ) ;
F_24 ( V_27 , F_26 ( V_27 ) + V_15 -> V_36 -
sizeof( T_2 ) ) ;
}
static struct V_31 * F_27 ( struct V_26 * V_27 ,
struct V_13 * V_14 ,
struct V_31 * V_32 ,
struct V_10 * V_15 )
{
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
T_3 V_33 ;
struct V_37 * V_38 = V_37 ( V_27 ) ;
if ( V_38 )
V_33 = V_38 -> V_39 . V_40 ;
else
V_33 = F_28 ( V_27 ) -> V_39 . V_41 . V_40 ;
V_15 -> V_36 = ( unsigned char * ) V_32 -
F_29 ( V_27 ) ;
V_32 = (struct V_31 * ) ( ( unsigned char * ) V_32 - 4 ) ;
V_15 -> V_33 = V_32 -> V_35 ;
V_32 -> V_34 = F_30 ( V_33 ) ;
}
V_32 -> V_35 = V_14 -> V_42 . V_35 ;
return V_32 ;
}
static void F_31 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_25 ( V_27 ) ;
F_19 ( V_24 , V_25 ) ;
}
static void F_32 ( T_1 * V_43 , int V_44 , int V_45 , T_4 V_46 )
{
if ( V_44 ) {
memset ( V_43 , 0 , V_44 ) ;
V_43 += V_44 ;
}
do {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_45 - 2 ; V_47 ++ )
V_43 [ V_47 ] = V_47 + 1 ;
} while ( 0 );
V_43 [ V_45 - 2 ] = V_45 - 2 ;
V_43 [ V_45 - 1 ] = V_46 ;
}
static void F_33 ( struct V_13 * V_14 , struct V_26 * V_27 , struct V_48 * V_49 )
{
int V_50 ;
struct V_51 * V_52 ;
T_2 * V_53 ;
T_5 V_54 , V_55 ;
struct V_56 * V_57 = V_14 -> V_57 ;
struct V_31 * V_32 = V_49 -> V_32 ;
F_34 ( & V_14 -> V_58 ) ;
V_54 = V_57 -> V_59 ;
V_55 = V_57 -> V_60 ;
V_50 = V_57 -> V_50 ;
F_35 ( & V_14 -> V_58 ) ;
V_52 = (struct V_51 * ) V_32 ;
V_52 -> V_61 = V_54 ;
V_52 -> V_62 = V_55 ;
V_52 -> V_5 = F_36 ( V_27 -> V_5 + V_49 -> V_63
- F_26 ( V_27 ) ) ;
V_52 -> V_64 = 0 ;
switch ( V_50 ) {
default:
case V_65 :
V_32 = (struct V_31 * ) ( V_52 + 1 ) ;
break;
case V_66 :
V_53 = ( T_2 * ) ( V_52 + 1 ) ;
V_53 [ 0 ] = V_53 [ 1 ] = 0 ;
V_32 = (struct V_31 * ) ( V_53 + 2 ) ;
break;
}
* F_37 ( V_27 ) = V_67 ;
V_49 -> V_32 = V_32 ;
}
int F_38 ( struct V_13 * V_14 , struct V_26 * V_27 , struct V_48 * V_49 )
{
T_1 * V_43 ;
T_1 * V_68 ;
int V_3 ;
int V_69 ;
struct V_70 * V_70 ;
struct V_26 * V_71 ;
int V_63 = V_49 -> V_63 ;
if ( V_14 -> V_57 )
F_33 ( V_14 , V_27 , V_49 ) ;
if ( ! F_39 ( V_27 ) ) {
if ( V_63 <= F_40 ( V_27 ) ) {
V_3 = 1 ;
V_71 = V_27 ;
V_43 = F_41 ( V_71 ) ;
goto V_72;
} else if ( ( F_42 ( V_27 ) -> V_73 < V_74 )
&& ! F_43 ( V_27 ) ) {
int V_75 ;
struct V_76 * V_77 = V_27 -> V_77 ;
struct V_78 * V_79 = & V_14 -> V_80 ;
V_49 -> V_81 = false ;
V_75 = F_5 ( V_63 , V_82 ) ;
F_34 ( & V_14 -> V_58 ) ;
if ( F_44 ( ! F_45 ( V_75 , V_79 , V_8 ) ) ) {
F_35 ( & V_14 -> V_58 ) ;
goto V_83;
}
V_70 = V_79 -> V_70 ;
F_46 ( V_70 ) ;
V_68 = F_47 ( V_70 ) ;
V_43 = V_68 + V_79 -> V_30 ;
F_32 ( V_43 , V_49 -> V_44 , V_49 -> V_45 , V_49 -> V_46 ) ;
F_48 ( V_68 ) ;
V_3 = F_42 ( V_27 ) -> V_73 ;
F_49 ( V_27 , V_3 , V_70 , V_79 -> V_30 ,
V_63 ) ;
F_42 ( V_27 ) -> V_73 = ++ V_3 ;
V_79 -> V_30 = V_79 -> V_30 + V_75 ;
F_35 ( & V_14 -> V_58 ) ;
V_3 ++ ;
V_27 -> V_5 += V_63 ;
V_27 -> V_84 += V_63 ;
V_27 -> V_85 += V_63 ;
if ( V_77 )
F_50 ( V_63 , & V_77 -> V_86 ) ;
goto V_87;
}
}
V_83:
V_69 = ( unsigned char * ) V_49 -> V_32 - F_29 ( V_27 ) ;
V_3 = F_51 ( V_27 , V_63 , & V_71 ) ;
if ( V_3 < 0 )
goto V_87;
V_43 = F_41 ( V_71 ) ;
V_49 -> V_32 = (struct V_31 * ) ( F_29 ( V_27 ) + V_69 ) ;
V_72:
F_32 ( V_43 , V_49 -> V_44 , V_49 -> V_45 , V_49 -> V_46 ) ;
F_52 ( V_27 , V_71 , V_63 ) ;
V_87:
return V_3 ;
}
int F_53 ( struct V_13 * V_14 , struct V_26 * V_27 , struct V_48 * V_49 )
{
T_1 * V_11 ;
int V_88 ;
void * V_9 ;
int V_89 ;
int V_90 ;
int V_4 ;
struct V_70 * V_70 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_17 , * V_91 ;
struct V_10 * V_15 ;
int V_25 = - V_92 ;
V_90 = sizeof( struct V_31 ) ;
V_4 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_4 += sizeof( * V_15 ) ;
V_90 += sizeof( T_2 ) ;
}
V_2 = V_14 -> V_16 ;
V_88 = F_54 ( V_2 ) ;
V_89 = F_2 ( V_2 ) ;
V_9 = F_1 ( V_2 , V_49 -> V_3 + 2 , V_4 ) ;
if ( ! V_9 )
goto error;
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_4 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
if ( V_49 -> V_81 )
V_91 = V_17 ;
else
V_91 = & V_17 [ V_49 -> V_3 ] ;
V_32 = F_27 ( V_27 , V_14 , V_49 -> V_32 , V_15 ) ;
V_49 -> V_32 = V_32 ;
F_55 ( V_17 , V_49 -> V_3 ) ;
V_25 = F_56 ( V_27 , V_17 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_90 + V_89 + V_49 -> V_93 + V_88 ) ;
if ( F_44 ( V_25 < 0 ) )
goto V_94;
if ( ! V_49 -> V_81 ) {
int V_75 ;
struct V_78 * V_79 = & V_14 -> V_80 ;
V_75 = F_5 ( V_27 -> V_84 , V_82 ) ;
F_34 ( & V_14 -> V_58 ) ;
if ( F_44 ( ! F_45 ( V_75 , V_79 , V_8 ) ) ) {
F_35 ( & V_14 -> V_58 ) ;
goto V_94;
}
F_42 ( V_27 ) -> V_73 = 1 ;
V_70 = V_79 -> V_70 ;
F_46 ( V_70 ) ;
F_49 ( V_27 , 0 , V_70 , V_79 -> V_30 , V_27 -> V_84 ) ;
V_79 -> V_30 = V_79 -> V_30 + V_75 ;
F_35 ( & V_14 -> V_58 ) ;
F_55 ( V_91 , F_42 ( V_27 ) -> V_73 + 1 ) ;
V_25 = F_56 ( V_27 , V_91 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_90 + V_89 + V_49 -> V_93 + V_88 ) ;
if ( F_44 ( V_25 < 0 ) )
goto V_94;
}
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_57 ( V_12 , 0 , F_31 , V_27 ) ;
else
F_57 ( V_12 , 0 , F_19 , V_27 ) ;
F_58 ( V_12 , V_17 , V_91 , V_89 + V_49 -> V_93 , V_11 ) ;
F_59 ( V_12 , V_90 ) ;
memset ( V_11 , 0 , V_89 ) ;
memcpy ( V_11 + V_89 - F_60 ( V_89 , 8 ) , ( T_1 * ) & V_49 -> V_95 + 8 - F_60 ( V_89 , 8 ) ,
F_60 ( V_89 , 8 ) ) ;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_25 = F_61 ( V_12 ) ;
switch ( V_25 ) {
case - V_96 :
goto error;
case - V_97 :
V_25 = V_98 ;
break;
case 0 :
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_25 ( V_27 ) ;
}
if ( V_17 != V_91 )
F_15 ( V_14 , V_9 ) ;
V_94:
F_22 ( V_9 ) ;
error:
return V_25 ;
}
static int F_62 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
int V_88 ;
int V_99 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_48 V_49 ;
V_49 . V_81 = true ;
V_49 . V_46 = * F_37 ( V_27 ) ;
* F_37 ( V_27 ) = V_100 ;
V_2 = V_14 -> V_16 ;
V_88 = F_54 ( V_2 ) ;
V_49 . V_44 = 0 ;
if ( V_14 -> V_101 ) {
struct V_102 * V_22 = (struct V_102 * ) F_20 ( V_27 ) ;
T_6 V_103 ;
V_103 = F_60 ( V_14 -> V_101 , F_63 ( V_14 , V_22 -> V_104 ) ) ;
if ( V_27 -> V_5 < V_103 )
V_49 . V_44 = V_103 - V_27 -> V_5 ;
}
V_99 = F_5 ( F_64 ( V_2 ) , 4 ) ;
V_49 . V_93 = F_5 ( V_27 -> V_5 + 2 + V_49 . V_44 , V_99 ) ;
V_49 . V_45 = V_49 . V_93 - V_27 -> V_5 - V_49 . V_44 ;
V_49 . V_63 = V_49 . V_44 + V_49 . V_45 + V_88 ;
V_49 . V_32 = V_31 ( V_27 ) ;
V_49 . V_3 = F_38 ( V_14 , V_27 , & V_49 ) ;
if ( V_49 . V_3 < 0 )
return V_49 . V_3 ;
V_32 = V_49 . V_32 ;
V_32 -> V_35 = V_14 -> V_42 . V_35 ;
V_32 -> V_34 = F_30 ( F_28 ( V_27 ) -> V_39 . V_41 . V_105 ) ;
V_49 . V_95 = F_65 ( F_28 ( V_27 ) -> V_39 . V_41 . V_105 +
( ( V_106 ) F_28 ( V_27 ) -> V_39 . V_41 . V_40 << 32 ) ) ;
F_66 ( V_27 , - F_67 ( V_27 ) ) ;
return F_53 ( V_14 , V_27 , & V_49 ) ;
}
static inline int F_68 ( struct V_26 * V_27 )
{
struct V_13 * V_14 = F_69 ( V_27 ) ;
struct V_37 * V_38 = V_37 ( V_27 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_88 , V_107 , V_108 ;
int V_109 , V_110 ;
T_7 V_111 ;
T_1 V_112 [ 2 ] ;
int V_113 ;
V_88 = F_54 ( V_2 ) ;
V_107 = sizeof( struct V_31 ) + F_2 ( V_2 ) ;
V_108 = V_27 -> V_5 - V_107 ;
if ( V_38 && ( V_38 -> V_19 & V_114 ) ) {
V_113 = V_38 -> V_46 ;
goto V_87;
}
if ( F_70 ( V_27 , V_27 -> V_5 - V_88 - 2 , V_112 , 2 ) )
F_71 () ;
V_113 = - V_115 ;
V_109 = V_112 [ 0 ] ;
if ( V_109 + 2 + V_88 >= V_108 ) {
F_72 ( L_1 ,
V_109 + 2 , V_108 - V_88 ) ;
goto V_87;
}
V_110 = V_88 + V_109 + 2 ;
if ( V_27 -> V_116 == V_117 ) {
V_111 = F_73 ( V_27 , V_27 -> V_5 - V_110 , V_110 , 0 ) ;
V_27 -> V_118 = F_74 ( V_27 -> V_118 , V_111 ,
V_27 -> V_5 - V_110 ) ;
}
F_75 ( V_27 , V_27 -> V_5 - V_110 ) ;
V_113 = V_112 [ 1 ] ;
V_87:
return V_113 ;
}
int F_76 ( struct V_26 * V_27 , int V_25 )
{
const struct V_119 * V_120 ;
struct V_13 * V_14 = F_69 ( V_27 ) ;
struct V_37 * V_38 = V_37 ( V_27 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_107 = sizeof( struct V_31 ) + F_2 ( V_2 ) ;
int V_121 ;
if ( ! V_38 || ( V_38 && ! ( V_38 -> V_19 & V_122 ) ) )
F_22 ( F_21 ( V_27 ) -> V_9 ) ;
if ( F_44 ( V_25 ) )
goto V_87;
V_25 = F_68 ( V_27 ) ;
if ( F_44 ( V_25 < 0 ) )
goto V_87;
V_120 = F_77 ( V_27 ) ;
V_121 = V_120 -> V_121 * 4 ;
if ( V_14 -> V_57 ) {
struct V_56 * V_57 = V_14 -> V_57 ;
struct V_51 * V_52 = ( void * ) ( F_78 ( V_27 ) + V_121 ) ;
if ( V_120 -> V_123 != V_14 -> V_18 . V_123 . V_124 ||
V_52 -> V_61 != V_57 -> V_59 ) {
T_8 V_125 ;
V_125 . V_124 = V_120 -> V_123 ;
F_79 ( V_14 , & V_125 , V_52 -> V_61 ) ;
}
if ( V_14 -> V_18 . V_126 == V_127 )
V_27 -> V_116 = V_128 ;
}
F_80 ( V_27 , V_107 ) ;
if ( V_14 -> V_18 . V_126 == V_129 )
F_81 ( V_27 ) ;
else
F_82 ( V_27 , - V_121 ) ;
if ( V_25 == V_130 )
V_25 = - V_115 ;
V_87:
return V_25 ;
}
static void F_83 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_84 ( V_27 , F_76 ( V_27 , V_25 ) ) ;
}
static void F_85 ( struct V_26 * V_27 )
{
F_24 ( V_27 , 0 ) ;
F_86 ( V_27 , 4 ) ;
}
static void F_87 ( struct V_26 * V_27 , T_2 * V_33 )
{
struct V_13 * V_14 = F_69 ( V_27 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_27 -> V_16 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_32 = F_66 ( V_27 , 4 ) ;
* V_33 = V_32 -> V_35 ;
V_32 -> V_35 = V_32 -> V_34 ;
V_32 -> V_34 = F_28 ( V_27 ) -> V_39 . V_131 . V_40 ;
}
}
static void F_88 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_85 ( V_27 ) ;
F_83 ( V_24 , V_25 ) ;
}
static int F_89 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_6 * V_12 ;
struct V_26 * V_71 ;
int V_89 = F_2 ( V_2 ) ;
int V_108 = V_27 -> V_5 - sizeof( * V_32 ) - V_89 ;
int V_3 ;
int V_90 ;
int V_132 ;
T_2 * V_33 ;
void * V_9 ;
T_1 * V_11 ;
struct V_7 * V_17 ;
int V_25 = - V_115 ;
if ( ! F_90 ( V_27 , sizeof( * V_32 ) + V_89 ) )
goto V_87;
if ( V_108 <= 0 )
goto V_87;
V_90 = sizeof( * V_32 ) ;
V_132 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_132 += sizeof( T_2 ) ;
V_90 += V_132 ;
}
if ( ! F_39 ( V_27 ) ) {
if ( ! F_91 ( V_27 ) ) {
V_3 = 1 ;
goto V_72;
} else if ( ! F_43 ( V_27 ) ) {
V_3 = F_42 ( V_27 ) -> V_73 ;
V_3 ++ ;
goto V_72;
}
}
V_25 = F_51 ( V_27 , 0 , & V_71 ) ;
if ( V_25 < 0 )
goto V_87;
V_3 = V_25 ;
V_72:
V_25 = - V_92 ;
V_9 = F_1 ( V_2 , V_3 , V_132 ) ;
if ( ! V_9 )
goto V_87;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_33 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_132 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
F_87 ( V_27 , V_33 ) ;
F_55 ( V_17 , V_3 ) ;
V_25 = F_56 ( V_27 , V_17 , 0 , V_27 -> V_5 ) ;
if ( F_44 ( V_25 < 0 ) ) {
F_22 ( V_9 ) ;
goto V_87;
}
V_27 -> V_116 = V_133 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_57 ( V_12 , 0 , F_88 , V_27 ) ;
else
F_57 ( V_12 , 0 , F_83 , V_27 ) ;
F_58 ( V_12 , V_17 , V_17 , V_108 + V_89 , V_11 ) ;
F_59 ( V_12 , V_90 ) ;
V_25 = F_92 ( V_12 ) ;
if ( V_25 == - V_96 )
goto V_87;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_85 ( V_27 ) ;
V_25 = F_76 ( V_27 , V_25 ) ;
V_87:
return V_25 ;
}
static T_6 F_63 ( struct V_13 * V_14 , int V_134 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
T_6 V_99 = F_5 ( F_64 ( V_2 ) , 4 ) ;
unsigned int V_135 ;
switch ( V_14 -> V_18 . V_126 ) {
case V_127 :
case V_136 :
V_135 = sizeof( struct V_119 ) ;
break;
case V_129 :
V_135 = 0 ;
break;
default:
F_71 () ;
}
return ( ( V_134 - V_14 -> V_18 . V_137 - F_54 ( V_2 ) -
V_135 ) & ~ ( V_99 - 1 ) ) + V_135 - 2 ;
}
static int F_93 ( struct V_26 * V_27 , T_6 V_138 )
{
struct V_139 * V_139 = F_94 ( V_27 -> V_140 ) ;
const struct V_119 * V_120 = ( const struct V_119 * ) V_27 -> V_16 ;
struct V_31 * V_32 = (struct V_31 * ) ( V_27 -> V_16 + ( V_120 -> V_121 << 2 ) ) ;
struct V_13 * V_14 ;
switch ( F_95 ( V_27 ) -> type ) {
case V_141 :
if ( F_95 ( V_27 ) -> V_142 != V_143 )
return 0 ;
case V_144 :
break;
default:
return 0 ;
}
V_14 = F_96 ( V_139 , V_27 -> V_145 , ( const T_8 * ) & V_120 -> V_146 ,
V_32 -> V_35 , V_100 , V_147 ) ;
if ( ! V_14 )
return 0 ;
if ( F_95 ( V_27 ) -> type == V_141 )
F_97 ( V_27 , V_139 , V_138 , 0 , 0 , V_100 , 0 ) ;
else
F_98 ( V_27 , V_139 , 0 , 0 , V_100 , 0 ) ;
F_99 ( V_14 ) ;
return 0 ;
}
static void F_100 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
if ( ! V_2 )
return;
F_101 ( V_2 ) ;
}
static int F_102 ( struct V_13 * V_14 )
{
char V_148 [ V_149 ] ;
struct V_1 * V_2 ;
int V_25 ;
T_6 V_150 = 0 ;
V_25 = - V_151 ;
if ( snprintf ( V_148 , V_149 , L_2 ,
V_14 -> V_152 , V_14 -> V_2 -> V_153 ) >= V_149 )
goto error;
if ( V_14 -> V_154 . V_155 )
V_150 |= V_156 ;
V_2 = F_103 ( V_148 , 0 , V_150 ) ;
V_25 = F_104 ( V_2 ) ;
if ( F_105 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_25 = F_106 ( V_2 , V_14 -> V_2 -> V_157 ,
( V_14 -> V_2 -> V_158 + 7 ) / 8 ) ;
if ( V_25 )
goto error;
V_25 = F_107 ( V_2 , V_14 -> V_2 -> V_159 / 8 ) ;
if ( V_25 )
goto error;
error:
return V_25 ;
}
static int F_108 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
char * V_164 ;
char * V_165 ;
char V_166 [ V_149 ] ;
unsigned int V_167 ;
int V_25 ;
T_6 V_150 = 0 ;
V_25 = - V_115 ;
if ( ! V_14 -> V_168 )
goto error;
V_25 = - V_151 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
if ( snprintf ( V_166 , V_149 ,
L_3 ,
V_14 -> V_152 ? : L_4 , V_14 -> V_152 ? L_5 : L_4 ,
V_14 -> V_169 ? V_14 -> V_169 -> V_153 : L_6 ,
V_14 -> V_168 -> V_153 ,
V_14 -> V_152 ? L_7 : L_4 ) >= V_149 )
goto error;
} else {
if ( snprintf ( V_166 , V_149 ,
L_8 ,
V_14 -> V_152 ? : L_4 , V_14 -> V_152 ? L_5 : L_4 ,
V_14 -> V_169 ? V_14 -> V_169 -> V_153 : L_6 ,
V_14 -> V_168 -> V_153 ,
V_14 -> V_152 ? L_7 : L_4 ) >= V_149 )
goto error;
}
if ( V_14 -> V_154 . V_155 )
V_150 |= V_156 ;
V_2 = F_103 ( V_166 , 0 , V_150 ) ;
V_25 = F_104 ( V_2 ) ;
if ( F_105 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_167 = ( V_14 -> V_169 ? ( V_14 -> V_169 -> V_158 + 7 ) / 8 : 0 ) +
( V_14 -> V_168 -> V_158 + 7 ) / 8 + F_109 ( sizeof( * V_161 ) ) ;
V_25 = - V_92 ;
V_164 = F_8 ( V_167 , V_170 ) ;
if ( ! V_164 )
goto error;
V_165 = V_164 ;
V_163 = ( void * ) V_165 ;
V_163 -> V_171 = V_172 ;
V_163 -> V_173 = F_110 ( sizeof( * V_161 ) ) ;
V_161 = F_111 ( V_163 ) ;
V_165 += F_109 ( sizeof( * V_161 ) ) ;
if ( V_14 -> V_169 ) {
struct V_174 * V_175 ;
memcpy ( V_165 , V_14 -> V_169 -> V_157 , ( V_14 -> V_169 -> V_158 + 7 ) / 8 ) ;
V_165 += ( V_14 -> V_169 -> V_158 + 7 ) / 8 ;
V_175 = F_112 ( V_14 -> V_169 -> V_153 , 0 ) ;
F_113 ( ! V_175 ) ;
V_25 = - V_115 ;
if ( V_175 -> V_176 . V_177 . V_178 / 8 !=
F_54 ( V_2 ) ) {
F_114 ( L_9 ,
V_14 -> V_169 -> V_153 ,
F_54 ( V_2 ) ,
V_175 -> V_176 . V_177 . V_178 / 8 ) ;
goto V_179;
}
V_25 = F_107 (
V_2 , V_14 -> V_169 -> V_180 / 8 ) ;
if ( V_25 )
goto V_179;
}
V_161 -> V_181 = F_115 ( ( V_14 -> V_168 -> V_158 + 7 ) / 8 ) ;
memcpy ( V_165 , V_14 -> V_168 -> V_157 , ( V_14 -> V_168 -> V_158 + 7 ) / 8 ) ;
V_25 = F_106 ( V_2 , V_164 , V_167 ) ;
V_179:
F_22 ( V_164 ) ;
error:
return V_25 ;
}
static int F_116 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_6 V_182 ;
int V_25 ;
V_14 -> V_16 = NULL ;
if ( V_14 -> V_2 )
V_25 = F_102 ( V_14 ) ;
else
V_25 = F_108 ( V_14 ) ;
if ( V_25 )
goto error;
V_2 = V_14 -> V_16 ;
V_14 -> V_18 . V_137 = sizeof( struct V_31 ) +
F_2 ( V_2 ) ;
if ( V_14 -> V_18 . V_126 == V_129 )
V_14 -> V_18 . V_137 += sizeof( struct V_119 ) ;
else if ( V_14 -> V_18 . V_126 == V_136 && V_14 -> V_183 . V_184 != V_185 )
V_14 -> V_18 . V_137 += V_186 ;
if ( V_14 -> V_57 ) {
struct V_56 * V_57 = V_14 -> V_57 ;
switch ( V_57 -> V_50 ) {
default:
goto error;
case V_65 :
V_14 -> V_18 . V_137 += sizeof( struct V_51 ) ;
break;
case V_66 :
V_14 -> V_18 . V_137 += sizeof( struct V_51 ) + 2 * sizeof( T_6 ) ;
break;
}
}
V_182 = F_5 ( F_64 ( V_2 ) , 4 ) ;
V_14 -> V_18 . V_187 = V_182 + 1 + F_54 ( V_2 ) ;
error:
return V_25 ;
}
static int F_117 ( struct V_26 * V_27 , int V_25 )
{
return 0 ;
}
static int T_9 F_118 ( void )
{
if ( F_119 ( & V_188 , V_147 ) < 0 ) {
F_114 ( L_10 , V_189 ) ;
return - V_190 ;
}
if ( F_120 ( & V_191 , V_100 ) < 0 ) {
F_114 ( L_11 , V_189 ) ;
F_121 ( & V_188 , V_147 ) ;
return - V_190 ;
}
return 0 ;
}
static void T_10 F_122 ( void )
{
if ( F_123 ( & V_191 , V_100 ) < 0 )
F_114 ( L_12 , V_189 ) ;
if ( F_121 ( & V_188 , V_147 ) < 0 )
F_114 ( L_13 , V_189 ) ;
}
