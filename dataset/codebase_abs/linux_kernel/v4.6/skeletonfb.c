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
int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_33 * V_34 , const struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_37 * V_37 = & V_34 -> V_34 ;
int V_38 , V_39 ;
V_2 = F_17 ( sizeof( struct V_6 ) , V_37 ) ;
if ( ! V_2 ) {
}
V_7 = V_2 -> V_7 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = & V_43 ;
V_2 -> V_16 = V_44 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 . V_48 = F_18 ( V_49 , V_50 ) ;
if ( ! V_2 -> V_47 . V_48 ) {
}
V_2 -> V_47 . V_51 = V_49 ;
V_2 -> V_47 . V_45 = V_52 ;
V_2 -> V_47 . V_53 = 4 ;
V_2 -> V_47 . V_54 = 4 ;
V_2 -> V_47 . V_55 = 32 ;
if ( ! V_56 )
V_56 = L_1 ;
V_39 = F_19 ( & V_2 -> V_5 , V_2 , V_56 , NULL , 0 , NULL , 8 ) ;
if ( ! V_39 || V_39 == 4 )
return - V_13 ;
if ( F_20 ( & V_2 -> V_57 , V_38 , 0 ) )
return - V_58 ;
V_2 -> V_5 = V_59 ;
F_3 ( & V_2 -> V_5 , V_2 ) ;
if ( F_21 ( V_2 ) < 0 ) {
F_22 ( & V_2 -> V_57 ) ;
return - V_13 ;
}
V_1 ( V_2 , L_2 , V_2 -> V_16 . V_60 ) ;
F_23 ( V_34 , V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_25 ( V_34 ) ;
if ( V_2 ) {
F_26 ( V_2 ) ;
F_22 ( & V_2 -> V_57 ) ;
F_27 ( V_2 ) ;
}
}
static int F_28 ( struct V_33 * V_34 , T_4 V_61 )
{
struct V_1 * V_2 = F_25 ( V_34 ) ;
struct V_62 * V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_25 ( V_34 ) ;
struct V_62 * V_7 = V_2 -> V_7 ;
return 0 ;
}
int T_5 F_30 ( void )
{
#ifndef F_31
char * V_63 = NULL ;
if ( F_32 ( L_3 , & V_63 ) )
return - V_64 ;
F_33 ( V_63 ) ;
#endif
return F_34 ( & V_65 ) ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_65 ) ;
}
static int F_28 ( struct V_66 * V_34 , T_4 V_61 )
{
struct V_1 * V_2 = F_37 ( V_34 ) ;
struct V_62 * V_7 = V_2 -> V_7 ;
return 0 ;
}
static int F_29 ( struct V_67 * V_34 )
{
struct V_1 * V_2 = F_37 ( V_34 ) ;
struct V_62 * V_7 = V_2 -> V_7 ;
return 0 ;
}
int T_5 F_33 ( char * V_68 )
{
}
static int T_5 F_30 ( void )
{
int V_69 ;
#ifndef F_31
char * V_63 = NULL ;
if ( F_32 ( L_3 , & V_63 ) )
return - V_64 ;
F_33 ( V_63 ) ;
#endif
V_69 = F_38 ( & V_65 ) ;
if ( ! V_69 ) {
V_70 = F_39 ( L_3 , 0 ,
NULL , 0 ) ;
if ( F_40 ( V_70 ) ) {
F_41 ( & V_65 ) ;
V_69 = F_42 ( V_70 ) ;
}
}
return V_69 ;
}
static void T_6 F_35 ( void )
{
F_43 ( V_70 ) ;
F_41 ( & V_65 ) ;
}
