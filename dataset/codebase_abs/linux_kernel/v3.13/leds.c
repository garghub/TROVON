static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_6 . V_2 ) ;
struct V_7 * V_8 = & V_5 -> V_9 ;
if ( ! V_5 -> V_10 || V_5 -> V_10 -> type == V_11 )
return ;
if ( ! V_8 -> V_12 )
return;
F_3 ( & V_5 -> V_13 ) ;
switch ( V_8 -> V_14 ) {
case V_15 :
F_4 ( V_5 , & V_5 -> V_16 -> V_17 , 0x01 ) ;
F_4 ( V_5 , & V_5 -> V_16 -> V_18 , 0x00 ) ;
break;
case V_19 :
V_3 = F_5 ( V_5 , & V_5 -> V_16 -> V_20 ) & ~ ( 1 << 4 ) ;
F_4 ( V_5 , & V_5 -> V_16 -> V_20 , V_3 ) ;
break;
case V_21 :
V_3 = F_5 ( V_5 , & V_5 -> V_16 -> V_20 ) & ~ ( 1 << 5 ) ;
F_4 ( V_5 , & V_5 -> V_16 -> V_20 , V_3 ) ;
break;
case V_22 :
default:
break;
}
F_6 ( & V_5 -> V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_23 . V_2 ) ;
struct V_7 * V_8 = & V_5 -> V_9 ;
if ( ! V_5 -> V_10 || V_5 -> V_10 -> type == V_11 )
return ;
if ( ! V_8 -> V_12 )
return;
F_3 ( & V_5 -> V_13 ) ;
switch ( V_8 -> V_14 ) {
case V_15 :
F_4 ( V_5 , & V_5 -> V_16 -> V_17 , 0x01 ) ;
F_4 ( V_5 , & V_5 -> V_16 -> V_18 , 0x01 ) ;
break;
case V_19 :
V_3 = F_5 ( V_5 , & V_5 -> V_16 -> V_20 ) | ( 1 << 4 ) ;
F_4 ( V_5 , & V_5 -> V_16 -> V_20 , V_3 ) ;
break;
case V_21 :
V_3 = F_5 ( V_5 , & V_5 -> V_16 -> V_20 ) | ( 1 << 5 ) ;
F_4 ( V_5 , & V_5 -> V_16 -> V_20 , V_3 ) ;
break;
case V_22 :
default:
break;
}
F_6 ( & V_5 -> V_13 ) ;
}
static void F_8 ( struct V_24 * V_25 ,
enum V_26 V_27 )
{
struct V_7 * V_8 = F_2 ( V_25 , struct V_7 ,
V_25 ) ;
struct V_28 * V_29 = V_8 -> V_12 ;
struct V_4 * V_5 ;
static bool V_30 ;
if ( ! V_29 )
return;
V_5 = V_29 -> V_5 ;
if ( V_8 -> V_31 ) {
if ( V_27 == V_32 ) {
F_9 ( V_29 , & V_5 -> V_6 , 0 ) ;
V_30 = true ;
} else if ( V_30 ) {
V_30 = false ;
F_10 ( & V_5 -> V_6 ) ;
F_9 ( V_29 , & V_5 -> V_23 , 0 ) ;
}
} else if ( V_30 ) {
if ( V_27 == V_33 ) {
F_9 ( V_29 , & V_5 -> V_23 , 0 ) ;
F_9 ( V_29 , & V_5 -> V_6 ,
V_34 / 20 ) ;
} else
F_9 ( V_29 , & V_5 -> V_6 , 0 ) ;
}
}
static int F_11 ( struct V_28 * V_12 ,
struct V_7 * V_8 , const char * V_35 ,
const char * V_36 , T_1 V_14 ,
bool V_31 )
{
int V_37 ;
struct V_4 * V_5 = V_12 -> V_5 ;
if ( V_8 -> V_12 )
return - V_38 ;
if ( ! V_36 )
return - V_39 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_31 = V_31 ;
strncpy ( V_8 -> V_35 , V_35 , sizeof( V_8 -> V_35 ) ) ;
V_8 -> V_25 . V_35 = V_8 -> V_35 ;
V_8 -> V_25 . V_36 = V_36 ;
V_8 -> V_25 . V_40 = F_8 ;
V_37 = F_12 ( & V_5 -> V_41 -> V_12 , & V_8 -> V_25 ) ;
if ( V_37 ) {
F_13 ( V_42 L_1 , V_35 ) ;
V_8 -> V_12 = NULL ;
return V_37 ;
}
return 0 ;
}
static void F_14 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = V_8 -> V_12 ;
struct V_4 * V_5 = V_29 -> V_5 ;
F_15 ( & V_8 -> V_25 ) ;
F_16 ( & V_5 -> V_23 ) ;
V_8 -> V_12 = NULL ;
}
void F_17 ( struct V_28 * V_12 , T_2 V_43 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
char V_35 [ V_44 + 1 ] ;
T_1 V_14 ;
int V_37 ;
F_13 ( V_42 L_2 , V_43 ) ;
switch ( V_43 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
V_14 = V_15 ;
break;
case V_51 :
V_14 = V_19 ;
break;
case V_52 :
V_14 = V_22 ;
break;
default:
V_14 = V_15 ;
}
F_18 ( & V_5 -> V_6 , F_1 ) ;
F_18 ( & V_5 -> V_23 , F_7 ) ;
snprintf ( V_35 , sizeof( V_35 ) ,
L_3 , F_19 ( V_12 -> V_53 ) ) ;
V_37 = F_11 ( V_12 , & V_5 -> V_54 , V_35 ,
F_20 ( V_12 ) , V_14 , true ) ;
if ( V_37 )
return;
snprintf ( V_35 , sizeof( V_35 ) ,
L_4 , F_19 ( V_12 -> V_53 ) ) ;
V_37 = F_11 ( V_12 , & V_5 -> V_9 , V_35 ,
F_21 ( V_12 ) , V_14 , false ) ;
if ( V_37 )
goto V_55;
snprintf ( V_35 , sizeof( V_35 ) ,
L_5 , F_19 ( V_12 -> V_53 ) ) ;
V_37 = F_11 ( V_12 , & V_5 -> V_56 , V_35 ,
F_22 ( V_12 ) , V_14 , false ) ;
if ( ! V_37 )
return;
F_14 ( & V_5 -> V_9 ) ;
V_55:
F_14 ( & V_5 -> V_54 ) ;
}
void F_23 ( struct V_28 * V_12 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
F_14 ( & V_5 -> V_54 ) ;
F_14 ( & V_5 -> V_56 ) ;
F_14 ( & V_5 -> V_9 ) ;
F_24 ( & V_5 -> V_23 ) ;
F_24 ( & V_5 -> V_6 ) ;
}
