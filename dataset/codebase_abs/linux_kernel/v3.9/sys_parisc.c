static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
struct V_3 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 = V_2 ;
V_4 . V_7 = F_2 ( V_1 ) ;
V_4 . V_8 = V_9 ;
V_4 . V_10 = 0 ;
V_4 . V_11 = 0 ;
return F_3 ( & V_4 ) ;
}
static int F_4 ( struct V_12 * V_13 )
{
return ( unsigned long ) V_13 >> 8 ;
}
static unsigned long F_5 ( struct V_12 * V_13 ,
unsigned long V_1 , unsigned long V_2 , unsigned long V_14 )
{
struct V_3 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 = V_2 ;
V_4 . V_7 = F_2 ( V_1 ) ;
V_4 . V_8 = V_9 ;
V_4 . V_10 = V_15 & ( V_16 - 1 ) ;
V_4 . V_11 = ( F_4 ( V_13 ) + V_14 ) << V_17 ;
return F_3 ( & V_4 ) ;
}
unsigned long F_6 ( struct V_18 * V_19 , unsigned long V_1 ,
unsigned long V_2 , unsigned long V_14 , unsigned long V_5 )
{
if ( V_2 > V_9 )
return - V_20 ;
if ( V_5 & V_21 ) {
if ( ( V_5 & V_22 ) &&
( V_1 - ( V_14 << V_17 ) ) & ( V_16 - 1 ) )
return - V_23 ;
return V_1 ;
}
if ( ! V_1 )
V_1 = V_24 ;
if ( V_19 ) {
V_1 = F_5 ( V_19 -> V_25 , V_1 , V_2 , V_14 ) ;
} else if( V_5 & V_22 ) {
V_1 = F_5 ( NULL , V_1 , V_2 , V_14 ) ;
} else {
V_1 = F_1 ( V_1 , V_2 ) ;
}
return V_1 ;
}
T_1 unsigned long F_7 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_26 , unsigned long V_5 , unsigned long V_27 ,
unsigned long V_14 )
{
return F_8 ( V_1 , V_2 , V_26 , V_5 , V_27 ,
V_14 >> ( V_17 - 12 ) ) ;
}
T_1 unsigned long F_9 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_26 , unsigned long V_5 , unsigned long V_27 ,
unsigned long V_28 )
{
if ( ! ( V_28 & ~ V_15 ) ) {
return F_8 ( V_1 , V_2 , V_26 , V_5 , V_27 ,
V_28 >> V_17 ) ;
} else {
return - V_23 ;
}
}
T_1 long F_10 ( const char T_2 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
return F_11 ( V_29 , ( long ) V_30 << 32 | V_31 ) ;
}
T_1 long F_12 ( unsigned int V_27 ,
unsigned int V_30 , unsigned int V_31 )
{
return F_13 ( V_27 , ( long ) V_30 << 32 | V_31 ) ;
}
T_1 long F_14 ( const char T_2 * V_29 , unsigned long V_6 )
{
return F_11 ( V_29 , V_6 ) ;
}
T_1 long F_15 ( unsigned int V_27 , unsigned long V_6 )
{
return F_13 ( V_27 , V_6 ) ;
}
T_1 long F_16 ( unsigned int V_27 , unsigned int V_32 , unsigned long V_33 )
{
return F_17 ( V_27 , V_32 , V_33 ) ;
}
T_1 long F_10 ( const char T_2 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
return F_14 ( V_29 , ( V_34 ) V_30 << 32 | V_31 ) ;
}
T_1 long F_12 ( unsigned int V_27 ,
unsigned int V_30 , unsigned int V_31 )
{
return F_15 ( V_27 , ( V_34 ) V_30 << 32 | V_31 ) ;
}
T_1 T_3 F_18 ( unsigned int V_27 , char T_2 * V_35 , T_4 V_36 ,
unsigned int V_30 , unsigned int V_31 )
{
return F_19 ( V_27 , V_35 , V_36 , ( V_34 ) V_30 << 32 | V_31 ) ;
}
T_1 T_3 F_20 ( unsigned int V_27 , const char T_2 * V_35 ,
T_4 V_36 , unsigned int V_30 , unsigned int V_31 )
{
return F_21 ( V_27 , V_35 , V_36 , ( V_34 ) V_30 << 32 | V_31 ) ;
}
T_1 T_3 F_22 ( int V_27 , unsigned int V_30 , unsigned int V_31 ,
T_4 V_36 )
{
return F_23 ( V_27 , ( V_34 ) V_30 << 32 | V_31 , V_36 ) ;
}
T_1 long F_24 ( int V_27 ,
unsigned int V_37 , unsigned int V_38 ,
unsigned int V_39 , unsigned int V_40 , int V_41 )
{
return F_25 ( V_27 , ( V_34 ) V_37 << 32 | V_38 ,
( V_34 ) V_39 << 32 | V_40 , V_41 ) ;
}
T_1 long F_26 ( int V_27 ,
T_5 V_42 , T_5 V_43 , T_5 V_44 , T_5 V_45 ,
unsigned int V_5 )
{
return F_27 ( V_27 , ( V_34 ) V_42 << 32 | V_43 ,
( V_34 ) V_44 << 32 | V_45 , V_5 ) ;
}
T_1 long F_28 ( int V_27 , int V_46 , T_5 V_47 , T_5 V_48 ,
T_5 V_49 , T_5 V_50 )
{
return F_29 ( V_27 , V_46 , ( ( V_51 ) V_47 << 32 ) | V_48 ,
( ( V_51 ) V_49 << 32 ) | V_50 ) ;
}
T_1 unsigned long F_30 ( int V_52 , unsigned long V_1 , unsigned long V_2 , int V_26 , int V_53 )
{
return - V_20 ;
}
T_1 int F_31 ( unsigned long V_1 )
{
return - V_23 ;
}
long F_32 ( unsigned long V_54 )
{
long V_55 ;
if ( V_54 ( V_56 -> V_54 ) == V_57
&& V_54 ( V_54 ) == V_58 )
V_54 = ( V_54 & ~ V_59 ) | V_57 ;
V_55 = F_33 ( V_54 ) ;
if ( V_54 ( V_55 ) == V_57 )
V_55 = ( V_55 & ~ V_59 ) | V_58 ;
return V_55 ;
}
