static int F_1 ( int V_1 )
{
int V_2 = V_1 / 2 ;
int V_3 = V_1 & 1 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 = V_12 [ 0 ] ;
T_1 V_13 ;
int V_14 ;
V_5 = F_2 ( V_2 , 0xC8 + V_3 , NULL ) ;
if ( V_5 == NULL ) {
F_3 ( V_15 L_1 ) ;
return - V_16 ;
}
V_7 = (struct V_6 * ) & V_5 [ 1 ] ;
V_5 = F_2 ( V_2 , 0xC4 + V_3 , NULL ) ;
if ( V_5 ) {
struct V_17 * V_18 = (struct V_17 * ) & V_5 [ 1 ] ;
V_13 = V_18 -> V_19 << 16 ;
} else
V_13 = 95 << 16 ;
if ( V_13 < V_20 )
V_20 = V_13 ;
V_14 = ( V_21 > 2 ) ? 750 : 515 ;
V_9 . V_22 = 1 ;
V_9 . V_23 = V_7 -> V_23 ;
V_9 . V_24 = V_7 -> V_24 ;
V_9 . V_25 = V_7 -> V_25 ;
V_9 . V_26 = V_7 -> V_26 / V_7 -> V_23 ;
V_9 . V_27 = ( V_7 -> V_28 << 16 ) - ( V_7 -> V_29 << 8 ) ;
V_9 . V_30 = V_13 - ( V_7 -> V_31 << 16 ) ;
V_9 . V_13 = V_13 ;
V_9 . V_32 = V_11 -> V_33 -> V_34 ( V_11 ) ;
V_9 . V_35 = V_11 -> V_33 -> V_36 ( V_11 ) ;
if ( V_9 . V_32 < V_14 )
V_9 . V_32 = V_14 ;
F_4 ( & V_37 [ V_1 ] , & V_9 ) ;
return 0 ;
}
static void F_5 ( void )
{
int V_38 ;
if ( V_39 )
F_6 ( V_39 ) ;
for ( V_38 = 0 ; V_38 < V_40 ; ++ V_38 )
if ( V_12 [ V_38 ] )
F_6 ( V_12 [ V_38 ] ) ;
}
static int F_7 ( T_1 V_41 )
{
int V_42 = 0 ;
T_1 V_43 , V_44 ;
if ( V_41 >= ( V_20 + V_45 ) ) {
V_42 |= V_46 ;
if ( ( V_47 & V_46 ) == 0 )
F_3 ( V_48 L_2
L_3 ) ;
}
if ( V_41 >= ( V_20 + V_49 ) ) {
V_42 |= V_50 ;
if ( ( V_47 & V_50 ) == 0 )
F_3 ( V_48 L_4
L_5 ) ;
}
V_44 = V_51 [ V_52 ] ;
V_51 [ V_52 ] = V_41 ;
V_52 = ( V_52 + 1 ) % V_53 ;
V_54 -= V_44 ;
V_54 += V_41 ;
V_43 = V_54 / V_53 ;
F_8 ( L_6 ,
F_9 ( V_43 ) , F_9 ( V_44 ) , F_9 ( V_41 ) ) ;
if ( V_43 >= ( V_20 + V_55 ) ) {
V_42 |= V_46 ;
if ( ( V_47 & V_46 ) == 0 )
F_3 ( V_48 L_7
L_3 ) ;
}
if ( V_43 >= ( V_20 + V_56 ) ) {
V_42 |= V_50 ;
if ( ( V_47 & V_50 ) == 0 )
F_3 ( V_48 L_4
L_8 ) ;
}
if ( V_42 ) {
if ( V_42 & V_50 )
F_10 () ;
if ( ( V_47 & V_42 ) != V_42 )
F_5 () ;
V_47 |= V_42 ;
} else if ( ( V_47 & V_46 ) &&
( V_41 < ( V_20 + V_57 ) ) ) {
F_3 ( V_48 L_9 ) ;
V_47 &= ~ V_46 ;
}
return V_47 & ( V_46 | V_50 ) ;
}
static void F_11 ( void )
{
int V_58 , V_1 ;
T_1 V_59 = 0 ;
T_1 V_41 , V_60 , V_61 = 0 ;
int V_38 , V_62 , V_63 = 0 ;
struct V_64 * V_65 ;
struct V_10 * V_66 ;
struct V_67 * V_68 ;
F_8 ( V_69 ) ;
for ( V_1 = 0 ; V_1 < V_21 ; ++ V_1 ) {
V_65 = V_70 [ V_1 ] ;
V_58 = V_65 -> V_33 -> V_71 ( V_65 , & V_41 ) ;
if ( V_58 ) {
F_12 ( L_10 ) ;
F_3 ( V_15 L_11
L_12 , V_1 , V_58 ) ;
V_47 |= V_72 ;
F_5 () ;
return;
}
V_61 = V_35 ( V_61 , V_41 ) ;
V_65 = V_73 [ V_1 ] ;
V_58 = V_65 -> V_33 -> V_71 ( V_65 , & V_60 ) ;
if ( V_58 ) {
F_12 ( L_10 ) ;
F_3 ( V_15 L_13
L_12 , V_1 , V_58 ) ;
V_47 |= V_72 ;
F_5 () ;
return;
}
V_68 = & V_37 [ V_1 ] ;
V_62 = F_13 ( V_68 , V_60 , V_41 ) ;
if ( V_1 == 0 || V_68 -> V_74 > V_59 ) {
V_59 = V_68 -> V_74 ;
V_63 = V_62 ;
}
F_8 ( L_14 ,
V_1 , F_9 ( V_60 ) , F_9 ( V_41 ) ) ;
}
F_8 ( L_15 , V_63 , F_9 ( V_61 ) ) ;
if ( V_63 < ( V_75 - 20 ) )
V_63 = V_75 - 20 ;
V_75 = V_63 ;
for ( V_1 = 0 ; V_1 < V_21 ; ++ V_1 )
V_37 [ V_1 ] . V_63 = V_63 ;
if ( F_7 ( V_61 ) )
return;
for ( V_38 = 0 ; V_38 < V_40 ; ++ V_38 ) {
V_66 = V_12 [ V_38 ] ;
if ( V_66 == NULL )
continue;
V_58 = V_66 -> V_33 -> V_76 ( V_66 , V_63 * V_77 [ V_38 ] / 100 ) ;
if ( V_58 ) {
F_3 ( V_15 L_16
L_17 , V_66 -> V_78 , V_58 ) ;
V_47 |= V_79 ;
break;
}
}
}
static void F_14 ( void )
{
T_1 V_41 ;
int V_80 ;
int V_58 ;
if ( ! V_81 || ! V_82 )
return;
if ( ! V_83 ) {
F_3 ( V_84 L_18 ) ;
V_85 . V_32 = V_81 -> V_33 -> V_34 ( V_81 ) ;
V_85 . V_35 = V_81 -> V_33 -> V_36 ( V_81 ) ;
F_15 ( & V_86 , & V_85 ) ;
V_83 = 1 ;
}
if ( -- V_83 > 0 )
return;
V_83 = V_86 . V_87 . V_22 ;
V_58 = V_82 -> V_33 -> V_71 ( V_82 , & V_41 ) ;
if ( V_58 ) {
F_3 ( V_15 L_19 ,
V_58 ) ;
V_47 |= V_72 ;
F_6 ( V_81 ) ;
return;
}
V_80 = F_16 ( & V_86 , V_41 ) ;
F_8 ( L_20 ,
F_9 ( V_41 ) , V_80 ) ;
V_58 = V_81 -> V_33 -> V_76 ( V_81 , V_80 ) ;
if ( V_58 ) {
F_3 ( V_15 L_21 , V_58 ) ;
V_47 |= V_79 ;
}
}
static void F_17 ( void )
{
T_1 V_41 ;
int V_80 ;
int V_58 ;
if ( ! V_88 || ! V_89 )
return;
if ( ! V_90 ) {
F_3 ( V_84 L_22 ) ;
V_91 . V_32 = V_88 -> V_33 -> V_34 ( V_88 ) ;
V_91 . V_35 = V_88 -> V_33 -> V_36 ( V_88 ) ;
F_15 ( & V_92 , & V_91 ) ;
V_90 = 1 ;
}
if ( -- V_90 > 0 )
return;
V_90 = V_92 . V_87 . V_22 ;
V_58 = V_89 -> V_33 -> V_71 ( V_89 , & V_41 ) ;
if ( V_58 ) {
F_3 ( V_15 L_23
L_17 , V_58 ) ;
V_47 |= V_72 ;
F_6 ( V_88 ) ;
return;
}
V_80 = F_16 ( & V_92 , V_41 ) ;
F_8 ( L_24 ,
F_9 ( V_41 ) , V_80 ) ;
V_58 = V_88 -> V_33 -> V_76 ( V_88 , V_80 ) ;
if ( V_58 ) {
F_3 ( V_15 L_25 , V_58 ) ;
V_47 |= V_79 ;
}
}
static void F_18 ( void )
{
T_1 V_60 ;
int V_80 ;
int V_58 ;
if ( ! V_93 || ! V_94 )
return;
if ( ! V_95 ) {
F_3 ( V_84 L_26 ) ;
F_15 ( & V_96 , & V_97 ) ;
V_95 = 1 ;
}
V_58 = V_94 -> V_33 -> V_71 ( V_94 , & V_60 ) ;
if ( V_58 ) {
F_3 ( V_15 L_27 ,
V_58 ) ;
V_47 |= V_72 ;
F_6 ( V_93 ) ;
return;
}
V_80 = F_16 ( & V_96 , V_60 ) ;
F_8 ( L_28 ,
F_9 ( V_60 ) , V_80 ) ;
V_58 = V_93 -> V_33 -> V_76 ( V_93 , V_80 ) ;
if ( V_58 ) {
F_3 ( V_15 L_29 , V_58 ) ;
V_47 |= V_79 ;
}
}
static void F_19 ( void )
{
int V_38 ;
if ( V_39 )
F_6 ( V_39 ) ;
for ( V_38 = 0 ; V_38 < V_40 ; ++ V_38 )
if ( V_12 [ V_38 ] )
F_6 ( V_12 [ V_38 ] ) ;
if ( V_81 )
F_6 ( V_81 ) ;
if ( V_93 )
F_6 ( V_93 ) ;
if ( V_88 )
F_6 ( V_88 ) ;
}
static void F_20 ( void )
{
int V_38 , V_98 ;
if ( ! V_99 ) {
V_99 = 1 ;
F_3 ( V_84 L_30 ) ;
for ( V_38 = 0 ; V_38 < V_21 ; ++ V_38 ) {
if ( F_1 ( V_38 ) < 0 ) {
V_47 = V_100 ;
F_19 () ;
break;
}
}
F_8 ( L_31 , F_9 ( V_20 ) ) ;
#ifdef F_21
V_20 = 60 << 16 ;
#endif
}
if ( V_47 & V_100 )
return;
V_98 = V_47 ;
V_47 &= V_46 ;
F_11 () ;
F_14 () ;
F_18 () ;
F_17 () ;
F_8 ( L_32 ,
V_98 , V_47 ) ;
if ( V_47 && V_98 == 0 && V_39 )
F_6 ( V_39 ) ;
if ( V_47 == 0 && V_98 && V_39 )
F_22 ( V_39 ) ;
}
static void F_23 ( struct V_10 * V_66 )
{
int V_38 , V_101 ;
if ( V_39 == NULL && ! strcmp ( V_66 -> V_78 , L_33 ) ) {
if ( F_24 ( V_66 ) == 0 )
V_39 = V_66 ;
}
for ( V_38 = 0 ; V_38 < V_40 ; ++ V_38 ) {
if ( ! strcmp ( V_66 -> V_78 , V_102 [ V_38 ] ) ) {
if ( V_12 [ V_38 ] == NULL && F_24 ( V_66 ) == 0 )
V_12 [ V_38 ] = V_66 ;
break;
}
}
if ( V_38 >= V_40 ) {
if ( ! strcmp ( V_66 -> V_78 , L_34 ) ) {
if ( V_81 == NULL && F_24 ( V_66 ) == 0 )
V_81 = V_66 ;
} else if ( ! strcmp ( V_66 -> V_78 , L_35 ) ) {
if ( V_93 == NULL && F_24 ( V_66 ) == 0 )
V_93 = V_66 ;
} else if ( ! strcmp ( V_66 -> V_78 , L_36 ) ) {
if ( V_88 == NULL && F_24 ( V_66 ) == 0 )
V_88 = V_66 ;
}
return;
}
for ( V_38 = 0 ; V_38 < V_103 ; ++ V_38 )
if ( V_12 [ V_38 ] == NULL )
return;
V_101 = V_12 [ 0 ] -> V_33 -> V_36 ( V_12 [ 0 ] ) ;
for ( V_38 = V_104 ; V_38 <= V_105 ; ++ V_38 )
if ( ( V_66 = V_12 [ V_38 ] ) != NULL )
V_77 [ V_38 ] =
V_66 -> V_33 -> V_36 ( V_66 ) * 100 / V_101 ;
V_106 = 1 ;
}
static void F_25 ( struct V_64 * V_65 )
{
unsigned int V_38 ;
if ( ! strncmp ( V_65 -> V_78 , L_37 , 9 ) ) {
V_38 = V_65 -> V_78 [ 9 ] - '0' ;
if ( V_65 -> V_78 [ 10 ] == 0 && V_38 < V_107 &&
V_70 [ V_38 ] == NULL && F_26 ( V_65 ) == 0 )
V_70 [ V_38 ] = V_65 ;
} else if ( ! strncmp ( V_65 -> V_78 , L_38 , 10 ) ) {
V_38 = V_65 -> V_78 [ 10 ] - '0' ;
if ( V_65 -> V_78 [ 11 ] == 0 && V_38 < V_107 &&
V_73 [ V_38 ] == NULL && F_26 ( V_65 ) == 0 )
V_73 [ V_38 ] = V_65 ;
} else if ( ! strcmp ( V_65 -> V_78 , L_39 ) ) {
if ( V_89 == NULL && F_26 ( V_65 ) == 0 )
V_89 = V_65 ;
} else if ( ! strcmp ( V_65 -> V_78 , L_40 ) ) {
if ( V_94 == NULL && F_26 ( V_65 ) == 0 )
V_94 = V_65 ;
} else if ( ! strcmp ( V_65 -> V_78 , L_41 ) ) {
if ( V_82 == NULL && F_26 ( V_65 ) == 0 )
V_82 = V_65 ;
} else
return;
for ( V_38 = 0 ; V_38 < V_21 ; ++ V_38 )
if ( V_70 [ V_38 ] == NULL || V_73 [ V_38 ] == NULL )
return;
V_108 = 1 ;
}
static int F_27 ( struct V_109 * V_110 ,
unsigned long V_111 , void * V_112 )
{
switch ( V_111 ) {
case V_113 :
F_25 ( V_112 ) ;
break;
case V_114 :
F_23 ( V_112 ) ;
break;
case V_115 :
if ( V_106 && V_108 )
F_20 () ;
}
return 0 ;
}
static int F_28 ( struct V_116 * V_117 )
{
F_29 ( & V_118 ) ;
return 0 ;
}
static int T_2 F_30 ( struct V_116 * V_117 )
{
F_31 ( & V_118 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
struct V_119 * V_1 ;
if ( ! F_33 ( L_42 ) )
return - V_120 ;
V_21 = 0 ;
for ( V_1 = NULL ; ( V_1 = F_34 ( V_1 , L_43 ) ) != NULL ; )
++ V_21 ;
F_3 ( V_84 L_44 ) ;
#ifdef F_35
F_36 ( L_45 ) ;
F_36 ( L_46 ) ;
F_36 ( L_47 ) ;
F_36 ( L_48 ) ;
F_36 ( L_49 ) ;
F_36 ( L_50 ) ;
#endif
F_37 ( & V_121 ) ;
return 0 ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_121 ) ;
}
