int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 + V_5 ;
struct V_6 V_7 ;
T_1 V_8 ;
if ( ! V_4 -> V_9 )
return - 1 ;
F_2 ( V_2 , & V_7 , V_4 ) ;
F_3 ( V_2 , V_2 -> V_10 , & V_8 ) ;
V_8 &= ~ V_11 ;
V_8 |= V_7 . V_12 | V_13 ;
F_4 ( V_2 , V_2 -> V_10 , V_8 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_3 ( V_2 , V_2 -> V_10 , & V_8 ) ;
V_8 &= ~ V_13 ;
F_4 ( V_2 , V_2 -> V_10 , V_8 ) ;
}
T_2 F_6 ( struct V_1 * V_2 , void T_3 * V_14 , T_2 V_15 )
{
void T_3 * V_16 ;
int V_17 ;
V_16 = V_14 ;
do {
void T_3 * V_18 ;
if ( F_7 ( V_16 ) != 0x55 ) {
F_8 ( & V_2 -> V_19 , L_1 ) ;
break;
}
if ( F_7 ( V_16 + 1 ) != 0xAA )
break;
V_18 = V_16 + F_9 ( V_16 + 24 ) ;
if ( F_7 ( V_18 ) != 'P' )
break;
if ( F_7 ( V_18 + 1 ) != 'C' )
break;
if ( F_7 ( V_18 + 2 ) != 'I' )
break;
if ( F_7 ( V_18 + 3 ) != 'R' )
break;
V_17 = F_7 ( V_18 + 21 ) & 0x80 ;
V_16 += F_9 ( V_18 + 16 ) * 512 ;
} while ( ! V_17 );
return F_10 ( ( T_2 ) ( V_16 - V_14 ) , V_15 ) ;
}
void T_3 * F_11 ( struct V_1 * V_2 , T_2 * V_15 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
T_4 V_12 ;
void T_3 * V_14 ;
if ( V_4 -> V_9 & V_20 ) {
V_12 = ( T_4 ) 0xC0000 ;
* V_15 = 0x20000 ;
} else {
if ( V_4 -> V_9 &
( V_21 | V_22 ) ) {
* V_15 = F_12 ( V_2 , V_5 ) ;
return ( void T_3 * ) ( unsigned long )
F_13 ( V_2 , V_5 ) ;
} else {
if ( V_4 -> V_23 == NULL &&
F_14 ( V_2 , V_5 ) )
return NULL ;
V_12 = F_13 ( V_2 , V_5 ) ;
* V_15 = F_12 ( V_2 , V_5 ) ;
if ( * V_15 == 0 )
return NULL ;
if ( F_1 ( V_2 ) )
return NULL ;
}
}
V_14 = F_15 ( V_12 , * V_15 ) ;
if ( ! V_14 ) {
if ( ! ( V_4 -> V_9 & ( V_24 |
V_20 |
V_21 ) ) )
F_5 ( V_2 ) ;
return NULL ;
}
* V_15 = F_6 ( V_2 , V_14 , * V_15 ) ;
return V_14 ;
}
void F_16 ( struct V_1 * V_2 , void T_3 * V_14 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
if ( V_4 -> V_9 & ( V_21 | V_22 ) )
return;
F_17 ( V_14 ) ;
if ( ! ( V_4 -> V_9 & ( V_24 | V_20 ) ) )
F_5 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
if ( V_4 -> V_9 & V_21 ) {
F_19 ( ( void * ) ( unsigned long ) V_4 -> V_12 ) ;
V_4 -> V_9 &= ~ V_21 ;
V_4 -> V_12 = 0 ;
V_4 -> V_25 = 0 ;
}
}
