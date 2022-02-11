static inline bool F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
return V_1 & V_4 ;
}
static int F_3 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 ,
int V_9 , T_2 * V_10 )
{
unsigned long V_11 ;
void T_3 * V_12 ;
T_1 V_13 ;
if ( ! V_14 )
return V_15 ;
if ( V_7 )
return V_15 ;
V_12 = V_16 ;
F_4 ( & V_17 , V_11 ) ;
V_13 = F_2 ( V_12 + ( V_8 & ~ 3 ) ) ;
switch ( V_9 ) {
case 1 :
if ( V_8 & 1 )
V_13 >>= 8 ;
if ( V_8 & 2 )
V_13 >>= 16 ;
V_13 &= 0xff ;
break;
case 2 :
if ( V_8 & 2 )
V_13 >>= 16 ;
V_13 &= 0xffff ;
break;
case 4 :
break;
default:
F_5 ( & V_17 , V_11 ) ;
return V_18 ;
}
F_5 ( & V_17 , V_11 ) ;
if ( V_8 == V_19 && V_9 == 4 &&
V_20 ) {
* V_10 = V_21 ;
} else {
* V_10 = V_13 ;
}
return V_22 ;
}
static int F_6 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 ,
int V_9 , T_2 V_10 )
{
unsigned long V_11 ;
void T_3 * V_12 ;
T_1 V_13 ;
int V_23 ;
if ( ! V_14 )
return V_15 ;
if ( V_7 )
return V_15 ;
if ( F_7 () && V_8 == V_19 && V_9 == 4 ) {
if ( V_10 != 0xffffffff ) {
V_20 = true ;
V_21 = V_10 ;
V_10 = V_24 ;
} else {
V_20 = false ;
}
}
V_12 = V_16 ;
F_4 ( & V_17 , V_11 ) ;
V_13 = F_2 ( V_12 + ( V_8 & ~ 3 ) ) ;
switch ( V_9 ) {
case 1 :
V_23 = ( ( V_8 & 3 ) * 8 ) ;
V_13 &= ~ ( 0xff << V_23 ) ;
V_13 |= ( ( V_10 & 0xff ) << V_23 ) ;
break;
case 2 :
V_23 = ( ( V_8 & 2 ) * 8 ) ;
V_13 &= ~ ( 0xffff << V_23 ) ;
V_13 |= ( ( V_10 & 0xffff ) << V_23 ) ;
break;
case 4 :
V_13 = V_10 ;
break;
default:
F_5 ( & V_17 , V_11 ) ;
return V_18 ;
}
F_8 ( V_13 , V_12 + ( V_8 & ~ 3 ) ) ;
F_2 ( V_12 + ( V_8 & ~ 3 ) ) ;
F_5 ( & V_17 , V_11 ) ;
return V_22 ;
}
static void F_9 ( unsigned int V_25 , struct V_26 * V_27 )
{
void T_3 * V_12 ;
T_1 V_28 ;
V_12 = V_2 ;
V_28 = F_2 ( V_12 + V_29 ) &
F_2 ( V_12 + V_30 ) ;
if ( V_28 & V_31 )
F_10 ( F_11 ( 0 ) ) ;
else
F_12 () ;
}
static void F_13 ( struct V_32 * V_33 )
{
void T_3 * V_12 ;
T_1 V_34 ;
V_12 = V_2 ;
switch ( V_33 -> V_25 ) {
case F_11 ( 0 ) :
V_34 = F_2 ( V_12 + V_30 ) ;
F_8 ( V_34 | V_31 ,
V_12 + V_30 ) ;
F_2 ( V_12 + V_30 ) ;
}
}
static void F_14 ( struct V_32 * V_33 )
{
void T_3 * V_12 ;
T_1 V_34 ;
V_12 = V_2 ;
switch ( V_33 -> V_25 ) {
case F_11 ( 0 ) :
V_34 = F_2 ( V_12 + V_30 ) ;
F_8 ( V_34 & ~ V_31 ,
V_12 + V_30 ) ;
F_2 ( V_12 + V_30 ) ;
V_34 = F_2 ( V_12 + V_29 ) ;
F_8 ( V_34 | V_31 ,
V_12 + V_29 ) ;
F_2 ( V_12 + V_29 ) ;
}
}
static void T_4 F_15 ( int V_25 )
{
void T_3 * V_12 ;
int V_35 ;
V_12 = V_2 ;
F_8 ( 0 , V_12 + V_30 ) ;
F_8 ( 0 , V_12 + V_29 ) ;
F_16 ( V_36 < V_37 ) ;
for ( V_35 = V_38 ;
V_35 < V_38 + V_37 ; V_35 ++ )
F_17 ( V_35 , & V_39 ,
V_40 ) ;
F_18 ( V_25 , F_9 ) ;
}
int T_4 F_19 ( int V_25 )
{
int V_41 ;
V_41 = - V_42 ;
V_16 = F_20 ( V_43 ,
V_44 ) ;
if ( V_16 == NULL )
goto V_45;
V_2 = F_20 ( V_46 ,
V_47 ) ;
if ( V_2 == NULL )
goto V_48;
V_14 = F_1 () ;
if ( ! V_14 )
F_21 ( L_1 ) ;
F_15 ( V_25 ) ;
F_22 ( & V_49 ) ;
return V_22 ;
V_48:
F_23 ( V_16 ) ;
V_45:
return V_41 ;
}
