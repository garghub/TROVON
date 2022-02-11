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
if ( V_8 == V_9 )
V_8 = F_2 ( L_9 ) ;
if ( V_1 == V_9 ||
V_2 == V_9 ||
( V_3 == V_9 &&
V_4 == V_9 ) ||
V_5 == V_9 ||
V_8 == V_9 ) {
F_3 ( L_10 ) ;
return - V_10 ;
}
F_4 ( & V_11 ) ;
V_12 = F_2 ( L_11 ) ;
if ( V_12 == V_9 ) {
F_3 ( L_12 ,
V_13 ) ;
V_12 = 1024 ;
} else if ( V_12 > V_14 ) {
F_3 ( L_13 ,
V_13 , V_12 , V_14 ) ;
V_12 = V_14 ;
}
F_5 ( V_15 | V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 )
{
T_1 V_19 ;
if ( ! V_18 )
return 0 ;
F_7 ( V_18 , V_20 , 2 , & V_19 ) ;
if ( ! ( V_19 & V_21 ) )
return 0 ;
return V_22 ;
}
static int F_8 ( struct V_17 * V_18 , int V_23 )
{
int V_24 = F_6 ( V_18 ) ;
int V_25 = 48 ;
T_1 V_26 ;
if ( ! V_24 )
return 0 ;
while ( V_25 -- ) {
F_7 ( V_18 , V_24 , 1 , & V_24 ) ;
if ( V_24 < 0x40 )
break;
V_24 &= ~ 3 ;
F_7 ( V_18 , V_24 + V_27 , 1 , & V_26 ) ;
if ( V_26 == 0xff )
break;
if ( V_26 == V_23 )
return V_24 ;
V_24 += V_28 ;
}
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , int V_23 )
{
struct V_29 * V_30 = F_10 ( V_18 ) ;
T_1 V_31 ;
int V_24 = 256 ;
int V_32 = ( 4096 - 256 ) / 8 ;
if ( ! V_30 || ! V_30 -> V_33 )
return 0 ;
if ( F_7 ( V_18 , V_24 , 4 , & V_31 ) != V_34 )
return 0 ;
else if ( ! V_31 )
return 0 ;
while ( V_32 -- > 0 ) {
if ( F_11 ( V_31 ) == V_23 && V_24 )
return V_24 ;
V_24 = F_12 ( V_31 ) ;
if ( V_24 < 256 )
break;
if ( F_7 ( V_18 , V_24 , 4 , & V_31 ) != V_34 )
break;
}
return 0 ;
}
static void * F_13 ( struct V_17 * V_18 , void * V_35 )
{
struct V_29 * V_30 ;
struct V_36 V_37 ;
T_1 V_38 ;
int V_39 = 0 ;
int V_40 ;
V_30 = F_10 ( V_18 ) ;
if ( ! V_30 || V_30 -> V_37 )
return NULL ;
if ( ! V_18 -> V_41 || ! V_18 -> V_42 || ! V_18 -> V_43 )
return NULL ;
if ( ( V_18 -> V_43 >> 8 ) == V_44 )
return NULL ;
V_30 -> V_43 = V_18 -> V_43 ;
V_30 -> V_45 = F_8 ( V_18 , V_46 ) ;
V_30 -> V_33 = F_8 ( V_18 , V_47 ) ;
V_30 -> V_48 = F_9 ( V_18 , V_49 ) ;
V_30 -> V_50 &= 0xFFFFFF00 ;
if ( ( V_30 -> V_43 >> 8 ) == V_51 ) {
V_30 -> V_50 |= V_52 ;
if ( V_30 -> V_33 ) {
F_7 ( V_18 , V_30 -> V_33 + V_53 ,
2 , & V_38 ) ;
V_38 = ( V_38 & V_54 ) >> 4 ;
if ( V_38 == V_55 )
V_30 -> V_50 |= V_56 ;
else if ( V_38 == V_57 )
V_30 -> V_50 |= V_58 ;
}
}
memset ( & V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 . V_59 = V_18 -> V_59 ;
V_37 . V_60 = ( V_18 -> V_61 << 16 ) | ( V_18 -> V_62 << 8 ) ;
V_40 = V_63 -> V_64 ( & V_37 , V_65 ) ;
if ( ! V_40 ) {
V_30 -> V_66 = V_63 -> V_67 ( & V_37 ) ;
V_37 . V_68 = V_30 -> V_66 ;
V_40 = V_63 -> V_69 ( & V_37 , NULL ) ;
if ( V_40 > 0 && V_40 != V_70 )
V_39 = 1 ;
if ( V_39 ) {
F_5 ( V_71 ) ;
F_14 ( V_30 ) ;
F_15 ( L_14 ,
V_13 , V_18 -> V_61 , F_16 ( V_18 -> V_62 ) ,
F_17 ( V_18 -> V_62 ) , V_37 . V_59 -> V_72 ,
V_37 . V_68 ) ;
} else if ( V_18 -> V_73 && F_10 ( V_18 -> V_73 ) &&
( F_10 ( V_18 -> V_73 ) ) -> V_37 ) {
V_30 -> V_66 = F_10 ( V_18 -> V_73 ) -> V_66 ;
F_14 ( V_30 ) ;
}
}
F_18 ( V_30 ) ;
return NULL ;
}
static int F_19 ( struct V_36 * V_37 , int V_74 )
{
int V_40 = 0 ;
int V_60 ;
switch ( V_74 ) {
case V_75 :
case V_65 :
case V_76 :
case V_77 :
V_60 = V_37 -> V_60 ;
if ( V_37 -> V_68 )
V_60 = V_37 -> V_68 ;
break;
case V_78 :
return 0 ;
default:
F_20 ( L_15 ,
V_13 , V_74 ) ;
return - V_10 ;
}
V_40 = F_21 ( V_1 , 4 , 1 , NULL ,
V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) , V_74 ) ;
return V_40 ;
}
static int F_24 ( struct V_36 * V_37 )
{
int V_40 = 0 ;
int V_80 [ 3 ] ;
if ( V_6 != V_9 ) {
V_40 = F_21 ( V_6 , 4 , 2 , V_80 ,
V_37 -> V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) , 1 ) ;
if ( V_40 || ( V_80 [ 0 ] == 0 ) )
return 0 ;
V_40 = F_21 ( V_6 , 4 , 2 , V_80 ,
V_37 -> V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) , 0 ) ;
if ( V_40 ) {
F_25 ( L_16 ,
V_13 , V_37 -> V_59 -> V_72 , V_37 -> V_60 ) ;
return 0 ;
}
return V_80 [ 0 ] ;
}
if ( V_7 != V_9 ) {
V_40 = F_21 ( V_7 , 4 , 2 , V_80 ,
V_37 -> V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) , 0 ) ;
if ( V_40 ) {
F_25 ( L_16 ,
V_13 , V_37 -> V_59 -> V_72 , V_37 -> V_60 ) ;
return 0 ;
}
return V_80 [ 0 ] ;
}
return V_40 ;
}
static int F_26 ( struct V_36 * V_37 , int * V_81 )
{
int V_60 ;
int V_40 ;
int V_80 [ 4 ] ;
int V_82 ;
V_60 = V_37 -> V_60 ;
if ( V_37 -> V_68 )
V_60 = V_37 -> V_68 ;
if ( V_3 != V_9 ) {
V_40 = F_21 ( V_3 , 3 , 4 , V_80 ,
V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) ) ;
} else if ( V_4 != V_9 ) {
V_80 [ 2 ] = 0 ;
V_40 = F_21 ( V_4 , 3 , 3 , V_80 ,
V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) ) ;
} else {
return V_70 ;
}
if ( V_40 )
return V_40 ;
if ( ! V_80 [ 1 ] )
return V_70 ;
switch( V_80 [ 0 ] ) {
case 0 :
V_82 = V_83 |
V_84 ;
break;
case 1 :
V_82 = V_85 |
V_83 |
V_84 ;
break;
case 2 :
V_82 = 0 ;
break;
case 4 :
V_82 = V_86 ;
break;
case 5 :
if ( V_80 [ 2 ] ) {
if ( V_81 ) * V_81 = V_80 [ 2 ] ;
V_82 = V_87 ;
} else {
V_82 = V_70 ;
}
break;
default:
V_82 = V_70 ;
}
return V_82 ;
}
static int F_27 ( struct V_36 * V_37 , int V_74 )
{
int V_60 ;
int V_40 ;
V_60 = V_37 -> V_60 ;
if ( V_37 -> V_68 )
V_60 = V_37 -> V_68 ;
V_40 = F_21 ( V_2 , 4 , 1 , NULL ,
V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) , V_74 ) ;
if ( V_74 == V_88 &&
V_40 == - 8 ) {
V_74 = V_89 ;
V_40 = F_21 ( V_2 , 4 , 1 , NULL ,
V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) , V_74 ) ;
}
if ( V_74 == V_88 ||
V_74 == V_89 )
F_28 ( V_90 ) ;
else
F_28 ( V_91 ) ;
return V_40 ;
}
static int F_29 ( struct V_36 * V_37 , int V_92 )
{
int V_40 ;
int V_93 ;
#define F_30 (1000)
#define F_31 (300 * 1000)
while ( 1 ) {
V_40 = F_26 ( V_37 , & V_93 ) ;
if ( V_40 != V_87 )
return V_40 ;
if ( V_92 <= 0 ) {
F_25 ( L_17 ,
V_13 , V_92 ) ;
return V_70 ;
}
if ( V_93 <= 0 ) {
F_25 ( L_18 ,
V_13 , V_93 ) ;
V_93 = F_30 ;
} else if ( V_93 > F_31 ) {
F_25 ( L_19 ,
V_13 , V_93 ) ;
V_93 = F_31 ;
}
V_92 -= V_93 ;
F_28 ( V_93 ) ;
}
return V_70 ;
}
static int F_32 ( struct V_36 * V_37 , int V_94 , char * V_95 , unsigned long V_96 )
{
int V_60 ;
unsigned long V_97 ;
int V_40 ;
F_33 ( & V_11 , V_97 ) ;
memset ( V_98 , 0 , V_12 ) ;
V_60 = V_37 -> V_60 ;
if ( V_37 -> V_68 )
V_60 = V_37 -> V_68 ;
V_40 = F_21 ( V_5 , 8 , 1 , NULL , V_60 ,
F_22 ( V_37 -> V_59 -> V_79 ) , F_23 ( V_37 -> V_59 -> V_79 ) ,
F_34 ( V_95 ) , V_96 ,
F_34 ( V_98 ) , V_12 ,
V_94 ) ;
if ( ! V_40 )
F_35 ( V_98 , V_99 , 0 ) ;
F_36 ( & V_11 , V_97 ) ;
return V_40 ;
}
static int F_37 ( struct V_36 * V_37 )
{
int V_60 ;
int V_40 ;
int V_92 = 200 ;
V_60 = V_37 -> V_60 ;
if ( V_37 -> V_68 )
V_60 = V_37 -> V_68 ;
while ( V_92 > 0 ) {
V_40 = F_21 ( V_8 , 3 , 1 , NULL ,
V_60 , F_22 ( V_37 -> V_59 -> V_79 ) ,
F_23 ( V_37 -> V_59 -> V_79 ) ) ;
if ( ! V_40 )
return V_40 ;
if ( V_40 > V_100 + 2 &&
V_40 <= V_101 )
V_40 = V_100 + 2 ;
V_92 -= F_38 ( V_40 ) ;
if ( V_92 < 0 )
break;
F_39 ( V_40 ) ;
}
F_25 ( L_20 ,
V_13 , V_37 -> V_59 -> V_72 , V_37 -> V_68 , V_40 ) ;
return V_40 ;
}
static int F_40 ( struct V_17 * V_18 , int V_102 , int V_103 , T_1 * V_104 )
{
return F_7 ( V_18 , V_102 , V_103 , V_104 ) ;
}
static int F_41 ( struct V_17 * V_18 , int V_102 , int V_103 , T_1 V_104 )
{
return F_42 ( V_18 , V_102 , V_103 , V_104 ) ;
}
static int T_2 F_43 ( void )
{
int V_40 ;
V_40 = F_44 ( & V_105 ) ;
if ( ! V_40 )
F_3 ( L_21 ) ;
else
F_3 ( L_22 ,
V_40 ) ;
return V_40 ;
}
