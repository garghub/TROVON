static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_2 ) ;
return V_3 ;
}
static inline int F_4 ( T_2 * V_4 )
{
int V_5 ;
if ( F_5 ( V_6 ) )
V_5 = V_4 -> V_7 . V_8 . V_9 . V_10 ;
else
V_5 = V_4 -> V_11 . V_12 . V_13 ;
if ( ( V_4 -> V_14 . V_15 . V_16 == 10 ) && ( V_4 -> V_11 . V_17 <= 64 ) ) {
} else if ( V_4 -> V_14 . V_15 . V_16 == 5 ||
V_4 -> V_14 . V_15 . V_16 == 7 ) {
int V_18 = F_6 ( V_5 ) ;
int V_19 = F_7 ( V_5 ) ;
union V_20 V_21 ;
V_21 . V_22 =
F_8 ( F_9 ( V_19 , V_18 ) ) ;
if ( V_21 . V_23 . V_24 == 0 ) {
T_3 * V_25 =
F_10 ( V_4 -> V_26 . V_23 . V_27 ) ;
int V_28 = 0 ;
while ( V_28 < V_4 -> V_11 . V_17 - 1 ) {
if ( * V_25 != 0x55 )
break;
V_25 ++ ;
V_28 ++ ;
}
if ( * V_25 == 0xd5 ) {
V_4 -> V_26 . V_23 . V_27 += V_28 + 1 ;
V_4 -> V_11 . V_17 -= V_28 + 5 ;
} else if ( ( * V_25 & 0xf ) == 0xd ) {
V_4 -> V_26 . V_23 . V_27 += V_28 ;
V_4 -> V_11 . V_17 -= V_28 + 4 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_11 . V_17 ; V_28 ++ ) {
* V_25 =
( ( * V_25 & 0xf0 ) >> 4 ) |
( ( * ( V_25 + 1 ) & 0xf ) << 4 ) ;
V_25 ++ ;
}
} else {
F_11 ( L_1 ,
V_5 ) ;
F_12 ( V_4 ) ;
return 1 ;
}
}
} else {
F_11 ( L_2 ,
V_5 , V_4 -> V_14 . V_15 . V_16 ) ;
F_12 ( V_4 ) ;
return 1 ;
}
return 0 ;
}
static void F_13 ( T_2 * V_4 , struct V_29 * V_30 )
{
int V_31 = V_4 -> V_14 . V_23 . V_32 ;
union V_33 V_34 = V_4 -> V_26 ;
int V_17 = V_4 -> V_11 . V_17 ;
int V_35 ;
while ( V_31 -- ) {
union V_33 V_36 ;
V_36 = * (union V_33 * )
F_10 ( V_34 . V_23 . V_27 - 8 ) ;
V_35 =
V_37 -
( V_34 . V_23 . V_27 -
( ( ( V_34 . V_23 . V_27 >> 7 ) -
V_34 . V_23 . V_38 ) << 7 ) ) ;
if ( V_35 > V_17 )
V_35 = V_17 ;
F_14 ( V_30 , F_10 ( V_34 . V_23 . V_27 ) ,
V_35 ) ;
V_17 -= V_35 ;
V_34 = V_36 ;
}
}
static int F_15 ( struct V_39 * V_40 , int V_41 )
{
const int V_42 = F_16 () ;
V_22 V_43 ;
V_22 V_44 ;
int V_45 = 0 ;
int V_46 = 0 ;
int V_47 ;
F_17 ( V_48 ) ;
if ( V_49 ) {
V_50 ;
V_44 = F_18 ( V_51 ) ;
}
if ( F_19 ( V_52 ) ) {
V_43 = F_8 ( F_20 ( V_42 ) ) ;
F_21 ( F_20 ( V_42 ) ,
F_22 ( V_40 -> V_53 ) ) ;
F_8 ( F_20 ( V_42 ) ) ;
} else {
V_43 = F_8 ( F_23 ( V_42 ) ) ;
F_21 ( F_23 ( V_42 ) ,
( V_43 & ~ 0xFFFFull ) |
F_22 ( V_40 -> V_53 ) ) ;
}
if ( V_49 ) {
F_24 ( V_51 , V_54 ) ;
V_46 = 1 ;
}
while ( V_45 < V_41 ) {
struct V_29 * V_30 = NULL ;
struct V_29 * * V_55 = NULL ;
int V_56 ;
T_2 * V_4 ;
int V_5 ;
if ( V_49 && V_46 )
V_4 = F_25 ( V_51 ) ;
else
V_4 = F_26 ( V_54 ) ;
F_17 ( V_4 ) ;
V_46 = 0 ;
if ( ! V_4 ) {
if ( F_19 ( V_52 ) ) {
F_21 ( V_57 ,
F_22 ( V_40 -> V_53 ) ) ;
F_21 ( V_58 ,
F_22 ( V_40 -> V_53 ) ) ;
} else {
union V_59 V_60 ;
V_60 . V_22 = 0 ;
V_60 . V_23 . V_61 = F_22 ( V_40 -> V_53 ) ;
V_60 . V_23 . V_60 = F_22 ( V_40 -> V_53 ) ;
F_21 ( V_62 , V_60 . V_22 ) ;
}
break;
}
V_55 = (struct V_29 * * )
( F_27 ( V_4 -> V_26 ) -
sizeof( void * ) ) ;
F_17 ( V_55 ) ;
if ( V_49 && V_45 < ( V_41 - 1 ) ) {
F_28 ( V_51 ,
V_54 ) ;
V_46 = 1 ;
}
V_45 ++ ;
V_56 = V_4 -> V_14 . V_23 . V_32 == 1 ;
if ( F_29 ( V_56 ) ) {
V_30 = * V_55 ;
F_17 ( & V_30 -> V_63 ) ;
F_17 ( & V_30 -> V_17 ) ;
}
if ( F_5 ( V_6 ) )
V_5 = V_4 -> V_7 . V_8 . V_9 . V_10 ;
else
V_5 = V_4 -> V_11 . V_12 . V_13 ;
F_17 ( V_48 [ V_5 ] ) ;
if ( F_30 ( V_4 -> V_14 . V_15 . V_64 ) ) {
if ( F_4 ( V_4 ) )
continue;
}
if ( F_29 ( V_56 ) ) {
V_30 -> V_65 = V_30 -> V_63 + V_4 -> V_26 . V_23 . V_27 -
F_31 ( V_30 -> V_63 ) ;
F_17 ( V_30 -> V_65 ) ;
V_30 -> V_17 = V_4 -> V_11 . V_17 ;
F_32 ( V_30 , V_30 -> V_17 ) ;
V_47 = 1 ;
} else {
V_30 = F_33 ( V_4 -> V_11 . V_17 ) ;
if ( ! V_30 ) {
F_12 ( V_4 ) ;
continue;
}
if ( F_30 ( V_4 -> V_14 . V_23 . V_32 == 0 ) ) {
T_3 * V_25 = V_4 -> V_66 ;
if ( F_29 ( ! V_4 -> V_14 . V_23 . V_67 ) ) {
if ( V_4 -> V_14 . V_23 . V_68 )
V_25 += 2 ;
else
V_25 += 6 ;
}
F_14 ( V_30 , V_25 , V_4 -> V_11 . V_17 ) ;
} else {
F_13 ( V_4 , V_30 ) ;
}
V_47 = 0 ;
}
if ( F_29 ( ( V_5 < V_69 ) &&
V_48 [ V_5 ] ) ) {
struct V_70 * V_71 = V_48 [ V_5 ] ;
if ( F_29 ( V_71 -> V_72 & V_73 ) ) {
V_30 -> V_74 = F_34 ( V_30 , V_71 ) ;
V_30 -> V_71 = V_71 ;
if ( F_30 ( V_4 -> V_14 . V_23 . V_67 ||
V_4 -> V_14 . V_23 . V_75 ||
V_4 -> V_14 . V_23 . V_76 ||
! V_4 -> V_14 . V_23 . V_77 ) )
V_30 -> V_78 = V_79 ;
else
V_30 -> V_78 = V_80 ;
if ( V_5 >= V_81 ) {
V_71 -> V_82 . V_83 ++ ;
V_71 -> V_82 . V_84 += V_30 -> V_17 ;
}
F_35 ( V_30 ) ;
} else {
V_71 -> V_82 . V_85 ++ ;
F_36 ( V_30 ) ;
}
} else {
F_11 ( L_3 ,
V_5 ) ;
F_36 ( V_30 ) ;
}
if ( F_29 ( V_47 ) ) {
F_37 ( V_86 ,
1 ) ;
F_38 ( V_4 , V_87 , 1 ) ;
} else {
F_12 ( V_4 ) ;
}
}
if ( F_19 ( V_52 ) ) {
F_21 ( F_20 ( V_42 ) , V_43 ) ;
F_8 ( F_20 ( V_42 ) ) ;
} else {
F_21 ( F_23 ( V_42 ) , V_43 ) ;
}
if ( V_49 ) {
F_39 ( V_51 , V_44 ) ;
}
F_40 ( 0 ) ;
return V_45 ;
}
static int F_41 ( struct V_88 * V_89 , int V_41 )
{
struct V_39 * V_40 = F_42 ( V_89 , struct V_39 ,
V_89 ) ;
int V_45 ;
V_45 = F_15 ( V_40 , V_41 ) ;
if ( V_45 < V_41 ) {
F_43 ( V_89 , V_45 ) ;
F_44 ( V_40 -> V_1 ) ;
}
return V_45 ;
}
void F_45 ( struct V_70 * V_71 )
{
int V_28 ;
if ( ! F_46 ( & V_90 ) )
return;
for ( V_28 = 0 ; V_28 < F_47 ( V_39 ) ; V_28 ++ ) {
if ( ! ( V_91 & F_22 ( V_28 ) ) )
continue;
F_15 ( & V_39 [ V_28 ] , 16 ) ;
}
}
void F_48 ( void )
{
int V_28 ;
struct V_70 * V_92 = NULL ;
for ( V_28 = 0 ; V_28 < V_69 ; V_28 ++ ) {
if ( V_48 [ V_28 ] ) {
V_92 = V_48 [ V_28 ] ;
break;
}
}
if ( ! V_92 )
F_49 ( L_4 ) ;
for ( V_28 = 0 ; V_28 < F_47 ( V_39 ) ; V_28 ++ ) {
int V_93 ;
if ( ! ( V_91 & F_22 ( V_28 ) ) )
continue;
F_50 ( V_92 , & V_39 [ V_28 ] . V_89 ,
F_41 , V_94 ) ;
F_51 ( & V_39 [ V_28 ] . V_89 ) ;
V_39 [ V_28 ] . V_1 = V_95 + V_28 ;
V_39 [ V_28 ] . V_53 = V_28 ;
V_93 = F_52 ( V_39 [ V_28 ] . V_1 , F_1 , 0 ,
L_5 , & V_39 [ V_28 ] . V_89 ) ;
if ( V_93 )
F_49 ( L_6 ,
V_39 [ V_28 ] . V_1 ) ;
F_2 ( V_39 [ V_28 ] . V_1 ) ;
if ( F_19 ( V_52 ) ) {
union V_96 V_97 ;
union V_98 V_99 ;
V_97 . V_22 = 0 ;
V_97 . V_23 . V_100 = 1 ;
V_97 . V_23 . V_101 = 1 ;
F_21 ( F_53 ( V_28 ) , V_97 . V_22 ) ;
V_99 . V_22 = 0 ;
V_99 . V_23 . V_102 = 5 ;
F_21 ( V_103 , V_99 . V_22 ) ;
} else {
union V_104 V_97 ;
union V_98 V_99 ;
V_97 . V_22 = 0 ;
V_97 . V_23 . V_100 = 1 ;
V_97 . V_23 . V_101 = 1 ;
F_21 ( F_54 ( V_28 ) , V_97 . V_22 ) ;
V_99 . V_22 = 0 ;
V_99 . V_23 . V_102 = 5 ;
F_21 ( V_105 , V_99 . V_22 ) ;
}
F_3 ( & V_39 [ V_28 ] . V_89 ) ;
}
F_55 ( & V_90 ) ;
}
void F_56 ( void )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < F_47 ( V_39 ) ; V_28 ++ ) {
if ( ! ( V_91 & F_22 ( V_28 ) ) )
continue;
if ( F_19 ( V_52 ) )
F_21 ( F_53 ( V_28 ) , 0 ) ;
else
F_21 ( F_54 ( V_28 ) , 0 ) ;
F_57 ( V_39 [ V_28 ] . V_1 , V_48 ) ;
F_58 ( & V_39 [ V_28 ] . V_89 ) ;
}
}
