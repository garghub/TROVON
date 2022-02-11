static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_8 != V_9 && ! ( V_4 -> V_10 & V_11 ) ) {
F_2 ( V_4 , L_1 ) ;
return V_12 ;
}
if ( V_6 && ( F_3 ( V_6 -> V_13 ) || F_4 ( V_6 ) ) )
return V_12 ;
V_4 -> V_10 |= V_14 ;
return V_15 ;
}
static int F_5 ( void * V_16 )
{
struct V_5 * V_6 = V_16 ;
struct V_1 * V_2 = V_6 -> V_17 ;
V_18 -> V_19 |= V_20 ;
F_6 ( & V_6 -> V_21 ) ;
do {
struct V_3 * V_4 = NULL ;
unsigned int V_10 = 0 ;
F_7 ( V_2 -> V_22 ) ;
F_8 ( V_23 ) ;
V_4 = F_9 ( V_2 ) ;
V_6 -> V_24 -> V_4 = V_4 ;
F_10 ( V_2 -> V_22 ) ;
if ( V_4 || V_6 -> V_25 -> V_4 ) {
F_8 ( V_26 ) ;
V_10 = V_4 ? V_4 -> V_10 : 0 ;
V_6 -> V_27 ( V_6 , V_4 ) ;
F_11 () ;
if ( V_6 -> V_19 & V_28 ) {
V_6 -> V_19 &= ~ V_28 ;
continue;
}
if ( V_10 & V_29 )
V_6 -> V_24 -> V_4 = NULL ;
V_6 -> V_25 -> V_30 . V_31 . V_32 = NULL ;
V_6 -> V_25 -> V_4 = NULL ;
F_12 ( V_6 -> V_25 , V_6 -> V_24 ) ;
} else {
if ( F_13 () ) {
F_8 ( V_26 ) ;
break;
}
F_14 ( & V_6 -> V_21 ) ;
F_15 () ;
F_6 ( & V_6 -> V_21 ) ;
}
} while ( 1 );
F_14 ( & V_6 -> V_21 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
struct V_33 * V_34 ;
if ( ! V_6 ) {
while ( ( V_4 = F_9 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_35 ;
F_17 ( V_4 , - V_36 ) ;
}
return;
}
V_34 = & V_6 -> V_13 -> V_37 -> V_38 ;
if ( ! V_6 -> V_24 -> V_4 && V_6 -> V_25 -> V_4 ) {
F_18 ( & V_34 -> V_39 , V_19 ) ;
if ( V_34 -> V_40 ) {
V_34 -> V_41 = true ;
F_19 ( & V_34 -> V_42 ) ;
}
F_20 ( & V_34 -> V_39 , V_19 ) ;
} else if ( ! V_6 -> V_24 -> V_4 && ! V_6 -> V_25 -> V_4 )
F_21 ( V_6 -> V_43 ) ;
}
static struct V_44 * F_22 ( int V_45 , int * V_46 )
{
struct V_44 * V_47 ;
V_47 = F_23 ( sizeof( struct V_44 ) * V_45 , V_48 ) ;
if ( ! V_47 )
* V_46 = - V_49 ;
else {
* V_46 = 0 ;
F_24 ( V_47 , V_45 ) ;
}
return V_47 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_50 * V_13 )
{
unsigned V_51 ;
V_51 = F_26 ( V_13 ) ;
if ( ! V_51 )
return;
F_27 ( V_52 , V_2 ) ;
F_28 ( V_2 , V_51 ) ;
if ( V_13 -> V_53 == 0 && ! F_29 ( V_13 ) )
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_56 = V_13 -> V_57 << 9 ;
if ( V_13 -> V_57 > V_51 )
V_2 -> V_54 . V_56 = 0 ;
if ( F_30 ( V_13 ) )
F_27 ( V_58 , V_2 ) ;
}
int F_31 ( struct V_5 * V_6 , struct V_50 * V_13 ,
T_1 * V_39 , const char * V_59 )
{
struct V_60 * V_37 = V_13 -> V_37 ;
T_2 V_61 = V_62 ;
int V_63 ;
struct V_64 * V_24 = & V_6 -> V_65 [ 0 ] ;
struct V_64 * V_25 = & V_6 -> V_65 [ 1 ] ;
if ( F_32 ( V_37 ) -> V_66 && * F_32 ( V_37 ) -> V_66 )
V_61 = ( T_2 ) F_33 ( F_32 ( V_37 ) ) << V_67 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_17 = F_34 ( F_16 , V_39 ) ;
if ( ! V_6 -> V_17 )
return - V_49 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_17 -> V_7 = V_6 ;
F_35 ( V_6 -> V_17 , F_1 ) ;
F_27 ( V_68 , V_6 -> V_17 ) ;
F_36 ( V_69 , V_6 -> V_17 ) ;
if ( F_37 ( V_13 ) )
F_25 ( V_6 -> V_17 , V_13 ) ;
#ifdef F_38
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
V_24 -> V_76 = F_23 ( V_71 , V_48 ) ;
if ( ! V_24 -> V_76 ) {
F_39 ( L_2 ,
F_40 ( V_13 ) ) ;
} else {
V_25 -> V_76 =
F_23 ( V_71 , V_48 ) ;
if ( ! V_25 -> V_76 ) {
F_39 ( L_3 ,
F_40 ( V_13 ) ) ;
F_41 ( V_24 -> V_76 ) ;
V_24 -> V_76 = NULL ;
}
}
}
if ( V_24 -> V_76 && V_25 -> V_76 ) {
F_42 ( V_6 -> V_17 , V_77 ) ;
F_43 ( V_6 -> V_17 , V_71 / 512 ) ;
F_44 ( V_6 -> V_17 , V_71 / 512 ) ;
F_45 ( V_6 -> V_17 , V_71 ) ;
V_24 -> V_47 = F_22 ( 1 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_24 -> V_79 =
F_22 ( V_71 / 512 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_25 -> V_47 = F_22 ( 1 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_25 -> V_79 =
F_22 ( V_71 / 512 , & V_63 ) ;
if ( V_63 )
goto V_78;
}
}
#endif
if ( ! V_24 -> V_76 && ! V_25 -> V_76 ) {
F_42 ( V_6 -> V_17 , V_61 ) ;
F_43 ( V_6 -> V_17 ,
F_46 ( V_37 -> V_75 , V_37 -> V_73 / 512 ) ) ;
F_44 ( V_6 -> V_17 , V_37 -> V_70 ) ;
F_45 ( V_6 -> V_17 , V_37 -> V_74 ) ;
V_24 -> V_47 = F_22 ( V_37 -> V_70 , & V_63 ) ;
if ( V_63 )
goto V_78;
V_25 -> V_47 = F_22 ( V_37 -> V_70 , & V_63 ) ;
if ( V_63 )
goto V_78;
}
F_47 ( & V_6 -> V_21 , 1 ) ;
V_6 -> V_43 = F_48 ( F_5 , V_6 , L_4 ,
V_37 -> V_80 , V_59 ? V_59 : L_5 ) ;
if ( F_49 ( V_6 -> V_43 ) ) {
V_63 = F_50 ( V_6 -> V_43 ) ;
goto V_81;
}
return 0 ;
V_81:
F_41 ( V_24 -> V_79 ) ;
V_24 -> V_79 = NULL ;
F_41 ( V_25 -> V_79 ) ;
V_25 -> V_79 = NULL ;
V_78:
F_41 ( V_24 -> V_47 ) ;
V_24 -> V_47 = NULL ;
F_41 ( V_24 -> V_76 ) ;
V_24 -> V_76 = NULL ;
F_41 ( V_25 -> V_47 ) ;
V_25 -> V_47 = NULL ;
F_41 ( V_25 -> V_76 ) ;
V_25 -> V_76 = NULL ;
F_51 ( V_6 -> V_17 ) ;
return V_63 ;
}
void F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
struct V_64 * V_24 = V_6 -> V_24 ;
struct V_64 * V_25 = V_6 -> V_25 ;
F_53 ( V_6 ) ;
F_54 ( V_6 -> V_43 ) ;
F_18 ( V_2 -> V_22 , V_19 ) ;
V_2 -> V_7 = NULL ;
F_55 ( V_2 ) ;
F_20 ( V_2 -> V_22 , V_19 ) ;
F_41 ( V_24 -> V_79 ) ;
V_24 -> V_79 = NULL ;
F_41 ( V_24 -> V_47 ) ;
V_24 -> V_47 = NULL ;
F_41 ( V_24 -> V_76 ) ;
V_24 -> V_76 = NULL ;
F_41 ( V_25 -> V_79 ) ;
V_25 -> V_79 = NULL ;
F_41 ( V_25 -> V_47 ) ;
V_25 -> V_47 = NULL ;
F_41 ( V_25 -> V_76 ) ;
V_25 -> V_76 = NULL ;
V_6 -> V_13 = NULL ;
}
int F_56 ( struct V_5 * V_6 , struct V_50 * V_13 )
{
struct V_64 * V_24 = & V_6 -> V_65 [ 0 ] ;
struct V_64 * V_25 = & V_6 -> V_65 [ 1 ] ;
int V_63 = 0 ;
V_24 -> V_82 = F_57 ( sizeof( struct V_83 ) , V_48 ) ;
if ( ! V_24 -> V_82 ) {
F_39 ( L_6 ,
F_40 ( V_13 ) ) ;
V_63 = - V_49 ;
goto V_84;
}
V_25 -> V_82 = F_57 ( sizeof( struct V_83 ) , V_48 ) ;
if ( ! V_25 -> V_82 ) {
F_39 ( L_7 ,
F_40 ( V_13 ) ) ;
F_41 ( V_24 -> V_82 ) ;
V_24 -> V_82 = NULL ;
V_63 = - V_49 ;
goto V_84;
}
F_58 ( & V_24 -> V_82 -> V_85 ) ;
F_58 ( & V_25 -> V_82 -> V_85 ) ;
V_84:
return V_63 ;
}
void F_59 ( struct V_5 * V_6 )
{
struct V_64 * V_24 = & V_6 -> V_65 [ 0 ] ;
struct V_64 * V_25 = & V_6 -> V_65 [ 1 ] ;
F_41 ( V_24 -> V_82 ) ;
V_24 -> V_82 = NULL ;
F_41 ( V_25 -> V_82 ) ;
V_25 -> V_82 = NULL ;
}
void F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
if ( ! ( V_6 -> V_19 & V_86 ) ) {
V_6 -> V_19 |= V_86 ;
F_18 ( V_2 -> V_22 , V_19 ) ;
F_61 ( V_2 ) ;
F_20 ( V_2 -> V_22 , V_19 ) ;
F_6 ( & V_6 -> V_21 ) ;
}
}
void F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
if ( V_6 -> V_19 & V_86 ) {
V_6 -> V_19 &= ~ V_86 ;
F_14 ( & V_6 -> V_21 ) ;
F_18 ( V_2 -> V_22 , V_19 ) ;
F_55 ( V_2 ) ;
F_20 ( V_2 -> V_22 , V_19 ) ;
}
}
static unsigned int F_62 ( struct V_5 * V_6 ,
struct V_83 * V_82 ,
struct V_44 * V_47 ,
enum V_87 V_8 )
{
struct V_44 * V_88 = V_47 ;
unsigned int V_45 = 0 ;
struct V_3 * V_4 ;
if ( F_63 ( V_8 ) ) {
unsigned int V_89 = F_64 ( V_6 -> V_13 ) ? 4096 : 512 ;
unsigned int V_90 = F_65 ( V_6 -> V_17 ) ;
unsigned int V_91 , V_92 , V_93 = 0 ;
T_3 * V_94 = ( T_3 * ) V_82 -> V_95 ;
V_92 = V_89 ;
do {
V_91 = F_46 ( V_92 , V_90 ) ;
F_66 ( V_88 , V_94 + V_93 , V_91 ) ;
V_93 += V_91 ;
V_92 -= V_91 ;
F_67 ( V_88 ++ ) ;
V_45 ++ ;
} while ( V_92 );
}
F_68 (req, &packed->list, queuelist) {
V_45 += F_69 ( V_6 -> V_17 , V_4 , V_88 ) ;
V_88 = V_47 + ( V_45 - 1 ) ;
F_67 ( V_88 ++ ) ;
}
F_70 ( V_47 + ( V_45 - 1 ) ) ;
return V_45 ;
}
unsigned int F_71 ( struct V_5 * V_6 , struct V_64 * V_65 )
{
unsigned int V_45 ;
T_4 V_96 ;
struct V_44 * V_47 ;
enum V_87 V_8 ;
int V_97 ;
V_8 = V_65 -> V_8 ;
if ( ! V_65 -> V_76 ) {
if ( F_72 ( V_8 ) )
return F_62 ( V_6 , V_65 -> V_82 ,
V_65 -> V_47 , V_8 ) ;
else
return F_69 ( V_6 -> V_17 , V_65 -> V_4 , V_65 -> V_47 ) ;
}
F_73 ( ! V_65 -> V_79 ) ;
if ( F_72 ( V_8 ) )
V_45 = F_62 ( V_6 , V_65 -> V_82 ,
V_65 -> V_79 , V_8 ) ;
else
V_45 = F_69 ( V_6 -> V_17 , V_65 -> V_4 , V_65 -> V_79 ) ;
V_65 -> V_98 = V_45 ;
V_96 = 0 ;
F_74 (mqrq->bounce_sg, sg, sg_len, i)
V_96 += V_47 -> V_99 ;
F_75 ( V_65 -> V_47 , V_65 -> V_76 , V_96 ) ;
return 1 ;
}
void F_76 ( struct V_64 * V_65 )
{
if ( ! V_65 -> V_76 )
return;
if ( F_77 ( V_65 -> V_4 ) != V_100 )
return;
F_78 ( V_65 -> V_79 , V_65 -> V_98 ,
V_65 -> V_76 , V_65 -> V_47 [ 0 ] . V_99 ) ;
}
void F_79 ( struct V_64 * V_65 )
{
if ( ! V_65 -> V_76 )
return;
if ( F_77 ( V_65 -> V_4 ) != V_101 )
return;
F_80 ( V_65 -> V_79 , V_65 -> V_98 ,
V_65 -> V_76 , V_65 -> V_47 [ 0 ] . V_99 ) ;
}
