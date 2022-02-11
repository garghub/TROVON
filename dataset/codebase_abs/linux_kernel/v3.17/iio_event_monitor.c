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
break;
default:
return false ;
}
switch ( V_8 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_47 :
case V_48 :
case V_49 :
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
int V_50 = F_7 ( V_2 -> V_4 ) ;
int V_51 = F_8 ( V_2 -> V_4 ) ;
bool V_52 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
printf ( L_1 ,
V_2 -> V_53 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_53 ) ;
if ( V_6 != V_30 ) {
printf ( L_3 ,
V_54 [ type ] ,
V_55 [ V_6 ] ) ;
} else {
printf ( L_4 ,
V_54 [ type ] ) ;
}
if ( V_52 && V_50 >= 0 && V_51 >= 0 )
printf ( L_5 , V_50 , V_51 ) ;
else if ( V_50 >= 0 )
printf ( L_6 , V_50 ) ;
printf ( L_7 ,
V_56 [ V_8 ] ,
V_57 [ V_10 ] ) ;
}
int main ( int V_58 , char * * V_59 )
{
struct V_1 V_2 ;
const char * V_60 ;
char * V_61 ;
int V_62 ;
int V_63 ;
int V_64 , V_65 ;
if ( V_58 <= 1 ) {
printf ( L_8 , V_59 [ 0 ] ) ;
return - 1 ;
}
V_60 = V_59 [ 1 ] ;
V_63 = F_10 ( V_60 , L_9 ) ;
if ( V_63 >= 0 ) {
printf ( L_10 ,
V_60 , V_63 ) ;
V_62 = F_11 ( & V_61 , L_11 , V_63 ) ;
if ( V_62 < 0 ) {
V_62 = - V_66 ;
goto V_67;
}
} else {
V_61 = F_12 ( V_60 ) ;
}
V_64 = F_13 ( V_61 , 0 ) ;
if ( V_64 == - 1 ) {
fprintf ( stdout , L_12 , V_61 ) ;
V_62 = - V_68 ;
goto V_69;
}
V_62 = F_14 ( V_64 , V_70 , & V_65 ) ;
F_15 ( V_64 ) ;
if ( V_62 == - 1 || V_65 == - 1 ) {
fprintf ( stdout , L_13 ) ;
V_62 = - V_68 ;
goto V_69;
}
while ( true ) {
V_62 = F_16 ( V_65 , & V_2 , sizeof( V_2 ) ) ;
if ( V_62 == - 1 ) {
if ( V_68 == V_71 ) {
printf ( L_14 ) ;
continue;
} else {
perror ( L_15 ) ;
V_62 = - V_68 ;
break;
}
}
F_6 ( & V_2 ) ;
}
F_15 ( V_65 ) ;
V_69:
free ( V_61 ) ;
V_67:
return V_62 ;
}
