int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 = 0 ;
if ( V_2 -> V_9 & V_10 )
return V_11 ;
F_2 ( & V_2 -> V_12 ) ;
V_8 = F_3 ( V_2 -> V_13 ,
F_4 ( V_2 -> V_13 , 0 ) , V_3 , 0x40 , V_4 ,
V_5 , V_7 , V_6 , V_14 ) ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_8 < ( int ) V_6 )
return V_11 ;
return V_15 ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
F_1 ( V_2 , V_19 ,
V_17 , V_16 , sizeof( T_1 ) , & V_18 ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 ;
if ( V_2 -> V_9 & V_10 )
return V_11 ;
F_2 ( & V_2 -> V_12 ) ;
V_8 = F_3 ( V_2 -> V_13 ,
F_8 ( V_2 -> V_13 , 0 ) , V_3 , 0xc0 , V_4 ,
V_5 , V_7 , V_6 , V_14 ) ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_8 < ( int ) V_6 )
return V_11 ;
return V_15 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 , T_1 * V_18 )
{
F_7 ( V_2 , V_20 ,
V_17 , V_16 , sizeof( T_1 ) , V_18 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_8 = V_11 ;
if ( V_2 -> V_21 . V_22 == true )
return V_11 ;
V_2 -> V_21 . V_22 = true ;
F_11 ( V_2 -> V_23 ,
V_2 -> V_13 ,
F_12 ( V_2 -> V_13 , 1 ) ,
V_2 -> V_21 . V_24 ,
V_25 ,
V_26 ,
V_2 ,
V_2 -> V_27 ) ;
V_8 = F_13 ( V_2 -> V_23 , V_28 ) ;
if ( V_8 ) {
F_14 ( & V_2 -> V_13 -> V_29 , L_1 , V_8 ) ;
V_2 -> V_21 . V_22 = false ;
}
return V_8 ;
}
static void V_26 ( struct V_30 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_31 ;
int V_8 ;
switch ( V_30 -> V_8 ) {
case 0 :
case - V_32 :
break;
case - V_33 :
case - V_34 :
case - V_35 :
V_2 -> V_21 . V_22 = false ;
return;
default:
break;
}
V_8 = V_30 -> V_8 ;
if ( V_8 != V_15 ) {
V_2 -> V_21 . V_22 = false ;
F_14 ( & V_2 -> V_13 -> V_29 , L_2 , V_36 , V_8 ) ;
} else {
F_15 ( V_2 ) ;
}
V_8 = F_13 ( V_2 -> V_23 , V_28 ) ;
if ( V_8 ) {
F_14 ( & V_2 -> V_13 -> V_29 , L_1 , V_8 ) ;
} else {
V_2 -> V_21 . V_22 = true ;
}
return;
}
int F_16 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
int V_8 = 0 ;
struct V_30 * V_30 ;
if ( V_2 -> V_9 & V_10 )
return V_11 ;
V_30 = V_38 -> V_39 ;
if ( V_38 -> V_40 == NULL ) {
F_14 ( & V_2 -> V_13 -> V_29 , L_3 ) ;
return V_8 ;
}
F_17 ( V_30 ,
V_2 -> V_13 ,
F_18 ( V_2 -> V_13 , 2 ) ,
( void * ) ( V_38 -> V_40 -> V_18 ) ,
V_41 ,
V_42 ,
V_38 ) ;
V_8 = F_13 ( V_30 , V_28 ) ;
if ( V_8 != 0 ) {
F_14 ( & V_2 -> V_13 -> V_29 , L_4 , V_8 ) ;
return V_11 ;
}
V_38 -> V_43 = 1 ;
V_38 -> V_44 = true ;
return V_8 ;
}
static void V_42 ( struct V_30 * V_30 )
{
struct V_37 * V_38 = V_30 -> V_31 ;
struct V_1 * V_2 = V_38 -> V_45 ;
unsigned long V_46 ;
int V_47 = false ;
switch ( V_30 -> V_8 ) {
case 0 :
break;
case - V_33 :
case - V_34 :
case - V_35 :
return;
case - V_32 :
default:
F_14 ( & V_2 -> V_13 -> V_29 , L_5 , V_30 -> V_8 ) ;
break;
}
if ( V_30 -> V_48 ) {
F_19 ( & V_2 -> V_49 , V_46 ) ;
if ( F_20 ( V_2 , V_38 , V_30 -> V_48 ) == true )
V_47 = true ;
F_21 ( & V_2 -> V_49 , V_46 ) ;
}
V_38 -> V_43 -- ;
if ( V_38 -> V_43 == 0 ) {
F_14 ( & V_2 -> V_13 -> V_29 ,
L_6 , V_2 -> V_50 ) ;
F_19 ( & V_2 -> V_49 , V_46 ) ;
F_22 ( V_38 , V_47 ) ;
F_21 ( & V_2 -> V_49 , V_46 ) ;
}
return;
}
int F_23 ( struct V_1 * V_2 ,
struct V_51 * V_31 )
{
int V_8 ;
struct V_30 * V_30 ;
V_2 -> V_52 = false ;
if ( ! ( F_24 ( V_2 ) && V_2 -> V_9 & V_53 ) ) {
V_31 -> V_22 = false ;
return V_54 ;
}
V_30 = V_31 -> V_30 ;
F_17 ( V_30 ,
V_2 -> V_13 ,
F_25 ( V_2 -> V_13 , 3 ) ,
V_31 -> V_18 ,
V_31 -> V_55 ,
V_56 ,
V_31 ) ;
V_8 = F_13 ( V_30 , V_28 ) ;
if ( V_8 != 0 ) {
F_14 ( & V_2 -> V_13 -> V_29 , L_7 , V_8 ) ;
V_31 -> V_22 = false ;
return V_11 ;
}
return V_57 ;
}
static void V_56 ( struct V_30 * V_30 )
{
struct V_51 * V_31 = V_30 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_1 V_58 = V_31 -> type ;
switch ( V_30 -> V_8 ) {
case 0 :
F_14 ( & V_2 -> V_13 -> V_29 , L_8 , V_31 -> V_55 ) ;
break;
case - V_33 :
case - V_34 :
case - V_35 :
V_31 -> V_22 = false ;
return;
case - V_32 :
default:
F_14 ( & V_2 -> V_13 -> V_29 , L_9 , V_30 -> V_8 ) ;
break;
}
if ( ! F_26 ( V_2 -> V_29 ) )
return;
if ( V_59 == V_58 ) {
if ( V_31 -> V_40 != NULL ) {
F_27 ( V_31 -> V_40 ) ;
V_31 -> V_40 = NULL ;
F_14 ( & V_2 -> V_13 -> V_29 ,
L_10 , V_31 -> V_55 ) ;
}
V_2 -> V_29 -> V_60 = V_61 ;
}
if ( V_2 -> V_62 == true ) {
if ( F_28 ( V_2 -> V_29 ) )
F_29 ( V_2 -> V_29 ) ;
}
V_31 -> V_22 = false ;
return;
}
