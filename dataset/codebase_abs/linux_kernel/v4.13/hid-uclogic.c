static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
T_1 V_9 = V_6 -> V_10 -> V_11 . V_12 ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
if ( V_14 -> V_3 != NULL ) {
V_3 = V_14 -> V_3 ;
* V_4 = V_14 -> V_4 ;
return V_3 ;
}
switch ( V_2 -> V_15 ) {
case V_16 :
if ( * V_4 == V_17 ) {
V_3 = V_18 ;
* V_4 = sizeof( V_18 ) ;
}
break;
case V_19 :
if ( * V_4 == V_20 ) {
V_3 = V_21 ;
* V_4 = sizeof( V_21 ) ;
}
break;
case V_22 :
if ( * V_4 == V_20 ) {
V_3 = V_23 ;
* V_4 = sizeof( V_23 ) ;
}
break;
case V_24 :
if ( * V_4 == V_20 ) {
V_3 = V_25 ;
* V_4 = sizeof( V_25 ) ;
}
break;
case V_26 :
if ( * V_4 == V_27 ) {
V_3 = V_28 ;
* V_4 = sizeof( V_28 ) ;
}
break;
case V_29 :
switch ( V_9 ) {
case 0 :
if ( * V_4 == V_30 ) {
V_3 = V_31 ;
* V_4 = sizeof( V_31 ) ;
}
break;
case 1 :
if ( * V_4 == V_32 ) {
V_3 = V_33 ;
* V_4 = sizeof( V_33 ) ;
}
break;
case 2 :
if ( * V_4 == V_34 ) {
V_3 = V_35 ;
* V_4 = sizeof( V_35 ) ;
}
break;
}
break;
case V_36 :
switch ( V_9 ) {
case 0 :
if ( * V_4 == V_37 ) {
V_3 = V_38 ;
* V_4 = sizeof( V_38 ) ;
}
break;
case 1 :
if ( * V_4 == V_39 ) {
V_3 = V_40 ;
* V_4 = sizeof( V_40 ) ;
}
break;
}
break;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 , struct V_45 * V_46 ,
unsigned long * * V_47 , int * V_48 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
if ( ( V_14 -> V_49 ) &&
( V_44 -> V_50 == V_51 ) )
return - 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
char * V_52 ;
const char * V_53 = NULL ;
struct V_43 * V_44 ;
T_2 V_54 ;
if ( ! V_42 -> V_55 )
return 0 ;
V_44 = V_42 -> V_55 -> V_44 [ 0 ] ;
switch ( V_44 -> V_50 ) {
case V_56 :
V_53 = L_1 ;
break;
case V_57 :
V_53 = L_2 ;
break;
case V_58 :
V_53 = L_3 ;
break;
case V_51 :
V_53 = L_4 ;
break;
case V_59 :
V_53 = L_5 ;
break;
case V_60 :
V_53 = L_6 ;
break;
}
if ( V_53 ) {
V_54 = strlen ( V_2 -> V_52 ) + 2 + strlen ( V_53 ) ;
V_52 = F_6 ( & V_42 -> V_61 -> V_7 , V_54 , V_62 ) ;
if ( V_52 ) {
snprintf ( V_52 , V_54 , L_7 , V_2 -> V_52 , V_53 ) ;
V_42 -> V_61 -> V_52 = V_52 ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_63 ;
struct V_64 * V_65 = F_8 ( V_2 ) ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
T_3 * V_66 = NULL ;
T_2 V_54 ;
T_4 V_67 [ V_68 ] ;
T_4 V_69 ;
T_1 * V_70 ;
T_4 V_71 ;
V_54 = V_72 * sizeof( * V_66 ) ;
V_66 = F_9 ( V_54 , V_62 ) ;
if ( V_66 == NULL ) {
V_63 = - V_73 ;
goto V_74;
}
V_63 = F_10 ( V_65 , F_11 ( V_65 , 0 ) ,
V_75 , V_76 ,
( V_77 << 8 ) + 0x64 ,
0x0409 , V_66 , V_54 ,
V_78 ) ;
if ( V_63 == - V_79 ) {
F_12 ( V_2 , L_8 ) ;
V_63 = - V_80 ;
goto V_74;
} else if ( V_63 < 0 ) {
F_12 ( V_2 , L_9 , V_63 ) ;
V_63 = - V_80 ;
goto V_74;
} else if ( V_63 != V_54 ) {
F_12 ( V_2 , L_10 ) ;
V_63 = - V_80 ;
goto V_74;
}
V_67 [ V_81 ] = F_13 ( V_66 [ V_82 ] ) ;
V_67 [ V_83 ] = F_13 ( V_66 [ V_84 ] ) ;
V_67 [ V_85 ] =
F_13 ( V_66 [ V_86 ] ) ;
V_69 = F_13 ( V_66 [ V_87 ] ) ;
if ( V_69 == 0 ) {
V_67 [ V_88 ] = 0 ;
V_67 [ V_89 ] = 0 ;
} else {
V_67 [ V_88 ] = V_67 [ V_81 ] *
1000 / V_69 ;
V_67 [ V_89 ] = V_67 [ V_83 ] *
1000 / V_69 ;
}
V_14 -> V_3 = F_6 ( & V_2 -> V_7 ,
sizeof( V_90 ) ,
V_62 ) ;
if ( V_14 -> V_3 == NULL ) {
V_63 = - V_73 ;
goto V_74;
}
V_14 -> V_4 = sizeof( V_90 ) ;
memcpy ( V_14 -> V_3 , V_90 ,
V_14 -> V_4 ) ;
for ( V_70 = V_14 -> V_3 ;
V_70 <= V_14 -> V_3 + V_14 -> V_4 - 4 ; ) {
if ( V_70 [ 0 ] == 0xFE && V_70 [ 1 ] == 0xED && V_70 [ 2 ] == 0x1D &&
V_70 [ 3 ] < F_14 ( V_67 ) ) {
V_71 = V_67 [ V_70 [ 3 ] ] ;
F_15 ( F_16 ( V_71 ) , ( T_4 * ) V_70 ) ;
V_70 += 4 ;
} else {
V_70 ++ ;
}
}
V_63 = 0 ;
V_74:
F_17 ( V_66 ) ;
return V_63 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_63 ;
struct V_64 * V_65 = F_8 ( V_2 ) ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
char * V_91 ;
T_2 V_92 = 16 ;
unsigned char * V_3 ;
T_2 V_93 ;
V_91 = F_19 ( V_92 , V_62 ) ;
if ( V_91 == NULL ) {
V_63 = - V_73 ;
goto V_74;
}
V_63 = F_20 ( V_65 , 0x7b , V_91 , V_92 ) ;
if ( V_63 == - V_79 ) {
F_21 ( V_2 , L_11 ) ;
V_63 = 0 ;
goto V_74;
} else if ( V_63 < 0 ) {
F_12 ( V_2 , L_12 ) ;
goto V_74;
} else if ( strncmp ( V_91 , L_13 , V_63 ) ) {
F_21 ( V_2 , L_14 ,
V_91 ) ;
V_63 = - V_94 ;
goto V_74;
}
V_93 = V_14 -> V_4 + sizeof( V_95 ) ;
V_3 = F_6 ( & V_2 -> V_7 , V_93 , V_62 ) ;
if ( ! V_3 ) {
V_63 = - V_73 ;
goto V_74;
}
memcpy ( V_3 , V_14 -> V_3 , V_14 -> V_4 ) ;
memcpy ( V_3 + V_14 -> V_4 , V_95 ,
sizeof( V_95 ) ) ;
V_14 -> V_4 = V_93 ;
F_22 ( & V_2 -> V_7 , V_14 -> V_3 ) ;
V_14 -> V_3 = V_3 ;
V_63 = 0 ;
V_74:
F_17 ( V_91 ) ;
return V_63 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_96 * V_97 )
{
int V_63 ;
struct V_5 * V_98 = F_2 ( V_2 -> V_7 . V_8 ) ;
struct V_64 * V_99 = F_8 ( V_2 ) ;
struct V_13 * V_14 ;
V_2 -> V_100 |= V_101 ;
V_2 -> V_100 |= V_102 ;
V_14 = F_6 ( & V_2 -> V_7 , sizeof( * V_14 ) , V_62 ) ;
if ( V_14 == NULL )
return - V_73 ;
F_24 ( V_2 , V_14 ) ;
switch ( V_97 -> V_15 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
if ( V_98 -> V_10 -> V_11 . V_12 == 0 ) {
V_63 = F_7 ( V_2 ) ;
if ( V_63 ) {
F_12 ( V_2 , L_15 ) ;
return V_63 ;
}
V_14 -> V_108 = true ;
V_63 = F_18 ( V_2 ) ;
V_14 -> V_109 = ! V_63 ;
} else {
V_14 -> V_49 = true ;
}
break;
case V_110 :
case V_111 :
if ( V_98 -> V_10 -> V_11 . V_12 == 1 ) {
V_63 = F_7 ( V_2 ) ;
if ( V_63 ) {
F_12 ( V_2 , L_15 ) ;
return V_63 ;
}
V_14 -> V_108 = true ;
} else {
V_14 -> V_49 = true ;
}
break;
case V_36 :
if ( V_99 -> V_112 -> V_11 . V_113 == 3 ) {
if ( V_98 -> V_10 -> V_11 . V_12 == 0 ) {
V_63 = F_7 ( V_2 ) ;
if ( V_63 ) {
F_12 ( V_2 , L_15 ) ;
return V_63 ;
}
V_14 -> V_108 = true ;
V_63 = F_18 ( V_2 ) ;
V_14 -> V_109 = ! V_63 ;
} else {
V_14 -> V_49 = true ;
}
}
break;
}
V_63 = F_25 ( V_2 ) ;
if ( V_63 ) {
F_12 ( V_2 , L_16 ) ;
return V_63 ;
}
V_63 = F_26 ( V_2 , V_114 ) ;
if ( V_63 ) {
F_12 ( V_2 , L_17 ) ;
return V_63 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_115 * V_55 ,
T_5 * V_116 , int V_117 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
if ( ( V_55 -> type == V_118 ) &&
( V_55 -> V_97 == V_119 ) &&
( V_117 >= 2 ) ) {
if ( V_14 -> V_109 && ( V_116 [ 1 ] & 0x20 ) )
V_116 [ 0 ] = 0xf7 ;
else if ( V_14 -> V_108 )
V_116 [ 1 ] ^= 0x40 ;
}
return 0 ;
}
