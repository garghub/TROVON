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
struct V_2 *
F_31 ( struct V_20 * V_21 )
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
bool F_32 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = V_21 -> V_23 -> V_27 ;
return V_3 && ( F_33 ( & V_3 -> V_4 . V_4 ) > 1 ) ;
}
int F_34 ( struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long V_37 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
V_37 = ( V_37 + V_16 - 1 ) & V_38 ;
if ( V_23 -> V_24 && V_23 -> V_25 == V_37 )
return 0 ;
F_11 ( V_19 , V_21 ) ;
if ( V_37 ) {
unsigned int V_9 = V_37 >> V_39 ;
F_16 ( V_19 , V_21 , V_9 ) ;
if ( ! V_23 -> V_24 ) {
F_11 ( V_19 , V_21 ) ;
return - V_40 ;
}
}
V_23 -> V_25 = V_37 ;
return 0 ;
}
void F_35 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
V_23 -> V_41 = 0 ;
V_23 -> V_42 = 0 ;
V_23 -> V_43 = 0 ;
V_23 -> V_44 = 0 ;
V_23 -> V_45 = 0 ;
V_23 -> V_46 = 0 ;
V_23 -> V_47 = 0 ;
V_23 -> V_48 = 0 ;
V_23 -> V_49 = 0 ;
V_23 -> V_50 = 0 ;
V_23 -> V_51 = 0 ;
V_23 -> V_52 = 0 ;
V_23 -> V_53 = 0 ;
}
static unsigned int F_36 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_54 = V_23 -> V_44 + V_23 -> V_25 ;
return V_54 - V_23 -> V_41 ;
}
unsigned int F_37 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_54 = V_23 -> V_44 + V_23 -> V_25 ;
return V_54 - V_23 -> V_42 ;
}
unsigned int F_38 ( struct V_20 * V_21 ,
unsigned int V_55 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_56 = F_36 ( V_21 ) ;
if ( V_55 > V_56 )
V_55 = V_56 ;
V_23 -> V_41 += V_55 ;
F_39 () ;
return V_55 ;
}
static unsigned int F_40 ( struct V_20 * V_21 ,
unsigned int V_57 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_58 = 0 ;
const unsigned int V_59 = F_41 ( V_21 ) ;
if ( ! V_21 -> V_60 || ( V_23 -> V_61 . V_12 & V_62 ) ) {
V_23 -> V_51 += V_57 ;
V_58 = V_57 ;
} else {
V_57 -= V_57 % V_59 ;
while ( V_58 < V_57 ) {
int V_63 = V_57 - V_58 ;
unsigned int V_64 ;
V_64 = V_23 -> V_25 - V_23 -> V_52 ;
if ( V_63 > V_64 )
V_63 = V_64 ;
V_21 -> V_60 ( V_21 -> V_65 , V_21 ,
V_23 -> V_24 + V_23 -> V_52 ,
V_63 , V_23 -> V_50 ) ;
F_42 () ;
V_23 -> V_50 += V_63 / V_59 ;
V_23 -> V_50 %= V_23 -> V_61 . V_66 ;
V_23 -> V_51 += V_63 ;
V_23 -> V_52 += V_63 ;
V_23 -> V_52 %= V_23 -> V_25 ;
V_58 += V_63 ;
}
}
return V_58 ;
}
unsigned int F_43 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
return V_23 -> V_41 - V_23 -> V_42 ;
}
unsigned int F_44 ( struct V_20 * V_21 ,
unsigned int V_55 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_67 = F_43 ( V_21 ) ;
if ( V_55 > V_67 )
V_55 = V_67 ;
V_23 -> V_42 += V_55 ;
V_23 -> V_45 += V_55 ;
F_40 ( V_21 , V_23 -> V_42 - V_23 -> V_51 ) ;
if ( V_23 -> V_45 >= V_23 -> V_25 )
V_23 -> V_45 %= V_23 -> V_25 ;
return V_55 ;
}
unsigned int F_45 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_57 ;
if ( ! V_23 )
return 0 ;
V_57 = V_23 -> V_51 - V_23 -> V_44 ;
F_46 () ;
return V_57 ;
}
unsigned int F_47 ( struct V_20 * V_21 ,
unsigned int V_55 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_68 ;
V_68 = V_23 -> V_51 - V_23 -> V_43 ;
if ( V_55 > V_68 )
V_55 = V_68 ;
V_23 -> V_43 += V_55 ;
F_46 () ;
return V_55 ;
}
static unsigned int F_48 ( struct V_22 * V_23 )
{
return V_23 -> V_43 - V_23 -> V_44 ;
}
unsigned int F_49 ( struct V_20 * V_21 ,
unsigned int V_55 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_67 ;
F_39 () ;
V_67 = F_48 ( V_23 ) ;
if ( V_55 > V_67 )
V_55 = V_67 ;
V_23 -> V_44 += V_55 ;
V_23 -> V_46 += V_55 ;
V_23 -> V_46 %= V_23 -> V_25 ;
return V_55 ;
}
static void F_50 ( struct V_20 * V_21 ,
const void * V_69 , unsigned int V_57 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_70 = V_23 -> V_45 ;
while ( V_57 ) {
unsigned int V_63 ;
if ( V_70 + V_57 > V_23 -> V_25 )
V_63 = V_23 -> V_25 - V_70 ;
else
V_63 = V_57 ;
memcpy ( V_23 -> V_24 + V_70 , V_69 , V_63 ) ;
V_69 += V_63 ;
V_57 -= V_63 ;
V_70 = 0 ;
}
}
static void F_51 ( struct V_20 * V_21 ,
void * V_71 , unsigned int V_55 )
{
void * V_72 ;
struct V_22 * V_23 = V_21 -> V_23 ;
unsigned int V_73 = V_23 -> V_46 ;
while ( V_55 ) {
unsigned int V_63 ;
V_72 = V_23 -> V_24 + V_73 ;
if ( V_55 >= V_23 -> V_25 - V_73 )
V_63 = V_23 -> V_25 - V_73 ;
else
V_63 = V_55 ;
memcpy ( V_71 , V_72 , V_63 ) ;
V_55 -= V_63 ;
V_71 += V_63 ;
V_73 = 0 ;
}
}
unsigned int F_52 ( struct V_20 * V_21 ,
const void * V_69 , unsigned int V_74 )
{
unsigned int V_75 ;
unsigned int V_55 ;
V_75 = F_53 ( V_21 , F_36 ( V_21 ) ) ;
if ( V_74 > V_75 ) {
F_54 ( V_21 -> V_65 -> V_31 , L_2 ) ;
V_21 -> V_23 -> V_53 |= V_76 ;
V_74 = V_75 ;
}
if ( V_74 == 0 )
return 0 ;
V_55 = F_38 ( V_21 ,
F_55 ( V_21 , V_74 ) ) ;
F_50 ( V_21 , V_69 , V_55 ) ;
F_44 ( V_21 , V_55 ) ;
F_56 ( V_21 , V_55 ) ;
V_21 -> V_23 -> V_53 |= V_77 ;
return V_55 ;
}
unsigned int F_57 ( struct V_20 * V_21 ,
void * V_69 , unsigned int V_74 )
{
unsigned int V_75 ;
unsigned int V_55 ;
V_75 = F_53 ( V_21 ,
F_45 ( V_21 ) ) ;
if ( V_74 > V_75 )
V_74 = V_75 ;
if ( V_74 == 0 )
return 0 ;
V_55 = F_47 ( V_21 ,
F_55 ( V_21 , V_74 ) ) ;
F_51 ( V_21 , V_69 , V_55 ) ;
F_49 ( V_21 , V_55 ) ;
F_56 ( V_21 , V_55 ) ;
V_21 -> V_23 -> V_53 |= V_77 ;
return V_55 ;
}
