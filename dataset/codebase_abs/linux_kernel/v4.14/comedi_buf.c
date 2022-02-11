static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
F_2 ( V_1 , struct V_2 , V_4 ) ;
struct V_5 * V_6 ;
unsigned int V_7 ;
if ( V_3 -> V_8 ) {
for ( V_7 = 0 ; V_7 < V_3 -> V_9 ; V_7 ++ ) {
V_6 = & V_3 -> V_8 [ V_7 ] ;
F_3 ( V_10 ,
& ( F_4 ( V_6 -> V_11 ) -> V_12 ) ) ;
if ( V_3 -> V_13 != V_14 ) {
#ifdef F_5
F_6 ( V_3 -> V_15 ,
V_16 ,
V_6 -> V_11 ,
V_6 -> V_17 ) ;
#endif
} else {
F_7 ( ( unsigned long ) V_6 -> V_11 ) ;
}
}
F_8 ( V_3 -> V_8 ) ;
}
if ( V_3 -> V_13 != V_14 )
F_9 ( V_3 -> V_15 ) ;
F_10 ( V_3 ) ;
}
static void F_11 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_2 * V_3 ;
unsigned long V_12 ;
if ( V_23 -> V_24 ) {
F_12 ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
V_23 -> V_25 = 0 ;
}
F_13 ( & V_21 -> V_26 , V_12 ) ;
V_3 = V_23 -> V_27 ;
V_23 -> V_27 = NULL ;
F_14 ( & V_21 -> V_26 , V_12 ) ;
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
unsigned int V_9 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_28 * * V_29 = NULL ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned long V_12 ;
unsigned int V_7 ;
if ( ! F_17 ( F_5 ) && V_21 -> V_30 != V_14 ) {
F_18 ( V_19 -> V_31 ,
L_1 ) ;
return;
}
V_3 = F_19 ( sizeof( * V_23 -> V_27 ) , V_32 ) ;
if ( ! V_3 )
return;
F_20 ( & V_3 -> V_4 ) ;
F_13 ( & V_21 -> V_26 , V_12 ) ;
V_23 -> V_27 = V_3 ;
F_14 ( & V_21 -> V_26 , V_12 ) ;
V_3 -> V_13 = V_21 -> V_30 ;
if ( V_3 -> V_13 != V_14 )
V_3 -> V_15 = F_21 ( V_19 -> V_33 ) ;
V_3 -> V_8 = F_22 ( sizeof( * V_6 ) * V_9 ) ;
if ( V_3 -> V_8 )
V_29 = F_23 ( sizeof( struct V_28 * ) * V_9 ) ;
if ( ! V_29 )
return;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_6 = & V_3 -> V_8 [ V_7 ] ;
if ( V_3 -> V_13 != V_14 )
#ifdef F_5
V_6 -> V_11 = F_24 ( V_3 -> V_15 ,
V_16 ,
& V_6 -> V_17 ,
V_32 |
V_34 ) ;
#else
break;
#endif
else
V_6 -> V_11 = ( void * ) F_25 ( V_32 ) ;
if ( ! V_6 -> V_11 )
break;
F_26 ( V_10 , & ( F_4 ( V_6 -> V_11 ) -> V_12 ) ) ;
V_29 [ V_7 ] = F_4 ( V_6 -> V_11 ) ;
}
F_13 ( & V_21 -> V_26 , V_12 ) ;
V_3 -> V_9 = V_7 ;
F_14 ( & V_21 -> V_26 , V_12 ) ;
if ( V_7 == V_9 )
V_23 -> V_24 = F_27 ( V_29 , V_9 , V_35 ,
V_36 ) ;
F_8 ( V_29 ) ;
}
void F_28 ( struct V_2 * V_3 )
{
if ( V_3 )
F_29 ( & V_3 -> V_4 ) ;
}
int F_15 ( struct V_2 * V_3 )
{
if ( V_3 )
return F_30 ( & V_3 -> V_4 , F_1 ) ;
return 1 ;
}
int F_31 ( struct V_2 * V_3 , unsigned long V_37 ,
void * V_6 , int V_38 , int V_39 )
{
unsigned int V_40 = F_32 ( V_37 ) ;
unsigned long V_41 = V_37 >> V_42 ;
int V_43 = 0 ;
while ( V_43 < V_38 && V_41 < V_3 -> V_9 ) {
int V_44 = F_33 ( int , V_38 - V_43 , V_16 - V_40 ) ;
void * V_45 = V_3 -> V_8 [ V_41 ] . V_11 + V_40 ;
if ( V_39 )
memcpy ( V_45 , V_6 , V_44 ) ;
else
memcpy ( V_6 , V_45 , V_44 ) ;
V_6 += V_44 ;
V_43 += V_44 ;
V_41 ++ ;
V_40 = 0 ;
}
return V_43 ;
}
struct V_2 *
F_34 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_2 * V_3 = NULL ;
unsigned long V_12 ;
if ( ! V_23 )
return NULL ;
F_13 ( & V_21 -> V_26 , V_12 ) ;
V_3 = V_23 -> V_27 ;
if ( V_3 && V_3 -> V_9 )
F_28 ( V_3 ) ;
else
V_3 = NULL ;
F_14 ( & V_21 -> V_26 , V_12 ) ;
return V_3 ;
}
bool F_35 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = V_21 -> V_23 -> V_27 ;
return V_3 && ( F_36 ( & V_3 -> V_4 ) > 1 ) ;
}
int F_37 ( struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long V_46 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
V_46 = ( V_46 + V_16 - 1 ) & V_47 ;
if ( V_23 -> V_24 && V_23 -> V_25 == V_46 )
return 0 ;
F_11 ( V_19 , V_21 ) ;
if ( V_46 ) {
unsigned int V_9 = V_46 >> V_42 ;
F_16 ( V_19 , V_21 , V_9 ) ;
if ( ! V_23 -> V_24 ) {
F_11 ( V_19 , V_21 ) ;
return - V_48 ;
}
}
V_23 -> V_25 = V_46 ;
return 0 ;
}
void F_38 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
V_23 -> V_49 = 0 ;
V_23 -> V_50 = 0 ;
V_23 -> V_51 = 0 ;
V_23 -> V_52 = 0 ;
V_23 -> V_53 = 0 ;
V_23 -> V_54 = 0 ;
V_23 -> V_55 = 0 ;
V_23 -> V_56 = 0 ;
V_23 -> V_57 = 0 ;
V_23 -> V_58 = 0 ;
V_23 -> V_59 = 0 ;
V_23 -> V_60 = 0 ;
V_23 -> V_61 = 0 ;
}
static unsigned int F_39 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_62 = V_23 -> V_52 + V_23 -> V_25 ;
return V_62 - V_23 -> V_49 ;
}
unsigned int F_40 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_62 = V_23 -> V_52 + V_23 -> V_25 ;
return V_62 - V_23 -> V_50 ;
}
unsigned int F_41 ( struct V_20 * V_21 ,
unsigned int V_63 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_64 = F_39 ( V_21 ) ;
if ( V_63 > V_64 )
V_63 = V_64 ;
V_23 -> V_49 += V_63 ;
F_42 () ;
return V_63 ;
}
static unsigned int F_43 ( struct V_20 * V_21 ,
unsigned int V_65 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_66 = 0 ;
const unsigned int V_67 = F_44 ( V_21 ) ;
if ( ! V_21 -> V_68 || ( V_23 -> V_69 . V_12 & V_70 ) ) {
V_23 -> V_59 += V_65 ;
V_66 = V_65 ;
} else {
V_65 -= V_65 % V_67 ;
while ( V_66 < V_65 ) {
int V_71 = V_65 - V_66 ;
unsigned int V_72 ;
V_72 = V_23 -> V_25 - V_23 -> V_60 ;
if ( V_71 > V_72 )
V_71 = V_72 ;
V_21 -> V_68 ( V_21 -> V_73 , V_21 ,
V_23 -> V_24 + V_23 -> V_60 ,
V_71 , V_23 -> V_58 ) ;
F_45 () ;
V_23 -> V_58 += V_71 / V_67 ;
V_23 -> V_58 %= V_23 -> V_69 . V_74 ;
V_23 -> V_59 += V_71 ;
V_23 -> V_60 += V_71 ;
V_23 -> V_60 %= V_23 -> V_25 ;
V_66 += V_71 ;
}
}
return V_66 ;
}
unsigned int F_46 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
return V_23 -> V_49 - V_23 -> V_50 ;
}
unsigned int F_47 ( struct V_20 * V_21 ,
unsigned int V_63 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_75 = F_46 ( V_21 ) ;
if ( V_63 > V_75 )
V_63 = V_75 ;
V_23 -> V_50 += V_63 ;
V_23 -> V_53 += V_63 ;
F_43 ( V_21 , V_23 -> V_50 - V_23 -> V_59 ) ;
if ( V_23 -> V_53 >= V_23 -> V_25 )
V_23 -> V_53 %= V_23 -> V_25 ;
return V_63 ;
}
unsigned int F_48 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_65 ;
if ( ! V_23 )
return 0 ;
V_65 = V_23 -> V_59 - V_23 -> V_52 ;
F_49 () ;
return V_65 ;
}
unsigned int F_50 ( struct V_20 * V_21 ,
unsigned int V_63 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_76 ;
V_76 = V_23 -> V_59 - V_23 -> V_51 ;
if ( V_63 > V_76 )
V_63 = V_76 ;
V_23 -> V_51 += V_63 ;
F_49 () ;
return V_63 ;
}
static unsigned int F_51 ( struct V_22 * V_23 )
{
return V_23 -> V_51 - V_23 -> V_52 ;
}
unsigned int F_52 ( struct V_20 * V_21 ,
unsigned int V_63 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_75 ;
F_42 () ;
V_75 = F_51 ( V_23 ) ;
if ( V_63 > V_75 )
V_63 = V_75 ;
V_23 -> V_52 += V_63 ;
V_23 -> V_54 += V_63 ;
V_23 -> V_54 %= V_23 -> V_25 ;
return V_63 ;
}
static void F_53 ( struct V_20 * V_21 ,
const void * V_77 , unsigned int V_65 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_78 = V_23 -> V_53 ;
while ( V_65 ) {
unsigned int V_71 ;
if ( V_78 + V_65 > V_23 -> V_25 )
V_71 = V_23 -> V_25 - V_78 ;
else
V_71 = V_65 ;
memcpy ( V_23 -> V_24 + V_78 , V_77 , V_71 ) ;
V_77 += V_71 ;
V_65 -= V_71 ;
V_78 = 0 ;
}
}
static void F_54 ( struct V_20 * V_21 ,
void * V_79 , unsigned int V_63 )
{
void * V_80 ;
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_81 = V_23 -> V_54 ;
while ( V_63 ) {
unsigned int V_71 ;
V_80 = V_23 -> V_24 + V_81 ;
if ( V_63 >= V_23 -> V_25 - V_81 )
V_71 = V_23 -> V_25 - V_81 ;
else
V_71 = V_63 ;
memcpy ( V_79 , V_80 , V_71 ) ;
V_63 -= V_71 ;
V_79 += V_71 ;
V_81 = 0 ;
}
}
unsigned int F_55 ( struct V_20 * V_21 ,
const void * V_77 , unsigned int V_82 )
{
unsigned int V_83 ;
unsigned int V_63 ;
V_83 = F_56 ( V_21 , F_39 ( V_21 ) ) ;
if ( V_82 > V_83 ) {
F_57 ( V_21 -> V_73 -> V_31 , L_2 ) ;
V_21 -> V_23 -> V_61 |= V_84 ;
V_82 = V_83 ;
}
if ( V_82 == 0 )
return 0 ;
V_63 = F_41 ( V_21 ,
F_58 ( V_21 , V_82 ) ) ;
F_53 ( V_21 , V_77 , V_63 ) ;
F_47 ( V_21 , V_63 ) ;
F_59 ( V_21 , V_63 ) ;
V_21 -> V_23 -> V_61 |= V_85 ;
return V_63 ;
}
unsigned int F_60 ( struct V_20 * V_21 ,
void * V_77 , unsigned int V_82 )
{
unsigned int V_83 ;
unsigned int V_63 ;
V_83 = F_56 ( V_21 ,
F_48 ( V_21 ) ) ;
if ( V_82 > V_83 )
V_82 = V_83 ;
if ( V_82 == 0 )
return 0 ;
V_63 = F_50 ( V_21 ,
F_58 ( V_21 , V_82 ) ) ;
F_54 ( V_21 , V_77 , V_63 ) ;
F_52 ( V_21 , V_63 ) ;
F_59 ( V_21 , V_63 ) ;
V_21 -> V_23 -> V_61 |= V_85 ;
return V_63 ;
}
