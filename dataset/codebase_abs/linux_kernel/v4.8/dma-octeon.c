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
return F_1 ( V_1 ) ;
}
static T_2 F_6 ( struct V_6 * V_7 , T_1 V_5 )
{
return F_2 ( V_5 ) ;
}
static T_1 F_7 ( struct V_6 * V_7 , T_2 V_1 )
{
if ( V_1 >= 0x410000000ull && V_1 < 0x420000000ull )
V_1 -= 0x400000000ull ;
if ( V_1 >= 0xf0000000ull )
V_1 = V_8 + V_1 ;
return V_1 ;
}
static T_2 F_8 ( struct V_6 * V_7 , T_1 V_5 )
{
if ( V_5 >= V_8 )
V_5 -= V_8 ;
if ( V_5 >= 0x10000000ull && V_5 < 0x20000000ull )
V_5 += 0x400000000ull ;
return V_5 ;
}
static T_1 F_9 ( struct V_6 * V_7 ,
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
static T_2 F_10 ( struct V_6 * V_7 ,
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
static T_1 F_11 ( struct V_6 * V_7 , struct V_10 * V_10 ,
unsigned long V_11 , T_3 V_12 , enum V_13 V_14 ,
unsigned long V_15 )
{
T_1 V_5 = F_12 ( V_7 , V_10 , V_11 , V_12 ,
V_14 , V_15 ) ;
F_13 () ;
return V_5 ;
}
static int F_14 ( struct V_6 * V_7 , struct V_16 * V_17 ,
int V_18 , enum V_13 V_14 , unsigned long V_15 )
{
int V_19 = F_15 ( V_7 , V_17 , V_18 , V_14 , V_15 ) ;
F_13 () ;
return V_19 ;
}
static void F_16 ( struct V_6 * V_7 ,
T_1 V_20 , T_3 V_12 , enum V_13 V_14 )
{
F_17 ( V_7 , V_20 , V_12 , V_14 ) ;
F_13 () ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_16 * V_17 , int V_21 , enum V_13 V_14 )
{
F_19 ( V_7 , V_17 , V_21 , V_14 ) ;
F_13 () ;
}
static void * F_20 ( struct V_6 * V_7 , T_3 V_12 ,
T_1 * V_20 , T_4 V_22 , unsigned long V_15 )
{
void * V_23 ;
V_22 &= ~ ( V_24 | V_25 | V_26 ) ;
#ifdef F_21
if ( V_7 == NULL )
V_22 |= V_24 ;
else if ( V_7 -> V_27 <= F_22 ( 24 ) )
V_22 |= V_24 ;
else
#endif
#ifdef F_23
if ( V_7 -> V_27 <= F_22 ( 32 ) )
V_22 |= V_25 ;
else
#endif
;
V_22 |= V_28 ;
V_23 = F_24 ( V_7 , V_12 , V_20 , V_22 ) ;
F_13 () ;
return V_23 ;
}
static void F_25 ( struct V_6 * V_7 , T_3 V_12 ,
void * V_29 , T_1 V_20 , unsigned long V_15 )
{
F_26 ( V_7 , V_12 , V_29 , V_20 ) ;
}
static T_1 F_27 ( struct V_6 * V_7 , T_2 V_1 )
{
return V_1 ;
}
static T_2 F_28 ( struct V_6 * V_7 , T_1 V_5 )
{
return V_5 ;
}
T_1 F_29 ( struct V_6 * V_7 , T_2 V_1 )
{
struct V_30 * V_31 = F_30 ( F_31 ( V_7 ) ,
struct V_30 ,
V_32 ) ;
return V_31 -> F_29 ( V_7 , V_1 ) ;
}
T_2 F_32 ( struct V_6 * V_7 , T_1 V_5 )
{
struct V_30 * V_31 = F_30 ( F_31 ( V_7 ) ,
struct V_30 ,
V_32 ) ;
return V_31 -> F_32 ( V_7 , V_5 ) ;
}
void T_5 F_33 ( void )
{
int V_33 ;
T_2 V_34 ;
T_2 V_35 ;
T_3 V_36 ;
unsigned long V_37 ;
V_34 = 0 ;
V_35 = 0 ;
for ( V_33 = 0 ; V_33 < V_38 . V_39 ; V_33 ++ ) {
struct V_40 * V_41 = & V_38 . V_42 [ V_33 ] ;
if ( V_41 -> type != V_43 && V_41 -> type != V_44 )
continue;
if ( V_41 -> V_45 > 0x410000000ull && ! F_34 () )
continue;
V_35 += V_41 -> V_12 ;
if ( V_34 < V_41 -> V_45 + V_41 -> V_12 )
V_34 = V_41 -> V_45 + V_41 -> V_12 ;
}
V_36 = V_46 ;
#ifdef F_35
if ( F_36 ( V_47 )
|| F_36 ( V_48 ) ) {
V_36 = V_35 / 4 ;
if ( V_36 > 64 * ( 1 << 20 ) )
V_36 = 64 * ( 1 << 20 ) ;
} else if ( V_34 > 0xf0000000ul ) {
V_36 = 64 * ( 1 << 20 ) ;
}
#endif
#ifdef F_37
if ( F_34 () && V_34 >= 0x100000000ul )
V_36 = 64 * ( 1 << 20 ) ;
#endif
V_37 = V_36 >> V_49 ;
V_37 = F_38 ( V_37 , V_50 ) ;
V_36 = V_37 << V_49 ;
V_51 = F_39 ( V_36 ) ;
if ( F_40 ( V_51 , V_37 , 1 ) == - V_52 )
F_41 ( L_1 ) ;
V_53 = & V_54 . V_32 ;
}
void T_5 F_42 ( void )
{
switch ( V_55 ) {
case V_56 :
V_57 . F_29 = F_5 ;
V_57 . F_32 = F_6 ;
break;
case V_58 :
V_57 . F_29 = F_3 ;
V_57 . F_32 = F_4 ;
break;
case V_59 :
V_57 . F_29 = F_7 ;
V_57 . F_32 = F_8 ;
break;
case V_60 :
V_57 . F_29 = F_9 ;
V_57 . F_32 = F_10 ;
break;
default:
F_43 () ;
}
V_61 = & V_57 . V_32 ;
}
