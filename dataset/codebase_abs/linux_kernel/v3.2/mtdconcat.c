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
if ( F_4 ( V_10 ) ) {
V_2 -> V_17 . V_18 ++ ;
V_9 = V_10 ;
} else if ( F_5 ( V_10 ) ) {
V_2 -> V_17 . V_19 ++ ;
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
return - V_20 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 = - V_20 ;
int V_11 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
return - V_24 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_15 ;
if ( V_21 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_21 -= V_13 -> V_14 ;
continue;
}
if ( V_21 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_21 ;
else
V_14 = V_4 ;
if ( ! ( V_13 -> V_22 & V_23 ) )
V_10 = - V_24 ;
else
V_10 = V_13 -> V_25 ( V_13 , V_21 , V_14 , & V_15 , V_6 ) ;
if ( V_10 )
break;
* V_5 += V_15 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_20 ;
V_6 += V_14 ;
V_21 = 0 ;
}
return V_10 ;
}
static int
F_7 ( struct V_1 * V_2 , const struct V_26 * V_27 ,
unsigned long V_28 , T_1 V_21 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_26 * V_29 ;
unsigned long V_30 , V_31 ;
T_2 V_32 = 0 ;
int V_11 ;
int V_10 = - V_20 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
return - V_24 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
V_32 += V_27 [ V_11 ] . V_33 ;
if ( ( V_21 + V_32 ) > V_2 -> V_14 )
return - V_20 ;
if ( V_2 -> V_34 > 1 ) {
T_4 V_35 = V_21 ;
if ( F_8 ( V_35 , V_2 -> V_34 ) || ( V_32 % V_2 -> V_34 ) )
return - V_20 ;
}
V_29 = F_9 ( V_27 , sizeof( struct V_26 ) * V_28 , V_36 ) ;
if ( ! V_29 )
return - V_37 ;
V_30 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_38 , V_15 , V_39 ;
if ( V_21 >= V_13 -> V_14 ) {
V_21 -= V_13 -> V_14 ;
continue;
}
V_14 = F_10 ( T_4 , V_32 , V_13 -> V_14 - V_21 ) ;
V_38 = V_14 ;
V_31 = V_30 ;
while ( V_31 < V_28 ) {
if ( V_14 <= V_29 [ V_31 ] . V_33 )
break;
V_14 -= V_29 [ V_31 ++ ] . V_33 ;
}
V_39 = V_29 [ V_31 ] . V_33 ;
V_29 [ V_31 ] . V_33 = V_14 ;
if ( ! ( V_13 -> V_22 & V_23 ) )
V_10 = - V_24 ;
else
V_10 = V_13 -> V_40 ( V_13 , & V_29 [ V_30 ] ,
V_31 - V_30 + 1 , V_21 , & V_15 ) ;
V_29 [ V_31 ] . V_33 = V_39 - V_14 ;
V_29 [ V_31 ] . V_41 += V_14 ;
V_30 = V_31 ;
if ( V_10 )
break;
* V_5 += V_15 ;
V_32 -= V_38 ;
if ( V_32 == 0 )
break;
V_10 = - V_20 ;
V_21 = 0 ;
}
F_11 ( V_29 ) ;
return V_10 ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 V_3 , struct V_42 * V_43 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_42 V_44 = * V_43 ;
int V_11 , V_10 , V_9 = 0 ;
V_43 -> V_5 = V_43 -> V_45 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_3 >= V_13 -> V_14 ) {
V_3 -= V_13 -> V_14 ;
continue;
}
if ( V_3 + V_44 . V_4 > V_13 -> V_14 )
V_44 . V_4 = V_13 -> V_14 - V_3 ;
V_10 = V_13 -> V_46 ( V_13 , V_3 , & V_44 ) ;
V_43 -> V_5 += V_44 . V_5 ;
V_43 -> V_45 += V_44 . V_45 ;
if ( F_3 ( V_10 ) ) {
if ( F_4 ( V_10 ) ) {
V_2 -> V_17 . V_18 ++ ;
V_9 = V_10 ;
} else if ( F_5 ( V_10 ) ) {
V_2 -> V_17 . V_19 ++ ;
if ( ! V_9 )
V_9 = V_10 ;
} else
return V_10 ;
}
if ( V_44 . V_47 ) {
V_44 . V_4 = V_43 -> V_4 - V_43 -> V_5 ;
if ( ! V_44 . V_4 )
return V_9 ;
V_44 . V_47 += V_44 . V_5 ;
}
if ( V_44 . V_48 ) {
V_44 . V_49 = V_43 -> V_49 - V_43 -> V_45 ;
if ( ! V_44 . V_49 )
return V_9 ;
V_44 . V_48 += V_43 -> V_45 ;
}
V_3 = 0 ;
}
return - V_20 ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 V_21 , struct V_42 * V_43 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_42 V_44 = * V_43 ;
int V_11 , V_10 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
return - V_24 ;
V_43 -> V_5 = V_43 -> V_45 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_21 >= V_13 -> V_14 ) {
V_21 -= V_13 -> V_14 ;
continue;
}
if ( V_21 + V_44 . V_4 > V_13 -> V_14 )
V_44 . V_4 = V_13 -> V_14 - V_21 ;
V_10 = V_13 -> V_50 ( V_13 , V_21 , & V_44 ) ;
V_43 -> V_5 += V_44 . V_45 ;
if ( V_10 )
return V_10 ;
if ( V_44 . V_47 ) {
V_44 . V_4 = V_43 -> V_4 - V_43 -> V_5 ;
if ( ! V_44 . V_4 )
return 0 ;
V_44 . V_47 += V_44 . V_5 ;
}
if ( V_44 . V_48 ) {
V_44 . V_49 = V_43 -> V_49 - V_43 -> V_45 ;
if ( ! V_44 . V_49 )
return 0 ;
V_44 . V_48 += V_44 . V_45 ;
}
V_21 = 0 ;
}
return - V_20 ;
}
static void F_14 ( struct V_51 * V_52 )
{
F_15 ( ( V_53 * ) V_52 -> V_54 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_51 * V_55 )
{
int V_10 ;
V_53 V_56 ;
F_17 ( V_57 , V_58 ) ;
F_18 ( & V_56 ) ;
V_55 -> V_2 = V_2 ;
V_55 -> V_59 = F_14 ;
V_55 -> V_54 = ( unsigned long ) & V_56 ;
V_10 = V_2 -> V_55 ( V_2 , V_55 ) ;
if ( ! V_10 ) {
F_19 ( V_60 ) ;
F_20 ( & V_56 , & V_57 ) ;
if ( V_55 -> V_61 != V_62
&& V_55 -> V_61 != V_63 )
F_21 () ;
F_22 ( & V_56 , & V_57 ) ;
F_19 ( V_64 ) ;
V_10 = ( V_55 -> V_61 == V_63 ) ? - V_65 : 0 ;
}
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_13 ;
int V_11 , V_10 ;
T_4 V_66 , V_67 = 0 ;
struct V_51 * V_55 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
return - V_24 ;
if ( V_52 -> V_68 > V_8 -> V_2 . V_14 )
return - V_20 ;
if ( V_52 -> V_4 + V_52 -> V_68 > V_8 -> V_2 . V_14 )
return - V_20 ;
if ( ! V_8 -> V_2 . V_69 ) {
if ( V_52 -> V_68 & ( V_8 -> V_2 . V_70 - 1 ) )
return - V_20 ;
if ( V_52 -> V_4 & ( V_8 -> V_2 . V_70 - 1 ) )
return - V_20 ;
} else {
struct V_71 * V_72 =
V_8 -> V_2 . V_73 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_2 . V_69 &&
V_52 -> V_68 >= V_72 [ V_11 ] . V_67 ; V_11 ++ ) ;
-- V_11 ;
if ( V_11 < 0 || V_52 -> V_68 & ( V_72 [ V_11 ] . V_70 - 1 ) )
return - V_20 ;
for (; V_11 < V_8 -> V_2 . V_69 &&
( V_52 -> V_68 + V_52 -> V_4 ) >= V_72 [ V_11 ] . V_67 ;
++ V_11 ) ;
-- V_11 ;
if ( V_11 < 0 || ( ( V_52 -> V_68 + V_52 -> V_4 ) &
( V_72 [ V_11 ] . V_70 - 1 ) ) )
return - V_20 ;
}
V_52 -> V_74 = V_75 ;
V_55 = F_24 ( sizeof ( struct V_51 ) , V_36 ) ;
if ( ! V_55 )
return - V_37 ;
* V_55 = * V_52 ;
V_66 = V_52 -> V_4 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_13 -> V_14 <= V_55 -> V_68 ) {
V_55 -> V_68 -= V_13 -> V_14 ;
V_67 += V_13 -> V_14 ;
} else {
break;
}
}
F_25 ( V_11 >= V_8 -> V_12 ) ;
V_10 = 0 ;
for (; V_66 > 0 ; V_11 ++ ) {
V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_55 -> V_68 + V_66 > V_13 -> V_14 )
V_55 -> V_4 = V_13 -> V_14 - V_55 -> V_68 ;
else
V_55 -> V_4 = V_66 ;
if ( ! ( V_13 -> V_22 & V_23 ) ) {
V_10 = - V_24 ;
break;
}
V_66 -= V_55 -> V_4 ;
if ( ( V_10 = F_16 ( V_13 , V_55 ) ) ) {
F_25 ( V_10 == - V_20 ) ;
if ( V_55 -> V_74 != V_75 )
V_52 -> V_74 = V_55 -> V_74 + V_67 ;
break;
}
V_55 -> V_68 = 0 ;
V_67 += V_13 -> V_14 ;
}
V_52 -> V_61 = V_55 -> V_61 ;
F_11 ( V_55 ) ;
if ( V_10 )
return V_10 ;
if ( V_52 -> V_59 )
V_52 -> V_59 ( V_52 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_76 , T_4 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = - V_20 ;
if ( ( V_4 + V_76 ) > V_2 -> V_14 )
return - V_20 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_4 V_14 ;
if ( V_76 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_76 -= V_13 -> V_14 ;
continue;
}
if ( V_76 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_76 ;
else
V_14 = V_4 ;
if ( V_13 -> V_77 ) {
V_10 = V_13 -> V_77 ( V_13 , V_76 , V_14 ) ;
if ( V_10 )
break;
} else
V_10 = - V_78 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_20 ;
V_76 = 0 ;
}
return V_10 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_76 , T_4 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = 0 ;
if ( ( V_4 + V_76 ) > V_2 -> V_14 )
return - V_20 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_4 V_14 ;
if ( V_76 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_76 -= V_13 -> V_14 ;
continue;
}
if ( V_76 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_76 ;
else
V_14 = V_4 ;
if ( V_13 -> V_79 ) {
V_10 = V_13 -> V_79 ( V_13 , V_76 , V_14 ) ;
if ( V_10 )
break;
} else
V_10 = - V_78 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_20 ;
V_76 = 0 ;
}
return V_10 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
V_13 -> V_80 ( V_13 ) ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_81 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( ( V_81 = V_13 -> V_82 ( V_13 ) ) < 0 )
return V_81 ;
}
return V_81 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
V_13 -> V_83 ( V_13 ) ;
}
}
static int F_31 ( struct V_1 * V_2 , T_1 V_76 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_84 = 0 ;
if ( ! V_8 -> V_13 [ 0 ] -> V_85 )
return V_84 ;
if ( V_76 > V_2 -> V_14 )
return - V_20 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_76 >= V_13 -> V_14 ) {
V_76 -= V_13 -> V_14 ;
continue;
}
V_84 = V_13 -> V_85 ( V_13 , V_76 ) ;
break;
}
return V_84 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_76 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = - V_20 ;
if ( ! V_8 -> V_13 [ 0 ] -> V_86 )
return 0 ;
if ( V_76 > V_2 -> V_14 )
return - V_20 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_76 >= V_13 -> V_14 ) {
V_76 -= V_13 -> V_14 ;
continue;
}
V_10 = V_13 -> V_86 ( V_13 , V_76 ) ;
if ( ! V_10 )
V_2 -> V_17 . V_87 ++ ;
break;
}
return V_10 ;
}
static unsigned long F_33 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_67 ,
unsigned long V_22 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_67 >= V_13 -> V_14 ) {
V_67 -= V_13 -> V_14 ;
continue;
}
if ( V_67 + V_4 > V_13 -> V_14 )
return ( unsigned long ) - V_20 ;
if ( V_13 -> V_88 )
return V_13 -> V_88 ( V_13 , V_4 , V_67 ,
V_22 ) ;
break;
}
return ( unsigned long ) - V_89 ;
}
struct V_1 * F_34 ( struct V_1 * V_13 [] ,
int V_90 ,
const char * V_91 )
{
int V_11 ;
T_2 V_14 ;
struct V_7 * V_8 ;
T_5 V_92 , V_93 ;
int V_94 ;
int V_95 = 0 ;
F_35 ( V_96 L_1 ) ;
for ( V_11 = 0 ; V_11 < V_90 ; V_11 ++ )
F_35 ( V_96 L_2 , V_11 , V_13 [ V_11 ] -> V_91 ) ;
F_35 ( V_96 L_3 , V_91 ) ;
V_14 = F_36 ( V_90 ) ;
V_8 = F_37 ( V_14 , V_36 ) ;
if ( ! V_8 ) {
F_35
( L_4 ,
V_91 ) ;
return NULL ;
}
V_8 -> V_13 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_8 -> V_2 . type = V_13 [ 0 ] -> type ;
V_8 -> V_2 . V_22 = V_13 [ 0 ] -> V_22 ;
V_8 -> V_2 . V_14 = V_13 [ 0 ] -> V_14 ;
V_8 -> V_2 . V_70 = V_13 [ 0 ] -> V_70 ;
V_8 -> V_2 . V_34 = V_13 [ 0 ] -> V_34 ;
for ( V_11 = 0 ; V_11 < V_90 ; V_11 ++ )
if ( V_95 < V_13 [ V_11 ] -> V_97 )
V_95 = V_13 [ V_11 ] -> V_97 ;
V_8 -> V_2 . V_97 = V_95 ;
V_8 -> V_2 . V_98 = V_13 [ 0 ] -> V_98 ;
V_8 -> V_2 . V_99 = V_13 [ 0 ] -> V_99 ;
V_8 -> V_2 . V_100 = V_13 [ 0 ] -> V_100 ;
if ( V_13 [ 0 ] -> V_40 )
V_8 -> V_2 . V_40 = F_7 ;
if ( V_13 [ 0 ] -> V_46 )
V_8 -> V_2 . V_46 = F_12 ;
if ( V_13 [ 0 ] -> V_50 )
V_8 -> V_2 . V_50 = F_13 ;
if ( V_13 [ 0 ] -> V_85 )
V_8 -> V_2 . V_85 = F_31 ;
if ( V_13 [ 0 ] -> V_86 )
V_8 -> V_2 . V_86 = F_32 ;
V_8 -> V_2 . V_17 . V_87 = V_13 [ 0 ] -> V_17 . V_87 ;
V_8 -> V_2 . V_101 = V_13 [ 0 ] -> V_101 ;
V_8 -> V_13 [ 0 ] = V_13 [ 0 ] ;
for ( V_11 = 1 ; V_11 < V_90 ; V_11 ++ ) {
if ( V_8 -> V_2 . type != V_13 [ V_11 ] -> type ) {
F_11 ( V_8 ) ;
F_35 ( L_5 ,
V_13 [ V_11 ] -> V_91 ) ;
return NULL ;
}
if ( V_8 -> V_2 . V_22 != V_13 [ V_11 ] -> V_22 ) {
if ( ( V_8 -> V_2 . V_22 ^ V_13 [ V_11 ] ->
V_22 ) & ~ V_23 ) {
F_11 ( V_8 ) ;
F_35 ( L_6 ,
V_13 [ V_11 ] -> V_91 ) ;
return NULL ;
} else
V_8 -> V_2 . V_22 |=
V_13 [ V_11 ] -> V_22 & V_23 ;
}
if ( V_8 -> V_2 . V_101 !=
V_13 [ V_11 ] -> V_101 )
V_8 -> V_2 . V_101 =
& V_102 ;
V_8 -> V_2 . V_14 += V_13 [ V_11 ] -> V_14 ;
V_8 -> V_2 . V_17 . V_87 +=
V_13 [ V_11 ] -> V_17 . V_87 ;
if ( V_8 -> V_2 . V_34 != V_13 [ V_11 ] -> V_34 ||
V_8 -> V_2 . V_98 != V_13 [ V_11 ] -> V_98 ||
V_8 -> V_2 . V_99 != V_13 [ V_11 ] -> V_99 ||
! V_8 -> V_2 . V_46 != ! V_13 [ V_11 ] -> V_46 ||
! V_8 -> V_2 . V_50 != ! V_13 [ V_11 ] -> V_50 ) {
F_11 ( V_8 ) ;
F_35 ( L_7 ,
V_13 [ V_11 ] -> V_91 ) ;
return NULL ;
}
V_8 -> V_13 [ V_11 ] = V_13 [ V_11 ] ;
}
V_8 -> V_2 . V_103 = V_13 [ 0 ] -> V_103 ;
V_8 -> V_12 = V_90 ;
V_8 -> V_2 . V_91 = V_91 ;
V_8 -> V_2 . V_55 = F_23 ;
V_8 -> V_2 . V_16 = F_1 ;
V_8 -> V_2 . V_25 = F_6 ;
V_8 -> V_2 . V_80 = F_28 ;
V_8 -> V_2 . V_77 = F_26 ;
V_8 -> V_2 . V_79 = F_27 ;
V_8 -> V_2 . V_82 = F_29 ;
V_8 -> V_2 . V_83 = F_30 ;
V_8 -> V_2 . V_88 = F_33 ;
V_92 = V_93 = V_13 [ 0 ] -> V_70 ;
V_94 = 1 ;
for ( V_11 = 0 ; V_11 < V_90 ; V_11 ++ ) {
if ( V_13 [ V_11 ] -> V_69 == 0 ) {
if ( V_13 [ V_11 ] -> V_70 != V_93 ) {
++ V_94 ;
V_93 = V_13 [ V_11 ] -> V_70 ;
if ( V_93 > V_92 )
V_92 = V_93 ;
}
} else {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_13 [ V_11 ] -> V_69 ; V_104 ++ ) {
if ( V_13 [ V_11 ] -> V_73 [ V_104 ] . V_70 !=
V_93 ) {
++ V_94 ;
V_93 =
V_13 [ V_11 ] -> V_73 [ V_104 ] .
V_70 ;
if ( V_93 > V_92 )
V_92 = V_93 ;
}
}
}
}
if ( V_94 == 1 ) {
V_8 -> V_2 . V_70 = V_93 ;
V_8 -> V_2 . V_69 = 0 ;
} else {
T_4 V_105 ;
struct V_71 * V_106 ;
T_4 V_107 , V_108 ;
V_8 -> V_2 . V_70 = V_92 ;
V_8 -> V_2 . V_69 = V_94 ;
V_8 -> V_2 . V_73 = V_106 =
F_24 ( V_94 *
sizeof ( struct V_71 ) , V_36 ) ;
if ( ! V_106 ) {
F_11 ( V_8 ) ;
F_35
( L_8
L_9 , V_91 ) ;
return NULL ;
}
V_93 = V_13 [ 0 ] -> V_70 ;
V_107 = V_108 = 0 ;
for ( V_11 = 0 ; V_11 < V_90 ; V_11 ++ ) {
if ( V_13 [ V_11 ] -> V_69 == 0 ) {
if ( V_13 [ V_11 ] -> V_70 != V_93 ) {
V_106 -> V_67 = V_107 ;
V_106 -> V_70 =
V_93 ;
V_105 = V_108 - V_107 ;
F_8 ( V_105 , V_93 ) ;
V_106 -> V_109 = V_105 ;
V_107 = V_108 ;
V_93 = V_13 [ V_11 ] -> V_70 ;
++ V_106 ;
}
V_108 += V_13 [ V_11 ] -> V_14 ;
} else {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_13 [ V_11 ] -> V_69 ; V_104 ++ ) {
if ( V_13 [ V_11 ] -> V_73 [ V_104 ] .
V_70 != V_93 ) {
V_106 -> V_67 = V_107 ;
V_106 -> V_70 =
V_93 ;
V_105 = V_108 - V_107 ;
F_8 ( V_105 , V_93 ) ;
V_106 -> V_109 = V_105 ;
V_107 = V_108 ;
V_93 =
V_13 [ V_11 ] -> V_73 [ V_104 ] .
V_70 ;
++ V_106 ;
}
V_108 +=
V_13 [ V_11 ] -> V_73 [ V_104 ] .
V_109 * ( T_4 ) V_93 ;
}
}
}
V_106 -> V_67 = V_107 ;
V_106 -> V_70 = V_93 ;
V_105 = V_108 - V_107 ;
F_8 ( V_105 , V_93 ) ;
V_106 -> V_109 = V_105 ;
}
return & V_8 -> V_2 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_2 . V_69 )
F_11 ( V_8 -> V_2 . V_73 ) ;
F_11 ( V_8 ) ;
}
