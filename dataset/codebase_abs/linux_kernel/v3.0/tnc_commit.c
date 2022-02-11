static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 , int V_9 )
{
struct V_5 * V_10 ;
int V_11 , V_12 ;
V_4 -> V_13 . V_14 = V_15 ;
V_4 -> V_16 = F_2 ( V_6 -> V_16 ) ;
V_4 -> V_17 = F_2 ( V_6 -> V_17 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_16 ; V_11 ++ ) {
struct V_18 * V_19 = F_3 ( V_2 , V_4 , V_11 ) ;
struct V_20 * V_21 = & V_6 -> V_22 [ V_11 ] ;
F_4 ( V_2 , & V_21 -> V_23 , & V_19 -> V_23 ) ;
V_19 -> V_7 = F_5 ( V_21 -> V_7 ) ;
V_19 -> V_8 = F_5 ( V_21 -> V_8 ) ;
V_19 -> V_9 = F_5 ( V_21 -> V_9 ) ;
if ( ! V_21 -> V_7 || ! V_21 -> V_9 ) {
F_6 ( L_1 ) ;
F_7 ( V_2 , V_6 ) ;
if ( V_21 -> V_6 )
F_7 ( V_2 , V_21 -> V_6 ) ;
}
}
F_8 ( V_2 , V_4 , V_9 , 0 ) ;
#ifdef F_9
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_9 = V_9 ;
#endif
V_12 = F_10 ( V_2 , V_6 ) ;
V_10 = V_6 -> V_24 ;
if ( V_10 ) {
struct V_20 * V_21 ;
V_21 = & V_10 -> V_22 [ V_6 -> V_25 ] ;
V_21 -> V_7 = V_7 ;
V_21 -> V_8 = V_8 ;
V_21 -> V_9 = V_9 ;
} else {
V_2 -> V_26 . V_7 = V_7 ;
V_2 -> V_26 . V_8 = V_8 ;
V_2 -> V_26 . V_9 = V_9 ;
}
V_2 -> V_27 += F_11 ( V_9 , 8 ) ;
F_12 ( & V_2 -> V_28 ) ;
F_13 ( F_14 ( V_6 ) ) ;
F_13 ( F_15 ( V_29 , & V_6 -> V_30 ) ) ;
F_16 ( V_31 , & V_6 -> V_30 ) ;
F_16 ( V_29 , & V_6 -> V_30 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 , int V_7 , int V_32 , int V_33 ,
int * V_34 )
{
int V_9 , V_35 , V_36 , V_37 , V_38 ;
F_13 ( ( V_32 & 7 ) == 0 ) ;
F_13 ( ( V_33 & 7 ) == 0 ) ;
F_13 ( V_33 >= V_32 ) ;
V_35 = V_33 - V_32 ;
if ( ! V_35 )
return 0 ;
V_36 = V_32 ;
V_37 = 0 ;
while ( V_2 -> V_39 ) {
V_9 = F_18 ( V_2 , V_2 -> V_39 -> V_16 ) ;
if ( V_9 < V_35 ) {
struct V_5 * V_6 = V_2 -> V_39 ;
const int V_40 = F_11 ( V_9 , 8 ) ;
int V_12 ;
F_13 ( V_40 <= V_35 ) ;
V_12 = F_1 ( V_2 , V_2 -> V_41 + V_36 , V_6 ,
V_7 , V_36 , V_9 ) ;
if ( V_12 )
return V_12 ;
V_35 -= V_40 ;
V_36 += V_40 ;
V_2 -> V_39 = V_6 -> V_42 ;
if ( V_2 -> V_39 == V_2 -> V_42 )
V_2 -> V_39 = NULL ;
V_37 += 1 ;
} else
break;
}
if ( V_33 == V_2 -> V_43 ) {
V_2 -> V_44 = F_11 ( V_36 , V_2 -> V_45 ) ;
V_38 = V_2 -> V_44 - V_36 ;
} else
V_38 = V_35 ;
F_19 ( L_2 ,
V_7 , V_32 , V_33 , V_33 - V_32 , V_37 , V_38 ) ;
F_20 ( V_2 , V_2 -> V_41 + V_36 , V_38 ) ;
* V_34 += V_38 ;
return V_37 ;
}
static int F_21 ( struct V_1 * V_2 , int V_7 , int V_8 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
V_49 = V_2 -> V_50 . V_48 ;
while ( V_49 ) {
V_47 = F_22 ( V_49 , struct V_46 , V_51 ) ;
if ( V_7 < V_47 -> V_7 )
V_49 = V_49 -> V_52 ;
else if ( V_7 > V_47 -> V_7 )
V_49 = V_49 -> V_53 ;
else if ( V_8 < V_47 -> V_8 )
V_49 = V_49 -> V_52 ;
else if ( V_8 > V_47 -> V_8 )
V_49 = V_49 -> V_53 ;
else
return 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , union V_54 * V_23 ,
int V_17 , int V_7 , int V_8 )
{
int V_55 ;
V_55 = F_24 ( V_2 , V_23 , V_17 , V_7 , V_8 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_55 == 0 )
if ( F_21 ( V_2 , V_7 , V_8 ) )
return 1 ;
return V_55 ;
}
static int F_25 ( struct V_1 * V_2 , int * V_49 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_7 , V_34 = 0 , V_32 , V_33 , V_12 , V_37 , V_60 ;
V_60 = 0 ;
V_7 = F_26 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_49 = V_7 ;
F_19 ( L_3 , V_7 ) ;
V_57 = F_27 ( V_2 , V_7 , 0 , V_2 -> V_41 , 0 ) ;
V_2 -> V_44 = 0 ;
if ( F_28 ( V_57 ) )
return F_29 ( V_57 ) ;
V_32 = 0 ;
F_30 (snod, &sleb->nodes, list) {
struct V_3 * V_4 ;
int V_61 , V_17 ;
F_13 ( V_59 -> type == V_15 ) ;
V_4 = V_59 -> V_62 ;
F_31 ( V_2 , F_32 ( V_2 , V_4 ) , & V_59 -> V_23 ) ;
V_17 = F_33 ( V_4 -> V_17 ) ;
V_61 = F_23 ( V_2 , & V_59 -> V_23 , V_17 , V_7 ,
V_59 -> V_8 ) ;
if ( V_61 < 0 ) {
F_34 ( V_57 ) ;
return V_61 ;
}
if ( V_61 ) {
if ( V_61 == 1 )
V_34 += F_11 ( V_59 -> V_9 , 8 ) ;
V_33 = V_59 -> V_8 ;
V_37 = F_17 ( V_2 , V_7 , V_32 , V_33 , & V_34 ) ;
if ( V_37 < 0 ) {
F_34 ( V_57 ) ;
return V_37 ;
}
V_60 += V_37 ;
V_32 = F_11 ( V_59 -> V_8 + V_59 -> V_9 , 8 ) ;
}
}
F_34 ( V_57 ) ;
V_2 -> V_44 = V_2 -> V_43 ;
V_33 = V_2 -> V_43 ;
V_37 = F_17 ( V_2 , V_7 , V_32 , V_33 , & V_34 ) ;
if ( V_37 < 0 )
return V_37 ;
V_60 += V_37 ;
if ( V_60 == 0 ) {
struct V_63 V_64 ;
F_19 ( L_4 , V_7 , V_60 ) ;
V_12 = F_35 ( V_2 , V_7 , & V_64 ) ;
if ( V_12 )
return V_12 ;
if ( V_64 . free == V_2 -> V_43 ) {
V_12 = F_36 ( V_2 , V_7 ,
V_2 -> V_43 - V_2 -> V_44 ,
V_34 , 0 , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
V_12 = F_36 ( V_2 , V_7 , V_2 -> V_43 - V_2 -> V_44 , V_34 ,
0 , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_37 ( V_2 , V_7 , V_2 -> V_41 , V_2 -> V_44 ,
V_65 ) ;
if ( V_12 )
return V_12 ;
F_19 ( L_4 , V_7 , V_60 ) ;
return V_60 ;
}
static int F_38 ( struct V_1 * V_2 , int V_66 )
{
int V_67 ;
V_66 -= ( V_2 -> V_43 - V_2 -> V_68 ) / V_2 -> V_69 ;
if ( V_66 < 0 )
V_66 = 0 ;
V_67 = V_2 -> V_43 / V_2 -> V_69 ;
return F_39 ( V_66 , V_67 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_66 )
{
int V_12 , V_70 , V_37 , * V_49 ;
F_19 ( L_5 , V_66 ) ;
V_2 -> V_71 = F_41 ( sizeof( int ) * ( V_2 -> V_72 . V_73 + 1 ) , V_74 ) ;
if ( ! V_2 -> V_71 )
return - V_75 ;
V_49 = V_2 -> V_71 ;
do {
F_13 ( V_49 < V_2 -> V_71 + sizeof( int ) * V_2 -> V_72 . V_73 ) ;
V_37 = F_25 ( V_2 , V_49 ) ;
if ( V_37 < 0 ) {
V_12 = V_37 ;
if ( V_12 != - V_76 ) {
F_42 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
return V_12 ;
}
if ( F_43 () ) {
F_44 ( L_6 ) ;
F_45 ( V_2 , & V_2 -> V_77 ) ;
F_46 ( V_2 ) ;
}
V_12 = 0 ;
break;
}
V_49 ++ ;
V_66 -= V_37 ;
V_70 = F_38 ( V_2 , V_66 ) ;
F_19 ( L_7 , V_66 ,
V_70 , V_2 -> V_78 ) ;
} while ( V_70 > V_2 -> V_78 );
* V_49 = - 1 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_42 , * V_10 ;
int V_7 , V_8 , V_9 , V_79 , V_80 , V_81 , V_82 , V_83 ;
int V_84 , V_85 , V_12 ;
V_42 = V_2 -> V_39 ;
if ( ! V_42 )
return 0 ;
V_7 = V_2 -> V_86 ;
V_81 = V_2 -> V_68 ;
V_80 = F_18 ( V_2 , V_2 -> V_87 ) ;
V_80 = F_11 ( V_80 , V_2 -> V_45 ) ;
V_82 = 0 ;
V_83 = V_80 ;
V_79 = F_18 ( V_2 , V_42 -> V_16 ) ;
if ( V_81 + V_79 > V_2 -> V_43 )
V_7 = - 1 ;
while ( 1 ) {
V_6 = V_42 ;
V_9 = F_18 ( V_2 , V_6 -> V_16 ) ;
if ( V_7 == - 1 ) {
if ( V_2 -> V_88 >= V_2 -> V_78 ) {
F_6 ( L_6 ) ;
return - V_76 ;
}
V_7 = V_2 -> V_89 [ V_2 -> V_88 ++ ] ;
V_81 = 0 ;
V_82 = 0 ;
V_83 = V_80 ;
}
V_8 = V_81 + V_82 ;
#ifdef F_9
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_9 = V_9 ;
#endif
V_10 = V_6 -> V_24 ;
if ( V_10 ) {
struct V_20 * V_21 ;
int V_11 ;
V_11 = V_6 -> V_25 ;
V_21 = & V_10 -> V_22 [ V_11 ] ;
V_21 -> V_7 = V_7 ;
V_21 -> V_8 = V_8 ;
V_21 -> V_9 = V_9 ;
} else {
V_2 -> V_26 . V_7 = V_7 ;
V_2 -> V_26 . V_8 = V_8 ;
V_2 -> V_26 . V_9 = V_9 ;
}
V_2 -> V_27 += F_11 ( V_9 , 8 ) ;
F_12 ( & V_2 -> V_28 ) ;
V_42 = V_6 -> V_42 ;
if ( V_42 == V_2 -> V_42 )
V_79 = 0 ;
else
V_79 = F_18 ( V_2 , V_42 -> V_16 ) ;
if ( V_2 -> V_45 == 1 ) {
V_81 += F_11 ( V_9 , 8 ) ;
if ( V_79 ) {
if ( V_81 + V_79 <= V_2 -> V_43 )
continue;
V_12 = F_48 ( V_2 , V_7 , 0 ,
V_2 -> V_43 - V_81 , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
V_7 = - 1 ;
continue;
}
V_12 = F_48 ( V_2 , V_7 ,
V_2 -> V_43 - V_81 , 0 , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
break;
}
V_84 = V_82 + V_9 ;
V_82 += F_11 ( V_9 , 8 ) ;
V_83 -= F_11 ( V_9 , 8 ) ;
if ( V_79 != 0 &&
V_81 + V_82 + V_79 <= V_2 -> V_43 &&
V_83 > 0 )
continue;
if ( V_83 <= 0 && V_79 &&
V_81 + V_82 + V_79 <= V_2 -> V_43 )
V_85 = V_80 ;
else
V_85 = F_11 ( V_84 , V_2 -> V_45 ) ;
V_81 += V_85 ;
if ( V_79 ) {
if ( V_81 + V_79 > V_2 -> V_43 ) {
V_12 = F_48 ( V_2 , V_7 ,
V_2 -> V_43 - V_81 , V_85 - V_82 ,
0 , 0 ) ;
if ( V_12 )
return V_12 ;
V_7 = - 1 ;
}
V_82 -= V_85 ;
if ( V_82 < 0 )
V_82 = 0 ;
V_83 = V_80 - V_82 ;
continue;
}
V_12 = F_48 ( V_2 , V_7 , V_2 -> V_43 - V_81 ,
V_85 - V_82 , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
break;
}
#ifdef F_9
V_2 -> V_90 -> V_91 = V_7 ;
V_2 -> V_90 -> V_92 = V_81 ;
#endif
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_93 , int V_66 )
{
int V_12 ;
if ( V_93 ) {
V_12 = F_40 ( V_2 , V_66 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_47 ( V_2 ) ;
return V_12 ;
}
static struct V_5 * F_50 ( struct V_5 * V_6 )
{
int V_11 , V_94 ;
if ( ! V_6 )
return NULL ;
while ( 1 ) {
if ( V_6 -> V_17 == 0 ) {
if ( F_14 ( V_6 ) )
return V_6 ;
return NULL ;
}
V_94 = 0 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_16 ; V_11 ++ ) {
struct V_20 * V_21 = & V_6 -> V_22 [ V_11 ] ;
if ( V_21 -> V_6 && F_14 ( V_21 -> V_6 ) ) {
V_6 = V_21 -> V_6 ;
V_94 = 1 ;
break;
}
}
if ( ! V_94 ) {
if ( F_14 ( V_6 ) )
return V_6 ;
return NULL ;
}
}
}
static struct V_5 * F_51 ( struct V_5 * V_6 )
{
int V_95 = V_6 -> V_25 + 1 ;
V_6 = V_6 -> V_24 ;
if ( ! V_6 )
return NULL ;
for (; V_95 < V_6 -> V_16 ; V_95 ++ ) {
struct V_20 * V_21 = & V_6 -> V_22 [ V_95 ] ;
if ( V_21 -> V_6 && F_14 ( V_21 -> V_6 ) )
return F_50 ( V_21 -> V_6 ) ;
}
return V_6 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_42 ;
int V_66 = 0 ;
V_2 -> V_42 = F_50 ( V_2 -> V_26 . V_6 ) ;
V_6 = V_2 -> V_39 = V_2 -> V_42 ;
if ( ! V_6 ) {
F_53 ( L_8 ) ;
return 0 ;
}
V_66 += 1 ;
while ( 1 ) {
F_13 ( ! F_15 ( V_29 , & V_6 -> V_30 ) ) ;
F_54 ( V_29 , & V_6 -> V_30 ) ;
V_6 -> V_96 = 0 ;
V_42 = F_51 ( V_6 ) ;
if ( ! V_42 ) {
V_6 -> V_42 = V_2 -> V_42 ;
break;
}
V_6 -> V_42 = V_42 ;
V_6 = V_42 ;
V_66 += 1 ;
}
F_53 ( L_9 , V_66 ) ;
F_13 ( V_66 == F_55 ( & V_2 -> V_28 ) ) ;
return V_66 ;
}
static int F_56 ( struct V_1 * V_2 , int V_66 )
{
int V_11 , V_97 , V_7 ;
V_2 -> V_78 = 0 ;
V_2 -> V_88 = 0 ;
V_97 = F_38 ( V_2 , V_66 ) ;
F_53 ( L_10 , V_97 ) ;
if ( ! V_97 )
return 0 ;
V_2 -> V_89 = F_41 ( V_97 * sizeof( int ) , V_74 ) ;
if ( ! V_2 -> V_89 )
return - V_75 ;
for ( V_11 = 0 ; V_11 < V_97 ; V_11 ++ ) {
V_7 = F_57 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_89 [ V_2 -> V_78 ++ ] = V_7 ;
F_53 ( L_3 , V_7 ) ;
}
if ( F_58 () )
return - V_76 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_11 , V_12 = 0 , V_7 , V_98 ;
for ( V_11 = V_2 -> V_88 ; V_11 < V_2 -> V_78 ; V_11 ++ ) {
V_7 = V_2 -> V_89 [ V_11 ] ;
F_53 ( L_3 , V_7 ) ;
V_98 = F_36 ( V_2 , V_7 , V_99 , V_99 , 0 ,
V_100 | V_101 , 0 ) ;
if ( ! V_12 )
V_12 = V_98 ;
}
return V_12 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_59 ( V_2 ) ;
F_42 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
return V_12 ;
}
int F_61 ( struct V_1 * V_2 , struct V_20 * V_26 )
{
int V_12 = 0 , V_66 ;
F_62 ( & V_2 -> V_102 ) ;
V_12 = F_63 ( V_2 , 1 ) ;
if ( V_12 )
goto V_103;
V_66 = F_52 ( V_2 ) ;
if ( V_66 != 0 ) {
int V_93 = 0 ;
V_12 = F_56 ( V_2 , V_66 ) ;
if ( V_12 == - V_76 )
V_93 = 1 ;
else if ( V_12 )
goto V_104;
V_12 = F_49 ( V_2 , V_93 , V_66 ) ;
if ( V_12 )
goto V_104;
F_13 ( F_55 ( & V_2 -> V_28 ) == 0 ) ;
V_12 = F_59 ( V_2 ) ;
if ( V_12 )
goto V_103;
}
F_64 ( V_2 ) ;
memcpy ( V_26 , & V_2 -> V_26 , sizeof( struct V_20 ) ) ;
V_12 = F_65 ( V_2 ) ;
if ( V_12 )
goto V_103;
F_66 ( & V_2 -> V_105 ) ;
F_13 ( V_2 -> V_77 . V_106 == F_67 ( V_2 ) ) ;
V_2 -> V_77 . V_107 = V_2 -> V_27 ;
V_2 -> V_77 . V_108 = 0 ;
V_2 -> V_77 . V_106 = F_67 ( V_2 ) ;
F_68 ( & V_2 -> V_105 ) ;
F_69 ( & V_2 -> V_102 ) ;
F_53 ( L_11 , V_2 -> V_72 . V_73 ) ;
F_53 ( L_12 , V_2 -> V_27 ) ;
return V_12 ;
V_104:
F_60 ( V_2 ) ;
V_103:
F_69 ( & V_2 -> V_102 ) ;
return V_12 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 , * V_42 ;
int V_11 , V_7 , V_8 , V_9 , V_79 , V_80 , V_81 , V_82 ;
int V_83 , V_84 , V_12 , V_109 = 0 ;
V_42 = V_2 -> V_39 ;
if ( ! V_42 )
return 0 ;
V_7 = V_2 -> V_86 ;
V_81 = V_2 -> V_68 ;
V_80 = F_11 ( V_2 -> V_69 , V_2 -> V_45 ) ;
V_82 = 0 ;
V_83 = V_80 ;
V_79 = F_18 ( V_2 , V_42 -> V_16 ) ;
if ( V_81 + V_79 > V_2 -> V_43 ) {
V_12 = F_48 ( V_2 , V_7 , V_99 , 0 , 0 ,
V_101 ) ;
if ( V_12 )
return V_12 ;
V_7 = - 1 ;
}
while ( 1 ) {
F_71 () ;
V_6 = V_42 ;
V_4 = V_2 -> V_110 + V_82 ;
V_4 -> V_13 . V_14 = V_15 ;
V_4 -> V_16 = F_2 ( V_6 -> V_16 ) ;
V_4 -> V_17 = F_2 ( V_6 -> V_17 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_16 ; V_11 ++ ) {
struct V_18 * V_19 = F_3 ( V_2 , V_4 , V_11 ) ;
struct V_20 * V_21 = & V_6 -> V_22 [ V_11 ] ;
F_4 ( V_2 , & V_21 -> V_23 , & V_19 -> V_23 ) ;
V_19 -> V_7 = F_5 ( V_21 -> V_7 ) ;
V_19 -> V_8 = F_5 ( V_21 -> V_8 ) ;
V_19 -> V_9 = F_5 ( V_21 -> V_9 ) ;
if ( ! V_21 -> V_7 || ! V_21 -> V_9 ) {
F_6 ( L_1 ) ;
F_7 ( V_2 , V_6 ) ;
if ( V_21 -> V_6 )
F_7 ( V_2 , V_21 -> V_6 ) ;
}
}
V_9 = F_18 ( V_2 , V_6 -> V_16 ) ;
F_8 ( V_2 , V_4 , V_9 , 0 ) ;
if ( V_7 == - 1 ) {
V_7 = V_2 -> V_89 [ V_109 ++ ] ;
V_81 = 0 ;
V_82 = 0 ;
V_83 = V_80 ;
}
V_8 = V_81 + V_82 ;
#ifdef F_9
if ( V_7 != V_6 -> V_7 || V_8 != V_6 -> V_8 ||
V_9 != V_6 -> V_9 ) {
F_6 ( L_13 ) ;
return - V_111 ;
}
#endif
V_42 = V_6 -> V_42 ;
F_13 ( F_14 ( V_6 ) ) ;
F_13 ( F_15 ( V_29 , & V_6 -> V_30 ) ) ;
F_72 ( V_31 , & V_6 -> V_30 ) ;
F_73 () ;
F_72 ( V_29 , & V_6 -> V_30 ) ;
F_74 () ;
V_84 = V_82 + V_9 ;
V_82 += F_11 ( V_9 , 8 ) ;
V_83 -= F_11 ( V_9 , 8 ) ;
if ( V_42 == V_2 -> V_42 )
V_79 = 0 ;
else
V_79 = F_18 ( V_2 , V_42 -> V_16 ) ;
if ( V_2 -> V_45 == 1 ) {
V_12 = F_75 ( V_2 , V_7 , V_2 -> V_110 , V_81 ,
V_84 , V_65 ) ;
if ( V_12 )
return V_12 ;
V_81 += F_11 ( V_84 , 8 ) ;
if ( V_79 ) {
V_82 = 0 ;
V_83 = V_80 ;
if ( V_81 + V_79 > V_2 -> V_43 ) {
V_12 = F_48 ( V_2 , V_7 ,
V_99 , 0 , 0 , V_101 ) ;
if ( V_12 )
return V_12 ;
V_7 = - 1 ;
}
continue;
}
} else {
int V_85 , V_112 = V_81 + V_82 + V_79 ;
if ( V_79 && V_112 <= V_2 -> V_43 ) {
if ( V_83 > 0 )
continue;
else
V_85 = V_80 ;
} else {
V_84 = F_11 ( V_84 , 8 ) ;
V_85 = F_11 ( V_84 , V_2 -> V_45 ) ;
F_20 ( V_2 , V_2 -> V_110 + V_84 , V_85 - V_84 ) ;
}
V_12 = F_75 ( V_2 , V_7 , V_2 -> V_110 , V_81 ,
V_85 , V_65 ) ;
if ( V_12 )
return V_12 ;
V_81 += V_85 ;
if ( V_79 ) {
if ( V_112 > V_2 -> V_43 ) {
V_12 = F_48 ( V_2 , V_7 ,
V_99 , 0 , 0 , V_101 ) ;
if ( V_12 )
return V_12 ;
V_7 = - 1 ;
}
V_82 -= V_85 ;
if ( V_82 < 0 )
V_82 = 0 ;
V_83 = V_80 - V_82 ;
memmove ( V_2 -> V_110 , V_2 -> V_110 + V_85 , V_82 ) ;
continue;
}
}
break;
}
#ifdef F_9
if ( V_7 != V_2 -> V_90 -> V_91 ||
V_81 != V_2 -> V_90 -> V_92 ) {
F_6 ( L_14 ) ;
return - V_111 ;
}
#endif
V_2 -> V_86 = V_7 ;
V_2 -> V_68 = V_81 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_42 ;
V_42 = V_2 -> V_42 ;
do {
V_6 = V_42 ;
V_42 = V_6 -> V_42 ;
if ( F_15 ( V_113 , & V_6 -> V_30 ) )
F_42 ( V_6 ) ;
else {
V_6 -> V_42 = NULL ;
F_77 ( & V_2 -> V_114 ) ;
F_77 ( & V_115 ) ;
}
} while ( V_42 != V_2 -> V_42 );
}
static int F_78 ( struct V_1 * V_2 )
{
int * V_49 , V_12 ;
if ( ! V_2 -> V_71 )
return 0 ;
F_53 ( L_15 ) ;
for ( V_49 = V_2 -> V_71 ; * V_49 != - 1 ; V_49 ++ ) {
V_12 = F_36 ( V_2 , * V_49 , V_99 , V_99 , 0 ,
V_101 , 0 ) ;
if ( V_12 )
return V_12 ;
}
F_42 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_42 )
return 0 ;
V_12 = F_78 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_70 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_62 ( & V_2 -> V_102 ) ;
F_53 ( L_16 , V_2 -> V_26 . V_6 -> V_17 + 1 ) ;
F_76 ( V_2 ) ;
V_2 -> V_42 = NULL ;
F_42 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
F_69 ( & V_2 -> V_102 ) ;
return 0 ;
}
