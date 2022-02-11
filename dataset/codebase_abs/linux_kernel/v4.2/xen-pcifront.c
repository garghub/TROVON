static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline void F_2 ( struct V_2 * V_3 ,
unsigned int V_5 , unsigned int V_6 ,
struct V_1 * V_4 )
{
V_3 -> V_5 = V_5 ;
V_3 -> V_4 = V_4 ;
}
static int F_3 ( int V_7 )
{
switch ( V_7 ) {
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
}
return V_7 ;
}
static inline void F_4 ( struct V_1 * V_4 )
{
if ( F_5 ( V_19 , ( unsigned long * ) & V_4 -> V_20 -> V_21 )
&& ! F_6 ( V_22 , & V_4 -> V_21 ) ) {
F_7 ( & V_4 -> V_23 -> V_24 , L_1 ) ;
F_8 ( & V_4 -> V_25 ) ;
}
}
static int F_9 ( struct V_1 * V_4 , struct V_26 * V_27 )
{
int V_28 = 0 ;
struct V_26 * V_29 = & V_4 -> V_20 -> V_27 ;
unsigned long V_30 ;
T_1 V_31 = V_4 -> V_32 ;
unsigned V_33 = V_4 -> V_33 ;
T_2 V_34 , V_35 ;
F_10 ( & V_4 -> V_36 , V_30 ) ;
memcpy ( V_29 , V_27 , sizeof( struct V_26 ) ) ;
F_11 () ;
F_12 ( V_37 , ( unsigned long * ) & V_4 -> V_20 -> V_21 ) ;
F_13 ( V_31 ) ;
V_35 = F_14 () + 2 * ( T_2 ) V_38 ;
F_15 ( V_33 ) ;
while ( F_5 ( V_37 ,
( unsigned long * ) & V_4 -> V_20 -> V_21 ) ) {
F_16 ( V_33 , V_39 + 3 * V_40 ) ;
F_15 ( V_33 ) ;
V_34 = F_14 () ;
if ( V_34 > V_35 ) {
F_17 ( & V_4 -> V_23 -> V_24 ,
L_2 ) ;
F_18 ( V_37 ,
( unsigned long * ) & V_4 -> V_20 -> V_21 ) ;
V_28 = V_10 ;
goto V_41;
}
}
if ( F_5 ( V_19 ,
( unsigned long * ) & V_4 -> V_20 -> V_21 ) ) {
F_17 ( & V_4 -> V_23 -> V_24 ,
L_3 ) ;
F_4 ( V_4 ) ;
}
memcpy ( V_27 , V_29 , sizeof( struct V_26 ) ) ;
V_28 = V_27 -> V_28 ;
V_41:
F_19 ( & V_4 -> V_36 , V_30 ) ;
return V_28 ;
}
static int F_20 ( struct V_42 * V_6 , unsigned int V_43 ,
int V_44 , int V_45 , T_3 * V_46 )
{
int V_28 = 0 ;
struct V_26 V_27 = {
. V_47 = V_48 ,
. V_5 = F_21 ( V_6 ) ,
. V_6 = V_6 -> V_49 ,
. V_43 = V_43 ,
. V_50 = V_44 ,
. V_45 = V_45 ,
} ;
struct V_2 * V_3 = V_6 -> V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_52 )
F_22 ( & V_4 -> V_23 -> V_24 ,
L_4 ,
F_21 ( V_6 ) , V_6 -> V_49 , F_23 ( V_43 ) ,
F_24 ( V_43 ) , V_44 , V_45 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( F_25 ( ! V_28 ) ) {
if ( V_52 )
F_22 ( & V_4 -> V_23 -> V_24 , L_5 ,
V_27 . V_53 ) ;
* V_46 = V_27 . V_53 ;
} else if ( V_28 == - V_54 ) {
V_28 = 0 ;
* V_46 = 0 ;
}
return F_3 ( V_28 ) ;
}
static int F_26 ( struct V_42 * V_6 , unsigned int V_43 ,
int V_44 , int V_45 , T_3 V_46 )
{
struct V_26 V_27 = {
. V_47 = V_55 ,
. V_5 = F_21 ( V_6 ) ,
. V_6 = V_6 -> V_49 ,
. V_43 = V_43 ,
. V_50 = V_44 ,
. V_45 = V_45 ,
. V_53 = V_46 ,
} ;
struct V_2 * V_3 = V_6 -> V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_52 )
F_22 ( & V_4 -> V_23 -> V_24 ,
L_6
L_7 ,
F_21 ( V_6 ) , V_6 -> V_49 ,
F_23 ( V_43 ) , F_24 ( V_43 ) , V_44 , V_45 , V_46 ) ;
return F_3 ( F_9 ( V_4 , & V_27 ) ) ;
}
static int F_27 ( struct V_56 * V_24 ,
int V_57 [] , int V_58 )
{
int V_28 ;
int V_59 ;
struct V_26 V_27 = {
. V_47 = V_60 ,
. V_5 = F_21 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_49 ,
. V_43 = V_24 -> V_43 ,
. V_53 = V_58 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_61 * V_62 ;
if ( V_58 > V_63 ) {
F_17 ( & V_24 -> V_24 , L_8
L_9 , V_58 ) ;
return - V_64 ;
}
V_59 = 0 ;
F_28 (entry, &dev->msi_list, list) {
V_27 . V_65 [ V_59 ] . V_62 = V_62 -> V_66 . V_67 ;
V_27 . V_65 [ V_59 ] . V_57 = - 1 ;
V_59 ++ ;
}
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( F_25 ( ! V_28 ) ) {
if ( F_25 ( ! V_27 . V_53 ) ) {
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
if ( V_27 . V_65 [ V_59 ] . V_57 <= 0 ) {
F_29 ( & V_24 -> V_24 , L_10 ,
V_59 , V_27 . V_65 [ V_59 ] . V_57 ) ;
V_28 = - V_64 ;
V_57 [ V_59 ] = - 1 ;
continue;
}
V_57 [ V_59 ] = V_27 . V_65 [ V_59 ] . V_57 ;
}
} else {
F_30 ( V_68 L_11 ,
V_27 . V_53 ) ;
V_28 = V_27 . V_53 ;
}
} else {
F_17 ( & V_24 -> V_24 , L_12 , V_28 ) ;
}
return V_28 ;
}
static void F_31 ( struct V_56 * V_24 )
{
int V_28 ;
struct V_26 V_27 = {
. V_47 = V_69 ,
. V_5 = F_21 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_49 ,
. V_43 = V_24 -> V_43 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( V_28 )
F_17 ( & V_24 -> V_24 , L_13 , V_28 ) ;
}
static int F_32 ( struct V_56 * V_24 , int V_57 [] )
{
int V_28 ;
struct V_26 V_27 = {
. V_47 = V_70 ,
. V_5 = F_21 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_49 ,
. V_43 = V_24 -> V_43 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( F_25 ( ! V_28 ) ) {
V_57 [ 0 ] = V_27 . V_53 ;
if ( V_27 . V_53 <= 0 ) {
F_29 ( & V_24 -> V_24 , L_14 ,
V_27 . V_53 ) ;
V_28 = - V_64 ;
V_57 [ 0 ] = - 1 ;
}
} else {
F_17 ( & V_24 -> V_24 , L_15
L_16 , V_27 . V_6 , V_27 . V_43 ) ;
V_28 = - V_64 ;
}
return V_28 ;
}
static void F_33 ( struct V_56 * V_24 )
{
int V_28 ;
struct V_26 V_27 = {
. V_47 = V_71 ,
. V_5 = F_21 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_49 ,
. V_43 = V_24 -> V_43 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_51 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( V_28 == V_10 ) {
F_30 ( V_68 L_17 ) ;
return;
}
if ( V_28 )
F_30 ( V_68 L_18 ) ;
}
static void F_34 ( int V_72 )
{
if ( V_72 )
V_73 = & V_74 ;
else
V_73 = NULL ;
}
static inline void F_34 ( int V_72 ) { }
static int F_35 ( struct V_56 * V_24 , void * V_75 )
{
struct V_1 * V_4 = V_75 ;
int V_59 ;
struct V_76 * V_77 ;
for ( V_59 = 0 ; V_59 < V_78 ; V_59 ++ ) {
V_77 = & V_24 -> V_76 [ V_59 ] ;
if ( ! V_77 -> V_79 && V_77 -> V_80 && V_77 -> V_21 ) {
F_22 ( & V_4 -> V_23 -> V_24 , L_19 ,
F_36 ( V_24 ) , V_59 ) ;
if ( F_37 ( V_24 , V_59 ) ) {
F_17 ( & V_4 -> V_23 -> V_24 , L_20
L_21 ,
F_36 ( V_24 ) , V_59 ) ;
}
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
struct V_42 * V_81 )
{
struct V_56 * V_82 ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < 0x100 ; V_43 ++ ) {
V_82 = F_39 ( V_81 , V_43 ) ;
if ( V_82 ) {
F_40 ( V_82 ) ;
continue;
}
V_82 = F_41 ( V_81 , V_43 ) ;
if ( V_82 )
F_22 ( & V_4 -> V_23 -> V_24 , L_22
L_23 , V_5 , V_6 ,
F_23 ( V_43 ) , F_24 ( V_43 ) ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_42 * V_81 ;
F_43 ( V_83 ) ;
struct V_2 * V_3 = NULL ;
struct V_84 * V_85 = NULL ;
int V_28 = 0 ;
static struct V_76 V_86 = {
. V_80 = 0 ,
. V_87 = 255 ,
. V_21 = V_88 ,
} ;
#ifndef F_44
if ( V_5 != 0 ) {
F_17 ( & V_4 -> V_23 -> V_24 ,
L_24 , V_5 ) ;
F_17 ( & V_4 -> V_23 -> V_24 ,
L_25 ) ;
V_28 = - V_64 ;
goto V_89;
}
#endif
F_22 ( & V_4 -> V_23 -> V_24 , L_26 ,
V_5 , V_6 ) ;
V_85 = F_45 ( sizeof( * V_85 ) , V_90 ) ;
V_3 = F_45 ( sizeof( * V_3 ) , V_90 ) ;
if ( ! V_85 || ! V_3 ) {
V_28 = - V_91 ;
goto V_89;
}
F_46 ( & V_83 , & V_92 ) ;
F_46 ( & V_83 , & V_93 ) ;
F_46 ( & V_83 , & V_86 ) ;
F_2 ( V_3 , V_5 , V_6 , V_4 ) ;
F_47 () ;
V_81 = F_48 ( & V_4 -> V_23 -> V_24 , V_6 ,
& V_94 , V_3 , & V_83 ) ;
if ( ! V_81 ) {
F_17 ( & V_4 -> V_23 -> V_24 ,
L_27 ) ;
V_28 = - V_91 ;
F_49 () ;
F_50 ( & V_83 ) ;
goto V_89;
}
V_85 -> V_6 = V_81 ;
F_51 ( & V_85 -> V_95 , & V_4 -> V_96 ) ;
V_28 = F_38 ( V_4 , V_5 , V_6 , V_81 ) ;
F_52 ( V_81 , F_35 , V_4 ) ;
F_53 ( V_81 ) ;
F_49 () ;
return V_28 ;
V_89:
F_54 ( V_85 ) ;
F_54 ( V_3 ) ;
return V_28 ;
}
static int F_55 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
int V_28 ;
struct V_42 * V_81 ;
#ifndef F_44
if ( V_5 != 0 ) {
F_17 ( & V_4 -> V_23 -> V_24 ,
L_24 , V_5 ) ;
F_17 ( & V_4 -> V_23 -> V_24 ,
L_25 ) ;
return - V_64 ;
}
#endif
F_22 ( & V_4 -> V_23 -> V_24 , L_28 ,
V_5 , V_6 ) ;
V_81 = F_56 ( V_5 , V_6 ) ;
if ( ! V_81 )
return F_42 ( V_4 , V_5 , V_6 ) ;
V_28 = F_38 ( V_4 , V_5 , V_6 , V_81 ) ;
F_52 ( V_81 , F_35 , V_4 ) ;
F_53 ( V_81 ) ;
return V_28 ;
}
static void F_57 ( struct V_42 * V_6 )
{
struct V_56 * V_24 ;
while ( ! F_58 ( & V_6 -> V_97 ) ) {
V_24 = F_59 ( V_6 -> V_97 . V_98 , struct V_56 ,
V_99 ) ;
F_7 ( & V_24 -> V_24 , L_29 ) ;
F_60 ( V_24 ) ;
}
}
static void F_61 ( struct V_1 * V_4 )
{
struct V_84 * V_85 , * V_100 ;
F_7 ( & V_4 -> V_23 -> V_24 , L_30 ) ;
F_47 () ;
F_62 (bus_entry, t, &pdev->root_buses, list) {
F_63 ( & V_85 -> V_95 ) ;
F_57 ( V_85 -> V_6 ) ;
F_54 ( V_85 -> V_6 -> V_51 ) ;
F_64 ( V_85 -> V_6 -> V_101 ) ;
F_65 ( V_85 -> V_6 ) ;
F_54 ( V_85 ) ;
}
F_49 () ;
}
static T_4 F_66 ( int V_47 ,
struct V_1 * V_4 ,
T_5 V_102 )
{
T_4 V_103 ;
struct V_104 * V_105 ;
int V_6 = V_4 -> V_20 -> V_106 . V_6 ;
int V_43 = V_4 -> V_20 -> V_106 . V_43 ;
struct V_56 * V_107 ;
int V_108 = 0 ;
F_7 ( & V_4 -> V_23 -> V_24 ,
L_31 ,
V_47 , V_6 , V_43 ) ;
V_103 = V_109 ;
V_107 = F_67 ( V_6 , V_43 ) ;
if ( ! V_107 || ! V_107 -> V_110 ) {
F_17 ( & V_4 -> V_23 -> V_24 , L_32 ) ;
F_40 ( V_107 ) ;
return V_103 ;
}
V_105 = V_107 -> V_110 ;
if ( V_105 ) {
if ( V_105 -> V_111 && V_105 -> V_111 -> V_112 ) {
F_7 ( & V_107 -> V_24 ,
L_33 ) ;
if ( V_107 ) {
V_108 = 1 ;
switch ( V_47 ) {
case V_113 :
V_103 = V_105 -> V_111 ->
V_112 ( V_107 , V_102 ) ;
break;
case V_114 :
V_103 = V_105 -> V_111 ->
V_115 ( V_107 ) ;
break;
case V_116 :
V_103 = V_105 -> V_111 ->
V_117 ( V_107 ) ;
break;
case V_118 :
V_105 -> V_111 -> V_119 ( V_107 ) ;
break;
default:
F_17 ( & V_4 -> V_23 -> V_24 ,
L_34
L_35 ) ;
}
}
}
}
if ( ! V_108 )
V_103 = V_109 ;
return V_103 ;
}
static void F_68 ( struct V_120 * V_75 )
{
struct V_1 * V_4 =
F_59 ( V_75 , struct V_1 , V_25 ) ;
int V_47 = V_4 -> V_20 -> V_106 . V_47 ;
T_5 V_102 =
( T_5 ) V_4 -> V_20 -> V_106 . V_28 ;
F_7 ( & V_4 -> V_23 -> V_24 ,
L_36 ,
V_4 -> V_20 -> V_106 . V_6 , V_4 -> V_20 -> V_106 . V_43 ) ;
V_4 -> V_20 -> V_106 . V_28 = F_66 ( V_47 , V_4 , V_102 ) ;
F_11 () ;
F_18 ( V_19 , ( unsigned long * ) & V_4 -> V_20 -> V_21 ) ;
F_13 ( V_4 -> V_32 ) ;
F_69 () ;
F_18 ( V_22 , & V_4 -> V_21 ) ;
F_70 () ;
F_4 ( V_4 ) ;
}
static T_6 F_71 ( int V_33 , void * V_24 )
{
struct V_1 * V_4 = V_24 ;
F_4 ( V_4 ) ;
return V_121 ;
}
static int F_72 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
F_73 ( & V_122 ) ;
if ( ! V_123 ) {
F_22 ( & V_4 -> V_23 -> V_24 , L_37 ) ;
V_123 = V_4 ;
} else
V_28 = - V_124 ;
F_74 ( & V_122 ) ;
if ( ! V_28 && ! F_75 () ) {
V_28 = F_76 () ;
if ( V_28 )
F_17 ( & V_4 -> V_23 -> V_24 , L_38 ) ;
}
return V_28 ;
}
static void F_77 ( struct V_1 * V_4 )
{
F_73 ( & V_122 ) ;
if ( V_4 == V_123 ) {
F_22 ( & V_4 -> V_23 -> V_24 ,
L_39 ) ;
V_123 = NULL ;
}
F_74 ( & V_122 ) ;
}
static struct V_1 * F_78 ( struct V_125 * V_23 )
{
struct V_1 * V_4 ;
V_4 = F_79 ( sizeof( struct V_1 ) , V_90 ) ;
if ( V_4 == NULL )
goto V_41;
V_4 -> V_20 =
(struct V_126 * ) F_80 ( V_90 ) ;
if ( V_4 -> V_20 == NULL ) {
F_54 ( V_4 ) ;
V_4 = NULL ;
goto V_41;
}
V_4 -> V_20 -> V_21 = 0 ;
F_12 ( V_127 , ( void * ) & V_4 -> V_20 -> V_21 ) ;
F_81 ( & V_23 -> V_24 , V_4 ) ;
V_4 -> V_23 = V_23 ;
F_82 ( & V_4 -> V_96 ) ;
F_83 ( & V_4 -> V_36 ) ;
V_4 -> V_32 = V_128 ;
V_4 -> V_129 = V_130 ;
V_4 -> V_33 = - 1 ;
F_84 ( & V_4 -> V_25 , F_68 ) ;
F_7 ( & V_23 -> V_24 , L_40 ,
V_4 , V_4 -> V_20 ) ;
V_41:
return V_4 ;
}
static void F_85 ( struct V_1 * V_4 )
{
F_7 ( & V_4 -> V_23 -> V_24 , L_41 , V_4 ) ;
F_61 ( V_4 ) ;
F_86 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_33 >= 0 )
F_87 ( V_4 -> V_33 , V_4 ) ;
if ( V_4 -> V_32 != V_128 )
F_88 ( V_4 -> V_23 , V_4 -> V_32 ) ;
if ( V_4 -> V_129 != V_130 )
F_89 ( V_4 -> V_129 , 0 ,
( unsigned long ) V_4 -> V_20 ) ;
else
F_90 ( ( unsigned long ) V_4 -> V_20 ) ;
F_81 ( & V_4 -> V_23 -> V_24 , NULL ) ;
F_54 ( V_4 ) ;
}
static int F_91 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
struct V_131 V_132 ;
T_7 V_133 ;
V_28 = F_92 ( V_4 -> V_23 , V_4 -> V_20 , 1 , & V_133 ) ;
if ( V_28 < 0 )
goto V_41;
V_4 -> V_129 = V_133 ;
V_28 = F_93 ( V_4 -> V_23 , & V_4 -> V_32 ) ;
if ( V_28 )
goto V_41;
V_28 = F_94 ( V_4 -> V_32 , F_71 ,
0 , L_42 , V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_4 -> V_33 = V_28 ;
V_134:
V_28 = F_95 ( & V_132 ) ;
if ( V_28 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_43
L_44 ) ;
goto V_41;
}
V_28 = F_97 ( V_132 , V_4 -> V_23 -> V_135 ,
L_45 , L_46 , V_4 -> V_129 ) ;
if ( ! V_28 )
V_28 = F_97 ( V_132 , V_4 -> V_23 -> V_135 ,
L_47 , L_46 , V_4 -> V_32 ) ;
if ( ! V_28 )
V_28 = F_97 ( V_132 , V_4 -> V_23 -> V_135 ,
L_48 , V_136 ) ;
if ( V_28 ) {
F_98 ( V_132 , 1 ) ;
F_96 ( V_4 -> V_23 , V_28 ,
L_49 ) ;
goto V_41;
} else {
V_28 = F_98 ( V_132 , 0 ) ;
if ( V_28 == - V_137 )
goto V_134;
else if ( V_28 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_50
L_51 ) ;
goto V_41;
}
}
F_99 ( V_4 -> V_23 , V_138 ) ;
F_7 ( & V_4 -> V_23 -> V_24 , L_52 ) ;
V_41:
return V_28 ;
}
static int F_100 ( struct V_1 * V_4 )
{
int V_28 = - V_139 ;
int V_59 , V_140 , V_141 ;
char V_142 [ 64 ] ;
unsigned int V_5 , V_6 ;
if ( F_101 ( V_4 -> V_23 -> V_135 ) !=
V_138 )
goto V_41;
V_28 = F_72 ( V_4 ) ;
if ( V_28 && V_28 != - V_124 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_53 ) ;
goto V_41;
}
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 ,
L_54 , L_55 , & V_140 ) ;
if ( V_28 == - V_145 ) {
F_103 ( V_4 -> V_23 , V_28 ,
L_56 ) ;
V_28 = F_42 ( V_4 , 0 , 0 ) ;
if ( V_28 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_57 ) ;
goto V_41;
}
V_140 = 0 ;
} else if ( V_28 != 1 ) {
if ( V_28 == 0 )
V_28 = - V_64 ;
F_96 ( V_4 -> V_23 , V_28 ,
L_58 ) ;
goto V_41;
}
for ( V_59 = 0 ; V_59 < V_140 ; V_59 ++ ) {
V_141 = snprintf ( V_142 , sizeof( V_142 ) , L_59 , V_59 ) ;
if ( F_104 ( V_141 >= ( sizeof( V_142 ) - 1 ) ) ) {
V_28 = - V_91 ;
goto V_41;
}
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 , V_142 ,
L_60 , & V_5 , & V_6 ) ;
if ( V_28 != 2 ) {
if ( V_28 >= 0 )
V_28 = - V_64 ;
F_96 ( V_4 -> V_23 , V_28 ,
L_61 , V_59 ) ;
goto V_41;
}
V_28 = F_42 ( V_4 , V_5 , V_6 ) ;
if ( V_28 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_62 ,
V_5 , V_6 ) ;
goto V_41;
}
}
V_28 = F_99 ( V_4 -> V_23 , V_146 ) ;
V_41:
return V_28 ;
}
static int F_105 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
enum V_147 V_148 ;
V_148 = F_101 ( V_4 -> V_23 -> V_135 ) ;
if ( V_148 >= V_149 )
goto V_41;
if ( V_148 == V_146 ) {
F_61 ( V_4 ) ;
F_77 ( V_4 ) ;
}
V_28 = F_99 ( V_4 -> V_23 , V_150 ) ;
V_41:
return V_28 ;
}
static int F_106 ( struct V_1 * V_4 )
{
int V_28 = - V_139 ;
int V_59 , V_140 , V_141 ;
unsigned int V_5 , V_6 ;
char V_142 [ 64 ] ;
if ( F_101 ( V_4 -> V_23 -> V_135 ) !=
V_151 )
goto V_41;
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 ,
L_54 , L_55 , & V_140 ) ;
if ( V_28 == - V_145 ) {
F_103 ( V_4 -> V_23 , V_28 ,
L_56 ) ;
V_28 = F_55 ( V_4 , 0 , 0 ) ;
if ( V_28 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_57 ) ;
goto V_41;
}
V_140 = 0 ;
} else if ( V_28 != 1 ) {
if ( V_28 == 0 )
V_28 = - V_64 ;
F_96 ( V_4 -> V_23 , V_28 ,
L_58 ) ;
goto V_41;
}
for ( V_59 = 0 ; V_59 < V_140 ; V_59 ++ ) {
V_141 = snprintf ( V_142 , sizeof( V_142 ) , L_59 , V_59 ) ;
if ( F_104 ( V_141 >= ( sizeof( V_142 ) - 1 ) ) ) {
V_28 = - V_91 ;
goto V_41;
}
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 , V_142 ,
L_60 , & V_5 , & V_6 ) ;
if ( V_28 != 2 ) {
if ( V_28 >= 0 )
V_28 = - V_64 ;
F_96 ( V_4 -> V_23 , V_28 ,
L_61 , V_59 ) ;
goto V_41;
}
V_28 = F_55 ( V_4 , V_5 , V_6 ) ;
if ( V_28 ) {
F_96 ( V_4 -> V_23 , V_28 ,
L_62 ,
V_5 , V_6 ) ;
goto V_41;
}
}
F_99 ( V_4 -> V_23 , V_146 ) ;
V_41:
return V_28 ;
}
static int F_107 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
int V_59 , V_152 ;
unsigned int V_5 , V_6 , V_153 , V_154 ;
struct V_56 * V_56 ;
char V_142 [ 64 ] ;
if ( F_101 ( V_4 -> V_23 -> V_135 ) !=
V_146 )
goto V_41;
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 , L_63 , L_55 ,
& V_152 ) ;
if ( V_28 != 1 ) {
if ( V_28 >= 0 )
V_28 = - V_64 ;
F_96 ( V_4 -> V_23 , V_28 ,
L_64 ) ;
goto V_41;
}
for ( V_59 = 0 ; V_59 < V_152 ; V_59 ++ ) {
int V_155 , V_102 ;
V_155 = snprintf ( V_142 , sizeof( V_142 ) , L_65 , V_59 ) ;
if ( F_104 ( V_155 >= ( sizeof( V_142 ) - 1 ) ) ) {
V_28 = - V_91 ;
goto V_41;
}
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 , V_142 , L_55 ,
& V_102 ) ;
if ( V_28 != 1 )
V_102 = V_156 ;
if ( V_102 != V_149 )
continue;
V_155 = snprintf ( V_142 , sizeof( V_142 ) , L_66 , V_59 ) ;
if ( F_104 ( V_155 >= ( sizeof( V_142 ) - 1 ) ) ) {
V_28 = - V_91 ;
goto V_41;
}
V_28 = F_102 ( V_143 , V_4 -> V_23 -> V_144 , V_142 ,
L_67 , & V_5 , & V_6 , & V_153 , & V_154 ) ;
if ( V_28 != 4 ) {
if ( V_28 >= 0 )
V_28 = - V_64 ;
F_96 ( V_4 -> V_23 , V_28 ,
L_68 , V_59 ) ;
goto V_41;
}
V_56 = F_108 ( V_5 , V_6 ,
F_109 ( V_153 , V_154 ) ) ;
if ( ! V_56 ) {
F_7 ( & V_4 -> V_23 -> V_24 ,
L_69 ,
V_5 , V_6 , V_153 , V_154 ) ;
continue;
}
F_47 () ;
F_60 ( V_56 ) ;
F_40 ( V_56 ) ;
F_49 () ;
F_7 ( & V_4 -> V_23 -> V_24 ,
L_70 ,
V_5 , V_6 , V_153 , V_154 ) ;
}
V_28 = F_99 ( V_4 -> V_23 , V_151 ) ;
V_41:
return V_28 ;
}
static void T_8 F_110 ( struct V_125 * V_23 ,
enum V_147 V_157 )
{
struct V_1 * V_4 = F_111 ( & V_23 -> V_24 ) ;
switch ( V_157 ) {
case V_156 :
case V_158 :
case V_159 :
case V_138 :
break;
case V_146 :
F_100 ( V_4 ) ;
break;
case V_150 :
if ( V_23 -> V_102 == V_150 )
break;
case V_149 :
F_29 ( & V_23 -> V_24 , L_71 ) ;
F_105 ( V_4 ) ;
break;
case V_151 :
F_107 ( V_4 ) ;
break;
case V_160 :
F_106 ( V_4 ) ;
break;
}
}
static int F_112 ( struct V_125 * V_23 ,
const struct V_161 * V_162 )
{
int V_28 = 0 ;
struct V_1 * V_4 = F_78 ( V_23 ) ;
if ( V_4 == NULL ) {
V_28 = - V_91 ;
F_96 ( V_23 , V_28 ,
L_72 ) ;
goto V_41;
}
V_28 = F_91 ( V_4 ) ;
if ( V_28 )
F_85 ( V_4 ) ;
V_41:
return V_28 ;
}
static int F_113 ( struct V_125 * V_23 )
{
struct V_1 * V_4 = F_111 ( & V_23 -> V_24 ) ;
if ( V_4 )
F_85 ( V_4 ) ;
return 0 ;
}
static int T_9 F_114 ( void )
{
if ( ! F_115 () || F_116 () )
return - V_54 ;
if ( ! F_117 () )
return - V_54 ;
F_34 ( 1 ) ;
return F_118 ( & V_163 ) ;
}
static void T_10 F_119 ( void )
{
F_120 ( & V_163 ) ;
F_34 ( 0 ) ;
}
