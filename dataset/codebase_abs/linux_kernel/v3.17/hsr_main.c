static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 , * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
V_6 = F_2 ( V_4 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 == NULL ) {
if ( ! F_4 ( V_6 ) )
return V_14 ;
V_11 = F_5 ( V_6 ) ;
V_8 = F_6 ( V_11 , V_15 ) ;
} else {
V_11 = V_8 -> V_11 ;
}
switch ( V_3 ) {
case V_16 :
case V_17 :
case V_18 :
F_7 ( V_11 ) ;
break;
case V_19 :
if ( V_8 -> type == V_15 ) {
break;
}
V_9 = F_6 ( V_11 , V_15 ) ;
if ( V_8 -> type == V_20 ) {
F_8 ( V_9 -> V_6 -> V_21 , V_6 -> V_21 ) ;
F_9 ( V_19 , V_9 -> V_6 ) ;
}
V_8 = F_6 ( V_11 , V_22 ) ;
V_13 = F_10 ( & V_11 -> V_23 ,
V_9 -> V_6 -> V_21 ,
V_8 ?
V_8 -> V_6 -> V_21 :
V_9 -> V_6 -> V_21 ) ;
if ( V_13 )
F_11 ( V_9 -> V_6 ,
L_1 ) ;
break;
case V_24 :
if ( V_8 -> type == V_15 )
break;
V_12 = F_12 ( V_8 -> V_11 ) ;
V_9 = F_6 ( V_8 -> V_11 , V_15 ) ;
V_9 -> V_6 -> V_25 = V_12 ;
break;
case V_26 :
F_13 ( V_8 ) ;
break;
case V_27 :
return V_28 ;
}
return V_14 ;
}
struct V_7 * F_6 ( struct V_10 * V_11 , enum V_29 V_30 )
{
struct V_7 * V_8 ;
F_14 (hsr, port)
if ( V_8 -> type == V_30 )
return V_8 ;
return NULL ;
}
static int T_1 F_15 ( void )
{
int V_13 ;
F_16 ( sizeof( struct V_31 ) != V_32 ) ;
F_17 ( & V_33 ) ;
V_13 = F_18 () ;
return V_13 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_33 ) ;
F_21 () ;
}
