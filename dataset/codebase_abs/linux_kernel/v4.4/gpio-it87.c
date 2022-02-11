static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( void )
{
if ( ! F_4 ( V_4 , 2 , V_5 ) )
return - V_6 ;
F_5 ( 0x87 , V_4 ) ;
F_5 ( 0x01 , V_4 ) ;
F_5 ( 0x55 , V_4 ) ;
F_5 ( 0x55 , V_4 ) ;
return 0 ;
}
static inline void F_6 ( void )
{
F_5 ( 0x02 , V_4 ) ;
F_5 ( 0x02 , V_7 ) ;
F_7 ( V_4 , 2 ) ;
}
static inline void F_8 ( int V_8 )
{
F_5 ( V_9 , V_4 ) ;
F_5 ( V_8 , V_7 ) ;
}
static inline int F_9 ( int V_10 )
{
F_5 ( V_10 , V_4 ) ;
return F_10 ( V_7 ) ;
}
static inline void F_11 ( int V_11 , int V_10 )
{
F_5 ( V_10 , V_4 ) ;
F_5 ( V_11 , V_7 ) ;
}
static inline int F_12 ( int V_10 )
{
int V_11 ;
F_5 ( V_10 ++ , V_4 ) ;
V_11 = F_10 ( V_7 ) << 8 ;
F_5 ( V_10 , V_4 ) ;
V_11 |= F_10 ( V_7 ) ;
return V_11 ;
}
static inline void F_13 ( int V_11 , int V_10 )
{
F_5 ( V_10 ++ , V_4 ) ;
F_5 ( V_11 >> 8 , V_7 ) ;
F_5 ( V_10 , V_4 ) ;
F_5 ( V_11 , V_7 ) ;
}
static inline void F_14 ( int V_12 , int V_10 )
{
T_1 V_13 = F_9 ( V_10 ) ;
T_1 V_14 = V_13 | V_12 ;
if ( V_13 != V_14 )
F_11 ( V_14 , V_10 ) ;
}
static inline void F_15 ( int V_12 , int V_10 )
{
T_1 V_13 = F_9 ( V_10 ) ;
T_1 V_14 = V_13 & ~ V_12 ;
if ( V_13 != V_14 )
F_11 ( V_14 , V_10 ) ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_15 )
{
T_1 V_12 , V_16 ;
int V_17 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_12 = 1 << ( V_15 % 8 ) ;
V_16 = ( V_15 / 8 ) ;
F_17 ( & V_1 -> V_18 ) ;
V_17 = F_3 () ;
if ( V_17 )
goto exit;
if ( V_16 < V_1 -> V_19 )
F_14 ( V_12 , V_16 + V_1 -> V_20 ) ;
F_15 ( V_12 , V_16 + V_1 -> V_21 ) ;
F_6 () ;
exit:
F_18 ( & V_1 -> V_18 ) ;
return V_17 ;
}
static int F_19 ( struct V_2 * V_3 , unsigned V_15 )
{
T_2 V_10 ;
T_1 V_12 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_12 = 1 << ( V_15 % 8 ) ;
V_10 = ( V_15 / 8 ) + V_1 -> V_22 ;
return ! ! ( F_10 ( V_10 ) & V_12 ) ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_15 )
{
T_1 V_12 , V_16 ;
int V_17 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_12 = 1 << ( V_15 % 8 ) ;
V_16 = ( V_15 / 8 ) ;
F_17 ( & V_1 -> V_18 ) ;
V_17 = F_3 () ;
if ( V_17 )
goto exit;
F_15 ( V_12 , V_16 + V_1 -> V_21 ) ;
F_6 () ;
exit:
F_18 ( & V_1 -> V_18 ) ;
return V_17 ;
}
static void F_21 ( struct V_2 * V_3 ,
unsigned V_15 , int V_11 )
{
T_1 V_12 , V_23 ;
T_2 V_10 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_12 = 1 << ( V_15 % 8 ) ;
V_10 = ( V_15 / 8 ) + V_1 -> V_22 ;
V_23 = F_10 ( V_10 ) ;
if ( V_11 )
F_5 ( V_23 | V_12 , V_10 ) ;
else
F_5 ( V_23 & ~ V_12 , V_10 ) ;
}
static int F_22 ( struct V_2 * V_3 ,
unsigned V_15 , int V_11 )
{
T_1 V_12 , V_16 ;
int V_17 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_12 = 1 << ( V_15 % 8 ) ;
V_16 = ( V_15 / 8 ) ;
F_17 ( & V_1 -> V_18 ) ;
V_17 = F_3 () ;
if ( V_17 )
goto exit;
F_14 ( V_12 , V_16 + V_1 -> V_21 ) ;
F_21 ( V_3 , V_15 , V_11 ) ;
F_6 () ;
exit:
F_18 ( & V_1 -> V_18 ) ;
return V_17 ;
}
static int T_3 F_23 ( void )
{
int V_17 = 0 , V_24 ;
T_2 V_25 ;
T_1 V_26 , V_27 ;
char * V_28 , * * V_29 ;
struct V_1 * V_1 = & V_30 ;
V_17 = F_3 () ;
if ( V_17 )
return V_17 ;
V_25 = F_12 ( V_31 ) ;
V_26 = F_9 ( V_32 ) & 0x0f ;
F_6 () ;
V_1 -> V_3 = V_33 ;
switch ( V_25 ) {
case V_34 :
case V_35 :
V_27 = 0x62 ;
V_1 -> V_36 = 8 ;
V_1 -> V_21 = 0xc8 ;
V_1 -> V_20 = 0xc0 ;
V_1 -> V_19 = 5 ;
V_1 -> V_3 . V_37 = 64 ;
break;
case V_38 :
V_27 = 0x60 ;
V_1 -> V_36 = 4 ;
V_1 -> V_21 = 0xf0 ;
V_1 -> V_19 = 0 ;
V_1 -> V_3 . V_37 = 16 ;
break;
case V_39 :
F_24 ( L_1 ) ;
return - V_40 ;
default:
F_24 ( L_2 ,
V_25 , V_26 ) ;
return - V_40 ;
}
V_17 = F_3 () ;
if ( V_17 )
return V_17 ;
F_8 ( V_41 ) ;
V_1 -> V_22 = F_12 ( V_27 ) ;
F_6 () ;
F_25 ( L_3 ,
V_25 , V_26 , V_1 -> V_3 . V_37 ,
V_1 -> V_22 ) ;
if ( ! F_26 ( V_1 -> V_22 , V_1 -> V_36 ,
V_5 ) )
return - V_6 ;
V_28 = F_27 ( V_1 -> V_3 . V_37 , sizeof( L_4 ) ,
V_42 ) ;
V_29 = F_27 ( V_1 -> V_3 . V_37 , sizeof( const char * ) ,
V_42 ) ;
if ( ! V_28 || ! V_29 ) {
V_17 = - V_43 ;
goto V_44;
}
for ( V_24 = 0 ; V_24 < V_1 -> V_3 . V_37 ; V_24 ++ ) {
char * V_45 = & V_28 [ V_24 * sizeof( L_4 ) ] ;
sprintf ( V_45 , L_5 , 1 + ( V_24 / 8 ) , V_24 % 8 ) ;
V_29 [ V_24 ] = V_45 ;
}
V_1 -> V_3 . V_46 = ( const char * const * ) V_29 ;
V_17 = F_28 ( & V_1 -> V_3 ) ;
if ( V_17 )
goto V_44;
return 0 ;
V_44:
F_29 ( V_29 ) ;
F_29 ( V_28 ) ;
F_7 ( V_1 -> V_22 , V_1 -> V_36 ) ;
return V_17 ;
}
static void T_4 F_30 ( void )
{
struct V_1 * V_1 = & V_30 ;
F_31 ( & V_1 -> V_3 ) ;
F_7 ( V_1 -> V_22 , V_1 -> V_36 ) ;
F_29 ( V_1 -> V_3 . V_46 [ 0 ] ) ;
F_29 ( V_1 -> V_3 . V_46 ) ;
}
