static void F_1 ( int V_1 , unsigned int V_2 , int V_3 )
{
while ( V_1 -- ) {
if ( V_2 & 1 ) {
F_2 ( 5 , V_3 ) ;
F_3 ( 6 ) ;
F_2 ( 7 , V_3 ) ;
F_3 ( 6 ) ;
} else {
F_2 ( 1 , V_3 ) ;
F_3 ( 6 ) ;
F_2 ( 3 , V_3 ) ;
F_3 ( 6 ) ;
}
V_2 >>= 1 ;
}
}
static inline void F_4 ( struct V_4 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
F_2 ( 0x00 , V_4 -> V_3 ) ;
F_6 ( & V_4 -> V_5 ) ;
}
static inline void F_7 ( struct V_4 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
F_2 ( 0x08 , V_4 -> V_3 ) ;
F_6 ( & V_4 -> V_5 ) ;
}
static inline int F_8 ( struct V_4 * V_4 , unsigned long V_6 )
{
F_5 ( & V_4 -> V_5 ) ;
V_4 -> V_7 = V_6 ;
F_1 ( 16 , F_9 ( V_6 ) , V_4 -> V_3 ) ;
F_1 ( 8 , 0xC0 , V_4 -> V_3 ) ;
F_10 ( 143 ) ;
F_6 ( & V_4 -> V_5 ) ;
if ( ! V_4 -> V_8 )
F_7 ( V_4 ) ;
return 0 ;
}
static inline int F_11 ( struct V_4 * V_4 )
{
int V_9 ;
int V_10 ;
F_5 ( & V_4 -> V_5 ) ;
V_9 = V_4 -> V_8 ? 0x00 : 0x08 ;
F_2 ( V_9 , V_4 -> V_3 ) ;
F_2 ( V_9 | 0x10 , V_4 -> V_3 ) ;
F_10 ( 143 ) ;
V_10 = ( int ) F_12 ( V_4 -> V_3 + 1 ) ;
F_2 ( V_9 , V_4 -> V_3 ) ;
F_6 ( & V_4 -> V_5 ) ;
return ( V_10 & 2 ) ? 0 : 0xFFFF ;
}
static int F_13 ( struct V_11 * V_11 , void * V_12 ,
struct V_13 * V_14 )
{
F_14 ( V_14 -> V_15 , L_1 , sizeof( V_14 -> V_15 ) ) ;
F_14 ( V_14 -> V_16 , L_2 , sizeof( V_14 -> V_16 ) ) ;
F_14 ( V_14 -> V_17 , L_3 , sizeof( V_14 -> V_17 ) ) ;
V_14 -> V_18 = V_19 | V_20 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_11 , void * V_12 ,
struct V_21 * V_14 )
{
struct V_4 * V_4 = F_16 ( V_11 ) ;
if ( V_14 -> V_22 > 0 )
return - V_23 ;
F_14 ( V_14 -> V_24 , L_4 , sizeof( V_14 -> V_24 ) ) ;
V_14 -> type = V_25 ;
V_14 -> V_26 = V_27 ;
V_14 -> V_28 = V_29 ;
V_14 -> V_30 = V_31 | V_32 ;
V_14 -> V_33 = V_34 | V_35 ;
V_14 -> V_36 = V_37 ;
V_14 -> signal = F_11 ( V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_11 , void * V_12 ,
struct V_21 * V_14 )
{
return V_14 -> V_22 ? - V_23 : 0 ;
}
static int F_18 ( struct V_11 * V_11 , void * V_12 ,
struct V_38 * V_39 )
{
struct V_4 * V_4 = F_16 ( V_11 ) ;
if ( V_39 -> V_40 != 0 || V_39 -> type != V_25 )
return - V_23 ;
if ( V_39 -> V_41 < V_27 ||
V_39 -> V_41 > V_29 )
return - V_23 ;
F_8 ( V_4 , ( V_39 -> V_41 / 800 ) * 800 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_11 , void * V_12 ,
struct V_38 * V_39 )
{
struct V_4 * V_4 = F_16 ( V_11 ) ;
if ( V_39 -> V_40 != 0 )
return - V_23 ;
V_39 -> type = V_25 ;
V_39 -> V_41 = V_4 -> V_7 ;
return 0 ;
}
static int F_20 ( struct V_11 * V_11 , void * V_12 ,
struct V_42 * V_43 )
{
switch ( V_43 -> V_44 ) {
case V_45 :
return F_21 ( V_43 , 0 , 1 , 1 , 1 ) ;
}
return - V_23 ;
}
static int F_22 ( struct V_11 * V_11 , void * V_12 ,
struct V_46 * V_47 )
{
struct V_4 * V_4 = F_16 ( V_11 ) ;
switch ( V_47 -> V_44 ) {
case V_45 :
V_47 -> V_48 = V_4 -> V_8 ;
return 0 ;
}
return - V_23 ;
}
static int F_23 ( struct V_11 * V_11 , void * V_12 ,
struct V_46 * V_47 )
{
struct V_4 * V_4 = F_16 ( V_11 ) ;
switch ( V_47 -> V_44 ) {
case V_45 :
if ( V_47 -> V_48 )
F_4 ( V_4 ) ;
else
F_7 ( V_4 ) ;
V_4 -> V_8 = V_47 -> V_48 ;
return 0 ;
}
return - V_23 ;
}
static int F_24 ( struct V_11 * V_49 , void * V_12 , unsigned int * V_50 )
{
* V_50 = 0 ;
return 0 ;
}
static int F_25 ( struct V_11 * V_49 , void * V_12 , unsigned int V_50 )
{
return V_50 ? - V_23 : 0 ;
}
static int F_26 ( struct V_11 * V_11 , void * V_12 ,
struct V_51 * V_52 )
{
V_52 -> V_22 = 0 ;
F_14 ( V_52 -> V_24 , L_5 , sizeof( V_52 -> V_24 ) ) ;
V_52 -> V_33 = V_53 ;
return 0 ;
}
static int F_27 ( struct V_11 * V_11 , void * V_12 ,
struct V_51 * V_52 )
{
return V_52 -> V_22 ? - V_23 : 0 ;
}
static int T_1 F_28 ( void )
{
int V_50 = 0 ;
while ( V_54 [ V_50 ] . V_55 != 0 && V_56 == NULL ) {
V_56 = F_29 ( NULL , V_54 [ V_50 ] . V_57 ,
V_54 [ V_50 ] . V_58 , NULL ) ;
V_50 ++ ;
}
if ( ! V_56 )
return - V_59 ;
if ( F_30 ( V_56 ) < 0 )
return - V_60 ;
if ( F_31 ( V_56 ) < 0 ) {
F_32 ( V_61 L_6 ) ;
F_33 ( V_56 ) ;
return - V_62 ;
}
if ( ! F_34 ( V_56 , 0 ) ) {
F_33 ( V_56 ) ;
return - V_59 ;
}
V_50 = F_35 ( V_56 , 0 ) ;
F_32 ( V_63 L_7 , V_50 ) ;
return V_50 ;
}
static int T_1 F_36 ( void )
{
struct V_4 * V_4 = & V_64 ;
struct V_65 * V_66 = & V_4 -> V_66 ;
int V_10 , V_50 ;
int V_67 [] = { 0 , 0x284 , 0x384 } ;
if ( V_3 < 0 ) {
for ( V_50 = 0 ; V_50 < F_37 ( V_67 ) ; V_50 ++ ) {
V_3 = V_67 [ V_50 ] ;
if ( V_3 == 0 ) {
V_3 = F_28 () ;
if ( V_3 < 0 )
continue;
V_68 = 1 ;
}
if ( ! F_38 ( V_3 , 2 , L_1 ) ) {
if ( V_68 )
F_33 ( V_56 ) ;
V_3 = - 1 ;
continue;
}
if ( V_68 ||
( ( F_12 ( V_3 ) & 0xf9 ) == 0xf9 && ( F_12 ( V_3 ) & 0x4 ) == 0 ) )
break;
F_39 ( V_3 , 2 ) ;
V_3 = - 1 ;
}
} else {
if ( ! F_38 ( V_3 , 2 , L_1 ) ) {
F_32 ( V_61 L_8 , V_3 ) ;
return - V_69 ;
}
if ( F_12 ( V_3 ) == 0xff ) {
F_32 ( V_61 L_9 , V_3 ) ;
F_39 ( V_3 , 2 ) ;
return - V_59 ;
}
}
if ( V_3 < 0 ) {
F_32 ( V_61 L_10 ) ;
return - V_59 ;
}
F_14 ( V_66 -> V_24 , L_11 , sizeof( V_66 -> V_24 ) ) ;
V_4 -> V_3 = V_3 ;
V_10 = F_40 ( NULL , V_66 ) ;
if ( V_10 < 0 ) {
F_39 ( V_4 -> V_3 , 2 ) ;
if ( V_68 )
F_33 ( V_56 ) ;
F_41 ( V_66 , L_12 ) ;
return V_10 ;
}
F_14 ( V_4 -> V_70 . V_24 , V_66 -> V_24 , sizeof( V_4 -> V_70 . V_24 ) ) ;
V_4 -> V_70 . V_66 = V_66 ;
V_4 -> V_70 . V_71 = & V_72 ;
V_4 -> V_70 . V_73 = & V_74 ;
V_4 -> V_70 . V_75 = V_76 ;
F_42 ( & V_4 -> V_70 , V_4 ) ;
F_43 ( & V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
if ( F_44 ( & V_4 -> V_70 , V_77 , V_78 ) < 0 ) {
F_45 ( V_66 ) ;
F_39 ( V_4 -> V_3 , 2 ) ;
if ( V_68 )
F_33 ( V_56 ) ;
return - V_23 ;
}
F_46 ( V_66 , L_13 , V_4 -> V_3 ) ;
return 0 ;
}
static void T_2 F_47 ( void )
{
struct V_4 * V_4 = & V_64 ;
F_48 ( & V_4 -> V_70 ) ;
F_45 ( & V_4 -> V_66 ) ;
F_39 ( V_4 -> V_3 , 2 ) ;
if ( V_56 && V_68 )
F_33 ( V_56 ) ;
}
