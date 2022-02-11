static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
switch ( V_3 -> type ) {
case V_5 :
case V_6 :
V_4 = F_3 ( V_3 , V_7 ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 , L_1 , V_4 ) ;
} else if ( V_4 & V_8 ) {
F_5 ( V_2 , L_2 ) ;
return 0 ;
}
break;
default:
break;
}
if ( ! V_3 -> V_9 )
F_6 ( V_3 , V_10 ,
V_11 | V_12 ,
V_11 | V_12 ) ;
F_7 ( V_3 , V_13 ,
F_3 ( V_3 , V_13 ) ) ;
F_8 ( V_3 -> V_14 ) ;
V_4 = F_9 ( V_3 -> V_14 , V_15 ,
V_16 ) ;
if ( V_4 != 0 )
F_4 ( V_2 , L_3 , V_4 ) ;
V_4 = F_9 ( V_3 -> V_14 ,
V_17 ,
V_17 ) ;
if ( V_4 != 0 )
F_4 ( V_2 , L_4 , V_4 ) ;
F_10 ( V_3 -> V_14 , true ) ;
V_3 -> V_18 = true ;
V_4 = F_11 ( V_3 -> V_19 ,
V_3 -> V_20 ) ;
if ( V_4 != 0 ) {
F_4 ( V_2 , L_5 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
if ( ! V_3 -> V_18 )
return 0 ;
V_4 = F_13 ( V_3 -> V_19 ,
V_3 -> V_20 ) ;
if ( V_4 != 0 ) {
F_4 ( V_2 , L_6 , V_4 ) ;
return V_4 ;
}
F_10 ( V_3 -> V_14 , false ) ;
V_4 = F_14 ( V_3 -> V_14 ) ;
if ( V_4 != 0 ) {
F_4 ( V_2 , L_7 , V_4 ) ;
goto V_21;
}
F_6 ( V_3 , V_10 ,
V_11 | V_12 ,
0 ) ;
V_3 -> V_18 = false ;
return 0 ;
V_21:
F_11 ( V_3 -> V_19 , V_3 -> V_20 ) ;
return V_4 ;
}
static int F_15 ( struct V_22 * V_23 , int V_24 )
{
struct V_25 * V_26 ;
if ( ! V_23 )
return 0 ;
V_26 = & V_23 -> V_24 [ V_24 ] ;
if ( ! V_26 -> V_27 )
return 0 ;
return V_26 -> V_27 -> V_28 != 0 ;
}
static int F_15 ( struct V_22 * V_23 , int V_24 )
{
return 0 ;
}
static int F_16 ( struct V_3 * V_3 )
{
struct V_29 * V_30 = V_3 -> V_2 -> V_31 ;
struct V_22 * V_23 = & V_3 -> V_23 ;
int V_32 ;
if ( ! V_30 )
return 0 ;
if ( F_17 ( V_30 , L_8 , V_23 -> V_33 ,
F_18 ( V_23 -> V_33 ) ) >= 0 ) {
for ( V_32 = 0 ; V_32 < F_18 ( V_23 -> V_33 ) ; V_32 ++ ) {
if ( V_3 -> V_23 . V_33 [ V_32 ] == 0 )
V_23 -> V_33 [ V_32 ]
= V_34 ;
}
}
F_17 ( V_30 , L_9 , V_23 -> V_35 ,
F_18 ( V_23 -> V_35 ) ) ;
V_23 -> V_36 = true ;
V_23 -> V_37 = true ;
if ( F_19 ( V_30 , L_10 , NULL ) )
V_23 -> V_36 = false ;
if ( F_19 ( V_30 , L_11 , NULL ) )
V_23 -> V_37 = false ;
if ( F_19 ( V_30 , L_12 , NULL ) )
V_23 -> V_38 = true ;
if ( F_19 ( V_30 , L_13 , NULL ) )
V_23 -> V_39 = true ;
if ( F_19 ( V_30 , L_14 , NULL ) )
V_23 -> V_39 = true ;
V_23 -> V_24 [ 0 ] . V_40 = F_20 ( V_30 , L_15 , 0 ) ;
if ( V_23 -> V_24 [ 0 ] . V_40 < 0 )
V_23 -> V_24 [ 0 ] . V_40 = 0 ;
V_23 -> V_24 [ 1 ] . V_40 = F_20 ( V_30 , L_16 , 0 ) ;
if ( V_23 -> V_24 [ 1 ] . V_40 < 0 )
V_23 -> V_24 [ 1 ] . V_40 = 0 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_3 )
{
return 0 ;
}
static int F_21 ( struct V_3 * V_3 , int V_41 )
{
struct V_22 * V_23 ;
struct V_42 * V_42 ;
const struct V_43 * V_44 = NULL ;
const char * V_45 ;
int V_4 , V_32 , V_46 = 0 ;
int V_47 = 0 ;
if ( F_22 ( V_3 -> V_2 ) ) {
V_23 = F_22 ( V_3 -> V_2 ) ;
V_3 -> V_23 = * V_23 ;
}
V_23 = & V_3 -> V_23 ;
V_4 = F_16 ( V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
F_23 ( V_3 -> V_2 , V_3 ) ;
V_4 = F_24 ( V_3 -> V_2 , 0 ,
V_48 ,
F_18 ( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_17 , V_4 ) ;
goto V_49;
}
switch ( V_3 -> type ) {
case V_6 :
V_3 -> V_19 = F_18 ( V_50 ) ;
break;
case V_51 :
V_3 -> V_19 = F_18 ( V_52 ) ;
break;
case V_5 :
V_3 -> V_19 = F_18 ( V_53 ) ;
break;
default:
F_25 () ;
goto V_49;
}
V_3 -> V_20 = F_26 ( V_3 -> V_2 ,
sizeof( struct V_54 ) *
V_3 -> V_19 , V_55 ) ;
if ( ! V_3 -> V_20 ) {
V_4 = - V_56 ;
goto V_49;
}
switch ( V_3 -> type ) {
case V_6 :
for ( V_32 = 0 ; V_32 < F_18 ( V_50 ) ; V_32 ++ )
V_3 -> V_20 [ V_32 ] . V_57 = V_50 [ V_32 ] ;
break;
case V_51 :
for ( V_32 = 0 ; V_32 < F_18 ( V_52 ) ; V_32 ++ )
V_3 -> V_20 [ V_32 ] . V_57 = V_52 [ V_32 ] ;
break;
case V_5 :
for ( V_32 = 0 ; V_32 < F_18 ( V_53 ) ; V_32 ++ )
V_3 -> V_20 [ V_32 ] . V_57 = V_53 [ V_32 ] ;
break;
default:
F_25 () ;
goto V_49;
}
V_4 = F_27 ( V_3 -> V_2 , V_3 -> V_19 ,
V_3 -> V_20 ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_18 , V_4 ) ;
goto V_49;
}
V_4 = F_13 ( V_3 -> V_19 ,
V_3 -> V_20 ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_6 , V_4 ) ;
goto V_49;
}
V_4 = F_3 ( V_3 , V_13 ) ;
if ( V_4 < 0 ) {
F_4 ( V_3 -> V_2 , L_19 ) ;
goto V_21;
}
switch ( V_4 ) {
case 0x1811 :
V_45 = L_20 ;
if ( V_3 -> type != V_6 )
F_28 ( V_3 -> V_2 , L_21 ,
V_3 -> type ) ;
V_3 -> type = V_6 ;
break;
case 0x8994 :
V_45 = L_22 ;
if ( V_3 -> type != V_51 )
F_28 ( V_3 -> V_2 , L_21 ,
V_3 -> type ) ;
V_3 -> type = V_51 ;
break;
case 0x8958 :
V_45 = L_23 ;
if ( V_3 -> type != V_5 )
F_28 ( V_3 -> V_2 , L_21 ,
V_3 -> type ) ;
V_3 -> type = V_5 ;
break;
default:
F_4 ( V_3 -> V_2 , L_24 ,
V_4 ) ;
V_4 = - V_58 ;
goto V_21;
}
V_4 = F_3 ( V_3 , V_59 ) ;
if ( V_4 < 0 ) {
F_4 ( V_3 -> V_2 , L_25 ,
V_4 ) ;
goto V_21;
}
V_3 -> V_60 = V_4 & V_61 ;
V_3 -> V_62 = ( V_4 & V_63 ) >> V_64 ;
switch ( V_3 -> type ) {
case V_51 :
switch ( V_3 -> V_60 ) {
case 0 :
case 1 :
F_28 ( V_3 -> V_2 ,
L_26 ,
'A' + V_3 -> V_60 ) ;
break;
case 2 :
case 3 :
default:
V_44 = V_65 ;
V_46 = F_18 ( V_65 ) ;
break;
}
break;
case V_5 :
switch ( V_3 -> V_60 ) {
case 0 :
V_44 = V_66 ;
V_46 = F_18 ( V_66 ) ;
break;
default:
break;
}
break;
case V_6 :
if ( V_3 -> V_60 > 1 )
V_3 -> V_60 ++ ;
V_44 = V_67 ;
V_46 = F_18 ( V_67 ) ;
break;
default:
break;
}
F_29 ( V_3 -> V_2 , L_27 , V_45 ,
'A' + V_3 -> V_60 , V_3 -> V_62 ) ;
switch ( V_3 -> type ) {
case V_6 :
V_42 = & V_68 ;
break;
case V_51 :
V_42 = & V_69 ;
break;
case V_5 :
V_42 = & V_70 ;
break;
default:
F_4 ( V_3 -> V_2 , L_28 , V_3 -> type ) ;
return - V_58 ;
}
V_4 = F_30 ( V_3 -> V_14 , V_42 ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_29 ,
V_4 ) ;
return V_4 ;
}
V_4 = F_7 ( V_3 , V_13 ,
F_3 ( V_3 , V_13 ) ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_30 , V_4 ) ;
return V_4 ;
}
if ( V_44 ) {
V_4 = F_31 ( V_3 -> V_14 , V_44 ,
V_46 ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_31 ,
V_4 ) ;
goto V_49;
}
}
V_3 -> V_71 = V_23 -> V_71 ;
V_3 -> V_72 = V_23 -> V_72 ;
for ( V_32 = 0 ; V_32 < F_18 ( V_23 -> V_33 ) ; V_32 ++ ) {
if ( V_23 -> V_33 [ V_32 ] ) {
F_6 ( V_3 , V_15 + V_32 ,
0xffff , V_23 -> V_33 [ V_32 ] ) ;
}
}
V_3 -> V_9 = V_23 -> V_9 ;
if ( V_23 -> V_73 )
V_47 |= V_74 ;
F_6 ( V_3 , V_10 ,
V_11 | V_12 |
V_74 | V_75 ,
V_47 ) ;
for ( V_32 = 0 ; V_32 < V_76 ; V_32 ++ ) {
if ( F_15 ( V_23 , V_32 ) )
F_6 ( V_3 , V_77 + V_32 ,
V_78 , V_78 ) ;
else
F_6 ( V_3 , V_77 + V_32 ,
V_78 , 0 ) ;
}
F_32 ( V_3 ) ;
V_4 = F_24 ( V_3 -> V_2 , - 1 ,
V_79 , F_18 ( V_79 ) ,
NULL , 0 , NULL ) ;
if ( V_4 != 0 ) {
F_4 ( V_3 -> V_2 , L_17 , V_4 ) ;
goto V_80;
}
F_33 ( V_3 -> V_2 ) ;
F_34 ( V_3 -> V_2 ) ;
return 0 ;
V_80:
F_35 ( V_3 ) ;
V_21:
F_11 ( V_3 -> V_19 ,
V_3 -> V_20 ) ;
V_49:
F_36 ( V_3 -> V_2 ) ;
return V_4 ;
}
static void F_37 ( struct V_3 * V_3 )
{
F_38 ( V_3 -> V_2 ) ;
F_36 ( V_3 -> V_2 ) ;
F_35 ( V_3 ) ;
F_11 ( V_3 -> V_19 ,
V_3 -> V_20 ) ;
}
static int F_39 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
const struct V_85 * V_86 ;
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_26 ( & V_82 -> V_2 , sizeof( struct V_3 ) , V_55 ) ;
if ( V_3 == NULL )
return - V_56 ;
F_40 ( V_82 , V_3 ) ;
V_3 -> V_2 = & V_82 -> V_2 ;
V_3 -> V_41 = V_82 -> V_41 ;
if ( V_82 -> V_2 . V_31 ) {
V_86 = F_41 ( V_87 , & V_82 -> V_2 ) ;
if ( V_86 )
V_3 -> type = (enum V_88 ) V_86 -> V_89 ;
} else {
V_3 -> type = V_84 -> V_90 ;
}
V_3 -> V_14 = F_42 ( V_82 , & V_91 ) ;
if ( F_43 ( V_3 -> V_14 ) ) {
V_4 = F_44 ( V_3 -> V_14 ) ;
F_4 ( V_3 -> V_2 , L_32 ,
V_4 ) ;
return V_4 ;
}
return F_21 ( V_3 , V_82 -> V_41 ) ;
}
static int F_45 ( struct V_81 * V_82 )
{
struct V_3 * V_3 = F_46 ( V_82 ) ;
F_37 ( V_3 ) ;
return 0 ;
}
