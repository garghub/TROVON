static inline void F_1 ( T_1 V_1 )
{
unsigned int V_2 = ( unsigned int ) & V_3 [ 0 ] ;
unsigned int V_4 = sizeof( V_3 ) ;
unsigned int V_5 = 0 ;
unsigned int V_6 = 0x40 ;
F_2 ( V_7 , V_2 ) ;
F_2 ( V_8 , V_1 . V_9 [ 0 ] ) ;
F_2 ( V_10 , V_1 . V_9 [ 1 ] ) ;
F_2 ( V_11 , V_4 ) ;
F_2 ( V_12 , V_5 ) ;
F_2 ( V_13 , V_6 ) ;
}
static inline void F_3 ( T_1 V_1 )
{
unsigned int V_2 = 16384 ;
unsigned int V_14 = ( unsigned int ) & V_15 [ 0 ] ;
unsigned int V_4 = sizeof( V_15 ) ;
unsigned int V_5 = 0 ;
unsigned int V_6 = 0x44 ;
F_2 ( V_7 , V_2 ) ;
F_2 ( V_8 , V_1 . V_9 [ 0 ] ) ;
F_2 ( V_10 , V_14 ) ;
F_2 ( V_11 , V_4 ) ;
F_2 ( V_12 , V_5 ) ;
F_2 ( V_13 , V_6 ) ;
}
static inline void F_4 ( void )
{
unsigned int V_16 ;
unsigned int V_17 ;
unsigned int V_18 ;
V_16 = F_5 ( V_19 ) ;
V_17 = V_3 [ V_16 ] . V_20 [ 0 ] & V_21 ;
if ( V_17 ) {
V_16 = F_5 ( V_18 ) ;
V_18 = V_3 [ V_16 ] . V_20 [ 0 ] ;
F_2 ( V_22 , V_18 ) ;
}
}
static inline void F_6 ( void )
{
unsigned int V_16 ;
unsigned int V_23 ;
V_16 = F_5 ( V_24 ) ;
V_23 = V_3 [ V_16 ] . V_20 [ 0 ] ;
F_2 ( V_25 , V_23 ) ;
}
static inline void F_7 ( void )
{
unsigned int V_16 ;
unsigned int V_23 ;
V_16 = F_5 ( V_26 ) ;
V_23 = V_3 [ V_16 ] . V_20 [ 0 ] ;
F_2 ( V_27 , V_23 ) ;
}
static inline void F_8 ( void )
{
unsigned int V_16 ;
T_2 unsigned int V_28 ;
V_16 = F_5 ( V_28 ) ;
V_28 = V_3 [ V_16 ] . V_29 ;
F_9 ( V_28 ) ;
}
static inline void F_10 ( void )
{
unsigned int V_16 ;
unsigned int V_30 ;
V_16 = F_5 ( V_30 ) ;
V_30 = V_3 [ V_16 ] . V_20 [ 0 ] ;
F_2 ( V_31 , V_30 ) ;
}
static inline void F_11 ( void )
{
unsigned int V_16 ;
unsigned int V_32 ;
V_16 = F_5 ( V_32 ) ;
V_32 = V_3 [ V_16 ] . V_20 [ 0 ] ;
F_2 ( V_33 , V_32 ) ;
}
static inline void F_12 ( void )
{
unsigned int V_16 ;
unsigned int V_34 ;
V_16 = F_5 ( V_34 ) ;
V_34 = V_3 [ V_16 ] . V_20 [ 0 ] ;
F_2 ( V_35 , V_34 ) ;
}
static inline void F_13 ( void )
{
extern void V_36 ( void ) ;
unsigned int * V_37 = ( unsigned int * ) V_36 ;
unsigned int V_16 ;
unsigned int V_38 ;
unsigned int V_39 ;
V_16 = F_5 ( V_38 ) ;
V_38 = V_3 [ V_16 ] . V_20 [ 0 ] ;
V_39 = V_3 [ V_16 ] . V_20 [ 1 ] ;
switch ( V_38 ) {
case V_40 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_42 ;
V_37 [ 2 ] = V_43 | V_39 ;
break;
case V_44 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_45 ;
V_37 [ 2 ] = V_43 | V_39 ;
break;
case V_46 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_43 | V_39 ;
V_37 [ 2 ] = V_47 ;
V_37 [ 3 ] = V_48 ;
break;
case V_49 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_42 ;
V_37 [ 2 ] = V_47 ;
V_37 [ 3 ] = V_48 ;
break;
case V_50 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_42 ;
V_37 [ 2 ] = V_47 ;
V_37 [ 3 ] = V_48 ;
break;
case V_51 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_47 ;
V_37 [ 2 ] = V_47 ;
V_37 [ 3 ] = V_48 ;
break;
case V_52 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_45 ;
V_37 [ 2 ] = V_47 ;
V_37 [ 3 ] = V_48 ;
break;
case V_53 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_43 | V_39 ;
break;
case V_54 :
V_37 [ 0 ] = V_41 ;
V_37 [ 1 ] = V_47 ;
V_37 [ 2 ] = V_47 ;
V_37 [ 3 ] = V_48 ;
break;
default:
break;
}
F_14 () ;
}
int main ()
{
T_1 V_1 ;
V_1 . V_9 [ 0 ] = F_15 ( V_55 ) ;
V_1 . V_9 [ 1 ] = F_15 ( V_56 ) ;
F_1 ( V_1 ) ;
F_16 () ;
F_17 () ;
F_18 ( V_1 ) ;
F_3 ( V_1 ) ;
F_19 ( V_1 ) ;
F_20 () ;
F_21 () ;
F_4 () ;
F_22 () ;
F_6 () ;
F_7 () ;
F_8 () ;
F_10 () ;
F_11 () ;
F_12 () ;
F_13 () ;
return 0 ;
}
