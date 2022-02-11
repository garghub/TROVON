void F_1 ( struct V_1 * V_2 )
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
unsigned long rand ;
F_6 ( L_4 ,
V_2 , & V_2 -> V_8 , & V_2 -> V_9 ,
V_2 -> V_10 ) ;
F_7 ( V_15 , & V_2 -> V_16 ) ;
if ( V_2 -> V_10 == 0 ) {
V_2 -> V_10 = V_17 ;
F_8 ( V_12 , & V_2 -> V_18 , 0 ) ;
return;
}
F_10 ( & rand , sizeof( rand ) ) ;
F_6 ( L_5 ,
rand % V_2 -> V_10 , V_2 -> V_10 ,
V_2 , & V_2 -> V_8 , & V_2 -> V_9 ) ;
F_8 ( V_12 , & V_2 -> V_18 ,
rand % V_2 -> V_10 ) ;
V_2 -> V_10 = F_11 ( V_2 -> V_10 * 2 ,
V_19 ) ;
}
void F_12 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_13 ( V_21 , struct V_1 , V_18 . V_21 ) ;
int V_22 ;
F_14 ( V_15 , & V_2 -> V_16 ) ;
if ( F_2 ( V_2 , V_23 , V_3 ) ) {
V_22 = V_2 -> V_24 -> V_25 ( V_2 ) ;
F_6 ( L_6 ,
V_2 , & V_2 -> V_8 , & V_2 -> V_9 , V_22 ) ;
if ( V_22 ) {
if ( F_2 ( V_2 , V_3 , V_23 ) )
F_9 ( V_2 ) ;
else
F_15 ( V_2 , L_7 ) ;
}
}
}
void F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_13 ( V_21 , struct V_1 , V_13 . V_21 ) ;
int V_22 ;
if ( F_17 ( V_2 ) == V_4 ) {
F_14 ( V_26 , & V_2 -> V_16 ) ;
V_22 = F_18 ( V_2 ) ;
F_19 () ;
F_6 ( L_8 , V_2 , V_22 ) ;
switch ( V_22 ) {
case - V_27 :
F_20 ( V_28 ) ;
F_8 ( V_12 , & V_2 -> V_13 , 0 ) ;
break;
case - V_29 :
F_20 ( V_30 ) ;
F_8 ( V_12 , & V_2 -> V_13 , 2 ) ;
default:
break;
}
}
}
void F_21 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_13 ( V_21 , struct V_1 , V_14 . V_21 ) ;
int V_22 ;
if ( F_17 ( V_2 ) == V_4 ) {
V_22 = V_2 -> V_24 -> V_31 ( V_2 ) ;
F_6 ( L_8 , V_2 , V_22 ) ;
switch ( V_22 ) {
case - V_27 :
F_20 ( V_32 ) ;
F_8 ( V_12 , & V_2 -> V_14 , 0 ) ;
break;
case - V_29 :
F_20 ( V_33 ) ;
F_8 ( V_12 , & V_2 -> V_14 , 2 ) ;
default:
break;
}
}
}
void F_22 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_13 ( V_21 , struct V_1 , V_34 ) ;
F_23 ( V_2 ) ;
}
void F_24 ( void )
{
F_25 ( V_12 ) ;
}
int F_26 ( void )
{
V_12 = F_27 ( L_9 ) ;
if ( ! V_12 )
return - V_29 ;
return 0 ;
}
