static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_12 ;
int V_13 ;
V_13 = F_4 ( V_9 -> V_14 , V_15 , & V_12 ) ;
if ( V_13 != 0 ) {
F_5 ( V_7 -> V_10 , L_1 , V_13 ) ;
return V_13 ;
}
V_12 = ( V_12 & V_16 ) >> V_17 ;
return F_6 ( V_2 , V_4 , V_5 , V_12 ) ;
}
static int F_7 ( struct V_6 * V_7 , int V_18 , int V_19 ,
unsigned int V_20 , unsigned int V_21 )
{
struct V_22 * V_23 = F_8 ( V_7 ) ;
switch ( V_18 ) {
case V_24 :
return F_9 ( & V_23 -> V_25 [ 0 ] , V_19 , V_20 , V_21 ) ;
case V_26 :
return F_9 ( & V_23 -> V_25 [ 1 ] , V_19 , V_20 , V_21 ) ;
case V_27 :
return F_10 ( & V_23 -> V_25 [ 0 ] , V_19 , V_20 ,
V_21 ) ;
case V_28 :
return F_10 ( & V_23 -> V_25 [ 1 ] , V_19 , V_20 ,
V_21 ) ;
default:
return - V_29 ;
}
}
static int F_11 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_34 ;
struct V_22 * V_35 = F_8 ( V_33 -> V_7 ) ;
struct V_9 * V_9 = V_35 -> V_36 . V_9 ;
int V_37 ;
if ( strcmp ( V_33 -> V_38 -> V_39 , L_2 ) == 0 ) {
V_37 = 2 ;
} else if ( strcmp ( V_33 -> V_38 -> V_39 , L_3 ) == 0 ) {
V_37 = 1 ;
} else {
F_5 ( V_9 -> V_10 ,
L_4 ,
V_33 -> V_38 -> V_39 ) ;
return - V_29 ;
}
return F_12 ( & V_35 -> V_36 . V_40 [ V_37 ] , V_31 ) ;
}
static T_1 F_13 ( int V_41 , void * V_42 )
{
struct V_22 * V_35 = V_42 ;
struct V_9 * V_9 = V_35 -> V_36 . V_9 ;
int V_43 = 0 ;
int V_44 , V_13 ;
for ( V_44 = 1 ; V_44 <= 2 ; ++ V_44 ) {
V_13 = F_14 ( & V_35 -> V_36 . V_40 [ V_44 ] ) ;
if ( V_13 != - V_45 )
V_43 ++ ;
}
if ( ! V_43 ) {
F_5 ( V_9 -> V_10 , L_5 ) ;
return V_46 ;
}
return V_47 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_48 * V_8 = F_16 ( V_7 ) ;
struct V_22 * V_35 = F_8 ( V_7 ) ;
struct V_9 * V_9 = V_35 -> V_36 . V_9 ;
int V_13 ;
V_35 -> V_36 . V_9 -> V_8 = V_8 ;
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
V_13 = F_20 ( V_9 , V_49 ,
L_6 , F_13 ,
V_35 ) ;
if ( V_13 != 0 ) {
F_5 ( V_7 -> V_10 , L_7 , V_13 ) ;
return V_13 ;
}
V_13 = F_21 ( & V_35 -> V_36 . V_40 [ 1 ] , V_7 ) ;
if ( V_13 )
goto V_50;
V_13 = F_21 ( & V_35 -> V_36 . V_40 [ 2 ] , V_7 ) ;
if ( V_13 )
goto V_50;
V_13 = F_22 ( V_7 ,
& V_51 [ 1 ] , 2 ) ;
if ( V_13 )
goto V_50;
F_23 ( V_8 , L_8 ) ;
return 0 ;
V_50:
F_24 ( & V_35 -> V_36 . V_40 [ 1 ] , V_7 ) ;
F_24 ( & V_35 -> V_36 . V_40 [ 2 ] , V_7 ) ;
return V_13 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_22 * V_35 = F_8 ( V_7 ) ;
struct V_9 * V_9 = V_35 -> V_36 . V_9 ;
F_24 ( & V_35 -> V_36 . V_40 [ 1 ] , V_7 ) ;
F_24 ( & V_35 -> V_36 . V_40 [ 2 ] , V_7 ) ;
V_35 -> V_36 . V_9 -> V_8 = NULL ;
F_26 ( V_9 , V_49 , V_35 ) ;
F_27 ( V_7 ) ;
return 0 ;
}
static struct V_14 * F_28 ( struct V_52 * V_10 )
{
struct V_22 * V_35 = F_3 ( V_10 ) ;
return V_35 -> V_36 . V_9 -> V_14 ;
}
static int F_29 ( struct V_53 * V_54 )
{
struct V_9 * V_9 = F_3 ( V_54 -> V_10 . V_11 ) ;
struct V_22 * V_23 ;
int V_44 , V_13 ;
F_30 ( F_31 ( V_55 ) > V_56 ) ;
V_23 = F_32 ( & V_54 -> V_10 , sizeof( struct V_22 ) ,
V_57 ) ;
if ( ! V_23 )
return - V_58 ;
F_33 ( V_54 , V_23 ) ;
V_23 -> V_36 . V_9 = V_9 ;
V_23 -> V_36 . V_59 = 4 ;
for ( V_44 = 1 ; V_44 <= 2 ; V_44 ++ ) {
V_23 -> V_36 . V_40 [ V_44 ] . V_60 = L_9 ;
V_23 -> V_36 . V_40 [ V_44 ] . V_61 = V_44 + 1 ;
V_23 -> V_36 . V_40 [ V_44 ] . type = V_62 ;
V_23 -> V_36 . V_40 [ V_44 ] . V_10 = V_9 -> V_10 ;
V_23 -> V_36 . V_40 [ V_44 ] . V_14 = V_9 -> V_14 ;
V_23 -> V_36 . V_40 [ V_44 ] . V_63 = V_64 +
( 0x100 * V_44 ) ;
V_23 -> V_36 . V_40 [ V_44 ] . V_65 = V_66 [ V_44 - 1 ] ;
V_23 -> V_36 . V_40 [ V_44 ] . V_67 =
F_31 ( V_68 ) ;
V_13 = F_34 ( & V_23 -> V_36 . V_40 [ V_44 ] ) ;
if ( V_13 != 0 )
return V_13 ;
}
for ( V_44 = 0 ; V_44 < F_31 ( V_23 -> V_25 ) ; V_44 ++ )
V_23 -> V_25 [ V_44 ] . V_69 = 3 ;
F_35 ( V_9 , 1 , V_70 - 1 ,
V_71 , V_72 ,
& V_23 -> V_25 [ 0 ] ) ;
F_35 ( V_9 , 2 , V_73 - 1 ,
V_74 , V_75 ,
& V_23 -> V_25 [ 1 ] ) ;
F_36 ( V_9 -> V_14 , V_76 ,
V_77 , 0x11 ) ;
F_36 ( V_9 -> V_14 , V_78 ,
V_79 , 0x12 ) ;
for ( V_44 = 0 ; V_44 < F_31 ( V_55 ) ; V_44 ++ )
F_37 ( & V_23 -> V_36 , V_44 ) ;
for ( V_44 = 0 ; V_44 < F_31 ( V_80 ) ; V_44 ++ )
F_36 ( V_9 -> V_14 , V_80 [ V_44 ] ,
V_81 , V_81 ) ;
F_38 ( & V_54 -> V_10 ) ;
F_39 ( & V_54 -> V_10 ) ;
V_13 = F_40 ( & V_54 -> V_10 , & V_82 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_54 -> V_10 , L_10 , V_13 ) ;
return V_13 ;
}
V_13 = F_41 ( & V_54 -> V_10 , & V_83 ,
V_55 , F_31 ( V_55 ) ) ;
if ( V_13 < 0 ) {
F_5 ( & V_54 -> V_10 , L_11 , V_13 ) ;
F_42 ( & V_54 -> V_10 ) ;
}
return V_13 ;
}
static int F_43 ( struct V_53 * V_54 )
{
struct V_22 * V_23 = F_44 ( V_54 ) ;
F_42 ( & V_54 -> V_10 ) ;
F_45 ( & V_54 -> V_10 ) ;
F_46 ( & V_54 -> V_10 ) ;
F_47 ( & V_23 -> V_36 . V_40 [ 1 ] ) ;
F_47 ( & V_23 -> V_36 . V_40 [ 2 ] ) ;
return 0 ;
}
