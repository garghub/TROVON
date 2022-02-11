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
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
return F_10 ( V_5 -> V_13 , V_3 ) ;
}
static const char * F_11 ( T_1 V_14 )
{
switch ( V_14 ) {
case V_15 :
return L_1 ;
case V_16 :
return L_2 ;
case V_17 :
return L_3 ;
case V_18 :
return L_4 ;
case V_19 :
return L_5 ;
case V_20 :
return L_6 ;
case V_21 :
return L_7 ;
case V_22 :
return L_8 ;
case V_23 :
return L_9 ;
case V_24 :
return L_10 ;
case V_25 :
return L_11 ;
case V_26 :
return L_12 ;
case V_27 :
return L_13 ;
case V_28 :
return L_14 ;
case V_29 :
return L_15 ;
case V_30 :
return L_16 ;
case V_31 :
return L_17 ;
case V_32 :
return L_18 ;
case V_33 :
return L_19 ;
case V_34 :
return L_20 ;
case V_35 :
return L_21 ;
case V_36 :
return L_22 ;
case V_37 :
return L_22 ;
default:
return L_23 ;
}
}
static void F_12 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_41 ; V_40 ++ ) {
int V_42 = V_40 + V_2 -> V_43 ;
int V_44 ;
const char * V_45 ;
V_45 = F_13 ( V_2 , V_40 ) ;
if ( ! V_45 )
V_45 = L_24 ;
F_14 ( V_39 , L_25 , V_42 , V_45 ) ;
V_44 = F_6 ( V_5 , V_8 + V_40 ) ;
if ( V_44 < 0 ) {
F_15 ( V_5 -> V_46 ,
L_26 ,
V_42 , V_44 ) ;
F_14 ( V_39 , L_27 ) ;
continue;
}
if ( V_44 & V_9 )
F_14 ( V_39 , L_28 ) ;
else
F_14 ( V_39 , L_29 ) ;
if ( V_44 & V_47 )
F_14 ( V_39 , L_30 ) ;
if ( V_44 & V_48 )
F_14 ( V_39 , L_31 ) ;
if ( V_44 & V_49 )
F_14 ( V_39 , L_32 ) ;
else
F_14 ( V_39 , L_33 ) ;
if ( V_44 & V_50 )
F_14 ( V_39 , L_34 ) ;
else
F_14 ( V_39 , L_35 ) ;
F_14 ( V_39 , L_36 ,
F_11 ( V_44 & V_51 ) , V_44 ) ;
}
}
static int F_16 ( struct V_52 * V_53 )
{
struct V_5 * V_5 = F_17 ( V_53 -> V_46 . V_54 ) ;
struct V_55 * V_56 = F_18 ( V_5 -> V_46 ) ;
struct V_4 * V_4 ;
int V_10 ;
V_4 = F_19 ( & V_53 -> V_46 , sizeof( * V_4 ) ,
V_57 ) ;
if ( V_4 == NULL )
return - V_58 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_59 ;
V_4 -> V_1 . V_41 = V_60 ;
V_4 -> V_1 . V_54 = & V_53 -> V_46 ;
if ( V_56 && V_56 -> V_61 )
V_4 -> V_1 . V_43 = V_56 -> V_61 ;
else
V_4 -> V_1 . V_43 = - 1 ;
V_10 = F_20 ( & V_53 -> V_46 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_10 < 0 ) {
F_15 ( & V_53 -> V_46 , L_37 ,
V_10 ) ;
return V_10 ;
}
F_21 ( V_53 , V_4 ) ;
return V_10 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_62 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_62 ) ;
}
