static void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 ) ;
}
static unsigned int F_3 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
return V_4 & ( V_3 -> V_5 - 1 ) ;
}
static T_1 * F_4 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
return V_3 -> V_1 + F_3 ( V_3 , V_4 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
struct V_8 * * V_9 = & ( V_3 -> V_10 . V_8 ) , * V_11 = NULL ;
V_3 -> V_12 ++ ;
while ( * V_9 ) {
struct V_6 * V_13 ;
V_13 = F_6 ( * V_9 , struct V_6 , V_14 ) ;
V_11 = * V_9 ;
if ( V_13 -> V_15 < V_7 -> V_15 )
V_9 = & ( ( * V_9 ) -> V_16 ) ;
else if ( V_13 -> V_15 > V_7 -> V_15 )
V_9 = & ( ( * V_9 ) -> V_17 ) ;
else
return - V_18 ;
}
F_7 ( & V_7 -> V_14 , V_11 , V_9 ) ;
F_8 ( & V_7 -> V_14 , & V_3 -> V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
V_3 -> V_12 -- ;
F_10 ( & V_7 -> V_14 , & V_3 -> V_10 ) ;
F_11 ( V_7 ) ;
}
static struct V_6 * F_12 ( struct V_2 * V_3 , unsigned V_15 )
{
struct V_8 * V_14 = V_3 -> V_10 . V_8 ;
while ( V_14 ) {
struct V_6 * V_7 ;
V_7 = F_6 ( V_14 , struct V_6 , V_14 ) ;
if ( V_7 -> V_15 < V_15 )
V_14 = V_14 -> V_16 ;
else if ( V_7 -> V_15 > V_15 )
V_14 = V_14 -> V_17 ;
else
return V_7 ;
}
return NULL ;
}
static T_2 F_13 ( int V_19 , void * V_20 )
{
struct V_6 * V_7 = V_20 ;
struct V_2 * V_3 = V_7 -> V_21 ;
F_14 ( ! V_7 -> V_22 ,
L_1 ,
V_7 -> V_15 , V_3 ) ;
F_15 ( V_19 ) ;
V_7 -> V_22 = false ;
F_16 ( & V_3 -> V_23 ) ;
if ( ( V_3 -> V_24 - V_3 -> V_25 ) < V_3 -> V_5 ) {
* F_4 ( V_3 , V_3 -> V_24 ) = V_7 -> V_15 ;
F_17 () ;
if ( V_3 -> V_25 == V_3 -> V_24 ++ ) {
F_18 ( & V_3 -> V_26 ) ;
F_19 ( & V_3 -> V_27 ,
V_28 , V_29 ) ;
}
} else
V_3 -> V_30 = 1 ;
F_20 ( & V_3 -> V_23 ) ;
return V_31 ;
}
static T_3 F_21 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_5 V_34 , T_6 * V_35 )
{
int V_36 ;
unsigned int V_37 , V_38 , V_39 = 0 , V_40 = 0 ;
struct V_2 * V_3 = V_32 -> V_41 ;
V_34 &= ~ ( sizeof( T_1 ) - 1 ) ;
if ( V_34 == 0 )
return 0 ;
if ( V_34 > V_42 )
V_34 = V_42 ;
for (; ; ) {
F_22 ( & V_3 -> V_43 ) ;
V_36 = - V_44 ;
if ( V_3 -> V_30 )
goto V_45;
V_37 = V_3 -> V_25 ;
V_38 = V_3 -> V_24 ;
if ( V_37 != V_38 )
break;
F_23 ( & V_3 -> V_43 ) ;
if ( V_32 -> V_46 & V_47 )
return - V_48 ;
V_36 = F_24 ( V_3 -> V_26 ,
V_3 -> V_25 != V_3 -> V_24 ) ;
if ( V_36 )
return V_36 ;
}
if ( ( ( V_37 ^ V_38 ) & V_3 -> V_5 ) != 0 ) {
V_39 = ( V_3 -> V_5 - F_3 ( V_3 , V_37 ) ) *
sizeof( T_1 ) ;
V_40 = F_3 ( V_3 , V_38 ) * sizeof( T_1 ) ;
} else {
V_39 = ( V_38 - V_37 ) * sizeof( T_1 ) ;
V_40 = 0 ;
}
if ( V_39 > V_34 ) {
V_39 = V_34 ;
V_40 = 0 ;
} else if ( ( V_39 + V_40 ) > V_34 ) {
V_40 = V_34 - V_39 ;
}
V_36 = - V_49 ;
F_25 () ;
if ( F_26 ( V_33 , F_4 ( V_3 , V_37 ) , V_39 ) ||
( ( V_40 != 0 ) &&
F_26 ( & V_33 [ V_39 ] , & V_3 -> V_1 [ 0 ] , V_40 ) ) )
goto V_45;
V_3 -> V_25 += ( V_39 + V_40 ) / sizeof( T_1 ) ;
V_36 = V_39 + V_40 ;
V_45:
F_23 ( & V_3 -> V_43 ) ;
return V_36 ;
}
static T_3 F_27 ( struct V_32 * V_32 , const char T_4 * V_33 ,
T_5 V_34 , T_6 * V_35 )
{
int V_36 , V_50 ;
T_1 * V_51 = ( T_1 * ) F_28 ( V_52 ) ;
struct V_2 * V_3 = V_32 -> V_41 ;
if ( V_51 == NULL )
return - V_53 ;
V_34 &= ~ ( sizeof( T_1 ) - 1 ) ;
V_36 = 0 ;
if ( V_34 == 0 )
goto V_54;
if ( V_34 > V_42 )
V_34 = V_42 ;
V_36 = - V_49 ;
if ( F_29 ( V_51 , V_33 , V_34 ) != 0 )
goto V_54;
F_22 ( & V_3 -> V_55 ) ;
for ( V_50 = 0 ; V_50 < ( V_34 / sizeof( T_1 ) ) ; V_50 ++ ) {
unsigned V_15 = V_51 [ V_50 ] ;
struct V_6 * V_7 ;
V_7 = F_12 ( V_3 , V_15 ) ;
if ( V_7 && ! V_7 -> V_22 ) {
V_7 -> V_22 = true ;
F_30 ( F_31 ( V_15 ) ) ;
}
}
F_23 ( & V_3 -> V_55 ) ;
V_36 = V_34 ;
V_54:
F_32 ( ( unsigned long ) V_51 ) ;
return V_36 ;
}
static int F_33 ( struct V_2 * V_3 )
{
unsigned int V_56 ;
T_1 * V_57 , * V_58 ;
if ( V_3 -> V_12 <= V_3 -> V_5 )
return 0 ;
if ( V_3 -> V_5 == 0 )
V_56 = 64 ;
else
V_56 = 2 * V_3 -> V_5 ;
V_57 = F_34 ( V_56 * sizeof( * V_57 ) , V_52 ) ;
if ( ! V_57 )
return - V_53 ;
V_58 = V_3 -> V_1 ;
F_22 ( & V_3 -> V_43 ) ;
F_35 ( & V_3 -> V_23 ) ;
memcpy ( V_57 , V_58 , V_3 -> V_5 * sizeof( * V_3 -> V_1 ) ) ;
memcpy ( V_57 + V_3 -> V_5 , V_58 ,
V_3 -> V_5 * sizeof( * V_3 -> V_1 ) ) ;
V_3 -> V_1 = V_57 ;
V_3 -> V_5 = V_56 ;
F_36 ( & V_3 -> V_23 ) ;
F_23 ( & V_3 -> V_43 ) ;
F_1 ( V_58 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , int V_15 )
{
struct V_6 * V_7 ;
struct V_59 V_60 ;
int V_36 = 0 ;
V_7 = F_38 ( sizeof( * V_7 ) , V_52 ) ;
if ( ! V_7 )
return - V_53 ;
V_7 -> V_21 = V_3 ;
V_7 -> V_15 = V_15 ;
V_7 -> V_22 = true ;
V_36 = F_5 ( V_3 , V_7 ) ;
if ( V_36 < 0 )
goto V_61;
V_36 = F_33 ( V_3 ) ;
if ( V_36 < 0 )
goto V_61;
V_36 = F_39 ( V_15 , F_13 , 0 ,
V_3 -> V_62 , V_7 ) ;
if ( V_36 < 0 )
goto V_61;
V_36 = F_40 ( V_15 ) ;
return V_36 ;
V_61:
V_60 . V_15 = V_15 ;
if ( F_41 ( V_63 , & V_60 ) != 0 )
F_42 () ;
F_9 ( V_3 , V_7 ) ;
return V_36 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_19 = F_31 ( V_7 -> V_15 ) ;
F_44 ( V_19 < 0 ) ;
F_45 ( V_19 , V_7 ) ;
F_9 ( V_3 , V_7 ) ;
}
static void F_46 ( int V_7 )
{
unsigned int V_64 , V_19 ;
struct V_65 * V_66 ;
unsigned long V_67 ;
V_19 = F_31 ( V_7 ) ;
V_66 = F_47 ( V_19 ) ;
if ( ! V_66 )
return;
F_48 ( & V_66 -> V_68 , V_67 ) ;
V_64 = F_49 ( V_69 ) ;
V_64 = F_50 ( V_64 ,
V_66 -> V_70 . V_71 , V_72 ) ;
if ( F_51 ( V_64 >= V_73 ) )
V_64 = F_52 ( V_66 -> V_70 . V_71 ,
V_72 ) ;
F_53 ( V_69 , V_64 ) ;
F_54 ( V_7 , V_64 ) ;
F_55 ( & V_66 -> V_68 , V_67 ) ;
}
static long F_56 ( struct V_32 * V_32 ,
unsigned int V_74 , unsigned long V_75 )
{
int V_36 ;
struct V_2 * V_3 = V_32 -> V_41 ;
void T_4 * V_76 = ( void T_4 * ) V_75 ;
F_22 ( & V_3 -> V_55 ) ;
switch ( V_74 ) {
case V_77 : {
struct V_78 V_79 ;
struct V_80 V_81 ;
V_36 = - V_82 ;
if ( V_3 -> V_83 != V_84 )
break;
V_36 = - V_49 ;
if ( F_29 ( & V_79 , V_76 , sizeof( V_79 ) ) )
break;
V_81 . V_85 = V_79 . V_85 ;
V_81 . V_86 = F_57 ( 0 ) ;
V_36 = F_41 ( V_87 ,
& V_81 ) ;
if ( V_36 != 0 )
break;
V_36 = F_37 ( V_3 , V_81 . V_15 ) ;
if ( V_36 == 0 )
V_36 = V_81 . V_15 ;
break;
}
case V_88 : {
struct V_89 V_79 ;
struct V_90 V_91 ;
V_36 = - V_49 ;
if ( F_29 ( & V_79 , V_76 , sizeof( V_79 ) ) )
break;
V_36 = - V_82 ;
if ( V_3 -> V_83 != V_84 &&
V_3 -> V_83 != V_79 . V_92 )
break;
V_91 . V_93 = V_79 . V_92 ;
V_91 . V_94 = V_79 . V_94 ;
V_36 = F_41 ( V_95 ,
& V_91 ) ;
if ( V_36 != 0 )
break;
V_36 = F_37 ( V_3 , V_91 . V_96 ) ;
if ( V_36 == 0 ) {
V_36 = V_91 . V_96 ;
F_46 ( V_36 ) ;
}
break;
}
case V_97 : {
struct V_98 V_79 ;
struct V_99 V_100 ;
V_36 = - V_82 ;
if ( V_3 -> V_83 != V_84 )
break;
V_36 = - V_49 ;
if ( F_29 ( & V_79 , V_76 , sizeof( V_79 ) ) )
break;
V_100 . V_101 = V_102 ;
V_100 . V_93 = V_79 . V_92 ;
V_36 = F_41 ( V_103 ,
& V_100 ) ;
if ( V_36 != 0 )
break;
V_36 = F_37 ( V_3 , V_100 . V_15 ) ;
if ( V_36 == 0 )
V_36 = V_100 . V_15 ;
break;
}
case V_104 : {
struct V_105 V_106 ;
struct V_6 * V_7 ;
V_36 = - V_49 ;
if ( F_29 ( & V_106 , V_76 , sizeof( V_106 ) ) )
break;
V_36 = - V_107 ;
if ( V_106 . V_15 >= F_58 () )
break;
V_36 = - V_108 ;
V_7 = F_12 ( V_3 , V_106 . V_15 ) ;
if ( ! V_7 )
break;
F_59 ( F_31 ( V_106 . V_15 ) ) ;
F_43 ( V_3 , V_7 ) ;
V_36 = 0 ;
break;
}
case V_109 : {
struct V_110 V_111 ;
struct V_6 * V_7 ;
V_36 = - V_49 ;
if ( F_29 ( & V_111 , V_76 , sizeof( V_111 ) ) )
break;
V_36 = - V_108 ;
V_7 = F_12 ( V_3 , V_111 . V_15 ) ;
if ( V_7 ) {
F_60 ( V_111 . V_15 ) ;
V_36 = 0 ;
}
break;
}
case V_112 : {
F_22 ( & V_3 -> V_43 ) ;
F_35 ( & V_3 -> V_23 ) ;
V_3 -> V_25 = V_3 -> V_24 = V_3 -> V_30 = 0 ;
F_36 ( & V_3 -> V_23 ) ;
F_23 ( & V_3 -> V_43 ) ;
V_36 = 0 ;
break;
}
case V_113 : {
struct V_114 V_115 ;
V_36 = - V_82 ;
if ( V_3 -> V_83 != V_84 )
break;
V_36 = - V_49 ;
if ( F_29 ( & V_115 , V_76 , sizeof( V_115 ) ) )
break;
V_36 = - V_107 ;
if ( V_115 . V_116 == 0 || V_115 . V_116 >= V_117 )
break;
V_3 -> V_83 = V_115 . V_116 ;
V_36 = 0 ;
break;
}
default:
V_36 = - V_118 ;
break;
}
F_23 ( & V_3 -> V_55 ) ;
return V_36 ;
}
static unsigned int F_61 ( struct V_32 * V_32 , T_7 * V_119 )
{
unsigned int V_120 = V_121 | V_122 ;
struct V_2 * V_3 = V_32 -> V_41 ;
F_62 ( V_32 , & V_3 -> V_26 , V_119 ) ;
if ( V_3 -> V_25 != V_3 -> V_24 )
V_120 |= V_123 | V_124 ;
if ( V_3 -> V_30 )
V_120 = V_125 ;
return V_120 ;
}
static int F_63 ( int V_126 , struct V_32 * V_127 , int V_128 )
{
struct V_2 * V_3 = V_127 -> V_41 ;
return F_64 ( V_126 , V_127 , V_128 , & V_3 -> V_27 ) ;
}
static int F_65 ( struct V_129 * V_129 , struct V_32 * V_127 )
{
struct V_2 * V_3 ;
V_3 = F_38 ( sizeof( * V_3 ) , V_52 ) ;
if ( V_3 == NULL )
return - V_53 ;
V_3 -> V_62 = F_66 ( V_52 , L_2 , V_130 -> V_131 ) ;
if ( V_3 -> V_62 == NULL ) {
F_11 ( V_3 ) ;
return - V_53 ;
}
F_67 ( & V_3 -> V_26 ) ;
F_68 ( & V_3 -> V_55 ) ;
F_68 ( & V_3 -> V_43 ) ;
F_69 ( & V_3 -> V_23 ) ;
V_3 -> V_83 = V_84 ;
V_127 -> V_41 = V_3 ;
return F_70 ( V_129 , V_127 ) ;
}
static int F_71 ( struct V_129 * V_129 , struct V_32 * V_127 )
{
struct V_2 * V_3 = V_127 -> V_41 ;
struct V_8 * V_14 ;
while ( ( V_14 = V_3 -> V_10 . V_8 ) ) {
struct V_6 * V_7 ;
V_7 = F_6 ( V_14 , struct V_6 , V_14 ) ;
F_59 ( F_31 ( V_7 -> V_15 ) ) ;
F_43 ( V_3 , V_7 ) ;
}
F_1 ( V_3 -> V_1 ) ;
F_11 ( V_3 -> V_62 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int T_8 F_72 ( void )
{
int V_61 ;
if ( ! F_73 () )
return - V_132 ;
V_61 = F_74 ( & V_133 ) ;
if ( V_61 != 0 ) {
F_75 ( L_3 ) ;
return V_61 ;
}
F_76 ( L_4 ) ;
return 0 ;
}
static void T_9 F_77 ( void )
{
F_78 ( & V_133 ) ;
}
