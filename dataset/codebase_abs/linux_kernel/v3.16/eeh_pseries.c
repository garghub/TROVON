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
F_5 ( V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_7 ( V_18 ) ;
T_1 V_21 ;
if ( ! V_20 )
return 0 ;
F_8 ( V_20 , V_22 , 2 , & V_21 ) ;
if ( ! ( V_21 & V_23 ) )
return 0 ;
return V_24 ;
}
static int F_9 ( struct V_17 * V_18 , int V_25 )
{
struct V_19 * V_20 = F_7 ( V_18 ) ;
int V_26 = F_6 ( V_18 ) ;
int V_27 = 48 ;
T_1 V_28 ;
if ( ! V_26 )
return 0 ;
while ( V_27 -- ) {
F_8 ( V_20 , V_26 , 1 , & V_26 ) ;
if ( V_26 < 0x40 )
break;
V_26 &= ~ 3 ;
F_8 ( V_20 , V_26 + V_29 , 1 , & V_28 ) ;
if ( V_28 == 0xff )
break;
if ( V_28 == V_25 )
return V_26 ;
V_26 += V_30 ;
}
return 0 ;
}
static int F_10 ( struct V_17 * V_18 , int V_25 )
{
struct V_19 * V_20 = F_7 ( V_18 ) ;
struct V_31 * V_32 = F_11 ( V_18 ) ;
T_1 V_33 ;
int V_26 = 256 ;
int V_34 = ( 4096 - 256 ) / 8 ;
if ( ! V_32 || ! V_32 -> V_35 )
return 0 ;
if ( F_8 ( V_20 , V_26 , 4 , & V_33 ) != V_36 )
return 0 ;
else if ( ! V_33 )
return 0 ;
while ( V_34 -- > 0 ) {
if ( F_12 ( V_33 ) == V_25 && V_26 )
return V_26 ;
V_26 = F_13 ( V_33 ) ;
if ( V_26 < 256 )
break;
if ( F_8 ( V_20 , V_26 , 4 , & V_33 ) != V_36 )
break;
}
return 0 ;
}
static void * F_14 ( struct V_17 * V_18 , void * V_37 )
{
struct V_31 * V_32 ;
struct V_38 V_39 ;
struct V_19 * V_20 = F_7 ( V_18 ) ;
const T_2 * V_40 , * V_41 , * V_42 ;
T_1 V_43 ;
const T_2 * V_44 ;
T_1 V_45 ;
int V_46 = 0 ;
int V_47 ;
V_32 = F_11 ( V_18 ) ;
if ( V_32 -> V_39 || ! F_15 ( V_18 ) )
return NULL ;
V_40 = F_16 ( V_18 , L_20 , NULL ) ;
V_41 = F_16 ( V_18 , L_21 , NULL ) ;
V_42 = F_16 ( V_18 , L_22 , NULL ) ;
if ( ! V_40 || ! V_41 || ! V_42 )
return NULL ;
if ( V_18 -> type && ! strcmp ( V_18 -> type , L_23 ) )
return NULL ;
V_43 = F_17 ( V_40 , 1 ) ;
V_32 -> V_43 = V_43 ;
V_32 -> V_48 = F_9 ( V_18 , V_49 ) ;
V_32 -> V_35 = F_9 ( V_18 , V_50 ) ;
V_32 -> V_51 = F_10 ( V_18 , V_52 ) ;
V_32 -> V_53 &= 0xFFFFFF00 ;
if ( ( V_32 -> V_43 >> 8 ) == V_54 ) {
V_32 -> V_53 |= V_55 ;
if ( V_32 -> V_35 ) {
F_8 ( V_20 , V_32 -> V_35 + V_56 ,
2 , & V_45 ) ;
V_45 = ( V_45 & V_57 ) >> 4 ;
if ( V_45 == V_58 )
V_32 -> V_53 |= V_59 ;
else if ( V_45 == V_60 )
V_32 -> V_53 |= V_61 ;
}
}
V_44 = F_16 ( V_18 , L_24 , NULL ) ;
if ( ! V_44 ) {
F_3 ( L_25 ,
V_11 , V_18 -> V_62 ) ;
return NULL ;
}
memset ( & V_39 , 0 , sizeof( struct V_38 ) ) ;
V_39 . V_63 = V_32 -> V_63 ;
V_39 . V_64 = F_17 ( V_44 , 1 ) ;
V_47 = V_65 -> V_66 ( & V_39 , V_67 ) ;
if ( ! V_47 ) {
V_32 -> V_64 = F_17 ( V_44 , 1 ) ;
V_32 -> V_68 = V_65 -> V_69 ( & V_39 ) ;
V_39 . V_70 = V_32 -> V_68 ;
V_47 = V_65 -> V_71 ( & V_39 , NULL ) ;
if ( V_47 > 0 && V_47 != V_72 )
V_46 = 1 ;
if ( V_46 ) {
F_18 ( true ) ;
F_19 ( V_32 ) ;
F_20 ( L_26 ,
V_11 , V_18 -> V_62 , V_39 . V_63 -> V_73 ,
V_39 . V_70 , V_39 . V_64 ) ;
} else if ( V_18 -> V_74 && F_11 ( V_18 -> V_74 ) &&
( F_11 ( V_18 -> V_74 ) ) -> V_39 ) {
V_32 -> V_64 = F_11 ( V_18 -> V_74 ) -> V_64 ;
V_32 -> V_68 = F_11 ( V_18 -> V_74 ) -> V_68 ;
F_19 ( V_32 ) ;
}
}
F_21 ( V_32 ) ;
return NULL ;
}
static int F_22 ( struct V_38 * V_39 , int V_75 )
{
int V_47 = 0 ;
int V_64 ;
switch ( V_75 ) {
case V_76 :
case V_67 :
case V_77 :
case V_78 :
V_64 = V_39 -> V_64 ;
if ( V_39 -> V_70 )
V_64 = V_39 -> V_70 ;
break;
default:
F_23 ( L_27 ,
V_11 , V_75 ) ;
return - V_12 ;
}
V_47 = F_24 ( V_1 , 4 , 1 , NULL ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) , V_75 ) ;
return V_47 ;
}
static int F_27 ( struct V_38 * V_39 )
{
int V_47 = 0 ;
int V_80 [ 3 ] ;
if ( V_6 != V_10 ) {
V_47 = F_24 ( V_6 , 4 , 2 , V_80 ,
V_39 -> V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) , 1 ) ;
if ( V_47 || ( V_80 [ 0 ] == 0 ) )
return 0 ;
V_47 = F_24 ( V_6 , 4 , 2 , V_80 ,
V_39 -> V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) , 0 ) ;
if ( V_47 ) {
F_3 ( L_28 ,
V_11 , V_39 -> V_63 -> V_73 , V_39 -> V_64 ) ;
return 0 ;
}
return V_80 [ 0 ] ;
}
if ( V_7 != V_10 ) {
V_47 = F_24 ( V_7 , 4 , 2 , V_80 ,
V_39 -> V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) , 0 ) ;
if ( V_47 ) {
F_3 ( L_28 ,
V_11 , V_39 -> V_63 -> V_73 , V_39 -> V_64 ) ;
return 0 ;
}
return V_80 [ 0 ] ;
}
return V_47 ;
}
static int F_28 ( struct V_38 * V_39 , int * V_81 )
{
int V_64 ;
int V_47 ;
int V_80 [ 4 ] ;
int V_82 ;
V_64 = V_39 -> V_64 ;
if ( V_39 -> V_70 )
V_64 = V_39 -> V_70 ;
if ( V_3 != V_10 ) {
V_47 = F_24 ( V_3 , 3 , 4 , V_80 ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) ) ;
} else if ( V_4 != V_10 ) {
V_80 [ 2 ] = 0 ;
V_47 = F_24 ( V_4 , 3 , 3 , V_80 ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) ) ;
} else {
return V_72 ;
}
if ( V_47 )
return V_47 ;
V_82 = 0 ;
if ( V_80 [ 1 ] ) {
switch( V_80 [ 0 ] ) {
case 0 :
V_82 &= ~ V_83 ;
V_82 |= V_84 ;
V_82 |= V_85 ;
break;
case 1 :
V_82 |= V_83 ;
V_82 |= V_84 ;
V_82 |= V_85 ;
break;
case 2 :
V_82 &= ~ V_83 ;
V_82 &= ~ V_84 ;
V_82 &= ~ V_85 ;
break;
case 4 :
V_82 &= ~ V_83 ;
V_82 &= ~ V_84 ;
V_82 &= ~ V_85 ;
V_82 |= V_86 ;
break;
case 5 :
if ( V_80 [ 2 ] ) {
if ( V_81 ) * V_81 = V_80 [ 2 ] ;
V_82 = V_87 ;
} else {
V_82 = V_72 ;
}
break;
default:
V_82 = V_72 ;
}
} else {
V_82 = V_72 ;
}
return V_82 ;
}
static int F_29 ( struct V_38 * V_39 , int V_75 )
{
int V_64 ;
int V_47 ;
V_64 = V_39 -> V_64 ;
if ( V_39 -> V_70 )
V_64 = V_39 -> V_70 ;
V_47 = F_24 ( V_2 , 4 , 1 , NULL ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) , V_75 ) ;
if ( V_75 == V_88 &&
V_47 == - 8 ) {
V_75 = V_89 ;
V_47 = F_24 ( V_2 , 4 , 1 , NULL ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) , V_75 ) ;
}
if ( V_75 == V_88 ||
V_75 == V_89 )
F_30 ( V_90 ) ;
else
F_30 ( V_91 ) ;
return V_47 ;
}
static int F_31 ( struct V_38 * V_39 , int V_92 )
{
int V_47 ;
int V_93 ;
#define F_32 (1000)
#define F_33 (300 * 1000)
while ( 1 ) {
V_47 = F_28 ( V_39 , & V_93 ) ;
if ( V_47 != V_87 )
return V_47 ;
if ( V_92 <= 0 ) {
F_3 ( L_29 ,
V_11 , V_92 ) ;
return V_72 ;
}
if ( V_93 <= 0 ) {
F_3 ( L_30 ,
V_11 , V_93 ) ;
V_93 = F_32 ;
} else if ( V_93 > F_33 ) {
F_3 ( L_31 ,
V_11 , V_93 ) ;
V_93 = F_33 ;
}
V_92 -= V_93 ;
F_30 ( V_93 ) ;
}
return V_72 ;
}
static int F_34 ( struct V_38 * V_39 , int V_94 , char * V_95 , unsigned long V_96 )
{
int V_64 ;
unsigned long V_97 ;
int V_47 ;
F_35 ( & V_13 , V_97 ) ;
memset ( V_98 , 0 , V_14 ) ;
V_64 = V_39 -> V_64 ;
if ( V_39 -> V_70 )
V_64 = V_39 -> V_70 ;
V_47 = F_24 ( V_5 , 8 , 1 , NULL , V_64 ,
F_25 ( V_39 -> V_63 -> V_79 ) , F_26 ( V_39 -> V_63 -> V_79 ) ,
F_36 ( V_95 ) , V_96 ,
F_36 ( V_98 ) , V_14 ,
V_94 ) ;
if ( ! V_47 )
F_37 ( V_98 , V_99 , 0 ) ;
F_38 ( & V_13 , V_97 ) ;
return V_47 ;
}
static int F_39 ( struct V_38 * V_39 )
{
int V_64 ;
int V_47 ;
V_64 = V_39 -> V_64 ;
if ( V_39 -> V_70 )
V_64 = V_39 -> V_70 ;
if ( V_8 != V_10 ) {
V_47 = F_24 ( V_8 , 3 , 1 , NULL ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) ) ;
} else if ( V_9 != V_10 ) {
V_47 = F_24 ( V_9 , 3 , 1 , NULL ,
V_64 , F_25 ( V_39 -> V_63 -> V_79 ) ,
F_26 ( V_39 -> V_63 -> V_79 ) ) ;
} else {
return - V_100 ;
}
if ( V_47 )
F_3 ( L_32 ,
V_11 , V_39 -> V_63 -> V_73 , V_39 -> V_70 , V_47 ) ;
return V_47 ;
}
static int F_40 ( struct V_17 * V_18 , int V_101 , int V_102 , T_1 * V_103 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( V_18 ) ;
return F_8 ( V_20 , V_101 , V_102 , V_103 ) ;
}
static int F_41 ( struct V_17 * V_18 , int V_101 , int V_102 , T_1 V_103 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( V_18 ) ;
return F_42 ( V_20 , V_101 , V_102 , V_103 ) ;
}
static int T_3 F_43 ( void )
{
int V_47 = - V_12 ;
if ( ! F_44 ( V_104 ) )
return V_47 ;
V_47 = F_45 ( & V_105 ) ;
if ( ! V_47 )
F_46 ( L_33 ) ;
else
F_46 ( L_34 ,
V_47 ) ;
return V_47 ;
}
