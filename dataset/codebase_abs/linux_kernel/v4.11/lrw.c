static inline void F_1 ( void * V_1 , int V_2 )
{
F_2 ( V_2 ^ ( 0x80 -
#ifdef F_3
V_3
#else
V_4
#endif
) , V_1 ) ;
}
int F_4 ( struct V_5 * V_6 , const T_1 * V_7 )
{
T_2 V_8 = { 0 } ;
int V_9 ;
if ( V_6 -> V_10 )
F_5 ( V_6 -> V_10 ) ;
V_6 -> V_10 = F_6 ( ( T_2 * ) V_7 ) ;
if ( ! V_6 -> V_10 )
return - V_11 ;
for ( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) {
F_1 ( & V_8 , V_9 ) ;
V_6 -> V_12 [ V_9 ] = V_8 ;
F_7 ( & V_6 -> V_12 [ V_9 ] , V_6 -> V_10 ) ;
}
return 0 ;
}
void F_8 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 )
F_5 ( V_6 -> V_10 ) ;
}
static int F_9 ( struct V_13 * V_14 , const T_1 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_6 = F_10 ( V_14 ) ;
struct V_13 * V_18 = V_6 -> V_18 ;
int V_19 , V_20 = V_21 ;
const T_1 * V_7 = V_15 + V_16 - V_20 ;
F_11 ( V_18 , V_22 ) ;
F_12 ( V_18 , F_13 ( V_14 ) &
V_22 ) ;
V_19 = F_14 ( V_18 , V_15 , V_16 - V_20 ) ;
F_12 ( V_14 , F_13 ( V_18 ) &
V_23 ) ;
if ( V_19 )
return V_19 ;
return F_4 ( & V_6 -> V_10 , V_7 ) ;
}
static inline void F_15 ( T_2 * V_24 )
{
F_16 ( & V_24 -> V_1 , 1 ) ;
if ( ! V_24 -> V_1 )
F_16 ( & V_24 -> V_25 , 1 ) ;
}
static inline int F_17 ( T_2 * V_26 )
{
int V_27 ;
T_3 * V_28 = ( T_3 * ) V_26 ;
for ( V_28 += 3 , V_27 = 0 ; V_27 < 128 ; V_28 -- , V_27 += 32 ) {
T_4 V_29 = F_18 ( V_28 ) ;
if ( ! ~ V_29 )
continue;
return V_27 + F_19 ( V_29 ) ;
}
return V_27 ;
}
static int F_20 ( struct V_30 * V_31 )
{
struct V_32 * V_32 = F_21 ( V_31 ) ;
T_2 * V_33 = V_32 -> V_34 ? : V_32 -> V_33 ;
struct V_30 * V_35 ;
const int V_36 = V_21 ;
struct V_37 V_38 ;
struct V_39 * V_40 ;
unsigned V_41 ;
int V_19 ;
V_35 = & V_32 -> V_35 ;
V_19 = F_22 ( & V_38 , V_35 , false ) ;
while ( V_38 . V_42 ) {
unsigned int V_43 = V_38 . V_42 ;
T_2 * V_44 ;
V_44 = V_38 . V_45 . V_46 . V_47 ;
do {
F_23 ( V_44 , V_33 ++ , V_44 ) ;
V_44 ++ ;
} while ( ( V_43 -= V_36 ) >= V_36 );
V_19 = F_24 ( & V_38 , V_43 ) ;
}
V_32 -> V_48 -= V_35 -> V_49 ;
if ( V_19 || ! V_32 -> V_48 )
goto V_50;
V_32 -> V_45 = V_32 -> V_51 ;
F_25 ( & V_38 . V_50 , 0 , 1 ) ;
V_40 = V_38 . V_50 . V_40 ;
V_41 = V_38 . V_50 . V_41 ;
if ( V_32 -> V_45 != V_40 ) {
V_32 -> V_45 [ 0 ] = * V_40 ;
F_26 ( V_32 -> V_45 ) ;
F_27 ( V_32 -> V_45 , F_28 ( V_40 ) , 0 , 2 ) ;
}
V_32 -> V_45 [ 0 ] . V_52 -= V_41 - V_40 -> V_41 ;
V_32 -> V_45 [ 0 ] . V_41 = V_41 ;
V_50:
return V_19 ;
}
static int F_29 ( struct V_30 * V_31 )
{
struct V_13 * V_53 = F_30 ( V_31 ) ;
struct V_32 * V_32 = F_21 ( V_31 ) ;
struct V_17 * V_6 = F_10 ( V_53 ) ;
T_2 * V_33 = V_32 -> V_34 ? : V_32 -> V_33 ;
struct V_30 * V_35 ;
const int V_36 = V_21 ;
struct V_37 V_38 ;
struct V_39 * V_40 ;
unsigned V_49 ;
unsigned V_41 ;
T_2 * V_24 ;
bool V_54 ;
int V_19 ;
V_35 = & V_32 -> V_35 ;
F_31 ( V_35 , V_53 ) ;
V_49 = V_35 -> V_49 ;
V_54 = V_32 -> V_48 > V_49 ;
if ( ! V_54 )
V_49 = V_32 -> V_48 ;
F_32 ( V_35 , V_32 -> V_55 , V_32 -> V_45 ,
V_49 , V_31 -> V_24 ) ;
V_19 = F_22 ( & V_38 , V_35 , false ) ;
V_24 = V_38 . V_24 ;
while ( V_38 . V_42 ) {
unsigned int V_43 = V_38 . V_42 ;
T_2 * V_56 ;
T_2 * V_44 ;
V_56 = V_38 . V_55 . V_46 . V_47 ;
V_44 = V_38 . V_45 . V_46 . V_47 ;
do {
* V_33 ++ = V_32 -> V_57 ;
F_23 ( V_44 ++ , & V_32 -> V_57 , V_56 ++ ) ;
F_23 ( & V_32 -> V_57 , & V_32 -> V_57 ,
& V_6 -> V_10 . V_12 [ F_17 ( V_24 ) ] ) ;
F_15 ( V_24 ) ;
} while ( ( V_43 -= V_36 ) >= V_36 );
V_19 = F_24 ( & V_38 , V_43 ) ;
}
F_31 ( V_35 , V_6 -> V_18 ) ;
F_32 ( V_35 , V_32 -> V_45 , V_32 -> V_45 ,
V_49 , NULL ) ;
if ( V_19 || ! V_54 )
goto V_50;
V_32 -> V_55 = V_32 -> V_58 ;
F_25 ( & V_38 . V_59 , 0 , 1 ) ;
V_40 = V_38 . V_59 . V_40 ;
V_41 = V_38 . V_59 . V_41 ;
if ( V_32 -> V_55 != V_40 ) {
V_32 -> V_55 [ 0 ] = * V_40 ;
F_26 ( V_32 -> V_55 ) ;
F_27 ( V_32 -> V_55 , F_28 ( V_40 ) , 0 , 2 ) ;
}
V_32 -> V_55 [ 0 ] . V_52 -= V_41 - V_40 -> V_41 ;
V_32 -> V_55 [ 0 ] . V_41 = V_41 ;
V_50:
return V_19 ;
}
static int F_33 ( struct V_30 * V_31 , T_5 V_60 )
{
struct V_17 * V_6 = F_10 ( F_30 ( V_31 ) ) ;
struct V_32 * V_32 = F_21 ( V_31 ) ;
struct V_30 * V_35 ;
T_6 V_61 ;
V_35 = & V_32 -> V_35 ;
F_34 ( V_35 , V_31 -> V_62 . V_63 , V_60 , V_31 ) ;
V_61 = V_31 -> V_62 . V_63 & V_64 ? V_65 :
V_66 ;
V_32 -> V_34 = NULL ;
V_35 -> V_49 = V_67 ;
if ( V_31 -> V_49 > V_67 ) {
unsigned int V_68 = F_35 ( V_31 -> V_49 , ( unsigned int ) V_69 ) ;
V_32 -> V_34 = F_36 ( V_68 , V_61 ) ;
if ( V_32 -> V_34 )
V_35 -> V_49 = V_68 ;
}
V_32 -> V_55 = V_31 -> V_55 ;
V_32 -> V_45 = V_31 -> V_45 ;
V_32 -> V_48 = V_31 -> V_49 ;
memcpy ( & V_32 -> V_57 , V_31 -> V_24 , sizeof( V_32 -> V_57 ) ) ;
F_7 ( & V_32 -> V_57 , V_6 -> V_10 . V_10 ) ;
return 0 ;
}
static void F_37 ( struct V_30 * V_31 )
{
struct V_32 * V_32 = F_21 ( V_31 ) ;
V_32 -> V_48 = 0 ;
if ( V_32 -> V_34 )
F_38 ( V_32 -> V_34 ) ;
}
static int F_39 ( struct V_30 * V_31 , int V_19 )
{
struct V_32 * V_32 = F_21 ( V_31 ) ;
struct V_30 * V_35 ;
V_35 = & V_32 -> V_35 ;
while ( ! V_19 && V_32 -> V_48 ) {
V_19 = F_29 ( V_31 ) ? :
F_40 ( V_35 ) ? :
F_20 ( V_31 ) ;
if ( V_19 == - V_70 ||
( V_19 == - V_71 &&
V_31 -> V_62 . V_63 & V_72 ) )
return V_19 ;
}
F_37 ( V_31 ) ;
return V_19 ;
}
static void F_41 ( struct V_73 * V_74 , int V_19 )
{
struct V_30 * V_31 = V_74 -> V_75 ;
struct V_30 * V_35 ;
struct V_32 * V_32 ;
V_32 = F_21 ( V_31 ) ;
if ( V_19 == - V_70 ) {
if ( V_32 -> V_48 != V_31 -> V_49 )
return;
goto V_50;
}
V_35 = & V_32 -> V_35 ;
V_35 -> V_62 . V_63 &= V_72 ;
V_19 = F_39 ( V_31 , V_19 ? : F_20 ( V_31 ) ) ;
if ( V_32 -> V_48 )
return;
V_50:
F_42 ( V_31 , V_19 ) ;
}
static int F_43 ( struct V_30 * V_31 )
{
return F_39 ( V_31 , F_33 ( V_31 , F_41 ) ) ;
}
static int F_44 ( struct V_30 * V_31 , int V_19 )
{
struct V_32 * V_32 = F_21 ( V_31 ) ;
struct V_30 * V_35 ;
V_35 = & V_32 -> V_35 ;
while ( ! V_19 && V_32 -> V_48 ) {
V_19 = F_29 ( V_31 ) ? :
F_45 ( V_35 ) ? :
F_20 ( V_31 ) ;
if ( V_19 == - V_70 ||
( V_19 == - V_71 &&
V_31 -> V_62 . V_63 & V_72 ) )
return V_19 ;
}
F_37 ( V_31 ) ;
return V_19 ;
}
static void F_46 ( struct V_73 * V_74 , int V_19 )
{
struct V_30 * V_31 = V_74 -> V_75 ;
struct V_30 * V_35 ;
struct V_32 * V_32 ;
V_32 = F_21 ( V_31 ) ;
if ( V_19 == - V_70 ) {
if ( V_32 -> V_48 != V_31 -> V_49 )
return;
goto V_50;
}
V_35 = & V_32 -> V_35 ;
V_35 -> V_62 . V_63 &= V_72 ;
V_19 = F_44 ( V_31 , V_19 ? : F_20 ( V_31 ) ) ;
if ( V_32 -> V_48 )
return;
V_50:
F_42 ( V_31 , V_19 ) ;
}
static int F_47 ( struct V_30 * V_31 )
{
return F_44 ( V_31 , F_33 ( V_31 , F_46 ) ) ;
}
int F_48 ( struct V_76 * V_77 , struct V_39 * V_78 ,
struct V_39 * V_79 , unsigned int V_42 ,
struct V_80 * V_31 )
{
const unsigned int V_20 = V_21 ;
const unsigned int V_81 = V_31 -> V_82 / V_20 ;
struct V_5 * V_6 = V_31 -> V_83 ;
struct V_84 V_85 ;
unsigned int V_86 ;
T_2 * V_24 , * V_55 , * V_45 , * V_57 ;
T_2 * V_87 = V_31 -> V_88 ;
int V_19 , V_9 ;
F_49 ( V_81 < 1 ) ;
F_50 ( & V_85 , V_78 , V_79 , V_42 ) ;
V_19 = F_51 ( V_77 , & V_85 ) ;
V_42 = V_85 . V_42 ;
if ( ! V_42 )
return V_19 ;
V_86 = F_35 ( V_85 . V_42 / V_20 , V_81 ) ;
V_55 = ( T_2 * ) V_85 . V_55 . V_46 . V_47 ;
V_45 = ( T_2 * ) V_85 . V_45 . V_46 . V_47 ;
V_24 = ( T_2 * ) V_85 . V_24 ;
V_87 [ 0 ] = * V_24 ;
F_7 ( & V_87 [ 0 ] , V_6 -> V_10 ) ;
V_9 = 0 ;
goto V_89;
for (; ; ) {
do {
for ( V_9 = 0 ; V_9 < V_86 ; V_9 ++ ) {
F_23 ( & V_87 [ V_9 ] , V_57 ,
& V_6 -> V_12 [ F_17 ( V_24 ) ] ) ;
F_15 ( V_24 ) ;
V_89:
V_57 = & V_87 [ V_9 ] ;
F_23 ( V_45 + V_9 , V_57 , V_55 + V_9 ) ;
}
V_31 -> V_90 ( V_31 -> V_91 , ( T_1 * ) V_45 ,
V_86 * V_20 ) ;
for ( V_9 = 0 ; V_9 < V_86 ; V_9 ++ )
F_23 ( V_45 + V_9 , V_45 + V_9 , & V_87 [ V_9 ] ) ;
V_55 += V_86 ;
V_45 += V_86 ;
V_42 -= V_86 * V_20 ;
V_86 = F_35 ( V_42 / V_20 , V_81 ) ;
} while ( V_86 > 0 );
V_19 = F_52 ( V_77 , & V_85 , V_42 ) ;
V_42 = V_85 . V_42 ;
if ( ! V_42 )
break;
V_86 = F_35 ( V_42 / V_20 , V_81 ) ;
V_55 = ( T_2 * ) V_85 . V_55 . V_46 . V_47 ;
V_45 = ( T_2 * ) V_85 . V_45 . V_46 . V_47 ;
}
return V_19 ;
}
static int F_53 ( struct V_13 * V_53 )
{
struct V_92 * V_93 = F_54 ( V_53 ) ;
struct V_94 * V_95 = F_55 ( V_93 ) ;
struct V_17 * V_6 = F_10 ( V_53 ) ;
struct V_13 * V_96 ;
V_96 = F_56 ( V_95 ) ;
if ( F_57 ( V_96 ) )
return F_58 ( V_96 ) ;
V_6 -> V_18 = V_96 ;
F_59 ( V_53 , F_60 ( V_96 ) +
sizeof( struct V_32 ) ) ;
return 0 ;
}
static void F_61 ( struct V_13 * V_53 )
{
struct V_17 * V_6 = F_10 ( V_53 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_62 ( V_6 -> V_18 ) ;
}
static void free ( struct V_92 * V_93 )
{
F_63 ( F_55 ( V_93 ) ) ;
F_38 ( V_93 ) ;
}
static int F_64 ( struct V_97 * V_98 , struct V_99 * * V_100 )
{
struct V_94 * V_95 ;
struct V_92 * V_93 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
const char * V_105 ;
char V_106 [ V_107 ] ;
int V_19 ;
V_102 = F_65 ( V_100 ) ;
if ( F_57 ( V_102 ) )
return F_58 ( V_102 ) ;
if ( ( V_102 -> type ^ V_108 ) & V_102 -> V_109 )
return - V_110 ;
V_105 = F_66 ( V_100 [ 1 ] ) ;
if ( F_57 ( V_105 ) )
return F_58 ( V_105 ) ;
V_93 = F_67 ( sizeof( * V_93 ) + sizeof( * V_95 ) , V_65 ) ;
if ( ! V_93 )
return - V_11 ;
V_95 = F_55 ( V_93 ) ;
F_68 ( V_95 , F_69 ( V_93 ) ) ;
V_19 = F_70 ( V_95 , V_105 , 0 ,
F_71 ( V_102 -> type ,
V_102 -> V_109 ) ) ;
if ( V_19 == - V_111 ) {
V_19 = - V_112 ;
if ( snprintf ( V_106 , V_107 , L_1 ,
V_105 ) >= V_107 )
goto V_113;
V_19 = F_70 ( V_95 , V_106 , 0 ,
F_71 ( V_102 -> type ,
V_102 -> V_109 ) ) ;
}
if ( V_19 )
goto V_113;
V_104 = F_72 ( V_95 ) ;
V_19 = - V_110 ;
if ( V_104 -> V_62 . V_114 != V_21 )
goto V_115;
if ( F_73 ( V_104 ) )
goto V_115;
V_19 = F_74 ( F_69 ( V_93 ) , L_2 ,
& V_104 -> V_62 ) ;
if ( V_19 )
goto V_115;
V_19 = - V_110 ;
V_105 = V_104 -> V_62 . V_116 ;
if ( ! strncmp ( V_105 , L_3 , 4 ) ) {
unsigned V_117 ;
V_117 = F_75 ( V_106 , V_105 + 4 , sizeof( V_106 ) ) ;
if ( V_117 < 2 || V_117 >= sizeof( V_106 ) )
goto V_115;
if ( V_106 [ V_117 - 1 ] != ')' )
goto V_115;
V_106 [ V_117 - 1 ] = 0 ;
if ( snprintf ( V_93 -> V_104 . V_62 . V_116 , V_107 ,
L_4 , V_106 ) >= V_107 )
return - V_112 ;
}
V_93 -> V_104 . V_62 . V_118 = V_104 -> V_62 . V_118 & V_119 ;
V_93 -> V_104 . V_62 . V_120 = V_104 -> V_62 . V_120 ;
V_93 -> V_104 . V_62 . V_114 = V_21 ;
V_93 -> V_104 . V_62 . V_121 = V_104 -> V_62 . V_121 |
( F_76 ( V_122 ) - 1 ) ;
V_93 -> V_104 . V_123 = V_21 ;
V_93 -> V_104 . V_124 = F_77 ( V_104 ) +
V_21 ;
V_93 -> V_104 . V_125 = F_78 ( V_104 ) +
V_21 ;
V_93 -> V_104 . V_62 . V_126 = sizeof( struct V_17 ) ;
V_93 -> V_104 . V_127 = F_53 ;
V_93 -> V_104 . exit = F_61 ;
V_93 -> V_104 . F_9 = F_9 ;
V_93 -> V_104 . F_43 = F_43 ;
V_93 -> V_104 . F_47 = F_47 ;
V_93 -> free = free ;
V_19 = F_79 ( V_98 , V_93 ) ;
if ( V_19 )
goto V_115;
V_50:
return V_19 ;
V_115:
F_63 ( V_95 ) ;
V_113:
F_38 ( V_93 ) ;
goto V_50;
}
static int T_7 F_80 ( void )
{
return F_81 ( & V_128 ) ;
}
static void T_8 F_82 ( void )
{
F_83 ( & V_128 ) ;
}
