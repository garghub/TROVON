int F_1 ( void )
{
int V_1 ;
const struct V_2 * V_3 ;
char V_4 [ 20 ] ;
if ( V_5 -> V_6 != V_7 )
return - V_8 ;
snprintf ( V_4 , sizeof( V_4 ) , L_1 , L_2 ,
V_5 -> V_9 , L_3 ) ;
F_2 ( L_4 , V_4 ) ;
V_1 = F_3 ( & V_3 , V_4 , & V_5 -> V_10 -> V_11 ) ;
if ( V_1 ) {
F_4 ( L_5 , V_1 ) ;
return V_1 ;
}
V_5 -> V_12 [ 0 ] . V_13 = V_14 ;
V_5 -> V_12 [ 0 ] . V_15 . V_16 = false ;
V_1 = F_5 ( V_3 , NULL ) ;
if ( V_1 )
goto V_17;
V_1 = F_6 ( V_5 , & V_5 -> V_12 [ 0 ] ) ;
if ( V_1 )
F_4 ( L_6 , V_1 ) ;
V_17:
F_7 ( V_3 ) ;
V_5 -> V_12 [ 0 ] . V_13 = V_18 ;
return V_1 ;
}
int F_8 ( void )
{
int V_19 = 1000 ;
int V_1 = - 1 ;
while ( V_19 ) {
if ( ! V_5 -> V_20 )
return 0 ;
F_9 ( 1 ) ;
V_19 -- ;
}
F_2 ( L_7 ) ;
return V_1 ;
}
void F_10 ( unsigned int V_21 )
{
struct V_22 * V_23 ;
if ( ! F_11 ( V_21 ) ) {
V_23 = & V_5 -> V_24 [ V_21 ] ;
if ( F_12 ( V_21 ) )
F_13 ( & V_5 -> V_24 [ V_21 ] ) ;
if ( V_23 -> V_25 == V_26 ||
V_23 -> V_25 == V_27 ) {
V_5 -> V_28 -- ;
if ( V_5 -> V_9 == V_29 )
V_5 -> V_30 -> V_31 (
V_23 -> V_32 ) ;
else {
if ( V_5 -> V_28 == 0 )
V_5 -> V_30 ->
V_31 ( V_23 -> V_32 ) ;
}
} else if ( V_23 -> V_25 == V_33 ) {
V_5 -> V_34 -- ;
if ( V_5 -> V_34 == 0 )
V_5 -> V_30 -> V_35 (
V_23 -> V_32 ) ;
}
if ( V_5 -> V_28 == 0
&& V_5 -> V_34 == 0 )
V_5 -> V_30 -> V_36 () ;
}
}
int F_14 ( struct V_37 * V_38 ,
struct V_39 * * V_40 )
{
int V_1 , V_21 ;
struct V_22 * V_41 ;
V_1 = F_15 ( ( char * ) & V_38 -> V_42 , V_38 -> V_25 ,
V_38 -> V_43 , V_38 -> V_44 ) ;
if ( V_1 < 0 ) {
F_4 ( L_8 , V_1 ) ;
return V_1 ;
}
F_2 ( L_9 , V_1 ) ;
V_21 = V_1 ;
V_41 = & V_5 -> V_24 [ V_21 ] ;
V_1 = F_16 ( V_5 ,
& V_41 -> V_45 , V_46 ) ;
if ( ( V_1 != 0 ) || ( V_41 -> V_45 . V_47 != 0 ) ) {
F_2 ( L_10 ,
V_1 , V_41 -> V_45 . V_47 ) ;
V_21 = - V_41 -> V_45 . V_47 ;
* V_40 = V_41 -> V_45 . V_48 ;
F_13 ( V_41 ) ;
} else
F_2 ( L_11 ) ;
return V_21 ;
}
static int F_17 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_43 ) {
case V_49 :
return 48000 ;
case V_50 :
return V_38 -> V_42 . V_51 . V_52 . V_53 ;
case V_54 :
return V_38 -> V_42 . V_51 . V_55 . V_53 ;
case V_56 :
return V_38 -> V_42 . V_51 . V_57 . V_53 ;
default:
return 0 ;
}
}
int F_18 ( struct V_37 * V_38 )
{
int V_58 , V_1 ;
struct V_22 * V_41 ;
struct V_39 * V_40 ;
V_1 = F_14 ( V_38 , & V_40 ) ;
if ( V_1 == - ( V_59 ) ) {
struct V_60 * V_61 ;
F_2 ( L_12 ) ;
if ( V_40 == NULL ) {
F_4 ( L_13 ) ;
return - V_62 ;
}
V_58 = F_19 ( V_5 ) ;
V_61 = V_5 -> V_12 [ V_58 ] . V_15 . V_48 ;
F_2 ( L_14 , V_58 ) ;
if ( V_58 < 0 ) {
F_20 ( V_40 ) ;
return - V_63 ;
}
V_1 = F_21 ( V_40 , V_38 -> V_25 ) ;
F_20 ( V_40 ) ;
V_5 -> V_12 [ V_58 ] . V_13 = V_18 ;
if ( ! V_1 ) {
F_2 ( L_15 ) ;
V_1 = F_14 ( V_38 , & V_40 ) ;
if ( V_1 <= 0 )
goto V_64;
F_2 ( L_16 , V_1 ) ;
} else {
F_2 ( L_17 ) ;
V_1 = - V_62 ;
goto V_64;
}
} else if ( V_1 <= 0 )
goto V_64;
V_41 = & V_5 -> V_24 [ V_1 ] ;
V_41 -> V_53 = F_17 ( V_38 ) ;
if ( V_38 -> V_25 == V_26 ||
V_38 -> V_25 == V_27 ) {
if ( V_5 -> V_9 == V_65 )
V_5 -> V_30 -> V_66 (
V_5 -> V_67 ) ;
else
V_5 -> V_30 -> V_66 (
V_41 -> V_32 ) ;
V_5 -> V_28 ++ ;
} else if ( V_38 -> V_25 == V_33 ) {
V_5 -> V_30 -> V_68 (
V_5 -> V_67 ) ;
V_5 -> V_34 ++ ;
}
V_64:
return V_1 ;
}
void F_22 ( struct V_69 * V_70 )
{
struct V_71 * V_72 =
F_23 ( V_70 , struct V_71 , V_73 ) ;
int V_1 = 0 ;
switch ( V_72 -> V_74 ) {
case V_75 :
V_1 = F_24 ( V_72 -> V_76 ) ;
break;
case V_77 :
V_1 = F_25 ( V_72 -> V_76 ) ;
break;
case V_78 :
V_1 = F_26 ( V_72 -> V_76 ) ;
break;
case V_79 :
F_2 ( L_18 ) ;
V_1 = F_27 ( V_72 -> V_76 ) ;
break;
case V_80 :
F_2 ( L_19 ) ;
break;
default:
F_4 ( L_20 ) ;
}
return;
}
void F_28 ( void )
{
if ( V_5 -> V_9 == V_65 &&
V_5 -> V_81 != V_82
&& V_5 -> V_83 != V_84 )
F_29 ( V_5 -> V_81 ) ;
}
int F_30 ( struct V_37 * V_38 )
{
struct V_22 * V_41 ;
int V_1 ;
F_31 ( & V_5 -> V_10 -> V_11 ) ;
if ( V_5 -> V_6 == V_85 ) {
F_2 ( L_21 ) ;
V_1 = F_32 ( V_5 -> V_10 ) ;
if ( V_1 ) {
F_4 ( L_22 , V_1 ) ;
F_33 ( & V_5 -> V_10 -> V_11 ) ;
return V_1 ;
}
}
if ( V_5 -> V_6 == V_7 ) {
F_2 ( L_23 ) ;
V_1 = F_1 () ;
if ( V_1 ) {
F_4 ( L_24 , V_1 ) ;
F_33 ( & V_5 -> V_10 -> V_11 ) ;
return V_1 ;
}
F_28 () ;
}
if ( ! V_38 ) {
F_33 ( & V_5 -> V_10 -> V_11 ) ;
return - V_86 ;
}
V_1 = F_18 ( V_38 ) ;
if ( V_1 > 0 ) {
V_5 -> V_87 ++ ;
V_41 = & V_5 -> V_24 [ V_1 ] ;
V_41 -> V_88 = V_89 ;
} else
F_33 ( & V_5 -> V_10 -> V_11 ) ;
return V_1 ;
}
int F_34 ( unsigned int V_21 )
{
struct V_22 * V_23 ;
F_2 ( L_25 ) ;
if ( F_11 ( V_21 ) )
return - V_86 ;
V_23 = & V_5 -> V_24 [ V_21 ] ;
F_10 ( V_21 ) ;
V_23 -> V_90 = NULL ;
V_23 -> V_91 = V_92 ;
V_23 -> V_93 = NULL ;
V_5 -> V_87 -- ;
F_2 ( L_26 ) ;
F_33 ( & V_5 -> V_10 -> V_11 ) ;
return 0 ;
}
int F_35 ( int V_94 , void * V_95 )
{
int V_1 = 0 , V_21 = 0 ;
switch ( V_94 ) {
case V_75 :
case V_77 :
case V_78 :
case V_79 :
V_5 -> V_72 . V_74 = V_94 ;
V_5 -> V_72 . V_76 = * ( int * ) V_95 ;
F_36 ( V_5 -> V_96 , & V_5 -> V_72 . V_73 ) ;
break;
case V_97 : {
struct V_98 * V_41 ;
struct V_22 * V_23 ;
F_2 ( L_27 ) ;
V_41 = (struct V_98 * ) V_95 ;
V_21 = V_41 -> V_21 ;
V_1 = F_11 ( V_21 ) ;
if ( V_1 )
break;
V_23 = & V_5 -> V_24 [ V_21 ] ;
F_2 ( L_28 ) ;
V_23 -> V_90 = V_41 -> V_99 ;
V_23 -> V_93 = V_41 -> V_93 ;
V_23 -> V_53 = V_41 -> V_53 ;
V_23 -> V_100 = V_23 -> V_91 ;
V_23 -> V_91 = V_101 ;
break;
}
case V_102 : {
struct V_98 * V_22 ;
struct V_103 V_104 = { 0 ,} ;
struct V_22 * V_23 ;
V_22 = (struct V_98 * ) V_95 ;
V_21 = V_22 -> V_21 ;
V_1 = F_11 ( V_21 ) ;
if ( V_1 )
break;
V_23 = & V_5 -> V_24 [ V_21 ] ;
if ( ! V_23 -> V_90 )
break;
F_37 ( & V_104 ,
( ( void * ) ( V_5 -> V_105 + V_106 )
+ ( V_21 * sizeof( V_104 ) ) ) ,
sizeof( V_104 ) ) ;
F_2 ( L_29 ,
V_21 , V_23 -> V_25 ) ;
if ( V_23 -> V_25 == V_26 )
V_22 -> V_107 = V_104 . V_108 ;
else
V_22 -> V_107 = V_104 . V_109 ;
F_2 ( L_30 ,
V_104 . V_108 , V_22 -> V_107 ) ;
break;
}
case V_110 : {
int V_91 = * ( int * ) V_95 ;
V_5 -> V_81 = V_91 ;
F_29 ( V_91 ) ;
break;
}
default:
F_38 ( L_31 ) ;
return - V_86 ;
}
return V_1 ;
}
int F_39 ( struct V_111 * V_112 )
{
if ( ! V_5 ) {
F_4 ( L_32 ) ;
return - V_113 ;
}
if ( ! V_112 || ! V_112 -> V_114 ) {
F_4 ( L_33 ) ;
return - V_86 ;
}
if ( V_5 -> V_115 == V_116 ) {
if ( ( strncmp ( V_117 , V_112 -> V_114 ,
strlen ( V_117 ) ) ) == 0 ) {
V_5 -> V_83 = V_112 -> V_118 ;
V_5 -> V_30 = V_112 -> V_30 ;
V_119 . V_114 = V_112 -> V_114 ;
V_5 -> V_115 = V_120 ;
V_5 -> V_81 = 0 ;
V_112 -> V_121 = V_119 . V_121 ;
return 0 ;
} else {
F_4 ( L_34 , V_112 -> V_114 ) ;
return - V_86 ;
}
} else {
F_4 ( L_35 ) ;
return - V_122 ;
}
if ( V_5 -> V_30 )
V_5 -> V_30 -> V_123 = V_124 ;
return 0 ;
}
void F_40 ( struct V_111 * V_112 )
{
if ( V_119 . V_121 == V_112 -> V_121 ) {
V_119 . V_114 = L_36 ;
V_5 -> V_115 = V_116 ;
F_2 ( L_37 , V_112 -> V_114 ) ;
}
return;
}
