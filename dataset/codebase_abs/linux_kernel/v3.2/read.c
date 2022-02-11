struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_4 , V_5 ) ;
if ( V_3 ) {
F_3 ( & V_3 -> V_6 ) ;
V_3 -> V_7 = V_2 ;
if ( V_2 <= F_4 ( V_3 -> V_8 ) )
V_3 -> V_9 = V_3 -> V_8 ;
else {
V_3 -> V_9 = F_5 ( V_2 , sizeof( struct V_10 * ) , V_5 ) ;
if ( ! V_3 -> V_9 ) {
F_6 ( V_4 , V_3 ) ;
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
F_6 ( V_4 , V_3 ) ;
}
void F_9 ( struct V_1 * V_11 )
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
void F_17 ( struct V_25 * V_26 ,
struct V_27 * V_27 )
{
F_18 ( V_26 , V_27 , & V_28 ,
F_19 ( V_27 ) -> V_29 , 0 ) ;
}
void F_20 ( struct V_25 * V_26 )
{
V_26 -> V_30 = & V_28 ;
V_26 -> V_31 = F_19 ( V_26 -> V_32 ) -> V_29 ;
}
static void F_21 ( struct V_25 * V_26 ,
struct V_27 * V_27 )
{
if ( ! F_22 ( V_26 , V_27 ) )
F_17 ( V_26 , V_27 ) ;
}
int F_23 ( struct V_33 * V_34 , struct V_27 * V_27 ,
struct V_10 * V_10 )
{
struct V_35 * V_36 ;
unsigned int V_37 ;
struct V_25 V_26 ;
V_37 = F_24 ( V_10 ) ;
if ( V_37 == 0 )
return F_12 ( V_10 ) ;
V_36 = F_25 ( V_34 , V_27 , V_10 , 0 , V_37 ) ;
if ( F_26 ( V_36 ) ) {
F_15 ( V_10 ) ;
return F_27 ( V_36 ) ;
}
if ( V_37 < V_14 )
F_28 ( V_10 , V_37 , V_14 ) ;
F_21 ( & V_26 , V_27 ) ;
F_29 ( & V_26 , V_36 ) ;
F_30 ( & V_26 ) ;
return 0 ;
}
static void F_31 ( struct V_35 * V_38 )
{
struct V_27 * V_39 = V_38 -> V_40 -> V_41 -> V_39 ;
if ( F_32 ( V_38 -> V_42 ) )
F_33 ( V_39 , V_38 -> V_42 , 0 ) ;
F_15 ( V_38 -> V_42 ) ;
F_34 ( L_1 ,
V_38 -> V_40 -> V_41 -> V_39 -> V_43 -> V_44 ,
( long long ) F_35 ( V_38 -> V_40 -> V_41 -> V_39 ) ,
V_38 -> V_45 ,
( long long ) F_36 ( V_38 ) ) ;
F_37 ( V_38 ) ;
}
int F_38 ( struct V_1 * V_15 , struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_27 * V_27 = V_15 -> V_27 ;
int V_50 = F_39 ( V_27 ) ? V_51 : 0 ;
struct V_52 * V_53 ;
struct V_54 V_55 = {
. V_56 = & V_15 -> args ,
. V_57 = & V_15 -> V_18 ,
. V_58 = V_15 -> V_59 ,
} ;
struct V_60 V_61 = {
. V_53 = & V_15 -> V_53 ,
. V_62 = V_47 ,
. V_54 = & V_55 ,
. V_63 = V_49 ,
. V_64 = V_15 ,
. V_65 = V_66 ,
. V_67 = V_68 | V_50 ,
} ;
F_40 ( V_27 ) -> F_41 ( V_15 , & V_55 ) ;
F_34 ( L_2
L_3 ,
V_15 -> V_53 . V_69 ,
V_27 -> V_43 -> V_44 ,
( long long ) F_35 ( V_27 ) ,
V_15 -> args . V_17 ,
( unsigned long long ) V_15 -> args . V_70 ) ;
V_53 = F_42 ( & V_61 ) ;
if ( F_26 ( V_53 ) )
return F_27 ( V_53 ) ;
F_43 ( V_53 ) ;
return 0 ;
}
static void F_44 ( struct V_35 * V_38 , struct V_1 * V_15 ,
unsigned int V_17 , unsigned int V_70 )
{
struct V_27 * V_27 = V_38 -> V_40 -> V_41 -> V_39 ;
V_15 -> V_38 = V_38 ;
V_15 -> V_27 = V_27 ;
V_15 -> V_59 = V_38 -> V_40 -> V_59 ;
V_15 -> args . V_71 = F_45 ( V_27 ) ;
V_15 -> args . V_70 = F_36 ( V_38 ) + V_70 ;
V_15 -> args . V_20 = V_38 -> V_72 + V_70 ;
V_15 -> args . V_6 = V_15 -> V_9 ;
V_15 -> args . V_17 = V_17 ;
V_15 -> args . V_13 = F_46 ( V_38 -> V_40 ) ;
V_15 -> args . V_73 = V_38 -> V_74 ;
V_15 -> V_18 . V_75 = & V_15 -> V_75 ;
V_15 -> V_18 . V_17 = V_17 ;
V_15 -> V_18 . V_22 = 0 ;
F_47 ( & V_15 -> V_75 ) ;
}
static int F_48 ( struct V_1 * V_15 ,
const struct V_48 * V_49 )
{
struct V_27 * V_27 = V_15 -> args . V_13 -> V_41 -> V_39 ;
return F_38 ( V_15 , F_49 ( V_27 ) , V_49 ) ;
}
static int
F_50 ( struct V_76 * V_77 ,
const struct V_48 * V_49 )
{
struct V_1 * V_15 ;
int V_78 = 0 ;
while ( ! F_51 ( V_77 ) ) {
int V_79 ;
V_15 = F_52 ( V_77 -> V_80 , struct V_1 , V_81 ) ;
F_53 ( & V_15 -> V_81 ) ;
V_79 = F_48 ( V_15 , V_49 ) ;
if ( V_78 == 0 )
V_78 = V_79 ;
}
return V_78 ;
}
static void
F_54 ( struct V_76 * V_77 )
{
struct V_35 * V_38 ;
while ( ! F_51 ( V_77 ) ) {
V_38 = F_55 ( V_77 -> V_80 ) ;
F_56 ( V_38 ) ;
F_31 ( V_38 ) ;
}
}
static int F_57 ( struct V_25 * V_82 , struct V_76 * V_18 )
{
struct V_35 * V_38 = F_55 ( V_82 -> V_83 . V_80 ) ;
struct V_10 * V_10 = V_38 -> V_42 ;
struct V_1 * V_15 ;
T_1 V_29 = V_82 -> V_31 , V_84 ;
unsigned int V_70 ;
int V_85 = 0 ;
int V_78 = 0 ;
F_56 ( V_38 ) ;
V_70 = 0 ;
V_84 = V_82 -> V_86 ;
do {
T_1 V_37 = F_58 ( V_84 , V_29 ) ;
V_15 = F_1 ( 1 ) ;
if ( ! V_15 )
goto V_87;
V_15 -> V_9 [ 0 ] = V_10 ;
F_44 ( V_38 , V_15 , V_37 , V_70 ) ;
F_59 ( & V_15 -> V_81 , V_18 ) ;
V_85 ++ ;
V_84 -= V_37 ;
V_70 += V_37 ;
} while( V_84 != 0 );
F_60 ( & V_38 -> V_88 , V_85 ) ;
V_82 -> V_89 = & V_90 ;
return V_78 ;
V_87:
while ( ! F_51 ( V_18 ) ) {
V_15 = F_52 ( V_18 -> V_80 , struct V_1 , V_81 ) ;
F_61 ( & V_15 -> V_81 ) ;
F_7 ( V_15 ) ;
}
F_31 ( V_38 ) ;
return - V_91 ;
}
static int F_62 ( struct V_25 * V_82 , struct V_76 * V_18 )
{
struct V_35 * V_38 ;
struct V_10 * * V_6 ;
struct V_1 * V_15 ;
struct V_76 * V_77 = & V_82 -> V_83 ;
int V_78 = 0 ;
V_15 = F_1 ( F_63 ( V_82 -> V_92 ,
V_82 -> V_86 ) ) ;
if ( ! V_15 ) {
F_54 ( V_77 ) ;
V_78 = - V_91 ;
goto V_93;
}
V_6 = V_15 -> V_9 ;
while ( ! F_51 ( V_77 ) ) {
V_38 = F_55 ( V_77 -> V_80 ) ;
F_56 ( V_38 ) ;
F_64 ( V_38 , & V_15 -> V_6 ) ;
* V_6 ++ = V_38 -> V_42 ;
}
V_38 = F_55 ( V_15 -> V_6 . V_80 ) ;
F_44 ( V_38 , V_15 , V_82 -> V_86 , 0 ) ;
F_59 ( & V_15 -> V_81 , V_18 ) ;
V_82 -> V_89 = & V_94 ;
V_93:
return V_78 ;
}
int F_65 ( struct V_25 * V_82 , struct V_76 * V_77 )
{
if ( V_82 -> V_31 < V_14 )
return F_57 ( V_82 , V_77 ) ;
return F_62 ( V_82 , V_77 ) ;
}
static int F_66 ( struct V_25 * V_82 )
{
F_67 ( V_77 ) ;
int V_78 ;
V_78 = F_65 ( V_82 , & V_77 ) ;
if ( V_78 == 0 )
V_78 = F_50 ( & V_77 , V_82 -> V_89 ) ;
return V_78 ;
}
int F_68 ( struct V_52 * V_53 , struct V_1 * V_15 )
{
int V_95 ;
F_34 ( L_4 , V_96 , V_53 -> V_69 ,
V_53 -> V_97 ) ;
V_95 = F_40 ( V_15 -> V_27 ) -> F_69 ( V_53 , V_15 ) ;
if ( V_95 != 0 )
return V_95 ;
F_70 ( V_15 -> V_27 , V_98 , V_15 -> V_18 . V_17 ) ;
if ( V_53 -> V_97 == - V_99 ) {
F_71 ( V_100 , & F_72 ( V_15 -> V_27 ) -> V_67 ) ;
F_73 ( V_15 -> V_27 ) ;
}
return 0 ;
}
static void F_74 ( struct V_52 * V_53 , struct V_1 * V_15 )
{
struct V_101 * V_102 = & V_15 -> args ;
struct V_103 * V_104 = & V_15 -> V_18 ;
if ( V_104 -> V_22 || V_104 -> V_17 == V_102 -> V_17 )
return;
F_75 ( V_15 -> V_27 , V_105 ) ;
if ( V_104 -> V_17 == 0 )
return;
V_15 -> V_106 += V_104 -> V_17 ;
V_102 -> V_70 += V_104 -> V_17 ;
V_102 -> V_20 += V_104 -> V_17 ;
V_102 -> V_17 -= V_104 -> V_17 ;
F_76 ( V_53 ) ;
}
static void F_77 ( struct V_52 * V_53 , void * V_107 )
{
struct V_1 * V_15 = V_107 ;
if ( F_68 ( V_53 , V_15 ) != 0 )
return;
if ( V_53 -> V_97 < 0 )
return;
F_16 ( V_15 ) ;
F_74 ( V_53 , V_15 ) ;
}
static void F_78 ( void * V_107 )
{
struct V_1 * V_15 = V_107 ;
struct V_35 * V_38 = V_15 -> V_38 ;
struct V_10 * V_10 = V_38 -> V_42 ;
int V_95 = V_15 -> V_53 . V_97 ;
if ( V_95 < 0 )
F_71 ( V_108 , & V_38 -> V_109 ) ;
if ( F_79 ( & V_38 -> V_88 ) ) {
if ( ! F_80 ( V_108 , & V_38 -> V_109 ) )
F_14 ( V_10 ) ;
F_31 ( V_38 ) ;
}
F_9 ( V_107 ) ;
}
void F_81 ( struct V_52 * V_53 , void * V_107 )
{
struct V_1 * V_15 = V_107 ;
if ( F_82 ( F_19 ( V_15 -> V_27 ) ,
& V_15 -> args . V_110 , & V_15 -> V_18 . V_111 ,
0 , V_53 ) )
return;
F_83 ( V_53 ) ;
}
static void F_84 ( struct V_1 * V_15 )
{
unsigned int V_17 = V_15 -> V_18 . V_17 ;
unsigned int V_19 = V_15 -> args . V_20 ;
struct V_10 * * V_6 ;
if ( V_15 -> V_18 . V_22 )
V_17 = V_15 -> args . V_17 ;
if ( F_85 ( V_17 == 0 ) )
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
static void F_86 ( struct V_52 * V_53 , void * V_107 )
{
struct V_1 * V_15 = V_107 ;
if ( F_68 ( V_53 , V_15 ) != 0 )
return;
if ( V_53 -> V_97 < 0 )
return;
F_16 ( V_15 ) ;
F_84 ( V_15 ) ;
F_74 ( V_53 , V_15 ) ;
}
static void F_87 ( void * V_107 )
{
struct V_1 * V_15 = V_107 ;
while ( ! F_51 ( & V_15 -> V_6 ) ) {
struct V_35 * V_38 = F_55 ( V_15 -> V_6 . V_80 ) ;
F_56 ( V_38 ) ;
F_31 ( V_38 ) ;
}
F_9 ( V_107 ) ;
}
int F_88 ( struct V_112 * V_112 , struct V_10 * V_10 )
{
struct V_33 * V_34 ;
struct V_27 * V_27 = V_10 -> V_113 -> V_114 ;
int error ;
F_34 ( L_5 ,
V_10 , V_14 , V_10 -> V_115 ) ;
F_75 ( V_27 , V_116 ) ;
F_70 ( V_27 , V_117 , 1 ) ;
error = F_89 ( V_27 , V_10 ) ;
if ( error )
goto V_118;
if ( F_32 ( V_10 ) )
goto V_118;
error = - V_99 ;
if ( F_90 ( V_27 ) )
goto V_118;
if ( V_112 == NULL ) {
error = - V_119 ;
V_34 = F_91 ( V_27 , NULL , V_120 ) ;
if ( V_34 == NULL )
goto V_118;
} else
V_34 = F_46 ( F_92 ( V_112 ) ) ;
if ( ! F_93 ( V_27 ) ) {
error = F_94 ( V_34 , V_27 , V_10 ) ;
if ( error == 0 )
goto V_93;
}
error = F_23 ( V_34 , V_27 , V_10 ) ;
V_93:
F_11 ( V_34 ) ;
return error ;
V_118:
F_15 ( V_10 ) ;
return error ;
}
static int
F_95 ( void * V_15 , struct V_10 * V_10 )
{
struct V_121 * V_82 = (struct V_121 * ) V_15 ;
struct V_27 * V_27 = V_10 -> V_113 -> V_114 ;
struct V_35 * V_36 ;
unsigned int V_37 ;
int error ;
V_37 = F_24 ( V_10 ) ;
if ( V_37 == 0 )
return F_12 ( V_10 ) ;
V_36 = F_25 ( V_82 -> V_34 , V_27 , V_10 , 0 , V_37 ) ;
if ( F_26 ( V_36 ) )
goto V_122;
if ( V_37 < V_14 )
F_28 ( V_10 , V_37 , V_14 ) ;
if ( ! F_29 ( V_82 -> V_26 , V_36 ) ) {
error = V_82 -> V_26 -> V_123 ;
goto V_118;
}
return 0 ;
V_122:
error = F_27 ( V_36 ) ;
V_118:
F_15 ( V_10 ) ;
return error ;
}
int F_96 ( struct V_112 * V_124 , struct V_125 * V_113 ,
struct V_76 * V_6 , unsigned V_126 )
{
struct V_25 V_26 ;
struct V_121 V_82 = {
. V_26 = & V_26 ,
} ;
struct V_27 * V_27 = V_113 -> V_114 ;
unsigned long V_7 ;
int V_78 = - V_99 ;
F_34 ( L_6 ,
V_27 -> V_43 -> V_44 ,
( long long ) F_35 ( V_27 ) ,
V_126 ) ;
F_75 ( V_27 , V_127 ) ;
if ( F_90 ( V_27 ) )
goto V_93;
if ( V_124 == NULL ) {
V_82 . V_34 = F_91 ( V_27 , NULL , V_120 ) ;
if ( V_82 . V_34 == NULL )
return - V_119 ;
} else
V_82 . V_34 = F_46 ( F_92 ( V_124 ) ) ;
V_78 = F_97 ( V_82 . V_34 , V_27 , V_113 ,
V_6 , & V_126 ) ;
if ( V_78 == 0 )
goto V_128;
F_21 ( & V_26 , V_27 ) ;
V_78 = F_98 ( V_113 , V_6 , F_95 , & V_82 ) ;
F_30 ( & V_26 ) ;
V_7 = ( V_26 . V_129 + V_14 - 1 ) >> V_23 ;
F_70 ( V_27 , V_117 , V_7 ) ;
V_128:
F_11 ( V_82 . V_34 ) ;
V_93:
return V_78 ;
}
int T_2 F_99 ( void )
{
V_4 = F_100 ( L_7 ,
sizeof( struct V_1 ) ,
0 , V_130 ,
NULL ) ;
if ( V_4 == NULL )
return - V_91 ;
return 0 ;
}
void F_101 ( void )
{
F_102 ( V_4 ) ;
}
