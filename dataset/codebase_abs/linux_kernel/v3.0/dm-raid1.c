static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 -> V_4 , & V_3 -> V_5 ) ;
}
static void F_3 ( unsigned long V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 ;
F_4 ( 0 , & V_3 -> V_7 ) ;
F_1 ( V_3 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( F_6 ( 0 , & V_3 -> V_7 ) )
return;
V_3 -> V_8 . V_9 = V_10 + V_11 / 5 ;
V_3 -> V_8 . V_6 = ( unsigned long ) V_3 ;
V_3 -> V_8 . V_12 = F_3 ;
F_7 ( & V_3 -> V_8 ) ;
}
static void F_8 ( void * V_1 )
{
F_9 ( & V_13 ) ;
}
static void F_10 ( struct V_2 * V_3 , struct V_14 * V_14 , int V_15 )
{
unsigned long V_16 ;
int V_17 = 0 ;
struct V_18 * V_19 ;
V_19 = ( V_15 == V_20 ) ? & V_3 -> V_21 : & V_3 -> V_22 ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
V_17 = ! ( V_19 -> V_24 ) ;
F_12 ( V_19 , V_14 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
if ( V_17 )
F_1 ( V_3 ) ;
}
static void F_14 ( void * V_1 , struct V_18 * V_18 )
{
struct V_2 * V_3 = V_1 ;
struct V_14 * V_14 ;
while ( ( V_14 = F_15 ( V_18 ) ) )
F_10 ( V_3 , V_14 , V_20 ) ;
}
static struct V_25 * F_16 ( struct V_14 * V_14 )
{
return (struct V_25 * ) V_14 -> V_26 ;
}
static void F_17 ( struct V_14 * V_14 , struct V_25 * V_27 )
{
V_14 -> V_26 = (struct V_14 * ) V_27 ;
}
static struct V_25 * F_18 ( struct V_2 * V_3 )
{
return & V_3 -> V_25 [ F_19 ( & V_3 -> V_28 ) ] ;
}
static void F_20 ( struct V_25 * V_27 )
{
struct V_2 * V_3 = V_27 -> V_3 ;
struct V_25 * V_29 = & ( V_3 -> V_25 [ 0 ] ) ;
F_21 ( & V_3 -> V_28 , V_27 - V_29 ) ;
}
static struct V_25 * F_22 ( struct V_2 * V_3 )
{
struct V_25 * V_27 ;
for ( V_27 = V_3 -> V_25 ; V_27 < V_3 -> V_25 + V_3 -> V_30 ; V_27 ++ )
if ( ! F_19 ( & V_27 -> V_31 ) )
return V_27 ;
return NULL ;
}
static void F_23 ( struct V_25 * V_27 , enum V_32 V_33 )
{
struct V_2 * V_3 = V_27 -> V_3 ;
struct V_25 * V_34 ;
V_3 -> V_35 = 1 ;
F_24 ( & V_27 -> V_31 ) ;
if ( F_6 ( V_33 , & V_27 -> V_33 ) )
return;
if ( ! F_25 ( V_3 ) )
return;
if ( V_27 != F_18 ( V_3 ) )
goto V_36;
if ( ! V_3 -> V_37 ) {
F_26 ( L_1
L_2 , V_27 -> V_38 -> V_39 ) ;
goto V_36;
}
V_34 = F_22 ( V_3 ) ;
if ( V_34 )
F_20 ( V_34 ) ;
else
F_27 ( L_3 ) ;
V_36:
F_28 ( & V_3 -> V_40 ) ;
}
static int F_29 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
unsigned long V_44 ;
unsigned int V_45 ;
struct V_46 V_47 [ V_3 -> V_30 ] ;
struct V_25 * V_27 ;
struct V_48 V_49 = {
. V_50 = V_51 ,
. V_52 . type = V_53 ,
. V_52 . V_54 . V_55 = NULL ,
. V_56 = V_3 -> V_57 ,
} ;
for ( V_45 = 0 , V_27 = V_3 -> V_25 ; V_45 < V_3 -> V_30 ; V_45 ++ , V_27 ++ ) {
V_47 [ V_45 ] . V_58 = V_27 -> V_38 -> V_58 ;
V_47 [ V_45 ] . V_59 = 0 ;
V_47 [ V_45 ] . V_60 = 0 ;
}
V_44 = - 1 ;
F_30 ( & V_49 , V_3 -> V_30 , V_47 , & V_44 ) ;
if ( F_31 ( V_44 != 0 ) ) {
for ( V_45 = 0 ; V_45 < V_3 -> V_30 ; V_45 ++ )
if ( F_32 ( V_45 , & V_44 ) )
F_23 ( V_3 -> V_25 + V_45 ,
V_61 ) ;
return - V_62 ;
}
return 0 ;
}
static void F_33 ( int V_63 , unsigned long V_64 ,
void * V_1 )
{
struct V_65 * V_66 = V_1 ;
struct V_2 * V_3 = F_34 ( V_66 ) ;
int V_27 , V_67 = 0 ;
if ( V_63 ) {
F_35 ( L_4 ) ;
F_23 ( F_18 ( V_3 ) , V_68 ) ;
}
if ( V_64 ) {
F_35 ( L_5 ,
V_64 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
if ( & V_3 -> V_25 [ V_27 ] == F_18 ( V_3 ) )
continue;
if ( F_32 ( V_67 , & V_64 ) )
F_23 ( V_3 -> V_25 + V_27 ,
V_68 ) ;
V_67 ++ ;
}
}
F_36 ( V_66 , ! ( V_63 || V_64 ) ) ;
}
static int F_37 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
int V_69 ;
unsigned V_45 ;
struct V_46 V_70 , V_71 [ V_72 ] , * V_73 ;
struct V_25 * V_27 ;
unsigned long V_16 = 0 ;
T_1 V_74 = F_38 ( V_66 ) ;
T_2 V_75 = F_39 ( V_3 -> V_76 ) ;
V_27 = F_18 ( V_3 ) ;
V_70 . V_58 = V_27 -> V_38 -> V_58 ;
V_70 . V_59 = V_27 -> V_77 + F_40 ( V_3 -> V_76 , V_74 ) ;
if ( V_74 == ( V_3 -> V_78 - 1 ) ) {
V_70 . V_60 = V_3 -> V_42 -> V_79 & ( V_75 - 1 ) ;
if ( ! V_70 . V_60 )
V_70 . V_60 = V_75 ;
} else
V_70 . V_60 = V_75 ;
for ( V_45 = 0 , V_73 = V_71 ; V_45 < V_3 -> V_30 ; V_45 ++ ) {
if ( & V_3 -> V_25 [ V_45 ] == F_18 ( V_3 ) )
continue;
V_27 = V_3 -> V_25 + V_45 ;
V_73 -> V_58 = V_27 -> V_38 -> V_58 ;
V_73 -> V_59 = V_27 -> V_77 + F_40 ( V_3 -> V_76 , V_74 ) ;
V_73 -> V_60 = V_70 . V_60 ;
V_73 ++ ;
}
if ( ! F_25 ( V_3 ) )
F_41 ( V_80 , & V_16 ) ;
V_69 = F_42 ( V_3 -> V_81 , & V_70 , V_3 -> V_30 - 1 , V_71 ,
V_16 , F_33 , V_66 ) ;
return V_69 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_65 * V_66 ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
int V_69 ;
F_45 ( V_3 -> V_76 ) ;
while ( ( V_66 = F_46 ( V_3 -> V_76 ) ) ) {
V_69 = F_37 ( V_3 , V_66 ) ;
if ( V_69 )
F_36 ( V_66 , 0 ) ;
}
if ( ! V_3 -> V_37 &&
( log -> type -> V_83 ( log ) == V_3 -> V_78 ) ) {
F_47 ( V_3 -> V_42 -> V_84 ) ;
V_3 -> V_37 = 1 ;
}
}
static struct V_25 * F_48 ( struct V_2 * V_3 , T_2 V_59 )
{
struct V_25 * V_27 = F_18 ( V_3 ) ;
do {
if ( F_49 ( ! F_19 ( & V_27 -> V_31 ) ) )
return V_27 ;
if ( V_27 -- == V_3 -> V_25 )
V_27 += V_3 -> V_30 ;
} while ( V_27 != F_18 ( V_3 ) );
return NULL ;
}
static int F_50 ( struct V_25 * V_27 )
{
struct V_25 * V_28 = F_18 ( V_27 -> V_3 ) ;
return ! F_19 ( & V_28 -> V_31 ) ;
}
static int F_51 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
T_1 V_85 = F_52 ( V_3 -> V_76 , V_14 ) ;
if ( log -> type -> V_37 ( log , V_85 , 0 ) )
return F_48 ( V_3 , V_14 -> V_86 ) ? 1 : 0 ;
return 0 ;
}
static T_2 F_53 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
if ( F_31 ( ! V_14 -> V_87 ) )
return 0 ;
return V_27 -> V_77 + F_54 ( V_27 -> V_3 -> V_42 , V_14 -> V_86 ) ;
}
static void F_55 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
V_14 -> V_88 = V_27 -> V_38 -> V_58 ;
V_14 -> V_86 = F_53 ( V_27 , V_14 ) ;
}
static void F_56 ( struct V_46 * V_47 , struct V_25 * V_27 ,
struct V_14 * V_14 )
{
V_47 -> V_58 = V_27 -> V_38 -> V_58 ;
V_47 -> V_59 = F_53 ( V_27 , V_14 ) ;
V_47 -> V_60 = V_14 -> V_87 >> 9 ;
}
static void F_57 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
F_58 ( & V_3 -> V_23 ) ;
if ( F_19 ( & V_3 -> V_89 ) ) {
F_59 ( & V_3 -> V_23 ) ;
if ( F_60 ( V_3 -> V_42 ) )
F_61 ( V_14 , V_90 ) ;
else
F_61 ( V_14 , - V_62 ) ;
return;
}
F_12 ( & V_3 -> V_91 , V_14 ) ;
F_59 ( & V_3 -> V_23 ) ;
}
static void F_62 ( unsigned long error , void * V_1 )
{
struct V_14 * V_14 = V_1 ;
struct V_25 * V_27 ;
V_27 = F_16 ( V_14 ) ;
F_17 ( V_14 , NULL ) ;
if ( F_49 ( ! error ) ) {
F_61 ( V_14 , 0 ) ;
return;
}
F_23 ( V_27 , V_92 ) ;
if ( F_49 ( F_50 ( V_27 ) ) || F_51 ( V_27 -> V_3 , V_14 ) ) {
F_63 ( L_6
L_7 ,
V_27 -> V_38 -> V_39 ) ;
F_10 ( V_27 -> V_3 , V_14 , F_64 ( V_14 ) ) ;
return;
}
F_35 ( L_8 ,
V_27 -> V_38 -> V_39 ) ;
F_61 ( V_14 , - V_62 ) ;
}
static void F_65 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
struct V_46 V_47 ;
struct V_48 V_49 = {
. V_50 = V_93 ,
. V_52 . type = V_94 ,
. V_52 . V_54 . V_95 = V_14 -> V_96 + V_14 -> V_97 ,
. V_98 . V_99 = F_62 ,
. V_98 . V_1 = V_14 ,
. V_56 = V_27 -> V_3 -> V_57 ,
} ;
F_56 ( & V_47 , V_27 , V_14 ) ;
F_17 ( V_14 , V_27 ) ;
F_66 ( F_30 ( & V_49 , 1 , & V_47 , NULL ) ) ;
}
static inline int F_67 ( struct V_2 * V_3 , T_1 V_85 ,
int V_100 )
{
int V_101 = F_68 ( V_3 -> V_76 , V_85 , V_100 ) ;
return V_101 == V_102 || V_101 == V_103 ;
}
static void F_69 ( struct V_2 * V_3 , struct V_18 * V_22 )
{
T_1 V_85 ;
struct V_14 * V_14 ;
struct V_25 * V_27 ;
while ( ( V_14 = F_15 ( V_22 ) ) ) {
V_85 = F_52 ( V_3 -> V_76 , V_14 ) ;
V_27 = F_18 ( V_3 ) ;
if ( F_49 ( F_67 ( V_3 , V_85 , 1 ) ) )
V_27 = F_48 ( V_3 , V_14 -> V_86 ) ;
else if ( V_27 && F_19 ( & V_27 -> V_31 ) )
V_27 = NULL ;
if ( F_49 ( V_27 ) )
F_65 ( V_27 , V_14 ) ;
else
F_61 ( V_14 , - V_62 ) ;
}
}
static void F_70 ( unsigned long error , void * V_1 )
{
unsigned V_45 , V_104 = 0 ;
struct V_14 * V_14 = (struct V_14 * ) V_1 ;
struct V_2 * V_3 ;
int V_17 = 0 ;
unsigned long V_16 ;
V_3 = F_16 ( V_14 ) -> V_3 ;
F_17 ( V_14 , NULL ) ;
if ( F_49 ( ! error ) ) {
F_61 ( V_14 , V_104 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_3 -> V_30 ; V_45 ++ )
if ( F_32 ( V_45 , & error ) )
F_23 ( V_3 -> V_25 + V_45 , V_105 ) ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
if ( ! V_3 -> V_106 . V_24 )
V_17 = 1 ;
F_12 ( & V_3 -> V_106 , V_14 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
if ( V_17 )
F_1 ( V_3 ) ;
}
static void F_71 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
unsigned int V_45 ;
struct V_46 V_47 [ V_3 -> V_30 ] , * V_73 = V_47 ;
struct V_25 * V_27 ;
struct V_48 V_49 = {
. V_50 = V_20 | ( V_14 -> V_50 & V_107 ) ,
. V_52 . type = V_94 ,
. V_52 . V_54 . V_95 = V_14 -> V_96 + V_14 -> V_97 ,
. V_98 . V_99 = F_70 ,
. V_98 . V_1 = V_14 ,
. V_56 = V_3 -> V_57 ,
} ;
if ( V_14 -> V_50 & V_108 ) {
V_49 . V_50 |= V_108 ;
V_49 . V_52 . type = V_53 ;
V_49 . V_52 . V_54 . V_55 = NULL ;
}
for ( V_45 = 0 , V_27 = V_3 -> V_25 ; V_45 < V_3 -> V_30 ; V_45 ++ , V_27 ++ )
F_56 ( V_73 ++ , V_27 , V_14 ) ;
F_17 ( V_14 , F_18 ( V_3 ) ) ;
F_66 ( F_30 ( & V_49 , V_3 -> V_30 , V_47 , NULL ) ) ;
}
static void F_72 ( struct V_2 * V_3 , struct V_18 * V_21 )
{
int V_101 ;
struct V_14 * V_14 ;
struct V_18 V_109 , V_110 , F_37 , * V_111 = NULL ;
struct V_18 V_112 ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
T_1 V_85 ;
if ( ! V_21 -> V_24 )
return;
F_73 ( & V_109 ) ;
F_73 ( & V_110 ) ;
F_73 ( & F_37 ) ;
F_73 ( & V_112 ) ;
while ( ( V_14 = F_15 ( V_21 ) ) ) {
if ( ( V_14 -> V_50 & V_113 ) ||
( V_14 -> V_50 & V_108 ) ) {
F_12 ( & V_109 , V_14 ) ;
continue;
}
V_85 = F_52 ( V_3 -> V_76 , V_14 ) ;
if ( log -> type -> V_114 &&
log -> type -> V_114 ( log , V_85 ) ) {
F_12 ( & V_112 , V_14 ) ;
continue;
}
V_101 = F_68 ( V_3 -> V_76 , V_85 , 1 ) ;
switch ( V_101 ) {
case V_102 :
case V_103 :
V_111 = & V_109 ;
break;
case V_115 :
V_111 = & V_110 ;
break;
case V_116 :
V_111 = & F_37 ;
break;
}
F_12 ( V_111 , V_14 ) ;
}
if ( F_31 ( V_112 . V_24 ) ) {
F_58 ( & V_3 -> V_23 ) ;
F_74 ( & V_3 -> V_21 , & V_112 ) ;
F_59 ( & V_3 -> V_23 ) ;
F_5 ( V_3 ) ;
}
F_75 ( V_3 -> V_76 , & V_109 ) ;
F_75 ( V_3 -> V_76 , & V_110 ) ;
V_3 -> V_117 = F_76 ( V_3 -> V_76 ) ? 1 : V_3 -> V_117 ;
if ( F_31 ( V_3 -> V_117 ) && F_25 ( V_3 ) ) {
F_58 ( & V_3 -> V_23 ) ;
F_74 ( & V_3 -> V_106 , & V_109 ) ;
F_59 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
} else
while ( ( V_14 = F_15 ( & V_109 ) ) )
F_71 ( V_3 , V_14 ) ;
while ( ( V_14 = F_15 ( & F_37 ) ) )
F_77 ( V_3 -> V_76 , V_14 ) ;
while ( ( V_14 = F_15 ( & V_110 ) ) ) {
if ( F_31 ( V_3 -> V_35 ) && F_25 ( V_3 ) ) {
F_58 ( & V_3 -> V_23 ) ;
F_12 ( & V_3 -> V_106 , V_14 ) ;
F_59 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
} else {
F_55 ( F_18 ( V_3 ) , V_14 ) ;
F_78 ( V_14 ) ;
}
}
}
static void F_79 ( struct V_2 * V_3 , struct V_18 * V_106 )
{
struct V_14 * V_14 ;
if ( F_49 ( ! V_106 -> V_24 ) )
return;
while ( ( V_14 = F_15 ( V_106 ) ) ) {
if ( ! V_3 -> V_117 ) {
V_3 -> V_37 = 0 ;
F_80 ( V_3 -> V_76 , V_14 ) ;
}
if ( ! F_22 ( V_3 ) )
F_61 ( V_14 , - V_62 ) ;
else if ( F_25 ( V_3 ) )
F_57 ( V_3 , V_14 ) ;
else
F_61 ( V_14 , 0 ) ;
}
}
static void V_40 ( struct V_118 * V_119 )
{
struct V_2 * V_3 =
F_81 ( V_119 , struct V_2 , V_40 ) ;
F_47 ( V_3 -> V_42 -> V_84 ) ;
}
static void F_82 ( struct V_118 * V_119 )
{
struct V_2 * V_3 = F_81 ( V_119 , struct V_2 ,
V_5 ) ;
struct V_18 V_22 , V_21 , V_106 ;
unsigned long V_16 ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
V_22 = V_3 -> V_22 ;
V_21 = V_3 -> V_21 ;
V_106 = V_3 -> V_106 ;
F_73 ( & V_3 -> V_22 ) ;
F_73 ( & V_3 -> V_21 ) ;
F_73 ( & V_3 -> V_106 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
F_83 ( V_3 -> V_76 , F_25 ( V_3 ) ) ;
F_43 ( V_3 ) ;
F_69 ( V_3 , & V_22 ) ;
F_72 ( V_3 , & V_21 ) ;
F_79 ( V_3 , & V_106 ) ;
}
static struct V_2 * F_84 ( unsigned int V_30 ,
T_3 V_75 ,
struct V_41 * V_42 ,
struct V_82 * V_120 )
{
T_4 V_79 ;
struct V_2 * V_3 = NULL ;
V_79 = sizeof( * V_3 ) + ( sizeof( V_3 -> V_25 [ 0 ] ) * V_30 ) ;
V_3 = F_85 ( V_79 , V_121 ) ;
if ( ! V_3 ) {
V_42 -> error = L_9 ;
return NULL ;
}
F_86 ( & V_3 -> V_23 ) ;
F_73 ( & V_3 -> V_22 ) ;
F_73 ( & V_3 -> V_21 ) ;
F_73 ( & V_3 -> V_106 ) ;
F_73 ( & V_3 -> V_91 ) ;
V_3 -> V_42 = V_42 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_78 = F_87 ( V_42 -> V_79 , V_75 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_117 = 0 ;
V_3 -> V_35 = 0 ;
F_21 ( & V_3 -> V_89 , 0 ) ;
F_21 ( & V_3 -> V_28 , V_122 ) ;
V_3 -> V_123 = F_88 ( V_124 ,
V_125 ) ;
if ( ! V_3 -> V_123 ) {
V_42 -> error = L_10 ;
F_89 ( V_3 ) ;
return NULL ;
}
V_3 -> V_57 = F_90 () ;
if ( F_91 ( V_3 -> V_57 ) ) {
V_42 -> error = L_11 ;
F_92 ( V_3 -> V_123 ) ;
F_89 ( V_3 ) ;
return NULL ;
}
V_3 -> V_76 = F_93 ( V_3 , F_14 , F_1 ,
F_8 ,
V_3 -> V_42 -> V_126 , V_127 ,
V_120 , V_75 , V_3 -> V_78 ) ;
if ( F_91 ( V_3 -> V_76 ) ) {
V_42 -> error = L_12 ;
F_94 ( V_3 -> V_57 ) ;
F_92 ( V_3 -> V_123 ) ;
F_89 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_41 * V_42 ,
unsigned int V_27 )
{
while ( V_27 -- )
F_96 ( V_42 , V_3 -> V_25 [ V_27 ] . V_38 ) ;
F_94 ( V_3 -> V_57 ) ;
F_97 ( V_3 -> V_76 ) ;
F_92 ( V_3 -> V_123 ) ;
F_89 ( V_3 ) ;
}
static int F_98 ( struct V_2 * V_3 , struct V_41 * V_42 ,
unsigned int V_25 , char * * V_128 )
{
unsigned long long V_77 ;
if ( sscanf ( V_128 [ 1 ] , L_13 , & V_77 ) != 1 ) {
V_42 -> error = L_14 ;
return - V_129 ;
}
if ( F_99 ( V_42 , V_128 [ 0 ] , F_100 ( V_42 -> V_84 ) ,
& V_3 -> V_25 [ V_25 ] . V_38 ) ) {
V_42 -> error = L_15 ;
return - V_130 ;
}
V_3 -> V_25 [ V_25 ] . V_3 = V_3 ;
F_21 ( & ( V_3 -> V_25 [ V_25 ] . V_31 ) , 0 ) ;
V_3 -> V_25 [ V_25 ] . V_33 = 0 ;
V_3 -> V_25 [ V_25 ] . V_77 = V_77 ;
return 0 ;
}
static struct V_82 * F_101 ( struct V_41 * V_42 ,
unsigned V_131 , char * * V_128 ,
unsigned * V_132 )
{
unsigned V_133 ;
struct V_82 * V_120 ;
if ( V_131 < 2 ) {
V_42 -> error = L_16 ;
return NULL ;
}
if ( sscanf ( V_128 [ 1 ] , L_17 , & V_133 ) != 1 ) {
V_42 -> error = L_18 ;
return NULL ;
}
* V_132 = 2 + V_133 ;
if ( V_131 < * V_132 ) {
V_42 -> error = L_16 ;
return NULL ;
}
V_120 = F_102 ( V_128 [ 0 ] , V_42 , F_29 , V_133 ,
V_128 + 2 ) ;
if ( ! V_120 ) {
V_42 -> error = L_19 ;
return NULL ;
}
return V_120 ;
}
static int F_103 ( struct V_2 * V_3 , unsigned V_131 , char * * V_128 ,
unsigned * V_132 )
{
unsigned V_134 ;
struct V_41 * V_42 = V_3 -> V_42 ;
* V_132 = 0 ;
if ( ! V_131 )
return 0 ;
if ( sscanf ( V_128 [ 0 ] , L_17 , & V_134 ) != 1 ) {
V_42 -> error = L_20 ;
return - V_129 ;
}
V_131 -- ;
V_128 ++ ;
( * V_132 ) ++ ;
if ( V_134 > V_131 ) {
V_42 -> error = L_21 ;
return - V_129 ;
}
if ( ! strcmp ( L_22 , V_128 [ 0 ] ) )
V_3 -> V_135 |= V_136 ;
else {
V_42 -> error = L_23 ;
return - V_129 ;
}
( * V_132 ) ++ ;
return 0 ;
}
static int F_104 ( struct V_41 * V_42 , unsigned int V_131 , char * * V_128 )
{
int V_69 ;
unsigned int V_30 , V_27 , V_132 ;
struct V_2 * V_3 ;
struct V_82 * V_120 ;
V_120 = F_101 ( V_42 , V_131 , V_128 , & V_132 ) ;
if ( ! V_120 )
return - V_129 ;
V_128 += V_132 ;
V_131 -= V_132 ;
if ( ! V_131 || sscanf ( V_128 [ 0 ] , L_17 , & V_30 ) != 1 ||
V_30 < 2 || V_30 > V_72 + 1 ) {
V_42 -> error = L_24 ;
F_105 ( V_120 ) ;
return - V_129 ;
}
V_128 ++ , V_131 -- ;
if ( V_131 < V_30 * 2 ) {
V_42 -> error = L_25 ;
F_105 ( V_120 ) ;
return - V_129 ;
}
V_3 = F_84 ( V_30 , V_120 -> type -> V_137 ( V_120 ) , V_42 , V_120 ) ;
if ( ! V_3 ) {
F_105 ( V_120 ) ;
return - V_138 ;
}
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
V_69 = F_98 ( V_3 , V_42 , V_27 , V_128 ) ;
if ( V_69 ) {
F_95 ( V_3 , V_42 , V_27 ) ;
return V_69 ;
}
V_128 += 2 ;
V_131 -= 2 ;
}
V_42 -> V_43 = V_3 ;
V_42 -> V_139 = F_39 ( V_3 -> V_76 ) ;
V_42 -> V_140 = 1 ;
V_42 -> V_141 = 1 ;
V_3 -> V_4 = F_106 ( L_26 ,
V_142 | V_143 , 0 ) ;
if ( ! V_3 -> V_4 ) {
F_26 ( L_27 ) ;
V_69 = - V_138 ;
goto V_144;
}
F_107 ( & V_3 -> V_5 , F_82 ) ;
F_108 ( & V_3 -> V_8 ) ;
V_3 -> V_7 = 0 ;
F_107 ( & V_3 -> V_40 , V_40 ) ;
V_69 = F_103 ( V_3 , V_131 , V_128 , & V_132 ) ;
if ( V_69 )
goto V_145;
V_128 += V_132 ;
V_131 -= V_132 ;
if ( V_131 ) {
V_42 -> error = L_28 ;
V_69 = - V_129 ;
goto V_145;
}
V_3 -> V_81 = F_109 () ;
if ( F_91 ( V_3 -> V_81 ) ) {
V_69 = F_110 ( V_3 -> V_81 ) ;
goto V_145;
}
F_1 ( V_3 ) ;
return 0 ;
V_145:
F_111 ( V_3 -> V_4 ) ;
V_144:
F_95 ( V_3 , V_42 , V_3 -> V_30 ) ;
return V_69 ;
}
static void F_112 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
F_113 ( & V_3 -> V_8 ) ;
F_114 ( V_3 -> V_4 ) ;
F_115 ( & V_3 -> V_40 ) ;
F_116 ( V_3 -> V_81 ) ;
F_111 ( V_3 -> V_4 ) ;
F_95 ( V_3 , V_42 , V_3 -> V_30 ) ;
}
static int F_117 ( struct V_41 * V_42 , struct V_14 * V_14 ,
union V_146 * V_147 )
{
int V_69 , V_15 = F_64 ( V_14 ) ;
struct V_25 * V_27 ;
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_148 * V_149 = NULL ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
if ( V_15 == V_20 ) {
V_147 -> V_150 = F_52 ( V_3 -> V_76 , V_14 ) ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_151 ;
}
V_69 = log -> type -> V_37 ( log , F_52 ( V_3 -> V_76 , V_14 ) , 0 ) ;
if ( V_69 < 0 && V_69 != - V_152 )
return V_69 ;
if ( ! V_69 || ( V_69 == - V_152 ) ) {
if ( V_15 == V_153 )
return - V_152 ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_151 ;
}
V_27 = F_48 ( V_3 , V_14 -> V_86 ) ;
if ( F_31 ( ! V_27 ) )
return - V_62 ;
V_149 = F_118 ( V_3 -> V_123 , V_154 ) ;
if ( F_49 ( V_149 ) ) {
F_119 ( & V_149 -> V_155 , V_14 ) ;
V_147 -> V_54 = V_149 ;
V_149 -> V_27 = V_27 ;
}
F_55 ( V_27 , V_14 ) ;
return V_156 ;
}
static int F_120 ( struct V_41 * V_42 , struct V_14 * V_14 ,
int error , union V_146 * V_147 )
{
int V_15 = F_64 ( V_14 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_25 * V_27 = NULL ;
struct V_157 * V_158 = NULL ;
struct V_148 * V_149 = V_147 -> V_54 ;
if ( V_15 == V_20 ) {
if ( ! ( V_14 -> V_50 & V_113 ) )
F_121 ( V_3 -> V_76 , V_147 -> V_150 ) ;
return error ;
}
if ( error == - V_159 )
goto V_36;
if ( ( error == - V_152 ) && ( V_14 -> V_50 & V_160 ) )
goto V_36;
if ( F_31 ( error ) ) {
if ( ! V_149 ) {
F_35 ( L_29 ) ;
return - V_62 ;
}
V_27 = V_149 -> V_27 ;
F_26 ( L_30 ,
V_27 -> V_38 -> V_39 ) ;
F_23 ( V_27 , V_92 ) ;
if ( F_50 ( V_27 ) || F_51 ( V_3 , V_14 ) ) {
V_158 = & V_149 -> V_155 ;
F_122 ( V_158 , V_14 ) ;
F_123 ( V_149 , V_3 -> V_123 ) ;
V_147 -> V_54 = NULL ;
F_10 ( V_3 , V_14 , V_15 ) ;
return 1 ;
}
F_26 ( L_31 ) ;
}
V_36:
if ( V_149 ) {
F_123 ( V_149 , V_3 -> V_123 ) ;
V_147 -> V_54 = NULL ;
}
return error ;
}
static void F_124 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
struct V_18 V_91 ;
struct V_14 * V_14 ;
F_21 ( & V_3 -> V_89 , 1 ) ;
F_58 ( & V_3 -> V_23 ) ;
V_91 = V_3 -> V_91 ;
F_73 ( & V_3 -> V_91 ) ;
F_59 ( & V_3 -> V_23 ) ;
while ( ( V_14 = F_15 ( & V_91 ) ) )
F_57 ( V_3 , V_14 ) ;
F_125 ( V_3 -> V_76 ) ;
F_126 ( V_13 ,
! F_127 ( V_3 -> V_76 ) ) ;
if ( log -> type -> V_161 && log -> type -> V_161 ( log ) )
F_27 ( L_32 ) ;
F_114 ( V_3 -> V_4 ) ;
}
static void F_128 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
if ( log -> type -> V_162 && log -> type -> V_162 ( log ) )
F_27 ( L_33 ) ;
}
static void F_129 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
F_21 ( & V_3 -> V_89 , 0 ) ;
if ( log -> type -> V_163 && log -> type -> V_163 ( log ) )
F_27 ( L_34 ) ;
F_130 ( V_3 -> V_76 ) ;
}
static char F_131 ( struct V_25 * V_27 )
{
if ( ! F_19 ( & ( V_27 -> V_31 ) ) )
return 'A' ;
return ( F_32 ( V_61 , & ( V_27 -> V_33 ) ) ) ? 'F' :
( F_32 ( V_105 , & ( V_27 -> V_33 ) ) ) ? 'D' :
( F_32 ( V_68 , & ( V_27 -> V_33 ) ) ) ? 'S' :
( F_32 ( V_92 , & ( V_27 -> V_33 ) ) ) ? 'R' : 'U' ;
}
static int F_132 ( struct V_41 * V_42 , T_5 type ,
char * V_164 , unsigned int V_165 )
{
unsigned int V_27 , V_166 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_82 * log = F_44 ( V_3 -> V_76 ) ;
char V_167 [ V_3 -> V_30 + 1 ] ;
switch ( type ) {
case V_168 :
F_133 ( L_35 , V_3 -> V_30 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
F_133 ( L_36 , V_3 -> V_25 [ V_27 ] . V_38 -> V_39 ) ;
V_167 [ V_27 ] = F_131 ( & ( V_3 -> V_25 [ V_27 ] ) ) ;
}
V_167 [ V_27 ] = '\0' ;
F_133 ( L_37 ,
( unsigned long long ) log -> type -> V_83 ( log ) ,
( unsigned long long ) V_3 -> V_78 , V_167 ) ;
V_166 += log -> type -> V_169 ( log , type , V_164 + V_166 , V_165 - V_166 ) ;
break;
case V_170 :
V_166 = log -> type -> V_169 ( log , type , V_164 , V_165 ) ;
F_133 ( L_38 , V_3 -> V_30 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ )
F_133 ( L_39 , V_3 -> V_25 [ V_27 ] . V_38 -> V_39 ,
( unsigned long long ) V_3 -> V_25 [ V_27 ] . V_77 ) ;
if ( V_3 -> V_135 & V_136 )
F_133 ( L_40 ) ;
}
return 0 ;
}
static int F_134 ( struct V_41 * V_42 ,
T_6 V_99 , void * V_6 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
int V_104 = 0 ;
unsigned V_45 ;
for ( V_45 = 0 ; ! V_104 && V_45 < V_3 -> V_30 ; V_45 ++ )
V_104 = V_99 ( V_42 , V_3 -> V_25 [ V_45 ] . V_38 ,
V_3 -> V_25 [ V_45 ] . V_77 , V_42 -> V_79 , V_6 ) ;
return V_104 ;
}
static int T_7 F_135 ( void )
{
int V_69 ;
V_125 = F_136 ( V_148 , 0 ) ;
if ( ! V_125 ) {
F_26 ( L_41 ) ;
V_69 = - V_138 ;
goto V_171;
}
V_69 = F_137 ( & V_172 ) ;
if ( V_69 < 0 ) {
F_26 ( L_42 ) ;
goto V_173;
}
return 0 ;
V_173:
F_138 ( V_125 ) ;
V_171:
return V_69 ;
}
static void T_8 F_139 ( void )
{
F_140 ( & V_172 ) ;
F_138 ( V_125 ) ;
}
