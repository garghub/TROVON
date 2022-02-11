static void F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 , T_2 V_4 , int V_5 )
{
T_2 V_6 ;
V_6 = V_2 -> V_7 ( V_3 ) ;
if ( V_5 )
V_6 |= F_2 ( V_4 ) ;
else
V_6 &= ~ F_2 ( V_4 ) ;
V_2 -> V_8 ( V_3 , V_6 ) ;
}
static int F_3 ( struct V_9 * V_10 , unsigned int type )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_4 = F_5 ( V_12 , V_10 -> V_13 ) ;
int V_14 = V_15 ;
switch ( type & V_16 ) {
case V_17 :
case V_18 :
V_14 = V_15 ;
break;
case V_19 :
case V_20 :
V_14 = V_21 ;
break;
default:
break;
}
F_1 ( & V_12 -> V_2 , V_12 -> V_22 + V_23 ,
V_4 * 2 , 1 ) ;
F_1 ( & V_12 -> V_2 , V_12 -> V_22 + V_24 ,
V_10 -> V_13 , V_14 ) ;
if ( type & V_25 )
return F_6 ( V_10 , V_17 ) ;
else
return F_6 ( V_10 , V_18 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_4 )
{
struct V_11 * V_12 = F_8 ( V_2 ) ;
struct V_26 V_27 ;
if ( ( V_4 < V_12 -> V_28 ) ||
( V_4 > F_5 ( V_12 , V_12 -> V_29 ) ) )
return - V_30 ;
if ( V_2 -> V_31 -> V_32 )
V_27 . V_33 = F_9 ( V_2 -> V_31 -> V_32 ) ;
else
V_27 . V_33 = V_2 -> V_31 -> V_33 ;
V_27 . V_34 = 2 ;
V_27 . V_35 [ 0 ] = F_10 ( V_12 , V_4 ) ;
V_27 . V_35 [ 1 ] = V_36 ;
return F_11 ( & V_27 ) ;
}
static void F_12 ( struct V_37 * V_10 ,
struct V_9 * V_9 )
{
struct V_11 * V_12 = V_10 -> V_38 ;
T_2 V_4 = F_5 ( V_12 , V_9 -> V_13 ) ;
if ( F_13 ( & V_12 -> V_2 , V_4 ) ) {
F_14 ( V_12 -> V_2 . V_31 ,
L_1 ,
V_4 ) ;
return;
}
F_1 ( & V_12 -> V_2 , V_12 -> V_22 + V_23 ,
V_4 * 2 , 1 ) ;
}
static void F_15 ( struct V_37 * V_10 ,
struct V_9 * V_9 )
{
struct V_11 * V_12 = V_10 -> V_38 ;
T_2 V_4 = F_5 ( V_12 , V_9 -> V_13 ) ;
F_16 ( & V_12 -> V_2 , V_4 ) ;
F_1 ( & V_12 -> V_2 , V_12 -> V_22 + V_23 ,
V_4 * 2 , 0 ) ;
}
static int F_17 ( struct V_37 * V_10 ,
struct V_26 * V_27 ,
unsigned long * V_13 ,
unsigned int * type )
{
struct V_11 * V_12 = V_10 -> V_38 ;
if ( ( V_27 -> V_34 != 2 ) ||
( V_27 -> V_35 [ 0 ] >= V_12 -> V_29 ) )
return - V_39 ;
* V_13 = V_27 -> V_35 [ 0 ] ;
* type = V_27 -> V_35 [ 1 ] ;
return 0 ;
}
static int F_18 ( struct V_37 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 , void * V_6 )
{
struct V_26 * V_27 = V_6 ;
struct V_26 V_43 ;
struct V_11 * V_12 = V_40 -> V_38 ;
T_3 V_13 ;
unsigned int V_44 ;
V_13 = V_27 -> V_35 [ 0 ] ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ )
F_19 ( V_40 , V_41 + V_44 , V_13 + V_44 ,
& V_45 , V_12 ) ;
V_43 . V_33 = V_40 -> V_31 -> V_33 ;
if ( F_20 ( V_43 . V_33 ) ) {
V_43 . V_34 = 3 ;
V_43 . V_35 [ 0 ] = 0 ;
V_43 . V_35 [ 1 ] = V_13 + V_12 -> V_46 - 32 ;
V_43 . V_35 [ 2 ] = V_27 -> V_35 [ 1 ] ;
} else if ( F_21 ( V_43 . V_33 ) ) {
V_43 . V_34 = 2 ;
V_43 . V_35 [ 0 ] = V_13 + V_12 -> V_46 ;
V_43 . V_35 [ 1 ] = V_27 -> V_35 [ 1 ] ;
} else
return - V_39 ;
return F_22 ( V_40 , V_41 , V_42 ,
& V_43 ) ;
}
static void F_23 ( struct V_37 * V_40 ,
unsigned int V_41 ,
unsigned int V_42 )
{
struct V_9 * V_10 ;
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_10 = F_24 ( V_40 , V_41 + V_44 ) ;
F_25 ( V_10 ) ;
}
}
static int F_26 ( struct V_47 * V_48 )
{
struct V_11 * V_12 ;
int V_49 ;
struct V_50 * V_51 ;
void T_1 * V_22 ;
struct V_37 * V_52 = NULL ;
struct V_53 * V_33 ;
T_2 V_54 ;
V_12 = F_27 ( & V_48 -> V_55 , sizeof( * V_12 ) , V_56 ) ;
if ( ! V_12 )
return - V_57 ;
V_51 = F_28 ( V_48 , V_58 , 0 ) ;
V_22 = F_29 ( & V_48 -> V_55 , V_51 ) ;
if ( F_30 ( V_22 ) )
return F_31 ( V_22 ) ;
V_12 -> V_22 = V_22 ;
V_49 = F_32 ( V_48 , 0 ) ;
if ( V_49 > 0 ) {
V_12 -> V_46 = F_33 ( V_49 ) -> V_13 ;
V_52 = F_33 ( V_49 ) -> V_40 ;
}
if ( ! V_52 ) {
F_14 ( & V_48 -> V_55 , L_2 ) ;
return - V_59 ;
}
V_49 = F_34 ( & V_12 -> V_2 , & V_48 -> V_55 , 4 ,
V_22 + V_60 ,
V_22 + V_61 , NULL ,
V_22 + V_62 , NULL , 0 ) ;
if ( V_49 )
return V_49 ;
V_12 -> V_2 . V_63 = F_7 ;
V_12 -> V_28 = V_64 ;
if ( ! F_35 ( & V_48 -> V_55 ,
V_65 , & V_54 ) )
V_12 -> V_28 = V_54 ;
V_12 -> V_29 = V_66 ;
if ( ! F_35 ( & V_48 -> V_55 , V_67 , & V_54 ) )
V_12 -> V_29 = V_54 ;
V_12 -> V_2 . V_68 = V_69 ;
if ( ! F_35 ( & V_48 -> V_55 , V_70 , & V_54 ) )
V_12 -> V_2 . V_68 = V_54 ;
F_36 ( & V_48 -> V_55 , L_3 ,
V_12 -> V_2 . V_68 , V_12 -> V_29 , V_12 -> V_28 ) ;
F_37 ( V_48 , V_12 ) ;
if ( V_48 -> V_55 . V_32 )
V_33 = F_9 ( V_48 -> V_55 . V_32 ) ;
else
V_33 = V_48 -> V_55 . V_33 ;
V_12 -> V_37 = F_38 ( V_52 ,
0 , V_12 -> V_29 , V_33 ,
& V_71 , V_12 ) ;
if ( ! V_12 -> V_37 )
return - V_59 ;
V_12 -> V_2 . V_72 = V_12 -> V_37 ;
V_49 = F_39 ( & V_48 -> V_55 , & V_12 -> V_2 , V_12 ) ;
if ( V_49 ) {
F_14 ( & V_48 -> V_55 ,
L_4 ) ;
F_40 ( V_12 -> V_37 ) ;
return V_49 ;
}
F_36 ( & V_48 -> V_55 , L_5 ) ;
if ( V_12 -> V_29 > 0 ) {
F_41 ( & V_12 -> V_2 ) ;
}
return V_49 ;
}
static int F_42 ( struct V_47 * V_48 )
{
struct V_11 * V_12 = F_43 ( V_48 ) ;
if ( V_12 -> V_29 > 0 ) {
F_44 ( & V_12 -> V_2 ) ;
}
F_40 ( V_12 -> V_37 ) ;
return 0 ;
}
