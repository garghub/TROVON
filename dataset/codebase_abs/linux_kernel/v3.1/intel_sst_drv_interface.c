int F_1 ( void )
{
int V_1 ;
const struct V_2 * V_3 ;
char V_4 [ 20 ] ;
if ( V_5 -> V_6 != V_7 )
return - V_8 ;
if ( ( V_5 -> V_9 == V_10 ) && V_5 -> V_11 ) {
F_2 ( L_1 ) ;
V_5 -> V_6 = V_12 ;
return 0 ;
}
snprintf ( V_4 , sizeof( V_4 ) , L_2 , L_3 ,
V_5 -> V_9 , L_4 ) ;
F_2 ( L_5 , V_4 ) ;
V_1 = F_3 ( & V_3 , V_4 , & V_5 -> V_13 -> V_14 ) ;
if ( V_1 ) {
F_4 ( L_6 , V_1 ) ;
return V_1 ;
}
V_5 -> V_15 [ 0 ] . V_16 = V_17 ;
V_5 -> V_15 [ 0 ] . V_18 . V_19 = false ;
V_1 = F_5 ( V_3 , NULL ) ;
if ( V_1 )
goto V_20;
V_1 = F_6 ( V_5 , & V_5 -> V_15 [ 0 ] ) ;
if ( V_1 )
F_4 ( L_7 , V_1 ) ;
else
V_5 -> V_11 = 1 ;
V_20:
F_7 ( V_3 ) ;
V_5 -> V_15 [ 0 ] . V_16 = V_21 ;
return V_1 ;
}
int F_8 ( void )
{
int V_22 = 1000 ;
int V_1 = - 1 ;
while ( V_22 ) {
if ( ! V_5 -> V_23 )
return 0 ;
F_9 ( 1 ) ;
V_22 -- ;
}
F_2 ( L_8 ) ;
return V_1 ;
}
void F_10 ( unsigned int V_24 )
{
struct V_25 * V_26 ;
if ( ! F_11 ( V_24 ) ) {
V_26 = & V_5 -> V_27 [ V_24 ] ;
if ( F_12 ( V_24 ) )
F_13 ( & V_5 -> V_27 [ V_24 ] ) ;
if ( V_26 -> V_28 == V_29 ||
V_26 -> V_28 == V_30 ) {
V_5 -> V_31 -- ;
if ( V_5 -> V_9 == V_32 )
V_5 -> V_33 -> V_34 (
V_26 -> V_35 ) ;
else {
if ( V_5 -> V_31 == 0 )
V_5 -> V_33 ->
V_34 ( V_26 -> V_35 ) ;
}
} else if ( V_26 -> V_28 == V_36 ) {
V_5 -> V_37 -- ;
if ( V_5 -> V_37 == 0 )
V_5 -> V_33 -> V_38 (
V_26 -> V_35 ) ;
}
if ( V_5 -> V_31 == 0
&& V_5 -> V_37 == 0 )
V_5 -> V_33 -> V_39 () ;
}
}
int F_14 ( struct V_40 * V_41 ,
struct V_42 * * V_43 )
{
int V_1 , V_24 ;
struct V_25 * V_44 ;
V_1 = F_15 ( ( char * ) & V_41 -> V_45 , V_41 -> V_28 ,
V_41 -> V_46 , V_41 -> V_47 ) ;
if ( V_1 < 0 ) {
F_4 ( L_9 , V_1 ) ;
return V_1 ;
}
F_2 ( L_10 , V_1 ) ;
V_24 = V_1 ;
V_44 = & V_5 -> V_27 [ V_24 ] ;
V_1 = F_16 ( V_5 ,
& V_44 -> V_48 , V_49 ) ;
if ( ( V_1 != 0 ) || ( V_44 -> V_48 . V_50 != 0 ) ) {
F_2 ( L_11 ,
V_1 , V_44 -> V_48 . V_50 ) ;
V_24 = - V_44 -> V_48 . V_50 ;
* V_43 = V_44 -> V_48 . V_51 ;
F_13 ( V_44 ) ;
} else
F_2 ( L_12 ) ;
return V_24 ;
}
static int F_17 ( struct V_40 * V_41 )
{
switch ( V_41 -> V_46 ) {
case V_52 :
return 48000 ;
case V_53 :
return V_41 -> V_45 . V_54 . V_55 . V_56 ;
case V_57 :
return V_41 -> V_45 . V_54 . V_58 . V_56 ;
case V_59 :
return V_41 -> V_45 . V_54 . V_60 . V_56 ;
default:
return 0 ;
}
}
int F_18 ( struct V_40 * V_41 )
{
int V_61 , V_1 ;
struct V_25 * V_44 ;
struct V_42 * V_43 ;
V_1 = F_14 ( V_41 , & V_43 ) ;
if ( V_1 == - ( V_62 ) ) {
struct V_63 * V_64 ;
F_2 ( L_13 ) ;
if ( V_43 == NULL ) {
F_4 ( L_14 ) ;
return - V_65 ;
}
V_61 = F_19 ( V_5 ) ;
V_64 = V_5 -> V_15 [ V_61 ] . V_18 . V_51 ;
F_2 ( L_15 , V_61 ) ;
if ( V_61 < 0 ) {
F_20 ( V_43 ) ;
return - V_66 ;
}
V_1 = F_21 ( V_43 , V_41 -> V_28 ) ;
F_20 ( V_43 ) ;
V_5 -> V_15 [ V_61 ] . V_16 = V_21 ;
if ( ! V_1 ) {
F_2 ( L_16 ) ;
V_1 = F_14 ( V_41 , & V_43 ) ;
if ( V_1 <= 0 )
goto V_67;
F_2 ( L_17 , V_1 ) ;
} else {
F_2 ( L_18 ) ;
V_1 = - V_65 ;
goto V_67;
}
} else if ( V_1 <= 0 )
goto V_67;
V_44 = & V_5 -> V_27 [ V_1 ] ;
V_44 -> V_56 = F_17 ( V_41 ) ;
if ( V_41 -> V_28 == V_29 ||
V_41 -> V_28 == V_30 ) {
if ( V_5 -> V_9 == V_10 )
V_5 -> V_33 -> V_68 (
V_5 -> V_69 ) ;
else
V_5 -> V_33 -> V_68 (
V_44 -> V_35 ) ;
V_5 -> V_31 ++ ;
} else if ( V_41 -> V_28 == V_36 ) {
V_5 -> V_33 -> V_70 (
V_5 -> V_69 ) ;
V_5 -> V_37 ++ ;
}
V_67:
return V_1 ;
}
void F_22 ( struct V_71 * V_72 )
{
struct V_73 * V_74 =
F_23 ( V_72 , struct V_73 , V_75 ) ;
int V_1 = 0 ;
switch ( V_74 -> V_76 ) {
case V_77 :
V_1 = F_24 ( V_74 -> V_78 ) ;
break;
case V_79 :
V_1 = F_25 ( V_74 -> V_78 ) ;
break;
case V_80 :
V_1 = F_26 ( V_74 -> V_78 ) ;
break;
case V_81 :
F_2 ( L_19 ) ;
V_1 = F_27 ( V_74 -> V_78 ) ;
break;
case V_82 :
F_2 ( L_20 ) ;
break;
default:
F_4 ( L_21 ) ;
}
return;
}
void F_28 ( void )
{
if ( V_5 -> V_9 == V_10 &&
V_5 -> V_83 != V_84
&& V_5 -> V_85 != V_86 )
F_29 ( V_5 -> V_83 ) ;
}
int F_30 ( struct V_40 * V_41 )
{
struct V_25 * V_44 ;
int V_1 ;
F_31 ( & V_5 -> V_13 -> V_14 ) ;
if ( V_5 -> V_6 == V_87 ) {
F_2 ( L_22 ) ;
V_1 = F_32 ( V_5 -> V_13 ) ;
if ( V_1 ) {
F_4 ( L_23 , V_1 ) ;
F_33 ( & V_5 -> V_13 -> V_14 ) ;
return V_1 ;
}
}
if ( V_5 -> V_6 == V_7 ) {
F_2 ( L_24 ) ;
V_1 = F_1 () ;
if ( V_1 ) {
F_4 ( L_25 , V_1 ) ;
F_33 ( & V_5 -> V_13 -> V_14 ) ;
return V_1 ;
}
F_28 () ;
}
if ( ! V_41 ) {
F_33 ( & V_5 -> V_13 -> V_14 ) ;
return - V_88 ;
}
V_1 = F_18 ( V_41 ) ;
if ( V_1 > 0 ) {
V_5 -> V_89 ++ ;
V_44 = & V_5 -> V_27 [ V_1 ] ;
V_44 -> V_90 = V_91 ;
} else
F_33 ( & V_5 -> V_13 -> V_14 ) ;
return V_1 ;
}
int F_34 ( unsigned int V_24 )
{
struct V_25 * V_26 ;
F_2 ( L_26 ) ;
if ( F_11 ( V_24 ) )
return - V_88 ;
V_26 = & V_5 -> V_27 [ V_24 ] ;
F_10 ( V_24 ) ;
V_26 -> V_92 = NULL ;
V_26 -> V_93 = V_94 ;
V_26 -> V_95 = NULL ;
V_5 -> V_89 -- ;
F_2 ( L_27 ) ;
F_33 ( & V_5 -> V_13 -> V_14 ) ;
return 0 ;
}
int F_35 ( int V_96 , void * V_97 )
{
int V_1 = 0 , V_24 = 0 ;
switch ( V_96 ) {
case V_77 :
case V_79 :
case V_80 :
case V_81 :
V_5 -> V_74 . V_76 = V_96 ;
V_5 -> V_74 . V_78 = * ( int * ) V_97 ;
F_36 ( V_5 -> V_98 , & V_5 -> V_74 . V_75 ) ;
break;
case V_99 : {
struct V_100 * V_44 ;
struct V_25 * V_26 ;
F_2 ( L_28 ) ;
V_44 = (struct V_100 * ) V_97 ;
V_24 = V_44 -> V_24 ;
V_1 = F_11 ( V_24 ) ;
if ( V_1 )
break;
V_26 = & V_5 -> V_27 [ V_24 ] ;
F_2 ( L_29 ) ;
V_26 -> V_92 = V_44 -> V_101 ;
V_26 -> V_95 = V_44 -> V_95 ;
V_26 -> V_56 = V_44 -> V_56 ;
V_26 -> V_102 = V_26 -> V_93 ;
V_26 -> V_93 = V_103 ;
break;
}
case V_104 : {
struct V_100 * V_25 ;
struct V_105 V_106 = { 0 ,} ;
struct V_25 * V_26 ;
V_25 = (struct V_100 * ) V_97 ;
V_24 = V_25 -> V_24 ;
V_1 = F_11 ( V_24 ) ;
if ( V_1 )
break;
V_26 = & V_5 -> V_27 [ V_24 ] ;
if ( ! V_26 -> V_92 )
break;
F_37 ( & V_106 ,
( ( void * ) ( V_5 -> V_107 + V_108 )
+ ( V_24 * sizeof( V_106 ) ) ) ,
sizeof( V_106 ) ) ;
F_2 ( L_30 ,
V_24 , V_26 -> V_28 ) ;
if ( V_26 -> V_28 == V_29 )
V_25 -> V_109 = V_106 . V_110 ;
else
V_25 -> V_109 = V_106 . V_111 ;
F_2 ( L_31 ,
V_106 . V_110 , V_25 -> V_109 ) ;
break;
}
case V_112 : {
int V_93 = * ( int * ) V_97 ;
V_5 -> V_83 = V_93 ;
F_29 ( V_93 ) ;
break;
}
default:
F_38 ( L_32 ) ;
return - V_88 ;
}
return V_1 ;
}
int F_39 ( struct V_113 * V_114 )
{
if ( ! V_5 ) {
F_4 ( L_33 ) ;
return - V_115 ;
}
if ( ! V_114 || ! V_114 -> V_116 ) {
F_4 ( L_34 ) ;
return - V_88 ;
}
if ( V_5 -> V_117 == V_118 ) {
if ( ( strncmp ( V_119 , V_114 -> V_116 ,
strlen ( V_119 ) ) ) == 0 ) {
V_5 -> V_85 = V_114 -> V_120 ;
V_5 -> V_33 = V_114 -> V_33 ;
V_121 . V_116 = V_114 -> V_116 ;
V_5 -> V_117 = V_122 ;
V_5 -> V_83 = 0 ;
V_114 -> V_123 = V_121 . V_123 ;
return 0 ;
} else {
F_4 ( L_35 , V_114 -> V_116 ) ;
return - V_88 ;
}
} else {
F_4 ( L_36 ) ;
return - V_124 ;
}
if ( V_5 -> V_33 )
V_5 -> V_33 -> V_125 = V_126 ;
return 0 ;
}
void F_40 ( struct V_113 * V_114 )
{
if ( V_121 . V_123 == V_114 -> V_123 ) {
V_121 . V_116 = L_37 ;
V_5 -> V_117 = V_118 ;
F_2 ( L_38 , V_114 -> V_116 ) ;
}
return;
}
