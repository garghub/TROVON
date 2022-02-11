struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 = F_2 ( V_4 , V_5 ) ;
if ( V_3 ) {
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_3 ( & V_3 -> V_6 ) ;
V_3 -> V_7 = V_2 ;
if ( V_2 <= F_4 ( V_3 -> V_8 ) )
V_3 -> V_9 = V_3 -> V_8 ;
else {
V_3 -> V_9 = F_5 ( V_2 , sizeof( struct V_10 * ) , V_5 ) ;
if ( ! V_3 -> V_9 ) {
F_6 ( V_3 , V_4 ) ;
V_3 = NULL ;
}
}
}
return V_3 ;
}
void F_7 ( struct V_1 * V_3 )
{
if ( V_3 && ( V_3 -> V_9 != & V_3 -> V_8 [ 0 ] ) )
F_8 ( V_3 -> V_9 ) ;
F_6 ( V_3 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_11 )
{
F_10 ( V_11 -> V_12 ) ;
F_11 ( V_11 -> args . V_13 ) ;
F_7 ( V_11 ) ;
}
static
int F_12 ( struct V_10 * V_10 )
{
F_13 ( V_10 , 0 , V_14 ) ;
F_14 ( V_10 ) ;
F_15 ( V_10 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_15 )
{
unsigned int V_16 = V_15 -> args . V_17 - V_15 -> V_18 . V_17 ;
unsigned int V_19 = V_15 -> args . V_20 + V_15 -> V_18 . V_17 ;
unsigned int V_21 ;
struct V_10 * * V_6 ;
if ( V_15 -> V_18 . V_22 == 0 || V_16 == 0 )
return;
V_6 = & V_15 -> args . V_6 [ V_19 >> V_23 ] ;
V_19 &= ~ V_24 ;
V_21 = V_14 - V_19 ;
for (; ; ) {
if ( V_16 <= V_21 ) {
F_13 ( * V_6 , V_19 , V_16 ) ;
break;
}
F_13 ( * V_6 , V_19 , V_21 ) ;
V_6 ++ ;
V_16 -= V_21 ;
V_21 = V_14 ;
V_19 = 0 ;
}
}
int F_17 ( struct V_25 * V_26 , struct V_27 * V_27 ,
struct V_10 * V_10 )
{
struct V_28 * V_29 ;
unsigned int V_30 ;
struct V_31 V_32 ;
V_30 = F_18 ( V_10 ) ;
if ( V_30 == 0 )
return F_12 ( V_10 ) ;
V_29 = F_19 ( V_26 , V_27 , V_10 , 0 , V_30 ) ;
if ( F_20 ( V_29 ) ) {
F_15 ( V_10 ) ;
return F_21 ( V_29 ) ;
}
if ( V_30 < V_14 )
F_22 ( V_10 , V_30 , V_14 ) ;
F_23 ( & V_32 , V_27 , NULL , 0 , 0 ) ;
F_24 ( V_29 , & V_32 . V_33 ) ;
V_32 . V_34 = V_30 ;
if ( F_25 ( V_27 ) -> V_35 < V_14 )
F_26 ( & V_32 ) ;
else
F_27 ( & V_32 ) ;
return 0 ;
}
static void F_28 ( struct V_28 * V_36 )
{
struct V_27 * V_37 = V_36 -> V_38 -> V_39 . V_40 -> V_37 ;
if ( F_29 ( V_36 -> V_41 ) )
F_30 ( V_37 , V_36 -> V_41 , 0 ) ;
F_15 ( V_36 -> V_41 ) ;
F_31 ( L_1 ,
V_36 -> V_38 -> V_39 . V_40 -> V_37 -> V_42 -> V_43 ,
( long long ) F_32 ( V_36 -> V_38 -> V_39 . V_40 -> V_37 ) ,
V_36 -> V_44 ,
( long long ) F_33 ( V_36 ) ) ;
F_34 ( V_36 ) ;
}
int F_35 ( struct V_1 * V_15 , struct V_45 * V_46 ,
const struct V_47 * V_48 )
{
struct V_27 * V_27 = V_15 -> V_27 ;
int V_49 = F_36 ( V_27 ) ? V_50 : 0 ;
struct V_51 * V_52 ;
struct V_53 V_54 = {
. V_55 = & V_15 -> args ,
. V_56 = & V_15 -> V_18 ,
. V_57 = V_15 -> V_58 ,
} ;
struct V_59 V_60 = {
. V_52 = & V_15 -> V_52 ,
. V_61 = V_46 ,
. V_53 = & V_54 ,
. V_62 = V_48 ,
. V_63 = V_15 ,
. V_64 = V_65 ,
. V_66 = V_67 | V_49 ,
} ;
F_37 ( V_27 ) -> F_38 ( V_15 , & V_54 ) ;
F_31 ( L_2
L_3 ,
V_15 -> V_52 . V_68 ,
V_27 -> V_42 -> V_43 ,
( long long ) F_32 ( V_27 ) ,
V_15 -> args . V_17 ,
( unsigned long long ) V_15 -> args . V_69 ) ;
V_52 = F_39 ( & V_60 ) ;
if ( F_20 ( V_52 ) )
return F_21 ( V_52 ) ;
F_40 ( V_52 ) ;
return 0 ;
}
static int F_41 ( struct V_28 * V_36 , struct V_1 * V_15 ,
const struct V_47 * V_48 ,
unsigned int V_17 , unsigned int V_69 ,
struct V_70 * V_12 )
{
struct V_27 * V_27 = V_36 -> V_38 -> V_39 . V_40 -> V_37 ;
V_15 -> V_36 = V_36 ;
V_15 -> V_27 = V_27 ;
V_15 -> V_58 = V_36 -> V_38 -> V_58 ;
V_15 -> V_12 = F_42 ( V_12 ) ;
V_15 -> args . V_71 = F_43 ( V_27 ) ;
V_15 -> args . V_69 = F_33 ( V_36 ) + V_69 ;
V_15 -> args . V_20 = V_36 -> V_72 + V_69 ;
V_15 -> args . V_6 = V_15 -> V_9 ;
V_15 -> args . V_17 = V_17 ;
V_15 -> args . V_13 = F_44 ( V_36 -> V_38 ) ;
V_15 -> args . V_73 = V_36 -> V_74 ;
V_15 -> V_18 . V_75 = & V_15 -> V_75 ;
V_15 -> V_18 . V_17 = V_17 ;
V_15 -> V_18 . V_22 = 0 ;
F_45 ( & V_15 -> V_75 ) ;
if ( V_15 -> V_12 &&
( F_46 ( V_15 , V_48 ) == V_76 ) )
return 0 ;
return F_35 ( V_15 , F_47 ( V_27 ) , V_48 ) ;
}
static void
F_48 ( struct V_77 * V_78 )
{
struct V_28 * V_36 ;
while ( ! F_49 ( V_78 ) ) {
V_36 = F_50 ( V_78 -> V_79 ) ;
F_51 ( V_36 ) ;
F_52 ( V_36 -> V_41 ) ;
F_28 ( V_36 ) ;
}
}
static int F_26 ( struct V_31 * V_80 )
{
struct V_28 * V_36 = F_50 ( V_80 -> V_33 . V_79 ) ;
struct V_10 * V_10 = V_36 -> V_41 ;
struct V_1 * V_15 ;
T_1 V_35 = F_25 ( V_80 -> V_81 ) -> V_35 , V_82 ;
unsigned int V_69 ;
int V_83 = 0 ;
int V_84 = 0 ;
struct V_70 * V_12 ;
F_53 ( V_85 ) ;
F_51 ( V_36 ) ;
V_82 = V_80 -> V_34 ;
do {
T_1 V_30 = F_54 ( V_82 , V_35 ) ;
V_15 = F_1 ( 1 ) ;
if ( ! V_15 )
goto V_86;
F_55 ( & V_15 -> V_6 , & V_85 ) ;
V_83 ++ ;
V_82 -= V_30 ;
} while( V_82 != 0 );
F_56 ( & V_36 -> V_87 , V_83 ) ;
F_57 ( V_80 -> V_88 != NULL ) ;
V_12 = F_58 ( V_80 -> V_81 , V_36 -> V_38 ,
F_33 ( V_36 ) , V_80 -> V_34 ,
V_89 , V_5 ) ;
F_59 ( V_10 ) ;
V_69 = 0 ;
V_82 = V_80 -> V_34 ;
do {
int V_90 ;
V_15 = F_60 ( V_85 . V_79 , struct V_1 , V_6 ) ;
F_61 ( & V_15 -> V_6 ) ;
V_15 -> V_9 [ 0 ] = V_10 ;
if ( V_82 < V_35 )
V_35 = V_82 ;
V_90 = F_41 ( V_36 , V_15 , & V_91 ,
V_35 , V_69 , V_12 ) ;
if ( V_84 == 0 )
V_84 = V_90 ;
V_69 += V_35 ;
V_82 -= V_35 ;
} while ( V_82 != 0 );
F_10 ( V_12 ) ;
V_80 -> V_88 = NULL ;
return V_84 ;
V_86:
while ( ! F_49 ( & V_85 ) ) {
V_15 = F_60 ( V_85 . V_79 , struct V_1 , V_6 ) ;
F_62 ( & V_15 -> V_6 ) ;
F_7 ( V_15 ) ;
}
F_52 ( V_10 ) ;
F_28 ( V_36 ) ;
return - V_92 ;
}
static int F_27 ( struct V_31 * V_80 )
{
struct V_28 * V_36 ;
struct V_10 * * V_6 ;
struct V_1 * V_15 ;
struct V_77 * V_78 = & V_80 -> V_33 ;
struct V_70 * V_12 = V_80 -> V_88 ;
int V_84 = - V_92 ;
V_15 = F_1 ( F_63 ( V_80 -> V_93 ,
V_80 -> V_34 ) ) ;
if ( ! V_15 ) {
F_48 ( V_78 ) ;
goto V_94;
}
V_6 = V_15 -> V_9 ;
while ( ! F_49 ( V_78 ) ) {
V_36 = F_50 ( V_78 -> V_79 ) ;
F_51 ( V_36 ) ;
F_24 ( V_36 , & V_15 -> V_6 ) ;
F_59 ( V_36 -> V_41 ) ;
* V_6 ++ = V_36 -> V_41 ;
}
V_36 = F_50 ( V_15 -> V_6 . V_79 ) ;
if ( ( ! V_12 ) && F_64 ( & V_15 -> V_6 ) )
V_12 = F_58 ( V_80 -> V_81 , V_36 -> V_38 ,
F_33 ( V_36 ) , V_80 -> V_34 ,
V_89 , V_5 ) ;
V_84 = F_41 ( V_36 , V_15 , & V_95 , V_80 -> V_34 ,
0 , V_12 ) ;
V_94:
F_10 ( V_12 ) ;
V_80 -> V_88 = NULL ;
return V_84 ;
}
int F_65 ( struct V_51 * V_52 , struct V_1 * V_15 )
{
int V_96 ;
F_31 ( L_4 , V_97 , V_52 -> V_68 ,
V_52 -> V_98 ) ;
V_96 = F_37 ( V_15 -> V_27 ) -> F_66 ( V_52 , V_15 ) ;
if ( V_96 != 0 )
return V_96 ;
F_67 ( V_15 -> V_27 , V_99 , V_15 -> V_18 . V_17 ) ;
if ( V_52 -> V_98 == - V_100 ) {
F_68 ( V_101 , & F_69 ( V_15 -> V_27 ) -> V_66 ) ;
F_70 ( V_15 -> V_27 ) ;
}
return 0 ;
}
static void F_71 ( struct V_51 * V_52 , struct V_1 * V_15 )
{
struct V_102 * V_103 = & V_15 -> args ;
struct V_104 * V_105 = & V_15 -> V_18 ;
if ( V_105 -> V_22 || V_105 -> V_17 == V_103 -> V_17 )
return;
F_72 ( V_15 -> V_27 , V_106 ) ;
if ( V_105 -> V_17 == 0 )
return;
V_15 -> V_107 += V_105 -> V_17 ;
V_103 -> V_69 += V_105 -> V_17 ;
V_103 -> V_20 += V_105 -> V_17 ;
V_103 -> V_17 -= V_105 -> V_17 ;
F_73 ( V_52 , F_25 ( V_15 -> V_27 ) -> V_108 ) ;
}
static void F_74 ( struct V_51 * V_52 , void * V_109 )
{
struct V_1 * V_15 = V_109 ;
if ( F_65 ( V_52 , V_15 ) != 0 )
return;
if ( V_52 -> V_98 < 0 )
return;
F_16 ( V_15 ) ;
F_71 ( V_52 , V_15 ) ;
}
static void F_75 ( void * V_109 )
{
struct V_1 * V_15 = V_109 ;
struct V_28 * V_36 = V_15 -> V_36 ;
struct V_10 * V_10 = V_36 -> V_41 ;
int V_96 = V_15 -> V_52 . V_98 ;
if ( V_96 < 0 )
F_52 ( V_10 ) ;
if ( F_76 ( & V_36 -> V_87 ) ) {
if ( ! F_77 ( V_10 ) )
F_14 ( V_10 ) ;
F_28 ( V_36 ) ;
}
F_9 ( V_109 ) ;
}
void F_78 ( struct V_51 * V_52 , void * V_109 )
{
struct V_1 * V_15 = V_109 ;
if ( F_79 ( F_25 ( V_15 -> V_27 ) ,
& V_15 -> args . V_110 , & V_15 -> V_18 . V_111 ,
0 , V_52 ) )
return;
F_80 ( V_52 ) ;
}
static void F_81 ( struct V_1 * V_15 )
{
unsigned int V_17 = V_15 -> V_18 . V_17 ;
unsigned int V_19 = V_15 -> args . V_20 ;
struct V_10 * * V_6 ;
if ( V_15 -> V_18 . V_22 )
V_17 = V_15 -> args . V_17 ;
if ( F_82 ( V_17 == 0 ) )
return;
V_6 = & V_15 -> args . V_6 [ V_19 >> V_23 ] ;
V_19 &= ~ V_24 ;
V_17 += V_19 ;
for (; V_17 >= V_14 ; V_17 -= V_14 , V_6 ++ )
F_14 ( * V_6 ) ;
if ( V_17 == 0 )
return;
if ( V_15 -> V_18 . V_22 || V_15 -> V_18 . V_17 == V_15 -> args . V_17 )
F_14 ( * V_6 ) ;
}
static void F_83 ( struct V_51 * V_52 , void * V_109 )
{
struct V_1 * V_15 = V_109 ;
if ( F_65 ( V_52 , V_15 ) != 0 )
return;
if ( V_52 -> V_98 < 0 )
return;
F_16 ( V_15 ) ;
F_81 ( V_15 ) ;
F_71 ( V_52 , V_15 ) ;
}
static void F_84 ( void * V_109 )
{
struct V_1 * V_15 = V_109 ;
while ( ! F_49 ( & V_15 -> V_6 ) ) {
struct V_28 * V_36 = F_50 ( V_15 -> V_6 . V_79 ) ;
F_51 ( V_36 ) ;
F_28 ( V_36 ) ;
}
F_9 ( V_109 ) ;
}
int F_85 ( struct V_112 * V_112 , struct V_10 * V_10 )
{
struct V_25 * V_26 ;
struct V_27 * V_27 = V_10 -> V_113 -> V_114 ;
int error ;
F_31 ( L_5 ,
V_10 , V_14 , V_10 -> V_115 ) ;
F_72 ( V_27 , V_116 ) ;
F_67 ( V_27 , V_117 , 1 ) ;
error = F_86 ( V_27 , V_10 ) ;
if ( error )
goto V_118;
if ( F_29 ( V_10 ) )
goto V_118;
error = - V_100 ;
if ( F_87 ( V_27 ) )
goto V_118;
if ( V_112 == NULL ) {
error = - V_119 ;
V_26 = F_88 ( V_27 , NULL , V_120 ) ;
if ( V_26 == NULL )
goto V_118;
} else
V_26 = F_44 ( F_89 ( V_112 ) ) ;
if ( ! F_90 ( V_27 ) ) {
error = F_91 ( V_26 , V_27 , V_10 ) ;
if ( error == 0 )
goto V_94;
}
error = F_17 ( V_26 , V_27 , V_10 ) ;
V_94:
F_11 ( V_26 ) ;
return error ;
V_118:
F_15 ( V_10 ) ;
return error ;
}
static int
F_92 ( void * V_15 , struct V_10 * V_10 )
{
struct V_121 * V_80 = (struct V_121 * ) V_15 ;
struct V_27 * V_27 = V_10 -> V_113 -> V_114 ;
struct V_28 * V_29 ;
unsigned int V_30 ;
int error ;
V_30 = F_18 ( V_10 ) ;
if ( V_30 == 0 )
return F_12 ( V_10 ) ;
V_29 = F_19 ( V_80 -> V_26 , V_27 , V_10 , 0 , V_30 ) ;
if ( F_20 ( V_29 ) )
goto V_122;
if ( V_30 < V_14 )
F_22 ( V_10 , V_30 , V_14 ) ;
if ( ! F_93 ( V_80 -> V_32 , V_29 ) ) {
error = V_80 -> V_32 -> V_123 ;
goto V_118;
}
return 0 ;
V_122:
error = F_21 ( V_29 ) ;
F_52 ( V_10 ) ;
V_118:
F_15 ( V_10 ) ;
return error ;
}
int F_94 ( struct V_112 * V_124 , struct V_125 * V_113 ,
struct V_77 * V_6 , unsigned V_126 )
{
struct V_31 V_32 ;
struct V_121 V_80 = {
. V_32 = & V_32 ,
} ;
struct V_27 * V_27 = V_113 -> V_114 ;
struct V_127 * V_128 = F_25 ( V_27 ) ;
T_1 V_35 = V_128 -> V_35 ;
unsigned long V_7 ;
int V_84 = - V_100 ;
F_31 ( L_6 ,
V_27 -> V_42 -> V_43 ,
( long long ) F_32 ( V_27 ) ,
V_126 ) ;
F_72 ( V_27 , V_129 ) ;
if ( F_87 ( V_27 ) )
goto V_94;
if ( V_124 == NULL ) {
V_80 . V_26 = F_88 ( V_27 , NULL , V_120 ) ;
if ( V_80 . V_26 == NULL )
return - V_119 ;
} else
V_80 . V_26 = F_44 ( F_89 ( V_124 ) ) ;
V_84 = F_95 ( V_80 . V_26 , V_27 , V_113 ,
V_6 , & V_126 ) ;
if ( V_84 == 0 )
goto V_130;
if ( V_35 < V_14 )
F_23 ( & V_32 , V_27 , F_26 , V_35 , 0 ) ;
else
F_23 ( & V_32 , V_27 , F_27 , V_35 , 0 ) ;
V_84 = F_96 ( V_113 , V_6 , F_92 , & V_80 ) ;
F_97 ( & V_32 ) ;
V_7 = ( V_32 . V_131 + V_14 - 1 ) >> V_23 ;
F_67 ( V_27 , V_117 , V_7 ) ;
V_130:
F_11 ( V_80 . V_26 ) ;
V_94:
return V_84 ;
}
int T_2 F_98 ( void )
{
V_132 = F_99 ( L_7 ,
sizeof( struct V_1 ) ,
0 , V_133 ,
NULL ) ;
if ( V_132 == NULL )
return - V_92 ;
V_4 = F_100 ( V_134 ,
V_132 ) ;
if ( V_4 == NULL )
return - V_92 ;
return 0 ;
}
void F_101 ( void )
{
F_102 ( V_4 ) ;
F_103 ( V_132 ) ;
}
