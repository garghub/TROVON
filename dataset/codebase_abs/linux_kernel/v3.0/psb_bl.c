int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
int V_6 = V_2 -> V_7 . V_8 ;
F_3 ( L_1 , V_6 ) ;
if ( V_6 < 1 )
V_6 = 1 ;
F_4 ( V_4 , V_6 ) ;
V_9 = V_6 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_10 * V_11 = V_4 -> V_12 ;
int V_6 = V_2 -> V_7 . V_8 ;
T_1 V_13 ;
T_1 V_14 ;
F_3 ( L_1 , V_6 ) ;
if ( V_6 < 1 )
V_6 = 1 ;
if ( F_6 ( V_4 , 0 ) ) {
V_14 = F_7 ( V_15 ) >> 16 ;
V_13 = V_6 * V_14 / 100 ;
V_13 = V_13 * V_11 -> V_16 ;
V_13 = V_13 / 100 ;
V_13 = V_13 * V_11 -> V_17 ;
V_13 = V_13 / 100 ;
if ( V_18 == V_19 )
V_13 = V_14 - V_13 ;
F_8 ( V_20 , ( 0x80000000 | F_7 ( V_20 ) ) ) ;
F_8 ( V_15 , ( V_14 << 16 ) | V_13 ) ;
F_9 ( V_4 ) ;
}
V_9 = V_6 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
F_3 ( L_2 , V_9 ) ;
return V_9 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned long V_21 ;
T_2 V_22 ;
T_3 V_23 ;
T_3 V_24 ;
if ( F_12 ( V_4 ) ) {
V_11 -> V_16 = V_25 ;
V_11 -> V_17 = V_25 ;
V_22 = 256 ;
V_18 = V_26 ;
V_24 = V_27 ;
} else {
if ( ! V_11 -> V_28 ) {
F_13 ( L_3 ) ;
return 1 ;
}
V_22 = V_11 -> V_28 -> V_29 ;
V_18 = V_11 -> V_28 -> V_30 ;
V_24 = V_31 ;
V_32 = V_11 -> V_28 -> V_33 ;
V_34 = V_11 -> V_28 -> type ;
}
V_21 = V_11 -> V_35 ;
V_23 = ( V_21 * V_36 ) / V_37 ;
V_23 *= V_24 ;
V_23 /= V_22 ;
V_23 /= V_24 ;
if ( F_6 ( V_4 , false ) ) {
if ( F_12 ( V_4 ) ) {
if ( V_23 > ( unsigned long long ) V_38 )
return 2 ;
else {
F_8 ( V_20 ,
( 0x80000000 | F_7 ( V_20 ) ) ) ;
F_8 ( V_15 , V_23 | ( V_23 << 16 ) ) ;
}
} else {
if ( V_23 > ( unsigned long long ) V_39 ||
V_23 < ( unsigned long long ) V_40 )
return 2 ;
else {
V_23 &= V_41 ;
F_8 ( V_15 ,
( V_23 << V_42 ) |
( V_23 ) ) ;
}
}
F_9 ( V_4 ) ;
}
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
#ifdef F_15
int V_43 = 0 ;
struct V_44 V_7 ;
memset ( & V_7 , 0 , sizeof( struct V_44 ) ) ;
V_7 . V_45 = 100 ;
V_7 . type = V_46 ;
V_5 = F_16 ( L_4 , NULL ,
( void * ) V_4 , & V_47 , & V_7 ) ;
if ( F_17 ( V_5 ) )
return F_18 ( V_5 ) ;
V_43 = F_11 ( V_4 ) ;
if ( V_43 < 0 )
return V_43 ;
V_5 -> V_7 . V_8 = 100 ;
V_5 -> V_7 . V_45 = 100 ;
F_19 ( V_5 ) ;
#endif
return 0 ;
}
void F_20 ( void )
{
#ifdef F_15
V_5 -> V_7 . V_8 = 0 ;
F_19 ( V_5 ) ;
F_21 ( V_5 ) ;
#endif
}
struct V_1 * F_22 ( void )
{
return V_5 ;
}
