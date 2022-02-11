void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
}
static inline const char * F_2 ( T_1 type )
{
switch ( type ) {
case V_6 :
return L_1 ;
case V_7 :
return L_2 ;
default:
return L_3 ;
}
}
static void F_3 ( struct V_8 * V_9 ,
T_1 V_10 , T_1 V_11 , T_1 V_4 )
{
F_4 ( L_4 ,
V_9 , V_10 , V_11 , V_4 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_12 = V_10 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_4 = V_4 ;
}
static void F_5 ( struct V_8 * V_9 )
{
F_4 ( L_5 ,
V_9 , V_9 -> V_13 , V_9 -> V_14 ) ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 0 ;
}
static int F_6 ( struct V_16 * V_17 ,
T_1 V_18 ,
T_1 type )
{
T_1 V_19 [] = {
V_20 ,
V_18 ,
sizeof( struct V_8 ) ,
type
} ;
int V_21 ;
V_21 = F_7 ( V_17 , V_19 , F_8 ( V_19 ) ) ;
if ( V_21 )
F_9 ( L_6 ,
F_2 ( type ) , V_21 ) ;
return V_21 ;
}
static int F_10 ( struct V_16 * V_17 ,
T_1 V_4 ,
T_1 type )
{
T_1 V_19 [] = {
V_22 ,
V_4 ,
type
} ;
int V_21 ;
V_21 = F_7 ( V_17 , V_19 , F_8 ( V_19 ) ) ;
if ( V_21 )
F_9 ( L_7 ,
F_2 ( type ) , V_4 , V_21 ) ;
return V_21 ;
}
static bool F_11 ( struct V_23 * V_24 )
{
return V_24 -> V_25 != NULL ;
}
static int F_12 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
struct V_26 * V_25 ;
void * V_27 ;
int V_21 ;
int V_28 ;
F_13 ( V_24 -> V_25 ) ;
V_25 = F_14 ( V_17 , V_29 ) ;
if ( F_15 ( V_25 ) ) {
V_21 = F_16 ( V_25 ) ;
goto V_30;
}
V_24 -> V_25 = V_25 ;
V_27 = F_17 ( V_25 -> V_31 , V_32 ) ;
if ( F_15 ( V_27 ) ) {
V_21 = F_16 ( V_27 ) ;
goto V_33;
}
F_4 ( L_8 , F_18 ( V_24 -> V_25 ) ) ;
for ( V_28 = 0 ; V_28 < F_8 ( V_24 -> V_34 ) ; V_28 ++ ) {
F_13 ( ( V_28 != V_35 ) && ( V_28 != V_36 ) ) ;
V_24 -> V_34 [ V_28 ] . V_9 = V_27 + V_29 / 4 * V_28 ;
V_24 -> V_34 [ V_28 ] . V_37 = V_27 + V_29 / 4 * V_28 + V_29 / 2 ;
}
return 0 ;
V_33:
F_19 ( & V_24 -> V_25 ) ;
V_30:
F_4 ( L_9 ,
V_24 -> V_4 , V_21 ) ;
return V_21 ;
}
static void F_20 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
F_13 ( ! V_24 -> V_25 ) ;
F_21 ( V_24 -> V_25 -> V_31 ) ;
F_19 ( & V_24 -> V_25 ) ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
T_1 V_38 ;
int V_21 ;
int V_28 ;
F_4 ( L_10 ,
V_24 -> V_4 , F_23 ( F_11 ( V_24 ) ) ) ;
if ( ! V_24 -> V_25 ) {
V_21 = F_12 ( V_17 , V_24 ) ;
if ( F_24 ( V_21 ) )
goto V_30;
}
V_38 = F_18 ( V_24 -> V_25 ) ;
for ( V_28 = 0 ; V_28 < F_8 ( V_24 -> V_34 ) ; V_28 ++ ) {
F_13 ( ( V_28 != V_35 ) && ( V_28 != V_36 ) ) ;
F_3 ( V_24 -> V_34 [ V_28 ] . V_9 ,
V_38 + V_29 / 4 * V_28 + V_29 / 2 ,
V_29 / 4 ,
V_24 -> V_4 ) ;
}
V_21 = F_6 ( V_17 ,
V_38 + V_29 / 4 * V_36 ,
V_7 ) ;
if ( F_24 ( V_21 ) )
goto V_39;
V_21 = F_6 ( V_17 ,
V_38 + V_29 / 4 * V_35 ,
V_6 ) ;
if ( F_24 ( V_21 ) )
goto V_40;
return 0 ;
V_40:
F_10 ( V_17 ,
V_24 -> V_4 ,
V_7 ) ;
V_39:
F_20 ( V_17 , V_24 ) ;
V_30:
F_9 ( L_11 , V_24 -> V_4 , V_21 ) ;
return V_21 ;
}
static void F_25 ( struct V_16 * V_17 ,
struct V_23 * V_24 )
{
F_13 ( ! F_11 ( V_24 ) ) ;
F_10 ( V_17 ,
V_24 -> V_4 ,
V_6 ) ;
F_10 ( V_17 ,
V_24 -> V_4 ,
V_7 ) ;
F_20 ( V_17 , V_24 ) ;
}
static T_1 F_26 ( struct V_23 * V_24 )
{
return ++ V_24 -> V_41 ;
}
static int F_27 ( struct V_42 * V_43 ,
const T_1 * V_19 ,
T_1 V_44 ,
T_1 V_45 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
T_1 V_13 = V_9 -> V_13 / 4 ;
T_1 V_14 = V_9 -> V_14 / 4 ;
T_1 V_11 = V_9 -> V_11 / 4 ;
T_1 V_46 ;
T_1 V_47 ;
T_1 * V_37 = V_43 -> V_37 ;
unsigned int V_28 ;
F_13 ( V_9 -> V_11 % 4 ) ;
F_13 ( V_9 -> V_13 % 4 ) ;
F_13 ( V_9 -> V_14 % 4 ) ;
F_13 ( V_14 >= V_11 ) ;
if ( V_14 < V_13 )
V_46 = ( V_11 - V_13 ) + V_14 ;
else
V_46 = V_14 - V_13 ;
if ( F_24 ( V_46 + V_44 + 1 >= V_11 ) )
return - V_48 ;
V_47 = ( V_44 << V_49 ) |
( V_50 ) |
( V_19 [ 0 ] << V_51 ) ;
V_37 [ V_14 ] = V_47 ;
V_14 = ( V_14 + 1 ) % V_11 ;
V_37 [ V_14 ] = V_45 ;
V_14 = ( V_14 + 1 ) % V_11 ;
for ( V_28 = 1 ; V_28 < V_44 ; V_28 ++ ) {
V_37 [ V_14 ] = V_19 [ V_28 ] ;
V_14 = ( V_14 + 1 ) % V_11 ;
}
V_9 -> V_14 = V_14 * 4 ;
F_13 ( V_9 -> V_14 > V_9 -> V_11 ) ;
return 0 ;
}
static int F_28 ( struct V_8 * V_9 ,
T_1 V_45 ,
T_1 * V_52 )
{
int V_21 ;
#define F_29 (READ_ONCE(desc->fence) == fence)
V_21 = F_30 ( F_29 , 10 ) ;
if ( V_21 )
V_21 = F_31 ( F_29 , 10 ) ;
#undef F_29
if ( F_24 ( V_21 ) ) {
F_9 ( L_12 ,
V_45 , V_9 -> V_45 ) ;
if ( F_32 ( V_9 -> V_15 ) ) {
F_5 ( V_9 ) ;
V_21 = - V_53 ;
}
}
* V_52 = V_9 -> V_52 ;
return V_21 ;
}
static int F_33 ( struct V_16 * V_17 ,
struct V_23 * V_24 ,
const T_1 * V_19 ,
T_1 V_44 ,
T_1 * V_52 )
{
struct V_42 * V_43 = & V_24 -> V_34 [ V_35 ] ;
struct V_8 * V_9 = V_43 -> V_9 ;
T_1 V_45 ;
int V_21 ;
F_13 ( ! F_11 ( V_24 ) ) ;
F_13 ( ! V_44 ) ;
F_13 ( V_44 & ~ V_54 ) ;
V_45 = F_26 ( V_24 ) ;
V_21 = F_27 ( V_43 , V_19 , V_44 , V_45 ) ;
if ( F_24 ( V_21 ) )
return V_21 ;
F_34 ( V_17 ) ;
V_21 = F_28 ( V_9 , V_45 , V_52 ) ;
if ( F_24 ( V_21 ) )
return V_21 ;
if ( * V_52 != V_55 )
return - V_56 ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 , const T_1 * V_19 , T_1 V_44 )
{
struct V_23 * V_24 = & V_17 -> V_2 . V_3 ;
T_1 V_52 = ~ 0 ;
int V_21 ;
F_36 ( & V_17 -> V_57 ) ;
V_21 = F_33 ( V_17 , V_24 , V_19 , V_44 , & V_52 ) ;
if ( F_24 ( V_21 ) ) {
F_9 ( L_13 ,
V_19 [ 0 ] , V_21 , V_52 ) ;
}
F_37 ( & V_17 -> V_57 ) ;
return V_21 ;
}
int F_38 ( struct V_16 * V_17 )
{
struct V_58 * V_59 = F_39 ( V_17 ) ;
struct V_23 * V_24 = & V_17 -> V_2 . V_3 ;
int V_21 ;
F_13 ( ! F_40 ( V_59 ) ) ;
V_21 = F_22 ( V_17 , V_24 ) ;
if ( F_24 ( V_21 ) )
return V_21 ;
V_17 -> V_60 = F_35 ;
F_41 ( L_14 , F_42 ( true ) ) ;
return 0 ;
}
void F_43 ( struct V_16 * V_17 )
{
struct V_58 * V_59 = F_39 ( V_17 ) ;
struct V_23 * V_24 = & V_17 -> V_2 . V_3 ;
F_13 ( ! F_40 ( V_59 ) ) ;
if ( ! F_11 ( V_24 ) )
return;
F_25 ( V_17 , V_24 ) ;
V_17 -> V_60 = V_61 ;
F_41 ( L_14 , F_42 ( false ) ) ;
}
