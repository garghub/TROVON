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
struct V_36 V_37 ;
F_10 ( & V_4 -> V_38 , V_30 ) ;
memcpy ( V_29 , V_27 , sizeof( struct V_26 ) ) ;
F_11 () ;
F_12 ( V_39 , ( unsigned long * ) & V_4 -> V_20 -> V_21 ) ;
F_13 ( V_31 ) ;
F_14 ( & V_37 ) ;
V_35 = F_15 ( & V_37 ) + 2 * ( T_2 ) V_40 ;
F_16 ( V_33 ) ;
while ( F_5 ( V_39 ,
( unsigned long * ) & V_4 -> V_20 -> V_21 ) ) {
F_17 ( V_33 , V_41 + 3 * V_42 ) ;
F_16 ( V_33 ) ;
F_14 ( & V_37 ) ;
V_34 = F_15 ( & V_37 ) ;
if ( V_34 > V_35 ) {
F_18 ( & V_4 -> V_23 -> V_24 ,
L_2 ) ;
F_19 ( V_39 ,
( unsigned long * ) & V_4 -> V_20 -> V_21 ) ;
V_28 = V_10 ;
goto V_43;
}
}
if ( F_5 ( V_19 ,
( unsigned long * ) & V_4 -> V_20 -> V_21 ) ) {
F_18 ( & V_4 -> V_23 -> V_24 ,
L_3 ) ;
F_4 ( V_4 ) ;
}
memcpy ( V_27 , V_29 , sizeof( struct V_26 ) ) ;
V_28 = V_27 -> V_28 ;
V_43:
F_20 ( & V_4 -> V_38 , V_30 ) ;
return V_28 ;
}
static int F_21 ( struct V_44 * V_6 , unsigned int V_45 ,
int V_46 , int V_47 , T_3 * V_48 )
{
int V_28 = 0 ;
struct V_26 V_27 = {
. V_49 = V_50 ,
. V_5 = F_22 ( V_6 ) ,
. V_6 = V_6 -> V_51 ,
. V_45 = V_45 ,
. V_52 = V_46 ,
. V_47 = V_47 ,
} ;
struct V_2 * V_3 = V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_54 )
F_23 ( & V_4 -> V_23 -> V_24 ,
L_4 ,
F_22 ( V_6 ) , V_6 -> V_51 , F_24 ( V_45 ) ,
F_25 ( V_45 ) , V_46 , V_47 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( F_26 ( ! V_28 ) ) {
if ( V_54 )
F_23 ( & V_4 -> V_23 -> V_24 , L_5 ,
V_27 . V_55 ) ;
* V_48 = V_27 . V_55 ;
} else if ( V_28 == - V_56 ) {
V_28 = 0 ;
* V_48 = 0 ;
}
return F_3 ( V_28 ) ;
}
static int F_27 ( struct V_44 * V_6 , unsigned int V_45 ,
int V_46 , int V_47 , T_3 V_48 )
{
struct V_26 V_27 = {
. V_49 = V_57 ,
. V_5 = F_22 ( V_6 ) ,
. V_6 = V_6 -> V_51 ,
. V_45 = V_45 ,
. V_52 = V_46 ,
. V_47 = V_47 ,
. V_55 = V_48 ,
} ;
struct V_2 * V_3 = V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_54 )
F_23 ( & V_4 -> V_23 -> V_24 ,
L_6
L_7 ,
F_22 ( V_6 ) , V_6 -> V_51 ,
F_24 ( V_45 ) , F_25 ( V_45 ) , V_46 , V_47 , V_48 ) ;
return F_3 ( F_9 ( V_4 , & V_27 ) ) ;
}
static int F_28 ( struct V_58 * V_24 ,
int V_59 [] , int V_60 )
{
int V_28 ;
int V_61 ;
struct V_26 V_27 = {
. V_49 = V_62 ,
. V_5 = F_22 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_51 ,
. V_45 = V_24 -> V_45 ,
. V_55 = V_60 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_63 * V_64 ;
if ( V_60 > V_65 ) {
F_18 ( & V_24 -> V_24 , L_8
L_9 , V_60 ) ;
return - V_66 ;
}
V_61 = 0 ;
F_29 (entry, &dev->msi_list, list) {
V_27 . V_67 [ V_61 ] . V_64 = V_64 -> V_68 . V_69 ;
V_27 . V_67 [ V_61 ] . V_59 = - 1 ;
V_61 ++ ;
}
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( F_26 ( ! V_28 ) ) {
if ( F_26 ( ! V_27 . V_55 ) ) {
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
if ( V_27 . V_67 [ V_61 ] . V_59 <= 0 ) {
F_30 ( & V_24 -> V_24 , L_10 ,
V_61 , V_27 . V_67 [ V_61 ] . V_59 ) ;
V_28 = - V_66 ;
V_59 [ V_61 ] = - 1 ;
continue;
}
V_59 [ V_61 ] = V_27 . V_67 [ V_61 ] . V_59 ;
}
} else {
F_31 ( V_70 L_11 ,
V_27 . V_55 ) ;
}
} else {
F_18 ( & V_24 -> V_24 , L_12 , V_28 ) ;
}
return V_28 ;
}
static void F_32 ( struct V_58 * V_24 )
{
int V_28 ;
struct V_26 V_27 = {
. V_49 = V_71 ,
. V_5 = F_22 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_51 ,
. V_45 = V_24 -> V_45 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( V_28 )
F_18 ( & V_24 -> V_24 , L_13 , V_28 ) ;
}
static int F_33 ( struct V_58 * V_24 , int V_59 [] )
{
int V_28 ;
struct V_26 V_27 = {
. V_49 = V_72 ,
. V_5 = F_22 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_51 ,
. V_45 = V_24 -> V_45 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( F_26 ( ! V_28 ) ) {
V_59 [ 0 ] = V_27 . V_55 ;
if ( V_27 . V_55 <= 0 ) {
F_30 ( & V_24 -> V_24 , L_14 ,
V_27 . V_55 ) ;
V_28 = - V_66 ;
V_59 [ 0 ] = - 1 ;
}
} else {
F_18 ( & V_24 -> V_24 , L_15
L_16 , V_27 . V_6 , V_27 . V_45 ) ;
V_28 = - V_66 ;
}
return V_28 ;
}
static void F_34 ( struct V_58 * V_24 )
{
int V_28 ;
struct V_26 V_27 = {
. V_49 = V_73 ,
. V_5 = F_22 ( V_24 -> V_6 ) ,
. V_6 = V_24 -> V_6 -> V_51 ,
. V_45 = V_24 -> V_45 ,
} ;
struct V_2 * V_3 = V_24 -> V_6 -> V_53 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_28 = F_9 ( V_4 , & V_27 ) ;
if ( V_28 == V_10 ) {
F_31 ( V_70 L_17 ) ;
return;
}
if ( V_28 )
F_31 ( V_70 L_18 ) ;
}
static void F_35 ( int V_74 )
{
if ( V_74 )
V_75 = & V_76 ;
else
V_75 = NULL ;
}
static inline void F_35 ( int V_74 ) { }
static int F_36 ( struct V_58 * V_24 , void * V_77 )
{
struct V_1 * V_4 = V_77 ;
int V_61 ;
struct V_78 * V_79 ;
for ( V_61 = 0 ; V_61 < V_80 ; V_61 ++ ) {
V_79 = & V_24 -> V_78 [ V_61 ] ;
if ( ! V_79 -> V_81 && V_79 -> V_82 && V_79 -> V_21 ) {
F_23 ( & V_4 -> V_23 -> V_24 , L_19 ,
F_37 ( V_24 ) , V_61 ) ;
if ( F_38 ( V_24 , V_61 ) ) {
F_18 ( & V_4 -> V_23 -> V_24 , L_20
L_21 ,
F_37 ( V_24 ) , V_61 ) ;
}
}
}
return 0 ;
}
static int T_4 F_39 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
struct V_44 * V_83 )
{
struct V_58 * V_84 ;
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < 0x100 ; V_45 ++ ) {
V_84 = F_40 ( V_83 , V_45 ) ;
if ( V_84 ) {
F_41 ( V_84 ) ;
continue;
}
V_84 = F_42 ( V_83 , V_45 ) ;
if ( V_84 )
F_23 ( & V_4 -> V_23 -> V_24 , L_22
L_23 , V_5 , V_6 ,
F_24 ( V_45 ) , F_25 ( V_45 ) ) ;
}
return 0 ;
}
static int T_4 F_43 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_44 * V_83 ;
struct V_2 * V_3 = NULL ;
struct V_85 * V_86 = NULL ;
int V_28 = 0 ;
#ifndef F_44
if ( V_5 != 0 ) {
F_18 ( & V_4 -> V_23 -> V_24 ,
L_24 , V_5 ) ;
F_18 ( & V_4 -> V_23 -> V_24 ,
L_25 ) ;
V_28 = - V_66 ;
goto V_87;
}
#endif
F_23 ( & V_4 -> V_23 -> V_24 , L_26 ,
V_5 , V_6 ) ;
V_86 = F_45 ( sizeof( * V_86 ) , V_88 ) ;
V_3 = F_45 ( sizeof( * V_3 ) , V_88 ) ;
if ( ! V_86 || ! V_3 ) {
V_28 = - V_89 ;
goto V_87;
}
F_2 ( V_3 , V_5 , V_6 , V_4 ) ;
V_83 = F_46 ( & V_4 -> V_23 -> V_24 , V_6 ,
& V_90 , V_3 ) ;
if ( ! V_83 ) {
F_18 ( & V_4 -> V_23 -> V_24 ,
L_27 ) ;
V_28 = - V_89 ;
goto V_87;
}
V_86 -> V_6 = V_83 ;
F_47 ( & V_86 -> V_91 , & V_4 -> V_92 ) ;
V_28 = F_39 ( V_4 , V_5 , V_6 , V_83 ) ;
F_48 ( V_83 , F_36 , V_4 ) ;
F_49 ( V_83 ) ;
return V_28 ;
V_87:
F_50 ( V_86 ) ;
F_50 ( V_3 ) ;
return V_28 ;
}
static int T_4 F_51 ( struct V_1 * V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
int V_28 ;
struct V_44 * V_83 ;
#ifndef F_44
if ( V_5 != 0 ) {
F_18 ( & V_4 -> V_23 -> V_24 ,
L_24 , V_5 ) ;
F_18 ( & V_4 -> V_23 -> V_24 ,
L_25 ) ;
return - V_66 ;
}
#endif
F_23 ( & V_4 -> V_23 -> V_24 , L_28 ,
V_5 , V_6 ) ;
V_83 = F_52 ( V_5 , V_6 ) ;
if ( ! V_83 )
return F_43 ( V_4 , V_5 , V_6 ) ;
V_28 = F_39 ( V_4 , V_5 , V_6 , V_83 ) ;
F_48 ( V_83 , F_36 , V_4 ) ;
F_49 ( V_83 ) ;
return V_28 ;
}
static void F_53 ( struct V_44 * V_6 )
{
struct V_58 * V_24 ;
while ( ! F_54 ( & V_6 -> V_93 ) ) {
V_24 = F_55 ( V_6 -> V_93 . V_94 , struct V_58 ,
V_95 ) ;
F_7 ( & V_24 -> V_24 , L_29 ) ;
F_56 ( V_24 ) ;
}
}
static void F_57 ( struct V_1 * V_4 )
{
struct V_85 * V_86 , * V_96 ;
F_7 ( & V_4 -> V_23 -> V_24 , L_30 ) ;
F_58 (bus_entry, t, &pdev->root_buses, list) {
F_59 ( & V_86 -> V_91 ) ;
F_53 ( V_86 -> V_6 ) ;
F_50 ( V_86 -> V_6 -> V_53 ) ;
F_60 ( V_86 -> V_6 -> V_97 ) ;
F_61 ( V_86 -> V_6 ) ;
F_50 ( V_86 ) ;
}
}
static T_5 F_62 ( int V_49 ,
struct V_1 * V_4 ,
T_6 V_98 )
{
T_5 V_99 ;
struct V_100 * V_101 ;
int V_6 = V_4 -> V_20 -> V_102 . V_6 ;
int V_45 = V_4 -> V_20 -> V_102 . V_45 ;
struct V_58 * V_103 ;
int V_104 = 0 ;
F_7 ( & V_4 -> V_23 -> V_24 ,
L_31 ,
V_49 , V_6 , V_45 ) ;
V_99 = V_105 ;
V_103 = F_63 ( V_6 , V_45 ) ;
if ( ! V_103 || ! V_103 -> V_106 ) {
F_18 ( & V_4 -> V_23 -> V_24 , L_32 ) ;
if ( V_103 )
F_41 ( V_103 ) ;
return V_99 ;
}
V_101 = V_103 -> V_106 ;
if ( F_64 ( & V_101 -> V_106 ) ) {
if ( V_101 -> V_107 && V_101 -> V_107 -> V_108 ) {
F_7 ( & V_103 -> V_24 ,
L_33 ) ;
if ( V_103 ) {
V_104 = 1 ;
switch ( V_49 ) {
case V_109 :
V_99 = V_101 -> V_107 ->
V_108 ( V_103 , V_98 ) ;
break;
case V_110 :
V_99 = V_101 -> V_107 ->
V_111 ( V_103 ) ;
break;
case V_112 :
V_99 = V_101 -> V_107 ->
V_113 ( V_103 ) ;
break;
case V_114 :
V_101 -> V_107 -> V_115 ( V_103 ) ;
break;
default:
F_18 ( & V_4 -> V_23 -> V_24 ,
L_34
L_35 ) ;
}
}
}
F_65 ( & V_101 -> V_106 ) ;
}
if ( ! V_104 )
V_99 = V_105 ;
return V_99 ;
}
static void F_66 ( struct V_116 * V_77 )
{
struct V_1 * V_4 =
F_55 ( V_77 , struct V_1 , V_25 ) ;
int V_49 = V_4 -> V_20 -> V_102 . V_49 ;
T_6 V_98 =
( T_6 ) V_4 -> V_20 -> V_102 . V_28 ;
F_7 ( & V_4 -> V_23 -> V_24 ,
L_36 ,
V_4 -> V_20 -> V_102 . V_6 , V_4 -> V_20 -> V_102 . V_45 ) ;
V_4 -> V_20 -> V_102 . V_28 = F_62 ( V_49 , V_4 , V_98 ) ;
F_11 () ;
F_19 ( V_19 , ( unsigned long * ) & V_4 -> V_20 -> V_21 ) ;
F_13 ( V_4 -> V_32 ) ;
F_67 () ;
F_19 ( V_22 , & V_4 -> V_21 ) ;
F_68 () ;
F_4 ( V_4 ) ;
}
static T_7 F_69 ( int V_33 , void * V_24 )
{
struct V_1 * V_4 = V_24 ;
F_4 ( V_4 ) ;
return V_117 ;
}
static int F_70 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
F_71 ( & V_118 ) ;
if ( ! V_119 ) {
F_23 ( & V_4 -> V_23 -> V_24 , L_37 ) ;
V_119 = V_4 ;
} else {
F_18 ( & V_4 -> V_23 -> V_24 , L_38 ) ;
V_28 = - V_120 ;
}
F_72 ( & V_118 ) ;
return V_28 ;
}
static void F_73 ( struct V_1 * V_4 )
{
F_71 ( & V_118 ) ;
if ( V_4 == V_119 ) {
F_23 ( & V_4 -> V_23 -> V_24 ,
L_39 ) ;
V_119 = NULL ;
}
F_72 ( & V_118 ) ;
}
static struct V_1 * F_74 ( struct V_121 * V_23 )
{
struct V_1 * V_4 ;
V_4 = F_75 ( sizeof( struct V_1 ) , V_88 ) ;
if ( V_4 == NULL )
goto V_43;
V_4 -> V_20 =
(struct V_122 * ) F_76 ( V_88 ) ;
if ( V_4 -> V_20 == NULL ) {
F_50 ( V_4 ) ;
V_4 = NULL ;
goto V_43;
}
V_4 -> V_20 -> V_21 = 0 ;
F_12 ( V_123 , ( void * ) & V_4 -> V_20 -> V_21 ) ;
F_77 ( & V_23 -> V_24 , V_4 ) ;
V_4 -> V_23 = V_23 ;
F_78 ( & V_4 -> V_92 ) ;
F_79 ( & V_4 -> V_38 ) ;
V_4 -> V_32 = V_124 ;
V_4 -> V_125 = V_126 ;
V_4 -> V_33 = - 1 ;
F_80 ( & V_4 -> V_25 , F_66 ) ;
F_7 ( & V_23 -> V_24 , L_40 ,
V_4 , V_4 -> V_20 ) ;
V_43:
return V_4 ;
}
static void F_81 ( struct V_1 * V_4 )
{
F_7 ( & V_4 -> V_23 -> V_24 , L_41 , V_4 ) ;
F_57 ( V_4 ) ;
F_82 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_33 >= 0 )
F_83 ( V_4 -> V_33 , V_4 ) ;
if ( V_4 -> V_32 != V_124 )
F_84 ( V_4 -> V_23 , V_4 -> V_32 ) ;
if ( V_4 -> V_125 != V_126 )
F_85 ( V_4 -> V_125 , 0 ,
( unsigned long ) V_4 -> V_20 ) ;
else
F_86 ( ( unsigned long ) V_4 -> V_20 ) ;
F_77 ( & V_4 -> V_23 -> V_24 , NULL ) ;
F_50 ( V_4 ) ;
}
static int F_87 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
struct V_127 V_128 ;
V_28 = F_88 ( V_4 -> V_23 , F_89 ( V_4 -> V_20 ) ) ;
if ( V_28 < 0 )
goto V_43;
V_4 -> V_125 = V_28 ;
V_28 = F_90 ( V_4 -> V_23 , & V_4 -> V_32 ) ;
if ( V_28 )
goto V_43;
V_28 = F_91 ( V_4 -> V_32 , F_69 ,
0 , L_42 , V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_4 -> V_33 = V_28 ;
V_129:
V_28 = F_92 ( & V_128 ) ;
if ( V_28 ) {
F_93 ( V_4 -> V_23 , V_28 ,
L_43
L_44 ) ;
goto V_43;
}
V_28 = F_94 ( V_128 , V_4 -> V_23 -> V_130 ,
L_45 , L_46 , V_4 -> V_125 ) ;
if ( ! V_28 )
V_28 = F_94 ( V_128 , V_4 -> V_23 -> V_130 ,
L_47 , L_46 , V_4 -> V_32 ) ;
if ( ! V_28 )
V_28 = F_94 ( V_128 , V_4 -> V_23 -> V_130 ,
L_48 , V_131 ) ;
if ( V_28 ) {
F_95 ( V_128 , 1 ) ;
F_93 ( V_4 -> V_23 , V_28 ,
L_49 ) ;
goto V_43;
} else {
V_28 = F_95 ( V_128 , 0 ) ;
if ( V_28 == - V_132 )
goto V_129;
else if ( V_28 ) {
F_93 ( V_4 -> V_23 , V_28 ,
L_50
L_51 ) ;
goto V_43;
}
}
F_96 ( V_4 -> V_23 , V_133 ) ;
F_7 ( & V_4 -> V_23 -> V_24 , L_52 ) ;
V_43:
return V_28 ;
}
static int T_4 F_97 ( struct V_1 * V_4 )
{
int V_28 = - V_134 ;
int V_61 , V_135 , V_136 ;
char V_137 [ 64 ] ;
unsigned int V_5 , V_6 ;
if ( F_98 ( V_4 -> V_23 -> V_130 ) !=
V_133 )
goto V_43;
V_28 = F_70 ( V_4 ) ;
if ( V_28 ) {
F_93 ( V_4 -> V_23 , V_28 ,
L_53 ) ;
goto V_43;
}
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 ,
L_54 , L_55 , & V_135 ) ;
if ( V_28 == - V_140 ) {
F_100 ( V_4 -> V_23 , V_28 ,
L_56 ) ;
V_28 = F_43 ( V_4 , 0 , 0 ) ;
V_135 = 0 ;
} else if ( V_28 != 1 ) {
if ( V_28 == 0 )
V_28 = - V_66 ;
F_93 ( V_4 -> V_23 , V_28 ,
L_57 ) ;
goto V_43;
}
for ( V_61 = 0 ; V_61 < V_135 ; V_61 ++ ) {
V_136 = snprintf ( V_137 , sizeof( V_137 ) , L_58 , V_61 ) ;
if ( F_101 ( V_136 >= ( sizeof( V_137 ) - 1 ) ) ) {
V_28 = - V_89 ;
goto V_43;
}
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 , V_137 ,
L_59 , & V_5 , & V_6 ) ;
if ( V_28 != 2 ) {
if ( V_28 >= 0 )
V_28 = - V_66 ;
F_93 ( V_4 -> V_23 , V_28 ,
L_60 , V_61 ) ;
goto V_43;
}
V_28 = F_43 ( V_4 , V_5 , V_6 ) ;
if ( V_28 ) {
F_93 ( V_4 -> V_23 , V_28 ,
L_61 ,
V_5 , V_6 ) ;
goto V_43;
}
}
V_28 = F_96 ( V_4 -> V_23 , V_141 ) ;
V_43:
return V_28 ;
}
static int F_102 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
enum V_142 V_143 ;
V_143 = F_98 ( V_4 -> V_23 -> V_130 ) ;
if ( V_143 >= V_144 )
goto V_43;
if ( V_143 == V_141 ) {
F_57 ( V_4 ) ;
F_73 ( V_4 ) ;
}
V_28 = F_96 ( V_4 -> V_23 , V_145 ) ;
V_43:
return V_28 ;
}
static int T_4 F_103 ( struct V_1 * V_4 )
{
int V_28 = - V_134 ;
int V_61 , V_135 , V_136 ;
unsigned int V_5 , V_6 ;
char V_137 [ 64 ] ;
if ( F_98 ( V_4 -> V_23 -> V_130 ) !=
V_146 )
goto V_43;
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 ,
L_54 , L_55 , & V_135 ) ;
if ( V_28 == - V_140 ) {
F_100 ( V_4 -> V_23 , V_28 ,
L_56 ) ;
V_28 = F_51 ( V_4 , 0 , 0 ) ;
V_135 = 0 ;
} else if ( V_28 != 1 ) {
if ( V_28 == 0 )
V_28 = - V_66 ;
F_93 ( V_4 -> V_23 , V_28 ,
L_57 ) ;
goto V_43;
}
for ( V_61 = 0 ; V_61 < V_135 ; V_61 ++ ) {
V_136 = snprintf ( V_137 , sizeof( V_137 ) , L_58 , V_61 ) ;
if ( F_101 ( V_136 >= ( sizeof( V_137 ) - 1 ) ) ) {
V_28 = - V_89 ;
goto V_43;
}
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 , V_137 ,
L_59 , & V_5 , & V_6 ) ;
if ( V_28 != 2 ) {
if ( V_28 >= 0 )
V_28 = - V_66 ;
F_93 ( V_4 -> V_23 , V_28 ,
L_60 , V_61 ) ;
goto V_43;
}
V_28 = F_51 ( V_4 , V_5 , V_6 ) ;
if ( V_28 ) {
F_93 ( V_4 -> V_23 , V_28 ,
L_61 ,
V_5 , V_6 ) ;
goto V_43;
}
}
F_96 ( V_4 -> V_23 , V_141 ) ;
V_43:
return V_28 ;
}
static int F_104 ( struct V_1 * V_4 )
{
int V_28 = 0 ;
int V_61 , V_147 ;
unsigned int V_5 , V_6 , V_148 , V_149 ;
struct V_44 * V_44 ;
struct V_58 * V_58 ;
char V_137 [ 64 ] ;
if ( F_98 ( V_4 -> V_23 -> V_130 ) !=
V_141 )
goto V_43;
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 , L_62 , L_55 ,
& V_147 ) ;
if ( V_28 != 1 ) {
if ( V_28 >= 0 )
V_28 = - V_66 ;
F_93 ( V_4 -> V_23 , V_28 ,
L_63 ) ;
goto V_43;
}
for ( V_61 = 0 ; V_61 < V_147 ; V_61 ++ ) {
int V_150 , V_98 ;
V_150 = snprintf ( V_137 , sizeof( V_137 ) , L_64 , V_61 ) ;
if ( F_101 ( V_150 >= ( sizeof( V_137 ) - 1 ) ) ) {
V_28 = - V_89 ;
goto V_43;
}
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 , V_137 , L_55 ,
& V_98 ) ;
if ( V_28 != 1 )
V_98 = V_151 ;
if ( V_98 != V_144 )
continue;
V_150 = snprintf ( V_137 , sizeof( V_137 ) , L_65 , V_61 ) ;
if ( F_101 ( V_150 >= ( sizeof( V_137 ) - 1 ) ) ) {
V_28 = - V_89 ;
goto V_43;
}
V_28 = F_99 ( V_138 , V_4 -> V_23 -> V_139 , V_137 ,
L_66 , & V_5 , & V_6 , & V_148 , & V_149 ) ;
if ( V_28 != 4 ) {
if ( V_28 >= 0 )
V_28 = - V_66 ;
F_93 ( V_4 -> V_23 , V_28 ,
L_67 , V_61 ) ;
goto V_43;
}
V_44 = F_52 ( V_5 , V_6 ) ;
if ( ! V_44 ) {
F_7 ( & V_4 -> V_23 -> V_24 , L_68 ,
V_5 , V_6 ) ;
continue;
}
V_58 = F_40 ( V_44 , F_105 ( V_148 , V_149 ) ) ;
if ( ! V_58 ) {
F_7 ( & V_4 -> V_23 -> V_24 ,
L_69 ,
V_5 , V_6 , V_148 , V_149 ) ;
continue;
}
F_56 ( V_58 ) ;
F_41 ( V_58 ) ;
F_7 ( & V_4 -> V_23 -> V_24 ,
L_70 ,
V_5 , V_6 , V_148 , V_149 ) ;
}
V_28 = F_96 ( V_4 -> V_23 , V_146 ) ;
V_43:
return V_28 ;
}
static void T_8 F_106 ( struct V_121 * V_23 ,
enum V_142 V_152 )
{
struct V_1 * V_4 = F_107 ( & V_23 -> V_24 ) ;
switch ( V_152 ) {
case V_151 :
case V_153 :
case V_154 :
case V_133 :
case V_145 :
break;
case V_141 :
F_97 ( V_4 ) ;
break;
case V_144 :
F_30 ( & V_23 -> V_24 , L_71 ) ;
F_102 ( V_4 ) ;
break;
case V_146 :
F_104 ( V_4 ) ;
break;
case V_155 :
F_103 ( V_4 ) ;
break;
}
}
static int F_108 ( struct V_121 * V_23 ,
const struct V_156 * V_157 )
{
int V_28 = 0 ;
struct V_1 * V_4 = F_74 ( V_23 ) ;
if ( V_4 == NULL ) {
V_28 = - V_89 ;
F_93 ( V_23 , V_28 ,
L_72 ) ;
goto V_43;
}
V_28 = F_87 ( V_4 ) ;
if ( V_28 )
F_81 ( V_4 ) ;
V_43:
return V_28 ;
}
static int F_109 ( struct V_121 * V_23 )
{
struct V_1 * V_4 = F_107 ( & V_23 -> V_24 ) ;
if ( V_4 )
F_81 ( V_4 ) ;
return 0 ;
}
static int T_9 F_110 ( void )
{
if ( ! F_111 () || F_112 () )
return - V_56 ;
F_35 ( 1 ) ;
return F_113 ( & V_158 ) ;
}
static void T_10 F_114 ( void )
{
F_115 ( & V_158 ) ;
F_35 ( 0 ) ;
}
