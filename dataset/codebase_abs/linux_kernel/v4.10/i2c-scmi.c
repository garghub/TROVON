static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned short V_4 ,
char V_5 , T_2 V_6 , int V_7 ,
union V_8 * V_9 )
{
int V_10 = 0 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned char V_14 ;
T_3 V_15 = 0 ;
struct V_16 V_17 ;
union V_18 V_19 [ 5 ] ;
struct V_20 V_21 = { V_22 , NULL } ;
union V_18 * V_23 ;
union V_18 * V_24 ;
char * V_25 ;
int V_26 = 0 ;
F_2 ( & V_2 -> V_27 , L_1 , V_7 ,
( V_5 ) ? L_2 : L_3 ) ;
switch ( V_7 ) {
case V_28 :
V_14 = V_29 ;
V_6 = 0 ;
if ( V_5 == V_30 ) {
V_19 [ 3 ] . type = V_31 ;
V_19 [ 3 ] . integer . V_32 = 0 ;
V_19 [ 4 ] . type = V_31 ;
V_19 [ 4 ] . integer . V_32 = 0 ;
}
break;
case V_33 :
V_14 = V_34 ;
if ( V_5 == V_30 ) {
V_19 [ 3 ] . type = V_31 ;
V_19 [ 3 ] . integer . V_32 = 0 ;
V_19 [ 4 ] . type = V_31 ;
V_19 [ 4 ] . integer . V_32 = 0 ;
} else {
V_6 = 0 ;
}
break;
case V_35 :
V_14 = V_36 ;
if ( V_5 == V_30 ) {
V_19 [ 3 ] . type = V_31 ;
V_19 [ 3 ] . integer . V_32 = 1 ;
V_19 [ 4 ] . type = V_31 ;
V_19 [ 4 ] . integer . V_32 = V_9 -> V_37 ;
}
break;
case V_38 :
V_14 = V_39 ;
if ( V_5 == V_30 ) {
V_19 [ 3 ] . type = V_31 ;
V_19 [ 3 ] . integer . V_32 = 2 ;
V_19 [ 4 ] . type = V_31 ;
V_19 [ 4 ] . integer . V_32 = V_9 -> V_40 ;
}
break;
case V_41 :
V_14 = V_42 ;
if ( V_5 == V_30 ) {
V_26 = V_9 -> V_43 [ 0 ] ;
if ( V_26 == 0 || V_26 > V_44 )
return - V_45 ;
V_19 [ 3 ] . type = V_31 ;
V_19 [ 3 ] . integer . V_32 = V_26 ;
V_19 [ 4 ] . type = V_46 ;
V_19 [ 4 ] . V_21 . V_47 = V_9 -> V_43 + 1 ;
}
break;
default:
F_3 ( & V_2 -> V_27 , L_4 , V_7 ) ;
return - V_48 ;
}
if ( V_5 == V_49 ) {
V_14 |= V_50 ;
V_25 = V_12 -> V_51 -> V_52 ;
V_17 . V_53 = 3 ;
} else {
V_14 |= V_54 ;
V_25 = V_12 -> V_51 -> V_55 ;
V_17 . V_53 = 5 ;
}
V_17 . V_47 = V_19 ;
V_19 [ 0 ] . type = V_31 ;
V_19 [ 0 ] . integer . V_32 = V_14 ;
V_19 [ 1 ] . type = V_31 ;
V_19 [ 1 ] . integer . V_32 = V_3 ;
V_19 [ 2 ] . type = V_31 ;
V_19 [ 2 ] . integer . V_32 = V_6 ;
V_15 = F_4 ( V_12 -> V_56 , V_25 , & V_17 ,
& V_21 ) ;
if ( F_5 ( V_15 ) ) {
F_6 ( ( V_57 , L_5 , V_25 , V_15 ) ) ;
return - V_58 ;
}
V_24 = V_21 . V_47 ;
if ( V_24 && V_24 -> type == V_59 )
V_23 = V_24 -> V_60 . V_61 ;
else {
F_6 ( ( V_57 , L_6 ) ) ;
V_10 = - V_58 ;
goto V_62;
}
if ( V_23 == NULL || V_23 -> type != V_31 ) {
F_6 ( ( V_57 , L_6 ) ) ;
V_10 = - V_58 ;
goto V_62;
}
V_10 = V_23 -> integer . V_32 ;
F_7 ( ( V_63 , L_7 ,
V_25 , V_10 ) ) ;
switch ( V_10 ) {
case V_64 :
V_10 = 0 ;
break;
case V_65 :
V_10 = - V_66 ;
goto V_62;
case V_67 :
V_10 = - V_68 ;
goto V_62;
case V_69 :
V_10 = - V_70 ;
goto V_62;
default:
V_10 = - V_58 ;
goto V_62;
}
if ( V_5 == V_30 || V_7 == V_28 )
goto V_62;
V_23 = V_24 -> V_60 . V_61 + 1 ;
if ( V_23 -> type != V_31 ) {
F_6 ( ( V_57 , L_6 ) ) ;
V_10 = - V_58 ;
goto V_62;
}
V_26 = V_23 -> integer . V_32 ;
V_23 = V_24 -> V_60 . V_61 + 2 ;
switch ( V_7 ) {
case V_33 :
case V_35 :
case V_38 :
if ( V_23 -> type != V_31 ) {
F_6 ( ( V_57 , L_6 ) ) ;
V_10 = - V_58 ;
goto V_62;
}
if ( V_26 == 2 )
V_9 -> V_40 = V_23 -> integer . V_32 ;
else
V_9 -> V_37 = V_23 -> integer . V_32 ;
break;
case V_41 :
if ( V_23 -> type != V_46 ) {
F_6 ( ( V_57 , L_6 ) ) ;
V_10 = - V_58 ;
goto V_62;
}
if ( V_26 == 0 || V_26 > V_44 )
return - V_71 ;
V_9 -> V_43 [ 0 ] = V_26 ;
memcpy ( V_9 -> V_43 + 1 , V_23 -> V_21 . V_47 , V_26 ) ;
break;
}
V_62:
F_8 ( V_21 . V_47 ) ;
F_2 ( & V_2 -> V_27 , L_8 , V_10 ) ;
return V_10 ;
}
static T_4 F_9 ( struct V_1 * V_72 )
{
struct V_11 * V_12 = V_72 -> V_13 ;
T_4 V_73 ;
V_73 = V_12 -> V_74 | V_12 -> V_75 ?
V_76 : 0 ;
V_73 |= V_12 -> V_74 ?
( V_77 |
V_78 |
V_79 |
V_80 ) : 0 ;
V_73 |= V_12 -> V_75 ?
( V_81 |
V_82 |
V_83 |
V_84 ) : 0 ;
return V_73 ;
}
static int F_10 ( struct V_11 * V_12 ,
const char * V_85 )
{
struct V_20 V_21 = { V_22 , NULL } ;
union V_18 * V_23 ;
T_3 V_15 ;
if ( ! strcmp ( V_85 , V_12 -> V_51 -> V_86 ) ) {
V_15 = F_4 ( V_12 -> V_56 ,
V_12 -> V_51 -> V_86 ,
NULL , & V_21 ) ;
if ( F_5 ( V_15 ) ) {
F_6 ( ( V_57 , L_5 ,
V_12 -> V_51 -> V_86 , V_15 ) ) ;
return - V_58 ;
}
V_23 = V_21 . V_47 ;
if ( V_23 && V_23 -> type == V_59 )
V_23 = V_23 -> V_60 . V_61 ;
else {
F_6 ( ( V_57 , L_6 ) ) ;
F_8 ( V_21 . V_47 ) ;
return - V_58 ;
}
if ( V_23 -> type != V_31 ) {
F_6 ( ( V_57 , L_6 ) ) ;
F_8 ( V_21 . V_47 ) ;
return - V_58 ;
} else
F_7 ( ( V_63 , L_9
L_10 , ( int ) V_23 -> integer . V_32 ) ) ;
F_8 ( V_21 . V_47 ) ;
V_12 -> V_87 = 1 ;
} else if ( ! strcmp ( V_85 , V_12 -> V_51 -> V_52 ) )
V_12 -> V_74 = 1 ;
else if ( ! strcmp ( V_85 , V_12 -> V_51 -> V_55 ) )
V_12 -> V_75 = 1 ;
else
F_7 ( ( V_63 , L_11 ,
V_85 ) ) ;
return 0 ;
}
static T_3 F_11 ( T_5 V_56 , T_4 V_88 ,
void * V_89 , void * * V_90 )
{
char V_91 [ 5 ] ;
struct V_20 V_21 = { sizeof( V_91 ) , V_91 } ;
struct V_11 * V_12 = V_89 ;
T_3 V_15 ;
V_15 = F_12 ( V_56 , V_92 , & V_21 ) ;
if ( F_13 ( V_15 ) )
F_10 ( V_12 , V_91 ) ;
return V_93 ;
}
static int F_14 ( struct V_94 * V_95 )
{
struct V_11 * V_12 ;
const struct V_96 * V_97 ;
V_12 = F_15 ( sizeof( struct V_11 ) , V_98 ) ;
if ( ! V_12 )
return - V_99 ;
V_12 -> V_56 = V_95 -> V_56 ;
strcpy ( F_16 ( V_95 ) , V_100 ) ;
strcpy ( F_17 ( V_95 ) , V_101 ) ;
V_95 -> V_102 = V_12 ;
V_12 -> V_87 = 0 ;
V_12 -> V_74 = 0 ;
V_12 -> V_75 = 0 ;
for ( V_97 = V_103 ; V_97 -> V_97 [ 0 ] ; V_97 ++ )
if ( ! strcmp ( V_97 -> V_97 , F_18 ( V_95 ) ) )
V_12 -> V_51 =
(struct V_104 * ) V_97 -> V_102 ;
F_19 ( V_105 , V_12 -> V_56 , 1 ,
F_11 , NULL , V_12 , NULL ) ;
if ( V_12 -> V_87 == 0 )
goto V_106;
snprintf ( V_12 -> V_72 . V_85 , sizeof( V_12 -> V_72 . V_85 ) ,
L_12 ,
F_16 ( V_95 ) ) ;
V_12 -> V_72 . V_107 = V_108 ;
V_12 -> V_72 . V_109 = & V_110 ;
V_12 -> V_72 . V_13 = V_12 ;
V_12 -> V_72 . V_111 = V_112 | V_113 ;
V_12 -> V_72 . V_27 . V_114 = & V_95 -> V_27 ;
if ( F_20 ( & V_12 -> V_72 ) ) {
F_21 ( & V_95 -> V_27 , L_13 ) ;
goto V_106;
}
return 0 ;
V_106:
F_8 ( V_12 ) ;
V_95 -> V_102 = NULL ;
return - V_58 ;
}
static int F_22 ( struct V_94 * V_95 )
{
struct V_11 * V_12 = F_23 ( V_95 ) ;
F_24 ( & V_12 -> V_72 ) ;
F_8 ( V_12 ) ;
V_95 -> V_102 = NULL ;
return 0 ;
}
