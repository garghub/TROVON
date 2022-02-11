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
if ( ! V_3 -> V_37 && ! F_26 ( V_3 ) ) {
F_27 ( L_1
L_2 , V_27 -> V_38 -> V_39 ) ;
goto V_36;
}
V_34 = F_22 ( V_3 ) ;
if ( V_34 )
F_20 ( V_34 ) ;
else
F_28 ( L_3 ) ;
V_36:
F_29 ( & V_3 -> V_40 ) ;
}
static int F_30 ( struct V_41 * V_42 )
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
F_31 ( & V_49 , V_3 -> V_30 , V_47 , & V_44 ) ;
if ( F_32 ( V_44 != 0 ) ) {
for ( V_45 = 0 ; V_45 < V_3 -> V_30 ; V_45 ++ )
if ( F_33 ( V_45 , & V_44 ) )
F_23 ( V_3 -> V_25 + V_45 ,
V_61 ) ;
return - V_62 ;
}
return 0 ;
}
static void F_34 ( int V_63 , unsigned long V_64 ,
void * V_1 )
{
struct V_65 * V_66 = V_1 ;
struct V_2 * V_3 = F_35 ( V_66 ) ;
int V_27 , V_67 = 0 ;
if ( V_63 ) {
F_36 ( L_4 ) ;
F_23 ( F_18 ( V_3 ) , V_68 ) ;
}
if ( V_64 ) {
F_36 ( L_5 ,
V_64 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
if ( & V_3 -> V_25 [ V_27 ] == F_18 ( V_3 ) )
continue;
if ( F_33 ( V_67 , & V_64 ) )
F_23 ( V_3 -> V_25 + V_27 ,
V_68 ) ;
V_67 ++ ;
}
}
F_37 ( V_66 , ! ( V_63 || V_64 ) ) ;
}
static int F_38 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
int V_69 ;
unsigned V_45 ;
struct V_46 V_70 , V_71 [ V_72 ] , * V_73 ;
struct V_25 * V_27 ;
unsigned long V_16 = 0 ;
T_1 V_74 = F_39 ( V_66 ) ;
T_2 V_75 = F_40 ( V_3 -> V_76 ) ;
V_27 = F_18 ( V_3 ) ;
V_70 . V_58 = V_27 -> V_38 -> V_58 ;
V_70 . V_59 = V_27 -> V_77 + F_41 ( V_3 -> V_76 , V_74 ) ;
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
V_73 -> V_59 = V_27 -> V_77 + F_41 ( V_3 -> V_76 , V_74 ) ;
V_73 -> V_60 = V_70 . V_60 ;
V_73 ++ ;
}
if ( ! F_25 ( V_3 ) )
F_42 ( V_80 , & V_16 ) ;
V_69 = F_43 ( V_3 -> V_81 , & V_70 , V_3 -> V_30 - 1 , V_71 ,
V_16 , F_34 , V_66 ) ;
return V_69 ;
}
static void F_44 ( struct V_2 * V_3 )
{
unsigned int V_27 ;
V_3 -> V_35 = 0 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
F_21 ( & ( V_3 -> V_25 [ V_27 ] . V_31 ) , 0 ) ;
V_3 -> V_25 [ V_27 ] . V_33 = 0 ;
}
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_65 * V_66 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
int V_69 ;
F_47 ( V_3 -> V_76 ) ;
while ( ( V_66 = F_48 ( V_3 -> V_76 ) ) ) {
V_69 = F_38 ( V_3 , V_66 ) ;
if ( V_69 )
F_37 ( V_66 , 0 ) ;
}
if ( ! V_3 -> V_37 &&
( log -> type -> V_83 ( log ) == V_3 -> V_78 ) ) {
F_49 ( V_3 -> V_42 -> V_84 ) ;
V_3 -> V_37 = 1 ;
F_44 ( V_3 ) ;
}
}
static struct V_25 * F_50 ( struct V_2 * V_3 , T_2 V_59 )
{
struct V_25 * V_27 = F_18 ( V_3 ) ;
do {
if ( F_51 ( ! F_19 ( & V_27 -> V_31 ) ) )
return V_27 ;
if ( V_27 -- == V_3 -> V_25 )
V_27 += V_3 -> V_30 ;
} while ( V_27 != F_18 ( V_3 ) );
return NULL ;
}
static int F_52 ( struct V_25 * V_27 )
{
struct V_25 * V_28 = F_18 ( V_27 -> V_3 ) ;
return ! F_19 ( & V_28 -> V_31 ) ;
}
static int F_53 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
T_1 V_85 = F_54 ( V_3 -> V_76 , V_14 ) ;
if ( log -> type -> V_37 ( log , V_85 , 0 ) )
return F_50 ( V_3 , V_14 -> V_86 . V_87 ) ? 1 : 0 ;
return 0 ;
}
static T_2 F_55 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
if ( F_32 ( ! V_14 -> V_86 . V_88 ) )
return 0 ;
return V_27 -> V_77 + F_56 ( V_27 -> V_3 -> V_42 , V_14 -> V_86 . V_87 ) ;
}
static void F_57 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
V_14 -> V_89 = V_27 -> V_38 -> V_58 ;
V_14 -> V_86 . V_87 = F_55 ( V_27 , V_14 ) ;
}
static void F_58 ( struct V_46 * V_47 , struct V_25 * V_27 ,
struct V_14 * V_14 )
{
V_47 -> V_58 = V_27 -> V_38 -> V_58 ;
V_47 -> V_59 = F_55 ( V_27 , V_14 ) ;
V_47 -> V_60 = F_59 ( V_14 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
F_61 ( & V_3 -> V_23 ) ;
if ( F_19 ( & V_3 -> V_90 ) ) {
F_62 ( & V_3 -> V_23 ) ;
if ( F_63 ( V_3 -> V_42 ) )
F_64 ( V_14 , V_91 ) ;
else
F_64 ( V_14 , - V_62 ) ;
return;
}
F_12 ( & V_3 -> V_92 , V_14 ) ;
F_62 ( & V_3 -> V_23 ) ;
}
static void F_65 ( unsigned long error , void * V_1 )
{
struct V_14 * V_14 = V_1 ;
struct V_25 * V_27 ;
V_27 = F_16 ( V_14 ) ;
F_17 ( V_14 , NULL ) ;
if ( F_51 ( ! error ) ) {
F_64 ( V_14 , 0 ) ;
return;
}
F_23 ( V_27 , V_93 ) ;
if ( F_51 ( F_52 ( V_27 ) ) || F_53 ( V_27 -> V_3 , V_14 ) ) {
F_66 ( L_6
L_7 ,
V_27 -> V_38 -> V_39 ) ;
F_10 ( V_27 -> V_3 , V_14 , F_67 ( V_14 ) ) ;
return;
}
F_36 ( L_8 ,
V_27 -> V_38 -> V_39 ) ;
F_64 ( V_14 , - V_62 ) ;
}
static void F_68 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
struct V_46 V_47 ;
struct V_48 V_49 = {
. V_50 = V_94 ,
. V_52 . type = V_95 ,
. V_52 . V_54 . V_14 = V_14 ,
. V_96 . V_97 = F_65 ,
. V_96 . V_1 = V_14 ,
. V_56 = V_27 -> V_3 -> V_57 ,
} ;
F_58 ( & V_47 , V_27 , V_14 ) ;
F_17 ( V_14 , V_27 ) ;
F_69 ( F_31 ( & V_49 , 1 , & V_47 , NULL ) ) ;
}
static inline int F_70 ( struct V_2 * V_3 , T_1 V_85 ,
int V_98 )
{
int V_99 = F_71 ( V_3 -> V_76 , V_85 , V_98 ) ;
return V_99 == V_100 || V_99 == V_101 ;
}
static void F_72 ( struct V_2 * V_3 , struct V_18 * V_22 )
{
T_1 V_85 ;
struct V_14 * V_14 ;
struct V_25 * V_27 ;
while ( ( V_14 = F_15 ( V_22 ) ) ) {
V_85 = F_54 ( V_3 -> V_76 , V_14 ) ;
V_27 = F_18 ( V_3 ) ;
if ( F_51 ( F_70 ( V_3 , V_85 , 1 ) ) )
V_27 = F_50 ( V_3 , V_14 -> V_86 . V_87 ) ;
else if ( V_27 && F_19 ( & V_27 -> V_31 ) )
V_27 = NULL ;
if ( F_51 ( V_27 ) )
F_68 ( V_27 , V_14 ) ;
else
F_64 ( V_14 , - V_62 ) ;
}
}
static void F_73 ( unsigned long error , void * V_1 )
{
unsigned V_45 , V_102 = 0 ;
struct V_14 * V_14 = (struct V_14 * ) V_1 ;
struct V_2 * V_3 ;
int V_17 = 0 ;
unsigned long V_16 ;
V_3 = F_16 ( V_14 ) -> V_3 ;
F_17 ( V_14 , NULL ) ;
if ( F_51 ( ! error ) ) {
F_64 ( V_14 , V_102 ) ;
return;
}
if ( V_14 -> V_50 & V_103 ) {
F_64 ( V_14 , - V_104 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_3 -> V_30 ; V_45 ++ )
if ( F_33 ( V_45 , & error ) )
F_23 ( V_3 -> V_25 + V_45 , V_105 ) ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
if ( ! V_3 -> V_106 . V_24 )
V_17 = 1 ;
F_12 ( & V_3 -> V_106 , V_14 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
if ( V_17 )
F_1 ( V_3 ) ;
}
static void F_74 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
unsigned int V_45 ;
struct V_46 V_47 [ V_3 -> V_30 ] , * V_73 = V_47 ;
struct V_25 * V_27 ;
struct V_48 V_49 = {
. V_50 = V_20 | ( V_14 -> V_50 & V_107 ) ,
. V_52 . type = V_95 ,
. V_52 . V_54 . V_14 = V_14 ,
. V_96 . V_97 = F_73 ,
. V_96 . V_1 = V_14 ,
. V_56 = V_3 -> V_57 ,
} ;
if ( V_14 -> V_50 & V_103 ) {
V_49 . V_50 |= V_103 ;
V_49 . V_52 . type = V_53 ;
V_49 . V_52 . V_54 . V_55 = NULL ;
}
for ( V_45 = 0 , V_27 = V_3 -> V_25 ; V_45 < V_3 -> V_30 ; V_45 ++ , V_27 ++ )
F_58 ( V_73 ++ , V_27 , V_14 ) ;
F_17 ( V_14 , F_18 ( V_3 ) ) ;
F_69 ( F_31 ( & V_49 , V_3 -> V_30 , V_47 , NULL ) ) ;
}
static void F_75 ( struct V_2 * V_3 , struct V_18 * V_21 )
{
int V_99 ;
struct V_14 * V_14 ;
struct V_18 V_108 , V_109 , F_38 , * V_110 = NULL ;
struct V_18 V_111 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
T_1 V_85 ;
if ( ! V_21 -> V_24 )
return;
F_76 ( & V_108 ) ;
F_76 ( & V_109 ) ;
F_76 ( & F_38 ) ;
F_76 ( & V_111 ) ;
while ( ( V_14 = F_15 ( V_21 ) ) ) {
if ( ( V_14 -> V_50 & V_112 ) ||
( V_14 -> V_50 & V_103 ) ) {
F_12 ( & V_108 , V_14 ) ;
continue;
}
V_85 = F_54 ( V_3 -> V_76 , V_14 ) ;
if ( log -> type -> V_113 &&
log -> type -> V_113 ( log , V_85 ) ) {
F_12 ( & V_111 , V_14 ) ;
continue;
}
V_99 = F_71 ( V_3 -> V_76 , V_85 , 1 ) ;
switch ( V_99 ) {
case V_100 :
case V_101 :
V_110 = & V_108 ;
break;
case V_114 :
V_110 = & V_109 ;
break;
case V_115 :
V_110 = & F_38 ;
break;
}
F_12 ( V_110 , V_14 ) ;
}
if ( F_32 ( V_111 . V_24 ) ) {
F_61 ( & V_3 -> V_23 ) ;
F_77 ( & V_3 -> V_21 , & V_111 ) ;
F_62 ( & V_3 -> V_23 ) ;
F_5 ( V_3 ) ;
}
F_78 ( V_3 -> V_76 , & V_108 ) ;
F_78 ( V_3 -> V_76 , & V_109 ) ;
V_3 -> V_116 = F_79 ( V_3 -> V_76 ) ? 1 : V_3 -> V_116 ;
if ( F_32 ( V_3 -> V_116 ) && F_25 ( V_3 ) ) {
F_61 ( & V_3 -> V_23 ) ;
F_77 ( & V_3 -> V_106 , & V_108 ) ;
F_62 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
} else
while ( ( V_14 = F_15 ( & V_108 ) ) )
F_74 ( V_3 , V_14 ) ;
while ( ( V_14 = F_15 ( & F_38 ) ) )
F_80 ( V_3 -> V_76 , V_14 ) ;
while ( ( V_14 = F_15 ( & V_109 ) ) ) {
if ( F_32 ( V_3 -> V_35 ) && F_25 ( V_3 ) && ! F_26 ( V_3 ) ) {
F_61 ( & V_3 -> V_23 ) ;
F_12 ( & V_3 -> V_106 , V_14 ) ;
F_62 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
} else {
F_57 ( F_18 ( V_3 ) , V_14 ) ;
F_81 ( V_14 ) ;
}
}
}
static void F_82 ( struct V_2 * V_3 , struct V_18 * V_106 )
{
struct V_14 * V_14 ;
if ( F_51 ( ! V_106 -> V_24 ) )
return;
while ( ( V_14 = F_15 ( V_106 ) ) ) {
if ( ! V_3 -> V_116 ) {
V_3 -> V_37 = 0 ;
F_83 ( V_3 -> V_76 , V_14 ) ;
}
if ( F_32 ( ! F_22 ( V_3 ) || ( F_26 ( V_3 ) && V_3 -> V_116 ) ) )
F_64 ( V_14 , - V_62 ) ;
else if ( F_25 ( V_3 ) && ! F_26 ( V_3 ) )
F_60 ( V_3 , V_14 ) ;
else
F_64 ( V_14 , 0 ) ;
}
}
static void V_40 ( struct V_117 * V_118 )
{
struct V_2 * V_3 =
F_84 ( V_118 , struct V_2 , V_40 ) ;
F_49 ( V_3 -> V_42 -> V_84 ) ;
}
static void F_85 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = F_84 ( V_118 , struct V_2 ,
V_5 ) ;
struct V_18 V_22 , V_21 , V_106 ;
unsigned long V_16 ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
V_22 = V_3 -> V_22 ;
V_21 = V_3 -> V_21 ;
V_106 = V_3 -> V_106 ;
F_76 ( & V_3 -> V_22 ) ;
F_76 ( & V_3 -> V_21 ) ;
F_76 ( & V_3 -> V_106 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
F_86 ( V_3 -> V_76 , F_25 ( V_3 ) ) ;
F_45 ( V_3 ) ;
F_72 ( V_3 , & V_22 ) ;
F_75 ( V_3 , & V_21 ) ;
F_82 ( V_3 , & V_106 ) ;
}
static struct V_2 * F_87 ( unsigned int V_30 ,
T_3 V_75 ,
struct V_41 * V_42 ,
struct V_82 * V_119 )
{
T_4 V_79 ;
struct V_2 * V_3 = NULL ;
V_79 = sizeof( * V_3 ) + ( sizeof( V_3 -> V_25 [ 0 ] ) * V_30 ) ;
V_3 = F_88 ( V_79 , V_120 ) ;
if ( ! V_3 ) {
V_42 -> error = L_9 ;
return NULL ;
}
F_89 ( & V_3 -> V_23 ) ;
F_76 ( & V_3 -> V_22 ) ;
F_76 ( & V_3 -> V_21 ) ;
F_76 ( & V_3 -> V_106 ) ;
F_76 ( & V_3 -> V_92 ) ;
V_3 -> V_42 = V_42 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_78 = F_90 ( V_42 -> V_79 , V_75 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_116 = 0 ;
V_3 -> V_35 = 0 ;
F_21 ( & V_3 -> V_90 , 0 ) ;
F_21 ( & V_3 -> V_28 , V_121 ) ;
V_3 -> V_57 = F_91 () ;
if ( F_92 ( V_3 -> V_57 ) ) {
V_42 -> error = L_10 ;
F_93 ( V_3 ) ;
return NULL ;
}
V_3 -> V_76 = F_94 ( V_3 , F_14 , F_1 ,
F_8 ,
V_3 -> V_42 -> V_122 , V_123 ,
V_119 , V_75 , V_3 -> V_78 ) ;
if ( F_92 ( V_3 -> V_76 ) ) {
V_42 -> error = L_11 ;
F_95 ( V_3 -> V_57 ) ;
F_93 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static void F_96 ( struct V_2 * V_3 , struct V_41 * V_42 ,
unsigned int V_27 )
{
while ( V_27 -- )
F_97 ( V_42 , V_3 -> V_25 [ V_27 ] . V_38 ) ;
F_95 ( V_3 -> V_57 ) ;
F_98 ( V_3 -> V_76 ) ;
F_93 ( V_3 ) ;
}
static int F_99 ( struct V_2 * V_3 , struct V_41 * V_42 ,
unsigned int V_25 , char * * V_124 )
{
unsigned long long V_77 ;
char V_125 ;
if ( sscanf ( V_124 [ 1 ] , L_12 , & V_77 , & V_125 ) != 1 ) {
V_42 -> error = L_13 ;
return - V_126 ;
}
if ( F_100 ( V_42 , V_124 [ 0 ] , F_101 ( V_42 -> V_84 ) ,
& V_3 -> V_25 [ V_25 ] . V_38 ) ) {
V_42 -> error = L_14 ;
return - V_127 ;
}
V_3 -> V_25 [ V_25 ] . V_3 = V_3 ;
F_21 ( & ( V_3 -> V_25 [ V_25 ] . V_31 ) , 0 ) ;
V_3 -> V_25 [ V_25 ] . V_33 = 0 ;
V_3 -> V_25 [ V_25 ] . V_77 = V_77 ;
return 0 ;
}
static struct V_82 * F_102 ( struct V_41 * V_42 ,
unsigned V_128 , char * * V_124 ,
unsigned * V_129 )
{
unsigned V_130 ;
struct V_82 * V_119 ;
char V_125 ;
if ( V_128 < 2 ) {
V_42 -> error = L_15 ;
return NULL ;
}
if ( sscanf ( V_124 [ 1 ] , L_16 , & V_130 , & V_125 ) != 1 ) {
V_42 -> error = L_17 ;
return NULL ;
}
* V_129 = 2 + V_130 ;
if ( V_128 < * V_129 ) {
V_42 -> error = L_15 ;
return NULL ;
}
V_119 = F_103 ( V_124 [ 0 ] , V_42 , F_30 , V_130 ,
V_124 + 2 ) ;
if ( ! V_119 ) {
V_42 -> error = L_18 ;
return NULL ;
}
return V_119 ;
}
static int F_104 ( struct V_2 * V_3 , unsigned V_128 , char * * V_124 ,
unsigned * V_129 )
{
unsigned V_131 ;
struct V_41 * V_42 = V_3 -> V_42 ;
char V_125 ;
int V_45 ;
* V_129 = 0 ;
if ( ! V_128 )
return 0 ;
if ( sscanf ( V_124 [ 0 ] , L_16 , & V_131 , & V_125 ) != 1 ) {
V_42 -> error = L_19 ;
return - V_126 ;
}
V_128 -- ;
V_124 ++ ;
( * V_129 ) ++ ;
if ( V_131 > V_128 ) {
V_42 -> error = L_20 ;
return - V_126 ;
}
for ( V_45 = 0 ; V_45 < V_131 ; V_45 ++ ) {
if ( ! strcmp ( L_21 , V_124 [ 0 ] ) )
V_3 -> V_132 |= V_133 ;
else if ( ! strcmp ( L_22 , V_124 [ 0 ] ) )
V_3 -> V_132 |= V_134 ;
else {
V_42 -> error = L_23 ;
return - V_126 ;
}
V_128 -- ;
V_124 ++ ;
( * V_129 ) ++ ;
}
if ( ! F_25 ( V_3 ) && F_26 ( V_3 ) ) {
V_42 -> error = L_24 ;
return - V_126 ;
}
return 0 ;
}
static int F_105 ( struct V_41 * V_42 , unsigned int V_128 , char * * V_124 )
{
int V_69 ;
unsigned int V_30 , V_27 , V_129 ;
struct V_2 * V_3 ;
struct V_82 * V_119 ;
char V_125 ;
V_119 = F_102 ( V_42 , V_128 , V_124 , & V_129 ) ;
if ( ! V_119 )
return - V_126 ;
V_124 += V_129 ;
V_128 -= V_129 ;
if ( ! V_128 || sscanf ( V_124 [ 0 ] , L_16 , & V_30 , & V_125 ) != 1 ||
V_30 < 2 || V_30 > V_72 + 1 ) {
V_42 -> error = L_25 ;
F_106 ( V_119 ) ;
return - V_126 ;
}
V_124 ++ , V_128 -- ;
if ( V_128 < V_30 * 2 ) {
V_42 -> error = L_26 ;
F_106 ( V_119 ) ;
return - V_126 ;
}
V_3 = F_87 ( V_30 , V_119 -> type -> V_135 ( V_119 ) , V_42 , V_119 ) ;
if ( ! V_3 ) {
F_106 ( V_119 ) ;
return - V_136 ;
}
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
V_69 = F_99 ( V_3 , V_42 , V_27 , V_124 ) ;
if ( V_69 ) {
F_96 ( V_3 , V_42 , V_27 ) ;
return V_69 ;
}
V_124 += 2 ;
V_128 -= 2 ;
}
V_42 -> V_43 = V_3 ;
V_69 = F_107 ( V_42 , F_40 ( V_3 -> V_76 ) ) ;
if ( V_69 )
goto V_137;
V_42 -> V_138 = 1 ;
V_42 -> V_139 = 1 ;
V_42 -> V_140 = sizeof( struct V_141 ) ;
V_42 -> V_142 = true ;
V_3 -> V_4 = F_108 ( L_27 , V_143 , 0 ) ;
if ( ! V_3 -> V_4 ) {
F_27 ( L_28 ) ;
V_69 = - V_136 ;
goto V_137;
}
F_109 ( & V_3 -> V_5 , F_85 ) ;
F_110 ( & V_3 -> V_8 ) ;
V_3 -> V_7 = 0 ;
F_109 ( & V_3 -> V_40 , V_40 ) ;
V_69 = F_104 ( V_3 , V_128 , V_124 , & V_129 ) ;
if ( V_69 )
goto V_144;
V_124 += V_129 ;
V_128 -= V_129 ;
if ( V_128 ) {
V_42 -> error = L_29 ;
V_69 = - V_126 ;
goto V_144;
}
V_3 -> V_81 = F_111 ( & V_145 ) ;
if ( F_92 ( V_3 -> V_81 ) ) {
V_69 = F_112 ( V_3 -> V_81 ) ;
goto V_144;
}
F_1 ( V_3 ) ;
return 0 ;
V_144:
F_113 ( V_3 -> V_4 ) ;
V_137:
F_96 ( V_3 , V_42 , V_3 -> V_30 ) ;
return V_69 ;
}
static void F_114 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
F_115 ( & V_3 -> V_8 ) ;
F_116 ( V_3 -> V_4 ) ;
F_117 ( & V_3 -> V_40 ) ;
F_118 ( V_3 -> V_81 ) ;
F_113 ( V_3 -> V_4 ) ;
F_96 ( V_3 , V_42 , V_3 -> V_30 ) ;
}
static int F_119 ( struct V_41 * V_42 , struct V_14 * V_14 )
{
int V_69 , V_15 = F_67 ( V_14 ) ;
struct V_25 * V_27 ;
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
struct V_141 * V_146 =
F_120 ( V_14 , sizeof( struct V_141 ) ) ;
V_146 -> V_147 . V_89 = NULL ;
if ( V_15 == V_20 ) {
V_146 -> V_148 = F_54 ( V_3 -> V_76 , V_14 ) ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_149 ;
}
V_69 = log -> type -> V_37 ( log , F_54 ( V_3 -> V_76 , V_14 ) , 0 ) ;
if ( V_69 < 0 && V_69 != - V_150 )
return V_69 ;
if ( ! V_69 || ( V_69 == - V_150 ) ) {
if ( V_15 == V_151 )
return - V_150 ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_149 ;
}
V_27 = F_50 ( V_3 , V_14 -> V_86 . V_87 ) ;
if ( F_32 ( ! V_27 ) )
return - V_62 ;
F_121 ( & V_146 -> V_147 , V_14 ) ;
V_146 -> V_27 = V_27 ;
F_57 ( V_27 , V_14 ) ;
return V_152 ;
}
static int F_122 ( struct V_41 * V_42 , struct V_14 * V_14 , int error )
{
int V_15 = F_67 ( V_14 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_25 * V_27 = NULL ;
struct V_153 * V_154 = NULL ;
struct V_141 * V_146 =
F_120 ( V_14 , sizeof( struct V_141 ) ) ;
if ( V_15 == V_20 ) {
if ( ! ( V_14 -> V_50 & ( V_112 | V_103 ) ) )
F_123 ( V_3 -> V_76 , V_146 -> V_148 ) ;
return error ;
}
if ( error == - V_104 )
goto V_36;
if ( ( error == - V_150 ) && ( V_14 -> V_50 & V_155 ) )
goto V_36;
if ( F_32 ( error ) ) {
if ( ! V_146 -> V_147 . V_89 ) {
F_36 ( L_30 ) ;
return - V_62 ;
}
V_27 = V_146 -> V_27 ;
F_27 ( L_31 ,
V_27 -> V_38 -> V_39 ) ;
F_23 ( V_27 , V_93 ) ;
if ( F_52 ( V_27 ) || F_53 ( V_3 , V_14 ) ) {
V_154 = & V_146 -> V_147 ;
F_124 ( V_154 , V_14 ) ;
V_146 -> V_147 . V_89 = NULL ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_156 ;
}
F_27 ( L_32 ) ;
}
V_36:
V_146 -> V_147 . V_89 = NULL ;
return error ;
}
static void F_125 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
struct V_18 V_92 ;
struct V_14 * V_14 ;
F_21 ( & V_3 -> V_90 , 1 ) ;
F_61 ( & V_3 -> V_23 ) ;
V_92 = V_3 -> V_92 ;
F_76 ( & V_3 -> V_92 ) ;
F_62 ( & V_3 -> V_23 ) ;
while ( ( V_14 = F_15 ( & V_92 ) ) )
F_60 ( V_3 , V_14 ) ;
F_126 ( V_3 -> V_76 ) ;
F_127 ( V_13 ,
! F_128 ( V_3 -> V_76 ) ) ;
if ( log -> type -> V_157 && log -> type -> V_157 ( log ) )
F_28 ( L_33 ) ;
F_116 ( V_3 -> V_4 ) ;
}
static void F_129 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
if ( log -> type -> V_158 && log -> type -> V_158 ( log ) )
F_28 ( L_34 ) ;
}
static void F_130 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
F_21 ( & V_3 -> V_90 , 0 ) ;
if ( log -> type -> V_159 && log -> type -> V_159 ( log ) )
F_28 ( L_35 ) ;
F_131 ( V_3 -> V_76 ) ;
}
static char F_132 ( struct V_25 * V_27 )
{
if ( ! F_19 ( & ( V_27 -> V_31 ) ) )
return 'A' ;
return ( F_33 ( V_61 , & ( V_27 -> V_33 ) ) ) ? 'F' :
( F_33 ( V_105 , & ( V_27 -> V_33 ) ) ) ? 'D' :
( F_33 ( V_68 , & ( V_27 -> V_33 ) ) ) ? 'S' :
( F_33 ( V_93 , & ( V_27 -> V_33 ) ) ) ? 'R' : 'U' ;
}
static void F_133 ( struct V_41 * V_42 , T_5 type ,
unsigned V_160 , char * V_161 , unsigned V_162 )
{
unsigned int V_27 , V_163 = 0 ;
int V_164 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_82 * log = F_46 ( V_3 -> V_76 ) ;
char V_165 [ V_3 -> V_30 + 1 ] ;
switch ( type ) {
case V_166 :
F_134 ( L_36 , V_3 -> V_30 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
F_134 ( L_37 , V_3 -> V_25 [ V_27 ] . V_38 -> V_39 ) ;
V_165 [ V_27 ] = F_132 ( & ( V_3 -> V_25 [ V_27 ] ) ) ;
}
V_165 [ V_27 ] = '\0' ;
F_134 ( L_38 ,
( unsigned long long ) log -> type -> V_83 ( log ) ,
( unsigned long long ) V_3 -> V_78 , V_165 ) ;
V_163 += log -> type -> V_167 ( log , type , V_161 + V_163 , V_162 - V_163 ) ;
break;
case V_168 :
V_163 = log -> type -> V_167 ( log , type , V_161 , V_162 ) ;
F_134 ( L_39 , V_3 -> V_30 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ )
F_134 ( L_40 , V_3 -> V_25 [ V_27 ] . V_38 -> V_39 ,
( unsigned long long ) V_3 -> V_25 [ V_27 ] . V_77 ) ;
V_164 += ! ! F_25 ( V_3 ) ;
V_164 += ! ! F_26 ( V_3 ) ;
if ( V_164 ) {
F_134 ( L_41 , V_164 ) ;
if ( F_25 ( V_3 ) )
F_134 ( L_42 ) ;
if ( F_26 ( V_3 ) )
F_134 ( L_43 ) ;
}
break;
}
}
static int F_135 ( struct V_41 * V_42 ,
T_6 V_97 , void * V_6 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
int V_102 = 0 ;
unsigned V_45 ;
for ( V_45 = 0 ; ! V_102 && V_45 < V_3 -> V_30 ; V_45 ++ )
V_102 = V_97 ( V_42 , V_3 -> V_25 [ V_45 ] . V_38 ,
V_3 -> V_25 [ V_45 ] . V_77 , V_42 -> V_79 , V_6 ) ;
return V_102 ;
}
static int T_7 F_136 ( void )
{
int V_69 ;
V_69 = F_137 ( & V_169 ) ;
if ( V_69 < 0 ) {
F_27 ( L_44 ) ;
goto V_170;
}
return 0 ;
V_170:
return V_69 ;
}
static void T_8 F_138 ( void )
{
F_139 ( & V_169 ) ;
}
