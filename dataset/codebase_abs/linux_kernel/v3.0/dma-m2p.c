static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 == 0 ) {
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_8 ) ;
F_2 ( V_4 -> V_9 , V_2 -> V_7 + V_10 ) ;
} else {
F_2 ( V_4 -> V_6 , V_2 -> V_7 + V_11 ) ;
F_2 ( V_4 -> V_9 , V_2 -> V_7 + V_12 ) ;
}
V_2 -> V_5 ^= 1 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_2 -> V_13 = NULL ;
if ( ! F_4 ( & V_2 -> V_14 ) ) {
V_4 = F_5 ( V_2 -> V_14 . V_15 ,
struct V_3 , V_16 ) ;
F_6 ( & V_4 -> V_16 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_13 = V_4 ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_2 -> V_17 = NULL ;
if ( ! F_4 ( & V_2 -> V_14 ) ) {
V_4 = F_5 ( V_2 -> V_14 . V_15 ,
struct V_3 , V_16 ) ;
F_6 ( & V_4 -> V_16 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_17 = V_4 ;
}
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_18 )
{
F_2 ( V_18 , V_2 -> V_7 + V_19 ) ;
F_9 ( V_2 -> V_7 + V_19 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return ( F_9 ( V_2 -> V_7 + V_20 ) >> 4 ) & 0x3 ;
}
static T_2 F_11 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_23 * V_24 ;
T_1 V_25 , V_18 ;
int error = 0 ;
V_24 = V_2 -> V_26 ;
F_12 ( & V_2 -> V_27 ) ;
V_25 = F_9 ( V_2 -> V_7 + V_28 ) ;
if ( V_25 & V_29 ) {
F_2 ( V_29 , V_2 -> V_7 + V_28 ) ;
error = 1 ;
}
if ( ( V_25 & ( V_30 | V_31 ) ) == 0 ) {
F_13 ( & V_2 -> V_27 ) ;
return V_32 ;
}
switch ( F_10 ( V_2 ) ) {
case V_33 :
F_14 ( L_1 ) ;
F_15 () ;
break;
case V_34 :
V_24 -> V_35 ( V_24 -> V_36 , V_2 -> V_13 , 0 , error ) ;
if ( V_2 -> V_17 != NULL ) {
V_24 -> V_35 ( V_24 -> V_36 , V_2 -> V_17 ,
0 , error ) ;
}
F_3 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( V_2 -> V_13 != NULL )
V_24 -> V_37 ( V_24 -> V_36 , V_2 -> V_13 ) ;
break;
case V_38 :
V_24 -> V_35 ( V_24 -> V_36 , V_2 -> V_13 , 0 , error ) ;
V_2 -> V_13 = V_2 -> V_17 ;
F_7 ( V_2 ) ;
V_24 -> V_37 ( V_24 -> V_36 , V_2 -> V_13 ) ;
break;
case V_39 :
F_14 ( L_2 ) ;
F_15 () ;
break;
}
V_18 = F_9 ( V_2 -> V_7 + V_19 ) & ~ ( V_40 |
V_41 ) ;
if ( V_2 -> V_13 != NULL )
V_18 |= V_40 ;
if ( V_2 -> V_17 != NULL )
V_18 |= V_41 ;
F_8 ( V_2 , V_18 ) ;
F_13 ( & V_2 -> V_27 ) ;
return V_42 ;
}
static struct V_1 * F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_24 -> V_44 & V_45 )
V_2 = V_46 ;
else
V_2 = V_47 ;
for ( V_43 = 0 ; V_2 [ V_43 ] . V_7 ; V_43 ++ ) {
struct V_23 * V_26 ;
V_26 = V_2 [ V_43 ] . V_26 ;
if ( V_26 != NULL ) {
int V_48 ;
V_48 = V_24 -> V_44 & V_49 ;
if ( V_48 == ( V_26 -> V_44 &
V_49 ) ) {
F_17 ( L_3 ,
V_24 -> V_50 ? : L_4 ) ;
return F_18 ( - V_51 ) ;
}
}
}
for ( V_43 = 0 ; V_2 [ V_43 ] . V_7 ; V_43 ++ ) {
if ( V_2 [ V_43 ] . V_26 == NULL )
return V_2 + V_43 ;
}
F_17 ( L_5 ,
V_24 -> V_50 ? : L_4 ) ;
return F_18 ( - V_52 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_26 ;
T_1 V_18 ;
F_20 ( V_2 -> V_53 ) ;
V_18 = V_24 -> V_44 & V_49 ;
F_2 ( V_18 , V_2 -> V_7 + V_54 ) ;
V_18 = V_24 -> V_44 & V_55 ;
V_18 |= V_56 | V_57 ;
F_8 ( V_2 , V_18 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_9 ( V_2 -> V_7 + V_19 ) ;
V_18 &= ~ ( V_40 | V_41 ) ;
F_8 ( V_2 , V_18 ) ;
while ( F_10 ( V_2 ) >= V_38 )
F_22 () ;
F_8 ( V_2 , 0x0 ) ;
while ( F_10 ( V_2 ) == V_34 )
F_22 () ;
F_23 ( V_2 -> V_53 ) ;
}
int F_24 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_16 ( V_24 ) ;
if ( F_25 ( V_2 ) )
return F_26 ( V_2 ) ;
V_58 = F_27 ( V_2 -> V_21 , F_11 , 0 , V_24 -> V_50 ? : L_6 , V_2 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_26 = V_24 ;
V_2 -> V_5 = 0 ;
V_2 -> V_13 = NULL ;
V_2 -> V_17 = NULL ;
F_28 ( & V_2 -> V_14 ) ;
V_24 -> V_59 = V_2 ;
F_19 ( V_2 ) ;
return 0 ;
}
void F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_59 ;
F_21 ( V_2 ) ;
F_30 ( V_2 -> V_21 , V_2 ) ;
V_2 -> V_26 = NULL ;
}
void F_31 ( struct V_23 * V_24 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_24 -> V_59 ;
unsigned long V_44 ;
T_1 V_18 ;
F_32 ( & V_2 -> V_27 , V_44 ) ;
V_18 = F_9 ( V_2 -> V_7 + V_19 ) ;
if ( V_2 -> V_13 == NULL ) {
V_2 -> V_13 = V_4 ;
F_1 ( V_2 , V_4 ) ;
V_24 -> V_37 ( V_24 -> V_36 , V_4 ) ;
V_18 |= V_40 ;
F_8 ( V_2 , V_18 ) ;
} else if ( V_2 -> V_17 == NULL ) {
V_2 -> V_17 = V_4 ;
F_1 ( V_2 , V_4 ) ;
V_18 |= V_41 ;
F_8 ( V_2 , V_18 ) ;
} else {
F_33 ( & V_4 -> V_16 , & V_2 -> V_14 ) ;
}
F_34 ( & V_2 -> V_27 , V_44 ) ;
}
void F_35 ( struct V_23 * V_24 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_24 -> V_59 ;
F_33 ( & V_4 -> V_16 , & V_2 -> V_14 ) ;
}
void F_36 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_59 ;
F_21 ( V_2 ) ;
V_2 -> V_5 = 0 ;
V_2 -> V_13 = NULL ;
V_2 -> V_17 = NULL ;
F_28 ( & V_2 -> V_14 ) ;
F_19 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_53 = F_38 ( NULL , V_2 -> V_50 ) ;
if ( F_25 ( V_2 -> V_53 ) )
return F_26 ( V_2 -> V_53 ) ;
F_39 ( & V_2 -> V_27 ) ;
V_2 -> V_26 = NULL ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_43 ;
int V_60 ;
for ( V_43 = 0 ; V_46 [ V_43 ] . V_7 ; V_43 ++ ) {
V_60 = F_37 ( V_46 + V_43 ) ;
if ( V_60 )
return V_60 ;
}
for ( V_43 = 0 ; V_47 [ V_43 ] . V_7 ; V_43 ++ ) {
V_60 = F_37 ( V_47 + V_43 ) ;
if ( V_60 )
return V_60 ;
}
F_41 ( L_7 ) ;
return 0 ;
}
