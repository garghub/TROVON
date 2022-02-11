static inline T_1
F_1 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 )
{
register T_1 V_4 ;
F_2 ( V_1 , V_3 ) ;
V_4 = F_3 ( V_2 ) ;
return ( V_4 ) ;
}
static inline void
F_4 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 , T_1 * V_5 , int V_6 )
{
F_2 ( V_1 , V_3 ) ;
F_5 ( V_2 , V_5 , V_6 ) ;
}
static inline void
F_6 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 , T_1 V_5 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_5 ) ;
}
static inline void
F_7 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 , T_1 * V_5 , int V_6 )
{
F_2 ( V_1 , V_3 ) ;
F_8 ( V_2 , V_5 , V_6 ) ;
}
static T_1
F_9 ( struct V_7 * V_8 , T_1 V_9 )
{
return ( F_1 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_9 ) ) ;
}
static void
F_10 ( struct V_7 * V_8 , T_1 V_9 , T_1 V_14 )
{
F_6 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_9 , V_14 ) ;
}
static void
F_11 ( struct V_7 * V_8 , T_1 * V_5 , int V_6 )
{
F_4 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , 0 , V_5 , V_6 ) ;
}
static void
F_12 ( struct V_7 * V_8 , T_1 * V_5 , int V_6 )
{
F_7 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , 0 , V_5 , V_6 ) ;
}
static T_1
F_13 ( struct V_7 * V_8 , int V_15 , T_1 V_9 )
{
return ( F_1 ( V_8 -> V_10 . V_11 . V_16 ,
V_8 -> V_10 . V_11 . V_15 , V_9 + ( V_15 ? 0x40 : 0 ) ) ) ;
}
static void
F_14 ( struct V_7 * V_8 , int V_15 , T_1 V_9 , T_1 V_14 )
{
F_6 ( V_8 -> V_10 . V_11 . V_16 ,
V_8 -> V_10 . V_11 . V_15 , V_9 + ( V_15 ? 0x40 : 0 ) , V_14 ) ;
}
static T_2
F_15 ( int V_17 , void * V_18 )
{
struct V_7 * V_8 = V_18 ;
T_1 V_19 ;
T_3 V_20 ;
F_16 ( & V_8 -> V_21 , V_20 ) ;
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_22 + 0x40 ) ;
V_23:
if ( V_19 )
F_17 ( V_8 , V_19 ) ;
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_24 ) ;
V_25:
if ( V_19 )
F_18 ( V_8 , V_19 ) ;
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_22 + 0x40 ) ;
if ( V_19 ) {
if ( V_8 -> V_26 & V_27 )
F_19 ( V_8 , L_1 ) ;
goto V_23;
}
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_24 ) ;
if ( V_19 ) {
if ( V_8 -> V_26 & V_28 )
F_19 ( V_8 , L_2 ) ;
goto V_25;
}
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_29 , 0xFF ) ;
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_29 + 0x40 , 0xFF ) ;
F_6 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_30 , 0xFF ) ;
F_6 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_30 , 0 ) ;
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_29 , 0 ) ;
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_29 + 0x40 , 0 ) ;
F_20 ( & V_8 -> V_21 , V_20 ) ;
return V_31 ;
}
static void
F_21 ( struct V_7 * V_8 )
{
if ( V_8 -> V_10 . V_11 . V_32 )
F_22 ( V_8 -> V_10 . V_11 . V_32 , 4 ) ;
}
static void
F_23 ( struct V_7 * V_8 )
{
int V_33 ;
V_33 = 3 * ( V_34 / 10 ) + 1 ;
while ( V_33 -- ) {
F_2 ( V_8 -> V_10 . V_11 . V_32 + V_35 , 1 ) ;
F_24 ( 1 ) ;
}
F_2 ( V_8 -> V_10 . V_11 . V_32 + V_35 , 0 ) ;
}
static int
F_25 ( struct V_7 * V_8 , int V_36 , void * V_37 )
{
T_3 V_20 ;
switch ( V_36 ) {
case V_38 :
F_16 ( & V_8 -> V_21 , V_20 ) ;
F_23 ( V_8 ) ;
F_20 ( & V_8 -> V_21 , V_20 ) ;
return ( 0 ) ;
case V_39 :
F_21 ( V_8 ) ;
return ( 0 ) ;
case V_40 :
F_16 ( & V_8 -> V_21 , V_20 ) ;
F_23 ( V_8 ) ;
F_26 ( V_8 , 3 ) ;
F_20 ( & V_8 -> V_21 , V_20 ) ;
return ( 0 ) ;
case V_41 :
return ( 0 ) ;
}
return ( 0 ) ;
}
int T_4
F_27 ( struct V_42 * V_43 )
{
struct V_7 * V_8 = V_43 -> V_8 ;
char V_44 [ 64 ] ;
strcpy ( V_44 , V_45 ) ;
F_28 ( V_46 L_3 , F_29 ( V_44 ) ) ;
if ( V_8 -> V_47 != V_48 )
return ( 0 ) ;
#ifdef F_30
if ( ! V_43 -> V_49 [ 1 ] && F_31 () ) {
struct V_50 * V_51 ;
while( V_52 -> V_53 ) {
if ( ( V_54 = F_32 ( V_52 -> V_53 ,
V_52 -> V_55 , V_54 ) ) ) {
V_51 = NULL ;
if ( ( V_51 = F_33 ( V_54 ,
V_52 -> V_56 , V_52 -> V_57 , V_51 ) ) ) {
int V_58 ;
F_28 ( V_46 L_4 ,
( char * ) V_52 -> V_59 ) ;
F_34 ( V_51 ) ;
V_58 = F_35 ( V_51 ) ;
if ( V_58 < 0 ) {
F_28 ( V_60 L_5 ,
V_61 , V_58 ) ;
return ( 0 ) ;
}
V_43 -> V_49 [ 1 ] = F_36 ( V_51 , 0 ) ;
V_43 -> V_49 [ 0 ] = F_37 ( V_51 , 0 ) ;
if ( ! V_43 -> V_49 [ 0 ] || ! V_43 -> V_49 [ 1 ] ) {
F_28 ( V_62 L_6 ,
V_43 -> V_49 [ 0 ] , V_43 -> V_49 [ 1 ] ) ;
F_34 ( V_51 ) ;
return ( 0 ) ;
}
break;
} else {
F_28 ( V_62 L_7 ) ;
}
}
V_52 ++ ;
V_54 = NULL ;
}
if ( ! V_52 -> V_53 ) {
F_28 ( V_46 L_8 ) ;
return ( 0 ) ;
}
}
#endif
V_8 -> V_10 . V_11 . V_12 = V_43 -> V_49 [ 1 ] + V_63 ;
V_8 -> V_10 . V_11 . V_16 = V_43 -> V_49 [ 1 ] + V_64 ;
V_8 -> V_10 . V_11 . V_13 = V_43 -> V_49 [ 1 ] + V_65 ;
V_8 -> V_10 . V_11 . V_15 = V_43 -> V_49 [ 1 ] + V_66 ;
V_8 -> V_10 . V_11 . V_32 = V_43 -> V_49 [ 1 ] ;
V_8 -> V_67 = V_43 -> V_49 [ 0 ] ;
if ( V_8 -> V_10 . V_11 . V_32 ) {
if ( ! F_38 ( V_8 -> V_10 . V_11 . V_32 , 4 , L_9 ) ) {
F_28 ( V_60
L_10
L_11 ,
V_8 -> V_10 . V_11 . V_32 ,
V_8 -> V_10 . V_11 . V_32 + 4 ) ;
return ( 0 ) ;
}
}
F_28 ( V_46 L_12 ,
V_8 -> V_67 , V_8 -> V_10 . V_11 . V_32 ) ;
F_39 ( V_8 ) ;
V_8 -> V_68 = & F_9 ;
V_8 -> V_69 = & F_10 ;
V_8 -> V_70 = & F_11 ;
V_8 -> V_71 = & F_12 ;
V_8 -> V_72 = & F_13 ;
V_8 -> V_73 = & F_14 ;
V_8 -> V_74 = & V_75 ;
V_8 -> V_76 = & F_25 ;
V_8 -> V_77 = & F_15 ;
F_40 ( V_8 , L_13 ) ;
if ( F_41 ( V_8 , L_13 ) ) {
F_28 ( V_60
L_14 ) ;
F_21 ( V_8 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
