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
if ( ! F_7 () && ( V_2 & V_14 ) ) {
* V_12 = 0x40000000 ;
* V_13 = 0x80000000 ;
if ( V_3 -> V_2 & V_4 ) {
* V_12 = F_8 ( * V_12 , 0x02000000 ) ;
}
return;
}
* V_12 = F_9 ( 1 ) ;
* V_13 = F_7 () ? F_10 () : F_11 () ;
}
unsigned long
F_12 ( struct V_15 * V_16 , unsigned long V_7 ,
unsigned long V_17 , unsigned long V_18 , unsigned long V_2 )
{
struct V_19 * V_20 = V_3 -> V_20 ;
struct V_21 * V_22 ;
struct V_23 V_24 ;
unsigned long V_12 , V_13 ;
if ( V_2 & V_25 )
return V_7 ;
F_6 ( V_2 , & V_12 , & V_13 ) ;
if ( V_17 > V_13 )
return - V_26 ;
if ( V_7 ) {
V_7 = F_13 ( V_7 ) ;
V_22 = F_14 ( V_20 , V_7 ) ;
if ( V_13 - V_17 >= V_7 &&
( ! V_22 || V_7 + V_17 <= F_15 ( V_22 ) ) )
return V_7 ;
}
V_24 . V_2 = 0 ;
V_24 . V_27 = V_17 ;
V_24 . V_28 = V_12 ;
V_24 . V_29 = V_13 ;
V_24 . V_8 = 0 ;
V_24 . V_30 = V_18 << V_31 ;
if ( V_16 ) {
V_24 . V_8 = F_1 () ;
V_24 . V_30 += F_3 () ;
}
return F_16 ( & V_24 ) ;
}
unsigned long
F_17 ( struct V_15 * V_16 , const unsigned long V_32 ,
const unsigned long V_17 , const unsigned long V_18 ,
const unsigned long V_2 )
{
struct V_21 * V_22 ;
struct V_19 * V_20 = V_3 -> V_20 ;
unsigned long V_7 = V_32 ;
struct V_23 V_24 ;
if ( V_17 > V_33 )
return - V_26 ;
if ( V_2 & V_25 )
return V_7 ;
if ( ! F_7 () && ( V_2 & V_14 ) )
goto V_34;
if ( V_7 ) {
V_7 = F_13 ( V_7 ) ;
V_22 = F_14 ( V_20 , V_7 ) ;
if ( V_33 - V_17 >= V_7 &&
( ! V_22 || V_7 + V_17 <= F_15 ( V_22 ) ) )
return V_7 ;
}
V_24 . V_2 = V_35 ;
V_24 . V_27 = V_17 ;
V_24 . V_28 = V_36 ;
V_24 . V_29 = F_9 ( 0 ) ;
V_24 . V_8 = 0 ;
V_24 . V_30 = V_18 << V_31 ;
if ( V_16 ) {
V_24 . V_8 = F_1 () ;
V_24 . V_30 += F_3 () ;
}
V_7 = F_16 ( & V_24 ) ;
if ( ! ( V_7 & ~ V_37 ) )
return V_7 ;
F_18 ( V_7 != - V_26 ) ;
V_34:
return F_12 ( V_16 , V_32 , V_17 , V_18 , V_2 ) ;
}
