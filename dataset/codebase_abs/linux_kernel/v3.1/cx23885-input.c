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
break;
default:
return;
}
V_3 = V_17 & ( V_27 |
V_28 ) ;
V_20 = V_17 & ( V_29 |
V_30 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_12 , V_13 , V_31 , & V_19 ) ;
V_19 . V_32 = false ;
V_19 . V_33 = F_7 ( & V_2 -> V_34 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
}
if ( V_20 )
F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 . V_32 = true ;
V_19 . V_33 = F_7 ( & V_2 -> V_34 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return - V_36 ;
F_9 ( & V_2 -> V_34 , 0 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_31 , & V_19 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_26 :
V_19 . V_37 = V_38 ;
V_19 . V_32 = true ;
V_19 . V_39 = true ;
V_19 . V_33 = false ;
V_19 . V_40 = false ;
V_19 . V_41 = 3333333 ;
V_19 . V_42 = 333333 ;
V_19 . V_43 = true ;
break;
case V_25 :
V_19 . V_37 = V_38 ;
V_19 . V_32 = true ;
V_19 . V_39 = true ;
V_19 . V_33 = false ;
V_19 . V_44 = 37917 ;
V_19 . V_45 = 33000 ;
V_19 . V_46 = 43000 ;
V_19 . V_47 = 33 ;
V_19 . V_41 = 12378022 ;
V_19 . V_42 = 351648 ;
V_19 . V_40 = false ;
V_19 . V_43 = true ;
break;
}
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_48 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_49 ;
if ( V_5 -> V_50 == NULL )
return - V_36 ;
return F_8 ( V_5 -> V_50 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return;
F_9 ( & V_2 -> V_34 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_31 , & V_19 ) ;
while ( V_19 . V_33 == false ) {
V_19 . V_32 = false ;
V_19 . V_39 = false ;
V_19 . V_33 = true ;
F_2 ( V_2 -> V_12 , V_13 , V_35 , & V_19 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_31 , & V_19 ) ;
}
F_12 ( & V_2 -> V_51 ) ;
F_12 ( & V_2 -> V_52 ) ;
F_12 ( & V_2 -> V_53 ) ;
}
static void F_13 ( struct V_48 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_49 ;
if ( V_5 -> V_50 != NULL )
F_11 ( V_5 -> V_50 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_48 * V_16 ;
char * V_54 ;
enum V_55 V_56 ;
unsigned long V_57 ;
int V_58 ;
if ( V_2 -> V_12 == NULL )
return - V_36 ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_26 :
V_56 = V_59 ;
V_57 = V_60 ;
V_54 = V_61 ;
break;
case V_25 :
V_56 = V_59 ;
V_57 = V_60 ;
V_54 = V_62 ;
break;
default:
return - V_36 ;
}
V_5 = F_15 ( sizeof( struct V_4 ) , V_63 ) ;
if ( V_5 == NULL )
return - V_64 ;
V_5 -> V_50 = V_2 ;
V_5 -> V_65 = F_16 ( V_63 , L_1 ,
V_66 [ V_2 -> V_21 ] . V_65 ) ;
V_5 -> V_67 = F_16 ( V_63 , L_2 ,
F_17 ( V_2 -> V_68 ) ) ;
V_16 = F_18 () ;
if ( ! V_16 ) {
V_58 = - V_64 ;
goto V_69;
}
V_5 -> V_16 = V_16 ;
V_16 -> V_70 = V_5 -> V_65 ;
V_16 -> V_71 = V_5 -> V_67 ;
V_16 -> V_72 . V_73 = V_74 ;
V_16 -> V_72 . V_75 = 1 ;
if ( V_2 -> V_68 -> V_76 ) {
V_16 -> V_72 . V_77 = V_2 -> V_68 -> V_76 ;
V_16 -> V_72 . V_78 = V_2 -> V_68 -> V_79 ;
} else {
V_16 -> V_72 . V_77 = V_2 -> V_68 -> V_77 ;
V_16 -> V_72 . V_78 = V_2 -> V_68 -> V_80 ;
}
V_16 -> V_2 . V_81 = & V_2 -> V_68 -> V_2 ;
V_16 -> V_56 = V_56 ;
V_16 -> V_57 = V_57 ;
V_16 -> V_49 = V_5 ;
V_16 -> V_82 = F_10 ;
V_16 -> V_83 = F_13 ;
V_16 -> V_84 = V_54 ;
V_16 -> V_85 = V_86 ;
V_2 -> V_5 = V_5 ;
V_58 = F_19 ( V_16 ) ;
if ( V_58 )
goto V_87;
return 0 ;
V_87:
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_20 ( V_16 ) ;
V_69:
F_21 ( V_5 -> V_67 ) ;
F_21 ( V_5 -> V_65 ) ;
F_21 ( V_5 ) ;
return V_58 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_5 == NULL )
return;
F_23 ( V_2 -> V_5 -> V_16 ) ;
F_21 ( V_2 -> V_5 -> V_67 ) ;
F_21 ( V_2 -> V_5 -> V_65 ) ;
F_21 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
