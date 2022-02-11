static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 ,
struct V_8 * V_9 )
{
int V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
int V_16 = V_6 -> V_17 ;
V_15 = V_2 -> V_15 ;
V_14 = V_2 -> V_14 ;
V_10 = V_9 [ V_16 ] . V_18 ;
V_11 = V_10 + V_7 ;
if ( V_11 < 0 )
V_11 = V_9 [ 0 ] . V_18 ;
else if ( V_11 >= V_14 )
V_11 = V_9 [ V_14 - 1 ] . V_18 ;
V_13 = V_11 ;
if ( V_7 < 0 ) {
for ( V_12 = V_10 ; V_12 >= V_11 ; V_12 -- )
if ( V_9 [ V_12 ] . V_19 <= V_9 [ V_10 ] . V_19 &&
F_2 ( V_4 , V_15 , V_9 [ V_12 ] . V_20 ) )
V_13 = V_12 ;
} else {
for ( V_12 = V_11 + 1 ; V_12 < V_14 ; V_12 ++ )
if ( V_9 [ V_12 ] . V_19 <= V_9 [ V_11 ] . V_19 &&
F_2 ( V_4 , V_15 , V_9 [ V_12 ] . V_20 ) )
V_13 = V_12 ;
}
do {
if ( F_2 ( V_4 , V_15 , V_9 [ V_13 ] . V_20 ) ) {
V_6 -> V_17 = V_9 [ V_13 ] . V_20 ;
break;
}
if ( V_7 < 0 )
V_13 -- ;
else
V_13 ++ ;
} while ( V_13 < V_14 && V_13 >= 0 );
#ifdef F_3
F_4 ( & V_6 -> V_21 ,
V_6 -> V_17 ,
V_2 -> V_22 [ V_6 -> V_17 ] . V_23 ) ;
#endif
}
static void F_5 ( struct V_24 * V_25 , int V_26 )
{
int V_27 , V_28 = V_25 -> V_28 ;
struct V_8 * V_29 = V_25 -> V_9 ;
if ( V_29 [ 0 ] . V_19 > V_28 )
V_29 [ 0 ] . V_19 -= V_28 ;
else if ( V_29 [ 0 ] . V_19 < - V_28 )
V_29 [ 0 ] . V_19 += V_28 ;
for ( V_27 = 0 ; V_27 < V_26 - 1 ; V_27 ++ )
if ( V_29 [ V_27 + 1 ] . V_19 > V_29 [ V_27 ] . V_19 + V_28 )
V_29 [ V_27 + 1 ] . V_19 -= V_28 ;
else if ( V_29 [ V_27 + 1 ] . V_19 <= V_29 [ V_27 ] . V_19 )
V_29 [ V_27 + 1 ] . V_19 += V_28 ;
}
static void F_6 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_8 * V_9 = V_25 -> V_9 ;
T_1 V_30 ;
T_2 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_1 V_34 ;
int V_7 , V_27 , V_35 , V_13 ;
unsigned long V_36 ;
V_36 = F_7 ( V_25 -> V_37 ) ;
if ( V_38 - V_6 -> V_39 > 2 * V_36 )
V_6 -> V_40 = V_25 -> V_41 ;
V_6 -> V_39 = V_38 ;
if ( F_8 ( V_6 -> V_42 == 0 ) )
V_30 = V_6 -> V_43 ;
else
V_30 = V_6 -> V_44 * 100 / V_6 -> V_42 ;
V_6 -> V_42 = 0 ;
V_6 -> V_44 = 0 ;
if ( V_25 -> V_45 != V_6 -> V_17 ) {
V_27 = V_9 [ V_25 -> V_45 ] . V_18 ;
V_35 = V_9 [ V_6 -> V_17 ] . V_18 ;
V_13 = ( V_30 - V_6 -> V_43 ) ;
V_13 = F_9 ( V_13 , V_46 ) ;
V_9 [ V_35 ] . V_19 = V_9 [ V_27 ] . V_19 + V_13 ;
V_25 -> V_45 = V_6 -> V_17 ;
}
F_5 ( V_25 , V_2 -> V_14 ) ;
V_32 = ( V_25 -> V_47 - V_30 ) << V_46 ;
V_31 = V_6 -> V_48 >> V_25 -> V_49 ;
V_6 -> V_48 = V_6 -> V_48 - V_31 + V_32 ;
V_33 = V_6 -> V_48 >> V_25 -> V_49 ;
V_34 = ( V_30 - V_6 -> V_43 ) *
( 1 + V_25 -> V_50 * V_6 -> V_40 ) ;
V_6 -> V_43 = V_30 ;
if ( V_6 -> V_40 )
V_6 -> V_40 -- ;
#ifdef F_3
F_10 ( & V_6 -> V_21 , V_30 , V_32 , V_33 ,
V_34 ) ;
#endif
V_7 = ( V_32 * V_25 -> V_51 + V_33 * V_25 -> V_52
+ V_34 * V_25 -> V_53 ) ;
V_7 = F_9 ( V_7 , 2 * V_46 ) ;
if ( V_7 )
F_1 ( V_2 , V_4 , V_6 , V_7 , V_9 ) ;
}
static void F_11 ( void * V_54 , struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_24 * V_25 = V_54 ;
struct V_5 * V_6 = V_55 ;
unsigned long V_36 ;
struct V_58 * V_59 = F_12 ( V_57 ) ;
if ( ! V_6 )
return;
if ( V_59 -> V_60 . V_61 [ 0 ] . V_62 != V_6 -> V_17 )
return;
V_6 -> V_42 ++ ;
#ifdef F_3
F_13 ( & V_6 -> V_21 , V_59 ) ;
#endif
if ( ! ( V_59 -> V_63 & V_64 ) ) {
V_6 -> V_44 += 2 ;
V_6 -> V_42 ++ ;
} else if ( V_59 -> V_60 . V_61 [ 0 ] . V_65 > 1 ) {
V_6 -> V_44 ++ ;
V_6 -> V_42 ++ ;
}
V_36 = F_7 ( V_25 -> V_37 ) ;
if ( F_14 ( V_38 , V_6 -> V_39 + V_36 ) )
F_6 ( V_25 , V_2 , V_4 , V_6 ) ;
}
static void
F_15 ( void * V_54 , struct V_3 * V_4 ,
void * V_55 ,
struct V_66 * V_67 )
{
struct V_56 * V_57 = V_67 -> V_57 ;
struct V_1 * V_2 = V_67 -> V_2 ;
struct V_58 * V_59 = F_12 ( V_57 ) ;
struct V_5 * V_6 = V_55 ;
int V_68 ;
if ( V_67 -> V_69 )
V_59 -> V_70 . V_61 [ 0 ] . V_65 =
V_67 -> V_71 -> V_72 . V_73 ;
else
V_59 -> V_70 . V_61 [ 0 ] . V_65 =
V_67 -> V_71 -> V_72 . V_74 ;
if ( F_16 ( V_4 , V_55 , V_67 ) )
return;
V_68 = V_6 -> V_17 ;
if ( V_68 >= V_2 -> V_14 )
V_68 = V_2 -> V_14 - 1 ;
V_59 -> V_70 . V_61 [ 0 ] . V_62 = V_68 ;
#ifdef F_3
F_17 ( & V_6 -> V_21 ,
V_68 , V_2 -> V_22 [ V_68 ] . V_23 ) ;
#endif
}
static void
F_18 ( void * V_54 , struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_55 )
{
struct V_5 * V_6 = V_55 ;
struct V_24 * V_25 = V_54 ;
struct V_8 * V_9 = V_25 -> V_9 ;
int V_27 , V_35 , V_13 ;
bool V_75 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_14 ; V_27 ++ ) {
V_9 [ V_27 ] . V_20 = V_27 ;
V_9 [ V_27 ] . V_18 = V_27 ;
if ( V_76 )
V_9 [ V_27 ] . V_19 = 0 ;
else
V_9 [ V_27 ] . V_19 = V_27 * V_25 -> V_28 ;
}
for ( V_27 = 1 ; V_27 < V_2 -> V_14 ; V_27 ++ ) {
V_75 = 0 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_14 - V_27 ; V_35 ++ )
if ( F_8 ( V_2 -> V_22 [ V_9 [ V_35 ] . V_20 ] . V_23 >
V_2 -> V_22 [ V_9 [ V_35 + 1 ] . V_20 ] . V_23 ) ) {
V_13 = V_9 [ V_35 ] . V_20 ;
V_9 [ V_35 ] . V_20 = V_9 [ V_35 + 1 ] . V_20 ;
V_9 [ V_35 + 1 ] . V_20 = V_13 ;
V_9 [ V_9 [ V_35 ] . V_20 ] . V_18 = V_35 ;
V_9 [ V_9 [ V_35 + 1 ] . V_20 ] . V_18 = V_35 + 1 ;
V_75 = 1 ;
}
if ( ! V_75 )
break;
}
V_6 -> V_17 = F_19 ( V_2 , V_4 ) ;
}
static void * F_20 ( struct V_77 * V_71 ,
struct V_78 * V_79 )
{
struct V_24 * V_25 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_27 , V_80 = 0 ;
#ifdef F_3
struct V_81 * V_82 ;
#endif
V_25 = F_21 ( sizeof( * V_25 ) , V_83 ) ;
if ( ! V_25 )
return NULL ;
for ( V_27 = 0 ; V_27 < V_84 ; V_27 ++ ) {
V_2 = V_71 -> V_85 -> V_86 [ V_27 ] ;
if ( V_2 && V_2 -> V_14 > V_80 )
V_80 = V_2 -> V_14 ;
}
V_9 = F_21 ( sizeof( * V_9 ) * V_80 , V_83 ) ;
if ( ! V_9 ) {
F_22 ( V_25 ) ;
return NULL ;
}
V_25 -> V_47 = V_87 ;
V_25 -> V_37 = V_88 ;
V_25 -> V_51 = V_89 ;
V_25 -> V_52 = V_90 ;
V_25 -> V_53 = V_91 ;
V_25 -> V_49 = V_92 ;
V_25 -> V_50 = V_93 ;
V_25 -> V_41 = V_94 ;
V_25 -> V_28 = V_95 ;
V_25 -> V_9 = V_9 ;
V_25 -> V_45 = 0 ;
#ifdef F_3
V_82 = & V_25 -> V_96 ;
V_82 -> V_47 = F_23 ( L_1 , V_97 | V_98 ,
V_79 , & V_25 -> V_47 ) ;
V_82 -> V_37 = F_23 ( L_2 ,
V_97 | V_98 , V_79 ,
& V_25 -> V_37 ) ;
V_82 -> V_51 = F_23 ( L_3 , V_97 | V_98 ,
V_79 , ( T_1 * ) & V_25 -> V_51 ) ;
V_82 -> V_52 = F_23 ( L_4 , V_97 | V_98 ,
V_79 , ( T_1 * ) & V_25 -> V_52 ) ;
V_82 -> V_53 = F_23 ( L_5 , V_97 | V_98 ,
V_79 , ( T_1 * ) & V_25 -> V_53 ) ;
V_82 -> V_49 = F_23 ( L_6 ,
V_97 | V_98 , V_79 ,
& V_25 -> V_49 ) ;
V_82 -> V_50 = F_23 ( L_7 ,
V_97 | V_98 , V_79 ,
& V_25 -> V_50 ) ;
V_82 -> V_41 = F_23 ( L_8 ,
V_97 | V_98 , V_79 ,
& V_25 -> V_41 ) ;
V_82 -> V_28 = F_23 ( L_9 ,
V_97 | V_98 , V_79 ,
& V_25 -> V_28 ) ;
#endif
return V_25 ;
}
static void F_24 ( void * V_54 )
{
struct V_24 * V_25 = V_54 ;
#ifdef F_3
struct V_81 * V_82 = & V_25 -> V_96 ;
F_25 ( V_82 -> V_28 ) ;
F_25 ( V_82 -> V_41 ) ;
F_25 ( V_82 -> V_50 ) ;
F_25 ( V_82 -> V_49 ) ;
F_25 ( V_82 -> V_53 ) ;
F_25 ( V_82 -> V_52 ) ;
F_25 ( V_82 -> V_51 ) ;
F_25 ( V_82 -> V_37 ) ;
F_25 ( V_82 -> V_47 ) ;
#endif
F_22 ( V_25 -> V_9 ) ;
F_22 ( V_25 ) ;
}
static void * F_26 ( void * V_54 , struct V_3 * V_4 ,
T_3 V_99 )
{
struct V_5 * V_6 ;
V_6 = F_27 ( sizeof( * V_6 ) , V_99 ) ;
if ( V_6 == NULL )
return NULL ;
V_6 -> V_39 = V_38 ;
#ifdef F_3
F_28 ( & V_6 -> V_21 . V_100 ) ;
F_29 ( & V_6 -> V_21 . V_101 ) ;
#endif
return V_6 ;
}
static void F_30 ( void * V_54 , struct V_3 * V_4 ,
void * V_55 )
{
F_22 ( V_55 ) ;
}
int T_4 F_31 ( void )
{
return F_32 ( & V_102 ) ;
}
void F_33 ( void )
{
F_34 ( & V_102 ) ;
}
