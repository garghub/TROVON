static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 && ( F_2 ( V_6 -> V_8 ) || F_3 ( V_6 ) ) )
return V_9 ;
V_4 -> V_10 |= V_11 ;
return V_12 ;
}
static int F_4 ( void * V_13 )
{
struct V_5 * V_6 = V_13 ;
struct V_1 * V_2 = V_6 -> V_14 ;
struct V_15 * V_16 = & V_6 -> V_8 -> V_17 -> V_18 ;
V_19 -> V_20 |= V_21 ;
F_5 ( & V_6 -> V_22 ) ;
do {
struct V_3 * V_4 = NULL ;
F_6 ( V_2 -> V_23 ) ;
F_7 ( V_24 ) ;
V_4 = F_8 ( V_2 ) ;
V_6 -> V_25 = false ;
V_16 -> V_26 = false ;
V_16 -> V_27 = false ;
if ( ! V_4 ) {
if ( V_6 -> V_28 -> V_4 )
V_16 -> V_26 = true ;
else
V_6 -> V_25 = true ;
}
V_6 -> V_29 -> V_4 = V_4 ;
F_9 ( V_2 -> V_23 ) ;
if ( V_4 || V_6 -> V_28 -> V_4 ) {
bool V_30 = F_10 ( V_4 ) ;
F_7 ( V_31 ) ;
F_11 ( V_6 , V_4 ) ;
F_12 () ;
if ( V_6 -> V_32 ) {
V_6 -> V_32 = false ;
continue;
}
if ( V_30 )
V_6 -> V_29 -> V_4 = NULL ;
V_6 -> V_28 -> V_33 . V_34 . V_35 = NULL ;
V_6 -> V_28 -> V_4 = NULL ;
F_13 ( V_6 -> V_28 , V_6 -> V_29 ) ;
} else {
if ( F_14 () ) {
F_7 ( V_31 ) ;
break;
}
F_15 ( & V_6 -> V_22 ) ;
F_16 () ;
F_5 ( & V_6 -> V_22 ) ;
}
} while ( 1 );
F_15 ( & V_6 -> V_22 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
if ( ! V_6 ) {
while ( ( V_4 = F_8 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_36 ;
F_18 ( V_4 , - V_37 ) ;
}
return;
}
V_16 = & V_6 -> V_8 -> V_17 -> V_18 ;
if ( V_16 -> V_26 ) {
V_16 -> V_27 = true ;
F_19 ( & V_16 -> V_38 ) ;
}
if ( V_6 -> V_25 )
F_20 ( V_6 -> V_39 ) ;
}
static struct V_40 * F_21 ( int V_41 , int * V_42 )
{
struct V_40 * V_43 ;
V_43 = F_22 ( V_41 , sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
* V_42 = - V_45 ;
else {
* V_42 = 0 ;
F_23 ( V_43 , V_41 ) ;
}
return V_43 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_46 * V_8 )
{
unsigned V_47 ;
V_47 = F_25 ( V_8 ) ;
if ( ! V_47 )
return;
F_26 ( V_48 , V_2 ) ;
F_27 ( V_2 , V_47 ) ;
if ( V_8 -> V_49 == 0 && ! F_28 ( V_8 ) )
V_2 -> V_50 . V_51 = 1 ;
V_2 -> V_50 . V_52 = V_8 -> V_53 << 9 ;
if ( V_8 -> V_53 > V_47 )
V_2 -> V_50 . V_52 = 0 ;
if ( F_29 ( V_8 ) )
F_26 ( V_54 , V_2 ) ;
}
static bool F_30 ( struct V_5 * V_6 ,
unsigned int V_55 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_6 -> V_57 ; V_56 ++ ) {
V_6 -> V_58 [ V_56 ] . V_59 = F_31 ( V_55 , V_44 ) ;
if ( ! V_6 -> V_58 [ V_56 ] . V_59 )
goto V_60;
}
return true ;
V_60:
while ( -- V_56 >= 0 ) {
F_32 ( V_6 -> V_58 [ V_56 ] . V_59 ) ;
V_6 -> V_58 [ V_56 ] . V_59 = NULL ;
}
F_33 ( L_1 ,
F_34 ( V_6 -> V_8 ) ) ;
return false ;
}
static int F_35 ( struct V_5 * V_6 ,
unsigned int V_55 )
{
int V_56 , V_61 ;
for ( V_56 = 0 ; V_56 < V_6 -> V_57 ; V_56 ++ ) {
V_6 -> V_58 [ V_56 ] . V_43 = F_21 ( 1 , & V_61 ) ;
if ( V_61 )
return V_61 ;
V_6 -> V_58 [ V_56 ] . V_62 = F_21 ( V_55 / 512 , & V_61 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_36 ( struct V_5 * V_6 , int V_63 )
{
int V_56 , V_61 ;
for ( V_56 = 0 ; V_56 < V_6 -> V_57 ; V_56 ++ ) {
V_6 -> V_58 [ V_56 ] . V_43 = F_21 ( V_63 , & V_61 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static void F_37 ( struct V_64 * V_58 )
{
F_32 ( V_58 -> V_62 ) ;
V_58 -> V_62 = NULL ;
F_32 ( V_58 -> V_43 ) ;
V_58 -> V_43 = NULL ;
F_32 ( V_58 -> V_59 ) ;
V_58 -> V_59 = NULL ;
}
static void F_38 ( struct V_5 * V_6 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_6 -> V_57 ; V_56 ++ )
F_37 ( & V_6 -> V_58 [ V_56 ] ) ;
}
int F_39 ( struct V_5 * V_6 , struct V_46 * V_8 ,
T_1 * V_65 , const char * V_66 )
{
struct V_67 * V_17 = V_8 -> V_17 ;
T_2 V_68 = V_69 ;
bool V_70 = false ;
int V_61 = - V_45 ;
if ( F_40 ( V_17 ) -> V_71 && * F_40 ( V_17 ) -> V_71 )
V_68 = ( T_2 ) F_41 ( F_40 ( V_17 ) ) << V_72 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_14 = F_42 ( F_17 , V_65 ) ;
if ( ! V_6 -> V_14 )
return - V_45 ;
V_6 -> V_57 = 2 ;
V_6 -> V_58 = F_43 ( V_6 -> V_57 , sizeof( struct V_64 ) ,
V_44 ) ;
if ( ! V_6 -> V_58 )
goto V_73;
V_6 -> V_29 = & V_6 -> V_58 [ 0 ] ;
V_6 -> V_28 = & V_6 -> V_58 [ 1 ] ;
V_6 -> V_14 -> V_7 = V_6 ;
F_44 ( V_6 -> V_14 , F_1 ) ;
F_26 ( V_74 , V_6 -> V_14 ) ;
F_45 ( V_75 , V_6 -> V_14 ) ;
if ( F_46 ( V_8 ) )
F_24 ( V_6 -> V_14 , V_8 ) ;
#ifdef F_47
if ( V_17 -> V_63 == 1 ) {
unsigned int V_55 ;
V_55 = V_76 ;
if ( V_55 > V_17 -> V_77 )
V_55 = V_17 -> V_77 ;
if ( V_55 > V_17 -> V_78 )
V_55 = V_17 -> V_78 ;
if ( V_55 > ( V_17 -> V_79 * 512 ) )
V_55 = V_17 -> V_79 * 512 ;
if ( V_55 > 512 &&
F_30 ( V_6 , V_55 ) ) {
F_48 ( V_6 -> V_14 , V_80 ) ;
F_49 ( V_6 -> V_14 , V_55 / 512 ) ;
F_50 ( V_6 -> V_14 , V_55 / 512 ) ;
F_51 ( V_6 -> V_14 , V_55 ) ;
V_61 = F_35 ( V_6 , V_55 ) ;
if ( V_61 )
goto V_81;
V_70 = true ;
}
}
#endif
if ( ! V_70 ) {
F_48 ( V_6 -> V_14 , V_68 ) ;
F_49 ( V_6 -> V_14 ,
F_52 ( V_17 -> V_79 , V_17 -> V_77 / 512 ) ) ;
F_50 ( V_6 -> V_14 , V_17 -> V_63 ) ;
F_51 ( V_6 -> V_14 , V_17 -> V_78 ) ;
V_61 = F_36 ( V_6 , V_17 -> V_63 ) ;
if ( V_61 )
goto V_81;
}
F_53 ( & V_6 -> V_22 , 1 ) ;
V_6 -> V_39 = F_54 ( F_4 , V_6 , L_2 ,
V_17 -> V_82 , V_66 ? V_66 : L_3 ) ;
if ( F_55 ( V_6 -> V_39 ) ) {
V_61 = F_56 ( V_6 -> V_39 ) ;
goto V_81;
}
return 0 ;
V_81:
F_38 ( V_6 ) ;
F_32 ( V_6 -> V_58 ) ;
V_6 -> V_58 = NULL ;
V_73:
F_57 ( V_6 -> V_14 ) ;
return V_61 ;
}
void F_58 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
F_59 ( V_6 ) ;
F_60 ( V_6 -> V_39 ) ;
F_61 ( V_2 -> V_23 , V_20 ) ;
V_2 -> V_7 = NULL ;
F_62 ( V_2 ) ;
F_63 ( V_2 -> V_23 , V_20 ) ;
F_38 ( V_6 ) ;
F_32 ( V_6 -> V_58 ) ;
V_6 -> V_58 = NULL ;
V_6 -> V_8 = NULL ;
}
void F_64 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
if ( ! V_6 -> V_83 ) {
V_6 -> V_83 |= true ;
F_61 ( V_2 -> V_23 , V_20 ) ;
F_65 ( V_2 ) ;
F_63 ( V_2 -> V_23 , V_20 ) ;
F_5 ( & V_6 -> V_22 ) ;
}
}
void F_59 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
if ( V_6 -> V_83 ) {
V_6 -> V_83 = false ;
F_15 ( & V_6 -> V_22 ) ;
F_61 ( V_2 -> V_23 , V_20 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 -> V_23 , V_20 ) ;
}
}
unsigned int F_66 ( struct V_5 * V_6 , struct V_64 * V_58 )
{
unsigned int V_41 ;
T_3 V_84 ;
struct V_40 * V_43 ;
int V_56 ;
if ( ! V_58 -> V_59 )
return F_67 ( V_6 -> V_14 , V_58 -> V_4 , V_58 -> V_43 ) ;
V_41 = F_67 ( V_6 -> V_14 , V_58 -> V_4 , V_58 -> V_62 ) ;
V_58 -> V_85 = V_41 ;
V_84 = 0 ;
F_68 (mqrq->bounce_sg, sg, sg_len, i)
V_84 += V_43 -> V_86 ;
F_69 ( V_58 -> V_43 , V_58 -> V_59 , V_84 ) ;
return 1 ;
}
void F_70 ( struct V_64 * V_58 )
{
if ( ! V_58 -> V_59 )
return;
if ( F_71 ( V_58 -> V_4 ) != V_87 )
return;
F_72 ( V_58 -> V_62 , V_58 -> V_85 ,
V_58 -> V_59 , V_58 -> V_43 [ 0 ] . V_86 ) ;
}
void F_73 ( struct V_64 * V_58 )
{
if ( ! V_58 -> V_59 )
return;
if ( F_71 ( V_58 -> V_4 ) != V_88 )
return;
F_74 ( V_58 -> V_62 , V_58 -> V_85 ,
V_58 -> V_59 , V_58 -> V_43 [ 0 ] . V_86 ) ;
}
