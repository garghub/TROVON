static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 , V_8 , V_9 , V_10 ;
V_7 = 1UL << 4 ;
if ( V_4 [ 1 ] . V_11 ) {
V_7 |= ( V_4 [ 1 ] . V_12 & 3 ) << 2 ;
} else {
if ( V_4 [ 0 ] . V_12 == 0 )
V_7 |= 1UL << 2 ;
}
V_2 -> V_13 = V_7 ;
V_2 -> V_14 = 0 ;
V_8 = V_9 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; ++ V_10 ) {
unsigned long V_15 = V_4 [ V_10 ] . V_15 ;
if ( ! V_4 [ V_10 ] . V_11 )
continue;
if ( V_15 > 0x100000 )
V_15 = 0x100000 ;
V_4 [ V_10 ] . V_15 = V_15 ;
V_8 |= ( 0x100000 - V_15 ) << ( V_10 ? 6 : 28 ) ;
if ( V_15 != 0x100000 )
V_9 |= 1 << V_10 ;
}
V_2 -> V_16 = V_8 ;
V_2 -> V_9 = V_9 ;
}
static void
F_2 ( void * V_17 )
{
struct V_1 * V_2 = V_17 ;
F_3 ( 2 , V_2 -> V_13 ) ;
F_3 ( 3 , V_2 -> V_14 ) ;
F_3 ( 6 , V_2 -> V_16 | 3 ) ;
}
static void
F_4 ( struct V_1 * V_2 , unsigned long V_4 )
{
F_3 ( 6 , V_2 -> V_16 | ( 1 << V_4 ) ) ;
}
static inline void
F_5 ( unsigned long V_18 , int V_19 , unsigned long V_20 ,
struct V_3 * V_4 , unsigned long V_12 )
{
unsigned long V_21 = 2 + V_12 ;
if ( V_20 == 1 )
V_21 += V_22 ;
if ( V_4 [ V_21 ] . V_11 )
F_6 ( V_18 , V_19 , V_21 ) ;
}
static void
F_7 ( unsigned long V_23 , struct V_24 * V_25 ,
struct V_3 * V_4 )
{
unsigned long V_26 , V_27 ;
int V_19 = ! F_8 ( V_25 ) ;
int V_28 = 0 ;
union {
unsigned long V_29 ;
struct {
unsigned V_30 : 30 ;
unsigned V_31 : 3 ;
unsigned V_32 : 1 ;
unsigned V_33 : 4 ;
unsigned V_34 : 1 ;
unsigned V_35 : 1 ;
unsigned V_28 : 1 ;
} V_36 ;
} V_37 ;
enum T_1 {
V_38 ,
V_39 ,
V_40 ,
V_41 ,
V_42 ,
V_43 ,
V_44 ,
V_45 ,
V_46 ,
V_47 ,
V_48 ,
V_49 ,
V_50 ,
V_51 ,
V_52 ,
V_53
};
V_26 = F_3 ( 9 , 0 ) ;
if ( V_26 & 1 )
return;
V_26 &= ~ 2 ;
V_37 . V_29 = F_3 ( 8 , 0 ) ;
if ( V_37 . V_36 . V_35 ) {
switch ( V_37 . V_36 . V_33 ) {
case V_47 :
case V_49 :
case V_51 :
F_6 ( V_25 -> V_18 , V_19 , V_23 ) ;
if ( ( V_26 & ( ( 1 << 15 ) - 1 ) ) == 581 )
F_5 ( V_25 -> V_18 , V_19 , V_23 ,
V_4 , V_54 ) ;
return;
case V_38 :
F_5 ( V_26 , V_19 , V_23 , V_4 ,
( V_37 . V_36 . V_34
? V_55 : V_56 ) ) ;
break;
case V_40 :
case V_41 :
case V_44 :
F_5 ( V_26 , V_19 , V_23 , V_4 , V_57 ) ;
break;
case V_43 :
F_5 ( V_26 , V_19 , V_23 , V_4 , V_58 ) ;
break;
case V_39 :
case V_42 :
case V_45 :
case V_46 :
case V_48 :
case V_50 :
case V_52 :
case V_53 :
break;
}
if ( V_37 . V_36 . V_28 ) {
V_28 = 1 ;
F_5 ( V_26 , V_19 , V_23 , V_4 , V_59 ) ;
}
}
F_6 ( V_26 , V_19 , V_23 ) ;
V_27 = F_3 ( 5 , 0 ) ;
if ( V_27 & ( 1UL << 27 ) )
F_5 ( V_26 , V_19 , V_23 , V_4 , V_60 ) ;
if ( ! V_28 && V_27 & ( 1UL << 0 ) )
F_5 ( V_26 , V_19 , V_23 , V_4 , V_61 ) ;
}
