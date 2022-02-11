void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 )
return;
F_2 ( & V_2 -> V_8 ) ;
V_2 -> V_7 = NULL ;
F_3 ( V_4 -> V_9 , V_6 ) ;
F_4 ( (struct V_10 * ) V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_11 -> V_4 ;
T_1 * V_12 = F_6 ( V_4 , V_2 -> V_13 ) ;
struct V_14 * V_15 ;
F_7 ( V_12 ) ;
F_8 ( (struct V_10 * ) V_2 ) ;
F_9 ( V_12 ) ;
V_15 = & V_4 -> V_16 [ F_10 ( F_11 ( V_2 ) , V_2 -> V_17 ,
V_4 -> V_18 ) ] ;
F_7 ( & V_15 -> V_12 ) ;
F_1 ( V_2 , V_4 ) ;
F_9 ( & V_15 -> V_12 ) ;
F_12 ( & V_2 -> V_11 -> V_19 ) ;
F_13 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_22 -> V_21 ;
F_15 ( (struct V_10 * ) V_2 ) ;
#ifdef F_16
F_17 ( L_1 , V_2 -> V_22 -> V_23 , V_2 ) ;
#endif
F_18 ( V_2 -> V_22 -> V_24 -> V_25 , V_2 ) ;
F_19 ( V_21 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( F_20 ( & V_2 -> V_26 ) )
F_14 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_22 ( & V_2 -> V_29 , V_28 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_30 * V_28 )
{
F_24 ( & V_2 -> V_8 , V_28 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_10 * V_31 ,
struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_26 ( V_31 ) ;
const struct V_34 * V_35 = F_27 ( V_31 ) ;
struct V_36 * V_37 = V_36 ( V_4 , V_31 -> V_38 ) ;
T_1 * V_12 = F_6 ( V_4 , V_31 -> V_38 ) ;
struct V_14 * V_15 ;
V_15 = & V_4 -> V_16 [ F_10 ( F_11 ( V_2 ) , V_33 -> V_39 ,
V_4 -> V_18 ) ] ;
F_7 ( & V_15 -> V_12 ) ;
V_2 -> V_7 = V_35 -> V_40 ;
F_28 ( ! V_35 -> V_40 ) ;
F_23 ( V_2 , & V_2 -> V_7 -> V_41 ) ;
F_9 ( & V_15 -> V_12 ) ;
F_7 ( V_12 ) ;
F_29 ( & V_2 -> V_26 , 4 ) ;
F_21 ( V_2 , & V_37 -> V_42 ) ;
if ( F_30 ( V_31 ) )
F_31 ( F_32 ( V_31 ) , V_31 -> V_43 , - 1 ) ;
F_9 ( V_12 ) ;
}
static void F_33 ( unsigned long V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
if ( V_2 -> V_45 )
F_34 ( F_11 ( V_2 ) , V_46 ) ;
else
F_34 ( F_11 ( V_2 ) , V_47 ) ;
F_5 ( V_2 ) ;
}
struct V_1 * F_35 ( const struct V_10 * V_31 ,
struct V_48 * V_49 ,
const int V_50 )
{
struct V_1 * V_2 ;
if ( F_36 ( & V_49 -> V_19 ) >= V_49 -> V_51 )
return NULL ;
V_2 = F_37 ( V_31 -> V_52 -> V_24 -> V_25 ,
V_53 ) ;
if ( V_2 ) {
const struct V_32 * V_33 = F_26 ( V_31 ) ;
F_38 ( V_2 , V_54 ) ;
V_2 -> V_11 = V_49 ;
V_2 -> V_55 = V_33 -> V_56 ;
V_2 -> V_57 = V_33 -> V_58 ;
V_2 -> V_59 = V_31 -> V_60 ;
V_2 -> V_61 = V_33 -> V_62 ;
V_2 -> V_17 = V_33 -> V_39 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_50 ;
V_2 -> V_66 = V_33 -> V_67 ;
V_2 -> V_68 = V_33 -> V_69 ;
V_2 -> V_70 = V_31 -> V_71 ;
V_2 -> V_72 = V_31 -> V_73 ;
V_2 -> V_13 = V_31 -> V_38 ;
V_2 -> V_74 = 0 ;
V_2 -> V_75 = V_33 -> V_76 ;
V_2 -> V_22 = V_31 -> V_52 ;
F_39 ( & V_2 -> V_77 , F_40 ( & V_31 -> V_78 ) ) ;
F_41 ( V_2 , F_32 ( V_31 ) ) ;
F_42 ( & V_2 -> V_79 , F_33 , ( unsigned long ) V_2 ) ;
F_29 ( & V_2 -> V_26 , 0 ) ;
F_43 ( V_2 -> V_22 -> V_21 ) ;
}
return V_2 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_45 ( & V_2 -> V_79 ) )
F_5 ( V_2 ) ;
F_13 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 , int V_80 , bool V_81 )
{
V_2 -> V_45 = V_80 <= 4 * V_82 ;
if ( ! V_81 ) {
F_47 ( F_48 ( & V_2 -> V_79 , V_83 + V_80 ) ) ;
F_49 ( & V_2 -> V_11 -> V_19 ) ;
} else {
F_50 ( & V_2 -> V_79 , V_83 + V_80 ) ;
}
}
void F_51 ( struct V_3 * V_4 ,
struct V_48 * V_84 , int V_85 )
{
struct V_1 * V_2 ;
struct V_10 * V_31 ;
struct V_86 * V_87 ;
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 <= V_4 -> V_89 ; V_88 ++ ) {
struct V_36 * V_90 = & V_4 -> V_91 [ V_88 ] ;
V_92:
F_52 () ;
F_53 () ;
V_93:
F_54 (sk, node, &head->chain) {
if ( V_31 -> V_94 != V_64 )
continue;
V_2 = F_55 ( V_31 ) ;
if ( ( V_2 -> V_70 != V_85 ) ||
F_36 ( & F_11 ( V_2 ) -> V_95 ) )
continue;
if ( F_56 ( ! F_57 ( & V_2 -> V_26 ) ) )
continue;
if ( F_56 ( ( V_2 -> V_70 != V_85 ) ||
F_36 ( & F_11 ( V_2 ) -> V_95 ) ) ) {
F_13 ( V_2 ) ;
goto V_93;
}
F_58 () ;
F_59 () ;
F_44 ( V_2 ) ;
F_60 () ;
goto V_92;
}
if ( F_61 ( V_87 ) != V_88 )
goto V_93;
F_58 () ;
}
}
