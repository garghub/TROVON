static int F_1 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short * V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
unsigned short V_8 ;
for ( V_7 = V_9 ; V_7 ; V_7 -- ) {
* V_4 = 0 ;
for ( V_5 = V_10 ;
V_5 && ! ( F_2 ( V_11 ) & V_12 ) ;
-- V_5 )
F_3 ( 1 ) ;
for ( V_6 = V_10 ;
V_6 && ! ( F_2 ( V_11 ) & V_13 ) ;
-- V_6 )
F_3 ( 1 ) ;
if ( ! V_5 && ! V_6 )
return 0 ;
V_8 = ( ( F_2 ( V_14 ) & V_15 ) >> V_16 ) ;
* V_4 = ( ( F_2 ( V_17 ) & V_18 ) >> V_19 ) ;
F_2 ( V_11 ) &= ~ ( V_13 | V_12 ) ;
if ( V_3 == V_8 )
break;
F_3 ( 21 ) ;
}
F_2 ( V_11 ) &= ~ ( V_13 | V_12 ) ;
return V_7 ;
}
static unsigned short F_4 ( struct V_1 * V_2 ,
unsigned short V_20 )
{
unsigned short V_21 ;
unsigned int V_7 , V_22 ;
for ( V_7 = V_9 ; V_7 ; V_7 -- ) {
F_5 () ;
F_2 ( V_23 ) &= ~ ( V_24 ) ;
F_2 ( V_14 ) = ( V_20 << V_16 ) | V_25 ;
F_6 () ;
for ( V_22 = V_26 ;
V_22 && ! ( F_2 ( V_23 ) & V_24 ) ;
-- V_22 )
F_3 ( 1 ) ;
F_2 ( V_23 ) &= ~ V_24 ;
V_21 = 0 ;
if ( F_1 ( V_2 , V_20 , & V_21 ) != 0 )
break;
}
return V_7 ? V_21 : ~ 0 ;
}
static void F_7 ( struct V_27 * V_28 , unsigned short V_20 ,
unsigned short V_21 )
{
int V_29 = 0 ;
struct V_1 * V_2 = & V_30 [ V_29 ] ;
unsigned int V_7 , V_22 ;
for ( V_7 = V_31 ; V_7 ; V_7 -- ) {
F_5 () ;
F_2 ( V_23 ) &= ~ ( V_32 | V_24 ) ;
F_2 ( V_17 ) = ( V_21 << V_19 ) ;
F_2 ( V_14 ) = ( V_20 << V_16 ) & ( ~ V_25 ) ;
F_6 () ;
for ( V_22 = V_33 ;
V_22 && ! ( F_2 ( V_23 ) & ( V_24 | V_32 ) ) ;
-- V_22 )
F_3 ( 1 ) ;
F_2 ( V_23 ) &= ~ ( V_24 | V_32 ) ;
if ( V_22 )
break;
}
}
static unsigned short F_8 ( struct V_27 * V_28 ,
unsigned short V_20 )
{
int V_29 = 0 ;
struct V_1 * V_2 = & V_30 [ V_29 ] ;
return F_4 ( V_2 , V_20 ) ;
}
static void F_9 ( struct V_27 * V_28 )
{
int V_29 = 0 ;
struct V_1 * V_2 = & V_30 [ V_29 ] ;
unsigned int V_34 ;
F_2 ( V_35 ) = V_36 | V_37 | V_38 ;
F_10 ( 10 ) ;
F_2 ( V_35 ) = V_37 | V_38 ;
for ( V_34 = 1000 ; ( V_34 > 0 ) && ! ( F_2 ( V_35 ) & V_39 ) ; V_34 -- )
F_3 ( 1 ) ;
if ( ! V_34 )
F_11 ( V_40 L_1 ) ;
F_2 ( V_41 ) |= V_42 ;
}
static void F_12 ( struct V_27 * V_28 )
{
int V_29 = 0 ;
struct V_1 * V_2 ;
V_2 = & V_30 [ V_29 ] ;
F_2 ( V_35 ) = 0 ;
F_2 ( V_35 ) = V_43 | V_37 | V_38 ;
F_10 ( 10 ) ;
F_9 ( V_28 ) ;
}
static int F_13 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = & V_30 [ V_49 -> V_50 ] ;
int V_51 = V_45 -> V_52 == V_53 ? 0 : 1 ;
switch ( V_47 -> V_54 ) {
case 16 :
F_2 ( V_41 ) |= V_51 ? V_55 : V_56 ;
F_2 ( V_41 ) &= V_51 ? ~ V_57 : ~ V_58 ;
break;
case 20 :
F_2 ( V_41 ) &= V_51 ? ~ V_55 : ~ V_56 ;
F_2 ( V_41 ) |= V_51 ? V_57 : V_58 ;
break;
default:
F_14 ( L_2 , V_47 -> V_54 ) ;
return - V_59 ;
break;
}
return 0 ;
}
static int F_15 ( struct V_60 * V_61 )
{
V_62 = F_16 ( & V_63 ) ;
if ( V_62 != 0 )
return V_62 ;
return F_17 ( & V_61 -> V_64 , & V_65 ,
V_66 , F_18 ( V_66 ) ) ;
}
static int F_19 ( struct V_60 * V_61 )
{
F_20 ( & V_61 -> V_64 ) ;
F_16 ( NULL ) ;
return 0 ;
}
