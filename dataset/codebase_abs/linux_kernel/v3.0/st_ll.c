static void F_1 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
F_2 ( L_1 , V_4 , V_3 ) ;
F_3 ( V_2 , & V_3 , 1 ) ;
return;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( L_2 , V_4 ) ;
if ( V_2 -> V_5 != V_6 )
F_5 ( L_3
L_4 , V_2 -> V_5 ) ;
F_1 ( V_2 , V_7 ) ;
V_2 -> V_5 = V_8 ;
}
static void F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_5 ) {
case V_8 :
F_1 ( V_2 , V_9 ) ;
break;
case V_10 :
F_5 ( L_5 ) ;
break;
case V_6 :
F_5 ( L_6 ) ;
break;
case V_11 :
F_5 ( L_7 ) ;
break;
}
V_2 -> V_5 = V_6 ;
}
void F_7 ( struct V_1 * V_12 )
{
V_12 -> V_5 = V_6 ;
}
void F_8 ( struct V_1 * V_12 )
{
V_12 -> V_5 = V_13 ;
}
void F_9 ( struct V_1 * V_12 )
{
if ( F_10 ( V_12 -> V_5 != V_6 ) ) {
F_1 ( V_12 , V_14 ) ;
V_12 -> V_5 = V_10 ;
} else {
F_5 ( L_8 ) ;
}
}
unsigned long F_11 ( struct V_1 * V_12 )
{
F_2 ( L_9 , V_12 -> V_5 ) ;
return V_12 -> V_5 ;
}
unsigned long F_12 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
switch ( V_3 ) {
case V_15 :
F_2 ( L_10 ) ;
F_4 ( V_2 ) ;
break;
case V_7 :
F_5 ( L_11 ) ;
break;
case V_14 :
F_2 ( L_12 ) ;
F_6 ( V_2 ) ;
break;
case V_9 :
F_2 ( L_13 ) ;
V_2 -> V_5 = V_6 ;
break;
default:
F_5 ( L_14 ) ;
return - V_16 ;
}
return 0 ;
}
long F_13 ( struct V_1 * V_12 )
{
V_12 -> V_5 = V_13 ;
return 0 ;
}
long F_14 ( struct V_1 * V_12 )
{
return 0 ;
}
