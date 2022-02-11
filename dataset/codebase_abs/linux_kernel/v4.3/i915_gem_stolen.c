int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 ,
unsigned V_6 )
{
int V_7 ;
if ( ! F_2 ( & V_2 -> V_8 . V_9 ) )
return - V_10 ;
F_3 ( & V_2 -> V_8 . V_11 ) ;
V_7 = F_4 ( & V_2 -> V_8 . V_9 , V_4 , V_5 , V_6 ,
V_12 ) ;
F_5 ( & V_2 -> V_8 . V_11 ) ;
return V_7 ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( & V_2 -> V_8 . V_11 ) ;
F_7 ( V_4 ) ;
F_5 ( & V_2 -> V_8 . V_11 ) ;
}
static unsigned long F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_16 * V_17 ;
T_2 V_18 ;
V_18 = 0 ;
if ( F_9 ( V_14 ) -> V_19 >= 3 ) {
F_10 ( V_14 -> V_20 , 0x5c , & V_18 ) ;
V_18 &= ~ ( ( 1 << 20 ) - 1 ) ;
} else {
#if 0
base = max_low_pfn_mapped << PAGE_SHIFT;
#endif
}
if ( V_18 == 0 )
return 0 ;
if ( F_9 ( V_14 ) -> V_19 <= 4 && ! F_11 ( V_14 ) && ! F_12 ( V_14 ) ) {
struct {
T_2 V_21 , V_22 ;
} V_9 [ 2 ] = {
{ . V_21 = V_18 , . V_22 = V_18 + V_2 -> V_23 . V_24 , } ,
{ . V_21 = V_18 , . V_22 = V_18 + V_2 -> V_23 . V_24 , } ,
} ;
T_1 V_25 , V_26 ;
V_25 = F_13 ( V_27 ) ;
if ( F_14 ( V_14 ) )
V_25 = ( V_25 & V_28 ) |
( V_25 & V_29 ) << 28 ;
else
V_25 &= V_28 ;
V_26 = V_25 + F_15 ( V_2 -> V_23 ) * 4 ;
if ( V_25 >= V_9 [ 0 ] . V_21 && V_25 < V_9 [ 0 ] . V_22 )
V_9 [ 0 ] . V_22 = V_25 ;
if ( V_26 > V_9 [ 1 ] . V_21 && V_26 <= V_9 [ 1 ] . V_22 )
V_9 [ 1 ] . V_21 = V_26 ;
if ( V_9 [ 0 ] . V_22 - V_9 [ 0 ] . V_21 >
V_9 [ 1 ] . V_22 - V_9 [ 1 ] . V_21 ) {
V_18 = V_9 [ 0 ] . V_21 ;
V_2 -> V_23 . V_24 = V_9 [ 0 ] . V_22 - V_9 [ 0 ] . V_21 ;
} else {
V_18 = V_9 [ 1 ] . V_21 ;
V_2 -> V_23 . V_24 = V_9 [ 1 ] . V_22 - V_9 [ 1 ] . V_21 ;
}
if ( V_9 [ 0 ] . V_21 != V_9 [ 1 ] . V_21 ||
V_9 [ 0 ] . V_22 != V_9 [ 1 ] . V_22 ) {
F_16 ( L_1 ,
( unsigned long long ) V_25 ,
( unsigned long long ) V_26 - 1 ) ;
F_16 ( L_2 ,
V_18 , V_18 + ( T_2 ) V_2 -> V_23 . V_24 - 1 ) ;
}
}
V_17 = F_17 ( V_14 -> V_14 , V_18 , V_2 -> V_23 . V_24 ,
L_3 ) ;
if ( V_17 == NULL ) {
V_17 = F_17 ( V_14 -> V_14 , V_18 + 1 ,
V_2 -> V_23 . V_24 - 1 ,
L_3 ) ;
if ( V_17 == NULL && ! F_18 ( V_14 ) ) {
F_19 ( L_4 ,
V_18 , V_18 + ( V_30 ) V_2 -> V_23 . V_24 ) ;
V_18 = 0 ;
}
}
return V_18 ;
}
void F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
if ( ! F_2 ( & V_2 -> V_8 . V_9 ) )
return;
F_21 ( & V_2 -> V_8 . V_9 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned long * V_18 , unsigned long * V_5 )
{
V_30 V_31 = F_13 ( V_32 ) ;
* V_18 = V_31 & V_33 ;
switch ( V_31 & V_34 ) {
case V_35 :
* V_5 = 1024 * 1024 ;
break;
case V_36 :
* V_5 = 512 * 1024 ;
break;
case V_37 :
* V_5 = 256 * 1024 ;
break;
case V_38 :
* V_5 = 128 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_23 ( V_31 & V_34 ) ;
}
}
static void F_24 ( struct V_1 * V_2 ,
unsigned long * V_18 , unsigned long * V_5 )
{
V_30 V_31 = F_13 ( V_32 ) ;
* V_18 = V_31 & V_39 ;
switch ( V_31 & V_40 ) {
case V_41 :
* V_5 = 1024 * 1024 ;
break;
case V_42 :
* V_5 = 256 * 1024 ;
break;
default:
* V_5 = 1024 * 1024 ;
F_23 ( V_31 & V_40 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
unsigned long * V_18 , unsigned long * V_5 )
{
V_30 V_31 = F_13 ( V_32 ) ;
* V_18 = V_31 & V_33 ;
switch ( V_31 & V_43 ) {
case V_44 :
* V_5 = 1024 * 1024 ;
break;
case V_45 :
* V_5 = 2 * 1024 * 1024 ;
break;
case V_46 :
* V_5 = 4 * 1024 * 1024 ;
break;
case V_47 :
* V_5 = 8 * 1024 * 1024 ;
break;
default:
* V_5 = 8 * 1024 * 1024 ;
F_23 ( V_31 & V_43 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
unsigned long * V_18 , unsigned long * V_5 )
{
V_30 V_31 = F_13 ( V_32 ) ;
unsigned long V_48 ;
V_48 = V_2 -> V_8 . V_49 + V_2 -> V_23 . V_24 ;
* V_18 = V_31 & V_33 ;
if ( * V_18 == 0 )
* V_5 = 0 ;
else
* V_5 = V_48 - * V_18 ;
}
int F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_50 , V_51 , V_52 ;
unsigned long V_48 ;
F_28 ( & V_2 -> V_8 . V_11 ) ;
#ifdef F_29
if ( V_53 && F_9 ( V_14 ) -> V_19 < 8 ) {
F_30 ( L_5 ) ;
return 0 ;
}
#endif
if ( V_2 -> V_23 . V_24 == 0 )
return 0 ;
V_2 -> V_8 . V_49 = F_8 ( V_14 ) ;
if ( V_2 -> V_8 . V_49 == 0 )
return 0 ;
V_48 = V_2 -> V_8 . V_49 + V_2 -> V_23 . V_24 ;
switch ( F_9 ( V_2 ) -> V_19 ) {
case 2 :
case 3 :
case 4 :
case 5 :
V_52 = 1024 * 1024 ;
V_51 = V_48 - V_52 ;
break;
case 6 :
F_22 ( V_2 , & V_51 ,
& V_52 ) ;
break;
case 7 :
F_24 ( V_2 , & V_51 ,
& V_52 ) ;
break;
default:
if ( F_31 ( V_2 ) || F_32 ( V_2 ) )
F_26 ( V_2 , & V_51 ,
& V_52 ) ;
else
F_25 ( V_2 , & V_51 ,
& V_52 ) ;
break;
}
if ( V_51 == 0 ) {
V_52 = 0 ;
V_51 = V_48 ;
}
if ( V_51 < V_2 -> V_8 . V_49 ||
V_51 + V_52 > V_48 ) {
F_16 ( L_6 ,
V_51 , V_51 + V_52 ,
V_2 -> V_8 . V_49 , V_48 ) ;
return 0 ;
}
V_50 = V_48 - V_51 ;
F_16 ( L_7 ,
V_2 -> V_23 . V_24 >> 10 ,
( V_2 -> V_23 . V_24 - V_50 ) >> 10 ) ;
F_33 ( & V_2 -> V_8 . V_9 , 0 , V_2 -> V_23 . V_24 -
V_50 ) ;
return 0 ;
}
static struct V_54 *
F_34 ( struct V_13 * V_14 ,
T_2 V_55 , T_2 V_5 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_54 * V_56 ;
struct V_57 * V_58 ;
F_35 ( L_8 , V_55 , V_5 ) ;
F_36 ( V_55 > V_2 -> V_23 . V_24 - V_5 ) ;
V_56 = F_37 ( sizeof( * V_56 ) , V_59 ) ;
if ( V_56 == NULL )
return NULL ;
if ( F_38 ( V_56 , 1 , V_59 ) ) {
F_39 ( V_56 ) ;
return NULL ;
}
V_58 = V_56 -> V_60 ;
V_58 -> V_55 = 0 ;
V_58 -> V_61 = V_5 ;
F_40 ( V_58 ) = ( V_62 ) V_2 -> V_8 . V_49 + V_55 ;
F_41 ( V_58 ) = V_5 ;
return V_56 ;
}
static int F_42 ( struct V_63 * V_64 )
{
F_43 () ;
return - V_65 ;
}
static void F_44 ( struct V_63 * V_64 )
{
F_45 ( V_64 -> V_66 ) ;
F_39 ( V_64 -> V_66 ) ;
}
static void
F_46 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_18 . V_14 -> V_15 ;
if ( V_64 -> V_9 ) {
F_6 ( V_2 , V_64 -> V_9 ) ;
F_39 ( V_64 -> V_9 ) ;
V_64 -> V_9 = NULL ;
}
}
static struct V_63 *
F_47 ( struct V_13 * V_14 ,
struct V_3 * V_9 )
{
struct V_63 * V_64 ;
V_64 = F_48 ( V_14 ) ;
if ( V_64 == NULL )
return NULL ;
F_49 ( V_14 , & V_64 -> V_18 , V_9 -> V_5 ) ;
F_50 ( V_64 , & V_67 ) ;
V_64 -> V_66 = F_34 ( V_14 ,
V_9 -> V_21 , V_9 -> V_5 ) ;
if ( V_64 -> V_66 == NULL )
goto V_68;
F_51 ( V_64 ) ;
V_64 -> V_9 = V_9 ;
V_64 -> V_18 . V_69 = V_70 | V_71 ;
V_64 -> V_72 = F_52 ( V_14 ) ? V_73 : V_74 ;
return V_64 ;
V_68:
F_53 ( V_64 ) ;
return NULL ;
}
struct V_63 *
F_54 ( struct V_13 * V_14 , T_2 V_5 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_63 * V_64 ;
struct V_3 * V_9 ;
int V_7 ;
if ( ! F_2 ( & V_2 -> V_8 . V_9 ) )
return NULL ;
F_16 ( L_9 , V_5 ) ;
if ( V_5 == 0 )
return NULL ;
V_9 = F_55 ( sizeof( * V_9 ) , V_59 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_1 ( V_2 , V_9 , V_5 , 4096 ) ;
if ( V_7 ) {
F_39 ( V_9 ) ;
return NULL ;
}
V_64 = F_47 ( V_14 , V_9 ) ;
if ( V_64 )
return V_64 ;
F_6 ( V_2 , V_9 ) ;
F_39 ( V_9 ) ;
return NULL ;
}
struct V_63 *
F_56 ( struct V_13 * V_14 ,
T_2 V_75 ,
T_2 V_76 ,
T_2 V_5 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_77 * V_78 = & V_2 -> V_23 . V_18 ;
struct V_63 * V_64 ;
struct V_3 * V_9 ;
struct V_79 * V_80 ;
int V_7 ;
if ( ! F_2 ( & V_2 -> V_8 . V_9 ) )
return NULL ;
F_16 ( L_10 ,
V_75 , V_76 , V_5 ) ;
if ( F_57 ( V_5 == 0 ) || F_57 ( V_5 & 4095 ) ||
F_57 ( V_75 & 4095 ) )
return NULL ;
V_9 = F_55 ( sizeof( * V_9 ) , V_59 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_21 = V_75 ;
V_9 -> V_5 = V_5 ;
F_3 ( & V_2 -> V_8 . V_11 ) ;
V_7 = F_58 ( & V_2 -> V_8 . V_9 , V_9 ) ;
F_5 ( & V_2 -> V_8 . V_11 ) ;
if ( V_7 ) {
F_16 ( L_11 ) ;
F_39 ( V_9 ) ;
return NULL ;
}
V_64 = F_47 ( V_14 , V_9 ) ;
if ( V_64 == NULL ) {
F_16 ( L_12 ) ;
F_6 ( V_2 , V_9 ) ;
F_39 ( V_9 ) ;
return NULL ;
}
if ( V_76 == V_81 )
return V_64 ;
V_80 = F_59 ( V_64 , V_78 ) ;
if ( F_60 ( V_80 ) ) {
V_7 = F_61 ( V_80 ) ;
goto V_82;
}
V_80 -> V_4 . V_21 = V_76 ;
V_80 -> V_4 . V_5 = V_5 ;
if ( F_2 ( & V_78 -> V_8 ) ) {
V_7 = F_58 ( & V_78 -> V_8 , & V_80 -> V_4 ) ;
if ( V_7 ) {
F_16 ( L_13 ) ;
goto V_83;
}
}
V_80 -> V_84 |= V_85 ;
F_62 ( & V_64 -> V_86 , & V_2 -> V_8 . V_87 ) ;
F_62 ( & V_80 -> V_88 , & V_78 -> V_89 ) ;
F_51 ( V_64 ) ;
return V_64 ;
V_83:
F_63 ( V_80 ) ;
V_82:
F_6 ( V_2 , V_9 ) ;
F_39 ( V_9 ) ;
F_64 ( & V_64 -> V_18 ) ;
return NULL ;
}
