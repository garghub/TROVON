static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_4 ^= 1 ;
F_2 ( V_3 -> V_5 ) ;
}
static void F_3 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_6 ^= 1 ;
F_2 ( V_3 -> V_7 ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_3 = & V_13 [ V_11 -> V_14 -> V_15 ] ;
int V_16 = V_9 -> V_17 == V_18 ? 0 : 1 ;
int V_19 , V_20 ;
F_5 ( V_9 , & V_21 ) ;
V_20 = ( V_16 ) ? V_3 -> V_22 + 2 : V_3 -> V_22 ;
if ( V_16 ) {
V_3 -> V_7 = V_9 ;
V_19 = F_6 ( V_20 , F_3 , V_3 ) ;
if ( F_7 ( V_19 ) ) {
F_8 ( L_1 ,
V_11 -> V_14 -> V_15 ) ;
return - V_23 ;
}
( void ) F_6 ( V_20 + 1 , F_3 , V_3 ) ;
} else {
V_3 -> V_5 = V_9 ;
V_19 = F_6 ( V_20 , F_1 , V_3 ) ;
if ( F_7 ( V_19 ) ) {
F_8 ( L_1 ,
V_11 -> V_14 -> V_15 ) ;
return - V_23 ;
}
( void ) F_6 ( V_20 + 1 , F_1 , V_3 ) ;
}
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_3 = & V_13 [ V_11 -> V_14 -> V_15 ] ;
int V_16 = V_9 -> V_17 == V_18 ? 0 : 1 ;
int V_20 ;
V_20 = ( V_16 ) ? V_3 -> V_22 + 2 : V_3 -> V_22 ;
if ( V_16 )
V_3 -> V_7 = NULL ;
else
V_3 -> V_5 = NULL ;
F_10 ( V_20 + 1 ) ;
F_10 ( V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_3 = & V_13 [ V_11 -> V_14 -> V_15 ] ;
int V_16 = V_9 -> V_17 == V_18 ? 0 : 1 ;
int V_19 ;
V_19 = F_12 ( V_9 ,
F_13 ( V_25 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_16 ) {
V_3 -> V_26 = F_14 ( V_25 ) ;
V_3 -> V_6 = 0 ;
} else {
V_3 -> V_27 = F_14 ( V_25 ) ;
V_3 -> V_4 = 0 ;
}
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
return F_16 ( V_9 ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_9 -> V_29 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_3 = & V_13 [ V_11 -> V_14 -> V_15 ] ;
F_8 ( L_2 ,
( V_30 ) V_29 -> V_31 , V_29 -> V_32 ) ;
if ( V_9 -> V_17 == V_18 ) {
F_18 ( V_33 ) = ( unsigned long ) V_29 -> V_34 ;
F_18 ( V_35 ) = V_29 -> V_32 ;
} else {
F_18 ( V_36 ) = ( unsigned long ) V_29 -> V_34 ;
F_18 ( V_37 ) = V_29 -> V_32 ;
}
return 0 ;
}
static inline void F_19 ( struct V_2 * V_3 )
{
unsigned long V_38 = F_18 ( V_39 ) & ~ ( V_40 | V_41 ) ;
F_18 ( V_39 ) = V_38 | V_42 | V_43 | V_44 ;
}
static inline void F_20 ( struct V_2 * V_3 )
{
unsigned long V_38 = F_18 ( V_39 ) & ~ ( V_40 | V_41 ) ;
F_18 ( V_39 ) = V_38 | V_40 ;
}
static inline void F_21 ( struct V_2 * V_3 )
{
unsigned long V_38 = F_18 ( V_39 ) & ~ ( V_40 | V_41 ) ;
F_18 ( V_39 ) = V_38 | V_45 | V_46 | V_47 ;
}
static inline void F_22 ( struct V_2 * V_3 )
{
unsigned long V_38 = F_18 ( V_39 ) & ~ ( V_40 | V_41 ) ;
F_18 ( V_39 ) = V_38 | V_41 ;
}
static int F_23 ( struct V_8 * V_9 , int V_48 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_3 = & V_13 [ V_11 -> V_14 -> V_15 ] ;
int V_16 = V_9 -> V_17 == V_18 ? 0 : 1 ;
switch ( V_48 ) {
case V_49 :
if ( V_16 )
F_21 ( V_3 ) ;
else
F_19 ( V_3 ) ;
break;
case V_50 :
if ( V_16 )
F_22 ( V_3 ) ;
else
F_20 ( V_3 ) ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static T_1 F_24 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_9 -> V_29 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_2 * V_3 = & V_13 [ V_11 -> V_14 -> V_15 ] ;
int V_16 = V_9 -> V_17 == V_18 ? 0 : 1 ;
unsigned long V_52 ;
if ( V_16 )
V_52 = V_3 -> V_6 ? V_3 -> V_26 : 0 ;
else
V_52 = V_3 -> V_4 ? V_3 -> V_27 : 0 ;
return F_25 ( V_29 , V_52 ) ;
}
static void F_26 ( struct V_53 * V_54 )
{
F_27 ( V_54 ) ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_53 * V_54 = V_11 -> V_54 ;
F_29 ( V_54 ,
V_55 ,
F_30 ( V_56 ) ,
V_57 , V_58 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_60 )
{
return F_32 ( & V_60 -> V_61 , & V_62 ) ;
}
static int F_33 ( struct V_59 * V_60 )
{
F_34 ( & V_60 -> V_61 ) ;
return 0 ;
}
