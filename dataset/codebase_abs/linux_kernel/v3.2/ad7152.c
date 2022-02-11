static inline T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 ,
T_3 V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 * V_13 = F_4 ( V_4 ) ;
bool V_14 ;
int V_15 , V_16 = 10 ;
V_15 = F_5 ( V_5 , & V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_14 )
return 0 ;
if ( V_13 -> V_17 == 0 )
V_7 |= V_18 ;
else
V_7 |= V_19 ;
F_6 ( & V_9 -> V_20 ) ;
V_15 = F_7 ( V_11 -> V_21 , V_22 , V_7 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_9 -> V_20 ) ;
return V_15 ;
}
do {
F_9 ( 20 ) ;
V_15 = F_10 ( V_11 -> V_21 , V_22 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_9 -> V_20 ) ;
return V_15 ;
}
} while ( ( V_15 == V_7 ) && V_16 -- );
F_8 ( & V_9 -> V_20 ) ;
return V_6 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 ,
V_23 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
return F_1 ( V_2 , V_4 , V_5 , V_6 ,
V_24 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
return sprintf ( V_5 , L_1 ,
V_25 [ V_11 -> V_26 ] [ 0 ] ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
T_3 V_27 ;
int V_15 , V_28 ;
V_15 = F_15 ( V_5 , 10 , & V_27 ) ;
if ( V_15 < 0 )
return V_15 ;
for ( V_28 = 0 ; V_28 < F_16 ( V_25 ) ; V_28 ++ )
if ( V_27 >= V_25 [ V_28 ] [ 0 ] )
break;
if ( V_28 >= F_16 ( V_25 ) )
V_28 = F_16 ( V_25 ) - 1 ;
F_6 ( & V_9 -> V_20 ) ;
V_15 = F_7 ( V_11 -> V_21 ,
V_29 , F_17 ( V_28 ) ) ;
if ( V_15 < 0 ) {
F_8 ( & V_9 -> V_20 ) ;
return V_15 ;
}
V_11 -> V_26 = V_28 ;
F_8 ( & V_9 -> V_20 ) ;
return V_6 ;
}
static int F_18 ( struct V_8 * V_9 ,
struct V_30 const * V_31 ,
int V_32 ,
int V_33 ,
long V_34 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_15 , V_28 ;
F_6 ( & V_9 -> V_20 ) ;
switch ( V_34 ) {
case ( 1 << V_35 ) :
if ( V_32 != 1 ) {
V_15 = - V_36 ;
goto V_37;
}
V_32 = ( V_33 * 1024 ) / 15625 ;
V_15 = F_19 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_40 ] ,
F_20 ( V_32 ) ) ;
if ( V_15 < 0 )
goto V_37;
V_15 = 0 ;
break;
case ( 1 << V_41 ) :
if ( ( V_32 < 0 ) | ( V_32 > 0xFFFF ) ) {
V_15 = - V_36 ;
goto V_37;
}
V_15 = F_19 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_42 ] ,
F_20 ( V_32 ) ) ;
if ( V_15 < 0 )
goto V_37;
V_15 = 0 ;
break;
case ( 1 << V_43 ) :
if ( V_32 != 0 ) {
V_15 = - V_36 ;
goto V_37;
}
for ( V_28 = 0 ; V_28 < F_16 ( V_44 ) ; V_28 ++ )
if ( V_33 == V_44 [ V_28 ] )
break;
V_11 -> V_45 [ V_31 -> V_39 ] &= ~ V_46 ;
V_11 -> V_45 [ V_31 -> V_39 ] |= F_21 ( V_28 ) ;
V_15 = F_7 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_47 ] ,
V_11 -> V_45 [ V_31 -> V_39 ] ) ;
if ( V_15 < 0 )
goto V_37;
V_15 = 0 ;
break;
default:
V_15 = - V_36 ;
}
V_37:
F_8 ( & V_9 -> V_20 ) ;
return V_15 ;
}
static int F_22 ( struct V_8 * V_9 ,
struct V_30 const * V_31 ,
int * V_32 , int * V_33 ,
long V_34 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_15 ;
T_3 V_7 = 0 ;
F_6 ( & V_9 -> V_20 ) ;
switch ( V_34 ) {
case 0 :
V_7 = V_11 -> V_45 [ V_31 -> V_39 ] ;
if ( V_31 -> V_48 )
V_11 -> V_45 [ V_31 -> V_39 ] |= V_49 ;
else
V_11 -> V_45 [ V_31 -> V_39 ] &= ~ V_49 ;
if ( V_7 != V_11 -> V_45 [ V_31 -> V_39 ] ) {
V_15 = F_7 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_47 ] ,
V_11 -> V_45 [ V_31 -> V_39 ] ) ;
if ( V_15 < 0 )
goto V_37;
}
if ( V_31 -> V_39 == 0 )
V_7 = V_18 ;
else
V_7 = V_19 ;
V_7 |= V_50 ;
V_15 = F_7 ( V_11 -> V_21 , V_22 ,
V_7 ) ;
if ( V_15 < 0 )
goto V_37;
F_23 ( V_25 [ V_11 -> V_26 ] [ 1 ] ) ;
V_15 = F_24 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_51 ] ) ;
if ( V_15 < 0 )
goto V_37;
* V_32 = F_20 ( V_15 ) ;
if ( V_31 -> V_48 )
* V_32 -= 0x8000 ;
V_15 = V_52 ;
break;
case ( 1 << V_35 ) :
V_15 = F_24 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_40 ] ) ;
if ( V_15 < 0 )
goto V_37;
* V_32 = 1 ;
* V_33 = ( 15625 * F_20 ( V_15 ) ) / 1024 ;
V_15 = V_53 ;
break;
case ( 1 << V_41 ) :
V_15 = F_24 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_42 ] ) ;
if ( V_15 < 0 )
goto V_37;
* V_32 = F_20 ( V_15 ) ;
V_15 = V_52 ;
break;
case ( 1 << V_43 ) :
V_15 = F_10 ( V_11 -> V_21 ,
V_38 [ V_31 -> V_39 ] [ V_47 ] ) ;
if ( V_15 < 0 )
goto V_37;
* V_32 = 0 ;
* V_33 = V_44 [ V_15 >> 6 ] ;
V_15 = V_54 ;
break;
default:
V_15 = - V_36 ;
} ;
V_37:
F_8 ( & V_9 -> V_20 ) ;
return V_15 ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_30 const * V_31 ,
long V_34 )
{
switch ( V_34 ) {
case ( 1 << V_43 ) :
return V_54 ;
default:
return V_53 ;
}
}
static int T_4 F_26 ( struct V_55 * V_21 ,
const struct V_56 * V_57 )
{
int V_15 = 0 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_27 ( sizeof( * V_11 ) ) ;
if ( V_9 == NULL ) {
V_15 = - V_58 ;
goto V_59;
}
V_11 = F_3 ( V_9 ) ;
F_28 ( V_21 , V_9 ) ;
V_11 -> V_21 = V_21 ;
V_9 -> V_60 = V_57 -> V_60 ;
V_9 -> V_2 . V_61 = & V_21 -> V_2 ;
V_9 -> V_62 = & V_63 ;
V_9 -> V_64 = V_65 ;
if ( V_57 -> V_66 == 0 )
V_9 -> V_67 = F_16 ( V_65 ) ;
else
V_9 -> V_67 = 2 ;
V_9 -> V_67 = F_16 ( V_65 ) ;
V_9 -> V_68 = V_69 ;
V_15 = F_29 ( V_9 ) ;
if ( V_15 )
goto V_70;
F_30 ( & V_21 -> V_2 , L_2 , V_57 -> V_60 ) ;
return 0 ;
V_70:
F_31 ( V_9 ) ;
V_59:
return V_15 ;
}
static int T_5 F_32 ( struct V_55 * V_21 )
{
struct V_8 * V_9 = F_33 ( V_21 ) ;
F_34 ( V_9 ) ;
F_31 ( V_9 ) ;
return 0 ;
}
static T_6 int F_35 ( void )
{
return F_36 ( & V_71 ) ;
}
static T_7 void F_37 ( void )
{
F_38 ( & V_71 ) ;
}
