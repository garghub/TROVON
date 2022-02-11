static struct V_1 * F_1 ( void )
{
return F_2 ( V_2 . V_3 ) ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 ;
F_4 ( & V_7 ) ;
F_5 ( V_1 ) ;
V_6 = F_6 ( V_1 , V_8 ) ;
V_6 &= ~ V_9 ;
V_6 |= V_4 ;
V_5 = F_7 ( V_1 , V_8 , V_6 ) ;
F_8 ( V_1 ) ;
F_9 ( & V_7 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_1 )
{
int V_5 ;
T_1 V_6 ;
F_4 ( & V_7 ) ;
F_5 ( V_1 ) ;
V_6 = F_6 ( V_1 , V_8 ) ;
V_6 &= ~ V_10 ;
V_6 |= 0x20 ;
V_5 = F_7 ( V_1 , V_8 , V_6 ) ;
F_8 ( V_1 ) ;
F_9 ( & V_7 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_5 ;
T_1 V_6 ;
F_4 ( & V_7 ) ;
F_5 ( V_1 ) ;
V_6 = F_6 ( V_1 , V_8 ) ;
V_6 &= ~ V_10 ;
V_5 = F_7 ( V_1 , V_8 , V_6 ) ;
F_8 ( V_1 ) ;
F_9 ( & V_7 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_5 ;
T_1 V_6 ;
F_4 ( & V_7 ) ;
V_6 = F_6 ( V_1 , V_8 ) ;
V_5 = F_7 ( V_1 , V_8 , V_6 ) ;
F_9 ( & V_7 ) ;
return V_5 ;
}
static int F_13 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_1 * V_1 = F_1 () ;
int V_5 ;
if ( ! V_1 )
return - V_13 ;
if ( F_14 ( 0 , & V_14 ) )
return - V_15 ;
V_5 = F_10 ( V_1 ) ;
if ( V_5 != 0 )
return V_5 ;
return F_15 ( V_11 , V_12 ) ;
}
static int F_16 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_1 * V_1 = F_1 () ;
if ( V_16 )
F_11 ( V_1 ) ;
else {
F_17 ( V_1 -> V_17 , L_1 ) ;
F_12 ( V_1 ) ;
}
F_18 ( 0 , & V_14 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_12 * V_12 ,
const char T_3 * V_18 , T_4 V_19 ,
T_5 * V_20 )
{
struct V_1 * V_1 = F_1 () ;
T_4 V_21 ;
if ( V_19 ) {
F_12 ( V_1 ) ;
if ( ! V_22 ) {
V_16 = 0 ;
for ( V_21 = 0 ; V_21 != V_19 ; V_21 ++ ) {
char V_23 ;
if ( F_20 ( V_23 , V_18 + V_21 ) )
return - V_24 ;
if ( V_23 == 'V' )
V_16 = 42 ;
}
}
}
return V_19 ;
}
static long F_21 ( struct V_12 * V_12 , unsigned int V_25 ,
unsigned long V_26 )
{
struct V_1 * V_1 = F_1 () ;
int V_5 = - V_27 , time , V_21 ;
void T_3 * V_28 = ( void T_3 * ) V_26 ;
int T_3 * V_29 = V_28 ;
T_1 V_6 ;
switch ( V_25 ) {
case V_30 :
V_5 = F_22 ( V_28 , & V_31 , sizeof( V_31 ) ) ? - V_24 : 0 ;
break;
case V_32 :
case V_33 :
V_5 = F_23 ( 0 , V_29 ) ;
break;
case V_34 :
{
int V_35 ;
if ( F_20 ( V_35 , V_29 ) )
return - V_24 ;
V_5 = - V_36 ;
if ( V_35 == V_37 )
V_5 = F_10 ( V_1 ) ;
if ( V_35 == V_38 )
V_5 = F_11 ( V_1 ) ;
break;
}
case V_39 :
V_5 = F_12 ( V_1 ) ;
break;
case V_40 :
V_5 = F_20 ( time , V_29 ) ;
if ( V_5 )
break;
if ( time == 0 ) {
if ( V_22 )
V_5 = - V_36 ;
else
F_11 ( V_1 ) ;
break;
}
for ( V_21 = 0 ; V_21 < F_24 ( V_41 ) ; V_21 ++ )
if ( V_41 [ V_21 ] . time == time )
break;
if ( V_21 == F_24 ( V_41 ) )
V_5 = - V_36 ;
else
V_5 = F_3 ( V_1 ,
V_41 [ V_21 ] . V_42 ) ;
break;
case V_43 :
V_6 = F_6 ( V_1 , V_8 ) ;
V_6 &= V_9 ;
for ( V_21 = 0 ; V_21 < F_24 ( V_41 ) ; V_21 ++ )
if ( V_41 [ V_21 ] . V_42 == V_6 )
break;
if ( V_21 == F_24 ( V_41 ) ) {
F_17 ( V_1 -> V_17 ,
L_2 , V_6 ) ;
V_5 = - V_36 ;
} else
V_5 = F_23 ( V_41 [ V_21 ] . time , V_29 ) ;
}
return V_5 ;
}
static int T_6 F_25 ( struct V_44 * V_45 )
{
struct V_1 * V_1 = F_26 ( V_45 ) ;
if ( ! V_1 ) {
F_27 ( L_3 ) ;
return - V_13 ;
}
F_3 ( V_1 , 0x05 ) ;
V_2 . V_3 = & V_45 -> V_17 ;
return F_28 ( & V_2 ) ;
}
static int T_7 F_29 ( struct V_44 * V_45 )
{
F_30 ( & V_2 ) ;
return 0 ;
}
static int T_8 F_31 ( void )
{
return F_32 ( & V_46 ) ;
}
static void T_9 F_33 ( void )
{
F_34 ( & V_46 ) ;
}
