static T_1 * F_1 ( unsigned int V_1 )
{
T_1 * V_2 ;
T_2 V_3 = V_1 * sizeof( * V_2 ) ;
V_2 = F_2 ( V_3 , V_4 ) ;
if ( ! V_2 )
V_2 = F_3 ( V_3 ) ;
return V_2 ;
}
static void F_4 ( T_1 * V_2 )
{
F_5 ( V_2 ) ;
}
static unsigned int F_6 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return V_7 & ( V_6 -> V_8 - 1 ) ;
}
static T_1 * F_7 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
return V_6 -> V_2 + F_6 ( V_6 , V_7 ) ;
}
static int F_8 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_11 * * V_12 = & ( V_6 -> V_13 . V_11 ) , * V_14 = NULL ;
V_6 -> V_15 ++ ;
while ( * V_12 ) {
struct V_9 * V_16 ;
V_16 = F_9 ( * V_12 , struct V_9 , V_17 ) ;
V_14 = * V_12 ;
if ( V_16 -> V_18 < V_10 -> V_18 )
V_12 = & ( ( * V_12 ) -> V_19 ) ;
else if ( V_16 -> V_18 > V_10 -> V_18 )
V_12 = & ( ( * V_12 ) -> V_20 ) ;
else
return - V_21 ;
}
F_10 ( & V_10 -> V_17 , V_14 , V_12 ) ;
F_11 ( & V_10 -> V_17 , & V_6 -> V_13 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
V_6 -> V_15 -- ;
F_13 ( & V_10 -> V_17 , & V_6 -> V_13 ) ;
F_14 ( V_10 ) ;
}
static struct V_9 * F_15 ( struct V_5 * V_6 , unsigned V_18 )
{
struct V_11 * V_17 = V_6 -> V_13 . V_11 ;
while ( V_17 ) {
struct V_9 * V_10 ;
V_10 = F_9 ( V_17 , struct V_9 , V_17 ) ;
if ( V_10 -> V_18 < V_18 )
V_17 = V_17 -> V_19 ;
else if ( V_10 -> V_18 > V_18 )
V_17 = V_17 -> V_20 ;
else
return V_10 ;
}
return NULL ;
}
static T_3 F_16 ( int V_22 , void * V_23 )
{
struct V_9 * V_10 = V_23 ;
struct V_5 * V_6 = V_10 -> V_24 ;
F_17 ( ! V_10 -> V_25 ,
L_1 ,
V_10 -> V_18 , V_6 ) ;
F_18 ( V_22 ) ;
V_10 -> V_25 = false ;
F_19 ( & V_6 -> V_26 ) ;
if ( ( V_6 -> V_27 - V_6 -> V_28 ) < V_6 -> V_8 ) {
* F_7 ( V_6 , V_6 -> V_27 ) = V_10 -> V_18 ;
F_20 () ;
if ( V_6 -> V_28 == V_6 -> V_27 ++ ) {
F_21 ( & V_6 -> V_29 ) ;
F_22 ( & V_6 -> V_30 ,
V_31 , V_32 ) ;
}
} else
V_6 -> V_33 = 1 ;
F_23 ( & V_6 -> V_26 ) ;
return V_34 ;
}
static T_4 F_24 ( struct V_35 * V_35 , char T_5 * V_36 ,
T_2 V_37 , T_6 * V_38 )
{
int V_39 ;
unsigned int V_40 , V_41 , V_42 = 0 , V_43 = 0 ;
struct V_5 * V_6 = V_35 -> V_44 ;
V_37 &= ~ ( sizeof( T_1 ) - 1 ) ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 > V_45 )
V_37 = V_45 ;
for (; ; ) {
F_25 ( & V_6 -> V_46 ) ;
V_39 = - V_47 ;
if ( V_6 -> V_33 )
goto V_48;
V_40 = V_6 -> V_28 ;
V_41 = V_6 -> V_27 ;
if ( V_40 != V_41 )
break;
F_26 ( & V_6 -> V_46 ) ;
if ( V_35 -> V_49 & V_50 )
return - V_51 ;
V_39 = F_27 ( V_6 -> V_29 ,
V_6 -> V_28 != V_6 -> V_27 ) ;
if ( V_39 )
return V_39 ;
}
if ( ( ( V_40 ^ V_41 ) & V_6 -> V_8 ) != 0 ) {
V_42 = ( V_6 -> V_8 - F_6 ( V_6 , V_40 ) ) *
sizeof( T_1 ) ;
V_43 = F_6 ( V_6 , V_41 ) * sizeof( T_1 ) ;
} else {
V_42 = ( V_41 - V_40 ) * sizeof( T_1 ) ;
V_43 = 0 ;
}
if ( V_42 > V_37 ) {
V_42 = V_37 ;
V_43 = 0 ;
} else if ( ( V_42 + V_43 ) > V_37 ) {
V_43 = V_37 - V_42 ;
}
V_39 = - V_52 ;
F_28 () ;
if ( F_29 ( V_36 , F_7 ( V_6 , V_40 ) , V_42 ) ||
( ( V_43 != 0 ) &&
F_29 ( & V_36 [ V_42 ] , & V_6 -> V_2 [ 0 ] , V_43 ) ) )
goto V_48;
V_6 -> V_28 += ( V_42 + V_43 ) / sizeof( T_1 ) ;
V_39 = V_42 + V_43 ;
V_48:
F_26 ( & V_6 -> V_46 ) ;
return V_39 ;
}
static T_4 F_30 ( struct V_35 * V_35 , const char T_5 * V_36 ,
T_2 V_37 , T_6 * V_38 )
{
int V_39 , V_53 ;
T_1 * V_54 = ( T_1 * ) F_31 ( V_4 ) ;
struct V_5 * V_6 = V_35 -> V_44 ;
if ( V_54 == NULL )
return - V_55 ;
V_37 &= ~ ( sizeof( T_1 ) - 1 ) ;
V_39 = 0 ;
if ( V_37 == 0 )
goto V_56;
if ( V_37 > V_45 )
V_37 = V_45 ;
V_39 = - V_52 ;
if ( F_32 ( V_54 , V_36 , V_37 ) != 0 )
goto V_56;
F_25 ( & V_6 -> V_57 ) ;
for ( V_53 = 0 ; V_53 < ( V_37 / sizeof( T_1 ) ) ; V_53 ++ ) {
unsigned V_18 = V_54 [ V_53 ] ;
struct V_9 * V_10 ;
V_10 = F_15 ( V_6 , V_18 ) ;
if ( V_10 && ! V_10 -> V_25 ) {
V_10 -> V_25 = true ;
F_33 ( F_34 ( V_18 ) ) ;
}
}
F_26 ( & V_6 -> V_57 ) ;
V_39 = V_37 ;
V_56:
F_35 ( ( unsigned long ) V_54 ) ;
return V_39 ;
}
static int F_36 ( struct V_5 * V_6 )
{
unsigned int V_58 ;
T_1 * V_59 , * V_60 ;
if ( V_6 -> V_15 <= V_6 -> V_8 )
return 0 ;
if ( V_6 -> V_8 == 0 )
V_58 = 64 ;
else
V_58 = 2 * V_6 -> V_8 ;
V_59 = F_1 ( V_58 ) ;
if ( ! V_59 )
return - V_55 ;
V_60 = V_6 -> V_2 ;
F_25 ( & V_6 -> V_46 ) ;
F_37 ( & V_6 -> V_26 ) ;
memcpy ( V_59 , V_60 , V_6 -> V_8 * sizeof( * V_6 -> V_2 ) ) ;
memcpy ( V_59 + V_6 -> V_8 , V_60 ,
V_6 -> V_8 * sizeof( * V_6 -> V_2 ) ) ;
V_6 -> V_2 = V_59 ;
V_6 -> V_8 = V_58 ;
F_38 ( & V_6 -> V_26 ) ;
F_26 ( & V_6 -> V_46 ) ;
F_4 ( V_60 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 , int V_18 )
{
struct V_9 * V_10 ;
struct V_61 V_62 ;
int V_39 = 0 ;
V_10 = F_40 ( sizeof( * V_10 ) , V_4 ) ;
if ( ! V_10 )
return - V_55 ;
V_10 -> V_24 = V_6 ;
V_10 -> V_18 = V_18 ;
V_10 -> V_25 = true ;
V_39 = F_8 ( V_6 , V_10 ) ;
if ( V_39 < 0 )
goto V_63;
V_39 = F_36 ( V_6 ) ;
if ( V_39 < 0 )
goto V_63;
V_39 = F_41 ( V_18 , F_16 , 0 ,
V_6 -> V_64 , V_10 ) ;
if ( V_39 < 0 )
goto V_63;
V_39 = F_42 ( V_18 ) ;
return V_39 ;
V_63:
V_62 . V_18 = V_18 ;
if ( F_43 ( V_65 , & V_62 ) != 0 )
F_44 () ;
F_12 ( V_6 , V_10 ) ;
return V_39 ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_22 = F_34 ( V_10 -> V_18 ) ;
F_46 ( V_22 < 0 ) ;
F_47 ( V_22 , V_10 ) ;
F_12 ( V_6 , V_10 ) ;
}
static long F_48 ( struct V_35 * V_35 ,
unsigned int V_66 , unsigned long V_67 )
{
int V_39 ;
struct V_5 * V_6 = V_35 -> V_44 ;
void T_5 * V_68 = ( void T_5 * ) V_67 ;
F_25 ( & V_6 -> V_57 ) ;
switch ( V_66 ) {
case V_69 : {
struct V_70 V_71 ;
struct V_72 V_73 ;
V_39 = - V_74 ;
if ( V_6 -> V_75 != V_76 )
break;
V_39 = - V_52 ;
if ( F_32 ( & V_71 , V_68 , sizeof( V_71 ) ) )
break;
V_73 . V_77 = V_71 . V_77 ;
V_73 . V_78 = F_49 ( 0 ) ;
V_39 = F_43 ( V_79 ,
& V_73 ) ;
if ( V_39 != 0 )
break;
V_39 = F_39 ( V_6 , V_73 . V_18 ) ;
if ( V_39 == 0 )
V_39 = V_73 . V_18 ;
break;
}
case V_80 : {
struct V_81 V_71 ;
struct V_82 V_83 ;
V_39 = - V_52 ;
if ( F_32 ( & V_71 , V_68 , sizeof( V_71 ) ) )
break;
V_39 = - V_74 ;
if ( V_6 -> V_75 != V_76 &&
V_6 -> V_75 != V_71 . V_84 )
break;
V_83 . V_85 = V_71 . V_84 ;
V_83 . V_86 = V_71 . V_86 ;
V_39 = F_43 ( V_87 ,
& V_83 ) ;
if ( V_39 != 0 )
break;
V_39 = F_39 ( V_6 , V_83 . V_88 ) ;
if ( V_39 == 0 )
V_39 = V_83 . V_88 ;
break;
}
case V_89 : {
struct V_90 V_71 ;
struct V_91 V_92 ;
V_39 = - V_74 ;
if ( V_6 -> V_75 != V_76 )
break;
V_39 = - V_52 ;
if ( F_32 ( & V_71 , V_68 , sizeof( V_71 ) ) )
break;
V_92 . V_93 = V_94 ;
V_92 . V_85 = V_71 . V_84 ;
V_39 = F_43 ( V_95 ,
& V_92 ) ;
if ( V_39 != 0 )
break;
V_39 = F_39 ( V_6 , V_92 . V_18 ) ;
if ( V_39 == 0 )
V_39 = V_92 . V_18 ;
break;
}
case V_96 : {
struct V_97 V_98 ;
struct V_9 * V_10 ;
V_39 = - V_52 ;
if ( F_32 ( & V_98 , V_68 , sizeof( V_98 ) ) )
break;
V_39 = - V_99 ;
if ( V_98 . V_18 >= F_50 () )
break;
V_39 = - V_100 ;
V_10 = F_15 ( V_6 , V_98 . V_18 ) ;
if ( ! V_10 )
break;
F_51 ( F_34 ( V_98 . V_18 ) ) ;
F_45 ( V_6 , V_10 ) ;
V_39 = 0 ;
break;
}
case V_101 : {
struct V_102 V_103 ;
struct V_9 * V_10 ;
V_39 = - V_52 ;
if ( F_32 ( & V_103 , V_68 , sizeof( V_103 ) ) )
break;
V_39 = - V_100 ;
V_10 = F_15 ( V_6 , V_103 . V_18 ) ;
if ( V_10 ) {
F_52 ( V_103 . V_18 ) ;
V_39 = 0 ;
}
break;
}
case V_104 : {
F_25 ( & V_6 -> V_46 ) ;
F_37 ( & V_6 -> V_26 ) ;
V_6 -> V_28 = V_6 -> V_27 = V_6 -> V_33 = 0 ;
F_38 ( & V_6 -> V_26 ) ;
F_26 ( & V_6 -> V_46 ) ;
V_39 = 0 ;
break;
}
case V_105 : {
struct V_106 V_107 ;
V_39 = - V_74 ;
if ( V_6 -> V_75 != V_76 )
break;
V_39 = - V_52 ;
if ( F_32 ( & V_107 , V_68 , sizeof( V_107 ) ) )
break;
V_39 = - V_99 ;
if ( V_107 . V_108 == 0 || V_107 . V_108 >= V_109 )
break;
V_6 -> V_75 = V_107 . V_108 ;
V_39 = 0 ;
break;
}
default:
V_39 = - V_110 ;
break;
}
F_26 ( & V_6 -> V_57 ) ;
return V_39 ;
}
static unsigned int F_53 ( struct V_35 * V_35 , T_7 * V_111 )
{
unsigned int V_112 = V_113 | V_114 ;
struct V_5 * V_6 = V_35 -> V_44 ;
F_54 ( V_35 , & V_6 -> V_29 , V_111 ) ;
if ( V_6 -> V_28 != V_6 -> V_27 )
V_112 |= V_115 | V_116 ;
if ( V_6 -> V_33 )
V_112 = V_117 ;
return V_112 ;
}
static int F_55 ( int V_118 , struct V_35 * V_119 , int V_120 )
{
struct V_5 * V_6 = V_119 -> V_44 ;
return F_56 ( V_118 , V_119 , V_120 , & V_6 -> V_30 ) ;
}
static int F_57 ( struct V_121 * V_121 , struct V_35 * V_119 )
{
struct V_5 * V_6 ;
V_6 = F_40 ( sizeof( * V_6 ) , V_4 ) ;
if ( V_6 == NULL )
return - V_55 ;
V_6 -> V_64 = F_58 ( V_4 , L_2 , V_122 -> V_123 ) ;
if ( V_6 -> V_64 == NULL ) {
F_14 ( V_6 ) ;
return - V_55 ;
}
F_59 ( & V_6 -> V_29 ) ;
F_60 ( & V_6 -> V_57 ) ;
F_60 ( & V_6 -> V_46 ) ;
F_61 ( & V_6 -> V_26 ) ;
V_6 -> V_75 = V_76 ;
V_119 -> V_44 = V_6 ;
return F_62 ( V_121 , V_119 ) ;
}
static int F_63 ( struct V_121 * V_121 , struct V_35 * V_119 )
{
struct V_5 * V_6 = V_119 -> V_44 ;
struct V_11 * V_17 ;
while ( ( V_17 = V_6 -> V_13 . V_11 ) ) {
struct V_9 * V_10 ;
V_10 = F_9 ( V_17 , struct V_9 , V_17 ) ;
F_51 ( F_34 ( V_10 -> V_18 ) ) ;
F_45 ( V_6 , V_10 ) ;
}
F_4 ( V_6 -> V_2 ) ;
F_14 ( V_6 -> V_64 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
static int T_8 F_64 ( void )
{
int V_63 ;
if ( ! F_65 () )
return - V_124 ;
V_63 = F_66 ( & V_125 ) ;
if ( V_63 != 0 ) {
F_67 ( L_3 ) ;
return V_63 ;
}
F_68 ( L_4 ) ;
return 0 ;
}
static void T_9 F_69 ( void )
{
F_70 ( & V_125 ) ;
}
