int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 + V_5 ;
struct V_6 V_7 ;
T_1 V_8 ;
if ( ! V_4 -> V_9 )
return - 1 ;
F_2 ( V_2 -> V_10 , & V_7 , V_4 ) ;
F_3 ( V_2 , V_2 -> V_11 , & V_8 ) ;
V_8 &= ~ V_12 ;
V_8 |= V_7 . V_13 | V_14 ;
F_4 ( V_2 , V_2 -> V_11 , V_8 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_3 ( V_2 , V_2 -> V_11 , & V_8 ) ;
V_8 &= ~ V_14 ;
F_4 ( V_2 , V_2 -> V_11 , V_8 ) ;
}
T_2 F_6 ( struct V_1 * V_2 , void T_3 * V_15 , T_2 V_16 )
{
void T_3 * V_17 ;
int V_18 ;
unsigned V_19 ;
V_17 = V_15 ;
do {
void T_3 * V_20 ;
if ( F_7 ( V_17 ) != 0xAA55 ) {
F_8 ( & V_2 -> V_21 , L_1 ,
F_7 ( V_17 ) ) ;
break;
}
V_20 = V_17 + F_7 ( V_17 + 24 ) ;
if ( F_9 ( V_20 ) != 0x52494350 ) {
F_8 ( & V_2 -> V_21 , L_2 ,
F_9 ( V_20 ) ) ;
break;
}
V_18 = F_10 ( V_20 + 21 ) & 0x80 ;
V_19 = F_7 ( V_20 + 16 ) ;
V_17 += V_19 * 512 ;
if ( V_17 > V_15 + V_16 )
break;
} while ( V_19 && ! V_18 );
return F_11 ( ( T_2 ) ( V_17 - V_15 ) , V_16 ) ;
}
void T_3 * F_12 ( struct V_1 * V_2 , T_2 * V_16 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
T_4 V_13 ;
void T_3 * V_15 ;
if ( V_4 -> V_9 & V_22 ) {
V_13 = ( T_4 ) 0xC0000 ;
* V_16 = 0x20000 ;
} else {
if ( V_4 -> V_9 &
( V_23 | V_24 ) ) {
* V_16 = F_13 ( V_2 , V_5 ) ;
return ( void T_3 * ) ( unsigned long )
F_14 ( V_2 , V_5 ) ;
} else {
if ( V_4 -> V_25 == NULL &&
F_15 ( V_2 , V_5 ) )
return NULL ;
V_13 = F_14 ( V_2 , V_5 ) ;
* V_16 = F_13 ( V_2 , V_5 ) ;
if ( * V_16 == 0 )
return NULL ;
if ( F_1 ( V_2 ) )
return NULL ;
}
}
V_15 = F_16 ( V_13 , * V_16 ) ;
if ( ! V_15 ) {
if ( ! ( V_4 -> V_9 & ( V_26 |
V_22 |
V_23 ) ) )
F_5 ( V_2 ) ;
return NULL ;
}
* V_16 = F_6 ( V_2 , V_15 , * V_16 ) ;
return V_15 ;
}
void F_17 ( struct V_1 * V_2 , void T_3 * V_15 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
if ( V_4 -> V_9 & ( V_23 | V_24 ) )
return;
F_18 ( V_15 ) ;
if ( ! ( V_4 -> V_9 & ( V_26 | V_22 ) ) )
F_5 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
if ( V_4 -> V_9 & V_23 ) {
F_20 ( ( void * ) ( unsigned long ) V_4 -> V_13 ) ;
V_4 -> V_9 |= V_27 ;
V_4 -> V_9 &= ~ V_23 ;
V_4 -> V_13 = 0 ;
V_4 -> V_28 = 0 ;
}
}
void T_3 * F_21 ( struct V_1 * V_2 , T_2 * V_16 )
{
if ( V_2 -> V_15 && V_2 -> V_29 ) {
* V_16 = V_2 -> V_29 ;
return F_22 ( ( V_30 ) V_2 -> V_15 ) ;
}
return NULL ;
}
