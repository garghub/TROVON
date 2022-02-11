static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
{
struct V_4 * V_5 ;
T_1 V_6 = * V_3 ;
F_2 ( & V_7 ) ;
if ( ! V_6 -- )
return V_8 ;
for ( V_5 = V_9 ; V_6 -- && V_5 ;
V_5 = V_5 -> V_10 )
;
return V_5 ;
}
static void * F_3 ( struct V_1 * V_2 , void * V_11 , T_1 * V_3 )
{
struct V_4 * V_5 = V_11 ;
( * V_3 ) ++ ;
return ( V_11 == V_8 ) ? V_9 : V_5 -> V_10 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_11 )
__releases( T_2 )
{
F_5 ( & V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_11 )
{
struct V_4 * V_12 = V_11 ;
if ( V_11 == V_8 ) {
F_7 ( V_2 , L_1
L_2 ) ;
return 0 ;
}
if ( ! V_12 -> V_13 )
return 0 ;
F_8 ( V_2 , L_3 ,
V_12 -> V_14 , V_12 -> V_15 , V_12 -> V_16 , V_12 -> V_17 , V_12 -> V_18 , V_12 -> V_19 ,
V_12 -> V_20 [ 0 ] , V_12 -> V_20 [ 1 ] , V_12 -> V_20 [ 2 ] , V_12 -> V_20 [ 3 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_11 )
{
struct V_4 * V_12 = V_11 ;
if ( V_11 == V_8 ) {
F_7 ( V_2 , L_4
L_5 ) ;
return 0 ;
}
if ( ! V_12 -> V_13 )
return 0 ;
F_8 ( V_2 , L_6 ,
V_12 -> V_14 ,
F_10 ( V_12 -> V_21 ) ,
V_12 -> V_21 == V_22 ?
( V_12 -> V_23 ? L_7 : L_8 ) :
( V_12 -> V_21 == V_24 ?
( V_12 -> V_23 ? L_9 : L_10 ) :
( L_11 ) ) ,
V_12 -> V_25 ? L_12 : L_13 ,
V_12 -> V_26 ? L_14 : L_15 ,
V_12 -> V_27 ,
V_12 -> V_28 ,
V_12 -> V_29 ) ;
switch ( V_12 -> V_13 ) {
case V_30 :
F_8 ( V_2 , L_16 , L_17 ) ;
break;
case V_31 :
F_8 ( V_2 , L_16 , L_18 ) ;
break;
case V_32 :
F_8 ( V_2 , L_16 , L_19 ) ;
break;
case V_33 :
F_8 ( V_2 , L_16 , L_20 ) ;
break;
default:
F_8 ( V_2 , L_16 , L_21 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_12 ( V_35 , & V_36 ) ;
}
static int F_13 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_12 ( V_35 , & V_37 ) ;
}
static int F_14 ( struct V_1 * V_2 , void * V_11 )
{
struct V_4 * V_5 = V_2 -> V_38 ;
if ( V_5 -> V_39 != V_40 )
return 0 ;
if ( ! V_5 -> V_13 ) {
F_7 ( V_2 , L_22 ) ;
return 0 ;
}
if ( V_5 -> V_41 ) {
int V_42 = V_5 -> V_41 ( V_5 ) ;
if ( V_42 == - V_43 ) {
F_7 ( V_2 , L_23 ) ;
return 0 ;
}
if ( V_42 ) {
F_7 ( V_2 , L_24 ) ;
return 0 ;
}
}
F_8 ( V_2 , V_44 ,
L_25 , V_5 -> V_45 . V_46 ) ;
F_8 ( V_2 , V_44 ,
L_26 , V_5 -> V_45 . V_47 ) ;
F_8 ( V_2 , V_44 ,
L_27 , V_5 -> V_45 . V_48 ) ;
F_8 ( V_2 , V_44 ,
L_28 , V_5 -> V_45 . V_49 ) ;
F_8 ( V_2 , V_44 ,
L_29 , V_5 -> V_45 . V_50 ) ;
F_8 ( V_2 , V_44 ,
L_30 , V_5 -> V_45 . V_51 ) ;
F_8 ( V_2 , V_44 ,
L_31 , V_5 -> V_45 . V_52 ) ;
F_8 ( V_2 , V_44 ,
L_32 , V_5 -> V_45 . V_53 ) ;
F_8 ( V_2 , V_44 ,
L_33 , V_5 -> V_45 . V_54 ) ;
F_8 ( V_2 , V_44 ,
L_34 , V_5 -> V_45 . V_55 ) ;
F_8 ( V_2 , V_44 ,
L_35 , V_5 -> V_45 . V_56 ) ;
F_8 ( V_2 , V_44 ,
L_36 , V_5 -> V_45 . V_57 ) ;
F_8 ( V_2 , V_44 ,
L_37 , V_5 -> V_45 . V_58 ) ;
F_8 ( V_2 , V_44 ,
L_38 , V_5 -> V_45 . V_59 ) ;
F_8 ( V_2 , V_44 ,
L_39 , V_5 -> V_45 . V_60 ) ;
F_8 ( V_2 , V_44 ,
L_40 , V_5 -> V_45 . V_61 ) ;
F_8 ( V_2 , V_44 ,
L_41 , V_5 -> V_45 . V_62 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_16 ( V_35 , F_14 , F_17 ( V_34 ) -> V_63 ) ;
}
int T_3 F_18 ( void )
{
struct V_64 * V_12 ;
V_65 = F_19 ( V_66 , V_67 . V_68 ) ;
if ( ! V_65 )
goto V_69;
V_12 = F_20 ( L_42 , V_70 , V_65 , & V_71 ) ;
if ( ! V_12 )
goto V_72;
V_12 = F_20 ( L_43 , V_70 , V_65 , & V_73 ) ;
if ( ! V_12 )
goto V_74;
return 0 ;
V_74:
F_21 ( L_42 , V_65 ) ;
V_72:
F_21 ( V_66 , V_67 . V_68 ) ;
V_69:
return - V_75 ;
}
void F_22 ( void )
{
F_21 ( L_42 , V_65 ) ;
F_21 ( L_43 , V_65 ) ;
F_21 ( V_66 , V_67 . V_68 ) ;
}
int F_23 ( struct V_4 * V_5 )
{
if ( V_5 -> V_39 != V_40 )
return - V_76 ;
V_5 -> V_77 = F_20 ( V_5 -> V_14 , V_70 ,
V_65 , & V_78 ) ;
if ( ! V_5 -> V_77 )
return - V_75 ;
V_5 -> V_77 -> V_63 = V_5 ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 )
{
if ( V_5 -> V_39 != V_40 )
return - V_76 ;
F_21 ( V_5 -> V_14 , V_65 ) ;
return 0 ;
}
int T_3 F_18 ( void )
{
return 0 ;
}
void F_22 ( void )
{
}
int F_23 ( struct V_4 * V_5 )
{
return 0 ;
}
int F_24 ( struct V_4 * V_5 )
{
return 0 ;
}
