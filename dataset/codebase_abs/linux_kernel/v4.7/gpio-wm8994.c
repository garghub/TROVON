static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
switch ( V_5 -> type ) {
case V_6 :
switch ( V_3 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 6 :
return - V_7 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
return F_4 ( V_5 , V_8 + V_3 ,
V_9 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_10 ;
V_10 = F_6 ( V_5 , V_8 + V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 & V_11 )
return 1 ;
else
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
return F_4 ( V_5 , V_8 + V_3 ,
V_9 | V_11 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_12 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
F_4 ( V_5 , V_8 + V_3 , V_11 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_13 V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
switch ( V_14 ) {
case V_15 :
return F_4 ( V_5 , V_8 + V_3 ,
V_16 ,
V_17 ) ;
case V_18 :
return F_4 ( V_5 , V_8 + V_3 ,
V_16 , 0 ) ;
default:
break;
}
return - V_19 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
return F_11 ( V_5 -> V_20 , V_3 ) ;
}
static const char * F_12 ( T_1 V_21 )
{
switch ( V_21 ) {
case V_22 :
return L_1 ;
case V_23 :
return L_2 ;
case V_24 :
return L_3 ;
case V_25 :
return L_4 ;
case V_26 :
return L_5 ;
case V_27 :
return L_6 ;
case V_28 :
return L_7 ;
case V_29 :
return L_8 ;
case V_30 :
return L_9 ;
case V_31 :
return L_10 ;
case V_32 :
return L_11 ;
case V_33 :
return L_12 ;
case V_34 :
return L_13 ;
case V_35 :
return L_14 ;
case V_36 :
return L_15 ;
case V_37 :
return L_16 ;
case V_38 :
return L_17 ;
case V_39 :
return L_18 ;
case V_40 :
return L_19 ;
case V_41 :
return L_20 ;
case V_42 :
return L_21 ;
case V_43 :
return L_22 ;
case V_44 :
return L_22 ;
default:
return L_23 ;
}
}
static void F_13 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_48 ; V_47 ++ ) {
int V_49 = V_47 + V_2 -> V_50 ;
int V_51 ;
const char * V_52 ;
V_52 = F_14 ( V_2 , V_47 ) ;
if ( ! V_52 )
V_52 = L_24 ;
F_15 ( V_46 , L_25 , V_49 , V_52 ) ;
V_51 = F_6 ( V_5 , V_8 + V_47 ) ;
if ( V_51 < 0 ) {
F_16 ( V_5 -> V_53 ,
L_26 ,
V_49 , V_51 ) ;
F_15 ( V_46 , L_27 ) ;
continue;
}
if ( V_51 & V_9 )
F_15 ( V_46 , L_28 ) ;
else
F_15 ( V_46 , L_29 ) ;
if ( V_51 & V_54 )
F_15 ( V_46 , L_30 ) ;
if ( V_51 & V_55 )
F_15 ( V_46 , L_31 ) ;
if ( V_51 & V_56 )
F_15 ( V_46 , L_32 ) ;
else
F_15 ( V_46 , L_33 ) ;
if ( V_51 & V_17 )
F_15 ( V_46 , L_34 ) ;
else
F_15 ( V_46 , L_35 ) ;
F_15 ( V_46 , L_36 ,
F_12 ( V_51 & V_57 ) , V_51 ) ;
}
}
static int F_17 ( struct V_58 * V_59 )
{
struct V_5 * V_5 = F_18 ( V_59 -> V_53 . V_60 ) ;
struct V_61 * V_62 = F_19 ( V_5 -> V_53 ) ;
struct V_4 * V_4 ;
int V_10 ;
V_4 = F_20 ( & V_59 -> V_53 , sizeof( * V_4 ) ,
V_63 ) ;
if ( V_4 == NULL )
return - V_64 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_65 ;
V_4 -> V_1 . V_48 = V_66 ;
V_4 -> V_1 . V_60 = & V_59 -> V_53 ;
if ( V_62 && V_62 -> V_67 )
V_4 -> V_1 . V_50 = V_62 -> V_67 ;
else
V_4 -> V_1 . V_50 = - 1 ;
V_10 = F_21 ( & V_59 -> V_53 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_10 < 0 ) {
F_16 ( & V_59 -> V_53 , L_37 ,
V_10 ) ;
return V_10 ;
}
F_22 ( V_59 , V_4 ) ;
return V_10 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_68 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_68 ) ;
}
