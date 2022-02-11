static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
unsigned int V_4 , V_5 ;
const char * string ;
if ( V_3 ) {
if ( F_2 ( V_4 , ( unsigned int T_1 * ) V_3 ) )
return - V_6 ;
if ( V_2 -> V_7 -> V_8 )
string = V_2 -> V_7 -> V_8 ( V_2 ) ;
else
string = V_2 -> V_7 -> V_9 ;
if ( string ) {
V_5 = strlen ( string ) ;
if ( V_4 > V_5 )
V_4 = V_5 + 1 ;
if ( F_3 ( V_3 , string , V_4 ) )
return - V_6 ;
}
}
return 1 ;
}
static int F_4 ( struct V_10 * V_11 , char * V_12 ,
int V_13 , int V_14 )
{
int V_15 ;
struct V_16 V_17 ;
F_5 ( 1 , F_6 ( V_18 , V_11 ,
L_1 , * V_12 ) ) ;
V_15 = F_7 ( V_11 , V_12 , V_19 , NULL , 0 ,
& V_17 , V_13 , V_14 , NULL ) ;
F_5 ( 2 , F_6 ( V_18 , V_11 ,
L_2 , V_15 ) ) ;
if ( ( F_8 ( V_15 ) & V_20 ) &&
( F_9 ( & V_17 ) ) ) {
switch ( V_17 . V_21 ) {
case V_22 :
if ( V_12 [ 0 ] == V_23 )
V_11 -> V_24 = 0 ;
else
F_6 ( V_18 , V_11 ,
L_3
L_4
L_5 ,
V_17 . V_25 , V_17 . V_26 ) ;
break;
case V_27 :
if ( V_11 -> V_28 )
break;
case V_29 :
if ( V_11 -> V_28 ) {
V_11 -> V_30 = 1 ;
V_15 = 0 ;
break;
}
default:
F_6 ( V_18 , V_11 ,
L_6 ,
V_15 ) ;
F_10 ( V_11 , NULL , & V_17 ) ;
break;
}
}
F_5 ( 2 , F_6 ( V_18 , V_11 ,
L_7 ) ) ;
return V_15 ;
}
int F_11 ( struct V_10 * V_11 , char V_31 )
{
char V_32 [ V_33 ] ;
int V_34 ;
if ( ! V_11 -> V_28 || ! V_11 -> V_24 )
return 0 ;
V_32 [ 0 ] = V_23 ;
V_32 [ 1 ] = 0 ;
V_32 [ 2 ] = 0 ;
V_32 [ 3 ] = 0 ;
V_32 [ 4 ] = V_31 ;
V_32 [ 5 ] = 0 ;
V_34 = F_4 ( V_11 , V_32 ,
V_35 , V_36 ) ;
if ( V_34 == 0 )
V_11 -> V_37 = ( V_31 == V_38 ) ;
return V_34 ;
}
static int F_12 ( struct V_10 * V_11 , void T_1 * V_39 )
{
struct V_40 * V_41 = F_13 ( V_11 -> V_2 ) ;
const char * V_9 ;
if ( ! V_41 )
return - V_42 ;
V_9 = F_14 ( V_41 ) ;
return F_3 ( V_39 , V_9 , F_15 ( strlen ( V_9 ) , ( V_43 ) 20 ) )
? - V_6 : 0 ;
}
int F_16 ( struct V_10 * V_11 , int V_12 , void T_1 * V_39 )
{
char V_32 [ V_33 ] ;
struct V_16 V_44 ;
switch ( V_12 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
F_17 ( V_51 L_8
L_9 , V_52 -> V_53 ) ;
break;
default:
break;
}
switch ( V_12 ) {
case V_54 :
if ( ! F_18 ( V_55 , V_39 , sizeof( struct V_56 ) ) )
return - V_6 ;
F_19 ( ( V_11 -> V_57 & 0xff )
+ ( ( V_11 -> V_58 & 0xff ) << 8 )
+ ( ( V_11 -> V_59 & 0xff ) << 16 )
+ ( ( V_11 -> V_2 -> V_60 & 0xff ) << 24 ) ,
& ( (struct V_56 T_1 * ) V_39 ) -> V_61 ) ;
F_19 ( V_11 -> V_2 -> V_62 ,
& ( (struct V_56 T_1 * ) V_39 ) -> V_63 ) ;
return 0 ;
case V_64 :
return F_20 ( V_11 -> V_2 -> V_60 , ( int T_1 * ) V_39 ) ;
case V_65 :
return F_1 ( V_11 -> V_2 , V_39 ) ;
case V_45 :
if ( ! F_21 ( V_66 ) || ! F_21 ( V_67 ) )
return - V_68 ;
return F_22 ( V_11 -> V_69 , NULL , 0 , V_39 ) ;
case V_70 :
return F_11 ( V_11 , V_38 ) ;
case V_71 :
return F_11 ( V_11 , V_72 ) ;
case V_46 :
return F_23 ( V_11 , V_35 ,
V_36 , & V_44 ) ;
case V_49 :
V_32 [ 0 ] = V_73 ;
V_32 [ 1 ] = 0 ;
V_32 [ 2 ] = V_32 [ 3 ] = V_32 [ 5 ] = 0 ;
V_32 [ 4 ] = 1 ;
return F_4 ( V_11 , V_32 ,
V_74 , V_36 ) ;
case V_50 :
V_32 [ 0 ] = V_73 ;
V_32 [ 1 ] = 0 ;
V_32 [ 2 ] = V_32 [ 3 ] = V_32 [ 5 ] = 0 ;
V_32 [ 4 ] = 0 ;
return F_4 ( V_11 , V_32 ,
V_74 , V_36 ) ;
case V_75 :
return F_12 ( V_11 , V_39 ) ;
case V_76 :
return F_24 ( V_11 , V_39 ) ;
default:
if ( V_11 -> V_2 -> V_7 -> V_77 )
return V_11 -> V_2 -> V_7 -> V_77 ( V_11 , V_12 , V_39 ) ;
}
return - V_78 ;
}
int F_25 ( struct V_10 * V_11 , int V_12 ,
bool V_79 )
{
if ( V_12 == V_76 && V_79 ) {
if ( F_26 ( V_11 -> V_2 ) )
return - V_80 ;
} else {
if ( ! F_27 ( V_11 ) )
return - V_81 ;
}
return 0 ;
}
