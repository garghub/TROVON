static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = F_2 ( V_2 ) ;
V_3 = V_6 [ V_5 ] ;
V_4 = V_7 [ V_5 ] ;
V_8 [ V_4 ] &= ~ ( 1 << V_3 ) ;
F_3 ( & V_9 -> V_10 + V_4 , V_8 [ V_4 ] ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = F_2 ( V_2 ) ;
V_3 = V_6 [ V_5 ] ;
V_4 = V_7 [ V_5 ] ;
V_8 [ V_4 ] |= 1 << V_3 ;
F_3 ( & V_9 -> V_10 + V_4 , V_8 [ V_4 ] ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = F_2 ( V_2 ) ;
V_3 = V_6 [ V_5 ] ;
V_4 = V_7 [ V_5 ] ;
F_3 ( & V_9 -> V_11 + V_4 , 1 << V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned int V_5 = F_2 ( V_2 ) ;
V_3 = V_6 [ V_5 ] ;
V_4 = V_7 [ V_5 ] ;
V_8 [ V_4 ] |= 1 << V_3 ;
F_3 ( & V_9 -> V_10 + V_4 , V_8 [ V_4 ] ) ;
F_7 () ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_12 )
{
unsigned int V_13 = F_2 ( V_2 ) ;
unsigned int V_14 , V_15 , V_16 ;
if ( V_13 >= V_17 && V_13 <= V_18 ) {
if ( V_12 == V_19 )
V_12 = V_20 ;
if ( V_12 != V_20 &&
V_12 != V_21 )
goto V_22;
} else {
if ( V_12 == V_19 )
V_12 = V_23 ;
if ( V_12 & ( V_24 | V_25 ) )
goto V_22;
}
F_9 ( V_2 , V_12 ) ;
if ( V_12 & V_23 )
F_10 ( V_2 , V_26 ) ;
else
F_10 ( V_2 , V_27 ) ;
if ( V_13 >= V_28 && V_13 <= V_29 )
V_16 = ( 14 - ( V_13 - V_28 ) ) ;
else
if ( V_13 >= V_17 && V_13 <= V_18 )
V_16 = ( 31 - ( V_18 - V_13 ) ) ;
else
return ( V_12 & V_23 ) ?
V_30 : - V_31 ;
V_14 = F_11 ( & V_9 -> V_32 ) ;
if ( ( V_12 & V_33 ) == V_21 )
V_15 = V_14 | ( 1 << V_16 ) ;
else
V_15 = V_14 & ~ ( 1 << V_16 ) ;
if ( V_14 != V_15 )
F_3 ( & V_9 -> V_32 , V_15 ) ;
return V_30 ;
V_22:
F_12 ( L_1 , V_12 ) ;
return - V_31 ;
}
unsigned int F_13 ( void )
{
int V_34 ;
unsigned long V_35 ;
V_35 = F_11 ( & V_9 -> V_36 ) ;
V_34 = V_35 >> 26 ;
if ( V_34 == 0 )
return ( - 1 ) ;
return F_14 ( V_37 , V_34 ) ;
}
static int F_15 ( struct V_38 * V_39 , unsigned int V_40 ,
T_1 V_41 )
{
F_16 ( L_2 , V_40 , V_41 ) ;
F_17 ( V_40 , V_42 ) ;
F_18 ( V_40 , & V_43 , V_26 ) ;
return 0 ;
}
void F_19 ( struct V_44 * V_45 )
{
int V_46 ;
V_9 = F_20 ( V_47 ) ;
F_3 ( & V_9 -> V_10 , 0x00000000 ) ;
F_3 ( & V_9 -> V_48 , 0x00000000 ) ;
F_21 () ;
F_3 ( & V_9 -> V_11 , 0xffffffff ) ;
F_3 ( & V_9 -> V_49 , 0xffffffff ) ;
F_21 () ;
V_46 = F_11 ( & V_9 -> V_36 ) ;
F_22 () ;
F_23 ( & V_9 -> V_50 , 0 ) ;
F_3 ( & V_9 -> V_51 , 0x05309770 ) ;
F_3 ( & V_9 -> V_52 , 0x05309770 ) ;
V_37 = F_24 ( V_45 , 64 , & V_53 , NULL ) ;
if ( V_37 == NULL ) {
F_25 ( V_54 L_3 ) ;
return;
}
}
