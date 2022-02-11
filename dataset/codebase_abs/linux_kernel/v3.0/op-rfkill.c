void F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
enum V_7 V_8 ;
F_3 ( 3 , V_6 , L_1 , V_1 , V_3 ) ;
F_4 ( V_3 == V_9 ) ;
F_4 ( V_3 != V_10 && V_3 != V_11 ) ;
F_5 ( & V_1 -> V_12 ) ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 )
goto V_13;
if ( V_3 != V_1 -> V_14 ) {
V_1 -> V_14 = V_3 ;
if ( V_1 -> V_14 == V_10 &&
V_1 -> V_15 == V_10 )
V_8 = V_16 ;
else
V_8 = V_17 ;
V_4 = F_7 ( V_1 -> V_18 ,
V_3 == V_11 ) ;
F_8 ( V_1 , V_8 ) ;
}
V_13:
F_9 ( & V_1 -> V_12 ) ;
F_10 ( 3 , V_6 , L_2 ,
V_1 , V_3 , V_4 ) ;
}
void F_11 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
enum V_7 V_8 ;
F_3 ( 3 , V_6 , L_1 , V_1 , V_3 ) ;
F_4 ( V_3 == V_9 ) ;
F_4 ( V_3 != V_10 && V_3 != V_11 ) ;
F_5 ( & V_1 -> V_12 ) ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 )
goto V_13;
if ( V_3 != V_1 -> V_15 ) {
V_1 -> V_15 = V_3 ;
if ( V_1 -> V_14 == V_10 &&
V_1 -> V_15 == V_10 )
V_8 = V_16 ;
else
V_8 = V_17 ;
F_8 ( V_1 , V_8 ) ;
F_12 ( V_1 -> V_18 , V_3 == V_11 ) ;
}
V_13:
F_9 ( & V_1 -> V_12 ) ;
F_10 ( 3 , V_6 , L_2 ,
V_1 , V_3 , V_4 ) ;
}
static
int F_13 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
enum V_7 V_8 ;
F_14 () ;
F_3 ( 3 , V_6 , L_1 , V_1 , V_3 ) ;
if ( V_1 -> V_15 == V_3 )
goto V_19;
if ( V_1 -> V_20 != NULL )
V_4 = V_1 -> V_20 ( V_1 , V_3 ) ;
else if ( V_3 == V_11 )
V_4 = - V_21 ;
else
V_4 = 0 ;
if ( V_4 >= 0 ) {
V_4 = 0 ;
V_1 -> V_15 = V_3 ;
V_8 = V_3 == V_10 ?
V_16 : V_17 ;
F_8 ( V_1 , V_8 ) ;
}
V_19:
F_10 ( 3 , V_6 , L_3 ,
V_1 , V_3 , V_4 ) ;
return V_4 ;
}
static int F_15 ( void * V_22 , bool V_23 )
{
int V_4 ;
struct V_1 * V_1 = V_22 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
enum V_2 V_24 ;
F_3 ( 3 , V_6 , L_4 , V_1 , V_23 ) ;
V_24 = V_10 ;
if ( V_23 )
V_24 = V_11 ;
F_5 ( & V_1 -> V_12 ) ;
if ( V_1 -> V_3 <= V_25 )
V_4 = 0 ;
else
V_4 = F_13 ( V_1 , V_24 ) ;
F_9 ( & V_1 -> V_12 ) ;
F_10 ( 3 , V_6 , L_5 ,
V_1 , V_23 , V_4 ) ;
return V_4 ;
}
int F_16 ( struct V_1 * V_1 , enum V_2 V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
F_3 ( 3 , V_6 , L_1 , V_1 , V_3 ) ;
F_5 ( & V_1 -> V_12 ) ;
V_4 = F_6 ( V_1 ) ;
if ( V_4 < 0 ) {
if ( V_4 == - V_26 && V_3 == V_9 )
V_4 = V_11 << 1 | V_11 ;
goto V_13;
}
switch ( V_3 ) {
case V_10 :
case V_11 :
V_4 = F_13 ( V_1 , V_3 ) ;
if ( V_4 < 0 )
goto error;
F_12 ( V_1 -> V_18 , V_3 == V_11 ) ;
break;
case V_9 :
break;
default:
V_4 = - V_27 ;
goto error;
}
V_4 = V_1 -> V_15 << 1 | V_1 -> V_14 ;
error:
V_13:
F_9 ( & V_1 -> V_12 ) ;
F_10 ( 3 , V_6 , L_3 ,
V_1 , V_3 , V_4 ) ;
return V_4 ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_4 ;
struct V_18 * V_18 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
F_3 ( 3 , V_6 , L_6 , V_1 ) ;
V_4 = - V_28 ;
V_18 = F_18 ( V_1 -> V_29 , V_6 , V_30 ,
& V_31 , V_1 ) ;
if ( V_18 == NULL )
goto V_32;
F_19 ( 1 , V_6 , L_7 , V_18 ) ;
V_1 -> V_18 = V_18 ;
F_20 ( V_18 , 1 ) ;
V_4 = F_21 ( V_1 -> V_18 ) ;
if ( V_4 < 0 )
goto V_33;
if ( V_1 -> V_20 == NULL )
V_1 -> V_15 = V_10 ;
F_10 ( 3 , V_6 , L_8 , V_1 ) ;
return 0 ;
V_33:
F_22 ( V_1 -> V_18 ) ;
V_32:
F_10 ( 3 , V_6 , L_9 , V_1 , V_4 ) ;
return V_4 ;
}
void F_23 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
F_3 ( 3 , V_6 , L_6 , V_1 ) ;
F_24 ( V_1 -> V_18 ) ;
F_22 ( V_1 -> V_18 ) ;
F_10 ( 3 , V_6 , L_6 , V_1 ) ;
}
static
int F_25 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
int V_4 , V_38 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
enum V_2 V_39 ;
F_3 ( 3 , NULL , L_10 , V_35 , V_37 ) ;
V_4 = - V_40 ;
if ( V_37 -> V_41 [ V_42 ] == NULL ) {
F_26 ( V_43 L_11
L_12 ) ;
goto V_44;
}
V_38 = F_27 ( V_37 -> V_41 [ V_42 ] ) ;
V_1 = F_28 ( V_37 , V_38 ) ;
if ( V_1 == NULL )
goto V_44;
V_6 = F_2 ( V_1 ) ;
V_4 = - V_27 ;
if ( V_37 -> V_41 [ V_45 ] == NULL ) {
F_29 ( V_6 , L_13
L_12 ) ;
goto V_46;
}
V_39 = F_27 ( V_37 -> V_41 [ V_45 ] ) ;
V_4 = F_16 ( V_1 , V_39 ) ;
V_46:
F_30 ( V_1 -> V_47 ) ;
V_44:
F_10 ( 3 , NULL , L_14 , V_35 , V_37 , V_4 ) ;
return V_4 ;
}
