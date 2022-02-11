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
static void F_6 ( unsigned long V_7 , unsigned long V_2 ,
unsigned long * V_12 , unsigned long * V_13 )
{
if ( ! F_7 () && ( V_2 & V_14 ) ) {
* V_12 = 0x40000000 ;
* V_13 = 0x80000000 ;
if ( V_3 -> V_2 & V_4 ) {
* V_12 = F_8 ( * V_12 , 0x02000000 ) ;
}
return;
}
* V_12 = F_9 ( 1 ) ;
if ( F_7 () )
* V_13 = F_10 () ;
else
* V_13 = F_11 ( V_7 > V_15 ) ;
}
unsigned long
F_12 ( struct V_16 * V_17 , unsigned long V_7 ,
unsigned long V_18 , unsigned long V_19 , unsigned long V_2 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_22 * V_23 ;
struct V_24 V_25 ;
unsigned long V_12 , V_13 ;
V_7 = F_13 ( V_7 , V_18 , V_2 ) ;
if ( F_14 ( V_7 ) )
return V_7 ;
if ( V_2 & V_26 )
return V_7 ;
F_6 ( V_7 , V_2 , & V_12 , & V_13 ) ;
if ( V_18 > V_13 )
return - V_27 ;
if ( V_7 ) {
V_7 = F_15 ( V_7 ) ;
V_23 = F_16 ( V_21 , V_7 ) ;
if ( V_13 - V_18 >= V_7 &&
( ! V_23 || V_7 + V_18 <= F_17 ( V_23 ) ) )
return V_7 ;
}
V_25 . V_2 = 0 ;
V_25 . V_28 = V_18 ;
V_25 . V_29 = V_12 ;
V_25 . V_30 = V_13 ;
V_25 . V_8 = 0 ;
V_25 . V_31 = V_19 << V_32 ;
if ( V_17 ) {
V_25 . V_8 = F_1 () ;
V_25 . V_31 += F_3 () ;
}
return F_18 ( & V_25 ) ;
}
unsigned long
F_19 ( struct V_16 * V_17 , const unsigned long V_33 ,
const unsigned long V_18 , const unsigned long V_19 ,
const unsigned long V_2 )
{
struct V_22 * V_23 ;
struct V_20 * V_21 = V_3 -> V_21 ;
unsigned long V_7 = V_33 ;
struct V_24 V_25 ;
V_7 = F_13 ( V_7 , V_18 , V_2 ) ;
if ( F_14 ( V_7 ) )
return V_7 ;
if ( V_18 > V_34 )
return - V_27 ;
if ( V_2 & V_26 )
return V_7 ;
if ( ! F_7 () && ( V_2 & V_14 ) )
goto V_35;
if ( V_7 ) {
V_7 = F_15 ( V_7 ) ;
V_23 = F_16 ( V_21 , V_7 ) ;
if ( V_34 - V_18 >= V_7 &&
( ! V_23 || V_7 + V_18 <= F_17 ( V_23 ) ) )
return V_7 ;
}
V_25 . V_2 = V_36 ;
V_25 . V_28 = V_18 ;
V_25 . V_29 = V_37 ;
V_25 . V_30 = F_9 ( 0 ) ;
if ( V_7 > V_15 && ! F_7 () )
V_25 . V_30 += V_38 - V_15 ;
V_25 . V_8 = 0 ;
V_25 . V_31 = V_19 << V_32 ;
if ( V_17 ) {
V_25 . V_8 = F_1 () ;
V_25 . V_31 += F_3 () ;
}
V_7 = F_18 ( & V_25 ) ;
if ( ! ( V_7 & ~ V_39 ) )
return V_7 ;
F_20 ( V_7 != - V_27 ) ;
V_35:
return F_12 ( V_17 , V_33 , V_18 , V_19 , V_2 ) ;
}
