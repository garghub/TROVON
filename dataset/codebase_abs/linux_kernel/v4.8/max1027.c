static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( & V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_8 -> V_11 = V_12 | V_13 | V_14 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 ,
L_2 ) ;
return V_6 ;
}
V_8 -> V_11 = V_16 | F_7 ( V_4 -> V_17 ) |
V_18 | ! ! ( V_4 -> type == V_19 ) ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 ,
L_3 ) ;
return V_6 ;
}
F_8 ( 1 ) ;
V_6 = F_9 ( V_8 -> V_15 , V_8 -> V_20 , ( V_4 -> type == V_19 ) ? 4 : 2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_5 = F_10 ( V_8 -> V_20 [ 0 ] ) ;
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_22 , long V_23 )
{
int V_6 = 0 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_12 ( & V_8 -> V_24 ) ;
switch ( V_23 ) {
case V_25 :
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
break;
case V_26 :
switch ( V_4 -> type ) {
case V_19 :
* V_5 = 1 ;
* V_22 = 8 ;
V_6 = V_27 ;
break;
case V_28 :
* V_5 = 2500 ;
* V_22 = 10 ;
V_6 = V_29 ;
break;
default:
V_6 = - V_30 ;
break;
}
break;
default:
V_6 = - V_30 ;
break;
}
F_13 ( & V_8 -> V_24 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_11 , unsigned V_31 ,
unsigned * V_32 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 * V_5 = ( T_1 * ) V_8 -> V_20 ;
if ( V_32 != NULL )
return - V_30 ;
* V_5 = ( T_1 ) V_31 ;
return F_5 ( V_8 -> V_15 , V_5 , 1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_34 != V_34 )
return - V_30 ;
return 0 ;
}
static int F_16 ( struct V_33 * V_34 , bool V_35 )
{
struct V_1 * V_2 = F_17 ( V_34 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_35 ) {
V_8 -> V_11 = V_12 | V_36 |
V_13 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_8 -> V_11 = V_16 | F_7 ( 0 ) |
V_37 | V_38 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
V_8 -> V_11 = V_12 | V_14 |
V_13 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_1 * V_2 )
{
struct V_1 * V_39 = F_17 ( V_34 ) ;
if ( V_39 != V_2 )
return - V_30 ;
return 0 ;
}
static T_2 F_19 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = (struct V_42 * ) V_41 ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_20 ( L_4 , V_44 , V_40 , V_41 ) ;
F_9 ( V_8 -> V_15 , V_8 -> V_20 , V_2 -> V_45 * 2 ) ;
F_21 ( V_2 , V_8 -> V_20 ) ;
F_22 ( V_2 -> V_34 ) ;
return V_46 ;
}
static int F_23 ( struct V_47 * V_15 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
F_20 ( L_5 , V_44 , V_15 ) ;
V_2 = F_24 ( & V_15 -> V_9 , sizeof( * V_8 ) ) ;
if ( V_2 == NULL ) {
F_25 ( L_6 ) ;
return - V_48 ;
}
F_26 ( V_15 , V_2 ) ;
V_8 = F_2 ( V_2 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_49 = & V_50 [ F_27 ( V_15 ) -> V_51 ] ;
F_28 ( & V_8 -> V_24 ) ;
V_2 -> V_52 = F_27 ( V_15 ) -> V_52 ;
V_2 -> V_9 . V_53 = & V_15 -> V_9 ;
V_2 -> V_9 . V_54 = V_15 -> V_9 . V_54 ;
V_2 -> V_49 = & V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = V_8 -> V_49 -> V_58 ;
V_2 -> V_59 = V_8 -> V_49 -> V_59 ;
V_2 -> V_60 = V_8 -> V_49 -> V_60 ;
V_8 -> V_20 = F_29 ( & V_2 -> V_9 ,
V_2 -> V_59 * 2 ,
V_61 ) ;
if ( V_8 -> V_20 == NULL ) {
F_6 ( & V_2 -> V_9 , L_7 ) ;
return - V_48 ;
}
V_6 = F_30 ( V_2 , & V_62 ,
& F_19 , NULL ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_8 ) ;
return V_6 ;
}
V_8 -> V_34 = F_31 ( & V_15 -> V_9 , L_9 ,
V_2 -> V_52 ) ;
if ( V_8 -> V_34 == NULL ) {
V_6 = - V_48 ;
F_6 ( & V_2 -> V_9 , L_10 ) ;
goto V_63;
}
V_8 -> V_34 -> V_64 = & V_65 ;
V_8 -> V_34 -> V_9 . V_53 = & V_15 -> V_9 ;
F_32 ( V_8 -> V_34 , V_2 ) ;
F_33 ( V_8 -> V_34 ) ;
V_6 = F_34 ( & V_15 -> V_9 , V_15 -> V_40 ,
V_66 ,
NULL ,
V_67 ,
V_15 -> V_9 . V_68 -> V_52 , V_8 -> V_34 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_11 ) ;
goto V_69;
}
V_8 -> V_11 = V_70 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_12 ) ;
goto V_69;
}
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_13 ) ;
goto V_69;
}
return 0 ;
V_69:
V_63:
F_36 ( V_2 ) ;
return V_6 ;
}
static int F_37 ( struct V_47 * V_15 )
{
struct V_1 * V_2 = F_38 ( V_15 ) ;
F_20 ( L_14 , V_44 , V_15 ) ;
F_39 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
