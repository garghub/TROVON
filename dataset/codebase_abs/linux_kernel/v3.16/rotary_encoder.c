static int F_1 ( const struct V_1 * V_2 )
{
int V_3 = ! ! F_2 ( V_2 -> V_4 ) ;
int V_5 = ! ! F_2 ( V_2 -> V_6 ) ;
V_3 ^= V_2 -> V_7 ;
V_5 ^= V_2 -> V_8 ;
return ( ( V_3 << 1 ) | V_5 ) ;
}
static void F_3 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 -> V_11 ) {
F_4 ( V_10 -> V_12 ,
V_2 -> V_13 , V_10 -> V_14 ? - 1 : 1 ) ;
} else {
unsigned int V_15 = V_10 -> V_15 ;
if ( V_10 -> V_14 ) {
if ( V_2 -> V_16 )
V_15 += V_2 -> V_17 ;
if ( V_15 )
V_15 -- ;
} else {
if ( V_2 -> V_16 || V_15 < V_2 -> V_17 )
V_15 ++ ;
}
if ( V_2 -> V_16 )
V_15 %= V_2 -> V_17 ;
V_10 -> V_15 = V_15 ;
F_5 ( V_10 -> V_12 , V_2 -> V_13 , V_10 -> V_15 ) ;
}
F_6 ( V_10 -> V_12 ) ;
}
static T_1 F_7 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
switch ( V_20 ) {
case 0x0 :
if ( V_10 -> V_21 ) {
F_3 ( V_10 ) ;
V_10 -> V_21 = false ;
}
break;
case 0x1 :
case 0x2 :
if ( V_10 -> V_21 )
V_10 -> V_14 = V_20 - 1 ;
break;
case 0x3 :
V_10 -> V_21 = true ;
break;
}
return V_22 ;
}
static T_1 F_8 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
switch ( V_20 ) {
case 0x00 :
case 0x03 :
if ( V_20 != V_10 -> V_23 ) {
F_3 ( V_10 ) ;
V_10 -> V_23 = V_20 ;
}
break;
case 0x01 :
case 0x02 :
V_10 -> V_14 = ( V_10 -> V_23 + V_20 ) & 0x01 ;
break;
}
return V_22 ;
}
static struct V_1 * F_9 ( struct V_24 * V_25 )
{
const struct V_26 * V_27 =
F_10 ( V_28 , V_25 ) ;
struct V_29 * V_30 = V_25 -> V_31 ;
struct V_1 * V_2 ;
enum V_32 V_33 ;
if ( ! V_27 || ! V_30 )
return NULL ;
V_2 = F_11 ( sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_2 )
return F_12 ( - V_35 ) ;
F_13 ( V_30 , L_1 , & V_2 -> V_17 ) ;
F_13 ( V_30 , L_2 , & V_2 -> V_13 ) ;
V_2 -> V_4 = F_14 ( V_30 , 0 , & V_33 ) ;
V_2 -> V_7 = V_33 & V_36 ;
V_2 -> V_6 = F_14 ( V_30 , 1 , & V_33 ) ;
V_2 -> V_8 = V_33 & V_36 ;
V_2 -> V_11 = ! ! F_15 ( V_30 ,
L_3 , NULL ) ;
V_2 -> V_16 = ! ! F_15 ( V_30 ,
L_4 , NULL ) ;
V_2 -> V_37 = ! ! F_15 ( V_30 ,
L_5 , NULL ) ;
return V_2 ;
}
static inline struct V_1 *
F_9 ( struct V_24 * V_25 )
{
return NULL ;
}
static int F_16 ( struct V_38 * V_39 )
{
struct V_24 * V_25 = & V_39 -> V_25 ;
const struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_9 * V_10 ;
struct V_40 * V_12 ;
T_2 V_41 ;
int V_42 ;
if ( ! V_2 ) {
V_2 = F_9 ( V_25 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
if ( ! V_2 ) {
F_20 ( V_25 , L_6 ) ;
return - V_43 ;
}
}
V_10 = F_11 ( sizeof( struct V_9 ) , V_34 ) ;
V_12 = F_21 () ;
if ( ! V_10 || ! V_12 ) {
V_42 = - V_35 ;
goto V_44;
}
V_10 -> V_12 = V_12 ;
V_10 -> V_2 = V_2 ;
V_12 -> V_45 = V_39 -> V_45 ;
V_12 -> V_46 . V_47 = V_48 ;
V_12 -> V_25 . V_49 = V_25 ;
if ( V_2 -> V_11 ) {
V_12 -> V_50 [ 0 ] = F_22 ( V_51 ) ;
V_12 -> V_52 [ 0 ] = F_22 ( V_2 -> V_13 ) ;
} else {
V_12 -> V_50 [ 0 ] = F_22 ( V_53 ) ;
F_23 ( V_10 -> V_12 ,
V_2 -> V_13 , 0 , V_2 -> V_17 , 0 , 1 ) ;
}
V_42 = F_24 ( V_2 -> V_4 , V_54 , F_25 ( V_25 ) ) ;
if ( V_42 ) {
F_20 ( V_25 , L_7 , V_2 -> V_4 ) ;
goto V_44;
}
V_42 = F_24 ( V_2 -> V_6 , V_54 , F_25 ( V_25 ) ) ;
if ( V_42 ) {
F_20 ( V_25 , L_7 , V_2 -> V_6 ) ;
goto V_55;
}
V_10 -> V_56 = F_26 ( V_2 -> V_4 ) ;
V_10 -> V_57 = F_26 ( V_2 -> V_6 ) ;
if ( V_2 -> V_37 ) {
V_41 = & F_8 ;
V_10 -> V_23 = F_1 ( V_2 ) ;
} else {
V_41 = & F_7 ;
}
V_42 = F_27 ( V_10 -> V_56 , V_41 ,
V_58 | V_59 ,
V_60 , V_10 ) ;
if ( V_42 ) {
F_20 ( V_25 , L_8 , V_10 -> V_56 ) ;
goto V_61;
}
V_42 = F_27 ( V_10 -> V_57 , V_41 ,
V_58 | V_59 ,
V_60 , V_10 ) ;
if ( V_42 ) {
F_20 ( V_25 , L_8 , V_10 -> V_57 ) ;
goto V_62;
}
V_42 = F_28 ( V_12 ) ;
if ( V_42 ) {
F_20 ( V_25 , L_9 ) ;
goto V_63;
}
F_29 ( V_39 , V_10 ) ;
return 0 ;
V_63:
F_30 ( V_10 -> V_57 , V_10 ) ;
V_62:
F_30 ( V_10 -> V_56 , V_10 ) ;
V_61:
F_31 ( V_2 -> V_6 ) ;
V_55:
F_31 ( V_2 -> V_4 ) ;
V_44:
F_32 ( V_12 ) ;
F_33 ( V_10 ) ;
if ( ! F_17 ( & V_39 -> V_25 ) )
F_33 ( V_2 ) ;
return V_42 ;
}
static int F_34 ( struct V_38 * V_39 )
{
struct V_9 * V_10 = F_35 ( V_39 ) ;
const struct V_1 * V_2 = V_10 -> V_2 ;
F_30 ( V_10 -> V_56 , V_10 ) ;
F_30 ( V_10 -> V_57 , V_10 ) ;
F_31 ( V_2 -> V_4 ) ;
F_31 ( V_2 -> V_6 ) ;
F_36 ( V_10 -> V_12 ) ;
F_33 ( V_10 ) ;
if ( ! F_17 ( & V_39 -> V_25 ) )
F_33 ( V_2 ) ;
return 0 ;
}
