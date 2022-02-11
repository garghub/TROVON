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
int F_68 ( struct V_26 * V_27 , int V_25 )
{
const struct V_107 * V_108 ;
struct V_13 * V_14 = F_69 ( V_27 ) ;
struct V_37 * V_38 = V_37 ( V_27 ) ;
struct V_1 * V_2 = V_14 -> V_16 ;
int V_88 = F_54 ( V_2 ) ;
int V_109 = sizeof( struct V_31 ) + F_2 ( V_2 ) ;
int V_110 = V_27 -> V_5 - V_109 ;
int V_111 ;
T_1 V_112 [ 2 ] ;
int V_113 ;
if ( ! V_38 || ( V_38 && ! ( V_38 -> V_19 & V_114 ) ) )
F_22 ( F_21 ( V_27 ) -> V_9 ) ;
if ( F_44 ( V_25 ) )
goto V_87;
if ( F_70 ( V_27 , V_27 -> V_5 - V_88 - 2 , V_112 , 2 ) )
F_71 () ;
V_25 = - V_115 ;
V_113 = V_112 [ 0 ] ;
if ( V_113 + 2 + V_88 >= V_110 )
goto V_87;
V_108 = F_72 ( V_27 ) ;
V_111 = V_108 -> V_111 * 4 ;
if ( V_14 -> V_57 ) {
struct V_56 * V_57 = V_14 -> V_57 ;
struct V_51 * V_52 = ( void * ) ( F_73 ( V_27 ) + V_111 ) ;
if ( V_108 -> V_116 != V_14 -> V_18 . V_116 . V_117 ||
V_52 -> V_61 != V_57 -> V_59 ) {
T_7 V_118 ;
V_118 . V_117 = V_108 -> V_116 ;
F_74 ( V_14 , & V_118 , V_52 -> V_61 ) ;
}
if ( V_14 -> V_18 . V_119 == V_120 )
V_27 -> V_121 = V_122 ;
}
F_75 ( V_27 , V_27 -> V_5 - V_88 - V_113 - 2 ) ;
F_76 ( V_27 , V_109 ) ;
if ( V_14 -> V_18 . V_119 == V_123 )
F_77 ( V_27 ) ;
else
F_78 ( V_27 , - V_111 ) ;
V_25 = V_112 [ 1 ] ;
if ( V_25 == V_124 )
V_25 = - V_115 ;
V_87:
return V_25 ;
}
static void F_79 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_80 ( V_27 , F_68 ( V_27 , V_25 ) ) ;
}
static void F_81 ( struct V_26 * V_27 )
{
F_24 ( V_27 , 0 ) ;
F_76 ( V_27 , 4 ) ;
}
static void F_82 ( struct V_26 * V_27 , T_2 * V_33 )
{
struct V_13 * V_14 = F_69 ( V_27 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_27 -> V_16 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
V_32 = F_66 ( V_27 , 4 ) ;
* V_33 = V_32 -> V_35 ;
V_32 -> V_35 = V_32 -> V_34 ;
V_32 -> V_34 = F_28 ( V_27 ) -> V_39 . V_125 . V_40 ;
}
}
static void F_83 ( struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_24 -> V_16 ;
F_81 ( V_27 ) ;
F_79 ( V_24 , V_25 ) ;
}
static int F_84 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_6 * V_12 ;
struct V_26 * V_71 ;
int V_89 = F_2 ( V_2 ) ;
int V_110 = V_27 -> V_5 - sizeof( * V_32 ) - V_89 ;
int V_3 ;
int V_90 ;
int V_126 ;
T_2 * V_33 ;
void * V_9 ;
T_1 * V_11 ;
struct V_7 * V_17 ;
int V_25 = - V_115 ;
if ( ! F_85 ( V_27 , sizeof( * V_32 ) + V_89 ) )
goto V_87;
if ( V_110 <= 0 )
goto V_87;
V_90 = sizeof( * V_32 ) ;
V_126 = 0 ;
if ( V_14 -> V_18 . V_19 & V_20 ) {
V_126 += sizeof( T_2 ) ;
V_90 += V_126 ;
}
if ( ! F_39 ( V_27 ) ) {
if ( ! F_86 ( V_27 ) ) {
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
V_9 = F_1 ( V_2 , V_3 , V_126 ) ;
if ( ! V_9 )
goto V_87;
F_21 ( V_27 ) -> V_9 = V_9 ;
V_33 = F_9 ( V_9 ) ;
V_11 = F_11 ( V_2 , V_9 , V_126 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_17 = F_14 ( V_2 , V_12 ) ;
F_82 ( V_27 , V_33 ) ;
F_55 ( V_17 , V_3 ) ;
V_25 = F_56 ( V_27 , V_17 , 0 , V_27 -> V_5 ) ;
if ( F_44 ( V_25 < 0 ) ) {
F_22 ( V_9 ) ;
goto V_87;
}
V_27 -> V_121 = V_127 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_57 ( V_12 , 0 , F_83 , V_27 ) ;
else
F_57 ( V_12 , 0 , F_79 , V_27 ) ;
F_58 ( V_12 , V_17 , V_17 , V_110 + V_89 , V_11 ) ;
F_59 ( V_12 , V_90 ) ;
V_25 = F_87 ( V_12 ) ;
if ( V_25 == - V_96 )
goto V_87;
if ( ( V_14 -> V_18 . V_19 & V_20 ) )
F_81 ( V_27 ) ;
V_25 = F_68 ( V_27 , V_25 ) ;
V_87:
return V_25 ;
}
static T_6 F_63 ( struct V_13 * V_14 , int V_128 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
T_6 V_99 = F_5 ( F_64 ( V_2 ) , 4 ) ;
unsigned int V_129 ;
switch ( V_14 -> V_18 . V_119 ) {
case V_120 :
case V_130 :
V_129 = sizeof( struct V_107 ) ;
break;
case V_123 :
V_129 = 0 ;
break;
default:
F_71 () ;
}
return ( ( V_128 - V_14 -> V_18 . V_131 - F_54 ( V_2 ) -
V_129 ) & ~ ( V_99 - 1 ) ) + V_129 - 2 ;
}
static int F_88 ( struct V_26 * V_27 , T_6 V_132 )
{
struct V_133 * V_133 = F_89 ( V_27 -> V_134 ) ;
const struct V_107 * V_108 = ( const struct V_107 * ) V_27 -> V_16 ;
struct V_31 * V_32 = (struct V_31 * ) ( V_27 -> V_16 + ( V_108 -> V_111 << 2 ) ) ;
struct V_13 * V_14 ;
switch ( F_90 ( V_27 ) -> type ) {
case V_135 :
if ( F_90 ( V_27 ) -> V_136 != V_137 )
return 0 ;
case V_138 :
break;
default:
return 0 ;
}
V_14 = F_91 ( V_133 , V_27 -> V_139 , ( const T_7 * ) & V_108 -> V_140 ,
V_32 -> V_35 , V_100 , V_141 ) ;
if ( ! V_14 )
return 0 ;
if ( F_90 ( V_27 ) -> type == V_135 )
F_92 ( V_27 , V_133 , V_132 , 0 , 0 , V_100 , 0 ) ;
else
F_93 ( V_27 , V_133 , 0 , 0 , V_100 , 0 ) ;
F_94 ( V_14 ) ;
return 0 ;
}
static void F_95 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
if ( ! V_2 )
return;
F_96 ( V_2 ) ;
}
static int F_97 ( struct V_13 * V_14 )
{
char V_142 [ V_143 ] ;
struct V_1 * V_2 ;
int V_25 ;
T_6 V_144 = 0 ;
V_25 = - V_145 ;
if ( snprintf ( V_142 , V_143 , L_1 ,
V_14 -> V_146 , V_14 -> V_2 -> V_147 ) >= V_143 )
goto error;
if ( V_14 -> V_148 . V_149 )
V_144 |= V_150 ;
V_2 = F_98 ( V_142 , 0 , V_144 ) ;
V_25 = F_99 ( V_2 ) ;
if ( F_100 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_25 = F_101 ( V_2 , V_14 -> V_2 -> V_151 ,
( V_14 -> V_2 -> V_152 + 7 ) / 8 ) ;
if ( V_25 )
goto error;
V_25 = F_102 ( V_2 , V_14 -> V_2 -> V_153 / 8 ) ;
if ( V_25 )
goto error;
error:
return V_25 ;
}
static int F_103 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_154 * V_155 ;
struct V_156 * V_157 ;
char * V_158 ;
char * V_159 ;
char V_160 [ V_143 ] ;
unsigned int V_161 ;
int V_25 ;
T_6 V_144 = 0 ;
V_25 = - V_115 ;
if ( ! V_14 -> V_162 )
goto error;
V_25 = - V_145 ;
if ( ( V_14 -> V_18 . V_19 & V_20 ) ) {
if ( snprintf ( V_160 , V_143 ,
L_2 ,
V_14 -> V_146 ? : L_3 , V_14 -> V_146 ? L_4 : L_3 ,
V_14 -> V_163 ? V_14 -> V_163 -> V_147 : L_5 ,
V_14 -> V_162 -> V_147 ,
V_14 -> V_146 ? L_6 : L_3 ) >= V_143 )
goto error;
} else {
if ( snprintf ( V_160 , V_143 ,
L_7 ,
V_14 -> V_146 ? : L_3 , V_14 -> V_146 ? L_4 : L_3 ,
V_14 -> V_163 ? V_14 -> V_163 -> V_147 : L_5 ,
V_14 -> V_162 -> V_147 ,
V_14 -> V_146 ? L_6 : L_3 ) >= V_143 )
goto error;
}
if ( V_14 -> V_148 . V_149 )
V_144 |= V_150 ;
V_2 = F_98 ( V_160 , 0 , V_144 ) ;
V_25 = F_99 ( V_2 ) ;
if ( F_100 ( V_2 ) )
goto error;
V_14 -> V_16 = V_2 ;
V_161 = ( V_14 -> V_163 ? ( V_14 -> V_163 -> V_152 + 7 ) / 8 : 0 ) +
( V_14 -> V_162 -> V_152 + 7 ) / 8 + F_104 ( sizeof( * V_155 ) ) ;
V_25 = - V_92 ;
V_158 = F_8 ( V_161 , V_164 ) ;
if ( ! V_158 )
goto error;
V_159 = V_158 ;
V_157 = ( void * ) V_159 ;
V_157 -> V_165 = V_166 ;
V_157 -> V_167 = F_105 ( sizeof( * V_155 ) ) ;
V_155 = F_106 ( V_157 ) ;
V_159 += F_104 ( sizeof( * V_155 ) ) ;
if ( V_14 -> V_163 ) {
struct V_168 * V_169 ;
memcpy ( V_159 , V_14 -> V_163 -> V_151 , ( V_14 -> V_163 -> V_152 + 7 ) / 8 ) ;
V_159 += ( V_14 -> V_163 -> V_152 + 7 ) / 8 ;
V_169 = F_107 ( V_14 -> V_163 -> V_147 , 0 ) ;
F_108 ( ! V_169 ) ;
V_25 = - V_115 ;
if ( V_169 -> V_170 . V_171 . V_172 / 8 !=
F_54 ( V_2 ) ) {
F_109 ( L_8 ,
V_14 -> V_163 -> V_147 ,
F_54 ( V_2 ) ,
V_169 -> V_170 . V_171 . V_172 / 8 ) ;
goto V_173;
}
V_25 = F_102 (
V_2 , V_14 -> V_163 -> V_174 / 8 ) ;
if ( V_25 )
goto V_173;
}
V_155 -> V_175 = F_110 ( ( V_14 -> V_162 -> V_152 + 7 ) / 8 ) ;
memcpy ( V_159 , V_14 -> V_162 -> V_151 , ( V_14 -> V_162 -> V_152 + 7 ) / 8 ) ;
V_25 = F_101 ( V_2 , V_158 , V_161 ) ;
V_173:
F_22 ( V_158 ) ;
error:
return V_25 ;
}
static int F_111 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
T_6 V_176 ;
int V_25 ;
V_14 -> V_16 = NULL ;
if ( V_14 -> V_2 )
V_25 = F_97 ( V_14 ) ;
else
V_25 = F_103 ( V_14 ) ;
if ( V_25 )
goto error;
V_2 = V_14 -> V_16 ;
V_14 -> V_18 . V_131 = sizeof( struct V_31 ) +
F_2 ( V_2 ) ;
if ( V_14 -> V_18 . V_119 == V_123 )
V_14 -> V_18 . V_131 += sizeof( struct V_107 ) ;
else if ( V_14 -> V_18 . V_119 == V_130 && V_14 -> V_177 . V_178 != V_179 )
V_14 -> V_18 . V_131 += V_180 ;
if ( V_14 -> V_57 ) {
struct V_56 * V_57 = V_14 -> V_57 ;
switch ( V_57 -> V_50 ) {
default:
goto error;
case V_65 :
V_14 -> V_18 . V_131 += sizeof( struct V_51 ) ;
break;
case V_66 :
V_14 -> V_18 . V_131 += sizeof( struct V_51 ) + 2 * sizeof( T_6 ) ;
break;
}
}
V_176 = F_5 ( F_64 ( V_2 ) , 4 ) ;
V_14 -> V_18 . V_181 = V_176 + 1 + F_54 ( V_2 ) ;
error:
return V_25 ;
}
static int F_112 ( struct V_26 * V_27 , int V_25 )
{
return 0 ;
}
static int T_8 F_113 ( void )
{
if ( F_114 ( & V_182 , V_141 ) < 0 ) {
F_109 ( L_9 , V_183 ) ;
return - V_184 ;
}
if ( F_115 ( & V_185 , V_100 ) < 0 ) {
F_109 ( L_10 , V_183 ) ;
F_116 ( & V_182 , V_141 ) ;
return - V_184 ;
}
return 0 ;
}
static void T_9 F_117 ( void )
{
if ( F_118 ( & V_185 , V_100 ) < 0 )
F_109 ( L_11 , V_183 ) ;
if ( F_116 ( & V_182 , V_141 ) < 0 )
F_109 ( L_12 , V_183 ) ;
}
