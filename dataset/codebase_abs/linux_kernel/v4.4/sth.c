static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 , unsigned int V_4 , unsigned int V_5 )
{
struct V_1 T_1 * V_6 = V_3 -> V_7 ;
return & V_6 [ ( V_4 - V_3 -> V_8 . V_9 ) * V_3 -> V_8 . V_10 +
V_5 ] ;
}
static void F_2 ( void T_1 * V_11 , const unsigned char * V_12 ,
unsigned int V_13 )
{
switch ( V_13 ) {
#ifdef F_3
case 8 :
F_4 ( * ( V_14 * ) V_12 , V_11 ) ;
break;
#endif
case 4 :
F_5 ( * ( V_15 * ) V_12 , V_11 ) ;
break;
case 2 :
F_6 ( * ( V_16 * ) V_12 , V_11 ) ;
break;
case 1 :
F_7 ( * ( V_17 * ) V_12 , V_11 ) ;
break;
default:
break;
}
}
static T_2 F_8 ( struct V_18 * V_18 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_19 ,
unsigned int V_20 , unsigned int V_13 ,
const unsigned char * V_12 )
{
struct V_2 * V_3 = F_9 ( V_18 , struct V_2 , V_8 ) ;
struct V_1 T_1 * V_21 =
F_1 ( V_3 , V_4 , V_5 ) ;
V_14 T_1 * V_22 = & V_21 -> V_23 ;
unsigned long V_24 = V_25 ;
#ifndef F_3
if ( V_13 > 4 )
V_13 = 4 ;
#endif
V_13 = F_10 ( V_13 ) ;
switch ( V_19 ) {
case V_26 :
V_24 += 4 ;
case V_27 :
V_24 += 8 ;
case V_28 :
if ( V_20 & V_29 )
V_24 += 4 ;
F_11 ( * V_12 , V_3 -> V_30 + V_24 ) ;
break;
case V_31 :
F_2 ( & V_21 -> V_32 , V_12 , V_13 ) ;
break;
case V_33 :
if ( V_20 & V_29 )
V_22 = ( V_14 T_1 * ) & V_21 -> V_34 ;
else
V_22 = ( V_14 T_1 * ) & V_21 -> V_35 ;
V_13 = 1 ;
F_2 ( V_22 , V_12 , V_13 ) ;
break;
case V_36 :
if ( V_20 & V_29 )
V_22 = & V_21 -> V_37 ;
else
V_22 = & V_21 -> V_38 ;
F_2 ( V_22 , V_12 , V_13 ) ;
break;
case V_39 :
V_22 = & V_21 -> V_23 ;
if ( V_20 & V_29 )
V_22 += 2 ;
if ( V_20 & V_40 )
V_22 ++ ;
F_2 ( V_22 , V_12 , V_13 ) ;
break;
}
return V_13 ;
}
static T_3
F_12 ( struct V_18 * V_18 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_41 )
{
struct V_2 * V_3 = F_9 ( V_18 , struct V_2 , V_8 ) ;
T_3 V_42 ;
V_4 -= V_3 -> V_8 . V_9 ;
V_42 = V_3 -> V_43 + ( V_4 * V_3 -> V_8 . V_10 + V_5 ) *
sizeof( struct V_1 ) ;
if ( F_13 ( V_42 ) ||
F_13 ( V_41 * sizeof( struct V_1 ) ) )
return 0 ;
return V_42 ;
}
static int F_14 ( struct V_18 * V_18 , unsigned int V_4 ,
unsigned int V_5 )
{
struct V_2 * V_3 = F_9 ( V_18 , struct V_2 , V_8 ) ;
F_15 ( F_16 ( V_3 -> V_44 ) , V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
V_15 V_24 ;
V_24 = F_18 ( V_3 -> V_30 + V_45 ) ;
V_3 -> V_8 . V_10 = V_24 & 0xff ;
V_24 = F_18 ( V_3 -> V_30 + V_46 ) ;
V_3 -> V_8 . V_9 = V_24 & 0xffff ;
V_3 -> V_8 . V_47 = V_24 >> 16 ;
V_3 -> V_48 = V_3 -> V_8 . V_47 - V_3 -> V_8 . V_9 ;
F_19 ( V_3 -> V_44 , L_1 ,
V_3 -> V_8 . V_9 , V_3 -> V_8 . V_47 , V_3 -> V_48 ,
V_3 -> V_8 . V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_49 * V_50 )
{
struct V_51 * V_44 = & V_50 -> V_44 ;
struct V_2 * V_3 ;
struct V_52 * V_53 ;
void T_1 * V_30 , * V_7 ;
int V_54 ;
V_53 = F_21 ( V_50 , V_55 , 0 ) ;
if ( ! V_53 )
return - V_56 ;
V_30 = F_22 ( V_44 , V_53 -> V_57 , F_23 ( V_53 ) ) ;
if ( ! V_30 )
return - V_58 ;
V_53 = F_21 ( V_50 , V_55 , 1 ) ;
if ( ! V_53 )
return - V_56 ;
V_7 = F_22 ( V_44 , V_53 -> V_57 , F_23 ( V_53 ) ) ;
if ( ! V_7 )
return - V_58 ;
V_3 = F_24 ( V_44 , sizeof( * V_3 ) , V_59 ) ;
if ( ! V_3 )
return - V_58 ;
V_3 -> V_44 = V_44 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_43 = V_53 -> V_57 ;
V_3 -> V_8 . V_60 = F_25 ( V_44 ) ;
V_3 -> V_8 . V_19 = F_8 ;
V_3 -> V_8 . V_61 = F_12 ;
V_3 -> V_8 . V_62 = sizeof( struct V_1 ) ;
V_3 -> V_8 . V_63 = F_14 ;
V_54 = F_17 ( V_3 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_26 ( V_44 , & V_3 -> V_8 , V_64 ) ;
if ( V_54 ) {
F_27 ( V_44 , L_2 ) ;
return V_54 ;
}
F_28 ( V_44 , V_3 ) ;
return 0 ;
}
static void F_29 ( struct V_49 * V_50 )
{
struct V_2 * V_3 = F_30 ( & V_50 -> V_44 ) ;
F_31 ( & V_3 -> V_8 ) ;
}
