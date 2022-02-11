static struct V_1 * F_1 ( char * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( ! strcmp ( V_4 [ V_3 ] . V_2 , V_2 ) )
return & V_4 [ V_3 ] ;
return NULL ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 , struct V_1 * V_1 , unsigned V_8 )
{
unsigned V_3 ;
struct V_5 * V_9 ;
T_1 V_10 ;
if ( V_8 <= V_1 -> V_11 ) {
V_7 -> error = L_1 ;
return F_4 ( - V_12 ) ;
}
V_10 = V_7 -> V_13 ;
if ( ( V_1 -> V_14 > 1 ) &&
F_5 ( V_10 , ( V_8 - V_1 -> V_11 ) ) ) {
V_7 -> error = L_2 ;
return F_4 ( - V_12 ) ;
}
V_9 = F_6 ( sizeof( * V_9 ) + V_8 * sizeof( V_9 -> V_15 [ 0 ] ) , V_16 ) ;
if ( ! V_9 ) {
V_7 -> error = L_3 ;
return F_4 ( - V_17 ) ;
}
F_7 ( & V_9 -> V_18 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_1 = V_1 ;
V_9 -> V_18 . V_19 = V_8 ;
V_9 -> V_18 . V_14 = V_1 -> V_14 ;
V_9 -> V_18 . V_20 = V_9 -> V_18 . V_14 ;
V_9 -> V_18 . V_21 = V_10 ;
V_9 -> V_18 . V_22 = V_1 -> V_23 ;
V_9 -> V_18 . V_24 = V_9 -> V_18 . V_22 ;
V_9 -> V_18 . V_25 = 0 ;
V_9 -> V_18 . V_26 = 0 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ )
F_8 ( & V_9 -> V_15 [ V_3 ] . V_27 ) ;
return V_9 ;
}
static void F_9 ( struct V_5 * V_9 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( V_9 -> V_15 [ V_3 ] . V_28 )
F_10 ( V_9 -> V_7 , V_9 -> V_15 [ V_3 ] . V_28 ) ;
if ( V_9 -> V_15 [ V_3 ] . V_27 . V_29 )
F_11 ( V_9 -> V_15 [ V_3 ] . V_27 . V_29 ) ;
V_9 -> V_15 [ V_3 ] . V_27 . V_29 = NULL ;
V_9 -> V_15 [ V_3 ] . V_27 . V_30 = 0 ;
if ( V_9 -> V_15 [ V_3 ] . V_31 )
F_10 ( V_9 -> V_7 , V_9 -> V_15 [ V_3 ] . V_31 ) ;
}
F_12 ( V_9 ) ;
}
static int F_13 ( struct V_5 * V_9 , char * * V_32 )
{
int V_3 ;
int V_33 = 0 ;
int V_34 = 0 ;
int V_35 = 0 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ , V_32 += 2 ) {
V_9 -> V_15 [ V_3 ] . V_27 . V_36 = V_3 ;
V_9 -> V_15 [ V_3 ] . V_28 = NULL ;
V_9 -> V_15 [ V_3 ] . V_31 = NULL ;
V_9 -> V_15 [ V_3 ] . V_27 . V_37 = 0 ;
V_9 -> V_15 [ V_3 ] . V_27 . V_38 = & V_9 -> V_18 ;
if ( strcmp ( V_32 [ 0 ] , L_4 ) ) {
V_35 = F_14 ( V_9 -> V_7 , V_32 [ 0 ] ,
F_15 ( V_9 -> V_7 -> V_39 ) ,
& V_9 -> V_15 [ V_3 ] . V_28 ) ;
V_9 -> V_7 -> error = L_5 ;
if ( V_35 )
return V_35 ;
V_9 -> V_15 [ V_3 ] . V_27 . V_29 = F_16 ( V_16 ) ;
if ( ! V_9 -> V_15 [ V_3 ] . V_27 . V_29 )
return - V_17 ;
}
if ( ! strcmp ( V_32 [ 1 ] , L_4 ) ) {
if ( ! F_17 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) &&
( ! V_9 -> V_15 [ V_3 ] . V_27 . V_42 ) ) {
V_9 -> V_7 -> error = L_6 ;
return - V_12 ;
}
V_9 -> V_7 -> error = L_7 ;
if ( V_9 -> V_15 [ V_3 ] . V_28 )
return - V_12 ;
continue;
}
V_35 = F_14 ( V_9 -> V_7 , V_32 [ 1 ] ,
F_15 ( V_9 -> V_7 -> V_39 ) ,
& V_9 -> V_15 [ V_3 ] . V_31 ) ;
if ( V_35 ) {
V_9 -> V_7 -> error = L_8 ;
return V_35 ;
}
if ( V_9 -> V_15 [ V_3 ] . V_28 ) {
V_34 = 1 ;
V_9 -> V_15 [ V_3 ] . V_27 . V_43 = V_9 -> V_15 [ V_3 ] . V_28 -> V_44 ;
}
V_9 -> V_15 [ V_3 ] . V_27 . V_44 = V_9 -> V_15 [ V_3 ] . V_31 -> V_44 ;
F_18 ( & V_9 -> V_15 [ V_3 ] . V_27 . V_45 , & V_9 -> V_18 . V_46 ) ;
if ( ! F_17 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
V_33 ++ ;
}
if ( V_34 ) {
V_9 -> V_18 . V_47 = 0 ;
V_9 -> V_18 . V_48 = 1 ;
V_9 -> V_18 . V_49 = 2 ;
} else if ( V_33 && ! V_9 -> V_18 . V_26 ) {
F_19 ( L_9 ) ;
V_9 -> V_7 -> error = L_8 ;
return - V_12 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_9 , unsigned long V_50 )
{
unsigned long V_51 = V_9 -> V_7 -> V_13 / ( 1 << 21 ) ;
if ( ! V_50 ) {
if ( V_51 > ( 1 << 13 ) ) {
F_21 ( L_10 ,
V_50 ) ;
V_50 = V_51 ;
} else {
F_21 ( L_11 ) ;
V_50 = 1 << 13 ;
}
} else {
if ( V_50 > V_9 -> V_7 -> V_13 ) {
V_9 -> V_7 -> error = L_12 ;
return - V_12 ;
}
if ( V_50 < V_51 ) {
F_19 ( L_13 ,
V_50 , V_51 ) ;
V_9 -> V_7 -> error = L_14 ;
return - V_12 ;
}
if ( ! F_22 ( V_50 ) ) {
V_9 -> V_7 -> error = L_15 ;
return - V_12 ;
}
if ( V_50 < V_9 -> V_18 . V_52 ) {
V_9 -> V_7 -> error = L_16 ;
return - V_12 ;
}
}
V_9 -> V_18 . V_53 . V_54 = ( V_50 << 9 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_9 , char * * V_32 ,
unsigned V_55 )
{
unsigned V_3 , V_56 = 0 ;
unsigned long V_57 , V_50 = 0 ;
char * V_58 ;
if ( ( F_24 ( V_32 [ 0 ] , 10 , & V_57 ) < 0 ) ) {
V_9 -> V_7 -> error = L_17 ;
return - V_12 ;
} else if ( V_9 -> V_1 -> V_14 == 1 ) {
if ( V_57 )
F_19 ( L_18 ) ;
V_57 = 0 ;
} else if ( ! F_22 ( V_57 ) ) {
V_9 -> V_7 -> error = L_19 ;
return - V_12 ;
} else if ( V_57 < 8 ) {
V_9 -> V_7 -> error = L_20 ;
return - V_12 ;
}
V_9 -> V_18 . V_59 = V_9 -> V_18 . V_52 = V_57 ;
V_32 ++ ;
V_55 -- ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
F_25 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) ;
V_9 -> V_15 [ V_3 ] . V_27 . V_42 = V_60 ;
}
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
if ( ! strcasecmp ( V_32 [ V_3 ] , L_21 ) ) {
V_9 -> V_18 . V_26 = V_60 ;
V_9 -> V_61 |= V_62 ;
continue;
}
if ( ! strcasecmp ( V_32 [ V_3 ] , L_22 ) ) {
V_9 -> V_18 . V_26 = 0 ;
V_9 -> V_61 |= V_63 ;
continue;
}
if ( ( V_3 + 1 ) >= V_55 ) {
V_9 -> V_7 -> error = L_23 ;
return - V_12 ;
}
V_58 = V_32 [ V_3 ++ ] ;
if ( F_24 ( V_32 [ V_3 ] , 10 , & V_57 ) < 0 ) {
V_9 -> V_7 -> error = L_24 ;
return - V_12 ;
}
if ( ! strcasecmp ( V_58 , L_25 ) ) {
V_56 ++ ;
if ( ( ( V_9 -> V_1 -> V_14 != 1 ) &&
( V_56 > V_9 -> V_1 -> V_11 ) ) ||
( ( V_9 -> V_1 -> V_14 == 1 ) &&
( V_56 > ( V_9 -> V_18 . V_19 - 1 ) ) ) ) {
V_9 -> V_7 -> error = L_26 ;
return - V_12 ;
}
if ( V_57 > V_9 -> V_18 . V_19 ) {
V_9 -> V_7 -> error = L_27 ;
return - V_12 ;
}
F_26 ( V_40 , & V_9 -> V_15 [ V_57 ] . V_27 . V_41 ) ;
V_9 -> V_15 [ V_57 ] . V_27 . V_42 = 0 ;
V_9 -> V_61 |= V_64 ;
} else if ( ! strcasecmp ( V_58 , L_28 ) ) {
if ( V_9 -> V_1 -> V_14 != 1 ) {
V_9 -> V_7 -> error = L_29 ;
return - V_12 ;
}
if ( V_57 >= V_9 -> V_18 . V_19 ) {
V_9 -> V_7 -> error = L_30 ;
return - V_12 ;
}
F_25 ( V_65 , & V_9 -> V_15 [ V_57 ] . V_27 . V_41 ) ;
} else if ( ! strcasecmp ( V_58 , L_31 ) ) {
if ( V_9 -> V_1 -> V_14 != 1 ) {
V_9 -> V_7 -> error = L_32 ;
return - V_12 ;
}
V_9 -> V_61 |= V_66 ;
V_57 /= 2 ;
if ( V_57 > V_67 ) {
V_9 -> V_7 -> error = L_33 ;
return - V_12 ;
}
V_9 -> V_18 . V_53 . V_68 = V_57 ;
} else if ( ! strcasecmp ( V_58 , L_34 ) ) {
V_9 -> V_61 |= V_69 ;
if ( ! V_57 || ( V_57 > V_70 ) ) {
V_9 -> V_7 -> error = L_35 ;
return - V_12 ;
}
V_9 -> V_18 . V_53 . V_71 = V_57 ;
} else if ( ! strcasecmp ( V_58 , L_36 ) ) {
V_9 -> V_61 |= V_72 ;
V_57 /= 2 ;
if ( V_9 -> V_1 -> V_14 < 5 ) {
V_9 -> V_7 -> error = L_37 ;
return - V_12 ;
}
if ( F_27 ( & V_9 -> V_18 , ( int ) V_57 ) ) {
V_9 -> V_7 -> error = L_38 ;
return - V_12 ;
}
} else if ( ! strcasecmp ( V_58 , L_39 ) ) {
V_9 -> V_61 |= V_73 ;
if ( V_57 > V_74 ) {
V_9 -> V_7 -> error = L_40 ;
return - V_12 ;
}
V_9 -> V_18 . V_75 = ( int ) V_57 ;
} else if ( ! strcasecmp ( V_58 , L_41 ) ) {
V_9 -> V_61 |= V_76 ;
if ( V_57 > V_74 ) {
V_9 -> V_7 -> error = L_42 ;
return - V_12 ;
}
V_9 -> V_18 . V_77 = ( int ) V_57 ;
} else if ( ! strcasecmp ( V_58 , L_43 ) ) {
V_9 -> V_61 |= V_78 ;
V_50 = V_57 ;
} else {
F_19 ( L_44 , V_58 ) ;
V_9 -> V_7 -> error = L_45 ;
return - V_12 ;
}
}
if ( F_20 ( V_9 , V_50 ) )
return - V_12 ;
if ( V_9 -> V_18 . V_52 )
V_9 -> V_7 -> V_79 = V_9 -> V_18 . V_52 ;
else
V_9 -> V_7 -> V_79 = V_50 ;
if ( V_9 -> V_18 . V_52 )
V_9 -> V_7 -> V_79 = V_9 -> V_18 . V_52 ;
else
V_9 -> V_7 -> V_79 = V_50 ;
V_9 -> V_18 . V_48 = 0 ;
V_9 -> V_18 . V_47 = 1 ;
return 0 ;
}
static void F_28 ( struct V_80 * V_81 )
{
struct V_5 * V_9 = F_29 ( V_81 , struct V_5 , V_18 . V_82 ) ;
F_30 ( V_9 -> V_7 -> V_39 ) ;
}
static int F_31 ( struct V_83 * V_84 , int V_85 )
{
struct V_5 * V_9 = F_29 ( V_84 , struct V_5 , V_86 ) ;
if ( V_9 -> V_1 -> V_14 == 1 )
return F_32 ( & V_9 -> V_18 , V_85 ) ;
return F_33 ( & V_9 -> V_18 , V_85 ) ;
}
static int F_34 ( struct V_87 * V_27 , int V_88 )
{
F_35 ( ! V_27 -> V_29 ) ;
if ( V_27 -> V_30 )
return 0 ;
if ( ! F_36 ( V_27 , 0 , V_88 , V_27 -> V_29 , V_89 , 1 ) ) {
F_19 ( L_46 ) ;
return - V_12 ;
}
V_27 -> V_30 = 1 ;
return 0 ;
}
static void F_37 ( struct V_38 * V_38 , struct V_87 * V_27 )
{
struct V_87 * V_90 , * V_91 ;
T_2 V_92 ;
struct V_93 * V_94 ;
V_94 = F_38 ( V_27 -> V_29 ) ;
V_92 = F_39 ( V_94 -> V_92 ) ;
F_40 (r, t, mddev)
if ( ( V_90 -> V_36 >= 0 ) && F_17 ( V_95 , & V_90 -> V_41 ) )
V_92 |= ( 1ULL << V_90 -> V_36 ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_96 = F_41 ( V_97 ) ;
V_94 -> V_98 = F_41 ( 0 ) ;
V_94 -> V_99 = F_41 ( V_38 -> V_19 ) ;
V_94 -> V_100 = F_41 ( V_27 -> V_36 ) ;
V_94 -> V_101 = F_42 ( V_38 -> V_101 ) ;
V_94 -> V_92 = F_42 ( V_92 ) ;
V_94 -> V_102 = F_42 ( V_27 -> V_42 ) ;
V_94 -> V_103 = F_42 ( V_38 -> V_26 ) ;
V_94 -> V_14 = F_41 ( V_38 -> V_14 ) ;
V_94 -> V_22 = F_41 ( V_38 -> V_22 ) ;
V_94 -> V_104 = F_41 ( V_38 -> V_52 ) ;
}
static int F_43 ( struct V_87 * V_27 , struct V_87 * V_105 )
{
int V_35 ;
struct V_93 * V_94 ;
struct V_93 * V_106 ;
T_2 V_107 , V_108 ;
V_27 -> V_109 = 0 ;
V_27 -> V_110 = sizeof( * V_94 ) ;
V_35 = F_34 ( V_27 , V_27 -> V_110 ) ;
if ( V_35 )
return V_35 ;
V_94 = F_38 ( V_27 -> V_29 ) ;
if ( ( V_94 -> V_96 != F_41 ( V_97 ) ) ||
( ! F_17 ( V_40 , & V_27 -> V_41 ) && ! V_27 -> V_42 ) ) {
F_37 ( V_27 -> V_38 , V_27 ) ;
F_25 ( V_111 , & V_27 -> V_41 ) ;
F_25 ( V_112 , & V_27 -> V_38 -> V_41 ) ;
return V_105 ? 0 : 1 ;
}
if ( ! V_105 )
return 1 ;
V_107 = F_39 ( V_94 -> V_101 ) ;
V_106 = F_38 ( V_105 -> V_29 ) ;
V_108 = F_39 ( V_106 -> V_101 ) ;
return ( V_107 > V_108 ) ? 1 : 0 ;
}
static int F_44 ( struct V_38 * V_38 , struct V_87 * V_27 )
{
int V_113 ;
struct V_5 * V_9 = F_29 ( V_38 , struct V_5 , V_18 ) ;
T_2 V_107 ;
T_2 V_92 ;
struct V_93 * V_94 ;
T_3 V_114 = 0 ;
T_3 V_115 = 0 ;
struct V_87 * V_90 , * V_91 ;
struct V_93 * V_116 ;
V_94 = F_38 ( V_27 -> V_29 ) ;
V_107 = F_39 ( V_94 -> V_101 ) ;
V_92 = F_39 ( V_94 -> V_92 ) ;
V_38 -> V_101 = V_107 ? : 1 ;
if ( ( F_45 ( V_94 -> V_14 ) != V_38 -> V_14 ) ||
( F_45 ( V_94 -> V_22 ) != V_38 -> V_22 ) ||
( F_45 ( V_94 -> V_104 ) != V_38 -> V_52 ) ) {
F_19 ( L_47 ) ;
return - V_12 ;
}
if ( ( V_9 -> V_1 -> V_14 != 1 ) &&
( F_45 ( V_94 -> V_99 ) != V_38 -> V_19 ) ) {
F_19 ( L_47 ) ;
return - V_12 ;
}
if ( ! ( V_9 -> V_61 & ( V_63 | V_62 ) ) )
V_38 -> V_26 = F_39 ( V_94 -> V_103 ) ;
F_40 (r, t, mddev) {
if ( ! F_17 ( V_40 , & V_90 -> V_41 ) ) {
F_21 ( L_48
L_49 , V_90 -> V_36 ) ;
V_115 ++ ;
} else if ( F_17 ( V_111 , & V_90 -> V_41 ) )
V_114 ++ ;
}
if ( ! V_115 ) {
if ( V_114 == V_38 -> V_19 ) {
F_21 ( L_50 ) ;
F_25 ( V_117 , & V_38 -> V_41 ) ;
} else if ( V_114 ) {
F_19 ( L_51
L_52
L_53 ) ;
return - V_12 ;
}
} else if ( V_114 ) {
F_19 ( L_54
L_55 ) ;
return - V_12 ;
} else if ( V_38 -> V_26 != V_60 ) {
F_19 ( L_56 ) ;
return - V_12 ;
}
F_40 (r, t, mddev) {
if ( ! V_90 -> V_29 )
continue;
V_116 = F_38 ( V_90 -> V_29 ) ;
V_116 -> V_92 = 0 ;
if ( ! F_17 ( V_111 , & V_90 -> V_41 ) && ( V_90 -> V_36 >= 0 ) ) {
V_113 = F_45 ( V_116 -> V_100 ) ;
if ( V_113 != V_90 -> V_36 ) {
if ( V_9 -> V_1 -> V_14 != 1 ) {
V_9 -> V_7 -> error = L_57
L_58 ;
return - V_12 ;
}
F_21 ( L_59 ,
V_113 , V_90 -> V_36 ) ;
}
if ( V_92 & ( 1 << V_113 ) )
F_25 ( V_95 , & V_90 -> V_41 ) ;
}
}
return 0 ;
}
static int F_46 ( struct V_38 * V_38 , struct V_87 * V_27 )
{
struct V_93 * V_94 = F_38 ( V_27 -> V_29 ) ;
if ( ! V_38 -> V_101 && F_44 ( V_38 , V_27 ) )
return - V_12 ;
V_38 -> V_53 . V_118 = 4096 >> 9 ;
V_27 -> V_38 -> V_53 . V_119 = 4096 >> 9 ;
if ( ! F_17 ( V_111 , & V_27 -> V_41 ) ) {
V_27 -> V_42 = F_39 ( V_94 -> V_102 ) ;
if ( V_27 -> V_42 != V_60 )
F_26 ( V_40 , & V_27 -> V_41 ) ;
}
if ( F_17 ( V_95 , & V_27 -> V_41 ) ) {
F_26 ( V_95 , & V_27 -> V_41 ) ;
F_26 ( V_40 , & V_27 -> V_41 ) ;
V_27 -> V_120 = V_27 -> V_36 ;
V_27 -> V_42 = 0 ;
}
F_26 ( V_111 , & V_27 -> V_41 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
int V_35 ;
struct V_87 * V_27 , * V_121 , * V_122 ;
struct V_38 * V_38 = & V_9 -> V_18 ;
V_121 = NULL ;
F_40 (rdev, tmp, mddev) {
if ( ! V_27 -> V_43 )
continue;
V_35 = F_43 ( V_27 , V_121 ) ;
switch ( V_35 ) {
case 1 :
V_121 = V_27 ;
break;
case 0 :
break;
default:
V_7 -> error = L_60 ;
return V_35 ;
}
}
if ( ! V_121 )
return 0 ;
V_7 -> error = L_61 ;
if ( F_46 ( V_38 , V_121 ) )
return - V_12 ;
F_40 (rdev, tmp, mddev)
if ( ( V_27 != V_121 ) && F_46 ( V_38 , V_27 ) )
return - V_12 ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , unsigned V_123 , char * * V_32 )
{
int V_35 ;
struct V_1 * V_124 ;
unsigned long V_55 , V_125 ;
struct V_5 * V_9 = NULL ;
if ( V_123 < 2 ) {
V_7 -> error = L_62 ;
return - V_12 ;
}
V_124 = F_1 ( V_32 [ 0 ] ) ;
if ( ! V_124 ) {
V_7 -> error = L_63 ;
return - V_12 ;
}
V_123 -- ;
V_32 ++ ;
if ( F_24 ( V_32 [ 0 ] , 10 , & V_55 ) < 0 ) {
V_7 -> error = L_64 ;
return - V_12 ;
}
V_123 -- ;
V_32 ++ ;
if ( V_55 + 1 > V_123 ) {
V_7 -> error = L_65 ;
return - V_12 ;
}
if ( ( F_24 ( V_32 [ V_55 ] , 10 , & V_125 ) < 0 ) ||
( V_125 >= V_74 ) ) {
V_7 -> error = L_66 ;
return - V_12 ;
}
V_9 = F_3 ( V_7 , V_124 , ( unsigned ) V_125 ) ;
if ( F_49 ( V_9 ) )
return F_50 ( V_9 ) ;
V_35 = F_23 ( V_9 , V_32 , ( unsigned ) V_55 ) ;
if ( V_35 )
goto V_126;
V_35 = - V_12 ;
V_123 -= V_55 + 1 ;
V_32 += V_55 + 1 ;
if ( V_123 != ( V_125 * 2 ) ) {
V_7 -> error = L_67 ;
goto V_126;
}
V_35 = F_13 ( V_9 , V_32 ) ;
if ( V_35 )
goto V_126;
V_9 -> V_18 . V_127 = F_37 ;
V_35 = F_47 ( V_7 , V_9 ) ;
if ( V_35 )
goto V_126;
F_51 ( & V_9 -> V_18 . V_82 , F_28 ) ;
V_7 -> V_128 = V_9 ;
V_7 -> V_129 = 1 ;
F_52 ( & V_9 -> V_18 . V_130 ) ;
V_35 = F_53 ( & V_9 -> V_18 ) ;
V_9 -> V_18 . V_131 = 0 ;
F_54 ( & V_9 -> V_18 . V_130 ) ;
if ( V_35 ) {
V_7 -> error = L_68 ;
goto V_126;
}
V_9 -> V_86 . V_132 = F_31 ;
F_55 ( V_7 -> V_39 , & V_9 -> V_86 ) ;
F_56 ( & V_9 -> V_18 ) ;
return 0 ;
V_126:
F_9 ( V_9 ) ;
return V_35 ;
}
static void F_57 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
F_58 ( & V_9 -> V_86 . V_133 ) ;
F_59 ( & V_9 -> V_18 ) ;
F_9 ( V_9 ) ;
}
static int F_60 ( struct V_6 * V_7 , struct V_134 * V_134 , union V_135 * V_136 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
struct V_38 * V_38 = & V_9 -> V_18 ;
V_38 -> V_137 -> V_138 ( V_38 , V_134 ) ;
return V_139 ;
}
static int F_61 ( struct V_6 * V_7 , T_4 type ,
char * V_140 , unsigned V_141 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
unsigned V_142 = 1 ;
unsigned V_143 = 0 ;
int V_3 , V_144 = 0 ;
T_1 V_145 ;
switch ( type ) {
case V_146 :
F_62 ( L_69 , V_9 -> V_1 -> V_2 , V_9 -> V_18 . V_19 ) ;
if ( F_17 ( V_147 , & V_9 -> V_18 . V_148 ) )
V_145 = V_9 -> V_18 . V_149 ;
else
V_145 = V_9 -> V_18 . V_26 ;
if ( V_145 >= V_9 -> V_18 . V_150 ) {
V_144 = 1 ;
V_145 = V_9 -> V_18 . V_150 ;
} else {
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( ! F_17 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
V_144 = 1 ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( F_17 ( V_95 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
F_62 ( L_70 ) ;
else if ( ! V_144 ||
! F_17 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
F_62 ( L_71 ) ;
else
F_62 ( L_72 ) ;
}
F_62 ( L_73 ,
( unsigned long long ) V_145 ,
( unsigned long long ) V_9 -> V_18 . V_150 ) ;
break;
case V_151 :
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( ( V_9 -> V_61 & V_64 ) &&
V_9 -> V_15 [ V_3 ] . V_31 &&
! F_17 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
V_142 += 2 ;
if ( V_9 -> V_15 [ V_3 ] . V_31 &&
F_17 ( V_65 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
V_142 += 2 ;
}
V_142 += ( F_63 ( V_9 -> V_61 & ~ V_64 ) * 2 ) ;
if ( V_9 -> V_61 & ( V_63 | V_62 ) )
V_142 -- ;
F_62 ( L_74 , V_9 -> V_1 -> V_2 ,
V_142 , V_9 -> V_18 . V_52 ) ;
if ( ( V_9 -> V_61 & V_63 ) &&
( V_9 -> V_18 . V_26 == V_60 ) )
F_62 ( L_75 ) ;
if ( V_9 -> V_61 & V_62 )
F_62 ( L_76 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( ( V_9 -> V_61 & V_64 ) &&
V_9 -> V_15 [ V_3 ] . V_31 &&
! F_17 ( V_40 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
F_62 ( L_77 , V_3 ) ;
if ( V_9 -> V_61 & V_69 )
F_62 ( L_78 ,
V_9 -> V_18 . V_53 . V_71 ) ;
if ( V_9 -> V_61 & V_73 )
F_62 ( L_79 , V_9 -> V_18 . V_75 ) ;
if ( V_9 -> V_61 & V_76 )
F_62 ( L_80 , V_9 -> V_18 . V_77 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( V_9 -> V_15 [ V_3 ] . V_31 &&
F_17 ( V_65 , & V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) )
F_62 ( L_81 , V_3 ) ;
if ( V_9 -> V_61 & V_66 )
F_62 ( L_82 ,
V_9 -> V_18 . V_53 . V_68 ) ;
if ( V_9 -> V_61 & V_72 ) {
struct V_152 * V_153 = V_9 -> V_18 . V_128 ;
F_62 ( L_83 ,
V_153 ? V_153 -> V_154 * 2 : 0 ) ;
}
if ( V_9 -> V_61 & V_78 )
F_62 ( L_84 ,
V_9 -> V_18 . V_53 . V_54 >> 9 ) ;
F_62 ( L_85 , V_9 -> V_18 . V_19 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( V_9 -> V_15 [ V_3 ] . V_28 )
F_62 ( L_86 , V_9 -> V_15 [ V_3 ] . V_28 -> V_2 ) ;
else
F_62 ( L_87 ) ;
if ( V_9 -> V_15 [ V_3 ] . V_31 )
F_62 ( L_86 , V_9 -> V_15 [ V_3 ] . V_31 -> V_2 ) ;
else
F_62 ( L_87 ) ;
}
}
return 0 ;
}
static int F_64 ( struct V_6 * V_7 , T_5 V_155 , void * V_156 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
unsigned V_3 ;
int V_35 = 0 ;
for ( V_3 = 0 ; ! V_35 && V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( V_9 -> V_15 [ V_3 ] . V_31 )
V_35 = V_155 ( V_7 ,
V_9 -> V_15 [ V_3 ] . V_31 ,
0 ,
V_9 -> V_18 . V_21 ,
V_156 ) ;
return V_35 ;
}
static void F_65 ( struct V_6 * V_7 , struct V_157 * V_158 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
unsigned V_159 = V_9 -> V_18 . V_52 << 9 ;
struct V_152 * V_153 = V_9 -> V_18 . V_128 ;
F_66 ( V_158 , V_159 ) ;
F_67 ( V_158 , V_159 * ( V_153 -> V_19 - V_153 -> V_160 ) ) ;
}
static void F_68 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
F_69 ( & V_9 -> V_18 ) ;
}
static void F_70 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
F_56 ( & V_9 -> V_18 ) ;
}
static void F_71 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_128 ;
if ( ! V_9 -> V_161 ) {
F_72 ( & V_9 -> V_18 ) ;
V_9 -> V_161 = 1 ;
} else
F_73 ( V_9 -> V_18 . V_162 ) ;
F_74 ( & V_9 -> V_18 ) ;
}
static int T_6 F_75 ( void )
{
return F_76 ( & V_163 ) ;
}
static void T_7 F_77 ( void )
{
F_78 ( & V_163 ) ;
}
