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
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
break;
default:
return false ;
}
switch ( V_6 ) {
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
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
break;
default:
return false ;
}
switch ( V_8 ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
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
int V_87 = F_7 ( V_2 -> V_4 ) ;
int V_88 = F_8 ( V_2 -> V_4 ) ;
bool V_89 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
fprintf ( V_90 , L_1 ,
V_2 -> V_91 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_91 ,
V_92 [ type ] ) ;
if ( V_6 != V_40 )
printf ( L_3 , V_93 [ V_6 ] ) ;
if ( V_87 >= 0 ) {
printf ( L_4 , V_87 ) ;
if ( V_89 && V_88 >= 0 )
printf ( L_5 , V_88 ) ;
}
printf ( L_6 , V_94 [ V_8 ] ) ;
if ( V_10 != V_86 )
printf ( L_7 , V_95 [ V_10 ] ) ;
printf ( L_8 ) ;
}
int main ( int V_96 , char * * V_97 )
{
struct V_1 V_2 ;
const char * V_98 ;
char * V_99 ;
int V_100 ;
int V_101 ;
int V_102 , V_103 ;
if ( V_96 <= 1 ) {
fprintf ( V_90 , L_9 , V_97 [ 0 ] ) ;
return - 1 ;
}
V_98 = V_97 [ 1 ] ;
V_101 = F_10 ( V_98 , L_10 ) ;
if ( V_101 >= 0 ) {
printf ( L_11 ,
V_98 , V_101 ) ;
V_100 = F_11 ( & V_99 , L_12 , V_101 ) ;
if ( V_100 < 0 )
return - V_104 ;
} else {
V_99 = F_12 ( V_98 ) ;
if ( ! V_99 )
return - V_104 ;
}
V_102 = F_13 ( V_99 , 0 ) ;
if ( V_102 == - 1 ) {
V_100 = - V_105 ;
fprintf ( V_90 , L_13 , V_99 ) ;
goto V_106;
}
V_100 = F_14 ( V_102 , V_107 , & V_103 ) ;
if ( V_100 == - 1 || V_103 == - 1 ) {
V_100 = - V_105 ;
if ( V_100 == - V_108 )
fprintf ( V_90 ,
L_14 ) ;
else
fprintf ( V_90 , L_15 ) ;
if ( F_15 ( V_102 ) == - 1 )
perror ( L_16 ) ;
goto V_106;
}
if ( F_15 ( V_102 ) == - 1 ) {
V_100 = - V_105 ;
goto V_106;
}
while ( true ) {
V_100 = F_16 ( V_103 , & V_2 , sizeof( V_2 ) ) ;
if ( V_100 == - 1 ) {
if ( V_105 == V_109 ) {
fprintf ( V_90 , L_17 ) ;
continue;
} else {
V_100 = - V_105 ;
perror ( L_18 ) ;
break;
}
}
if ( V_100 != sizeof( V_2 ) ) {
fprintf ( V_90 , L_19 ) ;
V_100 = - V_110 ;
break;
}
F_6 ( & V_2 ) ;
}
if ( F_15 ( V_103 ) == - 1 )
perror ( L_20 ) ;
V_106:
free ( V_99 ) ;
return V_100 ;
}
