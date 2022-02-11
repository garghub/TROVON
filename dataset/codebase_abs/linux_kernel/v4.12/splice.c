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
int V_24 = 0 , V_25 = 0 ;
if ( ! V_22 )
return 0 ;
if ( F_22 ( ! V_2 -> V_26 ) ) {
F_23 ( V_27 , V_28 , 0 ) ;
V_24 = - V_29 ;
goto V_30;
}
while ( V_2 -> V_31 < V_2 -> V_32 ) {
int V_33 = ( V_2 -> V_34 + V_2 -> V_31 ) & ( V_2 -> V_32 - 1 ) ;
struct V_3 * V_4 = V_2 -> V_35 + V_33 ;
V_4 -> V_5 = V_21 -> V_36 [ V_25 ] ;
V_4 -> V_37 = V_21 -> V_38 [ V_25 ] . V_37 ;
V_4 -> V_39 = V_21 -> V_38 [ V_25 ] . V_39 ;
V_4 -> V_40 = V_21 -> V_38 [ V_25 ] . V_40 ;
V_4 -> V_41 = V_21 -> V_41 ;
V_4 -> V_10 = 0 ;
V_2 -> V_31 ++ ;
V_25 ++ ;
V_24 += V_4 -> V_39 ;
if ( ! -- V_21 -> V_23 )
break;
}
if ( ! V_24 )
V_24 = - V_42 ;
V_30:
while ( V_25 < V_22 )
V_21 -> V_43 ( V_21 , V_25 ++ ) ;
return V_24 ;
}
T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_24 ;
if ( F_22 ( ! V_2 -> V_26 ) ) {
F_23 ( V_27 , V_28 , 0 ) ;
V_24 = - V_29 ;
} else if ( V_2 -> V_31 == V_2 -> V_32 ) {
V_24 = - V_42 ;
} else {
int V_33 = ( V_2 -> V_34 + V_2 -> V_31 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_35 [ V_33 ] = * V_4 ;
V_2 -> V_31 ++ ;
return V_4 -> V_39 ;
}
F_25 ( V_2 , V_4 ) ;
return V_24 ;
}
int F_26 ( const struct V_1 * V_2 , struct V_20 * V_21 )
{
unsigned int V_32 = F_27 ( V_2 -> V_32 ) ;
V_21 -> V_44 = V_32 ;
if ( V_32 <= V_45 )
return 0 ;
V_21 -> V_36 = F_28 ( V_32 * sizeof( struct V_5 * ) , V_8 ) ;
V_21 -> V_38 = F_28 ( V_32 * sizeof( struct V_46 ) , V_8 ) ;
if ( V_21 -> V_36 && V_21 -> V_38 )
return 0 ;
F_29 ( V_21 -> V_36 ) ;
F_29 ( V_21 -> V_38 ) ;
return - V_47 ;
}
void F_30 ( struct V_20 * V_21 )
{
if ( V_21 -> V_44 <= V_45 )
return;
F_29 ( V_21 -> V_36 ) ;
F_29 ( V_21 -> V_38 ) ;
}
T_1 F_31 ( struct V_48 * V_49 , T_2 * V_50 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_51 V_52 ;
struct V_53 V_53 ;
int V_54 , V_24 ;
F_32 ( & V_52 , V_55 | V_56 , V_2 , V_39 ) ;
V_54 = V_52 . V_54 ;
F_33 ( & V_53 , V_49 ) ;
V_53 . V_57 = * V_50 ;
V_24 = F_34 ( V_49 , & V_53 , & V_52 ) ;
if ( V_24 > 0 ) {
* V_50 = V_53 . V_57 ;
F_35 ( V_49 ) ;
} else if ( V_24 < 0 ) {
V_52 . V_54 = V_54 ;
V_52 . V_58 = 0 ;
F_36 ( & V_52 , 0 ) ;
if ( V_24 == - V_59 )
V_24 = - V_42 ;
}
return V_24 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static T_1 F_38 ( struct V_48 * V_48 , const struct V_60 * V_61 ,
unsigned long V_62 , T_2 V_37 )
{
T_4 V_63 ;
T_2 V_64 = V_37 ;
T_1 V_65 ;
V_63 = F_39 () ;
F_40 ( F_41 () ) ;
V_65 = F_42 ( V_48 , ( const struct V_66 V_67 * ) V_61 , V_62 , & V_64 , 0 ) ;
F_40 ( V_63 ) ;
return V_65 ;
}
T_1 F_43 ( struct V_48 * V_48 , const char * V_4 , T_3 V_68 ,
T_2 V_64 )
{
T_4 V_63 ;
T_1 V_65 ;
V_63 = F_39 () ;
F_40 ( F_41 () ) ;
V_65 = F_44 ( V_48 , ( V_69 const char V_67 * ) V_4 , V_68 , & V_64 ) ;
F_40 ( V_63 ) ;
return V_65 ;
}
static T_1 F_45 ( struct V_48 * V_49 , T_2 * V_50 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_60 * V_61 , V_70 [ V_45 ] ;
struct V_51 V_52 ;
struct V_5 * * V_36 ;
unsigned int V_23 ;
T_3 V_37 , V_71 , V_72 = 0 ;
T_1 V_65 ;
int V_73 ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return - V_42 ;
V_37 = * V_50 & ~ V_74 ;
F_32 ( & V_52 , V_55 | V_56 , V_2 , V_39 + V_37 ) ;
V_65 = F_46 ( & V_52 , & V_36 , V_39 + V_37 , & V_71 ) ;
if ( V_65 <= 0 )
return - V_47 ;
V_23 = F_47 ( V_65 + V_71 , V_75 ) ;
V_61 = V_70 ;
if ( V_23 > V_45 ) {
V_61 = F_28 ( V_23 * sizeof( struct V_60 ) , V_8 ) ;
if ( F_22 ( ! V_61 ) ) {
V_65 = - V_47 ;
goto V_30;
}
}
V_2 -> V_35 [ V_52 . V_54 ] . V_37 = V_37 ;
V_2 -> V_35 [ V_52 . V_54 ] . V_39 -= V_37 ;
for ( V_73 = 0 ; V_73 < V_23 ; V_73 ++ ) {
T_3 V_76 = F_48 ( T_3 , V_39 , V_75 - V_37 ) ;
V_61 [ V_73 ] . V_77 = F_49 ( V_36 [ V_73 ] ) + V_37 ;
V_61 [ V_73 ] . V_78 = V_76 ;
V_39 -= V_76 ;
V_37 = 0 ;
}
V_65 = F_38 ( V_49 , V_61 , V_23 , * V_50 ) ;
if ( V_65 > 0 ) {
V_72 = V_65 ;
* V_50 += V_65 ;
}
if ( V_61 != V_70 )
F_29 ( V_61 ) ;
V_30:
for ( V_73 = 0 ; V_73 < V_23 ; V_73 ++ )
F_12 ( V_36 [ V_73 ] ) ;
F_50 ( V_36 ) ;
F_36 ( & V_52 , V_72 ) ;
return V_65 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_79 * V_80 )
{
struct V_48 * V_48 = V_80 -> V_81 . V_48 ;
T_2 V_64 = V_80 -> V_64 ;
int V_82 ;
if ( ! F_52 ( V_48 -> V_83 -> V_84 ) )
return - V_85 ;
V_82 = ( V_80 -> V_10 & V_86 ) ? V_87 : 0 ;
if ( V_80 -> V_39 < V_80 -> V_88 && V_2 -> V_31 > 1 )
V_82 |= V_89 ;
return V_48 -> V_83 -> V_84 ( V_48 , V_4 -> V_5 , V_4 -> V_37 ,
V_80 -> V_39 , & V_64 , V_82 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_90 , V_18 , V_91 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_79 * V_80 ,
T_5 * V_92 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
V_80 -> V_39 = V_4 -> V_39 ;
if ( V_80 -> V_39 > V_80 -> V_88 )
V_80 -> V_39 = V_80 -> V_88 ;
V_24 = F_55 ( V_2 , V_4 ) ;
if ( F_22 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_92 ( V_2 , V_4 , V_80 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_80 -> V_93 += V_24 ;
V_80 -> V_39 -= V_24 ;
V_80 -> V_64 += V_24 ;
V_80 -> V_88 -= V_24 ;
if ( ! V_4 -> V_39 ) {
F_25 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_94 )
V_80 -> V_95 = true ;
}
if ( ! V_80 -> V_88 )
return 0 ;
}
return 1 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
if ( F_57 ( V_28 ) )
return - V_96 ;
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_97 )
return 0 ;
if ( ! V_2 -> V_98 && V_80 -> V_93 )
return 0 ;
if ( V_80 -> V_10 & V_99 )
return - V_42 ;
if ( F_57 ( V_28 ) )
return - V_96 ;
if ( V_80 -> V_95 ) {
F_53 ( V_2 ) ;
V_80 -> V_95 = false ;
}
F_58 ( V_2 ) ;
}
return 1 ;
}
static void F_59 ( struct V_79 * V_80 )
{
V_80 -> V_93 = 0 ;
V_80 -> V_95 = false ;
}
static void F_60 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
if ( V_80 -> V_95 )
F_53 ( V_2 ) ;
}
T_1 F_61 ( struct V_1 * V_2 , struct V_79 * V_80 ,
T_5 * V_92 )
{
int V_24 ;
F_59 ( V_80 ) ;
do {
F_62 () ;
V_24 = F_56 ( V_2 , V_80 ) ;
if ( V_24 > 0 )
V_24 = F_54 ( V_2 , V_80 , V_92 ) ;
} while ( V_24 > 0 );
F_60 ( V_2 , V_80 ) ;
return V_80 -> V_93 ? V_80 -> V_93 : V_24 ;
}
T_1 F_63 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 ,
T_5 * V_92 )
{
T_1 V_24 ;
struct V_79 V_80 = {
. V_88 = V_39 ,
. V_10 = V_10 ,
. V_64 = * V_50 ,
. V_81 . V_48 = V_30 ,
} ;
F_64 ( V_2 ) ;
V_24 = F_61 ( V_2 , & V_80 , V_92 ) ;
F_65 ( V_2 ) ;
return V_24 ;
}
T_1
F_66 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 )
{
struct V_79 V_80 = {
. V_88 = V_39 ,
. V_10 = V_10 ,
. V_64 = * V_50 ,
. V_81 . V_48 = V_30 ,
} ;
int V_100 = V_2 -> V_32 ;
struct V_101 * V_102 = F_67 ( V_100 , sizeof( struct V_101 ) ,
V_8 ) ;
T_1 V_24 ;
if ( F_22 ( ! V_102 ) )
return - V_47 ;
F_64 ( V_2 ) ;
F_59 ( & V_80 ) ;
while ( V_80 . V_88 ) {
struct V_51 V_103 ;
T_3 V_104 ;
int V_105 , V_54 ;
V_24 = F_56 ( V_2 , & V_80 ) ;
if ( V_24 <= 0 )
break;
if ( F_22 ( V_100 < V_2 -> V_32 ) ) {
F_29 ( V_102 ) ;
V_100 = V_2 -> V_32 ;
V_102 = F_67 ( V_100 , sizeof( struct V_101 ) ,
V_8 ) ;
if ( ! V_102 ) {
V_24 = - V_47 ;
break;
}
}
V_104 = V_80 . V_88 ;
for ( V_105 = 0 , V_54 = V_2 -> V_34 ; V_104 && V_105 < V_2 -> V_31 ; V_105 ++ , V_54 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_54 ;
T_3 V_76 = V_4 -> V_39 ;
if ( V_76 > V_104 )
V_76 = V_104 ;
if ( V_54 == V_2 -> V_32 - 1 )
V_54 = - 1 ;
V_24 = F_55 ( V_2 , V_4 ) ;
if ( F_22 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
goto V_106;
}
V_102 [ V_105 ] . V_107 = V_4 -> V_5 ;
V_102 [ V_105 ] . V_108 = V_76 ;
V_102 [ V_105 ] . V_109 = V_4 -> V_37 ;
V_104 -= V_76 ;
}
F_68 ( & V_103 , V_110 | V_111 , V_102 , V_105 ,
V_80 . V_88 - V_104 ) ;
V_24 = F_69 ( V_30 , & V_103 , & V_80 . V_64 ) ;
if ( V_24 <= 0 )
break;
V_80 . V_93 += V_24 ;
V_80 . V_88 -= V_24 ;
* V_50 = V_80 . V_64 ;
while ( V_24 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
if ( V_24 >= V_4 -> V_39 ) {
V_24 -= V_4 -> V_39 ;
V_4 -> V_39 = 0 ;
F_25 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_94 )
V_80 . V_95 = true ;
} else {
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_24 = 0 ;
}
}
}
V_106:
F_29 ( V_102 ) ;
F_60 ( V_2 , & V_80 ) ;
F_65 ( V_2 ) ;
if ( V_80 . V_93 )
V_24 = V_80 . V_93 ;
return V_24 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_79 * V_80 )
{
int V_24 ;
void * V_112 ;
T_2 V_113 = V_80 -> V_64 ;
V_112 = F_71 ( V_4 -> V_5 ) ;
V_24 = F_72 ( V_80 -> V_81 . V_48 , V_112 + V_4 -> V_37 , V_80 -> V_39 , & V_113 ) ;
F_73 ( V_4 -> V_5 ) ;
return V_24 ;
}
static T_1 F_74 ( struct V_1 * V_2 ,
struct V_48 * V_30 , T_2 * V_50 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_63 ( V_2 , V_30 , V_50 , V_39 , V_10 , F_70 ) ;
if ( V_24 > 0 )
* V_50 += V_24 ;
return V_24 ;
}
T_1 F_75 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 )
{
return F_63 ( V_2 , V_30 , V_50 , V_39 , V_10 , F_51 ) ;
}
static long F_76 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_77)( struct V_1 * , struct V_48 * ,
T_2 * , T_3 , unsigned int );
if ( V_30 -> V_83 -> F_77 )
F_77 = V_30 -> V_83 -> F_77 ;
else
F_77 = F_74 ;
return F_77 ( V_2 , V_30 , V_50 , V_39 , V_10 ) ;
}
static long F_78 ( struct V_48 * V_49 , T_2 * V_50 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_79)( struct V_48 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_22 ( ! ( V_49 -> V_114 & V_115 ) ) )
return - V_116 ;
V_24 = F_80 ( V_56 , V_49 , V_50 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
if ( F_22 ( V_39 > V_117 ) )
V_39 = V_117 ;
if ( V_49 -> V_83 -> F_79 )
F_79 = V_49 -> V_83 -> F_79 ;
else
F_79 = F_45 ;
return F_79 ( V_49 , V_50 , V_2 , V_39 , V_10 ) ;
}
T_1 F_81 ( struct V_48 * V_49 , struct V_79 * V_80 ,
T_6 * V_92 )
{
struct V_1 * V_2 ;
long V_24 , V_118 ;
T_7 V_119 ;
T_3 V_39 ;
int V_73 , V_10 , V_82 ;
V_119 = F_82 ( V_49 ) -> V_119 ;
if ( F_22 ( ! F_83 ( V_119 ) && ! F_84 ( V_119 ) ) )
return - V_85 ;
V_2 = V_28 -> V_120 ;
if ( F_22 ( ! V_2 ) ) {
V_2 = F_85 () ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_26 = 1 ;
V_28 -> V_120 = V_2 ;
}
V_24 = 0 ;
V_118 = 0 ;
V_39 = V_80 -> V_88 ;
V_10 = V_80 -> V_10 ;
V_80 -> V_10 &= ~ V_99 ;
V_82 = V_80 -> V_10 & V_86 ;
while ( V_39 ) {
T_3 V_121 ;
T_2 V_64 = V_80 -> V_64 , V_122 = V_64 ;
V_24 = F_78 ( V_49 , & V_64 , V_2 , V_39 , V_10 ) ;
if ( F_22 ( V_24 <= 0 ) )
goto V_123;
V_121 = V_24 ;
V_80 -> V_88 = V_121 ;
if ( V_121 < V_39 )
V_80 -> V_10 |= V_86 ;
else if ( ! V_82 )
V_80 -> V_10 &= ~ V_86 ;
V_24 = V_92 ( V_2 , V_80 ) ;
if ( F_22 ( V_24 <= 0 ) ) {
V_80 -> V_64 = V_122 ;
goto V_123;
}
V_118 += V_24 ;
V_39 -= V_24 ;
V_80 -> V_64 = V_64 ;
if ( V_24 < V_121 ) {
V_80 -> V_64 = V_122 + V_24 ;
goto V_123;
}
}
V_106:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_35 ( V_49 ) ;
return V_118 ;
V_123:
for ( V_73 = 0 ; V_73 < V_2 -> V_32 ; V_73 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_73 ;
if ( V_4 -> V_41 )
F_25 ( V_2 , V_4 ) ;
}
if ( ! V_118 )
V_118 = V_24 ;
goto V_106;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_48 * V_48 = V_80 -> V_81 . V_48 ;
return F_76 ( V_2 , V_48 , V_80 -> V_124 , V_80 -> V_88 ,
V_80 -> V_10 ) ;
}
long F_87 ( struct V_48 * V_49 , T_2 * V_50 , struct V_48 * V_30 ,
T_2 * V_124 , T_3 V_39 , unsigned int V_10 )
{
struct V_79 V_80 = {
. V_39 = V_39 ,
. V_88 = V_39 ,
. V_10 = V_10 ,
. V_64 = * V_50 ,
. V_81 . V_48 = V_30 ,
. V_124 = V_124 ,
} ;
long V_24 ;
if ( F_22 ( ! ( V_30 -> V_114 & V_125 ) ) )
return - V_116 ;
if ( F_22 ( V_30 -> V_126 & V_127 ) )
return - V_85 ;
V_24 = F_80 ( V_111 , V_30 , V_124 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
V_24 = F_81 ( V_49 , & V_80 , F_86 ) ;
if ( V_24 > 0 )
* V_50 = V_80 . V_64 ;
return V_24 ;
}
static int F_88 ( struct V_1 * V_2 , unsigned V_10 )
{
for (; ; ) {
if ( F_22 ( ! V_2 -> V_26 ) ) {
F_23 ( V_27 , V_28 , 0 ) ;
return - V_29 ;
}
if ( V_2 -> V_31 != V_2 -> V_32 )
return 0 ;
if ( V_10 & V_99 )
return - V_42 ;
if ( F_57 ( V_28 ) )
return - V_96 ;
V_2 -> V_98 ++ ;
F_58 ( V_2 ) ;
V_2 -> V_98 -- ;
}
}
static long F_89 ( struct V_48 * V_49 , T_2 V_67 * V_128 ,
struct V_48 * V_30 , T_2 V_67 * V_129 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_130 ;
struct V_1 * V_131 ;
T_2 V_37 ;
long V_24 ;
V_130 = F_90 ( V_49 ) ;
V_131 = F_90 ( V_30 ) ;
if ( V_130 && V_131 ) {
if ( V_128 || V_129 )
return - V_132 ;
if ( ! ( V_49 -> V_114 & V_115 ) )
return - V_116 ;
if ( ! ( V_30 -> V_114 & V_125 ) )
return - V_116 ;
if ( V_130 == V_131 )
return - V_85 ;
return F_91 ( V_130 , V_131 , V_39 , V_10 ) ;
}
if ( V_130 ) {
if ( V_128 )
return - V_132 ;
if ( V_129 ) {
if ( ! ( V_30 -> V_114 & V_133 ) )
return - V_85 ;
if ( F_92 ( & V_37 , V_129 , sizeof( T_2 ) ) )
return - V_59 ;
} else {
V_37 = V_30 -> V_134 ;
}
if ( F_22 ( ! ( V_30 -> V_114 & V_125 ) ) )
return - V_116 ;
if ( F_22 ( V_30 -> V_126 & V_127 ) )
return - V_85 ;
V_24 = F_80 ( V_111 , V_30 , & V_37 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
F_93 ( V_30 ) ;
V_24 = F_76 ( V_130 , V_30 , & V_37 , V_39 , V_10 ) ;
F_94 ( V_30 ) ;
if ( ! V_129 )
V_30 -> V_134 = V_37 ;
else if ( F_95 ( V_129 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_59 ;
return V_24 ;
}
if ( V_131 ) {
if ( V_129 )
return - V_132 ;
if ( V_128 ) {
if ( ! ( V_49 -> V_114 & V_135 ) )
return - V_85 ;
if ( F_92 ( & V_37 , V_128 , sizeof( T_2 ) ) )
return - V_59 ;
} else {
V_37 = V_49 -> V_134 ;
}
F_64 ( V_131 ) ;
V_24 = F_88 ( V_131 , V_10 ) ;
if ( ! V_24 )
V_24 = F_78 ( V_49 , & V_37 , V_131 , V_39 , V_10 ) ;
F_65 ( V_131 ) ;
if ( V_24 > 0 )
F_16 ( V_131 ) ;
if ( ! V_128 )
V_49 -> V_134 = V_37 ;
else if ( F_95 ( V_128 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_59 ;
return V_24 ;
}
return - V_85 ;
}
static int F_96 ( struct V_51 * V_103 ,
struct V_1 * V_2 ,
unsigned V_10 )
{
struct V_3 V_4 = {
. V_41 = & V_136 ,
. V_10 = V_10
} ;
T_3 V_137 = 0 ;
int V_24 = 0 ;
bool V_138 = false ;
while ( F_97 ( V_103 ) && ! V_138 ) {
struct V_5 * V_36 [ 16 ] ;
T_1 V_72 ;
T_3 V_139 ;
int V_105 ;
V_72 = F_98 ( V_103 , V_36 , ~ 0UL , 16 , & V_139 ) ;
if ( V_72 <= 0 ) {
V_24 = V_72 ;
break;
}
for ( V_105 = 0 ; V_72 ; V_105 ++ , V_139 = 0 ) {
int V_140 = F_48 ( int , V_72 , V_75 - V_139 ) ;
if ( ! V_138 ) {
V_4 . V_5 = V_36 [ V_105 ] ;
V_4 . V_37 = V_139 ;
V_4 . V_39 = V_140 ;
V_24 = F_24 ( V_2 , & V_4 ) ;
if ( F_22 ( V_24 < 0 ) ) {
V_138 = true ;
} else {
F_36 ( V_103 , V_24 ) ;
V_137 += V_24 ;
}
} else {
F_12 ( V_36 [ V_105 ] ) ;
}
V_72 -= V_140 ;
}
}
return V_137 ? V_137 : V_24 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_79 * V_80 )
{
int V_105 = F_100 ( V_4 -> V_5 , V_4 -> V_37 , V_80 -> V_39 , V_80 -> V_81 . V_112 ) ;
return V_105 == V_80 -> V_39 ? V_105 : - V_59 ;
}
static long F_101 ( struct V_48 * V_48 , const struct V_66 V_67 * V_141 ,
unsigned long V_142 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_79 V_80 ;
long V_24 ;
struct V_66 V_143 [ V_144 ] ;
struct V_66 * V_145 = V_143 ;
struct V_51 V_146 ;
V_2 = F_90 ( V_48 ) ;
if ( ! V_2 )
return - V_116 ;
V_24 = F_102 ( V_56 , V_141 , V_142 ,
F_103 ( V_143 ) , & V_145 , & V_146 ) ;
if ( V_24 < 0 )
return V_24 ;
V_80 . V_88 = F_97 ( & V_146 ) ;
V_80 . V_39 = 0 ;
V_80 . V_10 = V_10 ;
V_80 . V_81 . V_112 = & V_146 ;
V_80 . V_64 = 0 ;
if ( V_80 . V_88 ) {
F_64 ( V_2 ) ;
V_24 = F_61 ( V_2 , & V_80 , F_99 ) ;
F_65 ( V_2 ) ;
}
F_29 ( V_145 ) ;
return V_24 ;
}
static long F_104 ( struct V_48 * V_48 , const struct V_66 V_67 * V_141 ,
unsigned long V_142 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_66 V_143 [ V_144 ] ;
struct V_66 * V_145 = V_143 ;
struct V_51 V_103 ;
long V_24 ;
unsigned V_147 = 0 ;
if ( V_10 & V_148 )
V_147 = V_15 ;
V_2 = F_90 ( V_48 ) ;
if ( ! V_2 )
return - V_116 ;
V_24 = F_102 ( V_111 , V_141 , V_142 ,
F_103 ( V_143 ) , & V_145 , & V_103 ) ;
if ( V_24 < 0 )
return V_24 ;
F_64 ( V_2 ) ;
V_24 = F_88 ( V_2 , V_10 ) ;
if ( ! V_24 )
V_24 = F_96 ( & V_103 , V_2 , V_147 ) ;
F_65 ( V_2 ) ;
if ( V_24 > 0 )
F_16 ( V_2 ) ;
F_29 ( V_145 ) ;
return V_24 ;
}
static int F_105 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 )
return 0 ;
V_24 = 0 ;
F_64 ( V_2 ) ;
while ( ! V_2 -> V_31 ) {
if ( F_57 ( V_28 ) ) {
V_24 = - V_96 ;
break;
}
if ( ! V_2 -> V_97 )
break;
if ( ! V_2 -> V_98 ) {
if ( V_10 & V_99 ) {
V_24 = - V_42 ;
break;
}
}
F_58 ( V_2 ) ;
}
F_65 ( V_2 ) ;
return V_24 ;
}
static int F_106 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 < V_2 -> V_32 )
return 0 ;
V_24 = 0 ;
F_64 ( V_2 ) ;
while ( V_2 -> V_31 >= V_2 -> V_32 ) {
if ( ! V_2 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
V_24 = - V_29 ;
break;
}
if ( V_10 & V_99 ) {
V_24 = - V_42 ;
break;
}
if ( F_57 ( V_28 ) ) {
V_24 = - V_96 ;
break;
}
V_2 -> V_98 ++ ;
F_58 ( V_2 ) ;
V_2 -> V_98 -- ;
}
F_65 ( V_2 ) ;
return V_24 ;
}
static int F_91 ( struct V_1 * V_130 ,
struct V_1 * V_131 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_149 , * V_150 ;
int V_24 = 0 , V_151 ;
bool V_152 = false ;
V_153:
V_24 = F_105 ( V_130 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_106 ( V_131 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_107 ( V_130 , V_131 ) ;
do {
if ( ! V_131 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( ! V_130 -> V_31 && ! V_130 -> V_97 )
break;
if ( ! V_130 -> V_31 || V_131 -> V_31 >= V_131 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_99 ) {
V_24 = - V_42 ;
break;
}
F_65 ( V_130 ) ;
F_65 ( V_131 ) ;
goto V_153;
}
V_149 = V_130 -> V_35 + V_130 -> V_34 ;
V_151 = ( V_131 -> V_34 + V_131 -> V_31 ) & ( V_131 -> V_32 - 1 ) ;
V_150 = V_131 -> V_35 + V_151 ;
if ( V_39 >= V_149 -> V_39 ) {
* V_150 = * V_149 ;
V_149 -> V_41 = NULL ;
V_131 -> V_31 ++ ;
V_130 -> V_34 = ( V_130 -> V_34 + 1 ) & ( V_130 -> V_32 - 1 ) ;
V_130 -> V_31 -- ;
V_152 = true ;
} else {
F_108 ( V_130 , V_149 ) ;
* V_150 = * V_149 ;
V_150 -> V_10 &= ~ V_15 ;
V_150 -> V_39 = V_39 ;
V_131 -> V_31 ++ ;
V_149 -> V_37 += V_150 -> V_39 ;
V_149 -> V_39 -= V_150 -> V_39 ;
}
V_24 += V_150 -> V_39 ;
V_39 -= V_150 -> V_39 ;
} while ( V_39 );
F_65 ( V_130 ) ;
F_65 ( V_131 ) ;
if ( V_24 > 0 )
F_16 ( V_131 ) ;
if ( V_152 )
F_53 ( V_130 ) ;
return V_24 ;
}
static int F_109 ( struct V_1 * V_130 ,
struct V_1 * V_131 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_149 , * V_150 ;
int V_24 = 0 , V_73 = 0 , V_151 ;
F_107 ( V_130 , V_131 ) ;
do {
if ( ! V_131 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( V_73 >= V_130 -> V_31 || V_131 -> V_31 >= V_131 -> V_32 )
break;
V_149 = V_130 -> V_35 + ( ( V_130 -> V_34 + V_73 ) & ( V_130 -> V_32 - 1 ) ) ;
V_151 = ( V_131 -> V_34 + V_131 -> V_31 ) & ( V_131 -> V_32 - 1 ) ;
F_108 ( V_130 , V_149 ) ;
V_150 = V_131 -> V_35 + V_151 ;
* V_150 = * V_149 ;
V_150 -> V_10 &= ~ V_15 ;
if ( V_150 -> V_39 > V_39 )
V_150 -> V_39 = V_39 ;
V_131 -> V_31 ++ ;
V_24 += V_150 -> V_39 ;
V_39 -= V_150 -> V_39 ;
V_73 ++ ;
} while ( V_39 );
if ( ! V_24 && V_130 -> V_98 && ( V_10 & V_99 ) )
V_24 = - V_42 ;
F_65 ( V_130 ) ;
F_65 ( V_131 ) ;
if ( V_24 > 0 )
F_16 ( V_131 ) ;
return V_24 ;
}
static long F_110 ( struct V_48 * V_49 , struct V_48 * V_30 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_130 = F_90 ( V_49 ) ;
struct V_1 * V_131 = F_90 ( V_30 ) ;
int V_24 = - V_85 ;
if ( V_130 && V_131 && V_130 != V_131 ) {
V_24 = F_105 ( V_130 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_106 ( V_131 , V_10 ) ;
if ( ! V_24 )
V_24 = F_109 ( V_130 , V_131 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
