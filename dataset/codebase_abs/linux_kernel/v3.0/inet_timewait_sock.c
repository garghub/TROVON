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
V_2 -> V_17 = V_30 -> V_36 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = V_41 ;
V_2 -> V_54 = V_30 -> V_55 ;
V_2 -> V_56 = V_30 -> V_57 ;
V_2 -> V_58 = V_28 -> V_59 ;
V_2 -> V_60 = V_28 -> V_61 ;
V_2 -> V_15 = V_28 -> V_35 ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = V_30 -> V_64 ;
V_2 -> V_21 = V_28 -> V_42 ;
F_38 ( V_2 , F_39 ( F_33 ( V_28 ) ) ) ;
F_40 ( & V_2 -> V_19 , 0 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 -> V_21 -> V_24 ) ;
}
return V_2 ;
}
static int F_43 ( struct V_65 * V_66 ,
const int V_67 )
{
struct V_1 * V_2 ;
struct V_68 * V_69 ;
unsigned int V_70 ;
int V_71 ;
V_70 = 0 ;
V_71 = 0 ;
V_72:
F_44 (tw, node, &twdr->cells[slot]) {
F_45 ( V_2 ) ;
F_11 ( & V_66 -> V_73 ) ;
F_8 ( V_2 , V_66 -> V_5 ) ;
#ifdef F_46
F_47 ( F_13 ( V_2 ) , V_74 ) ;
#endif
F_17 ( V_2 ) ;
V_70 ++ ;
F_10 ( & V_66 -> V_73 ) ;
if ( V_70 > V_75 ) {
V_71 = 1 ;
break;
}
goto V_72;
}
V_66 -> V_76 -= V_70 ;
#ifndef F_46
F_48 ( & V_77 , V_74 , V_70 ) ;
#endif
return V_71 ;
}
void F_49 ( unsigned long V_78 )
{
struct V_65 * V_66 ;
int unsigned V_79 ;
V_66 = (struct V_65 * ) V_78 ;
F_10 ( & V_66 -> V_73 ) ;
if ( V_66 -> V_76 == 0 )
goto V_80;
V_79 = 0 ;
if ( F_43 ( V_66 , V_66 -> V_67 ) ) {
V_66 -> V_81 |= ( 1 << V_66 -> V_67 ) ;
F_50 ( & V_66 -> V_82 ) ;
V_79 = 1 ;
} else {
if ( V_66 -> V_76 )
V_79 = 1 ;
V_66 -> V_67 = ( ( V_66 -> V_67 + 1 ) & ( V_83 - 1 ) ) ;
}
if ( V_79 )
F_51 ( & V_66 -> V_84 , V_85 + V_66 -> V_86 ) ;
V_80:
F_11 ( & V_66 -> V_73 ) ;
}
void F_52 ( struct V_87 * V_88 )
{
struct V_65 * V_66 =
F_53 ( V_88 , struct V_65 , V_82 ) ;
int V_89 ;
F_54 ( ( V_83 - 1 ) >
( sizeof( V_66 -> V_81 ) * 8 ) ) ;
while ( V_66 -> V_81 ) {
F_55 ( & V_66 -> V_73 ) ;
for ( V_89 = 0 ; V_89 < V_83 ; V_89 ++ ) {
if ( ! ( V_66 -> V_81 & ( 1 << V_89 ) ) )
continue;
while ( F_43 ( V_66 , V_89 ) != 0 ) {
if ( F_56 () ) {
F_57 ( & V_66 -> V_73 ) ;
F_58 () ;
F_55 ( & V_66 -> V_73 ) ;
}
}
V_66 -> V_81 &= ~ ( 1 << V_89 ) ;
}
F_57 ( & V_66 -> V_73 ) ;
}
}
void F_59 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
F_10 ( & V_66 -> V_73 ) ;
if ( F_60 ( V_2 ) ) {
F_17 ( V_2 ) ;
if ( -- V_66 -> V_76 == 0 )
F_61 ( & V_66 -> V_84 ) ;
}
F_11 ( & V_66 -> V_73 ) ;
F_8 ( V_2 , V_66 -> V_5 ) ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
const int V_90 , const int V_91 )
{
struct V_92 * V_93 ;
int V_67 ;
V_67 = ( V_90 + ( 1 << V_94 ) - 1 ) >> V_94 ;
F_10 ( & V_66 -> V_73 ) ;
if ( F_60 ( V_2 ) )
V_66 -> V_76 -- ;
else
F_63 ( & V_2 -> V_19 ) ;
if ( V_67 >= V_95 ) {
if ( V_90 >= V_91 ) {
V_67 = V_83 - 1 ;
} else {
V_67 = F_64 ( V_90 , V_66 -> V_86 ) ;
if ( V_67 >= V_83 )
V_67 = V_83 - 1 ;
}
V_2 -> V_96 = V_85 + V_90 ;
V_67 = ( V_66 -> V_67 + V_67 ) & ( V_83 - 1 ) ;
V_93 = & V_66 -> V_97 [ V_67 ] ;
} else {
V_2 -> V_96 = V_85 + ( V_67 << V_94 ) ;
if ( V_66 -> V_98 < 0 ) {
V_66 -> V_98 = 0 ;
V_66 -> V_99 = V_85 ;
V_66 -> V_100 . V_101 = V_66 -> V_99 +
( V_67 << V_94 ) ;
F_65 ( & V_66 -> V_100 ) ;
} else {
if ( F_66 ( V_66 -> V_100 . V_101 ,
V_85 + ( V_67 << V_94 ) ) )
F_51 ( & V_66 -> V_100 ,
V_85 + ( V_67 << V_94 ) ) ;
V_67 = ( V_66 -> V_98 + V_67 ) & ( V_95 - 1 ) ;
}
V_93 = & V_66 -> V_102 [ V_67 ] ;
}
F_67 ( & V_2 -> V_103 , V_93 ) ;
if ( V_66 -> V_76 ++ == 0 )
F_51 ( & V_66 -> V_84 , V_85 + V_66 -> V_86 ) ;
F_11 ( & V_66 -> V_73 ) ;
}
void F_68 ( unsigned long V_78 )
{
struct V_65 * V_66 ;
int V_104 , V_67 ;
unsigned long V_105 ;
unsigned long V_106 = V_85 ;
int V_70 = 0 ;
int V_107 = 0 ;
V_66 = (struct V_65 * ) V_78 ;
F_10 ( & V_66 -> V_73 ) ;
if ( V_66 -> V_98 < 0 )
goto V_80;
V_67 = V_66 -> V_98 ;
V_105 = V_66 -> V_99 ;
for ( V_104 = 0 ; V_104 < V_95 ; V_104 ++ ) {
if ( F_69 ( V_105 , V_106 ) ) {
struct V_68 * V_69 , * V_108 ;
struct V_1 * V_2 ;
F_70 (tw, node, safe,
&twdr->twcal_row[slot]) {
F_45 ( V_2 ) ;
F_8 ( V_2 , V_66 -> V_5 ) ;
#ifdef F_46
F_47 ( F_13 ( V_2 ) , V_109 ) ;
#endif
F_17 ( V_2 ) ;
V_70 ++ ;
}
} else {
if ( ! V_107 ) {
V_107 = 1 ;
V_66 -> V_99 = V_105 ;
V_66 -> V_98 = V_67 ;
}
if ( ! F_71 ( & V_66 -> V_102 [ V_67 ] ) ) {
F_51 ( & V_66 -> V_100 , V_105 ) ;
goto V_80;
}
}
V_105 += 1 << V_94 ;
V_67 = ( V_67 + 1 ) & ( V_95 - 1 ) ;
}
V_66 -> V_98 = - 1 ;
V_80:
if ( ( V_66 -> V_76 -= V_70 ) == 0 )
F_61 ( & V_66 -> V_84 ) ;
#ifndef F_46
F_48 ( & V_77 , V_109 , V_70 ) ;
#endif
F_11 ( & V_66 -> V_73 ) ;
}
void F_72 ( struct V_4 * V_5 ,
struct V_65 * V_66 , int V_110 )
{
struct V_1 * V_2 ;
struct V_25 * V_28 ;
struct V_111 * V_69 ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 <= V_5 -> V_112 ; V_67 ++ ) {
struct V_33 * V_113 = & V_5 -> V_114 [ V_67 ] ;
V_115:
F_73 () ;
V_116:
F_74 (sk, node, &head->twchain) {
V_2 = F_75 ( V_28 ) ;
if ( ( V_2 -> V_58 != V_110 ) ||
F_15 ( & F_13 ( V_2 ) -> V_117 ) )
continue;
if ( F_76 ( ! F_77 ( & V_2 -> V_19 ) ) )
continue;
if ( F_76 ( ( V_2 -> V_58 != V_110 ) ||
F_15 ( & F_13 ( V_2 ) -> V_117 ) ) ) {
F_17 ( V_2 ) ;
goto V_116;
}
F_78 () ;
F_79 () ;
F_59 ( V_2 , V_66 ) ;
F_80 () ;
F_17 ( V_2 ) ;
goto V_115;
}
if ( F_81 ( V_69 ) != V_67 )
goto V_116;
F_78 () ;
}
}
