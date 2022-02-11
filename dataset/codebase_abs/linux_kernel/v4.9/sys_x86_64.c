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
* V_12 = 0x40000000 ;
* V_13 = 0x80000000 ;
if ( V_3 -> V_2 & V_4 ) {
* V_12 = F_8 ( * V_12 , 0x02000000 ) ;
}
} else {
* V_12 = V_3 -> V_16 -> V_17 ;
* V_13 = V_18 ;
}
}
unsigned long
F_9 ( struct V_19 * V_20 , unsigned long V_7 ,
unsigned long V_21 , unsigned long V_22 , unsigned long V_2 )
{
struct V_23 * V_16 = V_3 -> V_16 ;
struct V_24 * V_25 ;
struct V_26 V_27 ;
unsigned long V_12 , V_13 ;
if ( V_2 & V_28 )
return V_7 ;
F_6 ( V_2 , & V_12 , & V_13 ) ;
if ( V_21 > V_13 )
return - V_29 ;
if ( V_7 ) {
V_7 = F_10 ( V_7 ) ;
V_25 = F_11 ( V_16 , V_7 ) ;
if ( V_13 - V_21 >= V_7 &&
( ! V_25 || V_7 + V_21 <= V_25 -> V_30 ) )
return V_7 ;
}
V_27 . V_2 = 0 ;
V_27 . V_31 = V_21 ;
V_27 . V_32 = V_12 ;
V_27 . V_33 = V_13 ;
V_27 . V_8 = 0 ;
V_27 . V_34 = V_22 << V_35 ;
if ( V_20 ) {
V_27 . V_8 = F_1 () ;
V_27 . V_34 += F_3 () ;
}
return F_12 ( & V_27 ) ;
}
unsigned long
F_13 ( struct V_19 * V_20 , const unsigned long V_36 ,
const unsigned long V_21 , const unsigned long V_22 ,
const unsigned long V_2 )
{
struct V_24 * V_25 ;
struct V_23 * V_16 = V_3 -> V_16 ;
unsigned long V_7 = V_36 ;
struct V_26 V_27 ;
if ( V_21 > V_18 )
return - V_29 ;
if ( V_2 & V_28 )
return V_7 ;
if ( ! F_7 ( V_14 ) && ( V_2 & V_15 ) )
goto V_37;
if ( V_7 ) {
V_7 = F_10 ( V_7 ) ;
V_25 = F_11 ( V_16 , V_7 ) ;
if ( V_18 - V_21 >= V_7 &&
( ! V_25 || V_7 + V_21 <= V_25 -> V_30 ) )
return V_7 ;
}
V_27 . V_2 = V_38 ;
V_27 . V_31 = V_21 ;
V_27 . V_32 = V_39 ;
V_27 . V_33 = V_16 -> V_40 ;
V_27 . V_8 = 0 ;
V_27 . V_34 = V_22 << V_35 ;
if ( V_20 ) {
V_27 . V_8 = F_1 () ;
V_27 . V_34 += F_3 () ;
}
V_7 = F_12 ( & V_27 ) ;
if ( ! ( V_7 & ~ V_41 ) )
return V_7 ;
F_14 ( V_7 != - V_29 ) ;
V_37:
return F_9 ( V_20 , V_36 , V_21 , V_22 , V_2 ) ;
}
