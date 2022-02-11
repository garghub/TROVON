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
break;
default:
return;
}
V_3 = V_17 & ( V_26 |
V_27 ) ;
V_20 = V_17 & ( V_28 |
V_29 ) ;
if ( V_3 ) {
F_2 ( V_2 -> V_12 , V_13 , V_30 , & V_19 ) ;
V_19 . V_31 = false ;
V_19 . V_32 = F_7 ( & V_2 -> V_33 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_34 , & V_19 ) ;
}
if ( V_20 )
F_1 ( V_2 , V_3 ) ;
if ( V_3 ) {
V_19 . V_31 = true ;
V_19 . V_32 = F_7 ( & V_2 -> V_33 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_34 , & V_19 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return - V_35 ;
F_9 ( & V_2 -> V_33 , 0 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_30 , & V_19 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_25 :
V_19 . V_36 = V_37 ;
V_19 . V_31 = true ;
V_19 . V_38 = true ;
V_19 . V_32 = false ;
V_19 . V_39 = false ;
V_19 . V_40 = 3333333 ;
V_19 . V_41 = 333333 ;
V_19 . V_42 = true ;
break;
case V_24 :
V_19 . V_36 = V_37 ;
V_19 . V_31 = true ;
V_19 . V_38 = true ;
V_19 . V_32 = false ;
V_19 . V_43 = 37917 ;
V_19 . V_44 = 33000 ;
V_19 . V_45 = 43000 ;
V_19 . V_46 = 33 ;
V_19 . V_40 = 12378022 ;
V_19 . V_41 = 351648 ;
V_19 . V_39 = false ;
V_19 . V_42 = true ;
break;
}
F_2 ( V_2 -> V_12 , V_13 , V_34 , & V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_47 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_48 ;
if ( V_5 -> V_49 == NULL )
return - V_35 ;
return F_8 ( V_5 -> V_49 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_18 V_19 ;
if ( V_2 -> V_12 == NULL )
return;
F_9 ( & V_2 -> V_33 , 1 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_30 , & V_19 ) ;
while ( V_19 . V_32 == false ) {
V_19 . V_31 = false ;
V_19 . V_38 = false ;
V_19 . V_32 = true ;
F_2 ( V_2 -> V_12 , V_13 , V_34 , & V_19 ) ;
F_2 ( V_2 -> V_12 , V_13 , V_30 , & V_19 ) ;
}
}
static void F_12 ( struct V_47 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_48 ;
if ( V_5 -> V_49 != NULL )
F_11 ( V_5 -> V_49 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_47 * V_16 ;
char * V_50 ;
enum V_51 V_52 ;
unsigned long V_53 ;
int V_54 ;
if ( V_2 -> V_12 == NULL )
return - V_35 ;
switch ( V_2 -> V_21 ) {
case V_22 :
case V_23 :
case V_25 :
V_52 = V_55 ;
V_53 = V_56 ;
V_50 = V_57 ;
break;
case V_24 :
V_52 = V_55 ;
V_53 = V_56 ;
V_50 = V_58 ;
break;
default:
return - V_35 ;
}
V_5 = F_14 ( sizeof( struct V_4 ) , V_59 ) ;
if ( V_5 == NULL )
return - V_60 ;
V_5 -> V_49 = V_2 ;
V_5 -> V_61 = F_15 ( V_59 , L_1 ,
V_62 [ V_2 -> V_21 ] . V_61 ) ;
V_5 -> V_63 = F_15 ( V_59 , L_2 ,
F_16 ( V_2 -> V_64 ) ) ;
V_16 = F_17 () ;
if ( ! V_16 ) {
V_54 = - V_60 ;
goto V_65;
}
V_5 -> V_16 = V_16 ;
V_16 -> V_66 = V_5 -> V_61 ;
V_16 -> V_67 = V_5 -> V_63 ;
V_16 -> V_68 . V_69 = V_70 ;
V_16 -> V_68 . V_71 = 1 ;
if ( V_2 -> V_64 -> V_72 ) {
V_16 -> V_68 . V_73 = V_2 -> V_64 -> V_72 ;
V_16 -> V_68 . V_74 = V_2 -> V_64 -> V_75 ;
} else {
V_16 -> V_68 . V_73 = V_2 -> V_64 -> V_73 ;
V_16 -> V_68 . V_74 = V_2 -> V_64 -> V_76 ;
}
V_16 -> V_2 . V_77 = & V_2 -> V_64 -> V_2 ;
V_16 -> V_52 = V_52 ;
V_16 -> V_53 = V_53 ;
V_16 -> V_48 = V_5 ;
V_16 -> V_78 = F_10 ;
V_16 -> V_79 = F_12 ;
V_16 -> V_80 = V_50 ;
V_16 -> V_81 = V_82 ;
V_2 -> V_5 = V_5 ;
V_54 = F_18 ( V_16 ) ;
if ( V_54 )
goto V_83;
return 0 ;
V_83:
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_19 ( V_16 ) ;
V_65:
F_20 ( V_5 -> V_63 ) ;
F_20 ( V_5 -> V_61 ) ;
F_20 ( V_5 ) ;
return V_54 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_5 == NULL )
return;
F_22 ( V_2 -> V_5 -> V_16 ) ;
F_20 ( V_2 -> V_5 -> V_63 ) ;
F_20 ( V_2 -> V_5 -> V_61 ) ;
F_20 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
