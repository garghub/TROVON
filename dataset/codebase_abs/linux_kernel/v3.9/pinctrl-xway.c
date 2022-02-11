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
V_10 = F_5 ( V_3 ) ;
* V_4 = F_6 ( V_8 ,
! F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ) ;
break;
case V_15 :
if ( V_9 == V_12 )
V_10 = V_16 ;
else
V_10 = F_9 ( V_3 ) ;
if ( ! F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ) {
* V_4 = F_6 ( V_8 , 0 ) ;
break;
}
if ( V_9 == V_12 )
V_10 = V_17 ;
else
V_10 = F_10 ( V_3 ) ;
if ( ! F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) )
* V_4 = F_6 ( V_8 , 2 ) ;
else
* V_4 = F_6 ( V_8 , 1 ) ;
break;
case V_18 :
V_10 = F_11 ( V_3 ) ;
* V_4 = F_6 ( V_8 ,
F_7 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ) ;
break;
default:
F_12 ( V_2 -> V_19 , L_1 , V_8 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_7 V_8 = F_3 ( V_4 ) ;
int V_21 = F_14 ( V_4 ) ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_10 ;
switch ( V_8 ) {
case V_11 :
if ( V_9 == V_12 )
V_10 = V_13 ;
else
V_10 = F_5 ( V_3 ) ;
if ( V_21 == 0 )
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
break;
case V_15 :
if ( V_9 == V_12 )
V_10 = V_16 ;
else
V_10 = F_9 ( V_3 ) ;
if ( V_21 == 0 ) {
F_16 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
break;
}
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
if ( V_9 == V_12 )
V_10 = V_17 ;
else
V_10 = F_10 ( V_3 ) ;
if ( V_21 == 1 )
F_16 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
else if ( V_21 == 2 )
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
else
F_12 ( V_2 -> V_19 , L_2 , V_21 ) ;
break;
case V_18 :
V_10 = F_11 ( V_3 ) ;
if ( V_21 == 0 )
F_16 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
else
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
break;
default:
F_12 ( V_2 -> V_19 , L_1 , V_8 ) ;
return - V_20 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned V_22 ,
unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_23 , V_24 = 0 ;
for ( V_23 = 0 ; V_23 < V_6 -> V_25 [ V_22 ] . V_26 && ! V_24 ; V_23 ++ )
V_24 = F_13 ( V_2 ,
V_6 -> V_25 [ V_22 ] . V_27 [ V_23 ] , V_4 ) ;
return V_24 ;
}
static inline int F_18 ( struct V_1 * V_28 ,
int V_3 , int V_29 )
{
struct V_5 * V_6 = F_2 ( V_28 ) ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_30 = F_19 ( V_3 ) ;
if ( V_9 == V_12 )
V_30 = V_31 ;
if ( V_29 & V_32 )
F_15 ( V_6 -> V_14 [ 0 ] , F_20 ( V_3 ) , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , F_20 ( V_3 ) , F_8 ( V_3 ) ) ;
if ( V_29 & V_33 )
F_15 ( V_6 -> V_14 [ 0 ] , V_30 , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , V_30 , F_8 ( V_3 ) ) ;
return 0 ;
}
static void F_21 ( struct V_34 * V_35 , unsigned int V_3 , int V_36 )
{
struct V_5 * V_6 = F_22 ( V_35 -> V_19 ) ;
if ( V_36 )
F_15 ( V_6 -> V_14 [ 0 ] , F_23 ( V_3 ) , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , F_23 ( V_3 ) , F_8 ( V_3 ) ) ;
}
static int F_24 ( struct V_34 * V_35 , unsigned int V_3 )
{
struct V_5 * V_6 = F_22 ( V_35 -> V_19 ) ;
return F_7 ( V_6 -> V_14 [ 0 ] , F_25 ( V_3 ) , F_8 ( V_3 ) ) ;
}
static int F_26 ( struct V_34 * V_35 , unsigned int V_3 )
{
struct V_5 * V_6 = F_22 ( V_35 -> V_19 ) ;
F_16 ( V_6 -> V_14 [ 0 ] , F_11 ( V_3 ) , F_8 ( V_3 ) ) ;
return 0 ;
}
static int F_27 ( struct V_34 * V_35 , unsigned int V_3 , int V_36 )
{
struct V_5 * V_6 = F_22 ( V_35 -> V_19 ) ;
F_15 ( V_6 -> V_14 [ 0 ] , F_11 ( V_3 ) , F_8 ( V_3 ) ) ;
F_21 ( V_35 , V_3 , V_36 ) ;
return 0 ;
}
static int F_28 ( struct V_34 * V_35 , unsigned V_37 )
{
int V_38 = V_35 -> V_39 + V_37 ;
return F_29 ( V_38 ) ;
}
static void F_30 ( struct V_34 * V_35 , unsigned V_37 )
{
int V_38 = V_35 -> V_39 + V_37 ;
F_31 ( V_38 ) ;
}
static int F_32 ( struct V_40 * V_41 )
{
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_24 , V_23 ;
V_47 = F_33 ( V_41 , V_48 , 0 ) ;
if ( ! V_47 ) {
F_12 ( & V_41 -> V_19 , L_3 ) ;
return - V_49 ;
}
V_50 . V_14 [ 0 ] = F_34 ( & V_41 -> V_19 , V_47 ) ;
if ( F_35 ( V_50 . V_14 [ 0 ] ) )
return F_36 ( V_50 . V_14 [ 0 ] ) ;
V_43 = F_37 ( V_51 , & V_41 -> V_19 ) ;
if ( V_43 )
V_45 = ( const struct V_44 * ) V_43 -> V_52 ;
else
V_45 = & V_53 [ 0 ] ;
V_54 . V_55 = V_45 -> V_56 ;
V_50 . V_57 = F_38 ( & V_41 -> V_19 ,
sizeof( struct V_58 ) * V_54 . V_55 ,
V_59 ) ;
if ( ! V_50 . V_57 ) {
F_12 ( & V_41 -> V_19 , L_4 ) ;
return - V_60 ;
}
for ( V_23 = 0 ; V_23 < V_54 . V_55 ; V_23 ++ ) {
char * V_61 = F_38 ( & V_41 -> V_19 , 5 , V_59 ) ;
if ( ! V_61 ) {
F_12 ( & V_41 -> V_19 , L_5 ) ;
return - V_60 ;
}
snprintf ( V_61 , 5 , L_6 , V_23 ) ;
V_50 . V_57 [ V_23 ] . V_62 = V_63 + V_23 ;
V_50 . V_57 [ V_23 ] . V_61 = V_61 ;
}
V_64 . V_27 = V_50 . V_57 ;
V_54 . V_19 = & V_41 -> V_19 ;
F_39 ( & V_54 ) ;
V_24 = F_40 ( & V_54 ) ;
if ( V_24 ) {
F_12 ( & V_41 -> V_19 , L_7 ) ;
return V_24 ;
}
V_64 . V_61 = F_41 ( & V_41 -> V_19 ) ;
V_64 . V_26 = V_54 . V_55 ;
V_50 . V_65 = V_54 . V_55 ;
V_50 . V_66 = V_54 . V_55 ;
V_50 . V_67 = V_45 -> V_67 ;
V_50 . V_25 = V_45 -> V_25 ;
V_50 . V_68 = V_45 -> V_68 ;
V_50 . V_69 = V_45 -> V_69 ;
V_50 . V_70 = V_45 -> V_70 ;
V_50 . V_71 = V_45 -> V_71 ;
V_50 . V_72 = V_45 -> V_72 ;
V_24 = F_42 ( V_41 , & V_50 ) ;
if ( V_24 ) {
F_12 ( & V_41 -> V_19 , L_8 ) ;
return V_24 ;
}
V_73 . V_26 = V_54 . V_55 ;
V_73 . V_39 = V_54 . V_39 ;
F_43 ( V_50 . V_74 , & V_73 ) ;
F_44 ( & V_41 -> V_19 , L_9 ) ;
return 0 ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_75 ) ;
}
