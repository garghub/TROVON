static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_2 , V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_4 ( V_2 -> V_2 , V_3 ) ;
}
static inline T_3 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_6 ( V_2 -> V_2 , V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_4 )
{
F_8 ( V_2 -> V_2 , V_3 , V_4 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
T_2 V_3 , T_2 V_4 )
{
F_10 ( V_2 -> V_2 , V_3 , V_4 ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
T_2 V_3 , T_3 V_4 )
{
F_12 ( V_2 -> V_2 , V_3 , V_4 ) ;
}
static inline
T_1 F_13 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_14 ( V_3 >= 256 ) ;
return F_1 ( V_2 , V_5 + V_3 ) ;
}
static inline
T_2 F_15 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_14 ( V_3 >= 256 ) ;
return F_3 ( V_2 , V_5 + V_3 ) ;
}
static inline
T_3 F_16 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_14 ( V_3 >= 256 ) ;
return F_5 ( V_2 , V_5 + V_3 ) ;
}
static inline
void F_17 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_14 ( V_3 >= 256 ) ;
F_7 ( V_2 , V_5 + V_3 , V_4 ) ;
}
static inline
void F_18 ( struct V_1 * V_2 ,
unsigned int V_3 , T_2 V_4 )
{
F_14 ( V_3 >= 256 ) ;
F_9 ( V_2 , V_5 + V_3 , V_4 ) ;
}
static inline
void F_19 ( struct V_1 * V_2 ,
unsigned int V_3 , T_3 V_4 )
{
F_14 ( V_3 >= 256 ) ;
F_11 ( V_2 , V_5 + V_3 , V_4 ) ;
}
static int T_4 F_20 ( struct V_6 * V_7 ,
unsigned int V_8 , int V_9 ,
int V_10 , T_3 * V_11 )
{
struct V_1 * V_2 = F_21 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
unsigned long V_14 ;
if ( ( F_22 ( V_8 ) > 0 ) || ( F_23 ( V_8 ) > 0 ) )
return V_15 ;
if ( V_9 >= 256 )
return V_15 ;
F_24 ( & V_2 -> V_16 , V_14 ) ;
switch ( V_10 ) {
case 1 :
* V_11 = F_13 ( V_2 , V_9 ) ;
break;
case 2 :
* V_11 = F_15 ( V_2 , V_9 ) ;
break;
case 4 :
* V_11 = F_16 ( V_2 , V_9 ) ;
break;
default:
F_25 ( 1 ) ;
}
F_26 ( & V_2 -> V_16 , V_14 ) ;
return V_17 ;
}
static int T_4 F_27 ( struct V_6 * V_7 ,
unsigned int V_8 , int V_9 ,
int V_10 , T_3 V_11 )
{
struct V_1 * V_2 = F_21 ( V_7 -> V_12 , struct V_1 , V_13 ) ;
unsigned long V_14 ;
if ( ( F_22 ( V_8 ) > 0 ) || ( F_23 ( V_8 ) > 0 ) )
return V_15 ;
if ( V_9 >= 256 )
return V_15 ;
F_24 ( & V_2 -> V_16 , V_14 ) ;
switch ( V_10 ) {
case 1 :
F_17 ( V_2 , V_9 , V_11 ) ;
break;
case 2 :
F_18 ( V_2 , V_9 , V_11 ) ;
break;
case 4 :
F_19 ( V_2 , V_9 , V_11 ) ;
break;
default:
F_25 ( 1 ) ;
}
F_26 ( & V_2 -> V_16 , V_14 ) ;
return V_17 ;
}
static int T_4 F_28 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
T_3 V_22 , V_23 , V_24 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
V_2 -> V_2 = V_19 ;
F_30 ( & V_2 -> V_16 ) ;
V_2 -> V_27 . V_13 = & V_2 -> V_13 ;
V_2 -> V_27 . V_28 = & V_2 -> V_28 ;
V_2 -> V_27 . V_29 = & V_2 -> V_29 ;
V_2 -> V_27 . V_30 = 0x800 ;
V_2 -> V_13 . V_31 = F_20 ;
V_2 -> V_13 . V_32 = F_27 ;
V_2 -> V_28 . V_33 = V_34 ;
V_2 -> V_28 . V_35 = 0x800 ;
V_2 -> V_28 . V_36 = 0x8FF ;
V_2 -> V_28 . V_14 = V_37 | V_38 ;
if ( ! F_31 ( V_19 ) )
F_32 ( V_19 , 0 ) ;
V_22 = F_33 ( F_6 ( V_19 , V_39 ) ) ;
F_19 ( V_2 , V_40 , V_22 ) ;
F_19 ( V_2 , V_41 , 0 ) ;
V_2 -> V_29 . V_33 = V_42 ;
V_2 -> V_29 . V_35 = V_22 ;
V_2 -> V_29 . V_36 = V_22 + 0x10000 - 1 ;
V_2 -> V_29 . V_14 = V_43 | V_38 ;
F_18 ( V_2 , V_44 ,
F_15 ( V_2 , V_44 )
| V_45 ) ;
F_11 ( V_2 , V_46 , 0x00000068 ) ;
V_23 = F_6 ( V_19 , V_47 ) ;
V_24 = F_6 ( V_19 , V_48 ) ;
if ( V_24 & V_49 ) {
V_23 &= ~ V_50 ;
V_23 &= ~ V_51 ;
V_2 -> V_52 = 1 ;
} else {
V_23 |= V_50 ;
V_23 |= V_51 ;
V_2 -> V_52 = 0 ;
}
V_23 |= V_53 ;
F_12 ( V_19 , V_47 , V_23 ) ;
F_34 ( V_19 , V_2 ) ;
F_35 ( & V_2 -> V_27 ) ;
return 0 ;
}
bool F_36 ( struct V_54 * V_55 )
{
if ( ! V_55 -> V_56 [ 0 ] . V_33 )
return 0 ;
return ( strcmp ( V_55 -> V_56 [ 0 ] . V_33 , V_42 ) == 0 ) ;
}
int F_37 ( struct V_18 * V_19 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_38 ( V_19 ) ;
struct V_56 * V_57 ;
if ( V_55 -> V_7 -> V_12 != & V_2 -> V_13 ) {
return - V_58 ;
}
V_57 = & ( V_55 -> V_56 [ 0 ] ) ;
V_57 -> V_14 = V_43 | V_38 ;
V_57 -> V_33 = V_2 -> V_29 . V_33 ;
V_57 -> V_35 = V_2 -> V_29 . V_35 ;
V_57 -> V_36 = V_2 -> V_29 . V_36 ;
V_55 -> V_59 = F_39 ( V_19 ) + 2 ;
F_40 ( V_55 , V_60 , V_55 -> V_59 ) ;
return 0 ;
}
int F_41 ( struct V_18 * V_19 ,
const struct V_54 * V_55 )
{
struct V_1 * V_2 = F_38 ( V_19 ) ;
if ( V_55 -> V_7 -> V_12 != & V_2 -> V_13 ) {
return - V_58 ;
}
return F_39 ( V_19 ) + 2 ;
}
int F_42 ( void )
{
return F_43 ( & V_61 ) ;
}
