void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , V_3 , V_4 ) ) {
F_3 ( V_5 L_1
L_2 ,
V_6 ,
F_4 ( & V_2 -> V_7 ) ) ;
F_5 ( & V_2 -> V_7 , V_8 ) ;
F_6 ( V_9 , & V_2 -> V_10 ) ;
return;
}
F_7 ( L_3 ,
V_2 , & V_2 -> V_11 , & V_2 -> V_12 ) ;
V_2 -> V_13 = 0 ;
F_8 ( 0 , & V_2 -> V_14 ) ;
F_9 ( V_9 , & V_2 -> V_15 , 0 ) ;
F_9 ( V_9 , & V_2 -> V_16 , 0 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
unsigned long rand ;
F_7 ( L_4 ,
V_2 , & V_2 -> V_11 , & V_2 -> V_12 ,
V_2 -> V_13 ) ;
F_8 ( V_17 , & V_2 -> V_18 ) ;
if ( V_2 -> V_13 == 0 ) {
V_2 -> V_13 = V_19 ;
F_9 ( V_9 , & V_2 -> V_20 , 0 ) ;
return;
}
F_11 ( & rand , sizeof( rand ) ) ;
F_7 ( L_5 ,
rand % V_2 -> V_13 , V_2 -> V_13 ,
V_2 , & V_2 -> V_11 , & V_2 -> V_12 ) ;
F_9 ( V_9 , & V_2 -> V_20 ,
rand % V_2 -> V_13 ) ;
V_2 -> V_13 = F_12 ( V_2 -> V_13 * 2 ,
V_21 ) ;
}
void F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 , struct V_1 , V_20 . V_23 ) ;
int V_24 ;
F_15 ( V_17 , & V_2 -> V_18 ) ;
if ( F_2 ( V_2 , V_25 , V_3 ) ) {
V_24 = V_2 -> V_26 -> V_27 ( V_2 ) ;
F_7 ( L_6 ,
V_2 , & V_2 -> V_11 , & V_2 -> V_12 , V_24 ) ;
if ( V_24 ) {
if ( F_2 ( V_2 , V_3 , V_25 ) )
F_10 ( V_2 ) ;
else
F_16 ( V_2 , L_7 ) ;
}
}
}
void F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 , struct V_1 , V_15 . V_23 ) ;
int V_24 ;
if ( F_18 ( V_2 ) == V_4 ) {
V_24 = F_19 ( V_2 ) ;
F_7 ( L_8 , V_2 , V_24 ) ;
switch ( V_24 ) {
case - V_28 :
F_20 ( V_29 ) ;
F_9 ( V_9 , & V_2 -> V_15 , 0 ) ;
break;
case - V_30 :
F_20 ( V_31 ) ;
F_9 ( V_9 , & V_2 -> V_15 , 2 ) ;
default:
break;
}
}
}
void F_21 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 , struct V_1 , V_16 . V_23 ) ;
int V_24 ;
if ( F_18 ( V_2 ) == V_4 ) {
V_24 = V_2 -> V_26 -> V_32 ( V_2 ) ;
F_7 ( L_8 , V_2 , V_24 ) ;
switch ( V_24 ) {
case - V_28 :
F_20 ( V_33 ) ;
F_9 ( V_9 , & V_2 -> V_16 , 0 ) ;
break;
case - V_30 :
F_20 ( V_34 ) ;
F_9 ( V_9 , & V_2 -> V_16 , 2 ) ;
default:
break;
}
}
}
void F_22 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 , struct V_1 , V_10 ) ;
F_23 ( V_2 ) ;
}
void F_24 ( void )
{
F_25 ( V_9 ) ;
}
int F_26 ( void )
{
V_9 = F_27 ( L_9 ) ;
if ( ! V_9 )
return - V_30 ;
return 0 ;
}
