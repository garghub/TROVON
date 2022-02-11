static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_8 != V_9 && ! ( V_4 -> V_10 & V_11 ) ) {
F_2 ( V_4 , L_1 ) ;
return V_12 ;
}
if ( V_6 && F_3 ( V_6 -> V_13 ) )
return V_12 ;
V_4 -> V_10 |= V_14 ;
return V_15 ;
}
static int F_4 ( void * V_16 )
{
struct V_5 * V_6 = V_16 ;
struct V_1 * V_2 = V_6 -> V_17 ;
V_18 -> V_19 |= V_20 ;
F_5 ( & V_6 -> V_21 ) ;
do {
struct V_3 * V_4 = NULL ;
struct V_22 * V_23 ;
unsigned int V_10 = 0 ;
F_6 ( V_2 -> V_24 ) ;
F_7 ( V_25 ) ;
V_4 = F_8 ( V_2 ) ;
V_6 -> V_26 -> V_4 = V_4 ;
F_9 ( V_2 -> V_24 ) ;
if ( V_4 || V_6 -> V_27 -> V_4 ) {
F_7 ( V_28 ) ;
V_10 = V_4 ? V_4 -> V_10 : 0 ;
V_6 -> V_29 ( V_6 , V_4 ) ;
if ( V_6 -> V_19 & V_30 ) {
V_6 -> V_19 &= ~ V_30 ;
continue;
}
if ( V_10 & V_31 )
V_6 -> V_26 -> V_4 = NULL ;
V_6 -> V_27 -> V_32 . V_33 . V_34 = NULL ;
V_6 -> V_27 -> V_4 = NULL ;
V_23 = V_6 -> V_27 ;
V_6 -> V_27 = V_6 -> V_26 ;
V_6 -> V_26 = V_23 ;
} else {
if ( F_10 () ) {
F_7 ( V_28 ) ;
break;
}
F_11 ( & V_6 -> V_21 ) ;
F_12 () ;
F_5 ( & V_6 -> V_21 ) ;
}
} while ( 1 );
F_11 ( & V_6 -> V_21 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
struct V_35 * V_36 ;
if ( ! V_6 ) {
while ( ( V_4 = F_8 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_37 ;
F_14 ( V_4 , - V_38 ) ;
}
return;
}
V_36 = & V_6 -> V_13 -> V_39 -> V_40 ;
if ( ! V_6 -> V_26 -> V_4 && V_6 -> V_27 -> V_4 ) {
F_15 ( & V_36 -> V_41 , V_19 ) ;
if ( V_36 -> V_42 ) {
V_36 -> V_43 = true ;
F_16 ( & V_36 -> V_44 ) ;
}
F_17 ( & V_36 -> V_41 , V_19 ) ;
} else if ( ! V_6 -> V_26 -> V_4 && ! V_6 -> V_27 -> V_4 )
F_18 ( V_6 -> V_45 ) ;
}
static struct V_46 * F_19 ( int V_47 , int * V_48 )
{
struct V_46 * V_49 ;
V_49 = F_20 ( sizeof( struct V_46 ) * V_47 , V_50 ) ;
if ( ! V_49 )
* V_48 = - V_51 ;
else {
* V_48 = 0 ;
F_21 ( V_49 , V_47 ) ;
}
return V_49 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_52 * V_13 )
{
unsigned V_53 ;
V_53 = F_23 ( V_13 ) ;
if ( ! V_53 )
return;
F_24 ( V_54 , V_2 ) ;
V_2 -> V_55 . V_56 = V_53 ;
if ( V_13 -> V_57 == 0 && ! F_25 ( V_13 ) )
V_2 -> V_55 . V_58 = 1 ;
V_2 -> V_55 . V_59 = V_13 -> V_60 << 9 ;
if ( V_13 -> V_60 > V_53 )
V_2 -> V_55 . V_59 = 0 ;
if ( F_26 ( V_13 ) || F_27 ( V_13 ) )
F_24 ( V_61 , V_2 ) ;
}
int F_28 ( struct V_5 * V_6 , struct V_52 * V_13 ,
T_1 * V_41 , const char * V_62 )
{
struct V_63 * V_39 = V_13 -> V_39 ;
T_2 V_64 = V_65 ;
int V_66 ;
struct V_22 * V_26 = & V_6 -> V_67 [ 0 ] ;
struct V_22 * V_27 = & V_6 -> V_67 [ 1 ] ;
if ( F_29 ( V_39 ) -> V_68 && * F_29 ( V_39 ) -> V_68 )
V_64 = * F_29 ( V_39 ) -> V_68 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_17 = F_30 ( F_13 , V_41 ) ;
if ( ! V_6 -> V_17 )
return - V_51 ;
V_6 -> V_26 = V_26 ;
V_6 -> V_27 = V_27 ;
V_6 -> V_17 -> V_7 = V_6 ;
F_31 ( V_6 -> V_17 , F_1 ) ;
F_24 ( V_69 , V_6 -> V_17 ) ;
if ( F_32 ( V_13 ) )
F_22 ( V_6 -> V_17 , V_13 ) ;
#ifdef F_33
if ( V_39 -> V_70 == 1 ) {
unsigned int V_71 ;
V_71 = V_72 ;
if ( V_71 > V_39 -> V_73 )
V_71 = V_39 -> V_73 ;
if ( V_71 > V_39 -> V_74 )
V_71 = V_39 -> V_74 ;
if ( V_71 > ( V_39 -> V_75 * 512 ) )
V_71 = V_39 -> V_75 * 512 ;
if ( V_71 > 512 ) {
V_26 -> V_76 = F_20 ( V_71 , V_50 ) ;
if ( ! V_26 -> V_76 ) {
F_34 ( L_2
L_3 ,
F_35 ( V_13 ) ) ;
}
V_27 -> V_76 = F_20 ( V_71 , V_50 ) ;
if ( ! V_27 -> V_76 ) {
F_34 ( L_2
L_4 ,
F_35 ( V_13 ) ) ;
F_36 ( V_26 -> V_76 ) ;
V_26 -> V_76 = NULL ;
}
}
if ( V_26 -> V_76 && V_27 -> V_76 ) {
F_37 ( V_6 -> V_17 , V_77 ) ;
F_38 ( V_6 -> V_17 , V_71 / 512 ) ;
F_39 ( V_6 -> V_17 , V_71 / 512 ) ;
F_40 ( V_6 -> V_17 , V_71 ) ;
V_26 -> V_49 = F_19 ( 1 , & V_66 ) ;
if ( V_66 )
goto V_78;
V_26 -> V_79 =
F_19 ( V_71 / 512 , & V_66 ) ;
if ( V_66 )
goto V_78;
V_27 -> V_49 = F_19 ( 1 , & V_66 ) ;
if ( V_66 )
goto V_78;
V_27 -> V_79 =
F_19 ( V_71 / 512 , & V_66 ) ;
if ( V_66 )
goto V_78;
}
}
#endif
if ( ! V_26 -> V_76 && ! V_27 -> V_76 ) {
F_37 ( V_6 -> V_17 , V_64 ) ;
F_38 ( V_6 -> V_17 ,
F_41 ( V_39 -> V_75 , V_39 -> V_73 / 512 ) ) ;
F_39 ( V_6 -> V_17 , V_39 -> V_70 ) ;
F_40 ( V_6 -> V_17 , V_39 -> V_74 ) ;
V_26 -> V_49 = F_19 ( V_39 -> V_70 , & V_66 ) ;
if ( V_66 )
goto V_78;
V_27 -> V_49 = F_19 ( V_39 -> V_70 , & V_66 ) ;
if ( V_66 )
goto V_78;
}
F_42 ( & V_6 -> V_21 , 1 ) ;
V_6 -> V_45 = F_43 ( F_4 , V_6 , L_5 ,
V_39 -> V_80 , V_62 ? V_62 : L_6 ) ;
if ( F_44 ( V_6 -> V_45 ) ) {
V_66 = F_45 ( V_6 -> V_45 ) ;
goto V_81;
}
return 0 ;
V_81:
F_36 ( V_26 -> V_79 ) ;
V_26 -> V_79 = NULL ;
F_36 ( V_27 -> V_79 ) ;
V_27 -> V_79 = NULL ;
V_78:
F_36 ( V_26 -> V_49 ) ;
V_26 -> V_49 = NULL ;
F_36 ( V_26 -> V_76 ) ;
V_26 -> V_76 = NULL ;
F_36 ( V_27 -> V_49 ) ;
V_27 -> V_49 = NULL ;
F_36 ( V_27 -> V_76 ) ;
V_27 -> V_76 = NULL ;
F_46 ( V_6 -> V_17 ) ;
return V_66 ;
}
void F_47 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
struct V_22 * V_26 = V_6 -> V_26 ;
struct V_22 * V_27 = V_6 -> V_27 ;
F_48 ( V_6 ) ;
F_49 ( V_6 -> V_45 ) ;
F_15 ( V_2 -> V_24 , V_19 ) ;
V_2 -> V_7 = NULL ;
F_50 ( V_2 ) ;
F_17 ( V_2 -> V_24 , V_19 ) ;
F_36 ( V_26 -> V_79 ) ;
V_26 -> V_79 = NULL ;
F_36 ( V_26 -> V_49 ) ;
V_26 -> V_49 = NULL ;
F_36 ( V_26 -> V_76 ) ;
V_26 -> V_76 = NULL ;
F_36 ( V_27 -> V_79 ) ;
V_27 -> V_79 = NULL ;
F_36 ( V_27 -> V_49 ) ;
V_27 -> V_49 = NULL ;
F_36 ( V_27 -> V_76 ) ;
V_27 -> V_76 = NULL ;
V_6 -> V_13 = NULL ;
}
int F_51 ( struct V_5 * V_6 , struct V_52 * V_13 )
{
struct V_22 * V_26 = & V_6 -> V_67 [ 0 ] ;
struct V_22 * V_27 = & V_6 -> V_67 [ 1 ] ;
int V_66 = 0 ;
V_26 -> V_82 = F_52 ( sizeof( struct V_83 ) , V_50 ) ;
if ( ! V_26 -> V_82 ) {
F_53 ( L_7 ,
F_35 ( V_13 ) ) ;
V_66 = - V_51 ;
goto V_84;
}
V_27 -> V_82 = F_52 ( sizeof( struct V_83 ) , V_50 ) ;
if ( ! V_27 -> V_82 ) {
F_53 ( L_8 ,
F_35 ( V_13 ) ) ;
F_36 ( V_26 -> V_82 ) ;
V_26 -> V_82 = NULL ;
V_66 = - V_51 ;
goto V_84;
}
F_54 ( & V_26 -> V_82 -> V_85 ) ;
F_54 ( & V_27 -> V_82 -> V_85 ) ;
V_84:
return V_66 ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_22 * V_26 = & V_6 -> V_67 [ 0 ] ;
struct V_22 * V_27 = & V_6 -> V_67 [ 1 ] ;
F_36 ( V_26 -> V_82 ) ;
V_26 -> V_82 = NULL ;
F_36 ( V_27 -> V_82 ) ;
V_27 -> V_82 = NULL ;
}
void F_56 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
if ( ! ( V_6 -> V_19 & V_86 ) ) {
V_6 -> V_19 |= V_86 ;
F_15 ( V_2 -> V_24 , V_19 ) ;
F_57 ( V_2 ) ;
F_17 ( V_2 -> V_24 , V_19 ) ;
F_5 ( & V_6 -> V_21 ) ;
}
}
void F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_17 ;
unsigned long V_19 ;
if ( V_6 -> V_19 & V_86 ) {
V_6 -> V_19 &= ~ V_86 ;
F_11 ( & V_6 -> V_21 ) ;
F_15 ( V_2 -> V_24 , V_19 ) ;
F_50 ( V_2 ) ;
F_17 ( V_2 -> V_24 , V_19 ) ;
}
}
static unsigned int F_58 ( struct V_5 * V_6 ,
struct V_83 * V_82 ,
struct V_46 * V_49 ,
enum V_87 V_8 )
{
struct V_46 * V_88 = V_49 ;
unsigned int V_47 = 0 ;
struct V_3 * V_4 ;
if ( F_59 ( V_8 ) ) {
unsigned int V_89 = F_60 ( V_6 -> V_13 ) ? 4096 : 512 ;
unsigned int V_90 = F_61 ( V_6 -> V_17 ) ;
unsigned int V_91 , V_92 , V_93 = 0 ;
T_3 * V_94 = ( T_3 * ) V_82 -> V_95 ;
V_92 = V_89 ;
do {
V_91 = F_41 ( V_92 , V_90 ) ;
F_62 ( V_88 , V_94 + V_93 , V_91 ) ;
V_93 += V_91 ;
V_92 -= V_91 ;
( V_88 ++ ) -> V_96 &= ~ 0x02 ;
V_47 ++ ;
} while ( V_92 );
}
F_63 (req, &packed->list, queuelist) {
V_47 += F_64 ( V_6 -> V_17 , V_4 , V_88 ) ;
V_88 = V_49 + ( V_47 - 1 ) ;
( V_88 ++ ) -> V_96 &= ~ 0x02 ;
}
F_65 ( V_49 + ( V_47 - 1 ) ) ;
return V_47 ;
}
unsigned int F_66 ( struct V_5 * V_6 , struct V_22 * V_67 )
{
unsigned int V_47 ;
T_4 V_97 ;
struct V_46 * V_49 ;
enum V_87 V_8 ;
int V_98 ;
V_8 = V_67 -> V_8 ;
if ( ! V_67 -> V_76 ) {
if ( F_67 ( V_8 ) )
return F_58 ( V_6 , V_67 -> V_82 ,
V_67 -> V_49 , V_8 ) ;
else
return F_64 ( V_6 -> V_17 , V_67 -> V_4 , V_67 -> V_49 ) ;
}
F_68 ( ! V_67 -> V_79 ) ;
if ( F_67 ( V_8 ) )
V_47 = F_58 ( V_6 , V_67 -> V_82 ,
V_67 -> V_79 , V_8 ) ;
else
V_47 = F_64 ( V_6 -> V_17 , V_67 -> V_4 , V_67 -> V_79 ) ;
V_67 -> V_99 = V_47 ;
V_97 = 0 ;
F_69 (mqrq->bounce_sg, sg, sg_len, i)
V_97 += V_49 -> V_100 ;
F_70 ( V_67 -> V_49 , V_67 -> V_76 , V_97 ) ;
return 1 ;
}
void F_71 ( struct V_22 * V_67 )
{
if ( ! V_67 -> V_76 )
return;
if ( F_72 ( V_67 -> V_4 ) != V_101 )
return;
F_73 ( V_67 -> V_79 , V_67 -> V_99 ,
V_67 -> V_76 , V_67 -> V_49 [ 0 ] . V_100 ) ;
}
void F_74 ( struct V_22 * V_67 )
{
if ( ! V_67 -> V_76 )
return;
if ( F_72 ( V_67 -> V_4 ) != V_102 )
return;
F_75 ( V_67 -> V_79 , V_67 -> V_99 ,
V_67 -> V_76 , V_67 -> V_49 [ 0 ] . V_100 ) ;
}
