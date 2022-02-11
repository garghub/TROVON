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
case 0xEF :
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
T_8 V_52 ;
F_16 ( L_5 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( T_3 ) V_45 , V_37 ) ;
F_27 ( & V_51 ) ;
memset ( V_49 , 0 , ( sizeof V_49 ) ) ;
V_49 [ 0 ] . V_53 = V_4 -> V_11 ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) + ( V_4 -> V_54 ? 1 : 0 ) ;
F_28 ( & V_49 [ 0 ] , & V_51 ) ;
V_49 [ 1 ] . V_55 = V_47 ;
V_49 [ 1 ] . V_37 = V_37 ;
F_28 ( & V_49 [ 1 ] , & V_51 ) ;
F_23 ( & V_4 -> V_40 ) ;
if ( F_12 ( V_4 ) ) {
F_24 ( & V_4 -> V_40 ) ;
return 1 ;
}
V_52 = V_4 -> V_54 ? V_56 : V_57 ;
V_4 -> V_11 [ 0 ] = V_52 ;
F_18 ( V_4 , V_45 , V_4 -> V_11 ) ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 = V_51 . V_58 - F_19 ( V_4 ) -
( V_4 -> V_54 ? 1 : 0 ) ;
F_24 ( & V_4 -> V_40 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , T_5 V_59 , T_6 V_37 ,
T_6 * V_46 , const T_7 * V_47 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_60 , V_61 ;
struct V_48 V_49 [ 2 ] ;
struct V_50 V_51 ;
F_16 ( L_6 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( T_3 ) V_59 , V_37 ) ;
F_27 ( & V_51 ) ;
memset ( V_49 , 0 , ( sizeof V_49 ) ) ;
V_49 [ 0 ] . V_53 = V_4 -> V_11 ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) ;
F_28 ( & V_49 [ 0 ] , & V_51 ) ;
V_49 [ 1 ] . V_53 = V_47 ;
F_28 ( & V_49 [ 1 ] , & V_51 ) ;
F_23 ( & V_4 -> V_40 ) ;
if ( F_12 ( V_4 ) ) {
F_24 ( & V_4 -> V_40 ) ;
return 1 ;
}
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_62 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_60 = V_59 & ( V_4 -> V_61 - 1 ) ;
if ( V_60 + V_37 <= V_4 -> V_61 ) {
V_49 [ 1 ] . V_37 = V_37 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 = V_51 . V_58 - F_19 ( V_4 ) ;
} else {
T_3 V_63 ;
V_61 = V_4 -> V_61 - V_60 ;
V_49 [ 1 ] . V_37 = V_61 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 = V_51 . V_58 - F_19 ( V_4 ) ;
for ( V_63 = V_61 ; V_63 < V_37 ; V_63 += V_61 ) {
V_61 = V_37 - V_63 ;
if ( V_61 > V_4 -> V_61 )
V_61 = V_4 -> V_61 ;
F_18 ( V_4 , V_59 + V_63 , V_4 -> V_11 ) ;
V_49 [ 1 ] . V_53 = V_47 + V_63 ;
V_49 [ 1 ] . V_37 = V_61 ;
F_12 ( V_4 ) ;
F_8 ( V_4 ) ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
* V_46 += V_51 . V_58 - F_19 ( V_4 ) ;
}
}
F_24 ( & V_4 -> V_40 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , T_5 V_59 , T_6 V_37 ,
T_6 * V_46 , const T_7 * V_47 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_48 V_49 [ 2 ] ;
struct V_50 V_51 ;
T_6 V_64 ;
int V_65 , V_66 ;
F_16 ( L_6 , F_17 ( & V_4 -> V_9 -> V_10 ) ,
V_26 , ( T_3 ) V_59 , V_37 ) ;
F_27 ( & V_51 ) ;
memset ( V_49 , 0 , ( sizeof V_49 ) ) ;
V_49 [ 0 ] . V_53 = V_4 -> V_11 ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) ;
F_28 ( & V_49 [ 0 ] , & V_51 ) ;
V_49 [ 1 ] . V_53 = V_47 ;
F_28 ( & V_49 [ 1 ] , & V_51 ) ;
F_23 ( & V_4 -> V_40 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
F_8 ( V_4 ) ;
V_64 = V_59 % 2 ;
if ( V_64 ) {
V_4 -> V_11 [ 0 ] = V_68 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_49 [ 1 ] . V_37 = 1 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
* V_46 += V_51 . V_58 - F_19 ( V_4 ) ;
}
V_59 += V_64 ;
V_4 -> V_11 [ 0 ] = V_69 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_65 = F_19 ( V_4 ) ;
for (; V_64 < V_37 - 1 ; V_64 += 2 ) {
V_49 [ 0 ] . V_37 = V_65 ;
V_49 [ 1 ] . V_37 = 2 ;
V_49 [ 1 ] . V_53 = V_47 + V_64 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
* V_46 += V_51 . V_58 - V_65 ;
V_65 = 1 ;
V_59 += 2 ;
}
F_9 ( V_4 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
if ( V_64 != V_37 ) {
F_8 ( V_4 ) ;
V_4 -> V_11 [ 0 ] = V_68 ;
F_18 ( V_4 , V_59 , V_4 -> V_11 ) ;
V_49 [ 0 ] . V_37 = F_19 ( V_4 ) ;
V_49 [ 1 ] . V_37 = 1 ;
V_49 [ 1 ] . V_53 = V_47 + V_64 ;
F_29 ( V_4 -> V_9 , & V_51 ) ;
V_66 = F_12 ( V_4 ) ;
if ( V_66 )
goto V_67;
* V_46 += V_51 . V_58 - F_19 ( V_4 ) ;
F_9 ( V_4 ) ;
}
V_67:
F_24 ( & V_4 -> V_40 ) ;
return V_66 ;
}
static const struct V_70 * F_32 ( struct V_71 * V_9 )
{
int V_72 ;
T_2 V_6 = V_73 ;
T_2 V_74 [ 5 ] ;
T_3 V_75 ;
T_9 V_76 ;
struct V_77 * V_78 ;
V_72 = F_4 ( V_9 , & V_6 , 1 , V_74 , 5 ) ;
if ( V_72 < 0 ) {
F_16 ( L_7 ,
F_17 ( & V_9 -> V_10 ) , V_72 ) ;
return F_33 ( V_72 ) ;
}
V_75 = V_74 [ 0 ] ;
V_75 = V_75 << 8 ;
V_75 |= V_74 [ 1 ] ;
V_75 = V_75 << 8 ;
V_75 |= V_74 [ 2 ] ;
V_76 = V_74 [ 3 ] << 8 | V_74 [ 4 ] ;
for ( V_72 = 0 ; V_72 < F_34 ( V_79 ) - 1 ; V_72 ++ ) {
V_78 = ( void * ) V_79 [ V_72 ] . V_80 ;
if ( V_78 -> V_15 == V_75 ) {
if ( V_78 -> V_81 != 0 && V_78 -> V_81 != V_76 )
continue;
return & V_79 [ V_72 ] ;
}
}
F_5 ( & V_9 -> V_10 , L_8 , V_75 ) ;
return F_33 ( - V_82 ) ;
}
static int F_35 ( struct V_71 * V_9 )
{
const struct V_70 * V_74 = F_36 ( V_9 ) ;
struct V_83 * V_84 ;
struct V_1 * V_4 ;
struct V_77 * V_78 ;
unsigned V_63 ;
struct V_85 V_86 ;
struct V_87 T_10 * V_88 = V_9 -> V_10 . V_89 ;
#ifdef F_37
if ( ! F_38 ( V_88 ) )
return - V_82 ;
#endif
V_84 = V_9 -> V_10 . V_90 ;
if ( V_84 && V_84 -> type ) {
const struct V_70 * V_91 ;
for ( V_63 = 0 ; V_63 < F_34 ( V_79 ) - 1 ; V_63 ++ ) {
V_91 = & V_79 [ V_63 ] ;
if ( strcmp ( V_84 -> type , V_91 -> V_92 ) )
continue;
break;
}
if ( V_63 < F_34 ( V_79 ) - 1 )
V_74 = V_91 ;
else
F_39 ( & V_9 -> V_10 , L_9 , V_84 -> type ) ;
}
V_78 = ( void * ) V_74 -> V_80 ;
if ( V_78 -> V_15 ) {
const struct V_70 * V_93 ;
V_93 = F_32 ( V_9 ) ;
if ( F_40 ( V_93 ) ) {
return F_41 ( V_93 ) ;
} else if ( V_93 != V_74 ) {
F_39 ( & V_9 -> V_10 , L_10 ,
V_93 -> V_92 , V_74 -> V_92 ) ;
V_74 = V_93 ;
V_78 = ( void * ) V_93 -> V_80 ;
}
}
V_4 = F_42 ( sizeof *V_4 , V_94 ) ;
if ( ! V_4 )
return - V_95 ;
V_4 -> V_11 = F_43 ( V_96 + ( V_4 -> V_54 ? 1 : 0 ) ,
V_94 ) ;
if ( ! V_4 -> V_11 ) {
F_44 ( V_4 ) ;
return - V_95 ;
}
V_4 -> V_9 = V_9 ;
F_45 ( & V_4 -> V_40 ) ;
F_46 ( & V_9 -> V_10 , V_4 ) ;
if ( F_11 ( V_78 -> V_15 ) == V_97 ||
F_11 ( V_78 -> V_15 ) == V_98 ||
F_11 ( V_78 -> V_15 ) == V_99 ) {
F_8 ( V_4 ) ;
F_6 ( V_4 , 0 ) ;
}
if ( V_84 && V_84 -> V_92 )
V_4 -> V_3 . V_92 = V_84 -> V_92 ;
else
V_4 -> V_3 . V_92 = F_17 ( & V_9 -> V_10 ) ;
V_4 -> V_3 . type = V_100 ;
V_4 -> V_3 . V_101 = 1 ;
V_4 -> V_3 . V_102 = V_103 ;
V_4 -> V_3 . V_27 = V_78 -> V_104 * V_78 -> V_105 ;
V_4 -> V_3 . V_106 = F_21 ;
V_4 -> V_3 . V_107 = F_26 ;
if ( F_11 ( V_78 -> V_15 ) == V_99 )
V_4 -> V_3 . V_108 = F_31 ;
else
V_4 -> V_3 . V_108 = F_30 ;
if ( V_78 -> V_102 & V_109 ) {
V_4 -> V_34 = V_110 ;
V_4 -> V_3 . V_33 = 4096 ;
} else {
V_4 -> V_34 = V_111 ;
V_4 -> V_3 . V_33 = V_78 -> V_104 ;
}
if ( V_78 -> V_102 & V_112 )
V_4 -> V_3 . V_102 |= V_113 ;
V_86 . V_89 = V_9 -> V_10 . V_89 ;
V_4 -> V_3 . V_10 . V_114 = & V_9 -> V_10 ;
V_4 -> V_61 = V_78 -> V_61 ;
V_4 -> V_3 . V_115 = V_4 -> V_61 ;
V_4 -> V_54 = false ;
#ifdef F_47
if ( V_88 && F_48 ( V_88 , L_11 ) )
V_4 -> V_54 = true ;
#endif
#ifdef F_49
V_4 -> V_54 = true ;
#endif
if ( V_78 -> V_31 )
V_4 -> V_31 = V_78 -> V_31 ;
else {
if ( V_4 -> V_3 . V_27 > 0x1000000 ) {
V_4 -> V_31 = 4 ;
F_10 ( V_4 , V_78 -> V_15 , 1 ) ;
} else
V_4 -> V_31 = 3 ;
}
F_50 ( & V_9 -> V_10 , L_12 , V_74 -> V_92 ,
( long long ) V_4 -> V_3 . V_27 >> 10 ) ;
F_16 ( L_13
L_14 ,
V_4 -> V_3 . V_92 ,
( long long ) V_4 -> V_3 . V_27 , ( long long ) ( V_4 -> V_3 . V_27 >> 20 ) ,
V_4 -> V_3 . V_33 , V_4 -> V_3 . V_33 / 1024 ,
V_4 -> V_3 . V_116 ) ;
if ( V_4 -> V_3 . V_116 )
for ( V_63 = 0 ; V_63 < V_4 -> V_3 . V_116 ; V_63 ++ )
F_16 ( L_15
L_16
L_17 ,
V_63 , ( long long ) V_4 -> V_3 . V_117 [ V_63 ] . V_32 ,
V_4 -> V_3 . V_117 [ V_63 ] . V_33 ,
V_4 -> V_3 . V_117 [ V_63 ] . V_33 / 1024 ,
V_4 -> V_3 . V_117 [ V_63 ] . V_118 ) ;
return F_51 ( & V_4 -> V_3 , NULL , & V_86 ,
V_84 ? V_84 -> V_119 : NULL ,
V_84 ? V_84 -> V_120 : 0 ) ;
}
static int F_52 ( struct V_71 * V_9 )
{
struct V_1 * V_4 = F_53 ( & V_9 -> V_10 ) ;
int V_121 ;
V_121 = F_54 ( & V_4 -> V_3 ) ;
if ( V_121 == 0 ) {
F_44 ( V_4 -> V_11 ) ;
F_44 ( V_4 ) ;
}
return 0 ;
}
