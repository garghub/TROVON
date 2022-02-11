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
break;
default:
return;
}
V_3 = V_17 & ( V_28 |
V_29 ) ;
V_20 = V_17 & ( V_30 |
V_31 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_12 , V_13 , V_32 , & V_19 ) ;
V_19 . V_33 = false ;
V_19 . V_34 = F_7 ( & V_2 -> V_35 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_36 , & V_19 ) ;
}
if ( V_20 )
F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 . V_33 = true ;
V_19 . V_34 = F_7 ( & V_2 -> V_35 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_36 , & V_19 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return - V_37 ;
F_9 ( & V_2 -> V_35 , 0 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_32 , & V_19 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
V_19 . V_38 = V_39 ;
V_19 . V_33 = true ;
V_19 . V_40 = true ;
V_19 . V_34 = false ;
V_19 . V_41 = false ;
V_19 . V_42 = 3333333 ;
V_19 . V_43 = 333333 ;
V_19 . V_44 = true ;
break;
case V_25 :
case V_26 :
V_19 . V_38 = V_39 ;
V_19 . V_33 = true ;
V_19 . V_40 = true ;
V_19 . V_34 = false ;
V_19 . V_45 = 37917 ;
V_19 . V_46 = 33000 ;
V_19 . V_47 = 43000 ;
V_19 . V_48 = 33 ;
V_19 . V_42 = 12378022 ;
V_19 . V_43 = 351648 ;
V_19 . V_41 = false ;
V_19 . V_44 = true ;
break;
}
F_2 ( V_2 -> V_12 , V_13 , V_36 , & V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_49 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_50 ;
if ( V_5 -> V_51 == NULL )
return - V_37 ;
return F_8 ( V_5 -> V_51 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return;
F_9 ( & V_2 -> V_35 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_32 , & V_19 ) ;
while ( V_19 . V_34 == false ) {
V_19 . V_33 = false ;
V_19 . V_40 = false ;
V_19 . V_34 = true ;
F_2 ( V_2 -> V_12 , V_13 , V_36 , & V_19 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_32 , & V_19 ) ;
}
F_12 ( & V_2 -> V_52 ) ;
F_12 ( & V_2 -> V_53 ) ;
F_12 ( & V_2 -> V_54 ) ;
}
static void F_13 ( struct V_49 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_50 ;
if ( V_5 -> V_51 != NULL )
F_11 ( V_5 -> V_51 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_49 * V_16 ;
char * V_55 ;
enum V_56 V_57 ;
unsigned long V_58 ;
int V_59 ;
if ( V_2 -> V_12 == NULL )
return - V_37 ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
V_57 = V_60 ;
V_58 = V_61 ;
V_55 = V_62 ;
break;
case V_25 :
V_57 = V_60 ;
V_58 = V_63 ;
V_55 = V_64 ;
break;
case V_26 :
V_57 = V_60 ;
V_58 = V_61 ;
V_55 = V_65 ;
break;
default:
return - V_37 ;
}
V_5 = F_15 ( sizeof( struct V_4 ) , V_66 ) ;
if ( V_5 == NULL )
return - V_67 ;
V_5 -> V_51 = V_2 ;
V_5 -> V_68 = F_16 ( V_66 , L_1 ,
V_69 [ V_2 -> V_21 ] . V_68 ) ;
V_5 -> V_70 = F_16 ( V_66 , L_2 ,
F_17 ( V_2 -> V_71 ) ) ;
V_16 = F_18 () ;
if ( ! V_16 ) {
V_59 = - V_67 ;
goto V_72;
}
V_5 -> V_16 = V_16 ;
V_16 -> V_73 = V_5 -> V_68 ;
V_16 -> V_74 = V_5 -> V_70 ;
V_16 -> V_75 . V_76 = V_77 ;
V_16 -> V_75 . V_78 = 1 ;
if ( V_2 -> V_71 -> V_79 ) {
V_16 -> V_75 . V_80 = V_2 -> V_71 -> V_79 ;
V_16 -> V_75 . V_81 = V_2 -> V_71 -> V_82 ;
} else {
V_16 -> V_75 . V_80 = V_2 -> V_71 -> V_80 ;
V_16 -> V_75 . V_81 = V_2 -> V_71 -> V_83 ;
}
V_16 -> V_2 . V_84 = & V_2 -> V_71 -> V_2 ;
V_16 -> V_57 = V_57 ;
V_16 -> V_58 = V_58 ;
V_16 -> V_50 = V_5 ;
V_16 -> V_85 = F_10 ;
V_16 -> V_86 = F_13 ;
V_16 -> V_87 = V_55 ;
V_16 -> V_88 = V_89 ;
V_2 -> V_5 = V_5 ;
V_59 = F_19 ( V_16 ) ;
if ( V_59 )
goto V_90;
return 0 ;
V_90:
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_20 ( V_16 ) ;
V_72:
F_21 ( V_5 -> V_70 ) ;
F_21 ( V_5 -> V_68 ) ;
F_21 ( V_5 ) ;
return V_59 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_5 == NULL )
return;
F_23 ( V_2 -> V_5 -> V_16 ) ;
F_21 ( V_2 -> V_5 -> V_70 ) ;
F_21 ( V_2 -> V_5 -> V_68 ) ;
F_21 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
