static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 ; V_10 ++ ) {
V_11 = V_8 -> V_13 [ V_10 ] ;
if ( V_11 >= V_3 && V_11 <= V_4 )
return F_3 ( V_6 -> V_14 , V_10 ) ;
}
return - V_15 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
unsigned int V_16 ;
int V_17 ;
V_17 = F_5 ( V_6 -> V_14 , & V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_16 >= V_8 -> V_12 )
V_16 = V_8 -> V_12 - 1 ;
return V_8 -> V_13 [ V_16 ] ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_19 ;
switch ( V_18 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_18 , V_19 ) ;
}
static unsigned F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
unsigned int V_19 , V_18 = 0 ;
int V_17 ;
V_17 = F_5 ( V_6 -> V_18 , & V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_19 ) {
default:
case V_28 :
V_18 = V_20 | V_24 ;
break;
case V_25 :
return V_24 ;
case V_21 :
return V_20 ;
case V_23 :
return V_22 ;
}
V_17 = F_5 ( V_6 -> V_29 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
V_27 = V_6 -> V_30 ;
else
V_27 = V_6 -> V_31 ;
V_17 = F_5 ( V_27 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
V_18 &= V_24 ;
else
V_18 &= V_22 | V_20 ;
return V_18 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_19 ;
switch ( V_18 ) {
case V_22 :
V_19 = 0 ;
break;
case V_24 :
V_19 = 1 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_31 , V_19 ) ;
}
static unsigned F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
int V_17 , V_19 ;
V_17 = F_5 ( V_6 -> V_29 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
V_27 = V_6 -> V_30 ;
else
V_27 = V_6 -> V_31 ;
V_17 = F_5 ( V_27 , & V_19 ) ;
if ( V_17 < 0 )
return 0 ;
if ( V_19 )
return V_24 ;
else
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_17 = F_11 ( V_2 ) ;
if ( V_17 == 0 ) {
V_17 = V_32 ;
} else if ( V_17 > 0 ) {
V_17 = F_7 ( V_2 ) ;
if ( V_17 > 0 )
V_17 = F_12 ( V_17 ) ;
else if ( V_17 == 0 )
V_17 = - V_33 ;
}
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_17 = F_11 ( V_2 ) ;
if ( V_17 == 0 ) {
V_17 = V_32 ;
} else if ( V_17 > 0 ) {
V_17 = F_9 ( V_2 ) ;
if ( V_17 > 0 )
V_17 = F_12 ( V_17 ) ;
else if ( V_17 == 0 )
V_17 = - V_33 ;
}
return V_17 ;
}
static int F_14 ( struct V_1 * V_2 , int V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
int V_17 , V_16 ;
V_16 = F_15 ( V_2 , V_34 , V_34 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 <<= F_16 ( V_2 -> V_35 -> V_36 ) - 1 ;
V_17 = F_17 ( V_6 -> V_37 -> V_38 , V_8 -> V_39 ,
V_2 -> V_35 -> V_36 , V_16 ) ;
return V_17 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_29 , 1 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_29 , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 ;
switch ( V_18 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_18 , V_19 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_19 ;
switch ( V_18 ) {
case V_22 :
V_19 = 0 ;
break;
case V_24 :
V_19 = 1 ;
break;
default:
return - V_15 ;
}
return F_3 ( V_6 -> V_30 , V_19 ) ;
}
static T_1 F_22 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_44 * V_37 = V_43 -> V_45 [ 0 ] . V_37 ;
struct V_5 * V_6 ;
int V_46 = V_47 ;
int V_48 , V_49 , V_17 ;
V_17 = F_23 ( V_37 -> V_38 , V_50 , & V_48 ) ;
if ( V_17 < 0 ) {
F_24 ( V_37 -> V_51 ,
L_1 ) ;
goto V_52;
}
for ( V_49 = V_43 -> V_53 - 1 ; V_49 >= 0 ; V_49 -- ) {
V_6 = & V_43 -> V_45 [ V_49 ] ;
if ( V_6 -> V_9 -> V_54 . V_55 != V_50 )
continue;
if ( F_25 ( V_6 -> V_9 -> V_54 . V_56 ) & V_48 ) {
F_26 ( V_6 -> V_2 ,
V_57 , NULL ) ;
V_46 = V_58 ;
}
}
V_52:
return V_46 ;
}
static int F_27 ( struct V_59 * V_60 )
{
struct V_44 * V_61 = F_28 ( V_60 -> V_51 . V_62 ) ;
struct V_42 * V_43 ;
struct V_5 * V_6 ;
struct V_63 V_64 = { } ;
const struct V_7 * V_8 ;
int V_40 , V_10 , V_17 ;
T_2 V_65 ;
int V_66 ;
switch ( V_61 -> V_67 ) {
case V_68 :
V_66 = V_69 ;
V_8 = V_70 ;
break;
case V_71 :
V_66 = V_72 ;
V_8 = V_73 ;
break;
default:
F_24 ( V_61 -> V_51 , L_2 ) ;
return - V_74 ;
}
V_65 = sizeof( struct V_42 ) +
V_66 * sizeof( struct V_5 ) ;
V_43 = F_29 ( & V_60 -> V_51 , V_65 , V_75 ) ;
if ( ! V_43 )
return - V_76 ;
V_43 -> V_53 = V_66 ;
F_30 ( V_60 , V_43 ) ;
V_10 = 0 ;
while ( V_10 < V_43 -> V_53 ) {
V_6 = & V_43 -> V_45 [ V_10 ] ;
V_6 -> V_37 = V_61 ;
V_6 -> V_9 = & V_8 [ V_10 ] ;
V_6 -> V_35 = V_6 -> V_9 -> V_35 ;
V_6 -> V_35 . type = V_77 ;
V_6 -> V_35 . V_78 = V_79 ;
if ( V_6 -> V_9 -> V_18 . V_55 )
V_6 -> V_18 = F_31 (
& V_60 -> V_51 ,
V_61 -> V_38 ,
V_6 -> V_9 -> V_18 ) ;
if ( V_6 -> V_9 -> V_29 . V_55 )
V_6 -> V_29 = F_31 (
& V_60 -> V_51 ,
V_61 -> V_38 ,
V_6 -> V_9 -> V_29 ) ;
if ( V_6 -> V_9 -> V_31 . V_55 )
V_6 -> V_31 = F_31 (
& V_60 -> V_51 ,
V_61 -> V_38 ,
V_6 -> V_9 -> V_31 ) ;
if ( V_6 -> V_9 -> V_30 . V_55 )
V_6 -> V_30 = F_31 (
& V_60 -> V_51 ,
V_61 -> V_38 ,
V_6 -> V_9 -> V_30 ) ;
if ( V_6 -> V_9 -> V_14 . V_55 )
V_6 -> V_14 = F_31 (
& V_60 -> V_51 ,
V_61 -> V_38 ,
V_6 -> V_9 -> V_14 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_51 = V_61 -> V_51 ;
V_64 . V_80 = V_6 ;
V_64 . V_38 = V_61 -> V_38 ;
V_6 -> V_2 = F_32 ( & V_60 -> V_51 , & V_6 -> V_35 ,
& V_64 ) ;
if ( F_33 ( V_6 -> V_2 ) ) {
F_24 ( & V_60 -> V_51 ,
L_3 ,
V_6 -> V_35 . V_81 ) ;
return F_34 ( V_6 -> V_2 ) ;
}
V_10 ++ ;
}
V_40 = F_35 ( V_60 , L_4 ) ;
if ( V_40 < 0 ) {
F_24 ( & V_60 -> V_51 , L_5 ) ;
return V_40 ;
}
V_43 -> V_82 = V_40 ;
V_17 = F_36 ( & V_60 -> V_51 , V_40 ,
NULL , F_22 ,
V_83 | V_84 ,
L_4 , V_43 ) ;
if ( V_17 ) {
F_37 ( & V_60 -> V_51 ,
L_6 ) ;
V_43 -> V_82 = - V_85 ;
}
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_86 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_86 ) ;
}
