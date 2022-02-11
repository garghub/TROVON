static T_1 F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( F_3 ( * V_1 ) ) ;
V_3 = V_4 & V_2 ;
V_4 &= ~ V_2 ;
F_4 ( * V_1 , F_5 ( V_4 ) ) ;
return V_3 ;
}
static void F_6 ( struct V_5 * V_6 , void * V_7 )
{
struct V_8 * V_9 = F_7 ( V_6 ) ;
if ( V_9 -> V_10 )
* V_9 -> V_10 = ( ( V_11 * ) V_7 ) [ 1 ] ;
if ( V_9 -> V_5 . V_12 )
F_8 ( & V_9 -> V_13 ) ;
}
static void F_9 ( struct V_5 * V_6 , void * V_14 )
{
struct V_8 * V_9 = F_7 ( V_6 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
if ( ! F_1 ( & V_16 -> V_18 ,
V_19 ) )
return;
if ( F_1 ( & V_16 -> V_18 ,
V_20 ) ) {
V_14 = V_16 + 1 ;
if ( V_9 -> V_10 )
* V_9 -> V_10 = ( ( V_11 * ) V_14 ) [ 1 ] ;
F_8 ( & V_9 -> V_13 ) ;
}
}
static void F_10 ( struct V_8 * V_9 , V_11 * V_14 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
V_11 * V_21 = ( void * ) ( V_16 + 1 ) ;
T_1 V_18 ;
int V_22 ;
F_4 ( V_16 -> V_23 ,
F_11 ( V_24 | V_9 -> V_25 ) ) ;
F_4 ( V_16 -> V_26 ,
F_5 ( F_12 ( V_14 [ 0 ] ) | V_27 ) ) ;
V_18 = F_2 ( F_3 ( V_16 -> V_18 ) ) ;
V_18 &= ~ V_20 ;
F_4 ( V_16 -> V_18 , F_5 ( V_18 ) ) ;
for ( V_22 = 0 ; V_22 < V_28 ; V_22 ++ )
F_4 ( V_21 [ V_22 ] , F_11 ( V_14 [ V_22 ] ) ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
if ( V_9 -> V_5 . V_12 || ! V_29 ) {
if ( ! F_14 ( & V_9 -> V_13 ,
F_15 ( V_30 ) ) )
return - V_31 ;
}
if ( * V_9 -> V_10 == 0xffffffff )
return - V_32 ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 ,
V_11 * V_14 ,
V_11 * V_33 )
{
int V_34 ;
V_9 -> V_10 = V_33 ;
if ( ! V_29 ) {
F_17 ( & V_9 -> V_13 ) ;
F_10 ( V_9 , V_14 ) ;
}
V_34 = F_18 ( V_9 -> V_35 , V_14 ) ;
if ( V_34 < 0 )
goto V_36;
V_34 = F_13 ( V_9 ) ;
V_36:
if ( ! V_29 )
F_19 ( V_9 -> V_35 , 0 ) ;
V_9 -> V_10 = NULL ;
return V_34 ;
}
static int F_20 ( struct V_8 * V_9 , V_11 V_37 ,
V_11 V_1 , V_11 V_38 , V_11 V_39 ,
V_11 V_40 , V_11 * V_33 )
{
V_11 V_14 [ 3 ] ;
V_14 [ 0 ] = F_21 ( V_41 , V_37 ,
V_42 , V_39 , V_38 , V_40 ) ;
V_14 [ 1 ] = F_22 ( V_1 ) ;
V_14 [ 2 ] = 0 ;
return F_16 ( V_9 , V_14 , V_33 ) ;
}
static int F_23 ( struct V_8 * V_9 , V_11 V_37 ,
V_11 V_1 , V_11 V_38 , V_11 V_39 , V_11 V_43 ,
V_11 V_33 )
{
V_11 V_14 [ 3 ] ;
V_14 [ 0 ] = F_21 ( V_41 , V_37 ,
V_44 , V_39 , V_38 , V_43 ) ;
V_14 [ 1 ] = F_22 ( V_1 ) ;
V_14 [ 2 ] = V_33 ;
return F_16 ( V_9 , V_14 , V_14 ) ;
}
static int F_24 ( struct V_8 * V_9 , V_11 V_37 , V_11 V_1 ,
V_11 V_38 , V_11 V_39 , V_11 V_40 ,
V_11 V_45 , void * V_33 )
{
T_2 V_46 ;
V_11 V_14 [ 3 ] ;
int V_34 ;
V_46 = F_25 ( V_9 -> V_47 , V_9 -> V_48 , V_40 , V_49 ) ;
if ( F_26 ( V_9 -> V_47 , V_46 ) ) {
F_27 ( & V_9 -> V_50 . V_47 , L_1 ,
V_9 -> V_48 ) ;
return - V_51 ;
}
V_14 [ 0 ] = F_21 ( V_41 , V_37 , V_42 ,
V_39 , V_38 , V_40 ) ;
V_14 [ 1 ] = V_52 |
F_28 ( V_45 ) |
F_29 ( V_46 ) |
F_22 ( V_1 ) ;
V_14 [ 2 ] = ( V_11 ) V_46 ;
V_34 = F_16 ( V_9 , V_14 , V_14 ) ;
memcpy ( V_33 , V_9 -> V_48 , V_40 ) ;
F_30 ( V_9 -> V_47 , V_46 , V_40 , V_49 ) ;
return V_34 ;
}
static int F_31 ( struct V_8 * V_9 , V_11 V_37 ,
V_11 V_1 , V_11 V_38 , V_11 V_39 , V_11 V_43 ,
void * V_33 )
{
T_2 V_46 ;
V_11 V_14 [ 3 ] ;
int V_34 ;
memcpy ( V_9 -> V_48 , V_33 , V_43 ) ;
V_46 = F_25 ( V_9 -> V_47 , V_9 -> V_48 , V_43 ,
V_53 ) ;
if ( F_26 ( V_9 -> V_47 , V_46 ) ) {
F_27 ( & V_9 -> V_50 . V_47 , L_1 ,
V_9 -> V_48 ) ;
return - V_51 ;
}
V_14 [ 0 ] = F_21 ( V_41 , V_37 , V_44 ,
V_39 , V_38 , V_43 ) ;
V_14 [ 1 ] = V_52 |
F_29 ( V_46 ) |
F_22 ( V_1 ) ;
V_14 [ 2 ] = ( V_11 ) V_46 ;
if ( V_9 -> V_5 . V_12 )
F_17 ( & V_9 -> V_13 ) ;
V_34 = F_16 ( V_9 , V_14 , V_14 ) ;
F_30 ( V_9 -> V_47 , V_46 , V_43 , V_53 ) ;
return V_34 ;
}
static int F_32 ( struct V_54 * V_55 , T_1 V_1 ,
unsigned short V_56 , char V_57 ,
T_3 V_26 , int V_58 ,
union V_59 * V_33 )
{
struct V_8 * V_9 = F_33 ( V_55 ) ;
int V_3 = - V_60 ;
V_11 V_4 ;
switch ( V_58 ) {
case V_61 :
if ( V_57 == V_62 ) {
V_3 = F_20 ( V_9 , V_1 , 0 , 0 ,
V_63 ,
V_64 , & V_4 ) ;
V_33 -> V_65 = V_4 ;
} else {
V_3 = F_23 ( V_9 , V_1 , V_26 , V_66 ,
V_63 ,
0 , 0 ) ;
}
break;
case V_67 :
if ( V_57 == V_62 ) {
V_3 = F_20 ( V_9 , V_1 , V_26 , V_66 ,
V_63 ,
V_64 , & V_4 ) ;
V_33 -> V_65 = V_4 ;
} else {
V_4 = V_33 -> V_65 ;
V_3 = F_23 ( V_9 , V_1 , V_26 , V_66 ,
V_63 ,
V_64 , V_4 ) ;
}
break;
case V_68 :
if ( V_57 == V_62 ) {
V_3 = F_20 ( V_9 , V_1 , V_26 , V_66 ,
V_63 ,
V_69 , & V_4 ) ;
V_33 -> V_70 = V_4 ;
} else {
V_4 = V_33 -> V_70 ;
V_3 = F_23 ( V_9 , V_1 , V_26 , V_66 ,
V_63 ,
V_69 , V_4 ) ;
}
break;
case V_71 :
if ( V_57 == V_62 ) {
V_3 = F_24 ( V_9 , V_1 , V_26 ,
V_66 ,
V_63 ,
V_72 + 1 ,
V_73 ,
& V_33 -> V_74 [ 0 ] ) ;
} else {
V_3 = F_31 ( V_9 , V_1 , V_26 ,
V_66 ,
V_63 ,
V_33 -> V_74 [ 0 ] + 1 ,
& V_33 -> V_74 [ 0 ] ) ;
}
break;
case V_75 :
if ( V_57 == V_62 ) {
V_3 = F_24 ( V_9 , V_1 ,
V_26 ,
V_66 ,
V_76 ,
V_72 ,
V_77 ,
& V_33 -> V_74 [ 1 ] ) ;
} else {
V_3 = F_31 ( V_9 , V_1 , V_26 ,
V_66 ,
V_76 ,
V_33 -> V_74 [ 0 ] ,
& V_33 -> V_74 [ 1 ] ) ;
}
break;
default:
break;
}
return V_3 ;
}
static V_11 F_34 ( struct V_54 * V_50 )
{
return V_78 |
V_79 |
V_80 |
V_81 |
V_82 ;
}
static int F_35 ( struct V_83 * V_84 )
{
struct V_8 * V_9 ;
struct V_54 * V_50 ;
struct V_5 * V_6 ;
int V_34 ;
V_9 = F_36 ( & V_84 -> V_47 , sizeof( * V_9 ) , V_85 ) ;
if ( ! V_9 )
return - V_51 ;
V_9 -> V_47 = & V_84 -> V_47 ;
F_37 ( V_84 , V_9 ) ;
V_6 = & V_9 -> V_5 ;
V_6 -> V_47 = & V_84 -> V_47 ;
F_38 ( & V_9 -> V_13 ) ;
V_6 -> V_86 = V_30 ;
V_6 -> V_87 = false ;
if ( V_29 ) {
V_6 -> V_12 = true ;
V_6 -> V_88 = F_6 ;
V_9 -> V_35 = F_39 ( V_6 , V_89 ) ;
if ( F_40 ( V_9 -> V_35 ) ) {
F_27 ( & V_84 -> V_47 , L_2 ) ;
return F_41 ( V_9 -> V_35 ) ;
}
} else {
struct V_90 * V_91 ;
if ( F_42 ( & V_84 -> V_47 , L_3 ,
& V_9 -> V_25 ) )
V_9 -> V_25 = V_89 ;
V_6 -> V_12 = false ;
V_6 -> V_88 = F_9 ;
V_9 -> V_35 = F_43 ( V_6 , V_9 -> V_25 ) ;
if ( F_40 ( V_9 -> V_35 ) ) {
F_27 ( & V_84 -> V_47 , L_4 ) ;
return F_41 ( V_9 -> V_35 ) ;
}
V_91 = V_9 -> V_35 -> V_92 ;
if ( ! V_91 ) {
F_27 ( & V_84 -> V_47 , L_5 ) ;
V_34 = - V_93 ;
goto V_94;
}
if ( ! V_9 -> V_35 -> V_95 -> V_96 ) {
F_27 ( & V_84 -> V_47 , L_6 ) ;
V_34 = - V_93 ;
goto V_94;
}
V_9 -> V_97 = V_91 -> V_98 ;
if ( V_9 -> V_97 ) {
V_9 -> V_17 = F_44 ( V_9 -> V_97 ,
V_91 -> V_99 ,
V_100 ) ;
} else {
F_27 ( & V_84 -> V_47 , L_7 ) ;
V_34 = - V_93 ;
goto V_94;
}
if ( ! V_9 -> V_17 ) {
F_27 ( & V_84 -> V_47 ,
L_8 ) ;
V_34 = - V_51 ;
goto V_94;
}
}
V_34 = F_45 ( & V_84 -> V_47 , F_46 ( 64 ) ) ;
if ( V_34 )
F_47 ( & V_84 -> V_47 , L_9 ) ;
V_50 = & V_9 -> V_50 ;
snprintf ( V_50 -> V_101 , sizeof( V_50 -> V_101 ) , L_10 ) ;
V_50 -> V_102 = & V_103 ;
V_50 -> V_104 = V_105 ;
V_50 -> V_47 . V_106 = & V_84 -> V_47 ;
V_50 -> V_47 . V_107 = V_84 -> V_47 . V_107 ;
F_48 ( & V_50 -> V_47 , F_49 ( & V_84 -> V_47 ) ) ;
F_50 ( V_50 , V_9 ) ;
V_34 = F_51 ( V_50 ) ;
if ( V_34 )
goto V_94;
F_52 ( & V_84 -> V_47 , L_11 ) ;
return 0 ;
V_94:
if ( V_29 )
F_53 ( V_9 -> V_35 ) ;
else
F_54 ( V_9 -> V_35 ) ;
return V_34 ;
}
static int F_55 ( struct V_83 * V_84 )
{
struct V_8 * V_9 = F_56 ( V_84 ) ;
F_57 ( & V_9 -> V_50 ) ;
if ( V_29 )
F_53 ( V_9 -> V_35 ) ;
else
F_54 ( V_9 -> V_35 ) ;
return 0 ;
}
