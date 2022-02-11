static inline unsigned long
F_1 ( int V_1 , unsigned int V_2 , unsigned int type )
{
unsigned long V_3 ;
V_3 = ( V_2 | type ) & 0xf ;
V_3 <<= ( V_4 + V_1 * V_5 ) ;
V_3 |= ( V_6 << ( V_1 * V_7 ) ) ;
return V_3 ;
}
unsigned long F_2 ( int V_1 , unsigned int V_2 , unsigned int type )
{
return F_1 ( V_1 , V_2 , type ) | V_8 ;
}
int F_3 ( unsigned long V_9 , int V_10 , unsigned * V_2 , unsigned * type )
{
int V_3 = V_9 >> ( V_4 + V_10 * V_5 ) ;
* V_2 = ( V_3 & 0xc ) | 0x40 ;
* type = ( V_3 & 0x3 ) | 0x80 ;
return ( V_9 >> ( V_10 * V_7 ) ) & 0x3 ;
}
int F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
unsigned long * V_9 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
struct V_11 * * V_17 = F_6 ( & V_18 [ V_15 ] ) ;
if ( ! * V_17 ) {
* V_17 = V_12 ;
break;
}
}
if ( F_7 ( V_15 == V_16 , L_1 ) )
return - V_19 ;
F_8 ( V_14 -> V_20 , V_15 ) ;
F_9 ( V_21 [ V_15 ] , V_14 -> V_20 ) ;
V_9 = F_6 ( & V_22 ) ;
* V_9 |= F_2 ( V_15 , V_14 -> V_2 , V_14 -> type ) ;
F_8 ( * V_9 , 7 ) ;
if ( V_14 -> V_23 )
F_10 ( V_14 -> V_23 , V_15 ) ;
return 0 ;
}
void F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
unsigned long * V_9 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
struct V_11 * * V_17 = F_6 ( & V_18 [ V_15 ] ) ;
if ( * V_17 == V_12 ) {
* V_17 = NULL ;
break;
}
}
if ( F_7 ( V_15 == V_16 , L_1 ) )
return;
V_9 = F_6 ( & V_22 ) ;
* V_9 &= ~ F_1 ( V_15 , V_14 -> V_2 , V_14 -> type ) ;
F_8 ( * V_9 , 7 ) ;
if ( V_14 -> V_23 )
F_10 ( 0 , V_15 ) ;
}
int F_12 ( struct V_11 * V_12 )
{
unsigned int V_2 ;
unsigned long V_24 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_24 = V_14 -> V_20 ;
V_2 = V_12 -> V_25 . V_26 ;
return ( V_24 >= V_27 ) || ( ( V_24 + V_2 - 1 ) >= V_27 ) ;
}
int F_13 ( int V_28 , int V_29 ,
int * V_30 , int * V_31 )
{
switch ( V_29 ) {
case V_32 :
if ( V_28 != V_33 )
return - V_34 ;
* V_31 = V_35 ;
* V_30 = sizeof( long ) ;
return 0 ;
case V_36 :
* V_31 = V_37 ;
break;
case V_38 :
* V_31 = V_37 | V_39 ;
break;
default:
return - V_34 ;
}
switch ( V_28 ) {
case V_40 :
* V_30 = V_41 ;
break;
case V_42 :
* V_30 = V_43 ;
break;
case V_44 :
* V_30 = V_45 ;
break;
#ifdef F_14
case V_46 :
* V_30 = V_47 ;
break;
#endif
default:
return - V_34 ;
}
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_14 -> V_20 = V_12 -> V_25 . V_48 ;
switch ( V_12 -> V_25 . V_49 ) {
case V_37 :
V_14 -> type = V_36 ;
break;
case V_37 | V_39 :
V_14 -> type = V_38 ;
break;
case V_35 :
if ( V_12 -> V_25 . V_48 >= V_27 ) {
#ifdef F_16
if ( F_17 ( V_12 -> V_25 . V_48 ) )
return - V_34 ;
#else
return - V_34 ;
#endif
}
V_14 -> type = V_32 ;
if ( V_12 -> V_25 . V_26 == sizeof( long ) ) {
V_14 -> V_2 = V_33 ;
return 0 ;
}
default:
return - V_34 ;
}
V_14 -> V_23 = 0 ;
switch ( V_12 -> V_25 . V_26 ) {
case V_41 :
V_14 -> V_2 = V_40 ;
break;
case V_43 :
V_14 -> V_2 = V_42 ;
break;
case V_45 :
V_14 -> V_2 = V_44 ;
break;
#ifdef F_14
case V_47 :
V_14 -> V_2 = V_46 ;
break;
#endif
default:
if ( ! F_18 ( V_12 -> V_25 . V_26 ) )
return - V_34 ;
if ( V_12 -> V_25 . V_48 & ( V_12 -> V_25 . V_26 - 1 ) )
return - V_34 ;
if ( ! F_19 ( V_50 ) )
return - V_51 ;
V_14 -> V_23 = V_12 -> V_25 . V_26 - 1 ;
V_14 -> V_2 = V_40 ;
}
return 0 ;
}
int F_20 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
unsigned int V_52 ;
int V_53 ;
V_53 = F_15 ( V_12 ) ;
if ( V_53 )
return V_53 ;
switch ( V_14 -> V_2 ) {
case V_40 :
V_52 = 0 ;
if ( V_14 -> V_23 )
V_52 = V_14 -> V_23 ;
break;
case V_42 :
V_52 = 1 ;
break;
case V_44 :
V_52 = 3 ;
break;
#ifdef F_14
case V_46 :
V_52 = 7 ;
break;
#endif
default:
F_21 ( 1 ) ;
}
if ( V_14 -> V_20 & V_52 )
return - V_34 ;
return 0 ;
}
void F_22 ( struct V_54 * V_55 )
{
int V_15 ;
int V_9 = 0 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_56 * V_57 = & V_58 -> V_57 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_12 = V_57 -> V_59 [ V_15 ] ;
if ( V_12 && ! V_12 -> V_25 . V_60 ) {
V_55 -> V_61 [ V_15 ] = V_12 -> V_25 . V_48 ;
V_14 = F_5 ( V_12 ) ;
V_9 |= F_2 ( V_15 , V_14 -> V_2 , V_14 -> type ) ;
} else {
V_55 -> V_61 [ V_15 ] = 0 ;
}
}
V_55 -> V_61 [ 4 ] = 0 ;
V_55 -> V_61 [ 5 ] = 0 ;
V_55 -> V_61 [ 6 ] = V_58 -> V_57 . V_62 ;
V_55 -> V_61 [ 7 ] = V_9 ;
}
void F_23 ( struct V_63 * V_64 )
{
int V_15 ;
struct V_56 * V_65 = & V_64 -> V_57 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
F_24 ( V_65 -> V_59 [ V_15 ] ) ;
V_65 -> V_59 [ V_15 ] = NULL ;
}
V_65 -> V_62 = 0 ;
V_65 -> V_66 = 0 ;
}
void F_25 ( void )
{
F_8 ( F_26 ( V_21 [ 0 ] ) , 0 ) ;
F_8 ( F_26 ( V_21 [ 1 ] ) , 1 ) ;
F_8 ( F_26 ( V_21 [ 2 ] ) , 2 ) ;
F_8 ( F_26 ( V_21 [ 3 ] ) , 3 ) ;
F_8 ( V_58 -> V_57 . V_62 , 6 ) ;
F_8 ( F_26 ( V_22 ) , 7 ) ;
}
static int F_27 ( struct V_67 * args )
{
int V_15 , V_68 , V_69 = V_70 ;
struct V_11 * V_12 ;
unsigned long V_9 , V_71 ;
unsigned long * V_72 ;
V_72 = ( unsigned long * ) F_28 ( args -> V_73 ) ;
V_71 = * V_72 ;
if ( V_71 & V_74 )
return V_75 ;
if ( ( V_71 & V_76 ) == 0 )
return V_75 ;
F_29 ( V_9 , 7 ) ;
F_8 ( 0UL , 7 ) ;
V_58 -> V_57 . V_62 &= ~ V_76 ;
V_68 = F_30 () ;
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
if ( F_31 ( ! ( V_71 & ( V_77 << V_15 ) ) ) )
continue;
F_32 () ;
V_12 = F_33 ( V_18 [ V_15 ] , V_68 ) ;
( * V_72 ) &= ~ ( V_77 << V_15 ) ;
if ( ! V_12 ) {
F_34 () ;
break;
}
F_35 ( V_12 , args -> V_78 ) ;
if ( V_12 -> V_79 . V_14 . type == V_32 )
args -> V_78 -> V_80 |= V_81 ;
F_34 () ;
}
if ( ( V_58 -> V_57 . V_62 & V_76 ) ||
( V_71 & ( ~ V_76 ) ) )
V_69 = V_75 ;
F_8 ( V_9 , 7 ) ;
F_36 () ;
return V_69 ;
}
int F_37 (
struct V_82 * V_83 , unsigned long V_84 , void * V_85 )
{
if ( V_84 != V_86 )
return V_75 ;
return F_27 ( V_85 ) ;
}
void F_38 ( struct V_11 * V_12 )
{
}
