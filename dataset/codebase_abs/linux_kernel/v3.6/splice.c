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
static T_1 F_50 ( struct V_54 * V_54 , const struct V_78 * V_79 ,
unsigned long V_80 , T_2 V_37 )
{
T_5 V_81 ;
T_2 V_82 = V_37 ;
T_1 V_83 ;
V_81 = F_51 () ;
F_52 ( F_53 () ) ;
V_83 = F_54 ( V_54 , ( const struct V_78 V_84 * ) V_79 , V_80 , & V_82 ) ;
F_52 ( V_81 ) ;
return V_83 ;
}
static T_1 F_55 ( struct V_54 * V_54 , const char * V_4 , T_3 V_85 ,
T_2 V_82 )
{
T_5 V_81 ;
T_1 V_83 ;
V_81 = F_51 () ;
F_52 ( F_53 () ) ;
V_83 = F_56 ( V_54 , ( const char V_84 * ) V_4 , V_85 , & V_82 ) ;
F_52 ( V_81 ) ;
return V_83 ;
}
T_1 F_57 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
unsigned int V_23 ;
unsigned int V_86 ;
T_3 V_37 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_78 * V_79 , V_87 [ V_51 ] ;
T_1 V_83 ;
T_3 V_69 ;
int error ;
int V_49 ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_88 ,
. V_48 = F_28 ,
} ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_83 = - V_53 ;
V_79 = V_87 ;
if ( V_21 . V_50 > V_51 ) {
V_79 = F_31 ( V_21 . V_50 * sizeof( struct V_78 ) , V_8 ) ;
if ( ! V_79 )
goto V_89;
}
V_37 = * V_56 & ~ V_65 ;
V_23 = ( V_39 + V_37 + V_66 - 1 ) >> V_64 ;
for ( V_49 = 0 ; V_49 < V_23 && V_49 < V_21 . V_50 && V_39 ; V_49 ++ ) {
struct V_5 * V_5 ;
V_5 = F_58 ( V_90 ) ;
error = - V_53 ;
if ( ! V_5 )
goto V_12;
V_69 = F_42 ( T_3 , V_39 , V_66 - V_37 ) ;
V_79 [ V_49 ] . V_91 = ( void V_84 * ) F_59 ( V_5 ) ;
V_79 [ V_49 ] . V_92 = V_69 ;
V_21 . V_36 [ V_49 ] = V_5 ;
V_21 . V_23 ++ ;
V_39 -= V_69 ;
V_37 = 0 ;
}
V_83 = F_50 ( V_55 , V_79 , V_21 . V_23 , * V_56 ) ;
if ( V_83 < 0 ) {
error = V_83 ;
goto V_12;
}
error = 0 ;
if ( ! V_83 )
goto V_12;
V_86 = 0 ;
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ ) {
V_69 = F_42 ( T_3 , V_79 [ V_49 ] . V_92 , V_83 ) ;
V_21 . V_38 [ V_49 ] . V_37 = 0 ;
V_21 . V_38 [ V_49 ] . V_39 = V_69 ;
if ( ! V_69 ) {
F_60 ( V_21 . V_36 [ V_49 ] ) ;
V_21 . V_36 [ V_49 ] = NULL ;
V_86 ++ ;
}
V_83 -= V_69 ;
}
V_21 . V_23 -= V_86 ;
V_83 = F_21 ( V_2 , & V_21 ) ;
if ( V_83 > 0 )
* V_56 += V_83 ;
V_89:
if ( V_79 != V_87 )
F_32 ( V_79 ) ;
F_33 ( & V_21 ) ;
return V_83 ;
V_12:
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ )
F_60 ( V_21 . V_36 [ V_49 ] ) ;
V_83 = error ;
goto V_89;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_93 * V_94 )
{
struct V_54 * V_54 = V_94 -> V_95 . V_54 ;
T_2 V_82 = V_94 -> V_82 ;
int V_96 ;
if ( ! F_62 ( V_54 -> V_97 && V_54 -> V_97 -> V_98 ) )
return - V_99 ;
V_96 = ( V_94 -> V_10 & V_100 ) ? V_101 : 0 ;
if ( V_94 -> V_39 < V_94 -> V_102 )
V_96 |= V_103 ;
return V_54 -> V_97 -> V_98 ( V_54 , V_4 -> V_5 , V_4 -> V_37 ,
V_94 -> V_39 , & V_82 , V_96 ) ;
}
int F_63 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
struct V_54 * V_54 = V_94 -> V_95 . V_54 ;
struct V_6 * V_7 = V_54 -> V_57 ;
unsigned int V_37 , V_69 ;
struct V_5 * V_5 ;
void * V_104 ;
int V_24 ;
V_37 = V_94 -> V_82 & ~ V_65 ;
V_69 = V_94 -> V_39 ;
if ( V_69 + V_37 > V_66 )
V_69 = V_66 - V_37 ;
V_24 = F_64 ( V_54 , V_7 , V_94 -> V_82 , V_69 ,
V_105 , & V_5 , & V_104 ) ;
if ( F_41 ( V_24 ) )
goto V_106;
if ( V_4 -> V_5 != V_5 ) {
char * V_107 = V_4 -> V_41 -> V_108 ( V_2 , V_4 , 1 ) ;
char * V_109 = F_65 ( V_5 ) ;
memcpy ( V_109 + V_37 , V_107 + V_4 -> V_37 , V_69 ) ;
F_66 ( V_5 ) ;
F_67 ( V_109 ) ;
V_4 -> V_41 -> V_110 ( V_2 , V_4 , V_107 ) ;
}
V_24 = F_68 ( V_54 , V_7 , V_94 -> V_82 , V_69 , V_69 ,
V_5 , V_104 ) ;
V_106:
return V_24 ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_111 , V_18 , V_112 ) ;
}
int F_70 ( struct V_1 * V_2 , struct V_93 * V_94 ,
T_6 * V_113 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
const struct V_114 * V_41 = V_4 -> V_41 ;
V_94 -> V_39 = V_4 -> V_39 ;
if ( V_94 -> V_39 > V_94 -> V_102 )
V_94 -> V_39 = V_94 -> V_102 ;
V_24 = V_4 -> V_41 -> V_115 ( V_2 , V_4 ) ;
if ( F_41 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_113 ( V_2 , V_4 , V_94 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_94 -> V_116 += V_24 ;
V_94 -> V_39 -= V_24 ;
V_94 -> V_82 += V_24 ;
V_94 -> V_102 -= V_24 ;
if ( ! V_4 -> V_39 ) {
V_4 -> V_41 = NULL ;
V_41 -> V_117 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_43 )
V_94 -> V_118 = true ;
}
if ( ! V_94 -> V_102 )
return 0 ;
}
return 1 ;
}
int F_71 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_119 )
return 0 ;
if ( ! V_2 -> V_47 && V_94 -> V_116 )
return 0 ;
if ( V_94 -> V_10 & V_44 )
return - V_45 ;
if ( F_24 ( V_29 ) )
return - V_46 ;
if ( V_94 -> V_118 ) {
F_69 ( V_2 ) ;
V_94 -> V_118 = false ;
}
F_26 ( V_2 ) ;
}
return 1 ;
}
void F_72 ( struct V_93 * V_94 )
{
V_94 -> V_116 = 0 ;
V_94 -> V_118 = false ;
}
void F_73 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
if ( V_94 -> V_118 )
F_69 ( V_2 ) ;
}
T_1 F_74 ( struct V_1 * V_2 , struct V_93 * V_94 ,
T_6 * V_113 )
{
int V_24 ;
F_72 ( V_94 ) ;
do {
V_24 = F_71 ( V_2 , V_94 ) ;
if ( V_24 > 0 )
V_24 = F_70 ( V_2 , V_94 , V_113 ) ;
} while ( V_24 > 0 );
F_73 ( V_2 , V_94 ) ;
return V_94 -> V_116 ? V_94 -> V_116 : V_24 ;
}
T_1 F_75 ( struct V_1 * V_2 , struct V_54 * V_106 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 ,
T_6 * V_113 )
{
T_1 V_24 ;
struct V_93 V_94 = {
. V_102 = V_39 ,
. V_10 = V_10 ,
. V_82 = * V_56 ,
. V_95 . V_54 = V_106 ,
} ;
F_22 ( V_2 ) ;
V_24 = F_74 ( V_2 , & V_94 , V_113 ) ;
F_27 ( V_2 ) ;
return V_24 ;
}
T_1
F_76 ( struct V_1 * V_2 , struct V_54 * V_106 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
struct V_6 * V_7 = V_106 -> V_57 ;
struct V_43 * V_43 = V_7 -> V_74 ;
struct V_93 V_94 = {
. V_102 = V_39 ,
. V_10 = V_10 ,
. V_82 = * V_56 ,
. V_95 . V_54 = V_106 ,
} ;
T_1 V_24 ;
F_77 ( V_43 -> V_120 ) ;
F_22 ( V_2 ) ;
F_72 ( & V_94 ) ;
do {
V_24 = F_71 ( V_2 , & V_94 ) ;
if ( V_24 <= 0 )
break;
F_78 ( & V_43 -> V_121 , V_122 ) ;
V_24 = F_79 ( V_106 ) ;
if ( ! V_24 ) {
V_24 = F_80 ( V_106 ) ;
if ( ! V_24 )
V_24 = F_70 ( V_2 , & V_94 ,
F_63 ) ;
}
F_81 ( & V_43 -> V_121 ) ;
} while ( V_24 > 0 );
F_73 ( V_2 , & V_94 ) ;
F_27 ( V_2 ) ;
if ( V_94 . V_116 )
V_24 = V_94 . V_116 ;
if ( V_24 > 0 ) {
unsigned long V_23 ;
int V_12 ;
V_23 = ( V_24 + V_66 - 1 ) >> V_64 ;
V_12 = F_82 ( V_106 , * V_56 , V_24 ) ;
if ( V_12 )
V_24 = V_12 ;
else
* V_56 += V_24 ;
F_83 ( V_7 , V_23 ) ;
}
F_84 ( V_43 -> V_120 ) ;
return V_24 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
int V_24 ;
void * V_123 ;
V_123 = V_4 -> V_41 -> V_108 ( V_2 , V_4 , 0 ) ;
V_24 = F_55 ( V_94 -> V_95 . V_54 , V_123 + V_4 -> V_37 , V_94 -> V_39 , V_94 -> V_82 ) ;
V_4 -> V_41 -> V_110 ( V_2 , V_4 , V_123 ) ;
return V_24 ;
}
static T_1 F_86 ( struct V_1 * V_2 ,
struct V_54 * V_106 , T_2 * V_56 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_75 ( V_2 , V_106 , V_56 , V_39 , V_10 , F_85 ) ;
if ( V_24 > 0 )
* V_56 += V_24 ;
return V_24 ;
}
T_1 F_87 ( struct V_1 * V_2 , struct V_54 * V_106 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
return F_75 ( V_2 , V_106 , V_56 , V_39 , V_10 , F_61 ) ;
}
static long F_88 ( struct V_1 * V_2 , struct V_54 * V_106 ,
T_2 * V_56 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_89)( struct V_1 * , struct V_54 * ,
T_2 * , T_3 , unsigned int );
int V_24 ;
if ( F_41 ( ! ( V_106 -> V_124 & V_125 ) ) )
return - V_126 ;
if ( F_41 ( V_106 -> V_127 & V_128 ) )
return - V_99 ;
V_24 = F_90 ( V_129 , V_106 , V_56 , V_39 ) ;
if ( F_41 ( V_24 < 0 ) )
return V_24 ;
if ( V_106 -> V_97 && V_106 -> V_97 -> F_89 )
F_89 = V_106 -> V_97 -> F_89 ;
else
F_89 = F_86 ;
return F_89 ( V_2 , V_106 , V_56 , V_39 , V_10 ) ;
}
static long F_91 ( struct V_54 * V_55 , T_2 * V_56 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_92)( struct V_54 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_41 ( ! ( V_55 -> V_124 & V_130 ) ) )
return - V_126 ;
V_24 = F_90 ( V_131 , V_55 , V_56 , V_39 ) ;
if ( F_41 ( V_24 < 0 ) )
return V_24 ;
if ( V_55 -> V_97 && V_55 -> V_97 -> F_92 )
F_92 = V_55 -> V_97 -> F_92 ;
else
F_92 = F_57 ;
return F_92 ( V_55 , V_56 , V_2 , V_39 , V_10 ) ;
}
T_1 F_93 ( struct V_54 * V_55 , struct V_93 * V_94 ,
T_7 * V_113 )
{
struct V_1 * V_2 ;
long V_24 , V_132 ;
T_8 V_133 ;
T_3 V_39 ;
int V_49 , V_10 ;
V_133 = V_55 -> V_134 . V_135 -> V_136 -> V_133 ;
if ( F_41 ( ! F_94 ( V_133 ) && ! F_95 ( V_133 ) ) )
return - V_99 ;
V_2 = V_29 -> V_137 ;
if ( F_41 ( ! V_2 ) ) {
V_2 = F_96 ( NULL ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_27 = 1 ;
V_29 -> V_137 = V_2 ;
}
V_24 = 0 ;
V_132 = 0 ;
V_39 = V_94 -> V_102 ;
V_10 = V_94 -> V_10 ;
V_94 -> V_10 &= ~ V_44 ;
while ( V_39 ) {
T_3 V_138 ;
T_2 V_82 = V_94 -> V_82 , V_76 = V_82 ;
V_24 = F_91 ( V_55 , & V_82 , V_2 , V_39 , V_10 ) ;
if ( F_41 ( V_24 <= 0 ) )
goto V_139;
V_138 = V_24 ;
V_94 -> V_102 = V_138 ;
V_24 = V_113 ( V_2 , V_94 ) ;
if ( F_41 ( V_24 <= 0 ) ) {
V_94 -> V_82 = V_76 ;
goto V_139;
}
V_132 += V_24 ;
V_39 -= V_24 ;
V_94 -> V_82 = V_82 ;
if ( V_24 < V_138 ) {
V_94 -> V_82 = V_76 + V_24 ;
goto V_139;
}
}
V_140:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_49 ( V_55 ) ;
return V_132 ;
V_139:
for ( V_49 = 0 ; V_49 < V_2 -> V_32 ; V_49 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_49 ;
if ( V_4 -> V_41 ) {
V_4 -> V_41 -> V_117 ( V_2 , V_4 ) ;
V_4 -> V_41 = NULL ;
}
}
if ( ! V_132 )
V_132 = V_24 ;
goto V_140;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_54 * V_54 = V_94 -> V_95 . V_54 ;
return F_88 ( V_2 , V_54 , & V_54 -> V_141 , V_94 -> V_102 ,
V_94 -> V_10 ) ;
}
long F_98 ( struct V_54 * V_55 , T_2 * V_56 , struct V_54 * V_106 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_93 V_94 = {
. V_39 = V_39 ,
. V_102 = V_39 ,
. V_10 = V_10 ,
. V_82 = * V_56 ,
. V_95 . V_54 = V_106 ,
} ;
long V_24 ;
V_24 = F_93 ( V_55 , & V_94 , F_97 ) ;
if ( V_24 > 0 )
* V_56 = V_94 . V_82 ;
return V_24 ;
}
static long F_99 ( struct V_54 * V_55 , T_2 V_84 * V_142 ,
struct V_54 * V_106 , T_2 V_84 * V_143 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_144 ;
struct V_1 * V_145 ;
T_2 V_37 , * V_146 ;
long V_24 ;
V_144 = F_100 ( V_55 ) ;
V_145 = F_100 ( V_106 ) ;
if ( V_144 && V_145 ) {
if ( V_142 || V_143 )
return - V_147 ;
if ( ! ( V_55 -> V_124 & V_130 ) )
return - V_126 ;
if ( ! ( V_106 -> V_124 & V_125 ) )
return - V_126 ;
if ( V_144 == V_145 )
return - V_99 ;
return F_101 ( V_144 , V_145 , V_39 , V_10 ) ;
}
if ( V_144 ) {
if ( V_142 )
return - V_147 ;
if ( V_143 ) {
if ( ! ( V_106 -> V_124 & V_148 ) )
return - V_99 ;
if ( F_102 ( & V_37 , V_143 , sizeof( T_2 ) ) )
return - V_149 ;
V_146 = & V_37 ;
} else
V_146 = & V_106 -> V_141 ;
V_24 = F_88 ( V_144 , V_106 , V_146 , V_39 , V_10 ) ;
if ( V_143 && F_103 ( V_143 , V_146 , sizeof( T_2 ) ) )
V_24 = - V_149 ;
return V_24 ;
}
if ( V_145 ) {
if ( V_143 )
return - V_147 ;
if ( V_142 ) {
if ( ! ( V_55 -> V_124 & V_150 ) )
return - V_99 ;
if ( F_102 ( & V_37 , V_142 , sizeof( T_2 ) ) )
return - V_149 ;
V_146 = & V_37 ;
} else
V_146 = & V_55 -> V_141 ;
V_24 = F_91 ( V_55 , V_146 , V_145 , V_39 , V_10 ) ;
if ( V_142 && F_103 ( V_142 , V_146 , sizeof( T_2 ) ) )
V_24 = - V_149 ;
return V_24 ;
}
return - V_99 ;
}
static int F_104 ( const struct V_78 V_84 * V_151 ,
unsigned int V_152 , struct V_5 * * V_36 ,
struct V_52 * V_38 , bool V_153 ,
unsigned int V_154 )
{
int V_32 = 0 , error = 0 ;
while ( V_152 ) {
unsigned long V_146 , V_155 ;
struct V_78 V_156 ;
void V_84 * V_157 ;
T_3 V_39 ;
int V_49 ;
error = - V_149 ;
if ( F_102 ( & V_156 , V_151 , sizeof( V_156 ) ) )
break;
V_157 = V_156 . V_91 ;
V_39 = V_156 . V_92 ;
error = 0 ;
if ( F_41 ( ! V_39 ) )
break;
error = - V_149 ;
if ( ! F_105 ( V_158 , V_157 , V_39 ) )
break;
V_146 = ( unsigned long ) V_157 & ~ V_159 ;
error = - V_99 ;
if ( V_153 && ( V_146 || V_39 & ~ V_159 ) )
break;
V_155 = ( V_146 + V_39 + V_160 - 1 ) >> V_161 ;
if ( V_155 > V_154 - V_32 )
V_155 = V_154 - V_32 ;
error = F_106 ( ( unsigned long ) V_157 , V_155 ,
0 , & V_36 [ V_32 ] ) ;
if ( F_41 ( error <= 0 ) )
break;
for ( V_49 = 0 ; V_49 < error ; V_49 ++ ) {
const int V_75 = F_42 ( T_3 , V_39 , V_160 - V_146 ) ;
V_38 [ V_32 ] . V_37 = V_146 ;
V_38 [ V_32 ] . V_39 = V_75 ;
V_146 = 0 ;
V_39 -= V_75 ;
V_32 ++ ;
}
if ( V_39 )
break;
if ( error < V_155 || V_32 == V_154 )
break;
V_152 -- ;
V_151 ++ ;
}
if ( V_32 )
return V_32 ;
return error ;
}
static int F_107 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_93 * V_94 )
{
char * V_107 ;
int V_24 ;
if ( ! F_108 ( V_94 -> V_95 . V_162 , V_94 -> V_39 ) ) {
V_107 = V_4 -> V_41 -> V_108 ( V_2 , V_4 , 1 ) ;
V_24 = F_109 ( V_94 -> V_95 . V_162 , V_107 + V_4 -> V_37 ,
V_94 -> V_39 ) ;
V_4 -> V_41 -> V_110 ( V_2 , V_4 , V_107 ) ;
if ( ! V_24 ) {
V_24 = V_94 -> V_39 ;
goto V_106;
}
}
V_107 = V_4 -> V_41 -> V_108 ( V_2 , V_4 , 0 ) ;
V_24 = V_94 -> V_39 ;
if ( F_103 ( V_94 -> V_95 . V_162 , V_107 + V_4 -> V_37 , V_94 -> V_39 ) )
V_24 = - V_149 ;
V_4 -> V_41 -> V_110 ( V_2 , V_4 , V_107 ) ;
V_106:
if ( V_24 > 0 )
V_94 -> V_95 . V_162 += V_24 ;
return V_24 ;
}
static long F_110 ( struct V_54 * V_54 , const struct V_78 V_84 * V_151 ,
unsigned long V_163 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_93 V_94 ;
T_1 V_164 ;
int error ;
long V_24 ;
V_2 = F_100 ( V_54 ) ;
if ( ! V_2 )
return - V_126 ;
F_22 ( V_2 ) ;
error = V_24 = 0 ;
while ( V_163 ) {
void V_84 * V_157 ;
T_3 V_39 ;
error = F_111 ( V_157 , & V_151 -> V_91 ) ;
if ( F_41 ( error ) )
break;
error = F_111 ( V_39 , & V_151 -> V_92 ) ;
if ( F_41 ( error ) )
break;
if ( F_41 ( ! V_39 ) )
break;
if ( F_41 ( ! V_157 ) ) {
error = - V_149 ;
break;
}
if ( F_41 ( ! F_105 ( V_165 , V_157 , V_39 ) ) ) {
error = - V_149 ;
break;
}
V_94 . V_39 = 0 ;
V_94 . V_102 = V_39 ;
V_94 . V_10 = V_10 ;
V_94 . V_95 . V_162 = V_157 ;
V_94 . V_82 = 0 ;
V_164 = F_74 ( V_2 , & V_94 , F_107 ) ;
if ( V_164 < 0 ) {
if ( ! V_24 )
V_24 = V_164 ;
break;
}
V_24 += V_164 ;
if ( V_164 < V_39 )
break;
V_163 -- ;
V_151 ++ ;
}
F_27 ( V_2 ) ;
if ( ! V_24 )
V_24 = error ;
return V_24 ;
}
static long F_112 ( struct V_54 * V_54 , const struct V_78 V_84 * V_151 ,
unsigned long V_163 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_5 * V_36 [ V_51 ] ;
struct V_52 V_38 [ V_51 ] ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_50 = V_51 ,
. V_10 = V_10 ,
. V_41 = & V_166 ,
. V_48 = F_28 ,
} ;
long V_24 ;
V_2 = F_100 ( V_54 ) ;
if ( ! V_2 )
return - V_126 ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_53 ;
V_21 . V_23 = F_104 ( V_151 , V_163 , V_21 . V_36 ,
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
if ( ! V_2 -> V_119 )
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
static int F_101 ( struct V_1 * V_144 ,
struct V_1 * V_145 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_167 , * V_168 ;
int V_24 = 0 , V_169 ;
bool V_170 = false ;
V_171:
V_24 = F_113 ( V_144 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_114 ( V_145 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_115 ( V_144 , V_145 ) ;
do {
if ( ! V_145 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( ! V_144 -> V_31 && ! V_144 -> V_119 )
break;
if ( ! V_144 -> V_31 || V_145 -> V_31 >= V_145 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_44 ) {
V_24 = - V_45 ;
break;
}
F_27 ( V_144 ) ;
F_27 ( V_145 ) ;
goto V_171;
}
V_167 = V_144 -> V_35 + V_144 -> V_34 ;
V_169 = ( V_145 -> V_34 + V_145 -> V_31 ) & ( V_145 -> V_32 - 1 ) ;
V_168 = V_145 -> V_35 + V_169 ;
if ( V_39 >= V_167 -> V_39 ) {
* V_168 = * V_167 ;
V_167 -> V_41 = NULL ;
V_145 -> V_31 ++ ;
V_144 -> V_34 = ( V_144 -> V_34 + 1 ) & ( V_144 -> V_32 - 1 ) ;
V_144 -> V_31 -- ;
V_170 = true ;
} else {
V_167 -> V_41 -> V_172 ( V_144 , V_167 ) ;
* V_168 = * V_167 ;
V_168 -> V_10 &= ~ V_15 ;
V_168 -> V_39 = V_39 ;
V_145 -> V_31 ++ ;
V_167 -> V_37 += V_168 -> V_39 ;
V_167 -> V_39 -= V_168 -> V_39 ;
}
V_24 += V_168 -> V_39 ;
V_39 -= V_168 -> V_39 ;
} while ( V_39 );
F_27 ( V_144 ) ;
F_27 ( V_145 ) ;
if ( V_24 > 0 )
F_16 ( V_145 ) ;
if ( V_170 )
F_69 ( V_144 ) ;
return V_24 ;
}
static int F_116 ( struct V_1 * V_144 ,
struct V_1 * V_145 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_167 , * V_168 ;
int V_24 = 0 , V_49 = 0 , V_169 ;
F_115 ( V_144 , V_145 ) ;
do {
if ( ! V_145 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( V_49 >= V_144 -> V_31 || V_145 -> V_31 >= V_145 -> V_32 )
break;
V_167 = V_144 -> V_35 + ( ( V_144 -> V_34 + V_49 ) & ( V_144 -> V_32 - 1 ) ) ;
V_169 = ( V_145 -> V_34 + V_145 -> V_31 ) & ( V_145 -> V_32 - 1 ) ;
V_167 -> V_41 -> V_172 ( V_144 , V_167 ) ;
V_168 = V_145 -> V_35 + V_169 ;
* V_168 = * V_167 ;
V_168 -> V_10 &= ~ V_15 ;
if ( V_168 -> V_39 > V_39 )
V_168 -> V_39 = V_39 ;
V_145 -> V_31 ++ ;
V_24 += V_168 -> V_39 ;
V_39 -= V_168 -> V_39 ;
V_49 ++ ;
} while ( V_39 );
if ( ! V_24 && V_144 -> V_47 && ( V_10 & V_44 ) )
V_24 = - V_45 ;
F_27 ( V_144 ) ;
F_27 ( V_145 ) ;
if ( V_24 > 0 )
F_16 ( V_145 ) ;
return V_24 ;
}
static long F_117 ( struct V_54 * V_55 , struct V_54 * V_106 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_144 = F_100 ( V_55 ) ;
struct V_1 * V_145 = F_100 ( V_106 ) ;
int V_24 = - V_99 ;
if ( V_144 && V_145 && V_144 != V_145 ) {
V_24 = F_113 ( V_144 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_114 ( V_145 , V_10 ) ;
if ( ! V_24 )
V_24 = F_116 ( V_144 , V_145 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
