static void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
#ifdef F_2
F_3 ( V_2 , V_1 ) ;
#else
F_4 ( V_2 , V_1 ) ;
#endif
}
static unsigned long F_5 ( void T_1 * V_1 )
{
#ifdef F_2
return F_6 ( V_1 ) ;
#else
return F_7 ( V_1 ) ;
#endif
}
static unsigned long F_8 ( void T_1 * V_3 )
{
unsigned long V_4 ;
while ( ( V_4 = F_5 ( V_3 + V_5 ) ) &
V_6 )
F_9 ( V_7 ) ;
return V_4 ;
}
static void F_10 ( struct V_8 * V_9 ,
enum V_10 V_11 )
{
struct V_12 * V_13 =
F_11 ( V_9 , struct V_12 , V_14 ) ;
unsigned long V_15 , V_4 ;
F_12 ( V_13 -> V_16 , V_15 ) ;
F_8 ( V_13 -> V_3 ) ;
V_4 = F_5 ( V_13 -> V_3 + V_17 ) ;
if ( ( V_13 -> V_18 && V_11 == V_19 ) ||
( ! V_13 -> V_18 && V_11 != V_19 ) )
V_4 |= F_13 ( V_13 -> V_20 ) ;
else
V_4 &= ~ ( F_13 ( V_13 -> V_20 ) ) ;
F_1 ( V_13 -> V_3 + V_17 , V_4 ) ;
F_14 ( V_13 -> V_16 , V_15 ) ;
}
static int V_12 ( struct V_21 * V_22 , struct V_23 * V_24 , T_2 V_1 ,
void T_1 * V_3 , T_3 * V_16 )
{
struct V_12 * V_13 ;
const char * V_25 ;
int V_26 ;
V_13 = F_15 ( V_22 , sizeof( * V_13 ) , V_27 ) ;
if ( ! V_13 )
return - V_28 ;
V_13 -> V_20 = V_1 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_16 = V_16 ;
if ( F_16 ( V_24 , L_1 ) )
V_13 -> V_18 = true ;
V_13 -> V_14 . V_29 = F_17 ( V_24 , L_2 , NULL ) ? : V_24 -> V_29 ;
V_13 -> V_14 . V_30 = F_17 ( V_24 ,
L_3 ,
NULL ) ;
if ( ! F_18 ( V_24 , L_4 , & V_25 ) ) {
if ( ! strcmp ( V_25 , L_5 ) ) {
V_13 -> V_14 . V_31 = V_32 ;
} else if ( ! strcmp ( V_25 , L_6 ) ) {
unsigned long V_4 ;
V_4 = F_5 ( V_13 -> V_3 + V_17 ) ;
V_4 &= F_13 ( V_13 -> V_20 ) ;
if ( ( V_13 -> V_18 && ! V_4 ) ||
( ! V_13 -> V_18 && V_4 ) )
V_13 -> V_14 . V_31 = V_32 ;
else
V_13 -> V_14 . V_31 = V_19 ;
} else {
V_13 -> V_14 . V_31 = V_19 ;
}
} else {
V_13 -> V_14 . V_31 = V_19 ;
}
F_10 ( & V_13 -> V_14 , V_13 -> V_14 . V_31 ) ;
V_13 -> V_14 . V_33 = F_10 ;
V_26 = F_19 ( V_22 , & V_13 -> V_14 ) ;
if ( V_26 < 0 )
return V_26 ;
F_20 ( V_22 , L_7 , V_13 -> V_14 . V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_34 * V_35 )
{
struct V_21 * V_22 = & V_35 -> V_22 ;
struct V_23 * V_36 = V_35 -> V_22 . V_37 ;
struct V_23 * V_38 ;
struct V_39 * V_40 ;
void T_1 * V_3 ;
T_3 * V_16 ;
unsigned long V_4 ;
T_2 V_41 ;
V_40 = F_22 ( V_35 , V_42 , 0 ) ;
if ( ! V_40 )
return - V_43 ;
V_3 = F_23 ( V_22 , V_40 ) ;
if ( F_24 ( V_3 ) )
return F_25 ( V_3 ) ;
V_16 = F_15 ( V_22 , sizeof( * V_16 ) , V_27 ) ;
if ( ! V_16 )
return - V_28 ;
F_26 ( V_16 ) ;
V_4 = F_8 ( V_3 ) ;
V_4 &= ~ ( V_44 | V_45 ) ;
if ( F_16 ( V_36 , L_8 ) )
V_4 |= V_44 ;
F_27 ( V_36 , L_9 , & V_41 ) ;
switch ( V_41 ) {
case 8 :
V_4 |= V_46 ;
break;
case 4 :
V_4 |= V_47 ;
break;
case 2 :
V_4 |= V_48 ;
break;
default:
V_4 |= V_49 ;
break;
}
F_1 ( V_3 + V_5 , V_4 ) ;
F_28 (np, child) {
int V_26 ;
T_2 V_1 ;
if ( F_27 ( V_38 , L_10 , & V_1 ) )
continue;
if ( V_1 >= V_50 ) {
F_29 ( V_22 , L_11 , V_1 ,
V_50 ) ;
continue;
}
V_26 = V_12 ( V_22 , V_38 , V_1 , V_3 , V_16 ) ;
if ( V_26 < 0 ) {
F_30 ( V_38 ) ;
return V_26 ;
}
}
return 0 ;
}
