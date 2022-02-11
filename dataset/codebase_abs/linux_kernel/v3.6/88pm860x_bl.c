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
static int F_4 ( struct V_6 * V_7 , int V_1 ,
int V_8 )
{
int V_2 = - V_9 ;
switch ( V_1 ) {
case V_3 :
V_2 = V_8 ? F_5 ( V_7 , V_10 ) :
F_6 ( V_7 , V_10 ) ;
break;
case V_4 :
V_2 = V_8 ? F_5 ( V_7 , V_11 ) :
F_6 ( V_7 , V_11 ) ;
break;
case V_5 :
V_2 = V_8 ? F_5 ( V_7 , V_12 ) :
F_6 ( V_7 , V_12 ) ;
break;
}
return V_2 ;
}
static int F_7 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = F_8 ( V_14 ) ;
struct V_6 * V_7 = V_17 -> V_7 ;
unsigned char V_18 ;
int V_2 ;
if ( V_15 > V_19 )
V_18 = V_19 ;
else
V_18 = V_15 ;
if ( V_15 )
F_4 ( V_7 , V_17 -> V_1 , 1 ) ;
V_2 = F_9 ( V_17 -> V_20 , F_1 ( V_17 -> V_1 ) , V_18 ) ;
if ( V_2 < 0 )
goto V_21;
if ( ( V_17 -> V_22 == 0 ) && V_15 ) {
if ( V_17 -> V_23 ) {
V_2 = F_10 ( V_17 -> V_20 , F_3 ( V_17 -> V_1 ) ,
V_24 , V_17 -> V_23 ) ;
if ( V_2 < 0 )
goto V_21;
}
if ( V_17 -> V_25 ) {
V_2 = F_10 ( V_17 -> V_20 , V_26 ,
V_27 , V_17 -> V_25 ) ;
if ( V_2 < 0 )
goto V_21;
}
if ( V_15 == V_19 ) {
V_2 = F_10 ( V_17 -> V_20 , F_2 ( V_17 -> V_1 ) ,
V_28 , V_28 ) ;
}
} else {
if ( V_15 == V_19 ) {
V_2 = F_10 ( V_17 -> V_20 , F_2 ( V_17 -> V_1 ) ,
V_28 , V_28 ) ;
} else {
V_2 = F_10 ( V_17 -> V_20 , F_2 ( V_17 -> V_1 ) ,
V_28 , 0 ) ;
}
}
if ( V_2 < 0 )
goto V_21;
if ( V_15 == 0 )
F_4 ( V_7 , V_17 -> V_1 , 0 ) ;
F_11 ( V_7 -> V_29 , L_1 , V_18 ) ;
V_17 -> V_22 = V_18 ;
return 0 ;
V_21:
F_11 ( V_7 -> V_29 , L_2
L_3 , V_18 , V_2 ) ;
return V_2 ;
}
static int F_12 ( struct V_13 * V_14 )
{
int V_15 = V_14 -> V_30 . V_15 ;
if ( V_14 -> V_30 . V_31 != V_32 )
V_15 = 0 ;
if ( V_14 -> V_30 . V_33 != V_32 )
V_15 = 0 ;
if ( V_14 -> V_30 . V_34 & V_35 )
V_15 = 0 ;
return F_7 ( V_14 , V_15 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_8 ( V_14 ) ;
struct V_6 * V_7 = V_17 -> V_7 ;
int V_2 ;
V_2 = F_14 ( V_17 -> V_20 , F_1 ( V_17 -> V_1 ) ) ;
if ( V_2 < 0 )
goto V_21;
V_17 -> V_22 = V_2 ;
F_11 ( V_7 -> V_29 , L_4 , V_17 -> V_22 ) ;
return V_17 -> V_22 ;
V_21:
return - V_9 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_16 ( V_37 -> V_29 . V_38 ) ;
struct V_39 * V_40 = NULL ;
struct V_16 * V_17 ;
struct V_13 * V_14 ;
struct V_41 * V_42 ;
struct V_43 V_30 ;
char V_44 [ V_45 ] ;
int V_2 ;
V_42 = F_17 ( V_37 , V_46 , 0 ) ;
if ( V_42 == NULL ) {
F_18 ( & V_37 -> V_29 , L_5 ) ;
return - V_9 ;
}
V_40 = V_37 -> V_29 . V_47 ;
if ( V_40 == NULL ) {
F_18 ( & V_37 -> V_29 , L_6
L_7 ) ;
return - V_9 ;
}
V_17 = F_19 ( & V_37 -> V_29 , sizeof( struct V_16 ) ,
V_48 ) ;
if ( V_17 == NULL )
return - V_49 ;
strncpy ( V_44 , V_42 -> V_44 , V_45 ) ;
V_17 -> V_7 = V_7 ;
V_17 -> V_20 = ( V_7 -> V_50 == V_51 ) ? V_7 -> V_52 \
: V_7 -> V_53 ;
V_17 -> V_22 = V_19 ;
V_17 -> V_25 = V_40 -> V_25 ;
V_17 -> V_23 = V_40 -> V_23 ;
V_17 -> V_1 = V_40 -> V_54 ;
if ( V_17 -> V_1 < 0 ) {
F_18 ( & V_37 -> V_29 , L_8 ) ;
F_20 ( V_17 ) ;
return - V_9 ;
}
memset ( & V_30 , 0 , sizeof( struct V_43 ) ) ;
V_30 . type = V_55 ;
V_30 . V_56 = V_19 ;
V_14 = F_21 ( V_44 , & V_37 -> V_29 , V_17 ,
& V_57 , & V_30 ) ;
if ( F_22 ( V_14 ) ) {
F_18 ( & V_37 -> V_29 , L_9 ) ;
return F_23 ( V_14 ) ;
}
V_14 -> V_30 . V_15 = V_19 ;
F_24 ( V_37 , V_14 ) ;
V_2 = F_13 ( V_14 ) ;
if ( V_2 < 0 )
goto V_21;
F_25 ( V_14 ) ;
return 0 ;
V_21:
F_26 ( V_14 ) ;
return V_2 ;
}
static int F_27 ( struct V_36 * V_37 )
{
struct V_13 * V_14 = F_28 ( V_37 ) ;
F_26 ( V_14 ) ;
return 0 ;
}
