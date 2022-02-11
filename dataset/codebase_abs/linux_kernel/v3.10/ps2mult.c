static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( V_6 , V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
F_3 ( & V_6 -> V_9 , L_1 , V_4 -> V_7 ) ;
}
static int F_4 ( struct V_5 * V_5 , unsigned char V_10 )
{
struct V_5 * V_11 = V_5 -> V_12 ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
struct V_3 * V_4 = V_5 -> V_13 ;
bool V_14 ;
unsigned long V_15 ;
F_6 ( & V_2 -> V_16 , V_15 ) ;
if ( V_2 -> V_8 != V_4 )
F_1 ( V_2 , V_4 ) ;
V_14 = memchr ( V_17 , V_10 , sizeof( V_17 ) ) ;
F_3 ( & V_5 -> V_9 ,
L_2 , V_14 ? L_3 : L_4 , V_10 ) ;
if ( V_14 )
F_2 ( V_11 , V_18 ) ;
F_2 ( V_11 , V_10 ) ;
F_7 ( & V_2 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_12 ) ;
struct V_3 * V_4 = V_5 -> V_13 ;
unsigned long V_15 ;
F_6 ( & V_2 -> V_16 , V_15 ) ;
V_4 -> V_19 = true ;
F_7 ( & V_2 -> V_16 , V_15 ) ;
return 0 ;
}
static void F_9 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_12 ) ;
struct V_3 * V_4 = V_5 -> V_13 ;
unsigned long V_15 ;
F_6 ( & V_2 -> V_16 , V_15 ) ;
V_4 -> V_19 = false ;
F_7 ( & V_2 -> V_16 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_20 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_5 * V_5 ;
V_5 = F_11 ( sizeof( struct V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
F_12 ( V_5 -> V_23 , L_5 , sizeof( V_5 -> V_23 ) ) ;
snprintf ( V_5 -> V_24 , sizeof( V_5 -> V_24 ) ,
L_6 , V_6 -> V_24 , V_20 ) ;
V_5 -> V_25 . type = V_26 ;
V_5 -> V_27 = F_4 ;
V_5 -> V_28 = F_8 ;
V_5 -> V_29 = F_9 ;
V_5 -> V_12 = V_2 -> V_6 ;
V_5 -> V_13 = & V_2 -> V_30 [ V_20 ] ;
V_2 -> V_30 [ V_20 ] . V_5 = V_5 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
F_6 ( & V_2 -> V_16 , V_15 ) ;
F_2 ( V_2 -> V_6 , V_31 ) ;
F_2 ( V_2 -> V_6 , V_32 ) ;
F_1 ( V_2 , & V_2 -> V_30 [ V_33 ] ) ;
F_7 ( & V_2 -> V_16 , V_15 ) ;
}
static int F_14 ( struct V_5 * V_5 , struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int V_20 ;
int error ;
if ( ! V_5 -> V_27 )
return - V_36 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_22 ;
F_15 ( & V_2 -> V_16 ) ;
V_2 -> V_6 = V_5 ;
for ( V_20 = 0 ; V_20 < V_37 ; V_20 ++ ) {
V_2 -> V_30 [ V_20 ] . V_7 = V_17 [ V_20 ] ;
error = F_10 ( V_2 , V_20 ) ;
if ( error )
goto V_38;
}
V_2 -> V_39 = V_2 -> V_8 = & V_2 -> V_30 [ V_33 ] ;
F_16 ( V_5 , V_2 ) ;
error = F_17 ( V_5 , V_35 ) ;
if ( error )
goto V_38;
F_13 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < V_37 ; V_20 ++ ) {
struct V_5 * V_40 = V_2 -> V_30 [ V_20 ] . V_5 ;
F_18 ( & V_5 -> V_9 , L_7 , V_40 -> V_23 , V_5 -> V_24 ) ;
F_19 ( V_40 ) ;
}
return 0 ;
V_38:
while ( -- V_20 >= 0 )
F_20 ( V_2 -> V_30 [ V_20 ] . V_5 ) ;
F_20 ( V_2 ) ;
return error ;
}
static void F_21 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 ) ;
F_2 ( V_5 , V_31 ) ;
F_22 ( V_5 ) ;
F_20 ( V_2 ) ;
F_16 ( V_5 , NULL ) ;
}
static int F_23 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_5 * V_5 ,
unsigned char V_10 , unsigned int V_41 )
{
struct V_1 * V_2 = F_5 ( V_5 ) ;
struct V_3 * V_39 ;
unsigned long V_15 ;
F_3 ( & V_5 -> V_9 , L_8 , V_10 , V_41 ) ;
F_6 ( & V_2 -> V_16 , V_15 ) ;
if ( V_2 -> V_42 ) {
V_2 -> V_42 = false ;
V_39 = V_2 -> V_39 ;
if ( V_39 -> V_19 )
F_25 ( V_39 -> V_5 , V_10 , V_41 ) ;
goto V_43;
}
switch ( V_10 ) {
case V_18 :
F_3 ( & V_5 -> V_9 , L_9 ) ;
V_2 -> V_42 = true ;
break;
case V_44 :
F_3 ( & V_5 -> V_9 , L_10 ) ;
V_2 -> V_39 = V_2 -> V_8 ;
break;
case V_32 :
F_3 ( & V_5 -> V_9 , L_11 ) ;
break;
case V_31 :
F_3 ( & V_5 -> V_9 , L_12 ) ;
break;
case V_45 :
F_3 ( & V_5 -> V_9 , L_13 ) ;
V_2 -> V_39 = & V_2 -> V_30 [ V_33 ] ;
break;
case V_46 :
F_3 ( & V_5 -> V_9 , L_14 ) ;
V_2 -> V_39 = & V_2 -> V_30 [ V_47 ] ;
break;
default:
V_39 = V_2 -> V_39 ;
if ( V_39 -> V_19 )
F_25 ( V_39 -> V_5 , V_10 , V_41 ) ;
break;
}
V_43:
F_7 ( & V_2 -> V_16 , V_15 ) ;
return V_48 ;
}
