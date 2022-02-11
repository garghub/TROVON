static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
void T_2 * V_5 ;
if ( V_2 -> V_6 != 0x6145 )
return 1 ;
V_5 = F_2 ( V_2 , 5 , 0x10 ) ;
if ( V_5 == NULL )
return - V_7 ;
F_3 ( L_1 ) ;
for( V_3 = 0 ; V_3 <= 0x0F ; V_3 ++ )
F_3 ( L_2 , V_3 , F_4 ( V_5 + V_3 ) ) ;
F_3 ( L_3 ) ;
V_4 = F_5 ( V_5 + 0x0C ) ;
F_6 ( V_2 , V_5 ) ;
if ( V_4 & 0x10 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , unsigned long V_10 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_1 * V_2 = F_8 ( V_12 -> V_13 -> V_14 ) ;
if ( V_2 -> V_6 == 0x6145 && V_12 -> V_15 == 0 &&
! F_1 ( V_2 ) )
return - V_16 ;
return F_9 ( V_9 , V_10 ) ;
}
static int F_10 ( struct V_11 * V_12 )
{
switch( V_12 -> V_15 )
{
case 0 :
if ( F_4 ( V_12 -> V_17 . V_18 + 1 ) & 1 )
return V_19 ;
return V_20 ;
case 1 :
return V_21 ;
}
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
static const struct V_24 V_25 = {
. V_26 = V_27 ,
. V_28 = V_29 ,
. V_30 = V_31 ,
. V_32 = V_33 ,
. V_34 = & V_35 ,
} ;
static const struct V_24 V_36 = {
. V_26 = V_27 ,
. V_28 = V_29 ,
. V_30 = V_31 ,
. V_32 = V_37 ,
. V_34 = & V_35 ,
} ;
const struct V_24 * V_38 [] = { & V_25 , & V_36 } ;
if ( V_2 -> V_6 == 0x6101 )
V_38 [ 1 ] = & V_39 ;
#if F_13 ( V_40 ) || F_13 ( V_41 )
if ( ! F_1 ( V_2 ) ) {
F_3 (KERN_INFO DRV_NAME L_4 ) ;
return - V_42 ;
}
#endif
return F_14 ( V_2 , V_38 , & V_43 , NULL , 0 ) ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_44 ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_44 ) ;
}
