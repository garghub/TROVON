static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_2 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
int F_7 ( struct V_6 * V_7 , struct V_8 * V_9 ,
unsigned long V_10 , struct V_11 * V_12 )
{
F_8 ( V_13 ) ;
struct V_1 * V_2 ;
static T_1 V_14 = 0x80000000 ;
unsigned long V_15 ;
int V_16 = 0 ;
V_2 = F_1 () ;
if ( ! V_2 ) {
F_9 ( V_7 , V_9 ) ;
return - V_17 ;
}
if ( V_14 == 0xffffffff )
V_14 = 0x80000000 ;
if ( V_12 )
V_2 -> V_12 = * V_12 ;
V_9 -> V_18 . V_19 . V_20 = F_10 ( V_21 . V_22 ) ;
V_2 -> V_14 = V_14 ++ ;
V_9 -> V_18 . V_19 . V_14 = F_10 ( V_2 -> V_14 ) ;
V_2 -> V_13 = & V_13 ;
F_11 ( & V_2 -> V_4 , & V_23 ) ;
F_12 ( V_7 , V_9 ) ;
F_13 ( V_13 , V_2 -> V_24 , V_10 * V_25 ) ;
F_14 ( & V_2 -> V_5 , V_15 ) ;
V_2 -> V_13 = NULL ;
if ( V_2 -> V_24 )
V_16 = F_15 ( V_2 -> V_9 -> V_26 [ 0 ] ) >> 24 ;
else {
if ( V_12 )
V_12 -> V_27 = NULL ;
V_16 = - V_28 ;
}
F_16 ( & V_2 -> V_5 , V_15 ) ;
if ( V_16 != - V_28 ) {
F_17 ( V_7 , V_2 -> V_29 ) ;
F_5 ( V_2 ) ;
}
return V_16 ;
}
static int F_18 ( struct V_6 * V_7 , T_1 V_29 ,
struct V_8 * V_9 , T_1 V_22 )
{
struct V_1 * V_2 , * V_30 ;
unsigned long V_15 ;
int V_16 = 1 ;
F_19 (wait, tmp, &i2o_exec_wait_list, list) {
if ( V_2 -> V_14 == V_22 ) {
F_14 ( & V_2 -> V_5 , V_15 ) ;
F_20 ( & V_2 -> V_4 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_24 = 1 ;
if ( V_2 -> V_13 )
V_16 = 0 ;
else
V_16 = - 1 ;
F_16 ( & V_2 -> V_5 , V_15 ) ;
if ( V_16 ) {
struct V_31 * V_32 ;
V_32 = & V_7 -> V_33 -> V_32 ;
F_21 ( L_1 ,
V_7 -> V_34 ) ;
F_22 ( V_32 , & V_2 -> V_12 ) ;
F_5 ( V_2 ) ;
} else
F_23 ( V_2 -> V_13 ) ;
return V_16 ;
}
}
F_24 ( L_2 , V_7 -> V_34 ,
V_22 ) ;
return - 1 ;
}
static T_2 F_25 ( struct V_31 * V_35 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_39 * V_32 = F_26 ( V_35 ) ;
T_3 V_40 ;
if ( ! F_27 ( V_32 , 0x0000 , 0 , & V_40 , 2 ) ) {
sprintf ( V_38 , L_3 , F_28 ( V_40 ) ) ;
return strlen ( V_38 ) + 1 ;
}
return 0 ;
}
static T_2 F_29 ( struct V_31 * V_35 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_39 * V_32 = F_26 ( V_35 ) ;
T_3 V_40 ;
if ( ! F_27 ( V_32 , 0x0000 , 1 , & V_40 , 2 ) ) {
sprintf ( V_38 , L_3 , F_28 ( V_40 ) ) ;
return strlen ( V_38 ) + 1 ;
}
return 0 ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_39 * V_41 = F_26 ( V_32 ) ;
int V_16 ;
V_16 = F_31 ( V_41 , & V_21 , 0 , 0xffffffff ) ;
if ( V_16 ) goto V_42;
V_16 = F_32 ( V_32 , & V_43 ) ;
if ( V_16 ) goto V_44;
V_16 = F_32 ( V_32 , & V_45 ) ;
if ( V_16 ) goto V_46;
V_41 -> V_47 -> V_48 = V_41 ;
return 0 ;
V_46:
F_33 ( V_32 , & V_43 ) ;
V_44:
F_31 ( F_26 ( V_32 ) , & V_21 , 0 , 0 ) ;
V_42:
return V_16 ;
}
static int F_34 ( struct V_31 * V_32 )
{
F_33 ( V_32 , & V_45 ) ;
F_33 ( V_32 , & V_43 ) ;
F_31 ( F_26 ( V_32 ) , & V_21 , 0 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , T_1 V_49 )
{
T_4 * V_50 = V_7 -> V_51 . V_27 ;
struct V_31 * V_32 ;
struct V_8 * V_9 ;
F_36 ( & V_7 -> V_52 ) ;
V_32 = & V_7 -> V_33 -> V_32 ;
if ( F_37 ( V_32 , & V_7 -> V_53 ,
F_15 ( V_50 -> V_54 ) ) ) {
F_38 ( & V_7 -> V_52 ) ;
return - V_17 ;
}
V_9 = F_39 ( V_7 , V_55 ) ;
if ( F_40 ( V_9 ) ) {
F_38 ( & V_7 -> V_52 ) ;
return F_41 ( V_9 ) ;
}
V_9 -> V_18 . V_56 [ 0 ] = F_10 ( V_57 | V_58 ) ;
V_9 -> V_18 . V_56 [ 1 ] = F_10 ( V_59 << 24 | V_60 << 12 |
V_61 ) ;
V_9 -> V_18 . V_19 . V_20 = F_10 ( V_21 . V_22 ) ;
V_9 -> V_18 . V_19 . V_14 = F_10 ( 0x00000000 ) ;
V_9 -> V_26 [ 0 ] = F_10 ( 0xffffffff ) ;
V_9 -> V_26 [ 1 ] = F_10 ( V_49 ) ;
V_9 -> V_26 [ 2 ] = F_10 ( 0xd0000000 | V_7 -> V_53 . V_62 ) ;
V_9 -> V_26 [ 3 ] = F_10 ( V_7 -> V_53 . V_63 ) ;
F_12 ( V_7 , V_9 ) ;
F_38 ( & V_7 -> V_52 ) ;
return 0 ;
}
static void F_42 ( struct V_64 * V_65 )
{
struct V_66 * V_67 =
F_43 ( V_65 , struct V_66 , V_67 ) ;
T_1 V_49 = 0 ;
struct V_6 * V_7 = V_67 -> V_7 ;
F_6 ( V_67 ) ;
if ( F_44 ( V_7 ) != - V_68 )
V_49 = V_7 -> V_69 -> V_49 + 1 ;
#ifdef F_45
F_35 ( V_7 , V_49 ) ;
#endif
}
static int F_46 ( struct V_6 * V_7 , T_1 V_29 ,
struct V_8 * V_9 )
{
T_1 V_22 ;
if ( F_15 ( V_9 -> V_18 . V_56 [ 0 ] ) & V_70 ) {
struct V_8 T_5 * V_71 ;
T_1 V_72 ;
V_72 = F_15 ( V_9 -> V_26 [ 3 ] ) ;
V_71 = F_47 ( V_7 , V_72 ) ;
V_22 = F_48 ( & V_71 -> V_18 . V_19 . V_14 ) ;
F_49 ( V_73 , L_4 , V_9 ) ;
F_50 ( V_7 , V_72 ) ;
} else
V_22 = F_15 ( V_9 -> V_18 . V_19 . V_14 ) ;
if ( V_22 & 0x80000000 )
return F_18 ( V_7 , V_29 , V_9 , V_22 ) ;
if ( ( F_15 ( V_9 -> V_18 . V_56 [ 1 ] ) >> 24 ) == V_59 ) {
struct V_66 * V_67 ;
F_21 ( L_5 , V_7 -> V_34 ) ;
V_67 = F_51 ( sizeof( * V_67 ) , V_74 ) ;
if ( ! V_67 )
return - V_17 ;
V_67 -> V_7 = V_7 ;
F_52 ( & V_67 -> V_67 , F_42 ) ;
F_53 ( V_21 . V_75 , & V_67 -> V_67 ) ;
return 1 ;
}
F_54 ( V_76 L_6
L_7 , V_7 -> V_34 ) ;
F_55 ( V_9 ) ;
return - V_77 ;
}
static void F_56 ( struct V_64 * V_67 )
{
struct V_78 * V_79 = F_43 ( V_67 , struct V_78 , V_67 ) ;
if ( F_57 ( V_79 -> V_41 ) )
F_58 ( L_8 ,
V_79 -> V_41 -> V_80 . V_81 ) ;
F_6 ( V_79 ) ;
}
int F_59 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_82 = 0 ;
int V_16 = - V_68 ;
for ( V_82 = 1 ; V_82 <= V_83 ; V_82 ++ ) {
V_9 = F_39 ( V_7 , V_55 ) ;
if ( F_40 ( V_9 ) )
return F_41 ( V_9 ) ;
V_9 -> V_18 . V_56 [ 0 ] =
F_10 ( V_57 | V_58 ) ;
V_9 -> V_18 . V_56 [ 1 ] =
F_10 ( V_59 << 24 | V_60 << 12 |
V_61 ) ;
V_9 -> V_26 [ 0 ] = F_10 ( 0xffffffff ) ;
V_9 -> V_26 [ 1 ] = F_10 ( 0x00000000 ) ;
V_9 -> V_26 [ 2 ] = F_10 ( 0xd0000000 | V_7 -> V_53 . V_62 ) ;
V_9 -> V_26 [ 3 ] = F_10 ( V_7 -> V_53 . V_63 ) ;
V_16 = F_60 ( V_7 , V_9 , V_84 ) ;
if ( V_16 < 0 )
break;
V_16 = F_44 ( V_7 ) ;
if ( V_16 != - V_68 )
break;
}
return V_16 ;
}
int T_6 F_61 ( void )
{
return F_62 ( & V_21 ) ;
}
void F_63 ( void )
{
F_64 ( & V_21 ) ;
}
