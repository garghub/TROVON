static int F_1 ( void )
{
V_1 = F_2 ( L_1 ) ;
V_2 = F_2 ( L_2 ) ;
V_3 = F_2 ( L_3 ) ;
V_4 = F_2 ( L_4 ) ;
V_5 = F_2 ( L_5 ) ;
V_6 = F_2 ( L_6 ) ;
V_7 = F_2 ( L_7 ) ;
V_8 = F_2 ( L_8 ) ;
V_9 = F_2 ( L_9 ) ;
if ( V_1 == V_10 ) {
F_3 ( L_10 ,
V_11 ) ;
return - V_12 ;
} else if ( V_2 == V_10 ) {
F_3 ( L_11 ,
V_11 ) ;
return - V_12 ;
} else if ( V_3 == V_10 &&
V_4 == V_10 ) {
F_3 ( L_12
L_13 ,
V_11 ) ;
return - V_12 ;
} else if ( V_5 == V_10 ) {
F_3 ( L_14 ,
V_11 ) ;
return - V_12 ;
} else if ( V_8 == V_10 &&
V_9 == V_10 ) {
F_3 ( L_15
L_16 ,
V_11 ) ;
return - V_12 ;
}
F_4 ( & V_13 ) ;
V_14 = F_2 ( L_17 ) ;
if ( V_14 == V_10 ) {
F_3 ( L_18 ,
V_11 ) ;
V_14 = 1024 ;
} else if ( V_14 > V_15 ) {
F_3 ( L_19 ,
V_11 , V_14 , V_15 ) ;
V_14 = V_15 ;
}
F_5 ( V_16 | V_17 ) ;
return 0 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_7 ( V_19 ) ;
T_1 V_22 ;
if ( ! V_21 )
return 0 ;
F_8 ( V_21 , V_23 , 2 , & V_22 ) ;
if ( ! ( V_22 & V_24 ) )
return 0 ;
return V_25 ;
}
static int F_9 ( struct V_18 * V_19 , int V_26 )
{
struct V_20 * V_21 = F_7 ( V_19 ) ;
int V_27 = F_6 ( V_19 ) ;
int V_28 = 48 ;
T_1 V_29 ;
if ( ! V_27 )
return 0 ;
while ( V_28 -- ) {
F_8 ( V_21 , V_27 , 1 , & V_27 ) ;
if ( V_27 < 0x40 )
break;
V_27 &= ~ 3 ;
F_8 ( V_21 , V_27 + V_30 , 1 , & V_29 ) ;
if ( V_29 == 0xff )
break;
if ( V_29 == V_26 )
return V_27 ;
V_27 += V_31 ;
}
return 0 ;
}
static int F_10 ( struct V_18 * V_19 , int V_26 )
{
struct V_20 * V_21 = F_7 ( V_19 ) ;
struct V_32 * V_33 = F_11 ( V_19 ) ;
T_1 V_34 ;
int V_27 = 256 ;
int V_35 = ( 4096 - 256 ) / 8 ;
if ( ! V_33 || ! V_33 -> V_36 )
return 0 ;
if ( F_8 ( V_21 , V_27 , 4 , & V_34 ) != V_37 )
return 0 ;
else if ( ! V_34 )
return 0 ;
while ( V_35 -- > 0 ) {
if ( F_12 ( V_34 ) == V_26 && V_27 )
return V_27 ;
V_27 = F_13 ( V_34 ) ;
if ( V_27 < 256 )
break;
if ( F_8 ( V_21 , V_27 , 4 , & V_34 ) != V_37 )
break;
}
return 0 ;
}
static void * F_14 ( struct V_18 * V_19 , void * V_38 )
{
struct V_32 * V_33 ;
struct V_39 V_40 ;
struct V_20 * V_21 = F_7 ( V_19 ) ;
const T_2 * V_41 , * V_42 , * V_43 ;
T_1 V_44 ;
const T_2 * V_45 ;
T_1 V_46 ;
int V_47 = 0 ;
int V_48 ;
V_33 = F_11 ( V_19 ) ;
if ( V_33 -> V_40 || ! F_15 ( V_19 ) )
return NULL ;
V_41 = F_16 ( V_19 , L_20 , NULL ) ;
V_42 = F_16 ( V_19 , L_21 , NULL ) ;
V_43 = F_16 ( V_19 , L_22 , NULL ) ;
if ( ! V_41 || ! V_42 || ! V_43 )
return NULL ;
if ( V_19 -> type && ! strcmp ( V_19 -> type , L_23 ) )
return NULL ;
V_44 = F_17 ( V_41 , 1 ) ;
V_33 -> V_44 = V_44 ;
V_33 -> V_49 = F_9 ( V_19 , V_50 ) ;
V_33 -> V_36 = F_9 ( V_19 , V_51 ) ;
V_33 -> V_52 = F_10 ( V_19 , V_53 ) ;
V_33 -> V_54 &= 0xFFFFFF00 ;
if ( ( V_33 -> V_44 >> 8 ) == V_55 ) {
V_33 -> V_54 |= V_56 ;
if ( V_33 -> V_36 ) {
F_8 ( V_21 , V_33 -> V_36 + V_57 ,
2 , & V_46 ) ;
V_46 = ( V_46 & V_58 ) >> 4 ;
if ( V_46 == V_59 )
V_33 -> V_54 |= V_60 ;
else if ( V_46 == V_61 )
V_33 -> V_54 |= V_62 ;
}
}
V_45 = F_16 ( V_19 , L_24 , NULL ) ;
if ( ! V_45 ) {
F_3 ( L_25 ,
V_11 , V_19 -> V_63 ) ;
return NULL ;
}
memset ( & V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 . V_64 = V_33 -> V_64 ;
V_40 . V_65 = F_17 ( V_45 , 1 ) ;
V_48 = V_66 -> V_67 ( & V_40 , V_68 ) ;
if ( ! V_48 ) {
V_33 -> V_65 = F_17 ( V_45 , 1 ) ;
V_33 -> V_69 = V_66 -> V_70 ( & V_40 ) ;
V_40 . V_71 = V_33 -> V_69 ;
V_48 = V_66 -> V_72 ( & V_40 , NULL ) ;
if ( V_48 > 0 && V_48 != V_73 )
V_47 = 1 ;
if ( V_47 ) {
F_5 ( V_74 ) ;
F_18 ( V_33 ) ;
F_19 ( L_26 ,
V_11 , V_19 -> V_63 , V_40 . V_64 -> V_75 ,
V_40 . V_71 , V_40 . V_65 ) ;
} else if ( V_19 -> V_76 && F_11 ( V_19 -> V_76 ) &&
( F_11 ( V_19 -> V_76 ) ) -> V_40 ) {
V_33 -> V_65 = F_11 ( V_19 -> V_76 ) -> V_65 ;
V_33 -> V_69 = F_11 ( V_19 -> V_76 ) -> V_69 ;
F_18 ( V_33 ) ;
}
}
F_20 ( V_33 ) ;
return NULL ;
}
static int F_21 ( struct V_39 * V_40 , int V_77 )
{
int V_48 = 0 ;
int V_65 ;
switch ( V_77 ) {
case V_78 :
case V_68 :
case V_79 :
case V_80 :
V_65 = V_40 -> V_65 ;
if ( V_40 -> V_71 )
V_65 = V_40 -> V_71 ;
break;
default:
F_22 ( L_27 ,
V_11 , V_77 ) ;
return - V_12 ;
}
V_48 = F_23 ( V_1 , 4 , 1 , NULL ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) , V_77 ) ;
return V_48 ;
}
static int F_26 ( struct V_39 * V_40 )
{
int V_48 = 0 ;
int V_82 [ 3 ] ;
if ( V_6 != V_10 ) {
V_48 = F_23 ( V_6 , 4 , 2 , V_82 ,
V_40 -> V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) , 1 ) ;
if ( V_48 || ( V_82 [ 0 ] == 0 ) )
return 0 ;
V_48 = F_23 ( V_6 , 4 , 2 , V_82 ,
V_40 -> V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) , 0 ) ;
if ( V_48 ) {
F_3 ( L_28 ,
V_11 , V_40 -> V_64 -> V_75 , V_40 -> V_65 ) ;
return 0 ;
}
return V_82 [ 0 ] ;
}
if ( V_7 != V_10 ) {
V_48 = F_23 ( V_7 , 4 , 2 , V_82 ,
V_40 -> V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) , 0 ) ;
if ( V_48 ) {
F_3 ( L_28 ,
V_11 , V_40 -> V_64 -> V_75 , V_40 -> V_65 ) ;
return 0 ;
}
return V_82 [ 0 ] ;
}
return V_48 ;
}
static int F_27 ( struct V_39 * V_40 , int * V_83 )
{
int V_65 ;
int V_48 ;
int V_82 [ 4 ] ;
int V_84 ;
V_65 = V_40 -> V_65 ;
if ( V_40 -> V_71 )
V_65 = V_40 -> V_71 ;
if ( V_3 != V_10 ) {
V_48 = F_23 ( V_3 , 3 , 4 , V_82 ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) ) ;
} else if ( V_4 != V_10 ) {
V_82 [ 2 ] = 0 ;
V_48 = F_23 ( V_4 , 3 , 3 , V_82 ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) ) ;
} else {
return V_73 ;
}
if ( V_48 )
return V_48 ;
V_84 = 0 ;
if ( V_82 [ 1 ] ) {
switch( V_82 [ 0 ] ) {
case 0 :
V_84 &= ~ V_85 ;
V_84 |= V_86 ;
V_84 |= V_87 ;
break;
case 1 :
V_84 |= V_85 ;
V_84 |= V_86 ;
V_84 |= V_87 ;
break;
case 2 :
V_84 &= ~ V_85 ;
V_84 &= ~ V_86 ;
V_84 &= ~ V_87 ;
break;
case 4 :
V_84 &= ~ V_85 ;
V_84 &= ~ V_86 ;
V_84 &= ~ V_87 ;
V_84 |= V_88 ;
break;
case 5 :
if ( V_82 [ 2 ] ) {
if ( V_83 ) * V_83 = V_82 [ 2 ] ;
V_84 = V_89 ;
} else {
V_84 = V_73 ;
}
break;
default:
V_84 = V_73 ;
}
} else {
V_84 = V_73 ;
}
return V_84 ;
}
static int F_28 ( struct V_39 * V_40 , int V_77 )
{
int V_65 ;
int V_48 ;
V_65 = V_40 -> V_65 ;
if ( V_40 -> V_71 )
V_65 = V_40 -> V_71 ;
V_48 = F_23 ( V_2 , 4 , 1 , NULL ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) , V_77 ) ;
if ( V_77 == V_90 &&
V_48 == - 8 ) {
V_77 = V_91 ;
V_48 = F_23 ( V_2 , 4 , 1 , NULL ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) , V_77 ) ;
}
if ( V_77 == V_90 ||
V_77 == V_91 )
F_29 ( V_92 ) ;
else
F_29 ( V_93 ) ;
return V_48 ;
}
static int F_30 ( struct V_39 * V_40 , int V_94 )
{
int V_48 ;
int V_95 ;
#define F_31 (1000)
#define F_32 (300 * 1000)
while ( 1 ) {
V_48 = F_27 ( V_40 , & V_95 ) ;
if ( V_48 != V_89 )
return V_48 ;
if ( V_94 <= 0 ) {
F_3 ( L_29 ,
V_11 , V_94 ) ;
return V_73 ;
}
if ( V_95 <= 0 ) {
F_3 ( L_30 ,
V_11 , V_95 ) ;
V_95 = F_31 ;
} else if ( V_95 > F_32 ) {
F_3 ( L_31 ,
V_11 , V_95 ) ;
V_95 = F_32 ;
}
V_94 -= V_95 ;
F_29 ( V_95 ) ;
}
return V_73 ;
}
static int F_33 ( struct V_39 * V_40 , int V_96 , char * V_97 , unsigned long V_98 )
{
int V_65 ;
unsigned long V_99 ;
int V_48 ;
F_34 ( & V_13 , V_99 ) ;
memset ( V_100 , 0 , V_14 ) ;
V_65 = V_40 -> V_65 ;
if ( V_40 -> V_71 )
V_65 = V_40 -> V_71 ;
V_48 = F_23 ( V_5 , 8 , 1 , NULL , V_65 ,
F_24 ( V_40 -> V_64 -> V_81 ) , F_25 ( V_40 -> V_64 -> V_81 ) ,
F_35 ( V_97 ) , V_98 ,
F_35 ( V_100 ) , V_14 ,
V_96 ) ;
if ( ! V_48 )
F_36 ( V_100 , V_101 , 0 ) ;
F_37 ( & V_13 , V_99 ) ;
return V_48 ;
}
static int F_38 ( struct V_39 * V_40 )
{
int V_65 ;
int V_48 ;
V_65 = V_40 -> V_65 ;
if ( V_40 -> V_71 )
V_65 = V_40 -> V_71 ;
if ( V_8 != V_10 ) {
V_48 = F_23 ( V_8 , 3 , 1 , NULL ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) ) ;
} else if ( V_9 != V_10 ) {
V_48 = F_23 ( V_9 , 3 , 1 , NULL ,
V_65 , F_24 ( V_40 -> V_64 -> V_81 ) ,
F_25 ( V_40 -> V_64 -> V_81 ) ) ;
} else {
return - V_102 ;
}
if ( V_48 )
F_3 ( L_32 ,
V_11 , V_40 -> V_64 -> V_75 , V_40 -> V_71 , V_48 ) ;
return V_48 ;
}
static int F_39 ( struct V_18 * V_19 , int V_103 , int V_104 , T_1 * V_105 )
{
struct V_20 * V_21 ;
V_21 = F_7 ( V_19 ) ;
return F_8 ( V_21 , V_103 , V_104 , V_105 ) ;
}
static int F_40 ( struct V_18 * V_19 , int V_103 , int V_104 , T_1 V_105 )
{
struct V_20 * V_21 ;
V_21 = F_7 ( V_19 ) ;
return F_41 ( V_21 , V_103 , V_104 , V_105 ) ;
}
static int T_3 F_42 ( void )
{
int V_48 ;
V_48 = F_43 ( & V_106 ) ;
if ( ! V_48 )
F_44 ( L_33 ) ;
else
F_44 ( L_34 ,
V_48 ) ;
return V_48 ;
}
