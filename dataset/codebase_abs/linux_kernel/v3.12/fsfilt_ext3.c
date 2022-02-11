static char * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 -> V_4 ;
}
static void * F_3 ( struct V_5 * V_5 , int V_6 , void * V_7 ,
int V_8 )
{
int V_9 = F_4 ( V_5 -> V_10 ) ;
T_1 * V_11 ;
void * V_12 ;
if ( V_13 -> V_14 ) {
F_5 ( V_15 , L_1 ,
V_13 -> V_14 ) ;
goto V_16;
}
switch( V_6 ) {
case V_17 :
V_9 += F_6 ( V_5 -> V_10 ) ;
V_9 += ( V_18 +
F_4 ( V_5 -> V_10 ) ) * V_8 ;
break;
case V_19 :
F_7 ( V_8 == 1 ) ;
V_9 = ( V_20 >> V_5 -> V_21 ) +
F_6 ( V_5 -> V_10 ) +
F_8 ( V_5 ) + 3 ;
break;
default: F_9 ( L_2 , V_6 ) ;
F_10 () ;
}
F_7 ( V_13 -> V_14 == V_7 ) ;
V_11 = F_2 ( V_5 -> V_10 ) -> V_22 ;
if ( V_9 > V_11 -> V_23 ) {
F_11 ( L_3 ,
V_9 , V_6 , V_8 , V_11 -> V_23 ) ;
V_9 = V_11 -> V_23 ;
}
V_16:
F_12 ( V_9 > 0 , L_4 , V_9 ) ;
V_12 = F_13 ( V_5 , V_9 ) ;
if ( ! F_14 ( V_12 ) )
F_7 ( V_13 -> V_14 == V_12 ) ;
else
F_9 ( L_5 ,
V_6 , V_9 , F_15 ( V_12 ) ) ;
return V_12 ;
}
static int F_16 ( struct V_5 * V_5 , void * V_24 , int V_25 )
{
int V_26 ;
T_2 * V_12 = V_24 ;
F_7 ( V_13 -> V_14 == V_12 ) ;
if ( V_25 )
V_12 -> V_27 = 1 ;
V_26 = F_17 ( V_12 ) ;
return V_26 ;
}
static long F_18 ( struct V_5 * V_5 , struct V_28 * V_29 ,
unsigned long V_30 , int * V_31 )
{
struct V_32 * V_33 = F_19 ( V_5 ) ;
unsigned long V_34 ;
unsigned long V_35 ;
int V_36 ;
if ( V_29 ) {
struct V_37 * V_38 ;
V_36 = V_29 -> V_39 ;
if ( ( V_38 = V_29 [ V_36 ] . V_40 ) )
return F_20 ( V_38 ) + ( V_30 - F_21 ( V_38 -> V_41 ) ) ;
if ( V_29 [ V_36 ] . V_42 )
return V_29 [ V_36 ] . V_42 -> V_43 ;
}
V_34 = ( V_33 -> V_44 * F_22 ( V_5 -> V_10 ) ) +
F_21 ( F_2 ( V_5 -> V_10 ) -> V_3 -> V_45 ) ;
V_35 = ( V_13 -> V_46 % 16 ) *
( F_22 ( V_5 -> V_10 ) / 16 ) ;
return V_34 + V_35 + V_30 ;
}
static unsigned long F_23 ( T_2 * V_12 , struct V_47 * V_48 ,
struct V_28 * V_29 , unsigned long V_30 ,
unsigned long * V_49 , int * V_50 )
{
unsigned long V_51 , V_52 ;
int V_31 = 0 ;
struct V_5 * V_5 = F_24 ( V_48 ) ;
V_52 = F_18 ( V_5 , V_29 , V_30 , & V_31 ) ;
V_31 |= 2 ;
V_51 = F_25 ( V_12 , V_5 , V_52 , V_49 , V_31 , V_50 ) ;
return V_51 ;
}
static unsigned long F_23 ( T_2 * V_12 , struct V_47 * V_48 ,
struct V_28 * V_29 , unsigned long V_30 ,
unsigned long * V_49 , int * V_50 )
{
struct V_5 * V_5 = F_24 ( V_48 ) ;
struct V_53 V_54 ;
unsigned long V_51 ;
int V_31 ;
V_54 . V_55 = V_30 ;
* V_50 = F_26 ( V_48 , V_29 , & V_54 . V_55 , & V_54 . V_56 ) ;
if ( * V_50 )
return 0 ;
V_54 . V_57 = V_30 ;
* V_50 = F_27 ( V_48 , V_29 , & V_54 . V_57 , & V_54 . V_58 ) ;
if ( * V_50 )
return 0 ;
V_54 . V_52 = F_18 ( V_5 , V_29 , V_30 , & V_31 ) ;
V_54 . V_5 = V_5 ;
V_54 . V_59 = V_30 ;
V_54 . V_60 = * V_49 ;
V_54 . V_61 = V_62 ;
V_51 = F_25 ( V_12 , & V_54 , V_50 ) ;
* V_49 = V_54 . V_60 ;
return V_51 ;
}
static int F_28 ( struct V_47 * V_48 ,
struct V_28 * V_29 ,
struct V_63 * V_64 ,
#ifdef F_29
struct V_37 * V_38 ,
#endif
void * V_65 )
{
struct V_66 * V_67 = V_65 ;
struct V_5 * V_5 = F_24 ( V_48 ) ;
struct V_37 V_68 ;
unsigned long V_51 ;
unsigned long V_69 ;
int V_50 , V_70 ;
unsigned long V_49 ;
T_2 * V_12 ;
#ifdef F_30
if ( V_64 -> V_71 == F_30 )
#else
if ( ( V_64 -> V_72 != 0 ) && ( V_64 -> V_73 != 0 ) )
#endif
{
V_50 = V_74 ;
goto V_75;
}
if ( V_67 -> V_76 == 0 ) {
V_70 = 0 ;
if ( V_64 -> V_77 < V_67 -> V_78 )
V_70 = V_67 -> V_78 - V_64 -> V_77 ;
if ( V_70 >= V_64 -> V_72 )
F_9 ( L_6 ,
V_70 , V_64 -> V_72 ) ;
for (; V_70 < V_64 -> V_72 && V_67 -> V_79 ; V_70 ++ ) {
* ( V_67 -> V_80 ) = 0 ;
V_67 -> V_80 ++ ;
V_67 -> V_79 -- ;
V_67 -> V_78 ++ ;
}
return V_74 ;
}
V_69 = F_31 ( V_48 ) ;
V_49 = F_32 ( V_48 , V_29 ) ;
V_12 = F_13 ( V_5 , V_49 + V_81 + 1 ) ;
if ( F_14 ( V_12 ) ) {
return F_15 ( V_12 ) ;
}
if ( V_69 != F_31 ( V_48 ) ) {
F_17 ( V_12 ) ;
return V_82 ;
}
F_33 ( ( & F_34 ( V_5 ) -> V_83 ) ) ;
if ( F_31 ( V_48 ) != V_29 [ 0 ] . V_84 ) {
F_35 ( & F_34 ( V_5 ) -> V_83 ) ;
F_17 ( V_12 ) ;
return V_82 ;
}
V_49 = V_64 -> V_72 ;
V_51 = F_23 ( V_12 , V_48 , V_29 , V_64 -> V_77 , & V_49 , & V_50 ) ;
if ( ! V_51 )
goto V_85;
F_36 ( V_49 <= V_64 -> V_72 ) ;
V_68 . V_41 = F_37 ( V_64 -> V_77 ) ;
F_38 ( & V_68 , V_51 ) ;
V_68 . V_86 = F_39 ( V_49 ) ;
V_50 = F_40 ( V_12 , V_48 , V_29 , & V_68 , 0 ) ;
if ( V_50 ) {
#ifdef F_41
F_42 ( V_5 ) ;
#endif
#ifdef F_43
F_44 ( V_12 , V_5 , NULL , F_20 ( & V_68 ) ,
F_39 ( V_68 . V_86 ) , 0 ) ;
#else
F_44 ( V_12 , V_5 , F_20 ( & V_68 ) ,
F_39 ( V_68 . V_86 ) , 0 ) ;
#endif
goto V_85;
}
V_64 -> V_72 = F_45 ( V_68 . V_86 ) ;
V_64 -> V_73 = F_20 ( & V_68 ) ;
F_46 ( F_45 ( V_68 . V_86 ) == 0 ) ;
F_46 ( F_21 ( V_68 . V_41 ) != V_64 -> V_77 ) ;
V_85:
F_35 ( ( & F_34 ( V_5 ) -> V_83 ) ) ;
F_17 ( V_12 ) ;
V_75:
if ( V_50 >= 0 ) {
if ( V_67 -> V_79 == 0 ) {
F_9 ( L_7 ) ;
F_9 ( L_8 ,
V_67 -> V_78 , V_67 -> V_87 ) ;
#ifdef F_30
F_9 ( L_9 ,
V_64 -> V_77 , V_64 -> V_72 ,
( unsigned long long ) V_64 -> V_73 ,
V_64 -> V_71 ) ;
#else
F_9 ( L_10 ,
V_64 -> V_77 , V_64 -> V_72 ,
( unsigned long long ) V_64 -> V_73 ) ;
#endif
}
V_70 = 0 ;
if ( V_64 -> V_77 < V_67 -> V_78 )
V_70 = V_67 -> V_78 - V_64 -> V_77 ;
if ( V_70 >= V_64 -> V_72 )
F_9 ( L_6 ,
V_70 , V_64 -> V_72 ) ;
for (; V_70 < V_64 -> V_72 && V_67 -> V_79 ; V_70 ++ ) {
* ( V_67 -> V_80 ) = V_64 -> V_73 + V_70 ;
#ifdef F_30
if ( V_64 -> V_71 != F_30 )
#else
if ( ( V_64 -> V_72 == 0 ) || ( V_64 -> V_73 == 0 ) )
#endif
{
F_47 ( V_5 -> V_10 ,
* ( V_67 -> V_80 ) ) ;
}
V_67 -> V_80 ++ ;
V_67 -> V_79 -- ;
V_67 -> V_78 ++ ;
}
}
return V_50 ;
}
int F_48 ( struct V_5 * V_5 , unsigned long V_30 ,
unsigned long V_79 , unsigned long * V_80 ,
int V_76 )
{
struct V_47 * V_48 = V_5 ;
struct V_66 V_67 ;
int V_50 ;
F_5 ( V_88 , L_11 ,
V_30 , V_30 + V_79 - 1 , ( unsigned ) V_5 -> V_89 ) ;
V_67 . V_80 = V_80 ;
V_67 . V_78 = V_30 ;
V_67 . V_87 = V_67 . V_79 = V_79 ;
V_67 . V_76 = V_76 ;
V_50 = F_49 ( V_48 , V_30 , V_79 ,
F_28 , & V_67 ) ;
F_50 ( V_48 ) ;
return V_50 ;
}
int F_51 ( struct V_5 * V_5 , struct V_90 * * V_90 ,
int V_91 , unsigned long * V_80 ,
int V_76 )
{
int V_92 = V_93 >> V_5 -> V_21 ;
int V_26 = 0 , V_70 = 0 ;
struct V_90 * V_94 = NULL ;
int V_95 = 0 ;
F_5 ( V_88 , L_12 ,
V_5 -> V_89 , V_91 , ( * V_90 ) -> V_96 ) ;
while ( V_70 < V_91 ) {
if ( V_94 == NULL ) {
V_94 = * V_90 ++ ;
V_95 = 1 ;
V_70 ++ ;
continue;
} else if ( V_94 -> V_96 + V_95 == ( * V_90 ) -> V_96 ) {
V_90 ++ ;
V_95 ++ ;
V_70 ++ ;
continue;
}
V_26 = F_48 ( V_5 , V_94 -> V_96 * V_92 ,
V_95 * V_92 , V_80 ,
V_76 ) ;
if ( V_26 )
GOTO ( V_97 , V_26 ) ;
V_94 = NULL ;
V_80 += V_92 * V_95 ;
}
if ( V_94 )
V_26 = F_48 ( V_5 , V_94 -> V_96 * V_92 ,
V_95 * V_92 , V_80 ,
V_76 ) ;
V_97:
return V_26 ;
}
int F_52 ( struct V_5 * V_5 , struct V_90 * * V_90 ,
int V_91 , unsigned long * V_80 ,
int V_76 )
{
int V_92 = V_93 >> V_5 -> V_21 ;
unsigned long * V_98 ;
int V_26 = 0 , V_70 ;
for ( V_70 = 0 , V_98 = V_80 ; V_70 < V_91 ; V_70 ++ , V_90 ++ ) {
V_26 = F_53 ( V_5 , * V_90 , V_98 , V_76 ) ;
if ( V_26 ) {
F_9 ( L_13 ,
V_5 -> V_89 , * V_98 , V_76 , V_26 ) ;
break;
}
V_98 += V_92 ;
}
return V_26 ;
}
int F_54 ( struct V_5 * V_5 , struct V_90 * * V_90 ,
int V_91 , unsigned long * V_80 ,
int V_76 , struct V_99 * V_100 )
{
int V_26 ;
if ( F_19 ( V_5 ) -> V_101 & V_102 ) {
V_26 = F_51 ( V_5 , V_90 , V_91 ,
V_80 , V_76 ) ;
return V_26 ;
}
if ( V_100 != NULL )
F_55 ( V_100 ) ;
V_26 = F_52 ( V_5 , V_90 , V_91 , V_80 , V_76 ) ;
if ( V_100 != NULL )
F_56 ( V_100 ) ;
return V_26 ;
}
int F_57 ( struct V_5 * V_5 , void * V_103 , int V_104 , T_3 * V_105 )
{
unsigned long V_30 ;
struct V_106 * V_107 ;
int V_50 , V_108 , V_109 , V_110 , V_111 = V_104 ;
F_58 ( & V_5 -> V_112 ) ;
if ( F_59 ( V_5 ) < * V_105 + V_104 ) {
V_104 = F_59 ( V_5 ) - * V_105 ;
F_60 ( & V_5 -> V_112 ) ;
if ( V_104 < 0 ) {
F_5 ( V_113 , L_14 ,
F_59 ( V_5 ) , * V_105 ) ;
return - V_114 ;
} else if ( V_104 == 0 ) {
return 0 ;
}
} else {
F_60 ( & V_5 -> V_112 ) ;
}
V_108 = 1 << V_5 -> V_21 ;
while ( V_104 > 0 ) {
V_30 = * V_105 >> V_5 -> V_21 ;
V_110 = * V_105 & ( V_108 - 1 ) ;
V_109 = F_61 ( V_108 - V_110 , V_104 ) ;
V_107 = F_62 ( NULL , V_5 , V_30 , 0 , & V_50 ) ;
if ( ! V_107 ) {
F_9 ( L_15 , V_50 ) ;
return V_50 ;
}
memcpy ( V_103 , V_107 -> V_115 + V_110 , V_109 ) ;
F_63 ( V_107 ) ;
* V_105 += V_109 ;
V_103 += V_109 ;
V_104 -= V_109 ;
}
return V_111 ;
}
static int F_64 ( struct V_116 * V_116 , void * V_103 ,
int V_104 , T_3 * V_105 )
{
int V_26 ;
V_26 = F_57 ( V_116 -> V_117 -> V_118 , V_103 , V_104 , V_105 ) ;
if ( V_26 > 0 )
V_26 = 0 ;
return V_26 ;
}
int F_65 ( struct V_5 * V_5 , void * V_103 , int V_119 ,
T_3 * V_105 , T_2 * V_12 )
{
struct V_106 * V_107 = NULL ;
T_3 V_120 = F_59 ( V_5 ) , V_121 = * V_105 ;
T_3 V_122 = F_59 ( V_5 ) ;
unsigned long V_30 ;
int V_50 = 0 , V_108 = 1 << V_5 -> V_21 , V_104 , V_110 ;
while ( V_119 > 0 ) {
if ( V_107 != NULL )
F_63 ( V_107 ) ;
V_30 = V_121 >> V_5 -> V_21 ;
V_110 = V_121 & ( V_108 - 1 ) ;
V_104 = F_61 ( V_108 - V_110 , V_119 ) ;
V_107 = F_62 ( V_12 , V_5 , V_30 , 1 , & V_50 ) ;
if ( ! V_107 ) {
F_9 ( L_16 , V_50 ) ;
break;
}
V_50 = F_66 ( V_12 , V_107 ) ;
if ( V_50 ) {
F_9 ( L_17 ,
V_50 ) ;
break;
}
F_7 ( V_107 -> V_115 + V_110 + V_104 <= V_107 -> V_115 + V_107 -> V_123 ) ;
memcpy ( V_107 -> V_115 + V_110 , V_103 , V_104 ) ;
V_50 = F_67 ( V_12 , V_107 ) ;
if ( V_50 ) {
F_9 ( L_18 ,
V_50 ) ;
break;
}
if ( V_121 + V_104 > V_122 )
V_122 = V_121 + V_104 ;
V_121 += V_104 ;
V_119 -= V_104 ;
V_103 += V_104 ;
}
if ( V_107 )
F_63 ( V_107 ) ;
if ( V_122 > F_59 ( V_5 ) ) {
F_58 ( & V_5 -> V_112 ) ;
if ( V_122 > F_59 ( V_5 ) )
F_68 ( V_5 , V_122 ) ;
if ( F_59 ( V_5 ) > F_19 ( V_5 ) -> V_124 )
F_19 ( V_5 ) -> V_124 = F_59 ( V_5 ) ;
if ( F_59 ( V_5 ) > V_120 ) {
F_60 ( & V_5 -> V_112 ) ;
F_69 ( V_5 ) ;
} else {
F_60 ( & V_5 -> V_112 ) ;
}
}
if ( V_50 == 0 )
* V_105 = V_121 ;
return V_50 ;
}
static int F_70 ( struct V_116 * V_116 , void * V_103 , int V_119 ,
T_3 * V_105 , int V_25 )
{
struct V_5 * V_5 = V_116 -> V_117 -> V_118 ;
T_2 * V_12 ;
int V_50 , V_125 = 0 , V_108 ;
V_108 = 1 << V_5 -> V_21 ;
V_125 = ( * V_105 & ( V_108 - 1 ) ) + V_119 ;
V_125 = ( V_125 + V_108 - 1 ) >> V_5 -> V_21 ;
V_12 = F_13 ( V_5 ,
V_125 * F_71 ( V_5 -> V_10 ) + 2 ) ;
if ( F_14 ( V_12 ) ) {
F_9 ( L_19 ,
V_125 * F_71 ( V_5 -> V_10 ) + 2 ,
V_119 ) ;
return F_15 ( V_12 ) ;
}
V_50 = F_65 ( V_5 , V_103 , V_119 , V_105 , V_12 ) ;
if ( ! V_50 && V_25 )
V_12 -> V_27 = 1 ;
F_17 ( V_12 ) ;
return V_50 ;
}
static int F_72 ( struct V_1 * V_2 )
{
if ( ! F_73 ( V_2 ,
V_126 ) ) {
F_9 ( L_20 ) ;
return - V_127 ;
}
#ifdef F_74
F_11 ( L_21 ) ;
F_75 ( F_2 ( V_2 ) -> V_128 , V_129 ) ;
V_2 -> V_130 |= F_74 ;
#endif
if ( ! F_73 ( V_2 , V_131 ) )
F_11 ( L_22 ) ;
return 0 ;
}
static int T_4 F_76 ( void )
{
int V_26 ;
V_132 = F_77 ( L_23 ,
sizeof( struct V_133 ) , 0 , 0 ) ;
if ( ! V_132 ) {
F_9 ( L_24 ) ;
GOTO ( V_85 , V_26 = - V_134 ) ;
}
V_26 = F_78 ( & V_135 ) ;
if ( V_26 ) {
int V_50 = F_79 ( V_132 ) ;
F_12 ( V_50 == 0 , L_25 , V_50 ) ;
}
V_85:
return V_26 ;
}
static void T_5 F_80 ( void )
{
int V_26 ;
F_81 ( & V_135 ) ;
V_26 = F_79 ( V_132 ) ;
F_12 ( V_26 == 0 , L_26 ) ;
}
