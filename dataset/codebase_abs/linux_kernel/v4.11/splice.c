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
void F_26 ( struct V_20 * V_21 , unsigned int V_44 )
{
F_12 ( V_21 -> V_36 [ V_44 ] ) ;
}
int F_27 ( const struct V_1 * V_2 , struct V_20 * V_21 )
{
unsigned int V_32 = F_28 ( V_2 -> V_32 ) ;
V_21 -> V_45 = V_32 ;
if ( V_32 <= V_46 )
return 0 ;
V_21 -> V_36 = F_29 ( V_32 * sizeof( struct V_5 * ) , V_8 ) ;
V_21 -> V_38 = F_29 ( V_32 * sizeof( struct V_47 ) , V_8 ) ;
if ( V_21 -> V_36 && V_21 -> V_38 )
return 0 ;
F_30 ( V_21 -> V_36 ) ;
F_30 ( V_21 -> V_38 ) ;
return - V_48 ;
}
void F_31 ( struct V_20 * V_21 )
{
if ( V_21 -> V_45 <= V_46 )
return;
F_30 ( V_21 -> V_36 ) ;
F_30 ( V_21 -> V_38 ) ;
}
T_1 F_32 ( struct V_49 * V_50 , T_2 * V_51 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_52 V_53 ;
struct V_54 V_54 ;
int V_55 , V_24 ;
F_33 ( & V_53 , V_56 | V_57 , V_2 , V_39 ) ;
V_55 = V_53 . V_55 ;
F_34 ( & V_54 , V_50 ) ;
V_54 . V_58 = * V_51 ;
V_24 = F_35 ( V_50 , & V_54 , & V_53 ) ;
if ( V_24 > 0 ) {
* V_51 = V_54 . V_58 ;
F_36 ( V_50 ) ;
} else if ( V_24 < 0 ) {
V_53 . V_55 = V_55 ;
V_53 . V_59 = 0 ;
F_37 ( & V_53 , 0 ) ;
if ( V_24 == - V_60 )
V_24 = - V_42 ;
}
return V_24 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static T_1 F_39 ( struct V_49 * V_49 , const struct V_61 * V_62 ,
unsigned long V_63 , T_2 V_37 )
{
T_4 V_64 ;
T_2 V_65 = V_37 ;
T_1 V_66 ;
V_64 = F_40 () ;
F_41 ( F_42 () ) ;
V_66 = F_43 ( V_49 , ( const struct V_67 V_68 * ) V_62 , V_63 , & V_65 , 0 ) ;
F_41 ( V_64 ) ;
return V_66 ;
}
T_1 F_44 ( struct V_49 * V_49 , const char * V_4 , T_3 V_69 ,
T_2 V_65 )
{
T_4 V_64 ;
T_1 V_66 ;
V_64 = F_40 () ;
F_41 ( F_42 () ) ;
V_66 = F_45 ( V_49 , ( V_70 const char V_68 * ) V_4 , V_69 , & V_65 ) ;
F_41 ( V_64 ) ;
return V_66 ;
}
static T_1 F_46 ( struct V_49 * V_50 , T_2 * V_51 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_61 * V_62 , V_71 [ V_46 ] ;
struct V_52 V_53 ;
struct V_5 * * V_36 ;
unsigned int V_23 ;
T_3 V_37 , V_72 , V_73 = 0 ;
T_1 V_66 ;
int V_44 ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return - V_42 ;
V_37 = * V_51 & ~ V_74 ;
F_33 ( & V_53 , V_56 | V_57 , V_2 , V_39 + V_37 ) ;
V_66 = F_47 ( & V_53 , & V_36 , V_39 + V_37 , & V_72 ) ;
if ( V_66 <= 0 )
return - V_48 ;
F_48 ( V_72 ) ;
V_23 = F_49 ( V_66 , V_75 ) ;
V_62 = V_71 ;
if ( V_23 > V_46 ) {
V_62 = F_29 ( V_23 * sizeof( struct V_61 ) , V_8 ) ;
if ( F_22 ( ! V_62 ) ) {
V_66 = - V_48 ;
goto V_30;
}
}
V_2 -> V_35 [ V_53 . V_55 ] . V_37 = V_37 ;
V_2 -> V_35 [ V_53 . V_55 ] . V_39 -= V_37 ;
for ( V_44 = 0 ; V_44 < V_23 ; V_44 ++ ) {
T_3 V_76 = F_50 ( T_3 , V_39 , V_75 - V_37 ) ;
V_62 [ V_44 ] . V_77 = F_51 ( V_36 [ V_44 ] ) + V_37 ;
V_62 [ V_44 ] . V_78 = V_76 ;
V_39 -= V_76 ;
V_37 = 0 ;
}
V_66 = F_39 ( V_50 , V_62 , V_23 , * V_51 ) ;
if ( V_66 > 0 ) {
V_73 = V_66 ;
* V_51 += V_66 ;
}
if ( V_62 != V_71 )
F_30 ( V_62 ) ;
V_30:
for ( V_44 = 0 ; V_44 < V_23 ; V_44 ++ )
F_12 ( V_36 [ V_44 ] ) ;
F_52 ( V_36 ) ;
F_37 ( & V_53 , V_73 ) ;
return V_66 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_79 * V_80 )
{
struct V_49 * V_49 = V_80 -> V_81 . V_49 ;
T_2 V_65 = V_80 -> V_65 ;
int V_82 ;
if ( ! F_54 ( V_49 -> V_83 -> V_84 ) )
return - V_85 ;
V_82 = ( V_80 -> V_10 & V_86 ) ? V_87 : 0 ;
if ( V_80 -> V_39 < V_80 -> V_88 && V_2 -> V_31 > 1 )
V_82 |= V_89 ;
return V_49 -> V_83 -> V_84 ( V_49 , V_4 -> V_5 , V_4 -> V_37 ,
V_80 -> V_39 , & V_65 , V_82 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_90 , V_18 , V_91 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_79 * V_80 ,
T_5 * V_92 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
V_80 -> V_39 = V_4 -> V_39 ;
if ( V_80 -> V_39 > V_80 -> V_88 )
V_80 -> V_39 = V_80 -> V_88 ;
V_24 = F_57 ( V_2 , V_4 ) ;
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
V_80 -> V_65 += V_24 ;
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
static int F_58 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
if ( F_59 ( V_28 ) )
return - V_96 ;
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_97 )
return 0 ;
if ( ! V_2 -> V_98 && V_80 -> V_93 )
return 0 ;
if ( V_80 -> V_10 & V_99 )
return - V_42 ;
if ( F_59 ( V_28 ) )
return - V_96 ;
if ( V_80 -> V_95 ) {
F_55 ( V_2 ) ;
V_80 -> V_95 = false ;
}
F_60 ( V_2 ) ;
}
return 1 ;
}
static void F_61 ( struct V_79 * V_80 )
{
V_80 -> V_93 = 0 ;
V_80 -> V_95 = false ;
}
static void F_62 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
if ( V_80 -> V_95 )
F_55 ( V_2 ) ;
}
T_1 F_63 ( struct V_1 * V_2 , struct V_79 * V_80 ,
T_5 * V_92 )
{
int V_24 ;
F_61 ( V_80 ) ;
do {
F_64 () ;
V_24 = F_58 ( V_2 , V_80 ) ;
if ( V_24 > 0 )
V_24 = F_56 ( V_2 , V_80 , V_92 ) ;
} while ( V_24 > 0 );
F_62 ( V_2 , V_80 ) ;
return V_80 -> V_93 ? V_80 -> V_93 : V_24 ;
}
T_1 F_65 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 ,
T_5 * V_92 )
{
T_1 V_24 ;
struct V_79 V_80 = {
. V_88 = V_39 ,
. V_10 = V_10 ,
. V_65 = * V_51 ,
. V_81 . V_49 = V_30 ,
} ;
F_66 ( V_2 ) ;
V_24 = F_63 ( V_2 , & V_80 , V_92 ) ;
F_67 ( V_2 ) ;
return V_24 ;
}
T_1
F_68 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 )
{
struct V_79 V_80 = {
. V_88 = V_39 ,
. V_10 = V_10 ,
. V_65 = * V_51 ,
. V_81 . V_49 = V_30 ,
} ;
int V_100 = V_2 -> V_32 ;
struct V_101 * V_102 = F_69 ( V_100 , sizeof( struct V_101 ) ,
V_8 ) ;
T_1 V_24 ;
if ( F_22 ( ! V_102 ) )
return - V_48 ;
F_66 ( V_2 ) ;
F_61 ( & V_80 ) ;
while ( V_80 . V_88 ) {
struct V_52 V_103 ;
T_3 V_104 ;
int V_105 , V_55 ;
V_24 = F_58 ( V_2 , & V_80 ) ;
if ( V_24 <= 0 )
break;
if ( F_22 ( V_100 < V_2 -> V_32 ) ) {
F_30 ( V_102 ) ;
V_100 = V_2 -> V_32 ;
V_102 = F_69 ( V_100 , sizeof( struct V_101 ) ,
V_8 ) ;
if ( ! V_102 ) {
V_24 = - V_48 ;
break;
}
}
V_104 = V_80 . V_88 ;
for ( V_105 = 0 , V_55 = V_2 -> V_34 ; V_104 && V_105 < V_2 -> V_31 ; V_105 ++ , V_55 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_55 ;
T_3 V_76 = V_4 -> V_39 ;
if ( V_76 > V_104 )
V_76 = V_104 ;
if ( V_55 == V_2 -> V_32 - 1 )
V_55 = - 1 ;
V_24 = F_57 ( V_2 , V_4 ) ;
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
F_70 ( & V_103 , V_110 | V_111 , V_102 , V_105 ,
V_80 . V_88 - V_104 ) ;
V_24 = F_71 ( V_30 , & V_103 , & V_80 . V_65 ) ;
if ( V_24 <= 0 )
break;
V_80 . V_93 += V_24 ;
V_80 . V_88 -= V_24 ;
* V_51 = V_80 . V_65 ;
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
F_30 ( V_102 ) ;
F_62 ( V_2 , & V_80 ) ;
F_67 ( V_2 ) ;
if ( V_80 . V_93 )
V_24 = V_80 . V_93 ;
return V_24 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_79 * V_80 )
{
int V_24 ;
void * V_112 ;
T_2 V_113 = V_80 -> V_65 ;
V_112 = F_73 ( V_4 -> V_5 ) ;
V_24 = F_74 ( V_80 -> V_81 . V_49 , V_112 + V_4 -> V_37 , V_80 -> V_39 , & V_113 ) ;
F_75 ( V_4 -> V_5 ) ;
return V_24 ;
}
static T_1 F_76 ( struct V_1 * V_2 ,
struct V_49 * V_30 , T_2 * V_51 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_65 ( V_2 , V_30 , V_51 , V_39 , V_10 , F_72 ) ;
if ( V_24 > 0 )
* V_51 += V_24 ;
return V_24 ;
}
T_1 F_77 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 )
{
return F_65 ( V_2 , V_30 , V_51 , V_39 , V_10 , F_53 ) ;
}
static long F_78 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_79)( struct V_1 * , struct V_49 * ,
T_2 * , T_3 , unsigned int );
if ( V_30 -> V_83 -> F_79 )
F_79 = V_30 -> V_83 -> F_79 ;
else
F_79 = F_76 ;
return F_79 ( V_2 , V_30 , V_51 , V_39 , V_10 ) ;
}
static long F_80 ( struct V_49 * V_50 , T_2 * V_51 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_81)( struct V_49 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_22 ( ! ( V_50 -> V_114 & V_115 ) ) )
return - V_116 ;
V_24 = F_82 ( V_57 , V_50 , V_51 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
if ( F_22 ( V_39 > V_117 ) )
V_39 = V_117 ;
if ( V_50 -> V_83 -> F_81 )
F_81 = V_50 -> V_83 -> F_81 ;
else
F_81 = F_46 ;
return F_81 ( V_50 , V_51 , V_2 , V_39 , V_10 ) ;
}
T_1 F_83 ( struct V_49 * V_50 , struct V_79 * V_80 ,
T_6 * V_92 )
{
struct V_1 * V_2 ;
long V_24 , V_118 ;
T_7 V_119 ;
T_3 V_39 ;
int V_44 , V_10 , V_82 ;
V_119 = F_84 ( V_50 ) -> V_119 ;
if ( F_22 ( ! F_85 ( V_119 ) && ! F_86 ( V_119 ) ) )
return - V_85 ;
V_2 = V_28 -> V_120 ;
if ( F_22 ( ! V_2 ) ) {
V_2 = F_87 () ;
if ( ! V_2 )
return - V_48 ;
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
T_2 V_65 = V_80 -> V_65 , V_122 = V_65 ;
V_24 = F_80 ( V_50 , & V_65 , V_2 , V_39 , V_10 ) ;
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
V_80 -> V_65 = V_122 ;
goto V_123;
}
V_118 += V_24 ;
V_39 -= V_24 ;
V_80 -> V_65 = V_65 ;
if ( V_24 < V_121 ) {
V_80 -> V_65 = V_122 + V_24 ;
goto V_123;
}
}
V_106:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_36 ( V_50 ) ;
return V_118 ;
V_123:
for ( V_44 = 0 ; V_44 < V_2 -> V_32 ; V_44 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_44 ;
if ( V_4 -> V_41 )
F_25 ( V_2 , V_4 ) ;
}
if ( ! V_118 )
V_118 = V_24 ;
goto V_106;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_49 * V_49 = V_80 -> V_81 . V_49 ;
return F_78 ( V_2 , V_49 , V_80 -> V_124 , V_80 -> V_88 ,
V_80 -> V_10 ) ;
}
long F_89 ( struct V_49 * V_50 , T_2 * V_51 , struct V_49 * V_30 ,
T_2 * V_124 , T_3 V_39 , unsigned int V_10 )
{
struct V_79 V_80 = {
. V_39 = V_39 ,
. V_88 = V_39 ,
. V_10 = V_10 ,
. V_65 = * V_51 ,
. V_81 . V_49 = V_30 ,
. V_124 = V_124 ,
} ;
long V_24 ;
if ( F_22 ( ! ( V_30 -> V_114 & V_125 ) ) )
return - V_116 ;
if ( F_22 ( V_30 -> V_126 & V_127 ) )
return - V_85 ;
V_24 = F_82 ( V_111 , V_30 , V_124 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
V_24 = F_83 ( V_50 , & V_80 , F_88 ) ;
if ( V_24 > 0 )
* V_51 = V_80 . V_65 ;
return V_24 ;
}
static int F_90 ( struct V_1 * V_2 , unsigned V_10 )
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
if ( F_59 ( V_28 ) )
return - V_96 ;
V_2 -> V_98 ++ ;
F_60 ( V_2 ) ;
V_2 -> V_98 -- ;
}
}
static long F_91 ( struct V_49 * V_50 , T_2 V_68 * V_128 ,
struct V_49 * V_30 , T_2 V_68 * V_129 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_130 ;
struct V_1 * V_131 ;
T_2 V_37 ;
long V_24 ;
V_130 = F_92 ( V_50 ) ;
V_131 = F_92 ( V_30 ) ;
if ( V_130 && V_131 ) {
if ( V_128 || V_129 )
return - V_132 ;
if ( ! ( V_50 -> V_114 & V_115 ) )
return - V_116 ;
if ( ! ( V_30 -> V_114 & V_125 ) )
return - V_116 ;
if ( V_130 == V_131 )
return - V_85 ;
return F_93 ( V_130 , V_131 , V_39 , V_10 ) ;
}
if ( V_130 ) {
if ( V_128 )
return - V_132 ;
if ( V_129 ) {
if ( ! ( V_30 -> V_114 & V_133 ) )
return - V_85 ;
if ( F_94 ( & V_37 , V_129 , sizeof( T_2 ) ) )
return - V_60 ;
} else {
V_37 = V_30 -> V_134 ;
}
if ( F_22 ( ! ( V_30 -> V_114 & V_125 ) ) )
return - V_116 ;
if ( F_22 ( V_30 -> V_126 & V_127 ) )
return - V_85 ;
V_24 = F_82 ( V_111 , V_30 , & V_37 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
F_95 ( V_30 ) ;
V_24 = F_78 ( V_130 , V_30 , & V_37 , V_39 , V_10 ) ;
F_96 ( V_30 ) ;
if ( ! V_129 )
V_30 -> V_134 = V_37 ;
else if ( F_97 ( V_129 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_60 ;
return V_24 ;
}
if ( V_131 ) {
if ( V_129 )
return - V_132 ;
if ( V_128 ) {
if ( ! ( V_50 -> V_114 & V_135 ) )
return - V_85 ;
if ( F_94 ( & V_37 , V_128 , sizeof( T_2 ) ) )
return - V_60 ;
} else {
V_37 = V_50 -> V_134 ;
}
F_66 ( V_131 ) ;
V_24 = F_90 ( V_131 , V_10 ) ;
if ( ! V_24 )
V_24 = F_80 ( V_50 , & V_37 , V_131 , V_39 , V_10 ) ;
F_67 ( V_131 ) ;
if ( V_24 > 0 )
F_16 ( V_131 ) ;
if ( ! V_128 )
V_50 -> V_134 = V_37 ;
else if ( F_97 ( V_128 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_60 ;
return V_24 ;
}
return - V_85 ;
}
static int F_98 ( struct V_52 * V_103 ,
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
while ( F_99 ( V_103 ) && ! V_138 ) {
struct V_5 * V_36 [ 16 ] ;
T_1 V_73 ;
T_3 V_139 ;
int V_105 ;
V_73 = F_100 ( V_103 , V_36 , ~ 0UL , 16 , & V_139 ) ;
if ( V_73 <= 0 ) {
V_24 = V_73 ;
break;
}
for ( V_105 = 0 ; V_73 ; V_105 ++ , V_139 = 0 ) {
int V_140 = F_50 ( int , V_73 , V_75 - V_139 ) ;
if ( ! V_138 ) {
V_4 . V_5 = V_36 [ V_105 ] ;
V_4 . V_37 = V_139 ;
V_4 . V_39 = V_140 ;
V_24 = F_24 ( V_2 , & V_4 ) ;
if ( F_22 ( V_24 < 0 ) ) {
V_138 = true ;
} else {
F_37 ( V_103 , V_24 ) ;
V_137 += V_24 ;
}
} else {
F_12 ( V_36 [ V_105 ] ) ;
}
V_73 -= V_140 ;
}
}
return V_137 ? V_137 : V_24 ;
}
static int F_101 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_79 * V_80 )
{
int V_105 = F_102 ( V_4 -> V_5 , V_4 -> V_37 , V_80 -> V_39 , V_80 -> V_81 . V_112 ) ;
return V_105 == V_80 -> V_39 ? V_105 : - V_60 ;
}
static long F_103 ( struct V_49 * V_49 , const struct V_67 V_68 * V_141 ,
unsigned long V_142 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_79 V_80 ;
long V_24 ;
struct V_67 V_143 [ V_144 ] ;
struct V_67 * V_145 = V_143 ;
struct V_52 V_146 ;
V_2 = F_92 ( V_49 ) ;
if ( ! V_2 )
return - V_116 ;
V_24 = F_104 ( V_57 , V_141 , V_142 ,
F_105 ( V_143 ) , & V_145 , & V_146 ) ;
if ( V_24 < 0 )
return V_24 ;
V_80 . V_88 = F_99 ( & V_146 ) ;
V_80 . V_39 = 0 ;
V_80 . V_10 = V_10 ;
V_80 . V_81 . V_112 = & V_146 ;
V_80 . V_65 = 0 ;
if ( V_80 . V_88 ) {
F_66 ( V_2 ) ;
V_24 = F_63 ( V_2 , & V_80 , F_101 ) ;
F_67 ( V_2 ) ;
}
F_30 ( V_145 ) ;
return V_24 ;
}
static long F_106 ( struct V_49 * V_49 , const struct V_67 V_68 * V_141 ,
unsigned long V_142 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_67 V_143 [ V_144 ] ;
struct V_67 * V_145 = V_143 ;
struct V_52 V_103 ;
long V_24 ;
unsigned V_147 = 0 ;
if ( V_10 & V_148 )
V_147 = V_15 ;
V_2 = F_92 ( V_49 ) ;
if ( ! V_2 )
return - V_116 ;
V_24 = F_104 ( V_111 , V_141 , V_142 ,
F_105 ( V_143 ) , & V_145 , & V_103 ) ;
if ( V_24 < 0 )
return V_24 ;
F_66 ( V_2 ) ;
V_24 = F_90 ( V_2 , V_10 ) ;
if ( ! V_24 )
V_24 = F_98 ( & V_103 , V_2 , V_147 ) ;
F_67 ( V_2 ) ;
if ( V_24 > 0 )
F_16 ( V_2 ) ;
F_30 ( V_145 ) ;
return V_24 ;
}
static int F_107 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 )
return 0 ;
V_24 = 0 ;
F_66 ( V_2 ) ;
while ( ! V_2 -> V_31 ) {
if ( F_59 ( V_28 ) ) {
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
F_60 ( V_2 ) ;
}
F_67 ( V_2 ) ;
return V_24 ;
}
static int F_108 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 < V_2 -> V_32 )
return 0 ;
V_24 = 0 ;
F_66 ( V_2 ) ;
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
if ( F_59 ( V_28 ) ) {
V_24 = - V_96 ;
break;
}
V_2 -> V_98 ++ ;
F_60 ( V_2 ) ;
V_2 -> V_98 -- ;
}
F_67 ( V_2 ) ;
return V_24 ;
}
static int F_93 ( struct V_1 * V_130 ,
struct V_1 * V_131 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_149 , * V_150 ;
int V_24 = 0 , V_151 ;
bool V_152 = false ;
V_153:
V_24 = F_107 ( V_130 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_108 ( V_131 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_109 ( V_130 , V_131 ) ;
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
F_67 ( V_130 ) ;
F_67 ( V_131 ) ;
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
F_110 ( V_130 , V_149 ) ;
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
F_67 ( V_130 ) ;
F_67 ( V_131 ) ;
if ( V_24 > 0 )
F_16 ( V_131 ) ;
if ( V_152 )
F_55 ( V_130 ) ;
return V_24 ;
}
static int F_111 ( struct V_1 * V_130 ,
struct V_1 * V_131 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_149 , * V_150 ;
int V_24 = 0 , V_44 = 0 , V_151 ;
F_109 ( V_130 , V_131 ) ;
do {
if ( ! V_131 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( V_44 >= V_130 -> V_31 || V_131 -> V_31 >= V_131 -> V_32 )
break;
V_149 = V_130 -> V_35 + ( ( V_130 -> V_34 + V_44 ) & ( V_130 -> V_32 - 1 ) ) ;
V_151 = ( V_131 -> V_34 + V_131 -> V_31 ) & ( V_131 -> V_32 - 1 ) ;
F_110 ( V_130 , V_149 ) ;
V_150 = V_131 -> V_35 + V_151 ;
* V_150 = * V_149 ;
V_150 -> V_10 &= ~ V_15 ;
if ( V_150 -> V_39 > V_39 )
V_150 -> V_39 = V_39 ;
V_131 -> V_31 ++ ;
V_24 += V_150 -> V_39 ;
V_39 -= V_150 -> V_39 ;
V_44 ++ ;
} while ( V_39 );
if ( ! V_24 && V_130 -> V_98 && ( V_10 & V_99 ) )
V_24 = - V_42 ;
F_67 ( V_130 ) ;
F_67 ( V_131 ) ;
if ( V_24 > 0 )
F_16 ( V_131 ) ;
return V_24 ;
}
static long F_112 ( struct V_49 * V_50 , struct V_49 * V_30 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_130 = F_92 ( V_50 ) ;
struct V_1 * V_131 = F_92 ( V_30 ) ;
int V_24 = - V_85 ;
if ( V_130 && V_131 && V_130 != V_131 ) {
V_24 = F_107 ( V_130 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_108 ( V_131 , V_10 ) ;
if ( ! V_24 )
V_24 = F_111 ( V_130 , V_131 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
