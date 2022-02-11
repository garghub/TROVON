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
static long F_46 ( struct V_32 * V_32 ,
unsigned int V_64 , unsigned long V_65 )
{
int V_36 ;
struct V_2 * V_3 = V_32 -> V_41 ;
void T_4 * V_66 = ( void T_4 * ) V_65 ;
F_22 ( & V_3 -> V_55 ) ;
switch ( V_64 ) {
case V_67 : {
struct V_68 V_69 ;
struct V_70 V_71 ;
V_36 = - V_72 ;
if ( V_3 -> V_73 != V_74 )
break;
V_36 = - V_49 ;
if ( F_29 ( & V_69 , V_66 , sizeof( V_69 ) ) )
break;
V_71 . V_75 = V_69 . V_75 ;
V_71 . V_76 = F_47 ( 0 ) ;
V_36 = F_41 ( V_77 ,
& V_71 ) ;
if ( V_36 != 0 )
break;
V_36 = F_37 ( V_3 , V_71 . V_15 ) ;
if ( V_36 == 0 )
V_36 = V_71 . V_15 ;
break;
}
case V_78 : {
struct V_79 V_69 ;
struct V_80 V_81 ;
V_36 = - V_49 ;
if ( F_29 ( & V_69 , V_66 , sizeof( V_69 ) ) )
break;
V_36 = - V_72 ;
if ( V_3 -> V_73 != V_74 &&
V_3 -> V_73 != V_69 . V_82 )
break;
V_81 . V_83 = V_69 . V_82 ;
V_81 . V_84 = V_69 . V_84 ;
V_36 = F_41 ( V_85 ,
& V_81 ) ;
if ( V_36 != 0 )
break;
V_36 = F_37 ( V_3 , V_81 . V_86 ) ;
if ( V_36 == 0 )
V_36 = V_81 . V_86 ;
break;
}
case V_87 : {
struct V_88 V_69 ;
struct V_89 V_90 ;
V_36 = - V_72 ;
if ( V_3 -> V_73 != V_74 )
break;
V_36 = - V_49 ;
if ( F_29 ( & V_69 , V_66 , sizeof( V_69 ) ) )
break;
V_90 . V_91 = V_92 ;
V_90 . V_83 = V_69 . V_82 ;
V_36 = F_41 ( V_93 ,
& V_90 ) ;
if ( V_36 != 0 )
break;
V_36 = F_37 ( V_3 , V_90 . V_15 ) ;
if ( V_36 == 0 )
V_36 = V_90 . V_15 ;
break;
}
case V_94 : {
struct V_95 V_96 ;
struct V_6 * V_7 ;
V_36 = - V_49 ;
if ( F_29 ( & V_96 , V_66 , sizeof( V_96 ) ) )
break;
V_36 = - V_97 ;
if ( V_96 . V_15 >= F_48 () )
break;
V_36 = - V_98 ;
V_7 = F_12 ( V_3 , V_96 . V_15 ) ;
if ( ! V_7 )
break;
F_49 ( F_31 ( V_96 . V_15 ) ) ;
F_43 ( V_3 , V_7 ) ;
V_36 = 0 ;
break;
}
case V_99 : {
struct V_100 V_101 ;
struct V_6 * V_7 ;
V_36 = - V_49 ;
if ( F_29 ( & V_101 , V_66 , sizeof( V_101 ) ) )
break;
V_36 = - V_98 ;
V_7 = F_12 ( V_3 , V_101 . V_15 ) ;
if ( V_7 ) {
F_50 ( V_101 . V_15 ) ;
V_36 = 0 ;
}
break;
}
case V_102 : {
F_22 ( & V_3 -> V_43 ) ;
F_35 ( & V_3 -> V_23 ) ;
V_3 -> V_25 = V_3 -> V_24 = V_3 -> V_30 = 0 ;
F_36 ( & V_3 -> V_23 ) ;
F_23 ( & V_3 -> V_43 ) ;
V_36 = 0 ;
break;
}
case V_103 : {
struct V_104 V_105 ;
V_36 = - V_72 ;
if ( V_3 -> V_73 != V_74 )
break;
V_36 = - V_49 ;
if ( F_29 ( & V_105 , V_66 , sizeof( V_105 ) ) )
break;
V_36 = - V_97 ;
if ( V_105 . V_106 == 0 || V_105 . V_106 >= V_107 )
break;
V_3 -> V_73 = V_105 . V_106 ;
V_36 = 0 ;
break;
}
default:
V_36 = - V_108 ;
break;
}
F_23 ( & V_3 -> V_55 ) ;
return V_36 ;
}
static unsigned int F_51 ( struct V_32 * V_32 , T_7 * V_109 )
{
unsigned int V_110 = V_111 | V_112 ;
struct V_2 * V_3 = V_32 -> V_41 ;
F_52 ( V_32 , & V_3 -> V_26 , V_109 ) ;
if ( V_3 -> V_25 != V_3 -> V_24 )
V_110 |= V_113 | V_114 ;
if ( V_3 -> V_30 )
V_110 = V_115 ;
return V_110 ;
}
static int F_53 ( int V_116 , struct V_32 * V_117 , int V_118 )
{
struct V_2 * V_3 = V_117 -> V_41 ;
return F_54 ( V_116 , V_117 , V_118 , & V_3 -> V_27 ) ;
}
static int F_55 ( struct V_119 * V_119 , struct V_32 * V_117 )
{
struct V_2 * V_3 ;
V_3 = F_38 ( sizeof( * V_3 ) , V_52 ) ;
if ( V_3 == NULL )
return - V_53 ;
V_3 -> V_62 = F_56 ( V_52 , L_2 , V_120 -> V_121 ) ;
if ( V_3 -> V_62 == NULL ) {
F_11 ( V_3 ) ;
return - V_53 ;
}
F_57 ( & V_3 -> V_26 ) ;
F_58 ( & V_3 -> V_55 ) ;
F_58 ( & V_3 -> V_43 ) ;
F_59 ( & V_3 -> V_23 ) ;
V_3 -> V_73 = V_74 ;
V_117 -> V_41 = V_3 ;
return F_60 ( V_119 , V_117 ) ;
}
static int F_61 ( struct V_119 * V_119 , struct V_32 * V_117 )
{
struct V_2 * V_3 = V_117 -> V_41 ;
struct V_8 * V_14 ;
while ( ( V_14 = V_3 -> V_10 . V_8 ) ) {
struct V_6 * V_7 ;
V_7 = F_6 ( V_14 , struct V_6 , V_14 ) ;
F_49 ( F_31 ( V_7 -> V_15 ) ) ;
F_43 ( V_3 , V_7 ) ;
}
F_1 ( V_3 -> V_1 ) ;
F_11 ( V_3 -> V_62 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int T_8 F_62 ( void )
{
int V_61 ;
if ( ! F_63 () )
return - V_122 ;
V_61 = F_64 ( & V_123 ) ;
if ( V_61 != 0 ) {
F_65 ( L_3 ) ;
return V_61 ;
}
F_66 ( L_4 ) ;
return 0 ;
}
static void T_9 F_67 ( void )
{
F_68 ( & V_123 ) ;
}
