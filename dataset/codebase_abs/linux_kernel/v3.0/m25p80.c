static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
T_1 V_5 ;
T_2 V_6 = V_7 ;
T_2 V_8 ;
V_5 = F_4 ( V_4 -> V_9 , & V_6 , 1 , & V_8 , 1 ) ;
if ( V_5 < 0 ) {
F_5 ( & V_4 -> V_9 -> V_10 , L_1 ,
( int ) V_5 ) ;
return V_5 ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_4 , T_2 V_8 )
{
V_4 -> V_11 [ 0 ] = V_12 ;
V_4 -> V_11 [ 1 ] = V_8 ;
return F_7 ( V_4 -> V_9 , V_4 -> V_11 , 2 ) ;
}
static inline int F_8 ( struct V_1 * V_4 )
{
T_2 V_6 = V_13 ;
return F_4 ( V_4 -> V_9 , & V_6 , 1 , NULL , 0 ) ;
}
static inline int F_9 ( struct V_1 * V_4 )
{
T_2 V_6 = V_14 ;
return F_4 ( V_4 -> V_9 , & V_6 , 1 , NULL , 0 ) ;
}
static inline int F_10 ( struct V_1 * V_4 , T_3 V_15 , int V_16 )
{
switch ( F_11 ( V_15 ) ) {
case V_17 :
V_4 -> V_11 [ 0 ] = V_16 ? V_18 : V_19 ;
return F_7 ( V_4 -> V_9 , V_4 -> V_11 , 1 ) ;
default:
V_4 -> V_11 [ 0 ] = V_20 ;
V_4 -> V_11 [ 1 ] = V_16 << 7 ;
return F_7 ( V_4 -> V_9 , V_4 -> V_11 , 2 ) ;
}
}
static int F_12 ( struct V_1 * V_4 )
{
unsigned long V_21 ;
int V_22 ;
V_21 = V_23 + V_24 ;
do {
if ( ( V_22 = F_3 ( V_4 ) ) < 0 )
break;
else if ( ! ( V_22 & V_25 ) )
return 0 ;
F_13 () ;
} while ( ! F_14 ( V_23 , V_21 ) );
return 1 ;
}
static int F_15 ( struct V_1 * V_4 )
{
F_16 ( V_26 , L_2 ,
F_17 ( & V_4 -> V_9 -> V_10 ) , V_27 ,
( long long ) ( V_4 -> V_3 . V_28 >> 10 ) ) ;
if ( F_12 ( V_4 ) )
return 1 ;
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_29 ;
F_7 ( V_4 -> V_9 , V_4 -> V_11 , 1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_4 , unsigned int V_30 , T_2 * V_31 )
{
V_31 [ 1 ] = V_30 >> ( V_4 -> V_32 * 8 - 8 ) ;
V_31 [ 2 ] = V_30 >> ( V_4 -> V_32 * 8 - 16 ) ;
V_31 [ 3 ] = V_30 >> ( V_4 -> V_32 * 8 - 24 ) ;
V_31 [ 4 ] = V_30 >> ( V_4 -> V_32 * 8 - 32 ) ;
}
static int F_19 ( struct V_1 * V_4 )
{
return 1 + V_4 -> V_32 ;
}
static int F_20 ( struct V_1 * V_4 , T_3 V_33 )
{
F_16 ( V_26 , L_3 ,
F_17 ( & V_4 -> V_9 -> V_10 ) , V_27 ,
V_4 -> V_3 . V_34 / 1024 , V_33 ) ;
if ( F_12 ( V_4 ) )
return 1 ;
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_4 -> V_35 ;
F_18 ( V_4 , V_33 , V_4 -> V_11 ) ;
F_7 ( V_4 -> V_9 , V_4 -> V_11 , F_19 ( V_4 ) ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_30 , V_38 ;
T_4 V_39 ;
F_16 ( V_40 , L_4 ,
F_17 ( & V_4 -> V_9 -> V_10 ) , V_27 , L_5 ,
( long long ) V_37 -> V_30 , ( long long ) V_37 -> V_38 ) ;
if ( V_37 -> V_30 + V_37 -> V_38 > V_4 -> V_3 . V_28 )
return - V_41 ;
F_22 ( V_37 -> V_38 , V_3 -> V_34 , & V_39 ) ;
if ( V_39 )
return - V_41 ;
V_30 = V_37 -> V_30 ;
V_38 = V_37 -> V_38 ;
F_23 ( & V_4 -> V_42 ) ;
if ( V_38 == V_4 -> V_3 . V_28 ) {
if ( F_15 ( V_4 ) ) {
V_37 -> V_43 = V_44 ;
F_24 ( & V_4 -> V_42 ) ;
return - V_45 ;
}
} else {
while ( V_38 ) {
if ( F_20 ( V_4 , V_30 ) ) {
V_37 -> V_43 = V_44 ;
F_24 ( & V_4 -> V_42 ) ;
return - V_45 ;
}
V_30 += V_3 -> V_34 ;
V_38 -= V_3 -> V_34 ;
}
}
F_24 ( & V_4 -> V_42 ) ;
V_37 -> V_43 = V_46 ;
F_25 ( V_37 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , T_5 V_47 , T_6 V_38 ,
T_6 * V_48 , T_7 * V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_50 V_51 [ 2 ] ;
struct V_52 V_53 ;
F_16 ( V_40 , L_6 ,
F_17 ( & V_4 -> V_9 -> V_10 ) , V_27 , L_7 ,
( T_3 ) V_47 , V_38 ) ;
if ( ! V_38 )
return 0 ;
if ( V_47 + V_38 > V_4 -> V_3 . V_28 )
return - V_41 ;
F_27 ( & V_53 ) ;
memset ( V_51 , 0 , ( sizeof V_51 ) ) ;
V_51 [ 0 ] . V_54 = V_4 -> V_11 ;
V_51 [ 0 ] . V_38 = F_19 ( V_4 ) + V_55 ;
F_28 ( & V_51 [ 0 ] , & V_53 ) ;
V_51 [ 1 ] . V_56 = V_49 ;
V_51 [ 1 ] . V_38 = V_38 ;
F_28 ( & V_51 [ 1 ] , & V_53 ) ;
* V_48 = 0 ;
F_23 ( & V_4 -> V_42 ) ;
if ( F_12 ( V_4 ) ) {
F_24 ( & V_4 -> V_42 ) ;
return 1 ;
}
V_4 -> V_11 [ 0 ] = V_57 ;
F_18 ( V_4 , V_47 , V_4 -> V_11 ) ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
* V_48 = V_53 . V_58 - F_19 ( V_4 ) - V_55 ;
F_24 ( & V_4 -> V_42 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , T_5 V_59 , T_6 V_38 ,
T_6 * V_48 , const T_7 * V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_60 , V_61 ;
struct V_50 V_51 [ 2 ] ;
struct V_52 V_53 ;
F_16 ( V_40 , L_6 ,
F_17 ( & V_4 -> V_9 -> V_10 ) , V_27 , L_8 ,
( T_3 ) V_59 , V_38 ) ;
* V_48 = 0 ;
if ( ! V_38 )
return ( 0 ) ;
if ( V_59 + V_38 > V_4 -> V_3 . V_28 )
return - V_41 ;
F_27 ( & V_53 ) ;
memset ( V_51 , 0 , ( sizeof V_51 ) ) ;
V_51 [ 0 ] . V_54 = V_4 -> V_11 ;
V_51 [ 0 ] . V_38 = F_19 ( V_4 ) ;
F_28 ( & V_51 [ 0 ] , & V_53 ) ;
V_51 [ 1 ] . V_54 = V_49 ;
F_28 ( & V_51 [ 1 ] , & V_53 ) ;
F_23 ( & V_4 -> V_42 ) ;
if ( F_12 ( V_4 ) ) {
F_24 ( & V_4 -> V_42 ) ;
return 1 ;
}
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_62 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_60 = V_59 & ( V_4 -> V_61 - 1 ) ;
if ( V_60 + V_38 <= V_4 -> V_61 ) {
V_51 [ 1 ] . V_38 = V_38 ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
* V_48 = V_53 . V_58 - F_19 ( V_4 ) ;
} else {
T_3 V_63 ;
V_61 = V_4 -> V_61 - V_60 ;
V_51 [ 1 ] . V_38 = V_61 ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
* V_48 = V_53 . V_58 - F_19 ( V_4 ) ;
for ( V_63 = V_61 ; V_63 < V_38 ; V_63 += V_61 ) {
V_61 = V_38 - V_63 ;
if ( V_61 > V_4 -> V_61 )
V_61 = V_4 -> V_61 ;
F_18 ( V_4 , V_59 + V_63 , V_4 -> V_11 ) ;
V_51 [ 1 ] . V_54 = V_49 + V_63 ;
V_51 [ 1 ] . V_38 = V_61 ;
F_12 ( V_4 ) ;
F_8 ( V_4 ) ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
* V_48 += V_53 . V_58 - F_19 ( V_4 ) ;
}
}
F_24 ( & V_4 -> V_42 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , T_5 V_59 , T_6 V_38 ,
T_6 * V_48 , const T_7 * V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_50 V_51 [ 2 ] ;
struct V_52 V_53 ;
T_6 V_64 ;
int V_65 , V_66 ;
F_16 ( V_40 , L_6 ,
F_17 ( & V_4 -> V_9 -> V_10 ) , V_27 , L_8 ,
( T_3 ) V_59 , V_38 ) ;
* V_48 = 0 ;
if ( ! V_38 )
return 0 ;
if ( V_59 + V_38 > V_4 -> V_3 . V_28 )
return - V_41 ;
F_27 ( & V_53 ) ;
memset ( V_51 , 0 , ( sizeof V_51 ) ) ;
V_51 [ 0 ] . V_54 = V_4 -> V_11 ;
V_51 [ 0 ] . V_38 = F_19 ( V_4 ) ;
F_28 ( & V_51 [ 0 ] , & V_53 ) ;
V_51 [ 1 ] . V_54 = V_49 ;
F_28 ( & V_51 [ 1 ] , & V_53 ) ;
F_23 ( & V_4 -> V_42 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
F_8 ( V_4 ) ;
V_64 = V_59 % 2 ;
if ( V_64 ) {
V_4 -> V_11 [ 0 ] = V_68 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_51 [ 1 ] . V_38 = 1 ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
* V_48 += V_53 . V_58 - F_19 ( V_4 ) ;
}
V_59 += V_64 ;
V_4 -> V_11 [ 0 ] = V_69 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_65 = F_19 ( V_4 ) ;
for (; V_64 < V_38 - 1 ; V_64 += 2 ) {
V_51 [ 0 ] . V_38 = V_65 ;
V_51 [ 1 ] . V_38 = 2 ;
V_51 [ 1 ] . V_54 = V_49 + V_64 ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
* V_48 += V_53 . V_58 - V_65 ;
V_65 = 1 ;
V_59 += 2 ;
}
F_9 ( V_4 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
if ( V_64 != V_38 ) {
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_68 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_51 [ 0 ] . V_38 = F_19 ( V_4 ) ;
V_51 [ 1 ] . V_38 = 1 ;
V_51 [ 1 ] . V_54 = V_49 + V_64 ;
F_29 ( V_4 -> V_9 , & V_53 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
* V_48 += V_53 . V_58 - F_19 ( V_4 ) ;
F_9 ( V_4 ) ;
}
V_67:
F_24 ( & V_4 -> V_42 ) ;
return V_66 ;
}
static const struct V_70 * T_8 F_32 ( struct V_71 * V_9 )
{
int V_72 ;
T_2 V_6 = V_73 ;
T_2 V_74 [ 5 ] ;
T_3 V_75 ;
T_9 V_76 ;
struct V_77 * V_78 ;
V_72 = F_4 ( V_9 , & V_6 , 1 , V_74 , 5 ) ;
if ( V_72 < 0 ) {
F_16 ( V_79 , L_9 ,
F_17 ( & V_9 -> V_10 ) , V_72 ) ;
return F_33 ( V_72 ) ;
}
V_75 = V_74 [ 0 ] ;
V_75 = V_75 << 8 ;
V_75 |= V_74 [ 1 ] ;
V_75 = V_75 << 8 ;
V_75 |= V_74 [ 2 ] ;
V_76 = V_74 [ 3 ] << 8 | V_74 [ 4 ] ;
for ( V_72 = 0 ; V_72 < F_34 ( V_80 ) - 1 ; V_72 ++ ) {
V_78 = ( void * ) V_80 [ V_72 ] . V_81 ;
if ( V_78 -> V_15 == V_75 ) {
if ( V_78 -> V_82 != 0 && V_78 -> V_82 != V_76 )
continue;
return & V_80 [ V_72 ] ;
}
}
F_5 ( & V_9 -> V_10 , L_10 , V_75 ) ;
return F_33 ( - V_83 ) ;
}
static int T_8 F_35 ( struct V_71 * V_9 )
{
const struct V_70 * V_74 = F_36 ( V_9 ) ;
struct V_84 * V_85 ;
struct V_1 * V_4 ;
struct V_77 * V_78 ;
unsigned V_63 ;
struct V_86 * V_87 = NULL ;
int V_88 = 0 ;
V_85 = V_9 -> V_10 . V_89 ;
if ( V_85 && V_85 -> type ) {
const struct V_70 * V_90 ;
for ( V_63 = 0 ; V_63 < F_34 ( V_80 ) - 1 ; V_63 ++ ) {
V_90 = & V_80 [ V_63 ] ;
if ( strcmp ( V_85 -> type , V_90 -> V_91 ) )
continue;
break;
}
if ( V_63 < F_34 ( V_80 ) - 1 )
V_74 = V_90 ;
else
F_37 ( & V_9 -> V_10 , L_11 , V_85 -> type ) ;
}
V_78 = ( void * ) V_74 -> V_81 ;
if ( V_78 -> V_15 ) {
const struct V_70 * V_92 ;
V_92 = F_32 ( V_9 ) ;
if ( F_38 ( V_92 ) ) {
return F_39 ( V_92 ) ;
} else if ( V_92 != V_74 ) {
F_37 ( & V_9 -> V_10 , L_12 ,
V_92 -> V_91 , V_74 -> V_91 ) ;
V_74 = V_92 ;
V_78 = ( void * ) V_92 -> V_81 ;
}
}
V_4 = F_40 ( sizeof *V_4 , V_93 ) ;
if ( ! V_4 )
return - V_94 ;
V_4 -> V_11 = F_41 ( V_95 + V_55 , V_93 ) ;
if ( ! V_4 -> V_11 ) {
F_42 ( V_4 ) ;
return - V_94 ;
}
V_4 -> V_9 = V_9 ;
F_43 ( & V_4 -> V_42 ) ;
F_44 ( & V_9 -> V_10 , V_4 ) ;
if ( F_11 ( V_78 -> V_15 ) == V_96 ||
F_11 ( V_78 -> V_15 ) == V_97 ||
F_11 ( V_78 -> V_15 ) == V_98 ) {
F_8 ( V_4 ) ;
F_6 ( V_4 , 0 ) ;
}
if ( V_85 && V_85 -> V_91 )
V_4 -> V_3 . V_91 = V_85 -> V_91 ;
else
V_4 -> V_3 . V_91 = F_17 ( & V_9 -> V_10 ) ;
V_4 -> V_3 . type = V_99 ;
V_4 -> V_3 . V_100 = 1 ;
V_4 -> V_3 . V_101 = V_102 ;
V_4 -> V_3 . V_28 = V_78 -> V_103 * V_78 -> V_104 ;
V_4 -> V_3 . V_105 = F_21 ;
V_4 -> V_3 . V_106 = F_26 ;
if ( F_11 ( V_78 -> V_15 ) == V_98 )
V_4 -> V_3 . V_107 = F_31 ;
else
V_4 -> V_3 . V_107 = F_30 ;
if ( V_78 -> V_101 & V_108 ) {
V_4 -> V_35 = V_109 ;
V_4 -> V_3 . V_34 = 4096 ;
} else {
V_4 -> V_35 = V_110 ;
V_4 -> V_3 . V_34 = V_78 -> V_103 ;
}
if ( V_78 -> V_101 & V_111 )
V_4 -> V_3 . V_101 |= V_112 ;
V_4 -> V_3 . V_10 . V_113 = & V_9 -> V_10 ;
V_4 -> V_61 = V_78 -> V_61 ;
if ( V_78 -> V_32 )
V_4 -> V_32 = V_78 -> V_32 ;
else {
if ( V_4 -> V_3 . V_28 > 0x1000000 ) {
V_4 -> V_32 = 4 ;
F_10 ( V_4 , V_78 -> V_15 , 1 ) ;
} else
V_4 -> V_32 = 3 ;
}
F_45 ( & V_9 -> V_10 , L_13 , V_74 -> V_91 ,
( long long ) V_4 -> V_3 . V_28 >> 10 ) ;
F_16 ( V_40 ,
L_14
L_15 ,
V_4 -> V_3 . V_91 ,
( long long ) V_4 -> V_3 . V_28 , ( long long ) ( V_4 -> V_3 . V_28 >> 20 ) ,
V_4 -> V_3 . V_34 , V_4 -> V_3 . V_34 / 1024 ,
V_4 -> V_3 . V_114 ) ;
if ( V_4 -> V_3 . V_114 )
for ( V_63 = 0 ; V_63 < V_4 -> V_3 . V_114 ; V_63 ++ )
F_16 ( V_40 ,
L_16
L_17
L_18 ,
V_63 , ( long long ) V_4 -> V_3 . V_115 [ V_63 ] . V_33 ,
V_4 -> V_3 . V_115 [ V_63 ] . V_34 ,
V_4 -> V_3 . V_115 [ V_63 ] . V_34 / 1024 ,
V_4 -> V_3 . V_115 [ V_63 ] . V_116 ) ;
if ( F_46 () ) {
static const char * V_117 []
= { L_19 , NULL , } ;
V_88 = F_47 ( & V_4 -> V_3 ,
V_117 , & V_87 , 0 ) ;
}
if ( V_88 <= 0 && V_85 && V_85 -> V_87 ) {
V_87 = V_85 -> V_87 ;
V_88 = V_85 -> V_88 ;
}
#ifdef F_48
if ( V_88 <= 0 && V_9 -> V_10 . V_118 ) {
V_88 = F_49 ( & V_9 -> V_10 ,
V_9 -> V_10 . V_118 , & V_87 ) ;
}
#endif
if ( V_88 > 0 ) {
for ( V_63 = 0 ; V_63 < V_88 ; V_63 ++ ) {
F_16 ( V_40 , L_20
L_21
L_22 ,
V_63 , V_87 [ V_63 ] . V_91 ,
( long long ) V_87 [ V_63 ] . V_33 ,
( long long ) V_87 [ V_63 ] . V_28 ,
( long long ) ( V_87 [ V_63 ] . V_28 >> 10 ) ) ;
}
V_4 -> V_119 = 1 ;
}
return F_50 ( & V_4 -> V_3 , V_87 , V_88 ) == 1 ?
- V_83 : 0 ;
}
static int T_10 F_51 ( struct V_71 * V_9 )
{
struct V_1 * V_4 = F_52 ( & V_9 -> V_10 ) ;
int V_120 ;
V_120 = F_53 ( & V_4 -> V_3 ) ;
if ( V_120 == 0 ) {
F_42 ( V_4 -> V_11 ) ;
F_42 ( V_4 ) ;
}
return 0 ;
}
static int T_11 F_54 ( void )
{
return F_55 ( & V_121 ) ;
}
static void T_12 F_56 ( void )
{
F_57 ( & V_121 ) ;
}
