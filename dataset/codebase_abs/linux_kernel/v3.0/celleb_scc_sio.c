static int T_1 F_1 ( void )
{
extern int V_1 ( struct V_2 * V_3 ) ;
struct V_4 * V_5 = NULL ;
int V_6 ;
struct V_2 V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
while ( ( V_5 = F_2 ( V_5 ,
L_1 , L_2 ) ) != NULL ) {
for ( V_6 = 0 ; V_6 < F_3 ( V_12 ) ; V_6 ++ ) {
if ( ! ( V_13 & ( 1 << V_6 ) ) )
continue;
if ( F_4 ( V_5 , V_6 , & V_9 ) )
continue;
if ( F_5 ( V_5 ,
V_12 [ V_6 ] . V_14 , & V_11 ) )
continue;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . line = V_6 ;
V_7 . V_15 = V_16 ;
V_7 . V_17 = V_11 . V_18 + V_12 [ V_6 ] . V_19 ;
#ifdef F_6
V_7 . V_20 = F_7 ( V_7 . V_17 , 0x24 ) ;
#endif
V_7 . V_9 = F_8 ( V_9 . V_21 ,
V_9 . V_22 , V_9 . V_23 ) ;
V_7 . V_24 |= V_25 | V_26
;
V_7 . V_27 = 83300000 ;
V_1 ( & V_7 ) ;
}
}
return 0 ;
}
static int T_1 F_9 ( char * V_28 )
{
int V_6 ;
for (; ; ) {
switch ( F_10 ( & V_28 , & V_6 ) ) {
default:
return 0 ;
case 2 :
V_13 |= 1 << V_6 ;
break;
case 1 :
V_13 |= 1 << V_6 ;
return 0 ;
}
}
}
