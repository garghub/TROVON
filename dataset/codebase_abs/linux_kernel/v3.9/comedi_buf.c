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
F_5 ( V_2 -> V_19 ,
V_20 ,
V_9 -> V_14 ,
V_9 -> V_21 ) ;
} else {
F_6 ( ( unsigned long ) V_9 -> V_14 ) ;
}
}
}
F_7 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_22 = 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_23 * * V_24 = NULL ;
struct V_8 * V_9 ;
unsigned V_10 ;
V_7 -> V_13 = F_9 ( sizeof( * V_9 ) * V_5 ) ;
if ( V_7 -> V_13 )
V_24 = F_10 ( sizeof( struct V_23 * ) * V_5 ) ;
if ( ! V_24 )
return;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
V_9 = & V_7 -> V_13 [ V_10 ] ;
if ( V_4 -> V_17 != V_18 )
V_9 -> V_14 = F_11 ( V_2 -> V_19 ,
V_20 ,
& V_9 -> V_21 ,
V_25 |
V_26 ) ;
else
V_9 -> V_14 = ( void * ) F_12 ( V_25 ) ;
if ( ! V_9 -> V_14 )
break;
F_13 ( V_15 , & ( F_4 ( V_9 -> V_14 ) -> V_16 ) ) ;
V_24 [ V_10 ] = F_4 ( V_9 -> V_14 ) ;
}
if ( V_10 == V_5 )
V_7 -> V_11 = F_14 ( V_24 , V_5 , V_27 ,
V_28 ) ;
F_7 ( V_24 ) ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_29 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
V_29 = ( V_29 + V_20 - 1 ) & V_30 ;
if ( V_7 -> V_11 && V_7 -> V_12 == V_29 )
return 0 ;
F_1 ( V_2 , V_4 , V_7 -> V_22 ) ;
if ( V_29 ) {
unsigned V_5 = V_29 >> V_31 ;
F_8 ( V_2 , V_4 , V_5 ) ;
if ( ! V_7 -> V_11 ) {
F_1 ( V_2 , V_4 , V_5 ) ;
return - V_32 ;
}
V_7 -> V_22 = V_5 ;
}
V_7 -> V_12 = V_29 ;
return 0 ;
}
void F_16 ( struct V_6 * V_7 )
{
V_7 -> V_33 = 0 ;
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
}
static unsigned int F_17 ( struct V_6 * V_7 )
{
unsigned int V_45 = V_7 -> V_36 + V_7 -> V_12 ;
return V_45 - V_7 -> V_33 ;
}
static unsigned int F_18 ( struct V_6 * V_7 ,
unsigned int V_46 ,
int V_47 )
{
unsigned int V_48 = F_17 ( V_7 ) ;
if ( V_46 > V_48 )
V_46 = V_47 ? 0 : V_48 ;
V_7 -> V_33 += V_46 ;
F_19 () ;
return V_46 ;
}
unsigned int F_20 ( struct V_6 * V_7 ,
unsigned int V_46 )
{
return F_18 ( V_7 , V_46 , 0 ) ;
}
static unsigned int F_21 ( struct V_6 * V_7 ,
unsigned int V_49 )
{
struct V_3 * V_4 = V_7 -> V_50 ;
unsigned int V_51 = 0 ;
const unsigned V_52 = F_22 ( V_4 ) ;
if ( ! V_4 -> V_53 || ( V_7 -> V_54 . V_16 & V_55 ) ) {
V_7 -> V_42 += V_49 ;
V_51 = V_49 ;
} else {
V_49 -= V_49 % V_52 ;
while ( V_51 < V_49 ) {
int V_56 = V_49 - V_51 ;
unsigned int V_57 ;
V_57 = V_7 -> V_12 - V_7 -> V_43 ;
if ( V_56 > V_57 )
V_56 = V_57 ;
V_4 -> V_53 ( V_4 -> V_58 , V_4 ,
V_7 -> V_11 + V_7 -> V_43 ,
V_56 , V_7 -> V_41 ) ;
F_23 () ;
V_7 -> V_41 += V_56 / V_52 ;
V_7 -> V_41 %= V_7 -> V_54 . V_59 ;
V_7 -> V_42 += V_56 ;
V_7 -> V_43 += V_56 ;
V_7 -> V_43 %= V_7 -> V_12 ;
V_51 += V_56 ;
}
}
return V_51 ;
}
unsigned int F_24 ( struct V_6 * V_7 )
{
return V_7 -> V_33 - V_7 -> V_34 ;
}
unsigned int F_25 ( struct V_6 * V_7 ,
unsigned int V_46 )
{
unsigned int V_60 = F_24 ( V_7 ) ;
if ( V_46 > V_60 )
V_46 = V_60 ;
V_7 -> V_34 += V_46 ;
V_7 -> V_37 += V_46 ;
F_21 ( V_7 , V_7 -> V_34 - V_7 -> V_42 ) ;
if ( V_7 -> V_37 >= V_7 -> V_12 )
V_7 -> V_37 %= V_7 -> V_12 ;
return V_46 ;
}
unsigned int F_26 ( struct V_6 * V_7 )
{
unsigned V_49 ;
if ( ! V_7 )
return 0 ;
V_49 = V_7 -> V_42 - V_7 -> V_36 ;
F_27 () ;
return V_49 ;
}
unsigned int F_28 ( struct V_6 * V_7 ,
unsigned int V_46 )
{
unsigned int V_48 ;
V_48 = V_7 -> V_42 - V_7 -> V_35 ;
if ( V_46 > V_48 )
V_46 = V_48 ;
V_7 -> V_35 += V_46 ;
F_27 () ;
return V_46 ;
}
static unsigned int F_29 ( struct V_6 * V_7 )
{
return V_7 -> V_35 - V_7 -> V_36 ;
}
unsigned int F_30 ( struct V_6 * V_7 ,
unsigned int V_46 )
{
unsigned int V_60 ;
F_19 () ;
V_60 = F_29 ( V_7 ) ;
if ( V_46 > V_60 )
V_46 = V_60 ;
V_7 -> V_36 += V_46 ;
V_7 -> V_38 += V_46 ;
V_7 -> V_38 %= V_7 -> V_12 ;
return V_46 ;
}
int F_31 ( struct V_6 * V_7 , short V_61 )
{
unsigned int V_62 = F_18 ( V_7 , sizeof( short ) , 1 ) ;
if ( V_62 < sizeof( short ) ) {
V_7 -> V_44 |= V_63 ;
return 0 ;
}
* ( short * ) ( V_7 -> V_11 + V_7 -> V_37 ) = V_61 ;
F_25 ( V_7 , sizeof( short ) ) ;
return 1 ;
}
int F_32 ( struct V_6 * V_7 , short * V_61 )
{
unsigned int V_62 = F_26 ( V_7 ) ;
if ( V_62 < sizeof( short ) )
return 0 ;
F_28 ( V_7 , sizeof( short ) ) ;
* V_61 = * ( short * ) ( V_7 -> V_11 + V_7 -> V_38 ) ;
F_30 ( V_7 , sizeof( short ) ) ;
return 1 ;
}
void F_33 ( struct V_6 * V_7 , unsigned int V_64 ,
const void * V_65 , unsigned int V_49 )
{
unsigned int V_66 = V_7 -> V_37 + V_64 ;
if ( V_66 >= V_7 -> V_12 )
V_66 %= V_7 -> V_12 ;
while ( V_49 ) {
unsigned int V_56 ;
if ( V_66 + V_49 > V_7 -> V_12 )
V_56 = V_7 -> V_12 - V_66 ;
else
V_56 = V_49 ;
memcpy ( V_7 -> V_11 + V_66 , V_65 , V_56 ) ;
V_65 += V_56 ;
V_49 -= V_56 ;
V_66 = 0 ;
}
}
void F_34 ( struct V_6 * V_7 , unsigned int V_64 ,
void * V_67 , unsigned int V_46 )
{
void * V_68 ;
unsigned int V_69 = V_7 -> V_38 + V_64 ;
if ( V_69 >= V_7 -> V_12 )
V_69 %= V_7 -> V_12 ;
while ( V_46 ) {
unsigned int V_56 ;
V_68 = V_7 -> V_11 + V_69 ;
if ( V_46 >= V_7 -> V_12 - V_69 )
V_56 = V_7 -> V_12 - V_69 ;
else
V_56 = V_46 ;
memcpy ( V_67 , V_68 , V_56 ) ;
V_46 -= V_56 ;
V_67 += V_56 ;
V_69 = 0 ;
}
}
