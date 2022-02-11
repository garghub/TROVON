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
F_11 ( & V_9 -> V_15 [ V_3 ] . V_27 ) ;
if ( V_9 -> V_15 [ V_3 ] . V_29 )
F_10 ( V_9 -> V_7 , V_9 -> V_15 [ V_3 ] . V_29 ) ;
}
F_12 ( V_9 ) ;
}
static int F_13 ( struct V_5 * V_9 , char * * V_30 )
{
int V_3 ;
int V_31 = 0 ;
int V_32 = 0 ;
int V_33 = 0 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ , V_30 += 2 ) {
V_9 -> V_15 [ V_3 ] . V_27 . V_34 = V_3 ;
V_9 -> V_15 [ V_3 ] . V_28 = NULL ;
V_9 -> V_15 [ V_3 ] . V_29 = NULL ;
V_9 -> V_15 [ V_3 ] . V_27 . V_35 = 0 ;
V_9 -> V_15 [ V_3 ] . V_27 . V_36 = & V_9 -> V_18 ;
if ( strcmp ( V_30 [ 0 ] , L_4 ) ) {
V_33 = F_14 ( V_9 -> V_7 , V_30 [ 0 ] ,
F_15 ( V_9 -> V_7 -> V_37 ) ,
& V_9 -> V_15 [ V_3 ] . V_28 ) ;
V_9 -> V_7 -> error = L_5 ;
if ( V_33 )
return V_33 ;
V_9 -> V_15 [ V_3 ] . V_27 . V_38 = F_16 ( V_16 ) ;
if ( ! V_9 -> V_15 [ V_3 ] . V_27 . V_38 )
return - V_17 ;
}
if ( ! strcmp ( V_30 [ 1 ] , L_4 ) ) {
if ( ! F_17 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) &&
( ! V_9 -> V_15 [ V_3 ] . V_27 . V_41 ) ) {
V_9 -> V_7 -> error = L_6 ;
return - V_12 ;
}
V_9 -> V_7 -> error = L_7 ;
if ( V_9 -> V_15 [ V_3 ] . V_28 )
return - V_12 ;
continue;
}
V_33 = F_14 ( V_9 -> V_7 , V_30 [ 1 ] ,
F_15 ( V_9 -> V_7 -> V_37 ) ,
& V_9 -> V_15 [ V_3 ] . V_29 ) ;
if ( V_33 ) {
V_9 -> V_7 -> error = L_8 ;
return V_33 ;
}
if ( V_9 -> V_15 [ V_3 ] . V_28 ) {
V_32 = 1 ;
V_9 -> V_15 [ V_3 ] . V_27 . V_42 = V_9 -> V_15 [ V_3 ] . V_28 -> V_43 ;
}
V_9 -> V_15 [ V_3 ] . V_27 . V_43 = V_9 -> V_15 [ V_3 ] . V_29 -> V_43 ;
F_18 ( & V_9 -> V_15 [ V_3 ] . V_27 . V_44 , & V_9 -> V_18 . V_45 ) ;
if ( ! F_17 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
V_31 ++ ;
}
if ( V_32 ) {
V_9 -> V_18 . V_46 = 0 ;
V_9 -> V_18 . V_47 = 1 ;
V_9 -> V_18 . V_48 = 2 ;
} else if ( V_31 && ! V_9 -> V_18 . V_26 ) {
F_19 ( L_9 ) ;
V_9 -> V_7 -> error = L_8 ;
return - V_12 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_9 , unsigned long V_49 )
{
unsigned long V_50 = V_9 -> V_7 -> V_13 / ( 1 << 21 ) ;
if ( ! V_49 ) {
if ( V_50 > ( 1 << 13 ) ) {
F_21 ( L_10 ,
V_49 ) ;
V_49 = V_50 ;
} else {
F_21 ( L_11 ) ;
V_49 = 1 << 13 ;
}
} else {
if ( V_49 > V_9 -> V_7 -> V_13 ) {
V_9 -> V_7 -> error = L_12 ;
return - V_12 ;
}
if ( V_49 < V_50 ) {
F_19 ( L_13 ,
V_49 , V_50 ) ;
V_9 -> V_7 -> error = L_14 ;
return - V_12 ;
}
if ( ! F_22 ( V_49 ) ) {
V_9 -> V_7 -> error = L_15 ;
return - V_12 ;
}
if ( V_49 < V_9 -> V_18 . V_51 ) {
V_9 -> V_7 -> error = L_16 ;
return - V_12 ;
}
}
V_9 -> V_18 . V_52 . V_53 = ( V_49 << 9 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_9 , char * * V_30 ,
unsigned V_54 )
{
unsigned V_3 , V_55 = 0 ;
unsigned long V_56 , V_49 = 0 ;
char * V_57 ;
if ( ( F_24 ( V_30 [ 0 ] , 10 , & V_56 ) < 0 ) ) {
V_9 -> V_7 -> error = L_17 ;
return - V_12 ;
} else if ( V_9 -> V_1 -> V_14 == 1 ) {
if ( V_56 )
F_19 ( L_18 ) ;
V_56 = 0 ;
} else if ( ! F_22 ( V_56 ) ) {
V_9 -> V_7 -> error = L_19 ;
return - V_12 ;
} else if ( V_56 < 8 ) {
V_9 -> V_7 -> error = L_20 ;
return - V_12 ;
}
V_9 -> V_18 . V_58 = V_9 -> V_18 . V_51 = V_56 ;
V_30 ++ ;
V_54 -- ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
F_25 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) ;
V_9 -> V_15 [ V_3 ] . V_27 . V_41 = V_59 ;
}
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
if ( ! strcasecmp ( V_30 [ V_3 ] , L_21 ) ) {
V_9 -> V_18 . V_26 = V_59 ;
V_9 -> V_60 |= V_61 ;
continue;
}
if ( ! strcasecmp ( V_30 [ V_3 ] , L_22 ) ) {
V_9 -> V_18 . V_26 = 0 ;
V_9 -> V_60 |= V_62 ;
continue;
}
if ( ( V_3 + 1 ) >= V_54 ) {
V_9 -> V_7 -> error = L_23 ;
return - V_12 ;
}
V_57 = V_30 [ V_3 ++ ] ;
if ( F_24 ( V_30 [ V_3 ] , 10 , & V_56 ) < 0 ) {
V_9 -> V_7 -> error = L_24 ;
return - V_12 ;
}
if ( ! strcasecmp ( V_57 , L_25 ) ) {
V_55 ++ ;
if ( ( ( V_9 -> V_1 -> V_14 != 1 ) &&
( V_55 > V_9 -> V_1 -> V_11 ) ) ||
( ( V_9 -> V_1 -> V_14 == 1 ) &&
( V_55 > ( V_9 -> V_18 . V_19 - 1 ) ) ) ) {
V_9 -> V_7 -> error = L_26 ;
return - V_12 ;
}
if ( V_56 > V_9 -> V_18 . V_19 ) {
V_9 -> V_7 -> error = L_27 ;
return - V_12 ;
}
F_26 ( V_39 , & V_9 -> V_15 [ V_56 ] . V_27 . V_40 ) ;
V_9 -> V_15 [ V_56 ] . V_27 . V_41 = 0 ;
V_9 -> V_60 |= V_63 ;
} else if ( ! strcasecmp ( V_57 , L_28 ) ) {
if ( V_9 -> V_1 -> V_14 != 1 ) {
V_9 -> V_7 -> error = L_29 ;
return - V_12 ;
}
if ( V_56 >= V_9 -> V_18 . V_19 ) {
V_9 -> V_7 -> error = L_30 ;
return - V_12 ;
}
F_25 ( V_64 , & V_9 -> V_15 [ V_56 ] . V_27 . V_40 ) ;
} else if ( ! strcasecmp ( V_57 , L_31 ) ) {
if ( V_9 -> V_1 -> V_14 != 1 ) {
V_9 -> V_7 -> error = L_32 ;
return - V_12 ;
}
V_9 -> V_60 |= V_65 ;
V_56 /= 2 ;
if ( V_56 > V_66 ) {
V_9 -> V_7 -> error = L_33 ;
return - V_12 ;
}
V_9 -> V_18 . V_52 . V_67 = V_56 ;
} else if ( ! strcasecmp ( V_57 , L_34 ) ) {
V_9 -> V_60 |= V_68 ;
if ( ! V_56 || ( V_56 > V_69 ) ) {
V_9 -> V_7 -> error = L_35 ;
return - V_12 ;
}
V_9 -> V_18 . V_52 . V_70 = V_56 ;
} else if ( ! strcasecmp ( V_57 , L_36 ) ) {
V_9 -> V_60 |= V_71 ;
V_56 /= 2 ;
if ( V_9 -> V_1 -> V_14 < 5 ) {
V_9 -> V_7 -> error = L_37 ;
return - V_12 ;
}
if ( F_27 ( & V_9 -> V_18 , ( int ) V_56 ) ) {
V_9 -> V_7 -> error = L_38 ;
return - V_12 ;
}
} else if ( ! strcasecmp ( V_57 , L_39 ) ) {
V_9 -> V_60 |= V_72 ;
if ( V_56 > V_73 ) {
V_9 -> V_7 -> error = L_40 ;
return - V_12 ;
}
V_9 -> V_18 . V_74 = ( int ) V_56 ;
} else if ( ! strcasecmp ( V_57 , L_41 ) ) {
V_9 -> V_60 |= V_75 ;
if ( V_56 > V_73 ) {
V_9 -> V_7 -> error = L_42 ;
return - V_12 ;
}
V_9 -> V_18 . V_76 = ( int ) V_56 ;
} else if ( ! strcasecmp ( V_57 , L_43 ) ) {
V_9 -> V_60 |= V_77 ;
V_49 = V_56 ;
} else {
F_19 ( L_44 , V_57 ) ;
V_9 -> V_7 -> error = L_45 ;
return - V_12 ;
}
}
if ( F_20 ( V_9 , V_49 ) )
return - V_12 ;
if ( V_9 -> V_18 . V_51 )
V_9 -> V_7 -> V_78 = V_9 -> V_18 . V_51 ;
else
V_9 -> V_7 -> V_78 = V_49 ;
if ( V_9 -> V_18 . V_51 )
V_9 -> V_7 -> V_78 = V_9 -> V_18 . V_51 ;
else
V_9 -> V_7 -> V_78 = V_49 ;
V_9 -> V_18 . V_47 = 0 ;
V_9 -> V_18 . V_46 = 1 ;
return 0 ;
}
static void F_28 ( struct V_79 * V_80 )
{
struct V_5 * V_9 = F_29 ( V_80 , struct V_5 , V_18 . V_81 ) ;
F_30 ( V_9 -> V_7 -> V_37 ) ;
}
static int F_31 ( struct V_82 * V_83 , int V_84 )
{
struct V_5 * V_9 = F_29 ( V_83 , struct V_5 , V_85 ) ;
if ( V_9 -> V_1 -> V_14 == 1 )
return F_32 ( & V_9 -> V_18 , V_84 ) ;
return F_33 ( & V_9 -> V_18 , V_84 ) ;
}
static int F_34 ( struct V_86 * V_27 , int V_87 )
{
F_35 ( ! V_27 -> V_38 ) ;
if ( V_27 -> V_88 )
return 0 ;
if ( ! F_36 ( V_27 , 0 , V_87 , V_27 -> V_38 , V_89 , 1 ) ) {
F_19 ( L_46 ,
V_27 -> V_34 ) ;
F_37 ( V_27 -> V_36 , V_27 ) ;
return - V_12 ;
}
V_27 -> V_88 = 1 ;
return 0 ;
}
static void F_38 ( struct V_36 * V_36 , struct V_86 * V_27 )
{
int V_3 ;
T_2 V_90 ;
struct V_91 * V_92 ;
struct V_5 * V_9 = F_29 ( V_36 , struct V_5 , V_18 ) ;
V_92 = F_39 ( V_27 -> V_38 ) ;
V_90 = F_40 ( V_92 -> V_90 ) ;
for ( V_3 = 0 ; V_3 < V_36 -> V_19 ; V_3 ++ )
if ( ! V_9 -> V_15 [ V_3 ] . V_29 ||
F_17 ( V_93 , & ( V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) ) )
V_90 |= ( 1ULL << V_3 ) ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_94 = F_41 ( V_95 ) ;
V_92 -> V_96 = F_41 ( 0 ) ;
V_92 -> V_97 = F_41 ( V_36 -> V_19 ) ;
V_92 -> V_98 = F_41 ( V_27 -> V_34 ) ;
V_92 -> V_99 = F_42 ( V_36 -> V_99 ) ;
V_92 -> V_90 = F_42 ( V_90 ) ;
V_92 -> V_100 = F_42 ( V_27 -> V_41 ) ;
V_92 -> V_101 = F_42 ( V_36 -> V_26 ) ;
V_92 -> V_14 = F_41 ( V_36 -> V_14 ) ;
V_92 -> V_22 = F_41 ( V_36 -> V_22 ) ;
V_92 -> V_102 = F_41 ( V_36 -> V_51 ) ;
}
static int F_43 ( struct V_86 * V_27 , struct V_86 * V_103 )
{
int V_33 ;
struct V_91 * V_92 ;
struct V_91 * V_104 ;
T_2 V_105 , V_106 ;
V_27 -> V_107 = 0 ;
V_27 -> V_108 = sizeof( * V_92 ) ;
V_33 = F_34 ( V_27 , V_27 -> V_108 ) ;
if ( V_33 )
return V_33 ;
V_92 = F_39 ( V_27 -> V_38 ) ;
if ( ( V_92 -> V_94 != F_41 ( V_95 ) ) ||
( ! F_17 ( V_39 , & V_27 -> V_40 ) && ! V_27 -> V_41 ) ) {
F_38 ( V_27 -> V_36 , V_27 ) ;
F_25 ( V_109 , & V_27 -> V_40 ) ;
F_25 ( V_110 , & V_27 -> V_36 -> V_40 ) ;
return V_103 ? 0 : 1 ;
}
if ( ! V_103 )
return 1 ;
V_105 = F_40 ( V_92 -> V_99 ) ;
V_104 = F_39 ( V_103 -> V_38 ) ;
V_106 = F_40 ( V_104 -> V_99 ) ;
return ( V_105 > V_106 ) ? 1 : 0 ;
}
static int F_44 ( struct V_36 * V_36 , struct V_86 * V_27 )
{
int V_111 ;
struct V_5 * V_9 = F_29 ( V_36 , struct V_5 , V_18 ) ;
T_2 V_105 ;
T_2 V_90 ;
struct V_91 * V_92 ;
T_3 V_112 = 0 ;
T_3 V_113 = 0 ;
struct V_86 * V_114 ;
struct V_91 * V_115 ;
V_92 = F_39 ( V_27 -> V_38 ) ;
V_105 = F_40 ( V_92 -> V_99 ) ;
V_90 = F_40 ( V_92 -> V_90 ) ;
V_36 -> V_99 = V_105 ? : 1 ;
if ( ( F_45 ( V_92 -> V_14 ) != V_36 -> V_14 ) ||
( F_45 ( V_92 -> V_22 ) != V_36 -> V_22 ) ||
( F_45 ( V_92 -> V_102 ) != V_36 -> V_51 ) ) {
F_19 ( L_47 ) ;
return - V_12 ;
}
if ( ( V_9 -> V_1 -> V_14 != 1 ) &&
( F_45 ( V_92 -> V_97 ) != V_36 -> V_19 ) ) {
F_19 ( L_47 ) ;
return - V_12 ;
}
if ( ! ( V_9 -> V_60 & ( V_62 | V_61 ) ) )
V_36 -> V_26 = F_40 ( V_92 -> V_101 ) ;
F_46 (r, mddev) {
if ( ! F_17 ( V_39 , & V_114 -> V_40 ) ) {
F_21 ( L_48
L_49 , V_114 -> V_34 ) ;
V_113 ++ ;
} else if ( F_17 ( V_109 , & V_114 -> V_40 ) )
V_112 ++ ;
}
if ( ! V_113 ) {
if ( V_112 == V_36 -> V_19 ) {
F_21 ( L_50 ) ;
F_25 ( V_116 , & V_36 -> V_40 ) ;
} else if ( V_112 ) {
F_19 ( L_51
L_52
L_53 ) ;
return - V_12 ;
}
} else if ( V_112 ) {
F_19 ( L_54
L_55 ) ;
return - V_12 ;
} else if ( V_36 -> V_26 != V_59 ) {
F_19 ( L_56 ) ;
return - V_12 ;
}
F_46 (r, mddev) {
if ( ! V_114 -> V_38 )
continue;
V_115 = F_39 ( V_114 -> V_38 ) ;
V_115 -> V_90 = 0 ;
if ( ! F_17 ( V_109 , & V_114 -> V_40 ) && ( V_114 -> V_34 >= 0 ) ) {
V_111 = F_45 ( V_115 -> V_98 ) ;
if ( V_111 != V_114 -> V_34 ) {
if ( V_9 -> V_1 -> V_14 != 1 ) {
V_9 -> V_7 -> error = L_57
L_58 ;
return - V_12 ;
}
F_21 ( L_59 ,
V_111 , V_114 -> V_34 ) ;
}
if ( V_90 & ( 1 << V_111 ) )
F_25 ( V_93 , & V_114 -> V_40 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_36 * V_36 , struct V_86 * V_27 )
{
struct V_91 * V_92 = F_39 ( V_27 -> V_38 ) ;
if ( ! V_36 -> V_99 && F_44 ( V_36 , V_27 ) )
return - V_12 ;
V_36 -> V_52 . V_117 = 4096 >> 9 ;
V_27 -> V_36 -> V_52 . V_118 = 4096 >> 9 ;
if ( ! F_17 ( V_109 , & V_27 -> V_40 ) ) {
V_27 -> V_41 = F_40 ( V_92 -> V_100 ) ;
if ( V_27 -> V_41 != V_59 )
F_26 ( V_39 , & V_27 -> V_40 ) ;
}
if ( F_17 ( V_93 , & V_27 -> V_40 ) ) {
F_26 ( V_93 , & V_27 -> V_40 ) ;
F_26 ( V_39 , & V_27 -> V_40 ) ;
V_27 -> V_119 = V_27 -> V_34 ;
V_27 -> V_41 = 0 ;
}
F_26 ( V_109 , & V_27 -> V_40 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
int V_33 ;
unsigned V_120 = 0 ;
struct V_121 * V_15 ;
struct V_86 * V_27 , * V_122 , * V_123 ;
struct V_36 * V_36 = & V_9 -> V_18 ;
switch ( V_9 -> V_1 -> V_14 ) {
case 1 :
V_120 = V_9 -> V_18 . V_19 - 1 ;
break;
case 4 :
case 5 :
case 6 :
V_120 = V_9 -> V_1 -> V_11 ;
break;
default:
V_7 -> error = L_60 ;
return - V_12 ;
}
V_123 = NULL ;
F_49 (rdev, tmp, mddev) {
if ( ! V_27 -> V_42 )
continue;
V_33 = F_43 ( V_27 , V_123 ) ;
switch ( V_33 ) {
case 1 :
V_123 = V_27 ;
break;
case 0 :
break;
default:
V_15 = F_29 ( V_27 , struct V_121 , V_27 ) ;
if ( V_120 -- ) {
if ( V_15 -> V_28 )
F_10 ( V_7 , V_15 -> V_28 ) ;
V_15 -> V_28 = NULL ;
V_27 -> V_42 = NULL ;
if ( V_27 -> V_38 )
F_50 ( V_27 -> V_38 ) ;
V_27 -> V_38 = NULL ;
V_27 -> V_88 = 0 ;
if ( V_15 -> V_29 )
F_10 ( V_7 , V_15 -> V_29 ) ;
V_15 -> V_29 = NULL ;
V_27 -> V_43 = NULL ;
F_51 ( & V_27 -> V_44 ) ;
continue;
}
V_7 -> error = L_61 ;
return V_33 ;
}
}
if ( ! V_123 )
return 0 ;
V_7 -> error = L_62 ;
if ( F_47 ( V_36 , V_123 ) )
return - V_12 ;
F_46 (rdev, mddev)
if ( ( V_27 != V_123 ) && F_47 ( V_36 , V_27 ) )
return - V_12 ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 , unsigned V_124 , char * * V_30 )
{
int V_33 ;
struct V_1 * V_125 ;
unsigned long V_54 , V_126 ;
struct V_5 * V_9 = NULL ;
if ( V_124 < 2 ) {
V_7 -> error = L_63 ;
return - V_12 ;
}
V_125 = F_1 ( V_30 [ 0 ] ) ;
if ( ! V_125 ) {
V_7 -> error = L_64 ;
return - V_12 ;
}
V_124 -- ;
V_30 ++ ;
if ( F_24 ( V_30 [ 0 ] , 10 , & V_54 ) < 0 ) {
V_7 -> error = L_65 ;
return - V_12 ;
}
V_124 -- ;
V_30 ++ ;
if ( V_54 + 1 > V_124 ) {
V_7 -> error = L_66 ;
return - V_12 ;
}
if ( ( F_24 ( V_30 [ V_54 ] , 10 , & V_126 ) < 0 ) ||
( V_126 >= V_73 ) ) {
V_7 -> error = L_67 ;
return - V_12 ;
}
V_9 = F_3 ( V_7 , V_125 , ( unsigned ) V_126 ) ;
if ( F_53 ( V_9 ) )
return F_54 ( V_9 ) ;
V_33 = F_23 ( V_9 , V_30 , ( unsigned ) V_54 ) ;
if ( V_33 )
goto V_127;
V_33 = - V_12 ;
V_124 -= V_54 + 1 ;
V_30 += V_54 + 1 ;
if ( V_124 != ( V_126 * 2 ) ) {
V_7 -> error = L_68 ;
goto V_127;
}
V_33 = F_13 ( V_9 , V_30 ) ;
if ( V_33 )
goto V_127;
V_9 -> V_18 . V_128 = F_38 ;
V_33 = F_48 ( V_7 , V_9 ) ;
if ( V_33 )
goto V_127;
F_55 ( & V_9 -> V_18 . V_81 , F_28 ) ;
V_7 -> V_129 = V_9 ;
V_7 -> V_130 = 1 ;
F_56 ( & V_9 -> V_18 . V_131 ) ;
V_33 = F_57 ( & V_9 -> V_18 ) ;
V_9 -> V_18 . V_132 = 0 ;
F_58 ( & V_9 -> V_18 . V_131 ) ;
if ( V_33 ) {
V_7 -> error = L_69 ;
goto V_127;
}
V_9 -> V_85 . V_133 = F_31 ;
F_59 ( V_7 -> V_37 , & V_9 -> V_85 ) ;
F_60 ( & V_9 -> V_18 ) ;
return 0 ;
V_127:
F_9 ( V_9 ) ;
return V_33 ;
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
F_62 ( & V_9 -> V_85 . V_134 ) ;
F_63 ( & V_9 -> V_18 ) ;
F_9 ( V_9 ) ;
}
static int F_64 ( struct V_6 * V_7 , struct V_135 * V_135 , union V_136 * V_137 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
struct V_36 * V_36 = & V_9 -> V_18 ;
V_36 -> V_138 -> V_139 ( V_36 , V_135 ) ;
return V_140 ;
}
static int F_65 ( struct V_6 * V_7 , T_4 type ,
char * V_141 , unsigned V_142 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
unsigned V_143 = 1 ;
unsigned V_144 = 0 ;
int V_3 , V_145 = 0 ;
T_1 V_146 ;
switch ( type ) {
case V_147 :
F_66 ( L_70 , V_9 -> V_1 -> V_2 , V_9 -> V_18 . V_19 ) ;
if ( F_17 ( V_148 , & V_9 -> V_18 . V_149 ) )
V_146 = V_9 -> V_18 . V_150 ;
else
V_146 = V_9 -> V_18 . V_26 ;
if ( V_146 >= V_9 -> V_18 . V_151 ) {
V_145 = 1 ;
V_146 = V_9 -> V_18 . V_151 ;
} else {
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( ! F_17 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
V_145 = 1 ;
}
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( F_17 ( V_93 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
F_66 ( L_71 ) ;
else if ( ! V_145 ||
! F_17 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
F_66 ( L_72 ) ;
else
F_66 ( L_73 ) ;
}
F_66 ( L_74 ,
( unsigned long long ) V_146 ,
( unsigned long long ) V_9 -> V_18 . V_151 ) ;
break;
case V_152 :
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( ( V_9 -> V_60 & V_63 ) &&
V_9 -> V_15 [ V_3 ] . V_29 &&
! F_17 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
V_143 += 2 ;
if ( V_9 -> V_15 [ V_3 ] . V_29 &&
F_17 ( V_64 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
V_143 += 2 ;
}
V_143 += ( F_67 ( V_9 -> V_60 & ~ V_63 ) * 2 ) ;
if ( V_9 -> V_60 & ( V_62 | V_61 ) )
V_143 -- ;
F_66 ( L_75 , V_9 -> V_1 -> V_2 ,
V_143 , V_9 -> V_18 . V_51 ) ;
if ( ( V_9 -> V_60 & V_62 ) &&
( V_9 -> V_18 . V_26 == V_59 ) )
F_66 ( L_76 ) ;
if ( V_9 -> V_60 & V_61 )
F_66 ( L_77 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( ( V_9 -> V_60 & V_63 ) &&
V_9 -> V_15 [ V_3 ] . V_29 &&
! F_17 ( V_39 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
F_66 ( L_78 , V_3 ) ;
if ( V_9 -> V_60 & V_68 )
F_66 ( L_79 ,
V_9 -> V_18 . V_52 . V_70 ) ;
if ( V_9 -> V_60 & V_72 )
F_66 ( L_80 , V_9 -> V_18 . V_74 ) ;
if ( V_9 -> V_60 & V_75 )
F_66 ( L_81 , V_9 -> V_18 . V_76 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( V_9 -> V_15 [ V_3 ] . V_29 &&
F_17 ( V_64 , & V_9 -> V_15 [ V_3 ] . V_27 . V_40 ) )
F_66 ( L_82 , V_3 ) ;
if ( V_9 -> V_60 & V_65 )
F_66 ( L_83 ,
V_9 -> V_18 . V_52 . V_67 ) ;
if ( V_9 -> V_60 & V_71 ) {
struct V_153 * V_154 = V_9 -> V_18 . V_129 ;
F_66 ( L_84 ,
V_154 ? V_154 -> V_155 * 2 : 0 ) ;
}
if ( V_9 -> V_60 & V_77 )
F_66 ( L_85 ,
V_9 -> V_18 . V_52 . V_53 >> 9 ) ;
F_66 ( L_86 , V_9 -> V_18 . V_19 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_18 . V_19 ; V_3 ++ ) {
if ( V_9 -> V_15 [ V_3 ] . V_28 )
F_66 ( L_87 , V_9 -> V_15 [ V_3 ] . V_28 -> V_2 ) ;
else
F_66 ( L_88 ) ;
if ( V_9 -> V_15 [ V_3 ] . V_29 )
F_66 ( L_87 , V_9 -> V_15 [ V_3 ] . V_29 -> V_2 ) ;
else
F_66 ( L_88 ) ;
}
}
return 0 ;
}
static int F_68 ( struct V_6 * V_7 , T_5 V_156 , void * V_157 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
unsigned V_3 ;
int V_33 = 0 ;
for ( V_3 = 0 ; ! V_33 && V_3 < V_9 -> V_18 . V_19 ; V_3 ++ )
if ( V_9 -> V_15 [ V_3 ] . V_29 )
V_33 = V_156 ( V_7 ,
V_9 -> V_15 [ V_3 ] . V_29 ,
0 ,
V_9 -> V_18 . V_21 ,
V_157 ) ;
return V_33 ;
}
static void F_69 ( struct V_6 * V_7 , struct V_158 * V_159 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
unsigned V_160 = V_9 -> V_18 . V_51 << 9 ;
struct V_153 * V_154 = V_9 -> V_18 . V_129 ;
F_70 ( V_159 , V_160 ) ;
F_71 ( V_159 , V_160 * ( V_154 -> V_19 - V_154 -> V_161 ) ) ;
}
static void F_72 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
F_73 ( & V_9 -> V_18 ) ;
}
static void F_74 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
F_60 ( & V_9 -> V_18 ) ;
}
static void F_75 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_129 ;
F_25 ( V_110 , & V_9 -> V_18 . V_40 ) ;
if ( ! V_9 -> V_162 ) {
F_76 ( & V_9 -> V_18 ) ;
V_9 -> V_162 = 1 ;
}
F_26 ( V_163 , & V_9 -> V_18 . V_149 ) ;
F_77 ( & V_9 -> V_18 ) ;
}
static int T_6 F_78 ( void )
{
return F_79 ( & V_164 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_164 ) ;
}
