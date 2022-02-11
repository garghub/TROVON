static T_1 F_1 ( T_2 V_1 )
{
if ( V_1 >= V_2 && V_1 < ( V_2 + V_3 ) )
return V_1 - V_2 + V_4 ;
else
return V_1 ;
}
static T_2 F_2 ( T_1 V_5 )
{
if ( V_5 >= V_4 )
return V_5 + V_2 - V_4 ;
else
return V_5 ;
}
static T_1 F_3 ( struct V_6 * V_7 , T_2 V_1 )
{
if ( V_1 >= 0x410000000ull && V_1 < 0x420000000ull )
V_1 -= 0x400000000ull ;
return F_1 ( V_1 ) ;
}
static T_2 F_4 ( struct V_6 * V_7 , T_1 V_5 )
{
V_5 = F_2 ( V_5 ) ;
if ( V_5 >= 0x10000000ull && V_5 < 0x20000000ull )
V_5 += 0x400000000ull ;
return V_5 ;
}
static T_1 F_5 ( struct V_6 * V_7 , T_2 V_1 )
{
if ( V_1 >= 0x410000000ull && V_1 < 0x420000000ull )
V_1 -= 0x400000000ull ;
if ( V_1 >= 0xf0000000ull )
V_1 = V_8 + V_1 ;
return V_1 ;
}
static T_2 F_6 ( struct V_6 * V_7 , T_1 V_5 )
{
if ( V_5 >= V_8 )
V_5 -= V_8 ;
if ( V_5 >= 0x10000000ull && V_5 < 0x20000000ull )
V_5 += 0x400000000ull ;
return V_5 ;
}
static T_1 F_7 ( struct V_6 * V_7 ,
T_2 V_1 )
{
if ( V_1 >= 0x410000000ull && V_1 < 0x420000000ull )
V_1 -= 0x400000000ull ;
if ( V_1 >= V_9 && V_1 < V_9 + 0x8000000ull )
V_1 = V_1 - V_9 ;
else
V_1 = V_8 + V_1 ;
return V_1 ;
}
static T_2 F_8 ( struct V_6 * V_7 ,
T_1 V_5 )
{
if ( V_5 >= V_8 )
V_5 -= V_8 ;
else
V_5 += V_9 ;
if ( V_5 >= 0x10000000ull && V_5 < 0x20000000ull )
V_5 += 0x400000000ull ;
return V_5 ;
}
static T_1 F_9 ( struct V_6 * V_7 , struct V_10 * V_10 ,
unsigned long V_11 , T_3 V_12 , enum V_13 V_14 ,
struct V_15 * V_16 )
{
T_1 V_5 = F_10 ( V_7 , V_10 , V_11 , V_12 ,
V_14 , V_16 ) ;
F_11 () ;
return V_5 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_17 * V_18 ,
int V_19 , enum V_13 V_14 , struct V_15 * V_16 )
{
int V_20 = F_13 ( V_7 , V_18 , V_19 , V_14 , V_16 ) ;
F_11 () ;
return V_20 ;
}
static void F_14 ( struct V_6 * V_7 ,
T_1 V_21 , T_3 V_12 , enum V_13 V_14 )
{
F_15 ( V_7 , V_21 , V_12 , V_14 ) ;
F_11 () ;
}
static void F_16 ( struct V_6 * V_7 ,
struct V_17 * V_18 , int V_22 , enum V_13 V_14 )
{
F_17 ( V_7 , V_18 , V_22 , V_14 ) ;
F_11 () ;
}
static void * F_18 ( struct V_6 * V_7 , T_3 V_12 ,
T_1 * V_21 , T_4 V_23 )
{
void * V_24 ;
if ( F_19 ( V_7 , V_12 , V_21 , & V_24 ) )
return V_24 ;
V_23 &= ~ ( V_25 | V_26 | V_27 ) ;
#ifdef F_20
if ( V_7 == NULL )
V_23 |= V_25 ;
else if ( V_7 -> V_28 <= F_21 ( 24 ) )
V_23 |= V_25 ;
else
#endif
#ifdef F_22
if ( V_7 -> V_28 <= F_21 ( 32 ) )
V_23 |= V_26 ;
else
#endif
;
V_23 |= V_29 ;
V_24 = F_23 ( V_7 , V_12 , V_21 , V_23 ) ;
F_11 () ;
return V_24 ;
}
static void F_24 ( struct V_6 * V_7 , T_3 V_12 ,
void * V_30 , T_1 V_21 )
{
int V_31 = F_25 ( V_12 ) ;
if ( F_26 ( V_7 , V_31 , V_30 ) )
return;
F_27 ( V_7 , V_12 , V_30 , V_21 ) ;
}
static T_1 F_28 ( struct V_6 * V_7 , T_2 V_1 )
{
return V_1 ;
}
static T_2 F_29 ( struct V_6 * V_7 , T_1 V_5 )
{
return V_5 ;
}
T_1 F_30 ( struct V_6 * V_7 , T_2 V_1 )
{
struct V_32 * V_33 = F_31 ( F_32 ( V_7 ) ,
struct V_32 ,
V_34 ) ;
return V_33 -> F_30 ( V_7 , V_1 ) ;
}
T_2 F_33 ( struct V_6 * V_7 , T_1 V_5 )
{
struct V_32 * V_33 = F_31 ( F_32 ( V_7 ) ,
struct V_32 ,
V_34 ) ;
return V_33 -> F_33 ( V_7 , V_5 ) ;
}
void T_5 F_34 ( void )
{
int V_35 ;
T_6 V_36 ;
T_6 V_37 ;
T_3 V_38 ;
unsigned long V_39 ;
V_36 = 0 ;
V_37 = 0 ;
for ( V_35 = 0 ; V_35 < V_40 . V_41 ; V_35 ++ ) {
struct V_42 * V_43 = & V_40 . V_44 [ V_35 ] ;
if ( V_43 -> type != V_45 )
continue;
if ( V_43 -> V_46 > 0x410000000ull )
continue;
V_37 += V_43 -> V_12 ;
if ( V_36 < V_43 -> V_46 + V_43 -> V_12 )
V_36 = V_43 -> V_46 + V_43 -> V_12 ;
}
V_38 = V_47 ;
#ifdef F_35
if ( F_36 ( V_48 )
|| F_36 ( V_49 ) ) {
V_38 = V_37 / 4 ;
if ( V_38 > 64 * ( 1 << 20 ) )
V_38 = 64 * ( 1 << 20 ) ;
} else if ( V_36 > 0xf0000000ul ) {
V_38 = 64 * ( 1 << 20 ) ;
}
#endif
V_39 = V_38 >> V_50 ;
V_39 = F_37 ( V_39 , V_51 ) ;
V_38 = V_39 << V_50 ;
V_52 = F_38 ( V_38 ) ;
F_39 ( V_52 , V_39 , 1 ) ;
V_53 = & V_54 . V_34 ;
}
void T_5 F_40 ( void )
{
switch ( V_55 ) {
case V_56 :
V_57 . F_30 = F_3 ;
V_57 . F_33 = F_4 ;
break;
case V_58 :
V_57 . F_30 = F_5 ;
V_57 . F_33 = F_6 ;
break;
case V_59 :
V_57 . F_30 = F_7 ;
V_57 . F_33 = F_8 ;
break;
default:
F_41 () ;
}
V_60 = & V_57 . V_34 ;
}
