static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_7 = 0 ;
int V_8 = V_9 | V_10 |
( V_3 -> V_11 == V_12 ? V_13 : V_14 ) ;
F_2 ( ! F_3 ( V_1 ) ) ;
F_2 ( ! F_4 ( V_1 ) ) ;
V_6 = F_5 ( V_1 ) ;
V_5 = V_6 ;
do {
if ( ! F_6 ( V_5 ) )
continue;
if ( V_3 -> V_11 != V_15 ) {
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
} while ( ( V_5 = V_5 -> V_16 ) != V_6 );
F_2 ( F_13 ( V_1 ) ) ;
F_14 ( V_1 ) ;
do {
struct V_4 * V_17 = V_5 -> V_16 ;
if ( F_15 ( V_5 ) ) {
F_16 ( V_8 , V_5 ) ;
V_7 ++ ;
}
V_5 = V_17 ;
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
for ( V_5 = F_5 ( V_1 ) ; V_30 -- ; V_5 = V_5 -> V_16 )
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
V_5 = V_5 -> V_16 ;
do {
struct V_4 * V_17 = V_5 -> V_16 ;
V_50 -= V_5 -> V_53 ;
V_5 -> V_54 ( V_5 , ! V_45 -> V_55 ) ;
V_5 = V_17 ;
} while ( V_5 && V_50 );
}
F_36 ( V_45 ) ;
}
static void F_37 ( int V_56 , struct V_4 * V_57 [] , int V_58 )
{
struct V_4 * V_5 = V_57 [ 0 ] ;
struct V_45 * V_45 ;
int V_48 ;
if ( ! V_58 )
return;
V_45 = F_38 ( V_59 , V_58 ) ;
V_45 -> V_60 . V_61 = V_5 -> V_62 * ( V_5 -> V_53 >> 9 ) ;
V_45 -> V_63 = V_5 -> V_64 ;
for ( V_48 = 0 ; V_48 < V_58 ; V_48 ++ ) {
V_5 = V_57 [ V_48 ] ;
F_39 ( V_45 , V_5 -> V_65 , V_5 -> V_53 , F_35 ( V_5 ) ) ;
}
V_45 -> V_66 = F_33 ;
F_40 ( V_56 , V_45 ) ;
}
int F_41 ( struct V_18 * V_19 , T_1 V_20 , int V_67 ,
int V_68 , struct V_4 * * V_69 )
{
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_4 * V_5 , * V_57 [ 2 ] ;
int V_58 = 0 ;
if ( F_42 ( F_43 ( V_70 , & V_25 -> V_71 ) ) ) {
* V_69 = NULL ;
return - V_72 ;
}
* V_69 = V_5 = F_19 ( V_19 , V_20 , V_44 ) ;
F_7 ( V_5 ) ;
if ( F_44 ( V_5 ) ) {
F_12 ( V_5 ) ;
V_67 &= ~ V_73 ;
} else {
V_5 -> V_54 = V_74 ;
F_25 ( V_5 ) ;
V_57 [ V_58 ++ ] = V_5 ;
}
if ( V_68 ) {
V_5 = F_19 ( V_19 , V_20 + 1 , V_44 ) ;
F_7 ( V_5 ) ;
if ( F_44 ( V_5 ) ) {
F_12 ( V_5 ) ;
F_45 ( V_5 ) ;
} else {
V_5 -> V_54 = V_74 ;
V_57 [ V_58 ++ ] = V_5 ;
}
}
F_37 ( V_75 | V_9 | V_10 , V_57 , V_58 ) ;
if ( ! ( V_67 & V_73 ) )
return 0 ;
V_5 = * V_69 ;
F_46 ( V_5 ) ;
if ( F_42 ( ! F_44 ( V_5 ) ) ) {
struct V_76 * V_77 = V_78 -> V_79 ;
if ( V_77 && V_77 -> V_80 )
F_47 ( V_25 , V_5 ) ;
F_45 ( V_5 ) ;
* V_69 = NULL ;
return - V_72 ;
}
return 0 ;
}
int F_48 ( struct V_24 * V_25 , struct V_4 * V_5 )
{
if ( F_42 ( F_43 ( V_70 , & V_25 -> V_71 ) ) )
return - V_72 ;
F_46 ( V_5 ) ;
if ( ! F_44 ( V_5 ) ) {
struct V_76 * V_77 = V_78 -> V_79 ;
if ( V_77 && V_77 -> V_80 )
F_47 ( V_25 , V_5 ) ;
return - V_72 ;
}
if ( F_42 ( F_43 ( V_70 , & V_25 -> V_71 ) ) )
return - V_72 ;
return 0 ;
}
void F_49 ( struct V_4 * V_5 , struct V_76 * V_77 , int V_81 )
{
struct V_22 * V_23 = V_5 -> V_65 -> V_23 ;
struct V_24 * V_25 = F_50 ( V_23 ) ;
struct V_82 * V_83 = V_5 -> V_84 ;
int V_85 = 0 ;
if ( F_51 ( V_5 ) ) {
F_52 ( V_83 , 0 ) ;
F_53 ( & V_25 -> V_86 ) ;
F_54 ( & V_83 -> V_87 ) ;
if ( V_81 )
V_77 -> V_88 ++ ;
else
V_77 -> V_89 ++ ;
V_77 -> V_80 = 1 ;
V_85 = 1 ;
F_45 ( V_5 ) ;
}
if ( V_83 ) {
F_55 ( & V_25 -> V_90 ) ;
if ( V_83 -> V_91 ) {
F_56 ( V_25 , V_83 ) ;
} else if ( V_85 ) {
V_5 -> V_84 = NULL ;
F_57 ( V_92 , V_83 ) ;
}
F_58 ( & V_25 -> V_90 ) ;
}
F_29 ( V_5 ) ;
F_59 ( V_5 ) ;
}
void F_60 ( struct V_93 * V_94 , T_1 V_95 , T_2 V_96 )
{
struct V_24 * V_25 = F_61 ( & V_94 -> V_97 ) ;
struct V_4 * V_5 ;
while ( V_96 ) {
V_5 = F_19 ( V_94 -> V_98 , V_95 , V_99 ) ;
if ( V_5 ) {
F_7 ( V_5 ) ;
F_62 ( V_25 ) ;
F_49 ( V_5 , V_78 -> V_79 , 1 ) ;
F_63 ( V_25 ) ;
F_12 ( V_5 ) ;
F_45 ( V_5 ) ;
}
V_95 ++ ;
V_96 -- ;
}
}
int F_64 ( struct V_93 * V_94 , int V_100 , T_1 V_58 ,
struct V_4 * * V_69 )
{
struct V_24 * V_25 = F_61 ( & V_94 -> V_97 ) ;
struct V_18 * V_19 = V_94 -> V_98 ;
struct V_4 * V_5 ;
int V_101 = 0 ;
T_2 V_102 = V_100 ? V_103 : V_104 ;
int V_68 = 0 ;
if ( V_58 == V_94 -> V_105 )
V_68 = V_94 -> V_106 ;
V_101 = F_41 ( V_19 , V_58 , V_73 , V_68 , & V_5 ) ;
if ( V_101 == 0 && F_65 ( V_25 , V_5 , V_102 ) ) {
F_45 ( V_5 ) ;
V_101 = - V_72 ;
}
* V_69 = V_5 ;
return V_101 ;
}
struct V_4 * F_66 ( struct V_18 * V_19 , T_1 V_107 , T_2 V_108 )
{
struct V_24 * V_25 = V_19 -> V_26 . V_27 ;
struct V_4 * V_109 , * V_5 ;
T_2 V_110 = F_67 ( V_25 , V_111 ) >>
V_25 -> V_33 . V_34 ;
F_2 ( ! V_108 ) ;
if ( V_110 < 1 )
V_110 = 1 ;
if ( V_108 > V_110 )
V_108 = V_110 ;
V_109 = F_19 ( V_19 , V_107 , V_44 ) ;
if ( F_44 ( V_109 ) )
goto V_112;
if ( ! F_68 ( V_109 ) )
F_69 ( V_75 | V_9 , 1 , & V_109 ) ;
V_107 ++ ;
V_108 -- ;
while ( V_108 ) {
V_5 = F_19 ( V_19 , V_107 , V_44 ) ;
if ( ! F_44 ( V_5 ) && ! F_68 ( V_5 ) )
F_69 ( V_113 | V_9 , 1 , & V_5 ) ;
F_45 ( V_5 ) ;
V_107 ++ ;
V_108 -- ;
if ( ! F_68 ( V_109 ) && F_44 ( V_109 ) )
goto V_112;
}
F_46 ( V_109 ) ;
V_112:
return V_109 ;
}
