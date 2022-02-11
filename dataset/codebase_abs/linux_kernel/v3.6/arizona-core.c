int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
V_1 -> V_4 ++ ;
if ( V_1 -> V_4 == 1 )
V_2 = F_3 ( V_1 -> V_5 , V_6 ,
V_7 ,
V_7 ) ;
if ( V_2 != 0 )
V_1 -> V_4 -- ;
F_4 ( & V_1 -> V_3 ) ;
return V_2 ;
}
int F_5 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
F_6 ( V_1 -> V_4 <= 0 ) ;
V_1 -> V_4 -- ;
if ( V_1 -> V_4 == 0 )
F_3 ( V_1 -> V_5 , V_6 ,
V_7 , 0 ) ;
F_4 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static T_1 F_7 ( int V_8 , void * V_9 )
{
struct V_1 * V_1 = V_9 ;
F_8 ( V_1 -> V_10 , L_1 ) ;
return V_11 ;
}
static T_1 F_9 ( int V_8 , void * V_9 )
{
struct V_1 * V_1 = V_9 ;
unsigned int V_12 ;
int V_2 ;
V_2 = F_10 ( V_1 -> V_5 , V_13 ,
& V_12 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_2 ,
V_2 ) ;
return V_14 ;
}
if ( V_12 & V_15 )
F_8 ( V_1 -> V_10 , L_3 ) ;
if ( V_12 & V_15 )
F_8 ( V_1 -> V_10 , L_3 ) ;
if ( V_12 & V_16 )
F_8 ( V_1 -> V_10 , L_4 ) ;
if ( V_12 & V_17 )
F_8 ( V_1 -> V_10 , L_5 ) ;
if ( V_12 & V_18 )
F_8 ( V_1 -> V_10 , L_6 ) ;
if ( V_12 & V_19 )
F_8 ( V_1 -> V_10 , L_7 ) ;
if ( V_12 & V_20 )
F_8 ( V_1 -> V_10 , L_8 ) ;
if ( V_12 & V_21 )
F_8 ( V_1 -> V_10 , L_9 ) ;
if ( V_12 & V_22 )
F_8 ( V_1 -> V_10 , L_10 ) ;
if ( V_12 & V_23 )
F_8 ( V_1 -> V_10 , L_11 ) ;
return V_11 ;
}
static T_1 F_11 ( int V_8 , void * V_9 )
{
struct V_1 * V_1 = V_9 ;
unsigned int V_12 [ 2 ] ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_5 , V_24 ,
& V_12 [ 0 ] , 2 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_12 ,
V_2 ) ;
return V_14 ;
}
if ( V_12 [ 0 ] & V_25 )
F_8 ( V_1 -> V_10 , L_13 ) ;
if ( V_12 [ 0 ] & V_26 )
F_8 ( V_1 -> V_10 , L_14 ) ;
if ( V_12 [ 0 ] & V_27 )
F_8 ( V_1 -> V_10 , L_15 ) ;
if ( V_12 [ 0 ] & V_28 )
F_8 ( V_1 -> V_10 , L_16 ) ;
if ( V_12 [ 0 ] & V_29 )
F_8 ( V_1 -> V_10 , L_17 ) ;
if ( V_12 [ 0 ] & V_30 )
F_8 ( V_1 -> V_10 , L_18 ) ;
if ( V_12 [ 0 ] & V_31 )
F_8 ( V_1 -> V_10 , L_19 ) ;
if ( V_12 [ 0 ] & V_32 )
F_8 ( V_1 -> V_10 , L_20 ) ;
if ( V_12 [ 0 ] & V_33 )
F_8 ( V_1 -> V_10 , L_21 ) ;
if ( V_12 [ 0 ] & V_34 )
F_8 ( V_1 -> V_10 , L_22 ) ;
if ( V_12 [ 1 ] & V_35 )
F_8 ( V_1 -> V_10 , L_23 ) ;
if ( V_12 [ 1 ] & V_36 )
F_8 ( V_1 -> V_10 , L_24 ) ;
if ( V_12 [ 1 ] & V_37 )
F_8 ( V_1 -> V_10 , L_25 ) ;
if ( V_12 [ 1 ] & V_38 )
F_8 ( V_1 -> V_10 , L_26 ) ;
if ( V_12 [ 1 ] & V_39 )
F_8 ( V_1 -> V_10 , L_27 ) ;
if ( V_12 [ 1 ] & V_40 )
F_8 ( V_1 -> V_10 , L_28 ) ;
if ( V_12 [ 1 ] & V_41 )
F_8 ( V_1 -> V_10 , L_29 ) ;
if ( V_12 [ 1 ] & V_42 )
F_8 ( V_1 -> V_10 , L_30 ) ;
if ( V_12 [ 1 ] & V_43 )
F_8 ( V_1 -> V_10 , L_31 ) ;
if ( V_12 [ 1 ] & V_44 )
F_8 ( V_1 -> V_10 , L_32 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_1 )
{
unsigned int V_45 ;
int V_2 , V_46 ;
for ( V_46 = 0 ; V_46 < 5 ; V_46 ++ ) {
F_14 ( 1 ) ;
V_2 = F_10 ( V_1 -> V_5 ,
V_47 , & V_45 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_33 ,
V_2 ) ;
continue;
}
if ( V_45 & V_48 )
break;
}
if ( V_45 & V_48 ) {
F_15 ( V_1 -> V_5 , V_49 ,
V_48 ) ;
} else {
F_8 ( V_1 -> V_10 , L_34 , V_45 ) ;
return - V_50 ;
}
F_16 ( V_1 -> V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_51 * V_10 )
{
struct V_1 * V_1 = F_18 ( V_10 ) ;
int V_2 ;
F_19 ( V_1 -> V_10 , L_35 ) ;
V_2 = F_20 ( V_1 -> V_52 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_36 , V_2 ) ;
return V_2 ;
}
F_21 ( V_1 -> V_5 , false ) ;
V_2 = F_13 ( V_1 ) ;
if ( V_2 != 0 ) {
F_22 ( V_1 -> V_52 ) ;
return V_2 ;
}
F_23 ( V_1 -> V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_10 )
{
struct V_1 * V_1 = F_18 ( V_10 ) ;
F_19 ( V_1 -> V_10 , L_37 ) ;
F_22 ( V_1 -> V_52 ) ;
F_21 ( V_1 -> V_5 , true ) ;
F_25 ( V_1 -> V_5 ) ;
return 0 ;
}
int T_2 F_26 ( struct V_1 * V_1 )
{
struct V_51 * V_10 = V_1 -> V_10 ;
const char * V_53 ;
unsigned int V_45 , V_12 ;
int V_2 , V_46 ;
F_27 ( V_1 -> V_10 , V_1 ) ;
F_28 ( & V_1 -> V_3 ) ;
if ( F_29 ( V_1 -> V_10 ) )
memcpy ( & V_1 -> V_54 , F_29 ( V_1 -> V_10 ) ,
sizeof( V_1 -> V_54 ) ) ;
F_21 ( V_1 -> V_5 , true ) ;
switch ( V_1 -> type ) {
case V_55 :
case V_56 :
for ( V_46 = 0 ; V_46 < F_30 ( V_57 ) ; V_46 ++ )
V_1 -> V_58 [ V_46 ] . V_59
= V_57 [ V_46 ] ;
V_1 -> V_60 = F_30 ( V_57 ) ;
break;
default:
F_8 ( V_1 -> V_10 , L_38 ,
V_1 -> type ) ;
return - V_61 ;
}
V_2 = F_31 ( V_1 -> V_10 , - 1 , V_62 ,
F_30 ( V_62 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_39 , V_2 ) ;
return V_2 ;
}
V_2 = F_32 ( V_10 , V_1 -> V_60 ,
V_1 -> V_58 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_40 ,
V_2 ) ;
goto V_63;
}
V_1 -> V_52 = F_33 ( V_1 -> V_10 , L_41 ) ;
if ( F_34 ( V_1 -> V_52 ) ) {
V_2 = F_35 ( V_1 -> V_52 ) ;
F_8 ( V_10 , L_42 , V_2 ) ;
goto V_63;
}
V_2 = F_36 ( V_1 -> V_60 ,
V_1 -> V_58 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_43 ,
V_2 ) ;
goto V_63;
}
V_2 = F_20 ( V_1 -> V_52 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_36 , V_2 ) ;
goto V_64;
}
if ( V_1 -> V_54 . V_65 ) {
V_2 = F_37 ( V_1 -> V_54 . V_65 ,
V_66 | V_67 ,
L_44 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_45 , V_2 ) ;
goto V_68;
}
F_38 ( V_1 -> V_54 . V_65 , 1 ) ;
}
F_21 ( V_1 -> V_5 , false ) ;
V_2 = F_10 ( V_1 -> V_5 , V_69 , & V_45 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_46 , V_2 ) ;
goto V_70;
}
V_2 = F_10 ( V_1 -> V_5 , V_71 ,
& V_1 -> V_72 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_47 , V_2 ) ;
goto V_70;
}
V_1 -> V_72 &= V_73 ;
switch ( V_45 ) {
#ifdef F_39
case 0x5102 :
V_53 = L_48 ;
if ( V_1 -> type != V_55 ) {
F_8 ( V_1 -> V_10 , L_49 ,
V_1 -> type ) ;
V_1 -> type = V_55 ;
}
V_2 = F_40 ( V_1 ) ;
break;
#endif
#ifdef F_41
case 0x5110 :
V_53 = L_50 ;
if ( V_1 -> type != V_56 ) {
F_8 ( V_1 -> V_10 , L_51 ,
V_1 -> type ) ;
V_1 -> type = V_56 ;
}
V_2 = F_42 ( V_1 ) ;
break;
#endif
default:
F_8 ( V_1 -> V_10 , L_52 , V_45 ) ;
goto V_70;
}
F_43 ( V_10 , L_53 , V_53 , V_1 -> V_72 + 'A' ) ;
if ( V_2 != 0 )
F_8 ( V_1 -> V_10 , L_54 , V_2 ) ;
if ( ! V_1 -> V_54 . V_65 ) {
V_2 = F_15 ( V_1 -> V_5 , V_69 , 0 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_55 , V_2 ) ;
goto V_70;
}
}
V_2 = F_13 ( V_1 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_56 , V_2 ) ;
goto V_70;
}
for ( V_46 = 0 ; V_46 < F_30 ( V_1 -> V_54 . V_74 ) ; V_46 ++ ) {
if ( ! V_1 -> V_54 . V_74 [ V_46 ] )
continue;
F_15 ( V_1 -> V_5 , V_75 + V_46 ,
V_1 -> V_54 . V_74 [ V_46 ] ) ;
}
F_44 ( V_1 -> V_10 , 100 ) ;
F_45 ( V_1 -> V_10 ) ;
F_46 ( V_1 -> V_10 ) ;
if ( ! V_1 -> V_54 . V_76 )
V_1 -> V_54 . V_76 = V_77 ;
switch ( V_1 -> V_54 . V_76 ) {
case V_78 :
case V_77 :
F_3 ( V_1 -> V_5 , V_6 ,
V_79 ,
V_1 -> V_54 . V_76 - 1 ) ;
break;
case V_80 :
F_3 ( V_1 -> V_5 , V_6 ,
V_79 , 2 ) ;
break;
default:
F_8 ( V_1 -> V_10 , L_57 ,
V_1 -> V_54 . V_76 ) ;
V_2 = - V_61 ;
goto V_70;
}
for ( V_46 = 0 ; V_46 < V_81 ; V_46 ++ ) {
V_12 = V_1 -> V_54 . V_82 [ V_46 ]
<< V_83 ;
V_12 |= V_1 -> V_54 . V_84 [ V_46 ] << V_85 ;
F_3 ( V_1 -> V_5 ,
V_86 + ( V_46 * 8 ) ,
V_87 |
V_88 , V_12 ) ;
}
for ( V_46 = 0 ; V_46 < V_89 ; V_46 ++ ) {
if ( V_1 -> V_54 . V_90 [ V_46 ] )
V_12 = V_91 ;
else
V_12 = 0 ;
F_3 ( V_1 -> V_5 ,
V_92 + ( V_46 * 8 ) ,
V_91 , V_12 ) ;
}
for ( V_46 = 0 ; V_46 < V_93 ; V_46 ++ ) {
if ( V_1 -> V_54 . V_94 [ V_46 ] )
F_3 ( V_1 -> V_5 ,
V_95 + ( V_46 * 2 ) ,
V_96 |
V_97 ,
V_1 -> V_54 . V_94 [ V_46 ] ) ;
if ( V_1 -> V_54 . V_98 [ V_46 ] )
F_3 ( V_1 -> V_5 ,
V_99 + ( V_46 * 2 ) ,
V_100 ,
V_1 -> V_54 . V_98 [ V_46 ] ) ;
}
V_2 = F_47 ( V_1 ) ;
if ( V_2 != 0 )
goto V_70;
F_48 ( V_1 , V_101 , L_58 ,
F_7 , V_1 ) ;
F_48 ( V_1 , V_102 , L_59 ,
F_11 , V_1 ) ;
F_48 ( V_1 , V_103 , L_60 ,
F_9 , V_1 ) ;
switch ( V_1 -> type ) {
case V_55 :
V_2 = F_31 ( V_1 -> V_10 , - 1 , V_104 ,
F_30 ( V_104 ) , NULL , 0 , NULL ) ;
break;
case V_56 :
V_2 = F_31 ( V_1 -> V_10 , - 1 , V_105 ,
F_30 ( V_104 ) , NULL , 0 , NULL ) ;
break;
}
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_61 , V_2 ) ;
goto V_106;
}
#ifdef F_49
F_22 ( V_1 -> V_52 ) ;
#endif
return 0 ;
V_106:
F_50 ( V_1 ) ;
V_70:
if ( V_1 -> V_54 . V_65 ) {
F_38 ( V_1 -> V_54 . V_65 , 1 ) ;
F_51 ( V_1 -> V_54 . V_65 ) ;
}
V_68:
F_22 ( V_1 -> V_52 ) ;
V_64:
F_52 ( V_1 -> V_60 ,
V_1 -> V_58 ) ;
V_63:
F_53 ( V_10 ) ;
return V_2 ;
}
int T_3 F_54 ( struct V_1 * V_1 )
{
F_53 ( V_1 -> V_10 ) ;
F_55 ( V_1 , V_103 , V_1 ) ;
F_55 ( V_1 , V_102 , V_1 ) ;
F_55 ( V_1 , V_101 , V_1 ) ;
F_56 ( V_1 -> V_10 ) ;
F_50 ( V_1 ) ;
return 0 ;
}
