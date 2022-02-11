static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
switch ( V_3 ) {
case V_8 :
F_3 ( V_6 -> V_9 ) ;
break;
case V_10 :
F_4 ( V_6 -> V_9 ) ;
break;
default:
break;
}
return V_11 ;
}
static void F_5 ( struct V_12 * V_13 )
{
static char const V_14 [] = L_1 ;
static char * V_15 [] = {
L_2 ,
L_3 ,
NULL ,
} ;
static char * V_16 [] = {
( char * ) V_14 ,
L_4 ,
NULL ,
} ;
F_6 ( L_5 ,
V_16 [ 0 ] , V_16 [ 1 ] ) ;
F_7 ( V_14 , V_16 , V_15 , V_17 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_5 * V_6 ;
struct V_18 * V_9 ;
int V_19 ;
V_6 = F_2 ( V_13 , struct V_5 , V_13 . V_13 ) ;
V_9 = V_6 -> V_9 ;
F_9 ( & V_9 -> V_20 , L_6 , V_21 ) ;
V_19 = F_10 ( V_9 ) ;
if ( V_19 ) {
F_11 ( & V_9 -> V_20 ,
L_7 ,
V_19 ) ;
if ( V_9 -> V_22 == V_23 ) {
F_12 ( L_8 ) ;
} else if ( V_9 -> V_22 == V_24 ) {
F_11 ( & V_9 -> V_20 , L_9 ) ;
F_13 ( & V_25 , F_5 ) ;
F_14 ( & V_25 , V_26 / 2 ) ;
V_6 -> V_27 = false ;
}
}
if ( V_6 -> V_27 )
F_14 ( & V_6 -> V_13 , V_28 ) ;
}
int F_15 ( struct V_18 * V_9 )
{
struct V_5 * V_6 ;
int V_19 ;
if ( V_9 -> V_6 )
return 0 ;
V_6 = F_16 ( sizeof( * V_6 ) , V_29 ) ;
if ( ! V_6 )
return - V_30 ;
V_6 -> V_27 = false ;
V_6 -> V_9 = V_9 ;
F_13 ( & V_6 -> V_13 , F_8 ) ;
V_9 -> V_6 = V_6 ;
V_6 -> V_7 . V_31 = F_1 ;
V_19 = F_17 ( & V_6 -> V_7 ) ;
if ( V_19 ) {
F_11 ( & V_9 -> V_20 , L_10 ,
V_19 ) ;
goto V_32;
}
V_19 = F_4 ( V_9 ) ;
if ( V_19 ) {
F_11 ( & V_9 -> V_20 , L_11 , V_19 ) ;
F_18 ( & V_6 -> V_7 ) ;
goto V_32;
}
return V_19 ;
V_32:
V_9 -> V_6 = NULL ;
F_19 ( V_6 ) ;
return V_19 ;
}
void F_20 ( struct V_18 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
if ( ! V_6 )
return;
F_18 ( & V_6 -> V_7 ) ;
F_3 ( V_9 ) ;
V_9 -> V_6 = NULL ;
F_19 ( V_6 ) ;
}
bool F_21 ( struct V_18 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_6 )
return false ;
return V_9 -> V_6 -> V_27 ;
}
int F_4 ( struct V_18 * V_9 )
{
struct V_5 * V_6 ;
if ( ! V_9 -> V_6 )
return - V_33 ;
V_6 = V_9 -> V_6 ;
if ( V_6 -> V_27 )
return 0 ;
V_6 -> V_27 = true ;
F_14 ( & V_6 -> V_13 , V_28 ) ;
return 0 ;
}
int F_3 ( struct V_18 * V_9 )
{
struct V_5 * V_6 ;
if ( ! V_9 -> V_6 )
return - V_33 ;
V_6 = V_9 -> V_6 ;
if ( ! V_6 -> V_27 )
return 0 ;
V_6 -> V_27 = false ;
F_22 ( & V_6 -> V_13 ) ;
return 0 ;
}
