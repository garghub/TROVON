static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 ;
unsigned V_10 ;
if ( V_7 -> V_11 ) {
F_2 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = 0 ;
}
if ( ! V_7 -> V_13 )
return;
for ( V_10 = 0 ; V_10 < V_5 ; ++ V_10 ) {
V_9 = & V_7 -> V_13 [ V_10 ] ;
if ( V_9 -> V_14 ) {
F_3 ( V_15 ,
& ( F_4 ( V_9 -> V_14 ) -> V_16 ) ) ;
if ( V_4 -> V_17 != V_18 ) {
#ifdef F_5
F_6 ( V_2 -> V_19 ,
V_20 ,
V_9 -> V_14 ,
V_9 -> V_21 ) ;
#endif
} else {
F_7 ( ( unsigned long ) V_9 -> V_14 ) ;
}
}
}
F_8 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_22 = 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_23 * * V_24 = NULL ;
struct V_8 * V_9 ;
unsigned V_10 ;
if ( ! F_10 ( F_5 ) && V_4 -> V_17 != V_18 ) {
F_11 ( V_2 -> V_25 ,
L_1 ) ;
return;
}
V_7 -> V_13 = F_12 ( sizeof( * V_9 ) * V_5 ) ;
if ( V_7 -> V_13 )
V_24 = F_13 ( sizeof( struct V_23 * ) * V_5 ) ;
if ( ! V_24 )
return;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
V_9 = & V_7 -> V_13 [ V_10 ] ;
if ( V_4 -> V_17 != V_18 )
#ifdef F_5
V_9 -> V_14 = F_14 ( V_2 -> V_19 ,
V_20 ,
& V_9 -> V_21 ,
V_26 |
V_27 ) ;
#else
break;
#endif
else
V_9 -> V_14 = ( void * ) F_15 ( V_26 ) ;
if ( ! V_9 -> V_14 )
break;
F_16 ( V_15 , & ( F_4 ( V_9 -> V_14 ) -> V_16 ) ) ;
V_24 [ V_10 ] = F_4 ( V_9 -> V_14 ) ;
}
if ( V_10 == V_5 )
V_7 -> V_11 = F_17 ( V_24 , V_5 , V_28 ,
V_29 ) ;
F_8 ( V_24 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_30 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
V_30 = ( V_30 + V_20 - 1 ) & V_31 ;
if ( V_7 -> V_11 && V_7 -> V_12 == V_30 )
return 0 ;
F_1 ( V_2 , V_4 , V_7 -> V_22 ) ;
if ( V_30 ) {
unsigned V_5 = V_30 >> V_32 ;
F_9 ( V_2 , V_4 , V_5 ) ;
if ( ! V_7 -> V_11 ) {
F_1 ( V_2 , V_4 , V_5 ) ;
return - V_33 ;
}
V_7 -> V_22 = V_5 ;
}
V_7 -> V_12 = V_30 ;
return 0 ;
}
void F_19 ( struct V_6 * V_7 )
{
V_7 -> V_34 = 0 ;
V_7 -> V_35 = 0 ;
V_7 -> V_36 = 0 ;
V_7 -> V_37 = 0 ;
V_7 -> V_38 = 0 ;
V_7 -> V_39 = 0 ;
V_7 -> V_40 = 0 ;
V_7 -> V_41 = 0 ;
V_7 -> V_42 = 0 ;
V_7 -> V_43 = 0 ;
V_7 -> V_44 = 0 ;
V_7 -> V_45 = 0 ;
}
static unsigned int F_20 ( struct V_6 * V_7 )
{
unsigned int V_46 = V_7 -> V_37 + V_7 -> V_12 ;
return V_46 - V_7 -> V_34 ;
}
static unsigned int F_21 ( struct V_6 * V_7 ,
unsigned int V_47 ,
int V_48 )
{
unsigned int V_49 = F_20 ( V_7 ) ;
if ( V_47 > V_49 )
V_47 = V_48 ? 0 : V_49 ;
V_7 -> V_34 += V_47 ;
F_22 () ;
return V_47 ;
}
unsigned int F_23 ( struct V_6 * V_7 ,
unsigned int V_47 )
{
return F_21 ( V_7 , V_47 , 0 ) ;
}
static unsigned int F_24 ( struct V_6 * V_7 ,
unsigned int V_50 )
{
struct V_3 * V_4 = V_7 -> V_51 ;
unsigned int V_52 = 0 ;
const unsigned V_53 = F_25 ( V_4 ) ;
if ( ! V_4 -> V_54 || ( V_7 -> V_55 . V_16 & V_56 ) ) {
V_7 -> V_43 += V_50 ;
V_52 = V_50 ;
} else {
V_50 -= V_50 % V_53 ;
while ( V_52 < V_50 ) {
int V_57 = V_50 - V_52 ;
unsigned int V_58 ;
V_58 = V_7 -> V_12 - V_7 -> V_44 ;
if ( V_57 > V_58 )
V_57 = V_58 ;
V_4 -> V_54 ( V_4 -> V_59 , V_4 ,
V_7 -> V_11 + V_7 -> V_44 ,
V_57 , V_7 -> V_42 ) ;
F_26 () ;
V_7 -> V_42 += V_57 / V_53 ;
V_7 -> V_42 %= V_7 -> V_55 . V_60 ;
V_7 -> V_43 += V_57 ;
V_7 -> V_44 += V_57 ;
V_7 -> V_44 %= V_7 -> V_12 ;
V_52 += V_57 ;
}
}
return V_52 ;
}
unsigned int F_27 ( struct V_6 * V_7 )
{
return V_7 -> V_34 - V_7 -> V_35 ;
}
unsigned int F_28 ( struct V_6 * V_7 ,
unsigned int V_47 )
{
unsigned int V_61 = F_27 ( V_7 ) ;
if ( V_47 > V_61 )
V_47 = V_61 ;
V_7 -> V_35 += V_47 ;
V_7 -> V_38 += V_47 ;
F_24 ( V_7 , V_7 -> V_35 - V_7 -> V_43 ) ;
if ( V_7 -> V_38 >= V_7 -> V_12 )
V_7 -> V_38 %= V_7 -> V_12 ;
return V_47 ;
}
unsigned int F_29 ( struct V_6 * V_7 )
{
unsigned V_50 ;
if ( ! V_7 )
return 0 ;
V_50 = V_7 -> V_43 - V_7 -> V_37 ;
F_30 () ;
return V_50 ;
}
unsigned int F_31 ( struct V_6 * V_7 ,
unsigned int V_47 )
{
unsigned int V_49 ;
V_49 = V_7 -> V_43 - V_7 -> V_36 ;
if ( V_47 > V_49 )
V_47 = V_49 ;
V_7 -> V_36 += V_47 ;
F_30 () ;
return V_47 ;
}
static unsigned int F_32 ( struct V_6 * V_7 )
{
return V_7 -> V_36 - V_7 -> V_37 ;
}
unsigned int F_33 ( struct V_6 * V_7 ,
unsigned int V_47 )
{
unsigned int V_61 ;
F_22 () ;
V_61 = F_32 ( V_7 ) ;
if ( V_47 > V_61 )
V_47 = V_61 ;
V_7 -> V_37 += V_47 ;
V_7 -> V_39 += V_47 ;
V_7 -> V_39 %= V_7 -> V_12 ;
return V_47 ;
}
int F_34 ( struct V_6 * V_7 , short V_62 )
{
unsigned int V_63 = F_21 ( V_7 , sizeof( short ) , 1 ) ;
if ( V_63 < sizeof( short ) ) {
V_7 -> V_45 |= V_64 ;
return 0 ;
}
* ( short * ) ( V_7 -> V_11 + V_7 -> V_38 ) = V_62 ;
F_28 ( V_7 , sizeof( short ) ) ;
return 1 ;
}
int F_35 ( struct V_6 * V_7 , short * V_62 )
{
unsigned int V_63 = F_29 ( V_7 ) ;
if ( V_63 < sizeof( short ) )
return 0 ;
F_31 ( V_7 , sizeof( short ) ) ;
* V_62 = * ( short * ) ( V_7 -> V_11 + V_7 -> V_39 ) ;
F_33 ( V_7 , sizeof( short ) ) ;
return 1 ;
}
void F_36 ( struct V_6 * V_7 , unsigned int V_65 ,
const void * V_66 , unsigned int V_50 )
{
unsigned int V_67 = V_7 -> V_38 + V_65 ;
if ( V_67 >= V_7 -> V_12 )
V_67 %= V_7 -> V_12 ;
while ( V_50 ) {
unsigned int V_57 ;
if ( V_67 + V_50 > V_7 -> V_12 )
V_57 = V_7 -> V_12 - V_67 ;
else
V_57 = V_50 ;
memcpy ( V_7 -> V_11 + V_67 , V_66 , V_57 ) ;
V_66 += V_57 ;
V_50 -= V_57 ;
V_67 = 0 ;
}
}
void F_37 ( struct V_6 * V_7 , unsigned int V_65 ,
void * V_68 , unsigned int V_47 )
{
void * V_69 ;
unsigned int V_70 = V_7 -> V_39 + V_65 ;
if ( V_70 >= V_7 -> V_12 )
V_70 %= V_7 -> V_12 ;
while ( V_47 ) {
unsigned int V_57 ;
V_69 = V_7 -> V_11 + V_70 ;
if ( V_47 >= V_7 -> V_12 - V_70 )
V_57 = V_7 -> V_12 - V_70 ;
else
V_57 = V_47 ;
memcpy ( V_68 , V_69 , V_57 ) ;
V_47 -= V_57 ;
V_68 += V_57 ;
V_70 = 0 ;
}
}
