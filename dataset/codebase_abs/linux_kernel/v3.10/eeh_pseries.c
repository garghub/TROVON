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
static void * F_6 ( struct V_17 * V_18 , void * V_19 )
{
struct V_20 * V_21 ;
struct V_22 V_23 ;
const T_1 * V_24 , * V_25 , * V_26 ;
const T_1 * V_27 ;
int V_28 = 0 ;
int V_29 ;
V_21 = F_7 ( V_18 ) ;
if ( ! F_8 ( V_18 ) )
return NULL ;
V_24 = F_9 ( V_18 , L_20 , NULL ) ;
V_25 = F_9 ( V_18 , L_21 , NULL ) ;
V_26 = F_9 ( V_18 , L_22 , NULL ) ;
if ( ! V_24 || ! V_25 || ! V_26 )
return NULL ;
if ( V_18 -> type && ! strcmp ( V_18 -> type , L_23 ) )
return NULL ;
V_21 -> V_24 = * V_24 ;
V_21 -> V_30 = 0 ;
V_27 = F_9 ( V_18 , L_24 , NULL ) ;
if ( ! V_27 ) {
F_3 ( L_25 ,
V_11 , V_18 -> V_31 ) ;
return NULL ;
}
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_23 . V_32 = V_21 -> V_32 ;
V_23 . V_33 = V_27 [ 0 ] ;
V_29 = V_34 -> V_35 ( & V_23 , V_36 ) ;
if ( ! V_29 ) {
V_21 -> V_33 = V_27 [ 0 ] ;
V_21 -> V_37 = V_34 -> V_38 ( & V_23 ) ;
V_23 . V_39 = V_21 -> V_37 ;
V_29 = V_34 -> V_40 ( & V_23 , NULL ) ;
if ( V_29 > 0 && V_29 != V_41 )
V_28 = 1 ;
if ( V_28 ) {
V_42 = 1 ;
F_10 ( V_21 ) ;
F_11 ( L_26 ,
V_11 , V_18 -> V_31 , V_23 . V_32 -> V_43 ,
V_23 . V_39 , V_23 . V_33 ) ;
} else if ( V_18 -> V_44 && F_7 ( V_18 -> V_44 ) &&
( F_7 ( V_18 -> V_44 ) ) -> V_23 ) {
V_21 -> V_33 = F_7 ( V_18 -> V_44 ) -> V_33 ;
V_21 -> V_37 = F_7 ( V_18 -> V_44 ) -> V_37 ;
F_10 ( V_21 ) ;
}
}
F_12 ( V_21 ) ;
return NULL ;
}
static int F_13 ( struct V_22 * V_23 , int V_45 )
{
int V_29 = 0 ;
int V_33 ;
switch ( V_45 ) {
case V_46 :
case V_36 :
case V_47 :
case V_48 :
V_33 = V_23 -> V_33 ;
if ( V_23 -> V_39 )
V_33 = V_23 -> V_39 ;
break;
default:
F_14 ( L_27 ,
V_11 , V_45 ) ;
return - V_12 ;
}
V_29 = F_15 ( V_1 , 4 , 1 , NULL ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) , V_45 ) ;
return V_29 ;
}
static int F_18 ( struct V_22 * V_23 )
{
int V_29 = 0 ;
int V_50 [ 3 ] ;
if ( V_6 != V_10 ) {
V_29 = F_15 ( V_6 , 4 , 2 , V_50 ,
V_23 -> V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) , 1 ) ;
if ( V_29 || ( V_50 [ 0 ] == 0 ) )
return 0 ;
V_29 = F_15 ( V_6 , 4 , 2 , V_50 ,
V_23 -> V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) , 0 ) ;
if ( V_29 ) {
F_3 ( L_28 ,
V_11 , V_23 -> V_32 -> V_43 , V_23 -> V_33 ) ;
return 0 ;
}
return V_50 [ 0 ] ;
}
if ( V_7 != V_10 ) {
V_29 = F_15 ( V_7 , 4 , 2 , V_50 ,
V_23 -> V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) , 0 ) ;
if ( V_29 ) {
F_3 ( L_28 ,
V_11 , V_23 -> V_32 -> V_43 , V_23 -> V_33 ) ;
return 0 ;
}
return V_50 [ 0 ] ;
}
return V_29 ;
}
static int F_19 ( struct V_22 * V_23 , int * V_51 )
{
int V_33 ;
int V_29 ;
int V_50 [ 4 ] ;
int V_52 ;
V_33 = V_23 -> V_33 ;
if ( V_23 -> V_39 )
V_33 = V_23 -> V_39 ;
if ( V_3 != V_10 ) {
V_29 = F_15 ( V_3 , 3 , 4 , V_50 ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) ) ;
} else if ( V_4 != V_10 ) {
V_50 [ 2 ] = 0 ;
V_29 = F_15 ( V_4 , 3 , 3 , V_50 ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) ) ;
} else {
return V_41 ;
}
if ( V_29 )
return V_29 ;
V_52 = 0 ;
if ( V_50 [ 1 ] ) {
switch( V_50 [ 0 ] ) {
case 0 :
V_52 &= ~ V_53 ;
V_52 |= V_54 ;
V_52 |= V_55 ;
break;
case 1 :
V_52 |= V_53 ;
V_52 |= V_54 ;
V_52 |= V_55 ;
break;
case 2 :
V_52 &= ~ V_53 ;
V_52 &= ~ V_54 ;
V_52 &= ~ V_55 ;
break;
case 4 :
V_52 &= ~ V_53 ;
V_52 &= ~ V_54 ;
V_52 &= ~ V_55 ;
V_52 |= V_56 ;
break;
case 5 :
if ( V_50 [ 2 ] ) {
if ( V_51 ) * V_51 = V_50 [ 2 ] ;
V_52 = V_57 ;
} else {
V_52 = V_41 ;
}
default:
V_52 = V_41 ;
}
} else {
V_52 = V_41 ;
}
return V_52 ;
}
static int F_20 ( struct V_22 * V_23 , int V_45 )
{
int V_33 ;
int V_29 ;
V_33 = V_23 -> V_33 ;
if ( V_23 -> V_39 )
V_33 = V_23 -> V_39 ;
V_29 = F_15 ( V_2 , 4 , 1 , NULL ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) , V_45 ) ;
if ( V_45 == V_58 &&
V_29 == - 8 ) {
V_29 = F_15 ( V_2 , 4 , 1 , NULL ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) , V_59 ) ;
}
return V_29 ;
}
static int F_21 ( struct V_22 * V_23 , int V_60 )
{
int V_29 ;
int V_61 ;
#define F_22 (1000)
#define F_23 (300 * 1000)
while ( 1 ) {
V_29 = F_19 ( V_23 , & V_61 ) ;
if ( V_29 != V_57 )
return V_29 ;
if ( V_60 <= 0 ) {
F_3 ( L_29 ,
V_11 , V_60 ) ;
return V_41 ;
}
if ( V_61 <= 0 ) {
F_3 ( L_30 ,
V_11 , V_61 ) ;
V_61 = F_22 ;
} else if ( V_61 > F_23 ) {
F_3 ( L_31 ,
V_11 , V_61 ) ;
V_61 = F_23 ;
}
V_60 -= V_61 ;
F_24 ( V_61 ) ;
}
return V_41 ;
}
static int F_25 ( struct V_22 * V_23 , int V_62 , char * V_63 , unsigned long V_64 )
{
int V_33 ;
unsigned long V_65 ;
int V_29 ;
F_26 ( & V_13 , V_65 ) ;
memset ( V_66 , 0 , V_14 ) ;
V_33 = V_23 -> V_33 ;
if ( V_23 -> V_39 )
V_33 = V_23 -> V_39 ;
V_29 = F_15 ( V_5 , 8 , 1 , NULL , V_33 ,
F_16 ( V_23 -> V_32 -> V_49 ) , F_17 ( V_23 -> V_32 -> V_49 ) ,
F_27 ( V_63 ) , V_64 ,
F_27 ( V_66 ) , V_14 ,
V_62 ) ;
if ( ! V_29 )
F_28 ( V_66 , V_67 , 0 ) ;
F_29 ( & V_13 , V_65 ) ;
return V_29 ;
}
static int F_30 ( struct V_22 * V_23 )
{
int V_33 ;
int V_29 ;
V_33 = V_23 -> V_33 ;
if ( V_23 -> V_39 )
V_33 = V_23 -> V_39 ;
if ( V_8 != V_10 ) {
V_29 = F_15 ( V_8 , 3 , 1 , NULL ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) ) ;
} else if ( V_9 != V_10 ) {
V_29 = F_15 ( V_9 , 3 , 1 , NULL ,
V_33 , F_16 ( V_23 -> V_32 -> V_49 ) ,
F_17 ( V_23 -> V_32 -> V_49 ) ) ;
} else {
return - V_68 ;
}
if ( V_29 )
F_3 ( L_32 ,
V_11 , V_23 -> V_32 -> V_43 , V_23 -> V_39 , V_29 ) ;
return V_29 ;
}
static int F_31 ( struct V_17 * V_18 , int V_69 , int V_70 , T_1 * V_71 )
{
struct V_72 * V_73 ;
V_73 = F_32 ( V_18 ) ;
return F_33 ( V_73 , V_69 , V_70 , V_71 ) ;
}
static int F_34 ( struct V_17 * V_18 , int V_69 , int V_70 , T_1 V_71 )
{
struct V_72 * V_73 ;
V_73 = F_32 ( V_18 ) ;
return F_35 ( V_73 , V_69 , V_70 , V_71 ) ;
}
static int T_2 F_36 ( void )
{
int V_29 = - V_12 ;
if ( ! F_37 ( V_74 ) )
return V_29 ;
V_29 = F_38 ( & V_75 ) ;
if ( ! V_29 )
F_39 ( L_33 ) ;
else
F_39 ( L_34 ,
V_29 ) ;
return V_29 ;
}
