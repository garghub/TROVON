static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_4 )
{
if ( V_3 < 0 || V_3 >= V_2 -> V_5 ||
! V_2 -> V_6 [ V_3 ] )
return - V_7 ;
if ( V_4 && V_2 -> V_6 [ V_3 ] != V_4 )
return - V_8 ;
return 0 ;
}
static inline int F_2 ( struct V_9 * V_10 ,
struct V_9 * V_11 )
{
return V_10 -> type == V_11 -> type &&
( V_10 -> type != V_12 ||
V_10 -> V_13 . V_14 . V_15 == V_11 -> V_13 . V_14 . V_15 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_9 * V_16 )
{
int V_17 ;
switch ( V_16 -> type ) {
case V_18 :
if ( ! F_4 ( V_12 , V_2 -> V_19 ) )
return - V_7 ;
V_17 = V_16 -> V_13 . V_20 . V_21 / 3 +
V_16 -> V_13 . V_20 . V_22 / 6 ;
V_16 -> type = V_12 ;
V_16 -> V_13 . V_14 . V_15 = V_23 ;
V_16 -> V_13 . V_14 . V_24 = 50 ;
V_16 -> V_13 . V_14 . V_17 = F_5 ( V_17 , 0x7fff ) ;
V_16 -> V_13 . V_14 . V_25 = 0 ;
V_16 -> V_13 . V_14 . V_26 = 0 ;
V_16 -> V_13 . V_14 . V_27 . V_28 = 0 ;
V_16 -> V_13 . V_14 . V_27 . V_29 = 0 ;
V_16 -> V_13 . V_14 . V_27 . V_30 = 0 ;
V_16 -> V_13 . V_14 . V_27 . V_31 = 0 ;
return 0 ;
default:
return 0 ;
}
}
int F_6 ( struct V_32 * V_33 , struct V_9 * V_16 ,
struct V_4 * V_4 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_9 * V_34 ;
int V_35 = 0 ;
int V_36 ;
if ( ! F_4 ( V_37 , V_33 -> V_38 ) )
return - V_39 ;
if ( V_16 -> type < V_40 || V_16 -> type > V_41 ||
! F_4 ( V_16 -> type , V_33 -> V_19 ) ) {
F_7 ( & V_33 -> V_33 , L_1 ) ;
return - V_7 ;
}
if ( V_16 -> type == V_12 &&
( V_16 -> V_13 . V_14 . V_15 < V_42 ||
V_16 -> V_13 . V_14 . V_15 > V_43 ||
! F_4 ( V_16 -> V_13 . V_14 . V_15 , V_33 -> V_19 ) ) ) {
F_7 ( & V_33 -> V_33 , L_2 ) ;
return - V_7 ;
}
if ( ! F_4 ( V_16 -> type , V_2 -> V_19 ) ) {
V_35 = F_3 ( V_2 , V_16 ) ;
if ( V_35 )
return V_35 ;
}
F_8 ( & V_2 -> V_44 ) ;
if ( V_16 -> V_36 == - 1 ) {
for ( V_36 = 0 ; V_36 < V_2 -> V_5 ; V_36 ++ )
if ( ! V_2 -> V_6 [ V_36 ] )
break;
if ( V_36 >= V_2 -> V_5 ) {
V_35 = - V_45 ;
goto V_46;
}
V_16 -> V_36 = V_36 ;
V_34 = NULL ;
} else {
V_36 = V_16 -> V_36 ;
V_35 = F_1 ( V_2 , V_36 , V_4 ) ;
if ( V_35 )
goto V_46;
V_34 = & V_2 -> V_47 [ V_36 ] ;
if ( ! F_2 ( V_16 , V_34 ) ) {
V_35 = - V_7 ;
goto V_46;
}
}
V_35 = V_2 -> V_48 ( V_33 , V_16 , V_34 ) ;
if ( V_35 )
goto V_46;
F_9 ( & V_33 -> V_49 ) ;
V_2 -> V_47 [ V_36 ] = * V_16 ;
V_2 -> V_6 [ V_36 ] = V_4 ;
F_10 ( & V_33 -> V_49 ) ;
V_46:
F_11 ( & V_2 -> V_44 ) ;
return V_35 ;
}
static int F_12 ( struct V_32 * V_33 , int V_3 ,
struct V_4 * V_4 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
int error ;
error = F_1 ( V_2 , V_3 , V_4 ) ;
if ( error )
return error ;
F_9 ( & V_33 -> V_49 ) ;
V_2 -> V_50 ( V_33 , V_3 , 0 ) ;
V_2 -> V_6 [ V_3 ] = NULL ;
F_10 ( & V_33 -> V_49 ) ;
if ( V_2 -> V_51 ) {
error = V_2 -> V_51 ( V_33 , V_3 ) ;
if ( error ) {
F_9 ( & V_33 -> V_49 ) ;
V_2 -> V_6 [ V_3 ] = V_4 ;
F_10 ( & V_33 -> V_49 ) ;
return error ;
}
}
return 0 ;
}
int F_13 ( struct V_32 * V_33 , int V_3 , struct V_4 * V_4 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
int V_35 ;
if ( ! F_4 ( V_37 , V_33 -> V_38 ) )
return - V_39 ;
F_8 ( & V_2 -> V_44 ) ;
V_35 = F_12 ( V_33 , V_3 , V_4 ) ;
F_11 ( & V_2 -> V_44 ) ;
return V_35 ;
}
static int F_14 ( struct V_32 * V_33 , struct V_4 * V_4 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
int V_52 ;
F_7 ( & V_33 -> V_33 , L_3 ) ;
F_8 ( & V_2 -> V_44 ) ;
for ( V_52 = 0 ; V_52 < V_2 -> V_5 ; V_52 ++ )
F_12 ( V_33 , V_52 , V_4 ) ;
F_11 ( & V_2 -> V_44 ) ;
return 0 ;
}
int F_15 ( struct V_32 * V_33 , unsigned int type ,
unsigned int V_53 , int V_54 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
if ( type != V_37 )
return 0 ;
switch ( V_53 ) {
case V_55 :
if ( ! F_4 ( V_55 , V_33 -> V_19 ) || V_54 > 0xffffU )
break;
V_2 -> V_56 ( V_33 , V_54 ) ;
break;
case V_57 :
if ( ! F_4 ( V_57 , V_33 -> V_19 ) || V_54 > 0xffffU )
break;
V_2 -> V_58 ( V_33 , V_54 ) ;
break;
default:
if ( F_1 ( V_2 , V_53 , NULL ) == 0 )
V_2 -> V_50 ( V_33 , V_53 , V_54 ) ;
break;
}
return 0 ;
}
int F_16 ( struct V_32 * V_33 , unsigned int V_5 )
{
struct V_1 * V_2 ;
T_1 V_59 ;
int V_52 ;
if ( ! V_5 ) {
F_17 ( & V_33 -> V_33 , L_4 ) ;
return - V_7 ;
}
if ( V_5 > V_60 ) {
F_17 ( & V_33 -> V_33 , L_5 ) ;
return - V_7 ;
}
V_59 = sizeof( struct V_1 ) +
V_5 * sizeof( struct V_4 * ) ;
if ( V_59 < V_5 )
return - V_7 ;
V_2 = F_18 ( V_59 , V_61 ) ;
if ( ! V_2 )
return - V_62 ;
V_2 -> V_47 = F_19 ( V_5 , sizeof( struct V_9 ) ,
V_61 ) ;
if ( ! V_2 -> V_47 ) {
F_20 ( V_2 ) ;
return - V_62 ;
}
V_2 -> V_5 = V_5 ;
F_21 ( & V_2 -> V_44 ) ;
V_33 -> V_2 = V_2 ;
V_33 -> V_63 = F_14 ;
V_33 -> V_64 = F_15 ;
F_22 ( V_37 , V_33 -> V_38 ) ;
F_23 (i, dev->ffbit, FF_CNT)
F_22 ( V_52 , V_2 -> V_19 ) ;
if ( F_4 ( V_12 , V_2 -> V_19 ) )
F_22 ( V_18 , V_33 -> V_19 ) ;
return 0 ;
}
void F_24 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
F_25 ( V_37 , V_33 -> V_38 ) ;
if ( V_2 ) {
if ( V_2 -> V_65 )
V_2 -> V_65 ( V_2 ) ;
F_20 ( V_2 -> V_66 ) ;
F_20 ( V_2 -> V_47 ) ;
F_20 ( V_2 ) ;
V_33 -> V_2 = NULL ;
}
}
