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
static T_1 F_43 ( struct V_48 * V_49 , T_2 * V_50 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_60 * V_61 , V_68 [ V_45 ] ;
struct V_51 V_52 ;
struct V_5 * * V_36 ;
unsigned int V_23 ;
T_3 V_37 , V_69 , V_70 = 0 ;
T_1 V_65 ;
int V_71 ;
if ( V_2 -> V_31 == V_2 -> V_32 )
return - V_42 ;
V_37 = * V_50 & ~ V_72 ;
F_32 ( & V_52 , V_55 | V_56 , V_2 , V_39 + V_37 ) ;
V_65 = F_44 ( & V_52 , & V_36 , V_39 + V_37 , & V_69 ) ;
if ( V_65 <= 0 )
return - V_47 ;
V_23 = F_45 ( V_65 + V_69 , V_73 ) ;
V_61 = V_68 ;
if ( V_23 > V_45 ) {
V_61 = F_28 ( V_23 * sizeof( struct V_60 ) , V_8 ) ;
if ( F_22 ( ! V_61 ) ) {
V_65 = - V_47 ;
goto V_30;
}
}
V_2 -> V_35 [ V_52 . V_54 ] . V_37 = V_37 ;
V_2 -> V_35 [ V_52 . V_54 ] . V_39 -= V_37 ;
for ( V_71 = 0 ; V_71 < V_23 ; V_71 ++ ) {
T_3 V_74 = F_46 ( T_3 , V_39 , V_73 - V_37 ) ;
V_61 [ V_71 ] . V_75 = F_47 ( V_36 [ V_71 ] ) + V_37 ;
V_61 [ V_71 ] . V_76 = V_74 ;
V_39 -= V_74 ;
V_37 = 0 ;
}
V_65 = F_38 ( V_49 , V_61 , V_23 , * V_50 ) ;
if ( V_65 > 0 ) {
V_70 = V_65 ;
* V_50 += V_65 ;
}
if ( V_61 != V_68 )
F_29 ( V_61 ) ;
V_30:
for ( V_71 = 0 ; V_71 < V_23 ; V_71 ++ )
F_12 ( V_36 [ V_71 ] ) ;
F_48 ( V_36 ) ;
F_36 ( & V_52 , V_70 ) ;
return V_65 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_77 * V_78 )
{
struct V_48 * V_48 = V_78 -> V_79 . V_48 ;
T_2 V_64 = V_78 -> V_64 ;
int V_80 ;
if ( ! F_50 ( V_48 -> V_81 -> V_82 ) )
return - V_83 ;
V_80 = ( V_78 -> V_10 & V_84 ) ? V_85 : 0 ;
if ( V_78 -> V_39 < V_78 -> V_86 && V_2 -> V_31 > 1 )
V_80 |= V_87 ;
return V_48 -> V_81 -> V_82 ( V_48 , V_4 -> V_5 , V_4 -> V_37 ,
V_78 -> V_39 , & V_64 , V_80 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_17 () ;
if ( F_18 ( & V_2 -> V_16 ) )
F_19 ( & V_2 -> V_16 ) ;
F_20 ( & V_2 -> V_88 , V_18 , V_89 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_77 * V_78 ,
T_5 * V_90 )
{
int V_24 ;
while ( V_2 -> V_31 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
V_78 -> V_39 = V_4 -> V_39 ;
if ( V_78 -> V_39 > V_78 -> V_86 )
V_78 -> V_39 = V_78 -> V_86 ;
V_24 = F_53 ( V_2 , V_4 ) ;
if ( F_22 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
return V_24 ;
}
V_24 = V_90 ( V_2 , V_4 , V_78 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_78 -> V_91 += V_24 ;
V_78 -> V_39 -= V_24 ;
V_78 -> V_64 += V_24 ;
V_78 -> V_86 -= V_24 ;
if ( ! V_4 -> V_39 ) {
F_25 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_92 )
V_78 -> V_93 = true ;
}
if ( ! V_78 -> V_86 )
return 0 ;
}
return 1 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
if ( F_55 ( V_28 ) )
return - V_94 ;
while ( ! V_2 -> V_31 ) {
if ( ! V_2 -> V_95 )
return 0 ;
if ( ! V_2 -> V_96 && V_78 -> V_91 )
return 0 ;
if ( V_78 -> V_10 & V_97 )
return - V_42 ;
if ( F_55 ( V_28 ) )
return - V_94 ;
if ( V_78 -> V_93 ) {
F_51 ( V_2 ) ;
V_78 -> V_93 = false ;
}
F_56 ( V_2 ) ;
}
return 1 ;
}
static void F_57 ( struct V_77 * V_78 )
{
V_78 -> V_91 = 0 ;
V_78 -> V_93 = false ;
}
static void F_58 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
if ( V_78 -> V_93 )
F_51 ( V_2 ) ;
}
T_1 F_59 ( struct V_1 * V_2 , struct V_77 * V_78 ,
T_5 * V_90 )
{
int V_24 ;
F_57 ( V_78 ) ;
do {
F_60 () ;
V_24 = F_54 ( V_2 , V_78 ) ;
if ( V_24 > 0 )
V_24 = F_52 ( V_2 , V_78 , V_90 ) ;
} while ( V_24 > 0 );
F_58 ( V_2 , V_78 ) ;
return V_78 -> V_91 ? V_78 -> V_91 : V_24 ;
}
T_1 F_61 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 ,
T_5 * V_90 )
{
T_1 V_24 ;
struct V_77 V_78 = {
. V_86 = V_39 ,
. V_10 = V_10 ,
. V_64 = * V_50 ,
. V_79 . V_48 = V_30 ,
} ;
F_62 ( V_2 ) ;
V_24 = F_59 ( V_2 , & V_78 , V_90 ) ;
F_63 ( V_2 ) ;
return V_24 ;
}
T_1
F_64 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 )
{
struct V_77 V_78 = {
. V_86 = V_39 ,
. V_10 = V_10 ,
. V_64 = * V_50 ,
. V_79 . V_48 = V_30 ,
} ;
int V_98 = V_2 -> V_32 ;
struct V_99 * V_100 = F_65 ( V_98 , sizeof( struct V_99 ) ,
V_8 ) ;
T_1 V_24 ;
if ( F_22 ( ! V_100 ) )
return - V_47 ;
F_62 ( V_2 ) ;
F_57 ( & V_78 ) ;
while ( V_78 . V_86 ) {
struct V_51 V_101 ;
T_3 V_102 ;
int V_103 , V_54 ;
V_24 = F_54 ( V_2 , & V_78 ) ;
if ( V_24 <= 0 )
break;
if ( F_22 ( V_98 < V_2 -> V_32 ) ) {
F_29 ( V_100 ) ;
V_98 = V_2 -> V_32 ;
V_100 = F_65 ( V_98 , sizeof( struct V_99 ) ,
V_8 ) ;
if ( ! V_100 ) {
V_24 = - V_47 ;
break;
}
}
V_102 = V_78 . V_86 ;
for ( V_103 = 0 , V_54 = V_2 -> V_34 ; V_102 && V_103 < V_2 -> V_31 ; V_103 ++ , V_54 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_54 ;
T_3 V_74 = V_4 -> V_39 ;
if ( V_74 > V_102 )
V_74 = V_102 ;
if ( V_54 == V_2 -> V_32 - 1 )
V_54 = - 1 ;
V_24 = F_53 ( V_2 , V_4 ) ;
if ( F_22 ( V_24 ) ) {
if ( V_24 == - V_13 )
V_24 = 0 ;
goto V_104;
}
V_100 [ V_103 ] . V_105 = V_4 -> V_5 ;
V_100 [ V_103 ] . V_106 = V_74 ;
V_100 [ V_103 ] . V_107 = V_4 -> V_37 ;
V_102 -= V_74 ;
}
F_66 ( & V_101 , V_108 | V_109 , V_100 , V_103 ,
V_78 . V_86 - V_102 ) ;
V_24 = F_67 ( V_30 , & V_101 , & V_78 . V_64 , 0 ) ;
if ( V_24 <= 0 )
break;
V_78 . V_91 += V_24 ;
V_78 . V_86 -= V_24 ;
* V_50 = V_78 . V_64 ;
while ( V_24 ) {
struct V_3 * V_4 = V_2 -> V_35 + V_2 -> V_34 ;
if ( V_24 >= V_4 -> V_39 ) {
V_24 -= V_4 -> V_39 ;
V_4 -> V_39 = 0 ;
F_25 ( V_2 , V_4 ) ;
V_2 -> V_34 = ( V_2 -> V_34 + 1 ) & ( V_2 -> V_32 - 1 ) ;
V_2 -> V_31 -- ;
if ( V_2 -> V_92 )
V_78 . V_93 = true ;
} else {
V_4 -> V_37 += V_24 ;
V_4 -> V_39 -= V_24 ;
V_24 = 0 ;
}
}
}
V_104:
F_29 ( V_100 ) ;
F_58 ( V_2 , & V_78 ) ;
F_63 ( V_2 ) ;
if ( V_78 . V_91 )
V_24 = V_78 . V_91 ;
return V_24 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_77 * V_78 )
{
int V_24 ;
void * V_110 ;
T_2 V_111 = V_78 -> V_64 ;
V_110 = F_69 ( V_4 -> V_5 ) ;
V_24 = F_70 ( V_78 -> V_79 . V_48 , V_110 + V_4 -> V_37 , V_78 -> V_39 , & V_111 ) ;
F_71 ( V_4 -> V_5 ) ;
return V_24 ;
}
static T_1 F_72 ( struct V_1 * V_2 ,
struct V_48 * V_30 , T_2 * V_50 ,
T_3 V_39 , unsigned int V_10 )
{
T_1 V_24 ;
V_24 = F_61 ( V_2 , V_30 , V_50 , V_39 , V_10 , F_68 ) ;
if ( V_24 > 0 )
* V_50 += V_24 ;
return V_24 ;
}
T_1 F_73 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 )
{
return F_61 ( V_2 , V_30 , V_50 , V_39 , V_10 , F_49 ) ;
}
static long F_74 ( struct V_1 * V_2 , struct V_48 * V_30 ,
T_2 * V_50 , T_3 V_39 , unsigned int V_10 )
{
T_1 (* F_75)( struct V_1 * , struct V_48 * ,
T_2 * , T_3 , unsigned int );
if ( V_30 -> V_81 -> F_75 )
F_75 = V_30 -> V_81 -> F_75 ;
else
F_75 = F_72 ;
return F_75 ( V_2 , V_30 , V_50 , V_39 , V_10 ) ;
}
static long F_76 ( struct V_48 * V_49 , T_2 * V_50 ,
struct V_1 * V_2 , T_3 V_39 ,
unsigned int V_10 )
{
T_1 (* F_77)( struct V_48 * , T_2 * ,
struct V_1 * , T_3 , unsigned int );
int V_24 ;
if ( F_22 ( ! ( V_49 -> V_112 & V_113 ) ) )
return - V_114 ;
V_24 = F_78 ( V_56 , V_49 , V_50 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
if ( F_22 ( V_39 > V_115 ) )
V_39 = V_115 ;
if ( V_49 -> V_81 -> F_77 )
F_77 = V_49 -> V_81 -> F_77 ;
else
F_77 = F_43 ;
return F_77 ( V_49 , V_50 , V_2 , V_39 , V_10 ) ;
}
T_1 F_79 ( struct V_48 * V_49 , struct V_77 * V_78 ,
T_6 * V_90 )
{
struct V_1 * V_2 ;
long V_24 , V_116 ;
T_7 V_117 ;
T_3 V_39 ;
int V_71 , V_10 , V_80 ;
V_117 = F_80 ( V_49 ) -> V_117 ;
if ( F_22 ( ! F_81 ( V_117 ) && ! F_82 ( V_117 ) ) )
return - V_83 ;
V_2 = V_28 -> V_118 ;
if ( F_22 ( ! V_2 ) ) {
V_2 = F_83 () ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_26 = 1 ;
V_28 -> V_118 = V_2 ;
}
V_24 = 0 ;
V_116 = 0 ;
V_39 = V_78 -> V_86 ;
V_10 = V_78 -> V_10 ;
V_78 -> V_10 &= ~ V_97 ;
V_80 = V_78 -> V_10 & V_84 ;
while ( V_39 ) {
T_3 V_119 ;
T_2 V_64 = V_78 -> V_64 , V_120 = V_64 ;
V_24 = F_76 ( V_49 , & V_64 , V_2 , V_39 , V_10 ) ;
if ( F_22 ( V_24 <= 0 ) )
goto V_121;
V_119 = V_24 ;
V_78 -> V_86 = V_119 ;
if ( V_119 < V_39 )
V_78 -> V_10 |= V_84 ;
else if ( ! V_80 )
V_78 -> V_10 &= ~ V_84 ;
V_24 = V_90 ( V_2 , V_78 ) ;
if ( F_22 ( V_24 <= 0 ) ) {
V_78 -> V_64 = V_120 ;
goto V_121;
}
V_116 += V_24 ;
V_39 -= V_24 ;
V_78 -> V_64 = V_64 ;
if ( V_24 < V_119 ) {
V_78 -> V_64 = V_120 + V_24 ;
goto V_121;
}
}
V_104:
V_2 -> V_31 = V_2 -> V_34 = 0 ;
F_35 ( V_49 ) ;
return V_116 ;
V_121:
for ( V_71 = 0 ; V_71 < V_2 -> V_32 ; V_71 ++ ) {
struct V_3 * V_4 = V_2 -> V_35 + V_71 ;
if ( V_4 -> V_41 )
F_25 ( V_2 , V_4 ) ;
}
if ( ! V_116 )
V_116 = V_24 ;
goto V_104;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_48 * V_48 = V_78 -> V_79 . V_48 ;
return F_74 ( V_2 , V_48 , V_78 -> V_122 , V_78 -> V_86 ,
V_78 -> V_10 ) ;
}
long F_85 ( struct V_48 * V_49 , T_2 * V_50 , struct V_48 * V_30 ,
T_2 * V_122 , T_3 V_39 , unsigned int V_10 )
{
struct V_77 V_78 = {
. V_39 = V_39 ,
. V_86 = V_39 ,
. V_10 = V_10 ,
. V_64 = * V_50 ,
. V_79 . V_48 = V_30 ,
. V_122 = V_122 ,
} ;
long V_24 ;
if ( F_22 ( ! ( V_30 -> V_112 & V_123 ) ) )
return - V_114 ;
if ( F_22 ( V_30 -> V_124 & V_125 ) )
return - V_83 ;
V_24 = F_78 ( V_109 , V_30 , V_122 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
V_24 = F_79 ( V_49 , & V_78 , F_84 ) ;
if ( V_24 > 0 )
* V_50 = V_78 . V_64 ;
return V_24 ;
}
static int F_86 ( struct V_1 * V_2 , unsigned V_10 )
{
for (; ; ) {
if ( F_22 ( ! V_2 -> V_26 ) ) {
F_23 ( V_27 , V_28 , 0 ) ;
return - V_29 ;
}
if ( V_2 -> V_31 != V_2 -> V_32 )
return 0 ;
if ( V_10 & V_97 )
return - V_42 ;
if ( F_55 ( V_28 ) )
return - V_94 ;
V_2 -> V_96 ++ ;
F_56 ( V_2 ) ;
V_2 -> V_96 -- ;
}
}
static long F_87 ( struct V_48 * V_49 , T_2 V_67 * V_126 ,
struct V_48 * V_30 , T_2 V_67 * V_127 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_1 * V_128 ;
struct V_1 * V_129 ;
T_2 V_37 ;
long V_24 ;
V_128 = F_88 ( V_49 ) ;
V_129 = F_88 ( V_30 ) ;
if ( V_128 && V_129 ) {
if ( V_126 || V_127 )
return - V_130 ;
if ( ! ( V_49 -> V_112 & V_113 ) )
return - V_114 ;
if ( ! ( V_30 -> V_112 & V_123 ) )
return - V_114 ;
if ( V_128 == V_129 )
return - V_83 ;
return F_89 ( V_128 , V_129 , V_39 , V_10 ) ;
}
if ( V_128 ) {
if ( V_126 )
return - V_130 ;
if ( V_127 ) {
if ( ! ( V_30 -> V_112 & V_131 ) )
return - V_83 ;
if ( F_90 ( & V_37 , V_127 , sizeof( T_2 ) ) )
return - V_59 ;
} else {
V_37 = V_30 -> V_132 ;
}
if ( F_22 ( ! ( V_30 -> V_112 & V_123 ) ) )
return - V_114 ;
if ( F_22 ( V_30 -> V_124 & V_125 ) )
return - V_83 ;
V_24 = F_78 ( V_109 , V_30 , & V_37 , V_39 ) ;
if ( F_22 ( V_24 < 0 ) )
return V_24 ;
F_91 ( V_30 ) ;
V_24 = F_74 ( V_128 , V_30 , & V_37 , V_39 , V_10 ) ;
F_92 ( V_30 ) ;
if ( ! V_127 )
V_30 -> V_132 = V_37 ;
else if ( F_93 ( V_127 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_59 ;
return V_24 ;
}
if ( V_129 ) {
if ( V_127 )
return - V_130 ;
if ( V_126 ) {
if ( ! ( V_49 -> V_112 & V_133 ) )
return - V_83 ;
if ( F_90 ( & V_37 , V_126 , sizeof( T_2 ) ) )
return - V_59 ;
} else {
V_37 = V_49 -> V_132 ;
}
F_62 ( V_129 ) ;
V_24 = F_86 ( V_129 , V_10 ) ;
if ( ! V_24 )
V_24 = F_76 ( V_49 , & V_37 , V_129 , V_39 , V_10 ) ;
F_63 ( V_129 ) ;
if ( V_24 > 0 )
F_16 ( V_129 ) ;
if ( ! V_126 )
V_49 -> V_132 = V_37 ;
else if ( F_93 ( V_126 , & V_37 , sizeof( T_2 ) ) )
V_24 = - V_59 ;
return V_24 ;
}
return - V_83 ;
}
static int F_94 ( struct V_51 * V_101 ,
struct V_1 * V_2 ,
unsigned V_10 )
{
struct V_3 V_4 = {
. V_41 = & V_134 ,
. V_10 = V_10
} ;
T_3 V_135 = 0 ;
int V_24 = 0 ;
bool V_136 = false ;
while ( F_95 ( V_101 ) && ! V_136 ) {
struct V_5 * V_36 [ 16 ] ;
T_1 V_70 ;
T_3 V_137 ;
int V_103 ;
V_70 = F_96 ( V_101 , V_36 , ~ 0UL , 16 , & V_137 ) ;
if ( V_70 <= 0 ) {
V_24 = V_70 ;
break;
}
for ( V_103 = 0 ; V_70 ; V_103 ++ , V_137 = 0 ) {
int V_138 = F_46 ( int , V_70 , V_73 - V_137 ) ;
if ( ! V_136 ) {
V_4 . V_5 = V_36 [ V_103 ] ;
V_4 . V_37 = V_137 ;
V_4 . V_39 = V_138 ;
V_24 = F_24 ( V_2 , & V_4 ) ;
if ( F_22 ( V_24 < 0 ) ) {
V_136 = true ;
} else {
F_36 ( V_101 , V_24 ) ;
V_135 += V_24 ;
}
} else {
F_12 ( V_36 [ V_103 ] ) ;
}
V_70 -= V_138 ;
}
}
return V_135 ? V_135 : V_24 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_77 * V_78 )
{
int V_103 = F_98 ( V_4 -> V_5 , V_4 -> V_37 , V_78 -> V_39 , V_78 -> V_79 . V_110 ) ;
return V_103 == V_78 -> V_39 ? V_103 : - V_59 ;
}
static long F_99 ( struct V_48 * V_48 , const struct V_66 V_67 * V_139 ,
unsigned long V_140 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_77 V_78 ;
long V_24 ;
struct V_66 V_141 [ V_142 ] ;
struct V_66 * V_143 = V_141 ;
struct V_51 V_144 ;
V_2 = F_88 ( V_48 ) ;
if ( ! V_2 )
return - V_114 ;
V_24 = F_100 ( V_56 , V_139 , V_140 ,
F_101 ( V_141 ) , & V_143 , & V_144 ) ;
if ( V_24 < 0 )
return V_24 ;
V_78 . V_86 = F_95 ( & V_144 ) ;
V_78 . V_39 = 0 ;
V_78 . V_10 = V_10 ;
V_78 . V_79 . V_110 = & V_144 ;
V_78 . V_64 = 0 ;
if ( V_78 . V_86 ) {
F_62 ( V_2 ) ;
V_24 = F_59 ( V_2 , & V_78 , F_97 ) ;
F_63 ( V_2 ) ;
}
F_29 ( V_143 ) ;
return V_24 ;
}
static long F_102 ( struct V_48 * V_48 , const struct V_66 V_67 * V_139 ,
unsigned long V_140 , unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_66 V_141 [ V_142 ] ;
struct V_66 * V_143 = V_141 ;
struct V_51 V_101 ;
long V_24 ;
unsigned V_145 = 0 ;
if ( V_10 & V_146 )
V_145 = V_15 ;
V_2 = F_88 ( V_48 ) ;
if ( ! V_2 )
return - V_114 ;
V_24 = F_100 ( V_109 , V_139 , V_140 ,
F_101 ( V_141 ) , & V_143 , & V_101 ) ;
if ( V_24 < 0 )
return V_24 ;
F_62 ( V_2 ) ;
V_24 = F_86 ( V_2 , V_10 ) ;
if ( ! V_24 )
V_24 = F_94 ( & V_101 , V_2 , V_145 ) ;
F_63 ( V_2 ) ;
if ( V_24 > 0 )
F_16 ( V_2 ) ;
F_29 ( V_143 ) ;
return V_24 ;
}
static int F_103 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 )
return 0 ;
V_24 = 0 ;
F_62 ( V_2 ) ;
while ( ! V_2 -> V_31 ) {
if ( F_55 ( V_28 ) ) {
V_24 = - V_94 ;
break;
}
if ( ! V_2 -> V_95 )
break;
if ( ! V_2 -> V_96 ) {
if ( V_10 & V_97 ) {
V_24 = - V_42 ;
break;
}
}
F_56 ( V_2 ) ;
}
F_63 ( V_2 ) ;
return V_24 ;
}
static int F_104 ( struct V_1 * V_2 , unsigned int V_10 )
{
int V_24 ;
if ( V_2 -> V_31 < V_2 -> V_32 )
return 0 ;
V_24 = 0 ;
F_62 ( V_2 ) ;
while ( V_2 -> V_31 >= V_2 -> V_32 ) {
if ( ! V_2 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
V_24 = - V_29 ;
break;
}
if ( V_10 & V_97 ) {
V_24 = - V_42 ;
break;
}
if ( F_55 ( V_28 ) ) {
V_24 = - V_94 ;
break;
}
V_2 -> V_96 ++ ;
F_56 ( V_2 ) ;
V_2 -> V_96 -- ;
}
F_63 ( V_2 ) ;
return V_24 ;
}
static int F_89 ( struct V_1 * V_128 ,
struct V_1 * V_129 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_147 , * V_148 ;
int V_24 = 0 , V_149 ;
bool V_150 = false ;
V_151:
V_24 = F_103 ( V_128 , V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_104 ( V_129 , V_10 ) ;
if ( V_24 )
return V_24 ;
F_105 ( V_128 , V_129 ) ;
do {
if ( ! V_129 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( ! V_128 -> V_31 && ! V_128 -> V_95 )
break;
if ( ! V_128 -> V_31 || V_129 -> V_31 >= V_129 -> V_32 ) {
if ( V_24 )
break;
if ( V_10 & V_97 ) {
V_24 = - V_42 ;
break;
}
F_63 ( V_128 ) ;
F_63 ( V_129 ) ;
goto V_151;
}
V_147 = V_128 -> V_35 + V_128 -> V_34 ;
V_149 = ( V_129 -> V_34 + V_129 -> V_31 ) & ( V_129 -> V_32 - 1 ) ;
V_148 = V_129 -> V_35 + V_149 ;
if ( V_39 >= V_147 -> V_39 ) {
* V_148 = * V_147 ;
V_147 -> V_41 = NULL ;
V_129 -> V_31 ++ ;
V_128 -> V_34 = ( V_128 -> V_34 + 1 ) & ( V_128 -> V_32 - 1 ) ;
V_128 -> V_31 -- ;
V_150 = true ;
} else {
F_106 ( V_128 , V_147 ) ;
* V_148 = * V_147 ;
V_148 -> V_10 &= ~ V_15 ;
V_148 -> V_39 = V_39 ;
V_129 -> V_31 ++ ;
V_147 -> V_37 += V_148 -> V_39 ;
V_147 -> V_39 -= V_148 -> V_39 ;
}
V_24 += V_148 -> V_39 ;
V_39 -= V_148 -> V_39 ;
} while ( V_39 );
F_63 ( V_128 ) ;
F_63 ( V_129 ) ;
if ( V_24 > 0 )
F_16 ( V_129 ) ;
if ( V_150 )
F_51 ( V_128 ) ;
return V_24 ;
}
static int F_107 ( struct V_1 * V_128 ,
struct V_1 * V_129 ,
T_3 V_39 , unsigned int V_10 )
{
struct V_3 * V_147 , * V_148 ;
int V_24 = 0 , V_71 = 0 , V_149 ;
F_105 ( V_128 , V_129 ) ;
do {
if ( ! V_129 -> V_26 ) {
F_23 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 )
V_24 = - V_29 ;
break;
}
if ( V_71 >= V_128 -> V_31 || V_129 -> V_31 >= V_129 -> V_32 )
break;
V_147 = V_128 -> V_35 + ( ( V_128 -> V_34 + V_71 ) & ( V_128 -> V_32 - 1 ) ) ;
V_149 = ( V_129 -> V_34 + V_129 -> V_31 ) & ( V_129 -> V_32 - 1 ) ;
F_106 ( V_128 , V_147 ) ;
V_148 = V_129 -> V_35 + V_149 ;
* V_148 = * V_147 ;
V_148 -> V_10 &= ~ V_15 ;
if ( V_148 -> V_39 > V_39 )
V_148 -> V_39 = V_39 ;
V_129 -> V_31 ++ ;
V_24 += V_148 -> V_39 ;
V_39 -= V_148 -> V_39 ;
V_71 ++ ;
} while ( V_39 );
if ( ! V_24 && V_128 -> V_96 && ( V_10 & V_97 ) )
V_24 = - V_42 ;
F_63 ( V_128 ) ;
F_63 ( V_129 ) ;
if ( V_24 > 0 )
F_16 ( V_129 ) ;
return V_24 ;
}
static long F_108 ( struct V_48 * V_49 , struct V_48 * V_30 , T_3 V_39 ,
unsigned int V_10 )
{
struct V_1 * V_128 = F_88 ( V_49 ) ;
struct V_1 * V_129 = F_88 ( V_30 ) ;
int V_24 = - V_83 ;
if ( V_128 && V_129 && V_128 != V_129 ) {
V_24 = F_103 ( V_128 , V_10 ) ;
if ( ! V_24 ) {
V_24 = F_104 ( V_129 , V_10 ) ;
if ( ! V_24 )
V_24 = F_107 ( V_128 , V_129 , V_39 , V_10 ) ;
}
}
return V_24 ;
}
