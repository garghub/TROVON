static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static unsigned long F_3 ( unsigned long V_4 ,
unsigned long V_5 ,
T_1 * V_6 , T_1 * V_7 )
{
unsigned long V_8 = 0 ;
T_1 V_9 = 0 , V_10 = 0 , V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
unsigned long V_13 ;
V_13 = ( ( ( V_5 / 2 ) / 10 ) >> V_12 ) / ( V_11 + 1 ) ;
if ( V_13 > V_4 )
continue;
if ( abs ( V_4 - V_13 ) < abs ( V_4 - V_8 ) ) {
V_8 = V_13 ;
V_9 = V_11 ;
V_10 = V_12 ;
}
}
}
if ( V_6 && V_7 ) {
* V_6 = V_9 ;
* V_7 = V_10 ;
}
return V_8 ;
}
static long F_4 ( struct V_2 * V_3 , unsigned long V_4 ,
unsigned long * V_14 )
{
return F_3 ( V_4 , * V_14 , NULL , NULL ) ;
}
static unsigned long F_5 ( struct V_2 * V_3 ,
unsigned long V_5 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_2 V_16 ;
T_1 V_6 , V_7 ;
V_16 = F_6 ( V_15 -> V_17 -> V_18 + V_19 ) ;
V_6 = ( V_16 >> 3 ) & 0x7 ;
V_7 = V_16 & 0x7 ;
return ( ( ( V_5 / 2 ) / 10 ) >> V_7 ) / ( V_6 + 1 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned long V_4 ,
unsigned long V_5 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_1 V_20 , V_21 ;
F_3 ( V_4 , V_5 , & V_20 , & V_21 ) ;
F_8 ( F_9 ( V_20 ) | F_10 ( V_21 ) ,
V_15 -> V_17 -> V_18 + V_19 ) ;
return 0 ;
}
int F_11 ( struct V_22 * V_17 , struct V_23 * V_24 )
{
struct V_25 V_26 ;
struct V_1 * V_15 ;
const char * V_27 ;
V_27 = F_12 ( V_24 ) ;
if ( ! V_27 )
return - V_28 ;
V_15 = F_13 ( V_17 -> V_29 , sizeof( * V_15 ) , V_30 ) ;
if ( ! V_15 )
return - V_31 ;
V_26 . V_32 = L_1 ;
V_26 . V_33 = & V_34 ;
V_26 . V_35 = & V_27 ;
V_26 . V_36 = 1 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_3 . V_26 = & V_26 ;
V_17 -> V_37 = F_14 ( V_17 -> V_29 , & V_15 -> V_3 ) ;
if ( F_15 ( V_17 -> V_37 ) )
return F_16 ( V_17 -> V_37 ) ;
return 0 ;
}
