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
struct V_22 * V_35 = F_12 ( V_33 -> V_36 ) ;
struct V_9 * V_9 = V_35 -> V_37 . V_9 ;
int V_38 ;
if ( strcmp ( V_33 -> V_39 -> V_40 , L_2 ) == 0 ) {
V_38 = 2 ;
} else if ( strcmp ( V_33 -> V_39 -> V_40 , L_3 ) == 0 ) {
V_38 = 1 ;
} else {
F_5 ( V_9 -> V_10 ,
L_4 ,
V_33 -> V_39 -> V_40 ) ;
return - V_29 ;
}
return F_13 ( & V_35 -> V_37 . V_41 [ V_38 ] , V_31 ) ;
}
static T_1 F_14 ( int V_42 , void * V_43 )
{
struct V_22 * V_35 = V_43 ;
struct V_9 * V_9 = V_35 -> V_37 . V_9 ;
struct V_44 V_45 ;
int V_46 = 0 ;
int V_47 , V_13 ;
for ( V_47 = 1 ; V_47 <= 2 ; ++ V_47 ) {
V_13 = F_15 ( & V_35 -> V_37 . V_41 [ V_47 ] ) ;
if ( V_13 != - V_48 )
V_46 ++ ;
if ( V_13 == V_49 ) {
V_45 . V_37 = V_47 ;
F_16 ( V_9 ,
V_50 ,
& V_45 ) ;
}
}
if ( ! V_46 ) {
F_5 ( V_9 -> V_10 , L_5 ) ;
return V_51 ;
}
return V_52 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_53 * V_8 = F_18 ( V_7 ) ;
struct V_54 * V_55 = F_19 ( V_8 ) ;
struct V_22 * V_35 = F_8 ( V_7 ) ;
int V_13 ;
V_35 -> V_37 . V_9 -> V_8 = V_8 ;
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
F_22 ( V_7 ) ;
F_23 ( V_7 ) ;
V_13 = F_24 ( & V_35 -> V_37 . V_41 [ 1 ] , V_7 ) ;
if ( V_13 )
goto V_56;
V_13 = F_24 ( & V_35 -> V_37 . V_41 [ 2 ] , V_7 ) ;
if ( V_13 )
goto V_56;
V_13 = F_25 ( V_7 ,
& V_57 [ 1 ] , 2 ) ;
if ( V_13 )
goto V_56;
F_26 ( V_55 , L_6 ) ;
return 0 ;
V_56:
F_27 ( & V_35 -> V_37 . V_41 [ 1 ] , V_7 ) ;
F_27 ( & V_35 -> V_37 . V_41 [ 2 ] , V_7 ) ;
return V_13 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_22 * V_35 = F_8 ( V_7 ) ;
F_27 ( & V_35 -> V_37 . V_41 [ 1 ] , V_7 ) ;
F_27 ( & V_35 -> V_37 . V_41 [ 2 ] , V_7 ) ;
V_35 -> V_37 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_14 * F_29 ( struct V_58 * V_10 )
{
struct V_22 * V_35 = F_3 ( V_10 ) ;
return V_35 -> V_37 . V_9 -> V_14 ;
}
static int F_30 ( struct V_59 * V_60 )
{
struct V_9 * V_9 = F_3 ( V_60 -> V_10 . V_11 ) ;
struct V_22 * V_23 ;
int V_47 , V_13 ;
F_31 ( F_32 ( V_61 ) > V_62 ) ;
V_23 = F_33 ( & V_60 -> V_10 , sizeof( struct V_22 ) ,
V_63 ) ;
if ( ! V_23 )
return - V_64 ;
F_34 ( V_60 , V_23 ) ;
V_23 -> V_37 . V_9 = V_9 ;
V_23 -> V_37 . V_65 = 4 ;
for ( V_47 = 1 ; V_47 <= 2 ; V_47 ++ ) {
V_23 -> V_37 . V_41 [ V_47 ] . V_66 = L_7 ;
V_23 -> V_37 . V_41 [ V_47 ] . V_67 = V_47 + 1 ;
V_23 -> V_37 . V_41 [ V_47 ] . type = V_68 ;
V_23 -> V_37 . V_41 [ V_47 ] . V_10 = V_9 -> V_10 ;
V_23 -> V_37 . V_41 [ V_47 ] . V_14 = V_9 -> V_14 ;
V_23 -> V_37 . V_41 [ V_47 ] . V_69 = V_70 +
( 0x100 * V_47 ) ;
V_23 -> V_37 . V_41 [ V_47 ] . V_71 = V_72 [ V_47 - 1 ] ;
V_23 -> V_37 . V_41 [ V_47 ] . V_73 =
F_32 ( V_74 ) ;
V_13 = F_35 ( & V_23 -> V_37 . V_41 [ V_47 ] ) ;
if ( V_13 != 0 )
return V_13 ;
}
for ( V_47 = 0 ; V_47 < F_32 ( V_23 -> V_25 ) ; V_47 ++ )
V_23 -> V_25 [ V_47 ] . V_75 = 3 ;
F_36 ( V_9 , 1 , V_76 - 1 ,
V_77 , V_78 ,
& V_23 -> V_25 [ 0 ] ) ;
F_36 ( V_9 , 2 , V_79 - 1 ,
V_80 , V_81 ,
& V_23 -> V_25 [ 1 ] ) ;
F_37 ( V_9 -> V_14 , V_82 ,
V_83 , 0x11 ) ;
F_37 ( V_9 -> V_14 , V_84 ,
V_85 , 0x12 ) ;
for ( V_47 = 0 ; V_47 < F_32 ( V_61 ) ; V_47 ++ )
F_38 ( & V_23 -> V_37 , V_47 ) ;
for ( V_47 = 0 ; V_47 < F_32 ( V_86 ) ; V_47 ++ )
F_37 ( V_9 -> V_14 , V_86 [ V_47 ] ,
V_87 , V_87 ) ;
F_39 ( & V_60 -> V_10 ) ;
F_40 ( & V_60 -> V_10 ) ;
V_13 = F_41 ( V_9 , V_88 ,
L_8 , F_14 ,
V_23 ) ;
if ( V_13 != 0 ) {
F_5 ( & V_60 -> V_10 , L_9 , V_13 ) ;
return V_13 ;
}
V_13 = F_42 ( V_9 ) ;
if ( V_13 < 0 )
goto V_89;
V_13 = F_43 ( & V_60 -> V_10 , & V_90 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_60 -> V_10 , L_10 , V_13 ) ;
goto V_91;
}
V_13 = F_44 ( & V_60 -> V_10 , & V_92 ,
V_61 , F_32 ( V_61 ) ) ;
if ( V_13 < 0 ) {
F_5 ( & V_60 -> V_10 , L_11 , V_13 ) ;
goto V_93;
}
return V_13 ;
V_93:
F_45 ( & V_60 -> V_10 ) ;
V_91:
F_46 ( V_9 ) ;
V_89:
F_47 ( V_9 , V_88 , V_23 ) ;
return V_13 ;
}
static int F_48 ( struct V_59 * V_60 )
{
struct V_22 * V_23 = F_49 ( V_60 ) ;
struct V_9 * V_9 = V_23 -> V_37 . V_9 ;
F_45 ( & V_60 -> V_10 ) ;
F_50 ( & V_60 -> V_10 ) ;
F_51 ( & V_60 -> V_10 ) ;
F_52 ( & V_23 -> V_37 . V_41 [ 1 ] ) ;
F_52 ( & V_23 -> V_37 . V_41 [ 2 ] ) ;
F_46 ( V_9 ) ;
F_47 ( V_9 , V_88 , V_23 ) ;
return 0 ;
}
