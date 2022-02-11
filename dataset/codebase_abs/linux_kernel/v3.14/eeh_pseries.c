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
static void * F_10 ( struct V_17 * V_18 , void * V_31 )
{
struct V_32 * V_33 ;
struct V_34 V_35 ;
struct V_19 * V_20 = F_7 ( V_18 ) ;
const T_2 * V_36 , * V_37 , * V_38 ;
T_1 V_39 ;
const T_2 * V_40 ;
T_1 V_41 ;
int V_42 = 0 ;
int V_43 ;
V_33 = F_11 ( V_18 ) ;
if ( V_33 -> V_35 || ! F_12 ( V_18 ) )
return NULL ;
V_36 = F_13 ( V_18 , L_20 , NULL ) ;
V_37 = F_13 ( V_18 , L_21 , NULL ) ;
V_38 = F_13 ( V_18 , L_22 , NULL ) ;
if ( ! V_36 || ! V_37 || ! V_38 )
return NULL ;
if ( V_18 -> type && ! strcmp ( V_18 -> type , L_23 ) )
return NULL ;
V_39 = F_14 ( V_36 , 1 ) ;
V_33 -> V_39 = V_39 ;
V_33 -> V_44 = F_9 ( V_18 , V_45 ) ;
V_33 -> V_46 &= 0xFFFFFF00 ;
if ( ( V_33 -> V_39 >> 8 ) == V_47 ) {
V_33 -> V_46 |= V_48 ;
if ( V_33 -> V_44 ) {
F_8 ( V_20 , V_33 -> V_44 + V_49 ,
2 , & V_41 ) ;
V_41 = ( V_41 & V_50 ) >> 4 ;
if ( V_41 == V_51 )
V_33 -> V_46 |= V_52 ;
else if ( V_41 == V_53 )
V_33 -> V_46 |= V_54 ;
}
}
V_40 = F_13 ( V_18 , L_24 , NULL ) ;
if ( ! V_40 ) {
F_3 ( L_25 ,
V_11 , V_18 -> V_55 ) ;
return NULL ;
}
memset ( & V_35 , 0 , sizeof( struct V_34 ) ) ;
V_35 . V_56 = V_33 -> V_56 ;
V_35 . V_57 = F_14 ( V_40 , 1 ) ;
V_43 = V_58 -> V_59 ( & V_35 , V_60 ) ;
if ( ! V_43 ) {
V_33 -> V_57 = F_14 ( V_40 , 1 ) ;
V_33 -> V_61 = V_58 -> V_62 ( & V_35 ) ;
V_35 . V_63 = V_33 -> V_61 ;
V_43 = V_58 -> V_64 ( & V_35 , NULL ) ;
if ( V_43 > 0 && V_43 != V_65 )
V_42 = 1 ;
if ( V_42 ) {
F_15 ( true ) ;
F_16 ( V_33 ) ;
F_17 ( L_26 ,
V_11 , V_18 -> V_55 , V_35 . V_56 -> V_66 ,
V_35 . V_63 , V_35 . V_57 ) ;
} else if ( V_18 -> V_67 && F_11 ( V_18 -> V_67 ) &&
( F_11 ( V_18 -> V_67 ) ) -> V_35 ) {
V_33 -> V_57 = F_11 ( V_18 -> V_67 ) -> V_57 ;
V_33 -> V_61 = F_11 ( V_18 -> V_67 ) -> V_61 ;
F_16 ( V_33 ) ;
}
}
F_18 ( V_33 ) ;
return NULL ;
}
static int F_19 ( struct V_34 * V_35 , int V_68 )
{
int V_43 = 0 ;
int V_57 ;
switch ( V_68 ) {
case V_69 :
case V_60 :
case V_70 :
case V_71 :
V_57 = V_35 -> V_57 ;
if ( V_35 -> V_63 )
V_57 = V_35 -> V_63 ;
break;
default:
F_20 ( L_27 ,
V_11 , V_68 ) ;
return - V_12 ;
}
V_43 = F_21 ( V_1 , 4 , 1 , NULL ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) , V_68 ) ;
return V_43 ;
}
static int F_24 ( struct V_34 * V_35 )
{
int V_43 = 0 ;
int V_73 [ 3 ] ;
if ( V_6 != V_10 ) {
V_43 = F_21 ( V_6 , 4 , 2 , V_73 ,
V_35 -> V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) , 1 ) ;
if ( V_43 || ( V_73 [ 0 ] == 0 ) )
return 0 ;
V_43 = F_21 ( V_6 , 4 , 2 , V_73 ,
V_35 -> V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) , 0 ) ;
if ( V_43 ) {
F_3 ( L_28 ,
V_11 , V_35 -> V_56 -> V_66 , V_35 -> V_57 ) ;
return 0 ;
}
return V_73 [ 0 ] ;
}
if ( V_7 != V_10 ) {
V_43 = F_21 ( V_7 , 4 , 2 , V_73 ,
V_35 -> V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) , 0 ) ;
if ( V_43 ) {
F_3 ( L_28 ,
V_11 , V_35 -> V_56 -> V_66 , V_35 -> V_57 ) ;
return 0 ;
}
return V_73 [ 0 ] ;
}
return V_43 ;
}
static int F_25 ( struct V_34 * V_35 , int * V_74 )
{
int V_57 ;
int V_43 ;
int V_73 [ 4 ] ;
int V_75 ;
V_57 = V_35 -> V_57 ;
if ( V_35 -> V_63 )
V_57 = V_35 -> V_63 ;
if ( V_3 != V_10 ) {
V_43 = F_21 ( V_3 , 3 , 4 , V_73 ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) ) ;
} else if ( V_4 != V_10 ) {
V_73 [ 2 ] = 0 ;
V_43 = F_21 ( V_4 , 3 , 3 , V_73 ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) ) ;
} else {
return V_65 ;
}
if ( V_43 )
return V_43 ;
V_75 = 0 ;
if ( V_73 [ 1 ] ) {
switch( V_73 [ 0 ] ) {
case 0 :
V_75 &= ~ V_76 ;
V_75 |= V_77 ;
V_75 |= V_78 ;
break;
case 1 :
V_75 |= V_76 ;
V_75 |= V_77 ;
V_75 |= V_78 ;
break;
case 2 :
V_75 &= ~ V_76 ;
V_75 &= ~ V_77 ;
V_75 &= ~ V_78 ;
break;
case 4 :
V_75 &= ~ V_76 ;
V_75 &= ~ V_77 ;
V_75 &= ~ V_78 ;
V_75 |= V_79 ;
break;
case 5 :
if ( V_73 [ 2 ] ) {
if ( V_74 ) * V_74 = V_73 [ 2 ] ;
V_75 = V_80 ;
} else {
V_75 = V_65 ;
}
default:
V_75 = V_65 ;
}
} else {
V_75 = V_65 ;
}
return V_75 ;
}
static int F_26 ( struct V_34 * V_35 , int V_68 )
{
int V_57 ;
int V_43 ;
V_57 = V_35 -> V_57 ;
if ( V_35 -> V_63 )
V_57 = V_35 -> V_63 ;
V_43 = F_21 ( V_2 , 4 , 1 , NULL ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) , V_68 ) ;
if ( V_68 == V_81 &&
V_43 == - 8 ) {
V_43 = F_21 ( V_2 , 4 , 1 , NULL ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) , V_82 ) ;
}
return V_43 ;
}
static int F_27 ( struct V_34 * V_35 , int V_83 )
{
int V_43 ;
int V_84 ;
#define F_28 (1000)
#define F_29 (300 * 1000)
while ( 1 ) {
V_43 = F_25 ( V_35 , & V_84 ) ;
if ( V_43 != V_80 )
return V_43 ;
if ( V_83 <= 0 ) {
F_3 ( L_29 ,
V_11 , V_83 ) ;
return V_65 ;
}
if ( V_84 <= 0 ) {
F_3 ( L_30 ,
V_11 , V_84 ) ;
V_84 = F_28 ;
} else if ( V_84 > F_29 ) {
F_3 ( L_31 ,
V_11 , V_84 ) ;
V_84 = F_29 ;
}
V_83 -= V_84 ;
F_30 ( V_84 ) ;
}
return V_65 ;
}
static int F_31 ( struct V_34 * V_35 , int V_85 , char * V_86 , unsigned long V_87 )
{
int V_57 ;
unsigned long V_88 ;
int V_43 ;
F_32 ( & V_13 , V_88 ) ;
memset ( V_89 , 0 , V_14 ) ;
V_57 = V_35 -> V_57 ;
if ( V_35 -> V_63 )
V_57 = V_35 -> V_63 ;
V_43 = F_21 ( V_5 , 8 , 1 , NULL , V_57 ,
F_22 ( V_35 -> V_56 -> V_72 ) , F_23 ( V_35 -> V_56 -> V_72 ) ,
F_33 ( V_86 ) , V_87 ,
F_33 ( V_89 ) , V_14 ,
V_85 ) ;
if ( ! V_43 )
F_34 ( V_89 , V_90 , 0 ) ;
F_35 ( & V_13 , V_88 ) ;
return V_43 ;
}
static int F_36 ( struct V_34 * V_35 )
{
int V_57 ;
int V_43 ;
V_57 = V_35 -> V_57 ;
if ( V_35 -> V_63 )
V_57 = V_35 -> V_63 ;
if ( V_8 != V_10 ) {
V_43 = F_21 ( V_8 , 3 , 1 , NULL ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) ) ;
} else if ( V_9 != V_10 ) {
V_43 = F_21 ( V_9 , 3 , 1 , NULL ,
V_57 , F_22 ( V_35 -> V_56 -> V_72 ) ,
F_23 ( V_35 -> V_56 -> V_72 ) ) ;
} else {
return - V_91 ;
}
if ( V_43 )
F_3 ( L_32 ,
V_11 , V_35 -> V_56 -> V_66 , V_35 -> V_63 , V_43 ) ;
return V_43 ;
}
static int F_37 ( struct V_17 * V_18 , int V_92 , int V_93 , T_1 * V_94 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( V_18 ) ;
return F_8 ( V_20 , V_92 , V_93 , V_94 ) ;
}
static int F_38 ( struct V_17 * V_18 , int V_92 , int V_93 , T_1 V_94 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( V_18 ) ;
return F_39 ( V_20 , V_92 , V_93 , V_94 ) ;
}
static int T_3 F_40 ( void )
{
int V_43 = - V_12 ;
if ( ! F_41 ( V_95 ) )
return V_43 ;
V_43 = F_42 ( & V_96 ) ;
if ( ! V_43 )
F_43 ( L_33 ) ;
else
F_43 ( L_34 ,
V_43 ) ;
return V_43 ;
}
