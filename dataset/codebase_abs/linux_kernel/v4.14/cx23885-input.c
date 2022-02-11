static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 ;
int V_7 , V_8 ;
bool V_9 = false ;
struct V_10 V_11 [ 64 ] ;
do {
V_6 = 0 ;
F_2 ( V_2 -> V_12 , V_13 , V_14 , ( V_15 * ) V_11 ,
sizeof( V_11 ) , & V_6 ) ;
V_7 = V_6 / sizeof( struct V_10 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
F_3 ( V_5 -> V_16 ,
& V_11 [ V_8 ] ) ;
V_9 = true ;
}
} while ( V_6 != 0 );
if ( V_3 )
F_4 ( V_5 -> V_16 ) ;
else if ( V_9 )
F_5 ( V_5 -> V_16 ) ;
}
void F_6 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_18 V_19 ;
int V_3 , V_20 ;
if ( V_2 -> V_12 == NULL || V_17 == 0 )
return;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
break;
default:
return;
}
V_3 = V_17 & ( V_38 |
V_39 ) ;
V_20 = V_17 & ( V_40 |
V_41 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_12 , V_13 , V_42 , & V_19 ) ;
V_19 . V_43 = false ;
V_19 . V_44 = F_7 ( & V_2 -> V_45 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_46 , & V_19 ) ;
}
if ( V_20 )
F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 . V_43 = true ;
V_19 . V_44 = F_7 ( & V_2 -> V_45 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_46 , & V_19 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return - V_47 ;
F_9 ( & V_2 -> V_45 , 0 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_42 , & V_19 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
case V_28 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_19 . V_48 = V_49 ;
V_19 . V_43 = true ;
V_19 . V_50 = true ;
V_19 . V_44 = false ;
V_19 . V_51 = false ;
V_19 . V_52 = 3333333 ;
V_19 . V_53 = 333333 ;
V_19 . V_54 = true ;
break;
case V_25 :
case V_26 :
case V_29 :
case V_30 :
V_19 . V_48 = V_49 ;
V_19 . V_43 = true ;
V_19 . V_50 = true ;
V_19 . V_44 = false ;
V_19 . V_55 = 37917 ;
V_19 . V_56 = 33000 ;
V_19 . V_57 = 43000 ;
V_19 . V_58 = 33 ;
V_19 . V_52 = 12378022 ;
V_19 . V_53 = 351648 ;
V_19 . V_51 = false ;
V_19 . V_54 = true ;
break;
}
F_2 ( V_2 -> V_12 , V_13 , V_46 , & V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_59 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_60 ;
if ( V_5 -> V_61 == NULL )
return - V_47 ;
return F_8 ( V_5 -> V_61 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return;
F_9 ( & V_2 -> V_45 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_42 , & V_19 ) ;
while ( V_19 . V_44 == false ) {
V_19 . V_43 = false ;
V_19 . V_50 = false ;
V_19 . V_44 = true ;
F_2 ( V_2 -> V_12 , V_13 , V_46 , & V_19 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_42 , & V_19 ) ;
}
F_12 ( & V_2 -> V_62 ) ;
F_12 ( & V_2 -> V_63 ) ;
F_12 ( & V_2 -> V_64 ) ;
}
static void F_13 ( struct V_59 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_60 ;
if ( V_5 -> V_61 != NULL )
F_11 ( V_5 -> V_61 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_59 * V_16 ;
char * V_65 ;
T_3 V_66 ;
int V_67 ;
if ( V_2 -> V_12 == NULL )
return - V_47 ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
V_66 = V_68 ;
V_65 = V_69 ;
break;
case V_25 :
V_66 = V_68 ;
V_65 = V_70 ;
break;
case V_26 :
V_66 = V_68 ;
V_65 = V_71 ;
break;
case V_28 :
V_66 = V_68 ;
V_65 = V_72 ;
break;
case V_29 :
case V_30 :
V_66 = V_68 ;
V_65 = V_73 ;
break;
case V_31 :
case V_32 :
case V_33 :
case V_35 :
case V_36 :
case V_37 :
V_66 = V_68 ;
V_65 = V_74 ;
break;
case V_34 :
V_66 = V_68 ;
V_65 = V_75 ;
break;
default:
return - V_47 ;
}
V_5 = F_15 ( sizeof( struct V_4 ) , V_76 ) ;
if ( V_5 == NULL )
return - V_77 ;
V_5 -> V_61 = V_2 ;
V_5 -> V_78 = F_16 ( V_76 , L_1 ,
V_79 [ V_2 -> V_21 ] . V_78 ) ;
V_5 -> V_80 = F_16 ( V_76 , L_2 ,
F_17 ( V_2 -> V_81 ) ) ;
V_16 = F_18 ( V_82 ) ;
if ( ! V_16 ) {
V_67 = - V_77 ;
goto V_83;
}
V_5 -> V_16 = V_16 ;
V_16 -> V_84 = V_5 -> V_78 ;
V_16 -> V_85 = V_5 -> V_80 ;
V_16 -> V_86 . V_87 = V_88 ;
V_16 -> V_86 . V_89 = 1 ;
if ( V_2 -> V_81 -> V_90 ) {
V_16 -> V_86 . V_91 = V_2 -> V_81 -> V_90 ;
V_16 -> V_86 . V_92 = V_2 -> V_81 -> V_93 ;
} else {
V_16 -> V_86 . V_91 = V_2 -> V_81 -> V_91 ;
V_16 -> V_86 . V_92 = V_2 -> V_81 -> V_94 ;
}
V_16 -> V_2 . V_95 = & V_2 -> V_81 -> V_2 ;
V_16 -> V_96 = V_66 ;
V_16 -> V_60 = V_5 ;
V_16 -> V_97 = F_10 ;
V_16 -> V_98 = F_13 ;
V_16 -> V_99 = V_65 ;
V_16 -> V_100 = V_101 ;
V_2 -> V_5 = V_5 ;
V_67 = F_19 ( V_16 ) ;
if ( V_67 )
goto V_102;
return 0 ;
V_102:
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_20 ( V_16 ) ;
V_83:
F_21 ( V_5 -> V_80 ) ;
F_21 ( V_5 -> V_78 ) ;
F_21 ( V_5 ) ;
return V_67 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_5 == NULL )
return;
F_23 ( V_2 -> V_5 -> V_16 ) ;
F_21 ( V_2 -> V_5 -> V_80 ) ;
F_21 ( V_2 -> V_5 -> V_78 ) ;
F_21 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
