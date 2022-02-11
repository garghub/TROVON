int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 ( V_2 -> V_5 ) ;
V_2 -> V_6 = 1 ;
return 0 ;
}
void F_2 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
V_8 . V_9 = V_10 ;
V_8 . V_11 = 0 ;
V_2 -> V_3 -> V_4 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_12 , V_13 ,
sizeof( struct V_7 ) , ( V_14 * ) & V_8 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 -> V_15 ( V_2 -> V_5 ) ;
}
int F_4 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 V_18 = V_19 | V_20 |
V_21 ;
* F_5 ( V_17 , 1 ) = V_18 ;
F_6 ( & V_2 -> V_22 , V_17 ) ;
F_7 ( & V_2 -> V_23 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
int V_24 ;
unsigned long V_25 ;
if ( V_2 -> V_22 . V_26 )
F_9 ( L_1 ,
V_2 -> V_22 . V_26 , V_2 -> V_27 . V_26 ) ;
while ( V_2 -> V_22 . V_26 ) {
V_17 = F_10 ( & V_2 -> V_22 ) ;
F_11 ( L_2 , V_17 ) ;
V_24 = V_2 -> V_3 -> V_28 ( V_2 -> V_5 , V_17 ) ;
if ( V_24 < 0 ) {
V_2 -> V_29 = V_24 ;
break;
}
V_25 = V_30 ;
* ( unsigned long * ) V_17 -> V_31 = V_25 ;
F_6 ( & V_2 -> V_27 , V_17 ) ;
V_2 -> V_32 = true ;
F_12 ( & V_2 -> V_33 , V_25 +
F_13 ( V_34 ) ) ;
V_2 -> V_35 = true ;
F_12 ( & V_2 -> V_36 , V_25 +
F_13 ( V_37 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
T_1 V_18 ;
while ( ( V_17 = F_15 ( & V_2 -> V_27 ) ) ) {
V_18 = V_17 -> V_38 [ 0 ] ;
switch ( V_18 & V_39 ) {
case V_40 :
V_17 -> V_38 [ 0 ] = ( V_18 & ~ V_41 ) |
V_42 ;
break;
case V_19 :
V_17 -> V_38 [ 0 ] = ( V_18 & ~ V_43 ) |
V_44 ;
break;
default:
F_16 ( L_3 , V_18 ) ;
F_17 ( V_17 ) ;
continue;
}
F_18 ( & V_2 -> V_22 , V_17 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
T_1 V_18 ;
unsigned long V_25 ;
if ( V_2 -> V_45 . V_26 )
F_9 ( L_4 , V_2 -> V_45 . V_26 ) ;
while ( ( V_17 = F_10 ( & V_2 -> V_45 ) ) != NULL ) {
V_18 = V_17 -> V_38 [ 0 ] ;
F_20 ( V_17 , 1 ) ;
if ( ( V_18 & V_39 ) == V_40 ) {
switch ( V_18 & V_46 ) {
case V_47 :
F_21 ( & V_2 -> V_33 ) ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_35 = false ;
V_2 -> V_32 = false ;
break;
case V_48 :
F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
V_25 = V_30 ;
V_2 -> V_32 = true ;
F_12 ( & V_2 -> V_33 , V_25 +
F_13 ( V_34 ) ) ;
break;
case V_49 :
V_25 = V_30 ;
V_2 -> V_32 = true ;
F_12 ( & V_2 -> V_33 , V_25 +
F_13 ( V_50 ) ) ;
break;
default:
F_16 ( L_3 , V_18 ) ;
F_17 ( V_17 ) ;
break;
}
} else {
F_22 ( V_2 -> V_12 , V_17 ) ;
}
}
}
static void F_23 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_24 ( V_52 , struct V_1 , V_23 ) ;
F_8 ( V_2 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_32 && F_25 ( & V_2 -> V_33 ) == 0 ) {
F_9
( L_5 ) ;
V_2 -> V_32 = false ;
F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
}
if ( V_2 -> V_35 && F_25 ( & V_2 -> V_36 ) == 0 ) {
F_9 ( L_6 ) ;
V_2 -> V_35 = false ;
V_2 -> V_32 = false ;
F_21 ( & V_2 -> V_33 ) ;
F_21 ( & V_2 -> V_36 ) ;
F_2 ( V_2 ) ;
V_2 -> V_29 = - V_53 ;
}
}
void F_26 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_17 == NULL ) {
F_16 ( L_7 ) ;
V_2 -> V_29 = - V_53 ;
F_2 ( V_2 ) ;
} else {
F_11 ( L_8 , V_17 ) ;
F_6 ( & V_2 -> V_45 , V_17 ) ;
}
F_7 ( & V_2 -> V_23 ) ;
}
static void F_27 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
F_9 ( L_9 ) ;
F_7 ( & V_2 -> V_23 ) ;
}
static void F_28 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
F_9 ( L_9 ) ;
F_7 ( & V_2 -> V_23 ) ;
}
int F_29 ( void * V_5 , struct V_54 * V_55 , struct V_56 * V_57 ,
int V_58 , int V_59 , struct V_1 * * V_60 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( V_57 , sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_2 -> V_3 = V_55 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_6 = 0 ;
* V_60 = V_2 ;
F_31 ( & V_2 -> V_33 ) ;
V_2 -> V_33 . V_38 = ( unsigned long ) V_2 ;
V_2 -> V_33 . V_63 = F_27 ;
F_31 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_38 = ( unsigned long ) V_2 ;
V_2 -> V_36 . V_63 = F_28 ;
F_32 ( & V_2 -> V_45 ) ;
F_32 ( & V_2 -> V_22 ) ;
F_32 ( & V_2 -> V_27 ) ;
F_33 ( & V_2 -> V_23 , F_23 ) ;
return F_34 ( V_2 , V_58 , V_59 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_12 ) ;
F_21 ( & V_2 -> V_33 ) ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_35 = false ;
V_2 -> V_32 = false ;
F_37 ( & V_2 -> V_45 ) ;
F_37 ( & V_2 -> V_22 ) ;
}
