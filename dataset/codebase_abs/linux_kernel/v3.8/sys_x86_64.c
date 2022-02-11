static unsigned long F_1 ( void )
{
if ( V_1 . V_2 < 0 || ! ( V_1 . V_2 & ( 2 - F_2 () ) ) )
return 0 ;
if ( ! ( V_3 -> V_2 & V_4 ) )
return 0 ;
return V_1 . V_5 ;
}
unsigned long F_3 ( unsigned long V_6 )
{
unsigned long V_7 = F_1 () ;
return ( V_6 + V_7 ) & ~ V_7 ;
}
static int T_1 F_4 ( char * V_8 )
{
if ( V_1 . V_2 < 0 )
return 1 ;
if ( * V_8 == 0 )
return 1 ;
if ( * V_8 == '=' )
V_8 ++ ;
if ( ! strcmp ( V_8 , L_1 ) )
V_1 . V_2 = V_9 ;
else if ( ! strcmp ( V_8 , L_2 ) )
V_1 . V_2 = V_10 ;
else if ( ! strcmp ( V_8 , L_3 ) )
V_1 . V_2 = 0 ;
else if ( ! strcmp ( V_8 , L_4 ) )
V_1 . V_2 = V_9 | V_10 ;
else
return 0 ;
return 1 ;
}
static void F_5 ( unsigned long V_2 , unsigned long * V_11 ,
unsigned long * V_12 )
{
if ( ! F_6 ( V_13 ) && ( V_2 & V_14 ) ) {
unsigned long V_15 ;
* V_11 = 0x40000000 ;
* V_12 = 0x80000000 ;
if ( V_3 -> V_2 & V_4 ) {
V_15 = F_7 ( * V_11 , * V_11 + 0x02000000 , 0 ) ;
if ( V_15 )
* V_11 = V_15 ;
}
} else {
* V_11 = V_16 ;
* V_12 = V_17 ;
}
}
unsigned long
F_8 ( struct V_18 * V_19 , unsigned long V_6 ,
unsigned long V_20 , unsigned long V_21 , unsigned long V_2 )
{
struct V_22 * V_23 = V_3 -> V_23 ;
struct V_24 * V_25 ;
struct V_26 V_27 ;
unsigned long V_11 , V_12 ;
if ( V_2 & V_28 )
return V_6 ;
F_5 ( V_2 , & V_11 , & V_12 ) ;
if ( V_20 > V_12 )
return - V_29 ;
if ( V_6 ) {
V_6 = F_9 ( V_6 ) ;
V_25 = F_10 ( V_23 , V_6 ) ;
if ( V_12 - V_20 >= V_6 &&
( ! V_25 || V_6 + V_20 <= V_25 -> V_30 ) )
return V_6 ;
}
V_27 . V_2 = 0 ;
V_27 . V_31 = V_20 ;
V_27 . V_32 = V_11 ;
V_27 . V_33 = V_12 ;
V_27 . V_7 = V_19 ? F_1 () : 0 ;
V_27 . V_34 = V_21 << V_35 ;
return F_11 ( & V_27 ) ;
}
unsigned long
F_12 ( struct V_18 * V_19 , const unsigned long V_36 ,
const unsigned long V_20 , const unsigned long V_21 ,
const unsigned long V_2 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 = V_3 -> V_23 ;
unsigned long V_6 = V_36 ;
struct V_26 V_27 ;
if ( V_20 > V_17 )
return - V_29 ;
if ( V_2 & V_28 )
return V_6 ;
if ( ! F_6 ( V_13 ) && ( V_2 & V_14 ) )
goto V_37;
if ( V_6 ) {
V_6 = F_9 ( V_6 ) ;
V_25 = F_10 ( V_23 , V_6 ) ;
if ( V_17 - V_20 >= V_6 &&
( ! V_25 || V_6 + V_20 <= V_25 -> V_30 ) )
return V_6 ;
}
V_27 . V_2 = V_38 ;
V_27 . V_31 = V_20 ;
V_27 . V_32 = V_39 ;
V_27 . V_33 = V_23 -> V_40 ;
V_27 . V_7 = V_19 ? F_1 () : 0 ;
V_27 . V_34 = V_21 << V_35 ;
V_6 = F_11 ( & V_27 ) ;
if ( ! ( V_6 & ~ V_41 ) )
return V_6 ;
F_13 ( V_6 != - V_29 ) ;
V_37:
return F_8 ( V_19 , V_36 , V_20 , V_21 , V_2 ) ;
}
