static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 && ( F_2 ( V_6 -> V_8 ) || F_3 ( V_6 ) ) )
return V_9 ;
V_4 -> V_10 |= V_11 ;
return V_12 ;
}
struct V_13 * F_4 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 ;
int V_15 = F_5 ( V_6 -> V_16 ) ;
if ( V_15 >= V_6 -> V_17 )
return NULL ;
V_14 = & V_6 -> V_14 [ V_15 ] ;
F_6 ( V_14 -> V_4 || V_6 -> V_18 >= V_6 -> V_17 ||
F_7 ( V_14 -> V_19 , & V_6 -> V_16 ) ) ;
V_14 -> V_4 = V_4 ;
V_6 -> V_18 += 1 ;
F_8 ( V_14 -> V_19 , & V_6 -> V_16 ) ;
return V_14 ;
}
void F_9 ( struct V_5 * V_6 ,
struct V_13 * V_14 )
{
F_6 ( ! V_14 -> V_4 || V_6 -> V_18 < 1 ||
! F_7 ( V_14 -> V_19 , & V_6 -> V_16 ) ) ;
V_14 -> V_4 = NULL ;
V_6 -> V_18 -= 1 ;
F_10 ( V_14 -> V_19 , & V_6 -> V_16 ) ;
}
static int F_11 ( void * V_20 )
{
struct V_5 * V_6 = V_20 ;
struct V_1 * V_2 = V_6 -> V_21 ;
struct V_22 * V_23 = & V_6 -> V_8 -> V_24 -> V_25 ;
V_26 -> V_27 |= V_28 ;
F_12 ( & V_6 -> V_29 ) ;
do {
struct V_3 * V_4 ;
F_13 ( V_2 -> V_30 ) ;
F_14 ( V_31 ) ;
V_4 = F_15 ( V_2 ) ;
V_6 -> V_32 = false ;
V_23 -> V_33 = false ;
V_23 -> V_34 = false ;
if ( ! V_4 ) {
if ( V_6 -> V_18 )
V_23 -> V_33 = true ;
else
V_6 -> V_32 = true ;
}
F_16 ( V_2 -> V_30 ) ;
if ( V_4 || V_6 -> V_18 ) {
F_14 ( V_35 ) ;
F_17 ( V_6 , V_4 ) ;
F_18 () ;
} else {
if ( F_19 () ) {
F_14 ( V_35 ) ;
break;
}
F_20 ( & V_6 -> V_29 ) ;
F_21 () ;
F_12 ( & V_6 -> V_29 ) ;
}
} while ( 1 );
F_20 ( & V_6 -> V_29 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
struct V_22 * V_23 ;
if ( ! V_6 ) {
while ( ( V_4 = F_15 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_36 ;
F_23 ( V_4 , - V_37 ) ;
}
return;
}
V_23 = & V_6 -> V_8 -> V_24 -> V_25 ;
if ( V_23 -> V_33 ) {
V_23 -> V_34 = true ;
F_24 ( & V_23 -> V_38 ) ;
}
if ( V_6 -> V_32 )
F_25 ( V_6 -> V_39 ) ;
}
static struct V_40 * F_26 ( int V_41 )
{
struct V_40 * V_42 ;
V_42 = F_27 ( V_41 , sizeof( * V_42 ) , V_43 ) ;
if ( V_42 )
F_28 ( V_42 , V_41 ) ;
return V_42 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_44 * V_8 )
{
unsigned V_45 ;
V_45 = F_30 ( V_8 ) ;
if ( ! V_45 )
return;
F_31 ( V_46 , V_2 ) ;
F_32 ( V_2 , V_45 ) ;
V_2 -> V_47 . V_48 = V_8 -> V_49 << 9 ;
if ( V_8 -> V_49 > V_45 )
V_2 -> V_47 . V_48 = 0 ;
if ( F_33 ( V_8 ) )
F_31 ( V_50 , V_2 ) ;
}
static void F_34 ( struct V_13 * V_14 )
{
F_35 ( V_14 -> V_51 ) ;
V_14 -> V_51 = NULL ;
F_35 ( V_14 -> V_42 ) ;
V_14 -> V_42 = NULL ;
F_35 ( V_14 -> V_52 ) ;
V_14 -> V_52 = NULL ;
}
static void F_36 ( struct V_13 * V_14 , int V_17 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
F_34 ( & V_14 [ V_15 ] ) ;
}
static void F_37 ( struct V_13 * V_14 , int V_17 )
{
F_36 ( V_14 , V_17 ) ;
F_35 ( V_14 ) ;
}
static struct V_13 * F_38 ( int V_17 )
{
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_39 ( V_17 , sizeof( * V_14 ) , V_43 ) ;
if ( V_14 ) {
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
V_14 [ V_15 ] . V_19 = V_15 ;
}
return V_14 ;
}
static int F_40 ( struct V_13 * V_14 , int V_17 ,
unsigned int V_53 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ ) {
V_14 [ V_15 ] . V_52 = F_41 ( V_53 , V_43 ) ;
if ( ! V_14 [ V_15 ] . V_52 )
return - V_54 ;
V_14 [ V_15 ] . V_42 = F_26 ( 1 ) ;
if ( ! V_14 [ V_15 ] . V_42 )
return - V_54 ;
V_14 [ V_15 ] . V_51 = F_26 ( V_53 / 512 ) ;
if ( ! V_14 [ V_15 ] . V_51 )
return - V_54 ;
}
return 0 ;
}
static bool F_42 ( struct V_13 * V_14 , int V_17 ,
unsigned int V_53 )
{
int V_55 ;
V_55 = F_40 ( V_14 , V_17 , V_53 ) ;
if ( V_55 )
F_36 ( V_14 , V_17 ) ;
return ! V_55 ;
}
static unsigned int F_43 ( struct V_56 * V_24 )
{
unsigned int V_53 = V_57 ;
if ( V_24 -> V_58 != 1 )
return 0 ;
if ( V_53 > V_24 -> V_59 )
V_53 = V_24 -> V_59 ;
if ( V_53 > V_24 -> V_60 )
V_53 = V_24 -> V_60 ;
if ( V_53 > V_24 -> V_61 * 512 )
V_53 = V_24 -> V_61 * 512 ;
if ( V_53 <= 512 )
return 0 ;
return V_53 ;
}
static inline bool F_42 ( struct V_13 * V_14 ,
int V_17 , unsigned int V_53 )
{
return false ;
}
static unsigned int F_43 ( struct V_56 * V_24 )
{
return 0 ;
}
static int F_44 ( struct V_13 * V_14 , int V_17 ,
int V_58 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ ) {
V_14 [ V_15 ] . V_42 = F_26 ( V_58 ) ;
if ( ! V_14 [ V_15 ] . V_42 )
return - V_54 ;
}
return 0 ;
}
void F_45 ( struct V_44 * V_8 )
{
if ( V_8 -> V_14 ) {
F_37 ( V_8 -> V_14 , V_8 -> V_17 ) ;
V_8 -> V_14 = NULL ;
}
}
static int F_46 ( struct V_44 * V_8 , int V_17 )
{
struct V_56 * V_24 = V_8 -> V_24 ;
struct V_13 * V_14 ;
unsigned int V_53 ;
int V_55 = 0 ;
if ( V_8 -> V_14 )
return - V_62 ;
V_14 = F_38 ( V_17 ) ;
if ( ! V_14 )
return - V_54 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_17 = V_17 ;
V_53 = F_43 ( V_24 ) ;
if ( V_53 && ! F_42 ( V_14 , V_17 , V_53 ) ) {
V_53 = 0 ;
F_47 ( L_1 ,
F_48 ( V_8 ) ) ;
}
V_8 -> V_53 = V_53 ;
if ( ! V_53 ) {
V_55 = F_44 ( V_14 , V_17 , V_24 -> V_58 ) ;
if ( V_55 )
goto V_63;
}
return V_55 ;
V_63:
F_45 ( V_8 ) ;
return V_55 ;
}
int F_49 ( struct V_44 * V_8 )
{
return F_46 ( V_8 , 2 ) ;
}
int F_50 ( struct V_5 * V_6 , struct V_44 * V_8 ,
T_1 * V_64 , const char * V_65 )
{
struct V_56 * V_24 = V_8 -> V_24 ;
T_2 V_66 = V_67 ;
int V_55 = - V_54 ;
if ( F_51 ( V_24 ) -> V_68 && * F_51 ( V_24 ) -> V_68 )
V_66 = ( T_2 ) F_52 ( F_51 ( V_24 ) ) << V_69 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_21 = F_53 ( F_22 , V_64 ) ;
if ( ! V_6 -> V_21 )
return - V_54 ;
V_6 -> V_14 = V_8 -> V_14 ;
V_6 -> V_17 = V_8 -> V_17 ;
V_6 -> V_21 -> V_7 = V_6 ;
F_54 ( V_6 -> V_21 , F_1 ) ;
F_31 ( V_70 , V_6 -> V_21 ) ;
F_55 ( V_71 , V_6 -> V_21 ) ;
if ( F_56 ( V_8 ) )
F_29 ( V_6 -> V_21 , V_8 ) ;
if ( V_8 -> V_53 ) {
F_57 ( V_6 -> V_21 , V_72 ) ;
F_58 ( V_6 -> V_21 , V_8 -> V_53 / 512 ) ;
F_59 ( V_6 -> V_21 , V_8 -> V_53 / 512 ) ;
F_60 ( V_6 -> V_21 , V_8 -> V_53 ) ;
} else {
F_57 ( V_6 -> V_21 , V_66 ) ;
F_58 ( V_6 -> V_21 ,
F_61 ( V_24 -> V_61 , V_24 -> V_59 / 512 ) ) ;
F_59 ( V_6 -> V_21 , V_24 -> V_58 ) ;
F_60 ( V_6 -> V_21 , V_24 -> V_60 ) ;
}
F_62 ( & V_6 -> V_29 , 1 ) ;
V_6 -> V_39 = F_63 ( F_11 , V_6 , L_2 ,
V_24 -> V_73 , V_65 ? V_65 : L_3 ) ;
if ( F_64 ( V_6 -> V_39 ) ) {
V_55 = F_65 ( V_6 -> V_39 ) ;
goto V_74;
}
return 0 ;
V_74:
V_6 -> V_14 = NULL ;
F_66 ( V_6 -> V_21 ) ;
return V_55 ;
}
void F_67 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_21 ;
unsigned long V_27 ;
F_68 ( V_6 ) ;
F_69 ( V_6 -> V_39 ) ;
F_70 ( V_2 -> V_30 , V_27 ) ;
V_2 -> V_7 = NULL ;
F_71 ( V_2 ) ;
F_72 ( V_2 -> V_30 , V_27 ) ;
V_6 -> V_14 = NULL ;
V_6 -> V_8 = NULL ;
}
void F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_21 ;
unsigned long V_27 ;
if ( ! V_6 -> V_75 ) {
V_6 -> V_75 |= true ;
F_70 ( V_2 -> V_30 , V_27 ) ;
F_74 ( V_2 ) ;
F_72 ( V_2 -> V_30 , V_27 ) ;
F_12 ( & V_6 -> V_29 ) ;
}
}
void F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_21 ;
unsigned long V_27 ;
if ( V_6 -> V_75 ) {
V_6 -> V_75 = false ;
F_20 ( & V_6 -> V_29 ) ;
F_70 ( V_2 -> V_30 , V_27 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 -> V_30 , V_27 ) ;
}
}
unsigned int F_75 ( struct V_5 * V_6 , struct V_13 * V_14 )
{
unsigned int V_41 ;
T_3 V_76 ;
struct V_40 * V_42 ;
int V_15 ;
if ( ! V_14 -> V_52 )
return F_76 ( V_6 -> V_21 , V_14 -> V_4 , V_14 -> V_42 ) ;
V_41 = F_76 ( V_6 -> V_21 , V_14 -> V_4 , V_14 -> V_51 ) ;
V_14 -> V_77 = V_41 ;
V_76 = 0 ;
F_77 (mqrq->bounce_sg, sg, sg_len, i)
V_76 += V_42 -> V_78 ;
F_78 ( V_14 -> V_42 , V_14 -> V_52 , V_76 ) ;
return 1 ;
}
void F_79 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_52 )
return;
if ( F_80 ( V_14 -> V_4 ) != V_79 )
return;
F_81 ( V_14 -> V_51 , V_14 -> V_77 ,
V_14 -> V_52 , V_14 -> V_42 [ 0 ] . V_78 ) ;
}
void F_82 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_52 )
return;
if ( F_80 ( V_14 -> V_4 ) != V_80 )
return;
F_83 ( V_14 -> V_51 , V_14 -> V_77 ,
V_14 -> V_52 , V_14 -> V_42 [ 0 ] . V_78 ) ;
}
