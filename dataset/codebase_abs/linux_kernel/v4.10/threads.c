void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 , V_3 , V_4 ) ) {
F_3 ( V_5 L_1
L_2 ,
V_6 ,
F_4 ( & V_2 -> V_7 ) ) ;
F_5 ( V_2 ) ;
return;
}
F_6 ( L_3 ,
V_2 -> V_8 , & V_2 -> V_8 -> V_9 , & V_2 -> V_8 -> V_10 ) ;
V_2 -> V_11 = 0 ;
F_7 ( 0 , & V_2 -> V_8 -> V_12 ) ;
F_8 ( V_13 , & V_2 -> V_14 , 0 ) ;
F_8 ( V_13 , & V_2 -> V_15 , 0 ) ;
}
void F_9 ( struct V_16 * V_17 )
{
F_1 ( & V_17 -> V_18 [ 0 ] , V_19 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
unsigned long rand ;
struct V_16 * V_17 = V_2 -> V_8 ;
F_6 ( L_4 ,
V_17 , & V_17 -> V_9 , & V_17 -> V_10 ,
V_2 -> V_11 ) ;
if ( V_17 -> V_20 -> V_21 == V_22 &&
V_17 -> V_9 > V_17 -> V_10 )
return;
F_7 ( V_23 , & V_2 -> V_24 ) ;
if ( V_2 -> V_11 == 0 ) {
V_2 -> V_11 = V_25 ;
F_8 ( V_13 , & V_2 -> V_26 , 0 ) ;
return;
}
F_11 ( & rand , sizeof( rand ) ) ;
F_6 ( L_5 ,
rand % V_2 -> V_11 , V_2 -> V_11 ,
V_17 , & V_17 -> V_9 , & V_17 -> V_10 ) ;
F_8 ( V_13 , & V_2 -> V_26 ,
rand % V_2 -> V_11 ) ;
V_2 -> V_11 = F_12 ( V_2 -> V_11 * 2 ,
V_27 ) ;
}
void F_13 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ,
struct V_1 ,
V_26 . V_29 ) ;
struct V_16 * V_17 = V_2 -> V_8 ;
int V_30 ;
if ( V_2 -> V_31 > 1 && V_2 -> V_8 -> V_9 > V_2 -> V_8 -> V_10 )
return;
F_15 ( V_23 , & V_2 -> V_24 ) ;
V_30 = F_2 ( V_2 , V_32 , V_19 ) ;
if ( V_30 ) {
V_30 = V_17 -> V_20 -> V_33 ( V_2 ) ;
F_6 ( L_6 ,
V_17 , & V_17 -> V_9 , & V_17 -> V_10 , V_30 ) ;
if ( V_30 ) {
if ( F_2 ( V_2 ,
V_19 ,
V_32 ) )
F_10 ( V_2 ) ;
else
F_16 ( V_2 , L_7 ) ;
}
}
}
void F_17 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ,
struct V_1 ,
V_14 . V_29 ) ;
int V_30 ;
if ( F_18 ( V_2 ) == V_4 ) {
F_15 ( V_34 , & V_2 -> V_24 ) ;
V_30 = F_19 ( V_2 ) ;
F_20 () ;
F_6 ( L_8 , V_2 -> V_8 , V_30 ) ;
switch ( V_30 ) {
case - V_35 :
F_21 ( V_36 ) ;
F_8 ( V_13 , & V_2 -> V_14 , 0 ) ;
break;
case - V_37 :
F_21 ( V_38 ) ;
F_8 ( V_13 , & V_2 -> V_14 , 2 ) ;
default:
break;
}
}
}
void F_22 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ,
struct V_1 ,
V_15 . V_29 ) ;
int V_30 ;
if ( F_18 ( V_2 ) == V_4 ) {
V_30 = V_2 -> V_8 -> V_20 -> V_39 ( V_2 ) ;
F_6 ( L_8 , V_2 -> V_8 , V_30 ) ;
switch ( V_30 ) {
case - V_35 :
F_21 ( V_40 ) ;
F_8 ( V_13 , & V_2 -> V_15 , 0 ) ;
break;
case - V_37 :
F_21 ( V_41 ) ;
F_8 ( V_13 , & V_2 -> V_15 , 2 ) ;
default:
break;
}
}
}
void F_23 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_14 ( V_29 ,
struct V_1 ,
V_42 ) ;
F_24 ( V_2 ) ;
}
void F_25 ( void )
{
F_26 ( V_13 ) ;
}
int F_27 ( void )
{
V_13 = F_28 ( L_9 ) ;
if ( ! V_13 )
return - V_37 ;
return 0 ;
}
