static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = V_7 ;
if ( V_5 -> V_8 )
V_6 |= V_9 ;
return F_3 ( V_5 , V_10 + V_3 ,
V_7 | V_9 |
V_11 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_12 ;
V_12 = F_5 ( V_5 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & 1 << V_3 )
return 1 ;
else
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_3 ( V_5 , V_13 , 1 << V_3 ,
V_14 << V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 0 ;
int V_12 ;
if ( V_5 -> V_8 )
V_6 |= V_9 ;
V_12 = F_3 ( V_5 , V_10 + V_3 ,
V_7 | V_9 |
V_11 , V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
F_6 ( V_2 , V_3 , V_14 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
return F_9 ( V_5 -> V_15 ,
V_16 + V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_17 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_18 = V_10 + V_3 ;
int V_12 , V_19 ;
V_12 = F_5 ( V_5 , V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
switch ( V_12 & V_11 ) {
case 0 :
case 1 :
break;
default:
return - V_20 ;
}
if ( V_17 >= 32 && V_17 <= 64 )
V_19 = 0 ;
else if ( V_17 >= 4000 && V_17 <= 8000 )
V_19 = 1 ;
else
return - V_21 ;
return F_3 ( V_5 , V_18 , V_11 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_22 V_23 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_18 = V_10 + V_3 ;
switch ( V_23 ) {
case V_24 :
return F_3 ( V_5 , V_18 ,
V_25 , V_26 ) ;
case V_27 :
return F_3 ( V_5 , V_18 ,
V_25 , 0 ) ;
default:
break;
}
return - V_28 ;
}
static void F_12 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_31 , V_32 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_33 ; V_31 ++ ) {
int V_34 = V_31 + V_2 -> V_35 ;
int V_18 ;
const char * V_36 , * V_37 , * V_38 ;
V_36 = F_13 ( V_2 , V_31 ) ;
if ( ! V_36 )
V_36 = L_1 ;
F_14 ( V_30 , L_2 , V_34 , V_36 ) ;
V_18 = F_5 ( V_5 , V_10 + V_31 ) ;
if ( V_18 < 0 ) {
F_15 ( V_5 -> V_39 ,
L_3 ,
V_34 , V_18 ) ;
F_14 ( V_30 , L_4 ) ;
continue;
}
switch ( V_18 & V_40 ) {
case V_41 :
V_37 = L_5 ;
break;
case V_42 :
V_37 = L_6 ;
break;
case V_43 :
V_37 = L_7 ;
break;
default:
V_37 = L_8 ;
break;
}
switch ( V_31 + 1 ) {
case 1 ... 3 :
case 7 ... 9 :
if ( V_18 & V_44 )
V_38 = L_9 ;
else
V_38 = L_10 ;
break;
case 4 ... 6 :
case 10 ... 12 :
if ( V_18 & V_44 )
V_38 = L_11 ;
else
V_38 = L_10 ;
break;
case 13 ... 16 :
V_38 = L_12 ;
break;
default:
F_16 () ;
break;
}
V_32 = V_18 & V_9 ;
if ( V_5 -> V_8 )
V_32 = ! V_32 ;
F_14 ( V_30 , L_13
L_14 ,
V_18 & V_7 ? L_15 : L_16 ,
F_4 ( V_2 , V_31 ) ? L_17 : L_18 ,
V_37 ,
V_38 ,
V_18 & V_45 ? L_19 : L_20 ,
V_18 & V_26 ? L_21 : L_22 ,
V_32 ? L_23 : L_19 ,
V_18 ) ;
}
}
static int F_17 ( struct V_46 * V_47 )
{
struct V_5 * V_5 = F_18 ( V_47 -> V_39 . V_48 ) ;
struct V_49 * V_50 = F_19 ( V_5 -> V_39 ) ;
struct V_4 * V_4 ;
int V_12 ;
V_4 = F_20 ( & V_47 -> V_39 , sizeof( * V_4 ) ,
V_51 ) ;
if ( V_4 == NULL )
return - V_52 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_53 ;
V_4 -> V_1 . V_33 = V_5 -> V_54 ;
V_4 -> V_1 . V_48 = & V_47 -> V_39 ;
if ( V_50 && V_50 -> V_55 )
V_4 -> V_1 . V_35 = V_50 -> V_55 ;
else
V_4 -> V_1 . V_35 = - 1 ;
V_12 = F_21 ( & V_47 -> V_39 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_12 < 0 ) {
F_15 ( & V_47 -> V_39 , L_24 , V_12 ) ;
return V_12 ;
}
F_22 ( V_47 , V_4 ) ;
return V_12 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_56 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_56 ) ;
}
