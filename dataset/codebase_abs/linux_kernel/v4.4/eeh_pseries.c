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
if ( V_1 == V_10 ||
V_2 == V_10 ||
( V_3 == V_10 &&
V_4 == V_10 ) ||
V_5 == V_10 ||
( V_8 == V_10 &&
V_9 == V_10 ) ) {
F_3 ( L_10 ) ;
return - V_11 ;
}
F_4 ( & V_12 ) ;
V_13 = F_2 ( L_11 ) ;
if ( V_13 == V_10 ) {
F_3 ( L_12 ,
V_14 ) ;
V_13 = 1024 ;
} else if ( V_13 > V_15 ) {
F_3 ( L_13 ,
V_14 , V_13 , V_15 ) ;
V_13 = V_15 ;
}
F_5 ( V_16 | V_17 ) ;
return 0 ;
}
static int F_6 ( struct V_18 * V_19 )
{
T_1 V_20 ;
if ( ! V_19 )
return 0 ;
F_7 ( V_19 , V_21 , 2 , & V_20 ) ;
if ( ! ( V_20 & V_22 ) )
return 0 ;
return V_23 ;
}
static int F_8 ( struct V_18 * V_19 , int V_24 )
{
int V_25 = F_6 ( V_19 ) ;
int V_26 = 48 ;
T_1 V_27 ;
if ( ! V_25 )
return 0 ;
while ( V_26 -- ) {
F_7 ( V_19 , V_25 , 1 , & V_25 ) ;
if ( V_25 < 0x40 )
break;
V_25 &= ~ 3 ;
F_7 ( V_19 , V_25 + V_28 , 1 , & V_27 ) ;
if ( V_27 == 0xff )
break;
if ( V_27 == V_24 )
return V_25 ;
V_25 += V_29 ;
}
return 0 ;
}
static int F_9 ( struct V_18 * V_19 , int V_24 )
{
struct V_30 * V_31 = F_10 ( V_19 ) ;
T_1 V_32 ;
int V_25 = 256 ;
int V_33 = ( 4096 - 256 ) / 8 ;
if ( ! V_31 || ! V_31 -> V_34 )
return 0 ;
if ( F_7 ( V_19 , V_25 , 4 , & V_32 ) != V_35 )
return 0 ;
else if ( ! V_32 )
return 0 ;
while ( V_33 -- > 0 ) {
if ( F_11 ( V_32 ) == V_24 && V_25 )
return V_25 ;
V_25 = F_12 ( V_32 ) ;
if ( V_25 < 256 )
break;
if ( F_7 ( V_19 , V_25 , 4 , & V_32 ) != V_35 )
break;
}
return 0 ;
}
static void * F_13 ( struct V_18 * V_19 , void * V_36 )
{
struct V_30 * V_31 ;
struct V_37 V_38 ;
T_1 V_39 ;
int V_40 = 0 ;
int V_41 ;
V_31 = F_10 ( V_19 ) ;
if ( ! V_31 || V_31 -> V_38 )
return NULL ;
if ( ! V_19 -> V_42 || ! V_19 -> V_43 || ! V_19 -> V_44 )
return NULL ;
if ( ( V_19 -> V_44 >> 8 ) == V_45 )
return NULL ;
V_31 -> V_44 = V_19 -> V_44 ;
V_31 -> V_46 = F_8 ( V_19 , V_47 ) ;
V_31 -> V_34 = F_8 ( V_19 , V_48 ) ;
V_31 -> V_49 = F_9 ( V_19 , V_50 ) ;
V_31 -> V_51 &= 0xFFFFFF00 ;
if ( ( V_31 -> V_44 >> 8 ) == V_52 ) {
V_31 -> V_51 |= V_53 ;
if ( V_31 -> V_34 ) {
F_7 ( V_19 , V_31 -> V_34 + V_54 ,
2 , & V_39 ) ;
V_39 = ( V_39 & V_55 ) >> 4 ;
if ( V_39 == V_56 )
V_31 -> V_51 |= V_57 ;
else if ( V_39 == V_58 )
V_31 -> V_51 |= V_59 ;
}
}
memset ( & V_38 , 0 , sizeof( struct V_37 ) ) ;
V_38 . V_60 = V_31 -> V_60 ;
V_38 . V_61 = ( V_19 -> V_62 << 16 ) | ( V_19 -> V_63 << 8 ) ;
V_41 = V_64 -> V_65 ( & V_38 , V_66 ) ;
if ( ! V_41 ) {
V_31 -> V_61 = ( V_19 -> V_62 << 16 ) | ( V_19 -> V_63 << 8 ) ;
V_31 -> V_67 = V_64 -> V_68 ( & V_38 ) ;
V_38 . V_69 = V_31 -> V_67 ;
V_41 = V_64 -> V_70 ( & V_38 , NULL ) ;
if ( V_41 > 0 && V_41 != V_71 )
V_40 = 1 ;
if ( V_40 ) {
F_5 ( V_72 ) ;
F_14 ( V_31 ) ;
F_15 ( L_14 ,
V_14 , V_19 -> V_62 , F_16 ( V_19 -> V_63 ) ,
F_17 ( V_19 -> V_63 ) , V_38 . V_60 -> V_73 ,
V_38 . V_69 ) ;
} else if ( V_19 -> V_74 && F_10 ( V_19 -> V_74 ) &&
( F_10 ( V_19 -> V_74 ) ) -> V_38 ) {
V_31 -> V_61 = F_10 ( V_19 -> V_74 ) -> V_61 ;
V_31 -> V_67 = F_10 ( V_19 -> V_74 ) -> V_67 ;
F_14 ( V_31 ) ;
}
}
F_18 ( V_31 ) ;
return NULL ;
}
static int F_19 ( struct V_37 * V_38 , int V_75 )
{
int V_41 = 0 ;
int V_61 ;
switch ( V_75 ) {
case V_76 :
case V_66 :
case V_77 :
case V_78 :
V_61 = V_38 -> V_61 ;
if ( V_38 -> V_69 )
V_61 = V_38 -> V_69 ;
break;
case V_79 :
return 0 ;
default:
F_20 ( L_15 ,
V_14 , V_75 ) ;
return - V_11 ;
}
V_41 = F_21 ( V_1 , 4 , 1 , NULL ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) , V_75 ) ;
return V_41 ;
}
static int F_24 ( struct V_37 * V_38 )
{
int V_41 = 0 ;
int V_81 [ 3 ] ;
if ( V_6 != V_10 ) {
V_41 = F_21 ( V_6 , 4 , 2 , V_81 ,
V_38 -> V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) , 1 ) ;
if ( V_41 || ( V_81 [ 0 ] == 0 ) )
return 0 ;
V_41 = F_21 ( V_6 , 4 , 2 , V_81 ,
V_38 -> V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) , 0 ) ;
if ( V_41 ) {
F_25 ( L_16 ,
V_14 , V_38 -> V_60 -> V_73 , V_38 -> V_61 ) ;
return 0 ;
}
return V_81 [ 0 ] ;
}
if ( V_7 != V_10 ) {
V_41 = F_21 ( V_7 , 4 , 2 , V_81 ,
V_38 -> V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) , 0 ) ;
if ( V_41 ) {
F_25 ( L_16 ,
V_14 , V_38 -> V_60 -> V_73 , V_38 -> V_61 ) ;
return 0 ;
}
return V_81 [ 0 ] ;
}
return V_41 ;
}
static int F_26 ( struct V_37 * V_38 , int * V_82 )
{
int V_61 ;
int V_41 ;
int V_81 [ 4 ] ;
int V_83 ;
V_61 = V_38 -> V_61 ;
if ( V_38 -> V_69 )
V_61 = V_38 -> V_69 ;
if ( V_3 != V_10 ) {
V_41 = F_21 ( V_3 , 3 , 4 , V_81 ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) ) ;
} else if ( V_4 != V_10 ) {
V_81 [ 2 ] = 0 ;
V_41 = F_21 ( V_4 , 3 , 3 , V_81 ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) ) ;
} else {
return V_71 ;
}
if ( V_41 )
return V_41 ;
if ( ! V_81 [ 1 ] )
return V_71 ;
switch( V_81 [ 0 ] ) {
case 0 :
V_83 = V_84 |
V_85 ;
break;
case 1 :
V_83 = V_86 |
V_84 |
V_85 ;
break;
case 2 :
V_83 = 0 ;
break;
case 4 :
V_83 = V_87 ;
break;
case 5 :
if ( V_81 [ 2 ] ) {
if ( V_82 ) * V_82 = V_81 [ 2 ] ;
V_83 = V_88 ;
} else {
V_83 = V_71 ;
}
break;
default:
V_83 = V_71 ;
}
return V_83 ;
}
static int F_27 ( struct V_37 * V_38 , int V_75 )
{
int V_61 ;
int V_41 ;
V_61 = V_38 -> V_61 ;
if ( V_38 -> V_69 )
V_61 = V_38 -> V_69 ;
V_41 = F_21 ( V_2 , 4 , 1 , NULL ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) , V_75 ) ;
if ( V_75 == V_89 &&
V_41 == - 8 ) {
V_75 = V_90 ;
V_41 = F_21 ( V_2 , 4 , 1 , NULL ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) , V_75 ) ;
}
if ( V_75 == V_89 ||
V_75 == V_90 )
F_28 ( V_91 ) ;
else
F_28 ( V_92 ) ;
return V_41 ;
}
static int F_29 ( struct V_37 * V_38 , int V_93 )
{
int V_41 ;
int V_94 ;
#define F_30 (1000)
#define F_31 (300 * 1000)
while ( 1 ) {
V_41 = F_26 ( V_38 , & V_94 ) ;
if ( V_41 != V_88 )
return V_41 ;
if ( V_93 <= 0 ) {
F_25 ( L_17 ,
V_14 , V_93 ) ;
return V_71 ;
}
if ( V_94 <= 0 ) {
F_25 ( L_18 ,
V_14 , V_94 ) ;
V_94 = F_30 ;
} else if ( V_94 > F_31 ) {
F_25 ( L_19 ,
V_14 , V_94 ) ;
V_94 = F_31 ;
}
V_93 -= V_94 ;
F_28 ( V_94 ) ;
}
return V_71 ;
}
static int F_32 ( struct V_37 * V_38 , int V_95 , char * V_96 , unsigned long V_97 )
{
int V_61 ;
unsigned long V_98 ;
int V_41 ;
F_33 ( & V_12 , V_98 ) ;
memset ( V_99 , 0 , V_13 ) ;
V_61 = V_38 -> V_61 ;
if ( V_38 -> V_69 )
V_61 = V_38 -> V_69 ;
V_41 = F_21 ( V_5 , 8 , 1 , NULL , V_61 ,
F_22 ( V_38 -> V_60 -> V_80 ) , F_23 ( V_38 -> V_60 -> V_80 ) ,
F_34 ( V_96 ) , V_97 ,
F_34 ( V_99 ) , V_13 ,
V_95 ) ;
if ( ! V_41 )
F_35 ( V_99 , V_100 , 0 ) ;
F_36 ( & V_12 , V_98 ) ;
return V_41 ;
}
static int F_37 ( struct V_37 * V_38 )
{
int V_61 ;
int V_41 ;
V_61 = V_38 -> V_61 ;
if ( V_38 -> V_69 )
V_61 = V_38 -> V_69 ;
if ( V_8 != V_10 ) {
V_41 = F_21 ( V_8 , 3 , 1 , NULL ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) ) ;
} else if ( V_9 != V_10 ) {
V_41 = F_21 ( V_9 , 3 , 1 , NULL ,
V_61 , F_22 ( V_38 -> V_60 -> V_80 ) ,
F_23 ( V_38 -> V_60 -> V_80 ) ) ;
} else {
return - V_101 ;
}
if ( V_41 )
F_25 ( L_20 ,
V_14 , V_38 -> V_60 -> V_73 , V_38 -> V_69 , V_41 ) ;
return V_41 ;
}
static int F_38 ( struct V_18 * V_19 , int V_102 , int V_103 , T_1 * V_104 )
{
return F_7 ( V_19 , V_102 , V_103 , V_104 ) ;
}
static int F_39 ( struct V_18 * V_19 , int V_102 , int V_103 , T_1 V_104 )
{
return F_40 ( V_19 , V_102 , V_103 , V_104 ) ;
}
static int T_2 F_41 ( void )
{
int V_41 ;
V_41 = F_42 ( & V_105 ) ;
if ( ! V_41 )
F_3 ( L_21 ) ;
else
F_3 ( L_22 ,
V_41 ) ;
return V_41 ;
}
