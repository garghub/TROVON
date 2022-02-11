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
case V_30 :
case V_31 :
break;
default:
return false ;
}
switch ( V_6 ) {
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
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
break;
default:
return false ;
}
switch ( V_8 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
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
int V_73 = F_7 ( V_2 -> V_4 ) ;
int V_74 = F_8 ( V_2 -> V_4 ) ;
bool V_75 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
printf ( L_1 ,
V_2 -> V_76 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_76 ,
V_77 [ type ] ) ;
if ( V_6 != V_32 )
printf ( L_3 , V_78 [ V_6 ] ) ;
if ( V_73 >= 0 ) {
printf ( L_4 , V_73 ) ;
if ( V_75 && V_74 >= 0 )
printf ( L_5 , V_74 ) ;
}
printf ( L_6 , V_79 [ V_8 ] ) ;
if ( V_10 != V_72 )
printf ( L_7 , V_80 [ V_10 ] ) ;
printf ( L_8 ) ;
}
int main ( int V_81 , char * * V_82 )
{
struct V_1 V_2 ;
const char * V_83 ;
char * V_84 ;
int V_85 ;
int V_86 ;
int V_87 , V_88 ;
if ( V_81 <= 1 ) {
printf ( L_9 , V_82 [ 0 ] ) ;
return - 1 ;
}
V_83 = V_82 [ 1 ] ;
V_86 = F_10 ( V_83 , L_10 ) ;
if ( V_86 >= 0 ) {
printf ( L_11 ,
V_83 , V_86 ) ;
V_85 = F_11 ( & V_84 , L_12 , V_86 ) ;
if ( V_85 < 0 ) {
return - V_89 ;
}
} else {
V_84 = F_12 ( V_83 ) ;
if ( ! V_84 )
return - V_89 ;
}
V_87 = F_13 ( V_84 , 0 ) ;
if ( V_87 == - 1 ) {
V_85 = - V_90 ;
fprintf ( stdout , L_13 , V_84 ) ;
goto V_91;
}
V_85 = F_14 ( V_87 , V_92 , & V_88 ) ;
if ( V_85 == - 1 || V_88 == - 1 ) {
V_85 = - V_90 ;
fprintf ( stdout , L_14 ) ;
if ( F_15 ( V_87 ) == - 1 )
perror ( L_15 ) ;
goto V_91;
}
if ( F_15 ( V_87 ) == - 1 ) {
V_85 = - V_90 ;
goto V_91;
}
while ( true ) {
V_85 = F_16 ( V_88 , & V_2 , sizeof( V_2 ) ) ;
if ( V_85 == - 1 ) {
if ( V_90 == V_93 ) {
printf ( L_16 ) ;
continue;
} else {
V_85 = - V_90 ;
perror ( L_17 ) ;
break;
}
}
F_6 ( & V_2 ) ;
}
if ( F_15 ( V_88 ) == - 1 )
perror ( L_18 ) ;
V_91:
free ( V_84 ) ;
return V_85 ;
}
