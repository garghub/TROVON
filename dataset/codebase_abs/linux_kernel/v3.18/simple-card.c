static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_13 ;
int V_14 = 0 ;
if ( V_11 -> V_15 ) {
V_13 = F_3 ( V_4 ) * V_11 -> V_15 ;
V_14 = F_4 ( V_9 , 0 , V_13 ,
V_16 ) ;
}
return V_14 ;
}
static int F_5 ( struct V_8 * V_17 ,
struct V_18 * V_19 )
{
int V_14 ;
if ( V_19 -> V_20 ) {
V_14 = F_6 ( V_17 , V_19 -> V_20 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_1 ) ;
goto V_23;
}
}
if ( V_19 -> V_24 ) {
V_14 = F_4 ( V_17 , 0 , V_19 -> V_24 , 0 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_2 ) ;
goto V_23;
}
}
if ( V_19 -> V_25 ) {
V_14 = F_8 ( V_17 , 0 , 0 ,
V_19 -> V_25 ,
V_19 -> V_26 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_7 ( V_17 -> V_22 , L_3 ) ;
goto V_23;
}
}
V_14 = 0 ;
V_23:
return V_14 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_2 ( V_6 -> V_12 ) ;
struct V_8 * V_27 = V_6 -> V_9 ;
struct V_8 * V_28 = V_6 -> V_29 ;
struct V_30 * V_31 ;
int V_32 , V_14 ;
V_32 = V_6 - V_6 -> V_12 -> V_6 ;
V_31 = & V_11 -> V_31 [ V_32 ] ;
V_14 = F_5 ( V_27 , & V_31 -> V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_28 , & V_31 -> V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_10 ( V_11 -> V_33 ) ) {
F_11 ( V_27 -> V_27 , L_4 , V_34 ,
& V_35 ) ;
F_12 ( & V_35 ,
F_13 ( V_36 ) ,
V_36 ) ;
V_37 . V_38 = V_11 -> V_33 ;
F_14 ( & V_35 , 1 ,
& V_37 ) ;
}
if ( F_10 ( V_11 -> V_39 ) ) {
F_11 ( V_27 -> V_27 , L_5 , V_40 ,
& V_41 ) ;
F_12 ( & V_41 ,
F_13 ( V_42 ) ,
V_42 ) ;
V_43 . V_38 = V_11 -> V_39 ;
F_14 ( & V_41 , 1 ,
& V_43 ) ;
}
return 0 ;
}
static int
F_15 ( struct V_44 * V_45 ,
struct V_18 * V_17 ,
struct V_44 * * V_46 ,
const char * * V_47 ,
int * V_48 )
{
struct V_49 args ;
struct V_50 * V_50 ;
T_1 V_51 ;
int V_14 ;
V_14 = F_16 ( V_45 , L_6 ,
L_7 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
* V_46 = args . V_45 ;
if ( V_48 )
* V_48 = args . V_48 ;
V_14 = F_17 ( V_45 , V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_18 ( V_45 , & V_17 -> V_25 , & V_17 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( F_19 ( V_45 , L_8 ) ) {
V_50 = F_20 ( V_45 , 0 ) ;
if ( F_21 ( V_50 ) ) {
V_14 = F_22 ( V_50 ) ;
return V_14 ;
}
V_17 -> V_24 = F_23 ( V_50 ) ;
} else if ( ! F_24 ( V_45 , L_9 , & V_51 ) ) {
V_17 -> V_24 = V_51 ;
} else {
V_50 = F_20 ( args . V_45 , 0 ) ;
if ( ! F_21 ( V_50 ) )
V_17 -> V_24 = F_23 ( V_50 ) ;
}
return 0 ;
}
static int F_25 ( struct V_44 * V_52 ,
struct V_10 * V_11 ,
int V_53 ,
bool V_54 )
{
struct V_55 * V_22 = F_26 ( V_11 ) ;
struct V_56 * V_57 = F_27 ( V_11 , V_53 ) ;
struct V_30 * V_31 = F_28 ( V_11 , V_53 ) ;
struct V_44 * V_45 = NULL ;
struct V_44 * V_58 = NULL ;
struct V_44 * V_59 = NULL ;
unsigned int V_60 ;
char * V_47 ;
char V_61 [ 128 ] ;
char * V_62 = L_10 ;
int V_14 , V_63 ;
if ( V_54 )
V_62 = L_11 ;
V_60 = F_29 ( V_52 , V_62 ,
& V_58 , & V_59 ) ;
V_60 &= ~ V_64 ;
snprintf ( V_61 , sizeof( V_61 ) , L_12 , V_62 ) ;
V_45 = F_30 ( V_52 , V_61 ) ;
if ( ! V_45 ) {
V_14 = - V_65 ;
F_7 ( V_22 , L_13 , V_66 , V_61 ) ;
goto V_67;
}
V_14 = F_15 ( V_45 , & V_31 -> V_29 ,
& V_57 -> V_68 ,
& V_57 -> V_69 ,
& V_63 ) ;
if ( V_14 < 0 )
goto V_67;
V_31 -> V_29 . V_20 = V_60 ;
switch ( ( ( V_45 == V_58 ) << 4 ) | ( V_45 == V_59 ) ) {
case 0x11 :
V_31 -> V_29 . V_20 |= V_70 ;
break;
case 0x10 :
V_31 -> V_29 . V_20 |= V_71 ;
break;
case 0x01 :
V_31 -> V_29 . V_20 |= V_72 ;
break;
default:
V_31 -> V_29 . V_20 |= V_73 ;
break;
}
F_31 ( V_45 ) ;
snprintf ( V_61 , sizeof( V_61 ) , L_14 , V_62 ) ;
V_45 = F_30 ( V_52 , V_61 ) ;
if ( ! V_45 ) {
V_14 = - V_65 ;
F_7 ( V_22 , L_13 , V_66 , V_61 ) ;
goto V_67;
}
V_14 = F_15 ( V_45 , & V_31 -> V_9 ,
& V_57 -> V_74 ,
& V_57 -> V_75 , NULL ) ;
if ( V_14 < 0 )
goto V_67;
if ( strlen ( V_62 ) && ! V_58 && ! V_59 ) {
F_32 ( V_22 , L_15 ,
V_66 ) ;
V_31 -> V_29 . V_20 = V_31 -> V_9 . V_20 =
F_29 ( V_45 , NULL , NULL , NULL ) |
( V_60 & ~ V_76 ) ;
} else {
V_31 -> V_9 . V_20 = V_60 ;
switch ( ( ( V_45 == V_58 ) << 4 ) | ( V_45 == V_59 ) ) {
case 0x11 :
V_31 -> V_9 . V_20 |= V_73 ;
break;
case 0x10 :
V_31 -> V_9 . V_20 |= V_72 ;
break;
case 0x01 :
V_31 -> V_9 . V_20 |= V_71 ;
break;
default:
V_31 -> V_9 . V_20 |= V_70 ;
break;
}
}
if ( ! V_57 -> V_69 || ! V_57 -> V_75 ) {
V_14 = - V_65 ;
goto V_67;
}
V_57 -> V_77 = V_57 -> V_68 ;
V_47 = F_33 ( V_22 ,
strlen ( V_57 -> V_69 ) +
strlen ( V_57 -> V_75 ) + 2 ,
V_78 ) ;
sprintf ( V_47 , L_16 , V_57 -> V_69 ,
V_57 -> V_75 ) ;
V_57 -> V_47 = V_57 -> V_79 = V_47 ;
V_57 -> V_80 = & V_81 ;
V_57 -> V_82 = F_9 ;
F_32 ( V_22 , L_17 , V_57 -> V_79 ) ;
F_32 ( V_22 , L_18 ,
V_57 -> V_69 ,
V_31 -> V_29 . V_20 ,
V_31 -> V_29 . V_24 ) ;
F_32 ( V_22 , L_19 ,
V_57 -> V_75 ,
V_31 -> V_9 . V_20 ,
V_31 -> V_9 . V_24 ) ;
if ( ! V_63 )
V_57 -> V_69 = NULL ;
V_67:
if ( V_45 )
F_31 ( V_45 ) ;
if ( V_58 )
F_31 ( V_58 ) ;
if ( V_59 )
F_31 ( V_59 ) ;
return V_14 ;
}
static int F_34 ( struct V_44 * V_52 ,
struct V_10 * V_11 )
{
struct V_55 * V_22 = F_26 ( V_11 ) ;
T_1 V_51 ;
int V_14 ;
if ( ! V_52 )
return - V_65 ;
F_35 ( & V_11 -> V_83 , L_20 ) ;
if ( F_19 ( V_52 , L_21 ) ) {
V_14 = F_36 ( & V_11 -> V_83 ,
L_21 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_19 ( V_52 , L_22 ) ) {
V_14 = F_37 ( & V_11 -> V_83 ,
L_22 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_24 ( V_52 , L_23 , & V_51 ) ;
if ( V_14 == 0 )
V_11 -> V_15 = V_51 ;
F_32 ( V_22 , L_24 , V_11 -> V_83 . V_47 ?
V_11 -> V_83 . V_47 : L_10 ) ;
if ( F_30 ( V_52 , L_25 ) ) {
struct V_44 * V_45 = NULL ;
int V_84 = 0 ;
F_38 (node, np) {
F_32 ( V_22 , L_26 , V_84 ) ;
V_14 = F_25 ( V_45 , V_11 ,
V_84 , false ) ;
if ( V_14 < 0 ) {
F_31 ( V_45 ) ;
return V_14 ;
}
V_84 ++ ;
}
} else {
V_14 = F_25 ( V_52 , V_11 , 0 , true ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_11 -> V_33 = F_39 ( V_52 ,
L_27 , 0 ) ;
if ( V_11 -> V_33 == - V_85 )
return - V_85 ;
V_11 -> V_39 = F_39 ( V_52 ,
L_28 , 0 ) ;
if ( V_11 -> V_39 == - V_85 )
return - V_85 ;
if ( ! V_11 -> V_83 . V_47 )
V_11 -> V_83 . V_47 = V_11 -> V_83 . V_57 -> V_47 ;
return 0 ;
}
static int F_40 ( struct V_86 * V_87 )
{
struct V_88 * V_12 = F_41 ( V_87 ) ;
struct V_56 * V_57 ;
struct V_44 * V_45 ;
int V_89 ;
for ( V_89 = 0 , V_57 = V_12 -> V_57 ;
V_89 < V_12 -> V_89 ;
V_89 ++ , V_57 ++ ) {
V_45 = (struct V_44 * ) V_57 -> V_68 ;
if ( V_45 )
F_31 ( V_45 ) ;
V_45 = (struct V_44 * ) V_57 -> V_74 ;
if ( V_45 )
F_31 ( V_45 ) ;
}
return 0 ;
}
static int F_42 ( struct V_86 * V_87 )
{
struct V_10 * V_11 ;
struct V_56 * V_57 ;
struct V_44 * V_45 = V_87 -> V_22 . V_90 ;
struct V_55 * V_22 = & V_87 -> V_22 ;
int V_89 , V_14 ;
if ( V_45 && F_30 ( V_45 , L_25 ) )
V_89 = F_43 ( V_45 ) ;
else
V_89 = 1 ;
V_11 = F_33 ( V_22 ,
sizeof( * V_11 ) + sizeof( * V_57 ) * V_89 ,
V_78 ) ;
if ( ! V_11 )
return - V_91 ;
V_11 -> V_83 . V_92 = V_93 ;
V_11 -> V_83 . V_22 = V_22 ;
V_57 = V_11 -> V_57 ;
V_11 -> V_83 . V_57 = V_57 ;
V_11 -> V_83 . V_89 = V_89 ;
V_11 -> V_33 = - V_94 ;
V_11 -> V_39 = - V_94 ;
V_11 -> V_31 = F_33 ( V_22 ,
sizeof( * V_11 -> V_31 ) * V_89 ,
V_78 ) ;
if ( ! V_11 -> V_31 )
return - V_91 ;
if ( V_45 && F_44 ( V_45 ) ) {
V_14 = F_34 ( V_45 , V_11 ) ;
if ( V_14 < 0 ) {
if ( V_14 != - V_85 )
F_7 ( V_22 , L_29 , V_14 ) ;
goto V_23;
}
} else {
struct V_95 * V_96 ;
V_96 = V_22 -> V_97 ;
if ( ! V_96 ) {
F_7 ( V_22 , L_30 ) ;
return - V_65 ;
}
if ( ! V_96 -> V_47 ||
! V_96 -> V_9 . V_47 ||
! V_96 -> V_27 ||
! V_96 -> V_98 ||
! V_96 -> V_29 . V_47 ) {
F_7 ( V_22 , L_31 ) ;
return - V_65 ;
}
V_11 -> V_83 . V_47 = ( V_96 -> V_12 ) ? V_96 -> V_12 : V_96 -> V_47 ;
V_57 -> V_47 = V_96 -> V_47 ;
V_57 -> V_79 = V_96 -> V_47 ;
V_57 -> V_99 = V_96 -> V_98 ;
V_57 -> V_100 = V_96 -> V_27 ;
V_57 -> V_69 = V_96 -> V_29 . V_47 ;
V_57 -> V_75 = V_96 -> V_9 . V_47 ;
V_57 -> V_82 = F_9 ;
memcpy ( & V_11 -> V_31 -> V_29 , & V_96 -> V_29 ,
sizeof( V_11 -> V_31 -> V_29 ) ) ;
memcpy ( & V_11 -> V_31 -> V_9 , & V_96 -> V_9 ,
sizeof( V_11 -> V_31 -> V_9 ) ) ;
V_11 -> V_31 -> V_29 . V_20 |= V_96 -> V_60 ;
V_11 -> V_31 -> V_9 . V_20 |= V_96 -> V_60 ;
}
F_45 ( & V_11 -> V_83 , V_11 ) ;
V_14 = F_46 ( & V_87 -> V_22 , & V_11 -> V_83 ) ;
if ( V_14 >= 0 )
return V_14 ;
V_23:
F_40 ( V_87 ) ;
return V_14 ;
}
static int F_47 ( struct V_86 * V_87 )
{
struct V_88 * V_12 = F_41 ( V_87 ) ;
struct V_10 * V_11 = F_2 ( V_12 ) ;
if ( F_10 ( V_11 -> V_33 ) )
F_48 ( & V_35 , 1 ,
& V_37 ) ;
if ( F_10 ( V_11 -> V_39 ) )
F_48 ( & V_41 , 1 ,
& V_43 ) ;
return F_40 ( V_87 ) ;
}
