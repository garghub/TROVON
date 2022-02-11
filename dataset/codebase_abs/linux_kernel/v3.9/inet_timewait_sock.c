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
#ifdef F_14
if ( F_15 ( & V_2 -> V_19 ) != 1 ) {
F_16 ( L_1 ,
V_2 -> V_20 -> V_21 , V_2 , F_15 ( & V_2 -> V_19 ) ) ;
}
#endif
while ( V_13 ) {
F_17 ( V_2 ) ;
V_13 -- ;
}
}
static T_2 void F_18 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_20 -> V_23 ;
F_19 ( (struct V_24 * ) V_2 ) ;
#ifdef F_14
F_16 ( L_2 , V_2 -> V_20 -> V_21 , V_2 ) ;
#endif
F_20 ( F_13 ( V_2 ) ) ;
F_21 ( V_2 -> V_20 -> V_25 -> V_26 , V_2 ) ;
F_22 ( V_23 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( F_23 ( & V_2 -> V_19 ) )
F_18 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_24 * V_27 ,
struct V_4 * V_5 )
{
const struct V_28 * V_29 = F_25 ( V_27 ) ;
const struct V_30 * V_31 = F_26 ( V_27 ) ;
struct V_32 * V_33 = V_32 ( V_5 , V_27 -> V_34 ) ;
T_1 * V_14 = F_9 ( V_5 , V_27 -> V_34 ) ;
struct V_11 * V_12 ;
V_12 = & V_5 -> V_16 [ F_12 ( F_13 ( V_2 ) , V_29 -> V_35 ,
V_5 -> V_18 ) ] ;
F_10 ( & V_12 -> V_14 ) ;
V_2 -> V_8 = V_31 -> V_36 ;
F_27 ( ! V_31 -> V_36 ) ;
F_28 ( V_2 , & V_2 -> V_8 -> V_37 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_10 ( V_14 ) ;
F_29 ( V_2 , & V_33 -> V_38 ) ;
if ( F_30 ( V_27 ) )
F_31 ( F_32 ( V_27 ) , V_27 -> V_39 , - 1 ) ;
F_33 ( 1 + 1 + 1 , & V_2 -> V_19 ) ;
F_11 ( V_14 ) ;
}
struct V_1 * F_34 ( const struct V_24 * V_27 , const int V_40 )
{
struct V_1 * V_2 =
F_35 ( V_27 -> V_41 -> V_25 -> V_26 ,
V_42 ) ;
if ( V_2 != NULL ) {
const struct V_28 * V_29 = F_25 ( V_27 ) ;
F_36 ( V_2 , V_43 ) ;
V_2 -> V_44 = V_29 -> V_45 ;
V_2 -> V_46 = V_29 -> V_47 ;
V_2 -> V_48 = V_27 -> V_49 ;
V_2 -> V_50 = V_29 -> V_51 ;
V_2 -> V_17 = V_29 -> V_35 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = V_40 ;
V_2 -> V_55 = V_29 -> V_56 ;
V_2 -> V_57 = V_29 -> V_58 ;
V_2 -> V_59 = V_27 -> V_60 ;
V_2 -> V_61 = V_27 -> V_62 ;
V_2 -> V_15 = V_27 -> V_34 ;
V_2 -> V_63 = 0 ;
V_2 -> V_64 = V_29 -> V_65 ;
V_2 -> V_20 = V_27 -> V_41 ;
F_37 ( V_2 , F_38 ( F_32 ( V_27 ) ) ) ;
F_39 ( & V_2 -> V_19 , 0 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 -> V_20 -> V_23 ) ;
}
return V_2 ;
}
static int F_42 ( struct V_66 * V_67 ,
const int V_68 )
{
struct V_1 * V_2 ;
unsigned int V_69 ;
int V_70 ;
V_69 = 0 ;
V_70 = 0 ;
V_71:
F_43 (tw, &twdr->cells[slot]) {
F_44 ( V_2 ) ;
F_11 ( & V_67 -> V_72 ) ;
F_8 ( V_2 , V_67 -> V_5 ) ;
#ifdef F_45
F_46 ( F_13 ( V_2 ) , V_73 ) ;
#endif
F_17 ( V_2 ) ;
V_69 ++ ;
F_10 ( & V_67 -> V_72 ) ;
if ( V_69 > V_74 ) {
V_70 = 1 ;
break;
}
goto V_71;
}
V_67 -> V_75 -= V_69 ;
#ifndef F_45
F_47 ( & V_76 , V_73 , V_69 ) ;
#endif
return V_70 ;
}
void F_48 ( unsigned long V_77 )
{
struct V_66 * V_67 ;
unsigned int V_78 ;
V_67 = (struct V_66 * ) V_77 ;
F_10 ( & V_67 -> V_72 ) ;
if ( V_67 -> V_75 == 0 )
goto V_79;
V_78 = 0 ;
if ( F_42 ( V_67 , V_67 -> V_68 ) ) {
V_67 -> V_80 |= ( 1 << V_67 -> V_68 ) ;
F_49 ( & V_67 -> V_81 ) ;
V_78 = 1 ;
} else {
if ( V_67 -> V_75 )
V_78 = 1 ;
V_67 -> V_68 = ( ( V_67 -> V_68 + 1 ) & ( V_82 - 1 ) ) ;
}
if ( V_78 )
F_50 ( & V_67 -> V_83 , V_84 + V_67 -> V_85 ) ;
V_79:
F_11 ( & V_67 -> V_72 ) ;
}
void F_51 ( struct V_86 * V_87 )
{
struct V_66 * V_67 =
F_52 ( V_87 , struct V_66 , V_81 ) ;
int V_88 ;
F_53 ( ( V_82 - 1 ) >
( sizeof( V_67 -> V_80 ) * 8 ) ) ;
while ( V_67 -> V_80 ) {
F_54 ( & V_67 -> V_72 ) ;
for ( V_88 = 0 ; V_88 < V_82 ; V_88 ++ ) {
if ( ! ( V_67 -> V_80 & ( 1 << V_88 ) ) )
continue;
while ( F_42 ( V_67 , V_88 ) != 0 ) {
if ( F_55 () ) {
F_56 ( & V_67 -> V_72 ) ;
F_57 () ;
F_54 ( & V_67 -> V_72 ) ;
}
}
V_67 -> V_80 &= ~ ( 1 << V_88 ) ;
}
F_56 ( & V_67 -> V_72 ) ;
}
}
void F_58 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
F_10 ( & V_67 -> V_72 ) ;
if ( F_59 ( V_2 ) ) {
F_17 ( V_2 ) ;
if ( -- V_67 -> V_75 == 0 )
F_60 ( & V_67 -> V_83 ) ;
}
F_11 ( & V_67 -> V_72 ) ;
F_8 ( V_2 , V_67 -> V_5 ) ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
const int V_89 , const int V_90 )
{
struct V_91 * V_92 ;
int V_68 ;
V_68 = ( V_89 + ( 1 << V_93 ) - 1 ) >> V_93 ;
F_10 ( & V_67 -> V_72 ) ;
if ( F_59 ( V_2 ) )
V_67 -> V_75 -- ;
else
F_62 ( & V_2 -> V_19 ) ;
if ( V_68 >= V_94 ) {
if ( V_89 >= V_90 ) {
V_68 = V_82 - 1 ;
} else {
V_68 = F_63 ( V_89 , V_67 -> V_85 ) ;
if ( V_68 >= V_82 )
V_68 = V_82 - 1 ;
}
V_2 -> V_95 = V_84 + V_89 ;
V_68 = ( V_67 -> V_68 + V_68 ) & ( V_82 - 1 ) ;
V_92 = & V_67 -> V_96 [ V_68 ] ;
} else {
V_2 -> V_95 = V_84 + ( V_68 << V_93 ) ;
if ( V_67 -> V_97 < 0 ) {
V_67 -> V_97 = 0 ;
V_67 -> V_98 = V_84 ;
V_67 -> V_99 . V_100 = V_67 -> V_98 +
( V_68 << V_93 ) ;
F_64 ( & V_67 -> V_99 ) ;
} else {
if ( F_65 ( V_67 -> V_99 . V_100 ,
V_84 + ( V_68 << V_93 ) ) )
F_50 ( & V_67 -> V_99 ,
V_84 + ( V_68 << V_93 ) ) ;
V_68 = ( V_67 -> V_97 + V_68 ) & ( V_94 - 1 ) ;
}
V_92 = & V_67 -> V_101 [ V_68 ] ;
}
F_66 ( & V_2 -> V_102 , V_92 ) ;
if ( V_67 -> V_75 ++ == 0 )
F_50 ( & V_67 -> V_83 , V_84 + V_67 -> V_85 ) ;
F_11 ( & V_67 -> V_72 ) ;
}
void F_67 ( unsigned long V_77 )
{
struct V_66 * V_67 ;
int V_103 , V_68 ;
unsigned long V_104 ;
unsigned long V_105 = V_84 ;
int V_69 = 0 ;
int V_106 = 0 ;
V_67 = (struct V_66 * ) V_77 ;
F_10 ( & V_67 -> V_72 ) ;
if ( V_67 -> V_97 < 0 )
goto V_79;
V_68 = V_67 -> V_97 ;
V_104 = V_67 -> V_98 ;
for ( V_103 = 0 ; V_103 < V_94 ; V_103 ++ ) {
if ( F_68 ( V_104 , V_105 ) ) {
struct V_107 * V_108 ;
struct V_1 * V_2 ;
F_69 (tw, safe,
&twdr->twcal_row[slot]) {
F_44 ( V_2 ) ;
F_8 ( V_2 , V_67 -> V_5 ) ;
#ifdef F_45
F_46 ( F_13 ( V_2 ) , V_109 ) ;
#endif
F_17 ( V_2 ) ;
V_69 ++ ;
}
} else {
if ( ! V_106 ) {
V_106 = 1 ;
V_67 -> V_98 = V_104 ;
V_67 -> V_97 = V_68 ;
}
if ( ! F_70 ( & V_67 -> V_101 [ V_68 ] ) ) {
F_50 ( & V_67 -> V_99 , V_104 ) ;
goto V_79;
}
}
V_104 += 1 << V_93 ;
V_68 = ( V_68 + 1 ) & ( V_94 - 1 ) ;
}
V_67 -> V_97 = - 1 ;
V_79:
if ( ( V_67 -> V_75 -= V_69 ) == 0 )
F_60 ( & V_67 -> V_83 ) ;
#ifndef F_45
F_47 ( & V_76 , V_109 , V_69 ) ;
#endif
F_11 ( & V_67 -> V_72 ) ;
}
void F_71 ( struct V_4 * V_5 ,
struct V_66 * V_67 , int V_110 )
{
struct V_1 * V_2 ;
struct V_24 * V_27 ;
struct V_111 * V_112 ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 <= V_5 -> V_113 ; V_68 ++ ) {
struct V_32 * V_114 = & V_5 -> V_115 [ V_68 ] ;
V_116:
F_72 () ;
V_117:
F_73 (sk, node, &head->twchain) {
V_2 = F_74 ( V_27 ) ;
if ( ( V_2 -> V_59 != V_110 ) ||
F_15 ( & F_13 ( V_2 ) -> V_118 ) )
continue;
if ( F_75 ( ! F_76 ( & V_2 -> V_19 ) ) )
continue;
if ( F_75 ( ( V_2 -> V_59 != V_110 ) ||
F_15 ( & F_13 ( V_2 ) -> V_118 ) ) ) {
F_17 ( V_2 ) ;
goto V_117;
}
F_77 () ;
F_78 () ;
F_58 ( V_2 , V_67 ) ;
F_79 () ;
F_17 ( V_2 ) ;
goto V_116;
}
if ( F_80 ( V_112 ) != V_68 )
goto V_117;
F_77 () ;
}
}
