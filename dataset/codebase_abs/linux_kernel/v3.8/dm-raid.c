static unsigned F_1 ( int V_1 )
{
return V_1 & 0xFF ;
}
static int F_2 ( char * V_2 , unsigned V_3 )
{
return ( 1 << 8 ) | ( V_3 & 0xFF ) ;
}
static struct V_4 * F_3 ( char * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_7 ) ; V_6 ++ )
if ( ! strcmp ( V_7 [ V_6 ] . V_5 , V_5 ) )
return & V_7 [ V_6 ] ;
return NULL ;
}
static struct V_8 * F_5 ( struct V_9 * V_10 , struct V_4 * V_4 , unsigned V_11 )
{
unsigned V_6 ;
struct V_8 * V_12 ;
if ( V_11 <= V_4 -> V_13 ) {
V_10 -> error = L_1 ;
return F_6 ( - V_14 ) ;
}
V_12 = F_7 ( sizeof( * V_12 ) + V_11 * sizeof( V_12 -> V_15 [ 0 ] ) , V_16 ) ;
if ( ! V_12 ) {
V_10 -> error = L_2 ;
return F_6 ( - V_17 ) ;
}
F_8 ( & V_12 -> V_18 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_4 = V_4 ;
V_12 -> V_18 . V_19 = V_11 ;
V_12 -> V_18 . V_20 = V_4 -> V_20 ;
V_12 -> V_18 . V_21 = V_12 -> V_18 . V_20 ;
V_12 -> V_18 . V_1 = V_4 -> V_22 ;
V_12 -> V_18 . V_23 = V_12 -> V_18 . V_1 ;
V_12 -> V_18 . V_24 = 0 ;
V_12 -> V_18 . V_25 = 0 ;
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ )
F_9 ( & V_12 -> V_15 [ V_6 ] . V_26 ) ;
return V_12 ;
}
static void F_10 ( struct V_8 * V_12 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
if ( V_12 -> V_15 [ V_6 ] . V_27 )
F_11 ( V_12 -> V_10 , V_12 -> V_15 [ V_6 ] . V_27 ) ;
F_12 ( & V_12 -> V_15 [ V_6 ] . V_26 ) ;
if ( V_12 -> V_15 [ V_6 ] . V_28 )
F_11 ( V_12 -> V_10 , V_12 -> V_15 [ V_6 ] . V_28 ) ;
}
F_13 ( V_12 ) ;
}
static int F_14 ( struct V_8 * V_12 , char * * V_29 )
{
int V_6 ;
int V_30 = 0 ;
int V_31 = 0 ;
int V_32 = 0 ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ , V_29 += 2 ) {
V_12 -> V_15 [ V_6 ] . V_26 . V_33 = V_6 ;
V_12 -> V_15 [ V_6 ] . V_27 = NULL ;
V_12 -> V_15 [ V_6 ] . V_28 = NULL ;
V_12 -> V_15 [ V_6 ] . V_26 . V_34 = 0 ;
V_12 -> V_15 [ V_6 ] . V_26 . V_35 = & V_12 -> V_18 ;
if ( strcmp ( V_29 [ 0 ] , L_3 ) ) {
V_32 = F_15 ( V_12 -> V_10 , V_29 [ 0 ] ,
F_16 ( V_12 -> V_10 -> V_36 ) ,
& V_12 -> V_15 [ V_6 ] . V_27 ) ;
V_12 -> V_10 -> error = L_4 ;
if ( V_32 )
return V_32 ;
V_12 -> V_15 [ V_6 ] . V_26 . V_37 = F_17 ( V_16 ) ;
if ( ! V_12 -> V_15 [ V_6 ] . V_26 . V_37 )
return - V_17 ;
}
if ( ! strcmp ( V_29 [ 1 ] , L_3 ) ) {
if ( ! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) &&
( ! V_12 -> V_15 [ V_6 ] . V_26 . V_40 ) ) {
V_12 -> V_10 -> error = L_5 ;
return - V_14 ;
}
V_12 -> V_10 -> error = L_6 ;
if ( V_12 -> V_15 [ V_6 ] . V_27 )
return - V_14 ;
continue;
}
V_32 = F_15 ( V_12 -> V_10 , V_29 [ 1 ] ,
F_16 ( V_12 -> V_10 -> V_36 ) ,
& V_12 -> V_15 [ V_6 ] . V_28 ) ;
if ( V_32 ) {
V_12 -> V_10 -> error = L_7 ;
return V_32 ;
}
if ( V_12 -> V_15 [ V_6 ] . V_27 ) {
V_31 = 1 ;
V_12 -> V_15 [ V_6 ] . V_26 . V_41 = V_12 -> V_15 [ V_6 ] . V_27 -> V_42 ;
}
V_12 -> V_15 [ V_6 ] . V_26 . V_42 = V_12 -> V_15 [ V_6 ] . V_28 -> V_42 ;
F_19 ( & V_12 -> V_15 [ V_6 ] . V_26 . V_43 , & V_12 -> V_18 . V_44 ) ;
if ( ! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
V_30 ++ ;
}
if ( V_31 ) {
V_12 -> V_18 . V_45 = 0 ;
V_12 -> V_18 . V_46 = 1 ;
V_12 -> V_18 . V_47 = 2 ;
} else if ( V_30 && ! V_12 -> V_18 . V_25 ) {
F_20 ( L_8 ) ;
V_12 -> V_10 -> error = L_7 ;
return - V_14 ;
}
return 0 ;
}
static int F_21 ( struct V_8 * V_12 , unsigned long V_48 )
{
unsigned long V_49 = V_12 -> V_10 -> V_50 / ( 1 << 21 ) ;
if ( ! V_48 ) {
if ( V_49 > ( 1 << 13 ) ) {
if ( V_49 & ( V_49 - 1 ) )
V_48 = 1 << F_22 ( V_48 ) ;
F_23 ( L_9 ,
V_48 ) ;
} else {
F_23 ( L_10 ) ;
V_48 = 1 << 13 ;
}
} else {
if ( V_48 > V_12 -> V_10 -> V_50 ) {
V_12 -> V_10 -> error = L_11 ;
return - V_14 ;
}
if ( V_48 < V_49 ) {
F_20 ( L_12 ,
V_48 , V_49 ) ;
V_12 -> V_10 -> error = L_13 ;
return - V_14 ;
}
if ( ! F_24 ( V_48 ) ) {
V_12 -> V_10 -> error = L_14 ;
return - V_14 ;
}
if ( V_48 < V_12 -> V_18 . V_51 ) {
V_12 -> V_10 -> error = L_15 ;
return - V_14 ;
}
}
V_12 -> V_18 . V_52 . V_53 = ( V_48 << 9 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_12 )
{
unsigned V_6 , V_54 = 0 ;
unsigned V_55 , V_3 , V_56 ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( ! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) ||
! V_12 -> V_15 [ V_6 ] . V_26 . V_37 )
V_54 ++ ;
switch ( V_12 -> V_4 -> V_20 ) {
case 1 :
if ( V_54 >= V_12 -> V_18 . V_19 )
goto V_57;
break;
case 4 :
case 5 :
case 6 :
if ( V_54 > V_12 -> V_4 -> V_13 )
goto V_57;
break;
case 10 :
V_3 = F_1 ( V_12 -> V_18 . V_1 ) ;
if ( V_54 < V_3 )
break;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 * V_3 ; V_6 ++ ) {
if ( ! ( V_6 % V_3 ) )
V_55 = 0 ;
V_56 = V_6 % V_12 -> V_18 . V_19 ;
if ( ( ! V_12 -> V_15 [ V_56 ] . V_26 . V_37 ||
! F_18 ( V_38 , & V_12 -> V_15 [ V_56 ] . V_26 . V_39 ) ) &&
( ++ V_55 >= V_3 ) )
goto V_57;
}
break;
default:
if ( V_54 )
return - V_14 ;
}
return 0 ;
V_57:
return - V_14 ;
}
static int F_26 ( struct V_8 * V_12 , char * * V_29 ,
unsigned V_58 )
{
char * V_59 = L_16 ;
unsigned V_60 = 2 ;
unsigned V_6 ;
unsigned long V_61 , V_48 = 0 ;
T_1 V_62 = V_12 -> V_10 -> V_50 ;
T_1 V_63 ;
char * V_64 ;
if ( ( F_27 ( V_29 [ 0 ] , 10 , & V_61 ) < 0 ) ) {
V_12 -> V_10 -> error = L_17 ;
return - V_14 ;
} else if ( V_12 -> V_4 -> V_20 == 1 ) {
if ( V_61 )
F_20 ( L_18 ) ;
V_61 = 0 ;
} else if ( ! F_24 ( V_61 ) ) {
V_12 -> V_10 -> error = L_19 ;
return - V_14 ;
} else if ( V_61 < 8 ) {
V_12 -> V_10 -> error = L_20 ;
return - V_14 ;
}
V_12 -> V_18 . V_65 = V_12 -> V_18 . V_51 = V_61 ;
V_29 ++ ;
V_58 -- ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
F_28 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) ;
V_12 -> V_15 [ V_6 ] . V_26 . V_40 = V_66 ;
}
for ( V_6 = 0 ; V_6 < V_58 ; V_6 ++ ) {
if ( ! strcasecmp ( V_29 [ V_6 ] , L_21 ) ) {
V_12 -> V_18 . V_25 = V_66 ;
V_12 -> V_67 |= V_68 ;
continue;
}
if ( ! strcasecmp ( V_29 [ V_6 ] , L_22 ) ) {
V_12 -> V_18 . V_25 = 0 ;
V_12 -> V_67 |= V_69 ;
continue;
}
if ( ( V_6 + 1 ) >= V_58 ) {
V_12 -> V_10 -> error = L_23 ;
return - V_14 ;
}
V_64 = V_29 [ V_6 ++ ] ;
if ( ! strcasecmp ( V_64 , L_24 ) ) {
if ( V_12 -> V_4 -> V_20 != 10 ) {
V_12 -> V_10 -> error = L_25 ;
return - V_14 ;
}
if ( strcmp ( L_16 , V_29 [ V_6 ] ) ) {
V_12 -> V_10 -> error = L_26 ;
return - V_14 ;
}
V_59 = V_29 [ V_6 ] ;
V_12 -> V_67 |= V_70 ;
continue;
}
if ( F_27 ( V_29 [ V_6 ] , 10 , & V_61 ) < 0 ) {
V_12 -> V_10 -> error = L_27 ;
return - V_14 ;
}
if ( ! strcasecmp ( V_64 , L_28 ) ) {
if ( V_61 >= V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_29 ;
return - V_14 ;
}
F_29 ( V_38 , & V_12 -> V_15 [ V_61 ] . V_26 . V_39 ) ;
V_12 -> V_15 [ V_61 ] . V_26 . V_40 = 0 ;
V_12 -> V_67 |= V_71 ;
} else if ( ! strcasecmp ( V_64 , L_30 ) ) {
if ( V_12 -> V_4 -> V_20 != 1 ) {
V_12 -> V_10 -> error = L_31 ;
return - V_14 ;
}
if ( V_61 >= V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_32 ;
return - V_14 ;
}
F_28 ( V_72 , & V_12 -> V_15 [ V_61 ] . V_26 . V_39 ) ;
} else if ( ! strcasecmp ( V_64 , L_33 ) ) {
if ( V_12 -> V_4 -> V_20 != 1 ) {
V_12 -> V_10 -> error = L_34 ;
return - V_14 ;
}
V_12 -> V_67 |= V_73 ;
V_61 /= 2 ;
if ( V_61 > V_74 ) {
V_12 -> V_10 -> error = L_35 ;
return - V_14 ;
}
V_12 -> V_18 . V_52 . V_75 = V_61 ;
} else if ( ! strcasecmp ( V_64 , L_36 ) ) {
V_12 -> V_67 |= V_76 ;
if ( ! V_61 || ( V_61 > V_77 ) ) {
V_12 -> V_10 -> error = L_37 ;
return - V_14 ;
}
V_12 -> V_18 . V_52 . V_78 = V_61 ;
} else if ( ! strcasecmp ( V_64 , L_38 ) ) {
V_12 -> V_67 |= V_79 ;
V_61 /= 2 ;
if ( ( V_12 -> V_4 -> V_20 != 5 ) &&
( V_12 -> V_4 -> V_20 != 6 ) ) {
V_12 -> V_10 -> error = L_39 ;
return - V_14 ;
}
if ( F_30 ( & V_12 -> V_18 , ( int ) V_61 ) ) {
V_12 -> V_10 -> error = L_40 ;
return - V_14 ;
}
} else if ( ! strcasecmp ( V_64 , L_41 ) ) {
V_12 -> V_67 |= V_80 ;
if ( V_61 > V_81 ) {
V_12 -> V_10 -> error = L_42 ;
return - V_14 ;
}
V_12 -> V_18 . V_82 = ( int ) V_61 ;
} else if ( ! strcasecmp ( V_64 , L_43 ) ) {
V_12 -> V_67 |= V_83 ;
if ( V_61 > V_81 ) {
V_12 -> V_10 -> error = L_44 ;
return - V_14 ;
}
V_12 -> V_18 . V_84 = ( int ) V_61 ;
} else if ( ! strcasecmp ( V_64 , L_45 ) ) {
V_12 -> V_67 |= V_85 ;
V_48 = V_61 ;
} else if ( ! strcasecmp ( V_64 , L_46 ) &&
( V_12 -> V_4 -> V_20 == 10 ) ) {
if ( ( V_61 < 2 ) || ( V_61 > 0xFF ) ) {
V_12 -> V_10 -> error = L_47 ;
return - V_14 ;
}
V_12 -> V_67 |= V_86 ;
V_60 = V_61 ;
} else {
F_20 ( L_48 , V_64 ) ;
V_12 -> V_10 -> error = L_49 ;
return - V_14 ;
}
}
if ( F_21 ( V_12 , V_48 ) )
return - V_14 ;
if ( V_12 -> V_18 . V_51 )
V_63 = V_12 -> V_18 . V_51 ;
else
V_63 = V_48 ;
if ( F_31 ( V_12 -> V_10 , V_63 ) )
return - V_14 ;
if ( V_12 -> V_4 -> V_20 == 10 ) {
if ( V_60 > V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_50 ;
return - V_14 ;
}
V_62 = V_12 -> V_10 -> V_50 * V_60 ;
F_32 ( V_62 , V_12 -> V_18 . V_19 ) ;
V_12 -> V_18 . V_1 = F_2 ( V_59 ,
V_60 ) ;
V_12 -> V_18 . V_23 = V_12 -> V_18 . V_1 ;
} else if ( ( V_12 -> V_4 -> V_20 > 1 ) &&
F_32 ( V_62 ,
( V_12 -> V_18 . V_19 - V_12 -> V_4 -> V_13 ) ) ) {
V_12 -> V_10 -> error = L_51 ;
return - V_14 ;
}
V_12 -> V_18 . V_87 = V_62 ;
V_12 -> V_18 . V_46 = 0 ;
V_12 -> V_18 . V_45 = 1 ;
return 0 ;
}
static void F_33 ( struct V_88 * V_89 )
{
struct V_8 * V_12 = F_34 ( V_89 , struct V_8 , V_18 . V_90 ) ;
F_35 ( V_12 -> V_10 -> V_36 ) ;
}
static int F_36 ( struct V_91 * V_92 , int V_93 )
{
struct V_8 * V_12 = F_34 ( V_92 , struct V_8 , V_94 ) ;
if ( V_12 -> V_4 -> V_20 == 1 )
return F_37 ( & V_12 -> V_18 , V_93 ) ;
if ( V_12 -> V_4 -> V_20 == 10 )
return F_38 ( & V_12 -> V_18 , V_93 ) ;
return F_39 ( & V_12 -> V_18 , V_93 ) ;
}
static int F_40 ( struct V_95 * V_26 , int V_96 )
{
F_41 ( ! V_26 -> V_37 ) ;
if ( V_26 -> V_97 )
return 0 ;
if ( ! F_42 ( V_26 , 0 , V_96 , V_26 -> V_37 , V_98 , 1 ) ) {
F_20 ( L_52 ,
V_26 -> V_33 ) ;
F_43 ( V_26 -> V_35 , V_26 ) ;
return - V_14 ;
}
V_26 -> V_97 = 1 ;
return 0 ;
}
static void F_44 ( struct V_35 * V_35 , struct V_95 * V_26 )
{
int V_6 ;
T_2 V_99 ;
struct V_100 * V_101 ;
struct V_8 * V_12 = F_34 ( V_35 , struct V_8 , V_18 ) ;
V_101 = F_45 ( V_26 -> V_37 ) ;
V_99 = F_46 ( V_101 -> V_99 ) ;
for ( V_6 = 0 ; V_6 < V_35 -> V_19 ; V_6 ++ )
if ( ! V_12 -> V_15 [ V_6 ] . V_28 ||
F_18 ( V_102 , & ( V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) ) )
V_99 |= ( 1ULL << V_6 ) ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_103 = F_47 ( V_104 ) ;
V_101 -> V_105 = F_47 ( 0 ) ;
V_101 -> V_106 = F_47 ( V_35 -> V_19 ) ;
V_101 -> V_107 = F_47 ( V_26 -> V_33 ) ;
V_101 -> V_108 = F_48 ( V_35 -> V_108 ) ;
V_101 -> V_99 = F_48 ( V_99 ) ;
V_101 -> V_109 = F_48 ( V_26 -> V_40 ) ;
V_101 -> V_110 = F_48 ( V_35 -> V_25 ) ;
V_101 -> V_20 = F_47 ( V_35 -> V_20 ) ;
V_101 -> V_1 = F_47 ( V_35 -> V_1 ) ;
V_101 -> V_111 = F_47 ( V_35 -> V_51 ) ;
}
static int F_49 ( struct V_95 * V_26 , struct V_95 * V_112 )
{
int V_32 ;
struct V_100 * V_101 ;
struct V_100 * V_113 ;
T_2 V_114 , V_115 ;
V_26 -> V_116 = 0 ;
V_26 -> V_117 = sizeof( * V_101 ) ;
V_32 = F_40 ( V_26 , V_26 -> V_117 ) ;
if ( V_32 )
return V_32 ;
V_101 = F_45 ( V_26 -> V_37 ) ;
if ( ( V_101 -> V_103 != F_47 ( V_104 ) ) ||
( ! F_18 ( V_38 , & V_26 -> V_39 ) && ! V_26 -> V_40 ) ) {
F_44 ( V_26 -> V_35 , V_26 ) ;
F_28 ( V_118 , & V_26 -> V_39 ) ;
F_28 ( V_119 , & V_26 -> V_35 -> V_39 ) ;
return V_112 ? 0 : 1 ;
}
if ( ! V_112 )
return 1 ;
V_114 = F_46 ( V_101 -> V_108 ) ;
V_113 = F_45 ( V_112 -> V_37 ) ;
V_115 = F_46 ( V_113 -> V_108 ) ;
return ( V_114 > V_115 ) ? 1 : 0 ;
}
static int F_50 ( struct V_35 * V_35 , struct V_95 * V_26 )
{
int V_120 ;
struct V_8 * V_12 = F_34 ( V_35 , struct V_8 , V_18 ) ;
T_2 V_114 ;
T_2 V_99 ;
struct V_100 * V_101 ;
T_3 V_121 = 0 ;
T_3 V_122 = 0 ;
struct V_95 * V_123 ;
struct V_100 * V_124 ;
V_101 = F_45 ( V_26 -> V_37 ) ;
V_114 = F_46 ( V_101 -> V_108 ) ;
V_99 = F_46 ( V_101 -> V_99 ) ;
V_35 -> V_108 = V_114 ? : 1 ;
if ( ( F_51 ( V_101 -> V_20 ) != V_35 -> V_20 ) ||
( F_51 ( V_101 -> V_1 ) != V_35 -> V_1 ) ||
( F_51 ( V_101 -> V_111 ) != V_35 -> V_51 ) ) {
F_20 ( L_53 ) ;
return - V_14 ;
}
if ( ( V_12 -> V_4 -> V_20 != 1 ) &&
( F_51 ( V_101 -> V_106 ) != V_35 -> V_19 ) ) {
F_20 ( L_53 ) ;
return - V_14 ;
}
if ( ! ( V_12 -> V_67 & ( V_69 | V_68 ) ) )
V_35 -> V_25 = F_46 ( V_101 -> V_110 ) ;
F_52 (r, mddev) {
if ( ! F_18 ( V_38 , & V_123 -> V_39 ) ) {
F_23 ( L_54
L_55 , V_123 -> V_33 ) ;
V_122 ++ ;
} else if ( F_18 ( V_118 , & V_123 -> V_39 ) )
V_121 ++ ;
}
if ( ! V_122 ) {
if ( V_121 == V_35 -> V_19 ) {
F_23 ( L_56 ) ;
F_28 ( V_125 , & V_35 -> V_39 ) ;
} else if ( V_121 ) {
F_20 ( L_57
L_58
L_59 ) ;
return - V_14 ;
}
} else if ( V_121 ) {
F_20 ( L_60
L_61 ) ;
return - V_14 ;
} else if ( V_35 -> V_25 != V_66 ) {
F_20 ( L_62 ) ;
return - V_14 ;
}
F_52 (r, mddev) {
if ( ! V_123 -> V_37 )
continue;
V_124 = F_45 ( V_123 -> V_37 ) ;
V_124 -> V_99 = 0 ;
if ( ! F_18 ( V_118 , & V_123 -> V_39 ) && ( V_123 -> V_33 >= 0 ) ) {
V_120 = F_51 ( V_124 -> V_107 ) ;
if ( V_120 != V_123 -> V_33 ) {
if ( V_12 -> V_4 -> V_20 != 1 ) {
V_12 -> V_10 -> error = L_63
L_64 ;
return - V_14 ;
}
F_23 ( L_65 ,
V_120 , V_123 -> V_33 ) ;
}
if ( V_99 & ( 1 << V_120 ) )
F_28 ( V_102 , & V_123 -> V_39 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_35 * V_35 , struct V_95 * V_26 )
{
struct V_100 * V_101 = F_45 ( V_26 -> V_37 ) ;
if ( ! V_35 -> V_108 && F_50 ( V_35 , V_26 ) )
return - V_14 ;
V_35 -> V_52 . V_126 = 4096 >> 9 ;
V_26 -> V_35 -> V_52 . V_127 = 4096 >> 9 ;
if ( ! F_18 ( V_118 , & V_26 -> V_39 ) ) {
V_26 -> V_40 = F_46 ( V_101 -> V_109 ) ;
if ( V_26 -> V_40 != V_66 )
F_29 ( V_38 , & V_26 -> V_39 ) ;
}
if ( F_18 ( V_102 , & V_26 -> V_39 ) ) {
F_29 ( V_102 , & V_26 -> V_39 ) ;
F_29 ( V_38 , & V_26 -> V_39 ) ;
V_26 -> V_128 = V_26 -> V_33 ;
V_26 -> V_40 = 0 ;
}
F_29 ( V_118 , & V_26 -> V_39 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_10 , struct V_8 * V_12 )
{
int V_32 ;
struct V_129 * V_15 ;
struct V_95 * V_26 , * V_130 , * V_131 ;
struct V_35 * V_35 = & V_12 -> V_18 ;
V_131 = NULL ;
F_55 (rdev, tmp, mddev) {
if ( V_12 -> V_67 & V_69 )
continue;
if ( ! V_26 -> V_41 )
continue;
V_32 = F_49 ( V_26 , V_131 ) ;
switch ( V_32 ) {
case 1 :
V_131 = V_26 ;
break;
case 0 :
break;
default:
V_15 = F_34 ( V_26 , struct V_129 , V_26 ) ;
if ( V_15 -> V_27 )
F_11 ( V_10 , V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
V_26 -> V_41 = NULL ;
if ( V_26 -> V_37 )
F_56 ( V_26 -> V_37 ) ;
V_26 -> V_37 = NULL ;
V_26 -> V_97 = 0 ;
if ( V_15 -> V_28 )
F_11 ( V_10 , V_15 -> V_28 ) ;
V_15 -> V_28 = NULL ;
V_26 -> V_42 = NULL ;
F_57 ( & V_26 -> V_43 ) ;
}
}
if ( ! V_131 )
return 0 ;
if ( F_25 ( V_12 ) ) {
V_12 -> V_10 -> error = L_66 ;
return - V_14 ;
}
V_10 -> error = L_67 ;
if ( F_53 ( V_35 , V_131 ) )
return - V_14 ;
F_52 (rdev, mddev)
if ( ( V_26 != V_131 ) && F_53 ( V_35 , V_26 ) )
return - V_14 ;
return 0 ;
}
static int F_58 ( struct V_9 * V_10 , unsigned V_132 , char * * V_29 )
{
int V_32 ;
struct V_4 * V_133 ;
unsigned long V_58 , V_134 ;
struct V_8 * V_12 = NULL ;
if ( V_132 < 2 ) {
V_10 -> error = L_68 ;
return - V_14 ;
}
V_133 = F_3 ( V_29 [ 0 ] ) ;
if ( ! V_133 ) {
V_10 -> error = L_69 ;
return - V_14 ;
}
V_132 -- ;
V_29 ++ ;
if ( F_27 ( V_29 [ 0 ] , 10 , & V_58 ) < 0 ) {
V_10 -> error = L_70 ;
return - V_14 ;
}
V_132 -- ;
V_29 ++ ;
if ( V_58 + 1 > V_132 ) {
V_10 -> error = L_71 ;
return - V_14 ;
}
if ( ( F_27 ( V_29 [ V_58 ] , 10 , & V_134 ) < 0 ) ||
( V_134 >= V_81 ) ) {
V_10 -> error = L_72 ;
return - V_14 ;
}
V_12 = F_5 ( V_10 , V_133 , ( unsigned ) V_134 ) ;
if ( F_59 ( V_12 ) )
return F_60 ( V_12 ) ;
V_32 = F_26 ( V_12 , V_29 , ( unsigned ) V_58 ) ;
if ( V_32 )
goto V_135;
V_32 = - V_14 ;
V_132 -= V_58 + 1 ;
V_29 += V_58 + 1 ;
if ( V_132 != ( V_134 * 2 ) ) {
V_10 -> error = L_73 ;
goto V_135;
}
V_32 = F_14 ( V_12 , V_29 ) ;
if ( V_32 )
goto V_135;
V_12 -> V_18 . V_136 = F_44 ;
V_32 = F_54 ( V_10 , V_12 ) ;
if ( V_32 )
goto V_135;
F_61 ( & V_12 -> V_18 . V_90 , F_33 ) ;
V_10 -> V_137 = V_12 ;
V_10 -> V_138 = 1 ;
F_62 ( & V_12 -> V_18 . V_139 ) ;
V_32 = F_63 ( & V_12 -> V_18 ) ;
V_12 -> V_18 . V_140 = 0 ;
F_64 ( & V_12 -> V_18 . V_139 ) ;
if ( V_32 ) {
V_10 -> error = L_74 ;
goto V_135;
}
if ( V_10 -> V_50 != V_12 -> V_18 . V_141 ) {
V_10 -> error = L_75 ;
V_32 = - V_14 ;
goto V_142;
}
V_12 -> V_94 . V_143 = F_36 ;
F_65 ( V_10 -> V_36 , & V_12 -> V_94 ) ;
F_66 ( & V_12 -> V_18 ) ;
return 0 ;
V_142:
F_67 ( & V_12 -> V_18 ) ;
V_135:
F_10 ( V_12 ) ;
return V_32 ;
}
static void F_68 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
F_69 ( & V_12 -> V_94 . V_144 ) ;
F_67 ( & V_12 -> V_18 ) ;
F_10 ( V_12 ) ;
}
static int F_70 ( struct V_9 * V_10 , struct V_145 * V_145 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
struct V_35 * V_35 = & V_12 -> V_18 ;
V_35 -> V_146 -> V_147 ( V_35 , V_145 ) ;
return V_148 ;
}
static int F_71 ( struct V_9 * V_10 , T_4 type ,
unsigned V_149 , char * V_150 , unsigned V_151 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
unsigned V_152 = 1 ;
unsigned V_153 = 0 ;
int V_6 , V_154 = 0 ;
T_1 V_155 ;
switch ( type ) {
case V_156 :
F_72 ( L_76 , V_12 -> V_4 -> V_5 , V_12 -> V_18 . V_19 ) ;
if ( F_18 ( V_157 , & V_12 -> V_18 . V_158 ) )
V_155 = V_12 -> V_18 . V_159 ;
else
V_155 = V_12 -> V_18 . V_25 ;
if ( V_155 >= V_12 -> V_18 . V_160 ) {
V_154 = 1 ;
V_155 = V_12 -> V_18 . V_160 ;
} else {
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( ! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
V_154 = 1 ;
}
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
if ( F_18 ( V_102 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_72 ( L_77 ) ;
else if ( ! V_154 ||
! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_72 ( L_78 ) ;
else
F_72 ( L_79 ) ;
}
F_72 ( L_80 ,
( unsigned long long ) V_155 ,
( unsigned long long ) V_12 -> V_18 . V_160 ) ;
break;
case V_161 :
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
if ( ( V_12 -> V_67 & V_71 ) &&
V_12 -> V_15 [ V_6 ] . V_28 &&
! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
V_152 += 2 ;
if ( V_12 -> V_15 [ V_6 ] . V_28 &&
F_18 ( V_72 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
V_152 += 2 ;
}
V_152 += ( F_73 ( V_12 -> V_67 & ~ V_71 ) * 2 ) ;
if ( V_12 -> V_67 & ( V_69 | V_68 ) )
V_152 -- ;
F_72 ( L_81 , V_12 -> V_4 -> V_5 ,
V_152 , V_12 -> V_18 . V_51 ) ;
if ( ( V_12 -> V_67 & V_69 ) &&
( V_12 -> V_18 . V_25 == V_66 ) )
F_72 ( L_82 ) ;
if ( V_12 -> V_67 & V_68 )
F_72 ( L_83 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( ( V_12 -> V_67 & V_71 ) &&
V_12 -> V_15 [ V_6 ] . V_28 &&
! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_72 ( L_84 , V_6 ) ;
if ( V_12 -> V_67 & V_76 )
F_72 ( L_85 ,
V_12 -> V_18 . V_52 . V_78 ) ;
if ( V_12 -> V_67 & V_80 )
F_72 ( L_86 , V_12 -> V_18 . V_82 ) ;
if ( V_12 -> V_67 & V_83 )
F_72 ( L_87 , V_12 -> V_18 . V_84 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( V_12 -> V_15 [ V_6 ] . V_28 &&
F_18 ( V_72 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_72 ( L_88 , V_6 ) ;
if ( V_12 -> V_67 & V_73 )
F_72 ( L_89 ,
V_12 -> V_18 . V_52 . V_75 ) ;
if ( V_12 -> V_67 & V_79 ) {
struct V_162 * V_163 = V_12 -> V_18 . V_137 ;
F_72 ( L_90 ,
V_163 ? V_163 -> V_164 * 2 : 0 ) ;
}
if ( V_12 -> V_67 & V_85 )
F_72 ( L_91 ,
V_12 -> V_18 . V_52 . V_53 >> 9 ) ;
if ( V_12 -> V_67 & V_86 )
F_72 ( L_92 ,
F_1 ( V_12 -> V_18 . V_1 ) ) ;
if ( V_12 -> V_67 & V_70 )
F_72 ( L_93 ) ;
F_72 ( L_94 , V_12 -> V_18 . V_19 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
if ( V_12 -> V_15 [ V_6 ] . V_27 )
F_72 ( L_95 , V_12 -> V_15 [ V_6 ] . V_27 -> V_5 ) ;
else
F_72 ( L_96 ) ;
if ( V_12 -> V_15 [ V_6 ] . V_28 )
F_72 ( L_95 , V_12 -> V_15 [ V_6 ] . V_28 -> V_5 ) ;
else
F_72 ( L_96 ) ;
}
}
return 0 ;
}
static int F_74 ( struct V_9 * V_10 , T_5 V_165 , void * V_166 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
unsigned V_6 ;
int V_32 = 0 ;
for ( V_6 = 0 ; ! V_32 && V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( V_12 -> V_15 [ V_6 ] . V_28 )
V_32 = V_165 ( V_10 ,
V_12 -> V_15 [ V_6 ] . V_28 ,
0 ,
V_12 -> V_18 . V_87 ,
V_166 ) ;
return V_32 ;
}
static void F_75 ( struct V_9 * V_10 , struct V_167 * V_168 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
unsigned V_169 = V_12 -> V_18 . V_51 << 9 ;
struct V_162 * V_163 = V_12 -> V_18 . V_137 ;
F_76 ( V_168 , V_169 ) ;
F_77 ( V_168 , V_169 * ( V_163 -> V_19 - V_163 -> V_170 ) ) ;
}
static void F_78 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
F_79 ( & V_12 -> V_18 ) ;
}
static void F_80 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
F_66 ( & V_12 -> V_18 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_137 ;
F_28 ( V_119 , & V_12 -> V_18 . V_39 ) ;
if ( ! V_12 -> V_171 ) {
F_82 ( & V_12 -> V_18 ) ;
V_12 -> V_171 = 1 ;
}
F_29 ( V_172 , & V_12 -> V_18 . V_158 ) ;
F_83 ( & V_12 -> V_18 ) ;
}
static int T_6 F_84 ( void )
{
return F_85 ( & V_173 ) ;
}
static void T_7 F_86 ( void )
{
F_87 ( & V_173 ) ;
}
