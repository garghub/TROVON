static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_7 = 0 ;
int V_8 = V_9 | V_10 |
( V_3 -> V_11 == V_12 ? V_13 : 0 ) ;
F_2 ( ! F_3 ( V_1 ) ) ;
F_2 ( ! F_4 ( V_1 ) ) ;
V_6 = F_5 ( V_1 ) ;
V_5 = V_6 ;
do {
if ( ! F_6 ( V_5 ) )
continue;
if ( V_3 -> V_11 != V_14 ) {
F_7 ( V_5 ) ;
} else if ( ! F_8 ( V_5 ) ) {
F_9 ( V_3 , V_1 ) ;
continue;
}
if ( F_10 ( V_5 ) ) {
F_11 ( V_5 ) ;
} else {
F_12 ( V_5 ) ;
}
} while ( ( V_5 = V_5 -> V_15 ) != V_6 );
F_2 ( F_13 ( V_1 ) ) ;
F_14 ( V_1 ) ;
do {
struct V_4 * V_16 = V_5 -> V_15 ;
if ( F_15 ( V_5 ) ) {
F_16 ( V_17 , V_8 , V_5 ) ;
V_7 ++ ;
}
V_5 = V_16 ;
} while ( V_5 != V_6 );
F_17 ( V_1 ) ;
if ( V_7 == 0 )
F_18 ( V_1 ) ;
return 0 ;
}
struct V_4 * F_19 ( struct V_18 * V_19 , T_1 V_20 , int V_21 )
{
struct V_22 * V_23 = F_20 ( V_19 ) ;
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
unsigned int V_28 ;
unsigned long V_29 ;
unsigned int V_30 ;
if ( V_23 == NULL )
V_23 = & V_25 -> V_31 ;
V_28 = V_32 - V_25 -> V_33 . V_34 ;
V_29 = V_20 >> V_28 ;
V_30 = V_20 - ( V_29 << V_28 ) ;
if ( V_21 ) {
for (; ; ) {
V_1 = F_21 ( V_23 , V_29 ) ;
if ( V_1 )
break;
F_22 () ;
}
} else {
V_1 = F_23 ( V_23 , V_29 ,
V_35 | V_36 ) ;
if ( ! V_1 )
return NULL ;
}
if ( ! F_4 ( V_1 ) )
F_24 ( V_1 , V_25 -> V_33 . V_37 , 0 ) ;
for ( V_5 = F_5 ( V_1 ) ; V_30 -- ; V_5 = V_5 -> V_15 )
;
F_25 ( V_5 ) ;
if ( ! F_6 ( V_5 ) )
F_26 ( V_5 , V_25 -> V_38 , V_20 ) ;
F_17 ( V_1 ) ;
F_27 ( V_1 ) ;
return V_5 ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_39 * V_40 = (struct V_39 * ) V_5 -> V_41 ;
F_7 ( V_5 ) ;
F_29 ( V_5 ) ;
F_30 ( V_5 ) ;
F_12 ( V_5 ) ;
V_40 -> V_42 = F_31 ( V_43 ) ;
}
struct V_4 * F_32 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_4 * V_5 ;
V_5 = F_19 ( V_19 , V_20 , V_44 ) ;
F_28 ( V_5 ) ;
return V_5 ;
}
static void F_33 ( struct V_45 * V_45 )
{
struct V_46 * V_47 ;
int V_48 ;
F_34 (bvec, bio, i) {
struct V_1 * V_1 = V_47 -> V_49 ;
struct V_4 * V_5 = F_5 ( V_1 ) ;
unsigned int V_50 = V_47 -> V_51 ;
while ( F_35 ( V_5 ) < V_47 -> V_52 )
V_5 = V_5 -> V_15 ;
do {
struct V_4 * V_16 = V_5 -> V_15 ;
V_50 -= V_5 -> V_53 ;
V_5 -> V_54 ( V_5 , ! V_45 -> V_55 ) ;
V_5 = V_16 ;
} while ( V_5 && V_50 );
}
F_36 ( V_45 ) ;
}
static void F_37 ( int V_56 , int V_57 , struct V_4 * V_58 [] ,
int V_59 )
{
while ( V_59 > 0 ) {
struct V_4 * V_5 = * V_58 ;
struct V_45 * V_45 ;
V_45 = F_38 ( V_60 , V_59 ) ;
V_45 -> V_61 . V_62 = V_5 -> V_63 * ( V_5 -> V_53 >> 9 ) ;
V_45 -> V_64 = V_5 -> V_65 ;
while ( V_59 > 0 ) {
V_5 = * V_58 ;
if ( ! F_39 ( V_45 , V_5 -> V_66 , V_5 -> V_53 , F_35 ( V_5 ) ) ) {
F_2 ( V_45 -> V_61 . V_67 == 0 ) ;
break;
}
V_58 ++ ;
V_59 -- ;
}
V_45 -> V_68 = F_33 ;
F_40 ( V_45 , V_56 , V_57 ) ;
F_41 ( V_45 ) ;
}
}
int F_42 ( struct V_18 * V_19 , T_1 V_20 , int V_69 ,
int V_70 , struct V_4 * * V_71 )
{
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_4 * V_5 , * V_58 [ 2 ] ;
int V_59 = 0 ;
if ( F_43 ( F_44 ( V_72 , & V_25 -> V_73 ) ) ) {
* V_71 = NULL ;
return - V_74 ;
}
* V_71 = V_5 = F_19 ( V_19 , V_20 , V_44 ) ;
F_7 ( V_5 ) ;
if ( F_45 ( V_5 ) ) {
F_12 ( V_5 ) ;
V_69 &= ~ V_75 ;
} else {
V_5 -> V_54 = V_76 ;
F_25 ( V_5 ) ;
V_58 [ V_59 ++ ] = V_5 ;
}
if ( V_70 ) {
V_5 = F_19 ( V_19 , V_20 + 1 , V_44 ) ;
F_7 ( V_5 ) ;
if ( F_45 ( V_5 ) ) {
F_12 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
V_5 -> V_54 = V_76 ;
V_58 [ V_59 ++ ] = V_5 ;
}
}
F_37 ( V_77 , V_78 | V_9 | V_10 , V_58 , V_59 ) ;
if ( ! ( V_69 & V_75 ) )
return 0 ;
V_5 = * V_71 ;
F_47 ( V_5 ) ;
if ( F_43 ( ! F_45 ( V_5 ) ) ) {
struct V_79 * V_80 = V_81 -> V_82 ;
if ( V_80 && V_80 -> V_83 )
F_48 ( V_25 , V_5 ) ;
F_46 ( V_5 ) ;
* V_71 = NULL ;
return - V_74 ;
}
return 0 ;
}
int F_49 ( struct V_24 * V_25 , struct V_4 * V_5 )
{
if ( F_43 ( F_44 ( V_72 , & V_25 -> V_73 ) ) )
return - V_74 ;
F_47 ( V_5 ) ;
if ( ! F_45 ( V_5 ) ) {
struct V_79 * V_80 = V_81 -> V_82 ;
if ( V_80 && V_80 -> V_83 )
F_48 ( V_25 , V_5 ) ;
return - V_74 ;
}
if ( F_43 ( F_44 ( V_72 , & V_25 -> V_73 ) ) )
return - V_74 ;
return 0 ;
}
void F_50 ( struct V_4 * V_5 , int V_84 )
{
struct V_22 * V_23 = V_5 -> V_66 -> V_23 ;
struct V_24 * V_25 = F_51 ( V_23 ) ;
struct V_85 * V_86 = V_5 -> V_87 ;
struct V_79 * V_80 = V_81 -> V_82 ;
int V_88 = 0 ;
if ( F_52 ( V_5 ) ) {
F_53 ( V_86 , 0 ) ;
F_54 ( & V_25 -> V_89 ) ;
F_55 ( & V_86 -> V_90 ) ;
if ( V_84 == V_91 )
V_80 -> V_92 ++ ;
else
V_80 -> V_93 ++ ;
V_80 -> V_83 = 1 ;
V_88 = 1 ;
F_46 ( V_5 ) ;
}
if ( V_86 ) {
F_56 ( & V_25 -> V_94 ) ;
if ( V_86 -> V_95 ) {
F_57 ( V_25 , V_86 ) ;
} else if ( V_88 ) {
V_5 -> V_87 = NULL ;
F_58 ( V_96 , V_86 ) ;
}
F_59 ( & V_25 -> V_94 ) ;
}
F_29 ( V_5 ) ;
F_60 ( V_5 ) ;
}
void F_61 ( struct V_97 * V_98 , T_1 V_99 , T_2 V_100 )
{
struct V_24 * V_25 = F_62 ( & V_98 -> V_101 ) ;
struct V_4 * V_5 ;
while ( V_100 ) {
V_5 = F_19 ( V_98 -> V_102 , V_99 , V_103 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_63 ( V_25 ) ;
F_50 ( V_5 , V_91 ) ;
F_64 ( V_25 ) ;
F_12 ( V_5 ) ;
F_46 ( V_5 ) ;
}
V_99 ++ ;
V_100 -- ;
}
}
int F_65 ( struct V_97 * V_98 , int V_104 , T_1 V_59 ,
struct V_4 * * V_71 )
{
struct V_24 * V_25 = F_62 ( & V_98 -> V_101 ) ;
struct V_18 * V_19 = V_98 -> V_102 ;
struct V_4 * V_5 ;
int V_105 = 0 ;
T_2 V_106 = V_104 ? V_107 : V_108 ;
int V_70 = 0 ;
if ( V_59 == V_98 -> V_109 )
V_70 = V_98 -> V_110 ;
V_105 = F_42 ( V_19 , V_59 , V_75 , V_70 , & V_5 ) ;
if ( V_105 == 0 && F_66 ( V_25 , V_5 , V_106 ) ) {
F_46 ( V_5 ) ;
V_105 = - V_74 ;
}
* V_71 = V_5 ;
return V_105 ;
}
struct V_4 * F_67 ( struct V_18 * V_19 , T_1 V_111 , T_2 V_112 )
{
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_4 * V_113 , * V_5 ;
T_2 V_114 = F_68 ( V_25 , V_115 ) >>
V_25 -> V_33 . V_34 ;
F_2 ( ! V_112 ) ;
if ( V_114 < 1 )
V_114 = 1 ;
if ( V_112 > V_114 )
V_112 = V_114 ;
V_113 = F_19 ( V_19 , V_111 , V_44 ) ;
if ( F_45 ( V_113 ) )
goto V_116;
if ( ! F_69 ( V_113 ) )
F_70 ( V_77 , V_78 | V_9 , 1 , & V_113 ) ;
V_111 ++ ;
V_112 -- ;
while ( V_112 ) {
V_5 = F_19 ( V_19 , V_111 , V_44 ) ;
if ( ! F_45 ( V_5 ) && ! F_69 ( V_5 ) )
F_70 ( V_77 , V_117 | V_9 , 1 , & V_5 ) ;
F_46 ( V_5 ) ;
V_111 ++ ;
V_112 -- ;
if ( ! F_69 ( V_113 ) && F_45 ( V_113 ) )
goto V_116;
}
F_47 ( V_113 ) ;
V_116:
return V_113 ;
}
