static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
union V_4 V_5 )
{
unsigned long V_6 = ( unsigned long ) V_3 ;
int V_7 ;
V_8:
F_2 ( V_2 ) ;
V_7 = F_3 ( V_5 . V_9 , V_3 ) ;
F_4 ( V_2 ) ;
if ( F_5 ( V_7 ) ) {
V_7 = F_6 ( V_2 , V_6 , true ) ;
if ( F_5 ( V_7 ) ) {
F_7 ( L_1 ,
V_10 , V_3 ) ;
return - V_11 ;
}
goto V_8;
}
F_8 ( V_6 , V_6 + 4 ) ;
return 0 ;
}
int F_9 ( union V_4 V_12 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_13 = { 0 } ;
return F_1 ( V_2 , V_3 , V_13 ) ;
}
int F_10 ( union V_4 V_12 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_14 = { 0 } ;
V_14 . V_15 . V_16 = V_17 ;
V_14 . V_15 . V_18 = V_12 . V_15 . V_18 ;
V_14 . V_15 . V_19 = V_20 ;
if ( V_21 )
V_14 . V_15 . V_22 = V_12 . V_23 . V_22 ;
else
V_14 . V_15 . V_22 = V_12 . V_15 . V_22 ;
return F_1 ( V_2 , V_3 , V_14 ) ;
}
int F_11 ( union V_4 V_12 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_24 = { 0 } ;
T_1 V_25 , V_26 ;
V_25 = V_12 . V_27 . V_25 ;
V_26 = V_12 . V_27 . V_26 ;
if ( V_25 == V_28 && V_26 == 0 ) {
V_24 . V_29 . V_16 = V_30 ;
V_24 . V_29 . V_25 = V_12 . V_27 . V_19 ;
V_24 . V_29 . V_31 = V_32 ;
} else {
V_24 . V_15 . V_16 = V_33 ;
V_24 . V_15 . V_19 = V_12 . V_27 . V_19 ;
V_24 . V_15 . V_22 = V_34 |
F_12 ( struct V_35 , V_36 . V_37 [ V_25 ] [ V_26 ] ) ;
#ifdef F_13
if ( sizeof( V_2 -> V_38 . V_36 -> V_37 [ 0 ] [ 0 ] ) == 8 )
V_24 . V_15 . V_22 |= 4 ;
#endif
}
return F_1 ( V_2 , V_3 , V_24 ) ;
}
int F_14 ( union V_4 V_12 , T_1 * V_3 ,
struct V_1 * V_2 )
{
union V_4 V_39 = { 0 } ;
T_1 V_25 , V_26 ;
V_25 = V_12 . V_27 . V_25 ;
V_26 = V_12 . V_27 . V_26 ;
V_39 . V_15 . V_16 = V_40 ;
V_39 . V_15 . V_19 = V_12 . V_27 . V_19 ;
V_39 . V_15 . V_22 = V_34 |
F_12 ( struct V_35 , V_36 . V_37 [ V_25 ] [ V_26 ] ) ;
#ifdef F_13
if ( sizeof( V_2 -> V_38 . V_36 -> V_37 [ 0 ] [ 0 ] ) == 8 )
V_39 . V_15 . V_22 |= 4 ;
#endif
return F_1 ( V_2 , V_3 , V_39 ) ;
}
