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
V_110 = F_92 ( V_120 , V_27 ) ;
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
struct V_12 * V_34 ,
struct V_63 * V_64 ,
T_2 V_138 , T_3 V_139 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
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
if ( V_138 == ( T_2 ) - 1 ) {
while ( 1 ) {
if ( V_64 -> V_81 [ 0 ] >= F_39 ( V_66 ) ) {
V_29 = F_51 ( V_140 , V_64 ) ;
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
V_138 = F_96 ( V_66 , V_142 ) ;
break;
}
}
F_45 ( V_64 ) ;
if ( V_138 < V_148 )
V_146 += sizeof( * V_144 ) ;
V_146 -= sizeof( * V_130 ) ;
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 ,
V_146 + V_139 , 1 ) ;
if ( V_29 < 0 )
return V_29 ;
F_32 ( V_29 ) ;
F_97 ( V_34 , V_64 , V_146 ) ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_93 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] , struct V_121 ) ;
F_98 ( V_66 , V_93 , V_117 ) ;
F_99 ( V_66 , V_93 , 0 ) ;
if ( V_138 < V_148 ) {
F_100 ( V_66 , V_93 ,
V_149 |
V_131 ) ;
V_144 = (struct V_143 * ) ( V_93 + 1 ) ;
F_101 ( V_66 , ( unsigned long ) V_144 , sizeof( * V_144 ) ) ;
F_102 ( V_66 , V_144 , ( int ) V_138 ) ;
} else {
F_100 ( V_66 , V_93 , V_150 ) ;
}
F_103 ( V_66 ) ;
return 0 ;
}
static T_2 F_104 ( T_2 V_151 , T_2 V_138 , T_2 V_33 )
{
T_3 V_152 = ~ ( T_3 ) 0 ;
T_3 V_153 = ~ ( T_3 ) 0 ;
T_4 V_154 ;
V_154 = F_105 ( V_151 ) ;
V_152 = F_106 ( V_152 , & V_154 , sizeof( V_154 ) ) ;
V_154 = F_105 ( V_138 ) ;
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
T_2 V_151 , T_2 V_138 , T_2 V_33 )
{
if ( F_108 ( V_66 , V_156 ) != V_151 ||
F_109 ( V_66 , V_156 ) != V_138 ||
F_110 ( V_66 , V_156 ) != V_33 )
return 0 ;
return 1 ;
}
static T_1 int F_112 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 ,
T_2 V_138 , T_2 V_33 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
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
V_138 , V_33 ) ;
}
V_162:
V_157 = 0 ;
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 , - 1 , 1 ) ;
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
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 , - 1 , 1 ) ;
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
V_29 = F_51 ( V_140 , V_64 ) ;
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
V_138 , V_33 ) ) {
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
struct V_12 * V_34 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 , T_2 V_138 ,
T_2 V_33 , int V_164 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
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
V_138 , V_33 ) ;
V_57 = sizeof( struct V_155 ) ;
}
V_29 = F_114 ( V_115 , V_140 , V_64 , & V_21 , V_57 ) ;
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
V_138 , V_33 ) )
break;
F_45 ( V_64 ) ;
V_21 . V_33 ++ ;
V_29 = F_114 ( V_115 , V_140 , V_64 , & V_21 ,
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
F_118 ( V_66 , V_156 , V_138 ) ;
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
struct V_12 * V_34 ,
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
V_29 = F_124 ( V_115 , V_34 -> V_62 , V_64 ) ;
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
struct V_12 * V_34 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 ,
T_2 V_151 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
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
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_159 ;
#ifdef F_89
if ( V_29 == - V_159 && V_17 ) {
F_45 ( V_64 ) ;
V_21 . type = V_147 ;
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_159 ;
}
#endif
return V_29 ;
}
static T_1 int F_129 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
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
V_29 = F_114 ( V_115 , V_34 -> V_62 ,
V_64 , & V_21 , 0 ) ;
F_45 ( V_64 ) ;
return V_29 ;
}
static inline int F_130 ( T_2 V_17 , T_2 V_138 )
{
int type ;
if ( V_138 < V_148 ) {
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
struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_170 * * V_176 ,
T_2 V_27 , T_2 V_35 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_138 , T_2 V_33 , int V_177 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
struct V_67 V_21 ;
struct V_65 * V_66 ;
struct V_121 * V_122 ;
struct V_170 * V_171 ;
T_2 V_7 ;
T_2 V_123 ;
unsigned long V_178 ;
unsigned long V_31 ;
int V_139 ;
int type ;
int V_179 ;
int V_29 ;
int V_158 = 0 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
V_21 . V_22 = V_27 ;
V_21 . type = V_77 ;
V_21 . V_33 = V_35 ;
V_179 = F_130 ( V_17 , V_138 ) ;
if ( V_177 ) {
V_139 = F_133 ( V_179 ) ;
V_64 -> V_181 = 1 ;
} else
V_139 = - 1 ;
if ( V_180 && V_138 < V_148 ) {
V_21 . type = V_85 ;
V_21 . V_33 = V_138 ;
}
V_162:
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 , V_139 , 1 ) ;
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
V_29 = F_95 ( V_115 , V_34 , V_64 , V_138 ,
V_139 ) ;
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
V_138 , V_33 ) ) {
V_158 = 0 ;
break;
}
if ( F_107 ( V_66 , V_183 ) <
F_104 ( V_151 , V_138 , V_33 ) )
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
if ( V_123 + V_139 >=
F_135 ( V_140 ) ) {
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
void F_137 ( struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_170 * V_171 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_138 , T_2 V_33 , int V_164 ,
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
type = F_130 ( V_17 , V_138 ) ;
V_57 = F_133 ( type ) ;
F_97 ( V_34 , V_64 , V_57 ) ;
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
F_118 ( V_66 , V_183 , V_138 ) ;
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
struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_170 * * V_176 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 ,
T_2 V_151 , T_2 V_138 , T_2 V_33 )
{
int V_29 ;
V_29 = F_132 ( V_115 , V_34 , V_64 , V_176 ,
V_27 , V_35 , V_17 ,
V_151 , V_138 , V_33 , 0 ) ;
if ( V_29 != - V_159 )
return V_29 ;
F_45 ( V_64 ) ;
* V_176 = NULL ;
if ( V_138 < V_148 ) {
V_29 = F_128 ( V_115 , V_34 , V_64 , V_27 ,
V_17 , V_151 ) ;
} else {
V_29 = F_112 ( V_115 , V_34 , V_64 , V_27 ,
V_17 , V_151 , V_138 ,
V_33 ) ;
}
return V_29 ;
}
static T_5
void F_143 ( struct V_12 * V_34 ,
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
F_144 ( V_34 , V_64 , V_123 , 1 ) ;
}
F_103 ( V_66 ) ;
}
static T_5
int F_145 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 ,
T_2 V_151 , T_2 V_138 ,
T_2 V_33 , int V_164 ,
struct V_187 * V_134 )
{
struct V_170 * V_171 ;
int V_29 ;
V_29 = F_132 ( V_115 , V_34 , V_64 , & V_171 ,
V_27 , V_35 , V_17 ,
V_151 , V_138 , V_33 , 1 ) ;
if ( V_29 == 0 ) {
F_32 ( V_138 < V_148 ) ;
F_143 ( V_34 , V_64 , V_171 ,
V_164 , V_134 , NULL ) ;
} else if ( V_29 == - V_159 ) {
F_137 ( V_34 , V_64 , V_171 , V_17 ,
V_151 , V_138 , V_33 ,
V_164 , V_134 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static int F_146 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_63 * V_64 ,
T_2 V_27 , T_2 V_17 , T_2 V_151 ,
T_2 V_138 , T_2 V_33 , int V_164 )
{
int V_29 ;
if ( V_138 < V_148 ) {
F_32 ( V_164 != 1 ) ;
V_29 = F_129 ( V_115 , V_34 , V_64 , V_27 ,
V_17 , V_151 ) ;
} else {
V_29 = F_113 ( V_115 , V_34 , V_64 , V_27 ,
V_17 , V_151 ,
V_138 , V_33 , V_164 ) ;
}
return V_29 ;
}
static int F_147 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_170 * V_171 ,
int V_166 , int V_191 , int * V_167 )
{
int V_29 = 0 ;
F_32 ( ! V_191 && V_166 != 1 ) ;
if ( V_171 ) {
F_143 ( V_34 , V_64 , V_171 ,
- V_166 , NULL , V_167 ) ;
} else if ( V_191 ) {
V_29 = F_122 ( V_115 , V_34 , V_64 , V_166 ,
V_167 ) ;
} else {
* V_167 = 1 ;
V_29 = F_124 ( V_115 , V_34 -> V_62 , V_64 ) ;
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
T_2 V_151 , T_2 V_138 , T_2 V_33 )
{
int V_29 ;
F_32 ( V_138 < V_148 &&
V_151 == V_215 ) ;
if ( V_138 < V_148 ) {
V_29 = F_159 ( V_34 , V_115 , V_27 ,
V_35 ,
V_17 , V_151 , ( int ) V_138 ,
V_216 , NULL ) ;
} else {
V_29 = F_160 ( V_34 , V_115 , V_27 ,
V_35 , V_17 , V_151 ,
V_138 , V_33 , 0 ,
V_216 ) ;
}
return V_29 ;
}
static int F_161 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
struct V_217 * V_133 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_138 , T_2 V_33 , int V_164 ,
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
V_29 = F_145 ( V_115 , V_34 , V_64 , V_27 ,
V_35 , V_17 , V_151 ,
V_138 , V_33 ,
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
V_29 = F_146 ( V_115 , V_34 , V_64 , V_27 , V_17 ,
V_151 , V_138 , V_33 , V_164 ) ;
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
V_222 = V_156 -> V_140 ;
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
V_29 = F_95 ( V_115 , V_34 , V_64 , ( T_2 ) - 1 , 0 ) ;
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
V_222 = V_156 -> V_140 ;
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
static T_2 F_199 ( struct V_250 * V_140 )
{
struct V_15 * V_30 = V_140 -> V_15 ;
struct V_217 * V_251 ;
int V_252 = 1 ;
T_2 V_253 ;
T_2 V_254 = 0 , V_69 = 0 ;
V_30 = F_200 ( V_140 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_217 , V_15 ) ;
V_254 = V_251 -> V_27 ;
}
V_30 = F_201 ( V_140 ) ;
if ( V_30 ) {
V_251 = F_12 ( V_30 , struct V_217 , V_15 ) ;
V_69 = V_251 -> V_27 ;
}
V_30 = V_140 -> V_15 ;
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
struct V_12 * V_34 = V_270 -> V_140 -> V_34 ;
int V_29 ;
if ( F_215 ( V_34 ) )
goto V_271;
V_115 = F_216 ( V_270 -> V_140 ) ;
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
V_270 -> V_140 = V_34 -> V_274 ;
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
V_120 -> V_280 = F_199 ( & V_120 -> V_140 ) ;
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
static T_1 int F_234 ( struct V_61 * V_140 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_118 * V_110 ;
struct V_217 * V_156 ;
struct V_220 * V_282 ;
struct V_119 * V_120 ;
struct V_283 * V_284 ;
int V_29 = 0 ;
V_284 = V_140 -> V_34 -> V_285 ;
if ( ! V_284 )
return 0 ;
V_120 = & V_284 -> V_120 ;
F_11 ( & V_120 -> V_48 ) ;
V_110 = F_92 ( V_120 , V_27 ) ;
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
if ( V_282 -> V_140 != V_140 -> V_286 . V_22 ||
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
static T_1 int F_236 ( struct V_61 * V_140 ,
struct V_63 * V_64 ,
T_2 V_22 , T_2 V_33 , T_2 V_27 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
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
F_238 ( & V_140 -> V_287 ) )
goto V_79;
V_171 = (struct V_170 * ) ( V_122 + 1 ) ;
if ( F_127 ( V_66 , V_171 ) !=
V_161 )
goto V_79;
V_156 = (struct V_155 * ) ( & V_171 -> V_33 ) ;
if ( F_87 ( V_66 , V_122 ) !=
F_121 ( V_66 , V_156 ) ||
F_108 ( V_66 , V_156 ) !=
V_140 -> V_286 . V_22 ||
F_109 ( V_66 , V_156 ) != V_22 ||
F_110 ( V_66 , V_156 ) != V_33 )
goto V_79;
V_29 = 0 ;
V_79:
return V_29 ;
}
int F_239 ( struct V_61 * V_140 , T_2 V_22 , T_2 V_33 ,
T_2 V_27 )
{
struct V_63 * V_64 ;
int V_29 ;
int V_288 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_159 ;
do {
V_29 = F_236 ( V_140 , V_64 , V_22 ,
V_33 , V_27 ) ;
if ( V_29 && V_29 != - V_159 )
goto V_79;
V_288 = F_234 ( V_140 , V_64 , V_22 ,
V_33 , V_27 ) ;
} while ( V_288 == - V_185 );
if ( V_288 && V_288 != - V_159 ) {
V_29 = V_288 ;
goto V_79;
}
if ( V_29 != - V_159 || V_288 != - V_159 )
V_29 = 0 ;
V_79:
F_53 ( V_64 ) ;
if ( V_140 -> V_286 . V_22 == V_289 )
F_8 ( V_29 > 0 ) ;
return V_29 ;
}
static int F_240 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_65 * V_290 ,
int V_291 , int V_292 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
T_2 V_27 ;
T_2 V_35 ;
T_2 V_17 ;
T_2 V_222 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_293 * V_294 ;
int V_40 ;
int V_174 ;
int V_29 = 0 ;
int (* F_241)( struct V_114 * ,
struct V_12 * ,
T_2 , T_2 , T_2 , T_2 , T_2 , T_2 );
if ( F_242 ( V_34 ) )
return 0 ;
V_222 = F_243 ( V_290 ) ;
V_70 = F_39 ( V_290 ) ;
V_174 = F_244 ( V_290 ) ;
if ( ! F_226 ( V_295 , & V_140 -> V_296 ) && V_174 == 0 )
return 0 ;
if ( V_292 )
F_241 = F_158 ;
else
F_241 = V_297 ;
if ( V_291 )
V_17 = V_290 -> V_32 ;
else
V_17 = 0 ;
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ ) {
if ( V_174 == 0 ) {
F_41 ( V_290 , & V_21 , V_40 ) ;
if ( V_21 . type != V_298 )
continue;
V_294 = F_86 ( V_290 , V_40 ,
struct V_293 ) ;
if ( F_245 ( V_290 , V_294 ) ==
V_299 )
continue;
V_27 = F_246 ( V_290 , V_294 ) ;
if ( V_27 == 0 )
continue;
V_35 = F_247 ( V_290 , V_294 ) ;
V_21 . V_33 -= F_248 ( V_290 , V_294 ) ;
V_29 = F_241 ( V_115 , V_34 , V_27 , V_35 ,
V_17 , V_222 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
goto V_163;
} else {
V_27 = F_249 ( V_290 , V_40 ) ;
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
int F_250 ( struct V_114 * V_115 , struct V_61 * V_140 ,
struct V_65 * V_290 , int V_291 )
{
return F_240 ( V_115 , V_140 , V_290 , V_291 , 1 ) ;
}
int F_251 ( struct V_114 * V_115 , struct V_61 * V_140 ,
struct V_65 * V_290 , int V_291 )
{
return F_240 ( V_115 , V_140 , V_290 , V_291 , 0 ) ;
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
const T_2 V_300 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ;
F_13 ( & V_34 -> V_18 ) ;
F_6 ( V_2 ) ;
V_2 = F_75 ( V_34 , V_300 ) ; return V_2 ;
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
struct V_61 * V_140 = V_34 -> V_274 ;
struct V_301 * V_301 = NULL ;
T_2 V_302 = 0 ;
int V_303 = V_304 ;
T_2 V_305 = 0 ;
int V_306 = 0 ;
int V_29 = 0 ;
if ( V_14 -> V_21 . V_33 < ( 100 * V_307 ) ) {
F_11 ( & V_14 -> V_48 ) ;
V_14 -> V_308 = V_309 ;
F_13 ( & V_14 -> V_48 ) ;
return 0 ;
}
if ( V_115 -> V_226 )
return 0 ;
V_162:
V_301 = F_258 ( V_34 , V_14 , V_64 ) ;
if ( F_217 ( V_301 ) && F_218 ( V_301 ) != - V_159 ) {
V_29 = F_218 ( V_301 ) ;
F_45 ( V_64 ) ;
goto V_79;
}
if ( F_217 ( V_301 ) ) {
F_32 ( V_306 ) ;
V_306 ++ ;
if ( V_14 -> V_310 )
goto V_128;
V_29 = F_259 ( V_34 , V_115 , V_14 ,
V_64 ) ;
if ( V_29 )
goto V_128;
goto V_162;
}
if ( V_14 -> V_311 == V_115 -> V_273 &&
F_260 ( V_301 ) ) {
V_303 = V_312 ;
goto V_313;
}
F_261 ( V_301 ) -> V_314 = 0 ;
V_29 = F_262 ( V_115 , V_140 , V_301 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_313;
}
F_8 ( V_29 ) ;
if ( F_260 ( V_301 ) > 0 ) {
V_29 = F_263 ( V_34 ,
& V_34 -> V_265 ) ;
if ( V_29 )
goto V_313;
V_29 = F_264 ( V_115 , NULL , V_301 ) ;
if ( V_29 )
goto V_313;
}
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_3 != V_4 ||
! F_265 ( V_34 , V_315 ) ) {
V_303 = V_309 ;
F_13 ( & V_14 -> V_48 ) ;
goto V_313;
}
F_13 ( & V_14 -> V_48 ) ;
if ( F_226 ( V_316 , & V_115 -> V_132 -> V_7 ) ) {
V_29 = - V_317 ;
goto V_313;
}
V_305 = F_203 ( V_14 -> V_21 . V_33 , V_318 ) ;
if ( ! V_305 )
V_305 = 1 ;
V_305 *= 16 ;
V_305 *= V_319 ;
V_29 = F_266 ( V_301 , 0 , V_305 ) ;
if ( V_29 )
goto V_313;
V_29 = F_267 ( V_301 , V_115 , 0 , 0 , V_305 ,
V_305 , V_305 ,
& V_302 ) ;
if ( ! V_29 )
V_303 = V_312 ;
else if ( V_29 == - V_317 )
F_268 ( V_316 , & V_115 -> V_132 -> V_7 ) ;
V_313:
F_269 ( V_301 ) ;
V_128:
F_45 ( V_64 ) ;
V_79:
F_11 ( & V_14 -> V_48 ) ;
if ( ! V_29 && V_303 == V_312 )
V_14 -> V_311 = V_115 -> V_273 ;
V_14 -> V_308 = V_303 ;
F_13 ( & V_14 -> V_48 ) ;
return V_29 ;
}
int F_270 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_2 , * V_320 ;
struct V_283 * V_284 = V_115 -> V_132 ;
struct V_63 * V_64 ;
if ( F_183 ( & V_284 -> V_321 ) ||
! F_265 ( V_34 , V_315 ) )
return 0 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
F_271 (cache, tmp, &cur_trans->dirty_bgs,
dirty_list) {
if ( V_2 -> V_308 == V_322 )
F_257 ( V_2 , V_115 , V_64 ) ;
}
F_53 ( V_64 ) ;
return 0 ;
}
int F_272 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_2 ;
struct V_283 * V_284 = V_115 -> V_132 ;
int V_29 = 0 ;
int V_323 ;
struct V_63 * V_64 = NULL ;
F_273 ( V_324 ) ;
struct V_109 * V_325 = & V_284 -> V_326 ;
int V_327 = 0 ;
int V_328 = 0 ;
F_11 ( & V_284 -> V_329 ) ;
if ( F_183 ( & V_284 -> V_321 ) ) {
F_13 ( & V_284 -> V_329 ) ;
return 0 ;
}
F_274 ( & V_284 -> V_321 , & V_324 ) ;
F_13 ( & V_284 -> V_329 ) ;
V_162:
F_228 ( V_115 , V_34 ) ;
if ( ! V_64 ) {
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
}
F_49 ( & V_115 -> V_132 -> V_330 ) ;
while ( ! F_183 ( & V_324 ) ) {
V_2 = F_184 ( & V_324 ,
struct V_1 ,
V_331 ) ;
if ( ! F_183 ( & V_2 -> V_332 ) ) {
F_275 ( & V_2 -> V_332 ) ;
F_276 ( V_115 , V_2 , V_64 ) ;
F_6 ( V_2 ) ;
}
F_11 ( & V_284 -> V_329 ) ;
F_275 ( & V_2 -> V_331 ) ;
F_13 ( & V_284 -> V_329 ) ;
V_323 = 1 ;
F_257 ( V_2 , V_115 , V_64 ) ;
if ( V_2 -> V_308 == V_312 ) {
V_2 -> V_333 . V_301 = NULL ;
V_29 = F_277 ( V_34 , V_115 ,
V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_333 . V_301 ) {
V_327 ++ ;
V_323 = 0 ;
F_72 ( & V_2 -> V_332 , V_325 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_252 ( V_115 , V_34 ,
V_64 , V_2 ) ;
if ( V_29 == - V_159 ) {
V_29 = 0 ;
F_11 ( & V_284 -> V_329 ) ;
if ( F_183 ( & V_2 -> V_331 ) ) {
F_72 ( & V_2 -> V_331 ,
& V_284 -> V_321 ) ;
F_4 ( V_2 ) ;
}
F_13 ( & V_284 -> V_329 ) ;
} else if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
}
}
if ( V_323 )
F_6 ( V_2 ) ;
if ( V_29 )
break;
F_47 ( & V_115 -> V_132 -> V_330 ) ;
F_49 ( & V_115 -> V_132 -> V_330 ) ;
}
F_47 ( & V_115 -> V_132 -> V_330 ) ;
V_29 = F_219 ( V_115 , V_34 , 0 ) ;
if ( ! V_29 && V_328 == 0 ) {
V_328 ++ ;
F_11 ( & V_284 -> V_329 ) ;
F_274 ( & V_284 -> V_321 , & V_324 ) ;
if ( ! F_183 ( & V_324 ) ) {
F_13 ( & V_284 -> V_329 ) ;
goto V_162;
}
F_13 ( & V_284 -> V_329 ) ;
} else if ( V_29 < 0 ) {
F_278 ( V_284 , V_34 ) ;
}
F_53 ( V_64 ) ;
return V_29 ;
}
int F_279 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_2 ;
struct V_283 * V_284 = V_115 -> V_132 ;
int V_29 = 0 ;
int V_323 ;
struct V_63 * V_64 ;
struct V_109 * V_325 = & V_284 -> V_326 ;
int V_327 = 0 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
F_11 ( & V_284 -> V_329 ) ;
while ( ! F_183 ( & V_284 -> V_321 ) ) {
V_2 = F_184 ( & V_284 -> V_321 ,
struct V_1 ,
V_331 ) ;
if ( ! F_183 ( & V_2 -> V_332 ) ) {
F_13 ( & V_284 -> V_329 ) ;
F_275 ( & V_2 -> V_332 ) ;
F_276 ( V_115 , V_2 , V_64 ) ;
F_6 ( V_2 ) ;
F_11 ( & V_284 -> V_329 ) ;
}
F_275 ( & V_2 -> V_331 ) ;
F_13 ( & V_284 -> V_329 ) ;
V_323 = 1 ;
F_257 ( V_2 , V_115 , V_64 ) ;
if ( ! V_29 )
V_29 = F_219 ( V_115 , V_34 ,
( unsigned long ) - 1 ) ;
if ( ! V_29 && V_2 -> V_308 == V_312 ) {
V_2 -> V_333 . V_301 = NULL ;
V_29 = F_277 ( V_34 , V_115 ,
V_2 , V_64 ) ;
if ( V_29 == 0 && V_2 -> V_333 . V_301 ) {
V_327 ++ ;
V_323 = 0 ;
F_72 ( & V_2 -> V_332 , V_325 ) ;
} else {
V_29 = 0 ;
}
}
if ( ! V_29 ) {
V_29 = F_252 ( V_115 , V_34 ,
V_64 , V_2 ) ;
if ( V_29 == - V_159 ) {
F_280 ( V_284 -> V_334 ,
F_212 ( & V_284 -> V_335 ) == 1 ) ;
V_29 = F_252 ( V_115 , V_34 ,
V_64 , V_2 ) ;
}
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
}
if ( V_323 )
F_6 ( V_2 ) ;
F_11 ( & V_284 -> V_329 ) ;
}
F_13 ( & V_284 -> V_329 ) ;
while ( ! F_183 ( V_325 ) ) {
V_2 = F_184 ( V_325 , struct V_1 ,
V_332 ) ;
F_275 ( & V_2 -> V_332 ) ;
F_276 ( V_115 , V_2 , V_64 ) ;
F_6 ( V_2 ) ;
}
F_53 ( V_64 ) ;
return V_29 ;
}
int F_281 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_1 * V_14 ;
int V_336 = 0 ;
V_14 = F_76 ( V_34 , V_27 ) ;
if ( ! V_14 || V_14 -> V_310 )
V_336 = 1 ;
if ( V_14 )
F_6 ( V_14 ) ;
return V_336 ;
}
bool F_282 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_1 * V_337 ;
bool V_29 = true ;
V_337 = F_76 ( V_34 , V_27 ) ;
if ( ! V_337 )
return false ;
F_11 ( & V_337 -> V_48 ) ;
if ( V_337 -> V_310 )
V_29 = false ;
else
F_5 ( & V_337 -> V_338 ) ;
F_13 ( & V_337 -> V_48 ) ;
if ( ! V_29 )
F_6 ( V_337 ) ;
return V_29 ;
}
void F_283 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_1 * V_337 ;
V_337 = F_76 ( V_34 , V_27 ) ;
ASSERT ( V_337 ) ;
if ( F_7 ( & V_337 -> V_338 ) )
F_284 ( & V_337 -> V_338 ) ;
F_6 ( V_337 ) ;
F_6 ( V_337 ) ;
}
static int F_285 ( T_7 * V_339 )
{
F_68 () ;
return 0 ;
}
void F_286 ( struct V_1 * V_337 )
{
F_287 ( & V_337 -> V_338 ,
F_285 ,
V_99 ) ;
}
static const char * F_288 ( T_2 V_7 )
{
switch ( V_7 ) {
case V_51 | V_340 :
return L_4 ;
case V_51 :
return L_5 ;
case V_340 :
return L_6 ;
case V_341 :
return L_7 ;
default:
F_8 ( 1 ) ;
return L_8 ;
} ;
}
static int F_289 ( struct V_12 * V_13 , T_2 V_7 ,
T_2 V_342 , T_2 V_91 ,
T_2 V_343 ,
struct V_108 * * V_92 )
{
struct V_108 * V_111 ;
int V_40 ;
int V_344 ;
int V_29 ;
if ( V_7 & ( V_345 | V_346 |
V_347 ) )
V_344 = 2 ;
else
V_344 = 1 ;
V_111 = F_77 ( V_13 , V_7 ) ;
if ( V_111 ) {
F_11 ( & V_111 -> V_48 ) ;
V_111 -> V_342 += V_342 ;
V_111 -> V_348 += V_342 * V_344 ;
V_111 -> V_91 += V_91 ;
V_111 -> V_349 += V_91 * V_344 ;
V_111 -> V_343 += V_343 ;
if ( V_342 > 0 )
V_111 -> V_113 = 0 ;
F_290 ( V_13 , V_111 , V_342 -
V_91 - V_343 ) ;
F_13 ( & V_111 -> V_48 ) ;
* V_92 = V_111 ;
return 0 ;
}
V_111 = F_61 ( sizeof( * V_111 ) , V_95 ) ;
if ( ! V_111 )
return - V_72 ;
V_29 = F_291 ( & V_111 -> V_350 , 0 , V_351 ) ;
if ( V_29 ) {
F_9 ( V_111 ) ;
return V_29 ;
}
for ( V_40 = 0 ; V_40 < V_352 ; V_40 ++ )
F_62 ( & V_111 -> V_353 [ V_40 ] ) ;
F_292 ( & V_111 -> V_354 ) ;
F_293 ( & V_111 -> V_48 ) ;
V_111 -> V_7 = V_7 & V_112 ;
V_111 -> V_342 = V_342 ;
V_111 -> V_348 = V_342 * V_344 ;
V_111 -> V_91 = V_91 ;
V_111 -> V_349 = V_91 * V_344 ;
V_111 -> V_355 = 0 ;
V_111 -> V_356 = 0 ;
V_111 -> V_343 = V_343 ;
V_111 -> V_357 = 0 ;
V_111 -> V_113 = 0 ;
V_111 -> V_358 = 0 ;
V_111 -> V_359 = V_360 ;
V_111 -> V_361 = 0 ;
V_111 -> V_362 = 0 ;
F_64 ( & V_111 -> V_87 ) ;
F_62 ( & V_111 -> V_363 ) ;
F_62 ( & V_111 -> V_364 ) ;
F_62 ( & V_111 -> V_365 ) ;
V_29 = F_294 ( & V_111 -> V_366 , & V_367 ,
V_13 -> V_368 , L_9 ,
F_288 ( V_111 -> V_7 ) ) ;
if ( V_29 ) {
F_9 ( V_111 ) ;
return V_29 ;
}
* V_92 = V_111 ;
F_295 ( & V_111 -> V_96 , & V_13 -> V_92 ) ;
if ( V_7 & V_340 )
V_13 -> V_369 = V_111 ;
return V_29 ;
}
static void F_296 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_370 = F_297 ( V_7 ) &
V_371 ;
F_298 ( & V_34 -> V_372 ) ;
if ( V_7 & V_340 )
V_34 -> V_373 |= V_370 ;
if ( V_7 & V_51 )
V_34 -> V_374 |= V_370 ;
if ( V_7 & V_341 )
V_34 -> V_375 |= V_370 ;
F_299 ( & V_34 -> V_372 ) ;
}
static T_2 F_300 ( struct V_12 * V_34 , T_2 V_7 )
{
struct V_376 * V_377 = V_34 -> V_378 ;
T_2 V_379 = 0 ;
if ( ! V_377 )
return 0 ;
if ( V_7 & V_340 &&
V_377 -> V_380 . V_7 & V_381 ) {
V_379 = V_340 | V_377 -> V_380 . V_379 ;
} else if ( V_7 & V_341 &&
V_377 -> V_382 . V_7 & V_381 ) {
V_379 = V_341 | V_377 -> V_382 . V_379 ;
} else if ( V_7 & V_51 &&
V_377 -> V_383 . V_7 & V_381 ) {
V_379 = V_51 | V_377 -> V_383 . V_379 ;
}
return V_379 ;
}
static T_2 F_301 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_384 = V_34 -> V_385 -> V_386 ;
T_2 V_379 ;
T_2 V_387 ;
T_2 V_388 = 0 ;
F_11 ( & V_34 -> V_389 ) ;
V_379 = F_300 ( V_34 , V_7 ) ;
if ( V_379 ) {
if ( ( V_7 & V_379 ) & V_371 ) {
F_13 ( & V_34 -> V_389 ) ;
return F_302 ( V_379 ) ;
}
}
F_13 ( & V_34 -> V_389 ) ;
for ( V_387 = 0 ; V_387 < V_352 ; V_387 ++ ) {
if ( V_384 >= V_390 [ V_387 ] . V_391 )
V_388 |= V_392 [ V_387 ] ;
}
V_388 &= V_7 ;
if ( V_388 & V_393 )
V_388 = V_393 ;
else if ( V_388 & V_394 )
V_388 = V_394 ;
else if ( V_388 & V_347 )
V_388 = V_347 ;
else if ( V_388 & V_346 )
V_388 = V_346 ;
else if ( V_388 & V_395 )
V_388 = V_395 ;
V_7 &= ~ V_396 ;
return F_302 ( V_7 | V_388 ) ;
}
static T_2 F_303 ( struct V_12 * V_34 , T_2 V_397 )
{
unsigned V_236 ;
T_2 V_7 ;
do {
V_7 = V_397 ;
V_236 = F_304 ( & V_34 -> V_372 ) ;
if ( V_7 & V_340 )
V_7 |= V_34 -> V_373 ;
else if ( V_7 & V_341 )
V_7 |= V_34 -> V_375 ;
else if ( V_7 & V_51 )
V_7 |= V_34 -> V_374 ;
} while ( F_305 ( & V_34 -> V_372 , V_236 ) );
return F_301 ( V_34 , V_7 ) ;
}
T_2 F_306 ( struct V_61 * V_140 , int V_380 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
T_2 V_7 ;
T_2 V_29 ;
if ( V_380 )
V_7 = V_340 ;
else if ( V_140 == V_34 -> V_398 )
V_7 = V_341 ;
else
V_7 = V_51 ;
V_29 = F_303 ( V_34 , V_7 ) ;
return V_29 ;
}
static T_2 F_307 ( struct V_108 * V_399 ,
bool V_400 )
{
ASSERT ( V_399 ) ;
return V_399 -> V_91 + V_399 -> V_356 +
V_399 -> V_355 + V_399 -> V_343 +
( V_400 ? V_399 -> V_357 : 0 ) ;
}
int F_308 ( struct V_401 * V_301 , T_2 V_210 )
{
struct V_108 * V_369 ;
struct V_61 * V_140 = V_301 -> V_140 ;
struct V_12 * V_34 = V_140 -> V_34 ;
T_2 V_402 ;
int V_29 = 0 ;
int V_403 = 2 ;
int V_404 ;
V_210 = F_149 ( V_210 , V_34 -> V_53 ) ;
if ( F_309 ( V_301 ) ) {
V_403 = 0 ;
ASSERT ( V_405 -> V_406 ) ;
}
V_369 = V_34 -> V_369 ;
if ( ! V_369 )
goto V_407;
V_162:
F_11 ( & V_369 -> V_48 ) ;
V_402 = F_307 ( V_369 , true ) ;
if ( V_402 + V_210 > V_369 -> V_342 ) {
struct V_114 * V_115 ;
if ( ! V_369 -> V_113 ) {
T_2 V_408 ;
V_369 -> V_359 = V_409 ;
F_13 ( & V_369 -> V_48 ) ;
V_407:
V_408 = F_306 ( V_140 , 1 ) ;
V_115 = F_216 ( V_140 ) ;
if ( F_217 ( V_115 ) )
return F_218 ( V_115 ) ;
V_29 = F_310 ( V_115 , V_34 , V_408 ,
V_360 ) ;
F_220 ( V_115 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_317 )
return V_29 ;
else {
V_404 = 1 ;
goto V_410;
}
}
if ( ! V_369 )
V_369 = V_34 -> V_369 ;
goto V_162;
}
V_404 = F_311 (
& V_369 -> V_350 ,
V_402 + V_210 - V_369 -> V_342 ) ;
F_13 ( & V_369 -> V_48 ) ;
V_410:
if ( V_403 &&
! F_212 ( & V_34 -> V_411 ) ) {
V_403 -- ;
if ( V_403 > 0 ) {
F_312 ( V_34 , 0 , - 1 ) ;
F_313 ( V_34 , - 1 , 0 ,
( T_2 ) - 1 ) ;
}
V_115 = F_216 ( V_140 ) ;
if ( F_217 ( V_115 ) )
return F_218 ( V_115 ) ;
if ( V_404 >= 0 ||
F_226 ( V_412 ,
& V_115 -> V_132 -> V_7 ) ||
V_403 > 0 ) {
V_29 = F_314 ( V_115 ) ;
if ( V_29 )
return V_29 ;
F_49 ( & V_34 -> V_413 ) ;
F_47 ( & V_34 -> V_413 ) ;
goto V_162;
} else {
F_220 ( V_115 ) ;
}
}
F_315 ( V_34 ,
L_10 ,
V_369 -> V_7 , V_210 , 1 ) ;
return - V_317 ;
}
V_369 -> V_357 += V_210 ;
F_315 ( V_34 , L_11 ,
V_369 -> V_7 , V_210 , 1 ) ;
F_13 ( & V_369 -> V_48 ) ;
return V_29 ;
}
int F_266 ( struct V_301 * V_301 , T_2 V_32 , T_2 V_45 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_414 ) ;
int V_29 ;
V_45 = F_317 ( V_32 + V_45 , V_34 -> V_53 ) -
F_150 ( V_32 , V_34 -> V_53 ) ;
V_32 = F_150 ( V_32 , V_34 -> V_53 ) ;
V_29 = F_308 ( F_261 ( V_301 ) , V_45 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_318 ( V_301 , V_32 , V_45 ) ;
if ( V_29 )
F_319 ( V_301 , V_32 , V_45 ) ;
return V_29 ;
}
void F_319 ( struct V_301 * V_301 , T_2 V_32 ,
T_2 V_45 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_414 ) ;
struct V_108 * V_369 ;
V_45 = F_317 ( V_32 + V_45 , V_34 -> V_53 ) -
F_150 ( V_32 , V_34 -> V_53 ) ;
V_32 = F_150 ( V_32 , V_34 -> V_53 ) ;
V_369 = V_34 -> V_369 ;
F_11 ( & V_369 -> V_48 ) ;
if ( F_8 ( V_369 -> V_357 < V_45 ) )
V_369 -> V_357 = 0 ;
else
V_369 -> V_357 -= V_45 ;
F_315 ( V_34 , L_11 ,
V_369 -> V_7 , V_45 , 0 ) ;
F_13 ( & V_369 -> V_48 ) ;
}
void F_320 ( struct V_301 * V_301 , T_2 V_32 , T_2 V_45 )
{
struct V_61 * V_140 = F_261 ( V_301 ) -> V_140 ;
V_45 = F_317 ( V_32 + V_45 , V_140 -> V_34 -> V_53 ) -
F_150 ( V_32 , V_140 -> V_34 -> V_53 ) ;
V_32 = F_150 ( V_32 , V_140 -> V_34 -> V_53 ) ;
F_319 ( V_301 , V_32 , V_45 ) ;
F_321 ( V_301 , V_32 , V_45 ) ;
}
static void F_322 ( struct V_12 * V_13 )
{
struct V_109 * V_110 = & V_13 -> V_92 ;
struct V_108 * V_111 ;
F_78 () ;
F_79 (found, head, list) {
if ( V_111 -> V_7 & V_51 )
V_111 -> V_359 = V_409 ;
}
F_80 () ;
}
static inline T_2 F_323 ( struct V_261 * V_415 )
{
return ( V_415 -> V_57 << 1 ) ;
}
static int F_324 ( struct V_12 * V_34 ,
struct V_108 * V_416 , int V_417 )
{
struct V_261 * V_262 = & V_34 -> V_265 ;
T_2 V_35 = V_416 -> V_342 - V_416 -> V_343 ;
T_2 V_418 = V_416 -> V_91 + V_416 -> V_356 ;
T_2 V_419 ;
if ( V_417 == V_409 )
return 1 ;
if ( V_416 -> V_7 & V_51 )
V_418 += F_323 ( V_262 ) ;
if ( V_417 == V_420 ) {
V_419 = F_325 ( V_34 -> V_260 ) ;
V_419 = F_35 ( T_2 , V_421 , F_326 ( V_419 , 1 ) ) ;
if ( V_35 - V_418 < V_419 )
return 1 ;
}
if ( V_418 + V_422 < F_327 ( V_35 , 8 ) )
return 0 ;
return 1 ;
}
static T_2 F_328 ( struct V_12 * V_34 , T_2 type )
{
T_2 V_423 ;
if ( type & ( V_347 |
V_395 |
V_394 |
V_393 ) )
V_423 = V_34 -> V_385 -> V_386 ;
else if ( type & V_346 )
V_423 = 2 ;
else
V_423 = 1 ;
return V_423 ;
}
void F_329 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 type )
{
struct V_108 * V_13 ;
T_2 V_424 ;
T_2 V_419 ;
int V_29 = 0 ;
T_2 V_425 ;
ASSERT ( F_330 ( & V_34 -> V_426 ) ) ;
V_13 = F_77 ( V_34 , V_341 ) ;
F_11 ( & V_13 -> V_48 ) ;
V_424 = V_13 -> V_342 - F_307 ( V_13 , true ) ;
F_13 ( & V_13 -> V_48 ) ;
V_425 = F_328 ( V_34 , type ) ;
V_419 = F_331 ( V_34 , V_425 ) +
F_210 ( V_34 , 1 ) ;
if ( V_424 < V_419 && F_265 ( V_34 , V_427 ) ) {
F_332 ( V_34 , L_12 ,
V_424 , V_419 , type ) ;
F_333 ( V_34 , V_13 , 0 , 0 ) ;
}
if ( V_424 < V_419 ) {
T_2 V_7 ;
V_7 = F_306 ( V_34 -> V_398 , 0 ) ;
V_29 = F_334 ( V_115 , V_34 , V_7 ) ;
}
if ( ! V_29 ) {
V_29 = F_335 ( V_34 -> V_398 ,
& V_34 -> V_428 ,
V_419 , V_429 ) ;
if ( ! V_29 )
V_115 -> V_430 += V_419 ;
}
}
static int F_310 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_7 , int V_417 )
{
struct V_108 * V_92 ;
int V_431 = 0 ;
int V_29 = 0 ;
if ( V_115 -> V_432 )
return - V_317 ;
V_92 = F_77 ( V_34 , V_7 ) ;
if ( ! V_92 ) {
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
F_32 ( V_29 ) ;
}
F_32 ( ! V_92 ) ;
V_162:
F_11 ( & V_92 -> V_48 ) ;
if ( V_417 < V_92 -> V_359 )
V_417 = V_92 -> V_359 ;
if ( V_92 -> V_113 ) {
if ( F_324 ( V_34 , V_92 , V_417 ) )
V_29 = - V_317 ;
else
V_29 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
if ( ! F_324 ( V_34 , V_92 , V_417 ) ) {
F_13 ( & V_92 -> V_48 ) ;
return 0 ;
} else if ( V_92 -> V_361 ) {
V_431 = 1 ;
} else {
V_92 -> V_361 = 1 ;
}
F_13 ( & V_92 -> V_48 ) ;
F_49 ( & V_34 -> V_426 ) ;
if ( V_431 ) {
F_47 ( & V_34 -> V_426 ) ;
V_431 = 0 ;
goto V_162;
}
V_115 -> V_432 = true ;
if ( F_336 ( V_92 ) )
V_7 |= ( V_340 | V_51 ) ;
if ( V_7 & V_340 && V_34 -> V_433 ) {
V_34 -> V_434 ++ ;
if ( ! ( V_34 -> V_434 %
V_34 -> V_433 ) )
F_322 ( V_34 ) ;
}
F_329 ( V_115 , V_34 , V_7 ) ;
V_29 = F_334 ( V_115 , V_34 , V_7 ) ;
V_115 -> V_432 = false ;
F_11 ( & V_92 -> V_48 ) ;
if ( V_29 < 0 && V_29 != - V_317 )
goto V_79;
if ( V_29 )
V_92 -> V_113 = 1 ;
else
V_29 = 1 ;
V_92 -> V_359 = V_360 ;
V_79:
V_92 -> V_361 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
F_47 ( & V_34 -> V_426 ) ;
if ( V_115 -> V_278 &&
V_115 -> V_430 >= ( T_2 ) V_422 ) {
F_228 ( V_115 , V_34 ) ;
F_337 ( V_115 ) ;
}
return V_29 ;
}
static int F_338 ( struct V_61 * V_140 ,
struct V_108 * V_92 , T_2 V_210 ,
enum V_435 V_362 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
T_2 V_436 ;
T_2 V_437 ;
T_2 V_438 ;
T_2 V_402 ;
if ( V_92 -> V_7 & V_340 )
return 0 ;
V_436 = F_306 ( V_140 , 0 ) ;
V_402 = F_307 ( V_92 , false ) ;
F_11 ( & V_262 -> V_48 ) ;
V_437 = F_323 ( V_262 ) ;
F_13 ( & V_262 -> V_48 ) ;
if ( V_402 + V_437 >= V_92 -> V_342 )
return 0 ;
V_402 += V_92 -> V_357 ;
F_11 ( & V_34 -> V_439 ) ;
V_438 = V_34 -> V_440 ;
F_13 ( & V_34 -> V_439 ) ;
if ( V_436 & ( V_345 |
V_346 |
V_347 ) )
V_438 >>= 1 ;
if ( V_362 == V_441 )
V_438 >>= 3 ;
else
V_438 >>= 1 ;
if ( V_402 + V_210 < V_92 -> V_342 + V_438 )
return 1 ;
return 0 ;
}
static void F_339 ( struct V_12 * V_34 ,
unsigned long V_442 , int V_443 )
{
struct V_444 * V_445 = V_34 -> V_445 ;
if ( F_340 ( & V_445 -> V_446 ) ) {
F_341 ( V_445 , V_442 , V_447 ) ;
F_46 ( & V_445 -> V_446 ) ;
} else {
F_312 ( V_34 , 0 , V_443 ) ;
if ( ! V_405 -> V_406 )
F_313 ( V_34 , V_443 , 0 , ( T_2 ) - 1 ) ;
}
}
static inline int F_342 ( struct V_12 * V_34 ,
T_2 V_448 )
{
T_2 V_210 ;
int V_41 ;
V_210 = F_210 ( V_34 , 1 ) ;
V_41 = ( int ) F_207 ( V_448 , V_210 ) ;
if ( ! V_41 )
V_41 = 1 ;
return V_41 ;
}
static void F_343 ( struct V_61 * V_140 , T_2 V_448 , T_2 V_449 ,
bool V_450 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_261 * V_451 ;
struct V_108 * V_92 ;
struct V_114 * V_115 ;
T_2 V_452 ;
T_2 V_453 ;
long V_454 ;
unsigned long V_442 ;
int V_328 ;
int V_455 ;
enum V_435 V_362 ;
V_455 = F_342 ( V_34 , V_448 ) ;
V_448 = ( T_2 ) V_455 * V_456 ;
V_115 = (struct V_114 * ) V_405 -> V_406 ;
V_451 = & V_34 -> V_457 ;
V_92 = V_451 -> V_92 ;
V_452 = F_344 (
& V_34 -> V_452 ) ;
if ( V_452 == 0 ) {
if ( V_115 )
return;
if ( V_450 )
F_313 ( V_34 , V_455 , 0 , ( T_2 ) - 1 ) ;
return;
}
V_328 = 0 ;
while ( V_452 && V_328 < 3 ) {
V_453 = F_345 ( V_452 , V_448 ) ;
V_442 = V_453 >> V_458 ;
F_339 ( V_34 , V_442 , V_455 ) ;
V_453 = F_212 ( & V_34 -> V_459 ) ;
if ( ! V_453 )
goto V_460;
if ( V_453 <= V_442 )
V_453 = 0 ;
else
V_453 -= V_442 ;
F_280 ( V_34 -> V_461 ,
F_212 ( & V_34 -> V_459 ) <=
( int ) V_453 ) ;
V_460:
if ( ! V_115 )
V_362 = V_441 ;
else
V_362 = V_429 ;
F_11 ( & V_92 -> V_48 ) ;
if ( F_338 ( V_140 , V_92 , V_449 , V_362 ) ) {
F_13 ( & V_92 -> V_48 ) ;
break;
}
if ( F_183 ( & V_92 -> V_364 ) &&
F_183 ( & V_92 -> V_365 ) ) {
F_13 ( & V_92 -> V_48 ) ;
break;
}
F_13 ( & V_92 -> V_48 ) ;
V_328 ++ ;
if ( V_450 && ! V_115 ) {
F_313 ( V_34 , V_455 , 0 , ( T_2 ) - 1 ) ;
} else {
V_454 = F_346 ( 1 ) ;
if ( V_454 )
break;
}
V_452 = F_344 (
& V_34 -> V_452 ) ;
}
}
static int F_347 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
T_2 V_210 , int V_417 )
{
struct V_261 * V_462 = & V_34 -> V_463 ;
struct V_114 * V_115 ;
V_115 = (struct V_114 * ) V_405 -> V_406 ;
if ( V_115 )
return - V_185 ;
if ( V_417 )
goto V_464;
if ( F_311 ( & V_92 -> V_350 ,
V_210 ) >= 0 )
goto V_464;
if ( V_92 != V_462 -> V_92 )
return - V_317 ;
F_11 ( & V_462 -> V_48 ) ;
if ( F_311 ( & V_92 -> V_350 ,
V_210 - V_462 -> V_57 ) >= 0 ) {
F_13 ( & V_462 -> V_48 ) ;
return - V_317 ;
}
F_13 ( & V_462 -> V_48 ) ;
V_464:
V_115 = F_216 ( V_34 -> V_465 ) ;
if ( F_217 ( V_115 ) )
return - V_317 ;
return F_314 ( V_115 ) ;
}
static int F_348 ( struct V_12 * V_34 ,
struct V_108 * V_92 , T_2 V_35 ,
T_2 V_466 , int V_296 )
{
struct V_61 * V_140 = V_34 -> V_465 ;
struct V_114 * V_115 ;
int V_41 ;
int V_29 = 0 ;
switch ( V_296 ) {
case V_467 :
case V_468 :
if ( V_296 == V_467 )
V_41 = F_342 ( V_34 , V_35 ) * 2 ;
else
V_41 = - 1 ;
V_115 = F_216 ( V_140 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
break;
}
V_29 = F_349 ( V_115 , V_34 , V_41 ) ;
F_220 ( V_115 ) ;
break;
case V_469 :
case V_470 :
F_343 ( V_140 , V_35 * 2 , V_466 ,
V_296 == V_470 ) ;
break;
case V_471 :
V_115 = F_216 ( V_140 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
break;
}
V_29 = F_310 ( V_115 , V_34 ,
F_306 ( V_140 , 0 ) ,
V_360 ) ;
F_220 ( V_115 ) ;
if ( V_29 > 0 || V_29 == - V_317 )
V_29 = 0 ;
break;
case V_472 :
V_29 = F_347 ( V_34 , V_92 ,
V_466 , 0 ) ;
break;
default:
V_29 = - V_317 ;
break;
}
F_350 ( V_34 , V_92 -> V_7 , V_35 ,
V_466 , V_296 , V_29 ) ;
return V_29 ;
}
static inline T_2
F_351 ( struct V_61 * V_140 ,
struct V_108 * V_92 )
{
struct V_473 * V_474 ;
T_2 V_402 ;
T_2 V_475 ;
T_2 V_448 = 0 ;
F_235 (ticket, &space_info->tickets, list)
V_448 += V_474 -> V_210 ;
F_235 (ticket, &space_info->priority_tickets, list)
V_448 += V_474 -> V_210 ;
if ( V_448 )
return V_448 ;
V_448 = F_24 ( T_2 , F_352 () * V_307 , V_476 ) ;
if ( F_338 ( V_140 , V_92 , V_448 ,
V_441 ) )
return 0 ;
V_402 = V_92 -> V_91 + V_92 -> V_356 +
V_92 -> V_355 + V_92 -> V_343 +
V_92 -> V_357 ;
if ( F_338 ( V_140 , V_92 , V_307 , V_441 ) )
V_475 = F_326 ( V_92 -> V_342 , 95 ) ;
else
V_475 = F_326 ( V_92 -> V_342 , 90 ) ;
if ( V_402 > V_475 )
V_448 = V_402 - V_475 ;
else
V_448 = 0 ;
V_448 = F_345 ( V_448 , V_92 -> V_357 +
V_92 -> V_356 ) ;
return V_448 ;
}
static inline int F_353 ( struct V_108 * V_92 ,
struct V_61 * V_140 , T_2 V_402 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
T_2 V_419 = F_326 ( V_92 -> V_342 , 98 ) ;
if ( ( V_92 -> V_91 + V_92 -> V_356 ) >= V_419 )
return 0 ;
if ( ! F_351 ( V_140 , V_92 ) )
return 0 ;
return ( V_402 >= V_419 && ! F_40 ( V_34 ) &&
! F_226 ( V_477 , & V_34 -> V_478 ) ) ;
}
static void F_354 ( struct V_109 * V_110 )
{
struct V_473 * V_474 ;
while ( ! F_183 ( V_110 ) ) {
V_474 = F_184 ( V_110 , struct V_473 , V_96 ) ;
F_275 ( & V_474 -> V_96 ) ;
V_474 -> error = - V_317 ;
F_52 ( & V_474 -> V_87 ) ;
}
}
static void F_355 ( struct V_479 * V_89 )
{
struct V_12 * V_34 ;
struct V_108 * V_92 ;
T_2 V_448 ;
int V_480 ;
int V_481 = 0 ;
T_2 V_482 ;
V_34 = F_55 ( V_89 , struct V_12 , V_483 ) ;
V_92 = F_77 ( V_34 , V_51 ) ;
F_11 ( & V_92 -> V_48 ) ;
V_448 = F_351 ( V_34 -> V_465 ,
V_92 ) ;
if ( ! V_448 ) {
V_92 -> V_362 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
return;
}
V_482 = V_92 -> V_484 ;
F_13 ( & V_92 -> V_48 ) ;
V_480 = V_467 ;
do {
struct V_473 * V_474 ;
int V_29 ;
V_29 = F_348 ( V_34 , V_92 , V_448 , V_448 ,
V_480 ) ;
F_11 ( & V_92 -> V_48 ) ;
if ( F_183 ( & V_92 -> V_364 ) ) {
V_92 -> V_362 = 0 ;
F_13 ( & V_92 -> V_48 ) ;
return;
}
V_448 = F_351 ( V_34 -> V_465 ,
V_92 ) ;
V_474 = F_184 ( & V_92 -> V_364 ,
struct V_473 , V_96 ) ;
if ( V_482 == V_92 -> V_484 ) {
V_480 ++ ;
} else {
V_482 = V_92 -> V_484 ;
V_480 = V_467 ;
if ( V_481 )
V_481 -- ;
}
if ( V_480 > V_472 ) {
V_481 ++ ;
if ( V_481 > 2 ) {
F_354 ( & V_92 -> V_364 ) ;
V_92 -> V_362 = 0 ;
} else {
V_480 = V_467 ;
}
}
F_13 ( & V_92 -> V_48 ) ;
} while ( V_480 <= V_472 );
}
void F_356 ( struct V_479 * V_89 )
{
F_357 ( V_89 , F_355 ) ;
}
static void F_358 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
struct V_473 * V_474 )
{
T_2 V_448 ;
int V_480 = V_467 ;
F_11 ( & V_92 -> V_48 ) ;
V_448 = F_351 ( V_34 -> V_465 ,
V_92 ) ;
if ( ! V_448 ) {
F_13 ( & V_92 -> V_48 ) ;
return;
}
F_13 ( & V_92 -> V_48 ) ;
do {
F_348 ( V_34 , V_92 , V_448 , V_448 ,
V_480 ) ;
V_480 ++ ;
F_11 ( & V_92 -> V_48 ) ;
if ( V_474 -> V_210 == 0 ) {
F_13 ( & V_92 -> V_48 ) ;
return;
}
F_13 ( & V_92 -> V_48 ) ;
if ( V_480 == V_469 ||
V_480 == V_470 )
V_480 = V_471 ;
} while ( V_480 < V_472 );
}
static int F_359 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
struct V_473 * V_474 , T_2 V_466 )
{
F_60 ( V_87 ) ;
int V_29 = 0 ;
F_11 ( & V_92 -> V_48 ) ;
while ( V_474 -> V_210 > 0 && V_474 -> error == 0 ) {
V_29 = F_360 ( & V_474 -> V_87 , & V_87 , V_485 ) ;
if ( V_29 ) {
V_29 = - V_486 ;
break;
}
F_13 ( & V_92 -> V_48 ) ;
F_68 () ;
F_69 ( & V_474 -> V_87 , & V_87 ) ;
F_11 ( & V_92 -> V_48 ) ;
}
if ( ! V_29 )
V_29 = V_474 -> error ;
if ( ! F_183 ( & V_474 -> V_96 ) )
F_275 ( & V_474 -> V_96 ) ;
if ( V_474 -> V_210 && V_474 -> V_210 < V_466 ) {
T_2 V_35 = V_466 - V_474 -> V_210 ;
V_92 -> V_357 -= V_35 ;
F_315 ( V_34 , L_11 ,
V_92 -> V_7 , V_35 , 0 ) ;
}
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
static int F_361 ( struct V_61 * V_140 ,
struct V_108 * V_92 ,
T_2 V_466 ,
enum V_435 V_362 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_473 V_474 ;
T_2 V_402 ;
int V_29 = 0 ;
ASSERT ( V_466 ) ;
ASSERT ( ! V_405 -> V_406 || V_362 != V_441 ) ;
F_11 ( & V_92 -> V_48 ) ;
V_29 = - V_317 ;
V_402 = F_307 ( V_92 , true ) ;
if ( V_402 + V_466 <= V_92 -> V_342 ) {
V_92 -> V_357 += V_466 ;
F_315 ( V_34 , L_11 ,
V_92 -> V_7 , V_466 , 1 ) ;
V_29 = 0 ;
} else if ( F_338 ( V_140 , V_92 , V_466 , V_362 ) ) {
V_92 -> V_357 += V_466 ;
F_315 ( V_34 , L_11 ,
V_92 -> V_7 , V_466 , 1 ) ;
V_29 = 0 ;
}
if ( V_29 && V_362 != V_429 ) {
V_474 . V_210 = V_466 ;
V_474 . error = 0 ;
F_64 ( & V_474 . V_87 ) ;
if ( V_362 == V_441 ) {
F_72 ( & V_474 . V_96 , & V_92 -> V_364 ) ;
if ( ! V_92 -> V_362 ) {
V_92 -> V_362 = 1 ;
F_362 ( V_34 ,
V_92 -> V_7 ,
V_466 , V_362 ,
L_13 ) ;
F_363 ( V_487 ,
& V_140 -> V_34 -> V_483 ) ;
}
} else {
F_72 ( & V_474 . V_96 ,
& V_92 -> V_365 ) ;
}
} else if ( ! V_29 && V_92 -> V_7 & V_51 ) {
V_402 += V_466 ;
if ( ! F_226 ( V_488 , & V_34 -> V_7 ) &&
F_353 ( V_92 , V_140 , V_402 ) &&
! F_364 ( & V_34 -> V_483 ) ) {
F_362 ( V_34 , V_92 -> V_7 ,
V_466 , V_362 , L_14 ) ;
F_363 ( V_487 ,
& V_34 -> V_483 ) ;
}
}
F_13 ( & V_92 -> V_48 ) ;
if ( ! V_29 || V_362 == V_429 )
return V_29 ;
if ( V_362 == V_441 )
return F_359 ( V_34 , V_92 , & V_474 ,
V_466 ) ;
V_29 = 0 ;
F_358 ( V_34 , V_92 , & V_474 ) ;
F_11 ( & V_92 -> V_48 ) ;
if ( V_474 . V_210 ) {
if ( V_474 . V_210 < V_466 ) {
T_2 V_35 = V_466 - V_474 . V_210 ;
V_92 -> V_357 -= V_35 ;
F_315 ( V_34 , L_11 ,
V_92 -> V_7 ,
V_35 , 0 ) ;
}
F_275 ( & V_474 . V_96 ) ;
V_29 = - V_317 ;
}
F_13 ( & V_92 -> V_48 ) ;
ASSERT ( F_183 ( & V_474 . V_96 ) ) ;
return V_29 ;
}
static int F_365 ( struct V_61 * V_140 ,
struct V_261 * V_451 ,
T_2 V_466 ,
enum V_435 V_362 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
int V_29 ;
V_29 = F_361 ( V_140 , V_451 -> V_92 , V_466 ,
V_362 ) ;
if ( V_29 == - V_317 &&
F_366 ( V_140 -> V_489 == V_490 ) ) {
if ( V_451 != V_262 &&
! F_367 ( V_262 , V_466 ) )
V_29 = 0 ;
}
if ( V_29 == - V_317 )
F_315 ( V_34 , L_10 ,
V_451 -> V_92 -> V_7 ,
V_466 , 1 ) ;
return V_29 ;
}
static struct V_261 * F_368 (
const struct V_114 * V_115 ,
const struct V_61 * V_140 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_261 * V_451 = NULL ;
if ( F_226 ( V_295 , & V_140 -> V_296 ) ||
( V_140 == V_34 -> V_491 && V_115 -> V_492 ) ||
( V_140 == V_34 -> V_493 ) )
V_451 = V_115 -> V_451 ;
if ( ! V_451 )
V_451 = V_140 -> V_451 ;
if ( ! V_451 )
V_451 = & V_34 -> V_494 ;
return V_451 ;
}
static int F_367 ( struct V_261 * V_451 ,
T_2 V_35 )
{
int V_29 = - V_317 ;
F_11 ( & V_451 -> V_48 ) ;
if ( V_451 -> V_10 >= V_35 ) {
V_451 -> V_10 -= V_35 ;
if ( V_451 -> V_10 < V_451 -> V_57 )
V_451 -> V_113 = 0 ;
V_29 = 0 ;
}
F_13 ( & V_451 -> V_48 ) ;
return V_29 ;
}
static void F_369 ( struct V_261 * V_451 ,
T_2 V_35 , int V_495 )
{
F_11 ( & V_451 -> V_48 ) ;
V_451 -> V_10 += V_35 ;
if ( V_495 )
V_451 -> V_57 += V_35 ;
else if ( V_451 -> V_10 >= V_451 -> V_57 )
V_451 -> V_113 = 1 ;
F_13 ( & V_451 -> V_48 ) ;
}
int F_370 ( struct V_12 * V_34 ,
struct V_261 * V_496 , T_2 V_35 ,
int V_497 )
{
struct V_261 * V_262 = & V_34 -> V_265 ;
T_2 V_498 ;
if ( V_262 -> V_92 != V_496 -> V_92 )
return - V_317 ;
F_11 ( & V_262 -> V_48 ) ;
V_498 = F_327 ( V_262 -> V_57 , V_497 ) ;
if ( V_262 -> V_10 < V_498 + V_35 ) {
F_13 ( & V_262 -> V_48 ) ;
return - V_317 ;
}
V_262 -> V_10 -= V_35 ;
if ( V_262 -> V_10 < V_262 -> V_57 )
V_262 -> V_113 = 0 ;
F_13 ( & V_262 -> V_48 ) ;
F_369 ( V_496 , V_35 , 1 ) ;
return 0 ;
}
static void F_371 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
T_2 V_35 )
{
struct V_473 * V_474 ;
struct V_109 * V_110 ;
T_2 V_402 ;
enum V_435 V_362 = V_429 ;
bool V_499 = false ;
F_11 ( & V_92 -> V_48 ) ;
V_110 = & V_92 -> V_365 ;
V_402 = V_92 -> V_91 + V_92 -> V_356 +
V_92 -> V_355 + V_92 -> V_343 +
V_92 -> V_357 ;
if ( V_402 - V_35 >= V_92 -> V_342 )
V_499 = true ;
V_162:
while ( ! F_183 ( V_110 ) && V_35 ) {
V_474 = F_184 ( V_110 , struct V_473 ,
V_96 ) ;
if ( V_499 &&
! F_338 ( V_34 -> V_62 , V_92 , 0 ,
V_362 ) )
break;
if ( V_35 >= V_474 -> V_210 ) {
F_275 ( & V_474 -> V_96 ) ;
V_35 -= V_474 -> V_210 ;
V_474 -> V_210 = 0 ;
V_92 -> V_484 ++ ;
F_52 ( & V_474 -> V_87 ) ;
} else {
V_474 -> V_210 -= V_35 ;
V_35 = 0 ;
}
}
if ( V_35 && V_110 == & V_92 -> V_365 ) {
V_110 = & V_92 -> V_364 ;
V_362 = V_441 ;
goto V_162;
}
V_92 -> V_357 -= V_35 ;
F_315 ( V_34 , L_11 ,
V_92 -> V_7 , V_35 , 0 ) ;
F_13 ( & V_92 -> V_48 ) ;
}
static void F_290 ( struct V_12 * V_34 ,
struct V_108 * V_92 ,
T_2 V_35 )
{
struct V_473 * V_474 ;
struct V_109 * V_110 = & V_92 -> V_365 ;
V_162:
while ( ! F_183 ( V_110 ) && V_35 ) {
V_474 = F_184 ( V_110 , struct V_473 ,
V_96 ) ;
if ( V_35 >= V_474 -> V_210 ) {
F_315 ( V_34 , L_11 ,
V_92 -> V_7 ,
V_474 -> V_210 , 1 ) ;
F_275 ( & V_474 -> V_96 ) ;
V_35 -= V_474 -> V_210 ;
V_92 -> V_357 += V_474 -> V_210 ;
V_474 -> V_210 = 0 ;
V_92 -> V_484 ++ ;
F_52 ( & V_474 -> V_87 ) ;
} else {
F_315 ( V_34 , L_11 ,
V_92 -> V_7 ,
V_35 , 1 ) ;
V_92 -> V_357 += V_35 ;
V_474 -> V_210 -= V_35 ;
V_35 = 0 ;
}
}
if ( V_35 && V_110 == & V_92 -> V_365 ) {
V_110 = & V_92 -> V_364 ;
goto V_162;
}
}
static void F_372 ( struct V_12 * V_34 ,
struct V_261 * V_451 ,
struct V_261 * V_496 , T_2 V_35 )
{
struct V_108 * V_92 = V_451 -> V_92 ;
F_11 ( & V_451 -> V_48 ) ;
if ( V_35 == ( T_2 ) - 1 )
V_35 = V_451 -> V_57 ;
V_451 -> V_57 -= V_35 ;
if ( V_451 -> V_10 >= V_451 -> V_57 ) {
V_35 = V_451 -> V_10 - V_451 -> V_57 ;
V_451 -> V_10 = V_451 -> V_57 ;
V_451 -> V_113 = 1 ;
} else {
V_35 = 0 ;
}
F_13 ( & V_451 -> V_48 ) ;
if ( V_35 > 0 ) {
if ( V_496 ) {
F_11 ( & V_496 -> V_48 ) ;
if ( ! V_496 -> V_113 ) {
T_2 V_500 ;
V_500 = V_496 -> V_57 - V_496 -> V_10 ;
V_500 = F_345 ( V_35 , V_500 ) ;
V_496 -> V_10 += V_500 ;
if ( V_496 -> V_10 >= V_496 -> V_57 )
V_496 -> V_113 = 1 ;
V_35 -= V_500 ;
}
F_13 ( & V_496 -> V_48 ) ;
}
if ( V_35 )
F_371 ( V_34 , V_92 ,
V_35 ) ;
}
}
int F_373 ( struct V_261 * V_501 ,
struct V_261 * V_502 , T_2 V_35 ,
int V_495 )
{
int V_29 ;
V_29 = F_367 ( V_501 , V_35 ) ;
if ( V_29 )
return V_29 ;
F_369 ( V_502 , V_35 , V_495 ) ;
return 0 ;
}
void F_374 ( struct V_261 * V_503 , unsigned short type )
{
memset ( V_503 , 0 , sizeof( * V_503 ) ) ;
F_293 ( & V_503 -> V_48 ) ;
V_503 -> type = type ;
}
struct V_261 * F_375 ( struct V_12 * V_34 ,
unsigned short type )
{
struct V_261 * V_451 ;
V_451 = F_223 ( sizeof( * V_451 ) , V_95 ) ;
if ( ! V_451 )
return NULL ;
F_374 ( V_451 , type ) ;
V_451 -> V_92 = F_77 ( V_34 ,
V_51 ) ;
return V_451 ;
}
void F_376 ( struct V_12 * V_34 ,
struct V_261 * V_503 )
{
if ( ! V_503 )
return;
F_377 ( V_34 , V_503 , ( T_2 ) - 1 ) ;
F_9 ( V_503 ) ;
}
void F_378 ( struct V_261 * V_503 )
{
F_9 ( V_503 ) ;
}
int F_335 ( struct V_61 * V_140 ,
struct V_261 * V_451 , T_2 V_35 ,
enum V_435 V_362 )
{
int V_29 ;
if ( V_35 == 0 )
return 0 ;
V_29 = F_365 ( V_140 , V_451 , V_35 , V_362 ) ;
if ( ! V_29 ) {
F_369 ( V_451 , V_35 , 1 ) ;
return 0 ;
}
return V_29 ;
}
int F_379 ( struct V_261 * V_451 , int V_497 )
{
T_2 V_35 = 0 ;
int V_29 = - V_317 ;
if ( ! V_451 )
return 0 ;
F_11 ( & V_451 -> V_48 ) ;
V_35 = F_327 ( V_451 -> V_57 , V_497 ) ;
if ( V_451 -> V_10 >= V_35 )
V_29 = 0 ;
F_13 ( & V_451 -> V_48 ) ;
return V_29 ;
}
int F_380 ( struct V_61 * V_140 ,
struct V_261 * V_451 , T_2 V_504 ,
enum V_435 V_362 )
{
T_2 V_35 = 0 ;
int V_29 = - V_317 ;
if ( ! V_451 )
return 0 ;
F_11 ( & V_451 -> V_48 ) ;
V_35 = V_504 ;
if ( V_451 -> V_10 >= V_35 )
V_29 = 0 ;
else
V_35 -= V_451 -> V_10 ;
F_13 ( & V_451 -> V_48 ) ;
if ( ! V_29 )
return 0 ;
V_29 = F_365 ( V_140 , V_451 , V_35 , V_362 ) ;
if ( ! V_29 ) {
F_369 ( V_451 , V_35 , 0 ) ;
return 0 ;
}
return V_29 ;
}
void F_377 ( struct V_12 * V_34 ,
struct V_261 * V_451 ,
T_2 V_35 )
{
struct V_261 * V_262 = & V_34 -> V_265 ;
if ( V_262 == V_451 ||
V_451 -> V_92 != V_262 -> V_92 )
V_262 = NULL ;
F_372 ( V_34 , V_451 , V_262 , V_35 ) ;
}
static void F_381 ( struct V_12 * V_34 )
{
struct V_261 * V_451 = & V_34 -> V_265 ;
struct V_108 * V_416 = V_451 -> V_92 ;
T_2 V_35 ;
V_35 = F_382 ( & V_34 -> V_62 -> V_287 ) +
F_382 ( & V_34 -> V_491 -> V_287 ) +
F_382 ( & V_34 -> V_274 -> V_287 ) ;
V_35 = F_35 ( T_2 , V_35 , V_476 ) ;
F_11 ( & V_416 -> V_48 ) ;
F_11 ( & V_451 -> V_48 ) ;
V_451 -> V_57 = F_24 ( T_2 , V_35 , V_505 ) ;
if ( V_451 -> V_10 < V_451 -> V_57 ) {
V_35 = F_307 ( V_416 , true ) ;
if ( V_416 -> V_342 > V_35 ) {
V_35 = V_416 -> V_342 - V_35 ;
V_35 = F_345 ( V_35 ,
V_451 -> V_57 - V_451 -> V_10 ) ;
V_451 -> V_10 += V_35 ;
V_416 -> V_357 += V_35 ;
F_315 ( V_34 , L_11 ,
V_416 -> V_7 , V_35 ,
1 ) ;
}
} else if ( V_451 -> V_10 > V_451 -> V_57 ) {
V_35 = V_451 -> V_10 - V_451 -> V_57 ;
V_416 -> V_357 -= V_35 ;
F_315 ( V_34 , L_11 ,
V_416 -> V_7 , V_35 , 0 ) ;
V_451 -> V_10 = V_451 -> V_57 ;
}
if ( V_451 -> V_10 == V_451 -> V_57 )
V_451 -> V_113 = 1 ;
else
V_451 -> V_113 = 0 ;
F_13 ( & V_451 -> V_48 ) ;
F_13 ( & V_416 -> V_48 ) ;
}
static void F_383 ( struct V_12 * V_34 )
{
struct V_108 * V_92 ;
V_92 = F_77 ( V_34 , V_341 ) ;
V_34 -> V_428 . V_92 = V_92 ;
V_92 = F_77 ( V_34 , V_51 ) ;
V_34 -> V_265 . V_92 = V_92 ;
V_34 -> V_457 . V_92 = V_92 ;
V_34 -> V_506 . V_92 = V_92 ;
V_34 -> V_494 . V_92 = V_92 ;
V_34 -> V_463 . V_92 = V_92 ;
V_34 -> V_62 -> V_451 = & V_34 -> V_265 ;
V_34 -> V_491 -> V_451 = & V_34 -> V_265 ;
V_34 -> V_507 -> V_451 = & V_34 -> V_265 ;
V_34 -> V_274 -> V_451 = & V_34 -> V_265 ;
if ( V_34 -> V_508 )
V_34 -> V_508 -> V_451 = & V_34 -> V_265 ;
V_34 -> V_398 -> V_451 = & V_34 -> V_428 ;
F_381 ( V_34 ) ;
}
static void F_384 ( struct V_12 * V_34 )
{
F_372 ( V_34 , & V_34 -> V_265 , NULL ,
( T_2 ) - 1 ) ;
F_8 ( V_34 -> V_457 . V_57 > 0 ) ;
F_8 ( V_34 -> V_457 . V_10 > 0 ) ;
F_8 ( V_34 -> V_506 . V_57 > 0 ) ;
F_8 ( V_34 -> V_506 . V_10 > 0 ) ;
F_8 ( V_34 -> V_428 . V_57 > 0 ) ;
F_8 ( V_34 -> V_428 . V_10 > 0 ) ;
F_8 ( V_34 -> V_463 . V_57 > 0 ) ;
F_8 ( V_34 -> V_463 . V_10 > 0 ) ;
}
void F_385 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
if ( ! V_115 -> V_451 )
return;
if ( ! V_115 -> V_356 )
return;
F_315 ( V_34 , L_15 ,
V_115 -> V_273 , V_115 -> V_356 , 0 ) ;
F_377 ( V_34 , V_115 -> V_451 ,
V_115 -> V_356 ) ;
V_115 -> V_356 = 0 ;
}
void F_337 ( struct V_114 * V_115 )
{
struct V_12 * V_34 = V_115 -> V_34 ;
if ( ! V_115 -> V_430 )
return;
F_386 ( ! F_183 ( & V_115 -> V_281 ) ) ;
F_372 ( V_34 , & V_34 -> V_428 , NULL ,
V_115 -> V_430 ) ;
V_115 -> V_430 = 0 ;
}
int F_387 ( struct V_114 * V_115 ,
struct V_401 * V_301 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_509 . V_414 ) ;
struct V_61 * V_140 = V_301 -> V_140 ;
struct V_261 * V_510 = V_115 -> V_451 ;
struct V_261 * V_511 = V_140 -> V_512 ;
T_2 V_35 = F_210 ( V_34 , 1 ) ;
F_315 ( V_34 , L_16 , F_388 ( V_301 ) ,
V_35 , 1 ) ;
return F_373 ( V_510 , V_511 , V_35 , 1 ) ;
}
void F_389 ( struct V_401 * V_301 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_509 . V_414 ) ;
struct V_61 * V_140 = V_301 -> V_140 ;
T_2 V_35 = F_210 ( V_34 , 1 ) ;
F_315 ( V_34 , L_16 , F_388 ( V_301 ) ,
V_35 , 0 ) ;
F_377 ( V_34 , V_140 -> V_512 , V_35 ) ;
}
int F_390 ( struct V_61 * V_140 ,
struct V_261 * V_503 ,
int V_455 ,
T_2 * V_229 ,
bool V_513 )
{
T_2 V_35 ;
int V_29 ;
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
if ( F_226 ( V_514 , & V_34 -> V_7 ) ) {
V_35 = 3 * V_34 -> V_52 ;
V_29 = F_391 ( V_140 , V_35 , true ) ;
if ( V_29 )
return V_29 ;
} else {
V_35 = 0 ;
}
* V_229 = V_35 ;
V_35 = F_210 ( V_34 , V_455 ) ;
V_503 -> V_92 = F_77 ( V_34 ,
V_51 ) ;
V_29 = F_335 ( V_140 , V_503 , V_35 ,
V_441 ) ;
if ( V_29 == - V_317 && V_513 )
V_29 = F_373 ( V_262 , V_503 , V_35 , 1 ) ;
if ( V_29 && * V_229 )
F_392 ( V_140 , * V_229 ) ;
return V_29 ;
}
void F_393 ( struct V_12 * V_34 ,
struct V_261 * V_503 )
{
F_377 ( V_34 , V_503 , ( T_2 ) - 1 ) ;
}
static unsigned F_394 ( struct V_401 * V_301 ,
T_2 V_35 )
{
unsigned V_515 = 0 ;
unsigned V_516 = 0 ;
unsigned V_517 ;
V_517 = F_395 ( V_35 ) ;
ASSERT ( V_517 ) ;
ASSERT ( V_301 -> V_518 >= V_517 ) ;
V_301 -> V_518 -= V_517 ;
if ( V_301 -> V_518 == 0 &&
F_396 ( V_519 ,
& V_301 -> V_520 ) )
V_515 = 1 ;
if ( V_301 -> V_518 >= V_301 -> V_521 )
return V_515 ;
V_516 = V_301 -> V_521 - V_301 -> V_518 ;
V_301 -> V_521 -= V_516 ;
return V_516 + V_515 ;
}
static T_2 F_397 ( struct V_401 * V_301 , T_2 V_35 ,
int V_522 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_509 . V_414 ) ;
T_2 V_523 , V_259 ;
if ( V_301 -> V_7 & V_524 && V_301 -> V_256 == 0 )
return 0 ;
V_523 = F_205 ( V_34 , V_301 -> V_256 ) ;
if ( V_522 )
V_301 -> V_256 += V_35 ;
else
V_301 -> V_256 -= V_35 ;
V_259 = F_205 ( V_34 , V_301 -> V_256 ) ;
if ( V_523 == V_259 )
return 0 ;
if ( V_522 )
return F_210 ( V_34 ,
V_259 - V_523 ) ;
return F_210 ( V_34 , V_523 - V_259 ) ;
}
int F_398 ( struct V_401 * V_301 , T_2 V_35 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_509 . V_414 ) ;
struct V_61 * V_140 = V_301 -> V_140 ;
struct V_261 * V_451 = & V_34 -> V_457 ;
T_2 V_525 = 0 ;
T_2 V_256 ;
unsigned V_526 ;
enum V_435 V_362 = V_441 ;
int V_29 = 0 ;
bool V_527 = true ;
T_2 V_528 = 0 ;
unsigned V_529 ;
bool V_530 = false ;
if ( F_309 ( V_301 ) ) {
V_362 = V_429 ;
V_527 = false ;
} else if ( V_405 -> V_406 ) {
V_362 = V_531 ;
}
if ( V_362 != V_429 &&
F_399 ( V_34 ) )
F_400 ( 1 ) ;
if ( V_527 )
F_49 ( & V_301 -> V_532 ) ;
V_35 = F_149 ( V_35 , V_34 -> V_53 ) ;
F_11 ( & V_301 -> V_48 ) ;
V_526 = F_395 ( V_35 ) ;
V_301 -> V_518 += V_526 ;
V_526 = 0 ;
if ( V_301 -> V_518 > V_301 -> V_521 )
V_526 += V_301 -> V_518 -
V_301 -> V_521 ;
V_525 = F_210 ( V_34 , V_526 + 1 ) ;
V_525 += F_397 ( V_301 , V_35 , 1 ) ;
V_256 = V_301 -> V_256 ;
F_13 ( & V_301 -> V_48 ) ;
if ( F_226 ( V_514 , & V_34 -> V_7 ) ) {
V_29 = F_391 ( V_140 ,
V_526 * V_34 -> V_52 , true ) ;
if ( V_29 )
goto V_533;
}
V_29 = F_335 ( V_140 , V_451 , V_525 , V_362 ) ;
if ( F_366 ( V_29 ) ) {
F_392 ( V_140 ,
V_526 * V_34 -> V_52 ) ;
goto V_533;
}
F_11 ( & V_301 -> V_48 ) ;
if ( F_401 ( V_519 ,
& V_301 -> V_520 ) ) {
V_525 -= F_210 ( V_34 , 1 ) ;
V_530 = true ;
}
V_301 -> V_521 += V_526 ;
F_13 ( & V_301 -> V_48 ) ;
if ( V_527 )
F_47 ( & V_301 -> V_532 ) ;
if ( V_525 )
F_315 ( V_34 , L_17 ,
F_388 ( V_301 ) , V_525 , 1 ) ;
if ( V_530 )
F_377 ( V_34 , V_451 ,
F_210 ( V_34 , 1 ) ) ;
return 0 ;
V_533:
F_11 ( & V_301 -> V_48 ) ;
V_529 = F_394 ( V_301 , V_35 ) ;
if ( V_301 -> V_256 == V_256 ) {
F_397 ( V_301 , V_35 , 0 ) ;
} else {
T_2 V_534 = V_301 -> V_256 ;
T_2 V_210 ;
V_210 = V_256 - V_301 -> V_256 ;
V_301 -> V_256 = V_256 ;
V_528 = F_397 ( V_301 , V_210 , 0 ) ;
V_301 -> V_256 = V_256 - V_35 ;
V_210 = V_256 - V_534 ;
V_210 = F_397 ( V_301 , V_210 , 0 ) ;
V_301 -> V_256 = V_534 - V_35 ;
if ( V_210 > V_528 )
V_528 = V_210 - V_528 ;
else
V_528 = 0 ;
}
F_13 ( & V_301 -> V_48 ) ;
if ( V_529 )
V_528 += F_210 ( V_34 , V_529 ) ;
if ( V_528 ) {
F_377 ( V_34 , V_451 , V_528 ) ;
F_315 ( V_34 , L_17 ,
F_388 ( V_301 ) , V_528 , 0 ) ;
}
if ( V_527 )
F_47 ( & V_301 -> V_532 ) ;
return V_29 ;
}
void F_402 ( struct V_401 * V_301 , T_2 V_35 )
{
struct V_12 * V_34 = F_316 ( V_301 -> V_509 . V_414 ) ;
T_2 V_528 = 0 ;
unsigned V_529 ;
V_35 = F_149 ( V_35 , V_34 -> V_53 ) ;
F_11 ( & V_301 -> V_48 ) ;
V_529 = F_394 ( V_301 , V_35 ) ;
if ( V_35 )
V_528 = F_397 ( V_301 , V_35 , 0 ) ;
F_13 ( & V_301 -> V_48 ) ;
if ( V_529 > 0 )
V_528 += F_210 ( V_34 , V_529 ) ;
if ( F_242 ( V_34 ) )
return;
F_315 ( V_34 , L_17 , F_388 ( V_301 ) ,
V_528 , 0 ) ;
F_377 ( V_34 , & V_34 -> V_457 , V_528 ) ;
}
int F_403 ( struct V_301 * V_301 , T_2 V_32 , T_2 V_45 )
{
int V_29 ;
V_29 = F_266 ( V_301 , V_32 , V_45 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_398 ( F_261 ( V_301 ) , V_45 ) ;
if ( V_29 < 0 )
F_320 ( V_301 , V_32 , V_45 ) ;
return V_29 ;
}
void F_404 ( struct V_301 * V_301 , T_2 V_32 , T_2 V_45 )
{
F_402 ( F_261 ( V_301 ) , V_45 ) ;
F_320 ( V_301 , V_32 , V_45 ) ;
}
static int F_405 ( struct V_114 * V_115 ,
struct V_12 * V_13 , T_2 V_27 ,
T_2 V_35 , int V_407 )
{
struct V_1 * V_2 = NULL ;
T_2 V_535 = V_35 ;
T_2 V_536 ;
T_2 V_537 ;
int V_344 ;
F_11 ( & V_13 -> V_538 ) ;
V_536 = F_406 ( V_13 -> V_260 ) ;
if ( V_407 )
V_536 += V_35 ;
else
V_536 -= V_35 ;
F_407 ( V_13 -> V_260 , V_536 ) ;
F_13 ( & V_13 -> V_538 ) ;
while ( V_535 ) {
V_2 = F_76 ( V_13 , V_27 ) ;
if ( ! V_2 )
return - V_159 ;
if ( V_2 -> V_7 & ( V_345 |
V_346 |
V_347 ) )
V_344 = 2 ;
else
V_344 = 1 ;
if ( ! V_407 && V_2 -> V_3 == V_100 )
F_59 ( V_2 , 1 ) ;
V_537 = V_27 - V_2 -> V_21 . V_22 ;
F_8 ( V_537 > V_2 -> V_21 . V_33 ) ;
F_11 ( & V_2 -> V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( F_265 ( V_13 , V_315 ) &&
V_2 -> V_308 < V_322 )
V_2 -> V_308 = V_322 ;
V_536 = F_58 ( & V_2 -> V_93 ) ;
V_35 = F_345 ( V_535 , V_2 -> V_21 . V_33 - V_537 ) ;
if ( V_407 ) {
V_536 += V_35 ;
F_408 ( & V_2 -> V_93 , V_536 ) ;
V_2 -> V_10 -= V_35 ;
V_2 -> V_92 -> V_356 -= V_35 ;
V_2 -> V_92 -> V_91 += V_35 ;
V_2 -> V_92 -> V_349 += V_35 * V_344 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
} else {
V_536 -= V_35 ;
F_408 ( & V_2 -> V_93 , V_536 ) ;
V_2 -> V_9 += V_35 ;
V_2 -> V_92 -> V_355 += V_35 ;
V_2 -> V_92 -> V_91 -= V_35 ;
V_2 -> V_92 -> V_349 -= V_35 * V_344 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
F_315 ( V_13 , L_18 ,
V_2 -> V_92 -> V_7 ,
V_35 , 1 ) ;
F_409 ( V_13 -> V_59 ,
V_27 , V_27 + V_35 - 1 ,
V_95 | V_539 ) ;
}
F_11 ( & V_115 -> V_132 -> V_329 ) ;
if ( F_183 ( & V_2 -> V_331 ) ) {
F_72 ( & V_2 -> V_331 ,
& V_115 -> V_132 -> V_321 ) ;
V_115 -> V_132 -> V_263 ++ ;
F_4 ( V_2 ) ;
}
F_13 ( & V_115 -> V_132 -> V_329 ) ;
if ( ! V_407 && V_536 == 0 ) {
F_11 ( & V_13 -> V_540 ) ;
if ( F_183 ( & V_2 -> V_541 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_541 ,
& V_13 -> V_542 ) ;
}
F_13 ( & V_13 -> V_540 ) ;
}
F_6 ( V_2 ) ;
V_535 -= V_35 ;
V_27 += V_35 ;
}
return 0 ;
}
static T_2 V_26 ( struct V_12 * V_34 , T_2 V_543 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
F_11 ( & V_34 -> V_18 ) ;
V_27 = V_34 -> V_26 ;
F_13 ( & V_34 -> V_18 ) ;
if ( V_27 < ( T_2 ) - 1 )
return V_27 ;
V_2 = F_75 ( V_34 , V_543 ) ;
if ( ! V_2 )
return 0 ;
V_27 = V_2 -> V_21 . V_22 ;
F_6 ( V_2 ) ;
return V_27 ;
}
static int F_410 ( struct V_12 * V_34 ,
struct V_1 * V_2 ,
T_2 V_27 , T_2 V_35 , int V_10 )
{
F_11 ( & V_2 -> V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
V_2 -> V_9 += V_35 ;
V_2 -> V_92 -> V_355 += V_35 ;
if ( V_10 ) {
V_2 -> V_10 -= V_35 ;
V_2 -> V_92 -> V_356 -= V_35 ;
}
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_2 -> V_92 -> V_48 ) ;
F_315 ( V_34 , L_18 ,
V_2 -> V_92 -> V_7 , V_35 , 1 ) ;
F_409 ( V_34 -> V_59 , V_27 ,
V_27 + V_35 - 1 , V_95 | V_539 ) ;
return 0 ;
}
int F_176 ( struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_34 , V_27 ) ;
F_32 ( ! V_2 ) ;
F_410 ( V_34 , V_2 , V_27 , V_35 , V_10 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_411 ( struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_76 ( V_34 , V_27 ) ;
if ( ! V_2 )
return - V_544 ;
F_59 ( V_2 , 1 ) ;
F_410 ( V_34 , V_2 , V_27 , V_35 , 0 ) ;
V_29 = F_28 ( V_2 , V_27 , V_35 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
static int F_412 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_35 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_46 * V_49 ;
V_14 = F_76 ( V_34 , V_32 ) ;
if ( ! V_14 )
return - V_544 ;
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
goto V_545;
V_35 = ( V_32 + V_35 ) -
V_49 -> V_83 ;
V_32 = V_49 -> V_83 ;
V_29 = F_17 ( V_34 , V_32 , V_35 ) ;
}
V_545:
F_47 ( & V_49 -> V_84 ) ;
F_26 ( V_49 ) ;
}
F_6 ( V_14 ) ;
return V_29 ;
}
int F_413 ( struct V_12 * V_34 ,
struct V_65 * V_546 )
{
struct V_293 * V_93 ;
struct V_67 V_21 ;
int V_547 ;
int V_40 ;
if ( ! F_84 ( V_34 , V_548 ) )
return 0 ;
for ( V_40 = 0 ; V_40 < F_39 ( V_546 ) ; V_40 ++ ) {
F_41 ( V_546 , & V_21 , V_40 ) ;
if ( V_21 . type != V_298 )
continue;
V_93 = F_86 ( V_546 , V_40 , struct V_293 ) ;
V_547 = F_245 ( V_546 , V_93 ) ;
if ( V_547 == V_299 )
continue;
if ( F_246 ( V_546 , V_93 ) == 0 )
continue;
V_21 . V_22 = F_246 ( V_546 , V_93 ) ;
V_21 . V_33 = F_247 ( V_546 , V_93 ) ;
F_412 ( V_34 , V_21 . V_22 , V_21 . V_33 ) ;
}
return 0 ;
}
static void
F_414 ( struct V_1 * V_337 )
{
F_5 ( & V_337 -> V_549 ) ;
}
void F_415 ( struct V_12 * V_34 ,
const T_2 V_32 )
{
struct V_1 * V_337 ;
V_337 = F_76 ( V_34 , V_32 ) ;
ASSERT ( V_337 ) ;
if ( F_7 ( & V_337 -> V_549 ) )
F_284 ( & V_337 -> V_549 ) ;
F_6 ( V_337 ) ;
}
static int F_416 ( T_7 * V_339 )
{
F_68 () ;
return 0 ;
}
void F_417 ( struct V_1 * V_337 )
{
struct V_108 * V_92 = V_337 -> V_92 ;
ASSERT ( V_337 -> V_310 ) ;
if ( ! ( V_337 -> V_7 & V_340 ) )
return;
F_71 ( & V_92 -> V_354 ) ;
F_73 ( & V_92 -> V_354 ) ;
F_287 ( & V_337 -> V_549 ,
F_416 ,
V_99 ) ;
}
static int F_418 ( struct V_1 * V_2 ,
T_2 V_550 , T_2 V_35 , int V_551 )
{
struct V_108 * V_92 = V_2 -> V_92 ;
int V_29 = 0 ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_310 ) {
V_29 = - V_185 ;
} else {
V_2 -> V_10 += V_35 ;
V_92 -> V_356 += V_35 ;
F_315 ( V_2 -> V_34 ,
L_11 , V_92 -> V_7 ,
V_550 , 0 ) ;
V_92 -> V_357 -= V_550 ;
if ( V_551 )
V_2 -> V_452 += V_35 ;
}
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
static int F_419 ( struct V_1 * V_2 ,
T_2 V_35 , int V_551 )
{
struct V_108 * V_92 = V_2 -> V_92 ;
int V_29 = 0 ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_310 )
V_92 -> V_343 += V_35 ;
V_2 -> V_10 -= V_35 ;
V_92 -> V_356 -= V_35 ;
if ( V_551 )
V_2 -> V_452 -= V_35 ;
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
return V_29 ;
}
void F_420 ( struct V_12 * V_34 )
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
F_381 ( V_34 ) ;
}
static struct V_552 *
F_421 ( struct V_12 * V_34 ,
struct V_108 * V_92 , T_2 * V_553 )
{
struct V_552 * V_29 = NULL ;
bool V_554 = F_265 ( V_34 , V_555 ) ;
* V_553 = 0 ;
if ( F_336 ( V_92 ) )
return V_29 ;
if ( V_554 )
* V_553 = V_422 ;
if ( V_92 -> V_7 & V_51 ) {
V_29 = & V_34 -> V_556 ;
if ( ! V_554 )
* V_553 = V_557 ;
} else if ( ( V_92 -> V_7 & V_340 ) && V_554 ) {
V_29 = & V_34 -> V_558 ;
}
return V_29 ;
}
static int F_422 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_31 ,
const bool V_559 )
{
struct V_1 * V_2 = NULL ;
struct V_108 * V_92 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
struct V_552 * V_560 = NULL ;
T_2 V_45 ;
T_2 V_561 = 0 ;
T_2 V_553 = 0 ;
bool V_336 ;
while ( V_32 <= V_31 ) {
V_336 = false ;
if ( ! V_2 ||
V_32 >= V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) {
if ( V_2 )
F_6 ( V_2 ) ;
V_561 = 0 ;
V_2 = F_76 ( V_34 , V_32 ) ;
F_32 ( ! V_2 ) ;
V_560 = F_421 ( V_34 ,
V_2 -> V_92 ,
& V_553 ) ;
V_553 <<= 1 ;
}
V_45 = V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 - V_32 ;
V_45 = F_345 ( V_45 , V_31 + 1 - V_32 ) ;
if ( V_32 < V_2 -> V_103 ) {
V_45 = F_345 ( V_45 , V_2 -> V_103 - V_32 ) ;
if ( V_559 )
F_31 ( V_2 , V_32 , V_45 ) ;
}
V_32 += V_45 ;
V_561 += V_45 ;
V_92 = V_2 -> V_92 ;
if ( V_560 && V_560 -> V_562 &&
V_561 > V_553 ) {
F_11 ( & V_560 -> V_48 ) ;
V_560 -> V_562 = 0 ;
F_13 ( & V_560 -> V_48 ) ;
}
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
V_2 -> V_9 -= V_45 ;
V_92 -> V_355 -= V_45 ;
F_315 ( V_34 , L_18 ,
V_92 -> V_7 , V_45 , 0 ) ;
V_92 -> V_358 = 0 ;
F_423 ( & V_92 -> V_350 , - V_45 ) ;
if ( V_2 -> V_310 ) {
V_92 -> V_343 += V_45 ;
V_336 = true ;
}
F_13 ( & V_2 -> V_48 ) ;
if ( ! V_336 && V_559 &&
V_262 -> V_92 == V_92 ) {
T_2 V_563 = V_45 ;
F_8 ( ! V_559 ) ;
F_11 ( & V_262 -> V_48 ) ;
if ( ! V_262 -> V_113 ) {
V_563 = F_345 ( V_45 , V_262 -> V_57 -
V_262 -> V_10 ) ;
V_262 -> V_10 += V_563 ;
V_92 -> V_357 += V_563 ;
if ( V_262 -> V_10 >= V_262 -> V_57 )
V_262 -> V_113 = 1 ;
F_315 ( V_34 ,
L_11 ,
V_92 -> V_7 ,
V_563 , 1 ) ;
V_45 -= V_563 ;
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
int F_424 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_14 , * V_320 ;
struct V_109 * V_564 ;
struct V_565 * V_566 ;
T_2 V_32 ;
T_2 V_31 ;
int V_29 ;
if ( V_34 -> V_59 == & V_34 -> V_36 [ 0 ] )
V_566 = & V_34 -> V_36 [ 1 ] ;
else
V_566 = & V_34 -> V_36 [ 0 ] ;
while ( ! V_115 -> V_226 ) {
F_49 ( & V_34 -> V_567 ) ;
V_29 = F_30 ( V_566 , 0 , & V_32 , & V_31 ,
V_60 , NULL ) ;
if ( V_29 ) {
F_47 ( & V_34 -> V_567 ) ;
break;
}
if ( F_265 ( V_34 , V_568 ) )
V_29 = F_153 ( V_34 , V_32 ,
V_31 + 1 - V_32 , NULL ) ;
F_425 ( V_566 , V_32 , V_31 ) ;
F_422 ( V_34 , V_32 , V_31 , true ) ;
F_47 ( & V_34 -> V_567 ) ;
F_48 () ;
}
V_564 = & V_115 -> V_132 -> V_564 ;
F_271 (block_group, tmp, deleted_bgs, bg_list) {
T_2 V_569 = 0 ;
V_29 = - V_570 ;
if ( ! V_115 -> V_226 )
V_29 = F_153 ( V_34 ,
V_14 -> V_21 . V_22 ,
V_14 -> V_21 . V_33 ,
& V_569 ) ;
F_275 ( & V_14 -> V_541 ) ;
F_426 ( V_14 ) ;
F_6 ( V_14 ) ;
if ( V_29 ) {
const char * V_571 = F_427 ( V_29 ) ;
F_428 ( V_34 ,
L_19 ,
V_29 , V_571 ) ;
}
}
return 0 ;
}
static void F_429 ( struct V_12 * V_34 , T_2 V_35 ,
T_2 V_138 , T_2 V_151 )
{
struct V_108 * V_92 ;
T_2 V_7 ;
if ( V_138 < V_148 ) {
if ( V_151 == V_572 )
V_7 = V_341 ;
else
V_7 = V_51 ;
} else {
V_7 = V_340 ;
}
V_92 = F_77 ( V_34 , V_7 ) ;
F_32 ( ! V_92 ) ;
F_423 ( & V_92 -> V_350 , V_35 ) ;
}
static int F_167 ( struct V_114 * V_115 ,
struct V_12 * V_13 ,
struct V_217 * V_133 , T_2 V_17 ,
T_2 V_151 , T_2 V_573 ,
T_2 V_574 , int V_166 ,
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
int V_575 = 0 ;
int V_576 = 0 ;
int V_577 = 1 ;
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
V_191 = V_573 >= V_148 ;
F_32 ( ! V_191 && V_166 != 1 ) ;
if ( V_191 )
V_180 = 0 ;
V_29 = F_142 ( V_115 , V_13 , V_64 , & V_171 ,
V_27 , V_35 , V_17 ,
V_151 , V_573 ,
V_574 ) ;
if ( V_29 == 0 ) {
V_575 = V_64 -> V_81 [ 0 ] ;
while ( V_575 >= 0 ) {
F_41 ( V_64 -> V_80 [ 0 ] , & V_21 ,
V_575 ) ;
if ( V_21 . V_22 != V_27 )
break;
if ( V_21 . type == V_77 &&
V_21 . V_33 == V_35 ) {
V_576 = 1 ;
break;
}
if ( V_21 . type == V_85 &&
V_21 . V_33 == V_573 ) {
V_576 = 1 ;
break;
}
if ( V_64 -> V_81 [ 0 ] - V_575 > 5 )
break;
V_575 -- ;
}
#ifdef F_89
V_123 = F_85 ( V_64 -> V_80 [ 0 ] , V_575 ) ;
if ( V_576 && V_123 < sizeof( * V_122 ) )
V_576 = 0 ;
#endif
if ( ! V_576 ) {
F_32 ( V_171 ) ;
V_29 = F_147 ( V_115 , V_13 , V_64 , NULL ,
V_166 ,
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
V_21 . V_33 = V_573 ;
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
F_430 ( V_13 , V_64 -> V_80 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_575 = V_64 -> V_81 [ 0 ] ;
}
} else if ( F_8 ( V_29 == - V_159 ) ) {
F_430 ( V_13 , V_64 -> V_80 [ 0 ] ) ;
F_173 ( V_13 ,
L_21 ,
V_27 , V_17 , V_151 , V_573 ,
V_574 ) ;
F_162 ( V_115 , V_29 ) ;
goto V_79;
} else {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_575 ) ;
#ifdef F_89
if ( V_123 < sizeof( * V_122 ) ) {
F_32 ( V_576 || V_575 != V_64 -> V_81 [ 0 ] ) ;
V_29 = F_95 ( V_115 , V_13 , V_64 , V_573 ,
0 ) ;
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
F_430 ( V_13 , V_64 -> V_80 [ 0 ] ) ;
}
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_575 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
V_123 = F_85 ( V_66 , V_575 ) ;
}
#endif
F_32 ( V_123 < sizeof( * V_122 ) ) ;
V_122 = F_86 ( V_66 , V_575 ,
struct V_121 ) ;
if ( V_573 < V_148 &&
V_21 . type == V_77 ) {
struct V_143 * V_144 ;
F_32 ( V_123 < sizeof( * V_122 ) + sizeof( * V_144 ) ) ;
V_144 = (struct V_143 * ) ( V_122 + 1 ) ;
F_8 ( V_573 != F_431 ( V_66 , V_144 ) ) ;
}
V_117 = F_87 ( V_66 , V_122 ) ;
if ( V_117 < V_166 ) {
F_173 ( V_13 ,
L_22 ,
V_166 , V_117 , V_27 ) ;
V_29 = - V_544 ;
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_117 -= V_166 ;
if ( V_117 > 0 ) {
if ( V_134 )
F_138 ( V_134 , V_66 , V_122 ) ;
if ( V_171 ) {
F_32 ( ! V_576 ) ;
} else {
F_98 ( V_66 , V_122 , V_117 ) ;
F_103 ( V_66 ) ;
}
if ( V_576 ) {
V_29 = F_147 ( V_115 , V_13 , V_64 ,
V_171 , V_166 ,
V_191 , & V_167 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
}
F_429 ( V_13 , - V_35 , V_573 ,
V_151 ) ;
} else {
if ( V_576 ) {
F_32 ( V_191 && V_166 !=
F_126 ( V_64 , V_171 ) ) ;
if ( V_171 ) {
F_32 ( V_64 -> V_81 [ 0 ] != V_575 ) ;
} else {
F_32 ( V_64 -> V_81 [ 0 ] != V_575 + 1 ) ;
V_64 -> V_81 [ 0 ] = V_575 ;
V_577 = 2 ;
}
}
V_167 = 1 ;
V_29 = F_432 ( V_115 , V_62 , V_64 , V_64 -> V_81 [ 0 ] ,
V_577 ) ;
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
V_29 = F_433 ( V_115 , V_13 , V_27 , V_35 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_79;
}
V_29 = F_405 ( V_115 , V_13 , V_27 , V_35 , 0 ) ;
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
static T_1 int F_434 ( struct V_114 * V_115 ,
T_2 V_27 )
{
struct V_118 * V_110 ;
struct V_119 * V_120 ;
int V_29 = 0 ;
V_120 = & V_115 -> V_132 -> V_120 ;
F_11 ( & V_120 -> V_48 ) ;
V_110 = F_92 ( V_120 , V_27 ) ;
if ( ! V_110 )
goto V_578;
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
V_578:
F_13 ( & V_120 -> V_48 ) ;
return 0 ;
}
void F_435 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_65 * V_290 ,
T_2 V_17 , int V_167 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
int V_579 = 1 ;
int V_29 ;
if ( V_140 -> V_286 . V_22 != V_215 ) {
V_29 = F_159 ( V_34 , V_115 ,
V_290 -> V_32 , V_290 -> V_45 ,
V_17 ,
V_140 -> V_286 . V_22 ,
F_244 ( V_290 ) ,
V_224 , NULL ) ;
F_32 ( V_29 ) ;
}
if ( ! V_167 )
return;
if ( F_436 ( V_290 ) == V_115 -> V_273 ) {
struct V_1 * V_2 ;
if ( V_140 -> V_286 . V_22 != V_215 ) {
V_29 = F_434 ( V_115 , V_290 -> V_32 ) ;
if ( ! V_29 )
goto V_79;
}
V_2 = F_76 ( V_34 , V_290 -> V_32 ) ;
if ( F_437 ( V_290 , V_580 ) ) {
F_410 ( V_34 , V_2 , V_290 -> V_32 ,
V_290 -> V_45 , 1 ) ;
F_6 ( V_2 ) ;
goto V_79;
}
F_8 ( F_226 ( V_581 , & V_290 -> V_582 ) ) ;
F_31 ( V_2 , V_290 -> V_32 , V_290 -> V_45 ) ;
F_419 ( V_2 , V_290 -> V_45 , 0 ) ;
F_6 ( V_2 ) ;
F_438 ( V_34 , V_290 -> V_32 , V_290 -> V_45 ) ;
V_579 = 0 ;
}
V_79:
if ( V_579 )
F_429 ( V_34 , V_290 -> V_45 , F_244 ( V_290 ) ,
V_140 -> V_286 . V_22 ) ;
F_439 ( V_583 , & V_290 -> V_582 ) ;
}
int V_297 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_27 , T_2 V_35 , T_2 V_17 , T_2 V_151 ,
T_2 V_138 , T_2 V_33 )
{
int V_29 ;
if ( F_242 ( V_34 ) )
return 0 ;
F_429 ( V_34 , V_35 , V_138 , V_151 ) ;
if ( V_151 == V_215 ) {
F_8 ( V_138 >= V_148 ) ;
F_176 ( V_34 , V_27 , V_35 , 1 ) ;
V_29 = 0 ;
} else if ( V_138 < V_148 ) {
V_29 = F_159 ( V_34 , V_115 , V_27 ,
V_35 ,
V_17 , V_151 , ( int ) V_138 ,
V_224 , NULL ) ;
} else {
V_29 = F_160 ( V_34 , V_115 , V_27 ,
V_35 ,
V_17 , V_151 , V_138 ,
V_33 , 0 ,
V_224 ) ;
}
return V_29 ;
}
static T_1 void
F_440 ( struct V_1 * V_2 ,
T_2 V_35 )
{
struct V_46 * V_49 ;
V_49 = F_25 ( V_2 ) ;
if ( ! V_49 )
return;
F_280 ( V_49 -> V_87 , F_1 ( V_2 ) ||
( V_2 -> V_11 -> V_584 >= V_35 ) ) ;
F_26 ( V_49 ) ;
}
static T_1 int
F_441 ( struct V_1 * V_2 )
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
int F_442 ( T_2 V_7 )
{
if ( V_7 & V_347 )
return V_585 ;
else if ( V_7 & V_346 )
return V_586 ;
else if ( V_7 & V_345 )
return V_587 ;
else if ( V_7 & V_395 )
return V_588 ;
else if ( V_7 & V_394 )
return V_589 ;
else if ( V_7 & V_393 )
return V_590 ;
return V_591 ;
}
int F_443 ( struct V_1 * V_2 )
{
return F_442 ( V_2 -> V_7 ) ;
}
static const char * F_444 ( enum V_592 type )
{
if ( type >= V_352 )
return NULL ;
return V_593 [ type ] ;
}
static inline void
F_445 ( struct V_1 * V_2 ,
int V_551 )
{
if ( V_551 )
F_50 ( & V_2 -> V_594 ) ;
}
static inline void
F_446 ( struct V_1 * V_2 ,
int V_551 )
{
F_4 ( V_2 ) ;
if ( V_551 )
F_50 ( & V_2 -> V_594 ) ;
}
static struct V_1 *
F_447 ( struct V_1 * V_14 ,
struct V_552 * V_560 ,
int V_551 )
{
struct V_1 * V_595 = NULL ;
F_11 ( & V_560 -> V_596 ) ;
while ( 1 ) {
V_595 = V_560 -> V_14 ;
if ( ! V_595 )
return NULL ;
if ( V_595 == V_14 )
return V_595 ;
F_4 ( V_595 ) ;
if ( ! V_551 )
return V_595 ;
if ( F_340 ( & V_595 -> V_594 ) )
return V_595 ;
F_13 ( & V_560 -> V_596 ) ;
F_448 ( & V_595 -> V_594 , V_597 ) ;
F_11 ( & V_560 -> V_596 ) ;
if ( V_595 == V_560 -> V_14 )
return V_595 ;
F_46 ( & V_595 -> V_594 ) ;
F_6 ( V_595 ) ;
}
}
static inline void
F_449 ( struct V_1 * V_2 ,
int V_551 )
{
if ( V_551 )
F_46 ( & V_2 -> V_594 ) ;
F_6 ( V_2 ) ;
}
static T_1 int F_450 ( struct V_12 * V_34 ,
T_2 V_550 , T_2 V_35 , T_2 V_598 ,
T_2 V_599 , struct V_67 * V_221 ,
T_2 V_7 , int V_551 )
{
int V_29 = 0 ;
struct V_61 * V_140 = V_34 -> V_62 ;
struct V_552 * V_600 = NULL ;
struct V_1 * V_14 = NULL ;
T_2 V_543 = 0 ;
T_2 V_358 = 0 ;
T_2 V_553 = 0 ;
struct V_108 * V_92 ;
int V_601 = 0 ;
int V_602 = F_442 ( V_7 ) ;
bool V_603 = false ;
bool V_604 = false ;
bool V_605 = true ;
bool V_606 = false ;
bool V_607 = false ;
bool V_608 = false ;
F_8 ( V_35 < V_34 -> V_53 ) ;
V_221 -> type = V_77 ;
V_221 -> V_22 = 0 ;
V_221 -> V_33 = 0 ;
F_451 ( V_34 , V_35 , V_598 , V_7 ) ;
V_92 = F_77 ( V_34 , V_7 ) ;
if ( ! V_92 ) {
F_173 ( V_34 , L_23 , V_7 ) ;
return - V_317 ;
}
if ( F_366 ( V_92 -> V_358 ) ) {
F_11 ( & V_92 -> V_48 ) ;
if ( V_92 -> V_358 &&
V_35 > V_92 -> V_358 ) {
V_221 -> V_33 = V_92 -> V_358 ;
F_13 ( & V_92 -> V_48 ) ;
return - V_317 ;
} else if ( V_92 -> V_358 ) {
V_605 = false ;
}
F_13 ( & V_92 -> V_48 ) ;
}
V_600 = F_421 ( V_34 , V_92 , & V_553 ) ;
if ( V_600 ) {
F_11 ( & V_600 -> V_48 ) ;
if ( V_600 -> V_14 )
V_599 = V_600 -> V_609 ;
if ( V_600 -> V_562 ) {
V_599 = V_600 -> V_609 ;
V_605 = false ;
}
F_13 ( & V_600 -> V_48 ) ;
}
V_543 = F_452 ( V_543 , V_26 ( V_34 , 0 ) ) ;
V_543 = F_452 ( V_543 , V_599 ) ;
if ( V_543 == V_599 ) {
V_14 = F_76 ( V_34 , V_543 ) ;
if ( V_14 && F_3 ( V_14 , V_7 ) &&
V_14 -> V_3 != V_100 ) {
F_50 ( & V_92 -> V_354 ) ;
if ( F_183 ( & V_14 -> V_96 ) ||
V_14 -> V_310 ) {
F_6 ( V_14 ) ;
F_46 ( & V_92 -> V_354 ) ;
} else {
V_602 = F_443 ( V_14 ) ;
F_445 ( V_14 , V_551 ) ;
goto V_610;
}
} else if ( V_14 ) {
F_6 ( V_14 ) ;
}
}
V_611:
V_606 = false ;
if ( V_602 == 0 || V_602 == F_442 ( V_7 ) )
V_608 = true ;
F_50 ( & V_92 -> V_354 ) ;
F_235 (block_group, &space_info->block_groups[index],
list) {
T_2 V_33 ;
int V_3 ;
F_446 ( V_14 , V_551 ) ;
V_543 = V_14 -> V_21 . V_22 ;
if ( ! F_3 ( V_14 , V_7 ) ) {
T_2 V_612 = V_345 |
V_346 |
V_394 |
V_393 |
V_347 ;
if ( ( V_7 & V_612 ) && ! ( V_14 -> V_7 & V_612 ) )
goto V_601;
}
V_610:
V_3 = F_1 ( V_14 ) ;
if ( F_366 ( ! V_3 ) ) {
V_606 = true ;
V_29 = F_59 ( V_14 , 0 ) ;
F_32 ( V_29 < 0 ) ;
V_29 = 0 ;
}
if ( F_366 ( V_14 -> V_3 == V_5 ) )
goto V_601;
if ( F_366 ( V_14 -> V_310 ) )
goto V_601;
if ( V_600 && V_605 ) {
struct V_1 * V_613 ;
unsigned long V_614 ;
V_613 = F_447 ( V_14 ,
V_600 ,
V_551 ) ;
if ( ! V_613 )
goto V_615;
if ( V_613 != V_14 &&
( V_613 -> V_310 ||
! F_3 ( V_613 , V_7 ) ) )
goto V_616;
V_33 = F_453 ( V_613 ,
V_600 ,
V_35 ,
V_613 -> V_21 . V_22 ,
& V_358 ) ;
if ( V_33 ) {
F_13 ( & V_600 -> V_596 ) ;
F_454 ( V_34 ,
V_613 ,
V_543 , V_35 ) ;
if ( V_613 != V_14 ) {
F_449 ( V_14 ,
V_551 ) ;
V_14 = V_613 ;
}
goto V_617;
}
F_8 ( V_600 -> V_14 != V_613 ) ;
V_616:
if ( V_601 >= V_618 &&
V_613 != V_14 ) {
F_13 ( & V_600 -> V_596 ) ;
F_449 ( V_613 ,
V_551 ) ;
goto V_619;
}
F_455 ( NULL , V_600 ) ;
if ( V_613 != V_14 )
F_449 ( V_613 ,
V_551 ) ;
V_615:
if ( V_601 >= V_618 ) {
F_13 ( & V_600 -> V_596 ) ;
goto V_619;
}
V_614 = F_35 (unsigned long,
empty_cluster + empty_size,
block_group->full_stripe_len) ;
V_29 = F_456 ( V_34 , V_14 ,
V_600 , V_543 ,
V_35 ,
V_614 ) ;
if ( V_29 == 0 ) {
V_33 = F_453 ( V_14 ,
V_600 ,
V_35 ,
V_543 ,
& V_358 ) ;
if ( V_33 ) {
F_13 ( & V_600 -> V_596 ) ;
F_454 ( V_34 ,
V_14 , V_543 ,
V_35 ) ;
goto V_617;
}
} else if ( ! V_3 && V_601 > V_620
&& ! V_603 ) {
F_13 ( & V_600 -> V_596 ) ;
V_603 = true ;
F_440 ( V_14 ,
V_35 + V_553 + V_598 ) ;
goto V_610;
}
F_455 ( NULL , V_600 ) ;
F_13 ( & V_600 -> V_596 ) ;
goto V_601;
}
V_619:
if ( F_366 ( V_600 ) ) {
F_11 ( & V_600 -> V_48 ) ;
V_600 -> V_562 = 1 ;
F_13 ( & V_600 -> V_48 ) ;
}
if ( V_3 ) {
struct V_621 * V_47 =
V_14 -> V_11 ;
F_11 ( & V_47 -> V_622 ) ;
if ( V_47 -> V_584 <
V_35 + V_553 + V_598 ) {
if ( V_47 -> V_584 > V_358 )
V_358 = V_47 -> V_584 ;
F_13 ( & V_47 -> V_622 ) ;
goto V_601;
}
F_13 ( & V_47 -> V_622 ) ;
}
V_33 = F_457 ( V_14 , V_543 ,
V_35 , V_598 ,
& V_358 ) ;
if ( ! V_33 && ! V_604 && ! V_3 &&
V_601 > V_620 ) {
F_440 ( V_14 ,
V_35 + V_598 ) ;
V_604 = true ;
goto V_610;
} else if ( ! V_33 ) {
goto V_601;
}
V_617:
V_543 = F_149 ( V_33 , V_34 -> V_623 ) ;
if ( V_543 + V_35 >
V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ) {
F_31 ( V_14 , V_33 , V_35 ) ;
goto V_601;
}
if ( V_33 < V_543 )
F_31 ( V_14 , V_33 ,
V_543 - V_33 ) ;
F_32 ( V_33 > V_543 ) ;
V_29 = F_418 ( V_14 , V_550 ,
V_35 , V_551 ) ;
if ( V_29 == - V_185 ) {
F_31 ( V_14 , V_33 , V_35 ) ;
goto V_601;
}
F_414 ( V_14 ) ;
V_221 -> V_22 = V_543 ;
V_221 -> V_33 = V_35 ;
F_458 ( V_34 , V_14 ,
V_543 , V_35 ) ;
F_449 ( V_14 , V_551 ) ;
break;
V_601:
V_603 = false ;
V_604 = false ;
F_32 ( V_602 != F_443 ( V_14 ) ) ;
F_449 ( V_14 , V_551 ) ;
}
F_46 ( & V_92 -> V_354 ) ;
if ( ( V_601 == V_620 ) && V_606
&& ! V_607 )
V_607 = true ;
if ( ! V_221 -> V_22 && V_601 >= V_624 && V_606 )
goto V_611;
if ( ! V_221 -> V_22 && ++ V_602 < V_352 )
goto V_611;
if ( ! V_221 -> V_22 && V_601 < V_618 ) {
V_602 = 0 ;
if ( V_601 == V_620 ) {
if ( V_607 || ! V_608 )
V_601 = V_624 ;
else
V_601 = V_625 ;
} else {
V_601 ++ ;
}
if ( V_601 == V_625 ) {
struct V_114 * V_115 ;
int V_626 = 0 ;
V_115 = V_405 -> V_406 ;
if ( V_115 )
V_626 = 1 ;
else
V_115 = F_216 ( V_140 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
goto V_79;
}
V_29 = F_310 ( V_115 , V_34 , V_7 ,
V_409 ) ;
if ( V_29 == - V_317 )
V_601 = V_618 ;
if ( V_29 < 0 && V_29 != - V_317 )
F_162 ( V_115 , V_29 ) ;
else
V_29 = 0 ;
if ( ! V_626 )
F_220 ( V_115 ) ;
if ( V_29 )
goto V_79;
}
if ( V_601 == V_618 ) {
if ( V_598 == 0 &&
V_553 == 0 ) {
V_29 = - V_317 ;
goto V_79;
}
V_598 = 0 ;
V_553 = 0 ;
}
goto V_611;
} else if ( ! V_221 -> V_22 ) {
V_29 = - V_317 ;
} else if ( V_221 -> V_22 ) {
if ( ! V_605 && V_600 ) {
F_11 ( & V_600 -> V_48 ) ;
V_600 -> V_609 = V_221 -> V_22 ;
F_13 ( & V_600 -> V_48 ) ;
}
V_29 = 0 ;
}
V_79:
if ( V_29 == - V_317 ) {
F_11 ( & V_92 -> V_48 ) ;
V_92 -> V_358 = V_358 ;
F_13 ( & V_92 -> V_48 ) ;
V_221 -> V_33 = V_358 ;
}
return V_29 ;
}
static void F_333 ( struct V_12 * V_34 ,
struct V_108 * V_13 , T_2 V_210 ,
int V_627 )
{
struct V_1 * V_2 ;
int V_602 = 0 ;
F_11 ( & V_13 -> V_48 ) ;
F_332 ( V_34 , L_24 ,
V_13 -> V_7 ,
V_13 -> V_342 - F_307 ( V_13 , true ) ,
V_13 -> V_113 ? L_25 : L_26 ) ;
F_332 ( V_34 ,
L_27 ,
V_13 -> V_342 , V_13 -> V_91 , V_13 -> V_355 ,
V_13 -> V_356 , V_13 -> V_357 ,
V_13 -> V_343 ) ;
F_13 ( & V_13 -> V_48 ) ;
if ( ! V_627 )
return;
F_50 ( & V_13 -> V_354 ) ;
V_162:
F_235 (cache, &info->block_groups[index], list) {
F_11 ( & V_2 -> V_48 ) ;
F_332 ( V_34 ,
L_28 ,
V_2 -> V_21 . V_22 , V_2 -> V_21 . V_33 ,
F_58 ( & V_2 -> V_93 ) , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_310 ? L_29 : L_25 ) ;
F_459 ( V_2 , V_210 ) ;
F_13 ( & V_2 -> V_48 ) ;
}
if ( ++ V_602 < V_352 )
goto V_162;
F_46 ( & V_13 -> V_354 ) ;
}
int F_460 ( struct V_61 * V_140 , T_2 V_550 ,
T_2 V_35 , T_2 V_628 ,
T_2 V_598 , T_2 V_599 ,
struct V_67 * V_221 , int V_191 , int V_551 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
bool V_629 = V_35 == V_628 ;
T_2 V_7 ;
int V_29 ;
V_7 = F_306 ( V_140 , V_191 ) ;
V_162:
F_8 ( V_35 < V_34 -> V_53 ) ;
V_29 = F_450 ( V_34 , V_550 , V_35 , V_598 ,
V_599 , V_221 , V_7 , V_551 ) ;
if ( ! V_29 && ! V_191 ) {
F_415 ( V_34 , V_221 -> V_22 ) ;
} else if ( V_29 == - V_317 ) {
if ( ! V_629 && V_221 -> V_33 ) {
V_35 = F_345 ( V_35 >> 1 , V_221 -> V_33 ) ;
V_35 = F_150 ( V_35 ,
V_34 -> V_53 ) ;
V_35 = F_452 ( V_35 , V_628 ) ;
V_550 = V_35 ;
if ( V_35 == V_628 )
V_629 = true ;
goto V_162;
} else if ( F_265 ( V_34 , V_427 ) ) {
struct V_108 * V_416 ;
V_416 = F_77 ( V_34 , V_7 ) ;
F_173 ( V_34 ,
L_30 ,
V_7 , V_35 ) ;
if ( V_416 )
F_333 ( V_34 , V_416 , V_35 , 1 ) ;
}
}
return V_29 ;
}
static int F_461 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_45 ,
int V_579 , int V_551 )
{
struct V_1 * V_2 ;
int V_29 = 0 ;
V_2 = F_76 ( V_34 , V_32 ) ;
if ( ! V_2 ) {
F_173 ( V_34 , L_31 ,
V_32 ) ;
return - V_317 ;
}
if ( V_579 )
F_410 ( V_34 , V_2 , V_32 , V_45 , 1 ) ;
else {
if ( F_265 ( V_34 , V_568 ) )
V_29 = F_153 ( V_34 , V_32 , V_45 , NULL ) ;
F_31 ( V_2 , V_32 , V_45 ) ;
F_419 ( V_2 , V_45 , V_551 ) ;
F_438 ( V_34 , V_32 , V_45 ) ;
}
F_6 ( V_2 ) ;
return V_29 ;
}
int F_462 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_45 , int V_551 )
{
return F_461 ( V_34 , V_32 , V_45 , 0 , V_551 ) ;
}
int F_463 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_45 )
{
return F_461 ( V_34 , V_32 , V_45 , 1 , 0 ) ;
}
static int F_166 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_7 , T_2 V_138 , T_2 V_33 ,
struct V_67 * V_221 , int V_137 )
{
int V_29 ;
struct V_121 * V_630 ;
struct V_170 * V_171 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int type ;
T_3 V_57 ;
if ( V_17 > 0 )
type = V_160 ;
else
type = V_161 ;
V_57 = sizeof( * V_630 ) + F_133 ( type ) ;
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
V_630 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_121 ) ;
F_98 ( V_66 , V_630 , V_137 ) ;
F_99 ( V_66 , V_630 , V_115 -> V_273 ) ;
F_100 ( V_66 , V_630 ,
V_7 | V_150 ) ;
V_171 = (struct V_170 * ) ( V_630 + 1 ) ;
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
F_118 ( V_66 , V_156 , V_138 ) ;
F_119 ( V_66 , V_156 , V_33 ) ;
F_120 ( V_66 , V_156 , V_137 ) ;
}
F_103 ( V_64 -> V_80 [ 0 ] ) ;
F_53 ( V_64 ) ;
V_29 = F_464 ( V_115 , V_34 , V_221 -> V_22 ,
V_221 -> V_33 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_405 ( V_115 , V_34 , V_221 -> V_22 , V_221 -> V_33 , 1 ) ;
if ( V_29 ) {
F_173 ( V_34 , L_32 ,
V_221 -> V_22 , V_221 -> V_33 ) ;
F_91 () ;
}
F_465 ( V_34 , V_221 -> V_22 , V_221 -> V_33 ) ;
return V_29 ;
}
static int F_174 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_17 , T_2 V_151 ,
T_2 V_7 , struct V_631 * V_21 ,
int V_174 , struct V_67 * V_221 )
{
int V_29 ;
struct V_121 * V_630 ;
struct V_143 * V_632 ;
struct V_170 * V_171 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_3 V_57 = sizeof( * V_630 ) + sizeof( * V_171 ) ;
T_2 V_35 = V_221 -> V_33 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
if ( ! V_180 )
V_57 += sizeof( * V_632 ) ;
V_64 = F_34 () ;
if ( ! V_64 ) {
F_463 ( V_34 , V_221 -> V_22 ,
V_34 -> V_52 ) ;
return - V_72 ;
}
V_64 -> V_218 = 1 ;
V_29 = F_114 ( V_115 , V_34 -> V_62 , V_64 ,
V_221 , V_57 ) ;
if ( V_29 ) {
F_53 ( V_64 ) ;
F_463 ( V_34 , V_221 -> V_22 ,
V_34 -> V_52 ) ;
return V_29 ;
}
V_66 = V_64 -> V_80 [ 0 ] ;
V_630 = F_86 ( V_66 , V_64 -> V_81 [ 0 ] ,
struct V_121 ) ;
F_98 ( V_66 , V_630 , 1 ) ;
F_99 ( V_66 , V_630 , V_115 -> V_273 ) ;
F_100 ( V_66 , V_630 ,
V_7 | V_149 ) ;
if ( V_180 ) {
V_171 = (struct V_170 * ) ( V_630 + 1 ) ;
V_35 = V_34 -> V_52 ;
} else {
V_632 = (struct V_143 * ) ( V_630 + 1 ) ;
F_168 ( V_66 , V_632 , V_21 ) ;
F_102 ( V_66 , V_632 , V_174 ) ;
V_171 = (struct V_170 * ) ( V_632 + 1 ) ;
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
V_29 = F_464 ( V_115 , V_34 , V_221 -> V_22 ,
V_35 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_405 ( V_115 , V_34 , V_221 -> V_22 ,
V_34 -> V_52 , 1 ) ;
if ( V_29 ) {
F_173 ( V_34 , L_32 ,
V_221 -> V_22 , V_221 -> V_33 ) ;
F_91 () ;
}
F_465 ( V_34 , V_221 -> V_22 ,
V_34 -> V_52 ) ;
return V_29 ;
}
int F_466 ( struct V_114 * V_115 ,
T_2 V_151 , T_2 V_138 ,
T_2 V_33 , T_2 V_550 ,
struct V_67 * V_221 )
{
struct V_12 * V_34 = V_115 -> V_34 ;
int V_29 ;
F_32 ( V_151 == V_215 ) ;
V_29 = F_160 ( V_34 , V_115 , V_221 -> V_22 ,
V_221 -> V_33 , 0 ,
V_151 , V_138 , V_33 ,
V_550 , V_244 ) ;
return V_29 ;
}
int F_467 ( struct V_114 * V_115 ,
struct V_12 * V_34 ,
T_2 V_151 , T_2 V_138 , T_2 V_33 ,
struct V_67 * V_221 )
{
int V_29 ;
struct V_1 * V_14 ;
struct V_108 * V_92 ;
if ( ! F_84 ( V_34 , V_548 ) ) {
V_29 = F_412 ( V_34 , V_221 -> V_22 ,
V_221 -> V_33 ) ;
if ( V_29 )
return V_29 ;
}
V_14 = F_76 ( V_34 , V_221 -> V_22 ) ;
if ( ! V_14 )
return - V_544 ;
V_92 = V_14 -> V_92 ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_14 -> V_48 ) ;
V_92 -> V_356 += V_221 -> V_33 ;
V_14 -> V_10 += V_221 -> V_33 ;
F_13 ( & V_14 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
V_29 = F_166 ( V_115 , V_34 , 0 , V_151 ,
0 , V_138 , V_33 , V_221 , 1 ) ;
F_6 ( V_14 ) ;
return V_29 ;
}
static struct V_65 *
F_468 ( struct V_114 * V_115 , struct V_61 * V_140 ,
T_2 V_27 , int V_174 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_65 * V_290 ;
V_290 = F_469 ( V_34 , V_27 ) ;
if ( F_217 ( V_290 ) )
return V_290 ;
F_470 ( V_290 , V_115 -> V_273 ) ;
F_471 ( V_140 -> V_286 . V_22 , V_290 , V_174 ) ;
F_472 ( V_290 ) ;
F_473 ( V_34 , V_290 ) ;
F_439 ( V_633 , & V_290 -> V_582 ) ;
F_474 ( V_290 ) ;
F_475 ( V_290 ) ;
if ( V_140 -> V_286 . V_22 == V_215 ) {
V_290 -> V_634 = V_140 -> V_635 % 2 ;
if ( V_290 -> V_634 == 0 )
F_409 ( & V_140 -> V_636 , V_290 -> V_32 ,
V_290 -> V_32 + V_290 -> V_45 - 1 , V_95 ) ;
else
F_476 ( & V_140 -> V_636 , V_290 -> V_32 ,
V_290 -> V_32 + V_290 -> V_45 - 1 ) ;
} else {
V_290 -> V_634 = - 1 ;
F_409 ( & V_115 -> V_132 -> V_637 , V_290 -> V_32 ,
V_290 -> V_32 + V_290 -> V_45 - 1 , V_95 ) ;
}
V_115 -> V_324 = true ;
return V_290 ;
}
static struct V_261 *
F_477 ( struct V_114 * V_115 ,
struct V_61 * V_140 , T_3 V_638 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_261 * V_451 ;
struct V_261 * V_262 = & V_34 -> V_265 ;
int V_29 ;
bool V_639 = false ;
V_451 = F_368 ( V_115 , V_140 ) ;
if ( F_366 ( V_451 -> V_57 == 0 ) )
goto V_640;
V_162:
V_29 = F_367 ( V_451 , V_638 ) ;
if ( ! V_29 )
return V_451 ;
if ( V_451 -> V_641 )
return F_478 ( V_29 ) ;
if ( V_451 -> type == V_642 && ! V_639 ) {
V_639 = true ;
F_381 ( V_34 ) ;
goto V_162;
}
if ( F_265 ( V_34 , V_427 ) ) {
static F_479 ( V_643 ,
V_644 * 10 ,
1 ) ;
if ( F_480 ( & V_643 ) )
F_481 ( 1 , V_645
L_33 , V_29 ) ;
}
V_640:
V_29 = F_365 ( V_140 , V_451 , V_638 ,
V_429 ) ;
if ( ! V_29 )
return V_451 ;
if ( V_451 -> type != V_642 &&
V_451 -> V_92 == V_262 -> V_92 ) {
V_29 = F_367 ( V_262 , V_638 ) ;
if ( ! V_29 )
return V_262 ;
}
return F_478 ( V_29 ) ;
}
static void F_482 ( struct V_12 * V_34 ,
struct V_261 * V_451 , T_3 V_638 )
{
F_369 ( V_451 , V_638 , 0 ) ;
F_372 ( V_34 , V_451 , NULL , 0 ) ;
}
struct V_65 * F_483 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
T_2 V_17 , T_2 V_151 ,
const struct V_631 * V_21 ,
int V_174 , T_2 V_646 ,
T_2 V_598 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_67 V_221 ;
struct V_261 * V_451 ;
struct V_65 * V_290 ;
struct V_187 * V_134 ;
T_2 V_7 = 0 ;
int V_29 ;
T_3 V_638 = V_34 -> V_52 ;
bool V_180 = F_84 ( V_34 , V_126 ) ;
#ifdef F_484
if ( F_242 ( V_34 ) ) {
V_290 = F_468 ( V_115 , V_140 , V_140 -> V_647 ,
V_174 ) ;
if ( ! F_217 ( V_290 ) )
V_140 -> V_647 += V_638 ;
return V_290 ;
}
#endif
V_451 = F_477 ( V_115 , V_140 , V_638 ) ;
if ( F_217 ( V_451 ) )
return F_485 ( V_451 ) ;
V_29 = F_460 ( V_140 , V_638 , V_638 , V_638 ,
V_598 , V_646 , & V_221 , 0 , 0 ) ;
if ( V_29 )
goto V_648;
V_290 = F_468 ( V_115 , V_140 , V_221 . V_22 , V_174 ) ;
if ( F_217 ( V_290 ) ) {
V_29 = F_218 ( V_290 ) ;
goto V_649;
}
if ( V_151 == V_650 ) {
if ( V_17 == 0 )
V_17 = V_221 . V_22 ;
V_7 |= V_131 ;
} else
F_32 ( V_17 > 0 ) ;
if ( V_151 != V_215 ) {
V_134 = F_232 () ;
if ( ! V_134 ) {
V_29 = - V_72 ;
goto V_651;
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
goto V_652;
}
return V_290 ;
V_652:
F_192 ( V_134 ) ;
V_651:
F_486 ( V_290 ) ;
V_649:
F_462 ( V_34 , V_221 . V_22 , V_221 . V_33 , 0 ) ;
V_648:
F_482 ( V_34 , V_451 , V_638 ) ;
return F_478 ( V_29 ) ;
}
static T_1 void F_487 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_653 * V_654 ,
struct V_63 * V_64 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
T_2 V_27 ;
T_2 V_314 ;
T_2 V_117 ;
T_2 V_7 ;
T_3 V_70 ;
struct V_67 V_21 ;
struct V_65 * V_546 ;
int V_29 ;
int V_655 ;
int V_656 = 0 ;
if ( V_64 -> V_81 [ V_654 -> V_174 ] < V_654 -> V_657 ) {
V_654 -> V_658 = V_654 -> V_658 * 2 / 3 ;
V_654 -> V_658 = F_452 ( V_654 -> V_658 , 2 ) ;
} else {
V_654 -> V_658 = V_654 -> V_658 * 3 / 2 ;
V_654 -> V_658 = F_24 ( int , V_654 -> V_658 ,
F_488 ( V_34 ) ) ;
}
V_546 = V_64 -> V_80 [ V_654 -> V_174 ] ;
V_70 = F_39 ( V_546 ) ;
for ( V_655 = V_64 -> V_81 [ V_654 -> V_174 ] ; V_655 < V_70 ; V_655 ++ ) {
if ( V_656 >= V_654 -> V_658 )
break;
F_48 () ;
V_27 = F_249 ( V_546 , V_655 ) ;
V_314 = F_489 ( V_546 , V_655 ) ;
if ( V_655 == V_64 -> V_81 [ V_654 -> V_174 ] )
goto V_75;
if ( V_654 -> V_659 == V_660 &&
V_314 <= V_140 -> V_286 . V_33 )
continue;
V_29 = F_83 ( V_115 , V_34 , V_27 ,
V_654 -> V_174 - 1 , 1 , & V_117 ,
& V_7 ) ;
if ( V_29 < 0 )
continue;
F_32 ( V_117 == 0 ) ;
if ( V_654 -> V_659 == V_661 ) {
if ( V_117 == 1 )
goto V_75;
if ( V_654 -> V_174 == 1 &&
( V_7 & V_131 ) )
continue;
if ( ! V_654 -> V_662 ||
V_314 <= V_140 -> V_286 . V_33 )
continue;
F_131 ( V_546 , & V_21 , V_655 ) ;
V_29 = F_490 ( & V_21 ,
& V_654 -> V_663 ) ;
if ( V_29 < 0 )
continue;
} else {
if ( V_654 -> V_174 == 1 &&
( V_7 & V_131 ) )
continue;
}
V_75:
F_491 ( V_34 , V_27 ) ;
V_656 ++ ;
}
V_654 -> V_657 = V_655 ;
}
static T_1 int F_492 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_63 * V_64 ,
struct V_653 * V_654 , int V_664 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
int V_174 = V_654 -> V_174 ;
struct V_65 * V_546 = V_64 -> V_80 [ V_174 ] ;
T_2 V_665 = V_131 ;
int V_29 ;
if ( V_654 -> V_659 == V_660 &&
F_243 ( V_546 ) != V_140 -> V_286 . V_22 )
return 1 ;
if ( V_664 &&
( ( V_654 -> V_659 == V_661 && V_654 -> V_117 [ V_174 ] != 1 ) ||
( V_654 -> V_659 == V_660 && ! ( V_654 -> V_7 [ V_174 ] & V_665 ) ) ) ) {
F_32 ( ! V_64 -> V_666 [ V_174 ] ) ;
V_29 = F_83 ( V_115 , V_34 ,
V_546 -> V_32 , V_174 , 1 ,
& V_654 -> V_117 [ V_174 ] ,
& V_654 -> V_7 [ V_174 ] ) ;
F_32 ( V_29 == - V_72 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_654 -> V_117 [ V_174 ] == 0 ) ;
}
if ( V_654 -> V_659 == V_661 ) {
if ( V_654 -> V_117 [ V_174 ] > 1 )
return 1 ;
if ( V_64 -> V_666 [ V_174 ] && ! V_654 -> V_181 ) {
F_493 ( V_546 , V_64 -> V_666 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = 0 ;
}
return 0 ;
}
if ( ! ( V_654 -> V_7 [ V_174 ] & V_665 ) ) {
F_32 ( ! V_64 -> V_666 [ V_174 ] ) ;
V_29 = F_250 ( V_115 , V_140 , V_546 , 1 ) ;
F_32 ( V_29 ) ;
V_29 = F_251 ( V_115 , V_140 , V_546 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_231 ( V_115 , V_34 , V_546 -> V_32 ,
V_546 -> V_45 , V_665 ,
F_244 ( V_546 ) , 0 ) ;
F_32 ( V_29 ) ;
V_654 -> V_7 [ V_174 ] |= V_665 ;
}
if ( V_64 -> V_666 [ V_174 ] && V_174 > 0 ) {
F_493 ( V_546 , V_64 -> V_666 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = 0 ;
}
return 0 ;
}
static T_1 int F_494 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_63 * V_64 ,
struct V_653 * V_654 , int * V_664 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
T_2 V_27 ;
T_2 V_314 ;
T_2 V_17 ;
T_3 V_638 ;
struct V_67 V_21 ;
struct V_65 * V_78 ;
int V_174 = V_654 -> V_174 ;
int V_75 = 0 ;
int V_29 = 0 ;
bool V_667 = false ;
V_314 = F_489 ( V_64 -> V_80 [ V_174 ] ,
V_64 -> V_81 [ V_174 ] ) ;
if ( V_654 -> V_659 == V_660 &&
V_314 <= V_140 -> V_286 . V_33 ) {
* V_664 = 1 ;
return 1 ;
}
V_27 = F_249 ( V_64 -> V_80 [ V_174 ] , V_64 -> V_81 [ V_174 ] ) ;
V_638 = V_34 -> V_52 ;
V_78 = F_495 ( V_34 , V_27 ) ;
if ( ! V_78 ) {
V_78 = F_469 ( V_34 , V_27 ) ;
if ( F_217 ( V_78 ) )
return F_218 ( V_78 ) ;
F_471 ( V_140 -> V_286 . V_22 , V_78 ,
V_174 - 1 ) ;
V_75 = 1 ;
}
F_472 ( V_78 ) ;
F_474 ( V_78 ) ;
V_29 = F_83 ( V_115 , V_34 , V_27 , V_174 - 1 , 1 ,
& V_654 -> V_117 [ V_174 - 1 ] ,
& V_654 -> V_7 [ V_174 - 1 ] ) ;
if ( V_29 < 0 )
goto V_668;
if ( F_366 ( V_654 -> V_117 [ V_174 - 1 ] == 0 ) ) {
F_173 ( V_34 , L_34 ) ;
V_29 = - V_182 ;
goto V_668;
}
* V_664 = 0 ;
if ( V_654 -> V_659 == V_661 ) {
if ( V_654 -> V_117 [ V_174 - 1 ] > 1 ) {
V_667 = true ;
if ( V_174 == 1 &&
( V_654 -> V_7 [ 0 ] & V_131 ) )
goto V_669;
if ( ! V_654 -> V_662 ||
V_314 <= V_140 -> V_286 . V_33 )
goto V_669;
F_131 ( V_64 -> V_80 [ V_174 ] , & V_21 ,
V_64 -> V_81 [ V_174 ] ) ;
V_29 = F_490 ( & V_21 , & V_654 -> V_663 ) ;
if ( V_29 < 0 )
goto V_669;
V_654 -> V_659 = V_660 ;
V_654 -> V_670 = V_174 - 1 ;
}
} else {
if ( V_174 == 1 &&
( V_654 -> V_7 [ 0 ] & V_131 ) )
goto V_669;
}
if ( ! F_496 ( V_78 , V_314 , 0 ) ) {
F_497 ( V_78 ) ;
F_486 ( V_78 ) ;
V_78 = NULL ;
* V_664 = 1 ;
}
if ( ! V_78 ) {
if ( V_75 && V_174 == 1 )
F_487 ( V_115 , V_140 , V_654 , V_64 ) ;
V_78 = F_498 ( V_34 , V_27 , V_314 ) ;
if ( F_217 ( V_78 ) ) {
return F_218 ( V_78 ) ;
} else if ( ! F_499 ( V_78 ) ) {
F_486 ( V_78 ) ;
return - V_182 ;
}
F_472 ( V_78 ) ;
F_474 ( V_78 ) ;
}
V_174 -- ;
ASSERT ( V_174 == F_244 ( V_78 ) ) ;
if ( V_174 != F_244 ( V_78 ) ) {
F_173 ( V_140 -> V_34 , L_35 ) ;
V_29 = - V_182 ;
goto V_668;
}
V_64 -> V_80 [ V_174 ] = V_78 ;
V_64 -> V_81 [ V_174 ] = 0 ;
V_64 -> V_666 [ V_174 ] = V_671 ;
V_654 -> V_174 = V_174 ;
if ( V_654 -> V_174 == 1 )
V_654 -> V_657 = 0 ;
return 0 ;
V_669:
V_654 -> V_117 [ V_174 - 1 ] = 0 ;
V_654 -> V_7 [ V_174 - 1 ] = 0 ;
if ( V_654 -> V_659 == V_661 ) {
if ( V_654 -> V_7 [ V_174 ] & V_131 ) {
V_17 = V_64 -> V_80 [ V_174 ] -> V_32 ;
} else {
ASSERT ( V_140 -> V_286 . V_22 ==
F_243 ( V_64 -> V_80 [ V_174 ] ) ) ;
if ( V_140 -> V_286 . V_22 !=
F_243 ( V_64 -> V_80 [ V_174 ] ) ) {
F_173 ( V_140 -> V_34 ,
L_36 ) ;
V_29 = - V_182 ;
goto V_668;
}
V_17 = 0 ;
}
if ( V_667 ) {
V_29 = F_500 ( V_115 , V_140 , V_78 ,
V_314 , V_174 - 1 ) ;
if ( V_29 ) {
F_501 ( V_34 ,
L_37 ,
V_29 ) ;
}
}
V_29 = V_297 ( V_115 , V_34 , V_27 , V_638 ,
V_17 , V_140 -> V_286 . V_22 ,
V_174 - 1 , 0 ) ;
if ( V_29 )
goto V_668;
}
* V_664 = 1 ;
V_29 = 1 ;
V_668:
F_497 ( V_78 ) ;
F_486 ( V_78 ) ;
return V_29 ;
}
static T_1 int F_502 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_63 * V_64 ,
struct V_653 * V_654 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
int V_29 ;
int V_174 = V_654 -> V_174 ;
struct V_65 * V_546 = V_64 -> V_80 [ V_174 ] ;
T_2 V_17 = 0 ;
if ( V_654 -> V_659 == V_660 ) {
F_32 ( V_654 -> V_670 < V_174 ) ;
if ( V_174 < V_654 -> V_670 )
goto V_79;
V_29 = F_42 ( V_64 , V_174 + 1 , & V_654 -> V_663 ) ;
if ( V_29 > 0 )
V_654 -> V_662 = 0 ;
V_654 -> V_659 = V_661 ;
V_654 -> V_670 = - 1 ;
V_64 -> V_81 [ V_174 ] = 0 ;
if ( ! V_64 -> V_666 [ V_174 ] ) {
F_32 ( V_174 == 0 ) ;
F_472 ( V_546 ) ;
F_474 ( V_546 ) ;
V_64 -> V_666 [ V_174 ] = V_671 ;
V_29 = F_83 ( V_115 , V_34 ,
V_546 -> V_32 , V_174 , 1 ,
& V_654 -> V_117 [ V_174 ] ,
& V_654 -> V_7 [ V_174 ] ) ;
if ( V_29 < 0 ) {
F_493 ( V_546 , V_64 -> V_666 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = 0 ;
return V_29 ;
}
F_32 ( V_654 -> V_117 [ V_174 ] == 0 ) ;
if ( V_654 -> V_117 [ V_174 ] == 1 ) {
F_493 ( V_546 , V_64 -> V_666 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = 0 ;
return 1 ;
}
}
}
F_32 ( V_654 -> V_117 [ V_174 ] > 1 && ! V_64 -> V_666 [ V_174 ] ) ;
if ( V_654 -> V_117 [ V_174 ] == 1 ) {
if ( V_174 == 0 ) {
if ( V_654 -> V_7 [ V_174 ] & V_131 )
V_29 = F_251 ( V_115 , V_140 , V_546 , 1 ) ;
else
V_29 = F_251 ( V_115 , V_140 , V_546 , 0 ) ;
F_32 ( V_29 ) ;
V_29 = F_503 ( V_115 , V_34 , V_546 ) ;
if ( V_29 ) {
F_501 ( V_34 ,
L_38 ,
V_29 ) ;
}
}
if ( ! V_64 -> V_666 [ V_174 ] &&
F_436 ( V_546 ) == V_115 -> V_273 ) {
F_472 ( V_546 ) ;
F_474 ( V_546 ) ;
V_64 -> V_666 [ V_174 ] = V_671 ;
}
F_473 ( V_34 , V_546 ) ;
}
if ( V_546 == V_140 -> V_133 ) {
if ( V_654 -> V_7 [ V_174 ] & V_131 )
V_17 = V_546 -> V_32 ;
else
F_32 ( V_140 -> V_286 . V_22 !=
F_243 ( V_546 ) ) ;
} else {
if ( V_654 -> V_7 [ V_174 + 1 ] & V_131 )
V_17 = V_64 -> V_80 [ V_174 + 1 ] -> V_32 ;
else
F_32 ( V_140 -> V_286 . V_22 !=
F_243 ( V_64 -> V_80 [ V_174 + 1 ] ) ) ;
}
F_435 ( V_115 , V_140 , V_546 , V_17 , V_654 -> V_117 [ V_174 ] == 1 ) ;
V_79:
V_654 -> V_117 [ V_174 ] = 0 ;
V_654 -> V_7 [ V_174 ] = 0 ;
return 0 ;
}
static T_1 int F_504 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_63 * V_64 ,
struct V_653 * V_654 )
{
int V_174 = V_654 -> V_174 ;
int V_664 = 1 ;
int V_29 ;
while ( V_174 >= 0 ) {
V_29 = F_492 ( V_115 , V_140 , V_64 , V_654 , V_664 ) ;
if ( V_29 > 0 )
break;
if ( V_174 == 0 )
break;
if ( V_64 -> V_81 [ V_174 ] >=
F_39 ( V_64 -> V_80 [ V_174 ] ) )
break;
V_29 = F_494 ( V_115 , V_140 , V_64 , V_654 , & V_664 ) ;
if ( V_29 > 0 ) {
V_64 -> V_81 [ V_174 ] ++ ;
continue;
} else if ( V_29 < 0 )
return V_29 ;
V_174 = V_654 -> V_174 ;
}
return 0 ;
}
static T_1 int F_505 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_63 * V_64 ,
struct V_653 * V_654 , int V_672 )
{
int V_174 = V_654 -> V_174 ;
int V_29 ;
V_64 -> V_81 [ V_174 ] = F_39 ( V_64 -> V_80 [ V_174 ] ) ;
while ( V_174 < V_672 && V_64 -> V_80 [ V_174 ] ) {
V_654 -> V_174 = V_174 ;
if ( V_64 -> V_81 [ V_174 ] + 1 <
F_39 ( V_64 -> V_80 [ V_174 ] ) ) {
V_64 -> V_81 [ V_174 ] ++ ;
return 0 ;
} else {
V_29 = F_502 ( V_115 , V_140 , V_64 , V_654 ) ;
if ( V_29 > 0 )
return 0 ;
if ( V_64 -> V_666 [ V_174 ] ) {
F_493 ( V_64 -> V_80 [ V_174 ] ,
V_64 -> V_666 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = 0 ;
}
F_486 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_80 [ V_174 ] = NULL ;
V_174 ++ ;
}
}
return 1 ;
}
int F_506 ( struct V_61 * V_140 ,
struct V_261 * V_451 , int V_662 ,
int V_673 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_63 * V_64 ;
struct V_114 * V_115 ;
struct V_61 * V_274 = V_34 -> V_274 ;
struct V_674 * V_287 = & V_140 -> V_287 ;
struct V_653 * V_654 ;
struct V_67 V_21 ;
int V_158 = 0 ;
int V_29 ;
int V_174 ;
bool V_675 = false ;
F_193 ( V_34 , L_39 , V_140 -> V_22 ) ;
V_64 = F_34 () ;
if ( ! V_64 ) {
V_158 = - V_72 ;
goto V_79;
}
V_654 = F_61 ( sizeof( * V_654 ) , V_95 ) ;
if ( ! V_654 ) {
F_53 ( V_64 ) ;
V_158 = - V_72 ;
goto V_79;
}
V_115 = F_507 ( V_274 , 0 ) ;
if ( F_217 ( V_115 ) ) {
V_158 = F_218 ( V_115 ) ;
goto V_128;
}
if ( V_451 )
V_115 -> V_451 = V_451 ;
if ( F_508 ( & V_287 -> V_676 ) == 0 ) {
V_174 = F_244 ( V_140 -> V_133 ) ;
V_64 -> V_80 [ V_174 ] = F_509 ( V_140 ) ;
F_474 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_81 [ V_174 ] = 0 ;
V_64 -> V_666 [ V_174 ] = V_671 ;
memset ( & V_654 -> V_663 , 0 ,
sizeof( V_654 -> V_663 ) ) ;
} else {
F_510 ( & V_21 , & V_287 -> V_676 ) ;
memcpy ( & V_654 -> V_663 , & V_21 ,
sizeof( V_654 -> V_663 ) ) ;
V_174 = V_287 -> V_677 ;
F_32 ( V_174 == 0 ) ;
V_64 -> V_678 = V_174 ;
V_29 = F_38 ( NULL , V_140 , & V_21 , V_64 , 0 , 0 ) ;
V_64 -> V_678 = 0 ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_679;
}
F_8 ( V_29 > 0 ) ;
F_136 ( V_64 , 0 ) ;
V_174 = F_244 ( V_140 -> V_133 ) ;
while ( 1 ) {
F_472 ( V_64 -> V_80 [ V_174 ] ) ;
F_474 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = V_671 ;
V_29 = F_83 ( V_115 , V_34 ,
V_64 -> V_80 [ V_174 ] -> V_32 ,
V_174 , 1 , & V_654 -> V_117 [ V_174 ] ,
& V_654 -> V_7 [ V_174 ] ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
goto V_679;
}
F_32 ( V_654 -> V_117 [ V_174 ] == 0 ) ;
if ( V_174 == V_287 -> V_677 )
break;
F_497 ( V_64 -> V_80 [ V_174 ] ) ;
V_64 -> V_666 [ V_174 ] = 0 ;
F_8 ( V_654 -> V_117 [ V_174 ] != 1 ) ;
V_174 -- ;
}
}
V_654 -> V_174 = V_174 ;
V_654 -> V_670 = - 1 ;
V_654 -> V_659 = V_661 ;
V_654 -> V_662 = V_662 ;
V_654 -> V_181 = 0 ;
V_654 -> V_673 = V_673 ;
V_654 -> V_658 = F_488 ( V_34 ) ;
while ( 1 ) {
V_29 = F_504 ( V_115 , V_140 , V_64 , V_654 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
break;
}
V_29 = F_505 ( V_115 , V_140 , V_64 , V_654 , V_175 ) ;
if ( V_29 < 0 ) {
V_158 = V_29 ;
break;
}
if ( V_29 > 0 ) {
F_32 ( V_654 -> V_659 != V_661 ) ;
break;
}
if ( V_654 -> V_659 == V_661 ) {
V_174 = V_654 -> V_174 ;
F_511 ( V_64 -> V_80 [ V_174 ] ,
& V_287 -> V_676 ,
V_64 -> V_81 [ V_174 ] ) ;
V_287 -> V_677 = V_174 ;
}
F_32 ( V_654 -> V_174 == 0 ) ;
if ( F_512 ( V_115 ) ||
( ! V_673 && F_513 ( V_34 ) ) ) {
V_29 = F_514 ( V_115 , V_274 ,
& V_140 -> V_286 ,
V_287 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
V_158 = V_29 ;
goto V_679;
}
F_515 ( V_115 ) ;
if ( ! V_673 && F_513 ( V_34 ) ) {
F_193 ( V_34 ,
L_40 ) ;
V_158 = - V_185 ;
goto V_128;
}
V_115 = F_507 ( V_274 , 0 ) ;
if ( F_217 ( V_115 ) ) {
V_158 = F_218 ( V_115 ) ;
goto V_128;
}
if ( V_451 )
V_115 -> V_451 = V_451 ;
}
}
F_45 ( V_64 ) ;
if ( V_158 )
goto V_679;
V_29 = F_516 ( V_115 , V_274 , & V_140 -> V_286 ) ;
if ( V_29 ) {
F_162 ( V_115 , V_29 ) ;
goto V_679;
}
if ( V_140 -> V_286 . V_22 != V_650 ) {
V_29 = F_517 ( V_274 , & V_140 -> V_286 , V_64 ,
NULL , NULL ) ;
if ( V_29 < 0 ) {
F_162 ( V_115 , V_29 ) ;
V_158 = V_29 ;
goto V_679;
} else if ( V_29 > 0 ) {
F_518 ( V_115 , V_274 ,
V_140 -> V_286 . V_22 ) ;
}
}
if ( F_226 ( V_680 , & V_140 -> V_296 ) ) {
F_519 ( V_115 , V_140 ) ;
} else {
F_486 ( V_140 -> V_133 ) ;
F_486 ( V_140 -> V_681 ) ;
F_520 ( V_140 ) ;
}
V_675 = true ;
V_679:
F_515 ( V_115 ) ;
V_128:
F_9 ( V_654 ) ;
F_53 ( V_64 ) ;
V_79:
if ( ! V_673 && V_675 == false )
F_521 ( V_140 ) ;
if ( V_158 && V_158 != - V_185 )
F_522 ( V_34 , V_158 , NULL ) ;
return V_158 ;
}
int F_523 ( struct V_114 * V_115 ,
struct V_61 * V_140 ,
struct V_65 * V_133 ,
struct V_65 * V_17 )
{
struct V_12 * V_34 = V_140 -> V_34 ;
struct V_63 * V_64 ;
struct V_653 * V_654 ;
int V_174 ;
int V_682 ;
int V_29 = 0 ;
int V_683 ;
F_32 ( V_140 -> V_286 . V_22 != V_650 ) ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_654 = F_61 ( sizeof( * V_654 ) , V_95 ) ;
if ( ! V_654 ) {
F_53 ( V_64 ) ;
return - V_72 ;
}
F_524 ( V_17 ) ;
V_682 = F_244 ( V_17 ) ;
F_525 ( V_17 ) ;
V_64 -> V_80 [ V_682 ] = V_17 ;
V_64 -> V_81 [ V_682 ] = F_39 ( V_17 ) ;
F_524 ( V_133 ) ;
V_174 = F_244 ( V_133 ) ;
V_64 -> V_80 [ V_174 ] = V_133 ;
V_64 -> V_81 [ V_174 ] = 0 ;
V_64 -> V_666 [ V_174 ] = V_671 ;
V_654 -> V_117 [ V_682 ] = 1 ;
V_654 -> V_7 [ V_682 ] = V_131 ;
V_654 -> V_174 = V_174 ;
V_654 -> V_670 = - 1 ;
V_654 -> V_659 = V_661 ;
V_654 -> V_662 = 0 ;
V_654 -> V_181 = 1 ;
V_654 -> V_673 = 1 ;
V_654 -> V_658 = F_488 ( V_34 ) ;
while ( 1 ) {
V_683 = F_504 ( V_115 , V_140 , V_64 , V_654 ) ;
if ( V_683 < 0 ) {
V_29 = V_683 ;
break;
}
V_683 = F_505 ( V_115 , V_140 , V_64 , V_654 , V_682 ) ;
if ( V_683 < 0 )
V_29 = V_683 ;
if ( V_683 != 0 )
break;
}
F_9 ( V_654 ) ;
F_53 ( V_64 ) ;
return V_29 ;
}
static T_2 F_526 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_384 ;
T_2 V_684 ;
V_684 = F_300 ( V_34 , V_7 ) ;
if ( V_684 )
return F_302 ( V_684 ) ;
V_384 = V_34 -> V_385 -> V_386 ;
V_684 = V_395 |
V_394 | V_393 |
V_346 | V_347 ;
if ( V_384 == 1 ) {
V_684 |= V_345 ;
V_684 = V_7 & ~ V_684 ;
if ( V_7 & V_395 )
return V_684 ;
if ( V_7 & ( V_346 |
V_347 ) )
return V_684 | V_345 ;
} else {
if ( V_7 & V_684 )
return V_7 ;
V_684 |= V_345 ;
V_684 = V_7 & ~ V_684 ;
if ( V_7 & V_345 )
return V_684 | V_346 ;
}
return V_7 ;
}
static int F_527 ( struct V_1 * V_2 , int V_417 )
{
struct V_108 * V_416 = V_2 -> V_92 ;
T_2 V_35 ;
T_2 V_685 ;
int V_29 = - V_317 ;
if ( ( V_416 -> V_7 &
( V_341 | V_51 ) ) &&
! V_417 )
V_685 = V_307 ;
else
V_685 = 0 ;
F_11 ( & V_416 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_310 ) {
V_2 -> V_310 ++ ;
V_29 = 0 ;
goto V_79;
}
V_35 = V_2 -> V_21 . V_33 - V_2 -> V_10 - V_2 -> V_9 -
V_2 -> V_43 - F_58 ( & V_2 -> V_93 ) ;
if ( F_307 ( V_416 , true ) + V_35 +
V_685 <= V_416 -> V_342 ) {
V_416 -> V_343 += V_35 ;
V_2 -> V_310 ++ ;
F_72 ( & V_2 -> V_686 , & V_416 -> V_363 ) ;
V_29 = 0 ;
}
V_79:
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_416 -> V_48 ) ;
return V_29 ;
}
int F_528 ( struct V_12 * V_34 ,
struct V_1 * V_2 )
{
struct V_114 * V_115 ;
T_2 V_687 ;
int V_29 ;
V_162:
V_115 = F_216 ( V_34 -> V_62 ) ;
if ( F_217 ( V_115 ) )
return F_218 ( V_115 ) ;
F_49 ( & V_34 -> V_688 ) ;
if ( F_226 ( V_689 , & V_115 -> V_132 -> V_7 ) ) {
T_2 V_273 = V_115 -> V_273 ;
F_47 ( & V_34 -> V_688 ) ;
F_220 ( V_115 ) ;
V_29 = F_529 ( V_34 , V_273 ) ;
if ( V_29 )
return V_29 ;
goto V_162;
}
V_687 = F_526 ( V_34 , V_2 -> V_7 ) ;
if ( V_687 != V_2 -> V_7 ) {
V_29 = F_310 ( V_115 , V_34 , V_687 ,
V_409 ) ;
if ( V_29 == - V_317 )
V_29 = 0 ;
if ( V_29 < 0 )
goto V_79;
}
V_29 = F_527 ( V_2 , 0 ) ;
if ( ! V_29 )
goto V_79;
V_687 = F_303 ( V_34 , V_2 -> V_92 -> V_7 ) ;
V_29 = F_310 ( V_115 , V_34 , V_687 ,
V_409 ) ;
if ( V_29 < 0 )
goto V_79;
V_29 = F_527 ( V_2 , 0 ) ;
V_79:
if ( V_2 -> V_7 & V_341 ) {
V_687 = F_526 ( V_34 , V_2 -> V_7 ) ;
F_49 ( & V_34 -> V_426 ) ;
F_329 ( V_115 , V_34 , V_687 ) ;
F_47 ( & V_34 -> V_426 ) ;
}
F_47 ( & V_34 -> V_688 ) ;
F_220 ( V_115 ) ;
return V_29 ;
}
int F_530 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 type )
{
T_2 V_687 = F_303 ( V_34 , type ) ;
return F_310 ( V_115 , V_34 , V_687 , V_409 ) ;
}
T_2 F_531 ( struct V_108 * V_416 )
{
struct V_1 * V_14 ;
T_2 V_690 = 0 ;
int V_344 ;
if ( F_183 ( & V_416 -> V_363 ) )
return 0 ;
F_11 ( & V_416 -> V_48 ) ;
F_235 (block_group, &sinfo->ro_bgs, ro_list) {
F_11 ( & V_14 -> V_48 ) ;
if ( ! V_14 -> V_310 ) {
F_13 ( & V_14 -> V_48 ) ;
continue;
}
if ( V_14 -> V_7 & ( V_346 |
V_347 |
V_345 ) )
V_344 = 2 ;
else
V_344 = 1 ;
V_690 += ( V_14 -> V_21 . V_33 -
F_58 ( & V_14 -> V_93 ) ) *
V_344 ;
F_13 ( & V_14 -> V_48 ) ;
}
F_13 ( & V_416 -> V_48 ) ;
return V_690 ;
}
void F_532 ( struct V_1 * V_2 )
{
struct V_108 * V_416 = V_2 -> V_92 ;
T_2 V_35 ;
F_32 ( ! V_2 -> V_310 ) ;
F_11 ( & V_416 -> V_48 ) ;
F_11 ( & V_2 -> V_48 ) ;
if ( ! -- V_2 -> V_310 ) {
V_35 = V_2 -> V_21 . V_33 - V_2 -> V_10 -
V_2 -> V_9 - V_2 -> V_43 -
F_58 ( & V_2 -> V_93 ) ;
V_416 -> V_343 -= V_35 ;
F_275 ( & V_2 -> V_686 ) ;
}
F_13 ( & V_2 -> V_48 ) ;
F_13 ( & V_416 -> V_48 ) ;
}
int F_533 ( struct V_12 * V_34 , T_2 V_27 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
struct V_1 * V_14 ;
struct V_108 * V_92 ;
struct V_691 * V_385 = V_34 -> V_385 ;
struct V_692 * V_693 ;
struct V_114 * V_115 ;
T_2 V_694 ;
T_2 V_695 = 1 ;
T_2 V_696 = 0 ;
T_2 V_379 ;
int V_697 ;
int V_602 ;
int V_113 = 0 ;
int V_29 = 0 ;
V_697 = F_265 ( V_34 , V_427 ) ;
V_14 = F_76 ( V_34 , V_27 ) ;
if ( ! V_14 ) {
if ( V_697 )
F_428 ( V_34 ,
L_41 ,
V_27 ) ;
return - 1 ;
}
V_694 = F_58 ( & V_14 -> V_93 ) ;
if ( ! V_694 )
goto V_79;
V_92 = V_14 -> V_92 ;
F_11 ( & V_92 -> V_48 ) ;
V_113 = V_92 -> V_113 ;
if ( ( V_92 -> V_342 != V_14 -> V_21 . V_33 ) &&
( F_307 ( V_92 , false ) + V_694 <
V_92 -> V_342 ) ) {
F_13 ( & V_92 -> V_48 ) ;
goto V_79;
}
F_13 ( & V_92 -> V_48 ) ;
V_29 = - 1 ;
V_379 = F_300 ( V_34 , V_14 -> V_7 ) ;
if ( V_379 ) {
V_602 = F_442 ( F_302 ( V_379 ) ) ;
} else {
if ( V_113 ) {
if ( V_697 )
F_428 ( V_34 ,
L_42 ,
V_14 -> V_21 . V_22 ) ;
goto V_79;
}
V_602 = F_443 ( V_14 ) ;
}
if ( V_602 == V_585 ) {
V_695 = 4 ;
V_694 >>= 1 ;
} else if ( V_602 == V_586 ) {
V_695 = 2 ;
} else if ( V_602 == V_587 ) {
V_694 <<= 1 ;
} else if ( V_602 == V_588 ) {
V_695 = V_385 -> V_386 ;
V_694 = F_207 ( V_694 , V_695 ) ;
}
V_115 = F_216 ( V_140 ) ;
if ( F_217 ( V_115 ) ) {
V_29 = F_218 ( V_115 ) ;
goto V_79;
}
F_49 ( & V_34 -> V_426 ) ;
F_235 (device, &fs_devices->alloc_list, dev_alloc_list) {
T_2 V_698 ;
if ( V_693 -> V_342 > V_693 -> V_91 + V_694 &&
! V_693 -> V_699 ) {
V_29 = F_534 ( V_115 , V_693 , V_694 ,
& V_698 , NULL ) ;
if ( ! V_29 )
V_696 ++ ;
if ( V_696 >= V_695 )
break;
V_29 = - 1 ;
}
}
if ( V_697 && V_29 == - 1 )
F_428 ( V_34 ,
L_43 ,
V_14 -> V_21 . V_22 ) ;
F_47 ( & V_34 -> V_426 ) ;
F_220 ( V_115 ) ;
V_79:
F_6 ( V_14 ) ;
return V_29 ;
}
static int F_535 ( struct V_12 * V_34 ,
struct V_63 * V_64 ,
struct V_67 * V_21 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
int V_29 = 0 ;
struct V_67 V_145 ;
struct V_65 * V_66 ;
int V_655 ;
V_29 = F_38 ( NULL , V_140 , V_21 , V_64 , 0 , 0 ) ;
if ( V_29 < 0 )
goto V_79;
while ( 1 ) {
V_655 = V_64 -> V_81 [ 0 ] ;
V_66 = V_64 -> V_80 [ 0 ] ;
if ( V_655 >= F_39 ( V_66 ) ) {
V_29 = F_51 ( V_140 , V_64 ) ;
if ( V_29 == 0 )
continue;
if ( V_29 < 0 )
goto V_79;
break;
}
F_41 ( V_66 , & V_145 , V_655 ) ;
if ( V_145 . V_22 >= V_21 -> V_22 &&
V_145 . type == V_186 ) {
struct V_700 * V_701 ;
struct V_702 * V_703 ;
V_701 = & V_140 -> V_34 -> V_704 . V_705 ;
F_536 ( & V_701 -> V_48 ) ;
V_703 = F_537 ( V_701 , V_145 . V_22 ,
V_145 . V_33 ) ;
F_538 ( & V_701 -> V_48 ) ;
if ( ! V_703 ) {
F_173 ( V_34 ,
L_44 ,
V_145 . V_22 , V_145 . V_33 ) ;
V_29 = - V_159 ;
} else {
V_29 = 0 ;
}
F_539 ( V_703 ) ;
goto V_79;
}
V_64 -> V_81 [ 0 ] ++ ;
}
V_79:
return V_29 ;
}
void F_540 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
T_2 V_69 = 0 ;
while ( 1 ) {
struct V_301 * V_301 ;
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
V_301 = V_14 -> V_301 ;
V_14 -> V_171 = 0 ;
V_14 -> V_301 = NULL ;
F_13 ( & V_14 -> V_48 ) ;
ASSERT ( V_14 -> V_333 . V_301 == NULL ) ;
F_269 ( V_301 ) ;
V_69 = V_14 -> V_21 . V_22 + V_14 -> V_21 . V_33 ;
F_6 ( V_14 ) ;
}
}
int F_541 ( struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_108 * V_92 ;
struct V_46 * V_49 ;
struct V_15 * V_30 ;
F_71 ( & V_13 -> V_82 ) ;
while ( ! F_183 ( & V_13 -> V_106 ) ) {
V_49 = F_542 ( V_13 -> V_106 . V_78 ,
struct V_46 , V_96 ) ;
F_195 ( & V_49 -> V_96 ) ;
F_26 ( V_49 ) ;
}
F_73 ( & V_13 -> V_82 ) ;
F_11 ( & V_13 -> V_540 ) ;
while ( ! F_183 ( & V_13 -> V_542 ) ) {
V_14 = F_184 ( & V_13 -> V_542 ,
struct V_1 ,
V_541 ) ;
F_275 ( & V_14 -> V_541 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_13 -> V_540 ) ;
F_11 ( & V_13 -> V_18 ) ;
while ( ( V_30 = F_201 ( & V_13 -> V_19 ) ) != NULL ) {
V_14 = F_12 ( V_30 , struct V_1 ,
V_20 ) ;
F_194 ( & V_14 -> V_20 ,
& V_13 -> V_19 ) ;
F_543 ( & V_14 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_71 ( & V_14 -> V_92 -> V_354 ) ;
F_195 ( & V_14 -> V_96 ) ;
F_73 ( & V_14 -> V_92 -> V_354 ) ;
if ( V_14 -> V_3 == V_100 ||
V_14 -> V_3 == V_5 )
F_19 ( V_13 , V_14 ) ;
F_544 ( V_14 ) ;
ASSERT ( V_14 -> V_3 != V_104 ) ;
ASSERT ( F_183 ( & V_14 -> V_331 ) ) ;
ASSERT ( F_183 ( & V_14 -> V_332 ) ) ;
ASSERT ( F_183 ( & V_14 -> V_541 ) ) ;
ASSERT ( F_212 ( & V_14 -> V_8 ) == 1 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
F_13 ( & V_13 -> V_18 ) ;
F_545 () ;
F_384 ( V_13 ) ;
while ( ! F_183 ( & V_13 -> V_92 ) ) {
int V_40 ;
V_92 = F_542 ( V_13 -> V_92 . V_78 ,
struct V_108 ,
V_96 ) ;
if ( F_8 ( V_92 -> V_355 > 0 ||
V_92 -> V_356 > 0 ||
V_92 -> V_357 > 0 ) )
F_333 ( V_13 , V_92 , 0 , 0 ) ;
F_195 ( & V_92 -> V_96 ) ;
for ( V_40 = 0 ; V_40 < V_352 ; V_40 ++ ) {
struct V_706 * V_366 ;
V_366 = V_92 -> V_707 [ V_40 ] ;
V_92 -> V_707 [ V_40 ] = NULL ;
if ( V_366 ) {
F_546 ( V_366 ) ;
F_547 ( V_366 ) ;
}
}
F_546 ( & V_92 -> V_366 ) ;
F_547 ( & V_92 -> V_366 ) ;
}
return 0 ;
}
static void F_548 ( struct V_108 * V_92 ,
struct V_1 * V_2 )
{
int V_602 = F_443 ( V_2 ) ;
bool V_254 = false ;
F_71 ( & V_92 -> V_354 ) ;
if ( F_183 ( & V_92 -> V_353 [ V_602 ] ) )
V_254 = true ;
F_72 ( & V_2 -> V_96 , & V_92 -> V_353 [ V_602 ] ) ;
F_73 ( & V_92 -> V_354 ) ;
if ( V_254 ) {
struct V_708 * V_709 ;
int V_29 ;
V_709 = F_61 ( sizeof( * V_709 ) , V_95 ) ;
if ( ! V_709 )
goto V_710;
V_709 -> V_387 = V_602 ;
F_549 ( & V_709 -> V_366 , & V_711 ) ;
V_29 = F_550 ( & V_709 -> V_366 , & V_92 -> V_366 ,
L_9 , F_444 ( V_602 ) ) ;
if ( V_29 ) {
F_547 ( & V_709 -> V_366 ) ;
goto V_710;
}
V_92 -> V_707 [ V_602 ] = & V_709 -> V_366 ;
}
return;
V_710:
F_428 ( V_2 -> V_34 ,
L_45 ) ;
}
static struct V_1 *
F_551 ( struct V_12 * V_34 ,
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
V_2 -> V_712 = F_552 ( V_34 ,
& V_34 -> V_704 ,
V_32 ) ;
F_553 ( V_2 ) ;
F_65 ( & V_2 -> V_8 , 1 ) ;
F_293 ( & V_2 -> V_48 ) ;
F_292 ( & V_2 -> V_594 ) ;
F_62 ( & V_2 -> V_96 ) ;
F_62 ( & V_2 -> V_713 ) ;
F_62 ( & V_2 -> V_541 ) ;
F_62 ( & V_2 -> V_686 ) ;
F_62 ( & V_2 -> V_331 ) ;
F_62 ( & V_2 -> V_332 ) ;
F_554 ( V_2 ) ;
F_65 ( & V_2 -> V_714 , 0 ) ;
F_63 ( & V_2 -> V_715 ) ;
return V_2 ;
}
int F_555 ( struct V_12 * V_13 )
{
struct V_63 * V_64 ;
int V_29 ;
struct V_1 * V_2 ;
struct V_108 * V_92 ;
struct V_67 V_21 ;
struct V_67 V_145 ;
struct V_65 * V_66 ;
int V_716 = 0 ;
T_2 V_717 ;
T_2 V_718 ;
int V_719 ;
V_718 = F_556 ( V_13 -> V_260 ) ;
V_719 = ! ! ( V_718 & V_720 ) ;
V_21 . V_22 = 0 ;
V_21 . V_33 = 0 ;
V_21 . type = V_186 ;
V_64 = F_34 () ;
if ( ! V_64 )
return - V_72 ;
V_64 -> V_75 = V_76 ;
V_717 = F_557 ( V_13 -> V_260 ) ;
if ( F_265 ( V_13 , V_315 ) &&
F_558 ( V_13 -> V_260 ) != V_717 )
V_716 = 1 ;
if ( F_265 ( V_13 , V_721 ) )
V_716 = 1 ;
while ( 1 ) {
V_29 = F_535 ( V_13 , V_64 , & V_21 ) ;
if ( V_29 > 0 )
break;
if ( V_29 != 0 )
goto error;
V_66 = V_64 -> V_80 [ 0 ] ;
F_41 ( V_66 , & V_145 , V_64 -> V_81 [ 0 ] ) ;
V_2 = F_551 ( V_13 , V_145 . V_22 ,
V_145 . V_33 ) ;
if ( ! V_2 ) {
V_29 = - V_72 ;
goto error;
}
if ( V_716 ) {
if ( F_265 ( V_13 , V_315 ) )
V_2 -> V_308 = V_322 ;
}
F_559 ( V_66 , & V_2 -> V_93 ,
F_253 ( V_66 , V_64 -> V_81 [ 0 ] ) ,
sizeof( V_2 -> V_93 ) ) ;
V_2 -> V_7 = F_560 ( & V_2 -> V_93 ) ;
if ( ! V_719 &&
( ( V_2 -> V_7 & V_51 ) &&
( V_2 -> V_7 & V_340 ) ) ) {
F_173 ( V_13 ,
L_46 ,
V_2 -> V_21 . V_22 ) ;
V_29 = - V_544 ;
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
F_544 ( V_2 ) ;
F_6 ( V_2 ) ;
goto error;
}
F_561 ( V_13 , V_2 , 0 ) ;
V_29 = F_289 ( V_13 , V_2 -> V_7 , V_145 . V_33 ,
F_58 ( & V_2 -> V_93 ) ,
V_2 -> V_43 , & V_92 ) ;
if ( V_29 ) {
F_544 ( V_2 ) ;
F_11 ( & V_13 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_13 -> V_19 ) ;
F_543 ( & V_2 -> V_20 ) ;
F_13 ( & V_13 -> V_18 ) ;
F_6 ( V_2 ) ;
goto error;
}
V_2 -> V_92 = V_92 ;
F_548 ( V_92 , V_2 ) ;
F_296 ( V_13 , V_2 -> V_7 ) ;
if ( F_562 ( V_13 , V_2 -> V_21 . V_22 ) ) {
F_527 ( V_2 , 1 ) ;
} else if ( F_58 ( & V_2 -> V_93 ) == 0 ) {
F_11 ( & V_13 -> V_540 ) ;
if ( F_183 ( & V_2 -> V_541 ) ) {
F_4 ( V_2 ) ;
F_72 ( & V_2 -> V_541 ,
& V_13 -> V_542 ) ;
}
F_13 ( & V_13 -> V_540 ) ;
}
}
F_79 (space_info, &info->space_info, list) {
if ( ! ( F_303 ( V_13 , V_92 -> V_7 ) &
( V_347 |
V_346 |
V_394 |
V_393 |
V_345 ) ) )
continue;
F_235 (cache,
&space_info->block_groups[BTRFS_RAID_RAID0],
list)
F_527 ( V_2 , 1 ) ;
F_235 (cache,
&space_info->block_groups[BTRFS_RAID_SINGLE],
list)
F_527 ( V_2 , 1 ) ;
}
F_383 ( V_13 ) ;
V_29 = 0 ;
error:
F_53 ( V_64 ) ;
return V_29 ;
}
void F_228 ( struct V_114 * V_115 ,
struct V_12 * V_34 )
{
struct V_1 * V_14 , * V_320 ;
struct V_61 * V_62 = V_34 -> V_62 ;
struct V_722 V_93 ;
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
V_29 = F_563 ( V_115 , V_62 , & V_21 , & V_93 ,
sizeof( V_93 ) ) ;
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
V_29 = F_564 ( V_115 , V_34 , V_21 . V_22 ,
V_21 . V_33 ) ;
if ( V_29 )
F_162 ( V_115 , V_29 ) ;
F_565 ( V_115 , V_34 , V_14 ) ;
V_78:
F_275 ( & V_14 -> V_541 ) ;
}
V_115 -> V_278 = V_278 ;
}
int F_566 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_91 ,
T_2 type , T_2 V_723 , T_2 V_724 ,
T_2 V_57 )
{
struct V_1 * V_2 ;
int V_29 ;
F_567 ( V_34 , V_115 ) ;
V_2 = F_551 ( V_34 , V_724 , V_57 ) ;
if ( ! V_2 )
return - V_72 ;
F_408 ( & V_2 -> V_93 , V_91 ) ;
F_568 ( & V_2 -> V_93 , V_723 ) ;
F_569 ( & V_2 -> V_93 , type ) ;
V_2 -> V_7 = type ;
V_2 -> V_103 = ( T_2 ) - 1 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_725 = 1 ;
V_29 = F_21 ( V_34 , V_2 ) ;
if ( V_29 ) {
F_19 ( V_34 , V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_29 ( V_2 , V_34 , V_724 , V_724 + V_57 ) ;
F_19 ( V_34 , V_2 ) ;
#ifdef F_36
if ( F_37 ( V_2 ) ) {
T_2 V_726 = V_57 - V_91 ;
V_91 += V_726 >> 1 ;
F_27 ( V_2 ) ;
}
#endif
V_29 = F_289 ( V_34 , V_2 -> V_7 , 0 , 0 , 0 ,
& V_2 -> V_92 ) ;
if ( V_29 ) {
F_544 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
V_29 = F_10 ( V_34 , V_2 ) ;
if ( V_29 ) {
F_544 ( V_2 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_561 ( V_34 , V_2 , 1 ) ;
V_29 = F_289 ( V_34 , V_2 -> V_7 , V_57 , V_91 ,
V_2 -> V_43 , & V_2 -> V_92 ) ;
if ( V_29 ) {
F_544 ( V_2 ) ;
F_11 ( & V_34 -> V_18 ) ;
F_194 ( & V_2 -> V_20 ,
& V_34 -> V_19 ) ;
F_543 ( & V_2 -> V_20 ) ;
F_13 ( & V_34 -> V_18 ) ;
F_6 ( V_2 ) ;
return V_29 ;
}
F_381 ( V_34 ) ;
F_548 ( V_2 -> V_92 , V_2 ) ;
F_72 ( & V_2 -> V_541 , & V_115 -> V_281 ) ;
F_296 ( V_34 , type ) ;
return 0 ;
}
static void F_570 ( struct V_12 * V_34 , T_2 V_7 )
{
T_2 V_370 = F_297 ( V_7 ) &
V_371 ;
F_298 ( & V_34 -> V_372 ) ;
if ( V_7 & V_340 )
V_34 -> V_373 &= ~ V_370 ;
if ( V_7 & V_51 )
V_34 -> V_374 &= ~ V_370 ;
if ( V_7 & V_341 )
V_34 -> V_375 &= ~ V_370 ;
F_299 ( & V_34 -> V_372 ) ;
}
int F_571 ( struct V_114 * V_115 ,
struct V_12 * V_34 , T_2 V_727 ,
struct V_702 * V_703 )
{
struct V_61 * V_140 = V_34 -> V_62 ;
struct V_63 * V_64 ;
struct V_1 * V_14 ;
struct V_552 * V_560 ;
struct V_61 * V_274 = V_34 -> V_274 ;
struct V_67 V_21 ;
struct V_301 * V_301 ;
struct V_706 * V_366 = NULL ;
int V_29 ;
int V_602 ;
int V_344 ;
struct V_46 * V_49 = NULL ;
bool V_728 ;
V_14 = F_76 ( V_34 , V_727 ) ;
F_32 ( ! V_14 ) ;
F_32 ( ! V_14 -> V_310 ) ;
F_19 ( V_34 , V_14 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
V_602 = F_443 ( V_14 ) ;
if ( V_14 -> V_7 & ( V_345 |
V_346 |
V_347 ) )
V_344 = 2 ;
else
V_344 = 1 ;
V_560 = & V_34 -> V_558 ;
F_11 ( & V_560 -> V_596 ) ;
F_455 ( V_14 , V_560 ) ;
F_13 ( & V_560 -> V_596 ) ;
V_560 = & V_34 -> V_556 ;
F_11 ( & V_560 -> V_596 ) ;
F_455 ( V_14 , V_560 ) ;
F_13 ( & V_560 -> V_596 ) ;
V_64 = F_34 () ;
if ( ! V_64 ) {
V_29 = - V_72 ;
goto V_79;
}
V_301 = F_258 ( V_34 , V_14 , V_64 ) ;
F_49 ( & V_115 -> V_132 -> V_330 ) ;
F_11 ( & V_115 -> V_132 -> V_329 ) ;
if ( ! F_183 ( & V_14 -> V_332 ) ) {
F_275 ( & V_14 -> V_332 ) ;
F_8 ( ! F_217 ( V_301 ) && V_301 != V_14 -> V_333 . V_301 ) ;
F_13 ( & V_115 -> V_132 -> V_329 ) ;
F_276 ( V_115 , V_14 , V_64 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_115 -> V_132 -> V_329 ) ;
}
if ( ! F_183 ( & V_14 -> V_331 ) ) {
F_275 ( & V_14 -> V_331 ) ;
F_6 ( V_14 ) ;
}
F_13 ( & V_115 -> V_132 -> V_329 ) ;
F_47 ( & V_115 -> V_132 -> V_330 ) ;
if ( ! F_217 ( V_301 ) ) {
V_29 = F_572 ( V_115 , F_261 ( V_301 ) ) ;
if ( V_29 ) {
F_573 ( V_301 ) ;
goto V_79;
}
F_574 ( V_301 ) ;
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_171 ) {
V_14 -> V_171 = 0 ;
V_14 -> V_301 = NULL ;
F_13 ( & V_14 -> V_48 ) ;
F_269 ( V_301 ) ;
} else {
F_13 ( & V_14 -> V_48 ) ;
}
F_573 ( V_301 ) ;
}
V_21 . V_22 = V_729 ;
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
F_543 ( & V_14 -> V_20 ) ;
if ( V_34 -> V_26 == V_14 -> V_21 . V_22 )
V_34 -> V_26 = ( T_2 ) - 1 ;
F_13 ( & V_34 -> V_18 ) ;
F_71 ( & V_14 -> V_92 -> V_354 ) ;
F_275 ( & V_14 -> V_96 ) ;
if ( F_183 ( & V_14 -> V_92 -> V_353 [ V_602 ] ) ) {
V_366 = V_14 -> V_92 -> V_707 [ V_602 ] ;
V_14 -> V_92 -> V_707 [ V_602 ] = NULL ;
F_570 ( V_34 , V_14 -> V_7 ) ;
}
F_73 ( & V_14 -> V_92 -> V_354 ) ;
if ( V_366 ) {
F_546 ( V_366 ) ;
F_547 ( V_366 ) ;
}
if ( V_14 -> V_105 )
V_49 = F_25 ( V_14 ) ;
if ( V_14 -> V_3 == V_104 )
F_441 ( V_14 ) ;
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
F_11 ( & V_115 -> V_132 -> V_329 ) ;
if ( ! F_183 ( & V_14 -> V_331 ) ) {
F_8 ( 1 ) ;
}
if ( ! F_183 ( & V_14 -> V_332 ) ) {
F_8 ( 1 ) ;
}
F_13 ( & V_115 -> V_132 -> V_329 ) ;
F_544 ( V_14 ) ;
F_11 ( & V_14 -> V_92 -> V_48 ) ;
F_275 ( & V_14 -> V_686 ) ;
if ( F_265 ( V_34 , V_427 ) ) {
F_8 ( V_14 -> V_92 -> V_342
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_92 -> V_343
< V_14 -> V_21 . V_33 ) ;
F_8 ( V_14 -> V_92 -> V_348
< V_14 -> V_21 . V_33 * V_344 ) ;
}
V_14 -> V_92 -> V_342 -= V_14 -> V_21 . V_33 ;
V_14 -> V_92 -> V_343 -= V_14 -> V_21 . V_33 ;
V_14 -> V_92 -> V_348 -= V_14 -> V_21 . V_33 * V_344 ;
F_13 ( & V_14 -> V_92 -> V_48 ) ;
memcpy ( & V_21 , & V_14 -> V_21 , sizeof( V_21 ) ) ;
F_49 ( & V_34 -> V_426 ) ;
if ( ! F_183 ( & V_703 -> V_96 ) ) {
F_539 ( V_703 ) ;
}
F_11 ( & V_14 -> V_48 ) ;
V_14 -> V_730 = 1 ;
V_728 = ( F_212 ( & V_14 -> V_714 ) == 0 ) ;
if ( ! V_728 ) {
F_575 ( & V_703 -> V_96 , & V_34 -> V_731 ) ;
}
F_13 ( & V_14 -> V_48 ) ;
if ( V_728 ) {
struct V_700 * V_701 ;
V_701 = & V_34 -> V_704 . V_705 ;
F_576 ( & V_701 -> V_48 ) ;
F_577 ( V_701 , V_703 ) ;
F_578 ( & V_701 -> V_48 ) ;
F_539 ( V_703 ) ;
}
F_47 ( & V_34 -> V_426 ) ;
V_29 = F_579 ( V_115 , V_34 , V_14 ) ;
if ( V_29 )
goto V_79;
F_6 ( V_14 ) ;
F_6 ( V_14 ) ;
V_29 = F_38 ( V_115 , V_140 , & V_21 , V_64 , - 1 , 1 ) ;
if ( V_29 > 0 )
V_29 = - V_182 ;
if ( V_29 < 0 )
goto V_79;
V_29 = F_124 ( V_115 , V_140 , V_64 ) ;
V_79:
F_53 ( V_64 ) ;
return V_29 ;
}
struct V_114 *
F_580 ( struct V_12 * V_34 ,
const T_2 V_724 )
{
struct V_700 * V_701 = & V_34 -> V_704 . V_705 ;
struct V_702 * V_703 ;
struct V_732 * V_733 ;
unsigned int V_734 ;
F_536 ( & V_701 -> V_48 ) ;
V_703 = F_537 ( V_701 , V_724 , 1 ) ;
F_538 ( & V_701 -> V_48 ) ;
ASSERT ( V_703 && V_703 -> V_32 == V_724 ) ;
V_733 = V_703 -> V_732 ;
V_734 = 3 + V_733 -> V_209 ;
F_539 ( V_703 ) ;
return F_581 ( V_34 -> V_62 ,
V_734 , 1 ) ;
}
void F_582 ( struct V_12 * V_34 )
{
struct V_1 * V_14 ;
struct V_108 * V_92 ;
struct V_114 * V_115 ;
int V_29 = 0 ;
if ( ! F_226 ( V_735 , & V_34 -> V_7 ) )
return;
F_11 ( & V_34 -> V_540 ) ;
while ( ! F_183 ( & V_34 -> V_542 ) ) {
T_2 V_32 , V_31 ;
int V_714 ;
V_14 = F_184 ( & V_34 -> V_542 ,
struct V_1 ,
V_541 ) ;
F_275 ( & V_14 -> V_541 ) ;
V_92 = V_14 -> V_92 ;
if ( V_29 || F_336 ( V_92 ) ) {
F_6 ( V_14 ) ;
continue;
}
F_13 ( & V_34 -> V_540 ) ;
F_49 ( & V_34 -> V_736 ) ;
F_71 ( & V_92 -> V_354 ) ;
F_11 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_10 ||
F_58 ( & V_14 -> V_93 ) ||
V_14 -> V_310 ||
F_583 ( & V_14 -> V_96 ) ) {
F_13 ( & V_14 -> V_48 ) ;
F_73 ( & V_92 -> V_354 ) ;
goto V_78;
}
F_13 ( & V_14 -> V_48 ) ;
V_29 = F_527 ( V_14 , 0 ) ;
F_73 ( & V_92 -> V_354 ) ;
if ( V_29 < 0 ) {
V_29 = 0 ;
goto V_78;
}
V_115 = F_580 ( V_34 ,
V_14 -> V_21 . V_22 ) ;
if ( F_217 ( V_115 ) ) {
F_532 ( V_14 ) ;
V_29 = F_218 ( V_115 ) ;
goto V_78;
}
V_32 = V_14 -> V_21 . V_22 ;
V_31 = V_32 + V_14 -> V_21 . V_33 - 1 ;
F_49 ( & V_34 -> V_567 ) ;
V_29 = F_20 ( & V_34 -> V_36 [ 0 ] , V_32 , V_31 ,
V_60 ) ;
if ( V_29 ) {
F_47 ( & V_34 -> V_567 ) ;
F_532 ( V_14 ) ;
goto V_737;
}
V_29 = F_20 ( & V_34 -> V_36 [ 1 ] , V_32 , V_31 ,
V_60 ) ;
if ( V_29 ) {
F_47 ( & V_34 -> V_567 ) ;
F_532 ( V_14 ) ;
goto V_737;
}
F_47 ( & V_34 -> V_567 ) ;
F_11 ( & V_92 -> V_48 ) ;
F_11 ( & V_14 -> V_48 ) ;
V_92 -> V_355 -= V_14 -> V_9 ;
V_92 -> V_343 += V_14 -> V_9 ;
F_423 ( & V_92 -> V_350 ,
- V_14 -> V_9 ) ;
V_14 -> V_9 = 0 ;
F_13 ( & V_14 -> V_48 ) ;
F_13 ( & V_92 -> V_48 ) ;
V_714 = F_265 ( V_34 , V_568 ) ;
if ( V_714 )
F_584 ( V_14 ) ;
V_29 = F_585 ( V_115 , V_34 ,
V_14 -> V_21 . V_22 ) ;
if ( V_29 ) {
if ( V_714 )
F_426 ( V_14 ) ;
goto V_737;
}
if ( V_714 ) {
F_11 ( & V_34 -> V_540 ) ;
F_586 ( & V_14 -> V_541 ,
& V_115 -> V_132 -> V_564 ) ;
F_13 ( & V_34 -> V_540 ) ;
F_4 ( V_14 ) ;
}
V_737:
F_220 ( V_115 ) ;
V_78:
F_47 ( & V_34 -> V_736 ) ;
F_6 ( V_14 ) ;
F_11 ( & V_34 -> V_540 ) ;
}
F_13 ( & V_34 -> V_540 ) ;
}
int F_587 ( struct V_12 * V_34 )
{
struct V_108 * V_92 ;
struct V_738 * V_739 ;
T_2 V_740 ;
T_2 V_7 ;
int V_719 = 0 ;
int V_29 ;
V_739 = V_34 -> V_260 ;
if ( ! F_588 ( V_739 ) )
return - V_544 ;
V_740 = F_556 ( V_739 ) ;
if ( V_740 & V_720 )
V_719 = 1 ;
V_7 = V_341 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
if ( V_29 )
goto V_79;
if ( V_719 ) {
V_7 = V_51 | V_340 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
} else {
V_7 = V_51 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
if ( V_29 )
goto V_79;
V_7 = V_340 ;
V_29 = F_289 ( V_34 , V_7 , 0 , 0 , 0 , & V_92 ) ;
}
V_79:
return V_29 ;
}
int F_589 ( struct V_12 * V_34 ,
T_2 V_32 , T_2 V_31 )
{
return F_422 ( V_34 , V_32 , V_31 , false ) ;
}
static int F_590 ( struct V_692 * V_693 ,
T_2 V_741 , T_2 * V_569 )
{
T_2 V_32 = 0 , V_45 = 0 ;
int V_29 ;
* V_569 = 0 ;
if ( ! V_693 -> V_742 )
return 0 ;
if ( V_693 -> V_342 <= V_693 -> V_91 )
return 0 ;
V_29 = 0 ;
while ( 1 ) {
struct V_12 * V_34 = V_693 -> V_34 ;
struct V_283 * V_115 ;
T_2 V_210 ;
V_29 = F_591 ( & V_34 -> V_426 ) ;
if ( V_29 )
return V_29 ;
F_50 ( & V_34 -> V_82 ) ;
F_11 ( & V_34 -> V_743 ) ;
V_115 = V_34 -> V_285 ;
if ( V_115 )
F_5 ( & V_115 -> V_744 ) ;
F_13 ( & V_34 -> V_743 ) ;
V_29 = F_592 ( V_115 , V_693 , V_741 , V_32 ,
& V_32 , & V_45 ) ;
if ( V_115 )
F_593 ( V_115 ) ;
if ( V_29 ) {
F_46 ( & V_34 -> V_82 ) ;
F_47 ( & V_34 -> V_426 ) ;
if ( V_29 == - V_317 )
V_29 = 0 ;
break;
}
V_29 = F_148 ( V_693 -> V_193 , V_32 , V_45 , & V_210 ) ;
F_46 ( & V_34 -> V_82 ) ;
F_47 ( & V_34 -> V_426 ) ;
if ( V_29 )
break;
V_32 += V_45 ;
* V_569 += V_210 ;
if ( F_594 ( V_405 ) ) {
V_29 = - V_745 ;
break;
}
F_48 () ;
}
return V_29 ;
}
int F_595 ( struct V_12 * V_34 , struct V_746 * V_747 )
{
struct V_1 * V_2 = NULL ;
struct V_692 * V_693 ;
struct V_109 * V_748 ;
T_2 V_749 ;
T_2 V_32 ;
T_2 V_31 ;
T_2 V_569 = 0 ;
T_2 V_342 = F_325 ( V_34 -> V_260 ) ;
int V_29 = 0 ;
if ( V_747 -> V_45 == V_342 )
V_2 = F_75 ( V_34 , V_747 -> V_32 ) ;
else
V_2 = F_76 ( V_34 , V_747 -> V_32 ) ;
while ( V_2 ) {
if ( V_2 -> V_21 . V_22 >= ( V_747 -> V_32 + V_747 -> V_45 ) ) {
F_6 ( V_2 ) ;
break;
}
V_32 = F_452 ( V_747 -> V_32 , V_2 -> V_21 . V_22 ) ;
V_31 = F_345 ( V_747 -> V_32 + V_747 -> V_45 ,
V_2 -> V_21 . V_22 + V_2 -> V_21 . V_33 ) ;
if ( V_31 - V_32 >= V_747 -> V_741 ) {
if ( ! F_1 ( V_2 ) ) {
V_29 = F_59 ( V_2 , 0 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
V_29 = F_441 ( V_2 ) ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_29 = F_596 ( V_2 ,
& V_749 ,
V_32 ,
V_31 ,
V_747 -> V_741 ) ;
V_569 += V_749 ;
if ( V_29 ) {
F_6 ( V_2 ) ;
break;
}
}
V_2 = F_255 ( V_34 , V_2 ) ;
}
F_49 ( & V_34 -> V_385 -> V_750 ) ;
V_748 = & V_34 -> V_385 -> V_751 ;
F_235 (device, devices, dev_alloc_list) {
V_29 = F_590 ( V_693 , V_747 -> V_741 ,
& V_749 ) ;
if ( V_29 )
break;
V_569 += V_749 ;
}
F_47 ( & V_34 -> V_385 -> V_750 ) ;
V_747 -> V_45 = V_569 ;
return V_29 ;
}
void F_597 ( struct V_61 * V_140 )
{
F_598 ( & V_140 -> V_752 -> V_753 ) ;
F_2 () ;
if ( F_599 ( & V_140 -> V_752 -> V_87 ) )
F_52 ( & V_140 -> V_752 -> V_87 ) ;
}
int F_600 ( struct V_61 * V_140 )
{
if ( F_212 ( & V_140 -> V_754 ) )
return 0 ;
F_601 ( & V_140 -> V_752 -> V_753 ) ;
F_2 () ;
if ( F_212 ( & V_140 -> V_754 ) ) {
F_597 ( V_140 ) ;
return 0 ;
}
return 1 ;
}
static int F_602 ( T_7 * V_339 )
{
F_68 () ;
return 0 ;
}
void F_603 ( struct V_61 * V_140 )
{
while ( true ) {
int V_29 ;
V_29 = F_600 ( V_140 ) ;
if ( V_29 )
break;
F_287 ( & V_140 -> V_754 ,
F_602 ,
V_99 ) ;
}
}
