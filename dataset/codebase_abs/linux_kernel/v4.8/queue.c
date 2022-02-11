static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_8 != V_9 && F_2 ( V_4 ) != V_10 &&
F_2 ( V_4 ) != V_11 ) {
F_3 ( V_4 , L_1 ) ;
return V_12 ;
}
if ( V_6 && ( F_4 ( V_6 -> V_13 ) || F_5 ( V_6 ) ) )
return V_12 ;
V_4 -> V_14 |= V_15 ;
return V_16 ;
}
static int F_6 ( void * V_17 )
{
struct V_5 * V_6 = V_17 ;
struct V_1 * V_2 = V_6 -> V_18 ;
V_19 -> V_20 |= V_21 ;
F_7 ( & V_6 -> V_22 ) ;
do {
struct V_3 * V_4 = NULL ;
F_8 ( V_2 -> V_23 ) ;
F_9 ( V_24 ) ;
V_4 = F_10 ( V_2 ) ;
V_6 -> V_25 -> V_4 = V_4 ;
F_11 ( V_2 -> V_23 ) ;
if ( V_4 || V_6 -> V_26 -> V_4 ) {
bool V_27 = F_12 ( V_4 ) ;
F_9 ( V_28 ) ;
V_6 -> V_29 ( V_6 , V_4 ) ;
F_13 () ;
if ( V_6 -> V_20 & V_30 ) {
V_6 -> V_20 &= ~ V_30 ;
continue;
}
if ( V_27 )
V_6 -> V_25 -> V_4 = NULL ;
V_6 -> V_26 -> V_31 . V_32 . V_33 = NULL ;
V_6 -> V_26 -> V_4 = NULL ;
F_14 ( V_6 -> V_26 , V_6 -> V_25 ) ;
} else {
if ( F_15 () ) {
F_9 ( V_28 ) ;
break;
}
F_16 ( & V_6 -> V_22 ) ;
F_17 () ;
F_7 ( & V_6 -> V_22 ) ;
}
} while ( 1 );
F_16 ( & V_6 -> V_22 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned long V_20 ;
struct V_34 * V_35 ;
if ( ! V_6 ) {
while ( ( V_4 = F_10 ( V_2 ) ) != NULL ) {
V_4 -> V_14 |= V_36 ;
F_19 ( V_4 , - V_37 ) ;
}
return;
}
V_35 = & V_6 -> V_13 -> V_38 -> V_39 ;
if ( ! V_6 -> V_25 -> V_4 && V_6 -> V_26 -> V_4 ) {
F_20 ( & V_35 -> V_40 , V_20 ) ;
if ( V_35 -> V_41 ) {
V_35 -> V_42 = true ;
F_21 ( & V_35 -> V_43 ) ;
}
F_22 ( & V_35 -> V_40 , V_20 ) ;
} else if ( ! V_6 -> V_25 -> V_4 && ! V_6 -> V_26 -> V_4 )
F_23 ( V_6 -> V_44 ) ;
}
static struct V_45 * F_24 ( int V_46 , int * V_47 )
{
struct V_45 * V_48 ;
V_48 = F_25 ( sizeof( struct V_45 ) * V_46 , V_49 ) ;
if ( ! V_48 )
* V_47 = - V_50 ;
else {
* V_47 = 0 ;
F_26 ( V_48 , V_46 ) ;
}
return V_48 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_51 * V_13 )
{
unsigned V_52 ;
V_52 = F_28 ( V_13 ) ;
if ( ! V_52 )
return;
F_29 ( V_53 , V_2 ) ;
F_30 ( V_2 , V_52 ) ;
if ( V_13 -> V_54 == 0 && ! F_31 ( V_13 ) )
V_2 -> V_55 . V_56 = 1 ;
V_2 -> V_55 . V_57 = V_13 -> V_58 << 9 ;
if ( V_13 -> V_58 > V_52 )
V_2 -> V_55 . V_57 = 0 ;
if ( F_32 ( V_13 ) )
F_29 ( V_59 , V_2 ) ;
}
int F_33 ( struct V_5 * V_6 , struct V_51 * V_13 ,
T_1 * V_40 , const char * V_60 )
{
struct V_61 * V_38 = V_13 -> V_38 ;
T_2 V_62 = V_63 ;
int V_64 ;
struct V_65 * V_25 = & V_6 -> V_66 [ 0 ] ;
struct V_65 * V_26 = & V_6 -> V_66 [ 1 ] ;
if ( F_34 ( V_38 ) -> V_67 && * F_34 ( V_38 ) -> V_67 )
V_62 = ( T_2 ) F_35 ( F_34 ( V_38 ) ) << V_68 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_18 = F_36 ( F_18 , V_40 ) ;
if ( ! V_6 -> V_18 )
return - V_50 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_18 -> V_7 = V_6 ;
F_37 ( V_6 -> V_18 , F_1 ) ;
F_29 ( V_69 , V_6 -> V_18 ) ;
F_38 ( V_70 , V_6 -> V_18 ) ;
if ( F_39 ( V_13 ) )
F_27 ( V_6 -> V_18 , V_13 ) ;
#ifdef F_40
if ( V_38 -> V_71 == 1 ) {
unsigned int V_72 ;
V_72 = V_73 ;
if ( V_72 > V_38 -> V_74 )
V_72 = V_38 -> V_74 ;
if ( V_72 > V_38 -> V_75 )
V_72 = V_38 -> V_75 ;
if ( V_72 > ( V_38 -> V_76 * 512 ) )
V_72 = V_38 -> V_76 * 512 ;
if ( V_72 > 512 ) {
V_25 -> V_77 = F_25 ( V_72 , V_49 ) ;
if ( ! V_25 -> V_77 ) {
F_41 ( L_2 ,
F_42 ( V_13 ) ) ;
} else {
V_26 -> V_77 =
F_25 ( V_72 , V_49 ) ;
if ( ! V_26 -> V_77 ) {
F_41 ( L_3 ,
F_42 ( V_13 ) ) ;
F_43 ( V_25 -> V_77 ) ;
V_25 -> V_77 = NULL ;
}
}
}
if ( V_25 -> V_77 && V_26 -> V_77 ) {
F_44 ( V_6 -> V_18 , V_78 ) ;
F_45 ( V_6 -> V_18 , V_72 / 512 ) ;
F_46 ( V_6 -> V_18 , V_72 / 512 ) ;
F_47 ( V_6 -> V_18 , V_72 ) ;
V_25 -> V_48 = F_24 ( 1 , & V_64 ) ;
if ( V_64 )
goto V_79;
V_25 -> V_80 =
F_24 ( V_72 / 512 , & V_64 ) ;
if ( V_64 )
goto V_79;
V_26 -> V_48 = F_24 ( 1 , & V_64 ) ;
if ( V_64 )
goto V_79;
V_26 -> V_80 =
F_24 ( V_72 / 512 , & V_64 ) ;
if ( V_64 )
goto V_79;
}
}
#endif
if ( ! V_25 -> V_77 && ! V_26 -> V_77 ) {
F_44 ( V_6 -> V_18 , V_62 ) ;
F_45 ( V_6 -> V_18 ,
F_48 ( V_38 -> V_76 , V_38 -> V_74 / 512 ) ) ;
F_46 ( V_6 -> V_18 , V_38 -> V_71 ) ;
F_47 ( V_6 -> V_18 , V_38 -> V_75 ) ;
V_25 -> V_48 = F_24 ( V_38 -> V_71 , & V_64 ) ;
if ( V_64 )
goto V_79;
V_26 -> V_48 = F_24 ( V_38 -> V_71 , & V_64 ) ;
if ( V_64 )
goto V_79;
}
F_49 ( & V_6 -> V_22 , 1 ) ;
V_6 -> V_44 = F_50 ( F_6 , V_6 , L_4 ,
V_38 -> V_81 , V_60 ? V_60 : L_5 ) ;
if ( F_51 ( V_6 -> V_44 ) ) {
V_64 = F_52 ( V_6 -> V_44 ) ;
goto V_82;
}
return 0 ;
V_82:
F_43 ( V_25 -> V_80 ) ;
V_25 -> V_80 = NULL ;
F_43 ( V_26 -> V_80 ) ;
V_26 -> V_80 = NULL ;
V_79:
F_43 ( V_25 -> V_48 ) ;
V_25 -> V_48 = NULL ;
F_43 ( V_25 -> V_77 ) ;
V_25 -> V_77 = NULL ;
F_43 ( V_26 -> V_48 ) ;
V_26 -> V_48 = NULL ;
F_43 ( V_26 -> V_77 ) ;
V_26 -> V_77 = NULL ;
F_53 ( V_6 -> V_18 ) ;
return V_64 ;
}
void F_54 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_20 ;
struct V_65 * V_25 = V_6 -> V_25 ;
struct V_65 * V_26 = V_6 -> V_26 ;
F_55 ( V_6 ) ;
F_56 ( V_6 -> V_44 ) ;
F_20 ( V_2 -> V_23 , V_20 ) ;
V_2 -> V_7 = NULL ;
F_57 ( V_2 ) ;
F_22 ( V_2 -> V_23 , V_20 ) ;
F_43 ( V_25 -> V_80 ) ;
V_25 -> V_80 = NULL ;
F_43 ( V_25 -> V_48 ) ;
V_25 -> V_48 = NULL ;
F_43 ( V_25 -> V_77 ) ;
V_25 -> V_77 = NULL ;
F_43 ( V_26 -> V_80 ) ;
V_26 -> V_80 = NULL ;
F_43 ( V_26 -> V_48 ) ;
V_26 -> V_48 = NULL ;
F_43 ( V_26 -> V_77 ) ;
V_26 -> V_77 = NULL ;
V_6 -> V_13 = NULL ;
}
int F_58 ( struct V_5 * V_6 , struct V_51 * V_13 )
{
struct V_65 * V_25 = & V_6 -> V_66 [ 0 ] ;
struct V_65 * V_26 = & V_6 -> V_66 [ 1 ] ;
int V_64 = 0 ;
V_25 -> V_83 = F_59 ( sizeof( struct V_84 ) , V_49 ) ;
if ( ! V_25 -> V_83 ) {
F_41 ( L_6 ,
F_42 ( V_13 ) ) ;
V_64 = - V_50 ;
goto V_85;
}
V_26 -> V_83 = F_59 ( sizeof( struct V_84 ) , V_49 ) ;
if ( ! V_26 -> V_83 ) {
F_41 ( L_7 ,
F_42 ( V_13 ) ) ;
F_43 ( V_25 -> V_83 ) ;
V_25 -> V_83 = NULL ;
V_64 = - V_50 ;
goto V_85;
}
F_60 ( & V_25 -> V_83 -> V_86 ) ;
F_60 ( & V_26 -> V_83 -> V_86 ) ;
V_85:
return V_64 ;
}
void F_61 ( struct V_5 * V_6 )
{
struct V_65 * V_25 = & V_6 -> V_66 [ 0 ] ;
struct V_65 * V_26 = & V_6 -> V_66 [ 1 ] ;
F_43 ( V_25 -> V_83 ) ;
V_25 -> V_83 = NULL ;
F_43 ( V_26 -> V_83 ) ;
V_26 -> V_83 = NULL ;
}
void F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_20 ;
if ( ! ( V_6 -> V_20 & V_87 ) ) {
V_6 -> V_20 |= V_87 ;
F_20 ( V_2 -> V_23 , V_20 ) ;
F_63 ( V_2 ) ;
F_22 ( V_2 -> V_23 , V_20 ) ;
F_7 ( & V_6 -> V_22 ) ;
}
}
void F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_20 ;
if ( V_6 -> V_20 & V_87 ) {
V_6 -> V_20 &= ~ V_87 ;
F_16 ( & V_6 -> V_22 ) ;
F_20 ( V_2 -> V_23 , V_20 ) ;
F_57 ( V_2 ) ;
F_22 ( V_2 -> V_23 , V_20 ) ;
}
}
static unsigned int F_64 ( struct V_5 * V_6 ,
struct V_84 * V_83 ,
struct V_45 * V_48 ,
enum V_88 V_8 )
{
struct V_45 * V_89 = V_48 ;
unsigned int V_46 = 0 ;
struct V_3 * V_4 ;
if ( F_65 ( V_8 ) ) {
unsigned int V_90 = F_66 ( V_6 -> V_13 ) ? 4096 : 512 ;
unsigned int V_91 = F_67 ( V_6 -> V_18 ) ;
unsigned int V_92 , V_93 , V_94 = 0 ;
T_3 * V_95 = ( T_3 * ) V_83 -> V_96 ;
V_93 = V_90 ;
do {
V_92 = F_48 ( V_93 , V_91 ) ;
F_68 ( V_89 , V_95 + V_94 , V_92 ) ;
V_94 += V_92 ;
V_93 -= V_92 ;
F_69 ( V_89 ++ ) ;
V_46 ++ ;
} while ( V_93 );
}
F_70 (req, &packed->list, queuelist) {
V_46 += F_71 ( V_6 -> V_18 , V_4 , V_89 ) ;
V_89 = V_48 + ( V_46 - 1 ) ;
F_69 ( V_89 ++ ) ;
}
F_72 ( V_48 + ( V_46 - 1 ) ) ;
return V_46 ;
}
unsigned int F_73 ( struct V_5 * V_6 , struct V_65 * V_66 )
{
unsigned int V_46 ;
T_4 V_97 ;
struct V_45 * V_48 ;
enum V_88 V_8 ;
int V_98 ;
V_8 = V_66 -> V_8 ;
if ( ! V_66 -> V_77 ) {
if ( F_74 ( V_8 ) )
return F_64 ( V_6 , V_66 -> V_83 ,
V_66 -> V_48 , V_8 ) ;
else
return F_71 ( V_6 -> V_18 , V_66 -> V_4 , V_66 -> V_48 ) ;
}
F_75 ( ! V_66 -> V_80 ) ;
if ( F_74 ( V_8 ) )
V_46 = F_64 ( V_6 , V_66 -> V_83 ,
V_66 -> V_80 , V_8 ) ;
else
V_46 = F_71 ( V_6 -> V_18 , V_66 -> V_4 , V_66 -> V_80 ) ;
V_66 -> V_99 = V_46 ;
V_97 = 0 ;
F_76 (mqrq->bounce_sg, sg, sg_len, i)
V_97 += V_48 -> V_100 ;
F_77 ( V_66 -> V_48 , V_66 -> V_77 , V_97 ) ;
return 1 ;
}
void F_78 ( struct V_65 * V_66 )
{
if ( ! V_66 -> V_77 )
return;
if ( F_79 ( V_66 -> V_4 ) != V_101 )
return;
F_80 ( V_66 -> V_80 , V_66 -> V_99 ,
V_66 -> V_77 , V_66 -> V_48 [ 0 ] . V_100 ) ;
}
void F_81 ( struct V_65 * V_66 )
{
if ( ! V_66 -> V_77 )
return;
if ( F_79 ( V_66 -> V_4 ) != V_102 )
return;
F_82 ( V_66 -> V_80 , V_66 -> V_99 ,
V_66 -> V_77 , V_66 -> V_48 [ 0 ] . V_100 ) ;
}
