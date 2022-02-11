void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ) {
F_2 ( & V_2 -> V_5 -> V_6 ,
( sizeof( V_7 ) * V_8 ) + V_9 ,
V_2 -> V_3 . V_4 ,
V_2 -> V_3 . V_10 ) ;
V_2 -> V_3 . V_4 = NULL ;
}
}
int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 =
F_4 ( & V_2 -> V_5 -> V_6 ,
( sizeof( V_7 ) * V_8 ) + V_9 ,
& V_2 -> V_3 . V_10 , V_11 ) ;
if ( ! V_2 -> V_3 . V_4 )
return - V_12 ;
V_2 -> V_3 . V_13 = F_5 ( V_2 -> V_3 . V_10 , V_9 ) ;
F_6 ( V_2 , L_1 ,
( unsigned long long ) V_2 -> V_3 . V_10 ,
( unsigned long long ) V_2 -> V_3 . V_13 ,
( int ) ( V_2 -> V_3 . V_13 - V_2 -> V_3 . V_10 ) ) ;
V_2 -> V_3 . V_14 = V_2 -> V_3 . V_4 +
( V_2 -> V_3 . V_13 - V_2 -> V_3 . V_10 ) ;
F_6 ( V_2 , L_2 ,
V_2 -> V_3 . V_14 , V_2 -> V_3 . V_4 ,
( int ) ( V_2 -> V_3 . V_13 - V_2 -> V_3 . V_10 ) ) ;
memset ( V_2 -> V_3 . V_4 , 0 , ( sizeof( V_7 ) * V_8 ) + V_9 ) ;
V_2 -> V_3 . V_15 = 0 ;
V_2 -> V_16 |= V_17 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
V_7 V_18 ;
unsigned long V_19 ;
if ( ! V_2 -> V_3 . V_4 )
return 0 ;
F_8 ( & V_2 -> V_20 , V_19 ) ;
F_9 ( V_2 ) ;
memset ( & V_2 -> V_3 . V_14 [ 0 ] , 0 , sizeof( V_7 ) * V_8 ) ;
V_18 = V_2 -> V_3 . V_13 >> V_21 ;
V_18 |= V_22 ;
V_18 |= V_23 ;
F_6 ( V_2 , L_3
L_4 ,
V_18 , ( unsigned long long ) V_2 -> V_3 . V_13 ) ;
F_10 ( V_2 , V_24 , V_18 ) ;
V_2 -> V_3 . V_25 = true ;
V_2 -> V_3 . V_15 = 0 ;
F_10 ( V_2 , V_26 , V_2 -> V_16 ) ;
F_11 ( V_2 ) ;
F_12 ( & V_2 -> V_20 , V_19 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
F_8 ( & V_2 -> V_20 , V_19 ) ;
V_2 -> V_3 . V_25 = false ;
F_12 ( & V_2 -> V_20 , V_19 ) ;
}
static T_1 F_14 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
V_7 V_29 , V_16 ;
unsigned long V_19 ;
#ifdef F_15
V_7 V_30 ;
#endif
if ( ! V_2 )
return V_31 ;
F_8 ( & V_2 -> V_20 , V_19 ) ;
V_16 = F_16 ( V_2 , V_32 ) ;
F_10 ( V_2 , V_32 , 0x00000000 ) ;
V_29 = F_16 ( V_2 , V_26 ) ;
if ( ! V_29 ) {
F_6 ( V_2 , L_5 ) ;
goto V_33;
}
if ( ( V_29 == 0xFFFFFFFF ) || ( ( V_29 & 0xFFFFFFF0 ) == 0xa5a5a5a0 ) ) {
F_17 ( V_2 , L_6 , V_29 ) ;
goto V_34;
}
#ifdef F_15
if ( F_18 ( V_2 ) & ( V_35 ) ) {
V_30 = F_16 ( V_2 , V_36 ) ;
F_6 ( V_2 , L_7
L_8 , V_29 , V_16 , V_30 ) ;
}
#endif
V_2 -> V_3 . V_29 |= V_29 ;
if ( F_19 ( V_29 ) )
F_20 ( & V_2 -> V_37 ) ;
else if ( F_21 ( V_38 , & V_2 -> V_39 ) && ! V_2 -> V_3 . V_29 )
F_11 ( V_2 ) ;
V_34:
F_12 ( & V_2 -> V_20 , V_19 ) ;
return V_40 ;
V_33:
if ( F_21 ( V_38 , & V_2 -> V_39 ) && ! V_2 -> V_3 . V_29 )
F_11 ( V_2 ) ;
F_12 ( & V_2 -> V_20 , V_19 ) ;
return V_31 ;
}
T_1 F_22 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
V_7 V_29 , V_16 ;
V_7 V_18 = 0 ;
unsigned long V_19 ;
if ( ! V_2 )
return V_31 ;
if ( ! V_2 -> V_3 . V_25 )
return F_14 ( V_27 , V_28 ) ;
F_8 ( & V_2 -> V_20 , V_19 ) ;
V_16 = F_16 ( V_2 , V_32 ) ;
F_10 ( V_2 , V_32 , 0x00000000 ) ;
if ( ! V_2 -> V_3 . V_14 [ V_2 -> V_3 . V_15 ] ) {
F_6 ( V_2 , L_5 ) ;
goto V_33;
}
while ( V_2 -> V_3 . V_14 [ V_2 -> V_3 . V_15 ] ) {
V_18 |= F_23 ( V_2 -> V_3 . V_14 [ V_2 -> V_3 . V_15 ] ) ;
F_6 ( V_2 , L_9 ,
V_2 -> V_3 . V_15 ,
F_23 ( V_2 -> V_3 . V_14 [ V_2 -> V_3 . V_15 ] ) ) ;
V_2 -> V_3 . V_14 [ V_2 -> V_3 . V_15 ] = 0 ;
V_2 -> V_3 . V_15 = F_24 ( V_2 -> V_3 . V_15 ,
V_8 ) ;
}
if ( V_18 == 0xffffffff )
V_18 = 0 ;
if ( V_18 & 0xC0000 )
V_18 |= 0x8000 ;
V_29 = ( 0xff & V_18 ) | ( ( 0xff00 & V_18 ) << 16 ) ;
F_6 ( V_2 , L_10 ,
V_29 , V_16 , V_18 ) ;
V_29 &= V_2 -> V_16 ;
V_2 -> V_3 . V_29 |= V_29 ;
if ( F_19 ( V_29 ) )
F_20 ( & V_2 -> V_37 ) ;
else if ( F_21 ( V_38 , & V_2 -> V_39 ) && ! V_2 -> V_3 . V_29 ) {
F_11 ( V_2 ) ;
}
F_12 ( & V_2 -> V_20 , V_19 ) ;
return V_40 ;
V_33:
if ( F_21 ( V_38 , & V_2 -> V_39 ) && ! V_2 -> V_3 . V_29 )
F_11 ( V_2 ) ;
F_12 ( & V_2 -> V_20 , V_19 ) ;
return V_31 ;
}
