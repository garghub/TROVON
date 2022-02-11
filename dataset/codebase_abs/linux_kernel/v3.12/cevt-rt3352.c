static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_7 ) ;
V_6 = F_3 ( V_5 -> V_8 + V_9 ) ;
V_6 = ( V_6 + V_1 ) % V_10 ;
F_4 ( V_6 + V_1 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static void F_5 ( struct V_2 * V_7 )
{
}
static T_2 F_6 ( int V_12 , void * V_13 )
{
struct V_2 * V_7 = (struct V_2 * ) V_13 ;
V_7 -> V_14 ( V_7 ) ;
return V_15 ;
}
static void F_7 ( enum V_16 V_17 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , struct V_4 , V_7 ) ;
switch ( V_17 ) {
case V_18 :
if ( ! V_5 -> V_19 )
F_8 ( V_20 . V_7 . V_12 , & V_21 ) ;
V_5 -> V_19 = 1 ;
F_4 ( V_22 | V_23 ,
V_20 . V_8 + V_24 ) ;
break;
case V_25 :
if ( V_5 -> V_19 )
F_9 ( V_20 . V_7 . V_12 , & V_21 ) ;
V_5 -> V_19 = 0 ;
F_4 ( 0 , V_20 . V_8 + V_24 ) ;
break;
default:
F_10 ( L_1 , V_20 . V_7 . V_26 ) ;
break;
}
}
static void T_3 F_11 ( struct V_27 * V_28 )
{
V_20 . V_8 = F_12 ( V_28 , 0 ) ;
if ( ! V_20 . V_8 )
return;
V_21 . V_26 = V_28 -> V_26 ;
V_20 . V_7 . V_26 = V_28 -> V_26 ;
F_13 ( & V_20 . V_7 , V_10 , 60 ) ;
V_20 . V_7 . V_29 = F_14 ( 0x7fff , & V_20 . V_7 ) ;
V_20 . V_7 . V_30 = F_14 ( 0x3 , & V_20 . V_7 ) ;
V_20 . V_7 . V_12 = F_15 ( V_28 , 0 ) ;
if ( ! V_20 . V_7 . V_12 ) {
F_10 ( L_2 , V_28 -> V_26 ) ;
return;
}
F_16 ( V_20 . V_8 + V_9 , V_28 -> V_26 ,
V_10 , 301 , 16 , V_31 ) ;
F_17 ( & V_20 . V_7 ) ;
F_18 ( L_3 ,
V_28 -> V_26 , V_20 . V_7 . V_32 , V_20 . V_7 . V_33 ) ;
}
