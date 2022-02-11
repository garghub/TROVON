static inline int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
long V_3 = V_1 - V_2 ;
return ( V_3 >= - 1000 && V_3 <= 1000 ) ;
}
int F_2 ( struct V_4 * V_5 )
{
unsigned int V_6 , V_7 ;
unsigned long V_8 , V_9 , V_10 ;
unsigned long V_11 ;
V_9 = V_5 -> V_12 . V_9 ;
V_10 = V_5 -> V_12 . V_10 ;
V_11 = V_5 -> V_13 . V_8 ;
F_3 ( L_1 ,
V_14 , V_9 , V_10 , V_11 ) ;
if ( V_10 > V_9 ) {
F_4 ( V_15 L_2 , V_14 ) ;
V_10 = V_9 ;
}
if ( V_10 < V_9 && V_10 < V_11 )
V_11 = V_10 ;
for ( V_6 = 1 ; V_6 < 9 ; V_6 ++ ) {
if ( V_6 == 5 || V_6 == 7 )
V_6 ++ ;
V_8 = ( V_9 / V_6 ) ;
if ( V_8 <= V_11 || F_1 ( V_8 , V_11 ) )
break;
}
F_3 ( L_3 , V_14 , V_8 , V_6 ) ;
if ( V_6 > 8 )
goto V_16;
V_7 = ( V_8 > V_5 -> V_13 . V_17 ) ? 2 : 1 ;
if ( ( V_8 / V_7 ) > V_5 -> V_13 . V_17 )
V_7 ++ ;
F_3 ( L_4 , V_14 , V_7 ) ;
if ( V_7 > 2 )
goto V_16;
V_7 *= V_6 ;
if ( V_10 < V_8 )
V_10 = V_8 ;
if ( V_10 < V_9 ) {
V_5 -> V_18 . V_19 = 1 ;
V_10 = V_8 ;
} else
V_5 -> V_18 . V_19 = 0 ;
V_5 -> V_12 . V_10 = V_10 ;
V_5 -> V_18 . V_20 = V_6 ;
V_5 -> V_18 . V_21 = V_7 ;
return 0 ;
V_16:
return - V_22 ;
}
static void F_5 ( struct V_4 * V_5 )
{
unsigned long V_23 , V_24 ;
F_3 ( L_5 , V_14 ,
V_5 -> V_18 . V_20 , V_5 -> V_18 . V_21 ) ;
V_23 = F_6 ( V_25 ) ;
V_24 = F_6 ( V_26 ) ;
V_23 &= ~ ( V_27 | V_28 ) ;
V_24 &= ~ V_29 ;
switch ( V_5 -> V_18 . V_20 ) {
case 1 :
V_23 |= V_30 ;
break;
case 2 :
V_23 |= V_31 ;
break;
case 6 :
V_24 |= V_32 ;
case 3 :
V_23 |= V_33 ;
break;
case 8 :
V_24 |= V_34 ;
case 4 :
V_23 |= V_35 ;
break;
default:
F_7 () ;
}
if ( V_5 -> V_18 . V_21 != V_5 -> V_18 . V_20 )
V_23 |= V_28 ;
F_8 ( V_24 | V_29 , V_26 ) ;
F_8 ( V_23 , V_25 ) ;
F_9 ( 20 ) ;
F_8 ( V_24 , V_26 ) ;
F_10 ( V_10 , V_5 -> V_18 . V_19 ? V_8 : V_9 ) ;
}
static int F_11 ( unsigned long V_36 , unsigned long V_9 ,
int * V_18 ,
struct V_37 * V_38 ,
T_1 V_39 )
{
unsigned long V_12 ;
int V_40 = 0 ;
int div ;
for ( div = * V_18 ; div > 0 ; div = * V_18 ++ ) {
V_12 = V_9 / div ;
if ( V_12 > V_36 && div != 1 )
continue;
V_12 /= 1000 ;
V_40 = F_12 ( V_38 , V_40 , V_39 , V_12 ) ;
if ( V_40 < 0 )
break;
}
return V_40 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_37 * V_38 ,
T_1 V_39 )
{
int V_41 ;
F_14 ( V_5 -> V_42 == NULL ) ;
F_14 ( V_5 -> V_43 == NULL ) ;
V_41 = F_11 ( V_5 -> V_42 -> V_13 . V_8 ,
V_5 -> V_42 -> V_13 . V_9 ,
V_44 ,
V_38 , V_39 ) ;
F_3 ( L_6 , V_14 , V_41 ) ;
return V_41 ;
}
static int F_15 ( struct V_45 * V_46 )
{
V_47 = F_16 ( NULL , L_7 ) ;
V_8 = F_16 ( NULL , L_8 ) ;
V_9 = F_16 ( NULL , L_9 ) ;
V_10 = F_16 ( NULL , L_10 ) ;
if ( F_17 ( V_47 ) || F_17 ( V_8 ) || F_17 ( V_9 ) || F_17 ( V_10 ) ) {
F_4 ( V_48 L_11 , V_14 ) ;
return - V_49 ;
}
return F_18 ( & V_50 ) ;
}
static int F_19 ( void )
{
return F_20 ( & V_51 ,
& V_52 ) ;
}
static int F_21 ( void )
{
return F_20 ( & V_53 ,
& V_54 ) ;
}
