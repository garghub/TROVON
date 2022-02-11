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
unsigned long * V_21 ,
unsigned V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
enum V_7 V_8 ;
int V_23 ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_10 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
V_8 = F_3 ( V_21 [ V_24 ] ) ;
V_23 = F_14 ( V_21 [ V_24 ] ) ;
switch ( V_8 ) {
case V_11 :
if ( V_9 == V_12 )
V_10 = V_13 ;
else
V_10 = F_5 ( V_3 ) ;
if ( V_23 == 0 )
F_15 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
break;
case V_15 :
if ( V_9 == V_12 )
V_10 = V_16 ;
else
V_10 = F_9 ( V_3 ) ;
if ( V_23 == 0 ) {
F_16 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
break;
}
F_15 ( V_6 -> V_14 [ 0 ] , V_10 , F_8 ( V_3 ) ) ;
if ( V_9 == V_12 )
V_10 = V_17 ;
else
V_10 = F_10 ( V_3 ) ;
if ( V_23 == 1 )
F_16 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
else if ( V_23 == 2 )
F_15 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
else
F_12 ( V_2 -> V_19 ,
L_2 , V_23 ) ;
break;
case V_18 :
V_10 = F_11 ( V_3 ) ;
if ( V_23 == 0 )
F_16 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
else
F_15 ( V_6 -> V_14 [ 0 ] ,
V_10 ,
F_8 ( V_3 ) ) ;
break;
default:
F_12 ( V_2 -> V_19 ,
L_1 , V_8 ) ;
return - V_20 ;
}
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned V_25 ,
unsigned long * V_21 ,
unsigned V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_24 , V_26 = 0 ;
for ( V_24 = 0 ; V_24 < V_6 -> V_27 [ V_25 ] . V_28 && ! V_26 ; V_24 ++ )
V_26 = F_13 ( V_2 ,
V_6 -> V_27 [ V_25 ] . V_29 [ V_24 ] ,
V_21 ,
V_22 ) ;
return V_26 ;
}
static inline int F_18 ( struct V_1 * V_30 ,
int V_3 , int V_31 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
int V_9 = F_4 ( V_3 ) ;
T_1 V_32 = F_19 ( V_3 ) ;
if ( V_9 == V_12 )
V_32 = V_33 ;
if ( V_31 & V_34 )
F_15 ( V_6 -> V_14 [ 0 ] , F_20 ( V_3 ) , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , F_20 ( V_3 ) , F_8 ( V_3 ) ) ;
if ( V_31 & V_35 )
F_15 ( V_6 -> V_14 [ 0 ] , V_32 , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , V_32 , F_8 ( V_3 ) ) ;
return 0 ;
}
static void F_21 ( struct V_36 * V_37 , unsigned int V_3 , int V_38 )
{
struct V_5 * V_6 = F_22 ( V_37 -> V_39 ) ;
if ( V_38 )
F_15 ( V_6 -> V_14 [ 0 ] , F_23 ( V_3 ) , F_8 ( V_3 ) ) ;
else
F_16 ( V_6 -> V_14 [ 0 ] , F_23 ( V_3 ) , F_8 ( V_3 ) ) ;
}
static int F_24 ( struct V_36 * V_37 , unsigned int V_3 )
{
struct V_5 * V_6 = F_22 ( V_37 -> V_39 ) ;
return ! ! F_7 ( V_6 -> V_14 [ 0 ] , F_25 ( V_3 ) , F_8 ( V_3 ) ) ;
}
static int F_26 ( struct V_36 * V_37 , unsigned int V_3 )
{
struct V_5 * V_6 = F_22 ( V_37 -> V_39 ) ;
F_16 ( V_6 -> V_14 [ 0 ] , F_11 ( V_3 ) , F_8 ( V_3 ) ) ;
return 0 ;
}
static int F_27 ( struct V_36 * V_37 , unsigned int V_3 , int V_38 )
{
struct V_5 * V_6 = F_22 ( V_37 -> V_39 ) ;
if ( F_4 ( V_3 ) == V_12 )
F_15 ( V_6 -> V_14 [ 0 ] , V_13 , F_8 ( V_3 ) ) ;
else
F_15 ( V_6 -> V_14 [ 0 ] , F_5 ( V_3 ) , F_8 ( V_3 ) ) ;
F_15 ( V_6 -> V_14 [ 0 ] , F_11 ( V_3 ) , F_8 ( V_3 ) ) ;
F_21 ( V_37 , V_3 , V_38 ) ;
return 0 ;
}
static int F_28 ( struct V_40 * V_41 )
{
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_26 , V_24 ;
V_47 = F_29 ( V_41 , V_48 , 0 ) ;
V_49 . V_14 [ 0 ] = F_30 ( & V_41 -> V_19 , V_47 ) ;
if ( F_31 ( V_49 . V_14 [ 0 ] ) )
return F_32 ( V_49 . V_14 [ 0 ] ) ;
V_43 = F_33 ( V_50 , & V_41 -> V_19 ) ;
if ( V_43 )
V_45 = ( const struct V_44 * ) V_43 -> V_51 ;
else
V_45 = & V_52 ;
V_53 . V_54 = V_45 -> V_55 ;
V_49 . V_56 = F_34 ( & V_41 -> V_19 ,
sizeof( struct V_57 ) * V_53 . V_54 ,
V_58 ) ;
if ( ! V_49 . V_56 ) {
F_12 ( & V_41 -> V_19 , L_3 ) ;
return - V_59 ;
}
for ( V_24 = 0 ; V_24 < V_53 . V_54 ; V_24 ++ ) {
char * V_60 = F_34 ( & V_41 -> V_19 , 5 , V_58 ) ;
if ( ! V_60 ) {
F_12 ( & V_41 -> V_19 , L_4 ) ;
return - V_59 ;
}
snprintf ( V_60 , 5 , L_5 , V_24 ) ;
V_49 . V_56 [ V_24 ] . V_61 = V_62 + V_24 ;
V_49 . V_56 [ V_24 ] . V_60 = V_60 ;
}
V_63 . V_29 = V_49 . V_56 ;
V_53 . V_39 = & V_41 -> V_19 ;
V_26 = F_35 ( & V_53 ) ;
if ( V_26 ) {
F_12 ( & V_41 -> V_19 , L_6 ) ;
return V_26 ;
}
V_63 . V_60 = F_36 ( & V_41 -> V_19 ) ;
V_63 . V_28 = V_53 . V_54 ;
V_49 . V_64 = V_53 . V_54 ;
V_49 . V_65 = V_53 . V_54 ;
V_49 . V_66 = V_45 -> V_66 ;
V_49 . V_27 = V_45 -> V_27 ;
V_49 . V_67 = V_45 -> V_67 ;
V_49 . V_68 = V_45 -> V_68 ;
V_49 . V_69 = V_45 -> V_69 ;
V_49 . V_70 = V_45 -> V_70 ;
V_49 . V_71 = V_45 -> V_71 ;
V_26 = F_37 ( V_41 , & V_49 ) ;
if ( V_26 ) {
F_38 ( & V_53 ) ;
F_12 ( & V_41 -> V_19 , L_7 ) ;
return V_26 ;
}
V_72 . V_28 = V_53 . V_54 ;
V_72 . V_73 = V_53 . V_73 ;
F_39 ( V_49 . V_74 , & V_72 ) ;
F_40 ( & V_41 -> V_19 , L_8 ) ;
return 0 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_75 ) ;
}
