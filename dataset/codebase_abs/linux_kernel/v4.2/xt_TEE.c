static struct V_1 * F_1 ( struct V_2 * V_3 )
{
#ifdef F_2
const struct V_4 * V_5 ;
if ( V_3 -> V_6 != NULL )
return F_3 ( V_3 -> V_6 ) ;
V_5 = F_4 ( V_3 ) ;
if ( V_5 != NULL && V_5 -> V_6 != NULL )
return F_3 ( V_5 -> V_6 ) ;
#endif
return & V_7 ;
}
static bool
F_5 ( struct V_2 * V_3 , const struct V_8 * V_9 )
{
const struct V_10 * V_11 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_12 * V_13 ;
struct V_14 V_15 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
if ( V_9 -> V_16 ) {
if ( V_9 -> V_16 -> V_17 == - 1 )
return false ;
V_15 . V_18 = V_9 -> V_16 -> V_17 ;
}
V_15 . V_19 = V_9 -> V_20 . V_21 ;
V_15 . V_22 = F_7 ( V_11 -> V_23 ) ;
V_15 . V_24 = V_25 ;
V_15 . V_26 = V_27 ;
V_13 = F_8 ( V_1 , & V_15 ) ;
if ( F_9 ( V_13 ) )
return false ;
F_10 ( V_3 ) ;
F_11 ( V_3 , & V_13 -> V_5 ) ;
V_3 -> V_6 = V_13 -> V_5 . V_6 ;
V_3 -> V_28 = F_12 ( V_29 ) ;
return true ;
}
static unsigned int
F_13 ( struct V_2 * V_3 , const struct V_30 * V_31 )
{
const struct V_8 * V_9 = V_31 -> V_32 ;
struct V_10 * V_11 ;
if ( F_14 ( V_33 ) )
return V_34 ;
V_3 = F_15 ( V_3 , V_35 ) ;
if ( V_3 == NULL )
return V_34 ;
#ifdef F_16
F_17 ( V_3 -> V_36 ) ;
V_3 -> V_36 = & F_18 () -> V_37 ;
V_3 -> V_38 = V_39 ;
F_19 ( V_3 -> V_36 ) ;
#endif
V_11 = F_6 ( V_3 ) ;
V_11 -> V_40 |= F_12 ( V_41 ) ;
if ( V_31 -> V_42 == V_43 ||
V_31 -> V_42 == V_44 )
-- V_11 -> V_45 ;
F_20 ( V_11 ) ;
if ( F_5 ( V_3 , V_9 ) ) {
F_21 ( V_33 , true ) ;
F_22 ( V_3 ) ;
F_21 ( V_33 , false ) ;
} else {
F_23 ( V_3 ) ;
}
return V_34 ;
}
static bool
F_24 ( struct V_2 * V_3 , const struct V_8 * V_9 )
{
const struct V_46 * V_11 = F_25 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
struct V_47 V_48 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
if ( V_9 -> V_16 ) {
if ( V_9 -> V_16 -> V_17 == - 1 )
return false ;
V_48 . V_49 = V_9 -> V_16 -> V_17 ;
}
V_48 . V_19 = V_9 -> V_20 . V_50 ;
V_48 . V_51 = ( ( V_11 -> V_52 [ 0 ] & 0xF ) << 16 ) |
( V_11 -> V_52 [ 1 ] << 8 ) | V_11 -> V_52 [ 2 ] ;
V_48 . V_53 = V_27 ;
V_5 = F_26 ( V_1 , NULL , & V_48 ) ;
if ( V_5 -> error ) {
F_27 ( V_5 ) ;
return false ;
}
F_10 ( V_3 ) ;
F_11 ( V_3 , V_5 ) ;
V_3 -> V_6 = V_5 -> V_6 ;
V_3 -> V_28 = F_12 ( V_54 ) ;
return true ;
}
static unsigned int
F_28 ( struct V_2 * V_3 , const struct V_30 * V_31 )
{
const struct V_8 * V_9 = V_31 -> V_32 ;
if ( F_14 ( V_33 ) )
return V_34 ;
V_3 = F_15 ( V_3 , V_35 ) ;
if ( V_3 == NULL )
return V_34 ;
#ifdef F_16
F_17 ( V_3 -> V_36 ) ;
V_3 -> V_36 = & F_18 () -> V_37 ;
V_3 -> V_38 = V_39 ;
F_19 ( V_3 -> V_36 ) ;
#endif
if ( V_31 -> V_42 == V_43 ||
V_31 -> V_42 == V_44 ) {
struct V_46 * V_11 = F_25 ( V_3 ) ;
-- V_11 -> V_55 ;
}
if ( F_24 ( V_3 , V_9 ) ) {
F_21 ( V_33 , true ) ;
F_29 ( V_3 ) ;
F_21 ( V_33 , false ) ;
} else {
F_23 ( V_3 ) ;
}
return V_34 ;
}
static int F_30 ( struct V_56 * V_57 , unsigned long V_58 ,
void * V_59 )
{
struct V_60 * V_6 = F_31 ( V_59 ) ;
struct V_61 * V_16 ;
V_16 = F_32 ( V_57 , struct V_61 , V_62 ) ;
switch ( V_58 ) {
case V_63 :
if ( ! strcmp ( V_6 -> V_64 , V_16 -> V_65 -> V_17 ) )
V_16 -> V_17 = V_6 -> V_66 ;
break;
case V_67 :
if ( V_6 -> V_66 == V_16 -> V_17 )
V_16 -> V_17 = - 1 ;
break;
case V_68 :
if ( ! strcmp ( V_6 -> V_64 , V_16 -> V_65 -> V_17 ) )
V_16 -> V_17 = V_6 -> V_66 ;
else if ( V_6 -> V_66 == V_16 -> V_17 )
V_16 -> V_17 = - 1 ;
break;
}
return V_69 ;
}
static int F_33 ( const struct V_70 * V_31 )
{
struct V_8 * V_9 = V_31 -> V_32 ;
struct V_61 * V_16 ;
if ( memcmp ( & V_9 -> V_20 , & V_71 ,
sizeof( V_71 ) ) == 0 )
return - V_72 ;
if ( V_9 -> V_17 [ 0 ] ) {
if ( V_9 -> V_17 [ sizeof( V_9 -> V_17 ) - 1 ] != '\0' )
return - V_72 ;
V_16 = F_34 ( sizeof( * V_16 ) , V_73 ) ;
if ( V_16 == NULL )
return - V_74 ;
V_16 -> V_65 = V_9 ;
V_16 -> V_17 = - 1 ;
V_16 -> V_62 . V_75 = F_30 ;
V_9 -> V_16 = V_16 ;
F_35 ( & V_16 -> V_62 ) ;
} else
V_9 -> V_16 = NULL ;
return 0 ;
}
static void F_36 ( const struct V_76 * V_31 )
{
struct V_8 * V_9 = V_31 -> V_32 ;
if ( V_9 -> V_16 ) {
F_37 ( & V_9 -> V_16 -> V_62 ) ;
F_38 ( V_9 -> V_16 ) ;
}
}
static int T_1 F_39 ( void )
{
return F_40 ( V_77 , F_41 ( V_77 ) ) ;
}
static void T_2 F_42 ( void )
{
F_43 ( V_77 , F_41 ( V_77 ) ) ;
}
