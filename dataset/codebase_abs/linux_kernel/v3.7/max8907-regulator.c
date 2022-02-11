static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_7 ;
struct V_3 * V_8 ;
int V_9 ;
if ( ! V_2 -> V_5 . V_6 -> V_7 )
return 0 ;
V_8 = F_2 ( V_4 , L_1 ) ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_5 , L_2 ) ;
return - V_10 ;
}
V_9 = F_4 ( V_2 -> V_5 . V_6 , V_8 ,
V_11 ,
F_5 ( V_11 ) ) ;
if ( V_9 < 0 ) {
F_3 ( & V_2 -> V_5 , L_3 ,
V_9 ) ;
return V_9 ;
}
return 0 ;
}
static inline struct V_12 * F_6 ( int V_13 )
{
return V_11 [ V_13 ] . V_14 ;
}
static inline struct V_3 * F_7 ( int V_13 )
{
return V_11 [ V_13 ] . V_7 ;
}
static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline struct V_12 * F_6 ( int V_13 )
{
return NULL ;
}
static inline struct V_3 * F_7 ( int V_13 )
{
return NULL ;
}
static T_1 int F_8 ( struct V_1 * V_2 )
{
struct V_15 * V_15 = F_9 ( V_2 -> V_5 . V_6 ) ;
struct V_16 * V_17 = F_10 ( V_15 -> V_5 ) ;
int V_9 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
int V_21 ;
struct V_22 V_23 = {} ;
struct V_12 * V_24 ;
const char * V_25 = NULL ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_19 = F_11 ( & V_2 -> V_5 , sizeof( * V_19 ) , V_26 ) ;
if ( ! V_19 ) {
F_3 ( & V_2 -> V_5 , L_4 ) ;
return - V_27 ;
}
F_12 ( V_2 , V_19 ) ;
memcpy ( V_19 -> V_28 , V_29 , sizeof( V_19 -> V_28 ) ) ;
F_13 ( V_15 -> V_30 , V_31 , & V_20 ) ;
if ( ( V_20 & V_32 ) ==
V_33 ) {
V_19 -> V_28 [ V_34 ] . V_35 = 637500 ;
V_19 -> V_28 [ V_34 ] . V_36 = 12500 ;
V_19 -> V_28 [ V_34 ] . V_37 =
( 1425000 - 637500 ) / 12500 + 1 ;
}
for ( V_21 = 0 ; V_21 < V_38 ; V_21 ++ ) {
V_23 . V_5 = V_2 -> V_5 . V_6 ;
if ( V_17 )
V_24 = V_17 -> V_14 [ V_21 ] ;
else
V_24 = F_6 ( V_21 ) ;
V_23 . V_14 = V_24 ;
V_23 . V_39 = V_19 ;
V_23 . V_40 = V_15 -> V_30 ;
V_23 . V_7 = F_7 ( V_21 ) ;
switch ( V_19 -> V_28 [ V_21 ] . V_41 ) {
case V_42 :
if ( V_24 && V_24 -> V_43 . V_44 )
V_25 = V_24 -> V_43 . V_44 ;
else
V_25 = V_19 -> V_28 [ V_21 ] . V_44 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_24 -> V_48 = V_25 ;
break;
}
if ( V_19 -> V_28 [ V_21 ] . V_49 == & V_50 ) {
F_13 ( V_23 . V_40 , V_19 -> V_28 [ V_21 ] . V_51 ,
& V_20 ) ;
if ( ( V_20 & V_52 ) !=
V_52 )
V_19 -> V_28 [ V_21 ] . V_49 = & V_53 ;
} else if ( V_19 -> V_28 [ V_21 ] . V_49 == & V_54 ) {
F_13 ( V_23 . V_40 , V_19 -> V_28 [ V_21 ] . V_51 ,
& V_20 ) ;
if ( ( V_20 & ( V_55 |
V_56 ) ) !=
V_56 )
V_19 -> V_28 [ V_21 ] . V_49 = & V_57 ;
}
V_19 -> V_58 [ V_21 ] = F_14 ( & V_19 -> V_28 [ V_21 ] , & V_23 ) ;
if ( F_15 ( V_19 -> V_58 [ V_21 ] ) ) {
F_3 ( & V_2 -> V_5 ,
L_5 ,
V_19 -> V_28 [ V_21 ] . V_44 ) ;
V_9 = F_16 ( V_19 -> V_58 [ V_21 ] ) ;
goto V_59;
}
}
return 0 ;
V_59:
while ( -- V_21 >= 0 )
F_17 ( V_19 -> V_58 [ V_21 ] ) ;
return V_9 ;
}
static T_2 int F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_19 ( V_2 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_38 ; V_21 ++ )
F_17 ( V_19 -> V_58 [ V_21 ] ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_60 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_60 ) ;
}
