static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_6 = V_7 ;
if ( V_5 -> V_8 )
V_6 |= V_9 ;
return F_4 ( V_5 , V_10 + V_4 ,
V_7 | V_9 |
V_11 , V_6 ) ;
}
static int F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_12 ;
V_12 = F_6 ( V_5 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & 1 << V_4 )
return 1 ;
else
return 0 ;
}
static void F_7 ( struct V_2 * V_3 , unsigned V_4 , int V_14 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
F_4 ( V_5 , V_13 , 1 << V_4 ,
V_14 << V_4 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned V_4 , int V_14 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_6 = 0 ;
int V_12 ;
if ( V_5 -> V_8 )
V_6 |= V_9 ;
V_12 = F_4 ( V_5 , V_10 + V_4 ,
V_7 | V_9 |
V_11 , V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
F_7 ( V_3 , V_4 , V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
return F_10 ( V_5 -> V_15 ,
V_16 + V_4 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned V_17 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_18 = V_10 + V_4 ;
int V_12 , V_19 ;
V_12 = F_6 ( V_5 , V_18 ) ;
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
return F_4 ( V_5 , V_18 , V_11 , V_19 ) ;
}
static void F_12 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < V_3 -> V_26 ; V_24 ++ ) {
int V_27 = V_24 + V_3 -> V_28 ;
int V_18 ;
const char * V_29 , * V_30 , * V_31 ;
V_29 = F_13 ( V_3 , V_24 ) ;
if ( ! V_29 )
V_29 = L_1 ;
F_14 ( V_23 , L_2 , V_27 , V_29 ) ;
V_18 = F_6 ( V_5 , V_10 + V_24 ) ;
if ( V_18 < 0 ) {
F_15 ( V_5 -> V_32 ,
L_3 ,
V_27 , V_18 ) ;
F_14 ( V_23 , L_4 ) ;
continue;
}
switch ( V_18 & V_33 ) {
case V_34 :
V_30 = L_5 ;
break;
case V_35 :
V_30 = L_6 ;
break;
case V_36 :
V_30 = L_7 ;
break;
default:
V_30 = L_8 ;
break;
}
switch ( V_24 + 1 ) {
case 1 ... 3 :
case 7 ... 9 :
if ( V_18 & V_37 )
V_31 = L_9 ;
else
V_31 = L_10 ;
break;
case 4 ... 6 :
case 10 ... 12 :
if ( V_18 & V_37 )
V_31 = L_11 ;
else
V_31 = L_10 ;
break;
case 13 ... 16 :
V_31 = L_12 ;
break;
default:
F_16 () ;
break;
}
V_25 = V_18 & V_9 ;
if ( V_5 -> V_8 )
V_25 = ! V_25 ;
F_14 ( V_23 , L_13
L_14 ,
V_18 & V_7 ? L_15 : L_16 ,
F_5 ( V_3 , V_24 ) ? L_17 : L_18 ,
V_30 ,
V_31 ,
V_18 & V_38 ? L_19 : L_20 ,
V_18 & V_39 ? L_21 : L_22 ,
V_25 ? L_23 : L_19 ,
V_18 ) ;
}
}
static int F_17 ( struct V_40 * V_41 )
{
struct V_5 * V_5 = F_18 ( V_41 -> V_32 . V_42 ) ;
struct V_43 * V_44 = V_5 -> V_32 -> V_45 ;
struct V_1 * V_1 ;
int V_12 ;
V_1 = F_19 ( & V_41 -> V_32 , sizeof( * V_1 ) ,
V_46 ) ;
if ( V_1 == NULL )
return - V_47 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_2 = V_48 ;
V_1 -> V_2 . V_26 = V_5 -> V_49 ;
V_1 -> V_2 . V_32 = & V_41 -> V_32 ;
if ( V_44 && V_44 -> V_50 )
V_1 -> V_2 . V_28 = V_44 -> V_50 ;
else
V_1 -> V_2 . V_28 = - 1 ;
V_12 = F_20 ( & V_1 -> V_2 ) ;
if ( V_12 < 0 ) {
F_15 ( & V_41 -> V_32 , L_24 , V_12 ) ;
return V_12 ;
}
F_21 ( V_41 , V_1 ) ;
return V_12 ;
}
static int F_22 ( struct V_40 * V_41 )
{
struct V_1 * V_1 = F_23 ( V_41 ) ;
return F_24 ( & V_1 -> V_2 ) ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_51 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_51 ) ;
}
