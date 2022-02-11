static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 - V_4 ) ;
}
static int F_2 ( T_1 V_3 )
{
struct V_5 V_6 , V_7 ;
T_1 V_8 ;
F_3 ( & V_6 ) ;
V_6 . V_9 = V_3 ;
F_4 ( 0x10 , & V_6 , NULL ) ;
V_6 . V_10 = 0x0f ;
F_4 ( 0x10 , & V_6 , & V_7 ) ;
V_11 = 1 ;
V_8 = V_7 . V_9 & 0x7f ;
if ( V_8 == V_3 )
return 0 ;
#ifndef F_5
if ( V_8 != V_12 . V_13 . V_14 ) {
V_6 . V_15 = V_12 . V_13 . V_14 ;
F_4 ( 0x10 , & V_6 , NULL ) ;
}
#endif
return - 1 ;
}
static int F_6 ( void )
{
T_1 V_3 ;
#ifdef F_5
T_1 V_16 = 0x03 ;
#else
T_1 V_16 = V_12 . V_13 . V_14 ;
#endif
T_2 V_17 ;
struct V_1 * V_2 ;
int V_18 = 0 ;
if ( V_19 != V_20 && V_19 != V_21 )
return 0 ;
F_7 ( 0 ) ;
V_17 = F_8 () ;
V_22 . V_23 = F_9 ( struct V_1 , 0 ) ;
for ( V_3 = 0x14 ; V_3 <= 0x7f ; V_3 ++ ) {
if ( ! F_10 ( sizeof( struct V_1 ) ) )
break;
if ( F_11 ( V_4 + V_3 ) )
continue;
if ( F_2 ( V_3 ) )
continue;
if ( F_12 ( 0x3c0 , 0x10 ) & 0x01 )
continue;
if ( F_12 ( 0x3ce , 0x06 ) & 0x01 )
continue;
if ( F_12 ( V_17 , 0x0f ) )
continue;
V_2 = F_9 ( struct V_1 , 1 ) ;
V_2 -> V_3 = V_4 + V_3 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = F_13 ( 0x44a ) ;
V_2 -> V_26 = F_14 ( 0x484 ) + 1 ;
V_18 ++ ;
}
F_2 ( V_16 ) ;
return V_18 ;
}
