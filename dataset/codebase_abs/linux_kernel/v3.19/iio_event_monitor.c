static bool F_1 ( struct V_1 * V_2 )
{
enum V_3 type = F_2 ( V_2 -> V_4 ) ;
enum V_5 V_6 = F_3 ( V_2 -> V_4 ) ;
enum V_7 V_8 = F_4 ( V_2 -> V_4 ) ;
enum V_9 V_10 = F_5 ( V_2 -> V_4 ) ;
switch ( type ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
break;
default:
return false ;
}
switch ( V_6 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
break;
default:
return false ;
}
switch ( V_8 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_62 :
case V_63 :
case V_64 :
break;
default:
return false ;
}
return true ;
}
static void F_6 ( struct V_1 * V_2 )
{
enum V_3 type = F_2 ( V_2 -> V_4 ) ;
enum V_5 V_6 = F_3 ( V_2 -> V_4 ) ;
enum V_7 V_8 = F_4 ( V_2 -> V_4 ) ;
enum V_9 V_10 = F_5 ( V_2 -> V_4 ) ;
int V_65 = F_7 ( V_2 -> V_4 ) ;
int V_66 = F_8 ( V_2 -> V_4 ) ;
bool V_67 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
printf ( L_1 ,
V_2 -> V_68 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_68 ) ;
if ( V_6 != V_30 ) {
printf ( L_3 ,
V_69 [ type ] ,
V_70 [ V_6 ] ) ;
} else {
printf ( L_4 ,
V_69 [ type ] ) ;
}
if ( V_67 && V_65 >= 0 && V_66 >= 0 )
printf ( L_5 , V_65 , V_66 ) ;
else if ( V_65 >= 0 )
printf ( L_6 , V_65 ) ;
printf ( L_7 ,
V_71 [ V_8 ] ,
V_72 [ V_10 ] ) ;
}
int main ( int V_73 , char * * V_74 )
{
struct V_1 V_2 ;
const char * V_75 ;
char * V_76 ;
int V_77 ;
int V_78 ;
int V_79 , V_80 ;
if ( V_73 <= 1 ) {
printf ( L_8 , V_74 [ 0 ] ) ;
return - 1 ;
}
V_75 = V_74 [ 1 ] ;
V_78 = F_10 ( V_75 , L_9 ) ;
if ( V_78 >= 0 ) {
printf ( L_10 ,
V_75 , V_78 ) ;
V_77 = F_11 ( & V_76 , L_11 , V_78 ) ;
if ( V_77 < 0 ) {
V_77 = - V_81 ;
goto V_82;
}
} else {
V_76 = F_12 ( V_75 ) ;
}
V_79 = F_13 ( V_76 , 0 ) ;
if ( V_79 == - 1 ) {
fprintf ( stdout , L_12 , V_76 ) ;
V_77 = - V_83 ;
goto V_84;
}
V_77 = F_14 ( V_79 , V_85 , & V_80 ) ;
F_15 ( V_79 ) ;
if ( V_77 == - 1 || V_80 == - 1 ) {
fprintf ( stdout , L_13 ) ;
V_77 = - V_83 ;
goto V_84;
}
while ( true ) {
V_77 = F_16 ( V_80 , & V_2 , sizeof( V_2 ) ) ;
if ( V_77 == - 1 ) {
if ( V_83 == V_86 ) {
printf ( L_14 ) ;
continue;
} else {
perror ( L_15 ) ;
V_77 = - V_83 ;
break;
}
}
F_6 ( & V_2 ) ;
}
F_15 ( V_80 ) ;
V_84:
free ( V_76 ) ;
V_82:
return V_77 ;
}
