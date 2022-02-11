static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int F_3 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_5 ( unsigned V_8 , unsigned V_9 , unsigned V_10 ,
unsigned V_11 , unsigned V_12 ,
struct V_1 * V_2 )
{
if ( V_8 >= 256 )
return - V_13 ;
if ( V_2 -> V_5 . V_14 ) {
V_9 = V_10 = V_11 = ( V_9 * 77 + V_10 * 151 + V_11 * 28 ) >> 8 ;
}
#define F_6 ( T_1 , T_2 ) ((((val)<<(width))+0x7FFF-(val))>>16)
V_9 = F_6 ( V_9 , V_2 -> V_5 . V_9 . V_15 ) ;
V_10 = F_6 ( V_10 , V_2 -> V_5 . V_10 . V_15 ) ;
V_11 = F_6 ( V_11 , V_2 -> V_5 . V_11 . V_15 ) ;
V_12 = F_6 ( V_12 , V_2 -> V_5 . V_12 . V_15 ) ;
#undef F_6
if ( V_2 -> V_16 . V_17 == V_18 ||
V_2 -> V_16 . V_17 == V_19 )
F_7 { V_9 | V_10 | V_11 | V_12 } F_8 () ;
if ( V_2 -> V_16 . V_17 == V_19 ||
V_2 -> V_16 . V_17 == V_18 ) {
T_3 V_20 ;
if ( V_8 >= 16 )
return - V_13 ;
V_20 = ( V_9 << V_2 -> V_5 . V_9 . V_21 ) |
( V_10 << V_2 -> V_5 . V_10 . V_21 ) |
( V_11 << V_2 -> V_5 . V_11 . V_21 ) |
( V_12 << V_2 -> V_5 . V_12 . V_21 ) ;
( ( T_3 * ) ( V_2 -> V_22 ) ) [ V_8 ] = V_20 ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( int V_23 , struct V_1 * V_2 )
{
return 0 ;
}
void F_11 ( struct V_1 * V_24 , const struct V_25 * V_26 )
{
}
void F_12 ( struct V_1 * V_24 , const struct V_27 * V_28 )
{
}
void F_13 ( struct V_1 * V_24 , const struct V_29 * V_30 )
{
}
int F_14 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
}
void F_15 ( struct V_1 * V_2 , int V_33 )
{
}
int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_17 ( struct V_34 * V_35 , const struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_38 * V_38 = & V_35 -> V_35 ;
int V_39 , V_40 ;
V_2 = F_18 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_2 ) {
}
V_7 = V_2 -> V_7 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = & V_44 ;
V_2 -> V_16 = V_45 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 . V_49 = F_19 ( V_50 , V_51 ) ;
if ( ! V_2 -> V_48 . V_49 ) {
}
V_2 -> V_48 . V_52 = V_50 ;
V_2 -> V_48 . V_46 = V_53 ;
V_2 -> V_48 . V_54 = 4 ;
V_2 -> V_48 . V_55 = 4 ;
V_2 -> V_48 . V_56 = 32 ;
if ( ! V_57 )
V_57 = L_1 ;
V_40 = F_20 ( & V_2 -> V_5 , V_2 , V_57 , NULL , 0 , NULL , 8 ) ;
if ( ! V_40 || V_40 == 4 )
return - V_13 ;
if ( F_21 ( & V_2 -> V_58 , V_39 , 0 ) )
return - V_59 ;
V_2 -> V_5 = V_60 ;
F_3 ( & V_2 -> V_5 , V_2 ) ;
if ( F_22 ( V_2 ) < 0 ) {
F_23 ( & V_2 -> V_58 ) ;
return - V_13 ;
}
F_24 ( V_61 L_2 , V_2 -> V_62 ,
V_2 -> V_16 . V_63 ) ;
F_25 ( V_35 , V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_27 ( V_35 ) ;
if ( V_2 ) {
F_28 ( V_2 ) ;
F_23 ( & V_2 -> V_58 ) ;
F_29 ( V_2 ) ;
}
}
static int F_30 ( struct V_34 * V_35 , T_4 V_64 )
{
struct V_1 * V_2 = F_27 ( V_35 ) ;
struct V_65 * V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_31 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_27 ( V_35 ) ;
struct V_65 * V_7 = V_2 -> V_7 ;
return 0 ;
}
int T_5 F_32 ( void )
{
#ifndef F_33
char * V_66 = NULL ;
if ( F_34 ( L_3 , & V_66 ) )
return - V_67 ;
F_35 ( V_66 ) ;
#endif
return F_36 ( & V_68 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_68 ) ;
}
static int F_30 ( struct V_69 * V_35 , T_4 V_64 )
{
struct V_1 * V_2 = F_39 ( V_35 ) ;
struct V_65 * V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_31 ( struct V_70 * V_35 )
{
struct V_1 * V_2 = F_39 ( V_35 ) ;
struct V_65 * V_7 = V_2 -> V_7 ;
return 0 ;
}
int T_5 F_35 ( char * V_71 )
{
}
static int T_5 F_32 ( void )
{
int V_72 ;
#ifndef F_33
char * V_66 = NULL ;
if ( F_34 ( L_3 , & V_66 ) )
return - V_67 ;
F_35 ( V_66 ) ;
#endif
V_72 = F_40 ( & V_68 ) ;
if ( ! V_72 ) {
V_73 = F_41 ( L_3 , 0 ,
NULL , 0 ) ;
if ( F_42 ( V_73 ) ) {
F_43 ( & V_68 ) ;
V_72 = F_44 ( V_73 ) ;
}
}
return V_72 ;
}
static void T_6 F_37 ( void )
{
F_45 ( V_73 ) ;
F_43 ( & V_68 ) ;
}
