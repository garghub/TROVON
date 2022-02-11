int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_5 ;
return V_6 -> V_8 ? V_4 -> V_9 : 0 ;
}
int F_2 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_5 ;
if ( F_3 ( V_10 ) && V_6 -> V_8 )
return V_4 -> V_9 ;
else
return 0 ;
}
int F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
void * V_13 , void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
if ( ! F_3 ( V_10 ) )
return - V_15 ;
F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
return F_7 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_17 , 0 , - 1 ) ;
}
int F_8 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
const void * V_13 , const void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
int V_18 ;
if ( ! F_3 ( V_10 ) )
return - V_15 ;
F_9 ( V_5 ) ;
F_6 ( V_5 ) ;
V_18 = F_10 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_17 , 0 , - 1 ) ;
V_5 -> V_16 . V_17 . V_19 &= V_20 ;
if ( F_3 ( V_21 ) )
V_5 -> V_16 . V_22 . V_23 . V_24 |= V_25 ;
return V_18 ;
}
int F_11 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
void * V_13 , void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_26 * V_22 ;
int V_18 ;
if ( ! F_3 ( V_21 ) )
return - V_15 ;
F_5 ( V_5 ) ;
V_22 = & V_5 -> V_16 . V_22 ;
memcpy ( & V_22 -> V_27 . V_28 ,
V_29 , sizeof( V_29 ) ) ;
V_18 = F_7 ( & V_11 , & V_12 , & V_13 , & V_14 , V_22 , 0 , - 1 ) ;
return V_18 ;
}
int F_12 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
const void * V_13 , const void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_26 * V_22 ;
int V_18 ;
if ( ! F_3 ( V_21 ) )
return - V_15 ;
F_9 ( V_5 ) ;
V_22 = & V_5 -> V_16 . V_22 ;
V_18 = F_10 ( & V_11 , & V_12 , & V_13 , & V_14 , V_22 , 0 , - 1 ) ;
V_22 -> V_27 . V_19 &= V_20 ;
V_22 -> V_23 . V_24 &= V_30 ;
memset ( & V_22 -> V_23 . V_31 , 0 , 48 ) ;
return V_18 ;
}
static inline unsigned short F_13 ( unsigned short V_32 )
{
unsigned int V_33 ;
V_33 = ~ V_32 ;
V_33 = ( V_33 | ( V_33 >> 1 ) ) & 0x5555 ;
V_33 = ( V_33 | ( V_33 >> 1 ) ) & 0x3333 ;
V_33 = ( V_33 | ( V_33 >> 2 ) ) & 0x0f0f ;
V_33 = ( V_33 | ( V_33 >> 4 ) ) & 0x00ff ;
return V_33 ;
}
static inline T_2 F_14 ( struct V_34 * V_17 )
{
struct V_35 * V_36 ;
T_2 V_37 = ( V_17 -> V_38 >> 11 ) & 7 ;
T_2 V_32 = ( unsigned long ) V_17 -> V_32 ;
T_2 V_39 ;
T_2 V_18 = 0xffff0000u ;
int V_40 ;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ , V_32 >>= 1 ) {
if ( V_32 & 0x1 ) {
V_36 = F_15 ( V_17 , ( V_40 - V_37 ) & 7 ) ;
switch ( V_36 -> V_41 & 0x7fff ) {
case 0x7fff :
V_39 = V_42 ;
break;
case 0x0000 :
if ( ! V_36 -> V_43 [ 0 ] &&
! V_36 -> V_43 [ 1 ] &&
! V_36 -> V_43 [ 2 ] &&
! V_36 -> V_43 [ 3 ] )
V_39 = V_44 ;
else
V_39 = V_42 ;
break;
default:
if ( V_36 -> V_43 [ 3 ] & 0x8000 )
V_39 = V_45 ;
else
V_39 = V_42 ;
break;
}
} else {
V_39 = V_46 ;
}
V_18 |= V_39 << ( 2 * V_40 ) ;
}
return V_18 ;
}
void
F_16 ( struct V_47 * V_48 , struct V_1 * V_49 )
{
struct V_34 * V_17 = & V_49 -> V_7 . V_5 . V_16 . V_17 ;
struct V_50 * V_51 = (struct V_50 * ) & V_48 -> V_52 [ 0 ] ;
struct V_35 * V_53 = (struct V_35 * ) & V_17 -> V_52 [ 0 ] ;
int V_40 ;
V_48 -> V_54 = V_17 -> V_54 | 0xffff0000u ;
V_48 -> V_38 = V_17 -> V_38 | 0xffff0000u ;
V_48 -> V_32 = F_14 ( V_17 ) ;
#ifdef F_17
V_48 -> V_55 = V_17 -> V_56 ;
V_48 -> V_57 = V_17 -> V_58 ;
V_48 -> V_59 = F_18 ( V_49 ) -> V_60 ;
if ( V_49 == V_61 ) {
F_19 ( V_62 , V_48 -> V_63 ) ;
} else {
V_48 -> V_63 = V_49 -> V_7 . V_62 ;
}
V_48 -> V_63 |= 0xffff0000 ;
#else
V_48 -> V_55 = V_17 -> V_55 ;
V_48 -> V_59 = ( V_64 ) V_17 -> V_59 | ( ( T_2 ) V_17 -> V_65 << 16 ) ;
V_48 -> V_57 = V_17 -> V_57 ;
V_48 -> V_63 = V_17 -> V_63 ;
#endif
for ( V_40 = 0 ; V_40 < 8 ; ++ V_40 )
memcpy ( & V_51 [ V_40 ] , & V_53 [ V_40 ] , sizeof( V_51 [ 0 ] ) ) ;
}
void F_20 ( struct V_1 * V_49 ,
const struct V_47 * V_48 )
{
struct V_34 * V_17 = & V_49 -> V_7 . V_5 . V_16 . V_17 ;
struct V_50 * V_53 = (struct V_50 * ) & V_48 -> V_52 [ 0 ] ;
struct V_35 * V_51 = (struct V_35 * ) & V_17 -> V_52 [ 0 ] ;
int V_40 ;
V_17 -> V_54 = V_48 -> V_54 ;
V_17 -> V_38 = V_48 -> V_38 ;
V_17 -> V_32 = F_13 ( V_48 -> V_32 ) ;
V_17 -> V_65 = ( V_64 ) ( ( T_2 ) V_48 -> V_59 >> 16 ) ;
#ifdef F_17
V_17 -> V_56 = V_48 -> V_55 ;
V_17 -> V_58 = V_48 -> V_57 ;
#else
V_17 -> V_55 = V_48 -> V_55 ;
V_17 -> V_59 = ( V_48 -> V_59 & 0xffff ) ;
V_17 -> V_57 = V_48 -> V_57 ;
V_17 -> V_63 = V_48 -> V_63 ;
#endif
for ( V_40 = 0 ; V_40 < 8 ; ++ V_40 )
memcpy ( & V_51 [ V_40 ] , & V_53 [ V_40 ] , sizeof( V_53 [ 0 ] ) ) ;
}
int F_21 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
void * V_13 , void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_47 V_48 ;
F_5 ( V_5 ) ;
if ( ! F_3 ( V_66 ) )
return F_22 ( V_2 , V_4 , V_11 , V_12 , V_13 , V_14 ) ;
if ( ! F_3 ( V_10 ) )
return F_7 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_67 , 0 ,
- 1 ) ;
F_6 ( V_5 ) ;
if ( V_13 && V_11 == 0 && V_12 == sizeof( V_48 ) ) {
F_16 ( V_13 , V_2 ) ;
return 0 ;
}
F_16 ( & V_48 , V_2 ) ;
return F_7 ( & V_11 , & V_12 , & V_13 , & V_14 , & V_48 , 0 , - 1 ) ;
}
int F_23 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_11 , unsigned int V_12 ,
const void * V_13 , const void T_1 * V_14 )
{
struct V_5 * V_5 = & V_2 -> V_7 . V_5 ;
struct V_47 V_48 ;
int V_18 ;
F_9 ( V_5 ) ;
F_6 ( V_5 ) ;
if ( ! F_3 ( V_66 ) )
return F_24 ( V_2 , V_4 , V_11 , V_12 , V_13 , V_14 ) ;
if ( ! F_3 ( V_10 ) )
return F_10 ( & V_11 , & V_12 , & V_13 , & V_14 ,
& V_5 -> V_16 . V_67 , 0 ,
- 1 ) ;
if ( V_11 > 0 || V_12 < sizeof( V_48 ) )
F_16 ( & V_48 , V_2 ) ;
V_18 = F_10 ( & V_11 , & V_12 , & V_13 , & V_14 , & V_48 , 0 , - 1 ) ;
if ( ! V_18 )
F_20 ( V_2 , & V_48 ) ;
if ( F_3 ( V_21 ) )
V_5 -> V_16 . V_22 . V_23 . V_24 |= V_68 ;
return V_18 ;
}
int F_25 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_1 * V_49 = V_61 ;
struct V_5 * V_5 = & V_49 -> V_7 . V_5 ;
int V_73 ;
V_73 = V_5 -> V_8 ;
if ( V_73 )
V_73 = ! F_21 ( V_49 , NULL ,
0 , sizeof( struct V_47 ) ,
V_72 , NULL ) ;
return V_73 ;
}
