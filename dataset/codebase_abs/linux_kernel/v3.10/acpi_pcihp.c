static T_1
F_1 ( union V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
union V_1 * V_6 = V_2 -> V_7 . V_8 ;
T_2 V_9 = V_6 [ 1 ] . integer . V_10 ;
switch ( V_9 ) {
case 1 :
if ( V_2 -> V_7 . V_11 != 6 )
return V_12 ;
for ( V_5 = 2 ; V_5 < 6 ; V_5 ++ )
if ( V_6 [ V_5 ] . type != V_13 )
return V_12 ;
V_4 -> V_14 = & V_4 -> V_15 ;
V_4 -> V_14 -> V_9 = V_9 ;
V_4 -> V_14 -> V_16 = V_6 [ 2 ] . integer . V_10 ;
V_4 -> V_14 -> V_17 = V_6 [ 3 ] . integer . V_10 ;
V_4 -> V_14 -> V_18 = V_6 [ 4 ] . integer . V_10 ;
V_4 -> V_14 -> V_19 = V_6 [ 5 ] . integer . V_10 ;
break;
default:
F_2 ( V_20
L_1 ,
V_21 , V_9 ) ;
return V_12 ;
}
return V_22 ;
}
static T_1
F_3 ( union V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
union V_1 * V_6 = V_2 -> V_7 . V_8 ;
T_2 V_9 = V_6 [ 1 ] . integer . V_10 ;
switch ( V_9 ) {
case 1 :
if ( V_2 -> V_7 . V_11 != 5 )
return V_12 ;
for ( V_5 = 2 ; V_5 < 5 ; V_5 ++ )
if ( V_6 [ V_5 ] . type != V_13 )
return V_12 ;
V_4 -> V_23 = & V_4 -> V_24 ;
V_4 -> V_23 -> V_9 = V_9 ;
V_4 -> V_23 -> V_25 = V_6 [ 2 ] . integer . V_10 ;
V_4 -> V_23 -> V_26 = V_6 [ 3 ] . integer . V_10 ;
V_4 -> V_23 -> V_27 = V_6 [ 4 ] . integer . V_10 ;
break;
default:
F_2 ( V_20
L_2 ,
V_21 , V_9 ) ;
return V_12 ;
}
return V_22 ;
}
static T_1
F_4 ( union V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
union V_1 * V_6 = V_2 -> V_7 . V_8 ;
T_2 V_9 = V_6 [ 1 ] . integer . V_10 ;
switch ( V_9 ) {
case 1 :
if ( V_2 -> V_7 . V_11 != 18 )
return V_12 ;
for ( V_5 = 2 ; V_5 < 18 ; V_5 ++ )
if ( V_6 [ V_5 ] . type != V_13 )
return V_12 ;
V_4 -> V_28 = & V_4 -> V_29 ;
V_4 -> V_28 -> V_9 = V_9 ;
V_4 -> V_28 -> V_30 = V_6 [ 2 ] . integer . V_10 ;
V_4 -> V_28 -> V_31 = V_6 [ 3 ] . integer . V_10 ;
V_4 -> V_28 -> V_32 = V_6 [ 4 ] . integer . V_10 ;
V_4 -> V_28 -> V_33 = V_6 [ 5 ] . integer . V_10 ;
V_4 -> V_28 -> V_34 = V_6 [ 6 ] . integer . V_10 ;
V_4 -> V_28 -> V_35 = V_6 [ 7 ] . integer . V_10 ;
V_4 -> V_28 -> V_36 = V_6 [ 8 ] . integer . V_10 ;
V_4 -> V_28 -> V_37 = V_6 [ 9 ] . integer . V_10 ;
V_4 -> V_28 -> V_38 = V_6 [ 10 ] . integer . V_10 ;
V_4 -> V_28 -> V_39 = V_6 [ 11 ] . integer . V_10 ;
V_4 -> V_28 -> V_40 = V_6 [ 12 ] . integer . V_10 ;
V_4 -> V_28 -> V_41 = V_6 [ 13 ] . integer . V_10 ;
V_4 -> V_28 -> V_42 = V_6 [ 14 ] . integer . V_10 ;
V_4 -> V_28 -> V_43 = V_6 [ 15 ] . integer . V_10 ;
V_4 -> V_28 -> V_44 = V_6 [ 16 ] . integer . V_10 ;
V_4 -> V_28 -> V_45 = V_6 [ 17 ] . integer . V_10 ;
break;
default:
F_2 ( V_20
L_3 ,
V_21 , V_9 ) ;
return V_12 ;
}
return V_22 ;
}
static T_1
F_5 ( T_3 V_46 , struct V_3 * V_4 )
{
T_1 V_47 ;
struct V_48 V_49 = { V_50 , NULL } ;
union V_1 * V_7 , * V_2 , * V_6 ;
T_2 type ;
int V_5 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_47 = F_6 ( V_46 , L_4 , NULL , & V_49 ) ;
if ( F_7 ( V_47 ) )
return V_47 ;
V_7 = (union V_1 * ) V_49 . V_51 ;
if ( V_7 -> type != V_52 ) {
V_47 = V_12 ;
goto exit;
}
for ( V_5 = 0 ; V_5 < V_7 -> V_7 . V_11 ; V_5 ++ ) {
V_2 = & V_7 -> V_7 . V_8 [ V_5 ] ;
if ( V_2 -> type != V_52 ) {
V_47 = V_12 ;
goto exit;
}
V_6 = V_2 -> V_7 . V_8 ;
if ( V_6 [ 0 ] . type != V_13 ||
V_6 [ 1 ] . type != V_13 ) {
V_47 = V_12 ;
goto exit;
}
type = V_6 [ 0 ] . integer . V_10 ;
switch ( type ) {
case 0 :
V_47 = F_1 ( V_2 , V_4 ) ;
if ( F_7 ( V_47 ) )
goto exit;
break;
case 1 :
V_47 = F_3 ( V_2 , V_4 ) ;
if ( F_7 ( V_47 ) )
goto exit;
break;
case 2 :
V_47 = F_4 ( V_2 , V_4 ) ;
if ( F_7 ( V_47 ) )
goto exit;
break;
default:
F_2 ( V_53 L_5 ,
V_21 , type ) ;
V_47 = V_12 ;
goto exit;
}
}
exit:
F_8 ( V_49 . V_51 ) ;
return V_47 ;
}
static T_1
F_9 ( T_3 V_46 , struct V_3 * V_54 )
{
T_1 V_47 ;
struct V_48 V_49 = { V_50 , NULL } ;
union V_1 * V_7 , * V_6 ;
int V_5 ;
memset ( V_54 , 0 , sizeof( struct V_3 ) ) ;
V_47 = F_6 ( V_46 , L_6 , NULL , & V_49 ) ;
if ( F_7 ( V_47 ) )
return V_47 ;
V_7 = (union V_1 * ) V_49 . V_51 ;
if ( V_7 -> type != V_52 ||
V_7 -> V_7 . V_11 != 4 ) {
V_47 = V_12 ;
goto exit;
}
V_6 = V_7 -> V_7 . V_8 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( V_6 [ V_5 ] . type != V_13 ) {
V_47 = V_12 ;
goto exit;
}
}
V_54 -> V_14 = & V_54 -> V_15 ;
V_54 -> V_14 -> V_9 = 1 ;
V_54 -> V_14 -> V_16 = V_6 [ 0 ] . integer . V_10 ;
V_54 -> V_14 -> V_17 = V_6 [ 1 ] . integer . V_10 ;
V_54 -> V_14 -> V_18 = V_6 [ 2 ] . integer . V_10 ;
V_54 -> V_14 -> V_19 = V_6 [ 3 ] . integer . V_10 ;
exit:
F_8 ( V_49 . V_51 ) ;
return V_47 ;
}
static T_1 F_10 ( T_3 V_46 )
{
T_1 V_47 ;
struct V_48 string = { V_50 , NULL } ;
F_11 ( V_46 , V_55 , & string ) ;
V_47 = F_6 ( V_46 , V_56 , NULL , NULL ) ;
if ( F_7 ( V_47 ) )
if ( V_47 != V_57 )
F_2 ( V_53 L_7 ,
V_21 , ( char * ) string . V_51 , V_47 ) ;
else
F_12 ( L_8 ,
V_21 , ( char * ) string . V_51 ) ;
else
F_13 ( L_9 , V_21 ,
( char * ) string . V_51 ) ;
F_8 ( string . V_51 ) ;
return V_47 ;
}
int F_14 ( struct V_58 * V_59 , struct V_3 * V_54 )
{
T_1 V_47 ;
T_3 V_46 , V_60 ;
struct V_61 * V_62 ;
V_46 = NULL ;
for ( V_62 = V_59 -> V_63 ; V_62 ; V_62 = V_62 -> V_64 ) {
V_46 = F_15 ( V_62 ) ;
if ( V_46 )
break;
}
while ( V_46 ) {
V_47 = F_5 ( V_46 , V_54 ) ;
if ( F_16 ( V_47 ) )
return 0 ;
V_47 = F_9 ( V_46 , V_54 ) ;
if ( F_16 ( V_47 ) )
return 0 ;
if ( F_17 ( V_46 ) )
break;
V_47 = F_18 ( V_46 , & V_60 ) ;
if ( F_7 ( V_47 ) )
break;
V_46 = V_60 ;
}
return - V_65 ;
}
int F_19 ( struct V_58 * V_66 , T_2 V_67 )
{
T_1 V_47 ;
T_3 V_68 , V_46 ;
struct V_48 string = { V_50 , NULL } ;
V_67 &= V_69 ;
if ( ! V_67 ) {
F_20 ( L_10 , V_67 ) ;
return - V_70 ;
}
V_46 = F_21 ( V_66 ) ;
if ( V_46 ) {
F_11 ( V_46 , V_55 , & string ) ;
F_12 ( L_11 ,
( char * ) string . V_51 ) ;
V_47 = F_22 ( V_46 , & V_67 , V_67 ) ;
if ( F_16 ( V_47 ) )
goto V_71;
if ( V_47 == V_72 )
goto V_73;
F_8 ( string . V_51 ) ;
string = (struct V_48 ) { V_50 , NULL } ;
}
V_46 = F_23 ( & V_66 -> V_59 ) ;
if ( ! V_46 ) {
struct V_61 * V_62 ;
for ( V_62 = V_66 -> V_63 ; V_62 ; V_62 = V_62 -> V_64 ) {
V_46 = F_15 ( V_62 ) ;
if ( V_46 )
break;
}
}
while ( V_46 ) {
F_11 ( V_46 , V_55 , & string ) ;
F_12 ( L_12 ,
( char * ) string . V_51 ) ;
V_47 = F_10 ( V_46 ) ;
if ( F_16 ( V_47 ) )
goto V_71;
if ( F_17 ( V_46 ) )
break;
V_68 = V_46 ;
V_47 = F_18 ( V_68 , & V_46 ) ;
if ( F_7 ( V_47 ) )
break;
}
V_73:
F_12 ( L_13 ,
F_24 ( V_66 ) ) ;
F_8 ( string . V_51 ) ;
return - V_65 ;
V_71:
F_12 ( L_14 ,
F_24 ( V_66 ) , ( char * ) string . V_51 ) ;
F_8 ( string . V_51 ) ;
return 0 ;
}
static int F_25 ( T_3 V_46 )
{
T_1 V_47 ;
T_3 V_74 ;
unsigned long long V_75 ;
V_47 = F_26 ( V_46 , L_15 , & V_74 ) ;
if ( F_7 ( V_47 ) )
return 0 ;
V_47 = F_26 ( V_46 , L_16 , & V_74 ) ;
if ( F_16 ( V_47 ) )
return 1 ;
V_47 = F_27 ( V_46 , L_17 , NULL , & V_75 ) ;
if ( F_16 ( V_47 ) && V_75 )
return 1 ;
return 0 ;
}
int F_28 ( struct V_61 * V_62 , T_3 V_46 )
{
T_3 V_76 , V_77 ;
if ( ! ( V_76 = F_15 ( V_62 ) ) )
return 0 ;
if ( ( F_7 ( F_18 ( V_46 , & V_77 ) ) ) )
return 0 ;
if ( V_76 != V_77 )
return 0 ;
return F_25 ( V_46 ) ;
}
static T_1
F_29 ( T_3 V_46 , T_2 V_78 , void * V_79 , void * * V_80 )
{
int * V_81 = ( int * ) V_79 ;
if ( F_25 ( V_46 ) ) {
* V_81 = 1 ;
return V_82 ;
}
return V_22 ;
}
int F_30 ( T_3 V_46 )
{
int V_81 = 0 ;
if ( ! V_46 )
return V_81 ;
F_31 ( V_83 , V_46 , 1 ,
F_29 , NULL , ( void * ) & V_81 , NULL ) ;
return V_81 ;
}
