static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 = 0 , V_10 ;
int V_11 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_15 ;
if ( V_3 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_3 -= V_13 -> V_14 ;
continue;
}
if ( V_3 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_3 ;
else
V_14 = V_4 ;
V_10 = V_13 -> V_16 ( V_13 , V_3 , V_14 , & V_15 , V_6 ) ;
if ( F_3 ( V_10 ) ) {
if ( V_10 == - V_17 ) {
V_2 -> V_18 . V_19 ++ ;
V_9 = V_10 ;
} else if ( V_10 == - V_20 ) {
V_2 -> V_18 . V_21 ++ ;
if ( ! V_9 )
V_9 = V_10 ;
} else
return V_10 ;
}
* V_5 += V_15 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
return V_9 ;
V_6 += V_14 ;
V_3 = 0 ;
}
return - V_22 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_23 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 = - V_22 ;
int V_11 ;
if ( ! ( V_2 -> V_24 & V_25 ) )
return - V_26 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_15 ;
if ( V_23 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_23 -= V_13 -> V_14 ;
continue;
}
if ( V_23 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_23 ;
else
V_14 = V_4 ;
if ( ! ( V_13 -> V_24 & V_25 ) )
V_10 = - V_26 ;
else
V_10 = V_13 -> V_27 ( V_13 , V_23 , V_14 , & V_15 , V_6 ) ;
if ( V_10 )
break;
* V_5 += V_15 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_22 ;
V_6 += V_14 ;
V_23 = 0 ;
}
return V_10 ;
}
static int
F_5 ( struct V_1 * V_2 , const struct V_28 * V_29 ,
unsigned long V_30 , T_1 V_23 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_28 * V_31 ;
unsigned long V_32 , V_33 ;
T_2 V_34 = 0 ;
int V_11 ;
int V_10 = - V_22 ;
if ( ! ( V_2 -> V_24 & V_25 ) )
return - V_26 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_30 ; V_11 ++ )
V_34 += V_29 [ V_11 ] . V_35 ;
if ( ( V_23 + V_34 ) > V_2 -> V_14 )
return - V_22 ;
if ( V_2 -> V_36 > 1 ) {
T_4 V_37 = V_23 ;
if ( F_6 ( V_37 , V_2 -> V_36 ) || ( V_34 % V_2 -> V_36 ) )
return - V_22 ;
}
V_31 = F_7 ( V_29 , sizeof( struct V_28 ) * V_30 , V_38 ) ;
if ( ! V_31 )
return - V_39 ;
V_32 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_40 , V_15 , V_41 ;
if ( V_23 >= V_13 -> V_14 ) {
V_23 -= V_13 -> V_14 ;
continue;
}
V_14 = F_8 ( T_4 , V_34 , V_13 -> V_14 - V_23 ) ;
V_40 = V_14 ;
V_33 = V_32 ;
while ( V_33 < V_30 ) {
if ( V_14 <= V_31 [ V_33 ] . V_35 )
break;
V_14 -= V_31 [ V_33 ++ ] . V_35 ;
}
V_41 = V_31 [ V_33 ] . V_35 ;
V_31 [ V_33 ] . V_35 = V_14 ;
if ( ! ( V_13 -> V_24 & V_25 ) )
V_10 = - V_26 ;
else
V_10 = V_13 -> V_42 ( V_13 , & V_31 [ V_32 ] ,
V_33 - V_32 + 1 , V_23 , & V_15 ) ;
V_31 [ V_33 ] . V_35 = V_41 - V_14 ;
V_31 [ V_33 ] . V_43 += V_14 ;
V_32 = V_33 ;
if ( V_10 )
break;
* V_5 += V_15 ;
V_34 -= V_40 ;
if ( V_34 == 0 )
break;
V_10 = - V_22 ;
V_23 = 0 ;
}
F_9 ( V_31 ) ;
return V_10 ;
}
static int
F_10 ( struct V_1 * V_2 , T_1 V_3 , struct V_44 * V_45 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_44 V_46 = * V_45 ;
int V_11 , V_10 , V_9 = 0 ;
V_45 -> V_5 = V_45 -> V_47 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_3 >= V_13 -> V_14 ) {
V_3 -= V_13 -> V_14 ;
continue;
}
if ( V_3 + V_46 . V_4 > V_13 -> V_14 )
V_46 . V_4 = V_13 -> V_14 - V_3 ;
V_10 = V_13 -> V_48 ( V_13 , V_3 , & V_46 ) ;
V_45 -> V_5 += V_46 . V_5 ;
V_45 -> V_47 += V_46 . V_47 ;
if ( F_3 ( V_10 ) ) {
if ( V_10 == - V_17 ) {
V_2 -> V_18 . V_19 ++ ;
V_9 = V_10 ;
} else if ( V_10 == - V_20 ) {
V_2 -> V_18 . V_21 ++ ;
if ( ! V_9 )
V_9 = V_10 ;
} else
return V_10 ;
}
if ( V_46 . V_49 ) {
V_46 . V_4 = V_45 -> V_4 - V_45 -> V_5 ;
if ( ! V_46 . V_4 )
return V_9 ;
V_46 . V_49 += V_46 . V_5 ;
}
if ( V_46 . V_50 ) {
V_46 . V_51 = V_45 -> V_51 - V_45 -> V_47 ;
if ( ! V_46 . V_51 )
return V_9 ;
V_46 . V_50 += V_45 -> V_47 ;
}
V_3 = 0 ;
}
return - V_22 ;
}
static int
F_11 ( struct V_1 * V_2 , T_1 V_23 , struct V_44 * V_45 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_44 V_46 = * V_45 ;
int V_11 , V_10 ;
if ( ! ( V_2 -> V_24 & V_25 ) )
return - V_26 ;
V_45 -> V_5 = V_45 -> V_47 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_23 >= V_13 -> V_14 ) {
V_23 -= V_13 -> V_14 ;
continue;
}
if ( V_23 + V_46 . V_4 > V_13 -> V_14 )
V_46 . V_4 = V_13 -> V_14 - V_23 ;
V_10 = V_13 -> V_52 ( V_13 , V_23 , & V_46 ) ;
V_45 -> V_5 += V_46 . V_47 ;
if ( V_10 )
return V_10 ;
if ( V_46 . V_49 ) {
V_46 . V_4 = V_45 -> V_4 - V_45 -> V_5 ;
if ( ! V_46 . V_4 )
return 0 ;
V_46 . V_49 += V_46 . V_5 ;
}
if ( V_46 . V_50 ) {
V_46 . V_51 = V_45 -> V_51 - V_45 -> V_47 ;
if ( ! V_46 . V_51 )
return 0 ;
V_46 . V_50 += V_46 . V_47 ;
}
V_23 = 0 ;
}
return - V_22 ;
}
static void F_12 ( struct V_53 * V_54 )
{
F_13 ( ( V_55 * ) V_54 -> V_56 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_53 * V_57 )
{
int V_10 ;
V_55 V_58 ;
F_15 ( V_59 , V_60 ) ;
F_16 ( & V_58 ) ;
V_57 -> V_2 = V_2 ;
V_57 -> V_61 = F_12 ;
V_57 -> V_56 = ( unsigned long ) & V_58 ;
V_10 = V_2 -> V_57 ( V_2 , V_57 ) ;
if ( ! V_10 ) {
F_17 ( V_62 ) ;
F_18 ( & V_58 , & V_59 ) ;
if ( V_57 -> V_63 != V_64
&& V_57 -> V_63 != V_65 )
F_19 () ;
F_20 ( & V_58 , & V_59 ) ;
F_17 ( V_66 ) ;
V_10 = ( V_57 -> V_63 == V_65 ) ? - V_67 : 0 ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_13 ;
int V_11 , V_10 ;
T_4 V_68 , V_69 = 0 ;
struct V_53 * V_57 ;
if ( ! ( V_2 -> V_24 & V_25 ) )
return - V_26 ;
if ( V_54 -> V_70 > V_8 -> V_2 . V_14 )
return - V_22 ;
if ( V_54 -> V_4 + V_54 -> V_70 > V_8 -> V_2 . V_14 )
return - V_22 ;
if ( ! V_8 -> V_2 . V_71 ) {
if ( V_54 -> V_70 & ( V_8 -> V_2 . V_72 - 1 ) )
return - V_22 ;
if ( V_54 -> V_4 & ( V_8 -> V_2 . V_72 - 1 ) )
return - V_22 ;
} else {
struct V_73 * V_74 =
V_8 -> V_2 . V_75 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_2 . V_71 &&
V_54 -> V_70 >= V_74 [ V_11 ] . V_69 ; V_11 ++ ) ;
-- V_11 ;
if ( V_11 < 0 || V_54 -> V_70 & ( V_74 [ V_11 ] . V_72 - 1 ) )
return - V_22 ;
for (; V_11 < V_8 -> V_2 . V_71 &&
( V_54 -> V_70 + V_54 -> V_4 ) >= V_74 [ V_11 ] . V_69 ;
++ V_11 ) ;
-- V_11 ;
if ( V_11 < 0 || ( ( V_54 -> V_70 + V_54 -> V_4 ) &
( V_74 [ V_11 ] . V_72 - 1 ) ) )
return - V_22 ;
}
V_54 -> V_76 = V_77 ;
V_57 = F_22 ( sizeof ( struct V_53 ) , V_38 ) ;
if ( ! V_57 )
return - V_39 ;
* V_57 = * V_54 ;
V_68 = V_54 -> V_4 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_13 -> V_14 <= V_57 -> V_70 ) {
V_57 -> V_70 -= V_13 -> V_14 ;
V_69 += V_13 -> V_14 ;
} else {
break;
}
}
F_23 ( V_11 >= V_8 -> V_12 ) ;
V_10 = 0 ;
for (; V_68 > 0 ; V_11 ++ ) {
V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_57 -> V_70 + V_68 > V_13 -> V_14 )
V_57 -> V_4 = V_13 -> V_14 - V_57 -> V_70 ;
else
V_57 -> V_4 = V_68 ;
if ( ! ( V_13 -> V_24 & V_25 ) ) {
V_10 = - V_26 ;
break;
}
V_68 -= V_57 -> V_4 ;
if ( ( V_10 = F_14 ( V_13 , V_57 ) ) ) {
F_23 ( V_10 == - V_22 ) ;
if ( V_57 -> V_76 != V_77 )
V_54 -> V_76 = V_57 -> V_76 + V_69 ;
break;
}
V_57 -> V_70 = 0 ;
V_69 += V_13 -> V_14 ;
}
V_54 -> V_63 = V_57 -> V_63 ;
F_9 ( V_57 ) ;
if ( V_10 )
return V_10 ;
if ( V_54 -> V_61 )
V_54 -> V_61 ( V_54 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_78 , T_4 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = - V_22 ;
if ( ( V_4 + V_78 ) > V_2 -> V_14 )
return - V_22 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_4 V_14 ;
if ( V_78 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_78 -= V_13 -> V_14 ;
continue;
}
if ( V_78 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_78 ;
else
V_14 = V_4 ;
if ( V_13 -> V_79 ) {
V_10 = V_13 -> V_79 ( V_13 , V_78 , V_14 ) ;
if ( V_10 )
break;
} else
V_10 = - V_80 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_22 ;
V_78 = 0 ;
}
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_78 , T_4 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = 0 ;
if ( ( V_4 + V_78 ) > V_2 -> V_14 )
return - V_22 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_4 V_14 ;
if ( V_78 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_78 -= V_13 -> V_14 ;
continue;
}
if ( V_78 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_78 ;
else
V_14 = V_4 ;
if ( V_13 -> V_81 ) {
V_10 = V_13 -> V_81 ( V_13 , V_78 , V_14 ) ;
if ( V_10 )
break;
} else
V_10 = - V_80 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_22 ;
V_78 = 0 ;
}
return V_10 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
V_13 -> V_82 ( V_13 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_83 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( ( V_83 = V_13 -> V_84 ( V_13 ) ) < 0 )
return V_83 ;
}
return V_83 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
V_13 -> V_85 ( V_13 ) ;
}
}
static int F_29 ( struct V_1 * V_2 , T_1 V_78 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_86 = 0 ;
if ( ! V_8 -> V_13 [ 0 ] -> V_87 )
return V_86 ;
if ( V_78 > V_2 -> V_14 )
return - V_22 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_78 >= V_13 -> V_14 ) {
V_78 -= V_13 -> V_14 ;
continue;
}
V_86 = V_13 -> V_87 ( V_13 , V_78 ) ;
break;
}
return V_86 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_78 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = - V_22 ;
if ( ! V_8 -> V_13 [ 0 ] -> V_88 )
return 0 ;
if ( V_78 > V_2 -> V_14 )
return - V_22 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_78 >= V_13 -> V_14 ) {
V_78 -= V_13 -> V_14 ;
continue;
}
V_10 = V_13 -> V_88 ( V_13 , V_78 ) ;
if ( ! V_10 )
V_2 -> V_18 . V_89 ++ ;
break;
}
return V_10 ;
}
static unsigned long F_31 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_69 ,
unsigned long V_24 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_69 >= V_13 -> V_14 ) {
V_69 -= V_13 -> V_14 ;
continue;
}
if ( V_69 + V_4 > V_13 -> V_14 )
return ( unsigned long ) - V_22 ;
if ( V_13 -> V_90 )
return V_13 -> V_90 ( V_13 , V_4 , V_69 ,
V_24 ) ;
break;
}
return ( unsigned long ) - V_91 ;
}
struct V_1 * F_32 ( struct V_1 * V_13 [] ,
int V_92 ,
const char * V_93 )
{
int V_11 ;
T_2 V_14 ;
struct V_7 * V_8 ;
T_5 V_94 , V_95 ;
int V_96 ;
int V_97 = 0 ;
F_33 ( V_98 L_1 ) ;
for ( V_11 = 0 ; V_11 < V_92 ; V_11 ++ )
F_33 ( V_98 L_2 , V_11 , V_13 [ V_11 ] -> V_93 ) ;
F_33 ( V_98 L_3 , V_93 ) ;
V_14 = F_34 ( V_92 ) ;
V_8 = F_35 ( V_14 , V_38 ) ;
if ( ! V_8 ) {
F_33
( L_4 ,
V_93 ) ;
return NULL ;
}
V_8 -> V_13 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_8 -> V_2 . type = V_13 [ 0 ] -> type ;
V_8 -> V_2 . V_24 = V_13 [ 0 ] -> V_24 ;
V_8 -> V_2 . V_14 = V_13 [ 0 ] -> V_14 ;
V_8 -> V_2 . V_72 = V_13 [ 0 ] -> V_72 ;
V_8 -> V_2 . V_36 = V_13 [ 0 ] -> V_36 ;
for ( V_11 = 0 ; V_11 < V_92 ; V_11 ++ )
if ( V_97 < V_13 [ V_11 ] -> V_99 )
V_97 = V_13 [ V_11 ] -> V_99 ;
V_8 -> V_2 . V_99 = V_97 ;
V_8 -> V_2 . V_100 = V_13 [ 0 ] -> V_100 ;
V_8 -> V_2 . V_101 = V_13 [ 0 ] -> V_101 ;
V_8 -> V_2 . V_102 = V_13 [ 0 ] -> V_102 ;
if ( V_13 [ 0 ] -> V_42 )
V_8 -> V_2 . V_42 = F_5 ;
if ( V_13 [ 0 ] -> V_48 )
V_8 -> V_2 . V_48 = F_10 ;
if ( V_13 [ 0 ] -> V_52 )
V_8 -> V_2 . V_52 = F_11 ;
if ( V_13 [ 0 ] -> V_87 )
V_8 -> V_2 . V_87 = F_29 ;
if ( V_13 [ 0 ] -> V_88 )
V_8 -> V_2 . V_88 = F_30 ;
V_8 -> V_2 . V_18 . V_89 = V_13 [ 0 ] -> V_18 . V_89 ;
V_8 -> V_2 . V_103 = V_13 [ 0 ] -> V_103 ;
V_8 -> V_13 [ 0 ] = V_13 [ 0 ] ;
for ( V_11 = 1 ; V_11 < V_92 ; V_11 ++ ) {
if ( V_8 -> V_2 . type != V_13 [ V_11 ] -> type ) {
F_9 ( V_8 ) ;
F_33 ( L_5 ,
V_13 [ V_11 ] -> V_93 ) ;
return NULL ;
}
if ( V_8 -> V_2 . V_24 != V_13 [ V_11 ] -> V_24 ) {
if ( ( V_8 -> V_2 . V_24 ^ V_13 [ V_11 ] ->
V_24 ) & ~ V_25 ) {
F_9 ( V_8 ) ;
F_33 ( L_6 ,
V_13 [ V_11 ] -> V_93 ) ;
return NULL ;
} else
V_8 -> V_2 . V_24 |=
V_13 [ V_11 ] -> V_24 & V_25 ;
}
if ( V_8 -> V_2 . V_103 !=
V_13 [ V_11 ] -> V_103 )
V_8 -> V_2 . V_103 =
& V_104 ;
V_8 -> V_2 . V_14 += V_13 [ V_11 ] -> V_14 ;
V_8 -> V_2 . V_18 . V_89 +=
V_13 [ V_11 ] -> V_18 . V_89 ;
if ( V_8 -> V_2 . V_36 != V_13 [ V_11 ] -> V_36 ||
V_8 -> V_2 . V_100 != V_13 [ V_11 ] -> V_100 ||
V_8 -> V_2 . V_101 != V_13 [ V_11 ] -> V_101 ||
! V_8 -> V_2 . V_48 != ! V_13 [ V_11 ] -> V_48 ||
! V_8 -> V_2 . V_52 != ! V_13 [ V_11 ] -> V_52 ) {
F_9 ( V_8 ) ;
F_33 ( L_7 ,
V_13 [ V_11 ] -> V_93 ) ;
return NULL ;
}
V_8 -> V_13 [ V_11 ] = V_13 [ V_11 ] ;
}
V_8 -> V_2 . V_105 = V_13 [ 0 ] -> V_105 ;
V_8 -> V_12 = V_92 ;
V_8 -> V_2 . V_93 = V_93 ;
V_8 -> V_2 . V_57 = F_21 ;
V_8 -> V_2 . V_16 = F_1 ;
V_8 -> V_2 . V_27 = F_4 ;
V_8 -> V_2 . V_82 = F_26 ;
V_8 -> V_2 . V_79 = F_24 ;
V_8 -> V_2 . V_81 = F_25 ;
V_8 -> V_2 . V_84 = F_27 ;
V_8 -> V_2 . V_85 = F_28 ;
V_8 -> V_2 . V_90 = F_31 ;
V_94 = V_95 = V_13 [ 0 ] -> V_72 ;
V_96 = 1 ;
for ( V_11 = 0 ; V_11 < V_92 ; V_11 ++ ) {
if ( V_13 [ V_11 ] -> V_71 == 0 ) {
if ( V_13 [ V_11 ] -> V_72 != V_95 ) {
++ V_96 ;
V_95 = V_13 [ V_11 ] -> V_72 ;
if ( V_95 > V_94 )
V_94 = V_95 ;
}
} else {
int V_106 ;
for ( V_106 = 0 ; V_106 < V_13 [ V_11 ] -> V_71 ; V_106 ++ ) {
if ( V_13 [ V_11 ] -> V_75 [ V_106 ] . V_72 !=
V_95 ) {
++ V_96 ;
V_95 =
V_13 [ V_11 ] -> V_75 [ V_106 ] .
V_72 ;
if ( V_95 > V_94 )
V_94 = V_95 ;
}
}
}
}
if ( V_96 == 1 ) {
V_8 -> V_2 . V_72 = V_95 ;
V_8 -> V_2 . V_71 = 0 ;
} else {
T_4 V_107 ;
struct V_73 * V_108 ;
T_4 V_109 , V_110 ;
V_8 -> V_2 . V_72 = V_94 ;
V_8 -> V_2 . V_71 = V_96 ;
V_8 -> V_2 . V_75 = V_108 =
F_22 ( V_96 *
sizeof ( struct V_73 ) , V_38 ) ;
if ( ! V_108 ) {
F_9 ( V_8 ) ;
F_33
( L_8
L_9 , V_93 ) ;
return NULL ;
}
V_95 = V_13 [ 0 ] -> V_72 ;
V_109 = V_110 = 0 ;
for ( V_11 = 0 ; V_11 < V_92 ; V_11 ++ ) {
if ( V_13 [ V_11 ] -> V_71 == 0 ) {
if ( V_13 [ V_11 ] -> V_72 != V_95 ) {
V_108 -> V_69 = V_109 ;
V_108 -> V_72 =
V_95 ;
V_107 = V_110 - V_109 ;
F_6 ( V_107 , V_95 ) ;
V_108 -> V_111 = V_107 ;
V_109 = V_110 ;
V_95 = V_13 [ V_11 ] -> V_72 ;
++ V_108 ;
}
V_110 += V_13 [ V_11 ] -> V_14 ;
} else {
int V_106 ;
for ( V_106 = 0 ; V_106 < V_13 [ V_11 ] -> V_71 ; V_106 ++ ) {
if ( V_13 [ V_11 ] -> V_75 [ V_106 ] .
V_72 != V_95 ) {
V_108 -> V_69 = V_109 ;
V_108 -> V_72 =
V_95 ;
V_107 = V_110 - V_109 ;
F_6 ( V_107 , V_95 ) ;
V_108 -> V_111 = V_107 ;
V_109 = V_110 ;
V_95 =
V_13 [ V_11 ] -> V_75 [ V_106 ] .
V_72 ;
++ V_108 ;
}
V_110 +=
V_13 [ V_11 ] -> V_75 [ V_106 ] .
V_111 * ( T_4 ) V_95 ;
}
}
}
V_108 -> V_69 = V_109 ;
V_108 -> V_72 = V_95 ;
V_107 = V_110 - V_109 ;
F_6 ( V_107 , V_95 ) ;
V_108 -> V_111 = V_107 ;
}
return & V_8 -> V_2 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_2 . V_71 )
F_9 ( V_8 -> V_2 . V_75 ) ;
F_9 ( V_8 ) ;
}
