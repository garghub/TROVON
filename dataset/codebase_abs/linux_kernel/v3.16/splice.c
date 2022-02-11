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
V_8 ) ;
if ( F_41 ( error ) ) {
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
V_69 = F_42 (unsigned long, len, PAGE_CACHE_SIZE - loff) ;
V_5 = V_21 . V_36 [ V_26 ] ;
if ( F_43 ( V_5 ) )
F_44 ( V_7 , & V_55 -> V_67 , V_55 ,
V_5 , V_60 , V_59 - V_26 ) ;
if ( ! F_5 ( V_5 ) ) {
F_2 ( V_5 ) ;
if ( ! V_5 -> V_7 ) {
F_10 ( V_5 ) ;
V_5 = F_45 ( V_7 , V_60 ,
F_46 ( V_7 ) ) ;
if ( ! V_5 ) {
error = - V_53 ;
break;
}
F_12 ( V_21 . V_36 [ V_26 ] ) ;
V_21 . V_36 [ V_26 ] = V_5 ;
}
if ( F_5 ( V_5 ) ) {
F_10 ( V_5 ) ;
goto V_70;
}
error = V_7 -> V_71 -> V_72 ( V_55 , V_5 ) ;
if ( F_41 ( error ) ) {
if ( error == V_73 )
error = 0 ;
break;
}
}
V_70:
V_62 = F_47 ( V_7 -> V_74 ) ;
V_61 = ( V_62 - 1 ) >> V_64 ;
if ( F_41 ( ! V_62 || V_60 > V_61 ) )
break;
if ( V_61 == V_60 ) {
unsigned int V_75 ;
V_75 = ( ( V_62 - 1 ) & ~ V_65 ) + 1 ;
if ( V_75 <= V_58 )
break;
V_69 = F_35 ( V_69 , V_75 - V_58 ) ;
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
V_55 -> V_67 . V_76 = ( T_2 ) V_60 << V_64 ;
if ( V_21 . V_23 )
error = F_21 ( V_2 , & V_21 ) ;
F_33 ( & V_21 ) ;
return error ;
}
T_1 F_48 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_2 V_62 , V_77 ;
int V_24 ;
V_62 = F_47 ( V_55 -> V_57 -> V_74 ) ;
if ( F_41 ( * V_56 >= V_62 ) )
return 0 ;
V_77 = V_62 - * V_56 ;
if ( F_41 ( V_77 < V_39 ) )
V_39 = V_77 ;
V_24 = F_34 ( V_55 , V_56 , V_2 , V_39 , V_10 ) ;
if ( V_24 > 0 ) {
* V_56 += V_24 ;
F_49 ( V_55 ) ;
}
return V_24 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static T_1 F_51 ( struct V_54 * V_54 , const struct V_78 * V_79 ,
unsigned long V_80 , T_2 V_37 )
{
T_5 V_81 ;
T_2 V_82 = V_37 ;
T_1 V_83 ;
V_81 = F_52 () ;
F_53 ( F_54 () ) ;
V_83 = F_55 ( V_54 , ( const struct V_78 V_84 * ) V_79 , V_80 , & V_82 ) ;
F_53 ( V_81 ) ;
return V_83 ;
}
T_1 F_56 ( struct V_54 * V_54 , const char * V_4 , T_3 V_85 ,
T_2 V_82 )
{
T_5 V_81 ;
T_1 V_83 ;
V_81 = F_52 () ;
F_53 ( F_54 () ) ;
V_83 = F_57 ( V_54 , ( V_86 const char V_84 * ) V_4 , V_85 , & V_82 ) ;
F_53 ( V_81 ) ;
return V_83 ;
}
T_1 F_58 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
unsigned int V_23 ;
unsigned int V_87 ;
T_3 V_37 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_78 * V_79 , V_88 [ V_51 ] ;
T_1 V_83 ;
T_3 V_69 ;
int error ;
int V_49 ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_89 ,
. V_48 = F_28 ,
} ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_83 = - V_53 ;
V_79 = V_88 ;
if ( V_21 . V_50 > V_51 ) {
V_79 = F_31 ( V_21 . V_50 * sizeof( struct V_78 ) , V_8 ) ;
if ( ! V_79 )
goto V_90;
}
V_37 = * V_56 & ~ V_65 ;
V_23 = ( V_39 + V_37 + V_66 - 1 ) >> V_64 ;
for ( V_49 = 0 ; V_49 < V_23 && V_49 < V_21 . V_50 && V_39 ; V_49 ++ ) {
struct V_5 * V_5 ;
V_5 = F_59 ( V_91 ) ;
error = - V_53 ;
if ( ! V_5 )
goto V_12;
V_69 = F_42 ( T_3 , V_39 , V_66 - V_37 ) ;
V_79 [ V_49 ] . V_92 = ( void V_84 * ) F_60 ( V_5 ) ;
V_79 [ V_49 ] . V_93 = V_69 ;
V_21 . V_36 [ V_49 ] = V_5 ;
V_21 . V_23 ++ ;
V_39 -= V_69 ;
V_37 = 0 ;
}
V_83 = F_51 ( V_55 , V_79 , V_21 . V_23 , * V_56 ) ;
if ( V_83 < 0 ) {
error = V_83 ;
goto V_12;
}
error = 0 ;
if ( ! V_83 )
goto V_12;
V_87 = 0 ;
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ ) {
V_69 = F_42 ( T_3 , V_79 [ V_49 ] . V_93 , V_83 ) ;
V_21 . V_38 [ V_49 ] . V_37 = 0 ;
V_21 . V_38 [ V_49 ] . V_39 = V_69 ;
if ( ! V_69 ) {
F_61 ( V_21 . V_36 [ V_49 ] ) ;
V_21 . V_36 [ V_49 ] = NULL ;
V_87 ++ ;
}
V_83 -= V_69 ;
}
V_21 . V_23 -= V_87 ;
V_83 = F_21 ( V_2 , & V_21 ) ;
if ( V_83 > 0 )
* V_56 += V_83 ;
V_90:
if ( V_79 != V_88 )
F_32 ( V_79 ) ;
F_33 ( & V_21 ) ;
return V_83 ;
V_12:
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ )
F_61 ( V_21 . V_36 [ V_49 ] ) ;
V_83 = error ;
goto V_90;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_94 * V_95 )
{
struct V_54 * V_54 = V_95 -> V_96 . V_54 ;
T_2 V_82 = V_95 -> V_82 ;
int V_97 ;
if ( ! F_63 ( V_54 -> V_98 -> V_99 ) )
return - V_100 ;
V_97 = ( V_95 -> V_10 & V_101 ) ? V_102 : 0 ;
if ( V_95 -> V_39 < V_95 -> V_103 && V_2 -> V_31 > 1 )
V_97 |= V_104 ;
return V_54 -> V_98 -> V_99 ( V_54 , V_4 -> V_5 , V_4 -> V_37 ,
V_95 -> V_39 , & V_82 , V_97 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_105 , V_18 , V_106 ) ;
}
static int F_65 ( struct V_1 * V_2 , struct V_94 * V_95 ,
T_6 * V_107 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
const struct V_108 * V_41 = V_4 -> V_41 ;
V_95 -> V_39 = V_4 -> V_39 ;
if ( V_95 -> V_39 > V_95 -> V_103 )
V_95 -> V_39 = V_95 -> V_103 ;
V_24 = V_4 -> V_41 -> V_109 ( V_2 , V_4 ) ;
if ( F_41 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_107 ( V_2 , V_4 , V_95 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_95 -> V_110 += V_24 ;
V_95 -> V_39 -= V_24 ;
V_95 -> V_82 += V_24 ;
V_95 -> V_103 -= V_24 ;
if ( ! V_4 -> V_39 ) {
V_4 -> V_41 = NULL ;
V_41 -> V_111 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_43 )
V_95 -> V_112 = true ;
}
if ( ! V_95 -> V_103 )
return 0 ;
}
return 1 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_113 )
return 0 ;
if ( ! V_2 -> V_47 && V_95 -> V_110 )
return 0 ;
if ( V_95 -> V_10 & V_44 )
return - V_45 ;
if ( F_24 ( V_29 ) )
return - V_46 ;
if ( V_95 -> V_112 ) {
F_64 ( V_2 ) ;
V_95 -> V_112 = false ;
}
F_26 ( V_2 ) ;
}
return 1 ;
}
static void F_67 ( struct V_94 * V_95 )
{
V_95 -> V_110 = 0 ;
V_95 -> V_112 = false ;
}
static void F_68 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
if ( V_95 -> V_112 )
F_64 ( V_2 ) ;
}
T_1 F_69 ( struct V_1 * V_2 , struct V_94 * V_95 ,
T_6 * V_107 )
{
int V_24 ;
F_67 ( V_95 ) ;
do {
V_24 = F_66 ( V_2 , V_95 ) ;
if ( V_24 > 0 )
V_24 = F_65 ( V_2 , V_95 , V_107 ) ;
} while ( V_24 > 0 );
F_68 ( V_2 , V_95 ) ;
return V_95 -> V_110 ? V_95 -> V_110 : V_24 ;
}
T_1 F_70 ( struct V_1 * V_2 , struct V_54 * V_114 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 ,
T_6 * V_107 )
{
T_1 V_24 ;
struct V_94 V_95 = {
. V_103 = V_39 ,
. V_10 = V_10 ,
. V_82 = * V_56 ,
. V_96 . V_54 = V_114 ,
} ;
F_22 ( V_2 ) ;
V_24 = F_69 ( V_2 , & V_95 , V_107 ) ;
F_27 ( V_2 ) ;
return V_24 ;
}
T_1
F_71 ( struct V_1 * V_2 , struct V_54 * V_114 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
struct V_94 V_95 = {
. V_103 = V_39 ,
. V_10 = V_10 ,
. V_82 = * V_56 ,
. V_96 . V_54 = V_114 ,
} ;
int V_115 = V_2 -> V_32 ;
struct V_116 * V_117 = F_72 ( V_115 , sizeof( struct V_116 ) ,
V_8 ) ;
T_1 V_24 ;
if ( F_41 ( ! V_117 ) )
return - V_53 ;
F_22 ( V_2 ) ;
F_67 ( & V_95 ) ;
while ( V_95 . V_103 ) {
struct V_118 V_119 ;
struct V_120 V_120 ;
T_3 V_77 ;
int V_121 , V_122 ;
V_24 = F_66 ( V_2 , & V_95 ) ;
if ( V_24 <= 0 )
break;
if ( F_41 ( V_115 < V_2 -> V_32 ) ) {
F_32 ( V_117 ) ;
V_115 = V_2 -> V_32 ;
V_117 = F_72 ( V_115 , sizeof( struct V_116 ) ,
V_8 ) ;
if ( ! V_117 ) {
V_24 = - V_53 ;
break;
}
}
V_77 = V_95 . V_103 ;
for ( V_121 = 0 , V_122 = V_2 -> V_34 ; V_77 && V_121 < V_2 -> V_31 ; V_121 ++ , V_122 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_122 ;
T_3 V_69 = V_4 -> V_39 ;
if ( V_69 > V_77 )
V_69 = V_77 ;
if ( V_122 == V_2 -> V_32 - 1 )
V_122 = - 1 ;
V_24 = V_4 -> V_41 -> V_109 ( V_2 , V_4 ) ;
if ( F_41 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
goto V_123;
}
V_117 [ V_121 ] . V_124 = V_4 -> V_5 ;
V_117 [ V_121 ] . V_125 = V_69 ;
V_117 [ V_121 ] . V_126 = V_4 -> V_37 ;
V_77 -= V_69 ;
}
V_119 . type = V_127 | V_128 ;
V_119 . V_129 = V_117 ;
V_119 . V_130 = V_121 ;
V_119 . V_85 = V_95 . V_103 - V_77 ;
V_119 . V_131 = 0 ;
F_73 ( & V_120 , V_114 ) ;
V_120 . V_132 = V_95 . V_82 ;
V_120 . V_133 = V_95 . V_103 - V_77 ;
V_24 = V_114 -> V_98 -> V_134 ( & V_120 , & V_119 ) ;
if ( - V_135 == V_24 )
V_24 = F_74 ( & V_120 ) ;
if ( V_24 <= 0 )
break;
V_95 . V_110 += V_24 ;
V_95 . V_103 -= V_24 ;
* V_56 = V_95 . V_82 = V_120 . V_132 ;
while ( V_24 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
if ( V_24 >= V_4 -> V_39 ) {
const struct V_108 * V_41 = V_4 -> V_41 ;
V_24 -= V_4 -> V_39 ;
V_4 -> V_39 = 0 ;
V_4 -> V_41 = NULL ;
V_41 -> V_111 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_43 )
V_95 . V_112 = true ;
} else {
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_24 = 0 ;
}
}
}
V_123:
F_32 ( V_117 ) ;
F_68 ( V_2 , & V_95 ) ;
F_27 ( V_2 ) ;
if ( V_95 . V_110 )
V_24 = V_95 . V_110 ;
return V_24 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_94 * V_95 )
{
int V_24 ;
void * V_136 ;
T_2 V_137 = V_95 -> V_82 ;
V_136 = F_76 ( V_4 -> V_5 ) ;
V_24 = F_77 ( V_95 -> V_96 . V_54 , V_136 + V_4 -> V_37 , V_95 -> V_39 , & V_137 ) ;
F_78 ( V_4 -> V_5 ) ;
return V_24 ;
}
static T_1 F_79 ( struct V_1 * V_2 ,
struct V_54 * V_114 , T_2 * V_56 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_70 ( V_2 , V_114 , V_56 , V_39 , V_10 , F_75 ) ;
if ( V_24 > 0 )
* V_56 += V_24 ;
return V_24 ;
}
T_1 F_80 ( struct V_1 * V_2 , struct V_54 * V_114 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
return F_70 ( V_2 , V_114 , V_56 , V_39 , V_10 , F_62 ) ;
}
static long F_81 ( struct V_1 * V_2 , struct V_54 * V_114 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_82)( struct V_1 * , struct V_54 * ,
T_2 * , T_3 , unsigned int );
if ( V_114 -> V_98 -> F_82 )
F_82 = V_114 -> V_98 -> F_82 ;
else
F_82 = F_79 ;
return F_82 ( V_2 , V_114 , V_56 , V_39 , V_10 ) ;
}
static long F_83 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_84)( struct V_54 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_41 ( ! ( V_55 -> V_138 & V_139 ) ) )
return - V_140 ;
V_24 = F_85 ( V_141 , V_55 , V_56 , V_39 ) ;
if ( F_41 ( V_24 < 0 ) )
return V_24 ;
if ( V_55 -> V_98 -> F_84 )
F_84 = V_55 -> V_98 -> F_84 ;
else
F_84 = F_58 ;
return F_84 ( V_55 , V_56 , V_2 , V_39 , V_10 ) ;
}
T_1 F_86 ( struct V_54 * V_55 , struct V_94 * V_95 ,
T_7 * V_107 )
{
struct V_1 * V_2 ;
long V_24 , V_142 ;
T_8 V_143 ;
T_3 V_39 ;
int V_49 , V_10 ;
V_143 = F_87 ( V_55 ) -> V_143 ;
if ( F_41 ( ! F_88 ( V_143 ) && ! F_89 ( V_143 ) ) )
return - V_100 ;
V_2 = V_29 -> V_144 ;
if ( F_41 ( ! V_2 ) ) {
V_2 = F_90 () ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_27 = 1 ;
V_29 -> V_144 = V_2 ;
}
V_24 = 0 ;
V_142 = 0 ;
V_39 = V_95 -> V_103 ;
V_10 = V_95 -> V_10 ;
V_95 -> V_10 &= ~ V_44 ;
while ( V_39 ) {
T_3 V_145 ;
T_2 V_82 = V_95 -> V_82 , V_76 = V_82 ;
V_24 = F_83 ( V_55 , & V_82 , V_2 , V_39 , V_10 ) ;
if ( F_41 ( V_24 <= 0 ) )
goto V_146;
V_145 = V_24 ;
V_95 -> V_103 = V_145 ;
V_24 = V_107 ( V_2 , V_95 ) ;
if ( F_41 ( V_24 <= 0 ) ) {
V_95 -> V_82 = V_76 ;
goto V_146;
}
V_142 += V_24 ;
V_39 -= V_24 ;
V_95 -> V_82 = V_82 ;
if ( V_24 < V_145 ) {
V_95 -> V_82 = V_76 + V_24 ;
goto V_146;
}
}
V_123:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_49 ( V_55 ) ;
return V_142 ;
V_146:
for ( V_49 = 0 ; V_49 < V_2 -> V_32 ; V_49 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_49 ;
if ( V_4 -> V_41 ) {
V_4 -> V_41 -> V_111 ( V_2 , V_4 ) ;
V_4 -> V_41 = NULL ;
}
}
if ( ! V_142 )
V_142 = V_24 ;
goto V_123;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_54 * V_54 = V_95 -> V_96 . V_54 ;
return F_81 ( V_2 , V_54 , V_95 -> V_147 , V_95 -> V_103 ,
V_95 -> V_10 ) ;
}
long F_92 ( struct V_54 * V_55 , T_2 * V_56 , struct V_54 * V_114 ,
T_2 * V_147 , T_3 V_39 , unsigned int V_10 )
{
struct V_94 V_95 = {
. V_39 = V_39 ,
. V_103 = V_39 ,
. V_10 = V_10 ,
. V_82 = * V_56 ,
. V_96 . V_54 = V_114 ,
. V_147 = V_147 ,
} ;
long V_24 ;
if ( F_41 ( ! ( V_114 -> V_138 & V_148 ) ) )
return - V_140 ;
if ( F_41 ( V_114 -> V_149 & V_150 ) )
return - V_100 ;
V_24 = F_85 ( V_128 , V_114 , V_147 , V_39 ) ;
if ( F_41 ( V_24 < 0 ) )
return V_24 ;
V_24 = F_86 ( V_55 , & V_95 , F_91 ) ;
if ( V_24 > 0 )
* V_56 = V_95 . V_82 ;
return V_24 ;
}
static long F_93 ( struct V_54 * V_55 , T_2 V_84 * V_151 ,
struct V_54 * V_114 , T_2 V_84 * V_152 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_153 ;
struct V_1 * V_154 ;
T_2 V_37 ;
long V_24 ;
V_153 = F_94 ( V_55 ) ;
V_154 = F_94 ( V_114 ) ;
if ( V_153 && V_154 ) {
if ( V_151 || V_152 )
return - V_155 ;
if ( ! ( V_55 -> V_138 & V_139 ) )
return - V_140 ;
if ( ! ( V_114 -> V_138 & V_148 ) )
return - V_140 ;
if ( V_153 == V_154 )
return - V_100 ;
return F_95 ( V_153 , V_154 , V_39 , V_10 ) ;
}
if ( V_153 ) {
if ( V_151 )
return - V_155 ;
if ( V_152 ) {
if ( ! ( V_114 -> V_138 & V_156 ) )
return - V_100 ;
if ( F_96 ( & V_37 , V_152 , sizeof( T_2 ) ) )
return - V_157 ;
} else {
V_37 = V_114 -> V_158 ;
}
if ( F_41 ( ! ( V_114 -> V_138 & V_148 ) ) )
return - V_140 ;
if ( F_41 ( V_114 -> V_149 & V_150 ) )
return - V_100 ;
V_24 = F_85 ( V_128 , V_114 , & V_37 , V_39 ) ;
if ( F_41 ( V_24 < 0 ) )
return V_24 ;
F_97 ( V_114 ) ;
V_24 = F_81 ( V_153 , V_114 , & V_37 , V_39 , V_10 ) ;
F_98 ( V_114 ) ;
if ( ! V_152 )
V_114 -> V_158 = V_37 ;
else if ( F_99 ( V_152 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_157 ;
return V_24 ;
}
if ( V_154 ) {
if ( V_152 )
return - V_155 ;
if ( V_151 ) {
if ( ! ( V_55 -> V_138 & V_159 ) )
return - V_100 ;
if ( F_96 ( & V_37 , V_151 , sizeof( T_2 ) ) )
return - V_157 ;
} else {
V_37 = V_55 -> V_158 ;
}
V_24 = F_83 ( V_55 , & V_37 , V_154 , V_39 , V_10 ) ;
if ( ! V_151 )
V_55 -> V_158 = V_37 ;
else if ( F_99 ( V_151 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_157 ;
return V_24 ;
}
return - V_100 ;
}
static int F_100 ( const struct V_78 V_84 * V_160 ,
unsigned int V_161 , struct V_5 * * V_36 ,
struct V_52 * V_38 , bool V_162 ,
unsigned int V_163 )
{
int V_32 = 0 , error = 0 ;
while ( V_161 ) {
unsigned long V_164 , V_165 ;
struct V_78 V_166 ;
void V_84 * V_167 ;
T_3 V_39 ;
int V_49 ;
error = - V_157 ;
if ( F_96 ( & V_166 , V_160 , sizeof( V_166 ) ) )
break;
V_167 = V_166 . V_92 ;
V_39 = V_166 . V_93 ;
error = 0 ;
if ( F_41 ( ! V_39 ) )
break;
error = - V_157 ;
if ( ! F_101 ( V_168 , V_167 , V_39 ) )
break;
V_164 = ( unsigned long ) V_167 & ~ V_169 ;
error = - V_100 ;
if ( V_162 && ( V_164 || V_39 & ~ V_169 ) )
break;
V_165 = ( V_164 + V_39 + V_170 - 1 ) >> V_171 ;
if ( V_165 > V_163 - V_32 )
V_165 = V_163 - V_32 ;
error = F_102 ( ( unsigned long ) V_167 , V_165 ,
0 , & V_36 [ V_32 ] ) ;
if ( F_41 ( error <= 0 ) )
break;
for ( V_49 = 0 ; V_49 < error ; V_49 ++ ) {
const int V_75 = F_42 ( T_3 , V_39 , V_170 - V_164 ) ;
V_38 [ V_32 ] . V_37 = V_164 ;
V_38 [ V_32 ] . V_39 = V_75 ;
V_164 = 0 ;
V_39 -= V_75 ;
V_32 ++ ;
}
if ( V_39 )
break;
if ( error < V_165 || V_32 == V_163 )
break;
V_161 -- ;
V_160 ++ ;
}
if ( V_32 )
return V_32 ;
return error ;
}
static int F_103 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_94 * V_95 )
{
int V_121 = F_104 ( V_4 -> V_5 , V_4 -> V_37 , V_95 -> V_39 , V_95 -> V_96 . V_136 ) ;
return V_121 == V_95 -> V_39 ? V_121 : - V_157 ;
}
static long F_105 ( struct V_54 * V_54 , const struct V_78 V_84 * V_172 ,
unsigned long V_130 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_94 V_95 ;
long V_24 ;
struct V_78 V_173 [ V_174 ] ;
struct V_78 * V_160 = V_173 ;
struct V_118 V_175 ;
T_1 V_85 ;
V_2 = F_94 ( V_54 ) ;
if ( ! V_2 )
return - V_140 ;
V_24 = F_106 ( V_141 , V_172 , V_130 ,
F_107 ( V_173 ) , V_173 , & V_160 ) ;
if ( V_24 <= 0 )
goto V_114;
V_85 = V_24 ;
F_108 ( & V_175 , V_141 , V_160 , V_130 , V_85 ) ;
V_95 . V_39 = 0 ;
V_95 . V_103 = V_85 ;
V_95 . V_10 = V_10 ;
V_95 . V_96 . V_136 = & V_175 ;
V_95 . V_82 = 0 ;
F_22 ( V_2 ) ;
V_24 = F_69 ( V_2 , & V_95 , F_103 ) ;
F_27 ( V_2 ) ;
V_114:
if ( V_160 != V_173 )
F_32 ( V_160 ) ;
return V_24 ;
}
static long F_109 ( struct V_54 * V_54 , const struct V_78 V_84 * V_160 ,
unsigned long V_130 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_176 ,
. V_48 = F_28 ,
} ;
long V_24 ;
V_2 = F_94 ( V_54 ) ;
if ( ! V_2 )
return - V_140 ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_21 . V_23 = F_100 ( V_160 , V_130 , V_21 . V_36 ,
V_21 . V_38 , false ,
V_21 . V_50 ) ;
if ( V_21 . V_23 <= 0 )
V_24 = V_21 . V_23 ;
else
V_24 = F_21 ( V_2 , & V_21 ) ;
F_33 ( & V_21 ) ;
return V_24 ;
}
static int F_110 ( struct V_1 * V_2 , unsigned int V_10 )
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
if ( ! V_2 -> V_113 )
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
static int F_111 ( struct V_1 * V_2 , unsigned int V_10 )
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
static int F_95 ( struct V_1 * V_153 ,
struct V_1 * V_154 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_177 , * V_178 ;
int V_24 = 0 , V_179 ;
bool V_180 = false ;
V_181:
V_24 = F_110 ( V_153 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_111 ( V_154 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_112 ( V_153 , V_154 ) ;
do {
if ( ! V_154 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( ! V_153 -> V_31 && ! V_153 -> V_113 )
break;
if ( ! V_153 -> V_31 || V_154 -> V_31 >= V_154 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_44 ) {
V_24 = - V_45 ;
break;
}
F_27 ( V_153 ) ;
F_27 ( V_154 ) ;
goto V_181;
}
V_177 = V_153 -> V_35 + V_153 -> V_34 ;
V_179 = ( V_154 -> V_34 + V_154 -> V_31 ) & ( V_154 -> V_32 - 1 ) ;
V_178 = V_154 -> V_35 + V_179 ;
if ( V_39 >= V_177 -> V_39 ) {
* V_178 = * V_177 ;
V_177 -> V_41 = NULL ;
V_154 -> V_31 ++ ;
V_153 -> V_34 = ( V_153 -> V_34 + 1 ) & ( V_153 -> V_32 - 1 ) ;
V_153 -> V_31 -- ;
V_180 = true ;
} else {
V_177 -> V_41 -> V_182 ( V_153 , V_177 ) ;
* V_178 = * V_177 ;
V_178 -> V_10 &= ~ V_15 ;
V_178 -> V_39 = V_39 ;
V_154 -> V_31 ++ ;
V_177 -> V_37 += V_178 -> V_39 ;
V_177 -> V_39 -= V_178 -> V_39 ;
}
V_24 += V_178 -> V_39 ;
V_39 -= V_178 -> V_39 ;
} while ( V_39 );
F_27 ( V_153 ) ;
F_27 ( V_154 ) ;
if ( V_24 > 0 )
F_16 ( V_154 ) ;
if ( V_180 )
F_64 ( V_153 ) ;
return V_24 ;
}
static int F_113 ( struct V_1 * V_153 ,
struct V_1 * V_154 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_177 , * V_178 ;
int V_24 = 0 , V_49 = 0 , V_179 ;
F_112 ( V_153 , V_154 ) ;
do {
if ( ! V_154 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( V_49 >= V_153 -> V_31 || V_154 -> V_31 >= V_154 -> V_32 )
break;
V_177 = V_153 -> V_35 + ( ( V_153 -> V_34 + V_49 ) & ( V_153 -> V_32 - 1 ) ) ;
V_179 = ( V_154 -> V_34 + V_154 -> V_31 ) & ( V_154 -> V_32 - 1 ) ;
V_177 -> V_41 -> V_182 ( V_153 , V_177 ) ;
V_178 = V_154 -> V_35 + V_179 ;
* V_178 = * V_177 ;
V_178 -> V_10 &= ~ V_15 ;
if ( V_178 -> V_39 > V_39 )
V_178 -> V_39 = V_39 ;
V_154 -> V_31 ++ ;
V_24 += V_178 -> V_39 ;
V_39 -= V_178 -> V_39 ;
V_49 ++ ;
} while ( V_39 );
if ( ! V_24 && V_153 -> V_47 && ( V_10 & V_44 ) )
V_24 = - V_45 ;
F_27 ( V_153 ) ;
F_27 ( V_154 ) ;
if ( V_24 > 0 )
F_16 ( V_154 ) ;
return V_24 ;
}
static long F_114 ( struct V_54 * V_55 , struct V_54 * V_114 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_153 = F_94 ( V_55 ) ;
struct V_1 * V_154 = F_94 ( V_114 ) ;
int V_24 = - V_100 ;
if ( V_153 && V_154 && V_153 != V_154 ) {
V_24 = F_110 ( V_153 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_111 ( V_154 , V_10 ) ;
if ( ! V_24 )
V_24 = F_113 ( V_153 , V_154 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
