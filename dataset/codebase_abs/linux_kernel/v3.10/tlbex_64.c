static int F_1 ( unsigned long long V_1 ,
unsigned long V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
T_4 V_7 ;
if ( F_2 ( ( void * ) V_2 ) ) {
V_3 = F_3 ( V_2 ) ;
} else {
if ( F_4 ( V_2 >= V_8 || ! V_9 -> V_10 ) )
return 1 ;
V_3 = F_5 ( V_9 -> V_10 , V_2 ) ;
}
V_4 = F_6 ( V_3 , V_2 ) ;
if ( F_7 ( * V_4 ) || ! F_8 ( * V_4 ) )
return 1 ;
V_5 = F_9 ( V_4 , V_2 ) ;
if ( F_10 ( * V_5 ) || ! F_11 ( * V_5 ) )
return 1 ;
V_6 = F_12 ( V_5 , V_2 ) ;
V_7 = * V_6 ;
if ( F_13 ( V_7 ) || ! F_14 ( V_7 ) )
return 1 ;
if ( ( F_15 ( V_7 ) & V_1 ) != V_1 )
return 1 ;
F_16 ( NULL , V_2 , V_6 ) ;
return 0 ;
}
static inline unsigned int
F_17 ( unsigned long V_11 )
{
if ( V_11 == 0xa40 )
return V_12 ;
else if ( V_11 == 0x060 )
return V_13 ;
return 0 ;
}
T_5 int T_6
F_18 ( unsigned long long V_14 , unsigned long long V_11 ,
unsigned long V_2 )
{
unsigned long long V_1 ;
unsigned long long V_15 ;
unsigned long long V_16 ;
unsigned int V_17 ;
V_16 = ( V_11 >> 4 ) ;
V_15 = V_16 ^ ( V_16 >> 5 ) ;
V_15 &= 7 ;
V_17 = F_17 ( V_11 ) ;
V_1 = V_18 . V_1 [ V_15 ] ;
if ( V_18 . V_19 [ V_15 ] )
V_17 |= V_12 ;
if ( ! V_14 )
V_17 |= V_20 ;
F_19 ( V_17 ) ;
return F_1 ( V_1 , V_2 ) ;
}
