static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 ;
V_6 = F_3 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_7 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_8 ) {
V_6 = F_5 ( V_2 -> V_8 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_2 -> V_9 )
V_6 = F_6 ( V_2 -> V_9 ) ;
else if ( V_2 -> V_10 && V_2 -> V_10 -> V_11 )
V_6 = V_2 -> V_10 -> V_11 ( V_4 , V_2 -> V_10 -> V_12 ) ;
else {
V_6 = F_7 ( V_2 -> V_13 ) ;
if ( V_6 == 0 )
V_6 = V_11 ( V_2 -> V_13 ) ;
}
return V_6 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_6 = F_1 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_14 = true ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 = 0 ;
if ( V_2 -> V_9 )
F_10 ( V_2 -> V_9 ) ;
else if ( V_2 -> V_10 && V_2 -> V_10 -> V_15 )
V_6 = V_2 -> V_10 -> V_15 ( V_4 , V_2 -> V_10 -> V_12 ) ;
else {
V_6 = V_15 ( V_2 -> V_13 ) ;
if ( V_6 == 0 )
V_6 = F_11 ( V_2 -> V_13 ) ;
}
if ( V_6 )
return V_6 ;
if ( V_2 -> V_8 )
F_12 ( V_2 -> V_8 ) ;
V_6 = F_13 ( F_4 ( V_2 -> V_7 ) ,
V_2 -> V_7 ) ;
return V_6 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_6 = F_9 ( V_2 ) ;
if ( V_6 == 0 )
V_2 -> V_14 = false ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_16 , V_6 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_13 = F_16 ( V_2 -> V_5 , L_1 ) ;
if ( F_17 ( V_2 -> V_13 ) ) {
V_6 = F_18 ( V_2 -> V_13 ) ;
switch ( V_6 ) {
case - V_19 :
case - V_20 :
V_2 -> V_13 = NULL ;
break;
case - V_21 :
return V_6 ;
default:
F_19 ( V_2 -> V_5 , L_2 , V_6 ) ;
return V_6 ;
}
}
if ( ! V_2 -> V_13 ) {
V_2 -> V_9 = F_20 ( V_2 -> V_5 , V_22 ) ;
if ( F_17 ( V_2 -> V_9 ) ) {
V_6 = F_18 ( V_2 -> V_9 ) ;
switch ( V_6 ) {
case - V_19 :
case - V_23 :
V_2 -> V_9 = NULL ;
break;
case - V_21 :
return V_6 ;
default:
F_19 ( V_2 -> V_5 , L_3 ,
V_6 ) ;
return V_6 ;
}
}
}
V_2 -> V_10 = F_21 ( V_2 -> V_5 ) ;
if ( V_2 -> V_13 ) {
if ( F_22 ( V_2 -> V_13 ) == 8 )
V_2 -> V_17 = V_24 ;
}
V_2 -> V_8 = F_23 ( V_2 -> V_5 , L_4 ) ;
if ( F_17 ( V_2 -> V_8 ) ) {
V_2 -> V_8 = NULL ;
F_24 ( V_2 -> V_5 , L_5 ) ;
}
for ( V_16 = 0 ; V_16 < F_4 ( V_2 -> V_7 ) ; V_16 ++ )
V_2 -> V_7 [ V_16 ] . V_25 = V_26 [ V_16 ] ;
V_6 = F_25 ( V_2 -> V_5 , F_4 ( V_2 -> V_7 ) ,
V_2 -> V_7 ) ;
if ( V_6 ) {
F_19 ( V_2 -> V_5 , L_6 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_26 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = F_27 ( V_5 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_27 )
F_29 ( V_2 ) ;
if ( V_2 -> V_28 )
F_30 ( V_2 ) ;
if ( V_2 -> V_14 )
F_14 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_5 )
{
const struct V_29 * V_30 ;
const struct V_31 * V_32 ;
struct V_31 V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_36 ;
int V_37 ;
V_30 = F_32 ( V_38 , & V_5 -> V_5 ) ;
if ( V_30 && V_30 -> V_39 ) {
V_32 = V_30 -> V_39 ;
} else {
F_33 ( & V_33 , - 1 ) ;
V_32 = & V_33 ;
V_33 . V_40 = 0 ;
}
V_2 = F_34 ( & V_5 -> V_5 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_5 = & V_5 -> V_5 ;
if ( ! V_5 -> V_5 . V_43 )
V_5 -> V_5 . V_43 = & V_5 -> V_5 . V_44 ;
V_36 = F_35 ( & V_5 -> V_5 , F_36 ( 32 ) ) ;
if ( V_36 )
return V_36 ;
V_35 = F_37 ( V_5 , V_45 , 0 ) ;
V_2 -> V_46 = F_38 ( & V_5 -> V_5 , V_35 ) ;
if ( F_17 ( V_2 -> V_46 ) )
return F_18 ( V_2 -> V_46 ) ;
F_24 ( & V_5 -> V_5 , L_7 ,
( unsigned long ) V_35 -> V_47 , V_2 -> V_46 ) ;
V_2 -> V_48 = F_39 ( & V_5 -> V_5 ) ;
if ( F_40 ( V_49 ) &&
V_2 -> V_48 != V_50 ) {
V_2 -> V_48 = V_50 ;
F_41 ( V_2 -> V_5 ,
L_8 ) ;
} else if ( F_40 ( V_51 ) &&
V_2 -> V_48 != V_52 ) {
V_2 -> V_48 = V_52 ;
F_41 ( V_2 -> V_5 ,
L_9 ) ;
}
V_36 = F_15 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_42 ( & V_2 -> V_53 ) ;
V_2 -> V_54 = F_34 ( & V_5 -> V_5 ,
sizeof( * V_2 -> V_54 ) , V_41 ) ;
if ( ! V_2 -> V_54 )
return - V_42 ;
F_33 ( V_2 -> V_54 , - 1 ) ;
V_37 = F_43 ( V_5 , 0 ) ;
if ( V_37 < 0 ) {
F_19 ( & V_5 -> V_5 , L_10 ) ;
return V_37 ;
}
F_24 ( V_2 -> V_5 , L_11 ,
V_37 ) ;
V_36 = F_44 ( V_2 -> V_5 , V_37 ,
V_55 , V_56 ,
F_45 ( V_2 -> V_5 ) , V_2 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_46 ( V_2 ) ;
if ( V_36 )
goto error;
F_47 ( V_2 , V_32 ) ;
if ( V_2 -> V_48 != V_50 ) {
V_36 = F_48 ( V_2 , V_37 ) ;
if ( V_36 )
goto error;
V_2 -> V_28 = 1 ;
}
if ( V_2 -> V_48 != V_52 ) {
V_36 = F_49 ( V_2 , V_37 ) ;
if ( V_36 ) {
if ( V_2 -> V_28 )
F_30 ( V_2 ) ;
goto error;
}
V_2 -> V_27 = 1 ;
}
F_50 ( V_5 , V_2 ) ;
F_51 ( V_2 ) ;
if ( V_2 -> V_48 == V_52 )
F_14 ( V_2 ) ;
return 0 ;
error:
F_14 ( V_2 ) ;
return V_36 ;
}
static int T_1 F_52 ( struct V_57 * V_5 )
{
struct V_1 * V_58 = F_53 ( V_5 ) ;
int V_6 = 0 ;
if ( F_54 ( V_58 ) )
F_55 ( V_58 ) ;
if ( V_58 -> V_14 )
V_6 = F_9 ( V_58 ) ;
return V_6 ;
}
static int T_1 F_56 ( struct V_57 * V_5 )
{
struct V_1 * V_58 = F_53 ( V_5 ) ;
int V_6 = 0 ;
if ( V_58 -> V_14 ) {
V_6 = F_1 ( V_58 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_54 ( V_58 ) )
V_6 = F_57 ( V_58 ) ;
return V_6 ;
}
