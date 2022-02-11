static long F_1 ( T_1 V_1 )
{
T_1 V_2 ;
T_2 V_3 ;
long V_4 ;
V_2 = V_1 >> 11 ;
V_3 = ( ( T_1 ) ( ( V_1 & 0x7ff ) << 5 ) ) >> 5 ;
V_4 = V_3 ;
V_4 = V_4 * 1000L ;
if ( V_2 >= 0 )
V_4 <<= V_2 ;
else
V_4 >>= - V_2 ;
return V_4 ;
}
static T_3 F_2 ( long V_4 )
{
T_1 V_2 = 0 , V_3 ;
bool V_5 = false ;
if ( V_4 == 0 )
return 0 ;
if ( V_4 < 0 ) {
V_5 = true ;
V_4 = - V_4 ;
}
while ( V_4 >= V_6 && V_2 < 15 ) {
V_2 ++ ;
V_4 >>= 1 ;
}
while ( V_4 < V_7 && V_2 > - 15 ) {
V_2 -- ;
V_4 <<= 1 ;
}
V_3 = F_3 ( V_4 , 1000 ) ;
if ( V_3 > 0x3ff )
V_3 = 0x3ff ;
if ( V_5 )
V_3 = - V_3 ;
return ( V_3 & 0x7ff ) | ( ( V_2 << 11 ) & 0xf800 ) ;
}
static inline void F_4 ( const struct V_8 * V_9 )
{
if ( V_9 -> V_10 ) {
T_4 V_11 = F_5 ( F_6 () , V_9 -> V_12 ) ;
if ( V_11 < V_9 -> V_10 )
F_7 ( V_9 -> V_10 - V_11 ) ;
}
}
static int F_8 ( struct V_13 * V_14 , int V_15 , int V_16 )
{
const struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_8 * V_9 = F_10 ( V_18 ) ;
int V_19 , V_20 ;
if ( V_15 > 0 )
return - V_21 ;
if ( V_9 -> V_22 == V_23 ) {
switch ( V_16 ) {
case V_24 :
case V_25 :
case V_26 :
return - V_21 ;
}
}
switch ( V_16 ) {
case V_27 :
V_20 = V_28 ;
break;
case V_29 :
case V_30 :
V_20 = V_31 ;
break;
case V_32 :
case V_33 :
V_20 = V_34 ;
break;
default:
if ( V_16 >= V_35 )
return - V_21 ;
V_20 = V_16 ;
break;
}
F_4 ( V_9 ) ;
V_19 = F_11 ( V_14 , V_15 , V_20 ) ;
V_9 -> V_12 = F_6 () ;
if ( V_19 < 0 )
return V_19 ;
switch ( V_16 ) {
case V_29 :
V_19 = F_2 ( F_3 ( F_1 ( V_19 ) * 9 , 10 ) ) ;
break;
case V_32 :
V_19 = F_2 ( F_3 ( F_1 ( V_19 ) * 11 , 10 ) ) ;
break;
}
return V_19 ;
}
static int F_12 ( struct V_13 * V_14 , int V_15 , int V_16 )
{
const struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_8 * V_9 = F_10 ( V_18 ) ;
int V_19 , V_36 ;
if ( V_15 > 0 )
return - V_21 ;
F_4 ( V_9 ) ;
switch ( V_16 ) {
case V_37 :
V_19 = F_13 ( V_14 , 0 ,
V_38 ) ;
if ( V_19 < 0 )
break;
V_36 = 0 ;
if ( V_19 & V_39 )
V_36 |= V_40 ;
if ( V_19 & V_41 )
V_36 |= V_42 ;
if ( V_19 & V_43 )
V_36 |= V_44 ;
if ( V_19 & V_45 )
V_36 |= V_46 ;
V_19 = V_36 ;
break;
default:
V_19 = F_13 ( V_14 , V_15 , V_16 ) ;
break;
}
V_9 -> V_12 = F_6 () ;
return V_19 ;
}
static int F_14 ( struct V_13 * V_14 , int V_15 , int V_16 ,
T_3 V_47 )
{
const struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_8 * V_9 = F_10 ( V_18 ) ;
int V_19 , V_20 ;
if ( V_15 > 0 )
return - V_21 ;
switch ( V_16 ) {
case V_29 :
V_47 = F_2 ( F_3 ( F_1 ( V_47 ) * 10 , 9 ) ) ;
V_20 = V_31 ;
F_15 ( V_14 ) ;
break;
case V_30 :
V_20 = V_31 ;
F_15 ( V_14 ) ;
break;
case V_32 :
V_47 = F_2 ( F_3 ( F_1 ( V_47 ) * 10 , 11 ) ) ;
V_20 = V_34 ;
F_15 ( V_14 ) ;
break;
case V_33 :
V_20 = V_34 ;
F_15 ( V_14 ) ;
break;
default:
if ( V_16 >= V_35 )
return - V_21 ;
V_20 = V_16 ;
}
F_4 ( V_9 ) ;
V_19 = F_16 ( V_14 , V_15 , V_20 , V_47 ) ;
V_9 -> V_12 = F_6 () ;
return V_19 ;
}
static int F_17 ( struct V_13 * V_14 , int V_15 , T_5 V_48 )
{
const struct V_17 * V_18 = F_9 ( V_14 ) ;
struct V_8 * V_9 = F_10 ( V_18 ) ;
int V_19 ;
if ( V_15 > 0 )
return - V_21 ;
F_4 ( V_9 ) ;
V_19 = F_18 ( V_14 , V_15 , V_48 ) ;
V_9 -> V_12 = F_6 () ;
return V_19 ;
}
static int F_19 ( struct V_13 * V_14 ,
const struct V_49 * V_22 )
{
int V_19 ;
struct V_8 * V_9 ;
struct V_17 * V_18 ;
T_5 V_50 [ V_51 + 1 ] ;
const struct V_49 * V_52 ;
if ( ! F_20 ( V_14 -> V_53 ,
V_54
| V_55 ) )
return - V_56 ;
V_19 = F_21 ( V_14 , V_57 ,
V_50 ) ;
if ( V_19 < 0 ) {
F_22 ( & V_14 -> V_58 , L_1 ) ;
return V_19 ;
}
V_50 [ V_19 ] = '\0' ;
F_23 ( & V_14 -> V_58 , L_2 , V_50 ) ;
V_52 = NULL ;
for ( V_52 = V_59 ; V_52 -> V_60 [ 0 ] ; V_52 ++ ) {
if ( ! strncasecmp ( V_52 -> V_60 , V_50 , strlen ( V_52 -> V_60 ) ) )
break;
}
if ( ! V_52 -> V_60 [ 0 ] ) {
F_22 ( & V_14 -> V_58 , L_3 ) ;
return - V_56 ;
}
if ( V_22 -> V_61 != V_52 -> V_61 )
F_24 ( & V_14 -> V_58 ,
L_4 ,
V_22 -> V_60 , V_52 -> V_60 ) ;
V_9 = F_25 ( & V_14 -> V_58 , sizeof( struct V_8 ) ,
V_62 ) ;
if ( ! V_9 )
return - V_63 ;
V_9 -> V_22 = V_52 -> V_61 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_12 = F_6 () ;
F_4 ( V_9 ) ;
V_18 = & V_9 -> V_18 ;
V_18 -> V_64 = 1 ;
V_18 -> V_65 [ 0 ] = V_66 | V_67
| V_68 | V_69
| V_70 | V_71
| V_72 | V_73 ;
if ( V_9 -> V_22 == V_74 || V_9 -> V_22 == V_75 || V_9 -> V_22 == V_76 )
V_18 -> V_65 [ 0 ] |= V_77 | V_78 ;
V_19 = F_26 ( V_14 , V_79 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 & V_80 )
V_18 -> V_65 [ 0 ] |= V_81 ;
V_9 -> V_12 = F_6 () ;
F_4 ( V_9 ) ;
V_18 -> V_82 = F_8 ;
V_18 -> V_83 = F_12 ;
V_18 -> V_84 = F_14 ;
V_18 -> V_85 = F_17 ;
return F_27 ( V_14 , V_52 , V_18 ) ;
}
