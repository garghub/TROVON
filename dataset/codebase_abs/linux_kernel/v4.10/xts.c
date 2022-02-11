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
V_18 -> V_33 = F_28 ( V_14 -> V_33 , ( unsigned ) V_51 ) ;
V_15 -> V_17 = F_29 ( V_18 -> V_33 , V_44 ) ;
}
V_15 -> V_38 = V_14 -> V_38 ;
V_15 -> V_29 = V_14 -> V_29 ;
V_15 -> V_32 = V_14 -> V_33 ;
F_30 ( V_6 -> V_9 , ( T_1 * ) & V_15 -> V_40 , V_14 -> V_52 ) ;
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
if ( V_10 == - V_53 ||
( V_10 == - V_54 &&
V_14 -> V_45 . V_46 & V_55 ) )
return V_10 ;
}
F_31 ( V_14 ) ;
return V_10 ;
}
static void F_35 ( struct V_56 * V_57 , int V_10 )
{
struct V_13 * V_14 = V_57 -> V_58 ;
struct V_13 * V_18 ;
struct V_15 * V_15 ;
V_15 = F_13 ( V_14 ) ;
V_18 = & V_15 -> V_18 ;
V_18 -> V_45 . V_46 &= V_55 ;
V_10 = F_33 ( V_14 , V_10 ? : F_12 ( V_14 ) ) ;
if ( V_15 -> V_32 )
return;
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
if ( V_10 == - V_53 ||
( V_10 == - V_54 &&
V_14 -> V_45 . V_46 & V_55 ) )
return V_10 ;
}
F_31 ( V_14 ) ;
return V_10 ;
}
static void F_40 ( struct V_56 * V_57 , int V_10 )
{
struct V_13 * V_14 = V_57 -> V_58 ;
struct V_13 * V_18 ;
struct V_15 * V_15 ;
V_15 = F_13 ( V_14 ) ;
V_18 = & V_15 -> V_18 ;
V_18 -> V_45 . V_46 &= V_55 ;
V_10 = F_38 ( V_14 , V_10 ? : F_12 ( V_14 ) ) ;
if ( V_15 -> V_32 )
return;
F_36 ( V_14 , V_10 ) ;
}
static int F_41 ( struct V_13 * V_14 )
{
return F_38 ( V_14 , F_24 ( V_14 , F_40 ) ) ;
}
int F_42 ( struct V_59 * V_60 , struct V_23 * V_61 ,
struct V_23 * V_62 , unsigned int V_26 ,
struct V_63 * V_14 )
{
const unsigned int V_64 = V_20 ;
const unsigned int V_65 = V_14 -> V_66 / V_64 ;
struct V_67 V_68 ;
unsigned int V_69 ;
T_2 * V_38 , * V_29 , * V_40 ;
T_2 * V_70 = V_14 -> V_71 ;
int V_10 , V_72 ;
F_43 ( V_65 < 1 ) ;
F_44 ( & V_68 , V_61 , V_62 , V_26 ) ;
V_10 = F_45 ( V_60 , & V_68 ) ;
V_26 = V_68 . V_26 ;
if ( ! V_26 )
return V_10 ;
V_69 = F_28 ( V_26 / V_64 , V_65 ) ;
V_38 = ( T_2 * ) V_68 . V_38 . V_30 . V_31 ;
V_29 = ( T_2 * ) V_68 . V_29 . V_30 . V_31 ;
V_14 -> V_73 ( V_14 -> V_74 , ( T_1 * ) & V_70 [ 0 ] , V_68 . V_52 ) ;
V_72 = 0 ;
goto V_75;
for (; ; ) {
do {
for ( V_72 = 0 ; V_72 < V_69 ; V_72 ++ ) {
F_23 ( & V_70 [ V_72 ] , V_40 ) ;
V_75:
V_40 = & V_70 [ V_72 ] ;
F_15 ( V_29 + V_72 , V_40 , V_38 + V_72 ) ;
}
V_14 -> V_76 ( V_14 -> V_77 , ( T_1 * ) V_29 ,
V_69 * V_64 ) ;
for ( V_72 = 0 ; V_72 < V_69 ; V_72 ++ )
F_15 ( V_29 + V_72 , V_29 + V_72 , & V_70 [ V_72 ] ) ;
V_38 += V_69 ;
V_29 += V_69 ;
V_26 -= V_69 * V_64 ;
V_69 = F_28 ( V_26 / V_64 , V_65 ) ;
} while ( V_69 > 0 );
* ( T_2 * ) V_68 . V_52 = * V_40 ;
V_10 = F_46 ( V_60 , & V_68 , V_26 ) ;
V_26 = V_68 . V_26 ;
if ( ! V_26 )
break;
V_69 = F_28 ( V_26 / V_64 , V_65 ) ;
V_38 = ( T_2 * ) V_68 . V_38 . V_30 . V_31 ;
V_29 = ( T_2 * ) V_68 . V_29 . V_30 . V_31 ;
}
return V_10 ;
}
static int F_47 ( struct V_1 * V_78 )
{
struct V_79 * V_80 = F_48 ( V_78 ) ;
struct V_81 * V_82 = F_49 ( V_80 ) ;
struct V_5 * V_6 = F_2 ( V_78 ) ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_50 ( & V_82 -> V_83 ) ;
if ( F_51 ( V_7 ) )
return F_52 ( V_7 ) ;
V_6 -> V_7 = V_7 ;
V_9 = F_53 ( V_82 -> V_84 , 0 , 0 ) ;
if ( F_51 ( V_9 ) ) {
F_54 ( V_6 -> V_7 ) ;
return F_52 ( V_9 ) ;
}
V_6 -> V_9 = V_9 ;
F_55 ( V_78 , F_56 ( V_7 ) +
sizeof( struct V_15 ) ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_78 ) ;
F_54 ( V_6 -> V_7 ) ;
F_58 ( V_6 -> V_9 ) ;
}
static void free ( struct V_79 * V_80 )
{
F_59 ( F_49 ( V_80 ) ) ;
F_60 ( V_80 ) ;
}
static int F_61 ( struct V_85 * V_86 , struct V_87 * * V_88 )
{
struct V_79 * V_80 ;
struct V_89 * V_90 ;
struct V_81 * V_6 ;
struct V_91 * V_92 ;
const char * V_93 ;
int V_10 ;
V_90 = F_62 ( V_88 ) ;
if ( F_51 ( V_90 ) )
return F_52 ( V_90 ) ;
if ( ( V_90 -> type ^ V_94 ) & V_90 -> V_95 )
return - V_96 ;
V_93 = F_63 ( V_88 [ 1 ] ) ;
if ( F_51 ( V_93 ) )
return F_52 ( V_93 ) ;
V_80 = F_64 ( sizeof( * V_80 ) + sizeof( * V_6 ) , V_48 ) ;
if ( ! V_80 )
return - V_97 ;
V_6 = F_49 ( V_80 ) ;
F_65 ( & V_6 -> V_83 , F_66 ( V_80 ) ) ;
V_10 = F_67 ( & V_6 -> V_83 , V_93 , 0 ,
F_68 ( V_90 -> type ,
V_90 -> V_95 ) ) ;
if ( V_10 == - V_98 ) {
V_10 = - V_99 ;
if ( snprintf ( V_6 -> V_84 , V_100 , L_1 ,
V_93 ) >= V_100 )
goto V_101;
V_10 = F_67 ( & V_6 -> V_83 , V_6 -> V_84 , 0 ,
F_68 ( V_90 -> type ,
V_90 -> V_95 ) ) ;
}
if ( V_10 )
goto V_101;
V_92 = F_69 ( & V_6 -> V_83 ) ;
V_10 = - V_96 ;
if ( V_92 -> V_45 . V_102 != V_20 )
goto V_103;
if ( F_70 ( V_92 ) )
goto V_103;
V_10 = F_71 ( F_66 ( V_80 ) , L_2 ,
& V_92 -> V_45 ) ;
if ( V_10 )
goto V_103;
V_10 = - V_96 ;
V_93 = V_92 -> V_45 . V_104 ;
if ( ! strncmp ( V_93 , L_3 , 4 ) ) {
unsigned V_105 ;
V_105 = F_72 ( V_6 -> V_84 , V_93 + 4 , sizeof( V_6 -> V_84 ) ) ;
if ( V_105 < 2 || V_105 >= sizeof( V_6 -> V_84 ) )
goto V_103;
if ( V_6 -> V_84 [ V_105 - 1 ] != ')' )
goto V_103;
V_6 -> V_84 [ V_105 - 1 ] = 0 ;
if ( snprintf ( V_80 -> V_92 . V_45 . V_104 , V_100 ,
L_4 , V_6 -> V_84 ) >= V_100 )
return - V_99 ;
} else
goto V_103;
V_80 -> V_92 . V_45 . V_106 = V_92 -> V_45 . V_106 & V_107 ;
V_80 -> V_92 . V_45 . V_108 = V_92 -> V_45 . V_108 ;
V_80 -> V_92 . V_45 . V_102 = V_20 ;
V_80 -> V_92 . V_45 . V_109 = V_92 -> V_45 . V_109 |
( F_73 ( V_110 ) - 1 ) ;
V_80 -> V_92 . V_111 = V_20 ;
V_80 -> V_92 . V_112 = F_74 ( V_92 ) * 2 ;
V_80 -> V_92 . V_113 = F_75 ( V_92 ) * 2 ;
V_80 -> V_92 . V_45 . V_114 = sizeof( struct V_5 ) ;
V_80 -> V_92 . V_115 = F_47 ;
V_80 -> V_92 . exit = F_57 ;
V_80 -> V_92 . F_1 = F_1 ;
V_80 -> V_92 . F_37 = F_37 ;
V_80 -> V_92 . F_41 = F_41 ;
V_80 -> free = free ;
V_10 = F_76 ( V_86 , V_80 ) ;
if ( V_10 )
goto V_103;
V_34:
return V_10 ;
V_103:
F_59 ( & V_6 -> V_83 ) ;
V_101:
F_60 ( V_80 ) ;
goto V_34;
}
static int T_5 F_77 ( void )
{
return F_78 ( & V_116 ) ;
}
static void T_6 F_79 ( void )
{
F_80 ( & V_116 ) ;
}
