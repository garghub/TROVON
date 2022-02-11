struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_5 , V_4 -> V_6 + F_5 ( V_4 -> V_7 ) ) ;
}
static inline void F_6 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_9 | V_8 , V_4 -> V_6 + F_5 ( V_4 -> V_7 ) ) ;
}
static inline void F_7 ( struct V_2 * V_3 ,
unsigned long V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_8 ( V_10 , V_4 -> V_6 + F_9 ( V_4 -> V_7 ) ) ;
}
static void F_10 ( enum V_11 V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
switch ( V_8 ) {
case V_12 :
F_3 ( V_3 ) ;
F_7 ( V_3 , V_4 -> V_13 ) ;
F_6 ( V_3 , V_14 ) ;
break;
case V_15 :
F_3 ( V_3 ) ;
F_6 ( V_3 , V_16 ) ;
break;
case V_17 :
case V_18 :
default:
F_3 ( V_3 ) ;
break;
}
}
static int F_11 ( unsigned long V_19 ,
struct V_2 * V_3 )
{
F_3 ( V_3 ) ;
F_7 ( V_3 , V_19 ) ;
F_6 ( V_3 , V_16 ) ;
return 0 ;
}
static T_2 F_12 ( int V_20 , void * V_21 )
{
struct V_2 * V_19 = V_21 ;
V_19 -> V_22 ( V_19 ) ;
return V_23 ;
}
static T_3 F_13 ( void )
{
return ~ F_14 ( V_24 . V_6 + F_9 ( V_25 ) ) ;
}
static void T_4 F_15 ( struct V_26 * V_27 )
{
unsigned long V_28 ;
struct V_29 * V_29 ;
int V_30 , V_20 ;
V_24 . V_6 = F_16 ( V_27 , 0 ) ;
if ( ! V_24 . V_6 ) {
F_17 ( L_1 ) ;
return;
}
V_20 = F_18 ( V_27 , V_24 . V_7 ) ;
if ( V_20 <= 0 ) {
F_17 ( L_2 ) ;
return;
}
V_29 = F_19 ( V_27 , 0 ) ;
if ( F_20 ( V_29 ) ) {
F_17 ( L_3 ) ;
return;
}
F_21 ( V_29 ) ;
V_28 = F_22 ( V_29 ) ;
V_24 . V_13 = F_23 ( V_28 , V_31 ) ;
F_4 ( V_5 , V_24 . V_6 + F_5 ( V_25 ) ) ;
F_8 ( V_32 , V_24 . V_6 + F_9 ( V_25 ) ) ;
F_4 ( V_9 , V_24 . V_6 + F_5 ( V_25 ) ) ;
F_24 ( F_13 , 32 , V_28 ) ;
F_25 ( V_24 . V_6 + F_9 ( V_25 ) , V_27 -> V_33 ,
V_28 , 340 , 32 , V_34 ) ;
V_30 = F_26 ( V_20 , F_12 ,
V_35 | V_36 , L_4 ,
& V_24 . V_3 ) ;
if ( V_30 )
F_27 ( L_5 , V_20 , V_30 ) ;
V_24 . V_3 . V_37 = V_38 ;
V_24 . V_3 . V_20 = V_20 ;
F_28 ( & V_24 . V_3 , V_28 , 0 , 0xffffffff ) ;
}
