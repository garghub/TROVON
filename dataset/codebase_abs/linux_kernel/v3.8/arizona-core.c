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
if ( V_12 & V_24 )
F_8 ( V_1 -> V_10 , L_12 ) ;
return V_11 ;
}
static T_1 F_11 ( int V_8 , void * V_9 )
{
struct V_1 * V_1 = V_9 ;
unsigned int V_12 [ 2 ] ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_5 , V_25 ,
& V_12 [ 0 ] , 2 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_13 ,
V_2 ) ;
return V_14 ;
}
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
if ( V_12 [ 0 ] & V_35 )
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
if ( V_12 [ 1 ] & V_45 )
F_8 ( V_1 -> V_10 , L_33 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_1 )
{
unsigned int V_46 ;
int V_2 , V_47 ;
for ( V_47 = 0 ; V_47 < 5 ; V_47 ++ ) {
F_14 ( 1 ) ;
V_2 = F_10 ( V_1 -> V_5 ,
V_48 , & V_46 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_34 ,
V_2 ) ;
continue;
}
if ( V_46 & V_49 )
break;
}
if ( V_46 & V_49 ) {
F_15 ( V_1 -> V_5 , V_50 ,
V_49 ) ;
} else {
F_8 ( V_1 -> V_10 , L_35 , V_46 ) ;
return - V_51 ;
}
F_16 ( V_1 -> V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_52 * V_10 )
{
struct V_1 * V_1 = F_18 ( V_10 ) ;
int V_2 ;
F_19 ( V_1 -> V_10 , L_36 ) ;
V_2 = F_20 ( V_1 -> V_53 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_37 , V_2 ) ;
return V_2 ;
}
F_21 ( V_1 -> V_5 , false ) ;
V_2 = F_13 ( V_1 ) ;
if ( V_2 != 0 ) {
F_22 ( V_1 -> V_53 ) ;
return V_2 ;
}
V_2 = F_23 ( V_1 -> V_5 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_38 ) ;
F_22 ( V_1 -> V_53 ) ;
return V_2 ;
}
return 0 ;
}
static int F_24 ( struct V_52 * V_10 )
{
struct V_1 * V_1 = F_18 ( V_10 ) ;
F_19 ( V_1 -> V_10 , L_39 ) ;
F_22 ( V_1 -> V_53 ) ;
F_21 ( V_1 -> V_5 , true ) ;
F_25 ( V_1 -> V_5 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_1 )
{
struct V_52 * V_10 = V_1 -> V_10 ;
const char * V_54 ;
unsigned int V_46 , V_12 ;
int (* F_27)( struct V_1 * ) = NULL ;
int V_2 , V_47 ;
F_28 ( V_1 -> V_10 , V_1 ) ;
F_29 ( & V_1 -> V_3 ) ;
if ( F_30 ( V_1 -> V_10 ) )
memcpy ( & V_1 -> V_55 , F_30 ( V_1 -> V_10 ) ,
sizeof( V_1 -> V_55 ) ) ;
F_21 ( V_1 -> V_5 , true ) ;
switch ( V_1 -> type ) {
case V_56 :
case V_57 :
for ( V_47 = 0 ; V_47 < F_31 ( V_58 ) ; V_47 ++ )
V_1 -> V_59 [ V_47 ] . V_60
= V_58 [ V_47 ] ;
V_1 -> V_61 = F_31 ( V_58 ) ;
break;
default:
F_8 ( V_1 -> V_10 , L_40 ,
V_1 -> type ) ;
return - V_62 ;
}
V_2 = F_32 ( V_1 -> V_10 , - 1 , V_63 ,
F_31 ( V_63 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_41 , V_2 ) ;
return V_2 ;
}
V_2 = F_33 ( V_10 , V_1 -> V_61 ,
V_1 -> V_59 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_42 ,
V_2 ) ;
goto V_64;
}
V_1 -> V_53 = F_34 ( V_1 -> V_10 , L_43 ) ;
if ( F_35 ( V_1 -> V_53 ) ) {
V_2 = F_36 ( V_1 -> V_53 ) ;
F_8 ( V_10 , L_44 , V_2 ) ;
goto V_64;
}
V_2 = F_37 ( V_1 -> V_61 ,
V_1 -> V_59 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_45 ,
V_2 ) ;
goto V_64;
}
V_2 = F_20 ( V_1 -> V_53 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_37 , V_2 ) ;
goto V_65;
}
if ( V_1 -> V_55 . V_66 ) {
V_2 = F_38 ( V_1 -> V_55 . V_66 ,
V_67 | V_68 ,
L_46 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_47 , V_2 ) ;
goto V_69;
}
F_39 ( V_1 -> V_55 . V_66 , 1 ) ;
}
F_21 ( V_1 -> V_5 , false ) ;
V_2 = F_10 ( V_1 -> V_5 , V_70 , & V_46 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_48 , V_2 ) ;
goto V_71;
}
V_2 = F_10 ( V_1 -> V_5 , V_72 ,
& V_1 -> V_73 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_49 , V_2 ) ;
goto V_71;
}
V_1 -> V_73 &= V_74 ;
switch ( V_46 ) {
#ifdef F_40
case 0x5102 :
V_54 = L_50 ;
if ( V_1 -> type != V_56 ) {
F_8 ( V_1 -> V_10 , L_51 ,
V_1 -> type ) ;
V_1 -> type = V_56 ;
}
F_27 = V_75 ;
break;
#endif
#ifdef F_41
case 0x5110 :
V_54 = L_52 ;
if ( V_1 -> type != V_57 ) {
F_8 ( V_1 -> V_10 , L_53 ,
V_1 -> type ) ;
V_1 -> type = V_57 ;
}
F_27 = V_76 ;
break;
#endif
default:
F_8 ( V_1 -> V_10 , L_54 , V_46 ) ;
goto V_71;
}
F_42 ( V_10 , L_55 , V_54 , V_1 -> V_73 + 'A' ) ;
if ( ! V_1 -> V_55 . V_66 ) {
F_25 ( V_1 -> V_5 ) ;
V_2 = F_15 ( V_1 -> V_5 , V_70 , 0 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_56 , V_2 ) ;
goto V_71;
}
V_2 = F_23 ( V_1 -> V_5 ) ;
if ( V_2 != 0 ) {
F_8 ( V_10 , L_57 , V_2 ) ;
goto V_71;
}
}
V_2 = F_13 ( V_1 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_58 , V_2 ) ;
goto V_71;
}
if ( F_27 ) {
V_2 = F_27 ( V_1 ) ;
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_59 ,
V_2 ) ;
goto V_71;
}
}
for ( V_47 = 0 ; V_47 < F_31 ( V_1 -> V_55 . V_77 ) ; V_47 ++ ) {
if ( ! V_1 -> V_55 . V_77 [ V_47 ] )
continue;
F_15 ( V_1 -> V_5 , V_78 + V_47 ,
V_1 -> V_55 . V_77 [ V_47 ] ) ;
}
F_43 ( V_1 -> V_10 , 100 ) ;
F_44 ( V_1 -> V_10 ) ;
F_45 ( V_1 -> V_10 ) ;
if ( ! V_1 -> V_55 . V_79 )
V_1 -> V_55 . V_79 = V_80 ;
switch ( V_1 -> V_55 . V_79 ) {
case V_81 :
case V_80 :
F_3 ( V_1 -> V_5 , V_6 ,
V_82 ,
V_1 -> V_55 . V_79 - 1 ) ;
break;
case V_83 :
F_3 ( V_1 -> V_5 , V_6 ,
V_82 , 2 ) ;
break;
default:
F_8 ( V_1 -> V_10 , L_60 ,
V_1 -> V_55 . V_79 ) ;
V_2 = - V_62 ;
goto V_71;
}
for ( V_47 = 0 ; V_47 < V_84 ; V_47 ++ ) {
V_12 = V_1 -> V_55 . V_85 [ V_47 ]
<< V_86 ;
V_12 |= V_1 -> V_55 . V_87 [ V_47 ] << V_88 ;
F_3 ( V_1 -> V_5 ,
V_89 + ( V_47 * 8 ) ,
V_90 |
V_91 , V_12 ) ;
}
for ( V_47 = 0 ; V_47 < V_92 ; V_47 ++ ) {
if ( V_1 -> V_55 . V_93 [ V_47 ] )
V_12 = V_94 ;
else
V_12 = 0 ;
F_3 ( V_1 -> V_5 ,
V_95 + ( V_47 * 8 ) ,
V_94 , V_12 ) ;
}
for ( V_47 = 0 ; V_47 < V_96 ; V_47 ++ ) {
if ( V_1 -> V_55 . V_97 [ V_47 ] )
F_3 ( V_1 -> V_5 ,
V_98 + ( V_47 * 2 ) ,
V_99 |
V_100 ,
V_1 -> V_55 . V_97 [ V_47 ] ) ;
if ( V_1 -> V_55 . V_101 [ V_47 ] )
F_3 ( V_1 -> V_5 ,
V_102 + ( V_47 * 2 ) ,
V_103 ,
V_1 -> V_55 . V_101 [ V_47 ] ) ;
}
V_2 = F_46 ( V_1 ) ;
if ( V_2 != 0 )
goto V_71;
F_47 ( V_1 , V_104 , L_61 ,
F_7 , V_1 ) ;
F_47 ( V_1 , V_105 , L_62 ,
F_11 , V_1 ) ;
F_47 ( V_1 , V_106 , L_63 ,
F_9 , V_1 ) ;
switch ( V_1 -> type ) {
case V_56 :
V_2 = F_32 ( V_1 -> V_10 , - 1 , V_107 ,
F_31 ( V_107 ) , NULL , 0 , NULL ) ;
break;
case V_57 :
V_2 = F_32 ( V_1 -> V_10 , - 1 , V_108 ,
F_31 ( V_108 ) , NULL , 0 , NULL ) ;
break;
}
if ( V_2 != 0 ) {
F_8 ( V_1 -> V_10 , L_64 , V_2 ) ;
goto V_109;
}
#ifdef F_48
F_22 ( V_1 -> V_53 ) ;
#endif
return 0 ;
V_109:
F_49 ( V_1 ) ;
V_71:
if ( V_1 -> V_55 . V_66 ) {
F_39 ( V_1 -> V_55 . V_66 , 1 ) ;
F_50 ( V_1 -> V_55 . V_66 ) ;
}
V_69:
F_22 ( V_1 -> V_53 ) ;
V_65:
F_51 ( V_1 -> V_61 ,
V_1 -> V_59 ) ;
V_64:
F_52 ( V_10 ) ;
return V_2 ;
}
int F_53 ( struct V_1 * V_1 )
{
F_52 ( V_1 -> V_10 ) ;
F_54 ( V_1 , V_106 , V_1 ) ;
F_54 ( V_1 , V_105 , V_1 ) ;
F_54 ( V_1 , V_104 , V_1 ) ;
F_55 ( V_1 -> V_10 ) ;
F_49 ( V_1 ) ;
return 0 ;
}
