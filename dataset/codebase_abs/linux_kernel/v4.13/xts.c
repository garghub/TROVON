static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_10 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_10 )
return V_10 ;
V_4 /= 2 ;
V_9 = V_6 -> V_9 ;
F_4 ( V_9 , V_11 ) ;
F_5 ( V_9 , F_6 ( V_2 ) &
V_11 ) ;
V_10 = F_7 ( V_9 , V_3 + V_4 , V_4 ) ;
F_8 ( V_2 , F_9 ( V_9 ) &
V_12 ) ;
if ( V_10 )
return V_10 ;
V_7 = V_6 -> V_7 ;
F_10 ( V_7 , V_11 ) ;
F_8 ( V_7 , F_6 ( V_2 ) &
V_11 ) ;
V_10 = F_11 ( V_7 , V_3 , V_4 ) ;
F_8 ( V_2 , F_6 ( V_7 ) &
V_12 ) ;
return V_10 ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_15 * V_15 = F_13 ( V_14 ) ;
T_2 * V_16 = V_15 -> V_17 ? : V_15 -> V_16 ;
struct V_13 * V_18 ;
const int V_19 = V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
unsigned V_25 ;
int V_10 ;
V_18 = & V_15 -> V_18 ;
V_10 = F_14 ( & V_22 , V_18 , false ) ;
while ( V_22 . V_26 ) {
unsigned int V_27 = V_22 . V_26 ;
T_2 * V_28 ;
V_28 = V_22 . V_29 . V_30 . V_31 ;
do {
F_15 ( V_28 , V_16 ++ , V_28 ) ;
V_28 ++ ;
} while ( ( V_27 -= V_19 ) >= V_19 );
V_10 = F_16 ( & V_22 , V_27 ) ;
}
V_15 -> V_32 -= V_18 -> V_33 ;
if ( V_10 || ! V_15 -> V_32 )
goto V_34;
V_15 -> V_29 = V_15 -> V_35 ;
F_17 ( & V_22 . V_34 , 0 , 1 ) ;
V_24 = V_22 . V_34 . V_24 ;
V_25 = V_22 . V_34 . V_25 ;
if ( V_15 -> V_29 != V_24 ) {
V_15 -> V_29 [ 0 ] = * V_24 ;
F_18 ( V_15 -> V_29 ) ;
F_19 ( V_15 -> V_29 , F_20 ( V_24 ) , 0 , 2 ) ;
}
V_15 -> V_29 [ 0 ] . V_36 -= V_25 - V_24 -> V_25 ;
V_15 -> V_29 [ 0 ] . V_25 = V_25 ;
V_34:
return V_10 ;
}
static int F_21 ( struct V_13 * V_14 )
{
struct V_15 * V_15 = F_13 ( V_14 ) ;
T_2 * V_16 = V_15 -> V_17 ? : V_15 -> V_16 ;
struct V_13 * V_18 ;
const int V_19 = V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
unsigned V_33 ;
unsigned V_25 ;
bool V_37 ;
int V_10 ;
V_18 = & V_15 -> V_18 ;
V_33 = V_18 -> V_33 ;
V_37 = V_15 -> V_32 > V_33 ;
if ( ! V_37 )
V_33 = V_15 -> V_32 ;
F_22 ( V_18 , V_15 -> V_38 , V_15 -> V_29 ,
V_33 , NULL ) ;
V_10 = F_14 ( & V_22 , V_18 , false ) ;
while ( V_22 . V_26 ) {
unsigned int V_27 = V_22 . V_26 ;
T_2 * V_39 ;
T_2 * V_28 ;
V_39 = V_22 . V_38 . V_30 . V_31 ;
V_28 = V_22 . V_29 . V_30 . V_31 ;
do {
* V_16 ++ = V_15 -> V_40 ;
F_15 ( V_28 ++ , & V_15 -> V_40 , V_39 ++ ) ;
F_23 ( & V_15 -> V_40 , & V_15 -> V_40 ) ;
} while ( ( V_27 -= V_19 ) >= V_19 );
V_10 = F_16 ( & V_22 , V_27 ) ;
}
F_22 ( V_18 , V_15 -> V_29 , V_15 -> V_29 ,
V_33 , NULL ) ;
if ( V_10 || ! V_37 )
goto V_34;
V_15 -> V_38 = V_15 -> V_41 ;
F_17 ( & V_22 . V_42 , 0 , 1 ) ;
V_24 = V_22 . V_42 . V_24 ;
V_25 = V_22 . V_42 . V_25 ;
if ( V_15 -> V_38 != V_24 ) {
V_15 -> V_38 [ 0 ] = * V_24 ;
F_18 ( V_15 -> V_38 ) ;
F_19 ( V_15 -> V_38 , F_20 ( V_24 ) , 0 , 2 ) ;
}
V_15 -> V_38 [ 0 ] . V_36 -= V_25 - V_24 -> V_25 ;
V_15 -> V_38 [ 0 ] . V_25 = V_25 ;
V_34:
return V_10 ;
}
static int F_24 ( struct V_13 * V_14 , T_3 V_43 )
{
struct V_5 * V_6 = F_2 ( F_25 ( V_14 ) ) ;
struct V_15 * V_15 = F_13 ( V_14 ) ;
struct V_13 * V_18 ;
T_4 V_44 ;
V_18 = & V_15 -> V_18 ;
F_26 ( V_18 , V_6 -> V_7 ) ;
F_27 ( V_18 , V_14 -> V_45 . V_46 , V_43 , V_14 ) ;
V_44 = V_14 -> V_45 . V_46 & V_47 ? V_48 :
V_49 ;
V_15 -> V_17 = NULL ;
V_18 -> V_33 = V_50 ;
if ( V_14 -> V_33 > V_50 ) {
unsigned int V_51 = F_28 ( V_14 -> V_33 , ( unsigned int ) V_52 ) ;
V_15 -> V_17 = F_29 ( V_51 , V_44 ) ;
if ( V_15 -> V_17 )
V_18 -> V_33 = V_51 ;
}
V_15 -> V_38 = V_14 -> V_38 ;
V_15 -> V_29 = V_14 -> V_29 ;
V_15 -> V_32 = V_14 -> V_33 ;
F_30 ( V_6 -> V_9 , ( T_1 * ) & V_15 -> V_40 , V_14 -> V_53 ) ;
return 0 ;
}
static void F_31 ( struct V_13 * V_14 )
{
struct V_15 * V_15 = F_13 ( V_14 ) ;
V_15 -> V_32 = 0 ;
if ( V_15 -> V_17 )
F_32 ( V_15 -> V_17 ) ;
}
static int F_33 ( struct V_13 * V_14 , int V_10 )
{
struct V_15 * V_15 = F_13 ( V_14 ) ;
struct V_13 * V_18 ;
V_18 = & V_15 -> V_18 ;
while ( ! V_10 && V_15 -> V_32 ) {
V_10 = F_21 ( V_14 ) ? :
F_34 ( V_18 ) ? :
F_12 ( V_14 ) ;
if ( V_10 == - V_54 ||
( V_10 == - V_55 &&
V_14 -> V_45 . V_46 & V_56 ) )
return V_10 ;
}
F_31 ( V_14 ) ;
return V_10 ;
}
static void F_35 ( struct V_57 * V_58 , int V_10 )
{
struct V_13 * V_14 = V_58 -> V_59 ;
struct V_13 * V_18 ;
struct V_15 * V_15 ;
V_15 = F_13 ( V_14 ) ;
if ( V_10 == - V_54 ) {
if ( V_15 -> V_32 != V_14 -> V_33 )
return;
goto V_34;
}
V_18 = & V_15 -> V_18 ;
V_18 -> V_45 . V_46 &= V_56 ;
V_10 = F_33 ( V_14 , V_10 ? : F_12 ( V_14 ) ) ;
if ( V_15 -> V_32 )
return;
V_34:
F_36 ( V_14 , V_10 ) ;
}
static int F_37 ( struct V_13 * V_14 )
{
return F_33 ( V_14 , F_24 ( V_14 , F_35 ) ) ;
}
static int F_38 ( struct V_13 * V_14 , int V_10 )
{
struct V_15 * V_15 = F_13 ( V_14 ) ;
struct V_13 * V_18 ;
V_18 = & V_15 -> V_18 ;
while ( ! V_10 && V_15 -> V_32 ) {
V_10 = F_21 ( V_14 ) ? :
F_39 ( V_18 ) ? :
F_12 ( V_14 ) ;
if ( V_10 == - V_54 ||
( V_10 == - V_55 &&
V_14 -> V_45 . V_46 & V_56 ) )
return V_10 ;
}
F_31 ( V_14 ) ;
return V_10 ;
}
static void F_40 ( struct V_57 * V_58 , int V_10 )
{
struct V_13 * V_14 = V_58 -> V_59 ;
struct V_13 * V_18 ;
struct V_15 * V_15 ;
V_15 = F_13 ( V_14 ) ;
if ( V_10 == - V_54 ) {
if ( V_15 -> V_32 != V_14 -> V_33 )
return;
goto V_34;
}
V_18 = & V_15 -> V_18 ;
V_18 -> V_45 . V_46 &= V_56 ;
V_10 = F_38 ( V_14 , V_10 ? : F_12 ( V_14 ) ) ;
if ( V_15 -> V_32 )
return;
V_34:
F_36 ( V_14 , V_10 ) ;
}
static int F_41 ( struct V_13 * V_14 )
{
return F_38 ( V_14 , F_24 ( V_14 , F_40 ) ) ;
}
int F_42 ( struct V_60 * V_61 , struct V_23 * V_62 ,
struct V_23 * V_63 , unsigned int V_26 ,
struct V_64 * V_14 )
{
const unsigned int V_65 = V_20 ;
const unsigned int V_66 = V_14 -> V_67 / V_65 ;
struct V_68 V_69 ;
unsigned int V_70 ;
T_2 * V_38 , * V_29 , * V_40 ;
T_2 * V_71 = V_14 -> V_72 ;
int V_10 , V_73 ;
F_43 ( V_66 < 1 ) ;
F_44 ( & V_69 , V_62 , V_63 , V_26 ) ;
V_10 = F_45 ( V_61 , & V_69 ) ;
V_26 = V_69 . V_26 ;
if ( ! V_26 )
return V_10 ;
V_70 = F_28 ( V_26 / V_65 , V_66 ) ;
V_38 = ( T_2 * ) V_69 . V_38 . V_30 . V_31 ;
V_29 = ( T_2 * ) V_69 . V_29 . V_30 . V_31 ;
V_14 -> V_74 ( V_14 -> V_75 , ( T_1 * ) & V_71 [ 0 ] , V_69 . V_53 ) ;
V_73 = 0 ;
goto V_76;
for (; ; ) {
do {
for ( V_73 = 0 ; V_73 < V_70 ; V_73 ++ ) {
F_23 ( & V_71 [ V_73 ] , V_40 ) ;
V_76:
V_40 = & V_71 [ V_73 ] ;
F_15 ( V_29 + V_73 , V_40 , V_38 + V_73 ) ;
}
V_14 -> V_77 ( V_14 -> V_78 , ( T_1 * ) V_29 ,
V_70 * V_65 ) ;
for ( V_73 = 0 ; V_73 < V_70 ; V_73 ++ )
F_15 ( V_29 + V_73 , V_29 + V_73 , & V_71 [ V_73 ] ) ;
V_38 += V_70 ;
V_29 += V_70 ;
V_26 -= V_70 * V_65 ;
V_70 = F_28 ( V_26 / V_65 , V_66 ) ;
} while ( V_70 > 0 );
* ( T_2 * ) V_69 . V_53 = * V_40 ;
V_10 = F_46 ( V_61 , & V_69 , V_26 ) ;
V_26 = V_69 . V_26 ;
if ( ! V_26 )
break;
V_70 = F_28 ( V_26 / V_65 , V_66 ) ;
V_38 = ( T_2 * ) V_69 . V_38 . V_30 . V_31 ;
V_29 = ( T_2 * ) V_69 . V_29 . V_30 . V_31 ;
}
return V_10 ;
}
static int F_47 ( struct V_1 * V_79 )
{
struct V_80 * V_81 = F_48 ( V_79 ) ;
struct V_82 * V_83 = F_49 ( V_81 ) ;
struct V_5 * V_6 = F_2 ( V_79 ) ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_50 ( & V_83 -> V_84 ) ;
if ( F_51 ( V_7 ) )
return F_52 ( V_7 ) ;
V_6 -> V_7 = V_7 ;
V_9 = F_53 ( V_83 -> V_85 , 0 , 0 ) ;
if ( F_51 ( V_9 ) ) {
F_54 ( V_6 -> V_7 ) ;
return F_52 ( V_9 ) ;
}
V_6 -> V_9 = V_9 ;
F_55 ( V_79 , F_56 ( V_7 ) +
sizeof( struct V_15 ) ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
F_54 ( V_6 -> V_7 ) ;
F_58 ( V_6 -> V_9 ) ;
}
static void free ( struct V_80 * V_81 )
{
F_59 ( F_49 ( V_81 ) ) ;
F_60 ( V_81 ) ;
}
static int F_61 ( struct V_86 * V_87 , struct V_88 * * V_89 )
{
struct V_80 * V_81 ;
struct V_90 * V_91 ;
struct V_82 * V_6 ;
struct V_92 * V_93 ;
const char * V_94 ;
T_5 V_95 ;
int V_10 ;
V_91 = F_62 ( V_89 ) ;
if ( F_51 ( V_91 ) )
return F_52 ( V_91 ) ;
if ( ( V_91 -> type ^ V_96 ) & V_91 -> V_95 )
return - V_97 ;
V_94 = F_63 ( V_89 [ 1 ] ) ;
if ( F_51 ( V_94 ) )
return F_52 ( V_94 ) ;
V_81 = F_64 ( sizeof( * V_81 ) + sizeof( * V_6 ) , V_48 ) ;
if ( ! V_81 )
return - V_98 ;
V_6 = F_49 ( V_81 ) ;
F_65 ( & V_6 -> V_84 , F_66 ( V_81 ) ) ;
V_95 = F_67 ( V_91 -> type , V_91 -> V_95 ,
V_99 |
V_100 ) ;
V_10 = F_68 ( & V_6 -> V_84 , V_94 , 0 , V_95 ) ;
if ( V_10 == - V_101 ) {
V_10 = - V_102 ;
if ( snprintf ( V_6 -> V_85 , V_103 , L_1 ,
V_94 ) >= V_103 )
goto V_104;
V_10 = F_68 ( & V_6 -> V_84 , V_6 -> V_85 , 0 , V_95 ) ;
}
if ( V_10 )
goto V_104;
V_93 = F_69 ( & V_6 -> V_84 ) ;
V_10 = - V_97 ;
if ( V_93 -> V_45 . V_105 != V_20 )
goto V_106;
if ( F_70 ( V_93 ) )
goto V_106;
V_10 = F_71 ( F_66 ( V_81 ) , L_2 ,
& V_93 -> V_45 ) ;
if ( V_10 )
goto V_106;
V_10 = - V_97 ;
V_94 = V_93 -> V_45 . V_107 ;
if ( ! strncmp ( V_94 , L_3 , 4 ) ) {
unsigned V_108 ;
V_108 = F_72 ( V_6 -> V_85 , V_94 + 4 , sizeof( V_6 -> V_85 ) ) ;
if ( V_108 < 2 || V_108 >= sizeof( V_6 -> V_85 ) )
goto V_106;
if ( V_6 -> V_85 [ V_108 - 1 ] != ')' )
goto V_106;
V_6 -> V_85 [ V_108 - 1 ] = 0 ;
if ( snprintf ( V_81 -> V_93 . V_45 . V_107 , V_103 ,
L_4 , V_6 -> V_85 ) >= V_103 )
return - V_102 ;
} else
goto V_106;
V_81 -> V_93 . V_45 . V_109 = V_93 -> V_45 . V_109 & V_100 ;
V_81 -> V_93 . V_45 . V_110 = V_93 -> V_45 . V_110 ;
V_81 -> V_93 . V_45 . V_105 = V_20 ;
V_81 -> V_93 . V_45 . V_111 = V_93 -> V_45 . V_111 |
( F_73 ( V_112 ) - 1 ) ;
V_81 -> V_93 . V_113 = V_20 ;
V_81 -> V_93 . V_114 = F_74 ( V_93 ) * 2 ;
V_81 -> V_93 . V_115 = F_75 ( V_93 ) * 2 ;
V_81 -> V_93 . V_45 . V_116 = sizeof( struct V_5 ) ;
V_81 -> V_93 . V_117 = F_47 ;
V_81 -> V_93 . exit = F_57 ;
V_81 -> V_93 . F_1 = F_1 ;
V_81 -> V_93 . F_37 = F_37 ;
V_81 -> V_93 . F_41 = F_41 ;
V_81 -> free = free ;
V_10 = F_76 ( V_87 , V_81 ) ;
if ( V_10 )
goto V_106;
V_34:
return V_10 ;
V_106:
F_59 ( & V_6 -> V_84 ) ;
V_104:
F_60 ( V_81 ) ;
goto V_34;
}
static int T_6 F_77 ( void )
{
return F_78 ( & V_118 ) ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_118 ) ;
}
