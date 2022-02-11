static T_1
F_1 ( const char * V_1 )
{
if ( * V_1 != '/' )
return FALSE ;
do {
V_1 ++ ;
if ( * V_1 == '/' )
return FALSE ;
while ( ( * V_1 >= 'A' && * V_1 <= 'Z' ) || ( * V_1 >= 'a' && * V_1 <= 'z' ) || ( * V_1 >= '0' && * V_1 <= '9' ) || * V_1 == '_' )
V_1 ++ ;
if ( * V_1 == '\0' )
return TRUE ;
} while ( * V_1 == '/' );
return FALSE ;
}
static T_1
F_2 ( const char * T_2 V_2 )
{
return TRUE ;
}
static int
F_3 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 , char T_2 , T_6 * V_7 )
{
const int V_8 = V_6 ;
T_7 * V_9 ;
switch ( T_2 ) {
case 'y' :
{
T_8 V_10 ;
V_10 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
F_5 ( V_5 , V_11 , V_3 , V_8 , V_6 - V_8 , V_10 , L_1 , V_10 ) ;
V_7 -> V_12 = V_10 ;
return V_6 ;
}
case 'b' :
{
T_9 V_10 ;
V_10 = V_4 -> V_13 ( V_3 , V_6 ) ;
V_6 += 4 ;
V_9 = F_6 ( V_5 , V_14 , V_3 , V_8 , V_6 - V_8 , V_10 , L_2 , V_10 ? L_3 : L_4 ) ;
if ( V_10 != 0 && V_10 != 1 ) {
F_7 ( V_4 -> V_15 , V_9 , V_16 , V_17 , L_5 , V_10 ) ;
return - 1 ;
}
V_7 -> V_12 = V_10 ;
return V_6 ;
}
case 'n' :
{
T_10 V_10 ;
V_10 = ( T_10 ) V_4 -> V_18 ( V_3 , V_6 ) ;
V_6 += 2 ;
F_5 ( V_5 , V_19 , V_3 , V_8 , V_6 - V_8 , V_10 , L_6 , V_10 ) ;
return V_6 ;
}
case 'q' :
{
T_11 V_10 ;
V_10 = V_4 -> V_18 ( V_3 , V_6 ) ;
V_6 += 2 ;
F_5 ( V_5 , V_11 , V_3 , V_8 , V_6 - V_8 , V_10 , L_7 , V_10 ) ;
V_7 -> V_12 = V_10 ;
return V_6 ;
}
case 'i' :
{
T_12 V_10 ;
V_10 = ( T_12 ) V_4 -> V_13 ( V_3 , V_6 ) ;
V_6 += 4 ;
F_8 ( V_5 , V_19 , V_3 , V_8 , V_6 - V_8 , V_10 , L_8 , V_10 ) ;
return V_6 ;
}
case 'u' :
{
T_9 V_10 ;
V_10 = V_4 -> V_13 ( V_3 , V_6 ) ;
V_6 += 4 ;
F_5 ( V_5 , V_11 , V_3 , V_8 , V_6 - V_8 , V_10 , L_9 , V_10 ) ;
V_7 -> V_12 = V_10 ;
return V_6 ;
}
case 'x' :
case 't' :
return - 1 ;
case 'd' :
{
T_13 V_10 ;
V_10 = V_4 -> V_20 ( V_3 , V_6 ) ;
V_6 += 8 ;
F_9 ( V_5 , V_21 , V_3 , V_8 , V_6 - V_8 , V_10 , L_10 F_10 ( V_22 ) L_11 , V_10 ) ;
return V_6 ;
}
case 's' :
case 'o' :
{
T_9 V_23 ;
char * V_10 ;
V_23 = V_4 -> V_13 ( V_3 , V_6 ) ;
V_6 += 4 ;
V_10 = F_11 ( V_3 , V_6 , V_23 ) ;
V_6 += ( V_23 + 1 + 3 ) & ~ 3 ;
if ( T_2 == 's' ) {
V_9 = F_12 ( V_5 , V_24 , V_3 , V_8 , V_6 - V_8 , V_10 , L_12 , V_10 ) ;
if ( ! F_13 ( V_10 , - 1 , NULL ) ) {
F_7 ( V_4 -> V_15 , V_9 , V_16 , V_17 , L_13 ) ;
return - 1 ;
}
} else {
V_9 = F_12 ( V_5 , V_24 , V_3 , V_8 , V_6 - V_8 , V_10 , L_14 , V_10 ) ;
if ( ! F_1 ( V_10 ) ) {
F_7 ( V_4 -> V_15 , V_9 , V_16 , V_17 , L_15 ) ;
return - 1 ;
}
}
V_7 -> V_25 = V_10 ;
return V_6 ;
}
case 'g' :
{
T_8 V_23 ;
char * V_10 ;
V_23 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
V_10 = F_11 ( V_3 , V_6 , V_23 ) ;
V_6 += ( V_23 + 1 ) ;
V_9 = F_12 ( V_5 , V_24 , V_3 , V_8 , V_6 - V_8 , V_10 , L_16 , V_10 ) ;
if ( ! F_2 ( V_10 ) ) {
F_7 ( V_4 -> V_15 , V_9 , V_16 , V_17 , L_17 ) ;
return - 1 ;
}
V_7 -> V_25 = V_10 ;
return V_6 ;
}
}
return - 1 ;
}
static int
F_14 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 , int V_26 )
{
const int V_8 = V_6 ;
T_7 * V_9 ;
T_14 V_27 ;
char * T_2 ;
V_27 = F_4 ( V_3 , V_6 ) ;
V_6 += 1 ;
T_2 = F_11 ( V_3 , V_6 , V_27 ) ;
V_6 += ( V_27 + 1 ) ;
V_9 = F_15 ( V_5 , V_28 , V_3 , V_8 , V_6 - V_8 , T_2 ) ;
if ( ! F_2 ( T_2 ) ) {
F_7 ( V_4 -> V_15 , V_9 , V_16 , V_17 , L_17 ) ;
return - 1 ;
}
switch ( V_26 ) {
case V_29 :
if ( ! strcmp ( T_2 , L_18 ) ) {
T_6 V_30 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 'u' , & V_30 ) ;
if ( V_6 != - 1 )
{ }
return V_6 ;
}
break;
case V_31 :
case V_32 :
if ( ! strcmp ( T_2 , L_19 ) ) {
T_6 V_33 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 's' , & V_33 ) ;
if ( V_6 != - 1 )
F_16 ( ( V_26 == V_31 ) ? & V_4 -> V_15 -> V_34 : & V_4 -> V_15 -> V_35 ,
V_36 , ( int ) strlen ( V_33 . V_25 ) + 1 , V_33 . V_25 ) ;
return V_6 ;
}
break;
case V_37 :
if ( ! strcmp ( T_2 , L_11 ) ) {
T_6 V_38 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , 'g' , & V_38 ) ;
if ( V_6 != - 1 )
V_4 -> V_39 = V_38 . V_25 ;
return V_6 ;
}
break;
}
while ( * T_2 ) {
T_6 V_10 ;
V_6 = F_3 ( V_3 , V_4 , V_5 , V_6 , * T_2 , & V_10 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
return V_6 ;
}
static int
F_17 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
int V_40 ;
V_40 = V_6 + V_4 -> V_41 ;
while ( V_6 < V_40 ) {
T_5 * V_42 ;
T_7 * V_9 ;
T_8 V_26 ;
V_9 = F_18 ( V_5 , V_43 , V_3 , V_6 , 0 , V_44 ) ;
V_42 = F_19 ( V_9 , V_45 ) ;
V_26 = F_4 ( V_3 , V_6 ) ;
F_18 ( V_42 , V_46 , V_3 , V_6 , 1 , V_4 -> V_47 ) ;
F_20 ( V_9 , L_20 , F_21 ( V_26 , V_48 , L_21 ) ) ;
V_6 += 1 ;
V_6 = F_14 ( V_3 , V_4 , V_42 , V_6 , V_26 ) ;
if ( V_6 == - 1 )
break;
V_6 = ( V_6 + 7 ) & ~ 7 ;
F_22 ( V_9 , V_3 , V_6 ) ;
}
if ( V_6 >= V_40 ) {
}
return V_40 ;
}
static int
F_23 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_49 ;
T_7 * V_9 ;
T_8 type ;
V_9 = F_18 ( V_5 , V_50 , V_3 , V_6 , 0 , V_44 ) ;
V_49 = F_19 ( V_9 , V_51 ) ;
F_18 ( V_49 , V_52 , V_3 , V_6 , 1 , V_53 | V_44 ) ;
V_6 += 1 ;
type = F_4 ( V_3 , V_6 ) ;
F_24 ( V_4 -> V_15 -> V_54 , V_55 , F_25 ( type , V_56 , L_22 ) ) ;
F_18 ( V_49 , V_57 , V_3 , V_6 , 1 , V_4 -> V_47 ) ;
V_6 += 1 ;
F_18 ( V_49 , V_58 , V_3 , V_6 , 1 , V_4 -> V_47 ) ;
V_6 += 1 ;
F_18 ( V_49 , V_59 , V_3 , V_6 , 1 , V_4 -> V_47 ) ;
V_6 += 1 ;
V_4 -> V_60 = V_4 -> V_13 ( V_3 , V_6 ) ;
F_18 ( V_49 , V_61 , V_3 , V_6 , 4 , V_4 -> V_47 ) ;
V_6 += 4 ;
F_18 ( V_49 , V_62 , V_3 , V_6 , 4 , V_4 -> V_47 ) ;
V_6 += 4 ;
V_4 -> V_41 = V_4 -> V_13 ( V_3 , V_6 ) ;
F_18 ( V_49 , V_63 , V_3 , V_6 , 4 , V_4 -> V_47 ) ;
V_6 += 4 ;
return V_6 ;
}
static int
F_26 ( T_3 * V_3 , T_4 * V_4 , T_5 * V_5 , int V_6 )
{
T_5 * V_64 ;
T_7 * V_9 ;
if ( V_4 -> V_60 && V_4 -> V_39 [ 0 ] ) {
const char * T_2 = V_4 -> V_39 ;
V_9 = F_18 ( V_5 , V_65 , V_3 , V_6 , 0 , V_44 ) ;
V_64 = F_19 ( V_9 , V_66 ) ;
while ( * T_2 ) {
T_6 V_10 ;
V_6 = F_3 ( V_3 , V_4 , V_64 , V_6 , * T_2 , & V_10 ) ;
if ( V_6 == - 1 )
return - 1 ;
T_2 ++ ;
}
F_22 ( V_9 , V_3 , V_6 ) ;
} else if ( V_4 -> V_60 || V_4 -> V_39 [ 0 ] ) {
}
return V_6 ;
}
static int
F_27 ( T_3 * V_3 , T_15 * V_15 , T_5 * V_5 , void * T_16 V_2 )
{
T_5 * V_67 = NULL ;
T_4 V_4 ;
int V_6 ;
F_28 ( V_15 -> V_54 , V_68 , L_23 ) ;
F_29 ( V_15 -> V_54 , V_55 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_15 = V_15 ;
switch ( F_4 ( V_3 , 0 ) ) {
case 'l' :
V_4 . V_47 = V_69 ;
V_4 . V_18 = V_70 ;
V_4 . V_13 = V_71 ;
V_4 . V_20 = V_72 ;
break;
case 'B' :
V_4 . V_47 = V_73 ;
V_4 . V_18 = V_74 ;
V_4 . V_13 = V_75 ;
V_4 . V_20 = V_76 ;
break;
default:
V_4 . V_47 = V_44 ;
V_4 . V_18 = V_74 ;
V_4 . V_13 = V_75 ;
V_4 . V_20 = V_76 ;
}
if ( V_5 ) {
T_7 * V_9 = F_18 ( V_5 , V_77 , V_3 , 0 , - 1 , V_44 ) ;
V_67 = F_19 ( V_9 , V_78 ) ;
}
V_6 = 0 ;
V_6 = F_23 ( V_3 , & V_4 , V_67 , V_6 ) ;
V_6 = F_17 ( V_3 , & V_4 , V_67 , V_6 ) ;
V_6 = ( V_6 + 7 ) & ~ 7 ;
if ( ! V_4 . V_39 )
V_4 . V_39 = L_22 ;
V_6 = F_26 ( V_3 , & V_4 , V_67 , V_6 ) ;
return V_6 ;
}
static T_14
F_30 ( T_15 * V_15 V_2 , T_3 * V_3 , int V_6 )
{
T_9 (* F_31)( T_3 * , const T_17 );
T_9 V_79 , V_80 ;
switch ( F_4 ( V_3 , V_6 ) ) {
case 'l' :
F_31 = V_71 ;
break;
case 'B' :
default:
F_31 = V_75 ;
break;
}
V_80 = V_81 + F_31 ( V_3 , V_6 + 12 ) ;
V_80 = ( V_80 + 7 ) & ~ 7 ;
V_79 = F_31 ( V_3 , V_6 + 4 ) ;
return V_80 + V_79 ;
}
static void
F_32 ( T_3 * V_3 , T_15 * V_15 , T_5 * V_5 )
{
F_27 ( V_3 , V_15 , V_5 , NULL ) ;
}
static int
F_33 ( T_3 * V_3 , T_15 * V_15 , T_5 * V_5 , void * T_16 V_2 )
{
F_34 ( V_3 , V_15 , V_5 , V_82 , V_81 , F_30 , F_32 ) ;
return F_35 ( V_3 ) ;
}
void
F_36 ( void )
{
static T_18 V_83 [] = {
{ & V_50 ,
{ L_24 , L_25 , V_84 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_52 ,
{ L_26 , L_27 , V_87 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_57 ,
{ L_28 , L_29 , V_88 , V_89 , F_37 ( V_56 ) , 0x00 , NULL , V_86 }
} ,
{ & V_58 ,
{ L_30 , L_31 , V_88 , V_90 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_59 ,
{ L_32 , L_33 , V_88 , V_89 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_61 ,
{ L_34 , L_35 , V_91 , V_89 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_62 ,
{ L_36 , L_37 , V_91 , V_89 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_63 ,
{ L_38 , L_39 , V_91 , V_89 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_43 ,
{ L_40 , L_41 , V_84 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_46 ,
{ L_42 , L_43 , V_88 , V_89 , F_37 ( V_48 ) , 0x00 , NULL , V_86 }
} ,
{ & V_28 ,
{ L_44 , L_45 , V_92 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_65 ,
{ L_46 , L_47 , V_84 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_14 ,
{ L_48 , L_49 , V_93 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_19 ,
{ L_48 , L_50 , V_94 , V_89 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_11 ,
{ L_48 , L_51 , V_91 , V_89 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_24 ,
{ L_48 , L_52 , V_87 , V_85 , NULL , 0x00 , NULL , V_86 }
} ,
{ & V_21 ,
{ L_48 , L_53 , V_95 , V_85 , NULL , 0x00 , NULL , V_86 }
}
} ;
static T_17 * V_96 [] = {
& V_78 ,
& V_51 ,
& V_66 ,
& V_45
} ;
V_77 = F_38 ( L_54 , L_23 , L_55 ) ;
F_39 ( V_77 , V_83 , F_40 ( V_83 ) ) ;
F_41 ( V_96 , F_40 ( V_96 ) ) ;
}
void
F_42 ( void )
{
T_19 V_97 = F_43 ( F_27 , V_77 ) ;
T_19 V_98 = F_43 ( F_33 , V_77 ) ;
F_44 ( L_56 , V_99 , V_97 ) ;
F_45 ( L_57 , V_98 ) ;
}
