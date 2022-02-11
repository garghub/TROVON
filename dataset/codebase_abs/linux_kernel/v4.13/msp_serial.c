static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_2 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_4 ( V_2 -> V_11 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 = F_4 ( V_2 -> V_11 + ( V_13 << V_2 -> V_10 ) ) ;
if ( F_6 ( V_2 , V_12 ) ) {
return 1 ;
} else if ( ( V_12 & V_14 ) == V_14 ) {
( void ) F_4 ( V_2 -> V_11 + 0xc0 ) ;
F_2 ( V_6 -> V_9 , V_2 -> V_11 + ( V_8 << V_2 -> V_10 ) ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_7 ( void )
{
char * V_15 ;
char * V_16 ;
struct V_1 V_17 ;
unsigned int V_18 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_15 = F_8 ( L_1 ) ;
if( ! ( V_15 && * V_15 && ( V_18 = F_9 ( V_15 , & V_16 , 10 ) ) && * V_16 == 0 ) )
V_18 = V_19 ;
F_10 ( L_2 , V_18 ) ;
V_17 . V_20 = V_21 ;
V_17 . V_11 = F_11 ( V_17 . V_20 , V_22 ) ;
V_17 . V_23 = V_24 ;
V_17 . V_18 = V_18 ;
V_17 . V_10 = 2 ;
V_17 . V_25 = V_26 ;
V_17 . V_27 = V_28 | V_29 ;
V_17 . type = V_30 ;
V_17 . line = 0 ;
V_17 . V_31 = F_1 ;
V_17 . V_32 = F_3 ;
V_17 . V_33 = F_5 ;
V_17 . V_7 = F_12 ( sizeof( struct V_5 ) , V_34 ) ;
if ( ! V_17 . V_7 ) {
F_13 ( L_3 ) ;
return;
}
if ( F_14 ( & V_17 ) ) {
F_15 ( V_17 . V_7 ) ;
F_13 ( L_4 ) ;
}
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
* V_42 = 0x00002299 ;
break;
default:
return;
}
V_17 . V_20 = V_43 ;
V_17 . V_11 = F_11 ( V_17 . V_20 , V_22 ) ;
V_17 . V_23 = V_44 ;
V_17 . line = 1 ;
V_17 . V_7 = ( void * ) V_45 ;
if ( F_14 ( & V_17 ) ) {
F_15 ( V_17 . V_7 ) ;
F_13 ( L_5 ) ;
}
}
