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
static int F_8 ( const char * V_19 )
{
int V_20 = F_6 ( V_21 ) ;
while ( V_20 -- )
if ( ! strcasecmp ( V_19 , V_21 [ V_20 ] . V_22 ) )
return V_21 [ V_20 ] . V_19 ;
return - V_23 ;
}
static const char * F_9 ( const int V_19 )
{
int V_20 = F_6 ( V_21 ) ;
while ( V_20 -- )
if ( V_19 == V_21 [ V_20 ] . V_19 )
return V_21 [ V_20 ] . V_22 ;
return L_2 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return ! V_2 -> V_6 . V_24 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_24 == 1 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_24 == 10 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_24 == 6 ;
}
static bool F_14 ( struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_6 . V_24 , 4 , 6 ) ;
}
static bool F_15 ( struct V_1 * V_2 )
{
return F_14 ( V_2 ) ||
( F_12 ( V_2 ) && ! F_16 ( V_2 -> V_6 . V_8 ) ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_25 < V_2 -> V_6 . V_26 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_27 != V_28 ;
}
static bool F_19 ( struct V_29 * V_30 )
{
return ! V_30 -> V_24 ;
}
static bool F_20 ( struct V_29 * V_30 )
{
return V_30 -> V_24 == 1 ;
}
static bool F_21 ( struct V_29 * V_30 )
{
return V_30 -> V_24 == 10 ;
}
static bool F_22 ( struct V_29 * V_30 )
{
return F_3 ( V_30 -> V_24 , 4 , 5 ) ;
}
static bool F_23 ( struct V_29 * V_30 )
{
return V_30 -> V_24 == 6 ;
}
static bool F_24 ( struct V_29 * V_30 )
{
return F_3 ( V_30 -> V_24 , 4 , 6 ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 )
{
if ( F_19 ( V_2 -> V_29 ) )
return V_31 ;
else if ( F_20 ( V_2 -> V_29 ) )
return V_32 ;
else if ( F_21 ( V_2 -> V_29 ) )
return V_33 ;
else if ( F_22 ( V_2 -> V_29 ) )
return V_34 ;
else if ( F_23 ( V_2 -> V_29 ) )
return V_35 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 & ~ F_25 ( V_2 ) ) {
V_2 -> V_37 -> error = L_3 ;
return - V_23 ;
}
return 0 ;
}
static unsigned int F_27 ( int V_38 )
{
return V_38 & 0xFF ;
}
static unsigned int F_28 ( int V_38 )
{
return F_27 ( V_38 >> V_39 ) ;
}
static bool F_29 ( int V_38 )
{
return ! ! ( V_38 & V_40 ) ;
}
static bool F_30 ( int V_38 )
{
return ! F_29 ( V_38 ) && F_27 ( V_38 ) > 1 ;
}
static bool F_16 ( int V_38 )
{
return ! F_29 ( V_38 ) && F_28 ( V_38 ) > 1 ;
}
static const char * F_31 ( int V_38 )
{
if ( F_29 ( V_38 ) )
return L_4 ;
if ( F_27 ( V_38 ) > 1 )
return L_5 ;
if ( F_28 ( V_38 ) > 1 )
return L_6 ;
return L_2 ;
}
static int F_32 ( const char * V_17 )
{
if ( ! strcasecmp ( V_17 , L_5 ) )
return V_41 ;
else if ( ! strcasecmp ( V_17 , L_4 ) )
return V_42 ;
else if ( ! strcasecmp ( V_17 , L_6 ) )
return V_43 ;
return - V_23 ;
}
static unsigned int F_33 ( int V_38 )
{
return V_12 ( F_27 ( V_38 ) , F_28 ( V_38 ) ) ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned int V_44 ,
unsigned int V_45 )
{
unsigned int V_46 = 1 , V_47 = 1 , V_48 = 0 ;
if ( V_44 == V_49 ||
V_44 == V_41 )
V_46 = V_45 ;
else if ( V_44 == V_42 ) {
V_47 = V_45 ;
V_48 = V_40 ;
if ( ! F_35 ( V_50 , & V_2 -> V_36 ) )
V_48 |= V_51 ;
} else if ( V_44 == V_43 ) {
V_47 = V_45 ;
V_48 = ! V_40 ;
if ( ! F_35 ( V_50 , & V_2 -> V_36 ) )
V_48 |= V_51 ;
} else
return - V_23 ;
return V_48 | ( V_47 << V_39 ) | V_46 ;
}
static bool F_36 ( struct V_29 * V_52 , const int V_38 )
{
if ( V_52 -> V_24 == 10 ) {
switch ( V_52 -> V_44 ) {
case V_49 :
case V_41 :
return F_30 ( V_38 ) ;
case V_42 :
return F_29 ( V_38 ) ;
case V_43 :
return F_16 ( V_38 ) ;
default:
break;
}
}
return false ;
}
static struct V_29 * F_37 ( const char * V_17 )
{
struct V_29 * V_52 = V_53 + F_6 ( V_53 ) ;
while ( V_52 -- > V_53 )
if ( ! strcasecmp ( V_52 -> V_17 , V_17 ) )
return V_52 ;
return NULL ;
}
static struct V_29 * F_38 ( const int V_24 , const int V_38 )
{
struct V_29 * V_52 = V_53 + F_6 ( V_53 ) ;
while ( V_52 -- > V_53 ) {
if ( V_52 -> V_24 == V_24 &&
( F_36 ( V_52 , V_38 ) || V_52 -> V_44 == V_38 ) )
return V_52 ;
}
return NULL ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_54 * V_55 ;
struct V_56 * V_56 = F_40 ( F_41 ( V_2 -> V_37 -> V_57 ) ) ;
F_42 (rdev, mddev)
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) )
V_55 -> V_60 = V_5 -> V_26 ;
F_43 ( V_56 , V_5 -> V_61 ) ;
F_44 ( V_56 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_7 = V_5 -> V_24 ;
V_5 -> V_8 = V_5 -> V_38 ;
V_5 -> V_9 = V_5 -> V_62 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
V_5 -> V_24 = V_5 -> V_7 ;
V_5 -> V_38 = V_5 -> V_8 ;
V_5 -> V_62 = V_5 -> V_9 ;
V_5 -> V_63 = V_2 -> V_63 ;
V_5 -> V_64 = 0 ;
}
static struct V_1 * F_47 ( struct V_65 * V_37 , struct V_29 * V_29 ,
unsigned int V_66 )
{
unsigned int V_67 ;
struct V_1 * V_2 ;
if ( V_66 <= V_29 -> V_68 ) {
V_37 -> error = L_7 ;
return F_48 ( - V_23 ) ;
}
V_2 = F_49 ( sizeof( * V_2 ) + V_66 * sizeof( V_2 -> V_69 [ 0 ] ) , V_70 ) ;
if ( ! V_2 ) {
V_37 -> error = L_8 ;
return F_48 ( - V_71 ) ;
}
F_50 ( & V_2 -> V_6 ) ;
V_2 -> V_63 = V_66 ;
V_2 -> V_64 = 0 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_72 = 256 ;
V_2 -> V_6 . V_63 = V_66 ;
V_2 -> V_6 . V_24 = V_29 -> V_24 ;
V_2 -> V_6 . V_7 = V_2 -> V_6 . V_24 ;
V_2 -> V_6 . V_38 = V_29 -> V_44 ;
V_2 -> V_6 . V_8 = V_2 -> V_6 . V_38 ;
V_2 -> V_6 . V_64 = 0 ;
V_2 -> V_6 . V_25 = V_28 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ )
F_51 ( & V_2 -> V_69 [ V_67 ] . V_55 ) ;
return V_2 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_67 ;
if ( V_2 -> V_73 . V_69 ) {
F_53 ( & V_2 -> V_73 . V_55 ) ;
F_54 ( V_2 -> V_37 , V_2 -> V_73 . V_69 ) ;
}
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ ) {
if ( V_2 -> V_69 [ V_67 ] . V_74 )
F_54 ( V_2 -> V_37 , V_2 -> V_69 [ V_67 ] . V_74 ) ;
F_53 ( & V_2 -> V_69 [ V_67 ] . V_55 ) ;
if ( V_2 -> V_69 [ V_67 ] . V_75 )
F_54 ( V_2 -> V_37 , V_2 -> V_69 [ V_67 ] . V_75 ) ;
}
F_55 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
int V_67 ;
int V_78 = 0 ;
int V_79 = 0 ;
int V_48 = 0 ;
const char * V_80 ;
V_80 = F_57 ( V_77 ) ;
if ( ! V_80 )
return - V_23 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ ) {
V_2 -> V_69 [ V_67 ] . V_55 . V_81 = V_67 ;
V_2 -> V_69 [ V_67 ] . V_74 = NULL ;
V_2 -> V_69 [ V_67 ] . V_75 = NULL ;
V_2 -> V_69 [ V_67 ] . V_55 . V_82 = 0 ;
V_2 -> V_69 [ V_67 ] . V_55 . V_83 = 0 ;
V_2 -> V_69 [ V_67 ] . V_55 . V_5 = & V_2 -> V_6 ;
V_80 = F_57 ( V_77 ) ;
if ( ! V_80 )
return - V_23 ;
if ( strcmp ( V_80 , L_9 ) ) {
V_48 = F_58 ( V_2 -> V_37 , V_80 , F_59 ( V_2 -> V_37 -> V_57 ) ,
& V_2 -> V_69 [ V_67 ] . V_74 ) ;
if ( V_48 ) {
V_2 -> V_37 -> error = L_10 ;
return V_48 ;
}
V_2 -> V_69 [ V_67 ] . V_55 . V_84 = F_60 ( V_70 ) ;
if ( ! V_2 -> V_69 [ V_67 ] . V_55 . V_84 ) {
V_2 -> V_37 -> error = L_11 ;
return - V_71 ;
}
}
V_80 = F_57 ( V_77 ) ;
if ( ! V_80 )
return - V_23 ;
if ( ! strcmp ( V_80 , L_9 ) ) {
if ( ! F_35 ( V_85 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) &&
( ! V_2 -> V_69 [ V_67 ] . V_55 . V_86 ) ) {
V_2 -> V_37 -> error = L_12 ;
return - V_23 ;
}
if ( V_2 -> V_69 [ V_67 ] . V_74 ) {
V_2 -> V_37 -> error = L_13 ;
return - V_23 ;
}
continue;
}
V_48 = F_58 ( V_2 -> V_37 , V_80 , F_59 ( V_2 -> V_37 -> V_57 ) ,
& V_2 -> V_69 [ V_67 ] . V_75 ) ;
if ( V_48 ) {
V_2 -> V_37 -> error = L_14 ;
return V_48 ;
}
if ( V_2 -> V_69 [ V_67 ] . V_74 ) {
V_79 = 1 ;
V_2 -> V_69 [ V_67 ] . V_55 . V_87 = V_2 -> V_69 [ V_67 ] . V_74 -> V_88 ;
}
V_2 -> V_69 [ V_67 ] . V_55 . V_88 = V_2 -> V_69 [ V_67 ] . V_75 -> V_88 ;
F_61 ( & V_2 -> V_69 [ V_67 ] . V_55 . V_89 , & V_2 -> V_6 . V_90 ) ;
if ( ! F_35 ( V_85 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) )
V_78 ++ ;
}
if ( V_2 -> V_73 . V_69 )
F_61 ( & V_2 -> V_73 . V_55 . V_89 , & V_2 -> V_6 . V_90 ) ;
if ( V_79 ) {
V_2 -> V_6 . V_91 = 0 ;
V_2 -> V_6 . V_92 = 1 ;
V_2 -> V_6 . V_93 = 2 ;
} else if ( V_78 && ! V_2 -> V_6 . V_25 ) {
V_2 -> V_37 -> error = L_15 ;
return - V_23 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned long V_94 )
{
unsigned long V_95 = V_2 -> V_37 -> V_96 / ( 1 << 21 ) ;
if ( F_10 ( V_2 ) )
return 0 ;
if ( ! V_94 ) {
if ( V_95 > ( 1 << 13 ) ) {
V_94 = F_63 ( V_95 ) ;
F_64 ( L_16 ,
V_94 ) ;
} else {
F_64 ( L_17 ) ;
V_94 = 1 << 13 ;
}
} else {
if ( V_94 > V_2 -> V_37 -> V_96 ) {
V_2 -> V_37 -> error = L_18 ;
return - V_23 ;
}
if ( V_94 < V_95 ) {
F_7 ( L_19 ,
V_94 , V_95 ) ;
V_2 -> V_37 -> error = L_20 ;
return - V_23 ;
}
if ( ! F_65 ( V_94 ) ) {
V_2 -> V_37 -> error = L_21 ;
return - V_23 ;
}
if ( V_94 < V_2 -> V_6 . V_62 ) {
V_2 -> V_37 -> error = L_22 ;
return - V_23 ;
}
}
V_2 -> V_6 . V_97 . V_98 = F_66 ( V_94 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
unsigned int V_67 , V_99 = 0 ;
unsigned int V_100 = 0 , V_45 ;
unsigned int V_101 , V_102 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_6 . V_63 ; V_67 ++ )
if ( ! F_35 ( V_85 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) ||
! V_2 -> V_69 [ V_67 ] . V_55 . V_84 )
V_99 ++ ;
switch ( V_2 -> V_29 -> V_24 ) {
case 0 :
break;
case 1 :
if ( V_99 >= V_2 -> V_6 . V_63 )
goto V_103;
break;
case 4 :
case 5 :
case 6 :
if ( V_99 > V_2 -> V_29 -> V_68 )
goto V_103;
break;
case 10 :
V_45 = F_33 ( V_2 -> V_6 . V_8 ) ;
if ( V_99 < V_45 )
break;
if ( F_30 ( V_2 -> V_6 . V_8 ) ) {
for ( V_67 = 0 ; V_67 < V_2 -> V_6 . V_63 ; V_67 ++ ) {
if ( ! ( V_67 % V_45 ) )
V_100 = 0 ;
if ( ( ! V_2 -> V_69 [ V_67 ] . V_55 . V_84 ||
! F_35 ( V_85 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) ) &&
( ++ V_100 >= V_45 ) )
goto V_103;
}
break;
}
V_101 = ( V_2 -> V_6 . V_63 / V_45 ) ;
V_102 = ( V_2 -> V_6 . V_63 / V_101 ) - 1 ;
V_102 *= V_101 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_6 . V_63 ; V_67 ++ ) {
if ( ! ( V_67 % V_45 ) && ! ( V_67 > V_102 ) )
V_100 = 0 ;
if ( ( ! V_2 -> V_69 [ V_67 ] . V_55 . V_84 ||
! F_35 ( V_85 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) ) &&
( ++ V_100 >= V_45 ) )
goto V_103;
}
break;
default:
if ( V_99 )
return - V_23 ;
}
return 0 ;
V_103:
return - V_23 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_76 * V_77 ,
unsigned int V_104 )
{
int V_105 , V_106 = V_49 ;
unsigned int V_107 = 2 ;
unsigned int V_67 , V_108 = 0 ;
unsigned int V_94 = 0 ;
T_2 V_109 ;
const char * V_80 , * V_110 ;
struct V_111 * V_112 ;
struct V_29 * V_30 = V_2 -> V_29 ;
V_80 = F_57 ( V_77 ) ;
V_104 -- ;
if ( F_69 ( V_80 , 10 , & V_105 ) < 0 ) {
V_2 -> V_37 -> error = L_23 ;
return - V_23 ;
}
if ( F_20 ( V_30 ) ) {
if ( V_105 )
F_7 ( L_24 ) ;
V_105 = 0 ;
} else if ( ! F_65 ( V_105 ) ) {
V_2 -> V_37 -> error = L_25 ;
return - V_23 ;
} else if ( V_105 < 8 ) {
V_2 -> V_37 -> error = L_26 ;
return - V_23 ;
}
V_2 -> V_6 . V_9 = V_2 -> V_6 . V_62 = V_105 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ ) {
F_70 ( V_85 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) ;
V_2 -> V_69 [ V_67 ] . V_55 . V_86 = V_28 ;
}
for ( V_67 = 0 ; V_67 < V_104 ; V_67 ++ ) {
V_110 = F_57 ( V_77 ) ;
if ( ! V_110 ) {
V_2 -> V_37 -> error = L_27 ;
return - V_23 ;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_113 ) ) ) {
if ( F_71 ( V_114 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_28 ;
return - V_23 ;
}
continue;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_115 ) ) ) {
if ( F_71 ( V_116 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_29 ;
return - V_23 ;
}
continue;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_117 ) ) ) {
if ( F_71 ( V_50 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_30 ;
return - V_23 ;
}
continue;
}
V_80 = F_57 ( V_77 ) ;
V_67 ++ ;
if ( ! V_80 ) {
V_2 -> V_37 -> error = L_31 ;
return - V_23 ;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_118 ) ) ) {
if ( F_71 ( V_119 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_32 ;
return - V_23 ;
}
if ( ! F_21 ( V_30 ) ) {
V_2 -> V_37 -> error = L_33 ;
return - V_23 ;
}
V_106 = F_32 ( V_80 ) ;
if ( V_106 < 0 ) {
V_2 -> V_37 -> error = L_34 ;
return V_106 ;
}
continue;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_120 ) ) ) {
int V_48 ;
struct V_54 * V_121 ;
if ( F_71 ( V_122 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_35 ;
return - V_23 ;
}
if ( ! F_24 ( V_30 ) ) {
V_2 -> V_37 -> error = L_36 ;
return - V_23 ;
}
V_48 = F_58 ( V_2 -> V_37 , V_80 , F_59 ( V_2 -> V_37 -> V_57 ) ,
& V_2 -> V_73 . V_69 ) ;
if ( V_48 ) {
V_2 -> V_37 -> error = L_37 ;
return V_48 ;
}
V_121 = & V_2 -> V_73 . V_55 ;
F_51 ( V_121 ) ;
V_121 -> V_5 = & V_2 -> V_6 ;
V_121 -> V_88 = V_2 -> V_73 . V_69 -> V_88 ;
V_121 -> V_60 = F_72 ( F_73 ( V_121 -> V_88 -> V_123 ) ) ;
if ( V_121 -> V_60 < V_124 ) {
V_2 -> V_37 -> error = L_38 ;
return - V_125 ;
}
V_2 -> V_73 . V_19 = V_126 ;
F_70 ( V_58 , & V_121 -> V_59 ) ;
continue;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_127 ) ) ) {
int V_48 ;
if ( ! F_35 ( V_122 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_39 ;
return - V_23 ;
}
if ( F_71 ( V_128 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_40 ;
return - V_23 ;
}
V_48 = F_8 ( V_80 ) ;
if ( V_48 < 0 ) {
V_2 -> V_37 -> error = L_41 ;
return V_48 ;
}
V_2 -> V_73 . V_19 = V_48 ;
continue;
}
if ( F_69 ( V_80 , 10 , & V_105 ) < 0 ) {
V_2 -> V_37 -> error = L_42 ;
return - V_23 ;
}
if ( ! strcasecmp ( V_110 , F_4 ( V_129 ) ) ) {
if ( ! F_3 ( V_105 , 0 , V_2 -> V_63 - 1 ) ) {
V_2 -> V_37 -> error = L_43 ;
return - V_23 ;
}
if ( F_71 ( V_105 , ( void * ) V_2 -> V_130 ) ) {
V_2 -> V_37 -> error = L_44 ;
return - V_23 ;
}
V_112 = V_2 -> V_69 + V_105 ;
F_74 ( V_85 , & V_112 -> V_55 . V_59 ) ;
F_74 ( V_131 , & V_112 -> V_55 . V_59 ) ;
V_112 -> V_55 . V_86 = 0 ;
F_70 ( V_132 , & V_2 -> V_36 ) ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_133 ) ) ) {
if ( ! F_20 ( V_30 ) ) {
V_2 -> V_37 -> error = L_45 ;
return - V_23 ;
}
if ( ! F_3 ( V_105 , 0 , V_2 -> V_6 . V_63 - 1 ) ) {
V_2 -> V_37 -> error = L_46 ;
return - V_23 ;
}
V_108 ++ ;
F_70 ( V_134 , & V_2 -> V_69 [ V_105 ] . V_55 . V_59 ) ;
F_70 ( V_135 , & V_2 -> V_36 ) ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_136 ) ) ) {
if ( ! F_20 ( V_30 ) ) {
V_2 -> V_37 -> error = L_47 ;
return - V_23 ;
}
if ( F_71 ( V_137 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_48 ;
return - V_23 ;
}
V_105 /= 2 ;
if ( V_105 > V_138 ) {
V_2 -> V_37 -> error = L_49 ;
return - V_23 ;
}
V_2 -> V_6 . V_97 . V_139 = V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_140 ) ) ) {
if ( F_71 ( V_141 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_50 ;
return - V_23 ;
}
if ( ! V_105 || ( V_105 > V_142 ) ) {
V_2 -> V_37 -> error = L_51 ;
return - V_23 ;
}
V_2 -> V_6 . V_97 . V_143 = V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_144 ) ) ) {
if ( F_71 ( V_145 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_52 ;
return - V_23 ;
}
if ( V_105 < 0 ||
( V_105 && ( V_105 < V_146 || V_105 % F_72 ( V_147 ) ) ) ) {
V_2 -> V_37 -> error = L_53 ;
return - V_23 ;
}
V_2 -> V_82 = V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_148 ) ) ) {
if ( F_71 ( V_149 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_54 ;
return - V_23 ;
}
if ( ! F_3 ( abs ( V_105 ) , 1 , V_150 - V_30 -> V_151 ) ) {
V_2 -> V_37 -> error = L_55 ;
return - V_23 ;
}
V_2 -> V_64 = V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_152 ) ) ) {
if ( F_71 ( V_153 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_56 ;
return - V_23 ;
}
if ( ! F_24 ( V_30 ) ) {
V_2 -> V_37 -> error = L_57 ;
return - V_23 ;
}
V_2 -> V_72 = V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_154 ) ) ) {
if ( F_71 ( V_155 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_58 ;
return - V_23 ;
}
if ( V_105 > V_156 ) {
V_2 -> V_37 -> error = L_59 ;
return - V_23 ;
}
V_2 -> V_6 . V_157 = ( int ) V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_158 ) ) ) {
if ( F_71 ( V_159 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_60 ;
return - V_23 ;
}
if ( V_105 > V_156 ) {
V_2 -> V_37 -> error = L_61 ;
return - V_23 ;
}
V_2 -> V_6 . V_160 = ( int ) V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_161 ) ) ) {
if ( F_71 ( V_162 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_62 ;
return - V_23 ;
}
V_94 = V_105 ;
V_2 -> V_163 = V_105 ;
} else if ( ! strcasecmp ( V_110 , F_4 ( V_164 ) ) ) {
if ( F_71 ( V_165 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_63 ;
return - V_23 ;
}
if ( ! F_3 ( V_105 , 2 , V_2 -> V_6 . V_63 ) ) {
V_2 -> V_37 -> error = L_64 ;
return - V_23 ;
}
V_107 = V_105 ;
} else {
F_7 ( L_65 , V_110 ) ;
V_2 -> V_37 -> error = L_66 ;
return - V_23 ;
}
}
if ( F_35 ( V_116 , & V_2 -> V_36 ) &&
F_35 ( V_114 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_67 ;
return - V_23 ;
}
if ( F_35 ( V_132 , & V_2 -> V_36 ) &&
( F_35 ( V_116 , & V_2 -> V_36 ) ||
F_35 ( V_114 , & V_2 -> V_36 ) ) ) {
V_2 -> V_37 -> error = L_68 ;
return - V_23 ;
}
if ( V_108 >= V_2 -> V_6 . V_63 ) {
V_2 -> V_37 -> error = L_69 ;
return - V_23 ;
}
if ( F_62 ( V_2 , V_94 ) )
return - V_23 ;
if ( V_2 -> V_6 . V_62 )
V_109 = V_2 -> V_6 . V_62 ;
else
V_109 = V_94 ;
if ( F_75 ( V_2 -> V_37 , V_109 ) )
return - V_23 ;
if ( F_21 ( V_30 ) ) {
if ( V_107 > V_2 -> V_6 . V_63 ) {
V_2 -> V_37 -> error = L_70 ;
return - V_23 ;
}
V_2 -> V_6 . V_8 = F_34 ( V_2 , V_106 , V_107 ) ;
if ( V_2 -> V_6 . V_8 < 0 ) {
V_2 -> V_37 -> error = L_71 ;
return V_2 -> V_6 . V_8 ;
}
V_30 = F_38 ( 10 , V_2 -> V_6 . V_8 ) ;
if ( ! V_30 ) {
V_2 -> V_37 -> error = L_72 ;
return - V_23 ;
}
if ( ( V_30 -> V_44 == V_49 ||
V_30 -> V_44 == V_41 ) &&
F_35 ( V_50 , & V_2 -> V_36 ) ) {
V_2 -> V_37 -> error = L_73 ;
return - V_23 ;
}
}
V_2 -> V_107 = V_107 ;
V_2 -> V_6 . V_92 = 0 ;
V_2 -> V_6 . V_91 = 1 ;
return F_26 ( V_2 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_166 * V_167 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
T_1 V_168 = V_12 ( V_5 -> V_62 , V_5 -> V_9 ) / 2 ;
T_1 V_169 = V_2 -> V_72 ;
if ( ! F_24 ( V_2 -> V_29 ) ) {
V_2 -> V_37 -> error = L_74 ;
return - V_23 ;
}
if ( V_169 < V_168 ) {
F_64 ( L_75 ,
V_169 , V_168 ) ;
V_169 = V_168 ;
}
V_167 = V_5 -> V_170 ;
if ( ! V_167 ) {
V_2 -> V_37 -> error = L_76 ;
return - V_23 ;
}
if ( V_167 -> V_171 != V_169 ) {
V_48 = F_77 ( V_5 , V_169 ) ;
if ( V_48 ) {
V_2 -> V_37 -> error = L_77 ;
return V_48 ;
}
F_64 ( L_78 , V_169 ) ;
}
return 0 ;
}
static unsigned int F_78 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_63 - V_2 -> V_29 -> V_68 ;
}
static unsigned int F_79 ( struct V_1 * V_2 )
{
return V_2 -> V_63 - V_2 -> V_29 -> V_68 ;
}
static T_2 F_80 ( struct V_1 * V_2 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_6 . V_63 ; V_67 ++ ) {
struct V_54 * V_55 = & V_2 -> V_69 [ V_67 ] . V_55 ;
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) &&
V_55 -> V_88 && V_55 -> V_60 )
return V_55 -> V_60 ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , bool V_172 )
{
int V_64 ;
unsigned int V_173 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_54 * V_55 ;
T_2 V_61 = V_2 -> V_37 -> V_96 , V_26 = V_2 -> V_37 -> V_96 ;
if ( V_172 ) {
V_64 = V_5 -> V_64 ;
V_173 = F_78 ( V_2 ) ;
} else {
V_64 = V_2 -> V_64 ;
V_173 = F_79 ( V_2 ) ;
}
if ( F_20 ( V_2 -> V_29 ) )
;
else if ( F_21 ( V_2 -> V_29 ) ) {
if ( V_2 -> V_107 < 2 ||
V_64 < 0 ) {
V_2 -> V_37 -> error = L_79 ;
return - V_23 ;
}
V_26 *= V_2 -> V_107 ;
if ( F_82 ( V_26 , V_173 ) )
goto V_174;
V_61 = ( V_173 + V_64 ) * V_26 ;
if ( F_82 ( V_61 , V_2 -> V_107 ) )
goto V_174;
} else if ( F_82 ( V_26 , V_173 ) )
goto V_174;
else
V_61 = ( V_173 + V_64 ) * V_26 ;
F_42 (rdev, mddev)
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) )
V_55 -> V_60 = V_26 ;
V_5 -> V_61 = V_61 ;
V_5 -> V_26 = V_26 ;
return 0 ;
V_174:
V_2 -> V_37 -> error = L_80 ;
return - V_23 ;
}
static void F_83 ( struct V_1 * V_2 , T_2 V_26 )
{
if ( F_10 ( V_2 ) )
V_2 -> V_6 . V_25 = V_28 ;
else if ( F_13 ( V_2 ) )
V_2 -> V_6 . V_25 = V_26 ;
else
V_2 -> V_6 . V_25 = F_35 ( V_114 , & V_2 -> V_36 )
? V_28 : V_26 ;
}
static void F_84 ( struct V_1 * V_2 , T_2 V_26 )
{
if ( ! V_26 )
F_83 ( V_2 , 0 ) ;
else if ( V_26 == V_28 )
F_83 ( V_2 , V_28 ) ;
else if ( F_80 ( V_2 ) < V_26 )
F_83 ( V_2 , F_80 ( V_2 ) ) ;
else
F_83 ( V_2 , V_28 ) ;
}
static void F_85 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = F_86 ( V_176 , struct V_1 , V_6 . V_177 ) ;
F_87 () ;
if ( ! F_18 ( V_2 ) )
F_39 ( V_2 ) ;
F_88 ( V_2 -> V_37 -> V_57 ) ;
}
static int F_89 ( struct V_178 * V_179 , int V_180 )
{
struct V_1 * V_2 = F_86 ( V_179 , struct V_1 , V_181 ) ;
return F_90 ( & V_2 -> V_6 , V_180 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
unsigned int V_182 ;
if ( V_2 -> V_6 . V_183 ) {
V_2 -> V_37 -> error = L_81 ;
return - V_184 ;
}
if ( F_18 ( V_2 ) ) {
V_2 -> V_37 -> error = L_82 ;
return - V_184 ;
}
switch ( V_5 -> V_24 ) {
case 0 :
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 5 ) &&
V_5 -> V_63 == 1 )
return 0 ;
if ( V_5 -> V_7 == 10 &&
! ( V_2 -> V_63 % V_5 -> V_63 ) )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 4 , 6 ) &&
V_5 -> V_8 == V_185 &&
V_5 -> V_63 > 1 )
return 0 ;
break;
case 10 :
if ( F_29 ( V_5 -> V_38 ) )
break;
V_182 = F_27 ( V_5 -> V_38 ) ;
if ( V_5 -> V_7 == 0 ) {
if ( V_182 > 1 &&
! ( V_5 -> V_63 % V_182 ) ) {
V_5 -> V_63 /= V_182 ;
V_5 -> V_64 = V_5 -> V_63 ;
return 0 ;
}
if ( V_182 == 1 &&
F_28 ( V_5 -> V_38 ) > 1 )
return 0 ;
break;
}
if ( V_5 -> V_7 == 1 &&
V_12 ( V_182 , F_28 ( V_5 -> V_38 ) ) == V_5 -> V_63 )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 4 , 5 ) &&
V_5 -> V_63 == 2 )
return 0 ;
break;
case 1 :
if ( F_3 ( V_5 -> V_7 , 4 , 5 ) &&
V_5 -> V_63 == 2 ) {
V_5 -> V_183 = 1 ;
return 0 ;
}
if ( V_5 -> V_7 == 0 &&
V_5 -> V_63 == 1 )
return 0 ;
if ( V_5 -> V_7 == 10 )
return 0 ;
break;
case 4 :
if ( V_5 -> V_7 == 0 )
return 0 ;
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 5 ) &&
V_5 -> V_63 == 2 )
return 0 ;
if ( F_3 ( V_5 -> V_7 , 5 , 6 ) &&
V_5 -> V_38 == V_185 )
return 0 ;
break;
case 5 :
if ( V_5 -> V_7 == 0 &&
V_5 -> V_38 == V_185 )
return 0 ;
if ( V_5 -> V_7 == 4 &&
V_5 -> V_38 == V_185 )
return 0 ;
if ( ( V_5 -> V_7 == 1 || V_5 -> V_7 == 4 || V_5 -> V_7 == 10 ) &&
V_5 -> V_63 == 2 )
return 0 ;
if ( V_5 -> V_7 == 6 &&
( ( V_5 -> V_38 == V_185 && V_5 -> V_8 == V_185 ) ||
F_3 ( V_5 -> V_8 , V_186 , V_187 ) ) )
return 0 ;
break;
case 6 :
if ( V_5 -> V_7 == 0 &&
V_5 -> V_38 == V_185 )
return 0 ;
if ( V_5 -> V_7 == 4 &&
V_5 -> V_38 == V_185 )
return 0 ;
if ( V_5 -> V_7 == 5 &&
( ( V_5 -> V_38 == V_185 && V_5 -> V_8 == V_185 ) ||
F_3 ( V_5 -> V_8 , V_188 , V_189 ) ) )
return 0 ;
default:
break;
}
V_2 -> V_37 -> error = L_83 ;
return - V_23 ;
}
static bool F_92 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_7 != V_2 -> V_6 . V_24 ;
}
static bool F_93 ( struct V_1 * V_2 )
{
bool V_190 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_92 ( V_2 ) )
return false ;
if ( ! V_5 -> V_24 )
return false ;
V_190 = V_5 -> V_8 != V_5 -> V_38 ||
V_5 -> V_9 != V_5 -> V_62 ||
V_2 -> V_64 ;
if ( V_5 -> V_24 == 1 ) {
if ( V_2 -> V_64 )
return ! ! V_2 -> V_64 ;
return ! V_190 &&
V_5 -> V_63 != V_2 -> V_63 ;
}
if ( V_5 -> V_24 == 10 )
return V_190 &&
! F_16 ( V_5 -> V_8 ) &&
V_2 -> V_64 >= 0 ;
return V_190 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_191 || ! V_5 -> V_191 -> V_192 )
V_2 -> V_37 -> error = L_84 ;
else if ( V_5 -> V_183 )
V_2 -> V_37 -> error = L_85 ;
else if ( F_17 ( V_2 ) )
V_2 -> V_37 -> error = L_86 ;
else if ( F_18 ( V_2 ) )
V_2 -> V_37 -> error = L_87 ;
else if ( ! ( F_11 ( V_2 ) || F_12 ( V_2 ) || F_14 ( V_2 ) ) )
V_2 -> V_37 -> error = L_88 ;
else
return 0 ;
return - V_184 ;
}
static int F_95 ( struct V_54 * V_55 , int V_193 , bool V_194 )
{
F_96 ( ! V_55 -> V_84 ) ;
if ( V_55 -> V_195 && ! V_194 )
return 0 ;
V_55 -> V_195 = 0 ;
if ( ! F_97 ( V_55 , 0 , V_193 , V_55 -> V_84 , V_196 , 0 , true ) ) {
F_7 ( L_89 ,
V_55 -> V_81 ) ;
F_98 ( V_55 -> V_5 , V_55 ) ;
F_70 ( V_131 , & V_55 -> V_59 ) ;
return - V_197 ;
}
V_55 -> V_195 = 1 ;
return 0 ;
}
static void F_99 ( struct V_198 * V_199 , T_3 * V_200 )
{
V_200 [ 0 ] = F_100 ( V_199 -> V_200 ) ;
memset ( V_200 + 1 , 0 , sizeof( V_199 -> V_201 ) ) ;
if ( F_101 ( V_199 -> V_202 ) & V_203 ) {
int V_67 = F_6 ( V_199 -> V_201 ) ;
while ( V_67 -- )
V_200 [ V_67 + 1 ] = F_100 ( V_199 -> V_201 [ V_67 ] ) ;
}
}
static void F_102 ( struct V_198 * V_199 , T_3 * V_200 )
{
int V_67 = F_6 ( V_199 -> V_201 ) ;
V_199 -> V_200 = F_103 ( V_200 [ 0 ] ) ;
while ( V_67 -- )
V_199 -> V_201 [ V_67 ] = F_103 ( V_200 [ V_67 + 1 ] ) ;
}
static void F_104 ( struct V_5 * V_5 , struct V_54 * V_55 )
{
bool V_204 = false ;
unsigned int V_67 ;
T_3 V_200 [ V_205 ] ;
struct V_198 * V_199 ;
struct V_1 * V_2 = F_86 ( V_5 , struct V_1 , V_6 ) ;
if ( ! V_55 -> V_87 )
return;
F_96 ( ! V_55 -> V_84 ) ;
V_199 = F_105 ( V_55 -> V_84 ) ;
F_99 ( V_199 , V_200 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ )
if ( ! V_2 -> V_69 [ V_67 ] . V_75 || F_35 ( V_131 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) ) {
V_204 = true ;
F_70 ( V_67 , ( void * ) V_200 ) ;
}
if ( V_204 )
F_102 ( V_199 , V_200 ) ;
V_199 -> V_206 = F_106 ( V_207 ) ;
V_199 -> V_202 = F_106 ( V_203 ) ;
V_199 -> V_208 = F_106 ( V_5 -> V_63 ) ;
V_199 -> V_209 = F_106 ( V_55 -> V_81 ) ;
V_199 -> V_210 = F_103 ( V_5 -> V_210 ) ;
V_199 -> V_211 = F_103 ( V_55 -> V_86 ) ;
V_199 -> V_212 = F_103 ( V_5 -> V_25 ) ;
V_199 -> V_24 = F_106 ( V_5 -> V_24 ) ;
V_199 -> V_38 = F_106 ( V_5 -> V_38 ) ;
V_199 -> V_213 = F_106 ( V_5 -> V_62 ) ;
V_199 -> V_7 = F_106 ( V_5 -> V_7 ) ;
V_199 -> V_8 = F_106 ( V_5 -> V_8 ) ;
V_199 -> V_214 = F_106 ( V_5 -> V_9 ) ;
V_199 -> V_64 = F_106 ( V_5 -> V_64 ) ;
F_87 () ;
V_199 -> V_27 = F_103 ( V_5 -> V_27 ) ;
if ( F_100 ( V_199 -> V_27 ) != V_28 ) {
V_199 -> V_59 |= F_106 ( V_215 ) ;
if ( V_5 -> V_64 < 0 || V_5 -> V_216 )
V_199 -> V_59 |= F_106 ( V_217 ) ;
} else {
V_199 -> V_59 &= ~ ( F_106 ( V_215 | V_217 ) ) ;
}
V_199 -> V_61 = F_103 ( V_5 -> V_61 ) ;
V_199 -> V_82 = F_103 ( V_55 -> V_82 ) ;
V_199 -> V_83 = F_103 ( V_55 -> V_83 ) ;
V_199 -> V_60 = F_103 ( V_55 -> V_60 ) ;
V_199 -> V_218 = F_106 ( 0 ) ;
memset ( V_199 + 1 , 0 , V_55 -> V_219 - sizeof( * V_199 ) ) ;
}
static int F_107 ( struct V_54 * V_55 , struct V_54 * V_220 )
{
int V_48 ;
struct V_198 * V_199 ;
struct V_198 * V_221 ;
T_3 V_222 , V_223 ;
V_55 -> V_224 = 0 ;
V_55 -> V_219 = F_108 ( V_55 -> V_87 ) ;
if ( V_55 -> V_219 < sizeof( * V_199 ) || V_55 -> V_219 > V_147 ) {
F_7 ( L_90 ) ;
return - V_23 ;
}
V_48 = F_95 ( V_55 , V_55 -> V_219 , false ) ;
if ( V_48 )
return V_48 ;
V_199 = F_105 ( V_55 -> V_84 ) ;
if ( ( V_199 -> V_206 != F_106 ( V_207 ) ) ||
( ! F_35 ( V_85 , & V_55 -> V_59 ) && ! V_55 -> V_86 ) ) {
F_104 ( V_55 -> V_5 , V_55 ) ;
F_70 ( V_225 , & V_55 -> V_59 ) ;
V_199 -> V_202 = F_106 ( V_203 ) ;
F_70 ( V_226 , & V_55 -> V_5 -> V_227 ) ;
return V_220 ? 0 : 1 ;
}
if ( ! V_220 )
return 1 ;
V_222 = F_100 ( V_199 -> V_210 ) ;
V_221 = F_105 ( V_220 -> V_84 ) ;
V_223 = F_100 ( V_221 -> V_210 ) ;
return ( V_222 > V_223 ) ? 1 : 0 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
int V_228 ;
unsigned int V_229 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
T_3 V_222 ;
T_3 V_200 [ V_205 ] ;
struct V_198 * V_199 ;
T_1 V_230 = 0 , V_231 = 0 , V_232 = 0 ;
struct V_54 * V_48 ;
struct V_198 * V_233 ;
V_199 = F_105 ( V_55 -> V_84 ) ;
V_222 = F_100 ( V_199 -> V_210 ) ;
V_5 -> V_210 = V_222 ? : 1 ;
V_5 -> V_27 = V_28 ;
V_5 -> V_63 = F_101 ( V_199 -> V_208 ) ;
V_5 -> V_24 = F_101 ( V_199 -> V_24 ) ;
V_5 -> V_38 = F_101 ( V_199 -> V_38 ) ;
V_5 -> V_62 = F_101 ( V_199 -> V_213 ) ;
if ( F_101 ( V_199 -> V_202 ) & V_203 ) {
V_5 -> V_7 = F_101 ( V_199 -> V_7 ) ;
V_5 -> V_8 = F_101 ( V_199 -> V_8 ) ;
V_5 -> V_9 = F_101 ( V_199 -> V_214 ) ;
V_5 -> V_64 = F_101 ( V_199 -> V_64 ) ;
V_5 -> V_61 = F_100 ( V_199 -> V_61 ) ;
if ( F_101 ( V_199 -> V_59 ) & V_215 ) {
if ( F_35 ( V_149 , & V_2 -> V_36 ) ) {
F_7 ( L_91 ) ;
return - V_23 ;
}
if ( V_5 -> V_64 < 0 ||
( ! V_5 -> V_64 && ( F_101 ( V_199 -> V_59 ) & V_217 ) ) )
V_5 -> V_216 = 1 ;
else
V_5 -> V_216 = 0 ;
V_5 -> V_27 = F_100 ( V_199 -> V_27 ) ;
V_2 -> V_29 = F_38 ( V_5 -> V_24 , V_5 -> V_38 ) ;
}
} else {
struct V_29 * V_234 = F_38 ( V_5 -> V_24 , V_5 -> V_38 ) ;
struct V_29 * V_235 = F_38 ( V_5 -> V_7 , V_5 -> V_8 ) ;
if ( F_92 ( V_2 ) ) {
if ( V_234 && V_235 )
F_7 ( L_92 ,
V_234 -> V_17 , V_235 -> V_17 ) ;
else
F_7 ( L_93 ) ;
return - V_23 ;
} else if ( F_93 ( V_2 ) ) {
F_7 ( L_94 ) ;
if ( V_5 -> V_38 != V_5 -> V_8 ) {
if ( V_234 && V_235 )
F_7 ( L_95 ,
V_234 -> V_17 , V_235 -> V_17 ) ;
else
F_7 ( L_96 ,
F_101 ( V_199 -> V_38 ) , V_5 -> V_8 ) ;
}
if ( V_5 -> V_62 != V_5 -> V_9 )
F_7 ( L_97 ,
V_5 -> V_62 , V_5 -> V_9 ) ;
if ( V_2 -> V_64 )
F_7 ( L_98 ,
V_5 -> V_63 , V_5 -> V_63 + V_2 -> V_64 ) ;
if ( F_12 ( V_2 ) ) {
F_7 ( L_99 ,
F_31 ( V_5 -> V_38 ) ,
F_33 ( V_5 -> V_38 ) ) ;
F_7 ( L_100 ,
F_31 ( V_5 -> V_8 ) ,
F_33 ( V_5 -> V_8 ) ) ;
}
return - V_23 ;
}
F_64 ( L_101 ) ;
}
if ( ! F_35 ( V_114 , & V_2 -> V_36 ) )
V_5 -> V_25 = F_100 ( V_199 -> V_212 ) ;
V_229 = 0 ;
F_42 (r, mddev) {
if ( F_35 ( V_58 , & V_55 -> V_59 ) )
continue;
if ( F_35 ( V_225 , & V_48 -> V_59 ) )
V_230 ++ ;
if ( ! F_35 ( V_85 , & V_48 -> V_59 ) ) {
F_64 ( L_102 ,
V_48 -> V_81 ) ;
V_232 ++ ;
if ( F_35 ( V_225 , & V_48 -> V_59 ) )
V_231 ++ ;
}
V_229 ++ ;
}
if ( V_230 == V_2 -> V_63 || ! V_232 ) {
if ( V_230 == 1 && ! V_2 -> V_64 )
;
if ( V_230 == V_2 -> V_63 ) {
F_64 ( L_103 ) ;
F_70 ( V_236 , & V_5 -> V_59 ) ;
} else if ( V_230 != V_232 &&
V_230 != V_2 -> V_64 ) {
F_7 ( L_104
L_105 ) ;
return - V_23 ;
}
} else if ( V_230 && V_230 != V_232 ) {
F_7 ( L_106
L_107 ,
V_232 , V_230 ) ;
return - V_23 ;
} else if ( V_232 ) {
if ( V_231 && V_232 != V_231 ) {
F_7 ( L_108 ,
V_230 > 1 ? L_109 : L_110 ) ;
return - V_23 ;
} else if ( F_17 ( V_2 ) ) {
F_7 ( L_111 ,
( unsigned long long ) V_5 -> V_25 ) ;
return - V_23 ;
} else if ( F_18 ( V_2 ) ) {
F_7 ( L_112 ,
( unsigned long long ) V_5 -> V_27 ) ;
return - V_23 ;
}
}
F_99 ( V_199 , V_200 ) ;
F_42 (r, mddev) {
if ( F_35 ( V_58 , & V_55 -> V_59 ) ||
! V_48 -> V_84 )
continue;
V_233 = F_105 ( V_48 -> V_84 ) ;
V_233 -> V_200 = 0 ;
memset ( V_233 -> V_201 , 0 , sizeof( V_233 -> V_201 ) ) ;
if ( ! F_35 ( V_225 , & V_48 -> V_59 ) && ( V_48 -> V_81 >= 0 ) ) {
V_228 = F_101 ( V_233 -> V_209 ) ;
if ( V_228 < 0 )
continue;
if ( V_228 != V_48 -> V_81 ) {
if ( F_12 ( V_2 ) && F_30 ( V_5 -> V_38 ) ) {
if ( V_5 -> V_63 % F_27 ( V_5 -> V_38 ) ||
V_2 -> V_63 % V_2 -> V_107 ) {
V_2 -> V_37 -> error =
L_113 ;
return - V_23 ;
}
V_233 -> V_209 = F_106 ( V_48 -> V_81 ) ;
} else if ( ! ( F_12 ( V_2 ) && F_19 ( V_2 -> V_29 ) ) &&
! ( F_10 ( V_2 ) && F_21 ( V_2 -> V_29 ) ) &&
! F_20 ( V_2 -> V_29 ) ) {
V_2 -> V_37 -> error = L_114 ;
return - V_23 ;
}
F_64 ( L_115 , V_228 , V_48 -> V_81 ) ;
}
if ( F_35 ( V_228 , ( void * ) V_200 ) )
F_70 ( V_131 , & V_48 -> V_59 ) ;
}
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_198 * V_199 ;
if ( F_10 ( V_2 ) || ! V_55 -> V_84 || V_55 -> V_81 < 0 )
return 0 ;
V_199 = F_105 ( V_55 -> V_84 ) ;
if ( ! V_5 -> V_210 && F_109 ( V_2 , V_55 ) )
return - V_23 ;
if ( F_101 ( V_199 -> V_202 ) &&
F_101 ( V_199 -> V_202 ) != V_203 ) {
V_2 -> V_37 -> error = L_116 ;
return - V_23 ;
}
if ( V_199 -> V_218 ) {
V_2 -> V_37 -> error = L_117 ;
return - V_23 ;
}
V_5 -> V_97 . V_237 = F_19 ( V_2 -> V_29 ) ? 0 : F_72 ( 4096 ) ;
V_5 -> V_97 . V_238 = V_5 -> V_97 . V_237 ;
if ( ! F_111 ( V_225 , & V_55 -> V_59 ) ) {
if ( F_101 ( V_199 -> V_202 ) & V_203 )
V_55 -> V_60 = F_100 ( V_199 -> V_60 ) ;
V_55 -> V_86 = F_100 ( V_199 -> V_211 ) ;
if ( V_55 -> V_86 == V_28 )
F_70 ( V_85 , & V_55 -> V_59 ) ;
else if ( ! F_18 ( V_2 ) )
F_74 ( V_85 , & V_55 -> V_59 ) ;
}
if ( F_111 ( V_131 , & V_55 -> V_59 ) ) {
V_55 -> V_86 = 0 ;
F_74 ( V_85 , & V_55 -> V_59 ) ;
V_55 -> V_239 = V_55 -> V_81 ;
}
V_55 -> V_82 = F_100 ( V_199 -> V_82 ) ;
V_55 -> V_83 = F_100 ( V_199 -> V_83 ) ;
return 0 ;
}
static int F_112 ( struct V_65 * V_37 , struct V_1 * V_2 )
{
int V_48 ;
struct V_54 * V_55 , * V_240 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
V_240 = NULL ;
F_42 (rdev, mddev) {
if ( F_35 ( V_58 , & V_55 -> V_59 ) )
continue;
if ( F_35 ( V_116 , & V_2 -> V_36 ) )
continue;
if ( ! V_55 -> V_87 )
continue;
V_48 = F_107 ( V_55 , V_240 ) ;
switch ( V_48 ) {
case 1 :
V_240 = V_55 ;
break;
case 0 :
break;
default:
if ( F_10 ( V_2 ) )
continue;
V_55 -> V_81 = V_55 -> V_239 = - 1 ;
break;
}
}
if ( ! V_240 )
return 0 ;
V_2 -> V_37 -> error = L_118 ;
if ( F_110 ( V_2 , V_240 ) )
return - V_23 ;
if ( F_67 ( V_2 ) ) {
V_2 -> V_37 -> error = L_119 ;
return - V_23 ;
}
F_42 (rdev, mddev)
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) &&
V_55 != V_240 &&
F_110 ( V_2 , V_55 ) )
return - V_23 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
T_2 V_82 = 0 , V_83 = 0 ;
struct V_54 * V_55 ;
if ( ! F_35 ( V_145 , & V_2 -> V_36 ) ) {
if ( ! F_15 ( V_2 ) )
goto V_241;
return 0 ;
}
V_55 = & V_2 -> V_69 [ 0 ] . V_55 ;
if ( V_2 -> V_64 < 0 ) {
V_82 = 0 ;
V_83 = V_2 -> V_82 ;
} else if ( V_2 -> V_64 > 0 ) {
V_82 = V_2 -> V_82 ;
V_83 = 0 ;
} else {
V_82 = V_2 -> V_82 ? V_55 -> V_82 : 0 ;
V_83 = V_82 ? 0 : V_2 -> V_82 ;
F_70 ( V_242 , & V_2 -> V_243 ) ;
}
if ( V_2 -> V_82 &&
F_72 ( F_73 ( V_55 -> V_88 -> V_123 ) ) - V_55 -> V_60 < V_146 ) {
V_2 -> V_37 -> error = V_82 ? L_120 :
L_121 ;
return - V_125 ;
}
V_241:
F_42 (rdev, &rs->md) {
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) ) {
V_55 -> V_82 = V_82 ;
V_55 -> V_83 = V_83 ;
}
}
return 0 ;
}
static void F_114 ( struct V_1 * V_2 )
{
int V_67 = 0 ;
struct V_54 * V_55 ;
F_42 (rdev, &rs->md) {
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) ) {
V_55 -> V_81 = V_67 ++ ;
V_55 -> V_239 = V_55 -> V_244 = - 1 ;
}
}
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_54 * V_55 ;
unsigned int V_229 = V_5 -> V_63 = V_2 -> V_63 ;
T_2 V_83 = V_2 -> V_69 [ 0 ] . V_55 . V_82 ? 0 : V_2 -> V_82 ;
if ( F_21 ( V_2 -> V_29 ) ) {
if ( V_5 -> V_24 == 0 ) {
F_114 ( V_2 ) ;
V_5 -> V_38 = F_34 ( V_2 , V_43 ,
V_2 -> V_107 ) ;
} else if ( V_5 -> V_24 == 1 )
V_5 -> V_38 = F_34 ( V_2 , V_41 ,
V_2 -> V_63 ) ;
else
return - V_23 ;
}
F_74 ( V_236 , & V_5 -> V_59 ) ;
V_5 -> V_25 = V_28 ;
while ( V_229 -- ) {
V_55 = & V_2 -> V_69 [ V_229 ] . V_55 ;
if ( F_35 ( V_229 , ( void * ) V_2 -> V_130 ) ) {
F_74 ( V_85 , & V_55 -> V_59 ) ;
F_74 ( V_131 , & V_55 -> V_59 ) ;
V_5 -> V_25 = V_55 -> V_86 = 0 ;
F_70 ( V_236 , & V_5 -> V_59 ) ;
}
V_55 -> V_83 = V_83 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
bool V_245 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_12 ( V_2 ) ) {
if ( V_2 -> V_63 != V_5 -> V_63 &&
F_30 ( V_5 -> V_38 ) &&
V_2 -> V_107 &&
V_2 -> V_107 != F_27 ( V_5 -> V_38 ) ) {
if ( V_2 -> V_63 % V_2 -> V_107 ) {
V_2 -> V_37 -> error = L_122 ;
return - V_23 ;
}
F_114 ( V_2 ) ;
V_5 -> V_38 = F_34 ( V_2 , V_41 ,
V_2 -> V_107 ) ;
V_5 -> V_8 = V_5 -> V_38 ;
V_245 = false ;
} else
V_245 = true ;
} else if ( F_14 ( V_2 ) )
V_245 = true ;
else if ( F_11 ( V_2 ) ) {
if ( V_2 -> V_64 ) {
V_5 -> V_183 = V_2 -> V_64 < 0 ? - V_2 -> V_64 : V_2 -> V_64 ;
V_245 = true ;
} else {
V_5 -> V_63 = V_2 -> V_63 ;
V_245 = false ;
}
} else {
V_2 -> V_37 -> error = L_123 ;
return - V_23 ;
}
if ( V_245 ) {
F_70 ( V_246 , & V_2 -> V_243 ) ;
F_70 ( V_242 , & V_2 -> V_243 ) ;
} else if ( V_5 -> V_63 < V_2 -> V_63 )
F_70 ( V_242 , & V_2 -> V_243 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_48 = 0 ;
unsigned int V_247 , V_229 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_54 * V_55 ;
V_5 -> V_64 = V_2 -> V_64 ;
V_247 = V_5 -> V_63 ;
if ( V_5 -> V_64 &&
V_5 -> V_38 != V_5 -> V_8 ) {
F_64 ( L_124 , V_2 -> V_64 ) ;
V_5 -> V_8 = V_5 -> V_38 ;
}
if ( V_2 -> V_64 > 0 ) {
for ( V_229 = V_247 ; V_229 < V_2 -> V_63 ; V_229 ++ ) {
V_55 = & V_2 -> V_69 [ V_229 ] . V_55 ;
F_74 ( V_85 , & V_55 -> V_59 ) ;
V_55 -> V_239 = - 1 ;
V_55 -> V_81 = V_229 ;
V_55 -> V_60 = V_5 -> V_26 ;
V_55 -> V_86 = F_11 ( V_2 ) ? 0 : V_28 ;
}
V_5 -> V_216 = 0 ;
} else if ( V_2 -> V_64 < 0 ) {
V_48 = F_81 ( V_2 , true ) ;
V_5 -> V_216 = 1 ;
} else {
V_5 -> V_216 = V_2 -> V_69 [ 0 ] . V_55 . V_82 ? 0 : 1 ;
}
return V_48 ;
}
static void F_118 ( struct V_1 * V_2 )
{
int V_67 ;
bool V_248 ;
struct V_65 * V_37 = V_2 -> V_37 ;
V_37 -> V_249 = false ;
V_248 = ( V_2 -> V_6 . V_24 == 4 || V_2 -> V_6 . V_24 == 5 || V_2 -> V_6 . V_24 == 6 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ ) {
struct V_250 * V_251 ;
if ( ! V_2 -> V_69 [ V_67 ] . V_55 . V_88 )
continue;
V_251 = F_119 ( V_2 -> V_69 [ V_67 ] . V_55 . V_88 ) ;
if ( ! V_251 || ! F_120 ( V_251 ) )
return;
if ( V_248 ) {
if ( ! V_252 ) {
F_7 ( L_125 ) ;
F_7 ( L_126 ) ;
return;
}
}
}
V_37 -> V_249 = true ;
V_37 -> V_253 = ! ! ( V_2 -> V_6 . V_24 == 1 || V_2 -> V_6 . V_24 == 10 ) ;
V_37 -> V_254 = 1 ;
}
static int F_121 ( struct V_65 * V_37 , unsigned int V_255 , char * * V_256 )
{
int V_48 ;
bool V_257 ;
struct V_29 * V_30 ;
unsigned int V_104 , V_258 ;
T_2 V_259 , V_260 ;
struct V_1 * V_2 = NULL ;
const char * V_80 ;
struct V_3 V_3 ;
struct V_76 V_77 = { V_255 , V_256 } , V_261 ;
struct V_262 V_263 [] = {
{ 0 , V_77 . V_255 , L_127 } ,
{ 1 , 254 , L_128 }
} ;
V_80 = F_57 ( & V_77 ) ;
if ( ! V_80 ) {
V_37 -> error = L_129 ;
return - V_23 ;
}
V_30 = F_37 ( V_80 ) ;
if ( ! V_30 ) {
V_37 -> error = L_130 ;
return - V_23 ;
}
if ( F_122 ( V_263 , & V_77 , & V_104 , & V_37 -> error ) )
return - V_23 ;
V_261 = V_77 ;
F_123 ( & V_261 , V_104 ) ;
V_263 [ 1 ] . V_12 = ( V_261 . V_255 - 1 ) / 2 ;
if ( F_124 ( V_263 + 1 , & V_261 , & V_258 , & V_37 -> error ) )
return - V_23 ;
if ( ! F_3 ( V_258 , 1 , V_150 ) ) {
V_37 -> error = L_131 ;
return - V_23 ;
}
V_2 = F_47 ( V_37 , V_30 , V_258 ) ;
if ( F_125 ( V_2 ) )
return F_126 ( V_2 ) ;
V_48 = F_68 ( V_2 , & V_77 , V_104 ) ;
if ( V_48 )
goto V_174;
V_48 = F_56 ( V_2 , & V_77 ) ;
if ( V_48 )
goto V_174;
V_2 -> V_6 . V_264 = F_104 ;
V_48 = F_81 ( V_2 , false ) ;
if ( V_48 )
goto V_174;
V_259 = V_2 -> V_6 . V_26 ;
F_1 ( V_2 , & V_3 ) ;
V_48 = F_112 ( V_37 , V_2 ) ;
if ( V_48 )
goto V_174;
V_260 = F_80 ( V_2 ) ;
if ( ! V_260 ) {
V_37 -> error = L_132 ;
V_48 = - V_23 ;
goto V_174;
}
V_257 = V_259 != V_260 ;
F_127 ( & V_2 -> V_6 . V_177 , F_85 ) ;
V_37 -> V_170 = V_2 ;
V_37 -> V_265 = 1 ;
F_2 ( V_2 , & V_3 ) ;
if ( F_35 ( V_236 , & V_2 -> V_6 . V_59 ) ) {
if ( F_13 ( V_2 ) &&
F_35 ( V_114 , & V_2 -> V_36 ) ) {
V_37 -> error = L_133 ;
V_48 = - V_23 ;
goto V_174;
}
F_84 ( V_2 , 0 ) ;
F_70 ( V_242 , & V_2 -> V_243 ) ;
F_46 ( V_2 ) ;
} else if ( F_17 ( V_2 ) ) {
;
} else if ( F_18 ( V_2 ) ) {
if ( V_257 ) {
V_37 -> error = L_134 ;
V_48 = - V_184 ;
goto V_174;
}
} else if ( F_92 ( V_2 ) ) {
if ( F_18 ( V_2 ) ) {
V_37 -> error = L_135 ;
V_48 = - V_184 ;
goto V_174;
}
if ( F_35 ( V_122 , & V_2 -> V_36 ) ) {
V_37 -> error = L_136 ;
V_48 = - V_184 ;
goto V_174;
}
V_48 = F_91 ( V_2 ) ;
if ( V_48 )
goto V_174;
V_48 = F_115 ( V_2 ) ;
if ( V_48 )
goto V_174;
F_70 ( V_242 , & V_2 -> V_243 ) ;
F_84 ( V_2 , V_28 ) ;
F_46 ( V_2 ) ;
} else if ( F_93 ( V_2 ) ) {
if ( F_35 ( V_122 , & V_2 -> V_36 ) ) {
V_37 -> error = L_137 ;
V_48 = - V_184 ;
goto V_174;
}
V_48 = F_116 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_84 ( V_2 , V_28 ) ;
F_45 ( V_2 ) ;
} else {
if ( F_35 ( V_132 , & V_2 -> V_36 ) ) {
F_84 ( V_2 , V_28 ) ;
F_70 ( V_242 , & V_2 -> V_243 ) ;
} else
F_84 ( V_2 , F_35 ( V_116 , & V_2 -> V_36 ) ?
0 : ( V_257 ? V_259 : V_28 ) ) ;
F_45 ( V_2 ) ;
}
V_48 = F_113 ( V_2 ) ;
if ( V_48 )
goto V_174;
V_2 -> V_6 . V_266 = 1 ;
V_2 -> V_6 . V_267 = 1 ;
F_70 ( V_268 , & V_2 -> V_6 . V_269 ) ;
F_128 ( & V_2 -> V_6 ) ;
V_48 = F_129 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_267 = 0 ;
if ( V_48 ) {
V_37 -> error = L_138 ;
F_130 ( & V_2 -> V_6 ) ;
goto V_174;
}
V_2 -> V_181 . V_270 = F_89 ;
F_131 ( V_37 -> V_57 , & V_2 -> V_181 ) ;
if ( F_35 ( V_128 , & V_2 -> V_36 ) ) {
V_48 = F_132 ( & V_2 -> V_6 , V_2 -> V_73 . V_19 ) ;
if ( V_48 ) {
V_37 -> error = L_139 ;
F_130 ( & V_2 -> V_6 ) ;
goto V_271;
}
}
F_133 ( & V_2 -> V_6 ) ;
F_70 ( V_272 , & V_2 -> V_243 ) ;
if ( F_14 ( V_2 ) ) {
V_48 = F_76 ( V_2 ) ;
if ( V_48 )
goto V_273;
}
if ( F_35 ( V_246 , & V_2 -> V_243 ) ) {
V_48 = F_94 ( V_2 ) ;
if ( V_48 )
goto V_274;
F_2 ( V_2 , & V_3 ) ;
if ( V_2 -> V_6 . V_191 -> V_275 ) {
V_48 = V_2 -> V_6 . V_191 -> V_192 ( & V_2 -> V_6 ) ;
if ( V_48 ) {
V_37 -> error = L_140 ;
goto V_274;
}
}
}
F_118 ( V_2 ) ;
F_130 ( & V_2 -> V_6 ) ;
return 0 ;
V_271:
V_273:
V_274:
F_134 ( & V_2 -> V_6 ) ;
V_174:
F_52 ( V_2 ) ;
return V_48 ;
}
static void F_135 ( struct V_65 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
F_136 ( & V_2 -> V_181 . V_276 ) ;
F_134 ( & V_2 -> V_6 ) ;
F_52 ( V_2 ) ;
}
static int F_137 ( struct V_65 * V_37 , struct V_277 * V_277 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_138 ( F_139 ( V_277 ) > V_5 -> V_61 ) )
return V_278 ;
V_5 -> V_191 -> V_279 ( V_5 , V_277 ) ;
return V_280 ;
}
static const char * F_140 ( struct V_5 * V_5 )
{
if ( F_35 ( V_268 , & V_5 -> V_269 ) )
return L_141 ;
if ( F_35 ( V_281 , & V_5 -> V_269 ) ||
( ! V_5 -> V_266 && F_35 ( V_282 , & V_5 -> V_269 ) ) ) {
if ( F_35 ( V_283 , & V_5 -> V_269 ) )
return L_142 ;
if ( F_35 ( V_284 , & V_5 -> V_269 ) ) {
if ( ! F_35 ( V_285 , & V_5 -> V_269 ) )
return L_143 ;
else if ( F_35 ( V_286 , & V_5 -> V_269 ) )
return L_144 ;
return L_145 ;
}
if ( F_35 ( V_287 , & V_5 -> V_269 ) )
return L_146 ;
}
return L_147 ;
}
static const char * F_141 ( struct V_1 * V_2 , struct V_54 * V_55 , bool V_288 )
{
if ( ! V_55 -> V_88 )
return L_9 ;
else if ( F_35 ( V_131 , & V_55 -> V_59 ) )
return L_148 ;
else if ( F_35 ( V_58 , & V_55 -> V_59 ) )
return ( V_2 -> V_73 . V_19 == V_126 ) ? L_149 : L_150 ;
else if ( ! V_288 || ! F_35 ( V_85 , & V_55 -> V_59 ) )
return L_150 ;
else
return L_149 ;
}
static T_2 F_142 ( struct V_1 * V_2 ,
T_2 V_289 , bool * V_288 )
{
T_2 V_48 , V_25 , V_290 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
V_290 = V_5 -> V_290 ? : V_5 -> V_25 ;
V_25 = V_5 -> V_25 ;
* V_288 = false ;
if ( F_10 ( V_2 ) ) {
V_48 = V_289 ;
* V_288 = true ;
} else {
V_48 = V_5 -> V_27 ;
if ( F_35 ( V_283 , & V_5 -> V_269 ) ||
V_48 != V_28 ) {
if ( V_48 == V_28 ) {
* V_288 = true ;
V_48 = V_289 ;
} else {
if ( V_5 -> V_216 )
V_48 = V_5 -> V_61 - V_48 ;
F_82 ( V_48 , F_78 ( V_2 ) ) ;
}
} else if ( F_35 ( V_281 , & V_5 -> V_269 ) )
V_48 = V_290 ;
else
V_48 = V_25 ;
if ( V_48 == V_28 ) {
* V_288 = true ;
V_48 = V_289 ;
} else if ( F_35 ( V_285 , & V_5 -> V_269 ) ) {
* V_288 = true ;
} else {
struct V_54 * V_55 ;
F_42 (rdev, mddev)
if ( ! F_35 ( V_58 , & V_55 -> V_59 ) &&
! F_35 ( V_85 , & V_55 -> V_59 ) )
* V_288 = true ;
#if 0
r = 0;
#endif
}
}
return V_48 ;
}
static const char * F_143 ( struct V_291 * V_69 )
{
return V_69 ? V_69 -> V_17 : L_9 ;
}
static void F_144 ( struct V_65 * V_37 , T_4 type ,
unsigned int V_292 , char * V_293 , unsigned int V_294 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_166 * V_167 = V_5 -> V_170 ;
int V_67 , V_295 = V_167 ? V_167 -> V_295 : 0 ;
bool V_288 ;
unsigned int V_296 = 1 ;
unsigned int V_297 = 0 ;
unsigned int V_130 ;
unsigned int V_298 = 0 ;
T_2 V_299 , V_289 , V_300 ;
const char * V_301 ;
struct V_29 * V_30 ;
switch ( type ) {
case V_302 :
V_30 = F_38 ( V_5 -> V_7 , V_5 -> V_8 ) ;
if ( ! V_30 )
return;
F_145 ( L_151 , V_30 -> V_17 , V_5 -> V_63 ) ;
F_87 () ;
V_289 = F_35 ( V_303 , & V_2 -> V_243 ) ?
V_5 -> V_289 : V_5 -> V_26 ;
V_299 = F_142 ( V_2 , V_289 , & V_288 ) ;
V_300 = ( V_5 -> V_304 && ! strcasecmp ( V_5 -> V_304 , L_144 ) ) ?
F_146 ( & V_5 -> V_300 ) : 0 ;
V_301 = F_140 ( & V_2 -> V_6 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ )
F_145 ( F_141 ( V_2 , & V_2 -> V_69 [ V_67 ] . V_55 , V_288 ) ) ;
F_145 ( L_152 , ( unsigned long long ) V_299 ,
( unsigned long long ) V_289 ) ;
F_145 ( L_153 , V_301 ) ;
F_145 ( L_154 , ( unsigned long long ) V_300 ) ;
F_145 ( L_154 , ( unsigned long long ) V_2 -> V_69 [ 0 ] . V_55 . V_82 ) ;
F_145 ( L_153 , F_35 ( V_122 , & V_2 -> V_36 ) ?
F_141 ( V_2 , & V_2 -> V_73 . V_55 , 0 ) : L_9 ) ;
break;
case V_305 :
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ )
if ( F_35 ( V_134 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) )
V_298 += 2 ;
V_130 = F_147 ( V_2 -> V_130 , V_205 * sizeof( * V_2 -> V_130 ) ) ;
V_296 += V_130 * 2 +
V_298 +
F_5 ( V_2 -> V_36 & V_306 ) +
F_5 ( V_2 -> V_36 & V_307 ) * 2 +
( F_35 ( V_122 , & V_2 -> V_36 ) ? 2 : 0 ) +
( F_35 ( V_128 , & V_2 -> V_36 ) ? 2 : 0 ) ;
F_145 ( L_155 , V_2 -> V_29 -> V_17 , V_296 , V_5 -> V_9 ) ;
if ( F_35 ( V_116 , & V_2 -> V_36 ) )
F_145 ( L_153 , F_4 ( V_115 ) ) ;
if ( F_35 ( V_114 , & V_2 -> V_36 ) )
F_145 ( L_153 , F_4 ( V_113 ) ) ;
if ( V_130 )
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ )
if ( F_35 ( V_2 -> V_69 [ V_67 ] . V_55 . V_81 , ( void * ) V_2 -> V_130 ) )
F_145 ( L_156 , F_4 ( V_129 ) ,
V_2 -> V_69 [ V_67 ] . V_55 . V_81 ) ;
if ( F_35 ( V_141 , & V_2 -> V_36 ) )
F_145 ( L_157 , F_4 ( V_140 ) ,
V_5 -> V_97 . V_143 ) ;
if ( F_35 ( V_155 , & V_2 -> V_36 ) )
F_145 ( L_158 , F_4 ( V_154 ) ,
V_5 -> V_157 ) ;
if ( F_35 ( V_159 , & V_2 -> V_36 ) )
F_145 ( L_158 , F_4 ( V_158 ) ,
V_5 -> V_160 ) ;
if ( V_298 )
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ )
if ( F_35 ( V_134 , & V_2 -> V_69 [ V_67 ] . V_55 . V_59 ) )
F_145 ( L_158 , F_4 ( V_133 ) ,
V_2 -> V_69 [ V_67 ] . V_55 . V_81 ) ;
if ( F_35 ( V_137 , & V_2 -> V_36 ) )
F_145 ( L_157 , F_4 ( V_136 ) ,
V_5 -> V_97 . V_139 ) ;
if ( F_35 ( V_153 , & V_2 -> V_36 ) )
F_145 ( L_158 , F_4 ( V_152 ) ,
V_295 ) ;
if ( F_35 ( V_162 , & V_2 -> V_36 ) )
F_145 ( L_159 , F_4 ( V_161 ) ,
( unsigned long long ) F_72 ( V_5 -> V_97 . V_98 ) ) ;
if ( F_35 ( V_165 , & V_2 -> V_36 ) )
F_145 ( L_158 , F_4 ( V_164 ) ,
F_33 ( V_5 -> V_38 ) ) ;
if ( F_35 ( V_119 , & V_2 -> V_36 ) )
F_145 ( L_160 , F_4 ( V_118 ) ,
F_31 ( V_5 -> V_38 ) ) ;
if ( F_35 ( V_149 , & V_2 -> V_36 ) )
F_145 ( L_158 , F_4 ( V_148 ) ,
V_12 ( V_2 -> V_64 , V_5 -> V_64 ) ) ;
if ( F_35 ( V_145 , & V_2 -> V_36 ) )
F_145 ( L_159 , F_4 ( V_144 ) ,
( unsigned long long ) V_2 -> V_82 ) ;
if ( F_35 ( V_122 , & V_2 -> V_36 ) )
F_145 ( L_160 , F_4 ( V_120 ) ,
F_143 ( V_2 -> V_73 . V_69 ) ) ;
if ( F_35 ( V_128 , & V_2 -> V_36 ) )
F_145 ( L_160 , F_4 ( V_127 ) ,
F_9 ( V_2 -> V_73 . V_19 ) ) ;
F_145 ( L_161 , V_2 -> V_63 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_63 ; V_67 ++ )
F_145 ( L_160 , F_143 ( V_2 -> V_69 [ V_67 ] . V_74 ) ,
F_143 ( V_2 -> V_69 [ V_67 ] . V_75 ) ) ;
}
}
static int F_148 ( struct V_65 * V_37 , unsigned int V_255 , char * * V_256 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( ! V_5 -> V_191 || ! V_5 -> V_191 -> V_308 )
return - V_23 ;
if ( ! strcasecmp ( V_256 [ 0 ] , L_141 ) )
F_70 ( V_268 , & V_5 -> V_269 ) ;
else
F_74 ( V_268 , & V_5 -> V_269 ) ;
if ( ! strcasecmp ( V_256 [ 0 ] , L_147 ) || ! strcasecmp ( V_256 [ 0 ] , L_141 ) ) {
if ( V_5 -> V_309 ) {
F_70 ( V_310 , & V_5 -> V_269 ) ;
F_149 ( V_5 ) ;
}
} else if ( F_35 ( V_281 , & V_5 -> V_269 ) ||
F_35 ( V_282 , & V_5 -> V_269 ) )
return - V_311 ;
else if ( ! strcasecmp ( V_256 [ 0 ] , L_143 ) )
;
else if ( ! strcasecmp ( V_256 [ 0 ] , L_146 ) )
F_70 ( V_287 , & V_5 -> V_269 ) ;
else {
if ( ! strcasecmp ( V_256 [ 0 ] , L_144 ) ) {
F_70 ( V_286 , & V_5 -> V_269 ) ;
F_70 ( V_285 , & V_5 -> V_269 ) ;
F_70 ( V_284 , & V_5 -> V_269 ) ;
} else if ( ! strcasecmp ( V_256 [ 0 ] , L_145 ) ) {
F_70 ( V_285 , & V_5 -> V_269 ) ;
F_70 ( V_284 , & V_5 -> V_269 ) ;
} else
return - V_23 ;
}
if ( V_5 -> V_266 == 2 ) {
V_5 -> V_266 = 0 ;
if ( ! V_5 -> V_312 && V_5 -> V_309 )
F_150 ( V_5 -> V_309 ) ;
}
F_70 ( V_282 , & V_5 -> V_269 ) ;
if ( ! V_5 -> V_312 && V_5 -> V_313 )
F_150 ( V_5 -> V_313 ) ;
return 0 ;
}
static int F_151 ( struct V_65 * V_37 ,
T_5 V_314 , void * V_315 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
unsigned int V_67 ;
int V_48 = 0 ;
for ( V_67 = 0 ; ! V_48 && V_67 < V_2 -> V_6 . V_63 ; V_67 ++ )
if ( V_2 -> V_69 [ V_67 ] . V_75 )
V_48 = V_314 ( V_37 ,
V_2 -> V_69 [ V_67 ] . V_75 ,
0 ,
V_2 -> V_6 . V_26 ,
V_315 ) ;
return V_48 ;
}
static void F_152 ( struct V_65 * V_37 , struct V_316 * V_317 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
unsigned int V_318 = F_66 ( V_2 -> V_6 . V_62 ) ;
F_153 ( V_317 , V_318 ) ;
F_154 ( V_317 , V_318 * F_78 ( V_2 ) ) ;
}
static void F_155 ( struct V_65 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
F_156 ( & V_2 -> V_6 ) ;
}
static void F_157 ( struct V_65 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
if ( ! F_71 ( V_272 , & V_2 -> V_243 ) )
F_133 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_266 = 1 ;
}
static void F_158 ( struct V_1 * V_2 )
{
int V_67 ;
T_3 V_319 [ V_205 ] ;
unsigned long V_59 ;
bool V_320 = false ;
struct V_198 * V_199 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_54 * V_48 ;
if ( ! V_5 -> V_191 || ! V_5 -> V_191 -> V_321 || ! V_5 -> V_191 -> V_322 )
return;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
for ( V_67 = 0 ; V_67 < V_5 -> V_63 ; V_67 ++ ) {
V_48 = & V_2 -> V_69 [ V_67 ] . V_55 ;
if ( F_35 ( V_58 , & V_48 -> V_59 ) )
continue;
if ( F_35 ( V_131 , & V_48 -> V_59 ) &&
V_48 -> V_87 && ! F_95 ( V_48 , V_48 -> V_219 , true ) ) {
F_64 ( L_162
L_163 ,
V_2 -> V_29 -> V_17 , V_67 ) ;
V_59 = V_48 -> V_59 ;
F_74 ( V_85 , & V_48 -> V_59 ) ;
if ( V_48 -> V_81 >= 0 ) {
if ( V_5 -> V_191 -> V_322 ( V_5 , V_48 ) ) {
V_48 -> V_59 = V_59 ;
continue;
}
} else
V_48 -> V_81 = V_48 -> V_239 = V_67 ;
F_74 ( V_131 , & V_48 -> V_59 ) ;
F_74 ( V_323 , & V_48 -> V_59 ) ;
if ( V_5 -> V_191 -> V_321 ( V_5 , V_48 ) ) {
V_48 -> V_81 = V_48 -> V_239 = - 1 ;
V_48 -> V_59 = V_59 ;
} else {
F_74 ( V_85 , & V_48 -> V_59 ) ;
V_48 -> V_86 = 0 ;
F_70 ( V_67 , ( void * ) V_319 ) ;
V_320 = true ;
}
}
}
if ( V_320 ) {
T_3 V_200 [ V_205 ] ;
F_42 (r, &rs->md) {
if ( F_35 ( V_58 , & V_48 -> V_59 ) )
continue;
V_199 = F_105 ( V_48 -> V_84 ) ;
F_99 ( V_199 , V_200 ) ;
for ( V_67 = 0 ; V_67 < V_205 ; V_67 ++ )
V_200 [ V_67 ] &= ~ V_319 [ V_67 ] ;
F_102 ( V_199 , V_200 ) ;
}
}
}
static int F_159 ( struct V_1 * V_2 )
{
int V_48 = 0 ;
if ( ! F_10 ( V_2 ) &&
! F_71 ( V_324 , & V_2 -> V_243 ) ) {
V_48 = F_160 ( & V_2 -> V_6 ) ;
if ( V_48 )
F_7 ( L_164 ) ;
}
return V_48 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = & V_2 -> V_6 ;
int V_266 = V_5 -> V_266 ;
F_70 ( V_226 , & V_5 -> V_227 ) ;
V_5 -> V_266 = 0 ;
F_162 ( V_5 , 1 ) ;
V_5 -> V_266 = V_266 ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
struct V_325 * V_191 = V_5 -> V_191 ;
V_48 = F_117 ( V_2 ) ;
if ( V_48 )
return V_48 ;
if ( F_111 ( V_272 , & V_2 -> V_243 ) )
F_164 ( V_5 ) ;
V_48 = V_191 -> V_192 ( V_5 ) ;
if ( V_48 ) {
V_2 -> V_37 -> error = L_165 ;
return V_48 ;
}
if ( V_191 -> V_275 ) {
V_48 = V_191 -> V_275 ( V_5 ) ;
if ( V_48 ) {
V_2 -> V_37 -> error = L_166 ;
return V_48 ;
}
}
F_70 ( V_272 , & V_2 -> V_243 ) ;
F_133 ( V_5 ) ;
F_161 ( V_2 ) ;
return 0 ;
}
static int F_165 ( struct V_65 * V_37 )
{
int V_48 ;
struct V_1 * V_2 = V_37 -> V_170 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_71 ( V_303 , & V_2 -> V_243 ) )
return 0 ;
if ( F_35 ( V_242 , & V_2 -> V_243 ) )
F_161 ( V_2 ) ;
V_48 = F_159 ( V_2 ) ;
if ( V_48 )
return V_48 ;
if ( F_35 ( V_324 , & V_2 -> V_243 ) && V_5 -> V_326 &&
V_5 -> V_97 . V_98 != F_66 ( V_2 -> V_163 ) ) {
V_48 = F_166 ( V_5 -> V_326 , V_5 -> V_26 ,
F_66 ( V_2 -> V_163 ) , 0 ) ;
if ( V_48 )
F_7 ( L_167 ) ;
}
F_70 ( V_268 , & V_5 -> V_269 ) ;
if ( V_5 -> V_25 && V_5 -> V_25 < V_28 ) {
F_70 ( V_284 , & V_5 -> V_269 ) ;
V_5 -> V_327 = V_5 -> V_25 ;
}
F_39 ( V_2 ) ;
if ( F_111 ( V_246 , & V_2 -> V_243 ) ) {
F_128 ( V_5 ) ;
V_48 = F_163 ( V_2 ) ;
F_130 ( V_5 ) ;
if ( V_48 )
F_167 ( L_168 ) ;
V_48 = 0 ;
}
return V_48 ;
}
static void F_168 ( struct V_65 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_170 ;
struct V_5 * V_5 = & V_2 -> V_6 ;
if ( F_71 ( V_328 , & V_2 -> V_243 ) ) {
F_158 ( V_2 ) ;
}
V_5 -> V_266 = 0 ;
V_5 -> V_267 = 0 ;
if ( ! ( V_2 -> V_36 & V_329 ) )
F_74 ( V_268 , & V_5 -> V_269 ) ;
if ( F_111 ( V_272 , & V_2 -> V_243 ) )
F_164 ( V_5 ) ;
}
static int T_6 F_169 ( void )
{
F_64 ( L_169 ,
V_330 . V_331 [ 0 ] ,
V_330 . V_331 [ 1 ] ,
V_330 . V_331 [ 2 ] ) ;
return F_170 ( & V_330 ) ;
}
static void T_7 F_171 ( void )
{
F_172 ( & V_330 ) ;
}
