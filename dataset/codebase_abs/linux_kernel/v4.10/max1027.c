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
V_18 ;
if ( V_4 -> type == V_19 )
V_8 -> V_11 |= V_20 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 ,
L_3 ) ;
return V_6 ;
}
F_8 ( 1 ) ;
V_6 = F_9 ( V_8 -> V_15 , V_8 -> V_21 , ( V_4 -> type == V_19 ) ? 4 : 2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_5 = F_10 ( V_8 -> V_21 [ 0 ] ) ;
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_23 , long V_24 )
{
int V_6 = 0 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_12 ( & V_8 -> V_25 ) ;
switch ( V_24 ) {
case V_26 :
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
break;
case V_27 :
switch ( V_4 -> type ) {
case V_19 :
* V_5 = 1 ;
* V_23 = 8 ;
V_6 = V_28 ;
break;
case V_29 :
* V_5 = 2500 ;
* V_23 = 10 ;
V_6 = V_30 ;
break;
default:
V_6 = - V_31 ;
break;
}
break;
default:
V_6 = - V_31 ;
break;
}
F_13 ( & V_8 -> V_25 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned V_11 , unsigned V_32 ,
unsigned * V_33 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 * V_5 = ( T_1 * ) V_8 -> V_21 ;
if ( V_33 != NULL )
return - V_31 ;
* V_5 = ( T_1 ) V_32 ;
return F_5 ( V_8 -> V_15 , V_5 , 1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_35 != V_35 )
return - V_31 ;
return 0 ;
}
static int F_16 ( struct V_34 * V_35 , bool V_36 )
{
struct V_1 * V_2 = F_17 ( V_35 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_36 ) {
V_8 -> V_11 = V_12 | V_37 |
V_13 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_8 -> V_11 = V_16 | F_7 ( 0 ) |
V_38 | V_20 ;
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
static T_2 F_18 ( int V_39 , void * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_19 ( L_4 , V_43 , V_39 , V_40 ) ;
F_9 ( V_8 -> V_15 , V_8 -> V_21 , V_2 -> V_44 * 2 ) ;
F_20 ( V_2 , V_8 -> V_21 ) ;
F_21 ( V_2 -> V_35 ) ;
return V_45 ;
}
static int F_22 ( struct V_46 * V_15 )
{
int V_6 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
F_19 ( L_5 , V_43 , V_15 ) ;
V_2 = F_23 ( & V_15 -> V_9 , sizeof( * V_8 ) ) ;
if ( V_2 == NULL ) {
F_24 ( L_6 ) ;
return - V_47 ;
}
F_25 ( V_15 , V_2 ) ;
V_8 = F_2 ( V_2 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_48 = & V_49 [ F_26 ( V_15 ) -> V_50 ] ;
F_27 ( & V_8 -> V_25 ) ;
V_2 -> V_51 = F_26 ( V_15 ) -> V_51 ;
V_2 -> V_9 . V_52 = & V_15 -> V_9 ;
V_2 -> V_9 . V_53 = V_15 -> V_9 . V_53 ;
V_2 -> V_48 = & V_54 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = V_8 -> V_48 -> V_57 ;
V_2 -> V_58 = V_8 -> V_48 -> V_58 ;
V_2 -> V_59 = V_8 -> V_48 -> V_59 ;
V_8 -> V_21 = F_28 ( & V_2 -> V_9 ,
V_2 -> V_58 * 2 ,
V_60 ) ;
if ( V_8 -> V_21 == NULL ) {
F_6 ( & V_2 -> V_9 , L_7 ) ;
return - V_47 ;
}
V_6 = F_29 ( V_2 , & V_61 ,
& F_18 , NULL ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_8 ) ;
return V_6 ;
}
V_8 -> V_35 = F_30 ( & V_15 -> V_9 , L_9 ,
V_2 -> V_51 ) ;
if ( V_8 -> V_35 == NULL ) {
V_6 = - V_47 ;
F_6 ( & V_2 -> V_9 , L_10 ) ;
goto V_62;
}
V_8 -> V_35 -> V_63 = & V_64 ;
V_8 -> V_35 -> V_9 . V_52 = & V_15 -> V_9 ;
F_31 ( V_8 -> V_35 , V_2 ) ;
F_32 ( V_8 -> V_35 ) ;
V_6 = F_33 ( & V_15 -> V_9 , V_15 -> V_39 ,
V_65 ,
NULL ,
V_66 ,
V_15 -> V_9 . V_67 -> V_51 , V_8 -> V_35 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_11 ) ;
goto V_68;
}
V_8 -> V_11 = V_69 ;
V_6 = F_5 ( V_8 -> V_15 , & V_8 -> V_11 , 1 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_12 ) ;
goto V_68;
}
V_6 = F_34 ( V_2 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_2 -> V_9 , L_13 ) ;
goto V_68;
}
return 0 ;
V_68:
V_62:
F_35 ( V_2 ) ;
return V_6 ;
}
static int F_36 ( struct V_46 * V_15 )
{
struct V_1 * V_2 = F_37 ( V_15 ) ;
F_19 ( L_14 , V_43 , V_15 ) ;
F_38 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
