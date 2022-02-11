static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_7 = 0 ;
int V_8 = V_9 | V_10 | F_2 ( V_3 ) ;
F_3 ( ! F_4 ( V_1 ) ) ;
F_3 ( ! F_5 ( V_1 ) ) ;
V_6 = F_6 ( V_1 ) ;
V_5 = V_6 ;
do {
if ( ! F_7 ( V_5 ) )
continue;
if ( V_3 -> V_11 != V_12 ) {
F_8 ( V_5 ) ;
} else if ( ! F_9 ( V_5 ) ) {
F_10 ( V_3 , V_1 ) ;
continue;
}
if ( F_11 ( V_5 ) ) {
F_12 ( V_5 ) ;
} else {
F_13 ( V_5 ) ;
}
} while ( ( V_5 = V_5 -> V_13 ) != V_6 );
F_3 ( F_14 ( V_1 ) ) ;
F_15 ( V_1 ) ;
do {
struct V_4 * V_14 = V_5 -> V_13 ;
if ( F_16 ( V_5 ) ) {
F_17 ( V_15 , V_8 , V_5 ) ;
V_7 ++ ;
}
V_5 = V_14 ;
} while ( V_5 != V_6 );
F_18 ( V_1 ) ;
if ( V_7 == 0 )
F_19 ( V_1 ) ;
return 0 ;
}
struct V_4 * F_20 ( struct V_16 * V_17 , T_1 V_18 , int V_19 )
{
struct V_20 * V_21 = F_21 ( V_17 ) ;
struct V_22 * V_23 = V_17 -> V_24 . V_25 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_26 ;
unsigned long V_27 ;
unsigned int V_28 ;
if ( V_21 == NULL )
V_21 = & V_23 -> V_29 ;
V_26 = V_30 - V_23 -> V_31 . V_32 ;
V_27 = V_18 >> V_26 ;
V_28 = V_18 - ( V_27 << V_26 ) ;
if ( V_19 ) {
for (; ; ) {
V_1 = F_22 ( V_21 , V_27 ) ;
if ( V_1 )
break;
F_23 () ;
}
} else {
V_1 = F_24 ( V_21 , V_27 ,
V_33 | V_34 ) ;
if ( ! V_1 )
return NULL ;
}
if ( ! F_5 ( V_1 ) )
F_25 ( V_1 , V_23 -> V_31 . V_35 , 0 ) ;
for ( V_5 = F_6 ( V_1 ) ; V_28 -- ; V_5 = V_5 -> V_13 )
;
F_26 ( V_5 ) ;
if ( ! F_7 ( V_5 ) )
F_27 ( V_5 , V_23 -> V_36 , V_18 ) ;
F_18 ( V_1 ) ;
F_28 ( V_1 ) ;
return V_5 ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_37 * V_38 = (struct V_37 * ) V_5 -> V_39 ;
F_8 ( V_5 ) ;
F_30 ( V_5 ) ;
F_31 ( V_5 ) ;
F_13 ( V_5 ) ;
V_38 -> V_40 = F_32 ( V_41 ) ;
}
struct V_4 * F_33 ( struct V_16 * V_17 , T_1 V_18 )
{
struct V_4 * V_5 ;
V_5 = F_20 ( V_17 , V_18 , V_42 ) ;
F_29 ( V_5 ) ;
return V_5 ;
}
static void F_34 ( struct V_43 * V_43 )
{
struct V_44 * V_45 ;
int V_46 ;
F_35 (bvec, bio, i) {
struct V_1 * V_1 = V_45 -> V_47 ;
struct V_4 * V_5 = F_6 ( V_1 ) ;
unsigned int V_48 = V_45 -> V_49 ;
while ( F_36 ( V_5 ) < V_45 -> V_50 )
V_5 = V_5 -> V_13 ;
do {
struct V_4 * V_14 = V_5 -> V_13 ;
V_48 -= V_5 -> V_51 ;
V_5 -> V_52 ( V_5 , ! V_43 -> V_53 ) ;
V_5 = V_14 ;
} while ( V_5 && V_48 );
}
F_37 ( V_43 ) ;
}
static void F_38 ( int V_54 , int V_55 , struct V_4 * V_56 [] ,
int V_57 )
{
while ( V_57 > 0 ) {
struct V_4 * V_5 = * V_56 ;
struct V_43 * V_43 ;
V_43 = F_39 ( V_58 , V_57 ) ;
V_43 -> V_59 . V_60 = V_5 -> V_61 * ( V_5 -> V_51 >> 9 ) ;
F_40 ( V_43 , V_5 -> V_62 ) ;
while ( V_57 > 0 ) {
V_5 = * V_56 ;
if ( ! F_41 ( V_43 , V_5 -> V_63 , V_5 -> V_51 , F_36 ( V_5 ) ) ) {
F_3 ( V_43 -> V_59 . V_64 == 0 ) ;
break;
}
V_56 ++ ;
V_57 -- ;
}
V_43 -> V_65 = F_34 ;
F_42 ( V_43 , V_54 , V_55 ) ;
F_43 ( V_43 ) ;
}
}
int F_44 ( struct V_16 * V_17 , T_1 V_18 , int V_66 ,
int V_67 , struct V_4 * * V_68 )
{
struct V_22 * V_23 = V_17 -> V_24 . V_25 ;
struct V_4 * V_5 , * V_56 [ 2 ] ;
int V_57 = 0 ;
if ( F_45 ( F_46 ( V_69 , & V_23 -> V_70 ) ) ) {
* V_68 = NULL ;
return - V_71 ;
}
* V_68 = V_5 = F_20 ( V_17 , V_18 , V_42 ) ;
F_8 ( V_5 ) ;
if ( F_47 ( V_5 ) ) {
F_13 ( V_5 ) ;
V_66 &= ~ V_72 ;
} else {
V_5 -> V_52 = V_73 ;
F_26 ( V_5 ) ;
V_56 [ V_57 ++ ] = V_5 ;
}
if ( V_67 ) {
V_5 = F_20 ( V_17 , V_18 + 1 , V_42 ) ;
F_8 ( V_5 ) ;
if ( F_47 ( V_5 ) ) {
F_13 ( V_5 ) ;
F_48 ( V_5 ) ;
} else {
V_5 -> V_52 = V_73 ;
V_56 [ V_57 ++ ] = V_5 ;
}
}
F_38 ( V_74 , V_9 | V_10 , V_56 , V_57 ) ;
if ( ! ( V_66 & V_72 ) )
return 0 ;
V_5 = * V_68 ;
F_49 ( V_5 ) ;
if ( F_45 ( ! F_47 ( V_5 ) ) ) {
struct V_75 * V_76 = V_77 -> V_78 ;
if ( V_76 && F_46 ( V_79 , & V_76 -> V_80 ) )
F_50 ( V_23 , V_5 ) ;
F_48 ( V_5 ) ;
* V_68 = NULL ;
return - V_71 ;
}
return 0 ;
}
int F_51 ( struct V_22 * V_23 , struct V_4 * V_5 )
{
if ( F_45 ( F_46 ( V_69 , & V_23 -> V_70 ) ) )
return - V_71 ;
F_49 ( V_5 ) ;
if ( ! F_47 ( V_5 ) ) {
struct V_75 * V_76 = V_77 -> V_78 ;
if ( V_76 && F_46 ( V_79 , & V_76 -> V_80 ) )
F_50 ( V_23 , V_5 ) ;
return - V_71 ;
}
if ( F_45 ( F_46 ( V_69 , & V_23 -> V_70 ) ) )
return - V_71 ;
return 0 ;
}
void F_52 ( struct V_4 * V_5 , int V_81 )
{
struct V_20 * V_21 = V_5 -> V_63 -> V_21 ;
struct V_22 * V_23 = F_53 ( V_21 ) ;
struct V_82 * V_83 = V_5 -> V_84 ;
struct V_75 * V_76 = V_77 -> V_78 ;
int V_85 = 0 ;
if ( F_54 ( V_5 ) ) {
F_55 ( V_83 , 0 ) ;
F_56 ( & V_23 -> V_86 ) ;
F_57 ( & V_83 -> V_87 ) ;
if ( V_81 == V_88 )
V_76 -> V_89 ++ ;
else
V_76 -> V_90 ++ ;
F_58 ( V_79 , & V_76 -> V_80 ) ;
V_85 = 1 ;
F_48 ( V_5 ) ;
}
if ( V_83 ) {
F_59 ( & V_23 -> V_91 ) ;
if ( V_83 -> V_92 ) {
F_60 ( V_23 , V_83 ) ;
} else if ( V_85 ) {
V_5 -> V_84 = NULL ;
F_61 ( V_93 , V_83 ) ;
}
F_62 ( & V_23 -> V_91 ) ;
}
F_30 ( V_5 ) ;
F_63 ( V_5 ) ;
}
void F_64 ( struct V_94 * V_95 , T_1 V_96 , T_2 V_97 )
{
struct V_22 * V_23 = F_65 ( & V_95 -> V_98 ) ;
struct V_4 * V_5 ;
while ( V_97 ) {
V_5 = F_20 ( V_95 -> V_99 , V_96 , V_100 ) ;
if ( V_5 ) {
F_8 ( V_5 ) ;
F_66 ( V_23 ) ;
F_52 ( V_5 , V_88 ) ;
F_67 ( V_23 ) ;
F_13 ( V_5 ) ;
F_48 ( V_5 ) ;
}
V_96 ++ ;
V_97 -- ;
}
}
int F_68 ( struct V_94 * V_95 , int V_101 , T_1 V_57 ,
struct V_4 * * V_68 )
{
struct V_22 * V_23 = F_65 ( & V_95 -> V_98 ) ;
struct V_16 * V_17 = V_95 -> V_99 ;
struct V_4 * V_5 ;
int V_102 = 0 ;
T_2 V_103 = V_101 ? V_104 : V_105 ;
int V_67 = 0 ;
if ( V_57 == V_95 -> V_106 )
V_67 = V_95 -> V_107 ;
V_102 = F_44 ( V_17 , V_57 , V_72 , V_67 , & V_5 ) ;
if ( V_102 == 0 && F_69 ( V_23 , V_5 , V_103 ) ) {
F_48 ( V_5 ) ;
V_102 = - V_71 ;
} else {
* V_68 = V_5 ;
}
return V_102 ;
}
struct V_4 * F_70 ( struct V_16 * V_17 , T_1 V_108 , T_2 V_109 )
{
struct V_22 * V_23 = V_17 -> V_24 . V_25 ;
struct V_4 * V_110 , * V_5 ;
T_2 V_111 = F_71 ( V_23 , V_112 ) >>
V_23 -> V_31 . V_32 ;
F_3 ( ! V_109 ) ;
if ( V_111 < 1 )
V_111 = 1 ;
if ( V_109 > V_111 )
V_109 = V_111 ;
V_110 = F_20 ( V_17 , V_108 , V_42 ) ;
if ( F_47 ( V_110 ) )
goto V_113;
if ( ! F_72 ( V_110 ) )
F_73 ( V_74 , V_9 | V_10 , 1 , & V_110 ) ;
V_108 ++ ;
V_109 -- ;
while ( V_109 ) {
V_5 = F_20 ( V_17 , V_108 , V_42 ) ;
if ( ! F_47 ( V_5 ) && ! F_72 ( V_5 ) )
F_73 ( V_74 ,
V_114 | V_9 | V_10 ,
1 , & V_5 ) ;
F_48 ( V_5 ) ;
V_108 ++ ;
V_109 -- ;
if ( ! F_72 ( V_110 ) && F_47 ( V_110 ) )
goto V_113;
}
F_49 ( V_110 ) ;
V_113:
return V_110 ;
}
