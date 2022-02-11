static void F_1 ( T_1 V_1 , T_2 V_2 )
{
if ( F_2 ( F_3 ( V_3 ) ,
L_1 ) )
return;
F_4 ( V_2 , V_3 + V_1 ) ;
F_5 () ;
F_6 ( V_3 + V_1 ) ;
}
T_2 F_7 ( unsigned int V_4 )
{
T_1 V_1 = V_5 [ V_4 ] ;
if ( F_2 ( F_3 ( V_3 ) ,
L_1 ) )
return 0 ;
return F_8 ( V_3 + V_1 ) ;
}
void F_9 ( unsigned int V_4 , T_2 V_2 )
{
return F_1 ( V_5 [ V_4 ] , V_2 ) ;
}
void F_10 ( unsigned int V_4 , T_2 V_2 )
{
return F_1 ( V_6 [ V_4 ] , V_2 ) ;
}
void F_11 ( unsigned int V_4 )
{
unsigned int V_7 ;
int V_8 ;
V_7 = F_7 ( V_4 ) ;
switch ( F_12 () ) {
case V_9 :
V_7 &= ~ V_10 ;
V_7 &= ~ V_11 ;
V_7 |= V_12 << V_4 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_7 &= ~ V_16 ;
V_7 &= ~ V_17 ;
V_7 |= V_18 << V_4 ;
break;
}
V_7 |= V_19 ;
V_7 |= V_20 ;
V_7 |= V_21 ;
F_9 ( V_4 , V_7 ) ;
for ( V_8 = 0 ; V_8 < F_13 () ; V_8 ++ ) {
if ( V_8 == V_4 )
continue;
V_7 = F_7 ( V_8 ) ;
V_7 |= V_20 ;
V_7 |= V_19 ;
F_9 ( V_8 , V_7 ) ;
}
}
void F_14 ( unsigned int V_4 )
{
unsigned int V_7 ;
V_7 = F_7 ( V_4 ) ;
switch ( F_12 () ) {
case V_9 :
V_7 &= ~ V_10 ;
V_7 &= ~ V_11 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_7 &= ~ V_16 ;
V_7 &= ~ V_17 ;
break;
}
V_7 &= ~ V_21 ;
V_7 |= V_19 ;
V_7 |= V_20 ;
F_9 ( V_4 , V_7 ) ;
}
static int F_15 ( struct V_22 * V_23 )
{
void T_3 * V_24 = V_3 ;
struct V_25 * V_26 ;
V_26 = F_16 ( V_23 , V_27 , 0 ) ;
V_3 = F_17 ( & V_23 -> V_28 , V_26 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_24 ) ;
F_20 ( V_24 ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
struct V_25 V_26 ;
struct V_29 * V_30 ;
if ( ! F_22 () )
return 0 ;
V_30 = F_23 ( NULL , V_31 ) ;
if ( V_30 ) {
if ( F_24 ( V_30 , 0 , & V_26 ) < 0 ) {
F_25 ( L_2 ) ;
return - V_32 ;
}
F_26 ( V_30 ) ;
} else if ( F_27 ( V_33 ) ) {
V_26 . V_34 = 0x60007000 ;
V_26 . V_35 = 0x60007fff ;
V_26 . V_36 = V_27 ;
} else {
return 0 ;
}
V_3 = F_28 ( V_26 . V_34 , F_29 ( & V_26 ) ) ;
if ( ! V_3 )
return - V_32 ;
return 0 ;
}
