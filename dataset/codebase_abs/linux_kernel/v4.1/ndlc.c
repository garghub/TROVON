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
V_2 -> V_26 = true ;
F_11 ( & V_2 -> V_27 , V_16 +
F_12 ( V_28 ) ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
while ( ( V_8 = F_14 ( & V_2 -> V_18 ) ) ) {
V_9 = V_8 -> V_29 [ 0 ] ;
switch ( V_9 & V_30 ) {
case V_31 :
V_8 -> V_29 [ 0 ] = ( V_9 & ~ V_32 ) |
V_33 ;
break;
case V_10 :
V_8 -> V_29 [ 0 ] = ( V_9 & ~ V_34 ) |
V_35 ;
break;
default:
F_15 ( L_3 , V_9 ) ;
F_16 ( V_8 ) ;
continue;
}
F_17 ( & V_2 -> V_13 , V_8 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
unsigned long V_16 ;
if ( V_2 -> V_36 . V_17 )
F_8 ( L_4 , V_2 -> V_36 . V_17 ) ;
while ( ( V_8 = F_9 ( & V_2 -> V_36 ) ) != NULL ) {
V_9 = V_8 -> V_29 [ 0 ] ;
F_19 ( V_8 , 1 ) ;
if ( ( V_9 & V_30 ) == V_31 ) {
switch ( V_9 & V_37 ) {
case V_38 :
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_27 ) ;
V_2 -> V_26 = false ;
V_2 -> V_23 = false ;
break;
case V_39 :
F_13 ( V_2 ) ;
F_7 ( V_2 ) ;
V_16 = V_21 ;
V_2 -> V_23 = true ;
F_11 ( & V_2 -> V_24 , V_16 +
F_12 ( V_25 ) ) ;
break;
case V_40 :
V_16 = V_21 ;
V_2 -> V_23 = true ;
F_11 ( & V_2 -> V_24 , V_16 +
F_12 ( V_41 ) ) ;
break;
default:
F_15 ( L_3 , V_9 ) ;
F_16 ( V_8 ) ;
break;
}
} else {
F_21 ( V_2 -> V_42 , V_8 ) ;
}
}
}
static void F_22 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 , struct V_1 , V_14 ) ;
F_7 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_23 && F_24 ( & V_2 -> V_24 ) == 0 ) {
F_8
( L_5 ) ;
V_2 -> V_23 = false ;
F_13 ( V_2 ) ;
F_7 ( V_2 ) ;
}
if ( V_2 -> V_26 && F_24 ( & V_2 -> V_27 ) == 0 ) {
F_8 ( L_6 ) ;
V_2 -> V_26 = false ;
V_2 -> V_23 = false ;
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_27 ) ;
F_2 ( V_2 ) ;
V_2 -> V_20 = - V_45 ;
}
}
void F_25 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
if ( V_8 == NULL ) {
F_15 ( L_7 ) ;
V_2 -> V_20 = - V_45 ;
F_2 ( V_2 ) ;
} else {
F_10 ( L_8 , V_8 ) ;
F_5 ( & V_2 -> V_36 , V_8 ) ;
}
F_6 ( & V_2 -> V_14 ) ;
}
static void F_26 ( unsigned long V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
F_8 ( L_9 ) ;
F_6 ( & V_2 -> V_14 ) ;
}
static void F_27 ( unsigned long V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
F_8 ( L_9 ) ;
F_6 ( & V_2 -> V_14 ) ;
}
int F_28 ( void * V_5 , struct V_46 * V_47 , struct V_48 * V_49 ,
int V_50 , int V_51 , struct V_1 * * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_49 , sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_3 = V_47 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_49 = V_49 ;
* V_52 = V_2 ;
F_30 ( & V_2 -> V_24 ) ;
V_2 -> V_24 . V_29 = ( unsigned long ) V_2 ;
V_2 -> V_24 . V_55 = F_26 ;
F_30 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_29 = ( unsigned long ) V_2 ;
V_2 -> V_27 . V_55 = F_27 ;
F_31 ( & V_2 -> V_36 ) ;
F_31 ( & V_2 -> V_13 ) ;
F_31 ( & V_2 -> V_18 ) ;
F_32 ( & V_2 -> V_14 , F_22 ) ;
return F_33 ( V_2 , V_50 , V_51 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_27 ) ;
V_2 -> V_26 = false ;
V_2 -> V_23 = false ;
F_35 ( & V_2 -> V_36 ) ;
F_35 ( & V_2 -> V_13 ) ;
F_36 ( V_2 -> V_42 ) ;
}
