static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
const char * V_7 = V_8 ;
int V_9 ;
V_9 = F_2 ( V_4 , V_7 , & V_6 -> V_10 -> V_11 ) ;
if ( V_9 )
F_3 ( L_1 , V_7 ) ;
else {
T_1 V_12 = ( * V_4 ) -> V_13 ;
if ( V_12 < 2 || V_12 > 64 || ( V_12 % 2 ) != 0 ) {
F_3 ( L_2 ,
V_7 , ( unsigned long ) V_12 ) ;
V_9 = - V_14 ;
F_4 ( * V_4 ) ;
* V_4 = NULL ;
}
}
if ( V_9 ) {
F_3 ( L_3
L_4 ) ;
F_3 ( L_5
L_6 ) ;
}
return V_9 ;
}
static int F_5 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_16 -> V_18 ,
struct V_17 , V_19 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
const struct V_3 * V_4 = NULL ;
int V_9 ;
int V_20 ;
T_2 V_21 [ 3 ] ;
V_9 = F_1 ( V_2 , & V_4 ) ;
if ( V_9 )
return V_9 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_13 ; V_20 += 2 ) {
V_21 [ 0 ] = V_4 -> V_22 [ V_20 ] ;
switch ( V_21 [ 0 ] ) {
case V_23 :
break;
case V_24 :
V_21 [ 1 ] = 0x72 ;
V_21 [ 2 ] = 0x49 ;
F_7 ( V_16 , V_21 , 3 ) ;
break;
case V_25 :
break;
case V_26 :
V_21 [ 1 ] = 0x31 ;
V_21 [ 2 ] = 0xc0 ;
F_7 ( V_16 , V_21 , 3 ) ;
break;
default:
V_21 [ 1 ] = V_4 -> V_22 [ V_20 + 1 ] ;
F_7 ( V_16 , V_21 , 2 ) ;
break;
}
}
V_21 [ 0 ] = ( T_2 ) V_27 ;
V_21 [ 1 ] = 0x01 ;
F_7 ( V_16 , V_21 , 2 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_32 ;
struct V_5 * V_6 ;
int V_9 ;
T_3 V_33 ;
if ( ! V_2 )
return - V_34 ;
V_6 = V_2 -> V_6 ;
F_9 ( L_7 ,
V_29 -> V_35 , V_29 -> V_36 ) ;
F_10 ( & V_6 -> V_37 ) ;
V_9 = F_11 ( V_6 ) ;
F_12 ( & V_6 -> V_37 ) ;
if ( V_9 ) {
F_3 ( L_8 ) ;
return V_9 ;
}
V_9 = - V_34 ;
switch ( V_6 -> V_38 -> type ) {
case V_39 :
case V_40 :
case V_41 :
V_33 = F_13 ( V_6 , V_42 ) ;
V_33 |= 0x00400000 ;
V_33 |= 0x00002000 ;
V_33 |= 0x00010000 ;
V_33 |= 0x00020000 ;
V_33 |= 0x000c0000 ;
F_14 ( V_6 , V_33 , V_42 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
default:
break;
}
if ( ! V_31 -> V_46 . V_47 )
return - V_34 ;
F_10 ( & V_2 -> V_18 -> V_48 ) ;
if ( V_2 -> V_18 -> V_49 ++ == 0 ) {
F_9 ( L_9 ) ;
F_10 ( & V_6 -> V_37 ) ;
F_15 ( V_50 , & V_2 -> V_51 ) ;
V_9 = F_16 ( V_2 ) ;
if ( V_9 < 0 ) {
F_9 ( L_10 ) ;
V_2 -> V_18 -> V_49 -- ;
if ( V_2 -> V_18 -> V_49 == 0 )
F_17 ( V_50 , & V_2 -> V_51 ) ;
}
F_12 ( & V_6 -> V_37 ) ;
} else
V_9 = 0 ;
F_12 ( & V_2 -> V_18 -> V_48 ) ;
return V_9 ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_32 ;
struct V_5 * V_6 ;
int V_9 = - V_34 ;
if ( V_2 ) {
V_6 = V_2 -> V_6 ;
F_9 ( L_11 ,
V_29 -> V_35 , V_29 -> V_36 ) ;
F_10 ( & V_2 -> V_18 -> V_48 ) ;
if ( -- V_2 -> V_18 -> V_49 == 0 ) {
F_9 ( L_12 ) ;
F_10 ( & V_6 -> V_37 ) ;
V_9 = F_19 ( V_2 , 0 ) ;
F_12 ( & V_6 -> V_37 ) ;
} else
V_9 = 0 ;
F_12 ( & V_2 -> V_18 -> V_48 ) ;
}
return V_9 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_19 ;
struct V_30 * V_52 ;
struct V_53 * V_46 ;
int V_9 ;
if ( ! V_18 )
return - V_34 ;
V_18 -> V_54 = 0 ;
V_18 -> V_2 = V_2 ;
V_9 = F_21 ( & V_18 -> V_19 ,
V_55 ,
V_56 , & V_6 -> V_10 -> V_11 , V_57 ) ;
if ( V_9 < 0 )
goto V_58;
V_19 = & V_18 -> V_19 ;
V_52 = & V_18 -> V_31 ;
V_52 -> V_32 = ( void * ) V_2 ;
V_52 -> V_59 = 256 ;
V_52 -> V_60 = 256 ;
V_52 -> V_61 = F_8 ;
V_52 -> V_62 = F_18 ;
V_52 -> V_46 . V_63 = ( V_64 |
V_65 | V_66 ) ;
V_9 = F_22 ( V_52 ) ;
if ( V_9 < 0 )
goto V_67;
V_46 = & V_52 -> V_46 ;
V_18 -> V_68 . V_69 = V_70 ;
V_18 -> V_71 . V_69 = V_72 ;
V_18 -> V_73 . V_59 = 256 ;
V_18 -> V_73 . V_31 = V_46 ;
V_9 = F_23 ( & V_18 -> V_73 , V_19 ) ;
if ( V_9 < 0 )
goto V_74;
V_9 = V_46 -> V_75 ( V_46 , & V_18 -> V_68 ) ;
if ( V_9 < 0 )
goto V_76;
V_9 = V_46 -> V_75 ( V_46 , & V_18 -> V_71 ) ;
if ( V_9 < 0 )
goto V_77;
V_9 = V_46 -> V_78 ( V_46 , & V_18 -> V_68 ) ;
if ( V_9 < 0 )
goto V_79;
V_9 = F_24 ( V_2 ) ;
if ( V_9 < 0 )
goto V_80;
F_25 ( V_19 , & V_18 -> V_81 , V_46 ) ;
F_26 ( L_13 ) ;
F_26 ( L_14 ,
V_2 -> V_18 -> V_19 . V_82 , V_2 -> V_83 ,
V_2 -> V_84 , V_2 -> V_85 / 1024 ,
( V_2 -> V_85 * 100 / 1024 ) % 100 ) ;
F_27 ( & V_18 -> V_48 ) ;
V_18 -> V_54 = 1 ;
return V_9 ;
V_80:
V_46 -> V_86 ( V_46 ) ;
V_79:
V_46 -> V_87 ( V_46 , & V_18 -> V_71 ) ;
V_77:
V_46 -> V_87 ( V_46 , & V_18 -> V_68 ) ;
V_76:
F_28 ( & V_18 -> V_73 ) ;
V_74:
F_29 ( V_52 ) ;
V_67:
F_30 ( V_19 ) ;
V_58:
return V_9 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_19 * V_19 ;
struct V_30 * V_52 ;
struct V_53 * V_46 ;
F_26 ( L_15 ) ;
if ( V_18 == NULL || ! V_18 -> V_54 )
return;
V_19 = & V_18 -> V_19 ;
V_52 = & V_18 -> V_31 ;
V_46 = & V_52 -> V_46 ;
V_46 -> V_88 ( V_46 ) ;
F_32 ( & V_18 -> V_81 ) ;
V_46 -> V_87 ( V_46 , & V_18 -> V_71 ) ;
V_46 -> V_87 ( V_46 , & V_18 -> V_68 ) ;
F_28 ( & V_18 -> V_73 ) ;
F_29 ( V_52 ) ;
F_33 ( V_18 -> V_16 ) ;
F_34 ( V_18 -> V_16 ) ;
F_30 ( V_19 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_9 = 0 ;
switch ( V_6 -> V_38 -> type ) {
case V_39 :
case V_40 :
V_18 -> V_16 = F_35 ( V_89 ,
& V_90 ,
& V_6 -> V_91 [ 0 ] ) ;
if ( V_18 -> V_16 != NULL ) {
F_35 ( V_92 , V_18 -> V_16 ,
& V_6 -> V_91 [ 0 ] ,
& V_93 ) ;
V_9 = 0 ;
}
break;
case V_41 :
V_18 -> V_16 = F_35 ( V_94 ,
& V_95 ,
& V_6 -> V_91 [ 0 ] ) ;
if ( V_18 -> V_16 != NULL )
F_35 ( V_96 , V_18 -> V_16 ,
0x60 , & V_6 -> V_91 [ 0 ] ,
& V_97 ) ;
break;
case V_43 :
V_18 -> V_16 = F_35 ( V_98 ,
& V_99 ,
& V_6 -> V_91 [ 1 ] ) ;
if ( V_18 -> V_16 != NULL ) {
struct V_15 * V_16 ;
struct V_100 V_101 = {
. V_91 = & V_6 -> V_91 [ 1 ] ,
. V_102 = 0xc2 >> 1 ,
. V_103 = NULL ,
} ;
static struct V_104 V_103 = {
. V_105 = V_106 ,
. V_107 = 64 ,
. V_108 = V_109 ,
. type = V_110 ,
} ;
V_16 = F_35 ( V_111 , V_18 -> V_16 , & V_101 ) ;
if ( V_16 != NULL && V_16 -> V_112 . V_113 . V_114 != NULL )
V_16 -> V_112 . V_113 . V_114 ( V_16 , & V_103 ) ;
}
break;
case V_44 :
V_18 -> V_16 = F_35 ( V_115 ,
& V_116 ,
& V_6 -> V_91 [ 1 ] ) ;
if ( V_18 -> V_16 == NULL )
V_18 -> V_16 = F_35 ( V_98 ,
& V_117 ,
& V_6 -> V_91 [ 1 ] ) ;
if ( V_18 -> V_16 != NULL ) {
struct V_15 * V_16 ;
struct V_100 V_101 = {
. V_91 = & V_6 -> V_91 [ 1 ] ,
. V_102 = 0xc2 >> 1 ,
. V_103 = NULL ,
} ;
static struct V_104 V_103 = {
. V_105 = V_106 ,
. V_107 = 64 ,
. V_108 = V_109 ,
. type = V_110 ,
} ;
V_16 = F_35 ( V_111 , V_18 -> V_16 , & V_101 ) ;
if ( V_16 != NULL && V_16 -> V_112 . V_113 . V_114 != NULL )
V_16 -> V_112 . V_113 . V_114 ( V_16 , & V_103 ) ;
}
break;
case V_45 :
V_18 -> V_16 = F_35 ( V_98 ,
& V_118 ,
& V_6 -> V_91 [ 1 ] ) ;
if ( V_18 -> V_16 != NULL ) {
struct V_15 * V_16 ;
struct V_100 V_101 = {
. V_91 = & V_6 -> V_91 [ 1 ] ,
. V_102 = 0xc2 >> 1 ,
. V_103 = NULL ,
} ;
static struct V_104 V_103 = {
. V_105 = V_106 ,
. V_107 = 64 ,
. V_108 = V_109 ,
. type = V_110 ,
} ;
V_16 = F_35 ( V_111 , V_18 -> V_16 , & V_101 ) ;
if ( V_16 != NULL && V_16 -> V_112 . V_113 . V_114 != NULL )
V_16 -> V_112 . V_113 . V_114 ( V_16 , & V_103 ) ;
}
break;
default:
break;
}
if ( V_18 -> V_16 == NULL ) {
F_3 ( L_16 ) ;
return - 1 ;
}
V_18 -> V_16 -> V_119 = V_120 ;
V_9 = F_36 ( & V_18 -> V_19 , V_18 -> V_16 ) ;
if ( V_9 < 0 ) {
if ( V_18 -> V_16 -> V_112 . V_121 )
V_18 -> V_16 -> V_112 . V_121 ( V_18 -> V_16 ) ;
return V_9 ;
}
F_37 ( V_6 ,
( V_122 << 16 ) | V_122 ,
V_123 ,
V_122 ,
( V_122 << 16 ) | V_122 ) ;
return V_9 ;
}
