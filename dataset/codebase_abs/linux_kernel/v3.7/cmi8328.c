static T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
F_2 ( 0x43 , V_1 + 3 ) ;
F_2 ( 0x21 , V_1 + 3 ) ;
F_2 ( V_2 , V_1 + 3 ) ;
return F_3 ( V_1 ) ;
}
static void F_4 ( T_2 V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( 0x43 , V_1 + 3 ) ;
F_2 ( 0x21 , V_1 + 3 ) ;
F_2 ( V_2 , V_1 + 3 ) ;
F_2 ( V_3 , V_1 + 3 ) ;
}
static void F_5 ( T_2 V_1 , T_1 V_4 [] )
{
V_4 [ 0 ] = F_1 ( V_1 , V_5 ) ;
V_4 [ 1 ] = F_1 ( V_1 , V_6 ) ;
V_4 [ 2 ] = F_1 ( V_1 , V_7 ) ;
}
static void F_6 ( T_2 V_1 , T_1 V_4 [] )
{
F_4 ( V_1 , V_5 , V_4 [ 0 ] ) ;
F_4 ( V_1 , V_6 , V_4 [ 1 ] ) ;
F_4 ( V_1 , V_7 , V_4 [ 2 ] ) ;
}
static int T_3 F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 V_13 , V_14 ;
int V_15 ;
V_11 = V_9 -> V_11 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_13 . V_16 = V_14 . V_16 = V_17 ;
strcpy ( V_13 . V_18 , L_1 ) ;
strcpy ( V_14 . V_18 , L_2 ) ;
V_15 = F_8 ( V_11 , & V_13 , & V_14 ) ;
if ( V_15 < 0 ) {
F_9 ( V_19 L_3 ) ;
return V_15 ;
}
strcpy ( V_13 . V_18 , L_4 ) ;
strcpy ( V_14 . V_18 , L_5 ) ;
V_15 = F_8 ( V_11 , & V_13 , & V_14 ) ;
if ( V_15 < 0 ) {
F_9 ( V_19 L_3 ) ;
return V_15 ;
}
strcpy ( V_13 . V_18 , L_1 ) ;
V_13 . V_20 = 1 ;
strcpy ( V_14 . V_18 , L_6 ) ;
V_15 = F_8 ( V_11 , & V_13 , & V_14 ) ;
if ( V_15 < 0 ) {
F_9 ( V_19 L_3 ) ;
return V_15 ;
}
strcpy ( V_13 . V_18 , L_4 ) ;
V_13 . V_20 = 1 ;
strcpy ( V_14 . V_18 , L_7 ) ;
V_15 = F_8 ( V_11 , & V_13 , & V_14 ) ;
if ( V_15 < 0 ) {
F_9 ( V_19 L_3 ) ;
return V_15 ;
}
return 0 ;
}
int F_10 ( int V_21 [] , int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_21 [ V_23 ] != - 1 ; V_23 ++ )
if ( V_21 [ V_23 ] == V_22 )
return V_23 ;
return - 1 ;
}
int F_11 ( long V_21 [] , long V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_21 [ V_23 ] != - 1 ; V_23 ++ )
if ( V_21 [ V_23 ] == V_22 )
return V_23 ;
return - 1 ;
}
static int T_3 F_12 ( struct V_24 * V_25 , unsigned int V_26 )
{
struct V_10 * V_11 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
#ifdef F_13
struct V_31 * V_32 ;
#endif
int V_15 , V_33 ;
static long V_34 [] = { 0x330 , 0x300 , 0x310 , 0x320 , 0x332 , 0x334 ,
0x336 , - 1 } ;
static T_1 V_35 [] = { 3 , 0 , 1 , 2 , 4 , 5 , 6 } ;
static int V_36 [] = { 9 , 7 , 5 , 3 , - 1 } ;
static T_1 V_37 [] = { 3 , 2 , 1 , 0 } ;
static int V_38 [] = { 9 , 10 , 11 , 7 , - 1 } ;
static T_1 V_39 [] = { 2 , 3 , 4 , 1 } ;
static int V_40 [] = { 3 , 1 , 0 , - 1 } ;
static T_1 V_41 [] = { 3 , 2 , 1 } ;
static int V_42 [] [ 2 ] = { { 1 , - 1 } , { 0 , - 1 } , { - 1 , - 1 } , { 0 , - 1 } } ;
T_2 V_1 = V_43 [ V_26 ] ;
T_1 V_3 ;
if ( F_1 ( V_1 , V_5 ) == 0xff )
return - V_44 ;
F_4 ( V_1 , V_5 , V_45 ) ;
if ( F_1 ( V_1 , V_5 ) != V_45 )
return - V_44 ;
F_4 ( V_1 , V_6 , 0 ) ;
F_4 ( V_1 , V_7 , 0 ) ;
if ( V_46 [ V_26 ] == V_47 ) {
V_46 [ V_26 ] = F_14 ( V_38 ) ;
if ( V_46 [ V_26 ] < 0 ) {
F_9 ( V_19 L_8 ) ;
return - V_48 ;
}
}
if ( V_49 [ V_26 ] == V_50 ) {
V_49 [ V_26 ] = F_15 ( V_40 ) ;
if ( V_49 [ V_26 ] < 0 ) {
F_9 ( V_19 L_9 ) ;
return - V_48 ;
}
}
if ( V_51 [ V_26 ] == V_50 ) {
V_51 [ V_26 ] = F_15 ( V_42 [ V_49 [ V_26 ] % 4 ] ) ;
if ( V_51 [ V_26 ] < 0 ) {
F_9 ( V_52 L_10 ) ;
V_51 [ V_26 ] = - 1 ;
}
}
V_33 = F_10 ( V_38 , V_46 [ V_26 ] ) ;
if ( V_33 < 0 ) {
F_9 ( V_19 L_11 , V_46 [ V_26 ] ) ;
return - V_53 ;
}
V_3 = V_39 [ V_33 ] << 3 ;
V_33 = F_10 ( V_40 , V_49 [ V_26 ] ) ;
if ( V_33 < 0 ) {
F_9 ( V_19 L_12 , V_49 [ V_26 ] ) ;
return - V_53 ;
}
V_3 |= V_41 [ V_33 ] ;
if ( V_51 [ V_26 ] >= 0 && V_49 [ V_26 ] != V_51 [ V_26 ] ) {
V_33 = F_10 ( V_42 [ V_49 [ V_26 ] ] , V_51 [ V_26 ] ) ;
if ( V_33 < 0 ) {
F_9 ( V_19 L_13 , V_51 [ V_26 ] ) ;
return - V_53 ;
}
V_3 |= 0x04 ;
}
F_2 ( V_3 , V_1 ) ;
V_15 = F_16 ( V_20 [ V_26 ] , V_54 [ V_26 ] , V_55 ,
sizeof( struct V_29 ) , & V_11 ) ;
if ( V_15 < 0 )
return V_15 ;
V_30 = V_11 -> V_56 ;
V_30 -> V_11 = V_11 ;
V_30 -> V_1 = V_1 ;
V_30 -> V_57 = V_3 ;
F_17 ( V_11 , V_25 ) ;
V_15 = F_18 ( V_11 , V_1 + 4 , - 1 , V_46 [ V_26 ] , V_49 [ V_26 ] ,
V_51 [ V_26 ] , V_58 , 0 , & V_30 -> V_59 ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_19 ( V_30 -> V_59 , 0 , NULL ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_20 ( V_30 -> V_59 ) ;
if ( V_15 < 0 )
goto error;
V_15 = F_7 ( V_30 -> V_59 ) ;
if ( V_15 < 0 )
goto error;
if ( F_21 ( V_30 -> V_59 , 0 , NULL ) < 0 )
F_9 ( V_52 L_14 ) ;
if ( V_60 [ V_26 ] == V_61 ) {
V_60 [ V_26 ] = F_22 ( V_34 , 2 ) ;
if ( V_60 [ V_26 ] < 0 )
F_9 ( V_19 L_15 ) ;
}
if ( V_62 [ V_26 ] == V_47 ) {
V_62 [ V_26 ] = F_14 ( V_36 ) ;
if ( V_62 [ V_26 ] < 0 )
F_9 ( V_19 L_16 ) ;
}
if ( V_60 [ V_26 ] > 0 && V_62 [ V_26 ] > 0 ) {
V_3 = V_63 ;
V_33 = F_11 ( V_34 , V_60 [ V_26 ] ) ;
if ( V_33 < 0 )
F_9 ( V_52 L_17 ,
V_60 [ V_26 ] ) ;
else {
V_3 |= V_35 [ V_33 ] << 5 ;
V_33 = F_10 ( V_36 , V_62 [ V_26 ] ) ;
if ( V_33 < 0 )
F_9 ( V_52 L_18 ,
V_62 [ V_26 ] ) ;
else {
V_3 |= V_37 [ V_33 ] << 3 ;
F_4 ( V_1 , V_6 , V_3 ) ;
if ( F_23 ( V_11 , 0 ,
V_64 , V_60 [ V_26 ] ,
0 , V_62 [ V_26 ] , NULL ) < 0 )
F_9 ( V_19 L_19 ) ;
}
}
}
if ( F_24 ( V_11 , 0x388 , 0x38a , V_65 , 0 , & V_28 ) < 0 )
F_9 ( V_19 L_20 ) ;
else
if ( F_25 ( V_28 , 0 , 1 , NULL ) < 0 )
F_9 ( V_52 L_21 ) ;
strcpy ( V_11 -> V_66 , L_22 ) ;
strcpy ( V_11 -> V_67 , L_23 ) ;
sprintf ( V_11 -> V_68 , L_24 ,
V_11 -> V_67 , V_30 -> V_59 -> V_1 , V_46 [ V_26 ] , V_49 [ V_26 ] ,
( V_51 [ V_26 ] >= 0 ) ? V_51 [ V_26 ] : V_49 [ V_26 ] ) ;
F_26 ( V_25 , V_11 ) ;
V_15 = F_27 ( V_11 ) ;
if ( V_15 < 0 )
goto error;
#ifdef F_13
if ( ! V_69 [ V_26 ] )
return 0 ;
V_32 = F_28 ( 0x200 , 8 , L_25 ) ;
if ( ! V_32 )
F_9 ( V_52 L_26 ) ;
else {
struct V_69 * V_70 = V_30 -> V_69 = F_29 () ;
if ( ! V_30 -> V_69 )
F_30 ( V_32 ) ;
else {
F_31 ( V_70 , L_27 ) ;
F_32 ( V_70 , L_28 , F_33 ( V_25 ) ) ;
F_34 ( V_70 , V_25 ) ;
V_70 -> V_71 = 0x200 ;
F_35 ( V_70 , V_32 ) ;
F_4 ( V_1 , V_5 ,
V_45 | V_72 ) ;
F_36 ( V_70 ) ;
}
}
#endif
return 0 ;
error:
F_37 ( V_11 ) ;
return V_15 ;
}
static int T_4 F_38 ( struct V_24 * V_25 , unsigned int V_73 )
{
struct V_10 * V_11 = F_39 ( V_25 ) ;
struct V_29 * V_30 = V_11 -> V_56 ;
#ifdef F_13
if ( V_30 -> V_69 ) {
struct V_31 * V_32 = F_40 ( V_30 -> V_69 ) ;
F_41 ( V_30 -> V_69 ) ;
F_30 ( V_32 ) ;
}
#endif
F_4 ( V_30 -> V_1 , V_5 , V_45 ) ;
F_4 ( V_30 -> V_1 , V_6 , 0 ) ;
F_4 ( V_30 -> V_1 , V_7 , 0 ) ;
F_37 ( V_11 ) ;
F_26 ( V_25 , NULL ) ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 , unsigned int V_74 ,
T_5 V_75 )
{
struct V_10 * V_11 = F_39 ( V_25 ) ;
struct V_29 * V_30 ;
if ( ! V_11 )
return 0 ;
V_30 = V_11 -> V_56 ;
F_5 ( V_30 -> V_1 , V_30 -> V_4 ) ;
F_43 ( V_11 , V_76 ) ;
F_44 ( V_30 -> V_59 -> V_77 ) ;
V_30 -> V_59 -> V_78 ( V_30 -> V_59 ) ;
return 0 ;
}
static int F_45 ( struct V_24 * V_25 , unsigned int V_74 )
{
struct V_10 * V_11 = F_39 ( V_25 ) ;
struct V_29 * V_30 ;
if ( ! V_11 )
return 0 ;
V_30 = V_11 -> V_56 ;
F_6 ( V_30 -> V_1 , V_30 -> V_4 ) ;
F_2 ( V_30 -> V_57 , V_30 -> V_1 ) ;
V_30 -> V_59 -> V_79 ( V_30 -> V_59 ) ;
F_43 ( V_11 , V_80 ) ;
return 0 ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_81 , V_82 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_81 ) ;
}
