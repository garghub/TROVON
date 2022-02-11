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
V_24 = V_50 -> V_59 -> V_60 ( & V_54 , & V_53 ) ;
if ( V_24 > 0 ) {
* V_51 = V_54 . V_58 ;
F_35 ( V_50 ) ;
} else if ( V_24 < 0 ) {
V_53 . V_55 = V_55 ;
V_53 . V_61 = 0 ;
F_36 ( & V_53 , 0 ) ;
if ( V_24 == - V_62 )
V_24 = - V_42 ;
}
return V_24 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 1 ;
}
static T_1 F_38 ( struct V_49 * V_49 , const struct V_63 * V_64 ,
unsigned long V_65 , T_2 V_37 )
{
T_4 V_66 ;
T_2 V_67 = V_37 ;
T_1 V_68 ;
V_66 = F_39 () ;
F_40 ( F_41 () ) ;
V_68 = F_42 ( V_49 , ( const struct V_69 V_70 * ) V_64 , V_65 , & V_67 , 0 ) ;
F_40 ( V_66 ) ;
return V_68 ;
}
T_1 F_43 ( struct V_49 * V_49 , const char * V_4 , T_3 V_71 ,
T_2 V_67 )
{
T_4 V_66 ;
T_1 V_68 ;
V_66 = F_39 () ;
F_40 ( F_41 () ) ;
V_68 = F_44 ( V_49 , ( V_72 const char V_70 * ) V_4 , V_71 , & V_67 ) ;
F_40 ( V_66 ) ;
return V_68 ;
}
static T_1 F_45 ( struct V_49 * V_50 , T_2 * V_51 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_63 * V_64 , V_73 [ V_46 ] ;
struct V_52 V_53 ;
struct V_5 * * V_36 ;
unsigned int V_23 ;
T_3 V_37 , V_74 , V_75 = 0 ;
T_1 V_68 ;
int V_44 ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return - V_42 ;
V_37 = * V_51 & ~ V_76 ;
F_33 ( & V_53 , V_56 | V_57 , V_2 , V_39 + V_37 ) ;
V_68 = F_46 ( & V_53 , & V_36 , V_39 + V_37 , & V_74 ) ;
if ( V_68 <= 0 )
return - V_48 ;
F_47 ( V_74 ) ;
V_23 = F_48 ( V_68 , V_77 ) ;
V_64 = V_73 ;
if ( V_23 > V_46 ) {
V_64 = F_29 ( V_23 * sizeof( struct V_63 ) , V_8 ) ;
if ( F_22 ( ! V_64 ) ) {
V_68 = - V_48 ;
goto V_30;
}
}
V_2 -> V_35 [ V_53 . V_55 ] . V_37 = V_37 ;
V_2 -> V_35 [ V_53 . V_55 ] . V_39 -= V_37 ;
for ( V_44 = 0 ; V_44 < V_23 ; V_44 ++ ) {
T_3 V_78 = F_49 ( T_3 , V_39 , V_77 - V_37 ) ;
V_64 [ V_44 ] . V_79 = F_50 ( V_36 [ V_44 ] ) + V_37 ;
V_64 [ V_44 ] . V_80 = V_78 ;
V_39 -= V_78 ;
V_37 = 0 ;
}
V_68 = F_38 ( V_50 , V_64 , V_23 , * V_51 ) ;
if ( V_68 > 0 ) {
V_75 = V_68 ;
* V_51 += V_68 ;
}
if ( V_64 != V_73 )
F_30 ( V_64 ) ;
V_30:
for ( V_44 = 0 ; V_44 < V_23 ; V_44 ++ )
F_12 ( V_36 [ V_44 ] ) ;
F_51 ( V_36 ) ;
F_36 ( & V_53 , V_75 ) ;
return V_68 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_81 * V_82 )
{
struct V_49 * V_49 = V_82 -> V_83 . V_49 ;
T_2 V_67 = V_82 -> V_67 ;
int V_84 ;
if ( ! F_53 ( V_49 -> V_59 -> V_85 ) )
return - V_86 ;
V_84 = ( V_82 -> V_10 & V_87 ) ? V_88 : 0 ;
if ( V_82 -> V_39 < V_82 -> V_89 && V_2 -> V_31 > 1 )
V_84 |= V_90 ;
return V_49 -> V_59 -> V_85 ( V_49 , V_4 -> V_5 , V_4 -> V_37 ,
V_82 -> V_39 , & V_67 , V_84 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_91 , V_18 , V_92 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_81 * V_82 ,
T_5 * V_93 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
V_82 -> V_39 = V_4 -> V_39 ;
if ( V_82 -> V_39 > V_82 -> V_89 )
V_82 -> V_39 = V_82 -> V_89 ;
V_24 = F_56 ( V_2 , V_4 ) ;
if ( F_22 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_93 ( V_2 , V_4 , V_82 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_82 -> V_94 += V_24 ;
V_82 -> V_39 -= V_24 ;
V_82 -> V_67 += V_24 ;
V_82 -> V_89 -= V_24 ;
if ( ! V_4 -> V_39 ) {
F_25 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_95 )
V_82 -> V_96 = true ;
}
if ( ! V_82 -> V_89 )
return 0 ;
}
return 1 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
if ( F_58 ( V_28 ) )
return - V_97 ;
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_98 )
return 0 ;
if ( ! V_2 -> V_99 && V_82 -> V_94 )
return 0 ;
if ( V_82 -> V_10 & V_100 )
return - V_42 ;
if ( F_58 ( V_28 ) )
return - V_97 ;
if ( V_82 -> V_96 ) {
F_54 ( V_2 ) ;
V_82 -> V_96 = false ;
}
F_59 ( V_2 ) ;
}
return 1 ;
}
static void F_60 ( struct V_81 * V_82 )
{
V_82 -> V_94 = 0 ;
V_82 -> V_96 = false ;
}
static void F_61 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
if ( V_82 -> V_96 )
F_54 ( V_2 ) ;
}
T_1 F_62 ( struct V_1 * V_2 , struct V_81 * V_82 ,
T_5 * V_93 )
{
int V_24 ;
F_60 ( V_82 ) ;
do {
F_63 () ;
V_24 = F_57 ( V_2 , V_82 ) ;
if ( V_24 > 0 )
V_24 = F_55 ( V_2 , V_82 , V_93 ) ;
} while ( V_24 > 0 );
F_61 ( V_2 , V_82 ) ;
return V_82 -> V_94 ? V_82 -> V_94 : V_24 ;
}
T_1 F_64 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 ,
T_5 * V_93 )
{
T_1 V_24 ;
struct V_81 V_82 = {
. V_89 = V_39 ,
. V_10 = V_10 ,
. V_67 = * V_51 ,
. V_83 . V_49 = V_30 ,
} ;
F_65 ( V_2 ) ;
V_24 = F_62 ( V_2 , & V_82 , V_93 ) ;
F_66 ( V_2 ) ;
return V_24 ;
}
T_1
F_67 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 )
{
struct V_81 V_82 = {
. V_89 = V_39 ,
. V_10 = V_10 ,
. V_67 = * V_51 ,
. V_83 . V_49 = V_30 ,
} ;
int V_101 = V_2 -> V_32 ;
struct V_102 * V_103 = F_68 ( V_101 , sizeof( struct V_102 ) ,
V_8 ) ;
T_1 V_24 ;
if ( F_22 ( ! V_103 ) )
return - V_48 ;
F_65 ( V_2 ) ;
F_60 ( & V_82 ) ;
while ( V_82 . V_89 ) {
struct V_52 V_104 ;
T_3 V_105 ;
int V_106 , V_55 ;
V_24 = F_57 ( V_2 , & V_82 ) ;
if ( V_24 <= 0 )
break;
if ( F_22 ( V_101 < V_2 -> V_32 ) ) {
F_30 ( V_103 ) ;
V_101 = V_2 -> V_32 ;
V_103 = F_68 ( V_101 , sizeof( struct V_102 ) ,
V_8 ) ;
if ( ! V_103 ) {
V_24 = - V_48 ;
break;
}
}
V_105 = V_82 . V_89 ;
for ( V_106 = 0 , V_55 = V_2 -> V_34 ; V_105 && V_106 < V_2 -> V_31 ; V_106 ++ , V_55 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_55 ;
T_3 V_78 = V_4 -> V_39 ;
if ( V_78 > V_105 )
V_78 = V_105 ;
if ( V_55 == V_2 -> V_32 - 1 )
V_55 = - 1 ;
V_24 = F_56 ( V_2 , V_4 ) ;
if ( F_22 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
goto V_107;
}
V_103 [ V_106 ] . V_108 = V_4 -> V_5 ;
V_103 [ V_106 ] . V_109 = V_78 ;
V_103 [ V_106 ] . V_110 = V_4 -> V_37 ;
V_105 -= V_78 ;
}
F_69 ( & V_104 , V_111 | V_112 , V_103 , V_106 ,
V_82 . V_89 - V_105 ) ;
V_24 = F_70 ( V_30 , & V_104 , & V_82 . V_67 ) ;
if ( V_24 <= 0 )
break;
V_82 . V_94 += V_24 ;
V_82 . V_89 -= V_24 ;
* V_51 = V_82 . V_67 ;
while ( V_24 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
if ( V_24 >= V_4 -> V_39 ) {
V_24 -= V_4 -> V_39 ;
V_4 -> V_39 = 0 ;
F_25 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_95 )
V_82 . V_96 = true ;
} else {
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_24 = 0 ;
}
}
}
V_107:
F_30 ( V_103 ) ;
F_61 ( V_2 , & V_82 ) ;
F_66 ( V_2 ) ;
if ( V_82 . V_94 )
V_24 = V_82 . V_94 ;
return V_24 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_81 * V_82 )
{
int V_24 ;
void * V_113 ;
T_2 V_114 = V_82 -> V_67 ;
V_113 = F_72 ( V_4 -> V_5 ) ;
V_24 = F_73 ( V_82 -> V_83 . V_49 , V_113 + V_4 -> V_37 , V_82 -> V_39 , & V_114 ) ;
F_74 ( V_4 -> V_5 ) ;
return V_24 ;
}
static T_1 F_75 ( struct V_1 * V_2 ,
struct V_49 * V_30 , T_2 * V_51 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_64 ( V_2 , V_30 , V_51 , V_39 , V_10 , F_71 ) ;
if ( V_24 > 0 )
* V_51 += V_24 ;
return V_24 ;
}
T_1 F_76 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 )
{
return F_64 ( V_2 , V_30 , V_51 , V_39 , V_10 , F_52 ) ;
}
static long F_77 ( struct V_1 * V_2 , struct V_49 * V_30 ,
T_2 * V_51 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_78)( struct V_1 * , struct V_49 * ,
T_2 * , T_3 , unsigned int );
if ( V_30 -> V_59 -> F_78 )
F_78 = V_30 -> V_59 -> F_78 ;
else
F_78 = F_75 ;
return F_78 ( V_2 , V_30 , V_51 , V_39 , V_10 ) ;
}
static long F_79 ( struct V_49 * V_50 , T_2 * V_51 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_80)( struct V_49 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_22 ( ! ( V_50 -> V_115 & V_116 ) ) )
return - V_117 ;
V_24 = F_81 ( V_57 , V_50 , V_51 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
if ( F_22 ( V_39 > V_118 ) )
V_39 = V_118 ;
if ( V_50 -> V_59 -> F_80 )
F_80 = V_50 -> V_59 -> F_80 ;
else
F_80 = F_45 ;
return F_80 ( V_50 , V_51 , V_2 , V_39 , V_10 ) ;
}
T_1 F_82 ( struct V_49 * V_50 , struct V_81 * V_82 ,
T_6 * V_93 )
{
struct V_1 * V_2 ;
long V_24 , V_119 ;
T_7 V_120 ;
T_3 V_39 ;
int V_44 , V_10 , V_84 ;
V_120 = F_83 ( V_50 ) -> V_120 ;
if ( F_22 ( ! F_84 ( V_120 ) && ! F_85 ( V_120 ) ) )
return - V_86 ;
V_2 = V_28 -> V_121 ;
if ( F_22 ( ! V_2 ) ) {
V_2 = F_86 () ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_26 = 1 ;
V_28 -> V_121 = V_2 ;
}
V_24 = 0 ;
V_119 = 0 ;
V_39 = V_82 -> V_89 ;
V_10 = V_82 -> V_10 ;
V_82 -> V_10 &= ~ V_100 ;
V_84 = V_82 -> V_10 & V_87 ;
while ( V_39 ) {
T_3 V_122 ;
T_2 V_67 = V_82 -> V_67 , V_123 = V_67 ;
V_24 = F_79 ( V_50 , & V_67 , V_2 , V_39 , V_10 ) ;
if ( F_22 ( V_24 <= 0 ) )
goto V_124;
V_122 = V_24 ;
V_82 -> V_89 = V_122 ;
if ( V_122 < V_39 )
V_82 -> V_10 |= V_87 ;
else if ( ! V_84 )
V_82 -> V_10 &= ~ V_87 ;
V_24 = V_93 ( V_2 , V_82 ) ;
if ( F_22 ( V_24 <= 0 ) ) {
V_82 -> V_67 = V_123 ;
goto V_124;
}
V_119 += V_24 ;
V_39 -= V_24 ;
V_82 -> V_67 = V_67 ;
if ( V_24 < V_122 ) {
V_82 -> V_67 = V_123 + V_24 ;
goto V_124;
}
}
V_107:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_35 ( V_50 ) ;
return V_119 ;
V_124:
for ( V_44 = 0 ; V_44 < V_2 -> V_32 ; V_44 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_44 ;
if ( V_4 -> V_41 )
F_25 ( V_2 , V_4 ) ;
}
if ( ! V_119 )
V_119 = V_24 ;
goto V_107;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
struct V_49 * V_49 = V_82 -> V_83 . V_49 ;
return F_77 ( V_2 , V_49 , V_82 -> V_125 , V_82 -> V_89 ,
V_82 -> V_10 ) ;
}
long F_88 ( struct V_49 * V_50 , T_2 * V_51 , struct V_49 * V_30 ,
T_2 * V_125 , T_3 V_39 , unsigned int V_10 )
{
struct V_81 V_82 = {
. V_39 = V_39 ,
. V_89 = V_39 ,
. V_10 = V_10 ,
. V_67 = * V_51 ,
. V_83 . V_49 = V_30 ,
. V_125 = V_125 ,
} ;
long V_24 ;
if ( F_22 ( ! ( V_30 -> V_115 & V_126 ) ) )
return - V_117 ;
if ( F_22 ( V_30 -> V_127 & V_128 ) )
return - V_86 ;
V_24 = F_81 ( V_112 , V_30 , V_125 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
V_24 = F_82 ( V_50 , & V_82 , F_87 ) ;
if ( V_24 > 0 )
* V_51 = V_82 . V_67 ;
return V_24 ;
}
static int F_89 ( struct V_1 * V_2 , unsigned V_10 )
{
for (; ; ) {
if ( F_22 ( ! V_2 -> V_26 ) ) {
F_23 ( V_27 , V_28 , 0 ) ;
return - V_29 ;
}
if ( V_2 -> V_31 != V_2 -> V_32 )
return 0 ;
if ( V_10 & V_100 )
return - V_42 ;
if ( F_58 ( V_28 ) )
return - V_97 ;
V_2 -> V_99 ++ ;
F_59 ( V_2 ) ;
V_2 -> V_99 -- ;
}
}
static long F_90 ( struct V_49 * V_50 , T_2 V_70 * V_129 ,
struct V_49 * V_30 , T_2 V_70 * V_130 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_131 ;
struct V_1 * V_132 ;
T_2 V_37 ;
long V_24 ;
V_131 = F_91 ( V_50 ) ;
V_132 = F_91 ( V_30 ) ;
if ( V_131 && V_132 ) {
if ( V_129 || V_130 )
return - V_133 ;
if ( ! ( V_50 -> V_115 & V_116 ) )
return - V_117 ;
if ( ! ( V_30 -> V_115 & V_126 ) )
return - V_117 ;
if ( V_131 == V_132 )
return - V_86 ;
return F_92 ( V_131 , V_132 , V_39 , V_10 ) ;
}
if ( V_131 ) {
if ( V_129 )
return - V_133 ;
if ( V_130 ) {
if ( ! ( V_30 -> V_115 & V_134 ) )
return - V_86 ;
if ( F_93 ( & V_37 , V_130 , sizeof( T_2 ) ) )
return - V_62 ;
} else {
V_37 = V_30 -> V_135 ;
}
if ( F_22 ( ! ( V_30 -> V_115 & V_126 ) ) )
return - V_117 ;
if ( F_22 ( V_30 -> V_127 & V_128 ) )
return - V_86 ;
V_24 = F_81 ( V_112 , V_30 , & V_37 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
F_94 ( V_30 ) ;
V_24 = F_77 ( V_131 , V_30 , & V_37 , V_39 , V_10 ) ;
F_95 ( V_30 ) ;
if ( ! V_130 )
V_30 -> V_135 = V_37 ;
else if ( F_96 ( V_130 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_62 ;
return V_24 ;
}
if ( V_132 ) {
if ( V_130 )
return - V_133 ;
if ( V_129 ) {
if ( ! ( V_50 -> V_115 & V_136 ) )
return - V_86 ;
if ( F_93 ( & V_37 , V_129 , sizeof( T_2 ) ) )
return - V_62 ;
} else {
V_37 = V_50 -> V_135 ;
}
F_65 ( V_132 ) ;
V_24 = F_89 ( V_132 , V_10 ) ;
if ( ! V_24 )
V_24 = F_79 ( V_50 , & V_37 , V_132 , V_39 , V_10 ) ;
F_66 ( V_132 ) ;
if ( V_24 > 0 )
F_16 ( V_132 ) ;
if ( ! V_129 )
V_50 -> V_135 = V_37 ;
else if ( F_96 ( V_129 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_62 ;
return V_24 ;
}
return - V_86 ;
}
static int F_97 ( struct V_52 * V_104 ,
struct V_1 * V_2 ,
unsigned V_10 )
{
struct V_3 V_4 = {
. V_41 = & V_137 ,
. V_10 = V_10
} ;
T_3 V_138 = 0 ;
int V_24 = 0 ;
bool V_139 = false ;
while ( F_98 ( V_104 ) && ! V_139 ) {
struct V_5 * V_36 [ 16 ] ;
T_1 V_75 ;
T_3 V_140 ;
int V_106 ;
V_75 = F_99 ( V_104 , V_36 , ~ 0UL , 16 , & V_140 ) ;
if ( V_75 <= 0 ) {
V_24 = V_75 ;
break;
}
for ( V_106 = 0 ; V_75 ; V_106 ++ , V_140 = 0 ) {
int V_141 = F_49 ( int , V_75 , V_77 - V_140 ) ;
if ( ! V_139 ) {
V_4 . V_5 = V_36 [ V_106 ] ;
V_4 . V_37 = V_140 ;
V_4 . V_39 = V_141 ;
V_24 = F_24 ( V_2 , & V_4 ) ;
if ( F_22 ( V_24 < 0 ) ) {
V_139 = true ;
} else {
F_36 ( V_104 , V_24 ) ;
V_138 += V_24 ;
}
} else {
F_12 ( V_36 [ V_106 ] ) ;
}
V_75 -= V_141 ;
}
}
return V_138 ? V_138 : V_24 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_81 * V_82 )
{
int V_106 = F_101 ( V_4 -> V_5 , V_4 -> V_37 , V_82 -> V_39 , V_82 -> V_83 . V_113 ) ;
return V_106 == V_82 -> V_39 ? V_106 : - V_62 ;
}
static long F_102 ( struct V_49 * V_49 , const struct V_69 V_70 * V_142 ,
unsigned long V_143 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_81 V_82 ;
long V_24 ;
struct V_69 V_144 [ V_145 ] ;
struct V_69 * V_146 = V_144 ;
struct V_52 V_147 ;
V_2 = F_91 ( V_49 ) ;
if ( ! V_2 )
return - V_117 ;
V_24 = F_103 ( V_57 , V_142 , V_143 ,
F_104 ( V_144 ) , & V_146 , & V_147 ) ;
if ( V_24 < 0 )
return V_24 ;
V_82 . V_89 = F_98 ( & V_147 ) ;
V_82 . V_39 = 0 ;
V_82 . V_10 = V_10 ;
V_82 . V_83 . V_113 = & V_147 ;
V_82 . V_67 = 0 ;
if ( V_82 . V_89 ) {
F_65 ( V_2 ) ;
V_24 = F_62 ( V_2 , & V_82 , F_100 ) ;
F_66 ( V_2 ) ;
}
F_30 ( V_146 ) ;
return V_24 ;
}
static long F_105 ( struct V_49 * V_49 , const struct V_69 V_70 * V_142 ,
unsigned long V_143 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_69 V_144 [ V_145 ] ;
struct V_69 * V_146 = V_144 ;
struct V_52 V_104 ;
long V_24 ;
unsigned V_148 = 0 ;
if ( V_10 & V_149 )
V_148 = V_15 ;
V_2 = F_91 ( V_49 ) ;
if ( ! V_2 )
return - V_117 ;
V_24 = F_103 ( V_112 , V_142 , V_143 ,
F_104 ( V_144 ) , & V_146 , & V_104 ) ;
if ( V_24 < 0 )
return V_24 ;
F_65 ( V_2 ) ;
V_24 = F_89 ( V_2 , V_10 ) ;
if ( ! V_24 )
V_24 = F_97 ( & V_104 , V_2 , V_148 ) ;
F_66 ( V_2 ) ;
if ( V_24 > 0 )
F_16 ( V_2 ) ;
F_30 ( V_146 ) ;
return V_24 ;
}
static int F_106 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 )
return 0 ;
V_24 = 0 ;
F_65 ( V_2 ) ;
while ( ! V_2 -> V_31 ) {
if ( F_58 ( V_28 ) ) {
V_24 = - V_97 ;
break;
}
if ( ! V_2 -> V_98 )
break;
if ( ! V_2 -> V_99 ) {
if ( V_10 & V_100 ) {
V_24 = - V_42 ;
break;
}
}
F_59 ( V_2 ) ;
}
F_66 ( V_2 ) ;
return V_24 ;
}
static int F_107 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 < V_2 -> V_32 )
return 0 ;
V_24 = 0 ;
F_65 ( V_2 ) ;
while ( V_2 -> V_31 >= V_2 -> V_32 ) {
if ( ! V_2 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
V_24 = - V_29 ;
break;
}
if ( V_10 & V_100 ) {
V_24 = - V_42 ;
break;
}
if ( F_58 ( V_28 ) ) {
V_24 = - V_97 ;
break;
}
V_2 -> V_99 ++ ;
F_59 ( V_2 ) ;
V_2 -> V_99 -- ;
}
F_66 ( V_2 ) ;
return V_24 ;
}
static int F_92 ( struct V_1 * V_131 ,
struct V_1 * V_132 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_150 , * V_151 ;
int V_24 = 0 , V_152 ;
bool V_153 = false ;
V_154:
V_24 = F_106 ( V_131 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_107 ( V_132 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_108 ( V_131 , V_132 ) ;
do {
if ( ! V_132 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( ! V_131 -> V_31 && ! V_131 -> V_98 )
break;
if ( ! V_131 -> V_31 || V_132 -> V_31 >= V_132 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_100 ) {
V_24 = - V_42 ;
break;
}
F_66 ( V_131 ) ;
F_66 ( V_132 ) ;
goto V_154;
}
V_150 = V_131 -> V_35 + V_131 -> V_34 ;
V_152 = ( V_132 -> V_34 + V_132 -> V_31 ) & ( V_132 -> V_32 - 1 ) ;
V_151 = V_132 -> V_35 + V_152 ;
if ( V_39 >= V_150 -> V_39 ) {
* V_151 = * V_150 ;
V_150 -> V_41 = NULL ;
V_132 -> V_31 ++ ;
V_131 -> V_34 = ( V_131 -> V_34 + 1 ) & ( V_131 -> V_32 - 1 ) ;
V_131 -> V_31 -- ;
V_153 = true ;
} else {
F_109 ( V_131 , V_150 ) ;
* V_151 = * V_150 ;
V_151 -> V_10 &= ~ V_15 ;
V_151 -> V_39 = V_39 ;
V_132 -> V_31 ++ ;
V_150 -> V_37 += V_151 -> V_39 ;
V_150 -> V_39 -= V_151 -> V_39 ;
}
V_24 += V_151 -> V_39 ;
V_39 -= V_151 -> V_39 ;
} while ( V_39 );
F_66 ( V_131 ) ;
F_66 ( V_132 ) ;
if ( V_24 > 0 )
F_16 ( V_132 ) ;
if ( V_153 )
F_54 ( V_131 ) ;
return V_24 ;
}
static int F_110 ( struct V_1 * V_131 ,
struct V_1 * V_132 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_150 , * V_151 ;
int V_24 = 0 , V_44 = 0 , V_152 ;
F_108 ( V_131 , V_132 ) ;
do {
if ( ! V_132 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( V_44 >= V_131 -> V_31 || V_132 -> V_31 >= V_132 -> V_32 )
break;
V_150 = V_131 -> V_35 + ( ( V_131 -> V_34 + V_44 ) & ( V_131 -> V_32 - 1 ) ) ;
V_152 = ( V_132 -> V_34 + V_132 -> V_31 ) & ( V_132 -> V_32 - 1 ) ;
F_109 ( V_131 , V_150 ) ;
V_151 = V_132 -> V_35 + V_152 ;
* V_151 = * V_150 ;
V_151 -> V_10 &= ~ V_15 ;
if ( V_151 -> V_39 > V_39 )
V_151 -> V_39 = V_39 ;
V_132 -> V_31 ++ ;
V_24 += V_151 -> V_39 ;
V_39 -= V_151 -> V_39 ;
V_44 ++ ;
} while ( V_39 );
if ( ! V_24 && V_131 -> V_99 && ( V_10 & V_100 ) )
V_24 = - V_42 ;
F_66 ( V_131 ) ;
F_66 ( V_132 ) ;
if ( V_24 > 0 )
F_16 ( V_132 ) ;
return V_24 ;
}
static long F_111 ( struct V_49 * V_50 , struct V_49 * V_30 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_131 = F_91 ( V_50 ) ;
struct V_1 * V_132 = F_91 ( V_30 ) ;
int V_24 = - V_86 ;
if ( V_131 && V_132 && V_131 != V_132 ) {
V_24 = F_106 ( V_131 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_107 ( V_132 , V_10 ) ;
if ( ! V_24 )
V_24 = F_110 ( V_131 , V_132 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
