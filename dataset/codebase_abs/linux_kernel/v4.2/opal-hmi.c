static void F_1 ( struct V_1 * V_2 )
{
const char * V_3 , * V_4 , * V_5 ;
static const char * V_6 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12
} ;
if ( V_2 -> V_7 < V_8 ) {
F_2 ( L_13 ,
V_2 -> V_7 ) ;
return;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_3 = V_11 ;
V_4 = L_14 ;
break;
case V_12 :
V_3 = V_13 ;
V_4 = L_15 ;
break;
case V_14 :
V_3 = V_15 ;
V_4 = L_16 ;
break;
case V_16 :
default:
V_3 = V_15 ;
V_4 = L_17 ;
break;
}
F_3 ( L_18 ,
V_3 , V_4 ,
V_2 -> V_17 == V_18 ?
L_19 : L_20 ) ;
V_5 = V_2 -> type < F_4 ( V_6 ) ?
V_6 [ V_2 -> type ]
: L_21 ;
F_3 ( L_22 , V_3 , V_5 ) ;
F_3 ( L_23 , V_3 , F_5 ( V_2 -> V_19 ) ) ;
if ( ( V_2 -> type == V_20 ) ||
( V_2 -> type == V_21 ) )
F_3 ( L_24 , V_3 ,
F_5 ( V_2 -> V_22 ) ) ;
}
static void F_6 ( struct V_23 * V_24 )
{
unsigned long V_25 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
T_1 V_17 ;
F_7 ( & V_28 , V_25 ) ;
while ( ! F_8 ( & V_29 ) ) {
V_27 = F_9 ( V_29 . V_30 ,
struct V_26 , V_31 ) ;
F_10 ( & V_27 -> V_31 ) ;
F_11 ( & V_28 , V_25 ) ;
V_2 = (struct V_1 * ) & V_27 -> V_2 ;
F_1 ( V_2 ) ;
V_17 = V_2 -> V_17 ;
F_12 ( V_27 ) ;
if ( V_17 != V_18 )
F_13 ( L_25 ) ;
F_7 ( & V_28 , V_25 ) ;
}
F_11 ( & V_28 , V_25 ) ;
}
static int F_14 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
unsigned long V_25 ;
struct V_1 * V_2 ;
struct V_36 * V_37 = V_35 ;
struct V_26 * V_27 ;
if ( V_34 != V_38 )
return 0 ;
V_2 = (struct V_1 * ) & V_37 -> V_39 [ 0 ] ;
V_27 = F_15 ( sizeof( * V_27 ) , V_40 ) ;
if ( ! V_27 ) {
F_2 ( L_26 ) ;
return - V_41 ;
}
memcpy ( & V_27 -> V_2 , V_2 , sizeof( struct V_1 ) ) ;
F_7 ( & V_28 , V_25 ) ;
F_16 ( & V_27 -> V_31 , & V_29 ) ;
F_11 ( & V_28 , V_25 ) ;
F_17 ( & V_42 ) ;
return 0 ;
}
int T_2 F_18 ( void )
{
int V_43 ;
if ( ! V_44 ) {
V_43 = F_19 (
V_38 , & V_45 ) ;
if ( V_43 ) {
F_2 ( L_27 ,
V_46 , V_43 ) ;
return V_43 ;
}
V_44 = 1 ;
}
return 0 ;
}
