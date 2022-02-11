static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_4 -> V_7 = V_5 -> V_7 ;
V_4 -> V_8 = V_5 -> V_8 ;
V_4 -> V_9 = V_5 -> V_9 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_7 = V_4 -> V_7 ;
V_5 -> V_8 = V_4 -> V_8 ;
V_5 -> V_9 = V_4 -> V_9 ;
}
static bool F_3 ( long V_10 , long V_11 , long V_12 )
{
return V_10 >= V_11 && V_10 <= V_12 ;
}
static const char * F_4 ( const T_1 V_13 )
{
if ( F_5 ( V_13 ) == 1 ) {
struct V_14 * V_15 = V_16 + F_6 ( V_16 ) ;
while ( V_15 -- > V_16 )
if ( V_13 & V_15 -> V_13 )
return V_15 -> V_17 ;
} else
F_7 ( L_1 , V_18 ) ;
return NULL ;
}
static bool F_8 ( struct V_1 * V_2 )
{
return ! V_2 -> V_6 . V_19 ;
}
static bool F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_19 == 1 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_19 == 10 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_19 == 6 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_6 . V_19 , 4 , 6 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
return F_12 ( V_2 ) ||
( F_10 ( V_2 ) && ! F_14 ( V_2 -> V_6 . V_8 ) ) ;
}
static bool F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_20 < V_2 -> V_21 [ 0 ] . V_22 . V_23 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_24 != V_25 ;
}
static bool F_17 ( struct V_26 * V_27 )
{
return ! V_27 -> V_19 ;
}
static bool F_18 ( struct V_26 * V_27 )
{
return V_27 -> V_19 == 1 ;
}
static bool F_19 ( struct V_26 * V_27 )
{
return V_27 -> V_19 == 10 ;
}
static bool F_20 ( struct V_26 * V_27 )
{
return F_3 ( V_27 -> V_19 , 4 , 5 ) ;
}
static bool F_21 ( struct V_26 * V_27 )
{
return V_27 -> V_19 == 6 ;
}
static bool F_22 ( struct V_26 * V_27 )
{
return F_3 ( V_27 -> V_19 , 4 , 6 ) ;
}
static unsigned long F_23 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 -> V_26 ) )
return V_28 ;
else if ( F_18 ( V_2 -> V_26 ) )
return V_29 ;
else if ( F_19 ( V_2 -> V_26 ) )
return V_30 ;
else if ( F_20 ( V_2 -> V_26 ) )
return V_31 ;
else if ( F_21 ( V_2 -> V_26 ) )
return V_32 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 & ~ F_23 ( V_2 ) ) {
V_2 -> V_34 -> error = L_2 ;
return - V_35 ;
}
return 0 ;
}
static unsigned int F_25 ( int V_36 )
{
return V_36 & 0xFF ;
}
static unsigned int F_26 ( int V_36 )
{
return F_25 ( V_36 >> V_37 ) ;
}
static bool F_27 ( int V_36 )
{
return ! ! ( V_36 & V_38 ) ;
}
static bool F_28 ( int V_36 )
{
return ! F_27 ( V_36 ) && F_25 ( V_36 ) > 1 ;
}
static bool F_14 ( int V_36 )
{
return ! F_27 ( V_36 ) && F_26 ( V_36 ) > 1 ;
}
static const char * F_29 ( int V_36 )
{
if ( F_27 ( V_36 ) )
return L_3 ;
if ( F_25 ( V_36 ) > 1 )
return L_4 ;
F_30 ( F_26 ( V_36 ) < 2 ) ;
return L_5 ;
}
static int F_31 ( const char * V_17 )
{
if ( ! strcasecmp ( V_17 , L_4 ) )
return V_39 ;
else if ( ! strcasecmp ( V_17 , L_3 ) )
return V_40 ;
else if ( ! strcasecmp ( V_17 , L_5 ) )
return V_41 ;
return - V_35 ;
}
static unsigned int F_32 ( int V_36 )
{
return V_12 ( F_25 ( V_36 ) , F_26 ( V_36 ) ) ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned int V_42 ,
unsigned int V_43 )
{
unsigned int V_44 = 1 , V_45 = 1 , V_46 = 0 ;
if ( V_42 == V_47 ||
V_42 == V_39 )
V_44 = V_43 ;
else if ( V_42 == V_40 ) {
V_45 = V_43 ;
V_46 = V_38 ;
if ( ! F_34 ( V_48 , & V_2 -> V_33 ) )
V_46 |= V_49 ;
} else if ( V_42 == V_41 ) {
V_45 = V_43 ;
V_46 = ! V_38 ;
if ( ! F_34 ( V_48 , & V_2 -> V_33 ) )
V_46 |= V_49 ;
} else
return - V_35 ;
return V_46 | ( V_45 << V_37 ) | V_44 ;
}
static bool F_35 ( struct V_26 * V_50 , const int V_36 )
{
if ( V_50 -> V_19 == 10 ) {
switch ( V_50 -> V_42 ) {
case V_47 :
case V_39 :
return F_28 ( V_36 ) ;
case V_40 :
return F_27 ( V_36 ) ;
case V_41 :
return F_14 ( V_36 ) ;
default:
break;
}
}
return false ;
}
static struct V_26 * F_36 ( const char * V_17 )
{
struct V_26 * V_50 = V_51 + F_6 ( V_51 ) ;
while ( V_50 -- > V_51 )
if ( ! strcasecmp ( V_50 -> V_17 , V_17 ) )
return V_50 ;
return NULL ;
}
static struct V_26 * F_37 ( const int V_19 , const int V_36 )
{
struct V_26 * V_50 = V_51 + F_6 ( V_51 ) ;
while ( V_50 -- > V_51 ) {
if ( V_50 -> V_19 == V_19 &&
( F_35 ( V_50 , V_36 ) || V_50 -> V_42 == V_36 ) )
return V_50 ;
}
return NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_52 * V_22 ;
struct V_53 * V_53 = F_39 ( F_40 ( V_2 -> V_34 -> V_54 ) ) ;
F_41 (rdev, mddev)
V_22 -> V_23 = V_5 -> V_55 ;
F_42 ( V_53 , V_5 -> V_56 ) ;
F_43 ( V_53 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_7 = V_5 -> V_19 ;
V_5 -> V_8 = V_5 -> V_36 ;
V_5 -> V_9 = V_5 -> V_57 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_19 = V_5 -> V_7 ;
V_5 -> V_36 = V_5 -> V_8 ;
V_5 -> V_57 = V_5 -> V_9 ;
V_5 -> V_58 = V_2 -> V_58 ;
V_5 -> V_59 = 0 ;
}
static struct V_1 * F_46 ( struct V_60 * V_34 , struct V_26 * V_26 ,
unsigned int V_61 )
{
unsigned int V_62 ;
struct V_1 * V_2 ;
if ( V_61 <= V_26 -> V_63 ) {
V_34 -> error = L_6 ;
return F_47 ( - V_35 ) ;
}
V_2 = F_48 ( sizeof( * V_2 ) + V_61 * sizeof( V_2 -> V_21 [ 0 ] ) , V_64 ) ;
if ( ! V_2 ) {
V_34 -> error = L_7 ;
return F_47 ( - V_65 ) ;
}
F_49 ( & V_2 -> V_6 ) ;
V_2 -> V_58 = V_61 ;
V_2 -> V_59 = 0 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_66 = 256 ;
V_2 -> V_6 . V_58 = V_61 ;
V_2 -> V_6 . V_19 = V_26 -> V_19 ;
V_2 -> V_6 . V_7 = V_2 -> V_6 . V_19 ;
V_2 -> V_6 . V_36 = V_26 -> V_42 ;
V_2 -> V_6 . V_8 = V_2 -> V_6 . V_36 ;
V_2 -> V_6 . V_59 = 0 ;
V_2 -> V_6 . V_20 = V_25 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ )
F_50 ( & V_2 -> V_21 [ V_62 ] . V_22 ) ;
return V_2 ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ ) {
if ( V_2 -> V_21 [ V_62 ] . V_67 )
F_52 ( V_2 -> V_34 , V_2 -> V_21 [ V_62 ] . V_67 ) ;
F_53 ( & V_2 -> V_21 [ V_62 ] . V_22 ) ;
if ( V_2 -> V_21 [ V_62 ] . V_68 )
F_52 ( V_2 -> V_34 , V_2 -> V_21 [ V_62 ] . V_68 ) ;
}
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
int V_62 ;
int V_71 = 0 ;
int V_72 = 0 ;
int V_46 = 0 ;
const char * V_73 ;
V_73 = F_56 ( V_70 ) ;
if ( ! V_73 )
return - V_35 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ ) {
V_2 -> V_21 [ V_62 ] . V_22 . V_74 = V_62 ;
V_2 -> V_21 [ V_62 ] . V_67 = NULL ;
V_2 -> V_21 [ V_62 ] . V_68 = NULL ;
V_2 -> V_21 [ V_62 ] . V_22 . V_75 = 0 ;
V_2 -> V_21 [ V_62 ] . V_22 . V_5 = & V_2 -> V_6 ;
V_73 = F_56 ( V_70 ) ;
if ( ! V_73 )
return - V_35 ;
if ( strcmp ( V_73 , L_8 ) ) {
V_46 = F_57 ( V_2 -> V_34 , V_73 , F_58 ( V_2 -> V_34 -> V_54 ) ,
& V_2 -> V_21 [ V_62 ] . V_67 ) ;
if ( V_46 ) {
V_2 -> V_34 -> error = L_9 ;
return V_46 ;
}
V_2 -> V_21 [ V_62 ] . V_22 . V_76 = F_59 ( V_64 ) ;
if ( ! V_2 -> V_21 [ V_62 ] . V_22 . V_76 ) {
V_2 -> V_34 -> error = L_10 ;
return - V_65 ;
}
}
V_73 = F_56 ( V_70 ) ;
if ( ! V_73 )
return - V_35 ;
if ( ! strcmp ( V_73 , L_8 ) ) {
if ( ! F_34 ( V_77 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) &&
( ! V_2 -> V_21 [ V_62 ] . V_22 . V_79 ) ) {
V_2 -> V_34 -> error = L_11 ;
return - V_35 ;
}
if ( V_2 -> V_21 [ V_62 ] . V_67 ) {
V_2 -> V_34 -> error = L_12 ;
return - V_35 ;
}
continue;
}
V_46 = F_57 ( V_2 -> V_34 , V_73 , F_58 ( V_2 -> V_34 -> V_54 ) ,
& V_2 -> V_21 [ V_62 ] . V_68 ) ;
if ( V_46 ) {
V_2 -> V_34 -> error = L_13 ;
return V_46 ;
}
if ( V_2 -> V_21 [ V_62 ] . V_67 ) {
V_72 = 1 ;
V_2 -> V_21 [ V_62 ] . V_22 . V_80 = V_2 -> V_21 [ V_62 ] . V_67 -> V_81 ;
}
V_2 -> V_21 [ V_62 ] . V_22 . V_81 = V_2 -> V_21 [ V_62 ] . V_68 -> V_81 ;
F_60 ( & V_2 -> V_21 [ V_62 ] . V_22 . V_82 , & V_2 -> V_6 . V_83 ) ;
if ( ! F_34 ( V_77 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) )
V_71 ++ ;
}
if ( V_72 ) {
V_2 -> V_6 . V_84 = 0 ;
V_2 -> V_6 . V_85 = 1 ;
V_2 -> V_6 . V_86 = 2 ;
} else if ( V_71 && ! V_2 -> V_6 . V_20 ) {
V_2 -> V_34 -> error = L_14 ;
return - V_35 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned long V_87 )
{
unsigned long V_88 = V_2 -> V_34 -> V_89 / ( 1 << 21 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
if ( ! V_87 ) {
if ( V_88 > ( 1 << 13 ) ) {
V_87 = F_62 ( V_88 ) ;
F_63 ( L_15 ,
V_87 ) ;
} else {
F_63 ( L_16 ) ;
V_87 = 1 << 13 ;
}
} else {
if ( V_87 > V_2 -> V_34 -> V_89 ) {
V_2 -> V_34 -> error = L_17 ;
return - V_35 ;
}
if ( V_87 < V_88 ) {
F_7 ( L_18 ,
V_87 , V_88 ) ;
V_2 -> V_34 -> error = L_19 ;
return - V_35 ;
}
if ( ! F_64 ( V_87 ) ) {
V_2 -> V_34 -> error = L_20 ;
return - V_35 ;
}
if ( V_87 < V_2 -> V_6 . V_57 ) {
V_2 -> V_34 -> error = L_21 ;
return - V_35 ;
}
}
V_2 -> V_6 . V_90 . V_91 = F_65 ( V_87 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
unsigned int V_62 , V_92 = 0 ;
unsigned int V_93 = 0 , V_43 ;
unsigned int V_94 , V_95 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_6 . V_58 ; V_62 ++ )
if ( ! F_34 ( V_77 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) ||
! V_2 -> V_21 [ V_62 ] . V_22 . V_76 )
V_92 ++ ;
switch ( V_2 -> V_26 -> V_19 ) {
case 0 :
break;
case 1 :
if ( V_92 >= V_2 -> V_6 . V_58 )
goto V_96;
break;
case 4 :
case 5 :
case 6 :
if ( V_92 > V_2 -> V_26 -> V_63 )
goto V_96;
break;
case 10 :
V_43 = F_32 ( V_2 -> V_6 . V_8 ) ;
if ( V_92 < V_43 )
break;
if ( F_28 ( V_2 -> V_6 . V_8 ) ) {
for ( V_62 = 0 ; V_62 < V_2 -> V_6 . V_58 ; V_62 ++ ) {
if ( ! ( V_62 % V_43 ) )
V_93 = 0 ;
if ( ( ! V_2 -> V_21 [ V_62 ] . V_22 . V_76 ||
! F_34 ( V_77 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) ) &&
( ++ V_93 >= V_43 ) )
goto V_96;
}
break;
}
V_94 = ( V_2 -> V_6 . V_58 / V_43 ) ;
V_95 = ( V_2 -> V_6 . V_58 / V_94 ) - 1 ;
V_95 *= V_94 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_6 . V_58 ; V_62 ++ ) {
if ( ! ( V_62 % V_43 ) && ! ( V_62 > V_95 ) )
V_93 = 0 ;
if ( ( ! V_2 -> V_21 [ V_62 ] . V_22 . V_76 ||
! F_34 ( V_77 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) ) &&
( ++ V_93 >= V_43 ) )
goto V_96;
}
break;
default:
if ( V_92 )
return - V_35 ;
}
return 0 ;
V_96:
return - V_35 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_69 * V_70 ,
unsigned int V_97 )
{
int V_98 , V_99 = V_47 ;
unsigned int V_100 = 2 ;
unsigned int V_62 , V_101 = 0 ;
unsigned int V_87 = 0 ;
T_2 V_102 ;
const char * V_73 , * V_103 ;
struct V_104 * V_105 ;
struct V_26 * V_27 = V_2 -> V_26 ;
V_73 = F_56 ( V_70 ) ;
V_97 -- ;
if ( F_68 ( V_73 , 10 , & V_98 ) < 0 ) {
V_2 -> V_34 -> error = L_22 ;
return - V_35 ;
}
if ( F_18 ( V_27 ) ) {
if ( V_98 )
F_7 ( L_23 ) ;
V_98 = 0 ;
} else if ( ! F_64 ( V_98 ) ) {
V_2 -> V_34 -> error = L_24 ;
return - V_35 ;
} else if ( V_98 < 8 ) {
V_2 -> V_34 -> error = L_25 ;
return - V_35 ;
}
V_2 -> V_6 . V_9 = V_2 -> V_6 . V_57 = V_98 ;
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ ) {
F_69 ( V_77 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) ;
V_2 -> V_21 [ V_62 ] . V_22 . V_79 = V_25 ;
}
for ( V_62 = 0 ; V_62 < V_97 ; V_62 ++ ) {
V_103 = F_56 ( V_70 ) ;
if ( ! V_103 ) {
V_2 -> V_34 -> error = L_26 ;
return - V_35 ;
}
if ( ! strcasecmp ( V_103 , F_4 ( V_106 ) ) ) {
if ( F_70 ( V_107 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_27 ;
return - V_35 ;
}
continue;
}
if ( ! strcasecmp ( V_103 , F_4 ( V_108 ) ) ) {
if ( F_70 ( V_109 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_28 ;
return - V_35 ;
}
continue;
}
if ( ! strcasecmp ( V_103 , F_4 ( V_110 ) ) ) {
if ( F_70 ( V_48 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_29 ;
return - V_35 ;
}
continue;
}
V_73 = F_56 ( V_70 ) ;
V_62 ++ ;
if ( ! V_73 ) {
V_2 -> V_34 -> error = L_30 ;
return - V_35 ;
}
if ( ! strcasecmp ( V_103 , F_4 ( V_111 ) ) ) {
if ( F_70 ( V_112 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_31 ;
return - V_35 ;
}
if ( ! F_19 ( V_27 ) ) {
V_2 -> V_34 -> error = L_32 ;
return - V_35 ;
}
V_99 = F_31 ( V_73 ) ;
if ( V_99 < 0 ) {
V_2 -> V_34 -> error = L_33 ;
return V_99 ;
}
continue;
}
if ( F_68 ( V_73 , 10 , & V_98 ) < 0 ) {
V_2 -> V_34 -> error = L_34 ;
return - V_35 ;
}
if ( ! strcasecmp ( V_103 , F_4 ( V_113 ) ) ) {
if ( ! F_3 ( V_98 , 0 , V_2 -> V_58 - 1 ) ) {
V_2 -> V_34 -> error = L_35 ;
return - V_35 ;
}
if ( F_70 ( V_98 , ( void * ) V_2 -> V_114 ) ) {
V_2 -> V_34 -> error = L_36 ;
return - V_35 ;
}
V_105 = V_2 -> V_21 + V_98 ;
F_71 ( V_77 , & V_105 -> V_22 . V_78 ) ;
F_71 ( V_115 , & V_105 -> V_22 . V_78 ) ;
V_105 -> V_22 . V_79 = 0 ;
F_69 ( V_116 , & V_2 -> V_33 ) ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_117 ) ) ) {
if ( ! F_18 ( V_27 ) ) {
V_2 -> V_34 -> error = L_37 ;
return - V_35 ;
}
if ( ! F_3 ( V_98 , 0 , V_2 -> V_6 . V_58 - 1 ) ) {
V_2 -> V_34 -> error = L_38 ;
return - V_35 ;
}
V_101 ++ ;
F_69 ( V_118 , & V_2 -> V_21 [ V_98 ] . V_22 . V_78 ) ;
F_69 ( V_119 , & V_2 -> V_33 ) ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_120 ) ) ) {
if ( ! F_18 ( V_27 ) ) {
V_2 -> V_34 -> error = L_39 ;
return - V_35 ;
}
if ( F_70 ( V_121 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_40 ;
return - V_35 ;
}
V_98 /= 2 ;
if ( V_98 > V_122 ) {
V_2 -> V_34 -> error = L_41 ;
return - V_35 ;
}
V_2 -> V_6 . V_90 . V_123 = V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_124 ) ) ) {
if ( F_70 ( V_125 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_42 ;
return - V_35 ;
}
if ( ! V_98 || ( V_98 > V_126 ) ) {
V_2 -> V_34 -> error = L_43 ;
return - V_35 ;
}
V_2 -> V_6 . V_90 . V_127 = V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_128 ) ) ) {
if ( F_70 ( V_129 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_44 ;
return - V_35 ;
}
if ( V_98 < 0 ||
( V_98 && ( V_98 < V_130 || V_98 % F_72 ( V_131 ) ) ) ) {
V_2 -> V_34 -> error = L_45 ;
return - V_35 ;
}
V_2 -> V_75 = V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_132 ) ) ) {
if ( F_70 ( V_133 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_46 ;
return - V_35 ;
}
if ( ! F_3 ( abs ( V_98 ) , 1 , V_134 - V_27 -> V_135 ) ) {
V_2 -> V_34 -> error = L_47 ;
return - V_35 ;
}
V_2 -> V_59 = V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_136 ) ) ) {
if ( F_70 ( V_137 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_48 ;
return - V_35 ;
}
if ( ! F_22 ( V_27 ) ) {
V_2 -> V_34 -> error = L_49 ;
return - V_35 ;
}
V_2 -> V_66 = V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_138 ) ) ) {
if ( F_70 ( V_139 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_50 ;
return - V_35 ;
}
if ( V_98 > V_140 ) {
V_2 -> V_34 -> error = L_51 ;
return - V_35 ;
}
V_2 -> V_6 . V_141 = ( int ) V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_142 ) ) ) {
if ( F_70 ( V_143 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_52 ;
return - V_35 ;
}
if ( V_98 > V_140 ) {
V_2 -> V_34 -> error = L_53 ;
return - V_35 ;
}
V_2 -> V_6 . V_144 = ( int ) V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_145 ) ) ) {
if ( F_70 ( V_146 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_54 ;
return - V_35 ;
}
V_87 = V_98 ;
V_2 -> V_147 = V_98 ;
} else if ( ! strcasecmp ( V_103 , F_4 ( V_148 ) ) ) {
if ( F_70 ( V_149 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_55 ;
return - V_35 ;
}
if ( ! F_3 ( V_98 , 2 , V_2 -> V_6 . V_58 ) ) {
V_2 -> V_34 -> error = L_56 ;
return - V_35 ;
}
V_100 = V_98 ;
} else {
F_7 ( L_57 , V_103 ) ;
V_2 -> V_34 -> error = L_58 ;
return - V_35 ;
}
}
if ( F_34 ( V_109 , & V_2 -> V_33 ) &&
F_34 ( V_107 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_59 ;
return - V_35 ;
}
if ( F_34 ( V_116 , & V_2 -> V_33 ) &&
( F_34 ( V_109 , & V_2 -> V_33 ) ||
F_34 ( V_107 , & V_2 -> V_33 ) ) ) {
V_2 -> V_34 -> error = L_60 ;
return - V_35 ;
}
if ( V_101 >= V_2 -> V_6 . V_58 ) {
V_2 -> V_34 -> error = L_61 ;
return - V_35 ;
}
if ( F_61 ( V_2 , V_87 ) )
return - V_35 ;
if ( V_2 -> V_6 . V_57 )
V_102 = V_2 -> V_6 . V_57 ;
else
V_102 = V_87 ;
if ( F_73 ( V_2 -> V_34 , V_102 ) )
return - V_35 ;
if ( F_19 ( V_27 ) ) {
if ( V_100 > V_2 -> V_6 . V_58 ) {
V_2 -> V_34 -> error = L_62 ;
return - V_35 ;
}
V_2 -> V_6 . V_8 = F_33 ( V_2 , V_99 , V_100 ) ;
if ( V_2 -> V_6 . V_8 < 0 ) {
V_2 -> V_34 -> error = L_63 ;
return V_2 -> V_6 . V_8 ;
}
V_27 = F_37 ( 10 , V_2 -> V_6 . V_8 ) ;
if ( ! V_27 ) {
V_2 -> V_34 -> error = L_64 ;
return - V_35 ;
}
if ( ( V_27 -> V_42 == V_47 ||
V_27 -> V_42 == V_39 ) &&
F_34 ( V_48 , & V_2 -> V_33 ) ) {
V_2 -> V_34 -> error = L_65 ;
return - V_35 ;
}
}
V_2 -> V_100 = V_100 ;
V_2 -> V_6 . V_85 = 0 ;
V_2 -> V_6 . V_84 = 1 ;
return F_24 ( V_2 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_46 ;
struct V_150 * V_151 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
T_1 V_152 = V_12 ( V_5 -> V_57 , V_5 -> V_9 ) / 2 ;
T_1 V_153 = V_2 -> V_66 ;
if ( ! F_22 ( V_2 -> V_26 ) ) {
V_2 -> V_34 -> error = L_66 ;
return - V_35 ;
}
if ( V_153 < V_152 ) {
F_63 ( L_67 ,
V_153 , V_152 ) ;
V_153 = V_152 ;
}
V_151 = V_5 -> V_154 ;
if ( ! V_151 ) {
V_2 -> V_34 -> error = L_68 ;
return - V_35 ;
}
if ( V_151 -> V_155 != V_153 ) {
V_46 = F_75 ( V_5 , V_153 ) ;
if ( V_46 ) {
V_2 -> V_34 -> error = L_69 ;
return V_46 ;
}
F_63 ( L_70 , V_153 ) ;
}
return 0 ;
}
static unsigned int F_76 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_58 - V_2 -> V_26 -> V_63 ;
}
static unsigned int F_77 ( struct V_1 * V_2 )
{
return V_2 -> V_58 - V_2 -> V_26 -> V_63 ;
}
static int F_78 ( struct V_1 * V_2 , bool V_156 )
{
int V_59 ;
unsigned int V_157 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_52 * V_22 ;
T_2 V_56 = V_2 -> V_34 -> V_89 , V_55 = V_2 -> V_34 -> V_89 ;
if ( V_156 ) {
V_59 = V_5 -> V_59 ;
V_157 = F_76 ( V_2 ) ;
} else {
V_59 = V_2 -> V_59 ;
V_157 = F_77 ( V_2 ) ;
}
if ( F_18 ( V_2 -> V_26 ) )
;
else if ( F_19 ( V_2 -> V_26 ) ) {
if ( V_2 -> V_100 < 2 ||
V_59 < 0 ) {
V_2 -> V_34 -> error = L_71 ;
return - V_35 ;
}
V_55 *= V_2 -> V_100 ;
if ( F_79 ( V_55 , V_157 ) )
goto V_158;
V_56 = ( V_157 + V_59 ) * V_55 ;
if ( F_79 ( V_56 , V_2 -> V_100 ) )
goto V_158;
} else if ( F_79 ( V_55 , V_157 ) )
goto V_158;
else
V_56 = ( V_157 + V_59 ) * V_55 ;
F_41 (rdev, mddev)
V_22 -> V_23 = V_55 ;
V_5 -> V_56 = V_56 ;
V_5 -> V_55 = V_55 ;
return 0 ;
V_158:
V_2 -> V_34 -> error = L_72 ;
return - V_35 ;
}
static void F_80 ( struct V_1 * V_2 , T_2 V_55 )
{
if ( F_8 ( V_2 ) )
V_2 -> V_6 . V_20 = V_25 ;
else if ( F_11 ( V_2 ) )
V_2 -> V_6 . V_20 = V_55 ;
else
V_2 -> V_6 . V_20 = F_34 ( V_107 , & V_2 -> V_33 )
? V_25 : V_55 ;
}
static void F_81 ( struct V_1 * V_2 , T_2 V_55 )
{
if ( ! V_55 )
F_80 ( V_2 , 0 ) ;
else if ( V_55 == V_25 )
F_80 ( V_2 , V_25 ) ;
else if ( V_2 -> V_21 [ 0 ] . V_22 . V_23 < V_55 )
F_80 ( V_2 , V_2 -> V_21 [ 0 ] . V_22 . V_23 ) ;
else
F_80 ( V_2 , V_25 ) ;
}
static void F_82 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_83 ( V_160 , struct V_1 , V_6 . V_161 ) ;
F_84 () ;
if ( ! F_16 ( V_2 ) )
F_38 ( V_2 ) ;
F_85 ( V_2 -> V_34 -> V_54 ) ;
}
static int F_86 ( struct V_162 * V_163 , int V_164 )
{
struct V_1 * V_2 = F_83 ( V_163 , struct V_1 , V_165 ) ;
return F_87 ( & V_2 -> V_6 , V_164 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
unsigned int V_166 ;
if ( V_2 -> V_6 . V_167 ) {
V_2 -> V_34 -> error = L_73 ;
return - V_168 ;
}
if ( F_16 ( V_2 ) ) {
V_2 -> V_34 -> error = L_74 ;
return - V_168 ;
}
switch ( V_5 -> V_19 ) {
case 0 :
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 5 ) &&
V_5 -> V_58 == 1 )
return 0 ;
if ( V_5 -> V_7 == 10 &&
! ( V_2 -> V_58 % V_5 -> V_58 ) )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 4 , 6 ) &&
V_5 -> V_8 == V_169 &&
V_5 -> V_58 > 1 )
return 0 ;
break;
case 10 :
if ( F_27 ( V_5 -> V_36 ) )
break;
V_166 = F_25 ( V_5 -> V_36 ) ;
if ( V_5 -> V_7 == 0 ) {
if ( V_166 > 1 &&
! ( V_5 -> V_58 % V_166 ) ) {
V_5 -> V_58 /= V_166 ;
V_5 -> V_59 = V_5 -> V_58 ;
return 0 ;
}
if ( V_166 == 1 &&
F_26 ( V_5 -> V_36 ) > 1 )
return 0 ;
break;
}
if ( V_5 -> V_7 == 1 &&
V_12 ( V_166 , F_26 ( V_5 -> V_36 ) ) == V_5 -> V_58 )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 4 , 5 ) &&
V_5 -> V_58 == 2 )
return 0 ;
break;
case 1 :
if ( F_3 ( V_5 -> V_7 , 4 , 5 ) &&
V_5 -> V_58 == 2 ) {
V_5 -> V_167 = 1 ;
return 0 ;
}
if ( V_5 -> V_7 == 0 &&
V_5 -> V_58 == 1 )
return 0 ;
if ( V_5 -> V_7 == 10 )
return 0 ;
break;
case 4 :
if ( V_5 -> V_7 == 0 )
return 0 ;
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 5 ) &&
V_5 -> V_58 == 2 )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 5 , 6 ) &&
V_5 -> V_36 == V_169 )
return 0 ;
break;
case 5 :
if ( V_5 -> V_7 == 0 &&
V_5 -> V_36 == V_169 )
return 0 ;
if ( V_5 -> V_7 == 4 &&
V_5 -> V_36 == V_169 )
return 0 ;
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 4 || V_5 -> V_7 == 10 ) &&
V_5 -> V_58 == 2 )
return 0 ;
if ( V_5 -> V_7 == 6 &&
( ( V_5 -> V_36 == V_169 && V_5 -> V_8 == V_169 ) ||
F_3 ( V_5 -> V_8 , V_170 , V_171 ) ) )
return 0 ;
break;
case 6 :
if ( V_5 -> V_7 == 0 &&
V_5 -> V_36 == V_169 )
return 0 ;
if ( V_5 -> V_7 == 4 &&
V_5 -> V_36 == V_169 )
return 0 ;
if ( V_5 -> V_7 == 5 &&
( ( V_5 -> V_36 == V_169 && V_5 -> V_8 == V_169 ) ||
F_3 ( V_5 -> V_8 , V_172 , V_173 ) ) )
return 0 ;
default:
break;
}
V_2 -> V_34 -> error = L_75 ;
return - V_35 ;
}
static bool F_89 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_7 != V_2 -> V_6 . V_19 ;
}
static bool F_90 ( struct V_1 * V_2 )
{
bool V_174 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_89 ( V_2 ) )
return false ;
if ( ! V_5 -> V_19 )
return false ;
V_174 = V_5 -> V_8 != V_5 -> V_36 ||
V_5 -> V_9 != V_5 -> V_57 ||
V_2 -> V_59 ;
if ( V_5 -> V_19 == 1 ) {
if ( V_2 -> V_59 )
return ! ! V_2 -> V_59 ;
return ! V_174 &&
V_5 -> V_58 != V_2 -> V_58 ;
}
if ( V_5 -> V_19 == 10 )
return V_174 &&
! F_14 ( V_5 -> V_8 ) &&
V_2 -> V_59 >= 0 ;
return V_174 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_175 || ! V_5 -> V_175 -> V_176 )
V_2 -> V_34 -> error = L_76 ;
else if ( V_5 -> V_167 )
V_2 -> V_34 -> error = L_77 ;
else if ( F_15 ( V_2 ) )
V_2 -> V_34 -> error = L_78 ;
else if ( F_16 ( V_2 ) )
V_2 -> V_34 -> error = L_79 ;
else if ( ! ( F_9 ( V_2 ) || F_10 ( V_2 ) || F_12 ( V_2 ) ) )
V_2 -> V_34 -> error = L_80 ;
else
return 0 ;
return - V_168 ;
}
static int F_92 ( struct V_52 * V_22 , int V_177 )
{
F_93 ( ! V_22 -> V_76 ) ;
if ( V_22 -> V_178 )
return 0 ;
if ( ! F_94 ( V_22 , 0 , V_177 , V_22 -> V_76 , V_179 , 0 , true ) ) {
F_7 ( L_81 ,
V_22 -> V_74 ) ;
F_95 ( V_22 -> V_5 , V_22 ) ;
return - V_35 ;
}
V_22 -> V_178 = 1 ;
return 0 ;
}
static void F_96 ( struct V_180 * V_181 , T_3 * V_182 )
{
V_182 [ 0 ] = F_97 ( V_181 -> V_182 ) ;
memset ( V_182 + 1 , 0 , sizeof( V_181 -> V_183 ) ) ;
if ( F_98 ( V_181 -> V_184 ) & V_185 ) {
int V_62 = F_6 ( V_181 -> V_183 ) ;
while ( V_62 -- )
V_182 [ V_62 + 1 ] = F_97 ( V_181 -> V_183 [ V_62 ] ) ;
}
}
static void F_99 ( struct V_180 * V_181 , T_3 * V_182 )
{
int V_62 = F_6 ( V_181 -> V_183 ) ;
V_181 -> V_182 = F_100 ( V_182 [ 0 ] ) ;
while ( V_62 -- )
V_181 -> V_183 [ V_62 ] = F_100 ( V_182 [ V_62 + 1 ] ) ;
}
static void F_101 ( struct V_5 * V_5 , struct V_52 * V_22 )
{
bool V_186 = false ;
unsigned int V_62 ;
T_3 V_182 [ V_187 ] ;
struct V_180 * V_181 ;
struct V_1 * V_2 = F_83 ( V_5 , struct V_1 , V_6 ) ;
if ( ! V_22 -> V_80 )
return;
F_93 ( ! V_22 -> V_76 ) ;
V_181 = F_102 ( V_22 -> V_76 ) ;
F_96 ( V_181 , V_182 ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ )
if ( ! V_2 -> V_21 [ V_62 ] . V_68 || F_34 ( V_115 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) ) {
V_186 = true ;
F_69 ( V_62 , ( void * ) V_182 ) ;
}
if ( V_186 )
F_99 ( V_181 , V_182 ) ;
V_181 -> V_188 = F_103 ( V_189 ) ;
V_181 -> V_184 = F_103 ( V_185 ) ;
V_181 -> V_190 = F_103 ( V_5 -> V_58 ) ;
V_181 -> V_191 = F_103 ( V_22 -> V_74 ) ;
V_181 -> V_192 = F_100 ( V_5 -> V_192 ) ;
V_181 -> V_193 = F_100 ( V_22 -> V_79 ) ;
V_181 -> V_194 = F_100 ( V_5 -> V_20 ) ;
V_181 -> V_19 = F_103 ( V_5 -> V_19 ) ;
V_181 -> V_36 = F_103 ( V_5 -> V_36 ) ;
V_181 -> V_195 = F_103 ( V_5 -> V_57 ) ;
V_181 -> V_7 = F_103 ( V_5 -> V_7 ) ;
V_181 -> V_8 = F_103 ( V_5 -> V_8 ) ;
V_181 -> V_196 = F_103 ( V_5 -> V_9 ) ;
V_181 -> V_59 = F_103 ( V_5 -> V_59 ) ;
F_84 () ;
V_181 -> V_24 = F_100 ( V_5 -> V_24 ) ;
if ( F_97 ( V_181 -> V_24 ) != V_25 ) {
V_181 -> V_78 |= F_103 ( V_197 ) ;
if ( V_5 -> V_59 < 0 || V_5 -> V_198 )
V_181 -> V_78 |= F_103 ( V_199 ) ;
} else {
V_181 -> V_78 &= ~ ( F_103 ( V_197 | V_199 ) ) ;
}
V_181 -> V_56 = F_100 ( V_5 -> V_56 ) ;
V_181 -> V_75 = F_100 ( V_22 -> V_75 ) ;
V_181 -> V_200 = F_100 ( V_22 -> V_200 ) ;
V_181 -> V_23 = F_100 ( V_22 -> V_23 ) ;
V_181 -> V_201 = F_103 ( 0 ) ;
memset ( V_181 + 1 , 0 , V_22 -> V_202 - sizeof( * V_181 ) ) ;
}
static int F_104 ( struct V_52 * V_22 , struct V_52 * V_203 )
{
int V_46 ;
struct V_180 * V_181 ;
struct V_180 * V_204 ;
T_3 V_205 , V_206 ;
V_22 -> V_207 = 0 ;
V_22 -> V_202 = F_105 ( V_22 -> V_80 ) ;
if ( V_22 -> V_202 < sizeof( * V_181 ) || V_22 -> V_202 > V_131 ) {
F_7 ( L_82 ) ;
return - V_35 ;
}
V_46 = F_92 ( V_22 , V_22 -> V_202 ) ;
if ( V_46 )
return V_46 ;
V_181 = F_102 ( V_22 -> V_76 ) ;
if ( ( V_181 -> V_188 != F_103 ( V_189 ) ) ||
( ! F_34 ( V_77 , & V_22 -> V_78 ) && ! V_22 -> V_79 ) ) {
F_101 ( V_22 -> V_5 , V_22 ) ;
F_69 ( V_208 , & V_22 -> V_78 ) ;
V_181 -> V_184 = F_103 ( V_185 ) ;
F_69 ( V_209 , & V_22 -> V_5 -> V_78 ) ;
return V_203 ? 0 : 1 ;
}
if ( ! V_203 )
return 1 ;
V_205 = F_97 ( V_181 -> V_192 ) ;
V_204 = F_102 ( V_203 -> V_76 ) ;
V_206 = F_97 ( V_204 -> V_192 ) ;
return ( V_205 > V_206 ) ? 1 : 0 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_52 * V_22 )
{
int V_210 ;
unsigned int V_211 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
T_3 V_205 ;
T_3 V_182 [ V_187 ] ;
struct V_180 * V_181 ;
T_1 V_212 = 0 , V_213 = 0 , V_214 = 0 ;
struct V_52 * V_46 ;
struct V_180 * V_215 ;
V_181 = F_102 ( V_22 -> V_76 ) ;
V_205 = F_97 ( V_181 -> V_192 ) ;
V_5 -> V_192 = V_205 ? : 1 ;
V_5 -> V_24 = V_25 ;
if ( F_98 ( V_181 -> V_184 ) & V_185 ) {
V_5 -> V_58 = F_98 ( V_181 -> V_190 ) ;
V_5 -> V_19 = F_98 ( V_181 -> V_19 ) ;
V_5 -> V_36 = F_98 ( V_181 -> V_36 ) ;
V_5 -> V_57 = F_98 ( V_181 -> V_195 ) ;
V_5 -> V_7 = F_98 ( V_181 -> V_7 ) ;
V_5 -> V_8 = F_98 ( V_181 -> V_8 ) ;
V_5 -> V_9 = F_98 ( V_181 -> V_196 ) ;
V_5 -> V_59 = F_98 ( V_181 -> V_59 ) ;
V_5 -> V_56 = F_97 ( V_181 -> V_56 ) ;
if ( F_98 ( V_181 -> V_78 ) & V_197 ) {
if ( F_34 ( V_133 , & V_2 -> V_33 ) ) {
F_7 ( L_83 ) ;
return - V_35 ;
}
if ( V_5 -> V_59 < 0 ||
( ! V_5 -> V_59 && ( F_98 ( V_181 -> V_78 ) & V_199 ) ) )
V_5 -> V_198 = 1 ;
else
V_5 -> V_198 = 0 ;
V_5 -> V_24 = F_97 ( V_181 -> V_24 ) ;
V_2 -> V_26 = F_37 ( V_5 -> V_19 , V_5 -> V_36 ) ;
}
} else {
if ( F_98 ( V_181 -> V_19 ) != V_5 -> V_7 ) {
F_7 ( L_84 ) ;
return - V_35 ;
}
if ( F_98 ( V_181 -> V_36 ) != V_5 -> V_8 ) {
F_7 ( L_85 ) ;
F_7 ( L_86 , F_98 ( V_181 -> V_36 ) , V_5 -> V_36 ) ;
F_7 ( L_87 ,
F_29 ( F_98 ( V_181 -> V_36 ) ) ,
F_32 ( F_98 ( V_181 -> V_36 ) ) ) ;
F_7 ( L_88 ,
F_29 ( V_5 -> V_36 ) ,
F_32 ( V_5 -> V_36 ) ) ;
return - V_35 ;
}
if ( F_98 ( V_181 -> V_195 ) != V_5 -> V_9 ) {
F_7 ( L_89 ) ;
return - V_35 ;
}
if ( ! F_18 ( V_2 -> V_26 ) &&
( F_98 ( V_181 -> V_190 ) != V_5 -> V_58 ) ) {
F_7 ( L_90 ,
V_181 -> V_190 , V_5 -> V_58 ) ;
return - V_35 ;
}
F_63 ( L_91 ) ;
F_45 ( V_2 ) ;
}
if ( ! F_34 ( V_107 , & V_2 -> V_33 ) )
V_5 -> V_20 = F_97 ( V_181 -> V_194 ) ;
V_211 = 0 ;
F_41 (r, mddev) {
if ( F_34 ( V_208 , & V_46 -> V_78 ) )
V_212 ++ ;
if ( ! F_34 ( V_77 , & V_46 -> V_78 ) ) {
F_63 ( L_92 ,
V_46 -> V_74 ) ;
V_214 ++ ;
if ( F_34 ( V_208 , & V_46 -> V_78 ) )
V_213 ++ ;
}
V_211 ++ ;
}
if ( V_212 == V_2 -> V_58 || ! V_214 ) {
if ( V_212 == 1 && ! V_2 -> V_59 )
;
if ( V_212 == V_2 -> V_58 ) {
F_63 ( L_93 ) ;
F_69 ( V_216 , & V_5 -> V_78 ) ;
} else if ( V_212 != V_214 &&
V_212 != V_2 -> V_59 ) {
F_7 ( L_94
L_95 ) ;
return - V_35 ;
}
} else if ( V_212 && V_212 != V_214 ) {
F_7 ( L_96
L_97 ,
V_214 , V_212 ) ;
return - V_35 ;
} else if ( V_214 ) {
if ( V_213 && V_214 != V_213 ) {
F_7 ( L_98 ,
V_212 > 1 ? L_99 : L_100 ) ;
return - V_35 ;
} else if ( F_15 ( V_2 ) ) {
F_7 ( L_101 ,
( unsigned long long ) V_5 -> V_20 ) ;
return - V_35 ;
} else if ( F_16 ( V_2 ) ) {
F_7 ( L_102 ,
( unsigned long long ) V_5 -> V_24 ) ;
return - V_35 ;
}
}
F_96 ( V_181 , V_182 ) ;
F_41 (r, mddev) {
if ( ! V_46 -> V_76 )
continue;
V_215 = F_102 ( V_46 -> V_76 ) ;
V_215 -> V_182 = 0 ;
memset ( V_215 -> V_183 , 0 , sizeof( V_215 -> V_183 ) ) ;
if ( ! F_34 ( V_208 , & V_46 -> V_78 ) && ( V_46 -> V_74 >= 0 ) ) {
V_210 = F_98 ( V_215 -> V_191 ) ;
if ( V_210 < 0 )
continue;
if ( V_210 != V_46 -> V_74 ) {
if ( F_28 ( V_5 -> V_36 ) ) {
if ( V_5 -> V_58 % F_25 ( V_5 -> V_36 ) ||
V_2 -> V_58 % V_2 -> V_100 ) {
V_2 -> V_34 -> error =
L_103 ;
return - V_35 ;
}
V_215 -> V_191 = F_103 ( V_46 -> V_74 ) ;
} else if ( ! ( F_10 ( V_2 ) && F_17 ( V_2 -> V_26 ) ) &&
! ( F_8 ( V_2 ) && F_19 ( V_2 -> V_26 ) ) &&
! F_18 ( V_2 -> V_26 ) ) {
V_2 -> V_34 -> error = L_104 ;
return - V_35 ;
}
F_63 ( L_105 , V_210 , V_46 -> V_74 ) ;
}
if ( F_34 ( V_210 , ( void * ) V_182 ) )
F_69 ( V_115 , & V_46 -> V_78 ) ;
}
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_52 * V_22 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_180 * V_181 ;
if ( F_8 ( V_2 ) || ! V_22 -> V_76 )
return 0 ;
V_181 = F_102 ( V_22 -> V_76 ) ;
if ( ! V_5 -> V_192 && F_106 ( V_2 , V_22 ) )
return - V_35 ;
if ( F_98 ( V_181 -> V_184 ) &&
F_98 ( V_181 -> V_184 ) != V_185 ) {
V_2 -> V_34 -> error = L_106 ;
return - V_35 ;
}
if ( V_181 -> V_201 ) {
V_2 -> V_34 -> error = L_107 ;
return - V_35 ;
}
V_5 -> V_90 . V_217 = F_17 ( V_2 -> V_26 ) ? 0 : F_72 ( 4096 ) ;
V_22 -> V_5 -> V_90 . V_218 = V_5 -> V_90 . V_217 ;
if ( ! F_108 ( V_208 , & V_22 -> V_78 ) ) {
V_22 -> V_23 = F_97 ( V_181 -> V_23 ) ;
V_22 -> V_79 = F_97 ( V_181 -> V_193 ) ;
if ( V_22 -> V_79 == V_25 )
F_69 ( V_77 , & V_22 -> V_78 ) ;
else if ( ! F_16 ( V_2 ) )
F_71 ( V_77 , & V_22 -> V_78 ) ;
}
if ( F_108 ( V_115 , & V_22 -> V_78 ) ) {
V_22 -> V_79 = 0 ;
F_71 ( V_77 , & V_22 -> V_78 ) ;
V_22 -> V_219 = V_22 -> V_74 ;
}
V_22 -> V_75 = F_97 ( V_181 -> V_75 ) ;
V_22 -> V_200 = F_97 ( V_181 -> V_200 ) ;
return 0 ;
}
static int F_109 ( struct V_60 * V_34 , struct V_1 * V_2 )
{
int V_46 ;
struct V_104 * V_21 ;
struct V_52 * V_22 , * V_220 , * V_221 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
V_221 = NULL ;
F_110 (rdev, tmp, mddev) {
if ( F_34 ( V_109 , & V_2 -> V_33 ) )
continue;
if ( ! V_22 -> V_80 )
continue;
V_46 = F_104 ( V_22 , V_221 ) ;
switch ( V_46 ) {
case 1 :
V_221 = V_22 ;
break;
case 0 :
break;
default:
if ( F_8 ( V_2 ) )
continue;
V_21 = F_83 ( V_22 , struct V_104 , V_22 ) ;
if ( V_21 -> V_67 )
F_52 ( V_34 , V_21 -> V_67 ) ;
V_21 -> V_67 = NULL ;
V_22 -> V_80 = NULL ;
if ( V_22 -> V_76 )
F_111 ( V_22 -> V_76 ) ;
V_22 -> V_76 = NULL ;
V_22 -> V_178 = 0 ;
if ( V_21 -> V_68 )
F_52 ( V_34 , V_21 -> V_68 ) ;
V_21 -> V_68 = NULL ;
V_22 -> V_81 = NULL ;
F_112 ( & V_22 -> V_82 ) ;
}
}
if ( ! V_221 )
return 0 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_34 -> error = L_108 ;
return - V_35 ;
}
V_2 -> V_34 -> error = L_109 ;
if ( F_107 ( V_2 , V_221 ) )
return - V_35 ;
F_41 (rdev, mddev)
if ( ( V_22 != V_221 ) && F_107 ( V_2 , V_22 ) )
return - V_35 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
T_2 V_75 = 0 , V_200 = 0 ;
struct V_52 * V_22 ;
if ( ! F_34 ( V_129 , & V_2 -> V_33 ) ) {
if ( ! F_13 ( V_2 ) )
goto V_222;
return 0 ;
}
V_22 = & V_2 -> V_21 [ 0 ] . V_22 ;
if ( V_2 -> V_59 < 0 ) {
V_75 = 0 ;
V_200 = V_2 -> V_75 ;
} else if ( V_2 -> V_59 > 0 ) {
V_75 = V_2 -> V_75 ;
V_200 = 0 ;
} else {
V_75 = V_2 -> V_75 ? V_22 -> V_75 : 0 ;
V_200 = V_75 ? 0 : V_2 -> V_75 ;
F_69 ( V_223 , & V_2 -> V_224 ) ;
}
if ( V_2 -> V_75 &&
F_72 ( F_114 ( V_22 -> V_81 -> V_225 ) ) - V_22 -> V_23 < V_130 ) {
V_2 -> V_34 -> error = V_75 ? L_110 :
L_111 ;
return - V_226 ;
}
V_222:
F_41 (rdev, &rs->md) {
V_22 -> V_75 = V_75 ;
V_22 -> V_200 = V_200 ;
}
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
int V_62 = 0 ;
struct V_52 * V_22 ;
F_41 (rdev, &rs->md) {
V_22 -> V_74 = V_62 ++ ;
V_22 -> V_219 = V_22 -> V_227 = - 1 ;
}
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_52 * V_22 ;
unsigned int V_211 = V_5 -> V_58 = V_2 -> V_58 ;
T_2 V_200 = V_2 -> V_21 [ 0 ] . V_22 . V_75 ? 0 : V_2 -> V_75 ;
if ( F_19 ( V_2 -> V_26 ) ) {
if ( V_5 -> V_19 == 0 ) {
F_115 ( V_2 ) ;
V_5 -> V_36 = F_33 ( V_2 , V_41 ,
V_2 -> V_100 ) ;
} else if ( V_5 -> V_19 == 1 )
V_5 -> V_36 = F_33 ( V_2 , V_39 ,
V_2 -> V_58 ) ;
else
return - V_35 ;
}
F_71 ( V_216 , & V_5 -> V_78 ) ;
V_5 -> V_20 = V_25 ;
while ( V_211 -- ) {
V_22 = & V_2 -> V_21 [ V_211 ] . V_22 ;
if ( F_34 ( V_211 , ( void * ) V_2 -> V_114 ) ) {
F_71 ( V_77 , & V_22 -> V_78 ) ;
F_71 ( V_115 , & V_22 -> V_78 ) ;
V_5 -> V_20 = V_22 -> V_79 = 0 ;
F_69 ( V_216 , & V_5 -> V_78 ) ;
}
V_22 -> V_200 = V_200 ;
}
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
bool V_228 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_10 ( V_2 ) ) {
if ( V_2 -> V_58 != V_5 -> V_58 &&
F_28 ( V_5 -> V_36 ) &&
V_2 -> V_100 &&
V_2 -> V_100 != F_25 ( V_5 -> V_36 ) ) {
if ( V_2 -> V_58 % V_2 -> V_100 ) {
V_2 -> V_34 -> error = L_112 ;
return - V_35 ;
}
F_115 ( V_2 ) ;
V_5 -> V_36 = F_33 ( V_2 , V_39 ,
V_2 -> V_100 ) ;
V_5 -> V_8 = V_5 -> V_36 ;
V_228 = false ;
} else
V_228 = true ;
} else if ( F_12 ( V_2 ) )
V_228 = true ;
else if ( F_9 ( V_2 ) ) {
if ( V_2 -> V_59 ) {
V_5 -> V_167 = V_2 -> V_59 < 0 ? - V_2 -> V_59 : V_2 -> V_59 ;
V_228 = true ;
} else {
V_5 -> V_58 = V_2 -> V_58 ;
V_228 = false ;
}
} else {
V_2 -> V_34 -> error = L_113 ;
return - V_35 ;
}
if ( V_228 ) {
F_69 ( V_229 , & V_2 -> V_224 ) ;
F_69 ( V_223 , & V_2 -> V_224 ) ;
} else if ( V_5 -> V_58 < V_2 -> V_58 )
F_69 ( V_223 , & V_2 -> V_224 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
unsigned int V_230 , V_211 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_52 * V_22 ;
V_5 -> V_59 = V_2 -> V_59 ;
V_230 = V_5 -> V_58 ;
if ( V_5 -> V_59 &&
V_5 -> V_36 != V_5 -> V_8 ) {
F_63 ( L_114 , V_2 -> V_59 ) ;
V_5 -> V_8 = V_5 -> V_36 ;
}
if ( V_2 -> V_59 > 0 ) {
for ( V_211 = V_230 ; V_211 < V_2 -> V_58 ; V_211 ++ ) {
V_22 = & V_2 -> V_21 [ V_211 ] . V_22 ;
F_71 ( V_77 , & V_22 -> V_78 ) ;
V_22 -> V_219 = - 1 ;
V_22 -> V_74 = V_211 ;
V_22 -> V_23 = V_5 -> V_55 ;
V_22 -> V_79 = F_9 ( V_2 ) ? 0 : V_25 ;
}
V_5 -> V_198 = 0 ;
} else if ( V_2 -> V_59 < 0 ) {
V_46 = F_78 ( V_2 , true ) ;
V_5 -> V_198 = 1 ;
} else {
V_5 -> V_198 = V_2 -> V_21 [ 0 ] . V_22 . V_75 ? 0 : 1 ;
}
return V_46 ;
}
static void F_119 ( struct V_1 * V_2 )
{
int V_62 ;
bool V_231 ;
struct V_60 * V_34 = V_2 -> V_34 ;
V_34 -> V_232 = false ;
V_231 = ( V_2 -> V_6 . V_19 == 4 || V_2 -> V_6 . V_19 == 5 || V_2 -> V_6 . V_19 == 6 ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ ) {
struct V_233 * V_234 ;
if ( ! V_2 -> V_21 [ V_62 ] . V_22 . V_81 )
continue;
V_234 = F_120 ( V_2 -> V_21 [ V_62 ] . V_22 . V_81 ) ;
if ( ! V_234 || ! F_121 ( V_234 ) )
return;
if ( V_231 ) {
if ( ! V_234 -> V_235 . V_236 )
return;
if ( ! V_237 ) {
F_7 ( L_115 ) ;
F_7 ( L_116 ) ;
return;
}
}
}
V_34 -> V_232 = true ;
V_34 -> V_238 = ! ! ( V_2 -> V_6 . V_19 == 1 || V_2 -> V_6 . V_19 == 10 ) ;
V_34 -> V_239 = 1 ;
}
static int F_122 ( struct V_60 * V_34 , unsigned int V_240 , char * * V_241 )
{
int V_46 ;
bool V_242 ;
struct V_26 * V_27 ;
unsigned int V_97 , V_243 ;
T_2 V_244 ;
struct V_1 * V_2 = NULL ;
const char * V_73 ;
struct V_3 V_3 ;
struct V_69 V_70 = { V_240 , V_241 } , V_245 ;
struct V_246 V_247 [] = {
{ 0 , V_70 . V_240 , L_117 } ,
{ 1 , 254 , L_118 }
} ;
V_73 = F_56 ( & V_70 ) ;
if ( ! V_73 ) {
V_34 -> error = L_119 ;
return - V_35 ;
}
V_27 = F_36 ( V_73 ) ;
if ( ! V_27 ) {
V_34 -> error = L_120 ;
return - V_35 ;
}
if ( F_123 ( V_247 , & V_70 , & V_97 , & V_34 -> error ) )
return - V_35 ;
V_245 = V_70 ;
F_124 ( & V_245 , V_97 ) ;
V_247 [ 1 ] . V_12 = ( V_245 . V_240 - 1 ) / 2 ;
if ( F_125 ( V_247 + 1 , & V_245 , & V_243 , & V_34 -> error ) )
return - V_35 ;
if ( ! F_3 ( V_243 , 1 , V_134 ) ) {
V_34 -> error = L_121 ;
return - V_35 ;
}
V_2 = F_46 ( V_34 , V_27 , V_243 ) ;
if ( F_126 ( V_2 ) )
return F_127 ( V_2 ) ;
V_46 = F_67 ( V_2 , & V_70 , V_97 ) ;
if ( V_46 )
goto V_158;
V_46 = F_55 ( V_2 , & V_70 ) ;
if ( V_46 )
goto V_158;
V_2 -> V_6 . V_248 = F_101 ;
V_46 = F_78 ( V_2 , false ) ;
if ( V_46 )
goto V_158;
V_244 = V_2 -> V_21 [ 0 ] . V_22 . V_23 ;
F_1 ( V_2 , & V_3 ) ;
V_46 = F_109 ( V_34 , V_2 ) ;
if ( V_46 )
goto V_158;
V_242 = V_244 != V_2 -> V_21 [ 0 ] . V_22 . V_23 ;
F_128 ( & V_2 -> V_6 . V_161 , F_82 ) ;
V_34 -> V_154 = V_2 ;
V_34 -> V_249 = 1 ;
F_2 ( V_2 , & V_3 ) ;
if ( F_34 ( V_216 , & V_2 -> V_6 . V_78 ) ) {
if ( F_11 ( V_2 ) &&
F_34 ( V_107 , & V_2 -> V_33 ) ) {
V_34 -> error = L_122 ;
V_46 = - V_35 ;
goto V_158;
}
F_81 ( V_2 , 0 ) ;
F_69 ( V_223 , & V_2 -> V_224 ) ;
F_45 ( V_2 ) ;
} else if ( F_15 ( V_2 ) ) {
;
} else if ( F_16 ( V_2 ) ) {
if ( V_242 ) {
V_34 -> error = L_123 ;
V_46 = - V_168 ;
goto V_158;
}
} else if ( F_89 ( V_2 ) ) {
if ( F_16 ( V_2 ) ) {
V_34 -> error = L_124 ;
V_46 = - V_168 ;
goto V_158;
}
V_46 = F_88 ( V_2 ) ;
if ( V_46 )
goto V_158;
V_46 = F_116 ( V_2 ) ;
if ( V_46 )
goto V_158;
F_69 ( V_223 , & V_2 -> V_224 ) ;
F_81 ( V_2 , V_25 ) ;
F_45 ( V_2 ) ;
} else if ( F_90 ( V_2 ) ) {
V_46 = F_117 ( V_2 ) ;
if ( V_46 )
return V_46 ;
F_81 ( V_2 , V_25 ) ;
F_44 ( V_2 ) ;
} else {
if ( F_34 ( V_116 , & V_2 -> V_33 ) ) {
F_81 ( V_2 , V_25 ) ;
F_69 ( V_223 , & V_2 -> V_224 ) ;
} else
F_81 ( V_2 , F_34 ( V_109 , & V_2 -> V_33 ) ?
0 : ( V_242 ? V_244 : V_25 ) ) ;
F_44 ( V_2 ) ;
}
V_46 = F_113 ( V_2 ) ;
if ( V_46 )
goto V_158;
V_2 -> V_6 . V_250 = 1 ;
V_2 -> V_6 . V_251 = 1 ;
F_69 ( V_252 , & V_2 -> V_6 . V_253 ) ;
F_129 ( & V_2 -> V_6 ) ;
V_46 = F_130 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_251 = 0 ;
if ( V_46 ) {
V_34 -> error = L_125 ;
F_131 ( & V_2 -> V_6 ) ;
goto V_158;
}
V_2 -> V_165 . V_254 = F_86 ;
F_132 ( V_34 -> V_54 , & V_2 -> V_165 ) ;
F_133 ( & V_2 -> V_6 ) ;
if ( F_12 ( V_2 ) ) {
V_46 = F_74 ( V_2 ) ;
if ( V_46 )
goto V_255;
}
if ( F_34 ( V_229 , & V_2 -> V_224 ) ) {
V_46 = F_91 ( V_2 ) ;
if ( V_46 )
goto V_256;
F_2 ( V_2 , & V_3 ) ;
if ( V_2 -> V_6 . V_175 -> V_257 ) {
V_46 = V_2 -> V_6 . V_175 -> V_176 ( & V_2 -> V_6 ) ;
if ( V_46 ) {
V_34 -> error = L_126 ;
goto V_256;
}
}
}
F_131 ( & V_2 -> V_6 ) ;
return 0 ;
V_255:
V_256:
F_134 ( & V_2 -> V_6 ) ;
V_158:
F_51 ( V_2 ) ;
return V_46 ;
}
static void F_135 ( struct V_60 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
F_136 ( & V_2 -> V_165 . V_258 ) ;
F_134 ( & V_2 -> V_6 ) ;
F_51 ( V_2 ) ;
}
static int F_137 ( struct V_60 * V_34 , struct V_259 * V_259 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_138 ( F_139 ( V_259 ) > V_5 -> V_56 ) )
return V_260 ;
V_5 -> V_175 -> V_261 ( V_5 , V_259 ) ;
return V_262 ;
}
static const char * F_140 ( struct V_5 * V_5 )
{
if ( F_34 ( V_252 , & V_5 -> V_253 ) )
return L_127 ;
if ( F_34 ( V_263 , & V_5 -> V_253 ) ||
( ! V_5 -> V_250 && F_34 ( V_264 , & V_5 -> V_253 ) ) ) {
if ( F_34 ( V_265 , & V_5 -> V_253 ) )
return L_128 ;
if ( F_34 ( V_266 , & V_5 -> V_253 ) ) {
if ( ! F_34 ( V_267 , & V_5 -> V_253 ) )
return L_129 ;
else if ( F_34 ( V_268 , & V_5 -> V_253 ) )
return L_130 ;
return L_131 ;
}
if ( F_34 ( V_269 , & V_5 -> V_253 ) )
return L_132 ;
}
return L_133 ;
}
static const char * F_141 ( struct V_52 * V_22 , bool V_270 )
{
if ( F_34 ( V_115 , & V_22 -> V_78 ) )
return L_134 ;
else if ( ! V_270 || ! F_34 ( V_77 , & V_22 -> V_78 ) )
return L_135 ;
else
return L_136 ;
}
static T_2 F_142 ( struct V_1 * V_2 ,
T_2 V_271 , bool * V_270 )
{
T_2 V_46 , V_20 , V_272 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
V_272 = V_5 -> V_272 ? : V_5 -> V_20 ;
V_20 = V_5 -> V_20 ;
* V_270 = false ;
if ( F_8 ( V_2 ) ) {
V_46 = V_271 ;
* V_270 = true ;
} else {
V_46 = V_5 -> V_24 ;
if ( F_34 ( V_265 , & V_5 -> V_253 ) ||
V_46 != V_25 ) {
if ( V_46 == V_25 ) {
* V_270 = true ;
V_46 = V_271 ;
} else {
if ( V_5 -> V_198 )
V_46 = V_5 -> V_56 - V_46 ;
F_79 ( V_46 , F_76 ( V_2 ) ) ;
}
} else if ( F_34 ( V_263 , & V_5 -> V_253 ) )
V_46 = V_272 ;
else
V_46 = V_20 ;
if ( V_46 == V_25 ) {
* V_270 = true ;
V_46 = V_271 ;
} else if ( F_34 ( V_267 , & V_5 -> V_253 ) ) {
* V_270 = true ;
} else {
struct V_52 * V_22 ;
F_41 (rdev, mddev)
if ( ! F_34 ( V_77 , & V_22 -> V_78 ) )
* V_270 = true ;
#if 0
r = 0;
#endif
}
}
return V_46 ;
}
static const char * F_143 ( struct V_273 * V_21 )
{
return V_21 ? V_21 -> V_17 : L_8 ;
}
static void F_144 ( struct V_60 * V_34 , T_4 type ,
unsigned int V_274 , char * V_275 , unsigned int V_276 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_150 * V_151 = V_5 -> V_154 ;
int V_62 , V_277 = V_151 ? V_151 -> V_277 : 0 ;
bool V_270 ;
unsigned int V_278 = 1 ;
unsigned int V_279 = 0 ;
unsigned int V_114 ;
unsigned int V_280 = 0 ;
T_2 V_281 , V_271 , V_282 ;
const char * V_283 ;
struct V_26 * V_27 ;
struct V_52 * V_22 ;
switch ( type ) {
case V_284 :
V_27 = F_37 ( V_5 -> V_7 , V_5 -> V_8 ) ;
if ( ! V_27 )
return;
F_145 ( L_137 , V_27 -> V_17 , V_5 -> V_58 ) ;
F_84 () ;
V_271 = F_34 ( V_285 , & V_2 -> V_224 ) ?
V_5 -> V_271 : V_5 -> V_55 ;
V_281 = F_142 ( V_2 , V_271 , & V_270 ) ;
V_282 = ( V_5 -> V_286 && ! strcasecmp ( V_5 -> V_286 , L_130 ) ) ?
F_146 ( & V_5 -> V_282 ) : 0 ;
V_283 = F_140 ( & V_2 -> V_6 ) ;
F_41 (rdev, mddev)
F_145 ( F_141 ( V_22 , V_270 ) ) ;
F_145 ( L_138 , ( unsigned long long ) V_281 ,
( unsigned long long ) V_271 ) ;
F_145 ( L_139 , V_283 ) ;
F_145 ( L_140 , ( unsigned long long ) V_282 ) ;
F_145 ( L_140 , ( unsigned long long ) V_2 -> V_21 [ 0 ] . V_22 . V_75 ) ;
break;
case V_287 :
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ )
if ( F_34 ( V_118 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) )
V_280 += 2 ;
V_114 = F_147 ( V_2 -> V_114 , V_187 * sizeof( * V_2 -> V_114 ) ) ;
V_278 += V_114 * 2 +
V_280 +
F_5 ( V_2 -> V_33 & V_288 ) +
F_5 ( V_2 -> V_33 & V_289 ) * 2 ;
F_145 ( L_141 , V_2 -> V_26 -> V_17 , V_278 , V_5 -> V_9 ) ;
if ( F_34 ( V_112 , & V_2 -> V_33 ) )
F_145 ( L_142 , F_4 ( V_111 ) ,
F_29 ( V_5 -> V_36 ) ) ;
if ( F_34 ( V_149 , & V_2 -> V_33 ) )
F_145 ( L_143 , F_4 ( V_148 ) ,
F_32 ( V_5 -> V_36 ) ) ;
if ( F_34 ( V_107 , & V_2 -> V_33 ) )
F_145 ( L_139 , F_4 ( V_106 ) ) ;
if ( F_34 ( V_109 , & V_2 -> V_33 ) )
F_145 ( L_139 , F_4 ( V_108 ) ) ;
if ( F_34 ( V_146 , & V_2 -> V_33 ) )
F_145 ( L_144 , F_4 ( V_145 ) ,
( unsigned long long ) F_72 ( V_5 -> V_90 . V_91 ) ) ;
if ( F_34 ( V_129 , & V_2 -> V_33 ) )
F_145 ( L_144 , F_4 ( V_128 ) ,
( unsigned long long ) V_2 -> V_75 ) ;
if ( F_34 ( V_125 , & V_2 -> V_33 ) )
F_145 ( L_145 , F_4 ( V_124 ) ,
V_5 -> V_90 . V_127 ) ;
if ( F_34 ( V_133 , & V_2 -> V_33 ) )
F_145 ( L_143 , F_4 ( V_132 ) ,
V_12 ( V_2 -> V_59 , V_5 -> V_59 ) ) ;
if ( F_34 ( V_137 , & V_2 -> V_33 ) )
F_145 ( L_143 , F_4 ( V_136 ) ,
V_277 ) ;
if ( V_114 )
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ )
if ( F_34 ( V_2 -> V_21 [ V_62 ] . V_22 . V_74 , ( void * ) V_2 -> V_114 ) )
F_145 ( L_146 , F_4 ( V_113 ) ,
V_2 -> V_21 [ V_62 ] . V_22 . V_74 ) ;
if ( V_280 )
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ )
if ( F_34 ( V_118 , & V_2 -> V_21 [ V_62 ] . V_22 . V_78 ) )
F_145 ( L_143 , F_4 ( V_117 ) ,
V_2 -> V_21 [ V_62 ] . V_22 . V_74 ) ;
if ( F_34 ( V_121 , & V_2 -> V_33 ) )
F_145 ( L_145 , F_4 ( V_120 ) ,
V_5 -> V_90 . V_123 ) ;
if ( F_34 ( V_143 , & V_2 -> V_33 ) )
F_145 ( L_143 , F_4 ( V_142 ) ,
V_5 -> V_144 ) ;
if ( F_34 ( V_139 , & V_2 -> V_33 ) )
F_145 ( L_143 , F_4 ( V_138 ) ,
V_5 -> V_141 ) ;
F_145 ( L_147 , V_2 -> V_58 ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_58 ; V_62 ++ )
F_145 ( L_142 , F_143 ( V_2 -> V_21 [ V_62 ] . V_67 ) ,
F_143 ( V_2 -> V_21 [ V_62 ] . V_68 ) ) ;
}
}
static int F_148 ( struct V_60 * V_34 , unsigned int V_240 , char * * V_241 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_175 || ! V_5 -> V_175 -> V_290 )
return - V_35 ;
if ( ! strcasecmp ( V_241 [ 0 ] , L_127 ) )
F_69 ( V_252 , & V_5 -> V_253 ) ;
else
F_71 ( V_252 , & V_5 -> V_253 ) ;
if ( ! strcasecmp ( V_241 [ 0 ] , L_133 ) || ! strcasecmp ( V_241 [ 0 ] , L_127 ) ) {
if ( V_5 -> V_291 ) {
F_69 ( V_292 , & V_5 -> V_253 ) ;
F_149 ( V_5 ) ;
}
} else if ( F_34 ( V_263 , & V_5 -> V_253 ) ||
F_34 ( V_264 , & V_5 -> V_253 ) )
return - V_293 ;
else if ( ! strcasecmp ( V_241 [ 0 ] , L_129 ) )
;
else if ( ! strcasecmp ( V_241 [ 0 ] , L_132 ) )
F_69 ( V_269 , & V_5 -> V_253 ) ;
else {
if ( ! strcasecmp ( V_241 [ 0 ] , L_130 ) )
F_69 ( V_268 , & V_5 -> V_253 ) ;
else if ( ! ! strcasecmp ( V_241 [ 0 ] , L_131 ) )
return - V_35 ;
F_69 ( V_267 , & V_5 -> V_253 ) ;
F_69 ( V_266 , & V_5 -> V_253 ) ;
}
if ( V_5 -> V_250 == 2 ) {
V_5 -> V_250 = 0 ;
if ( ! V_5 -> V_294 && V_5 -> V_291 )
F_150 ( V_5 -> V_291 ) ;
}
F_69 ( V_264 , & V_5 -> V_253 ) ;
if ( ! V_5 -> V_294 && V_5 -> V_295 )
F_150 ( V_5 -> V_295 ) ;
return 0 ;
}
static int F_151 ( struct V_60 * V_34 ,
T_5 V_296 , void * V_297 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
unsigned int V_62 ;
int V_46 = 0 ;
for ( V_62 = 0 ; ! V_46 && V_62 < V_2 -> V_6 . V_58 ; V_62 ++ )
if ( V_2 -> V_21 [ V_62 ] . V_68 )
V_46 = V_296 ( V_34 ,
V_2 -> V_21 [ V_62 ] . V_68 ,
0 ,
V_2 -> V_6 . V_55 ,
V_297 ) ;
return V_46 ;
}
static void F_152 ( struct V_60 * V_34 , struct V_298 * V_235 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
unsigned int V_299 = F_65 ( V_2 -> V_6 . V_57 ) ;
F_153 ( V_235 , V_299 ) ;
F_154 ( V_235 , V_299 * F_76 ( V_2 ) ) ;
}
static void F_155 ( struct V_60 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
F_156 ( & V_2 -> V_6 ) ;
}
static void F_157 ( struct V_60 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
if ( ! V_2 -> V_6 . V_294 )
F_133 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_250 = 1 ;
}
static void F_158 ( struct V_1 * V_2 )
{
int V_62 ;
T_3 V_300 [ V_187 ] ;
unsigned long V_78 ;
bool V_301 = false ;
struct V_180 * V_181 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_52 * V_46 ;
if ( ! V_5 -> V_175 || ! V_5 -> V_175 -> V_302 || ! V_5 -> V_175 -> V_303 )
return;
memset ( V_300 , 0 , sizeof( V_300 ) ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_6 . V_58 ; V_62 ++ ) {
V_46 = & V_2 -> V_21 [ V_62 ] . V_22 ;
if ( F_34 ( V_115 , & V_46 -> V_78 ) && V_46 -> V_76 &&
F_94 ( V_46 , 0 , V_46 -> V_202 , V_46 -> V_76 ,
V_179 , 0 , true ) ) {
F_63 ( L_148
L_149 ,
V_2 -> V_26 -> V_17 , V_62 ) ;
if ( ( V_46 -> V_74 >= 0 ) &&
( V_5 -> V_175 -> V_303 ( V_5 , V_46 ) != 0 ) )
continue;
V_46 -> V_74 = V_62 ;
V_46 -> V_219 = V_62 ;
V_78 = V_46 -> V_78 ;
F_71 ( V_115 , & V_46 -> V_78 ) ;
F_71 ( V_304 , & V_46 -> V_78 ) ;
F_71 ( V_77 , & V_46 -> V_78 ) ;
if ( V_5 -> V_175 -> V_302 ( V_5 , V_46 ) ) {
V_46 -> V_74 = - 1 ;
V_46 -> V_219 = - 1 ;
V_46 -> V_78 = V_78 ;
} else {
V_46 -> V_79 = 0 ;
F_69 ( V_62 , ( void * ) V_300 ) ;
V_301 = true ;
}
}
}
if ( V_301 ) {
T_3 V_182 [ V_187 ] ;
F_41 (r, &rs->md) {
V_181 = F_102 ( V_46 -> V_76 ) ;
F_96 ( V_181 , V_182 ) ;
for ( V_62 = 0 ; V_62 < V_187 ; V_62 ++ )
V_182 [ V_62 ] &= ~ V_300 [ V_62 ] ;
F_99 ( V_181 , V_182 ) ;
}
}
}
static int F_159 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
if ( ! F_8 ( V_2 ) &&
! F_70 ( V_305 , & V_2 -> V_224 ) ) {
V_46 = F_160 ( & V_2 -> V_6 ) ;
if ( V_46 )
F_7 ( L_150 ) ;
}
return V_46 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
int V_250 = V_5 -> V_250 ;
F_69 ( V_209 , & V_5 -> V_78 ) ;
V_5 -> V_250 = 0 ;
F_162 ( V_5 , 1 ) ;
V_5 -> V_250 = V_250 ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_46 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_306 * V_175 = V_5 -> V_175 ;
V_46 = F_118 ( V_2 ) ;
if ( V_46 )
return V_46 ;
if ( V_5 -> V_294 )
F_164 ( V_5 ) ;
V_46 = V_175 -> V_176 ( V_5 ) ;
if ( V_46 ) {
V_2 -> V_34 -> error = L_151 ;
return V_46 ;
}
if ( V_175 -> V_257 ) {
V_46 = V_175 -> V_257 ( V_5 ) ;
if ( V_46 ) {
V_2 -> V_34 -> error = L_152 ;
return V_46 ;
}
}
if ( ! V_5 -> V_294 )
F_133 ( V_5 ) ;
F_161 ( V_2 ) ;
return 0 ;
}
static int F_165 ( struct V_60 * V_34 )
{
int V_46 ;
struct V_1 * V_2 = V_34 -> V_154 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_70 ( V_285 , & V_2 -> V_224 ) )
return 0 ;
if ( F_34 ( V_223 , & V_2 -> V_224 ) )
F_161 ( V_2 ) ;
F_119 ( V_2 ) ;
V_46 = F_159 ( V_2 ) ;
if ( V_46 )
return V_46 ;
if ( F_34 ( V_305 , & V_2 -> V_224 ) &&
V_5 -> V_90 . V_91 != F_65 ( V_2 -> V_147 ) ) {
V_46 = F_166 ( V_5 -> V_307 , V_5 -> V_55 ,
F_65 ( V_2 -> V_147 ) , 0 ) ;
if ( V_46 )
F_7 ( L_153 ) ;
}
F_69 ( V_252 , & V_5 -> V_253 ) ;
if ( V_5 -> V_20 && V_5 -> V_20 < V_25 ) {
F_69 ( V_266 , & V_5 -> V_253 ) ;
V_5 -> V_308 = V_5 -> V_20 ;
}
F_38 ( V_2 ) ;
if ( F_108 ( V_229 , & V_2 -> V_224 ) ) {
F_129 ( V_5 ) ;
V_46 = F_163 ( V_2 ) ;
F_131 ( V_5 ) ;
if ( V_46 )
F_167 ( L_154 ) ;
V_46 = 0 ;
}
return V_46 ;
}
static void F_168 ( struct V_60 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_154 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_70 ( V_309 , & V_2 -> V_224 ) ) {
F_158 ( V_2 ) ;
}
V_5 -> V_250 = 0 ;
V_5 -> V_251 = 0 ;
F_71 ( V_252 , & V_5 -> V_253 ) ;
if ( V_5 -> V_294 )
F_164 ( V_5 ) ;
}
static int T_6 F_169 ( void )
{
F_63 ( L_155 ,
V_310 . V_311 [ 0 ] ,
V_310 . V_311 [ 1 ] ,
V_310 . V_311 [ 2 ] ) ;
return F_170 ( & V_310 ) ;
}
static void T_7 F_171 ( void )
{
F_172 ( & V_310 ) ;
}
