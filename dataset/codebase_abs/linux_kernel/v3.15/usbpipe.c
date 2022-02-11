int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 ;
if ( V_2 -> V_9 & V_10 )
return V_11 ;
if ( V_2 -> V_9 & V_12 )
return V_11 ;
if ( F_2 () ) {
F_3 ( V_13 , V_14 L_1 , V_3 ) ;
return V_11 ;
}
V_8 = F_4 (
V_2 -> V_15 ,
F_5 ( V_2 -> V_15 , 0 ) ,
V_3 ,
0x40 ,
V_4 ,
V_5 ,
( void * ) V_7 ,
V_6 ,
V_16
) ;
if ( V_8 >= 0 ) {
F_3 ( V_13 , V_14 L_2 , V_8 ) ;
V_8 = 0 ;
} else {
F_3 ( V_13 , V_14 L_3 , V_8 ) ;
}
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
__releases( &pDevice->lock
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
__releases( &pDevice->lock
static void F_8 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
V_2 = V_17 -> V_18 ;
switch ( V_17 -> V_19 ) {
case 0 :
break;
case - V_20 :
F_3 ( V_13 , V_14 L_4 , V_17 -> V_19 ) ;
break;
case - V_21 :
F_3 ( V_13 , V_14 L_5 , V_17 -> V_19 ) ;
break;
default:
F_3 ( V_13 , V_14 L_6 , V_17 -> V_19 ) ;
}
F_9 ( V_2 , V_12 ) ;
}
static void F_10 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
switch ( V_17 -> V_19 ) {
case 0 :
break;
case - V_20 :
F_3 ( V_13 , V_14 L_7 , V_17 -> V_19 ) ;
break;
case - V_21 :
F_3 ( V_13 , V_14 L_8 , V_17 -> V_19 ) ;
break;
default:
F_3 ( V_13 , V_14 L_9 , V_17 -> V_19 ) ;
}
F_9 ( V_2 , V_22 ) ;
}
int F_11 ( struct V_1 * V_23 )
{
int V_19 = V_11 ;
F_3 ( V_13 , V_14
L_10 ) ;
if ( V_23 -> V_24 . V_25 == true )
return V_11 ;
V_23 -> V_24 . V_25 = true ;
F_12 ( V_23 -> V_26 ,
V_23 -> V_15 ,
F_13 ( V_23 -> V_15 , 1 ) ,
V_23 -> V_24 . V_27 ,
V_28 ,
V_29 ,
V_23 ,
V_23 -> V_30 ) ;
V_19 = F_14 ( V_23 -> V_26 , V_31 ) ;
if ( V_19 ) {
F_3 ( V_13 , V_14
L_11 , V_19 ) ;
V_23 -> V_24 . V_25 = false ;
}
F_3 ( V_13 , V_14
L_12 , V_19 ) ;
return V_19 ;
}
static void V_29 ( struct V_17 * V_17 )
{
struct V_1 * V_23 = V_17 -> V_18 ;
int V_19 ;
F_3 ( V_13 , V_14
L_13 ) ;
switch ( V_17 -> V_19 ) {
case 0 :
case - V_32 :
break;
case - V_33 :
case - V_21 :
case - V_34 :
V_23 -> V_24 . V_25 = false ;
return;
default:
break;
}
V_19 = V_17 -> V_19 ;
F_3 ( V_13 , V_14
L_14 , V_19 ) ;
if ( V_19 != V_35 ) {
V_23 -> V_24 . V_25 = false ;
F_3 ( V_13 , V_14
L_15 , V_19 ) ;
} else {
F_15 ( V_23 ) ;
}
V_19 = F_14 ( V_23 -> V_26 , V_31 ) ;
if ( V_19 ) {
F_3 ( V_13 , V_14
L_11 , V_19 ) ;
} else {
V_23 -> V_24 . V_25 = true ;
}
return;
}
int F_16 ( struct V_1 * V_23 , struct V_36 * V_37 )
{
int V_19 = 0 ;
struct V_17 * V_17 ;
F_3 ( V_13 , V_14 L_16 ) ;
if ( V_23 -> V_9 & V_10 )
return V_11 ;
V_17 = V_37 -> V_38 ;
if ( V_37 -> V_39 == NULL ) {
F_3 ( V_13 , V_14 L_17 ) ;
return V_19 ;
}
F_17 ( V_17 ,
V_23 -> V_15 ,
F_18 ( V_23 -> V_15 , 2 ) ,
( void * ) ( V_37 -> V_39 -> V_40 ) ,
V_41 ,
V_42 ,
V_37 ) ;
V_19 = F_14 ( V_17 , V_31 ) ;
if ( V_19 != 0 ) {
F_3 ( V_13 , V_14
L_18 , V_19 ) ;
return V_11 ;
}
V_37 -> V_43 = 1 ;
V_37 -> V_44 = true ;
return V_19 ;
}
static void V_42 ( struct V_17 * V_17 )
{
struct V_36 * V_37 = V_17 -> V_18 ;
struct V_1 * V_23 = V_37 -> V_2 ;
int V_45 = false ;
F_3 ( V_13 , V_14 L_19 ) ;
switch ( V_17 -> V_19 ) {
case 0 :
break;
case - V_33 :
case - V_21 :
case - V_34 :
return;
case - V_32 :
default:
F_3 ( V_13 , V_14
L_20 , V_17 -> V_19 ) ;
break;
}
if ( V_17 -> V_46 ) {
F_19 ( & V_23 -> V_47 ) ;
if ( F_20 ( V_23 , V_37 , V_17 -> V_46 ) == true )
V_45 = true ;
F_21 ( & V_23 -> V_47 ) ;
}
V_37 -> V_43 -- ;
if ( V_37 -> V_43 == 0 ) {
F_3 ( V_13 , V_14 L_21 ,
V_23 -> V_48 ) ;
F_19 ( & V_23 -> V_47 ) ;
F_22 ( V_37 , V_45 ) ;
F_21 ( & V_23 -> V_47 ) ;
}
return;
}
int F_23 ( struct V_1 * V_23 ,
struct V_49 * V_18 )
{
int V_19 ;
struct V_17 * V_17 ;
V_23 -> V_50 = false ;
F_3 ( V_13 , V_14 L_22 ) ;
if ( ! ( F_24 ( V_23 ) && V_23 -> V_9 & V_51 ) ) {
V_18 -> V_44 = false ;
return V_52 ;
}
V_17 = V_18 -> V_38 ;
F_17 ( V_17 ,
V_23 -> V_15 ,
F_25 ( V_23 -> V_15 , 3 ) ,
V_18 -> V_53 ,
V_18 -> V_54 ,
V_55 ,
V_18 ) ;
V_19 = F_14 ( V_17 , V_31 ) ;
if ( V_19 != 0 ) {
F_3 ( V_13 , V_14
L_23 , V_19 ) ;
V_18 -> V_44 = false ;
return V_11 ;
}
return V_56 ;
}
static void V_55 ( struct V_17 * V_17 )
{
struct V_49 * V_18 = V_17 -> V_18 ;
struct V_1 * V_23 = V_18 -> V_2 ;
T_1 V_57 = V_18 -> type ;
F_3 ( V_13 , V_14 L_24 ) ;
switch ( V_17 -> V_19 ) {
case 0 :
F_3 ( V_13 , V_14
L_25 , V_18 -> V_54 ) ;
break;
case - V_33 :
case - V_21 :
case - V_34 :
V_18 -> V_44 = false ;
return;
case - V_32 :
default:
F_3 ( V_13 , V_14
L_26 , V_17 -> V_19 ) ;
break;
}
if ( ! F_26 ( V_23 -> V_58 ) )
return;
if ( V_59 == V_57 ) {
if ( V_18 -> V_60 != NULL ) {
F_27 ( V_18 -> V_60 ) ;
V_18 -> V_60 = NULL ;
F_3 ( V_13 , V_14
L_27 , V_18 -> V_54 ) ;
}
V_23 -> V_58 -> V_61 = V_62 ;
}
if ( V_23 -> V_63 == true ) {
if ( F_28 ( V_23 -> V_58 ) )
F_29 ( V_23 -> V_58 ) ;
}
V_18 -> V_44 = false ;
return;
}
