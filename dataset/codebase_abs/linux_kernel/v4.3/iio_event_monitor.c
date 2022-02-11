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
break;
default:
return false ;
}
switch ( V_6 ) {
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
case V_63 :
case V_64 :
case V_65 :
case V_66 :
break;
default:
return false ;
}
switch ( V_8 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
break;
default:
return false ;
}
switch ( V_10 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
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
int V_77 = F_7 ( V_2 -> V_4 ) ;
int V_78 = F_8 ( V_2 -> V_4 ) ;
bool V_79 = F_9 ( V_2 -> V_4 ) ;
if ( ! F_1 ( V_2 ) ) {
fprintf ( V_80 , L_1 ,
V_2 -> V_81 , V_2 -> V_4 ) ;
return;
}
printf ( L_2 , V_2 -> V_81 ,
V_82 [ type ] ) ;
if ( V_6 != V_35 )
printf ( L_3 , V_83 [ V_6 ] ) ;
if ( V_77 >= 0 ) {
printf ( L_4 , V_77 ) ;
if ( V_79 && V_78 >= 0 )
printf ( L_5 , V_78 ) ;
}
printf ( L_6 , V_84 [ V_8 ] ) ;
if ( V_10 != V_76 )
printf ( L_7 , V_85 [ V_10 ] ) ;
printf ( L_8 ) ;
}
int main ( int V_86 , char * * V_87 )
{
struct V_1 V_2 ;
const char * V_88 ;
char * V_89 ;
int V_90 ;
int V_91 ;
int V_92 , V_93 ;
if ( V_86 <= 1 ) {
fprintf ( V_80 , L_9 , V_87 [ 0 ] ) ;
return - 1 ;
}
V_88 = V_87 [ 1 ] ;
V_91 = F_10 ( V_88 , L_10 ) ;
if ( V_91 >= 0 ) {
printf ( L_11 ,
V_88 , V_91 ) ;
V_90 = F_11 ( & V_89 , L_12 , V_91 ) ;
if ( V_90 < 0 )
return - V_94 ;
} else {
V_89 = F_12 ( V_88 ) ;
if ( ! V_89 )
return - V_94 ;
}
V_92 = F_13 ( V_89 , 0 ) ;
if ( V_92 == - 1 ) {
V_90 = - V_95 ;
fprintf ( V_80 , L_13 , V_89 ) ;
goto V_96;
}
V_90 = F_14 ( V_92 , V_97 , & V_93 ) ;
if ( V_90 == - 1 || V_93 == - 1 ) {
V_90 = - V_95 ;
fprintf ( V_80 , L_14 ) ;
if ( F_15 ( V_92 ) == - 1 )
perror ( L_15 ) ;
goto V_96;
}
if ( F_15 ( V_92 ) == - 1 ) {
V_90 = - V_95 ;
goto V_96;
}
while ( true ) {
V_90 = F_16 ( V_93 , & V_2 , sizeof( V_2 ) ) ;
if ( V_90 == - 1 ) {
if ( V_95 == V_98 ) {
fprintf ( V_80 , L_16 ) ;
continue;
} else {
V_90 = - V_95 ;
perror ( L_17 ) ;
break;
}
}
if ( V_90 != sizeof( V_2 ) ) {
fprintf ( V_80 , L_18 ) ;
V_90 = - V_99 ;
break;
}
F_6 ( & V_2 ) ;
}
if ( F_15 ( V_93 ) == - 1 )
perror ( L_19 ) ;
V_96:
free ( V_89 ) ;
return V_90 ;
}
