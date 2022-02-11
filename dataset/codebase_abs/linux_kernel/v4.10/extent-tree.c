static T_1 int
F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return V_2 -> V_3 == V_4 ||
V_2 -> V_3 == V_5 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_6 )
{
return ( V_2 -> V_7 & V_6 ) == V_6 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_8 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( & V_2 -> V_8 ) ) {
F_8 ( V_2 -> V_9 > 0 ) ;
F_8 ( V_2 -> V_10 > 0 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 ) ;
}
}
static int F_10 ( struct V_12 * V_13 ,
struct V_1 * V_14 )
{
struct V_15 * * V_16 ;
struct V_15 * V_17 = NULL ;
struct V_1 * V_2 ;
F_11 ( & V_13 -> V_18 ) ;
V_16 = & V_13 -> V_19 . V_15 ;
while ( * V_16 ) {
V_17 = * V_16 ;
V_2 = F_12 ( V_17 , struct V_1 ,
V_20 ) ;
if ( V_14 -> V_21 . V_22 < V_2 -> V_21 . V_22 ) {
V_16 = & ( * V_16 ) -> V_23 ;
} else if ( V_14 -> V_21 . V_22 > V_2 -> V_21 . V_22 ) {
V_16 = & ( * V_16 ) -> V_24 ;
} else {
F_13 ( & V_13 -> V_18 ) ;
return - V_25 ;
}
}
F_14 ( & V_14 -> V_20 , V_17 , V_16 ) ;
F_15 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
if ( V_13 -> V_26 > V_14 -> V_21 . V_22 )
V_13 -> V_26 = V_14 -> V_21 . V_22 ;
F_13 ( & V_13 -> V_18 ) ;
return 0 ;
}
static struct V_1 *
F_16 ( struct V_12 * V_13 , T_2 V_27 ,
int V_28 )
{
struct V_1 * V_2 , * V_29 = NULL ;
struct V_15 * V_30 ;
T_2 V_31 , V_32 ;
F_11 ( & V_13 -> V_18 ) ;
V_30 = V_13 -> V_19 . V_15 ;
while ( V_30 ) {
V_2 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
V_31 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - 1 ;
V_32 = V_2 -> V_21 . V_22 ;
if ( V_27 < V_32 ) {
if ( ! V_28 && ( ! V_29 || V_32 < V_29 -> V_21 . V_22 ) )
V_29 = V_2 ;
V_30 = V_30 -> V_23 ;
} else if ( V_27 > V_32 ) {
if ( V_28 && V_27 <= V_31 ) {
V_29 = V_2 ;
break;
}
V_30 = V_30 -> V_24 ;
} else {
V_29 = V_2 ;
break;
}
}
if ( V_29 ) {
F_4 ( V_29 ) ;
if ( V_27 == 0 && V_13 -> V_26 > V_29 -> V_21 . V_22 )
V_13 -> V_26 = V_29 -> V_21 . V_22 ;
}
F_13 ( & V_13 -> V_18 ) ;
return V_29 ;
}
static int F_17 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_35 )
{
T_2 V_31 = V_32 + V_35 - 1 ;
F_18 ( & V_34 -> V_36 [ 0 ] ,
V_32 , V_31 , V_37 ) ;
F_18 ( & V_34 -> V_36 [ 1 ] ,
V_32 , V_31 , V_37 ) ;
return 0 ;
}
static void F_19 ( struct V_12 * V_34 ,
struct V_1 * V_2 )
{
T_2 V_32 , V_31 ;
V_32 = V_2 -> V_21 . V_22 ;
V_31 = V_32 + V_2 -> V_21 . V_33 - 1 ;
F_20 ( & V_34 -> V_36 [ 0 ] ,
V_32 , V_31 , V_37 ) ;
F_20 ( & V_34 -> V_36 [ 1 ] ,
V_32 , V_31 , V_37 ) ;
}
static int F_21 ( struct V_12 * V_34 ,
struct V_1 * V_2 )
{
T_2 V_27 ;
T_2 * V_38 ;
int V_39 ;
int V_40 , V_41 , V_29 ;
if ( V_2 -> V_21 . V_22 < V_42 ) {
V_39 = V_42 - V_2 -> V_21 . V_22 ;
V_2 -> V_43 += V_39 ;
V_29 = F_17 ( V_34 , V_2 -> V_21 . V_22 ,
V_39 ) ;
if ( V_29 )
return V_29 ;
}
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ ) {
V_27 = F_22 ( V_40 ) ;
V_29 = F_23 ( V_34 , V_2 -> V_21 . V_22 ,
V_27 , 0 , & V_38 , & V_41 , & V_39 ) ;
if ( V_29 )
return V_29 ;
while ( V_41 -- ) {
T_2 V_32 , V_45 ;
if ( V_38 [ V_41 ] > V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 )
continue;
if ( V_38 [ V_41 ] + V_39 <= V_2 -> V_21 . V_22 )
continue;
V_32 = V_38 [ V_41 ] ;
if ( V_32 < V_2 -> V_21 . V_22 ) {
V_32 = V_2 -> V_21 . V_22 ;
V_45 = ( V_38 [ V_41 ] + V_39 ) - V_32 ;
} else {
V_45 = F_24 ( T_2 , V_39 ,
V_2 -> V_21 . V_22 +
V_2 -> V_21 . V_33 - V_32 ) ;
}
V_2 -> V_43 += V_45 ;
V_29 = F_17 ( V_34 , V_32 , V_45 ) ;
if ( V_29 ) {
F_9 ( V_38 ) ;
return V_29 ;
}
}
F_9 ( V_38 ) ;
}
return 0 ;
}
static struct V_46 *
F_25 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
F_11 ( & V_2 -> V_48 ) ;
if ( ! V_2 -> V_49 ) {
F_13 ( & V_2 -> V_48 ) ;
return NULL ;
}
V_47 = V_2 -> V_49 ;
F_5 ( & V_47 -> V_8 ) ;
F_13 ( & V_2 -> V_48 ) ;
return V_47 ;
}
static void F_26 ( struct V_46 * V_47 )
{
if ( F_7 ( & V_47 -> V_8 ) )
F_9 ( V_47 ) ;
}
static void F_27 ( struct V_1 * V_14 )
{
struct V_12 * V_34 = V_14 -> V_34 ;
T_2 V_32 = V_14 -> V_21 . V_22 ;
T_2 V_45 = V_14 -> V_21 . V_33 ;
T_2 V_50 = V_14 -> V_7 & V_51 ?
V_34 -> V_52 : V_34 -> V_53 ;
T_2 V_54 = V_50 << 1 ;
while ( V_45 > V_50 ) {
F_28 ( V_14 , V_32 , V_50 ) ;
V_32 += V_54 ;
if ( V_45 < V_54 )
V_45 = 0 ;
else
V_45 -= V_54 ;
}
}
T_2 F_29 ( struct V_1 * V_14 ,
struct V_12 * V_13 , T_2 V_32 , T_2 V_31 )
{
T_2 V_55 , V_56 , V_57 , V_58 = 0 ;
int V_29 ;
while ( V_32 < V_31 ) {
V_29 = F_30 ( V_13 -> V_59 , V_32 ,
& V_55 , & V_56 ,
V_60 | V_37 ,
NULL ) ;
if ( V_29 )
break;
if ( V_55 <= V_32 ) {
V_32 = V_56 + 1 ;
} else if ( V_55 > V_32 && V_55 < V_31 ) {
V_57 = V_55 - V_32 ;
V_58 += V_57 ;
V_29 = F_31 ( V_14 , V_32 ,
V_57 ) ;
F_32 ( V_29 ) ;
V_32 = V_56 + 1 ;
} else {
break;
}
}
if ( V_32 < V_31 ) {
V_57 = V_31 - V_32 ;
V_58 += V_57 ;
V_29 = F_31 ( V_14 , V_32 , V_57 ) ;
F_32 ( V_29 ) ;
}
return V_58 ;
}
static int F_33 ( struct V_46 * V_49 )
{
struct V_1 * V_14 = V_49 -> V_14 ;
struct V_12 * V_34 = V_14 -> V_34 ;
struct V_61 * V_62 = V_34 -> V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 V_21 ;
T_2 V_68 = 0 ;
T_2 V_69 = 0 ;
T_3 V_70 ;
int V_29 ;
bool V_71 = true ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_69 = F_35 ( T_2 , V_14 -> V_21 . V_22 , V_42 ) ;
#ifdef F_36
if ( F_37 ( V_14 ) )
V_71 = false ;
#endif
V_64 -> V_73 = 1 ;
V_64 -> V_74 = 1 ;
V_64 -> V_75 = V_76 ;
V_21 . V_22 = V_69 ;
V_21 . V_33 = 0 ;
V_21 . type = V_77 ;
V_78:
V_29 = F_38 ( NULL , V_62 , & V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_79;
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_39 ( V_66 ) ;
while ( 1 ) {
if ( F_40 ( V_34 ) > 1 ) {
V_69 = ( T_2 ) - 1 ;
break;
}
if ( V_64 -> V_81 [ 0 ] < V_70 ) {
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
} else {
V_29 = F_42 ( V_64 , 0 , & V_21 ) ;
if ( V_29 )
break;
if ( F_43 () ||
F_44 ( & V_34 -> V_82 ) ) {
if ( V_71 )
V_49 -> V_83 = V_69 ;
F_45 ( V_64 ) ;
F_46 ( & V_34 -> V_82 ) ;
F_47 ( & V_49 -> V_84 ) ;
F_48 () ;
F_49 ( & V_49 -> V_84 ) ;
F_50 ( & V_34 -> V_82 ) ;
goto V_78;
}
V_29 = F_51 ( V_62 , V_64 ) ;
if ( V_29 < 0 )
goto V_79;
if ( V_29 )
break;
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_39 ( V_66 ) ;
continue;
}
if ( V_21 . V_22 < V_69 ) {
V_21 . V_22 = V_69 ;
V_21 . V_33 = 0 ;
V_21 . type = V_77 ;
if ( V_71 )
V_49 -> V_83 = V_69 ;
F_45 ( V_64 ) ;
goto V_78;
}
if ( V_21 . V_22 < V_14 -> V_21 . V_22 ) {
V_64 -> V_81 [ 0 ] ++ ;
continue;
}
if ( V_21 . V_22 >= V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 )
break;
if ( V_21 . type == V_77 ||
V_21 . type == V_85 ) {
V_68 += F_29 ( V_14 ,
V_34 , V_69 ,
V_21 . V_22 ) ;
if ( V_21 . type == V_85 )
V_69 = V_21 . V_22 +
V_34 -> V_52 ;
else
V_69 = V_21 . V_22 + V_21 . V_33 ;
if ( V_68 > V_86 ) {
V_68 = 0 ;
if ( V_71 )
F_52 ( & V_49 -> V_87 ) ;
}
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_29 = 0 ;
V_68 += F_29 ( V_14 , V_34 , V_69 ,
V_14 -> V_21 . V_22 +
V_14 -> V_21 . V_33 ) ;
V_49 -> V_83 = ( T_2 ) - 1 ;
V_79:
F_53 ( V_64 ) ;
return V_29 ;
}
static T_1 void F_54 ( struct V_88 * V_89 )
{
struct V_1 * V_14 ;
struct V_12 * V_34 ;
struct V_46 * V_49 ;
struct V_61 * V_62 ;
int V_29 ;
V_49 = F_55 ( V_89 , struct V_46 , V_89 ) ;
V_14 = V_49 -> V_14 ;
V_34 = V_14 -> V_34 ;
V_62 = V_34 -> V_62 ;
F_49 ( & V_49 -> V_84 ) ;
F_50 ( & V_34 -> V_82 ) ;
if ( F_56 ( V_34 , V_90 ) )
V_29 = F_57 ( V_49 ) ;
else
V_29 = F_33 ( V_49 ) ;
F_11 ( & V_14 -> V_48 ) ;
V_14 -> V_49 = NULL ;
V_14 -> V_3 = V_29 ? V_5 : V_4 ;
F_13 ( & V_14 -> V_48 ) ;
#ifdef F_36
if ( F_37 ( V_14 ) ) {
T_2 V_91 ;
F_11 ( & V_14 -> V_92 -> V_48 ) ;
F_11 ( & V_14 -> V_48 ) ;
V_91 = V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_93 ) ;
V_14 -> V_92 -> V_91 += V_91 >> 1 ;
F_13 ( & V_14 -> V_48 ) ;
F_13 ( & V_14 -> V_92 -> V_48 ) ;
F_27 ( V_14 ) ;
}
#endif
V_49 -> V_83 = ( T_2 ) - 1 ;
F_46 ( & V_34 -> V_82 ) ;
F_19 ( V_34 , V_14 ) ;
F_47 ( & V_49 -> V_84 ) ;
F_52 ( & V_49 -> V_87 ) ;
F_26 ( V_49 ) ;
F_6 ( V_14 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
int V_94 )
{
F_60 ( V_87 ) ;
struct V_12 * V_34 = V_2 -> V_34 ;
struct V_46 * V_49 ;
int V_29 = 0 ;
V_49 = F_61 ( sizeof( * V_49 ) , V_95 ) ;
if ( ! V_49 )
return - V_72 ;
F_62 ( & V_49 -> V_96 ) ;
F_63 ( & V_49 -> V_84 ) ;
F_64 ( & V_49 -> V_87 ) ;
V_49 -> V_14 = V_2 ;
V_49 -> V_83 = V_2 -> V_21 . V_22 ;
F_65 ( & V_49 -> V_8 , 1 ) ;
F_66 ( & V_49 -> V_89 , V_97 ,
F_54 , NULL , NULL ) ;
F_11 ( & V_2 -> V_48 ) ;
while ( V_2 -> V_3 == V_98 ) {
struct V_46 * V_47 ;
V_47 = V_2 -> V_49 ;
F_5 ( & V_47 -> V_8 ) ;
F_67 ( & V_47 -> V_87 , & V_87 , V_99 ) ;
F_13 ( & V_2 -> V_48 ) ;
F_68 () ;
F_69 ( & V_47 -> V_87 , & V_87 ) ;
F_26 ( V_47 ) ;
F_11 ( & V_2 -> V_48 ) ;
}
if ( V_2 -> V_3 != V_100 ) {
F_13 ( & V_2 -> V_48 ) ;
F_9 ( V_49 ) ;
return 0 ;
}
F_8 ( V_2 -> V_49 ) ;
V_2 -> V_49 = V_49 ;
V_2 -> V_3 = V_98 ;
F_13 ( & V_2 -> V_48 ) ;
if ( V_34 -> V_101 & V_102 ) {
F_49 ( & V_49 -> V_84 ) ;
V_29 = F_70 ( V_34 , V_2 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_29 == 1 ) {
V_2 -> V_49 = NULL ;
V_2 -> V_3 = V_4 ;
V_2 -> V_103 = ( T_2 ) - 1 ;
V_49 -> V_83 = ( T_2 ) - 1 ;
} else {
if ( V_94 ) {
V_2 -> V_49 = NULL ;
V_2 -> V_3 = V_100 ;
} else {
V_2 -> V_3 = V_104 ;
V_2 -> V_105 = 1 ;
}
}
F_13 ( & V_2 -> V_48 ) ;
#ifdef F_36
if ( V_29 == 1 &&
F_37 ( V_2 ) ) {
T_2 V_91 ;
F_11 ( & V_2 -> V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
V_91 = V_2 -> V_21 . V_33 -
F_58 ( & V_2 -> V_93 ) ;
V_2 -> V_92 -> V_91 += V_91 >> 1 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
F_27 ( V_2 ) ;
}
#endif
F_47 ( & V_49 -> V_84 ) ;
F_52 ( & V_49 -> V_87 ) ;
if ( V_29 == 1 ) {
F_26 ( V_49 ) ;
F_19 ( V_34 , V_2 ) ;
return 0 ;
}
} else {
F_11 ( & V_2 -> V_48 ) ;
if ( V_94 ) {
V_2 -> V_49 = NULL ;
V_2 -> V_3 = V_100 ;
} else {
V_2 -> V_3 = V_104 ;
V_2 -> V_105 = 1 ;
}
F_13 ( & V_2 -> V_48 ) ;
F_52 ( & V_49 -> V_87 ) ;
}
if ( V_94 ) {
F_26 ( V_49 ) ;
return 0 ;
}
F_71 ( & V_34 -> V_82 ) ;
F_5 ( & V_49 -> V_8 ) ;
F_72 ( & V_49 -> V_96 , & V_34 -> V_106 ) ;
F_73 ( & V_34 -> V_82 ) ;
F_4 ( V_2 ) ;
F_74 ( V_34 -> V_107 , & V_49 -> V_89 ) ;
return V_29 ;
}
static struct V_1 *
F_75 ( struct V_12 * V_13 , T_2 V_27 )
{
return F_16 ( V_13 , V_27 , 0 ) ;
}
struct V_1 * F_76 (
struct V_12 * V_13 ,
T_2 V_27 )
{
return F_16 ( V_13 , V_27 , 1 ) ;
}
static struct V_108 * F_77 ( struct V_12 * V_13 ,
T_2 V_7 )
{
struct V_109 * V_110 = & V_13 -> V_92 ;
struct V_108 * V_111 ;
V_7 &= V_112 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_111 -> V_7 & V_7 ) {
F_80 () ;
return V_111 ;
}
}
F_80 () ;
return NULL ;
}
void F_81 ( struct V_12 * V_13 )
{
struct V_109 * V_110 = & V_13 -> V_92 ;
struct V_108 * V_111 ;
F_78 () ;
F_79 (found, head, list)
V_111 -> V_113 = 0 ;
F_80 () ;
}
int F_82 ( struct V_12 * V_34 , T_2 V_32 , T_2 V_45 )
{
int V_29 ;
struct V_67 V_21 ;
struct V_63 * V_64 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_21 . V_22 = V_32 ;
V_21 . V_33 = V_45 ;
V_21 . type = V_77 ;
V_29 = F_38 ( NULL , V_34 -> V_62 , & V_21 , V_64 , 0 , 0 ) ;
F_53 ( V_64 ) ;
return V_29 ;
}
int F_83 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_27 ,
T_2 V_33 , int V_116 , T_2 * V_117 , T_2 * V_7 )
{
struct V_118 * V_110 ;
struct V_119 * V_120 ;
struct V_63 * V_64 ;
struct V_121 * V_122 ;
struct V_65 * V_66 ;
struct V_67 V_21 ;
T_3 V_123 ;
T_2 V_124 ;
T_2 V_125 ;
int V_29 ;
if ( V_116 && ! F_84 ( V_34 , V_126 ) ) {
V_33 = V_34 -> V_52 ;
V_116 = 0 ;
}
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
if ( ! V_115 ) {
V_64 -> V_73 = 1 ;
V_64 -> V_74 = 1 ;
}
V_127:
V_21 . V_22 = V_27 ;
V_21 . V_33 = V_33 ;
if ( V_116 )
V_21 . type = V_85 ;
else
V_21 . type = V_77 ;
V_29 = F_38 ( V_115 , V_34 -> V_62 , & V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_128;
if ( V_29 > 0 && V_116 && V_21 . type == V_85 ) {
if ( V_64 -> V_81 [ 0 ] ) {
V_64 -> V_81 [ 0 ] -- ;
F_41 ( V_64 -> V_80 [ 0 ] , & V_21 ,
V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_34 -> V_52 )
V_29 = 0 ;
}
}
if ( V_29 == 0 ) {
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
if ( V_123 >= sizeof( * V_122 ) ) {
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_121 ) ;
V_124 = F_87 ( V_66 , V_122 ) ;
V_125 = F_88 ( V_66 , V_122 ) ;
} else {
#ifdef F_89
struct V_129 * V_130 ;
F_32 ( V_123 != sizeof( * V_130 ) ) ;
V_130 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_129 ) ;
V_124 = F_90 ( V_66 , V_130 ) ;
V_125 = V_131 ;
#else
F_91 () ;
#endif
}
F_32 ( V_124 == 0 ) ;
} else {
V_124 = 0 ;
V_125 = 0 ;
V_29 = 0 ;
}
if ( ! V_115 )
goto V_79;
V_120 = & V_115 -> V_132 -> V_120 ;
F_11 ( & V_120 -> V_48 ) ;
V_110 = F_92 ( V_115 , V_27 ) ;
if ( V_110 ) {
if ( ! F_93 ( & V_110 -> V_84 ) ) {
F_5 ( & V_110 -> V_133 . V_117 ) ;
F_13 ( & V_120 -> V_48 ) ;
F_45 ( V_64 ) ;
F_49 ( & V_110 -> V_84 ) ;
F_47 ( & V_110 -> V_84 ) ;
F_94 ( & V_110 -> V_133 ) ;
goto V_127;
}
F_11 ( & V_110 -> V_48 ) ;
if ( V_110 -> V_134 && V_110 -> V_134 -> V_135 )
V_125 |= V_110 -> V_134 -> V_136 ;
else
F_32 ( V_124 == 0 ) ;
V_124 += V_110 -> V_133 . V_137 ;
F_13 ( & V_110 -> V_48 ) ;
F_47 ( & V_110 -> V_84 ) ;
}
F_13 ( & V_120 -> V_48 ) ;
V_79:
F_8 ( V_124 == 0 ) ;
if ( V_117 )
* V_117 = V_124 ;
if ( V_7 )
* V_7 = V_125 ;
V_128:
F_53 ( V_64 ) ;
return V_29 ;
}
static int F_95 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_139 , T_3 V_140 )
{
struct V_121 * V_93 ;
struct V_129 * V_130 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_65 * V_66 ;
struct V_67 V_21 ;
struct V_67 V_145 ;
T_3 V_146 = sizeof( * V_93 ) ;
T_2 V_117 ;
int V_29 ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_32 ( F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) != sizeof( * V_130 ) ) ;
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
V_130 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_129 ) ;
V_117 = F_90 ( V_66 , V_130 ) ;
if ( V_139 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_64 -> V_81 [ 0 ] >= F_39 ( V_66 ) ) {
V_29 = F_51 ( V_138 , V_64 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 > 0 ) ;
V_66 = V_64 -> V_80 [ 0 ] ;
}
F_41 ( V_66 , & V_145 ,
V_64 -> V_81 [ 0 ] ) ;
F_32 ( V_21 . V_22 != V_145 . V_22 ) ;
if ( V_145 . type != V_147 ) {
V_64 -> V_81 [ 0 ] ++ ;
continue;
}
V_142 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_141 ) ;
V_139 = F_96 ( V_66 , V_142 ) ;
break;
}
}
F_45 ( V_64 ) ;
if ( V_139 < V_148 )
V_146 += sizeof( * V_144 ) ;
V_146 -= sizeof( * V_130 ) ;
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 ,
V_146 + V_140 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 ) ;
F_97 ( V_138 -> V_34 , V_64 , V_146 ) ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_93 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
F_98 ( V_66 , V_93 , V_117 ) ;
F_99 ( V_66 , V_93 , 0 ) ;
if ( V_139 < V_148 ) {
F_100 ( V_66 , V_93 ,
V_149 |
V_131 ) ;
V_144 = (struct V_143 * ) ( V_93 + 1 ) ;
F_101 ( V_66 , ( unsigned long ) V_144 , sizeof( * V_144 ) ) ;
F_102 ( V_66 , V_144 , ( int ) V_139 ) ;
} else {
F_100 ( V_66 , V_93 , V_150 ) ;
}
F_103 ( V_66 ) ;
return 0 ;
}
static T_2 F_104 ( T_2 V_151 , T_2 V_139 , T_2 V_33 )
{
T_3 V_152 = ~ ( T_3 ) 0 ;
T_3 V_153 = ~ ( T_3 ) 0 ;
T_4 V_154 ;
V_154 = F_105 ( V_151 ) ;
V_152 = F_106 ( V_152 , & V_154 , sizeof( V_154 ) ) ;
V_154 = F_105 ( V_139 ) ;
V_153 = F_106 ( V_153 , & V_154 , sizeof( V_154 ) ) ;
V_154 = F_105 ( V_33 ) ;
V_153 = F_106 ( V_153 , & V_154 , sizeof( V_154 ) ) ;
return ( ( T_2 ) V_152 << 31 ) ^ ( T_2 ) V_153 ;
}
static T_2 F_107 ( struct V_65 * V_66 ,
struct V_155 * V_156 )
{
return F_104 ( F_108 ( V_66 , V_156 ) ,
F_109 ( V_66 , V_156 ) ,
F_110 ( V_66 , V_156 ) ) ;
}
static int F_111 ( struct V_65 * V_66 ,
struct V_155 * V_156 ,
T_2 V_151 , T_2 V_139 , T_2 V_33 )
{
if ( F_108 ( V_66 , V_156 ) != V_151 ||
F_109 ( V_66 , V_156 ) != V_139 ||
F_110 ( V_66 , V_156 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_112 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 ,
T_2 V_139 , T_2 V_33 )
{
struct V_67 V_21 ;
struct V_155 * V_156 ;
struct V_65 * V_66 ;
T_3 V_70 ;
int V_29 ;
int V_157 ;
int V_158 = - V_159 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_160 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_161 ;
V_21 . V_33 = F_104 ( V_151 ,
V_139 , V_33 ) ;
}
V_162:
V_157 = 0 ;
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_163;
}
if ( V_17 ) {
if ( ! V_29 )
return 0 ;
#ifdef F_89
V_21 . type = V_147 ;
F_45 ( V_64 ) ;
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_163;
}
if ( ! V_29 )
return 0 ;
#endif
goto V_163;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_39 ( V_66 ) ;
while ( 1 ) {
if ( V_64 -> V_81 [ 0 ] >= V_70 ) {
V_29 = F_51 ( V_138 , V_64 ) ;
if ( V_29 < 0 )
V_158 = V_29 ;
if ( V_29 )
goto V_163;
V_66 = V_64 -> V_80 [ 0 ] ;
V_70 = F_39 ( V_66 ) ;
V_157 = 1 ;
}
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 ||
V_21 . type != V_161 )
goto V_163;
V_156 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_155 ) ;
if ( F_111 ( V_66 , V_156 , V_151 ,
V_139 , V_33 ) ) {
if ( V_157 ) {
F_45 ( V_64 ) ;
goto V_162;
}
V_158 = 0 ;
break;
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_163:
return V_158 ;
}
static T_1 int F_113 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 , T_2 V_139 ,
T_2 V_33 , int V_164 )
{
struct V_67 V_21 ;
struct V_65 * V_66 ;
T_3 V_57 ;
T_3 V_124 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_160 ;
V_21 . V_33 = V_17 ;
V_57 = sizeof( struct V_165 ) ;
} else {
V_21 . type = V_161 ;
V_21 . V_33 = F_104 ( V_151 ,
V_139 , V_33 ) ;
V_57 = sizeof( struct V_155 ) ;
}
V_29 = F_114 ( V_115 , V_138 , V_64 , & V_21 , V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_163;
V_66 = V_64 -> V_80 [ 0 ] ;
if ( V_17 ) {
struct V_165 * V_156 ;
V_156 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_165 ) ;
if ( V_29 == 0 ) {
F_115 ( V_66 , V_156 , V_164 ) ;
} else {
V_124 = F_116 ( V_66 , V_156 ) ;
V_124 += V_164 ;
F_115 ( V_66 , V_156 , V_124 ) ;
}
} else {
struct V_155 * V_156 ;
while ( V_29 == - V_25 ) {
V_156 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_155 ) ;
if ( F_111 ( V_66 , V_156 , V_151 ,
V_139 , V_33 ) )
break;
F_45 ( V_64 ) ;
V_21 . V_33 ++ ;
V_29 = F_114 ( V_115 , V_138 , V_64 , & V_21 ,
V_57 ) ;
if ( V_29 && V_29 != - V_25 )
goto V_163;
V_66 = V_64 -> V_80 [ 0 ] ;
}
V_156 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_155 ) ;
if ( V_29 == 0 ) {
F_117 ( V_66 , V_156 ,
V_151 ) ;
F_118 ( V_66 , V_156 , V_139 ) ;
F_119 ( V_66 , V_156 , V_33 ) ;
F_120 ( V_66 , V_156 , V_164 ) ;
} else {
V_124 = F_121 ( V_66 , V_156 ) ;
V_124 += V_164 ;
F_120 ( V_66 , V_156 , V_124 ) ;
}
}
F_103 ( V_66 ) ;
V_29 = 0 ;
V_163:
F_45 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_122 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
int V_166 , int * V_167 )
{
struct V_67 V_21 ;
struct V_155 * V_168 = NULL ;
struct V_165 * V_169 = NULL ;
struct V_65 * V_66 ;
T_3 V_124 = 0 ;
int V_29 = 0 ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . type == V_161 ) {
V_168 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_155 ) ;
V_124 = F_121 ( V_66 , V_168 ) ;
} else if ( V_21 . type == V_160 ) {
V_169 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_165 ) ;
V_124 = F_116 ( V_66 , V_169 ) ;
#ifdef F_89
} else if ( V_21 . type == V_147 ) {
struct V_141 * V_142 ;
V_142 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_141 ) ;
V_124 = F_123 ( V_66 , V_142 ) ;
#endif
} else {
F_91 () ;
}
F_32 ( V_124 < V_166 ) ;
V_124 -= V_166 ;
if ( V_124 == 0 ) {
V_29 = F_124 ( V_115 , V_138 , V_64 ) ;
* V_167 = 1 ;
} else {
if ( V_21 . type == V_161 )
F_120 ( V_66 , V_168 , V_124 ) ;
else if ( V_21 . type == V_160 )
F_115 ( V_66 , V_169 , V_124 ) ;
#ifdef F_89
else {
struct V_141 * V_142 ;
V_142 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_141 ) ;
F_125 ( V_66 , V_142 , V_124 ) ;
}
#endif
F_103 ( V_66 ) ;
}
return V_29 ;
}
static T_1 T_3 F_126 ( struct V_63 * V_64 ,
struct V_170 * V_171 )
{
struct V_67 V_21 ;
struct V_65 * V_66 ;
struct V_155 * V_168 ;
struct V_165 * V_169 ;
T_3 V_124 = 0 ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
if ( V_171 ) {
if ( F_127 ( V_66 , V_171 ) ==
V_161 ) {
V_168 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
V_124 = F_121 ( V_66 , V_168 ) ;
} else {
V_169 = (struct V_165 * ) ( V_171 + 1 ) ;
V_124 = F_116 ( V_66 , V_169 ) ;
}
} else if ( V_21 . type == V_161 ) {
V_168 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_155 ) ;
V_124 = F_121 ( V_66 , V_168 ) ;
} else if ( V_21 . type == V_160 ) {
V_169 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_165 ) ;
V_124 = F_116 ( V_66 , V_169 ) ;
#ifdef F_89
} else if ( V_21 . type == V_147 ) {
struct V_141 * V_142 ;
V_142 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_141 ) ;
V_124 = F_123 ( V_66 , V_142 ) ;
#endif
} else {
F_8 ( 1 ) ;
}
return V_124 ;
}
static T_1 int F_128 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 )
{
struct V_67 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_172 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_173 ;
V_21 . V_33 = V_151 ;
}
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_159 ;
#ifdef F_89
if ( V_29 == - V_159 && V_17 ) {
F_45 ( V_64 ) ;
V_21 . type = V_147 ;
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_159 ;
}
#endif
return V_29 ;
}
static T_1 int F_129 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 )
{
struct V_67 V_21 ;
int V_29 ;
V_21 . V_22 = V_27 ;
if ( V_17 ) {
V_21 . type = V_172 ;
V_21 . V_33 = V_17 ;
} else {
V_21 . type = V_173 ;
V_21 . V_33 = V_151 ;
}
V_29 = F_114 ( V_115 , V_138 , V_64 , & V_21 , 0 ) ;
F_45 ( V_64 ) ;
return V_29 ;
}
static inline int F_130 ( T_2 V_17 , T_2 V_139 )
{
int type ;
if ( V_139 < V_148 ) {
if ( V_17 > 0 )
type = V_172 ;
else
type = V_173 ;
} else {
if ( V_17 > 0 )
type = V_160 ;
else
type = V_161 ;
}
return type ;
}
static int F_42 ( struct V_63 * V_64 , int V_174 ,
struct V_67 * V_21 )
{
for (; V_174 < V_175 ; V_174 ++ ) {
if ( ! V_64 -> V_80 [ V_174 ] )
break;
if ( V_64 -> V_81 [ V_174 ] + 1 >=
F_39 ( V_64 -> V_80 [ V_174 ] ) )
continue;
if ( V_174 == 0 )
F_41 ( V_64 -> V_80 [ V_174 ] , V_21 ,
V_64 -> V_81 [ V_174 ] + 1 ) ;
else
F_131 ( V_64 -> V_80 [ V_174 ] , V_21 ,
V_64 -> V_81 [ V_174 ] + 1 ) ;
return 0 ;
}
return 1 ;
}
static T_5
int F_132 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_170 * * V_176 ,
T_2 V_27 , T_2 V_35 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_139 , T_2 V_33 , int V_177 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_67 V_21 ;
struct V_65 * V_66 ;
struct V_121 * V_122 ;
struct V_170 * V_171 ;
T_2 V_7 ;
T_2 V_123 ;
unsigned long V_178 ;
unsigned long V_31 ;
int V_140 ;
int type ;
int V_179 ;
int V_29 ;
int V_158 = 0 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 ;
V_179 = F_130 ( V_17 , V_139 ) ;
if ( V_177 ) {
V_140 = F_133 ( V_179 ) ;
V_64 -> V_181 = 1 ;
} else
V_140 = - 1 ;
if ( V_180 && V_139 < V_148 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_139 ;
}
V_162:
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 , V_140 , 1 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_79;
}
if ( V_29 > 0 && V_180 ) {
V_180 = false ;
if ( V_64 -> V_81 [ 0 ] ) {
V_64 -> V_81 [ 0 ] -- ;
F_41 ( V_64 -> V_80 [ 0 ] , & V_21 ,
V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_35 )
V_29 = 0 ;
}
if ( V_29 ) {
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 ;
F_45 ( V_64 ) ;
goto V_162;
}
}
if ( V_29 && ! V_177 ) {
V_158 = - V_159 ;
goto V_79;
} else if ( F_8 ( V_29 ) ) {
V_158 = - V_182 ;
goto V_79;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
#ifdef F_89
if ( V_123 < sizeof( * V_122 ) ) {
if ( ! V_177 ) {
V_158 = - V_159 ;
goto V_79;
}
V_29 = F_95 ( V_115 , V_138 , V_64 , V_139 ,
V_140 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_79;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
}
#endif
F_32 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
V_7 = F_88 ( V_66 , V_122 ) ;
V_178 = ( unsigned long ) ( V_122 + 1 ) ;
V_31 = ( unsigned long ) V_122 + V_123 ;
if ( V_7 & V_149 && ! V_180 ) {
V_178 += sizeof( struct V_143 ) ;
F_32 ( V_178 > V_31 ) ;
}
V_158 = - V_159 ;
while ( 1 ) {
if ( V_178 >= V_31 ) {
F_8 ( V_178 > V_31 ) ;
break;
}
V_171 = (struct V_170 * ) V_178 ;
type = F_127 ( V_66 , V_171 ) ;
if ( V_179 < type )
break;
if ( V_179 > type ) {
V_178 += F_133 ( type ) ;
continue;
}
if ( type == V_161 ) {
struct V_155 * V_183 ;
V_183 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
if ( F_111 ( V_66 , V_183 , V_151 ,
V_139 , V_33 ) ) {
V_158 = 0 ;
break;
}
if ( F_107 ( V_66 , V_183 ) <
F_104 ( V_151 , V_139 , V_33 ) )
break;
} else {
T_2 V_184 ;
V_184 = F_134 ( V_66 , V_171 ) ;
if ( V_17 > 0 ) {
if ( V_17 == V_184 ) {
V_158 = 0 ;
break;
}
if ( V_184 < V_17 )
break;
} else {
if ( V_151 == V_184 ) {
V_158 = 0 ;
break;
}
if ( V_184 < V_151 )
break;
}
}
V_178 += F_133 ( type ) ;
}
if ( V_158 == - V_159 && V_177 ) {
if ( V_123 + V_140 >=
F_135 ( V_138 ) ) {
V_158 = - V_185 ;
goto V_79;
}
if ( F_42 ( V_64 , 0 , & V_21 ) == 0 &&
V_21 . V_22 == V_27 &&
V_21 . type < V_186 ) {
V_158 = - V_185 ;
goto V_79;
}
}
* V_176 = (struct V_170 * ) V_178 ;
V_79:
if ( V_177 ) {
V_64 -> V_181 = 0 ;
F_136 ( V_64 , 1 ) ;
}
return V_158 ;
}
static T_5
void F_137 ( struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_170 * V_171 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_139 , T_2 V_33 , int V_164 ,
struct V_187 * V_134 )
{
struct V_65 * V_66 ;
struct V_121 * V_122 ;
unsigned long V_178 ;
unsigned long V_31 ;
unsigned long V_188 ;
T_2 V_117 ;
int V_57 ;
int type ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
V_188 = ( unsigned long ) V_171 - ( unsigned long ) V_122 ;
type = F_130 ( V_17 , V_139 ) ;
V_57 = F_133 ( type ) ;
F_97 ( V_138 -> V_34 , V_64 , V_57 ) ;
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
V_117 = F_87 ( V_66 , V_122 ) ;
V_117 += V_164 ;
F_98 ( V_66 , V_122 , V_117 ) ;
if ( V_134 )
F_138 ( V_134 , V_66 , V_122 ) ;
V_178 = ( unsigned long ) V_122 + V_188 ;
V_31 = ( unsigned long ) V_122 + F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
if ( V_178 < V_31 - V_57 )
F_139 ( V_66 , V_178 + V_57 , V_178 ,
V_31 - V_57 - V_178 ) ;
V_171 = (struct V_170 * ) V_178 ;
F_140 ( V_66 , V_171 , type ) ;
if ( type == V_161 ) {
struct V_155 * V_183 ;
V_183 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
F_117 ( V_66 , V_183 , V_151 ) ;
F_118 ( V_66 , V_183 , V_139 ) ;
F_119 ( V_66 , V_183 , V_33 ) ;
F_120 ( V_66 , V_183 , V_164 ) ;
} else if ( type == V_160 ) {
struct V_165 * V_189 ;
V_189 = (struct V_165 * ) ( V_171 + 1 ) ;
F_115 ( V_66 , V_189 , V_164 ) ;
F_141 ( V_66 , V_171 , V_17 ) ;
} else if ( type == V_172 ) {
F_141 ( V_66 , V_171 , V_17 ) ;
} else {
F_141 ( V_66 , V_171 , V_151 ) ;
}
F_103 ( V_66 ) ;
}
static int F_142 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_170 * * V_176 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 ,
T_2 V_151 , T_2 V_139 , T_2 V_33 )
{
int V_29 ;
V_29 = F_132 ( V_115 , V_138 , V_64 , V_176 ,
V_27 , V_35 , V_17 ,
V_151 , V_139 , V_33 , 0 ) ;
if ( V_29 != - V_159 )
return V_29 ;
F_45 ( V_64 ) ;
* V_176 = NULL ;
if ( V_139 < V_148 ) {
V_29 = F_128 ( V_115 , V_138 , V_64 , V_27 , V_17 ,
V_151 ) ;
} else {
V_29 = F_112 ( V_115 , V_138 , V_64 , V_27 , V_17 ,
V_151 , V_139 , V_33 ) ;
}
return V_29 ;
}
static T_5
void F_143 ( struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_170 * V_171 ,
int V_190 ,
struct V_187 * V_134 ,
int * V_167 )
{
struct V_65 * V_66 ;
struct V_121 * V_122 ;
struct V_155 * V_183 = NULL ;
struct V_165 * V_189 = NULL ;
unsigned long V_178 ;
unsigned long V_31 ;
T_3 V_123 ;
int V_57 ;
int type ;
T_2 V_117 ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
V_117 = F_87 ( V_66 , V_122 ) ;
F_8 ( V_190 < 0 && V_117 + V_190 <= 0 ) ;
V_117 += V_190 ;
F_98 ( V_66 , V_122 , V_117 ) ;
if ( V_134 )
F_138 ( V_134 , V_66 , V_122 ) ;
type = F_127 ( V_66 , V_171 ) ;
if ( type == V_161 ) {
V_183 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
V_117 = F_121 ( V_66 , V_183 ) ;
} else if ( type == V_160 ) {
V_189 = (struct V_165 * ) ( V_171 + 1 ) ;
V_117 = F_116 ( V_66 , V_189 ) ;
} else {
V_117 = 1 ;
F_32 ( V_190 != - 1 ) ;
}
F_32 ( V_190 < 0 && V_117 < - V_190 ) ;
V_117 += V_190 ;
if ( V_117 > 0 ) {
if ( type == V_161 )
F_120 ( V_66 , V_183 , V_117 ) ;
else
F_115 ( V_66 , V_189 , V_117 ) ;
} else {
* V_167 = 1 ;
V_57 = F_133 ( type ) ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
V_178 = ( unsigned long ) V_171 ;
V_31 = ( unsigned long ) V_122 + V_123 ;
if ( V_178 + V_57 < V_31 )
F_139 ( V_66 , V_178 , V_178 + V_57 ,
V_31 - V_178 - V_57 ) ;
V_123 -= V_57 ;
F_144 ( V_138 -> V_34 , V_64 , V_123 , 1 ) ;
}
F_103 ( V_66 ) ;
}
static T_5
int F_145 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 ,
T_2 V_151 , T_2 V_139 ,
T_2 V_33 , int V_164 ,
struct V_187 * V_134 )
{
struct V_170 * V_171 ;
int V_29 ;
V_29 = F_132 ( V_115 , V_138 , V_64 , & V_171 ,
V_27 , V_35 , V_17 ,
V_151 , V_139 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_32 ( V_139 < V_148 ) ;
F_143 ( V_138 , V_64 , V_171 ,
V_164 , V_134 , NULL ) ;
} else if ( V_29 == - V_159 ) {
F_137 ( V_138 , V_64 , V_171 , V_17 ,
V_151 , V_139 , V_33 ,
V_164 , V_134 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_146 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 , T_2 V_151 ,
T_2 V_139 , T_2 V_33 , int V_164 )
{
int V_29 ;
if ( V_139 < V_148 ) {
F_32 ( V_164 != 1 ) ;
V_29 = F_129 ( V_115 , V_138 , V_64 , V_27 ,
V_17 , V_151 ) ;
} else {
V_29 = F_113 ( V_115 , V_138 , V_64 , V_27 ,
V_17 , V_151 ,
V_139 , V_33 , V_164 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_170 * V_171 ,
int V_166 , int V_191 , int * V_167 )
{
int V_29 = 0 ;
F_32 ( ! V_191 && V_166 != 1 ) ;
if ( V_171 ) {
F_143 ( V_138 , V_64 , V_171 ,
- V_166 , NULL , V_167 ) ;
} else if ( V_191 ) {
V_29 = F_122 ( V_115 , V_138 , V_64 , V_166 ,
V_167 ) ;
} else {
* V_167 = 1 ;
V_29 = F_124 ( V_115 , V_138 , V_64 ) ;
}
return V_29 ;
}
static int F_148 ( struct V_192 * V_193 , T_2 V_32 , T_2 V_45 ,
T_2 * V_194 )
{
int V_195 , V_29 = 0 ;
T_2 V_196 , V_31 ;
T_2 V_197 = F_149 ( V_32 , 1 << 9 ) ;
if ( F_8 ( V_32 != V_197 ) ) {
V_45 -= V_197 - V_32 ;
V_45 = F_150 ( V_45 , 1 << 9 ) ;
V_32 = V_197 ;
}
* V_194 = 0 ;
if ( ! V_45 )
return 0 ;
V_31 = V_32 + V_45 ;
V_196 = V_45 ;
for ( V_195 = 0 ; V_195 < V_44 ; V_195 ++ ) {
T_2 V_198 = F_22 ( V_195 ) ;
T_2 V_199 = V_198 + V_200 ;
T_2 V_57 = V_198 - V_32 ;
if ( ! F_151 ( V_198 , V_32 , V_196 ) &&
! F_151 ( V_199 , V_32 , V_196 ) &&
! F_151 ( V_32 , V_198 , V_200 ) )
continue;
if ( V_198 <= V_32 ) {
V_32 += V_199 - V_32 ;
if ( V_32 > V_31 ) {
V_196 = 0 ;
break;
}
V_196 = V_31 - V_32 ;
continue;
}
if ( V_57 ) {
V_29 = F_152 ( V_193 , V_32 >> 9 , V_57 >> 9 ,
V_95 , 0 ) ;
if ( ! V_29 )
* V_194 += V_57 ;
else if ( V_29 != - V_201 )
return V_29 ;
}
V_32 = V_199 ;
if ( V_32 > V_31 ) {
V_196 = 0 ;
break;
}
V_196 = V_31 - V_32 ;
}
if ( V_196 ) {
V_29 = F_152 ( V_193 , V_32 >> 9 , V_196 >> 9 ,
V_95 , 0 ) ;
if ( ! V_29 )
* V_194 += V_196 ;
}
return V_29 ;
}
int F_153 ( struct V_12 * V_34 , T_2 V_27 ,
T_2 V_35 , T_2 * V_202 )
{
int V_29 ;
T_2 V_194 = 0 ;
struct V_203 * V_204 = NULL ;
F_154 ( V_34 ) ;
V_29 = F_155 ( V_34 , V_205 , V_27 , & V_35 ,
& V_204 , 0 ) ;
if ( ! V_29 ) {
struct V_206 * V_207 = V_204 -> V_208 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_204 -> V_209 ; V_40 ++ , V_207 ++ ) {
T_2 V_210 ;
if ( ! V_207 -> V_211 -> V_212 )
continue;
V_29 = F_148 ( V_207 -> V_211 -> V_193 ,
V_207 -> V_213 ,
V_207 -> V_214 ,
& V_210 ) ;
if ( ! V_29 )
V_194 += V_210 ;
else if ( V_29 != - V_201 )
break;
V_29 = 0 ;
}
F_156 ( V_204 ) ;
}
F_157 ( V_34 ) ;
if ( V_202 )
* V_202 = V_194 ;
if ( V_29 == - V_201 )
V_29 = 0 ;
return V_29 ;
}
int F_158 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 ,
T_2 V_151 , T_2 V_139 , T_2 V_33 )
{
int V_29 ;
F_32 ( V_139 < V_148 &&
V_151 == V_215 ) ;
if ( V_139 < V_148 ) {
V_29 = F_159 ( V_34 , V_115 , V_27 ,
V_35 ,
V_17 , V_151 , ( int ) V_139 ,
V_216 , NULL ) ;
} else {
V_29 = F_160 ( V_34 , V_115 , V_27 ,
V_35 , V_17 , V_151 ,
V_139 , V_33 , 0 ,
V_216 , NULL ) ;
}
return V_29 ;
}
static int F_161 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_217 * V_133 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_139 , T_2 V_33 , int V_164 ,
struct V_187 * V_134 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_121 * V_93 ;
struct V_67 V_21 ;
T_2 V_27 = V_133 -> V_27 ;
T_2 V_35 = V_133 -> V_35 ;
T_2 V_117 ;
int V_29 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_64 -> V_75 = V_76 ;
V_64 -> V_218 = 1 ;
V_29 = F_145 ( V_115 , V_34 -> V_62 , V_64 ,
V_27 , V_35 , V_17 ,
V_151 , V_139 , V_33 ,
V_164 , V_134 ) ;
if ( ( V_29 < 0 && V_29 != - V_185 ) || ! V_29 )
goto V_79;
V_66 = V_64 -> V_80 [ 0 ] ;
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
V_93 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
V_117 = F_87 ( V_66 , V_93 ) ;
F_98 ( V_66 , V_93 , V_117 + V_164 ) ;
if ( V_134 )
F_138 ( V_134 , V_66 , V_93 ) ;
F_103 ( V_66 ) ;
F_45 ( V_64 ) ;
V_64 -> V_75 = V_76 ;
V_64 -> V_218 = 1 ;
V_29 = F_146 ( V_115 , V_34 -> V_62 ,
V_64 , V_27 , V_17 , V_151 ,
V_139 , V_33 , V_164 ) ;
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
V_79:
F_53 ( V_64 ) ;
return V_29 ;
}
static int F_163 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_217 * V_133 ,
struct V_187 * V_134 ,
int V_219 )
{
int V_29 = 0 ;
struct V_220 * V_156 ;
struct V_67 V_221 ;
T_2 V_17 = 0 ;
T_2 V_222 = 0 ;
T_2 V_7 = 0 ;
V_221 . V_22 = V_133 -> V_27 ;
V_221 . V_33 = V_133 -> V_35 ;
V_221 . type = V_77 ;
V_156 = F_164 ( V_133 ) ;
F_165 ( V_34 , V_133 , V_156 , V_133 -> V_223 ) ;
if ( V_133 -> type == V_160 )
V_17 = V_156 -> V_17 ;
V_222 = V_156 -> V_138 ;
if ( V_133 -> V_223 == V_216 && V_219 ) {
if ( V_134 )
V_7 |= V_134 -> V_136 ;
V_29 = F_166 ( V_115 , V_34 ,
V_17 , V_222 , V_7 ,
V_156 -> V_22 , V_156 -> V_33 ,
& V_221 , V_133 -> V_137 ) ;
} else if ( V_133 -> V_223 == V_216 ) {
V_29 = F_161 ( V_115 , V_34 , V_133 , V_17 ,
V_222 , V_156 -> V_22 ,
V_156 -> V_33 , V_133 -> V_137 ,
V_134 ) ;
} else if ( V_133 -> V_223 == V_224 ) {
V_29 = F_167 ( V_115 , V_34 , V_133 , V_17 ,
V_222 , V_156 -> V_22 ,
V_156 -> V_33 , V_133 -> V_137 ,
V_134 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static void F_138 ( struct V_187 * V_134 ,
struct V_65 * V_66 ,
struct V_121 * V_122 )
{
T_2 V_7 = F_88 ( V_66 , V_122 ) ;
if ( V_134 -> V_135 ) {
V_7 |= V_134 -> V_136 ;
F_100 ( V_66 , V_122 , V_7 ) ;
}
if ( V_134 -> V_225 ) {
struct V_143 * V_144 ;
F_32 ( ! ( V_7 & V_149 ) ) ;
V_144 = (struct V_143 * ) ( V_122 + 1 ) ;
F_168 ( V_66 , V_144 , & V_134 -> V_21 ) ;
}
}
static int F_169 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_217 * V_133 ,
struct V_187 * V_134 )
{
struct V_67 V_21 ;
struct V_63 * V_64 ;
struct V_121 * V_122 ;
struct V_65 * V_66 ;
T_3 V_123 ;
int V_29 ;
int V_158 = 0 ;
int V_116 = ! V_134 -> V_191 ;
if ( V_115 -> V_226 )
return 0 ;
if ( V_116 && ! F_84 ( V_34 , V_126 ) )
V_116 = 0 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_21 . V_22 = V_133 -> V_27 ;
if ( V_116 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_134 -> V_174 ;
} else {
V_21 . type = V_77 ;
V_21 . V_33 = V_133 -> V_35 ;
}
V_162:
V_64 -> V_75 = V_76 ;
V_64 -> V_218 = 1 ;
V_29 = F_38 ( V_115 , V_34 -> V_62 , & V_21 , V_64 , 0 , 1 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_79;
}
if ( V_29 > 0 ) {
if ( V_116 ) {
if ( V_64 -> V_81 [ 0 ] > 0 ) {
V_64 -> V_81 [ 0 ] -- ;
F_41 ( V_64 -> V_80 [ 0 ] , & V_21 ,
V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . V_22 == V_133 -> V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_133 -> V_35 )
V_29 = 0 ;
}
if ( V_29 > 0 ) {
F_45 ( V_64 ) ;
V_116 = 0 ;
V_21 . V_22 = V_133 -> V_27 ;
V_21 . V_33 = V_133 -> V_35 ;
V_21 . type = V_77 ;
goto V_162;
}
} else {
V_158 = - V_182 ;
goto V_79;
}
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
#ifdef F_89
if ( V_123 < sizeof( * V_122 ) ) {
V_29 = F_95 ( V_115 , V_34 -> V_62 ,
V_64 , ( T_2 ) - 1 , 0 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_79;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
}
#endif
F_32 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
F_138 ( V_134 , V_66 , V_122 ) ;
F_103 ( V_66 ) ;
V_79:
F_53 ( V_64 ) ;
return V_158 ;
}
static int F_170 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_217 * V_133 ,
struct V_187 * V_134 ,
int V_219 )
{
int V_29 = 0 ;
struct V_227 * V_156 ;
struct V_67 V_221 ;
T_2 V_17 = 0 ;
T_2 V_222 = 0 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
V_156 = F_171 ( V_133 ) ;
F_172 ( V_34 , V_133 , V_156 , V_133 -> V_223 ) ;
if ( V_133 -> type == V_172 )
V_17 = V_156 -> V_17 ;
V_222 = V_156 -> V_138 ;
V_221 . V_22 = V_133 -> V_27 ;
if ( V_180 ) {
V_221 . V_33 = V_156 -> V_174 ;
V_221 . type = V_85 ;
} else {
V_221 . V_33 = V_133 -> V_35 ;
V_221 . type = V_77 ;
}
if ( V_133 -> V_137 != 1 ) {
F_173 ( V_34 ,
L_1 ,
V_133 -> V_27 , V_133 -> V_137 , V_133 -> V_223 , V_222 ,
V_17 ) ;
return - V_182 ;
}
if ( V_133 -> V_223 == V_216 && V_219 ) {
F_32 ( ! V_134 || ! V_134 -> V_135 ) ;
V_29 = F_174 ( V_115 , V_34 ,
V_17 , V_222 ,
V_134 -> V_136 ,
& V_134 -> V_21 ,
V_156 -> V_174 , & V_221 ) ;
} else if ( V_133 -> V_223 == V_216 ) {
V_29 = F_161 ( V_115 , V_34 , V_133 ,
V_17 , V_222 ,
V_156 -> V_174 , 0 , 1 ,
V_134 ) ;
} else if ( V_133 -> V_223 == V_224 ) {
V_29 = F_167 ( V_115 , V_34 , V_133 ,
V_17 , V_222 ,
V_156 -> V_174 , 0 , 1 , V_134 ) ;
} else {
F_91 () ;
}
return V_29 ;
}
static int F_175 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_217 * V_133 ,
struct V_187 * V_134 ,
int V_219 )
{
int V_29 = 0 ;
if ( V_115 -> V_226 ) {
if ( V_219 )
F_176 ( V_34 , V_133 -> V_27 ,
V_133 -> V_35 , 1 ) ;
return 0 ;
}
if ( F_177 ( V_133 ) ) {
struct V_118 * V_110 ;
F_32 ( V_134 ) ;
V_110 = F_178 ( V_133 ) ;
F_179 ( V_34 , V_133 , V_110 , V_133 -> V_223 ) ;
if ( V_219 ) {
F_176 ( V_34 , V_133 -> V_27 ,
V_133 -> V_35 , 1 ) ;
if ( V_110 -> V_191 ) {
V_29 = F_180 ( V_115 , V_34 ,
V_133 -> V_27 ,
V_133 -> V_35 ) ;
}
}
F_181 ( V_34 , V_110 -> V_228 ,
V_110 -> V_229 ) ;
return V_29 ;
}
if ( V_133 -> type == V_173 ||
V_133 -> type == V_172 )
V_29 = F_170 ( V_115 , V_34 , V_133 , V_134 ,
V_219 ) ;
else if ( V_133 -> type == V_161 ||
V_133 -> type == V_160 )
V_29 = F_163 ( V_115 , V_34 , V_133 , V_134 ,
V_219 ) ;
else
F_91 () ;
return V_29 ;
}
static inline struct V_217 *
F_182 ( struct V_118 * V_110 )
{
struct V_217 * V_156 ;
if ( F_183 ( & V_110 -> V_230 ) )
return NULL ;
if ( ! F_183 ( & V_110 -> V_231 ) )
return F_184 ( & V_110 -> V_231 ,
struct V_217 , V_232 ) ;
V_156 = F_184 ( & V_110 -> V_230 , struct V_217 ,
V_96 ) ;
ASSERT ( F_183 ( & V_156 -> V_232 ) ) ;
return V_156 ;
}
static T_1 int F_185 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
unsigned long V_41 )
{
struct V_119 * V_120 ;
struct V_217 * V_156 ;
struct V_118 * V_233 = NULL ;
struct V_187 * V_134 ;
T_6 V_32 = F_186 () ;
int V_29 ;
unsigned long V_8 = 0 ;
unsigned long V_234 = 0 ;
int V_235 = 0 ;
V_120 = & V_115 -> V_132 -> V_120 ;
while ( 1 ) {
if ( ! V_233 ) {
if ( V_8 >= V_41 )
break;
F_11 ( & V_120 -> V_48 ) ;
V_233 = F_187 ( V_115 ) ;
if ( ! V_233 ) {
F_13 ( & V_120 -> V_48 ) ;
break;
}
V_29 = F_188 ( V_115 , V_233 ) ;
F_13 ( & V_120 -> V_48 ) ;
if ( V_29 == - V_185 ) {
V_233 = NULL ;
V_8 ++ ;
continue;
}
}
F_11 ( & V_233 -> V_48 ) ;
F_189 ( V_115 , V_34 , V_120 ,
V_233 ) ;
V_156 = F_182 ( V_233 ) ;
if ( V_156 && V_156 -> V_236 &&
F_190 ( V_34 , V_120 , V_156 -> V_236 ) ) {
F_13 ( & V_233 -> V_48 ) ;
F_11 ( & V_120 -> V_48 ) ;
V_233 -> V_237 = 0 ;
V_120 -> V_238 ++ ;
F_13 ( & V_120 -> V_48 ) ;
F_191 ( V_233 ) ;
V_233 = NULL ;
F_48 () ;
V_8 ++ ;
continue;
}
V_235 = V_233 -> V_235 ;
V_233 -> V_235 = 0 ;
V_134 = V_233 -> V_134 ;
V_233 -> V_134 = NULL ;
if ( ! V_156 ) {
V_156 = & V_233 -> V_133 ;
if ( V_134 && V_235 ) {
F_192 ( V_134 ) ;
V_134 = NULL ;
}
if ( V_134 ) {
F_13 ( & V_233 -> V_48 ) ;
V_29 = F_169 ( V_115 , V_34 ,
V_156 , V_134 ) ;
F_192 ( V_134 ) ;
if ( V_29 ) {
if ( V_235 )
V_233 -> V_235 = 1 ;
F_11 ( & V_120 -> V_48 ) ;
V_233 -> V_237 = 0 ;
V_120 -> V_238 ++ ;
F_13 ( & V_120 -> V_48 ) ;
F_193 ( V_34 ,
L_2 ,
V_29 ) ;
F_191 ( V_233 ) ;
return V_29 ;
}
continue;
}
F_13 ( & V_233 -> V_48 ) ;
F_11 ( & V_120 -> V_48 ) ;
F_11 ( & V_233 -> V_48 ) ;
if ( ! F_183 ( & V_233 -> V_230 ) ||
V_233 -> V_134 ) {
F_13 ( & V_233 -> V_48 ) ;
F_13 ( & V_120 -> V_48 ) ;
continue;
}
V_156 -> V_239 = 0 ;
V_120 -> V_240 -- ;
F_194 ( & V_233 -> V_241 ,
& V_120 -> V_242 ) ;
F_13 ( & V_120 -> V_48 ) ;
} else {
V_234 ++ ;
V_156 -> V_239 = 0 ;
F_195 ( & V_156 -> V_96 ) ;
if ( ! F_183 ( & V_156 -> V_232 ) )
F_195 ( & V_156 -> V_232 ) ;
}
F_196 ( & V_120 -> V_243 ) ;
if ( ! F_177 ( V_156 ) ) {
switch ( V_156 -> V_223 ) {
case V_216 :
case V_244 :
V_233 -> V_133 . V_137 -= V_156 -> V_137 ;
break;
case V_224 :
V_233 -> V_133 . V_137 += V_156 -> V_137 ;
break;
default:
F_8 ( 1 ) ;
}
}
F_13 ( & V_233 -> V_48 ) ;
V_29 = F_175 ( V_115 , V_34 , V_156 , V_134 ,
V_235 ) ;
F_192 ( V_134 ) ;
if ( V_29 ) {
F_11 ( & V_120 -> V_48 ) ;
V_233 -> V_237 = 0 ;
V_120 -> V_238 ++ ;
F_13 ( & V_120 -> V_48 ) ;
F_191 ( V_233 ) ;
F_94 ( V_156 ) ;
F_193 ( V_34 , L_3 ,
V_29 ) ;
return V_29 ;
}
if ( F_177 ( V_156 ) ) {
if ( V_233 -> V_191 &&
V_233 -> V_245 < 0 ) {
F_11 ( & V_120 -> V_48 ) ;
V_120 -> V_246 -= V_156 -> V_35 ;
F_13 ( & V_120 -> V_48 ) ;
}
F_191 ( V_233 ) ;
V_233 = NULL ;
}
F_94 ( V_156 ) ;
V_8 ++ ;
F_48 () ;
}
if ( V_234 > 0 ) {
T_2 V_247 = F_197 ( F_198 ( F_186 () , V_32 ) ) ;
T_2 V_248 ;
F_11 ( & V_120 -> V_48 ) ;
V_248 = V_34 -> V_249 * 3 + V_247 ;
V_34 -> V_249 = V_248 >> 2 ;
F_13 ( & V_120 -> V_48 ) ;
}
return 0 ;
}
static T_2 F_199 ( struct V_250 * V_138 )
{
struct V_15 * V_30 = V_138 -> V_15 ;
struct V_217 * V_251 ;
int V_252 = 1 ;
T_2 V_253 ;
T_2 V_254 = 0 , V_69 = 0 ;
V_30 = F_200 ( V_138 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_217 , V_15 ) ;
V_254 = V_251 -> V_27 ;
}
V_30 = F_201 ( V_138 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_217 , V_15 ) ;
V_69 = V_251 -> V_27 ;
}
V_30 = V_138 -> V_15 ;
while ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_217 , V_15 ) ;
F_8 ( ! V_251 -> V_239 ) ;
V_253 = V_251 -> V_27 ;
if ( V_252 )
V_30 = V_30 -> V_23 ;
else
V_30 = V_30 -> V_24 ;
V_252 = 1 - V_252 ;
}
return V_253 ;
}
static inline T_2 F_202 ( struct V_12 * V_34 , T_2 V_255 )
{
T_2 V_35 ;
V_35 = V_255 * ( sizeof( struct V_121 ) +
sizeof( struct V_170 ) ) ;
if ( ! F_84 ( V_34 , V_126 ) )
V_35 += V_255 * sizeof( struct V_143 ) ;
return F_203 ( V_35 , F_204 ( V_34 ) ) ;
}
T_2 F_205 ( struct V_12 * V_34 , T_2 V_256 )
{
T_2 V_257 ;
T_2 V_258 ;
T_2 V_259 ;
V_257 = F_206 ( V_34 ) ;
V_258 = F_207 ( V_257 ,
( T_2 ) F_208 ( V_34 -> V_260 ) ) ;
V_259 = F_207 ( V_256 , V_34 -> V_53 ) ;
V_259 += V_258 - 1 ;
V_259 = F_207 ( V_259 , V_258 ) ;
return V_259 ;
}
int F_209 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_261 * V_262 ;
T_2 V_240 = V_115 -> V_132 -> V_120 . V_238 ;
T_2 V_256 = V_115 -> V_132 -> V_120 . V_246 ;
T_2 V_263 = V_115 -> V_132 -> V_263 ;
T_2 V_35 , V_264 ;
int V_29 = 0 ;
V_35 = F_210 ( V_34 , 1 ) ;
V_240 = F_202 ( V_34 , V_240 ) ;
if ( V_240 > 1 )
V_35 += ( V_240 - 1 ) * V_34 -> V_52 ;
V_35 <<= 1 ;
V_35 += F_205 ( V_34 , V_256 ) *
V_34 -> V_52 ;
V_264 = F_210 ( V_34 ,
V_263 ) ;
V_262 = & V_34 -> V_265 ;
if ( V_262 -> V_92 -> V_113 ) {
V_264 <<= 1 ;
V_35 <<= 1 ;
}
F_11 ( & V_262 -> V_48 ) ;
if ( V_262 -> V_10 <= V_35 + V_264 )
V_29 = 1 ;
F_13 ( & V_262 -> V_48 ) ;
return V_29 ;
}
int F_211 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
T_2 V_243 =
F_212 ( & V_115 -> V_132 -> V_120 . V_243 ) ;
T_2 V_266 ;
T_2 V_267 ;
F_2 () ;
V_266 = V_34 -> V_249 ;
V_267 = V_243 * V_266 ;
if ( V_267 >= V_268 )
return 1 ;
if ( V_267 >= V_268 / 2 )
return 2 ;
return F_209 ( V_115 , V_34 ) ;
}
static inline struct V_269 *
F_213 ( struct V_88 * V_89 )
{
return F_55 ( V_89 , struct V_269 , V_89 ) ;
}
static void F_214 ( struct V_88 * V_89 )
{
struct V_269 * V_270 = F_213 ( V_89 ) ;
struct V_114 * V_115 ;
struct V_12 * V_34 = V_270 -> V_138 -> V_34 ;
int V_29 ;
if ( F_215 ( V_34 ) )
goto V_271;
V_115 = F_216 ( V_270 -> V_138 ) ;
if ( F_217 ( V_115 ) ) {
V_270 -> error = F_218 ( V_115 ) ;
goto V_271;
}
V_115 -> V_272 = true ;
if ( V_115 -> V_273 > V_270 -> V_273 )
goto V_31;
V_29 = F_219 ( V_115 , V_34 , V_270 -> V_8 ) ;
if ( V_29 )
V_270 -> error = V_29 ;
V_31:
V_29 = F_220 ( V_115 ) ;
if ( V_29 && ! V_270 -> error )
V_270 -> error = V_29 ;
V_271:
if ( V_270 -> V_272 )
F_221 ( & V_270 -> V_87 ) ;
else
F_9 ( V_270 ) ;
}
int F_222 ( struct V_12 * V_34 ,
unsigned long V_8 , T_2 V_273 , int V_87 )
{
struct V_269 * V_270 ;
int V_29 ;
V_270 = F_223 ( sizeof( * V_270 ) , V_95 ) ;
if ( ! V_270 )
return - V_72 ;
V_270 -> V_138 = V_34 -> V_274 ;
V_270 -> V_8 = V_8 ;
V_270 -> error = 0 ;
V_270 -> V_273 = V_273 ;
if ( V_87 )
V_270 -> V_272 = 1 ;
else
V_270 -> V_272 = 0 ;
F_224 ( & V_270 -> V_87 ) ;
F_66 ( & V_270 -> V_89 , V_275 ,
F_214 , NULL , NULL ) ;
F_74 ( V_34 -> V_276 , & V_270 -> V_89 ) ;
if ( V_87 ) {
F_225 ( & V_270 -> V_87 ) ;
V_29 = V_270 -> error ;
F_9 ( V_270 ) ;
return V_29 ;
}
return 0 ;
}
int F_219 ( struct V_114 * V_115 ,
struct V_12 * V_34 , unsigned long V_8 )
{
struct V_15 * V_133 ;
struct V_119 * V_120 ;
struct V_118 * V_110 ;
int V_29 ;
int V_277 = V_8 == ( unsigned long ) - 1 ;
bool V_278 = V_115 -> V_278 ;
if ( V_115 -> V_226 )
return 0 ;
if ( F_226 ( V_279 , & V_34 -> V_7 ) )
return 0 ;
V_120 = & V_115 -> V_132 -> V_120 ;
if ( V_8 == 0 )
V_8 = F_212 ( & V_120 -> V_243 ) * 2 ;
V_162:
#ifdef F_227
V_120 -> V_280 = F_199 ( & V_120 -> V_138 ) ;
#endif
V_115 -> V_278 = false ;
V_29 = F_185 ( V_115 , V_34 , V_8 ) ;
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
return V_29 ;
}
if ( V_277 ) {
if ( ! F_183 ( & V_115 -> V_281 ) )
F_228 ( V_115 , V_34 ) ;
F_11 ( & V_120 -> V_48 ) ;
V_133 = F_200 ( & V_120 -> V_242 ) ;
if ( ! V_133 ) {
F_13 ( & V_120 -> V_48 ) ;
goto V_79;
}
while ( V_133 ) {
V_110 = F_12 ( V_133 , struct V_118 ,
V_241 ) ;
if ( F_177 ( & V_110 -> V_133 ) ) {
struct V_217 * V_156 ;
V_156 = & V_110 -> V_133 ;
F_5 ( & V_156 -> V_117 ) ;
F_13 ( & V_120 -> V_48 ) ;
F_49 ( & V_110 -> V_84 ) ;
F_47 ( & V_110 -> V_84 ) ;
F_94 ( V_156 ) ;
F_48 () ;
goto V_162;
} else {
F_8 ( 1 ) ;
}
V_133 = F_229 ( V_133 ) ;
}
F_13 ( & V_120 -> V_48 ) ;
F_48 () ;
goto V_162;
}
V_79:
F_230 ( V_115 ) ;
V_115 -> V_278 = V_278 ;
return 0 ;
}
int F_231 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 , T_2 V_7 ,
int V_174 , int V_191 )
{
struct V_187 * V_134 ;
int V_29 ;
V_134 = F_232 () ;
if ( ! V_134 )
return - V_72 ;
V_134 -> V_136 = V_7 ;
V_134 -> V_135 = true ;
V_134 -> V_225 = false ;
V_134 -> V_191 = V_191 ? true : false ;
V_134 -> V_174 = V_174 ;
V_29 = F_233 ( V_34 , V_115 , V_27 ,
V_35 , V_134 ) ;
if ( V_29 )
F_192 ( V_134 ) ;
return V_29 ;
}
static T_1 int F_234 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_118 * V_110 ;
struct V_217 * V_156 ;
struct V_220 * V_282 ;
struct V_119 * V_120 ;
int V_29 = 0 ;
V_120 = & V_115 -> V_132 -> V_120 ;
F_11 ( & V_120 -> V_48 ) ;
V_110 = F_92 ( V_115 , V_27 ) ;
if ( ! V_110 ) {
F_13 ( & V_120 -> V_48 ) ;
return 0 ;
}
if ( ! F_93 ( & V_110 -> V_84 ) ) {
F_5 ( & V_110 -> V_133 . V_117 ) ;
F_13 ( & V_120 -> V_48 ) ;
F_45 ( V_64 ) ;
F_49 ( & V_110 -> V_84 ) ;
F_47 ( & V_110 -> V_84 ) ;
F_94 ( & V_110 -> V_133 ) ;
return - V_185 ;
}
F_13 ( & V_120 -> V_48 ) ;
F_11 ( & V_110 -> V_48 ) ;
F_235 (ref, &head->ref_list, list) {
if ( V_156 -> type != V_161 ) {
V_29 = 1 ;
break;
}
V_282 = F_164 ( V_156 ) ;
if ( V_282 -> V_138 != V_138 -> V_283 . V_22 ||
V_282 -> V_22 != V_22 ||
V_282 -> V_33 != V_33 ) {
V_29 = 1 ;
break;
}
}
F_13 ( & V_110 -> V_48 ) ;
F_47 ( & V_110 -> V_84 ) ;
return V_29 ;
}
static T_1 int F_236 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_61 * V_62 = V_34 -> V_62 ;
struct V_65 * V_66 ;
struct V_155 * V_156 ;
struct V_170 * V_171 ;
struct V_121 * V_122 ;
struct V_67 V_21 ;
T_3 V_123 ;
int V_29 ;
V_21 . V_22 = V_27 ;
V_21 . V_33 = ( T_2 ) - 1 ;
V_21 . type = V_77 ;
V_29 = F_38 ( NULL , V_62 , & V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_79;
F_32 ( V_29 == 0 ) ;
V_29 = - V_159 ;
if ( V_64 -> V_81 [ 0 ] == 0 )
goto V_79;
V_64 -> V_81 [ 0 ] -- ;
V_66 = V_64 -> V_80 [ 0 ] ;
F_41 ( V_66 , & V_21 , V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . V_22 != V_27 || V_21 . type != V_77 )
goto V_79;
V_29 = 1 ;
V_123 = F_85 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
#ifdef F_89
if ( V_123 < sizeof( * V_122 ) ) {
F_8 ( V_123 != sizeof( struct V_129 ) ) ;
goto V_79;
}
#endif
V_122 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
if ( V_123 != sizeof( * V_122 ) +
F_133 ( V_161 ) )
goto V_79;
if ( F_237 ( V_66 , V_122 ) <=
F_238 ( & V_138 -> V_284 ) )
goto V_79;
V_171 = (struct V_170 * ) ( V_122 + 1 ) ;
if ( F_127 ( V_66 , V_171 ) !=
V_161 )
goto V_79;
V_156 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
if ( F_87 ( V_66 , V_122 ) !=
F_121 ( V_66 , V_156 ) ||
F_108 ( V_66 , V_156 ) !=
V_138 -> V_283 . V_22 ||
F_109 ( V_66 , V_156 ) != V_22 ||
F_110 ( V_66 , V_156 ) != V_33 )
goto V_79;
V_29 = 0 ;
V_79:
return V_29 ;
}
int F_239 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_63 * V_64 ;
int V_29 ;
int V_285 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_159 ;
do {
V_29 = F_236 ( V_115 , V_138 , V_64 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_159 )
goto V_79;
V_285 = F_234 ( V_115 , V_138 , V_64 , V_22 ,
V_33 , V_27 ) ;
} while ( V_285 == - V_185 );
if ( V_285 && V_285 != - V_159 ) {
V_29 = V_285 ;
goto V_79;
}
if ( V_29 != - V_159 || V_285 != - V_159 )
V_29 = 0 ;
V_79:
F_53 ( V_64 ) ;
if ( V_138 -> V_283 . V_22 == V_286 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_240 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_65 * V_287 ,
int V_288 , int V_289 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
T_2 V_27 ;
T_2 V_35 ;
T_2 V_17 ;
T_2 V_222 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_290 * V_291 ;
int V_40 ;
int V_174 ;
int V_29 = 0 ;
int (* F_241)( struct V_114 * ,
struct V_12 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_242 ( V_34 ) )
return 0 ;
V_222 = F_243 ( V_287 ) ;
V_70 = F_39 ( V_287 ) ;
V_174 = F_244 ( V_287 ) ;
if ( ! F_226 ( V_292 , & V_138 -> V_293 ) && V_174 == 0 )
return 0 ;
if ( V_289 )
F_241 = F_158 ;
else
F_241 = V_294 ;
if ( V_288 )
V_17 = V_287 -> V_32 ;
else
V_17 = 0 ;
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ ) {
if ( V_174 == 0 ) {
F_41 ( V_287 , & V_21 , V_40 ) ;
if ( V_21 . type != V_295 )
continue;
V_291 = F_86 ( V_287 , V_40 ,
struct V_290 ) ;
if ( F_245 ( V_287 , V_291 ) ==
V_296 )
continue;
V_27 = F_246 ( V_287 , V_291 ) ;
if ( V_27 == 0 )
continue;
V_35 = F_247 ( V_287 , V_291 ) ;
V_21 . V_33 -= F_248 ( V_287 , V_291 ) ;
V_29 = F_241 ( V_115 , V_34 , V_27 , V_35 ,
V_17 , V_222 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_163;
} else {
V_27 = F_249 ( V_287 , V_40 ) ;
V_35 = V_34 -> V_52 ;
V_29 = F_241 ( V_115 , V_34 , V_27 , V_35 ,
V_17 , V_222 , V_174 - 1 , 0 ) ;
if ( V_29 )
goto V_163;
}
}
return 0 ;
V_163:
return V_29 ;
}
int F_250 ( struct V_114 * V_115 , struct V_61 * V_138 ,
struct V_65 * V_287 , int V_288 )
{
return F_240 ( V_115 , V_138 , V_287 , V_288 , 1 ) ;
}
int F_251 ( struct V_114 * V_115 , struct V_61 * V_138 ,
struct V_65 * V_287 , int V_288 )
{
return F_240 ( V_115 , V_138 , V_287 , V_288 , 0 ) ;
}
static int F_252 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_1 * V_2 )
{
int V_29 ;
struct V_61 * V_62 = V_34 -> V_62 ;
unsigned long V_144 ;
struct V_65 * V_66 ;
V_29 = F_38 ( V_115 , V_62 , & V_2 -> V_21 , V_64 , 0 , 1 ) ;
if ( V_29 ) {
if ( V_29 > 0 )
V_29 = - V_159 ;
goto V_163;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_144 = F_253 ( V_66 , V_64 -> V_81 [ 0 ] ) ;
F_254 ( V_66 , & V_2 -> V_93 , V_144 , sizeof( V_2 -> V_93 ) ) ;
F_103 ( V_66 ) ;
V_163:
F_45 ( V_64 ) ;
return V_29 ;
}
static struct V_1 *
F_255 ( struct V_12 * V_34 ,
struct V_1 * V_2 )
{
struct V_15 * V_133 ;
F_11 ( & V_34 -> V_18 ) ;
if ( F_256 ( & V_2 -> V_20 ) ) {
const T_2 V_297 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_34 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_75 ( V_34 , V_297 ) ; return V_2 ;
}
V_133 = F_229 ( & V_2 -> V_20 ) ;
F_6 ( V_2 ) ;
if ( V_133 ) {
V_2 = F_12 ( V_133 , struct V_1 ,
V_20 ) ;
F_4 ( V_2 ) ;
} else
V_2 = NULL ;
F_13 ( & V_34 -> V_18 ) ;
return V_2 ;
}
static int F_257 ( struct V_1 * V_14 ,
struct V_114 * V_115 ,
struct V_63 * V_64 )
{
struct V_12 * V_34 = V_14 -> V_34 ;
struct V_61 * V_138 = V_34 -> V_274 ;
struct V_298 * V_298 = NULL ;
T_2 V_299 = 0 ;
int V_300 = V_301 ;
T_2 V_302 = 0 ;
int V_303 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * V_304 ) ) {
F_11 ( & V_14 -> V_48 ) ;
V_14 -> V_305 = V_306 ;
F_13 ( & V_14 -> V_48 ) ;
return 0 ;
}
if ( V_115 -> V_226 )
return 0 ;
V_162:
V_298 = F_258 ( V_138 , V_14 , V_64 ) ;
if ( F_217 ( V_298 ) && F_218 ( V_298 ) != - V_159 ) {
V_29 = F_218 ( V_298 ) ;
F_45 ( V_64 ) ;
goto V_79;
}
if ( F_217 ( V_298 ) ) {
F_32 ( V_303 ) ;
V_303 ++ ;
if ( V_14 -> V_307 )
goto V_128;
V_29 = F_259 ( V_138 , V_115 , V_14 , V_64 ) ;
if ( V_29 )
goto V_128;
goto V_162;
}
if ( V_14 -> V_308 == V_115 -> V_273 &&
F_260 ( V_298 ) ) {
V_300 = V_309 ;
goto V_310;
}
F_261 ( V_298 ) -> V_311 = 0 ;
V_29 = F_262 ( V_115 , V_138 , V_298 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_310;
}
F_8 ( V_29 ) ;
if ( F_260 ( V_298 ) > 0 ) {
V_29 = F_263 ( V_34 ,
& V_34 -> V_265 ) ;
if ( V_29 )
goto V_310;
V_29 = F_264 ( V_138 , V_115 , NULL , V_298 ) ;
if ( V_29 )
goto V_310;
}
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_265 ( V_34 , V_312 ) ) {
V_300 = V_306 ;
F_13 ( & V_14 -> V_48 ) ;
goto V_310;
}
F_13 ( & V_14 -> V_48 ) ;
if ( F_226 ( V_313 , & V_115 -> V_132 -> V_7 ) ) {
V_29 = - V_314 ;
goto V_310;
}
V_302 = F_203 ( V_14 -> V_21 . V_33 , V_315 ) ;
if ( ! V_302 )
V_302 = 1 ;
V_302 *= 16 ;
V_302 *= V_316 ;
V_29 = F_266 ( V_298 , 0 , V_302 ) ;
if ( V_29 )
goto V_310;
V_29 = F_267 ( V_298 , V_115 , 0 , 0 , V_302 ,
V_302 , V_302 ,
& V_299 ) ;
if ( ! V_29 )
V_300 = V_309 ;
else if ( V_29 == - V_314 )
F_268 ( V_313 , & V_115 -> V_132 -> V_7 ) ;
V_310:
F_269 ( V_298 ) ;
V_128:
F_45 ( V_64 ) ;
V_79:
F_11 ( & V_14 -> V_48 ) ;
if ( ! V_29 && V_300 == V_309 )
V_14 -> V_308 = V_115 -> V_273 ;
V_14 -> V_305 = V_300 ;
F_13 ( & V_14 -> V_48 ) ;
return V_29 ;
}
int F_270 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_2 , * V_317 ;
struct V_318 * V_319 = V_115 -> V_132 ;
struct V_63 * V_64 ;
if ( F_183 ( & V_319 -> V_320 ) ||
! F_265 ( V_34 , V_312 ) )
return 0 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
F_271 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_305 == V_321 )
F_257 ( V_2 , V_115 , V_64 ) ;
}
F_53 ( V_64 ) ;
return 0 ;
}
int F_272 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_2 ;
struct V_318 * V_319 = V_115 -> V_132 ;
int V_29 = 0 ;
int V_322 ;
struct V_63 * V_64 = NULL ;
F_273 ( V_323 ) ;
struct V_109 * V_324 = & V_319 -> V_325 ;
int V_326 = 0 ;
int V_327 = 0 ;
F_11 ( & V_319 -> V_328 ) ;
if ( F_183 ( & V_319 -> V_320 ) ) {
F_13 ( & V_319 -> V_328 ) ;
return 0 ;
}
F_274 ( & V_319 -> V_320 , & V_323 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_162:
F_228 ( V_115 , V_34 ) ;
if ( ! V_64 ) {
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
}
F_49 ( & V_115 -> V_132 -> V_329 ) ;
while ( ! F_183 ( & V_323 ) ) {
V_2 = F_184 ( & V_323 ,
struct V_1 ,
V_330 ) ;
if ( ! F_183 ( & V_2 -> V_331 ) ) {
F_275 ( & V_2 -> V_331 ) ;
F_276 ( V_115 , V_2 , V_64 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_319 -> V_328 ) ;
F_275 ( & V_2 -> V_330 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_322 = 1 ;
F_257 ( V_2 , V_115 , V_64 ) ;
if ( V_2 -> V_305 == V_309 ) {
V_2 -> V_332 . V_298 = NULL ;
V_29 = F_277 ( V_34 , V_115 ,
V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_332 . V_298 ) {
V_326 ++ ;
V_322 = 0 ;
F_72 ( & V_2 -> V_331 , V_324 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_252 ( V_115 , V_34 ,
V_64 , V_2 ) ;
if ( V_29 == - V_159 ) {
V_29 = 0 ;
F_11 ( & V_319 -> V_328 ) ;
if ( F_183 ( & V_2 -> V_330 ) ) {
F_72 ( & V_2 -> V_330 ,
& V_319 -> V_320 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_319 -> V_328 ) ;
} else if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
}
}
if ( V_322 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_47 ( & V_115 -> V_132 -> V_329 ) ;
F_49 ( & V_115 -> V_132 -> V_329 ) ;
}
F_47 ( & V_115 -> V_132 -> V_329 ) ;
V_29 = F_219 ( V_115 , V_34 , 0 ) ;
if ( ! V_29 && V_327 == 0 ) {
V_327 ++ ;
F_11 ( & V_319 -> V_328 ) ;
F_274 ( & V_319 -> V_320 , & V_323 ) ;
if ( ! F_183 ( & V_323 ) ) {
F_13 ( & V_319 -> V_328 ) ;
goto V_162;
}
F_13 ( & V_319 -> V_328 ) ;
} else if ( V_29 < 0 ) {
F_278 ( V_319 , V_34 ) ;
}
F_53 ( V_64 ) ;
return V_29 ;
}
int F_279 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_2 ;
struct V_318 * V_319 = V_115 -> V_132 ;
int V_29 = 0 ;
int V_322 ;
struct V_63 * V_64 ;
struct V_109 * V_324 = & V_319 -> V_325 ;
int V_326 = 0 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
F_11 ( & V_319 -> V_328 ) ;
while ( ! F_183 ( & V_319 -> V_320 ) ) {
V_2 = F_184 ( & V_319 -> V_320 ,
struct V_1 ,
V_330 ) ;
if ( ! F_183 ( & V_2 -> V_331 ) ) {
F_13 ( & V_319 -> V_328 ) ;
F_275 ( & V_2 -> V_331 ) ;
F_276 ( V_115 , V_2 , V_64 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_319 -> V_328 ) ;
}
F_275 ( & V_2 -> V_330 ) ;
F_13 ( & V_319 -> V_328 ) ;
V_322 = 1 ;
F_257 ( V_2 , V_115 , V_64 ) ;
if ( ! V_29 )
V_29 = F_219 ( V_115 , V_34 ,
( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_305 == V_309 ) {
V_2 -> V_332 . V_298 = NULL ;
V_29 = F_277 ( V_34 , V_115 ,
V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_332 . V_298 ) {
V_326 ++ ;
V_322 = 0 ;
F_72 ( & V_2 -> V_331 , V_324 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_252 ( V_115 , V_34 ,
V_64 , V_2 ) ;
if ( V_29 == - V_159 ) {
F_280 ( V_319 -> V_333 ,
F_212 ( & V_319 -> V_334 ) == 1 ) ;
V_29 = F_252 ( V_115 , V_34 ,
V_64 , V_2 ) ;
}
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
}
if ( V_322 )
F_6 ( V_2 ) ;
F_11 ( & V_319 -> V_328 ) ;
}
F_13 ( & V_319 -> V_328 ) ;
while ( ! F_183 ( V_324 ) ) {
V_2 = F_184 ( V_324 , struct V_1 ,
V_331 ) ;
F_275 ( & V_2 -> V_331 ) ;
F_276 ( V_115 , V_2 , V_64 ) ;
F_6 ( V_2 ) ;
}
F_53 ( V_64 ) ;
return V_29 ;
}
int F_281 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_335 = 0 ;
V_14 = F_76 ( V_34 , V_27 ) ;
if ( ! V_14 || V_14 -> V_307 )
V_335 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_335 ;
}
bool F_282 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_1 * V_336 ;
bool V_29 = true ;
V_336 = F_76 ( V_34 , V_27 ) ;
if ( ! V_336 )
return false ;
F_11 ( & V_336 -> V_48 ) ;
if ( V_336 -> V_307 )
V_29 = false ;
else
F_5 ( & V_336 -> V_337 ) ;
F_13 ( & V_336 -> V_48 ) ;
if ( ! V_29 )
F_6 ( V_336 ) ;
return V_29 ;
}
void F_283 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_1 * V_336 ;
V_336 = F_76 ( V_34 , V_27 ) ;
ASSERT ( V_336 ) ;
if ( F_7 ( & V_336 -> V_337 ) )
F_284 ( & V_336 -> V_337 ) ;
F_6 ( V_336 ) ;
F_6 ( V_336 ) ;
}
static int F_285 ( T_7 * V_338 )
{
F_68 () ;
return 0 ;
}
void F_286 ( struct V_1 * V_336 )
{
F_287 ( & V_336 -> V_337 ,
F_285 ,
V_99 ) ;
}
static const char * F_288 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_51 | V_339 :
return L_4 ;
case V_51 :
return L_5 ;
case V_339 :
return L_6 ;
case V_340 :
return L_7 ;
default:
F_8 ( 1 ) ;
return L_8 ;
} ;
}
static int F_289 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_341 , T_2 V_91 ,
T_2 V_342 ,
struct V_108 * * V_92 )
{
struct V_108 * V_111 ;
int V_40 ;
int V_343 ;
int V_29 ;
if ( V_7 & ( V_344 | V_345 |
V_346 ) )
V_343 = 2 ;
else
V_343 = 1 ;
V_111 = F_77 ( V_13 , V_7 ) ;
if ( V_111 ) {
F_11 ( & V_111 -> V_48 ) ;
V_111 -> V_341 += V_341 ;
V_111 -> V_347 += V_341 * V_343 ;
V_111 -> V_91 += V_91 ;
V_111 -> V_348 += V_91 * V_343 ;
V_111 -> V_342 += V_342 ;
if ( V_341 > 0 )
V_111 -> V_113 = 0 ;
F_290 ( V_13 , V_111 , V_341 -
V_91 - V_342 ) ;
F_13 ( & V_111 -> V_48 ) ;
* V_92 = V_111 ;
return 0 ;
}
V_111 = F_61 ( sizeof( * V_111 ) , V_95 ) ;
if ( ! V_111 )
return - V_72 ;
V_29 = F_291 ( & V_111 -> V_349 , 0 , V_350 ) ;
if ( V_29 ) {
F_9 ( V_111 ) ;
return V_29 ;
}
for ( V_40 = 0 ; V_40 < V_351 ; V_40 ++ )
F_62 ( & V_111 -> V_352 [ V_40 ] ) ;
F_292 ( & V_111 -> V_353 ) ;
F_293 ( & V_111 -> V_48 ) ;
V_111 -> V_7 = V_7 & V_112 ;
V_111 -> V_341 = V_341 ;
V_111 -> V_347 = V_341 * V_343 ;
V_111 -> V_91 = V_91 ;
V_111 -> V_348 = V_91 * V_343 ;
V_111 -> V_354 = 0 ;
V_111 -> V_355 = 0 ;
V_111 -> V_342 = V_342 ;
V_111 -> V_356 = 0 ;
V_111 -> V_113 = 0 ;
V_111 -> V_357 = 0 ;
V_111 -> V_358 = V_359 ;
V_111 -> V_360 = 0 ;
V_111 -> V_361 = 0 ;
F_64 ( & V_111 -> V_87 ) ;
F_62 ( & V_111 -> V_362 ) ;
F_62 ( & V_111 -> V_363 ) ;
F_62 ( & V_111 -> V_364 ) ;
V_29 = F_294 ( & V_111 -> V_365 , & V_366 ,
V_13 -> V_367 , L_9 ,
F_288 ( V_111 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_111 ) ;
return V_29 ;
}
* V_92 = V_111 ;
F_295 ( & V_111 -> V_96 , & V_13 -> V_92 ) ;
if ( V_7 & V_339 )
V_13 -> V_368 = V_111 ;
return V_29 ;
}
static void F_296 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_369 = F_297 ( V_7 ) &
V_370 ;
F_298 ( & V_34 -> V_371 ) ;
if ( V_7 & V_339 )
V_34 -> V_372 |= V_369 ;
if ( V_7 & V_51 )
V_34 -> V_373 |= V_369 ;
if ( V_7 & V_340 )
V_34 -> V_374 |= V_369 ;
F_299 ( & V_34 -> V_371 ) ;
}
static T_2 F_300 ( struct V_12 * V_34 , T_2 V_7 )
{
struct V_375 * V_376 = V_34 -> V_377 ;
T_2 V_378 = 0 ;
if ( ! V_376 )
return 0 ;
if ( V_7 & V_339 &&
V_376 -> V_379 . V_7 & V_380 ) {
V_378 = V_339 | V_376 -> V_379 . V_378 ;
} else if ( V_7 & V_340 &&
V_376 -> V_381 . V_7 & V_380 ) {
V_378 = V_340 | V_376 -> V_381 . V_378 ;
} else if ( V_7 & V_51 &&
V_376 -> V_382 . V_7 & V_380 ) {
V_378 = V_51 | V_376 -> V_382 . V_378 ;
}
return V_378 ;
}
static T_2 F_301 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_383 = V_34 -> V_384 -> V_385 ;
T_2 V_378 ;
T_2 V_386 ;
T_2 V_387 = 0 ;
F_11 ( & V_34 -> V_388 ) ;
V_378 = F_300 ( V_34 , V_7 ) ;
if ( V_378 ) {
if ( ( V_7 & V_378 ) & V_370 ) {
F_13 ( & V_34 -> V_388 ) ;
return F_302 ( V_378 ) ;
}
}
F_13 ( & V_34 -> V_388 ) ;
for ( V_386 = 0 ; V_386 < V_351 ; V_386 ++ ) {
if ( V_383 >= V_389 [ V_386 ] . V_390 )
V_387 |= V_391 [ V_386 ] ;
}
V_387 &= V_7 ;
if ( V_387 & V_392 )
V_387 = V_392 ;
else if ( V_387 & V_393 )
V_387 = V_393 ;
else if ( V_387 & V_346 )
V_387 = V_346 ;
else if ( V_387 & V_345 )
V_387 = V_345 ;
else if ( V_387 & V_394 )
V_387 = V_394 ;
V_7 &= ~ V_395 ;
return F_302 ( V_7 | V_387 ) ;
}
static T_2 F_303 ( struct V_12 * V_34 , T_2 V_396 )
{
unsigned V_236 ;
T_2 V_7 ;
do {
V_7 = V_396 ;
V_236 = F_304 ( & V_34 -> V_371 ) ;
if ( V_7 & V_339 )
V_7 |= V_34 -> V_372 ;
else if ( V_7 & V_340 )
V_7 |= V_34 -> V_374 ;
else if ( V_7 & V_51 )
V_7 |= V_34 -> V_373 ;
} while ( F_305 ( & V_34 -> V_371 , V_236 ) );
return F_301 ( V_34 , V_7 ) ;
}
T_2 F_306 ( struct V_61 * V_138 , int V_379 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
T_2 V_7 ;
T_2 V_29 ;
if ( V_379 )
V_7 = V_339 ;
else if ( V_138 == V_34 -> V_397 )
V_7 = V_340 ;
else
V_7 = V_51 ;
V_29 = F_303 ( V_34 , V_7 ) ;
return V_29 ;
}
int F_307 ( struct V_298 * V_298 , T_2 V_210 )
{
struct V_108 * V_368 ;
struct V_61 * V_138 = F_261 ( V_298 ) -> V_138 ;
struct V_12 * V_34 = V_138 -> V_34 ;
T_2 V_398 ;
int V_29 = 0 ;
int V_399 = 2 ;
int V_400 ;
V_210 = F_149 ( V_210 , V_34 -> V_53 ) ;
if ( F_308 ( V_298 ) ) {
V_399 = 0 ;
ASSERT ( V_401 -> V_402 ) ;
}
V_368 = V_34 -> V_368 ;
if ( ! V_368 )
goto V_403;
V_162:
F_11 ( & V_368 -> V_48 ) ;
V_398 = V_368 -> V_91 + V_368 -> V_355 +
V_368 -> V_354 + V_368 -> V_342 +
V_368 -> V_356 ;
if ( V_398 + V_210 > V_368 -> V_341 ) {
struct V_114 * V_115 ;
if ( ! V_368 -> V_113 ) {
T_2 V_404 ;
V_368 -> V_358 = V_405 ;
F_13 ( & V_368 -> V_48 ) ;
V_403:
V_404 = F_306 ( V_138 , 1 ) ;
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) )
return F_218 ( V_115 ) ;
V_29 = F_309 ( V_115 , V_34 , V_404 ,
V_359 ) ;
F_220 ( V_115 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_314 )
return V_29 ;
else {
V_400 = 1 ;
goto V_406;
}
}
if ( ! V_368 )
V_368 = V_34 -> V_368 ;
goto V_162;
}
V_400 = F_310 (
& V_368 -> V_349 ,
V_398 + V_210 - V_368 -> V_341 ) ;
F_13 ( & V_368 -> V_48 ) ;
V_406:
if ( V_399 &&
! F_212 ( & V_34 -> V_407 ) ) {
V_399 -- ;
if ( V_399 > 0 ) {
F_311 ( V_34 , 0 , - 1 ) ;
F_312 ( V_34 , - 1 , 0 ,
( T_2 ) - 1 ) ;
}
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) )
return F_218 ( V_115 ) ;
if ( V_400 >= 0 ||
F_226 ( V_408 ,
& V_115 -> V_132 -> V_7 ) ||
V_399 > 0 ) {
V_29 = F_313 ( V_115 ) ;
if ( V_29 )
return V_29 ;
F_49 ( & V_34 -> V_409 ) ;
F_47 ( & V_34 -> V_409 ) ;
goto V_162;
} else {
F_220 ( V_115 ) ;
}
}
F_314 ( V_34 ,
L_10 ,
V_368 -> V_7 , V_210 , 1 ) ;
return - V_314 ;
}
V_368 -> V_356 += V_210 ;
F_314 ( V_34 , L_11 ,
V_368 -> V_7 , V_210 , 1 ) ;
F_13 ( & V_368 -> V_48 ) ;
return V_29 ;
}
int F_266 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_45 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
int V_29 ;
V_45 = F_316 ( V_32 + V_45 , V_34 -> V_53 ) -
F_150 ( V_32 , V_34 -> V_53 ) ;
V_32 = F_150 ( V_32 , V_34 -> V_53 ) ;
V_29 = F_307 ( V_298 , V_45 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_317 ( V_298 , V_32 , V_45 ) ;
if ( V_29 )
F_318 ( V_298 , V_32 , V_45 ) ;
return V_29 ;
}
void F_318 ( struct V_298 * V_298 , T_2 V_32 ,
T_2 V_45 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
struct V_108 * V_368 ;
V_45 = F_316 ( V_32 + V_45 , V_34 -> V_53 ) -
F_150 ( V_32 , V_34 -> V_53 ) ;
V_32 = F_150 ( V_32 , V_34 -> V_53 ) ;
V_368 = V_34 -> V_368 ;
F_11 ( & V_368 -> V_48 ) ;
if ( F_8 ( V_368 -> V_356 < V_45 ) )
V_368 -> V_356 = 0 ;
else
V_368 -> V_356 -= V_45 ;
F_314 ( V_34 , L_11 ,
V_368 -> V_7 , V_45 , 0 ) ;
F_13 ( & V_368 -> V_48 ) ;
}
void F_319 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_45 )
{
struct V_61 * V_138 = F_261 ( V_298 ) -> V_138 ;
V_45 = F_316 ( V_32 + V_45 , V_138 -> V_34 -> V_53 ) -
F_150 ( V_32 , V_138 -> V_34 -> V_53 ) ;
V_32 = F_150 ( V_32 , V_138 -> V_34 -> V_53 ) ;
F_318 ( V_298 , V_32 , V_45 ) ;
F_320 ( V_298 , V_32 , V_45 ) ;
}
static void F_321 ( struct V_12 * V_13 )
{
struct V_109 * V_110 = & V_13 -> V_92 ;
struct V_108 * V_111 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_111 -> V_7 & V_51 )
V_111 -> V_358 = V_405 ;
}
F_80 () ;
}
static inline T_2 F_322 ( struct V_261 * V_411 )
{
return ( V_411 -> V_57 << 1 ) ;
}
static int F_323 ( struct V_12 * V_34 ,
struct V_108 * V_412 , int V_413 )
{
struct V_261 * V_262 = & V_34 -> V_265 ;
T_2 V_35 = V_412 -> V_341 - V_412 -> V_342 ;
T_2 V_414 = V_412 -> V_91 + V_412 -> V_355 ;
T_2 V_415 ;
if ( V_413 == V_405 )
return 1 ;
if ( V_412 -> V_7 & V_51 )
V_414 += F_322 ( V_262 ) ;
if ( V_413 == V_416 ) {
V_415 = F_324 ( V_34 -> V_260 ) ;
V_415 = F_35 ( T_2 , V_417 , F_325 ( V_415 , 1 ) ) ;
if ( V_35 - V_414 < V_415 )
return 1 ;
}
if ( V_414 + V_418 < F_326 ( V_35 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_327 ( struct V_12 * V_34 , T_2 type )
{
T_2 V_419 ;
if ( type & ( V_346 |
V_394 |
V_393 |
V_392 ) )
V_419 = V_34 -> V_384 -> V_385 ;
else if ( type & V_345 )
V_419 = 2 ;
else
V_419 = 1 ;
return V_419 ;
}
void F_328 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 type )
{
struct V_108 * V_13 ;
T_2 V_420 ;
T_2 V_415 ;
int V_29 = 0 ;
T_2 V_421 ;
ASSERT ( F_329 ( & V_34 -> V_422 ) ) ;
V_13 = F_77 ( V_34 , V_340 ) ;
F_11 ( & V_13 -> V_48 ) ;
V_420 = V_13 -> V_341 - V_13 -> V_91 - V_13 -> V_354 -
V_13 -> V_355 - V_13 -> V_342 -
V_13 -> V_356 ;
F_13 ( & V_13 -> V_48 ) ;
V_421 = F_327 ( V_34 , type ) ;
V_415 = F_330 ( V_34 , V_421 ) +
F_210 ( V_34 , 1 ) ;
if ( V_420 < V_415 && F_265 ( V_34 , V_423 ) ) {
F_331 ( V_34 , L_12 ,
V_420 , V_415 , type ) ;
F_332 ( V_34 , V_13 , 0 , 0 ) ;
}
if ( V_420 < V_415 ) {
T_2 V_7 ;
V_7 = F_306 ( V_34 -> V_397 , 0 ) ;
V_29 = F_333 ( V_115 , V_34 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_334 ( V_34 -> V_397 ,
& V_34 -> V_424 ,
V_415 , V_425 ) ;
if ( ! V_29 )
V_115 -> V_426 += V_415 ;
}
}
static int F_309 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_7 , int V_413 )
{
struct V_108 * V_92 ;
int V_427 = 0 ;
int V_29 = 0 ;
if ( V_115 -> V_428 )
return - V_314 ;
V_92 = F_77 ( V_34 , V_7 ) ;
if ( ! V_92 ) {
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_92 ) ;
V_162:
F_11 ( & V_92 -> V_48 ) ;
if ( V_413 < V_92 -> V_358 )
V_413 = V_92 -> V_358 ;
if ( V_92 -> V_113 ) {
if ( F_323 ( V_34 , V_92 , V_413 ) )
V_29 = - V_314 ;
else
V_29 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
if ( ! F_323 ( V_34 , V_92 , V_413 ) ) {
F_13 ( & V_92 -> V_48 ) ;
return 0 ;
} else if ( V_92 -> V_360 ) {
V_427 = 1 ;
} else {
V_92 -> V_360 = 1 ;
}
F_13 ( & V_92 -> V_48 ) ;
F_49 ( & V_34 -> V_422 ) ;
if ( V_427 ) {
F_47 ( & V_34 -> V_422 ) ;
V_427 = 0 ;
goto V_162;
}
V_115 -> V_428 = true ;
if ( F_335 ( V_92 ) )
V_7 |= ( V_339 | V_51 ) ;
if ( V_7 & V_339 && V_34 -> V_429 ) {
V_34 -> V_430 ++ ;
if ( ! ( V_34 -> V_430 %
V_34 -> V_429 ) )
F_321 ( V_34 ) ;
}
F_328 ( V_115 , V_34 , V_7 ) ;
V_29 = F_333 ( V_115 , V_34 , V_7 ) ;
V_115 -> V_428 = false ;
F_11 ( & V_92 -> V_48 ) ;
if ( V_29 < 0 && V_29 != - V_314 )
goto V_79;
if ( V_29 )
V_92 -> V_113 = 1 ;
else
V_29 = 1 ;
V_92 -> V_358 = V_359 ;
V_79:
V_92 -> V_360 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
F_47 ( & V_34 -> V_422 ) ;
if ( V_115 -> V_278 &&
V_115 -> V_426 >= ( T_2 ) V_418 ) {
F_228 ( V_115 , V_34 ) ;
F_336 ( V_115 ) ;
}
return V_29 ;
}
static int F_337 ( struct V_61 * V_138 ,
struct V_108 * V_92 , T_2 V_210 ,
enum V_431 V_361 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
T_2 V_432 ;
T_2 V_433 ;
T_2 V_434 ;
T_2 V_398 ;
if ( V_92 -> V_7 & V_339 )
return 0 ;
V_432 = F_306 ( V_138 , 0 ) ;
V_398 = V_92 -> V_91 + V_92 -> V_355 +
V_92 -> V_354 + V_92 -> V_342 ;
F_11 ( & V_262 -> V_48 ) ;
V_433 = F_322 ( V_262 ) ;
F_13 ( & V_262 -> V_48 ) ;
if ( V_398 + V_433 >= V_92 -> V_341 )
return 0 ;
V_398 += V_92 -> V_356 ;
F_11 ( & V_34 -> V_435 ) ;
V_434 = V_34 -> V_436 ;
F_13 ( & V_34 -> V_435 ) ;
if ( V_432 & ( V_344 |
V_345 |
V_346 ) )
V_434 >>= 1 ;
if ( V_361 == V_437 )
V_434 >>= 3 ;
else
V_434 >>= 1 ;
if ( V_398 + V_210 < V_92 -> V_341 + V_434 )
return 1 ;
return 0 ;
}
static void F_338 ( struct V_12 * V_34 ,
unsigned long V_438 , int V_439 )
{
struct V_440 * V_441 = V_34 -> V_441 ;
if ( F_339 ( & V_441 -> V_442 ) ) {
F_340 ( V_441 , V_438 , V_443 ) ;
F_46 ( & V_441 -> V_442 ) ;
} else {
F_311 ( V_34 , 0 , V_439 ) ;
if ( ! V_401 -> V_402 )
F_312 ( V_34 , V_439 , 0 , ( T_2 ) - 1 ) ;
}
}
static inline int F_341 ( struct V_12 * V_34 ,
T_2 V_444 )
{
T_2 V_210 ;
int V_41 ;
V_210 = F_210 ( V_34 , 1 ) ;
V_41 = ( int ) F_207 ( V_444 , V_210 ) ;
if ( ! V_41 )
V_41 = 1 ;
return V_41 ;
}
static void F_342 ( struct V_61 * V_138 , T_2 V_444 , T_2 V_445 ,
bool V_446 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_447 ;
struct V_108 * V_92 ;
struct V_114 * V_115 ;
T_2 V_448 ;
T_2 V_449 ;
long V_450 ;
unsigned long V_438 ;
int V_327 ;
int V_451 ;
enum V_431 V_361 ;
V_451 = F_341 ( V_34 , V_444 ) ;
V_444 = ( T_2 ) V_451 * V_452 ;
V_115 = (struct V_114 * ) V_401 -> V_402 ;
V_447 = & V_34 -> V_453 ;
V_92 = V_447 -> V_92 ;
V_448 = F_343 (
& V_34 -> V_448 ) ;
if ( V_448 == 0 ) {
if ( V_115 )
return;
if ( V_446 )
F_312 ( V_34 , V_451 , 0 , ( T_2 ) - 1 ) ;
return;
}
V_327 = 0 ;
while ( V_448 && V_327 < 3 ) {
V_449 = F_344 ( V_448 , V_444 ) ;
V_438 = V_449 >> V_454 ;
F_338 ( V_34 , V_438 , V_451 ) ;
V_449 = F_212 ( & V_34 -> V_455 ) ;
if ( ! V_449 )
goto V_456;
if ( V_449 <= V_438 )
V_449 = 0 ;
else
V_449 -= V_438 ;
F_280 ( V_34 -> V_457 ,
F_212 ( & V_34 -> V_455 ) <=
( int ) V_449 ) ;
V_456:
if ( ! V_115 )
V_361 = V_437 ;
else
V_361 = V_425 ;
F_11 ( & V_92 -> V_48 ) ;
if ( F_337 ( V_138 , V_92 , V_445 , V_361 ) ) {
F_13 ( & V_92 -> V_48 ) ;
break;
}
if ( F_183 ( & V_92 -> V_363 ) &&
F_183 ( & V_92 -> V_364 ) ) {
F_13 ( & V_92 -> V_48 ) ;
break;
}
F_13 ( & V_92 -> V_48 ) ;
V_327 ++ ;
if ( V_446 && ! V_115 ) {
F_312 ( V_34 , V_451 , 0 , ( T_2 ) - 1 ) ;
} else {
V_450 = F_345 ( 1 ) ;
if ( V_450 )
break;
}
V_448 = F_343 (
& V_34 -> V_448 ) ;
}
}
static int F_346 ( struct V_61 * V_138 ,
struct V_108 * V_92 ,
T_2 V_210 , int V_413 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_458 = & V_34 -> V_459 ;
struct V_114 * V_115 ;
V_115 = (struct V_114 * ) V_401 -> V_402 ;
if ( V_115 )
return - V_185 ;
if ( V_413 )
goto V_460;
if ( F_310 ( & V_92 -> V_349 ,
V_210 ) >= 0 )
goto V_460;
if ( V_92 != V_458 -> V_92 )
return - V_314 ;
F_11 ( & V_458 -> V_48 ) ;
if ( F_310 ( & V_92 -> V_349 ,
V_210 - V_458 -> V_57 ) >= 0 ) {
F_13 ( & V_458 -> V_48 ) ;
return - V_314 ;
}
F_13 ( & V_458 -> V_48 ) ;
V_460:
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) )
return - V_314 ;
return F_313 ( V_115 ) ;
}
static int F_347 ( struct V_61 * V_138 ,
struct V_108 * V_92 , T_2 V_35 ,
T_2 V_461 , int V_293 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_114 * V_115 ;
int V_41 ;
int V_29 = 0 ;
switch ( V_293 ) {
case V_462 :
case V_463 :
if ( V_293 == V_462 )
V_41 = F_341 ( V_34 , V_35 ) * 2 ;
else
V_41 = - 1 ;
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
break;
}
V_29 = F_348 ( V_115 , V_34 , V_41 ) ;
F_220 ( V_115 ) ;
break;
case V_464 :
case V_465 :
F_342 ( V_138 , V_35 * 2 , V_461 ,
V_293 == V_465 ) ;
break;
case V_466 :
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
break;
}
V_29 = F_309 ( V_115 , V_34 ,
F_306 ( V_138 , 0 ) ,
V_359 ) ;
F_220 ( V_115 ) ;
if ( V_29 > 0 || V_29 == - V_314 )
V_29 = 0 ;
break;
case V_467 :
V_29 = F_346 ( V_138 , V_92 , V_461 , 0 ) ;
break;
default:
V_29 = - V_314 ;
break;
}
F_349 ( V_34 , V_92 -> V_7 , V_35 ,
V_461 , V_293 , V_29 ) ;
return V_29 ;
}
static inline T_2
F_350 ( struct V_61 * V_138 ,
struct V_108 * V_92 )
{
struct V_468 * V_469 ;
T_2 V_398 ;
T_2 V_470 ;
T_2 V_444 = 0 ;
F_235 (ticket, &space_info->tickets, list)
V_444 += V_469 -> V_210 ;
F_235 (ticket, &space_info->priority_tickets, list)
V_444 += V_469 -> V_210 ;
if ( V_444 )
return V_444 ;
V_444 = F_24 ( T_2 , F_351 () * V_304 , V_471 ) ;
if ( F_337 ( V_138 , V_92 , V_444 ,
V_437 ) )
return 0 ;
V_398 = V_92 -> V_91 + V_92 -> V_355 +
V_92 -> V_354 + V_92 -> V_342 +
V_92 -> V_356 ;
if ( F_337 ( V_138 , V_92 , V_304 , V_437 ) )
V_470 = F_325 ( V_92 -> V_341 , 95 ) ;
else
V_470 = F_325 ( V_92 -> V_341 , 90 ) ;
if ( V_398 > V_470 )
V_444 = V_398 - V_470 ;
else
V_444 = 0 ;
V_444 = F_344 ( V_444 , V_92 -> V_356 +
V_92 -> V_355 ) ;
return V_444 ;
}
static inline int F_352 ( struct V_108 * V_92 ,
struct V_61 * V_138 , T_2 V_398 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
T_2 V_415 = F_325 ( V_92 -> V_341 , 98 ) ;
if ( ( V_92 -> V_91 + V_92 -> V_355 ) >= V_415 )
return 0 ;
if ( ! F_350 ( V_138 , V_92 ) )
return 0 ;
return ( V_398 >= V_415 && ! F_40 ( V_34 ) &&
! F_226 ( V_472 , & V_34 -> V_473 ) ) ;
}
static void F_353 ( struct V_109 * V_110 )
{
struct V_468 * V_469 ;
while ( ! F_183 ( V_110 ) ) {
V_469 = F_184 ( V_110 , struct V_468 , V_96 ) ;
F_275 ( & V_469 -> V_96 ) ;
V_469 -> error = - V_314 ;
F_52 ( & V_469 -> V_87 ) ;
}
}
static void F_354 ( struct V_474 * V_89 )
{
struct V_12 * V_34 ;
struct V_108 * V_92 ;
T_2 V_444 ;
int V_475 ;
int V_476 = 0 ;
T_2 V_477 ;
V_34 = F_55 ( V_89 , struct V_12 , V_478 ) ;
V_92 = F_77 ( V_34 , V_51 ) ;
F_11 ( & V_92 -> V_48 ) ;
V_444 = F_350 ( V_34 -> V_479 ,
V_92 ) ;
if ( ! V_444 ) {
V_92 -> V_361 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
return;
}
V_477 = V_92 -> V_480 ;
F_13 ( & V_92 -> V_48 ) ;
V_475 = V_462 ;
do {
struct V_468 * V_469 ;
int V_29 ;
V_29 = F_347 ( V_34 -> V_479 , V_92 , V_444 ,
V_444 , V_475 ) ;
F_11 ( & V_92 -> V_48 ) ;
if ( F_183 ( & V_92 -> V_363 ) ) {
V_92 -> V_361 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
return;
}
V_444 = F_350 ( V_34 -> V_479 ,
V_92 ) ;
V_469 = F_184 ( & V_92 -> V_363 ,
struct V_468 , V_96 ) ;
if ( V_477 == V_92 -> V_480 ) {
V_475 ++ ;
} else {
V_477 = V_92 -> V_480 ;
V_475 = V_462 ;
if ( V_476 )
V_476 -- ;
}
if ( V_475 > V_467 ) {
V_476 ++ ;
if ( V_476 > 2 ) {
F_353 ( & V_92 -> V_363 ) ;
V_92 -> V_361 = 0 ;
} else {
V_475 = V_462 ;
}
}
F_13 ( & V_92 -> V_48 ) ;
} while ( V_475 <= V_467 );
}
void F_355 ( struct V_474 * V_89 )
{
F_356 ( V_89 , F_354 ) ;
}
static void F_357 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
struct V_468 * V_469 )
{
T_2 V_444 ;
int V_475 = V_462 ;
F_11 ( & V_92 -> V_48 ) ;
V_444 = F_350 ( V_34 -> V_479 ,
V_92 ) ;
if ( ! V_444 ) {
F_13 ( & V_92 -> V_48 ) ;
return;
}
F_13 ( & V_92 -> V_48 ) ;
do {
F_347 ( V_34 -> V_479 , V_92 , V_444 ,
V_444 , V_475 ) ;
V_475 ++ ;
F_11 ( & V_92 -> V_48 ) ;
if ( V_469 -> V_210 == 0 ) {
F_13 ( & V_92 -> V_48 ) ;
return;
}
F_13 ( & V_92 -> V_48 ) ;
if ( V_475 == V_464 ||
V_475 == V_465 )
V_475 = V_466 ;
} while ( V_475 < V_467 );
}
static int F_358 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
struct V_468 * V_469 , T_2 V_461 )
{
F_60 ( V_87 ) ;
int V_29 = 0 ;
F_11 ( & V_92 -> V_48 ) ;
while ( V_469 -> V_210 > 0 && V_469 -> error == 0 ) {
V_29 = F_359 ( & V_469 -> V_87 , & V_87 , V_481 ) ;
if ( V_29 ) {
V_29 = - V_482 ;
break;
}
F_13 ( & V_92 -> V_48 ) ;
F_68 () ;
F_69 ( & V_469 -> V_87 , & V_87 ) ;
F_11 ( & V_92 -> V_48 ) ;
}
if ( ! V_29 )
V_29 = V_469 -> error ;
if ( ! F_183 ( & V_469 -> V_96 ) )
F_275 ( & V_469 -> V_96 ) ;
if ( V_469 -> V_210 && V_469 -> V_210 < V_461 ) {
T_2 V_35 = V_461 - V_469 -> V_210 ;
V_92 -> V_356 -= V_35 ;
F_314 ( V_34 , L_11 ,
V_92 -> V_7 , V_35 , 0 ) ;
}
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
static int F_360 ( struct V_61 * V_138 ,
struct V_108 * V_92 ,
T_2 V_461 ,
enum V_431 V_361 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_468 V_469 ;
T_2 V_398 ;
int V_29 = 0 ;
ASSERT ( V_461 ) ;
ASSERT ( ! V_401 -> V_402 || V_361 != V_437 ) ;
F_11 ( & V_92 -> V_48 ) ;
V_29 = - V_314 ;
V_398 = V_92 -> V_91 + V_92 -> V_355 +
V_92 -> V_354 + V_92 -> V_342 +
V_92 -> V_356 ;
if ( V_398 + V_461 <= V_92 -> V_341 ) {
V_92 -> V_356 += V_461 ;
F_314 ( V_34 , L_11 ,
V_92 -> V_7 , V_461 , 1 ) ;
V_29 = 0 ;
} else if ( F_337 ( V_138 , V_92 , V_461 , V_361 ) ) {
V_92 -> V_356 += V_461 ;
F_314 ( V_34 , L_11 ,
V_92 -> V_7 , V_461 , 1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_361 != V_425 ) {
V_469 . V_210 = V_461 ;
V_469 . error = 0 ;
F_64 ( & V_469 . V_87 ) ;
if ( V_361 == V_437 ) {
F_72 ( & V_469 . V_96 , & V_92 -> V_363 ) ;
if ( ! V_92 -> V_361 ) {
V_92 -> V_361 = 1 ;
F_361 ( V_34 ,
V_92 -> V_7 ,
V_461 , V_361 ,
L_13 ) ;
F_362 ( V_483 ,
& V_138 -> V_34 -> V_478 ) ;
}
} else {
F_72 ( & V_469 . V_96 ,
& V_92 -> V_364 ) ;
}
} else if ( ! V_29 && V_92 -> V_7 & V_51 ) {
V_398 += V_461 ;
if ( ! F_226 ( V_484 , & V_34 -> V_7 ) &&
F_352 ( V_92 , V_138 , V_398 ) &&
! F_363 ( & V_34 -> V_478 ) ) {
F_361 ( V_34 , V_92 -> V_7 ,
V_461 , V_361 , L_14 ) ;
F_362 ( V_483 ,
& V_34 -> V_478 ) ;
}
}
F_13 ( & V_92 -> V_48 ) ;
if ( ! V_29 || V_361 == V_425 )
return V_29 ;
if ( V_361 == V_437 )
return F_358 ( V_34 , V_92 , & V_469 ,
V_461 ) ;
V_29 = 0 ;
F_357 ( V_34 , V_92 , & V_469 ) ;
F_11 ( & V_92 -> V_48 ) ;
if ( V_469 . V_210 ) {
if ( V_469 . V_210 < V_461 ) {
T_2 V_35 = V_461 - V_469 . V_210 ;
V_92 -> V_356 -= V_35 ;
F_314 ( V_34 , L_11 ,
V_92 -> V_7 ,
V_35 , 0 ) ;
}
F_275 ( & V_469 . V_96 ) ;
V_29 = - V_314 ;
}
F_13 ( & V_92 -> V_48 ) ;
ASSERT ( F_183 ( & V_469 . V_96 ) ) ;
return V_29 ;
}
static int F_364 ( struct V_61 * V_138 ,
struct V_261 * V_447 ,
T_2 V_461 ,
enum V_431 V_361 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
int V_29 ;
V_29 = F_360 ( V_138 , V_447 -> V_92 , V_461 ,
V_361 ) ;
if ( V_29 == - V_314 &&
F_365 ( V_138 -> V_485 == V_486 ) ) {
if ( V_447 != V_262 &&
! F_366 ( V_262 , V_461 ) )
V_29 = 0 ;
}
if ( V_29 == - V_314 )
F_314 ( V_34 , L_10 ,
V_447 -> V_92 -> V_7 ,
V_461 , 1 ) ;
return V_29 ;
}
static struct V_261 * F_367 (
const struct V_114 * V_115 ,
const struct V_61 * V_138 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_447 = NULL ;
if ( F_226 ( V_292 , & V_138 -> V_293 ) ||
( V_138 == V_34 -> V_487 && V_115 -> V_488 ) ||
( V_138 == V_34 -> V_489 ) )
V_447 = V_115 -> V_447 ;
if ( ! V_447 )
V_447 = V_138 -> V_447 ;
if ( ! V_447 )
V_447 = & V_34 -> V_490 ;
return V_447 ;
}
static int F_366 ( struct V_261 * V_447 ,
T_2 V_35 )
{
int V_29 = - V_314 ;
F_11 ( & V_447 -> V_48 ) ;
if ( V_447 -> V_10 >= V_35 ) {
V_447 -> V_10 -= V_35 ;
if ( V_447 -> V_10 < V_447 -> V_57 )
V_447 -> V_113 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_447 -> V_48 ) ;
return V_29 ;
}
static void F_368 ( struct V_261 * V_447 ,
T_2 V_35 , int V_491 )
{
F_11 ( & V_447 -> V_48 ) ;
V_447 -> V_10 += V_35 ;
if ( V_491 )
V_447 -> V_57 += V_35 ;
else if ( V_447 -> V_10 >= V_447 -> V_57 )
V_447 -> V_113 = 1 ;
F_13 ( & V_447 -> V_48 ) ;
}
int F_369 ( struct V_12 * V_34 ,
struct V_261 * V_492 , T_2 V_35 ,
int V_493 )
{
struct V_261 * V_262 = & V_34 -> V_265 ;
T_2 V_494 ;
if ( V_262 -> V_92 != V_492 -> V_92 )
return - V_314 ;
F_11 ( & V_262 -> V_48 ) ;
V_494 = F_326 ( V_262 -> V_57 , V_493 ) ;
if ( V_262 -> V_10 < V_494 + V_35 ) {
F_13 ( & V_262 -> V_48 ) ;
return - V_314 ;
}
V_262 -> V_10 -= V_35 ;
if ( V_262 -> V_10 < V_262 -> V_57 )
V_262 -> V_113 = 0 ;
F_13 ( & V_262 -> V_48 ) ;
F_368 ( V_492 , V_35 , 1 ) ;
return 0 ;
}
static void F_370 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
T_2 V_35 )
{
struct V_468 * V_469 ;
struct V_109 * V_110 ;
T_2 V_398 ;
enum V_431 V_361 = V_425 ;
bool V_495 = false ;
F_11 ( & V_92 -> V_48 ) ;
V_110 = & V_92 -> V_364 ;
V_398 = V_92 -> V_91 + V_92 -> V_355 +
V_92 -> V_354 + V_92 -> V_342 +
V_92 -> V_356 ;
if ( V_398 - V_35 >= V_92 -> V_341 )
V_495 = true ;
V_162:
while ( ! F_183 ( V_110 ) && V_35 ) {
V_469 = F_184 ( V_110 , struct V_468 ,
V_96 ) ;
if ( V_495 &&
! F_337 ( V_34 -> V_62 , V_92 , 0 ,
V_361 ) )
break;
if ( V_35 >= V_469 -> V_210 ) {
F_275 ( & V_469 -> V_96 ) ;
V_35 -= V_469 -> V_210 ;
V_469 -> V_210 = 0 ;
V_92 -> V_480 ++ ;
F_52 ( & V_469 -> V_87 ) ;
} else {
V_469 -> V_210 -= V_35 ;
V_35 = 0 ;
}
}
if ( V_35 && V_110 == & V_92 -> V_364 ) {
V_110 = & V_92 -> V_363 ;
V_361 = V_437 ;
goto V_162;
}
V_92 -> V_356 -= V_35 ;
F_314 ( V_34 , L_11 ,
V_92 -> V_7 , V_35 , 0 ) ;
F_13 ( & V_92 -> V_48 ) ;
}
static void F_290 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
T_2 V_35 )
{
struct V_468 * V_469 ;
struct V_109 * V_110 = & V_92 -> V_364 ;
V_162:
while ( ! F_183 ( V_110 ) && V_35 ) {
V_469 = F_184 ( V_110 , struct V_468 ,
V_96 ) ;
if ( V_35 >= V_469 -> V_210 ) {
F_314 ( V_34 , L_11 ,
V_92 -> V_7 ,
V_469 -> V_210 , 1 ) ;
F_275 ( & V_469 -> V_96 ) ;
V_35 -= V_469 -> V_210 ;
V_92 -> V_356 += V_469 -> V_210 ;
V_469 -> V_210 = 0 ;
V_92 -> V_480 ++ ;
F_52 ( & V_469 -> V_87 ) ;
} else {
F_314 ( V_34 , L_11 ,
V_92 -> V_7 ,
V_35 , 1 ) ;
V_92 -> V_356 += V_35 ;
V_469 -> V_210 -= V_35 ;
V_35 = 0 ;
}
}
if ( V_35 && V_110 == & V_92 -> V_364 ) {
V_110 = & V_92 -> V_363 ;
goto V_162;
}
}
static void F_371 ( struct V_12 * V_34 ,
struct V_261 * V_447 ,
struct V_261 * V_492 , T_2 V_35 )
{
struct V_108 * V_92 = V_447 -> V_92 ;
F_11 ( & V_447 -> V_48 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_447 -> V_57 ;
V_447 -> V_57 -= V_35 ;
if ( V_447 -> V_10 >= V_447 -> V_57 ) {
V_35 = V_447 -> V_10 - V_447 -> V_57 ;
V_447 -> V_10 = V_447 -> V_57 ;
V_447 -> V_113 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_447 -> V_48 ) ;
if ( V_35 > 0 ) {
if ( V_492 ) {
F_11 ( & V_492 -> V_48 ) ;
if ( ! V_492 -> V_113 ) {
T_2 V_496 ;
V_496 = V_492 -> V_57 - V_492 -> V_10 ;
V_496 = F_344 ( V_35 , V_496 ) ;
V_492 -> V_10 += V_496 ;
if ( V_492 -> V_10 >= V_492 -> V_57 )
V_492 -> V_113 = 1 ;
V_35 -= V_496 ;
}
F_13 ( & V_492 -> V_48 ) ;
}
if ( V_35 )
F_370 ( V_34 , V_92 ,
V_35 ) ;
}
}
int F_372 ( struct V_261 * V_497 ,
struct V_261 * V_498 , T_2 V_35 ,
int V_491 )
{
int V_29 ;
V_29 = F_366 ( V_497 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_368 ( V_498 , V_35 , V_491 ) ;
return 0 ;
}
void F_373 ( struct V_261 * V_499 , unsigned short type )
{
memset ( V_499 , 0 , sizeof( * V_499 ) ) ;
F_293 ( & V_499 -> V_48 ) ;
V_499 -> type = type ;
}
struct V_261 * F_374 ( struct V_12 * V_34 ,
unsigned short type )
{
struct V_261 * V_447 ;
V_447 = F_223 ( sizeof( * V_447 ) , V_95 ) ;
if ( ! V_447 )
return NULL ;
F_373 ( V_447 , type ) ;
V_447 -> V_92 = F_77 ( V_34 ,
V_51 ) ;
return V_447 ;
}
void F_375 ( struct V_12 * V_34 ,
struct V_261 * V_499 )
{
if ( ! V_499 )
return;
F_376 ( V_34 , V_499 , ( T_2 ) - 1 ) ;
F_9 ( V_499 ) ;
}
void F_377 ( struct V_261 * V_499 )
{
F_9 ( V_499 ) ;
}
int F_334 ( struct V_61 * V_138 ,
struct V_261 * V_447 , T_2 V_35 ,
enum V_431 V_361 )
{
int V_29 ;
if ( V_35 == 0 )
return 0 ;
V_29 = F_364 ( V_138 , V_447 , V_35 , V_361 ) ;
if ( ! V_29 ) {
F_368 ( V_447 , V_35 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_378 ( struct V_261 * V_447 , int V_493 )
{
T_2 V_35 = 0 ;
int V_29 = - V_314 ;
if ( ! V_447 )
return 0 ;
F_11 ( & V_447 -> V_48 ) ;
V_35 = F_326 ( V_447 -> V_57 , V_493 ) ;
if ( V_447 -> V_10 >= V_35 )
V_29 = 0 ;
F_13 ( & V_447 -> V_48 ) ;
return V_29 ;
}
int F_379 ( struct V_61 * V_138 ,
struct V_261 * V_447 , T_2 V_500 ,
enum V_431 V_361 )
{
T_2 V_35 = 0 ;
int V_29 = - V_314 ;
if ( ! V_447 )
return 0 ;
F_11 ( & V_447 -> V_48 ) ;
V_35 = V_500 ;
if ( V_447 -> V_10 >= V_35 )
V_29 = 0 ;
else
V_35 -= V_447 -> V_10 ;
F_13 ( & V_447 -> V_48 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_364 ( V_138 , V_447 , V_35 , V_361 ) ;
if ( ! V_29 ) {
F_368 ( V_447 , V_35 , 0 ) ;
return 0 ;
}
return V_29 ;
}
void F_376 ( struct V_12 * V_34 ,
struct V_261 * V_447 ,
T_2 V_35 )
{
struct V_261 * V_262 = & V_34 -> V_265 ;
if ( V_262 == V_447 ||
V_447 -> V_92 != V_262 -> V_92 )
V_262 = NULL ;
F_371 ( V_34 , V_447 , V_262 , V_35 ) ;
}
static void F_380 ( struct V_12 * V_34 )
{
struct V_261 * V_447 = & V_34 -> V_265 ;
struct V_108 * V_412 = V_447 -> V_92 ;
T_2 V_35 ;
V_35 = F_381 ( & V_34 -> V_62 -> V_284 ) +
F_381 ( & V_34 -> V_487 -> V_284 ) +
F_381 ( & V_34 -> V_274 -> V_284 ) ;
V_35 = F_35 ( T_2 , V_35 , V_471 ) ;
F_11 ( & V_412 -> V_48 ) ;
F_11 ( & V_447 -> V_48 ) ;
V_447 -> V_57 = F_24 ( T_2 , V_35 , V_501 ) ;
if ( V_447 -> V_10 < V_447 -> V_57 ) {
V_35 = V_412 -> V_91 + V_412 -> V_354 +
V_412 -> V_355 + V_412 -> V_342 +
V_412 -> V_356 ;
if ( V_412 -> V_341 > V_35 ) {
V_35 = V_412 -> V_341 - V_35 ;
V_35 = F_344 ( V_35 ,
V_447 -> V_57 - V_447 -> V_10 ) ;
V_447 -> V_10 += V_35 ;
V_412 -> V_356 += V_35 ;
F_314 ( V_34 , L_11 ,
V_412 -> V_7 , V_35 ,
1 ) ;
}
} else if ( V_447 -> V_10 > V_447 -> V_57 ) {
V_35 = V_447 -> V_10 - V_447 -> V_57 ;
V_412 -> V_356 -= V_35 ;
F_314 ( V_34 , L_11 ,
V_412 -> V_7 , V_35 , 0 ) ;
V_447 -> V_10 = V_447 -> V_57 ;
}
if ( V_447 -> V_10 == V_447 -> V_57 )
V_447 -> V_113 = 1 ;
else
V_447 -> V_113 = 0 ;
F_13 ( & V_447 -> V_48 ) ;
F_13 ( & V_412 -> V_48 ) ;
}
static void F_382 ( struct V_12 * V_34 )
{
struct V_108 * V_92 ;
V_92 = F_77 ( V_34 , V_340 ) ;
V_34 -> V_424 . V_92 = V_92 ;
V_92 = F_77 ( V_34 , V_51 ) ;
V_34 -> V_265 . V_92 = V_92 ;
V_34 -> V_453 . V_92 = V_92 ;
V_34 -> V_502 . V_92 = V_92 ;
V_34 -> V_490 . V_92 = V_92 ;
V_34 -> V_459 . V_92 = V_92 ;
V_34 -> V_62 -> V_447 = & V_34 -> V_265 ;
V_34 -> V_487 -> V_447 = & V_34 -> V_265 ;
V_34 -> V_503 -> V_447 = & V_34 -> V_265 ;
V_34 -> V_274 -> V_447 = & V_34 -> V_265 ;
if ( V_34 -> V_504 )
V_34 -> V_504 -> V_447 = & V_34 -> V_265 ;
V_34 -> V_397 -> V_447 = & V_34 -> V_424 ;
F_380 ( V_34 ) ;
}
static void F_383 ( struct V_12 * V_34 )
{
F_371 ( V_34 , & V_34 -> V_265 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_34 -> V_453 . V_57 > 0 ) ;
F_8 ( V_34 -> V_453 . V_10 > 0 ) ;
F_8 ( V_34 -> V_502 . V_57 > 0 ) ;
F_8 ( V_34 -> V_502 . V_10 > 0 ) ;
F_8 ( V_34 -> V_424 . V_57 > 0 ) ;
F_8 ( V_34 -> V_424 . V_10 > 0 ) ;
F_8 ( V_34 -> V_459 . V_57 > 0 ) ;
F_8 ( V_34 -> V_459 . V_10 > 0 ) ;
}
void F_384 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
if ( ! V_115 -> V_447 )
return;
if ( ! V_115 -> V_355 )
return;
F_314 ( V_34 , L_15 ,
V_115 -> V_273 , V_115 -> V_355 , 0 ) ;
F_376 ( V_34 , V_115 -> V_447 ,
V_115 -> V_355 ) ;
V_115 -> V_355 = 0 ;
}
void F_336 ( struct V_114 * V_115 )
{
struct V_12 * V_34 = V_115 -> V_34 ;
if ( ! V_115 -> V_426 )
return;
F_385 ( ! F_183 ( & V_115 -> V_281 ) ) ;
F_371 ( V_34 , & V_34 -> V_424 , NULL ,
V_115 -> V_426 ) ;
V_115 -> V_426 = 0 ;
}
int F_386 ( struct V_114 * V_115 ,
struct V_298 * V_298 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
struct V_61 * V_138 = F_261 ( V_298 ) -> V_138 ;
struct V_261 * V_505 = V_115 -> V_447 ;
struct V_261 * V_506 = V_138 -> V_507 ;
T_2 V_35 = F_210 ( V_34 , 1 ) ;
F_314 ( V_34 , L_16 ,
F_387 ( V_298 ) , V_35 , 1 ) ;
return F_372 ( V_505 , V_506 , V_35 , 1 ) ;
}
void F_388 ( struct V_298 * V_298 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
struct V_61 * V_138 = F_261 ( V_298 ) -> V_138 ;
T_2 V_35 = F_210 ( V_34 , 1 ) ;
F_314 ( V_34 , L_16 ,
F_387 ( V_298 ) , V_35 , 0 ) ;
F_376 ( V_34 , V_138 -> V_507 , V_35 ) ;
}
int F_389 ( struct V_61 * V_138 ,
struct V_261 * V_499 ,
int V_451 ,
T_2 * V_229 ,
bool V_508 )
{
T_2 V_35 ;
int V_29 ;
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
if ( F_226 ( V_509 , & V_34 -> V_7 ) ) {
V_35 = 3 * V_34 -> V_52 ;
V_29 = F_390 ( V_138 , V_35 ) ;
if ( V_29 )
return V_29 ;
} else {
V_35 = 0 ;
}
* V_229 = V_35 ;
V_35 = F_210 ( V_34 , V_451 ) ;
V_499 -> V_92 = F_77 ( V_34 ,
V_51 ) ;
V_29 = F_334 ( V_138 , V_499 , V_35 ,
V_437 ) ;
if ( V_29 == - V_314 && V_508 )
V_29 = F_372 ( V_262 , V_499 , V_35 , 1 ) ;
if ( V_29 && * V_229 )
F_391 ( V_138 , * V_229 ) ;
return V_29 ;
}
void F_392 ( struct V_12 * V_34 ,
struct V_261 * V_499 ,
T_2 V_229 )
{
F_376 ( V_34 , V_499 , ( T_2 ) - 1 ) ;
}
static unsigned F_393 ( struct V_298 * V_298 , T_2 V_35 )
{
unsigned V_510 = 0 ;
unsigned V_511 = 0 ;
unsigned V_512 = 0 ;
V_512 = ( unsigned ) F_207 ( V_35 +
V_513 - 1 ,
V_513 ) ;
ASSERT ( V_512 ) ;
ASSERT ( F_261 ( V_298 ) -> V_514 >= V_512 ) ;
F_261 ( V_298 ) -> V_514 -= V_512 ;
if ( F_261 ( V_298 ) -> V_514 == 0 &&
F_394 ( V_515 ,
& F_261 ( V_298 ) -> V_516 ) )
V_510 = 1 ;
if ( F_261 ( V_298 ) -> V_514 >=
F_261 ( V_298 ) -> V_517 )
return V_510 ;
V_511 = F_261 ( V_298 ) -> V_517 -
F_261 ( V_298 ) -> V_514 ;
F_261 ( V_298 ) -> V_517 -= V_511 ;
return V_511 + V_510 ;
}
static T_2 F_395 ( struct V_298 * V_298 , T_2 V_35 ,
int V_518 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
T_2 V_519 , V_259 ;
if ( F_261 ( V_298 ) -> V_7 & V_520 &&
F_261 ( V_298 ) -> V_256 == 0 )
return 0 ;
V_519 = F_205 ( V_34 ,
F_261 ( V_298 ) -> V_256 ) ;
if ( V_518 )
F_261 ( V_298 ) -> V_256 += V_35 ;
else
F_261 ( V_298 ) -> V_256 -= V_35 ;
V_259 = F_205 ( V_34 ,
F_261 ( V_298 ) -> V_256 ) ;
if ( V_519 == V_259 )
return 0 ;
if ( V_518 )
return F_210 ( V_34 ,
V_259 - V_519 ) ;
return F_210 ( V_34 , V_519 - V_259 ) ;
}
int F_396 ( struct V_298 * V_298 , T_2 V_35 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
struct V_61 * V_138 = F_261 ( V_298 ) -> V_138 ;
struct V_261 * V_447 = & V_34 -> V_453 ;
T_2 V_521 = 0 ;
T_2 V_256 ;
unsigned V_522 = 0 ;
enum V_431 V_361 = V_437 ;
int V_29 = 0 ;
bool V_523 = true ;
T_2 V_524 = 0 ;
unsigned V_525 ;
bool V_526 = false ;
if ( F_308 ( V_298 ) ) {
V_361 = V_425 ;
V_523 = false ;
} else if ( V_401 -> V_402 ) {
V_361 = V_527 ;
}
if ( V_361 != V_425 &&
F_397 ( V_34 ) )
F_398 ( 1 ) ;
if ( V_523 )
F_49 ( & F_261 ( V_298 ) -> V_528 ) ;
V_35 = F_149 ( V_35 , V_34 -> V_53 ) ;
F_11 ( & F_261 ( V_298 ) -> V_48 ) ;
V_522 = ( unsigned ) F_207 ( V_35 +
V_513 - 1 ,
V_513 ) ;
F_261 ( V_298 ) -> V_514 += V_522 ;
V_522 = 0 ;
if ( F_261 ( V_298 ) -> V_514 >
F_261 ( V_298 ) -> V_517 )
V_522 += F_261 ( V_298 ) -> V_514 -
F_261 ( V_298 ) -> V_517 ;
V_521 = F_210 ( V_34 , V_522 + 1 ) ;
V_521 += F_395 ( V_298 , V_35 , 1 ) ;
V_256 = F_261 ( V_298 ) -> V_256 ;
F_13 ( & F_261 ( V_298 ) -> V_48 ) ;
if ( F_226 ( V_509 , & V_34 -> V_7 ) ) {
V_29 = F_390 ( V_138 ,
V_522 * V_34 -> V_52 ) ;
if ( V_29 )
goto V_529;
}
V_29 = F_334 ( V_138 , V_447 , V_521 , V_361 ) ;
if ( F_365 ( V_29 ) ) {
F_391 ( V_138 ,
V_522 * V_34 -> V_52 ) ;
goto V_529;
}
F_11 ( & F_261 ( V_298 ) -> V_48 ) ;
if ( F_399 ( V_515 ,
& F_261 ( V_298 ) -> V_516 ) ) {
V_521 -= F_210 ( V_34 , 1 ) ;
V_526 = true ;
}
F_261 ( V_298 ) -> V_517 += V_522 ;
F_13 ( & F_261 ( V_298 ) -> V_48 ) ;
if ( V_523 )
F_47 ( & F_261 ( V_298 ) -> V_528 ) ;
if ( V_521 )
F_314 ( V_34 , L_17 ,
F_387 ( V_298 ) , V_521 , 1 ) ;
if ( V_526 )
F_376 ( V_34 , V_447 ,
F_210 ( V_34 , 1 ) ) ;
return 0 ;
V_529:
F_11 ( & F_261 ( V_298 ) -> V_48 ) ;
V_525 = F_393 ( V_298 , V_35 ) ;
if ( F_261 ( V_298 ) -> V_256 == V_256 ) {
F_395 ( V_298 , V_35 , 0 ) ;
} else {
T_2 V_530 = F_261 ( V_298 ) -> V_256 ;
T_2 V_210 ;
V_210 = V_256 - F_261 ( V_298 ) -> V_256 ;
F_261 ( V_298 ) -> V_256 = V_256 ;
V_524 = F_395 ( V_298 , V_210 , 0 ) ;
F_261 ( V_298 ) -> V_256 = V_256 - V_35 ;
V_210 = V_256 - V_530 ;
V_210 = F_395 ( V_298 , V_210 , 0 ) ;
F_261 ( V_298 ) -> V_256 = V_530 - V_35 ;
if ( V_210 > V_524 )
V_524 = V_210 - V_524 ;
else
V_524 = 0 ;
}
F_13 ( & F_261 ( V_298 ) -> V_48 ) ;
if ( V_525 )
V_524 += F_210 ( V_34 , V_525 ) ;
if ( V_524 ) {
F_376 ( V_34 , V_447 , V_524 ) ;
F_314 ( V_34 , L_17 ,
F_387 ( V_298 ) , V_524 , 0 ) ;
}
if ( V_523 )
F_47 ( & F_261 ( V_298 ) -> V_528 ) ;
return V_29 ;
}
void F_400 ( struct V_298 * V_298 , T_2 V_35 )
{
struct V_12 * V_34 = F_315 ( V_298 -> V_410 ) ;
T_2 V_524 = 0 ;
unsigned V_525 ;
V_35 = F_149 ( V_35 , V_34 -> V_53 ) ;
F_11 ( & F_261 ( V_298 ) -> V_48 ) ;
V_525 = F_393 ( V_298 , V_35 ) ;
if ( V_35 )
V_524 = F_395 ( V_298 , V_35 , 0 ) ;
F_13 ( & F_261 ( V_298 ) -> V_48 ) ;
if ( V_525 > 0 )
V_524 += F_210 ( V_34 , V_525 ) ;
if ( F_242 ( V_34 ) )
return;
F_314 ( V_34 , L_17 ,
F_387 ( V_298 ) , V_524 , 0 ) ;
F_376 ( V_34 , & V_34 -> V_453 , V_524 ) ;
}
int F_401 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_45 )
{
int V_29 ;
V_29 = F_266 ( V_298 , V_32 , V_45 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_396 ( V_298 , V_45 ) ;
if ( V_29 < 0 )
F_319 ( V_298 , V_32 , V_45 ) ;
return V_29 ;
}
void F_402 ( struct V_298 * V_298 , T_2 V_32 , T_2 V_45 )
{
F_400 ( V_298 , V_45 ) ;
F_319 ( V_298 , V_32 , V_45 ) ;
}
static int F_403 ( struct V_114 * V_115 ,
struct V_12 * V_13 , T_2 V_27 ,
T_2 V_35 , int V_403 )
{
struct V_1 * V_2 = NULL ;
T_2 V_531 = V_35 ;
T_2 V_532 ;
T_2 V_533 ;
int V_343 ;
F_11 ( & V_13 -> V_534 ) ;
V_532 = F_404 ( V_13 -> V_260 ) ;
if ( V_403 )
V_532 += V_35 ;
else
V_532 -= V_35 ;
F_405 ( V_13 -> V_260 , V_532 ) ;
F_13 ( & V_13 -> V_534 ) ;
while ( V_531 ) {
V_2 = F_76 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_159 ;
if ( V_2 -> V_7 & ( V_344 |
V_345 |
V_346 ) )
V_343 = 2 ;
else
V_343 = 1 ;
if ( ! V_403 && V_2 -> V_3 == V_100 )
F_59 ( V_2 , 1 ) ;
V_533 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_533 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( F_265 ( V_13 , V_312 ) &&
V_2 -> V_305 < V_321 )
V_2 -> V_305 = V_321 ;
V_532 = F_58 ( & V_2 -> V_93 ) ;
V_35 = F_344 ( V_531 , V_2 -> V_21 . V_33 - V_533 ) ;
if ( V_403 ) {
V_532 += V_35 ;
F_406 ( & V_2 -> V_93 , V_532 ) ;
V_2 -> V_10 -= V_35 ;
V_2 -> V_92 -> V_355 -= V_35 ;
V_2 -> V_92 -> V_91 += V_35 ;
V_2 -> V_92 -> V_348 += V_35 * V_343 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
} else {
V_532 -= V_35 ;
F_406 ( & V_2 -> V_93 , V_532 ) ;
V_2 -> V_9 += V_35 ;
V_2 -> V_92 -> V_354 += V_35 ;
V_2 -> V_92 -> V_91 -= V_35 ;
V_2 -> V_92 -> V_348 -= V_35 * V_343 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
F_314 ( V_13 , L_18 ,
V_2 -> V_92 -> V_7 ,
V_35 , 1 ) ;
F_407 ( V_13 -> V_59 ,
V_27 , V_27 + V_35 - 1 ,
V_95 | V_535 ) ;
}
F_11 ( & V_115 -> V_132 -> V_328 ) ;
if ( F_183 ( & V_2 -> V_330 ) ) {
F_72 ( & V_2 -> V_330 ,
& V_115 -> V_132 -> V_320 ) ;
V_115 -> V_132 -> V_263 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_115 -> V_132 -> V_328 ) ;
if ( ! V_403 && V_532 == 0 ) {
F_11 ( & V_13 -> V_536 ) ;
if ( F_183 ( & V_2 -> V_537 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_537 ,
& V_13 -> V_538 ) ;
}
F_13 ( & V_13 -> V_536 ) ;
}
F_6 ( V_2 ) ;
V_531 -= V_35 ;
V_27 += V_35 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_12 * V_34 , T_2 V_539 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_34 -> V_18 ) ;
V_27 = V_34 -> V_26 ;
F_13 ( & V_34 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_75 ( V_34 , V_539 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_408 ( struct V_12 * V_34 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_35 , int V_10 )
{
F_11 ( & V_2 -> V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
V_2 -> V_9 += V_35 ;
V_2 -> V_92 -> V_354 += V_35 ;
if ( V_10 ) {
V_2 -> V_10 -= V_35 ;
V_2 -> V_92 -> V_355 -= V_35 ;
}
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
F_314 ( V_34 , L_18 ,
V_2 -> V_92 -> V_7 , V_35 , 1 ) ;
F_407 ( V_34 -> V_59 , V_27 ,
V_27 + V_35 - 1 , V_95 | V_535 ) ;
return 0 ;
}
int F_176 ( struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_34 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_408 ( V_34 , V_2 , V_27 , V_35 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_409 ( struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_76 ( V_34 , V_27 ) ;
if ( ! V_2 )
return - V_540 ;
F_59 ( V_2 , 1 ) ;
F_408 ( V_34 , V_2 , V_27 , V_35 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_35 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_410 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_35 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_46 * V_49 ;
V_14 = F_76 ( V_34 , V_32 ) ;
if ( ! V_14 )
return - V_540 ;
F_59 ( V_14 , 0 ) ;
V_49 = F_25 ( V_14 ) ;
if ( ! V_49 ) {
F_32 ( ! F_1 ( V_14 ) ) ;
V_29 = F_28 ( V_14 , V_32 , V_35 ) ;
} else {
F_49 ( & V_49 -> V_84 ) ;
if ( V_32 >= V_49 -> V_83 ) {
V_29 = F_17 ( V_34 , V_32 , V_35 ) ;
} else if ( V_32 + V_35 <= V_49 -> V_83 ) {
V_29 = F_28 ( V_14 ,
V_32 , V_35 ) ;
} else {
V_35 = V_49 -> V_83 - V_32 ;
V_29 = F_28 ( V_14 ,
V_32 , V_35 ) ;
if ( V_29 )
goto V_541;
V_35 = ( V_32 + V_35 ) -
V_49 -> V_83 ;
V_32 = V_49 -> V_83 ;
V_29 = F_17 ( V_34 , V_32 , V_35 ) ;
}
V_541:
F_47 ( & V_49 -> V_84 ) ;
F_26 ( V_49 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_411 ( struct V_12 * V_34 ,
struct V_65 * V_542 )
{
struct V_290 * V_93 ;
struct V_67 V_21 ;
int V_543 ;
int V_40 ;
if ( ! F_84 ( V_34 , V_544 ) )
return 0 ;
for ( V_40 = 0 ; V_40 < F_39 ( V_542 ) ; V_40 ++ ) {
F_41 ( V_542 , & V_21 , V_40 ) ;
if ( V_21 . type != V_295 )
continue;
V_93 = F_86 ( V_542 , V_40 , struct V_290 ) ;
V_543 = F_245 ( V_542 , V_93 ) ;
if ( V_543 == V_296 )
continue;
if ( F_246 ( V_542 , V_93 ) == 0 )
continue;
V_21 . V_22 = F_246 ( V_542 , V_93 ) ;
V_21 . V_33 = F_247 ( V_542 , V_93 ) ;
F_410 ( V_34 , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static void
F_412 ( struct V_1 * V_336 )
{
F_5 ( & V_336 -> V_545 ) ;
}
void F_413 ( struct V_12 * V_34 ,
const T_2 V_32 )
{
struct V_1 * V_336 ;
V_336 = F_76 ( V_34 , V_32 ) ;
ASSERT ( V_336 ) ;
if ( F_7 ( & V_336 -> V_545 ) )
F_284 ( & V_336 -> V_545 ) ;
F_6 ( V_336 ) ;
}
static int F_414 ( T_7 * V_338 )
{
F_68 () ;
return 0 ;
}
void F_415 ( struct V_1 * V_336 )
{
struct V_108 * V_92 = V_336 -> V_92 ;
ASSERT ( V_336 -> V_307 ) ;
if ( ! ( V_336 -> V_7 & V_339 ) )
return;
F_71 ( & V_92 -> V_353 ) ;
F_73 ( & V_92 -> V_353 ) ;
F_287 ( & V_336 -> V_545 ,
F_414 ,
V_99 ) ;
}
static int F_416 ( struct V_1 * V_2 ,
T_2 V_546 , T_2 V_35 , int V_547 )
{
struct V_108 * V_92 = V_2 -> V_92 ;
int V_29 = 0 ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_307 ) {
V_29 = - V_185 ;
} else {
V_2 -> V_10 += V_35 ;
V_92 -> V_355 += V_35 ;
F_314 ( V_2 -> V_34 ,
L_11 , V_92 -> V_7 ,
V_546 , 0 ) ;
V_92 -> V_356 -= V_546 ;
if ( V_547 )
V_2 -> V_448 += V_35 ;
}
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
static int F_417 ( struct V_1 * V_2 ,
T_2 V_35 , int V_547 )
{
struct V_108 * V_92 = V_2 -> V_92 ;
int V_29 = 0 ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_307 )
V_92 -> V_342 += V_35 ;
V_2 -> V_10 -= V_35 ;
V_92 -> V_355 -= V_35 ;
if ( V_547 )
V_2 -> V_448 -= V_35 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
void F_418 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_46 * V_78 ;
struct V_46 * V_49 ;
struct V_1 * V_2 ;
F_71 ( & V_34 -> V_82 ) ;
F_271 (caching_ctl, next,
&fs_info->caching_block_groups, list) {
V_2 = V_49 -> V_14 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_103 = ( T_2 ) - 1 ;
F_275 ( & V_49 -> V_96 ) ;
F_26 ( V_49 ) ;
} else {
V_2 -> V_103 = V_49 -> V_83 ;
}
}
if ( V_34 -> V_59 == & V_34 -> V_36 [ 0 ] )
V_34 -> V_59 = & V_34 -> V_36 [ 1 ] ;
else
V_34 -> V_59 = & V_34 -> V_36 [ 0 ] ;
F_73 ( & V_34 -> V_82 ) ;
F_380 ( V_34 ) ;
}
static struct V_548 *
F_419 ( struct V_12 * V_34 ,
struct V_108 * V_92 , T_2 * V_549 )
{
struct V_548 * V_29 = NULL ;
bool V_550 = F_265 ( V_34 , V_551 ) ;
* V_549 = 0 ;
if ( F_335 ( V_92 ) )
return V_29 ;
if ( V_550 )
* V_549 = V_418 ;
if ( V_92 -> V_7 & V_51 ) {
V_29 = & V_34 -> V_552 ;
if ( ! V_550 )
* V_549 = V_553 ;
} else if ( ( V_92 -> V_7 & V_339 ) && V_550 ) {
V_29 = & V_34 -> V_554 ;
}
return V_29 ;
}
static int F_420 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_31 ,
const bool V_555 )
{
struct V_1 * V_2 = NULL ;
struct V_108 * V_92 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
struct V_548 * V_556 = NULL ;
T_2 V_45 ;
T_2 V_557 = 0 ;
T_2 V_549 = 0 ;
bool V_335 ;
while ( V_32 <= V_31 ) {
V_335 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_557 = 0 ;
V_2 = F_76 ( V_34 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_556 = F_419 ( V_34 ,
V_2 -> V_92 ,
& V_549 ) ;
V_549 <<= 1 ;
}
V_45 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_45 = F_344 ( V_45 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_103 ) {
V_45 = F_344 ( V_45 , V_2 -> V_103 - V_32 ) ;
if ( V_555 )
F_31 ( V_2 , V_32 , V_45 ) ;
}
V_32 += V_45 ;
V_557 += V_45 ;
V_92 = V_2 -> V_92 ;
if ( V_556 && V_556 -> V_558 &&
V_557 > V_549 ) {
F_11 ( & V_556 -> V_48 ) ;
V_556 -> V_558 = 0 ;
F_13 ( & V_556 -> V_48 ) ;
}
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
V_2 -> V_9 -= V_45 ;
V_92 -> V_354 -= V_45 ;
F_314 ( V_34 , L_18 ,
V_92 -> V_7 , V_45 , 0 ) ;
V_92 -> V_357 = 0 ;
F_421 ( & V_92 -> V_349 , - V_45 ) ;
if ( V_2 -> V_307 ) {
V_92 -> V_342 += V_45 ;
V_335 = true ;
}
F_13 ( & V_2 -> V_48 ) ;
if ( ! V_335 && V_555 &&
V_262 -> V_92 == V_92 ) {
T_2 V_559 = V_45 ;
F_8 ( ! V_555 ) ;
F_11 ( & V_262 -> V_48 ) ;
if ( ! V_262 -> V_113 ) {
V_559 = F_344 ( V_45 , V_262 -> V_57 -
V_262 -> V_10 ) ;
V_262 -> V_10 += V_559 ;
V_92 -> V_356 += V_559 ;
if ( V_262 -> V_10 >= V_262 -> V_57 )
V_262 -> V_113 = 1 ;
F_314 ( V_34 ,
L_11 ,
V_92 -> V_7 ,
V_559 , 1 ) ;
V_45 -= V_559 ;
}
F_13 ( & V_262 -> V_48 ) ;
if ( V_45 )
F_290 ( V_34 , V_92 ,
V_45 ) ;
}
F_13 ( & V_92 -> V_48 ) ;
}
if ( V_2 )
F_6 ( V_2 ) ;
return 0 ;
}
int F_422 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_14 , * V_317 ;
struct V_109 * V_560 ;
struct V_561 * V_562 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_34 -> V_59 == & V_34 -> V_36 [ 0 ] )
V_562 = & V_34 -> V_36 [ 1 ] ;
else
V_562 = & V_34 -> V_36 [ 0 ] ;
while ( ! V_115 -> V_226 ) {
F_49 ( & V_34 -> V_563 ) ;
V_29 = F_30 ( V_562 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 ) {
F_47 ( & V_34 -> V_563 ) ;
break;
}
if ( F_265 ( V_34 , V_564 ) )
V_29 = F_153 ( V_34 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_423 ( V_562 , V_32 , V_31 ) ;
F_420 ( V_34 , V_32 , V_31 , true ) ;
F_47 ( & V_34 -> V_563 ) ;
F_48 () ;
}
V_560 = & V_115 -> V_132 -> V_560 ;
F_271 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_565 = 0 ;
V_29 = - V_566 ;
if ( ! V_115 -> V_226 )
V_29 = F_153 ( V_34 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_565 ) ;
F_275 ( & V_14 -> V_537 ) ;
F_424 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_567 = F_425 ( V_29 ) ;
F_426 ( V_34 ,
L_19 ,
V_29 , V_567 ) ;
}
}
return 0 ;
}
static void F_427 ( struct V_12 * V_34 , T_2 V_35 ,
T_2 V_139 , T_2 V_151 )
{
struct V_108 * V_92 ;
T_2 V_7 ;
if ( V_139 < V_148 ) {
if ( V_151 == V_568 )
V_7 = V_340 ;
else
V_7 = V_51 ;
} else {
V_7 = V_339 ;
}
V_92 = F_77 ( V_34 , V_7 ) ;
F_32 ( ! V_92 ) ;
F_421 ( & V_92 -> V_349 , V_35 ) ;
}
static int F_167 ( struct V_114 * V_115 ,
struct V_12 * V_13 ,
struct V_217 * V_133 , T_2 V_17 ,
T_2 V_151 , T_2 V_569 ,
T_2 V_570 , int V_166 ,
struct V_187 * V_134 )
{
struct V_67 V_21 ;
struct V_63 * V_64 ;
struct V_61 * V_62 = V_13 -> V_62 ;
struct V_65 * V_66 ;
struct V_121 * V_122 ;
struct V_170 * V_171 ;
int V_29 ;
int V_191 ;
int V_571 = 0 ;
int V_572 = 0 ;
int V_573 = 1 ;
T_3 V_123 ;
T_2 V_117 ;
T_2 V_27 = V_133 -> V_27 ;
T_2 V_35 = V_133 -> V_35 ;
int V_167 = 0 ;
bool V_180 = F_84 ( V_13 , V_126 ) ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_64 -> V_75 = V_76 ;
V_64 -> V_218 = 1 ;
V_191 = V_569 >= V_148 ;
F_32 ( ! V_191 && V_166 != 1 ) ;
if ( V_191 )
V_180 = 0 ;
V_29 = F_142 ( V_115 , V_62 , V_64 , & V_171 ,
V_27 , V_35 , V_17 ,
V_151 , V_569 ,
V_570 ) ;
if ( V_29 == 0 ) {
V_571 = V_64 -> V_81 [ 0 ] ;
while ( V_571 >= 0 ) {
F_41 ( V_64 -> V_80 [ 0 ] , & V_21 ,
V_571 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_35 ) {
V_572 = 1 ;
break;
}
if ( V_21 . type == V_85 &&
V_21 . V_33 == V_569 ) {
V_572 = 1 ;
break;
}
if ( V_64 -> V_81 [ 0 ] - V_571 > 5 )
break;
V_571 -- ;
}
#ifdef F_89
V_123 = F_85 ( V_64 -> V_80 [ 0 ] , V_571 ) ;
if ( V_572 && V_123 < sizeof( * V_122 ) )
V_572 = 0 ;
#endif
if ( ! V_572 ) {
F_32 ( V_171 ) ;
V_29 = F_147 ( V_115 , V_62 , V_64 ,
NULL , V_166 ,
V_191 , & V_167 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
F_45 ( V_64 ) ;
V_64 -> V_218 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 ;
if ( ! V_191 && V_180 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_569 ;
}
V_29 = F_38 ( V_115 , V_62 ,
& V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 && V_180 && V_64 -> V_81 [ 0 ] ) {
V_64 -> V_81 [ 0 ] -- ;
F_41 ( V_64 -> V_80 [ 0 ] , & V_21 ,
V_64 -> V_81 [ 0 ] ) ;
if ( V_21 . V_22 == V_27 &&
V_21 . type == V_77 &&
V_21 . V_33 == V_35 )
V_29 = 0 ;
}
if ( V_29 > 0 && V_180 ) {
V_180 = false ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 ;
F_45 ( V_64 ) ;
V_29 = F_38 ( V_115 , V_62 ,
& V_21 , V_64 , - 1 , 1 ) ;
}
if ( V_29 ) {
F_173 ( V_13 ,
L_20 ,
V_29 , V_27 ) ;
if ( V_29 > 0 )
F_428 ( V_13 , V_64 -> V_80 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_571 = V_64 -> V_81 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_159 ) ) {
F_428 ( V_13 , V_64 -> V_80 [ 0 ] ) ;
F_173 ( V_13 ,
L_21 ,
V_27 , V_17 , V_151 , V_569 ,
V_570 ) ;
F_162 ( V_115 , V_29 ) ;
goto V_79;
} else {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_571 ) ;
#ifdef F_89
if ( V_123 < sizeof( * V_122 ) ) {
F_32 ( V_572 || V_571 != V_64 -> V_81 [ 0 ] ) ;
V_29 = F_95 ( V_115 , V_62 , V_64 ,
V_569 , 0 ) ;
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
F_45 ( V_64 ) ;
V_64 -> V_218 = 1 ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 ;
V_29 = F_38 ( V_115 , V_62 , & V_21 , V_64 ,
- 1 , 1 ) ;
if ( V_29 ) {
F_173 ( V_13 ,
L_20 ,
V_29 , V_27 ) ;
F_428 ( V_13 , V_64 -> V_80 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_571 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_571 ) ;
}
#endif
F_32 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_86 ( V_66 , V_571 ,
struct V_121 ) ;
if ( V_569 < V_148 &&
V_21 . type == V_77 ) {
struct V_143 * V_144 ;
F_32 ( V_123 < sizeof( * V_122 ) + sizeof( * V_144 ) ) ;
V_144 = (struct V_143 * ) ( V_122 + 1 ) ;
F_8 ( V_569 != F_429 ( V_66 , V_144 ) ) ;
}
V_117 = F_87 ( V_66 , V_122 ) ;
if ( V_117 < V_166 ) {
F_173 ( V_13 ,
L_22 ,
V_166 , V_117 , V_27 ) ;
V_29 = - V_540 ;
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_117 -= V_166 ;
if ( V_117 > 0 ) {
if ( V_134 )
F_138 ( V_134 , V_66 , V_122 ) ;
if ( V_171 ) {
F_32 ( ! V_572 ) ;
} else {
F_98 ( V_66 , V_122 , V_117 ) ;
F_103 ( V_66 ) ;
}
if ( V_572 ) {
V_29 = F_147 ( V_115 , V_62 , V_64 ,
V_171 , V_166 ,
V_191 , & V_167 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
}
F_427 ( V_13 , - V_35 , V_569 ,
V_151 ) ;
} else {
if ( V_572 ) {
F_32 ( V_191 && V_166 !=
F_126 ( V_64 , V_171 ) ) ;
if ( V_171 ) {
F_32 ( V_64 -> V_81 [ 0 ] != V_571 ) ;
} else {
F_32 ( V_64 -> V_81 [ 0 ] != V_571 + 1 ) ;
V_64 -> V_81 [ 0 ] = V_571 ;
V_573 = 2 ;
}
}
V_167 = 1 ;
V_29 = F_430 ( V_115 , V_62 , V_64 , V_64 -> V_81 [ 0 ] ,
V_573 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
F_45 ( V_64 ) ;
if ( V_191 ) {
V_29 = F_180 ( V_115 , V_13 , V_27 , V_35 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
}
V_29 = F_431 ( V_115 , V_13 , V_27 , V_35 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_29 = F_403 ( V_115 , V_13 , V_27 , V_35 , 0 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
}
F_45 ( V_64 ) ;
V_79:
F_53 ( V_64 ) ;
return V_29 ;
}
static T_1 int F_432 ( struct V_114 * V_115 ,
T_2 V_27 )
{
struct V_118 * V_110 ;
struct V_119 * V_120 ;
int V_29 = 0 ;
V_120 = & V_115 -> V_132 -> V_120 ;
F_11 ( & V_120 -> V_48 ) ;
V_110 = F_92 ( V_115 , V_27 ) ;
if ( ! V_110 )
goto V_574;
F_11 ( & V_110 -> V_48 ) ;
if ( ! F_183 ( & V_110 -> V_230 ) )
goto V_79;
if ( V_110 -> V_134 ) {
if ( ! V_110 -> V_235 )
goto V_79;
F_192 ( V_110 -> V_134 ) ;
V_110 -> V_134 = NULL ;
}
if ( ! F_93 ( & V_110 -> V_84 ) )
goto V_79;
V_110 -> V_133 . V_239 = 0 ;
F_194 ( & V_110 -> V_241 , & V_120 -> V_242 ) ;
F_196 ( & V_120 -> V_243 ) ;
V_120 -> V_240 -- ;
if ( V_110 -> V_237 == 0 )
V_120 -> V_238 -- ;
V_110 -> V_237 = 0 ;
F_13 ( & V_110 -> V_48 ) ;
F_13 ( & V_120 -> V_48 ) ;
F_32 ( V_110 -> V_134 ) ;
if ( V_110 -> V_235 )
V_29 = 1 ;
F_47 ( & V_110 -> V_84 ) ;
F_94 ( & V_110 -> V_133 ) ;
return V_29 ;
V_79:
F_13 ( & V_110 -> V_48 ) ;
V_574:
F_13 ( & V_120 -> V_48 ) ;
return 0 ;
}
void F_433 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_65 * V_287 ,
T_2 V_17 , int V_167 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
int V_575 = 1 ;
int V_29 ;
if ( V_138 -> V_283 . V_22 != V_215 ) {
V_29 = F_159 ( V_34 , V_115 ,
V_287 -> V_32 , V_287 -> V_45 ,
V_17 ,
V_138 -> V_283 . V_22 ,
F_244 ( V_287 ) ,
V_224 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_167 )
return;
if ( F_434 ( V_287 ) == V_115 -> V_273 ) {
struct V_1 * V_2 ;
if ( V_138 -> V_283 . V_22 != V_215 ) {
V_29 = F_432 ( V_115 , V_287 -> V_32 ) ;
if ( ! V_29 )
goto V_79;
}
V_2 = F_76 ( V_34 , V_287 -> V_32 ) ;
if ( F_435 ( V_287 , V_576 ) ) {
F_408 ( V_34 , V_2 , V_287 -> V_32 ,
V_287 -> V_45 , 1 ) ;
F_6 ( V_2 ) ;
goto V_79;
}
F_8 ( F_226 ( V_577 , & V_287 -> V_578 ) ) ;
F_31 ( V_2 , V_287 -> V_32 , V_287 -> V_45 ) ;
F_417 ( V_2 , V_287 -> V_45 , 0 ) ;
F_6 ( V_2 ) ;
F_436 ( V_34 , V_287 -> V_32 , V_287 -> V_45 ) ;
V_575 = 0 ;
}
V_79:
if ( V_575 )
F_427 ( V_34 , V_287 -> V_45 , F_244 ( V_287 ) ,
V_138 -> V_283 . V_22 ) ;
F_437 ( V_579 , & V_287 -> V_578 ) ;
}
int V_294 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 , T_2 V_151 ,
T_2 V_139 , T_2 V_33 )
{
int V_29 ;
if ( F_242 ( V_34 ) )
return 0 ;
F_427 ( V_34 , V_35 , V_139 , V_151 ) ;
if ( V_151 == V_215 ) {
F_8 ( V_139 >= V_148 ) ;
F_176 ( V_34 , V_27 , V_35 , 1 ) ;
V_29 = 0 ;
} else if ( V_139 < V_148 ) {
V_29 = F_159 ( V_34 , V_115 , V_27 ,
V_35 ,
V_17 , V_151 , ( int ) V_139 ,
V_224 , NULL ) ;
} else {
V_29 = F_160 ( V_34 , V_115 , V_27 ,
V_35 ,
V_17 , V_151 , V_139 ,
V_33 , 0 ,
V_224 , NULL ) ;
}
return V_29 ;
}
static T_1 void
F_438 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_46 * V_49 ;
V_49 = F_25 ( V_2 ) ;
if ( ! V_49 )
return;
F_280 ( V_49 -> V_87 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_580 >= V_35 ) ) ;
F_26 ( V_49 ) ;
}
static T_1 int
F_439 ( struct V_1 * V_2 )
{
struct V_46 * V_49 ;
int V_29 = 0 ;
V_49 = F_25 ( V_2 ) ;
if ( ! V_49 )
return ( V_2 -> V_3 == V_5 ) ? - V_182 : 0 ;
F_280 ( V_49 -> V_87 , F_1 ( V_2 ) ) ;
if ( V_2 -> V_3 == V_5 )
V_29 = - V_182 ;
F_26 ( V_49 ) ;
return V_29 ;
}
int F_440 ( T_2 V_7 )
{
if ( V_7 & V_346 )
return V_581 ;
else if ( V_7 & V_345 )
return V_582 ;
else if ( V_7 & V_344 )
return V_583 ;
else if ( V_7 & V_394 )
return V_584 ;
else if ( V_7 & V_393 )
return V_585 ;
else if ( V_7 & V_392 )
return V_586 ;
return V_587 ;
}
int F_441 ( struct V_1 * V_2 )
{
return F_440 ( V_2 -> V_7 ) ;
}
static const char * F_442 ( enum V_588 type )
{
if ( type >= V_351 )
return NULL ;
return V_589 [ type ] ;
}
static inline void
F_443 ( struct V_1 * V_2 ,
int V_547 )
{
if ( V_547 )
F_50 ( & V_2 -> V_590 ) ;
}
static inline void
F_444 ( struct V_1 * V_2 ,
int V_547 )
{
F_4 ( V_2 ) ;
if ( V_547 )
F_50 ( & V_2 -> V_590 ) ;
}
static struct V_1 *
F_445 ( struct V_1 * V_14 ,
struct V_548 * V_556 ,
int V_547 )
{
struct V_1 * V_591 = NULL ;
F_11 ( & V_556 -> V_592 ) ;
while ( 1 ) {
V_591 = V_556 -> V_14 ;
if ( ! V_591 )
return NULL ;
if ( V_591 == V_14 )
return V_591 ;
F_4 ( V_591 ) ;
if ( ! V_547 )
return V_591 ;
if ( F_339 ( & V_591 -> V_590 ) )
return V_591 ;
F_13 ( & V_556 -> V_592 ) ;
F_446 ( & V_591 -> V_590 , V_593 ) ;
F_11 ( & V_556 -> V_592 ) ;
if ( V_591 == V_556 -> V_14 )
return V_591 ;
F_46 ( & V_591 -> V_590 ) ;
F_6 ( V_591 ) ;
}
}
static inline void
F_447 ( struct V_1 * V_2 ,
int V_547 )
{
if ( V_547 )
F_46 ( & V_2 -> V_590 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_448 ( struct V_61 * V_594 ,
T_2 V_546 , T_2 V_35 , T_2 V_595 ,
T_2 V_596 , struct V_67 * V_221 ,
T_2 V_7 , int V_547 )
{
struct V_12 * V_34 = V_594 -> V_34 ;
int V_29 = 0 ;
struct V_61 * V_138 = V_34 -> V_62 ;
struct V_548 * V_597 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_539 = 0 ;
T_2 V_357 = 0 ;
T_2 V_549 = 0 ;
struct V_108 * V_92 ;
int V_598 = 0 ;
int V_599 = F_440 ( V_7 ) ;
bool V_600 = false ;
bool V_601 = false ;
bool V_602 = true ;
bool V_603 = false ;
bool V_604 = false ;
bool V_605 = false ;
F_8 ( V_35 < V_34 -> V_53 ) ;
V_221 -> type = V_77 ;
V_221 -> V_22 = 0 ;
V_221 -> V_33 = 0 ;
F_449 ( V_34 , V_35 , V_595 , V_7 ) ;
V_92 = F_77 ( V_34 , V_7 ) ;
if ( ! V_92 ) {
F_173 ( V_34 , L_23 , V_7 ) ;
return - V_314 ;
}
if ( F_365 ( V_92 -> V_357 ) ) {
F_11 ( & V_92 -> V_48 ) ;
if ( V_92 -> V_357 &&
V_35 > V_92 -> V_357 ) {
V_221 -> V_33 = V_92 -> V_357 ;
F_13 ( & V_92 -> V_48 ) ;
return - V_314 ;
} else if ( V_92 -> V_357 ) {
V_602 = false ;
}
F_13 ( & V_92 -> V_48 ) ;
}
V_597 = F_419 ( V_34 , V_92 , & V_549 ) ;
if ( V_597 ) {
F_11 ( & V_597 -> V_48 ) ;
if ( V_597 -> V_14 )
V_596 = V_597 -> V_606 ;
if ( V_597 -> V_558 ) {
V_596 = V_597 -> V_606 ;
V_602 = false ;
}
F_13 ( & V_597 -> V_48 ) ;
}
V_539 = F_450 ( V_539 , V_26 ( V_34 , 0 ) ) ;
V_539 = F_450 ( V_539 , V_596 ) ;
if ( V_539 == V_596 ) {
V_14 = F_76 ( V_34 , V_539 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_100 ) {
F_50 ( & V_92 -> V_353 ) ;
if ( F_183 ( & V_14 -> V_96 ) ||
V_14 -> V_307 ) {
F_6 ( V_14 ) ;
F_46 ( & V_92 -> V_353 ) ;
} else {
V_599 = F_441 ( V_14 ) ;
F_443 ( V_14 , V_547 ) ;
goto V_607;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_608:
V_603 = false ;
if ( V_599 == 0 || V_599 == F_440 ( V_7 ) )
V_605 = true ;
F_50 ( & V_92 -> V_353 ) ;
F_235 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_444 ( V_14 , V_547 ) ;
V_539 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_609 = V_344 |
V_345 |
V_393 |
V_392 |
V_346 ;
if ( ( V_7 & V_609 ) && ! ( V_14 -> V_7 & V_609 ) )
goto V_598;
}
V_607:
V_3 = F_1 ( V_14 ) ;
if ( F_365 ( ! V_3 ) ) {
V_603 = true ;
V_29 = F_59 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_365 ( V_14 -> V_3 == V_5 ) )
goto V_598;
if ( F_365 ( V_14 -> V_307 ) )
goto V_598;
if ( V_597 && V_602 ) {
struct V_1 * V_610 ;
unsigned long V_611 ;
V_610 = F_445 ( V_14 ,
V_597 ,
V_547 ) ;
if ( ! V_610 )
goto V_612;
if ( V_610 != V_14 &&
( V_610 -> V_307 ||
! F_3 ( V_610 , V_7 ) ) )
goto V_613;
V_33 = F_451 ( V_610 ,
V_597 ,
V_35 ,
V_610 -> V_21 . V_22 ,
& V_357 ) ;
if ( V_33 ) {
F_13 ( & V_597 -> V_592 ) ;
F_452 ( V_34 ,
V_610 ,
V_539 , V_35 ) ;
if ( V_610 != V_14 ) {
F_447 ( V_14 ,
V_547 ) ;
V_14 = V_610 ;
}
goto V_614;
}
F_8 ( V_597 -> V_14 != V_610 ) ;
V_613:
if ( V_598 >= V_615 &&
V_610 != V_14 ) {
F_13 ( & V_597 -> V_592 ) ;
F_447 ( V_610 ,
V_547 ) ;
goto V_616;
}
F_453 ( NULL , V_597 ) ;
if ( V_610 != V_14 )
F_447 ( V_610 ,
V_547 ) ;
V_612:
if ( V_598 >= V_615 ) {
F_13 ( & V_597 -> V_592 ) ;
goto V_616;
}
V_611 = F_35 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_454 ( V_34 , V_14 ,
V_597 , V_539 ,
V_35 ,
V_611 ) ;
if ( V_29 == 0 ) {
V_33 = F_451 ( V_14 ,
V_597 ,
V_35 ,
V_539 ,
& V_357 ) ;
if ( V_33 ) {
F_13 ( & V_597 -> V_592 ) ;
F_452 ( V_34 ,
V_14 , V_539 ,
V_35 ) ;
goto V_614;
}
} else if ( ! V_3 && V_598 > V_617
&& ! V_600 ) {
F_13 ( & V_597 -> V_592 ) ;
V_600 = true ;
F_438 ( V_14 ,
V_35 + V_549 + V_595 ) ;
goto V_607;
}
F_453 ( NULL , V_597 ) ;
F_13 ( & V_597 -> V_592 ) ;
goto V_598;
}
V_616:
if ( F_365 ( V_597 ) ) {
F_11 ( & V_597 -> V_48 ) ;
V_597 -> V_558 = 1 ;
F_13 ( & V_597 -> V_48 ) ;
}
F_11 ( & V_14 -> V_11 -> V_618 ) ;
if ( V_3 &&
V_14 -> V_11 -> V_580 <
V_35 + V_549 + V_595 ) {
if ( V_14 -> V_11 -> V_580 >
V_357 )
V_357 =
V_14 -> V_11 -> V_580 ;
F_13 ( & V_14 -> V_11 -> V_618 ) ;
goto V_598;
}
F_13 ( & V_14 -> V_11 -> V_618 ) ;
V_33 = F_455 ( V_14 , V_539 ,
V_35 , V_595 ,
& V_357 ) ;
if ( ! V_33 && ! V_601 && ! V_3 &&
V_598 > V_617 ) {
F_438 ( V_14 ,
V_35 + V_595 ) ;
V_601 = true ;
goto V_607;
} else if ( ! V_33 ) {
goto V_598;
}
V_614:
V_539 = F_149 ( V_33 , V_34 -> V_619 ) ;
if ( V_539 + V_35 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_35 ) ;
goto V_598;
}
if ( V_33 < V_539 )
F_31 ( V_14 , V_33 ,
V_539 - V_33 ) ;
F_32 ( V_33 > V_539 ) ;
V_29 = F_416 ( V_14 , V_546 ,
V_35 , V_547 ) ;
if ( V_29 == - V_185 ) {
F_31 ( V_14 , V_33 , V_35 ) ;
goto V_598;
}
F_412 ( V_14 ) ;
V_221 -> V_22 = V_539 ;
V_221 -> V_33 = V_35 ;
F_456 ( V_34 , V_14 ,
V_539 , V_35 ) ;
F_447 ( V_14 , V_547 ) ;
break;
V_598:
V_600 = false ;
V_601 = false ;
F_32 ( V_599 != F_441 ( V_14 ) ) ;
F_447 ( V_14 , V_547 ) ;
}
F_46 ( & V_92 -> V_353 ) ;
if ( ( V_598 == V_617 ) && V_603
&& ! V_604 )
V_604 = true ;
if ( ! V_221 -> V_22 && V_598 >= V_620 && V_603 )
goto V_608;
if ( ! V_221 -> V_22 && ++ V_599 < V_351 )
goto V_608;
if ( ! V_221 -> V_22 && V_598 < V_615 ) {
V_599 = 0 ;
if ( V_598 == V_617 ) {
if ( V_604 || ! V_605 )
V_598 = V_620 ;
else
V_598 = V_621 ;
} else {
V_598 ++ ;
}
if ( V_598 == V_621 ) {
struct V_114 * V_115 ;
int V_622 = 0 ;
V_115 = V_401 -> V_402 ;
if ( V_115 )
V_622 = 1 ;
else
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
goto V_79;
}
V_29 = F_309 ( V_115 , V_34 , V_7 ,
V_405 ) ;
if ( V_29 == - V_314 )
V_598 = V_615 ;
if ( V_29 < 0 && V_29 != - V_314 )
F_162 ( V_115 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_622 )
F_220 ( V_115 ) ;
if ( V_29 )
goto V_79;
}
if ( V_598 == V_615 ) {
if ( V_595 == 0 &&
V_549 == 0 ) {
V_29 = - V_314 ;
goto V_79;
}
V_595 = 0 ;
V_549 = 0 ;
}
goto V_608;
} else if ( ! V_221 -> V_22 ) {
V_29 = - V_314 ;
} else if ( V_221 -> V_22 ) {
if ( ! V_602 && V_597 ) {
F_11 ( & V_597 -> V_48 ) ;
V_597 -> V_606 = V_221 -> V_22 ;
F_13 ( & V_597 -> V_48 ) ;
}
V_29 = 0 ;
}
V_79:
if ( V_29 == - V_314 ) {
F_11 ( & V_92 -> V_48 ) ;
V_92 -> V_357 = V_357 ;
F_13 ( & V_92 -> V_48 ) ;
V_221 -> V_33 = V_357 ;
}
return V_29 ;
}
static void F_332 ( struct V_12 * V_34 ,
struct V_108 * V_13 , T_2 V_210 ,
int V_623 )
{
struct V_1 * V_2 ;
int V_599 = 0 ;
F_11 ( & V_13 -> V_48 ) ;
F_331 ( V_34 , L_24 ,
V_13 -> V_7 ,
V_13 -> V_341 - V_13 -> V_91 - V_13 -> V_354 -
V_13 -> V_355 - V_13 -> V_342 -
V_13 -> V_356 , ( V_13 -> V_113 ) ? L_25 : L_26 ) ;
F_331 ( V_34 ,
L_27 ,
V_13 -> V_341 , V_13 -> V_91 , V_13 -> V_354 ,
V_13 -> V_355 , V_13 -> V_356 ,
V_13 -> V_342 ) ;
F_13 ( & V_13 -> V_48 ) ;
if ( ! V_623 )
return;
F_50 ( & V_13 -> V_353 ) ;
V_162:
F_235 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_48 ) ;
F_331 ( V_34 ,
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_58 ( & V_2 -> V_93 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_307 ? L_29 : L_25 ) ;
F_457 ( V_2 , V_210 ) ;
F_13 ( & V_2 -> V_48 ) ;
}
if ( ++ V_599 < V_351 )
goto V_162;
F_46 ( & V_13 -> V_353 ) ;
}
int F_458 ( struct V_61 * V_138 , T_2 V_546 ,
T_2 V_35 , T_2 V_624 ,
T_2 V_595 , T_2 V_596 ,
struct V_67 * V_221 , int V_191 , int V_547 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
bool V_625 = V_35 == V_624 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_306 ( V_138 , V_191 ) ;
V_162:
F_8 ( V_35 < V_34 -> V_53 ) ;
V_29 = F_448 ( V_138 , V_546 , V_35 , V_595 ,
V_596 , V_221 , V_7 , V_547 ) ;
if ( ! V_29 && ! V_191 ) {
F_413 ( V_34 , V_221 -> V_22 ) ;
} else if ( V_29 == - V_314 ) {
if ( ! V_625 && V_221 -> V_33 ) {
V_35 = F_344 ( V_35 >> 1 , V_221 -> V_33 ) ;
V_35 = F_150 ( V_35 ,
V_34 -> V_53 ) ;
V_35 = F_450 ( V_35 , V_624 ) ;
V_546 = V_35 ;
if ( V_35 == V_624 )
V_625 = true ;
goto V_162;
} else if ( F_265 ( V_34 , V_423 ) ) {
struct V_108 * V_412 ;
V_412 = F_77 ( V_34 , V_7 ) ;
F_173 ( V_34 ,
L_30 ,
V_7 , V_35 ) ;
if ( V_412 )
F_332 ( V_34 , V_412 , V_35 , 1 ) ;
}
}
return V_29 ;
}
static int F_459 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_45 ,
int V_575 , int V_547 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_76 ( V_34 , V_32 ) ;
if ( ! V_2 ) {
F_173 ( V_34 , L_31 ,
V_32 ) ;
return - V_314 ;
}
if ( V_575 )
F_408 ( V_34 , V_2 , V_32 , V_45 , 1 ) ;
else {
if ( F_265 ( V_34 , V_564 ) )
V_29 = F_153 ( V_34 , V_32 , V_45 , NULL ) ;
F_31 ( V_2 , V_32 , V_45 ) ;
F_417 ( V_2 , V_45 , V_547 ) ;
F_436 ( V_34 , V_32 , V_45 ) ;
}
F_6 ( V_2 ) ;
return V_29 ;
}
int F_460 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_45 , int V_547 )
{
return F_459 ( V_34 , V_32 , V_45 , 0 , V_547 ) ;
}
int F_461 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_45 )
{
return F_459 ( V_34 , V_32 , V_45 , 1 , 0 ) ;
}
static int F_166 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_7 , T_2 V_139 , T_2 V_33 ,
struct V_67 * V_221 , int V_137 )
{
int V_29 ;
struct V_121 * V_626 ;
struct V_170 * V_171 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_160 ;
else
type = V_161 ;
V_57 = sizeof( * V_626 ) + F_133 ( type ) ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_64 -> V_218 = 1 ;
V_29 = F_114 ( V_115 , V_34 -> V_62 , V_64 ,
V_221 , V_57 ) ;
if ( V_29 ) {
F_53 ( V_64 ) ;
return V_29 ;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_626 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_121 ) ;
F_98 ( V_66 , V_626 , V_137 ) ;
F_99 ( V_66 , V_626 , V_115 -> V_273 ) ;
F_100 ( V_66 , V_626 ,
V_7 | V_150 ) ;
V_171 = (struct V_170 * ) ( V_626 + 1 ) ;
F_140 ( V_66 , V_171 , type ) ;
if ( V_17 > 0 ) {
struct V_165 * V_156 ;
V_156 = (struct V_165 * ) ( V_171 + 1 ) ;
F_141 ( V_66 , V_171 , V_17 ) ;
F_115 ( V_66 , V_156 , V_137 ) ;
} else {
struct V_155 * V_156 ;
V_156 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
F_117 ( V_66 , V_156 , V_151 ) ;
F_118 ( V_66 , V_156 , V_139 ) ;
F_119 ( V_66 , V_156 , V_33 ) ;
F_120 ( V_66 , V_156 , V_137 ) ;
}
F_103 ( V_64 -> V_80 [ 0 ] ) ;
F_53 ( V_64 ) ;
V_29 = F_462 ( V_115 , V_34 , V_221 -> V_22 ,
V_221 -> V_33 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_403 ( V_115 , V_34 , V_221 -> V_22 , V_221 -> V_33 , 1 ) ;
if ( V_29 ) {
F_173 ( V_34 , L_32 ,
V_221 -> V_22 , V_221 -> V_33 ) ;
F_91 () ;
}
F_463 ( V_34 , V_221 -> V_22 , V_221 -> V_33 ) ;
return V_29 ;
}
static int F_174 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_7 , struct V_627 * V_21 ,
int V_174 , struct V_67 * V_221 )
{
int V_29 ;
struct V_121 * V_626 ;
struct V_143 * V_628 ;
struct V_170 * V_171 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_57 = sizeof( * V_626 ) + sizeof( * V_171 ) ;
T_2 V_35 = V_221 -> V_33 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
if ( ! V_180 )
V_57 += sizeof( * V_628 ) ;
V_64 = F_34 () ;
if ( ! V_64 ) {
F_461 ( V_34 , V_221 -> V_22 ,
V_34 -> V_52 ) ;
return - V_72 ;
}
V_64 -> V_218 = 1 ;
V_29 = F_114 ( V_115 , V_34 -> V_62 , V_64 ,
V_221 , V_57 ) ;
if ( V_29 ) {
F_53 ( V_64 ) ;
F_461 ( V_34 , V_221 -> V_22 ,
V_34 -> V_52 ) ;
return V_29 ;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_626 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_121 ) ;
F_98 ( V_66 , V_626 , 1 ) ;
F_99 ( V_66 , V_626 , V_115 -> V_273 ) ;
F_100 ( V_66 , V_626 ,
V_7 | V_149 ) ;
if ( V_180 ) {
V_171 = (struct V_170 * ) ( V_626 + 1 ) ;
V_35 = V_34 -> V_52 ;
} else {
V_628 = (struct V_143 * ) ( V_626 + 1 ) ;
F_168 ( V_66 , V_628 , V_21 ) ;
F_102 ( V_66 , V_628 , V_174 ) ;
V_171 = (struct V_170 * ) ( V_628 + 1 ) ;
}
if ( V_17 > 0 ) {
F_32 ( ! ( V_7 & V_131 ) ) ;
F_140 ( V_66 , V_171 ,
V_172 ) ;
F_141 ( V_66 , V_171 , V_17 ) ;
} else {
F_140 ( V_66 , V_171 ,
V_173 ) ;
F_141 ( V_66 , V_171 , V_151 ) ;
}
F_103 ( V_66 ) ;
F_53 ( V_64 ) ;
V_29 = F_462 ( V_115 , V_34 , V_221 -> V_22 ,
V_35 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_403 ( V_115 , V_34 , V_221 -> V_22 ,
V_34 -> V_52 , 1 ) ;
if ( V_29 ) {
F_173 ( V_34 , L_32 ,
V_221 -> V_22 , V_221 -> V_33 ) ;
F_91 () ;
}
F_463 ( V_34 , V_221 -> V_22 ,
V_34 -> V_52 ) ;
return V_29 ;
}
int F_464 ( struct V_114 * V_115 ,
T_2 V_151 , T_2 V_139 ,
T_2 V_33 , T_2 V_546 ,
struct V_67 * V_221 )
{
struct V_12 * V_34 = V_115 -> V_34 ;
int V_29 ;
F_32 ( V_151 == V_215 ) ;
V_29 = F_160 ( V_34 , V_115 , V_221 -> V_22 ,
V_221 -> V_33 , 0 ,
V_151 , V_139 , V_33 ,
V_546 , V_244 ,
NULL ) ;
return V_29 ;
}
int F_465 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_151 , T_2 V_139 , T_2 V_33 ,
struct V_67 * V_221 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_108 * V_92 ;
if ( ! F_84 ( V_34 , V_544 ) ) {
V_29 = F_410 ( V_34 , V_221 -> V_22 ,
V_221 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_76 ( V_34 , V_221 -> V_22 ) ;
if ( ! V_14 )
return - V_540 ;
V_92 = V_14 -> V_92 ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_14 -> V_48 ) ;
V_92 -> V_355 += V_221 -> V_33 ;
V_14 -> V_10 += V_221 -> V_33 ;
F_13 ( & V_14 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
V_29 = F_166 ( V_115 , V_34 , 0 , V_151 ,
0 , V_139 , V_33 , V_221 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_65 *
F_466 ( struct V_114 * V_115 , struct V_61 * V_138 ,
T_2 V_27 , int V_174 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_65 * V_287 ;
V_287 = F_467 ( V_34 , V_27 ) ;
if ( F_217 ( V_287 ) )
return V_287 ;
F_468 ( V_287 , V_115 -> V_273 ) ;
F_469 ( V_138 -> V_283 . V_22 , V_287 , V_174 ) ;
F_470 ( V_287 ) ;
F_471 ( V_115 , V_34 , V_287 ) ;
F_437 ( V_629 , & V_287 -> V_578 ) ;
F_472 ( V_287 ) ;
F_473 ( V_287 ) ;
if ( V_138 -> V_283 . V_22 == V_215 ) {
V_287 -> V_630 = V_138 -> V_631 % 2 ;
if ( V_287 -> V_630 == 0 )
F_407 ( & V_138 -> V_632 , V_287 -> V_32 ,
V_287 -> V_32 + V_287 -> V_45 - 1 , V_95 ) ;
else
F_474 ( & V_138 -> V_632 , V_287 -> V_32 ,
V_287 -> V_32 + V_287 -> V_45 - 1 ) ;
} else {
V_287 -> V_630 = - 1 ;
F_407 ( & V_115 -> V_132 -> V_633 , V_287 -> V_32 ,
V_287 -> V_32 + V_287 -> V_45 - 1 , V_95 ) ;
}
V_115 -> V_323 = true ;
return V_287 ;
}
static struct V_261 *
F_475 ( struct V_114 * V_115 ,
struct V_61 * V_138 , T_3 V_634 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_261 * V_447 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
int V_29 ;
bool V_635 = false ;
V_447 = F_367 ( V_115 , V_138 ) ;
if ( F_365 ( V_447 -> V_57 == 0 ) )
goto V_636;
V_162:
V_29 = F_366 ( V_447 , V_634 ) ;
if ( ! V_29 )
return V_447 ;
if ( V_447 -> V_637 )
return F_476 ( V_29 ) ;
if ( V_447 -> type == V_638 && ! V_635 ) {
V_635 = true ;
F_380 ( V_34 ) ;
goto V_162;
}
if ( F_265 ( V_34 , V_423 ) ) {
static F_477 ( V_639 ,
V_640 * 10 ,
1 ) ;
if ( F_478 ( & V_639 ) )
F_479 ( 1 , V_641
L_33 , V_29 ) ;
}
V_636:
V_29 = F_364 ( V_138 , V_447 , V_634 ,
V_425 ) ;
if ( ! V_29 )
return V_447 ;
if ( V_447 -> type != V_638 &&
V_447 -> V_92 == V_262 -> V_92 ) {
V_29 = F_366 ( V_262 , V_634 ) ;
if ( ! V_29 )
return V_262 ;
}
return F_476 ( V_29 ) ;
}
static void F_480 ( struct V_12 * V_34 ,
struct V_261 * V_447 , T_3 V_634 )
{
F_368 ( V_447 , V_634 , 0 ) ;
F_371 ( V_34 , V_447 , NULL , 0 ) ;
}
struct V_65 * F_481 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
T_2 V_17 , T_2 V_151 ,
struct V_627 * V_21 , int V_174 ,
T_2 V_642 , T_2 V_595 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_67 V_221 ;
struct V_261 * V_447 ;
struct V_65 * V_287 ;
struct V_187 * V_134 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_634 = V_34 -> V_52 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
#ifdef F_482
if ( F_242 ( V_34 ) ) {
V_287 = F_466 ( V_115 , V_138 , V_138 -> V_643 ,
V_174 ) ;
if ( ! F_217 ( V_287 ) )
V_138 -> V_643 += V_634 ;
return V_287 ;
}
#endif
V_447 = F_475 ( V_115 , V_138 , V_634 ) ;
if ( F_217 ( V_447 ) )
return F_483 ( V_447 ) ;
V_29 = F_458 ( V_138 , V_634 , V_634 , V_634 ,
V_595 , V_642 , & V_221 , 0 , 0 ) ;
if ( V_29 )
goto V_644;
V_287 = F_466 ( V_115 , V_138 , V_221 . V_22 , V_174 ) ;
if ( F_217 ( V_287 ) ) {
V_29 = F_218 ( V_287 ) ;
goto V_645;
}
if ( V_151 == V_646 ) {
if ( V_17 == 0 )
V_17 = V_221 . V_22 ;
V_7 |= V_131 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_151 != V_215 ) {
V_134 = F_232 () ;
if ( ! V_134 ) {
V_29 = - V_72 ;
goto V_647;
}
if ( V_21 )
memcpy ( & V_134 -> V_21 , V_21 , sizeof( V_134 -> V_21 ) ) ;
else
memset ( & V_134 -> V_21 , 0 , sizeof( V_134 -> V_21 ) ) ;
V_134 -> V_136 = V_7 ;
V_134 -> V_225 = V_180 ? false : true ;
V_134 -> V_135 = true ;
V_134 -> V_191 = false ;
V_134 -> V_174 = V_174 ;
V_29 = F_159 ( V_34 , V_115 ,
V_221 . V_22 , V_221 . V_33 ,
V_17 , V_151 , V_174 ,
V_244 ,
V_134 ) ;
if ( V_29 )
goto V_648;
}
return V_287 ;
V_648:
F_192 ( V_134 ) ;
V_647:
F_484 ( V_287 ) ;
V_645:
F_460 ( V_34 , V_221 . V_22 , V_221 . V_33 , 0 ) ;
V_644:
F_480 ( V_34 , V_447 , V_634 ) ;
return F_476 ( V_29 ) ;
}
static T_1 void F_485 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_649 * V_650 ,
struct V_63 * V_64 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
T_2 V_27 ;
T_2 V_311 ;
T_2 V_117 ;
T_2 V_7 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_65 * V_542 ;
int V_29 ;
int V_651 ;
int V_652 = 0 ;
if ( V_64 -> V_81 [ V_650 -> V_174 ] < V_650 -> V_653 ) {
V_650 -> V_654 = V_650 -> V_654 * 2 / 3 ;
V_650 -> V_654 = F_450 ( V_650 -> V_654 , 2 ) ;
} else {
V_650 -> V_654 = V_650 -> V_654 * 3 / 2 ;
V_650 -> V_654 = F_24 ( int , V_650 -> V_654 ,
F_486 ( V_34 ) ) ;
}
V_542 = V_64 -> V_80 [ V_650 -> V_174 ] ;
V_70 = F_39 ( V_542 ) ;
for ( V_651 = V_64 -> V_81 [ V_650 -> V_174 ] ; V_651 < V_70 ; V_651 ++ ) {
if ( V_652 >= V_650 -> V_654 )
break;
F_48 () ;
V_27 = F_249 ( V_542 , V_651 ) ;
V_311 = F_487 ( V_542 , V_651 ) ;
if ( V_651 == V_64 -> V_81 [ V_650 -> V_174 ] )
goto V_75;
if ( V_650 -> V_655 == V_656 &&
V_311 <= V_138 -> V_283 . V_33 )
continue;
V_29 = F_83 ( V_115 , V_34 , V_27 ,
V_650 -> V_174 - 1 , 1 , & V_117 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_117 == 0 ) ;
if ( V_650 -> V_655 == V_657 ) {
if ( V_117 == 1 )
goto V_75;
if ( V_650 -> V_174 == 1 &&
( V_7 & V_131 ) )
continue;
if ( ! V_650 -> V_658 ||
V_311 <= V_138 -> V_283 . V_33 )
continue;
F_131 ( V_542 , & V_21 , V_651 ) ;
V_29 = F_488 ( & V_21 ,
& V_650 -> V_659 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_650 -> V_174 == 1 &&
( V_7 & V_131 ) )
continue;
}
V_75:
F_489 ( V_34 , V_27 ) ;
V_652 ++ ;
}
V_650 -> V_653 = V_651 ;
}
static T_1 int F_490 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_649 * V_650 , int V_660 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
int V_174 = V_650 -> V_174 ;
struct V_65 * V_542 = V_64 -> V_80 [ V_174 ] ;
T_2 V_661 = V_131 ;
int V_29 ;
if ( V_650 -> V_655 == V_656 &&
F_243 ( V_542 ) != V_138 -> V_283 . V_22 )
return 1 ;
if ( V_660 &&
( ( V_650 -> V_655 == V_657 && V_650 -> V_117 [ V_174 ] != 1 ) ||
( V_650 -> V_655 == V_656 && ! ( V_650 -> V_7 [ V_174 ] & V_661 ) ) ) ) {
F_32 ( ! V_64 -> V_662 [ V_174 ] ) ;
V_29 = F_83 ( V_115 , V_34 ,
V_542 -> V_32 , V_174 , 1 ,
& V_650 -> V_117 [ V_174 ] ,
& V_650 -> V_7 [ V_174 ] ) ;
F_32 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_650 -> V_117 [ V_174 ] == 0 ) ;
}
if ( V_650 -> V_655 == V_657 ) {
if ( V_650 -> V_117 [ V_174 ] > 1 )
return 1 ;
if ( V_64 -> V_662 [ V_174 ] && ! V_650 -> V_181 ) {
F_491 ( V_542 , V_64 -> V_662 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_650 -> V_7 [ V_174 ] & V_661 ) ) {
F_32 ( ! V_64 -> V_662 [ V_174 ] ) ;
V_29 = F_250 ( V_115 , V_138 , V_542 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_251 ( V_115 , V_138 , V_542 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_231 ( V_115 , V_34 , V_542 -> V_32 ,
V_542 -> V_45 , V_661 ,
F_244 ( V_542 ) , 0 ) ;
F_32 ( V_29 ) ;
V_650 -> V_7 [ V_174 ] |= V_661 ;
}
if ( V_64 -> V_662 [ V_174 ] && V_174 > 0 ) {
F_491 ( V_542 , V_64 -> V_662 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = 0 ;
}
return 0 ;
}
static T_1 int F_492 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_649 * V_650 , int * V_660 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
T_2 V_27 ;
T_2 V_311 ;
T_2 V_17 ;
T_3 V_634 ;
struct V_67 V_21 ;
struct V_65 * V_78 ;
int V_174 = V_650 -> V_174 ;
int V_75 = 0 ;
int V_29 = 0 ;
bool V_663 = false ;
V_311 = F_487 ( V_64 -> V_80 [ V_174 ] ,
V_64 -> V_81 [ V_174 ] ) ;
if ( V_650 -> V_655 == V_656 &&
V_311 <= V_138 -> V_283 . V_33 ) {
* V_660 = 1 ;
return 1 ;
}
V_27 = F_249 ( V_64 -> V_80 [ V_174 ] , V_64 -> V_81 [ V_174 ] ) ;
V_634 = V_34 -> V_52 ;
V_78 = F_493 ( V_34 , V_27 ) ;
if ( ! V_78 ) {
V_78 = F_467 ( V_34 , V_27 ) ;
if ( F_217 ( V_78 ) )
return F_218 ( V_78 ) ;
F_469 ( V_138 -> V_283 . V_22 , V_78 ,
V_174 - 1 ) ;
V_75 = 1 ;
}
F_470 ( V_78 ) ;
F_472 ( V_78 ) ;
V_29 = F_83 ( V_115 , V_34 , V_27 , V_174 - 1 , 1 ,
& V_650 -> V_117 [ V_174 - 1 ] ,
& V_650 -> V_7 [ V_174 - 1 ] ) ;
if ( V_29 < 0 )
goto V_664;
if ( F_365 ( V_650 -> V_117 [ V_174 - 1 ] == 0 ) ) {
F_173 ( V_34 , L_34 ) ;
V_29 = - V_182 ;
goto V_664;
}
* V_660 = 0 ;
if ( V_650 -> V_655 == V_657 ) {
if ( V_650 -> V_117 [ V_174 - 1 ] > 1 ) {
V_663 = true ;
if ( V_174 == 1 &&
( V_650 -> V_7 [ 0 ] & V_131 ) )
goto V_665;
if ( ! V_650 -> V_658 ||
V_311 <= V_138 -> V_283 . V_33 )
goto V_665;
F_131 ( V_64 -> V_80 [ V_174 ] , & V_21 ,
V_64 -> V_81 [ V_174 ] ) ;
V_29 = F_488 ( & V_21 , & V_650 -> V_659 ) ;
if ( V_29 < 0 )
goto V_665;
V_650 -> V_655 = V_656 ;
V_650 -> V_666 = V_174 - 1 ;
}
} else {
if ( V_174 == 1 &&
( V_650 -> V_7 [ 0 ] & V_131 ) )
goto V_665;
}
if ( ! F_494 ( V_78 , V_311 , 0 ) ) {
F_495 ( V_78 ) ;
F_484 ( V_78 ) ;
V_78 = NULL ;
* V_660 = 1 ;
}
if ( ! V_78 ) {
if ( V_75 && V_174 == 1 )
F_485 ( V_115 , V_138 , V_650 , V_64 ) ;
V_78 = F_496 ( V_34 , V_27 , V_311 ) ;
if ( F_217 ( V_78 ) ) {
return F_218 ( V_78 ) ;
} else if ( ! F_497 ( V_78 ) ) {
F_484 ( V_78 ) ;
return - V_182 ;
}
F_470 ( V_78 ) ;
F_472 ( V_78 ) ;
}
V_174 -- ;
ASSERT ( V_174 == F_244 ( V_78 ) ) ;
if ( V_174 != F_244 ( V_78 ) ) {
F_173 ( V_138 -> V_34 , L_35 ) ;
V_29 = - V_182 ;
goto V_664;
}
V_64 -> V_80 [ V_174 ] = V_78 ;
V_64 -> V_81 [ V_174 ] = 0 ;
V_64 -> V_662 [ V_174 ] = V_667 ;
V_650 -> V_174 = V_174 ;
if ( V_650 -> V_174 == 1 )
V_650 -> V_653 = 0 ;
return 0 ;
V_665:
V_650 -> V_117 [ V_174 - 1 ] = 0 ;
V_650 -> V_7 [ V_174 - 1 ] = 0 ;
if ( V_650 -> V_655 == V_657 ) {
if ( V_650 -> V_7 [ V_174 ] & V_131 ) {
V_17 = V_64 -> V_80 [ V_174 ] -> V_32 ;
} else {
ASSERT ( V_138 -> V_283 . V_22 ==
F_243 ( V_64 -> V_80 [ V_174 ] ) ) ;
if ( V_138 -> V_283 . V_22 !=
F_243 ( V_64 -> V_80 [ V_174 ] ) ) {
F_173 ( V_138 -> V_34 ,
L_36 ) ;
V_29 = - V_182 ;
goto V_664;
}
V_17 = 0 ;
}
if ( V_663 ) {
V_29 = F_498 ( V_115 , V_138 , V_78 ,
V_311 , V_174 - 1 ) ;
if ( V_29 ) {
F_499 ( V_34 ,
L_37 ,
V_29 ) ;
}
}
V_29 = V_294 ( V_115 , V_34 , V_27 , V_634 ,
V_17 , V_138 -> V_283 . V_22 ,
V_174 - 1 , 0 ) ;
if ( V_29 )
goto V_664;
}
* V_660 = 1 ;
V_29 = 1 ;
V_664:
F_495 ( V_78 ) ;
F_484 ( V_78 ) ;
return V_29 ;
}
static T_1 int F_500 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_649 * V_650 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
int V_29 ;
int V_174 = V_650 -> V_174 ;
struct V_65 * V_542 = V_64 -> V_80 [ V_174 ] ;
T_2 V_17 = 0 ;
if ( V_650 -> V_655 == V_656 ) {
F_32 ( V_650 -> V_666 < V_174 ) ;
if ( V_174 < V_650 -> V_666 )
goto V_79;
V_29 = F_42 ( V_64 , V_174 + 1 , & V_650 -> V_659 ) ;
if ( V_29 > 0 )
V_650 -> V_658 = 0 ;
V_650 -> V_655 = V_657 ;
V_650 -> V_666 = - 1 ;
V_64 -> V_81 [ V_174 ] = 0 ;
if ( ! V_64 -> V_662 [ V_174 ] ) {
F_32 ( V_174 == 0 ) ;
F_470 ( V_542 ) ;
F_472 ( V_542 ) ;
V_64 -> V_662 [ V_174 ] = V_667 ;
V_29 = F_83 ( V_115 , V_34 ,
V_542 -> V_32 , V_174 , 1 ,
& V_650 -> V_117 [ V_174 ] ,
& V_650 -> V_7 [ V_174 ] ) ;
if ( V_29 < 0 ) {
F_491 ( V_542 , V_64 -> V_662 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = 0 ;
return V_29 ;
}
F_32 ( V_650 -> V_117 [ V_174 ] == 0 ) ;
if ( V_650 -> V_117 [ V_174 ] == 1 ) {
F_491 ( V_542 , V_64 -> V_662 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_650 -> V_117 [ V_174 ] > 1 && ! V_64 -> V_662 [ V_174 ] ) ;
if ( V_650 -> V_117 [ V_174 ] == 1 ) {
if ( V_174 == 0 ) {
if ( V_650 -> V_7 [ V_174 ] & V_131 )
V_29 = F_251 ( V_115 , V_138 , V_542 , 1 ) ;
else
V_29 = F_251 ( V_115 , V_138 , V_542 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_501 ( V_115 , V_34 , V_542 ) ;
if ( V_29 ) {
F_499 ( V_34 ,
L_38 ,
V_29 ) ;
}
}
if ( ! V_64 -> V_662 [ V_174 ] &&
F_434 ( V_542 ) == V_115 -> V_273 ) {
F_470 ( V_542 ) ;
F_472 ( V_542 ) ;
V_64 -> V_662 [ V_174 ] = V_667 ;
}
F_471 ( V_115 , V_34 , V_542 ) ;
}
if ( V_542 == V_138 -> V_133 ) {
if ( V_650 -> V_7 [ V_174 ] & V_131 )
V_17 = V_542 -> V_32 ;
else
F_32 ( V_138 -> V_283 . V_22 !=
F_243 ( V_542 ) ) ;
} else {
if ( V_650 -> V_7 [ V_174 + 1 ] & V_131 )
V_17 = V_64 -> V_80 [ V_174 + 1 ] -> V_32 ;
else
F_32 ( V_138 -> V_283 . V_22 !=
F_243 ( V_64 -> V_80 [ V_174 + 1 ] ) ) ;
}
F_433 ( V_115 , V_138 , V_542 , V_17 , V_650 -> V_117 [ V_174 ] == 1 ) ;
V_79:
V_650 -> V_117 [ V_174 ] = 0 ;
V_650 -> V_7 [ V_174 ] = 0 ;
return 0 ;
}
static T_1 int F_502 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_649 * V_650 )
{
int V_174 = V_650 -> V_174 ;
int V_660 = 1 ;
int V_29 ;
while ( V_174 >= 0 ) {
V_29 = F_490 ( V_115 , V_138 , V_64 , V_650 , V_660 ) ;
if ( V_29 > 0 )
break;
if ( V_174 == 0 )
break;
if ( V_64 -> V_81 [ V_174 ] >=
F_39 ( V_64 -> V_80 [ V_174 ] ) )
break;
V_29 = F_492 ( V_115 , V_138 , V_64 , V_650 , & V_660 ) ;
if ( V_29 > 0 ) {
V_64 -> V_81 [ V_174 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_174 = V_650 -> V_174 ;
}
return 0 ;
}
static T_1 int F_503 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_63 * V_64 ,
struct V_649 * V_650 , int V_668 )
{
int V_174 = V_650 -> V_174 ;
int V_29 ;
V_64 -> V_81 [ V_174 ] = F_39 ( V_64 -> V_80 [ V_174 ] ) ;
while ( V_174 < V_668 && V_64 -> V_80 [ V_174 ] ) {
V_650 -> V_174 = V_174 ;
if ( V_64 -> V_81 [ V_174 ] + 1 <
F_39 ( V_64 -> V_80 [ V_174 ] ) ) {
V_64 -> V_81 [ V_174 ] ++ ;
return 0 ;
} else {
V_29 = F_500 ( V_115 , V_138 , V_64 , V_650 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_64 -> V_662 [ V_174 ] ) {
F_491 ( V_64 -> V_80 [ V_174 ] ,
V_64 -> V_662 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = 0 ;
}
F_484 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_80 [ V_174 ] = NULL ;
V_174 ++ ;
}
}
return 1 ;
}
int F_504 ( struct V_61 * V_138 ,
struct V_261 * V_447 , int V_658 ,
int V_669 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_63 * V_64 ;
struct V_114 * V_115 ;
struct V_61 * V_274 = V_34 -> V_274 ;
struct V_670 * V_284 = & V_138 -> V_284 ;
struct V_649 * V_650 ;
struct V_67 V_21 ;
int V_158 = 0 ;
int V_29 ;
int V_174 ;
bool V_671 = false ;
F_193 ( V_34 , L_39 , V_138 -> V_22 ) ;
V_64 = F_34 () ;
if ( ! V_64 ) {
V_158 = - V_72 ;
goto V_79;
}
V_650 = F_61 ( sizeof( * V_650 ) , V_95 ) ;
if ( ! V_650 ) {
F_53 ( V_64 ) ;
V_158 = - V_72 ;
goto V_79;
}
V_115 = F_505 ( V_274 , 0 ) ;
if ( F_217 ( V_115 ) ) {
V_158 = F_218 ( V_115 ) ;
goto V_128;
}
if ( V_447 )
V_115 -> V_447 = V_447 ;
if ( F_506 ( & V_284 -> V_672 ) == 0 ) {
V_174 = F_244 ( V_138 -> V_133 ) ;
V_64 -> V_80 [ V_174 ] = F_507 ( V_138 ) ;
F_472 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_81 [ V_174 ] = 0 ;
V_64 -> V_662 [ V_174 ] = V_667 ;
memset ( & V_650 -> V_659 , 0 ,
sizeof( V_650 -> V_659 ) ) ;
} else {
F_508 ( & V_21 , & V_284 -> V_672 ) ;
memcpy ( & V_650 -> V_659 , & V_21 ,
sizeof( V_650 -> V_659 ) ) ;
V_174 = V_284 -> V_673 ;
F_32 ( V_174 == 0 ) ;
V_64 -> V_674 = V_174 ;
V_29 = F_38 ( NULL , V_138 , & V_21 , V_64 , 0 , 0 ) ;
V_64 -> V_674 = 0 ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_675;
}
F_8 ( V_29 > 0 ) ;
F_136 ( V_64 , 0 ) ;
V_174 = F_244 ( V_138 -> V_133 ) ;
while ( 1 ) {
F_470 ( V_64 -> V_80 [ V_174 ] ) ;
F_472 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = V_667 ;
V_29 = F_83 ( V_115 , V_34 ,
V_64 -> V_80 [ V_174 ] -> V_32 ,
V_174 , 1 , & V_650 -> V_117 [ V_174 ] ,
& V_650 -> V_7 [ V_174 ] ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_675;
}
F_32 ( V_650 -> V_117 [ V_174 ] == 0 ) ;
if ( V_174 == V_284 -> V_673 )
break;
F_495 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_662 [ V_174 ] = 0 ;
F_8 ( V_650 -> V_117 [ V_174 ] != 1 ) ;
V_174 -- ;
}
}
V_650 -> V_174 = V_174 ;
V_650 -> V_666 = - 1 ;
V_650 -> V_655 = V_657 ;
V_650 -> V_658 = V_658 ;
V_650 -> V_181 = 0 ;
V_650 -> V_669 = V_669 ;
V_650 -> V_654 = F_486 ( V_34 ) ;
while ( 1 ) {
V_29 = F_502 ( V_115 , V_138 , V_64 , V_650 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
break;
}
V_29 = F_503 ( V_115 , V_138 , V_64 , V_650 , V_175 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_650 -> V_655 != V_657 ) ;
break;
}
if ( V_650 -> V_655 == V_657 ) {
V_174 = V_650 -> V_174 ;
F_509 ( V_64 -> V_80 [ V_174 ] ,
& V_284 -> V_672 ,
V_64 -> V_81 [ V_174 ] ) ;
V_284 -> V_673 = V_174 ;
}
F_32 ( V_650 -> V_174 == 0 ) ;
if ( F_510 ( V_115 ) ||
( ! V_669 && F_511 ( V_34 ) ) ) {
V_29 = F_512 ( V_115 , V_274 ,
& V_138 -> V_283 ,
V_284 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
V_158 = V_29 ;
goto V_675;
}
F_513 ( V_115 ) ;
if ( ! V_669 && F_511 ( V_34 ) ) {
F_193 ( V_34 ,
L_40 ) ;
V_158 = - V_185 ;
goto V_128;
}
V_115 = F_505 ( V_274 , 0 ) ;
if ( F_217 ( V_115 ) ) {
V_158 = F_218 ( V_115 ) ;
goto V_128;
}
if ( V_447 )
V_115 -> V_447 = V_447 ;
}
}
F_45 ( V_64 ) ;
if ( V_158 )
goto V_675;
V_29 = F_514 ( V_115 , V_274 , & V_138 -> V_283 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_675;
}
if ( V_138 -> V_283 . V_22 != V_646 ) {
V_29 = F_515 ( V_274 , & V_138 -> V_283 , V_64 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
V_158 = V_29 ;
goto V_675;
} else if ( V_29 > 0 ) {
F_516 ( V_115 , V_274 ,
V_138 -> V_283 . V_22 ) ;
}
}
if ( F_226 ( V_676 , & V_138 -> V_293 ) ) {
F_517 ( V_115 , V_138 ) ;
} else {
F_484 ( V_138 -> V_133 ) ;
F_484 ( V_138 -> V_677 ) ;
F_518 ( V_138 ) ;
}
V_671 = true ;
V_675:
F_513 ( V_115 ) ;
V_128:
F_9 ( V_650 ) ;
F_53 ( V_64 ) ;
V_79:
if ( ! V_669 && V_671 == false )
F_519 ( V_138 ) ;
if ( V_158 && V_158 != - V_185 )
F_520 ( V_34 , V_158 , NULL ) ;
return V_158 ;
}
int F_521 ( struct V_114 * V_115 ,
struct V_61 * V_138 ,
struct V_65 * V_133 ,
struct V_65 * V_17 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_63 * V_64 ;
struct V_649 * V_650 ;
int V_174 ;
int V_678 ;
int V_29 = 0 ;
int V_679 ;
F_32 ( V_138 -> V_283 . V_22 != V_646 ) ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_650 = F_61 ( sizeof( * V_650 ) , V_95 ) ;
if ( ! V_650 ) {
F_53 ( V_64 ) ;
return - V_72 ;
}
F_522 ( V_17 ) ;
V_678 = F_244 ( V_17 ) ;
F_523 ( V_17 ) ;
V_64 -> V_80 [ V_678 ] = V_17 ;
V_64 -> V_81 [ V_678 ] = F_39 ( V_17 ) ;
F_522 ( V_133 ) ;
V_174 = F_244 ( V_133 ) ;
V_64 -> V_80 [ V_174 ] = V_133 ;
V_64 -> V_81 [ V_174 ] = 0 ;
V_64 -> V_662 [ V_174 ] = V_667 ;
V_650 -> V_117 [ V_678 ] = 1 ;
V_650 -> V_7 [ V_678 ] = V_131 ;
V_650 -> V_174 = V_174 ;
V_650 -> V_666 = - 1 ;
V_650 -> V_655 = V_657 ;
V_650 -> V_658 = 0 ;
V_650 -> V_181 = 1 ;
V_650 -> V_669 = 1 ;
V_650 -> V_654 = F_486 ( V_34 ) ;
while ( 1 ) {
V_679 = F_502 ( V_115 , V_138 , V_64 , V_650 ) ;
if ( V_679 < 0 ) {
V_29 = V_679 ;
break;
}
V_679 = F_503 ( V_115 , V_138 , V_64 , V_650 , V_678 ) ;
if ( V_679 < 0 )
V_29 = V_679 ;
if ( V_679 != 0 )
break;
}
F_9 ( V_650 ) ;
F_53 ( V_64 ) ;
return V_29 ;
}
static T_2 F_524 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_383 ;
T_2 V_680 ;
V_680 = F_300 ( V_34 , V_7 ) ;
if ( V_680 )
return F_302 ( V_680 ) ;
V_383 = V_34 -> V_384 -> V_385 ;
V_680 = V_394 |
V_393 | V_392 |
V_345 | V_346 ;
if ( V_383 == 1 ) {
V_680 |= V_344 ;
V_680 = V_7 & ~ V_680 ;
if ( V_7 & V_394 )
return V_680 ;
if ( V_7 & ( V_345 |
V_346 ) )
return V_680 | V_344 ;
} else {
if ( V_7 & V_680 )
return V_7 ;
V_680 |= V_344 ;
V_680 = V_7 & ~ V_680 ;
if ( V_7 & V_344 )
return V_680 | V_345 ;
}
return V_7 ;
}
static int F_525 ( struct V_1 * V_2 , int V_413 )
{
struct V_108 * V_412 = V_2 -> V_92 ;
T_2 V_35 ;
T_2 V_681 ;
int V_29 = - V_314 ;
if ( ( V_412 -> V_7 &
( V_340 | V_51 ) ) &&
! V_413 )
V_681 = V_304 ;
else
V_681 = 0 ;
F_11 ( & V_412 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_307 ) {
V_2 -> V_307 ++ ;
V_29 = 0 ;
goto V_79;
}
V_35 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_43 - F_58 ( & V_2 -> V_93 ) ;
if ( V_412 -> V_91 + V_412 -> V_355 + V_412 -> V_354 +
V_412 -> V_356 + V_412 -> V_342 + V_35 +
V_681 <= V_412 -> V_341 ) {
V_412 -> V_342 += V_35 ;
V_2 -> V_307 ++ ;
F_72 ( & V_2 -> V_682 , & V_412 -> V_362 ) ;
V_29 = 0 ;
}
V_79:
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_412 -> V_48 ) ;
return V_29 ;
}
int F_526 ( struct V_61 * V_138 ,
struct V_1 * V_2 )
{
struct V_12 * V_34 = V_138 -> V_34 ;
struct V_114 * V_115 ;
T_2 V_683 ;
int V_29 ;
V_162:
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) )
return F_218 ( V_115 ) ;
F_49 ( & V_34 -> V_684 ) ;
if ( F_226 ( V_685 , & V_115 -> V_132 -> V_7 ) ) {
T_2 V_273 = V_115 -> V_273 ;
F_47 ( & V_34 -> V_684 ) ;
F_220 ( V_115 ) ;
V_29 = F_527 ( V_34 , V_273 ) ;
if ( V_29 )
return V_29 ;
goto V_162;
}
V_683 = F_524 ( V_34 , V_2 -> V_7 ) ;
if ( V_683 != V_2 -> V_7 ) {
V_29 = F_309 ( V_115 , V_34 , V_683 ,
V_405 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_79;
}
V_29 = F_525 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_79;
V_683 = F_303 ( V_34 , V_2 -> V_92 -> V_7 ) ;
V_29 = F_309 ( V_115 , V_34 , V_683 ,
V_405 ) ;
if ( V_29 < 0 )
goto V_79;
V_29 = F_525 ( V_2 , 0 ) ;
V_79:
if ( V_2 -> V_7 & V_340 ) {
V_683 = F_524 ( V_34 , V_2 -> V_7 ) ;
F_49 ( & V_34 -> V_422 ) ;
F_328 ( V_115 , V_34 , V_683 ) ;
F_47 ( & V_34 -> V_422 ) ;
}
F_47 ( & V_34 -> V_684 ) ;
F_220 ( V_115 ) ;
return V_29 ;
}
int F_528 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 type )
{
T_2 V_683 = F_303 ( V_34 , type ) ;
return F_309 ( V_115 , V_34 , V_683 , V_405 ) ;
}
T_2 F_529 ( struct V_108 * V_412 )
{
struct V_1 * V_14 ;
T_2 V_686 = 0 ;
int V_343 ;
if ( F_183 ( & V_412 -> V_362 ) )
return 0 ;
F_11 ( & V_412 -> V_48 ) ;
F_235 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_48 ) ;
if ( ! V_14 -> V_307 ) {
F_13 ( & V_14 -> V_48 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_345 |
V_346 |
V_344 ) )
V_343 = 2 ;
else
V_343 = 1 ;
V_686 += ( V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_93 ) ) *
V_343 ;
F_13 ( & V_14 -> V_48 ) ;
}
F_13 ( & V_412 -> V_48 ) ;
return V_686 ;
}
void F_530 ( struct V_1 * V_2 )
{
struct V_108 * V_412 = V_2 -> V_92 ;
T_2 V_35 ;
F_32 ( ! V_2 -> V_307 ) ;
F_11 ( & V_412 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( ! -- V_2 -> V_307 ) {
V_35 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_43 -
F_58 ( & V_2 -> V_93 ) ;
V_412 -> V_342 -= V_35 ;
F_275 ( & V_2 -> V_682 ) ;
}
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_412 -> V_48 ) ;
}
int F_531 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_61 * V_138 = V_34 -> V_62 ;
struct V_1 * V_14 ;
struct V_108 * V_92 ;
struct V_687 * V_384 = V_34 -> V_384 ;
struct V_688 * V_689 ;
struct V_114 * V_115 ;
T_2 V_690 ;
T_2 V_691 = 1 ;
T_2 V_692 = 0 ;
T_2 V_378 ;
int V_693 ;
int V_599 ;
int V_113 = 0 ;
int V_29 = 0 ;
V_693 = F_265 ( V_34 , V_423 ) ;
V_14 = F_76 ( V_34 , V_27 ) ;
if ( ! V_14 ) {
if ( V_693 )
F_426 ( V_34 ,
L_41 ,
V_27 ) ;
return - 1 ;
}
V_690 = F_58 ( & V_14 -> V_93 ) ;
if ( ! V_690 )
goto V_79;
V_92 = V_14 -> V_92 ;
F_11 ( & V_92 -> V_48 ) ;
V_113 = V_92 -> V_113 ;
if ( ( V_92 -> V_341 != V_14 -> V_21 . V_33 ) &&
( V_92 -> V_91 + V_92 -> V_355 +
V_92 -> V_354 + V_92 -> V_342 +
V_690 < V_92 -> V_341 ) ) {
F_13 ( & V_92 -> V_48 ) ;
goto V_79;
}
F_13 ( & V_92 -> V_48 ) ;
V_29 = - 1 ;
V_378 = F_300 ( V_34 , V_14 -> V_7 ) ;
if ( V_378 ) {
V_599 = F_440 ( F_302 ( V_378 ) ) ;
} else {
if ( V_113 ) {
if ( V_693 )
F_426 ( V_34 ,
L_42 ,
V_14 -> V_21 . V_22 ) ;
goto V_79;
}
V_599 = F_441 ( V_14 ) ;
}
if ( V_599 == V_581 ) {
V_691 = 4 ;
V_690 >>= 1 ;
} else if ( V_599 == V_582 ) {
V_691 = 2 ;
} else if ( V_599 == V_583 ) {
V_690 <<= 1 ;
} else if ( V_599 == V_584 ) {
V_691 = V_384 -> V_385 ;
V_690 = F_207 ( V_690 , V_691 ) ;
}
V_115 = F_216 ( V_138 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
goto V_79;
}
F_49 ( & V_34 -> V_422 ) ;
F_235 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_694 ;
if ( V_689 -> V_341 > V_689 -> V_91 + V_690 &&
! V_689 -> V_695 ) {
V_29 = F_532 ( V_115 , V_689 , V_690 ,
& V_694 , NULL ) ;
if ( ! V_29 )
V_692 ++ ;
if ( V_692 >= V_691 )
break;
V_29 = - 1 ;
}
}
if ( V_693 && V_29 == - 1 )
F_426 ( V_34 ,
L_43 ,
V_14 -> V_21 . V_22 ) ;
F_47 ( & V_34 -> V_422 ) ;
F_220 ( V_115 ) ;
V_79:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_533 ( struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_67 * V_21 )
{
struct V_61 * V_138 = V_34 -> V_62 ;
int V_29 = 0 ;
struct V_67 V_145 ;
struct V_65 * V_66 ;
int V_651 ;
V_29 = F_38 ( NULL , V_138 , V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_79;
while ( 1 ) {
V_651 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
if ( V_651 >= F_39 ( V_66 ) ) {
V_29 = F_51 ( V_138 , V_64 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_79;
break;
}
F_41 ( V_66 , & V_145 , V_651 ) ;
if ( V_145 . V_22 >= V_21 -> V_22 &&
V_145 . type == V_186 ) {
struct V_696 * V_697 ;
struct V_698 * V_699 ;
V_697 = & V_138 -> V_34 -> V_700 . V_701 ;
F_534 ( & V_697 -> V_48 ) ;
V_699 = F_535 ( V_697 , V_145 . V_22 ,
V_145 . V_33 ) ;
F_536 ( & V_697 -> V_48 ) ;
if ( ! V_699 ) {
F_173 ( V_34 ,
L_44 ,
V_145 . V_22 , V_145 . V_33 ) ;
V_29 = - V_159 ;
} else {
V_29 = 0 ;
}
F_537 ( V_699 ) ;
goto V_79;
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_79:
return V_29 ;
}
void F_538 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_298 * V_298 ;
V_14 = F_75 ( V_13 , V_69 ) ;
while ( V_14 ) {
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_171 )
break;
F_13 ( & V_14 -> V_48 ) ;
V_14 = F_255 ( V_13 , V_14 ) ;
}
if ( ! V_14 ) {
if ( V_69 == 0 )
break;
V_69 = 0 ;
continue;
}
V_298 = V_14 -> V_298 ;
V_14 -> V_171 = 0 ;
V_14 -> V_298 = NULL ;
F_13 ( & V_14 -> V_48 ) ;
ASSERT ( V_14 -> V_332 . V_298 == NULL ) ;
F_269 ( V_298 ) ;
V_69 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_539 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_108 * V_92 ;
struct V_46 * V_49 ;
struct V_15 * V_30 ;
F_71 ( & V_13 -> V_82 ) ;
while ( ! F_183 ( & V_13 -> V_106 ) ) {
V_49 = F_540 ( V_13 -> V_106 . V_78 ,
struct V_46 , V_96 ) ;
F_195 ( & V_49 -> V_96 ) ;
F_26 ( V_49 ) ;
}
F_73 ( & V_13 -> V_82 ) ;
F_11 ( & V_13 -> V_536 ) ;
while ( ! F_183 ( & V_13 -> V_538 ) ) {
V_14 = F_184 ( & V_13 -> V_538 ,
struct V_1 ,
V_537 ) ;
F_275 ( & V_14 -> V_537 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_536 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_201 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_194 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_541 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_71 ( & V_14 -> V_92 -> V_353 ) ;
F_195 ( & V_14 -> V_96 ) ;
F_73 ( & V_14 -> V_92 -> V_353 ) ;
if ( V_14 -> V_3 == V_104 )
F_439 ( V_14 ) ;
if ( V_14 -> V_3 == V_100 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 , V_14 ) ;
F_542 ( V_14 ) ;
ASSERT ( F_183 ( & V_14 -> V_330 ) ) ;
ASSERT ( F_183 ( & V_14 -> V_331 ) ) ;
ASSERT ( F_183 ( & V_14 -> V_537 ) ) ;
ASSERT ( F_212 ( & V_14 -> V_8 ) == 1 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_543 () ;
F_383 ( V_13 ) ;
while ( ! F_183 ( & V_13 -> V_92 ) ) {
int V_40 ;
V_92 = F_540 ( V_13 -> V_92 . V_78 ,
struct V_108 ,
V_96 ) ;
if ( F_8 ( V_92 -> V_354 > 0 ||
V_92 -> V_355 > 0 ||
V_92 -> V_356 > 0 ) )
F_332 ( V_13 , V_92 , 0 , 0 ) ;
F_195 ( & V_92 -> V_96 ) ;
for ( V_40 = 0 ; V_40 < V_351 ; V_40 ++ ) {
struct V_702 * V_365 ;
V_365 = V_92 -> V_703 [ V_40 ] ;
V_92 -> V_703 [ V_40 ] = NULL ;
if ( V_365 ) {
F_544 ( V_365 ) ;
F_545 ( V_365 ) ;
}
}
F_544 ( & V_92 -> V_365 ) ;
F_545 ( & V_92 -> V_365 ) ;
}
return 0 ;
}
static void F_546 ( struct V_108 * V_92 ,
struct V_1 * V_2 )
{
int V_599 = F_441 ( V_2 ) ;
bool V_254 = false ;
F_71 ( & V_92 -> V_353 ) ;
if ( F_183 ( & V_92 -> V_352 [ V_599 ] ) )
V_254 = true ;
F_72 ( & V_2 -> V_96 , & V_92 -> V_352 [ V_599 ] ) ;
F_73 ( & V_92 -> V_353 ) ;
if ( V_254 ) {
struct V_704 * V_705 ;
int V_29 ;
V_705 = F_61 ( sizeof( * V_705 ) , V_95 ) ;
if ( ! V_705 )
goto V_706;
V_705 -> V_386 = V_599 ;
F_547 ( & V_705 -> V_365 , & V_707 ) ;
V_29 = F_548 ( & V_705 -> V_365 , & V_92 -> V_365 ,
L_9 , F_442 ( V_599 ) ) ;
if ( V_29 ) {
F_545 ( & V_705 -> V_365 ) ;
goto V_706;
}
V_92 -> V_703 [ V_599 ] = & V_705 -> V_365 ;
}
return;
V_706:
F_426 ( V_2 -> V_34 ,
L_45 ) ;
}
static struct V_1 *
F_549 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_57 )
{
struct V_1 * V_2 ;
V_2 = F_61 ( sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_61 ( sizeof( * V_2 -> V_11 ) ,
V_95 ) ;
if ( ! V_2 -> V_11 ) {
F_9 ( V_2 ) ;
return NULL ;
}
V_2 -> V_21 . V_22 = V_32 ;
V_2 -> V_21 . V_33 = V_57 ;
V_2 -> V_21 . type = V_186 ;
V_2 -> V_53 = V_34 -> V_53 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_708 = F_550 ( V_34 ,
& V_34 -> V_700 ,
V_32 ) ;
F_551 ( V_2 ) ;
F_65 ( & V_2 -> V_8 , 1 ) ;
F_293 ( & V_2 -> V_48 ) ;
F_292 ( & V_2 -> V_590 ) ;
F_62 ( & V_2 -> V_96 ) ;
F_62 ( & V_2 -> V_709 ) ;
F_62 ( & V_2 -> V_537 ) ;
F_62 ( & V_2 -> V_682 ) ;
F_62 ( & V_2 -> V_330 ) ;
F_62 ( & V_2 -> V_331 ) ;
F_552 ( V_2 ) ;
F_65 ( & V_2 -> V_710 , 0 ) ;
F_63 ( & V_2 -> V_711 ) ;
return V_2 ;
}
int F_553 ( struct V_12 * V_13 )
{
struct V_63 * V_64 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_108 * V_92 ;
struct V_67 V_21 ;
struct V_67 V_145 ;
struct V_65 * V_66 ;
int V_712 = 0 ;
T_2 V_713 ;
T_2 V_714 ;
int V_715 ;
V_714 = F_554 ( V_13 -> V_260 ) ;
V_715 = ! ! ( V_714 & V_716 ) ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_186 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_64 -> V_75 = V_76 ;
V_713 = F_555 ( V_13 -> V_260 ) ;
if ( F_265 ( V_13 , V_312 ) &&
F_556 ( V_13 -> V_260 ) != V_713 )
V_712 = 1 ;
if ( F_265 ( V_13 , V_717 ) )
V_712 = 1 ;
while ( 1 ) {
V_29 = F_533 ( V_13 , V_64 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_66 = V_64 -> V_80 [ 0 ] ;
F_41 ( V_66 , & V_145 , V_64 -> V_81 [ 0 ] ) ;
V_2 = F_549 ( V_13 , V_145 . V_22 ,
V_145 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_712 ) {
if ( F_265 ( V_13 , V_312 ) )
V_2 -> V_305 = V_321 ;
}
F_557 ( V_66 , & V_2 -> V_93 ,
F_253 ( V_66 , V_64 -> V_81 [ 0 ] ) ,
sizeof( V_2 -> V_93 ) ) ;
V_2 -> V_7 = F_558 ( & V_2 -> V_93 ) ;
if ( ! V_715 &&
( ( V_2 -> V_7 & V_51 ) &&
( V_2 -> V_7 & V_339 ) ) ) {
F_173 ( V_13 ,
L_46 ,
V_2 -> V_21 . V_22 ) ;
V_29 = - V_540 ;
goto error;
}
V_21 . V_22 = V_145 . V_22 + V_145 . V_33 ;
F_45 ( V_64 ) ;
V_29 = F_21 ( V_13 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_13 , V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
if ( V_145 . V_33 == F_58 ( & V_2 -> V_93 ) ) {
V_2 -> V_103 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_19 ( V_13 , V_2 ) ;
} else if ( F_58 ( & V_2 -> V_93 ) == 0 ) {
V_2 -> V_103 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
F_29 ( V_2 , V_13 ,
V_145 . V_22 ,
V_145 . V_22 +
V_145 . V_33 ) ;
F_19 ( V_13 , V_2 ) ;
}
V_29 = F_10 ( V_13 , V_2 ) ;
if ( V_29 ) {
F_542 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_559 ( V_13 , V_2 , 0 ) ;
V_29 = F_289 ( V_13 , V_2 -> V_7 , V_145 . V_33 ,
F_58 ( & V_2 -> V_93 ) ,
V_2 -> V_43 , & V_92 ) ;
if ( V_29 ) {
F_542 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_541 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_92 = V_92 ;
F_546 ( V_92 , V_2 ) ;
F_296 ( V_13 , V_2 -> V_7 ) ;
if ( F_560 ( V_13 , V_2 -> V_21 . V_22 ) ) {
F_525 ( V_2 , 1 ) ;
} else if ( F_58 ( & V_2 -> V_93 ) == 0 ) {
F_11 ( & V_13 -> V_536 ) ;
if ( F_183 ( & V_2 -> V_537 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_537 ,
& V_13 -> V_538 ) ;
}
F_13 ( & V_13 -> V_536 ) ;
}
}
F_79 (space_info, &info->space_info, list) {
if ( ! ( F_303 ( V_13 , V_92 -> V_7 ) &
( V_346 |
V_345 |
V_393 |
V_392 |
V_344 ) ) )
continue;
F_235 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_525 ( V_2 , 1 ) ;
F_235 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_525 ( V_2 , 1 ) ;
}
F_382 ( V_13 ) ;
V_29 = 0 ;
error:
F_53 ( V_64 ) ;
return V_29 ;
}
void F_228 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_14 , * V_317 ;
struct V_61 * V_62 = V_34 -> V_62 ;
struct V_718 V_93 ;
struct V_67 V_21 ;
int V_29 = 0 ;
bool V_278 = V_115 -> V_278 ;
V_115 -> V_278 = false ;
F_271 (block_group, tmp, &trans->new_bgs, bg_list) {
if ( V_29 )
goto V_78;
F_11 ( & V_14 -> V_48 ) ;
memcpy ( & V_93 , & V_14 -> V_93 , sizeof( V_93 ) ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_13 ( & V_14 -> V_48 ) ;
V_29 = F_561 ( V_115 , V_62 , & V_21 , & V_93 ,
sizeof( V_93 ) ) ;
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
V_29 = F_562 ( V_115 , V_34 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
F_563 ( V_115 , V_34 , V_14 ) ;
V_78:
F_275 ( & V_14 -> V_537 ) ;
}
V_115 -> V_278 = V_278 ;
}
int F_564 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_91 ,
T_2 type , T_2 V_719 , T_2 V_720 ,
T_2 V_57 )
{
struct V_1 * V_2 ;
int V_29 ;
F_565 ( V_34 , V_115 ) ;
V_2 = F_549 ( V_34 , V_720 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_406 ( & V_2 -> V_93 , V_91 ) ;
F_566 ( & V_2 -> V_93 , V_719 ) ;
F_567 ( & V_2 -> V_93 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_103 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_721 = 1 ;
V_29 = F_21 ( V_34 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_34 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_34 , V_720 , V_720 + V_57 ) ;
F_19 ( V_34 , V_2 ) ;
#ifdef F_36
if ( F_37 ( V_2 ) ) {
T_2 V_722 = V_57 - V_91 ;
V_91 += V_722 >> 1 ;
F_27 ( V_2 ) ;
}
#endif
V_29 = F_289 ( V_34 , V_2 -> V_7 , 0 , 0 , 0 ,
& V_2 -> V_92 ) ;
if ( V_29 ) {
F_542 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_34 , V_2 ) ;
if ( V_29 ) {
F_542 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_559 ( V_34 , V_2 , 1 ) ;
V_29 = F_289 ( V_34 , V_2 -> V_7 , V_57 , V_91 ,
V_2 -> V_43 , & V_2 -> V_92 ) ;
if ( V_29 ) {
F_542 ( V_2 ) ;
F_11 ( & V_34 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_34 -> V_19 ) ;
F_541 ( & V_2 -> V_20 ) ;
F_13 ( & V_34 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_380 ( V_34 ) ;
F_546 ( V_2 -> V_92 , V_2 ) ;
F_72 ( & V_2 -> V_537 , & V_115 -> V_281 ) ;
F_296 ( V_34 , type ) ;
return 0 ;
}
static void F_568 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_369 = F_297 ( V_7 ) &
V_370 ;
F_298 ( & V_34 -> V_371 ) ;
if ( V_7 & V_339 )
V_34 -> V_372 &= ~ V_369 ;
if ( V_7 & V_51 )
V_34 -> V_373 &= ~ V_369 ;
if ( V_7 & V_340 )
V_34 -> V_374 &= ~ V_369 ;
F_299 ( & V_34 -> V_371 ) ;
}
int F_569 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_723 ,
struct V_698 * V_699 )
{
struct V_61 * V_138 = V_34 -> V_62 ;
struct V_63 * V_64 ;
struct V_1 * V_14 ;
struct V_548 * V_556 ;
struct V_61 * V_274 = V_34 -> V_274 ;
struct V_67 V_21 ;
struct V_298 * V_298 ;
struct V_702 * V_365 = NULL ;
int V_29 ;
int V_599 ;
int V_343 ;
struct V_46 * V_49 = NULL ;
bool V_724 ;
V_14 = F_76 ( V_34 , V_723 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_307 ) ;
F_19 ( V_34 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_599 = F_441 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_344 |
V_345 |
V_346 ) )
V_343 = 2 ;
else
V_343 = 1 ;
V_556 = & V_34 -> V_554 ;
F_11 ( & V_556 -> V_592 ) ;
F_453 ( V_14 , V_556 ) ;
F_13 ( & V_556 -> V_592 ) ;
V_556 = & V_34 -> V_552 ;
F_11 ( & V_556 -> V_592 ) ;
F_453 ( V_14 , V_556 ) ;
F_13 ( & V_556 -> V_592 ) ;
V_64 = F_34 () ;
if ( ! V_64 ) {
V_29 = - V_72 ;
goto V_79;
}
V_298 = F_258 ( V_274 , V_14 , V_64 ) ;
F_49 ( & V_115 -> V_132 -> V_329 ) ;
F_11 ( & V_115 -> V_132 -> V_328 ) ;
if ( ! F_183 ( & V_14 -> V_331 ) ) {
F_275 ( & V_14 -> V_331 ) ;
F_8 ( ! F_217 ( V_298 ) && V_298 != V_14 -> V_332 . V_298 ) ;
F_13 ( & V_115 -> V_132 -> V_328 ) ;
F_276 ( V_115 , V_14 , V_64 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_115 -> V_132 -> V_328 ) ;
}
if ( ! F_183 ( & V_14 -> V_330 ) ) {
F_275 ( & V_14 -> V_330 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_115 -> V_132 -> V_328 ) ;
F_47 ( & V_115 -> V_132 -> V_329 ) ;
if ( ! F_217 ( V_298 ) ) {
V_29 = F_570 ( V_115 , V_298 ) ;
if ( V_29 ) {
F_571 ( V_298 ) ;
goto V_79;
}
F_572 ( V_298 ) ;
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_171 ) {
V_14 -> V_171 = 0 ;
V_14 -> V_298 = NULL ;
F_13 ( & V_14 -> V_48 ) ;
F_269 ( V_298 ) ;
} else {
F_13 ( & V_14 -> V_48 ) ;
}
F_571 ( V_298 ) ;
}
V_21 . V_22 = V_725 ;
V_21 . V_33 = V_14 -> V_21 . V_22 ;
V_21 . type = 0 ;
V_29 = F_38 ( V_115 , V_274 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 < 0 )
goto V_79;
if ( V_29 > 0 )
F_45 ( V_64 ) ;
if ( V_29 == 0 ) {
V_29 = F_124 ( V_115 , V_274 , V_64 ) ;
if ( V_29 )
goto V_79;
F_45 ( V_64 ) ;
}
F_11 ( & V_34 -> V_18 ) ;
F_194 ( & V_14 -> V_20 ,
& V_34 -> V_19 ) ;
F_541 ( & V_14 -> V_20 ) ;
if ( V_34 -> V_26 == V_14 -> V_21 . V_22 )
V_34 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_34 -> V_18 ) ;
F_71 ( & V_14 -> V_92 -> V_353 ) ;
F_275 ( & V_14 -> V_96 ) ;
if ( F_183 ( & V_14 -> V_92 -> V_352 [ V_599 ] ) ) {
V_365 = V_14 -> V_92 -> V_703 [ V_599 ] ;
V_14 -> V_92 -> V_703 [ V_599 ] = NULL ;
F_568 ( V_34 , V_14 -> V_7 ) ;
}
F_73 ( & V_14 -> V_92 -> V_353 ) ;
if ( V_365 ) {
F_544 ( V_365 ) ;
F_545 ( V_365 ) ;
}
if ( V_14 -> V_105 )
V_49 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_104 )
F_439 ( V_14 ) ;
if ( V_14 -> V_105 ) {
F_71 ( & V_34 -> V_82 ) ;
if ( ! V_49 ) {
struct V_46 * V_47 ;
F_235 (ctl,
&fs_info->caching_block_groups, list)
if ( V_47 -> V_14 == V_14 ) {
V_49 = V_47 ;
F_5 ( & V_49 -> V_8 ) ;
break;
}
}
if ( V_49 )
F_275 ( & V_49 -> V_96 ) ;
F_73 ( & V_34 -> V_82 ) ;
if ( V_49 ) {
F_26 ( V_49 ) ;
F_26 ( V_49 ) ;
}
}
F_11 ( & V_115 -> V_132 -> V_328 ) ;
if ( ! F_183 ( & V_14 -> V_330 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_183 ( & V_14 -> V_331 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_115 -> V_132 -> V_328 ) ;
F_542 ( V_14 ) ;
F_11 ( & V_14 -> V_92 -> V_48 ) ;
F_275 ( & V_14 -> V_682 ) ;
if ( F_265 ( V_34 , V_423 ) ) {
F_8 ( V_14 -> V_92 -> V_341
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_92 -> V_342
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_92 -> V_347
< V_14 -> V_21 . V_33 * V_343 ) ;
}
V_14 -> V_92 -> V_341 -= V_14 -> V_21 . V_33 ;
V_14 -> V_92 -> V_342 -= V_14 -> V_21 . V_33 ;
V_14 -> V_92 -> V_347 -= V_14 -> V_21 . V_33 * V_343 ;
F_13 ( & V_14 -> V_92 -> V_48 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_49 ( & V_34 -> V_422 ) ;
if ( ! F_183 ( & V_699 -> V_96 ) ) {
F_537 ( V_699 ) ;
}
F_11 ( & V_14 -> V_48 ) ;
V_14 -> V_726 = 1 ;
V_724 = ( F_212 ( & V_14 -> V_710 ) == 0 ) ;
if ( ! V_724 ) {
F_573 ( & V_699 -> V_96 , & V_34 -> V_727 ) ;
}
F_13 ( & V_14 -> V_48 ) ;
if ( V_724 ) {
struct V_696 * V_697 ;
V_697 = & V_34 -> V_700 . V_701 ;
F_574 ( & V_697 -> V_48 ) ;
F_575 ( V_697 , V_699 ) ;
F_576 ( & V_697 -> V_48 ) ;
F_537 ( V_699 ) ;
}
F_47 ( & V_34 -> V_422 ) ;
V_29 = F_577 ( V_115 , V_34 , V_14 ) ;
if ( V_29 )
goto V_79;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_38 ( V_115 , V_138 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_182 ;
if ( V_29 < 0 )
goto V_79;
V_29 = F_124 ( V_115 , V_138 , V_64 ) ;
V_79:
F_53 ( V_64 ) ;
return V_29 ;
}
struct V_114 *
F_578 ( struct V_12 * V_34 ,
const T_2 V_720 )
{
struct V_696 * V_697 = & V_34 -> V_700 . V_701 ;
struct V_698 * V_699 ;
struct V_728 * V_729 ;
unsigned int V_730 ;
F_534 ( & V_697 -> V_48 ) ;
V_699 = F_535 ( V_697 , V_720 , 1 ) ;
F_536 ( & V_697 -> V_48 ) ;
ASSERT ( V_699 && V_699 -> V_32 == V_720 ) ;
V_729 = V_699 -> V_728 ;
V_730 = 3 + V_729 -> V_209 ;
F_537 ( V_699 ) ;
return F_579 ( V_34 -> V_62 ,
V_730 , 1 ) ;
}
void F_580 ( struct V_12 * V_34 )
{
struct V_1 * V_14 ;
struct V_108 * V_92 ;
struct V_114 * V_115 ;
int V_29 = 0 ;
if ( ! F_226 ( V_731 , & V_34 -> V_7 ) )
return;
F_11 ( & V_34 -> V_536 ) ;
while ( ! F_183 ( & V_34 -> V_538 ) ) {
T_2 V_32 , V_31 ;
int V_710 ;
V_14 = F_184 ( & V_34 -> V_538 ,
struct V_1 ,
V_537 ) ;
F_275 ( & V_14 -> V_537 ) ;
V_92 = V_14 -> V_92 ;
if ( V_29 || F_335 ( V_92 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_34 -> V_536 ) ;
F_49 ( & V_34 -> V_732 ) ;
F_71 ( & V_92 -> V_353 ) ;
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_10 ||
F_58 ( & V_14 -> V_93 ) ||
V_14 -> V_307 ||
F_581 ( & V_14 -> V_96 ) ) {
F_13 ( & V_14 -> V_48 ) ;
F_73 ( & V_92 -> V_353 ) ;
goto V_78;
}
F_13 ( & V_14 -> V_48 ) ;
V_29 = F_525 ( V_14 , 0 ) ;
F_73 ( & V_92 -> V_353 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_78;
}
V_115 = F_578 ( V_34 ,
V_14 -> V_21 . V_22 ) ;
if ( F_217 ( V_115 ) ) {
F_530 ( V_14 ) ;
V_29 = F_218 ( V_115 ) ;
goto V_78;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_49 ( & V_34 -> V_563 ) ;
V_29 = F_20 ( & V_34 -> V_36 [ 0 ] , V_32 , V_31 ,
V_60 ) ;
if ( V_29 ) {
F_47 ( & V_34 -> V_563 ) ;
F_530 ( V_14 ) ;
goto V_733;
}
V_29 = F_20 ( & V_34 -> V_36 [ 1 ] , V_32 , V_31 ,
V_60 ) ;
if ( V_29 ) {
F_47 ( & V_34 -> V_563 ) ;
F_530 ( V_14 ) ;
goto V_733;
}
F_47 ( & V_34 -> V_563 ) ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_14 -> V_48 ) ;
V_92 -> V_354 -= V_14 -> V_9 ;
V_92 -> V_342 += V_14 -> V_9 ;
F_421 ( & V_92 -> V_349 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
V_710 = F_265 ( V_34 , V_564 ) ;
if ( V_710 )
F_582 ( V_14 ) ;
V_29 = F_583 ( V_115 , V_34 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_710 )
F_424 ( V_14 ) ;
goto V_733;
}
if ( V_710 ) {
F_11 ( & V_34 -> V_536 ) ;
F_584 ( & V_14 -> V_537 ,
& V_115 -> V_132 -> V_560 ) ;
F_13 ( & V_34 -> V_536 ) ;
F_4 ( V_14 ) ;
}
V_733:
F_220 ( V_115 ) ;
V_78:
F_47 ( & V_34 -> V_732 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_34 -> V_536 ) ;
}
F_13 ( & V_34 -> V_536 ) ;
}
int F_585 ( struct V_12 * V_34 )
{
struct V_108 * V_92 ;
struct V_734 * V_735 ;
T_2 V_736 ;
T_2 V_7 ;
int V_715 = 0 ;
int V_29 ;
V_735 = V_34 -> V_260 ;
if ( ! F_586 ( V_735 ) )
return - V_540 ;
V_736 = F_554 ( V_735 ) ;
if ( V_736 & V_716 )
V_715 = 1 ;
V_7 = V_340 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
if ( V_29 )
goto V_79;
if ( V_715 ) {
V_7 = V_51 | V_339 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
} else {
V_7 = V_51 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
if ( V_29 )
goto V_79;
V_7 = V_339 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
}
V_79:
return V_29 ;
}
int F_587 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_31 )
{
return F_420 ( V_34 , V_32 , V_31 , false ) ;
}
static int F_588 ( struct V_688 * V_689 ,
T_2 V_737 , T_2 * V_565 )
{
T_2 V_32 = 0 , V_45 = 0 ;
int V_29 ;
* V_565 = 0 ;
if ( ! V_689 -> V_738 )
return 0 ;
if ( V_689 -> V_341 <= V_689 -> V_91 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_34 = V_689 -> V_34 ;
struct V_318 * V_115 ;
T_2 V_210 ;
V_29 = F_589 ( & V_34 -> V_422 ) ;
if ( V_29 )
return V_29 ;
F_50 ( & V_34 -> V_82 ) ;
F_11 ( & V_34 -> V_739 ) ;
V_115 = V_34 -> V_740 ;
if ( V_115 )
F_5 ( & V_115 -> V_741 ) ;
F_13 ( & V_34 -> V_739 ) ;
V_29 = F_590 ( V_115 , V_689 , V_737 , V_32 ,
& V_32 , & V_45 ) ;
if ( V_115 )
F_591 ( V_115 ) ;
if ( V_29 ) {
F_46 ( & V_34 -> V_82 ) ;
F_47 ( & V_34 -> V_422 ) ;
if ( V_29 == - V_314 )
V_29 = 0 ;
break;
}
V_29 = F_148 ( V_689 -> V_193 , V_32 , V_45 , & V_210 ) ;
F_46 ( & V_34 -> V_82 ) ;
F_47 ( & V_34 -> V_422 ) ;
if ( V_29 )
break;
V_32 += V_45 ;
* V_565 += V_210 ;
if ( F_592 ( V_401 ) ) {
V_29 = - V_742 ;
break;
}
F_48 () ;
}
return V_29 ;
}
int F_593 ( struct V_12 * V_34 , struct V_743 * V_744 )
{
struct V_1 * V_2 = NULL ;
struct V_688 * V_689 ;
struct V_109 * V_745 ;
T_2 V_746 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_565 = 0 ;
T_2 V_341 = F_324 ( V_34 -> V_260 ) ;
int V_29 = 0 ;
if ( V_744 -> V_45 == V_341 )
V_2 = F_75 ( V_34 , V_744 -> V_32 ) ;
else
V_2 = F_76 ( V_34 , V_744 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_744 -> V_32 + V_744 -> V_45 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_450 ( V_744 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_344 ( V_744 -> V_32 + V_744 -> V_45 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_744 -> V_737 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_59 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_439 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_594 ( V_2 ,
& V_746 ,
V_32 ,
V_31 ,
V_744 -> V_737 ) ;
V_565 += V_746 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_255 ( V_34 , V_2 ) ;
}
F_49 ( & V_34 -> V_384 -> V_747 ) ;
V_745 = & V_34 -> V_384 -> V_748 ;
F_235 (device, devices, dev_alloc_list) {
V_29 = F_588 ( V_689 , V_744 -> V_737 ,
& V_746 ) ;
if ( V_29 )
break;
V_565 += V_746 ;
}
F_47 ( & V_34 -> V_384 -> V_747 ) ;
V_744 -> V_45 = V_565 ;
return V_29 ;
}
void F_595 ( struct V_61 * V_138 )
{
F_596 ( & V_138 -> V_749 -> V_750 ) ;
F_2 () ;
if ( F_597 ( & V_138 -> V_749 -> V_87 ) )
F_52 ( & V_138 -> V_749 -> V_87 ) ;
}
int F_598 ( struct V_61 * V_138 )
{
if ( F_212 ( & V_138 -> V_751 ) )
return 0 ;
F_599 ( & V_138 -> V_749 -> V_750 ) ;
F_2 () ;
if ( F_212 ( & V_138 -> V_751 ) ) {
F_595 ( V_138 ) ;
return 0 ;
}
return 1 ;
}
static int F_600 ( T_7 * V_338 )
{
F_68 () ;
return 0 ;
}
void F_601 ( struct V_61 * V_138 )
{
while ( true ) {
int V_29 ;
V_29 = F_598 ( V_138 ) ;
if ( V_29 )
break;
F_287 ( & V_138 -> V_751 ,
F_600 ,
V_99 ) ;
}
}
