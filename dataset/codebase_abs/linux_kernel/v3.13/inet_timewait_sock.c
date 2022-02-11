int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) )
return 0 ;
F_3 ( & V_2 -> V_3 ) ;
F_4 ( & V_2 -> V_3 ) ;
return 1 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return 0 ;
F_6 ( & V_2 -> V_9 ) ;
V_2 -> V_8 = NULL ;
F_7 ( V_5 -> V_10 , V_7 ) ;
return 1 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_11 * V_12 ;
int V_13 ;
T_1 * V_14 = F_9 ( V_5 , V_2 -> V_15 ) ;
F_10 ( V_14 ) ;
V_13 = F_1 ( V_2 ) ;
F_11 ( V_14 ) ;
V_12 = & V_5 -> V_16 [ F_12 ( F_13 ( V_2 ) , V_2 -> V_17 ,
V_5 -> V_18 ) ] ;
F_10 ( & V_12 -> V_14 ) ;
V_13 += F_5 ( V_2 , V_5 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_14 ( V_13 >= F_15 ( & V_2 -> V_19 ) ) ;
F_16 ( V_13 , & V_2 -> V_19 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_22 -> V_21 ;
F_18 ( (struct V_23 * ) V_2 ) ;
#ifdef F_19
F_20 ( L_1 , V_2 -> V_22 -> V_24 , V_2 ) ;
#endif
F_21 ( F_13 ( V_2 ) ) ;
F_22 ( V_2 -> V_22 -> V_25 -> V_26 , V_2 ) ;
F_23 ( V_21 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( & V_2 -> V_19 ) )
F_17 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_27 ( & V_2 -> V_3 , V_28 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_29 * V_28 )
{
F_29 ( & V_2 -> V_9 , V_28 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_23 * V_30 ,
struct V_4 * V_5 )
{
const struct V_31 * V_32 = F_31 ( V_30 ) ;
const struct V_33 * V_34 = F_32 ( V_30 ) ;
struct V_35 * V_36 = V_35 ( V_5 , V_30 -> V_37 ) ;
T_1 * V_14 = F_9 ( V_5 , V_30 -> V_37 ) ;
struct V_11 * V_12 ;
V_12 = & V_5 -> V_16 [ F_12 ( F_13 ( V_2 ) , V_32 -> V_38 ,
V_5 -> V_18 ) ] ;
F_10 ( & V_12 -> V_14 ) ;
V_2 -> V_8 = V_34 -> V_39 ;
F_33 ( ! V_34 -> V_39 ) ;
F_28 ( V_2 , & V_2 -> V_8 -> V_40 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_10 ( V_14 ) ;
F_34 ( & V_2 -> V_19 , 1 + 1 + 1 ) ;
F_26 ( V_2 , & V_36 -> V_41 ) ;
if ( F_35 ( V_30 ) )
F_36 ( F_37 ( V_30 ) , V_30 -> V_42 , - 1 ) ;
F_11 ( V_14 ) ;
}
struct V_1 * F_38 ( const struct V_23 * V_30 , const int V_43 )
{
struct V_1 * V_2 =
F_39 ( V_30 -> V_44 -> V_25 -> V_26 ,
V_45 ) ;
if ( V_2 != NULL ) {
const struct V_31 * V_32 = F_31 ( V_30 ) ;
F_40 ( V_2 , V_46 ) ;
V_2 -> V_47 = V_32 -> V_48 ;
V_2 -> V_49 = V_32 -> V_50 ;
V_2 -> V_51 = V_30 -> V_52 ;
V_2 -> V_53 = V_32 -> V_54 ;
V_2 -> V_17 = V_32 -> V_38 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = V_43 ;
V_2 -> V_58 = V_32 -> V_59 ;
V_2 -> V_60 = V_32 -> V_61 ;
V_2 -> V_62 = V_30 -> V_63 ;
V_2 -> V_64 = V_30 -> V_65 ;
V_2 -> V_15 = V_30 -> V_37 ;
V_2 -> V_66 = 0 ;
V_2 -> V_67 = V_32 -> V_68 ;
V_2 -> V_22 = V_30 -> V_44 ;
F_41 ( V_2 , F_42 ( F_37 ( V_30 ) ) ) ;
F_34 ( & V_2 -> V_19 , 0 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 -> V_22 -> V_21 ) ;
}
return V_2 ;
}
static int F_45 ( struct V_69 * V_70 ,
const int V_71 )
{
struct V_1 * V_2 ;
unsigned int V_72 ;
int V_73 ;
V_72 = 0 ;
V_73 = 0 ;
V_74:
F_46 (tw, &twdr->cells[slot]) {
F_47 ( V_2 ) ;
F_11 ( & V_70 -> V_75 ) ;
F_8 ( V_2 , V_70 -> V_5 ) ;
#ifdef F_48
F_49 ( F_13 ( V_2 ) , V_76 ) ;
#endif
F_24 ( V_2 ) ;
V_72 ++ ;
F_10 ( & V_70 -> V_75 ) ;
if ( V_72 > V_77 ) {
V_73 = 1 ;
break;
}
goto V_74;
}
V_70 -> V_78 -= V_72 ;
#ifndef F_48
F_50 ( & V_79 , V_76 , V_72 ) ;
#endif
return V_73 ;
}
void F_51 ( unsigned long V_80 )
{
struct V_69 * V_70 ;
unsigned int V_81 ;
V_70 = (struct V_69 * ) V_80 ;
F_10 ( & V_70 -> V_75 ) ;
if ( V_70 -> V_78 == 0 )
goto V_82;
V_81 = 0 ;
if ( F_45 ( V_70 , V_70 -> V_71 ) ) {
V_70 -> V_83 |= ( 1 << V_70 -> V_71 ) ;
F_52 ( & V_70 -> V_84 ) ;
V_81 = 1 ;
} else {
if ( V_70 -> V_78 )
V_81 = 1 ;
V_70 -> V_71 = ( ( V_70 -> V_71 + 1 ) & ( V_85 - 1 ) ) ;
}
if ( V_81 )
F_53 ( & V_70 -> V_86 , V_87 + V_70 -> V_88 ) ;
V_82:
F_11 ( & V_70 -> V_75 ) ;
}
void F_54 ( struct V_89 * V_90 )
{
struct V_69 * V_70 =
F_55 ( V_90 , struct V_69 , V_84 ) ;
int V_91 ;
F_56 ( ( V_85 - 1 ) >
( sizeof( V_70 -> V_83 ) * 8 ) ) ;
while ( V_70 -> V_83 ) {
F_57 ( & V_70 -> V_75 ) ;
for ( V_91 = 0 ; V_91 < V_85 ; V_91 ++ ) {
if ( ! ( V_70 -> V_83 & ( 1 << V_91 ) ) )
continue;
while ( F_45 ( V_70 , V_91 ) != 0 ) {
if ( F_58 () ) {
F_59 ( & V_70 -> V_75 ) ;
F_60 () ;
F_57 ( & V_70 -> V_75 ) ;
}
}
V_70 -> V_83 &= ~ ( 1 << V_91 ) ;
}
F_59 ( & V_70 -> V_75 ) ;
}
}
void F_61 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
F_10 ( & V_70 -> V_75 ) ;
if ( F_62 ( V_2 ) ) {
F_24 ( V_2 ) ;
if ( -- V_70 -> V_78 == 0 )
F_63 ( & V_70 -> V_86 ) ;
}
F_11 ( & V_70 -> V_75 ) ;
F_8 ( V_2 , V_70 -> V_5 ) ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
const int V_92 , const int V_93 )
{
struct V_29 * V_28 ;
int V_71 ;
V_71 = ( V_92 + ( 1 << V_94 ) - 1 ) >> V_94 ;
F_10 ( & V_70 -> V_75 ) ;
if ( F_62 ( V_2 ) )
V_70 -> V_78 -- ;
else
F_65 ( & V_2 -> V_19 ) ;
if ( V_71 >= V_95 ) {
if ( V_92 >= V_93 ) {
V_71 = V_85 - 1 ;
} else {
V_71 = F_66 ( V_92 , V_70 -> V_88 ) ;
if ( V_71 >= V_85 )
V_71 = V_85 - 1 ;
}
V_2 -> V_96 = F_67 () + V_92 ;
V_71 = ( V_70 -> V_71 + V_71 ) & ( V_85 - 1 ) ;
V_28 = & V_70 -> V_97 [ V_71 ] ;
} else {
V_2 -> V_96 = F_67 () + ( V_71 << V_94 ) ;
if ( V_70 -> V_98 < 0 ) {
V_70 -> V_98 = 0 ;
V_70 -> V_99 = V_87 ;
V_70 -> V_100 . V_101 = V_70 -> V_99 +
( V_71 << V_94 ) ;
F_68 ( & V_70 -> V_100 ) ;
} else {
if ( F_69 ( V_70 -> V_100 . V_101 ,
V_87 + ( V_71 << V_94 ) ) )
F_53 ( & V_70 -> V_100 ,
V_87 + ( V_71 << V_94 ) ) ;
V_71 = ( V_70 -> V_98 + V_71 ) & ( V_95 - 1 ) ;
}
V_28 = & V_70 -> V_102 [ V_71 ] ;
}
F_29 ( & V_2 -> V_103 , V_28 ) ;
if ( V_70 -> V_78 ++ == 0 )
F_53 ( & V_70 -> V_86 , V_87 + V_70 -> V_88 ) ;
F_11 ( & V_70 -> V_75 ) ;
}
void F_70 ( unsigned long V_80 )
{
struct V_69 * V_70 ;
int V_104 , V_71 ;
unsigned long V_105 ;
unsigned long V_106 = V_87 ;
int V_72 = 0 ;
int V_107 = 0 ;
V_70 = (struct V_69 * ) V_80 ;
F_10 ( & V_70 -> V_75 ) ;
if ( V_70 -> V_98 < 0 )
goto V_82;
V_71 = V_70 -> V_98 ;
V_105 = V_70 -> V_99 ;
for ( V_104 = 0 ; V_104 < V_95 ; V_104 ++ ) {
if ( F_71 ( V_105 , V_106 ) ) {
struct V_108 * V_109 ;
struct V_1 * V_2 ;
F_72 (tw, safe,
&twdr->twcal_row[slot]) {
F_47 ( V_2 ) ;
F_8 ( V_2 , V_70 -> V_5 ) ;
#ifdef F_48
F_49 ( F_13 ( V_2 ) , V_110 ) ;
#endif
F_24 ( V_2 ) ;
V_72 ++ ;
}
} else {
if ( ! V_107 ) {
V_107 = 1 ;
V_70 -> V_99 = V_105 ;
V_70 -> V_98 = V_71 ;
}
if ( ! F_73 ( & V_70 -> V_102 [ V_71 ] ) ) {
F_53 ( & V_70 -> V_100 , V_105 ) ;
goto V_82;
}
}
V_105 += 1 << V_94 ;
V_71 = ( V_71 + 1 ) & ( V_95 - 1 ) ;
}
V_70 -> V_98 = - 1 ;
V_82:
if ( ( V_70 -> V_78 -= V_72 ) == 0 )
F_63 ( & V_70 -> V_86 ) ;
#ifndef F_48
F_50 ( & V_79 , V_110 , V_72 ) ;
#endif
F_11 ( & V_70 -> V_75 ) ;
}
void F_74 ( struct V_4 * V_5 ,
struct V_69 * V_70 , int V_111 )
{
struct V_1 * V_2 ;
struct V_23 * V_30 ;
struct V_112 * V_113 ;
unsigned int V_71 ;
for ( V_71 = 0 ; V_71 <= V_5 -> V_114 ; V_71 ++ ) {
struct V_35 * V_115 = & V_5 -> V_116 [ V_71 ] ;
V_117:
F_75 () ;
V_118:
F_76 (sk, node, &head->chain) {
if ( V_30 -> V_119 != V_56 )
continue;
V_2 = F_77 ( V_30 ) ;
if ( ( V_2 -> V_62 != V_111 ) ||
F_15 ( & F_13 ( V_2 ) -> V_120 ) )
continue;
if ( F_78 ( ! F_79 ( & V_2 -> V_19 ) ) )
continue;
if ( F_78 ( ( V_2 -> V_62 != V_111 ) ||
F_15 ( & F_13 ( V_2 ) -> V_120 ) ) ) {
F_24 ( V_2 ) ;
goto V_118;
}
F_80 () ;
F_81 () ;
F_61 ( V_2 , V_70 ) ;
F_82 () ;
F_24 ( V_2 ) ;
goto V_117;
}
if ( F_83 ( V_113 ) != V_71 )
goto V_118;
F_80 () ;
}
}
