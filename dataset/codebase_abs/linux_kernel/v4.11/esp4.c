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
struct V_31 * V_32 ,
struct V_10 * V_15 )
{
struct V_13 * V_14 = F_20 ( V_27 ) -> V_29 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_15 -> V_36 = ( unsigned char * ) V_32 -
F_28 ( V_27 ) ;
V_32 = (struct V_31 * ) ( ( unsigned char * ) V_32 - 4 ) ;
V_15 -> V_33 = V_32 -> V_35 ;
V_32 -> V_34 = F_29 ( F_30 ( V_27 ) -> V_37 . V_38 . V_39 ) ;
}
V_32 -> V_35 = V_14 -> V_40 . V_35 ;
return V_32 ;
}
static void F_31 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_25 ( V_27 ) ;
F_19 ( V_24 , V_25 ) ;
}
static void F_32 ( T_1 * V_41 , int V_42 , int V_43 , T_3 V_44 )
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
static int F_33 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_10 * V_15 ;
int V_25 = - V_46 ;
struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_17 , * V_47 ;
struct V_26 * V_48 ;
struct V_49 * V_49 ;
void * V_9 ;
T_1 * V_11 ;
T_1 * V_41 ;
T_1 * V_50 ;
int V_51 ;
int V_52 ;
int V_53 ;
int V_43 ;
int V_54 ;
int V_42 ;
int V_3 ;
int V_55 ;
int V_4 ;
int V_56 ;
T_4 V_57 ;
T_3 V_44 = * F_34 ( V_27 ) ;
V_2 = V_14 -> V_16 ;
V_53 = F_35 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
V_42 = 0 ;
if ( V_14 -> V_58 ) {
struct V_59 * V_22 = (struct V_59 * ) F_20 ( V_27 ) ;
T_5 V_60 ;
V_60 = F_36 ( V_14 -> V_58 , F_37 ( V_14 , V_22 -> V_61 ) ) ;
if ( V_27 -> V_5 < V_60 )
V_42 = V_60 - V_27 -> V_5 ;
}
V_51 = F_5 ( F_38 ( V_2 ) , 4 ) ;
V_52 = F_5 ( V_27 -> V_5 + 2 + V_42 , V_51 ) ;
V_43 = V_52 - V_27 -> V_5 - V_42 ;
V_56 = V_42 + V_43 + V_53 ;
V_55 = sizeof( * V_32 ) ;
V_4 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_4 += sizeof( * V_15 ) ;
V_55 += sizeof( T_2 ) ;
}
* F_34 ( V_27 ) = V_62 ;
V_32 = V_31 ( V_27 ) ;
if ( V_14 -> V_63 ) {
struct V_64 * V_63 = V_14 -> V_63 ;
struct V_65 * V_66 ;
T_2 * V_67 ;
T_6 V_68 , V_69 ;
int V_70 ;
F_39 ( & V_14 -> V_71 ) ;
V_68 = V_63 -> V_72 ;
V_69 = V_63 -> V_73 ;
V_70 = V_63 -> V_70 ;
F_40 ( & V_14 -> V_71 ) ;
V_66 = (struct V_65 * ) V_32 ;
V_66 -> V_74 = V_68 ;
V_66 -> V_75 = V_69 ;
V_66 -> V_5 = F_41 ( V_27 -> V_5 + V_56
- F_26 ( V_27 ) ) ;
V_66 -> V_76 = 0 ;
switch ( V_70 ) {
default:
case V_77 :
V_32 = (struct V_31 * ) ( V_66 + 1 ) ;
break;
case V_78 :
V_67 = ( T_2 * ) ( V_66 + 1 ) ;
V_67 [ 0 ] = V_67 [ 1 ] = 0 ;
V_32 = (struct V_31 * ) ( V_67 + 2 ) ;
break;
}
* F_34 ( V_27 ) = V_79 ;
}
if ( ! F_42 ( V_27 ) ) {
if ( V_56 <= F_43 ( V_27 ) ) {
V_3 = 1 ;
V_48 = V_27 ;
V_41 = F_44 ( V_48 ) ;
goto V_80;
} else if ( ( F_45 ( V_27 ) -> V_81 < V_82 )
&& ! F_46 ( V_27 ) ) {
int V_83 ;
struct V_84 * V_85 = V_27 -> V_85 ;
struct V_86 * V_87 = & V_14 -> V_88 ;
V_83 = F_5 ( V_56 , V_89 ) ;
F_39 ( & V_14 -> V_71 ) ;
if ( F_47 ( ! F_48 ( V_83 , V_87 , V_8 ) ) ) {
F_40 ( & V_14 -> V_71 ) ;
goto V_90;
}
V_49 = V_87 -> V_49 ;
F_49 ( V_49 ) ;
V_50 = F_50 ( V_49 ) ;
V_41 = V_50 + V_87 -> V_30 ;
F_32 ( V_41 , V_42 , V_43 , V_44 ) ;
F_51 ( V_50 ) ;
V_3 = F_45 ( V_27 ) -> V_81 ;
F_52 ( V_27 , V_3 , V_49 , V_87 -> V_30 ,
V_56 ) ;
F_45 ( V_27 ) -> V_81 = ++ V_3 ;
V_87 -> V_30 = V_87 -> V_30 + V_83 ;
V_3 ++ ;
V_27 -> V_5 += V_56 ;
V_27 -> V_91 += V_56 ;
V_27 -> V_92 += V_56 ;
if ( V_85 )
F_53 ( V_56 , & V_85 -> V_93 ) ;
F_54 ( V_27 , - F_55 ( V_27 ) ) ;
V_32 -> V_34 = F_29 ( F_30 ( V_27 ) -> V_37 . V_38 . V_94 ) ;
V_32 -> V_35 = V_14 -> V_40 . V_35 ;
V_9 = F_1 ( V_2 , V_3 + 2 , V_4 ) ;
if ( ! V_9 ) {
F_40 ( & V_14 -> V_71 ) ;
V_25 = - V_46 ;
goto error;
}
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_4 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
V_47 = & V_17 [ V_3 ] ;
V_32 = F_27 ( V_27 , V_32 , V_15 ) ;
F_56 ( V_17 , V_3 ) ;
F_57 ( V_27 , V_17 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_55 + V_54 + V_52 + V_53 ) ;
V_83 = F_5 ( V_27 -> V_91 , V_89 ) ;
if ( F_47 ( ! F_48 ( V_83 , V_87 , V_8 ) ) ) {
F_40 ( & V_14 -> V_71 ) ;
V_25 = - V_46 ;
goto error;
}
F_45 ( V_27 ) -> V_81 = 1 ;
V_49 = V_87 -> V_49 ;
F_49 ( V_49 ) ;
F_52 ( V_27 , 0 , V_49 , V_87 -> V_30 , V_27 -> V_91 ) ;
V_87 -> V_30 = V_87 -> V_30 + V_83 ;
F_56 ( V_47 , F_45 ( V_27 ) -> V_81 + 1 ) ;
F_57 ( V_27 , V_47 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_55 + V_54 + V_52 + V_53 ) ;
F_40 ( & V_14 -> V_71 ) ;
goto V_95;
}
}
V_90:
V_25 = F_58 ( V_27 , V_56 , & V_48 ) ;
if ( V_25 < 0 )
goto error;
V_3 = V_25 ;
V_41 = F_44 ( V_48 ) ;
V_32 = V_31 ( V_27 ) ;
V_80:
F_32 ( V_41 , V_42 , V_43 , V_44 ) ;
F_59 ( V_27 , V_48 , V_52 - V_27 -> V_5 + V_53 ) ;
F_54 ( V_27 , - F_55 ( V_27 ) ) ;
V_32 -> V_34 = F_29 ( F_30 ( V_27 ) -> V_37 . V_38 . V_94 ) ;
V_32 -> V_35 = V_14 -> V_40 . V_35 ;
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_9 ) {
V_25 = - V_46 ;
goto error;
}
V_15 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_4 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
V_47 = V_17 ;
V_32 = F_27 ( V_27 , V_32 , V_15 ) ;
F_56 ( V_17 , V_3 ) ;
F_57 ( V_27 , V_17 ,
( unsigned char * ) V_32 - V_27 -> V_16 ,
V_55 + V_54 + V_52 + V_53 ) ;
V_95:
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_60 ( V_12 , 0 , F_31 , V_27 ) ;
else
F_60 ( V_12 , 0 , F_19 , V_27 ) ;
F_61 ( V_12 , V_17 , V_47 , V_54 + V_52 , V_11 ) ;
F_62 ( V_12 , V_55 ) ;
V_57 = F_63 ( F_30 ( V_27 ) -> V_37 . V_38 . V_94 +
( ( V_96 ) F_30 ( V_27 ) -> V_37 . V_38 . V_39 << 32 ) ) ;
memset ( V_11 , 0 , V_54 ) ;
memcpy ( V_11 + V_54 - F_36 ( V_54 , 8 ) , ( T_1 * ) & V_57 + 8 - F_36 ( V_54 , 8 ) ,
F_36 ( V_54 , 8 ) ) ;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_25 = F_64 ( V_12 ) ;
switch ( V_25 ) {
case - V_97 :
goto error;
case - V_98 :
V_25 = V_99 ;
break;
case 0 :
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_25 ( V_27 ) ;
}
if ( V_17 != V_47 )
F_15 ( V_14 , V_9 ) ;
F_22 ( V_9 ) ;
error:
return V_25 ;
}
static int F_65 ( struct V_26 * V_27 , int V_25 )
{
const struct V_100 * V_101 ;
struct V_13 * V_14 = F_66 ( V_27 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_53 = F_35 ( V_2 ) ;
int V_102 = sizeof( struct V_31 ) + F_2 ( V_2 ) ;
int V_103 = V_27 -> V_5 - V_102 ;
int V_104 ;
T_1 V_105 [ 2 ] ;
int V_106 ;
F_22 ( F_21 ( V_27 ) -> V_9 ) ;
if ( F_47 ( V_25 ) )
goto V_107;
if ( F_67 ( V_27 , V_27 -> V_5 - V_53 - 2 , V_105 , 2 ) )
F_68 () ;
V_25 = - V_108 ;
V_106 = V_105 [ 0 ] ;
if ( V_106 + 2 + V_53 >= V_103 )
goto V_107;
V_101 = F_69 ( V_27 ) ;
V_104 = V_101 -> V_104 * 4 ;
if ( V_14 -> V_63 ) {
struct V_64 * V_63 = V_14 -> V_63 ;
struct V_65 * V_66 = ( void * ) ( F_70 ( V_27 ) + V_104 ) ;
if ( V_101 -> V_109 != V_14 -> V_18 . V_109 . V_110 ||
V_66 -> V_74 != V_63 -> V_72 ) {
T_7 V_111 ;
V_111 . V_110 = V_101 -> V_109 ;
F_71 ( V_14 , & V_111 , V_66 -> V_74 ) ;
}
if ( V_14 -> V_18 . V_112 == V_113 )
V_27 -> V_114 = V_115 ;
}
F_72 ( V_27 , V_27 -> V_5 - V_53 - V_106 - 2 ) ;
F_73 ( V_27 , V_102 ) ;
if ( V_14 -> V_18 . V_112 == V_116 )
F_74 ( V_27 ) ;
else
F_75 ( V_27 , - V_104 ) ;
V_25 = V_105 [ 1 ] ;
if ( V_25 == V_117 )
V_25 = - V_108 ;
V_107:
return V_25 ;
}
static void F_76 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_77 ( V_27 , F_65 ( V_27 , V_25 ) ) ;
}
static void F_78 ( struct V_26 * V_27 )
{
F_24 ( V_27 , 0 ) ;
F_73 ( V_27 , 4 ) ;
}
static void F_79 ( struct V_26 * V_27 , T_2 * V_33 )
{
struct V_13 * V_14 = F_66 ( V_27 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_27 -> V_16 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_32 = ( void * ) F_54 ( V_27 , 4 ) ;
* V_33 = V_32 -> V_35 ;
V_32 -> V_35 = V_32 -> V_34 ;
V_32 -> V_34 = F_30 ( V_27 ) -> V_37 . V_118 . V_39 ;
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
struct V_26 * V_48 ;
int V_54 = F_2 ( V_2 ) ;
int V_103 = V_27 -> V_5 - sizeof( * V_32 ) - V_54 ;
int V_3 ;
int V_55 ;
int V_119 ;
T_2 * V_33 ;
void * V_9 ;
T_1 * V_11 ;
struct V_7 * V_17 ;
int V_25 = - V_108 ;
if ( ! F_82 ( V_27 , sizeof( * V_32 ) + V_54 ) )
goto V_107;
if ( V_103 <= 0 )
goto V_107;
V_55 = sizeof( * V_32 ) ;
V_119 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_119 += sizeof( T_2 ) ;
V_55 += V_119 ;
}
if ( ! F_42 ( V_27 ) ) {
if ( ! F_83 ( V_27 ) ) {
V_3 = 1 ;
goto V_80;
} else if ( ! F_46 ( V_27 ) ) {
V_3 = F_45 ( V_27 ) -> V_81 ;
V_3 ++ ;
goto V_80;
}
}
V_25 = F_58 ( V_27 , 0 , & V_48 ) ;
if ( V_25 < 0 )
goto V_107;
V_3 = V_25 ;
V_80:
V_25 = - V_46 ;
V_9 = F_1 ( V_2 , V_3 , V_119 ) ;
if ( ! V_9 )
goto V_107;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_33 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_119 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
F_79 ( V_27 , V_33 ) ;
F_56 ( V_17 , V_3 ) ;
F_57 ( V_27 , V_17 , 0 , V_27 -> V_5 ) ;
V_27 -> V_114 = V_120 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_60 ( V_12 , 0 , F_80 , V_27 ) ;
else
F_60 ( V_12 , 0 , F_76 , V_27 ) ;
F_61 ( V_12 , V_17 , V_17 , V_103 + V_54 , V_11 ) ;
F_62 ( V_12 , V_55 ) ;
V_25 = F_84 ( V_12 ) ;
if ( V_25 == - V_97 )
goto V_107;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_78 ( V_27 ) ;
V_25 = F_65 ( V_27 , V_25 ) ;
V_107:
return V_25 ;
}
static T_5 F_37 ( struct V_13 * V_14 , int V_121 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
T_5 V_51 = F_5 ( F_38 ( V_2 ) , 4 ) ;
unsigned int V_122 ;
switch ( V_14 -> V_18 . V_112 ) {
case V_113 :
case V_123 :
V_122 = sizeof( struct V_100 ) ;
break;
case V_116 :
V_122 = 0 ;
break;
default:
F_68 () ;
}
return ( ( V_121 - V_14 -> V_18 . V_124 - F_35 ( V_2 ) -
V_122 ) & ~ ( V_51 - 1 ) ) + V_122 - 2 ;
}
static int F_85 ( struct V_26 * V_27 , T_5 V_125 )
{
struct V_126 * V_126 = F_86 ( V_27 -> V_127 ) ;
const struct V_100 * V_101 = ( const struct V_100 * ) V_27 -> V_16 ;
struct V_31 * V_32 = (struct V_31 * ) ( V_27 -> V_16 + ( V_101 -> V_104 << 2 ) ) ;
struct V_13 * V_14 ;
switch ( F_87 ( V_27 ) -> type ) {
case V_128 :
if ( F_87 ( V_27 ) -> V_129 != V_130 )
return 0 ;
case V_131 :
break;
default:
return 0 ;
}
V_14 = F_88 ( V_126 , V_27 -> V_132 , ( const T_7 * ) & V_101 -> V_133 ,
V_32 -> V_35 , V_62 , V_134 ) ;
if ( ! V_14 )
return 0 ;
if ( F_87 ( V_27 ) -> type == V_128 )
F_89 ( V_27 , V_126 , V_125 , 0 , 0 , V_62 , 0 ) ;
else
F_90 ( V_27 , V_126 , 0 , 0 , V_62 , 0 ) ;
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
char V_135 [ V_136 ] ;
struct V_1 * V_2 ;
int V_25 ;
V_25 = - V_137 ;
if ( snprintf ( V_135 , V_136 , L_1 ,
V_14 -> V_138 , V_14 -> V_2 -> V_139 ) >= V_136 )
goto error;
V_2 = F_95 ( V_135 , 0 , 0 ) ;
V_25 = F_96 ( V_2 ) ;
if ( F_97 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_25 = F_98 ( V_2 , V_14 -> V_2 -> V_140 ,
( V_14 -> V_2 -> V_141 + 7 ) / 8 ) ;
if ( V_25 )
goto error;
V_25 = F_99 ( V_2 , V_14 -> V_2 -> V_142 / 8 ) ;
if ( V_25 )
goto error;
error:
return V_25 ;
}
static int F_100 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
char * V_147 ;
char * V_148 ;
char V_149 [ V_136 ] ;
unsigned int V_150 ;
int V_25 ;
V_25 = - V_108 ;
if ( ! V_14 -> V_151 )
goto error;
V_25 = - V_137 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
if ( snprintf ( V_149 , V_136 ,
L_2 ,
V_14 -> V_138 ? : L_3 , V_14 -> V_138 ? L_4 : L_3 ,
V_14 -> V_152 ? V_14 -> V_152 -> V_139 : L_5 ,
V_14 -> V_151 -> V_139 ,
V_14 -> V_138 ? L_6 : L_3 ) >= V_136 )
goto error;
} else {
if ( snprintf ( V_149 , V_136 ,
L_7 ,
V_14 -> V_138 ? : L_3 , V_14 -> V_138 ? L_4 : L_3 ,
V_14 -> V_152 ? V_14 -> V_152 -> V_139 : L_5 ,
V_14 -> V_151 -> V_139 ,
V_14 -> V_138 ? L_6 : L_3 ) >= V_136 )
goto error;
}
V_2 = F_95 ( V_149 , 0 , 0 ) ;
V_25 = F_96 ( V_2 ) ;
if ( F_97 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_150 = ( V_14 -> V_152 ? ( V_14 -> V_152 -> V_141 + 7 ) / 8 : 0 ) +
( V_14 -> V_151 -> V_141 + 7 ) / 8 + F_101 ( sizeof( * V_144 ) ) ;
V_25 = - V_46 ;
V_147 = F_8 ( V_150 , V_153 ) ;
if ( ! V_147 )
goto error;
V_148 = V_147 ;
V_146 = ( void * ) V_148 ;
V_146 -> V_154 = V_155 ;
V_146 -> V_156 = F_102 ( sizeof( * V_144 ) ) ;
V_144 = F_103 ( V_146 ) ;
V_148 += F_101 ( sizeof( * V_144 ) ) ;
if ( V_14 -> V_152 ) {
struct V_157 * V_158 ;
memcpy ( V_148 , V_14 -> V_152 -> V_140 , ( V_14 -> V_152 -> V_141 + 7 ) / 8 ) ;
V_148 += ( V_14 -> V_152 -> V_141 + 7 ) / 8 ;
V_158 = F_104 ( V_14 -> V_152 -> V_139 , 0 ) ;
F_105 ( ! V_158 ) ;
V_25 = - V_108 ;
if ( V_158 -> V_159 . V_160 . V_161 / 8 !=
F_35 ( V_2 ) ) {
F_106 ( L_8 ,
V_14 -> V_152 -> V_139 ,
F_35 ( V_2 ) ,
V_158 -> V_159 . V_160 . V_161 / 8 ) ;
goto V_162;
}
V_25 = F_99 (
V_2 , V_14 -> V_152 -> V_163 / 8 ) ;
if ( V_25 )
goto V_162;
}
V_144 -> V_164 = F_107 ( ( V_14 -> V_151 -> V_141 + 7 ) / 8 ) ;
memcpy ( V_148 , V_14 -> V_151 -> V_140 , ( V_14 -> V_151 -> V_141 + 7 ) / 8 ) ;
V_25 = F_98 ( V_2 , V_147 , V_150 ) ;
V_162:
F_22 ( V_147 ) ;
error:
return V_25 ;
}
static int F_108 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_5 V_165 ;
int V_25 ;
V_14 -> V_16 = NULL ;
if ( V_14 -> V_2 )
V_25 = F_94 ( V_14 ) ;
else
V_25 = F_100 ( V_14 ) ;
if ( V_25 )
goto error;
V_2 = V_14 -> V_16 ;
V_14 -> V_18 . V_124 = sizeof( struct V_31 ) +
F_2 ( V_2 ) ;
if ( V_14 -> V_18 . V_112 == V_116 )
V_14 -> V_18 . V_124 += sizeof( struct V_100 ) ;
else if ( V_14 -> V_18 . V_112 == V_123 && V_14 -> V_166 . V_167 != V_168 )
V_14 -> V_18 . V_124 += V_169 ;
if ( V_14 -> V_63 ) {
struct V_64 * V_63 = V_14 -> V_63 ;
switch ( V_63 -> V_70 ) {
default:
goto error;
case V_77 :
V_14 -> V_18 . V_124 += sizeof( struct V_65 ) ;
break;
case V_78 :
V_14 -> V_18 . V_124 += sizeof( struct V_65 ) + 2 * sizeof( T_5 ) ;
break;
}
}
V_165 = F_5 ( F_38 ( V_2 ) , 4 ) ;
V_14 -> V_18 . V_170 = V_165 + 1 + F_35 ( V_2 ) ;
error:
return V_25 ;
}
static int F_109 ( struct V_26 * V_27 , int V_25 )
{
return 0 ;
}
static int T_8 F_110 ( void )
{
if ( F_111 ( & V_171 , V_134 ) < 0 ) {
F_106 ( L_9 , V_172 ) ;
return - V_173 ;
}
if ( F_112 ( & V_174 , V_62 ) < 0 ) {
F_106 ( L_10 , V_172 ) ;
F_113 ( & V_171 , V_134 ) ;
return - V_173 ;
}
return 0 ;
}
static void T_9 F_114 ( void )
{
if ( F_115 ( & V_174 , V_62 ) < 0 )
F_106 ( L_11 , V_172 ) ;
if ( F_113 ( & V_171 , V_134 ) < 0 )
F_106 ( L_12 , V_172 ) ;
}
