static unsigned long F_1 ( void )
{
if ( V_1 . V_2 < 0 || ! ( V_1 . V_2 & ( 2 - F_2 () ) ) )
return 0 ;
if ( ! ( V_3 -> V_2 & V_4 ) )
return 0 ;
return V_1 . V_5 ;
}
static unsigned long F_3 ( void )
{
return V_1 . V_6 & F_1 () ;
}
unsigned long F_4 ( unsigned long V_7 )
{
unsigned long V_8 = F_1 () ;
V_7 = ( V_7 + V_8 ) & ~ V_8 ;
return V_7 | F_3 () ;
}
static int T_1 F_5 ( char * V_9 )
{
if ( V_1 . V_2 < 0 )
return 1 ;
if ( * V_9 == 0 )
return 1 ;
if ( * V_9 == '=' )
V_9 ++ ;
if ( ! strcmp ( V_9 , L_1 ) )
V_1 . V_2 = V_10 ;
else if ( ! strcmp ( V_9 , L_2 ) )
V_1 . V_2 = V_11 ;
else if ( ! strcmp ( V_9 , L_3 ) )
V_1 . V_2 = 0 ;
else if ( ! strcmp ( V_9 , L_4 ) )
V_1 . V_2 = V_10 | V_11 ;
else
return 0 ;
return 1 ;
}
static void F_6 ( unsigned long V_2 , unsigned long * V_12 ,
unsigned long * V_13 )
{
if ( ! F_7 ( V_14 ) && ( V_2 & V_15 ) ) {
unsigned long V_16 ;
* V_12 = 0x40000000 ;
* V_13 = 0x80000000 ;
if ( V_3 -> V_2 & V_4 ) {
V_16 = F_8 ( * V_12 , * V_12 + 0x02000000 , 0 ) ;
if ( V_16 )
* V_12 = V_16 ;
}
} else {
* V_12 = V_3 -> V_17 -> V_18 ;
* V_13 = V_19 ;
}
}
unsigned long
F_9 ( struct V_20 * V_21 , unsigned long V_7 ,
unsigned long V_22 , unsigned long V_23 , unsigned long V_2 )
{
struct V_24 * V_17 = V_3 -> V_17 ;
struct V_25 * V_26 ;
struct V_27 V_28 ;
unsigned long V_12 , V_13 ;
if ( V_2 & V_29 )
return V_7 ;
F_6 ( V_2 , & V_12 , & V_13 ) ;
if ( V_22 > V_13 )
return - V_30 ;
if ( V_7 ) {
V_7 = F_10 ( V_7 ) ;
V_26 = F_11 ( V_17 , V_7 ) ;
if ( V_13 - V_22 >= V_7 &&
( ! V_26 || V_7 + V_22 <= V_26 -> V_31 ) )
return V_7 ;
}
V_28 . V_2 = 0 ;
V_28 . V_32 = V_22 ;
V_28 . V_33 = V_12 ;
V_28 . V_34 = V_13 ;
V_28 . V_8 = 0 ;
V_28 . V_35 = V_23 << V_36 ;
if ( V_21 ) {
V_28 . V_8 = F_1 () ;
V_28 . V_35 += F_3 () ;
}
return F_12 ( & V_28 ) ;
}
unsigned long
F_13 ( struct V_20 * V_21 , const unsigned long V_37 ,
const unsigned long V_22 , const unsigned long V_23 ,
const unsigned long V_2 )
{
struct V_25 * V_26 ;
struct V_24 * V_17 = V_3 -> V_17 ;
unsigned long V_7 = V_37 ;
struct V_27 V_28 ;
if ( V_22 > V_19 )
return - V_30 ;
if ( V_2 & V_29 )
return V_7 ;
if ( ! F_7 ( V_14 ) && ( V_2 & V_15 ) )
goto V_38;
if ( V_7 ) {
V_7 = F_10 ( V_7 ) ;
V_26 = F_11 ( V_17 , V_7 ) ;
if ( V_19 - V_22 >= V_7 &&
( ! V_26 || V_7 + V_22 <= V_26 -> V_31 ) )
return V_7 ;
}
V_28 . V_2 = V_39 ;
V_28 . V_32 = V_22 ;
V_28 . V_33 = V_40 ;
V_28 . V_34 = V_17 -> V_41 ;
V_28 . V_8 = 0 ;
V_28 . V_35 = V_23 << V_36 ;
if ( V_21 ) {
V_28 . V_8 = F_1 () ;
V_28 . V_35 += F_3 () ;
}
V_7 = F_12 ( & V_28 ) ;
if ( ! ( V_7 & ~ V_42 ) )
return V_7 ;
F_14 ( V_7 != - V_30 ) ;
V_38:
return F_9 ( V_21 , V_37 , V_22 , V_23 , V_2 ) ;
}
