int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_4 < 0 ) ) {
F_4 ( & V_2 -> V_5 ,
L_1 , V_3 ) ;
return V_4 ;
}
return F_5 ( V_4 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_3 , int V_6 )
{
F_7 ( V_2 , V_3 , F_8 ( V_6 ) ) ;
}
static struct V_7 * F_9 ( struct V_8 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
struct V_7 * V_6 = F_11 ( V_2 ) ;
struct V_7 * V_9 = V_6 ;
F_12 ( & V_6 -> V_10 ) ;
if ( F_13 ( V_11 , V_6 -> V_12 +
V_13 / V_14 ) || ! V_6 -> V_15 ) {
int V_16 ;
F_4 ( & V_2 -> V_5 , L_2 ) ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
int V_18 = F_1 ( V_2 , V_16 ) ;
if ( V_18 < 0 ) {
V_9 = F_14 ( V_18 ) ;
goto abort;
}
V_6 -> V_19 [ V_16 ] = V_18 ;
}
V_6 -> V_12 = V_11 ;
V_6 -> V_15 = 1 ;
}
abort:
F_15 ( & V_6 -> V_10 ) ;
return V_9 ;
}
static int F_16 ( struct V_7 * V_6 , T_1 V_3 )
{
int V_4 = V_6 -> V_19 [ V_3 ] ;
switch ( V_3 ) {
case V_20 :
V_4 = F_17 ( V_4 , 100 ) ;
break;
case V_21 :
V_4 = ( V_4 >> 3 ) * 4 ;
break;
case V_22 :
V_4 = V_4 * 20 * 1000 ;
break;
case V_23 :
break;
default:
F_18 ( 1 ) ;
V_4 = 0 ;
break;
}
return V_4 ;
}
static int F_19 ( struct V_7 * V_6 , T_1 V_3 )
{
int V_4 = V_6 -> V_19 [ V_3 ] ;
switch ( V_3 ) {
case V_20 :
V_4 = F_17 ( V_4 , 400 ) ;
break;
case V_21 :
V_4 = V_4 + F_17 ( V_4 , 4 ) ;
break;
case V_22 :
V_4 = V_4 * 25 * 1000 ;
break;
case V_23 :
break;
default:
F_18 ( 1 ) ;
V_4 = 0 ;
break;
}
return V_4 ;
}
static T_2 F_20 ( struct V_8 * V_5 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_21 ( V_25 ) ;
struct V_7 * V_6 = F_9 ( V_5 ) ;
int V_29 = 0 ;
if ( F_22 ( V_6 ) )
return F_23 ( V_6 ) ;
switch ( V_6 -> V_30 ) {
case V_31 :
V_29 = F_16 ( V_6 , V_28 -> V_32 ) ;
break;
case V_33 :
V_29 = F_19 ( V_6 , V_28 -> V_32 ) ;
break;
default:
F_18 ( 1 ) ;
break;
}
return snprintf ( V_26 , V_34 , L_3 , V_29 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_7 * V_6 ;
struct V_39 * V_40 ;
int V_9 = 0 ;
long V_41 = 10000 ;
if ( ! F_25 ( V_38 , V_42 ) )
return - V_43 ;
V_6 = F_26 ( & V_2 -> V_5 , sizeof( * V_6 ) , V_44 ) ;
if ( ! V_6 )
return - V_45 ;
if ( V_2 -> V_5 . V_46 ) {
V_40 =
(struct V_39 * ) V_2 -> V_5 . V_46 ;
V_41 = V_40 -> V_47 ;
}
if ( V_41 <= 0 )
return - V_43 ;
V_6 -> V_30 = V_36 -> V_48 ;
switch ( V_6 -> V_30 ) {
case V_31 :
F_6 ( V_2 , V_49 , V_50 ) ;
F_6 ( V_2 , V_51 , 40960000 / V_41 ) ;
F_27 ( & V_2 -> V_5 ,
L_4 , V_41 ) ;
V_6 -> V_17 = V_52 ;
break;
case V_33 :
F_6 ( V_2 , V_49 , V_53 ) ;
F_6 ( V_2 , V_51 , 5120000 / V_41 ) ;
F_27 ( & V_2 -> V_5 ,
L_5 , V_41 ) ;
V_6 -> V_17 = V_54 ;
break;
default:
return - V_43 ;
}
F_28 ( V_2 , V_6 ) ;
F_29 ( & V_6 -> V_10 ) ;
V_9 = F_30 ( & V_2 -> V_5 . V_55 , & V_56 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_57 = F_31 ( & V_2 -> V_5 ) ;
if ( F_22 ( V_6 -> V_57 ) ) {
V_9 = F_23 ( V_6 -> V_57 ) ;
goto V_58;
}
return 0 ;
V_58:
F_32 ( & V_2 -> V_5 . V_55 , & V_56 ) ;
return V_9 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_7 * V_6 = F_11 ( V_2 ) ;
F_34 ( V_6 -> V_57 ) ;
F_32 ( & V_2 -> V_5 . V_55 , & V_56 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_59 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_59 ) ;
}
