static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
const char * V_7 = L_1 ;
int V_8 ;
V_8 = F_2 ( V_4 , V_7 , & V_6 -> V_9 -> V_10 ) ;
if ( V_8 )
F_3 ( L_2 , V_7 ) ;
else {
T_1 V_11 = ( * V_4 ) -> V_12 ;
if ( V_11 < 2 || V_11 > 64 || ( V_11 % 2 ) != 0 ) {
F_3 ( L_3 ,
V_7 , ( unsigned long ) V_11 ) ;
V_8 = - V_13 ;
F_4 ( * V_4 ) ;
* V_4 = NULL ;
}
}
if ( V_8 ) {
F_3 ( L_4
L_5 ) ;
F_3 ( L_6
L_7 ) ;
}
return V_8 ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_6 ( V_15 -> V_17 ,
struct V_16 , V_18 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
const struct V_3 * V_4 = NULL ;
int V_8 ;
int V_19 ;
T_2 V_20 [ 3 ] ;
V_8 = F_1 ( V_2 , & V_4 ) ;
if ( V_8 )
return V_8 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_12 ; V_19 += 2 ) {
V_20 [ 0 ] = V_4 -> V_21 [ V_19 ] ;
switch ( V_20 [ 0 ] ) {
case V_22 :
break;
case V_23 :
V_20 [ 1 ] = 0x72 ;
V_20 [ 2 ] = 0x49 ;
F_7 ( V_15 , V_20 , 3 ) ;
break;
case V_24 :
break;
case V_25 :
V_20 [ 1 ] = 0x31 ;
V_20 [ 2 ] = 0xc0 ;
F_7 ( V_15 , V_20 , 3 ) ;
break;
default:
V_20 [ 1 ] = V_4 -> V_21 [ V_19 + 1 ] ;
F_7 ( V_15 , V_20 , 2 ) ;
break;
}
}
V_20 [ 0 ] = ( T_2 ) V_26 ;
V_20 [ 1 ] = 0x01 ;
F_7 ( V_15 , V_20 , 2 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_1 * V_2 = (struct V_1 * ) V_30 -> V_31 ;
struct V_5 * V_6 ;
int V_8 ;
T_3 V_32 ;
if ( ! V_2 )
return - V_33 ;
V_6 = V_2 -> V_6 ;
F_9 ( L_8 ,
V_28 -> V_34 , V_28 -> V_35 ) ;
F_10 ( & V_6 -> V_36 ) ;
V_8 = F_11 ( V_6 ) ;
F_12 ( & V_6 -> V_36 ) ;
if ( V_8 ) {
F_3 ( L_9 ) ;
return V_8 ;
}
V_8 = - V_33 ;
switch ( V_6 -> V_37 -> type ) {
case V_38 :
case V_39 :
case V_40 :
V_32 = F_13 ( V_6 , V_41 ) ;
V_32 |= 0x00400000 ;
V_32 |= 0x00002000 ;
V_32 |= 0x00010000 ;
V_32 |= 0x00020000 ;
V_32 |= 0x000c0000 ;
F_14 ( V_6 , V_32 , V_41 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
default:
break;
}
if ( ! V_30 -> V_45 . V_46 )
return - V_33 ;
F_10 ( & V_2 -> V_17 -> V_47 ) ;
if ( V_2 -> V_17 -> V_48 ++ == 0 ) {
F_9 ( L_10 ) ;
F_10 ( & V_6 -> V_36 ) ;
F_15 ( V_49 , & V_2 -> V_50 ) ;
V_8 = F_16 ( V_2 ) ;
if ( V_8 < 0 ) {
F_9 ( L_11 ) ;
V_2 -> V_17 -> V_48 -- ;
if ( V_2 -> V_17 -> V_48 == 0 )
F_17 ( V_49 , & V_2 -> V_50 ) ;
}
F_12 ( & V_6 -> V_36 ) ;
} else
V_8 = 0 ;
F_12 ( & V_2 -> V_17 -> V_47 ) ;
return V_8 ;
}
static int F_18 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_1 * V_2 = (struct V_1 * ) V_30 -> V_31 ;
struct V_5 * V_6 ;
int V_8 = - V_33 ;
if ( V_2 ) {
V_6 = V_2 -> V_6 ;
F_9 ( L_12 ,
V_28 -> V_34 , V_28 -> V_35 ) ;
F_10 ( & V_2 -> V_17 -> V_47 ) ;
if ( -- V_2 -> V_17 -> V_48 == 0 ) {
F_9 ( L_13 ) ;
F_10 ( & V_6 -> V_36 ) ;
V_8 = F_19 ( V_2 , 0 ) ;
F_12 ( & V_6 -> V_36 ) ;
} else
V_8 = 0 ;
F_12 ( & V_2 -> V_17 -> V_47 ) ;
}
return V_8 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 * V_18 ;
struct V_29 * V_51 ;
struct V_52 * V_45 ;
int V_8 ;
if ( ! V_17 )
return - V_33 ;
V_17 -> V_53 = 0 ;
V_17 -> V_2 = V_2 ;
V_8 = F_21 ( & V_17 -> V_18 ,
V_54 ,
V_55 , & V_6 -> V_9 -> V_10 , V_56 ) ;
if ( V_8 < 0 )
goto V_57;
V_18 = & V_17 -> V_18 ;
V_51 = & V_17 -> V_30 ;
V_51 -> V_31 = ( void * ) V_2 ;
V_51 -> V_58 = 256 ;
V_51 -> V_59 = 256 ;
V_51 -> V_60 = F_8 ;
V_51 -> V_61 = F_18 ;
V_51 -> V_45 . V_62 = ( V_63 |
V_64 | V_65 ) ;
V_8 = F_22 ( V_51 ) ;
if ( V_8 < 0 )
goto V_66;
V_45 = & V_51 -> V_45 ;
V_17 -> V_67 . V_68 = V_69 ;
V_17 -> V_70 . V_68 = V_71 ;
V_17 -> V_72 . V_58 = 256 ;
V_17 -> V_72 . V_30 = V_45 ;
V_8 = F_23 ( & V_17 -> V_72 , V_18 ) ;
if ( V_8 < 0 )
goto V_73;
V_8 = V_45 -> V_74 ( V_45 , & V_17 -> V_67 ) ;
if ( V_8 < 0 )
goto V_75;
V_8 = V_45 -> V_74 ( V_45 , & V_17 -> V_70 ) ;
if ( V_8 < 0 )
goto V_76;
V_8 = V_45 -> V_77 ( V_45 , & V_17 -> V_67 ) ;
if ( V_8 < 0 )
goto V_78;
V_8 = F_24 ( V_2 ) ;
if ( V_8 < 0 )
goto V_79;
F_25 ( V_18 , & V_17 -> V_80 , V_45 ) ;
F_26 ( L_14 ) ;
F_26 ( L_15 ,
V_2 -> V_17 -> V_18 . V_81 , V_2 -> V_82 ,
V_2 -> V_83 , V_2 -> V_84 / 1024 ,
( V_2 -> V_84 * 100 / 1024 ) % 100 ) ;
F_27 ( & V_17 -> V_47 ) ;
V_17 -> V_53 = 1 ;
return V_8 ;
V_79:
V_45 -> V_85 ( V_45 ) ;
V_78:
V_45 -> V_86 ( V_45 , & V_17 -> V_70 ) ;
V_76:
V_45 -> V_86 ( V_45 , & V_17 -> V_67 ) ;
V_75:
F_28 ( & V_17 -> V_72 ) ;
V_73:
F_29 ( V_51 ) ;
V_66:
F_30 ( V_18 ) ;
V_57:
return V_8 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 * V_18 ;
struct V_29 * V_51 ;
struct V_52 * V_45 ;
F_26 ( L_16 ) ;
if ( V_17 == NULL || ! V_17 -> V_53 )
return;
V_18 = & V_17 -> V_18 ;
V_51 = & V_17 -> V_30 ;
V_45 = & V_51 -> V_45 ;
V_45 -> V_87 ( V_45 ) ;
F_32 ( & V_17 -> V_80 ) ;
V_45 -> V_86 ( V_45 , & V_17 -> V_70 ) ;
V_45 -> V_86 ( V_45 , & V_17 -> V_67 ) ;
F_28 ( & V_17 -> V_72 ) ;
F_29 ( V_51 ) ;
F_33 ( V_17 -> V_15 ) ;
F_34 ( V_17 -> V_15 ) ;
F_30 ( V_18 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_8 = 0 ;
switch ( V_6 -> V_37 -> type ) {
case V_38 :
case V_39 :
V_17 -> V_15 = F_35 ( V_88 ,
& V_89 ,
& V_6 -> V_90 [ 0 ] ) ;
if ( V_17 -> V_15 != NULL ) {
F_35 ( V_91 , V_17 -> V_15 ,
& V_6 -> V_90 [ 0 ] ,
& V_92 ) ;
V_8 = 0 ;
}
break;
case V_40 :
V_17 -> V_15 = F_35 ( V_93 ,
& V_94 ,
& V_6 -> V_90 [ 0 ] ) ;
if ( V_17 -> V_15 != NULL )
F_35 ( V_95 , V_17 -> V_15 ,
0x60 , & V_6 -> V_90 [ 0 ] ,
& V_96 ) ;
break;
case V_42 :
V_17 -> V_15 = F_35 ( V_97 ,
& V_98 ,
& V_6 -> V_90 [ 1 ] ) ;
if ( V_17 -> V_15 != NULL ) {
struct V_14 * V_15 ;
struct V_99 V_100 = {
. V_90 = & V_6 -> V_90 [ 1 ] ,
. V_101 = 0xc2 >> 1 ,
. V_102 = NULL ,
} ;
static struct V_103 V_102 = {
. V_104 = V_105 ,
. V_106 = 64 ,
. V_107 = V_108 ,
. type = V_109 ,
} ;
V_15 = F_35 ( V_110 , V_17 -> V_15 , & V_100 ) ;
if ( V_15 != NULL && V_15 -> V_111 . V_112 . V_113 != NULL )
V_15 -> V_111 . V_112 . V_113 ( V_15 , & V_102 ) ;
}
break;
case V_43 :
V_17 -> V_15 = F_35 ( V_114 ,
& V_115 ,
& V_6 -> V_90 [ 1 ] ) ;
if ( V_17 -> V_15 == NULL )
V_17 -> V_15 = F_35 ( V_97 ,
& V_116 ,
& V_6 -> V_90 [ 1 ] ) ;
if ( V_17 -> V_15 != NULL ) {
struct V_14 * V_15 ;
struct V_99 V_100 = {
. V_90 = & V_6 -> V_90 [ 1 ] ,
. V_101 = 0xc2 >> 1 ,
. V_102 = NULL ,
} ;
static struct V_103 V_102 = {
. V_104 = V_105 ,
. V_106 = 64 ,
. V_107 = V_108 ,
. type = V_109 ,
} ;
V_15 = F_35 ( V_110 , V_17 -> V_15 , & V_100 ) ;
if ( V_15 != NULL && V_15 -> V_111 . V_112 . V_113 != NULL )
V_15 -> V_111 . V_112 . V_113 ( V_15 , & V_102 ) ;
}
break;
case V_44 :
V_17 -> V_15 = F_35 ( V_97 ,
& V_117 ,
& V_6 -> V_90 [ 1 ] ) ;
if ( V_17 -> V_15 != NULL ) {
struct V_14 * V_15 ;
struct V_99 V_100 = {
. V_90 = & V_6 -> V_90 [ 1 ] ,
. V_101 = 0xc2 >> 1 ,
. V_102 = NULL ,
} ;
static struct V_103 V_102 = {
. V_104 = V_105 ,
. V_106 = 64 ,
. V_107 = V_108 ,
. type = V_109 ,
} ;
V_15 = F_35 ( V_110 , V_17 -> V_15 , & V_100 ) ;
if ( V_15 != NULL && V_15 -> V_111 . V_112 . V_113 != NULL )
V_15 -> V_111 . V_112 . V_113 ( V_15 , & V_102 ) ;
}
break;
default:
break;
}
if ( V_17 -> V_15 == NULL ) {
F_3 ( L_17 ) ;
return - 1 ;
}
V_17 -> V_15 -> V_118 = V_119 ;
V_8 = F_36 ( & V_17 -> V_18 , V_17 -> V_15 ) ;
if ( V_8 < 0 ) {
if ( V_17 -> V_15 -> V_111 . V_120 )
V_17 -> V_15 -> V_111 . V_120 ( V_17 -> V_15 ) ;
return V_8 ;
}
F_37 ( V_6 ,
( V_121 << 16 ) | V_121 ,
V_122 ,
V_121 ,
( V_121 << 16 ) | V_121 ) ;
return V_8 ;
}
