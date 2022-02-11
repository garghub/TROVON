static inline int F_1 ( int V_1 )
{
int V_2 ;
V_2 = ( ( V_1 - V_3 ) << 1 ) + 2 ;
return V_2 ;
}
static inline int F_2 ( int V_1 )
{
int V_2 ;
V_2 = ( ( V_1 - V_3 ) << 1 ) + 3 ;
return V_2 ;
}
static inline int F_3 ( int V_1 )
{
int V_2 ;
switch ( V_1 ) {
case V_3 :
case V_4 :
V_2 = ( ( V_1 - V_3 ) << 1 ) + 3 ;
break;
case V_5 :
default:
V_2 = ( ( V_1 - V_4 ) << 1 ) + 3 ;
break;
}
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = F_5 ( V_7 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
unsigned char V_13 ;
int V_2 ;
if ( V_8 > V_14 )
V_13 = V_14 ;
else
V_13 = V_8 ;
V_2 = F_6 ( V_10 -> V_15 , F_1 ( V_10 -> V_1 ) , V_13 ) ;
if ( V_2 < 0 )
goto V_16;
if ( ( V_10 -> V_17 == 0 ) && V_8 ) {
if ( V_10 -> V_18 ) {
V_2 = F_7 ( V_10 -> V_15 , F_3 ( V_10 -> V_1 ) ,
V_19 , V_10 -> V_18 ) ;
if ( V_2 < 0 )
goto V_16;
}
if ( V_10 -> V_20 ) {
V_2 = F_7 ( V_10 -> V_15 , V_21 ,
V_22 , V_10 -> V_20 ) ;
if ( V_2 < 0 )
goto V_16;
}
if ( V_8 == V_14 ) {
V_2 = F_7 ( V_10 -> V_15 , F_2 ( V_10 -> V_1 ) ,
V_23 , V_23 ) ;
}
} else {
if ( V_8 == V_14 ) {
V_2 = F_7 ( V_10 -> V_15 , F_2 ( V_10 -> V_1 ) ,
V_23 , V_23 ) ;
} else {
V_2 = F_7 ( V_10 -> V_15 , F_2 ( V_10 -> V_1 ) ,
V_23 , 0 ) ;
}
}
if ( V_2 < 0 )
goto V_16;
F_8 ( V_12 -> V_24 , L_1 , V_13 ) ;
V_10 -> V_17 = V_13 ;
return 0 ;
V_16:
F_8 ( V_12 -> V_24 , L_2
L_3 , V_13 , V_2 ) ;
return V_2 ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_8 = V_7 -> V_25 . V_8 ;
if ( V_7 -> V_25 . V_26 != V_27 )
V_8 = 0 ;
if ( V_7 -> V_25 . V_28 != V_27 )
V_8 = 0 ;
if ( V_7 -> V_25 . V_29 & V_30 )
V_8 = 0 ;
return F_4 ( V_7 , V_8 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_5 ( V_7 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_2 ;
V_2 = F_11 ( V_10 -> V_15 , F_1 ( V_10 -> V_1 ) ) ;
if ( V_2 < 0 )
goto V_16;
V_10 -> V_17 = V_2 ;
F_8 ( V_12 -> V_24 , L_4 , V_10 -> V_17 ) ;
return V_10 -> V_17 ;
V_16:
return - V_31 ;
}
static int F_12 ( struct V_32 * V_33 )
{
struct V_11 * V_12 = F_13 ( V_33 -> V_24 . V_34 ) ;
struct V_35 * V_36 = NULL ;
struct V_9 * V_10 ;
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_39 V_25 ;
unsigned char V_13 ;
char V_40 [ V_41 ] ;
int V_2 ;
V_38 = F_14 ( V_33 , V_42 , 0 ) ;
if ( V_38 == NULL ) {
F_15 ( & V_33 -> V_24 , L_5 ) ;
return - V_31 ;
}
V_36 = V_33 -> V_24 . V_43 ;
if ( V_36 == NULL ) {
F_15 ( & V_33 -> V_24 , L_6
L_7 ) ;
return - V_31 ;
}
V_10 = F_16 ( sizeof( struct V_9 ) , V_44 ) ;
if ( V_10 == NULL )
return - V_45 ;
strncpy ( V_40 , V_38 -> V_40 , V_41 ) ;
V_10 -> V_12 = V_12 ;
V_10 -> V_15 = ( V_12 -> V_46 == V_47 ) ? V_12 -> V_48 \
: V_12 -> V_49 ;
V_10 -> V_17 = V_14 ;
V_10 -> V_20 = V_36 -> V_20 ;
V_10 -> V_18 = V_36 -> V_18 ;
V_10 -> V_1 = V_36 -> V_50 ;
if ( V_10 -> V_1 < 0 ) {
F_15 ( & V_33 -> V_24 , L_8 ) ;
F_17 ( V_10 ) ;
return - V_31 ;
}
memset ( & V_25 , 0 , sizeof( struct V_39 ) ) ;
V_25 . type = V_51 ;
V_25 . V_52 = V_14 ;
V_7 = F_18 ( V_40 , & V_33 -> V_24 , V_10 ,
& V_53 , & V_25 ) ;
if ( F_19 ( V_7 ) ) {
F_15 ( & V_33 -> V_24 , L_9 ) ;
F_17 ( V_10 ) ;
return F_20 ( V_7 ) ;
}
V_7 -> V_25 . V_8 = V_14 ;
F_21 ( V_33 , V_7 ) ;
V_2 = F_11 ( V_10 -> V_15 , V_54 ) ;
if ( V_2 < 0 )
goto V_16;
if ( ( V_2 & V_55 ) == 0 ) {
V_13 = V_2 | V_55 ;
V_2 = F_6 ( V_10 -> V_15 , V_54 , V_13 ) ;
if ( V_2 < 0 )
goto V_16;
}
V_2 = F_11 ( V_10 -> V_15 , V_56 ) ;
if ( V_2 < 0 )
goto V_16;
if ( ( V_2 & V_57 ) == 0 ) {
V_13 = V_2 | V_57 ;
V_2 = F_6 ( V_10 -> V_15 , V_56 , V_13 ) ;
if ( V_2 < 0 )
goto V_16;
}
V_2 = F_10 ( V_7 ) ;
if ( V_2 < 0 )
goto V_16;
F_22 ( V_7 ) ;
return 0 ;
V_16:
F_23 ( V_7 ) ;
F_17 ( V_10 ) ;
return V_2 ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_6 * V_7 = F_25 ( V_33 ) ;
struct V_9 * V_10 = F_5 ( V_7 ) ;
F_23 ( V_7 ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_58 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_58 ) ;
}
