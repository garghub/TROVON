static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_8 , V_9 = 0 , V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( 0 > V_12 -> V_13 -> V_14 ) {
int V_15 = V_12 -> V_13 -> V_16 + 1 ;
if ( V_15 >= F_2 ( V_12 -> V_13 -> V_17 ) )
V_15 = 0 ;
V_12 -> V_13 -> V_14 = V_15 ;
F_3 ( L_1 , V_15 ) ;
}
for ( V_8 = 0 ; V_8 < F_4 () ; V_8 ++ ) {
if ( V_3 -> V_18 [ V_8 ] . V_19 ) {
F_5 ( V_20 L_2 , V_3 -> V_18 [ V_8 ] . V_19 ) ;
return V_3 -> V_18 [ V_8 ] . V_19 ;
}
V_9 += V_3 -> V_18 [ V_8 ] . V_21 / V_12 -> V_22 ;
}
if ( ( V_10 += V_9 ) >= V_6 -> V_23 )
V_10 -= V_6 -> V_23 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_24 += V_9 ;
if ( V_2 -> V_24 >= V_6 -> V_25 ) {
V_2 -> V_24 -= V_6 -> V_25 ;
F_6 ( V_2 -> V_7 ) ;
}
return 0 ;
}
static inline int F_7 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
return ( V_6 -> V_23 * 1000 ) / V_12 -> V_26 + 1 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
int V_27 , V_28 , V_29 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_30 * V_31 = V_12 -> V_13 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
if ( 0 > V_31 -> V_32 ) {
V_31 -> V_32 = V_31 -> V_16 -
F_7 ( V_6 , V_12 ) ;
if ( 0 > V_31 -> V_32 )
V_31 -> V_32 += F_2 ( V_31 -> V_17 ) ;
V_31 -> V_33 = V_31 -> V_32 ;
}
V_27 = 0 ;
for ( V_29 = 0 ; V_29 < F_4 () ; V_29 ++ ) {
V_28 = V_31 -> V_17 [ V_31 -> V_33 ] . V_34 / V_12 -> V_22 ;
if ( V_28 < 43 || V_28 > 50 ) {
F_5 ( V_20 L_3 , V_28 ) ;
return - V_35 ;
}
V_3 -> V_18 [ V_29 ] . V_36 = V_31 -> V_17 [ V_31 -> V_33 ] . V_36 ;
V_3 -> V_18 [ V_29 ] . V_34 = V_31 -> V_17 [ V_31 -> V_33 ] . V_34 ;
if ( F_9 ( & V_2 -> V_37 ) != V_38 )
memset ( ( char * ) V_3 -> V_39 + V_3 -> V_18 [ V_29 ] . V_36 , 0 ,
V_3 -> V_18 [ V_29 ] . V_34 ) ;
if ( ++ V_31 -> V_33 >= F_2 ( V_31 -> V_17 ) )
V_31 -> V_33 = 0 ;
V_27 += V_28 ;
}
V_3 -> V_40 = V_27 * V_12 -> V_22 ;
return 0 ;
}
static inline void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_4 () ; ++ V_29 ) {
struct V_41 * V_42 = V_3 -> V_18 + V_29 ;
if ( NULL != V_2 ) {
struct V_30 * V_31 = V_2 -> V_12 -> V_13 ;
int V_15 = V_31 -> V_16 + 1 ;
if ( V_15 >= F_2 ( V_31 -> V_17 ) )
V_15 = 0 ;
V_31 -> V_17 [ V_15 ] . V_43 = V_3 -> V_44 + V_29 ;
V_31 -> V_17 [ V_15 ] . V_36 = V_42 -> V_36 ;
V_31 -> V_17 [ V_15 ] . V_34 = V_42 -> V_21 ;
V_31 -> V_16 = V_15 ;
V_31 -> V_45 ++ ;
}
if ( ( V_42 -> V_36 += V_42 -> V_34 * V_46 * F_4 () ) +
V_42 -> V_34 >= V_47 )
V_42 -> V_36 -= ( V_47 - V_42 -> V_34 ) ;
}
}
static inline int F_11 ( struct V_1 * V_48 ,
struct V_1 * V_49 ,
struct V_1 * V_50 ,
int V_43 )
{
int V_51 , V_37 ;
struct V_3 * V_3 = V_50 -> V_4 ;
V_37 = F_9 ( & V_50 -> V_37 ) ;
if ( NULL != V_3 ) {
if ( V_37 == V_38 )
F_12 ( V_50 , V_3 ) ;
else if ( V_37 >= V_52 )
F_13 ( & V_50 -> V_37 ) ;
} else {
switch ( V_37 ) {
case V_53 :
V_3 = V_50 -> V_3 [ 0 ] ;
F_13 ( & V_50 -> V_37 ) ;
break;
case V_54 :
V_3 = V_50 -> V_3 [ 1 ] ;
F_13 ( & V_50 -> V_37 ) ;
break;
}
}
if ( V_3 ) {
if ( ( V_51 = F_8 ( V_50 , V_3 ) ) ||
( V_51 = F_14 ( V_50 , V_3 , V_43 ) ) ) {
return V_51 ;
}
}
V_50 -> V_4 = NULL ;
V_37 = F_9 ( & V_48 -> V_37 ) ;
if ( V_37 >= V_55 ) {
if ( V_37 == V_38 ) {
if ( ( V_51 = F_1 ( V_48 ) ) )
return V_51 ;
} else if ( V_37 >= V_52 )
F_13 ( & V_48 -> V_37 ) ;
F_10 ( V_48 , V_48 -> V_4 ) ;
if ( NULL != V_49 )
F_10 ( NULL , V_49 -> V_4 ) ;
if ( ( V_51 = F_14 ( V_48 , V_48 -> V_4 , V_43 ) ) )
return V_51 ;
if ( NULL != V_49 )
if ( ( V_51 = F_14 ( V_49 , V_49 -> V_4 , V_43 ) ) )
return V_51 ;
}
V_48 -> V_4 = NULL ;
if ( NULL != V_49 )
V_49 -> V_4 = NULL ;
return 0 ;
}
static void F_15 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_56 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_1 * V_48 , * V_49 , * V_50 ;
if ( F_16 ( F_9 ( & V_2 -> V_37 ) < V_55 ) ) {
F_3 ( L_4 ,
F_17 ( V_12 -> V_57 ) ,
V_2 -> V_58 , F_18 ( V_3 -> V_59 ) ? L_5 : L_6 ,
V_3 -> V_19 , V_3 -> V_44 ) ;
return;
}
if ( F_16 ( V_3 -> V_19 ) ) {
F_19 ( V_12 , V_2 , V_3 ) ;
return;
}
V_2 -> V_4 = V_3 ;
V_48 = V_12 -> V_2 [ V_60 ] ;
V_49 = V_12 -> V_2 [ V_60 + 2 ] ;
V_50 = V_12 -> V_2 [ V_61 ] ;
if ( V_48 -> V_4 && F_9 ( & V_48 -> V_37 ) >= V_55 &&
( NULL == V_49 || V_49 -> V_4 ) &&
( V_50 -> V_4 || F_9 ( & V_50 -> V_37 ) < V_55 ) ) {
if ( ! F_11 ( V_48 , V_49 , V_50 , V_3 -> V_44 ) )
V_12 -> V_62 += F_4 () ;
else {
F_3 ( L_7 ) ;
F_20 ( V_12 ) ;
}
}
}
static void F_21 ( struct V_3 * * V_3 )
{
F_22 ( * V_3 ) ;
F_23 ( * V_3 ) ;
* V_3 = NULL ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_8 ;
F_3 ( L_8 , V_2 -> V_58 ) ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ )
F_21 ( V_2 -> V_3 + V_8 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
F_26 ( V_12 , F_15 ) ;
V_12 -> V_63 = NULL ;
}
static void F_27 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_56 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_1 * V_63 = V_12 -> V_63 ;
if ( NULL != V_63 &&
V_3 -> V_44 == V_63 -> V_3 [ 0 ] -> V_44 ) {
F_13 ( & V_63 -> V_37 ) ;
if ( V_63 == V_12 -> V_2 [ V_60 ] ) {
struct V_1 * V_64 = V_12 -> V_2 [ V_60 + 2 ] ;
if ( V_64 != NULL )
F_13 ( & V_64 -> V_37 ) ;
}
F_25 ( V_12 ) ;
F_28 ( & V_12 -> V_65 ) ;
}
F_15 ( V_3 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_8 ;
unsigned int V_59 ;
int V_66 = V_2 == V_2 -> V_12 -> V_2 [ V_61 ] ;
struct V_67 * V_57 = V_2 -> V_12 -> V_57 ;
V_59 = V_66 ? F_30 ( V_57 , V_2 -> V_58 ) :
F_31 ( V_57 , V_2 -> V_58 ) ;
V_2 -> V_68 = F_32 ( V_57 , V_59 , V_66 ) ;
if ( ! V_2 -> V_68 )
return - V_69 ;
for ( V_8 = 0 ; V_8 < V_46 ; V_8 ++ ) {
struct V_3 * * V_70 = V_2 -> V_3 + V_8 ;
if ( * V_70 ) {
F_22 ( * V_70 ) ;
continue;
}
* V_70 = F_33 ( F_4 () , V_71 ) ;
if ( NULL == * V_70 ) {
F_24 ( V_2 ) ;
return - V_72 ;
}
( * V_70 ) -> V_39 = V_66 ?
V_2 -> V_12 -> V_13 -> V_73 : (
V_2 -> V_58 == 0x8 ?
V_2 -> V_12 -> V_13 -> V_74 :
V_2 -> V_12 -> V_13 -> V_75 ) ;
( * V_70 ) -> V_57 = V_57 ;
( * V_70 ) -> V_59 = V_59 ;
( * V_70 ) -> V_76 = F_4 () ;
( * V_70 ) -> V_56 = V_2 ;
( * V_70 ) -> V_77 = 1 ;
( * V_70 ) -> V_78 = F_27 ;
}
return 0 ;
}
static int F_34 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = V_80 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_81 ,
* V_64 = V_2 -> V_12 -> V_2 [ V_60 + 2 ] ;
F_35 ( & V_2 -> V_12 -> V_82 ) ;
F_3 ( L_9 , V_80 ) ;
if ( V_61 == V_80 -> V_83 ) {
struct V_1 * V_84 = V_2 -> V_12 -> V_2 [ V_60 ] ;
F_36 ( & V_2 -> V_37 , V_85 ) ;
F_24 ( V_2 ) ;
if ( ! V_84 -> V_7 ||
! V_84 -> V_7 -> V_6 ||
! V_84 -> V_7 -> V_6 -> V_19 ||
V_84 -> V_7 -> V_6 -> V_19 -> V_37 < V_86 ) {
F_36 ( & V_84 -> V_37 , V_85 ) ;
if ( NULL != V_64 )
F_36 ( & V_64 -> V_37 , V_85 ) ;
F_24 ( V_84 ) ;
if ( NULL != V_64 )
F_24 ( V_64 ) ;
}
} else {
struct V_1 * V_87 = V_2 -> V_12 -> V_2 [ V_61 ] ;
if ( F_9 ( & V_87 -> V_37 ) < V_55 ) {
F_36 ( & V_2 -> V_37 , V_85 ) ;
if ( NULL != V_64 )
F_36 ( & V_64 -> V_37 , V_85 ) ;
F_24 ( V_2 ) ;
if ( NULL != V_64 )
F_24 ( V_64 ) ;
}
}
F_37 ( & V_2 -> V_12 -> V_82 ) ;
return F_38 ( V_80 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
V_12 -> V_63 = V_2 ;
V_2 -> V_3 [ 0 ] -> V_44 = - 1 ;
F_40 () ;
F_26 ( V_12 , F_27 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_88 , V_89 , V_51 ,
V_83 = V_2 -> V_7 -> V_83 ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_60 == V_83 ) {
V_12 -> V_13 -> V_16 = - 1 ;
V_12 -> V_13 -> V_45 = 0 ;
}
for ( V_88 = 0 ; 3 >= ( V_83 + V_88 ) ; V_88 += 2 ) {
struct V_1 * V_2 = V_12 -> V_2 [ V_83 + V_88 ] ;
if ( V_2 != NULL ) {
if ( ( V_51 = F_29 ( V_2 ) ) < 0 )
return V_51 ;
V_2 -> V_4 = NULL ;
}
}
for ( V_88 = 0 ; V_88 < 4 ; V_88 ++ ) {
struct V_1 * V_2 = V_12 -> V_2 [ V_88 ] ;
if ( V_2 != NULL && F_9 ( & V_2 -> V_37 ) >= V_55 )
goto V_90;
}
V_90:
F_39 ( V_2 ) ;
for ( V_89 = 0 ; V_89 < V_46 ; V_89 ++ ) {
for ( V_88 = 0 ; 3 >= ( V_83 + V_88 ) ; V_88 += 2 ) {
struct V_1 * V_2 = V_12 -> V_2 [ V_83 + V_88 ] ;
if ( V_2 != NULL ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_89 ] ;
if ( F_18 ( V_3 -> V_59 ) ) {
unsigned long V_29 ;
if ( 0 == V_89 )
F_36 ( & V_2 -> V_37 , V_91 ) ;
V_3 -> V_57 = V_12 -> V_57 ;
for ( V_29 = 0 ; V_29 < F_4 () ; V_29 ++ ) {
V_3 -> V_18 [ V_29 ] . V_36 = V_2 -> V_68 * ( V_29 + V_89 * F_4 () ) ;
V_3 -> V_18 [ V_29 ] . V_34 = V_2 -> V_68 ;
}
V_3 -> V_40 = V_2 -> V_68 * F_4 () ;
if ( ( V_51 = F_42 ( V_3 , V_71 ) ) < 0 ) {
F_5 ( V_20 L_10 , V_89 , V_51 ) ;
V_51 = - V_35 ;
goto V_92;
} else {
F_3 ( L_11 , V_3 -> V_44 ) ;
if ( V_89 == 0 )
V_12 -> V_62 = V_3 -> V_44 ;
}
V_3 -> V_93 = 0 ;
} else {
F_36 ( & V_2 -> V_37 , V_53 ) ;
break;
}
}
}
}
V_51 = 0 ;
F_43 ( V_12 -> V_65 , NULL == V_12 -> V_63 ) ;
if ( F_9 ( & V_2 -> V_37 ) != V_55 )
V_51 = - V_35 ;
V_92:
if ( V_51 ) {
F_44 ( V_12 ) ;
F_20 ( V_12 ) ;
}
return V_51 ;
}
static int F_45 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = V_80 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_81 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_1 * V_48 = V_2 -> V_12 -> V_2 [ V_60 ] ;
int V_51 = 0 ;
F_3 ( L_12 , V_80 ) ;
if ( NULL == V_12 -> V_13 ) {
if ( NULL == ( V_12 -> V_13 = F_46 ( sizeof( struct V_30 ) , V_71 ) ) )
return - V_72 ;
memset ( V_12 -> V_13 , 0 , sizeof( struct V_30 ) ) ;
}
F_35 ( & V_12 -> V_82 ) ;
F_47 ( V_2 ) ;
if ( F_9 ( & V_48 -> V_37 ) < V_55 ) {
if ( V_12 -> V_94 != V_6 -> V_94 )
if ( ( V_51 = F_48 ( V_12 , V_6 -> V_94 ) ) < 0 )
goto V_95;
if ( V_12 -> V_26 != V_6 -> V_26 )
if ( ( V_51 = F_49 ( V_12 , V_6 -> V_26 ) ) < 0 )
goto V_95;
F_3 ( L_13 , V_2 == V_48 ?
L_14 : L_15 ) ;
if ( 0 > ( V_51 = F_41 ( V_48 ) ) )
goto V_95;
}
if ( V_2 != V_48 ) {
V_12 -> V_13 -> V_32 = - 1 ;
if ( F_9 ( & V_2 -> V_37 ) < V_55 ) {
while ( F_7 ( V_6 , V_12 ) >
V_12 -> V_13 -> V_45 ) {
F_3 ( L_16
L_17 ,
F_7 ( V_6 , V_12 ) ,
V_12 -> V_13 -> V_45 ) ;
if ( F_50 ( 10 ) ) {
V_51 = - V_96 ;
goto V_95;
}
}
if ( 0 > ( V_51 = F_41 ( V_2 ) ) )
goto V_95;
}
F_3 ( L_18 ,
F_7 ( V_6 , V_12 ) ,
V_12 -> V_13 -> V_45 ) ;
} else
V_12 -> V_13 -> V_14 = - 1 ;
V_95:
F_37 ( & V_12 -> V_82 ) ;
return V_51 ;
}
static int F_51 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = ( (struct V_1 * * )
F_52 ( V_80 ) ) [ V_80 -> V_83 ] ;
struct V_5 * V_6 = V_80 -> V_6 ;
if ( ! ( V_2 -> V_12 -> V_97 & V_98 ) )
return - V_99 ;
V_6 -> V_100 = V_61 == V_80 -> V_83 ? V_101 :
( V_2 -> V_12 -> V_2 [ 3 ] ? V_102 : V_101 ) ;
V_6 -> V_81 = V_2 ;
V_2 -> V_7 = V_80 ;
F_53 ( V_6 , V_103 , 1000 , 200000 ) ;
return 0 ;
}
static int F_54 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = V_80 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_81 ;
V_2 -> V_7 = NULL ;
return 0 ;
}
static int F_55 ( struct V_104 * V_105 )
{
struct V_106 * V_107 ;
struct V_108 * V_57 ;
struct V_109 * V_110 ;
int V_51 = 0 ;
F_56 (list, &card->devices) {
V_57 = V_108 ( V_107 ) ;
if ( V_57 -> type != V_111 )
continue;
V_110 = V_57 -> V_112 ;
F_35 ( & V_110 -> V_113 ) ;
}
F_56 (list, &card->devices) {
int V_114 ;
V_57 = V_108 ( V_107 ) ;
if ( V_57 -> type != V_111 )
continue;
V_110 = V_57 -> V_112 ;
for ( V_114 = 0 ; V_114 < 2 ; ++ V_114 ) {
struct V_79 * V_80 ;
V_80 = V_110 -> V_115 [ V_114 ] . V_80 ;
if ( V_80 && F_57 ( V_80 ) )
V_51 = - V_99 ;
}
}
return V_51 ;
}
static void F_58 ( struct V_104 * V_105 )
{
struct V_106 * V_107 ;
struct V_108 * V_57 ;
struct V_109 * V_110 ;
F_56 (list, &card->devices) {
V_57 = V_108 ( V_107 ) ;
if ( V_57 -> type != V_111 )
continue;
V_110 = V_57 -> V_112 ;
F_37 ( & V_110 -> V_113 ) ;
}
}
static int F_59 ( struct V_116 * V_100 , struct V_117 * V_117 )
{
struct V_104 * V_105 = V_100 -> V_105 ;
int V_51 = F_55 ( V_105 ) ;
if ( 0 == V_51 )
V_12 ( V_105 ) -> V_97 |= V_98 ;
F_58 ( V_105 ) ;
return V_51 ;
}
static int F_60 ( struct V_116 * V_100 , struct V_117 * V_117 )
{
struct V_104 * V_105 = V_100 -> V_105 ;
int V_51 = F_55 ( V_105 ) ;
if ( 0 == V_51 )
V_12 ( V_100 -> V_105 ) -> V_97 &= ~ V_98 ;
F_58 ( V_105 ) ;
return V_51 ;
}
static void F_61 ( struct V_118 * V_119 )
{
}
static void F_62 ( struct V_118 * V_119 )
{
}
static int F_63 ( struct V_118 * V_119 ,
struct V_120 * V_121 )
{
unsigned long V_36 ;
void * V_122 ;
V_36 = V_121 -> V_123 << V_124 ;
V_122 = ( char * ) ( (struct V_11 * ) V_119 -> V_125 ) -> V_13 + V_36 ;
V_121 -> V_126 = F_64 ( V_122 ) ;
F_65 ( V_121 -> V_126 ) ;
return 0 ;
}
static int F_66 ( struct V_116 * V_100 , struct V_117 * V_127 , struct V_118 * V_119 )
{
unsigned long V_128 = ( unsigned long ) ( V_119 -> V_129 - V_119 -> V_130 ) ;
struct V_11 * V_12 = V_100 -> V_81 ;
if ( ! ( V_12 -> V_97 & V_131 ) )
return - V_99 ;
if ( V_128 > F_67 ( sizeof( struct V_30 ) ) ) {
F_68 ( L_19 , V_128 , ( unsigned long ) sizeof( struct V_30 ) ) ;
return - V_69 ;
}
if ( ! V_12 -> V_13 ) {
return - V_132 ;
}
V_119 -> V_133 = & V_134 ;
V_119 -> V_135 |= V_136 | V_137 ;
V_119 -> V_125 = V_100 -> V_81 ;
return 0 ;
}
static void F_69 ( struct V_116 * V_138 )
{
struct V_11 * V_12 = V_138 -> V_81 ;
if ( NULL != V_12 -> V_13 )
F_70 ( V_12 -> V_13 , sizeof( struct V_30 ) ) ;
}
int F_71 ( struct V_104 * V_105 )
{
int V_51 ;
struct V_116 * V_100 ;
struct V_109 * V_110 ;
struct V_67 * V_57 = V_12 ( V_105 ) -> V_57 ;
if ( 1 != F_4 () )
return 0 ;
if ( ( V_51 = F_72 ( V_105 , V_139 , 1 , & V_100 ) ) < 0 )
return V_51 ;
V_100 -> V_140 = V_141 ;
V_100 -> V_81 = V_12 ( V_105 ) ;
V_100 -> V_142 = F_69 ;
V_100 -> V_143 . V_144 = F_59 ;
V_100 -> V_143 . V_145 = F_60 ;
V_100 -> V_143 . V_146 = F_66 ;
V_100 -> V_147 = 1 ;
sprintf ( V_100 -> V_148 , L_20 , V_57 -> V_149 -> V_150 , V_57 -> V_151 ) ;
V_51 = F_73 ( V_105 , V_152 L_21 , 2 , 1 , 1 , & V_110 ) ;
if ( V_51 < 0 ) {
return V_51 ;
}
F_74 ( V_110 , V_61 , & V_153 ) ;
F_74 ( V_110 , V_60 , & V_153 ) ;
V_110 -> V_81 = V_12 ( V_105 ) -> V_2 ;
V_110 -> V_154 = 0 ;
sprintf ( V_110 -> V_148 , V_152 L_21 ) ;
if ( 0 > ( V_51 = F_75 ( V_110 -> V_115 [ V_61 ] . V_80 ,
V_155 ,
F_76 ( V_71 ) ,
64 * 1024 , 128 * 1024 ) ) ||
0 > ( V_51 = F_75 ( V_110 -> V_115 [ V_60 ] . V_80 ,
V_155 ,
F_76 ( V_71 ) ,
64 * 1024 , 128 * 1024 ) ) ) {
return V_51 ;
}
return 0 ;
}
int F_71 ( struct V_104 * V_105 )
{
return 0 ;
}
