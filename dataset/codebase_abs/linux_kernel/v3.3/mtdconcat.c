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
V_10 = F_3 ( V_13 , V_3 , V_14 , & V_15 , V_6 ) ;
if ( F_4 ( V_10 ) ) {
if ( F_5 ( V_10 ) ) {
V_2 -> V_16 . V_17 ++ ;
V_9 = V_10 ;
} else if ( F_6 ( V_10 ) ) {
V_2 -> V_16 . V_18 ++ ;
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
return - V_19 ;
}
static int
F_7 ( struct V_1 * V_2 , T_1 V_20 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_10 = - V_19 ;
int V_11 ;
if ( ! ( V_2 -> V_21 & V_22 ) )
return - V_23 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_15 ;
if ( V_20 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_20 -= V_13 -> V_14 ;
continue;
}
if ( V_20 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_20 ;
else
V_14 = V_4 ;
if ( ! ( V_13 -> V_21 & V_22 ) )
V_10 = - V_23 ;
else
V_10 = F_8 ( V_13 , V_20 , V_14 , & V_15 , V_6 ) ;
if ( V_10 )
break;
* V_5 += V_15 ;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_19 ;
V_6 += V_14 ;
V_20 = 0 ;
}
return V_10 ;
}
static int
F_9 ( struct V_1 * V_2 , const struct V_24 * V_25 ,
unsigned long V_26 , T_1 V_20 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_24 * V_27 ;
unsigned long V_28 , V_29 ;
T_2 V_30 = 0 ;
int V_11 ;
int V_10 = - V_19 ;
if ( ! ( V_2 -> V_21 & V_22 ) )
return - V_23 ;
* V_5 = 0 ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ )
V_30 += V_25 [ V_11 ] . V_31 ;
if ( ( V_20 + V_30 ) > V_2 -> V_14 )
return - V_19 ;
if ( V_2 -> V_32 > 1 ) {
T_4 V_33 = V_20 ;
if ( F_10 ( V_33 , V_2 -> V_32 ) || ( V_30 % V_2 -> V_32 ) )
return - V_19 ;
}
V_27 = F_11 ( V_25 , sizeof( struct V_24 ) * V_26 , V_34 ) ;
if ( ! V_27 )
return - V_35 ;
V_28 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_2 V_14 , V_36 , V_15 , V_37 ;
if ( V_20 >= V_13 -> V_14 ) {
V_20 -= V_13 -> V_14 ;
continue;
}
V_14 = F_12 ( T_4 , V_30 , V_13 -> V_14 - V_20 ) ;
V_36 = V_14 ;
V_29 = V_28 ;
while ( V_29 < V_26 ) {
if ( V_14 <= V_27 [ V_29 ] . V_31 )
break;
V_14 -= V_27 [ V_29 ++ ] . V_31 ;
}
V_37 = V_27 [ V_29 ] . V_31 ;
V_27 [ V_29 ] . V_31 = V_14 ;
if ( ! ( V_13 -> V_21 & V_22 ) )
V_10 = - V_23 ;
else
V_10 = F_13 ( V_13 , & V_27 [ V_28 ] ,
V_29 - V_28 + 1 , V_20 ,
& V_15 ) ;
V_27 [ V_29 ] . V_31 = V_37 - V_14 ;
V_27 [ V_29 ] . V_38 += V_14 ;
V_28 = V_29 ;
if ( V_10 )
break;
* V_5 += V_15 ;
V_30 -= V_36 ;
if ( V_30 == 0 )
break;
V_10 = - V_19 ;
V_20 = 0 ;
}
F_14 ( V_27 ) ;
return V_10 ;
}
static int
F_15 ( struct V_1 * V_2 , T_1 V_3 , struct V_39 * V_40 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_39 V_41 = * V_40 ;
int V_11 , V_10 , V_9 = 0 ;
V_40 -> V_5 = V_40 -> V_42 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_3 >= V_13 -> V_14 ) {
V_3 -= V_13 -> V_14 ;
continue;
}
if ( V_3 + V_41 . V_4 > V_13 -> V_14 )
V_41 . V_4 = V_13 -> V_14 - V_3 ;
V_10 = F_16 ( V_13 , V_3 , & V_41 ) ;
V_40 -> V_5 += V_41 . V_5 ;
V_40 -> V_42 += V_41 . V_42 ;
if ( F_4 ( V_10 ) ) {
if ( F_5 ( V_10 ) ) {
V_2 -> V_16 . V_17 ++ ;
V_9 = V_10 ;
} else if ( F_6 ( V_10 ) ) {
V_2 -> V_16 . V_18 ++ ;
if ( ! V_9 )
V_9 = V_10 ;
} else
return V_10 ;
}
if ( V_41 . V_43 ) {
V_41 . V_4 = V_40 -> V_4 - V_40 -> V_5 ;
if ( ! V_41 . V_4 )
return V_9 ;
V_41 . V_43 += V_41 . V_5 ;
}
if ( V_41 . V_44 ) {
V_41 . V_45 = V_40 -> V_45 - V_40 -> V_42 ;
if ( ! V_41 . V_45 )
return V_9 ;
V_41 . V_44 += V_40 -> V_42 ;
}
V_3 = 0 ;
}
return - V_19 ;
}
static int
F_17 ( struct V_1 * V_2 , T_1 V_20 , struct V_39 * V_40 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_39 V_41 = * V_40 ;
int V_11 , V_10 ;
if ( ! ( V_2 -> V_21 & V_22 ) )
return - V_23 ;
V_40 -> V_5 = V_40 -> V_42 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_20 >= V_13 -> V_14 ) {
V_20 -= V_13 -> V_14 ;
continue;
}
if ( V_20 + V_41 . V_4 > V_13 -> V_14 )
V_41 . V_4 = V_13 -> V_14 - V_20 ;
V_10 = F_18 ( V_13 , V_20 , & V_41 ) ;
V_40 -> V_5 += V_41 . V_42 ;
if ( V_10 )
return V_10 ;
if ( V_41 . V_43 ) {
V_41 . V_4 = V_40 -> V_4 - V_40 -> V_5 ;
if ( ! V_41 . V_4 )
return 0 ;
V_41 . V_43 += V_41 . V_5 ;
}
if ( V_41 . V_44 ) {
V_41 . V_45 = V_40 -> V_45 - V_40 -> V_42 ;
if ( ! V_41 . V_45 )
return 0 ;
V_41 . V_44 += V_41 . V_42 ;
}
V_20 = 0 ;
}
return - V_19 ;
}
static void F_19 ( struct V_46 * V_47 )
{
F_20 ( ( V_48 * ) V_47 -> V_49 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_46 * V_50 )
{
int V_10 ;
V_48 V_51 ;
F_22 ( V_52 , V_53 ) ;
F_23 ( & V_51 ) ;
V_50 -> V_2 = V_2 ;
V_50 -> V_54 = F_19 ;
V_50 -> V_49 = ( unsigned long ) & V_51 ;
V_10 = F_24 ( V_2 , V_50 ) ;
if ( ! V_10 ) {
F_25 ( V_55 ) ;
F_26 ( & V_51 , & V_52 ) ;
if ( V_50 -> V_56 != V_57
&& V_50 -> V_56 != V_58 )
F_27 () ;
F_28 ( & V_51 , & V_52 ) ;
F_25 ( V_59 ) ;
V_10 = ( V_50 -> V_56 == V_58 ) ? - V_60 : 0 ;
}
return V_10 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_13 ;
int V_11 , V_10 ;
T_4 V_61 , V_62 = 0 ;
struct V_46 * V_50 ;
if ( ! ( V_2 -> V_21 & V_22 ) )
return - V_23 ;
if ( V_47 -> V_63 > V_8 -> V_2 . V_14 )
return - V_19 ;
if ( V_47 -> V_4 + V_47 -> V_63 > V_8 -> V_2 . V_14 )
return - V_19 ;
if ( ! V_8 -> V_2 . V_64 ) {
if ( V_47 -> V_63 & ( V_8 -> V_2 . V_65 - 1 ) )
return - V_19 ;
if ( V_47 -> V_4 & ( V_8 -> V_2 . V_65 - 1 ) )
return - V_19 ;
} else {
struct V_66 * V_67 =
V_8 -> V_2 . V_68 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_2 . V_64 &&
V_47 -> V_63 >= V_67 [ V_11 ] . V_62 ; V_11 ++ ) ;
-- V_11 ;
if ( V_11 < 0 || V_47 -> V_63 & ( V_67 [ V_11 ] . V_65 - 1 ) )
return - V_19 ;
for (; V_11 < V_8 -> V_2 . V_64 &&
( V_47 -> V_63 + V_47 -> V_4 ) >= V_67 [ V_11 ] . V_62 ;
++ V_11 ) ;
-- V_11 ;
if ( V_11 < 0 || ( ( V_47 -> V_63 + V_47 -> V_4 ) &
( V_67 [ V_11 ] . V_65 - 1 ) ) )
return - V_19 ;
}
V_47 -> V_69 = V_70 ;
V_50 = F_30 ( sizeof ( struct V_46 ) , V_34 ) ;
if ( ! V_50 )
return - V_35 ;
* V_50 = * V_47 ;
V_61 = V_47 -> V_4 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_13 -> V_14 <= V_50 -> V_63 ) {
V_50 -> V_63 -= V_13 -> V_14 ;
V_62 += V_13 -> V_14 ;
} else {
break;
}
}
F_31 ( V_11 >= V_8 -> V_12 ) ;
V_10 = 0 ;
for (; V_61 > 0 ; V_11 ++ ) {
V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_50 -> V_63 + V_61 > V_13 -> V_14 )
V_50 -> V_4 = V_13 -> V_14 - V_50 -> V_63 ;
else
V_50 -> V_4 = V_61 ;
if ( ! ( V_13 -> V_21 & V_22 ) ) {
V_10 = - V_23 ;
break;
}
V_61 -= V_50 -> V_4 ;
if ( ( V_10 = F_21 ( V_13 , V_50 ) ) ) {
F_31 ( V_10 == - V_19 ) ;
if ( V_50 -> V_69 != V_70 )
V_47 -> V_69 = V_50 -> V_69 + V_62 ;
break;
}
V_50 -> V_63 = 0 ;
V_62 += V_13 -> V_14 ;
}
V_47 -> V_56 = V_50 -> V_56 ;
F_14 ( V_50 ) ;
if ( V_10 )
return V_10 ;
if ( V_47 -> V_54 )
V_47 -> V_54 ( V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_71 , T_4 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = - V_19 ;
if ( ( V_4 + V_71 ) > V_2 -> V_14 )
return - V_19 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_4 V_14 ;
if ( V_71 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_71 -= V_13 -> V_14 ;
continue;
}
if ( V_71 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_71 ;
else
V_14 = V_4 ;
V_10 = F_33 ( V_13 , V_71 , V_14 ) ;
if ( V_10 )
break;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_19 ;
V_71 = 0 ;
}
return V_10 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_71 , T_4 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = 0 ;
if ( ( V_4 + V_71 ) > V_2 -> V_14 )
return - V_19 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
T_4 V_14 ;
if ( V_71 >= V_13 -> V_14 ) {
V_14 = 0 ;
V_71 -= V_13 -> V_14 ;
continue;
}
if ( V_71 + V_4 > V_13 -> V_14 )
V_14 = V_13 -> V_14 - V_71 ;
else
V_14 = V_4 ;
V_10 = F_35 ( V_13 , V_71 , V_14 ) ;
if ( V_10 )
break;
V_4 -= V_14 ;
if ( V_4 == 0 )
break;
V_10 = - V_19 ;
V_71 = 0 ;
}
return V_10 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
F_37 ( V_13 ) ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_72 = 0 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( ( V_72 = F_39 ( V_13 ) ) < 0 )
return V_72 ;
}
return V_72 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
F_41 ( V_13 ) ;
}
}
static int F_42 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_73 = 0 ;
if ( ! F_43 ( V_8 -> V_13 [ 0 ] ) )
return V_73 ;
if ( V_71 > V_2 -> V_14 )
return - V_19 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_71 >= V_13 -> V_14 ) {
V_71 -= V_13 -> V_14 ;
continue;
}
V_73 = F_44 ( V_13 , V_71 ) ;
break;
}
return V_73 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 , V_10 = - V_19 ;
if ( ! F_43 ( V_8 -> V_13 [ 0 ] ) )
return 0 ;
if ( V_71 > V_2 -> V_14 )
return - V_19 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_71 >= V_13 -> V_14 ) {
V_71 -= V_13 -> V_14 ;
continue;
}
V_10 = F_46 ( V_13 , V_71 ) ;
if ( ! V_10 )
V_2 -> V_16 . V_74 ++ ;
break;
}
return V_10 ;
}
static unsigned long F_47 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_62 ,
unsigned long V_21 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; V_11 ++ ) {
struct V_1 * V_13 = V_8 -> V_13 [ V_11 ] ;
if ( V_62 >= V_13 -> V_14 ) {
V_62 -= V_13 -> V_14 ;
continue;
}
if ( V_62 + V_4 > V_13 -> V_14 )
return ( unsigned long ) - V_19 ;
return F_48 ( V_13 , V_4 , V_62 , V_21 ) ;
}
return ( unsigned long ) - V_75 ;
}
struct V_1 * F_49 ( struct V_1 * V_13 [] ,
int V_76 ,
const char * V_77 )
{
int V_11 ;
T_2 V_14 ;
struct V_7 * V_8 ;
T_5 V_78 , V_79 ;
int V_80 ;
int V_81 = 0 ;
F_50 ( V_82 L_1 ) ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ )
F_50 ( V_82 L_2 , V_11 , V_13 [ V_11 ] -> V_77 ) ;
F_50 ( V_82 L_3 , V_77 ) ;
V_14 = F_51 ( V_76 ) ;
V_8 = F_52 ( V_14 , V_34 ) ;
if ( ! V_8 ) {
F_50
( L_4 ,
V_77 ) ;
return NULL ;
}
V_8 -> V_13 = (struct V_1 * * ) ( V_8 + 1 ) ;
V_8 -> V_2 . type = V_13 [ 0 ] -> type ;
V_8 -> V_2 . V_21 = V_13 [ 0 ] -> V_21 ;
V_8 -> V_2 . V_14 = V_13 [ 0 ] -> V_14 ;
V_8 -> V_2 . V_65 = V_13 [ 0 ] -> V_65 ;
V_8 -> V_2 . V_32 = V_13 [ 0 ] -> V_32 ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ )
if ( V_81 < V_13 [ V_11 ] -> V_83 )
V_81 = V_13 [ V_11 ] -> V_83 ;
V_8 -> V_2 . V_83 = V_81 ;
V_8 -> V_2 . V_84 = V_13 [ 0 ] -> V_84 ;
V_8 -> V_2 . V_85 = V_13 [ 0 ] -> V_85 ;
V_8 -> V_2 . V_86 = V_13 [ 0 ] -> V_86 ;
if ( V_13 [ 0 ] -> V_87 )
V_8 -> V_2 . V_87 = F_9 ;
if ( V_13 [ 0 ] -> V_88 )
V_8 -> V_2 . V_88 = F_15 ;
if ( V_13 [ 0 ] -> V_89 )
V_8 -> V_2 . V_89 = F_17 ;
if ( V_13 [ 0 ] -> V_90 )
V_8 -> V_2 . V_90 = F_42 ;
if ( V_13 [ 0 ] -> V_91 )
V_8 -> V_2 . V_91 = F_45 ;
V_8 -> V_2 . V_16 . V_74 = V_13 [ 0 ] -> V_16 . V_74 ;
V_8 -> V_2 . V_92 = V_13 [ 0 ] -> V_92 ;
V_8 -> V_13 [ 0 ] = V_13 [ 0 ] ;
for ( V_11 = 1 ; V_11 < V_76 ; V_11 ++ ) {
if ( V_8 -> V_2 . type != V_13 [ V_11 ] -> type ) {
F_14 ( V_8 ) ;
F_50 ( L_5 ,
V_13 [ V_11 ] -> V_77 ) ;
return NULL ;
}
if ( V_8 -> V_2 . V_21 != V_13 [ V_11 ] -> V_21 ) {
if ( ( V_8 -> V_2 . V_21 ^ V_13 [ V_11 ] ->
V_21 ) & ~ V_22 ) {
F_14 ( V_8 ) ;
F_50 ( L_6 ,
V_13 [ V_11 ] -> V_77 ) ;
return NULL ;
} else
V_8 -> V_2 . V_21 |=
V_13 [ V_11 ] -> V_21 & V_22 ;
}
if ( V_8 -> V_2 . V_92 !=
V_13 [ V_11 ] -> V_92 )
V_8 -> V_2 . V_92 =
& V_93 ;
V_8 -> V_2 . V_14 += V_13 [ V_11 ] -> V_14 ;
V_8 -> V_2 . V_16 . V_74 +=
V_13 [ V_11 ] -> V_16 . V_74 ;
if ( V_8 -> V_2 . V_32 != V_13 [ V_11 ] -> V_32 ||
V_8 -> V_2 . V_84 != V_13 [ V_11 ] -> V_84 ||
V_8 -> V_2 . V_85 != V_13 [ V_11 ] -> V_85 ||
! V_8 -> V_2 . V_88 != ! V_13 [ V_11 ] -> V_88 ||
! V_8 -> V_2 . V_89 != ! V_13 [ V_11 ] -> V_89 ) {
F_14 ( V_8 ) ;
F_50 ( L_7 ,
V_13 [ V_11 ] -> V_77 ) ;
return NULL ;
}
V_8 -> V_13 [ V_11 ] = V_13 [ V_11 ] ;
}
V_8 -> V_2 . V_94 = V_13 [ 0 ] -> V_94 ;
V_8 -> V_12 = V_76 ;
V_8 -> V_2 . V_77 = V_77 ;
V_8 -> V_2 . V_50 = F_29 ;
V_8 -> V_2 . V_95 = F_1 ;
V_8 -> V_2 . V_96 = F_7 ;
V_8 -> V_2 . V_97 = F_36 ;
V_8 -> V_2 . V_98 = F_32 ;
V_8 -> V_2 . V_99 = F_34 ;
V_8 -> V_2 . V_100 = F_38 ;
V_8 -> V_2 . V_101 = F_40 ;
V_8 -> V_2 . V_102 = F_47 ;
V_78 = V_79 = V_13 [ 0 ] -> V_65 ;
V_80 = 1 ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) {
if ( V_13 [ V_11 ] -> V_64 == 0 ) {
if ( V_13 [ V_11 ] -> V_65 != V_79 ) {
++ V_80 ;
V_79 = V_13 [ V_11 ] -> V_65 ;
if ( V_79 > V_78 )
V_78 = V_79 ;
}
} else {
int V_103 ;
for ( V_103 = 0 ; V_103 < V_13 [ V_11 ] -> V_64 ; V_103 ++ ) {
if ( V_13 [ V_11 ] -> V_68 [ V_103 ] . V_65 !=
V_79 ) {
++ V_80 ;
V_79 =
V_13 [ V_11 ] -> V_68 [ V_103 ] .
V_65 ;
if ( V_79 > V_78 )
V_78 = V_79 ;
}
}
}
}
if ( V_80 == 1 ) {
V_8 -> V_2 . V_65 = V_79 ;
V_8 -> V_2 . V_64 = 0 ;
} else {
T_4 V_104 ;
struct V_66 * V_105 ;
T_4 V_106 , V_107 ;
V_8 -> V_2 . V_65 = V_78 ;
V_8 -> V_2 . V_64 = V_80 ;
V_8 -> V_2 . V_68 = V_105 =
F_30 ( V_80 *
sizeof ( struct V_66 ) , V_34 ) ;
if ( ! V_105 ) {
F_14 ( V_8 ) ;
F_50
( L_8
L_9 , V_77 ) ;
return NULL ;
}
V_79 = V_13 [ 0 ] -> V_65 ;
V_106 = V_107 = 0 ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) {
if ( V_13 [ V_11 ] -> V_64 == 0 ) {
if ( V_13 [ V_11 ] -> V_65 != V_79 ) {
V_105 -> V_62 = V_106 ;
V_105 -> V_65 =
V_79 ;
V_104 = V_107 - V_106 ;
F_10 ( V_104 , V_79 ) ;
V_105 -> V_108 = V_104 ;
V_106 = V_107 ;
V_79 = V_13 [ V_11 ] -> V_65 ;
++ V_105 ;
}
V_107 += V_13 [ V_11 ] -> V_14 ;
} else {
int V_103 ;
for ( V_103 = 0 ; V_103 < V_13 [ V_11 ] -> V_64 ; V_103 ++ ) {
if ( V_13 [ V_11 ] -> V_68 [ V_103 ] .
V_65 != V_79 ) {
V_105 -> V_62 = V_106 ;
V_105 -> V_65 =
V_79 ;
V_104 = V_107 - V_106 ;
F_10 ( V_104 , V_79 ) ;
V_105 -> V_108 = V_104 ;
V_106 = V_107 ;
V_79 =
V_13 [ V_11 ] -> V_68 [ V_103 ] .
V_65 ;
++ V_105 ;
}
V_107 +=
V_13 [ V_11 ] -> V_68 [ V_103 ] .
V_108 * ( T_4 ) V_79 ;
}
}
}
V_105 -> V_62 = V_106 ;
V_105 -> V_65 = V_79 ;
V_104 = V_107 - V_106 ;
F_10 ( V_104 , V_79 ) ;
V_105 -> V_108 = V_104 ;
}
return & V_8 -> V_2 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_2 . V_64 )
F_14 ( V_8 -> V_2 . V_68 ) ;
F_14 ( V_8 ) ;
}
