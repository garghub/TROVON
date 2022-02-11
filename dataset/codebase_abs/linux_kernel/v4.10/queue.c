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
struct V_19 * V_20 = & V_6 -> V_13 -> V_21 -> V_22 ;
V_23 -> V_24 |= V_25 ;
F_7 ( & V_6 -> V_26 ) ;
do {
struct V_3 * V_4 = NULL ;
F_8 ( V_2 -> V_27 ) ;
F_9 ( V_28 ) ;
V_4 = F_10 ( V_2 ) ;
V_6 -> V_29 = false ;
V_20 -> V_30 = false ;
V_20 -> V_31 = false ;
if ( ! V_4 ) {
if ( V_6 -> V_32 -> V_4 )
V_20 -> V_30 = true ;
else
V_6 -> V_29 = true ;
}
V_6 -> V_33 -> V_4 = V_4 ;
F_11 ( V_2 -> V_27 ) ;
if ( V_4 || V_6 -> V_32 -> V_4 ) {
bool V_34 = F_12 ( V_4 ) ;
F_9 ( V_35 ) ;
F_13 ( V_6 , V_4 ) ;
F_14 () ;
if ( V_6 -> V_24 & V_36 ) {
V_6 -> V_24 &= ~ V_36 ;
continue;
}
if ( V_34 )
V_6 -> V_33 -> V_4 = NULL ;
V_6 -> V_32 -> V_37 . V_38 . V_39 = NULL ;
V_6 -> V_32 -> V_4 = NULL ;
F_15 ( V_6 -> V_32 , V_6 -> V_33 ) ;
} else {
if ( F_16 () ) {
F_9 ( V_35 ) ;
break;
}
F_17 ( & V_6 -> V_26 ) ;
F_18 () ;
F_7 ( & V_6 -> V_26 ) ;
}
} while ( 1 );
F_17 ( & V_6 -> V_26 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
struct V_19 * V_20 ;
if ( ! V_6 ) {
while ( ( V_4 = F_10 ( V_2 ) ) != NULL ) {
V_4 -> V_14 |= V_40 ;
F_20 ( V_4 , - V_41 ) ;
}
return;
}
V_20 = & V_6 -> V_13 -> V_21 -> V_22 ;
if ( V_20 -> V_30 ) {
V_20 -> V_31 = true ;
F_21 ( & V_20 -> V_42 ) ;
}
if ( V_6 -> V_29 )
F_22 ( V_6 -> V_43 ) ;
}
static struct V_44 * F_23 ( int V_45 , int * V_46 )
{
struct V_44 * V_47 ;
V_47 = F_24 ( sizeof( struct V_44 ) * V_45 , V_48 ) ;
if ( ! V_47 )
* V_46 = - V_49 ;
else {
* V_46 = 0 ;
F_25 ( V_47 , V_45 ) ;
}
return V_47 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_50 * V_13 )
{
unsigned V_51 ;
V_51 = F_27 ( V_13 ) ;
if ( ! V_51 )
return;
F_28 ( V_52 , V_2 ) ;
F_29 ( V_2 , V_51 ) ;
if ( V_13 -> V_53 == 0 && ! F_30 ( V_13 ) )
V_2 -> V_54 . V_55 = 1 ;
V_2 -> V_54 . V_56 = V_13 -> V_57 << 9 ;
if ( V_13 -> V_57 > V_51 )
V_2 -> V_54 . V_56 = 0 ;
if ( F_31 ( V_13 ) )
F_28 ( V_58 , V_2 ) ;
}
static bool F_32 ( struct V_5 * V_6 ,
unsigned int V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_61 ; V_60 ++ ) {
V_6 -> V_62 [ V_60 ] . V_63 = F_24 ( V_59 , V_48 ) ;
if ( ! V_6 -> V_62 [ V_60 ] . V_63 )
goto V_64;
}
return true ;
V_64:
while ( -- V_60 >= 0 ) {
F_33 ( V_6 -> V_62 [ V_60 ] . V_63 ) ;
V_6 -> V_62 [ V_60 ] . V_63 = NULL ;
}
F_34 ( L_2 ,
F_35 ( V_6 -> V_13 ) ) ;
return false ;
}
static int F_36 ( struct V_5 * V_6 ,
unsigned int V_59 )
{
int V_60 , V_65 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_61 ; V_60 ++ ) {
V_6 -> V_62 [ V_60 ] . V_47 = F_23 ( 1 , & V_65 ) ;
if ( V_65 )
return V_65 ;
V_6 -> V_62 [ V_60 ] . V_66 = F_23 ( V_59 / 512 , & V_65 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 , int V_67 )
{
int V_60 , V_65 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_61 ; V_60 ++ ) {
V_6 -> V_62 [ V_60 ] . V_47 = F_23 ( V_67 , & V_65 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static void F_38 ( struct V_68 * V_62 )
{
F_33 ( V_62 -> V_66 ) ;
V_62 -> V_66 = NULL ;
F_33 ( V_62 -> V_47 ) ;
V_62 -> V_47 = NULL ;
F_33 ( V_62 -> V_63 ) ;
V_62 -> V_63 = NULL ;
}
static void F_39 ( struct V_5 * V_6 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_61 ; V_60 ++ )
F_38 ( & V_6 -> V_62 [ V_60 ] ) ;
}
int F_40 ( struct V_5 * V_6 , struct V_50 * V_13 ,
T_1 * V_69 , const char * V_70 )
{
struct V_71 * V_21 = V_13 -> V_21 ;
T_2 V_72 = V_73 ;
bool V_74 = false ;
int V_65 = - V_49 ;
if ( F_41 ( V_21 ) -> V_75 && * F_41 ( V_21 ) -> V_75 )
V_72 = ( T_2 ) F_42 ( F_41 ( V_21 ) ) << V_76 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_18 = F_43 ( F_19 , V_69 ) ;
if ( ! V_6 -> V_18 )
return - V_49 ;
V_6 -> V_61 = 2 ;
V_6 -> V_62 = F_44 ( V_6 -> V_61 , sizeof( struct V_68 ) ,
V_48 ) ;
if ( ! V_6 -> V_62 )
goto V_77;
V_6 -> V_33 = & V_6 -> V_62 [ 0 ] ;
V_6 -> V_32 = & V_6 -> V_62 [ 1 ] ;
V_6 -> V_18 -> V_7 = V_6 ;
F_45 ( V_6 -> V_18 , F_1 ) ;
F_28 ( V_78 , V_6 -> V_18 ) ;
F_46 ( V_79 , V_6 -> V_18 ) ;
if ( F_47 ( V_13 ) )
F_26 ( V_6 -> V_18 , V_13 ) ;
#ifdef F_48
if ( V_21 -> V_67 == 1 ) {
unsigned int V_59 ;
V_59 = V_80 ;
if ( V_59 > V_21 -> V_81 )
V_59 = V_21 -> V_81 ;
if ( V_59 > V_21 -> V_82 )
V_59 = V_21 -> V_82 ;
if ( V_59 > ( V_21 -> V_83 * 512 ) )
V_59 = V_21 -> V_83 * 512 ;
if ( V_59 > 512 &&
F_32 ( V_6 , V_59 ) ) {
F_49 ( V_6 -> V_18 , V_84 ) ;
F_50 ( V_6 -> V_18 , V_59 / 512 ) ;
F_51 ( V_6 -> V_18 , V_59 / 512 ) ;
F_52 ( V_6 -> V_18 , V_59 ) ;
V_65 = F_36 ( V_6 , V_59 ) ;
if ( V_65 )
goto V_85;
V_74 = true ;
}
}
#endif
if ( ! V_74 ) {
F_49 ( V_6 -> V_18 , V_72 ) ;
F_50 ( V_6 -> V_18 ,
F_53 ( V_21 -> V_83 , V_21 -> V_81 / 512 ) ) ;
F_51 ( V_6 -> V_18 , V_21 -> V_67 ) ;
F_52 ( V_6 -> V_18 , V_21 -> V_82 ) ;
V_65 = F_37 ( V_6 , V_21 -> V_67 ) ;
if ( V_65 )
goto V_85;
}
F_54 ( & V_6 -> V_26 , 1 ) ;
V_6 -> V_43 = F_55 ( F_6 , V_6 , L_3 ,
V_21 -> V_86 , V_70 ? V_70 : L_4 ) ;
if ( F_56 ( V_6 -> V_43 ) ) {
V_65 = F_57 ( V_6 -> V_43 ) ;
goto V_85;
}
return 0 ;
V_85:
F_39 ( V_6 ) ;
F_33 ( V_6 -> V_62 ) ;
V_6 -> V_62 = NULL ;
V_77:
F_58 ( V_6 -> V_18 ) ;
return V_65 ;
}
void F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_24 ;
F_60 ( V_6 ) ;
F_61 ( V_6 -> V_43 ) ;
F_62 ( V_2 -> V_27 , V_24 ) ;
V_2 -> V_7 = NULL ;
F_63 ( V_2 ) ;
F_64 ( V_2 -> V_27 , V_24 ) ;
F_39 ( V_6 ) ;
F_33 ( V_6 -> V_62 ) ;
V_6 -> V_62 = NULL ;
V_6 -> V_13 = NULL ;
}
void F_65 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_24 ;
if ( ! ( V_6 -> V_24 & V_87 ) ) {
V_6 -> V_24 |= V_87 ;
F_62 ( V_2 -> V_27 , V_24 ) ;
F_66 ( V_2 ) ;
F_64 ( V_2 -> V_27 , V_24 ) ;
F_7 ( & V_6 -> V_26 ) ;
}
}
void F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_18 ;
unsigned long V_24 ;
if ( V_6 -> V_24 & V_87 ) {
V_6 -> V_24 &= ~ V_87 ;
F_17 ( & V_6 -> V_26 ) ;
F_62 ( V_2 -> V_27 , V_24 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 -> V_27 , V_24 ) ;
}
}
unsigned int F_67 ( struct V_5 * V_6 , struct V_68 * V_62 )
{
unsigned int V_45 ;
T_3 V_88 ;
struct V_44 * V_47 ;
int V_60 ;
if ( ! V_62 -> V_63 )
return F_68 ( V_6 -> V_18 , V_62 -> V_4 , V_62 -> V_47 ) ;
V_45 = F_68 ( V_6 -> V_18 , V_62 -> V_4 , V_62 -> V_66 ) ;
V_62 -> V_89 = V_45 ;
V_88 = 0 ;
F_69 (mqrq->bounce_sg, sg, sg_len, i)
V_88 += V_47 -> V_90 ;
F_70 ( V_62 -> V_47 , V_62 -> V_63 , V_88 ) ;
return 1 ;
}
void F_71 ( struct V_68 * V_62 )
{
if ( ! V_62 -> V_63 )
return;
if ( F_72 ( V_62 -> V_4 ) != V_91 )
return;
F_73 ( V_62 -> V_66 , V_62 -> V_89 ,
V_62 -> V_63 , V_62 -> V_47 [ 0 ] . V_90 ) ;
}
void F_74 ( struct V_68 * V_62 )
{
if ( ! V_62 -> V_63 )
return;
if ( F_72 ( V_62 -> V_4 ) != V_92 )
return;
F_75 ( V_62 -> V_66 , V_62 -> V_89 ,
V_62 -> V_63 , V_62 -> V_47 [ 0 ] . V_90 ) ;
}
