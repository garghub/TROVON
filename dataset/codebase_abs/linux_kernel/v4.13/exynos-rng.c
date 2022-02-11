static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_2 * V_6 , unsigned int V_7 )
{
T_1 V_5 ;
int V_8 ;
V_7 = F_6 ( V_7 , 4 ) ;
if ( V_7 < V_9 )
return - V_10 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += 4 ) {
unsigned int V_11 = ( V_8 / 4 ) % V_12 ;
V_5 = V_6 [ V_8 ] << 24 ;
V_5 |= V_6 [ V_8 + 1 ] << 16 ;
V_5 |= V_6 [ V_8 + 2 ] << 8 ;
V_5 |= V_6 [ V_8 + 3 ] << 0 ;
F_3 ( V_2 , V_5 , F_7 ( V_11 ) ) ;
}
V_5 = F_1 ( V_2 , V_13 ) ;
if ( ! ( V_5 & V_14 ) ) {
F_8 ( V_2 -> V_15 , L_1 ) ;
return - V_16 ;
}
V_2 -> V_17 = V_18 ;
return 0 ;
}
static unsigned int F_9 ( struct V_1 * V_2 ,
T_2 * V_19 , unsigned int V_20 )
{
unsigned int V_21 = 0 ;
int V_8 , V_22 ;
T_1 V_5 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
V_5 = F_1 ( V_2 , F_10 ( V_22 ) ) ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_19 [ V_21 ] = V_5 & 0xff ;
V_5 >>= 8 ;
if ( ++ V_21 >= V_20 )
return V_21 ;
}
}
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 * V_19 , unsigned int V_20 ,
unsigned int * V_23 )
{
int V_24 = V_25 ;
F_3 ( V_2 , V_26 ,
V_27 ) ;
while ( ! ( F_1 ( V_2 ,
V_13 ) & V_28 ) && -- V_24 )
F_12 () ;
if ( ! V_24 )
return - V_29 ;
F_3 ( V_2 , V_28 ,
V_13 ) ;
* V_23 = F_9 ( V_2 , V_19 , V_20 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_30 = V_2 -> V_17 + \
F_14 ( V_31 ) ;
unsigned long V_32 = V_18 ;
unsigned int V_23 = 0 ;
T_2 V_6 [ V_9 ] ;
if ( F_15 ( V_32 , V_30 ) )
return;
if ( F_11 ( V_2 , V_6 , sizeof( V_6 ) , & V_23 ) )
return;
F_5 ( V_2 , V_6 , V_23 ) ;
}
static int F_16 ( struct V_33 * V_34 ,
const T_2 * V_35 , unsigned int V_7 ,
T_2 * V_19 , unsigned int V_20 )
{
struct V_36 * V_37 = F_17 ( V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
unsigned int V_23 = 0 ;
int V_38 ;
V_38 = F_18 ( V_2 -> V_39 ) ;
if ( V_38 )
return V_38 ;
do {
V_38 = F_11 ( V_2 , V_19 , V_20 , & V_23 ) ;
if ( V_38 )
break;
V_20 -= V_23 ;
V_19 += V_23 ;
F_13 ( V_2 ) ;
} while ( V_20 > 0 );
F_19 ( V_2 -> V_39 ) ;
return V_38 ;
}
static int F_20 ( struct V_33 * V_34 , const T_2 * V_6 ,
unsigned int V_7 )
{
struct V_36 * V_37 = F_17 ( V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
int V_38 ;
V_38 = F_18 ( V_2 -> V_39 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_5 ( V_37 -> V_2 , V_6 , V_7 ) ;
F_19 ( V_2 -> V_39 ) ;
return V_38 ;
}
static int F_21 ( struct V_40 * V_34 )
{
struct V_36 * V_37 = F_22 ( V_34 ) ;
V_37 -> V_2 = V_1 ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_38 ;
if ( V_1 )
return - V_45 ;
V_2 = F_24 ( & V_42 -> V_15 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_15 = & V_42 -> V_15 ;
V_2 -> V_39 = F_25 ( & V_42 -> V_15 , L_2 ) ;
if ( F_26 ( V_2 -> V_39 ) ) {
F_27 ( & V_42 -> V_15 , L_3 ) ;
return F_28 ( V_2 -> V_39 ) ;
}
V_44 = F_29 ( V_42 , V_48 , 0 ) ;
V_2 -> V_4 = F_30 ( & V_42 -> V_15 , V_44 ) ;
if ( F_26 ( V_2 -> V_4 ) )
return F_28 ( V_2 -> V_4 ) ;
F_31 ( V_42 , V_2 ) ;
V_1 = V_2 ;
V_38 = F_32 ( & V_49 ) ;
if ( V_38 ) {
F_27 ( & V_42 -> V_15 ,
L_4 , V_38 ) ;
V_1 = NULL ;
}
return V_38 ;
}
static int F_33 ( struct V_41 * V_42 )
{
F_34 ( & V_49 ) ;
V_1 = NULL ;
return 0 ;
}
static int T_3 F_35 ( struct V_50 * V_15 )
{
struct V_41 * V_42 = F_36 ( V_15 ) ;
struct V_1 * V_2 = F_37 ( V_42 ) ;
int V_38 ;
if ( ! V_2 -> V_17 )
return 0 ;
V_2 -> V_51 = 0 ;
V_38 = F_18 ( V_2 -> V_39 ) ;
if ( V_38 )
return V_38 ;
F_11 ( V_2 , V_2 -> V_52 , sizeof( V_2 -> V_52 ) ,
& ( V_2 -> V_51 ) ) ;
F_38 ( V_2 -> V_15 , L_5 ,
V_2 -> V_51 ) ;
F_19 ( V_2 -> V_39 ) ;
return 0 ;
}
static int T_3 F_39 ( struct V_50 * V_15 )
{
struct V_41 * V_42 = F_36 ( V_15 ) ;
struct V_1 * V_2 = F_37 ( V_42 ) ;
int V_38 ;
if ( ! V_2 -> V_17 )
return 0 ;
V_38 = F_18 ( V_2 -> V_39 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_5 ( V_2 , V_2 -> V_52 , V_2 -> V_51 ) ;
F_19 ( V_2 -> V_39 ) ;
return V_38 ;
}
