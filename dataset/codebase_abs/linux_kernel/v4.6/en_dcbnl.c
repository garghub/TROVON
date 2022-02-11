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
V_21 [ V_14 ] = V_4 -> V_21 [ V_14 ] ? : V_23 ;
break;
}
}
}
int F_6 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
struct V_24 * V_7 = V_6 -> V_7 ;
T_1 V_21 [ V_25 ] ;
T_1 V_10 [ V_25 ] ;
int V_11 = F_7 ( V_7 ) ;
int V_26 ;
if ( ! F_3 ( V_7 , V_4 ) )
return - V_8 ;
F_4 ( V_4 , V_10 , V_11 ) ;
F_5 ( V_4 , V_21 , V_10 , V_11 ) ;
V_26 = F_8 ( V_7 , V_4 -> V_27 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_9 ( V_7 , V_10 ) ;
if ( V_26 )
return V_26 ;
return F_10 ( V_7 , V_21 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_28 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ ) {
if ( V_4 -> V_27 [ V_14 ] >= V_29 )
return - V_30 ;
}
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ ) {
if ( V_4 -> V_15 [ V_14 ] == V_16 )
V_28 += V_4 -> V_21 [ V_14 ] ;
}
if ( V_28 != 0 && V_28 != 100 )
return - V_30 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_26 ;
V_26 = F_11 ( V_4 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_6 ( V_6 , V_4 ) ;
if ( V_26 )
return V_26 ;
memcpy ( & V_6 -> V_9 . V_4 , V_4 , sizeof( * V_4 ) ) ;
V_6 -> V_9 . V_4 . V_31 = F_7 ( V_6 -> V_7 ) + 1 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_32 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_32 ) ;
struct V_24 * V_7 = V_6 -> V_7 ;
V_34 -> V_35 = F_7 ( V_7 ) + 1 ;
return F_14 ( V_7 , & V_34 -> V_36 , NULL ) ;
}
static int F_15 ( struct V_1 * V_32 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_32 ) ;
struct V_24 * V_7 = V_6 -> V_7 ;
enum V_37 V_38 ;
T_1 V_39 ;
int V_40 ;
F_14 ( V_7 , & V_39 , NULL ) ;
if ( V_34 -> V_36 == V_39 )
return 0 ;
F_16 ( V_7 , & V_38 ) ;
if ( V_38 == V_41 )
F_17 ( V_7 , V_42 ) ;
V_40 = F_18 ( V_7 , V_34 -> V_36 , V_34 -> V_36 ) ;
if ( V_38 == V_41 )
F_17 ( V_7 , V_41 ) ;
return V_40 ;
}
static T_1 F_19 ( struct V_1 * V_32 )
{
return V_43 | V_44 ;
}
static T_1 F_20 ( struct V_1 * V_32 , T_1 V_45 )
{
if ( ( V_45 & V_46 ) ||
( V_45 & V_47 ) ||
! ( V_45 & V_44 ) ||
! ( V_45 & V_43 ) )
return 1 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 * V_7 = V_6 -> V_7 ;
T_1 V_50 [ V_25 ] ;
T_1 V_51 [ V_25 ] ;
int V_26 ;
int V_14 ;
V_26 = F_22 ( V_7 , V_50 , V_51 ) ;
if ( V_26 )
return V_26 ;
memset ( V_49 -> V_52 , 0 , sizeof( V_49 -> V_52 ) ) ;
for ( V_14 = 0 ; V_14 <= F_7 ( V_7 ) ; V_14 ++ ) {
switch ( V_51 [ V_14 ] ) {
case V_53 :
V_49 -> V_52 [ V_14 ] = V_50 [ V_14 ] * V_54 ;
break;
case V_55 :
V_49 -> V_52 [ V_14 ] = V_50 [ V_14 ] * V_56 ;
break;
case V_57 :
break;
default:
F_23 ( true , L_1 ) ;
break;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 * V_7 = V_6 -> V_7 ;
T_1 V_50 [ V_25 ] ;
T_1 V_51 [ V_25 ] ;
T_2 V_58 = F_25 ( 255 * V_54 , V_56 ) ;
int V_14 ;
memset ( V_50 , 0 , sizeof( V_50 ) ) ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
for ( V_14 = 0 ; V_14 <= F_7 ( V_7 ) ; V_14 ++ ) {
if ( ! V_49 -> V_52 [ V_14 ] ) {
V_51 [ V_14 ] = V_57 ;
continue;
}
if ( V_49 -> V_52 [ V_14 ] < V_58 ) {
V_50 [ V_14 ] = F_26 ( V_49 -> V_52 [ V_14 ] ,
V_54 ) ;
V_50 [ V_14 ] = V_50 [ V_14 ] ? V_50 [ V_14 ] : 1 ;
V_51 [ V_14 ] = V_53 ;
} else {
V_50 [ V_14 ] = F_26 ( V_49 -> V_52 [ V_14 ] ,
V_56 ) ;
V_51 [ V_14 ] = V_55 ;
}
}
return F_27 ( V_7 , V_50 , V_51 ) ;
}
