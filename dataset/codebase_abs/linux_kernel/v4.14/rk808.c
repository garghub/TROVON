static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
}
return false ;
}
static void F_2 ( void )
{
int V_16 ;
struct V_17 * V_17 = F_3 ( V_18 ) ;
if ( ! V_17 ) {
F_4 ( & V_18 -> V_2 ,
L_1 ) ;
return;
}
V_16 = F_5 ( V_17 -> V_19 ,
V_20 ,
V_21 , V_21 ) ;
if ( V_16 )
F_6 ( & V_18 -> V_2 , L_2 ) ;
}
static void F_7 ( void )
{
int V_16 ;
struct V_17 * V_17 = F_3 ( V_18 ) ;
if ( ! V_17 ) {
F_4 ( & V_18 -> V_2 ,
L_3 ) ;
return;
}
V_16 = F_5 ( V_17 -> V_19 ,
V_13 ,
V_22 , V_22 ) ;
if ( V_16 )
F_6 ( & V_18 -> V_2 , L_2 ) ;
}
static void F_8 ( void )
{
int V_16 ;
struct V_17 * V_17 = F_3 ( V_18 ) ;
if ( ! V_17 ) {
F_4 ( & V_18 -> V_2 ,
L_4 ) ;
return;
}
V_16 = F_5 ( V_17 -> V_19 ,
V_23 ,
V_21 , V_21 ) ;
if ( V_16 )
F_6 ( & V_18 -> V_2 , L_2 ) ;
}
static int F_9 ( struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 = V_25 -> V_2 . V_30 ;
struct V_17 * V_17 ;
const struct V_31 * V_32 ;
const struct V_33 * V_34 ;
void (* F_10)( void );
int V_35 ;
int V_36 ;
int V_37 = 0 , V_38 , V_39 ;
int V_16 ;
int V_40 ;
V_17 = F_11 ( & V_25 -> V_2 , sizeof( * V_17 ) , V_41 ) ;
if ( ! V_17 )
return - V_42 ;
V_38 = F_12 ( V_25 , V_43 ) ;
if ( V_38 < 0 ) {
F_6 ( & V_25 -> V_2 , L_5 ,
V_43 ) ;
return V_38 ;
}
V_39 = F_12 ( V_25 , V_44 ) ;
if ( V_39 < 0 ) {
F_6 ( & V_25 -> V_2 , L_5 ,
V_44 ) ;
return V_39 ;
}
V_17 -> V_45 = ( ( V_38 << 8 ) | V_39 ) & V_46 ;
F_13 ( & V_25 -> V_2 , L_6 , ( unsigned int ) V_17 -> V_45 ) ;
switch ( V_17 -> V_45 ) {
case V_47 :
V_17 -> V_48 = & V_49 ;
V_17 -> V_50 = & V_51 ;
V_32 = V_52 ;
V_35 = F_14 ( V_52 ) ;
V_34 = V_53 ;
V_36 = F_14 ( V_53 ) ;
F_10 = F_2 ;
break;
case V_54 :
V_17 -> V_48 = & V_55 ;
V_17 -> V_50 = & V_56 ;
V_32 = V_57 ;
V_35 = F_14 ( V_57 ) ;
V_34 = V_58 ;
V_36 = F_14 ( V_58 ) ;
F_10 = F_7 ;
break;
case V_59 :
V_17 -> V_48 = & V_60 ;
V_17 -> V_50 = & V_61 ;
V_32 = V_62 ;
V_35 = F_14 ( V_62 ) ;
V_34 = V_63 ;
V_36 = F_14 ( V_63 ) ;
F_10 = F_8 ;
break;
default:
F_6 ( & V_25 -> V_2 , L_7 ,
V_17 -> V_45 ) ;
return - V_64 ;
}
V_17 -> V_65 = V_25 ;
F_15 ( V_25 , V_17 ) ;
V_17 -> V_19 = F_16 ( V_25 , V_17 -> V_48 ) ;
if ( F_17 ( V_17 -> V_19 ) ) {
F_6 ( & V_25 -> V_2 , L_8 ) ;
return F_18 ( V_17 -> V_19 ) ;
}
if ( ! V_25 -> V_66 ) {
F_6 ( & V_25 -> V_2 , L_9 ) ;
return - V_64 ;
}
V_16 = F_19 ( V_17 -> V_19 , V_25 -> V_66 ,
V_67 , - 1 ,
V_17 -> V_50 , & V_17 -> V_68 ) ;
if ( V_16 ) {
F_6 ( & V_25 -> V_2 , L_10 , V_16 ) ;
return V_16 ;
}
for ( V_40 = 0 ; V_40 < V_35 ; V_40 ++ ) {
V_16 = F_5 ( V_17 -> V_19 ,
V_32 [ V_40 ] . V_69 ,
V_32 [ V_40 ] . V_70 ,
V_32 [ V_40 ] . V_71 ) ;
if ( V_16 ) {
F_6 ( & V_25 -> V_2 ,
L_11 ,
V_32 [ V_40 ] . V_69 ) ;
return V_16 ;
}
}
V_16 = F_20 ( & V_25 -> V_2 , V_72 ,
V_34 , V_36 , NULL , 0 ,
F_21 ( V_17 -> V_68 ) ) ;
if ( V_16 ) {
F_6 ( & V_25 -> V_2 , L_12 , V_16 ) ;
goto V_73;
}
V_37 = F_22 ( V_29 ,
L_13 ) ;
if ( V_37 && ! V_74 ) {
V_18 = V_25 ;
V_74 = F_10 ;
}
return 0 ;
V_73:
F_23 ( V_25 -> V_66 , V_17 -> V_68 ) ;
return V_16 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_17 * V_17 = F_3 ( V_25 ) ;
F_23 ( V_25 -> V_66 , V_17 -> V_68 ) ;
V_74 = NULL ;
return 0 ;
}
