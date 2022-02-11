int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 ( V_2 -> V_5 ) ;
return 0 ;
}
void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_6 ( V_2 -> V_5 ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_9 = V_10 | V_11 |
V_12 ;
* F_4 ( V_8 , 1 ) = V_9 ;
F_5 ( & V_2 -> V_13 , V_8 ) ;
F_6 ( & V_2 -> V_14 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_15 ;
unsigned long V_16 ;
if ( V_2 -> V_13 . V_17 )
F_8 ( L_1 ,
V_2 -> V_13 . V_17 , V_2 -> V_18 . V_17 ) ;
while ( V_2 -> V_13 . V_17 ) {
V_8 = F_9 ( & V_2 -> V_13 ) ;
F_10 ( L_2 , V_8 ) ;
V_15 = V_2 -> V_3 -> V_19 ( V_2 -> V_5 , V_8 ) ;
if ( V_15 < 0 ) {
V_2 -> V_20 = V_15 ;
break;
}
V_16 = V_21 ;
* ( unsigned long * ) V_8 -> V_22 = V_16 ;
F_5 ( & V_2 -> V_18 , V_8 ) ;
V_2 -> V_23 = true ;
F_11 ( & V_2 -> V_24 , V_16 +
F_12 ( V_25 ) ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
while ( ( V_8 = F_14 ( & V_2 -> V_18 ) ) ) {
V_9 = V_8 -> V_26 [ 0 ] ;
switch ( V_9 & V_27 ) {
case V_28 :
V_8 -> V_26 [ 0 ] = ( V_9 & ~ V_29 ) |
V_30 ;
break;
case V_10 :
V_8 -> V_26 [ 0 ] = ( V_9 & ~ V_31 ) |
V_32 ;
break;
default:
F_15 ( L_3 , V_9 ) ;
F_16 ( V_8 ) ;
break;
}
F_17 ( & V_2 -> V_13 , V_8 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
unsigned long V_16 ;
if ( V_2 -> V_33 . V_17 )
F_8 ( L_4 , V_2 -> V_33 . V_17 ) ;
while ( ( V_8 = F_9 ( & V_2 -> V_33 ) ) != NULL ) {
V_9 = V_8 -> V_26 [ 0 ] ;
F_19 ( V_8 , 1 ) ;
if ( ( V_9 & V_27 ) == V_28 ) {
switch ( V_9 & V_34 ) {
case V_35 :
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = false ;
V_2 -> V_23 = false ;
break;
case V_38 :
F_13 ( V_2 ) ;
F_7 ( V_2 ) ;
V_16 = V_21 ;
V_2 -> V_23 = true ;
F_11 ( & V_2 -> V_24 , V_16 +
F_12 ( V_25 ) ) ;
break;
case V_39 :
V_16 = V_21 ;
V_2 -> V_23 = true ;
F_11 ( & V_2 -> V_24 , V_16 +
F_12 ( V_40 ) ) ;
break;
default:
F_15 ( L_3 , V_9 ) ;
F_16 ( V_8 ) ;
break;
}
} else {
F_21 ( V_2 -> V_41 , V_8 ) ;
}
}
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_23 ( V_43 , struct V_1 , V_14 ) ;
F_7 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_23 && F_24 ( & V_2 -> V_24 ) == 0 ) {
F_8
( L_5 ) ;
V_2 -> V_23 = false ;
F_13 ( V_2 ) ;
F_7 ( V_2 ) ;
}
if ( V_2 -> V_37 && F_24 ( & V_2 -> V_36 ) == 0 ) {
F_8 ( L_6 ) ;
V_2 -> V_37 = false ;
V_2 -> V_23 = false ;
F_20 ( & V_2 -> V_24 ) ;
F_2 ( V_2 ) ;
V_2 -> V_20 = - V_44 ;
}
}
void F_25 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
if ( V_8 == NULL ) {
F_15 ( L_7 ) ;
V_2 -> V_20 = - V_44 ;
F_2 ( V_2 ) ;
} else {
F_10 ( L_8 , V_8 ) ;
F_5 ( & V_2 -> V_33 , V_8 ) ;
}
F_6 ( & V_2 -> V_14 ) ;
}
static void F_26 ( unsigned long V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
F_8 ( L_9 ) ;
F_6 ( & V_2 -> V_14 ) ;
}
static void F_27 ( unsigned long V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
F_8 ( L_9 ) ;
F_6 ( & V_2 -> V_14 ) ;
}
int F_28 ( void * V_5 , struct V_45 * V_46 , struct V_47 * V_48 ,
int V_49 , int V_50 , struct V_1 * * V_51 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_48 , sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_2 ) {
F_30 ( V_48 , L_10 ) ;
return - V_53 ;
}
V_2 -> V_3 = V_46 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_48 = V_48 ;
* V_51 = V_2 ;
F_31 ( & V_2 -> V_24 ) ;
V_2 -> V_24 . V_26 = ( unsigned long ) V_2 ;
V_2 -> V_24 . V_54 = F_26 ;
F_31 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_26 = ( unsigned long ) V_2 ;
V_2 -> V_36 . V_54 = F_27 ;
F_32 ( & V_2 -> V_33 ) ;
F_32 ( & V_2 -> V_13 ) ;
F_32 ( & V_2 -> V_18 ) ;
F_33 ( & V_2 -> V_14 , F_22 ) ;
return F_34 ( V_2 , V_49 , V_50 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = false ;
V_2 -> V_23 = false ;
F_36 ( & V_2 -> V_33 ) ;
F_36 ( & V_2 -> V_13 ) ;
F_37 ( V_2 -> V_41 ) ;
F_38 ( V_2 ) ;
}
