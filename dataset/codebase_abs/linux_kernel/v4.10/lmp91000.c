static int F_1 ( struct V_1 * V_2 , int V_3 , int * V_4 )
{
int V_5 , V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 , & V_5 ) ;
if ( V_6 )
return - V_9 ;
V_6 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_6 )
return - V_9 ;
if ( ( V_5 != V_3 ) && ( V_3 == V_10 ) )
F_4 ( 3000 , 4000 ) ;
V_2 -> V_11 = V_3 != V_12 ;
F_5 ( V_2 -> V_13 ) ;
V_6 = F_6 ( & V_2 -> V_14 , V_15 ) ;
F_7 ( & V_2 -> V_14 ) ;
if ( ! V_6 )
return - V_16 ;
* V_4 = V_2 -> V_17 [ V_2 -> V_11 ] ;
return 0 ;
}
static T_1 F_8 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_1 * V_2 = F_9 ( V_23 ) ;
int V_6 , V_4 ;
memset ( V_2 -> V_17 , 0 , sizeof( V_2 -> V_17 ) ) ;
V_6 = F_1 ( V_2 , V_12 , & V_4 ) ;
if ( ! V_6 ) {
V_2 -> V_17 [ 0 ] = V_4 ;
F_10 ( V_23 , V_2 -> V_17 ,
F_11 ( V_23 ) ) ;
}
F_12 ( V_23 -> V_13 ) ;
return V_24 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_25 const * V_26 ,
int * V_4 , int * V_27 , long V_28 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
switch ( V_28 ) {
case V_29 :
case V_30 : {
int V_6 = F_14 ( V_2 -> V_31 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_26 -> V_32 , V_4 ) ;
F_15 ( V_2 -> V_31 ) ;
if ( V_6 )
return V_6 ;
if ( V_28 == V_30 ) {
int V_33 , V_34 ;
V_6 = F_16 ( V_2 -> V_35 ,
* V_4 , & V_33 , 1 ) ;
if ( V_6 )
return V_6 ;
for ( V_34 = 0 ; V_34 < F_17 ( V_36 ) ; V_34 ++ )
if ( V_36 [ V_34 ] < V_33 )
break;
* V_4 = ( V_37 + V_34 ) * 1000 ;
}
return V_38 ;
}
case V_39 :
return F_18 ( V_2 -> V_35 , V_4 , V_27 ) ;
case V_40 :
return F_19 ( V_2 -> V_35 , V_4 , V_27 ) ;
}
return - V_9 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_43 * V_44 = V_42 -> V_45 ;
unsigned int V_46 , V_4 ;
int V_34 , V_6 ;
V_6 = F_21 ( V_44 , L_1 , & V_4 ) ;
if ( V_6 ) {
if ( F_22 ( V_44 , L_2 ) )
V_4 = 0 ;
else {
F_23 ( V_42 , L_3 ) ;
return V_6 ;
}
}
V_6 = - V_9 ;
for ( V_34 = 0 ; V_34 < F_17 ( V_47 ) ; V_34 ++ ) {
if ( V_47 [ V_34 ] == V_4 ) {
V_46 = V_34 << V_48 ;
V_6 = 0 ;
break;
}
}
if ( V_6 ) {
F_23 ( V_42 , L_4 , V_4 ) ;
return V_6 ;
}
V_6 = F_21 ( V_44 , L_5 , & V_4 ) ;
if ( V_6 ) {
V_4 = 100 ;
F_24 ( V_42 , L_6 , V_4 ) ;
}
V_6 = - V_9 ;
for ( V_34 = 0 ; V_34 < F_17 ( V_49 ) ; V_34 ++ ) {
if ( V_49 [ V_34 ] == V_4 ) {
V_46 |= V_34 ;
V_6 = 0 ;
break;
}
}
if ( V_6 ) {
F_23 ( V_42 , L_7 , V_4 ) ;
return V_6 ;
}
F_3 ( V_2 -> V_7 , V_50 , 0 ) ;
F_3 ( V_2 -> V_7 , V_51 , V_46 ) ;
F_3 ( V_2 -> V_7 , V_52 , V_53
| V_54 ) ;
F_3 ( V_2 -> V_7 , V_50 , 1 ) ;
return 0 ;
}
static int F_25 ( const void * V_4 , void * V_19 )
{
struct V_22 * V_23 = V_19 ;
struct V_1 * V_2 = F_9 ( V_23 ) ;
V_2 -> V_17 [ V_2 -> V_11 ] = * ( ( int * ) V_4 ) ;
F_26 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
return F_14 ( V_2 -> V_31 ) ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_15 ( V_2 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_41 * V_42 = & V_56 -> V_42 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_6 ;
V_23 = F_30 ( V_42 , sizeof( * V_2 ) ) ;
if ( ! V_23 )
return - V_59 ;
V_23 -> V_60 = & V_61 ;
V_23 -> V_62 = V_63 ;
V_23 -> V_64 = F_17 ( V_63 ) ;
V_23 -> V_65 = V_66 ;
V_23 -> V_67 = V_68 ;
F_31 ( V_56 , V_23 ) ;
V_2 = F_9 ( V_23 ) ;
V_2 -> V_42 = V_42 ;
V_2 -> V_7 = F_32 ( V_56 , & V_69 ) ;
if ( F_33 ( V_2 -> V_7 ) ) {
F_23 ( V_42 , L_8 ) ;
return F_34 ( V_2 -> V_7 ) ;
}
V_2 -> V_13 = F_35 ( V_2 -> V_42 , L_9 ,
V_23 -> V_65 , V_23 -> V_58 ) ;
if ( ! V_2 -> V_13 ) {
F_23 ( V_42 , L_10 ) ;
return - V_59 ;
}
V_2 -> V_13 -> V_70 = & V_71 ;
V_2 -> V_13 -> V_42 . V_72 = V_42 ;
F_36 ( & V_2 -> V_14 ) ;
V_6 = F_20 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_37 ( F_38 ( V_2 -> V_31 ) ,
V_2 -> V_13 ) ;
if ( V_6 ) {
F_23 ( V_42 , L_11 ) ;
return V_6 ;
}
V_6 = F_39 ( V_2 -> V_13 ) ;
if ( V_6 ) {
F_23 ( V_42 , L_12 ) ;
return V_6 ;
}
V_6 = F_40 ( V_23 , NULL ,
& F_8 ,
& V_73 ) ;
if ( V_6 )
goto V_74;
V_2 -> V_31 = F_41 ( V_42 , & F_25 ,
V_23 ) ;
if ( F_33 ( V_2 -> V_31 ) ) {
if ( F_34 ( V_2 -> V_31 ) == - V_75 )
V_6 = - V_76 ;
else
V_6 = F_34 ( V_2 -> V_31 ) ;
goto V_77;
}
V_2 -> V_35 = F_42 ( V_2 -> V_31 ) ;
V_6 = F_43 ( V_23 ) ;
if ( V_6 )
goto V_78;
return 0 ;
V_78:
F_44 ( V_2 -> V_31 ) ;
V_77:
F_45 ( V_23 ) ;
V_74:
F_46 ( V_2 -> V_13 ) ;
return V_6 ;
}
static int F_47 ( struct V_55 * V_56 )
{
struct V_22 * V_23 = F_48 ( V_56 ) ;
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_49 ( V_23 ) ;
F_15 ( V_2 -> V_31 ) ;
F_44 ( V_2 -> V_31 ) ;
F_45 ( V_23 ) ;
F_46 ( V_2 -> V_13 ) ;
return 0 ;
}
