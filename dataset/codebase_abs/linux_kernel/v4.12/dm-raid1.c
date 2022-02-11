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
. V_52 = V_53 | V_54 ,
. V_55 . type = V_56 ,
. V_55 . V_57 . V_58 = NULL ,
. V_59 = V_3 -> V_60 ,
} ;
for ( V_45 = 0 , V_27 = V_3 -> V_25 ; V_45 < V_3 -> V_30 ; V_45 ++ , V_27 ++ ) {
V_47 [ V_45 ] . V_61 = V_27 -> V_38 -> V_61 ;
V_47 [ V_45 ] . V_62 = 0 ;
V_47 [ V_45 ] . V_63 = 0 ;
}
V_44 = - 1 ;
F_31 ( & V_49 , V_3 -> V_30 , V_47 , & V_44 ) ;
if ( F_32 ( V_44 != 0 ) ) {
for ( V_45 = 0 ; V_45 < V_3 -> V_30 ; V_45 ++ )
if ( F_33 ( V_45 , & V_44 ) )
F_23 ( V_3 -> V_25 + V_45 ,
V_64 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_34 ( int V_66 , unsigned long V_67 ,
void * V_1 )
{
struct V_68 * V_69 = V_1 ;
struct V_2 * V_3 = F_35 ( V_69 ) ;
int V_27 , V_70 = 0 ;
if ( V_66 ) {
F_36 ( L_4 ) ;
F_23 ( F_18 ( V_3 ) , V_71 ) ;
}
if ( V_67 ) {
F_36 ( L_5 ,
V_67 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
if ( & V_3 -> V_25 [ V_27 ] == F_18 ( V_3 ) )
continue;
if ( F_33 ( V_70 , & V_67 ) )
F_23 ( V_3 -> V_25 + V_27 ,
V_71 ) ;
V_70 ++ ;
}
}
F_37 ( V_69 , ! ( V_66 || V_67 ) ) ;
}
static int F_38 ( struct V_2 * V_3 , struct V_68 * V_69 )
{
int V_72 ;
unsigned V_45 ;
struct V_46 V_73 , V_74 [ V_75 ] , * V_76 ;
struct V_25 * V_27 ;
unsigned long V_16 = 0 ;
T_1 V_77 = F_39 ( V_69 ) ;
T_2 V_78 = F_40 ( V_3 -> V_79 ) ;
V_27 = F_18 ( V_3 ) ;
V_73 . V_61 = V_27 -> V_38 -> V_61 ;
V_73 . V_62 = V_27 -> V_80 + F_41 ( V_3 -> V_79 , V_77 ) ;
if ( V_77 == ( V_3 -> V_81 - 1 ) ) {
V_73 . V_63 = V_3 -> V_42 -> V_82 & ( V_78 - 1 ) ;
if ( ! V_73 . V_63 )
V_73 . V_63 = V_78 ;
} else
V_73 . V_63 = V_78 ;
for ( V_45 = 0 , V_76 = V_74 ; V_45 < V_3 -> V_30 ; V_45 ++ ) {
if ( & V_3 -> V_25 [ V_45 ] == F_18 ( V_3 ) )
continue;
V_27 = V_3 -> V_25 + V_45 ;
V_76 -> V_61 = V_27 -> V_38 -> V_61 ;
V_76 -> V_62 = V_27 -> V_80 + F_41 ( V_3 -> V_79 , V_77 ) ;
V_76 -> V_63 = V_73 . V_63 ;
V_76 ++ ;
}
if ( ! F_25 ( V_3 ) )
F_42 ( V_83 , & V_16 ) ;
V_72 = F_43 ( V_3 -> V_84 , & V_73 , V_3 -> V_30 - 1 , V_74 ,
V_16 , F_34 , V_69 ) ;
return V_72 ;
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
struct V_68 * V_69 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
int V_72 ;
F_47 ( V_3 -> V_79 ) ;
while ( ( V_69 = F_48 ( V_3 -> V_79 ) ) ) {
V_72 = F_38 ( V_3 , V_69 ) ;
if ( V_72 )
F_37 ( V_69 , 0 ) ;
}
if ( ! V_3 -> V_37 &&
( log -> type -> V_86 ( log ) == V_3 -> V_81 ) ) {
F_49 ( V_3 -> V_42 -> V_87 ) ;
V_3 -> V_37 = 1 ;
F_44 ( V_3 ) ;
}
}
static struct V_25 * F_50 ( struct V_2 * V_3 , T_2 V_62 )
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
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
T_1 V_88 = F_54 ( V_3 -> V_79 , V_14 ) ;
if ( log -> type -> V_37 ( log , V_88 , 0 ) )
return F_50 ( V_3 , V_14 -> V_89 . V_90 ) ? 1 : 0 ;
return 0 ;
}
static T_2 F_55 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
if ( F_32 ( ! V_14 -> V_89 . V_91 ) )
return 0 ;
return V_27 -> V_80 + F_56 ( V_27 -> V_3 -> V_42 , V_14 -> V_89 . V_90 ) ;
}
static void F_57 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
V_14 -> V_92 = V_27 -> V_38 -> V_61 ;
V_14 -> V_89 . V_90 = F_55 ( V_27 , V_14 ) ;
}
static void F_58 ( struct V_46 * V_47 , struct V_25 * V_27 ,
struct V_14 * V_14 )
{
V_47 -> V_61 = V_27 -> V_38 -> V_61 ;
V_47 -> V_62 = F_55 ( V_27 , V_14 ) ;
V_47 -> V_63 = F_59 ( V_14 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
F_61 ( & V_3 -> V_23 ) ;
if ( F_19 ( & V_3 -> V_93 ) ) {
F_62 ( & V_3 -> V_23 ) ;
if ( F_63 ( V_3 -> V_42 ) )
V_14 -> V_94 = V_95 ;
else
V_14 -> V_94 = - V_65 ;
F_64 ( V_14 ) ;
return;
}
F_12 ( & V_3 -> V_96 , V_14 ) ;
F_62 ( & V_3 -> V_23 ) ;
}
static void F_65 ( unsigned long error , void * V_1 )
{
struct V_14 * V_14 = V_1 ;
struct V_25 * V_27 ;
V_27 = F_16 ( V_14 ) ;
F_17 ( V_14 , NULL ) ;
if ( F_51 ( ! error ) ) {
F_64 ( V_14 ) ;
return;
}
F_23 ( V_27 , V_97 ) ;
if ( F_51 ( F_52 ( V_27 ) ) || F_53 ( V_27 -> V_3 , V_14 ) ) {
F_66 ( L_6
L_7 ,
V_27 -> V_38 -> V_39 ) ;
F_10 ( V_27 -> V_3 , V_14 , F_67 ( V_14 ) ) ;
return;
}
F_36 ( L_8 ,
V_27 -> V_38 -> V_39 ) ;
F_68 ( V_14 ) ;
}
static void F_69 ( struct V_25 * V_27 , struct V_14 * V_14 )
{
struct V_46 V_47 ;
struct V_48 V_49 = {
. V_50 = V_98 ,
. V_52 = 0 ,
. V_55 . type = V_99 ,
. V_55 . V_57 . V_14 = V_14 ,
. V_100 . V_101 = F_65 ,
. V_100 . V_1 = V_14 ,
. V_59 = V_27 -> V_3 -> V_60 ,
} ;
F_58 ( & V_47 , V_27 , V_14 ) ;
F_17 ( V_14 , V_27 ) ;
F_70 ( F_31 ( & V_49 , 1 , & V_47 , NULL ) ) ;
}
static inline int F_71 ( struct V_2 * V_3 , T_1 V_88 ,
int V_102 )
{
int V_103 = F_72 ( V_3 -> V_79 , V_88 , V_102 ) ;
return V_103 == V_104 || V_103 == V_105 ;
}
static void F_73 ( struct V_2 * V_3 , struct V_18 * V_22 )
{
T_1 V_88 ;
struct V_14 * V_14 ;
struct V_25 * V_27 ;
while ( ( V_14 = F_15 ( V_22 ) ) ) {
V_88 = F_54 ( V_3 -> V_79 , V_14 ) ;
V_27 = F_18 ( V_3 ) ;
if ( F_51 ( F_71 ( V_3 , V_88 , 1 ) ) )
V_27 = F_50 ( V_3 , V_14 -> V_89 . V_90 ) ;
else if ( V_27 && F_19 ( & V_27 -> V_31 ) )
V_27 = NULL ;
if ( F_51 ( V_27 ) )
F_69 ( V_27 , V_14 ) ;
else
F_68 ( V_14 ) ;
}
}
static void F_74 ( unsigned long error , void * V_1 )
{
unsigned V_45 ;
struct V_14 * V_14 = (struct V_14 * ) V_1 ;
struct V_2 * V_3 ;
int V_17 = 0 ;
unsigned long V_16 ;
V_3 = F_16 ( V_14 ) -> V_3 ;
F_17 ( V_14 , NULL ) ;
if ( F_51 ( ! error ) ) {
F_64 ( V_14 ) ;
return;
}
if ( F_75 ( V_14 ) == V_106 ) {
V_14 -> V_94 = - V_107 ;
F_64 ( V_14 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_3 -> V_30 ; V_45 ++ )
if ( F_33 ( V_45 , & error ) )
F_23 ( V_3 -> V_25 + V_45 , V_108 ) ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
if ( ! V_3 -> V_109 . V_24 )
V_17 = 1 ;
F_12 ( & V_3 -> V_109 , V_14 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
if ( V_17 )
F_1 ( V_3 ) ;
}
static void F_76 ( struct V_2 * V_3 , struct V_14 * V_14 )
{
unsigned int V_45 ;
struct V_46 V_47 [ V_3 -> V_30 ] , * V_76 = V_47 ;
struct V_25 * V_27 ;
struct V_48 V_49 = {
. V_50 = V_51 ,
. V_52 = V_14 -> V_110 & ( V_111 | V_53 ) ,
. V_55 . type = V_99 ,
. V_55 . V_57 . V_14 = V_14 ,
. V_100 . V_101 = F_74 ,
. V_100 . V_1 = V_14 ,
. V_59 = V_3 -> V_60 ,
} ;
if ( F_75 ( V_14 ) == V_106 ) {
V_49 . V_50 = V_106 ;
V_49 . V_55 . type = V_56 ;
V_49 . V_55 . V_57 . V_58 = NULL ;
}
for ( V_45 = 0 , V_27 = V_3 -> V_25 ; V_45 < V_3 -> V_30 ; V_45 ++ , V_27 ++ )
F_58 ( V_76 ++ , V_27 , V_14 ) ;
F_17 ( V_14 , F_18 ( V_3 ) ) ;
F_70 ( F_31 ( & V_49 , V_3 -> V_30 , V_47 , NULL ) ) ;
}
static void F_77 ( struct V_2 * V_3 , struct V_18 * V_21 )
{
int V_103 ;
struct V_14 * V_14 ;
struct V_18 V_112 , V_113 , F_38 , * V_114 = NULL ;
struct V_18 V_115 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
T_1 V_88 ;
if ( ! V_21 -> V_24 )
return;
F_78 ( & V_112 ) ;
F_78 ( & V_113 ) ;
F_78 ( & F_38 ) ;
F_78 ( & V_115 ) ;
while ( ( V_14 = F_15 ( V_21 ) ) ) {
if ( ( V_14 -> V_110 & V_53 ) ||
( F_75 ( V_14 ) == V_106 ) ) {
F_12 ( & V_112 , V_14 ) ;
continue;
}
V_88 = F_54 ( V_3 -> V_79 , V_14 ) ;
if ( log -> type -> V_116 &&
log -> type -> V_116 ( log , V_88 ) ) {
F_12 ( & V_115 , V_14 ) ;
continue;
}
V_103 = F_72 ( V_3 -> V_79 , V_88 , 1 ) ;
switch ( V_103 ) {
case V_104 :
case V_105 :
V_114 = & V_112 ;
break;
case V_117 :
V_114 = & V_113 ;
break;
case V_118 :
V_114 = & F_38 ;
break;
}
F_12 ( V_114 , V_14 ) ;
}
if ( F_32 ( V_115 . V_24 ) ) {
F_61 ( & V_3 -> V_23 ) ;
F_79 ( & V_3 -> V_21 , & V_115 ) ;
F_62 ( & V_3 -> V_23 ) ;
F_5 ( V_3 ) ;
}
F_80 ( V_3 -> V_79 , & V_112 ) ;
F_80 ( V_3 -> V_79 , & V_113 ) ;
V_3 -> V_119 = F_81 ( V_3 -> V_79 ) ? 1 : V_3 -> V_119 ;
if ( F_32 ( V_3 -> V_119 ) && F_25 ( V_3 ) ) {
F_61 ( & V_3 -> V_23 ) ;
F_79 ( & V_3 -> V_109 , & V_112 ) ;
F_62 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
} else
while ( ( V_14 = F_15 ( & V_112 ) ) )
F_76 ( V_3 , V_14 ) ;
while ( ( V_14 = F_15 ( & F_38 ) ) )
F_82 ( V_3 -> V_79 , V_14 ) ;
while ( ( V_14 = F_15 ( & V_113 ) ) ) {
if ( F_32 ( V_3 -> V_35 ) && F_25 ( V_3 ) && ! F_26 ( V_3 ) ) {
F_61 ( & V_3 -> V_23 ) ;
F_12 ( & V_3 -> V_109 , V_14 ) ;
F_62 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
} else {
F_57 ( F_18 ( V_3 ) , V_14 ) ;
F_83 ( V_14 ) ;
}
}
}
static void F_84 ( struct V_2 * V_3 , struct V_18 * V_109 )
{
struct V_14 * V_14 ;
if ( F_51 ( ! V_109 -> V_24 ) )
return;
while ( ( V_14 = F_15 ( V_109 ) ) ) {
if ( ! V_3 -> V_119 ) {
V_3 -> V_37 = 0 ;
F_85 ( V_3 -> V_79 , V_14 ) ;
}
if ( F_32 ( ! F_22 ( V_3 ) || ( F_26 ( V_3 ) && V_3 -> V_119 ) ) )
F_68 ( V_14 ) ;
else if ( F_25 ( V_3 ) && ! F_26 ( V_3 ) )
F_60 ( V_3 , V_14 ) ;
else
F_64 ( V_14 ) ;
}
}
static void V_40 ( struct V_120 * V_121 )
{
struct V_2 * V_3 =
F_86 ( V_121 , struct V_2 , V_40 ) ;
F_49 ( V_3 -> V_42 -> V_87 ) ;
}
static void F_87 ( struct V_120 * V_121 )
{
struct V_2 * V_3 = F_86 ( V_121 , struct V_2 ,
V_5 ) ;
struct V_18 V_22 , V_21 , V_109 ;
unsigned long V_16 ;
F_11 ( & V_3 -> V_23 , V_16 ) ;
V_22 = V_3 -> V_22 ;
V_21 = V_3 -> V_21 ;
V_109 = V_3 -> V_109 ;
F_78 ( & V_3 -> V_22 ) ;
F_78 ( & V_3 -> V_21 ) ;
F_78 ( & V_3 -> V_109 ) ;
F_13 ( & V_3 -> V_23 , V_16 ) ;
F_88 ( V_3 -> V_79 , F_25 ( V_3 ) ) ;
F_45 ( V_3 ) ;
F_73 ( V_3 , & V_22 ) ;
F_77 ( V_3 , & V_21 ) ;
F_84 ( V_3 , & V_109 ) ;
}
static struct V_2 * F_89 ( unsigned int V_30 ,
T_3 V_78 ,
struct V_41 * V_42 ,
struct V_85 * V_122 )
{
T_4 V_82 ;
struct V_2 * V_3 = NULL ;
V_82 = sizeof( * V_3 ) + ( sizeof( V_3 -> V_25 [ 0 ] ) * V_30 ) ;
V_3 = F_90 ( V_82 , V_123 ) ;
if ( ! V_3 ) {
V_42 -> error = L_9 ;
return NULL ;
}
F_91 ( & V_3 -> V_23 ) ;
F_78 ( & V_3 -> V_22 ) ;
F_78 ( & V_3 -> V_21 ) ;
F_78 ( & V_3 -> V_109 ) ;
F_78 ( & V_3 -> V_96 ) ;
V_3 -> V_42 = V_42 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_81 = F_92 ( V_42 -> V_82 , V_78 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_119 = 0 ;
V_3 -> V_35 = 0 ;
F_21 ( & V_3 -> V_93 , 0 ) ;
F_21 ( & V_3 -> V_28 , V_124 ) ;
V_3 -> V_60 = F_93 () ;
if ( F_94 ( V_3 -> V_60 ) ) {
V_42 -> error = L_10 ;
F_95 ( V_3 ) ;
return NULL ;
}
V_3 -> V_79 = F_96 ( V_3 , F_14 , F_1 ,
F_8 ,
V_3 -> V_42 -> V_125 , V_126 ,
V_122 , V_78 , V_3 -> V_81 ) ;
if ( F_94 ( V_3 -> V_79 ) ) {
V_42 -> error = L_11 ;
F_97 ( V_3 -> V_60 ) ;
F_95 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
static void F_98 ( struct V_2 * V_3 , struct V_41 * V_42 ,
unsigned int V_27 )
{
while ( V_27 -- )
F_99 ( V_42 , V_3 -> V_25 [ V_27 ] . V_38 ) ;
F_97 ( V_3 -> V_60 ) ;
F_100 ( V_3 -> V_79 ) ;
F_95 ( V_3 ) ;
}
static int F_101 ( struct V_2 * V_3 , struct V_41 * V_42 ,
unsigned int V_25 , char * * V_127 )
{
unsigned long long V_80 ;
char V_128 ;
int V_129 ;
if ( sscanf ( V_127 [ 1 ] , L_12 , & V_80 , & V_128 ) != 1 ) {
V_42 -> error = L_13 ;
return - V_130 ;
}
V_129 = F_102 ( V_42 , V_127 [ 0 ] , F_103 ( V_42 -> V_87 ) ,
& V_3 -> V_25 [ V_25 ] . V_38 ) ;
if ( V_129 ) {
V_42 -> error = L_14 ;
return V_129 ;
}
V_3 -> V_25 [ V_25 ] . V_3 = V_3 ;
F_21 ( & ( V_3 -> V_25 [ V_25 ] . V_31 ) , 0 ) ;
V_3 -> V_25 [ V_25 ] . V_33 = 0 ;
V_3 -> V_25 [ V_25 ] . V_80 = V_80 ;
return 0 ;
}
static struct V_85 * F_104 ( struct V_41 * V_42 ,
unsigned V_131 , char * * V_127 ,
unsigned * V_132 )
{
unsigned V_133 ;
struct V_85 * V_122 ;
char V_128 ;
if ( V_131 < 2 ) {
V_42 -> error = L_15 ;
return NULL ;
}
if ( sscanf ( V_127 [ 1 ] , L_16 , & V_133 , & V_128 ) != 1 ) {
V_42 -> error = L_17 ;
return NULL ;
}
* V_132 = 2 + V_133 ;
if ( V_131 < * V_132 ) {
V_42 -> error = L_15 ;
return NULL ;
}
V_122 = F_105 ( V_127 [ 0 ] , V_42 , F_30 , V_133 ,
V_127 + 2 ) ;
if ( ! V_122 ) {
V_42 -> error = L_18 ;
return NULL ;
}
return V_122 ;
}
static int F_106 ( struct V_2 * V_3 , unsigned V_131 , char * * V_127 ,
unsigned * V_132 )
{
unsigned V_134 ;
struct V_41 * V_42 = V_3 -> V_42 ;
char V_128 ;
int V_45 ;
* V_132 = 0 ;
if ( ! V_131 )
return 0 ;
if ( sscanf ( V_127 [ 0 ] , L_16 , & V_134 , & V_128 ) != 1 ) {
V_42 -> error = L_19 ;
return - V_130 ;
}
V_131 -- ;
V_127 ++ ;
( * V_132 ) ++ ;
if ( V_134 > V_131 ) {
V_42 -> error = L_20 ;
return - V_130 ;
}
for ( V_45 = 0 ; V_45 < V_134 ; V_45 ++ ) {
if ( ! strcmp ( L_21 , V_127 [ 0 ] ) )
V_3 -> V_135 |= V_136 ;
else if ( ! strcmp ( L_22 , V_127 [ 0 ] ) )
V_3 -> V_135 |= V_137 ;
else {
V_42 -> error = L_23 ;
return - V_130 ;
}
V_131 -- ;
V_127 ++ ;
( * V_132 ) ++ ;
}
if ( ! F_25 ( V_3 ) && F_26 ( V_3 ) ) {
V_42 -> error = L_24 ;
return - V_130 ;
}
return 0 ;
}
static int F_107 ( struct V_41 * V_42 , unsigned int V_131 , char * * V_127 )
{
int V_72 ;
unsigned int V_30 , V_27 , V_132 ;
struct V_2 * V_3 ;
struct V_85 * V_122 ;
char V_128 ;
V_122 = F_104 ( V_42 , V_131 , V_127 , & V_132 ) ;
if ( ! V_122 )
return - V_130 ;
V_127 += V_132 ;
V_131 -= V_132 ;
if ( ! V_131 || sscanf ( V_127 [ 0 ] , L_16 , & V_30 , & V_128 ) != 1 ||
V_30 < 2 || V_30 > V_75 + 1 ) {
V_42 -> error = L_25 ;
F_108 ( V_122 ) ;
return - V_130 ;
}
V_127 ++ , V_131 -- ;
if ( V_131 < V_30 * 2 ) {
V_42 -> error = L_26 ;
F_108 ( V_122 ) ;
return - V_130 ;
}
V_3 = F_89 ( V_30 , V_122 -> type -> V_138 ( V_122 ) , V_42 , V_122 ) ;
if ( ! V_3 ) {
F_108 ( V_122 ) ;
return - V_139 ;
}
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
V_72 = F_101 ( V_3 , V_42 , V_27 , V_127 ) ;
if ( V_72 ) {
F_98 ( V_3 , V_42 , V_27 ) ;
return V_72 ;
}
V_127 += 2 ;
V_131 -= 2 ;
}
V_42 -> V_43 = V_3 ;
V_72 = F_109 ( V_42 , F_40 ( V_3 -> V_79 ) ) ;
if ( V_72 )
goto V_140;
V_42 -> V_141 = 1 ;
V_42 -> V_142 = 1 ;
V_42 -> V_143 = sizeof( struct V_144 ) ;
V_3 -> V_4 = F_110 ( L_27 , V_145 , 0 ) ;
if ( ! V_3 -> V_4 ) {
F_27 ( L_28 ) ;
V_72 = - V_139 ;
goto V_140;
}
F_111 ( & V_3 -> V_5 , F_87 ) ;
F_112 ( & V_3 -> V_8 ) ;
V_3 -> V_7 = 0 ;
F_111 ( & V_3 -> V_40 , V_40 ) ;
V_72 = F_106 ( V_3 , V_131 , V_127 , & V_132 ) ;
if ( V_72 )
goto V_146;
V_127 += V_132 ;
V_131 -= V_132 ;
if ( V_131 ) {
V_42 -> error = L_29 ;
V_72 = - V_130 ;
goto V_146;
}
V_3 -> V_84 = F_113 ( & V_147 ) ;
if ( F_94 ( V_3 -> V_84 ) ) {
V_72 = F_114 ( V_3 -> V_84 ) ;
goto V_146;
}
F_1 ( V_3 ) ;
return 0 ;
V_146:
F_115 ( V_3 -> V_4 ) ;
V_140:
F_98 ( V_3 , V_42 , V_3 -> V_30 ) ;
return V_72 ;
}
static void F_116 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
F_117 ( & V_3 -> V_8 ) ;
F_118 ( V_3 -> V_4 ) ;
F_119 ( & V_3 -> V_40 ) ;
F_120 ( V_3 -> V_84 ) ;
F_115 ( V_3 -> V_4 ) ;
F_98 ( V_3 , V_42 , V_3 -> V_30 ) ;
}
static int F_121 ( struct V_41 * V_42 , struct V_14 * V_14 )
{
int V_72 , V_15 = F_67 ( V_14 ) ;
struct V_25 * V_27 ;
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
struct V_144 * V_148 =
F_122 ( V_14 , sizeof( struct V_144 ) ) ;
V_148 -> V_149 . V_92 = NULL ;
if ( V_15 == V_20 ) {
V_148 -> V_150 = F_54 ( V_3 -> V_79 , V_14 ) ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_151 ;
}
V_72 = log -> type -> V_37 ( log , F_54 ( V_3 -> V_79 , V_14 ) , 0 ) ;
if ( V_72 < 0 && V_72 != - V_152 )
return V_72 ;
if ( ! V_72 || ( V_72 == - V_152 ) ) {
if ( V_14 -> V_110 & V_153 )
return - V_152 ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_151 ;
}
V_27 = F_50 ( V_3 , V_14 -> V_89 . V_90 ) ;
if ( F_32 ( ! V_27 ) )
return - V_65 ;
F_123 ( & V_148 -> V_149 , V_14 ) ;
V_148 -> V_27 = V_27 ;
F_57 ( V_27 , V_14 ) ;
return V_154 ;
}
static int F_124 ( struct V_41 * V_42 , struct V_14 * V_14 , int error )
{
int V_15 = F_67 ( V_14 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_25 * V_27 = NULL ;
struct V_155 * V_156 = NULL ;
struct V_144 * V_148 =
F_122 ( V_14 , sizeof( struct V_144 ) ) ;
if ( V_15 == V_20 ) {
if ( ! ( V_14 -> V_110 & V_53 ) &&
F_75 ( V_14 ) != V_106 )
F_125 ( V_3 -> V_79 , V_148 -> V_150 ) ;
return error ;
}
if ( error == - V_107 )
goto V_36;
if ( ( error == - V_152 ) && ( V_14 -> V_110 & V_153 ) )
goto V_36;
if ( F_32 ( error ) ) {
if ( ! V_148 -> V_149 . V_92 ) {
F_36 ( L_30 ) ;
return - V_65 ;
}
V_27 = V_148 -> V_27 ;
F_27 ( L_31 ,
V_27 -> V_38 -> V_39 ) ;
F_23 ( V_27 , V_97 ) ;
if ( F_52 ( V_27 ) || F_53 ( V_3 , V_14 ) ) {
V_156 = & V_148 -> V_149 ;
F_126 ( V_156 , V_14 ) ;
V_148 -> V_149 . V_92 = NULL ;
V_14 -> V_94 = 0 ;
F_10 ( V_3 , V_14 , V_15 ) ;
return V_157 ;
}
F_27 ( L_32 ) ;
}
V_36:
V_148 -> V_149 . V_92 = NULL ;
return error ;
}
static void F_127 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
struct V_18 V_96 ;
struct V_14 * V_14 ;
F_21 ( & V_3 -> V_93 , 1 ) ;
F_61 ( & V_3 -> V_23 ) ;
V_96 = V_3 -> V_96 ;
F_78 ( & V_3 -> V_96 ) ;
F_62 ( & V_3 -> V_23 ) ;
while ( ( V_14 = F_15 ( & V_96 ) ) )
F_60 ( V_3 , V_14 ) ;
F_128 ( V_3 -> V_79 ) ;
F_129 ( V_13 ,
! F_130 ( V_3 -> V_79 ) ) ;
if ( log -> type -> V_158 && log -> type -> V_158 ( log ) )
F_28 ( L_33 ) ;
F_118 ( V_3 -> V_4 ) ;
}
static void F_131 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
if ( log -> type -> V_159 && log -> type -> V_159 ( log ) )
F_28 ( L_34 ) ;
}
static void F_132 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
F_21 ( & V_3 -> V_93 , 0 ) ;
if ( log -> type -> V_160 && log -> type -> V_160 ( log ) )
F_28 ( L_35 ) ;
F_133 ( V_3 -> V_79 ) ;
}
static char F_134 ( struct V_25 * V_27 )
{
if ( ! F_19 ( & ( V_27 -> V_31 ) ) )
return 'A' ;
return ( F_33 ( V_64 , & ( V_27 -> V_33 ) ) ) ? 'F' :
( F_33 ( V_108 , & ( V_27 -> V_33 ) ) ) ? 'D' :
( F_33 ( V_71 , & ( V_27 -> V_33 ) ) ) ? 'S' :
( F_33 ( V_97 , & ( V_27 -> V_33 ) ) ) ? 'R' : 'U' ;
}
static void F_135 ( struct V_41 * V_42 , T_5 type ,
unsigned V_161 , char * V_162 , unsigned V_163 )
{
unsigned int V_27 , V_164 = 0 ;
int V_165 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_42 -> V_43 ;
struct V_85 * log = F_46 ( V_3 -> V_79 ) ;
char V_166 [ V_3 -> V_30 + 1 ] ;
switch ( type ) {
case V_167 :
F_136 ( L_36 , V_3 -> V_30 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ ) {
F_136 ( L_37 , V_3 -> V_25 [ V_27 ] . V_38 -> V_39 ) ;
V_166 [ V_27 ] = F_134 ( & ( V_3 -> V_25 [ V_27 ] ) ) ;
}
V_166 [ V_27 ] = '\0' ;
F_136 ( L_38 ,
( unsigned long long ) log -> type -> V_86 ( log ) ,
( unsigned long long ) V_3 -> V_81 , V_166 ) ;
V_164 += log -> type -> V_168 ( log , type , V_162 + V_164 , V_163 - V_164 ) ;
break;
case V_169 :
V_164 = log -> type -> V_168 ( log , type , V_162 , V_163 ) ;
F_136 ( L_39 , V_3 -> V_30 ) ;
for ( V_27 = 0 ; V_27 < V_3 -> V_30 ; V_27 ++ )
F_136 ( L_40 , V_3 -> V_25 [ V_27 ] . V_38 -> V_39 ,
( unsigned long long ) V_3 -> V_25 [ V_27 ] . V_80 ) ;
V_165 += ! ! F_25 ( V_3 ) ;
V_165 += ! ! F_26 ( V_3 ) ;
if ( V_165 ) {
F_136 ( L_41 , V_165 ) ;
if ( F_25 ( V_3 ) )
F_136 ( L_42 ) ;
if ( F_26 ( V_3 ) )
F_136 ( L_43 ) ;
}
break;
}
}
static int F_137 ( struct V_41 * V_42 ,
T_6 V_101 , void * V_6 )
{
struct V_2 * V_3 = V_42 -> V_43 ;
int V_129 = 0 ;
unsigned V_45 ;
for ( V_45 = 0 ; ! V_129 && V_45 < V_3 -> V_30 ; V_45 ++ )
V_129 = V_101 ( V_42 , V_3 -> V_25 [ V_45 ] . V_38 ,
V_3 -> V_25 [ V_45 ] . V_80 , V_42 -> V_82 , V_6 ) ;
return V_129 ;
}
static int T_7 F_138 ( void )
{
int V_72 ;
V_72 = F_139 ( & V_170 ) ;
if ( V_72 < 0 ) {
F_27 ( L_44 ) ;
goto V_171;
}
return 0 ;
V_171:
return V_72 ;
}
static void T_8 F_140 ( void )
{
F_141 ( & V_170 ) ;
}
