static T_1 F_1 ( int V_1 , int V_2 )
{
T_1 V_3 ;
V_3 = V_1 * V_2 ;
V_3 = ( V_3 + 31 ) & ~ 31 ;
V_3 >>= 3 ;
return ( V_3 ) ;
}
static int F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
T_1 V_8 ;
if ( V_5 -> V_9 & V_10 ) {
V_5 -> V_9 |= V_11 ;
V_5 -> V_12 = V_7 -> V_5 . V_12 ;
V_5 -> V_13 = V_7 -> V_5 . V_13 ;
}
if ( ! V_5 -> V_14 )
V_5 -> V_14 = 1 ;
if ( ! V_5 -> V_15 )
V_5 -> V_15 = 1 ;
if ( V_5 -> V_14 > V_5 -> V_1 )
V_5 -> V_1 = V_5 -> V_14 ;
if ( V_5 -> V_15 > V_5 -> V_16 )
V_5 -> V_16 = V_5 -> V_15 ;
if ( V_5 -> V_17 <= 1 )
V_5 -> V_17 = 1 ;
else if ( V_5 -> V_17 <= 8 )
V_5 -> V_17 = 8 ;
else if ( V_5 -> V_17 <= 16 )
V_5 -> V_17 = 16 ;
else if ( V_5 -> V_17 <= 24 )
V_5 -> V_17 = 24 ;
else if ( V_5 -> V_17 <= 32 )
V_5 -> V_17 = 32 ;
else
return - V_18 ;
if ( V_5 -> V_1 < V_5 -> V_12 + V_5 -> V_14 )
V_5 -> V_1 = V_5 -> V_12 + V_5 -> V_14 ;
if ( V_5 -> V_16 < V_5 -> V_13 + V_5 -> V_15 )
V_5 -> V_16 = V_5 -> V_13 + V_5 -> V_15 ;
V_8 =
F_1 ( V_5 -> V_1 , V_5 -> V_17 ) ;
if ( V_8 * V_5 -> V_16 > V_19 )
return - V_20 ;
switch ( V_5 -> V_17 ) {
case 1 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 1 ;
V_5 -> V_23 . V_22 = 0 ;
V_5 -> V_23 . V_3 = 1 ;
V_5 -> V_24 . V_22 = 0 ;
V_5 -> V_24 . V_3 = 1 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
break;
case 8 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 8 ;
V_5 -> V_23 . V_22 = 0 ;
V_5 -> V_23 . V_3 = 8 ;
V_5 -> V_24 . V_22 = 0 ;
V_5 -> V_24 . V_3 = 8 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
break;
case 16 :
if ( V_5 -> V_25 . V_3 ) {
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 5 ;
V_5 -> V_23 . V_22 = 5 ;
V_5 -> V_23 . V_3 = 5 ;
V_5 -> V_24 . V_22 = 10 ;
V_5 -> V_24 . V_3 = 5 ;
V_5 -> V_25 . V_22 = 15 ;
V_5 -> V_25 . V_3 = 1 ;
} else {
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 5 ;
V_5 -> V_23 . V_22 = 5 ;
V_5 -> V_23 . V_3 = 6 ;
V_5 -> V_24 . V_22 = 11 ;
V_5 -> V_24 . V_3 = 5 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
}
break;
case 24 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 8 ;
V_5 -> V_23 . V_22 = 8 ;
V_5 -> V_23 . V_3 = 8 ;
V_5 -> V_24 . V_22 = 16 ;
V_5 -> V_24 . V_3 = 8 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
break;
case 32 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 8 ;
V_5 -> V_23 . V_22 = 8 ;
V_5 -> V_23 . V_3 = 8 ;
V_5 -> V_24 . V_22 = 16 ;
V_5 -> V_24 . V_3 = 8 ;
V_5 -> V_25 . V_22 = 24 ;
V_5 -> V_25 . V_3 = 8 ;
break;
}
V_5 -> V_21 . V_26 = 0 ;
V_5 -> V_23 . V_26 = 0 ;
V_5 -> V_24 . V_26 = 0 ;
V_5 -> V_25 . V_26 = 0 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 )
{
V_7 -> V_27 . V_8 = F_1 ( V_7 -> V_5 . V_1 ,
V_7 -> V_5 . V_17 ) ;
return 0 ;
}
static int F_4 ( T_2 V_28 , T_2 V_21 , T_2 V_23 , T_2 V_24 ,
T_2 V_25 , struct V_6 * V_7 )
{
if ( V_28 >= 256 )
return 1 ;
if ( V_7 -> V_5 . V_29 ) {
V_21 = V_23 = V_24 =
( V_21 * 77 + V_23 * 151 + V_24 * 28 ) >> 8 ;
}
#define F_5 ( T_3 , T_4 ) ((((val)<<(width))+0x7FFF-(val))>>16)
switch ( V_7 -> V_27 . V_30 ) {
case V_31 :
case V_32 :
V_21 = F_5 ( V_21 , V_7 -> V_5 . V_21 . V_3 ) ;
V_23 = F_5 ( V_23 , V_7 -> V_5 . V_23 . V_3 ) ;
V_24 = F_5 ( V_24 , V_7 -> V_5 . V_24 . V_3 ) ;
V_25 = F_5 ( V_25 , V_7 -> V_5 . V_25 . V_3 ) ;
break;
case V_33 :
V_21 = F_5 ( V_21 , 8 ) ;
V_23 = F_5 ( V_23 , 8 ) ;
V_24 = F_5 ( V_24 , 8 ) ;
V_25 = F_5 ( V_25 , 8 ) ;
break;
}
#undef F_5
if ( V_7 -> V_27 . V_30 == V_31 ) {
T_5 V_34 ;
if ( V_28 >= 16 )
return 1 ;
V_34 = ( V_21 << V_7 -> V_5 . V_21 . V_22 ) |
( V_23 << V_7 -> V_5 . V_23 . V_22 ) |
( V_24 << V_7 -> V_5 . V_24 . V_22 ) |
( V_25 << V_7 -> V_5 . V_25 . V_22 ) ;
switch ( V_7 -> V_5 . V_17 ) {
case 8 :
break;
case 16 :
( ( T_5 * ) ( V_7 -> V_35 ) ) [ V_28 ] = V_34 ;
break;
case 24 :
case 32 :
( ( T_5 * ) ( V_7 -> V_35 ) ) [ V_28 ] = V_34 ;
break;
}
return 0 ;
}
return 0 ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( V_5 -> V_9 & V_11 ) {
if ( V_5 -> V_13 < 0
|| V_5 -> V_13 >= V_7 -> V_5 . V_16
|| V_5 -> V_12 )
return - V_18 ;
} else {
if ( V_5 -> V_12 + V_7 -> V_5 . V_14 > V_7 -> V_5 . V_1 ||
V_5 -> V_13 + V_7 -> V_5 . V_15 > V_7 -> V_5 . V_16 )
return - V_18 ;
}
V_7 -> V_5 . V_12 = V_5 -> V_12 ;
V_7 -> V_5 . V_13 = V_5 -> V_13 ;
if ( V_5 -> V_9 & V_11 )
V_7 -> V_5 . V_9 |= V_11 ;
else
V_7 -> V_5 . V_9 &= ~ V_11 ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_36 * V_37 )
{
#ifndef F_8
V_37 -> V_38 |= V_39 | V_40 ;
V_37 -> V_41 = V_42 ;
return 0 ;
#else
return - V_18 ;
#endif
}
int T_6 F_9 ( char * V_43 )
{
#if 0
char *this_opt;
#endif
if ( ! V_43 || ! * V_43 )
return 1 ;
#if 0
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt)
continue;
if (!strncmp(this_opt, "disable", 7))
mc68x328fb_enable = 0;
}
#endif
return 1 ;
}
int T_6 F_10 ( void )
{
#ifndef F_11
char * V_44 = NULL ;
if ( F_12 ( L_1 , & V_44 ) )
return - V_45 ;
F_9 ( V_44 ) ;
#endif
V_46 . V_14 = V_47 ;
V_46 . V_15 = V_48 + 1 ;
V_46 . V_1 = V_46 . V_14 ;
V_46 . V_16 = V_46 . V_15 ;
V_46 . V_17 = 1 + ( V_49 & 0x01 ) ;
V_42 = V_50 ;
V_19 = ( V_46 . V_1 + 7 ) / 8 *
V_46 . V_16 * V_46 . V_17 ;
V_6 . V_51 = ( void * ) V_42 ;
V_6 . V_52 = & V_53 ;
V_6 . V_5 = V_46 ;
V_6 . V_27 = V_54 ;
V_6 . V_27 . V_55 = V_42 ;
V_6 . V_27 . V_56 = V_19 ;
V_6 . V_27 . V_8 =
F_1 ( V_46 . V_1 , V_46 . V_17 ) ;
V_6 . V_27 . V_30 = ( V_46 . V_17 ) == 1 ?
V_57 : V_32 ;
if ( V_6 . V_5 . V_17 == 1 ) {
V_6 . V_5 . V_21 . V_3 = V_6 . V_5 . V_23 . V_3 = V_6 . V_5 . V_24 . V_3 = 1 ;
V_6 . V_5 . V_21 . V_22 = V_6 . V_5 . V_23 . V_22 = V_6 . V_5 . V_24 . V_22 = 0 ;
}
V_6 . V_35 = & V_58 ;
V_6 . V_59 = V_60 | V_61 ;
if ( F_13 ( & V_6 . V_62 , 256 , 0 ) )
return - V_20 ;
if ( F_14 ( & V_6 ) < 0 ) {
F_15 ( & V_6 . V_62 ) ;
return - V_18 ;
}
V_6 ( & V_6 , L_2 , V_6 . V_27 . V_63 ) ;
V_6 ( & V_6 , L_3 ,
V_46 . V_1 ,
V_46 . V_16 ,
1 << V_46 . V_17 , V_42 ) ;
return 0 ;
}
static void T_7 F_16 ( void )
{
F_17 ( & V_6 ) ;
F_15 ( & V_6 . V_62 ) ;
}
