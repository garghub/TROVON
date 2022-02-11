static struct V_1 * F_1 ( void * V_2 )
{
struct V_1 * V_3 = V_4 ;
if ( V_3 == NULL )
return V_3 ;
while ( ( V_3 != NULL ) &&
( V_3 -> V_5 -> V_2 != V_2 ) )
V_3 = V_3 -> V_6 ;
return V_3 ;
}
static struct V_7 * F_2 ( struct V_7 * V_8 ,
void * V_9 , int V_10 )
{
if ( V_8 == NULL )
return NULL ;
if ( ( V_8 -> V_11 [ V_10 ] ) == NULL )
return NULL ;
if ( V_8 -> V_11 [ V_10 ] -> V_12 == V_9 )
return V_8 ;
return NULL ;
}
static struct V_1 * F_3 ( void * V_9 )
{
struct V_1 * V_3 = V_4 ;
struct V_7 * V_8 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_5 != NULL ) {
V_8 = V_3 -> V_5 ;
if ( F_2 ( V_8 , V_9 , 0 ) )
break;
if ( F_2 ( V_8 , V_9 , 1 ) )
break;
}
V_3 = V_3 -> V_6 ;
}
return V_3 ;
}
static void F_4 ( struct V_7 * V_5 )
{
struct V_1 * V_13 = V_4 ;
struct V_1 * V_14 = F_1 ( V_5 -> V_2 ) ;
if ( V_14 != NULL ) {
if ( V_14 == V_4 ) {
V_4 = V_14 -> V_6 ;
} else {
while ( V_13 -> V_6 != V_14 )
V_13 = V_13 -> V_6 ;
if ( V_14 -> V_6 == NULL )
V_13 -> V_6 = NULL ;
else
V_13 -> V_6 =
V_13 -> V_6 -> V_6 ;
}
F_5 ( V_14 ) ;
}
}
static struct V_1 * F_6 ( struct V_7 * V_5 )
{
struct V_1 * V_15 = V_4 ;
if ( V_15 == NULL ) {
V_15 = F_7 ( sizeof( struct V_1 ) , V_16 ) ;
V_4 = V_15 ;
} else {
while ( V_15 -> V_6 != NULL )
V_15 = V_15 -> V_6 ;
V_15 -> V_6 =
F_7 ( sizeof( struct V_1 ) , V_16 ) ;
if ( V_15 -> V_6 != NULL )
V_15 = V_15 -> V_6 ;
else
V_15 = NULL ;
}
if ( V_15 != NULL ) {
V_15 -> V_5 = V_5 ;
V_15 -> V_6 = NULL ;
}
return V_15 ;
}
static int F_8 ( struct V_7 * V_17 , int V_18 ,
T_1 V_19 , T_1 V_20 )
{
V_17 -> V_21 ( V_17 -> V_2 , V_22 , V_18 , 0 ) ;
return V_17 -> V_21 ( V_17 -> V_2 , 0 , V_19 , V_20 ) ;
}
static int F_9 ( struct V_23 * V_24 , int V_25 ,
T_1 V_26 , T_1 V_20 , int V_18 , T_1 V_19 )
{
struct V_27 * V_28 = V_24 -> V_29 ;
struct V_7 * V_17 = V_28 -> V_5 ;
T_1 V_30 ;
int V_31 = 0 ;
if ( 0 != V_25 )
return - V_32 ;
F_10 ( & V_17 -> V_33 ) ;
F_8 ( V_17 , V_34 , ( ( V_18 << 1 ) & 0xfe ) , 0 ) ;
F_8 ( V_17 , V_35 , ( ( V_18 >> 7 ) & 0x7f ) , 0 ) ;
V_30 = F_8 ( V_17 , V_36 , 0 , V_37 ) ;
V_30 &= 0x0f ;
V_30 |= ( ( V_28 -> V_38 << 7 ) | ( V_26 << 6 ) ) ;
F_8 ( V_17 , V_36 , V_30 , 0 ) ;
V_31 = F_8 ( V_17 , V_39 , V_19 , V_20 ) ;
F_11 ( & V_17 -> V_33 ) ;
F_12 ( L_1 , V_40 ,
( V_20 ) ? L_2 : L_3 , V_18 ,
( V_26 == V_41 ) ? L_4 : L_5 ,
( V_20 ) ? V_31 : V_19 ) ;
return V_31 ;
}
static int F_13 ( struct V_23 * V_24 ,
int V_25 , int V_18 )
{
return F_9 ( V_24 , V_25 , 0 , V_37 , V_18 , 0 ) ;
}
static int F_14 ( struct V_23 * V_24 ,
int V_25 , int V_18 , T_1 V_29 )
{
return F_9 ( V_24 , V_25 , 0 , 0 , V_18 , V_29 ) ;
}
static int F_15 ( struct V_23 * V_24 ,
int V_25 , T_1 V_18 )
{
return F_9 ( V_24 , V_25 , V_41 ,
V_37 , V_18 , 0 ) ;
}
static int F_16 ( struct V_23 * V_24 , int V_25 ,
T_1 V_18 , T_1 V_29 )
{
return F_9 ( V_24 , V_25 , V_41 , 0 , V_18 , V_29 ) ;
}
static int F_17 ( struct V_23 * V_24 , int V_25 )
{
struct V_27 * V_28 = V_24 -> V_29 ;
struct V_7 * V_17 = V_28 -> V_5 ;
unsigned long V_42 = V_43 + F_18 ( 9999 ) ;
int V_44 ;
F_12 ( L_6 , V_40 ) ;
if ( 0 != V_25 )
return - V_32 ;
F_10 ( & V_17 -> V_33 ) ;
V_44 = F_8 ( V_17 , V_36 , 0 , V_37 ) ;
F_8 ( V_17 , V_36 ,
( V_44 & 0xcf ) | ( 1 << ( 5 - V_28 -> V_38 ) ) , 0 ) ;
F_11 ( & V_17 -> V_33 ) ;
for (; ; ) {
F_19 ( 50 ) ;
F_10 ( & V_17 -> V_33 ) ;
V_44 = F_8 ( V_17 , V_36 ,
0 , V_37 ) ;
F_11 ( & V_17 -> V_33 ) ;
if ( ( V_44 & ( 1 << ( 5 - V_28 -> V_38 ) ) ) == 0 )
break;
if ( F_20 ( V_43 , V_42 ) )
break;
}
F_12 ( L_7 , V_40 ,
F_21 ( V_43 + F_18 ( 9999 ) - V_42 ) ) ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 , int V_25 )
{
return 0 ;
}
static int F_23 ( struct V_23 * V_24 , int V_25 )
{
struct V_27 * V_28 = V_24 -> V_29 ;
struct V_7 * V_17 = V_28 -> V_5 ;
int V_44 ;
F_12 ( L_6 , V_40 ) ;
if ( 0 != V_25 )
return - V_32 ;
F_10 ( & V_17 -> V_33 ) ;
V_44 = F_8 ( V_17 , V_36 , 0 , V_37 ) ;
F_8 ( V_17 , V_36 ,
( V_44 & 0x0f ) | ( 1 << ( 3 - V_28 -> V_38 ) ) , 0 ) ;
F_11 ( & V_17 -> V_33 ) ;
return 0 ;
}
static void F_24 ( struct V_45 * V_46 )
{
struct V_7 * V_17 =
F_25 ( V_46 , struct V_7 , V_46 ) ;
int V_44 ;
F_12 ( L_6 , V_40 ) ;
F_10 ( & V_17 -> V_33 ) ;
V_44 = F_8 ( V_17 , V_47 , 0 , V_37 ) ;
V_44 = F_8 ( V_17 , V_36 , 0 , V_37 ) ;
F_11 ( & V_17 -> V_33 ) ;
if ( V_17 -> V_28 [ 1 ] != NULL ) {
V_17 -> V_28 [ 1 ] -> V_48 =
( ( V_44 & 1 ) == 0 ?
V_49 |
V_50 : 0 ) ;
F_12 ( L_8 ,
V_40 , V_17 -> V_28 [ 1 ] -> V_48 ) ;
}
if ( V_17 -> V_28 [ 0 ] != NULL ) {
V_17 -> V_28 [ 0 ] -> V_48 =
( ( V_44 & 2 ) == 0 ?
V_49 |
V_50 : 0 ) ;
F_12 ( L_9 ,
V_40 , V_17 -> V_28 [ 0 ] -> V_48 ) ;
}
}
int F_26 ( void * V_2 )
{
struct V_1 * V_8 = NULL ;
struct V_7 * V_17 = NULL ;
F_12 ( L_6 , V_40 ) ;
if ( V_2 != NULL ) {
V_8 = F_1 ( V_2 ) ;
if ( V_8 != NULL ) {
V_17 = V_8 -> V_5 ;
F_27 ( & V_17 -> V_46 ) ;
}
}
return 1 ;
}
static int F_28 ( struct V_23 * V_24 ,
int V_25 , int V_51 )
{
struct V_27 * V_28 = V_24 -> V_29 ;
if ( 0 != V_25 )
return - V_32 ;
return V_28 -> V_48 ;
}
static void F_29 ( void * V_52 , int V_10 )
{
struct V_1 * V_8 = F_1 ( V_52 ) ;
struct V_53 * V_11 = NULL ;
F_12 ( L_6 , V_40 ) ;
if ( V_8 != NULL ) {
V_11 = V_8 -> V_5 -> V_11 [ V_10 - 1 ] ;
V_11 -> V_12 -> V_54 = V_11 -> V_54 ;
V_11 -> V_12 -> V_55 = V_11 -> V_55 ;
if ( ( ( -- ( V_8 -> V_5 -> V_56 ) ) <= 0 ) &&
( ( V_8 -> V_5 -> V_57 ) <= 0 ) ) {
F_12 ( L_10 , V_40 ) ;
F_4 ( V_8 -> V_5 ) ;
F_5 ( V_11 -> V_5 ) ;
}
F_5 ( V_11 ) ;
}
}
void F_30 ( void * V_2 , int V_58 )
{
struct V_1 * V_8 = F_1 ( V_2 ) ;
struct V_27 * V_28 = NULL ;
F_12 ( L_6 , V_40 ) ;
if ( V_8 != NULL ) {
V_28 = V_8 -> V_5 -> V_28 [ V_58 - 1 ] ;
F_29 ( V_2 , V_58 ) ;
if ( ( ( V_8 -> V_5 -> V_56 ) <= 0 ) &&
( ( -- ( V_8 -> V_5 -> V_57 ) ) <= 0 ) ) {
F_12 ( L_10 , V_40 ) ;
F_4 ( V_8 -> V_5 ) ;
F_5 ( V_28 -> V_5 ) ;
}
if ( V_28 != NULL ) {
if ( V_28 -> V_59 . V_29 != NULL )
F_31 ( & V_28 -> V_59 ) ;
F_5 ( V_28 ) ;
}
}
}
static void F_32 ( struct V_53 * V_11 ,
T_2 V_60 , int V_61 )
{
struct V_7 * V_17 = V_11 -> V_5 ;
T_1 V_30 = 0 ;
if ( ( V_60 == 0x2000 ) || ( V_60 < 0x20 ) )
return;
F_10 ( & V_17 -> V_33 ) ;
F_8 ( V_17 , V_62 , ( V_60 >> 3 ) & 0xff , 0 ) ;
F_8 ( V_17 , V_63 ,
( ( V_60 >> 11 ) & 0x03 ) | ( V_11 -> V_38 << 2 ) , 0 ) ;
V_30 = F_8 ( V_17 , V_64 , 0 , V_37 ) ;
if ( V_61 )
V_30 |= ( 1 << ( V_60 & 7 ) ) ;
else
V_30 &= ~ ( 1 << ( V_60 & 7 ) ) ;
F_8 ( V_17 , V_64 , V_30 , 0 ) ;
F_11 ( & V_17 -> V_33 ) ;
F_33 ( L_11 , V_40 ,
V_11 -> V_38 , V_60 , V_60 , V_61 ? L_12 : L_13 ) ;
}
static void F_34 ( struct V_53 * V_11 ,
int V_10 , int V_61 )
{
struct V_7 * V_17 = V_11 -> V_5 ;
T_1 V_30 = 0 ;
int V_65 ;
F_33 ( L_14 , V_40 , V_11 -> V_38 ,
V_61 ? L_12 : L_13 ) ;
if ( V_61 )
V_30 = 0xff ;
else
V_30 = 0 ;
F_10 ( & V_17 -> V_33 ) ;
for ( V_65 = 0 ; V_65 < 1024 ; V_65 ++ ) {
F_8 ( V_17 , V_62 , V_65 & 0xff , 0 ) ;
F_8 ( V_17 , V_63 ,
( ( V_65 >> 8 ) & 0x03 ) | ( V_11 -> V_38 << 2 ) , 0 ) ;
F_8 ( V_17 , V_64 ,
( V_65 > 3 ? V_30 : 0 ) , 0 ) ;
}
F_11 ( & V_17 -> V_33 ) ;
}
static int F_35 ( void * V_9 , int V_10 ,
struct V_66 * V_67 , int V_61 )
{
struct V_1 * V_8 = F_3 ( V_9 ) ;
struct V_7 * V_17 = V_8 -> V_5 ;
struct V_53 * V_11 = V_17 -> V_11 [ V_10 - 1 ] ;
F_32 ( V_11 , V_67 -> V_60 , V_61 ? 0 : 1 ) ;
if ( V_61 )
V_11 -> V_54 ( V_67 ) ;
else
V_11 -> V_55 ( V_67 ) ;
if ( V_67 -> V_60 == 0x2000 )
F_34 ( V_11 , V_10 ,
V_61 ? 0 : 1 ) ;
return 0 ;
}
static int F_36 ( struct V_66 * V_67 , int V_68 )
{
F_35 ( V_67 -> V_12 , V_68 , V_67 , 1 ) ;
return 0 ;
}
static int F_37 ( struct V_66 * V_67 , int V_68 )
{
F_35 ( V_67 -> V_12 , V_68 , V_67 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_66 * V_67 )
{
return F_36 ( V_67 , 1 ) ;
}
static int F_39 ( struct V_66 * V_67 )
{
return F_37 ( V_67 , 1 ) ;
}
static int F_40 ( struct V_66 * V_67 )
{
return F_36 ( V_67 , 2 ) ;
}
static int F_41 ( struct V_66 * V_67 )
{
return F_37 ( V_67 , 2 ) ;
}
static int F_42 ( struct V_69 * V_70 , int V_71 )
{
struct V_53 * V_11 = NULL ;
struct V_1 * V_8 = F_1 ( V_70 -> V_2 ) ;
struct V_7 * V_17 = NULL ;
int V_44 = 0 ;
V_11 = F_43 ( sizeof( struct V_53 ) , V_16 ) ;
F_12 ( L_6 , V_40 ) ;
if ( ! V_11 ) {
V_44 = - V_72 ;
goto V_73;
}
if ( V_8 != NULL ) {
V_17 = V_8 -> V_5 ;
( V_17 -> V_56 ) ++ ;
F_12 ( L_15 , V_40 ) ;
} else {
V_17 = F_43 ( sizeof( struct V_7 ) , V_16 ) ;
if ( ! V_17 ) {
V_44 = - V_72 ;
goto V_73;
}
V_8 = F_6 ( V_17 ) ;
V_17 -> V_56 = 1 ;
V_17 -> V_2 = V_70 -> V_2 ;
V_17 -> V_21 = V_70 -> V_21 ;
F_44 ( & V_17 -> V_33 ) ;
V_17 -> V_74 = 1 ;
F_12 ( L_16 , V_40 ) ;
}
F_12 ( L_17 , V_40 ,
V_11 , V_71 - 1 ) ;
V_17 -> V_11 [ V_71 - 1 ] = V_11 ;
V_11 -> V_12 = V_70 -> V_12 ;
V_11 -> V_5 = V_17 ;
V_11 -> V_38 = V_71 - 1 ;
V_11 -> V_54 = V_70 -> V_12 -> V_54 ;
V_11 -> V_55 = V_70 -> V_12 -> V_55 ;
if ( V_71 == 1 ) {
V_11 -> V_12 -> V_54 = F_38 ;
V_11 -> V_12 -> V_55 = F_39 ;
} else if ( V_71 == 2 ) {
V_11 -> V_12 -> V_54 = F_40 ;
V_11 -> V_12 -> V_55 = F_41 ;
}
F_34 ( V_11 , 0 , 1 ) ;
return 0 ;
V_73:
F_12 ( L_18 ,
V_40 , V_44 ) ;
F_5 ( V_11 ) ;
return V_44 ;
}
int F_45 ( struct V_69 * V_70 , int V_58 )
{
struct V_27 * V_28 ;
struct V_1 * V_8 = F_1 ( V_70 -> V_2 ) ;
struct V_7 * V_17 = NULL ;
int V_44 = 0 ;
T_1 V_30 = 0 ;
V_28 = F_43 ( sizeof( struct V_27 ) , V_16 ) ;
F_12 ( L_6 , V_40 ) ;
if ( ! V_28 ) {
V_44 = - V_72 ;
goto V_73;
}
if ( V_8 != NULL ) {
V_17 = V_8 -> V_5 ;
( V_17 -> V_57 ) ++ ;
V_17 -> V_21 = V_70 -> V_21 ;
F_12 ( L_15 , V_40 ) ;
} else {
V_17 = F_43 ( sizeof( struct V_7 ) , V_16 ) ;
if ( ! V_17 ) {
V_44 = - V_72 ;
goto V_73;
}
V_8 = F_6 ( V_17 ) ;
V_17 -> V_57 = 1 ;
V_17 -> V_2 = V_70 -> V_2 ;
V_17 -> V_21 = V_70 -> V_21 ;
F_44 ( & V_17 -> V_33 ) ;
V_17 -> V_74 = 1 ;
F_12 ( L_16 , V_40 ) ;
}
F_12 ( L_19 , V_40 ,
V_28 , V_58 - 1 ) ;
V_28 -> V_5 = V_17 ;
V_28 -> V_38 = V_58 - 1 ;
V_28 -> V_59 . V_75 = V_76 ;
V_28 -> V_59 . V_77 = F_13 ;
V_28 -> V_59 . V_78 = F_14 ;
V_28 -> V_59 . V_79 = F_15 ;
V_28 -> V_59 . V_80 = F_16 ;
V_28 -> V_59 . V_81 = F_17 ;
V_28 -> V_59 . V_82 = F_22 ;
V_28 -> V_59 . V_83 = F_23 ;
V_28 -> V_59 . V_84 = F_28 ;
V_28 -> V_59 . V_29 = V_28 ;
V_44 = F_46 ( V_70 -> V_85 ,
& V_28 -> V_59 ,
0 ,
1 ) ;
if ( 0 != V_44 )
goto V_73;
V_17 -> V_28 [ V_58 - 1 ] = V_28 ;
F_42 ( V_70 , V_58 ) ;
if ( V_17 -> V_74 ) {
F_47 ( & V_17 -> V_46 , F_24 ) ;
V_17 -> V_74 = 0 ;
}
F_12 ( L_20 , V_40 ) ;
F_10 ( & V_17 -> V_33 ) ;
F_8 ( V_17 , V_86 , 0x0 , 0 ) ;
F_8 ( V_17 , V_87 , 0x0 , 0 ) ;
V_30 = F_8 ( V_17 , V_88 , 0 , V_37 ) ;
V_30 |= ( 3 << 4 ) ;
F_8 ( V_17 , V_88 , V_30 , 0 ) ;
V_44 = F_8 ( V_17 , V_89 , 0 , V_37 ) ;
F_8 ( V_17 , V_47 , 0x44 , 0 ) ;
F_11 ( & V_17 -> V_33 ) ;
F_12 ( L_21 , V_40 , V_44 ) ;
F_27 ( & V_17 -> V_46 ) ;
return 0 ;
V_73:
F_12 ( L_22 , V_40 , V_44 ) ;
F_5 ( V_28 ) ;
return V_44 ;
}
int F_48 ( void * V_2 , int V_58 )
{
struct V_1 * V_8 = F_1 ( V_2 ) ;
struct V_7 * V_17 = NULL ;
T_1 V_30 ;
F_12 ( L_6 , V_40 ) ;
if ( V_8 == NULL )
return - 1 ;
if ( V_8 -> V_5 == NULL )
return - 1 ;
V_17 = V_8 -> V_5 ;
F_10 ( & V_17 -> V_33 ) ;
V_30 = F_8 ( V_17 , V_88 , 0 , V_37 ) ;
V_30 &= ~ ( 4 << ( 2 - V_58 ) ) ;
F_8 ( V_17 , V_88 , V_30 , 0 ) ;
F_49 ( 100 ) ;
V_30 |= ( 4 << ( 2 - V_58 ) ) ;
F_8 ( V_17 , V_88 , V_30 , 0 ) ;
F_11 ( & V_17 -> V_33 ) ;
return 0 ;
}
