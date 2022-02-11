static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( enum V_2 V_3 ,
struct V_4 * V_5 )
{
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
break;
default:
F_4 ( 1 , L_1 , V_10 , V_3 ) ;
break;
}
}
static int F_5 ( unsigned long V_11 ,
struct V_4 * V_5 )
{
struct V_12 * V_13 = F_6 ( V_5 ,
struct V_12 , V_14 ) ;
F_7 ( F_2 ( V_1 ) + V_11 ,
V_13 -> V_15 ) ;
return 0 ;
}
static T_3 F_8 ( int V_16 , void * V_17 )
{
struct V_12 * V_13 = V_17 ;
void (* F_9)( struct V_4 * );
if ( F_2 ( V_13 -> V_18 ) & V_13 -> V_19 ) {
F_7 ( V_13 -> V_19 , V_13 -> V_18 ) ;
F_9 = F_10 ( V_13 -> V_14 . F_9 ) ;
if ( F_9 )
F_9 ( & V_13 -> V_14 ) ;
return V_20 ;
} else {
return V_21 ;
}
}
static void T_4 F_11 ( struct V_22 * V_23 )
{
void T_5 * V_24 ;
T_6 V_25 ;
int V_16 ;
struct V_12 * V_13 ;
V_24 = F_12 ( V_23 , 0 ) ;
if ( ! V_24 )
F_13 ( L_2 ) ;
if ( F_14 ( V_23 , L_3 , & V_25 ) )
F_13 ( L_4 ) ;
V_1 = V_24 + V_26 ;
F_15 ( F_1 , 32 , V_25 ) ;
F_16 ( V_24 + V_26 , V_23 -> V_27 ,
V_25 , 300 , 32 , V_28 ) ;
V_16 = F_17 ( V_23 , V_29 ) ;
if ( V_16 <= 0 )
F_13 ( L_5 ) ;
V_13 = F_18 ( sizeof( * V_13 ) , V_30 ) ;
if ( ! V_13 )
F_13 ( L_6 ) ;
V_13 -> V_18 = V_24 + V_31 ;
V_13 -> V_15 = V_24 + F_19 ( V_29 ) ;
V_13 -> V_19 = F_20 ( V_29 ) ;
V_13 -> V_14 . V_27 = V_23 -> V_27 ;
V_13 -> V_14 . V_32 = 300 ;
V_13 -> V_14 . V_33 = V_34 ;
V_13 -> V_14 . V_35 = F_3 ;
V_13 -> V_14 . V_36 = F_5 ;
V_13 -> V_14 . V_37 = F_21 ( 0 ) ;
V_13 -> V_38 . V_27 = V_23 -> V_27 ;
V_13 -> V_38 . V_39 = V_40 | V_41 ;
V_13 -> V_38 . V_17 = V_13 ;
V_13 -> V_38 . V_42 = F_8 ;
if ( F_22 ( V_16 , & V_13 -> V_38 ) )
F_13 ( L_7 ) ;
F_23 ( & V_13 -> V_14 , V_25 , 0xf , 0xffffffff ) ;
F_24 ( L_8 , V_16 ) ;
}
