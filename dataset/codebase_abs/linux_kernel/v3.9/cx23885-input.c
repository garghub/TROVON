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
break;
default:
return;
}
V_3 = V_17 & ( V_29 |
V_30 ) ;
V_20 = V_17 & ( V_31 |
V_32 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_12 , V_13 , V_33 , & V_19 ) ;
V_19 . V_34 = false ;
V_19 . V_35 = F_7 ( & V_2 -> V_36 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_37 , & V_19 ) ;
}
if ( V_20 )
F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 . V_34 = true ;
V_19 . V_35 = F_7 ( & V_2 -> V_36 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_37 , & V_19 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return - V_38 ;
F_9 ( & V_2 -> V_36 , 0 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_33 , & V_19 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
case V_28 :
V_19 . V_39 = V_40 ;
V_19 . V_34 = true ;
V_19 . V_41 = true ;
V_19 . V_35 = false ;
V_19 . V_42 = false ;
V_19 . V_43 = 3333333 ;
V_19 . V_44 = 333333 ;
V_19 . V_45 = true ;
break;
case V_25 :
case V_26 :
V_19 . V_39 = V_40 ;
V_19 . V_34 = true ;
V_19 . V_41 = true ;
V_19 . V_35 = false ;
V_19 . V_46 = 37917 ;
V_19 . V_47 = 33000 ;
V_19 . V_48 = 43000 ;
V_19 . V_49 = 33 ;
V_19 . V_43 = 12378022 ;
V_19 . V_44 = 351648 ;
V_19 . V_42 = false ;
V_19 . V_45 = true ;
break;
}
F_2 ( V_2 -> V_12 , V_13 , V_37 , & V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_50 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_51 ;
if ( V_5 -> V_52 == NULL )
return - V_38 ;
return F_8 ( V_5 -> V_52 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return;
F_9 ( & V_2 -> V_36 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_33 , & V_19 ) ;
while ( V_19 . V_35 == false ) {
V_19 . V_34 = false ;
V_19 . V_41 = false ;
V_19 . V_35 = true ;
F_2 ( V_2 -> V_12 , V_13 , V_37 , & V_19 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_33 , & V_19 ) ;
}
F_12 ( & V_2 -> V_53 ) ;
F_12 ( & V_2 -> V_54 ) ;
F_12 ( & V_2 -> V_55 ) ;
}
static void F_13 ( struct V_50 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_51 ;
if ( V_5 -> V_52 != NULL )
F_11 ( V_5 -> V_52 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_50 * V_16 ;
char * V_56 ;
enum V_57 V_58 ;
unsigned long V_59 ;
int V_60 ;
if ( V_2 -> V_12 == NULL )
return - V_38 ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
V_58 = V_61 ;
V_59 = V_62 ;
V_56 = V_63 ;
break;
case V_25 :
V_58 = V_61 ;
V_59 = V_64 ;
V_56 = V_65 ;
break;
case V_26 :
V_58 = V_61 ;
V_59 = V_62 ;
V_56 = V_66 ;
break;
case V_28 :
V_58 = V_61 ;
V_59 = V_62 ;
V_56 = V_67 ;
break;
default:
return - V_38 ;
}
V_5 = F_15 ( sizeof( struct V_4 ) , V_68 ) ;
if ( V_5 == NULL )
return - V_69 ;
V_5 -> V_52 = V_2 ;
V_5 -> V_70 = F_16 ( V_68 , L_1 ,
V_71 [ V_2 -> V_21 ] . V_70 ) ;
V_5 -> V_72 = F_16 ( V_68 , L_2 ,
F_17 ( V_2 -> V_73 ) ) ;
V_16 = F_18 () ;
if ( ! V_16 ) {
V_60 = - V_69 ;
goto V_74;
}
V_5 -> V_16 = V_16 ;
V_16 -> V_75 = V_5 -> V_70 ;
V_16 -> V_76 = V_5 -> V_72 ;
V_16 -> V_77 . V_78 = V_79 ;
V_16 -> V_77 . V_80 = 1 ;
if ( V_2 -> V_73 -> V_81 ) {
V_16 -> V_77 . V_82 = V_2 -> V_73 -> V_81 ;
V_16 -> V_77 . V_83 = V_2 -> V_73 -> V_84 ;
} else {
V_16 -> V_77 . V_82 = V_2 -> V_73 -> V_82 ;
V_16 -> V_77 . V_83 = V_2 -> V_73 -> V_85 ;
}
V_16 -> V_2 . V_86 = & V_2 -> V_73 -> V_2 ;
V_16 -> V_58 = V_58 ;
V_16 -> V_59 = V_59 ;
V_16 -> V_51 = V_5 ;
V_16 -> V_87 = F_10 ;
V_16 -> V_88 = F_13 ;
V_16 -> V_89 = V_56 ;
V_16 -> V_90 = V_91 ;
V_2 -> V_5 = V_5 ;
V_60 = F_19 ( V_16 ) ;
if ( V_60 )
goto V_92;
return 0 ;
V_92:
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_20 ( V_16 ) ;
V_74:
F_21 ( V_5 -> V_72 ) ;
F_21 ( V_5 -> V_70 ) ;
F_21 ( V_5 ) ;
return V_60 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_5 == NULL )
return;
F_23 ( V_2 -> V_5 -> V_16 ) ;
F_21 ( V_2 -> V_5 -> V_72 ) ;
F_21 ( V_2 -> V_5 -> V_70 ) ;
F_21 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
