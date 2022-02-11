static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 , F_3 ( 0 , 0 , 0 ) ,
V_4 -> V_6 ) ;
F_2 ( V_2 -> V_5 , F_3 ( 0 , 0 , 1 ) ,
V_4 -> V_7 ) ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_6 = V_8 ;
F_1 ( V_2 , V_4 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_6 = V_9 ;
F_1 ( V_2 , V_4 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {} ;
V_4 . V_6 = F_7 ( V_2 -> V_5 , F_3 ( 0 , 0 , 0 ) ) ;
V_4 . V_7 = F_7 ( V_2 -> V_5 , F_3 ( 0 , 0 , 1 ) ) ;
F_8 ( & V_2 -> V_10 -> V_11 , L_1 ,
V_12 , V_4 . V_6 ) ;
switch ( V_4 . V_6 ) {
case V_13 :
{
V_2 -> V_14 = true ;
V_2 -> V_15 = V_4 . V_7 ;
F_8 ( & V_2 -> V_10 -> V_11 , L_2 , V_2 -> V_15 ) ;
break;
}
case V_16 :
V_2 -> V_14 = true ;
V_2 -> V_17 = V_4 . V_7 ;
F_8 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_2 -> V_15 , ( ( V_4 . V_7 == V_18 ) ? L_4 : L_5 ) ,
V_2 -> V_19 ) ;
break;
case V_8 :
V_2 -> V_14 = true ;
break;
case V_9 :
V_2 -> V_20 = true ;
break;
default:
F_9 ( & V_2 -> V_10 -> V_11 , L_6 ,
V_4 . V_6 ) ;
break;
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_21 = V_22 ;
int V_23 = 10 ;
V_2 -> V_14 = false ;
V_2 -> V_20 = false ;
F_1 ( V_2 , V_4 ) ;
while ( ! V_2 -> V_14 ) {
if ( V_2 -> V_20 )
return - V_24 ;
F_11 ( V_23 ) ;
if ( V_2 -> V_14 )
break;
V_21 -= V_23 ;
if ( ! V_21 ) {
F_9 ( & V_2 -> V_10 -> V_11 , L_7 ,
( V_4 -> V_6 & 0xFF ) , V_2 -> V_15 ) ;
return - V_25 ;
}
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_26 * V_10 = V_2 -> V_10 ;
struct V_3 V_4 = {} ;
V_4 . V_6 = V_13 ;
if ( F_10 ( V_2 , & V_4 ) ) {
F_9 ( & V_10 -> V_11 , L_8 ) ;
return - V_25 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_26 * V_10 = V_2 -> V_10 ;
struct V_3 V_4 = {} ;
V_4 . V_6 = V_27 ;
V_4 . V_7 = V_2 -> V_28 ;
if ( F_10 ( V_2 , & V_4 ) ) {
F_9 ( & V_10 -> V_11 , L_9 ) ;
return - V_25 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_26 * V_10 = V_2 -> V_10 ;
struct V_3 V_4 = {} ;
V_4 . V_6 = V_16 ;
V_4 . V_7 = V_2 -> V_19 ;
if ( F_10 ( V_2 , & V_4 ) ) {
F_9 ( & V_10 -> V_11 , L_10 ) ;
return - V_25 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_26 * V_10 = V_2 -> V_10 ;
struct V_3 V_4 = {} ;
V_4 . V_6 = V_29 ;
V_4 . V_7 = V_2 -> V_30 ;
if ( F_10 ( V_2 , & V_4 ) ) {
F_9 ( & V_10 -> V_11 , L_10 ) ;
return - V_25 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_26 * V_10 = V_2 -> V_10 ;
struct V_3 V_4 = {} ;
V_4 . V_6 = V_31 ;
if ( F_10 ( V_2 , & V_4 ) ) {
F_9 ( & V_10 -> V_11 , L_11 ) ;
return - V_25 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_26 * V_10 = V_2 -> V_10 ;
struct V_3 V_4 = {} ;
V_4 . V_6 = V_32 ;
if ( F_10 ( V_2 , & V_4 ) ) {
F_9 ( & V_10 -> V_11 , L_12 ) ;
return - V_25 ;
}
return 0 ;
}
