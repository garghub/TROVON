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
F_16 ( L_2 , F_17 ( & V_4 -> V_9 -> V_10 ) , V_26 ,
( long long ) ( V_4 -> V_3 . V_27 >> 10 ) ) ;
if ( F_12 ( V_4 ) )
return 1 ;
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_28 ;
F_7 ( V_4 -> V_9 , V_4 -> V_11 , 1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_4 , unsigned int V_29 , T_2 * V_30 )
{
V_30 [ 1 ] = V_29 >> ( V_4 -> V_31 * 8 - 8 ) ;
V_30 [ 2 ] = V_29 >> ( V_4 -> V_31 * 8 - 16 ) ;
V_30 [ 3 ] = V_29 >> ( V_4 -> V_31 * 8 - 24 ) ;
V_30 [ 4 ] = V_29 >> ( V_4 -> V_31 * 8 - 32 ) ;
}
static int F_19 ( struct V_1 * V_4 )
{
return 1 + V_4 -> V_31 ;
}
static int F_20 ( struct V_1 * V_4 , T_3 V_32 )
{
F_16 ( L_3 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , V_4 -> V_3 . V_33 / 1024 , V_32 ) ;
if ( F_12 ( V_4 ) )
return 1 ;
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_4 -> V_34 ;
F_18 ( V_4 , V_32 , V_4 -> V_11 ) ;
F_7 ( V_4 -> V_9 , V_4 -> V_11 , F_19 ( V_4 ) ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_29 , V_37 ;
T_4 V_38 ;
F_16 ( L_4 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( long long ) V_36 -> V_29 ,
( long long ) V_36 -> V_37 ) ;
F_22 ( V_36 -> V_37 , V_3 -> V_33 , & V_38 ) ;
if ( V_38 )
return - V_39 ;
V_29 = V_36 -> V_29 ;
V_37 = V_36 -> V_37 ;
F_23 ( & V_4 -> V_40 ) ;
if ( V_37 == V_4 -> V_3 . V_27 ) {
if ( F_15 ( V_4 ) ) {
V_36 -> V_41 = V_42 ;
F_24 ( & V_4 -> V_40 ) ;
return - V_43 ;
}
} else {
while ( V_37 ) {
if ( F_20 ( V_4 , V_29 ) ) {
V_36 -> V_41 = V_42 ;
F_24 ( & V_4 -> V_40 ) ;
return - V_43 ;
}
V_29 += V_3 -> V_33 ;
V_37 -= V_3 -> V_33 ;
}
}
F_24 ( & V_4 -> V_40 ) ;
V_36 -> V_41 = V_44 ;
F_25 ( V_36 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , T_5 V_45 , T_6 V_37 ,
T_6 * V_46 , T_7 * V_47 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_48 V_49 [ 2 ] ;
struct V_50 V_51 ;
F_16 ( L_5 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( T_3 ) V_45 , V_37 ) ;
F_27 ( & V_51 ) ;
memset ( V_49 , 0 , ( sizeof V_49 ) ) ;
V_49 [ 0 ] . V_52 = V_4 -> V_11 ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) + V_53 ;
F_28 ( & V_49 [ 0 ] , & V_51 ) ;
V_49 [ 1 ] . V_54 = V_47 ;
V_49 [ 1 ] . V_37 = V_37 ;
F_28 ( & V_49 [ 1 ] , & V_51 ) ;
F_23 ( & V_4 -> V_40 ) ;
if ( F_12 ( V_4 ) ) {
F_24 ( & V_4 -> V_40 ) ;
return 1 ;
}
V_4 -> V_11 [ 0 ] = V_55 ;
F_18 ( V_4 , V_45 , V_4 -> V_11 ) ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 = V_51 . V_56 - F_19 ( V_4 ) - V_53 ;
F_24 ( & V_4 -> V_40 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , T_5 V_57 , T_6 V_37 ,
T_6 * V_46 , const T_7 * V_47 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_58 , V_59 ;
struct V_48 V_49 [ 2 ] ;
struct V_50 V_51 ;
F_16 ( L_6 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( T_3 ) V_57 , V_37 ) ;
F_27 ( & V_51 ) ;
memset ( V_49 , 0 , ( sizeof V_49 ) ) ;
V_49 [ 0 ] . V_52 = V_4 -> V_11 ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) ;
F_28 ( & V_49 [ 0 ] , & V_51 ) ;
V_49 [ 1 ] . V_52 = V_47 ;
F_28 ( & V_49 [ 1 ] , & V_51 ) ;
F_23 ( & V_4 -> V_40 ) ;
if ( F_12 ( V_4 ) ) {
F_24 ( & V_4 -> V_40 ) ;
return 1 ;
}
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_60 ;
F_18 ( V_4 , V_57 , V_4 -> V_11 ) ;
V_58 = V_57 & ( V_4 -> V_59 - 1 ) ;
if ( V_58 + V_37 <= V_4 -> V_59 ) {
V_49 [ 1 ] . V_37 = V_37 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 = V_51 . V_56 - F_19 ( V_4 ) ;
} else {
T_3 V_61 ;
V_59 = V_4 -> V_59 - V_58 ;
V_49 [ 1 ] . V_37 = V_59 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 = V_51 . V_56 - F_19 ( V_4 ) ;
for ( V_61 = V_59 ; V_61 < V_37 ; V_61 += V_59 ) {
V_59 = V_37 - V_61 ;
if ( V_59 > V_4 -> V_59 )
V_59 = V_4 -> V_59 ;
F_18 ( V_4 , V_57 + V_61 , V_4 -> V_11 ) ;
V_49 [ 1 ] . V_52 = V_47 + V_61 ;
V_49 [ 1 ] . V_37 = V_59 ;
F_12 ( V_4 ) ;
F_8 ( V_4 ) ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 += V_51 . V_56 - F_19 ( V_4 ) ;
}
}
F_24 ( & V_4 -> V_40 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , T_5 V_57 , T_6 V_37 ,
T_6 * V_46 , const T_7 * V_47 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_48 V_49 [ 2 ] ;
struct V_50 V_51 ;
T_6 V_62 ;
int V_63 , V_64 ;
F_16 ( L_6 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( T_3 ) V_57 , V_37 ) ;
F_27 ( & V_51 ) ;
memset ( V_49 , 0 , ( sizeof V_49 ) ) ;
V_49 [ 0 ] . V_52 = V_4 -> V_11 ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) ;
F_28 ( & V_49 [ 0 ] , & V_51 ) ;
V_49 [ 1 ] . V_52 = V_47 ;
F_28 ( & V_49 [ 1 ] , & V_51 ) ;
F_23 ( & V_4 -> V_40 ) ;
V_64 = F_12 ( V_4 ) ;
if ( V_64 )
goto V_65;
F_8 ( V_4 ) ;
V_62 = V_57 % 2 ;
if ( V_62 ) {
V_4 -> V_11 [ 0 ] = V_66 ;
F_18 ( V_4 , V_57 , V_4 -> V_11 ) ;
V_49 [ 1 ] . V_37 = 1 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
V_64 = F_12 ( V_4 ) ;
if ( V_64 )
goto V_65;
* V_46 += V_51 . V_56 - F_19 ( V_4 ) ;
}
V_57 += V_62 ;
V_4 -> V_11 [ 0 ] = V_67 ;
F_18 ( V_4 , V_57 , V_4 -> V_11 ) ;
V_63 = F_19 ( V_4 ) ;
for (; V_62 < V_37 - 1 ; V_62 += 2 ) {
V_49 [ 0 ] . V_37 = V_63 ;
V_49 [ 1 ] . V_37 = 2 ;
V_49 [ 1 ] . V_52 = V_47 + V_62 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
V_64 = F_12 ( V_4 ) ;
if ( V_64 )
goto V_65;
* V_46 += V_51 . V_56 - V_63 ;
V_63 = 1 ;
V_57 += 2 ;
}
F_9 ( V_4 ) ;
V_64 = F_12 ( V_4 ) ;
if ( V_64 )
goto V_65;
if ( V_62 != V_37 ) {
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_66 ;
F_18 ( V_4 , V_57 , V_4 -> V_11 ) ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) ;
V_49 [ 1 ] . V_37 = 1 ;
V_49 [ 1 ] . V_52 = V_47 + V_62 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
V_64 = F_12 ( V_4 ) ;
if ( V_64 )
goto V_65;
* V_46 += V_51 . V_56 - F_19 ( V_4 ) ;
F_9 ( V_4 ) ;
}
V_65:
F_24 ( & V_4 -> V_40 ) ;
return V_64 ;
}
static const struct V_68 * T_8 F_32 ( struct V_69 * V_9 )
{
int V_70 ;
T_2 V_6 = V_71 ;
T_2 V_72 [ 5 ] ;
T_3 V_73 ;
T_9 V_74 ;
struct V_75 * V_76 ;
V_70 = F_4 ( V_9 , & V_6 , 1 , V_72 , 5 ) ;
if ( V_70 < 0 ) {
F_16 ( L_7 ,
F_17 ( & V_9 -> V_10 ) , V_70 ) ;
return F_33 ( V_70 ) ;
}
V_73 = V_72 [ 0 ] ;
V_73 = V_73 << 8 ;
V_73 |= V_72 [ 1 ] ;
V_73 = V_73 << 8 ;
V_73 |= V_72 [ 2 ] ;
V_74 = V_72 [ 3 ] << 8 | V_72 [ 4 ] ;
for ( V_70 = 0 ; V_70 < F_34 ( V_77 ) - 1 ; V_70 ++ ) {
V_76 = ( void * ) V_77 [ V_70 ] . V_78 ;
if ( V_76 -> V_15 == V_73 ) {
if ( V_76 -> V_79 != 0 && V_76 -> V_79 != V_74 )
continue;
return & V_77 [ V_70 ] ;
}
}
F_5 ( & V_9 -> V_10 , L_8 , V_73 ) ;
return F_33 ( - V_80 ) ;
}
static int T_8 F_35 ( struct V_69 * V_9 )
{
const struct V_68 * V_72 = F_36 ( V_9 ) ;
struct V_81 * V_82 ;
struct V_1 * V_4 ;
struct V_75 * V_76 ;
unsigned V_61 ;
struct V_83 V_84 ;
#ifdef F_37
if ( ! F_38 ( V_9 -> V_10 . V_85 ) )
return - V_80 ;
#endif
V_82 = V_9 -> V_10 . V_86 ;
if ( V_82 && V_82 -> type ) {
const struct V_68 * V_87 ;
for ( V_61 = 0 ; V_61 < F_34 ( V_77 ) - 1 ; V_61 ++ ) {
V_87 = & V_77 [ V_61 ] ;
if ( strcmp ( V_82 -> type , V_87 -> V_88 ) )
continue;
break;
}
if ( V_61 < F_34 ( V_77 ) - 1 )
V_72 = V_87 ;
else
F_39 ( & V_9 -> V_10 , L_9 , V_82 -> type ) ;
}
V_76 = ( void * ) V_72 -> V_78 ;
if ( V_76 -> V_15 ) {
const struct V_68 * V_89 ;
V_89 = F_32 ( V_9 ) ;
if ( F_40 ( V_89 ) ) {
return F_41 ( V_89 ) ;
} else if ( V_89 != V_72 ) {
F_39 ( & V_9 -> V_10 , L_10 ,
V_89 -> V_88 , V_72 -> V_88 ) ;
V_72 = V_89 ;
V_76 = ( void * ) V_89 -> V_78 ;
}
}
V_4 = F_42 ( sizeof *V_4 , V_90 ) ;
if ( ! V_4 )
return - V_91 ;
V_4 -> V_11 = F_43 ( V_92 + V_53 , V_90 ) ;
if ( ! V_4 -> V_11 ) {
F_44 ( V_4 ) ;
return - V_91 ;
}
V_4 -> V_9 = V_9 ;
F_45 ( & V_4 -> V_40 ) ;
F_46 ( & V_9 -> V_10 , V_4 ) ;
if ( F_11 ( V_76 -> V_15 ) == V_93 ||
F_11 ( V_76 -> V_15 ) == V_94 ||
F_11 ( V_76 -> V_15 ) == V_95 ) {
F_8 ( V_4 ) ;
F_6 ( V_4 , 0 ) ;
}
if ( V_82 && V_82 -> V_88 )
V_4 -> V_3 . V_88 = V_82 -> V_88 ;
else
V_4 -> V_3 . V_88 = F_17 ( & V_9 -> V_10 ) ;
V_4 -> V_3 . type = V_96 ;
V_4 -> V_3 . V_97 = 1 ;
V_4 -> V_3 . V_98 = V_99 ;
V_4 -> V_3 . V_27 = V_76 -> V_100 * V_76 -> V_101 ;
V_4 -> V_3 . V_102 = F_21 ;
V_4 -> V_3 . V_103 = F_26 ;
if ( F_11 ( V_76 -> V_15 ) == V_95 )
V_4 -> V_3 . V_104 = F_31 ;
else
V_4 -> V_3 . V_104 = F_30 ;
if ( V_76 -> V_98 & V_105 ) {
V_4 -> V_34 = V_106 ;
V_4 -> V_3 . V_33 = 4096 ;
} else {
V_4 -> V_34 = V_107 ;
V_4 -> V_3 . V_33 = V_76 -> V_100 ;
}
if ( V_76 -> V_98 & V_108 )
V_4 -> V_3 . V_98 |= V_109 ;
V_84 . V_85 = V_9 -> V_10 . V_85 ;
V_4 -> V_3 . V_10 . V_110 = & V_9 -> V_10 ;
V_4 -> V_59 = V_76 -> V_59 ;
V_4 -> V_3 . V_111 = V_4 -> V_59 ;
if ( V_76 -> V_31 )
V_4 -> V_31 = V_76 -> V_31 ;
else {
if ( V_4 -> V_3 . V_27 > 0x1000000 ) {
V_4 -> V_31 = 4 ;
F_10 ( V_4 , V_76 -> V_15 , 1 ) ;
} else
V_4 -> V_31 = 3 ;
}
F_47 ( & V_9 -> V_10 , L_11 , V_72 -> V_88 ,
( long long ) V_4 -> V_3 . V_27 >> 10 ) ;
F_16 ( L_12
L_13 ,
V_4 -> V_3 . V_88 ,
( long long ) V_4 -> V_3 . V_27 , ( long long ) ( V_4 -> V_3 . V_27 >> 20 ) ,
V_4 -> V_3 . V_33 , V_4 -> V_3 . V_33 / 1024 ,
V_4 -> V_3 . V_112 ) ;
if ( V_4 -> V_3 . V_112 )
for ( V_61 = 0 ; V_61 < V_4 -> V_3 . V_112 ; V_61 ++ )
F_16 ( L_14
L_15
L_16 ,
V_61 , ( long long ) V_4 -> V_3 . V_113 [ V_61 ] . V_32 ,
V_4 -> V_3 . V_113 [ V_61 ] . V_33 ,
V_4 -> V_3 . V_113 [ V_61 ] . V_33 / 1024 ,
V_4 -> V_3 . V_113 [ V_61 ] . V_114 ) ;
return F_48 ( & V_4 -> V_3 , NULL , & V_84 ,
V_82 ? V_82 -> V_115 : NULL ,
V_82 ? V_82 -> V_116 : 0 ) ;
}
static int T_10 F_49 ( struct V_69 * V_9 )
{
struct V_1 * V_4 = F_50 ( & V_9 -> V_10 ) ;
int V_117 ;
V_117 = F_51 ( & V_4 -> V_3 ) ;
if ( V_117 == 0 ) {
F_44 ( V_4 -> V_11 ) ;
F_44 ( V_4 ) ;
}
return 0 ;
}
