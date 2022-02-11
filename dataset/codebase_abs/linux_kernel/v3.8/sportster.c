static inline int
F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return ( V_1 + ( ( V_2 & 0xfc ) << 8 ) + ( ( V_2 & 3 ) << 1 ) ) ;
}
static inline void
F_2 ( unsigned int V_3 , T_1 * V_4 , int V_5 )
{
F_3 ( V_3 , V_4 , V_5 ) ;
}
static void
F_4 ( unsigned int V_3 , T_1 * V_4 , int V_5 )
{
F_5 ( V_3 , V_4 , V_5 ) ;
}
static T_1
F_6 ( struct V_6 * V_7 , T_1 V_8 )
{
return ( F_7 ( F_1 ( V_7 -> V_9 . V_10 . V_11 , V_8 ) ) ) ;
}
static void
F_8 ( struct V_6 * V_7 , T_1 V_8 , T_1 V_12 )
{
F_9 ( F_1 ( V_7 -> V_9 . V_10 . V_11 , V_8 ) , V_12 ) ;
}
static void
F_10 ( struct V_6 * V_7 , T_1 * V_4 , int V_5 )
{
F_2 ( V_7 -> V_9 . V_10 . V_11 , V_4 , V_5 ) ;
}
static void
F_11 ( struct V_6 * V_7 , T_1 * V_4 , int V_5 )
{
F_4 ( V_7 -> V_9 . V_10 . V_11 , V_4 , V_5 ) ;
}
static T_1
F_12 ( struct V_6 * V_7 , int V_13 , T_1 V_8 )
{
return ( F_7 ( F_1 ( V_7 -> V_9 . V_10 . V_13 [ V_13 ] , V_8 ) ) ) ;
}
static void
F_13 ( struct V_6 * V_7 , int V_13 , T_1 V_8 , T_1 V_12 )
{
F_9 ( F_1 ( V_7 -> V_9 . V_10 . V_13 [ V_13 ] , V_8 ) , V_12 ) ;
}
static T_2
F_14 ( int V_14 , void * V_15 )
{
struct V_6 * V_7 = V_15 ;
T_1 V_16 ;
T_3 V_17 ;
F_15 ( & V_7 -> V_18 , V_17 ) ;
V_16 = F_16 ( V_7 , 1 , V_19 ) ;
V_20:
if ( V_16 )
F_17 ( V_7 , V_16 ) ;
V_16 = F_6 ( V_7 , V_21 ) ;
V_22:
if ( V_16 )
F_18 ( V_7 , V_16 ) ;
V_16 = F_16 ( V_7 , 1 , V_19 ) ;
if ( V_16 ) {
if ( V_7 -> V_23 & V_24 )
F_19 ( V_7 , L_1 ) ;
goto V_20;
}
V_16 = F_6 ( V_7 , V_21 ) ;
if ( V_16 ) {
if ( V_7 -> V_23 & V_25 )
F_19 ( V_7 , L_2 ) ;
goto V_22;
}
F_7 ( V_7 -> V_9 . V_10 . V_26 + V_27 + 1 ) ;
F_20 ( & V_7 -> V_18 , V_17 ) ;
return V_28 ;
}
static void
F_21 ( struct V_6 * V_7 )
{
int V_29 , V_3 ;
F_9 ( V_7 -> V_9 . V_10 . V_26 + V_27 , 0 ) ;
for ( V_29 = 0 ; V_29 < 64 ; V_29 ++ ) {
V_3 = V_7 -> V_9 . V_10 . V_26 + V_29 * 1024 ;
F_22 ( V_3 , 8 ) ;
}
}
static void
F_23 ( struct V_6 * V_7 )
{
V_7 -> V_9 . V_10 . V_30 |= V_31 ;
F_9 ( V_7 -> V_9 . V_10 . V_26 + V_27 , V_7 -> V_9 . V_10 . V_30 ) ;
F_24 ( 10 ) ;
V_7 -> V_9 . V_10 . V_30 &= ~ V_31 ;
F_9 ( V_7 -> V_9 . V_10 . V_26 + V_27 , V_7 -> V_9 . V_10 . V_30 ) ;
F_24 ( 10 ) ;
}
static int
F_25 ( struct V_6 * V_7 , int V_32 , void * V_33 )
{
T_3 V_17 ;
switch ( V_32 ) {
case V_34 :
F_15 ( & V_7 -> V_18 , V_17 ) ;
F_23 ( V_7 ) ;
F_20 ( & V_7 -> V_18 , V_17 ) ;
return ( 0 ) ;
case V_35 :
F_21 ( V_7 ) ;
return ( 0 ) ;
case V_36 :
F_15 ( & V_7 -> V_18 , V_17 ) ;
F_23 ( V_7 ) ;
F_26 ( V_7 , 1 ) ;
V_7 -> V_9 . V_10 . V_30 |= V_37 ;
F_9 ( V_7 -> V_9 . V_10 . V_26 + V_27 , V_7 -> V_9 . V_10 . V_30 ) ;
F_26 ( V_7 , 2 ) ;
F_20 ( & V_7 -> V_18 , V_17 ) ;
return ( 0 ) ;
case V_38 :
return ( 0 ) ;
}
return ( 0 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
int V_29 , V_39 , V_3 ;
for ( V_29 = 0 ; V_29 < 64 ; V_29 ++ ) {
V_3 = V_7 -> V_9 . V_10 . V_26 + V_29 * 1024 ;
if ( ! F_28 ( V_3 , 8 , L_3 ) ) {
F_29 ( V_40 L_4
L_5 ,
V_3 , V_3 + 8 ) ;
break;
}
}
if ( V_29 == 64 )
return ( 1 ) ;
else {
for ( V_39 = 0 ; V_39 < V_29 ; V_39 ++ ) {
V_3 = V_7 -> V_9 . V_10 . V_26 + V_39 * 1024 ;
F_22 ( V_3 , 8 ) ;
}
return ( 0 ) ;
}
}
int F_30 ( struct V_41 * V_42 )
{
struct V_6 * V_7 = V_42 -> V_7 ;
char V_43 [ 64 ] ;
strcpy ( V_43 , V_44 ) ;
F_29 ( V_45 L_6 , F_31 ( V_43 ) ) ;
if ( V_7 -> V_46 != V_47 )
return ( 0 ) ;
V_7 -> V_9 . V_10 . V_26 = V_42 -> V_48 [ 1 ] ;
V_7 -> V_49 = V_42 -> V_48 [ 0 ] ;
if ( ! F_27 ( V_7 ) )
return ( 0 ) ;
V_7 -> V_9 . V_10 . V_11 = V_7 -> V_9 . V_10 . V_26 + V_50 ;
V_7 -> V_9 . V_10 . V_13 [ 0 ] = V_7 -> V_9 . V_10 . V_26 + V_51 ;
V_7 -> V_9 . V_10 . V_13 [ 1 ] = V_7 -> V_9 . V_10 . V_26 + V_52 ;
switch ( V_7 -> V_49 ) {
case 5 : V_7 -> V_9 . V_10 . V_30 = 1 ;
break;
case 7 : V_7 -> V_9 . V_10 . V_30 = 2 ;
break;
case 10 : V_7 -> V_9 . V_10 . V_30 = 3 ;
break;
case 11 : V_7 -> V_9 . V_10 . V_30 = 4 ;
break;
case 12 : V_7 -> V_9 . V_10 . V_30 = 5 ;
break;
case 14 : V_7 -> V_9 . V_10 . V_30 = 6 ;
break;
case 15 : V_7 -> V_9 . V_10 . V_30 = 7 ;
break;
default: F_21 ( V_7 ) ;
F_29 ( V_40 L_7 ) ;
return ( 0 ) ;
}
F_29 ( V_45 L_8 ,
V_7 -> V_49 , V_7 -> V_9 . V_10 . V_26 ) ;
F_32 ( V_7 ) ;
V_7 -> V_53 = & F_6 ;
V_7 -> V_54 = & F_8 ;
V_7 -> V_55 = & F_10 ;
V_7 -> V_56 = & F_11 ;
V_7 -> V_57 = & F_12 ;
V_7 -> V_58 = & F_13 ;
V_7 -> V_59 = & V_60 ;
V_7 -> V_61 = & F_25 ;
V_7 -> V_62 = & F_14 ;
F_33 ( V_7 , L_9 ) ;
if ( F_34 ( V_7 , L_9 ) ) {
F_29 ( V_40
L_10 ) ;
F_21 ( V_7 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
