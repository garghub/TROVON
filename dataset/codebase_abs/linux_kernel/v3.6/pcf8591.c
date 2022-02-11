static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 * 10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
unsigned long V_10 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_12 ) ;
int V_13 ;
V_13 = F_5 ( V_5 , 10 , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_10 /= 10 ;
if ( V_10 > 255 )
return - V_14 ;
V_7 -> V_8 = V_10 ;
F_6 ( V_12 , V_7 -> V_15 , V_7 -> V_8 ) ;
return V_9 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
return sprintf ( V_5 , L_2 , ! ( ! ( V_7 -> V_15 & V_16 ) ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_9 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_12 ) ;
unsigned long V_10 ;
int V_13 ;
V_13 = F_5 ( V_5 , 10 , & V_10 ) ;
if ( V_13 )
return V_13 ;
F_9 ( & V_7 -> V_17 ) ;
if ( V_10 )
V_7 -> V_15 |= V_16 ;
else
V_7 -> V_15 &= ~ V_16 ;
F_10 ( V_12 , V_7 -> V_15 ) ;
F_11 ( & V_7 -> V_17 ) ;
return V_9 ;
}
static int F_12 ( struct V_11 * V_12 ,
const struct V_18 * V_19 )
{
struct V_6 * V_7 ;
int V_13 ;
V_7 = F_13 ( & V_12 -> V_2 , sizeof( struct V_6 ) ,
V_20 ) ;
if ( ! V_7 )
return - V_21 ;
F_14 ( V_12 , V_7 ) ;
F_15 ( & V_7 -> V_17 ) ;
F_16 ( V_12 ) ;
V_13 = F_17 ( & V_12 -> V_2 . V_22 , & V_23 ) ;
if ( V_13 )
return V_13 ;
if ( V_24 != 3 ) {
V_13 = F_18 ( & V_12 -> V_2 , & V_25 ) ;
if ( V_13 )
goto V_26;
}
if ( V_24 == 0 ) {
V_13 = F_18 ( & V_12 -> V_2 , & V_27 ) ;
if ( V_13 )
goto V_26;
}
V_7 -> V_28 = F_19 ( & V_12 -> V_2 ) ;
if ( F_20 ( V_7 -> V_28 ) ) {
V_13 = F_21 ( V_7 -> V_28 ) ;
goto V_26;
}
return 0 ;
V_26:
F_22 ( & V_12 -> V_2 . V_22 , & V_29 ) ;
F_22 ( & V_12 -> V_2 . V_22 , & V_23 ) ;
return V_13 ;
}
static int F_23 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_2 ( V_12 ) ;
F_24 ( V_7 -> V_28 ) ;
F_22 ( & V_12 -> V_2 . V_22 , & V_29 ) ;
F_22 ( & V_12 -> V_2 . V_22 , & V_23 ) ;
return 0 ;
}
static void F_16 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_2 ( V_12 ) ;
V_7 -> V_15 = V_30 ;
V_7 -> V_8 = V_31 ;
F_6 ( V_12 , V_7 -> V_15 , V_7 -> V_8 ) ;
F_25 ( V_12 ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_32 )
{
T_3 V_33 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_12 ) ;
F_9 ( & V_7 -> V_17 ) ;
if ( ( V_7 -> V_15 & V_34 ) != V_32 ) {
V_7 -> V_15 = ( V_7 -> V_15 & ~ V_34 )
| V_32 ;
F_10 ( V_12 , V_7 -> V_15 ) ;
F_25 ( V_12 ) ;
}
V_33 = F_25 ( V_12 ) ;
F_11 ( & V_7 -> V_17 ) ;
if ( ( V_32 == 2 && V_24 == 2 ) ||
( V_32 != 3 && ( V_24 == 1 || V_24 == 3 ) ) )
return 10 * F_27 ( V_33 ) ;
else
return 10 * V_33 ;
}
static int T_4 F_28 ( void )
{
if ( V_24 < 0 || V_24 > 3 ) {
F_29 ( L_3 , V_24 ) ;
V_24 = 0 ;
}
return F_30 ( & V_35 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_35 ) ;
}
