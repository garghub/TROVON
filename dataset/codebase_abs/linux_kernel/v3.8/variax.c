static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 [ V_5 ] = V_3 ;
F_2 ( & V_2 -> V_6 , V_2 -> V_4 ,
sizeof( V_7 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_8 , V_9 ) ;
F_5 ( & V_2 -> V_10 , V_11 ,
V_12 , ( unsigned long ) V_2 ) ;
}
static void V_12 ( unsigned long V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_14 * V_6 = & V_2 -> V_6 ;
if ( V_2 -> V_8 >= V_15 )
return;
V_2 -> V_8 = V_16 ;
F_5 ( & V_2 -> V_10 , V_11 ,
V_12 , ( unsigned long ) V_2 ) ;
F_6 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_8 , V_17 ) ;
F_5 ( & V_2 -> V_18 , V_19 ,
V_20 , ( unsigned long ) V_2 ) ;
}
static void V_20 ( unsigned long V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
F_4 ( V_2 -> V_8 ,
V_21 ) ;
F_1 ( V_2 , 1 ) ;
F_5 ( & V_2 -> V_18 , V_22 ,
V_23 , ( unsigned long ) V_2 ) ;
}
static void V_23 ( unsigned long V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
F_4 ( V_2 -> V_8 ,
V_24 ) ;
F_8 ( & V_2 -> V_25 ) ;
}
static void F_9 ( struct V_26 * V_27 )
{
struct V_1 * V_2 =
F_10 ( V_27 , struct V_1 , V_25 ) ;
F_4 ( V_2 -> V_8 , V_28 ) ;
F_11 ( & V_2 -> V_6 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
const unsigned char * V_29 = V_2 -> V_6 . V_30 ;
switch ( V_29 [ 0 ] ) {
case V_31 | V_32 :
break;
case V_33 | V_34 :
case V_33 | V_32 :
break;
case V_35 :
F_13 ( V_2 -> V_6 . V_36 , L_1 ) ;
break;
case V_37 :
if ( memcmp ( V_29 + 1 , V_38 + 1 ,
sizeof( V_38 ) - 1 ) == 0 ) {
F_7 ( V_2 ) ;
} else if ( memcmp ( V_29 + 1 , V_39 + 1 ,
sizeof( V_39 ) - 1 ) == 0 ) {
V_20 ( ( unsigned long ) V_2 ) ;
}
break;
case V_40 :
break;
default:
F_14 ( V_2 -> V_6 . V_36 ,
L_2 , V_29 [ 0 ] ) ;
}
}
static void F_15 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
if ( V_2 == NULL )
return;
F_17 ( & V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_10 ) ;
F_18 ( & V_2 -> V_18 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_20 ( V_2 -> V_4 ) ;
}
static int F_21 ( struct V_41 * V_42 ,
struct V_1 * V_2 )
{
int V_43 ;
F_22 ( & V_2 -> V_10 ) ;
F_22 ( & V_2 -> V_18 ) ;
F_23 ( & V_2 -> V_25 , F_9 ) ;
if ( ( V_42 == NULL ) || ( V_2 == NULL ) )
return - V_44 ;
V_2 -> V_4 = F_24 ( V_7 ,
sizeof( V_7 ) , V_45 ) ;
if ( V_2 -> V_4 == NULL ) {
F_25 ( & V_42 -> V_46 , L_3 ) ;
return - V_47 ;
}
V_43 = F_26 ( & V_2 -> V_6 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_27 ( & V_2 -> V_6 ) ;
if ( V_43 < 0 )
return V_43 ;
F_3 ( V_2 ) ;
return 0 ;
}
int F_28 ( struct V_41 * V_42 ,
struct V_1 * V_2 )
{
int V_43 = F_21 ( V_42 , V_2 ) ;
if ( V_43 < 0 )
F_15 ( V_42 ) ;
return V_43 ;
}
void F_29 ( struct V_41 * V_42 )
{
if ( V_42 == NULL )
return;
F_15 ( V_42 ) ;
}
