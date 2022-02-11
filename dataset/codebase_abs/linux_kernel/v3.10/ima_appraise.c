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
static int F_4 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_12 . type = V_13 ;
return F_5 ( V_9 , V_14 ,
( V_15 * ) & V_11 -> V_12 ,
sizeof( V_11 -> V_12 ) , 0 ) ;
}
enum V_16 F_6 ( struct V_10 * V_11 ,
int V_7 )
{
switch( V_7 ) {
case V_17 :
return V_11 -> V_18 ;
case V_19 :
return V_11 -> V_20 ;
case V_21 :
return V_11 -> V_22 ;
case V_23 :
default:
return V_11 -> V_24 ;
}
}
static void F_7 ( struct V_10 * V_11 ,
int V_7 , enum V_16 V_25 )
{
switch( V_7 ) {
case V_17 :
V_11 -> V_18 = V_25 ;
break;
case V_19 :
V_11 -> V_20 = V_25 ;
break;
case V_21 :
V_11 -> V_22 = V_25 ;
break;
case V_23 :
default:
V_11 -> V_24 = V_25 ;
break;
}
}
static void F_8 ( struct V_10 * V_11 , int V_7 )
{
switch( V_7 ) {
case V_17 :
V_11 -> V_26 |= ( V_27 | V_28 ) ;
break;
case V_19 :
V_11 -> V_26 |= ( V_29 | V_28 ) ;
break;
case V_21 :
V_11 -> V_26 |= ( V_30 | V_28 ) ;
break;
case V_23 :
default:
V_11 -> V_26 |= ( V_31 | V_28 ) ;
break;
}
}
int F_9 ( int V_7 , struct V_10 * V_11 ,
struct V_32 * V_32 , const unsigned char * V_33 )
{
struct V_9 * V_9 = V_32 -> V_34 ;
struct V_4 * V_4 = V_9 -> V_35 ;
struct V_36 * V_37 = NULL ;
enum V_16 V_25 = V_38 ;
const char * V_39 = L_3 ;
char * V_40 = L_4 ;
int V_41 ;
if ( ! V_2 )
return 0 ;
if ( ! V_4 -> V_42 -> V_43 )
return V_38 ;
V_41 = F_10 ( V_9 , V_14 , ( char * * ) & V_37 ,
0 , V_44 ) ;
if ( V_41 <= 0 ) {
if ( V_41 && V_41 != - V_45 )
goto V_46;
V_40 = L_5 ;
V_25 =
( V_4 -> V_47 == 0 ) ? V_48 : V_49 ;
goto V_46;
}
V_25 = F_11 ( V_9 , V_14 , V_37 , V_41 , V_11 ) ;
if ( ( V_25 != V_48 ) && ( V_25 != V_38 ) ) {
if ( ( V_25 == V_49 )
|| ( V_25 == V_50 ) )
V_40 = L_6 ;
else if ( V_25 == V_51 )
V_40 = L_7 ;
goto V_46;
}
switch ( V_37 -> type ) {
case V_13 :
if ( V_11 -> V_26 & V_52 ) {
V_40 = L_8 ;
V_25 = V_51 ;
break;
}
V_41 = memcmp ( V_37 -> V_53 , V_11 -> V_12 . V_53 ,
V_54 ) ;
if ( V_41 ) {
V_40 = L_9 ;
V_25 = V_51 ;
break;
}
V_25 = V_48 ;
break;
case V_55 :
V_11 -> V_26 |= V_56 ;
V_41 = F_12 ( V_57 ,
V_37 -> V_53 , V_41 - 1 ,
V_11 -> V_12 . V_53 ,
V_54 ) ;
if ( V_41 == - V_58 ) {
V_25 = V_38 ;
} else if ( V_41 ) {
V_40 = L_10 ;
V_25 = V_51 ;
} else {
V_25 = V_48 ;
}
break;
default:
V_25 = V_38 ;
V_40 = L_11 ;
break;
}
V_46:
if ( V_25 != V_48 ) {
if ( ( V_2 & V_3 ) &&
( ! V_37 ||
V_37 -> type != V_55 ) ) {
if ( ! F_4 ( V_9 , V_11 ) )
V_25 = V_48 ;
}
F_13 ( V_59 , V_4 , V_33 ,
V_39 , V_40 , V_41 , 0 ) ;
} else {
F_8 ( V_11 , V_7 ) ;
}
F_7 ( V_11 , V_7 , V_25 ) ;
F_14 ( V_37 ) ;
return V_25 ;
}
void F_15 ( struct V_10 * V_11 , struct V_32 * V_32 )
{
struct V_9 * V_9 = V_32 -> V_34 ;
int V_41 = 0 ;
if ( V_11 -> V_26 & V_56 )
return;
V_41 = F_16 ( V_11 , V_32 ) ;
if ( V_41 < 0 )
return;
F_4 ( V_9 , V_11 ) ;
}
void F_17 ( struct V_9 * V_9 )
{
struct V_4 * V_4 = V_9 -> V_35 ;
struct V_10 * V_11 ;
int V_60 , V_41 ;
if ( ! V_61 || ! V_2 || ! F_18 ( V_4 -> V_62 )
|| ! V_4 -> V_42 -> V_63 )
return;
V_60 = F_2 ( V_4 , V_64 , V_65 ) ;
V_11 = F_19 ( V_4 ) ;
if ( V_11 ) {
V_11 -> V_26 &= ~ ( V_8 | V_28 |
V_66 | V_67 |
V_68 ) ;
if ( V_60 )
V_11 -> V_26 |= V_8 ;
}
if ( ! V_60 )
V_41 = V_4 -> V_42 -> V_63 ( V_9 , V_14 ) ;
return;
}
static int F_20 ( struct V_9 * V_9 , const char * V_69 ,
const void * V_37 , T_2 V_70 )
{
if ( strcmp ( V_69 , V_14 ) == 0 ) {
if ( ! F_21 ( V_71 ) )
return - V_72 ;
return 1 ;
}
return 0 ;
}
static void F_22 ( struct V_4 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_61 || ! V_2 || ! F_18 ( V_4 -> V_62 ) )
return;
V_11 = F_19 ( V_4 ) ;
if ( ! V_11 )
return;
V_11 -> V_26 &= ~ V_73 ;
return;
}
int F_23 ( struct V_9 * V_9 , const char * V_69 ,
const void * V_37 , T_2 V_70 )
{
int V_74 ;
V_74 = F_20 ( V_9 , V_69 , V_37 ,
V_70 ) ;
if ( V_74 == 1 ) {
F_22 ( V_9 -> V_35 ) ;
V_74 = 0 ;
}
return V_74 ;
}
int F_24 ( struct V_9 * V_9 , const char * V_69 )
{
int V_74 ;
V_74 = F_20 ( V_9 , V_69 , NULL , 0 ) ;
if ( V_74 == 1 ) {
F_22 ( V_9 -> V_35 ) ;
V_74 = 0 ;
}
return V_74 ;
}
