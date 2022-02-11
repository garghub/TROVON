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
return V_2 -> V_6 . V_20 < V_2 -> V_6 . V_21 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_22 != V_23 ;
}
static bool F_17 ( struct V_24 * V_25 )
{
return ! V_25 -> V_19 ;
}
static bool F_18 ( struct V_24 * V_25 )
{
return V_25 -> V_19 == 1 ;
}
static bool F_19 ( struct V_24 * V_25 )
{
return V_25 -> V_19 == 10 ;
}
static bool F_20 ( struct V_24 * V_25 )
{
return F_3 ( V_25 -> V_19 , 4 , 5 ) ;
}
static bool F_21 ( struct V_24 * V_25 )
{
return V_25 -> V_19 == 6 ;
}
static bool F_22 ( struct V_24 * V_25 )
{
return F_3 ( V_25 -> V_19 , 4 , 6 ) ;
}
static unsigned long F_23 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 -> V_24 ) )
return V_26 ;
else if ( F_18 ( V_2 -> V_24 ) )
return V_27 ;
else if ( F_19 ( V_2 -> V_24 ) )
return V_28 ;
else if ( F_20 ( V_2 -> V_24 ) )
return V_29 ;
else if ( F_21 ( V_2 -> V_24 ) )
return V_30 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 & ~ F_23 ( V_2 ) ) {
V_2 -> V_32 -> error = L_2 ;
return - V_33 ;
}
return 0 ;
}
static unsigned int F_25 ( int V_34 )
{
return V_34 & 0xFF ;
}
static unsigned int F_26 ( int V_34 )
{
return F_25 ( V_34 >> V_35 ) ;
}
static bool F_27 ( int V_34 )
{
return ! ! ( V_34 & V_36 ) ;
}
static bool F_28 ( int V_34 )
{
return ! F_27 ( V_34 ) && F_25 ( V_34 ) > 1 ;
}
static bool F_14 ( int V_34 )
{
return ! F_27 ( V_34 ) && F_26 ( V_34 ) > 1 ;
}
static const char * F_29 ( int V_34 )
{
if ( F_27 ( V_34 ) )
return L_3 ;
if ( F_25 ( V_34 ) > 1 )
return L_4 ;
F_30 ( F_26 ( V_34 ) < 2 ) ;
return L_5 ;
}
static int F_31 ( const char * V_17 )
{
if ( ! strcasecmp ( V_17 , L_4 ) )
return V_37 ;
else if ( ! strcasecmp ( V_17 , L_3 ) )
return V_38 ;
else if ( ! strcasecmp ( V_17 , L_5 ) )
return V_39 ;
return - V_33 ;
}
static unsigned int F_32 ( int V_34 )
{
return V_12 ( F_25 ( V_34 ) , F_26 ( V_34 ) ) ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned int V_40 ,
unsigned int V_41 )
{
unsigned int V_42 = 1 , V_43 = 1 , V_44 = 0 ;
if ( V_40 == V_45 ||
V_40 == V_37 )
V_42 = V_41 ;
else if ( V_40 == V_38 ) {
V_43 = V_41 ;
V_44 = V_36 ;
if ( ! F_34 ( V_46 , & V_2 -> V_31 ) )
V_44 |= V_47 ;
} else if ( V_40 == V_39 ) {
V_43 = V_41 ;
V_44 = ! V_36 ;
if ( ! F_34 ( V_46 , & V_2 -> V_31 ) )
V_44 |= V_47 ;
} else
return - V_33 ;
return V_44 | ( V_43 << V_35 ) | V_42 ;
}
static bool F_35 ( struct V_24 * V_48 , const int V_34 )
{
if ( V_48 -> V_19 == 10 ) {
switch ( V_48 -> V_40 ) {
case V_45 :
case V_37 :
return F_28 ( V_34 ) ;
case V_38 :
return F_27 ( V_34 ) ;
case V_39 :
return F_14 ( V_34 ) ;
default:
break;
}
}
return false ;
}
static struct V_24 * F_36 ( const char * V_17 )
{
struct V_24 * V_48 = V_49 + F_6 ( V_49 ) ;
while ( V_48 -- > V_49 )
if ( ! strcasecmp ( V_48 -> V_17 , V_17 ) )
return V_48 ;
return NULL ;
}
static struct V_24 * F_37 ( const int V_19 , const int V_34 )
{
struct V_24 * V_48 = V_49 + F_6 ( V_49 ) ;
while ( V_48 -- > V_49 ) {
if ( V_48 -> V_19 == V_19 &&
( F_35 ( V_48 , V_34 ) || V_48 -> V_40 == V_34 ) )
return V_48 ;
}
return NULL ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_50 * V_51 ;
struct V_52 * V_52 = F_39 ( F_40 ( V_2 -> V_32 -> V_53 ) ) ;
F_41 (rdev, mddev)
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) )
V_51 -> V_56 = V_5 -> V_21 ;
F_42 ( V_52 , V_5 -> V_57 ) ;
F_43 ( V_52 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_7 = V_5 -> V_19 ;
V_5 -> V_8 = V_5 -> V_34 ;
V_5 -> V_9 = V_5 -> V_58 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_19 = V_5 -> V_7 ;
V_5 -> V_34 = V_5 -> V_8 ;
V_5 -> V_58 = V_5 -> V_9 ;
V_5 -> V_59 = V_2 -> V_59 ;
V_5 -> V_60 = 0 ;
}
static struct V_1 * F_46 ( struct V_61 * V_32 , struct V_24 * V_24 ,
unsigned int V_62 )
{
unsigned int V_63 ;
struct V_1 * V_2 ;
if ( V_62 <= V_24 -> V_64 ) {
V_32 -> error = L_6 ;
return F_47 ( - V_33 ) ;
}
V_2 = F_48 ( sizeof( * V_2 ) + V_62 * sizeof( V_2 -> V_65 [ 0 ] ) , V_66 ) ;
if ( ! V_2 ) {
V_32 -> error = L_7 ;
return F_47 ( - V_67 ) ;
}
F_49 ( & V_2 -> V_6 ) ;
V_2 -> V_59 = V_62 ;
V_2 -> V_60 = 0 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_68 = 256 ;
V_2 -> V_6 . V_59 = V_62 ;
V_2 -> V_6 . V_19 = V_24 -> V_19 ;
V_2 -> V_6 . V_7 = V_2 -> V_6 . V_19 ;
V_2 -> V_6 . V_34 = V_24 -> V_40 ;
V_2 -> V_6 . V_8 = V_2 -> V_6 . V_34 ;
V_2 -> V_6 . V_60 = 0 ;
V_2 -> V_6 . V_20 = V_23 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
F_50 ( & V_2 -> V_65 [ V_63 ] . V_51 ) ;
return V_2 ;
}
static void F_51 ( struct V_1 * V_2 )
{
int V_63 ;
if ( V_2 -> V_69 . V_65 ) {
F_52 ( & V_2 -> V_69 . V_51 ) ;
F_53 ( V_2 -> V_32 , V_2 -> V_69 . V_65 ) ;
}
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ ) {
if ( V_2 -> V_65 [ V_63 ] . V_70 )
F_53 ( V_2 -> V_32 , V_2 -> V_65 [ V_63 ] . V_70 ) ;
F_52 ( & V_2 -> V_65 [ V_63 ] . V_51 ) ;
if ( V_2 -> V_65 [ V_63 ] . V_71 )
F_53 ( V_2 -> V_32 , V_2 -> V_65 [ V_63 ] . V_71 ) ;
}
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
int V_63 ;
int V_74 = 0 ;
int V_75 = 0 ;
int V_44 = 0 ;
const char * V_76 ;
V_76 = F_56 ( V_73 ) ;
if ( ! V_76 )
return - V_33 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ ) {
V_2 -> V_65 [ V_63 ] . V_51 . V_77 = V_63 ;
V_2 -> V_65 [ V_63 ] . V_70 = NULL ;
V_2 -> V_65 [ V_63 ] . V_71 = NULL ;
V_2 -> V_65 [ V_63 ] . V_51 . V_78 = 0 ;
V_2 -> V_65 [ V_63 ] . V_51 . V_79 = 0 ;
V_2 -> V_65 [ V_63 ] . V_51 . V_5 = & V_2 -> V_6 ;
V_76 = F_56 ( V_73 ) ;
if ( ! V_76 )
return - V_33 ;
if ( strcmp ( V_76 , L_8 ) ) {
V_44 = F_57 ( V_2 -> V_32 , V_76 , F_58 ( V_2 -> V_32 -> V_53 ) ,
& V_2 -> V_65 [ V_63 ] . V_70 ) ;
if ( V_44 ) {
V_2 -> V_32 -> error = L_9 ;
return V_44 ;
}
V_2 -> V_65 [ V_63 ] . V_51 . V_80 = F_59 ( V_66 ) ;
if ( ! V_2 -> V_65 [ V_63 ] . V_51 . V_80 ) {
V_2 -> V_32 -> error = L_10 ;
return - V_67 ;
}
}
V_76 = F_56 ( V_73 ) ;
if ( ! V_76 )
return - V_33 ;
if ( ! strcmp ( V_76 , L_8 ) ) {
if ( ! F_34 ( V_81 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) &&
( ! V_2 -> V_65 [ V_63 ] . V_51 . V_82 ) ) {
V_2 -> V_32 -> error = L_11 ;
return - V_33 ;
}
if ( V_2 -> V_65 [ V_63 ] . V_70 ) {
V_2 -> V_32 -> error = L_12 ;
return - V_33 ;
}
continue;
}
V_44 = F_57 ( V_2 -> V_32 , V_76 , F_58 ( V_2 -> V_32 -> V_53 ) ,
& V_2 -> V_65 [ V_63 ] . V_71 ) ;
if ( V_44 ) {
V_2 -> V_32 -> error = L_13 ;
return V_44 ;
}
if ( V_2 -> V_65 [ V_63 ] . V_70 ) {
V_75 = 1 ;
V_2 -> V_65 [ V_63 ] . V_51 . V_83 = V_2 -> V_65 [ V_63 ] . V_70 -> V_84 ;
}
V_2 -> V_65 [ V_63 ] . V_51 . V_84 = V_2 -> V_65 [ V_63 ] . V_71 -> V_84 ;
F_60 ( & V_2 -> V_65 [ V_63 ] . V_51 . V_85 , & V_2 -> V_6 . V_86 ) ;
if ( ! F_34 ( V_81 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) )
V_74 ++ ;
}
if ( V_2 -> V_69 . V_65 )
F_60 ( & V_2 -> V_69 . V_51 . V_85 , & V_2 -> V_6 . V_86 ) ;
if ( V_75 ) {
V_2 -> V_6 . V_87 = 0 ;
V_2 -> V_6 . V_88 = 1 ;
V_2 -> V_6 . V_89 = 2 ;
} else if ( V_74 && ! V_2 -> V_6 . V_20 ) {
V_2 -> V_32 -> error = L_14 ;
return - V_33 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned long V_90 )
{
unsigned long V_91 = V_2 -> V_32 -> V_92 / ( 1 << 21 ) ;
if ( F_8 ( V_2 ) )
return 0 ;
if ( ! V_90 ) {
if ( V_91 > ( 1 << 13 ) ) {
V_90 = F_62 ( V_91 ) ;
F_63 ( L_15 ,
V_90 ) ;
} else {
F_63 ( L_16 ) ;
V_90 = 1 << 13 ;
}
} else {
if ( V_90 > V_2 -> V_32 -> V_92 ) {
V_2 -> V_32 -> error = L_17 ;
return - V_33 ;
}
if ( V_90 < V_91 ) {
F_7 ( L_18 ,
V_90 , V_91 ) ;
V_2 -> V_32 -> error = L_19 ;
return - V_33 ;
}
if ( ! F_64 ( V_90 ) ) {
V_2 -> V_32 -> error = L_20 ;
return - V_33 ;
}
if ( V_90 < V_2 -> V_6 . V_58 ) {
V_2 -> V_32 -> error = L_21 ;
return - V_33 ;
}
}
V_2 -> V_6 . V_93 . V_94 = F_65 ( V_90 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
unsigned int V_63 , V_95 = 0 ;
unsigned int V_96 = 0 , V_41 ;
unsigned int V_97 , V_98 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_6 . V_59 ; V_63 ++ )
if ( ! F_34 ( V_81 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) ||
! V_2 -> V_65 [ V_63 ] . V_51 . V_80 )
V_95 ++ ;
switch ( V_2 -> V_24 -> V_19 ) {
case 0 :
break;
case 1 :
if ( V_95 >= V_2 -> V_6 . V_59 )
goto V_99;
break;
case 4 :
case 5 :
case 6 :
if ( V_95 > V_2 -> V_24 -> V_64 )
goto V_99;
break;
case 10 :
V_41 = F_32 ( V_2 -> V_6 . V_8 ) ;
if ( V_95 < V_41 )
break;
if ( F_28 ( V_2 -> V_6 . V_8 ) ) {
for ( V_63 = 0 ; V_63 < V_2 -> V_6 . V_59 ; V_63 ++ ) {
if ( ! ( V_63 % V_41 ) )
V_96 = 0 ;
if ( ( ! V_2 -> V_65 [ V_63 ] . V_51 . V_80 ||
! F_34 ( V_81 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) ) &&
( ++ V_96 >= V_41 ) )
goto V_99;
}
break;
}
V_97 = ( V_2 -> V_6 . V_59 / V_41 ) ;
V_98 = ( V_2 -> V_6 . V_59 / V_97 ) - 1 ;
V_98 *= V_97 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_6 . V_59 ; V_63 ++ ) {
if ( ! ( V_63 % V_41 ) && ! ( V_63 > V_98 ) )
V_96 = 0 ;
if ( ( ! V_2 -> V_65 [ V_63 ] . V_51 . V_80 ||
! F_34 ( V_81 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) ) &&
( ++ V_96 >= V_41 ) )
goto V_99;
}
break;
default:
if ( V_95 )
return - V_33 ;
}
return 0 ;
V_99:
return - V_33 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_72 * V_73 ,
unsigned int V_100 )
{
int V_101 , V_102 = V_45 ;
unsigned int V_103 = 2 ;
unsigned int V_63 , V_104 = 0 ;
unsigned int V_90 = 0 ;
T_2 V_105 ;
const char * V_76 , * V_106 ;
struct V_107 * V_108 ;
struct V_24 * V_25 = V_2 -> V_24 ;
V_76 = F_56 ( V_73 ) ;
V_100 -- ;
if ( F_68 ( V_76 , 10 , & V_101 ) < 0 ) {
V_2 -> V_32 -> error = L_22 ;
return - V_33 ;
}
if ( F_18 ( V_25 ) ) {
if ( V_101 )
F_7 ( L_23 ) ;
V_101 = 0 ;
} else if ( ! F_64 ( V_101 ) ) {
V_2 -> V_32 -> error = L_24 ;
return - V_33 ;
} else if ( V_101 < 8 ) {
V_2 -> V_32 -> error = L_25 ;
return - V_33 ;
}
V_2 -> V_6 . V_9 = V_2 -> V_6 . V_58 = V_101 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ ) {
F_69 ( V_81 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) ;
V_2 -> V_65 [ V_63 ] . V_51 . V_82 = V_23 ;
}
for ( V_63 = 0 ; V_63 < V_100 ; V_63 ++ ) {
V_106 = F_56 ( V_73 ) ;
if ( ! V_106 ) {
V_2 -> V_32 -> error = L_26 ;
return - V_33 ;
}
if ( ! strcasecmp ( V_106 , F_4 ( V_109 ) ) ) {
if ( F_70 ( V_110 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_27 ;
return - V_33 ;
}
continue;
}
if ( ! strcasecmp ( V_106 , F_4 ( V_111 ) ) ) {
if ( F_70 ( V_112 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_28 ;
return - V_33 ;
}
continue;
}
if ( ! strcasecmp ( V_106 , F_4 ( V_113 ) ) ) {
if ( F_70 ( V_46 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_29 ;
return - V_33 ;
}
continue;
}
V_76 = F_56 ( V_73 ) ;
V_63 ++ ;
if ( ! V_76 ) {
V_2 -> V_32 -> error = L_30 ;
return - V_33 ;
}
if ( ! strcasecmp ( V_106 , F_4 ( V_114 ) ) ) {
if ( F_70 ( V_115 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_31 ;
return - V_33 ;
}
if ( ! F_19 ( V_25 ) ) {
V_2 -> V_32 -> error = L_32 ;
return - V_33 ;
}
V_102 = F_31 ( V_76 ) ;
if ( V_102 < 0 ) {
V_2 -> V_32 -> error = L_33 ;
return V_102 ;
}
continue;
}
if ( ! strcasecmp ( V_106 , F_4 ( V_116 ) ) ) {
int V_44 ;
struct V_50 * V_117 ;
if ( F_70 ( V_118 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_34 ;
return - V_33 ;
}
if ( ! F_22 ( V_25 ) ) {
V_2 -> V_32 -> error = L_35 ;
return - V_33 ;
}
V_44 = F_57 ( V_2 -> V_32 , V_76 , F_58 ( V_2 -> V_32 -> V_53 ) ,
& V_2 -> V_69 . V_65 ) ;
if ( V_44 ) {
V_2 -> V_32 -> error = L_36 ;
return V_44 ;
}
V_117 = & V_2 -> V_69 . V_51 ;
F_50 ( V_117 ) ;
V_117 -> V_5 = & V_2 -> V_6 ;
V_117 -> V_84 = V_2 -> V_69 . V_65 -> V_84 ;
V_117 -> V_56 = F_71 ( F_72 ( V_117 -> V_84 -> V_119 ) ) ;
if ( V_117 -> V_56 < V_120 ) {
V_2 -> V_32 -> error = L_37 ;
return - V_121 ;
}
F_69 ( V_54 , & V_117 -> V_55 ) ;
continue;
}
if ( F_68 ( V_76 , 10 , & V_101 ) < 0 ) {
V_2 -> V_32 -> error = L_38 ;
return - V_33 ;
}
if ( ! strcasecmp ( V_106 , F_4 ( V_122 ) ) ) {
if ( ! F_3 ( V_101 , 0 , V_2 -> V_59 - 1 ) ) {
V_2 -> V_32 -> error = L_39 ;
return - V_33 ;
}
if ( F_70 ( V_101 , ( void * ) V_2 -> V_123 ) ) {
V_2 -> V_32 -> error = L_40 ;
return - V_33 ;
}
V_108 = V_2 -> V_65 + V_101 ;
F_73 ( V_81 , & V_108 -> V_51 . V_55 ) ;
F_73 ( V_124 , & V_108 -> V_51 . V_55 ) ;
V_108 -> V_51 . V_82 = 0 ;
F_69 ( V_125 , & V_2 -> V_31 ) ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_126 ) ) ) {
if ( ! F_18 ( V_25 ) ) {
V_2 -> V_32 -> error = L_41 ;
return - V_33 ;
}
if ( ! F_3 ( V_101 , 0 , V_2 -> V_6 . V_59 - 1 ) ) {
V_2 -> V_32 -> error = L_42 ;
return - V_33 ;
}
V_104 ++ ;
F_69 ( V_127 , & V_2 -> V_65 [ V_101 ] . V_51 . V_55 ) ;
F_69 ( V_128 , & V_2 -> V_31 ) ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_129 ) ) ) {
if ( ! F_18 ( V_25 ) ) {
V_2 -> V_32 -> error = L_43 ;
return - V_33 ;
}
if ( F_70 ( V_130 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_44 ;
return - V_33 ;
}
V_101 /= 2 ;
if ( V_101 > V_131 ) {
V_2 -> V_32 -> error = L_45 ;
return - V_33 ;
}
V_2 -> V_6 . V_93 . V_132 = V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_133 ) ) ) {
if ( F_70 ( V_134 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_46 ;
return - V_33 ;
}
if ( ! V_101 || ( V_101 > V_135 ) ) {
V_2 -> V_32 -> error = L_47 ;
return - V_33 ;
}
V_2 -> V_6 . V_93 . V_136 = V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_137 ) ) ) {
if ( F_70 ( V_138 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_48 ;
return - V_33 ;
}
if ( V_101 < 0 ||
( V_101 && ( V_101 < V_139 || V_101 % F_71 ( V_140 ) ) ) ) {
V_2 -> V_32 -> error = L_49 ;
return - V_33 ;
}
V_2 -> V_78 = V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_141 ) ) ) {
if ( F_70 ( V_142 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_50 ;
return - V_33 ;
}
if ( ! F_3 ( abs ( V_101 ) , 1 , V_143 - V_25 -> V_144 ) ) {
V_2 -> V_32 -> error = L_51 ;
return - V_33 ;
}
V_2 -> V_60 = V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_145 ) ) ) {
if ( F_70 ( V_146 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_52 ;
return - V_33 ;
}
if ( ! F_22 ( V_25 ) ) {
V_2 -> V_32 -> error = L_53 ;
return - V_33 ;
}
V_2 -> V_68 = V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_147 ) ) ) {
if ( F_70 ( V_148 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_54 ;
return - V_33 ;
}
if ( V_101 > V_149 ) {
V_2 -> V_32 -> error = L_55 ;
return - V_33 ;
}
V_2 -> V_6 . V_150 = ( int ) V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_151 ) ) ) {
if ( F_70 ( V_152 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_56 ;
return - V_33 ;
}
if ( V_101 > V_149 ) {
V_2 -> V_32 -> error = L_57 ;
return - V_33 ;
}
V_2 -> V_6 . V_153 = ( int ) V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_154 ) ) ) {
if ( F_70 ( V_155 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_58 ;
return - V_33 ;
}
V_90 = V_101 ;
V_2 -> V_156 = V_101 ;
} else if ( ! strcasecmp ( V_106 , F_4 ( V_157 ) ) ) {
if ( F_70 ( V_158 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_59 ;
return - V_33 ;
}
if ( ! F_3 ( V_101 , 2 , V_2 -> V_6 . V_59 ) ) {
V_2 -> V_32 -> error = L_60 ;
return - V_33 ;
}
V_103 = V_101 ;
} else {
F_7 ( L_61 , V_106 ) ;
V_2 -> V_32 -> error = L_62 ;
return - V_33 ;
}
}
if ( F_34 ( V_112 , & V_2 -> V_31 ) &&
F_34 ( V_110 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_63 ;
return - V_33 ;
}
if ( F_34 ( V_125 , & V_2 -> V_31 ) &&
( F_34 ( V_112 , & V_2 -> V_31 ) ||
F_34 ( V_110 , & V_2 -> V_31 ) ) ) {
V_2 -> V_32 -> error = L_64 ;
return - V_33 ;
}
if ( V_104 >= V_2 -> V_6 . V_59 ) {
V_2 -> V_32 -> error = L_65 ;
return - V_33 ;
}
if ( F_61 ( V_2 , V_90 ) )
return - V_33 ;
if ( V_2 -> V_6 . V_58 )
V_105 = V_2 -> V_6 . V_58 ;
else
V_105 = V_90 ;
if ( F_74 ( V_2 -> V_32 , V_105 ) )
return - V_33 ;
if ( F_19 ( V_25 ) ) {
if ( V_103 > V_2 -> V_6 . V_59 ) {
V_2 -> V_32 -> error = L_66 ;
return - V_33 ;
}
V_2 -> V_6 . V_8 = F_33 ( V_2 , V_102 , V_103 ) ;
if ( V_2 -> V_6 . V_8 < 0 ) {
V_2 -> V_32 -> error = L_67 ;
return V_2 -> V_6 . V_8 ;
}
V_25 = F_37 ( 10 , V_2 -> V_6 . V_8 ) ;
if ( ! V_25 ) {
V_2 -> V_32 -> error = L_68 ;
return - V_33 ;
}
if ( ( V_25 -> V_40 == V_45 ||
V_25 -> V_40 == V_37 ) &&
F_34 ( V_46 , & V_2 -> V_31 ) ) {
V_2 -> V_32 -> error = L_69 ;
return - V_33 ;
}
}
V_2 -> V_103 = V_103 ;
V_2 -> V_6 . V_88 = 0 ;
V_2 -> V_6 . V_87 = 1 ;
return F_24 ( V_2 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_44 ;
struct V_159 * V_160 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
T_1 V_161 = V_12 ( V_5 -> V_58 , V_5 -> V_9 ) / 2 ;
T_1 V_162 = V_2 -> V_68 ;
if ( ! F_22 ( V_2 -> V_24 ) ) {
V_2 -> V_32 -> error = L_70 ;
return - V_33 ;
}
if ( V_162 < V_161 ) {
F_63 ( L_71 ,
V_162 , V_161 ) ;
V_162 = V_161 ;
}
V_160 = V_5 -> V_163 ;
if ( ! V_160 ) {
V_2 -> V_32 -> error = L_72 ;
return - V_33 ;
}
if ( V_160 -> V_164 != V_162 ) {
V_44 = F_76 ( V_5 , V_162 ) ;
if ( V_44 ) {
V_2 -> V_32 -> error = L_73 ;
return V_44 ;
}
F_63 ( L_74 , V_162 ) ;
}
return 0 ;
}
static unsigned int F_77 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_59 - V_2 -> V_24 -> V_64 ;
}
static unsigned int F_78 ( struct V_1 * V_2 )
{
return V_2 -> V_59 - V_2 -> V_24 -> V_64 ;
}
static T_2 F_79 ( struct V_1 * V_2 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_2 -> V_6 . V_59 ; V_63 ++ ) {
struct V_50 * V_51 = & V_2 -> V_65 [ V_63 ] . V_51 ;
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) &&
V_51 -> V_84 && V_51 -> V_56 )
return V_51 -> V_56 ;
}
F_80 () ;
}
static int F_81 ( struct V_1 * V_2 , bool V_165 )
{
int V_60 ;
unsigned int V_166 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_50 * V_51 ;
T_2 V_57 = V_2 -> V_32 -> V_92 , V_21 = V_2 -> V_32 -> V_92 ;
if ( V_165 ) {
V_60 = V_5 -> V_60 ;
V_166 = F_77 ( V_2 ) ;
} else {
V_60 = V_2 -> V_60 ;
V_166 = F_78 ( V_2 ) ;
}
if ( F_18 ( V_2 -> V_24 ) )
;
else if ( F_19 ( V_2 -> V_24 ) ) {
if ( V_2 -> V_103 < 2 ||
V_60 < 0 ) {
V_2 -> V_32 -> error = L_75 ;
return - V_33 ;
}
V_21 *= V_2 -> V_103 ;
if ( F_82 ( V_21 , V_166 ) )
goto V_167;
V_57 = ( V_166 + V_60 ) * V_21 ;
if ( F_82 ( V_57 , V_2 -> V_103 ) )
goto V_167;
} else if ( F_82 ( V_21 , V_166 ) )
goto V_167;
else
V_57 = ( V_166 + V_60 ) * V_21 ;
F_41 (rdev, mddev)
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) )
V_51 -> V_56 = V_21 ;
V_5 -> V_57 = V_57 ;
V_5 -> V_21 = V_21 ;
return 0 ;
V_167:
V_2 -> V_32 -> error = L_76 ;
return - V_33 ;
}
static void F_83 ( struct V_1 * V_2 , T_2 V_21 )
{
if ( F_8 ( V_2 ) )
V_2 -> V_6 . V_20 = V_23 ;
else if ( F_11 ( V_2 ) )
V_2 -> V_6 . V_20 = V_21 ;
else
V_2 -> V_6 . V_20 = F_34 ( V_110 , & V_2 -> V_31 )
? V_23 : V_21 ;
}
static void F_84 ( struct V_1 * V_2 , T_2 V_21 )
{
if ( ! V_21 )
F_83 ( V_2 , 0 ) ;
else if ( V_21 == V_23 )
F_83 ( V_2 , V_23 ) ;
else if ( F_79 ( V_2 ) < V_21 )
F_83 ( V_2 , F_79 ( V_2 ) ) ;
else
F_83 ( V_2 , V_23 ) ;
}
static void F_85 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = F_86 ( V_169 , struct V_1 , V_6 . V_170 ) ;
F_87 () ;
if ( ! F_16 ( V_2 ) )
F_38 ( V_2 ) ;
F_88 ( V_2 -> V_32 -> V_53 ) ;
}
static int F_89 ( struct V_171 * V_172 , int V_173 )
{
struct V_1 * V_2 = F_86 ( V_172 , struct V_1 , V_174 ) ;
return F_90 ( & V_2 -> V_6 , V_173 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
unsigned int V_175 ;
if ( V_2 -> V_6 . V_176 ) {
V_2 -> V_32 -> error = L_77 ;
return - V_177 ;
}
if ( F_16 ( V_2 ) ) {
V_2 -> V_32 -> error = L_78 ;
return - V_177 ;
}
switch ( V_5 -> V_19 ) {
case 0 :
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 5 ) &&
V_5 -> V_59 == 1 )
return 0 ;
if ( V_5 -> V_7 == 10 &&
! ( V_2 -> V_59 % V_5 -> V_59 ) )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 4 , 6 ) &&
V_5 -> V_8 == V_178 &&
V_5 -> V_59 > 1 )
return 0 ;
break;
case 10 :
if ( F_27 ( V_5 -> V_34 ) )
break;
V_175 = F_25 ( V_5 -> V_34 ) ;
if ( V_5 -> V_7 == 0 ) {
if ( V_175 > 1 &&
! ( V_5 -> V_59 % V_175 ) ) {
V_5 -> V_59 /= V_175 ;
V_5 -> V_60 = V_5 -> V_59 ;
return 0 ;
}
if ( V_175 == 1 &&
F_26 ( V_5 -> V_34 ) > 1 )
return 0 ;
break;
}
if ( V_5 -> V_7 == 1 &&
V_12 ( V_175 , F_26 ( V_5 -> V_34 ) ) == V_5 -> V_59 )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 4 , 5 ) &&
V_5 -> V_59 == 2 )
return 0 ;
break;
case 1 :
if ( F_3 ( V_5 -> V_7 , 4 , 5 ) &&
V_5 -> V_59 == 2 ) {
V_5 -> V_176 = 1 ;
return 0 ;
}
if ( V_5 -> V_7 == 0 &&
V_5 -> V_59 == 1 )
return 0 ;
if ( V_5 -> V_7 == 10 )
return 0 ;
break;
case 4 :
if ( V_5 -> V_7 == 0 )
return 0 ;
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 5 ) &&
V_5 -> V_59 == 2 )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 5 , 6 ) &&
V_5 -> V_34 == V_178 )
return 0 ;
break;
case 5 :
if ( V_5 -> V_7 == 0 &&
V_5 -> V_34 == V_178 )
return 0 ;
if ( V_5 -> V_7 == 4 &&
V_5 -> V_34 == V_178 )
return 0 ;
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 4 || V_5 -> V_7 == 10 ) &&
V_5 -> V_59 == 2 )
return 0 ;
if ( V_5 -> V_7 == 6 &&
( ( V_5 -> V_34 == V_178 && V_5 -> V_8 == V_178 ) ||
F_3 ( V_5 -> V_8 , V_179 , V_180 ) ) )
return 0 ;
break;
case 6 :
if ( V_5 -> V_7 == 0 &&
V_5 -> V_34 == V_178 )
return 0 ;
if ( V_5 -> V_7 == 4 &&
V_5 -> V_34 == V_178 )
return 0 ;
if ( V_5 -> V_7 == 5 &&
( ( V_5 -> V_34 == V_178 && V_5 -> V_8 == V_178 ) ||
F_3 ( V_5 -> V_8 , V_181 , V_182 ) ) )
return 0 ;
default:
break;
}
V_2 -> V_32 -> error = L_79 ;
return - V_33 ;
}
static bool F_92 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_7 != V_2 -> V_6 . V_19 ;
}
static bool F_93 ( struct V_1 * V_2 )
{
bool V_183 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_92 ( V_2 ) )
return false ;
if ( ! V_5 -> V_19 )
return false ;
V_183 = V_5 -> V_8 != V_5 -> V_34 ||
V_5 -> V_9 != V_5 -> V_58 ||
V_2 -> V_60 ;
if ( V_5 -> V_19 == 1 ) {
if ( V_2 -> V_60 )
return ! ! V_2 -> V_60 ;
return ! V_183 &&
V_5 -> V_59 != V_2 -> V_59 ;
}
if ( V_5 -> V_19 == 10 )
return V_183 &&
! F_14 ( V_5 -> V_8 ) &&
V_2 -> V_60 >= 0 ;
return V_183 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_184 || ! V_5 -> V_184 -> V_185 )
V_2 -> V_32 -> error = L_80 ;
else if ( V_5 -> V_176 )
V_2 -> V_32 -> error = L_81 ;
else if ( F_15 ( V_2 ) )
V_2 -> V_32 -> error = L_82 ;
else if ( F_16 ( V_2 ) )
V_2 -> V_32 -> error = L_83 ;
else if ( ! ( F_9 ( V_2 ) || F_10 ( V_2 ) || F_12 ( V_2 ) ) )
V_2 -> V_32 -> error = L_84 ;
else
return 0 ;
return - V_177 ;
}
static int F_95 ( struct V_50 * V_51 , int V_186 , bool V_187 )
{
F_96 ( ! V_51 -> V_80 ) ;
if ( V_51 -> V_188 && ! V_187 )
return 0 ;
V_51 -> V_188 = 0 ;
if ( ! F_97 ( V_51 , 0 , V_186 , V_51 -> V_80 , V_189 , 0 , true ) ) {
F_7 ( L_85 ,
V_51 -> V_77 ) ;
F_98 ( V_51 -> V_5 , V_51 ) ;
F_69 ( V_124 , & V_51 -> V_55 ) ;
return - V_190 ;
}
V_51 -> V_188 = 1 ;
return 0 ;
}
static void F_99 ( struct V_191 * V_192 , T_3 * V_193 )
{
V_193 [ 0 ] = F_100 ( V_192 -> V_193 ) ;
memset ( V_193 + 1 , 0 , sizeof( V_192 -> V_194 ) ) ;
if ( F_101 ( V_192 -> V_195 ) & V_196 ) {
int V_63 = F_6 ( V_192 -> V_194 ) ;
while ( V_63 -- )
V_193 [ V_63 + 1 ] = F_100 ( V_192 -> V_194 [ V_63 ] ) ;
}
}
static void F_102 ( struct V_191 * V_192 , T_3 * V_193 )
{
int V_63 = F_6 ( V_192 -> V_194 ) ;
V_192 -> V_193 = F_103 ( V_193 [ 0 ] ) ;
while ( V_63 -- )
V_192 -> V_194 [ V_63 ] = F_103 ( V_193 [ V_63 + 1 ] ) ;
}
static void F_104 ( struct V_5 * V_5 , struct V_50 * V_51 )
{
bool V_197 = false ;
unsigned int V_63 ;
T_3 V_193 [ V_198 ] ;
struct V_191 * V_192 ;
struct V_1 * V_2 = F_86 ( V_5 , struct V_1 , V_6 ) ;
if ( ! V_51 -> V_83 )
return;
F_96 ( ! V_51 -> V_80 ) ;
V_192 = F_105 ( V_51 -> V_80 ) ;
F_99 ( V_192 , V_193 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ )
if ( ! V_2 -> V_65 [ V_63 ] . V_71 || F_34 ( V_124 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) ) {
V_197 = true ;
F_69 ( V_63 , ( void * ) V_193 ) ;
}
if ( V_197 )
F_102 ( V_192 , V_193 ) ;
V_192 -> V_199 = F_106 ( V_200 ) ;
V_192 -> V_195 = F_106 ( V_196 ) ;
V_192 -> V_201 = F_106 ( V_5 -> V_59 ) ;
V_192 -> V_202 = F_106 ( V_51 -> V_77 ) ;
V_192 -> V_203 = F_103 ( V_5 -> V_203 ) ;
V_192 -> V_204 = F_103 ( V_51 -> V_82 ) ;
V_192 -> V_205 = F_103 ( V_5 -> V_20 ) ;
V_192 -> V_19 = F_106 ( V_5 -> V_19 ) ;
V_192 -> V_34 = F_106 ( V_5 -> V_34 ) ;
V_192 -> V_206 = F_106 ( V_5 -> V_58 ) ;
V_192 -> V_7 = F_106 ( V_5 -> V_7 ) ;
V_192 -> V_8 = F_106 ( V_5 -> V_8 ) ;
V_192 -> V_207 = F_106 ( V_5 -> V_9 ) ;
V_192 -> V_60 = F_106 ( V_5 -> V_60 ) ;
F_87 () ;
V_192 -> V_22 = F_103 ( V_5 -> V_22 ) ;
if ( F_100 ( V_192 -> V_22 ) != V_23 ) {
V_192 -> V_55 |= F_106 ( V_208 ) ;
if ( V_5 -> V_60 < 0 || V_5 -> V_209 )
V_192 -> V_55 |= F_106 ( V_210 ) ;
} else {
V_192 -> V_55 &= ~ ( F_106 ( V_208 | V_210 ) ) ;
}
V_192 -> V_57 = F_103 ( V_5 -> V_57 ) ;
V_192 -> V_78 = F_103 ( V_51 -> V_78 ) ;
V_192 -> V_79 = F_103 ( V_51 -> V_79 ) ;
V_192 -> V_56 = F_103 ( V_51 -> V_56 ) ;
V_192 -> V_211 = F_106 ( 0 ) ;
memset ( V_192 + 1 , 0 , V_51 -> V_212 - sizeof( * V_192 ) ) ;
}
static int F_107 ( struct V_50 * V_51 , struct V_50 * V_213 )
{
int V_44 ;
struct V_191 * V_192 ;
struct V_191 * V_214 ;
T_3 V_215 , V_216 ;
V_51 -> V_217 = 0 ;
V_51 -> V_212 = F_108 ( V_51 -> V_83 ) ;
if ( V_51 -> V_212 < sizeof( * V_192 ) || V_51 -> V_212 > V_140 ) {
F_7 ( L_86 ) ;
return - V_33 ;
}
V_44 = F_95 ( V_51 , V_51 -> V_212 , false ) ;
if ( V_44 )
return V_44 ;
V_192 = F_105 ( V_51 -> V_80 ) ;
if ( ( V_192 -> V_199 != F_106 ( V_200 ) ) ||
( ! F_34 ( V_81 , & V_51 -> V_55 ) && ! V_51 -> V_82 ) ) {
F_104 ( V_51 -> V_5 , V_51 ) ;
F_69 ( V_218 , & V_51 -> V_55 ) ;
V_192 -> V_195 = F_106 ( V_196 ) ;
F_69 ( V_219 , & V_51 -> V_5 -> V_220 ) ;
return V_213 ? 0 : 1 ;
}
if ( ! V_213 )
return 1 ;
V_215 = F_100 ( V_192 -> V_203 ) ;
V_214 = F_105 ( V_213 -> V_80 ) ;
V_216 = F_100 ( V_214 -> V_203 ) ;
return ( V_215 > V_216 ) ? 1 : 0 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
int V_221 ;
unsigned int V_222 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
T_3 V_215 ;
T_3 V_193 [ V_198 ] ;
struct V_191 * V_192 ;
T_1 V_223 = 0 , V_224 = 0 , V_225 = 0 ;
struct V_50 * V_44 ;
struct V_191 * V_226 ;
V_192 = F_105 ( V_51 -> V_80 ) ;
V_215 = F_100 ( V_192 -> V_203 ) ;
V_5 -> V_203 = V_215 ? : 1 ;
V_5 -> V_22 = V_23 ;
V_5 -> V_59 = F_101 ( V_192 -> V_201 ) ;
V_5 -> V_19 = F_101 ( V_192 -> V_19 ) ;
V_5 -> V_34 = F_101 ( V_192 -> V_34 ) ;
V_5 -> V_58 = F_101 ( V_192 -> V_206 ) ;
if ( F_101 ( V_192 -> V_195 ) & V_196 ) {
V_5 -> V_7 = F_101 ( V_192 -> V_7 ) ;
V_5 -> V_8 = F_101 ( V_192 -> V_8 ) ;
V_5 -> V_9 = F_101 ( V_192 -> V_207 ) ;
V_5 -> V_60 = F_101 ( V_192 -> V_60 ) ;
V_5 -> V_57 = F_100 ( V_192 -> V_57 ) ;
if ( F_101 ( V_192 -> V_55 ) & V_208 ) {
if ( F_34 ( V_142 , & V_2 -> V_31 ) ) {
F_7 ( L_87 ) ;
return - V_33 ;
}
if ( V_5 -> V_60 < 0 ||
( ! V_5 -> V_60 && ( F_101 ( V_192 -> V_55 ) & V_210 ) ) )
V_5 -> V_209 = 1 ;
else
V_5 -> V_209 = 0 ;
V_5 -> V_22 = F_100 ( V_192 -> V_22 ) ;
V_2 -> V_24 = F_37 ( V_5 -> V_19 , V_5 -> V_34 ) ;
}
} else {
struct V_24 * V_227 = F_37 ( V_5 -> V_19 , V_5 -> V_34 ) ;
struct V_24 * V_228 = F_37 ( V_5 -> V_7 , V_5 -> V_8 ) ;
if ( F_92 ( V_2 ) ) {
if ( V_227 && V_228 )
F_7 ( L_88 ,
V_227 -> V_17 , V_228 -> V_17 ) ;
else
F_7 ( L_89 ) ;
return - V_33 ;
} else if ( F_93 ( V_2 ) ) {
F_7 ( L_90 ) ;
if ( V_5 -> V_34 != V_5 -> V_8 ) {
if ( V_227 && V_228 )
F_7 ( L_91 ,
V_227 -> V_17 , V_228 -> V_17 ) ;
else
F_7 ( L_92 ,
F_101 ( V_192 -> V_34 ) , V_5 -> V_8 ) ;
}
if ( V_5 -> V_58 != V_5 -> V_9 )
F_7 ( L_93 ,
V_5 -> V_58 , V_5 -> V_9 ) ;
if ( V_2 -> V_60 )
F_7 ( L_94 ,
V_5 -> V_59 , V_5 -> V_59 + V_2 -> V_60 ) ;
if ( F_10 ( V_2 ) ) {
F_7 ( L_95 ,
F_29 ( V_5 -> V_34 ) ,
F_32 ( V_5 -> V_34 ) ) ;
F_7 ( L_96 ,
F_29 ( V_5 -> V_8 ) ,
F_32 ( V_5 -> V_8 ) ) ;
}
return - V_33 ;
}
F_63 ( L_97 ) ;
}
if ( ! F_34 ( V_110 , & V_2 -> V_31 ) )
V_5 -> V_20 = F_100 ( V_192 -> V_205 ) ;
V_222 = 0 ;
F_41 (r, mddev) {
if ( F_34 ( V_54 , & V_51 -> V_55 ) )
continue;
if ( F_34 ( V_218 , & V_44 -> V_55 ) )
V_223 ++ ;
if ( ! F_34 ( V_81 , & V_44 -> V_55 ) ) {
F_63 ( L_98 ,
V_44 -> V_77 ) ;
V_225 ++ ;
if ( F_34 ( V_218 , & V_44 -> V_55 ) )
V_224 ++ ;
}
V_222 ++ ;
}
if ( V_223 == V_2 -> V_59 || ! V_225 ) {
if ( V_223 == 1 && ! V_2 -> V_60 )
;
if ( V_223 == V_2 -> V_59 ) {
F_63 ( L_99 ) ;
F_69 ( V_229 , & V_5 -> V_55 ) ;
} else if ( V_223 != V_225 &&
V_223 != V_2 -> V_60 ) {
F_7 ( L_100
L_101 ) ;
return - V_33 ;
}
} else if ( V_223 && V_223 != V_225 ) {
F_7 ( L_102
L_103 ,
V_225 , V_223 ) ;
return - V_33 ;
} else if ( V_225 ) {
if ( V_224 && V_225 != V_224 ) {
F_7 ( L_104 ,
V_223 > 1 ? L_105 : L_106 ) ;
return - V_33 ;
} else if ( F_15 ( V_2 ) ) {
F_7 ( L_107 ,
( unsigned long long ) V_5 -> V_20 ) ;
return - V_33 ;
} else if ( F_16 ( V_2 ) ) {
F_7 ( L_108 ,
( unsigned long long ) V_5 -> V_22 ) ;
return - V_33 ;
}
}
F_99 ( V_192 , V_193 ) ;
F_41 (r, mddev) {
if ( F_34 ( V_54 , & V_51 -> V_55 ) ||
! V_44 -> V_80 )
continue;
V_226 = F_105 ( V_44 -> V_80 ) ;
V_226 -> V_193 = 0 ;
memset ( V_226 -> V_194 , 0 , sizeof( V_226 -> V_194 ) ) ;
if ( ! F_34 ( V_218 , & V_44 -> V_55 ) && ( V_44 -> V_77 >= 0 ) ) {
V_221 = F_101 ( V_226 -> V_202 ) ;
if ( V_221 < 0 )
continue;
if ( V_221 != V_44 -> V_77 ) {
if ( F_10 ( V_2 ) && F_28 ( V_5 -> V_34 ) ) {
if ( V_5 -> V_59 % F_25 ( V_5 -> V_34 ) ||
V_2 -> V_59 % V_2 -> V_103 ) {
V_2 -> V_32 -> error =
L_109 ;
return - V_33 ;
}
V_226 -> V_202 = F_106 ( V_44 -> V_77 ) ;
} else if ( ! ( F_10 ( V_2 ) && F_17 ( V_2 -> V_24 ) ) &&
! ( F_8 ( V_2 ) && F_19 ( V_2 -> V_24 ) ) &&
! F_18 ( V_2 -> V_24 ) ) {
V_2 -> V_32 -> error = L_110 ;
return - V_33 ;
}
F_63 ( L_111 , V_221 , V_44 -> V_77 ) ;
}
if ( F_34 ( V_221 , ( void * ) V_193 ) )
F_69 ( V_124 , & V_44 -> V_55 ) ;
}
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_191 * V_192 ;
if ( F_8 ( V_2 ) || ! V_51 -> V_80 || V_51 -> V_77 < 0 )
return 0 ;
V_192 = F_105 ( V_51 -> V_80 ) ;
if ( ! V_5 -> V_203 && F_109 ( V_2 , V_51 ) )
return - V_33 ;
if ( F_101 ( V_192 -> V_195 ) &&
F_101 ( V_192 -> V_195 ) != V_196 ) {
V_2 -> V_32 -> error = L_112 ;
return - V_33 ;
}
if ( V_192 -> V_211 ) {
V_2 -> V_32 -> error = L_113 ;
return - V_33 ;
}
V_5 -> V_93 . V_230 = F_17 ( V_2 -> V_24 ) ? 0 : F_71 ( 4096 ) ;
V_5 -> V_93 . V_231 = V_5 -> V_93 . V_230 ;
if ( ! F_111 ( V_218 , & V_51 -> V_55 ) ) {
V_51 -> V_56 = F_100 ( V_192 -> V_56 ) ;
V_51 -> V_82 = F_100 ( V_192 -> V_204 ) ;
if ( V_51 -> V_82 == V_23 )
F_69 ( V_81 , & V_51 -> V_55 ) ;
else if ( ! F_16 ( V_2 ) )
F_73 ( V_81 , & V_51 -> V_55 ) ;
}
if ( F_111 ( V_124 , & V_51 -> V_55 ) ) {
V_51 -> V_82 = 0 ;
F_73 ( V_81 , & V_51 -> V_55 ) ;
V_51 -> V_232 = V_51 -> V_77 ;
}
V_51 -> V_78 = F_100 ( V_192 -> V_78 ) ;
V_51 -> V_79 = F_100 ( V_192 -> V_79 ) ;
return 0 ;
}
static int F_112 ( struct V_61 * V_32 , struct V_1 * V_2 )
{
int V_44 ;
struct V_50 * V_51 , * V_233 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
V_233 = NULL ;
F_41 (rdev, mddev) {
if ( F_34 ( V_54 , & V_51 -> V_55 ) )
continue;
if ( F_34 ( V_112 , & V_2 -> V_31 ) )
continue;
if ( ! V_51 -> V_83 )
continue;
V_44 = F_107 ( V_51 , V_233 ) ;
switch ( V_44 ) {
case 1 :
V_233 = V_51 ;
break;
case 0 :
break;
default:
if ( F_8 ( V_2 ) )
continue;
V_51 -> V_77 = V_51 -> V_232 = - 1 ;
break;
}
}
if ( ! V_233 )
return 0 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_32 -> error = L_114 ;
return - V_33 ;
}
V_2 -> V_32 -> error = L_115 ;
if ( F_110 ( V_2 , V_233 ) )
return - V_33 ;
F_41 (rdev, mddev)
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) &&
V_51 != V_233 &&
F_110 ( V_2 , V_51 ) )
return - V_33 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
T_2 V_78 = 0 , V_79 = 0 ;
struct V_50 * V_51 ;
if ( ! F_34 ( V_138 , & V_2 -> V_31 ) ) {
if ( ! F_13 ( V_2 ) )
goto V_234;
return 0 ;
}
V_51 = & V_2 -> V_65 [ 0 ] . V_51 ;
if ( V_2 -> V_60 < 0 ) {
V_78 = 0 ;
V_79 = V_2 -> V_78 ;
} else if ( V_2 -> V_60 > 0 ) {
V_78 = V_2 -> V_78 ;
V_79 = 0 ;
} else {
V_78 = V_2 -> V_78 ? V_51 -> V_78 : 0 ;
V_79 = V_78 ? 0 : V_2 -> V_78 ;
F_69 ( V_235 , & V_2 -> V_236 ) ;
}
if ( V_2 -> V_78 &&
F_71 ( F_72 ( V_51 -> V_84 -> V_119 ) ) - V_51 -> V_56 < V_139 ) {
V_2 -> V_32 -> error = V_78 ? L_116 :
L_117 ;
return - V_121 ;
}
V_234:
F_41 (rdev, &rs->md) {
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) ) {
V_51 -> V_78 = V_78 ;
V_51 -> V_79 = V_79 ;
}
}
return 0 ;
}
static void F_114 ( struct V_1 * V_2 )
{
int V_63 = 0 ;
struct V_50 * V_51 ;
F_41 (rdev, &rs->md) {
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) ) {
V_51 -> V_77 = V_63 ++ ;
V_51 -> V_232 = V_51 -> V_237 = - 1 ;
}
}
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_50 * V_51 ;
unsigned int V_222 = V_5 -> V_59 = V_2 -> V_59 ;
T_2 V_79 = V_2 -> V_65 [ 0 ] . V_51 . V_78 ? 0 : V_2 -> V_78 ;
if ( F_19 ( V_2 -> V_24 ) ) {
if ( V_5 -> V_19 == 0 ) {
F_114 ( V_2 ) ;
V_5 -> V_34 = F_33 ( V_2 , V_39 ,
V_2 -> V_103 ) ;
} else if ( V_5 -> V_19 == 1 )
V_5 -> V_34 = F_33 ( V_2 , V_37 ,
V_2 -> V_59 ) ;
else
return - V_33 ;
}
F_73 ( V_229 , & V_5 -> V_55 ) ;
V_5 -> V_20 = V_23 ;
while ( V_222 -- ) {
V_51 = & V_2 -> V_65 [ V_222 ] . V_51 ;
if ( F_34 ( V_222 , ( void * ) V_2 -> V_123 ) ) {
F_73 ( V_81 , & V_51 -> V_55 ) ;
F_73 ( V_124 , & V_51 -> V_55 ) ;
V_5 -> V_20 = V_51 -> V_82 = 0 ;
F_69 ( V_229 , & V_5 -> V_55 ) ;
}
V_51 -> V_79 = V_79 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
bool V_238 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_10 ( V_2 ) ) {
if ( V_2 -> V_59 != V_5 -> V_59 &&
F_28 ( V_5 -> V_34 ) &&
V_2 -> V_103 &&
V_2 -> V_103 != F_25 ( V_5 -> V_34 ) ) {
if ( V_2 -> V_59 % V_2 -> V_103 ) {
V_2 -> V_32 -> error = L_118 ;
return - V_33 ;
}
F_114 ( V_2 ) ;
V_5 -> V_34 = F_33 ( V_2 , V_37 ,
V_2 -> V_103 ) ;
V_5 -> V_8 = V_5 -> V_34 ;
V_238 = false ;
} else
V_238 = true ;
} else if ( F_12 ( V_2 ) )
V_238 = true ;
else if ( F_9 ( V_2 ) ) {
if ( V_2 -> V_60 ) {
V_5 -> V_176 = V_2 -> V_60 < 0 ? - V_2 -> V_60 : V_2 -> V_60 ;
V_238 = true ;
} else {
V_5 -> V_59 = V_2 -> V_59 ;
V_238 = false ;
}
} else {
V_2 -> V_32 -> error = L_119 ;
return - V_33 ;
}
if ( V_238 ) {
F_69 ( V_239 , & V_2 -> V_236 ) ;
F_69 ( V_235 , & V_2 -> V_236 ) ;
} else if ( V_5 -> V_59 < V_2 -> V_59 )
F_69 ( V_235 , & V_2 -> V_236 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
unsigned int V_240 , V_222 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_50 * V_51 ;
V_5 -> V_60 = V_2 -> V_60 ;
V_240 = V_5 -> V_59 ;
if ( V_5 -> V_60 &&
V_5 -> V_34 != V_5 -> V_8 ) {
F_63 ( L_120 , V_2 -> V_60 ) ;
V_5 -> V_8 = V_5 -> V_34 ;
}
if ( V_2 -> V_60 > 0 ) {
for ( V_222 = V_240 ; V_222 < V_2 -> V_59 ; V_222 ++ ) {
V_51 = & V_2 -> V_65 [ V_222 ] . V_51 ;
F_73 ( V_81 , & V_51 -> V_55 ) ;
V_51 -> V_232 = - 1 ;
V_51 -> V_77 = V_222 ;
V_51 -> V_56 = V_5 -> V_21 ;
V_51 -> V_82 = F_9 ( V_2 ) ? 0 : V_23 ;
}
V_5 -> V_209 = 0 ;
} else if ( V_2 -> V_60 < 0 ) {
V_44 = F_81 ( V_2 , true ) ;
V_5 -> V_209 = 1 ;
} else {
V_5 -> V_209 = V_2 -> V_65 [ 0 ] . V_51 . V_78 ? 0 : 1 ;
}
return V_44 ;
}
static void F_118 ( struct V_1 * V_2 )
{
int V_63 ;
bool V_241 ;
struct V_61 * V_32 = V_2 -> V_32 ;
V_32 -> V_242 = false ;
V_241 = ( V_2 -> V_6 . V_19 == 4 || V_2 -> V_6 . V_19 == 5 || V_2 -> V_6 . V_19 == 6 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ ) {
struct V_243 * V_244 ;
if ( ! V_2 -> V_65 [ V_63 ] . V_51 . V_84 )
continue;
V_244 = F_119 ( V_2 -> V_65 [ V_63 ] . V_51 . V_84 ) ;
if ( ! V_244 || ! F_120 ( V_244 ) )
return;
if ( V_241 ) {
if ( ! V_244 -> V_245 . V_246 )
return;
if ( ! V_247 ) {
F_7 ( L_121 ) ;
F_7 ( L_122 ) ;
return;
}
}
}
V_32 -> V_242 = true ;
V_32 -> V_248 = ! ! ( V_2 -> V_6 . V_19 == 1 || V_2 -> V_6 . V_19 == 10 ) ;
V_32 -> V_249 = 1 ;
}
static int F_121 ( struct V_61 * V_32 , unsigned int V_250 , char * * V_251 )
{
int V_44 ;
bool V_252 ;
struct V_24 * V_25 ;
unsigned int V_100 , V_253 ;
T_2 V_254 ;
struct V_1 * V_2 = NULL ;
const char * V_76 ;
struct V_3 V_3 ;
struct V_72 V_73 = { V_250 , V_251 } , V_255 ;
struct V_256 V_257 [] = {
{ 0 , V_73 . V_250 , L_123 } ,
{ 1 , 254 , L_124 }
} ;
V_76 = F_56 ( & V_73 ) ;
if ( ! V_76 ) {
V_32 -> error = L_125 ;
return - V_33 ;
}
V_25 = F_36 ( V_76 ) ;
if ( ! V_25 ) {
V_32 -> error = L_126 ;
return - V_33 ;
}
if ( F_122 ( V_257 , & V_73 , & V_100 , & V_32 -> error ) )
return - V_33 ;
V_255 = V_73 ;
F_123 ( & V_255 , V_100 ) ;
V_257 [ 1 ] . V_12 = ( V_255 . V_250 - 1 ) / 2 ;
if ( F_124 ( V_257 + 1 , & V_255 , & V_253 , & V_32 -> error ) )
return - V_33 ;
if ( ! F_3 ( V_253 , 1 , V_143 ) ) {
V_32 -> error = L_127 ;
return - V_33 ;
}
V_2 = F_46 ( V_32 , V_25 , V_253 ) ;
if ( F_125 ( V_2 ) )
return F_126 ( V_2 ) ;
V_44 = F_67 ( V_2 , & V_73 , V_100 ) ;
if ( V_44 )
goto V_167;
V_44 = F_55 ( V_2 , & V_73 ) ;
if ( V_44 )
goto V_167;
V_2 -> V_6 . V_258 = F_104 ;
V_44 = F_81 ( V_2 , false ) ;
if ( V_44 )
goto V_167;
V_254 = V_2 -> V_6 . V_21 ;
F_1 ( V_2 , & V_3 ) ;
V_44 = F_112 ( V_32 , V_2 ) ;
if ( V_44 )
goto V_167;
V_252 = V_254 != F_79 ( V_2 ) ;
F_127 ( & V_2 -> V_6 . V_170 , F_85 ) ;
V_32 -> V_163 = V_2 ;
V_32 -> V_259 = 1 ;
F_2 ( V_2 , & V_3 ) ;
if ( F_34 ( V_229 , & V_2 -> V_6 . V_55 ) ) {
if ( F_11 ( V_2 ) &&
F_34 ( V_110 , & V_2 -> V_31 ) ) {
V_32 -> error = L_128 ;
V_44 = - V_33 ;
goto V_167;
}
F_84 ( V_2 , 0 ) ;
F_69 ( V_235 , & V_2 -> V_236 ) ;
F_45 ( V_2 ) ;
} else if ( F_15 ( V_2 ) ) {
;
} else if ( F_16 ( V_2 ) ) {
if ( V_252 ) {
V_32 -> error = L_129 ;
V_44 = - V_177 ;
goto V_167;
}
} else if ( F_92 ( V_2 ) ) {
if ( F_16 ( V_2 ) ) {
V_32 -> error = L_130 ;
V_44 = - V_177 ;
goto V_167;
}
if ( F_34 ( V_118 , & V_2 -> V_31 ) ) {
V_32 -> error = L_131 ;
V_44 = - V_177 ;
goto V_167;
}
V_44 = F_91 ( V_2 ) ;
if ( V_44 )
goto V_167;
V_44 = F_115 ( V_2 ) ;
if ( V_44 )
goto V_167;
F_69 ( V_235 , & V_2 -> V_236 ) ;
F_84 ( V_2 , V_23 ) ;
F_45 ( V_2 ) ;
} else if ( F_93 ( V_2 ) ) {
if ( F_34 ( V_118 , & V_2 -> V_31 ) ) {
V_32 -> error = L_132 ;
V_44 = - V_177 ;
goto V_167;
}
V_44 = F_116 ( V_2 ) ;
if ( V_44 )
return V_44 ;
F_84 ( V_2 , V_23 ) ;
F_44 ( V_2 ) ;
} else {
if ( F_34 ( V_125 , & V_2 -> V_31 ) ) {
F_84 ( V_2 , V_23 ) ;
F_69 ( V_235 , & V_2 -> V_236 ) ;
} else
F_84 ( V_2 , F_34 ( V_112 , & V_2 -> V_31 ) ?
0 : ( V_252 ? V_254 : V_23 ) ) ;
F_44 ( V_2 ) ;
}
V_44 = F_113 ( V_2 ) ;
if ( V_44 )
goto V_167;
V_2 -> V_6 . V_260 = 1 ;
V_2 -> V_6 . V_261 = 1 ;
F_69 ( V_262 , & V_2 -> V_6 . V_263 ) ;
F_128 ( & V_2 -> V_6 ) ;
V_44 = F_129 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_261 = 0 ;
if ( V_44 ) {
V_32 -> error = L_133 ;
F_130 ( & V_2 -> V_6 ) ;
goto V_167;
}
V_2 -> V_174 . V_264 = F_89 ;
F_131 ( V_32 -> V_53 , & V_2 -> V_174 ) ;
F_132 ( & V_2 -> V_6 ) ;
if ( F_12 ( V_2 ) ) {
V_44 = F_75 ( V_2 ) ;
if ( V_44 )
goto V_265;
}
if ( F_34 ( V_239 , & V_2 -> V_236 ) ) {
V_44 = F_94 ( V_2 ) ;
if ( V_44 )
goto V_266;
F_2 ( V_2 , & V_3 ) ;
if ( V_2 -> V_6 . V_184 -> V_267 ) {
V_44 = V_2 -> V_6 . V_184 -> V_185 ( & V_2 -> V_6 ) ;
if ( V_44 ) {
V_32 -> error = L_134 ;
goto V_266;
}
}
}
F_118 ( V_2 ) ;
F_130 ( & V_2 -> V_6 ) ;
return 0 ;
V_265:
V_266:
F_133 ( & V_2 -> V_6 ) ;
V_167:
F_51 ( V_2 ) ;
return V_44 ;
}
static void F_134 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
F_135 ( & V_2 -> V_174 . V_268 ) ;
F_133 ( & V_2 -> V_6 ) ;
F_51 ( V_2 ) ;
}
static int F_136 ( struct V_61 * V_32 , struct V_269 * V_269 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_137 ( F_138 ( V_269 ) > V_5 -> V_57 ) )
return V_270 ;
V_5 -> V_184 -> V_271 ( V_5 , V_269 ) ;
return V_272 ;
}
static const char * F_139 ( struct V_5 * V_5 )
{
if ( F_34 ( V_262 , & V_5 -> V_263 ) )
return L_135 ;
if ( F_34 ( V_273 , & V_5 -> V_263 ) ||
( ! V_5 -> V_260 && F_34 ( V_274 , & V_5 -> V_263 ) ) ) {
if ( F_34 ( V_275 , & V_5 -> V_263 ) )
return L_136 ;
if ( F_34 ( V_276 , & V_5 -> V_263 ) ) {
if ( ! F_34 ( V_277 , & V_5 -> V_263 ) )
return L_137 ;
else if ( F_34 ( V_278 , & V_5 -> V_263 ) )
return L_138 ;
return L_139 ;
}
if ( F_34 ( V_279 , & V_5 -> V_263 ) )
return L_140 ;
}
return L_141 ;
}
static const char * F_140 ( struct V_50 * V_51 , bool V_280 )
{
if ( ! V_51 -> V_84 )
return L_8 ;
else if ( F_34 ( V_124 , & V_51 -> V_55 ) )
return L_142 ;
else if ( F_34 ( V_54 , & V_51 -> V_55 ) )
return L_143 ;
else if ( ! V_280 || ! F_34 ( V_81 , & V_51 -> V_55 ) )
return L_144 ;
else
return L_143 ;
}
static T_2 F_141 ( struct V_1 * V_2 ,
T_2 V_281 , bool * V_280 )
{
T_2 V_44 , V_20 , V_282 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
V_282 = V_5 -> V_282 ? : V_5 -> V_20 ;
V_20 = V_5 -> V_20 ;
* V_280 = false ;
if ( F_8 ( V_2 ) ) {
V_44 = V_281 ;
* V_280 = true ;
} else {
V_44 = V_5 -> V_22 ;
if ( F_34 ( V_275 , & V_5 -> V_263 ) ||
V_44 != V_23 ) {
if ( V_44 == V_23 ) {
* V_280 = true ;
V_44 = V_281 ;
} else {
if ( V_5 -> V_209 )
V_44 = V_5 -> V_57 - V_44 ;
F_82 ( V_44 , F_77 ( V_2 ) ) ;
}
} else if ( F_34 ( V_273 , & V_5 -> V_263 ) )
V_44 = V_282 ;
else
V_44 = V_20 ;
if ( V_44 == V_23 ) {
* V_280 = true ;
V_44 = V_281 ;
} else if ( F_34 ( V_277 , & V_5 -> V_263 ) ) {
* V_280 = true ;
} else {
struct V_50 * V_51 ;
F_41 (rdev, mddev)
if ( ! F_34 ( V_54 , & V_51 -> V_55 ) &&
! F_34 ( V_81 , & V_51 -> V_55 ) )
* V_280 = true ;
#if 0
r = 0;
#endif
}
}
return V_44 ;
}
static const char * F_142 ( struct V_283 * V_65 )
{
return V_65 ? V_65 -> V_17 : L_8 ;
}
static void F_143 ( struct V_61 * V_32 , T_4 type ,
unsigned int V_284 , char * V_285 , unsigned int V_286 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_159 * V_160 = V_5 -> V_163 ;
int V_63 , V_287 = V_160 ? V_160 -> V_287 : 0 ;
bool V_280 ;
unsigned int V_288 = 1 ;
unsigned int V_289 = 0 ;
unsigned int V_123 ;
unsigned int V_290 = 0 ;
T_2 V_291 , V_281 , V_292 ;
const char * V_293 ;
struct V_24 * V_25 ;
switch ( type ) {
case V_294 :
V_25 = F_37 ( V_5 -> V_7 , V_5 -> V_8 ) ;
if ( ! V_25 )
return;
F_144 ( L_145 , V_25 -> V_17 , V_5 -> V_59 ) ;
F_87 () ;
V_281 = F_34 ( V_295 , & V_2 -> V_236 ) ?
V_5 -> V_281 : V_5 -> V_21 ;
V_291 = F_141 ( V_2 , V_281 , & V_280 ) ;
V_292 = ( V_5 -> V_296 && ! strcasecmp ( V_5 -> V_296 , L_138 ) ) ?
F_145 ( & V_5 -> V_292 ) : 0 ;
V_293 = F_139 ( & V_2 -> V_6 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ )
F_144 ( F_140 ( & V_2 -> V_65 [ V_63 ] . V_51 , V_280 ) ) ;
F_144 ( L_146 , ( unsigned long long ) V_291 ,
( unsigned long long ) V_281 ) ;
F_144 ( L_147 , V_293 ) ;
F_144 ( L_148 , ( unsigned long long ) V_292 ) ;
F_144 ( L_148 , ( unsigned long long ) V_2 -> V_65 [ 0 ] . V_51 . V_78 ) ;
F_144 ( L_147 , F_34 ( V_118 , & V_2 -> V_31 ) ?
F_140 ( & V_2 -> V_69 . V_51 , 0 ) : L_8 ) ;
break;
case V_297 :
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ )
if ( F_34 ( V_127 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) )
V_290 += 2 ;
V_123 = F_146 ( V_2 -> V_123 , V_198 * sizeof( * V_2 -> V_123 ) ) ;
V_288 += V_123 * 2 +
V_290 +
F_5 ( V_2 -> V_31 & V_298 ) +
F_5 ( V_2 -> V_31 & V_299 ) * 2 +
( F_34 ( V_118 , & V_2 -> V_31 ) ? 2 : 0 ) ;
F_144 ( L_149 , V_2 -> V_24 -> V_17 , V_288 , V_5 -> V_9 ) ;
if ( F_34 ( V_115 , & V_2 -> V_31 ) )
F_144 ( L_150 , F_4 ( V_114 ) ,
F_29 ( V_5 -> V_34 ) ) ;
if ( F_34 ( V_158 , & V_2 -> V_31 ) )
F_144 ( L_151 , F_4 ( V_157 ) ,
F_32 ( V_5 -> V_34 ) ) ;
if ( F_34 ( V_110 , & V_2 -> V_31 ) )
F_144 ( L_147 , F_4 ( V_109 ) ) ;
if ( F_34 ( V_112 , & V_2 -> V_31 ) )
F_144 ( L_147 , F_4 ( V_111 ) ) ;
if ( F_34 ( V_155 , & V_2 -> V_31 ) )
F_144 ( L_152 , F_4 ( V_154 ) ,
( unsigned long long ) F_71 ( V_5 -> V_93 . V_94 ) ) ;
if ( F_34 ( V_138 , & V_2 -> V_31 ) )
F_144 ( L_152 , F_4 ( V_137 ) ,
( unsigned long long ) V_2 -> V_78 ) ;
if ( F_34 ( V_134 , & V_2 -> V_31 ) )
F_144 ( L_153 , F_4 ( V_133 ) ,
V_5 -> V_93 . V_136 ) ;
if ( F_34 ( V_142 , & V_2 -> V_31 ) )
F_144 ( L_151 , F_4 ( V_141 ) ,
V_12 ( V_2 -> V_60 , V_5 -> V_60 ) ) ;
if ( F_34 ( V_146 , & V_2 -> V_31 ) )
F_144 ( L_151 , F_4 ( V_145 ) ,
V_287 ) ;
if ( V_123 )
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ )
if ( F_34 ( V_2 -> V_65 [ V_63 ] . V_51 . V_77 , ( void * ) V_2 -> V_123 ) )
F_144 ( L_154 , F_4 ( V_122 ) ,
V_2 -> V_65 [ V_63 ] . V_51 . V_77 ) ;
if ( V_290 )
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ )
if ( F_34 ( V_127 , & V_2 -> V_65 [ V_63 ] . V_51 . V_55 ) )
F_144 ( L_151 , F_4 ( V_126 ) ,
V_2 -> V_65 [ V_63 ] . V_51 . V_77 ) ;
if ( F_34 ( V_130 , & V_2 -> V_31 ) )
F_144 ( L_153 , F_4 ( V_129 ) ,
V_5 -> V_93 . V_132 ) ;
if ( F_34 ( V_152 , & V_2 -> V_31 ) )
F_144 ( L_151 , F_4 ( V_151 ) ,
V_5 -> V_153 ) ;
if ( F_34 ( V_148 , & V_2 -> V_31 ) )
F_144 ( L_151 , F_4 ( V_147 ) ,
V_5 -> V_150 ) ;
if ( F_34 ( V_118 , & V_2 -> V_31 ) )
F_144 ( L_150 , F_4 ( V_116 ) ,
F_142 ( V_2 -> V_69 . V_65 ) ) ;
F_144 ( L_155 , V_2 -> V_59 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_59 ; V_63 ++ )
F_144 ( L_150 , F_142 ( V_2 -> V_65 [ V_63 ] . V_70 ) ,
F_142 ( V_2 -> V_65 [ V_63 ] . V_71 ) ) ;
}
}
static int F_147 ( struct V_61 * V_32 , unsigned int V_250 , char * * V_251 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_184 || ! V_5 -> V_184 -> V_300 )
return - V_33 ;
if ( ! strcasecmp ( V_251 [ 0 ] , L_135 ) )
F_69 ( V_262 , & V_5 -> V_263 ) ;
else
F_73 ( V_262 , & V_5 -> V_263 ) ;
if ( ! strcasecmp ( V_251 [ 0 ] , L_141 ) || ! strcasecmp ( V_251 [ 0 ] , L_135 ) ) {
if ( V_5 -> V_301 ) {
F_69 ( V_302 , & V_5 -> V_263 ) ;
F_148 ( V_5 ) ;
}
} else if ( F_34 ( V_273 , & V_5 -> V_263 ) ||
F_34 ( V_274 , & V_5 -> V_263 ) )
return - V_303 ;
else if ( ! strcasecmp ( V_251 [ 0 ] , L_137 ) )
;
else if ( ! strcasecmp ( V_251 [ 0 ] , L_140 ) )
F_69 ( V_279 , & V_5 -> V_263 ) ;
else {
if ( ! strcasecmp ( V_251 [ 0 ] , L_138 ) ) {
F_69 ( V_278 , & V_5 -> V_263 ) ;
F_69 ( V_277 , & V_5 -> V_263 ) ;
F_69 ( V_276 , & V_5 -> V_263 ) ;
} else if ( ! strcasecmp ( V_251 [ 0 ] , L_139 ) ) {
F_69 ( V_277 , & V_5 -> V_263 ) ;
F_69 ( V_276 , & V_5 -> V_263 ) ;
} else
return - V_33 ;
}
if ( V_5 -> V_260 == 2 ) {
V_5 -> V_260 = 0 ;
if ( ! V_5 -> V_304 && V_5 -> V_301 )
F_149 ( V_5 -> V_301 ) ;
}
F_69 ( V_274 , & V_5 -> V_263 ) ;
if ( ! V_5 -> V_304 && V_5 -> V_305 )
F_149 ( V_5 -> V_305 ) ;
return 0 ;
}
static int F_150 ( struct V_61 * V_32 ,
T_5 V_306 , void * V_307 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
unsigned int V_63 ;
int V_44 = 0 ;
for ( V_63 = 0 ; ! V_44 && V_63 < V_2 -> V_6 . V_59 ; V_63 ++ )
if ( V_2 -> V_65 [ V_63 ] . V_71 )
V_44 = V_306 ( V_32 ,
V_2 -> V_65 [ V_63 ] . V_71 ,
0 ,
V_2 -> V_6 . V_21 ,
V_307 ) ;
return V_44 ;
}
static void F_151 ( struct V_61 * V_32 , struct V_308 * V_245 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
unsigned int V_309 = F_65 ( V_2 -> V_6 . V_58 ) ;
F_152 ( V_245 , V_309 ) ;
F_153 ( V_245 , V_309 * F_77 ( V_2 ) ) ;
}
static void F_154 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
F_155 ( & V_2 -> V_6 ) ;
}
static void F_156 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
if ( ! V_2 -> V_6 . V_304 )
F_132 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_260 = 1 ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_63 ;
T_3 V_310 [ V_198 ] ;
unsigned long V_55 ;
bool V_311 = false ;
struct V_191 * V_192 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_50 * V_44 ;
if ( ! V_5 -> V_184 || ! V_5 -> V_184 -> V_312 || ! V_5 -> V_184 -> V_313 )
return;
memset ( V_310 , 0 , sizeof( V_310 ) ) ;
for ( V_63 = 0 ; V_63 < V_5 -> V_59 ; V_63 ++ ) {
V_44 = & V_2 -> V_65 [ V_63 ] . V_51 ;
if ( F_34 ( V_54 , & V_44 -> V_55 ) )
continue;
if ( F_34 ( V_124 , & V_44 -> V_55 ) &&
V_44 -> V_83 && ! F_95 ( V_44 , V_44 -> V_212 , true ) ) {
F_63 ( L_156
L_157 ,
V_2 -> V_24 -> V_17 , V_63 ) ;
V_55 = V_44 -> V_55 ;
F_73 ( V_81 , & V_44 -> V_55 ) ;
if ( V_44 -> V_77 >= 0 ) {
if ( V_5 -> V_184 -> V_313 ( V_5 , V_44 ) ) {
V_44 -> V_55 = V_55 ;
continue;
}
} else
V_44 -> V_77 = V_44 -> V_232 = V_63 ;
F_73 ( V_124 , & V_44 -> V_55 ) ;
F_73 ( V_314 , & V_44 -> V_55 ) ;
if ( V_5 -> V_184 -> V_312 ( V_5 , V_44 ) ) {
V_44 -> V_77 = V_44 -> V_232 = - 1 ;
V_44 -> V_55 = V_55 ;
} else {
F_73 ( V_81 , & V_44 -> V_55 ) ;
V_44 -> V_82 = 0 ;
F_69 ( V_63 , ( void * ) V_310 ) ;
V_311 = true ;
}
}
}
if ( V_311 ) {
T_3 V_193 [ V_198 ] ;
F_41 (r, &rs->md) {
if ( F_34 ( V_54 , & V_44 -> V_55 ) )
continue;
V_192 = F_105 ( V_44 -> V_80 ) ;
F_99 ( V_192 , V_193 ) ;
for ( V_63 = 0 ; V_63 < V_198 ; V_63 ++ )
V_193 [ V_63 ] &= ~ V_310 [ V_63 ] ;
F_102 ( V_192 , V_193 ) ;
}
}
}
static int F_158 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
if ( ! F_8 ( V_2 ) &&
! F_70 ( V_315 , & V_2 -> V_236 ) ) {
V_44 = F_159 ( & V_2 -> V_6 ) ;
if ( V_44 )
F_7 ( L_158 ) ;
}
return V_44 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
int V_260 = V_5 -> V_260 ;
F_69 ( V_219 , & V_5 -> V_220 ) ;
V_5 -> V_260 = 0 ;
F_161 ( V_5 , 1 ) ;
V_5 -> V_260 = V_260 ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_44 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_316 * V_184 = V_5 -> V_184 ;
V_44 = F_117 ( V_2 ) ;
if ( V_44 )
return V_44 ;
if ( V_5 -> V_304 )
F_163 ( V_5 ) ;
V_44 = V_184 -> V_185 ( V_5 ) ;
if ( V_44 ) {
V_2 -> V_32 -> error = L_159 ;
return V_44 ;
}
if ( V_184 -> V_267 ) {
V_44 = V_184 -> V_267 ( V_5 ) ;
if ( V_44 ) {
V_2 -> V_32 -> error = L_160 ;
return V_44 ;
}
}
if ( ! V_5 -> V_304 )
F_132 ( V_5 ) ;
F_160 ( V_2 ) ;
return 0 ;
}
static int F_164 ( struct V_61 * V_32 )
{
int V_44 ;
struct V_1 * V_2 = V_32 -> V_163 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_70 ( V_295 , & V_2 -> V_236 ) )
return 0 ;
if ( F_34 ( V_235 , & V_2 -> V_236 ) )
F_160 ( V_2 ) ;
V_44 = F_158 ( V_2 ) ;
if ( V_44 )
return V_44 ;
if ( F_34 ( V_315 , & V_2 -> V_236 ) && V_5 -> V_317 &&
V_5 -> V_93 . V_94 != F_65 ( V_2 -> V_156 ) ) {
V_44 = F_165 ( V_5 -> V_317 , V_5 -> V_21 ,
F_65 ( V_2 -> V_156 ) , 0 ) ;
if ( V_44 )
F_7 ( L_161 ) ;
}
F_69 ( V_262 , & V_5 -> V_263 ) ;
if ( V_5 -> V_20 && V_5 -> V_20 < V_23 ) {
F_69 ( V_276 , & V_5 -> V_263 ) ;
V_5 -> V_318 = V_5 -> V_20 ;
}
F_38 ( V_2 ) ;
if ( F_111 ( V_239 , & V_2 -> V_236 ) ) {
F_128 ( V_5 ) ;
V_44 = F_162 ( V_2 ) ;
F_130 ( V_5 ) ;
if ( V_44 )
F_166 ( L_162 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static void F_167 ( struct V_61 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_163 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_70 ( V_319 , & V_2 -> V_236 ) ) {
F_157 ( V_2 ) ;
}
V_5 -> V_260 = 0 ;
V_5 -> V_261 = 0 ;
if ( ! ( V_2 -> V_31 & V_320 ) )
F_73 ( V_262 , & V_5 -> V_263 ) ;
if ( V_5 -> V_304 )
F_163 ( V_5 ) ;
}
static int T_6 F_168 ( void )
{
F_63 ( L_163 ,
V_321 . V_322 [ 0 ] ,
V_321 . V_322 [ 1 ] ,
V_321 . V_322 [ 2 ] ) ;
return F_169 ( & V_321 ) ;
}
static void T_7 F_170 ( void )
{
F_171 ( & V_321 ) ;
}
