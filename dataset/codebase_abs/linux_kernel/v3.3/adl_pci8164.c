static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
F_2 ( V_11 L_1 ) ;
F_2 ( V_11 L_2 , V_2 -> V_12 ) ;
V_2 -> V_13 = L_3 ;
V_9 = V_4 -> V_14 [ 0 ] ;
V_10 = V_4 -> V_14 [ 1 ] ;
if ( F_3 ( V_2 , sizeof( struct V_15 ) ) < 0 )
return - V_16 ;
if ( F_4 ( V_2 , 4 ) < 0 )
return - V_16 ;
F_5 (pcidev) {
if ( V_6 -> V_17 == V_18 &&
V_6 -> V_19 == V_20 ) {
if ( V_9 || V_10 ) {
if ( V_6 -> V_9 -> V_21 != V_9
|| F_6 ( V_6 -> V_22 ) != V_10 )
continue;
}
V_23 -> V_5 = V_6 ;
if ( F_7 ( V_6 , L_4 ) < 0 ) {
F_2 ( V_24 L_5
L_6 , V_2 -> V_12 ) ;
return - V_25 ;
}
V_2 -> V_26 = F_8 ( V_6 , 2 ) ;
F_2 ( V_27 L_7 ,
V_2 -> V_26 ) ;
V_8 = V_2 -> V_28 + 0 ;
V_8 -> type = V_29 ;
V_8 -> V_30 = V_31 | V_32 ;
V_8 -> V_33 = 4 ;
V_8 -> V_34 = 0xffff ;
V_8 -> V_35 = 4 ;
V_8 -> V_36 = V_37 ;
V_8 -> V_38 = V_39 ;
V_8 = V_2 -> V_28 + 1 ;
V_8 -> type = V_29 ;
V_8 -> V_30 = V_31 | V_32 ;
V_8 -> V_33 = 4 ;
V_8 -> V_34 = 0xffff ;
V_8 -> V_35 = 4 ;
V_8 -> V_36 = V_40 ;
V_8 -> V_38 = V_41 ;
V_8 = V_2 -> V_28 + 2 ;
V_8 -> type = V_29 ;
V_8 -> V_30 = V_31 | V_32 ;
V_8 -> V_33 = 4 ;
V_8 -> V_34 = 0xffff ;
V_8 -> V_35 = 4 ;
V_8 -> V_36 = V_42 ;
V_8 -> V_38 = V_43 ;
V_8 = V_2 -> V_28 + 3 ;
V_8 -> type = V_29 ;
V_8 -> V_30 = V_31 | V_32 ;
V_8 -> V_33 = 4 ;
V_8 -> V_34 = 0xffff ;
V_8 -> V_35 = 4 ;
V_8 -> V_36 = V_44 ;
V_8 -> V_38 = V_45 ;
F_2 ( V_11 L_8 ) ;
return 1 ;
}
}
F_2 ( V_24 L_9
L_10 , V_2 -> V_12 , V_9 , V_10 ) ;
return - V_25 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_2 ( V_11 L_11 , V_2 -> V_12 ) ;
if ( V_23 && V_23 -> V_5 ) {
if ( V_2 -> V_26 )
F_10 ( V_23 -> V_5 ) ;
F_11 ( V_23 -> V_5 ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 ,
char * V_49 , unsigned short V_50 )
{
int V_51 , V_52 ;
char * V_53 ;
V_51 = F_13 ( V_47 -> V_54 ) ;
switch ( V_51 ) {
case 0 :
V_52 = V_55 ;
V_53 = L_12 ;
break;
case 1 :
V_52 = V_56 ;
V_53 = L_13 ;
break;
case 2 :
V_52 = V_57 ;
V_53 = L_14 ;
break;
case 3 :
V_52 = V_58 ;
V_53 = L_15 ;
break;
default:
V_52 = V_55 ;
V_53 = L_12 ;
}
V_48 [ 0 ] = F_14 ( V_2 -> V_26 + V_52 + V_50 ) ;
F_2 ( V_27 L_16
L_17 ,
V_49 , V_48 [ 0 ] , V_48 [ 1 ] , V_53 ) ;
}
static int V_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_12 ( V_2 , V_8 , V_47 , V_48 , L_18 , V_59 ) ;
return 2 ;
}
static int V_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_12 ( V_2 , V_8 , V_47 , V_48 , L_19 , V_60 ) ;
return 2 ;
}
static int V_42 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_12 ( V_2 , V_8 , V_47 , V_48 , L_20 , V_61 ) ;
return 2 ;
}
static int V_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_12 ( V_2 , V_8 , V_47 , V_48 , L_21 , V_62 ) ;
return 2 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 ,
char * V_49 , unsigned short V_50 )
{
unsigned int V_51 , V_52 ;
char * V_53 ;
V_51 = F_13 ( V_47 -> V_54 ) ;
switch ( V_51 ) {
case 0 :
V_52 = V_55 ;
V_53 = L_12 ;
break;
case 1 :
V_52 = V_56 ;
V_53 = L_13 ;
break;
case 2 :
V_52 = V_57 ;
V_53 = L_14 ;
break;
case 3 :
V_52 = V_58 ;
V_53 = L_15 ;
break;
default:
V_52 = V_55 ;
V_53 = L_12 ;
}
F_16 ( V_48 [ 0 ] , V_2 -> V_26 + V_52 + V_50 ) ;
F_2 ( V_27 L_22
L_17 ,
V_49 , V_48 [ 0 ] , V_48 [ 1 ] , V_53 ) ;
}
static int V_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_15 ( V_2 , V_8 , V_47 , V_48 , L_23 , V_63 ) ;
return 2 ;
}
static int V_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_15 ( V_2 , V_8 , V_47 , V_48 , L_24 , V_64 ) ;
return 2 ;
}
static int V_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_15 ( V_2 , V_8 , V_47 , V_48 , L_20 , V_61 ) ;
return 2 ;
}
static int V_45 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
F_15 ( V_2 , V_8 , V_47 , V_48 , L_21 , V_62 ) ;
return 2 ;
}
static int T_1 F_17 ( struct V_5 * V_2 ,
const struct V_65
* V_66 )
{
return F_18 ( V_2 , V_67 . V_68 ) ;
}
static void T_2 F_19 ( struct V_5 * V_2 )
{
F_20 ( V_2 ) ;
}
static int T_3 F_21 ( void )
{
int V_69 ;
V_69 = F_22 ( & V_67 ) ;
if ( V_69 < 0 )
return V_69 ;
V_70 . V_71 =
( char * ) V_67 . V_68 ;
return F_23 ( & V_70 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_70 ) ;
F_26 ( & V_67 ) ;
}
