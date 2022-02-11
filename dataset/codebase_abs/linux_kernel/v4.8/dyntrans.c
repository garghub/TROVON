static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
union V_4 V_5 )
{
unsigned long V_6 , V_7 ;
void * V_8 ;
if ( F_2 ( ( unsigned long ) V_3 ) == V_9 ) {
V_6 = F_3 ( V_2 ,
( unsigned long ) V_3 ) ;
V_8 = F_4 ( F_5 ( F_6 ( V_6 ) ) ) ;
V_8 += V_6 & ~ V_10 ;
memcpy ( V_8 , ( void * ) & V_5 , sizeof( T_1 ) ) ;
F_7 ( ( unsigned long ) V_8 ,
( unsigned long ) V_8 + 32 ) ;
F_8 ( V_8 ) ;
} else if ( F_2 ( ( unsigned long ) V_3 ) == V_11 ) {
F_9 ( V_7 ) ;
memcpy ( ( void * ) V_3 , ( void * ) & V_5 , sizeof( T_1 ) ) ;
F_7 ( ( unsigned long ) V_3 ,
( unsigned long ) V_3 + 32 ) ;
F_10 ( V_7 ) ;
} else {
F_11 ( L_1 , V_12 , V_3 ) ;
return - V_13 ;
}
return 0 ;
}
int F_12 ( union V_4 V_14 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_15 = { 0 } ;
return F_1 ( V_2 , V_3 , V_15 ) ;
}
int F_13 ( union V_4 V_14 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_16 = { 0 } ;
V_16 . V_17 . V_18 = V_19 ;
V_16 . V_17 . V_20 = V_14 . V_17 . V_20 ;
V_16 . V_17 . V_21 = V_22 ;
if ( V_23 )
V_16 . V_17 . V_24 = V_14 . V_25 . V_24 ;
else
V_16 . V_17 . V_24 = V_14 . V_17 . V_24 ;
return F_1 ( V_2 , V_3 , V_16 ) ;
}
int F_14 ( union V_4 V_14 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_26 = { 0 } ;
T_1 V_27 , V_28 ;
V_27 = V_14 . V_29 . V_27 ;
V_28 = V_14 . V_29 . V_28 ;
if ( V_27 == V_30 && V_28 == 0 ) {
V_26 . V_31 . V_18 = V_32 ;
V_26 . V_31 . V_27 = V_14 . V_29 . V_21 ;
V_26 . V_31 . V_33 = V_34 ;
} else {
V_26 . V_17 . V_18 = V_35 ;
V_26 . V_17 . V_21 = V_14 . V_29 . V_21 ;
V_26 . V_17 . V_24 = V_36 |
F_15 ( struct V_37 , V_38 . V_39 [ V_27 ] [ V_28 ] ) ;
#ifdef F_16
if ( sizeof( V_2 -> V_40 . V_38 -> V_39 [ 0 ] [ 0 ] ) == 8 )
V_26 . V_17 . V_24 |= 4 ;
#endif
}
return F_1 ( V_2 , V_3 , V_26 ) ;
}
int F_17 ( union V_4 V_14 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_41 = { 0 } ;
T_1 V_27 , V_28 ;
V_27 = V_14 . V_29 . V_27 ;
V_28 = V_14 . V_29 . V_28 ;
V_41 . V_17 . V_18 = V_42 ;
V_41 . V_17 . V_21 = V_14 . V_29 . V_21 ;
V_41 . V_17 . V_24 = V_36 |
F_15 ( struct V_37 , V_38 . V_39 [ V_27 ] [ V_28 ] ) ;
#ifdef F_16
if ( sizeof( V_2 -> V_40 . V_38 -> V_39 [ 0 ] [ 0 ] ) == 8 )
V_41 . V_17 . V_24 |= 4 ;
#endif
return F_1 ( V_2 , V_3 , V_41 ) ;
}
