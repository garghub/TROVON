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
F_13 ( V_6 , V_4 ) ;
F_14 () ;
if ( V_6 -> V_20 & V_29 ) {
V_6 -> V_20 &= ~ V_29 ;
continue;
}
if ( V_27 )
V_6 -> V_25 -> V_4 = NULL ;
V_6 -> V_26 -> V_30 . V_31 . V_32 = NULL ;
V_6 -> V_26 -> V_4 = NULL ;
F_15 ( V_6 -> V_26 , V_6 -> V_25 ) ;
} else {
if ( F_16 () ) {
F_9 ( V_28 ) ;
break;
}
F_17 ( & V_6 -> V_22 ) ;
F_18 () ;
F_7 ( & V_6 -> V_22 ) ;
}
} while ( 1 );
F_17 ( & V_6 -> V_22 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned long V_20 ;
struct V_33 * V_34 ;
if ( ! V_6 ) {
while ( ( V_4 = F_10 ( V_2 ) ) != NULL ) {
V_4 -> V_14 |= V_35 ;
F_20 ( V_4 , - V_36 ) ;
}
return;
}
V_34 = & V_6 -> V_13 -> V_37 -> V_38 ;
if ( ! V_6 -> V_25 -> V_4 && V_6 -> V_26 -> V_4 ) {
F_21 ( & V_34 -> V_39 , V_20 ) ;
if ( V_34 -> V_40 ) {
V_34 -> V_41 = true ;
F_22 ( & V_34 -> V_42 ) ;
}
F_23 ( & V_34 -> V_39 , V_20 ) ;
} else if ( ! V_6 -> V_25 -> V_4 && ! V_6 -> V_26 -> V_4 )
F_24 ( V_6 -> V_43 ) ;
}
static struct V_44 * F_25 ( int V_45 , int * V_46 )
{
struct V_44 * V_47 ;
V_47 = F_26 ( sizeof( struct V_44 ) * V_45 , V_48 ) ;
if ( ! V_47 )
* V_46 = - V_49 ;
else {
* V_46 = 0 ;
F_27 ( V_47 , V_45 ) ;
}
return V_47 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_50 * V_13 )
{
unsigned V_51 ;
V_51 = F_29 ( V_13 ) ;
if ( ! V_51 )
return;
F_30 ( V_52 , V_2 ) ;
F_31 ( V_2 , V_51 ) ;
if ( V_13 -> V_53 == 0 && ! F_32 ( V_13 ) )
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_56 = V_13 -> V_57 << 9 ;
if ( V_13 -> V_57 > V_51 )
V_2 -> V_54 . V_56 = 0 ;
if ( F_33 ( V_13 ) )
F_30 ( V_58 , V_2 ) ;
}
int F_34 ( struct V_5 * V_6 , struct V_50 * V_13 ,
T_1 * V_39 , const char * V_59 )
{
struct V_60 * V_37 = V_13 -> V_37 ;
T_2 V_61 = V_62 ;
int V_63 ;
struct V_64 * V_25 = & V_6 -> V_65 [ 0 ] ;
struct V_64 * V_26 = & V_6 -> V_65 [ 1 ] ;
if ( F_35 ( V_37 ) -> V_66 && * F_35 ( V_37 ) -> V_66 )
V_61 = ( T_2 ) F_36 ( F_35 ( V_37 ) ) << V_67 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_18 = F_37 ( F_19 , V_39 ) ;
if ( ! V_6 -> V_18 )
return - V_49 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_18 -> V_7 = V_6 ;
F_38 ( V_6 -> V_18 , F_1 ) ;
F_30 ( V_68 , V_6 -> V_18 ) ;
F_39 ( V_69 , V_6 -> V_18 ) ;
if ( F_40 ( V_13 ) )
F_28 ( V_6 -> V_18 , V_13 ) ;
#ifdef F_41
if ( V_37 -> V_70 == 1 ) {
unsigned int V_71 ;
V_71 = V_72 ;
if ( V_71 > V_37 -> V_73 )
V_71 = V_37 -> V_73 ;
if ( V_71 > V_37 -> V_74 )
V_71 = V_37 -> V_74 ;
if ( V_71 > ( V_37 -> V_75 * 512 ) )
V_71 = V_37 -> V_75 * 512 ;
if ( V_71 > 512 ) {
V_25 -> V_76 = F_26 ( V_71 , V_48 ) ;
if ( ! V_25 -> V_76 ) {
F_42 ( L_2 ,
F_43 ( V_13 ) ) ;
} else {
V_26 -> V_76 =
F_26 ( V_71 , V_48 ) ;
if ( ! V_26 -> V_76 ) {
F_42 ( L_3 ,
F_43 ( V_13 ) ) ;
F_44 ( V_25 -> V_76 ) ;
V_25 -> V_76 = NULL ;
}
}
}
if ( V_25 -> V_76 && V_26 -> V_76 ) {
F_45 ( V_6 -> V_18 , V_77 ) ;
F_46 ( V_6 -> V_18 , V_71 / 512 ) ;
F_47 ( V_6 -> V_18 , V_71 / 512 ) ;
F_48 ( V_6 -> V_18 , V_71 ) ;
V_25 -> V_47 = F_25 ( 1 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_25 -> V_79 =
F_25 ( V_71 / 512 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_26 -> V_47 = F_25 ( 1 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_26 -> V_79 =
F_25 ( V_71 / 512 , & V_63 ) ;
if ( V_63 )
goto V_78;
}
}
#endif
if ( ! V_25 -> V_76 && ! V_26 -> V_76 ) {
F_45 ( V_6 -> V_18 , V_61 ) ;
F_46 ( V_6 -> V_18 ,
F_49 ( V_37 -> V_75 , V_37 -> V_73 / 512 ) ) ;
F_47 ( V_6 -> V_18 , V_37 -> V_70 ) ;
F_48 ( V_6 -> V_18 , V_37 -> V_74 ) ;
V_25 -> V_47 = F_25 ( V_37 -> V_70 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_26 -> V_47 = F_25 ( V_37 -> V_70 , & V_63 ) ;
if ( V_63 )
goto V_78;
}
F_50 ( & V_6 -> V_22 , 1 ) ;
V_6 -> V_43 = F_51 ( F_6 , V_6 , L_4 ,
V_37 -> V_80 , V_59 ? V_59 : L_5 ) ;
if ( F_52 ( V_6 -> V_43 ) ) {
V_63 = F_53 ( V_6 -> V_43 ) ;
goto V_81;
}
return 0 ;
V_81:
F_44 ( V_25 -> V_79 ) ;
V_25 -> V_79 = NULL ;
F_44 ( V_26 -> V_79 ) ;
V_26 -> V_79 = NULL ;
V_78:
F_44 ( V_25 -> V_47 ) ;
V_25 -> V_47 = NULL ;
F_44 ( V_25 -> V_76 ) ;
V_25 -> V_76 = NULL ;
F_44 ( V_26 -> V_47 ) ;
V_26 -> V_47 = NULL ;
F_44 ( V_26 -> V_76 ) ;
V_26 -> V_76 = NULL ;
F_54 ( V_6 -> V_18 ) ;
return V_63 ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_20 ;
struct V_64 * V_25 = V_6 -> V_25 ;
struct V_64 * V_26 = V_6 -> V_26 ;
F_56 ( V_6 ) ;
F_57 ( V_6 -> V_43 ) ;
F_21 ( V_2 -> V_23 , V_20 ) ;
V_2 -> V_7 = NULL ;
F_58 ( V_2 ) ;
F_23 ( V_2 -> V_23 , V_20 ) ;
F_44 ( V_25 -> V_79 ) ;
V_25 -> V_79 = NULL ;
F_44 ( V_25 -> V_47 ) ;
V_25 -> V_47 = NULL ;
F_44 ( V_25 -> V_76 ) ;
V_25 -> V_76 = NULL ;
F_44 ( V_26 -> V_79 ) ;
V_26 -> V_79 = NULL ;
F_44 ( V_26 -> V_47 ) ;
V_26 -> V_47 = NULL ;
F_44 ( V_26 -> V_76 ) ;
V_26 -> V_76 = NULL ;
V_6 -> V_13 = NULL ;
}
int F_59 ( struct V_5 * V_6 , struct V_50 * V_13 )
{
struct V_64 * V_25 = & V_6 -> V_65 [ 0 ] ;
struct V_64 * V_26 = & V_6 -> V_65 [ 1 ] ;
int V_63 = 0 ;
V_25 -> V_82 = F_60 ( sizeof( struct V_83 ) , V_48 ) ;
if ( ! V_25 -> V_82 ) {
F_42 ( L_6 ,
F_43 ( V_13 ) ) ;
V_63 = - V_49 ;
goto V_84;
}
V_26 -> V_82 = F_60 ( sizeof( struct V_83 ) , V_48 ) ;
if ( ! V_26 -> V_82 ) {
F_42 ( L_7 ,
F_43 ( V_13 ) ) ;
F_44 ( V_25 -> V_82 ) ;
V_25 -> V_82 = NULL ;
V_63 = - V_49 ;
goto V_84;
}
F_61 ( & V_25 -> V_82 -> V_85 ) ;
F_61 ( & V_26 -> V_82 -> V_85 ) ;
V_84:
return V_63 ;
}
void F_62 ( struct V_5 * V_6 )
{
struct V_64 * V_25 = & V_6 -> V_65 [ 0 ] ;
struct V_64 * V_26 = & V_6 -> V_65 [ 1 ] ;
F_44 ( V_25 -> V_82 ) ;
V_25 -> V_82 = NULL ;
F_44 ( V_26 -> V_82 ) ;
V_26 -> V_82 = NULL ;
}
void F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_20 ;
if ( ! ( V_6 -> V_20 & V_86 ) ) {
V_6 -> V_20 |= V_86 ;
F_21 ( V_2 -> V_23 , V_20 ) ;
F_64 ( V_2 ) ;
F_23 ( V_2 -> V_23 , V_20 ) ;
F_7 ( & V_6 -> V_22 ) ;
}
}
void F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_20 ;
if ( V_6 -> V_20 & V_86 ) {
V_6 -> V_20 &= ~ V_86 ;
F_17 ( & V_6 -> V_22 ) ;
F_21 ( V_2 -> V_23 , V_20 ) ;
F_58 ( V_2 ) ;
F_23 ( V_2 -> V_23 , V_20 ) ;
}
}
static unsigned int F_65 ( struct V_5 * V_6 ,
struct V_83 * V_82 ,
struct V_44 * V_47 ,
enum V_87 V_8 )
{
struct V_44 * V_88 = V_47 ;
unsigned int V_45 = 0 ;
struct V_3 * V_4 ;
if ( F_66 ( V_8 ) ) {
unsigned int V_89 = F_67 ( V_6 -> V_13 ) ? 4096 : 512 ;
unsigned int V_90 = F_68 ( V_6 -> V_18 ) ;
unsigned int V_91 , V_92 , V_93 = 0 ;
T_3 * V_94 = ( T_3 * ) V_82 -> V_95 ;
V_92 = V_89 ;
do {
V_91 = F_49 ( V_92 , V_90 ) ;
F_69 ( V_88 , V_94 + V_93 , V_91 ) ;
V_93 += V_91 ;
V_92 -= V_91 ;
F_70 ( V_88 ++ ) ;
V_45 ++ ;
} while ( V_92 );
}
F_71 (req, &packed->list, queuelist) {
V_45 += F_72 ( V_6 -> V_18 , V_4 , V_88 ) ;
V_88 = V_47 + ( V_45 - 1 ) ;
F_70 ( V_88 ++ ) ;
}
F_73 ( V_47 + ( V_45 - 1 ) ) ;
return V_45 ;
}
unsigned int F_74 ( struct V_5 * V_6 , struct V_64 * V_65 )
{
unsigned int V_45 ;
T_4 V_96 ;
struct V_44 * V_47 ;
enum V_87 V_8 ;
int V_97 ;
V_8 = V_65 -> V_8 ;
if ( ! V_65 -> V_76 ) {
if ( F_75 ( V_8 ) )
return F_65 ( V_6 , V_65 -> V_82 ,
V_65 -> V_47 , V_8 ) ;
else
return F_72 ( V_6 -> V_18 , V_65 -> V_4 , V_65 -> V_47 ) ;
}
F_76 ( ! V_65 -> V_79 ) ;
if ( F_75 ( V_8 ) )
V_45 = F_65 ( V_6 , V_65 -> V_82 ,
V_65 -> V_79 , V_8 ) ;
else
V_45 = F_72 ( V_6 -> V_18 , V_65 -> V_4 , V_65 -> V_79 ) ;
V_65 -> V_98 = V_45 ;
V_96 = 0 ;
F_77 (mqrq->bounce_sg, sg, sg_len, i)
V_96 += V_47 -> V_99 ;
F_78 ( V_65 -> V_47 , V_65 -> V_76 , V_96 ) ;
return 1 ;
}
void F_79 ( struct V_64 * V_65 )
{
if ( ! V_65 -> V_76 )
return;
if ( F_80 ( V_65 -> V_4 ) != V_100 )
return;
F_81 ( V_65 -> V_79 , V_65 -> V_98 ,
V_65 -> V_76 , V_65 -> V_47 [ 0 ] . V_99 ) ;
}
void F_82 ( struct V_64 * V_65 )
{
if ( ! V_65 -> V_76 )
return;
if ( F_80 ( V_65 -> V_4 ) != V_101 )
return;
F_83 ( V_65 -> V_79 , V_65 -> V_98 ,
V_65 -> V_76 , V_65 -> V_47 [ 0 ] . V_99 ) ;
}
