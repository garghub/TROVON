static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
int V_8 ;
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_10 [ 0 ] = ( V_3 << V_5 -> V_11 ) |
V_12 | V_13 |
V_14 | V_15 | V_16 ;
V_8 = F_4 ( V_5 -> V_17 , & V_5 -> V_18 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 , L_1 , V_8 ) ;
F_6 ( & V_5 -> V_9 ) ;
return V_8 ;
}
V_6 = V_5 -> V_19 [ 0 ] ;
V_7 = V_5 -> V_19 [ 1 ] ;
F_6 ( & V_5 -> V_9 ) ;
if ( ( V_6 & 0xc0 ) || ( V_7 & 0x3f ) )
return - V_20 ;
return ( V_6 << 2 ) | ( V_7 >> 6 ) ;
}
int F_7 ( int V_3 )
{
return F_1 ( & V_21 -> V_17 -> V_2 , V_3 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
return sprintf ( V_24 , L_2 , F_9 ( V_2 ) -> V_25 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 = F_11 ( V_23 ) -> V_26 ;
int V_27 ;
V_27 = F_1 ( V_2 , V_3 ) ;
if ( V_27 < 0 )
return V_27 ;
return sprintf ( V_24 , L_3 , V_27 * V_5 -> V_28 ) ;
}
static int T_3 F_12 ( struct V_4 * V_5 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
V_30 = & V_5 -> V_18 ;
V_32 = & V_5 -> V_33 [ 0 ] ;
F_13 ( V_30 ) ;
V_32 -> V_10 = & V_5 -> V_10 [ 0 ] ;
V_32 -> V_34 = V_35 ;
F_14 ( V_32 , V_30 ) ;
V_32 ++ ;
V_32 -> V_19 = & V_5 -> V_19 [ 0 ] ;
V_32 -> V_34 = V_36 ;
F_14 ( V_32 , V_30 ) ;
return 0 ;
}
static int T_3 F_15 ( struct V_37 * V_17 )
{
enum V_38 V_39 = F_16 ( V_17 ) -> V_40 ;
struct V_4 * V_5 ;
int V_8 ;
V_17 -> V_41 = 8 ;
V_17 -> V_42 = V_43 ;
V_8 = F_17 ( V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_18 ( & V_17 -> V_2 , sizeof( struct V_4 ) , V_44 ) ;
if ( V_5 == NULL ) {
F_5 ( & V_17 -> V_2 , L_4 ) ;
return - V_45 ;
}
switch ( V_39 ) {
case V_46 :
V_5 -> V_28 = 8 ;
V_5 -> V_11 = V_47 ;
break;
case V_48 :
V_5 -> V_28 = 8 ;
V_5 -> V_11 = V_49 ;
break;
case V_50 :
V_5 -> V_28 = 16 ;
V_5 -> V_11 = V_47 ;
break;
case V_51 :
V_5 -> V_28 = 16 ;
V_5 -> V_11 = V_49 ;
break;
}
V_8 = F_12 ( V_5 ) ;
if ( V_8 )
return V_8 ;
F_19 ( & V_5 -> V_9 ) ;
V_5 -> V_17 = V_17 ;
F_20 ( V_17 , V_5 ) ;
V_8 = F_21 ( & V_17 -> V_2 . V_52 , & V_53 ) ;
if ( V_8 ) {
F_5 ( & V_17 -> V_2 , L_5 ) ;
return V_8 ;
}
if ( V_39 == V_46 || V_39 == V_50 ) {
V_8 = F_21 ( & V_17 -> V_2 . V_52 , & V_54 ) ;
if ( V_8 ) {
F_5 ( & V_17 -> V_2 ,
L_6 ) ;
goto V_55;
}
}
V_5 -> V_56 = F_22 ( & V_17 -> V_2 ) ;
if ( F_23 ( V_5 -> V_56 ) ) {
F_5 ( & V_17 -> V_2 , L_7 ) ;
V_8 = F_24 ( V_5 -> V_56 ) ;
goto V_55;
}
#ifdef F_25
V_21 = V_5 ;
#endif
return 0 ;
V_55:
F_26 ( & V_17 -> V_2 . V_52 , & V_54 ) ;
F_26 ( & V_17 -> V_2 . V_52 , & V_53 ) ;
return V_8 ;
}
static int T_4 F_27 ( struct V_37 * V_17 )
{
struct V_4 * V_5 = F_28 ( V_17 ) ;
F_29 ( V_5 -> V_56 ) ;
F_26 ( & V_17 -> V_2 . V_52 , & V_54 ) ;
F_26 ( & V_17 -> V_2 . V_52 , & V_53 ) ;
F_30 ( & V_5 -> V_9 ) ;
return 0 ;
}
