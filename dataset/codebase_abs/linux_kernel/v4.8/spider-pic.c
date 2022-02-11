static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static void T_1 * F_3 ( struct V_1 * V_4 ,
unsigned int V_5 )
{
return V_4 -> V_6 + V_7 + 8 * V_5 ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
void T_1 * V_8 = F_3 ( V_4 , F_5 ( V_3 ) ) ;
F_6 ( V_8 , F_7 ( V_8 ) | 0x30000000u ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
void T_1 * V_8 = F_3 ( V_4 , F_5 ( V_3 ) ) ;
F_6 ( V_8 , F_7 ( V_8 ) & ~ 0x30000000u ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_5 = F_5 ( V_3 ) ;
if ( F_10 ( V_3 ) )
return;
if ( V_5 < 47 || V_5 > 50 )
return;
F_6 ( V_4 -> V_6 + V_9 , 0x100 | ( V_5 & 0xf ) ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned int type )
{
unsigned int V_10 = type & V_11 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_12 = F_5 ( V_3 ) ;
void T_1 * V_8 = F_3 ( V_4 , V_12 ) ;
T_2 V_13 ;
T_2 V_14 ;
if ( V_10 != V_15 && V_10 != V_16 &&
( V_12 < 47 || V_12 > 50 ) )
return - V_17 ;
switch( V_10 ) {
case V_18 :
V_14 = 0x3 ;
break;
case V_19 :
V_14 = 0x2 ;
break;
case V_20 :
V_14 = 0x0 ;
break;
case V_16 :
case V_15 :
V_14 = 0x1 ;
break;
default:
return - V_17 ;
}
V_13 = F_7 ( V_8 ) & 0x30000000u ;
F_6 ( V_8 , V_13 | ( V_14 << 24 ) | ( 0x7 << 16 ) |
( V_4 -> V_21 << 4 ) | 0xe ) ;
F_6 ( V_8 + 4 , ( 0x2 << 16 ) | ( V_12 & 0xff ) ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , unsigned int V_24 ,
T_3 V_12 )
{
F_13 ( V_24 , V_23 -> V_25 ) ;
F_14 ( V_24 , & V_1 , V_26 ) ;
F_15 ( V_24 , V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 , struct V_27 * V_28 ,
const T_2 * V_29 , unsigned int V_30 ,
T_3 * V_31 , unsigned int * V_32 )
{
* V_31 = V_29 [ 0 ] & 0x3f ;
* V_32 = V_16 ;
return 0 ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_18 ( V_34 ) ;
struct V_1 * V_4 = F_19 ( V_34 ) ;
unsigned int V_37 , V_24 ;
V_37 = F_7 ( V_4 -> V_6 + V_38 ) >> 24 ;
if ( V_37 == V_39 )
V_24 = V_40 ;
else
V_24 = F_20 ( V_4 -> V_41 , V_37 ) ;
if ( V_24 != V_40 )
F_21 ( V_24 ) ;
V_36 -> V_42 ( & V_34 -> V_2 ) ;
}
static unsigned int T_4 F_22 ( struct V_1 * V_4 )
{
unsigned int V_24 ;
const T_2 * V_43 , * V_44 ;
int V_45 , V_30 , V_46 ;
struct V_27 * V_47 ;
struct V_27 * V_48 ;
V_48 = F_23 ( V_4 -> V_41 ) ;
V_24 = F_24 ( V_48 , 0 ) ;
if ( V_24 )
return V_24 ;
V_44 = F_25 ( V_48 , L_1 , NULL ) ;
if ( V_44 == NULL )
return V_40 ;
V_30 = * V_44 ;
V_43 = F_25 ( V_48 , L_2 , & V_45 ) ;
if ( V_43 == NULL || V_45 < ( V_30 + 1 ) )
return V_40 ;
V_47 = F_26 ( V_43 [ V_30 ] ) ;
if ( V_47 == NULL )
return V_40 ;
V_43 += V_30 + 1 ;
V_44 = F_25 ( V_47 , L_1 , NULL ) ;
if ( V_44 == NULL ) {
F_27 ( V_47 ) ;
return V_40 ;
}
V_30 = * V_44 ;
V_46 = V_43 [ V_30 - 1 ] ;
V_44 = F_25 ( V_47 , L_3 , NULL ) ;
if ( V_44 == NULL ) {
F_27 ( V_47 ) ;
return V_40 ;
}
V_4 -> V_21 = ( * V_44 ) >> 1 ;
F_27 ( V_47 ) ;
V_24 = F_28 ( NULL ,
( V_4 -> V_21 << V_49 ) |
( 2 << V_50 ) |
V_46 ) ;
if ( V_24 == V_40 )
F_29 ( V_51 L_4 ) ;
return V_24 ;
}
static void T_4 F_30 ( struct V_27 * V_48 , int V_36 ,
unsigned long V_52 )
{
struct V_1 * V_4 = & V_53 [ V_36 ] ;
int V_54 , V_24 ;
V_4 -> V_6 = F_31 ( V_52 , 0x1000 ) ;
if ( V_4 -> V_6 == NULL )
F_32 ( L_5 ) ;
V_4 -> V_41 = F_33 ( V_48 , V_55 ,
& V_56 , V_4 ) ;
if ( V_4 -> V_41 == NULL )
F_32 ( L_6 ) ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
void T_1 * V_8 = V_4 -> V_6 + V_7 + 8 * V_54 ;
F_6 ( V_8 , F_7 ( V_8 ) & ~ 0x30000000u ) ;
}
F_6 ( V_4 -> V_6 + V_57 , 0x0 ) ;
F_6 ( V_4 -> V_6 + V_58 , F_7 ( V_4 -> V_6 + V_58 ) | 0x1 ) ;
V_24 = F_22 ( V_4 ) ;
if ( V_24 == V_40 )
return;
F_34 ( V_24 , V_4 ) ;
F_35 ( V_24 , F_17 ) ;
F_29 ( V_59 L_7 ,
V_4 -> V_21 , V_52 , V_48 -> V_60 ) ;
F_6 ( V_4 -> V_6 + V_61 , F_7 ( V_4 -> V_6 + V_61 ) | 0x1 ) ;
}
void T_4 F_36 ( void )
{
struct V_62 V_63 ;
struct V_27 * V_64 ;
int V_36 = 0 ;
for ( V_64 = NULL ;
( V_64 = F_37 ( V_64 , L_8 ) ) ; ) {
if ( F_38 ( V_64 , L_9 ) ) {
if ( F_39 ( V_64 , 0 , & V_63 ) ) {
F_29 ( V_65 L_10 ) ;
continue;
}
} else if ( F_38 ( V_64 , L_11 )
&& ( V_36 < 2 ) ) {
static long V_66 [] =
{ 0x24000008000ul , 0x34000008000ul } ;
V_63 . V_67 = V_66 [ V_36 ] ;
} else
continue;
F_30 ( V_64 , V_36 ++ , V_63 . V_67 ) ;
}
}
