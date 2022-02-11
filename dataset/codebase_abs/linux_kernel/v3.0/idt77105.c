static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
F_2 ( V_3 , V_5 ) ;
V_4 = F_3 ( V_6 ) ;
V_4 |= F_3 ( V_7 ) << 8 ;
return V_4 ;
}
static void F_4 ( unsigned long V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_5 ( L_1 ) ;
for ( V_10 = V_13 ; V_10 ; V_10 = V_10 -> V_14 ) {
V_2 = V_10 -> V_2 ;
V_12 = & V_10 -> V_12 ;
V_12 -> V_15 += F_1 ( V_2 , V_16 ) ;
V_12 -> V_17 += F_1 ( V_2 , V_18 ) ;
V_12 -> V_19 += F_1 ( V_2 , V_20 ) ;
V_12 -> V_21 += F_1 ( V_2 , V_22 ) ;
}
if ( ! V_23 ) F_6 ( & V_24 , V_25 + V_26 ) ;
}
static void F_7 ( unsigned long V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned char V_27 ;
F_5 ( L_2 ) ;
for ( V_10 = V_13 ; V_10 ; V_10 = V_10 -> V_14 ) {
V_2 = V_10 -> V_2 ;
if ( V_2 -> signal != V_28 )
continue;
V_27 = F_3 ( V_29 ) ;
if ( V_27 & V_30 ) {
F_8 ( V_2 , V_31 ) ;
F_9 ( V_32 L_3 ,
V_2 -> type , V_2 -> V_33 ) ;
F_2 ( F_3 ( V_34 ) | V_35 , V_34 ) ;
F_2 ( V_10 -> V_36 , V_37 ) ;
}
}
if ( ! V_23 ) F_6 ( & V_38 , V_25 + V_39 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_11 T_2 * V_40 , int V_41 )
{
unsigned long V_42 ;
struct V_11 V_12 ;
F_11 ( & V_43 , V_42 ) ;
memcpy ( & V_12 , & F_12 ( V_2 ) -> V_12 , sizeof( struct V_11 ) ) ;
if ( V_41 )
memset ( & F_12 ( V_2 ) -> V_12 , 0 , sizeof( struct V_11 ) ) ;
F_13 ( & V_43 , V_42 ) ;
if ( V_40 == NULL )
return 0 ;
return F_14 ( V_40 , & V_12 ,
sizeof( struct V_11 ) ) ? - V_44 : 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_45 )
{
int V_46 ;
V_46 = F_3 ( V_34 ) & ~ V_47 ;
switch ( V_45 ) {
case V_48 :
break;
case V_49 :
V_46 |= V_50 ;
break;
case V_51 :
V_46 |= V_52 ;
break;
default:
return - V_53 ;
}
F_2 ( V_46 , V_34 ) ;
F_9 ( V_32 L_4 , V_2 -> type ,
V_2 -> V_33 ,
( V_45 == V_48 ? L_5 :
( V_45 == V_49 ? L_6 :
( V_45 == V_52 ? L_7 :
L_8 ) ) )
) ;
F_12 ( V_2 ) -> V_54 = V_45 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_55 , void T_2 * V_40 )
{
F_9 ( V_32 L_9 , V_2 -> type , V_2 -> V_33 ) ;
switch ( V_55 ) {
case V_56 :
if ( ! F_17 ( V_57 ) ) return - V_58 ;
case V_59 :
return F_10 ( V_2 , V_40 , V_55 == V_56 ) ;
case V_60 :
return F_15 ( V_2 , ( int ) ( unsigned long ) V_40 ) ;
case V_61 :
return F_18 ( F_12 ( V_2 ) -> V_54 , ( int T_2 * ) V_40 ) ?
- V_44 : 0 ;
case V_62 :
return F_18 ( V_49 | V_51 ,
( int T_2 * ) V_40 ) ? - V_44 : 0 ;
default:
return - V_63 ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned char V_27 ;
V_27 = F_3 ( V_29 ) ;
F_5 ( L_10 , ( unsigned ) V_27 ) ;
if ( V_27 & V_64 ) {
if ( V_27 & V_30 ) {
F_8 ( V_2 , V_31 ) ;
} else {
F_12 ( V_2 ) -> V_36 = F_3 ( V_37 ) ;
F_2 (
( F_12 ( V_2 ) -> V_36 |
V_65 |
V_66 |
V_67
) & ~ V_68 , V_37 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_32 L_11 ,
V_2 -> type , V_2 -> V_33 ) ;
}
}
if ( V_27 & V_69 ) {
F_2 ( F_3 ( V_34 ) | V_35 , V_34 ) ;
F_9 ( V_32 L_12 ,
V_2 -> type , V_2 -> V_33 ) ;
}
#ifdef F_20
if ( V_27 & ( V_70 | V_71 |
V_72 ) ) {
F_9 ( V_32 L_13 ,
V_2 -> type , V_2 -> V_33 ) ;
}
#endif
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned long V_42 ;
if ( ! ( V_2 -> V_73 = F_22 ( sizeof( struct V_9 ) , V_74 ) ) )
return - V_75 ;
F_12 ( V_2 ) -> V_2 = V_2 ;
F_11 ( & V_43 , V_42 ) ;
F_12 ( V_2 ) -> V_14 = V_13 ;
V_13 = F_12 ( V_2 ) ;
F_13 ( & V_43 , V_42 ) ;
memset ( & F_12 ( V_2 ) -> V_12 , 0 , sizeof( struct V_11 ) ) ;
F_8 ( V_2 ,
F_3 ( V_29 ) & V_30 ?
V_31 : V_28 ) ;
if ( V_2 -> signal == V_28 )
F_9 ( V_76 L_14 , V_2 -> type ,
V_2 -> V_33 ) ;
switch ( F_3 ( V_34 ) & V_47 ) {
case V_77 :
F_12 ( V_2 ) -> V_54 = V_48 ;
break;
case V_50 :
F_12 ( V_2 ) -> V_54 = V_49 ;
break;
case V_52 :
F_12 ( V_2 ) -> V_54 = V_51 ;
break;
}
F_12 ( V_2 ) -> V_36 = F_3 ( V_37 ) ;
if ( V_2 -> signal == V_31 ) {
F_12 ( V_2 ) -> V_36 |= V_68 ;
F_2 ( F_12 ( V_2 ) -> V_36 , V_37 ) ;
}
F_4 ( 0 ) ;
( void ) F_10 ( V_2 , NULL , 1 ) ;
F_11 ( & V_43 , V_42 ) ;
if ( V_23 ) {
V_23 = 0 ;
F_23 ( & V_24 ) ;
V_24 . V_78 = V_25 + V_26 ;
V_24 . V_79 = F_4 ;
F_24 ( & V_24 ) ;
F_23 ( & V_38 ) ;
V_38 . V_78 = V_25 + V_39 ;
V_38 . V_79 = F_7 ;
F_24 ( & V_38 ) ;
}
F_13 ( & V_43 , V_42 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_80 ;
F_5 ( L_15 , V_2 -> type , V_2 -> V_33 ) ;
F_2 ( F_3 ( V_37 ) & ~ V_68 , V_37 ) ;
for ( V_80 = NULL , V_10 = V_13 ;
V_10 != NULL ;
V_80 = V_10 , V_10 = V_10 -> V_14 ) {
if ( V_10 -> V_2 == V_2 ) {
if ( V_80 != NULL )
V_80 -> V_14 = V_10 -> V_14 ;
else
V_13 = V_10 -> V_14 ;
V_2 -> V_81 = NULL ;
V_2 -> V_73 = NULL ;
F_26 ( V_10 ) ;
break;
}
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
V_2 -> V_81 = & V_82 ;
return 0 ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_24 ) ;
F_29 ( & V_38 ) ;
}
