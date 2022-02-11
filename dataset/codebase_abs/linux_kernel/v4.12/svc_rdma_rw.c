static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_4 ) ;
}
static struct V_1 *
F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
struct V_1 * V_8 ;
F_4 ( & V_6 -> V_9 ) ;
V_8 = F_1 ( & V_6 -> V_10 ) ;
if ( V_8 ) {
F_5 ( & V_8 -> V_4 ) ;
F_6 ( & V_6 -> V_9 ) ;
} else {
F_6 ( & V_6 -> V_9 ) ;
V_8 = F_7 ( sizeof( * V_8 ) +
V_11 * sizeof( struct V_12 ) ,
V_13 ) ;
if ( ! V_8 )
goto V_14;
F_8 ( & V_8 -> V_4 ) ;
}
V_8 -> V_15 . V_16 = V_8 -> V_17 ;
if ( F_9 ( & V_8 -> V_15 , V_7 ,
V_8 -> V_15 . V_16 ) ) {
F_10 ( V_8 ) ;
V_8 = NULL ;
}
V_14:
return V_8 ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_1 * V_8 )
{
F_12 ( & V_8 -> V_15 , true ) ;
F_4 ( & V_6 -> V_9 ) ;
F_13 ( & V_8 -> V_4 , & V_6 -> V_10 ) ;
F_6 ( & V_6 -> V_9 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_8 ;
while ( ( V_8 = F_1 ( & V_6 -> V_10 ) ) != NULL ) {
F_5 ( & V_8 -> V_4 ) ;
F_10 ( V_8 ) ;
}
}
static void F_15 ( struct V_5 * V_6 ,
struct V_18 * V_19 ,
enum V_20 V_21 )
{
V_19 -> V_22 = V_6 ;
F_16 ( & V_6 -> V_23 ) ;
F_8 ( & V_19 -> V_24 ) ;
V_19 -> V_25 = 0 ;
V_19 -> V_26 = V_21 ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_22 ;
struct V_1 * V_8 ;
while ( ( V_8 = F_1 ( & V_19 -> V_24 ) ) != NULL ) {
F_5 ( & V_8 -> V_4 ) ;
F_18 ( & V_8 -> V_27 , V_6 -> V_28 ,
V_6 -> V_29 , V_8 -> V_15 . V_16 ,
V_8 -> V_30 , V_19 -> V_26 ) ;
F_11 ( V_6 , V_8 ) ;
}
F_19 ( & V_6 -> V_23 ) ;
}
static struct V_31 *
F_20 ( struct V_5 * V_6 , T_1 * V_32 )
{
struct V_31 * V_33 ;
V_33 = F_7 ( sizeof( * V_33 ) , V_13 ) ;
if ( ! V_33 )
return V_33 ;
V_33 -> V_34 = 0 ;
V_33 -> V_35 = 0 ;
V_33 -> V_36 = F_21 ( ++ V_32 ) ;
V_33 -> V_37 = ++ V_32 ;
F_15 ( V_6 , & V_33 -> V_38 , V_39 ) ;
return V_33 ;
}
static void F_22 ( struct V_31 * V_33 )
{
F_17 ( & V_33 -> V_38 ) ;
F_10 ( V_33 ) ;
}
static void F_23 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_18 * V_19 =
F_24 ( V_45 , struct V_18 , V_47 ) ;
struct V_5 * V_6 = V_19 -> V_22 ;
struct V_31 * V_33 =
F_24 ( V_19 , struct V_31 , V_38 ) ;
F_25 ( V_19 -> V_25 , & V_6 -> V_48 ) ;
F_26 ( & V_6 -> V_49 ) ;
if ( F_27 ( V_43 -> V_50 != V_51 ) ) {
F_28 ( V_52 , & V_6 -> V_23 . V_53 ) ;
if ( V_43 -> V_50 != V_54 )
F_29 ( L_1 ,
F_30 ( V_43 -> V_50 ) ,
V_43 -> V_50 , V_43 -> V_55 ) ;
}
F_22 ( V_33 ) ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_22 ;
struct V_56 * V_57 = & V_6 -> V_23 ;
struct V_58 * V_59 , * V_60 ;
struct V_2 * V_61 ;
struct V_44 * V_45 ;
int V_62 ;
V_59 = NULL ;
V_45 = & V_19 -> V_47 ;
F_32 (tmp, &cc->cc_rwctxts) {
struct V_1 * V_8 ;
V_8 = F_33 ( V_61 , struct V_1 , V_4 ) ;
V_59 = F_34 ( & V_8 -> V_27 , V_6 -> V_28 ,
V_6 -> V_29 , V_45 , V_59 ) ;
V_45 = NULL ;
}
do {
if ( F_35 ( V_19 -> V_25 ,
& V_6 -> V_48 ) > 0 ) {
V_62 = F_36 ( V_6 -> V_28 , V_59 , & V_60 ) ;
if ( V_62 )
break;
return 0 ;
}
F_37 ( & V_63 ) ;
F_25 ( V_19 -> V_25 , & V_6 -> V_48 ) ;
F_38 ( V_6 -> V_49 ,
F_39 ( & V_6 -> V_48 ) > V_19 -> V_25 ) ;
} while ( 1 );
F_29 ( L_2 , V_62 ) ;
F_28 ( V_52 , & V_57 -> V_53 ) ;
if ( V_60 != V_59 )
return 0 ;
F_25 ( V_19 -> V_25 , & V_6 -> V_48 ) ;
F_26 ( & V_6 -> V_49 ) ;
return - V_64 ;
}
static void F_40 ( struct V_31 * V_33 ,
unsigned int V_65 ,
struct V_1 * V_8 )
{
struct V_12 * V_66 = V_8 -> V_15 . V_16 ;
F_41 ( & V_66 [ 0 ] , V_33 -> V_67 , V_65 ) ;
V_33 -> V_67 += V_65 ;
V_8 -> V_30 = 1 ;
}
static void F_42 ( struct V_31 * V_33 ,
unsigned int V_68 ,
struct V_1 * V_8 )
{
unsigned int V_69 , V_70 , V_71 , V_72 ;
struct V_73 * V_74 = V_33 -> V_75 ;
struct V_12 * V_66 ;
struct V_76 * * V_76 ;
V_71 = ( V_33 -> V_77 + V_74 -> V_78 ) & ~ V_79 ;
V_72 = ( V_33 -> V_77 + V_74 -> V_78 ) >> V_80 ;
V_76 = V_74 -> V_81 + V_72 ;
V_33 -> V_77 += V_68 ;
V_66 = V_8 -> V_15 . V_16 ;
V_69 = 0 ;
do {
V_70 = F_43 (unsigned int, remaining,
PAGE_SIZE - page_off) ;
F_44 ( V_66 , * V_76 , V_70 , V_71 ) ;
V_68 -= V_70 ;
V_66 = F_45 ( V_66 ) ;
V_71 = 0 ;
V_69 ++ ;
V_76 ++ ;
} while ( V_68 );
V_8 -> V_30 = V_69 ;
}
static int
F_46 ( struct V_31 * V_33 ,
void (* F_47)( struct V_31 * V_33 ,
unsigned int V_65 ,
struct V_1 * V_8 ) ,
unsigned int V_68 )
{
struct V_18 * V_19 = & V_33 -> V_38 ;
struct V_5 * V_6 = V_19 -> V_22 ;
struct V_1 * V_8 ;
T_1 * V_82 ;
int V_62 ;
V_19 -> V_47 . V_83 = F_23 ;
V_82 = V_33 -> V_37 + V_33 -> V_35 * V_84 ;
do {
unsigned int V_85 ;
T_2 V_86 , V_87 ;
T_3 V_88 ;
if ( V_33 -> V_35 >= V_33 -> V_36 )
goto V_89;
V_87 = F_21 ( V_82 ) ;
V_86 = F_21 ( V_82 + 1 ) ;
F_48 ( V_82 + 2 , & V_88 ) ;
V_88 += V_33 -> V_34 ;
V_85 = F_49 ( V_68 , V_86 - V_33 -> V_34 ) ;
V_8 = F_3 ( V_6 ,
( V_85 >> V_80 ) + 2 ) ;
if ( ! V_8 )
goto V_90;
F_47 ( V_33 , V_85 , V_8 ) ;
V_62 = F_50 ( & V_8 -> V_27 , V_6 -> V_28 ,
V_6 -> V_29 , V_8 -> V_15 . V_16 ,
V_8 -> V_30 , 0 , V_88 ,
V_87 , V_39 ) ;
if ( V_62 < 0 )
goto V_91;
F_13 ( & V_8 -> V_4 , & V_19 -> V_24 ) ;
V_19 -> V_25 += V_62 ;
if ( V_85 == V_86 - V_33 -> V_34 ) {
V_82 += 4 ;
V_33 -> V_35 ++ ;
V_33 -> V_34 = 0 ;
} else {
V_33 -> V_34 += V_85 ;
}
V_68 -= V_85 ;
} while ( V_68 );
return 0 ;
V_89:
F_51 ( L_3 ,
V_33 -> V_36 ) ;
return - V_92 ;
V_90:
F_51 ( L_4 ) ;
return - V_93 ;
V_91:
F_11 ( V_6 , V_8 ) ;
F_29 ( L_5 , V_62 ) ;
return - V_94 ;
}
static int F_52 ( struct V_31 * V_33 ,
struct V_95 * V_96 )
{
V_33 -> V_67 = V_96 -> V_97 ;
return F_46 ( V_33 , F_40 ,
V_96 -> V_98 ) ;
}
static int F_53 ( struct V_31 * V_33 ,
struct V_73 * V_74 )
{
V_33 -> V_75 = V_74 ;
V_33 -> V_77 = 0 ;
return F_46 ( V_33 , F_42 ,
V_74 -> V_99 ) ;
}
int F_54 ( struct V_5 * V_6 , T_1 * V_100 ,
struct V_73 * V_74 )
{
struct V_31 * V_33 ;
int V_62 ;
if ( ! V_74 -> V_99 )
return 0 ;
V_33 = F_20 ( V_6 , V_100 ) ;
if ( ! V_33 )
return - V_93 ;
V_62 = F_53 ( V_33 , V_74 ) ;
if ( V_62 < 0 )
goto V_101;
V_62 = F_31 ( & V_33 -> V_38 ) ;
if ( V_62 < 0 )
goto V_101;
return V_74 -> V_99 ;
V_101:
F_22 ( V_33 ) ;
return V_62 ;
}
int F_55 ( struct V_5 * V_6 , T_1 * V_102 ,
bool V_103 , struct V_73 * V_74 )
{
struct V_31 * V_33 ;
int V_104 , V_62 ;
V_33 = F_20 ( V_6 , V_102 ) ;
if ( ! V_33 )
return - V_93 ;
V_62 = F_52 ( V_33 , & V_74 -> V_105 [ 0 ] ) ;
if ( V_62 < 0 )
goto V_101;
V_104 = V_74 -> V_105 [ 0 ] . V_98 ;
if ( ! V_103 && V_74 -> V_99 ) {
V_62 = F_53 ( V_33 , V_74 ) ;
if ( V_62 < 0 )
goto V_101;
V_104 += V_74 -> V_99 ;
}
if ( V_74 -> V_106 [ 0 ] . V_98 ) {
V_62 = F_52 ( V_33 , & V_74 -> V_106 [ 0 ] ) ;
if ( V_62 < 0 )
goto V_101;
V_104 += V_74 -> V_106 [ 0 ] . V_98 ;
}
V_62 = F_31 ( & V_33 -> V_38 ) ;
if ( V_62 < 0 )
goto V_101;
return V_104 ;
V_101:
F_22 ( V_33 ) ;
return V_62 ;
}
