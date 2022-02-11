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
if ( F_5 ( V_10 , ( V_8 - V_1 -> V_11 ) ) ) {
V_7 -> error = L_2 ;
return F_4 ( - V_12 ) ;
}
V_9 = F_6 ( sizeof( * V_9 ) + V_8 * sizeof( V_9 -> V_14 [ 0 ] ) , V_15 ) ;
if ( ! V_9 ) {
V_7 -> error = L_3 ;
return F_4 ( - V_16 ) ;
}
F_7 ( & V_9 -> V_17 ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_1 = V_1 ;
V_9 -> V_17 . V_18 = V_8 ;
V_9 -> V_17 . V_19 = V_1 -> V_19 ;
V_9 -> V_17 . V_20 = V_9 -> V_17 . V_19 ;
V_9 -> V_17 . V_21 = V_10 ;
V_9 -> V_17 . V_22 = V_1 -> V_23 ;
V_9 -> V_17 . V_24 = V_9 -> V_17 . V_22 ;
V_9 -> V_17 . V_25 = 0 ;
V_9 -> V_17 . V_26 = 0 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ )
F_8 ( & V_9 -> V_14 [ V_3 ] . V_27 ) ;
return V_9 ;
}
static void F_9 ( struct V_5 * V_9 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ )
if ( V_9 -> V_14 [ V_3 ] . V_28 )
F_10 ( V_9 -> V_7 , V_9 -> V_14 [ V_3 ] . V_28 ) ;
F_11 ( V_9 ) ;
}
static int F_12 ( struct V_5 * V_9 , char * * V_29 )
{
int V_3 ;
int V_30 = 0 ;
int V_31 = 0 ;
int V_32 = 0 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ , V_29 += 2 ) {
V_9 -> V_14 [ V_3 ] . V_27 . V_33 = V_3 ;
V_9 -> V_14 [ V_3 ] . V_34 = NULL ;
V_9 -> V_14 [ V_3 ] . V_28 = NULL ;
V_9 -> V_14 [ V_3 ] . V_27 . V_35 = 0 ;
V_9 -> V_14 [ V_3 ] . V_27 . V_36 = & V_9 -> V_17 ;
if ( strcmp ( V_29 [ 0 ] , L_4 ) ) {
V_9 -> V_7 -> error = L_5 ;
return - V_12 ;
}
if ( ! strcmp ( V_29 [ 1 ] , L_4 ) ) {
if ( ! F_13 ( V_37 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) &&
( ! V_9 -> V_14 [ V_3 ] . V_27 . V_39 ) ) {
V_9 -> V_7 -> error = L_6 ;
return - V_12 ;
}
continue;
}
V_32 = F_14 ( V_9 -> V_7 , V_29 [ 1 ] ,
F_15 ( V_9 -> V_7 -> V_40 ) ,
& V_9 -> V_14 [ V_3 ] . V_28 ) ;
if ( V_32 ) {
V_9 -> V_7 -> error = L_7 ;
return V_32 ;
}
V_9 -> V_14 [ V_3 ] . V_27 . V_41 = V_9 -> V_14 [ V_3 ] . V_28 -> V_41 ;
F_16 ( & V_9 -> V_14 [ V_3 ] . V_27 . V_42 , & V_9 -> V_17 . V_43 ) ;
if ( ! F_13 ( V_37 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) )
V_30 ++ ;
}
if ( V_31 ) {
V_9 -> V_17 . V_44 = 0 ;
V_9 -> V_17 . V_45 = 1 ;
V_9 -> V_17 . V_46 = 2 ;
} else if ( V_30 && ! V_9 -> V_17 . V_26 ) {
F_17 ( L_8 ) ;
V_9 -> V_7 -> error = L_7 ;
return - V_12 ;
}
return 0 ;
}
static int F_18 ( struct V_5 * V_9 , char * * V_29 ,
unsigned V_47 )
{
unsigned V_3 , V_48 = 0 ;
unsigned long V_49 ;
char * V_50 ;
if ( ( F_19 ( V_29 [ 0 ] , 10 , & V_49 ) < 0 ) ||
! F_20 ( V_49 ) || ( V_49 < 8 ) ) {
V_9 -> V_7 -> error = L_9 ;
return - V_12 ;
}
V_9 -> V_17 . V_51 = V_9 -> V_17 . V_52 = V_49 ;
V_29 ++ ;
V_47 -- ;
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ )
F_21 ( V_37 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
if ( ! strcmp ( V_29 [ V_3 ] , L_10 ) ) {
V_9 -> V_17 . V_26 = V_53 ;
V_9 -> V_54 |= V_55 ;
V_9 -> V_17 . V_38 |= V_56 ;
continue;
}
if ( ! strcmp ( V_29 [ V_3 ] , L_11 ) ) {
V_9 -> V_17 . V_26 = 0 ;
V_9 -> V_54 |= V_57 ;
V_9 -> V_17 . V_38 |= V_56 ;
continue;
}
if ( ( V_3 + 1 ) >= V_47 ) {
V_9 -> V_7 -> error = L_12 ;
return - V_12 ;
}
V_50 = V_29 [ V_3 ++ ] ;
if ( F_19 ( V_29 [ V_3 ] , 10 , & V_49 ) < 0 ) {
V_9 -> V_7 -> error = L_13 ;
return - V_12 ;
}
if ( ! strcmp ( V_50 , L_14 ) ) {
if ( ++ V_48 > V_9 -> V_1 -> V_11 ) {
V_9 -> V_7 -> error = L_15 ;
return - V_12 ;
}
if ( V_49 > V_9 -> V_17 . V_18 ) {
V_9 -> V_7 -> error = L_16 ;
return - V_12 ;
}
F_22 ( V_37 , & V_9 -> V_14 [ V_49 ] . V_27 . V_38 ) ;
V_9 -> V_14 [ V_49 ] . V_27 . V_39 = 0 ;
} else if ( ! strcmp ( V_50 , L_17 ) ) {
V_9 -> V_54 |= V_58 ;
V_49 /= 2 ;
if ( V_49 > V_59 ) {
V_9 -> V_7 -> error = L_18 ;
return - V_12 ;
}
V_9 -> V_17 . V_60 . V_61 = V_49 ;
} else if ( ! strcmp ( V_50 , L_19 ) ) {
V_9 -> V_54 |= V_62 ;
if ( ! V_49 || ( V_49 > V_63 ) ) {
V_9 -> V_7 -> error = L_20 ;
return - V_12 ;
}
V_9 -> V_17 . V_60 . V_64 = V_49 ;
} else if ( ! strcmp ( V_50 , L_21 ) ) {
V_9 -> V_54 |= V_65 ;
V_49 /= 2 ;
if ( V_9 -> V_1 -> V_19 < 5 ) {
V_9 -> V_7 -> error = L_22 ;
return - V_12 ;
}
if ( F_23 ( & V_9 -> V_17 , ( int ) V_49 ) ) {
V_9 -> V_7 -> error = L_23 ;
return - V_12 ;
}
} else if ( ! strcmp ( V_50 , L_24 ) ) {
V_9 -> V_54 |= V_66 ;
if ( V_49 > V_67 ) {
V_9 -> V_7 -> error = L_25 ;
return - V_12 ;
}
V_9 -> V_17 . V_68 = ( int ) V_49 ;
} else if ( ! strcmp ( V_50 , L_26 ) ) {
V_9 -> V_54 |= V_69 ;
if ( V_49 > V_67 ) {
V_9 -> V_7 -> error = L_27 ;
return - V_12 ;
}
V_9 -> V_17 . V_70 = ( int ) V_49 ;
} else {
F_17 ( L_28 , V_50 ) ;
V_9 -> V_7 -> error = L_29 ;
return - V_12 ;
}
}
V_9 -> V_17 . V_45 = 0 ;
V_9 -> V_17 . V_44 = 1 ;
return 0 ;
}
static void F_24 ( struct V_71 * V_72 )
{
struct V_5 * V_9 = F_25 ( V_72 , struct V_5 , V_17 . V_73 ) ;
F_26 ( V_9 -> V_7 -> V_40 ) ;
}
static int F_27 ( struct V_74 * V_75 , int V_76 )
{
struct V_5 * V_9 = F_25 ( V_75 , struct V_5 , V_77 ) ;
return F_28 ( & V_9 -> V_17 , V_76 ) ;
}
static int F_29 ( struct V_6 * V_7 , unsigned V_78 , char * * V_29 )
{
int V_32 ;
struct V_1 * V_79 ;
unsigned long V_47 , V_80 ;
struct V_5 * V_9 = NULL ;
if ( V_78 < 2 ) {
V_7 -> error = L_30 ;
return - V_12 ;
}
V_79 = F_1 ( V_29 [ 0 ] ) ;
if ( ! V_79 ) {
V_7 -> error = L_31 ;
return - V_12 ;
}
V_78 -- ;
V_29 ++ ;
if ( F_19 ( V_29 [ 0 ] , 10 , & V_47 ) < 0 ) {
V_7 -> error = L_32 ;
return - V_12 ;
}
V_78 -- ;
V_29 ++ ;
if ( V_47 + 1 > V_78 ) {
V_7 -> error = L_33 ;
return - V_12 ;
}
if ( ( F_19 ( V_29 [ V_47 ] , 10 , & V_80 ) < 0 ) ||
( V_80 >= V_67 ) ) {
V_7 -> error = L_34 ;
return - V_12 ;
}
V_9 = F_3 ( V_7 , V_79 , ( unsigned ) V_80 ) ;
if ( F_30 ( V_9 ) )
return F_31 ( V_9 ) ;
V_32 = F_18 ( V_9 , V_29 , ( unsigned ) V_47 ) ;
if ( V_32 )
goto V_81;
V_32 = - V_12 ;
V_78 -= V_47 + 1 ;
V_29 += V_47 + 1 ;
if ( V_78 != ( V_80 * 2 ) ) {
V_7 -> error = L_35 ;
goto V_81;
}
V_32 = F_12 ( V_9 , V_29 ) ;
if ( V_32 )
goto V_81;
F_32 ( & V_9 -> V_17 . V_73 , F_24 ) ;
V_7 -> V_82 = V_9 -> V_17 . V_52 ;
V_7 -> V_83 = V_9 ;
F_33 ( & V_9 -> V_17 . V_84 ) ;
V_32 = F_34 ( & V_9 -> V_17 ) ;
V_9 -> V_17 . V_85 = 0 ;
F_35 ( & V_9 -> V_17 . V_84 ) ;
if ( V_32 ) {
V_7 -> error = L_36 ;
goto V_81;
}
V_9 -> V_77 . V_86 = F_27 ;
F_36 ( V_7 -> V_40 , & V_9 -> V_77 ) ;
return 0 ;
V_81:
F_9 ( V_9 ) ;
return V_32 ;
}
static void F_37 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
F_38 ( & V_9 -> V_77 . V_87 ) ;
F_39 ( & V_9 -> V_17 ) ;
F_9 ( V_9 ) ;
}
static int F_40 ( struct V_6 * V_7 , struct V_88 * V_88 , union V_89 * V_90 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
T_2 * V_36 = & V_9 -> V_17 ;
V_36 -> V_91 -> V_92 ( V_36 , V_88 ) ;
return V_93 ;
}
static int F_41 ( struct V_6 * V_7 , T_3 type ,
char * V_94 , unsigned V_95 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
unsigned V_96 = 1 ;
unsigned V_97 = 0 ;
int V_3 ;
T_1 V_98 ;
switch ( type ) {
case V_99 :
F_42 ( L_37 , V_9 -> V_1 -> V_2 , V_9 -> V_17 . V_18 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ ) {
if ( F_13 ( V_100 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) )
F_42 ( L_38 ) ;
else if ( F_13 ( V_37 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) )
F_42 ( L_39 ) ;
else
F_42 ( L_40 ) ;
}
if ( F_13 ( V_101 , & V_9 -> V_17 . V_102 ) )
V_98 = V_9 -> V_17 . V_103 ;
else
V_98 = V_9 -> V_17 . V_26 ;
if ( V_98 > V_9 -> V_17 . V_104 )
V_98 = V_9 -> V_17 . V_104 ;
F_42 ( L_41 ,
( unsigned long long ) V_98 ,
( unsigned long long ) V_9 -> V_17 . V_104 ) ;
break;
case V_105 :
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ )
if ( V_9 -> V_14 [ V_3 ] . V_28 &&
! F_13 ( V_37 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) )
V_96 ++ ;
V_96 += ( F_43 ( V_9 -> V_54 ) * 2 ) ;
if ( V_9 -> V_54 & ( V_57 | V_55 ) )
V_96 -- ;
F_42 ( L_42 , V_9 -> V_1 -> V_2 ,
V_96 , V_9 -> V_17 . V_52 ) ;
if ( ( V_9 -> V_54 & V_57 ) &&
( V_9 -> V_17 . V_26 == V_53 ) )
F_42 ( L_43 ) ;
if ( V_9 -> V_54 & V_55 )
F_42 ( L_44 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ )
if ( V_9 -> V_14 [ V_3 ] . V_28 &&
! F_13 ( V_37 , & V_9 -> V_14 [ V_3 ] . V_27 . V_38 ) )
F_42 ( L_45 , V_3 ) ;
if ( V_9 -> V_54 & V_62 )
F_42 ( L_46 ,
V_9 -> V_17 . V_60 . V_64 ) ;
if ( V_9 -> V_54 & V_66 )
F_42 ( L_47 , V_9 -> V_17 . V_68 ) ;
if ( V_9 -> V_54 & V_69 )
F_42 ( L_48 , V_9 -> V_17 . V_70 ) ;
if ( V_9 -> V_54 & V_58 )
F_42 ( L_49 ,
V_9 -> V_17 . V_60 . V_61 ) ;
if ( V_9 -> V_54 & V_65 ) {
T_4 * V_106 = V_9 -> V_17 . V_83 ;
F_42 ( L_50 ,
V_106 ? V_106 -> V_107 * 2 : 0 ) ;
}
F_42 ( L_51 , V_9 -> V_17 . V_18 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_17 . V_18 ; V_3 ++ ) {
F_42 ( L_52 ) ;
if ( V_9 -> V_14 [ V_3 ] . V_28 )
F_42 ( L_53 , V_9 -> V_14 [ V_3 ] . V_28 -> V_2 ) ;
else
F_42 ( L_52 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_6 * V_7 , T_5 V_108 , void * V_109 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
unsigned V_3 ;
int V_32 = 0 ;
for ( V_3 = 0 ; ! V_32 && V_3 < V_9 -> V_17 . V_18 ; V_3 ++ )
if ( V_9 -> V_14 [ V_3 ] . V_28 )
V_32 = V_108 ( V_7 ,
V_9 -> V_14 [ V_3 ] . V_28 ,
0 ,
V_9 -> V_17 . V_21 ,
V_109 ) ;
return V_32 ;
}
static void F_45 ( struct V_6 * V_7 , struct V_110 * V_111 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
unsigned V_112 = V_9 -> V_17 . V_52 << 9 ;
T_4 * V_106 = V_9 -> V_17 . V_83 ;
F_46 ( V_111 , V_112 ) ;
F_47 ( V_111 , V_112 * ( V_106 -> V_18 - V_106 -> V_113 ) ) ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
F_49 ( & V_9 -> V_17 ) ;
}
static void F_50 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
F_51 ( & V_9 -> V_17 ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_5 * V_9 = V_7 -> V_83 ;
F_53 ( & V_9 -> V_17 ) ;
}
static int T_6 F_54 ( void )
{
return F_55 ( & V_114 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_114 ) ;
}
