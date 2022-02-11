static T_1 F_1 ( void * V_1 ,
const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
T_1 V_8 ;
V_8 = ( V_3 -> V_8 & ~ V_7 -> V_9 ) + V_7 -> V_10 ;
if ( V_8 < V_3 -> V_8 )
V_8 += V_7 -> V_9 + 1 ;
#ifdef F_2
if ( V_3 -> V_11 & V_12 ) {
if ( V_8 & 0x300 )
V_8 = ( V_8 + 0x3ff ) & ~ 0x3ff ;
}
#endif
#ifdef F_3
if ( V_3 -> V_11 & V_12 ) {
if ( ( V_3 -> V_8 + V_4 - 1 ) >= 1024 )
V_8 = V_3 -> V_13 ;
}
#endif
return V_8 ;
}
static struct V_2 * F_4 ( struct V_14 * V_15 ,
unsigned long V_16 , int V_17 ,
unsigned long V_5 )
{
struct V_2 * V_3 = F_5 ( 0 , V_17 , V_12 ,
F_6 ( & V_15 -> V_18 ) ) ;
struct V_6 V_7 ;
unsigned long V_19 = V_16 ;
int V_20 ;
V_7 . V_9 = V_5 - 1 ;
V_7 . V_10 = V_16 & V_7 . V_9 ;
#ifdef F_7
if ( V_15 -> V_21 ) {
V_20 = F_8 ( V_15 -> V_21 -> V_22 , V_3 , V_17 , 1 ,
V_19 , 0 , F_1 , & V_7 ) ;
} else
#endif
V_20 = F_9 ( & V_23 , V_3 , V_17 , V_19 , ~ 0UL ,
1 , F_1 , & V_7 ) ;
if ( V_20 != 0 ) {
F_10 ( V_3 ) ;
V_3 = NULL ;
}
return V_3 ;
}
static int F_11 ( struct V_14 * V_15 , unsigned int V_24 ,
unsigned int * V_16 , unsigned int V_17 ,
unsigned int V_5 , struct V_2 * * V_25 )
{
int V_26 , V_20 = 0 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
if ( ! V_15 -> V_28 [ V_26 ] . V_3 )
continue;
if ( ! * V_16 )
continue;
if ( ( V_15 -> V_28 [ V_26 ] . V_3 -> V_8 & ( V_5 - 1 ) ) == * V_16 )
return - V_29 ;
}
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
struct V_2 * V_3 = V_15 -> V_28 [ V_26 ] . V_3 ;
unsigned int V_30 ;
if ( V_3 && ( V_3 -> V_11 & V_31 ) !=
( V_24 & V_31 ) )
continue;
if ( ! V_3 ) {
if ( V_5 == 0 )
V_5 = 0x10000 ;
V_3 = V_15 -> V_28 [ V_26 ] . V_3 = F_4 ( V_15 , * V_16 ,
V_17 , V_5 ) ;
if ( ! V_3 )
return - V_32 ;
* V_16 = V_3 -> V_8 ;
V_15 -> V_28 [ V_26 ] . V_3 -> V_11 =
( ( V_3 -> V_11 & ~ V_31 ) |
( V_24 & V_31 ) ) ;
V_15 -> V_28 [ V_26 ] . V_33 = V_17 ;
* V_25 = V_3 ;
return 0 ;
}
V_30 = V_3 -> V_13 + 1 ;
if ( ( * V_16 == 0 ) || ( * V_16 == V_30 ) ) {
if ( F_12 ( V_15 -> V_28 [ V_26 ] . V_3 , V_3 -> V_8 ,
V_3 -> V_13 - V_3 -> V_8 + V_17 + 1 ) )
continue;
* V_16 = V_30 ;
V_15 -> V_28 [ V_26 ] . V_33 += V_17 ;
* V_25 = V_3 ;
return 0 ;
}
V_30 = V_3 -> V_8 - V_17 ;
if ( ( * V_16 == 0 ) || ( * V_16 == V_30 ) ) {
if ( F_12 ( V_15 -> V_28 [ V_26 ] . V_3 ,
V_3 -> V_8 - V_17 ,
V_3 -> V_13 - V_3 -> V_8 + V_17 + 1 ) )
continue;
* V_16 = V_30 ;
V_15 -> V_28 [ V_26 ] . V_33 += V_17 ;
* V_25 = V_3 ;
return 0 ;
}
}
return - V_32 ;
}
