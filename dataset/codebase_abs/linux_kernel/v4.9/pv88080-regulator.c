static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 , V_7 = 0 ;
V_6 = F_3 ( V_2 -> V_8 , V_4 -> V_9 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_5 & V_10 ) {
case V_11 :
V_7 = V_12 ;
break;
case V_13 :
V_7 = V_14 ;
break;
case V_15 :
V_7 = V_16 ;
break;
default:
return - V_17 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 = 0 ;
switch ( V_7 ) {
case V_12 :
V_18 = V_11 ;
break;
case V_14 :
V_18 = V_13 ;
break;
case V_16 :
V_18 = V_15 ;
break;
default:
return - V_17 ;
}
return F_5 ( V_2 -> V_8 , V_4 -> V_9 ,
V_10 , V_18 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_19 ,
int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_21 ;
for ( V_21 = V_4 -> V_22 ; V_21 >= 0 ; V_21 -- ) {
if ( V_19 <= V_4 -> V_23 [ V_21 ]
&& V_20 >= V_4 -> V_23 [ V_21 ] ) {
return F_5 ( V_2 -> V_8 ,
V_4 -> V_24 ,
V_4 -> V_25 ,
V_21 << V_26 ) ;
}
}
return - V_17 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_3 ( V_2 -> V_8 , V_4 -> V_24 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = ( V_5 & V_4 -> V_25 ) >> V_26 ;
return V_4 -> V_23 [ V_5 ] ;
}
static T_1 F_8 ( int V_27 , void * V_5 )
{
struct V_28 * V_29 = V_5 ;
int V_21 , V_30 , V_31 , V_6 = V_32 ;
V_31 = F_3 ( V_29 -> V_8 , V_33 , & V_30 ) ;
if ( V_31 < 0 )
goto V_34;
if ( V_30 & V_35 ) {
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ ) {
if ( V_29 -> V_2 [ V_21 ] != NULL ) {
F_9 ( V_29 -> V_2 [ V_21 ] ,
V_37 ,
NULL ) ;
}
}
V_31 = F_10 ( V_29 -> V_8 , V_33 ,
V_35 ) ;
if ( V_31 < 0 )
goto V_34;
V_6 = V_38 ;
}
if ( V_30 & V_39 ) {
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ ) {
if ( V_29 -> V_2 [ V_21 ] != NULL ) {
F_9 ( V_29 -> V_2 [ V_21 ] ,
V_40 ,
NULL ) ;
}
}
V_31 = F_10 ( V_29 -> V_8 , V_33 ,
V_39 ) ;
if ( V_31 < 0 )
goto V_34;
V_6 = V_38 ;
}
return V_6 ;
V_34:
F_11 ( V_29 -> V_41 , L_1 , V_31 ) ;
return V_32 ;
}
static int F_12 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_46 * V_47 = F_13 ( & V_43 -> V_41 ) ;
struct V_28 * V_29 ;
const struct V_48 * V_49 ;
const struct V_50 * V_51 ;
struct V_52 V_53 = { } ;
int V_21 , error , V_6 ;
unsigned int V_54 , V_55 ;
V_29 = F_14 ( & V_43 -> V_41 , sizeof( struct V_28 ) , V_56 ) ;
if ( ! V_29 )
return - V_57 ;
V_29 -> V_41 = & V_43 -> V_41 ;
V_29 -> V_8 = F_15 ( V_43 , & V_58 ) ;
if ( F_16 ( V_29 -> V_8 ) ) {
error = F_17 ( V_29 -> V_8 ) ;
F_11 ( V_29 -> V_41 , L_2 ,
error ) ;
return error ;
}
if ( V_43 -> V_41 . V_59 ) {
V_51 = F_18 ( V_60 , V_43 -> V_41 . V_59 ) ;
if ( ! V_51 ) {
F_11 ( V_29 -> V_41 , L_3 ) ;
return - V_17 ;
}
V_29 -> type = ( unsigned long ) V_51 -> V_5 ;
} else {
V_29 -> type = V_45 -> V_61 ;
}
F_19 ( V_43 , V_29 ) ;
if ( V_43 -> V_27 != 0 ) {
V_6 = F_10 ( V_29 -> V_8 , V_62 , 0xFF ) ;
if ( V_6 < 0 ) {
F_11 ( V_29 -> V_41 ,
L_4 , V_6 ) ;
return V_6 ;
}
V_6 = F_10 ( V_29 -> V_8 , V_63 , 0xFF ) ;
if ( V_6 < 0 ) {
F_11 ( V_29 -> V_41 ,
L_5 , V_6 ) ;
return V_6 ;
}
V_6 = F_10 ( V_29 -> V_8 , V_64 , 0xFF ) ;
if ( V_6 < 0 ) {
F_11 ( V_29 -> V_41 ,
L_6 , V_6 ) ;
return V_6 ;
}
V_6 = F_20 ( & V_43 -> V_41 , V_43 -> V_27 , NULL ,
F_8 ,
V_65 | V_66 ,
L_7 , V_29 ) ;
if ( V_6 != 0 ) {
F_11 ( V_29 -> V_41 , L_8 ,
V_43 -> V_27 ) ;
return V_6 ;
}
V_6 = F_5 ( V_29 -> V_8 , V_62 ,
V_67 | V_68 , 0 ) ;
if ( V_6 < 0 ) {
F_11 ( V_29 -> V_41 ,
L_9 , V_6 ) ;
return V_6 ;
}
} else {
F_21 ( V_29 -> V_41 , L_10 ) ;
}
switch ( V_29 -> type ) {
case V_69 :
V_29 -> V_49 = & V_70 ;
break;
case V_71 :
V_29 -> V_49 = & V_72 ;
break;
}
V_49 = V_29 -> V_49 ;
V_53 . V_41 = V_29 -> V_41 ;
V_53 . V_8 = V_29 -> V_8 ;
for ( V_21 = 0 ; V_21 < V_36 - 1 ; V_21 ++ ) {
if ( V_47 )
V_53 . V_47 = & V_47 [ V_21 ] ;
V_73 [ V_21 ] . V_24
= V_49 -> V_74 [ V_21 ] . V_75 ;
V_73 [ V_21 ] . V_25
= V_49 -> V_74 [ V_21 ] . V_76 ;
V_73 [ V_21 ] . V_9
= V_49 -> V_74 [ V_21 ] . V_77 ;
V_73 [ V_21 ] . V_54
= V_49 -> V_74 [ V_21 ] . V_78 ;
V_73 [ V_21 ] . V_55
= V_49 -> V_74 [ V_21 ] . V_79 ;
V_73 [ V_21 ] . V_80 . V_81
= V_49 -> V_74 [ V_21 ] . V_82 ;
V_73 [ V_21 ] . V_80 . V_83
= V_49 -> V_74 [ V_21 ] . V_84 ;
V_73 [ V_21 ] . V_80 . V_85
= V_49 -> V_74 [ V_21 ] . V_86 ;
V_73 [ V_21 ] . V_80 . V_87
= V_49 -> V_74 [ V_21 ] . V_88 ;
V_6 = F_3 ( V_29 -> V_8 ,
V_73 [ V_21 ] . V_54 , & V_54 ) ;
if ( V_6 < 0 )
return V_6 ;
V_54 = ( ( V_54 >> V_89 ) &
V_90 ) ;
V_6 = F_3 ( V_29 -> V_8 ,
V_73 [ V_21 ] . V_55 , & V_55 ) ;
if ( V_6 < 0 )
return V_6 ;
V_55 = ( ( V_55 >> V_91 ) &
V_92 ) ;
V_73 [ V_21 ] . V_80 . V_93 =
V_94 [ V_54 ] . V_93 * ( V_55 + 1 ) ;
V_73 [ V_21 ] . V_80 . V_95 =
V_94 [ V_54 ] . V_95 * ( V_55 + 1 ) ;
V_73 [ V_21 ] . V_80 . V_96 =
( ( V_94 [ V_54 ] . V_97 * ( V_55 + 1 ) )
- ( V_73 [ V_21 ] . V_80 . V_93 ) )
/ ( V_73 [ V_21 ] . V_80 . V_95 ) + 1 ;
V_53 . V_61 = ( void * ) & V_73 [ V_21 ] ;
V_29 -> V_2 [ V_21 ] = F_22 ( V_29 -> V_41 ,
& V_73 [ V_21 ] . V_80 , & V_53 ) ;
if ( F_16 ( V_29 -> V_2 [ V_21 ] ) ) {
F_11 ( V_29 -> V_41 ,
L_11 ) ;
return F_17 ( V_29 -> V_2 [ V_21 ] ) ;
}
}
V_73 [ V_98 ] . V_80 . V_81
= V_49 -> V_99 ;
V_73 [ V_98 ] . V_80 . V_83
= V_49 -> V_100 ;
V_73 [ V_98 ] . V_80 . V_85
= V_49 -> V_101 ;
V_73 [ V_98 ] . V_80 . V_87
= V_49 -> V_102 ;
if ( V_47 )
V_53 . V_47 = & V_47 [ V_98 ] ;
V_53 . V_61 = ( void * ) & V_73 [ V_98 ] ;
V_29 -> V_2 [ V_98 ] = F_22 ( V_29 -> V_41 ,
& V_73 [ V_98 ] . V_80 , & V_53 ) ;
if ( F_16 ( V_29 -> V_2 [ V_98 ] ) ) {
F_11 ( V_29 -> V_41 , L_11 ) ;
return F_17 ( V_29 -> V_2 [ V_98 ] ) ;
}
return 0 ;
}
