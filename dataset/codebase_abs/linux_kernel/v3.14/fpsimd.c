void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
F_2 ( 1 ) ;
}
void F_3 ( unsigned int V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
unsigned int V_5 = 0 ;
if ( V_1 & V_6 )
V_5 = V_7 ;
else if ( V_1 & V_8 )
V_5 = V_9 ;
else if ( V_1 & V_10 )
V_5 = V_11 ;
else if ( V_1 & V_12 )
V_5 = V_13 ;
else if ( V_1 & V_14 )
V_5 = V_15 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 = V_17 ;
V_4 . V_5 = V_5 ;
V_4 . V_18 = ( void V_19 * ) F_4 ( V_3 ) ;
F_5 ( V_17 , & V_4 , V_20 ) ;
}
void F_6 ( struct V_21 * V_22 )
{
if ( V_20 -> V_23 )
F_7 ( & V_20 -> V_24 . V_25 ) ;
if ( V_22 -> V_23 )
F_8 ( & V_22 -> V_24 . V_25 ) ;
}
void F_9 ( void )
{
F_10 () ;
memset ( & V_20 -> V_24 . V_25 , 0 , sizeof( struct V_25 ) ) ;
F_8 ( & V_20 -> V_24 . V_25 ) ;
F_11 () ;
}
void F_12 ( void )
{
F_13 ( F_14 () ) ;
F_10 () ;
if ( V_20 -> V_23 )
F_7 ( & V_20 -> V_24 . V_25 ) ;
}
void F_15 ( void )
{
if ( V_20 -> V_23 )
F_8 ( & V_20 -> V_24 . V_25 ) ;
F_11 () ;
}
static int F_16 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
switch ( V_28 ) {
case V_30 :
if ( V_20 -> V_23 )
F_7 ( & V_20 -> V_24 . V_25 ) ;
break;
case V_31 :
if ( V_20 -> V_23 )
F_8 ( & V_20 -> V_24 . V_25 ) ;
break;
case V_32 :
default:
return V_33 ;
}
return V_34 ;
}
static void F_17 ( void )
{
F_18 ( & V_35 ) ;
}
static inline void F_17 ( void ) { }
static int T_2 F_19 ( void )
{
T_3 V_36 = F_20 ( V_37 ) ;
if ( V_36 & ( 0xf << 16 ) ) {
F_21 ( L_1 ) ;
return 0 ;
}
V_38 |= V_39 ;
if ( V_36 & ( 0xf << 20 ) )
F_21 ( L_2 ) ;
else
V_38 |= V_40 ;
F_17 () ;
return 0 ;
}
