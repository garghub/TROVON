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
V_11 = V_7 [ 0 ] ;
if ( V_11 > ( V_1 -> V_17 - 1 ) )
V_11 = V_1 -> V_17 - 1 ;
F_5 ( & V_3 -> V_3 , & V_7 [ 1 ] , V_11 ) ;
F_6 ( & V_3 -> V_3 ) ;
} else {
F_3 ( & V_3 -> V_15 , L_3 , V_16 ) ;
}
exit:
F_7 ( & V_6 -> V_18 ) ;
if ( ! V_6 -> V_19 ) {
V_10 = F_8 ( V_3 -> V_20 , V_21 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_15 ,
L_4 ,
V_16 , V_10 ) ;
} else
V_6 -> V_22 = true ;
F_10 ( & V_6 -> V_18 ) ;
}
static int F_11 ( struct V_23 * V_24 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_25 ;
int V_10 = 0 ;
F_12 ( & V_6 -> V_18 , V_25 ) ;
V_6 -> V_19 = false ;
V_6 -> V_22 = false ;
F_13 ( & V_6 -> V_18 , V_25 ) ;
V_10 = F_8 ( V_3 -> V_20 , V_26 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_15 ,
L_4 ,
V_16 , V_10 ) ;
return V_10 ;
}
static void F_14 ( struct V_2 * V_3 )
{
F_15 ( V_3 -> V_20 ) ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = V_24 -> V_27 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_17 ( & V_6 -> V_18 ) ;
V_6 -> V_19 = true ;
F_18 ( & V_6 -> V_18 ) ;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_2 * V_3 = V_24 -> V_27 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_10 ;
bool V_28 ;
F_17 ( & V_6 -> V_18 ) ;
V_6 -> V_19 = false ;
V_28 = V_6 -> V_22 ;
V_6 -> V_22 = false ;
F_18 ( & V_6 -> V_18 ) ;
if ( V_28 ) {
V_10 = F_8 ( V_3 -> V_20 , V_26 ) ;
if ( V_10 )
F_9 ( & V_3 -> V_15 ,
L_5 ,
V_16 , V_10 ) ;
}
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
V_6 = F_21 ( sizeof( * V_6 ) , V_26 ) ;
if ( ! V_6 )
return - V_29 ;
F_22 ( & V_6 -> V_18 ) ;
F_23 ( V_3 , V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
