static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
F_2 ( V_9 , 50 ) ;
V_10 = F_3 ( V_9 , V_11 ,
F_4 ( V_4 ) * 512 ,
V_12 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_6 ( V_9 , 0 , V_14 ,
F_4 ( V_4 ) * 50 ,
F_4 ( V_4 ) * 512 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( const struct V_15 * V_16 )
{
V_17 = ( unsigned long ) V_16 -> V_18 ;
return 1 ;
}
static int F_8 ( struct V_5 * V_19 )
{
int V_10 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_19 -> V_23 ;
const struct V_24 * V_25 ;
int V_26 ;
V_23 -> V_27 . V_28 = true ;
F_9 ( V_21 ,
V_29 |
V_30 ,
V_31 ) ;
V_10 = F_10 ( V_23 , V_32 ,
F_11 ( V_32 ) ) ;
if ( V_10 ) {
F_5 ( V_23 -> V_13 , L_3 ) ;
return V_10 ;
}
switch ( F_12 ( V_17 ) ) {
case V_33 :
V_25 = V_34 ;
V_26 = F_11 ( V_34 ) ;
break;
case V_35 :
V_25 = V_36 ;
V_26 = F_11 ( V_36 ) ;
break;
default:
V_25 = V_37 ;
V_26 = F_11 ( V_37 ) ;
}
V_10 = F_13 ( & V_23 -> V_27 , V_25 , V_26 ) ;
if ( V_10 )
return V_10 ;
if ( V_17 & V_38 ) {
V_10 = F_14 ( V_21 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
F_15 ( & V_23 -> V_27 , L_4 ) ;
F_15 ( & V_23 -> V_27 , L_5 ) ;
return V_10 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_39 * V_40 = F_17 ( V_4 ,
V_41 ) ;
struct V_39 * V_42 = F_17 ( V_4 ,
V_43 ) ;
int V_10 ;
V_40 -> V_44 = V_40 -> V_45 = 48000 ;
V_42 -> V_44 = V_42 -> V_45 = 2 ;
F_18 ( V_4 , V_46 ) ;
V_10 = F_19 ( V_6 -> V_47 ,
V_48 |
V_49 |
V_50
) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_20 ( V_6 -> V_47 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_7 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_22 ( V_2 -> V_19 ,
V_41 , 48000 ) ;
}
static int F_23 ( struct V_51 * V_52 )
{
int V_53 = 0 ;
struct V_54 * V_55 ;
const char * V_56 = NULL ;
int V_57 ;
int V_58 ;
V_59 . V_13 = & V_52 -> V_13 ;
V_55 = V_59 . V_13 -> V_60 ;
V_58 = V_61 + 1 ;
for ( V_57 = 0 ; V_57 < F_11 ( V_62 ) ; V_57 ++ ) {
if ( ! strcmp ( V_62 [ V_57 ] . V_63 , L_8 ) ) {
V_58 = V_57 ;
break;
}
}
V_56 = F_24 ( V_55 -> V_16 ) ;
if ( V_56 != NULL ) {
snprintf ( V_64 , sizeof( V_64 ) ,
L_9 , L_10 , V_56 ) ;
V_62 [ V_58 ] . V_63 = V_64 ;
}
F_25 ( V_65 ) ;
V_53 = F_26 ( & V_52 -> V_13 , & V_59 ) ;
if ( V_53 ) {
F_5 ( & V_52 -> V_13 , L_11 ,
V_53 ) ;
return V_53 ;
}
F_27 ( V_52 , & V_59 ) ;
return V_53 ;
}
