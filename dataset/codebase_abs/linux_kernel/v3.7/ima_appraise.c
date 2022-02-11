static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 0 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_2 = V_3 ;
return 1 ;
}
int F_2 ( struct V_4 * V_4 , int V_5 , enum V_6 V_7 )
{
if ( ! V_2 )
return 0 ;
return F_3 ( V_4 , V_7 , V_5 , V_8 ) ;
}
static void F_4 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_12 . type = V_13 ;
F_5 ( V_9 , V_14 , ( V_15 * ) & V_11 -> V_12 ,
sizeof V_11 -> V_12 , 0 ) ;
}
int F_6 ( struct V_10 * V_11 ,
struct V_16 * V_16 , const unsigned char * V_17 )
{
struct V_9 * V_9 = V_16 -> V_18 ;
struct V_4 * V_4 = V_9 -> V_19 ;
struct V_20 * V_21 = NULL ;
enum V_22 V_23 = V_24 ;
const char * V_25 = L_3 ;
char * V_26 = L_4 ;
int V_27 ;
if ( ! V_2 )
return 0 ;
if ( ! V_4 -> V_28 -> V_29 )
return V_24 ;
if ( V_11 -> V_30 & V_31 )
return V_11 -> V_32 ;
V_27 = F_7 ( V_9 , V_14 , ( char * * ) & V_21 ,
0 , V_33 ) ;
if ( V_27 <= 0 ) {
if ( V_27 && V_27 != - V_34 )
goto V_35;
V_26 = L_5 ;
V_23 =
( V_4 -> V_36 == 0 ) ? V_37 : V_38 ;
goto V_35;
}
V_23 = F_8 ( V_9 , V_14 , V_21 , V_27 , V_11 ) ;
if ( ( V_23 != V_37 ) && ( V_23 != V_24 ) ) {
if ( ( V_23 == V_38 )
|| ( V_23 == V_39 ) )
V_26 = L_6 ;
else if ( V_23 == V_40 )
V_26 = L_7 ;
goto V_35;
}
switch ( V_21 -> type ) {
case V_13 :
V_27 = memcmp ( V_21 -> V_41 , V_11 -> V_12 . V_41 ,
V_42 ) ;
if ( V_27 ) {
V_26 = L_8 ;
V_23 = V_40 ;
F_9 ( L_9 , V_43 ,
V_21 , sizeof( * V_21 ) ) ;
F_9 ( L_10 , V_43 ,
( V_15 * ) & V_11 -> V_12 ,
sizeof V_11 -> V_12 ) ;
break;
}
V_23 = V_37 ;
break;
case V_44 :
V_11 -> V_30 |= V_45 ;
V_27 = F_10 ( V_46 ,
V_21 -> V_41 , V_27 - 1 ,
V_11 -> V_12 . V_41 ,
V_42 ) ;
if ( V_27 == - V_47 ) {
V_23 = V_24 ;
} else if ( V_27 ) {
V_26 = L_11 ;
V_23 = V_40 ;
} else {
V_23 = V_37 ;
}
break;
default:
V_23 = V_24 ;
V_26 = L_12 ;
break;
}
V_35:
if ( V_23 != V_37 ) {
if ( ( V_2 & V_3 ) &&
( ! V_21 ||
V_21 -> type != V_44 ) ) {
F_4 ( V_9 , V_11 ) ;
V_23 = V_37 ;
}
F_11 ( V_48 , V_4 , V_17 ,
V_25 , V_26 , V_27 , 0 ) ;
} else {
V_11 -> V_30 |= V_31 ;
}
V_11 -> V_32 = V_23 ;
F_12 ( V_21 ) ;
return V_23 ;
}
void F_13 ( struct V_10 * V_11 , struct V_16 * V_16 )
{
struct V_9 * V_9 = V_16 -> V_18 ;
int V_27 = 0 ;
if ( V_11 -> V_30 & V_45 )
return;
V_27 = F_14 ( V_11 , V_16 ) ;
if ( V_27 < 0 )
return;
F_4 ( V_9 , V_11 ) ;
}
void F_15 ( struct V_9 * V_9 )
{
struct V_4 * V_4 = V_9 -> V_19 ;
struct V_10 * V_11 ;
int V_49 , V_27 ;
if ( ! V_50 || ! V_2 || ! F_16 ( V_4 -> V_51 )
|| ! V_4 -> V_28 -> V_52 )
return;
V_49 = F_2 ( V_4 , V_53 , V_54 ) ;
V_11 = F_17 ( V_4 ) ;
if ( V_11 ) {
if ( V_49 )
V_11 -> V_30 |= V_8 ;
else
V_11 -> V_30 &= ~ ( V_8 | V_31 ) ;
}
if ( ! V_49 )
V_27 = V_4 -> V_28 -> V_52 ( V_9 , V_14 ) ;
return;
}
static int F_18 ( struct V_9 * V_9 , const char * V_55 ,
const void * V_21 , T_2 V_56 )
{
if ( strcmp ( V_55 , V_14 ) == 0 ) {
if ( ! F_19 ( V_57 ) )
return - V_58 ;
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_4 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_50 || ! V_2 || ! F_16 ( V_4 -> V_51 ) )
return;
V_11 = F_17 ( V_4 ) ;
if ( ! V_11 )
return;
V_11 -> V_30 &= ~ V_59 ;
return;
}
int F_21 ( struct V_9 * V_9 , const char * V_55 ,
const void * V_21 , T_2 V_56 )
{
int V_60 ;
V_60 = F_18 ( V_9 , V_55 , V_21 ,
V_56 ) ;
if ( V_60 == 1 ) {
F_20 ( V_9 -> V_19 ) ;
V_60 = 0 ;
}
return V_60 ;
}
int F_22 ( struct V_9 * V_9 , const char * V_55 )
{
int V_60 ;
V_60 = F_18 ( V_9 , V_55 , NULL , 0 ) ;
if ( V_60 == 1 ) {
F_20 ( V_9 -> V_19 ) ;
V_60 = 0 ;
}
return V_60 ;
}
