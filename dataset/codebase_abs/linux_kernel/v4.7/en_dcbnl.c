static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_6 -> V_7 , V_4 ) )
return - V_8 ;
memcpy ( V_4 , & V_6 -> V_9 . V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 , T_1 * V_10 , int V_11 )
{
bool V_12 = false ;
int V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 <= V_11 ; V_14 ++ )
if ( V_4 -> V_15 [ V_14 ] == V_16 )
V_12 = true ;
V_13 = V_12 ? 1 : 0 ;
for ( V_14 = 0 ; V_14 <= V_11 ; V_14 ++ ) {
switch ( V_4 -> V_15 [ V_14 ] ) {
case V_17 :
V_10 [ V_14 ] = V_18 ;
break;
case V_19 :
V_10 [ V_14 ] = V_13 ++ ;
break;
case V_16 :
V_10 [ V_14 ] = V_20 ;
break;
}
}
}
static void F_5 ( struct V_3 * V_4 , T_1 * V_21 ,
T_1 * V_10 , int V_11 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 <= V_11 ; V_14 ++ ) {
switch ( V_4 -> V_15 [ V_14 ] ) {
case V_17 :
V_21 [ V_14 ] = V_22 ;
break;
case V_19 :
V_21 [ V_14 ] = V_22 ;
break;
case V_16 :
V_21 [ V_14 ] = V_4 -> V_21 [ V_14 ] ;
break;
}
}
}
int F_6 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
struct V_23 * V_7 = V_6 -> V_7 ;
T_1 V_21 [ V_24 ] ;
T_1 V_10 [ V_24 ] ;
int V_11 = F_7 ( V_7 ) ;
int V_25 ;
if ( ! F_3 ( V_7 , V_4 ) )
return - V_8 ;
F_4 ( V_4 , V_10 , V_11 ) ;
F_5 ( V_4 , V_21 , V_10 , V_11 ) ;
V_25 = F_8 ( V_7 , V_4 -> V_26 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_9 ( V_7 , V_10 ) ;
if ( V_25 )
return V_25 ;
return F_10 ( V_7 , V_21 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_27 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ ) {
if ( V_4 -> V_26 [ V_14 ] >= V_28 )
return - V_29 ;
}
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ ) {
if ( V_4 -> V_15 [ V_14 ] == V_16 ) {
if ( ! V_4 -> V_21 [ V_14 ] )
return - V_29 ;
V_27 += V_4 -> V_21 [ V_14 ] ;
}
}
if ( V_27 != 0 && V_27 != 100 )
return - V_29 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_25 ;
V_25 = F_11 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_6 ( V_6 , V_4 ) ;
if ( V_25 )
return V_25 ;
memcpy ( & V_6 -> V_9 . V_4 , V_4 , sizeof( * V_4 ) ) ;
V_6 -> V_9 . V_4 . V_30 = F_7 ( V_6 -> V_7 ) + 1 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_31 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_31 ) ;
struct V_23 * V_7 = V_6 -> V_7 ;
struct V_34 * V_35 = & V_6 -> V_36 . V_37 ;
int V_14 ;
V_33 -> V_38 = F_7 ( V_7 ) + 1 ;
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ ) {
V_33 -> V_39 [ V_14 ] = F_14 ( V_35 , V_14 , V_40 ) ;
V_33 -> V_41 [ V_14 ] = F_14 ( V_35 , V_14 , V_42 ) ;
}
return F_15 ( V_7 , & V_33 -> V_43 , NULL ) ;
}
static int F_16 ( struct V_1 * V_31 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_31 ) ;
struct V_23 * V_7 = V_6 -> V_7 ;
enum V_44 V_45 ;
T_1 V_46 ;
int V_47 ;
F_15 ( V_7 , & V_46 , NULL ) ;
if ( V_33 -> V_43 == V_46 )
return 0 ;
F_17 ( V_7 , & V_45 ) ;
if ( V_45 == V_48 )
F_18 ( V_7 , V_49 ) ;
V_47 = F_19 ( V_7 , V_33 -> V_43 , V_33 -> V_43 ) ;
if ( V_45 == V_48 )
F_18 ( V_7 , V_48 ) ;
return V_47 ;
}
static T_1 F_20 ( struct V_1 * V_31 )
{
return V_50 | V_51 ;
}
static T_1 F_21 ( struct V_1 * V_31 , T_1 V_52 )
{
if ( ( V_52 & V_53 ) ||
( V_52 & V_54 ) ||
! ( V_52 & V_51 ) ||
! ( V_52 & V_50 ) )
return 1 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_23 * V_7 = V_6 -> V_7 ;
T_1 V_57 [ V_24 ] ;
T_1 V_58 [ V_24 ] ;
int V_25 ;
int V_14 ;
V_25 = F_23 ( V_7 , V_57 , V_58 ) ;
if ( V_25 )
return V_25 ;
memset ( V_56 -> V_59 , 0 , sizeof( V_56 -> V_59 ) ) ;
for ( V_14 = 0 ; V_14 <= F_7 ( V_7 ) ; V_14 ++ ) {
switch ( V_58 [ V_14 ] ) {
case V_60 :
V_56 -> V_59 [ V_14 ] = V_57 [ V_14 ] * V_61 ;
break;
case V_62 :
V_56 -> V_59 [ V_14 ] = V_57 [ V_14 ] * V_63 ;
break;
case V_64 :
break;
default:
F_24 ( true , L_1 ) ;
break;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_23 * V_7 = V_6 -> V_7 ;
T_1 V_57 [ V_24 ] ;
T_1 V_58 [ V_24 ] ;
T_2 V_65 = F_26 ( 255 * V_61 , V_63 ) ;
int V_14 ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
for ( V_14 = 0 ; V_14 <= F_7 ( V_7 ) ; V_14 ++ ) {
if ( ! V_56 -> V_59 [ V_14 ] ) {
V_58 [ V_14 ] = V_64 ;
continue;
}
if ( V_56 -> V_59 [ V_14 ] < V_65 ) {
V_57 [ V_14 ] = F_27 ( V_56 -> V_59 [ V_14 ] ,
V_61 ) ;
V_57 [ V_14 ] = V_57 [ V_14 ] ? V_57 [ V_14 ] : 1 ;
V_58 [ V_14 ] = V_60 ;
} else {
V_57 [ V_14 ] = F_27 ( V_56 -> V_59 [ V_14 ] ,
V_63 ) ;
V_58 [ V_14 ] = V_62 ;
}
}
return F_28 ( V_7 , V_57 , V_58 ) ;
}
