static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 -> V_9 ;
void T_1 * V_11 = V_9 -> V_12 . V_11 ;
unsigned int V_13 = V_4 >> 1 ;
struct V_14 * V_15 = V_2 -> V_16 ;
bool V_17 = 1 ;
if ( V_7 -> V_18 == V_19 && V_15 && V_15 -> V_20 &&
! F_2 ( V_15 -> V_20 ) )
V_17 = 0 ;
if ( V_5 == V_21 ) {
if ( V_17 )
F_3 ( ( V_22 * ) V_11 , ( V_22 * ) V_3 , V_13 ) ;
else
F_4 ( ( V_22 * ) V_11 , ( V_22 * ) V_3 , V_13 ) ;
} else {
if ( V_17 )
F_5 ( ( V_22 * ) V_11 , ( V_22 * ) V_3 , V_13 ) ;
else
F_6 ( ( V_22 * ) V_11 , ( V_22 * ) V_3 , V_13 ) ;
}
if ( F_7 ( V_4 & 0x01 ) ) {
unsigned char V_23 [ 2 ] = { } ;
V_3 += V_4 - 1 ;
if ( V_5 == V_21 ) {
if ( V_17 )
F_3 ( ( V_22 * ) V_11 , ( V_22 * ) V_23 , 1 ) ;
else
F_4 ( ( V_22 * ) V_11 , ( V_22 * ) V_23 , 1 ) ;
* V_3 = V_23 [ 0 ] ;
} else {
V_23 [ 0 ] = * V_3 ;
if ( V_17 )
F_5 ( ( V_22 * ) V_11 , ( V_22 * ) V_23 , 1 ) ;
else
F_6 ( ( V_22 * ) V_11 , ( V_22 * ) V_23 , 1 ) ;
}
V_13 ++ ;
}
return V_13 << 1 ;
}
static int F_8 ( struct V_24 * V_10 ,
struct V_6 * * V_25 )
{
struct V_6 * V_7 ;
F_9 (dev, link, ENABLED) {
V_7 -> V_26 = V_7 -> V_27 = V_28 ;
V_7 -> V_29 = V_30 ;
V_7 -> V_31 |= V_32 ;
F_10 ( V_7 , L_1 ) ;
}
return 0 ;
}
static int F_11 ( void )
{
struct V_33 * V_34 ;
struct V_8 * V_9 ;
struct V_35 * V_36 ;
void T_1 * V_37 ;
if ( ! V_38 || ! F_12 ( V_39 ) )
return - V_40 ;
F_13 ( V_41 L_2 ) ;
V_36 = F_14 ( V_41 , 0 , NULL , 0 ) ;
if ( F_15 ( V_36 ) )
return F_16 ( V_36 ) ;
if ( ! F_17 ( & V_36 -> V_7 , V_42 , 0x40 , V_41 ) ) {
F_18 ( V_41 L_3 ) ;
return - V_43 ;
}
V_34 = F_19 ( & V_36 -> V_7 , 1 ) ;
if ( ! V_34 )
return - V_44 ;
V_9 = V_34 -> V_45 [ 0 ] ;
V_9 -> V_46 = & V_47 ;
V_9 -> V_48 = V_49 ;
V_9 -> V_31 |= V_50 | V_51 ;
V_9 -> V_31 |= V_52 ;
V_37 = ( void T_1 * ) V_42 ;
V_9 -> V_12 . V_11 = V_37 ;
V_9 -> V_12 . V_53 = V_37 + 1 + 1 * 4 ;
V_9 -> V_12 . V_54 = V_37 + 1 + 1 * 4 ;
V_9 -> V_12 . V_55 = V_37 + 1 + 2 * 4 ;
V_9 -> V_12 . V_56 = V_37 + 1 + 3 * 4 ;
V_9 -> V_12 . V_57 = V_37 + 1 + 4 * 4 ;
V_9 -> V_12 . V_58 = V_37 + 1 + 5 * 4 ;
V_9 -> V_12 . V_59 = V_37 + 1 + 6 * 4 ;
V_9 -> V_12 . V_60 = V_37 + 1 + 7 * 4 ;
V_9 -> V_12 . V_61 = V_37 + 1 + 7 * 4 ;
V_9 -> V_12 . V_62 = V_37 + V_63 ;
V_9 -> V_12 . V_64 = V_37 + V_63 ;
F_20 ( V_9 , L_4 , ( unsigned long ) V_37 ,
( unsigned long ) V_37 + V_63 ) ;
return F_21 ( V_34 , 0 , NULL , 0 , & V_65 ) ;
}
