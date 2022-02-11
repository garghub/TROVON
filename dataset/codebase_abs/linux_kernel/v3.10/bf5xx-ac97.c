void F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 , unsigned int V_5 )
{
while ( V_4 -- ) {
V_2 -> V_6 = V_7 ;
if ( V_5 & V_8 ) {
V_2 -> V_9 = * V_3 ++ ;
V_2 -> V_6 |= V_10 ;
}
if ( V_5 & V_11 ) {
V_2 -> V_12 = * V_3 ++ ;
V_2 -> V_6 |= V_13 ;
}
#if F_2 ( V_14 )
if ( V_5 & V_15 ) {
V_2 -> V_16 = * V_3 ++ ;
V_2 -> V_6 |= V_17 ;
}
if ( V_5 & V_18 ) {
V_2 -> V_19 = * V_3 ++ ;
V_2 -> V_6 |= V_20 ;
}
if ( V_5 & V_21 ) {
V_2 -> V_22 = * V_3 ++ ;
V_2 -> V_6 |= V_23 ;
}
if ( V_5 & V_24 ) {
V_2 -> V_25 = * V_3 ++ ;
V_2 -> V_6 |= V_26 ;
}
#endif
V_2 ++ ;
}
}
void F_3 ( const struct V_1 * V_3 , T_1 * V_2 ,
T_2 V_4 )
{
while ( V_4 -- ) {
* ( V_2 ++ ) = V_3 -> V_12 ;
* ( V_2 ++ ) = V_3 -> V_9 ;
V_3 ++ ;
}
}
static unsigned int F_4 ( struct V_27 * V_28 )
{
return V_28 -> V_29 = F_5 ( V_28 ) /
V_28 -> V_30 ;
}
static void F_6 ( struct V_31 * V_32 , T_1 V_33 , T_1 V_34 )
{
struct V_27 * V_28 = V_35 ;
int * V_36 = V_28 -> V_37 ;
int V_38 = F_4 ( V_28 ) ;
struct V_1 * V_39 ;
F_7 ( V_28 , & V_38 , 1 ) ;
V_39 = (struct V_1 * ) ( V_28 -> V_40 +
V_38 * V_28 -> V_30 ) ;
F_8 ( L_1 ,
V_28 -> V_40 , V_38 , V_39 , V_36 [ V_38 ] ) ;
V_39 [ V_36 [ V_38 ] ] . V_6 |= V_41 ;
V_39 [ V_36 [ V_38 ] ] . V_42 = V_33 ;
V_39 [ V_36 [ V_38 ] ] . V_43 = V_34 ;
++ V_36 [ V_38 ] ;
F_8 ( L_2 ,
V_33 >> 8 , V_34 , V_38 ) ;
}
static unsigned short F_9 ( struct V_31 * V_32 ,
unsigned short V_44 )
{
struct V_27 * V_45 = V_35 ;
struct V_1 V_46 [ 2 ] , V_47 [ 2 ] ;
F_8 ( L_3 , V_48 , V_44 ) ;
if ( V_45 -> V_49 || V_45 -> V_50 ) {
F_10 ( L_4
L_5 ) ;
return - V_51 ;
}
memset ( & V_46 , 0 , 2 * sizeof( struct V_1 ) ) ;
memset ( & V_47 , 0 , 2 * sizeof( struct V_1 ) ) ;
V_46 [ 0 ] . V_6 = V_7 | V_41 ;
V_46 [ 0 ] . V_42 = ( ( V_44 << 8 ) | 0x8000 ) ;
F_11 ( V_45 , ( unsigned char * ) & V_46 ,
( unsigned char * ) & V_47 ,
2 * sizeof( struct V_1 ) ) ;
return V_47 [ 1 ] . V_43 ;
}
void F_12 ( struct V_31 * V_32 , unsigned short V_44 ,
unsigned short V_52 )
{
struct V_27 * V_45 = V_35 ;
F_8 ( L_6 , V_48 , V_44 , V_52 ) ;
if ( V_45 -> V_49 ) {
F_6 ( V_32 , ( V_44 << 8 ) , V_52 ) ;
F_6 ( V_32 , ( V_44 << 8 ) | 0x8000 , 0 ) ;
} else {
struct V_1 V_53 ;
memset ( & V_53 , 0 , sizeof( struct V_1 ) ) ;
V_53 . V_6 = V_7 | V_41 ;
V_53 . V_42 = ( V_44 << 8 ) ;
V_53 . V_43 = V_52 ;
F_11 ( V_45 , ( unsigned char * ) & V_53 , \
NULL , sizeof( struct V_1 ) ) ;
}
}
static void F_13 ( struct V_31 * V_32 )
{
struct V_27 * V_45 = V_35 ;
T_3 V_54 = F_14 ( V_45 -> V_55 [ 3 ] ) ;
F_8 ( L_7 , V_48 ) ;
F_15 ( V_45 -> V_55 ) ;
F_16 ( V_54 , L_8 ) ;
F_17 ( V_54 , 1 ) ;
F_18 ( 2 ) ;
F_19 ( V_54 , 0 ) ;
F_18 ( 1 ) ;
F_20 ( V_54 ) ;
F_21 ( V_45 -> V_55 , L_9 ) ;
}
static void F_22 ( struct V_31 * V_32 )
{
#ifdef F_23
F_8 ( L_7 , V_48 ) ;
F_19 ( V_56 , 0 ) ;
F_24 ( 1 ) ;
F_19 ( V_56 , 1 ) ;
F_24 ( 1 ) ;
#else
F_25 ( L_10 , V_48 ) ;
#endif
}
static int F_26 ( struct V_57 * V_58 )
{
struct V_27 * V_28 = F_27 ( V_58 ) ;
F_8 ( L_11 , V_48 , V_58 -> V_59 ) ;
if ( ! V_58 -> V_60 )
return 0 ;
if ( V_58 -> V_61 )
F_28 ( V_28 ) ;
if ( V_58 -> V_62 )
F_29 ( V_28 ) ;
return 0 ;
}
static int F_30 ( struct V_57 * V_58 )
{
int V_63 ;
struct V_27 * V_28 = F_27 ( V_58 ) ;
F_8 ( L_11 , V_48 , V_58 -> V_59 ) ;
if ( ! V_58 -> V_60 )
return 0 ;
#if F_2 ( V_14 )
V_63 = F_31 ( V_28 , 16 , 0x3FF , 1 ) ;
#else
V_63 = F_31 ( V_28 , 16 , 0x1F , 1 ) ;
#endif
if ( V_63 ) {
F_10 ( L_12 ) ;
return - V_64 ;
}
V_63 = F_32 ( V_28 , V_65 , 0xF , 0 , ( 16 * 16 - 1 ) ) ;
if ( V_63 ) {
F_10 ( L_12 ) ;
return - V_64 ;
}
V_63 = F_33 ( V_28 , V_66 , 0xF , 0 , ( 16 * 16 - 1 ) ) ;
if ( V_63 ) {
F_10 ( L_12 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_34 ( struct V_67 * V_68 )
{
struct V_27 * V_45 ;
int V_63 ;
#ifdef F_23
if ( F_16 ( V_56 , L_13 ) ) {
F_10 ( L_14 ,
V_56 ) ;
V_63 = - 1 ;
goto V_69;
}
F_17 ( V_56 , 1 ) ;
#endif
V_45 = F_35 ( V_68 , 2 , sizeof( struct V_1 ) ,
V_70 ) ;
if ( ! V_45 ) {
V_63 = - V_71 ;
goto V_72;
}
#if F_2 ( V_14 )
V_63 = F_31 ( V_45 , 16 , 0x3FF , 1 ) ;
#else
V_63 = F_31 ( V_45 , 16 , 0x1F , 1 ) ;
#endif
if ( V_63 ) {
F_10 ( L_12 ) ;
V_63 = - V_64 ;
goto V_73;
}
V_63 = F_32 ( V_45 , V_65 , 0xF , 0 , ( 16 * 16 - 1 ) ) ;
if ( V_63 ) {
F_10 ( L_12 ) ;
V_63 = - V_64 ;
goto V_73;
}
V_63 = F_33 ( V_45 , V_66 , 0xF , 0 , ( 16 * 16 - 1 ) ) ;
if ( V_63 ) {
F_10 ( L_12 ) ;
V_63 = - V_64 ;
goto V_73;
}
V_63 = F_36 ( & V_68 -> V_74 , & V_75 ,
& V_76 , 1 ) ;
if ( V_63 ) {
F_10 ( L_15 , V_63 ) ;
goto V_73;
}
V_35 = V_45 ;
return 0 ;
V_73:
F_37 ( V_45 ) ;
V_72:
#ifdef F_23
F_20 ( V_56 ) ;
V_69:
#endif
return V_63 ;
}
static int F_38 ( struct V_67 * V_68 )
{
struct V_27 * V_45 = F_39 ( V_68 ) ;
F_40 ( & V_68 -> V_74 ) ;
F_37 ( V_45 ) ;
#ifdef F_23
F_20 ( V_56 ) ;
#endif
return 0 ;
}
