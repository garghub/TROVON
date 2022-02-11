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
break;
default:
return false ;
}
switch ( V_6 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
break;
default:
return false ;
}
switch ( V_8 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_37 :
case V_38 :
case V_39 :
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
int V_40 = F_7 ( V_2 -> V_4 ) ;
int V_41 = F_8 ( V_2 -> V_4 ) ;
bool V_42 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
printf ( L_1 ,
V_2 -> V_43 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_43 ) ;
if ( V_6 != V_26 ) {
printf ( L_3 ,
V_44 [ type ] ,
V_45 [ V_6 ] ) ;
} else {
printf ( L_4 ,
V_44 [ type ] ) ;
}
if ( V_42 && V_40 >= 0 && V_41 >= 0 )
printf ( L_5 , V_40 , V_41 ) ;
else if ( V_40 >= 0 )
printf ( L_6 , V_40 ) ;
printf ( L_7 ,
V_46 [ V_8 ] ,
V_47 [ V_10 ] ) ;
}
int main ( int V_48 , char * * V_49 )
{
struct V_1 V_2 ;
const char * V_50 ;
char * V_51 ;
int V_52 ;
int V_53 ;
int V_54 , V_55 ;
if ( V_48 <= 1 ) {
printf ( L_8 , V_49 [ 0 ] ) ;
return - 1 ;
}
V_50 = V_49 [ 1 ] ;
V_53 = F_10 ( V_50 , L_9 ) ;
if ( V_53 >= 0 ) {
printf ( L_10 ,
V_50 , V_53 ) ;
V_52 = F_11 ( & V_51 , L_11 , V_53 ) ;
if ( V_52 < 0 ) {
V_52 = - V_56 ;
goto V_57;
}
} else {
V_51 = F_12 ( V_50 ) ;
}
V_54 = F_13 ( V_51 , 0 ) ;
if ( V_54 == - 1 ) {
fprintf ( stdout , L_12 , V_51 ) ;
V_52 = - V_58 ;
goto V_59;
}
V_52 = F_14 ( V_54 , V_60 , & V_55 ) ;
F_15 ( V_54 ) ;
if ( V_52 == - 1 || V_55 == - 1 ) {
fprintf ( stdout , L_13 ) ;
V_52 = - V_58 ;
goto V_59;
}
while ( true ) {
V_52 = F_16 ( V_55 , & V_2 , sizeof( V_2 ) ) ;
if ( V_52 == - 1 ) {
if ( V_58 == V_61 ) {
printf ( L_14 ) ;
continue;
} else {
perror ( L_15 ) ;
V_52 = - V_58 ;
break;
}
}
F_6 ( & V_2 ) ;
}
F_15 ( V_55 ) ;
V_59:
free ( V_51 ) ;
V_57:
return V_52 ;
}
