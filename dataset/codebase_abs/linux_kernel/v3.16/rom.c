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
V_17 = V_15 ;
do {
void T_3 * V_19 ;
if ( F_7 ( V_17 ) != 0x55 ) {
F_8 ( & V_2 -> V_20 , L_1 ) ;
break;
}
if ( F_7 ( V_17 + 1 ) != 0xAA )
break;
V_19 = V_17 + F_9 ( V_17 + 24 ) ;
if ( F_7 ( V_19 ) != 'P' )
break;
if ( F_7 ( V_19 + 1 ) != 'C' )
break;
if ( F_7 ( V_19 + 2 ) != 'I' )
break;
if ( F_7 ( V_19 + 3 ) != 'R' )
break;
V_18 = F_7 ( V_19 + 21 ) & 0x80 ;
V_17 += F_9 ( V_19 + 16 ) * 512 ;
} while ( ! V_18 );
return F_10 ( ( T_2 ) ( V_17 - V_15 ) , V_16 ) ;
}
void T_3 * F_11 ( struct V_1 * V_2 , T_2 * V_16 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
T_4 V_13 ;
void T_3 * V_15 ;
if ( V_4 -> V_9 & V_21 ) {
V_13 = ( T_4 ) 0xC0000 ;
* V_16 = 0x20000 ;
} else {
if ( V_4 -> V_9 &
( V_22 | V_23 ) ) {
* V_16 = F_12 ( V_2 , V_5 ) ;
return ( void T_3 * ) ( unsigned long )
F_13 ( V_2 , V_5 ) ;
} else {
if ( V_4 -> V_24 == NULL &&
F_14 ( V_2 , V_5 ) )
return NULL ;
V_13 = F_13 ( V_2 , V_5 ) ;
* V_16 = F_12 ( V_2 , V_5 ) ;
if ( * V_16 == 0 )
return NULL ;
if ( F_1 ( V_2 ) )
return NULL ;
}
}
V_15 = F_15 ( V_13 , * V_16 ) ;
if ( ! V_15 ) {
if ( ! ( V_4 -> V_9 & ( V_25 |
V_21 |
V_22 ) ) )
F_5 ( V_2 ) ;
return NULL ;
}
* V_16 = F_6 ( V_2 , V_15 , * V_16 ) ;
return V_15 ;
}
void F_16 ( struct V_1 * V_2 , void T_3 * V_15 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
if ( V_4 -> V_9 & ( V_22 | V_23 ) )
return;
F_17 ( V_15 ) ;
if ( ! ( V_4 -> V_9 & ( V_25 | V_21 ) ) )
F_5 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
if ( V_4 -> V_9 & V_22 ) {
F_19 ( ( void * ) ( unsigned long ) V_4 -> V_13 ) ;
V_4 -> V_9 |= V_26 ;
V_4 -> V_9 &= ~ V_22 ;
V_4 -> V_13 = 0 ;
V_4 -> V_27 = 0 ;
}
}
void T_3 * F_20 ( struct V_1 * V_2 , T_2 * V_16 )
{
if ( V_2 -> V_15 && V_2 -> V_28 ) {
* V_16 = V_2 -> V_28 ;
return F_21 ( ( V_29 ) V_2 -> V_15 ) ;
}
return NULL ;
}
