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
int F_15 ( unsigned int V_24 )
{
if ( ( V_24 < V_25 ) || ( V_24 > V_26 ) )
return - V_16 ;
return ( V_24 - V_25 ) ;
}
void F_16 ( void )
{
if ( F_17 ( & V_27 , NULL ) )
F_18 ( V_28 L_1 ) ;
}
static int F_19 ( struct V_29 * V_30 , void * V_31 )
{
unsigned int V_3 [] = { V_4 , V_5 , V_6 , V_7 , V_8 , V_9 } ;
unsigned int V_32 [] = { V_33 , V_34 , V_35 , V_36 } ;
unsigned long V_37 , V_38 , V_39 ;
int V_40 ;
V_37 = F_3 ( V_13 + V_17 ) ;
V_38 = F_3 ( V_13 + V_14 ) ;
V_39 = F_3 ( V_13 + V_23 ) ;
F_20 ( V_30 , L_2 ) ;
for ( V_40 = V_41 ; V_40 <= V_21 ; V_40 ++ ) {
F_20 ( V_30 , L_3 , V_40 ) ;
F_20 ( V_30 , L_4 , ( V_37 & F_7 ( V_40 ) ) ? L_5 : L_6 ) ;
if ( V_40 <= V_15 ) {
if ( V_38 & V_3 [ V_40 ] ) {
F_20 ( V_30 , L_7 , V_40 ) ;
switch ( ( V_38 & V_32 [ V_40 ] ) >> ( 4 * V_40 ) ) {
case V_42 :
F_20 ( V_30 , L_8 ) ; break;
case V_43 :
F_20 ( V_30 , L_9 ) ; break;
case V_44 :
F_20 ( V_30 , L_10 ) ; break;
case V_45 :
F_20 ( V_30 , L_11 ) ; break;
case V_46 :
F_20 ( V_30 , L_12 ) ; break;
}
} else
F_20 ( V_30 , L_13 ) ;
} else if ( V_40 <= V_12 ) {
if ( V_38 & V_3 [ V_40 ] )
F_20 ( V_30 , L_14 , V_40 - V_47 ) ;
else
F_20 ( V_30 , L_13 ) ;
} else {
F_20 ( V_30 , L_13 ) ;
}
F_20 ( V_30 , L_15 ) ;
F_20 ( V_30 , L_16 , ( V_39 & F_11 ( V_40 ) ) ? 1 : 0 ) ;
}
return 0 ;
}
static int F_21 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_22 ( V_49 , F_19 , NULL ) ;
}
static int T_1 F_23 ( void )
{
( void ) F_24 ( L_17 , V_50 | V_51 , NULL , NULL , & V_52 ) ;
return 0 ;
}
