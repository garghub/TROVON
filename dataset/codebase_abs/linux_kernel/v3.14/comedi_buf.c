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
if ( V_23 -> V_24 ) {
F_12 ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
V_23 -> V_25 = 0 ;
}
F_13 ( V_23 -> V_26 ) ;
V_23 -> V_26 = NULL ;
}
static void F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
unsigned V_9 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_27 * * V_28 = NULL ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned V_7 ;
if ( ! F_15 ( F_5 ) && V_21 -> V_29 != V_14 ) {
F_16 ( V_19 -> V_30 ,
L_1 ) ;
return;
}
V_3 = F_17 ( sizeof( * V_23 -> V_26 ) , V_31 ) ;
if ( ! V_3 )
return;
V_23 -> V_26 = V_3 ;
F_18 ( & V_3 -> V_4 ) ;
V_3 -> V_13 = V_21 -> V_29 ;
if ( V_3 -> V_13 != V_14 )
V_3 -> V_15 = F_19 ( V_19 -> V_32 ) ;
V_3 -> V_8 = F_20 ( sizeof( * V_6 ) * V_9 ) ;
if ( V_3 -> V_8 )
V_28 = F_21 ( sizeof( struct V_27 * ) * V_9 ) ;
if ( ! V_28 )
return;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_6 = & V_3 -> V_8 [ V_7 ] ;
if ( V_3 -> V_13 != V_14 )
#ifdef F_5
V_6 -> V_11 = F_22 ( V_3 -> V_15 ,
V_16 ,
& V_6 -> V_17 ,
V_31 |
V_33 ) ;
#else
break;
#endif
else
V_6 -> V_11 = ( void * ) F_23 ( V_31 ) ;
if ( ! V_6 -> V_11 )
break;
F_24 ( V_10 , & ( F_4 ( V_6 -> V_11 ) -> V_12 ) ) ;
V_28 [ V_7 ] = F_4 ( V_6 -> V_11 ) ;
}
V_3 -> V_9 = V_7 ;
if ( V_7 == V_9 )
V_23 -> V_24 = F_25 ( V_28 , V_9 , V_34 ,
V_35 ) ;
F_8 ( V_28 ) ;
}
void F_26 ( struct V_2 * V_3 )
{
if ( V_3 )
F_27 ( & V_3 -> V_4 ) ;
}
int F_13 ( struct V_2 * V_3 )
{
if ( V_3 )
return F_28 ( & V_3 -> V_4 , F_1 ) ;
return 1 ;
}
bool F_29 ( struct V_22 * V_23 )
{
struct V_2 * V_3 = V_23 -> V_26 ;
return V_3 && ( F_30 ( & V_3 -> V_4 . V_4 ) > 1 ) ;
}
int F_31 ( struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned long V_36 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
V_36 = ( V_36 + V_16 - 1 ) & V_37 ;
if ( V_23 -> V_24 && V_23 -> V_25 == V_36 )
return 0 ;
F_11 ( V_19 , V_21 ) ;
if ( V_36 ) {
unsigned V_9 = V_36 >> V_38 ;
F_14 ( V_19 , V_21 , V_9 ) ;
if ( ! V_23 -> V_24 ) {
F_11 ( V_19 , V_21 ) ;
return - V_39 ;
}
}
V_23 -> V_25 = V_36 ;
return 0 ;
}
void F_32 ( struct V_22 * V_23 )
{
V_23 -> V_40 = 0 ;
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
}
static unsigned int F_33 ( struct V_22 * V_23 )
{
unsigned int V_52 = V_23 -> V_43 + V_23 -> V_25 ;
return V_52 - V_23 -> V_40 ;
}
static unsigned int F_34 ( struct V_22 * V_23 ,
unsigned int V_53 ,
int V_54 )
{
unsigned int V_55 = F_33 ( V_23 ) ;
if ( V_53 > V_55 )
V_53 = V_54 ? 0 : V_55 ;
V_23 -> V_40 += V_53 ;
F_35 () ;
return V_53 ;
}
unsigned int F_36 ( struct V_22 * V_23 ,
unsigned int V_53 )
{
return F_34 ( V_23 , V_53 , 0 ) ;
}
static unsigned int F_37 ( struct V_22 * V_23 ,
unsigned int V_56 )
{
struct V_20 * V_21 = V_23 -> V_57 ;
unsigned int V_58 = 0 ;
const unsigned V_59 = F_38 ( V_21 ) ;
if ( ! V_21 -> V_60 || ( V_23 -> V_61 . V_12 & V_62 ) ) {
V_23 -> V_49 += V_56 ;
V_58 = V_56 ;
} else {
V_56 -= V_56 % V_59 ;
while ( V_58 < V_56 ) {
int V_63 = V_56 - V_58 ;
unsigned int V_64 ;
V_64 = V_23 -> V_25 - V_23 -> V_50 ;
if ( V_63 > V_64 )
V_63 = V_64 ;
V_21 -> V_60 ( V_21 -> V_65 , V_21 ,
V_23 -> V_24 + V_23 -> V_50 ,
V_63 , V_23 -> V_48 ) ;
F_39 () ;
V_23 -> V_48 += V_63 / V_59 ;
V_23 -> V_48 %= V_23 -> V_61 . V_66 ;
V_23 -> V_49 += V_63 ;
V_23 -> V_50 += V_63 ;
V_23 -> V_50 %= V_23 -> V_25 ;
V_58 += V_63 ;
}
}
return V_58 ;
}
unsigned int F_40 ( struct V_22 * V_23 )
{
return V_23 -> V_40 - V_23 -> V_41 ;
}
unsigned int F_41 ( struct V_22 * V_23 ,
unsigned int V_53 )
{
unsigned int V_67 = F_40 ( V_23 ) ;
if ( V_53 > V_67 )
V_53 = V_67 ;
V_23 -> V_41 += V_53 ;
V_23 -> V_44 += V_53 ;
F_37 ( V_23 , V_23 -> V_41 - V_23 -> V_49 ) ;
if ( V_23 -> V_44 >= V_23 -> V_25 )
V_23 -> V_44 %= V_23 -> V_25 ;
return V_53 ;
}
unsigned int F_42 ( struct V_22 * V_23 )
{
unsigned V_56 ;
if ( ! V_23 )
return 0 ;
V_56 = V_23 -> V_49 - V_23 -> V_43 ;
F_43 () ;
return V_56 ;
}
unsigned int F_44 ( struct V_22 * V_23 ,
unsigned int V_53 )
{
unsigned int V_55 ;
V_55 = V_23 -> V_49 - V_23 -> V_42 ;
if ( V_53 > V_55 )
V_53 = V_55 ;
V_23 -> V_42 += V_53 ;
F_43 () ;
return V_53 ;
}
static unsigned int F_45 ( struct V_22 * V_23 )
{
return V_23 -> V_42 - V_23 -> V_43 ;
}
unsigned int F_46 ( struct V_22 * V_23 ,
unsigned int V_53 )
{
unsigned int V_67 ;
F_35 () ;
V_67 = F_45 ( V_23 ) ;
if ( V_53 > V_67 )
V_53 = V_67 ;
V_23 -> V_43 += V_53 ;
V_23 -> V_45 += V_53 ;
V_23 -> V_45 %= V_23 -> V_25 ;
return V_53 ;
}
int F_47 ( struct V_22 * V_23 , unsigned short V_68 )
{
unsigned int V_69 = F_34 ( V_23 , sizeof( short ) , 1 ) ;
if ( V_69 < sizeof( short ) ) {
V_23 -> V_51 |= V_70 ;
return 0 ;
}
* ( unsigned short * ) ( V_23 -> V_24 + V_23 -> V_44 ) = V_68 ;
F_41 ( V_23 , sizeof( short ) ) ;
return 1 ;
}
int F_48 ( struct V_22 * V_23 , unsigned short * V_68 )
{
unsigned int V_69 = F_42 ( V_23 ) ;
if ( V_69 < sizeof( short ) )
return 0 ;
F_44 ( V_23 , sizeof( short ) ) ;
* V_68 = * ( unsigned short * ) ( V_23 -> V_24 + V_23 -> V_45 ) ;
F_46 ( V_23 , sizeof( short ) ) ;
return 1 ;
}
void F_49 ( struct V_22 * V_23 , unsigned int V_71 ,
const void * V_72 , unsigned int V_56 )
{
unsigned int V_73 = V_23 -> V_44 + V_71 ;
if ( V_73 >= V_23 -> V_25 )
V_73 %= V_23 -> V_25 ;
while ( V_56 ) {
unsigned int V_63 ;
if ( V_73 + V_56 > V_23 -> V_25 )
V_63 = V_23 -> V_25 - V_73 ;
else
V_63 = V_56 ;
memcpy ( V_23 -> V_24 + V_73 , V_72 , V_63 ) ;
V_72 += V_63 ;
V_56 -= V_63 ;
V_73 = 0 ;
}
}
void F_50 ( struct V_22 * V_23 , unsigned int V_71 ,
void * V_74 , unsigned int V_53 )
{
void * V_75 ;
unsigned int V_76 = V_23 -> V_45 + V_71 ;
if ( V_76 >= V_23 -> V_25 )
V_76 %= V_23 -> V_25 ;
while ( V_53 ) {
unsigned int V_63 ;
V_75 = V_23 -> V_24 + V_76 ;
if ( V_53 >= V_23 -> V_25 - V_76 )
V_63 = V_23 -> V_25 - V_76 ;
else
V_63 = V_53 ;
memcpy ( V_74 , V_75 , V_63 ) ;
V_53 -= V_63 ;
V_74 += V_63 ;
V_76 = 0 ;
}
}
