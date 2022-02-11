static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 ;
F_2 ( V_5 ) ;
V_7 = F_3 ( V_5 ) ;
if ( V_7 ) {
F_4 ( ! F_5 ( V_5 ) ) ;
F_6 ( V_5 ) ;
if ( F_7 ( V_5 ) &&
! F_8 ( V_5 , V_8 ) )
goto V_9;
if ( F_9 ( V_7 , V_5 ) ) {
V_4 -> V_10 |= V_11 ;
return 0 ;
}
}
V_9:
F_10 ( V_5 ) ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_12 ( V_4 -> V_5 ) ;
V_4 -> V_10 &= ~ V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
int V_12 ;
if ( ! F_5 ( V_5 ) ) {
F_2 ( V_5 ) ;
if ( ! V_5 -> V_7 ) {
V_12 = - V_13 ;
goto error;
}
if ( ! F_5 ( V_5 ) ) {
V_12 = - V_14 ;
goto error;
}
F_10 ( V_5 ) ;
}
return 0 ;
error:
F_10 ( V_5 ) ;
return V_12 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_10 & V_15 ) )
return 1 ;
V_4 -> V_10 |= V_11 ;
return F_15 ( V_2 , V_4 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_17 , V_18 , V_19 ) ;
}
T_1 F_21 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
unsigned int V_22 = V_21 -> V_23 ;
int V_24 , V_25 , V_26 ;
V_24 = 0 ;
V_25 = 0 ;
V_26 = 0 ;
F_22 ( V_2 ) ;
for (; ; ) {
if ( ! V_2 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( V_2 -> V_31 < V_2 -> V_32 ) {
int V_33 = ( V_2 -> V_34 + V_2 -> V_31 ) & ( V_2 -> V_32 - 1 ) ;
struct V_3 * V_4 = V_2 -> V_35 + V_33 ;
V_4 -> V_5 = V_21 -> V_36 [ V_26 ] ;
V_4 -> V_37 = V_21 -> V_38 [ V_26 ] . V_37 ;
V_4 -> V_39 = V_21 -> V_38 [ V_26 ] . V_39 ;
V_4 -> V_40 = V_21 -> V_38 [ V_26 ] . V_40 ;
V_4 -> V_41 = V_21 -> V_41 ;
if ( V_21 -> V_10 & V_42 )
V_4 -> V_10 |= V_15 ;
V_2 -> V_31 ++ ;
V_26 ++ ;
V_24 += V_4 -> V_39 ;
if ( V_2 -> V_43 )
V_25 = 1 ;
if ( ! -- V_21 -> V_23 )
break;
if ( V_2 -> V_31 < V_2 -> V_32 )
continue;
break;
}
if ( V_21 -> V_10 & V_44 ) {
if ( ! V_24 )
V_24 = - V_45 ;
break;
}
if ( F_24 ( V_29 ) ) {
if ( ! V_24 )
V_24 = - V_46 ;
break;
}
if ( V_25 ) {
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_25 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_17 , V_18 , V_19 ) ;
V_25 = 0 ;
}
V_2 -> V_47 ++ ;
F_26 ( V_2 ) ;
V_2 -> V_47 -- ;
}
F_27 ( V_2 ) ;
if ( V_25 )
F_16 ( V_2 ) ;
while ( V_26 < V_22 )
V_21 -> V_48 ( V_21 , V_26 ++ ) ;
return V_24 ;
}
void F_28 ( struct V_20 * V_21 , unsigned int V_49 )
{
F_12 ( V_21 -> V_36 [ V_49 ] ) ;
}
int F_29 ( const struct V_1 * V_2 , struct V_20 * V_21 )
{
unsigned int V_32 = F_30 ( V_2 -> V_32 ) ;
V_21 -> V_50 = V_32 ;
if ( V_32 <= V_51 )
return 0 ;
V_21 -> V_36 = F_31 ( V_32 * sizeof( struct V_5 * ) , V_8 ) ;
V_21 -> V_38 = F_31 ( V_32 * sizeof( struct V_52 ) , V_8 ) ;
if ( V_21 -> V_36 && V_21 -> V_38 )
return 0 ;
F_32 ( V_21 -> V_36 ) ;
F_32 ( V_21 -> V_38 ) ;
return - V_53 ;
}
void F_33 ( struct V_20 * V_21 )
{
if ( V_21 -> V_50 <= V_51 )
return;
F_32 ( V_21 -> V_36 ) ;
F_32 ( V_21 -> V_38 ) ;
}
static int
F_34 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_6 * V_7 = V_55 -> V_57 ;
unsigned int V_58 , V_23 , V_59 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_5 * V_5 ;
T_4 V_60 , V_61 ;
T_2 V_62 ;
int error , V_26 ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_63 ,
. V_48 = F_28 ,
} ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_60 = * V_56 >> V_64 ;
V_58 = * V_56 & ~ V_65 ;
V_59 = ( V_39 + V_58 + V_66 - 1 ) >> V_64 ;
V_23 = F_35 ( V_59 , V_21 . V_50 ) ;
V_21 . V_23 = F_36 ( V_7 , V_60 , V_23 , V_21 . V_36 ) ;
V_60 += V_21 . V_23 ;
if ( V_21 . V_23 < V_23 )
F_37 ( V_7 , & V_55 -> V_67 , V_55 ,
V_60 , V_59 - V_21 . V_23 ) ;
error = 0 ;
while ( V_21 . V_23 < V_23 ) {
V_5 = F_38 ( V_7 , V_60 ) ;
if ( ! V_5 ) {
V_5 = F_39 ( V_7 ) ;
if ( ! V_5 )
break;
error = F_40 ( V_5 , V_7 , V_60 ,
F_41 ( V_7 , V_8 ) ) ;
if ( F_42 ( error ) ) {
F_12 ( V_5 ) ;
if ( error == - V_68 )
continue;
break;
}
F_10 ( V_5 ) ;
}
V_21 . V_36 [ V_21 . V_23 ++ ] = V_5 ;
V_60 ++ ;
}
V_60 = * V_56 >> V_64 ;
V_23 = V_21 . V_23 ;
V_21 . V_23 = 0 ;
for ( V_26 = 0 ; V_26 < V_23 ; V_26 ++ ) {
unsigned int V_69 ;
if ( ! V_39 )
break;
V_69 = F_43 (unsigned long, len, PAGE_CACHE_SIZE - loff) ;
V_5 = V_21 . V_36 [ V_26 ] ;
if ( F_44 ( V_5 ) )
F_45 ( V_7 , & V_55 -> V_67 , V_55 ,
V_5 , V_60 , V_59 - V_26 ) ;
if ( ! F_5 ( V_5 ) ) {
F_2 ( V_5 ) ;
if ( ! V_5 -> V_7 ) {
F_10 ( V_5 ) ;
V_70:
V_5 = F_46 ( V_7 , V_60 ,
F_47 ( V_7 ) ) ;
if ( ! V_5 ) {
error = - V_53 ;
break;
}
F_12 ( V_21 . V_36 [ V_26 ] ) ;
V_21 . V_36 [ V_26 ] = V_5 ;
}
if ( F_5 ( V_5 ) ) {
F_10 ( V_5 ) ;
goto V_71;
}
error = V_7 -> V_72 -> V_73 ( V_55 , V_5 ) ;
if ( F_42 ( error ) ) {
if ( error == V_74 )
goto V_70;
break;
}
}
V_71:
V_62 = F_48 ( V_7 -> V_75 ) ;
V_61 = ( V_62 - 1 ) >> V_64 ;
if ( F_42 ( ! V_62 || V_60 > V_61 ) )
break;
if ( V_61 == V_60 ) {
unsigned int V_76 ;
V_76 = ( ( V_62 - 1 ) & ~ V_65 ) + 1 ;
if ( V_76 <= V_58 )
break;
V_69 = F_35 ( V_69 , V_76 - V_58 ) ;
V_39 = V_69 ;
}
V_21 . V_38 [ V_26 ] . V_37 = V_58 ;
V_21 . V_38 [ V_26 ] . V_39 = V_69 ;
V_39 -= V_69 ;
V_58 = 0 ;
V_21 . V_23 ++ ;
V_60 ++ ;
}
while ( V_26 < V_23 )
F_12 ( V_21 . V_36 [ V_26 ++ ] ) ;
V_55 -> V_67 . V_77 = ( T_2 ) V_60 << V_64 ;
if ( V_21 . V_23 )
error = F_21 ( V_2 , & V_21 ) ;
F_33 ( & V_21 ) ;
return error ;
}
T_1 F_49 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_2 V_62 , V_78 ;
int V_24 ;
if ( F_50 ( V_55 -> V_57 -> V_75 ) )
return F_51 ( V_55 , V_56 , V_2 , V_39 , V_10 ) ;
V_62 = F_48 ( V_55 -> V_57 -> V_75 ) ;
if ( F_42 ( * V_56 >= V_62 ) )
return 0 ;
V_78 = V_62 - * V_56 ;
if ( F_42 ( V_78 < V_39 ) )
V_39 = V_78 ;
V_24 = F_34 ( V_55 , V_56 , V_2 , V_39 , V_10 ) ;
if ( V_24 > 0 ) {
* V_56 += V_24 ;
F_52 ( V_55 ) ;
}
return V_24 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static T_1 F_54 ( struct V_54 * V_54 , const struct V_79 * V_80 ,
unsigned long V_81 , T_2 V_37 )
{
T_5 V_82 ;
T_2 V_83 = V_37 ;
T_1 V_84 ;
V_82 = F_55 () ;
F_56 ( F_57 () ) ;
V_84 = F_58 ( V_54 , ( const struct V_79 V_85 * ) V_80 , V_81 , & V_83 ) ;
F_56 ( V_82 ) ;
return V_84 ;
}
T_1 F_59 ( struct V_54 * V_54 , const char * V_4 , T_3 V_86 ,
T_2 V_83 )
{
T_5 V_82 ;
T_1 V_84 ;
V_82 = F_55 () ;
F_56 ( F_57 () ) ;
V_84 = F_60 ( V_54 , ( V_87 const char V_85 * ) V_4 , V_86 , & V_83 ) ;
F_56 ( V_82 ) ;
return V_84 ;
}
T_1 F_51 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
unsigned int V_23 ;
unsigned int V_88 ;
T_3 V_37 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_79 * V_80 , V_89 [ V_51 ] ;
T_1 V_84 ;
T_3 V_69 ;
int error ;
int V_49 ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_90 ,
. V_48 = F_28 ,
} ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_84 = - V_53 ;
V_80 = V_89 ;
if ( V_21 . V_50 > V_51 ) {
V_80 = F_31 ( V_21 . V_50 * sizeof( struct V_79 ) , V_8 ) ;
if ( ! V_80 )
goto V_91;
}
V_37 = * V_56 & ~ V_65 ;
V_23 = ( V_39 + V_37 + V_66 - 1 ) >> V_64 ;
for ( V_49 = 0 ; V_49 < V_23 && V_49 < V_21 . V_50 && V_39 ; V_49 ++ ) {
struct V_5 * V_5 ;
V_5 = F_61 ( V_92 ) ;
error = - V_53 ;
if ( ! V_5 )
goto V_12;
V_69 = F_43 ( T_3 , V_39 , V_66 - V_37 ) ;
V_80 [ V_49 ] . V_93 = ( void V_85 * ) F_62 ( V_5 ) ;
V_80 [ V_49 ] . V_94 = V_69 ;
V_21 . V_36 [ V_49 ] = V_5 ;
V_21 . V_23 ++ ;
V_39 -= V_69 ;
V_37 = 0 ;
}
V_84 = F_54 ( V_55 , V_80 , V_21 . V_23 , * V_56 ) ;
if ( V_84 < 0 ) {
error = V_84 ;
goto V_12;
}
error = 0 ;
if ( ! V_84 )
goto V_12;
V_88 = 0 ;
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ ) {
V_69 = F_43 ( T_3 , V_80 [ V_49 ] . V_94 , V_84 ) ;
V_21 . V_38 [ V_49 ] . V_37 = 0 ;
V_21 . V_38 [ V_49 ] . V_39 = V_69 ;
if ( ! V_69 ) {
F_63 ( V_21 . V_36 [ V_49 ] ) ;
V_21 . V_36 [ V_49 ] = NULL ;
V_88 ++ ;
}
V_84 -= V_69 ;
}
V_21 . V_23 -= V_88 ;
V_84 = F_21 ( V_2 , & V_21 ) ;
if ( V_84 > 0 )
* V_56 += V_84 ;
V_91:
if ( V_80 != V_89 )
F_32 ( V_80 ) ;
F_33 ( & V_21 ) ;
return V_84 ;
V_12:
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ )
F_63 ( V_21 . V_36 [ V_49 ] ) ;
V_84 = error ;
goto V_91;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_95 * V_96 )
{
struct V_54 * V_54 = V_96 -> V_97 . V_54 ;
T_2 V_83 = V_96 -> V_83 ;
int V_98 ;
if ( ! F_65 ( V_54 -> V_99 -> V_100 ) )
return - V_101 ;
V_98 = ( V_96 -> V_10 & V_102 ) ? V_103 : 0 ;
if ( V_96 -> V_39 < V_96 -> V_104 && V_2 -> V_31 > 1 )
V_98 |= V_105 ;
return V_54 -> V_99 -> V_100 ( V_54 , V_4 -> V_5 , V_4 -> V_37 ,
V_96 -> V_39 , & V_83 , V_98 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_106 , V_18 , V_107 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_95 * V_96 ,
T_6 * V_108 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
const struct V_109 * V_41 = V_4 -> V_41 ;
V_96 -> V_39 = V_4 -> V_39 ;
if ( V_96 -> V_39 > V_96 -> V_104 )
V_96 -> V_39 = V_96 -> V_104 ;
V_24 = V_4 -> V_41 -> V_110 ( V_2 , V_4 ) ;
if ( F_42 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_108 ( V_2 , V_4 , V_96 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_96 -> V_111 += V_24 ;
V_96 -> V_39 -= V_24 ;
V_96 -> V_83 += V_24 ;
V_96 -> V_104 -= V_24 ;
if ( ! V_4 -> V_39 ) {
V_4 -> V_41 = NULL ;
V_41 -> V_112 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_43 )
V_96 -> V_113 = true ;
}
if ( ! V_96 -> V_104 )
return 0 ;
}
return 1 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
if ( F_24 ( V_29 ) )
return - V_46 ;
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_114 )
return 0 ;
if ( ! V_2 -> V_47 && V_96 -> V_111 )
return 0 ;
if ( V_96 -> V_10 & V_44 )
return - V_45 ;
if ( F_24 ( V_29 ) )
return - V_46 ;
if ( V_96 -> V_113 ) {
F_66 ( V_2 ) ;
V_96 -> V_113 = false ;
}
F_26 ( V_2 ) ;
}
return 1 ;
}
static void F_69 ( struct V_95 * V_96 )
{
V_96 -> V_111 = 0 ;
V_96 -> V_113 = false ;
}
static void F_70 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
if ( V_96 -> V_113 )
F_66 ( V_2 ) ;
}
T_1 F_71 ( struct V_1 * V_2 , struct V_95 * V_96 ,
T_6 * V_108 )
{
int V_24 ;
F_69 ( V_96 ) ;
do {
F_72 () ;
V_24 = F_68 ( V_2 , V_96 ) ;
if ( V_24 > 0 )
V_24 = F_67 ( V_2 , V_96 , V_108 ) ;
} while ( V_24 > 0 );
F_70 ( V_2 , V_96 ) ;
return V_96 -> V_111 ? V_96 -> V_111 : V_24 ;
}
T_1 F_73 ( struct V_1 * V_2 , struct V_54 * V_115 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 ,
T_6 * V_108 )
{
T_1 V_24 ;
struct V_95 V_96 = {
. V_104 = V_39 ,
. V_10 = V_10 ,
. V_83 = * V_56 ,
. V_97 . V_54 = V_115 ,
} ;
F_22 ( V_2 ) ;
V_24 = F_71 ( V_2 , & V_96 , V_108 ) ;
F_27 ( V_2 ) ;
return V_24 ;
}
T_1
F_74 ( struct V_1 * V_2 , struct V_54 * V_115 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
struct V_95 V_96 = {
. V_104 = V_39 ,
. V_10 = V_10 ,
. V_83 = * V_56 ,
. V_97 . V_54 = V_115 ,
} ;
int V_116 = V_2 -> V_32 ;
struct V_117 * V_118 = F_75 ( V_116 , sizeof( struct V_117 ) ,
V_8 ) ;
T_1 V_24 ;
if ( F_42 ( ! V_118 ) )
return - V_53 ;
F_22 ( V_2 ) ;
F_69 ( & V_96 ) ;
while ( V_96 . V_104 ) {
struct V_119 V_120 ;
T_3 V_78 ;
int V_121 , V_122 ;
V_24 = F_68 ( V_2 , & V_96 ) ;
if ( V_24 <= 0 )
break;
if ( F_42 ( V_116 < V_2 -> V_32 ) ) {
F_32 ( V_118 ) ;
V_116 = V_2 -> V_32 ;
V_118 = F_75 ( V_116 , sizeof( struct V_117 ) ,
V_8 ) ;
if ( ! V_118 ) {
V_24 = - V_53 ;
break;
}
}
V_78 = V_96 . V_104 ;
for ( V_121 = 0 , V_122 = V_2 -> V_34 ; V_78 && V_121 < V_2 -> V_31 ; V_121 ++ , V_122 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_122 ;
T_3 V_69 = V_4 -> V_39 ;
if ( V_69 > V_78 )
V_69 = V_78 ;
if ( V_122 == V_2 -> V_32 - 1 )
V_122 = - 1 ;
V_24 = V_4 -> V_41 -> V_110 ( V_2 , V_4 ) ;
if ( F_42 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
goto V_123;
}
V_118 [ V_121 ] . V_124 = V_4 -> V_5 ;
V_118 [ V_121 ] . V_125 = V_69 ;
V_118 [ V_121 ] . V_126 = V_4 -> V_37 ;
V_78 -= V_69 ;
}
F_76 ( & V_120 , V_127 | V_128 , V_118 , V_121 ,
V_96 . V_104 - V_78 ) ;
V_24 = F_77 ( V_115 , & V_120 , & V_96 . V_83 ) ;
if ( V_24 <= 0 )
break;
V_96 . V_111 += V_24 ;
V_96 . V_104 -= V_24 ;
* V_56 = V_96 . V_83 ;
while ( V_24 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
if ( V_24 >= V_4 -> V_39 ) {
const struct V_109 * V_41 = V_4 -> V_41 ;
V_24 -= V_4 -> V_39 ;
V_4 -> V_39 = 0 ;
V_4 -> V_41 = NULL ;
V_41 -> V_112 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_43 )
V_96 . V_113 = true ;
} else {
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_24 = 0 ;
}
}
}
V_123:
F_32 ( V_118 ) ;
F_70 ( V_2 , & V_96 ) ;
F_27 ( V_2 ) ;
if ( V_96 . V_111 )
V_24 = V_96 . V_111 ;
return V_24 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 )
{
int V_24 ;
void * V_129 ;
T_2 V_130 = V_96 -> V_83 ;
V_129 = F_79 ( V_4 -> V_5 ) ;
V_24 = F_80 ( V_96 -> V_97 . V_54 , V_129 + V_4 -> V_37 , V_96 -> V_39 , & V_130 ) ;
F_81 ( V_4 -> V_5 ) ;
return V_24 ;
}
static T_1 F_82 ( struct V_1 * V_2 ,
struct V_54 * V_115 , T_2 * V_56 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_73 ( V_2 , V_115 , V_56 , V_39 , V_10 , F_78 ) ;
if ( V_24 > 0 )
* V_56 += V_24 ;
return V_24 ;
}
T_1 F_83 ( struct V_1 * V_2 , struct V_54 * V_115 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
return F_73 ( V_2 , V_115 , V_56 , V_39 , V_10 , F_64 ) ;
}
static long F_84 ( struct V_1 * V_2 , struct V_54 * V_115 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_85)( struct V_1 * , struct V_54 * ,
T_2 * , T_3 , unsigned int );
if ( V_115 -> V_99 -> F_85 )
F_85 = V_115 -> V_99 -> F_85 ;
else
F_85 = F_82 ;
return F_85 ( V_2 , V_115 , V_56 , V_39 , V_10 ) ;
}
static long F_86 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_87)( struct V_54 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_42 ( ! ( V_55 -> V_131 & V_132 ) ) )
return - V_133 ;
V_24 = F_88 ( V_134 , V_55 , V_56 , V_39 ) ;
if ( F_42 ( V_24 < 0 ) )
return V_24 ;
if ( V_55 -> V_99 -> F_87 )
F_87 = V_55 -> V_99 -> F_87 ;
else
F_87 = F_51 ;
return F_87 ( V_55 , V_56 , V_2 , V_39 , V_10 ) ;
}
T_1 F_89 ( struct V_54 * V_55 , struct V_95 * V_96 ,
T_7 * V_108 )
{
struct V_1 * V_2 ;
long V_24 , V_135 ;
T_8 V_136 ;
T_3 V_39 ;
int V_49 , V_10 , V_98 ;
V_136 = F_90 ( V_55 ) -> V_136 ;
if ( F_42 ( ! F_91 ( V_136 ) && ! F_92 ( V_136 ) ) )
return - V_101 ;
V_2 = V_29 -> V_137 ;
if ( F_42 ( ! V_2 ) ) {
V_2 = F_93 () ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_27 = 1 ;
V_29 -> V_137 = V_2 ;
}
V_24 = 0 ;
V_135 = 0 ;
V_39 = V_96 -> V_104 ;
V_10 = V_96 -> V_10 ;
V_96 -> V_10 &= ~ V_44 ;
V_98 = V_96 -> V_10 & V_102 ;
while ( V_39 ) {
T_3 V_138 ;
T_2 V_83 = V_96 -> V_83 , V_77 = V_83 ;
V_24 = F_86 ( V_55 , & V_83 , V_2 , V_39 , V_10 ) ;
if ( F_42 ( V_24 <= 0 ) )
goto V_139;
V_138 = V_24 ;
V_96 -> V_104 = V_138 ;
if ( V_138 < V_39 )
V_96 -> V_10 |= V_102 ;
else if ( ! V_98 )
V_96 -> V_10 &= ~ V_102 ;
V_24 = V_108 ( V_2 , V_96 ) ;
if ( F_42 ( V_24 <= 0 ) ) {
V_96 -> V_83 = V_77 ;
goto V_139;
}
V_135 += V_24 ;
V_39 -= V_24 ;
V_96 -> V_83 = V_83 ;
if ( V_24 < V_138 ) {
V_96 -> V_83 = V_77 + V_24 ;
goto V_139;
}
}
V_123:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_52 ( V_55 ) ;
return V_135 ;
V_139:
for ( V_49 = 0 ; V_49 < V_2 -> V_32 ; V_49 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_49 ;
if ( V_4 -> V_41 ) {
V_4 -> V_41 -> V_112 ( V_2 , V_4 ) ;
V_4 -> V_41 = NULL ;
}
}
if ( ! V_135 )
V_135 = V_24 ;
goto V_123;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_54 * V_54 = V_96 -> V_97 . V_54 ;
return F_84 ( V_2 , V_54 , V_96 -> V_140 , V_96 -> V_104 ,
V_96 -> V_10 ) ;
}
long F_95 ( struct V_54 * V_55 , T_2 * V_56 , struct V_54 * V_115 ,
T_2 * V_140 , T_3 V_39 , unsigned int V_10 )
{
struct V_95 V_96 = {
. V_39 = V_39 ,
. V_104 = V_39 ,
. V_10 = V_10 ,
. V_83 = * V_56 ,
. V_97 . V_54 = V_115 ,
. V_140 = V_140 ,
} ;
long V_24 ;
if ( F_42 ( ! ( V_115 -> V_131 & V_141 ) ) )
return - V_133 ;
if ( F_42 ( V_115 -> V_142 & V_143 ) )
return - V_101 ;
V_24 = F_88 ( V_128 , V_115 , V_140 , V_39 ) ;
if ( F_42 ( V_24 < 0 ) )
return V_24 ;
V_24 = F_89 ( V_55 , & V_96 , F_94 ) ;
if ( V_24 > 0 )
* V_56 = V_96 . V_83 ;
return V_24 ;
}
static long F_96 ( struct V_54 * V_55 , T_2 V_85 * V_144 ,
struct V_54 * V_115 , T_2 V_85 * V_145 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_146 ;
struct V_1 * V_147 ;
T_2 V_37 ;
long V_24 ;
V_146 = F_97 ( V_55 ) ;
V_147 = F_97 ( V_115 ) ;
if ( V_146 && V_147 ) {
if ( V_144 || V_145 )
return - V_148 ;
if ( ! ( V_55 -> V_131 & V_132 ) )
return - V_133 ;
if ( ! ( V_115 -> V_131 & V_141 ) )
return - V_133 ;
if ( V_146 == V_147 )
return - V_101 ;
return F_98 ( V_146 , V_147 , V_39 , V_10 ) ;
}
if ( V_146 ) {
if ( V_144 )
return - V_148 ;
if ( V_145 ) {
if ( ! ( V_115 -> V_131 & V_149 ) )
return - V_101 ;
if ( F_99 ( & V_37 , V_145 , sizeof( T_2 ) ) )
return - V_150 ;
} else {
V_37 = V_115 -> V_151 ;
}
if ( F_42 ( ! ( V_115 -> V_131 & V_141 ) ) )
return - V_133 ;
if ( F_42 ( V_115 -> V_142 & V_143 ) )
return - V_101 ;
V_24 = F_88 ( V_128 , V_115 , & V_37 , V_39 ) ;
if ( F_42 ( V_24 < 0 ) )
return V_24 ;
F_100 ( V_115 ) ;
V_24 = F_84 ( V_146 , V_115 , & V_37 , V_39 , V_10 ) ;
F_101 ( V_115 ) ;
if ( ! V_145 )
V_115 -> V_151 = V_37 ;
else if ( F_102 ( V_145 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_150 ;
return V_24 ;
}
if ( V_147 ) {
if ( V_145 )
return - V_148 ;
if ( V_144 ) {
if ( ! ( V_55 -> V_131 & V_152 ) )
return - V_101 ;
if ( F_99 ( & V_37 , V_144 , sizeof( T_2 ) ) )
return - V_150 ;
} else {
V_37 = V_55 -> V_151 ;
}
V_24 = F_86 ( V_55 , & V_37 , V_147 , V_39 , V_10 ) ;
if ( ! V_144 )
V_55 -> V_151 = V_37 ;
else if ( F_102 ( V_144 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_150 ;
return V_24 ;
}
return - V_101 ;
}
static int F_103 ( const struct V_79 V_85 * V_153 ,
unsigned int V_154 , struct V_5 * * V_36 ,
struct V_52 * V_38 , bool V_155 ,
unsigned int V_156 )
{
int V_32 = 0 , error = 0 ;
while ( V_154 ) {
unsigned long V_157 , V_158 ;
struct V_79 V_159 ;
void V_85 * V_160 ;
T_3 V_39 ;
int V_49 ;
error = - V_150 ;
if ( F_99 ( & V_159 , V_153 , sizeof( V_159 ) ) )
break;
V_160 = V_159 . V_93 ;
V_39 = V_159 . V_94 ;
error = 0 ;
if ( F_42 ( ! V_39 ) )
break;
error = - V_150 ;
if ( ! F_104 ( V_161 , V_160 , V_39 ) )
break;
V_157 = ( unsigned long ) V_160 & ~ V_162 ;
error = - V_101 ;
if ( V_155 && ( V_157 || V_39 & ~ V_162 ) )
break;
V_158 = ( V_157 + V_39 + V_163 - 1 ) >> V_164 ;
if ( V_158 > V_156 - V_32 )
V_158 = V_156 - V_32 ;
error = F_105 ( ( unsigned long ) V_160 , V_158 ,
0 , & V_36 [ V_32 ] ) ;
if ( F_42 ( error <= 0 ) )
break;
for ( V_49 = 0 ; V_49 < error ; V_49 ++ ) {
const int V_76 = F_43 ( T_3 , V_39 , V_163 - V_157 ) ;
V_38 [ V_32 ] . V_37 = V_157 ;
V_38 [ V_32 ] . V_39 = V_76 ;
V_157 = 0 ;
V_39 -= V_76 ;
V_32 ++ ;
}
if ( V_39 )
break;
if ( error < V_158 || V_32 == V_156 )
break;
V_154 -- ;
V_153 ++ ;
}
if ( V_32 )
return V_32 ;
return error ;
}
static int F_106 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_95 * V_96 )
{
int V_121 = F_107 ( V_4 -> V_5 , V_4 -> V_37 , V_96 -> V_39 , V_96 -> V_97 . V_129 ) ;
return V_121 == V_96 -> V_39 ? V_121 : - V_150 ;
}
static long F_108 ( struct V_54 * V_54 , const struct V_79 V_85 * V_165 ,
unsigned long V_166 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_95 V_96 ;
long V_24 ;
struct V_79 V_167 [ V_168 ] ;
struct V_79 * V_153 = V_167 ;
struct V_119 V_169 ;
V_2 = F_97 ( V_54 ) ;
if ( ! V_2 )
return - V_133 ;
V_24 = F_109 ( V_134 , V_165 , V_166 ,
F_110 ( V_167 ) , & V_153 , & V_169 ) ;
if ( V_24 < 0 )
return V_24 ;
V_96 . V_104 = F_111 ( & V_169 ) ;
V_96 . V_39 = 0 ;
V_96 . V_10 = V_10 ;
V_96 . V_97 . V_129 = & V_169 ;
V_96 . V_83 = 0 ;
if ( V_96 . V_104 ) {
F_22 ( V_2 ) ;
V_24 = F_71 ( V_2 , & V_96 , F_106 ) ;
F_27 ( V_2 ) ;
}
F_32 ( V_153 ) ;
return V_24 ;
}
static long F_112 ( struct V_54 * V_54 , const struct V_79 V_85 * V_153 ,
unsigned long V_166 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_170 ,
. V_48 = F_28 ,
} ;
long V_24 ;
V_2 = F_97 ( V_54 ) ;
if ( ! V_2 )
return - V_133 ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_21 . V_23 = F_103 ( V_153 , V_166 , V_21 . V_36 ,
V_21 . V_38 , false ,
V_21 . V_50 ) ;
if ( V_21 . V_23 <= 0 )
V_24 = V_21 . V_23 ;
else
V_24 = F_21 ( V_2 , & V_21 ) ;
F_33 ( & V_21 ) ;
return V_24 ;
}
static int F_113 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 )
return 0 ;
V_24 = 0 ;
F_22 ( V_2 ) ;
while ( ! V_2 -> V_31 ) {
if ( F_24 ( V_29 ) ) {
V_24 = - V_46 ;
break;
}
if ( ! V_2 -> V_114 )
break;
if ( ! V_2 -> V_47 ) {
if ( V_10 & V_44 ) {
V_24 = - V_45 ;
break;
}
}
F_26 ( V_2 ) ;
}
F_27 ( V_2 ) ;
return V_24 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 < V_2 -> V_32 )
return 0 ;
V_24 = 0 ;
F_22 ( V_2 ) ;
while ( V_2 -> V_31 >= V_2 -> V_32 ) {
if ( ! V_2 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
V_24 = - V_30 ;
break;
}
if ( V_10 & V_44 ) {
V_24 = - V_45 ;
break;
}
if ( F_24 ( V_29 ) ) {
V_24 = - V_46 ;
break;
}
V_2 -> V_47 ++ ;
F_26 ( V_2 ) ;
V_2 -> V_47 -- ;
}
F_27 ( V_2 ) ;
return V_24 ;
}
static int F_98 ( struct V_1 * V_146 ,
struct V_1 * V_147 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_171 , * V_172 ;
int V_24 = 0 , V_173 ;
bool V_174 = false ;
V_175:
V_24 = F_113 ( V_146 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_114 ( V_147 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_115 ( V_146 , V_147 ) ;
do {
if ( ! V_147 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( ! V_146 -> V_31 && ! V_146 -> V_114 )
break;
if ( ! V_146 -> V_31 || V_147 -> V_31 >= V_147 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_44 ) {
V_24 = - V_45 ;
break;
}
F_27 ( V_146 ) ;
F_27 ( V_147 ) ;
goto V_175;
}
V_171 = V_146 -> V_35 + V_146 -> V_34 ;
V_173 = ( V_147 -> V_34 + V_147 -> V_31 ) & ( V_147 -> V_32 - 1 ) ;
V_172 = V_147 -> V_35 + V_173 ;
if ( V_39 >= V_171 -> V_39 ) {
* V_172 = * V_171 ;
V_171 -> V_41 = NULL ;
V_147 -> V_31 ++ ;
V_146 -> V_34 = ( V_146 -> V_34 + 1 ) & ( V_146 -> V_32 - 1 ) ;
V_146 -> V_31 -- ;
V_174 = true ;
} else {
V_171 -> V_41 -> V_176 ( V_146 , V_171 ) ;
* V_172 = * V_171 ;
V_172 -> V_10 &= ~ V_15 ;
V_172 -> V_39 = V_39 ;
V_147 -> V_31 ++ ;
V_171 -> V_37 += V_172 -> V_39 ;
V_171 -> V_39 -= V_172 -> V_39 ;
}
V_24 += V_172 -> V_39 ;
V_39 -= V_172 -> V_39 ;
} while ( V_39 );
F_27 ( V_146 ) ;
F_27 ( V_147 ) ;
if ( V_24 > 0 )
F_16 ( V_147 ) ;
if ( V_174 )
F_66 ( V_146 ) ;
return V_24 ;
}
static int F_116 ( struct V_1 * V_146 ,
struct V_1 * V_147 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_171 , * V_172 ;
int V_24 = 0 , V_49 = 0 , V_173 ;
F_115 ( V_146 , V_147 ) ;
do {
if ( ! V_147 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( V_49 >= V_146 -> V_31 || V_147 -> V_31 >= V_147 -> V_32 )
break;
V_171 = V_146 -> V_35 + ( ( V_146 -> V_34 + V_49 ) & ( V_146 -> V_32 - 1 ) ) ;
V_173 = ( V_147 -> V_34 + V_147 -> V_31 ) & ( V_147 -> V_32 - 1 ) ;
V_171 -> V_41 -> V_176 ( V_146 , V_171 ) ;
V_172 = V_147 -> V_35 + V_173 ;
* V_172 = * V_171 ;
V_172 -> V_10 &= ~ V_15 ;
if ( V_172 -> V_39 > V_39 )
V_172 -> V_39 = V_39 ;
V_147 -> V_31 ++ ;
V_24 += V_172 -> V_39 ;
V_39 -= V_172 -> V_39 ;
V_49 ++ ;
} while ( V_39 );
if ( ! V_24 && V_146 -> V_47 && ( V_10 & V_44 ) )
V_24 = - V_45 ;
F_27 ( V_146 ) ;
F_27 ( V_147 ) ;
if ( V_24 > 0 )
F_16 ( V_147 ) ;
return V_24 ;
}
static long F_117 ( struct V_54 * V_55 , struct V_54 * V_115 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_146 = F_97 ( V_55 ) ;
struct V_1 * V_147 = F_97 ( V_115 ) ;
int V_24 = - V_101 ;
if ( V_146 && V_147 && V_146 != V_147 ) {
V_24 = F_113 ( V_146 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_114 ( V_147 , V_10 ) ;
if ( ! V_24 )
V_24 = F_116 ( V_146 , V_147 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
