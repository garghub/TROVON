static T_1 F_1 ( void )
{
return F_2 ( ( V_1 ) V_2 * 1000 ) ;
}
static T_2 F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
return F_5 ( true , V_7 , & V_9 -> V_10 ) ;
}
static T_3 F_6 ( struct V_8 * V_9 , int V_11 )
{
void T_4 * V_12 , * V_13 ;
V_12 = V_9 -> V_12 ;
switch ( V_11 ) {
case V_14 :
V_13 = V_12 + V_15 ;
break;
case V_16 :
V_13 = V_12 + V_17 ;
break;
case V_18 :
V_13 = V_12 + V_19 ;
break;
case V_20 :
V_13 = V_12 + V_21 ;
break;
case V_22 :
V_13 = V_12 + V_23 ;
break;
case V_24 :
V_13 = V_12 + V_25 ;
break;
default:
return F_7 ( 1 ,
L_1 , V_11 ) ;
}
return F_8 ( V_13 ) ;
}
static int F_9 ( unsigned int V_10 , struct V_26 * V_27 )
{
struct V_8 * V_9 = F_10 ( V_27 , struct V_8 , V_27 ) ;
int V_28 ;
if ( ! F_11 ( V_10 , & V_9 -> V_10 ) )
return 0 ;
V_28 = F_12 ( V_29 , V_10 ) ;
if ( V_28 >= V_30 )
return 0 ;
F_13 ( & V_9 -> V_31 , V_10 , V_28 ) ;
F_14 ( V_28 , & V_9 -> V_10 ) ;
return 0 ;
}
static bool F_15 ( struct V_32 * V_33 ,
struct V_31 * V_31 ,
unsigned long * V_34 )
{
int V_11 = V_33 -> V_6 . V_35 ;
if ( F_16 ( V_33 ) )
return true ;
if ( V_33 -> V_31 != V_31 )
return false ;
return ! F_17 ( V_11 , V_34 ) ;
}
static bool F_18 ( struct V_32 * V_33 )
{
struct V_31 * V_31 = V_33 -> V_31 ;
struct V_32 * V_36 = V_33 -> V_37 ;
struct V_32 * V_38 ;
unsigned long V_39 = 0 ;
F_19 ( V_36 -> V_6 . V_35 , & V_39 ) ;
if ( V_33 != V_36 ) {
if ( ! F_15 ( V_33 , V_31 , & V_39 ) )
return false ;
}
F_20 (sibling, &leader->sibling_list, group_entry) {
if ( ! F_15 ( V_38 , V_31 , & V_39 ) )
return false ;
}
return true ;
}
static int F_21 ( struct V_32 * V_33 )
{
struct V_8 * V_9 = F_22 ( V_33 -> V_31 ) ;
int V_11 = V_33 -> V_6 . V_35 ;
if ( V_33 -> V_6 . type != V_33 -> V_31 -> type )
return - V_40 ;
if ( F_23 ( V_33 ) || V_33 -> V_41 & V_42 )
return - V_43 ;
if ( V_33 -> V_10 < 0 ) {
F_24 ( V_9 -> V_4 , L_2 ) ;
return - V_43 ;
}
if ( V_33 -> V_6 . V_44 ||
V_33 -> V_6 . V_45 ||
V_33 -> V_6 . V_46 ||
V_33 -> V_6 . V_47 ||
V_33 -> V_6 . V_48 ||
V_33 -> V_6 . V_49 ||
V_33 -> V_6 . V_50 )
return - V_51 ;
if ( V_11 < 0 || V_11 >= V_52 )
return - V_51 ;
if ( ! F_18 ( V_33 ) )
return - V_51 ;
V_33 -> V_10 = F_25 ( & V_9 -> V_10 ) ;
return 0 ;
}
static void F_26 ( struct V_32 * V_33 )
{
struct V_8 * V_9 = F_22 ( V_33 -> V_31 ) ;
struct V_53 * V_54 = & V_33 -> V_55 ;
V_1 V_56 , V_57 , V_58 ;
do {
V_57 = F_27 ( & V_54 -> V_59 ) ;
V_58 = F_6 ( V_9 ,
V_33 -> V_6 . V_35 ) ;
} while ( F_28 ( & V_54 -> V_59 , V_57 ,
V_58 ) != V_57 );
V_56 = ( V_58 - V_57 ) & 0xFFFFFFFF ;
F_29 ( V_56 , & V_33 -> V_60 ) ;
}
static void F_30 ( struct V_32 * V_33 , int V_61 )
{
struct V_8 * V_9 = F_22 ( V_33 -> V_31 ) ;
struct V_53 * V_54 = & V_33 -> V_55 ;
void T_4 * V_12 , * V_13 ;
T_3 V_62 ;
V_12 = V_9 -> V_12 ;
V_13 = V_12 + V_63 ;
F_31 ( & V_9 -> V_64 , F_1 () ,
V_65 ) ;
F_32 ( & V_54 -> V_59 , 0 ) ;
F_33 ( V_66 , V_13 ) ;
V_62 = V_33 -> V_6 . V_67 ;
V_13 = V_12 + V_68 ;
F_33 ( V_62 , V_13 ) ;
V_13 = V_12 + V_63 ;
V_62 = V_69 ;
if ( V_9 -> V_70 -> V_61 & V_71 )
V_62 |= V_72 ;
F_33 ( V_62 , V_13 ) ;
}
static int F_34 ( struct V_32 * V_33 , int V_61 )
{
struct V_8 * V_9 = F_22 ( V_33 -> V_31 ) ;
struct V_53 * V_54 = & V_33 -> V_55 ;
int V_11 = V_33 -> V_6 . V_35 ;
if ( V_61 & V_73 )
F_30 ( V_33 , V_61 ) ;
if ( V_9 -> V_74 [ V_11 ] != NULL )
return - V_75 ;
V_9 -> V_74 [ V_11 ] = V_33 ;
V_9 -> V_76 ++ ;
F_32 ( & V_54 -> V_59 , F_6 ( V_9 , V_11 ) ) ;
return 0 ;
}
static void F_35 ( struct V_32 * V_33 , int V_61 )
{
struct V_8 * V_9 = F_22 ( V_33 -> V_31 ) ;
void T_4 * V_12 , * V_13 ;
V_12 = V_9 -> V_12 ;
V_13 = V_12 + V_63 ;
F_33 ( V_77 , V_13 ) ;
V_13 = V_12 + V_68 ;
F_33 ( V_78 , V_13 ) ;
F_26 ( V_33 ) ;
}
static void F_36 ( struct V_32 * V_33 , int V_61 )
{
struct V_8 * V_9 = F_22 ( V_33 -> V_31 ) ;
int V_11 = V_33 -> V_6 . V_35 ;
V_9 -> V_74 [ V_11 ] = NULL ;
V_9 -> V_76 -- ;
if ( V_9 -> V_76 == 0 )
F_37 ( & V_9 -> V_64 ) ;
F_35 ( V_33 , V_79 ) ;
}
static void F_38 ( struct V_8 * V_9 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_52 ; V_80 ++ ) {
struct V_32 * V_33 = V_9 -> V_74 [ V_80 ] ;
if ( V_33 )
F_26 ( V_33 ) ;
}
}
static enum V_81 F_39 ( struct V_64 * V_64 )
{
struct V_8 * V_9 = F_40 ( V_64 , struct V_8 ,
V_64 ) ;
F_38 ( V_9 ) ;
F_41 ( V_64 , F_1 () ) ;
return V_82 ;
}
static int F_42 ( struct V_8 * V_9 ,
void T_4 * V_12 , struct V_3 * V_4 )
{
int V_83 ;
* V_9 = (struct V_8 ) {
. V_31 = (struct V_31 ) {
. V_84 = V_85 ,
. V_86 = V_86 ,
. V_87 = F_21 ,
. V_88 = F_34 ,
. V_89 = F_36 ,
. V_90 = F_30 ,
. V_91 = F_35 ,
. V_92 = F_26 ,
} ,
. V_12 = V_12 ,
. V_4 = V_4 ,
. V_76 = 0 ,
} ;
V_83 = F_43 ( & V_93 , 0 , 0 , V_94 ) ;
return V_83 ;
}
static int F_44 ( struct V_95 * V_96 )
{
struct V_8 * V_9 = F_45 ( V_96 ) ;
F_46 ( V_97 , & V_9 -> V_27 ) ;
F_47 ( & V_9 -> V_31 ) ;
F_48 ( V_9 ) ;
return 0 ;
}
static int F_49 ( struct V_95 * V_96 , void T_4 * V_12 )
{
struct V_8 * V_9 ;
char * V_98 ;
int V_83 ;
int V_99 ;
const struct V_100 * V_101 =
F_50 ( V_102 , & V_96 -> V_4 ) ;
V_9 = F_51 ( sizeof( * V_9 ) , V_94 ) ;
if ( ! V_9 ) {
F_52 ( L_3 ) ;
return - V_103 ;
}
if ( ! V_97 ) {
V_99 = F_53 ( V_104 ,
L_4 , NULL ,
F_9 ) ;
if ( V_99 < 0 ) {
F_52 ( L_5 ) ;
goto V_105;
}
V_97 = V_99 ;
}
V_83 = F_42 ( V_9 , V_12 , & V_96 -> V_4 ) ;
if ( V_83 == 0 )
V_98 = L_6 ;
else
V_98 = F_54 ( & V_96 -> V_4 ,
V_94 , L_7 , V_83 ) ;
V_9 -> V_70 = (struct V_106 * ) V_101 -> V_107 ;
F_55 ( & V_9 -> V_64 , V_108 ,
V_109 ) ;
V_9 -> V_64 . V_110 = F_39 ;
F_14 ( F_56 () , & V_9 -> V_10 ) ;
F_57 ( V_97 , & V_9 -> V_27 ) ;
V_99 = F_58 ( & ( V_9 -> V_31 ) , V_98 , - 1 ) ;
if ( V_99 )
goto V_111;
F_59 ( V_96 , V_9 ) ;
return 0 ;
V_111:
F_60 ( L_8 , V_99 ) ;
F_46 ( V_97 , & V_9 -> V_27 ) ;
F_37 ( & V_9 -> V_64 ) ;
V_105:
F_48 ( V_9 ) ;
return V_99 ;
}
static int F_61 ( struct V_95 * V_96 )
{
struct V_112 * V_113 = V_96 -> V_4 . V_114 ;
void T_4 * V_12 , * V_13 ;
T_3 V_62 ;
int V_115 = 0x400 ;
V_12 = F_62 ( V_113 , 0 ) ;
F_63 ( ! V_12 ) ;
V_13 = V_12 + V_116 ;
V_62 = F_64 ( V_13 ) ;
V_117 = ( V_62 & V_118 ) >>
V_119 ;
V_13 = V_12 + V_120 ;
V_62 = F_64 ( V_13 ) ;
V_62 &= ~ ( 1 << V_121 ) ;
F_65 ( V_62 , V_13 ) ;
while ( ! ( F_64 ( V_13 ) & 1 << V_122 ) && -- V_115 )
F_66 () ;
if ( F_67 ( ! V_115 ) ) {
F_60 ( L_9 ,
V_123 ) ;
return - V_124 ;
}
return F_49 ( V_96 , V_12 ) ;
}
int F_68 ( void )
{
return V_117 ;
}
static int T_5 F_69 ( void )
{
return F_70 ( & V_125 ) ;
}
