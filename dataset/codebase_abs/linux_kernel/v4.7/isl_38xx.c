void
F_1 ( void T_1 * V_1 )
{
F_2 ( V_1 , 0x00000000 , V_2 ) ;
F_3 ( V_3 ) ;
}
void
F_4 ( T_2 * V_4 ,
int * V_5 , void T_1 * V_6 )
{
if ( F_5 ( V_4 , V_7 ) )
return;
if ( F_5 ( V_4 , V_8 ) )
return;
if ( F_5 ( V_4 , V_9 ) )
return;
if ( F_5 ( V_4 , V_10 ) )
return;
#if V_11 > V_12
F_6 ( V_13 , L_1 ) ;
#endif
* V_5 = V_14 ;
F_2 ( V_6 , V_15 ,
V_16 ) ;
F_3 ( V_3 ) ;
}
void
F_7 ( T_2 * V_4 ,
int * V_5 , void T_1 * V_6 )
{
* V_5 = V_17 ;
if ( ! F_5 ( V_4 , V_7 )
&& ! F_5 ( V_4 , V_8 ) )
return;
#if V_11 > V_12
F_6 ( V_18 , L_2 ) ;
#endif
F_2 ( V_6 , V_19 ,
V_16 ) ;
F_3 ( V_3 ) ;
}
void
F_8 ( int V_20 , void T_1 * V_6 )
{
T_3 V_21 ;
#if V_11 > V_12
T_3 V_22 = 0 ;
struct V_23 V_24 ;
F_6 ( V_25 , L_3 ) ;
#endif
if ( V_20 ) {
#if V_11 > V_12
F_9 ( & V_24 ) ;
F_6 ( V_13 , L_4 ,
( V_26 ) V_24 . V_27 , V_24 . V_28 ) ;
F_6 ( V_13 , L_5 ,
( V_26 ) V_24 . V_27 , V_24 . V_28 ,
F_10 ( V_6 + V_29 ) ) ;
#endif
V_21 = F_10 ( V_6 + V_30 ) ;
if ( V_21 == 0xabadface ) {
#if V_11 > V_12
F_9 ( & V_24 ) ;
F_6 ( V_13 ,
L_6 ,
( V_26 ) V_24 . V_27 , V_24 . V_28 ) ;
#endif
while ( V_21 = F_10 ( V_6 + V_29 ) ,
( V_21 & V_31 ) == 0 ) {
F_3 ( V_3 ) ;
#if V_11 > V_12
V_22 ++ ;
#endif
}
#if V_11 > V_12
F_6 ( V_13 ,
L_5 ,
( V_26 ) V_24 . V_27 , V_24 . V_28 ,
F_10 ( V_6 + V_29 ) ) ;
F_9 ( & V_24 ) ;
F_6 ( V_13 ,
L_7 ,
( V_26 ) V_24 . V_27 , V_24 . V_28 ,
V_22 ) ;
#endif
}
F_2 ( V_6 , V_32 ,
V_16 ) ;
#if V_11 > V_12
F_3 ( V_3 ) ;
V_21 = F_10 ( V_6 + V_29 ) ;
F_9 ( & V_24 ) ;
F_6 ( V_13 , L_8 ,
( V_26 ) V_24 . V_27 , V_24 . V_28 , V_21 ) ;
#endif
} else {
#if V_11 > V_12
F_6 ( V_13 , L_9 ) ;
#endif
F_2 ( V_6 , V_19 ,
V_16 ) ;
}
}
void
F_11 ( void T_1 * V_6 , T_4 V_33 )
{
#if V_11 > V_12
F_6 ( V_25 , L_10 ) ;
#endif
F_2 ( V_6 , V_33 , V_34 ) ;
F_3 ( V_3 ) ;
F_2 ( V_6 , V_35 , V_16 ) ;
F_3 ( V_3 ) ;
F_2 ( V_6 , V_36 , V_2 ) ;
F_3 ( V_3 ) ;
}
void
F_12 ( void T_1 * V_6 )
{
T_3 V_21 ;
V_21 = V_37 | V_38 |
V_39 ;
F_2 ( V_6 , V_21 , V_2 ) ;
F_3 ( V_3 ) ;
}
int
F_5 ( T_2 * V_40 , int V_41 )
{
const T_5 V_42 = ( F_13 ( V_40 -> V_43 [ V_41 ] ) -
F_13 ( V_40 -> V_44 [ V_41 ] ) ) ;
F_14 ( V_42 < 0 ) ;
switch ( V_41 ) {
case V_8 :
F_14 ( V_42 > V_45 ) ;
case V_7 :
case V_46 :
F_14 ( V_42 > V_47 ) ;
return V_42 ;
case V_10 :
F_14 ( V_42 > V_45 ) ;
return V_45 - V_42 ;
case V_9 :
case V_48 :
F_14 ( V_42 > V_49 ) ;
return V_49 - V_42 ;
}
F_15 () ;
return 0 ;
}
