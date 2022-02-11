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
static void F_28 ( struct V_20 * V_21 , unsigned int V_49 )
{
F_12 ( V_21 -> V_36 [ V_49 ] ) ;
}
int F_29 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
if ( V_2 -> V_32 <= V_50 )
return 0 ;
V_21 -> V_36 = F_30 ( V_2 -> V_32 * sizeof( struct V_5 * ) , V_8 ) ;
V_21 -> V_38 = F_30 ( V_2 -> V_32 * sizeof( struct V_51 ) , V_8 ) ;
if ( V_21 -> V_36 && V_21 -> V_38 )
return 0 ;
F_31 ( V_21 -> V_36 ) ;
F_31 ( V_21 -> V_38 ) ;
return - V_52 ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
if ( V_2 -> V_32 <= V_50 )
return;
F_31 ( V_21 -> V_36 ) ;
F_31 ( V_21 -> V_38 ) ;
}
static int
F_33 ( struct V_53 * V_54 , T_2 * V_55 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_6 * V_7 = V_54 -> V_56 ;
unsigned int V_57 , V_23 , V_58 ;
struct V_5 * V_36 [ V_50 ] ;
struct V_51 V_38 [ V_50 ] ;
struct V_5 * V_5 ;
T_4 V_59 , V_60 ;
T_2 V_61 ;
int error , V_26 ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_10 = V_10 ,
. V_41 = & V_62 ,
. V_48 = F_28 ,
} ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_52 ;
V_59 = * V_55 >> V_63 ;
V_57 = * V_55 & ~ V_64 ;
V_58 = ( V_39 + V_57 + V_65 - 1 ) >> V_63 ;
V_23 = F_34 ( V_58 , V_2 -> V_32 ) ;
V_21 . V_23 = F_35 ( V_7 , V_59 , V_23 , V_21 . V_36 ) ;
V_59 += V_21 . V_23 ;
if ( V_21 . V_23 < V_23 )
F_36 ( V_7 , & V_54 -> V_66 , V_54 ,
V_59 , V_58 - V_21 . V_23 ) ;
error = 0 ;
while ( V_21 . V_23 < V_23 ) {
V_5 = F_37 ( V_7 , V_59 ) ;
if ( ! V_5 ) {
V_5 = F_38 ( V_7 ) ;
if ( ! V_5 )
break;
error = F_39 ( V_5 , V_7 , V_59 ,
V_8 ) ;
if ( F_40 ( error ) ) {
F_12 ( V_5 ) ;
if ( error == - V_67 )
continue;
break;
}
F_10 ( V_5 ) ;
}
V_21 . V_36 [ V_21 . V_23 ++ ] = V_5 ;
V_59 ++ ;
}
V_59 = * V_55 >> V_63 ;
V_23 = V_21 . V_23 ;
V_21 . V_23 = 0 ;
for ( V_26 = 0 ; V_26 < V_23 ; V_26 ++ ) {
unsigned int V_68 ;
if ( ! V_39 )
break;
V_68 = F_41 (unsigned long, len, PAGE_CACHE_SIZE - loff) ;
V_5 = V_21 . V_36 [ V_26 ] ;
if ( F_42 ( V_5 ) )
F_43 ( V_7 , & V_54 -> V_66 , V_54 ,
V_5 , V_59 , V_58 - V_26 ) ;
if ( ! F_5 ( V_5 ) ) {
F_2 ( V_5 ) ;
if ( ! V_5 -> V_7 ) {
F_10 ( V_5 ) ;
V_5 = F_44 ( V_7 , V_59 ,
F_45 ( V_7 ) ) ;
if ( ! V_5 ) {
error = - V_52 ;
break;
}
F_12 ( V_21 . V_36 [ V_26 ] ) ;
V_21 . V_36 [ V_26 ] = V_5 ;
}
if ( F_5 ( V_5 ) ) {
F_10 ( V_5 ) ;
goto V_69;
}
error = V_7 -> V_70 -> V_71 ( V_54 , V_5 ) ;
if ( F_40 ( error ) ) {
if ( error == V_72 )
error = 0 ;
break;
}
}
V_69:
V_61 = F_46 ( V_7 -> V_73 ) ;
V_60 = ( V_61 - 1 ) >> V_63 ;
if ( F_40 ( ! V_61 || V_59 > V_60 ) )
break;
if ( V_60 == V_59 ) {
unsigned int V_74 ;
V_74 = ( ( V_61 - 1 ) & ~ V_64 ) + 1 ;
if ( V_74 <= V_57 )
break;
V_68 = F_34 ( V_68 , V_74 - V_57 ) ;
V_39 = V_68 ;
}
V_21 . V_38 [ V_26 ] . V_37 = V_57 ;
V_21 . V_38 [ V_26 ] . V_39 = V_68 ;
V_39 -= V_68 ;
V_57 = 0 ;
V_21 . V_23 ++ ;
V_59 ++ ;
}
while ( V_26 < V_23 )
F_12 ( V_21 . V_36 [ V_26 ++ ] ) ;
V_54 -> V_66 . V_75 = ( T_2 ) V_59 << V_63 ;
if ( V_21 . V_23 )
error = F_21 ( V_2 , & V_21 ) ;
F_32 ( V_2 , & V_21 ) ;
return error ;
}
T_1 F_47 ( struct V_53 * V_54 , T_2 * V_55 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_2 V_61 , V_76 ;
int V_24 ;
V_61 = F_46 ( V_54 -> V_56 -> V_73 ) ;
if ( F_40 ( * V_55 >= V_61 ) )
return 0 ;
V_76 = V_61 - * V_55 ;
if ( F_40 ( V_76 < V_39 ) )
V_39 = V_76 ;
V_24 = F_33 ( V_54 , V_55 , V_2 , V_39 , V_10 ) ;
if ( V_24 > 0 ) {
* V_55 += V_24 ;
F_48 ( V_54 ) ;
}
return V_24 ;
}
static T_1 F_49 ( struct V_53 * V_53 , const struct V_77 * V_78 ,
unsigned long V_79 , T_2 V_37 )
{
T_5 V_80 ;
T_2 V_81 = V_37 ;
T_1 V_82 ;
V_80 = F_50 () ;
F_51 ( F_52 () ) ;
V_82 = F_53 ( V_53 , ( const struct V_77 V_83 * ) V_78 , V_79 , & V_81 ) ;
F_51 ( V_80 ) ;
return V_82 ;
}
static T_1 F_54 ( struct V_53 * V_53 , const char * V_4 , T_3 V_84 ,
T_2 V_81 )
{
T_5 V_80 ;
T_1 V_82 ;
V_80 = F_50 () ;
F_51 ( F_52 () ) ;
V_82 = F_55 ( V_53 , ( const char V_83 * ) V_4 , V_84 , & V_81 ) ;
F_51 ( V_80 ) ;
return V_82 ;
}
T_1 F_56 ( struct V_53 * V_54 , T_2 * V_55 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
unsigned int V_23 ;
unsigned int V_85 ;
T_3 V_37 ;
struct V_5 * V_36 [ V_50 ] ;
struct V_51 V_38 [ V_50 ] ;
struct V_77 * V_78 , V_86 [ V_50 ] ;
T_1 V_82 ;
T_3 V_68 ;
int error ;
int V_49 ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_10 = V_10 ,
. V_41 = & V_87 ,
. V_48 = F_28 ,
} ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_52 ;
V_82 = - V_52 ;
V_78 = V_86 ;
if ( V_2 -> V_32 > V_50 ) {
V_78 = F_30 ( V_2 -> V_32 * sizeof( struct V_77 ) , V_8 ) ;
if ( ! V_78 )
goto V_88;
}
V_37 = * V_55 & ~ V_64 ;
V_23 = ( V_39 + V_37 + V_65 - 1 ) >> V_63 ;
for ( V_49 = 0 ; V_49 < V_23 && V_49 < V_2 -> V_32 && V_39 ; V_49 ++ ) {
struct V_5 * V_5 ;
V_5 = F_57 ( V_89 ) ;
error = - V_52 ;
if ( ! V_5 )
goto V_12;
V_68 = F_41 ( T_3 , V_39 , V_65 - V_37 ) ;
V_78 [ V_49 ] . V_90 = ( void V_83 * ) F_58 ( V_5 ) ;
V_78 [ V_49 ] . V_91 = V_68 ;
V_21 . V_36 [ V_49 ] = V_5 ;
V_21 . V_23 ++ ;
V_39 -= V_68 ;
V_37 = 0 ;
}
V_82 = F_49 ( V_54 , V_78 , V_21 . V_23 , * V_55 ) ;
if ( V_82 < 0 ) {
error = V_82 ;
goto V_12;
}
error = 0 ;
if ( ! V_82 )
goto V_12;
V_85 = 0 ;
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ ) {
V_68 = F_41 ( T_3 , V_78 [ V_49 ] . V_91 , V_82 ) ;
V_21 . V_38 [ V_49 ] . V_37 = 0 ;
V_21 . V_38 [ V_49 ] . V_39 = V_68 ;
if ( ! V_68 ) {
F_59 ( V_21 . V_36 [ V_49 ] ) ;
V_21 . V_36 [ V_49 ] = NULL ;
V_85 ++ ;
}
V_82 -= V_68 ;
}
V_21 . V_23 -= V_85 ;
V_82 = F_21 ( V_2 , & V_21 ) ;
if ( V_82 > 0 )
* V_55 += V_82 ;
V_88:
if ( V_78 != V_86 )
F_31 ( V_78 ) ;
F_32 ( V_2 , & V_21 ) ;
return V_82 ;
V_12:
for ( V_49 = 0 ; V_49 < V_21 . V_23 ; V_49 ++ )
F_59 ( V_21 . V_36 [ V_49 ] ) ;
V_82 = error ;
goto V_88;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_92 * V_93 )
{
struct V_53 * V_53 = V_93 -> V_94 . V_53 ;
T_2 V_81 = V_93 -> V_81 ;
int V_95 ;
if ( ! F_61 ( V_53 -> V_96 && V_53 -> V_96 -> V_97 ) )
return - V_98 ;
V_95 = ( V_93 -> V_10 & V_99 ) || V_93 -> V_39 < V_93 -> V_100 ;
return V_53 -> V_96 -> V_97 ( V_53 , V_4 -> V_5 , V_4 -> V_37 ,
V_93 -> V_39 , & V_81 , V_95 ) ;
}
int F_62 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_92 * V_93 )
{
struct V_53 * V_53 = V_93 -> V_94 . V_53 ;
struct V_6 * V_7 = V_53 -> V_56 ;
unsigned int V_37 , V_68 ;
struct V_5 * V_5 ;
void * V_101 ;
int V_24 ;
V_37 = V_93 -> V_81 & ~ V_64 ;
V_68 = V_93 -> V_39 ;
if ( V_68 + V_37 > V_65 )
V_68 = V_65 - V_37 ;
V_24 = F_63 ( V_53 , V_7 , V_93 -> V_81 , V_68 ,
V_102 , & V_5 , & V_101 ) ;
if ( F_40 ( V_24 ) )
goto V_103;
if ( V_4 -> V_5 != V_5 ) {
char * V_104 = V_4 -> V_41 -> V_105 ( V_2 , V_4 , 1 ) ;
char * V_106 = F_64 ( V_5 , V_107 ) ;
memcpy ( V_106 + V_37 , V_104 + V_4 -> V_37 , V_68 ) ;
F_65 ( V_5 ) ;
F_66 ( V_106 , V_107 ) ;
V_4 -> V_41 -> V_108 ( V_2 , V_4 , V_104 ) ;
}
V_24 = F_67 ( V_53 , V_7 , V_93 -> V_81 , V_68 , V_68 ,
V_5 , V_101 ) ;
V_103:
return V_24 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_109 , V_18 , V_110 ) ;
}
int F_69 ( struct V_1 * V_2 , struct V_92 * V_93 ,
T_6 * V_111 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
const struct V_112 * V_41 = V_4 -> V_41 ;
V_93 -> V_39 = V_4 -> V_39 ;
if ( V_93 -> V_39 > V_93 -> V_100 )
V_93 -> V_39 = V_93 -> V_100 ;
V_24 = V_4 -> V_41 -> V_113 ( V_2 , V_4 ) ;
if ( F_40 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_111 ( V_2 , V_4 , V_93 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_93 -> V_114 += V_24 ;
V_93 -> V_39 -= V_24 ;
V_93 -> V_81 += V_24 ;
V_93 -> V_100 -= V_24 ;
if ( ! V_4 -> V_39 ) {
V_4 -> V_41 = NULL ;
V_41 -> V_115 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_43 )
V_93 -> V_116 = true ;
}
if ( ! V_93 -> V_100 )
return 0 ;
}
return 1 ;
}
int F_70 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_117 )
return 0 ;
if ( ! V_2 -> V_47 && V_93 -> V_114 )
return 0 ;
if ( V_93 -> V_10 & V_44 )
return - V_45 ;
if ( F_24 ( V_29 ) )
return - V_46 ;
if ( V_93 -> V_116 ) {
F_68 ( V_2 ) ;
V_93 -> V_116 = false ;
}
F_26 ( V_2 ) ;
}
return 1 ;
}
void F_71 ( struct V_92 * V_93 )
{
V_93 -> V_114 = 0 ;
V_93 -> V_116 = false ;
}
void F_72 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
if ( V_93 -> V_116 )
F_68 ( V_2 ) ;
}
T_1 F_73 ( struct V_1 * V_2 , struct V_92 * V_93 ,
T_6 * V_111 )
{
int V_24 ;
F_71 ( V_93 ) ;
do {
V_24 = F_70 ( V_2 , V_93 ) ;
if ( V_24 > 0 )
V_24 = F_69 ( V_2 , V_93 , V_111 ) ;
} while ( V_24 > 0 );
F_72 ( V_2 , V_93 ) ;
return V_93 -> V_114 ? V_93 -> V_114 : V_24 ;
}
T_1 F_74 ( struct V_1 * V_2 , struct V_53 * V_103 ,
T_2 * V_55 , T_3 V_39 , unsigned int V_10 ,
T_6 * V_111 )
{
T_1 V_24 ;
struct V_92 V_93 = {
. V_100 = V_39 ,
. V_10 = V_10 ,
. V_81 = * V_55 ,
. V_94 . V_53 = V_103 ,
} ;
F_22 ( V_2 ) ;
V_24 = F_73 ( V_2 , & V_93 , V_111 ) ;
F_27 ( V_2 ) ;
return V_24 ;
}
T_1
F_75 ( struct V_1 * V_2 , struct V_53 * V_103 ,
T_2 * V_55 , T_3 V_39 , unsigned int V_10 )
{
struct V_6 * V_7 = V_103 -> V_56 ;
struct V_43 * V_43 = V_7 -> V_73 ;
struct V_92 V_93 = {
. V_100 = V_39 ,
. V_10 = V_10 ,
. V_81 = * V_55 ,
. V_94 . V_53 = V_103 ,
} ;
T_1 V_24 ;
F_22 ( V_2 ) ;
F_71 ( & V_93 ) ;
do {
V_24 = F_70 ( V_2 , & V_93 ) ;
if ( V_24 <= 0 )
break;
F_76 ( & V_43 -> V_118 , V_119 ) ;
V_24 = F_77 ( V_103 ) ;
if ( ! V_24 ) {
F_78 ( V_103 ) ;
V_24 = F_69 ( V_2 , & V_93 , F_62 ) ;
}
F_79 ( & V_43 -> V_118 ) ;
} while ( V_24 > 0 );
F_72 ( V_2 , & V_93 ) ;
F_27 ( V_2 ) ;
if ( V_93 . V_114 )
V_24 = V_93 . V_114 ;
if ( V_24 > 0 ) {
unsigned long V_23 ;
int V_12 ;
V_23 = ( V_24 + V_65 - 1 ) >> V_63 ;
V_12 = F_80 ( V_103 , * V_55 , V_24 ) ;
if ( V_12 )
V_24 = V_12 ;
else
* V_55 += V_24 ;
F_81 ( V_7 , V_23 ) ;
}
return V_24 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_92 * V_93 )
{
int V_24 ;
void * V_120 ;
V_120 = V_4 -> V_41 -> V_105 ( V_2 , V_4 , 0 ) ;
V_24 = F_54 ( V_93 -> V_94 . V_53 , V_120 + V_4 -> V_37 , V_93 -> V_39 , V_93 -> V_81 ) ;
V_4 -> V_41 -> V_108 ( V_2 , V_4 , V_120 ) ;
return V_24 ;
}
static T_1 F_83 ( struct V_1 * V_2 ,
struct V_53 * V_103 , T_2 * V_55 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_74 ( V_2 , V_103 , V_55 , V_39 , V_10 , F_82 ) ;
if ( V_24 > 0 )
* V_55 += V_24 ;
return V_24 ;
}
T_1 F_84 ( struct V_1 * V_2 , struct V_53 * V_103 ,
T_2 * V_55 , T_3 V_39 , unsigned int V_10 )
{
return F_74 ( V_2 , V_103 , V_55 , V_39 , V_10 , F_60 ) ;
}
static long F_85 ( struct V_1 * V_2 , struct V_53 * V_103 ,
T_2 * V_55 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_86)( struct V_1 * , struct V_53 * ,
T_2 * , T_3 , unsigned int );
int V_24 ;
if ( F_40 ( ! ( V_103 -> V_121 & V_122 ) ) )
return - V_123 ;
if ( F_40 ( V_103 -> V_124 & V_125 ) )
return - V_98 ;
V_24 = F_87 ( V_126 , V_103 , V_55 , V_39 ) ;
if ( F_40 ( V_24 < 0 ) )
return V_24 ;
if ( V_103 -> V_96 && V_103 -> V_96 -> F_86 )
F_86 = V_103 -> V_96 -> F_86 ;
else
F_86 = F_83 ;
return F_86 ( V_2 , V_103 , V_55 , V_39 , V_10 ) ;
}
static long F_88 ( struct V_53 * V_54 , T_2 * V_55 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_89)( struct V_53 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_40 ( ! ( V_54 -> V_121 & V_127 ) ) )
return - V_123 ;
V_24 = F_87 ( V_128 , V_54 , V_55 , V_39 ) ;
if ( F_40 ( V_24 < 0 ) )
return V_24 ;
if ( V_54 -> V_96 && V_54 -> V_96 -> F_89 )
F_89 = V_54 -> V_96 -> F_89 ;
else
F_89 = F_56 ;
return F_89 ( V_54 , V_55 , V_2 , V_39 , V_10 ) ;
}
T_1 F_90 ( struct V_53 * V_54 , struct V_92 * V_93 ,
T_7 * V_111 )
{
struct V_1 * V_2 ;
long V_24 , V_129 ;
T_8 V_130 ;
T_3 V_39 ;
int V_49 , V_10 ;
V_130 = V_54 -> V_131 . V_132 -> V_133 -> V_130 ;
if ( F_40 ( ! F_91 ( V_130 ) && ! F_92 ( V_130 ) ) )
return - V_98 ;
V_2 = V_29 -> V_134 ;
if ( F_40 ( ! V_2 ) ) {
V_2 = F_93 ( NULL ) ;
if ( ! V_2 )
return - V_52 ;
V_2 -> V_27 = 1 ;
V_29 -> V_134 = V_2 ;
}
V_24 = 0 ;
V_129 = 0 ;
V_39 = V_93 -> V_100 ;
V_10 = V_93 -> V_10 ;
V_93 -> V_10 &= ~ V_44 ;
while ( V_39 ) {
T_3 V_135 ;
T_2 V_81 = V_93 -> V_81 , V_75 = V_81 ;
V_24 = F_88 ( V_54 , & V_81 , V_2 , V_39 , V_10 ) ;
if ( F_40 ( V_24 <= 0 ) )
goto V_136;
V_135 = V_24 ;
V_93 -> V_100 = V_135 ;
V_24 = V_111 ( V_2 , V_93 ) ;
if ( F_40 ( V_24 <= 0 ) ) {
V_93 -> V_81 = V_75 ;
goto V_136;
}
V_129 += V_24 ;
V_39 -= V_24 ;
V_93 -> V_81 = V_81 ;
if ( V_24 < V_135 ) {
V_93 -> V_81 = V_75 + V_24 ;
goto V_136;
}
}
V_137:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_48 ( V_54 ) ;
return V_129 ;
V_136:
for ( V_49 = 0 ; V_49 < V_2 -> V_32 ; V_49 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_49 ;
if ( V_4 -> V_41 ) {
V_4 -> V_41 -> V_115 ( V_2 , V_4 ) ;
V_4 -> V_41 = NULL ;
}
}
if ( ! V_129 )
V_129 = V_24 ;
goto V_137;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_53 * V_53 = V_93 -> V_94 . V_53 ;
return F_85 ( V_2 , V_53 , & V_53 -> V_138 , V_93 -> V_100 ,
V_93 -> V_10 ) ;
}
long F_95 ( struct V_53 * V_54 , T_2 * V_55 , struct V_53 * V_103 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_92 V_93 = {
. V_39 = V_39 ,
. V_100 = V_39 ,
. V_10 = V_10 ,
. V_81 = * V_55 ,
. V_94 . V_53 = V_103 ,
} ;
long V_24 ;
V_24 = F_90 ( V_54 , & V_93 , F_94 ) ;
if ( V_24 > 0 )
* V_55 = V_93 . V_81 ;
return V_24 ;
}
static long F_96 ( struct V_53 * V_54 , T_2 V_83 * V_139 ,
struct V_53 * V_103 , T_2 V_83 * V_140 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_141 ;
struct V_1 * V_142 ;
T_2 V_37 , * V_143 ;
long V_24 ;
V_141 = F_97 ( V_54 ) ;
V_142 = F_97 ( V_103 ) ;
if ( V_141 && V_142 ) {
if ( V_139 || V_140 )
return - V_144 ;
if ( ! ( V_54 -> V_121 & V_127 ) )
return - V_123 ;
if ( ! ( V_103 -> V_121 & V_122 ) )
return - V_123 ;
if ( V_141 == V_142 )
return - V_98 ;
return F_98 ( V_141 , V_142 , V_39 , V_10 ) ;
}
if ( V_141 ) {
if ( V_139 )
return - V_144 ;
if ( V_140 ) {
if ( ! ( V_103 -> V_121 & V_145 ) )
return - V_98 ;
if ( F_99 ( & V_37 , V_140 , sizeof( T_2 ) ) )
return - V_146 ;
V_143 = & V_37 ;
} else
V_143 = & V_103 -> V_138 ;
V_24 = F_85 ( V_141 , V_103 , V_143 , V_39 , V_10 ) ;
if ( V_140 && F_100 ( V_140 , V_143 , sizeof( T_2 ) ) )
V_24 = - V_146 ;
return V_24 ;
}
if ( V_142 ) {
if ( V_140 )
return - V_144 ;
if ( V_139 ) {
if ( ! ( V_54 -> V_121 & V_147 ) )
return - V_98 ;
if ( F_99 ( & V_37 , V_139 , sizeof( T_2 ) ) )
return - V_146 ;
V_143 = & V_37 ;
} else
V_143 = & V_54 -> V_138 ;
V_24 = F_88 ( V_54 , V_143 , V_142 , V_39 , V_10 ) ;
if ( V_139 && F_100 ( V_139 , V_143 , sizeof( T_2 ) ) )
V_24 = - V_146 ;
return V_24 ;
}
return - V_98 ;
}
static int F_101 ( const struct V_77 V_83 * V_148 ,
unsigned int V_149 , struct V_5 * * V_36 ,
struct V_51 * V_38 , int V_150 ,
unsigned int V_151 )
{
int V_32 = 0 , error = 0 ;
while ( V_149 ) {
unsigned long V_143 , V_152 ;
struct V_77 V_153 ;
void V_83 * V_154 ;
T_3 V_39 ;
int V_49 ;
error = - V_146 ;
if ( F_99 ( & V_153 , V_148 , sizeof( V_153 ) ) )
break;
V_154 = V_153 . V_90 ;
V_39 = V_153 . V_91 ;
error = 0 ;
if ( F_40 ( ! V_39 ) )
break;
error = - V_146 ;
if ( ! F_102 ( V_155 , V_154 , V_39 ) )
break;
V_143 = ( unsigned long ) V_154 & ~ V_156 ;
error = - V_98 ;
if ( V_150 && ( V_143 || V_39 & ~ V_156 ) )
break;
V_152 = ( V_143 + V_39 + V_157 - 1 ) >> V_158 ;
if ( V_152 > V_151 - V_32 )
V_152 = V_151 - V_32 ;
error = F_103 ( ( unsigned long ) V_154 , V_152 ,
0 , & V_36 [ V_32 ] ) ;
if ( F_40 ( error <= 0 ) )
break;
for ( V_49 = 0 ; V_49 < error ; V_49 ++ ) {
const int V_74 = F_41 ( T_3 , V_39 , V_157 - V_143 ) ;
V_38 [ V_32 ] . V_37 = V_143 ;
V_38 [ V_32 ] . V_39 = V_74 ;
V_143 = 0 ;
V_39 -= V_74 ;
V_32 ++ ;
}
if ( V_39 )
break;
if ( error < V_152 || V_32 == V_151 )
break;
V_149 -- ;
V_148 ++ ;
}
if ( V_32 )
return V_32 ;
return error ;
}
static int F_104 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_92 * V_93 )
{
char * V_104 ;
int V_24 ;
if ( ! F_105 ( V_93 -> V_94 . V_159 , V_93 -> V_39 ) ) {
V_104 = V_4 -> V_41 -> V_105 ( V_2 , V_4 , 1 ) ;
V_24 = F_106 ( V_93 -> V_94 . V_159 , V_104 + V_4 -> V_37 ,
V_93 -> V_39 ) ;
V_4 -> V_41 -> V_108 ( V_2 , V_4 , V_104 ) ;
if ( ! V_24 ) {
V_24 = V_93 -> V_39 ;
goto V_103;
}
}
V_104 = V_4 -> V_41 -> V_105 ( V_2 , V_4 , 0 ) ;
V_24 = V_93 -> V_39 ;
if ( F_100 ( V_93 -> V_94 . V_159 , V_104 + V_4 -> V_37 , V_93 -> V_39 ) )
V_24 = - V_146 ;
V_4 -> V_41 -> V_108 ( V_2 , V_4 , V_104 ) ;
V_103:
if ( V_24 > 0 )
V_93 -> V_94 . V_159 += V_24 ;
return V_24 ;
}
static long F_107 ( struct V_53 * V_53 , const struct V_77 V_83 * V_148 ,
unsigned long V_160 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_92 V_93 ;
T_1 V_161 ;
int error ;
long V_24 ;
V_2 = F_97 ( V_53 ) ;
if ( ! V_2 )
return - V_123 ;
F_22 ( V_2 ) ;
error = V_24 = 0 ;
while ( V_160 ) {
void V_83 * V_154 ;
T_3 V_39 ;
error = F_108 ( V_154 , & V_148 -> V_90 ) ;
if ( F_40 ( error ) )
break;
error = F_108 ( V_39 , & V_148 -> V_91 ) ;
if ( F_40 ( error ) )
break;
if ( F_40 ( ! V_39 ) )
break;
if ( F_40 ( ! V_154 ) ) {
error = - V_146 ;
break;
}
if ( F_40 ( ! F_102 ( V_162 , V_154 , V_39 ) ) ) {
error = - V_146 ;
break;
}
V_93 . V_39 = 0 ;
V_93 . V_100 = V_39 ;
V_93 . V_10 = V_10 ;
V_93 . V_94 . V_159 = V_154 ;
V_93 . V_81 = 0 ;
V_161 = F_73 ( V_2 , & V_93 , F_104 ) ;
if ( V_161 < 0 ) {
if ( ! V_24 )
V_24 = V_161 ;
break;
}
V_24 += V_161 ;
if ( V_161 < V_39 )
break;
V_160 -- ;
V_148 ++ ;
}
F_27 ( V_2 ) ;
if ( ! V_24 )
V_24 = error ;
return V_24 ;
}
static long F_109 ( struct V_53 * V_53 , const struct V_77 V_83 * V_148 ,
unsigned long V_160 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_5 * V_36 [ V_50 ] ;
struct V_51 V_38 [ V_50 ] ;
struct V_20 V_21 = {
. V_36 = V_36 ,
. V_38 = V_38 ,
. V_10 = V_10 ,
. V_41 = & V_163 ,
. V_48 = F_28 ,
} ;
long V_24 ;
V_2 = F_97 ( V_53 ) ;
if ( ! V_2 )
return - V_123 ;
if ( F_29 ( V_2 , & V_21 ) )
return - V_52 ;
V_21 . V_23 = F_101 ( V_148 , V_160 , V_21 . V_36 ,
V_21 . V_38 , V_10 & V_42 ,
V_2 -> V_32 ) ;
if ( V_21 . V_23 <= 0 )
V_24 = V_21 . V_23 ;
else
V_24 = F_21 ( V_2 , & V_21 ) ;
F_32 ( V_2 , & V_21 ) ;
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
if ( ! V_2 -> V_117 )
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
static int F_98 ( struct V_1 * V_141 ,
struct V_1 * V_142 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_164 , * V_165 ;
int V_24 = 0 , V_166 ;
bool V_167 = false ;
V_168:
V_24 = F_110 ( V_141 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_111 ( V_142 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_112 ( V_141 , V_142 ) ;
do {
if ( ! V_142 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( ! V_141 -> V_31 && ! V_141 -> V_117 )
break;
if ( ! V_141 -> V_31 || V_142 -> V_31 >= V_142 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_44 ) {
V_24 = - V_45 ;
break;
}
F_27 ( V_141 ) ;
F_27 ( V_142 ) ;
goto V_168;
}
V_164 = V_141 -> V_35 + V_141 -> V_34 ;
V_166 = ( V_142 -> V_34 + V_142 -> V_31 ) & ( V_142 -> V_32 - 1 ) ;
V_165 = V_142 -> V_35 + V_166 ;
if ( V_39 >= V_164 -> V_39 ) {
* V_165 = * V_164 ;
V_164 -> V_41 = NULL ;
V_142 -> V_31 ++ ;
V_141 -> V_34 = ( V_141 -> V_34 + 1 ) & ( V_141 -> V_32 - 1 ) ;
V_141 -> V_31 -- ;
V_167 = true ;
} else {
V_164 -> V_41 -> V_169 ( V_141 , V_164 ) ;
* V_165 = * V_164 ;
V_165 -> V_10 &= ~ V_15 ;
V_165 -> V_39 = V_39 ;
V_142 -> V_31 ++ ;
V_164 -> V_37 += V_165 -> V_39 ;
V_164 -> V_39 -= V_165 -> V_39 ;
}
V_24 += V_165 -> V_39 ;
V_39 -= V_165 -> V_39 ;
} while ( V_39 );
F_27 ( V_141 ) ;
F_27 ( V_142 ) ;
if ( V_24 > 0 )
F_16 ( V_142 ) ;
if ( V_167 )
F_68 ( V_141 ) ;
return V_24 ;
}
static int F_113 ( struct V_1 * V_141 ,
struct V_1 * V_142 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_164 , * V_165 ;
int V_24 = 0 , V_49 = 0 , V_166 ;
F_112 ( V_141 , V_142 ) ;
do {
if ( ! V_142 -> V_27 ) {
F_23 ( V_28 , V_29 , 0 ) ;
if ( ! V_24 )
V_24 = - V_30 ;
break;
}
if ( V_49 >= V_141 -> V_31 || V_142 -> V_31 >= V_142 -> V_32 )
break;
V_164 = V_141 -> V_35 + ( ( V_141 -> V_34 + V_49 ) & ( V_141 -> V_32 - 1 ) ) ;
V_166 = ( V_142 -> V_34 + V_142 -> V_31 ) & ( V_142 -> V_32 - 1 ) ;
V_164 -> V_41 -> V_169 ( V_141 , V_164 ) ;
V_165 = V_142 -> V_35 + V_166 ;
* V_165 = * V_164 ;
V_165 -> V_10 &= ~ V_15 ;
if ( V_165 -> V_39 > V_39 )
V_165 -> V_39 = V_39 ;
V_142 -> V_31 ++ ;
V_24 += V_165 -> V_39 ;
V_39 -= V_165 -> V_39 ;
V_49 ++ ;
} while ( V_39 );
if ( ! V_24 && V_141 -> V_47 && ( V_10 & V_44 ) )
V_24 = - V_45 ;
F_27 ( V_141 ) ;
F_27 ( V_142 ) ;
if ( V_24 > 0 )
F_16 ( V_142 ) ;
return V_24 ;
}
static long F_114 ( struct V_53 * V_54 , struct V_53 * V_103 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_141 = F_97 ( V_54 ) ;
struct V_1 * V_142 = F_97 ( V_103 ) ;
int V_24 = - V_98 ;
if ( V_141 && V_142 && V_141 != V_142 ) {
V_24 = F_110 ( V_141 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_111 ( V_142 , V_10 ) ;
if ( ! V_24 )
V_24 = F_113 ( V_141 , V_142 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
