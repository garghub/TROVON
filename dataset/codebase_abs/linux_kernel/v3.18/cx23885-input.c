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
break;
default:
return;
}
V_3 = V_17 & ( V_31 |
V_32 ) ;
V_20 = V_17 & ( V_33 |
V_34 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
V_19 . V_36 = false ;
V_19 . V_37 = F_7 ( & V_2 -> V_38 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_39 , & V_19 ) ;
}
if ( V_20 )
F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 . V_36 = true ;
V_19 . V_37 = F_7 ( & V_2 -> V_38 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_39 , & V_19 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return - V_40 ;
F_9 ( & V_2 -> V_38 , 0 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
case V_28 :
V_19 . V_41 = V_42 ;
V_19 . V_36 = true ;
V_19 . V_43 = true ;
V_19 . V_37 = false ;
V_19 . V_44 = false ;
V_19 . V_45 = 3333333 ;
V_19 . V_46 = 333333 ;
V_19 . V_47 = true ;
break;
case V_25 :
case V_26 :
case V_29 :
case V_30 :
V_19 . V_41 = V_42 ;
V_19 . V_36 = true ;
V_19 . V_43 = true ;
V_19 . V_37 = false ;
V_19 . V_48 = 37917 ;
V_19 . V_49 = 33000 ;
V_19 . V_50 = 43000 ;
V_19 . V_51 = 33 ;
V_19 . V_45 = 12378022 ;
V_19 . V_46 = 351648 ;
V_19 . V_44 = false ;
V_19 . V_47 = true ;
break;
}
F_2 ( V_2 -> V_12 , V_13 , V_39 , & V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_52 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_53 ;
if ( V_5 -> V_54 == NULL )
return - V_40 ;
return F_8 ( V_5 -> V_54 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return;
F_9 ( & V_2 -> V_38 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
while ( V_19 . V_37 == false ) {
V_19 . V_36 = false ;
V_19 . V_43 = false ;
V_19 . V_37 = true ;
F_2 ( V_2 -> V_12 , V_13 , V_39 , & V_19 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
}
F_12 ( & V_2 -> V_55 ) ;
F_12 ( & V_2 -> V_56 ) ;
F_12 ( & V_2 -> V_57 ) ;
}
static void F_13 ( struct V_52 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_53 ;
if ( V_5 -> V_54 != NULL )
F_11 ( V_5 -> V_54 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_52 * V_16 ;
char * V_58 ;
enum V_59 V_60 ;
unsigned long V_61 ;
int V_62 ;
if ( V_2 -> V_12 == NULL )
return - V_40 ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
V_60 = V_63 ;
V_61 = V_64 ;
V_58 = V_65 ;
break;
case V_25 :
V_60 = V_63 ;
V_61 = V_66 ;
V_58 = V_67 ;
break;
case V_26 :
V_60 = V_63 ;
V_61 = V_64 ;
V_58 = V_68 ;
break;
case V_28 :
V_60 = V_63 ;
V_61 = V_64 ;
V_58 = V_69 ;
break;
case V_29 :
case V_30 :
V_60 = V_63 ;
V_61 = V_64 ;
V_58 = V_70 ;
break;
default:
return - V_40 ;
}
V_5 = F_15 ( sizeof( struct V_4 ) , V_71 ) ;
if ( V_5 == NULL )
return - V_72 ;
V_5 -> V_54 = V_2 ;
V_5 -> V_73 = F_16 ( V_71 , L_1 ,
V_74 [ V_2 -> V_21 ] . V_73 ) ;
V_5 -> V_75 = F_16 ( V_71 , L_2 ,
F_17 ( V_2 -> V_76 ) ) ;
V_16 = F_18 () ;
if ( ! V_16 ) {
V_62 = - V_72 ;
goto V_77;
}
V_5 -> V_16 = V_16 ;
V_16 -> V_78 = V_5 -> V_73 ;
V_16 -> V_79 = V_5 -> V_75 ;
V_16 -> V_80 . V_81 = V_82 ;
V_16 -> V_80 . V_83 = 1 ;
if ( V_2 -> V_76 -> V_84 ) {
V_16 -> V_80 . V_85 = V_2 -> V_76 -> V_84 ;
V_16 -> V_80 . V_86 = V_2 -> V_76 -> V_87 ;
} else {
V_16 -> V_80 . V_85 = V_2 -> V_76 -> V_85 ;
V_16 -> V_80 . V_86 = V_2 -> V_76 -> V_88 ;
}
V_16 -> V_2 . V_89 = & V_2 -> V_76 -> V_2 ;
V_16 -> V_60 = V_60 ;
V_16 -> V_90 = V_61 ;
V_16 -> V_53 = V_5 ;
V_16 -> V_91 = F_10 ;
V_16 -> V_92 = F_13 ;
V_16 -> V_93 = V_58 ;
V_16 -> V_94 = V_95 ;
V_2 -> V_5 = V_5 ;
V_62 = F_19 ( V_16 ) ;
if ( V_62 )
goto V_96;
return 0 ;
V_96:
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_20 ( V_16 ) ;
V_77:
F_21 ( V_5 -> V_75 ) ;
F_21 ( V_5 -> V_73 ) ;
F_21 ( V_5 ) ;
return V_62 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_5 == NULL )
return;
F_23 ( V_2 -> V_5 -> V_16 ) ;
F_21 ( V_2 -> V_5 -> V_75 ) ;
F_21 ( V_2 -> V_5 -> V_73 ) ;
F_21 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
