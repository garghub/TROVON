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
V_43 -> V_62 = V_5 -> V_63 ;
while ( V_57 > 0 ) {
V_5 = * V_56 ;
if ( ! F_40 ( V_43 , V_5 -> V_64 , V_5 -> V_51 , F_36 ( V_5 ) ) ) {
F_3 ( V_43 -> V_59 . V_65 == 0 ) ;
break;
}
V_56 ++ ;
V_57 -- ;
}
V_43 -> V_66 = F_34 ;
F_41 ( V_43 , V_54 , V_55 ) ;
F_42 ( V_43 ) ;
}
}
int F_43 ( struct V_16 * V_17 , T_1 V_18 , int V_67 ,
int V_68 , struct V_4 * * V_69 )
{
struct V_22 * V_23 = V_17 -> V_24 . V_25 ;
struct V_4 * V_5 , * V_56 [ 2 ] ;
int V_57 = 0 ;
if ( F_44 ( F_45 ( V_70 , & V_23 -> V_71 ) ) ) {
* V_69 = NULL ;
return - V_72 ;
}
* V_69 = V_5 = F_20 ( V_17 , V_18 , V_42 ) ;
F_8 ( V_5 ) ;
if ( F_46 ( V_5 ) ) {
F_13 ( V_5 ) ;
V_67 &= ~ V_73 ;
} else {
V_5 -> V_52 = V_74 ;
F_26 ( V_5 ) ;
V_56 [ V_57 ++ ] = V_5 ;
}
if ( V_68 ) {
V_5 = F_20 ( V_17 , V_18 + 1 , V_42 ) ;
F_8 ( V_5 ) ;
if ( F_46 ( V_5 ) ) {
F_13 ( V_5 ) ;
F_47 ( V_5 ) ;
} else {
V_5 -> V_52 = V_74 ;
V_56 [ V_57 ++ ] = V_5 ;
}
}
F_38 ( V_75 , V_9 | V_10 , V_56 , V_57 ) ;
if ( ! ( V_67 & V_73 ) )
return 0 ;
V_5 = * V_69 ;
F_48 ( V_5 ) ;
if ( F_44 ( ! F_46 ( V_5 ) ) ) {
struct V_76 * V_77 = V_78 -> V_79 ;
if ( V_77 && F_45 ( V_80 , & V_77 -> V_81 ) )
F_49 ( V_23 , V_5 ) ;
F_47 ( V_5 ) ;
* V_69 = NULL ;
return - V_72 ;
}
return 0 ;
}
int F_50 ( struct V_22 * V_23 , struct V_4 * V_5 )
{
if ( F_44 ( F_45 ( V_70 , & V_23 -> V_71 ) ) )
return - V_72 ;
F_48 ( V_5 ) ;
if ( ! F_46 ( V_5 ) ) {
struct V_76 * V_77 = V_78 -> V_79 ;
if ( V_77 && F_45 ( V_80 , & V_77 -> V_81 ) )
F_49 ( V_23 , V_5 ) ;
return - V_72 ;
}
if ( F_44 ( F_45 ( V_70 , & V_23 -> V_71 ) ) )
return - V_72 ;
return 0 ;
}
void F_51 ( struct V_4 * V_5 , int V_82 )
{
struct V_20 * V_21 = V_5 -> V_64 -> V_21 ;
struct V_22 * V_23 = F_52 ( V_21 ) ;
struct V_83 * V_84 = V_5 -> V_85 ;
struct V_76 * V_77 = V_78 -> V_79 ;
int V_86 = 0 ;
if ( F_53 ( V_5 ) ) {
F_54 ( V_84 , 0 ) ;
F_55 ( & V_23 -> V_87 ) ;
F_56 ( & V_84 -> V_88 ) ;
if ( V_82 == V_89 )
V_77 -> V_90 ++ ;
else
V_77 -> V_91 ++ ;
F_57 ( V_80 , & V_77 -> V_81 ) ;
V_86 = 1 ;
F_47 ( V_5 ) ;
}
if ( V_84 ) {
F_58 ( & V_23 -> V_92 ) ;
if ( V_84 -> V_93 ) {
F_59 ( V_23 , V_84 ) ;
} else if ( V_86 ) {
V_5 -> V_85 = NULL ;
F_60 ( V_94 , V_84 ) ;
}
F_61 ( & V_23 -> V_92 ) ;
}
F_30 ( V_5 ) ;
F_62 ( V_5 ) ;
}
void F_63 ( struct V_95 * V_96 , T_1 V_97 , T_2 V_98 )
{
struct V_22 * V_23 = F_64 ( & V_96 -> V_99 ) ;
struct V_4 * V_5 ;
while ( V_98 ) {
V_5 = F_20 ( V_96 -> V_100 , V_97 , V_101 ) ;
if ( V_5 ) {
F_8 ( V_5 ) ;
F_65 ( V_23 ) ;
F_51 ( V_5 , V_89 ) ;
F_66 ( V_23 ) ;
F_13 ( V_5 ) ;
F_47 ( V_5 ) ;
}
V_97 ++ ;
V_98 -- ;
}
}
int F_67 ( struct V_95 * V_96 , int V_102 , T_1 V_57 ,
struct V_4 * * V_69 )
{
struct V_22 * V_23 = F_64 ( & V_96 -> V_99 ) ;
struct V_16 * V_17 = V_96 -> V_100 ;
struct V_4 * V_5 ;
int V_103 = 0 ;
T_2 V_104 = V_102 ? V_105 : V_106 ;
int V_68 = 0 ;
if ( V_57 == V_96 -> V_107 )
V_68 = V_96 -> V_108 ;
V_103 = F_43 ( V_17 , V_57 , V_73 , V_68 , & V_5 ) ;
if ( V_103 == 0 && F_68 ( V_23 , V_5 , V_104 ) ) {
F_47 ( V_5 ) ;
V_103 = - V_72 ;
}
* V_69 = V_5 ;
return V_103 ;
}
struct V_4 * F_69 ( struct V_16 * V_17 , T_1 V_109 , T_2 V_110 )
{
struct V_22 * V_23 = V_17 -> V_24 . V_25 ;
struct V_4 * V_111 , * V_5 ;
T_2 V_112 = F_70 ( V_23 , V_113 ) >>
V_23 -> V_31 . V_32 ;
F_3 ( ! V_110 ) ;
if ( V_112 < 1 )
V_112 = 1 ;
if ( V_110 > V_112 )
V_110 = V_112 ;
V_111 = F_20 ( V_17 , V_109 , V_42 ) ;
if ( F_46 ( V_111 ) )
goto V_114;
if ( ! F_71 ( V_111 ) )
F_72 ( V_75 , V_9 , 1 , & V_111 ) ;
V_109 ++ ;
V_110 -- ;
while ( V_110 ) {
V_5 = F_20 ( V_17 , V_109 , V_42 ) ;
if ( ! F_46 ( V_5 ) && ! F_71 ( V_5 ) )
F_72 ( V_75 , V_115 | V_9 , 1 , & V_5 ) ;
F_47 ( V_5 ) ;
V_109 ++ ;
V_110 -- ;
if ( ! F_71 ( V_111 ) && F_46 ( V_111 ) )
goto V_114;
}
F_48 ( V_111 ) ;
V_114:
return V_111 ;
}
