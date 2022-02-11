static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned long * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_7 V_8 = F_3 ( * V_4 ) ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_10 ;
switch ( V_8 ) {
case V_11 :
if ( V_9 == V_12 )
V_10 = V_13 ;
else
V_10 = F_5 ( V_9 ) ;
* V_4 = F_6 ( V_8 ,
! ! F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ) ;
break;
case V_15 :
if ( V_9 == V_12 )
V_10 = V_16 ;
else
V_10 = F_9 ( V_9 ) ;
if ( ! F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ) {
* V_4 = F_6 ( V_8 , 0 ) ;
break;
}
if ( V_9 == V_12 )
V_10 = V_17 ;
else
V_10 = F_10 ( V_9 ) ;
if ( ! F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) )
* V_4 = F_6 ( V_8 , 2 ) ;
else
* V_4 = F_6 ( V_8 , 1 ) ;
break;
default:
F_11 ( V_2 -> V_18 , L_1 , V_8 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_7 V_8 = F_3 ( V_4 ) ;
int V_20 = F_13 ( V_4 ) ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_10 ;
switch ( V_8 ) {
case V_11 :
if ( V_9 == V_12 )
V_10 = V_13 ;
else
V_10 = F_5 ( V_9 ) ;
F_14 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ;
break;
case V_15 :
if ( V_9 == V_12 )
V_10 = V_16 ;
else
V_10 = F_9 ( V_9 ) ;
if ( V_20 == 0 ) {
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ;
break;
}
F_14 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ;
if ( V_9 == V_12 )
V_10 = V_17 ;
else
V_10 = F_10 ( V_9 ) ;
if ( V_20 == 1 )
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ;
else if ( V_20 == 2 )
F_14 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_9 ) ) ;
else
F_11 ( V_2 -> V_18 , L_2 , V_20 ) ;
break;
default:
F_11 ( V_2 -> V_18 , L_1 , V_8 ) ;
return - V_19 ;
}
return 0 ;
}
static inline int F_16 ( struct V_1 * V_21 ,
int V_3 , int V_22 )
{
struct V_5 * V_6 = F_2 ( V_21 ) ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_23 = F_17 ( V_3 ) ;
if ( V_9 == V_12 )
V_23 = V_24 ;
if ( V_22 & V_25 )
F_14 ( V_6 -> V_14 [ 0 ] , F_18 ( V_3 ) , F_8 ( V_3 ) ) ;
else
F_15 ( V_6 -> V_14 [ 0 ] , F_18 ( V_3 ) , F_8 ( V_3 ) ) ;
if ( V_22 & V_26 )
F_14 ( V_6 -> V_14 [ 0 ] , V_23 , F_8 ( V_3 ) ) ;
else
F_15 ( V_6 -> V_14 [ 0 ] , V_23 , F_8 ( V_3 ) ) ;
return 0 ;
}
static void F_19 ( struct V_27 * V_28 , unsigned int V_3 , int V_29 )
{
struct V_5 * V_6 = F_20 ( V_28 -> V_18 ) ;
if ( V_29 )
F_14 ( V_6 -> V_14 [ 0 ] , F_21 ( V_3 ) , F_8 ( V_3 ) ) ;
else
F_15 ( V_6 -> V_14 [ 0 ] , F_21 ( V_3 ) , F_8 ( V_3 ) ) ;
}
static int F_22 ( struct V_27 * V_28 , unsigned int V_3 )
{
struct V_5 * V_6 = F_20 ( V_28 -> V_18 ) ;
return F_7 ( V_6 -> V_14 [ 0 ] , F_23 ( V_3 ) , F_8 ( V_3 ) ) ;
}
static int F_24 ( struct V_27 * V_28 , unsigned int V_3 )
{
struct V_5 * V_6 = F_20 ( V_28 -> V_18 ) ;
F_15 ( V_6 -> V_14 [ 0 ] , F_25 ( V_3 ) , F_8 ( V_3 ) ) ;
return 0 ;
}
static int F_26 ( struct V_27 * V_28 , unsigned int V_3 , int V_29 )
{
struct V_5 * V_6 = F_20 ( V_28 -> V_18 ) ;
F_14 ( V_6 -> V_14 [ 0 ] , F_25 ( V_3 ) , F_8 ( V_3 ) ) ;
F_19 ( V_28 , V_3 , V_29 ) ;
return 0 ;
}
static int F_27 ( struct V_27 * V_28 , unsigned V_30 )
{
int V_31 = V_28 -> V_32 + V_30 ;
return F_28 ( V_31 ) ;
}
static void F_29 ( struct V_27 * V_28 , unsigned V_30 )
{
int V_31 = V_28 -> V_32 + V_30 ;
F_30 ( V_31 ) ;
}
static int F_31 ( struct V_33 * V_34 )
{
const struct V_35 * V_36 ;
const struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_41 , V_42 ;
V_40 = F_32 ( V_34 , V_43 , 0 ) ;
if ( ! V_40 ) {
F_11 ( & V_34 -> V_18 , L_3 ) ;
return - V_44 ;
}
V_45 . V_14 [ 0 ] = F_33 ( & V_34 -> V_18 , V_40 ) ;
if ( ! V_45 . V_14 [ 0 ] ) {
F_11 ( & V_34 -> V_18 , L_4 ) ;
return - V_46 ;
}
V_36 = F_34 ( V_47 , & V_34 -> V_18 ) ;
if ( V_36 )
V_38 = ( const struct V_37 * ) V_36 -> V_48 ;
else
V_38 = & V_49 [ 0 ] ;
V_50 . V_51 = V_38 -> V_52 ;
V_45 . V_53 = F_35 ( & V_34 -> V_18 ,
sizeof( struct V_54 ) * V_50 . V_51 ,
V_55 ) ;
if ( ! V_45 . V_53 ) {
F_11 ( & V_34 -> V_18 , L_5 ) ;
return - V_46 ;
}
for ( V_42 = 0 ; V_42 < V_50 . V_51 ; V_42 ++ ) {
char * V_56 = F_35 ( & V_34 -> V_18 , 5 , V_55 ) ;
if ( ! V_56 ) {
F_11 ( & V_34 -> V_18 , L_6 ) ;
return - V_46 ;
}
snprintf ( V_56 , 5 , L_7 , V_42 ) ;
V_45 . V_53 [ V_42 ] . V_57 = V_58 + V_42 ;
V_45 . V_53 [ V_42 ] . V_56 = V_56 ;
}
V_59 . V_60 = V_45 . V_53 ;
V_50 . V_18 = & V_34 -> V_18 ;
F_36 ( & V_50 ) ;
V_41 = F_37 ( & V_50 ) ;
if ( V_41 ) {
F_11 ( & V_34 -> V_18 , L_8 ) ;
return V_41 ;
}
V_59 . V_56 = F_38 ( & V_34 -> V_18 ) ;
V_59 . V_61 = V_50 . V_51 ;
V_45 . V_62 = V_50 . V_51 ;
V_45 . V_63 = V_50 . V_51 ;
V_45 . V_64 = V_38 -> V_64 ;
V_45 . V_65 = V_38 -> V_65 ;
V_45 . V_66 = V_38 -> V_66 ;
V_45 . V_67 = V_38 -> V_67 ;
V_45 . V_68 = V_38 -> V_68 ;
V_45 . V_69 = V_38 -> V_69 ;
V_45 . V_70 = V_38 -> V_70 ;
V_41 = F_39 ( V_34 , & V_45 ) ;
if ( V_41 ) {
F_11 ( & V_34 -> V_18 , L_9 ) ;
return V_41 ;
}
V_71 . V_61 = V_50 . V_51 ;
V_71 . V_32 = V_50 . V_32 ;
F_40 ( V_45 . V_72 , & V_71 ) ;
F_41 ( & V_34 -> V_18 , L_10 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_73 ) ;
}
