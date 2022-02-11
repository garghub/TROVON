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
F_22 ( L_9 ,
V_48 ) ;
V_48 = V_49 ;
} else {
F_22 ( L_10 ) ;
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
if ( ! F_23 ( V_48 ) ) {
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
static int F_24 ( struct V_8 * V_12 , char * * V_29 ,
unsigned V_54 )
{
char * V_55 = L_16 ;
unsigned V_56 = 2 ;
unsigned V_6 , V_57 = 0 ;
unsigned long V_58 , V_48 = 0 ;
T_1 V_59 = V_12 -> V_10 -> V_50 ;
T_1 V_60 ;
char * V_61 ;
if ( ( F_25 ( V_29 [ 0 ] , 10 , & V_58 ) < 0 ) ) {
V_12 -> V_10 -> error = L_17 ;
return - V_14 ;
} else if ( V_12 -> V_4 -> V_20 == 1 ) {
if ( V_58 )
F_20 ( L_18 ) ;
V_58 = 0 ;
} else if ( ! F_23 ( V_58 ) ) {
V_12 -> V_10 -> error = L_19 ;
return - V_14 ;
} else if ( V_58 < 8 ) {
V_12 -> V_10 -> error = L_20 ;
return - V_14 ;
}
V_12 -> V_18 . V_62 = V_12 -> V_18 . V_51 = V_58 ;
V_29 ++ ;
V_54 -- ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
F_26 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) ;
V_12 -> V_15 [ V_6 ] . V_26 . V_40 = V_63 ;
}
for ( V_6 = 0 ; V_6 < V_54 ; V_6 ++ ) {
if ( ! strcasecmp ( V_29 [ V_6 ] , L_21 ) ) {
V_12 -> V_18 . V_25 = V_63 ;
V_12 -> V_64 |= V_65 ;
continue;
}
if ( ! strcasecmp ( V_29 [ V_6 ] , L_22 ) ) {
V_12 -> V_18 . V_25 = 0 ;
V_12 -> V_64 |= V_66 ;
continue;
}
if ( ( V_6 + 1 ) >= V_54 ) {
V_12 -> V_10 -> error = L_23 ;
return - V_14 ;
}
V_61 = V_29 [ V_6 ++ ] ;
if ( ! strcasecmp ( V_61 , L_24 ) ) {
if ( V_12 -> V_4 -> V_20 != 10 ) {
V_12 -> V_10 -> error = L_25 ;
return - V_14 ;
}
if ( strcmp ( L_16 , V_29 [ V_6 ] ) ) {
V_12 -> V_10 -> error = L_26 ;
return - V_14 ;
}
V_55 = V_29 [ V_6 ] ;
V_12 -> V_64 |= V_67 ;
continue;
}
if ( F_25 ( V_29 [ V_6 ] , 10 , & V_58 ) < 0 ) {
V_12 -> V_10 -> error = L_27 ;
return - V_14 ;
}
if ( ! strcasecmp ( V_61 , L_28 ) ) {
V_57 ++ ;
switch ( V_12 -> V_4 -> V_20 ) {
case 1 :
if ( V_57 >= V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_29 ;
return - V_14 ;
}
break;
case 4 :
case 5 :
case 6 :
if ( V_57 > V_12 -> V_4 -> V_13 ) {
V_12 -> V_10 -> error = L_30 ;
return - V_14 ;
}
break;
case 10 :
default:
F_20 ( L_31 , V_12 -> V_4 -> V_5 ) ;
V_12 -> V_10 -> error = L_32 ;
return - V_14 ;
}
if ( V_58 > V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_33 ;
return - V_14 ;
}
F_27 ( V_38 , & V_12 -> V_15 [ V_58 ] . V_26 . V_39 ) ;
V_12 -> V_15 [ V_58 ] . V_26 . V_40 = 0 ;
V_12 -> V_64 |= V_68 ;
} else if ( ! strcasecmp ( V_61 , L_34 ) ) {
if ( V_12 -> V_4 -> V_20 != 1 ) {
V_12 -> V_10 -> error = L_35 ;
return - V_14 ;
}
if ( V_58 >= V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_36 ;
return - V_14 ;
}
F_26 ( V_69 , & V_12 -> V_15 [ V_58 ] . V_26 . V_39 ) ;
} else if ( ! strcasecmp ( V_61 , L_37 ) ) {
if ( V_12 -> V_4 -> V_20 != 1 ) {
V_12 -> V_10 -> error = L_38 ;
return - V_14 ;
}
V_12 -> V_64 |= V_70 ;
V_58 /= 2 ;
if ( V_58 > V_71 ) {
V_12 -> V_10 -> error = L_39 ;
return - V_14 ;
}
V_12 -> V_18 . V_52 . V_72 = V_58 ;
} else if ( ! strcasecmp ( V_61 , L_40 ) ) {
V_12 -> V_64 |= V_73 ;
if ( ! V_58 || ( V_58 > V_74 ) ) {
V_12 -> V_10 -> error = L_41 ;
return - V_14 ;
}
V_12 -> V_18 . V_52 . V_75 = V_58 ;
} else if ( ! strcasecmp ( V_61 , L_42 ) ) {
V_12 -> V_64 |= V_76 ;
V_58 /= 2 ;
if ( ( V_12 -> V_4 -> V_20 != 5 ) &&
( V_12 -> V_4 -> V_20 != 6 ) ) {
V_12 -> V_10 -> error = L_43 ;
return - V_14 ;
}
if ( F_28 ( & V_12 -> V_18 , ( int ) V_58 ) ) {
V_12 -> V_10 -> error = L_44 ;
return - V_14 ;
}
} else if ( ! strcasecmp ( V_61 , L_45 ) ) {
V_12 -> V_64 |= V_77 ;
if ( V_58 > V_78 ) {
V_12 -> V_10 -> error = L_46 ;
return - V_14 ;
}
V_12 -> V_18 . V_79 = ( int ) V_58 ;
} else if ( ! strcasecmp ( V_61 , L_47 ) ) {
V_12 -> V_64 |= V_80 ;
if ( V_58 > V_78 ) {
V_12 -> V_10 -> error = L_48 ;
return - V_14 ;
}
V_12 -> V_18 . V_81 = ( int ) V_58 ;
} else if ( ! strcasecmp ( V_61 , L_49 ) ) {
V_12 -> V_64 |= V_82 ;
V_48 = V_58 ;
} else if ( ! strcasecmp ( V_61 , L_50 ) &&
( V_12 -> V_4 -> V_20 == 10 ) ) {
if ( ( V_58 < 2 ) || ( V_58 > 0xFF ) ) {
V_12 -> V_10 -> error = L_51 ;
return - V_14 ;
}
V_12 -> V_64 |= V_83 ;
V_56 = V_58 ;
} else {
F_20 ( L_52 , V_61 ) ;
V_12 -> V_10 -> error = L_53 ;
return - V_14 ;
}
}
if ( F_21 ( V_12 , V_48 ) )
return - V_14 ;
if ( V_12 -> V_18 . V_51 )
V_60 = V_12 -> V_18 . V_51 ;
else
V_60 = V_48 ;
if ( F_29 ( V_12 -> V_10 , V_60 ) )
return - V_14 ;
if ( V_12 -> V_4 -> V_20 == 10 ) {
if ( V_56 > V_12 -> V_18 . V_19 ) {
V_12 -> V_10 -> error = L_54 ;
return - V_14 ;
}
V_59 = V_12 -> V_10 -> V_50 * V_56 ;
F_30 ( V_59 , V_12 -> V_18 . V_19 ) ;
V_12 -> V_18 . V_1 = F_2 ( V_55 ,
V_56 ) ;
V_12 -> V_18 . V_23 = V_12 -> V_18 . V_1 ;
} else if ( ( V_12 -> V_4 -> V_20 > 1 ) &&
F_30 ( V_59 ,
( V_12 -> V_18 . V_19 - V_12 -> V_4 -> V_13 ) ) ) {
V_12 -> V_10 -> error = L_55 ;
return - V_14 ;
}
V_12 -> V_18 . V_84 = V_59 ;
V_12 -> V_18 . V_46 = 0 ;
V_12 -> V_18 . V_45 = 1 ;
return 0 ;
}
static void F_31 ( struct V_85 * V_86 )
{
struct V_8 * V_12 = F_32 ( V_86 , struct V_8 , V_18 . V_87 ) ;
F_33 ( V_12 -> V_10 -> V_36 ) ;
}
static int F_34 ( struct V_88 * V_89 , int V_90 )
{
struct V_8 * V_12 = F_32 ( V_89 , struct V_8 , V_91 ) ;
if ( V_12 -> V_4 -> V_20 == 1 )
return F_35 ( & V_12 -> V_18 , V_90 ) ;
if ( V_12 -> V_4 -> V_20 == 10 )
return F_36 ( & V_12 -> V_18 , V_90 ) ;
return F_37 ( & V_12 -> V_18 , V_90 ) ;
}
static int F_38 ( struct V_92 * V_26 , int V_93 )
{
F_39 ( ! V_26 -> V_37 ) ;
if ( V_26 -> V_94 )
return 0 ;
if ( ! F_40 ( V_26 , 0 , V_93 , V_26 -> V_37 , V_95 , 1 ) ) {
F_20 ( L_56 ,
V_26 -> V_33 ) ;
F_41 ( V_26 -> V_35 , V_26 ) ;
return - V_14 ;
}
V_26 -> V_94 = 1 ;
return 0 ;
}
static void F_42 ( struct V_35 * V_35 , struct V_92 * V_26 )
{
int V_6 ;
T_2 V_96 ;
struct V_97 * V_98 ;
struct V_8 * V_12 = F_32 ( V_35 , struct V_8 , V_18 ) ;
V_98 = F_43 ( V_26 -> V_37 ) ;
V_96 = F_44 ( V_98 -> V_96 ) ;
for ( V_6 = 0 ; V_6 < V_35 -> V_19 ; V_6 ++ )
if ( ! V_12 -> V_15 [ V_6 ] . V_28 ||
F_18 ( V_99 , & ( V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) ) )
V_96 |= ( 1ULL << V_6 ) ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_100 = F_45 ( V_101 ) ;
V_98 -> V_102 = F_45 ( 0 ) ;
V_98 -> V_103 = F_45 ( V_35 -> V_19 ) ;
V_98 -> V_104 = F_45 ( V_26 -> V_33 ) ;
V_98 -> V_105 = F_46 ( V_35 -> V_105 ) ;
V_98 -> V_96 = F_46 ( V_96 ) ;
V_98 -> V_106 = F_46 ( V_26 -> V_40 ) ;
V_98 -> V_107 = F_46 ( V_35 -> V_25 ) ;
V_98 -> V_20 = F_45 ( V_35 -> V_20 ) ;
V_98 -> V_1 = F_45 ( V_35 -> V_1 ) ;
V_98 -> V_108 = F_45 ( V_35 -> V_51 ) ;
}
static int F_47 ( struct V_92 * V_26 , struct V_92 * V_109 )
{
int V_32 ;
struct V_97 * V_98 ;
struct V_97 * V_110 ;
T_2 V_111 , V_112 ;
V_26 -> V_113 = 0 ;
V_26 -> V_114 = sizeof( * V_98 ) ;
V_32 = F_38 ( V_26 , V_26 -> V_114 ) ;
if ( V_32 )
return V_32 ;
V_98 = F_43 ( V_26 -> V_37 ) ;
if ( ( V_98 -> V_100 != F_45 ( V_101 ) ) ||
( ! F_18 ( V_38 , & V_26 -> V_39 ) && ! V_26 -> V_40 ) ) {
F_42 ( V_26 -> V_35 , V_26 ) ;
F_26 ( V_115 , & V_26 -> V_39 ) ;
F_26 ( V_116 , & V_26 -> V_35 -> V_39 ) ;
return V_109 ? 0 : 1 ;
}
if ( ! V_109 )
return 1 ;
V_111 = F_44 ( V_98 -> V_105 ) ;
V_110 = F_43 ( V_109 -> V_37 ) ;
V_112 = F_44 ( V_110 -> V_105 ) ;
return ( V_111 > V_112 ) ? 1 : 0 ;
}
static int F_48 ( struct V_35 * V_35 , struct V_92 * V_26 )
{
int V_117 ;
struct V_8 * V_12 = F_32 ( V_35 , struct V_8 , V_18 ) ;
T_2 V_111 ;
T_2 V_96 ;
struct V_97 * V_98 ;
T_3 V_118 = 0 ;
T_3 V_119 = 0 ;
struct V_92 * V_120 ;
struct V_97 * V_121 ;
V_98 = F_43 ( V_26 -> V_37 ) ;
V_111 = F_44 ( V_98 -> V_105 ) ;
V_96 = F_44 ( V_98 -> V_96 ) ;
V_35 -> V_105 = V_111 ? : 1 ;
if ( ( F_49 ( V_98 -> V_20 ) != V_35 -> V_20 ) ||
( F_49 ( V_98 -> V_1 ) != V_35 -> V_1 ) ||
( F_49 ( V_98 -> V_108 ) != V_35 -> V_51 ) ) {
F_20 ( L_57 ) ;
return - V_14 ;
}
if ( ( V_12 -> V_4 -> V_20 != 1 ) &&
( F_49 ( V_98 -> V_103 ) != V_35 -> V_19 ) ) {
F_20 ( L_57 ) ;
return - V_14 ;
}
if ( ! ( V_12 -> V_64 & ( V_66 | V_65 ) ) )
V_35 -> V_25 = F_44 ( V_98 -> V_107 ) ;
F_50 (r, mddev) {
if ( ! F_18 ( V_38 , & V_120 -> V_39 ) ) {
F_22 ( L_58
L_59 , V_120 -> V_33 ) ;
V_119 ++ ;
} else if ( F_18 ( V_115 , & V_120 -> V_39 ) )
V_118 ++ ;
}
if ( ! V_119 ) {
if ( V_118 == V_35 -> V_19 ) {
F_22 ( L_60 ) ;
F_26 ( V_122 , & V_35 -> V_39 ) ;
} else if ( V_118 ) {
F_20 ( L_61
L_62
L_63 ) ;
return - V_14 ;
}
} else if ( V_118 ) {
F_20 ( L_64
L_65 ) ;
return - V_14 ;
} else if ( V_35 -> V_25 != V_63 ) {
F_20 ( L_66 ) ;
return - V_14 ;
}
F_50 (r, mddev) {
if ( ! V_120 -> V_37 )
continue;
V_121 = F_43 ( V_120 -> V_37 ) ;
V_121 -> V_96 = 0 ;
if ( ! F_18 ( V_115 , & V_120 -> V_39 ) && ( V_120 -> V_33 >= 0 ) ) {
V_117 = F_49 ( V_121 -> V_104 ) ;
if ( V_117 != V_120 -> V_33 ) {
if ( V_12 -> V_4 -> V_20 != 1 ) {
V_12 -> V_10 -> error = L_67
L_68 ;
return - V_14 ;
}
F_22 ( L_69 ,
V_117 , V_120 -> V_33 ) ;
}
if ( V_96 & ( 1 << V_117 ) )
F_26 ( V_99 , & V_120 -> V_39 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_35 * V_35 , struct V_92 * V_26 )
{
struct V_97 * V_98 = F_43 ( V_26 -> V_37 ) ;
if ( ! V_35 -> V_105 && F_48 ( V_35 , V_26 ) )
return - V_14 ;
V_35 -> V_52 . V_123 = 4096 >> 9 ;
V_26 -> V_35 -> V_52 . V_124 = 4096 >> 9 ;
if ( ! F_18 ( V_115 , & V_26 -> V_39 ) ) {
V_26 -> V_40 = F_44 ( V_98 -> V_106 ) ;
if ( V_26 -> V_40 != V_63 )
F_27 ( V_38 , & V_26 -> V_39 ) ;
}
if ( F_18 ( V_99 , & V_26 -> V_39 ) ) {
F_27 ( V_99 , & V_26 -> V_39 ) ;
F_27 ( V_38 , & V_26 -> V_39 ) ;
V_26 -> V_125 = V_26 -> V_33 ;
V_26 -> V_40 = 0 ;
}
F_27 ( V_115 , & V_26 -> V_39 ) ;
return 0 ;
}
static int F_52 ( struct V_9 * V_10 , struct V_8 * V_12 )
{
int V_32 ;
unsigned V_126 = 0 ;
struct V_127 * V_15 ;
struct V_92 * V_26 , * V_128 , * V_129 ;
struct V_35 * V_35 = & V_12 -> V_18 ;
switch ( V_12 -> V_4 -> V_20 ) {
case 1 :
V_126 = V_12 -> V_18 . V_19 - 1 ;
break;
case 4 :
case 5 :
case 6 :
V_126 = V_12 -> V_4 -> V_13 ;
break;
case 10 :
V_126 = F_1 ( V_35 -> V_1 ) - 1 ;
break;
default:
V_10 -> error = L_70 ;
return - V_14 ;
}
V_129 = NULL ;
F_53 (rdev, tmp, mddev) {
if ( ! V_26 -> V_41 )
continue;
V_32 = F_47 ( V_26 , V_129 ) ;
switch ( V_32 ) {
case 1 :
V_129 = V_26 ;
break;
case 0 :
break;
default:
V_15 = F_32 ( V_26 , struct V_127 , V_26 ) ;
if ( V_126 -- ) {
if ( V_15 -> V_27 )
F_11 ( V_10 , V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
V_26 -> V_41 = NULL ;
if ( V_26 -> V_37 )
F_54 ( V_26 -> V_37 ) ;
V_26 -> V_37 = NULL ;
V_26 -> V_94 = 0 ;
if ( V_15 -> V_28 )
F_11 ( V_10 , V_15 -> V_28 ) ;
V_15 -> V_28 = NULL ;
V_26 -> V_42 = NULL ;
F_55 ( & V_26 -> V_43 ) ;
continue;
}
V_10 -> error = L_71 ;
return V_32 ;
}
}
if ( ! V_129 )
return 0 ;
V_10 -> error = L_72 ;
if ( F_51 ( V_35 , V_129 ) )
return - V_14 ;
F_50 (rdev, mddev)
if ( ( V_26 != V_129 ) && F_51 ( V_35 , V_26 ) )
return - V_14 ;
return 0 ;
}
static int F_56 ( struct V_9 * V_10 , unsigned V_130 , char * * V_29 )
{
int V_32 ;
struct V_4 * V_131 ;
unsigned long V_54 , V_132 ;
struct V_8 * V_12 = NULL ;
if ( V_130 < 2 ) {
V_10 -> error = L_73 ;
return - V_14 ;
}
V_131 = F_3 ( V_29 [ 0 ] ) ;
if ( ! V_131 ) {
V_10 -> error = L_74 ;
return - V_14 ;
}
V_130 -- ;
V_29 ++ ;
if ( F_25 ( V_29 [ 0 ] , 10 , & V_54 ) < 0 ) {
V_10 -> error = L_75 ;
return - V_14 ;
}
V_130 -- ;
V_29 ++ ;
if ( V_54 + 1 > V_130 ) {
V_10 -> error = L_76 ;
return - V_14 ;
}
if ( ( F_25 ( V_29 [ V_54 ] , 10 , & V_132 ) < 0 ) ||
( V_132 >= V_78 ) ) {
V_10 -> error = L_77 ;
return - V_14 ;
}
V_12 = F_5 ( V_10 , V_131 , ( unsigned ) V_132 ) ;
if ( F_57 ( V_12 ) )
return F_58 ( V_12 ) ;
V_32 = F_24 ( V_12 , V_29 , ( unsigned ) V_54 ) ;
if ( V_32 )
goto V_133;
V_32 = - V_14 ;
V_130 -= V_54 + 1 ;
V_29 += V_54 + 1 ;
if ( V_130 != ( V_132 * 2 ) ) {
V_10 -> error = L_78 ;
goto V_133;
}
V_32 = F_14 ( V_12 , V_29 ) ;
if ( V_32 )
goto V_133;
V_12 -> V_18 . V_134 = F_42 ;
V_32 = F_52 ( V_10 , V_12 ) ;
if ( V_32 )
goto V_133;
F_59 ( & V_12 -> V_18 . V_87 , F_31 ) ;
V_10 -> V_135 = V_12 ;
V_10 -> V_136 = 1 ;
F_60 ( & V_12 -> V_18 . V_137 ) ;
V_32 = F_61 ( & V_12 -> V_18 ) ;
V_12 -> V_18 . V_138 = 0 ;
F_62 ( & V_12 -> V_18 . V_137 ) ;
if ( V_32 ) {
V_10 -> error = L_79 ;
goto V_133;
}
if ( V_10 -> V_50 != V_12 -> V_18 . V_139 ) {
V_10 -> error = L_80 ;
V_32 = - V_14 ;
goto V_140;
}
V_12 -> V_91 . V_141 = F_34 ;
F_63 ( V_10 -> V_36 , & V_12 -> V_91 ) ;
F_64 ( & V_12 -> V_18 ) ;
return 0 ;
V_140:
F_65 ( & V_12 -> V_18 ) ;
V_133:
F_10 ( V_12 ) ;
return V_32 ;
}
static void F_66 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
F_67 ( & V_12 -> V_91 . V_142 ) ;
F_65 ( & V_12 -> V_18 ) ;
F_10 ( V_12 ) ;
}
static int F_68 ( struct V_9 * V_10 , struct V_143 * V_143 , union V_144 * V_145 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
struct V_35 * V_35 = & V_12 -> V_18 ;
V_35 -> V_146 -> V_147 ( V_35 , V_143 ) ;
return V_148 ;
}
static int F_69 ( struct V_9 * V_10 , T_4 type ,
unsigned V_149 , char * V_150 , unsigned V_151 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
unsigned V_152 = 1 ;
unsigned V_153 = 0 ;
int V_6 , V_154 = 0 ;
T_1 V_155 ;
switch ( type ) {
case V_156 :
F_70 ( L_81 , V_12 -> V_4 -> V_5 , V_12 -> V_18 . V_19 ) ;
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
if ( F_18 ( V_99 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_70 ( L_82 ) ;
else if ( ! V_154 ||
! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_70 ( L_83 ) ;
else
F_70 ( L_84 ) ;
}
F_70 ( L_85 ,
( unsigned long long ) V_155 ,
( unsigned long long ) V_12 -> V_18 . V_160 ) ;
break;
case V_161 :
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
if ( ( V_12 -> V_64 & V_68 ) &&
V_12 -> V_15 [ V_6 ] . V_28 &&
! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
V_152 += 2 ;
if ( V_12 -> V_15 [ V_6 ] . V_28 &&
F_18 ( V_69 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
V_152 += 2 ;
}
V_152 += ( F_71 ( V_12 -> V_64 & ~ V_68 ) * 2 ) ;
if ( V_12 -> V_64 & ( V_66 | V_65 ) )
V_152 -- ;
F_70 ( L_86 , V_12 -> V_4 -> V_5 ,
V_152 , V_12 -> V_18 . V_51 ) ;
if ( ( V_12 -> V_64 & V_66 ) &&
( V_12 -> V_18 . V_25 == V_63 ) )
F_70 ( L_87 ) ;
if ( V_12 -> V_64 & V_65 )
F_70 ( L_88 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( ( V_12 -> V_64 & V_68 ) &&
V_12 -> V_15 [ V_6 ] . V_28 &&
! F_18 ( V_38 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_70 ( L_89 , V_6 ) ;
if ( V_12 -> V_64 & V_73 )
F_70 ( L_90 ,
V_12 -> V_18 . V_52 . V_75 ) ;
if ( V_12 -> V_64 & V_77 )
F_70 ( L_91 , V_12 -> V_18 . V_79 ) ;
if ( V_12 -> V_64 & V_80 )
F_70 ( L_92 , V_12 -> V_18 . V_81 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( V_12 -> V_15 [ V_6 ] . V_28 &&
F_18 ( V_69 , & V_12 -> V_15 [ V_6 ] . V_26 . V_39 ) )
F_70 ( L_93 , V_6 ) ;
if ( V_12 -> V_64 & V_70 )
F_70 ( L_94 ,
V_12 -> V_18 . V_52 . V_72 ) ;
if ( V_12 -> V_64 & V_76 ) {
struct V_162 * V_163 = V_12 -> V_18 . V_135 ;
F_70 ( L_95 ,
V_163 ? V_163 -> V_164 * 2 : 0 ) ;
}
if ( V_12 -> V_64 & V_82 )
F_70 ( L_96 ,
V_12 -> V_18 . V_52 . V_53 >> 9 ) ;
if ( V_12 -> V_64 & V_83 )
F_70 ( L_97 ,
F_1 ( V_12 -> V_18 . V_1 ) ) ;
if ( V_12 -> V_64 & V_67 )
F_70 ( L_98 ) ;
F_70 ( L_99 , V_12 -> V_18 . V_19 ) ;
for ( V_6 = 0 ; V_6 < V_12 -> V_18 . V_19 ; V_6 ++ ) {
if ( V_12 -> V_15 [ V_6 ] . V_27 )
F_70 ( L_100 , V_12 -> V_15 [ V_6 ] . V_27 -> V_5 ) ;
else
F_70 ( L_101 ) ;
if ( V_12 -> V_15 [ V_6 ] . V_28 )
F_70 ( L_100 , V_12 -> V_15 [ V_6 ] . V_28 -> V_5 ) ;
else
F_70 ( L_101 ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_9 * V_10 , T_5 V_165 , void * V_166 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
unsigned V_6 ;
int V_32 = 0 ;
for ( V_6 = 0 ; ! V_32 && V_6 < V_12 -> V_18 . V_19 ; V_6 ++ )
if ( V_12 -> V_15 [ V_6 ] . V_28 )
V_32 = V_165 ( V_10 ,
V_12 -> V_15 [ V_6 ] . V_28 ,
0 ,
V_12 -> V_18 . V_84 ,
V_166 ) ;
return V_32 ;
}
static void F_73 ( struct V_9 * V_10 , struct V_167 * V_168 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
unsigned V_169 = V_12 -> V_18 . V_51 << 9 ;
struct V_162 * V_163 = V_12 -> V_18 . V_135 ;
F_74 ( V_168 , V_169 ) ;
F_75 ( V_168 , V_169 * ( V_163 -> V_19 - V_163 -> V_170 ) ) ;
}
static void F_76 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
F_77 ( & V_12 -> V_18 ) ;
}
static void F_78 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
F_64 ( & V_12 -> V_18 ) ;
}
static void F_79 ( struct V_9 * V_10 )
{
struct V_8 * V_12 = V_10 -> V_135 ;
F_26 ( V_116 , & V_12 -> V_18 . V_39 ) ;
if ( ! V_12 -> V_171 ) {
F_80 ( & V_12 -> V_18 ) ;
V_12 -> V_171 = 1 ;
}
F_27 ( V_172 , & V_12 -> V_18 . V_158 ) ;
F_81 ( & V_12 -> V_18 ) ;
}
static int T_6 F_82 ( void )
{
return F_83 ( & V_173 ) ;
}
static void T_7 F_84 ( void )
{
F_85 ( & V_173 ) ;
}
