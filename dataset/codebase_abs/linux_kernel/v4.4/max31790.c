static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
int V_8 ;
int V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_11 , V_4 -> V_12 + V_13 ) || ! V_4 -> V_14 ) {
V_9 = F_5 ( V_6 ,
V_15 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_16 = V_9 & 0x3F ;
V_9 = F_5 ( V_6 ,
V_17 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_16 |= ( V_9 & 0x3F ) << 6 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
V_9 = F_6 ( V_6 ,
F_7 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ V_8 ] = V_9 ;
if ( V_4 -> V_20 [ V_8 ]
& V_21 ) {
V_9 = F_6 ( V_6 ,
F_7 ( V_18
+ V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ V_18 + V_8 ] = V_9 ;
} else {
V_9 = F_6 ( V_6 ,
F_8 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_22 [ V_8 ] = V_9 ;
V_9 = F_6 ( V_6 ,
F_9 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_23 [ V_8 ] = V_9 ;
}
}
V_4 -> V_12 = V_11 ;
V_4 -> V_14 = true ;
}
goto V_24;
abort:
V_4 -> V_14 = false ;
V_7 = F_10 ( V_9 ) ;
V_24:
F_11 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static T_1 F_12 ( T_1 V_25 )
{
return V_26 [ F_13 ( V_25 ) ] ;
}
static T_1 F_14 ( int V_27 )
{
T_1 V_28 ;
if ( V_27 < 500 )
V_28 = 0x0 ;
else if ( V_27 < 1000 )
V_28 = 0x1 ;
else if ( V_27 < 2000 )
V_28 = 0x2 ;
else if ( V_27 < 4000 )
V_28 = 0x3 ;
else if ( V_27 < 8000 )
V_28 = 0x4 ;
else
V_28 = 0x5 ;
return V_28 ;
}
static T_2 F_15 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_34 , V_27 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_34 = F_12 ( V_4 -> V_25 [ V_33 -> V_35 ] ) ;
V_27 = F_19 ( V_4 -> V_19 [ V_33 -> V_35 ] , V_34 ) ;
return sprintf ( V_31 , L_1 , V_27 ) ;
}
static T_2 F_20 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_34 , V_27 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_34 = F_12 ( V_4 -> V_25 [ V_33 -> V_35 ] ) ;
V_27 = F_19 ( V_4 -> V_23 [ V_33 -> V_35 ] , V_34 ) ;
return sprintf ( V_31 , L_1 , V_27 ) ;
}
static T_2 F_21 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_36 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_28 ;
int V_34 ;
int V_23 ;
unsigned long V_27 ;
int V_37 ;
V_37 = F_22 ( V_31 , 10 , & V_27 ) ;
if ( V_37 )
return V_37 ;
F_3 ( & V_4 -> V_10 ) ;
V_27 = F_23 ( V_27 , V_38 , V_39 ) ;
V_28 = F_14 ( V_27 ) ;
V_4 -> V_25 [ V_33 -> V_35 ] =
( ( V_4 -> V_25 [ V_33 -> V_35 ]
& ~ V_40 )
| ( V_28 << V_41 ) ) ;
V_37 = F_24 ( V_6 ,
F_25 ( V_33 -> V_35 ) ,
V_4 -> V_25 [ V_33 -> V_35 ] ) ;
if ( V_37 < 0 ) {
F_11 ( & V_4 -> V_10 ) ;
return V_37 ;
}
V_34 = F_12 ( V_4 -> V_25 [ V_33 -> V_35 ] ) ;
V_23 = F_26 ( V_27 , V_34 ) ;
V_23 = F_23 ( V_23 , 0x1 , 0x7FF ) ;
V_4 -> V_23 [ V_33 -> V_35 ] = V_23 << 5 ;
V_37 = F_27 ( V_6 ,
F_9 ( V_33 -> V_35 ) ,
V_4 -> V_23 [ V_33 -> V_35 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
if ( V_37 < 0 )
return V_37 ;
return V_36 ;
}
static T_2 F_28 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_22 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_22 = V_4 -> V_22 [ V_33 -> V_35 ] >> 8 ;
return sprintf ( V_31 , L_1 , V_22 ) ;
}
static T_2 F_29 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_36 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_22 ;
int V_37 ;
V_37 = F_22 ( V_31 , 10 , & V_22 ) ;
if ( V_37 )
return V_37 ;
if ( V_22 > 255 )
return - V_42 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_22 [ V_33 -> V_35 ] = V_22 << 8 ;
V_37 = F_27 ( V_6 ,
F_8 ( V_33 -> V_35 ) ,
V_4 -> V_22 [ V_33 -> V_35 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
if ( V_37 < 0 )
return V_37 ;
return V_36 ;
}
static T_2 F_30 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_43 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
if ( V_4 -> V_20 [ V_33 -> V_35 ] & V_44 )
V_43 = 2 ;
else if ( V_4 -> V_20 [ V_33 -> V_35 ] & V_45 )
V_43 = 1 ;
else
V_43 = 0 ;
return sprintf ( V_31 , L_1 , V_43 ) ;
}
static T_2 F_31 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_36 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_43 ;
int V_37 ;
V_37 = F_22 ( V_31 , 10 , & V_43 ) ;
if ( V_37 )
return V_37 ;
switch ( V_43 ) {
case 0 :
V_4 -> V_20 [ V_33 -> V_35 ] =
V_4 -> V_20 [ V_33 -> V_35 ]
& ~ ( V_45
| V_44 ) ;
break;
case 1 :
V_4 -> V_20 [ V_33 -> V_35 ] =
( V_4 -> V_20 [ V_33 -> V_35 ]
| V_45 )
& ~ V_44 ;
break;
case 2 :
V_4 -> V_20 [ V_33 -> V_35 ] =
V_4 -> V_20 [ V_33 -> V_35 ]
| V_45
| V_44 ;
break;
default:
return - V_42 ;
}
F_3 ( & V_4 -> V_10 ) ;
V_37 = F_24 ( V_6 ,
F_32 ( V_33 -> V_35 ) ,
V_4 -> V_20 [ V_33 -> V_35 ] ) ;
F_11 ( & V_4 -> V_10 ) ;
if ( V_37 < 0 )
return V_37 ;
return V_36 ;
}
static T_2 F_33 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_32 * V_33 = F_16 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_46 ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_46 = ! ! ( V_4 -> V_16 & ( 1 << V_33 -> V_35 ) ) ;
return sprintf ( V_31 , L_1 , V_46 ) ;
}
static T_4 F_34 ( struct V_47 * V_48 ,
struct V_49 * V_50 , int V_51 )
{
struct V_2 * V_3 = F_35 ( V_48 , struct V_2 , V_48 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_29 * V_30 =
F_35 ( V_50 , struct V_29 , V_33 ) ;
int V_35 = F_16 ( V_30 ) -> V_35 % V_18 ;
T_1 V_20 ;
V_20 = V_4 -> V_20 [ V_35 ] ;
if ( V_51 >= V_18 * 2 && V_51 < V_18 * 4 &&
! ( V_20 & V_21 ) )
return 0 ;
if ( V_51 >= V_18 * 4 && ( V_20 & V_21 ) )
return 0 ;
return V_50 -> V_43 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
V_9 = F_5 ( V_6 ,
F_32 ( V_8 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_20 [ V_8 ] = V_9 ;
V_9 = F_5 ( V_6 ,
F_25 ( V_8 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_25 [ V_8 ] = V_9 ;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
const struct V_52 * V_53 )
{
struct V_54 * V_55 = V_6 -> V_55 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_56 ;
int V_37 ;
if ( ! F_38 ( V_55 ,
V_57 | V_58 ) )
return - V_59 ;
V_4 = F_39 ( V_3 , sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_6 = V_6 ;
F_40 ( & V_4 -> V_10 ) ;
V_37 = F_36 ( V_6 , V_4 ) ;
if ( V_37 )
return V_37 ;
V_56 = F_41 ( V_3 ,
V_6 -> V_62 , V_4 , V_63 ) ;
return F_42 ( V_56 ) ;
}
