int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 -> V_4 ) )
return - V_5 ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 -> V_4 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_6 ( & V_8 -> V_9 ) ;
if ( V_8 -> V_10 ) {
F_7 ( & V_8 -> V_9 ) ;
return - V_11 ;
}
V_8 -> V_10 ++ ;
F_7 ( & V_8 -> V_9 ) ;
F_8 ( V_2 ) ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ ) {
V_2 -> V_13 [ V_6 ] . V_14 = V_15 ;
V_2 -> V_13 [ V_6 ] . time = 0 ;
V_2 -> V_13 [ V_6 ] . V_16 = 0x00 ;
}
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0x00 ;
if ( V_2 -> V_19 >= V_20 ) {
V_2 -> V_21 ( V_2 , V_22 | V_23 ,
V_2 -> V_18 ) ;
V_2 -> V_24 = V_12 ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
struct V_7 * V_8 ;
F_10 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> V_27 ) {
F_11 ( & V_2 -> V_28 ) ;
V_2 -> V_27 = 0 ;
}
F_12 ( & V_2 -> V_26 , V_25 ) ;
F_8 ( V_2 ) ;
V_8 = V_2 -> V_8 ;
F_6 ( & V_8 -> V_9 ) ;
V_8 -> V_10 -- ;
F_7 ( & V_8 -> V_9 ) ;
F_13 ( & V_8 -> V_29 ) ;
}
static int F_14 ( void * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_2 = V_30 ;
int V_33 ;
if ( ( V_33 = F_5 ( V_2 ) ) < 0 )
return V_33 ;
if ( V_34 ) {
V_2 -> V_13 [ 6 ] . V_14 = V_2 -> V_13 [ 7 ] . V_14 =
V_2 -> V_13 [ 8 ] . V_14 = V_35 ;
F_15 ( V_2 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_21 ( V_2 , V_38 | V_39 , V_2 -> V_36 ) ;
} else {
V_2 -> V_36 = 0x00 ;
}
if ( V_32 -> V_40 . V_41 != V_42 ) {
if ( ( V_33 = F_1 ( V_2 ) ) < 0 )
return V_33 ;
}
V_2 -> V_43 = V_44 ;
return 0 ;
}
static int F_16 ( void * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_2 = V_30 ;
F_9 ( V_2 ) ;
if ( V_32 -> V_40 . V_41 != V_42 )
F_3 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_46 , int V_47 ,
void * V_30 , int V_48 , int V_49 )
{
struct V_1 * V_2 = V_30 ;
F_18 ( & V_50 , V_46 , V_2 -> V_51 ) ;
return 0 ;
}
static void F_19 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
F_20 ( V_2 -> V_51 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_52 V_53 ;
char V_54 [ 32 ] ;
int V_13 , V_55 ;
V_13 = ( V_2 -> V_19 < V_20 ) ?
V_56 : V_12 ;
V_2 -> V_51 = F_22 ( 16 ) ;
if ( V_2 -> V_51 == NULL )
return - V_57 ;
V_2 -> V_51 -> V_30 = V_2 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_58 = V_59 ;
V_53 . V_60 = F_14 ;
V_53 . V_61 = F_16 ;
V_53 . V_62 = F_17 ;
V_53 . V_63 = F_19 ;
V_53 . V_30 = V_2 ;
V_55 = ( V_2 -> V_19 & V_64 ) >> 8 ;
sprintf ( V_54 , L_1 , V_55 ) ;
V_2 -> V_51 -> V_41 = V_2 -> V_65 ;
V_2 -> V_51 -> V_66 = F_23 ( V_2 -> V_65 , & V_53 ,
V_67 |
V_68 ,
V_69 |
V_70 |
V_71 |
V_72 |
V_73 ,
16 , V_13 ,
V_54 ) ;
if ( V_2 -> V_51 -> V_66 < 0 ) {
int V_66 ;
V_66 = V_2 -> V_51 -> V_66 ;
F_20 ( V_2 -> V_51 ) ;
return V_66 ;
}
return 0 ;
}
static int F_24 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
int V_41 , V_33 ;
char V_54 [ 32 ] ;
int V_55 ;
V_2 = * (struct V_1 * * ) F_25 ( V_75 ) ;
if ( V_2 == NULL )
return - V_76 ;
F_26 ( & V_2 -> V_77 ) ;
V_2 -> V_65 = - 1 ;
V_55 = ( V_2 -> V_19 & V_64 ) >> 8 ;
sprintf ( V_54 , L_2 , V_55 ) ;
V_41 = V_2 -> V_65 =
F_27 ( V_2 -> V_3 , V_2 -> V_78 ,
V_54 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ( V_33 = F_21 ( V_2 ) ) < 0 ) {
F_28 ( V_41 ) ;
V_2 -> V_65 = - 1 ;
return V_33 ;
}
F_29 ( & V_2 -> V_28 , V_79 , ( unsigned long ) V_2 ) ;
F_26 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = 0 ;
#ifdef F_30
F_31 ( V_2 , V_54 ) ;
#endif
return 0 ;
}
static int F_32 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = * (struct V_1 * * ) F_25 ( V_75 ) ;
if ( V_2 == NULL )
return - V_76 ;
#ifdef F_30
F_33 ( V_2 ) ;
#endif
if ( V_2 -> V_65 >= 0 ) {
F_28 ( V_2 -> V_65 ) ;
V_2 -> V_65 = - 1 ;
}
return 0 ;
}
static int T_1 F_34 ( void )
{
static struct V_80 V_81 =
{
F_24 ,
F_32
} ;
return F_35 ( V_82 , & V_81 ,
sizeof( struct V_1 * ) ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( V_82 ) ;
}
