static void F_1 ( unsigned int V_1 , short V_2 )
{
unsigned int V_3 [] = { V_4 , V_5 , V_6 , V_7 , V_8 , V_9 } ;
unsigned long V_10 , V_11 ;
if ( V_1 > V_12 )
return;
F_2 ( V_11 ) ;
V_10 = F_3 ( V_13 + V_14 ) ;
if ( V_2 )
V_10 &= ~ V_3 [ V_1 ] ;
else
V_10 |= V_3 [ V_1 ] ;
F_4 ( V_10 , V_13 + V_14 ) ;
F_5 ( V_11 ) ;
}
int F_6 ( unsigned int V_1 , unsigned int type )
{
unsigned long V_10 , V_11 ;
if ( V_1 > V_15 )
return - V_16 ;
F_2 ( V_11 ) ;
V_10 = F_3 ( V_13 + V_17 ) ;
V_10 &= ~ F_7 ( V_1 ) ;
F_4 ( V_10 , V_13 + V_17 ) ;
F_5 ( V_11 ) ;
F_8 ( V_18 [ V_1 ] , type ) ;
F_1 ( V_1 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 , unsigned int V_1 )
{
unsigned long V_10 , V_11 ;
if ( V_1 > V_21 )
return - V_16 ;
F_1 ( V_1 , 1 ) ;
F_2 ( V_11 ) ;
V_10 = F_3 ( V_13 + V_17 ) ;
V_10 &= ~ F_7 ( V_1 ) ;
F_4 ( V_10 , V_13 + V_17 ) ;
F_5 ( V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 ,
unsigned int V_1 , int V_22 )
{
unsigned long V_10 , V_11 ;
if ( V_1 > V_21 )
return - V_16 ;
F_1 ( V_1 , 1 ) ;
F_2 ( V_11 ) ;
V_10 = F_3 ( V_13 + V_23 ) ;
if ( V_22 )
V_10 |= F_11 ( V_1 ) ;
else
V_10 &= ~ F_11 ( V_1 ) ;
F_4 ( V_10 , V_13 + V_23 ) ;
V_10 = F_3 ( V_13 + V_17 ) ;
V_10 |= F_7 ( V_1 ) ;
F_4 ( V_10 , V_13 + V_17 ) ;
F_5 ( V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_19 * V_20 ,
unsigned int V_1 , int V_22 )
{
unsigned long V_10 , V_11 ;
if ( V_1 > V_21 )
return;
F_2 ( V_11 ) ;
V_10 = F_3 ( V_13 + V_23 ) ;
if ( V_22 )
V_10 |= F_11 ( V_1 ) ;
else
V_10 &= ~ F_11 ( V_1 ) ;
F_4 ( V_10 , V_13 + V_23 ) ;
F_5 ( V_11 ) ;
}
static int F_13 ( struct V_19 * V_20 , unsigned int V_1 )
{
unsigned long V_10 ;
if ( V_1 > V_21 )
return - V_16 ;
V_10 = F_3 ( V_13 + V_23 ) ;
return ( V_10 & F_11 ( V_1 ) ) != 0 ;
}
static int F_14 ( struct V_19 * V_20 , unsigned int V_1 )
{
if ( V_1 > V_15 )
return - V_16 ;
return V_18 [ V_1 ] ;
}
void F_15 ( void )
{
if ( F_16 ( & V_24 , NULL ) )
F_17 ( V_25 L_1 ) ;
}
static int F_18 ( struct V_26 * V_27 , void * V_28 )
{
unsigned int V_3 [] = { V_4 , V_5 , V_6 , V_7 , V_8 , V_9 } ;
unsigned int V_29 [] = { V_30 , V_31 , V_32 , V_33 } ;
unsigned long V_34 , V_35 , V_36 ;
int V_37 ;
V_34 = F_3 ( V_13 + V_17 ) ;
V_35 = F_3 ( V_13 + V_14 ) ;
V_36 = F_3 ( V_13 + V_23 ) ;
F_19 ( V_27 , L_2 ) ;
for ( V_37 = V_38 ; V_37 <= V_21 ; V_37 ++ ) {
F_19 ( V_27 , L_3 , V_37 ) ;
F_19 ( V_27 , L_4 , ( V_34 & F_7 ( V_37 ) ) ? L_5 : L_6 ) ;
if ( V_37 <= V_15 ) {
if ( V_35 & V_3 [ V_37 ] ) {
F_19 ( V_27 , L_7 , V_37 ) ;
switch ( ( V_35 & V_29 [ V_37 ] ) >> ( 4 * V_37 ) ) {
case V_39 :
F_19 ( V_27 , L_8 ) ; break;
case V_40 :
F_19 ( V_27 , L_9 ) ; break;
case V_41 :
F_19 ( V_27 , L_10 ) ; break;
case V_42 :
F_19 ( V_27 , L_11 ) ; break;
case V_43 :
F_19 ( V_27 , L_12 ) ; break;
}
} else
F_19 ( V_27 , L_13 ) ;
} else if ( V_37 <= V_12 ) {
if ( V_35 & V_3 [ V_37 ] )
F_19 ( V_27 , L_14 , V_37 - V_44 ) ;
else
F_19 ( V_27 , L_13 ) ;
} else {
F_19 ( V_27 , L_13 ) ;
}
F_19 ( V_27 , L_15 ) ;
F_19 ( V_27 , L_16 , ( V_36 & F_11 ( V_37 ) ) ? 1 : 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_21 ( V_46 , F_18 , NULL ) ;
}
static int T_1 F_22 ( void )
{
( void ) F_23 ( L_17 , V_47 | V_48 , NULL , NULL , & V_49 ) ;
return 0 ;
}
