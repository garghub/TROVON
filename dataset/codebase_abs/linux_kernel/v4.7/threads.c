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
V_2 , & V_2 -> V_8 , & V_2 -> V_9 ) ;
V_2 -> V_10 = 0 ;
F_7 ( 0 , & V_2 -> V_11 ) ;
F_8 ( V_12 , & V_2 -> V_13 , 0 ) ;
F_8 ( V_12 , & V_2 -> V_14 , 0 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_15 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
unsigned long rand ;
F_6 ( L_4 ,
V_2 , & V_2 -> V_8 , & V_2 -> V_9 ,
V_2 -> V_10 ) ;
F_7 ( V_16 , & V_2 -> V_17 ) ;
if ( V_2 -> V_10 == 0 ) {
V_2 -> V_10 = V_18 ;
F_8 ( V_12 , & V_2 -> V_19 , 0 ) ;
return;
}
F_11 ( & rand , sizeof( rand ) ) ;
F_6 ( L_5 ,
rand % V_2 -> V_10 , V_2 -> V_10 ,
V_2 , & V_2 -> V_8 , & V_2 -> V_9 ) ;
F_8 ( V_12 , & V_2 -> V_19 ,
rand % V_2 -> V_10 ) ;
V_2 -> V_10 = F_12 ( V_2 -> V_10 * 2 ,
V_20 ) ;
}
void F_13 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 , struct V_1 , V_19 . V_22 ) ;
int V_23 ;
F_15 ( V_16 , & V_2 -> V_17 ) ;
if ( F_2 ( V_2 , V_24 , V_15 ) ) {
V_23 = V_2 -> V_25 -> V_26 ( V_2 ) ;
F_6 ( L_6 ,
V_2 , & V_2 -> V_8 , & V_2 -> V_9 , V_23 ) ;
if ( V_23 ) {
if ( F_2 ( V_2 , V_15 , V_24 ) )
F_10 ( V_2 ) ;
else
F_16 ( V_2 , L_7 ) ;
}
}
}
void F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 , struct V_1 , V_13 . V_22 ) ;
int V_23 ;
if ( F_18 ( V_2 ) == V_4 ) {
F_15 ( V_27 , & V_2 -> V_17 ) ;
V_23 = F_19 ( V_2 ) ;
F_20 () ;
F_6 ( L_8 , V_2 , V_23 ) ;
switch ( V_23 ) {
case - V_28 :
F_21 ( V_29 ) ;
F_8 ( V_12 , & V_2 -> V_13 , 0 ) ;
break;
case - V_30 :
F_21 ( V_31 ) ;
F_8 ( V_12 , & V_2 -> V_13 , 2 ) ;
default:
break;
}
}
}
void F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 , struct V_1 , V_14 . V_22 ) ;
int V_23 ;
if ( F_18 ( V_2 ) == V_4 ) {
V_23 = V_2 -> V_25 -> V_32 ( V_2 ) ;
F_6 ( L_8 , V_2 , V_23 ) ;
switch ( V_23 ) {
case - V_28 :
F_21 ( V_33 ) ;
F_8 ( V_12 , & V_2 -> V_14 , 0 ) ;
break;
case - V_30 :
F_21 ( V_34 ) ;
F_8 ( V_12 , & V_2 -> V_14 , 2 ) ;
default:
break;
}
}
}
void F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 , struct V_1 , V_35 ) ;
F_24 ( V_2 ) ;
}
void F_25 ( void )
{
F_26 ( V_12 ) ;
}
int F_27 ( void )
{
V_12 = F_28 ( L_9 ) ;
if ( ! V_12 )
return - V_30 ;
return 0 ;
}
