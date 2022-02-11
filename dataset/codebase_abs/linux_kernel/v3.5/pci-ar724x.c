static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
unsigned long V_7 ;
void T_2 * V_8 ;
T_3 V_9 ;
if ( V_3 )
return V_10 ;
V_8 = V_11 ;
F_2 ( & V_12 , V_7 ) ;
V_9 = F_3 ( V_8 + ( V_4 & ~ 3 ) ) ;
switch ( V_5 ) {
case 1 :
if ( V_4 & 1 )
V_9 >>= 8 ;
if ( V_4 & 2 )
V_9 >>= 16 ;
V_9 &= 0xff ;
break;
case 2 :
if ( V_4 & 2 )
V_9 >>= 16 ;
V_9 &= 0xffff ;
break;
case 4 :
break;
default:
F_4 ( & V_12 , V_7 ) ;
return V_13 ;
}
F_4 ( & V_12 , V_7 ) ;
if ( V_4 == V_14 && V_5 == 4 &&
V_15 ) {
* V_6 = V_16 ;
} else {
* V_6 = V_9 ;
}
return V_17 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 V_6 )
{
unsigned long V_7 ;
void T_2 * V_8 ;
T_3 V_9 ;
int V_18 ;
if ( V_3 )
return V_10 ;
if ( F_6 () && V_4 == V_14 && V_5 == 4 ) {
if ( V_6 != 0xffffffff ) {
V_15 = true ;
V_16 = V_6 ;
V_6 = V_19 ;
} else {
V_15 = false ;
}
}
V_8 = V_11 ;
F_2 ( & V_12 , V_7 ) ;
V_9 = F_3 ( V_8 + ( V_4 & ~ 3 ) ) ;
switch ( V_5 ) {
case 1 :
V_18 = ( ( V_4 & 3 ) * 8 ) ;
V_9 &= ~ ( 0xff << V_18 ) ;
V_9 |= ( ( V_6 & 0xff ) << V_18 ) ;
break;
case 2 :
V_18 = ( ( V_4 & 2 ) * 8 ) ;
V_9 &= ~ ( 0xffff << V_18 ) ;
V_9 |= ( ( V_6 & 0xffff ) << V_18 ) ;
break;
case 4 :
V_9 = V_6 ;
break;
default:
F_4 ( & V_12 , V_7 ) ;
return V_13 ;
}
F_7 ( V_9 , V_8 + ( V_4 & ~ 3 ) ) ;
F_3 ( V_8 + ( V_4 & ~ 3 ) ) ;
F_4 ( & V_12 , V_7 ) ;
return V_17 ;
}
static void F_8 ( unsigned int V_20 , struct V_21 * V_22 )
{
void T_2 * V_8 ;
T_3 V_23 ;
V_8 = V_24 ;
V_23 = F_3 ( V_8 + V_25 ) &
F_3 ( V_8 + V_26 ) ;
if ( V_23 & V_27 )
F_9 ( F_10 ( 0 ) ) ;
else
F_11 () ;
}
static void F_12 ( struct V_28 * V_29 )
{
void T_2 * V_8 ;
T_3 V_30 ;
V_8 = V_24 ;
switch ( V_29 -> V_20 ) {
case F_10 ( 0 ) :
V_30 = F_3 ( V_8 + V_26 ) ;
F_7 ( V_30 | V_27 ,
V_8 + V_26 ) ;
F_3 ( V_8 + V_26 ) ;
}
}
static void F_13 ( struct V_28 * V_29 )
{
void T_2 * V_8 ;
T_3 V_30 ;
V_8 = V_24 ;
switch ( V_29 -> V_20 ) {
case F_10 ( 0 ) :
V_30 = F_3 ( V_8 + V_26 ) ;
F_7 ( V_30 & ~ V_27 ,
V_8 + V_26 ) ;
F_3 ( V_8 + V_26 ) ;
V_30 = F_3 ( V_8 + V_25 ) ;
F_7 ( V_30 | V_27 ,
V_8 + V_25 ) ;
F_3 ( V_8 + V_25 ) ;
}
}
static void T_4 F_14 ( int V_20 )
{
void T_2 * V_8 ;
int V_31 ;
V_8 = V_24 ;
F_7 ( 0 , V_8 + V_26 ) ;
F_7 ( 0 , V_8 + V_25 ) ;
F_15 ( V_32 < V_33 ) ;
for ( V_31 = V_34 ;
V_31 < V_34 + V_33 ; V_31 ++ )
F_16 ( V_31 , & V_35 ,
V_36 ) ;
F_17 ( V_20 , F_8 ) ;
}
int T_4 F_18 ( int V_20 )
{
int V_37 ;
V_37 = - V_38 ;
V_11 = F_19 ( V_39 ,
V_40 ) ;
if ( V_11 == NULL )
goto V_41;
V_24 = F_19 ( V_42 ,
V_43 ) ;
if ( V_24 == NULL )
goto V_44;
F_14 ( V_20 ) ;
F_20 ( & V_45 ) ;
return V_17 ;
V_44:
F_21 ( V_11 ) ;
V_41:
return V_37 ;
}
