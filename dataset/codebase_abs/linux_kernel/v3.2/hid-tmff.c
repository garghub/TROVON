static inline int F_1 ( unsigned int V_1 , int V_2 , int V_3 )
{
int V_4 ;
V_4 = ( V_1 * ( V_3 - V_2 ) / 0xffff ) + V_2 ;
if ( V_4 < V_2 )
return V_2 ;
if ( V_4 > V_3 )
return V_3 ;
return V_4 ;
}
static inline int F_2 ( int V_1 , int V_2 , int V_3 )
{
int V_4 ;
V_4 = ( ( ( V_1 + 0x80 ) * ( V_3 - V_2 ) ) / 0xff ) + V_2 ;
if ( V_4 < V_2 )
return V_2 ;
if ( V_4 > V_3 )
return V_3 ;
return V_4 ;
}
static int F_3 ( struct V_5 * V_6 , void * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_12 * V_13 = V_7 ;
struct V_14 * V_15 = V_13 -> V_15 ;
int V_16 , V_17 ;
int V_18 , V_19 ;
switch ( V_9 -> type ) {
case V_20 :
V_16 = F_2 ( V_9 -> V_21 . V_22 . V_23 ,
V_15 -> V_24 ,
V_15 -> V_25 ) ;
V_17 = F_2 ( V_9 -> V_21 . V_22 . V_26 ,
V_15 -> V_24 ,
V_15 -> V_25 ) ;
F_5 ( L_1 , V_16 , V_17 ) ;
V_15 -> V_27 [ 0 ] = V_16 ;
V_15 -> V_27 [ 1 ] = V_17 ;
F_6 ( V_11 , V_13 -> V_28 , V_29 ) ;
break;
case V_30 :
V_18 = F_1 ( V_9 -> V_21 . V_31 . V_32 ,
V_15 -> V_24 ,
V_15 -> V_25 ) ;
V_19 = F_1 ( V_9 -> V_21 . V_31 . V_33 ,
V_15 -> V_24 ,
V_15 -> V_25 ) ;
F_5 ( L_2 , V_18 , V_19 ) ;
V_15 -> V_27 [ 0 ] = V_18 ;
V_15 -> V_27 [ 1 ] = V_19 ;
F_6 ( V_11 , V_13 -> V_28 , V_29 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_10 * V_11 , const signed short * V_34 )
{
struct V_12 * V_13 ;
struct V_35 * V_28 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = F_8 ( V_11 -> V_40 . V_41 ,
struct V_38 , V_42 ) ;
struct V_5 * V_5 = V_39 -> V_43 ;
int error ;
int V_44 ;
V_13 = F_9 ( sizeof( struct V_12 ) , V_45 ) ;
if ( ! V_13 )
return - V_46 ;
V_37 = & V_11 -> V_47 [ V_48 ] . V_37 ;
F_10 (report, report_list, list) {
int V_49 ;
for ( V_49 = 0 ; V_49 < V_28 -> V_50 ; ++ V_49 ) {
struct V_14 * V_51 = V_28 -> V_51 [ V_49 ] ;
if ( V_51 -> V_52 <= 0 )
continue;
switch ( V_51 -> V_53 [ 0 ] . V_11 ) {
case V_54 :
if ( V_51 -> V_55 < 2 ) {
F_11 ( V_11 , L_3 ) ;
continue;
}
if ( V_51 -> V_25 ==
V_51 -> V_24 ) {
F_11 ( V_11 , L_4 ) ;
continue;
}
if ( V_13 -> V_28 && V_13 -> V_28 != V_28 ) {
F_11 ( V_11 , L_5 ) ;
continue;
}
if ( V_13 -> V_15 && V_13 -> V_15 != V_51 ) {
F_11 ( V_11 , L_6 ) ;
continue;
}
V_13 -> V_28 = V_28 ;
V_13 -> V_15 = V_51 ;
for ( V_44 = 0 ; V_34 [ V_44 ] >= 0 ; V_44 ++ )
F_12 ( V_34 [ V_44 ] , V_5 -> V_56 ) ;
break;
default:
F_11 ( V_11 , L_7 ,
V_51 -> V_53 [ 0 ] . V_11 ) ;
continue;
}
}
}
if ( ! V_13 -> V_28 ) {
F_13 ( V_11 , L_8 ) ;
error = - V_57 ;
goto V_58;
}
error = F_14 ( V_5 , V_13 , F_3 ) ;
if ( error )
goto V_58;
F_15 ( V_11 , L_9 ) ;
return 0 ;
V_58:
F_16 ( V_13 ) ;
return error ;
}
static inline int F_7 ( struct V_10 * V_11 , const signed short * V_34 )
{
return 0 ;
}
static int F_17 ( struct V_10 * V_59 , const struct V_60 * V_61 )
{
int V_4 ;
V_4 = F_18 ( V_59 ) ;
if ( V_4 ) {
F_13 ( V_59 , L_10 ) ;
goto V_62;
}
V_4 = F_19 ( V_59 , V_63 & ~ V_64 ) ;
if ( V_4 ) {
F_13 ( V_59 , L_11 ) ;
goto V_62;
}
F_7 ( V_59 , ( void * ) V_61 -> V_65 ) ;
return 0 ;
V_62:
return V_4 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_66 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_66 ) ;
}
