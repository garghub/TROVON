static int
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
struct V_5 * * V_6 )
{
struct V_5 * V_5 = NULL ;
* V_6 = NULL ;
for ( V_5 = F_2 ( V_7 , V_8 , NULL ) ;
V_5 != NULL ;
V_5 = F_2 ( V_7 ,
V_8 , V_5 ) ) {
if ( V_3 || V_4 ) {
if ( V_3 != V_5 -> V_3 -> V_9
|| V_4 != F_3 ( V_5 -> V_10 ) )
continue;
}
if ( V_11 -> V_12 == V_13 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < F_4 ( V_15 ) ; V_14 ++ ) {
if ( V_15 [ V_14 ] . V_16 != V_17 )
continue;
if ( V_5 -> V_18 == V_15 [ V_14 ] . V_19 ) {
V_2 -> V_20 = & V_15 [ V_14 ] ;
break;
}
}
if ( V_14 == F_4 ( V_15 ) )
continue;
} else {
if ( V_5 -> V_18 != V_11 -> V_19 )
continue;
}
* V_6 = V_5 ;
return 0 ;
}
if ( V_3 || V_4 ) {
F_5 ( V_21
L_1 ,
V_2 -> V_22 , V_11 -> V_23 , V_3 , V_4 ) ;
} else {
F_5 ( V_21 L_2 ,
V_2 -> V_22 , V_11 -> V_23 ) ;
}
return - V_24 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_27 * V_28 ;
unsigned long V_29 = 0 ;
#ifdef F_7
struct V_5 * V_5 = NULL ;
int V_3 = 0 , V_4 = 0 ;
#endif
int V_30 ;
F_5 ( V_31 L_3 , V_2 -> V_22 ,
V_32 ) ;
#ifdef F_7
V_30 = F_8 ( V_2 , sizeof( struct V_33 ) ) ;
if ( V_30 < 0 ) {
F_5 ( V_21 L_4 ,
V_2 -> V_22 ) ;
return V_30 ;
}
#endif
switch ( V_11 -> V_16 ) {
case V_34 :
V_29 = V_26 -> V_35 [ 0 ] ;
break;
#ifdef F_7
case V_17 :
V_3 = V_26 -> V_35 [ 0 ] ;
V_4 = V_26 -> V_35 [ 1 ] ;
V_30 = F_1 ( V_2 , V_3 , V_4 , & V_5 ) ;
if ( V_30 < 0 )
return V_30 ;
V_36 -> V_5 = V_5 ;
break;
#endif
default:
F_5 ( V_21
L_5 ,
V_2 -> V_22 , V_32 ) ;
return - V_37 ;
break;
}
V_2 -> V_38 = V_11 -> V_23 ;
#ifdef F_7
if ( V_5 ) {
V_30 = F_9 ( V_5 , V_32 ) ;
if ( V_30 < 0 ) {
F_5 ( V_21
L_6
L_7 ,
V_2 -> V_22 ) ;
return V_30 ;
}
V_29 = F_10 ( V_5 , 2 ) ;
} else
#endif
{
V_30 = F_11 ( V_2 -> V_22 , V_29 , V_39 ) ;
if ( V_30 < 0 )
return V_30 ;
}
V_2 -> V_29 = V_29 ;
V_30 = F_12 ( V_2 , 1 ) ;
if ( V_30 < 0 ) {
F_5 ( V_21 L_4 ,
V_2 -> V_22 ) ;
return V_30 ;
}
V_28 = V_2 -> V_40 + 0 ;
V_28 -> type = V_41 ;
V_28 -> V_42 = V_43 | V_44 ;
V_28 -> V_45 = 16 ;
V_28 -> V_46 = 1 ;
V_28 -> V_47 = & V_48 ;
V_28 -> V_49 = V_50 ;
V_28 -> V_51 = V_52 ;
V_28 -> V_53 = 0xffff ;
V_28 -> V_54 = F_13 ( V_2 -> V_29 ) ;
V_28 -> V_54 = V_28 -> V_54 | ( F_13 ( V_2 -> V_29 ) << 8 ) ;
F_5 ( V_55 L_8 , V_2 -> V_22 , V_2 -> V_38 ) ;
if ( V_11 -> V_16 == V_34 ) {
F_5 ( L_9 , V_29 ) ;
} else {
#ifdef F_7
F_5 ( L_10 , F_14 ( V_5 ) ) ;
#endif
}
F_5 ( L_11 ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_5 ( V_31 L_12 , V_2 -> V_22 ,
V_32 ) ;
#ifdef F_7
if ( V_36 ) {
#endif
#ifdef F_7
if ( V_36 -> V_5 ) {
if ( V_2 -> V_29 )
F_16 ( V_36 -> V_5 ) ;
F_17 ( V_36 -> V_5 ) ;
} else
#endif
{
if ( V_2 -> V_29 )
F_18 ( V_2 -> V_29 , V_39 ) ;
}
}
if ( V_2 -> V_38 ) {
F_5 ( V_55 L_13 ,
V_2 -> V_22 , V_2 -> V_38 ) ;
}
return 0 ;
}
static int F_11 ( unsigned V_22 , unsigned long V_56 ,
unsigned long V_57 )
{
if ( ! V_56 || ! F_19 ( V_56 , V_57 , V_32 ) ) {
F_5 ( V_21 L_14 ,
V_22 , V_56 , V_57 ) ;
return - V_24 ;
}
return 0 ;
}
static int V_50 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_58 * V_59 , unsigned int * V_60 )
{
if ( V_59 -> V_61 != 2 )
return - V_37 ;
if ( V_60 [ 0 ] ) {
V_28 -> V_54 &= ~ V_60 [ 0 ] ;
V_28 -> V_54 |= V_60 [ 0 ] & V_60 [ 1 ] ;
F_20 ( V_28 -> V_54 & 0xFF , V_2 -> V_29 ) ;
F_20 ( V_28 -> V_54 >> 8 , V_2 -> V_29 + 1 ) ;
}
V_60 [ 1 ] = V_28 -> V_54 ;
return 2 ;
}
static int V_52 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_58 * V_59 , unsigned int * V_60 )
{
if ( V_59 -> V_61 != 1 )
return - V_37 ;
return 1 ;
}
static int T_1 F_21 ( struct V_5 * V_2 ,
const struct V_62
* V_63 )
{
return F_22 ( V_2 , V_64 . V_65 ) ;
}
static void T_2 F_23 ( struct V_5 * V_2 )
{
F_24 ( V_2 ) ;
}
static int T_3 F_25 ( void )
{
int V_66 ;
V_66 = F_26 ( & V_64 ) ;
if ( V_66 < 0 )
return V_66 ;
V_67 . V_23 =
( char * ) V_64 . V_65 ;
return F_27 ( & V_67 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_67 ) ;
F_30 ( & V_64 ) ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_64 ) ;
}
static void T_4 F_28 ( void )
{
F_30 ( & V_64 ) ;
}
