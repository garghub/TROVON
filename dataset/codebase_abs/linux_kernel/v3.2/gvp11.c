static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_7 = V_6 -> V_8 -> V_9 ;
unsigned long V_10 ;
if ( ! ( V_7 & V_11 ) )
return V_12 ;
F_3 ( V_4 -> V_13 , V_10 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_13 , V_10 ) ;
return V_14 ;
}
void F_6 ( char * V_15 , int * V_16 )
{
V_17 = V_16 [ 1 ] ;
}
static int F_7 ( struct V_18 * V_19 , int V_20 )
{
struct V_3 * V_4 = V_19 -> V_21 -> V_22 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_23 * V_24 = & V_6 -> V_24 ;
struct V_25 * V_8 = V_6 -> V_8 ;
unsigned short V_26 = V_27 ;
unsigned long V_28 = F_8 ( V_19 -> V_29 . V_30 ) ;
int V_31 ;
static int V_32 = 0 ;
if ( V_28 & V_24 -> V_33 ) {
V_24 -> V_34 = ( V_19 -> V_29 . V_35 + 511 ) & ~ 0x1ff ;
if ( ! V_32 ) {
V_24 -> V_36 =
F_9 ( V_24 -> V_34 , V_37 ) ;
V_24 -> V_38 = V_39 ;
}
if ( V_32 ||
! V_24 -> V_36 ) {
V_24 -> V_36 =
F_10 ( V_24 -> V_34 ,
L_1 ) ;
if ( ! V_24 -> V_36 ) {
V_24 -> V_34 = 0 ;
return 1 ;
}
V_24 -> V_38 = V_40 ;
}
V_28 = F_8 ( V_24 -> V_36 ) ;
if ( V_28 & V_24 -> V_33 ) {
if ( V_24 -> V_38 == V_39 ) {
F_11 ( V_24 -> V_36 ) ;
V_32 = 1 ;
} else {
F_12 ( V_24 -> V_36 ) ;
}
V_24 -> V_36 =
F_10 ( V_24 -> V_34 ,
L_1 ) ;
if ( ! V_24 -> V_36 ) {
V_24 -> V_34 = 0 ;
return 1 ;
}
V_28 = F_8 ( V_24 -> V_36 ) ;
V_24 -> V_38 = V_40 ;
}
if ( ! V_20 ) {
memcpy ( V_24 -> V_36 , V_19 -> V_29 . V_30 ,
V_19 -> V_29 . V_35 ) ;
}
}
if ( ! V_20 )
V_26 |= V_41 ;
V_24 -> V_42 = V_20 ;
V_8 -> V_9 = V_26 ;
V_8 -> V_43 = V_28 ;
if ( V_20 ) {
F_13 ( V_28 , V_19 -> V_29 . V_35 ) ;
} else {
F_14 ( V_28 , V_19 -> V_29 . V_35 ) ;
}
V_31 = ( ~ V_24 -> V_33 >> 18 ) & 0x01c0 ;
if ( V_31 )
V_8 -> V_44 = V_31 & ( V_28 >> 18 ) ;
V_8 -> V_45 = 1 ;
return 0 ;
}
static void F_15 ( struct V_3 * V_4 , struct V_18 * V_46 ,
int V_7 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_23 * V_24 = & V_6 -> V_24 ;
struct V_25 * V_8 = V_6 -> V_8 ;
V_8 -> V_47 = 1 ;
V_8 -> V_9 = V_27 ;
if ( V_7 && V_24 -> V_36 ) {
if ( V_24 -> V_42 && V_46 )
memcpy ( V_46 -> V_29 . V_30 , V_24 -> V_36 ,
V_46 -> V_29 . V_35 ) ;
if ( V_24 -> V_38 == V_39 )
F_11 ( V_24 -> V_36 ) ;
else
F_12 ( V_24 -> V_36 ) ;
V_24 -> V_36 = NULL ;
V_24 -> V_34 = 0 ;
}
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_21 -> V_22 ;
F_17 ( V_4 -> V_13 ) ;
F_18 ( V_19 ) ;
F_19 ( V_4 -> V_13 ) ;
return V_48 ;
}
static int T_2 F_20 ( struct V_25 * V_8 )
{
#ifdef F_21
volatile unsigned char * V_49 , * V_50 ;
unsigned char V_51 ;
unsigned char V_52 , V_53 ;
V_49 = & V_8 -> V_54 ;
V_50 = & V_8 -> V_55 ;
V_51 = * V_49 ;
V_52 = * V_49 ;
if ( V_52 & 0x08 )
return - V_56 ;
* V_49 = V_57 ;
if ( * V_49 == V_57 ) {
* V_49 = V_51 ;
return - V_56 ;
}
if ( * V_49 != V_52 ) {
* V_49 = V_51 ;
return - V_56 ;
}
if ( * V_50 != V_52 )
return - V_56 ;
* V_49 = V_58 ;
V_52 = * V_50 ;
* V_49 = V_58 ;
* V_50 = ~ V_52 ;
* V_49 = V_58 ;
V_53 = * V_50 ;
* V_49 = V_58 ;
* V_50 = V_52 ;
if ( V_53 != V_52 )
return - V_56 ;
* V_49 = 0x1e ;
V_52 = * V_50 ;
* V_49 = 0x1e ;
* V_50 = ~ V_52 ;
* V_49 = 0x1e ;
V_53 = * V_50 ;
* V_49 = 0x1e ;
* V_50 = V_52 ;
if ( V_53 != V_52 || V_53 != 0xff )
return - V_56 ;
* V_49 = V_59 ;
V_52 = * V_50 ;
* V_49 = V_59 ;
* V_50 = ~ V_52 ;
* V_49 = V_59 ;
V_53 = * V_50 ;
* V_49 = V_59 ;
* V_50 = V_52 ;
if ( V_53 != ( ~ V_52 & 0xff ) )
return - V_56 ;
#endif
return 0 ;
}
static int T_2 F_22 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_3 * V_4 ;
unsigned long V_64 ;
int error ;
unsigned int V_65 ;
unsigned int V_66 ;
struct V_5 * V_6 ;
struct V_25 * V_8 ;
T_3 V_67 ;
V_66 = V_63 -> V_68 ;
if ( F_23 ( V_61 ) != 0x10000 )
return - V_56 ;
V_64 = V_61 -> V_69 . V_70 ;
if ( ! F_24 ( V_64 , 256 , L_2 ) )
return - V_71 ;
V_8 = (struct V_25 * ) ( F_25 ( V_64 ) ) ;
error = F_20 ( V_8 ) ;
if ( error )
goto V_72;
V_4 = F_26 ( & V_73 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 ) {
error = - V_74 ;
goto V_72;
}
V_4 -> V_1 = V_75 ;
V_4 -> V_76 = V_61 -> V_77 ;
V_8 -> V_78 = 1 ;
V_8 -> V_79 = 0 ;
V_8 -> V_80 = 15 ;
while ( V_8 -> V_9 & V_81 )
;
V_8 -> V_9 = 0 ;
V_8 -> V_44 = 0 ;
V_67 . V_54 = & V_8 -> V_54 ;
V_67 . V_55 = & V_8 -> V_55 ;
V_6 = F_2 ( V_4 ) ;
if ( V_17 )
V_6 -> V_24 . V_33 = V_17 ;
else
V_6 -> V_24 . V_33 = V_66 ;
V_6 -> V_24 . V_82 = 0xff ;
V_6 -> V_24 . V_83 = 0 ;
V_6 -> V_24 . V_84 = V_85 ;
V_6 -> V_8 = V_8 ;
V_65 = * ( unsigned short * ) ( F_25 ( V_64 ) + 0x8000 ) ;
F_27 ( V_4 , V_67 , F_7 , F_15 ,
( V_65 & V_86 ) ? V_87
: V_88 ) ;
error = F_28 ( V_75 , F_1 , V_89 ,
L_3 , V_4 ) ;
if ( error )
goto V_90;
V_8 -> V_9 = V_27 ;
error = F_29 ( V_4 , NULL ) ;
if ( error )
goto V_91;
F_30 ( V_61 , V_4 ) ;
F_31 ( V_4 ) ;
return 0 ;
V_91:
F_32 ( V_75 , V_4 ) ;
V_90:
F_33 ( V_4 ) ;
V_72:
F_34 ( V_64 , 256 ) ;
return error ;
}
static void T_4 F_35 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = F_36 ( V_61 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_8 -> V_9 = 0 ;
F_37 ( V_4 ) ;
F_32 ( V_75 , V_4 ) ;
F_33 ( V_4 ) ;
F_34 ( V_61 -> V_69 . V_70 , 256 ) ;
}
static int T_5 F_38 ( void )
{
return F_39 ( & V_92 ) ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_92 ) ;
}
