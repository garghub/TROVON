static char * F_1 ( int V_1 )
{
if ( ( V_1 & 0x10000 ) && ( V_1 & 0x20000 ) )
return L_1 ;
if ( ( V_1 & 0xFF ) > 1 )
return L_2 ;
return L_3 ;
}
static unsigned F_2 ( int V_1 )
{
if ( ( V_1 & 0xFF ) > 1 )
return V_1 & 0xFF ;
return ( V_1 >> 8 ) & 0xFF ;
}
static int F_3 ( char * V_2 , unsigned V_3 )
{
unsigned V_4 = 1 , V_5 = 1 ;
if ( ! strcmp ( L_2 , V_2 ) )
V_4 = V_3 ;
else
V_5 = V_3 ;
if ( ! strcmp ( L_1 , V_2 ) )
return 0x30000 | ( V_5 << 8 ) | V_4 ;
if ( ! strcmp ( L_3 , V_2 ) )
return 0x20000 | ( V_5 << 8 ) | V_4 ;
return ( V_5 << 8 ) | V_4 ;
}
static struct V_6 * F_4 ( char * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_9 ) ; V_8 ++ )
if ( ! strcmp ( V_9 [ V_8 ] . V_7 , V_7 ) )
return & V_9 [ V_8 ] ;
return NULL ;
}
static struct V_10 * F_6 ( struct V_11 * V_12 , struct V_6 * V_6 , unsigned V_13 )
{
unsigned V_8 ;
struct V_10 * V_14 ;
if ( V_13 <= V_6 -> V_15 ) {
V_12 -> error = L_4 ;
return F_7 ( - V_16 ) ;
}
V_14 = F_8 ( sizeof( * V_14 ) + V_13 * sizeof( V_14 -> V_17 [ 0 ] ) , V_18 ) ;
if ( ! V_14 ) {
V_12 -> error = L_5 ;
return F_7 ( - V_19 ) ;
}
F_9 ( & V_14 -> V_20 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_20 . V_21 = V_13 ;
V_14 -> V_20 . V_22 = V_6 -> V_22 ;
V_14 -> V_20 . V_23 = V_14 -> V_20 . V_22 ;
V_14 -> V_20 . V_1 = V_6 -> V_24 ;
V_14 -> V_20 . V_25 = V_14 -> V_20 . V_1 ;
V_14 -> V_20 . V_26 = 0 ;
V_14 -> V_20 . V_27 = 0 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
F_10 ( & V_14 -> V_17 [ V_8 ] . V_28 ) ;
return V_14 ;
}
static void F_11 ( struct V_10 * V_14 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( V_14 -> V_17 [ V_8 ] . V_29 )
F_12 ( V_14 -> V_12 , V_14 -> V_17 [ V_8 ] . V_29 ) ;
F_13 ( & V_14 -> V_17 [ V_8 ] . V_28 ) ;
if ( V_14 -> V_17 [ V_8 ] . V_30 )
F_12 ( V_14 -> V_12 , V_14 -> V_17 [ V_8 ] . V_30 ) ;
}
F_14 ( V_14 ) ;
}
static int F_15 ( struct V_10 * V_14 , char * * V_31 )
{
int V_8 ;
int V_32 = 0 ;
int V_33 = 0 ;
int V_34 = 0 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ , V_31 += 2 ) {
V_14 -> V_17 [ V_8 ] . V_28 . V_35 = V_8 ;
V_14 -> V_17 [ V_8 ] . V_29 = NULL ;
V_14 -> V_17 [ V_8 ] . V_30 = NULL ;
V_14 -> V_17 [ V_8 ] . V_28 . V_36 = 0 ;
V_14 -> V_17 [ V_8 ] . V_28 . V_37 = & V_14 -> V_20 ;
if ( strcmp ( V_31 [ 0 ] , L_6 ) ) {
V_34 = F_16 ( V_14 -> V_12 , V_31 [ 0 ] ,
F_17 ( V_14 -> V_12 -> V_38 ) ,
& V_14 -> V_17 [ V_8 ] . V_29 ) ;
V_14 -> V_12 -> error = L_7 ;
if ( V_34 )
return V_34 ;
V_14 -> V_17 [ V_8 ] . V_28 . V_39 = F_18 ( V_18 ) ;
if ( ! V_14 -> V_17 [ V_8 ] . V_28 . V_39 )
return - V_19 ;
}
if ( ! strcmp ( V_31 [ 1 ] , L_6 ) ) {
if ( ! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) &&
( ! V_14 -> V_17 [ V_8 ] . V_28 . V_42 ) ) {
V_14 -> V_12 -> error = L_8 ;
return - V_16 ;
}
V_14 -> V_12 -> error = L_9 ;
if ( V_14 -> V_17 [ V_8 ] . V_29 )
return - V_16 ;
continue;
}
V_34 = F_16 ( V_14 -> V_12 , V_31 [ 1 ] ,
F_17 ( V_14 -> V_12 -> V_38 ) ,
& V_14 -> V_17 [ V_8 ] . V_30 ) ;
if ( V_34 ) {
V_14 -> V_12 -> error = L_10 ;
return V_34 ;
}
if ( V_14 -> V_17 [ V_8 ] . V_29 ) {
V_33 = 1 ;
V_14 -> V_17 [ V_8 ] . V_28 . V_43 = V_14 -> V_17 [ V_8 ] . V_29 -> V_44 ;
}
V_14 -> V_17 [ V_8 ] . V_28 . V_44 = V_14 -> V_17 [ V_8 ] . V_30 -> V_44 ;
F_20 ( & V_14 -> V_17 [ V_8 ] . V_28 . V_45 , & V_14 -> V_20 . V_46 ) ;
if ( ! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_32 ++ ;
}
if ( V_33 ) {
V_14 -> V_20 . V_47 = 0 ;
V_14 -> V_20 . V_48 = 1 ;
V_14 -> V_20 . V_49 = 2 ;
} else if ( V_32 && ! V_14 -> V_20 . V_27 ) {
F_21 ( L_11 ) ;
V_14 -> V_12 -> error = L_10 ;
return - V_16 ;
}
return 0 ;
}
static int F_22 ( struct V_10 * V_14 , unsigned long V_50 )
{
unsigned long V_51 = V_14 -> V_12 -> V_52 / ( 1 << 21 ) ;
if ( ! V_50 ) {
if ( V_51 > ( 1 << 13 ) ) {
if ( V_51 & ( V_51 - 1 ) )
V_50 = 1 << F_23 ( V_50 ) ;
F_24 ( L_12 ,
V_50 ) ;
} else {
F_24 ( L_13 ) ;
V_50 = 1 << 13 ;
}
} else {
if ( V_50 > V_14 -> V_12 -> V_52 ) {
V_14 -> V_12 -> error = L_14 ;
return - V_16 ;
}
if ( V_50 < V_51 ) {
F_21 ( L_15 ,
V_50 , V_51 ) ;
V_14 -> V_12 -> error = L_16 ;
return - V_16 ;
}
if ( ! F_25 ( V_50 ) ) {
V_14 -> V_12 -> error = L_17 ;
return - V_16 ;
}
if ( V_50 < V_14 -> V_20 . V_53 ) {
V_14 -> V_12 -> error = L_18 ;
return - V_16 ;
}
}
V_14 -> V_20 . V_54 . V_55 = ( V_50 << 9 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_14 )
{
unsigned V_8 , V_56 = 0 ;
unsigned V_57 , V_3 , V_58 ;
unsigned V_59 , V_60 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( ! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) ||
! V_14 -> V_17 [ V_8 ] . V_28 . V_39 )
V_56 ++ ;
switch ( V_14 -> V_6 -> V_22 ) {
case 1 :
if ( V_56 >= V_14 -> V_20 . V_21 )
goto V_61;
break;
case 4 :
case 5 :
case 6 :
if ( V_56 > V_14 -> V_6 -> V_15 )
goto V_61;
break;
case 10 :
V_3 = F_2 ( V_14 -> V_20 . V_1 ) ;
if ( V_56 < V_3 )
break;
if ( ! strcmp ( L_2 , F_1 ( V_14 -> V_20 . V_1 ) ) ) {
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 * V_3 ; V_8 ++ ) {
if ( ! ( V_8 % V_3 ) )
V_57 = 0 ;
V_58 = V_8 % V_14 -> V_20 . V_21 ;
if ( ( ! V_14 -> V_17 [ V_58 ] . V_28 . V_39 ||
! F_19 ( V_40 , & V_14 -> V_17 [ V_58 ] . V_28 . V_41 ) ) &&
( ++ V_57 >= V_3 ) )
goto V_61;
}
break;
}
V_59 = ( V_14 -> V_20 . V_21 / V_3 ) ;
V_60 = ( V_14 -> V_20 . V_21 / V_59 ) - 1 ;
V_60 *= V_59 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( ! ( V_8 % V_3 ) && ! ( V_8 > V_60 ) )
V_57 = 0 ;
if ( ( ! V_14 -> V_17 [ V_8 ] . V_28 . V_39 ||
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) ) &&
( ++ V_57 >= V_3 ) )
goto V_61;
}
break;
default:
if ( V_56 )
return - V_16 ;
}
return 0 ;
V_61:
return - V_16 ;
}
static int F_27 ( struct V_10 * V_14 , char * * V_31 ,
unsigned V_62 )
{
char * V_63 = L_2 ;
unsigned V_64 = 2 ;
unsigned V_8 ;
unsigned long V_65 , V_50 = 0 ;
T_1 V_66 = V_14 -> V_12 -> V_52 ;
T_1 V_67 ;
char * V_68 ;
if ( ( F_28 ( V_31 [ 0 ] , 10 , & V_65 ) < 0 ) ) {
V_14 -> V_12 -> error = L_19 ;
return - V_16 ;
} else if ( V_14 -> V_6 -> V_22 == 1 ) {
if ( V_65 )
F_21 ( L_20 ) ;
V_65 = 0 ;
} else if ( ! F_25 ( V_65 ) ) {
V_14 -> V_12 -> error = L_21 ;
return - V_16 ;
} else if ( V_65 < 8 ) {
V_14 -> V_12 -> error = L_22 ;
return - V_16 ;
}
V_14 -> V_20 . V_69 = V_14 -> V_20 . V_53 = V_65 ;
V_31 ++ ;
V_62 -- ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
F_29 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) ;
V_14 -> V_17 [ V_8 ] . V_28 . V_42 = V_70 ;
}
for ( V_8 = 0 ; V_8 < V_62 ; V_8 ++ ) {
if ( ! strcasecmp ( V_31 [ V_8 ] , L_23 ) ) {
V_14 -> V_20 . V_27 = V_70 ;
V_14 -> V_71 |= V_72 ;
continue;
}
if ( ! strcasecmp ( V_31 [ V_8 ] , L_24 ) ) {
V_14 -> V_20 . V_27 = 0 ;
V_14 -> V_71 |= V_73 ;
continue;
}
if ( ( V_8 + 1 ) >= V_62 ) {
V_14 -> V_12 -> error = L_25 ;
return - V_16 ;
}
V_68 = V_31 [ V_8 ++ ] ;
if ( ! strcasecmp ( V_68 , L_26 ) ) {
if ( V_14 -> V_6 -> V_22 != 10 ) {
V_14 -> V_12 -> error = L_27 ;
return - V_16 ;
}
if ( strcmp ( L_2 , V_31 [ V_8 ] ) &&
strcmp ( L_3 , V_31 [ V_8 ] ) &&
strcmp ( L_1 , V_31 [ V_8 ] ) ) {
V_14 -> V_12 -> error = L_28 ;
return - V_16 ;
}
V_63 = V_31 [ V_8 ] ;
V_14 -> V_71 |= V_74 ;
continue;
}
if ( F_28 ( V_31 [ V_8 ] , 10 , & V_65 ) < 0 ) {
V_14 -> V_12 -> error = L_29 ;
return - V_16 ;
}
if ( ! strcasecmp ( V_68 , L_30 ) ) {
if ( V_65 >= V_14 -> V_20 . V_21 ) {
V_14 -> V_12 -> error = L_31 ;
return - V_16 ;
}
F_30 ( V_40 , & V_14 -> V_17 [ V_65 ] . V_28 . V_41 ) ;
V_14 -> V_17 [ V_65 ] . V_28 . V_42 = 0 ;
V_14 -> V_71 |= V_75 ;
} else if ( ! strcasecmp ( V_68 , L_32 ) ) {
if ( V_14 -> V_6 -> V_22 != 1 ) {
V_14 -> V_12 -> error = L_33 ;
return - V_16 ;
}
if ( V_65 >= V_14 -> V_20 . V_21 ) {
V_14 -> V_12 -> error = L_34 ;
return - V_16 ;
}
F_29 ( V_76 , & V_14 -> V_17 [ V_65 ] . V_28 . V_41 ) ;
} else if ( ! strcasecmp ( V_68 , L_35 ) ) {
if ( V_14 -> V_6 -> V_22 != 1 ) {
V_14 -> V_12 -> error = L_36 ;
return - V_16 ;
}
V_14 -> V_71 |= V_77 ;
V_65 /= 2 ;
if ( V_65 > V_78 ) {
V_14 -> V_12 -> error = L_37 ;
return - V_16 ;
}
V_14 -> V_20 . V_54 . V_79 = V_65 ;
} else if ( ! strcasecmp ( V_68 , L_38 ) ) {
V_14 -> V_71 |= V_80 ;
if ( ! V_65 || ( V_65 > V_81 ) ) {
V_14 -> V_12 -> error = L_39 ;
return - V_16 ;
}
V_14 -> V_20 . V_54 . V_82 = V_65 ;
} else if ( ! strcasecmp ( V_68 , L_40 ) ) {
V_14 -> V_71 |= V_83 ;
V_65 /= 2 ;
if ( ( V_14 -> V_6 -> V_22 != 5 ) &&
( V_14 -> V_6 -> V_22 != 6 ) ) {
V_14 -> V_12 -> error = L_41 ;
return - V_16 ;
}
if ( F_31 ( & V_14 -> V_20 , ( int ) V_65 ) ) {
V_14 -> V_12 -> error = L_42 ;
return - V_16 ;
}
} else if ( ! strcasecmp ( V_68 , L_43 ) ) {
V_14 -> V_71 |= V_84 ;
if ( V_65 > V_85 ) {
V_14 -> V_12 -> error = L_44 ;
return - V_16 ;
}
V_14 -> V_20 . V_86 = ( int ) V_65 ;
} else if ( ! strcasecmp ( V_68 , L_45 ) ) {
V_14 -> V_71 |= V_87 ;
if ( V_65 > V_85 ) {
V_14 -> V_12 -> error = L_46 ;
return - V_16 ;
}
V_14 -> V_20 . V_88 = ( int ) V_65 ;
} else if ( ! strcasecmp ( V_68 , L_47 ) ) {
V_14 -> V_71 |= V_89 ;
V_50 = V_65 ;
} else if ( ! strcasecmp ( V_68 , L_48 ) &&
( V_14 -> V_6 -> V_22 == 10 ) ) {
if ( ( V_65 < 2 ) || ( V_65 > 0xFF ) ) {
V_14 -> V_12 -> error = L_49 ;
return - V_16 ;
}
V_14 -> V_71 |= V_90 ;
V_64 = V_65 ;
} else {
F_21 ( L_50 , V_68 ) ;
V_14 -> V_12 -> error = L_51 ;
return - V_16 ;
}
}
if ( F_22 ( V_14 , V_50 ) )
return - V_16 ;
if ( V_14 -> V_20 . V_53 )
V_67 = V_14 -> V_20 . V_53 ;
else
V_67 = V_50 ;
if ( F_32 ( V_14 -> V_12 , V_67 ) )
return - V_16 ;
if ( V_14 -> V_6 -> V_22 == 10 ) {
if ( V_64 > V_14 -> V_20 . V_21 ) {
V_14 -> V_12 -> error = L_52 ;
return - V_16 ;
}
if ( strcmp ( L_2 , V_63 ) && ( V_64 > 2 ) ) {
V_14 -> V_12 -> error = L_53 ;
return - V_16 ;
}
V_66 = V_14 -> V_12 -> V_52 * V_64 ;
F_33 ( V_66 , V_14 -> V_20 . V_21 ) ;
V_14 -> V_20 . V_1 = F_3 ( V_63 ,
V_64 ) ;
V_14 -> V_20 . V_25 = V_14 -> V_20 . V_1 ;
} else if ( ( V_14 -> V_6 -> V_22 > 1 ) &&
F_33 ( V_66 ,
( V_14 -> V_20 . V_21 - V_14 -> V_6 -> V_15 ) ) ) {
V_14 -> V_12 -> error = L_54 ;
return - V_16 ;
}
V_14 -> V_20 . V_91 = V_66 ;
V_14 -> V_20 . V_48 = 0 ;
V_14 -> V_20 . V_47 = 1 ;
return 0 ;
}
static void F_34 ( struct V_92 * V_93 )
{
struct V_10 * V_14 = F_35 ( V_93 , struct V_10 , V_20 . V_94 ) ;
F_36 ( V_14 -> V_12 -> V_38 ) ;
}
static int F_37 ( struct V_95 * V_96 , int V_97 )
{
struct V_10 * V_14 = F_35 ( V_96 , struct V_10 , V_98 ) ;
if ( V_14 -> V_6 -> V_22 == 1 )
return F_38 ( & V_14 -> V_20 , V_97 ) ;
if ( V_14 -> V_6 -> V_22 == 10 )
return F_39 ( & V_14 -> V_20 , V_97 ) ;
return F_40 ( & V_14 -> V_20 , V_97 ) ;
}
static int F_41 ( struct V_99 * V_28 , int V_100 )
{
F_42 ( ! V_28 -> V_39 ) ;
if ( V_28 -> V_101 )
return 0 ;
if ( ! F_43 ( V_28 , 0 , V_100 , V_28 -> V_39 , V_102 , 1 ) ) {
F_21 ( L_55 ,
V_28 -> V_35 ) ;
F_44 ( V_28 -> V_37 , V_28 ) ;
return - V_16 ;
}
V_28 -> V_101 = 1 ;
return 0 ;
}
static void F_45 ( struct V_37 * V_37 , struct V_99 * V_28 )
{
int V_8 ;
T_2 V_103 ;
struct V_104 * V_105 ;
struct V_10 * V_14 = F_35 ( V_37 , struct V_10 , V_20 ) ;
V_105 = F_46 ( V_28 -> V_39 ) ;
V_103 = F_47 ( V_105 -> V_103 ) ;
for ( V_8 = 0 ; V_8 < V_37 -> V_21 ; V_8 ++ )
if ( ! V_14 -> V_17 [ V_8 ] . V_30 ||
F_19 ( V_106 , & ( V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) ) )
V_103 |= ( 1ULL << V_8 ) ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_107 = F_48 ( V_108 ) ;
V_105 -> V_109 = F_48 ( 0 ) ;
V_105 -> V_110 = F_48 ( V_37 -> V_21 ) ;
V_105 -> V_111 = F_48 ( V_28 -> V_35 ) ;
V_105 -> V_112 = F_49 ( V_37 -> V_112 ) ;
V_105 -> V_103 = F_49 ( V_103 ) ;
V_105 -> V_113 = F_49 ( V_28 -> V_42 ) ;
V_105 -> V_114 = F_49 ( V_37 -> V_27 ) ;
V_105 -> V_22 = F_48 ( V_37 -> V_22 ) ;
V_105 -> V_1 = F_48 ( V_37 -> V_1 ) ;
V_105 -> V_115 = F_48 ( V_37 -> V_53 ) ;
}
static int F_50 ( struct V_99 * V_28 , struct V_99 * V_116 )
{
int V_34 ;
struct V_104 * V_105 ;
struct V_104 * V_117 ;
T_2 V_118 , V_119 ;
V_28 -> V_120 = 0 ;
V_28 -> V_121 = sizeof( * V_105 ) ;
V_34 = F_41 ( V_28 , V_28 -> V_121 ) ;
if ( V_34 )
return V_34 ;
V_105 = F_46 ( V_28 -> V_39 ) ;
if ( ( V_105 -> V_107 != F_48 ( V_108 ) ) ||
( ! F_19 ( V_40 , & V_28 -> V_41 ) && ! V_28 -> V_42 ) ) {
F_45 ( V_28 -> V_37 , V_28 ) ;
F_29 ( V_122 , & V_28 -> V_41 ) ;
F_29 ( V_123 , & V_28 -> V_37 -> V_41 ) ;
return V_116 ? 0 : 1 ;
}
if ( ! V_116 )
return 1 ;
V_118 = F_47 ( V_105 -> V_112 ) ;
V_117 = F_46 ( V_116 -> V_39 ) ;
V_119 = F_47 ( V_117 -> V_112 ) ;
return ( V_118 > V_119 ) ? 1 : 0 ;
}
static int F_51 ( struct V_37 * V_37 , struct V_99 * V_28 )
{
int V_124 ;
struct V_10 * V_14 = F_35 ( V_37 , struct V_10 , V_20 ) ;
T_2 V_118 ;
T_2 V_103 ;
struct V_104 * V_105 ;
T_3 V_125 = 0 ;
T_3 V_126 = 0 ;
struct V_99 * V_127 ;
struct V_104 * V_128 ;
V_105 = F_46 ( V_28 -> V_39 ) ;
V_118 = F_47 ( V_105 -> V_112 ) ;
V_103 = F_47 ( V_105 -> V_103 ) ;
V_37 -> V_112 = V_118 ? : 1 ;
if ( F_52 ( V_105 -> V_22 ) != V_37 -> V_22 ) {
F_21 ( L_56 ) ;
return - V_16 ;
}
if ( F_52 ( V_105 -> V_1 ) != V_37 -> V_1 ) {
F_21 ( L_57 ) ;
F_21 ( L_58 , F_52 ( V_105 -> V_1 ) , V_37 -> V_1 ) ;
F_21 ( L_59 ,
F_1 ( F_52 ( V_105 -> V_1 ) ) ,
F_2 ( F_52 ( V_105 -> V_1 ) ) ) ;
F_21 ( L_60 ,
F_1 ( V_37 -> V_1 ) ,
F_2 ( V_37 -> V_1 ) ) ;
return - V_16 ;
}
if ( F_52 ( V_105 -> V_115 ) != V_37 -> V_53 ) {
F_21 ( L_61 ) ;
return - V_16 ;
}
if ( ( V_14 -> V_6 -> V_22 != 1 ) &&
( F_52 ( V_105 -> V_110 ) != V_37 -> V_21 ) ) {
F_21 ( L_62 ) ;
return - V_16 ;
}
if ( ! ( V_14 -> V_71 & ( V_73 | V_72 ) ) )
V_37 -> V_27 = F_47 ( V_105 -> V_114 ) ;
F_53 (r, mddev) {
if ( ! F_19 ( V_40 , & V_127 -> V_41 ) ) {
F_24 ( L_63
L_64 , V_127 -> V_35 ) ;
V_126 ++ ;
} else if ( F_19 ( V_122 , & V_127 -> V_41 ) )
V_125 ++ ;
}
if ( ! V_126 ) {
if ( V_125 == V_37 -> V_21 ) {
F_24 ( L_65 ) ;
F_29 ( V_129 , & V_37 -> V_41 ) ;
} else if ( V_125 ) {
F_21 ( L_66
L_67
L_68 ) ;
return - V_16 ;
}
} else if ( V_125 ) {
F_21 ( L_69
L_70 ) ;
return - V_16 ;
} else if ( V_37 -> V_27 != V_70 ) {
F_21 ( L_71 ) ;
return - V_16 ;
}
F_53 (r, mddev) {
if ( ! V_127 -> V_39 )
continue;
V_128 = F_46 ( V_127 -> V_39 ) ;
V_128 -> V_103 = 0 ;
if ( ! F_19 ( V_122 , & V_127 -> V_41 ) && ( V_127 -> V_35 >= 0 ) ) {
V_124 = F_52 ( V_128 -> V_111 ) ;
if ( V_124 != V_127 -> V_35 ) {
if ( V_14 -> V_6 -> V_22 != 1 ) {
V_14 -> V_12 -> error = L_72
L_73 ;
return - V_16 ;
}
F_24 ( L_74 ,
V_124 , V_127 -> V_35 ) ;
}
if ( V_103 & ( 1 << V_124 ) )
F_29 ( V_106 , & V_127 -> V_41 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_37 * V_37 , struct V_99 * V_28 )
{
struct V_104 * V_105 = F_46 ( V_28 -> V_39 ) ;
if ( ! V_37 -> V_112 && F_51 ( V_37 , V_28 ) )
return - V_16 ;
V_37 -> V_54 . V_130 = 4096 >> 9 ;
V_28 -> V_37 -> V_54 . V_131 = 4096 >> 9 ;
if ( ! F_19 ( V_122 , & V_28 -> V_41 ) ) {
V_28 -> V_42 = F_47 ( V_105 -> V_113 ) ;
if ( V_28 -> V_42 != V_70 )
F_30 ( V_40 , & V_28 -> V_41 ) ;
}
if ( F_19 ( V_106 , & V_28 -> V_41 ) ) {
F_30 ( V_106 , & V_28 -> V_41 ) ;
F_30 ( V_40 , & V_28 -> V_41 ) ;
V_28 -> V_132 = V_28 -> V_35 ;
V_28 -> V_42 = 0 ;
}
F_30 ( V_122 , & V_28 -> V_41 ) ;
return 0 ;
}
static int F_55 ( struct V_11 * V_12 , struct V_10 * V_14 )
{
int V_34 ;
struct V_133 * V_17 ;
struct V_99 * V_28 , * V_134 , * V_135 ;
struct V_37 * V_37 = & V_14 -> V_20 ;
V_135 = NULL ;
F_56 (rdev, tmp, mddev) {
if ( V_14 -> V_71 & V_73 )
continue;
if ( ! V_28 -> V_43 )
continue;
V_34 = F_50 ( V_28 , V_135 ) ;
switch ( V_34 ) {
case 1 :
V_135 = V_28 ;
break;
case 0 :
break;
default:
V_17 = F_35 ( V_28 , struct V_133 , V_28 ) ;
if ( V_17 -> V_29 )
F_12 ( V_12 , V_17 -> V_29 ) ;
V_17 -> V_29 = NULL ;
V_28 -> V_43 = NULL ;
if ( V_28 -> V_39 )
F_57 ( V_28 -> V_39 ) ;
V_28 -> V_39 = NULL ;
V_28 -> V_101 = 0 ;
if ( V_17 -> V_30 )
F_12 ( V_12 , V_17 -> V_30 ) ;
V_17 -> V_30 = NULL ;
V_28 -> V_44 = NULL ;
F_58 ( & V_28 -> V_45 ) ;
}
}
if ( ! V_135 )
return 0 ;
if ( F_26 ( V_14 ) ) {
V_14 -> V_12 -> error = L_75 ;
return - V_16 ;
}
V_12 -> error = L_76 ;
if ( F_54 ( V_37 , V_135 ) )
return - V_16 ;
F_53 (rdev, mddev)
if ( ( V_28 != V_135 ) && F_54 ( V_37 , V_28 ) )
return - V_16 ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 , unsigned V_136 , char * * V_31 )
{
int V_34 ;
struct V_6 * V_137 ;
unsigned long V_62 , V_138 ;
struct V_10 * V_14 = NULL ;
if ( V_136 < 2 ) {
V_12 -> error = L_77 ;
return - V_16 ;
}
V_137 = F_4 ( V_31 [ 0 ] ) ;
if ( ! V_137 ) {
V_12 -> error = L_78 ;
return - V_16 ;
}
V_136 -- ;
V_31 ++ ;
if ( F_28 ( V_31 [ 0 ] , 10 , & V_62 ) < 0 ) {
V_12 -> error = L_79 ;
return - V_16 ;
}
V_136 -- ;
V_31 ++ ;
if ( V_62 + 1 > V_136 ) {
V_12 -> error = L_80 ;
return - V_16 ;
}
if ( ( F_28 ( V_31 [ V_62 ] , 10 , & V_138 ) < 0 ) ||
( V_138 >= V_85 ) ) {
V_12 -> error = L_81 ;
return - V_16 ;
}
V_14 = F_6 ( V_12 , V_137 , ( unsigned ) V_138 ) ;
if ( F_60 ( V_14 ) )
return F_61 ( V_14 ) ;
V_34 = F_27 ( V_14 , V_31 , ( unsigned ) V_62 ) ;
if ( V_34 )
goto V_139;
V_34 = - V_16 ;
V_136 -= V_62 + 1 ;
V_31 += V_62 + 1 ;
if ( V_136 != ( V_138 * 2 ) ) {
V_12 -> error = L_82 ;
goto V_139;
}
V_34 = F_15 ( V_14 , V_31 ) ;
if ( V_34 )
goto V_139;
V_14 -> V_20 . V_140 = F_45 ;
V_34 = F_55 ( V_12 , V_14 ) ;
if ( V_34 )
goto V_139;
F_62 ( & V_14 -> V_20 . V_94 , F_34 ) ;
V_12 -> V_141 = V_14 ;
V_12 -> V_142 = 1 ;
F_63 ( & V_14 -> V_20 . V_143 ) ;
V_34 = F_64 ( & V_14 -> V_20 ) ;
V_14 -> V_20 . V_144 = 0 ;
F_65 ( & V_14 -> V_20 . V_143 ) ;
if ( V_34 ) {
V_12 -> error = L_83 ;
goto V_139;
}
if ( V_12 -> V_52 != V_14 -> V_20 . V_145 ) {
V_12 -> error = L_84 ;
V_34 = - V_16 ;
goto V_146;
}
V_14 -> V_98 . V_147 = F_37 ;
F_66 ( V_12 -> V_38 , & V_14 -> V_98 ) ;
F_67 ( & V_14 -> V_20 ) ;
return 0 ;
V_146:
F_68 ( & V_14 -> V_20 ) ;
V_139:
F_11 ( V_14 ) ;
return V_34 ;
}
static void F_69 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
F_70 ( & V_14 -> V_98 . V_148 ) ;
F_68 ( & V_14 -> V_20 ) ;
F_11 ( V_14 ) ;
}
static int F_71 ( struct V_11 * V_12 , struct V_149 * V_149 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
struct V_37 * V_37 = & V_14 -> V_20 ;
V_37 -> V_150 -> V_151 ( V_37 , V_149 ) ;
return V_152 ;
}
static const char * F_72 ( struct V_37 * V_37 )
{
if ( F_19 ( V_153 , & V_37 -> V_154 ) )
return L_85 ;
if ( F_19 ( V_155 , & V_37 -> V_154 ) ||
( ! V_37 -> V_156 && F_19 ( V_157 , & V_37 -> V_154 ) ) ) {
if ( F_19 ( V_158 , & V_37 -> V_154 ) )
return L_86 ;
if ( F_19 ( V_159 , & V_37 -> V_154 ) ) {
if ( ! F_19 ( V_160 , & V_37 -> V_154 ) )
return L_87 ;
else if ( F_19 ( V_161 , & V_37 -> V_154 ) )
return L_88 ;
return L_89 ;
}
if ( F_19 ( V_162 , & V_37 -> V_154 ) )
return L_90 ;
}
return L_91 ;
}
static void F_73 ( struct V_11 * V_12 , T_4 type ,
unsigned V_163 , char * V_164 , unsigned V_165 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
unsigned V_166 = 1 ;
unsigned V_167 = 0 ;
int V_8 , V_168 = 0 ;
T_1 V_169 ;
switch ( type ) {
case V_170 :
F_74 ( L_92 , V_14 -> V_6 -> V_7 , V_14 -> V_20 . V_21 ) ;
if ( F_19 ( V_155 , & V_14 -> V_20 . V_154 ) )
V_169 = V_14 -> V_20 . V_171 ;
else
V_169 = V_14 -> V_20 . V_27 ;
if ( V_169 >= V_14 -> V_20 . V_172 ) {
V_168 = 1 ;
V_169 = V_14 -> V_20 . V_172 ;
} else if ( F_19 ( V_160 , & V_14 -> V_20 . V_154 ) ) {
V_168 = 1 ;
} else {
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( ! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_168 = 1 ;
}
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( F_19 ( V_106 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_74 ( L_93 ) ;
else if ( ! V_168 ||
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_74 ( L_94 ) ;
else
F_74 ( L_95 ) ;
}
F_74 ( L_96 ,
( unsigned long long ) V_169 ,
( unsigned long long ) V_14 -> V_20 . V_172 ) ;
F_74 ( L_97 , F_72 ( & V_14 -> V_20 ) ) ;
F_74 ( L_98 ,
( unsigned long long )
F_75 ( & V_14 -> V_20 . V_173 ) ) ;
break;
case V_174 :
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( ( V_14 -> V_71 & V_75 ) &&
V_14 -> V_17 [ V_8 ] . V_30 &&
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_166 += 2 ;
if ( V_14 -> V_17 [ V_8 ] . V_30 &&
F_19 ( V_76 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_166 += 2 ;
}
V_166 += ( F_76 ( V_14 -> V_71 & ~ V_75 ) * 2 ) ;
if ( V_14 -> V_71 & ( V_73 | V_72 ) )
V_166 -- ;
F_74 ( L_99 , V_14 -> V_6 -> V_7 ,
V_166 , V_14 -> V_20 . V_53 ) ;
if ( ( V_14 -> V_71 & V_73 ) &&
( V_14 -> V_20 . V_27 == V_70 ) )
F_74 ( L_100 ) ;
if ( V_14 -> V_71 & V_72 )
F_74 ( L_101 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( ( V_14 -> V_71 & V_75 ) &&
V_14 -> V_17 [ V_8 ] . V_30 &&
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_74 ( L_102 , V_8 ) ;
if ( V_14 -> V_71 & V_80 )
F_74 ( L_103 ,
V_14 -> V_20 . V_54 . V_82 ) ;
if ( V_14 -> V_71 & V_84 )
F_74 ( L_104 , V_14 -> V_20 . V_86 ) ;
if ( V_14 -> V_71 & V_87 )
F_74 ( L_105 , V_14 -> V_20 . V_88 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( V_14 -> V_17 [ V_8 ] . V_30 &&
F_19 ( V_76 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_74 ( L_106 , V_8 ) ;
if ( V_14 -> V_71 & V_77 )
F_74 ( L_107 ,
V_14 -> V_20 . V_54 . V_79 ) ;
if ( V_14 -> V_71 & V_83 ) {
struct V_175 * V_176 = V_14 -> V_20 . V_141 ;
F_74 ( L_108 ,
V_176 ? V_176 -> V_177 * 2 : 0 ) ;
}
if ( V_14 -> V_71 & V_89 )
F_74 ( L_109 ,
V_14 -> V_20 . V_54 . V_55 >> 9 ) ;
if ( V_14 -> V_71 & V_90 )
F_74 ( L_110 ,
F_2 ( V_14 -> V_20 . V_1 ) ) ;
if ( V_14 -> V_71 & V_74 )
F_74 ( L_111 ,
F_1 ( V_14 -> V_20 . V_1 ) ) ;
F_74 ( L_112 , V_14 -> V_20 . V_21 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( V_14 -> V_17 [ V_8 ] . V_29 )
F_74 ( L_97 , V_14 -> V_17 [ V_8 ] . V_29 -> V_7 ) ;
else
F_74 ( L_113 ) ;
if ( V_14 -> V_17 [ V_8 ] . V_30 )
F_74 ( L_97 , V_14 -> V_17 [ V_8 ] . V_30 -> V_7 ) ;
else
F_74 ( L_113 ) ;
}
}
}
static int F_77 ( struct V_11 * V_12 , unsigned V_136 , char * * V_31 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
struct V_37 * V_37 = & V_14 -> V_20 ;
if ( ! strcasecmp ( V_31 [ 0 ] , L_86 ) ) {
F_21 ( L_114 ) ;
return - V_16 ;
}
if ( ! V_37 -> V_150 || ! V_37 -> V_150 -> V_178 )
return - V_16 ;
if ( ! strcasecmp ( V_31 [ 0 ] , L_85 ) )
F_29 ( V_153 , & V_37 -> V_154 ) ;
else
F_30 ( V_153 , & V_37 -> V_154 ) ;
if ( ! strcasecmp ( V_31 [ 0 ] , L_91 ) || ! strcasecmp ( V_31 [ 0 ] , L_85 ) ) {
if ( V_37 -> V_179 ) {
F_29 ( V_180 , & V_37 -> V_154 ) ;
F_78 ( V_37 ) ;
}
} else if ( F_19 ( V_155 , & V_37 -> V_154 ) ||
F_19 ( V_157 , & V_37 -> V_154 ) )
return - V_181 ;
else if ( ! strcasecmp ( V_31 [ 0 ] , L_87 ) )
F_29 ( V_157 , & V_37 -> V_154 ) ;
else if ( ! strcasecmp ( V_31 [ 0 ] , L_90 ) ) {
F_29 ( V_162 , & V_37 -> V_154 ) ;
F_29 ( V_157 , & V_37 -> V_154 ) ;
} else {
if ( ! strcasecmp ( V_31 [ 0 ] , L_88 ) )
F_29 ( V_161 , & V_37 -> V_154 ) ;
else if ( ! ! strcasecmp ( V_31 [ 0 ] , L_89 ) )
return - V_16 ;
F_29 ( V_160 , & V_37 -> V_154 ) ;
F_29 ( V_159 , & V_37 -> V_154 ) ;
}
if ( V_37 -> V_156 == 2 ) {
V_37 -> V_156 = 0 ;
if ( ! V_37 -> V_182 )
F_79 ( V_37 -> V_179 ) ;
}
F_29 ( V_157 , & V_37 -> V_154 ) ;
if ( ! V_37 -> V_182 )
F_79 ( V_37 -> V_183 ) ;
return 0 ;
}
static int F_80 ( struct V_11 * V_12 ,
T_5 V_184 , void * V_185 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
unsigned V_8 ;
int V_34 = 0 ;
for ( V_8 = 0 ; ! V_34 && V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( V_14 -> V_17 [ V_8 ] . V_30 )
V_34 = V_184 ( V_12 ,
V_14 -> V_17 [ V_8 ] . V_30 ,
0 ,
V_14 -> V_20 . V_91 ,
V_185 ) ;
return V_34 ;
}
static void F_81 ( struct V_11 * V_12 , struct V_186 * V_187 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
unsigned V_188 = V_14 -> V_20 . V_53 << 9 ;
struct V_175 * V_176 = V_14 -> V_20 . V_141 ;
F_82 ( V_187 , V_188 ) ;
F_83 ( V_187 , V_188 * ( V_176 -> V_21 - V_176 -> V_189 ) ) ;
}
static void F_84 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
F_85 ( & V_14 -> V_20 ) ;
}
static void F_86 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
F_67 ( & V_14 -> V_20 ) ;
}
static void F_87 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_141 ;
F_29 ( V_123 , & V_14 -> V_20 . V_41 ) ;
if ( ! V_14 -> V_190 ) {
F_88 ( & V_14 -> V_20 ) ;
V_14 -> V_190 = 1 ;
}
F_30 ( V_153 , & V_14 -> V_20 . V_154 ) ;
F_89 ( & V_14 -> V_20 ) ;
}
static int T_6 F_90 ( void )
{
F_24 ( L_115 ,
V_191 . V_192 [ 0 ] ,
V_191 . V_192 [ 1 ] ,
V_191 . V_192 [ 2 ] ) ;
return F_91 ( & V_191 ) ;
}
static void T_7 F_92 ( void )
{
F_93 ( & V_191 ) ;
}
