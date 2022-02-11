static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned char * V_7 = V_1 -> V_8 ;
int V_9 = V_1 -> V_9 ;
int V_10 ;
int V_11 ;
switch ( V_9 ) {
case 0 :
break;
case - V_12 :
case - V_13 :
case - V_14 :
F_3 ( & V_3 -> V_15 , L_1 ,
V_16 , V_9 ) ;
return;
default:
F_3 ( & V_3 -> V_15 , L_2 ,
V_16 , V_9 ) ;
goto exit;
}
F_4 ( & V_3 -> V_15 , V_16 , V_1 -> V_17 , V_7 ) ;
if ( V_1 -> V_17 > 1 ) {
V_11 = V_1 -> V_17 - 1 ;
F_5 ( & V_3 -> V_3 , & V_7 [ 1 ] , V_11 ) ;
F_6 ( & V_3 -> V_3 ) ;
} else {
F_3 ( & V_3 -> V_15 ,
L_3
L_4 , V_1 -> V_17 ) ;
}
exit:
F_7 ( & V_6 -> V_18 ) ;
if ( ! V_6 -> V_19 ) {
V_10 = F_8 ( V_3 -> V_20 , V_21 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_15 ,
L_5 ,
V_16 , V_10 ) ;
} else
V_6 -> V_22 = true ;
F_10 ( & V_6 -> V_18 ) ;
}
static int F_11 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_12 ( V_3 -> V_25 ) ;
unsigned long V_26 ;
int V_10 = 0 ;
F_13 ( & V_6 -> V_18 , V_26 ) ;
V_6 -> V_19 = false ;
V_6 -> V_22 = false ;
F_14 ( & V_6 -> V_18 , V_26 ) ;
V_10 = F_8 ( V_3 -> V_20 , V_27 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_15 ,
L_5 ,
V_16 , V_10 ) ;
return V_10 ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_16 ( V_3 -> V_20 ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = V_24 -> V_28 ;
struct V_5 * V_6 = F_12 ( V_3 -> V_25 ) ;
F_18 ( & V_6 -> V_18 ) ;
V_6 -> V_19 = true ;
F_19 ( & V_6 -> V_18 ) ;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = V_24 -> V_28 ;
struct V_5 * V_6 = F_12 ( V_3 -> V_25 ) ;
int V_10 ;
bool V_29 ;
F_18 ( & V_6 -> V_18 ) ;
V_6 -> V_19 = false ;
V_29 = V_6 -> V_22 ;
V_6 -> V_22 = false ;
F_19 ( & V_6 -> V_18 ) ;
if ( V_29 ) {
V_10 = F_8 ( V_3 -> V_20 , V_27 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_15 ,
L_6 ,
V_16 , V_10 ) ;
}
}
static int F_21 ( struct V_30 * V_25 )
{
if ( ! V_25 -> V_31 ) {
F_9 ( & V_25 -> V_15 -> V_15 , L_7 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
V_6 = F_23 ( sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 )
return - V_33 ;
F_24 ( & V_6 -> V_18 ) ;
F_25 ( V_3 , V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
