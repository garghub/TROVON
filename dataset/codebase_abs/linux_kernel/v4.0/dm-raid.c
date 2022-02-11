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
unsigned V_57 = 0 , V_3 , V_58 ;
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
return F_38 ( & V_14 -> V_20 , V_97 ) ;
}
static int F_39 ( struct V_99 * V_28 , int V_100 )
{
F_40 ( ! V_28 -> V_39 ) ;
if ( V_28 -> V_101 )
return 0 ;
if ( ! F_41 ( V_28 , 0 , V_100 , V_28 -> V_39 , V_102 , 1 ) ) {
F_21 ( L_55 ,
V_28 -> V_35 ) ;
F_42 ( V_28 -> V_37 , V_28 ) ;
return - V_16 ;
}
V_28 -> V_101 = 1 ;
return 0 ;
}
static void F_43 ( struct V_37 * V_37 , struct V_99 * V_28 )
{
int V_8 ;
T_2 V_103 ;
struct V_104 * V_105 ;
struct V_10 * V_14 = F_35 ( V_37 , struct V_10 , V_20 ) ;
V_105 = F_44 ( V_28 -> V_39 ) ;
V_103 = F_45 ( V_105 -> V_103 ) ;
for ( V_8 = 0 ; V_8 < V_37 -> V_21 ; V_8 ++ )
if ( ! V_14 -> V_17 [ V_8 ] . V_30 ||
F_19 ( V_106 , & ( V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) ) )
V_103 |= ( 1ULL << V_8 ) ;
memset ( V_105 + 1 , 0 , V_28 -> V_107 - sizeof( * V_105 ) ) ;
V_105 -> V_108 = F_46 ( V_109 ) ;
V_105 -> V_110 = F_46 ( 0 ) ;
V_105 -> V_111 = F_46 ( V_37 -> V_21 ) ;
V_105 -> V_112 = F_46 ( V_28 -> V_35 ) ;
V_105 -> V_113 = F_47 ( V_37 -> V_113 ) ;
V_105 -> V_103 = F_47 ( V_103 ) ;
V_105 -> V_114 = F_47 ( V_28 -> V_42 ) ;
V_105 -> V_115 = F_47 ( V_37 -> V_27 ) ;
V_105 -> V_22 = F_46 ( V_37 -> V_22 ) ;
V_105 -> V_1 = F_46 ( V_37 -> V_1 ) ;
V_105 -> V_116 = F_46 ( V_37 -> V_53 ) ;
}
static int F_48 ( struct V_99 * V_28 , struct V_99 * V_117 )
{
int V_34 ;
struct V_104 * V_105 ;
struct V_104 * V_118 ;
T_2 V_119 , V_120 ;
V_28 -> V_121 = 0 ;
V_28 -> V_107 = F_49 ( V_28 -> V_43 ) ;
if ( V_28 -> V_107 < sizeof( * V_105 ) || V_28 -> V_107 > V_122 ) {
F_21 ( L_56 ) ;
return - V_16 ;
}
V_34 = F_39 ( V_28 , V_28 -> V_107 ) ;
if ( V_34 )
return V_34 ;
V_105 = F_44 ( V_28 -> V_39 ) ;
if ( ( V_105 -> V_108 != F_46 ( V_109 ) ) ||
( ! F_19 ( V_40 , & V_28 -> V_41 ) && ! V_28 -> V_42 ) ) {
F_43 ( V_28 -> V_37 , V_28 ) ;
F_29 ( V_123 , & V_28 -> V_41 ) ;
F_29 ( V_124 , & V_28 -> V_37 -> V_41 ) ;
return V_117 ? 0 : 1 ;
}
if ( ! V_117 )
return 1 ;
V_119 = F_45 ( V_105 -> V_113 ) ;
V_118 = F_44 ( V_117 -> V_39 ) ;
V_120 = F_45 ( V_118 -> V_113 ) ;
return ( V_119 > V_120 ) ? 1 : 0 ;
}
static int F_50 ( struct V_37 * V_37 , struct V_99 * V_28 )
{
int V_125 ;
struct V_10 * V_14 = F_35 ( V_37 , struct V_10 , V_20 ) ;
T_2 V_119 ;
T_2 V_103 ;
struct V_104 * V_105 ;
T_3 V_126 = 0 ;
T_3 V_127 = 0 ;
struct V_99 * V_128 ;
struct V_104 * V_129 ;
V_105 = F_44 ( V_28 -> V_39 ) ;
V_119 = F_45 ( V_105 -> V_113 ) ;
V_103 = F_45 ( V_105 -> V_103 ) ;
V_37 -> V_113 = V_119 ? : 1 ;
if ( F_51 ( V_105 -> V_22 ) != V_37 -> V_22 ) {
F_21 ( L_57 ) ;
return - V_16 ;
}
if ( F_51 ( V_105 -> V_1 ) != V_37 -> V_1 ) {
F_21 ( L_58 ) ;
F_21 ( L_59 , F_51 ( V_105 -> V_1 ) , V_37 -> V_1 ) ;
F_21 ( L_60 ,
F_1 ( F_51 ( V_105 -> V_1 ) ) ,
F_2 ( F_51 ( V_105 -> V_1 ) ) ) ;
F_21 ( L_61 ,
F_1 ( V_37 -> V_1 ) ,
F_2 ( V_37 -> V_1 ) ) ;
return - V_16 ;
}
if ( F_51 ( V_105 -> V_116 ) != V_37 -> V_53 ) {
F_21 ( L_62 ) ;
return - V_16 ;
}
if ( ( V_14 -> V_6 -> V_22 != 1 ) &&
( F_51 ( V_105 -> V_111 ) != V_37 -> V_21 ) ) {
F_21 ( L_63 ) ;
return - V_16 ;
}
if ( ! ( V_14 -> V_71 & ( V_73 | V_72 ) ) )
V_37 -> V_27 = F_45 ( V_105 -> V_115 ) ;
F_52 (r, mddev) {
if ( ! F_19 ( V_40 , & V_128 -> V_41 ) ) {
F_24 ( L_64
L_65 , V_128 -> V_35 ) ;
V_127 ++ ;
} else if ( F_19 ( V_123 , & V_128 -> V_41 ) )
V_126 ++ ;
}
if ( ! V_127 ) {
if ( V_126 == V_37 -> V_21 ) {
F_24 ( L_66 ) ;
F_29 ( V_130 , & V_37 -> V_41 ) ;
} else if ( V_126 ) {
F_21 ( L_67
L_68
L_69 ) ;
return - V_16 ;
}
} else if ( V_126 ) {
F_21 ( L_70
L_71 ) ;
return - V_16 ;
} else if ( V_37 -> V_27 != V_70 ) {
F_21 ( L_72 ) ;
return - V_16 ;
}
F_52 (r, mddev) {
if ( ! V_128 -> V_39 )
continue;
V_129 = F_44 ( V_128 -> V_39 ) ;
V_129 -> V_103 = 0 ;
if ( ! F_19 ( V_123 , & V_128 -> V_41 ) && ( V_128 -> V_35 >= 0 ) ) {
V_125 = F_51 ( V_129 -> V_112 ) ;
if ( V_125 != V_128 -> V_35 ) {
if ( V_14 -> V_6 -> V_22 != 1 ) {
V_14 -> V_12 -> error = L_73
L_74 ;
return - V_16 ;
}
F_24 ( L_75 ,
V_125 , V_128 -> V_35 ) ;
}
if ( V_103 & ( 1 << V_125 ) )
F_29 ( V_106 , & V_128 -> V_41 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_37 * V_37 , struct V_99 * V_28 )
{
struct V_104 * V_105 = F_44 ( V_28 -> V_39 ) ;
if ( ! V_37 -> V_113 && F_50 ( V_37 , V_28 ) )
return - V_16 ;
V_37 -> V_54 . V_131 = 4096 >> 9 ;
V_28 -> V_37 -> V_54 . V_132 = 4096 >> 9 ;
if ( ! F_19 ( V_123 , & V_28 -> V_41 ) ) {
V_28 -> V_42 = F_45 ( V_105 -> V_114 ) ;
if ( V_28 -> V_42 != V_70 )
F_30 ( V_40 , & V_28 -> V_41 ) ;
}
if ( F_19 ( V_106 , & V_28 -> V_41 ) ) {
F_30 ( V_106 , & V_28 -> V_41 ) ;
F_30 ( V_40 , & V_28 -> V_41 ) ;
V_28 -> V_133 = V_28 -> V_35 ;
V_28 -> V_42 = 0 ;
}
F_30 ( V_123 , & V_28 -> V_41 ) ;
return 0 ;
}
static int F_54 ( struct V_11 * V_12 , struct V_10 * V_14 )
{
int V_34 ;
struct V_134 * V_17 ;
struct V_99 * V_28 , * V_135 , * V_136 ;
struct V_37 * V_37 = & V_14 -> V_20 ;
V_136 = NULL ;
F_55 (rdev, tmp, mddev) {
if ( V_14 -> V_71 & V_73 )
continue;
if ( ! V_28 -> V_43 )
continue;
V_34 = F_48 ( V_28 , V_136 ) ;
switch ( V_34 ) {
case 1 :
V_136 = V_28 ;
break;
case 0 :
break;
default:
V_17 = F_35 ( V_28 , struct V_134 , V_28 ) ;
if ( V_17 -> V_29 )
F_12 ( V_12 , V_17 -> V_29 ) ;
V_17 -> V_29 = NULL ;
V_28 -> V_43 = NULL ;
if ( V_28 -> V_39 )
F_56 ( V_28 -> V_39 ) ;
V_28 -> V_39 = NULL ;
V_28 -> V_101 = 0 ;
if ( V_17 -> V_30 )
F_12 ( V_12 , V_17 -> V_30 ) ;
V_17 -> V_30 = NULL ;
V_28 -> V_44 = NULL ;
F_57 ( & V_28 -> V_45 ) ;
}
}
if ( ! V_136 )
return 0 ;
if ( F_26 ( V_14 ) ) {
V_14 -> V_12 -> error = L_76 ;
return - V_16 ;
}
V_12 -> error = L_77 ;
if ( F_53 ( V_37 , V_136 ) )
return - V_16 ;
F_52 (rdev, mddev)
if ( ( V_28 != V_136 ) && F_53 ( V_37 , V_28 ) )
return - V_16 ;
return 0 ;
}
static void F_58 ( struct V_11 * V_12 , struct V_10 * V_14 )
{
int V_8 ;
bool V_137 ;
V_12 -> V_138 = false ;
V_137 = ( V_14 -> V_20 . V_22 == 4 || V_14 -> V_20 . V_22 == 5 || V_14 -> V_20 . V_22 == 6 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
struct V_139 * V_140 ;
if ( ! V_14 -> V_17 [ V_8 ] . V_28 . V_44 )
continue;
V_140 = F_59 ( V_14 -> V_17 [ V_8 ] . V_28 . V_44 ) ;
if ( ! V_140 || ! F_60 ( V_140 ) )
return;
if ( V_137 ) {
if ( ! V_140 -> V_141 . V_142 )
return;
if ( ! V_143 ) {
F_21 ( L_78 ) ;
F_21 ( L_79 ) ;
return;
}
}
}
V_12 -> V_138 = true ;
V_12 -> V_144 = ! ! ( V_14 -> V_20 . V_22 == 1 || V_14 -> V_20 . V_22 == 10 ) ;
V_12 -> V_145 = 1 ;
}
static int F_61 ( struct V_11 * V_12 , unsigned V_146 , char * * V_31 )
{
int V_34 ;
struct V_6 * V_147 ;
unsigned long V_62 , V_148 ;
struct V_10 * V_14 = NULL ;
if ( V_146 < 2 ) {
V_12 -> error = L_80 ;
return - V_16 ;
}
V_147 = F_4 ( V_31 [ 0 ] ) ;
if ( ! V_147 ) {
V_12 -> error = L_81 ;
return - V_16 ;
}
V_146 -- ;
V_31 ++ ;
if ( F_28 ( V_31 [ 0 ] , 10 , & V_62 ) < 0 ) {
V_12 -> error = L_82 ;
return - V_16 ;
}
V_146 -- ;
V_31 ++ ;
if ( V_62 >= V_146 ) {
V_12 -> error = L_83 ;
return - V_16 ;
}
if ( ( F_28 ( V_31 [ V_62 ] , 10 , & V_148 ) < 0 ) ||
( V_148 >= V_85 ) ) {
V_12 -> error = L_84 ;
return - V_16 ;
}
V_146 -= V_62 + 1 ;
if ( V_146 != ( V_148 * 2 ) ) {
V_12 -> error = L_85 ;
return - V_16 ;
}
V_14 = F_6 ( V_12 , V_147 , ( unsigned ) V_148 ) ;
if ( F_62 ( V_14 ) )
return F_63 ( V_14 ) ;
V_34 = F_27 ( V_14 , V_31 , ( unsigned ) V_62 ) ;
if ( V_34 )
goto V_149;
V_31 += V_62 + 1 ;
V_34 = F_15 ( V_14 , V_31 ) ;
if ( V_34 )
goto V_149;
V_14 -> V_20 . V_150 = F_43 ;
V_34 = F_54 ( V_12 , V_14 ) ;
if ( V_34 )
goto V_149;
F_64 ( & V_14 -> V_20 . V_94 , F_34 ) ;
V_12 -> V_151 = V_14 ;
V_12 -> V_152 = 1 ;
F_58 ( V_12 , V_14 ) ;
F_65 ( & V_14 -> V_20 . V_153 ) ;
V_34 = F_66 ( & V_14 -> V_20 ) ;
V_14 -> V_20 . V_154 = 0 ;
F_67 ( & V_14 -> V_20 . V_153 ) ;
if ( V_34 ) {
V_12 -> error = L_86 ;
goto V_149;
}
if ( V_12 -> V_52 != V_14 -> V_20 . V_155 ) {
V_12 -> error = L_87 ;
V_34 = - V_16 ;
goto V_156;
}
V_14 -> V_98 . V_157 = F_37 ;
F_68 ( V_12 -> V_38 , & V_14 -> V_98 ) ;
F_69 ( & V_14 -> V_20 ) ;
return 0 ;
V_156:
F_70 ( & V_14 -> V_20 ) ;
V_149:
F_11 ( V_14 ) ;
return V_34 ;
}
static void F_71 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
F_72 ( & V_14 -> V_98 . V_158 ) ;
F_70 ( & V_14 -> V_20 ) ;
F_11 ( V_14 ) ;
}
static int F_73 ( struct V_11 * V_12 , struct V_159 * V_159 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
struct V_37 * V_37 = & V_14 -> V_20 ;
V_37 -> V_160 -> V_161 ( V_37 , V_159 ) ;
return V_162 ;
}
static const char * F_74 ( struct V_37 * V_37 )
{
if ( F_19 ( V_163 , & V_37 -> V_164 ) )
return L_88 ;
if ( F_19 ( V_165 , & V_37 -> V_164 ) ||
( ! V_37 -> V_166 && F_19 ( V_167 , & V_37 -> V_164 ) ) ) {
if ( F_19 ( V_168 , & V_37 -> V_164 ) )
return L_89 ;
if ( F_19 ( V_169 , & V_37 -> V_164 ) ) {
if ( ! F_19 ( V_170 , & V_37 -> V_164 ) )
return L_90 ;
else if ( F_19 ( V_171 , & V_37 -> V_164 ) )
return L_91 ;
return L_92 ;
}
if ( F_19 ( V_172 , & V_37 -> V_164 ) )
return L_93 ;
}
return L_94 ;
}
static void F_75 ( struct V_11 * V_12 , T_4 type ,
unsigned V_173 , char * V_174 , unsigned V_175 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
unsigned V_176 = 1 ;
unsigned V_177 = 0 ;
int V_8 , V_178 = 0 ;
T_1 V_179 ;
switch ( type ) {
case V_180 :
F_76 ( L_95 , V_14 -> V_6 -> V_7 , V_14 -> V_20 . V_21 ) ;
if ( F_19 ( V_165 , & V_14 -> V_20 . V_164 ) )
V_179 = V_14 -> V_20 . V_181 ;
else
V_179 = V_14 -> V_20 . V_27 ;
if ( V_179 >= V_14 -> V_20 . V_182 ) {
V_178 = 1 ;
V_179 = V_14 -> V_20 . V_182 ;
} else if ( F_19 ( V_170 , & V_14 -> V_20 . V_164 ) ) {
V_178 = 1 ;
} else {
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( ! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_178 = 1 ;
}
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( F_19 ( V_106 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_76 ( L_96 ) ;
else if ( ! V_178 ||
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_76 ( L_97 ) ;
else
F_76 ( L_98 ) ;
}
F_76 ( L_99 ,
( unsigned long long ) V_179 ,
( unsigned long long ) V_14 -> V_20 . V_182 ) ;
F_76 ( L_100 , F_74 ( & V_14 -> V_20 ) ) ;
F_76 ( L_101 ,
( strcmp ( V_14 -> V_20 . V_183 , L_91 ) ) ? 0 :
( unsigned long long )
F_77 ( & V_14 -> V_20 . V_184 ) ) ;
break;
case V_185 :
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( ( V_14 -> V_71 & V_75 ) &&
V_14 -> V_17 [ V_8 ] . V_30 &&
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_176 += 2 ;
if ( V_14 -> V_17 [ V_8 ] . V_30 &&
F_19 ( V_76 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
V_176 += 2 ;
}
V_176 += ( F_78 ( V_14 -> V_71 & ~ V_75 ) * 2 ) ;
if ( V_14 -> V_71 & ( V_73 | V_72 ) )
V_176 -- ;
F_76 ( L_102 , V_14 -> V_6 -> V_7 ,
V_176 , V_14 -> V_20 . V_53 ) ;
if ( ( V_14 -> V_71 & V_73 ) &&
( V_14 -> V_20 . V_27 == V_70 ) )
F_76 ( L_103 ) ;
if ( V_14 -> V_71 & V_72 )
F_76 ( L_104 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( ( V_14 -> V_71 & V_75 ) &&
V_14 -> V_17 [ V_8 ] . V_30 &&
! F_19 ( V_40 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_76 ( L_105 , V_8 ) ;
if ( V_14 -> V_71 & V_80 )
F_76 ( L_106 ,
V_14 -> V_20 . V_54 . V_82 ) ;
if ( V_14 -> V_71 & V_84 )
F_76 ( L_107 , V_14 -> V_20 . V_86 ) ;
if ( V_14 -> V_71 & V_87 )
F_76 ( L_108 , V_14 -> V_20 . V_88 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( V_14 -> V_17 [ V_8 ] . V_30 &&
F_19 ( V_76 , & V_14 -> V_17 [ V_8 ] . V_28 . V_41 ) )
F_76 ( L_109 , V_8 ) ;
if ( V_14 -> V_71 & V_77 )
F_76 ( L_110 ,
V_14 -> V_20 . V_54 . V_79 ) ;
if ( V_14 -> V_71 & V_83 ) {
struct V_186 * V_187 = V_14 -> V_20 . V_151 ;
F_76 ( L_111 ,
V_187 ? V_187 -> V_188 * 2 : 0 ) ;
}
if ( V_14 -> V_71 & V_89 )
F_76 ( L_112 ,
V_14 -> V_20 . V_54 . V_55 >> 9 ) ;
if ( V_14 -> V_71 & V_90 )
F_76 ( L_113 ,
F_2 ( V_14 -> V_20 . V_1 ) ) ;
if ( V_14 -> V_71 & V_74 )
F_76 ( L_114 ,
F_1 ( V_14 -> V_20 . V_1 ) ) ;
F_76 ( L_115 , V_14 -> V_20 . V_21 ) ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
if ( V_14 -> V_17 [ V_8 ] . V_29 )
F_76 ( L_100 , V_14 -> V_17 [ V_8 ] . V_29 -> V_7 ) ;
else
F_76 ( L_116 ) ;
if ( V_14 -> V_17 [ V_8 ] . V_30 )
F_76 ( L_100 , V_14 -> V_17 [ V_8 ] . V_30 -> V_7 ) ;
else
F_76 ( L_116 ) ;
}
}
}
static int F_79 ( struct V_11 * V_12 , unsigned V_146 , char * * V_31 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
struct V_37 * V_37 = & V_14 -> V_20 ;
if ( ! strcasecmp ( V_31 [ 0 ] , L_89 ) ) {
F_21 ( L_117 ) ;
return - V_16 ;
}
if ( ! V_37 -> V_160 || ! V_37 -> V_160 -> V_189 )
return - V_16 ;
if ( ! strcasecmp ( V_31 [ 0 ] , L_88 ) )
F_29 ( V_163 , & V_37 -> V_164 ) ;
else
F_30 ( V_163 , & V_37 -> V_164 ) ;
if ( ! strcasecmp ( V_31 [ 0 ] , L_94 ) || ! strcasecmp ( V_31 [ 0 ] , L_88 ) ) {
if ( V_37 -> V_190 ) {
F_29 ( V_191 , & V_37 -> V_164 ) ;
F_80 ( V_37 ) ;
}
} else if ( F_19 ( V_165 , & V_37 -> V_164 ) ||
F_19 ( V_167 , & V_37 -> V_164 ) )
return - V_192 ;
else if ( ! strcasecmp ( V_31 [ 0 ] , L_90 ) )
F_29 ( V_167 , & V_37 -> V_164 ) ;
else if ( ! strcasecmp ( V_31 [ 0 ] , L_93 ) ) {
F_29 ( V_172 , & V_37 -> V_164 ) ;
F_29 ( V_167 , & V_37 -> V_164 ) ;
} else {
if ( ! strcasecmp ( V_31 [ 0 ] , L_91 ) )
F_29 ( V_171 , & V_37 -> V_164 ) ;
else if ( ! ! strcasecmp ( V_31 [ 0 ] , L_92 ) )
return - V_16 ;
F_29 ( V_170 , & V_37 -> V_164 ) ;
F_29 ( V_169 , & V_37 -> V_164 ) ;
}
if ( V_37 -> V_166 == 2 ) {
V_37 -> V_166 = 0 ;
if ( ! V_37 -> V_193 )
F_81 ( V_37 -> V_190 ) ;
}
F_29 ( V_167 , & V_37 -> V_164 ) ;
if ( ! V_37 -> V_193 )
F_81 ( V_37 -> V_194 ) ;
return 0 ;
}
static int F_82 ( struct V_11 * V_12 ,
T_5 V_195 , void * V_196 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
unsigned V_8 ;
int V_34 = 0 ;
for ( V_8 = 0 ; ! V_34 && V_8 < V_14 -> V_20 . V_21 ; V_8 ++ )
if ( V_14 -> V_17 [ V_8 ] . V_30 )
V_34 = V_195 ( V_12 ,
V_14 -> V_17 [ V_8 ] . V_30 ,
0 ,
V_14 -> V_20 . V_91 ,
V_196 ) ;
return V_34 ;
}
static void F_83 ( struct V_11 * V_12 , struct V_197 * V_141 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
unsigned V_198 = V_14 -> V_20 . V_53 << 9 ;
struct V_186 * V_187 = V_14 -> V_20 . V_151 ;
F_84 ( V_141 , V_198 ) ;
F_85 ( V_141 , V_198 * ( V_187 -> V_21 - V_187 -> V_199 ) ) ;
}
static void F_86 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
F_87 ( & V_14 -> V_20 ) ;
}
static void F_88 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
F_69 ( & V_14 -> V_20 ) ;
}
static void F_89 ( struct V_10 * V_14 )
{
int V_8 ;
T_2 V_103 , V_200 = 0 ;
unsigned long V_41 ;
struct V_104 * V_105 ;
struct V_99 * V_128 ;
for ( V_8 = 0 ; V_8 < V_14 -> V_20 . V_21 ; V_8 ++ ) {
V_128 = & V_14 -> V_17 [ V_8 ] . V_28 ;
if ( F_19 ( V_106 , & V_128 -> V_41 ) && V_128 -> V_39 &&
F_41 ( V_128 , 0 , V_128 -> V_107 , V_128 -> V_39 , V_102 , 1 ) ) {
F_24 ( L_118
L_119 ,
V_14 -> V_6 -> V_7 , V_8 ) ;
if ( ( V_128 -> V_35 >= 0 ) &&
( V_128 -> V_37 -> V_160 -> V_201 ( V_128 -> V_37 , V_128 ) != 0 ) )
continue;
V_128 -> V_35 = V_8 ;
V_128 -> V_133 = V_8 ;
V_41 = V_128 -> V_41 ;
F_30 ( V_106 , & V_128 -> V_41 ) ;
F_30 ( V_202 , & V_128 -> V_41 ) ;
F_30 ( V_40 , & V_128 -> V_41 ) ;
if ( V_128 -> V_37 -> V_160 -> V_203 ( V_128 -> V_37 , V_128 ) ) {
V_128 -> V_35 = - 1 ;
V_128 -> V_133 = - 1 ;
V_128 -> V_41 = V_41 ;
} else {
V_128 -> V_42 = 0 ;
V_200 |= 1 << V_8 ;
}
}
}
if ( V_200 ) {
F_52 (r, &rs->md) {
V_105 = F_44 ( V_128 -> V_39 ) ;
V_103 = F_45 ( V_105 -> V_103 ) ;
V_103 &= ~ V_200 ;
V_105 -> V_103 = F_47 ( V_103 ) ;
}
}
}
static void F_90 ( struct V_11 * V_12 )
{
struct V_10 * V_14 = V_12 -> V_151 ;
F_29 ( V_124 , & V_14 -> V_20 . V_41 ) ;
if ( ! V_14 -> V_204 ) {
F_91 ( & V_14 -> V_20 ) ;
V_14 -> V_204 = 1 ;
} else {
F_89 ( V_14 ) ;
}
F_30 ( V_163 , & V_14 -> V_20 . V_164 ) ;
F_92 ( & V_14 -> V_20 ) ;
}
static int T_6 F_93 ( void )
{
F_24 ( L_120 ,
V_205 . V_206 [ 0 ] ,
V_205 . V_206 [ 1 ] ,
V_205 . V_206 [ 2 ] ) ;
return F_94 ( & V_205 ) ;
}
static void T_7 F_95 ( void )
{
F_96 ( & V_205 ) ;
}
