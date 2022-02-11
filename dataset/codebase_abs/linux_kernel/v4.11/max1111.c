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
if ( ! V_21 || ! V_21 -> V_17 )
return - V_22 ;
return F_1 ( & V_21 -> V_17 -> V_2 , V_3 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
return sprintf ( V_25 , L_2 , F_9 ( V_2 ) -> V_26 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 = F_11 ( V_24 ) -> V_27 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_3 ) ;
if ( V_28 < 0 )
return V_28 ;
return sprintf ( V_25 , L_3 , V_28 * V_5 -> V_29 ) ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_31 = & V_5 -> V_18 ;
V_33 = & V_5 -> V_34 [ 0 ] ;
F_13 ( V_31 ) ;
V_33 -> V_10 = & V_5 -> V_10 [ 0 ] ;
V_33 -> V_35 = V_36 ;
F_14 ( V_33 , V_31 ) ;
V_33 ++ ;
V_33 -> V_19 = & V_5 -> V_19 [ 0 ] ;
V_33 -> V_35 = V_37 ;
F_14 ( V_33 , V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_38 * V_17 )
{
enum V_39 V_40 = F_16 ( V_17 ) -> V_41 ;
struct V_4 * V_5 ;
int V_8 ;
V_17 -> V_42 = 8 ;
V_17 -> V_43 = V_44 ;
V_8 = F_17 ( V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_18 ( & V_17 -> V_2 , sizeof( struct V_4 ) , V_45 ) ;
if ( V_5 == NULL )
return - V_46 ;
switch ( V_40 ) {
case V_47 :
V_5 -> V_29 = 8 ;
V_5 -> V_11 = V_48 ;
break;
case V_49 :
V_5 -> V_29 = 8 ;
V_5 -> V_11 = V_50 ;
break;
case V_51 :
V_5 -> V_29 = 16 ;
V_5 -> V_11 = V_48 ;
break;
case V_52 :
V_5 -> V_29 = 16 ;
V_5 -> V_11 = V_50 ;
break;
}
V_8 = F_12 ( V_5 ) ;
if ( V_8 )
return V_8 ;
F_19 ( & V_5 -> V_9 ) ;
V_5 -> V_17 = V_17 ;
F_20 ( V_17 , V_5 ) ;
V_8 = F_21 ( & V_17 -> V_2 . V_53 , & V_54 ) ;
if ( V_8 ) {
F_5 ( & V_17 -> V_2 , L_4 ) ;
return V_8 ;
}
if ( V_40 == V_47 || V_40 == V_51 ) {
V_8 = F_21 ( & V_17 -> V_2 . V_53 , & V_55 ) ;
if ( V_8 ) {
F_5 ( & V_17 -> V_2 ,
L_5 ) ;
goto V_56;
}
}
V_5 -> V_57 = F_22 ( & V_17 -> V_2 ) ;
if ( F_23 ( V_5 -> V_57 ) ) {
F_5 ( & V_17 -> V_2 , L_6 ) ;
V_8 = F_24 ( V_5 -> V_57 ) ;
goto V_56;
}
#ifdef F_25
V_21 = V_5 ;
#endif
return 0 ;
V_56:
F_26 ( & V_17 -> V_2 . V_53 , & V_55 ) ;
F_26 ( & V_17 -> V_2 . V_53 , & V_54 ) ;
return V_8 ;
}
static int F_27 ( struct V_38 * V_17 )
{
struct V_4 * V_5 = F_28 ( V_17 ) ;
#ifdef F_25
V_21 = NULL ;
#endif
F_29 ( V_5 -> V_57 ) ;
F_26 ( & V_17 -> V_2 . V_53 , & V_55 ) ;
F_26 ( & V_17 -> V_2 . V_53 , & V_54 ) ;
F_30 ( & V_5 -> V_9 ) ;
return 0 ;
}
