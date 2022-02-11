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
F_16 ( V_20 L_1 ,
V_2 -> V_21 -> V_22 , V_2 , F_15 ( & V_2 -> V_19 ) ) ;
}
#endif
while ( V_13 ) {
F_17 ( V_2 ) ;
V_13 -- ;
}
}
static T_2 void F_18 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_21 -> V_24 ;
F_19 ( (struct V_25 * ) V_2 ) ;
#ifdef F_14
F_20 ( L_2 , V_2 -> V_21 -> V_22 , V_2 ) ;
#endif
F_21 ( F_13 ( V_2 ) ) ;
F_22 ( V_2 -> V_21 -> V_26 -> V_27 , V_2 ) ;
F_23 ( V_24 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( F_24 ( & V_2 -> V_19 ) )
F_18 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_25 * V_28 ,
struct V_4 * V_5 )
{
const struct V_29 * V_30 = F_26 ( V_28 ) ;
const struct V_31 * V_32 = F_27 ( V_28 ) ;
struct V_33 * V_34 = V_33 ( V_5 , V_28 -> V_35 ) ;
T_1 * V_14 = F_9 ( V_5 , V_28 -> V_35 ) ;
struct V_11 * V_12 ;
V_12 = & V_5 -> V_16 [ F_12 ( F_13 ( V_2 ) , V_30 -> V_36 ,
V_5 -> V_18 ) ] ;
F_10 ( & V_12 -> V_14 ) ;
V_2 -> V_8 = V_32 -> V_37 ;
F_28 ( ! V_32 -> V_37 ) ;
F_29 ( V_2 , & V_2 -> V_8 -> V_38 ) ;
F_11 ( & V_12 -> V_14 ) ;
F_10 ( V_14 ) ;
F_30 ( V_2 , & V_34 -> V_39 ) ;
if ( F_31 ( V_28 ) )
F_32 ( F_33 ( V_28 ) , V_28 -> V_40 , - 1 ) ;
F_34 ( 1 + 1 + 1 , & V_2 -> V_19 ) ;
F_11 ( V_14 ) ;
}
struct V_1 * F_35 ( const struct V_25 * V_28 , const int V_41 )
{
struct V_1 * V_2 =
F_36 ( V_28 -> V_42 -> V_26 -> V_27 ,
V_43 ) ;
if ( V_2 != NULL ) {
const struct V_29 * V_30 = F_26 ( V_28 ) ;
F_37 ( V_2 , V_44 ) ;
V_2 -> V_45 = V_30 -> V_46 ;
V_2 -> V_47 = V_30 -> V_48 ;
V_2 -> V_49 = V_28 -> V_50 ;
V_2 -> V_51 = V_30 -> V_52 ;
V_2 -> V_17 = V_30 -> V_36 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = V_41 ;
V_2 -> V_56 = V_30 -> V_57 ;
V_2 -> V_58 = V_30 -> V_59 ;
V_2 -> V_60 = V_28 -> V_61 ;
V_2 -> V_62 = V_28 -> V_63 ;
V_2 -> V_15 = V_28 -> V_35 ;
V_2 -> V_64 = 0 ;
V_2 -> V_65 = V_30 -> V_66 ;
V_2 -> V_21 = V_28 -> V_42 ;
F_38 ( V_2 , F_39 ( F_33 ( V_28 ) ) ) ;
F_40 ( & V_2 -> V_19 , 0 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 -> V_21 -> V_24 ) ;
}
return V_2 ;
}
static int F_43 ( struct V_67 * V_68 ,
const int V_69 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
unsigned int V_72 ;
int V_73 ;
V_72 = 0 ;
V_73 = 0 ;
V_74:
F_44 (tw, node, &twdr->cells[slot]) {
F_45 ( V_2 ) ;
F_11 ( & V_68 -> V_75 ) ;
F_8 ( V_2 , V_68 -> V_5 ) ;
#ifdef F_46
F_47 ( F_13 ( V_2 ) , V_76 ) ;
#endif
F_17 ( V_2 ) ;
V_72 ++ ;
F_10 ( & V_68 -> V_75 ) ;
if ( V_72 > V_77 ) {
V_73 = 1 ;
break;
}
goto V_74;
}
V_68 -> V_78 -= V_72 ;
#ifndef F_46
F_48 ( & V_79 , V_76 , V_72 ) ;
#endif
return V_73 ;
}
void F_49 ( unsigned long V_80 )
{
struct V_67 * V_68 ;
int unsigned V_81 ;
V_68 = (struct V_67 * ) V_80 ;
F_10 ( & V_68 -> V_75 ) ;
if ( V_68 -> V_78 == 0 )
goto V_82;
V_81 = 0 ;
if ( F_43 ( V_68 , V_68 -> V_69 ) ) {
V_68 -> V_83 |= ( 1 << V_68 -> V_69 ) ;
F_50 ( & V_68 -> V_84 ) ;
V_81 = 1 ;
} else {
if ( V_68 -> V_78 )
V_81 = 1 ;
V_68 -> V_69 = ( ( V_68 -> V_69 + 1 ) & ( V_85 - 1 ) ) ;
}
if ( V_81 )
F_51 ( & V_68 -> V_86 , V_87 + V_68 -> V_88 ) ;
V_82:
F_11 ( & V_68 -> V_75 ) ;
}
void F_52 ( struct V_89 * V_90 )
{
struct V_67 * V_68 =
F_53 ( V_90 , struct V_67 , V_84 ) ;
int V_91 ;
F_54 ( ( V_85 - 1 ) >
( sizeof( V_68 -> V_83 ) * 8 ) ) ;
while ( V_68 -> V_83 ) {
F_55 ( & V_68 -> V_75 ) ;
for ( V_91 = 0 ; V_91 < V_85 ; V_91 ++ ) {
if ( ! ( V_68 -> V_83 & ( 1 << V_91 ) ) )
continue;
while ( F_43 ( V_68 , V_91 ) != 0 ) {
if ( F_56 () ) {
F_57 ( & V_68 -> V_75 ) ;
F_58 () ;
F_55 ( & V_68 -> V_75 ) ;
}
}
V_68 -> V_83 &= ~ ( 1 << V_91 ) ;
}
F_57 ( & V_68 -> V_75 ) ;
}
}
void F_59 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
F_10 ( & V_68 -> V_75 ) ;
if ( F_60 ( V_2 ) ) {
F_17 ( V_2 ) ;
if ( -- V_68 -> V_78 == 0 )
F_61 ( & V_68 -> V_86 ) ;
}
F_11 ( & V_68 -> V_75 ) ;
F_8 ( V_2 , V_68 -> V_5 ) ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
const int V_92 , const int V_93 )
{
struct V_94 * V_95 ;
int V_69 ;
V_69 = ( V_92 + ( 1 << V_96 ) - 1 ) >> V_96 ;
F_10 ( & V_68 -> V_75 ) ;
if ( F_60 ( V_2 ) )
V_68 -> V_78 -- ;
else
F_63 ( & V_2 -> V_19 ) ;
if ( V_69 >= V_97 ) {
if ( V_92 >= V_93 ) {
V_69 = V_85 - 1 ;
} else {
V_69 = F_64 ( V_92 , V_68 -> V_88 ) ;
if ( V_69 >= V_85 )
V_69 = V_85 - 1 ;
}
V_2 -> V_98 = V_87 + V_92 ;
V_69 = ( V_68 -> V_69 + V_69 ) & ( V_85 - 1 ) ;
V_95 = & V_68 -> V_99 [ V_69 ] ;
} else {
V_2 -> V_98 = V_87 + ( V_69 << V_96 ) ;
if ( V_68 -> V_100 < 0 ) {
V_68 -> V_100 = 0 ;
V_68 -> V_101 = V_87 ;
V_68 -> V_102 . V_103 = V_68 -> V_101 +
( V_69 << V_96 ) ;
F_65 ( & V_68 -> V_102 ) ;
} else {
if ( F_66 ( V_68 -> V_102 . V_103 ,
V_87 + ( V_69 << V_96 ) ) )
F_51 ( & V_68 -> V_102 ,
V_87 + ( V_69 << V_96 ) ) ;
V_69 = ( V_68 -> V_100 + V_69 ) & ( V_97 - 1 ) ;
}
V_95 = & V_68 -> V_104 [ V_69 ] ;
}
F_67 ( & V_2 -> V_105 , V_95 ) ;
if ( V_68 -> V_78 ++ == 0 )
F_51 ( & V_68 -> V_86 , V_87 + V_68 -> V_88 ) ;
F_11 ( & V_68 -> V_75 ) ;
}
void F_68 ( unsigned long V_80 )
{
struct V_67 * V_68 ;
int V_106 , V_69 ;
unsigned long V_107 ;
unsigned long V_108 = V_87 ;
int V_72 = 0 ;
int V_109 = 0 ;
V_68 = (struct V_67 * ) V_80 ;
F_10 ( & V_68 -> V_75 ) ;
if ( V_68 -> V_100 < 0 )
goto V_82;
V_69 = V_68 -> V_100 ;
V_107 = V_68 -> V_101 ;
for ( V_106 = 0 ; V_106 < V_97 ; V_106 ++ ) {
if ( F_69 ( V_107 , V_108 ) ) {
struct V_70 * V_71 , * V_110 ;
struct V_1 * V_2 ;
F_70 (tw, node, safe,
&twdr->twcal_row[slot]) {
F_45 ( V_2 ) ;
F_8 ( V_2 , V_68 -> V_5 ) ;
#ifdef F_46
F_47 ( F_13 ( V_2 ) , V_111 ) ;
#endif
F_17 ( V_2 ) ;
V_72 ++ ;
}
} else {
if ( ! V_109 ) {
V_109 = 1 ;
V_68 -> V_101 = V_107 ;
V_68 -> V_100 = V_69 ;
}
if ( ! F_71 ( & V_68 -> V_104 [ V_69 ] ) ) {
F_51 ( & V_68 -> V_102 , V_107 ) ;
goto V_82;
}
}
V_107 += 1 << V_96 ;
V_69 = ( V_69 + 1 ) & ( V_97 - 1 ) ;
}
V_68 -> V_100 = - 1 ;
V_82:
if ( ( V_68 -> V_78 -= V_72 ) == 0 )
F_61 ( & V_68 -> V_86 ) ;
#ifndef F_46
F_48 ( & V_79 , V_111 , V_72 ) ;
#endif
F_11 ( & V_68 -> V_75 ) ;
}
void F_72 ( struct V_4 * V_5 ,
struct V_67 * V_68 , int V_112 )
{
struct V_1 * V_2 ;
struct V_25 * V_28 ;
struct V_113 * V_71 ;
unsigned int V_69 ;
for ( V_69 = 0 ; V_69 <= V_5 -> V_114 ; V_69 ++ ) {
struct V_33 * V_115 = & V_5 -> V_116 [ V_69 ] ;
V_117:
F_73 () ;
V_118:
F_74 (sk, node, &head->twchain) {
V_2 = F_75 ( V_28 ) ;
if ( ( V_2 -> V_60 != V_112 ) ||
F_15 ( & F_13 ( V_2 ) -> V_119 ) )
continue;
if ( F_76 ( ! F_77 ( & V_2 -> V_19 ) ) )
continue;
if ( F_76 ( ( V_2 -> V_60 != V_112 ) ||
F_15 ( & F_13 ( V_2 ) -> V_119 ) ) ) {
F_17 ( V_2 ) ;
goto V_118;
}
F_78 () ;
F_79 () ;
F_59 ( V_2 , V_68 ) ;
F_80 () ;
F_17 ( V_2 ) ;
goto V_117;
}
if ( F_81 ( V_71 ) != V_69 )
goto V_118;
F_78 () ;
}
}
