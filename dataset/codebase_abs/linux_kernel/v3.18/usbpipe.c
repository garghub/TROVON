int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 = 0 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) )
return V_11 ;
F_3 ( & V_2 -> V_12 ) ;
V_8 = F_4 ( V_2 -> V_13 ,
F_5 ( V_2 -> V_13 , 0 ) , V_3 , 0x40 , V_4 ,
V_5 , V_7 , V_6 , V_14 ) ;
F_6 ( & V_2 -> V_12 ) ;
if ( V_8 < ( int ) V_6 )
return V_11 ;
return V_15 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
F_1 ( V_2 , V_19 ,
V_17 , V_16 , sizeof( T_1 ) , & V_18 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) )
return V_11 ;
F_3 ( & V_2 -> V_12 ) ;
V_8 = F_4 ( V_2 -> V_13 ,
F_9 ( V_2 -> V_13 , 0 ) , V_3 , 0xc0 , V_4 ,
V_5 , V_7 , V_6 , V_14 ) ;
F_6 ( & V_2 -> V_12 ) ;
if ( V_8 < ( int ) V_6 )
return V_11 ;
return V_15 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 , T_1 * V_18 )
{
F_8 ( V_2 , V_20 ,
V_17 , V_16 , sizeof( T_1 ) , V_18 ) ;
}
static void F_11 ( struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_8 ;
switch ( V_21 -> V_8 ) {
case 0 :
case - V_23 :
break;
case - V_24 :
case - V_25 :
case - V_26 :
V_2 -> V_27 . V_28 = false ;
return;
default:
break;
}
V_8 = V_21 -> V_8 ;
if ( V_8 != V_15 ) {
V_2 -> V_27 . V_28 = false ;
F_12 ( & V_2 -> V_13 -> V_29 , L_1 , V_30 , V_8 ) ;
} else {
F_13 ( V_2 ) ;
}
V_8 = F_14 ( V_2 -> V_31 , V_32 ) ;
if ( V_8 )
F_12 ( & V_2 -> V_13 -> V_29 , L_2 , V_8 ) ;
else
V_2 -> V_27 . V_28 = true ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_8 = V_11 ;
if ( V_2 -> V_27 . V_28 == true )
return V_11 ;
V_2 -> V_27 . V_28 = true ;
F_16 ( V_2 -> V_31 ,
V_2 -> V_13 ,
F_17 ( V_2 -> V_13 , 1 ) ,
V_2 -> V_27 . V_33 ,
V_34 ,
F_11 ,
V_2 ,
V_2 -> V_35 ) ;
V_8 = F_14 ( V_2 -> V_31 , V_32 ) ;
if ( V_8 ) {
F_12 ( & V_2 -> V_13 -> V_29 , L_2 , V_8 ) ;
V_2 -> V_27 . V_28 = false ;
}
return V_8 ;
}
static void F_18 ( struct V_21 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_22 ;
struct V_1 * V_2 = V_37 -> V_2 ;
unsigned long V_10 ;
switch ( V_21 -> V_8 ) {
case 0 :
break;
case - V_24 :
case - V_25 :
case - V_26 :
return;
case - V_23 :
default:
F_12 ( & V_2 -> V_13 -> V_29 , L_3 , V_21 -> V_8 ) ;
break;
}
if ( V_21 -> V_38 ) {
F_19 ( & V_2 -> V_39 , V_10 ) ;
if ( F_20 ( V_2 , V_37 , V_21 -> V_38 ) ) {
V_37 -> V_40 = F_21 ( V_2 -> V_41 ) ;
if ( ! V_37 -> V_40 ) {
F_12 ( & V_2 -> V_13 -> V_29 ,
L_4 ) ;
V_37 -> V_28 = false ;
F_22 ( & V_2 -> V_39 , V_10 ) ;
return;
}
} else {
F_23 ( V_37 -> V_40 , F_24 ( V_37 -> V_40 ) ) ;
F_25 ( V_37 -> V_40 , 0 ) ;
}
V_21 -> V_42 = F_26 ( V_37 -> V_40 ,
F_27 ( V_37 -> V_40 ) ) ;
F_22 ( & V_2 -> V_39 , V_10 ) ;
}
if ( F_14 ( V_21 , V_32 ) ) {
F_12 ( & V_2 -> V_13 -> V_29 , L_5 ) ;
V_37 -> V_28 = false ;
}
}
int F_28 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_8 = 0 ;
struct V_21 * V_21 ;
V_21 = V_37 -> V_21 ;
if ( V_37 -> V_40 == NULL ) {
F_12 ( & V_2 -> V_13 -> V_29 , L_6 ) ;
return V_8 ;
}
F_29 ( V_21 ,
V_2 -> V_13 ,
F_30 ( V_2 -> V_13 , 2 ) ,
F_26 ( V_37 -> V_40 , F_27 ( V_37 -> V_40 ) ) ,
V_43 ,
F_18 ,
V_37 ) ;
V_8 = F_14 ( V_21 , V_32 ) ;
if ( V_8 != 0 ) {
F_12 ( & V_2 -> V_13 -> V_29 , L_7 , V_8 ) ;
return V_11 ;
}
V_37 -> V_28 = true ;
return V_8 ;
}
static void F_31 ( struct V_21 * V_21 )
{
struct V_44 * V_22 = V_21 -> V_22 ;
struct V_1 * V_2 = V_22 -> V_2 ;
switch ( V_21 -> V_8 ) {
case 0 :
F_12 ( & V_2 -> V_13 -> V_29 , L_8 , V_22 -> V_45 ) ;
break;
case - V_24 :
case - V_25 :
case - V_26 :
V_22 -> V_28 = false ;
return;
case - V_23 :
default:
F_12 ( & V_2 -> V_13 -> V_29 , L_9 , V_21 -> V_8 ) ;
break;
}
if ( V_22 -> type == V_46 )
F_32 ( V_2 -> V_47 ) ;
if ( V_21 -> V_8 || V_22 -> type == V_48 ) {
if ( V_22 -> V_40 )
F_33 ( V_2 -> V_47 , V_22 -> V_40 ) ;
V_22 -> V_28 = false ;
}
}
int F_34 ( struct V_1 * V_2 ,
struct V_44 * V_22 )
{
int V_8 ;
struct V_21 * V_21 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) ) {
V_22 -> V_28 = false ;
return V_49 ;
}
V_21 = V_22 -> V_21 ;
F_29 ( V_21 ,
V_2 -> V_13 ,
F_35 ( V_2 -> V_13 , 3 ) ,
V_22 -> V_18 ,
V_22 -> V_45 ,
F_31 ,
V_22 ) ;
V_8 = F_14 ( V_21 , V_32 ) ;
if ( V_8 != 0 ) {
F_12 ( & V_2 -> V_13 -> V_29 , L_10 , V_8 ) ;
V_22 -> V_28 = false ;
return V_11 ;
}
return V_50 ;
}
