static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline void F_2 ( struct V_2 * V_3 ,
unsigned int V_5 , unsigned int V_6 ,
struct V_1 * V_4 )
{
V_3 -> V_3 . V_7 = V_8 ;
V_3 -> V_3 . V_5 = V_5 ;
V_3 -> V_4 = V_4 ;
}
static int F_3 ( int V_9 )
{
switch ( V_9 ) {
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
case V_19 :
return V_20 ;
}
return V_9 ;
}
static inline void F_4 ( struct V_1 * V_4 )
{
if ( F_5 ( V_21 , ( unsigned long * ) & V_4 -> V_22 -> V_23 )
&& ! F_6 ( V_24 , & V_4 -> V_23 ) ) {
F_7 ( & V_4 -> V_25 -> V_26 , L_1 ) ;
F_8 ( & V_4 -> V_27 ) ;
}
}
static int F_9 ( struct V_1 * V_4 , struct V_28 * V_29 )
{
int V_30 = 0 ;
struct V_28 * V_31 = & V_4 -> V_22 -> V_29 ;
unsigned long V_32 ;
T_1 V_33 = V_4 -> V_34 ;
unsigned V_35 = V_4 -> V_35 ;
T_2 V_36 , V_37 ;
F_10 ( & V_4 -> V_38 , V_32 ) ;
memcpy ( V_31 , V_29 , sizeof( struct V_28 ) ) ;
F_11 () ;
F_12 ( V_39 , ( unsigned long * ) & V_4 -> V_22 -> V_23 ) ;
F_13 ( V_33 ) ;
V_37 = F_14 () + 2 * ( T_2 ) V_40 ;
F_15 ( V_35 ) ;
while ( F_5 ( V_39 ,
( unsigned long * ) & V_4 -> V_22 -> V_23 ) ) {
F_16 ( V_35 , V_41 + 3 * V_42 ) ;
F_15 ( V_35 ) ;
V_36 = F_14 () ;
if ( V_36 > V_37 ) {
F_17 ( & V_4 -> V_25 -> V_26 ,
L_2 ) ;
F_18 ( V_39 ,
( unsigned long * ) & V_4 -> V_22 -> V_23 ) ;
V_30 = V_12 ;
goto V_43;
}
}
if ( F_5 ( V_21 ,
( unsigned long * ) & V_4 -> V_22 -> V_23 ) ) {
F_17 ( & V_4 -> V_25 -> V_26 ,
L_3 ) ;
F_4 ( V_4 ) ;
}
memcpy ( V_29 , V_31 , sizeof( struct V_28 ) ) ;
V_30 = V_29 -> V_30 ;
V_43:
F_19 ( & V_4 -> V_38 , V_32 ) ;
return V_30 ;
}
static int F_20 ( struct V_44 * V_6 , unsigned int V_45 ,
int V_46 , int V_47 , T_3 * V_48 )
{
int V_30 = 0 ;
struct V_28 V_29 = {
. V_49 = V_50 ,
. V_5 = F_21 ( V_6 ) ,
. V_6 = V_6 -> V_51 ,
. V_45 = V_45 ,
. V_52 = V_46 ,
. V_47 = V_47 ,
} ;
struct V_2 * V_3 = V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_54 )
F_22 ( & V_4 -> V_25 -> V_26 ,
L_4 ,
F_21 ( V_6 ) , V_6 -> V_51 , F_23 ( V_45 ) ,
F_24 ( V_45 ) , V_46 , V_47 ) ;
V_30 = F_9 ( V_4 , & V_29 ) ;
if ( F_25 ( ! V_30 ) ) {
if ( V_54 )
F_22 ( & V_4 -> V_25 -> V_26 , L_5 ,
V_29 . V_55 ) ;
* V_48 = V_29 . V_55 ;
} else if ( V_30 == - V_56 ) {
V_30 = 0 ;
* V_48 = 0 ;
}
return F_3 ( V_30 ) ;
}
static int F_26 ( struct V_44 * V_6 , unsigned int V_45 ,
int V_46 , int V_47 , T_3 V_48 )
{
struct V_28 V_29 = {
. V_49 = V_57 ,
. V_5 = F_21 ( V_6 ) ,
. V_6 = V_6 -> V_51 ,
. V_45 = V_45 ,
. V_52 = V_46 ,
. V_47 = V_47 ,
. V_55 = V_48 ,
} ;
struct V_2 * V_3 = V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_54 )
F_22 ( & V_4 -> V_25 -> V_26 ,
L_6
L_7 ,
F_21 ( V_6 ) , V_6 -> V_51 ,
F_23 ( V_45 ) , F_24 ( V_45 ) , V_46 , V_47 , V_48 ) ;
return F_3 ( F_9 ( V_4 , & V_29 ) ) ;
}
static int F_27 ( struct V_58 * V_26 ,
int V_59 [] , int V_60 )
{
int V_30 ;
int V_61 ;
struct V_28 V_29 = {
. V_49 = V_62 ,
. V_5 = F_21 ( V_26 -> V_6 ) ,
. V_6 = V_26 -> V_6 -> V_51 ,
. V_45 = V_26 -> V_45 ,
. V_55 = V_60 ,
} ;
struct V_2 * V_3 = V_26 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_63 * V_64 ;
if ( V_60 > V_65 ) {
F_17 ( & V_26 -> V_26 , L_8
L_9 , V_60 ) ;
return - V_66 ;
}
V_61 = 0 ;
F_28 (entry, dev) {
V_29 . V_67 [ V_61 ] . V_64 = V_64 -> V_68 . V_69 ;
V_29 . V_67 [ V_61 ] . V_59 = - 1 ;
V_61 ++ ;
}
V_30 = F_9 ( V_4 , & V_29 ) ;
if ( F_25 ( ! V_30 ) ) {
if ( F_25 ( ! V_29 . V_55 ) ) {
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
if ( V_29 . V_67 [ V_61 ] . V_59 <= 0 ) {
F_29 ( & V_26 -> V_26 , L_10 ,
V_61 , V_29 . V_67 [ V_61 ] . V_59 ) ;
V_30 = - V_66 ;
V_59 [ V_61 ] = - 1 ;
continue;
}
V_59 [ V_61 ] = V_29 . V_67 [ V_61 ] . V_59 ;
}
} else {
F_30 ( V_70 L_11 ,
V_29 . V_55 ) ;
V_30 = V_29 . V_55 ;
}
} else {
F_17 ( & V_26 -> V_26 , L_12 , V_30 ) ;
}
return V_30 ;
}
static void F_31 ( struct V_58 * V_26 )
{
int V_30 ;
struct V_28 V_29 = {
. V_49 = V_71 ,
. V_5 = F_21 ( V_26 -> V_6 ) ,
. V_6 = V_26 -> V_6 -> V_51 ,
. V_45 = V_26 -> V_45 ,
} ;
struct V_2 * V_3 = V_26 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_30 = F_9 ( V_4 , & V_29 ) ;
if ( V_30 )
F_17 ( & V_26 -> V_26 , L_13 , V_30 ) ;
}
static int F_32 ( struct V_58 * V_26 , int V_59 [] )
{
int V_30 ;
struct V_28 V_29 = {
. V_49 = V_72 ,
. V_5 = F_21 ( V_26 -> V_6 ) ,
. V_6 = V_26 -> V_6 -> V_51 ,
. V_45 = V_26 -> V_45 ,
} ;
struct V_2 * V_3 = V_26 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_30 = F_9 ( V_4 , & V_29 ) ;
if ( F_25 ( ! V_30 ) ) {
V_59 [ 0 ] = V_29 . V_55 ;
if ( V_29 . V_55 <= 0 ) {
F_29 ( & V_26 -> V_26 , L_14 ,
V_29 . V_55 ) ;
V_30 = - V_66 ;
V_59 [ 0 ] = - 1 ;
}
} else {
F_17 ( & V_26 -> V_26 , L_15
L_16 , V_29 . V_6 , V_29 . V_45 ) ;
V_30 = - V_66 ;
}
return V_30 ;
}
static void F_33 ( struct V_58 * V_26 )
{
int V_30 ;
struct V_28 V_29 = {
. V_49 = V_73 ,
. V_5 = F_21 ( V_26 -> V_6 ) ,
. V_6 = V_26 -> V_6 -> V_51 ,
. V_45 = V_26 -> V_45 ,
} ;
struct V_2 * V_3 = V_26 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_30 = F_9 ( V_4 , & V_29 ) ;
if ( V_30 == V_12 ) {
F_30 ( V_70 L_17 ) ;
return;
}
if ( V_30 )
F_30 ( V_70 L_18 ) ;
}
static void F_34 ( int V_74 )
{
if ( V_74 )
V_75 = & V_76 ;
else
V_75 = NULL ;
}
static inline void F_34 ( int V_74 ) { }
static int F_35 ( struct V_58 * V_26 , void * V_77 )
{
struct V_1 * V_4 = V_77 ;
int V_61 ;
struct V_78 * V_79 ;
for ( V_61 = 0 ; V_61 < V_80 ; V_61 ++ ) {
V_79 = & V_26 -> V_78 [ V_61 ] ;
if ( ! V_79 -> V_81 && V_79 -> V_82 && V_79 -> V_23 ) {
F_22 ( & V_4 -> V_25 -> V_26 , L_19 ,
F_36 ( V_26 ) , V_61 ) ;
if ( F_37 ( V_26 , V_61 ) ) {
F_17 ( & V_4 -> V_25 -> V_26 , L_20
L_21 ,
F_36 ( V_26 ) , V_61 ) ;
}
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
struct V_44 * V_83 )
{
struct V_58 * V_84 ;
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < 0x100 ; V_45 ++ ) {
V_84 = F_39 ( V_83 , V_45 ) ;
if ( V_84 ) {
F_40 ( V_84 ) ;
continue;
}
V_84 = F_41 ( V_83 , V_45 ) ;
if ( V_84 )
F_22 ( & V_4 -> V_25 -> V_26 , L_22
L_23 , V_5 , V_6 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_44 * V_83 ;
F_43 ( V_85 ) ;
struct V_2 * V_3 = NULL ;
struct V_86 * V_87 = NULL ;
int V_30 = 0 ;
static struct V_78 V_88 = {
. V_82 = 0 ,
. V_89 = 255 ,
. V_23 = V_90 ,
} ;
#ifndef F_44
if ( V_5 != 0 ) {
F_17 ( & V_4 -> V_25 -> V_26 ,
L_24 , V_5 ) ;
F_17 ( & V_4 -> V_25 -> V_26 ,
L_25 ) ;
V_30 = - V_66 ;
goto V_91;
}
#endif
F_22 ( & V_4 -> V_25 -> V_26 , L_26 ,
V_5 , V_6 ) ;
V_87 = F_45 ( sizeof( * V_87 ) , V_92 ) ;
V_3 = F_45 ( sizeof( * V_3 ) , V_92 ) ;
if ( ! V_87 || ! V_3 ) {
V_30 = - V_93 ;
goto V_91;
}
F_46 ( & V_85 , & V_94 ) ;
F_46 ( & V_85 , & V_95 ) ;
F_46 ( & V_85 , & V_88 ) ;
F_2 ( V_3 , V_5 , V_6 , V_4 ) ;
F_47 () ;
V_83 = F_48 ( & V_4 -> V_25 -> V_26 , V_6 ,
& V_96 , V_3 , & V_85 ) ;
if ( ! V_83 ) {
F_17 ( & V_4 -> V_25 -> V_26 ,
L_27 ) ;
V_30 = - V_93 ;
F_49 () ;
F_50 ( & V_85 ) ;
goto V_91;
}
V_87 -> V_6 = V_83 ;
F_51 ( & V_87 -> V_97 , & V_4 -> V_98 ) ;
V_30 = F_38 ( V_4 , V_5 , V_6 , V_83 ) ;
F_52 ( V_83 , F_35 , V_4 ) ;
F_53 ( V_83 ) ;
F_49 () ;
return V_30 ;
V_91:
F_54 ( V_87 ) ;
F_54 ( V_3 ) ;
return V_30 ;
}
static int F_55 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
int V_30 ;
struct V_44 * V_83 ;
#ifndef F_44
if ( V_5 != 0 ) {
F_17 ( & V_4 -> V_25 -> V_26 ,
L_24 , V_5 ) ;
F_17 ( & V_4 -> V_25 -> V_26 ,
L_25 ) ;
return - V_66 ;
}
#endif
F_22 ( & V_4 -> V_25 -> V_26 , L_28 ,
V_5 , V_6 ) ;
V_83 = F_56 ( V_5 , V_6 ) ;
if ( ! V_83 )
return F_42 ( V_4 , V_5 , V_6 ) ;
V_30 = F_38 ( V_4 , V_5 , V_6 , V_83 ) ;
F_52 ( V_83 , F_35 , V_4 ) ;
F_53 ( V_83 ) ;
return V_30 ;
}
static void F_57 ( struct V_44 * V_6 )
{
struct V_58 * V_26 ;
while ( ! F_58 ( & V_6 -> V_99 ) ) {
V_26 = F_59 ( V_6 -> V_99 . V_100 , struct V_58 ,
V_101 ) ;
F_7 ( & V_26 -> V_26 , L_29 ) ;
F_60 ( V_26 ) ;
}
}
static void F_61 ( struct V_1 * V_4 )
{
struct V_86 * V_87 , * V_102 ;
F_7 ( & V_4 -> V_25 -> V_26 , L_30 ) ;
F_47 () ;
F_62 (bus_entry, t, &pdev->root_buses, list) {
F_63 ( & V_87 -> V_97 ) ;
F_57 ( V_87 -> V_6 ) ;
F_54 ( V_87 -> V_6 -> V_53 ) ;
F_64 ( V_87 -> V_6 -> V_103 ) ;
F_65 ( V_87 -> V_6 ) ;
F_54 ( V_87 ) ;
}
F_49 () ;
}
static T_4 F_66 ( int V_49 ,
struct V_1 * V_4 ,
T_5 V_104 )
{
T_4 V_105 ;
struct V_106 * V_107 ;
int V_6 = V_4 -> V_22 -> V_108 . V_6 ;
int V_45 = V_4 -> V_22 -> V_108 . V_45 ;
struct V_58 * V_109 ;
int V_110 = 0 ;
F_7 ( & V_4 -> V_25 -> V_26 ,
L_31 ,
V_49 , V_6 , V_45 ) ;
V_105 = V_111 ;
V_109 = F_67 ( V_6 , V_45 ) ;
if ( ! V_109 || ! V_109 -> V_112 ) {
F_17 ( & V_4 -> V_25 -> V_26 , L_32 ) ;
F_40 ( V_109 ) ;
return V_105 ;
}
V_107 = V_109 -> V_112 ;
if ( V_107 ) {
if ( V_107 -> V_113 && V_107 -> V_113 -> V_114 ) {
F_7 ( & V_109 -> V_26 ,
L_33 ) ;
if ( V_109 ) {
V_110 = 1 ;
switch ( V_49 ) {
case V_115 :
V_105 = V_107 -> V_113 ->
V_114 ( V_109 , V_104 ) ;
break;
case V_116 :
V_105 = V_107 -> V_113 ->
V_117 ( V_109 ) ;
break;
case V_118 :
V_105 = V_107 -> V_113 ->
V_119 ( V_109 ) ;
break;
case V_120 :
V_107 -> V_113 -> V_121 ( V_109 ) ;
break;
default:
F_17 ( & V_4 -> V_25 -> V_26 ,
L_34
L_35 ) ;
}
}
}
}
if ( ! V_110 )
V_105 = V_111 ;
return V_105 ;
}
static void F_68 ( struct V_122 * V_77 )
{
struct V_1 * V_4 =
F_59 ( V_77 , struct V_1 , V_27 ) ;
int V_49 = V_4 -> V_22 -> V_108 . V_49 ;
T_5 V_104 =
( T_5 ) V_4 -> V_22 -> V_108 . V_30 ;
F_7 ( & V_4 -> V_25 -> V_26 ,
L_36 ,
V_4 -> V_22 -> V_108 . V_6 , V_4 -> V_22 -> V_108 . V_45 ) ;
V_4 -> V_22 -> V_108 . V_30 = F_66 ( V_49 , V_4 , V_104 ) ;
F_11 () ;
F_18 ( V_21 , ( unsigned long * ) & V_4 -> V_22 -> V_23 ) ;
F_13 ( V_4 -> V_34 ) ;
F_69 () ;
F_18 ( V_24 , & V_4 -> V_23 ) ;
F_70 () ;
F_4 ( V_4 ) ;
}
static T_6 F_71 ( int V_35 , void * V_26 )
{
struct V_1 * V_4 = V_26 ;
F_4 ( V_4 ) ;
return V_123 ;
}
static int F_72 ( struct V_1 * V_4 )
{
int V_30 = 0 ;
F_73 ( & V_124 ) ;
if ( ! V_125 ) {
F_22 ( & V_4 -> V_25 -> V_26 , L_37 ) ;
V_125 = V_4 ;
} else
V_30 = - V_126 ;
F_74 ( & V_124 ) ;
if ( ! V_30 && ! F_75 () ) {
V_30 = F_76 () ;
if ( V_30 )
F_17 ( & V_4 -> V_25 -> V_26 , L_38 ) ;
}
return V_30 ;
}
static void F_77 ( struct V_1 * V_4 )
{
F_73 ( & V_124 ) ;
if ( V_4 == V_125 ) {
F_22 ( & V_4 -> V_25 -> V_26 ,
L_39 ) ;
V_125 = NULL ;
}
F_74 ( & V_124 ) ;
}
static struct V_1 * F_78 ( struct V_127 * V_25 )
{
struct V_1 * V_4 ;
V_4 = F_45 ( sizeof( struct V_1 ) , V_92 ) ;
if ( V_4 == NULL )
goto V_43;
V_4 -> V_22 =
(struct V_128 * ) F_79 ( V_92 ) ;
if ( V_4 -> V_22 == NULL ) {
F_54 ( V_4 ) ;
V_4 = NULL ;
goto V_43;
}
V_4 -> V_22 -> V_23 = 0 ;
F_12 ( V_129 , ( void * ) & V_4 -> V_22 -> V_23 ) ;
F_80 ( & V_25 -> V_26 , V_4 ) ;
V_4 -> V_25 = V_25 ;
F_81 ( & V_4 -> V_98 ) ;
F_82 ( & V_4 -> V_38 ) ;
V_4 -> V_34 = V_130 ;
V_4 -> V_131 = V_132 ;
V_4 -> V_35 = - 1 ;
F_83 ( & V_4 -> V_27 , F_68 ) ;
F_7 ( & V_25 -> V_26 , L_40 ,
V_4 , V_4 -> V_22 ) ;
V_43:
return V_4 ;
}
static void F_84 ( struct V_1 * V_4 )
{
F_7 ( & V_4 -> V_25 -> V_26 , L_41 , V_4 ) ;
F_61 ( V_4 ) ;
F_85 ( & V_4 -> V_27 ) ;
if ( V_4 -> V_35 >= 0 )
F_86 ( V_4 -> V_35 , V_4 ) ;
if ( V_4 -> V_34 != V_130 )
F_87 ( V_4 -> V_25 , V_4 -> V_34 ) ;
if ( V_4 -> V_131 != V_132 )
F_88 ( V_4 -> V_131 , 0 ,
( unsigned long ) V_4 -> V_22 ) ;
else
F_89 ( ( unsigned long ) V_4 -> V_22 ) ;
F_80 ( & V_4 -> V_25 -> V_26 , NULL ) ;
F_54 ( V_4 ) ;
}
static int F_90 ( struct V_1 * V_4 )
{
int V_30 = 0 ;
struct V_133 V_134 ;
T_7 V_135 ;
V_30 = F_91 ( V_4 -> V_25 , V_4 -> V_22 , 1 , & V_135 ) ;
if ( V_30 < 0 )
goto V_43;
V_4 -> V_131 = V_135 ;
V_30 = F_92 ( V_4 -> V_25 , & V_4 -> V_34 ) ;
if ( V_30 )
goto V_43;
V_30 = F_93 ( V_4 -> V_34 , F_71 ,
0 , L_42 , V_4 ) ;
if ( V_30 < 0 )
return V_30 ;
V_4 -> V_35 = V_30 ;
V_136:
V_30 = F_94 ( & V_134 ) ;
if ( V_30 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_43
L_44 ) ;
goto V_43;
}
V_30 = F_96 ( V_134 , V_4 -> V_25 -> V_137 ,
L_45 , L_46 , V_4 -> V_131 ) ;
if ( ! V_30 )
V_30 = F_96 ( V_134 , V_4 -> V_25 -> V_137 ,
L_47 , L_46 , V_4 -> V_34 ) ;
if ( ! V_30 )
V_30 = F_96 ( V_134 , V_4 -> V_25 -> V_137 ,
L_48 , V_138 ) ;
if ( V_30 ) {
F_97 ( V_134 , 1 ) ;
F_95 ( V_4 -> V_25 , V_30 ,
L_49 ) ;
goto V_43;
} else {
V_30 = F_97 ( V_134 , 0 ) ;
if ( V_30 == - V_139 )
goto V_136;
else if ( V_30 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_50
L_51 ) ;
goto V_43;
}
}
F_98 ( V_4 -> V_25 , V_140 ) ;
F_7 ( & V_4 -> V_25 -> V_26 , L_52 ) ;
V_43:
return V_30 ;
}
static int F_99 ( struct V_1 * V_4 )
{
int V_30 = - V_141 ;
int V_61 , V_142 , V_143 ;
char V_144 [ 64 ] ;
unsigned int V_5 , V_6 ;
if ( F_100 ( V_4 -> V_25 -> V_137 ) !=
V_140 )
goto V_43;
V_30 = F_72 ( V_4 ) ;
if ( V_30 && V_30 != - V_126 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_53 ) ;
goto V_43;
}
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 ,
L_54 , L_55 , & V_142 ) ;
if ( V_30 == - V_147 ) {
F_102 ( V_4 -> V_25 , V_30 ,
L_56 ) ;
V_30 = F_42 ( V_4 , 0 , 0 ) ;
if ( V_30 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_57 ) ;
goto V_43;
}
V_142 = 0 ;
} else if ( V_30 != 1 ) {
if ( V_30 == 0 )
V_30 = - V_66 ;
F_95 ( V_4 -> V_25 , V_30 ,
L_58 ) ;
goto V_43;
}
for ( V_61 = 0 ; V_61 < V_142 ; V_61 ++ ) {
V_143 = snprintf ( V_144 , sizeof( V_144 ) , L_59 , V_61 ) ;
if ( F_103 ( V_143 >= ( sizeof( V_144 ) - 1 ) ) ) {
V_30 = - V_93 ;
goto V_43;
}
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 , V_144 ,
L_60 , & V_5 , & V_6 ) ;
if ( V_30 != 2 ) {
if ( V_30 >= 0 )
V_30 = - V_66 ;
F_95 ( V_4 -> V_25 , V_30 ,
L_61 , V_61 ) ;
goto V_43;
}
V_30 = F_42 ( V_4 , V_5 , V_6 ) ;
if ( V_30 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_62 ,
V_5 , V_6 ) ;
goto V_43;
}
}
V_30 = F_98 ( V_4 -> V_25 , V_148 ) ;
V_43:
return V_30 ;
}
static int F_104 ( struct V_1 * V_4 )
{
int V_30 = 0 ;
enum V_149 V_150 ;
V_150 = F_100 ( V_4 -> V_25 -> V_137 ) ;
if ( V_150 >= V_151 )
goto V_43;
if ( V_150 == V_148 ) {
F_61 ( V_4 ) ;
F_77 ( V_4 ) ;
}
V_30 = F_98 ( V_4 -> V_25 , V_152 ) ;
V_43:
return V_30 ;
}
static int F_105 ( struct V_1 * V_4 )
{
int V_30 = - V_141 ;
int V_61 , V_142 , V_143 ;
unsigned int V_5 , V_6 ;
char V_144 [ 64 ] ;
if ( F_100 ( V_4 -> V_25 -> V_137 ) !=
V_153 )
goto V_43;
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 ,
L_54 , L_55 , & V_142 ) ;
if ( V_30 == - V_147 ) {
F_102 ( V_4 -> V_25 , V_30 ,
L_56 ) ;
V_30 = F_55 ( V_4 , 0 , 0 ) ;
if ( V_30 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_57 ) ;
goto V_43;
}
V_142 = 0 ;
} else if ( V_30 != 1 ) {
if ( V_30 == 0 )
V_30 = - V_66 ;
F_95 ( V_4 -> V_25 , V_30 ,
L_58 ) ;
goto V_43;
}
for ( V_61 = 0 ; V_61 < V_142 ; V_61 ++ ) {
V_143 = snprintf ( V_144 , sizeof( V_144 ) , L_59 , V_61 ) ;
if ( F_103 ( V_143 >= ( sizeof( V_144 ) - 1 ) ) ) {
V_30 = - V_93 ;
goto V_43;
}
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 , V_144 ,
L_60 , & V_5 , & V_6 ) ;
if ( V_30 != 2 ) {
if ( V_30 >= 0 )
V_30 = - V_66 ;
F_95 ( V_4 -> V_25 , V_30 ,
L_61 , V_61 ) ;
goto V_43;
}
V_30 = F_55 ( V_4 , V_5 , V_6 ) ;
if ( V_30 ) {
F_95 ( V_4 -> V_25 , V_30 ,
L_62 ,
V_5 , V_6 ) ;
goto V_43;
}
}
F_98 ( V_4 -> V_25 , V_148 ) ;
V_43:
return V_30 ;
}
static int F_106 ( struct V_1 * V_4 )
{
int V_30 = 0 ;
int V_61 , V_154 ;
unsigned int V_5 , V_6 , V_155 , V_156 ;
struct V_58 * V_58 ;
char V_144 [ 64 ] ;
if ( F_100 ( V_4 -> V_25 -> V_137 ) !=
V_148 )
goto V_43;
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 , L_63 , L_55 ,
& V_154 ) ;
if ( V_30 != 1 ) {
if ( V_30 >= 0 )
V_30 = - V_66 ;
F_95 ( V_4 -> V_25 , V_30 ,
L_64 ) ;
goto V_43;
}
for ( V_61 = 0 ; V_61 < V_154 ; V_61 ++ ) {
int V_157 , V_104 ;
V_157 = snprintf ( V_144 , sizeof( V_144 ) , L_65 , V_61 ) ;
if ( F_103 ( V_157 >= ( sizeof( V_144 ) - 1 ) ) ) {
V_30 = - V_93 ;
goto V_43;
}
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 , V_144 , L_55 ,
& V_104 ) ;
if ( V_30 != 1 )
V_104 = V_158 ;
if ( V_104 != V_151 )
continue;
V_157 = snprintf ( V_144 , sizeof( V_144 ) , L_66 , V_61 ) ;
if ( F_103 ( V_157 >= ( sizeof( V_144 ) - 1 ) ) ) {
V_30 = - V_93 ;
goto V_43;
}
V_30 = F_101 ( V_145 , V_4 -> V_25 -> V_146 , V_144 ,
L_67 , & V_5 , & V_6 , & V_155 , & V_156 ) ;
if ( V_30 != 4 ) {
if ( V_30 >= 0 )
V_30 = - V_66 ;
F_95 ( V_4 -> V_25 , V_30 ,
L_68 , V_61 ) ;
goto V_43;
}
V_58 = F_107 ( V_5 , V_6 ,
F_108 ( V_155 , V_156 ) ) ;
if ( ! V_58 ) {
F_7 ( & V_4 -> V_25 -> V_26 ,
L_69 ,
V_5 , V_6 , V_155 , V_156 ) ;
continue;
}
F_47 () ;
F_60 ( V_58 ) ;
F_40 ( V_58 ) ;
F_49 () ;
F_7 ( & V_4 -> V_25 -> V_26 ,
L_70 ,
V_5 , V_6 , V_155 , V_156 ) ;
}
V_30 = F_98 ( V_4 -> V_25 , V_153 ) ;
V_43:
return V_30 ;
}
static void T_8 F_109 ( struct V_127 * V_25 ,
enum V_149 V_159 )
{
struct V_1 * V_4 = F_110 ( & V_25 -> V_26 ) ;
switch ( V_159 ) {
case V_158 :
case V_160 :
case V_161 :
case V_140 :
break;
case V_148 :
F_99 ( V_4 ) ;
break;
case V_152 :
if ( V_25 -> V_104 == V_152 )
break;
case V_151 :
F_29 ( & V_25 -> V_26 , L_71 ) ;
F_104 ( V_4 ) ;
break;
case V_153 :
F_106 ( V_4 ) ;
break;
case V_162 :
F_105 ( V_4 ) ;
break;
}
}
static int F_111 ( struct V_127 * V_25 ,
const struct V_163 * V_164 )
{
int V_30 = 0 ;
struct V_1 * V_4 = F_78 ( V_25 ) ;
if ( V_4 == NULL ) {
V_30 = - V_93 ;
F_95 ( V_25 , V_30 ,
L_72 ) ;
goto V_43;
}
V_30 = F_90 ( V_4 ) ;
if ( V_30 )
F_84 ( V_4 ) ;
V_43:
return V_30 ;
}
static int F_112 ( struct V_127 * V_25 )
{
struct V_1 * V_4 = F_110 ( & V_25 -> V_26 ) ;
if ( V_4 )
F_84 ( V_4 ) ;
return 0 ;
}
static int T_9 F_113 ( void )
{
if ( ! F_114 () || F_115 () )
return - V_56 ;
if ( ! F_116 () )
return - V_56 ;
F_34 ( 1 ) ;
return F_117 ( & V_165 ) ;
}
static void T_10 F_118 ( void )
{
F_119 ( & V_165 ) ;
F_34 ( 0 ) ;
}
