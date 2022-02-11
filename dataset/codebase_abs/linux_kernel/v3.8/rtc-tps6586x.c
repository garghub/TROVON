static inline struct V_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_1 * V_8 = F_1 ( V_2 ) ;
unsigned long long V_9 = 0 ;
unsigned long V_10 ;
T_1 V_11 [ 6 ] ;
int V_12 ;
int V_13 ;
V_12 = F_4 ( V_8 , V_14 , sizeof( V_11 ) , V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 , L_1 , V_12 ) ;
return V_12 ;
}
for ( V_13 = 1 ; V_13 < sizeof( V_11 ) ; V_13 ++ ) {
V_9 <<= 8 ;
V_9 |= V_11 [ V_13 ] ;
}
V_10 = V_9 >> 10 ;
V_10 += V_7 -> V_15 ;
F_6 ( V_10 , V_5 ) ;
return F_7 ( V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_1 * V_8 = F_1 ( V_2 ) ;
unsigned long long V_9 ;
unsigned long V_10 ;
T_1 V_11 [ 5 ] ;
int V_12 ;
F_9 ( V_5 , & V_10 ) ;
if ( V_10 < V_7 -> V_15 ) {
F_5 ( V_2 , L_2 ) ;
return - V_16 ;
}
V_10 -= V_7 -> V_15 ;
V_9 = ( unsigned long long ) V_10 << 10 ;
V_11 [ 0 ] = ( V_9 >> 32 ) & 0xff ;
V_11 [ 1 ] = ( V_9 >> 24 ) & 0xff ;
V_11 [ 2 ] = ( V_9 >> 16 ) & 0xff ;
V_11 [ 3 ] = ( V_9 >> 8 ) & 0xff ;
V_11 [ 4 ] = V_9 & 0xff ;
V_12 = F_10 ( V_8 , V_17 , V_18 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 , L_3 ) ;
return V_12 ;
}
V_12 = F_11 ( V_8 , V_19 , sizeof( V_11 ) , V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 , L_4 ) ;
return V_12 ;
}
V_12 = F_12 ( V_8 , V_17 , V_18 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 , L_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_20 && ! V_7 -> V_21 ) {
F_14 ( V_7 -> V_22 ) ;
V_7 -> V_21 = true ;
} else if ( ! V_20 && V_7 -> V_21 ) {
F_15 ( V_7 -> V_22 ) ;
V_7 -> V_21 = false ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_1 * V_8 = F_1 ( V_2 ) ;
unsigned long V_10 ;
unsigned long V_9 ;
unsigned long V_25 ;
unsigned long long V_26 = 0 ;
T_1 V_11 [ 3 ] ;
T_1 V_27 [ 6 ] ;
int V_12 ;
int V_13 ;
F_9 ( & V_24 -> time , & V_10 ) ;
if ( V_24 -> V_20 && ( V_10 < V_7 -> V_15 ) ) {
F_5 ( V_2 , L_6 ) ;
return - V_16 ;
}
V_12 = F_13 ( V_2 , V_24 -> V_20 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 , L_7 , V_12 ) ;
return V_12 ;
}
V_10 -= V_7 -> V_15 ;
V_12 = F_4 ( V_8 , V_14 ,
sizeof( V_27 ) , V_27 ) ;
if ( V_12 < 0 ) {
F_5 ( V_2 , L_1 , V_12 ) ;
return V_12 ;
}
for ( V_13 = 1 ; V_13 < sizeof( V_27 ) ; V_13 ++ ) {
V_26 <<= 8 ;
V_26 |= V_27 [ V_13 ] ;
}
V_25 = V_26 >> 10 ;
if ( ( V_10 - V_25 ) > V_28 )
V_10 = V_25 - 1 ;
V_9 = ( unsigned long long ) V_10 << 10 ;
V_11 [ 0 ] = ( V_9 >> 16 ) & 0xff ;
V_11 [ 1 ] = ( V_9 >> 8 ) & 0xff ;
V_11 [ 2 ] = V_9 & 0xff ;
V_12 = F_11 ( V_8 , V_29 , sizeof( V_11 ) , V_11 ) ;
if ( V_12 )
F_5 ( V_2 , L_8 , V_12 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_1 * V_8 = F_1 ( V_2 ) ;
unsigned long V_9 ;
unsigned long V_10 ;
T_1 V_11 [ 3 ] ;
int V_12 ;
V_12 = F_4 ( V_8 , V_29 , sizeof( V_11 ) , V_11 ) ;
if ( V_12 ) {
F_5 ( V_2 , L_9 , V_12 ) ;
return V_12 ;
}
V_9 = ( V_11 [ 0 ] << 16 ) | ( V_11 [ 1 ] << 8 ) | V_11 [ 2 ] ;
V_10 = V_9 >> 10 ;
V_10 += V_7 -> V_15 ;
F_6 ( V_10 , & V_24 -> time ) ;
return 0 ;
}
static T_2 F_18 ( int V_22 , void * V_30 )
{
struct V_6 * V_7 = V_30 ;
F_19 ( V_7 -> V_7 , 1 , V_31 | V_32 ) ;
return V_33 ;
}
static int F_20 ( struct V_34 * V_35 )
{
struct V_1 * V_8 = F_1 ( & V_35 -> V_2 ) ;
struct V_6 * V_7 ;
int V_12 ;
V_7 = F_21 ( & V_35 -> V_2 , sizeof( * V_7 ) , V_36 ) ;
if ( ! V_7 )
return - V_37 ;
V_7 -> V_2 = & V_35 -> V_2 ;
V_7 -> V_22 = F_22 ( V_35 , 0 ) ;
V_7 -> V_15 = mktime ( 2009 , 1 , 1 , 0 , 0 , 0 ) ;
V_12 = F_23 ( V_8 , V_17 ,
V_18 | V_38 |
( ( V_39 << V_40 ) & V_41 ) ,
V_18 | V_38 | V_42 | V_41 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_35 -> V_2 , L_10 ) ;
return V_12 ;
}
F_24 ( V_35 , V_7 ) ;
V_7 -> V_7 = F_25 ( F_26 ( & V_35 -> V_2 ) , & V_35 -> V_2 ,
& V_43 , V_44 ) ;
if ( F_27 ( V_7 -> V_7 ) ) {
V_12 = F_28 ( V_7 -> V_7 ) ;
F_5 ( & V_35 -> V_2 , L_11 , V_12 ) ;
goto V_45;
}
V_12 = F_29 ( V_7 -> V_22 , NULL , F_18 ,
V_46 | V_47 ,
F_26 ( & V_35 -> V_2 ) , V_7 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_35 -> V_2 , L_12 ,
V_7 -> V_22 , V_12 ) ;
goto V_48;
}
F_15 ( V_7 -> V_22 ) ;
F_30 ( & V_35 -> V_2 , 1 ) ;
return 0 ;
V_48:
F_31 ( V_7 -> V_7 ) ;
V_45:
F_23 ( V_8 , V_17 , 0 ,
V_18 | V_38 | V_42 | V_41 ) ;
return V_12 ;
}
static int F_32 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_33 ( V_35 ) ;
struct V_1 * V_8 = F_1 ( & V_35 -> V_2 ) ;
F_23 ( V_8 , V_17 , 0 ,
V_18 | V_38 | V_42 | V_41 ) ;
F_31 ( V_7 -> V_7 ) ;
F_34 ( V_7 -> V_22 , V_7 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( F_36 ( V_2 ) )
F_37 ( V_7 -> V_22 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( F_36 ( V_2 ) )
F_39 ( V_7 -> V_22 ) ;
return 0 ;
}
