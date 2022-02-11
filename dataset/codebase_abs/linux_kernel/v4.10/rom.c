int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
struct V_6 V_7 ;
T_1 V_8 ;
if ( ! V_4 -> V_9 )
return - 1 ;
if ( V_4 -> V_9 & V_10 )
return 0 ;
F_2 ( V_2 -> V_11 , & V_7 , V_4 ) ;
F_3 ( V_2 , V_2 -> V_12 , & V_8 ) ;
V_8 &= ~ V_13 ;
V_8 |= V_7 . V_14 | V_15 ;
F_4 ( V_2 , V_2 -> V_12 , V_8 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
T_1 V_8 ;
if ( V_4 -> V_9 & V_10 )
return;
F_3 ( V_2 , V_2 -> V_12 , & V_8 ) ;
V_8 &= ~ V_15 ;
F_4 ( V_2 , V_2 -> V_12 , V_8 ) ;
}
T_2 F_6 ( struct V_1 * V_2 , void T_3 * V_16 , T_2 V_17 )
{
void T_3 * V_18 ;
int V_19 ;
unsigned V_20 ;
V_18 = V_16 ;
do {
void T_3 * V_21 ;
if ( F_7 ( V_18 ) != 0xAA55 ) {
F_8 ( & V_2 -> V_22 , L_1 ,
F_7 ( V_18 ) ) ;
break;
}
V_21 = V_18 + F_7 ( V_18 + 24 ) ;
if ( F_9 ( V_21 ) != 0x52494350 ) {
F_8 ( & V_2 -> V_22 , L_2 ,
F_9 ( V_21 ) ) ;
break;
}
V_19 = F_10 ( V_21 + 21 ) & 0x80 ;
V_20 = F_7 ( V_21 + 16 ) ;
V_18 += V_20 * 512 ;
if ( V_18 > V_16 + V_17 )
break;
} while ( V_20 && ! V_19 );
return F_11 ( ( T_2 ) ( V_18 - V_16 ) , V_17 ) ;
}
void T_3 * F_12 ( struct V_1 * V_2 , T_2 * V_17 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
T_4 V_14 ;
void T_3 * V_16 ;
if ( V_4 -> V_23 == NULL && F_13 ( V_2 , V_5 ) )
return NULL ;
V_14 = F_14 ( V_2 , V_5 ) ;
* V_17 = F_15 ( V_2 , V_5 ) ;
if ( * V_17 == 0 )
return NULL ;
if ( F_1 ( V_2 ) )
return NULL ;
V_16 = F_16 ( V_14 , * V_17 ) ;
if ( ! V_16 ) {
if ( ! ( V_4 -> V_9 & V_24 ) )
F_5 ( V_2 ) ;
return NULL ;
}
* V_17 = F_6 ( V_2 , V_16 , * V_17 ) ;
return V_16 ;
}
void F_17 ( struct V_1 * V_2 , void T_3 * V_16 )
{
struct V_3 * V_4 = & V_2 -> V_3 [ V_5 ] ;
F_18 ( V_16 ) ;
if ( ! ( V_4 -> V_9 & V_24 ) )
F_5 ( V_2 ) ;
}
void T_3 * F_19 ( struct V_1 * V_2 , T_2 * V_17 )
{
if ( V_2 -> V_16 && V_2 -> V_25 ) {
* V_17 = V_2 -> V_25 ;
return F_20 ( ( V_26 ) V_2 -> V_16 ) ;
}
return NULL ;
}
