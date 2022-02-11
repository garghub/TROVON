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
break;
default:
return false ;
}
switch ( V_6 ) {
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
case V_38 :
break;
default:
return false ;
}
switch ( V_8 ) {
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_44 :
case V_45 :
case V_46 :
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
int V_47 = F_7 ( V_2 -> V_4 ) ;
int V_48 = F_8 ( V_2 -> V_4 ) ;
bool V_49 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
printf ( L_1 ,
V_2 -> V_50 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_50 ) ;
if ( V_6 != V_27 ) {
printf ( L_3 ,
V_51 [ type ] ,
V_52 [ V_6 ] ) ;
} else {
printf ( L_4 ,
V_51 [ type ] ) ;
}
if ( V_49 && V_47 >= 0 && V_48 >= 0 )
printf ( L_5 , V_47 , V_48 ) ;
else if ( V_47 >= 0 )
printf ( L_6 , V_47 ) ;
printf ( L_7 ,
V_53 [ V_8 ] ,
V_54 [ V_10 ] ) ;
}
int main ( int V_55 , char * * V_56 )
{
struct V_1 V_2 ;
const char * V_57 ;
char * V_58 ;
int V_59 ;
int V_60 ;
int V_61 , V_62 ;
if ( V_55 <= 1 ) {
printf ( L_8 , V_56 [ 0 ] ) ;
return - 1 ;
}
V_57 = V_56 [ 1 ] ;
V_60 = F_10 ( V_57 , L_9 ) ;
if ( V_60 >= 0 ) {
printf ( L_10 ,
V_57 , V_60 ) ;
V_59 = F_11 ( & V_58 , L_11 , V_60 ) ;
if ( V_59 < 0 ) {
V_59 = - V_63 ;
goto V_64;
}
} else {
V_58 = F_12 ( V_57 ) ;
}
V_61 = F_13 ( V_58 , 0 ) ;
if ( V_61 == - 1 ) {
fprintf ( stdout , L_12 , V_58 ) ;
V_59 = - V_65 ;
goto V_66;
}
V_59 = F_14 ( V_61 , V_67 , & V_62 ) ;
F_15 ( V_61 ) ;
if ( V_59 == - 1 || V_62 == - 1 ) {
fprintf ( stdout , L_13 ) ;
V_59 = - V_65 ;
goto V_66;
}
while ( true ) {
V_59 = F_16 ( V_62 , & V_2 , sizeof( V_2 ) ) ;
if ( V_59 == - 1 ) {
if ( V_65 == V_68 ) {
printf ( L_14 ) ;
continue;
} else {
perror ( L_15 ) ;
V_59 = - V_65 ;
break;
}
}
F_6 ( & V_2 ) ;
}
F_15 ( V_62 ) ;
V_66:
free ( V_58 ) ;
V_64:
return V_59 ;
}
