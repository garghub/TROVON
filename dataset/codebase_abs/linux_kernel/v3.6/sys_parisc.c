static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
struct V_3 * V_4 ;
V_1 = F_2 ( V_1 ) ;
for ( V_4 = F_3 ( V_5 -> V_6 , V_1 ) ; ; V_4 = V_4 -> V_7 ) {
if ( V_8 - V_2 < V_1 )
return - V_9 ;
if ( ! V_4 || V_1 + V_2 <= V_4 -> V_10 )
return V_1 ;
V_1 = V_4 -> V_11 ;
}
}
static int F_4 ( struct V_12 * V_13 )
{
int V_14 = ( unsigned long ) V_13 << ( V_15 - 8 ) ;
return V_14 & 0x3FF000 ;
}
static unsigned long F_5 ( struct V_12 * V_13 ,
unsigned long V_1 , unsigned long V_2 , unsigned long V_16 )
{
struct V_3 * V_4 ;
int V_14 = V_13 ? F_4 ( V_13 ) : 0 ;
V_1 = F_6 ( V_1 - V_14 ) + V_14 ;
for ( V_4 = F_3 ( V_5 -> V_6 , V_1 ) ; ; V_4 = V_4 -> V_7 ) {
if ( V_8 - V_2 < V_1 )
return - V_9 ;
if ( ! V_4 || V_1 + V_2 <= V_4 -> V_10 )
return V_1 ;
V_1 = F_6 ( V_4 -> V_11 - V_14 ) + V_14 ;
if ( V_1 < V_4 -> V_11 )
return - V_9 ;
}
}
unsigned long F_7 ( struct V_17 * V_18 , unsigned long V_1 ,
unsigned long V_2 , unsigned long V_16 , unsigned long V_19 )
{
if ( V_2 > V_8 )
return - V_9 ;
if ( V_19 & V_20 )
return V_1 ;
if ( ! V_1 )
V_1 = V_21 ;
if ( V_18 ) {
V_1 = F_5 ( V_18 -> V_22 , V_1 , V_2 , V_16 ) ;
} else if( V_19 & V_23 ) {
V_1 = F_5 ( NULL , V_1 , V_2 , V_16 ) ;
} else {
V_1 = F_1 ( V_1 , V_2 ) ;
}
return V_1 ;
}
T_1 unsigned long F_8 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_24 , unsigned long V_19 , unsigned long V_25 ,
unsigned long V_16 )
{
return F_9 ( V_1 , V_2 , V_24 , V_19 , V_25 ,
V_16 >> ( V_15 - 12 ) ) ;
}
T_1 unsigned long F_10 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_24 , unsigned long V_19 , unsigned long V_25 ,
unsigned long V_14 )
{
if ( ! ( V_14 & ~ V_26 ) ) {
return F_9 ( V_1 , V_2 , V_24 , V_19 , V_25 ,
V_14 >> V_15 ) ;
} else {
return - V_27 ;
}
}
T_1 long F_11 ( const char T_2 * V_28 ,
unsigned int V_29 , unsigned int V_30 )
{
return F_12 ( V_28 , ( long ) V_29 << 32 | V_30 ) ;
}
T_1 long F_13 ( unsigned int V_25 ,
unsigned int V_29 , unsigned int V_30 )
{
return F_14 ( V_25 , ( long ) V_29 << 32 | V_30 ) ;
}
T_1 long F_15 ( const char T_2 * V_28 , unsigned long V_31 )
{
return F_12 ( V_28 , V_31 ) ;
}
T_1 long F_16 ( unsigned int V_25 , unsigned long V_31 )
{
return F_14 ( V_25 , V_31 ) ;
}
T_1 long F_17 ( unsigned int V_25 , unsigned int V_32 , unsigned long V_33 )
{
return F_18 ( V_25 , V_32 , V_33 ) ;
}
T_1 long F_11 ( const char T_2 * V_28 ,
unsigned int V_29 , unsigned int V_30 )
{
return F_15 ( V_28 , ( V_34 ) V_29 << 32 | V_30 ) ;
}
T_1 long F_13 ( unsigned int V_25 ,
unsigned int V_29 , unsigned int V_30 )
{
return F_16 ( V_25 , ( V_34 ) V_29 << 32 | V_30 ) ;
}
T_1 T_3 F_19 ( unsigned int V_25 , char T_2 * V_35 , T_4 V_36 ,
unsigned int V_29 , unsigned int V_30 )
{
return F_20 ( V_25 , V_35 , V_36 , ( V_34 ) V_29 << 32 | V_30 ) ;
}
T_1 T_3 F_21 ( unsigned int V_25 , const char T_2 * V_35 ,
T_4 V_36 , unsigned int V_29 , unsigned int V_30 )
{
return F_22 ( V_25 , V_35 , V_36 , ( V_34 ) V_29 << 32 | V_30 ) ;
}
T_1 T_3 F_23 ( int V_25 , unsigned int V_29 , unsigned int V_30 ,
T_4 V_36 )
{
return F_24 ( V_25 , ( V_34 ) V_29 << 32 | V_30 , V_36 ) ;
}
T_1 long F_25 ( int V_25 ,
unsigned int V_37 , unsigned int V_38 ,
unsigned int V_39 , unsigned int V_40 , int V_41 )
{
return F_26 ( V_25 , ( V_34 ) V_37 << 32 | V_38 ,
( V_34 ) V_39 << 32 | V_40 , V_41 ) ;
}
T_1 long F_27 ( int V_25 ,
T_5 V_42 , T_5 V_43 , T_5 V_44 , T_5 V_45 ,
unsigned int V_19 )
{
return F_28 ( V_25 , ( V_34 ) V_42 << 32 | V_43 ,
( V_34 ) V_44 << 32 | V_45 , V_19 ) ;
}
T_1 unsigned long F_29 ( int V_46 , unsigned long V_1 , unsigned long V_2 , int V_24 , int V_47 )
{
return - V_9 ;
}
T_1 int F_30 ( unsigned long V_1 )
{
return - V_27 ;
}
long F_31 ( unsigned long V_48 )
{
long V_49 ;
if ( V_48 ( V_5 -> V_48 ) == V_50
&& V_48 ( V_48 ) == V_51 )
V_48 = ( V_48 & ~ V_52 ) | V_50 ;
V_49 = F_32 ( V_48 ) ;
if ( V_48 ( V_49 ) == V_50 )
V_49 = ( V_49 & ~ V_52 ) | V_51 ;
return V_49 ;
}
