static inline int F_1 ( void )
{
if ( ! F_2 ( V_1 , 2 , V_2 ) )
return - V_3 ;
F_3 ( 0x87 , V_1 ) ;
F_3 ( 0x01 , V_1 ) ;
F_3 ( 0x55 , V_1 ) ;
F_3 ( 0x55 , V_1 ) ;
return 0 ;
}
static inline void F_4 ( void )
{
F_3 ( 0x02 , V_1 ) ;
F_3 ( 0x02 , V_4 ) ;
F_5 ( V_1 , 2 ) ;
}
static inline void F_6 ( int V_5 )
{
F_3 ( V_6 , V_1 ) ;
F_3 ( V_5 , V_4 ) ;
}
static inline int F_7 ( int V_7 )
{
F_3 ( V_7 , V_1 ) ;
return F_8 ( V_4 ) ;
}
static inline void F_9 ( int V_8 , int V_7 )
{
F_3 ( V_7 , V_1 ) ;
F_3 ( V_8 , V_4 ) ;
}
static inline int F_10 ( int V_7 )
{
int V_8 ;
F_3 ( V_7 ++ , V_1 ) ;
V_8 = F_8 ( V_4 ) << 8 ;
F_3 ( V_7 , V_1 ) ;
V_8 |= F_8 ( V_4 ) ;
return V_8 ;
}
static inline void F_11 ( int V_8 , int V_7 )
{
F_3 ( V_7 ++ , V_1 ) ;
F_3 ( V_8 >> 8 , V_4 ) ;
F_3 ( V_7 , V_1 ) ;
F_3 ( V_8 , V_4 ) ;
}
static inline void F_12 ( int V_9 , int V_7 )
{
T_1 V_10 = F_7 ( V_7 ) ;
T_1 V_11 = V_10 | V_9 ;
if ( V_10 != V_11 )
F_9 ( V_11 , V_7 ) ;
}
static inline void F_13 ( int V_9 , int V_7 )
{
T_1 V_10 = F_7 ( V_7 ) ;
T_1 V_11 = V_10 & ~ V_9 ;
if ( V_10 != V_11 )
F_9 ( V_11 , V_7 ) ;
}
static int F_14 ( struct V_12 * V_13 , unsigned V_14 )
{
T_1 V_9 , V_15 ;
int V_16 = 0 ;
struct V_17 * V_17 = F_15 ( V_13 ) ;
V_9 = 1 << ( V_14 % 8 ) ;
V_15 = ( V_14 / 8 ) ;
F_16 ( & V_17 -> V_18 ) ;
V_16 = F_1 () ;
if ( V_16 )
goto exit;
if ( V_15 < V_17 -> V_19 )
F_12 ( V_9 , V_15 + V_17 -> V_20 ) ;
F_13 ( V_9 , V_15 + V_17 -> V_21 ) ;
F_4 () ;
exit:
F_17 ( & V_17 -> V_18 ) ;
return V_16 ;
}
static int F_18 ( struct V_12 * V_13 , unsigned V_14 )
{
T_2 V_7 ;
T_1 V_9 ;
struct V_17 * V_17 = F_15 ( V_13 ) ;
V_9 = 1 << ( V_14 % 8 ) ;
V_7 = ( V_14 / 8 ) + V_17 -> V_22 ;
return ! ! ( F_8 ( V_7 ) & V_9 ) ;
}
static int F_19 ( struct V_12 * V_13 , unsigned V_14 )
{
T_1 V_9 , V_15 ;
int V_16 = 0 ;
struct V_17 * V_17 = F_15 ( V_13 ) ;
V_9 = 1 << ( V_14 % 8 ) ;
V_15 = ( V_14 / 8 ) ;
F_16 ( & V_17 -> V_18 ) ;
V_16 = F_1 () ;
if ( V_16 )
goto exit;
F_13 ( V_9 , V_15 + V_17 -> V_21 ) ;
F_4 () ;
exit:
F_17 ( & V_17 -> V_18 ) ;
return V_16 ;
}
static void F_20 ( struct V_12 * V_13 ,
unsigned V_14 , int V_8 )
{
T_1 V_9 , V_23 ;
T_2 V_7 ;
struct V_17 * V_17 = F_15 ( V_13 ) ;
V_9 = 1 << ( V_14 % 8 ) ;
V_7 = ( V_14 / 8 ) + V_17 -> V_22 ;
V_23 = F_8 ( V_7 ) ;
if ( V_8 )
F_3 ( V_23 | V_9 , V_7 ) ;
else
F_3 ( V_23 & ~ V_9 , V_7 ) ;
}
static int F_21 ( struct V_12 * V_13 ,
unsigned V_14 , int V_8 )
{
T_1 V_9 , V_15 ;
int V_16 = 0 ;
struct V_17 * V_17 = F_15 ( V_13 ) ;
V_9 = 1 << ( V_14 % 8 ) ;
V_15 = ( V_14 / 8 ) ;
F_16 ( & V_17 -> V_18 ) ;
V_16 = F_1 () ;
if ( V_16 )
goto exit;
F_12 ( V_9 , V_15 + V_17 -> V_21 ) ;
F_20 ( V_13 , V_14 , V_8 ) ;
F_4 () ;
exit:
F_17 ( & V_17 -> V_18 ) ;
return V_16 ;
}
static int T_3 F_22 ( void )
{
int V_16 = 0 , V_24 ;
T_2 V_25 ;
T_1 V_26 , V_27 ;
char * V_28 , * * V_29 ;
struct V_17 * V_17 = & V_30 ;
V_16 = F_1 () ;
if ( V_16 )
return V_16 ;
V_25 = F_10 ( V_31 ) ;
V_26 = F_7 ( V_32 ) & 0x0f ;
F_4 () ;
V_17 -> V_13 = V_33 ;
switch ( V_25 ) {
case V_34 :
case V_35 :
V_27 = 0x62 ;
V_17 -> V_36 = 11 ;
V_17 -> V_21 = 0xc8 ;
V_17 -> V_19 = 0 ;
V_17 -> V_13 . V_37 = 64 ;
break;
case V_38 :
case V_39 :
case V_40 :
V_27 = 0x62 ;
V_17 -> V_36 = 8 ;
V_17 -> V_21 = 0xc8 ;
V_17 -> V_20 = 0xc0 ;
V_17 -> V_19 = 5 ;
V_17 -> V_13 . V_37 = 64 ;
break;
case V_41 :
V_27 = 0x60 ;
V_17 -> V_36 = 4 ;
V_17 -> V_21 = 0xf0 ;
V_17 -> V_19 = 0 ;
V_17 -> V_13 . V_37 = 16 ;
break;
case V_42 :
F_23 ( L_1 ) ;
return - V_43 ;
default:
F_23 ( L_2 ,
V_25 , V_26 ) ;
return - V_43 ;
}
V_16 = F_1 () ;
if ( V_16 )
return V_16 ;
F_6 ( V_44 ) ;
V_17 -> V_22 = F_10 ( V_27 ) ;
F_4 () ;
F_24 ( L_3 ,
V_25 , V_26 , V_17 -> V_13 . V_37 ,
V_17 -> V_22 ) ;
if ( ! F_25 ( V_17 -> V_22 , V_17 -> V_36 ,
V_2 ) )
return - V_3 ;
V_28 = F_26 ( V_17 -> V_13 . V_37 , sizeof( L_4 ) ,
V_45 ) ;
V_29 = F_26 ( V_17 -> V_13 . V_37 , sizeof( const char * ) ,
V_45 ) ;
if ( ! V_28 || ! V_29 ) {
V_16 = - V_46 ;
goto V_47;
}
for ( V_24 = 0 ; V_24 < V_17 -> V_13 . V_37 ; V_24 ++ ) {
char * V_48 = & V_28 [ V_24 * sizeof( L_4 ) ] ;
sprintf ( V_48 , L_5 , 1 + ( V_24 / 8 ) , V_24 % 8 ) ;
V_29 [ V_24 ] = V_48 ;
}
V_17 -> V_13 . V_49 = ( const char * const * ) V_29 ;
V_16 = F_27 ( & V_17 -> V_13 , V_17 ) ;
if ( V_16 )
goto V_47;
return 0 ;
V_47:
F_28 ( V_29 ) ;
F_28 ( V_28 ) ;
F_5 ( V_17 -> V_22 , V_17 -> V_36 ) ;
return V_16 ;
}
static void T_4 F_29 ( void )
{
struct V_17 * V_17 = & V_30 ;
F_30 ( & V_17 -> V_13 ) ;
F_5 ( V_17 -> V_22 , V_17 -> V_36 ) ;
F_28 ( V_17 -> V_13 . V_49 [ 0 ] ) ;
F_28 ( V_17 -> V_13 . V_49 ) ;
}
