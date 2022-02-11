int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 = 0 ;
T_1 * V_9 ;
if ( F_2 ( V_10 , & V_2 -> V_11 ) )
return V_12 ;
F_3 ( & V_2 -> V_13 ) ;
V_9 = F_4 ( V_7 , V_6 , V_14 ) ;
if ( ! V_9 ) {
F_5 ( & V_2 -> V_13 ) ;
return - V_15 ;
}
V_8 = F_6 ( V_2 -> V_16 ,
F_7 ( V_2 -> V_16 , 0 ) ,
V_3 , 0x40 , V_4 ,
V_5 , V_9 , V_6 , V_17 ) ;
F_8 ( V_9 ) ;
F_5 ( & V_2 -> V_13 ) ;
if ( V_8 < ( int ) V_6 )
return V_12 ;
return V_18 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 , T_1 V_21 )
{
F_1 ( V_2 , V_22 ,
V_20 , V_19 , sizeof( T_1 ) , & V_21 ) ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 )
{
int V_8 ;
T_1 * V_9 ;
if ( F_2 ( V_10 , & V_2 -> V_11 ) )
return V_12 ;
F_3 ( & V_2 -> V_13 ) ;
V_9 = F_11 ( V_6 , V_14 ) ;
if ( ! V_9 ) {
F_5 ( & V_2 -> V_13 ) ;
return - V_15 ;
}
V_8 = F_6 ( V_2 -> V_16 ,
F_12 ( V_2 -> V_16 , 0 ) ,
V_3 , 0xc0 , V_4 ,
V_5 , V_9 , V_6 , V_17 ) ;
if ( V_8 == V_6 )
memcpy ( V_7 , V_9 , V_6 ) ;
F_8 ( V_9 ) ;
F_5 ( & V_2 -> V_13 ) ;
if ( V_8 < ( int ) V_6 )
return V_12 ;
return V_18 ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 , T_1 * V_21 )
{
F_10 ( V_2 , V_23 ,
V_20 , V_19 , sizeof( T_1 ) , V_21 ) ;
}
static void F_14 ( struct V_24 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
int V_8 = V_24 -> V_8 ;
switch ( V_8 ) {
case 0 :
case - V_26 :
break;
case - V_27 :
case - V_28 :
case - V_29 :
V_2 -> V_30 . V_31 = false ;
return;
default:
break;
}
if ( V_8 ) {
V_2 -> V_30 . V_31 = false ;
F_15 ( & V_2 -> V_16 -> V_32 , L_1 , V_33 , V_8 ) ;
} else {
F_16 ( V_2 ) ;
}
V_8 = F_17 ( V_2 -> V_34 , V_35 ) ;
if ( V_8 )
F_15 ( & V_2 -> V_16 -> V_32 , L_2 , V_8 ) ;
else
V_2 -> V_30 . V_31 = true ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_8 = V_12 ;
if ( V_2 -> V_30 . V_31 )
return V_12 ;
V_2 -> V_30 . V_31 = true ;
F_19 ( V_2 -> V_34 ,
V_2 -> V_16 ,
F_20 ( V_2 -> V_16 , 1 ) ,
V_2 -> V_30 . V_36 ,
V_37 ,
F_14 ,
V_2 ,
V_2 -> V_38 ) ;
V_8 = F_17 ( V_2 -> V_34 , V_35 ) ;
if ( V_8 ) {
F_15 ( & V_2 -> V_16 -> V_32 , L_2 , V_8 ) ;
V_2 -> V_30 . V_31 = false ;
}
return V_8 ;
}
static void F_21 ( struct V_24 * V_24 )
{
struct V_39 * V_40 = V_24 -> V_25 ;
struct V_1 * V_2 = V_40 -> V_2 ;
switch ( V_24 -> V_8 ) {
case 0 :
break;
case - V_27 :
case - V_28 :
case - V_29 :
return;
case - V_26 :
default:
F_15 ( & V_2 -> V_16 -> V_32 , L_3 , V_24 -> V_8 ) ;
break;
}
if ( V_24 -> V_41 ) {
if ( F_22 ( V_2 , V_40 , V_24 -> V_41 ) ) {
V_40 -> V_42 = F_23 ( V_2 -> V_43 ) ;
if ( ! V_40 -> V_42 ) {
F_15 ( & V_2 -> V_16 -> V_32 ,
L_4 ) ;
V_40 -> V_31 = false ;
return;
}
} else {
F_24 ( V_40 -> V_42 , F_25 ( V_40 -> V_42 ) ) ;
F_26 ( V_40 -> V_42 , 0 ) ;
}
V_24 -> V_44 = F_27 ( V_40 -> V_42 ,
F_28 ( V_40 -> V_42 ) ) ;
}
if ( F_17 ( V_24 , V_35 ) ) {
F_15 ( & V_2 -> V_16 -> V_32 , L_5 ) ;
V_40 -> V_31 = false ;
}
}
int F_29 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
int V_8 = 0 ;
struct V_24 * V_24 = V_40 -> V_24 ;
if ( ! V_40 -> V_42 ) {
F_15 ( & V_2 -> V_16 -> V_32 , L_6 ) ;
return V_8 ;
}
F_30 ( V_24 ,
V_2 -> V_16 ,
F_31 ( V_2 -> V_16 , 2 ) ,
F_27 ( V_40 -> V_42 , F_28 ( V_40 -> V_42 ) ) ,
V_45 ,
F_21 ,
V_40 ) ;
V_8 = F_17 ( V_24 , V_35 ) ;
if ( V_8 ) {
F_15 ( & V_2 -> V_16 -> V_32 , L_7 , V_8 ) ;
return V_12 ;
}
V_40 -> V_31 = true ;
return V_8 ;
}
static void F_32 ( struct V_24 * V_24 )
{
struct V_46 * V_25 = V_24 -> V_25 ;
struct V_1 * V_2 = V_25 -> V_2 ;
switch ( V_24 -> V_8 ) {
case 0 :
F_15 ( & V_2 -> V_16 -> V_32 , L_8 , V_25 -> V_47 ) ;
break;
case - V_27 :
case - V_28 :
case - V_29 :
V_25 -> V_31 = false ;
return;
case - V_26 :
default:
F_15 ( & V_2 -> V_16 -> V_32 , L_9 , V_24 -> V_8 ) ;
break;
}
if ( V_25 -> type == V_48 )
F_33 ( V_2 -> V_49 ) ;
if ( V_24 -> V_8 || V_25 -> type == V_50 ) {
if ( V_25 -> V_42 )
F_34 ( V_2 -> V_49 , V_25 -> V_42 ) ;
V_25 -> V_31 = false ;
}
}
int F_35 ( struct V_1 * V_2 ,
struct V_46 * V_25 )
{
int V_8 ;
struct V_24 * V_24 = V_25 -> V_24 ;
if ( F_2 ( V_10 , & V_2 -> V_11 ) ) {
V_25 -> V_31 = false ;
return V_51 ;
}
F_30 ( V_24 ,
V_2 -> V_16 ,
F_36 ( V_2 -> V_16 , 3 ) ,
V_25 -> V_21 ,
V_25 -> V_47 ,
F_32 ,
V_25 ) ;
V_8 = F_17 ( V_24 , V_35 ) ;
if ( V_8 ) {
F_15 ( & V_2 -> V_16 -> V_32 , L_10 , V_8 ) ;
V_25 -> V_31 = false ;
return V_12 ;
}
return V_52 ;
}
