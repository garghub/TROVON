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
V_24 . V_26 , ( long ) V_24 . V_27 ) ;
F_6 ( V_13 , L_5 ,
V_24 . V_26 , ( long ) V_24 . V_27 ,
F_10 ( V_6 + V_28 ) ) ;
#endif
V_21 = F_10 ( V_6 + V_29 ) ;
if ( V_21 == 0xabadface ) {
#if V_11 > V_12
F_9 ( & V_24 ) ;
F_6 ( V_13 ,
L_6 ,
V_24 . V_26 , ( long ) V_24 . V_27 ) ;
#endif
while ( V_21 = F_10 ( V_6 + V_28 ) ,
( V_21 & V_30 ) == 0 ) {
F_3 ( V_3 ) ;
#if V_11 > V_12
V_22 ++ ;
#endif
}
#if V_11 > V_12
F_6 ( V_13 ,
L_5 ,
V_24 . V_26 , ( long ) V_24 . V_27 ,
F_10 ( V_6 + V_28 ) ) ;
F_9 ( & V_24 ) ;
F_6 ( V_13 ,
L_7 ,
V_24 . V_26 , ( long ) V_24 . V_27 ,
V_22 ) ;
#endif
}
F_2 ( V_6 , V_31 ,
V_16 ) ;
#if V_11 > V_12
F_3 ( V_3 ) ;
V_21 = F_10 ( V_6 + V_28 ) ;
F_9 ( & V_24 ) ;
F_6 ( V_13 , L_5 ,
V_24 . V_26 , ( long ) V_24 . V_27 , V_21 ) ;
#endif
} else {
#if V_11 > V_12
F_6 ( V_13 , L_8 ) ;
#endif
F_2 ( V_6 , V_19 ,
V_16 ) ;
}
}
void
F_11 ( void T_1 * V_6 , T_4 V_32 )
{
#if V_11 > V_12
F_6 ( V_25 , L_9 ) ;
#endif
F_2 ( V_6 , V_32 , V_33 ) ;
F_3 ( V_3 ) ;
F_2 ( V_6 , V_34 , V_16 ) ;
F_3 ( V_3 ) ;
F_2 ( V_6 , V_35 , V_2 ) ;
F_3 ( V_3 ) ;
}
void
F_12 ( void T_1 * V_6 )
{
T_3 V_21 ;
V_21 = V_36 | V_37 |
V_38 ;
F_2 ( V_6 , V_21 , V_2 ) ;
F_3 ( V_3 ) ;
}
int
F_5 ( T_2 * V_39 , int V_40 )
{
const T_5 V_41 = ( F_13 ( V_39 -> V_42 [ V_40 ] ) -
F_13 ( V_39 -> V_43 [ V_40 ] ) ) ;
F_14 ( V_41 < 0 ) ;
switch ( V_40 ) {
case V_8 :
F_14 ( V_41 > V_44 ) ;
case V_7 :
case V_45 :
F_14 ( V_41 > V_46 ) ;
return V_41 ;
case V_10 :
F_14 ( V_41 > V_44 ) ;
return V_44 - V_41 ;
case V_9 :
case V_47 :
F_14 ( V_41 > V_48 ) ;
return V_48 - V_41 ;
}
F_15 () ;
return 0 ;
}
