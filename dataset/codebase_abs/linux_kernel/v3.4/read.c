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
F_10 ( V_11 -> args . V_12 ) ;
F_7 ( V_11 ) ;
}
static
int F_11 ( struct V_10 * V_10 )
{
F_12 ( V_10 , 0 , V_13 ) ;
F_13 ( V_10 ) ;
F_14 ( V_10 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_14 )
{
unsigned int V_15 = V_14 -> args . V_16 - V_14 -> V_17 . V_16 ;
unsigned int V_18 = V_14 -> args . V_19 + V_14 -> V_17 . V_16 ;
unsigned int V_20 ;
struct V_10 * * V_6 ;
if ( V_14 -> V_17 . V_21 == 0 || V_15 == 0 )
return;
V_6 = & V_14 -> args . V_6 [ V_18 >> V_22 ] ;
V_18 &= ~ V_23 ;
V_20 = V_13 - V_18 ;
for (; ; ) {
if ( V_15 <= V_20 ) {
F_12 ( * V_6 , V_18 , V_15 ) ;
break;
}
F_12 ( * V_6 , V_18 , V_20 ) ;
V_6 ++ ;
V_15 -= V_20 ;
V_20 = V_13 ;
V_18 = 0 ;
}
}
void F_16 ( struct V_24 * V_25 ,
struct V_26 * V_26 )
{
F_17 ( V_25 , V_26 , & V_27 ,
F_18 ( V_26 ) -> V_28 , 0 ) ;
}
void F_19 ( struct V_24 * V_25 )
{
V_25 -> V_29 = & V_27 ;
V_25 -> V_30 = F_18 ( V_25 -> V_31 ) -> V_28 ;
}
static void F_20 ( struct V_24 * V_25 ,
struct V_26 * V_26 )
{
if ( ! F_21 ( V_25 , V_26 ) )
F_16 ( V_25 , V_26 ) ;
}
int F_22 ( struct V_32 * V_33 , struct V_26 * V_26 ,
struct V_10 * V_10 )
{
struct V_34 * V_35 ;
unsigned int V_36 ;
struct V_24 V_25 ;
V_36 = F_23 ( V_10 ) ;
if ( V_36 == 0 )
return F_11 ( V_10 ) ;
V_35 = F_24 ( V_33 , V_26 , V_10 , 0 , V_36 ) ;
if ( F_25 ( V_35 ) ) {
F_14 ( V_10 ) ;
return F_26 ( V_35 ) ;
}
if ( V_36 < V_13 )
F_27 ( V_10 , V_36 , V_13 ) ;
F_20 ( & V_25 , V_26 ) ;
F_28 ( & V_25 , V_35 ) ;
F_29 ( & V_25 ) ;
return 0 ;
}
static void F_30 ( struct V_34 * V_37 )
{
struct V_26 * V_38 = V_37 -> V_39 -> V_40 -> V_38 ;
if ( F_31 ( V_37 -> V_41 ) )
F_32 ( V_38 , V_37 -> V_41 , 0 ) ;
F_14 ( V_37 -> V_41 ) ;
F_33 ( L_1 ,
V_37 -> V_39 -> V_40 -> V_38 -> V_42 -> V_43 ,
( long long ) F_34 ( V_37 -> V_39 -> V_40 -> V_38 ) ,
V_37 -> V_44 ,
( long long ) F_35 ( V_37 ) ) ;
F_36 ( V_37 ) ;
}
int F_37 ( struct V_1 * V_14 , struct V_45 * V_46 ,
const struct V_47 * V_48 )
{
struct V_26 * V_26 = V_14 -> V_26 ;
int V_49 = F_38 ( V_26 ) ? V_50 : 0 ;
struct V_51 * V_52 ;
struct V_53 V_54 = {
. V_55 = & V_14 -> args ,
. V_56 = & V_14 -> V_17 ,
. V_57 = V_14 -> V_58 ,
} ;
struct V_59 V_60 = {
. V_52 = & V_14 -> V_52 ,
. V_61 = V_46 ,
. V_53 = & V_54 ,
. V_62 = V_48 ,
. V_63 = V_14 ,
. V_64 = V_65 ,
. V_66 = V_67 | V_49 ,
} ;
F_39 ( V_26 ) -> F_40 ( V_14 , & V_54 ) ;
F_33 ( L_2
L_3 ,
V_14 -> V_52 . V_68 ,
V_26 -> V_42 -> V_43 ,
( long long ) F_34 ( V_26 ) ,
V_14 -> args . V_16 ,
( unsigned long long ) V_14 -> args . V_69 ) ;
V_52 = F_41 ( & V_60 ) ;
if ( F_25 ( V_52 ) )
return F_26 ( V_52 ) ;
F_42 ( V_52 ) ;
return 0 ;
}
static void F_43 ( struct V_34 * V_37 , struct V_1 * V_14 ,
unsigned int V_16 , unsigned int V_69 )
{
struct V_26 * V_26 = V_37 -> V_39 -> V_40 -> V_38 ;
V_14 -> V_37 = V_37 ;
V_14 -> V_26 = V_26 ;
V_14 -> V_58 = V_37 -> V_39 -> V_58 ;
V_14 -> args . V_70 = F_44 ( V_26 ) ;
V_14 -> args . V_69 = F_35 ( V_37 ) + V_69 ;
V_14 -> args . V_19 = V_37 -> V_71 + V_69 ;
V_14 -> args . V_6 = V_14 -> V_9 ;
V_14 -> args . V_16 = V_16 ;
V_14 -> args . V_12 = F_45 ( V_37 -> V_39 ) ;
V_14 -> args . V_72 = V_37 -> V_73 ;
V_14 -> V_17 . V_74 = & V_14 -> V_74 ;
V_14 -> V_17 . V_16 = V_16 ;
V_14 -> V_17 . V_21 = 0 ;
F_46 ( & V_14 -> V_74 ) ;
}
static int F_47 ( struct V_1 * V_14 ,
const struct V_47 * V_48 )
{
struct V_26 * V_26 = V_14 -> args . V_12 -> V_40 -> V_38 ;
return F_37 ( V_14 , F_48 ( V_26 ) , V_48 ) ;
}
static int
F_49 ( struct V_75 * V_76 ,
const struct V_47 * V_48 )
{
struct V_1 * V_14 ;
int V_77 = 0 ;
while ( ! F_50 ( V_76 ) ) {
int V_78 ;
V_14 = F_51 ( V_76 -> V_79 , struct V_1 , V_80 ) ;
F_52 ( & V_14 -> V_80 ) ;
V_78 = F_47 ( V_14 , V_48 ) ;
if ( V_77 == 0 )
V_77 = V_78 ;
}
return V_77 ;
}
static void
F_53 ( struct V_75 * V_76 )
{
struct V_34 * V_37 ;
while ( ! F_50 ( V_76 ) ) {
V_37 = F_54 ( V_76 -> V_79 ) ;
F_55 ( V_37 ) ;
F_30 ( V_37 ) ;
}
}
static int F_56 ( struct V_24 * V_81 , struct V_75 * V_17 )
{
struct V_34 * V_37 = F_54 ( V_81 -> V_82 . V_79 ) ;
struct V_10 * V_10 = V_37 -> V_41 ;
struct V_1 * V_14 ;
T_1 V_28 = V_81 -> V_30 , V_83 ;
unsigned int V_69 ;
int V_84 = 0 ;
int V_77 = 0 ;
F_55 ( V_37 ) ;
V_69 = 0 ;
V_83 = V_81 -> V_85 ;
do {
T_1 V_36 = F_57 ( V_83 , V_28 ) ;
V_14 = F_1 ( 1 ) ;
if ( ! V_14 )
goto V_86;
V_14 -> V_9 [ 0 ] = V_10 ;
F_43 ( V_37 , V_14 , V_36 , V_69 ) ;
F_58 ( & V_14 -> V_80 , V_17 ) ;
V_84 ++ ;
V_83 -= V_36 ;
V_69 += V_36 ;
} while( V_83 != 0 );
F_59 ( & V_37 -> V_87 , V_84 ) ;
V_81 -> V_88 = & V_89 ;
return V_77 ;
V_86:
while ( ! F_50 ( V_17 ) ) {
V_14 = F_51 ( V_17 -> V_79 , struct V_1 , V_80 ) ;
F_60 ( & V_14 -> V_80 ) ;
F_9 ( V_14 ) ;
}
F_30 ( V_37 ) ;
return - V_90 ;
}
static int F_61 ( struct V_24 * V_81 , struct V_75 * V_17 )
{
struct V_34 * V_37 ;
struct V_10 * * V_6 ;
struct V_1 * V_14 ;
struct V_75 * V_76 = & V_81 -> V_82 ;
int V_77 = 0 ;
V_14 = F_1 ( F_62 ( V_81 -> V_91 ,
V_81 -> V_85 ) ) ;
if ( ! V_14 ) {
F_53 ( V_76 ) ;
V_77 = - V_90 ;
goto V_92;
}
V_6 = V_14 -> V_9 ;
while ( ! F_50 ( V_76 ) ) {
V_37 = F_54 ( V_76 -> V_79 ) ;
F_55 ( V_37 ) ;
F_63 ( V_37 , & V_14 -> V_6 ) ;
* V_6 ++ = V_37 -> V_41 ;
}
V_37 = F_54 ( V_14 -> V_6 . V_79 ) ;
F_43 ( V_37 , V_14 , V_81 -> V_85 , 0 ) ;
F_58 ( & V_14 -> V_80 , V_17 ) ;
V_81 -> V_88 = & V_93 ;
V_92:
return V_77 ;
}
int F_64 ( struct V_24 * V_81 , struct V_75 * V_76 )
{
if ( V_81 -> V_30 < V_13 )
return F_56 ( V_81 , V_76 ) ;
return F_61 ( V_81 , V_76 ) ;
}
static int F_65 ( struct V_24 * V_81 )
{
F_66 ( V_76 ) ;
int V_77 ;
V_77 = F_64 ( V_81 , & V_76 ) ;
if ( V_77 == 0 )
V_77 = F_49 ( & V_76 , V_81 -> V_88 ) ;
return V_77 ;
}
int F_67 ( struct V_51 * V_52 , struct V_1 * V_14 )
{
int V_94 ;
F_33 ( L_4 , V_95 , V_52 -> V_68 ,
V_52 -> V_96 ) ;
V_94 = F_39 ( V_14 -> V_26 ) -> F_68 ( V_52 , V_14 ) ;
if ( V_94 != 0 )
return V_94 ;
F_69 ( V_14 -> V_26 , V_97 , V_14 -> V_17 . V_16 ) ;
if ( V_52 -> V_96 == - V_98 ) {
F_70 ( V_99 , & F_71 ( V_14 -> V_26 ) -> V_66 ) ;
F_72 ( V_14 -> V_26 ) ;
}
return 0 ;
}
static void F_73 ( struct V_51 * V_52 , struct V_1 * V_14 )
{
struct V_100 * V_101 = & V_14 -> args ;
struct V_102 * V_103 = & V_14 -> V_17 ;
if ( V_103 -> V_21 || V_103 -> V_16 == V_101 -> V_16 )
return;
F_74 ( V_14 -> V_26 , V_104 ) ;
if ( V_103 -> V_16 == 0 )
return;
V_14 -> V_105 += V_103 -> V_16 ;
V_101 -> V_69 += V_103 -> V_16 ;
V_101 -> V_19 += V_103 -> V_16 ;
V_101 -> V_16 -= V_103 -> V_16 ;
F_75 ( V_52 ) ;
}
static void F_76 ( struct V_51 * V_52 , void * V_106 )
{
struct V_1 * V_14 = V_106 ;
if ( F_67 ( V_52 , V_14 ) != 0 )
return;
if ( V_52 -> V_96 < 0 )
return;
F_15 ( V_14 ) ;
F_73 ( V_52 , V_14 ) ;
}
static void F_77 ( void * V_106 )
{
struct V_1 * V_14 = V_106 ;
struct V_34 * V_37 = V_14 -> V_37 ;
struct V_10 * V_10 = V_37 -> V_41 ;
int V_94 = V_14 -> V_52 . V_96 ;
if ( V_94 < 0 )
F_70 ( V_107 , & V_37 -> V_108 ) ;
if ( F_78 ( & V_37 -> V_87 ) ) {
if ( ! F_79 ( V_107 , & V_37 -> V_108 ) )
F_13 ( V_10 ) ;
F_30 ( V_37 ) ;
}
F_9 ( V_106 ) ;
}
void F_80 ( struct V_51 * V_52 , void * V_106 )
{
struct V_1 * V_14 = V_106 ;
F_39 ( V_14 -> V_26 ) -> F_81 ( V_52 , V_14 ) ;
}
static void F_82 ( struct V_1 * V_14 )
{
unsigned int V_16 = V_14 -> V_17 . V_16 ;
unsigned int V_18 = V_14 -> args . V_19 ;
struct V_10 * * V_6 ;
if ( V_14 -> V_17 . V_21 )
V_16 = V_14 -> args . V_16 ;
if ( F_83 ( V_16 == 0 ) )
return;
V_6 = & V_14 -> args . V_6 [ V_18 >> V_22 ] ;
V_18 &= ~ V_23 ;
V_16 += V_18 ;
for (; V_16 >= V_13 ; V_16 -= V_13 , V_6 ++ )
F_13 ( * V_6 ) ;
if ( V_16 == 0 )
return;
if ( V_14 -> V_17 . V_21 || V_14 -> V_17 . V_16 == V_14 -> args . V_16 )
F_13 ( * V_6 ) ;
}
static void F_84 ( struct V_51 * V_52 , void * V_106 )
{
struct V_1 * V_14 = V_106 ;
if ( F_67 ( V_52 , V_14 ) != 0 )
return;
if ( V_52 -> V_96 < 0 )
return;
F_15 ( V_14 ) ;
F_82 ( V_14 ) ;
F_73 ( V_52 , V_14 ) ;
}
static void F_85 ( void * V_106 )
{
struct V_1 * V_14 = V_106 ;
while ( ! F_50 ( & V_14 -> V_6 ) ) {
struct V_34 * V_37 = F_54 ( V_14 -> V_6 . V_79 ) ;
F_55 ( V_37 ) ;
F_30 ( V_37 ) ;
}
F_9 ( V_106 ) ;
}
int F_86 ( struct V_109 * V_109 , struct V_10 * V_10 )
{
struct V_32 * V_33 ;
struct V_26 * V_26 = V_10 -> V_110 -> V_111 ;
int error ;
F_33 ( L_5 ,
V_10 , V_13 , V_10 -> V_112 ) ;
F_74 ( V_26 , V_113 ) ;
F_69 ( V_26 , V_114 , 1 ) ;
error = F_87 ( V_26 , V_10 ) ;
if ( error )
goto V_115;
if ( F_31 ( V_10 ) )
goto V_115;
error = - V_98 ;
if ( F_88 ( V_26 ) )
goto V_115;
if ( V_109 == NULL ) {
error = - V_116 ;
V_33 = F_89 ( V_26 , NULL , V_117 ) ;
if ( V_33 == NULL )
goto V_115;
} else
V_33 = F_45 ( F_90 ( V_109 ) ) ;
if ( ! F_91 ( V_26 ) ) {
error = F_92 ( V_33 , V_26 , V_10 ) ;
if ( error == 0 )
goto V_92;
}
error = F_22 ( V_33 , V_26 , V_10 ) ;
V_92:
F_10 ( V_33 ) ;
return error ;
V_115:
F_14 ( V_10 ) ;
return error ;
}
static int
F_93 ( void * V_14 , struct V_10 * V_10 )
{
struct V_118 * V_81 = (struct V_118 * ) V_14 ;
struct V_26 * V_26 = V_10 -> V_110 -> V_111 ;
struct V_34 * V_35 ;
unsigned int V_36 ;
int error ;
V_36 = F_23 ( V_10 ) ;
if ( V_36 == 0 )
return F_11 ( V_10 ) ;
V_35 = F_24 ( V_81 -> V_33 , V_26 , V_10 , 0 , V_36 ) ;
if ( F_25 ( V_35 ) )
goto V_119;
if ( V_36 < V_13 )
F_27 ( V_10 , V_36 , V_13 ) ;
if ( ! F_28 ( V_81 -> V_25 , V_35 ) ) {
error = V_81 -> V_25 -> V_120 ;
goto V_115;
}
return 0 ;
V_119:
error = F_26 ( V_35 ) ;
V_115:
F_14 ( V_10 ) ;
return error ;
}
int F_94 ( struct V_109 * V_121 , struct V_122 * V_110 ,
struct V_75 * V_6 , unsigned V_123 )
{
struct V_24 V_25 ;
struct V_118 V_81 = {
. V_25 = & V_25 ,
} ;
struct V_26 * V_26 = V_110 -> V_111 ;
unsigned long V_7 ;
int V_77 = - V_98 ;
F_33 ( L_6 ,
V_26 -> V_42 -> V_43 ,
( long long ) F_34 ( V_26 ) ,
V_123 ) ;
F_74 ( V_26 , V_124 ) ;
if ( F_88 ( V_26 ) )
goto V_92;
if ( V_121 == NULL ) {
V_81 . V_33 = F_89 ( V_26 , NULL , V_117 ) ;
if ( V_81 . V_33 == NULL )
return - V_116 ;
} else
V_81 . V_33 = F_45 ( F_90 ( V_121 ) ) ;
V_77 = F_95 ( V_81 . V_33 , V_26 , V_110 ,
V_6 , & V_123 ) ;
if ( V_77 == 0 )
goto V_125;
F_20 ( & V_25 , V_26 ) ;
V_77 = F_96 ( V_110 , V_6 , F_93 , & V_81 ) ;
F_29 ( & V_25 ) ;
V_7 = ( V_25 . V_126 + V_13 - 1 ) >> V_22 ;
F_69 ( V_26 , V_114 , V_7 ) ;
V_125:
F_10 ( V_81 . V_33 ) ;
V_92:
return V_77 ;
}
int T_2 F_97 ( void )
{
V_4 = F_98 ( L_7 ,
sizeof( struct V_1 ) ,
0 , V_127 ,
NULL ) ;
if ( V_4 == NULL )
return - V_90 ;
return 0 ;
}
void F_99 ( void )
{
F_100 ( V_4 ) ;
}
