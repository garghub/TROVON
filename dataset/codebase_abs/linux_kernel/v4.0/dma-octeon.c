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
struct V_15 * V_16 )
{
T_1 V_5 = F_12 ( V_7 , V_10 , V_11 , V_12 ,
V_14 , V_16 ) ;
F_13 () ;
return V_5 ;
}
static int F_14 ( struct V_6 * V_7 , struct V_17 * V_18 ,
int V_19 , enum V_13 V_14 , struct V_15 * V_16 )
{
int V_20 = F_15 ( V_7 , V_18 , V_19 , V_14 , V_16 ) ;
F_13 () ;
return V_20 ;
}
static void F_16 ( struct V_6 * V_7 ,
T_1 V_21 , T_3 V_12 , enum V_13 V_14 )
{
F_17 ( V_7 , V_21 , V_12 , V_14 ) ;
F_13 () ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_17 * V_18 , int V_22 , enum V_13 V_14 )
{
F_19 ( V_7 , V_18 , V_22 , V_14 ) ;
F_13 () ;
}
static void * F_20 ( struct V_6 * V_7 , T_3 V_12 ,
T_1 * V_21 , T_4 V_23 , struct V_15 * V_16 )
{
void * V_24 ;
if ( F_21 ( V_7 , V_12 , V_21 , & V_24 ) )
return V_24 ;
V_23 &= ~ ( V_25 | V_26 | V_27 ) ;
#ifdef F_22
if ( V_7 == NULL )
V_23 |= V_25 ;
else if ( V_7 -> V_28 <= F_23 ( 24 ) )
V_23 |= V_25 ;
else
#endif
#ifdef F_24
if ( V_7 -> V_28 <= F_23 ( 32 ) )
V_23 |= V_26 ;
else
#endif
;
V_23 |= V_29 ;
V_24 = F_25 ( V_7 , V_12 , V_21 , V_23 ) ;
F_13 () ;
return V_24 ;
}
static void F_26 ( struct V_6 * V_7 , T_3 V_12 ,
void * V_30 , T_1 V_21 , struct V_15 * V_16 )
{
int V_31 = F_27 ( V_12 ) ;
if ( F_28 ( V_7 , V_31 , V_30 ) )
return;
F_29 ( V_7 , V_12 , V_30 , V_21 ) ;
}
static T_1 F_30 ( struct V_6 * V_7 , T_2 V_1 )
{
return V_1 ;
}
static T_2 F_31 ( struct V_6 * V_7 , T_1 V_5 )
{
return V_5 ;
}
T_1 F_32 ( struct V_6 * V_7 , T_2 V_1 )
{
struct V_32 * V_33 = F_33 ( F_34 ( V_7 ) ,
struct V_32 ,
V_34 ) ;
return V_33 -> F_32 ( V_7 , V_1 ) ;
}
T_2 F_35 ( struct V_6 * V_7 , T_1 V_5 )
{
struct V_32 * V_33 = F_33 ( F_34 ( V_7 ) ,
struct V_32 ,
V_34 ) ;
return V_33 -> F_35 ( V_7 , V_5 ) ;
}
void T_5 F_36 ( void )
{
int V_35 ;
T_2 V_36 ;
T_2 V_37 ;
T_3 V_38 ;
unsigned long V_39 ;
V_36 = 0 ;
V_37 = 0 ;
for ( V_35 = 0 ; V_35 < V_40 . V_41 ; V_35 ++ ) {
struct V_42 * V_43 = & V_40 . V_44 [ V_35 ] ;
if ( V_43 -> type != V_45 && V_43 -> type != V_46 )
continue;
if ( V_43 -> V_47 > 0x410000000ull && ! F_37 () )
continue;
V_37 += V_43 -> V_12 ;
if ( V_36 < V_43 -> V_47 + V_43 -> V_12 )
V_36 = V_43 -> V_47 + V_43 -> V_12 ;
}
V_38 = V_48 ;
#ifdef F_38
if ( F_39 ( V_49 )
|| F_39 ( V_50 ) ) {
V_38 = V_37 / 4 ;
if ( V_38 > 64 * ( 1 << 20 ) )
V_38 = 64 * ( 1 << 20 ) ;
} else if ( V_36 > 0xf0000000ul ) {
V_38 = 64 * ( 1 << 20 ) ;
}
#endif
#ifdef F_40
if ( F_37 () && V_36 >= 0x100000000ul )
V_38 = 64 * ( 1 << 20 ) ;
#endif
V_39 = V_38 >> V_51 ;
V_39 = F_41 ( V_39 , V_52 ) ;
V_38 = V_39 << V_51 ;
V_53 = F_42 ( V_38 ) ;
if ( F_43 ( V_53 , V_39 , 1 ) == - V_54 )
F_44 ( L_1 ) ;
V_55 = & V_56 . V_34 ;
}
void T_5 F_45 ( void )
{
switch ( V_57 ) {
case V_58 :
V_59 . F_32 = F_5 ;
V_59 . F_35 = F_6 ;
break;
case V_60 :
V_59 . F_32 = F_3 ;
V_59 . F_35 = F_4 ;
break;
case V_61 :
V_59 . F_32 = F_7 ;
V_59 . F_35 = F_8 ;
break;
case V_62 :
V_59 . F_32 = F_9 ;
V_59 . F_35 = F_10 ;
break;
default:
F_46 () ;
}
V_63 = & V_59 . V_34 ;
}
